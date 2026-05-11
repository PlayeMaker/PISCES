/************************ Include Files ************************/
#include "Power.h"
#include "Rte_Mcu.h"
#include "Rte_Log.h"
#include "Rte_Adc_If.h"
#include "Rte_Gpio_If.h"
#include "Rte_Pwm_If.h"
#include "Power_Message_Box.h"
#include "Basic_Config.h"
/************************ Macro Definitions ************************/
#ifdef POWER_PRINTF_ENABLE
#define POWER_PRINTF RTE_LOG_PRINTF
#else
#define POWER_PRINTF(...)
#endif
/************************ Private Global Variables ************************/
static power_bat_status_e  power_bat_status  = POWER_BAT_STATUS_NORMAL;
static power_load_status_e power_load_status = POWER_LOAD_STATUS_NORMAL;
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Power_Get_Response(void);
static void _Snf_Power_Voltage_Detection(void);
static void _Snf_Power_Load_Detection(void);
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
 * @brief  Detect Bat voltage levels
 * @param  None
 * @return None
 */
static void _Snf_Power_Voltage_Detection(void)
{
    uint16_t           bat_vol    = Snf_Power_Get_Bat_Voltage();
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
            RTE_PWM_SET_DUTY_PUMP_EN(RTE_PWM_DUTY_MIN);
        }
        else if (POWER_LOAD_STATUS_PUMP_SHORT_CIRCUIT == power_load_status ||
                 POWER_LOAD_STATUS_VALVE_SHORT_CIRCUIT == power_load_status)
        {
            RTE_PWM_SET_DUTY_PUMP_EN(RTE_PWM_DUTY_MIN);
        }
    }
}
/************************ Public Function Implementations ************************/
/**
 * @brief  Get battery voltage
 * @param  None
 * @return Battery voltage in millivolts
 */
uint16_t Snf_Power_Get_Bat_Voltage(void)
{
    uint16_t bat_ad  = RTE_ADC_GET_BAT_VOL();
    uint16_t bat_vol = POWER_BAT_AD_TO_VOLT(bat_ad);
    return bat_vol;
}

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
    Snf_Power_Message_Box_Handle();
}
