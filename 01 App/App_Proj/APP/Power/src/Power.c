/************************ Include Files ************************/
#include <stddef.h>
#include "Power.h"
#include "Power_Message_Box.h"
#include "Rte_Mcu.h"
#include "Rte_Log.h"
#include "Rte_Adc_If.h"
#include "Rte_Gpio_If.h"
#include "Rte_Pwm.h"
#include "Rte_Pwm_If.h"
#include "Rte_Os.h"
#include "Rte_Swc.h"
#include "Rte_Private.h"
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
static void _Snf_Power_Down_Signal_Detection(void);
/************************ Private Global Variables ************************/
static power_bat_status_e  power_bat_status                = POWER_BAT_STATUS_NORMAL;
static power_load_status_e power_load_status               = POWER_LOAD_STATUS_NORMAL;
static uint32_t            power_bat_det_last_update_time  = 0;
static uint32_t            power_load_det_last_update_time = 0;

static const power_bat_decection_t power_bat_detection[] = {
    { 0,     8000,                   POWER_BAT_STATUS_LOW_VOLT,  _Snf_Power_Bat_Low_Voltage_Callback    },
    { 9000,  16000,                  POWER_BAT_STATUS_NORMAL,    _Snf_Power_Bat_Normal_Voltage_Callback },
    { 17000, POWER_BAT_INVALID_VOLT, POWER_BAT_STATUS_OVER_VOLT, _Snf_Power_Bat_Over_Voltage_Callback   },
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
#if defined(PISCES_MCM_D)
    Rte_Call_Event_Cfg_D_Event_0x800116_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
#elif defined(PISCES_MCM_P)
    Rte_Call_Event_Cfg_P_Event_0x800116_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
#endif
    Rte_Call_Sync_C_Power_S_Valve_Set_Work_States(VALVE_WORK_STATE_OFF, VALVE_ALL_MODULE_DISABLE_WORK_MASK);
    Rte_Call_Sync_C_Power_S_Pump_Set_Work_States(PUMP_WORK_STATE_OFF, PUMP_ALL_MODULE_DISABLE_WORK_MASK);
}
/**
 * @brief  Callback function for normal battery voltage
 * @param  None
 * @return None
 */
void _Snf_Power_Bat_Normal_Voltage_Callback(void)
{
#if defined(PISCES_MCM_D)
    Rte_Call_Event_Cfg_D_Event_0x800116_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
    Rte_Call_Event_Cfg_D_Event_0x800117_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
#elif defined(PISCES_MCM_P)
    Rte_Call_Event_Cfg_P_Event_0x800116_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
    Rte_Call_Event_Cfg_P_Event_0x800117_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
#endif
}
/**
 * @brief  Callback function for over battery voltage
 * @param  None
 * @return None
 */
void _Snf_Power_Bat_Over_Voltage_Callback(void)
{
#if defined(PISCES_MCM_D)
    Rte_Call_Event_Cfg_D_Event_0x800117_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
#elif defined(PISCES_MCM_P)
    Rte_Call_Event_Cfg_P_Event_0x800117_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
#endif
    Rte_Call_Sync_C_Power_S_Valve_Set_Work_States(VALVE_WORK_STATE_OFF, VALVE_ALL_MODULE_DISABLE_WORK_MASK);
    Rte_Call_Sync_C_Power_S_Pump_Set_Work_States(PUMP_WORK_STATE_OFF, PUMP_ALL_MODULE_DISABLE_WORK_MASK);
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
                if (NULL != bat_decection_ptr->decection_callback)
                {
                    bat_decection_ptr->decection_callback();
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
            // RTE_PWM_SET_DUTY(RTE_PWM_CHANNEL_PUMP, RTE_PWM_DUTY_MIN);
            // RTE_GPIO_VALVE_DISABLE();
            // RTE_GPIO_PUMP_DISABLE();
        }
        else if (POWER_LOAD_STATUS_PUMP_SHORT_CIRCUIT == power_load_status ||
                 POWER_LOAD_STATUS_VALVE_SHORT_CIRCUIT == power_load_status)
        {
            // RTE_PWM_SET_DUTY(RTE_PWM_CHANNEL_PUMP, RTE_PWM_DUTY_MIN);
            // RTE_GPIO_VALVE_DISABLE();
            // RTE_GPIO_PUMP_DISABLE();
        }
    }
}
/**
 * @brief  power down detection
 * @param  None
 * @return None
 */
static void _Snf_Power_Down_Signal_Detection(void)
{
    PNC9_Sts_IDT                 current_pnc9_sts = (PNC9_Sts_IDT)POWER_PNC_STATUS_INVALID;
    PNC_DFT_IDT                  current_pnc_DFT  = (PNC_DFT_IDT)POWER_PNC_STATUS_INVALID;
    static volatile PNC9_Sts_IDT last_pnc9_sts    = (PNC9_Sts_IDT)POWER_PNC_STATUS_INVALID;
    static volatile PNC_DFT_IDT  last_pnc_DFT     = (PNC_DFT_IDT)POWER_PNC_STATUS_INVALID;

    Rte_Read_PNC9_Sts_PNC9_Sts(&current_pnc9_sts);
    Rte_Read_PNC_DFT_PNC_DFT(&current_pnc_DFT);

    if (((PNC9_Sts_IDT)POWER_PNC_STATUS_ACTIVE == last_pnc9_sts || (PNC_DFT_IDT)POWER_PNC_STATUS_ACTIVE == last_pnc_DFT) &&
        ((PNC9_Sts_IDT)POWER_PNC_STATUS_INACTIVE == current_pnc9_sts &&
         (PNC_DFT_IDT)POWER_PNC_STATUS_INACTIVE == current_pnc_DFT))
    {
        POWER_PRINTF("Power on form pnc\r\n");
        Com_IpduGroupStop(Com_BODY_LE1_CANTx);
        //下电前保存必要数据到NvM
        Rte_Call_WriteAll_WriteAll();
        //还需要添加其他下电前处理逻辑，如关闭泵、阀等
    }
    else if (((PNC9_Sts_IDT)POWER_PNC_STATUS_INACTIVE == last_pnc9_sts ||
              (PNC_DFT_IDT)POWER_PNC_STATUS_INACTIVE == last_pnc_DFT) &&
             ((PNC9_Sts_IDT)POWER_PNC_STATUS_ACTIVE == current_pnc9_sts &&
              (PNC_DFT_IDT)POWER_PNC_STATUS_ACTIVE == current_pnc_DFT))
    {
        POWER_PRINTF("Power down form pnc\r\n");
        Com_IpduGroupStart(Com_BODY_LE1_CANTx, false);
    }

    last_pnc9_sts = current_pnc9_sts;
    last_pnc_DFT  = current_pnc_DFT;
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
 * @brief  Get battery status
 * @param  None
 * @return Battery status
 */
power_bat_status_e Snf_Power_Bat_Get_State(void)
{
    return power_bat_status;
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
    RTE_GPIO_5V_LOAD_ENABLE();
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
    _Snf_Power_Down_Signal_Detection();
    Snf_Power_Message_Box_Handle();
}
