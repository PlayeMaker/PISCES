/*BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dem.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : Dem.h
*   Author          : Hirain
********************************************************************************
*   Description: AUTOSAR Diagnostic Event Manager (DEM) API header file.
*
********************************************************************************
*   Limitations:
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
*END_FILE_HDR*/

#ifndef DEM_H
#define DEM_H
/*SWS_Dem_00512*/
/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dem_Types.h"
#include "Dcm_Types.h"
#include "Dem_Version.h"
#include "Dem_Lcfg.h"
#include "Dem_Dcm.h"
#if(DEM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
#include "Dem_PBcfg.h"
#endif
#if(DEM_CORE_NUMBER > 1)
#include "Dem_Callout.h"
#endif
/*******************************************************************************
* Macros and Typedef
*******************************************************************************/
/* API Ids */
#define DEM_GETVERSIONINFO_APIID                          ((uint8)0x00)
/*Interface ECU State Manager <=> Dem*/
#define DEM_PREINIT_APIID                                 ((uint8)0x01)
#define DEM_INIT_APIID                                    ((uint8)0x02)
#define DEM_SHUTDOWN_APIID                                ((uint8)0x03)
/*Interface BSW modules / SW-Components <=> Dem*/
#define DEM_SETEVENTAVAILABLE_APIID                       ((uint8)0x37)
#define DEM_SETEVENTSTATUS_APIID                          ((uint8)0x04)
#define DEM_SETEVENTSTATUSWITHMONITORDATA_APIID           ((uint8)0xbd)
#define DEM_RESETEVENTDEBOUNCESTATUS_APIID                ((uint8)0x09)
#define DEM_RESETEVENTSTATUS_APIID                        ((uint8)0x05)
#define DEM_PRESTOREFREEZEFRAME_APIID                     ((uint8)0x06)
#define DEM_CLEARPRESTOREDFREEZEFRAME_APIID               ((uint8)0x07)
#define DEM_RESTARTOPERATIONCYCLE_APIID                   ((uint8)0x08)
#define DEM_GETOPERATIONCYCLESTATE_APIID                  ((uint8)0x9e)
#define DEM_SETWIRSTATUS_APIID                            ((uint8)0x7a)
#define DEM_GETCOMPONENTFAILED_APIID                      ((uint8)0x2a)
#define DEM_GETMONITORSTATUS_APIID                        ((uint8)0xb5)
#define DEM_GETEVENTUDSSTATUS_APIID                       ((uint8)0xb6)
#define DEM_GETEVENTAVAILABLE_APIID                       ((uint8)0xbe)
#define DEM_SETEVENTCONFIRMATIONTHRESHOLDCOUNTER_APIID    ((uint8)0x57)
#define DEM_GETDEBOUNCINGOFEVENT_APIID                    ((uint8)0x9f)
#define DEM_GETDTCOFEVENT_APIID                           ((uint8)0x0d)
#define DEM_SETENABLECONDITION_APIID                      ((uint8)0x39)
#define DEM_SETSTORAGECONDITION_APIID                     ((uint8)0x38)
#define DEM_GETFAULTDETECTIONCOUNTER_APIID                ((uint8)0x3e)
#define DEM_GETINDICATORSTATUS_APIID                      ((uint8)0x29)
#define DEM_GETEVENTFREEZEFRAMEDATAEX_APIID               ((uint8)0x6e)
#define DEM_GETEVENTEXTENDEDDATARECORDEX_APIID            ((uint8)0x6d)
#define DEM_GETEVENTMEMORYOVERFLOW_APIID                  ((uint8)0x32)
#define DEM_SETDTCSUPPRESSION_APIID                       ((uint8)0x33)
#define DEM_GETDTCSUPPRESSION_APIID                       ((uint8)0xbc)
#define DEM_GETNUMBEROFEVENTMEMORYENTRIES_APIID           ((uint8)0x35)
#define DEM_SETCYCLEQUALIFIED_APIID                       ((uint8)0x56)
#define DEM_SETCOMPONENTAVAILABLE_APIID                   ((uint8)0x2b)
#define DEM_CLEARDTC_APIID                                ((uint8)0x23)
#define DEM_GETCYCLEQUALIFIED_APIID                       ((uint8)0xab)
#define DEM_SELECTDTC_APIID                               ((uint8)0xb7)
#define DEM_GETDTCSELECTIONRESUIT_APIID                   ((uint8)0xb8)
#define DEM_SELECTFREEZEFRAMEDATA_APIID                   ((uint8)0xb9)
#define DEM_SELECTEXTENDEDDATARECORD_APIID                ((uint8)0xba)
#define DEM_GETDTCSELECTIONRESUITFORCLEARDTC_APIID        ((uint8)0xbb)
/*OBD-specific Interfaces*/
#define DEM_SETEVENTDISABLED_APIID                        ((uint8)0x51)
#define DEM_REPIUMPRFAULTDETECT_APIID                     ((uint8)0x73)
#define DEM_SETIUMPRDENCONDITION_APIID                    ((uint8)0xae)
#define DEM_GETIUMPRDENCONDITION_APIID                    ((uint8)0xaf)
#define DEM_REPIUMPRDENLOCK_APIID                         ((uint8)0x71)
#define DEM_REPIUMPRDENRELEASE_APIID                      ((uint8)0x72)
#define DEM_SETPTOSTATUS_APIID                            ((uint8)0x79)
#define DEM_READDATAOFPID01_APIID                         ((uint8)0xb3)
#define DEM_GETDATAOFPID21_APIID                          ((uint8)0xb1)
#define DEM_SETDATAOFPID21_APIID                          ((uint8)0xa6)
#define DEM_SETDATAOFPID31_APIID                          ((uint8)0xa7)
#define DEM_SETDATAOFPID4D_APIID                          ((uint8)0xa8)
#define DEM_SETDATAOFPID4E_APIID                          ((uint8)0xa9)
#define DEM_SETPFCCYCLEQUALIFIED_APIID                    ((uint8)0xaa)
#define DEM_GETPFCCYCLEQUALIFIED_APIID                    ((uint8)0xab)
#define DEM_GETB1COUNTER_APIID                            ((uint8)0xb4)
#define DEM_SETDTR_APIID                                  ((uint8)0xa2)

/*Dem_Dcm API ID*/
#define DEM_GETTRANSLATIONTYPE_APIID                      ((uint8)0x3c)
#define DEM_GETDTCSTATUSAVAILABILITYMASK_APIID            ((uint8)0x16)
#define DEM_GETSTATUSOFDTC_APIID                          ((uint8)0x15)
#define DEM_GETSEVERITYOFDTC_APIID                        ((uint8)0x0E)
#define DEM_GETFUNCTIONALUNITOFDTC_APIID                  ((uint8)0x34)
#define DEM_SETDTCFILTER_APIID                            ((uint8)0x13)
#define DEM_SETDTCFILTERBYEXTENDEDDATERECORD_APIID        ((uint8)0xC1) 
#define DEM_SETDTCFILTERBYREADINESSGROUP_APIID            ((uint8)0xC2)
#define DEM_GETNUMBEROFFILTEREDDTC_APIID                  ((uint8)0x17)
#define DEM_GETNEXTFILTEREDDTC_APIID                      ((uint8)0x18)
#define DEM_GETNEXTFILTEREDDTCANDFDC_APIID                ((uint8)0x3b)
#define DEM_GETNEXTFILTEREDDTCANDSEVERITY_APIID           ((uint8)0x3d)
#define DEM_SETFREEZEFRAMERECORDFILTER_APIID              ((uint8)0x3f)
#define DEM_GETNEXTFILTEREDRECORD_APIID                   ((uint8)0x3a)
#define DEM_GETDTCBYOCCURRENCETIME_APIID                  ((uint8)0x19)
#define DEM_DCMCONTROLDTCSTATUSCHANGEDNOTIFICATION_APIID  ((uint8)0xb0)
#define DEM_DISABLEDTCRECORDUPDATE_APIID                  ((uint8)0x1a)
#define DEM_ENABLEDTCRECORDUPDATE_APIID                   ((uint8)0x1b)
#define DEM_GETNEXTFREEZEFRAMEDATA_APIID                  ((uint8)0x1d)
#define DEM_GETSIZEOFFREEZEFRAMESELECTION_APIID           ((uint8)0x1f)
#define DEM_GETNEXTEXTENDEDDATARECORD_APIID               ((uint8)0x20)
#define DEM_GETSIZEOFEXTENDEDDATARECORDSELECTION_APIID    ((uint8)0x21)
#define DEM_DISABLEDTCSETTING_APIID                       ((uint8)0x24)
#define DEM_ENABLEDTCSETTING_APIID                        ((uint8)0x25)
#define DEM_GETNUMBEROFFREEZEFRAMERECORDS_APIID           ((uint8)0x5a)
#define DEM_DCMCHECKCLEARPARAMETER_APIID                  ((uint8)0x7b)
#define DEM_GETDTCSEVERITYAVAILABILITYMASK_APIID          ((uint8)0xb2)
/*Dem_Dcm OBD API ID*/
#define DEM_DCMGETINFOTYPEVALUE08_APIID                   ((uint8)0x6b)
#define DEM_DCMGETINFOTYPEVALUE0B_APIID                   ((uint8)0x6c)
#define DEM_DCMREADDATAOFPID01_APIID                      ((uint8)0x61)
#define DEM_DCMREADDATAOFPID1C_APIID                      ((uint8)0x63)
#define DEM_DCMREADDATAOFPID21_APIID                      ((uint8)0x64)
#define DEM_DCMREADDATAOFPID30_APIID                      ((uint8)0x65)
#define DEM_DCMREADDATAOFPID31_APIID                      ((uint8)0x66)
#define DEM_DCMREADDATAOFPID41_APIID                      ((uint8)0x67)
#define DEM_DCMREADDATAOFPID4D_APIID                      ((uint8)0x68)
#define DEM_DCMREADDATAOFPID4E_APIID                      ((uint8)0x69)
#define DEM_DCMREADDATAOFPID91_APIID                      ((uint8)0x6a)
#define DEM_DCMREADDATAOFOBDFREEZEFRAME_APIID             ((uint8)0x52)
#define DEM_DCMGETDTCOFOBDFREEZEFRAME_APIID               ((uint8)0x53)
#define DEM_DCMGETAVAILABLEOBDMIDS_APIID                  ((uint8)0xa3)
#define DEM_DCMGETNUMTIDSOFOBDMID_APIID                   ((uint8)0xa4)
#define DEM_DCMGETDTRDATA_APIID                           ((uint8)0xa5)

/*Dem_J1939Dcm API ID*/
#define DEM_J1939DCMSETDTCFILTER_APIID                    ((uint8)0x90)
#define DEM_J1939DCMGETNUMBEROFFILTEREDDTC_APIID          ((uint8)0x91)
#define DEM_J1939DCMGETNEXTFILTEREDDTC_APIID              ((uint8)0x92)
#define DEM_J1939DCMFIRSTDTCWITHLAMPSTATUS_APIID          ((uint8)0x93)
#define DEM_J1939DCMGETNEXTDTCWITHLAMPSTATUS_APIID        ((uint8)0x94)
#define DEM_J1939DCMCLEARDTC_APIID                        ((uint8)0x95)
#define DEM_J1939DCMSETFREEZEFRAMEFILTER_APIID            ((uint8)0x96)
#define DEM_J1939DCMGETNEXTFREEZEFRAME_APIID              ((uint8)0x97)
#define DEM_J1939DCMSETRATIOFILTER_APIID                  ((uint8)0x99)
#define DEM_J1939DCMGETNEXTFILTEREDRATIO_APIID            ((uint8)0x9a)
#define DEM_J1939DCMREADDIAGNOSTICREADINESS1_APIID        ((uint8)0x9b)
#define DEM_J1939DCMREADDIAGNOSTICREADINESS2_APIID        ((uint8)0x9c)
#define DEM_J1939DCMREADDIAGNOSTICREADINESS3_APIID        ((uint8)0x9d)
/*Dem_Dlt API ID*/
#define DEM_DLTGETMOSTRECENTFREEZEFRAMERECORDDATA_APIID   ((uint8)0x41)
#define DEM_DLTGETALLEXTENDEDDATARECORDS_APIID            ((uint8)0x40)
/*Scheduled functions API ID*/
#define DEM_MAINFUNCTION_APIID                            ((uint8)0x55)

/*SWS_Dem_00173*/
#define DEM_E_WRONG_CONFIGURATION                ((uint8)0x10)
#define DEM_E_PARAM_POINTER                      ((uint8)0x11)
#define DEM_E_PARAM_DATA                         ((uint8)0x12)
#define DEM_E_PARAM_LENGTH                       ((uint8)0x13)
#define DEM_E_INIT_FAILED                        ((uint8)0x14)
#define DEM_E_UNINIT                             ((uint8)0x20)
#define DEM_E_NODATAAVAILABLE                    ((uint8)0x30)
#define DEM_E_WRONG_RECORDNUMBER                 ((uint8)0x31)
#define DEM_E_WRONG_DIDNUMBER                    ((uint8)0x32)
#define DEM_E_WRONG_CONDITION                    ((uint8)0x40)


#define DEM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Dem_MemMap.h"

extern VAR(Dem_StorageMemType, DEM_VAR_NOINIT) Dem_StorageMem;

#define DEM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
* Global Function Prototype
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

#if(STD_ON == DEM_VERSION_INFO_API)
/*SWS_Dem_00177*/
extern FUNC(void, DEM_CODE) Dem_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DEM_APPL_DATA) versionInfo
);
#endif


/*SWS_Dem_00179*/
extern FUNC(void, DEM_CODE) Dem_PreInit
(
    void
);
/*SWS_Dem_00181*/
extern FUNC(void, DEM_CODE) Dem_Init
(
    P2CONST(Dem_ConfigType, AUTOMATIC, DEM_APPL_DATA) ConfigPtr
);
/*SWS_Dem_00182*/
extern FUNC(void, DEM_CODE) Dem_Shutdown
(
    void
);
/*SWS_Dem_91015*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SelectFreezeFrameData
(
    uint8 ClientId,
    uint8 RecordNumber
);
/*SWS_Dem_91017*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SelectExtendedDataRecord
(
    uint8 ClientId,
    uint8 ExtendedDataNumber
);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_RestartOperationCycle
(
    uint8 OperationCycleId
);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventStorageEntry
(
    Dem_EventIdType EventId,
    P2VAR(Dem_MemIdType, AUTOMATIC, DEM_APPL_DATA) DataEntryId
);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventStatus
(
    Dem_EventIdType EventId
);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetCycleQualified
(
    uint8 OperationCycleId
);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetCycleQualified
(
    uint8 OperationCycleId,
    boolean* isQualified
);

/*SWS_Dem_00183*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatusWithMonitorData
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus,
    Dem_MonitorDataType monitorData0,
    Dem_MonitorDataType monitorData1
);

/*SWS_Dem_01106*/
#if(DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
/*SWS_Dem_01080*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventAvailable
(
    Dem_EventIdType EventId,
    boolean AvailableStatus
);
#endif
#endif

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventAvailable
(
    Dem_EventIdType EventId,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) AvailableStatus
);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventConfirmationThresholdCounter
(
    Dem_EventIdType EventId,
    uint8 FailureCycleCounterThreshold
);
/*SWS_Dem_00683*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventDebounceStatus
(
    Dem_EventIdType EventId,
    Dem_DebounceResetStatusType DebounceResetStatus
);
#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
extern FUNC(Std_ReturnType, DEM_CODE) Dem_PrestoreFreezeFrame
(
    Dem_EventIdType EventId
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ClearPrestoredFreezeFrame
(
    Dem_EventIdType EventId
);
#endif
extern FUNC (Std_ReturnType, DEM_CODE) Dem_SelectDTC 
(
    uint8 ClientId,
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetNumberOfFreezeFrameRecords
(
    uint8 ClientId,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredRecords
);

/*SWS_Dem_00839*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetWIRStatus
(
    Dem_EventIdType EventId,
    boolean WIRStatus
);

/*SWS_Dem_00195*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventUdsStatus
(
    Dem_EventIdType EventId,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) UDSStatusByte
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetMonitorStatus
(
    Dem_EventIdType EventId,
    P2VAR(Dem_MonitorStatusType, AUTOMATIC, DEM_APPL_DATA) MonitorStatus
);
/*SWS_Dem_00730*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDebouncingOfEvent
(
    Dem_EventIdType EventId,
    P2VAR(Dem_DebouncingStateType, AUTOMATIC, DEM_APPL_DATA) DebouncingState
);
/*SWS_Dem_00198*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCOfEvent
(
    Dem_EventIdType EventId,
    Dem_DTCFormatType DTCFormat,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTCOfEvent
);
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
extern FUNC (Std_ReturnType, DEM_CODE) Dem_GetDTCSuppression
(
    uint8 ClientId,
    boolean* SuppressionStatus
);
#endif
/*SWS_Dem_00201*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEnableCondition
(
    uint8 EnableConditionID,
    boolean ConditionFulfilled
);

extern FUNC (Std_ReturnType, DEM_CODE) Dem_GetDTCSelectionResult 
(
    uint8 ClientId
);
extern FUNC (Std_ReturnType, DEM_CODE) Dem_GetDTCSelectionResultForClearDTC
(
    uint8 ClientId
);

/*SWS_Dem_00556*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetStorageCondition
(
    uint8 StorageConditionID,
    boolean ConditionFulfilled
);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetFaultDetectionCounter
(
    Dem_EventIdType EventId,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter
);
/*SWS_Dem_00205*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetIndicatorStatus
(
    uint8 IndicatorId,
    P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus
);

/*SWS_Dem_01191*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFreezeFrameDataEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    uint16 DataId,
    uint8 *DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);

/*SWS_Dem_01190*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventExtendedDataRecordEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
/*SWS_Dem_00559*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventMemoryOverflow
(
    uint8 ClientId,
    Dem_DTCOriginType DTCOrigin,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) OverflowIndication
);
/*SWS_Dem_00652*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetNumberOfEventMemoryEntries
(
    uint8 ClientId,
    Dem_DTCOriginType DTCOrigin,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfEventMemoryEntries
);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCSeverityAvailabilityMask
(
    uint8 ClientId,
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverityMask  
);
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
/*SWS_Dem_01047*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTCSuppression
(
    uint8 ClientId,
    boolean SuppressionStatus
);
#endif


/*SWS_Dem_00266*/
extern FUNC(void, DEM_CODE) Dem_MainFunction
(
    void
);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventInternalData
(
    Dem_EventIdType EventId,
    Dem_InternalDataElementType DataType,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataValue
);

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
/*SWS_Dem_00312*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventDisabled
(
    Dem_EventIdType EventId
);

/*SWS_Dem_00313*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRFaultDetect
(
    Dem_RatioIdType RatioID
);

/*SWS_Dem_00733*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetIUMPRDenCondition
(
    Dem_IumprDenomCondIdType ConditionId,
    Dem_IumprDenomCondStatusType ConditionStatus
);

/*SWS_Dem_00734*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetIUMPRDenCondition
(
    Dem_IumprDenomCondIdType ConditionId,
    P2VAR(Dem_IumprDenomCondStatusType, AUTOMATIC, DEM_APPL_DATA) ConditionStatus
);

/*SWS_Dem_00314*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenLock
(
    Dem_RatioIdType RatioID
);

/*SWS_Dem_00315*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenRelease
(
    Dem_RatioIdType RatioID
);

/*These two interface is provided to user to get the Numerator&Denominator
of one Ratio or Event.*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetGeneralNumeratorAndDenominator
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Numerator,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Denominator
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetNumeratorAndDenominator
(
    Dem_RatioIdType RatioID,
    P2VAR(Dem_EventIdType, AUTOMATIC, DEM_APPL_DATA) EventId,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Numerator,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Denominator
);

#if(DEM_CFG_PTO_SUPPORT == STD_ON)
/*SWS_Dem_00627*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetPtoStatus
(
    boolean PtoStatus
);
#endif

/*SWS_Dem_01167*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ReadDataOfPID01
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID01value
);

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU) \
    && (DEM_CFG_OBD_CENTRALIZED_PID21_HANDLING == STD_ON))
/*SWS_Dem_01093*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value
);
#endif

/*SWS_Dem_00735*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value
);

/*SWS_Dem_00736*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID31
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID31value
);

/*SWS_Dem_00737*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4D
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Dvalue
);

/*SWS_Dem_00738*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4E
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Evalue
);

/*SWS_Dem_00739*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetPfcCycleQualified
(
    void
);

/*SWS_Dem_00740*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetPfcCycleQualified
(
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) isqualified
);

/*SWS_Dem_01169*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetB1Counter
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) B1Counter
);

/*SWS_Dem_00765*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTR
(
    uint16 DTRId,
    sint32 TestResult,
    sint32 LowerLimit,
    sint32 UpperLimit,
    Dem_DTRControlType Ctrlval
);
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif /* DEM_H */

