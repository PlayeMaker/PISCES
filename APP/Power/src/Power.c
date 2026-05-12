/************************ Include Files ************************/
#include "Basic_Config.h"
#include "Power.h"
#include "Power_Message_Box.h"
#include "Rte_Mcu.h"
#include "Rte_Log.h"
#include "Rte_Adc_If.h"
#include "Rte_Gpio_If.h"
#include "Rte_Pwm.h"
#include "Rte_Pwm_If.h"
#include "Rte_Os.h"
/************************ Macro Definitions ************************/
#ifdef POWER_PRINTF_ENABLE
#define POWER_PRINTF RTE_LOG_PRINTF
#else
#define POWER_PRINTF(...)
#endif
/************************ Private Global Variables ************************/
static power_bat_status_e  power_bat_status            = POWER_BAT_STATUS_NORMAL;
static power_load_status_e power_load_status           = POWER_LOAD_STATUS_NORMAL;
static uint32_t            power_pump_last_update_time = 0;
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void     _Snf_Power_Get_Response(void);
static uint16_t _Snf_Power_Get_Bat_Voltage(void);
static void     _Snf_Power_Voltage_Detection(void);
static void     _Snf_Power_Load_Detection(void);
static void     _Snf_Pump_Constant_Voltage(void);
/************************ Private Function Implementations ************************/
/**
 * @brief  Get MCU reset reason
 * @param  None
 * @return None
 */
static void _Snf_Power_Get_Response(void)
{
    rte_mcu_reset_reason_e reset_reason = RTE_MCU_GET_RESET_REASON();
    POWER_PRINTF("Reset reason: %d\n", reset_reason);
}

/**
 * @brief  Get battery voltage
 * @param  None
 * @return Battery voltage in millivolts
 */
static uint16_t _Snf_Power_Get_Bat_Voltage(void)
{
    uint16_t bat_ad  = RTE_ADC_GET_BAT_VOL();
    uint16_t bat_vol = POWER_BAT_AD_TO_VOLT(bat_ad);
    return bat_vol;
}

/**
 * @brief  Detect Bat voltage levels
 * @param  None
 * @return None
 */
static void _Snf_Power_Voltage_Detection(void)
{
    uint16_t           bat_vol    = _Snf_Power_Get_Bat_Voltage();
    power_bat_status_e bat_status = POWER_BAT_STATUS_NORMAL;

    if (POWER_BAT_UNDER_VOLT > bat_vol)
    {
        bat_status = POWER_BAT_STATUS_LOW_VOLT;
    }
    else if (POWER_BAT_OVER_VOLT < bat_vol)
    {
        bat_status = POWER_BAT_STATUS_OVER_VOLT;
    }

    if (power_bat_status != bat_status)
    {
        power_bat_status = bat_status;
        POWER_PRINTF("Battery voltage: %d\r\n", bat_vol);

        if (POWER_BAT_STATUS_NORMAL == power_bat_status)
        {
            // Handle normal voltage status
        }
        else
        {
            // Handle low voltage status
        }
    }
}
/**
 * @brief  Detect load status
 * @param  None
 * @return None
 */
static void _Snf_Power_Load_Detection(void)
{
    uint16_t            vol         = RTE_ADC_GET_PUMP_VALVE_IS();
    uint16_t            ics         = (uint16_t)POWER_PUMP_VALVE_AD_TO_VCS(vol);
    power_load_status_e load_status = POWER_LOAD_STATUS_NORMAL;

    if (POWER_BAT_STATUS_NORMAL != power_bat_status)
    {
        return;
    }

    if (POWER_PUMP_OPEN_CIRCUIT > ics)
    {
        load_status = POWER_LOAD_STATUS_PUMP_OPEN_CIRCUIT;
    }
    else if (POWER_VALVE_SHORT_CIRCUIT < ics)
    {
        load_status = POWER_LOAD_STATUS_VALVE_SHORT_CIRCUIT;
    }
    else if (POWER_PUMP_SHORT_CIRCUIT < ics)
    {
        load_status = POWER_LOAD_STATUS_PUMP_SHORT_CIRCUIT;
    }

    if (power_load_status != load_status)
    {
        power_load_status = load_status;
        POWER_PRINTF("Battery voltage: %d\r\n", ics);

        if (POWER_LOAD_STATUS_NORMAL == power_load_status)
        {
            // Handle normal voltage status
        }
        else if (POWER_LOAD_STATUS_PUMP_OPEN_CIRCUIT == power_load_status ||
                 POWER_LOAD_STATUS_VALVE_OPEN_CIRCUIT == power_load_status)
        {
            RTE_PWM_SET_DUTY(RTE_PWM_CHANNEL_PUMP, RTE_PWM_DUTY_MIN);
        }
        else if (POWER_LOAD_STATUS_PUMP_SHORT_CIRCUIT == power_load_status ||
                 POWER_LOAD_STATUS_VALVE_SHORT_CIRCUIT == power_load_status)
        {
            RTE_PWM_SET_DUTY(RTE_PWM_CHANNEL_PUMP, RTE_PWM_DUTY_MIN);
        }
    }
}
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

    if (POWER_LOAD_STATUS_NORMAL != power_load_status || POWER_BAT_STATUS_NORMAL != power_bat_status)
    {
        return;
    }
    // 100mS更新一次气泵恒压PWM占空比
    if (RTE_OS_IS_TIMEOUT(power_pump_last_update_time, POWER_PUMP_CONSTANT_PUMP_UPDATE_CYCLE))
    {
        power_pump_last_update_time = RTE_OS_GET_TICK();
        voltage                     = _Snf_Power_Get_Bat_Voltage();
        duty_cycle                  = (uint8_t)POWER_PUMP_DUTY_FOR_CONST_VOLTAGE(voltage);
        RTE_PWM_SET_DUTY(RTE_PWM_CHANNEL_PUMP, duty_cycle);
    }
}
/************************ Public Function Implementations ************************/

/**
 * @brief  Reset MCU
 * @param  None
 * @return None
 */
void Snf_Power_Reset(void)
{
    RTE_MCU_RESET();
}

/**
 * @brief  Initialize power task function
 * @param  None
 * @return None
 */
void Snf_Power_Task_Init(void)
{
    _Snf_Power_Get_Response();
    power_pump_last_update_time = RTE_OS_GET_TICK();
    RTE_GPIO_BAT_VOL_AD_ENABLE();
}

/**
 * @brief  Power task function
 * @param  None
 * @return None
 */
void Snf_Power_Task(void)
{
    _Snf_Power_Voltage_Detection();
    _Snf_Power_Load_Detection();
    _Snf_Pump_Constant_Voltage();
    Snf_Power_Message_Box_Handle();
}
