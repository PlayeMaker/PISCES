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
/************************ Macro Definitions ************************/
#ifdef VALVE_PRINTF_ENABLE
#define VALVE_PRINTF RTE_LOG_PRINTF
#else
#define VALVE_PRINTF(...)
#endif
/************************ Private Global Variables ************************/
static const valve_ramp_step_t valve_ramp_up_step[] = {
    { 8000,  20 },
    { 10000, 20 },
    { 12000, 20 },
    { 8000,  20 },
};
static const uint8_t valve_ramp_up_step_size = sizeof(valve_ramp_up_step) / sizeof(valve_ramp_up_step[0]);

static const valve_ramp_step_t valve_ramp_down_step[] = {
    { 4000, 20 },
    { 2000, 20 },
    { 0,    20 },
};
static const uint8_t valve_ramp_down_step_size = sizeof(valve_ramp_down_step) / sizeof(valve_ramp_down_step[0]);

static valve_ramp_group_t valve_ramp_group[VALVE_RAMP_MEMBER_NUM] = { 0 };

static valve_config_t valve_config = { .state = VALVE_WORK_STATE_OFF, .valve_work_mask = 0 };
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Valve_Process_Ramp(void);
/************************ Private Function Implementations ************************/
/**
 * @brief  Handling the gradual up or down process
 * @param  None
 * @return None
 */
static void _Snf_Valve_Process_Ramp(void)
{
    valve_ramp_group_t* ramp_group_ptr   = NULL;
    valve_ramp_step_t*  ramp_config_ptr  = NULL;
    uint8_t             ramp_config_size = 0;
    uint16_t            vol              = 0;
    uint8_t             duty_cycle       = 0;

    for (uint8_t i = 0; i < VALVE_RAMP_MEMBER_NUM; i++)
    {
        ramp_group_ptr = &valve_ramp_group[i];
        if (POWER_VALVE_STATE_RAMP_UP == ramp_group_ptr->state)
        {
            ramp_config_ptr  = (valve_ramp_step_t*)valve_ramp_up_step;
            ramp_config_size = valve_ramp_up_step_size;
        }
        else if (POWER_VALVE_STATE_RAMP_DOWN == ramp_group_ptr->state)
        {
            ramp_config_ptr  = (valve_ramp_step_t*)valve_ramp_down_step;
            ramp_config_size = valve_ramp_down_step_size;
        }
        else
        {
            continue;
        }

        if (RTE_OS_IS_TIMEOUT(ramp_group_ptr->last_timer_ms, ramp_config_ptr[ramp_group_ptr->step_index].step_time_ms))
        {
            ramp_group_ptr->step_index++;
            if (ramp_group_ptr->step_index < ramp_config_size)
            {
                ramp_group_ptr->last_timer_ms = RTE_OS_GET_TICK();
                vol                           = ramp_config_ptr[ramp_group_ptr->step_index].voltage;
                duty_cycle                    = VALVE_RAMP_STEP_VOLTAGE_TO_DUTY_CYCLE(vol);
                RTE_PWM_SET_DUTY(i, duty_cycle);
            }
            else
            {
                ramp_group_ptr->state = (POWER_VALVE_STATE_RAMP_UP == ramp_group_ptr->state ? POWER_VALVE_STATE_RAMP_UP_DONE
                                                                                            : POWER_VALVE_STATE_RAMP_DOWN_DONE);
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
    valve_ramp_group_t* ramp_group_ptr  = NULL;
    valve_ramp_step_t*  ramp_config_ptr = NULL;
    uint16_t            vol             = 0;
    uint8_t             duty_cycle      = 0;

    if (index >= VALVE_RAMP_MEMBER_NUM)
    {
        return false;
    }

    ramp_group_ptr = &valve_ramp_group[index];
    if (ramp_group_ptr->state != state)
    {
        if (POWER_VALVE_STATE_RAMP_UP_DONE != ramp_group_ptr->state && POWER_VALVE_STATE_RAMP_UP == state)
        {
            ramp_config_ptr = (valve_ramp_step_t*)valve_ramp_up_step;
        }
        else if (POWER_VALVE_STATE_RAMP_DOWN_DONE != ramp_group_ptr->state && POWER_VALVE_STATE_RAMP_DOWN == state)
        {
            ramp_config_ptr = (valve_ramp_step_t*)valve_ramp_down_step;
        }
        else
        {
            return false;
        }
        ramp_group_ptr->state         = state;
        ramp_group_ptr->step_index    = 0;
        ramp_group_ptr->last_timer_ms = RTE_OS_GET_TICK();
        vol                           = ramp_config_ptr[ramp_group_ptr->step_index].voltage;
        duty_cycle                    = VALVE_RAMP_STEP_VOLTAGE_TO_DUTY_CYCLE(vol);
        RTE_PWM_SET_DUTY(index, duty_cycle);
    }
    return true;
}

/**
 * @brief  Set the valve work state
 * @param  state: the work state to be set
 * @return None
 */
void Snf_Valve_Set_Work_State(valve_work_state_e state, uint32_t work_mask)
{
    power_bat_status_e bat_status       = Rte_Call_Sync_C_Valve_S_Power_Get_Bat_States();
    valve_config_t*    valve_config_ptr = &valve_config;
    if (POWER_BAT_STATUS_NORMAL != bat_status)
    {
        return;
    }

    if (VALVE_WORK_STATE_ON == state)
    {
        SNF_SET_BIT(valve_config_ptr->valve_work_mask, work_mask);
    }
    else
    {
        SNF_CLR_BIT(valve_config_ptr->valve_work_mask, work_mask);
    }

    if (valve_config_ptr->state != state)
    {
        valve_config_ptr->state = state;
        VALVE_PRINTF("Valve work state: %d,%d\n", valve_config_ptr->state, work_mask);
        if (VALVE_WORK_STATE_ON == valve_config_ptr->state)
        {
            RTE_GPIO_VALVE_ENABLE();
        }
        else
        {
            if (0 == valve_config_ptr->valve_work_mask)  // 只有当所有模块都不需要阀时才关闭阀电源
            {
                RTE_GPIO_VALVE_DISABLE();
            }
        }
    }
}
/**
 * @brief  Set the valve work state
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
