/************************ Include Files ************************/
#include "Power.h"
#include <stdint.h>
#include "Rte_Mcu.h"
#include "Rte_Mcu_Types.h"
#include "Rte_Wdg.h"
#include "Rte_Log.h"
#include "Rte_Adc_If.h"
#include "Rte_Gpio_If.h"
#include "Power_Message_Box.h"
#include "Basic_Config.h"
/************************ Macro Definitions ************************/
#ifdef POWER_PRINTF_ENABLE
#define POWER_PRINTF RTE_LOG_PRINTF
#else
#define POWER_PRINTF(...)
#endif
/************************ Private Global Variables ************************/
static power_bat_status_e power_bat_status = POWER_BAT_STATUS_NORMAL;
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Power_Get_Response(void);
static void _Snf_Power_Voltage_Detection(void);
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
    uint16_t           bat_ad     = RTE_ADC_GET_BAT_VOL();
    uint16_t           bat_vol    = POWER_BAT_AD_TO_VOLT(bat_ad);
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
    RTE_GPIO_BAT_VOL_AD_ENABLE();
}

/**
 * @brief  Power task function
 * @param  None
 * @return None
 */
void Snf_Power_Task(void)
{
    RTE_WDG_REFRESH();
    _Snf_Power_Voltage_Detection();
    Snf_Power_Message_Box_Handle();
}
