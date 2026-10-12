/************************ Include Files ************************/
#include <stdbool.h>
#include <string.h>
#include "Power_Types.h"
#include "Power_Load.h"
#include "Power_Class.h"
#include "Power_Def.h"
#include "Rte_Adc_If.h"
#include "Rte_Pwm.h"
#include "Rte_Pwm_If.h"
#include "Rte_Gpio_If.h"
#include "Rte_Os.h"
#include "Rte_Type.h"
#include "Pump.h"
#include "Valve.h"
#include "Rte_Private_Type.h"
#include "Rte_Log.h"
#include "Rte_Swc.h"
#include "Basic_Config.h"
#include "Pump.h"
#include "Valve.h"

/************************ Macro Definitions ************************/
#ifdef POWER_PRINTF_ENABLE
#define POWER_LOG_PRINTF RTE_LOG_PRINTF
#else
#define POWER_LOG_PRINTF(...)
#endif

/************************ Private Function Declarations ************************/
static void     _Snf_Power_Load_Pump_Open_Circuit_Callback(void);
static void     _Snf_Power_Load_Valve_Open_Circuit_Callback(void);
static void     _Snf_Power_Load_Pump_Normal_Callback(void);
static void     _Snf_Power_Load_Valve_Normal_Callback(void);
static void     _Snf_Power_Load_Pump_Short_Circuit_Callback(void);
static void     _Snf_Power_Load_Valve_Short_Circuit_Callback(void);
static void     _Snf_Power_Load_Set_Dsel(void);
static uint16_t _Snf_Power_Load_Get_Adc_Value(power_load_channel_e channel);

/************************ Private Global Variables ************************/
static uint32_t               power_load_channel_timeout      = 0U;                       // 设置IO引脚后延时时间
static uint32_t               power_load_det_last_update_time = 0U;                       // 调度处理时间
static power_load_channel_e   power_load_channel              = POWER_LOAD_CHANNEL_PUMP;  // 当前通道
static uint8_t                power_load_active_channel       = 0U;                       // 活动通道
static power_load_status_e    power_load_status[POWER_LOAD_CHANNEL_MAX];                  // 通道状态
static power_load_detection_t load_detection[POWER_LOAD_DETECTION_TABLE_SIZE];
/************************ Load Detection Table ************************/
#include "Power_Load_Def.h"
/************************ Private Function Implementations ************************/
static void _Snf_Power_Load_Pump_Open_Circuit_Callback(void)
{
    Rte_Call_Event_Cfg_D_Event_0x9D0418_SetEventStatus(DEM_EVENT_STATUS_FAILED);
    RTE_PWM_SET_DUTY(RTE_PWM_CHANNEL_PUMP, RTE_PWM_DUTY_MIN);
    Snf_Pump_Set_Work_State(PUMP_WORK_STATE_OFF, PUMP_ALL_MODULE_DISABLE_WORK_MASK);
    Snf_Valve_Set_Work_State(VALVE_WORK_STATE_OFF, VALVE_ALL_MODULE_DISABLE_WORK_MASK);
    Rte_Write_DrvSystemFailr_DrvSystemFailr(POWER_LOAD_STATUS_ABNORMAL);
    Rte_Write_DrvSeatMassFailr_DrvSeatMassFailr(POWER_LOAD_STATUS_ABNORMAL);
}

static void _Snf_Power_Load_Valve_Open_Circuit_Callback(void)
{
    Rte_Call_Event_Cfg_D_Event_0x9D0218_SetEventStatus(DEM_EVENT_STATUS_FAILED);
    RTE_PWM_SET_DUTY(RTE_PWM_CHANNEL_PUMP, RTE_PWM_DUTY_MIN);
    Snf_Pump_Set_Work_State(PUMP_WORK_STATE_OFF, PUMP_ALL_MODULE_DISABLE_WORK_MASK);
    Snf_Valve_Set_Work_State(VALVE_WORK_STATE_OFF, VALVE_ALL_MODULE_DISABLE_WORK_MASK);
    Rte_Write_DrvSystemFailr_DrvSystemFailr(POWER_LOAD_STATUS_ABNORMAL);
    Rte_Write_DrvSeatMassFailr_DrvSeatMassFailr(POWER_LOAD_STATUS_ABNORMAL);
}

static void _Snf_Power_Load_Pump_Normal_Callback(void)
{
    Rte_Call_Event_Cfg_D_Event_0x9D0418_SetEventStatus(DEM_EVENT_STATUS_PASSED);
    Rte_Call_Event_Cfg_D_Event_0x9D0319_SetEventStatus(DEM_EVENT_STATUS_PASSED);
    Rte_Write_DrvSystemFailr_DrvSystemFailr(POWER_LOAD_STATUS_NORMAL);
    Rte_Write_DrvSeatMassFailr_DrvSeatMassFailr(POWER_LOAD_STATUS_NORMAL);
}

static void _Snf_Power_Load_Valve_Normal_Callback(void)
{
    Rte_Call_Event_Cfg_D_Event_0x9D0119_SetEventStatus(DEM_EVENT_STATUS_PASSED);
    Rte_Call_Event_Cfg_D_Event_0x9D0218_SetEventStatus(DEM_EVENT_STATUS_PASSED);
    Rte_Write_DrvSystemFailr_DrvSystemFailr(POWER_LOAD_STATUS_NORMAL);
    Rte_Write_DrvSeatMassFailr_DrvSeatMassFailr(POWER_LOAD_STATUS_NORMAL);
}

static void _Snf_Power_Load_Pump_Short_Circuit_Callback(void)
{
    Rte_Call_Event_Cfg_D_Event_0x9D0319_SetEventStatus(DEM_EVENT_STATUS_FAILED);
    RTE_PWM_SET_DUTY(RTE_PWM_CHANNEL_PUMP, RTE_PWM_DUTY_MIN);
    Snf_Pump_Set_Work_State(PUMP_WORK_STATE_OFF, PUMP_ALL_MODULE_DISABLE_WORK_MASK);
    Snf_Valve_Set_Work_State(VALVE_WORK_STATE_OFF, VALVE_ALL_MODULE_DISABLE_WORK_MASK);
    Rte_Write_DrvSystemFailr_DrvSystemFailr(POWER_LOAD_STATUS_ABNORMAL);
    Rte_Write_DrvSeatMassFailr_DrvSeatMassFailr(POWER_LOAD_STATUS_ABNORMAL);
}

static void _Snf_Power_Load_Valve_Short_Circuit_Callback(void)
{
    Rte_Call_Event_Cfg_D_Event_0x9D0119_SetEventStatus(DEM_EVENT_STATUS_FAILED);
    RTE_PWM_SET_DUTY(RTE_PWM_CHANNEL_PUMP, RTE_PWM_DUTY_MIN);
    Snf_Pump_Set_Work_State(PUMP_WORK_STATE_OFF, PUMP_ALL_MODULE_DISABLE_WORK_MASK);
    Snf_Valve_Set_Work_State(VALVE_WORK_STATE_OFF, VALVE_ALL_MODULE_DISABLE_WORK_MASK);
    Rte_Write_DrvSystemFailr_DrvSystemFailr(POWER_LOAD_STATUS_ABNORMAL);
    Rte_Write_DrvSeatMassFailr_DrvSeatMassFailr(POWER_LOAD_STATUS_ABNORMAL);
}

/**
 * @brief Set the DSEL pin for the specified channel.
 * 
 * @param channel The channel to set the DSEL pin for.
 */
static void _Snf_Power_Load_Set_Dsel(void)
{
    if (power_load_active_channel >= POWER_LOAD_CHANNEL_MAX)
    {
        power_load_active_channel = 0U;
    }

    if (power_load_channel != power_load_active_channel)
    {
        switch (power_load_active_channel)
        {
            case POWER_LOAD_CHANNEL_PUMP:
                RTE_GPIO_PUMP_DSEL_ENABLE();
                break;
            case POWER_LOAD_CHANNEL_VALVE:
                RTE_GPIO_VALVE_DSEL_ENABLE();
                break;
            default:
                break;
        }
        power_load_channel = power_load_active_channel;
    }
}

/**
 * @brief Get the ADC value for the specified channel.
 * 
 * @param channel The channel to get the ADC value for.
 */
static uint16_t _Snf_Power_Load_Get_Adc_Value(power_load_channel_e channel)
{
    uint16_t adc_value = 0U;

    switch (channel)
    {
        case POWER_LOAD_CHANNEL_PUMP:
            adc_value = (uint16_t)POWER_PUMP_VALVE_AD_TO_VCS(RTE_ADC_GET_PUMP_VALVE_IS());
            break;
        case POWER_LOAD_CHANNEL_VALVE:
            adc_value = (uint16_t)POWER_PUMP_VALVE_AD_TO_VCS(RTE_ADC_GET_PUMP_VALVE_IS());
            break;
        default:
            break;
    }
    return adc_value;
}

/************************ Public Function Implementations ************************/
/**
 * @brief Initialize the power load detection.
 * 
 * This function initializes the power load detection by setting the initial status of all channels to normal.
 */
void Snf_Power_Load_Init(void)
{
    power_load_det_last_update_time = RTE_OS_GET_TICK();
    power_load_channel_timeout      = RTE_OS_GET_TICK();
    for (uint8_t i = 0U; i < POWER_LOAD_CHANNEL_MAX; i++)
    {
        power_load_status[i] = POWER_LOAD_STATUS_NORMAL;
    }
    memcpy(&load_detection[0], &s_power_load_detection_table[0], sizeof(s_power_load_detection_table));
}

/**
 * @brief Task function for the power load detection.
 * 
 * This function is the main task function for the power load detection. It updates the status of each channel and calls the corresponding callback function if the status changes.
 */
void Snf_Power_Load_Task(void)
{
    if (false == RTE_OS_IS_TIMEOUT(power_load_det_last_update_time, POWER_LOAD_TASK_TIMEOUT))
    {
        return;
    }
    power_load_det_last_update_time = RTE_OS_GET_TICK();
    uint16_t adc_value              = 0U;

    _Snf_Power_Load_Set_Dsel();
    //避免设置IO后立即读取ADC值，导致读取到的是上一个IO状态的ADC值
    if (false == RTE_OS_IS_TIMEOUT(power_load_channel_timeout, POWER_LOAD_CHANNEL_PERIOD_MS))
    {
        return;
    }
    power_load_channel_timeout = RTE_OS_GET_TICK();
    power_load_active_channel++;

    if (Rte_Call_Sync_C_Power_S_Valve_Get_Work_States() != VALVE_WORK_STATE_ON ||
        Rte_Call_Sync_C_Power_S_Pump_Get_Work_States() != PUMP_WORK_STATE_ON)
    {
        return;
    }

    for (uint8_t i = 0U; i < POWER_LOAD_DETECTION_TABLE_SIZE; i++)
    {
        if (load_detection[i].channel != power_load_channel)
        {
            continue;
        }

        //判断是否在正常范围内
        adc_value = _Snf_Power_Load_Get_Adc_Value(load_detection[i].channel);
        if ((load_detection[i].current_min <= adc_value) && (adc_value < load_detection[i].current_max))
        {
            if (0U == load_detection[i].confirm_time_ms)
            {
                load_detection[i].confirm_time_ms = RTE_OS_GET_TICK();
            }
            else if (RTE_OS_IS_TIMEOUT(load_detection[i].confirm_time_ms, POWER_LOAD_ADC_STABLE_TIME_MS))
            {
                if (load_detection[i].detection_callback != NULL &&
                    (load_detection[i].status != power_load_status[load_detection[i].channel]))
                {
                    power_load_status[load_detection[i].channel] = load_detection[i].status;
                    load_detection[i].detection_callback();
                }
                load_detection[i].confirm_time_ms = 0U;
            }
        }
        else
        {
            load_detection[i].confirm_time_ms = 0U;
        }
    }
}

power_load_status_e Snf_Power_Load_Get_State(power_load_channel_e channel)
{
    return power_load_status[channel];
}

void Snf_Power_Set_Load_Status(power_load_channel_e channel, power_load_status_e status)
{
    power_load_status[channel] = status;
}