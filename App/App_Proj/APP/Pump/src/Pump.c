/************************ Include Files ************************/
#include "Pump.h"
#include "Basic_Config.h"
#include "Basic_Types.h"
#include "Rte_Gpio_If.h"
#include "Rte_Pwm.h"
#include "Rte_Pwm_If.h"
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
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Pump_Constant_Voltage(void);
/************************ Private Function Implementations ************************/
/**
 * @brief  Constant voltage control for pump
 * @details This function is used to control the pump at a constant voltage by adjusting the PWM
 * @param  None
 * @return None
 */
static void _Snf_Pump_Constant_Voltage(void)
{
    uint8_t  duty_cycle = 0;
    uint16_t voltage    = 0;
    if (PUMP_WORK_STATE_OFF == pump_config.state)
    {
        return;
    }
    voltage    = Rte_Call_Sync_C_Pump_S_Power_Get_Voltage();
    duty_cycle = (uint8_t)PUMP_DUTY_FOR_CONST_VOLTAGE(voltage);
    RTE_PWM_SET_DUTY(RTE_PWM_CHANNEL_PUMP, duty_cycle);
}
/************************ Public Function Implementations ************************/
/**
 * @brief  Set the pump work state
 * @param  state: the work state to be set
 * @return None
 */
void Snf_Pump_Set_Work_State(pump_work_state_e state, uint32_t work_mask)
{
    power_bat_status_e bat_status      = Rte_Call_Sync_C_Pump_S_Power_Get_Bat_States();
    pump_config_t*     pump_config_ptr = &pump_config;

    // 紧急处理：当工作掩码为全0时，强制关闭泵电源；
    if (PUMP_WORK_STATE_OFF == state && PUMP_ALL_MODULE_DISABLE_WORK_MASK == work_mask)
    {
        pump_config_ptr->pump_work_mask = PUMP_ALL_MODULE_DISABLE_WORK_MASK;
        RTE_GPIO_PUMP_DISABLE();
        return;
    }

    if (POWER_BAT_STATUS_NORMAL != bat_status)
    {
        return;
    }

    if (PUMP_WORK_STATE_ON == state)
    {
        SNF_SET_BIT(pump_config_ptr->pump_work_mask, work_mask);
    }
    else
    {
        SNF_CLR_BIT(pump_config_ptr->pump_work_mask, work_mask);
    }

    if (pump_config_ptr->state != state)
    {
        pump_config_ptr->state = state;
        PUMP_PRINTF("Pump work state: %d,%d\n", pump_config_ptr->state, work_mask);
        if (PUMP_WORK_STATE_ON == pump_config_ptr->state)
        {
            RTE_GPIO_PUMP_ENABLE();
        }
        else
        {
            if (PUMP_ALL_MODULE_DISABLE_WORK_MASK == pump_config_ptr->pump_work_mask)  // 只有当所有模块都不需要泵时才关闭泵电源
            {
                RTE_GPIO_PUMP_DISABLE();
            }
        }
    }
}
/**
 * @brief  Set the pump work state
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
