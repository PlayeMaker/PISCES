/* BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dem_Types.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : Dem module head File
*   Author          : Hirain
********************************************************************************
*   Description: Type header file of the AUTOSAR Diagnositc Event Manager,
*              according to AUTOSAR_SWS_DiagnosticEventManager.pdf (Release 4.2)
********************************************************************************
*   Limitations: None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/

#ifndef DEM_TYPES_H
#define DEM_TYPES_H

/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dem_Cfg.h"
#include "Std_Types.h"
#include "Rte_Dem_Type.h"
#if(DEM_NVM_SUPPORT == STD_ON)
#include "NvM_Types.h"
#endif
#if(DEM_CORE_NUMBER > 1)
#include "Os_Types.h"
#endif

/*******************************************************************************
* Macros and Typedef
*******************************************************************************/
/*SWS_Dem_01114*/
typedef uint16 Dem_ComponentIdType;/*1..65535, 0 is not a valid value*/
typedef uint8 Dem_MemIdType;


#define DEM_EVENT_ID_INVALID                        ((uint16)0xFFFF)
#define DEM_INDICATOR_ID_INVALID                    ((uint8)0xFF)
#define DEM_ENTRY_ID_INVALID                        ((uint8)0xFF)


/*SWS_Dem_00935*/
typedef uint8 Dem_DTCRequestType;
/*first failed DTC requested*/
#define DEM_FIRST_FAILED_DTC                        ((uint8)0x01)
/*most recent failed DTC requested*/
#define DEM_MOST_RECENT_FAILED_DTC                  ((uint8)0x02)
/*first detected confirmed DTC requested*/
#define DEM_FIRST_DET_CONFIRMED_DTC                 ((uint8)0x03)
/*most recently detected confirmed DTC requeste*/
#define DEM_MOST_REC_DET_CONFIRMED_DTC              ((uint8)0x04)

/*SWS_Dem_00936*/
typedef uint8 Dem_DTCTranslationFormatType;
/*ISO15031-6 DTC format/SAE J2012-DA_DTCFormat_00 DTC format*/
#define DEM_DTC_TRANSLATION_ISO15031_6              ((uint8)0x00)
/*ISO14229-1 DTC format*/
#define DEM_DTC_TRANSLATION_ISO14229_1              ((uint8)0x01)
/*SAEJ1939-73 DTC format*/
#define DEM_DTC_TRANSLATION_SAEJ1939_73             ((uint8)0x02)
/*ISO11992-4 DTC format*/
#define DEM_DTC_TRANSLATION_ISO11992_4              ((uint8)0x03)
/*SAE_J2012-DA_DTCFormat_04 DTC format*/
#define DEM_DTC_TRANSLATION_J2012DA_FORMAT_04       ((uint8)0x04)

/*SWS_Dem_00937*/
typedef uint8 Dem_DTCSeverityType;
#define DEM_SEVERITY_NO_SEVERITY                    ((uint8)0x00)/*No severity information available*/
#define DEM_SEVERITY_MAINTENANCE_ONLY               ((uint8)0x20)/*maintenance required*/
#define DEM_SEVERITY_CHECK_AT_NEXT_HALT             ((uint8)0x40)/*check at next halt*/
#define DEM_SEVERITY_CHECK_IMMEDIATELY              ((uint8)0x80)/*Check immediately*/

#define DEM_SEVERITY_WWHOBD_CLASS_NO_CLASS          ((uint8)0x01)/*No class information*/
#define DEM_SEVERITY_WWHOBD_CLASS_A                 ((uint8)0x02)/*WWH-OBD Class A*/
#define DEM_SEVERITY_WWHOBD_CLASS_B1                ((uint8)0x04)/*WWH-OBD Class B1*/
#define DEM_SEVERITY_WWHOBD_CLASS_B2                ((uint8)0x08)/*WWH-OBD Class B2*/
#define DEM_SEVERITY_WWHOBD_CLASS_C                 ((uint8)0x10)/*WWH-OBD Class C*/


#define DEM_PRIMARY_MEMORY                          ((uint8)0x1F)

typedef enum
{
    DEM_NO_CLIENT_REQUEST,
    DEM_FILTER_PROCESSING,
    DEM_FILTER_PROCESS_END
} Dem_FilterProcessType;


/*SWS_Dem_01317*/
typedef enum
{
    DEM_OP_QUALIFIED,
    DEM_OP_NOT_QUALIFIED
} Dem_DependentOpCycStatuType;


/*ECUC_Dem_00943*/
typedef enum
{
    DEM_CLIENT_ONLY_USES_EVENTOVERFLOW_INTERFACE,
    DEM_CLIENT_USES_FULL_FUNCTIONALITY
} Dem_ClientFunctionalityType;

/*SWS_Dem_00944*/
/*This type contains all possible states of an additional IUMPR denominator
condition to be broadcasted among OBD-relevant ECUs.*/
typedef enum
{
    /*Condition of IUMPRDenominator given by IUMPRDenCondId is not met (yet).*/
    DEM_IUMPR_DEN_STATUS_NOT_REACHED = 0x00,
    /*Condition of IUMPRDenominator given by IUMPRDenCondId is met*/
    DEM_IUMPR_DEN_STATUS_REACHED     = 0x01,
    /*Condition of IUMPRDenominator given by IUMPRDenCondId is inhibited and cannot be reached.*/
    DEM_IUMPR_DEN_STATUS_INHIBITED   = 0x02
} Dem_IumprDenomCondStatusType;

/*SWS_Dem_00945*/
typedef uint8 Dem_J1939DcmDTCStatusFilterType;
#define DEM_J1939DTC_ACTIVE                         ((uint8)0x00)/*active DTCs*/
#define DEM_J1939DTC_PREVIOUSLY_ACTIVE              ((uint8)0x01)/*previously active DTCs*/
#define DEM_J1939DTC_PENDING                        ((uint8)0x02)/*pending DTCs*/
#define DEM_J1939DTC_PERMANENT                      ((uint8)0x03)/*permanent DTCs*/
#define DEM_J1939DTC_CURRENTLY_ACTIVE               ((uint8)0x04)/*currently active DTC*/

/*SWS_Dem_00946*/
typedef uint8 Dem_J1939DcmSetClearFilterType;
#define DEM_J1939DTC_CLEAR_ACTIVE                   ((uint8)0x00)/*active DTCs*/
#define DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE        ((uint8)0x01)/*previously active DTCs*/
#define DEM_J1939DTC_CLEAR_ACTIVE_AND_PREVIOUSLY_ACTIVE  ((uint8)0x02) /*active and previously active DTCs*/

/*SWS_Dem_00947*/
typedef uint8 Dem_J1939DcmSetFreezeFrameFilterType;
#define DEM_J1939DCM_FREEZEFRAME                    ((uint8)0x00)/*FreezeFrame (DM04)*/
#define DEM_J1939DCM_EXPANDED_FREEZEFRAME           ((uint8)0x01)/*ExpandedFreezeFrame(DM25)*/
#define DEM_J1939DCM_SPNS_IN_EXPANDED_FREEZEFRAME   ((uint8)0x02)/*SPNs in ExpandedFreezeFrame (DM24)*/


/*SWS_Dem_00948*/
typedef struct
{
    uint8 LampStatus;
    uint8 FlashLampStatus;
} Dem_J1939DcmLampStatusType;

#define DEM_J1939_LAMP_UNAVAILABLE                  ((uint16)0xFFFF)
/*Malfunction Indicator Lamp Status:Off*/
#define DEM_J1939_MIL_OFF                           ((uint16)0x0000)
/*Malfunction Indicator Lamp Status:On*/
#define DEM_J1939_MIL_ON                            ((uint16)0x4000)
/*Malfunction Indicator Lamp Status:Short MI*/
#define DEM_J1939_MIL_SHORT                         ((uint16)0x8000)
/*Malfunction Indicator Lamp Status:Unavailable*/
#define DEM_J1939_MIL_UNAVAILABLE                   ((uint16)0xC000)

/*Red Stop Lamp Status:Off*/
#define DEM_J1939_RSL_OFF                           ((uint16)0x0000)
/*Red Stop Lamp Status:On*/
#define DEM_J1939_RSL_ON                            ((uint16)0x1000)
/*Reserved for SAE Assignment*/
#define DEM_J1939_RSL_RESERVED                      ((uint16)0x2000)
/*Red Stop Lamp Status:Unavailable*/
#define DEM_J1939_RSL_UNAVAILABLE                   ((uint16)0x3000)

/*Amber Warning Lamp Status:Off*/
#define DEM_J1939_AWL_OFF                           ((uint16)0x0000)
/*Amber Warning Lamp Status:On*/
#define DEM_J1939_AWL_ON                            ((uint16)0x0400)
/*Reserved for SAE Assignment*/
#define DEM_J1939_AWL_RESERVED                      ((uint16)0x0800)
/*Amber Warning Lamp Status:Unavailable*/
#define DEM_J1939_AWL_UNAVAILABLE                   ((uint16)0x0C00)

/*Protect Lamp Status:Off*/
#define DEM_J1939_PL_OFF                            ((uint16)0x0000)
/*Protect Lamp Status:On*/
#define DEM_J1939_PL_ON                             ((uint16)0x0100)
/*Reserved for SAE Assignment*/
#define DEM_J1939_PL_RESERVED                       ((uint16)0x0200)
/*Protect Lamp Status:Unavailable*/
#define DEM_J1939_PL_UNAVAILABLE                    ((uint16)0x0300)

/*Flash Malfunction Indicator Lamp Status:Slow Flash*/
#define DEM_J1939_FMIL_SF                           ((uint16)0x0000)
/*Flash Malfunction Indicator Lamp Status:Fast Flash*/
#define DEM_J1939_FMIL_FF                           ((uint16)0x0040)
/*Flash Malfunction Indicator Lamp Status:Class C DTC*/
#define DEM_J1939_FMIL_CCDTC                        ((uint16)0x0080)
/*Flash Malfunction Indicator Lamp Status:Unavailable/Do Not Flash*/
#define DEM_J1939_FMIL_UNAVAILABLE                  ((uint16)0x00C0)

/*Flash Red Stop Lamp Status:Slow Flash*/
#define DEM_J1939_FRSL_SF                           ((uint16)0x0000)
/*Flash Red Stop Lamp Status:Fast Flash*/
#define DEM_J1939_FRSL_FF                           ((uint16)0x0010)
/*Reserved for SAE Assignment*/
#define DEM_J1939_FRSL_RESERVED                     ((uint16)0x0020)
/*Flash Red Stop Lamp Status:Unavailable/Do Not Flash*/
#define DEM_J1939_FRSL_UNAVAILABLE                  ((uint16)0x0030)

/*Flash Amber Warning Lamp Status:Slow Flash*/
#define DEM_J1939_FAWL_SF                           ((uint16)0x0000)
/*Flash Amber Warning Lamp Status:Fast Flash*/
#define DEM_J1939_FAWL_FF                           ((uint16)0x0004)
/*Reserved for SAE Assignment*/
#define DEM_J1939_FAWL_RESERVED                     ((uint16)0x0008)
/*Flash Amber Warning Lamp Status:Unavailable/Do Not Flash*/
#define DEM_J1939_FAWL_UNAVAILABLE                  ((uint16)0x000C)

/*Flash Protect Lamp Status:Slow Flash*/
#define DEM_J1939_FPL_SF                            ((uint16)0x0000)
/*Flash Protect Lamp Status:Fast Flash*/
#define DEM_J1939_FPL_FF                            ((uint16)0x0001)
/*Reserved for SAE Assignment*/
#define DEM_J1939_FPL_RESERVED                      ((uint16)0x0002)
/*Flash Protect Lamp Status:Unavailable/Do Not Flash*/
#define DEM_J1939_FPL_UNAVAILABLE                   ((uint16)0x0003)



/*SWS_Dem_00949*/
typedef struct
{
    /*Number of active DTCs*/
    uint8  ActiveTroubleCodes;
    /*Number of previously active DTCs*/
    uint8  PreviouslyActiveDiagnosticTroubleCodes;
    /*OBD Compliance*/
    uint8  OBDCompliance;
    /*Identifies the continuously monitored system support and status*/
    uint8  ContinuouslyMonitoredSystemsSupport_Status;
    /*Identifies the noncontinuously monitored systems support(byte5)*/
    uint8  NonContinuouslyMonitoredSystemsSupport5;
    /*Identifies the noncontinuously monitored systems support(byte6)*/
    uint8  NonContinuouslyMonitoredSystemsSupport6;
    /*Identifies the noncontinuously monitored systems status(byte7)*/
    uint8  NonContinuouslyMonitoredSystemsStatus7;
    /*Identifies the noncontinuously monitored systems status(byte8)*/
    uint8  NonContinuouslyMonitoredSystemsStatus8;

} Dem_J1939DcmDiagnosticReadiness1Type;

/*SWS_Dem_00950*/
typedef struct
{
    /*The kilometers accumulated while the MIL is activated*/
    uint16 DistanceTraveledWhileMILisActivated;
    /*Distance accumulated since emission related DTCs were cleared*/
    uint16 DistanceSinceDTCsCleared;
    /*Accumulated count (in minutes) while the MIL is activated (on)*/
    uint16 MinutesRunbyEngineWhileMILisActivated;
    /*Engine running time accumulated since emission related DTCs were cleared*/
    uint16 TimeSinceDiagnosticTroubleCodesCleared;
} Dem_J1939DcmDiagnosticReadiness2Type;

/*SWS_Dem_00951*/
typedef struct
{
    /*Time since key-on that the engine has been running.*/
    uint16 TimeSinceEngineStart;
    /*Number of OBD warmup cycles since all DTCs were cleared*/
    uint8  NumberofWarmupsSinceDTCsCleared;
    /*Identifies the continuously monitored system enable/completed support and status.*/
    uint8  ContinuouslyMonitoredSystemsEnableCompletedStatus;
    /*Enable status of noncontinuous monitors this monitoring cycle(byte5)*/
    uint8 NonContinuouslyMonitoredSystemsEnableStatus5;
    /*Enable status of noncontinuous monitors this monitoring cycle(byte6)*/
    uint8 NonContinuouslyMonitoredSystemsEnableStatus6;
    /*Completion status of noncontinuous monitors this monitoring cycle(byte7)*/
    uint8 NonContinuouslyMonitoredSystems7;
    /*Completion status of noncontinuous monitors this monitoring cycle(byte8)*/
    uint8 NonContinuouslyMonitoredSystems8;

} Dem_J1939DcmDiagnosticReadiness3Type;

#define DEM_CLEAR_FAILED                            ((uint8)0x07)
#define DEM_CLEAR_BUSY                              ((uint8)0x05)
#define DEM_CLEAR_MEMORY_ERROR                      ((uint8)0x06)
#define DEM_WRONG_DTC                               ((uint8)0x08)
#define DEM_WRONG_DTCORIGIN                         ((uint8)0x09)
#define DEM_PENDING                                 ((uint8)0x04)
#define DEM_BUSY                                    ((uint8)0x16)
#define DEM_NO_SUCH_ELEMENT                         ((uint8)0x30)
#define DEM_BUFFER_TOO_SMALL                        ((uint8)0x15)
/*******************************************************************************
*   DemGeneral Types ECUC_Dem_00677
*******************************************************************************/
/*ECUC_Dem_00603*/
/*DemAgingCycleCounterProcessing*/
#define DEM_PROCESS_AGINGCTR_EXTERN                 (0)
#define DEM_PROCESS_AGINGCTR_INTERN                 (1)

/*ECUC_Dem_00878*/
/*DemAvailabilitySupport*/
#define DEM_EVENT_AVAILABILITY                      (0)
#define DEM_NO_AVAILABILITY                         (1)

/*ECUC_Dem_00766*/
/*DemClearDTCBehavior*/
#define DEM_CLRRESP_NONVOLATILE_FINISH              (0)
#define DEM_CLRRESP_NONVOLATILE_TRIGGER             (1)
#define DEM_CLRRESP_VOLATILE                        (2)

/*ECUC_Dem_00790*/
/*DemClearDTCLimitation*/
#define DEM_ALL_SUPPORTED_DTCS                      (0)
#define DEM_ONLY_CLEAR_ALL_DTCS                     (1)

/*ECUC_Dem_00858*/
/*DemDataElementDefaultEndianness*/
#define DEM_BIG_ENDIAN                              (0)
#define DEM_LITTLE_ENDIAN                           (1)
#define DEM_OPAQUE                                  (2)

/*ECUC_Dem_00895*/
/*DemEnvironmentDataCapture*/
#define DEM_CAPTURE_ASYNCHRONOUS_TO_REPORTING       (0)
#define DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING        (1)

/*ECUC_Dem_00740*/
/*DemEventCombinationSupport*/
#define DEM_EVCOMB_DISABLED                         (0)
#define DEM_EVCOMB_ONRETRIEVAL                      (1)
#define DEM_EVCOMB_ONSTORAGE                        (2)

/*ECUC_Dem_00742*/
/*DemEventDisplacementStrategy*/
typedef enum
{
    DEM_DISPLACEMENT_FULL,
    DEM_DISPLACEMENT_NONE,
    DEM_DISPLACEMENT_PRIO_OCC
} Dem_EventDisplacementStrategyType;

typedef enum
{
    DURING_SHUTDOWN,
    IMMEDIATE_AT_FIRST_OCCURRENCE
} Dem_NvStorageStrategyType;

/*ECUC_Dem_00927*/
typedef enum
{
    START,
    FINISH
} Dem_ClearDtcNotificationTimeType;

/*DemEventMemoryEntryStorageTrigger*/
typedef uint8 Dem_EventMemoryEntryStorageTriggerType;
/*ECUC_Dem_00804*/
#define DEM_TRIGGER_ON_PASSED                            ((uint8)0x01)
/*ECUC_Dem_00797*/
#define DEM_TRIGGER_ON_FDC_THRESHOLD                     ((uint8)0x02)
#define DEM_TRIGGER_ON_TEST_FAILED                       ((uint8)0x04)
#define DEM_TRIGGER_ON_EVERY_TEST_FAILED                 ((uint8)0x08)
#define DEM_TRIGGER_ON_TEST_FAILED_THIS_OPERATION_CYCLE  ((uint8)0x10)
#define DEM_TRIGGER_ON_PENDING                           ((uint8)0x20)
#define DEM_TRIGGER_ON_CONFIRMED                         ((uint8)0x40)



/*ECUC_Dem_00698*/
/*DemOBDSupport*/
#define DEM_OBD_DEP_SEC_ECU                         (0)
#define DEM_OBD_MASTER_ECU                          (1)
#define DEM_OBD_NO_OBD_SUPPORT                      (2)
#define DEM_OBD_PRIMARY_ECU                         (4)

/*ECUC_Dem_00900*/
/*DemOBDEngineType*/
#define DEM_IGNITION_SPARK                          (0)
#define DEM_IGNITION_COMPRESSION                    (1)

/*ECUC_Dem_00767*/
/*DemOccurrenceCounterProcessing*/
typedef enum
{
    DEM_PROCESS_OCCCTR_CDTC,
    DEM_PROCESS_OCCCTR_TF
} Dem_OccurrenceCounterProcessingType;


/*ECUC_Dem_00784*/
/*DemStatusBitHandlingTestFailedSinceLastClear*/
#define DEM_STATUS_BIT_AGING_AND_DISPLACEMENT       (0)
#define DEM_STATUS_BIT_NORMAL                       (1)

/*ECUC_Dem_00793*/
/*DemSuppressionSupport*/
#define DEM_DTC_SUPPRESSION                         (0)
#define DEM_NO_SUPPRESSION                          (1)

/*ECUC_Dem_00778*/
/*DemTypeOfFreezeFrameRecordNumeration*/
typedef enum
{
    /*freeze frame records will be numbered consecutive starting by 1 in their chronological order*/
    DEM_FF_RECNUM_CALCULATED,
    /*freeze frame records will be numbered based on the given configuration in their chronological order*/
    DEM_FF_RECNUM_CONFIGURED
}Dem_TypeOfFreezeFrameRecordNumerationType;



/*ECUC_Dem_00701*/
/*DemOperationCycle:1...256*/
typedef struct
{
    /*ECUC_Dem_00898*/
    uint8 DemOperationCycleId;
    /*ECUC_Dem_00703*/
    uint8 DemLeadingRef;
} Dem_OperationCycleInfoType;


/*ECUC_Dem_00653*/
/*DemEnableCondition 0..255*/
typedef struct
{
    /*ECUC_Dem_00654*/
    uint8 DemEnableConditionId;/*0..255*/
    /*ECUC_Dem_00656*/
    boolean DemEnableConditionStatus;
} Dem_EnableConditionType;

/*ECUC_Dem_00745*/
/*DemEnableConditionGroup 0..255*/
typedef struct
{
    uint8 Number;/*1..255*/
    /*ECUC_Dem_00655*/
    const uint8 *DemEnableConditionRef;
} Dem_EnableConditionGroupType;

/*ECUC_Dem_00728*/
/*DemStorageCondition 0..255*/
typedef struct
{
    /*ECUC_Dem_00730*/
    uint8 DemStorageConditionId;/*0..255*/
    /*ECUC_Dem_00893*//*SWS_Dem_01085*/
    uint16 DemStorageConditionReplacementEventRef;
    /*ECUC_Dem_00731*/
    boolean DemStorageConditionStatus;
} Dem_StorageConditionType;

/*ECUC_Dem_00773*/
/*DemStorageConditionGroup 0..255*/
typedef struct
{
    uint8 Number;/*1..255*/
    /*ECUC_Dem_00768*/
    const uint8 *DemStorageConditionRef;
} Dem_StorageConditionGroupType;


/*ECUC_Dem_00696*/
/*DemNvRamBlockId:0..n*/
typedef struct
{
    /*ECUC_Dem_00697*/
    /*This reference contains the link to a non-volatile memory block. For
          post build time configurations worst case scenario shall be used.*/
    uint16 DemNvRamBlockIdRef;
} Dem_NvRamBlockIdType;

/*ECUC_Dem_00679*//*ECUC_Dem_00678*//*SWS_Dem_01338*/
typedef uint32  Dem_DTCGroupType;
#define DEM_DTC_GROUP_EMISSION              ((uint32)0xFFFF33)/*Emissions-system group*/
#define DEM_DTC_GROUP_SAFETY                ((uint32)0xFFFFD0)/*Safety-system group*/
#define DEM_DTC_GROUP_VOBD                  ((uint32)0xFFFFFE)/*VOBD system*/

#define DEM_DTC_GROUP_CHASSIS               ((uint32)0x400000)/*Chassis Group*/
#define DEM_DTC_CHASSIS_RANGE_LOW           ((uint32)0x400000)
#define DEM_DTC_CHASSIS_RANGE_HIGH          ((uint32)0x7FFFFF)


#define DEM_DTC_GROUP_BODY                  ((uint32)0x800000)/*Body Group*/
#define DEM_DTC_BODY_RANGE_LOW              ((uint32)0x800000)
#define DEM_DTC_BODY_RANGE_HIGH             ((uint32)0xBFFFFF)

/*Powertrain Group: engine and transmission*/
#define DEM_DTC_GROUP_POWERTRAIN            ((uint32)0x100000)
#define DEM_DTC_POWER_RANGE_LOW             ((uint32)0x000100)
#define DEM_DTC_POWER_RANGE_HIGH            ((uint32)0x3FFFFF)

/*Network Communication Group*/
#define DEM_DTC_GROUP_NETWORK_COM           ((uint32)0xC00000)
#define DEM_DTC_COM_RANGE_LOW               ((uint32)0xC00000)
#define DEM_DTC_COM_RANGE_HIGH              ((uint32)0xFFFF00)

/*All functional system groups*/
#define DEM_DTC_GROUP_ALL                   ((uint32)0xFFFFFF)


typedef struct
{
    Dem_DTCGroupType DTCGroupValue;
    uint16 DTCGroupMemory;
} Dem_DTCGroupInfoType;


typedef uint32 Dem_UdsDTCType;

/*ECUC_Dem_00626*//*DemCallbackDTCStatusChanged*/
/*ECUC_Dem_00627*//*DemCallbackDTCStatusChangedFnc*/
/*SWS_Dem_00617*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_DTCStatusChangedNotificationType)
(
    Dem_UdsDTCType DTC,
    Dem_UdsStatusByteType DTCStatusOld,
    Dem_UdsStatusByteType DTCStatusNew
);



#ifndef DEM_E_NO_FDC_AVAILABLE
#define DEM_E_NO_FDC_AVAILABLE   ((uint8)2)
#endif



#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
/*ECUC_Dem_00838*/
#define DEM_IUMPR_DEN_GENERAL  ((uint8)0)
typedef enum
{
    DEM_IUMPR_DEN_NONE       = 0,
    DEM_IUMPR_DEN_COLDSTART  = 1,
    DEM_IUMPR_DEN_EVAP       = 2,
    DEM_IUMPR_DEN_500MILL    = 3,
    DEM_IUMPR_DEN_PHYS_API   = 4
} Dem_IUMPRDenGroupType;

/*ECUC_Dem_00737*/
typedef enum
{
#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_SPARK)
    DEM_IUMPR_CAT1        = 1,/*Sequence reference SAE J1979-DA*/
    DEM_IUMPR_CAT2        = 2,
    DEM_IUMPR_OXS1        = 3,
    DEM_IUMPR_OXS2        = 4,
    DEM_IUMPR_EGR         = 5,
    DEM_IUMPR_SAIR        = 6,
    DEM_IUMPR_EVAP        = 7,
    DEM_IUMPR_SECOXS1     = 8,
    DEM_IUMPR_SECOXS2     = 9,
#else
    DEM_IUMPR_NMHCCAT     = 1,
    DEM_IUMPR_NOXCAT      = 2,
    DEM_IUMPR_NOXADSORB   = 3,
    DEM_IUMPR_PMFILTER    = 4,
    DEM_IUMPR_EGSENSOR    = 5,
    DEM_IUMPR_EGR         = 6,
    DEM_IUMPR_BOOSTPRS    = 7,
    DEM_IUMPR_FLSYS       = 8,
#endif
    /*DEM_IUMPR_PRIVATE     = 10*//*Not used*/
} Dem_IUMPRGroupType;

/*ECUC_Dem_00741*/
typedef enum
{
    DEM_RATIO_API       = 0,
    DEM_RATIO_OBSERVER  = 1
} Dem_RatioKindType;

/*ECUC_Dem_00734*/
typedef struct
{

    /*ECUC_Dem_00735*/
    Dem_EventIdType DemDiagnosticEventRef;
    /*ECUC_Dem_00736*/
    Dem_IUMPRGroupType DemIUMPRGroup;
    /*ECUC_Dem_00838*//*SWS_Dem_00715*/
    Dem_IUMPRDenGroupType DemIUMPRDenGroup;
    /*ECUC_Dem_00741*//*SWS_Dem_00361*/
    Dem_RatioKindType DemRatioKind;
} Dem_RatioType;

#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/




/*******************************************************************************
*   DemConfigSet Types ECUC_Dem_00634
*******************************************************************************/
typedef uint8 Dem_EventOBDReadinessGroupType;
#define DEM_OBD_RDY_MISF                 ((Dem_EventOBDReadinessGroupType)0x00)
#define DEM_OBD_RDY_FLSYS                ((Dem_EventOBDReadinessGroupType)0x01)
#define DEM_OBD_RDY_CMPRCMPT             ((Dem_EventOBDReadinessGroupType)0x02)
#define DEM_OBD_RDY_FLSYS_NONCONT        ((Dem_EventOBDReadinessGroupType)0x03)
#define DEM_OBD_RDY_DOR                  ((Dem_EventOBDReadinessGroupType)0x04)
#define DEM_OBD_RDY_ECS                  ((Dem_EventOBDReadinessGroupType)0x05)

#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_SPARK)
#define DEM_OBD_RDY_CAT                  ((Dem_EventOBDReadinessGroupType)0x08)
#define DEM_OBD_RDY_HTCAT                ((Dem_EventOBDReadinessGroupType)0x09)
#define DEM_OBD_RDY_EVAP                 ((Dem_EventOBDReadinessGroupType)0x0A)
#define DEM_OBD_RDY_SECAIR               ((Dem_EventOBDReadinessGroupType)0x0B)
#define DEM_OBD_RDY_AC                   ((Dem_EventOBDReadinessGroupType)0x0C)
#define DEM_OBD_RDY_O2SENS               ((Dem_EventOBDReadinessGroupType)0x0D)
#define DEM_OBD_RDY_O2SENSHT             ((Dem_EventOBDReadinessGroupType)0x0E)
#else
#define DEM_OBD_RDY_HCCAT                ((Dem_EventOBDReadinessGroupType)0x08)
#define DEM_OBD_RDY_NOXCAT               ((Dem_EventOBDReadinessGroupType)0x09)
#define DEM_OBD_RDY_NOXADSORB            ((Dem_EventOBDReadinessGroupType)0x0A)
#define DEM_OBD_RDY_BOOSTPR              ((Dem_EventOBDReadinessGroupType)0x0C)
#define DEM_OBD_RDY_EGSENS               ((Dem_EventOBDReadinessGroupType)0x0D)
#define DEM_OBD_RDY_PMFLT                ((Dem_EventOBDReadinessGroupType)0x0E)
#endif
#define DEM_OBD_RDY_EGR                  ((Dem_EventOBDReadinessGroupType)0x0F)
#define DEM_OBD_RDY_VVT                  ((Dem_EventOBDReadinessGroupType)0x0F)
#define DEM_OBD_RDY_CSER                 ((Dem_EventOBDReadinessGroupType)0x10)
#define DEM_OBD_RDY_GPF                  ((Dem_EventOBDReadinessGroupType)0x11)
#define DEM_OBD_RDY_NONE                 ((Dem_EventOBDReadinessGroupType)0x12)
#define DEM_OBD_RDY_OTHER                ((Dem_EventOBDReadinessGroupType)0x13)
#define DEM_OBD_RDY_PCV                  ((Dem_EventOBDReadinessGroupType)0x14)


#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)||(DEM_J1939_SUPPORT == STD_ON))
/*ECUC_Dem_00884*/
typedef struct
{
#if(DEM_CFG_PTO_SUPPORT == STD_ON)
    /*ECUC_Dem_00602*/
    boolean DemConsiderPtoStatus;
#endif
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    /*ECUC_Dem_00885*/
    uint16 DemDtcValue;/*Range:1 .. 65535*/
#endif
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
    /*ECUC_Dem_00755*/
    Dem_EventOBDReadinessGroupType DemEventOBDReadinessGroup;
#endif
#if(DEM_J1939_SUPPORT == STD_ON)
    /*ECUC_Dem_00892*/
    uint32 DemJ1939DTCValue;
#endif
} Dem_ObdDTCInfoType;
#endif

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
typedef uint16 Dem_DtrIdType;
typedef uint8 Dem_DtrMidType;
typedef uint8 Dem_DtrTidType;
typedef uint8 Dem_DtrUasidType;
/*ECUC_Dem_00812*/
typedef enum
{
    DEM_DTR_UPDATE_ALWAYS  = 0,
    DEM_DTR_UPDATE_STEADY  = 1
} Dem_DtrUpdateKindType;

/*ECUC_Dem_00806*/
typedef struct
{
    /*ECUC_Dem_00815*/
    sint32 DemDtrCompuDenominator0;
    /*ECUC_Dem_00813*/
    sint32 DemDtrCompuNumerator0;
    /*ECUC_Dem_00814*/
    sint32 DemDtrCompuNumerator1;
    /*ECUC_Dem_00808*/
    Dem_EventIdType DemDtrEventRef;
    /*ECUC_Dem_00807*/
    Dem_DtrIdType DemDtrId;
    /*ECUC_Dem_00809*/
    Dem_DtrMidType DemDtrMid;
    /*ECUC_Dem_00810*/
    Dem_DtrTidType DemDtrTid;
    /*ECUC_Dem_00811*/
    Dem_DtrUasidType DemDtrUasid;
    /*ECUC_Dem_00812*/
    Dem_DtrUpdateKindType DemDtrUpdateKind;
} Dem_DtrType;

/*ECUC_Dem_00729*/
typedef struct
{
    /*ECUC_Dem_00705*/
    uint8 DemPidIdentifier;
    /*ECUC_Dem_00896*//*ECUC_Dem_00733*/
    uint8 NumOfData;
    const uint8 *DemPidDataElementClassRef;
} Dem_PidClassType;

#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/


/*ECUC_Dem_00886*/
/*DemDTC:This container contains the configuration (parameters) for DemUdsDTC.*/
/*0..65535*/
typedef struct
{
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
    boolean DTCCombined;
    uint8 CombinedEventNum;
    Dem_EventIdType* CombinedEventId;
#endif
    Dem_EventIdType RefEventId;
    /*ECUC_Dem_00642*/
    uint16 DemDTCAttributesRef;
    /*ECUC_Dem_00643*/
    uint8 DemDTCFunctionalUnit;/*0 .. 255*/
    /*ECUC_Dem_00645*/
    Dem_DTCSeverityType DemDTCSeverity;
    /*ECUC_Dem_00887*/
    Dem_UdsDTCType DemDtcValue;
    Dem_NvStorageStrategyType DemNvStorage;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)||(DEM_J1939_SUPPORT == STD_ON))
    /*ECUC_Dem_00889*/
    const Dem_ObdDTCInfoType *DemObdDTCRef;
#endif
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    /*ECUC_Dem_00912*/
    Dem_DTCSeverityType DemWWHOBDDTCClass;
#endif
} Dem_DTCInfoType;

typedef enum
{
    DEM_EVENT_SIGNIFICANCE_OCCURRENCE = 0,
    DEM_EVENT_SIGNIFICANCE_FAULT
} Dem_DTCSignificanceType;

/*ECUC_Dem_00616*/
typedef enum
{
    DEM_AGINGCTR_DOWNCNT = 0,
    DEM_AGINGCTR_UPCNT = 1,
    DEM_AGINGCTR_UPCNT_FIRST_ACTIVE = 2,
    DEM_CLR_DIST = 3,
    DEM_CLR_TIME = 4,
    DEM_CURRENT_FDC = 5,
    DEM_CYCLES_SINCE_FIRST_FAILED = 6,
    DEM_CYCLES_SINCE_LAST_FAILED = 7,
    DEM_DTC_PRIORITY = 8,
    DEM_DTR = 9,
    DEM_EVENT_ASSOCIATED_IDENTIFICATION = 10,
    DEM_FAILED_CYCLES = 11,
    DEM_IUMPR = 12,
    DEM_J1939LAMP_STATUS = 13,
    DEM_MAX_FDC_DURING_CURRENT_CYCLE = 14,
    DEM_MAX_FDC_SINCE_LAST_CLEAR = 15,
    DEM_MIL_DIST = 16,
    DEM_MIL_TIME = 17,
    DEM_MONITOR_ACTIVITY_DATA = 18,
    DEM_OCCCTR = 19,
    DEM_OVFLIND = 20,
    DEM_SIGNIFICANCE = 21,
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    DEM_PASSED_CYCLES_SINCE_LAST_FAILED = 22,
    DEM_CMA_SI30 = 23,
    DEM_CMA_CONSECUTIVE_FAILED_CYCLES = 24,
#endif
    DEM_OBD_PASSED_CYCLES_SINCE_LAST_FAILED = 25,
    DEM_AGED_COUNTER = 26,
    DEM_MONITOR_DATA_0 = 27,
    DEM_MONITOR_DATA_1 = 28,
    DEM_WARM_UPS = 29
} Dem_InternalDataElementType;

/*ECUC_Dem_00619*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_DataElementReadFncType)
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Data
);

/*ECUC_Dem_00925*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_ClearDtcNotificationFncType)
(
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
);

typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_CallbackMonitorStatusChangedFncType)
(
    void
);

/*ECUC_Dem_00684*/
typedef struct
{
    /*ECUC_Dem_00614*/
    uint8 DemDataElementDataSize;/*1 .. 255*/
    /*ECUC_Dem_00616*//*SWS_Dem_00469*/
    Dem_InternalDataElementType DemInternalDataElement;
} Dem_InternalDataElementClassType;

/*ECUC_Dem_00668*/
typedef struct
{
    /*ECUC_Dem_00646*/
    uint8 DemDataElementDataSize;/*1 .. 255*/
    /*ECUC_Dem_00619*//*SWS_Dem_00261*/
    Dem_DataElementReadFncType DemDataElementReadFnc;
    /*ECUC_Dem_00647*/
    boolean DemDataElementUsePort;
#if(DEM_CORE_NUMBER > 1)
    uint8 CoreId;
    uint8 *DemDataElementDataBuff;
#endif
} Dem_ExternalCSDataElementClassType;

/*ECUC_Dem_00610*/
/*DemDataElementClass 0..65535*/
typedef struct
{
    /*ECUC_Dem_00684*/
    const Dem_InternalDataElementClassType *DemInternalDataElementClass;
    /*ECUC_Dem_00668*/
    const Dem_ExternalCSDataElementClassType *DemExternalCSDataElementClass;
} Dem_DataElementClassType;

/*******************************************************************************
* Dem_J1939Dcm Types
*******************************************************************************/
/*ECUC_Dem_00828*/
/*DemJ1939FreezeFrameClass 0..255*/
typedef struct
{
    uint8 Number;/*1..255*/
    /*ECUC_Dem_00829*/
    const uint32 *DemSPNClassRef;
} Dem_J1939FreezeFrameClassType;


/*ECUC_Dem_00830*/
/*DemSPNClass 0..524287(0x7FFFF)*/
typedef struct
{
    /*ECUC_Dem_00832*/
    uint16 DemSPNDataElementClassRef;/*Multiplicity: 1*/
    /*ECUC_Dem_00831*/
    uint32 DemSPNId;/*0..524287(0x7FFFF)*/
} Dem_SPNClassType;




typedef uint8 Dem_PriorityType;

/*ECUC_Dem_00641*/
/*DemDTCAttributes:This container contains the configuration (parameters) for DemDTCAttributes.*/
/*0..65535*/
typedef struct
{
    /*ECUC_Dem_00623*//*SWS_Dem_00493*/
    uint8 DemAgingCycleCounterThreshold;/*1 .. 255*/
#if(DEM_CFG_STATUSBITHANDLING_TFSLC == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
    /*ECUC_Dem_00897*/
    uint8 DemAgingCycleCounterThresholdForTFSLC;/*1 .. 255*/
#endif
    /*ECUC_Dem_00624*//*SWS_Dem_00494*/
    uint8 DemAgingCycleRef;
    /*ECUC_Dem_00662*/
    Dem_PriorityType DemDTCPriority;/*1 .. 255*/
    /*ECUC_Dem_00779*/
    Dem_DTCSignificanceType DemDTCSignificance;
    /*ECUC_Dem_00798*/
    /*ECUC_Dem_00667*/
    const uint8 *DemExtendedDataClassRef;
    /*ECUC_Dem_00674*/
   /* const uint8 *DemFreezeFrameClassRef; */
    /*ECUC_Dem_00776*/
    const uint8 *DemFreezeFrameRecNumClassRef;


#if(STD_ON == DEM_CFG_J1939EX_FF_SUPPORT)
    /*ECUC_Dem_00834*/
    const Dem_J1939FreezeFrameClassType *DemJ1939ExpandedFreezeFrameClassRef;/*0..1*/
#endif
#if(STD_ON == DEM_CFG_J1939_FF_SUPPORT)
    /*ECUC_Dem_00835*/
    const Dem_J1939FreezeFrameClassType *DemJ1939FreezeFrameClassRef;/*0..1*/
#endif
    /*ECUC_Dem_00605*//*SWS_Dem_00337*/
    uint8 DemFreezeFrameClassRef;
    uint8 DemMaxNumberFreezeFrameRecords;/*0 .. 255*/
    /*ECUC_Dem_00890*/
    uint16 DemMemoryDestinationRef;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    /*ECUC_Dem_00911*/
    uint16 DemWWHOBDFreezeFrameClassRef;
#endif
} Dem_DTCAttributesType;


typedef enum
{
    DEM_EVENT_KIND_BSW,
    DEM_EVENT_KIND_SWC
} Dem_EventKindType;

typedef enum
{
    DEM_REPORT_AFTER_INIT = 1,
    DEM_REPORT_BEFORE_INIT = 2
} Dem_ReportBehaviorType;

/*Dem_EventReportingType*/
typedef enum
{
    IMMEDIATE_FAIL_AND_SYNCHRONOUS_PROCESSING,
    STANDARD_REPORTING,
    STANDARD_REPORTING_WITH_MONITOR_DATA
} Dem_EventReportingType;

typedef enum
{
    DEM_DEBOUNCE_FREEZE,
    DEM_DEBOUNCE_RESET
} Dem_DebounceBehaviorType;

#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
/*ECUC_Dem_00881*/
/*DemDebounceCounterBasedClass  0..65535*/
typedef struct
{
#if(DEM_FDC_STORAGE_SUPPORT == STD_ON)
    /*ECUC_Dem_00914*/
    uint16 CounterBasedFdcThresholdStorageValue;/*1 .. 32767*/
#endif
    /*ECUC_Dem_00786*/
    Dem_DebounceBehaviorType DemDebounceBehavior;
    /*ECUC_Dem_00635*//*SWS_Dem_00419*/
    uint16 DemDebounceCounterDecrementStepSize;/*PREPASSED 1 .. 32768*/
    /*ECUC_Dem_00637*//*SWS_Dem_00418*/
    uint16 DemDebounceCounterIncrementStepSize;/*PREFAILED 1 .. 32767*/
    /*ECUC_Dem_00636*//*SWS_Dem_00417*/
    sint16 DemDebounceCounterPassedThreshold;/*-32768 .. -1*/
    /*ECUC_Dem_00618*//*SWS_Dem_00416*/
    sint16 DemDebounceCounterFailedThreshold;/*1 .. 32767*/
    /*ECUC_Dem_00685*//*SWS_Dem_00422*/
    boolean DemDebounceCounterJumpDown;
    /*ECUC_Dem_00686*//*SWS_Dem_00424*/
    boolean DemDebounceCounterJumpUp;
    /*ECUC_Dem_00638*//*SWS_Dem_00423*/
    sint16 DemDebounceCounterJumpDownValue;/*-32768 .. 32767*/
    /*ECUC_Dem_00639*//*SWS_Dem_00425*/
    sint16 DemDebounceCounterJumpUpValue;/*-32768 .. 32767*/
    /*ECUC_Dem_00791*/
    boolean DemDebounceCounterStorage;
} Dem_DebounceCounterBasedClassType;
#endif

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
/*ECUC_Dem_00882*/
/*DemDebounceTimeBaseClass  0..65535*/
typedef struct
{
#if(DEM_FDC_STORAGE_SUPPORT == STD_ON)
    /*ECUC_Dem_00914*/
    uint32 TimeBasedFdcThresholdStorageValue;
#endif
    /*ECUC_Dem_00789*/
    Dem_DebounceBehaviorType DemDebounceBehavior;
    /*ECUC_Dem_00717*/
    uint32 DemDebounceTimePassedThreshold;
    /*ECUC_Dem_00716*//*SWS_Dem_00434*/
    uint32 DemDebounceTimeFailedThreshold;
} Dem_DebounceTimeBaseClassType;
#endif
/*SWS_Dem_00622*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_CallbackGetFDCFncType)
(
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter
);

/*ECUC_Dem_00604*/
/*DemDebounceAlgorithmClass*/
typedef struct
{
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
    /*ECUC_Dem_00711*//*ECUC_Dem_00883*/
    const Dem_DebounceCounterBasedClassType *DemDebounceCounterBasedClassRef;
#endif

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
    /*ECUC_Dem_00713*//*ECUC_Dem_00891*/
    const Dem_DebounceTimeBaseClassType *DemDebounceTimeBaseRef;
#endif
    /*ECUC_Dem_00712*//*ECUC_Dem_00630*//*ECUC_Dem_00631*/
    const Dem_CallbackGetFDCFncType DemCallbackGetFDCFnc;
} Dem_DebounceAlgorithmClassType;

#if((DEM_CORE_NUMBER > 1) && (DEM_EVENT_CALLBACK_SUPPORT == STD_ON))
typedef struct
{
#if(DEM_INITMFORE_CALLBACK_SUPPORT == STD_ON)
    boolean InitMforETrigger;
    Dem_InitMonitorReasonType InitReason;
#endif
#if(DEM_MONITOR_CHANGE_CALLBACK_SUPPORT == STD_ON)
    boolean MonitorChangeTrigger;
#endif
#if(DEM_EVENT_STATUS_CHANGE_CALLBACK_SUPPORT == STD_ON)
    boolean EventStatuChangeTrigger;
    Dem_UdsStatusByteType EventOldStatus;
    Dem_UdsStatusByteType EventNewStatus;
#endif
#if(DEM_EVENT_DATA_CHANGE_CALLBACK_SUPPORT == STD_ON)
    boolean EventDataChangeTrigger;
#endif
#if(DEM_CLEAR_EVENT_ALLOWED_CALLBACK_SUPPORT == STD_ON)
    boolean ClearEventAllowedTrigger;
    uint8 ClearEventAllowedResult;
#endif
} Dem_CrossCoreTriggerType;
#endif

#if(DEM_CORE_NUMBER > 1)
typedef struct
{
    Dem_EventIdType NumOfEvent;
    Dem_EventIdType* EventIdList;
}Dem_CrossCoreEventType;
#endif

/*ECUC_Dem_00609*//*SWS_Dem_00620*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_CallbackClearEventAllowedFncType)
(
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) Allowed
);
/*ECUC_Dem_00788*/
typedef enum
{
    DEM_NO_STATUS_BYTE_CHANGE = (uint8)0,
    DEM_ONLY_THIS_CYCLE_AND_READINESS
} Dem_ClearEventAllowedBehaviorType;
/*ECUC_Dem_00607*/
typedef struct
{
    /*ECUC_Dem_00609*/
    Dem_CallbackClearEventAllowedFncType DemCallbackClearEventAllowedFnc;
    /*ECUC_Dem_00788*/
    Dem_ClearEventAllowedBehaviorType DemClearEventAllowedBehavior;
} Dem_CallbackClearEventAllowedType;

/*ECUC_Dem_00606*//*ECUC_Dem_00608*//*SWS_Dem_00618*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_CallbackEventDataChangedFncType)
(
    void
);

/*ECUC_Dem_00628*//*ECUC_Dem_00629*//*SWS_Dem_00615*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_CallbackEventStatusChangedFncType)
(
    Dem_UdsStatusByteType EventStatusByteOld,
    Dem_UdsStatusByteType EventStatusByteNew
);

/*ECUC_Dem_00632*//*ECUC_Dem_00601*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_DemCallbackInitMForEFncType)
(
    Dem_InitMonitorReasonType InitMonitorReason
);

/*SWS_Dem_91009*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_DemGeneralTriggerOnMonitorStatusType)
(
    Dem_EventIdType EventId
);

/*ECUC_Dem_00681*/
/*DemIndicatorAttribute:0..255*/
typedef struct
{
    /*ECUC_Dem_00682*//*SWS_Dem_00511*/
    Dem_IndicatorStatusType DemIndicatorBehaviour;
    /*ECUC_Dem_00750*//*SWS_Dem_00500*/
    /*If the failure counter is set to 0 or 1, it means Indicator
    should immediately ON when TestFaild bit is set to 1.*/
    uint8 DemIndicatorFailureCycleCounterThreshold;
    /*ECUC_Dem_00748*//*SWS_Dem_00502*/
    /*If the healing counter is set to 0, it means Indicator
    should immediately OFF when TestFaild bit is reset to 0
    event if TestFaildThisOperationCycle is 1.*/
    uint8 DemIndicatorHealingCycleCounterThreshold;
    /*ECUC_Dem_00687 DemIndicatorRef->ECUC_Dem_00680 DemIndicator->
    ECUC_Dem_00683 DemIndicatorID*//*SWS_Dem_00509*/
    uint8 DemIndicatorID;/*0..255*/
    uint8 DemIndicatorStatusPosOffset;/*position offset*/
} Dem_IndicatorAttributeType;

#if(DEM_NUM_OF_INDICATOR > 0)
/*Developer define*/
typedef P2FUNC(Std_ReturnType, DEM_APPL_CODE, Dem_DemCallbackIndicatorStatusNotify)
(
    Dem_EventIdType EventId,
    Dem_IndicatorStatusType IndicatorStatus
);

typedef struct
{
    Dem_DemCallbackIndicatorStatusNotify DemCallbackIndicatorStatusNotifyFnc;
    uint16 IndicatorStatusStartOffset;
    uint16 NumOfReferencedEvent;
} Dem_IndicatorStatusIndexType;
#endif

/*ECUC_Dem_00661*/
/*DemEventParameter:1..65535*/
typedef struct
{
    /*ECUC_Dem_00908*/
    uint16 DemComponentClassRef;
    /*ECUC_Dem_00909*/
    uint8 DemComponentPriority;/*0 .. 255*/
    /*ECUC_Dem_00888*/
    uint16 DemDTCRef;
#if(DEM_CORE_NUMBER > 1)
    uint8 EventCoreRef;
#endif
    /*ECUC_Dem_00746*//*SWS_Dem_00446*/
#if(DEM_NUM_OF_EN_GROUP > 0)
    const Dem_EnableConditionGroupType *DemEnableConditionGroupRef;
#endif

#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    /*ECUC_Dem_00792*/
    boolean DemEventAvailable;
#endif

    uint8 DemEventConfirmationThreshold;
#if((DEM_EVENT_CALLBACK_SUPPORT == STD_ON) && (DEM_CORE_NUMBER > 1))
    Dem_CrossCoreTriggerType* CrossCoreTriggerInfo;
#endif
    /*ECUC_Dem_00659*/
    Dem_EventIdType DemEventId;/*1 .. 65535*/
    /*ECUC_Dem_00660*/
    Dem_EventKindType DemEventKind;
    /*ECUC_Dem_00671*//*SWS_Dem_00002*/
    boolean DemFFPrestorageSupported;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    /*ECUC_Dem_00839*/
    /*uint16 DemOBDGroupingAssociativeEventsRef;*/
#endif
    /*ECUC_Dem_00702*//*SWS_Dem_00529*/
    uint8 DemOperationCycleRef;
    /*ECUC_Dem_00894*/
    Dem_ReportBehaviorType DemReportBehavior;/*DemEventKind == DEM_EVENT_KIND_BSW*/
    /*ECUC_Dem_00970*/
    Dem_EventReportingType DemEventReportingType;
    /*ECUC_Dem_00769*//*SWS_Dem_00453*/
#if(DEM_NUM_OF_STOR_GROUP > 0)
    const Dem_StorageConditionGroupType *DemStorageConditionGroupRef;
#endif
#if(DEM_NUM_OF_INDICATOR > 0)
    /*ECUC_Dem_00681*//*SWS_Dem_00510*/
    uint8 NumOfIndicator;
    const Dem_IndicatorAttributeType *DemIndicatorAttribute;
#endif
    /*ECUC_Dem_00604*//*SWS_Dem_00413*/
    Dem_DebounceAlgorithmClassType DemDebounceAlgorithmClass;

    /*ECUC_Dem_00607*/
    Dem_CallbackClearEventAllowedType DemCallbackClearEventAllowed;
    /*ECUC_Dem_00606*//*ECUC_Dem_00608*/
    Dem_CallbackEventDataChangedFncType DemCallbackEventDataChangedFnc;
    /*ECUC_Dem_00628*//*ECUC_Dem_00629*/
    Dem_CallbackEventStatusChangedFncType DemCallbackEventStatusChangedFnc;
    /*ECUC_Dem_00632*//*ECUC_Dem_00601*/
    Dem_DemCallbackInitMForEFncType DemCallbackInitMForEFnc;
    Dem_CallbackMonitorStatusChangedFncType DemCallbackMonitorStatusChangedFnc;
} Dem_EventParameterType;


/*ECUC_Dem_00706*/
/*DemDidClass 0..65535*/
typedef struct
{
    uint8 Number;
    /*ECUC_Dem_00617*/
    const uint16 *DemDidDataElementClassRef;
    /*ECUC_Dem_00650*/
    uint16 DemDidIdentifier;
} Dem_DidClassType;

typedef enum
{
    DEM_UPDATE_RECORD_NO = 0,
    DEM_UPDATE_RECORD_YES
} Dem_RecordUpdateType;

/*ECUC_Dem_00801*/
/*DemFreezeFrameRecordClass 0...255*/
typedef struct
{
    /*ECUC_Dem_00777*/
    uint8 DemFreezeFrameRecordNumber;/*0...254*/
    /*ECUC_Dem_00803*/
    Dem_EventMemoryEntryStorageTriggerType DemFreezeFrameRecordTrigger;
    /*ECUC_Dem_00802*/
    Dem_RecordUpdateType DemFreezeFrameRecordUpdate;
    /*ECUC_Dem_00674/ECUC_Dem_00673  Dem_FreezeFrameClassType*/
    /*SWS_Dem_00040*/
    uint8 Number;
    /*ECUC_Dem_00707*/
    const uint8 *DemDidClassRef;
} Dem_FreezeFrameRecordClassType;

typedef struct
{
    /*SWS_Dem_00040*/
    uint8 Number;
    /*ECUC_Dem_00707*/
    const uint8 *DemDidClassRef;
} Dem_FreezeFrameClassType;

/*ECUC_Dem_00775*/
/*DemFreezeFrameRecNumClass 0..255*/
typedef struct
{
    uint8 Number;
    /*ECUC_Dem_00800*/
    const uint8 *DemFreezeFrameRecordClassRef;
} Dem_FreezeFrameRecNumClassType;

/*ECUC_Dem_00664*/
/*DemExtendedDataClass*/
typedef struct
{
    uint8 Number;
    /*ECUC_Dem_00774*/
    const uint8 *DemExtendedDataRecordClassRef;/*0...253*/
} Dem_ExtendedDataClassType;

/*ECUC_Dem_00665*/
/*DemExtendedDataRecordClass*/
typedef struct
{
    uint8 Number;
    /*ECUC_Dem_00771*/
    const uint16 *DemDataElementClassRef;
    /*ECUC_Dem_00666*/
    uint8 DemExtendedDataRecordNumber;/*1 .. 239*/
    /*ECUC_Dem_00804*/
    Dem_EventMemoryEntryStorageTriggerType DemExtendedDataRecordTrigger;
    /*ECUC_Dem_00621*/
    Dem_RecordUpdateType DemExtendedDataRecordUpdate;
} Dem_ExtendedDataRecordClassType;


/*******************************************************************************
* Event Memory Type
*******************************************************************************/
typedef struct
{
    /*0xFFFF is invalid value*/
    Dem_EventIdType FirstFailedEvent;
    /*0xFFFF is invalid value*/
    Dem_EventIdType FirstConfirmedEvent;
    /*0xFFFF is invalid value, only bit0 changed from 0 to 1 can affect the parameter's value*/
    Dem_EventIdType MostRecentFailedEvent;
    /*0xFFFF is invalid value, only bit3 changed from 0 to 1 can affect the parameter's value*/
    Dem_EventIdType MostRecentConfirmedEvent;
} Dem_EventHeadType;

typedef struct
{
#if(DEM_EVENT_ONE_TO_ONE_DTC_ENABLED == STD_OFF)
    Dem_UdsStatusByteType EventStatus;
#endif
    uint8 EventFaultConfCnt;
    /*SWS_Dem_00011*/
    uint8 EventOccurrence;/*Event occurrence*/
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
    uint8 EventAgingCounter;
    Dem_MemIdType DataEntryRef;
#endif
    /*User requirement*/
#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
    uint8 PreStorageFFEntryRef;
#endif

#if(DEM_MONITORDATA_SUPPORT == STD_ON)
    Dem_MonitorDataType MonitorData_0;
    Dem_MonitorDataType MonitorData_1;
#endif
#if(DEM_NUM_OF_INDICATOR > 0)
    /*SWS_Dem_00499*/
    uint8 IndicatorFailureCycleCounter;
    uint8 IndicatorHealingCycleCounter;
#endif
#if((DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON) && (DEM_DEBOUNCE_COUNTER_STORAGE_SUPPORT == STD_ON))
    /*SWS_Dem_00414*/
    sint16 EventDebounceCnt;/*Debounce Counter*/
#endif
#if(DEM_EVENT_MAXFDCDCC_SUPPORT == STD_ON)
    /*SWS_Dem_00788*/
    sint8 EventMaxFdcDuringCurrentCycle;
#endif
#if(DEM_EVENT_MAXFDCSLC_SUPPORT == STD_ON)
    /*SWS_Dem_00792*/
    sint8 EventMaxFdcSinceLastClear;
#endif
#if(DEM_EVENT_CSLF_SUPPORT == STD_ON)
    /*SWS_Dem_00984*/
    uint8 EventCyclesSinceLastFailed;
#endif
#if(DEM_EVENT_CSFF_SUPPORT == STD_ON)
    /*SWS_Dem_00775*/
    uint8 EventCyclesSinceFirstFailed;
#endif
#if(DEM_EVENT_FCSLC_SUPPORT == STD_ON)
    /*SWS_Dem_00779*/
    uint8 EventFailedCyclesSinceLastCleared;
#endif
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    /*number of continuous no fault operation cycle*/
    uint8 EventOBDPassedCyclesSinceLastFailed;
#endif
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
    /*Used for clear permanent DTC,
    Reset condition: Event fail again/Data failed to recover from NVRAM;
    Set TRUE condition: When an external diagnostic device requests to clear the DTC.*/
    boolean EventClearFlagForPermanent;
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    /*SI30:
    **bit0:UDTC  bit1:UDTCTOC  bit2:UDTCSLC
    **bit3:ADTC  The four bits are not used, shall be set to 0.
    **bit4:SSLC  bit5:WIRSLC
    **bit6:ERDTC bit7:TFSLCA*/
    uint8 EventCMAStatus;
    uint8 EventPassedCyclesSinceLastFailed;
#endif
} Dem_EventEntryType;

typedef struct
{
    /*SWS_Dem_01183*/
    Dem_UdsStatusByteType DtcStatus;
#if(DEM_DTC_LASTSTATUS_SUPPORT == STD_ON)
    Dem_UdsStatusByteType DtcLastStatus;
#endif
    /*SWS_Dem_00019*//*SWS_Dem_00492*/
    uint8 DtcAgingCounter;
#if(DEM_DTC_AGEDCNT_SUPPORT == STD_ON)
    /*User requirement*/
    uint8 DtcAgedCounter;
#endif
    /*0xFFFF is invalid value*/
    Dem_MemIdType DataEntryRef;
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
    uint8 DataEntryRefNum;
#endif
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
    /*SWS_Dem_00672*/
    sint8 CbDTC_FDC;
#endif
} Dem_DTCEntryType;


typedef struct
{
    uint16 EventId;
    boolean Used;
    /*SWS_Dem_00796*//*SWS_Dem_00039*/
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
    uint8 PreStorageFFData[DEM_MAX_FFSIZE_OF_DTC];
#endif
} Dem_PreStoreFFEntryType;
typedef struct
{
    boolean Used;
    /*SWS_Dem_00796*//*SWS_Dem_00039*/
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
    uint8 FreezeFrameData[DEM_MAX_FFSIZE_OF_DTC];
#endif
#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
    uint8 ExtendedData[DEM_MAX_EXTSIZE_OF_DTC];
#endif
#if(DEM_MAX_J1939FFSIZE_OF_DTC > 0)
    uint8 J1939FreezeFrameData[DEM_MAX_J1939FFSIZE_OF_DTC];
#endif
#if(DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0)
    uint8 J1939ExpFreezeFrameData[DEM_MAX_J1939EXPFFSIZE_OF_DTC];
#endif
    uint8 DemCrcValue[4]; /*u32 change to u8[4] to make sure the align issue*/
} Dem_DTCDataEntryType;


typedef struct
{
    Dem_DTCDataEntryType *DTCDataEntryPtr;
    uint16 DemBlockId;
} Dem_DTCDataInfoType;



#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))

#define DEM_NUM_OF_DEN_CONDITION   (uint8)4

typedef struct
{
    uint16 TestResult;
    uint16 LowerLimit;
    uint16 UpperLimit;
} Dem_DtrInfoType;

typedef struct
{
    /*Used for PID01/41*/
    uint8 ReadinessGroupStatus[4];
    /*Used for PID31.Unit:m, Range:0-65535000*/
    uint32 DistanceSinceDtcCleared;
    /*Used for PID21.Unit:m, Range:0-65535000*/
    uint32 DistanceTraveledMILActivated;
    /*Used for PID4D.Unit:min, Range:0-65535*/
    uint32 EngineRunTimeMILActivated;
    /*Used for PID4E.Unit:min, Range:0-65535*/
    uint32 EngineRunTimeDtcCleared;
    /*Used for PID30*/
    uint8 NumberOfWarmSinceDtcCleared;
    /*Data for Service 02*/
    Dem_EventIdType ObdEventId;
    uint8 ObdFreezeFrameData[DEM_CFG_OBD_FF_LENGTH];
#if(DEM_NUM_OF_RATIO > 0)
    /*Data for Infotype 08/0B of Service 09*/
    uint16 RatioIGNCycleCounter;
    uint16 RatioGeneralDenominatorCounter;
    uint8 RatioGeneralDenominatorState;/*Same to RatioState*/
    Dem_IumprDenomCondStatusType RatioDenomCondStatus[DEM_NUM_OF_DEN_CONDITION];/*only 4 elements*/
    uint16 RatioNumerator[DEM_NUM_OF_RATIO];
    uint16 RatioDenominator[DEM_NUM_OF_RATIO];
    /*bit 0: Numerator increased flag;
      bit 1: Denominator increased flag;
      bit 2: Denominator lock flag.*/
    uint8 RatioState[DEM_NUM_OF_RATIO];
#endif
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
    uint8 PfcCycleStatus;/*Permanent fault code - driving cycle Status*/
#endif
#if(DEM_MAX_NUM_OF_DTR > 0)
    Dem_DtrInfoType DtrInfo[DEM_MAX_NUM_OF_DTR];
#endif
} Dem_OBDDataInfoType;




#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/



typedef struct
{
    Dem_UdsStatusByteType DemDtcStatusAvailabilityMask;
    Dem_EventDisplacementStrategyType EventDisplacementStrategy;
    Dem_EventMemoryEntryStorageTriggerType EventMemoryEntryStorageTrigger;
    Dem_MemIdType MaxNumberEventEntry;
    Dem_OccurrenceCounterProcessingType  OccurrenceCounterProcessing;
    Dem_TypeOfFreezeFrameRecordNumerationType TypeOfFreezeFrameRecordNumeration;
} Dem_PrimaryMemoryType;

typedef struct
{
    Dem_UdsStatusByteType DemDtcStatusAvailabilityMask;
    Dem_EventDisplacementStrategyType EventDisplacementStrategy;
    Dem_EventMemoryEntryStorageTriggerType EventMemoryEntryStorageTrigger;
    Dem_MemIdType MaxNumberEventEntry;
    Dem_OccurrenceCounterProcessingType  OccurrenceCounterProcessing;
    Dem_TypeOfFreezeFrameRecordNumerationType TypeOfFreezeFrameRecordNumeration;
    uint8 UserDefinedMemoryIdentifier;
} Dem_UserDefinedParameterType;



/*ECUC_Dem_00939*/
typedef struct
{
    uint8 MaxNumberEventEntryPermanent;
    Dem_DTCTranslationFormatType TypeOfDTCSupported;
    uint8 AmberWarningLampIndicatorRef;
    uint8 MILIndicatorRef;
    uint8 ProtectLampIndicatorRef;
    uint8 RedStopLampIndicatorRef;
    Dem_ClearDtcNotificationFncType ClearDtcNotificationFnc;
    Dem_ClearDtcNotificationTimeType ClearDtcNotificationTime;
#if(DEM_NUM_OF_USERDEF > 0)
    uint8 UserdefNum;
    uint8 UserdefStart;
#endif
#if(DEM_NUM_OF_DTCGROUP > 0)
    const Dem_DTCGroupInfoType *DTCGroup;
    uint8 NumOfDTCGroup;
#endif
} Dem_EventMemorySetType;

/*ECUC_Dem_00931*/
typedef struct
{
    uint8 ClientId;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType RefCoreId;
#endif
    Dem_ClientFunctionalityType ClientFunc;
    boolean DemClientUsesRte;
    uint8 DemEventMemorySetRef;
    /*ECUC_Dem_00626*/
    Dem_DTCStatusChangedNotificationType DTCStatusChangedNotificationFnc;
} Dem_ClientType;


#if(DEM_CFG_BSWERRORBUFFERSIZE > 0)
typedef struct
{
    Dem_EventIdType ReportEventId[DEM_CFG_BSWERRORBUFFERSIZE];
    Dem_EventStatusType ReportEventStatu[DEM_CFG_BSWERRORBUFFERSIZE];
} Dem_BSWEventQueueType;
#endif

/*SWS_Dem_00924*/
typedef struct
{
    uint16 NumOfDTC;
    uint16 NumOfEvent;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    uint8  NumOfPid;
#endif
    const Dem_EventParameterType *EventTable;
    const Dem_DTCInfoType *DTCTable;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    const Dem_PidClassType *PidTable;
#endif

} Dem_ConfigType;


typedef struct
{
    Dem_OperationCycleStateType Dem_OpCycState[DEM_NUM_OF_OPCYCLE];
    Dem_EventHeadType EventHead;
    Dem_EventEntryType EventEntry[DEM_MAXNUM_OF_EVENT];
    Dem_DTCEntryType DtcEntry[DEM_MAXNUM_OF_DTC];
    Dem_MemIdType PrimaryDataEntryUsedNum[DEM_NUM_OF_EVENTMEMORYSET];
#if(DEM_NUM_OF_USERDEF > 0)
    Dem_MemIdType UserDefinedEntryUsedNum[DEM_NUM_OF_EVENTMEMORYSET][DEM_NUM_OF_USERDEF];
#endif
#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
    Dem_PreStoreFFEntryType PreStorageEntry[DEM_CFG_MAXNUMBER_PRESTOREDFF];
#endif
#if(DEM_NUM_OF_INDICATOR > 0)
    /*data struct is as below:
    --Indicator0--------|--Indicator1-----------...-----------|--IndicatorN...
    State00,...,State0X,|State10,..,State1Y,..................|StateN0,...StateNZ...*/
    Dem_IndicatorStatusType IndicatorStatus[DEM_NUM_OF_BYTE_RECORD_INDICATOR_STATE];
#endif/*#if(DEM_NUM_OF_INDICATOR > 0)*/
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    Dem_OBDDataInfoType OBDDataInfo;
#endif
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
    uint16 PermanentEntryUsedNum[DEM_NUM_OF_EVENTMEMORYSET];
    Dem_EventIdType PermanentDataEntry[DEM_NUM_OF_EVENTMEMORYSET][DEM_MAX_NUMBER_EVENTENTRY_PERMANENT];
#endif/*#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)*/

    uint8 DemCrcValue[4]; /*u32 change to u8[4] to make sure the align issue*/

} Dem_StorageMemType;

#endif /* DEM_TYPES_H */


