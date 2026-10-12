/************************ Include Files ************************/
#include "Basic_Config.h"
#include "Stack.h"
#include "EcuM.h"
#include "CanTP.h"
#include "Com.h"
#include "ComM.h"
#include "CanSM.h"
#include "Dem.h"
#include "BswM.h"
#include "Rte_Log.h"
#include "Rte_Os.h"
#include "Valve.h"
#include "Pump.h"
#include "Rte_Dem.h"
#include "Rte_Swc.h"
/************************ Macro Definitions ************************/
#ifdef STACK_PRINTF_ENABLE
#define STACK_PRINTF RTE_LOG_PRINTF
#else
#define STACK_PRINTF(...)
#endif

#define VEHICLE_STATE_DRIVING 0x01
#define VEHICLE_STATE_DRVRDY  0x02

#define STACK_LOW_VOLTAGE_STOP_MV       6000   // 6V
#define STACK_LOW_VOLTAGE_RECOVER_MV    6500   // 6.5V
#define STACK_LOW_VOLTAGE_DEBOUNCE_CNT  100    // 100 * 10ms = 1000ms
#define STACK_LOW_VOLTAGE_CHECK_TIMEOUT 10     // 10ms

/************************ Private Global Variables ************************/
static uint32_t can_tp_last_update_time = 0;
static uint32_t dtc_enable_last_update_time = 0;
static bool     can_network_status = TRUE;                  // TRUE : no bus off, FALSE : bus off
static bool     low_voltage_stop_flag = FALSE;              // TRUE : low voltage, stop communication
static uint8_t  low_voltage_debounce_cnt = 0;
static uint32_t low_voltage_last_check_time = 0;
static uint32_t dtc_enable_power_ign_time = 0;
static uint32_t dtc_enable_network_mode_time = 0;
static uint32_t dtc_enable_vehicle_drvrdy_time = 0;
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Can_Manager_Handle(void);
static void _Snf_Can_Process_Handle(void);
static void _Snf_Low_Voltage_Handle(void);
/************************ Private Function Implementations ************************/
/**
 * @brief  Low voltage protection handle, stop CAN communication when battery voltage is too low
 * @param  None
 * @return None
 */
static void _Snf_Low_Voltage_Handle(void)
{
    uint16_t bat_voltage = Rte_Call_Sync_C_Stack_S_Power_Get_Bat_Voltage();

    if (low_voltage_stop_flag == FALSE)
    {
        if (bat_voltage <= STACK_LOW_VOLTAGE_STOP_MV)
        {
            low_voltage_debounce_cnt++;
            if (low_voltage_debounce_cnt >= STACK_LOW_VOLTAGE_DEBOUNCE_CNT)
            {
                low_voltage_stop_flag = TRUE;
                low_voltage_debounce_cnt = 0;
                ComM_RequestComMode(ComM_USERID_User0, COMM_NO_COMMUNICATION);
            }
        }
        else
        {
            low_voltage_debounce_cnt = 0;
        }
    }
    else
    {
        if (bat_voltage >= STACK_LOW_VOLTAGE_RECOVER_MV)
        {
            low_voltage_debounce_cnt++;
            if (low_voltage_debounce_cnt >= STACK_LOW_VOLTAGE_DEBOUNCE_CNT)
            {
                low_voltage_stop_flag = FALSE;
                low_voltage_debounce_cnt = 0;
                ComM_RequestComMode(ComM_USERID_User0, COMM_FULL_COMMUNICATION);
            }
        }
        else
        {
            low_voltage_debounce_cnt = 0;
        }
    }
}

/**
 * @brief   Stack CAN manager handle
 * @param  None
 * @return None
 */
static void _Snf_Can_Manager_Handle(void)
{
    if (RTE_OS_IS_TIMEOUT(can_tp_last_update_time, STACK_CAN_TP_TIMEOUT))
    {
        can_tp_last_update_time = RTE_OS_GET_TICK();
        Com_MainFunctionRx();
        Com_MainFunctionTx();
        CanTp_MainFunction();
        Dcm_MainFunction();
        Dem_MainFunction();
    }

    if (RTE_OS_IS_TIMEOUT(low_voltage_last_check_time, STACK_LOW_VOLTAGE_CHECK_TIMEOUT))
    {
        low_voltage_last_check_time = RTE_OS_GET_TICK();
        _Snf_Low_Voltage_Handle();
    }

}
/**
 * @brief  Stack CAN process handle
 * @param  None
 * @return None
 */
static void _Snf_Can_Process_Handle(void)
{
    EcuM_MainFunction();
    CanSM_MainFunction();
    ComM_MainFunction(ComM_ComM_BODY_LE1_CAN);
    BswM_MainFunction();
}

static void _Snf_Dtc_Enable_Condition_Handle(void)
{
    if(RTE_OS_IS_TIMEOUT(dtc_enable_last_update_time, STACK_DTC_ENABLE_TIMEOUT) == false)
    {
        return ;
    }

    dtc_enable_last_update_time = RTE_OS_GET_TICK();

    if(Rte_Call_Sync_C_Stack_S_Pump_Get_Work_States() == PUMP_WORK_STATE_ON)
    {
        Rte_Call_EnableCond_TheAirPumpIsStarted_SetEnableCondition(TRUE);
    }
    else
    {
        Rte_Call_EnableCond_TheAirPumpIsStarted_SetEnableCondition(FALSE);
    }

    if(Rte_Call_Sync_C_Stack_S_Valve_Get_Work_States() == VALVE_WORK_STATE_ON)
    {
        Rte_Call_EnableCond_TheValveIStarted_SetEnableCondition(TRUE);
    }
    else
    {
        Rte_Call_EnableCond_TheValveIStarted_SetEnableCondition(FALSE);
    }
    /* 暂无加热功能 */
    // Rte_Call_EnableCond_TheHeatorIStarted_SetEnableCondition(TRUE);

    if(can_network_status == TRUE)
    {
        Rte_Call_EnableCond_NotInBusoffStatus_SetEnableCondition(TRUE);
        Rte_Call_EnableCond_StopMonitoringImmediatelyWhenNotInNetworkMode_SetEnableCondition(TRUE);
        if(RTE_OS_IS_TIMEOUT(dtc_enable_network_mode_time, STACK_DTC_ENABLE_CONDITION_TIMEOUT2))
        {
            Rte_Call_EnableCond_EnteringNetworkModeFor3s_SetEnableCondition(TRUE);           //网络模式
        }
    }
    else
    {
        Rte_Call_EnableCond_NotInBusoffStatus_SetEnableCondition(FALSE);
        Rte_Call_EnableCond_StopMonitoringImmediatelyWhenNotInNetworkMode_SetEnableCondition(FALSE);
        Rte_Call_EnableCond_EnteringNetworkModeFor3s_SetEnableCondition(FALSE);
        dtc_enable_network_mode_time = RTE_OS_GET_TICK();
    }

    if(RTE_OS_IS_TIMEOUT(dtc_enable_power_ign_time, STACK_DTC_ENABLE_CONDITION_TIMEOUT1))
    {
        Rte_Call_EnableCond_AfterPowerIGN_1s_SetEnableCondition(TRUE);           //电源ign
    }

    uint8_t veh_state = 0;
    Rte_Read_Com_VehStateDetailed_SrvSts_VehStateDetailed_SrvSts(&veh_state);
    if((veh_state == VEHICLE_STATE_DRIVING || veh_state == VEHICLE_STATE_DRVRDY)){
        if(RTE_OS_IS_TIMEOUT(dtc_enable_vehicle_drvrdy_time, STACK_DTC_ENABLE_CONDITION_TIMEOUT3)){
            Rte_Call_EnableCond_VehState_Driving_or_DrvRdy_for_3seconds_SetEnableCondition(TRUE);           //车辆模式
        }
    }else{
        dtc_enable_vehicle_drvrdy_time = RTE_OS_GET_TICK();
        Rte_Call_EnableCond_VehState_Driving_or_DrvRdy_for_3seconds_SetEnableCondition(FALSE);           
    }
    
}
/************************ Public Function Implementations ************************/
/**
 * @brief  Stack task function initialization
 * @param  None
 * @return None
 */
void Snf_Stack_Task_Init(void)
{
    EcuM_Init();
    EcuM_StartupTwo();

    EcuM_RequestRUN(EcuM_USERID_User0);
    ComM_RequestComMode(ComM_USERID_User0, COMM_FULL_COMMUNICATION);

    can_tp_last_update_time = RTE_OS_GET_TICK();
    dtc_enable_last_update_time = RTE_OS_GET_TICK();

    dtc_enable_power_ign_time = RTE_OS_GET_TICK();
    dtc_enable_network_mode_time = RTE_OS_GET_TICK();
    dtc_enable_vehicle_drvrdy_time = RTE_OS_GET_TICK();

}

/**
 * @brief  Stack task function
 * @param  None
 * @return None
 */
void Snf_Stack_Task(void)
{
    _Snf_Can_Manager_Handle();
    _Snf_Can_Process_Handle();
    _Snf_Dtc_Enable_Condition_Handle();
}

/**
 * @brief  Set stack can network status. TRUE : no bus off, FALSE : bus off
 * @param  status: The can network status to set
 * @return None
 */
void Set_Stack_CanNetwork_Status(bool status)
{
    can_network_status = status;
}