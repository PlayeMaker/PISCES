/************************ Include Files ************************/
#include "Pump.h"
#include "Basic_Config.h"
#include "Basic_Types.h"
#include "Rte_Gpio_If.h"
#include "Rte_Pwm.h"
#include "Rte_Pwm_If.h"
#include "Rte_Com.h"
#include "Rte_Swc.h"
#include "Rte_Log.h"
/************************ Macro Definitions ************************/
#ifdef PUMP_PRINTF_ENABLE
#define PUMP_PRINTF RTE_LOG_PRINTF
#else
#define PUMP_PRINTF(...)
#endif
/************************ Private Global Variables ************************/
static pump_config_t pump_config = { .state = PUMP_WORK_STATE_OFF, .pump_work_mask = PUMP_ALL_MODULE_DISABLE_WORK_MASK };

/**
 * @brief  泵状态上报表：[泵工作状态] = 上报的泵状态
 */
static const pump_status_e pump_status_table[] = {
    [PUMP_WORK_STATE_OFF]      = PUMP_STATUS_NO_ACTION,
    [PUMP_WORK_STATE_ON]       = PUMP_STATUS_ACTION,
    [PUMP_WORK_STATE_ABNORMAL] = PUMP_STATUS_ERR,
};
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Pump_Write_Sts(pump_status_e status);
static void _Snf_Pump_Constant_Voltage(void);
/************************ Private Function Implementations ************************/
/**
 * @brief  上报泵工作状态到网络
 * @param  status - 泵状态
 * @return None
 */
static void _Snf_Pump_Write_Sts(pump_status_e status)
{
#if defined(PISCES_MCM_D)
    (void)Rte_Write_DrvPumpSts_DrvPumpSts(status);
#elif defined(PISCES_MCM_P)
    (void)Rte_Write_PassPumpSts_PassPumpSts(status);
#endif
}

/**
 * @brief  Constant voltage control for pump
 * @details This function is used to control the pump at a constant voltage by adjusting the PWM
 * @param  None
 * @return None
 * @note   上报状态按工作状态查 pump_status_table；非 ON 状态(含异常)都关闭泵输出
 */
static void _Snf_Pump_Constant_Voltage(void)
{
    _Snf_Pump_Write_Sts(pump_status_table[pump_config.state]);

    if (PUMP_WORK_STATE_ON != pump_config.state)
    {
        RTE_PWM_SET_DUTY(RTE_PWM_CHANNEL_PUMP, RTE_PWM_DUTY_MIN);
        return;
    }

    uint16_t voltage    = Rte_Call_Sync_C_Pump_S_Power_Get_Voltage();
    uint8_t  duty_cycle = (uint8_t)PUMP_DUTY_FOR_CONST_VOLTAGE(voltage);
    RTE_PWM_SET_DUTY(RTE_PWM_CHANNEL_PUMP, duty_cycle);
}
/************************ Public Function Implementations ************************/
/**
 * @brief  设置气泵工作状态(按模块掩码聚合开关请求)
 * @param  state - 目标工作状态(ON 置位掩码/OFF 清除掩码)
 * @param  work_mask - 模块工作掩码
 * @return None
 * @note   state=OFF 且 work_mask=0 时为电源故障紧急处理：强制关泵并置异常态；
 *         电池/负载异常时拒绝一切请求；聚合掩码非 0 开泵、全 0 关泵
 */
void Snf_Pump_Set_Work_State(pump_work_state_e state, uint32_t work_mask)
{
    power_bat_status_e  bat_status  = Rte_Call_Sync_C_Pump_S_Power_Get_Bat_States();
    power_load_status_e load_status = Rte_Call_Sync_C_Pump_S_Power_Get_Load_States();

    // 紧急处理：工作掩码为全0时(Power模块电源故障时调用)强制关闭泵电源并置异常态；
    // 电源未恢复前下面的守卫会拒绝一切请求，其他模块无法重新开泵
    if (PUMP_WORK_STATE_OFF == state && PUMP_ALL_MODULE_DISABLE_WORK_MASK == work_mask)
    {
        pump_config.state          = (POWER_LOAD_STATUS_NORMAL != load_status) ? PUMP_WORK_STATE_ABNORMAL : PUMP_WORK_STATE_OFF;
        pump_config.pump_work_mask = PUMP_ALL_MODULE_DISABLE_WORK_MASK;
        RTE_GPIO_PUMP_DISABLE();
        return;
    }

    // 电源未恢复(电池或泵负载异常)时拒绝一切请求(含开泵)，防止故障未消除时被其他模块重新开泵
    if (POWER_BAT_STATUS_NORMAL != bat_status || POWER_LOAD_STATUS_NORMAL != load_status)
    {
        return;
    }

    if (PUMP_WORK_STATE_ON == state)
    {
        SNF_SET_BIT(pump_config.pump_work_mask, work_mask);
    }
    else
    {
        SNF_CLR_BIT(pump_config.pump_work_mask, work_mask);
    }

    //掩码非0说明有模块需要泵则开泵，全0则关泵
    pump_work_state_e new_state =
        (PUMP_ALL_MODULE_DISABLE_WORK_MASK != pump_config.pump_work_mask) ? PUMP_WORK_STATE_ON : PUMP_WORK_STATE_OFF;

    if (new_state != pump_config.state)
    {
        PUMP_PRINTF("Pump work state: %d,%d\n", new_state, work_mask);
        pump_config.state = new_state;
        if (PUMP_WORK_STATE_ON == new_state)
        {
            RTE_GPIO_PUMP_ENABLE();
        }
        else
        {
            RTE_GPIO_PUMP_DISABLE();
        }
    }
}
/**
 * @brief  Get the pump work state
 * @param  None
 * @return the current work state of the pump
 */
pump_work_state_e Snf_Pump_Get_Work_State(void)
{
    pump_config_t* pump_config_ptr = &pump_config;
    return pump_config_ptr->state;
}
/**
 * @brief  Pump task function
 * @param  None
 * @return None
 */
void Snf_Pump_Task(void)
{
    _Snf_Pump_Constant_Voltage();
}
