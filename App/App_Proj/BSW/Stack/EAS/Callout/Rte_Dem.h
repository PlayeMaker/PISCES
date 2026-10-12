/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_Dem.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Rte module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Rte module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/

/*****************************************************************************
*  General QAC Suppression
*****************************************************************************/
/*PRQA S 3432 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no
need to revise.
*/

/*PRQA S 776,777,778,779,791,792 EOF*/
/*
Names in this file may not follow relevant rules.
*/

/*PRQA S 3453,3429,1753 EOF*/
/*
A function-like macro is being defined. But this form is prescribed by autosar.
*/

/*PRQA S 5087 EOF*/
/*
Use of #include directive after code fragment.
*/


#ifndef RTE_DEM_H
#define RTE_DEM_H

#ifndef RTE_CORE
#ifdef RTE_APPLICATION_HEADER_FILE
#error Multiple application header files included.
#endif /* RTE_APPLICATION_HEADER_FILE */
#define RTE_APPLICATION_HEADER_FILE
#endif
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Dem.h"
#include "Rte_Dem_Type.h"
#define Rte_Call_ClearDTC_DemClient_0_ClearDTC()            Dem_ClearDTC(Dem_DemClient_0)
#define Rte_Call_ClearDTC_DemClient_0_SelectDTC(DTC, DTCFormat, DTCOrigin)      Dem_SelectDTC(Dem_DemClient_0, DTC, DTCFormat, DTCOrigin)
#define Rte_Call_EnableCond_AfterPowerIGN_1s_SetEnableCondition(ConditionFulfilled)       Dem_SetEnableCondition(Dem_EnableCond_AfterPowerIGN_1s, ConditionFulfilled)
#define Rte_Call_EnableCond_ECU_ActiveStatus_SetEnableCondition(ConditionFulfilled)       Dem_SetEnableCondition(Dem_EnableCond_ECU_ActiveStatus, ConditionFulfilled)
#define Rte_Call_EnableCond_EnteringNetworkModeFor3s_SetEnableCondition(ConditionFulfilled)         Dem_SetEnableCondition(Dem_EnableCond_EnteringNetworkModeFor3s, ConditionFulfilled)
#define Rte_Call_EnableCond_IGNPowerOn_SetEnableCondition(ConditionFulfilled)   Dem_SetEnableCondition(Dem_EnableCond_IGNPowerOn, ConditionFulfilled)
#define Rte_Call_EnableCond_NotInBusoffStatus_SetEnableCondition(ConditionFulfilled)      Dem_SetEnableCondition(Dem_EnableCond_NotInBusoffStatus, ConditionFulfilled)
#define Rte_Call_EnableCond_OnlyDracoHorizonVersion_SetEnableCondition(ConditionFulfilled)          Dem_SetEnableCondition(Dem_EnableCond_OnlyDracoHorizonVersion, ConditionFulfilled)
#define Rte_Call_EnableCond_PowerVoltage_9V_16V_SetEnableCondition(ConditionFulfilled)    Dem_SetEnableCondition(Dem_EnableCond_PowerVoltage_9V_16V, ConditionFulfilled)
#define Rte_Call_EnableCond_StopMonitoringImmediatelyWhenNotInNetworkMode_SetEnableCondition(ConditionFulfilled)        Dem_SetEnableCondition(Dem_EnableCond_StopMonitoringImmediatelyWhenNotInNetworkMode, ConditionFulfilled)
#define Rte_Call_EnableCond_TheAirPumpIsStarted_SetEnableCondition(ConditionFulfilled)    Dem_SetEnableCondition(Dem_EnableCond_TheAirPumpIsStarted, ConditionFulfilled)
#define Rte_Call_EnableCond_TheHeatorIStarted_SetEnableCondition(ConditionFulfilled)      Dem_SetEnableCondition(Dem_EnableCond_TheHeatorIStarted, ConditionFulfilled)
#define Rte_Call_EnableCond_TheValveIStarted_SetEnableCondition(ConditionFulfilled)       Dem_SetEnableCondition(Dem_EnableCond_TheValveIStarted, ConditionFulfilled)
#define Rte_Call_EnableCond_VehState_Driving_or_DrvRdy_for_3seconds_SetEnableCondition(ConditionFulfilled)    Dem_SetEnableCondition(Dem_EnableCond_VehState_Driving_or_DrvRdy_for_3seconds, ConditionFulfilled)
#define Rte_Call_EventInfo_Cfg_D_Event_0x800116_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0x800116, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0x800116_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_D_Event_0x800116, DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0x800116_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0x800116, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x800116_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0x800116, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x800116_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0x800116, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x800116_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0x800116, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0x800116_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0x800116, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0x800116_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0x800116, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x800117_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0x800117, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0x800117_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_D_Event_0x800117, DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0x800117_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0x800117, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x800117_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0x800117, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x800117_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0x800117, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x800117_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0x800117, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0x800117_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0x800117, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0x800117_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0x800117, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0119_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0x9C0119, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0119_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_D_Event_0x9C0119, DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0119_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0x9C0119, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0119_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0x9C0119, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0119_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0x9C0119, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0119_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0x9C0119, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0119_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0x9C0119, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0119_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0x9C0119, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0218_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0x9C0218, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0218_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_D_Event_0x9C0218, DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0218_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0x9C0218, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0218_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0x9C0218, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0218_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0x9C0218, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0218_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0x9C0218, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0218_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0x9C0218, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0218_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0x9C0218, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0311_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0x9C0311, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0311_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_D_Event_0x9C0311, DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0311_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0x9C0311, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0311_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0x9C0311, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0311_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0x9C0311, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0311_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0x9C0311, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0311_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0x9C0311, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0311_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0x9C0311, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0415_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0x9C0415, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0415_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_D_Event_0x9C0415, DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0415_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0x9C0415, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0415_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0x9C0415, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0415_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0x9C0415, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0415_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0x9C0415, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0415_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0x9C0415, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0415_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0x9C0415, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0511_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0x9C0511, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0511_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_D_Event_0x9C0511, DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0511_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0x9C0511, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0511_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0x9C0511, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0511_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0x9C0511, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0511_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0x9C0511, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0511_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0x9C0511, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0511_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0x9C0511, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0615_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0x9C0615, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0615_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_D_Event_0x9C0615, DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0615_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0x9C0615, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0615_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0x9C0615, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0615_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0x9C0615, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0615_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0x9C0615, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0615_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0x9C0615, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9C0615_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0x9C0615, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0119_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0x9D0119, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0119_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_D_Event_0x9D0119, DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0119_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0x9D0119, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0119_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0x9D0119, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0119_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0x9D0119, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0119_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0x9D0119, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0119_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0x9D0119, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0119_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0x9D0119, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0218_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0x9D0218, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0218_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_D_Event_0x9D0218, DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0218_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0x9D0218, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0218_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0x9D0218, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0218_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0x9D0218, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0218_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0x9D0218, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0218_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0x9D0218, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0218_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0x9D0218, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0319_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0x9D0319, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0319_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_D_Event_0x9D0319, DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0319_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0x9D0319, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0319_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0x9D0319, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0319_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0x9D0319, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0319_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0x9D0319, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0319_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0x9D0319, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0319_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0x9D0319, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0418_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0x9D0418, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0418_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_D_Event_0x9D0418, DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0418_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0x9D0418, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0418_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0x9D0418, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0418_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0x9D0418, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0418_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0x9D0418, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0418_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0x9D0418, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0418_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0x9D0418, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0511_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0x9D0511, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0511_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0511_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0x9D0511, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0511_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0x9D0511, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0511_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0x9D0511, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0511_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0x9D0511, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0511_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0x9D0511, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0511_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0x9D0511, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0615_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0x9D0615, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0615_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0615_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0x9D0615, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0615_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0x9D0615, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0615_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0x9D0615, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0615_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0x9D0615, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0615_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0x9D0615, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0x9D0615_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0x9D0615, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0xC00B88_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0xC00B88, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0xC00B88_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_D_Event_0xC00B88, DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0xC00B88_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0xC00B88, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0xC00B88_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0xC00B88, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0xC00B88_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0xC00B88, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0xC00B88_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0xC00B88, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0xC00B88_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0xC00B88, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0xC00B88_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0xC00B88, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF13C87_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0xF13C87, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF13C87_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF13C87_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0xF13C87, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF13C87_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0xF13C87, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF13C87_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0xF13C87, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF13C87_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0xF13C87, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF13C87_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0xF13C87, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF13C87_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0xF13C87, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF1D187_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0xF1D187, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF1D187_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF1D187_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0xF1D187, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF1D187_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0xF1D187, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF1D187_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0xF1D187, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF1D187_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0xF1D187, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF1D187_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0xF1D187, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF1D187_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0xF1D187, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF1D287_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0xF1D287, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF1D287_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF1D287_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0xF1D287, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF1D287_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0xF1D287, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF1D287_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0xF1D287, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF1D287_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0xF1D287, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF1D287_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0xF1D287, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF1D287_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0xF1D287, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF3A987_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0xF3A987, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF3A987_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF3A987_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0xF3A987, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF3A987_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0xF3A987, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF3A987_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0xF3A987, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF3A987_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0xF3A987, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF3A987_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0xF3A987, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF3A987_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0xF3A987, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF3B287_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_D_Event_0xF3B287, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF3B287_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(DebouncingState)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF3B287_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_D_Event_0xF3B287, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF3B287_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_D_Event_0xF3B287, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF3B287_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_D_Event_0xF3B287, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF3B287_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_D_Event_0xF3B287, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF3B287_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_D_Event_0xF3B287, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_D_Event_0xF3B287_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_D_Event_0xF3B287, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x800116_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0x800116, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0x800116_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_P_Event_0x800116, DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0x800116_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0x800116, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x800116_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0x800116, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x800116_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0x800116, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x800116_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0x800116, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0x800116_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0x800116, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0x800116_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0x800116, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x800117_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0x800117, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0x800117_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_P_Event_0x800117, DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0x800117_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0x800117, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x800117_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0x800117, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x800117_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0x800117, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x800117_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0x800117, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0x800117_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0x800117, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0x800117_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0x800117, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0119_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0x9C0119, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0119_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_P_Event_0x9C0119, DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0119_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0x9C0119, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0119_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0x9C0119, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0119_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0x9C0119, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0119_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0x9C0119, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0119_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0x9C0119, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0119_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0x9C0119, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0218_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0x9C0218, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0218_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_P_Event_0x9C0218, DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0218_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0x9C0218, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0218_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0x9C0218, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0218_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0x9C0218, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0218_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0x9C0218, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0218_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0x9C0218, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0218_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0x9C0218, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0311_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0x9C0311, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0311_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_P_Event_0x9C0311, DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0311_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0x9C0311, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0311_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0x9C0311, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0311_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0x9C0311, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0311_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0x9C0311, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0311_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0x9C0311, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0311_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0x9C0311, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0415_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0x9C0415, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0415_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_P_Event_0x9C0415, DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0415_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0x9C0415, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0415_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0x9C0415, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0415_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0x9C0415, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0415_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0x9C0415, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0415_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0x9C0415, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0415_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0x9C0415, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0511_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0x9C0511, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0511_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_P_Event_0x9C0511, DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0511_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0x9C0511, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0511_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0x9C0511, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0511_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0x9C0511, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0511_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0x9C0511, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0511_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0x9C0511, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0511_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0x9C0511, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0615_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0x9C0615, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0615_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_P_Event_0x9C0615, DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0615_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0x9C0615, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0615_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0x9C0615, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0615_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0x9C0615, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0615_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0x9C0615, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0615_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0x9C0615, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9C0615_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0x9C0615, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0119_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0x9D0119, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0119_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_P_Event_0x9D0119, DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0119_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0x9D0119, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0119_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0x9D0119, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0119_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0x9D0119, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0119_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0x9D0119, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0119_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0x9D0119, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0119_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0x9D0119, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0218_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0x9D0218, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0218_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_P_Event_0x9D0218, DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0218_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0x9D0218, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0218_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0x9D0218, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0218_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0x9D0218, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0218_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0x9D0218, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0218_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0x9D0218, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0218_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0x9D0218, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0319_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0x9D0319, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0319_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_P_Event_0x9D0319, DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0319_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0x9D0319, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0319_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0x9D0319, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0319_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0x9D0319, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0319_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0x9D0319, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0319_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0x9D0319, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0319_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0x9D0319, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0418_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0x9D0418, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0418_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_P_Event_0x9D0418, DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0418_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0x9D0418, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0418_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0x9D0418, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0418_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0x9D0418, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0418_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0x9D0418, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0418_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0x9D0418, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0418_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0x9D0418, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0511_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0x9D0511, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0511_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0511_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0x9D0511, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0511_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0x9D0511, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0511_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0x9D0511, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0511_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0x9D0511, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0511_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0x9D0511, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0511_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0x9D0511, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0615_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0x9D0615, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0615_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0615_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0x9D0615, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0615_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0x9D0615, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0615_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0x9D0615, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0615_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0x9D0615, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0615_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0x9D0615, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0x9D0615_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0x9D0615, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0xC00B88_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0xC00B88, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0xC00B88_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(Cfg_P_Event_0xC00B88, DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0xC00B88_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0xC00B88, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0xC00B88_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0xC00B88, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0xC00B88_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0xC00B88, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0xC00B88_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0xC00B88, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0xC00B88_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0xC00B88, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0xC00B88_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0xC00B88, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF13C87_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0xF13C87, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF13C87_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF13C87_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0xF13C87, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF13C87_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0xF13C87, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF13C87_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0xF13C87, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF13C87_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0xF13C87, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF13C87_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0xF13C87, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF13C87_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0xF13C87, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF1D387_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0xF1D387, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF1D387_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF1D387_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0xF1D387, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF1D387_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0xF1D387, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF1D387_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0xF1D387, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF1D387_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0xF1D387, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF1D387_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0xF1D387, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF1D387_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0xF1D387, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF1D487_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0xF1D487, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF1D487_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF1D487_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0xF1D487, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF1D487_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0xF1D487, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF1D487_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0xF1D487, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF1D487_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0xF1D487, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF1D487_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0xF1D487, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF1D487_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0xF1D487, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF3A987_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0xF3A987, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF3A987_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF3A987_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0xF3A987, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF3A987_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0xF3A987, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF3A987_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0xF3A987, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF3A987_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0xF3A987, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF3A987_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0xF3A987, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF3A987_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0xF3A987, MonitorStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF3B287_GetDTCOfEvent(DTCFormat, DTCOfEvent)      Dem_GetDTCOfEvent(Cfg_P_Event_0xF3B287, DTCFormat, DTCOfEvent)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF3B287_GetDebouncingOfEvent(DebouncingState)     Dem_GetDebouncingOfEvent(DebouncingState)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF3B287_GetEventAvailable(AvailableStatus)        Dem_GetEventAvailable(Cfg_P_Event_0xF3B287, AvailableStatus)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF3B287_GetEventExtendedDataRecordEx(RecordNumber, DestBuffer, Bufsize)         Dem_GetEventExtendedDataRecordEx(Cfg_P_Event_0xF3B287, RecordNumber, DestBuffer, Bufsize)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF3B287_GetEventFreezeFrameDataEx(RecordNumber, DataId, DestBuffer, BufSize)    Dem_GetEventFreezeFrameDataEx(Cfg_P_Event_0xF3B287, RecordNumber, DataId, DestBuffer, BufSize)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF3B287_GetEventUdsStatus(UDSStatusByte)          Dem_GetEventUdsStatus(Cfg_P_Event_0xF3B287, UDSStatusByte)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF3B287_GetFaultDetectionCounter(FaultDetectionCounter)     Dem_GetFaultDetectionCounter(Cfg_P_Event_0xF3B287, FaultDetectionCounter)
#define Rte_Call_EventInfo_Cfg_P_Event_0xF3B287_GetMonitorStatus(MonitorStatus) Dem_GetMonitorStatus(Cfg_P_Event_0xF3B287, MonitorStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0x800116_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0x800116, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0x800117_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0x800117, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0x9C0119_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0x9C0119, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0x9C0218_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0x9C0218, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0x9C0311_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0x9C0311, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0x9C0415_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0x9C0415, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0x9C0511_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0x9C0511, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0x9C0615_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0x9C0615, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0x9D0119_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0x9D0119, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0x9D0218_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0x9D0218, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0x9D0319_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0x9D0319, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0x9D0418_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0x9D0418, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0x9D0511_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0x9D0511, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0x9D0615_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0x9D0615, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0xC00B88_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0xC00B88, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0xF13C87_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0xF13C87, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0xF1D187_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0xF1D187, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0xF1D287_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0xF1D287, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0xF3A987_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0xF3A987, WIRStatus)
#define Rte_Call_EventStatus_Cfg_D_Event_0xF3B287_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_D_Event_0xF3B287, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0x800116_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0x800116, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0x800117_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0x800117, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0x9C0119_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0x9C0119, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0x9C0218_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0x9C0218, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0x9C0311_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0x9C0311, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0x9C0415_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0x9C0415, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0x9C0511_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0x9C0511, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0x9C0615_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0x9C0615, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0x9D0119_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0x9D0119, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0x9D0218_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0x9D0218, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0x9D0319_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0x9D0319, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0x9D0418_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0x9D0418, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0x9D0511_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0x9D0511, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0x9D0615_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0x9D0615, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0xC00B88_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0xC00B88, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0xF13C87_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0xF13C87, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0xF1D387_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0xF1D387, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0xF1D487_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0xF1D487, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0xF3A987_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0xF3A987, WIRStatus)
#define Rte_Call_EventStatus_Cfg_P_Event_0xF3B287_SetWIRStatus(WIRStatus)       Dem_SetWIRStatus(Cfg_P_Event_0xF3B287, WIRStatus)
#define Rte_Call_Event_Cfg_D_Event_0x800116_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0x800116, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0x800116_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0x800116)
#define Rte_Call_Event_Cfg_D_Event_0x800116_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0x800116, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0x800117_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0x800117, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0x800117_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0x800117)
#define Rte_Call_Event_Cfg_D_Event_0x800117_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0x800117, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9C0119_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0x9C0119, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9C0119_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0x9C0119)
#define Rte_Call_Event_Cfg_D_Event_0x9C0119_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0x9C0119, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9C0218_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0x9C0218, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9C0218_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0x9C0218)
#define Rte_Call_Event_Cfg_D_Event_0x9C0218_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0x9C0218, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9C0311_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0x9C0311, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9C0311_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0x9C0311)
#define Rte_Call_Event_Cfg_D_Event_0x9C0311_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0x9C0311, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9C0415_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0x9C0415, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9C0415_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0x9C0415)
#define Rte_Call_Event_Cfg_D_Event_0x9C0415_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0x9C0415, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9C0511_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0x9C0511, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9C0511_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0x9C0511)
#define Rte_Call_Event_Cfg_D_Event_0x9C0511_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0x9C0511, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9C0615_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0x9C0615, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9C0615_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0x9C0615)
#define Rte_Call_Event_Cfg_D_Event_0x9C0615_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0x9C0615, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9D0119_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0x9D0119, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9D0119_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0x9D0119)
#define Rte_Call_Event_Cfg_D_Event_0x9D0119_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0x9D0119, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9D0218_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0x9D0218, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9D0218_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0x9D0218)
#define Rte_Call_Event_Cfg_D_Event_0x9D0218_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0x9D0218, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9D0319_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0x9D0319, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9D0319_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0x9D0319)
#define Rte_Call_Event_Cfg_D_Event_0x9D0319_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0x9D0319, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9D0418_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0x9D0418, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9D0418_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0x9D0418)
#define Rte_Call_Event_Cfg_D_Event_0x9D0418_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0x9D0418, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9D0511_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0x9D0511, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9D0511_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0x9D0511)
#define Rte_Call_Event_Cfg_D_Event_0x9D0511_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0x9D0511, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9D0615_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0x9D0615, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0x9D0615_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0x9D0615)
#define Rte_Call_Event_Cfg_D_Event_0x9D0615_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0x9D0615, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0xC00B88_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0xC00B88, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0xC00B88_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0xC00B88)
#define Rte_Call_Event_Cfg_D_Event_0xC00B88_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0xC00B88, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0xF13C87_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0xF13C87, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0xF13C87_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0xF13C87)
#define Rte_Call_Event_Cfg_D_Event_0xF13C87_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0xF13C87, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0xF1D187_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0xF1D187, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0xF1D187_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0xF1D187)
#define Rte_Call_Event_Cfg_D_Event_0xF1D187_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0xF1D187, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0xF1D287_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0xF1D287, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0xF1D287_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0xF1D287)
#define Rte_Call_Event_Cfg_D_Event_0xF1D287_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0xF1D287, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0xF3A987_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0xF3A987, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0xF3A987_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0xF3A987)
#define Rte_Call_Event_Cfg_D_Event_0xF3A987_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0xF3A987, DebounceResetStatus)
#define Rte_Call_Event_Cfg_D_Event_0xF3B287_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_D_Event_0xF3B287, EventStatus)
#define Rte_Call_Event_Cfg_D_Event_0xF3B287_ResetEventStatus()        Dem_ResetEventStatus(Cfg_D_Event_0xF3B287)
#define Rte_Call_Event_Cfg_D_Event_0xF3B287_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_D_Event_0xF3B287, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0x800116_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0x800116, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0x800116_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0x800116)
#define Rte_Call_Event_Cfg_P_Event_0x800116_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0x800116, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0x800117_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0x800117, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0x800117_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0x800117)
#define Rte_Call_Event_Cfg_P_Event_0x800117_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0x800117, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9C0119_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0x9C0119, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9C0119_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0x9C0119)
#define Rte_Call_Event_Cfg_P_Event_0x9C0119_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0x9C0119, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9C0218_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0x9C0218, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9C0218_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0x9C0218)
#define Rte_Call_Event_Cfg_P_Event_0x9C0218_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0x9C0218, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9C0311_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0x9C0311, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9C0311_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0x9C0311)
#define Rte_Call_Event_Cfg_P_Event_0x9C0311_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0x9C0311, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9C0415_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0x9C0415, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9C0415_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0x9C0415)
#define Rte_Call_Event_Cfg_P_Event_0x9C0415_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0x9C0415, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9C0511_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0x9C0511, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9C0511_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0x9C0511)
#define Rte_Call_Event_Cfg_P_Event_0x9C0511_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0x9C0511, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9C0615_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0x9C0615, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9C0615_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0x9C0615)
#define Rte_Call_Event_Cfg_P_Event_0x9C0615_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0x9C0615, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9D0119_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0x9D0119, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9D0119_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0x9D0119)
#define Rte_Call_Event_Cfg_P_Event_0x9D0119_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0x9D0119, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9D0218_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0x9D0218, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9D0218_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0x9D0218)
#define Rte_Call_Event_Cfg_P_Event_0x9D0218_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0x9D0218, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9D0319_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0x9D0319, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9D0319_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0x9D0319)
#define Rte_Call_Event_Cfg_P_Event_0x9D0319_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0x9D0319, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9D0418_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0x9D0418, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9D0418_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0x9D0418)
#define Rte_Call_Event_Cfg_P_Event_0x9D0418_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0x9D0418, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9D0511_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0x9D0511, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9D0511_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0x9D0511)
#define Rte_Call_Event_Cfg_P_Event_0x9D0511_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0x9D0511, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9D0615_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0x9D0615, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0x9D0615_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0x9D0615)
#define Rte_Call_Event_Cfg_P_Event_0x9D0615_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0x9D0615, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0xC00B88_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0xC00B88, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0xC00B88_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0xC00B88)
#define Rte_Call_Event_Cfg_P_Event_0xC00B88_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0xC00B88, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0xF13C87_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0xF13C87, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0xF13C87_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0xF13C87)
#define Rte_Call_Event_Cfg_P_Event_0xF13C87_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0xF13C87, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0xF1D387_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0xF1D387, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0xF1D387_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0xF1D387)
#define Rte_Call_Event_Cfg_P_Event_0xF1D387_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0xF1D387, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0xF1D487_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0xF1D487, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0xF1D487_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0xF1D487)
#define Rte_Call_Event_Cfg_P_Event_0xF1D487_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0xF1D487, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0xF3A987_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0xF3A987, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0xF3A987_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0xF3A987)
#define Rte_Call_Event_Cfg_P_Event_0xF3A987_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0xF3A987, DebounceResetStatus)
#define Rte_Call_Event_Cfg_P_Event_0xF3B287_SetEventStatus(EventStatus)         Dem_SetEventStatus(Cfg_P_Event_0xF3B287, EventStatus)
#define Rte_Call_Event_Cfg_P_Event_0xF3B287_ResetEventStatus()        Dem_ResetEventStatus(Cfg_P_Event_0xF3B287)
#define Rte_Call_Event_Cfg_P_Event_0xF3B287_ResetEventDebounceStatus(DebounceResetStatus) Dem_ResetEventDebounceStatus(Cfg_P_Event_0xF3B287, DebounceResetStatus)
#define Rte_Call_OpCycle_OperationCycle_DEM_IGNITION_GetCycleQualified(isQualified)       Dem_GetCycleQualified(Dem_OpCycle_OperationCycle_DEM_IGNITION, isQualified)
#define Rte_Call_OpCycle_OperationCycle_DEM_IGNITION_RestartOperationCycle()    Dem_RestartOperationCycle(Dem_OpCycle_OperationCycle_DEM_IGNITION)
#define Rte_Call_OpCycle_OperationCycle_DEM_IGNITION_SetCycleQualified()        Dem_SetCycleQualified(Dem_OpCycle_OperationCycle_DEM_IGNITION)
#define Rte_Call_OpCycle_OperationCycle_DEM_WARMUP_GetCycleQualified(isQualified)         Dem_GetCycleQualified(Dem_OpCycle_OperationCycle_DEM_WARMUP, isQualified)
#define Rte_Call_OpCycle_OperationCycle_DEM_WARMUP_RestartOperationCycle()      Dem_RestartOperationCycle(Dem_OpCycle_OperationCycle_DEM_WARMUP)
#define Rte_Call_OpCycle_OperationCycle_DEM_WARMUP_SetCycleQualified()          Dem_SetCycleQualified(Dem_OpCycle_OperationCycle_DEM_WARMUP)
#define Rte_Call_OverflowIndPrimaryMemory_DemClient_0_GetEventMemoryOverflow(OverflowIndication)    Dem_GetEventMemoryOverflow(Dem_DemClient_0, DEM_DTC_ORIGIN_PRIMARY_MEMORY, OverflowIndication)
#define Rte_Call_OverflowIndPrimaryMemory_DemClient_0_GetNumberOfEventMemoryEntries(GetNumberOfEventMemoryEntries)      Dem_GetNumberOfEventMemoryEntries(Dem_DemClient_0, DEM_DTC_ORIGIN_PRIMARY_MEMORY, GetNumberOfEventMemoryEntries)

/*******************************************************************************
*   Extended
*******************************************************************************/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
#define Dem_Rte_Cfg_D_Event_0x9D0511_GetFaultDetectionCounter         Rte_Call_Dem_CBFaultDetectCtr_Cfg_D_Event_0x9D0511_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Cfg_D_Event_0x9D0511_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Cfg_D_Event_0x9D0615_GetFaultDetectionCounter         Rte_Call_Dem_CBFaultDetectCtr_Cfg_D_Event_0x9D0615_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Cfg_D_Event_0x9D0615_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Cfg_D_Event_0xF13C87_GetFaultDetectionCounter         Rte_Call_Dem_CBFaultDetectCtr_Cfg_D_Event_0xF13C87_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Cfg_D_Event_0xF13C87_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Cfg_D_Event_0xF1D187_GetFaultDetectionCounter         Rte_Call_Dem_CBFaultDetectCtr_Cfg_D_Event_0xF1D187_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Cfg_D_Event_0xF1D187_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Cfg_D_Event_0xF1D287_GetFaultDetectionCounter         Rte_Call_Dem_CBFaultDetectCtr_Cfg_D_Event_0xF1D287_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Cfg_D_Event_0xF1D287_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Cfg_D_Event_0xF3A987_GetFaultDetectionCounter         Rte_Call_Dem_CBFaultDetectCtr_Cfg_D_Event_0xF3A987_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Cfg_D_Event_0xF3A987_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Cfg_D_Event_0xF3B287_GetFaultDetectionCounter         Rte_Call_Dem_CBFaultDetectCtr_Cfg_D_Event_0xF3B287_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Cfg_D_Event_0xF3B287_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Cfg_P_Event_0x9D0511_GetFaultDetectionCounter         Rte_Call_Dem_CBFaultDetectCtr_Cfg_P_Event_0x9D0511_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Cfg_P_Event_0x9D0511_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Cfg_P_Event_0x9D0615_GetFaultDetectionCounter         Rte_Call_Dem_CBFaultDetectCtr_Cfg_P_Event_0x9D0615_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Cfg_P_Event_0x9D0615_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Cfg_P_Event_0xF13C87_GetFaultDetectionCounter         Rte_Call_Dem_CBFaultDetectCtr_Cfg_P_Event_0xF13C87_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Cfg_P_Event_0xF13C87_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Cfg_P_Event_0xF1D387_GetFaultDetectionCounter         Rte_Call_Dem_CBFaultDetectCtr_Cfg_P_Event_0xF1D387_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Cfg_P_Event_0xF1D387_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Cfg_P_Event_0xF1D487_GetFaultDetectionCounter         Rte_Call_Dem_CBFaultDetectCtr_Cfg_P_Event_0xF1D487_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Cfg_P_Event_0xF1D487_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Cfg_P_Event_0xF3A987_GetFaultDetectionCounter         Rte_Call_Dem_CBFaultDetectCtr_Cfg_P_Event_0xF3A987_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Cfg_P_Event_0xF3A987_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_Cfg_P_Event_0xF3B287_GetFaultDetectionCounter         Rte_Call_Dem_CBFaultDetectCtr_Cfg_P_Event_0xF3B287_GetFaultDetectionCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_CBFaultDetectCtr_Cfg_P_Event_0xF3B287_GetFaultDetectionCounter
(
    P2VAR(sint8, AUTOMATIC, RTE_APPL_DATA) FaultDetectionCounter
);
#define Dem_Rte_DataElement1_Year_ReadDataElement           Rte_Call_Dem_DataServices_DataElement1_Year_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DataServices_DataElement1_Year_ReadData
(
    P2VAR(Dem_DataType_DataElement1_Year, AUTOMATIC, RTE_APPL_DATA) Data
);
#define Dem_Rte_DataElement2_Month_ReadDataElement          Rte_Call_Dem_DataServices_DataElement2_Month_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DataServices_DataElement2_Month_ReadData
(
    P2VAR(Dem_DataType_DataElement2_Month, AUTOMATIC, RTE_APPL_DATA) Data
);
#define Dem_Rte_DataElement3_Day_ReadDataElement            Rte_Call_Dem_DataServices_DataElement3_Day_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DataServices_DataElement3_Day_ReadData
(
    P2VAR(Dem_DataType_DataElement3_Day, AUTOMATIC, RTE_APPL_DATA) Data
);
#define Dem_Rte_DataElement4_Hour_ReadDataElement           Rte_Call_Dem_DataServices_DataElement4_Hour_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DataServices_DataElement4_Hour_ReadData
(
    P2VAR(Dem_DataType_DataElement4_Hour, AUTOMATIC, RTE_APPL_DATA) Data
);
#define Dem_Rte_DataElement5_Minute_ReadDataElement         Rte_Call_Dem_DataServices_DataElement5_Minute_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DataServices_DataElement5_Minute_ReadData
(
    P2VAR(Dem_DataType_DataElement5_Minute, AUTOMATIC, RTE_APPL_DATA) Data
);
#define Dem_Rte_DataElement6_Second_ReadDataElement         Rte_Call_Dem_DataServices_DataElement6_Second_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DataServices_DataElement6_Second_ReadData
(
    P2VAR(Dem_DataType_DataElement6_Second, AUTOMATIC, RTE_APPL_DATA) Data
);
#define Dem_Rte_DataElement7_Odometer_ReadDataElement       Rte_Call_Dem_DataServices_DataElement7_Odometer_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DataServices_DataElement7_Odometer_ReadData
(
    VAR(Dem_DataType_DataElement7_Odometer,AUTOMATIC) Data
);
#define Dem_Rte_DataElement8_LV_Battery_Voltage_ReadDataElement       Rte_Call_Dem_DataServices_DataElement8_LV_Battery_Voltage_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DataServices_DataElement8_LV_Battery_Voltage_ReadData
(
    P2VAR(Dem_DataType_DataElement8_LV_Battery_Voltage, AUTOMATIC, RTE_APPL_DATA) Data
);
#define Dem_Rte_DataElement9_VehicleSpeed_ReadDataElement   Rte_Call_Dem_DataServices_DataElement9_VehicleSpeed_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dem_DataServices_DataElement9_VehicleSpeed_ReadData
(
    VAR(Dem_DataType_DataElement9_VehicleSpeed,AUTOMATIC) Data
);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif  /*RTE_DEM_H*/


