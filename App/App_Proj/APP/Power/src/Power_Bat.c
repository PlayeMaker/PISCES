/************************ Include Files ************************/
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "Rte_Type.h"
#include "Rte_Dem.h"
#include "Power_Bat.h"
#include "Power_Class.h"
#include "Power_Def.h"
#include "Rte_Adc.h"
#include "Rte_Adc_If.h"
#include "Rte_Log.h"
#include "Rte_Os.h"
#include "Rte_Swc.h"

/************************ Macro Definitions ************************/
#ifdef POWER_PRINTF_ENABLE
#define POWER_LOG_PRINTF RTE_LOG_PRINTF
#else
#define POWER_LOG_PRINTF(...)
#endif

/************************ Private Function Declarations ************************/
static void _Snf_Power_Bat_Low_Voltage_Callback(void);
static void _Snf_Power_Bat_Normal_Voltage_Callback(void);
static void _Snf_Power_Bat_Over_Voltage_Callback(void);

/************************ Private Global Variables ************************/
static power_bat_status_e           power_bat_status      = POWER_BAT_STATUS_NORMAL;
static const power_bat_detection_t* power_bat_pending_ptr = NULL;  //待定区间表项(含状态与回调)
static uint32_t                     power_bat_last_tick   = 0U;    //上次检测执行时间
static uint16_t                     power_bat_pending_cnt = 0U;    //待定区间持续计数

/************************ Battery Detection Table ************************/
#include "Power_Bat_Def.h"

/************************ Private Function Implementations ************************/
static void _Snf_Power_Bat_Low_Voltage_Callback(void)
{
    Rte_Call_EnableCond_PowerVoltage_9V_16V_SetEnableCondition(FALSE);
#if defined(PISCES_MCM_D)
    Rte_Call_Event_Cfg_D_Event_0x800116_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
#elif defined(PISCES_MCM_P)
    Rte_Call_Event_Cfg_P_Event_0x800116_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
#endif
    Rte_Call_Sync_C_Power_S_Valve_Set_Work_States(VALVE_WORK_STATE_OFF, VALVE_ALL_MODULE_DISABLE_WORK_MASK);
    Rte_Call_Sync_C_Power_S_Pump_Set_Work_States(PUMP_WORK_STATE_OFF, PUMP_ALL_MODULE_DISABLE_WORK_MASK);
}

static void _Snf_Power_Bat_Normal_Voltage_Callback(void)
{
    Rte_Call_EnableCond_PowerVoltage_9V_16V_SetEnableCondition(TRUE);
#if defined(PISCES_MCM_D)
    Rte_Call_Event_Cfg_D_Event_0x800116_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
    Rte_Call_Event_Cfg_D_Event_0x800117_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
#elif defined(PISCES_MCM_P)
    Rte_Call_Event_Cfg_P_Event_0x800116_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
    Rte_Call_Event_Cfg_P_Event_0x800117_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);
#endif
}

static void _Snf_Power_Bat_Over_Voltage_Callback(void)
{
    Rte_Call_EnableCond_PowerVoltage_9V_16V_SetEnableCondition(FALSE);
#if defined(PISCES_MCM_D)
    Rte_Call_Event_Cfg_D_Event_0x800117_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
#elif defined(PISCES_MCM_P)
    Rte_Call_Event_Cfg_P_Event_0x800117_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
#endif
    Rte_Call_Sync_C_Power_S_Valve_Set_Work_States(VALVE_WORK_STATE_OFF, VALVE_ALL_MODULE_DISABLE_WORK_MASK);
    Rte_Call_Sync_C_Power_S_Pump_Set_Work_States(PUMP_WORK_STATE_OFF, PUMP_ALL_MODULE_DISABLE_WORK_MASK);
}

/************************ Public Function Implementations ************************/
void Snf_Power_Bat_Init(void)
{
    power_bat_status      = POWER_BAT_STATUS_NORMAL;
    power_bat_pending_ptr = NULL;
    power_bat_last_tick   = RTE_OS_GET_TICK();
    power_bat_pending_cnt = 0U;
}

/**
 * @brief  电池电压检测任务
 * @param  None
 * @return None
 * @note   状态切换统一防抖：检测到某个电压区间并持续 POWER_BAT_STATUS_CONFIRM_TIME_MS 后，
 *         才切换到对应状态并执行回调；区间变化或无匹配区间时重新计时。
 */
void Snf_Power_Bat_Task(void)
{
    if (false == RTE_OS_IS_TIMEOUT(power_bat_last_tick, POWER_BAT_DETECTION_UPDATE_CYCLE))
    {
        return;
    }
    power_bat_last_tick = RTE_OS_GET_TICK();

    uint16_t bat_vol = Snf_Power_Get_Bat_Voltage();

    /* 查表确定当前电压所属区间 */
    const power_bat_detection_t* detection_ptr = NULL;
    for (uint8_t i = 0U; i < s_power_bat_detection_table_size; i++)
    {
        if ((s_power_bat_detection_table[i].voltage_min < bat_vol && s_power_bat_detection_table[i].voltage_max > bat_vol) ||
            (s_power_bat_detection_table[i].voltage_max == bat_vol))
        {
            detection_ptr = &s_power_bat_detection_table[i];
            break;
        }
    }

    /* 区间变化或无匹配区间：更新待定区间并重新计时，等待持续稳定 */
    if (detection_ptr != power_bat_pending_ptr)
    {
        power_bat_pending_ptr = detection_ptr;
        power_bat_pending_cnt = 0U;
        return;
    }

    /* 区间持续中：计时(饱和后保持) */
    if (power_bat_pending_cnt < (uint16_t)POWER_BAT_STATUS_CONFIRM_COUNT)
    {
        power_bat_pending_cnt++;
    }

    /* 区间已持续确认时间且与当前生效状态不同：切换状态并执行对应回调 */
    if ((NULL != detection_ptr) && (detection_ptr->status != power_bat_status) &&
        (power_bat_pending_cnt >= (uint16_t)POWER_BAT_STATUS_CONFIRM_COUNT))
    {
        power_bat_status = detection_ptr->status;
        POWER_LOG_PRINTF("Battery status: %d, voltage: %d\r\n", power_bat_status, bat_vol);
        if (NULL != detection_ptr->detection_callback)
        {
            detection_ptr->detection_callback();
        }
    }
}

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
 * @brief  Get battery status
 * @param  None
 * @return Battery status
 */
power_bat_status_e Snf_Power_Bat_Get_State(void)
{
    return power_bat_status;
}