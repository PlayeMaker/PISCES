/************************ Include Files ************************/
#include "Basic_Config.h"
#include "Basic_Types.h"
#include "Valve.h"
#include "Rte_Log.h"
#include "Rte_Pwm.h"
#include "Rte_Os.h"
#include "Rte_Swc.h"
#include "Rte_Gpio_If.h"
#include "Valve_Types.h"
#include "Valve_Ramp_Class.h"
#include "Valve_Ramp_Def.h"
#include "Valve_Ramp_Class.h"
#include "Valve_Ramp_Def.h"
#include "Valve_Ramp_Class.h"
/************************ Macro Definitions ************************/
#ifdef VALVE_PRINTF_ENABLE
#define VALVE_PRINTF RTE_LOG_PRINTF
#else
#define VALVE_PRINTF(...)
#endif
#define VALVE_ARRAY_SIZE(array) (sizeof(array) / sizeof((array)[0]))
/************************ Private Global Variables ************************/
static const valve_ramp_cfg_t valve_ramp_up_cfg   = { valve_ramp_up_steps, VALVE_ARRAY_SIZE(valve_ramp_up_steps) };
static const valve_ramp_cfg_t valve_ramp_down_cfg = { valve_ramp_down_steps, VALVE_ARRAY_SIZE(valve_ramp_down_steps) };

static valve_ramp_group_t valve_ramp_group[VALVE_RAMP_MEMBER_NUM] = { 0 };

static valve_config_t valve_config = { .state = VALVE_WORK_STATE_OFF, .valve_work_mask = VALVE_ALL_MODULE_DISABLE_WORK_MASK };
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Valve_Apply_Step(uint8_t index, const valve_ramp_cfg_t* ramp_cfg_ptr, uint32_t step_index);
static void _Snf_Valve_Process_Ramp(void);
/************************ Private Function Implementations ************************/
/**
 * @brief  Apply one ramp step to the valve channel
 * @param  index: the index of the solenoid valve
 * @param  ramp_cfg_ptr: the ramp config
 * @param  step_index: the step index in the ramp config
 * @return None
 */
static void _Snf_Valve_Apply_Step(uint8_t index, const valve_ramp_cfg_t* ramp_cfg_ptr, uint32_t step_index)
{
    uint16_t vol        = ramp_cfg_ptr->steps[step_index].voltage;
    uint8_t  duty_cycle = VALVE_RAMP_STEP_VOLTAGE_TO_DUTY_CYCLE(vol);
    RTE_PWM_SET_DUTY(index, duty_cycle);
}

/**
 * @brief  Handling the gradual up or down process
 * @param  None
 * @return None
 */
static void _Snf_Valve_Process_Ramp(void)
{
    valve_ramp_group_t*     ramp_group_ptr = NULL;
    const valve_ramp_cfg_t* ramp_cfg_ptr   = NULL;

    if (VALVE_WORK_STATE_ON != valve_config.state)
    {
        return;  // 阀电源未正常开启(关/异常)时不处理缓升缓降
    }

    for (uint8_t i = 0; i < VALVE_RAMP_MEMBER_NUM; i++)
    {
        ramp_group_ptr = &valve_ramp_group[i];
        if (POWER_VALVE_STATE_RAMP_UP != ramp_group_ptr->state && POWER_VALVE_STATE_RAMP_DOWN != ramp_group_ptr->state)
        {
            continue;  // 非进行中状态(完成态/非法)
        }
        ramp_cfg_ptr = (POWER_VALVE_STATE_RAMP_UP == ramp_group_ptr->state) ? &valve_ramp_up_cfg : &valve_ramp_down_cfg;

        if (RTE_OS_IS_TIMEOUT(ramp_group_ptr->last_timer_ms, ramp_cfg_ptr->steps[ramp_group_ptr->step_index].step_time_ms))
        {
            ramp_group_ptr->step_index++;
            if (ramp_group_ptr->step_index < ramp_cfg_ptr->step_num)
            {
                ramp_group_ptr->last_timer_ms = RTE_OS_GET_TICK();
                _Snf_Valve_Apply_Step(i, ramp_cfg_ptr, ramp_group_ptr->step_index);
            }
            else
            {
                ramp_group_ptr->state = (valve_state_e)(ramp_group_ptr->state + 1);  // +1 为对应的完成态
            }
        }
    }
}
/************************ Public Function Implementations ************************/
/**
 * @brief   Set the solenoid valve state
 * @param  index: the index of the solenoid valve
 * @param  state: the state of the solenoid valve
 * @return bool: true if success, false if fail
 */
bool Snf_Valve_Set_Config(uint8_t index, valve_state_e state)
{
    valve_ramp_group_t* ramp_group_ptr = NULL;

    if (index >= VALVE_RAMP_MEMBER_NUM || VALVE_WORK_STATE_ON != valve_config.state)
    {
        return false;
    }

    if (POWER_VALVE_STATE_RAMP_UP != state && POWER_VALVE_STATE_RAMP_DOWN != state)
    {
        return false;  // 参数错误，目标不是进行中状态(完成态/非法)
    }

    ramp_group_ptr = &valve_ramp_group[index];
    if (ramp_group_ptr->state == state || ramp_group_ptr->state == (valve_state_e)(state + 1))  // +1 为对应的完成态
    {
        return true;  // 已在目标方向(进行中或已完成),无需重复执行
    }

    ramp_group_ptr->state         = state;
    ramp_group_ptr->step_index    = 0;
    ramp_group_ptr->last_timer_ms = RTE_OS_GET_TICK();
    _Snf_Valve_Apply_Step(index, (POWER_VALVE_STATE_RAMP_UP == state) ? &valve_ramp_up_cfg : &valve_ramp_down_cfg, 0);
    return true;
}

/**
 * @brief  Set the valve work state
 * @param  state: the work state to be set
 * @param  work_mask: the module work mask
 * @return None
 * @note   state=OFF 且 work_mask=0 时为电源故障紧急处理(过压/欠压/负载异常)：强制关阀；
 *         阀通道负载异常(开路/短路)属于阀自身故障置异常态，其余电源侧原因置OFF；
 *         电源未恢复前下面的守卫会拒绝一切请求，直到故障恢复
 */
void Snf_Valve_Set_Work_State(valve_work_state_e state, uint32_t work_mask)
{
    power_bat_status_e  bat_status  = Rte_Call_Sync_C_Valve_S_Power_Get_Bat_States();
    power_load_status_e load_status = Rte_Call_Sync_C_Valve_S_Power_Get_Load_States();

    // 紧急处理：工作掩码为全0时(Power模块电源/负载故障时调用)强制关闭阀电源；
    // 结合阀通道负载状态区分故障源：负载异常是阀自身故障(开路/短路)置异常态，否则(过压/欠压/泵负载牵连)置OFF；
    // 电源未恢复前下面的守卫会拒绝一切重新开阀请求
    if (VALVE_WORK_STATE_OFF == state && VALVE_ALL_MODULE_DISABLE_WORK_MASK == work_mask)
    {
        valve_config.state = (POWER_LOAD_STATUS_NORMAL != load_status) ? VALVE_WORK_STATE_ABNORMAL : VALVE_WORK_STATE_OFF;
        valve_config.valve_work_mask = VALVE_ALL_MODULE_DISABLE_WORK_MASK;
        RTE_GPIO_VALVE_DISABLE();
        return;
    }

    // 电源未恢复(电池或负载异常)时拒绝一切请求(含开阀)，防止故障未消除时被其他模块重新开阀
    if (POWER_BAT_STATUS_NORMAL != bat_status || POWER_LOAD_STATUS_NORMAL != load_status)
    {
        return;
    }

    if (VALVE_WORK_STATE_ON == state)
    {
        SNF_SET_BIT(valve_config.valve_work_mask, work_mask);
    }
    else
    {
        SNF_CLR_BIT(valve_config.valve_work_mask, work_mask);
    }

    // 掩码非0说明有模块需要阀则开阀，全0则关阀
    valve_work_state_e new_state =
        (VALVE_ALL_MODULE_DISABLE_WORK_MASK != valve_config.valve_work_mask) ? VALVE_WORK_STATE_ON : VALVE_WORK_STATE_OFF;

    if (new_state != valve_config.state)
    {
        VALVE_PRINTF("Valve work state: %d,%d\n", new_state, work_mask);
        valve_config.state = new_state;
        if (VALVE_WORK_STATE_ON == new_state)
        {
            RTE_GPIO_VALVE_ENABLE();
        }
        else
        {
            RTE_GPIO_VALVE_DISABLE();
        }
    }
}
/**
 * @brief  Get the valve work state
 * @param  None
 * @return the current work state of the valve
 */
valve_work_state_e Snf_Valve_Get_Work_State(void)
{
    valve_config_t* valve_config_ptr = &valve_config;
    return valve_config_ptr->state;
}

/**
 * @brief  Initialize Solenoid valve task function
 * @param  None
 * @return None
 */
void Snf_Valve_Task_Init(void)
{
    valve_ramp_group_t* ramp_group_ptr = NULL;
    for (uint8_t i = 0; i < VALVE_RAMP_MEMBER_NUM; i++)
    {
        ramp_group_ptr        = &valve_ramp_group[i];
        ramp_group_ptr->state = POWER_VALVE_STATE_RAMP_DOWN_DONE;
    }
}

/**
 * @brief  Solenoid valve task function
 * @param  None
 * @return None
 */
void Snf_Valve_Task(void)
{
    _Snf_Valve_Process_Ramp();
}
