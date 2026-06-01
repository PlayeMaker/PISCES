/************************ Include Files ************************/
#include <stddef.h>
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
#include "Rte_Dem.h"
/************************ Macro Definitions ************************/
#ifdef POWER_PRINTF_ENABLE
#define POWER_PRINTF RTE_LOG_PRINTF
#else
#define POWER_PRINTF(...)
#endif
/************************ Private Function Declarations ************************/
static void _Snf_Power_Get_Response(void);
static void _Snf_Power_Voltage_Detection(void);
static void _Snf_Power_Load_Detection(void);

static void _Snf_Power_Bat_Low_Voltage_Callback(void);
static void _Snf_Power_Bat_Normal_Voltage_Callback(void);
static void _Snf_Power_Bat_Over_Voltage_Callback(void);

/************************ Private Global Variables ************************/
static power_bat_status_e  power_bat_status                = POWER_BAT_STATUS_NORMAL;
static power_load_status_e power_load_status               = POWER_LOAD_STATUS_NORMAL;
static uint32_t            power_bat_det_last_update_time  = 0;
static uint32_t            power_load_det_last_update_time = 0;

static const power_bat_decection_t power_bat_detection[] = {
    { 0,     8000,                   POWER_BAT_STATUS_LOW_VOLT,  _Snf_Power_Bat_Low_Voltage_Callback    },
    { 8000,  16000,                  POWER_BAT_STATUS_NORMAL,    _Snf_Power_Bat_Normal_Voltage_Callback },
    { 16000, POWER_BAT_INVALID_VOLT, POWER_BAT_STATUS_OVER_VOLT, _Snf_Power_Bat_Over_Voltage_Callback   },
};

static const uint8_t power_bat_detection_size = sizeof(power_bat_detection) / sizeof(power_bat_decection_t);
/************************ Public Global Variables ************************/

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
 * @brief  Callback function for low battery voltage
 * @param  None
 * @return None
 */
void _Snf_Power_Bat_Low_Voltage_Callback(void)
{
}
/**
 * @brief  Callback function for normal battery voltage
 * @param  None
 * @return None
 */
void _Snf_Power_Bat_Normal_Voltage_Callback(void)
{
}
/**
 * @brief  Callback function for over battery voltage
 * @param  None
 * @return None
 */
void _Snf_Power_Bat_Over_Voltage_Callback(void)
{
}

/**
 * @brief  Detect Bat voltage levels
 * @param  None
 * @return None
 */
static void _Snf_Power_Voltage_Detection(void)
{
    uint16_t               bat_vol           = 0;
    power_bat_status_e     bat_status        = POWER_BAT_STATUS_NORMAL;
    power_bat_decection_t* bat_decection_ptr = NULL;
    // 周期100mS检查电源状态
    if (false == RTE_OS_IS_TIMEOUT(power_bat_det_last_update_time, POWER_BAT_DETECTION_UPDATE_CYCLE))
    {
        return;
    }

    power_bat_det_last_update_time = RTE_OS_GET_TICK();
    bat_vol                        = Snf_Power_Get_Bat_Voltage();

    for (uint8_t i = 0; i < power_bat_detection_size; i++)
    {
        bat_decection_ptr = (power_bat_decection_t*)&power_bat_detection[i];
        if (bat_decection_ptr->voltage_min < bat_vol && bat_decection_ptr->voltage_max > bat_vol)
        {
            bat_status = bat_decection_ptr->status;
            if (power_bat_status != bat_status)
            {
                power_bat_status = bat_status;
                POWER_PRINTF("Battery status: %d, voltage: %d\r\n", power_bat_status, bat_vol);
                if (NULL != bat_decection_ptr->callback)
                {
                    bat_decection_ptr->callback();
                }
            }
            break;
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
    uint16_t            vol         = 0;
    uint16_t            ics         = 0;
    power_load_status_e load_status = POWER_LOAD_STATUS_NORMAL;

    // 周期100mS检查负载故障状态
    if (false == RTE_OS_IS_TIMEOUT(power_load_det_last_update_time, POWER_LOAD_DETECTION_UPDATE_CYCLE))
    {
        return;
    }

    power_load_det_last_update_time = RTE_OS_GET_TICK();
    vol                             = RTE_ADC_GET_PUMP_VALVE_IS();
    ics                             = (uint16_t)POWER_PUMP_VALVE_AD_TO_VCS(vol);

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
        POWER_PRINTF("Load status: %d, ics:%d\r\n", load_status, ics);

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
    power_bat_det_last_update_time  = RTE_OS_GET_TICK();
    power_load_det_last_update_time = RTE_OS_GET_TICK();
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
