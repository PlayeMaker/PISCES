/************************ Include Files ************************/
#include "Pump.h"
#include "Basic_Config.h"
#include "Rte_Gpio_If.h"
#include "Rte_Pwm_If.h"
#include "Rte_Swc.h"
#include "Rte_Os.h"
#include "Rte_Log.h"
/************************ Macro Definitions ************************/
#ifdef PUMP_PRINTF_ENABLE
#define PUMP_PRINTF RTE_LOG_PRINTF
#else
#define PUMP_PRINTF(...)
#endif
/************************ Private Global Variables ************************/
static pump_state_e pump_state       = PUMP_STATE_IDLE;
static uint32_t     last_update_time = 0;
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Pump_Constant_Voltage(void);
static void _Snf_Pump_Air_Inflation(void);
static void _Snf_Pump_Air_Deflation(void);
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
    uint16_t voltage    = Rte_Call_Sync_C_Pump_S_Power_Get_Voltage();

    // 100mS更新一次气泵恒压PWM占空比
    if (RTE_OS_IS_TIMEOUT(last_update_time, PUMP_CONSTANT_PUMP_UPDATE_CYCLE))
    {
        last_update_time = RTE_OS_GET_TICK();
        duty_cycle       = (uint8_t)PUMP_DUTY_FOR_CONST_VOLTAGE(voltage);
        RTE_PWM_SET_DUTY_PUMP_EN(duty_cycle);
    }
}
/**
 * @brief  Air inflation control for pump
 * @param  None
 * @return None
 */
static void _Snf_Pump_Air_Inflation(void)
{
    if (PUMP_STATE_AIR_INFLATION == pump_state)
    {
        return;
    }
    pump_state = PUMP_STATE_AIR_INFLATION;
    RTE_GPIO_PUMP_ENABLE();
    RTE_GPIO_VALVE_DISABLE();
}
/**
 * @brief  Air deflation control for pump
 * @param  None
 * @return None
 */
static void _Snf_Pump_Air_Deflation(void)
{
    if (PUMP_STATE_AIR_DEFLATION == pump_state)
    {
        return;
    }
    pump_state = PUMP_STATE_AIR_DEFLATION;
    RTE_GPIO_PUMP_ENABLE();
    RTE_GPIO_VALVE_ENABLE();
}
/**
 * @brief  Air stop control for pump
 * @param  None
 * @return None
 */
static void _Snf_Pump_Air_Stop(void)
{
    if (PUMP_STATE_IDLE == pump_state)
    {
        return;
    }
    pump_state = PUMP_STATE_IDLE;
    RTE_GPIO_PUMP_DISABLE();
    RTE_GPIO_VALVE_DISABLE();
}

/************************ Public Function Implementations ************************/
/**
 * @brief  Pump task function initialization
 * @param  None
 * @return None
 */
void Snf_Pump_Task_Init(void)
{
    last_update_time = RTE_OS_GET_TICK();
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
