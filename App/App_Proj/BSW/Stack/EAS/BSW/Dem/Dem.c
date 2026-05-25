/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dem.c
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : Dem.c
*   Author          : Hirain
********************************************************************************
*   Description: Main source file of the AUTOSAR Diagnositc Event Manager,
*                    AUTOSAR_SWS_DiagnosticEventManager.pdf (Release 4.2)
*                    and ISO14229-1(2013).pdf.
********************************************************************************
*   Limitations: None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version      Date         Initials          CR#       Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   04.00.00    10/10/2023    chaolimen.han     N/A       Beta
*   04.00.01    13/04/2024    chaolimen.han     N/A       EAS470_Dem_20240413_01
*   04.00.02    15/04/2024    chaolimen.han     N/A       EAS470_Dem_20240415_01
*   04.00.03    16/04/2024    chaolimen.han     N/A       EAS470_Dem_20240416_01
*   04.00.03    30/04/2024    chaolimen.han     N/A       EAS470_Dem_20240430_01
*   04.00.04    11/05/2024    chaolimen.han     N/A       EAS470_Dem_20240511_01
*   04.00.05    17/06/2024    chaolimen.han     N/A       EAS470_Dem_20240617_01
*   04.00.06    24/06/2024    chaolimen.han     N/A       EAS470_Dem_20240624_01
*   04.00.07    10/07/2024    chaolimen.han     N/A       EAS470_Dem_20240710_01
*   04.00.08    19/07/2024    chaolimen.han     N/A       EAS470_Dem_20240719_01
*   04.01.00    16/08/2024    chaolimen.han     N/A       EAS470_Dem_20240816_01
*   04.01.01    21/08/2024    chaolimen.han     N/A       EAS470_Dem_20240821_01
*   04.01.02    23/09/2024    chaolimen.han     N/A       EAS470_Dem_20240923_01
*   04.01.03    14/11/2024    chaolimen.han     N/A       EAS470_Dem_20241114_01
*   04.01.04    19/11/2024    chaolimen.han     N/A       EAS470_Dem_20241119_01
*   04.02.00    19/11/2024    chaolimen.han     N/A       EAS470_Dem_20241119_01
*   04.02.01    29/11/2024    chaolimen.han     N/A       EAS470_Dem_20241129_01
*   04.02.02    06/12/2024    chaolimen.han     N/A       EAS470_Dem_20241206_01
*   04.02.03    02/01/2025    chaolimen.han     N/A       EAS470_Dem_20250102_01
*   04.02.04    03/01/2025    chaolimen.han     N/A       EAS470_Dem_20250103_01
*   04.02.05    18/02/2025    chaolimen.han     N/A       EAS470_Dem_20250218_01
*   04.02.06    18/02/2025    chaolimen.han     N/A       EAS470_Dem_20250218_01
*   04.02.07    31/03/2025    chaolimen.han     N/A       EAS470_Dem_20250331_01
*   04.02.08    02/04/2025    chaolimen.han     N/A       EAS470_Dem_20250402_01
*   04.02.09    29/04/2025    chaolimen.han     N/A       EAS470_Dem_20250429_01
*   04.02.10    27/05/2025    chaolimen.han     N/A       EAS470_Dem_20250527_01
********************************************************************************
* END_FILE_HDR*/

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 4599 EOF*/
/*
Operands of binary operator '%1s' have the same type '%2s' but distinct type names '%3s' and '%4s'.
*/
/*PRQA S 0777 EOF*/
/*
External identifier does not differ from other identifier(s) (e.g. '%s') within the specified number of significant characters.
*/
/*PRQA S 2982,2984 EOF*/
/*
This assignment is redundant. The value of this object is never used before being modified.
*/
/*PRQA S 5087,3614,3214,862,292 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "EcuM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in EcuM_MemMap.h
*/

/*PRQA S 3453,3429 EOF*/
/*
1.The unified requirement of EAS is that the error reporting functions of Det
and Dem moduls are accessed by macro functions.This part has been verified and
has no problem.
2.Macro functions are allowed to use to access parameters and do some simple operations.
*/

/*PRQA S 3432,3410,3409 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no
need to revise.
*/

/*PRQA S 3673,4603 EOF*/
/*
Parameters in AUTOSAR standard APIs,they may not follow this rule.
*/

/*PRQA S 3212,3218 EOF*/
/*
Unified requirements of EAS: constant shall be converted.
Allow static variables that are only used once.
*/

/*PRQA S 3119 EOF*/
/*
No unified input parameter processing is used
*/

/*PRQA S 3197 EOF*/
/*
Redundant initialization will not cause functional problems,there is no need to
revise.And it is the requirement of programming specification to initialize
local variables.
*/

/*PRQA S 3138,3141 EOF*/
/*
The code of critical segments can be configured as void when QAC testing.
Note:When called by Det,Dem or BswM, the critical segments must be enabled when
QAC testing.Reasons are needed for special circumstances not enabled.
*/

/*PRQA S 3416 EOF*/
/*
In a If statement,calling a function to directly determine the return value is
allowed if there is only one judge branch.
*/

/*PRQA S 0857,0380 EOF*/
/*
Macro definitions exceed 1024. The number of macros is unlimited
*/

/*PRQA S 3227 EOF*/
/*
Read-only function input parameters may not be defined as const,it does not affect the function.
AUTOSAR API shall define standard input parameters according to specification requirements.
*/

/*PRQA S 3672 EOF*/
/*
Allow non-const function Pointers.
*/

/*PRQA S 2741,3324 EOF*/
/*
Macro DEM_EVENT_COMBINATION_SUPPORT changes under different configuration conditions.
*/


/*****************************************************************************
 *  Dem QAC Suppression
 *****************************************************************************/
/*PRQA S 0791,0792,778,779 EOF*/
/*
Relevant names of DEM_CFG_CLEAR_DTC_NOTIFICATION_TIME may not follow relevant naming rules,for example,DEM_CFG_CLEAR_DTC_NOTIFICATION_FUN.
Names in core files may not follow relevant rules.
*/

/*PRQA S 3435,3456,3103 EOF*/
/*
Using a specific formula, you need to use multiple parameters.
Result of signed division or remainder operation may be implementation defined.
*/

/*PRQA S 2100,2101,2104,2105,2144,2742,3112 EOF*/
/*
Integer promotion related.
Particularity of configuration files.
*/

/*PRQA S 2000,2013,2201 EOF*/
/*
When there is only one If,there can be no else.
*/

/*PRQA S 3892,771,1863,751 EOF*/
/*
Based on the function implementation, there is no need to modify.
*/

/*PRQA S 4397,4130,4570,4390 EOF*/
/*
The bit operation of the failure event status code transformation is not modified. For example DEM_SET_UDS_STATUS_TF.
*/

/*PRQA S 3204 EOF*/
/*
Read-only local variables may not be defined as const,this does not affect the function
*/

/*PRQA S 488,489 EOF*/
/*
Change the operation of the pointer to the array member address without modification.
Pointers to the address are added and subtract.
*/

/*PRQA S 1338 EOF*/
/*
Specific implementation methods.
*/

/*PRQA S 3383 EOF*/
/*
Addition and subtraction operations on internal variables of dcm doesn't overflow.
*/

/*PRQA S 2844,2814,2824 EOF*/
/*
Variable EventId and DtcId are effectively checked.
*/

/*PRQA S 2880,2877,2934 EOF*/
/*
An internal statement is executed only when the configuration meets the if condition.
Depends on configuration.
Multiple return are allowed.
*/

/*PRQA S 1503,1504,1505 EOF*/
/*
Function declared externally are called by the user.
Variable declared externally are used by the user.
*/

/*PRQA S 2962,2991,2992,2996,2986 EOF*/
/*
All variable are initialized.
Depends on configuration.
*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Dem.h"
#include "Dem_Dcm.h"
#include "Dem_NvM.h"
#include "Dem_Lcfg.h"
#include "SchM_Dem.h"
#if(DEM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if(DEM_CORE_NUMBER > 1)
#include "Bmc.h"
#endif
#if(DEM_NVM_SUPPORT == STD_ON)
#include "NvM.h"
#endif
#if(DEM_FIM_SUPPORT == STD_ON)
#include "FiM.h"
#endif
#include "Bsw_Common.h"

/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(DEM_PRIVATE_VERSION_CHECK == STD_ON)
/* check Version with cfg file */
#if ((DEM_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (DEM_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of Dem and its cfg file are different"
#endif

#if ((DEM_SW_MAJOR_VERSION != DEM_SW_MAJOR_VERSION_CFG) || \
   (DEM_SW_MINOR_VERSION != DEM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of Dem and its cfg file are different"
#endif

#endif/*(DEM_PRIVATE_VERSION_CHECK == STD_ON)*/

/*******************************************************************************
*   Cfg data Check
*******************************************************************************/
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#if(0 == DEM_CFG_OBD_MAXNUM_OF_PID)
#error "The number of Pid should not be 0 while OBD is supported."
#endif
#if(0 == DEM_NUM_OF_INDICATOR)
#error "The number of indicator should not be 0 while OBD is supported."
#endif
#else/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/
#if(0 != DEM_MAX_NUMBER_EVENTENTRY_PERMANENT)
#error "The number of permanent memory entry should be 0 if OBD is not supported."
#endif
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/

#if((DEM_EVENT_ONE_TO_ONE_DTC_ENABLED == STD_ON) && (DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED))
#error "There is currently a one-to-one relationship between Events and DTCs, so the parameter DemEventCombinationSupport shoud be selected as DEM_EVCOMB_DISABLED."
#endif

#if((DEM_CFG_MAXNUMBER_PRESTOREDFF > 0) && (DEM_MAX_FFSIZE_OF_DTC == 0))
#error "If DemMaxNumberPrestoredFF parameter is not configured to 0, you should configure DemFreezeFrameRecNumClassRef of DemDTCAttributes for at least one DTC."
#endif
/*******************************************************************************
*   Macro
*******************************************************************************/
#if(DEM_DEV_ERROR_DETECT == STD_ON)
#define DEM_DET_ERROR_DETECT(cond, ApiId, errcode)  \
    DET_ERROR_DETECT(cond, DEM_MODULE_ID, DEM_INSTANCE_ID, ApiId, errcode)

#define DEM_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret) \
    DET_ERROR_DETECT_RET(cond, DEM_MODULE_ID, DEM_INSTANCE_ID, ApiId, errcode, ret)

#define DEM_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(DEM_MODULE_ID, DEM_INSTANCE_ID, ApiId, errcode)
#else
#define DEM_DET_ERROR_DETECT(cond, ApiId, errcode)
#define DEM_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret)
#define DEM_DET_REPORT_ERROR(ApiId, errcode)
#endif

typedef uint8 Dem_StateType;
#define DEM_UNINIT                         ((Dem_StateType)0x00)
#define DEM_PREINIT                        ((Dem_StateType)0x01)
#define DEM_NORMAL                         ((Dem_StateType)0x02)

#define DEM_UINT16_2                ((uint16)2)
#define DEM_UINT16_8                ((uint16)8)

#define DEM_UINT8_5                 ((uint8)5)

typedef uint8 Dem_UserdefinedIdType;
/*Clear DTC State*/
#define DEM_IN_CLEAR_DTC_IDLE              ((uint8)0x00)
#define DEM_IN_CLEAR_DTC_BUSY              ((uint8)0x01)
#define DEM_IN_CLEAR_DTC_OK                ((uint8)0x02)
#define DEM_IN_CLEAR_DTC_ERR               ((uint8)0x03)
#define DEM_IN_CLEAR_EVENT_MEM             ((uint8)0x04)
#define DEM_IN_CLEAR_DTC_GROUP_WAIT        ((uint8)0x05)
#define DEM_IN_CLEAR_DTC_BUSY_SINGLE       ((uint8)0x06)
#define DEM_IN_CLEAR_DTC_BUSY_GROUP        ((uint8)0x07)
#define DEM_IN_CLEAR_DTC_FAILED            ((uint8)0x08)
#define DEM_IN_CLEAR_DTC_SINGLE_WAIT       ((uint8)0x09)
#define DEM_IN_CLEAR_DTC_GROUP_FINISH      ((uint8)0x0A)
#define DEM_IN_CLEAR_DTC_SINGLE_FINISH     ((uint8)0x0B)


/*Select DTC State*/
#define DEM_IN_SELECT_DTC_IDLE             ((uint8)0x50)
#define DEM_IN_SELECT_DTC_PROCESSING       ((uint8)0x51)
#define DEM_IN_SELECT_DTC_GROUP            ((uint8)0x57)
#define DEM_IN_SELECT_DTC_SINGLE           ((uint8)0x58)
#define DEM_IN_SELECT_DTC_CHECKING         ((uint8)0x59)
#define DEM_IN_SELECT_DTC_PENDING          ((uint8)0x5A)

#define DEM_CLEAR_NUM_PER_CYCLE            ((uint16)20)

/*Event Status Mask*/
#define DEM_EVENT_STATUS_UPDATE_MASK       ((Dem_EventStatusType)0x80)
#define DEM_EVENT_MONITOR_STATUS_MASK      ((Dem_EventStatusType)0x42)

/*Event Notification Mask*/
#define DEM_NOTI_MASK_INVALID              ((uint8)0x00)
#define DEM_NOTI_MASK_CLEAR_ALLOWED        ((uint8)0x01)
#define DEM_NOTI_MASK_MONITOR_STATUSCHANGED  ((uint8)0x02)
#define DEM_NOTI_MASK_EVENT_DATACHANGED    ((uint8)0x04)
#define DEM_NOTI_MASK_DTC_STATUSCHANGED    ((uint8)0x08)
#define DEM_NOTI_MASK_INITMFORE            ((uint8)0x10)



#define DEM_DATA_INVALID_U8                ((uint8)0xFF)
#define DEM_CLIENT_INVALID_U8              ((uint8)0xFF)
#define DEM_DATA_INVALID_U16               ((uint16)0xFFFF)
#define DEM_DATA_CLEAR                     (0u)
#define DEM_DATA_MAX_FDC                   ((sint8)127)
#define DEM_DATA_U8_FF                     ((uint8)0xFF)
#define DEM_OBD_PCSLF_MAXVALUE             ((uint8)3)
#define DEM_DATA_8                         ((uint8)8)
#define DEM_DATA_LENGTH_2                  (2)
#define DEM_RECORED_NUMBER_EF              ((uint8)0xEF)
#define DEM_RECORED_NUMBER_FF              ((uint8)0xFF)
#define DEM_RECORED_NUMBER_FD              ((uint8)0xFD)
#define DEM_FDC_10                         ((uint8)0x10)

#define DEM_DTC_REQURE_USERDEFINED_MEMORY_ID        ((uint16)0x00FF)
#define DEM_IS_INVALIED_READINESSGROUP(i)  ((uint8)i > (uint8)17)

#define DEM_STATUS_RESET                   ((Dem_UdsStatusByteType)0x50)
#define DEM_MONITOR_STATUS_RESET           ((Dem_MonitorStatusType)0x02)

#define DEM_F_FDC_FACTOR                   ((uint8)127)
#define DEM_P_FDC_FACTOR                   ((uint8)128)

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#define DEM_OBD_PID1C_DATA_LENGTH   (1)/*byte*/
#define DEM_OBD_PID21_DATA_LENGTH   (2)/*byte*/
#define DEM_OBD_PID30_DATA_LENGTH   (1)/*byte*/
#define DEM_OBD_PID4D_DATA_LENGTH   (2)/*byte*/
#define DEM_OBD_PID4E_DATA_LENGTH   (2)/*byte*/
#define DEM_OBD_PID91_DATA_LENGTH   (5)/*byte*/
#define DEM_OBD_INFO08_DATA_LENGTH  (40)/*byte: 32/40/56*/
#define DEM_OBD_INFO0B_DATA_LENGTH  (36)/*byte: 32/36*/

#define DEM_INDEX_0                 (0)
#define DEM_INDEX_1                 (1)
#define DEM_INDEX_2                 (2)
#define DEM_INDEX_3                 (3)

#define DEM_DATA_1000               (1000U)
#define DEM_DATA_60                 (60U)
#endif

#if(DEM_NUM_OF_RATIO > 0)
#define DEM_OBD_NUM_INCREASED_MASK  ((uint8)0x01)
#define DEM_OBD_DEN_INCREASED_MASK  ((uint8)0x02)
#define DEM_OBD_DEN_LOCK_MASK       ((uint8)0x04)
/*Numerator/Denominator max value*/
#define DEM_OBD_NUMDEN_MAX_VALUE    ((uint16)65535)
#endif

#if(DEM_NUM_OF_INDICATOR > 0)
typedef enum
{
    DEM_TF_CLEAR = 0,/*TestFailed bit of DTC status is reset to 0.*/
    DEM_CYCLE_END = 1/*Operation cycle end.*/
} Dem_IndicatorOffType;
#endif

#define DEM_SET_STATE(state)          (Dem_State = state)
#define DEM_GET_STATE                 (Dem_State)
#if(DEM_CORE_NUMBER > 1)
#define DEM_SELECT_DTC_STATE          (Dem_SelectDTC_State[CoreId])
#else
#define DEM_SELECT_DTC_STATE          (Dem_SelectDTC_State)
#endif
/*Enable Condition*/
#define DEM_ENABLECONDITION_STATU(i)           (Dem_EnConditionTable[i].DemEnableConditionStatus)

/*Storage Condition*/
#define DEM_STORAGECONDITION_STATU(i)          (Dem_StorageConditionTable[i].DemStorageConditionStatus)
/*Event*/
#if(DEM_EVENT_ONE_TO_ONE_DTC_ENABLED == STD_OFF)
#define DEM_EVENT_STATUS(i)                    (Dem_StorageMem.EventEntry[i].EventStatus)
#else
#define DEM_EVENT_STATUS(i)                    (DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(i)))
#endif
#define DEM_EVENT_FIRST_FAILED                 (Dem_StorageMem.EventHead.FirstFailedEvent)
#define DEM_EVENT_RECENT_FAILED                (Dem_StorageMem.EventHead.MostRecentFailedEvent)
#define DEM_EVENT_FIRST_CONFIRMED              (Dem_StorageMem.EventHead.FirstConfirmedEvent)
#define DEM_EVENT_RECENT_CONFIRMED             (Dem_StorageMem.EventHead.MostRecentConfirmedEvent)
#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
#define DEM_EVEVT_PRESTO_FF_ENTRY(i)           (Dem_StorageMem.EventEntry[i].PreStorageFFEntryRef)
#endif

/*Client*/
#define DEM_CLIENT_EVENT_MEM(i)                (Dem_ClientTable[i].DemEventMemorySetRef)
#if(DEM_CORE_NUMBER > 1)
#define DEM_CLIENT_REF_CORE(i)                 (Dem_ClientTable[i].RefCoreId)
#endif

#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
/*Event Counter*/
#define DEM_EVENT_AGINGCNT(i)                  (Dem_StorageMem.EventEntry[i].EventAgingCounter)
#define DEM_EVENT_DATAENTRYREF(i)              (Dem_StorageMem.EventEntry[i].DataEntryRef)
#endif
#define DEM_EVENT_FCC(i)                       (Dem_StorageMem.EventEntry[i].EventFaultConfCnt)
#if(DEM_NUM_OF_INDICATOR > 0)
#define DEM_EVENT_IFCC(i)                      (Dem_StorageMem.EventEntry[i].IndicatorFailureCycleCounter)
#define DEM_EVENT_IHCC(i)                      (Dem_StorageMem.EventEntry[i].IndicatorHealingCycleCounter)
#endif
#define DEM_EVENT_OCCCTR(i)                    (Dem_StorageMem.EventEntry[i].EventOccurrence)
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
#if(DEM_DEBOUNCE_COUNTER_STORAGE_SUPPORT == STD_ON)
#define DEM_EVENT_DBC(i)                       (Dem_StorageMem.EventEntry[i].EventDebounceCnt)
#else
#define DEM_EVENT_DBC(i)                       (Dem_EventDebounceCounter[i])
#endif
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
#define DEM_EVENT_DBT(i)                       (Dem_EventDebounceTimer[i].EventDebounceTimer)
#define DEM_EVENT_TIMERDIRECTION(i)            (Dem_EventDebounceTimer[i].TimerDirection)
#endif

#if(DEM_EVENT_MAXFDCDCC_SUPPORT == STD_ON)
#define DEM_EVENT_MAXFDCDCC(i)                 (Dem_StorageMem.EventEntry[i].EventMaxFdcDuringCurrentCycle)
#endif
#if(DEM_EVENT_MAXFDCSLC_SUPPORT == STD_ON)
#define DEM_EVENT_MAXFDCSLC(i)                 (Dem_StorageMem.EventEntry[i].EventMaxFdcSinceLastClear)
#endif
#if(DEM_EVENT_CSLF_SUPPORT == STD_ON)
#define DEM_EVENT_CSLF(i)                      (Dem_StorageMem.EventEntry[i].EventCyclesSinceLastFailed)
#endif
#if(DEM_EVENT_CSFF_SUPPORT == STD_ON)
#define DEM_EVENT_CSFF(i)                      (Dem_StorageMem.EventEntry[i].EventCyclesSinceFirstFailed)
#endif
#if(DEM_EVENT_FCSLC_SUPPORT == STD_ON)
#define DEM_EVENT_FCSLC(i)                     (Dem_StorageMem.EventEntry[i].EventFailedCyclesSinceLastCleared)
#endif
#if(DEM_MONITORDATA_SUPPORT == STD_ON)
#define DEM_EVENT_MONITOR_DATA_0(i)            (Dem_StorageMem.EventEntry[i].MonitorData_0)
#define DEM_EVENT_MONITOR_DATA_1(i)            (Dem_StorageMem.EventEntry[i].MonitorData_1)
#endif
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#define DEM_EVENT_OBD_PCSLF(i)                 (Dem_StorageMem.EventEntry[i].EventOBDPassedCyclesSinceLastFailed)
#endif
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
#define DEM_EVENT_OBD_CLEAR_FLAG(i)            (Dem_StorageMem.EventEntry[i].EventClearFlagForPermanent)
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
#define DEM_EVENT_CMA_STATUS(i)                (Dem_StorageMem.EventEntry[i].EventCMAStatus)
#define DEM_EVENT_CMA_PCSLF(i)                 (Dem_StorageMem.EventEntry[i].EventPassedCyclesSinceLastFailed)
#endif

/*PreStoreFF*/
#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
#define DEM_PRESTORE_FFENTRY(i)                (Dem_StorageMem.PreStorageEntry[i])
#define DEM_PRESTORE_FFENTRY_USED(i)           (DEM_PRESTORE_FFENTRY(i).Used)
#define DEM_PRESTORE_FFENTRY_EVENTID(i)        (DEM_PRESTORE_FFENTRY(i).EventId)
#endif



/*Indicator*/
#if(DEM_NUM_OF_INDICATOR > 0)
#define DEM_INDICATOR_STATUS(i)                (Dem_StorageMem.IndicatorStatus[i])
#endif
/*DTC*/
#define DEM_DTC_STATUS(i)                      (Dem_StorageMem.DtcEntry[i].DtcStatus)
#if(DEM_DTC_LASTSTATUS_SUPPORT == STD_ON)
#define DEM_DTC_LASTSTATUS(i)                  (Dem_StorageMem.DtcEntry[i].DtcLastStatus)
#endif
#define DEM_DTC_AGINGCNT(i)                    (Dem_StorageMem.DtcEntry[i].DtcAgingCounter)
#if(DEM_DTC_AGEDCNT_SUPPORT == STD_ON)
#define DEM_DTC_AGEDCNT(i)                     (Dem_StorageMem.DtcEntry[i].DtcAgedCounter)
#endif
#define DEM_DTC_DATAENTRYREF(i)                (Dem_StorageMem.DtcEntry[i].DataEntryRef)
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
#define DEM_DTC_DATAENTRYREF_NUM(i)            (Dem_StorageMem.DtcEntry[i].DataEntryRefNum)
#endif
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
#define DEM_IS_COMBINEDDTC(i)                  ((DEM_CFG_DTCTABLE[i].DTCCombined) != FALSE)
#define DEM_CFG_DTC_COMBINEDNUM(i)             (DEM_CFG_DTCTABLE[i].CombinedEventNum)
#define DEM_CFG_DTC_COMBINED_EVENTID(i,j)      (DEM_CFG_DTCTABLE[i].CombinedEventId[j])
#endif
/*EventMemorySet*/
#define DEM_GET_EVENTMEMORY_ID(i)              ((uint8)(i >> (uint8)8))
#define DEM_GET_SUBMEMORY_ID(i)                ((uint8)(i & DEM_DATA_U8_FF))
#define DEM_CFG_CLEAR_DTC_NOTIFICATION_FUN(i)  (Dem_EventMemorySetTable[i].ClearDtcNotificationFnc)
#define DEM_CFG_CLEAR_DTC_NOTIFICATION_TIME(i) (Dem_EventMemorySetTable[i].ClearDtcNotificationTime)

/*primary Memory*/
#define DEM_CFG_PRIMARY_ENTRY_BLOCKID(i,j)     (Dem_PrimaryMemoryTable[i][j].DemBlockId)
#define DEM_CFG_PRIMARY_ENTRY(i,j)             (Dem_PrimaryMemoryTable[i][j].DTCDataEntryPtr)
#define DEM_PRIMARY_DATAENTRY_USEDNUM(i)       (Dem_StorageMem.PrimaryDataEntryUsedNum[i])
#define DEM_PRIMARY_DATAENTRY_USED(i,j)        (Dem_PrimaryMemoryTable[i][j].DTCDataEntryPtr->Used)
#define DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY(i) (Dem_PrimaryMemoryParameter[i].MaxNumberEventEntry)
#define DEM_CFG_DTCSTATU_MASK_PRIMARY(i)       (Dem_PrimaryMemoryParameter[i].DemDtcStatusAvailabilityMask)
#define DEM_CFG_PRIMARY_EVENTMEMORYTRIGGER(i)  (Dem_PrimaryMemoryParameter[i].EventMemoryEntryStorageTrigger)
#define DEM_CFG_PRIMARY_EVENTDISPLACEMENTSTRATEGY(i) (Dem_PrimaryMemoryParameter[i].EventDisplacementStrategy)
#define DEM_CFG_PRIMARY_OCCURRENCECOUNTERPROCESSING(i) (Dem_PrimaryMemoryParameter[i].OccurrenceCounterProcessing)
#define DEM_CFG_PRIMARY_TYPE_OF_FF_RECORD_NUMERATION(i) (Dem_PrimaryMemoryParameter[i].TypeOfFreezeFrameRecordNumeration)
/*User define Memory*/
#if(DEM_NUM_OF_USERDEF > 0)
#define DEM_CFG_USERDEF_ENTRY_BLOCKID(i,j)           (Dem_UserDefinedMemTable[i][j].DemBlockId)
#define DEM_CFG_USERDEF_ENTRY(i,j)                   (Dem_UserDefinedMemTable[i][j].DTCDataEntryPtr)
#define DEM_USERDEFINED_DATAENTRY_USED(i,j)          (Dem_UserDefinedMemTable[i][j].DTCDataEntryPtr->Used)
#define DEM_USER_DEFINED_DATAENTRY_USEDNUM(i,j)      (Dem_StorageMem.UserDefinedEntryUsedNum[i][j])
#define DEM_CFG_MAXNUMBEREVENTENTRY_USERDEFINED(i)   (Dem_UserDefinedParameter[i].MaxNumberEventEntry)
#define DEM_CFG_DTCSTATU_MASK_USERDEFINED(i)         (Dem_UserDefinedParameter[i].DemDtcStatusAvailabilityMask)
#define DEM_CFG_USERDEF_OCCURRENCECOUNTERPROCESSING(i) (Dem_UserDefinedParameter[i].OccurrenceCounterProcessing)
#define DEM_CFG_USERDEF_EVENTMEMORYTRIGGER(i)        (Dem_UserDefinedParameter[i].EventMemoryEntryStorageTrigger)
#define DEM_CFG_USERDEF_EVENTDISPLACEMENTSTRATEGY(i) (Dem_UserDefinedParameter[i].EventDisplacementStrategy)
#define DEM_CFG_USERDEF_TYPE_OF_FF_RECORD_NUMERATION(i) (Dem_UserDefinedParameter[i].TypeOfFreezeFrameRecordNumeration)
#define DEM_CFG_USERDEF_STARTNUM(i)                  (Dem_EventMemorySetTable[i].UserdefStart)
#define DEM_CFG_USERDEF_NUMBER(i)                    (Dem_EventMemorySetTable[i].UserdefNum)
#endif

#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
#define DEM_EVCOMB_FDC(i)                      (Dem_StorageMem.DtcEntry[i].CbDTC_FDC)
#endif

#if(DEM_MAX_FFSIZE_OF_DTC > 0)
#define DEM_PRIMARY_FFDATA_PTR(i,j)            (Dem_PrimaryMemoryTable[i][j].DTCDataEntryPtr->FreezeFrameData)
#if(DEM_NUM_OF_USERDEF > 0)
#define DEM_USERDEFINED_FFDATA_PTR(i,j)        (Dem_UserDefinedMemTable[i][j].DTCDataEntryPtr->FreezeFrameData)
#endif
#endif
#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
#define DEM_PRIMARY_EXTDATA_PTR(i,j)           (Dem_PrimaryMemoryTable[i][j].DTCDataEntryPtr->ExtendedData)
#if(DEM_NUM_OF_USERDEF > 0)
#define DEM_USERDEFINED_EXTDATA_PTR(i,j)       (Dem_UserDefinedMemTable[i][j].DTCDataEntryPtr->ExtendedData)
#endif
#endif

#if(DEM_MAX_J1939FFSIZE_OF_DTC > 0)
#define DEM_PRIMARY_J1939DTC_FFDATA_PTR(i,j)            (Dem_PrimaryMemoryTable[i][j].DTCDataEntryPtr->J1939FreezeFrameData)
#if(DEM_NUM_OF_USERDEF > 0)
#define DEM_USERDEFINED_J1939DTC_FFDATA_PTR(i,j)        (Dem_UserDefinedMemTable[i][j].DTCDataEntryPtr->J1939FreezeFrameData)
#endif
#endif
#if(DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0)
#define DEM_PRIMARY_J1939DTC_EXPFFDATA_PTR(i,j)            (Dem_PrimaryMemoryTable[i][j].DTCDataEntryPtr->J1939ExpFreezeFrameData)
#if(DEM_NUM_OF_USERDEF > 0)
#define DEM_USERDEFINED_J1939DTC_EXPFFDATA_PTR(i,j)        (Dem_UserDefinedMemTable[i][j].DTCDataEntryPtr->J1939ExpFreezeFrameData)
#endif
#endif

/*MultiCore*/
#if(DEM_CORE_NUMBER > 1)
#define DEM_CFG_DATA_SPINLOCK_FLAG(i)          (Dem_DataElementUsed[i])
#define DEM_SERVICE_RESULT_NOTIFICATION(ServiceId, Id, Result)  Dem_ServiceResultNotification_Callout(ServiceId, Id, Result)
#endif


/*Report Event Queue*/

#define DEM_REPORT_BSW_EVENT_ID(i)             (Dem_BSWEventQueue.ReportEventId[i])
#define DEM_REPORT_BSW_EVENT_STATU(i)          (Dem_BSWEventQueue.ReportEventStatu[i])

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#define DEM_OBD_DATA_INFO                      (Dem_StorageMem.OBDDataInfo)
/*Used for PID01/41*/
#define DEM_OBD_READINESSGROUP_STATUS          (DEM_OBD_DATA_INFO.ReadinessGroupStatus)
/*Used for PID31.Unit:m, Range:0-65535000*/
#define DEM_OBD_DISTANCE_SINCEDTCCLEARED       (DEM_OBD_DATA_INFO.DistanceSinceDtcCleared)
#define DEM_OBD_DISTANCE_MILACTIVATED          (DEM_OBD_DATA_INFO.DistanceTraveledMILActivated)
#define DEM_OBD_ENGINERUN_MILACTIVATED         (DEM_OBD_DATA_INFO.EngineRunTimeMILActivated)
#define DEM_OBD_ENGINERUN_SINCEDTCCLEARED      (DEM_OBD_DATA_INFO.EngineRunTimeDtcCleared)
#define DEM_OBD_NUMWARMUP_SINCEDTCCLEARED      (DEM_OBD_DATA_INFO.NumberOfWarmSinceDtcCleared)
/*Data for Service 02*/
#define DEM_OBD_FF_EVENT                       (DEM_OBD_DATA_INFO.ObdEventId)
#define DEM_OBD_FF_DATA_BUF                    (DEM_OBD_DATA_INFO.ObdFreezeFrameData)
/*Data for Service 09*/
#if(DEM_NUM_OF_RATIO > 0)
#define DEM_OBD_RATIO_IGN_CNT                  (DEM_OBD_DATA_INFO.RatioIGNCycleCounter)
#define DEM_OBD_RATIO_GENDEN_CNT               (DEM_OBD_DATA_INFO.RatioGeneralDenominatorCounter)
#define DEM_OBD_RATIO_GENDEN_STATE             (DEM_OBD_DATA_INFO.RatioGeneralDenominatorState)
#define DEM_OBD_RATIO_DENOMCOND_STATUS(i)      (DEM_OBD_DATA_INFO.RatioDenomCondStatus[i])
#define DEM_OBD_RATIO_NUMERATOR(i)             (DEM_OBD_DATA_INFO.RatioNumerator[i])
#define DEM_OBD_RATIO_DENOMINATOR(i)           (DEM_OBD_DATA_INFO.RatioDenominator[i])
/*bit 0: Numerator increased flag;
  bit 1: Denominator increased flag;
  bit 2: Denominator lock flag.*/
#define DEM_OBD_RATIO_STATE(i)                 (DEM_OBD_DATA_INFO.RatioState[i])
#endif
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
#define DEM_OBD_PFC_CYCLE_STATUS               (DEM_OBD_DATA_INFO.PfcCycleStatus)
#endif

#if(DEM_MAX_NUM_OF_DTR > 0)
#define DEM_NUM_OF_DTR                         DEM_MAX_NUM_OF_DTR
#define DEM_OBD_AVAIL_PARA_LENGTH               (uint8)8
#define DEM_OBD_BIT_NUM_PER_4BYTE               (uint8)32
#define DEM_CFG_DTR_COMPUDENOMINATOR0(i)       (Dem_DtrTable[i].DemDtrCompuDenominator0)
#define DEM_CFG_DTR_COMPUNUMERATOR0(i)         (Dem_DtrTable[i].DemDtrCompuNumerator0)
#define DEM_CFG_DTR_COMPUNUMERATOR1(i)         (Dem_DtrTable[i].DemDtrCompuNumerator1)
#define DEM_CFG_DTR_EVENTREF(i)                (Dem_DtrTable[i].DemDtrEventRef)
#define DEM_CFG_DTR_MID(i)                     (Dem_DtrTable[i].DemDtrMid)
#define DEM_CFG_DTR_TID(i)                     (Dem_DtrTable[i].DemDtrTid)
#define DEM_CFG_DTR_UASID(i)                   (Dem_DtrTable[i].DemDtrUasid)
#define DEM_CFG_DTR_UPDATEKIND(i)              (Dem_DtrTable[i].DemDtrUpdateKind)
#define DEM_OBD_DTR_TESTRESULT(i)              (DEM_OBD_DATA_INFO.DtrInfo[i].TestResult)
#define DEM_OBD_DTR_UPPERLIMIT(i)              (DEM_OBD_DATA_INFO.DtrInfo[i].LowerLimit)
#define DEM_OBD_DTR_LOWERLIMIT(i)              (DEM_OBD_DATA_INFO.DtrInfo[i].UpperLimit)
#define DEM_OBD_DTR_AVAIL_DTR(Idx)             (Dem_OBD_AvailDTR[Idx])
#endif
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/


#define DEM_CFG_MILINDICATORREF(i)             (Dem_EventMemorySetTable[i].MILIndicatorRef)
#define DEM_CFG_RED_LAMP_REF(i)                (Dem_EventMemorySetTable[i].RedStopLampIndicatorRef)
#define DEM_CFG_PROTECT_LAMP_REF(i)            (Dem_EventMemorySetTable[i].ProtectLampIndicatorRef)
#define DEM_CFG_AMBER_LAMP_REF(i)              (Dem_EventMemorySetTable[i].AmberWarningLampIndicatorRef)


#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
#define DEM_PERMANENT_DATAENTRY_USEDNUM(i)       (Dem_StorageMem.PermanentEntryUsedNum[i])
#define DEM_PERMANENT_DATAENTRY_EVENTID(i,j)     (Dem_StorageMem.PermanentDataEntry[i][j])
#define DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT(i) (Dem_EventMemorySetTable[i].MaxNumberEventEntryPermanent)
#endif/*#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)*/


/*SWS_Dem_00415*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
#define DEM_EVENT_DBC_F_FDC(i)                 (sint8)(((sint32)DEM_EVENT_DBC(i)*(sint32)DEM_F_FDC_FACTOR)/((sint32)DEM_CFG_EVENT_DBC_FAILTHRESHOLD(i)))
#define DEM_EVENT_DBC_P_FDC(i)                 (sint8)(((sint32)DEM_EVENT_DBC(i)*(sint32)DEM_P_FDC_FACTOR)/(sint32)(0-DEM_CFG_EVENT_DBC_PASSTHRESHOLD(i)))
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
#define DEM_EVENT_DBT_F_FDC(i)                 (sint8)(((sint32)DEM_EVENT_DBT(i)*(sint32)DEM_F_FDC_FACTOR)/(sint32)(DEM_CFG_EVENT_DBT_FAILED(i)))
#define DEM_EVENT_DBT_P_FDC(i)                 (sint8)(((sint32)DEM_EVENT_DBT(i)*(sint32)DEM_P_FDC_FACTOR)/((sint32)0-(sint32)DEM_CFG_EVENT_DBT_PASSED(i)))
#endif


/*Operation Cycle*/
#define DEM_CFG_OPCYC_LEADING_REF(i)           (Dem_OperationCycleTable[i].DemLeadingRef)
#define DEM_CURRENT_OP_STATE(i)                (Dem_StorageMem.Dem_OpCycState[i])
/*#define DEM_CFG_OPCYC_AUTOSTART(i)             (Dem_OperationCycleTable[i].DemOperationCycleAutostart)
#define DEM_CFG_OPCYC_AUTOEND(i)               (Dem_OperationCycleTable[i].DemOperationCycleAutomaticEnd)
#define DEM_CFG_OPCYC_TYPE(i)                  (Dem_OperationCycleTable[i].DemOperationCycleType)*/

/*NvM BlockId*/
#define DEM_CFG_NVM_BLOCKID                    (Dem_NvRamBlockIdTable[0].DemNvRamBlockIdRef)

#if(DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#define DEM_NUM_OF_DTC                          DEM_MAXNUM_OF_DTC
#define DEM_NUM_OF_EVENT                        DEM_MAXNUM_OF_EVENT
#define DEM_CFG_EVENTTABLE                      Dem_EventTable
#define DEM_CFG_DTCTABLE                        Dem_DTCTable
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#define DEM_CFG_PIDTABLE                        Dem_PidTable
#define DEM_CFG_OBD_NUM_OF_PID                  DEM_CFG_OBD_MAXNUM_OF_PID
#endif
#else /*#if(DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)*/
#define DEM_NUM_OF_DTC                          Dem_ConfigPtr->NumOfDTC
#define DEM_NUM_OF_EVENT                        Dem_ConfigPtr->NumOfEvent
#define DEM_CFG_EVENTTABLE                      Dem_ConfigPtr->EventTable
#define DEM_CFG_DTCTABLE                        Dem_ConfigPtr->DTCTable
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#define DEM_CFG_PIDTABLE                        Dem_ConfigPtr->PidTable
#define DEM_CFG_OBD_NUM_OF_PID                  Dem_ConfigPtr->NumOfPid
#endif
#endif /*#if(DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)*/
/*Event*/
#define DEM_CFG_EVENT_DTCREF(i)                (DEM_CFG_EVENTTABLE[i].DemDTCRef)
#define DEM_CFG_EVENT_AVAILABLE(i)             (DEM_CFG_EVENTTABLE[i].DemEventAvailable)
#define DEM_CFG_EVENT_OPCYCREF(i)              (DEM_CFG_EVENTTABLE[i].DemOperationCycleRef)
#define DEM_CFG_EVENT_KIND(i)                  (DEM_CFG_EVENTTABLE[i].DemEventKind)
#define DEM_CFG_EVENT_REPBEHAVIOR(i)           (DEM_CFG_EVENTTABLE[i].DemReportBehavior)
#define DEM_CFG_EVENT_REPORTING_TYPE(i)        (DEM_CFG_EVENTTABLE[i].DemEventReportingType)
#define DEM_CFG_EVENT_PRESTORAGE(i)            (DEM_CFG_EVENTTABLE[i].DemFFPrestorageSupported)
#define DEM_CFG_EVENT_TRANSLATION_TYPE(i)      (Dem_EventMemorySetTable[i].TypeOfDTCSupported)
#if(DEM_CORE_NUMBER > 1)
#define DEM_CFG_EVENT_COREREF(i)               (DEM_CFG_EVENTTABLE[i].EventCoreRef)

#if(DEM_EVENT_CALLBACK_SUPPORT == STD_ON)
#define DEM_CFG_EVENT_CALLBACK(i)              (DEM_CFG_EVENTTABLE[i].CrossCoreTriggerInfo)
#if(DEM_INITMFORE_CALLBACK_SUPPORT == STD_ON)
#define DEM_CFG_EVENT_INITM_FLAG(i)            (DEM_CFG_EVENTTABLE[i].CrossCoreTriggerInfo->InitMforETrigger)
#define DEM_CFG_EVENT_INITM_REASON(i)          (DEM_CFG_EVENTTABLE[i].CrossCoreTriggerInfo->InitReason)
#endif

#if(DEM_MONITOR_CHANGE_CALLBACK_SUPPORT == STD_ON)
#define DEM_CFG_EVENT_MONITOR_STATUS_FLAG(i)   (DEM_CFG_EVENTTABLE[i].CrossCoreTriggerInfo->MonitorChangeTrigger)
#endif

#if(DEM_EVENT_STATUS_CHANGE_CALLBACK_SUPPORT == STD_ON)
#define DEM_CFG_EVENT_STATUS_CHANGE_FLAG(i)    (DEM_CFG_EVENTTABLE[i].CrossCoreTriggerInfo->EventStatuChangeTrigger)
#define DEM_CFG_EVENT_STATUS_OLDSTATUS(i)      (DEM_CFG_EVENTTABLE[i].CrossCoreTriggerInfo->EventOldStatus)
#define DEM_CFG_EVENT_STATUS_NEWSTATUS(i)      (DEM_CFG_EVENTTABLE[i].CrossCoreTriggerInfo->EventNewStatus)
#endif

#if(DEM_EVENT_DATA_CHANGE_CALLBACK_SUPPORT == STD_ON)
#define DEM_CFG_EVENT_DATA_CHANGE_FLAG(i)    (DEM_CFG_EVENTTABLE[i].CrossCoreTriggerInfo->EventDataChangeTrigger)
#endif

#if(DEM_CLEAR_EVENT_ALLOWED_CALLBACK_SUPPORT == STD_ON)
#define DEM_CFG_CLEAR_EVENT_ALLOWED_FLAG(i)    (DEM_CFG_EVENTTABLE[i].CrossCoreTriggerInfo->ClearEventAllowedTrigger)
#define DEM_CLEAR_EVENT_ALLOWED_RESULT(i)      (DEM_CFG_EVENTTABLE[i].CrossCoreTriggerInfo->ClearEventAllowedResult)
#endif
#endif
#define DEM_NUM_OF_CORE_EVENT(i)               (Dem_CrossCoreEventInfo[i].NumOfEvent)
#define DEM_GET_CORE_EVENT_ID(i,j)             (Dem_CrossCoreEventInfo[i].EventIdList[j])
#endif
#if(DEM_NUM_OF_EN_GROUP > 0)
#define DEM_CFG_EVENT_EN(i)                    (DEM_CFG_EVENTTABLE[i].DemEnableConditionGroupRef)
#define DEM_CFG_EVENT_EN_NUM(i)                (DEM_CFG_EVENTTABLE[i].DemEnableConditionGroupRef->Number)
#define DEM_CFG_EVENT_EN_REF(i)                (DEM_CFG_EVENTTABLE[i].DemEnableConditionGroupRef->DemEnableConditionRef)
#endif
#if(DEM_NUM_OF_STOR_GROUP > 0)
#define DEM_CFG_EVENT_STOR(i)                  (DEM_CFG_EVENTTABLE[i].DemStorageConditionGroupRef)
#define DEM_CFG_EVENT_STOR_NUM(i)              (DEM_CFG_EVENTTABLE[i].DemStorageConditionGroupRef->Number)
#define DEM_CFG_EVENT_STOR_REF(i)              (DEM_CFG_EVENTTABLE[i].DemStorageConditionGroupRef->DemStorageConditionRef)
#endif
#if(DEM_NUM_OF_INDICATOR > 0)
#define DEM_CFG_EVENT_INDICATOR_NUM(i)         (DEM_CFG_EVENTTABLE[i].NumOfIndicator)
#define DEM_CFG_EVENT_INDICATOR(i)             (DEM_CFG_EVENTTABLE[i].DemIndicatorAttribute)
#define DEM_CFG_EVENT_INDICATOR_BEHAVIOUR(i,j) (DEM_CFG_EVENTTABLE[i].DemIndicatorAttribute[j].DemIndicatorBehaviour)
#define DEM_CFG_EVENT_INDICATOR_F_THRESHOLD(i,j) \
    (DEM_CFG_EVENTTABLE[i].DemIndicatorAttribute[j].DemIndicatorFailureCycleCounterThreshold)
#define DEM_CFG_EVENT_INDICATOR_H_THRESHOLD(i,j) \
    (DEM_CFG_EVENTTABLE[i].DemIndicatorAttribute[j].DemIndicatorHealingCycleCounterThreshold)
#define DEM_CFG_EVENT_INDICATOR_ID(i,j)        (DEM_CFG_EVENTTABLE[i].DemIndicatorAttribute[j].DemIndicatorID)
#define DEM_CFG_EVENT_INDICATOR_OFFSET(i,j)    (DEM_CFG_EVENTTABLE[i].DemIndicatorAttribute[j].DemIndicatorStatusPosOffset)
#endif/*#if(DEM_NUM_OF_INDICATOR > 0)*/

#define DEM_CFG_EVENT_CONFIRMATIONTHRESHOLD(i) (DEM_CFG_EVENTTABLE[i].DemEventConfirmationThreshold)
#define DEM_CFG_EVENT_CLEARALLOWED_BEHAVIOR(i) (DEM_CFG_EVENTTABLE[i].DemCallbackClearEventAllowed.DemClearEventAllowedBehavior)
#define DEM_CFG_EVENT_CLEARALLOWED_CALLFNC(i)  (DEM_CFG_EVENTTABLE[i].DemCallbackClearEventAllowed.DemCallbackClearEventAllowedFnc)
#define DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(i) (DEM_CFG_EVENTTABLE[i].DemCallbackEventStatusChangedFnc)
#define DEM_CFG_EVENT_DATACHANGED_CALLFNC(i)   (DEM_CFG_EVENTTABLE[i].DemCallbackEventDataChangedFnc)
#define DEM_CFG_EVENT_INITM_CALLFNC(i)         (DEM_CFG_EVENTTABLE[i].DemCallbackInitMForEFnc)
#define DEM_CFG_MONITOR_STATUSCHANGED_CALLFNC(i) (DEM_CFG_EVENTTABLE[i].DemCallbackMonitorStatusChangedFnc)


#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
#define DEM_CFG_EVENT_DBC(i)                   \
    (DEM_CFG_EVENTTABLE[i].DemDebounceAlgorithmClass.DemDebounceCounterBasedClassRef)
#define DEM_CFG_EVENT_DBC_BEHAVIOR(i)          \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceBehavior)
#define DEM_CFG_EVENT_DBC_FAILTHRESHOLD(i)     \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterFailedThreshold)
#define DEM_CFG_EVENT_DBC_JUMPUP(i)            \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterJumpUp)
#define DEM_CFG_EVENT_DBC_JUMPUP_VALUE(i)      \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterJumpUpValue)
#define DEM_CFG_EVENT_DBC_INCREMENT_SIZE(i)    \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterIncrementStepSize)
#define DEM_CFG_EVENT_DBC_PASSTHRESHOLD(i)     \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterPassedThreshold)
#define DEM_CFG_EVENT_DBC_JUMPDOWN(i)          \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterJumpDown)
#define DEM_CFG_EVENT_DBC_JUMPDOWN_VALUE(i)    \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterJumpDownValue)
#define DEM_CFG_EVENT_DBC_DECREMENT_SIZE(i)    \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterDecrementStepSize)
#define DEM_CFG_EVENT_DBC_STORAGE(i)           \
    (DEM_CFG_EVENT_DBC(i)->DemDebounceCounterStorage)
#if(DEM_FDC_STORAGE_SUPPORT == STD_ON)
#define DEM_CFG_COUNTER_FDC_THRESHLD(i)            \
    (DEM_CFG_EVENT_DBC(i)->CounterBasedFdcThresholdStorageValue)
#endif
#endif

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
#define DEM_CFG_EVENT_DBT(i)                   \
    (DEM_CFG_EVENTTABLE[i].DemDebounceAlgorithmClass.DemDebounceTimeBaseRef)
#define DEM_CFG_EVENT_DBT_FAILED(i)            \
    ((DEM_CFG_EVENT_DBT(i)->DemDebounceTimeFailedThreshold)/DEM_TASK_TIME)
#define DEM_CFG_EVENT_DBT_PASSED(i)            \
    ((DEM_CFG_EVENT_DBT(i)->DemDebounceTimePassedThreshold)/DEM_TASK_TIME)
#define DEM_CFG_EVENT_DBT_BAHAVIOR(i)          \
    (DEM_CFG_EVENT_DBT(i)->DemDebounceBehavior)
#if(DEM_FDC_STORAGE_SUPPORT == STD_ON)
#define DEM_CFG_TIMER_FDC_THRESHLD(i)            \
    ((DEM_CFG_EVENT_DBT(i)->TimeBasedFdcThresholdStorageValue)/DEM_TASK_TIME)
#endif
#endif

#define DEM_CFG_EVENT_GET_FDC_FNC(i)           \
    (DEM_CFG_EVENTTABLE[i].DemDebounceAlgorithmClass.DemCallbackGetFDCFnc)

/*DTC StatusChangedNotification*/
#define DEM_CFG_DTC_STATUSCHANGED_CALLFNC(i)   (Dem_ClientTable[i].DTCStatusChangedNotificationFnc)

#if(DEM_NUM_OF_DTCGROUP > 0)
/*DTC groups*/
#define DEM_NUM_OF_DTCGROUP_MEMORY(i)            (Dem_EventMemorySetTable[i].NumOfDTCGroup)
#define DEM_CFG_DTC_GROUPVALUE(i,j)              (Dem_EventMemorySetTable[i].DTCGroup[j].DTCGroupValue)
#define DEM_CFG_GROUP_MEMORY_REF(i,j)            (Dem_EventMemorySetTable[i].DTCGroup[j].DTCGroupMemory)
#endif
/*DTCs*/
#define DEM_CFG_DTC_VALUE(i)                   (DEM_CFG_DTCTABLE[i].DemDtcValue)
#define DEM_CFG_DTC_EVENTREF(i)                (DEM_CFG_DTCTABLE[i].RefEventId)
#define DEM_CFG_DTC_SEVERITY(i)                (DEM_CFG_DTCTABLE[i].DemDTCSeverity)
#define DEM_CFG_DTC_FNCUNIT(i)                 (DEM_CFG_DTCTABLE[i].DemDTCFunctionalUnit)
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)||(DEM_J1939_SUPPORT == STD_ON))
#define DEM_CFG_DTC_OBDDTCREF(i)               (DEM_CFG_DTCTABLE[i].DemObdDTCRef)

#if(DEM_CFG_PTO_SUPPORT == STD_ON)
#define DEM_CFG_DTC_OBD_CON_PTO(i)             (DEM_CFG_DTC_OBDDTCREF(i)->DemConsiderPtoStatus)
#endif

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#define DEM_CFG_DTC_OBD_VALUE(i)               (DEM_CFG_DTC_OBDDTCREF(i)->DemDtcValue)
#define DEM_CFG_DTC_OBDDTCCLASS(i)             (DEM_CFG_DTCTABLE[i].DemWWHOBDDTCClass)

#define DEM_DTC_IS_OBD(i)                      \
    ((DEM_CFG_DTC_OBDDTCREF(i) != NULL_PTR) && (DEM_CFG_DTC_OBD_VALUE(i) != 0))
#endif

#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
#define DEM_CFG_DTC_OBD_READINESSGROUP(i)      (DEM_CFG_DTC_OBDDTCREF(i)->DemEventOBDReadinessGroup)
#endif

#if(DEM_J1939_SUPPORT == STD_ON)
#define DEM_CFG_DTC_J1939_VALUE(i)             (DEM_CFG_DTC_OBDDTCREF(i)->DemJ1939DTCValue)
#endif
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)||(DEM_J1939_SUPPORT == STD_ON))*/

#define DEM_CFG_DTC_MEMORY_DESTINATION_REF(i)  \
    (Dem_DTCAttributesTable[DEM_CFG_DTCTABLE[i].DemDTCAttributesRef].DemMemoryDestinationRef)
/*#define DEM_CFG_DTC_AGING_ALLOWED(i)           \
    (Dem_DTCAttributesTable[DEM_CFG_DTCTABLE[i].DemDTCAttributesRef].DemAgingAllowed)*/
#define DEM_CFG_DTC_AGINGCYCREF(i)             \
    (Dem_DTCAttributesTable[DEM_CFG_DTCTABLE[i].DemDTCAttributesRef].DemAgingCycleRef)
#define DEM_CFG_AGINGCYCLECOUNTERTHRESHOLD(i)  \
    (Dem_DTCAttributesTable[DEM_CFG_DTCTABLE[i].DemDTCAttributesRef].DemAgingCycleCounterThreshold)
#define DEM_CFG_DTC_SIGNIFICANCE(i)            \
    (Dem_DTCAttributesTable[DEM_CFG_DTCTABLE[i].DemDTCAttributesRef].DemDTCSignificance)
#define DEM_CFG_DTC_PRIORITY(i)                \
    (Dem_DTCAttributesTable[DEM_CFG_DTCTABLE[i].DemDTCAttributesRef].DemDTCPriority)
#define DEM_CFG_DTC_MAXNUMFFREC(i)                \
    (Dem_DTCAttributesTable[DEM_CFG_DTCTABLE[i].DemDTCAttributesRef].DemMaxNumberFreezeFrameRecords)




#if(DEM_NUM_OF_EXTDATACLASS > 0)
/*ExtendedData*/
#define DEM_CFG_DTC_EXTDATACLASSREF(i)         \
    (Dem_DTCAttributesTable[DEM_CFG_DTCTABLE[i].DemDTCAttributesRef].DemExtendedDataClassRef)
#define DEM_CFG_DTC_NUM_OF_EXTREC(i)           \
    (Dem_ExtDataClassTable[*DEM_CFG_DTC_EXTDATACLASSREF(i)].Number)
#define DEM_CFG_DTC_EXTREC_ARRAY(i)            \
    (Dem_ExtDataClassTable[*DEM_CFG_DTC_EXTDATACLASSREF(i)].DemExtendedDataRecordClassRef)
#define DEM_CFG_DTC_EXTRECNUM(i)               \
    (Dem_ExtDataRecClassTable[i].DemExtendedDataRecordNumber)
#define DEM_CFG_DTC_EXTREC_UPDATA(i)           \
    (Dem_ExtDataRecClassTable[i].DemExtendedDataRecordUpdate)
#define DEM_CFG_DTC_EXTREC_TRIGGER(i)          \
    (Dem_ExtDataRecClassTable[i].DemExtendedDataRecordTrigger)
#define DEM_CFG_NUMDATA_OF_EXTRECNUM(i)        \
    (Dem_ExtDataRecClassTable[i].Number)
#define DEM_CFG_DATAARRAY_OF_EXTRECNUM(i)      \
    (Dem_ExtDataRecClassTable[i].DemDataElementClassRef)
#endif

#if(DEM_NUM_OF_FFCLASS > 0)
#define DEM_CFG_DTC_FFCLASSREF(i)        \
    (Dem_DTCAttributesTable[DEM_CFG_DTCTABLE[i].DemDTCAttributesRef].DemFreezeFrameClassRef)
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
#define DEM_CFG_NUMDID_OF_FFNUM(i)          \
    (Dem_FFClassTable[i].Number)
#define DEM_CFG_DIDARRAY_OF_FFNUM(i)        \
    (Dem_FFClassTable[i].DemDidClassRef)
#endif
#endif

#if((DEM_NUM_OF_FFCLASS > 0)||(DEM_NUM_OF_FFRECCLASS > 0))

#define DEM_CFG_DID(i)                         \
    (Dem_DidClassTable[i].DemDidIdentifier)
#define DEM_CFG_NUMDATA_OF_DID(i)              \
    (Dem_DidClassTable[i].Number)
#define DEM_CFG_DATAARRAY_OF_DID(i)            \
    (Dem_DidClassTable[i].DemDidDataElementClassRef)

#endif
#if(DEM_NUM_OF_FFRECCLASS > 0)
/*FreezeFrameData*/
#define DEM_CFG_DTC_FFRECNUMCLASSREF(i)        \
    (Dem_DTCAttributesTable[DEM_CFG_DTCTABLE[i].DemDTCAttributesRef].DemFreezeFrameRecNumClassRef)
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
#define DEM_CFG_DTC_NUM_OF_FFREC(i)            \
    (Dem_FFRecNumClassTable[*DEM_CFG_DTC_FFRECNUMCLASSREF(i)].Number)
#define DEM_CFG_DTC_FFREC_ARRAY(i)             \
    (Dem_FFRecNumClassTable[*DEM_CFG_DTC_FFRECNUMCLASSREF(i)].DemFreezeFrameRecordClassRef)
#define DEM_CFG_DTC_FFRECNUM(i)                \
    (Dem_FFRecClassTable[i].DemFreezeFrameRecordNumber)
#define DEM_CFG_DTC_FFREC_UPDATA(i)            \
    (Dem_FFRecClassTable[i].DemFreezeFrameRecordUpdate)
#define DEM_CFG_DTC_FFREC_TRIGGER(i)           \
    (Dem_FFRecClassTable[i].DemFreezeFrameRecordTrigger)
#define DEM_CFG_NUMDID_OF_FFRECNUM(i)          \
    (Dem_FFRecClassTable[i].Number)
#define DEM_CFG_DIDARRAY_OF_FFRECNUM(i)        \
    (Dem_FFRecClassTable[i].DemDidClassRef)
#endif

#endif

#if(DEM_NUM_OF_DATA > 0)
/*DataElement*/
#define DEM_CFG_DATA_IN_DATA(i)                \
    (Dem_DataElementClassTable[i].DemInternalDataElementClass)
#define DEM_CFG_DATA_IN_DATA_SIZE(i)           \
    (DEM_CFG_DATA_IN_DATA(i)->DemDataElementDataSize)
#define DEM_CFG_DATA_IN_DATA_TYPE(i)           \
    (DEM_CFG_DATA_IN_DATA(i)->DemInternalDataElement)
#define DEM_CFG_DATA_CS_DATA(i)                \
    (Dem_DataElementClassTable[i].DemExternalCSDataElementClass)
#define DEM_CFG_DATA_CS_DATA_SIZE(i)           \
    (DEM_CFG_DATA_CS_DATA(i)->DemDataElementDataSize)
#define DEM_CFG_DATA_CS_DATA_READ_FNC(i)       \
    (DEM_CFG_DATA_CS_DATA(i)->DemDataElementReadFnc)
#if(DEM_CORE_NUMBER > 1)
#define DEM_CFG_DATA_CS_DATA_COREID(i)           \
    (DEM_CFG_DATA_CS_DATA(i)->CoreId)
#define DEM_CFG_DATA_CS_DATA_BUFFER(i)           \
    (DEM_CFG_DATA_CS_DATA(i)->DemDataElementDataBuff)
#endif
#endif

/*Enable condition*/
#if(DEM_NUM_OF_EN_CONDITION > 0)
#define DEM_CFG_EN_CONDITION_STATUS(i)         \
    (Dem_EnConditionTable[i].DemEnableConditionStatus)
#endif
/*Enable condition*/
#if(DEM_NUM_OF_STOR_CONDITION > 0)
#define DEM_CFG_STOR_CONDITION_STATUS(i)       \
    (Dem_StorageConditionTable[i].DemStorageConditionStatus)
#endif

/*Indicator*/
#if(DEM_NUM_OF_INDICATOR > 0)
#define DEM_CFG_INDICATOR_STATUS_FNC(i)        \
    (Dem_IndicatorStatusIndex[i].DemCallbackIndicatorStatusNotifyFnc)
#define DEM_CFG_INDICATOR_STATUS_START(i)      \
    (Dem_IndicatorStatusIndex[i].IndicatorStatusStartOffset)
#define DEM_CFG_INDICATOR_STATUS_NUM(i)        \
    (Dem_IndicatorStatusIndex[i].NumOfReferencedEvent)
#endif/*#if(DEM_NUM_OF_INDICATOR > 0)*/


#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
/*DemRatio*/
#if(DEM_NUM_OF_RATIO > 0)
#define DEM_CFG_RATIO_EVENTREF(i)              (Dem_RatioTable[i].DemDiagnosticEventRef)
#define DEM_CFG_RATIO_IUMPR(i)                 (Dem_RatioTable[i].DemIUMPRGroup)
#define DEM_CFG_RATIO_IUMPR_DEN(i)             (Dem_RatioTable[i].DemIUMPRDenGroup)
#define DEM_CFG_RATIO_KIND(i)                  (Dem_RatioTable[i].DemRatioKind)
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/

/*DemPidClass*/
#define DEM_CFG_PID_ID(i)                      (DEM_CFG_PIDTABLE[i].DemPidIdentifier)
#define DEM_CFG_PID_NUM_OF_DATA(i)             (DEM_CFG_PIDTABLE[i].NumOfData)
#define DEM_CFG_PID_DATA_CLASS(i)              (DEM_CFG_PIDTABLE[i].DemPidDataElementClassRef)
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/

#if(STD_ON == DEM_CFG_J1939_FF_SUPPORT)
#define DEM_CFG_J1939DTC_FFRECNUMCLASSREF(i)        \
    (Dem_DTCAttributesTable[DEM_CFG_DTCTABLE[i].DemDTCAttributesRef].DemJ1939FreezeFrameClassRef)
#define DEM_CFG_J1939DTC_NUM_OF_FFSPNC(i)            \
    (DEM_CFG_J1939DTC_FFRECNUMCLASSREF(i)->Number)
#define DEM_CFG_J1939DTC_FFSPNC_ARRAY(i)             \
    (DEM_CFG_J1939DTC_FFRECNUMCLASSREF(i)->DemSPNClassRef)
#endif

#if((STD_ON == DEM_CFG_J1939_FF_SUPPORT)||(STD_ON == DEM_CFG_J1939EX_FF_SUPPORT))
#define DEM_CFG_DATAARRAY_OF_FFSPN(i)            \
    (Dem_SPNClassTable[i].DemSPNDataElementClassRef)
#define DEM_CFG_SPNID_OF_FFSPNC(i)\
    (Dem_SPNClassTable[i].DemSPNId)
#endif

#if(STD_ON == DEM_CFG_J1939EX_FF_SUPPORT)
#define DEM_CFG_1939DTC_EXPFFRECNUMCLASSREF(i)        \
    (Dem_DTCAttributesTable[DEM_CFG_DTCTABLE[i].DemDTCAttributesRef].DemJ1939ExpandedFreezeFrameClassRef)
#define DEM_CFG_J1939DTC_NUM_OF_EXPFFSPNC(i)            \
    (DEM_CFG_1939DTC_EXPFFRECNUMCLASSREF(i)->Number)
#define DEM_CFG_J1939DTC_EXPFFSPNC_ARRAY(i)             \
    (DEM_CFG_1939DTC_EXPFFRECNUMCLASSREF(i)->DemSPNClassRef)
#endif


/* Status bit0 testFailed  */
#define DEM_TEST_UDS_STATUS_TF(Status)              ((Status & DEM_UDS_STATUS_TF) != 0)
#define DEM_SET_UDS_STATUS_TF(Status)               (Status | DEM_UDS_STATUS_TF)
#define DEM_CLEAR_UDS_STATUS_TF(Status)             (Status & (~DEM_UDS_STATUS_TF))

/* Status bit1 testFailedThisOperationCycle */
#define DEM_TEST_UDS_STATUS_TFTOC(Status)           ((Status & DEM_UDS_STATUS_TFTOC) != 0)
#define DEM_SET_UDS_STATUS_TFTOC(Status)            (Status | DEM_UDS_STATUS_TFTOC)
#define DEM_CLEAR_UDS_STATUS_TFTOC(Status)          (Status & (~DEM_UDS_STATUS_TFTOC))

/* Status bit2 pendingDTC */
#define DEM_TEST_UDS_STATUS_PDTC(Status)            ((Status & DEM_UDS_STATUS_PDTC) != 0)
#define DEM_SET_UDS_STATUS_PDTC(Status)             (Status | DEM_UDS_STATUS_PDTC)
#define DEM_CLEAR_UDS_STATUS_PDTC(Status)           (Status & (~DEM_UDS_STATUS_PDTC))

/* Status bit3 confirmedDTC */
#define DEM_TEST_UDS_STATUS_CDTC(Status)            ((Status & DEM_UDS_STATUS_CDTC) != 0)
#define DEM_SET_UDS_STATUS_CDTC(Status)             (Status | DEM_UDS_STATUS_CDTC)
#define DEM_CLEAR_UDS_STATUS_CDTC(Status)           (Status & (~DEM_UDS_STATUS_CDTC))

/* Status bit4 testNotCompletedSinceLastClear*/
#define DEM_TEST_UDS_STATUS_TNCSLC(Status)          ((Status & DEM_UDS_STATUS_TNCSLC) != 0)
#define DEM_SET_UDS_STATUS_TNCSLC(Status)           (Status | DEM_UDS_STATUS_TNCSLC)
#define DEM_CLEAR_UDS_STATUS_TNCSLC(Status)         (Status & (~DEM_UDS_STATUS_TNCSLC))

/* Status bit5 testFailedSinceLastClear */
#define DEM_TEST_UDS_STATUS_TFSLC(Status)           ((Status & DEM_UDS_STATUS_TFSLC) != 0)
#define DEM_SET_UDS_STATUS_TFSLC(Status)            (Status | DEM_UDS_STATUS_TFSLC)
#define DEM_CLEAR_UDS_STATUS_TFSLC(Status)          (Status & (~DEM_UDS_STATUS_TFSLC))


/* Status bit6 testNotCompletedThisOperationCycle*/
#define DEM_TEST_UDS_STATUS_TNCTOC(Status)          ((Status & DEM_UDS_STATUS_TNCTOC) != 0)
#define DEM_SET_UDS_STATUS_TNCTOC(Status)           (Status | DEM_UDS_STATUS_TNCTOC)
#define DEM_SET_MONITOR_STATUS_TNCTOC(Status)       (Status | DEM_MONITOR_STATUS_TNCTOC)
#define DEM_CLEAR_UDS_STATUS_TNCTOC(Status)         (Status & (~DEM_UDS_STATUS_TNCTOC))
#define DEM_CLEAR_MONITOR_STATUS_TNCTOC(Status)     (Status & (~DEM_MONITOR_STATUS_TNCTOC))

/* Status bit7 warningIndicatorRequested */
#define DEM_TEST_UDS_STATUS_WIR(Status)             ((Status & DEM_UDS_STATUS_WIR) != 0)
#define DEM_SET_UDS_STATUS_WIR(Status)              (Status | DEM_UDS_STATUS_WIR)
#define DEM_CLEAR_UDS_STATUS_WIR(Status)            (Status & (~DEM_UDS_STATUS_WIR))

#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
/*Status bit0 UnconfirmedDTC*/
#define DEM_TEST_CMA_STATUS_UDTC(Status)            ((Status & DEM_UDS_STATUS_TF) != 0)
#define DEM_SET_CMA_STATUS_UDTC(Status)             (Status | DEM_UDS_STATUS_TF)
#define DEM_CLEAR_CMA_STATUS_UDTC(Status)           (Status & (~DEM_UDS_STATUS_TF))
/*Status bit1 UnconfirmedDTCThisOperationonCycle*/
#define DEM_TEST_CMA_STATUS_UDTCTOC(Status)         ((Status & DEM_UDS_STATUS_TFTOC) != 0)
#define DEM_SET_CMA_STATUS_UDTCTOC(Status)          (Status | DEM_UDS_STATUS_TFTOC)
#define DEM_CLEAR_CMA_STATUS_UDTCTOC(Status)        (Status & (~DEM_UDS_STATUS_TFTOC))
/*Status bit2 UnconfirmedDTCSinceLastClear*/
#define DEM_TEST_CMA_STATUS_UDTCSLC(Status)         ((Status & DEM_UDS_STATUS_PDTC) != 0)
#define DEM_SET_CMA_STATUS_UDTCSLC(Status)          (Status | DEM_UDS_STATUS_PDTC)
#define DEM_CLEAR_CMA_STATUS_UDTCSLC(Status)        (Status & (~DEM_UDS_STATUS_PDTC))
/*Status bit3 AgedDTC*/
#define DEM_TEST_CMA_STATUS_ADTC(Status)            ((Status & DEM_UDS_STATUS_CDTC) != 0)
#define DEM_SET_CMA_STATUS_ADTC(Status)             (Status | DEM_UDS_STATUS_CDTC)
#define DEM_CLEAR_CMA_STATUS_ADTC(Status)           (Status & (~DEM_UDS_STATUS_CDTC))
/*Status bit4 SymptomSinceLastClear*/
#define DEM_TEST_CMA_STATUS_SSLC(Status)            ((Status & DEM_UDS_STATUS_TNCSLC) != 0)
#define DEM_SET_CMA_STATUS_SSLC(Status)             (Status | DEM_UDS_STATUS_TNCSLC)
#define DEM_CLEAR_CMA_STATUS_SSLC(Status)           (Status & (~DEM_UDS_STATUS_TNCSLC))
/*Status bit5 WarningIndicatorRequestedSinceLastClear*/
#define DEM_TEST_CMA_STATUS_WIRSLC(Status)          ((Status & DEM_UDS_STATUS_TFSLC) != 0)
#define DEM_SET_CMA_STATUS_WIRSLC(Status)           (Status | DEM_UDS_STATUS_TFSLC)
#define DEM_CLEAR_CMA_STATUS_WIRSLC(Status)         (Status & (~DEM_UDS_STATUS_TFSLC))
/*Status bit6 EmissionRelatedDTC*/
#define DEM_TEST_CMA_STATUS_ERDTC(Status)           ((Status & DEM_UDS_STATUS_TNCTOC) != 0)
#define DEM_SET_CMA_STATUS_ERDTC(Status)            (Status | DEM_UDS_STATUS_TNCTOC)
#define DEM_CLEAR_CMA_STATUS_ERDTC(Status)          (Status & (~DEM_UDS_STATUS_TNCTOC))
/*Status bit7 TestFailedSinceLastClear/Aged*/
#define DEM_TEST_CMA_STATUS_TFSLCA(Status)          ((Status & DEM_UDS_STATUS_WIR) != 0)
#define DEM_SET_CMA_STATUS_TFSLCA(Status)           (Status | DEM_UDS_STATUS_WIR)
#define DEM_CLEAR_CMA_STATUS_TFSLCA(Status)         (Status & (~DEM_UDS_STATUS_WIR))
#endif
/*******************************************************************************
*   typedef
*******************************************************************************/
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
typedef struct
{
    /*SWS_Dem_00426*/
    uint32 EventDebounceTimer;/*Debounce Timer*/
    Dem_EventStatusType TimerDirection;
} Dem_DebounceTimerType;
#endif

typedef struct
{
    uint16 ClearDTCNum;
    uint16 ClearBlockNum;
    uint16 ClearBlockIndex;
    uint16 ClearDTCFailedNum;
    uint8 ClearDTCTable[DEM_MAXNUM_OF_DTC];
    uint16 ClearBlockIdTable[DEM_MAXNUM_OF_DTC];
} Dem_ClearDTCInfoType;

typedef struct
{
    boolean FilteredValidFlag;
    Dem_UdsStatusByteType DTCStatusMask;
    Dem_DTCKindType DTCKind;
    Dem_DTCFormatType DTCFormat;
    Dem_DTCOriginType DTCOrigin;
    boolean FilterWithSeverity;
    boolean FilterForFDC;
    Dem_DTCSeverityType DTCSeverityMask;
    uint16 FilteredDTCIndexTable[DEM_MAXNUM_OF_DTC];
    uint16 NumberOfFilteredDTC;
    uint16 NextFilteredDTCIndex;
    uint16 NumberOfFreezeFrameRecord;
    Dem_FilterProcessType FilterProcess;
} Dem_DcmFilterInfoType;

#if(STD_ON == DEM_CFG_J1939READING_DTC_SUPPORT)
typedef struct
{
    boolean FilteredValidFlag;
    Dem_J1939DcmDTCStatusFilterType DTCStatusFilter;
    Dem_DTCKindType DTCKind;
    Dem_DTCOriginType DTCOrigin;
    Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind;
    uint16 FilteredDTCIndexTable[DEM_MAXNUM_OF_DTC];
    uint16 NumberOfFilteredDTC;
    uint16 NextFilteredDTCIndex;
} Dem_J1939DcmFilterInfoType;
#endif/*#if(STD_ON == DEM_CFG_J1939READING_DTC_SUPPORT)*/
#if((STD_ON == DEM_CFG_J1939EX_FF_SUPPORT)||(STD_ON == DEM_CFG_J1939_FF_SUPPORT))
typedef struct
{
    boolean FilteredValidFlag;
    Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind;
    uint16 FilteredDTCIndexTable[DEM_MAXNUM_OF_DTC];
    uint16 NumberOfFilteredDTC;
    uint16 NextFilteredDTCIndex;
} Dem_J1939DcmFilterFFType;
#endif
#if(STD_ON == DEM_CFG_J1939DM31_SUPPORT)
typedef struct
{
    boolean FilteredValidFlag;
    uint16 FilteredEventIndexTable[DEM_MAXNUM_OF_EVENT];
    uint16 NumberOfFilteredEvent;
    uint16 NextFilteredEventIndex;
} Dem_J1939DcmFilterDM31Type;
#endif


/*******************************************************************************
*   Vars
*******************************************************************************/
#define DEM_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "Dem_MemMap.h"

STATIC VAR(Dem_DcmFilterInfoType, DEM_VAR_NOINIT) Dem_DcmFilterInfo[DEM_NUM_OF_CLIENT];
#if((DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON) && (DEM_DEBOUNCE_COUNTER_STORAGE_SUPPORT == STD_OFF))
/*SWS_Dem_00414*/
STATIC VAR(sint16, DEM_VAR_NOINIT) Dem_EventDebounceCounter[DEM_MAXNUM_OF_EVENT];/*Debounce Counter*/
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
STATIC VAR(Dem_DebounceTimerType, DEM_VAR_NOINIT) Dem_EventDebounceTimer[DEM_MAXNUM_OF_EVENT];
#endif
#if(STD_ON == DEM_CFG_J1939READING_DTC_SUPPORT)
STATIC VAR(Dem_J1939DcmFilterInfoType, DEM_VAR_NOINIT) Dem_J1939DcmFilterInfo[DEM_NUM_OF_CLIENT];
#endif

#if((STD_ON == DEM_CFG_J1939EX_FF_SUPPORT)||(STD_ON == DEM_CFG_J1939_FF_SUPPORT))
STATIC VAR(Dem_J1939DcmFilterFFType, DEM_VAR_NOINIT) Dem_J1939DcmFilterFF[DEM_NUM_OF_CLIENT];
#endif
#if(STD_ON == DEM_CFG_J1939DM31_SUPPORT)
STATIC VAR(Dem_J1939DcmFilterDM31Type, DEM_VAR_NOINIT) Dem_J1939DcmFilterDM31[DEM_NUM_OF_CLIENT];
#endif

#define DEM_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "Dem_MemMap.h"

VAR(Dem_StorageMemType, DEM_VAR_NOINIT) Dem_StorageMem;
#if(DEM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
STATIC P2CONST(Dem_ConfigType, AUTOMATIC, DEM_VAR_NOINIT) Dem_ConfigPtr;
#endif

STATIC VAR(Dem_ClearDTCInfoType, DEM_VAR_NOINIT) Dem_ClearDTCInfo;

STATIC VAR(Dem_BSWEventQueueType, DEM_VAR_NOINIT) Dem_BSWEventQueue;

#define DEM_STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_INIT_LOCAL_8
#include "Dem_MemMap.h"
#if(DEM_CORE_NUMBER == 1)
STATIC VAR(uint8, DEM_VAR) Dem_SelectDTC_State = DEM_IN_SELECT_DTC_IDLE;
#endif

#if(DEM_CFG_BSWERRORBUFFERSIZE > 0)
STATIC VAR(uint8, DEM_VAR) Dem_ErrorBufferIndex = (uint8)0;
#endif

STATIC VAR(uint8, DEM_VAR) Dem_ClearDTCState = DEM_IN_CLEAR_DTC_IDLE;

#define DEM_STOP_SEC_VAR_INIT_LOCAL_8
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_INIT_GLOBAL_8
#include "Dem_MemMap.h"
STATIC VAR(Dem_StateType, DEM_VAR) Dem_State = DEM_UNINIT;

#define DEM_STOP_SEC_VAR_INIT_GLOBAL_8
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_INIT_LOCAL_16
#include "Dem_MemMap.h"

#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
STATIC VAR(uint16, DEM_VAR) Dem_ObdTimeSinceEngineStartLast = DEM_DATA_CLEAR;
STATIC VAR(uint16, DEM_VAR) Dem_ObdTimesOneSecond = DEM_DATA_CLEAR;
#endif

#define DEM_STOP_SEC_VAR_INIT_LOCAL_16
#include "Dem_MemMap.h"

#if(DEM_CORE_NUMBER > 1)
#define DEM_START_SEC_VAR_INIT_GLOBAL_32
#include "Dem_MemMap.h"

STATIC VAR(Bmc_SpinLockFlagType, DEM_VAR) Dem_DataElementUsed[DEM_NUM_OF_DATA] = {(Bmc_SpinLockFlagType)0};

#define DEM_STOP_SEC_VAR_INIT_GLOBAL_32
#include "Dem_MemMap.h"
#endif

#define DEM_START_SEC_VAR_CLEARED_LOCAL_8
#include "Dem_MemMap.h"

#if(DEM_CORE_NUMBER > 1)
STATIC VAR(uint8, DEM_VAR) Dem_SelectDTC_State[DEM_CORE_NUMBER];
#endif

STATIC VAR(Dem_OperationCycleStateType, DEM_VAR_NOINIT) Dem_OpCycReq[DEM_NUM_OF_OPCYCLE];
STATIC VAR(Dem_DependentOpCycStatuType, DEM_VAR_NOINIT) Dem_OpCycQualified[DEM_NUM_OF_OPCYCLE];
STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_DTCIsSelected[DEM_NUM_OF_CLIENT];
STATIC VAR(uint8, DEM_VAR_NOINIT) Dem_EventConfirmationCounter[DEM_MAXNUM_OF_EVENT];
STATIC VAR(uint8, DEM_VAR) Dem_SelectDTCState[DEM_NUM_OF_CLIENT];
STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_SelectDTCRecordUpdate[DEM_NUM_OF_CLIENT];
STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_EnableDtcSetting[DEM_MAXNUM_OF_DTC];
STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_DtcUpDateState[DEM_MAXNUM_OF_DTC];
STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_DataCaptureFlag[DEM_MAXNUM_OF_EVENT];

STATIC VAR(Dem_DTCFormatType, DEM_VAR_NOINIT) Dem_SelectDTC_DTCFormat[DEM_NUM_OF_CLIENT];
STATIC VAR(uint8, DEM_VAR_NOINIT) Dem_SelectDTC_RecordNumber[DEM_NUM_OF_CLIENT];
STATIC VAR(uint8, DEM_VAR_NOINIT) Dem_SelectDTC_FFRecIndex[DEM_NUM_OF_CLIENT];
STATIC VAR(uint8, DEM_VAR_NOINIT) Dem_SelectDTC_ExtendedDataNumber[DEM_NUM_OF_CLIENT];
STATIC VAR(uint8, DEM_VAR_NOINIT) Dem_SelectDTC_ExDataNumIndex[DEM_NUM_OF_CLIENT];
STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_SelectDTC_RecNumValidFlag[DEM_NUM_OF_CLIENT];
STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_SelectDTC_ExDaValidFlag[DEM_NUM_OF_CLIENT];
STATIC VAR(uint8, DEM_VAR_NOINIT) Dem_SelectDTC_ParentMem[DEM_NUM_OF_CLIENT];
STATIC VAR(uint8, DEM_VAR_NOINIT) Dem_SelectDTC_SubMem[DEM_NUM_OF_CLIENT];

/*used for UDS: Dem_SetFreezeFrameRecordFilter & Dem_GetNextFilteredRecord*/
#if(DEM_NUM_OF_FFRECCLASS > 0)
STATIC VAR(uint8, DEM_VAR_NOINIT) Dem_NumFFRecOfDTC[DEM_NUM_OF_CLIENT];
#endif

#if(DEM_NUM_OF_EN_CONDITION > 0)
STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_EventEnCondition[DEM_NUM_OF_EN_CONDITION];
#endif
#if(DEM_NUM_OF_STOR_CONDITION > 0)
STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_EventStorCondition[DEM_NUM_OF_STOR_CONDITION];
#endif

#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_EventAvailable[DEM_MAXNUM_OF_EVENT];
#endif

#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
STATIC VAR(boolean,DEM_VAR_NOINIT) Dem_DTCSuppressionState[DEM_MAXNUM_OF_DTC];
#endif

STATIC VAR(Dem_EventMemoryEntryStorageTriggerType, DEM_VAR_NOINIT) Dem_DataCaptureTrigger[DEM_MAXNUM_OF_EVENT];

#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
STATIC VAR(uint8, DEM_VAR_NOINIT) Dem_UsedNumOfPreStorageFF;
STATIC VAR(boolean,DEM_VAR_NOINIT) Dem_PreStorageFFFlag[DEM_MAXNUM_OF_EVENT];
#endif

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_EventDBTFreezeFlag[DEM_MAXNUM_OF_EVENT];
#endif

#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
STATIC VAR(boolean, DEM_VAR_NOINIT) Dem_DTC_FirstFdcThreshold[DEM_MAXNUM_OF_DTC];
#endif

#define DEM_STOP_SEC_VAR_CLEARED_LOCAL_8
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_CLEARED_LOCAL_16
#include "Dem_MemMap.h"

STATIC VAR(uint16, DEM_VAR_NOINIT) Dem_CapturePosition;
STATIC VAR(uint16, DEM_VAR_NOINIT) Dem_SelectDTC_Index[DEM_NUM_OF_CLIENT];
STATIC VAR(Dem_DTCOriginType, DEM_VAR_NOINIT) Dem_SelectDTC_DTCOrigin[DEM_NUM_OF_CLIENT];

#define DEM_STOP_SEC_VAR_CLEARED_LOCAL_16
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_CLEARED_LOCAL_32
#include "Dem_MemMap.h"

STATIC VAR(Dem_UdsDTCType, DEM_VAR_NOINIT) Dem_SelectDTC_DTC[DEM_NUM_OF_CLIENT];
#if(DEM_MAX_NUM_OF_DTR > 0)
STATIC VAR(uint32, DEM_VAR_NOINIT) Dem_OBD_AvailDTR[DEM_OBD_AVAIL_PARA_LENGTH];
#endif
#define DEM_STOP_SEC_VAR_CLEARED_LOCAL_32
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_CLEARED_GLOBAL_32
#include "Dem_MemMap.h"

STATIC VAR(Dem_UdsDTCType, DEM_VAR_NOINIT) Dem_ClearDTC_DTC;

#define DEM_STOP_SEC_VAR_CLEARED_GLOBAL_32
#include "Dem_MemMap.h"


#define DEM_START_SEC_VAR_CLEARED_GLOBAL_8
#include "Dem_MemMap.h"

STATIC VAR(uint8, DEM_VAR_NOINIT) Dem_EventStatusBuff[DEM_MAXNUM_OF_EVENT];
STATIC VAR(uint8, DEM_VAR_NOINIT) Dem_ClearDTC_Client;
STATIC VAR(Dem_DTCFormatType, DEM_VAR_NOINIT) Dem_ClearDTC_DTCFormat;

#if(DEM_CORE_NUMBER > 1)
#if(DEM_NUM_OF_EN_CONDITION > 0)
STATIC VAR(uint8, DEM_VAR_NOINIT) Dem_EnConditionBuff[DEM_NUM_OF_EN_CONDITION];
#endif
#if(DEM_NUM_OF_STOR_CONDITION > 0)
STATIC VAR(uint8, DEM_VAR_NOINIT) Dem_StorConditionBuff[DEM_NUM_OF_STOR_CONDITION];
#endif
STATIC VAR(uint8, DEM_VAR_NOINIT) Dem_DebounceStatusBuff[DEM_MAXNUM_OF_EVENT];
STATIC VAR(uint8, DEM_VAR_NOINIT) Dem_ResetEventStatusBuff[DEM_MAXNUM_OF_EVENT];
#endif

#define DEM_STOP_SEC_VAR_CLEARED_GLOBAL_8
#include "Dem_MemMap.h"



#define DEM_START_SEC_VAR_CLEARED_GLOBAL_16
#include "Dem_MemMap.h"
STATIC VAR(uint16, DEM_VAR_NOINIT) Dem_ClearDTC_Index;
STATIC VAR(Dem_DTCOriginType, DEM_VAR_NOINIT) Dem_ClearDTC_DTCOrigin;

#define DEM_STOP_SEC_VAR_CLEARED_GLOBAL_16
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_INIT_GLOBAL_16
#include "Dem_MemMap.h"
#if(DEM_NUM_OF_DTCGROUP > 0)
STATIC VAR(uint16, DEM_VAR_NOINIT) Dem_ClearDTC_GroupIndex = (uint16)DEM_NUM_OF_DTCGROUP;
#endif
#define DEM_START_SEC_VAR_INIT_GLOBAL_16
#include "Dem_MemMap.h"


#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
*   Dem static Api declaration
*******************************************************************************/
STATIC FUNC(void, DEM_CODE) DemInternal_CheckStorageMemFun
(
    Std_ReturnType result
);

STATIC FUNC(void, DEM_CODE) DemInternal_CheckStorageMem
(
    void
);


STATIC FUNC(void, DEM_CODE) DemInternal_SetCaptureQueue
(
    uint16 EventId,
    Dem_EventMemoryEntryStorageTriggerType Trigger
);

STATIC FUNC(void, DEM_CODE) DemInternal_ClrCaptureQueue
(
    uint16 EventId
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_CheckSelectDTC
(
    uint8 ClientId
);


STATIC FUNC(boolean, DEM_CODE) DemInternal_GetCaptureQueue
(
    uint16 EventId,
    Dem_EventMemoryEntryStorageTriggerType *Trigger
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_DTCMemoryCheck
(
    uint16 DtcId
);

STATIC FUNC(Dem_UdsStatusByteType, DEM_CODE) DemInternal_SetEventPass
(
    Dem_EventIdType EventId
);

STATIC FUNC(void, DEM_CODE) DemInternal_SetDTCFilter
(
    uint8 ClientId,
    uint8 StatusFilterMask,
    uint8 EventMemId,
    uint8 ClientSubMemId
);

#if(DEM_NVM_SUPPORT == STD_ON)
#if(DEM_CFG_CLEARDTCBEHAIOR != DEM_CLRRESP_VOLATILE)
STATIC FUNC(uint16, DEM_CODE) DemInternal_GetEntryBlockId
(
    uint16 DtcId,
    uint8 DataEntryId
);
STATIC FUNC(void, DEM_CODE) DemInternal_GetErrorState
(
    void
);
STATIC FUNC(void, DEM_CODE) DemInternal_ClearEntryInNvm
(
    uint16 DtcId
);
#endif
#endif

STATIC FUNC(Dem_UdsStatusByteType, DEM_CODE) DemInternal_SetEventFail
(
    Dem_EventIdType EventId
);

STATIC FUNC(uint16, DEM_CODE) DemInternal_GetDTCGroupMaxIndex
(
    void
);


#if(DEM_EVENT_COMBINATION_SUPPORT  != DEM_EVCOMB_DISABLED)
STATIC FUNC (Dem_UdsStatusByteType, DEM_CODE) DemInternal_UpdateCombinedDTC
(
    Dem_EventIdType EventId
);
#endif

STATIC FUNC(void, DEM_CODE) DemInternal_SetEventStatusAsync
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
);
#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
STATIC FUNC(uint8 ,DEM_CODE)DemInternal_GetFreePreStorageEntry
(
    uint16 EventId
);
#endif
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetUsableMemoryEntry
(
    uint16 DtcId,
    uint8 DTC_ParentMemId,
    uint8 DTC_SubMemId,
    Dem_EventDisplacementStrategyType Dtc_DisplacementStrategy,
    P2VAR(Dem_MemIdType, AUTOMATIC, DEM_APPL_DATA) MemoryEntryId
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_SearchFreeEntry
(
    uint8 ParentMemId,
    uint8 SubMemId,
    P2VAR(Dem_MemIdType, AUTOMATIC, DEM_APPL_DATA) MemoryEntryId
);
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_SetDTCSuppression
(
    uint16 DtcId,
    boolean SuppressionStatus
);
#endif
STATIC FUNC(void, DEM_CODE) DemInternal_ClearOneMemoryEntry
(
    uint8 DTC_ParentMemId,
    Dem_MemIdType MemoryEntryId,
    Dem_UserdefinedIdType  UserdefinedId
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_SearchEntryForDisplacement
(
    uint16 DtcId,
    uint8 DTC_ParentMemId,
    uint8 DTC_SubMemId,
    Dem_EventDisplacementStrategyType Dtc_DisplacementStrategy,
    P2VAR(Dem_MemIdType, AUTOMATIC, DEM_APPL_DATA) MemoryEntryId
);

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#if(DEM_CFG_OBD_EVENT_DISPLACEMENT == STD_ON)
STATIC FUNC(boolean, DEM_CODE) DemInternal_IgnoreFoundEntry
(
    uint16 EventId
);
#endif
#endif

STATIC FUNC(boolean, DEM_CODE) DemInternal_IsDtcActive
(
    uint16 DtcId
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetSizeOfFreezeFrameSelection
(
    uint8 ClientId,
    uint16 DtcId,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetSizeOfExtendedDataRecordSelection
(
    uint8 ClientId,
    uint16 DtcId,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord
);

STATIC FUNC(boolean, DEM_CODE) DemInternal_IsDtcOlder
(
    uint16 Event1,
    uint16 Event2
);


STATIC FUNC(void, DEM_CODE) DemInternal_GetEventInternalData
(
    uint16 EventId,
    Dem_InternalDataElementType DataType,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Data
);

#if(((DEM_MAX_FFSIZE_OF_DTC > 0)&&(DEM_NUM_OF_FFRECCLASS > 0))||((DEM_MAX_EXTSIZE_OF_DTC > 0)&&(DEM_NUM_OF_EXTDATACLASS > 0))\
    || (DEM_MAX_J1939FFSIZE_OF_DTC > 0) || (DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0))
STATIC FUNC(void, DEM_CODE) DemInternal_StorageDataElement
(
    uint16 EventId,
    uint16 DataIdx,
    P2P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufferPtr
);
#endif

STATIC FUNC(void, DEM_CODE) DemInternal_GetDtcInternalData
(
    uint16 DtcId,
    uint16 DataIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Data
);

STATIC FUNC(void, DEM_CODE) DemInternal_CaptureData
(
    uint16 EventId
);
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_ClearDTCAllowed
(
    Dem_EventIdType EventId
);

#if((DEM_MAX_FFSIZE_OF_DTC > 0) && (DEM_NUM_OF_FFRECCLASS > 0) \
    || ((DEM_MAX_J1939FFSIZE_OF_DTC > 0) || (DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0)))
STATIC FUNC(boolean, DEM_CODE) DemInternal_UpdateFFData
(
    uint16 EventId,
    Dem_EventMemoryEntryStorageTriggerType Trigger
);
#endif

#if((DEM_MAX_EXTSIZE_OF_DTC > 0) && (DEM_NUM_OF_EXTDATACLASS > 0))
STATIC FUNC(boolean, DEM_CODE) DemInternal_UpdateExtData
(
    uint16 EventId,
    Dem_EventMemoryEntryStorageTriggerType Trigger
);
#endif

#if(DEM_NUM_OF_EN_CONDITION > 0)
STATIC FUNC(void, DEM_CODE) DemInternal_SetEnCondition
(
    uint8 EnableConditionID,
    boolean ConditionFulfilled
);
#endif
#if(DEM_NUM_OF_STOR_CONDITION > 0)
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_SetStorCondition
(
    uint8 StorageConditionID,
    boolean ConditionFulfilled
);
#endif
STATIC FUNC(void, DEM_CODE) DemInternal_CycleStartProcess
(
    uint8 OperationCycleId
);

STATIC FUNC(void, DEM_CODE) DemInternal_CycleEndProcess
(
    uint8 OperationCycleId
);


STATIC FUNC(void, DEM_CODE) DemInternal_OperationCycleHandle
(
    uint8 OperationCycleId
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_ResetEventDebounceStatus
(
    Dem_EventIdType EventId,
    Dem_DebounceResetStatusType DebounceResetStatus
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_ResetEventStatus
(
    Dem_EventIdType EventId
);

STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_OperationCycle
(
    void
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_EventCheck
(
    Dem_EventIdType EventId
);

STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_UDSStatusHandle
(
    void
);

STATIC FUNC(void, DEM_CODE) DemInternal_EventQueuing
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
);

STATIC FUNC(void, DEM_CODE) DemInternal_GetClearDTCFromGroup
(
    void
);

STATIC FUNC(boolean, DEM_CODE) DemInternal_DebouncePrefailed
(
    Dem_EventIdType EventId
);
STATIC FUNC(boolean, DEM_CODE) DemInternal_DebouncePrepassed
(
    Dem_EventIdType EventId
);

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_DebounceTimer
(
    void
);
#endif

#if(DEM_CORE_NUMBER > 1)
STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_ServiceHandle
(
    void
);

#if(DEM_CSDATA_IN_MASTER_SUPPORT != STD_ON)
STATIC FUNC(void, DEM_CODE) DemInternal_ObtainCSData
(
    void
);
#endif
#endif

STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_CaptureData
(
    void
);

STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_ClearDTC
(
    void
);

STATIC FUNC(void, DEM_CODE) DemInternal_RestartOperationCycle
(
    uint8 OperationCycleId,
    Dem_OperationCycleStateType OperationCycleState
);

STATIC FUNC(void, DEM_CODE) DemInternal_SetUDSStatus
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
);

STATIC FUNC(void, DEM_CODE) DemInternal_EventStatusChangedNotification
(
    Dem_EventIdType EventId,
    Dem_UdsStatusByteType EventOldStatus,
    Dem_UdsStatusByteType EventNewStatus
);

STATIC FUNC(void, DEM_CODE) DemInternal_DTCStatusChangedNotification
(
    uint32 DTC,
    Dem_UdsStatusByteType DTCOldStatus,
    Dem_UdsStatusByteType DTCNewStatus

);

STATIC FUNC(void, DEM_CODE) DemInternal_GetClearEvent
(
    uint16 DtcId
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_ClearOneDTC
(
    uint16 DtcId
);

STATIC FUNC(void, DEM_CODE) DemInternal_ClearOneEvent
(
    Dem_EventIdType EventId,
    boolean Aging
);

STATIC FUNC(void, DEM_CODE) DemInternal_ClearOneDTCGroup
(
    void
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetEventFreezeFrameDataEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    uint16 DataId,
    uint8 *DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetEventExtendedDataRecordEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);

#if(DEM_NUM_OF_INDICATOR > 0)
STATIC FUNC(void, DEM_CODE) DemInternal_IndicatorOnCriteriaFulfilled
(
    Dem_EventIdType EventId,
    Dem_UdsStatusByteType EventOldStatus,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) EventNewStatus
);

STATIC FUNC(void, DEM_CODE) DemInternal_IndicatorOffCriteriaFulfilled
(
    Dem_EventIdType EventId,
    Dem_IndicatorOffType OffReason,
    Dem_UdsStatusByteType EventOldStatus,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) EventNewStatus
);

STATIC FUNC(void, DEM_CODE) DemInternal_GetIndicatorStatus
(
    uint8 IndicatorId,
    P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus
);
#endif/*#if(DEM_NUM_OF_INDICATOR > 0)*/

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
STATIC FUNC(void, DEM_CODE) DemInternal_InitOBDData
(
    void
);

STATIC FUNC(void, DEM_CODE) DemInternal_StoreOBDFreezeFrame
(
    Dem_EventIdType EventId,
    Dem_UdsStatusByteType EventOldStatus,
    Dem_UdsStatusByteType EventNewStatus
);

STATIC FUNC(void, DEM_CODE) DemInternal_ClearOBDFreezeFrame
(
    Dem_EventIdType EventId
);

STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_OBD
(
    void
);
#if(DEM_MAX_NUM_OF_DTR > 0)
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_CheckEventCondition
(
    Dem_EventIdType EventId
);

STATIC FUNC(uint16, DEM_CODE) DemInternal_GetDtrId
(
    uint8 Obdmid,
    uint8 TIDindex
);

STATIC FUNC(void, DEM_CODE) DemInternal_DtrInfoInit
(
    void
);
#endif

#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
STATIC FUNC(void, DEM_CODE) DemInternal_CalPID21_31_4D_4E_Data
(
    void
);
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU) && (DEM_CFG_OBD_CENTRALIZED_PID31_HANDLING == STD_ON))*/
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/

#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
STATIC FUNC(boolean, DEM_CODE) DemInternal_CopyPreStorageFFData
(
    uint16 EventId,
    uint8 MemId,
    uint8 SubMemId,
    uint8 MemEntryId
);

STATIC FUNC(void , DEM_CODE)DemInternal_PreStorageFFData
(
    uint16 EventId,
    uint8 EntryId
);
#endif

#if(DEM_NUM_OF_RATIO > 0)
STATIC FUNC(void, DEM_CODE) DemInternal_UpdateRatioNumerator
(
    Dem_EventIdType EventId
);

STATIC FUNC(void, DEM_CODE) DemInternal_UpdateRatioDenominator
(
    void
);
#endif

#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
STATIC FUNC(void, DEM_CODE) DemInternal_AddEventPermanentEntry
(
    Dem_EventIdType EventId
);

STATIC FUNC(void, DEM_CODE) DemInternal_RemoveEventPermanentEntry
(
    Dem_EventIdType EventId
);
#endif/*#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)*/
#if((STD_ON == DEM_CFG_J1939EX_FF_SUPPORT)||(STD_ON == DEM_CFG_J1939_FF_SUPPORT))
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_J1939GetSizeOfFreezeFrame
(
    uint16 DtcId,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
);
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_J1939ExpGetSizeOfFreezeFrame
(
    uint16 DtcId,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
);

STATIC FUNC(void, DEM_CODE) DemInternal_J1939GetDataOfFreezeFrame
(
    uint16 DtcId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer
);
STATIC FUNC(void, DEM_CODE) DemInternal_J1939ExpGetDataOfFreezeFrame
(
    uint16 DtcId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer
);
#endif
#if(DEM_J1939_SUPPORT == STD_ON)
STATIC FUNC(void, DEM_CODE) DemInternal_J1939GetOccurrenceCounter
(
    uint16 DtcId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter
);
#endif
/*******************************************************************************
*   Dem static Api definition
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_CheckStorageMemFun
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_CheckStorageMemFun
(
    Std_ReturnType result
)
{
    Std_ReturnType ret = result;
    uint8 ParentMemId;
    uint16 EventMemId;
    uint8 SubMemId;
    uint16 i;
    if(ret == E_OK)
    {
        for(i = (uint16)0; i < DEM_NUM_OF_EVENT; i++)
        {
#if((DEM_EVENT_MAXFDCDCC_SUPPORT == STD_ON)&&(DEM_EVENT_MAXFDCSLC_SUPPORT == STD_ON))
            if(DEM_EVENT_MAXFDCDCC(i) > DEM_EVENT_MAXFDCSLC(i))
            {
                ret = E_NOT_OK;
                break;
            }
#endif
#if((DEM_EVENT_CSLF_SUPPORT == STD_ON)&&(DEM_EVENT_CSFF_SUPPORT == STD_ON))
            if(DEM_EVENT_CSLF(i) > DEM_EVENT_CSFF(i))
            {
                ret = E_NOT_OK;
                break;
            }
#endif

            if(DEM_CFG_EVENT_DTCREF(i) != DEM_DTC_ID_INVALID)
            {
                EventMemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DEM_CFG_EVENT_DTCREF(i));
                ParentMemId = DEM_GET_EVENTMEMORY_ID(EventMemId);
                SubMemId = DEM_GET_SUBMEMORY_ID(EventMemId);
                if(SubMemId == DEM_PRIMARY_MEMORY)
                {
                    if((DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(i)) != DEM_DATA_INVALID_U8) \
                        && (DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(i)) >= DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY(ParentMemId)))
                    {
                        ret = E_NOT_OK;
                        break;
                    }
                }
#if(DEM_NUM_OF_USERDEF > 0)
                else
                {
                    if((DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(i)) != DEM_DATA_INVALID_U8) \
                        && (DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(i)) >= DEM_CFG_MAXNUMBEREVENTENTRY_USERDEFINED(ParentMemId)))
                    {
                        ret = E_NOT_OK;
                        break;
                    }
                }
#endif
            }
#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
            if(Dem_UsedNumOfPreStorageFF >= (uint8)DEM_CFG_MAXNUMBER_PRESTOREDFF)
            {
                ret = E_NOT_OK;
            }
#endif
        }
    }
    if(ret == E_NOT_OK)
    {
        DEM_DET_REPORT_ERROR(DEM_INIT_APIID, DEM_E_INIT_FAILED);
        (void)Dem_NvM_InitStorageMem();
    }
}
/*******************************************************************************
*   Dem static Api definition
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_CheckStorageMem
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(void, DEM_CODE) DemInternal_CheckStorageMem
(
    void
)
{
    uint8 OpIdx;
    uint8 MemId;
    uint8 ParentMemId;
    uint8 SubMemId;
    uint8 MemUsedNum;
    uint8 MemUsedNum1;
    uint16 i;
#if(DEM_NUM_OF_USERDEF > 0)
    uint8 UserIndex;
    uint8 userdefId;
#endif
    uint16 EventMemId;
#if((DEM_MAX_FFSIZE_OF_DTC > 0)||(DEM_MAX_EXTSIZE_OF_DTC > 0))
    uint16 j;
#endif
    Std_ReturnType ret = E_OK;

    if(((DEM_EVENT_FIRST_FAILED != DEM_DATA_INVALID_U16) && (DEM_EVENT_FIRST_FAILED >= DEM_NUM_OF_EVENT)) \
        || ((DEM_EVENT_RECENT_FAILED != DEM_DATA_INVALID_U16) && (DEM_EVENT_RECENT_FAILED >= DEM_NUM_OF_EVENT)) \
        || ((DEM_EVENT_FIRST_CONFIRMED != DEM_DATA_INVALID_U16) && (DEM_EVENT_FIRST_CONFIRMED >= DEM_NUM_OF_EVENT)) \
        || ((DEM_EVENT_RECENT_CONFIRMED != DEM_DATA_INVALID_U16) && (DEM_EVENT_RECENT_CONFIRMED >= DEM_NUM_OF_EVENT)))
    {
        ret = E_NOT_OK;
    }
    for(OpIdx = (uint8)0 ; OpIdx < (uint8)DEM_NUM_OF_OPCYCLE; OpIdx++)
    {
        if((DEM_CURRENT_OP_STATE(OpIdx) != DEM_CYCLE_STATE_START) && (DEM_CURRENT_OP_STATE(OpIdx) != DEM_CYCLE_STATE_END))
        {
            ret = E_NOT_OK;
            break;
        }
    }

    for(MemId = (uint8)0 ; MemId < DEM_NUM_OF_EVENTMEMORYSET; MemId++)
    {
        if((ret == E_OK) && (DEM_PRIMARY_DATAENTRY_USEDNUM(MemId) > DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY(MemId)))
        {
            ret = E_NOT_OK;
        }
        if((ret == E_OK) && (DEM_PRIMARY_DATAENTRY_USEDNUM(MemId) != (uint8)DEM_DATA_CLEAR))
        {
            MemUsedNum = (uint8)0;
            MemUsedNum1 = (uint8)0;
            for(i = (uint16)0; i < (uint16)DEM_NUM_OF_DTC; i++)
            {
                EventMemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(i);
                ParentMemId = DEM_GET_EVENTMEMORY_ID(EventMemId);
                SubMemId = DEM_GET_SUBMEMORY_ID(EventMemId);
                if((ParentMemId == MemId) && (SubMemId == DEM_PRIMARY_MEMORY) && (DEM_DTC_DATAENTRYREF(i) != DEM_DATA_INVALID_U8))
                {
                    MemUsedNum++;
                }
            }
            if(ParentMemId < DEM_NUM_OF_EVENTMEMORYSET)
            {
                for(i = (uint16)0; i < (uint16)DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY(MemId); i++)
                {
                    if(DEM_PRIMARY_DATAENTRY_USED(ParentMemId,i) == TRUE)
                    {
                        MemUsedNum1 ++;
                    }

                }
            }

            if((DEM_PRIMARY_DATAENTRY_USEDNUM(MemId) != MemUsedNum) || (MemUsedNum1 != MemUsedNum))
            {
                ret = E_NOT_OK;
                break;
            }
        }
        if((ret == E_OK) && (DEM_PRIMARY_DATAENTRY_USEDNUM(MemId) == (uint8)DEM_DATA_CLEAR))
        {
            for(i = (uint16)0; i < DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY(MemId); i++)
            {
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
                for(j = (uint16)0; j < (uint16)DEM_MAX_FFSIZE_OF_DTC; j++)
                {
                    if((DEM_PRIMARY_FFDATA_PTR(MemId,i))[j] != DEM_DATA_INVALID_U8)
                    {
                        ret = E_NOT_OK;
                        break;
                    }
                }
#endif/*#if(DEM_MAX_FFSIZE_OF_DTC > 0)*/

#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
                if(ret == E_OK)
                {
                    for(j = (uint16)0; j < (uint16)DEM_MAX_EXTSIZE_OF_DTC; j++)
                    {
                        if((DEM_PRIMARY_EXTDATA_PTR(MemId,i))[j] != DEM_DATA_INVALID_U8)
                        {
                            ret = E_NOT_OK;
                            break;
                        }
                    }
                }
#endif/*#if(DEM_MAX_EXTSIZE_OF_DTC > 0)*/
                if(ret == E_NOT_OK)
                {
                    break;
                }
            }
        }
#if(DEM_NUM_OF_USERDEF > 0)
        if(ret == E_OK)
        {
            for(UserIndex = (uint8)0; UserIndex < (uint8)DEM_CFG_USERDEF_NUMBER(MemId); UserIndex++)
            {
                userdefId = DEM_CFG_USERDEF_STARTNUM(MemId) + UserIndex;
                if(DEM_USER_DEFINED_DATAENTRY_USEDNUM(MemId,userdefId) > DEM_CFG_MAXNUMBEREVENTENTRY_USERDEFINED(userdefId))
                {
                    ret = E_NOT_OK;
                    break;
                }
                MemUsedNum = (uint8)0;
                MemUsedNum1 = (uint8)0;
                for(i = (uint16)0; i < (uint16)DEM_NUM_OF_DTC; i++)
                {
                    EventMemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(i);
                    ParentMemId = DEM_GET_EVENTMEMORY_ID(EventMemId);
                    SubMemId = DEM_GET_SUBMEMORY_ID(EventMemId);
                    if((ParentMemId == MemId) && (SubMemId == userdefId) && (DEM_DTC_DATAENTRYREF(i) != DEM_DATA_INVALID_U8))
                    {
                        MemUsedNum++;
                    }
                }

                for(i = (uint16)0; i < (uint16)DEM_USER_DEFINED_DATAENTRY_USEDNUM(MemId,userdefId); i++)
                {
                    if(DEM_USERDEFINED_DATAENTRY_USED(userdefId,i) == TRUE)
                    {
                        MemUsedNum1 ++;
                    }
                }

                if((DEM_USER_DEFINED_DATAENTRY_USEDNUM(MemId,userdefId) != MemUsedNum) || ( MemUsedNum1 != MemUsedNum))
                {
                    ret = E_NOT_OK;
                    break;
                }
                if(DEM_USER_DEFINED_DATAENTRY_USEDNUM(MemId,userdefId) == (uint8)DEM_DATA_CLEAR)
                {
                    for(i =(uint16) 0; i < DEM_CFG_MAXNUMBEREVENTENTRY_USERDEFINED(userdefId); i++)
                    {
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
                        for(j = (uint16)0; j < (uint16)DEM_MAX_FFSIZE_OF_DTC; j++)
                        {
                            if((DEM_USERDEFINED_FFDATA_PTR(userdefId,i))[j] != DEM_DATA_INVALID_U8)
                            {
                                ret = E_NOT_OK;
                                break;
                            }
                        }
#endif/*#if(DEM_MAX_FFSIZE_OF_DTC > 0)*/

#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
                        if(ret == E_OK)
                        {
                            for(j = (uint16)0; j < (uint16)DEM_MAX_EXTSIZE_OF_DTC; j++)
                            {
                                /*PRQA S 715 ++*/
                                /*
                                Nesting of control structures (statements) exceeds 15, without modification.
                                */
                                if((DEM_USERDEFINED_EXTDATA_PTR(userdefId,i))[j] != DEM_DATA_INVALID_U8)
                                {
                                    ret = E_NOT_OK;
                                    break;
                                }
                                /*PRQA S 715 --*/
                            }
                        }
#endif/*#if(DEM_MAX_EXTSIZE_OF_DTC > 0)*/
                        if(ret == E_NOT_OK)
                        {
                            break;
                        }
                    }
                }
            }
        }
#endif

#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
        if((ret == E_OK) && (DEM_PERMANENT_DATAENTRY_USEDNUM(MemId) > DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT(MemId)))
        {
            ret = E_NOT_OK;
        }

        if((ret == E_OK) && (DEM_PERMANENT_DATAENTRY_USEDNUM(MemId) == DEM_DATA_CLEAR))
        {
            for(i = (uint16)0; i < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT(MemId); i++)
            {
                if(DEM_PERMANENT_DATAENTRY_EVENTID(MemId,i) != DEM_EVENT_ID_INVALID)
                {
                    ret = E_NOT_OK;
                    break;
                }
            }
        }
#endif/*#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)*/
        if(ret == E_NOT_OK)
        {
            break;
        }
    }
    DemInternal_CheckStorageMemFun(ret);
}
/*PRQA S 4700 --*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_SetCaptureQueue
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_SetCaptureQueue
(
    uint16 EventId,
    Dem_EventMemoryEntryStorageTriggerType Trigger
)
{
    Dem_DataCaptureFlag[EventId] = TRUE;
    Dem_DataCaptureTrigger[EventId] |= Trigger;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_EventStatusChangedNotification
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_EventStatusChangedNotification
(
    Dem_EventIdType EventId,
    Dem_UdsStatusByteType EventOldStatus,
    Dem_UdsStatusByteType EventNewStatus

)
{
#if(DEM_EVENT_STATUS_CHANGE_CALLBACK_SUPPORT == STD_ON)
    if(NULL_PTR != DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(EventId))
    {
#if(DEM_CORE_NUMBER > 1)
        if(DEM_MASTER_COREID != DEM_CFG_EVENT_COREREF(EventId))
        {
            DEM_CFG_EVENT_STATUS_OLDSTATUS(EventId) = EventOldStatus;
            DEM_CFG_EVENT_STATUS_NEWSTATUS(EventId) = EventNewStatus;
            DEM_CFG_EVENT_STATUS_CHANGE_FLAG(EventId) = TRUE;
        }
        else
#endif
        {
            (void)DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(EventId)(EventOldStatus, EventNewStatus);
        }
    }
#endif
#if(DEM_CFG_TRIGGER_FIM_REPORTS == STD_ON)
    FiM_DemTriggerOnMonitorStatus(EventId);
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_DTCStatusChangedNotification
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_DTCStatusChangedNotification
(
    uint32 DTC,
    Dem_UdsStatusByteType DTCOldStatus,
    Dem_UdsStatusByteType DTCNewStatus

)
{
    uint8 ClientId;
    for(ClientId = (uint8)0; ClientId < DEM_NUM_OF_CLIENT; ClientId++)
    {
        if(DEM_CFG_DTC_STATUSCHANGED_CALLFNC(ClientId) != NULL_PTR )
        {
            /*SWS_Dem_00284*/
            (void)DEM_CFG_DTC_STATUSCHANGED_CALLFNC(ClientId)(DTC, DTCOldStatus, DTCNewStatus);
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_ClrCaptureQueue
(
    uint16 EventId
)
{
    Dem_DataCaptureFlag[EventId] = FALSE;
    Dem_DataCaptureTrigger[EventId] = DEM_DATA_CLEAR;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, DEM_CODE) DemInternal_GetCaptureQueue
(
    uint16 EventId,
    Dem_EventMemoryEntryStorageTriggerType *Trigger
)
{
    boolean ret = FALSE;

    if(Dem_DataCaptureFlag[EventId] == TRUE)
    {
        ret = TRUE;
    }

    if(Trigger != NULL_PTR)
    {
        *Trigger = Dem_DataCaptureTrigger[EventId];
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Dem_UdsStatusByteType, DEM_CODE) DemInternal_SetEventPass
(
    Dem_EventIdType EventId
)
{
    Dem_UdsStatusByteType EventNewStatus;
    Dem_UdsStatusByteType EventOldStatus;
#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
    uint8 i;
    uint8 PreStoEntryId;
#endif
    EventNewStatus = DEM_EVENT_STATUS(EventId);
    EventOldStatus = DEM_EVENT_STATUS(EventId);

    /*SWS_Dem_00036*//*SWS_Dem_00386*/
    EventNewStatus = DEM_CLEAR_UDS_STATUS_TF(EventNewStatus);
    /*SWS_Dem_00465*/
#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
    if(DEM_TEST_UDS_STATUS_TF(EventOldStatus))
    {
        PreStoEntryId = DEM_EVEVT_PRESTO_FF_ENTRY(EventId);
        if((DEM_CFG_EVENT_PRESTORAGE(EventId) != FALSE) && (PreStoEntryId != DEM_DATA_INVALID_U8))
        {
            DEM_PRESTORE_FFENTRY_EVENTID(PreStoEntryId) = DEM_DATA_CLEAR;
            DEM_PRESTORE_FFENTRY_USED(PreStoEntryId) = FALSE;
            for(i = (uint8)0; i < (uint8)DEM_MAX_FFSIZE_OF_DTC; i++)
            {
                DEM_PRESTORE_FFENTRY(PreStoEntryId).PreStorageFFData[i] = DEM_DATA_CLEAR;
            }
            DEM_EVEVT_PRESTO_FF_ENTRY(EventId) = DEM_DATA_INVALID_U8;
            Dem_PreStorageFFFlag[EventId] = FALSE;
            Dem_UsedNumOfPreStorageFF--;
        }
    }
#endif
    /*SWS_Dem_00392*/
    EventNewStatus = DEM_CLEAR_UDS_STATUS_TNCSLC(EventNewStatus);
    /*SWS_Dem_00394*/
    EventNewStatus = DEM_CLEAR_UDS_STATUS_TNCTOC(EventNewStatus);
    /*SWS_Dem_00421*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
    if(DEM_CFG_EVENT_DBC(EventId) != NULL_PTR)
    {
        DEM_EVENT_DBC(EventId) = DEM_CFG_EVENT_DBC_PASSTHRESHOLD(EventId);
    }
#endif
    /*SWS_Dem_00435*/
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
    if(DEM_CFG_EVENT_DBT(EventId) != NULL_PTR)
    {
        DEM_EVENT_DBT(EventId) = DEM_CFG_EVENT_DBT_PASSED(EventId);
        DEM_EVENT_TIMERDIRECTION(EventId) = DEM_EVENT_STATUS_PASSED;
        Dem_EventDBTFreezeFlag[EventId] = FALSE;
    }
#endif

#if(STD_ON != DEM_CMA_PLATFORM_ENABLED)
    if((DEM_TEST_UDS_STATUS_TF(EventOldStatus)) && (!DEM_TEST_UDS_STATUS_TF(EventNewStatus)))
#endif
    {
        /*SWS_Dem_01070*/
        DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_PASSED);
    }

#if(DEM_NUM_OF_INDICATOR > 0)
    DemInternal_IndicatorOffCriteriaFulfilled(EventId, DEM_TF_CLEAR, EventOldStatus, &EventNewStatus);
#endif

    return EventNewStatus;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(Dem_UdsStatusByteType, DEM_CODE) DemInternal_SetEventFail
(
    Dem_EventIdType EventId
)
{
    Dem_UdsStatusByteType EventOldStatus;
    Dem_UdsStatusByteType EventNewStatus;
#if(DEM_NUM_OF_STOR_GROUP > 0)
    boolean EventStorageCondFullFilled = TRUE;
#endif
    Dem_OccurrenceCounterProcessingType DtcOccProcessType;
    uint16 DTC_MemId;
    uint8 DTC_ParentMemId;
    uint8 DTC_SubMemId;
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    uint8 EventCmaStatus;
#endif
#if(DEM_NUM_OF_STOR_CONDITION > 0)
    uint8 i;
#endif

    if(DEM_EVENT_FIRST_FAILED == DEM_DATA_INVALID_U16)
    {
        DEM_EVENT_FIRST_FAILED = EventId;
    }
    /* Event not reference DTC*/
    if(DEM_CFG_EVENT_DTCREF(EventId) == DEM_DTC_ID_INVALID)
    {
        EventOldStatus = DEM_EVENT_STATUS(EventId);
        EventNewStatus = DEM_EVENT_STATUS(EventId);
    }
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
    /*Combined Event*/
    else if(DEM_IS_COMBINEDDTC(DEM_CFG_EVENT_DTCREF(EventId)))
    {
        EventOldStatus = DEM_EVENT_STATUS(EventId);
        EventNewStatus = DEM_EVENT_STATUS(EventId);
    }
#endif
    /*Event reference one DTC*/
    else
    {
        EventOldStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
        EventNewStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
    }



    /*SWS_Dem_00036*//*SWS_Dem_00386*/
    EventNewStatus = DEM_SET_UDS_STATUS_TF(EventNewStatus);
    /*SWS_Dem_00389*/
    EventNewStatus = DEM_SET_UDS_STATUS_TFTOC(EventNewStatus);
    /*SWS_Dem_00392*/
    EventNewStatus = DEM_CLEAR_UDS_STATUS_TNCSLC(EventNewStatus);
    /*SWS_Dem_00393*/
    EventNewStatus = DEM_SET_UDS_STATUS_TFSLC(EventNewStatus);
    /*SWS_Dem_00394*/
    EventNewStatus = DEM_CLEAR_UDS_STATUS_TNCTOC(EventNewStatus);




#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    EventCmaStatus = DEM_EVENT_CMA_STATUS(EventId);
    /*EventCmaStatus = DEM_SET_CMA_STATUS_WIRSLC(EventCmaStatus);
    EventCmaStatus = DEM_SET_CMA_STATUS_ERDTC(EventCmaStatus);*/
    EventCmaStatus = DEM_SET_CMA_STATUS_TFSLCA(EventCmaStatus);
    DEM_EVENT_CMA_STATUS(EventId) = EventCmaStatus;
#endif

    /*SWS_Dem_00420*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
    if(DEM_CFG_EVENT_DBC(EventId) != NULL_PTR)
    {
        DEM_EVENT_DBC(EventId) = DEM_CFG_EVENT_DBC_FAILTHRESHOLD(EventId);
    }
#endif
    /*SWS_Dem_00431*/
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
    if(DEM_CFG_EVENT_DBT(EventId) != NULL_PTR)
    {
        DEM_EVENT_DBT(EventId) = DEM_CFG_EVENT_DBT_FAILED(EventId);
        DEM_EVENT_TIMERDIRECTION(EventId) = DEM_EVENT_STATUS_FAILED;
        Dem_EventDBTFreezeFlag[EventId] = FALSE;
    }
#endif
#if(DEM_EVENT_MAXFDCDCC_SUPPORT == STD_ON)
    /*SWS_Dem_00791*/
    DEM_EVENT_MAXFDCDCC(EventId) = DEM_DATA_MAX_FDC;
#endif
#if(DEM_EVENT_MAXFDCSLC_SUPPORT == STD_ON)
    /*SWS_Dem_00795*/
    DEM_EVENT_MAXFDCSLC(EventId) = DEM_DATA_MAX_FDC;
#endif
    if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
    {
        /*Reset DTC aging counter*/
        DEM_DTC_AGINGCNT(DEM_CFG_EVENT_DTCREF(EventId)) = DEM_DATA_CLEAR;
    }

    if(!DEM_TEST_UDS_STATUS_TFTOC(EventOldStatus))
    {
        /*if(DEM_EVENT_FCC(EventId) < Dem_EventConfirmationCounter[EventId])*/
        {
            DEM_EVENT_FCC(EventId)++;
            if(DEM_EVENT_FCC(EventId) >= Dem_EventConfirmationCounter[EventId])
            {
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
                DEM_EVENT_FCC(EventId) = DEM_DATA_CLEAR;
#endif
                /*SWS_Dem_00391*/
                EventNewStatus = DEM_SET_UDS_STATUS_CDTC(EventNewStatus);
                if(DEM_EVENT_FIRST_CONFIRMED == DEM_DATA_INVALID_U16)
                {
                    DEM_EVENT_FIRST_CONFIRMED = EventId;
                }

                if(!DEM_TEST_UDS_STATUS_CDTC(EventOldStatus))
                {
                    DEM_EVENT_RECENT_CONFIRMED = EventId;
                }
            }
        }
    }
#if(DEM_EVENT_CSLF_SUPPORT == STD_ON)
    /*SWS_Dem_00771*//*SWS_Dem_00772*/
    DEM_EVENT_CSLF(EventId) = DEM_DATA_CLEAR;
#endif
    if(!DEM_TEST_UDS_STATUS_TF(EventOldStatus))
    {
        /*SWS_Dem_00787*/
        DEM_EVENT_RECENT_FAILED = EventId;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
        DEM_EVENT_OBD_PCSLF(EventId) = DEM_DATA_CLEAR;
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
        DEM_EVENT_CMA_PCSLF(EventId) = DEM_DATA_CLEAR;
#endif

        if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
        {
            DTC_MemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DEM_CFG_EVENT_DTCREF(EventId));
            DTC_ParentMemId = DEM_GET_EVENTMEMORY_ID(DTC_MemId);
            DTC_SubMemId = DEM_GET_SUBMEMORY_ID(DTC_MemId);
            if(DTC_SubMemId == DEM_PRIMARY_MEMORY)
            {
                DtcOccProcessType = DEM_CFG_PRIMARY_OCCURRENCECOUNTERPROCESSING(DTC_ParentMemId);
            }
#if(DEM_NUM_OF_USERDEF > 0)
            else
            {
                DtcOccProcessType = DEM_CFG_USERDEF_OCCURRENCECOUNTERPROCESSING(DTC_SubMemId);
            }
#endif
            if(((DtcOccProcessType == DEM_PROCESS_OCCCTR_TF)\
                || ((DtcOccProcessType == DEM_PROCESS_OCCCTR_CDTC)\
                && (DEM_TEST_UDS_STATUS_CDTC(EventNewStatus))))\
                && (DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) != DEM_DATA_INVALID_U8))
            {
                /*SWS_Dem_00625*/
                if(DEM_EVENT_OCCCTR(EventId) < DEM_DATA_U8_FF)
                {
                    DEM_EVENT_OCCCTR(EventId)++;
                }
            }
        }
    }

    if(!DEM_TEST_UDS_STATUS_TFSLC(EventOldStatus))
    {
#if(DEM_EVENT_CSFF_SUPPORT == STD_ON)
        /*SWS_Dem_00776*/
        DEM_EVENT_CSFF(EventId) = DEM_DATA_CLEAR;
#endif
#if(DEM_EVENT_FCSLC_SUPPORT == STD_ON)
        /*SWS_Dem_00780*/
        DEM_EVENT_FCSLC(EventId) = DEM_DATA_CLEAR;
#endif
    }

#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
#if(DEM_EVENT_FCSLC_SUPPORT == STD_ON)
    /*SWS_Dem_00782*/
    if((!DEM_TEST_UDS_STATUS_TFTOC(EventOldStatus)) \
            && (DEM_EVENT_FCSLC(EventId) < DEM_DATA_U8_FF))
    {
        DEM_EVENT_FCSLC(EventId)++;
    }
#endif
#endif
    if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
    {
#if(DEM_EVENT_COMBINATION_SUPPORT  == DEM_EVCOMB_ONSTORAGE)
        if(!DEM_IS_COMBINEDDTC(DEM_CFG_EVENT_DTCREF(EventId)))
        {
#endif
#if(DEM_NUM_OF_STOR_GROUP > 0)
            /*SWS_Dem_00455*//*SWS_Dem_00458*/
            /*SWS_Dem_00591*//*SWS_Dem_00459*/
            if(DEM_CFG_EVENT_STOR(EventId) != NULL_PTR)
            {
                for(i = (uint8)0; i < DEM_CFG_EVENT_STOR_NUM(EventId); i++)
                {
                    if(Dem_EventStorCondition[(DEM_CFG_EVENT_STOR_REF(EventId)[i])] != TRUE)
                    {
                        EventStorageCondFullFilled = FALSE;
                        break;
                    }
                }
            }
            if(EventStorageCondFullFilled != FALSE)
            {
#endif
                /*SWS_Dem_00390*/ /*SWS_Dem_01309*/
                EventNewStatus = DEM_SET_UDS_STATUS_PDTC(EventNewStatus);
                /*SWS_Dem_01308*/
                DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_EVERY_TEST_FAILED);
                /*SWS_Dem_01351*/
                if(!DEM_TEST_UDS_STATUS_TFTOC(EventOldStatus))
                {
                    DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_TEST_FAILED_THIS_OPERATION_CYCLE);
                }
                if(!DEM_TEST_UDS_STATUS_TF(EventOldStatus))
                {
                    /*SWS_Dem_00783*/
                    DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_TEST_FAILED);
                    /*SWS_Dem_00784*//*SWS_Dem_00922*/
                    DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_PENDING);
                    /*SWS_Dem_00923*/
                    if(DEM_TEST_UDS_STATUS_CDTC(EventNewStatus))
                    {
                        DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_CONFIRMED);
                    }
                }

                if((DEM_TEST_UDS_STATUS_CDTC(EventNewStatus)) && (!DEM_TEST_UDS_STATUS_CDTC(EventOldStatus)))
                {
                    /*SWS_Dem_00785*/
                    DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_CONFIRMED);
                }

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
                DemInternal_StoreOBDFreezeFrame(EventId, EventOldStatus, EventNewStatus);
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/

#if(DEM_NUM_OF_STOR_GROUP > 0)
            }
#endif
#if(DEM_EVENT_COMBINATION_SUPPORT  == DEM_EVCOMB_ONSTORAGE)
        } /*if(!DEM_IS_COMBINEDDTC(DEM_CFG_EVENT_DTCREF(EventId)))*/
#endif
    }
#if(DEM_NUM_OF_INDICATOR > 0)
    DemInternal_IndicatorOnCriteriaFulfilled(EventId, EventOldStatus, &EventNewStatus);
#endif
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
    DemInternal_AddEventPermanentEntry(EventId);
    DEM_EVENT_OBD_CLEAR_FLAG(EventId) = FALSE;
#endif
    return EventNewStatus;
}
/*PRQA S 4700 --*/

#if(DEM_CFG_BSWERRORBUFFERSIZE > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:DemInternal_EventQueuing
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_EventQueuing
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
)
{
    if(Dem_ErrorBufferIndex < (uint8)DEM_CFG_BSWERRORBUFFERSIZE)
    {
        DEM_REPORT_BSW_EVENT_ID(Dem_ErrorBufferIndex) = EventId;
        DEM_REPORT_BSW_EVENT_STATU(Dem_ErrorBufferIndex) = EventStatus;
        Dem_ErrorBufferIndex ++;
    }
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(void, DEM_CODE) DemInternal_SetEventStatusAsync
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
)
{
    boolean DebounceState;
    Dem_UdsStatusByteType EventOldStatus;
    Dem_UdsStatusByteType EventNewStatus;
    Dem_DemGeneralTriggerOnMonitorStatusType DemGeneralTriggerOnMonitorStatusFuncPtr;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    /*SWS_Dem_00626*//*SWS_Dem_00529*//*SWS_Dem_00481*//*SWS_Dem_00482*/
    if(DEM_CURRENT_OP_STATE(DEM_CFG_EVENT_OPCYCREF(EventId)) == DEM_CYCLE_STATE_START)
    {
        EventOldStatus = DEM_EVENT_STATUS(EventId);

        if(EventStatus == DEM_EVENT_STATUS_FAILED)
        {
            DemInternal_SetUDSStatus(EventId, DEM_EVENT_STATUS_FAILED);
        }
        else if(EventStatus == DEM_EVENT_STATUS_PREFAILED)
        {
            DebounceState = DemInternal_DebouncePrefailed(EventId);
            if(DebounceState != FALSE)
            {
                DemInternal_SetUDSStatus(EventId, DEM_EVENT_STATUS_FAILED);
            }
        }
        else if(EventStatus == DEM_EVENT_STATUS_PASSED)
        {
            DemInternal_SetUDSStatus(EventId, DEM_EVENT_STATUS_PASSED);
        }
        else if(EventStatus == DEM_EVENT_STATUS_PREPASSED)
        {
            DebounceState = DemInternal_DebouncePrepassed(EventId);
            if(DebounceState != FALSE)
            {
                DemInternal_SetUDSStatus(EventId, DEM_EVENT_STATUS_PASSED);
            }
        }
        else if(EventStatus == DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED)
        {
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
            if(FALSE == Dem_DTC_FirstFdcThreshold[DEM_CFG_EVENT_DTCREF(EventId)])
            {
                Dem_DTC_FirstFdcThreshold[DEM_CFG_EVENT_DTCREF(EventId)] = TRUE;
                /*SWS_Dem_01068*//*SWS_Dem_01069*/
                DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_FDC_THRESHOLD);
            }
#endif

        }
        else
        {
            /*do nothing*/
        }
        EventNewStatus = DEM_EVENT_STATUS(EventId);

        /*SWS_Dem_01283*/
        if(((EventOldStatus & DEM_EVENT_MONITOR_STATUS_MASK) != (EventNewStatus & DEM_EVENT_MONITOR_STATUS_MASK)) \
            && (DEM_CFG_EVENT_KIND(EventId) == DEM_EVENT_KIND_SWC))
        {
            if(NULL_PTR != DEM_CFG_GENERAL_CBMONITOR_STATUS_CHANGE_FNC)
            {
                DemGeneralTriggerOnMonitorStatusFuncPtr = DEM_CFG_GENERAL_CBMONITOR_STATUS_CHANGE_FNC;
                (void)DemGeneralTriggerOnMonitorStatusFuncPtr(EventId);
            }
#if(DEM_MONITOR_CHANGE_CALLBACK_SUPPORT == STD_ON)
            if(NULL_PTR != DEM_CFG_MONITOR_STATUSCHANGED_CALLFNC(EventId))
            {
#if(DEM_CORE_NUMBER > 1)
                if(CoreId != DEM_CFG_EVENT_COREREF(EventId))
                {
                   DEM_CFG_EVENT_MONITOR_STATUS_FLAG(EventId) = TRUE;
                }
                else
#endif
                {
                    /*SWS_Dem_00016*/
                    (void)DEM_CFG_MONITOR_STATUSCHANGED_CALLFNC(EventId);
                }

            }
#endif
        }
    }/*if((Dem_OpCycState[DEM_CFG_EVENT_OPCYCREF(EventId)] == DEM_CYCLE_STATE_START) */
}

/*PRQA S 4700 --*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, DEM_CODE) DemInternal_DebouncePrepassed
(
    Dem_EventIdType EventId
)
{
    boolean DebounceFailed = FALSE;
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
    if(DEM_CFG_EVENT_DBC(EventId) != NULL_PTR)
    {
        if((DEM_EVENT_DBC(EventId) > DEM_CFG_EVENT_DBC_JUMPDOWN_VALUE(EventId)) \
            && (DEM_CFG_EVENT_DBC_JUMPDOWN(EventId) == TRUE))
        {
            /*SWS_Dem_00423*/
            DEM_EVENT_DBC(EventId) = DEM_CFG_EVENT_DBC_JUMPDOWN_VALUE(EventId);
        }

        if((DEM_EVENT_DBC(EventId) - DEM_CFG_EVENT_DBC_PASSTHRESHOLD(EventId)) \
            > (sint16)DEM_CFG_EVENT_DBC_DECREMENT_SIZE(EventId))
        {
            /*SWS_Dem_00419*/
            DEM_EVENT_DBC(EventId) -= (sint16)DEM_CFG_EVENT_DBC_DECREMENT_SIZE(EventId);
        }
        else
        {
            DebounceFailed = TRUE;
        }
    }
#endif

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
    if(DEM_CFG_EVENT_DBT(EventId) != NULL_PTR)
    {
        /*SWS_Dem_00432*//*SWS_Dem_00433*/
        if((DEM_EVENT_TIMERDIRECTION(EventId) != DEM_EVENT_STATUS_PREPASSED) \
            && (DEM_EVENT_TIMERDIRECTION(EventId) != DEM_EVENT_STATUS_PASSED))
        {
            DEM_EVENT_TIMERDIRECTION(EventId) = DEM_EVENT_STATUS_PREPASSED;
            DEM_EVENT_DBT(EventId) = (uint32)0;
        }
        /*SWS_Dem_00656*/
        Dem_EventDBTFreezeFlag[EventId] = FALSE;
    }
#endif
    return DebounceFailed;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, DEM_CODE) DemInternal_DebouncePrefailed
(
    Dem_EventIdType EventId
)
{
    boolean DebounceFailed = FALSE;
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
#if((DEM_EVENT_MAXFDCDCC_SUPPORT == STD_ON) || (DEM_EVENT_MAXFDCSLC_SUPPORT == STD_ON))
    sint8 EventCurrentFDC;
#endif
#if(DEM_FDC_STORAGE_SUPPORT == STD_ON)
    sint16 EventOldFdc;
    sint16 EventNewFdc;
    uint16 EventFDC;
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    uint8 EventCmaStatus;
#endif
#endif
#endif
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
    if(DEM_CFG_EVENT_DBC(EventId) != NULL_PTR)
    {
#if(DEM_FDC_STORAGE_SUPPORT == STD_ON)
        EventOldFdc = DEM_EVENT_DBC(EventId);
#endif

        if((DEM_EVENT_DBC(EventId) < DEM_CFG_EVENT_DBC_JUMPUP_VALUE(EventId)) \
            && (DEM_CFG_EVENT_DBC_JUMPUP(EventId) == TRUE))
        {
            /*SWS_Dem_00425*/
            DEM_EVENT_DBC(EventId) = DEM_CFG_EVENT_DBC_JUMPUP_VALUE(EventId);
        }

        if((DEM_CFG_EVENT_DBC_FAILTHRESHOLD(EventId) - DEM_EVENT_DBC(EventId)) \
            > (sint16)DEM_CFG_EVENT_DBC_INCREMENT_SIZE(EventId))
        {
            /*SWS_Dem_00418*/
            DEM_EVENT_DBC(EventId) += (sint16)DEM_CFG_EVENT_DBC_INCREMENT_SIZE(EventId);
        }
        else
        {
            DebounceFailed = TRUE;
            DEM_EVENT_DBC(EventId) = DEM_CFG_EVENT_DBC_FAILTHRESHOLD(EventId);
        }
#if(DEM_FDC_STORAGE_SUPPORT == STD_ON)
        EventNewFdc = DEM_EVENT_DBC(EventId);
        EventFDC = DEM_CFG_COUNTER_FDC_THRESHLD(EventId);
        if((EventOldFdc < EventFDC) && (EventNewFdc >= EventFDC))
        {
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
            EventCmaStatus = DEM_EVENT_CMA_STATUS(EventId);
            EventCmaStatus = DEM_SET_CMA_STATUS_SSLC(EventCmaStatus);
            DEM_EVENT_CMA_STATUS(EventId) = EventCmaStatus;
#endif
            if(FALSE == Dem_DTC_FirstFdcThreshold[DEM_CFG_EVENT_DTCREF(EventId)])
            {
                Dem_DTC_FirstFdcThreshold[DEM_CFG_EVENT_DTCREF(EventId)] = TRUE;
                /*SWS_Dem_00786*//*SWS_Dem_00799*//*SWS_Dem_00811*/
                DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_FDC_THRESHOLD);
            }
        }
#endif
#if((DEM_EVENT_MAXFDCDCC_SUPPORT == STD_ON) || (DEM_EVENT_MAXFDCSLC_SUPPORT == STD_ON))
        EventCurrentFDC = DEM_EVENT_DBC_F_FDC(EventId);
#if(DEM_EVENT_MAXFDCDCC_SUPPORT == STD_ON)
        /*SWS_Dem_00791*/
        if(EventCurrentFDC > DEM_EVENT_MAXFDCDCC(EventId))
        {
            DEM_EVENT_MAXFDCDCC(EventId) = EventCurrentFDC;
        }
#endif
#if(DEM_EVENT_MAXFDCSLC_SUPPORT == STD_ON)
        /*SWS_Dem_00795*/
        if(EventCurrentFDC > DEM_EVENT_MAXFDCSLC(EventId))
        {
            DEM_EVENT_MAXFDCSLC(EventId) = EventCurrentFDC;
        }
#endif
#endif
    }
#endif

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
    if(DEM_CFG_EVENT_DBT(EventId) != NULL_PTR)
    {
        /*SWS_Dem_00429*//*SWS_Dem_00430*/
        if((DEM_EVENT_TIMERDIRECTION(EventId) != DEM_EVENT_STATUS_PREFAILED) \
                && (DEM_EVENT_TIMERDIRECTION(EventId) != DEM_EVENT_STATUS_FAILED))
        {
            DEM_EVENT_TIMERDIRECTION(EventId) = DEM_EVENT_STATUS_PREFAILED;
            DEM_EVENT_DBT(EventId) = (uint32)0;
        }
        /*SWS_Dem_00656*/
        Dem_EventDBTFreezeFlag[EventId] = FALSE;
    }
#endif
    return DebounceFailed;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(void, DEM_CODE) DemInternal_SetUDSStatus
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
)
{
    Dem_UdsStatusByteType EventOldStatus;
    Dem_UdsStatusByteType EventNewStatus;
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
    Dem_UdsStatusByteType CbEventOldStatus;
    Dem_UdsStatusByteType CbEventNewStatus;
#endif
    /*SWS_Dem_00626*//*SWS_Dem_00529*//*SWS_Dem_00481*//*SWS_Dem_00482*/
    if((DEM_CURRENT_OP_STATE(DEM_CFG_EVENT_OPCYCREF(EventId)) == DEM_CYCLE_STATE_START))
    {
        EventOldStatus = DEM_EVENT_STATUS(EventId);

        if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
        {
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
            if(DEM_IS_COMBINEDDTC(DEM_CFG_EVENT_DTCREF(EventId)))
            {
                CbEventOldStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
            }
#endif
        }


        if(EventStatus == DEM_EVENT_STATUS_FAILED)
        {
            EventNewStatus = DemInternal_SetEventFail(EventId);
        }
        else if(EventStatus == DEM_EVENT_STATUS_PASSED)
        {
            EventNewStatus = DemInternal_SetEventPass(EventId);
        }
        else
        {
            /*do nothing*/
        }
        DEM_EVENT_STATUS(EventId) = EventNewStatus;

        if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
        {
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
            if(DEM_IS_COMBINEDDTC(DEM_CFG_EVENT_DTCREF(EventId)))
            {
                CbEventNewStatus = DemInternal_UpdateCombinedDTC(EventId);
            }
            else
#endif
            {
                DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId)) = EventNewStatus;
            }
        }

#if(DEM_NUM_OF_RATIO > 0)
        DemInternal_UpdateRatioNumerator(EventId);
#endif
        if(EventNewStatus != EventOldStatus)
        {
            if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
            {
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
                /*SWS_Dem_01050*/
                if(DEM_IS_COMBINEDDTC(DEM_CFG_EVENT_DTCREF(EventId)))
                {
                    if(CbEventNewStatus != CbEventOldStatus)
                    {
                        DemInternal_DTCStatusChangedNotification(DEM_CFG_DTC_VALUE(DEM_CFG_EVENT_DTCREF(EventId)), CbEventOldStatus, CbEventNewStatus);
                    }
                    DemInternal_EventStatusChangedNotification(EventId,EventOldStatus, EventNewStatus);
                }
                else
#endif
                {
                    DemInternal_DTCStatusChangedNotification(DEM_CFG_DTC_VALUE(DEM_CFG_EVENT_DTCREF(EventId)), EventOldStatus, EventNewStatus);
                    /*SWS_Dem_00284*/
                    DemInternal_EventStatusChangedNotification(EventId, EventOldStatus, EventNewStatus);
                }
            }
            else
            {
                DemInternal_EventStatusChangedNotification(EventId, EventOldStatus, EventNewStatus);
            }
        }
    }/*if((Dem_OpCycState[DEM_CFG_EVENT_OPCYCREF(EventId)] == DEM_CYCLE_STATE_START) \
          && (Dem_EnableDtcSetting[EventId] == TRUE))*/
}

#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_UpdateCombinedDTC  SWS_Dem_00441
*
* Descriptin:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(Dem_UdsStatusByteType, DEM_CODE) DemInternal_UpdateCombinedDTC
(
    Dem_EventIdType EventId
)
{

    Dem_UdsStatusByteType CbEventNewStatus;
    uint8 DtcAgingCnt;
    uint16 DtcId, i;
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
    Dem_UdsStatusByteType CbEventOldStatus;
#endif
#if(DEM_NUM_OF_STOR_GROUP > 0)
    boolean StorageCondfilled = TRUE;
#endif
    DtcId = DEM_CFG_EVENT_DTCREF(EventId);
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_ONRETRIEVAL)
    CbEventOldStatus = DEM_DTC_STATUS(DtcId);
#endif
    CbEventNewStatus = DEM_EVENT_STATUS(EventId);
    DtcAgingCnt = DEM_EVENT_AGINGCNT(EventId);

    for(i = (uint16)0; i < DEM_NUM_OF_EVENT; i++)
    {
        if(DtcId == DEM_CFG_EVENT_DTCREF(i))
        {
            CbEventNewStatus |= DEM_EVENT_STATUS(i);
#if(DEM_EVENT_MAXFDCDCC_SUPPORT == STD_ON)
            /*SWS_Dem_00672*/
            if(DEM_EVCOMB_FDC(DtcId) < DEM_EVENT_MAXFDCDCC(i))
            {
            	DEM_EVCOMB_FDC(DtcId) = DEM_EVENT_MAXFDCDCC(i);
            }
#endif
            if(DEM_EVENT_AGINGCNT(i) < DtcAgingCnt)
            {
                DtcAgingCnt = DEM_EVENT_AGINGCNT(i);
            }
        }
    }
    DEM_DTC_AGINGCNT(DtcId) = DtcAgingCnt;
    /*bit4*/
    if((DEM_TEST_UDS_STATUS_TNCSLC(CbEventNewStatus)) && (!DEM_TEST_UDS_STATUS_TFSLC(CbEventNewStatus)))
    {
        CbEventNewStatus = DEM_SET_UDS_STATUS_TNCSLC(CbEventNewStatus);
    }
    else
    {
        CbEventNewStatus = DEM_CLEAR_UDS_STATUS_TNCSLC(CbEventNewStatus);
    }
     /*bit6*/
    if((DEM_TEST_UDS_STATUS_TNCTOC(CbEventNewStatus)) && (!DEM_TEST_UDS_STATUS_TFTOC(CbEventNewStatus)))
    {
        CbEventNewStatus = DEM_SET_UDS_STATUS_TNCTOC(CbEventNewStatus);
    }
    else
    {
        CbEventNewStatus = DEM_CLEAR_UDS_STATUS_TNCTOC(CbEventNewStatus);
    }

    DEM_DTC_STATUS(DtcId) = CbEventNewStatus;

#if(DEM_NUM_OF_STOR_GROUP > 0)
    /*SWS_Dem_00455*//*SWS_Dem_00458*/
    /*SWS_Dem_00591*//*SWS_Dem_00459*/
    if(DEM_CFG_EVENT_STOR(EventId) != NULL_PTR)
    {
        for(i = (uint16)0; i < DEM_CFG_EVENT_STOR_NUM(EventId); i++)
        {
            if(Dem_EventStorCondition[(DEM_CFG_EVENT_STOR_REF(EventId)[i])] != TRUE)
            {
                StorageCondfilled = FALSE;
                break;
            }
        }
    }
    if(StorageCondfilled != FALSE)
    {
#endif
        /*SWS_Dem_00163*/
#if(DEM_EVENT_COMBINATION_SUPPORT  != DEM_EVCOMB_ONRETRIEVAL)
        if(DEM_TEST_UDS_STATUS_TF(CbEventNewStatus))
        {
            DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_EVERY_TEST_FAILED);
        }
        if((DEM_TEST_UDS_STATUS_TFTOC(CbEventNewStatus)) && (!DEM_TEST_UDS_STATUS_TFTOC(CbEventOldStatus)))
        {
            DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_TEST_FAILED_THIS_OPERATION_CYCLE);
        }
        if((DEM_TEST_UDS_STATUS_TF(CbEventNewStatus)) && (!DEM_TEST_UDS_STATUS_TF(CbEventOldStatus)))
        {
            /*SWS_Dem_00783*/
            DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_TEST_FAILED);
            /*SWS_Dem_00784*//*SWS_Dem_00922*/
            DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_PENDING);
            /*SWS_Dem_00923*/
            if(DEM_TEST_UDS_STATUS_CDTC(CbEventNewStatus))
            {
                DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_CONFIRMED);
            }
        }

        if((DEM_TEST_UDS_STATUS_CDTC(CbEventNewStatus)) && (!DEM_TEST_UDS_STATUS_CDTC(CbEventOldStatus)))
        {
            /*SWS_Dem_00785*/
            DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_CONFIRMED);
        }
#endif

#if(DEM_NUM_OF_STOR_GROUP > 0)
    }
#endif
    return CbEventNewStatus;
}
/*PRQA S 4700 --*/
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetUsableMemoryEntry
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetUsableMemoryEntry
(
    uint16 DtcId,
    uint8 DTC_ParentMemId,
    uint8 DTC_SubMemId,
    Dem_EventDisplacementStrategyType Dtc_DisplacementStrategy,
    P2VAR(Dem_MemIdType, AUTOMATIC, DEM_APPL_DATA) MemoryEntryId
)
{
    /*SWS_Dem_00810*/
    Std_ReturnType Result = E_NOT_OK;

    /*Search a free entry for the reported event.*/
    Result = DemInternal_SearchFreeEntry(DTC_ParentMemId,DTC_SubMemId,MemoryEntryId);

    if(Result != E_OK)
    {
        if(Dtc_DisplacementStrategy != DEM_DISPLACEMENT_NONE)
        {
            /*SWS_Dem_00400*//*Event displacement*/
            Result = DemInternal_SearchEntryForDisplacement(DtcId,DTC_ParentMemId,DTC_SubMemId,Dtc_DisplacementStrategy, MemoryEntryId);
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_SearchFreeEntry
*
* Description: Search a free entry for reported event.
*
* Inputs:
*
* Outputs: MemoryEntryId
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_SearchFreeEntry
(
    uint8 ParentMemId,
    uint8 SubMemId,
    P2VAR(Dem_MemIdType, AUTOMATIC, DEM_APPL_DATA) MemoryEntryId
)
{
    Std_ReturnType Result = E_NOT_OK;
    Dem_MemIdType MemIndex;
    if(SubMemId == DEM_PRIMARY_MEMORY)
    {
        /*event reference one DTC*/
        if(DEM_PRIMARY_DATAENTRY_USEDNUM(ParentMemId) < DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY(ParentMemId))
        {
            for(MemIndex = (Dem_MemIdType)0; MemIndex < DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY(ParentMemId); MemIndex++)
            {
                if(DEM_PRIMARY_DATAENTRY_USED(ParentMemId,MemIndex) == FALSE)
                {
                    DEM_PRIMARY_DATAENTRY_USED(ParentMemId,MemIndex) = TRUE;
                    *MemoryEntryId = MemIndex;
                    DEM_PRIMARY_DATAENTRY_USEDNUM(ParentMemId)++;
                    Result = E_OK;
                    break;
                }
            }
        }/*if(DEM_PRIMARY_DATAENTRY_USEDNUM < DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY)*/

    }
#if(DEM_NUM_OF_USERDEF > 0)
    else
    {
        /*DTC store in user defined memory*/

        if(DEM_USER_DEFINED_DATAENTRY_USEDNUM(ParentMemId,SubMemId) < DEM_CFG_MAXNUMBEREVENTENTRY_USERDEFINED(SubMemId) )
        {
            for(MemIndex = (Dem_MemIdType)0; MemIndex < DEM_CFG_MAXNUMBEREVENTENTRY_USERDEFINED(SubMemId); MemIndex++)
            {
                if(DEM_USERDEFINED_DATAENTRY_USED(SubMemId,MemIndex) == FALSE)
                {
                    DEM_USERDEFINED_DATAENTRY_USED(SubMemId,MemIndex) = TRUE;
                    *MemoryEntryId = MemIndex;
                    DEM_USER_DEFINED_DATAENTRY_USEDNUM(ParentMemId,SubMemId)++;
                    Result = E_OK;
                    break;
                }
            }

        }
    }
#endif

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_ClearOneMemoryEntry
*
* Description: Clear one memory entry.
*
* Inputs: MemoryEntryId
*
* Outputs: None
*
* Return: None
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_ClearOneMemoryEntry
(
    uint8 DTC_ParentMemId,
    Dem_MemIdType MemoryEntryId,
    Dem_UserdefinedIdType  UserdefinedId
)
{
#if((DEM_MAX_FFSIZE_OF_DTC > 0) || (DEM_MAX_EXTSIZE_OF_DTC > 0))
    uint16 DataIndex = (uint16)0;
#endif/*#if((DEM_MAX_FFSIZE_OF_DTC > 0) || (DEM_MAX_EXTSIZE_OF_DTC > 0))*/
    if(UserdefinedId == DEM_PRIMARY_MEMORY)
    {
        if(DEM_PRIMARY_DATAENTRY_USEDNUM(DTC_ParentMemId) > (uint8)0)
        {
            DEM_PRIMARY_DATAENTRY_USEDNUM(DTC_ParentMemId)--;
        }
        DEM_PRIMARY_DATAENTRY_USED(DTC_ParentMemId, MemoryEntryId) = FALSE;
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
        for(DataIndex = (uint16)0; DataIndex < (uint16)DEM_MAX_FFSIZE_OF_DTC; DataIndex++)
        {
            DEM_PRIMARY_FFDATA_PTR(DTC_ParentMemId,MemoryEntryId)[DataIndex] = DEM_DATA_INVALID_U8;

        }
#endif
#if(DEM_MAX_J1939FFSIZE_OF_DTC > 0)
        for(DataIndex = (uint16)0; DataIndex < DEM_MAX_J1939FFSIZE_OF_DTC; DataIndex++)
        {
            DEM_PRIMARY_J1939DTC_FFDATA_PTR(DTC_ParentMemId,MemoryEntryId)[DataIndex] = DEM_DATA_INVALID_U8;
        }
#endif
#if(DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0)
        for(DataIndex = (uint16)0; DataIndex < DEM_MAX_J1939EXPFFSIZE_OF_DTC; DataIndex++)
        {
            DEM_PRIMARY_J1939DTC_EXPFFDATA_PTR(DTC_ParentMemId,MemoryEntryId)[DataIndex] = DEM_DATA_INVALID_U8;
        }
#endif


#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
        for(DataIndex = (uint16)0; DataIndex < (uint16)DEM_MAX_EXTSIZE_OF_DTC; DataIndex++)
        {
            DEM_PRIMARY_EXTDATA_PTR(DTC_ParentMemId,MemoryEntryId)[DataIndex] = DEM_DATA_INVALID_U8;
        }
#endif
    }
    else
    {
#if(DEM_NUM_OF_USERDEF > 0)
        if(DEM_USER_DEFINED_DATAENTRY_USEDNUM(DTC_ParentMemId,UserdefinedId) > (uint8)0)
        {
            DEM_USER_DEFINED_DATAENTRY_USEDNUM(DTC_ParentMemId,UserdefinedId)--;
        }
        DEM_USERDEFINED_DATAENTRY_USED(UserdefinedId, MemoryEntryId) = FALSE;
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
        for(DataIndex = (uint16)0; DataIndex < (uint16)DEM_MAX_FFSIZE_OF_DTC; DataIndex++)
        {
            DEM_USERDEFINED_FFDATA_PTR(UserdefinedId,MemoryEntryId)[DataIndex] = DEM_DATA_INVALID_U8;

        }
#endif
#if(DEM_MAX_J1939FFSIZE_OF_DTC > 0)
        for(DataIndex = (uint16)0; DataIndex < DEM_MAX_J1939FFSIZE_OF_DTC; DataIndex++)
        {
            DEM_USERDEFINED_J1939DTC_FFDATA_PTR(UserdefinedId,MemoryEntryId)[DataIndex] = DEM_DATA_INVALID_U8;
        }
#endif
#if(DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0)
        for(DataIndex = (uint16)0; DataIndex < DEM_MAX_J1939EXPFFSIZE_OF_DTC; DataIndex++)
        {
            DEM_USERDEFINED_J1939DTC_EXPFFDATA_PTR(UserdefinedId,MemoryEntryId)[DataIndex] = DEM_DATA_INVALID_U8;
        }
#endif
#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
        for(DataIndex = (uint16)0; DataIndex < (uint16)DEM_MAX_EXTSIZE_OF_DTC; DataIndex++)
        {
            DEM_USERDEFINED_EXTDATA_PTR(UserdefinedId,MemoryEntryId)[DataIndex] = DEM_DATA_INVALID_U8;
        }
#endif
#endif
    }
}

#if(DEM_CFG_CLEARDTCBEHAIOR != DEM_CLRRESP_VOLATILE)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_ClearEntryInNvm
*
* Description: Clear one memory entry.
*
* Inputs: MemoryEntryId
*
* Outputs: None
*
* Return: None
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_ClearEntryInNvm
(
    uint16 DtcId
)
{
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    uint16 BlockId ;
    Dem_MemIdType DtcEntryRef;
    uint8 DTC_SubMemId;
    uint8 DTC_ParentMemId;
#if(DEM_EVENT_COMBINATION_SUPPORT  == DEM_EVCOMB_ONRETRIEVAL)
    Dem_EventIdType i;
#endif
    uint16 DTC_MemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId);
    DTC_ParentMemId = DEM_GET_EVENTMEMORY_ID(DTC_MemId);
    DTC_SubMemId = DEM_GET_SUBMEMORY_ID(DTC_MemId);
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
    if(DEM_DTC_DATAENTRYREF_NUM(DtcId) > (uint8)0)
    {
        for( i = (Dem_EventIdType)0 ; i < DEM_NUM_OF_EVENT; i++)
        {
            if((DEM_CFG_EVENT_DTCREF(i) == DtcId)&&(DEM_EVENT_DATAENTRYREF(i) != DEM_DATA_INVALID_U8))
            {
                DtcEntryRef = DEM_EVENT_DATAENTRYREF(i);
                BlockId = DemInternal_GetEntryBlockId(DtcId,DtcEntryRef);
                if(DTC_SubMemId == DEM_PRIMARY_MEMORY)
                {
                    if(E_OK == Dem_WriteBlock(BlockId, NULL_PTR))
                    {
                        DEM_EVENT_DATAENTRYREF(i) = DEM_DATA_INVALID_U8;
                    }
                    else
                    {
                        Dem_ClearDTCState = DEM_IN_CLEAR_DTC_ERR;
                    }
                }
#if(DEM_NUM_OF_USERDEF > 0)
                else
                {
                    if(E_OK == Dem_WriteBlock(BlockId, NULL_PTR))
                    {
                        DEM_EVENT_DATAENTRYREF(i) = DEM_DATA_INVALID_U8;
                    }
                    else
                    {
                        Dem_ClearDTCState = DEM_IN_CLEAR_DTC_ERR;
                    }
                }
#endif

            }
        }
    }
    else
#endif
    {
        DtcEntryRef = DEM_DTC_DATAENTRYREF(DtcId);
        if(DtcEntryRef != DEM_DATA_INVALID_U8)
        {
            BlockId = DemInternal_GetEntryBlockId(DtcId,DtcEntryRef);
            /*PRQA S 3112, 315, 751 ++*/
            /*
            Nvm_writeblock,Nvm_SetRamBlockStatus is the NVM standard interface.
            */
            if(DTC_SubMemId == DEM_PRIMARY_MEMORY)
            {
                if(E_OK == Dem_WriteBlock(BlockId, NULL_PTR))
                {
                    Dem_ClearDTCInfo.ClearBlockIdTable[Dem_ClearDTCInfo.ClearBlockNum] = BlockId;
                    Dem_ClearDTCInfo.ClearBlockNum ++;
                    DEM_DTC_DATAENTRYREF(DtcId) = DEM_DATA_INVALID_U8;
                }
                else
                {
                    Dem_ClearDTCState = DEM_IN_CLEAR_DTC_ERR;
                }
            }
#if(DEM_NUM_OF_USERDEF > 0)
            else
            {
                if(E_OK != Dem_WriteBlock(BlockId, NULL_PTR))
                {
                    Dem_ClearDTCState = DEM_IN_CLEAR_DTC_ERR;
                }
            }
#endif
            /*PRQA S 3112, 315, 751 --*/
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetEntryBlockId
*
* Description: Get one entry reference block Id.
*
* Inputs: MemoryEntryId
*
* Outputs: None
*
* Return: None
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint16, DEM_CODE) DemInternal_GetEntryBlockId
(
    uint16 DtcId,
    uint8 DataEntryId
)
{
    uint16 BlockId;
    uint8 DTC_ParentMemId;
    uint8 DTC_SubMemId;
    uint16 DTC_MemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId);
    DTC_ParentMemId = DEM_GET_EVENTMEMORY_ID(DTC_MemId);
    DTC_SubMemId = DEM_GET_SUBMEMORY_ID(DTC_MemId);

    if(DTC_SubMemId == DEM_PRIMARY_MEMORY)
    {
        BlockId = DEM_CFG_PRIMARY_ENTRY_BLOCKID(DTC_ParentMemId,DataEntryId);
    }
#if(DEM_NUM_OF_USERDEF > 0)
    else
    {
        BlockId = DEM_CFG_USERDEF_ENTRY_BLOCKID(DTC_SubMemId,DataEntryId);
    }
#endif
    return BlockId;
}
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetDTCGroupMaxIndex
* Description: Get one DTC group max index.
*
* Inputs: MemoryEntryId
*
* Outputs: None
*
* Return: None
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint16, DEM_CODE) DemInternal_GetDTCGroupMaxIndex
(
    void
)
{
    uint16 MaxIndexCurrentCycle;

    if(DEM_NUM_OF_DTC <= (uint16)DEM_CLEAR_NUM_PER_CYCLE)
    {
        MaxIndexCurrentCycle = DEM_NUM_OF_DTC;
    }
    else
    {
        /*PRQA S 2895 ++*/
        if((uint16)(DEM_NUM_OF_DTC - DEM_CLEAR_NUM_PER_CYCLE) > Dem_ClearDTC_Index)
        {
            MaxIndexCurrentCycle = (Dem_ClearDTC_Index + DEM_CLEAR_NUM_PER_CYCLE);
        }
        else
        {
            MaxIndexCurrentCycle = DEM_NUM_OF_DTC;
        }
        /*PRQA S 2895 --*/
    }
    return MaxIndexCurrentCycle;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_SearchEntryForDisplacement
*
* Description: Event displacement
*
* Inputs: DtcId
*
* Outputs: MemoryEntryId
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_SearchEntryForDisplacement
(
    uint16 DtcId,
    uint8 DTC_ParentMemId,
    uint8 DTC_SubMemId,
    Dem_EventDisplacementStrategyType Dtc_DisplacementStrategy,
    P2VAR(Dem_MemIdType, AUTOMATIC, DEM_APPL_DATA) MemoryEntryId
)
{
    /*SWS_Dem_00810*/
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_CFG_RESETCONFIRMEDBITONOVERFLOW == STD_ON)
    Dem_UdsStatusByteType DtcStatus;
#endif

    uint16 EventId1 = (uint16)0;
    uint16 EventId2 = (uint16)0;
    uint16 DtcIndex1 = (uint16)0;
    uint16 DtcIndex2 = (uint16)0;
    boolean DtcActive1 = TRUE;
    boolean DtcActive2 = TRUE;
    Dem_PriorityType LowestPri = DEM_CFG_DTC_PRIORITY(DtcId);

    /*SWS_Dem_00401*//*SWS_Dem_00402*/

    for(EventId1 = (uint16)0; EventId1 < DEM_NUM_OF_EVENT; EventId1++)
    {
        if(DEM_CFG_EVENT_DTCREF(EventId1) != DEM_DATA_INVALID_U16)
        {
            DtcIndex1 = DEM_CFG_EVENT_DTCREF(EventId1);

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#if(DEM_CFG_OBD_EVENT_DISPLACEMENT == STD_ON)
            if((DEM_DTC_DATAENTRYREF(DtcIndex1) != DEM_DATA_INVALID_U8)\
                && (FALSE == DemInternal_IgnoreFoundEntry(EventId1))\
                && (Dem_DtcUpDateState[DtcIndex1] != FALSE ))
#else/*#if(DEM_CFG_OBD_EVENT_DISPLACEMENT == STD_ON)*/
            if((DEM_DTC_DATAENTRYREF(DtcIndex1) != DEM_DATA_INVALID_U8) && (Dem_DtcUpDateState[DtcIndex1] != FALSE))
#endif/*#if(DEM_CFG_OBD_EVENT_DISPLACEMENT == STD_ON)*/
#else/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/
            if((DEM_DTC_DATAENTRYREF(DtcIndex1) != DEM_DATA_INVALID_U8) && (Dem_DtcUpDateState[DtcIndex1] != FALSE))
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/
            {
                /*SWS_Dem_00406*//*SWS_Dem_00403*/
                if(LowestPri < DEM_CFG_DTC_PRIORITY(DtcIndex1))
                {
                    LowestPri = DEM_CFG_DTC_PRIORITY(DtcIndex1);
                    DtcIndex2 = DtcIndex1;
                    EventId2 = EventId1;
                    *MemoryEntryId = (Dem_MemIdType)DEM_DTC_DATAENTRYREF(DtcIndex1);
                    Result = E_OK;
                }
                else if(LowestPri == DEM_CFG_DTC_PRIORITY(DtcIndex1))
                {
                    /*PRQA S 3415 ++*/
                    /*
                    DemInternal_IsDtcOlder  is an expression with possible side effects.
                    */
                    if(Dtc_DisplacementStrategy == DEM_DISPLACEMENT_FULL)
                    {
                        DtcActive1 = DemInternal_IsDtcActive(DtcIndex1);
                        /*SWS_Dem_00404*/
                        if(Result == E_NOT_OK)/*None event entry has been searched for displacement.*/
                        {
                            if(DtcActive1 == FALSE)
                            {
                                LowestPri = DEM_CFG_DTC_PRIORITY(DtcIndex1);
                                DtcIndex2 = DtcIndex1;
                                EventId2 = EventId1;
                                *MemoryEntryId = (Dem_MemIdType)DEM_DTC_DATAENTRYREF(DtcIndex1);
                                Result = E_OK;
                            }
                        }
                        else/*Has found at least one memory entry used by lower priority DTC.*/
                        {
                            DtcActive2 = DemInternal_IsDtcActive(DtcIndex2);

                            if(((DtcActive1 == FALSE) && (DtcActive2 == TRUE)) \
                                || (DemInternal_IsDtcOlder(EventId1, EventId2) != FALSE))
                            {
                                /*SWS_Dem_00405*/
                                LowestPri = DEM_CFG_DTC_PRIORITY(DtcIndex1);
                                DtcIndex2 = DtcIndex1;
                                EventId2 = EventId1;
                                *MemoryEntryId = (Dem_MemIdType)DEM_DTC_DATAENTRYREF(DtcIndex1);
                                Result = E_OK;
                            }
                        }
                    }
                    else
                    {
                        if((DEM_CFG_DTC_PRIORITY(DtcId) < DEM_CFG_DTC_PRIORITY(DtcIndex1)) \
                            && (DemInternal_IsDtcOlder(EventId1, EventId2) != FALSE))
                        {
                            /*SWS_Dem_00405*/
                            LowestPri = DEM_CFG_DTC_PRIORITY(DtcIndex1);
                            DtcIndex2 = DtcIndex1;
                            EventId2 = EventId1;
                            *MemoryEntryId = (Dem_MemIdType)DEM_DTC_DATAENTRYREF(DtcIndex1);
                            Result = E_OK;
                        }
                    }
                    /*PRQA S 3415 --*/
                }
                else
                {
                    /*do nothing*/
                }
            }
        }
    }

    /*Clear the displacement memory entry.*/
    if(Result == E_OK)
    {
        DEM_DTC_DATAENTRYREF(DtcIndex2) = DEM_DATA_INVALID_U8;
        /*SWS_Dem_00408*//*Clear the stored data*/
        DemInternal_ClearOneMemoryEntry(DTC_ParentMemId,*MemoryEntryId,DTC_SubMemId);
        if(DTC_SubMemId == DEM_PRIMARY_MEMORY)
        {
            DEM_PRIMARY_DATAENTRY_USEDNUM(DTC_ParentMemId)++;
            DEM_PRIMARY_DATAENTRY_USED(DTC_ParentMemId, *MemoryEntryId) = TRUE;
        }
#if(DEM_NUM_OF_USERDEF > 0)
        else
        {
            DEM_USER_DEFINED_DATAENTRY_USEDNUM(DTC_ParentMemId,DTC_SubMemId)++;
            DEM_USERDEFINED_DATAENTRY_USED(DTC_SubMemId, *MemoryEntryId) = TRUE;
        }
#endif

#if(DEM_CFG_RESETCONFIRMEDBITONOVERFLOW == STD_ON)
        DtcStatus = DEM_DTC_STATUS(DtcIndex2);
        /*SWS_Dem_00409*/
        DtcStatus = DEM_CLEAR_UDS_STATUS_PDTC(DtcStatus);
        DtcStatus = DEM_CLEAR_UDS_STATUS_CDTC(DtcStatus);

        /*SWS_Dem_01186*/
#if(DEM_CFG_STATUSBITHANDLING_TFSLC == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
        DtcStatus = DEM_CLEAR_UDS_STATUS_TFSLC(DtcStatus);
#endif
        DEM_DTC_STATUS(DtcIndex2) = DtcStatus;
#endif
    }

#if(DEM_CFG_RESETCONFIRMEDBITONOVERFLOW == STD_ON)
    if(Result == E_NOT_OK)
    {
        DtcStatus = DEM_DTC_STATUS(DtcId);
        DtcStatus = DEM_CLEAR_UDS_STATUS_PDTC(DtcStatus);
        DtcStatus = DEM_CLEAR_UDS_STATUS_CDTC(DtcStatus);
        DEM_DTC_STATUS(DtcId) = DtcStatus;
    }
#endif

    return Result;
}

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#if(DEM_CFG_OBD_EVENT_DISPLACEMENT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_IgnoreFoundEntry
*
* Description: Check whether the found entry should be ignored.
*
* Inputs: DtcId
*
* Outputs:
*
* Return: TRUE: active, FALSE: passive
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, DEM_CODE) DemInternal_IgnoreFoundEntry
(
    uint16 EventId
)
{
    uint8 Index;
    uint8 IndicatorId;
    uint16 StatusPos;
    boolean Ignore = FALSE;
    uint16 DTCMemId;
    uint8 ParentMemId;
    uint16 DtcId = DEM_CFG_EVENT_DTCREF(EventId);
    DTCMemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId);
    ParentMemId = DEM_GET_EVENTMEMORY_ID(DTCMemId);
    Dem_UdsStatusByteType DtcStatus = DEM_DTC_STATUS(DtcId);

    if(DEM_CFG_DTC_OBDDTCREF(DtcId) == NULL_PTR)
    {
        Ignore = TRUE;
    }
    else if(DEM_OBD_FF_EVENT == EventId)
    {
        Ignore = TRUE;
    }
    else if(DEM_TEST_UDS_STATUS_PDTC(DtcStatus))
    {
        Ignore = TRUE;
    }
    else if((DEM_CFG_EVENT_INDICATOR_NUM(EventId) > (uint8)0) \
        && (DEM_CFG_EVENT_INDICATOR(EventId) != NULL_PTR))
    {
        for(Index = (uint8)0; Index < DEM_CFG_EVENT_INDICATOR_NUM(EventId); Index++)
        {
            IndicatorId = DEM_CFG_EVENT_INDICATOR_ID(EventId,Index);
            StatusPos = DEM_CFG_EVENT_INDICATOR_OFFSET(EventId,Index) \
                            + DEM_CFG_INDICATOR_STATUS_START(IndicatorId);

            if((IndicatorId == DEM_CFG_MILINDICATORREF(ParentMemId)) \
                && (DEM_INDICATOR_STATUS(StatusPos) != DEM_INDICATOR_OFF))
            {
                Ignore = TRUE;
                break;
            }
        }
    }
    else
    {
        /*do nothing*/
    }
    return Ignore;
}
#endif
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_IsDtcActive
*
* Description: Get DTC Active/Passive status.
*
* Inputs: DtcId
*
* Outputs:
*
* Return: TRUE: active, FALSE: passive
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, DEM_CODE) DemInternal_IsDtcActive
(
    uint16 DtcId
)
{
    boolean DtcActive = TRUE;
    Dem_UdsStatusByteType DtcStatus = DEM_DTC_STATUS(DtcId);

    /*SWS_Dem_00692*//*SWS_Dem_00693*/
    if(DEM_TEST_UDS_STATUS_TF(DtcStatus))
    {
        DtcActive = TRUE;
    }
    else
    {
        DtcActive = FALSE;
    }
    return DtcActive;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_IsDtcOlder
*
* Description: Check whether the fault Event1 is older than Event2.
*
* Inputs: Event1, Event2
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, DEM_CODE) DemInternal_IsDtcOlder
(
    uint16 Event1,
    uint16 Event2
)
{
    boolean kE1OlderThanE2 = FALSE;

    if(DEM_EVENT_OCCCTR(Event1) > DEM_EVENT_OCCCTR(Event2))
    {
        kE1OlderThanE2 = TRUE;
    }
    return kE1OlderThanE2;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetEventInternalData
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(void, DEM_CODE) DemInternal_GetEventInternalData
(
    uint16 EventId,
    Dem_InternalDataElementType DataType,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Data

)
{
    uint16 DtcId = DEM_CFG_EVENT_DTCREF(EventId);
    Std_ReturnType ret = E_OK;
    uint16 EventMemId;
    uint8 ParentMemId,SubMemId;
    EventMemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId);
    ParentMemId = DEM_GET_EVENTMEMORY_ID(EventMemId);
    SubMemId = DEM_GET_SUBMEMORY_ID(EventMemId);
    /*PRQA S 715 ++*/
    if(DataType == DEM_AGINGCTR_DOWNCNT)
    {
        /*SWS_Dem_00472*//*SWS_Dem_00673*/
        if(DEM_CFG_AGINGCYCLECOUNTERTHRESHOLD(DtcId) != 0)
        {
            *Data = DEM_CFG_AGINGCYCLECOUNTERTHRESHOLD(DtcId) - DEM_DTC_AGINGCNT(DtcId);/*1 byte*/
        }
        else
        {
            /*SWS_Dem_01043*/
            *Data = DEM_DATA_U8_FF;
        }
    }
    else if(DataType == DEM_AGINGCTR_UPCNT)
    {
        /*SWS_Dem_00472*//*SWS_Dem_00643*/
        if(DEM_CFG_AGINGCYCLECOUNTERTHRESHOLD(DtcId) != 0)
        {
            *Data = DEM_DTC_AGINGCNT(DtcId);/*1 byte*/
        }
        else
        {
            /*SWS_Dem_01044*/
            *Data = (uint8)0;
        }
    }
#if(DEM_DTC_AGEDCNT_SUPPORT == STD_ON)
    else if(DataType == DEM_AGED_COUNTER)
    {
        /*User requirement*/
        *Data = DEM_DTC_AGEDCNT(DtcId);/*1 byte*/
    }
#endif
    else if(DataType == DEM_CURRENT_FDC)
    {
        /*SWS_Dem_01084*//*SWS_Dem_01045*/
        /*1 byte*/
        ret = Dem_GetFaultDetectionCounter(EventId, (sint8*) Data);
        if(ret != E_OK)
        {
            *Data = DEM_DATA_INVALID_U8;
        }
    }
#if(DEM_EVENT_CSFF_SUPPORT == STD_ON)
    else if(DataType == DEM_CYCLES_SINCE_FIRST_FAILED)
    {
        /*SWS_Dem_00821*/
        *Data = DEM_EVENT_CSFF(EventId);/*1 byte*/
    }
#endif
#if(DEM_EVENT_CSLF_SUPPORT == STD_ON)
    else if(DataType == DEM_CYCLES_SINCE_LAST_FAILED)
    {
        /*SWS_Dem_00820*/
        *Data = DEM_EVENT_CSLF(EventId);/*1 byte*/
    }
#endif
#if(DEM_EVENT_FCSLC_SUPPORT == STD_ON)
    else if(DataType == DEM_FAILED_CYCLES)
    {
        /*SWS_Dem_00822*/
        *Data = DEM_EVENT_FCSLC(EventId);/*1 byte*/
    }
#endif
#if(DEM_EVENT_MAXFDCDCC_SUPPORT == STD_ON)
    else if(DataType == DEM_MAX_FDC_DURING_CURRENT_CYCLE)
    {
        /*SWS_Dem_00788*//*SWS_Dem_00819*//*SWS_Dem_00792*/
        *Data = DEM_EVENT_MAXFDCDCC(EventId);/*1 byte*/
    }
#endif
#if(DEM_EVENT_MAXFDCSLC_SUPPORT == STD_ON)
    else if(DataType == DEM_MAX_FDC_SINCE_LAST_CLEAR)
    {
        /*SWS_Dem_00818*/
        *Data = DEM_EVENT_MAXFDCSLC(EventId);/*1 byte*/
    }
#endif
#if(DEM_MONITORDATA_SUPPORT == STD_ON)
    else if(DataType == DEM_MONITOR_DATA_0)
    {
        *Data = (uint8)(DEM_EVENT_MONITOR_DATA_0(EventId) >> 24); /*4 byte*/
        *(Data + 1) = (uint8)(DEM_EVENT_MONITOR_DATA_0(EventId) >> 16);
        *(Data + 2) = (uint8)(DEM_EVENT_MONITOR_DATA_0(EventId) >> 8);
        *(Data + 3) = (uint8)DEM_EVENT_MONITOR_DATA_0(EventId);
    }
    else if(DataType == DEM_MONITOR_DATA_1)
    {
    	 *Data = (uint8)(DEM_EVENT_MONITOR_DATA_1(EventId) >> 24); /*4 byte*/
    	 *(Data + 1) = (uint8)(DEM_EVENT_MONITOR_DATA_1(EventId) >> 16);
    	 *(Data + 2) = (uint8)(DEM_EVENT_MONITOR_DATA_1(EventId) >> 8);
    	 *(Data + 3) = (uint8)DEM_EVENT_MONITOR_DATA_1(EventId);
    }
#endif
    else if(DataType == DEM_OCCCTR)
    {
        /*SWS_Dem_00471*/
        *Data = DEM_EVENT_OCCCTR(EventId);/*1 byte*/
    }
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    else if(DataType == DEM_OBD_PASSED_CYCLES_SINCE_LAST_FAILED)
    {
        *Data = DEM_EVENT_OBD_PCSLF(EventId);
    }
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    else if(DataType == DEM_PASSED_CYCLES_SINCE_LAST_FAILED)
    {
        *Data = DEM_EVENT_CMA_PCSLF(EventId);/*1 byte*/
    }
    else if(DataType == DEM_CMA_SI30)
    {
        *Data = DEM_EVENT_CMA_STATUS(EventId);/*1 byte*/
    }
    else if(DataType == DEM_CMA_CONSECUTIVE_FAILED_CYCLES)
    {
        *Data = DEM_EVENT_FCC(EventId);/*1 byte*/
    }
#endif
    else if(DataType == DEM_OVFLIND)
    {

        /*
        Nesting of control structures (statements) exceeds 15, without modification.
        */
        if(SubMemId == DEM_PRIMARY_MEMORY)
        {
            /*SWS_Dem_00473*/
            if(DEM_PRIMARY_DATAENTRY_USEDNUM(ParentMemId) < DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY(ParentMemId))
            {
                *Data = FALSE;/*1 byte*/
            }
            else
            {
                *Data = TRUE;/*1 byte*/
            }
        }
        else
        {
#if(DEM_NUM_OF_USERDEF > 0)
            if(DEM_USER_DEFINED_DATAENTRY_USEDNUM(ParentMemId,SubMemId) < DEM_CFG_MAXNUMBEREVENTENTRY_USERDEFINED(SubMemId))
            {
                *Data = FALSE;/*1 byte*/
            }
            else
            {
                *Data = TRUE;/*1 byte*/
            }
#endif
        }

    }
    else if(DataType == DEM_SIGNIFICANCE)
    {
        /*SWS_Dem_00592*/
        *Data = (uint8)DEM_CFG_DTC_SIGNIFICANCE(DtcId);/*1 byte*/
    }
    else/*DataType == DEM_DTC_PRIORITY*/
    {
        *Data = (uint8)DEM_CFG_DTC_PRIORITY(DtcId);/*1 byte*/
    }
    /*PRQA S 715 --*/
}
/*PRQA S 4700 --*/

#if(((DEM_MAX_FFSIZE_OF_DTC > 0)&&(DEM_NUM_OF_FFRECCLASS > 0))||((DEM_MAX_EXTSIZE_OF_DTC > 0)&&(DEM_NUM_OF_EXTDATACLASS > 0))\
    || (DEM_MAX_J1939FFSIZE_OF_DTC > 0) || (DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_StorageDataElement
(
    uint16 EventId,
    uint16 DataIdx,
    P2P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataBufferPtr
)
{
#if(DEM_NUM_OF_DATA > 0)
    uint8 DataSize;
    uint8 i;
    Std_ReturnType ret = E_OK;


    if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
    {
        DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);

        DemInternal_GetEventInternalData(EventId, DEM_CFG_DATA_IN_DATA_TYPE(DataIdx), *DataBufferPtr);

        (*DataBufferPtr) += DataSize;
    }

    if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
    {
        DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
#if((DEM_CORE_NUMBER > 1) && (DEM_CSDATA_IN_MASTER_SUPPORT != STD_ON))
        if(DEM_CFG_DATA_CS_DATA_COREID(DataIdx) != DEM_MASTER_COREID)
        {
            SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_1();
            Bmc_GetSpinLock(&DEM_CFG_DATA_SPINLOCK_FLAG(DataIdx));
            for(i = (uint8)0; i < (uint8)DataSize; i++)
            {
                *((*DataBufferPtr) + i) = DEM_CFG_DATA_CS_DATA_BUFFER(DataIdx)[i];
            }
            Bmc_ReleaseSpinLock(&DEM_CFG_DATA_SPINLOCK_FLAG(DataIdx));
            SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_1();
        }
        else
#endif
        {
            /*SWS_Dem_00282*//*SWS_Dem_00918*//*SWS_Dem_00919*//*SWS_Dem_00920*/
            ret = (*DEM_CFG_DATA_CS_DATA_READ_FNC(DataIdx))(*DataBufferPtr);
        }
        /*SWS_Dem_00463*/
        if(ret != E_OK)
        {
            for(i = (uint8)0; i < (uint8)DataSize; i++)
            {
                *((*DataBufferPtr) + i) = DEM_DATA_INVALID_U8;
            }
            /*SWS_Dem_00370*/
            DEM_DET_REPORT_ERROR(DEM_MAINFUNCTION_APIID, DEM_E_NODATAAVAILABLE);
        }
        (*DataBufferPtr) += DataSize;
    }
#endif
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetDtcInternalData
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_GetDtcInternalData
(
    uint16 DtcId,
    uint16 DataIdx,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Data
)
{
#if(DEM_NUM_OF_DATA > 0)
    Dem_EventIdType EventId;

    for(EventId = (Dem_EventIdType)0; EventId < DEM_NUM_OF_EVENT; EventId++)
    {
        if(DtcId == DEM_CFG_EVENT_DTCREF(EventId))
        {
            DemInternal_GetEventInternalData(EventId, DEM_CFG_DATA_IN_DATA_TYPE(DataIdx), Data);
            break;
        }
    }
#endif
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************ternal_cap
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_CaptureData
(
    uint16 EventId
)
{
    Dem_MemIdType MemEntryId;
    uint16 DtcId,DTC_MemId;
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
    uint16 i;
#endif
    uint8 DTC_ParentMemId,DTC_SubMemId;
    Dem_EventMemoryEntryStorageTriggerType Trigger, Trigger1;
    boolean ExtDataChangedFlag = FALSE;
    boolean FFDataChangedFlag = FALSE;
    Dem_EventDisplacementStrategyType Dtc_DisplacementStrategy;

    (void)DemInternal_GetCaptureQueue(EventId, &Trigger);
    DemInternal_ClrCaptureQueue(EventId);
    DtcId = DEM_CFG_EVENT_DTCREF(EventId);
    DTC_MemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId);
    DTC_ParentMemId = DEM_GET_EVENTMEMORY_ID(DTC_MemId);
    DTC_SubMemId = DEM_GET_SUBMEMORY_ID(DTC_MemId);
    if(DTC_SubMemId == DEM_PRIMARY_MEMORY)
    {
        Trigger1 = DEM_CFG_PRIMARY_EVENTMEMORYTRIGGER(DTC_ParentMemId);
        Dtc_DisplacementStrategy = DEM_CFG_PRIMARY_EVENTDISPLACEMENTSTRATEGY(DTC_ParentMemId);
    }
#if(DEM_NUM_OF_USERDEF > 0)
    else
    {
        Trigger1 = DEM_CFG_USERDEF_EVENTMEMORYTRIGGER(DTC_SubMemId);
        Dtc_DisplacementStrategy = DEM_CFG_USERDEF_EVENTDISPLACEMENTSTRATEGY(DTC_SubMemId);
    }
#endif
    /*DemEventMemoryEntryStorageTrigger: used to allocate an event memory entry.*/
    /*SWS_Dem_00783*//*SWS_Dem_00784*/
    /*SWS_Dem_00922*//*SWS_Dem_00785*/
    /*SWS_Dem_00786*//*SWS_Dem_00810*/
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
    if(((DEM_DTC_DATAENTRYREF(DtcId) == DEM_DATA_INVALID_U8)\
        &&(DEM_DTC_DATAENTRYREF_NUM(DtcId) == (uint8)0)) \
        && (Trigger >= Trigger1))
#else
    if((DEM_DTC_DATAENTRYREF(DtcId) == DEM_DATA_INVALID_U8)\
        && (Trigger >= Trigger1))
#endif
    {
        if(E_OK == DemInternal_GetUsableMemoryEntry(DtcId,DTC_ParentMemId,DTC_SubMemId,Dtc_DisplacementStrategy,&MemEntryId))
        {
            /*SWS_Dem_00523*/
            DEM_EVENT_OCCCTR(EventId) = (uint8)1;
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
            if(DEM_IS_COMBINEDDTC(DtcId))
            {
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
                DEM_EVENT_DATAENTRYREF(EventId) = MemEntryId;
                DEM_DTC_DATAENTRYREF_NUM(DtcId)++;
#else
                for(i = (uint16)0 ; i < DEM_NUM_OF_EVENT; i++)
                {
                    if(DtcId == DEM_CFG_EVENT_DTCREF(i))
                    {
                        DEM_EVENT_DATAENTRYREF(i) = MemEntryId;
                    }
                }
                DEM_DTC_DATAENTRYREF(DtcId) = MemEntryId;
#endif
            }
            else
#endif
            {
                DEM_DTC_DATAENTRYREF(DtcId) = MemEntryId;
            }
        }
        else
        {
#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
            /*SWS_Dem_00969*/
            Dem_PreStorageFFFlag[EventId] = FALSE;
#endif
            DEM_EVENT_FCC(EventId) = DEM_DATA_CLEAR;
            DEM_EVENT_OCCCTR(EventId) = DEM_DATA_CLEAR;
#if(DEM_EVENT_MAXFDCDCC_SUPPORT == STD_ON)
            DEM_EVENT_MAXFDCDCC(EventId) = (sint8)0;
#endif
#if(DEM_EVENT_MAXFDCSLC_SUPPORT == STD_ON)
            DEM_EVENT_MAXFDCSLC(EventId) = (sint8)0;
#endif
#if(DEM_EVENT_CSLF_SUPPORT == STD_ON)
            DEM_EVENT_CSLF(EventId) = DEM_DATA_CLEAR;
#endif
#if(DEM_EVENT_CSFF_SUPPORT == STD_ON)
            DEM_EVENT_CSFF(EventId) = DEM_DATA_CLEAR;
#endif
#if(DEM_EVENT_FCSLC_SUPPORT == STD_ON)
            DEM_EVENT_FCSLC(EventId) = DEM_DATA_CLEAR;
#endif
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
            DEM_EVENT_OBD_PCSLF(EventId) = DEM_DATA_CLEAR;
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
            DEM_EVENT_CMA_PCSLF(EventId) = DEM_DATA_CLEAR;
#endif
        }
    }

    /*Store data for the first time or Update Record*/
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
    if((DEM_DTC_DATAENTRYREF(DtcId) != DEM_DATA_INVALID_U8)\
        ||(DEM_EVENT_DATAENTRYREF(EventId) != DEM_DATA_INVALID_U8))
#else
    if(DEM_DTC_DATAENTRYREF(DtcId) != DEM_DATA_INVALID_U8)
#endif
    {
        /*SWS_Dem_00270: The function Dem_DcmDisableDTCRecordUpdate
        shall protect the event related data of the specified DTC
        within the specified origin from updating or deleting.*/
        if(Dem_DtcUpDateState[DtcId] == TRUE)
        {
#if((DEM_MAX_FFSIZE_OF_DTC > 0) && (DEM_NUM_OF_FFRECCLASS > 0) \
    || ((DEM_MAX_J1939FFSIZE_OF_DTC > 0) || (DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0)))
            /*SWS_Dem_00464*/
#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
            if(Dem_PreStorageFFFlag[EventId] == TRUE)
            {
                FFDataChangedFlag = DemInternal_CopyPreStorageFFData(EventId,DTC_ParentMemId,DTC_SubMemId,MemEntryId);

            }
            else
#endif
            {
                /*SWS_Dem_00191*/
                /*Update FreezeFrameData*/
                FFDataChangedFlag = DemInternal_UpdateFFData(EventId, Trigger);
            }
#endif

#if((DEM_MAX_EXTSIZE_OF_DTC > 0) && (DEM_NUM_OF_EXTDATACLASS > 0))
            /*Update Extended Data*/
            ExtDataChangedFlag = DemInternal_UpdateExtData(EventId, Trigger);
#endif
        }

    }
    else
    {
        /*SWS_Dem_00407*/
    }
    if((FFDataChangedFlag == TRUE) || (ExtDataChangedFlag == TRUE))
    {
#if(DEM_EVENT_DATA_CHANGE_CALLBACK_SUPPORT == STD_ON)
        /*SWS_Dem_00475*/
        if(DEM_CFG_EVENT_DATACHANGED_CALLFNC(EventId) != NULL_PTR)
        {
#if(DEM_CORE_NUMBER > 1)
            if(DEM_MASTER_COREID != DEM_CFG_EVENT_COREREF(EventId))
            {
                DEM_CFG_EVENT_DATA_CHANGE_FLAG(EventId) = TRUE;
            }
            else
#endif
            {
                (void)(*DEM_CFG_EVENT_DATACHANGED_CALLFNC(EventId))();
            }
        }
#endif
    }
}

#if((DEM_MAX_FFSIZE_OF_DTC > 0) && (DEM_NUM_OF_FFRECCLASS > 0) \
    || ((DEM_MAX_J1939FFSIZE_OF_DTC > 0) || (DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0)))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_UpdateFFData
*
* Description: Update the Freeze Frame Data of one Event/DTC.
*
* Inputs: EventId, Trigger
*
* Outputs:
*
* Return: TRUE: Data has been changed. FALSE:No data changed.
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(boolean, DEM_CODE) DemInternal_UpdateFFData
(
    uint16 EventId,
    Dem_EventMemoryEntryStorageTriggerType Trigger
)
{
    boolean DataChangedFlag = FALSE;
    uint8 RecIdx;
    uint8 i;
    uint8 j;
    uint16 DataIdx;
    uint8 *DataBufferPtr;
    uint8 RecNum;
    uint8 DidIdx;
    uint16 DID;
    uint8 k;
    Dem_TypeOfFreezeFrameRecordNumerationType Kind;
    uint8 NumOfFFrec = (uint8)0;
    boolean StoreData;
    uint8 NumOfDID;
    const uint8 *DIDarray;
#if((DEM_MAX_J1939FFSIZE_OF_DTC > 0) || (DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0))
    uint16 SPNIndex;
#endif
    Dem_MemIdType  MemEntryId;
    uint16 DtcId = DEM_CFG_EVENT_DTCREF(EventId);
    uint16 DTC_MemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId);
    uint8 DTC_ParentMemId = DEM_GET_EVENTMEMORY_ID(DTC_MemId);
    DTC_MemId = DEM_GET_SUBMEMORY_ID(DTC_MemId);
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
    if(DEM_IS_COMBINEDDTC(DtcId))
    {
        MemEntryId = DEM_EVENT_DATAENTRYREF(EventId);
    }
    else
#endif
    {
        MemEntryId = DEM_DTC_DATAENTRYREF(DtcId);
    }
#if(DEM_NUM_OF_FFRECCLASS > 0)
    if(DEM_CFG_DTC_FFRECNUMCLASSREF(DtcId) != NULL_PTR)
    {
        if(DTC_MemId == DEM_PRIMARY_MEMORY)
        {
            DataBufferPtr = DEM_PRIMARY_FFDATA_PTR(DTC_ParentMemId,MemEntryId);
            if(DEM_CFG_PRIMARY_TYPE_OF_FF_RECORD_NUMERATION(DTC_ParentMemId) == DEM_FF_RECNUM_CONFIGURED)
            {
                NumOfFFrec = DEM_CFG_DTC_NUM_OF_FFREC(DtcId);
                Kind = DEM_FF_RECNUM_CONFIGURED;
            }
        }
#if(DEM_NUM_OF_USERDEF > 0)
        else
        {
            DataBufferPtr = DEM_USERDEFINED_FFDATA_PTR(DTC_MemId,MemEntryId);
            if(DEM_CFG_USERDEF_TYPE_OF_FF_RECORD_NUMERATION(DTC_MemId) == DEM_FF_RECNUM_CONFIGURED)
            {
                NumOfFFrec = DEM_CFG_DTC_NUM_OF_FFREC(DtcId);
                Kind = DEM_FF_RECNUM_CONFIGURED;
            }
        }
#endif
    }/*if(DEM_CFG_DTC_FFRECNUMCLASSREF(DtcId) != NULL_PTR)*/
#endif
#if(DEM_NUM_OF_FFCLASS > 0)
    if(DEM_CFG_DTC_MAXNUMFFREC(DtcId) > (uint8)0)
    {
        if(DTC_MemId == DEM_PRIMARY_MEMORY)
        {
            DataBufferPtr = DEM_PRIMARY_FFDATA_PTR(DTC_ParentMemId,MemEntryId);
            if(DEM_CFG_PRIMARY_TYPE_OF_FF_RECORD_NUMERATION(DTC_ParentMemId) == DEM_FF_RECNUM_CALCULATED)
            {
                NumOfFFrec = DEM_CFG_DTC_MAXNUMFFREC(DtcId);
                Kind = DEM_FF_RECNUM_CALCULATED;
            }
        }
#if(DEM_NUM_OF_USERDEF > 0)
        else
        {
            DataBufferPtr = DEM_USERDEFINED_FFDATA_PTR(DTC_MemId,MemEntryId);
            if(DEM_CFG_USERDEF_TYPE_OF_FF_RECORD_NUMERATION(DTC_MemId) == DEM_FF_RECNUM_CALCULATED)
            {
                NumOfFFrec = DEM_CFG_DTC_MAXNUMFFREC(DtcId);
                Kind = DEM_FF_RECNUM_CALCULATED;
            }
        }
#endif
    }
#endif
    RecNum = (uint8)0;

    for(i = (uint8)0; i < NumOfFFrec; i++)
    {
        StoreData = FALSE;
#if(DEM_NUM_OF_FFRECCLASS > 0)
        if(Kind == DEM_FF_RECNUM_CONFIGURED)
        {
            /*SWS_Dem_00582*/
            RecIdx = (DEM_CFG_DTC_FFREC_ARRAY(DtcId)[i]);
            RecNum = DEM_CFG_DTC_FFRECNUM(RecIdx);
            NumOfDID = DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx);
            DIDarray = DEM_CFG_DIDARRAY_OF_FFRECNUM(RecIdx);
            if(((DEM_CFG_DTC_FFREC_UPDATA(RecIdx) == DEM_UPDATE_RECORD_YES) \
                || ((DEM_CFG_DTC_FFREC_UPDATA(RecIdx) == DEM_UPDATE_RECORD_NO) \
                && (*DataBufferPtr == DEM_DATA_INVALID_U8))) \
                && (((DEM_CFG_DTC_FFREC_TRIGGER(RecIdx))&Trigger) != 0))
            {
                StoreData = TRUE;
            }
        }
#endif
#if(DEM_NUM_OF_FFCLASS > 0)
        else
        {
            RecIdx = DEM_CFG_DTC_FFCLASSREF(DtcId);
            RecNum ++;
            NumOfDID =  DEM_CFG_NUMDID_OF_FFNUM(RecIdx);
            DIDarray = DEM_CFG_DIDARRAY_OF_FFNUM(RecIdx);
            if(((*DataBufferPtr == DEM_DATA_INVALID_U8) \
                || ((RecNum + (uint8)1) == NumOfFFrec))
                && ((DEM_TRIGGER_ON_TEST_FAILED & Trigger) != 0))
            {
                StoreData = TRUE;
            }
        }
#endif
        /*DemFreezeFrameRecordTrigger: Defines the trigger to store the FreezeFrameRecord*/
        if(StoreData == TRUE)
        {
            DataChangedFlag = TRUE;
            /*DemFreezeFrameRecordTrigger: Defines the trigger to store the FreezeFrameRecord*/
            *DataBufferPtr = RecNum;
            *(DataBufferPtr + (uint8)1) = NumOfDID;
            DataBufferPtr += (uint8)DEM_DATA_LENGTH_2;

            for(j = (uint8)0; j < NumOfDID; j++)
            {
                DidIdx = DIDarray[j];
                DID = DEM_CFG_DID(DidIdx);
                /*+ RecNum length(one byte) + RecordNumberOfIdentifiers length(one byte)*/
                *DataBufferPtr = ((uint8)(DID >> DEM_DATA_8));
                *(DataBufferPtr + (uint8)1) = ((uint8)DID);
                DataBufferPtr += (uint8)DEM_DATA_LENGTH_2;

                for(k = (uint8)0; k < (uint8)DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                {
                    DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);
                    /*Did length(two bytes)*/
                    DemInternal_StorageDataElement(EventId, DataIdx, &DataBufferPtr);
                }
            }
            if(Kind == DEM_FF_RECNUM_CALCULATED)
            {
                break;
            }
        }
        else
        {
            /*+ RecNum length(one byte) + RecordNumberOfIdentifiers length(one byte)*/
            DataBufferPtr += (uint8)DEM_DATA_LENGTH_2;

            for(j = (uint8)0; j < NumOfDID; j++)
            {

                DidIdx = DIDarray[j];
                /*+ RecNum length(one byte) + RecordNumberOfIdentifiers length(one byte)*/
                DataBufferPtr += (uint8)DEM_DATA_LENGTH_2;

                for(k = (uint8)0; k < (uint8)DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                {
                    DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);

                    if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                    {
                        DataBufferPtr += DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                    }

                    if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                    {
                        DataBufferPtr += DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                    }
                }
            }
        }
    }/*if(DEM_CFG_DTC_FFRECNUMCLASSREF(DtcId) != NULL_PTR)*/

#if(DEM_MAX_J1939FFSIZE_OF_DTC > 0)
    if(DEM_CFG_J1939DTC_FFRECNUMCLASSREF(DtcId) != NULL_PTR)
    {
        if(DTC_MemId == DEM_PRIMARY_MEMORY)
        {
            DataBufferPtr = DEM_PRIMARY_J1939DTC_FFDATA_PTR(DTC_ParentMemId,MemEntryId);
        }
#if(DEM_NUM_OF_USERDEF > 0)
        else
        {
            DataBufferPtr = DEM_USERDEFINED_J1939DTC_FFDATA_PTR(DTC_MemId,MemEntryId);
        }
#endif
        DataChangedFlag = TRUE;
        for(i = (uint8)0; i < DEM_CFG_J1939DTC_NUM_OF_FFSPNC(DtcId); i++)
        {
            SPNIndex = DEM_CFG_J1939DTC_FFSPNC_ARRAY(DtcId)[i];
            DataIdx = DEM_CFG_DATAARRAY_OF_FFSPN(SPNIndex);
            DemInternal_StorageDataElement(EventId, DataIdx, &DataBufferPtr);
        }
    }
#endif
#if(DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0)
    if( DEM_CFG_1939DTC_EXPFFRECNUMCLASSREF(DtcId) != NULL_PTR)
    {
        if(DTC_MemId == DEM_PRIMARY_MEMORY)
        {
            DataBufferPtr = DEM_PRIMARY_J1939DTC_EXPFFDATA_PTR(DTC_ParentMemId,MemEntryId);
        }
#if(DEM_NUM_OF_USERDEF > 0)
        else
        {
            DataBufferPtr = DEM_USERDEFINED_J1939DTC_EXPFFDATA_PTR(DTC_MemId,MemEntryId);
        }
#endif
        DataChangedFlag = TRUE;
        for(i = (uint8)0; i < DEM_CFG_J1939DTC_NUM_OF_EXPFFSPNC(DtcId); i++)
        {
            SPNIndex = DEM_CFG_J1939DTC_EXPFFSPNC_ARRAY(DtcId)[i];
            DataIdx = DEM_CFG_DATAARRAY_OF_FFSPN(SPNIndex);
            DemInternal_StorageDataElement(EventId, DataIdx, &DataBufferPtr);
        }
    }
#endif
    return DataChangedFlag;
}
/*PRQA S 4700 --*/
#endif
#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_CopyPreStorageFFData
*
* Description: PreStorge the Freeze Frame Data of one Event.
*
* Inputs: EventId
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, DEM_CODE) DemInternal_CopyPreStorageFFData
(
    uint16 EventId,
	uint8 MemId,
    uint8 SubMemId,
    uint8 MemEntryId
)
{

    uint8 *DataBufferPtr;
    uint16 i;
    boolean DataChangedFlag = TRUE;
    uint8 PreStoFFEntry = DEM_EVEVT_PRESTO_FF_ENTRY(EventId);

    if(SubMemId == DEM_PRIMARY_MEMORY)
    {
        DataBufferPtr = DEM_PRIMARY_FFDATA_PTR(MemId,MemEntryId);
    }
#if(DEM_NUM_OF_USERDEF > 0)
    else
    {
        DataBufferPtr = DEM_USERDEFINED_FFDATA_PTR(SubMemId,MemEntryId);
    }
#endif

    for(i = (uint16)0; i < (uint16)DEM_MAX_FFSIZE_OF_DTC; i++ )
    {
        *(DataBufferPtr + i) = DEM_PRESTORE_FFENTRY(PreStoFFEntry).PreStorageFFData[i];
    }
    /*SWS_Dem_00969*/
    DEM_PRESTORE_FFENTRY_EVENTID(PreStoFFEntry) = DEM_DATA_CLEAR;
    DEM_PRESTORE_FFENTRY_USED(PreStoFFEntry) = FALSE;
    DEM_EVEVT_PRESTO_FF_ENTRY(EventId) = DEM_DATA_INVALID_U8;
    Dem_UsedNumOfPreStorageFF--;
    Dem_PreStorageFFFlag[EventId] = FALSE;
    return DataChangedFlag;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_PreStorageFFData
*
* Description: PreStorge the Freeze Frame Data of one Event.
*
* Inputs: EventId
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void , DEM_CODE)DemInternal_PreStorageFFData
(
    uint16 EventId,
    uint8 EntryId
)
{
    uint8 RecIdx;
    uint8 i;
    uint8 j;
    uint16 DataIdx;
    uint8 *DataBufferPtr;
    uint8 RecNum = (uint8)0;
    uint8 DidIdx;
    uint16 DID;
    uint8 k;
    uint16 DtcId = DEM_CFG_EVENT_DTCREF(EventId);
    uint16 DTC_MemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId);
    uint8 DTC_ParentMemId = DEM_GET_EVENTMEMORY_ID(DTC_MemId);
    DTC_MemId = DEM_GET_SUBMEMORY_ID(DTC_MemId);
    DataBufferPtr = DEM_PRESTORE_FFENTRY(EntryId).PreStorageFFData;
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
    for(i = (uint8)0; i < DEM_CFG_DTC_NUM_OF_FFREC(DtcId); i++)
    {
        RecIdx = (DEM_CFG_DTC_FFREC_ARRAY(DtcId)[i]);
        if(DTC_MemId == DEM_PRIMARY_MEMORY)
        {
            if(DEM_CFG_PRIMARY_TYPE_OF_FF_RECORD_NUMERATION(DTC_ParentMemId) == DEM_FF_RECNUM_CONFIGURED)
            {
                /*SWS_Dem_00582*/
                RecNum = DEM_CFG_DTC_FFRECNUM(RecIdx);
            }
            else
            {
                /*SWS_Dem_00337*//*SWS_Dem_00581*/
                RecNum++;
            }
        }
#if(DEM_NUM_OF_USERDEF > 0)
        else
        {
            if(DEM_CFG_USERDEF_TYPE_OF_FF_RECORD_NUMERATION(DTC_MemId) == DEM_FF_RECNUM_CONFIGURED)
            {
                /*SWS_Dem_00582*/
                RecNum = DEM_CFG_DTC_FFRECNUM(RecIdx);
            }
            else
            {
                /*SWS_Dem_00337*//*SWS_Dem_00581*/
                RecNum++;
            }
        }
#endif

        /*+ RecNum length(one byte) + RecordNumberOfIdentifiers length(one byte)*/
        *(DataBufferPtr + (uint32)1) = DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx);
        DataBufferPtr += (uint8)DEM_DATA_LENGTH_2;

        for(j = (uint8)0; j < DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx); j++)
        {
            DidIdx = (DEM_CFG_DIDARRAY_OF_FFRECNUM(RecIdx)[j]);
            DID = DEM_CFG_DID(DidIdx);
            /*Did length(two bytes)*/
            *DataBufferPtr = ((uint8)(DID >> DEM_DATA_8));
            *(DataBufferPtr + (uint32)1) = ((uint8)DID);
            DataBufferPtr += (uint8)DEM_DATA_LENGTH_2;

            for(k = (uint8)0; k < DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
            {
                DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);
                /*SWS_Dem_00261*/
                DemInternal_StorageDataElement(EventId, DataIdx, &DataBufferPtr);
            }
        }

    }/*for(i = 0; i < DEM_CFG_DTC_NUM_OF_FFREC(DtcId); i++)*/
#endif
}
#endif
#if((DEM_MAX_EXTSIZE_OF_DTC > 0) && (DEM_NUM_OF_EXTDATACLASS > 0))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_UpdateExtData
*
* Description: Update the Extended Data of one Event/DTC.
*
* Inputs: EventId, Trigger
*
* Outputs:
*
* Return: TRUE: Data has been changed. FALSE:No data changed.
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, DEM_CODE) DemInternal_UpdateExtData
(
    uint16 EventId,
    Dem_EventMemoryEntryStorageTriggerType Trigger
)
{
    boolean DataChangedFlag = FALSE;
    uint8 RecIdx;
    uint8 i;
    uint8 j;
    uint16 DataIdx;
    uint8 *DataBufferPtr;
    Dem_MemIdType MemEntryId;
    uint16 DtcId = DEM_CFG_EVENT_DTCREF(EventId);
    uint16 MemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId);
    uint8 DTC_ParentMemId = DEM_GET_EVENTMEMORY_ID(MemId);
    uint8 DTC_MemId = DEM_GET_SUBMEMORY_ID(MemId);
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
    if(DEM_IS_COMBINEDDTC(DtcId))
    {
        MemEntryId = DEM_EVENT_DATAENTRYREF(EventId);
    }
    else
#endif
    {
        MemEntryId = DEM_DTC_DATAENTRYREF(DtcId);
    }
    if(DEM_CFG_DTC_EXTDATACLASSREF(DtcId) != NULL_PTR)
    {
        if(DTC_MemId == DEM_PRIMARY_MEMORY)
        {
            DataBufferPtr = DEM_PRIMARY_EXTDATA_PTR(DTC_ParentMemId, MemEntryId);
        }
#if(DEM_NUM_OF_USERDEF > 0)
        else
        {
            DataBufferPtr = DEM_USERDEFINED_EXTDATA_PTR(DTC_MemId, MemEntryId);
        }
#endif
        for(i = (uint8)0; i < (uint8)DEM_CFG_DTC_NUM_OF_EXTREC(DtcId); i++)
        {
            RecIdx = (DEM_CFG_DTC_EXTREC_ARRAY(DtcId)[i]);
            /*SWS_Dem_00809*//*SWS_Dem_00811*/
            /*SWS_Dem_01069*//*SWS_Dem_00812*/
            /*SWS_Dem_00813*//*SWS_Dem_00814*/
            /*SWS_Dem_00815*//*SWS_Dem_00816*/
            if(((DEM_CFG_DTC_EXTREC_UPDATA(RecIdx) == DEM_UPDATE_RECORD_YES) \
                || ((DEM_CFG_DTC_EXTREC_UPDATA(RecIdx) == DEM_UPDATE_RECORD_NO) \
                    && (*DataBufferPtr == DEM_DATA_INVALID_U8))) \
                && (((DEM_CFG_DTC_EXTREC_TRIGGER(RecIdx))&Trigger) != 0))
            {
                DataChangedFlag = TRUE;
                /*+ DataRecNum length(one byte)*/
                *DataBufferPtr = DEM_CFG_DTC_EXTRECNUM(RecIdx);
                DataBufferPtr += (uint8)1;

                for(j = (uint8)0; j < (uint8)DEM_CFG_NUMDATA_OF_EXTRECNUM(RecIdx); j++)
                {
                    DataIdx = (DEM_CFG_DATAARRAY_OF_EXTRECNUM(RecIdx)[j]);
                    /*SWS_Dem_00468*/
                    DemInternal_StorageDataElement(EventId, DataIdx, &DataBufferPtr);
                }
            }
            else
            {
                /*+ DataRecNum length(one byte)*/
                DataBufferPtr += (uint8)1;

                for(j = (uint8)0; j < (uint8)DEM_CFG_NUMDATA_OF_EXTRECNUM(RecIdx); j++)
                {
                    DataIdx = (DEM_CFG_DATAARRAY_OF_EXTRECNUM(RecIdx)[j]);

                    if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                    {
                        DataBufferPtr += DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                    }

                    if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                    {
                        DataBufferPtr += DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                    }
                }
            }
        }
    }

    return DataChangedFlag;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(void, DEM_CODE) DemInternal_CycleStartProcess
(
    uint8 OperationCycleId
)
{
    Dem_EventIdType EventId;
    uint16 DtcId;
    Dem_UdsStatusByteType EventOldStatus;
    Dem_UdsStatusByteType EventNewStatus;
    Dem_UdsStatusByteType DTCOldStatus;
    Dem_UdsStatusByteType DTCNewStatus;
    Dem_DemGeneralTriggerOnMonitorStatusType DemGeneralTriggerOnMonitorStatusFuncPtr;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
#if(DEM_NUM_OF_RATIO > 0)
    Dem_RatioIdType RatioID;
#endif

    for(EventId = (Dem_EventIdType)0; EventId < DEM_NUM_OF_EVENT; EventId++)
    {
        if(OperationCycleId == DEM_CFG_EVENT_OPCYCREF(EventId))
        {
            EventOldStatus = DEM_EVENT_STATUS(EventId);
            EventNewStatus = DEM_EVENT_STATUS(EventId);
            if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
            {
                DtcId = DEM_CFG_EVENT_DTCREF(EventId);
                DTCOldStatus = DEM_DTC_STATUS(DtcId);
                DTCNewStatus = DEM_DTC_STATUS(DtcId);
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
                Dem_DTC_FirstFdcThreshold[DEM_CFG_EVENT_DTCREF(EventId)] = FALSE;
#endif
            }

#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
            /*SWS_Dem_00674*//*SWS_Dem_00675*/
            if((DEM_CFG_EVENT_DBC(EventId) != NULL_PTR) && (DEM_CFG_EVENT_DBC_STORAGE(EventId) != TRUE))
            {
                /*SWS_Dem_00344*/
                DEM_EVENT_DBC(EventId) = (sint16)0;
            }
#endif

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
            DEM_EVENT_DBT(EventId) = (uint32)0;
            DEM_EVENT_TIMERDIRECTION(EventId) = DEM_DATA_INVALID_U8;
            Dem_EventDBTFreezeFlag[EventId] = FALSE;
#endif

#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
            if((!DEM_TEST_UDS_STATUS_TFTOC(EventNewStatus)) && (!DEM_TEST_UDS_STATUS_TNCTOC(EventNewStatus)))
            {
                DEM_EVENT_FCC(EventId) = (uint8)DEM_DATA_CLEAR;
            }
#endif
#if(DEM_EVENT_MAXFDCDCC_SUPPORT == STD_ON)
            /*SWS_Dem_00790 The maximum FDC during current operation cycle
            shall be reset to zero with each (re-)start operation cycle.*/
            DEM_EVENT_MAXFDCDCC(EventId) = (sint8)DEM_DATA_CLEAR;
#endif
            /*clear bit1 TestFailedThisOperationCycle*//*SWS_Dem_00389*/
            EventNewStatus = DEM_CLEAR_UDS_STATUS_TFTOC(EventNewStatus);
#if(DEM_CFG_STATUSBITSTORAGE_TF != STD_ON)
            /*clear bit0 TestFailed*//*SWS_Dem_00525*/
            EventNewStatus = DEM_CLEAR_UDS_STATUS_TF(EventNewStatus);
#endif
            /*set bit6 testNotCompletedThisOperationCycle*//*SWS_Dem_00394*/
            EventNewStatus = DEM_SET_UDS_STATUS_TNCTOC(EventNewStatus);
            DEM_EVENT_STATUS(EventId) = EventNewStatus;

            if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
            {
#if(DEM_EVENT_COMBINATION_SUPPORT  != DEM_EVCOMB_DISABLED)
                if(!DEM_IS_COMBINEDDTC(DEM_CFG_EVENT_DTCREF(EventId)))
                {
#endif
#if(DEM_DTC_LASTSTATUS_SUPPORT == STD_ON)
                    /*save the current and last operation cycle status*/
                    DEM_DTC_LASTSTATUS(DtcId) = EventNewStatus;
#endif
                    DEM_DTC_STATUS(DtcId) = EventNewStatus;
                    DTCNewStatus = EventNewStatus;
#if(DEM_EVENT_COMBINATION_SUPPORT  != DEM_EVCOMB_DISABLED)
                }
#endif
            }

            if((EventOldStatus & DEM_EVENT_MONITOR_STATUS_MASK) != (EventNewStatus & DEM_EVENT_MONITOR_STATUS_MASK))
            {
                if(NULL_PTR != DEM_CFG_GENERAL_CBMONITOR_STATUS_CHANGE_FNC)
                {
                    DemGeneralTriggerOnMonitorStatusFuncPtr = DEM_CFG_GENERAL_CBMONITOR_STATUS_CHANGE_FNC;
                    (void)DemGeneralTriggerOnMonitorStatusFuncPtr(EventId);
                }
#if(DEM_MONITOR_CHANGE_CALLBACK_SUPPORT == STD_ON)
                if(NULL_PTR != DEM_CFG_MONITOR_STATUSCHANGED_CALLFNC(EventId))
                {
#if(DEM_CORE_NUMBER > 1)
                    if(CoreId != DEM_CFG_EVENT_COREREF(EventId))
                    {
                        DEM_CFG_EVENT_MONITOR_STATUS_FLAG(EventId) = TRUE;
                    }
                    else
#endif
                    {
                    /*SWS_Dem_00016*/
                        (void)DEM_CFG_MONITOR_STATUSCHANGED_CALLFNC(EventId);
                    }
                }
#endif
            }

            if(EventNewStatus != EventOldStatus)
            {
                if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
                {
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
                    if(DEM_IS_COMBINEDDTC(DEM_CFG_EVENT_DTCREF(EventId)))
                    {
                        DTCNewStatus = DemInternal_UpdateCombinedDTC(EventId);

                    }
#endif
                    if(DTCNewStatus != DTCOldStatus)
                    {
                        if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
                        {
                            DemInternal_DTCStatusChangedNotification(DEM_CFG_DTC_VALUE(DtcId), DTCOldStatus, DTCNewStatus);
                        }
                    }
                }

                DemInternal_EventStatusChangedNotification(EventId,EventOldStatus, EventNewStatus);
            }
#if(DEM_INITMFORE_CALLBACK_SUPPORT == STD_ON)
            /*SWS_Dem_00679*/
            if(DEM_CFG_EVENT_INITM_CALLFNC(EventId) != NULL_PTR)
            {
#if(DEM_CORE_NUMBER > 1)
                if(CoreId != DEM_CFG_EVENT_COREREF(EventId))
                {
                    DEM_CFG_EVENT_INITM_FLAG(EventId) = TRUE;
                    DEM_CFG_EVENT_INITM_REASON(EventId) = DEM_INIT_MONITOR_RESTART;
                }
                else
#endif
                {
                    DEM_CFG_EVENT_INITM_CALLFNC(EventId)(DEM_INIT_MONITOR_RESTART);
                }
            }
#endif
        }
    }/*for(EventId = 0; EventId < DEM_NUM_OF_EVENT; EventId++)*/

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#if(DEM_NUM_OF_RATIO > 0)
    if(OperationCycleId == DEM_CFG_IGN_CYCLE_REF)
    {
        if(DEM_OBD_RATIO_IGN_CNT >= DEM_OBD_NUMDEN_MAX_VALUE)
        {
            DEM_OBD_RATIO_IGN_CNT = DEM_DATA_CLEAR;
        }

        /*Clear the General Denominator increased flag*/
        DEM_OBD_RATIO_GENDEN_STATE &= (~DEM_OBD_DEN_INCREASED_MASK);
        /*Reset the General Denominator condition state.*/
        DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_GENERAL_DENOMINATOR) = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
        /*Ignition Cycle counter increase 1*/
        DEM_OBD_RATIO_IGN_CNT++;

        if(DEM_OBD_RATIO_GENDEN_CNT >= DEM_OBD_NUMDEN_MAX_VALUE)
        {
            DEM_OBD_RATIO_GENDEN_CNT = DEM_DATA_CLEAR;
        }
    }

    if(OperationCycleId == DEM_CFG_OBD_DRIVING_CYCLE_REF)
    {
        /*Reset status enabled all readiness group*/
        DEM_OBD_READINESSGROUP_STATUS[0] = (uint8)0x03;
        DEM_OBD_READINESSGROUP_STATUS[0] = (uint8)0xFF;

        for(RatioID = (Dem_RatioIdType)0; RatioID < DEM_NUM_OF_RATIO; RatioID++)
        {
            /*Clear the Denominator increased flag*/
            DEM_OBD_RATIO_STATE(RatioID) &= (~DEM_OBD_DEN_INCREASED_MASK);
            /*Clear the Numerator increased flag*/
            DEM_OBD_RATIO_STATE(RatioID) &= (~DEM_OBD_NUM_INCREASED_MASK);
        }
        /*Reset additional IUMPR denominator condition state.*/
        DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_COND_COLDSTART) = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
        DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_COND_EVAP) = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
        DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_COND_500MI) = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
    }
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/
}
/*PRQA S 4700 ++*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_CycleEndProcess
(
    uint8 OperationCycleId
)
{
    Dem_EventIdType EventId;
#if((DEM_NUM_OF_STOR_GROUP > 0) || (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE))
    uint16 i;
#endif
    uint16 DtcId;
    uint16 EventMemoryId;
    uint8 ParentMemId;
    uint8 SubMemId;
    Dem_UdsStatusByteType DtcOldStatus;
    Dem_UdsStatusByteType DtcNewStatus;
    Dem_UdsStatusByteType EventCurStatus;
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
    Dem_UdsStatusByteType CbDtcOldStatus;
    Dem_UdsStatusByteType CbDtcNewStatus;
#endif
#if(DEM_NUM_OF_STOR_GROUP > 0)
    boolean EventStorageCondFullFilled = TRUE;
#endif
    for(EventId = (Dem_EventIdType)0; EventId < DEM_NUM_OF_EVENT; EventId++)
    {
        if(OperationCycleId == DEM_CFG_EVENT_OPCYCREF(EventId))
        {
            EventCurStatus = DEM_EVENT_STATUS(EventId);
            if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
            {
                /*The counter shall be started*/
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
                if(((DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) != DEM_DATA_INVALID_U8)\
                    || (DEM_DTC_DATAENTRYREF_NUM(DEM_CFG_EVENT_DTCREF(EventId)) > (uint8)0))\
                    && (DEM_TEST_UDS_STATUS_TFSLC(EventCurStatus)))
#else
                if((DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) != DEM_DATA_INVALID_U8)\
                    && (DEM_TEST_UDS_STATUS_TFSLC(EventCurStatus)))
#endif
                {
#if(DEM_EVENT_CSLF_SUPPORT == STD_ON)
                    /*SWS_Dem_00773*//*SWS_Dem_00774*//*SWS_Dem_01360*/
                    if(DEM_EVENT_CSLF(EventId) < DEM_DATA_U8_FF)
                    {
                        DEM_EVENT_CSLF(EventId)++;
                    }
#endif
#if(DEM_EVENT_CSFF_SUPPORT == STD_ON)
                    /*SWS_Dem_00777*//*SWS_Dem_00778*/
                    if(DEM_EVENT_CSFF(EventId) < DEM_DATA_U8_FF)
                    {
                        DEM_EVENT_CSFF(EventId)++;
                    }
#endif
#if(STD_OFF == DEM_CMA_PLATFORM_ENABLED)
#if(DEM_EVENT_FCSLC_SUPPORT == STD_ON)
                    /*SWS_Dem_00781*//*SWS_Dem_00782*/
                    if((DEM_TEST_UDS_STATUS_TFTOC(EventCurStatus)) \
                        && (DEM_EVENT_FCSLC(EventId) < DEM_DATA_U8_FF))
                    {
                        DEM_EVENT_FCSLC(EventId)++;
                    }
#endif
#endif
                }
            }

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
            if((DEM_TEST_UDS_STATUS_TFSLC(EventCurStatus)) \
                && (!DEM_TEST_UDS_STATUS_TFTOC(EventCurStatus)) \
                && (!DEM_TEST_UDS_STATUS_TNCTOC(EventCurStatus)) \
                && (DEM_EVENT_OBD_PCSLF(EventId) < DEM_OBD_PCSLF_MAXVALUE))
            {
                DEM_EVENT_OBD_PCSLF(EventId)++;
            }
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
            if((DEM_TEST_UDS_STATUS_TFSLC(EventCurStatus)) \
                && (!DEM_TEST_UDS_STATUS_TNCTOC(EventCurStatus)) \
                && (!DEM_TEST_UDS_STATUS_TFTOC(EventCurStatus)) \
                && (DEM_EVENT_CMA_PCSLF(EventId) < DEM_DATA_U8_FF))
            {
                DEM_EVENT_CMA_PCSLF(EventId)++;
            }
#endif
            if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
            {
                /*Capture data before operation cycle end*/
                if(TRUE == DemInternal_GetCaptureQueue(EventId, NULL_PTR))
                {
                    DemInternal_CaptureData(EventId);
                }
            }
        }

        /*Aging process*/
        /*SWS_Dem_00985*/
        /*SWS_Dem_00489: The Dem module shall only allow processing
        (counting further)the value of the aging counter, if the related
        event is stored in the event memory and is qualified as passed.
        Note: Aging is independent of the UDS status bit 3 (ConfirmedDTC)
        and therefore independent of the fault confirmation.*/
        if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
        {
            DtcId = DEM_CFG_EVENT_DTCREF(EventId);
            EventMemoryId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId);
            ParentMemId = DEM_GET_EVENTMEMORY_ID(EventMemoryId);
            SubMemId = DEM_GET_SUBMEMORY_ID(EventMemoryId);
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
            if(DEM_IS_COMBINEDDTC(DtcId))
            {
                DtcOldStatus = DEM_EVENT_STATUS(EventId);
                DtcNewStatus = DEM_EVENT_STATUS(EventId);
                CbDtcOldStatus = DEM_DTC_STATUS(DtcId);
                CbDtcNewStatus = DEM_DTC_STATUS(DtcId);

            }
            else
#endif
            {
                DtcOldStatus = DEM_DTC_STATUS(DtcId);
                DtcNewStatus = DEM_DTC_STATUS(DtcId);
            }
        }
        else
        {
            DtcOldStatus = DEM_EVENT_STATUS(EventId);
            DtcNewStatus = DEM_EVENT_STATUS(EventId);

        }

        /*if(OperationCycleId == DEM_CFG_DTC_AGINGCYCREF(DtcId))*/
        if(OperationCycleId == DEM_CFG_EVENT_OPCYCREF(EventId))
        {
#if(DEM_NUM_OF_INDICATOR > 0)
            DemInternal_IndicatorOffCriteriaFulfilled(EventId, DEM_CYCLE_END, DtcOldStatus, &DtcNewStatus);
#endif
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
            if((!DEM_TEST_UDS_STATUS_TFTOC(DtcOldStatus)) \
                && (!DEM_TEST_UDS_STATUS_TNCTOC(DtcOldStatus)))
            {
                DemInternal_RemoveEventPermanentEntry(EventId);
            }
#endif

#if(DEM_CFG_AGINGREQUIRESTESTEDCYCLE == STD_ON)
            if((!DEM_TEST_UDS_STATUS_TFTOC(DtcOldStatus)) \
                && (!DEM_TEST_UDS_STATUS_TNCTOC(DtcOldStatus)))
#else
            if(!DEM_TEST_UDS_STATUS_TFTOC(DtcOldStatus))
#endif
            {
                /*BIT2_Pending_DTC*//*SWS_Dem_00390*//*SWS_Dem_01183*/
                if(DEM_TEST_UDS_STATUS_PDTC(DtcOldStatus))
                {
#if(DEM_NUM_OF_STOR_GROUP > 0)
                    /*SWS_Dem_00455*//*SWS_Dem_00458*/
                    /*SWS_Dem_00591*//*SWS_Dem_00459*/
                    if(DEM_CFG_EVENT_STOR(EventId) != NULL_PTR)
                    {
                        for(i = (uint16)0; i < (uint16)DEM_CFG_EVENT_STOR_NUM(EventId); i++)
                        {
                            if(Dem_EventStorCondition[(DEM_CFG_EVENT_STOR_REF(EventId)[i])] != TRUE)
                            {
                                EventStorageCondFullFilled = FALSE;
                                break;
                            }
                        }
                    }
                    if(EventStorageCondFullFilled != FALSE)
#endif
                    {
                        DtcNewStatus = DEM_CLEAR_UDS_STATUS_PDTC(DtcNewStatus);
                    }
#if(STD_OFF == DEM_CMA_PLATFORM_ENABLED)
                    DEM_EVENT_FCC(EventId) = DEM_DATA_CLEAR;
#endif
                }
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
                if(!DEM_TEST_UDS_STATUS_CDTC(DtcOldStatus))
                {
                    DemInternal_ClearOBDFreezeFrame(EventId);
                }
#endif
            }
        }
        /*SWS_Dem_00270*/
        if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
        {
            if(Dem_DtcUpDateState[DEM_CFG_EVENT_DTCREF(EventId)] != FALSE)
            {
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
                if(DEM_IS_COMBINEDDTC(DtcId))
                {

                    if(((DEM_EVENT_DATAENTRYREF(EventId)) != DEM_DATA_INVALID_U8) \
                        && (!DEM_TEST_UDS_STATUS_WIR(DtcNewStatus))\
                        && (OperationCycleId == DEM_CFG_DTC_AGINGCYCREF(DtcId)) \
                        && (DEM_CFG_AGINGCYCLECOUNTERTHRESHOLD(DtcId) != 0))
                    {
#if(DEM_CFG_AGINGREQUIRESTESTEDCYCLE == STD_ON)
                        if((!DEM_TEST_UDS_STATUS_TFTOC(DtcOldStatus)) \
                            && (!DEM_TEST_UDS_STATUS_TNCTOC(DtcOldStatus)))
#else
                        if(!DEM_TEST_UDS_STATUS_TFTOC(DtcOldStatus))
#endif
                        {
                            /*SWS_Dem_01184*/
                            DEM_EVENT_AGINGCNT(EventId)++;
                        }
                        /*else
                        {
                            DEM_EVENT_AGINGCNT(DtcId) = 0;
                        }*/

                        if(DEM_EVENT_AGINGCNT(EventId) >= DEM_CFG_AGINGCYCLECOUNTERTHRESHOLD(DtcId))
                        {
                            if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
                            {
                                DtcNewStatus = DEM_CLEAR_UDS_STATUS_CDTC(DtcNewStatus);
#if(DEM_CFG_STATUSBITHANDLING_TFSLC == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
                                /*SWS_Dem_00393*//*SWS_Dem_01054*/
                                DtcNewStatus = DEM_CLEAR_UDS_STATUS_TFSLC(DtcNewStatus);
#endif
                            }
                            else
                            {
                                /*Clear event info*/
                                DemInternal_ClearOneEvent(EventId, TRUE);
                                /*Clear DTC info*/
                                /*SWS_Dem_00391*//*SWS_Dem_00498*/
                                DtcNewStatus = DEM_CLEAR_UDS_STATUS_CDTC(DtcNewStatus);
#if(DEM_CFG_STATUSBITHANDLING_TFSLC == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
                                /*SWS_Dem_00393*//*SWS_Dem_01054*/
                                DtcNewStatus = DEM_CLEAR_UDS_STATUS_TFSLC(DtcNewStatus);
#endif
                                DemInternal_ClearOneMemoryEntry(ParentMemId,DEM_EVENT_DATAENTRYREF(EventId),SubMemId);

                                DEM_EVENT_DATAENTRYREF(EventId) = DEM_DATA_INVALID_U8;
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
                                DEM_DTC_DATAENTRYREF_NUM(DtcId)--;
#endif
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
                                /*SWS_Dem_01174*/
                                DemInternal_ClearOBDFreezeFrame(EventId);
#endif
                            }
                            if(DtcOldStatus != DtcNewStatus)
                            {
                                DEM_EVENT_STATUS(EventId) = DtcNewStatus;
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
                                CbDtcNewStatus = DemInternal_UpdateCombinedDTC(EventId);
#endif
                               DemInternal_EventStatusChangedNotification(EventId,DtcOldStatus, DtcNewStatus);
                            }
                        }
                    }
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
                    if((DEM_DTC_AGINGCNT(DtcId) >= DEM_CFG_AGINGCYCLECOUNTERTHRESHOLD(DtcId))\
                        && (DEM_CFG_AGINGCYCLECOUNTERTHRESHOLD(DtcId) != (uint8)0))
                    {
                        for(i = (uint16)0; i < (uint16)DEM_NUM_OF_EVENT;i++)
                        {
                            if(DtcId == DEM_CFG_EVENT_DTCREF(i))
                            {
                                DemInternal_ClearOneEvent(i, TRUE);
                            }

                        }
                        /*Clear event info*/

                        /*Clear DTC info*/
                        /*SWS_Dem_00391*//*SWS_Dem_00498*/
                        CbDtcNewStatus = DEM_CLEAR_UDS_STATUS_CDTC(CbDtcNewStatus);
#if(DEM_CFG_STATUSBITHANDLING_TFSLC == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
                        /*SWS_Dem_00393*//*SWS_Dem_01054*/
                        CbDtcNewStatus = DEM_CLEAR_UDS_STATUS_TFSLC(CbDtcNewStatus);
#endif
                        DEM_DTC_AGINGCNT(DtcId) = DEM_DATA_CLEAR;
#if(DEM_DTC_AGEDCNT_SUPPORT == STD_ON)
                        if(DEM_DTC_AGEDCNT(DtcId) < DEM_DATA_U8_FF)
                        {
                            DEM_DTC_AGEDCNT(DtcId)++;
                        }
#endif
                        /*SWS_Dem_01075*/

                        DemInternal_ClearOneMemoryEntry(ParentMemId,(DEM_DTC_DATAENTRYREF(DtcId)),SubMemId);

                        DEM_DTC_DATAENTRYREF(DtcId) = DEM_DATA_INVALID_U8;

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
                        /*SWS_Dem_01174*/
                        DemInternal_ClearOBDFreezeFrame(EventId);
#endif
                    }
#endif
                    if(CbDtcNewStatus != CbDtcOldStatus)
                    {
                        DemInternal_DTCStatusChangedNotification(DEM_CFG_DTC_VALUE(DtcId), CbDtcOldStatus, CbDtcNewStatus);
                    }

                }
#endif/*#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)*/
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
                if((!DEM_IS_COMBINEDDTC(DtcId))\
                    && (!DEM_TEST_UDS_STATUS_WIR(DtcNewStatus))\
                    &&(DEM_DTC_DATAENTRYREF(DtcId) != DEM_DATA_INVALID_U8) \
                    && (DEM_CFG_AGINGCYCLECOUNTERTHRESHOLD(DtcId) != (uint8)0) \
                    && (OperationCycleId == DEM_CFG_DTC_AGINGCYCREF(DtcId)))
#else
                if((DEM_DTC_DATAENTRYREF(DtcId) != DEM_DATA_INVALID_U8) \
                    && (!DEM_TEST_UDS_STATUS_WIR(DtcNewStatus))\
                    && (OperationCycleId == DEM_CFG_DTC_AGINGCYCREF(DtcId)))
#endif
                {
                    /*SWS_Dem_00490*//*SWS_Dem_00826*/
#if(DEM_CFG_AGINGREQUIRESTESTEDCYCLE == STD_ON)
                    if((!DEM_TEST_UDS_STATUS_TFTOC(DtcOldStatus)) \
                        && (!DEM_TEST_UDS_STATUS_TNCTOC(DtcOldStatus)))
#else
                    if(!DEM_TEST_UDS_STATUS_TFTOC(DtcOldStatus))
#endif
                    {
                        /*SWS_Dem_01184*/
                        DEM_DTC_AGINGCNT(DtcId)++;
                    }
                    /*else
                    {
                        DEM_DTC_AGINGCNT(DtcId) = 0;
                    }*/

                    if(DEM_DTC_AGINGCNT(DtcId) >= DEM_CFG_AGINGCYCLECOUNTERTHRESHOLD(DtcId))
                    {
                        /*Clear event info*/
                        DemInternal_ClearOneEvent(EventId, TRUE);
                        /*Clear DTC info*/
                        /*SWS_Dem_00391*//*SWS_Dem_00498*/
                        DtcNewStatus = DEM_CLEAR_UDS_STATUS_CDTC(DtcNewStatus);
#if(DEM_CFG_STATUSBITHANDLING_TFSLC == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
                    /*SWS_Dem_00393*//*SWS_Dem_01054*/
                        DtcNewStatus = DEM_CLEAR_UDS_STATUS_TFSLC(DtcNewStatus);
#endif
                        DEM_DTC_AGINGCNT(DtcId) = DEM_DATA_CLEAR;
#if(DEM_DTC_AGEDCNT_SUPPORT == STD_ON)
                        if(DEM_DTC_AGEDCNT(DtcId) < DEM_DATA_U8_FF)
                        {
                            DEM_DTC_AGEDCNT(DtcId)++;
                        }
#endif

                        DemInternal_ClearOneMemoryEntry(ParentMemId,(DEM_DTC_DATAENTRYREF(DtcId)),SubMemId);
                        DEM_DTC_DATAENTRYREF(DtcId) = DEM_DATA_INVALID_U8;

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
                        /*SWS_Dem_01174*/
                        DemInternal_ClearOBDFreezeFrame(EventId);
#endif
                    }

                    if(DtcNewStatus != DtcOldStatus)
                    {
                        DemInternal_DTCStatusChangedNotification(DEM_CFG_DTC_VALUE(DtcId), DtcOldStatus, DtcNewStatus);
                        DemInternal_EventStatusChangedNotification(EventId,DtcOldStatus, DtcNewStatus);
                    }
                }
                else
                {
                    /*do nothing*/
                }
            }
        }
        else
        {
            if(DtcNewStatus != DtcOldStatus)
            {
                DemInternal_EventStatusChangedNotification(EventId,DtcOldStatus, DtcNewStatus);
            }
        }

        if(DEM_CFG_EVENT_DTCREF(EventId) !=DEM_DTC_ID_INVALID)
        {
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
            if(DEM_IS_COMBINEDDTC(DtcId))
            {
#if(DEM_DTC_LASTSTATUS_SUPPORT == STD_ON)
                DEM_DTC_LASTSTATUS(DtcId) = CbDtcOldStatus;
#endif
                DEM_DTC_STATUS(DtcId) = CbDtcNewStatus;
            }
            else
#endif
            {
#if(DEM_DTC_LASTSTATUS_SUPPORT == STD_ON)
                /*save the current and last operation cycle DTC status*/
                DEM_DTC_LASTSTATUS(DtcId) = DtcOldStatus;
#endif
                DEM_DTC_STATUS(DtcId) = DtcNewStatus;
            }
        }
        DEM_EVENT_STATUS(EventId) = DtcNewStatus;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_SetDTCFilter
*
* Description: Sets the DTC Filter.
*
* Inputs:
*
*
*
* Outputs: None
*
* Return:
*
* Limitations: Synchronous & Non Reentrant
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_SetDTCFilter
(
    uint8 ClientId,
    uint8 StatusFilterMask,
    uint8 EventMemId,
    uint8 ClientSubMemId
)
{
    uint16 DtcId;
    uint8 DTC_ParentMemId;
    uint8 DTC_SubMemId;
    boolean FilteredFailed;
    for(DtcId = (uint16)0; DtcId < (uint16)DEM_NUM_OF_DTC; DtcId++)
    {
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
        if(Dem_DTCSuppressionState[DtcId] != TRUE)
#endif
        {
            /*PRQA S 715 ++*/
            FilteredFailed = FALSE;
            DTC_ParentMemId = DEM_GET_EVENTMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId));
            DTC_SubMemId = DEM_GET_SUBMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId));
            if((DTC_SubMemId != ClientSubMemId) || (DTC_ParentMemId != EventMemId))
            {
                FilteredFailed = TRUE;
            }
            if(FilteredFailed != TRUE)
            {
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
                if(Dem_DcmFilterInfo[ClientId].DTCOrigin == DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY)
                {
                    if(!DEM_DTC_IS_OBD(DtcId))
                    {
                        FilteredFailed = TRUE;
                    }
                }
                else
#endif
                {
                    if(DEM_CFG_DTC_VALUE(DtcId) == (uint32)0)
                    {
                        FilteredFailed = TRUE;
                    }
                }
            }
            if(FilteredFailed != TRUE)
            {
                if(((Dem_DcmFilterInfo[ClientId].FilterWithSeverity == FALSE) || ((DEM_CFG_DTC_SEVERITY(DtcId) & Dem_DcmFilterInfo[ClientId].DTCSeverityMask) != (Dem_DTCSeverityType)0)) \
                    && ((Dem_DcmFilterInfo[ClientId].DTCStatusMask == (Dem_UdsStatusByteType)0) || ((DEM_DTC_STATUS(DtcId) & (Dem_UdsStatusByteType)StatusFilterMask) != (Dem_UdsStatusByteType)0)))
                {
                    /*DTCStatusMask 0x00: Autosar-specific value to deactivate the status-byte filtering
                    (different meaning than in ISO 14229-1) to report all supported DTCs (used for
                    service 0x19 subfunctions 0x0A/0x15)*/
                    Dem_DcmFilterInfo[ClientId].FilteredDTCIndexTable[Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC] = DtcId;
                    Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC++;

                }
            }

            /*PRQA S 715 --*/
        }
    }/*for(DtcId = 0; DtcId < DEM_NUM_OF_DTC; DtcId++)*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
#if((DEM_CORE_NUMBER > 1) && (DEM_CSDATA_IN_MASTER_SUPPORT != STD_ON))
STATIC FUNC(void, DEM_CODE) DemInternal_ObtainCSData
(
    void
)
{
    uint16 i;

    CoreIdType CoreId = Bmc_GetCoreId();

    for(i = (uint16)0; i < DEM_NUM_OF_DATA; i++)
    {
        if(DEM_CFG_DATA_CS_DATA(i) != NULL_PTR)
        {
            if(DEM_CFG_DATA_CS_DATA_COREID(i) == CoreId)
            {
                SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_1();
                Bmc_GetSpinLock(&DEM_CFG_DATA_SPINLOCK_FLAG(i));
                (void)(*DEM_CFG_DATA_CS_DATA_READ_FNC(i))(DEM_CFG_DATA_CS_DATA_BUFFER(i));
                Bmc_ReleaseSpinLock(&DEM_CFG_DATA_SPINLOCK_FLAG(i));
                SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_1();
            }
        }
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_OperationCycleHandle
(
    uint8 OperationCycleId
)
{
    if(DEM_CURRENT_OP_STATE(OperationCycleId) == DEM_CYCLE_STATE_END)
    {
        /*SWS_Dem_01224*//*SWS_Dem_01221*/
        DemInternal_RestartOperationCycle(OperationCycleId, DEM_CYCLE_STATE_START);
    }
    else
    {
        /*SWS_Dem_01224*//*SWS_Dem_01221*/
        DemInternal_RestartOperationCycle(OperationCycleId, DEM_CYCLE_STATE_RESTART);
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_OperationCycle
(
    void
)
{
    uint8 i;
    for(i = (uint8)0; i < (uint8)DEM_NUM_OF_OPCYCLE; i++)
    {
        if((Dem_OpCycReq[i] == DEM_CYCLE_STATE_START) \
                && (DEM_CURRENT_OP_STATE(i) == DEM_CYCLE_STATE_END))
        {
            Dem_OpCycReq[i] = DEM_DATA_CLEAR;
            DEM_CURRENT_OP_STATE(i) = DEM_CYCLE_STATE_START;
            DemInternal_CycleStartProcess(i);
        }
        else if((Dem_OpCycReq[i] == DEM_CYCLE_STATE_RESTART) \
                && (DEM_CURRENT_OP_STATE(i) == DEM_CYCLE_STATE_START))
        {
            /*SWS_Dem_00483*/
            Dem_OpCycReq[i] = DEM_DATA_CLEAR;
            DEM_CURRENT_OP_STATE(i) = DEM_CYCLE_STATE_START;
            DemInternal_CycleEndProcess(i);
            DemInternal_CycleStartProcess(i);
        }
        else
        {
            /*SWS_Dem_00484*/
        }
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_EventCheck
(
    Dem_EventIdType EventId
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_NUM_OF_EN_GROUP > 0)
    uint8 i;
#endif
    if ((DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID) \
        && (Dem_EnableDtcSetting[DEM_CFG_EVENT_DTCREF(EventId)] == FALSE)\
        && (DEM_GET_STATE != DEM_PREINIT))
    {
        Result = E_NOT_OK;
    }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
        Result = E_NOT_OK;
    }
#endif
    else
    {
#if(DEM_NUM_OF_EN_GROUP > 0)
        /*SWS_Dem_00447*//*SWS_Dem_00449*//*SWS_Dem_00450*/
        if(DEM_CFG_EVENT_EN(EventId) != NULL_PTR)
        {
            for(i = (uint8)0; i < DEM_CFG_EVENT_EN_NUM(EventId); i++)
            {
                if(Dem_EventEnCondition[(DEM_CFG_EVENT_EN_REF(EventId)[i])] != TRUE)
                {
                    Result = E_NOT_OK;
                    break;
                }
            }
        }
#endif
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_UDSStatusHandle
(
    void
)
{
    uint16 i;
    Dem_EventIdType Dem_ReportEventId[DEM_MAXNUM_OF_EVENT];
    Dem_EventStatusType Dem_ReportEventStatus[DEM_MAXNUM_OF_EVENT];
    uint16 NumOfEvent = (uint16)0;
#if(DEM_CFG_BSWERRORBUFFERSIZE > 0)
    if(Dem_ErrorBufferIndex > (uint8)0)
    {
        for(i = (uint16)0; i < Dem_ErrorBufferIndex ; i++)
        {
            Dem_ReportEventId[NumOfEvent] =  DEM_REPORT_BSW_EVENT_ID(i);
            Dem_ReportEventStatus[NumOfEvent] = DEM_REPORT_BSW_EVENT_STATU(i);
            NumOfEvent++;
        }
        Dem_ErrorBufferIndex  = (uint8)0;
    }
#endif

    for(i = (uint16)0; i < DEM_NUM_OF_EVENT; i++)
    {
        if((Dem_EventStatusBuff[i] & DEM_EVENT_STATUS_UPDATE_MASK) != 0)
        {
            Dem_ReportEventStatus[NumOfEvent] = Dem_EventStatusBuff[i];
            Dem_ReportEventId[NumOfEvent] = i;
            Dem_EventStatusBuff[i] = DEM_DATA_CLEAR;
            NumOfEvent++;
        }
    }
    for(i = (uint16)0; i < NumOfEvent; i++)
    {
/*PRQA S 2963 ++*/
/*
When NumOfEvent is greater than 0, Dem_ReportEventId has already been assigned a value.
*/
#if(DEM_CORE_NUMBER > 1)
        if(E_OK == DemInternal_EventCheck(Dem_ReportEventId[i]))
#endif
        {
            Dem_ReportEventStatus[i] &= (~DEM_EVENT_STATUS_UPDATE_MASK);
            DemInternal_SetEventStatusAsync(Dem_ReportEventId[i], Dem_ReportEventStatus[i]);
        }
#if(DEM_CORE_NUMBER > 1)
        else
        {

            DEM_SERVICE_RESULT_NOTIFICATION(DEM_SETEVENTSTATUS_APIID, Dem_ReportEventId[i], E_NOT_OK);
            /*Callout();*/
        }
#endif
/*PRQA S 2963 --*/
    }

}

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_DebounceTimer
(
    void
)
{
    Dem_EventIdType EventId;
#if(DEM_NUM_OF_EN_GROUP > 0)
    uint8 i;
    boolean DbtStopFlag;
#endif

    for(EventId = (Dem_EventIdType)0; EventId < DEM_NUM_OF_EVENT; EventId++)
    {
#if(DEM_NUM_OF_EN_GROUP > 0)
        DbtStopFlag = FALSE;

        if(DEM_CFG_EVENT_EN(EventId) != NULL_PTR)
        {
            for(i = (uint8)0; i < DEM_CFG_EVENT_EN_NUM(EventId); i++)
            {
                if(Dem_EventEnCondition[(DEM_CFG_EVENT_EN_REF(EventId)[i])] != TRUE)
                {
                    DbtStopFlag = TRUE;
                    break;
                }
            }
        }
        /*SWS_Dem_00655*//*SWS_Dem_00678*/
        if((DEM_CFG_EVENT_DBT(EventId) != NULL_PTR) \
            && ((DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREFAILED) \
                || (DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREPASSED)) \
            && (Dem_EventDBTFreezeFlag[EventId] == FALSE) \
            && (DbtStopFlag == FALSE))
#else
        if((DEM_CFG_EVENT_DBT(EventId) != NULL_PTR) \
            && ((DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREFAILED) \
                || (DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREPASSED)) \
            && (Dem_EventDBTFreezeFlag[EventId] == FALSE))
#endif
        {
            (DEM_EVENT_DBT(EventId))++;

            if((DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREFAILED) \
                && (DEM_EVENT_DBT(EventId) >= DEM_CFG_EVENT_DBT_FAILED(EventId)))
            {
                DemInternal_SetUDSStatus(EventId, DEM_EVENT_STATUS_FAILED);
            }
            else if((DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREPASSED) \
                && (DEM_EVENT_DBT(EventId) >= DEM_CFG_EVENT_DBT_PASSED(EventId)))
            {
                DemInternal_SetUDSStatus(EventId, DEM_EVENT_STATUS_PASSED);
            }
            else
            {
                /*do nothing*/
            }
#if(DEM_FDC_STORAGE_SUPPORT == STD_ON)
            if(DEM_EVENT_DBT(EventId) >= DEM_CFG_TIMER_FDC_THRESHLD(EventId))
            {
                if(FALSE == Dem_DTC_FirstFdcThreshold[DEM_CFG_EVENT_DTCREF(EventId)])
                {
                    Dem_DTC_FirstFdcThreshold[DEM_CFG_EVENT_DTCREF(EventId)] = TRUE;
                    /*SWS_Dem_00786*//*SWS_Dem_00799*//*SWS_Dem_00811*/
                    DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_FDC_THRESHOLD);
                }
            }
#endif
        }
    }
}
#endif/*#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_CaptureData
(
    void
)
{
    uint16 EventId;
    uint16 i = (uint16)0;

    for(EventId = (uint16)Dem_CapturePosition; EventId < (uint16)DEM_NUM_OF_EVENT; EventId++)
    {
        if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
        {
            if(DemInternal_GetCaptureQueue(EventId, NULL_PTR) == TRUE)
            {
                i++;
                SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_0();
                DemInternal_CaptureData(EventId);
                SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_0();
            }

            if(EventId >= ((uint16)DEM_NUM_OF_EVENT - (uint16)1))
            {
                /*the last DTC*/
                Dem_CapturePosition = (uint16)0;
                break;
            }
            else if(i >= DEM_MAXNUM_CAPTURE_DATA_PER_MAINCYCLE)
            {
                /*MaxNumOfCaptureDataForDtcPerMainCycle is reached*/
                Dem_CapturePosition += DEM_MAXNUM_CAPTURE_DATA_PER_MAINCYCLE;
                break;
            }
            else
            {
                /*continue capture data*/
            }
        }
    }
}

#if((DEM_CORE_NUMBER > 1) && (DEM_EVENT_CALLBACK_SUPPORT == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_Notification
(
    void
)
{
    uint16 index;
    Dem_EventIdType EventId;
    CoreIdType CoreId = Bmc_GetCoreId();

    for(index = (Dem_EventIdType)0; index < DEM_NUM_OF_CORE_EVENT(CoreId); index++)
    {
        EventId = DEM_GET_CORE_EVENT_ID(CoreId,index);
        if(DEM_CFG_EVENT_CALLBACK(EventId) != NULL_PTR)
        {
#if(DEM_INITMFORE_CALLBACK_SUPPORT == STD_ON)
            if(DEM_CFG_EVENT_INITM_FLAG(EventId) == TRUE)
            {
                DEM_CFG_EVENT_INITM_CALLFNC(EventId)(DEM_CFG_EVENT_INITM_REASON(EventId));
                DEM_CFG_EVENT_INITM_FLAG(EventId) = FALSE;
            }
#endif

#if(DEM_MONITOR_CHANGE_CALLBACK_SUPPORT == STD_ON)
            if(DEM_CFG_EVENT_MONITOR_STATUS_FLAG(EventId) == TRUE)
            {
                (void)DEM_CFG_MONITOR_STATUSCHANGED_CALLFNC(EventId);
                DEM_CFG_EVENT_MONITOR_STATUS_FLAG(EventId) = FALSE;
            }
#endif
#if(DEM_CLEAR_EVENT_ALLOWED_CALLBACK_SUPPORT == STD_ON)
            if(DEM_CFG_CLEAR_EVENT_ALLOWED_FLAG(EventId) == TRUE)
            {
                DEM_CLEAR_EVENT_ALLOWED_RESULT(EventId) = DemInternal_ClearDTCAllowed(EventId);
                DEM_CFG_CLEAR_EVENT_ALLOWED_FLAG(EventId) = FALSE;
            }
#endif
#if(DEM_EVENT_DATA_CHANGE_CALLBACK_SUPPORT == STD_ON)
            if(DEM_CFG_EVENT_DATA_CHANGE_FLAG(EventId) == TRUE)
            {
                (void)(*DEM_CFG_EVENT_DATACHANGED_CALLFNC(EventId))();
                DEM_CFG_EVENT_DATA_CHANGE_FLAG(EventId) = FALSE;
            }
#endif
#if(DEM_EVENT_STATUS_CHANGE_CALLBACK_SUPPORT == STD_ON)
            if(DEM_CFG_EVENT_STATUS_CHANGE_FLAG(EventId) == TRUE)
            {
                DEM_CFG_EVENT_STATUSCHANGED_CALLFNC(EventId)(DEM_CFG_EVENT_STATUS_OLDSTATUS(EventId),DEM_CFG_EVENT_STATUS_NEWSTATUS(EventId));
                DEM_CFG_EVENT_STATUS_CHANGE_FLAG(EventId) = FALSE;
            }
#endif
        }
    }
}
#endif
#if(DEM_CFG_CLEARDTCBEHAIOR != DEM_CLRRESP_VOLATILE)
#if(DEM_NVM_SUPPORT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetErrorState
*
* Description: Clear the group DTC or Write the RAM info which has been cleared
*              in nonvalatile memory.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_GetErrorState
(
    void
)
{

    Std_ReturnType ret;
    for(; Dem_ClearDTCInfo.ClearBlockIndex < Dem_ClearDTCInfo.ClearBlockNum;)
    {
        if(E_OK == Dem_GetErrorStatus(Dem_ClearDTCInfo.ClearBlockIdTable[Dem_ClearDTCInfo.ClearBlockIndex], &ret))
        {
            if(ret == NVM_REQ_OK)
            {
               Dem_ClearDTCInfo.ClearBlockIndex ++;
            }
            else if(ret == NVM_REQ_PENDING)
            {
                break;
            }
            else
            {
                Dem_ClearDTCState = DEM_IN_CLEAR_DTC_ERR;
                Dem_ClearDTCInfo.ClearBlockNum = (uint16)0;
                Dem_SelectDTCState[Dem_ClearDTC_Client] = DEM_IN_SELECT_DTC_IDLE;
                break;
            }
        }
        else
        {
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_ERR;
            Dem_ClearDTCInfo.ClearBlockNum = (uint16)0;
            Dem_SelectDTCState[Dem_ClearDTC_Client] = DEM_IN_SELECT_DTC_IDLE;
            break;
        }
    }
    if((Dem_ClearDTCInfo.ClearBlockIndex == Dem_ClearDTCInfo.ClearBlockNum) && (Dem_ClearDTCState != DEM_IN_CLEAR_DTC_ERR))
    {
        Dem_ClearDTCInfo.ClearBlockIndex= (uint16)0;
        Dem_ClearDTCInfo.ClearBlockNum = (uint16)0;
        Dem_ClearDTCState = DEM_IN_CLEAR_EVENT_MEM;
        Dem_SelectDTCState[Dem_ClearDTC_Client] = DEM_IN_SELECT_DTC_PROCESSING;
    }
}
#endif
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetClearEvent
*
* Description:
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_GetClearEvent
(
    uint16 DtcId
)
{
#if((DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED) || \
     ((DEM_CORE_NUMBER > 1) && (DEM_CLEAR_EVENT_ALLOWED_CALLBACK_SUPPORT == STD_ON)))
    Dem_EventIdType EventId;
#endif
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
    uint8 EventNum;
    if(DEM_IS_COMBINEDDTC(DtcId))
    {
        for(EventNum = (uint8)0; EventNum < DEM_CFG_DTC_COMBINEDNUM(DtcId); EventNum++)
        {
            EventId = DEM_CFG_DTC_COMBINED_EVENTID(DtcId,EventNum);
#if((DEM_CORE_NUMBER > 1) && (DEM_CLEAR_EVENT_ALLOWED_CALLBACK_SUPPORT == STD_ON))
            if(DEM_MASTER_COREID != DEM_CFG_EVENT_COREREF(EventId))
            {
                if(DEM_CFG_EVENT_CLEARALLOWED_CALLFNC(EventId) != NULL_PTR)
                {
                    DEM_CFG_CLEAR_EVENT_ALLOWED_FLAG(EventId) = TRUE;
                }
            }
#endif
        }
    }
    else
#endif
    {

#if((DEM_CORE_NUMBER > 1) && (DEM_CLEAR_EVENT_ALLOWED_CALLBACK_SUPPORT == STD_ON))
        EventId = DEM_CFG_DTC_EVENTREF(DtcId);
        if(DEM_MASTER_COREID != DEM_CFG_EVENT_COREREF(EventId))
        {
            if(DEM_CFG_EVENT_CLEARALLOWED_CALLFNC(EventId) != NULL_PTR)
            {
                DEM_CFG_CLEAR_EVENT_ALLOWED_FLAG(EventId) = TRUE;
            }
        }
#endif
    }
    Dem_ClearDTCInfo.ClearDTCTable[DtcId] = TRUE;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetClearDTCFromGroup
*
* Description:
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_GetClearDTCFromGroup
(
    void
)
{
    uint16 DtcIndex;

#if(DEM_NUM_OF_DTCGROUP > 0)
    uint8 MemId = DEM_CLIENT_EVENT_MEM(Dem_ClearDTC_Client);
    Dem_UdsDTCType NextGroupValue;

    if(Dem_ClearDTC_DTC != DEM_DTC_GROUP_ALL)
    {

        if(Dem_ClearDTC_DTC == DEM_DTC_GROUP_EMISSION)
        {
            NextGroupValue = DEM_DTC_GROUP_ALL;
        }
        /*PRQA S 3316 ++*/
        else if(Dem_ClearDTC_GroupIndex < ((uint16)DEM_NUM_OF_DTCGROUP_MEMORY(MemId) - (uint16)1))
        {
            NextGroupValue = (Dem_UdsDTCType)DEM_CFG_DTC_GROUPVALUE(MemId,(Dem_ClearDTC_GroupIndex + (uint16)1));
        }
        /*PRQA S 3316 --*/
        else
        {
            NextGroupValue = DEM_DTC_COM_RANGE_HIGH;
        }
    }
#endif

    for(DtcIndex = Dem_ClearDTC_Index; DtcIndex < DEM_NUM_OF_DTC; DtcIndex++)
    {
#if(DEM_NUM_OF_DTCGROUP > 0)
        if(((DEM_CFG_DTC_VALUE(DtcIndex) > Dem_ClearDTC_DTC) \
            && (DEM_CFG_DTC_VALUE(DtcIndex) < NextGroupValue)) \
            || (Dem_ClearDTC_DTC == DEM_DTC_GROUP_ALL))
#else
        if((Dem_ClearDTC_DTC == DEM_DTC_GROUP_ALL) || ((Dem_ClearDTC_DTC == DEM_DTC_GROUP_EMISSION)&&(DEM_CFG_DTC_VALUE(DtcIndex) > Dem_ClearDTC_DTC)))
#endif
        {
            DemInternal_GetClearEvent(DtcIndex);
        }
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_MainFnc_ClearDTC
*
* Description: Clear the group DTC or Write the RAM info which has been cleared
*              in nonvalatile memory.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_ClearDTC
(
    void
)
{
    Std_ReturnType Result;
#if(DEM_CFG_CLEARDTCBEHAIOR != DEM_CLRRESP_VOLATILE)
    uint16 MaxIndexCurrentCycle;
    uint16 BlockId;
    NvM_RequestResultType ret = NVM_REQ_OK;
#endif
#if((DEM_CORE_NUMBER > 1) && (DEM_CLEAR_EVENT_ALLOWED_CALLBACK_SUPPORT == STD_ON))
    Dem_EventIdType EventId;
#endif

    if((Dem_ClearDTCState == DEM_IN_CLEAR_DTC_GROUP_WAIT) || (Dem_ClearDTCState == DEM_IN_CLEAR_DTC_SINGLE_WAIT))
    {
#if((DEM_CORE_NUMBER > 1) && (DEM_CLEAR_EVENT_ALLOWED_CALLBACK_SUPPORT == STD_ON))
        for(EventId = 0; EventId < DEM_NUM_OF_EVENT; EventId++)
        {
            if((DEM_CFG_EVENT_COREREF(EventId) != DEM_MASTER_COREID) && (DEM_CFG_EVENT_CALLBACK(EventId) != NULL_PTR) && (DEM_CFG_EVENT_CLEARALLOWED_CALLFNC(EventId) != NULL_PTR))
            {
                if(DEM_CFG_CLEAR_EVENT_ALLOWED_FLAG(EventId) == TRUE)
                {
                    break;
                }
            }
        }
        if(EventId >= DEM_NUM_OF_EVENT)
#endif
        {
            if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_SINGLE_WAIT)
            {
                Dem_ClearDTCState = DEM_IN_CLEAR_DTC_SINGLE_FINISH;
            }
            else
            {
                Dem_ClearDTCState = DEM_IN_CLEAR_DTC_GROUP_FINISH;
            }
        }
    }


    if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_GROUP_FINISH)
    {
        DemInternal_ClearOneDTCGroup();
    }
    else if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_SINGLE_FINISH)
    {

        Result = DemInternal_ClearOneDTC(Dem_ClearDTC_Index);
        if(Result != DEM_CLEAR_FAILED)
        {

#if(DEM_CFG_CLEARDTCBEHAIOR == DEM_CLRRESP_VOLATILE)
            /*SWS_Dem_00570*/
            Dem_SelectDTCState[Dem_ClearDTC_Client] = DEM_IN_SELECT_DTC_IDLE;
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_OK;
            if((DEM_CFG_CLEAR_DTC_NOTIFICATION_FUN(DEM_CLIENT_EVENT_MEM(Dem_ClearDTC_Client)) != NULL_PTR) \
                    &&(DEM_CFG_CLEAR_DTC_NOTIFICATION_TIME(DEM_CLIENT_EVENT_MEM(Dem_ClearDTC_Client)) == FINISH))
            {
                (void)DEM_CFG_CLEAR_DTC_NOTIFICATION_FUN(DEM_CLIENT_EVENT_MEM(Dem_ClearDTC_Client))(Dem_ClearDTC_DTC, Dem_ClearDTC_DTCFormat, Dem_ClearDTC_DTCOrigin);
            }

#else
            DemInternal_ClearEntryInNvm(Dem_ClearDTC_Index);
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_BUSY_SINGLE;
            Dem_SelectDTCState[Dem_ClearDTC_Client] = DEM_IN_SELECT_DTC_PENDING;

#endif
        }
        else
        {
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_ERR;
            Dem_SelectDTCState[Dem_ClearDTC_Client] = DEM_IN_SELECT_DTC_IDLE;
        }
    }
#if(DEM_CFG_CLEARDTCBEHAIOR != DEM_CLRRESP_VOLATILE)
#if(DEM_NVM_SUPPORT == STD_ON)
    else if((Dem_ClearDTCState == DEM_IN_CLEAR_DTC_BUSY_SINGLE) \
        ||(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_BUSY_GROUP))
    {
       DemInternal_GetErrorState();
    }
    else if(Dem_ClearDTCState == DEM_IN_CLEAR_EVENT_MEM)
    {
        if(E_OK == Dem_WriteBlock(DEM_CFG_NVM_BLOCKID, NULL_PTR))
        {
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_BUSY;
        }
        else
        {
            Dem_SelectDTCState[Dem_ClearDTC_Client] = DEM_IN_SELECT_DTC_IDLE;
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_ERR;
        }
    }
    else if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_BUSY)
    {
        if(E_OK == Dem_GetErrorStatus(DEM_CFG_NVM_BLOCKID, &ret))
        {
            if(ret == NVM_REQ_OK)
            {
                Dem_ClearDTCState = DEM_IN_CLEAR_DTC_OK;
                Dem_SelectDTCState[Dem_ClearDTC_Client] = DEM_IN_SELECT_DTC_IDLE;
                if((DEM_CFG_CLEAR_DTC_NOTIFICATION_FUN(DEM_CLIENT_EVENT_MEM(Dem_ClearDTC_Client)) != NULL_PTR) \
                    &&(DEM_CFG_CLEAR_DTC_NOTIFICATION_TIME(DEM_CLIENT_EVENT_MEM(Dem_ClearDTC_Client)) == FINISH))
                {
                    (void)DEM_CFG_CLEAR_DTC_NOTIFICATION_FUN(DEM_CLIENT_EVENT_MEM(Dem_ClearDTC_Client))(Dem_ClearDTC_DTC, Dem_ClearDTC_DTCFormat, Dem_ClearDTC_DTCOrigin);
                }
            }
            else if(ret == NVM_REQ_PENDING)
            {
                /*do nothing*/
            }
            else
            {
                Dem_ClearDTCState = DEM_IN_CLEAR_DTC_ERR;
                Dem_SelectDTCState[Dem_ClearDTC_Client] = DEM_IN_SELECT_DTC_IDLE;
            }
        }
        else
        {
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_ERR;
            Dem_SelectDTCState[Dem_ClearDTC_Client] = DEM_IN_SELECT_DTC_IDLE;
        }
    }
#endif
#endif
    else
    {
        /*do nothing*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_MainFnc_SelectDTC
*
* Description: Select the group DTC or single DTC checking
*
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_CheckSelectDTC
(
    uint8 ClientId
)
{
    uint16 DtcIndex;
    Std_ReturnType Result = E_NOT_OK;
    uint8 MemSetId = DEM_CLIENT_EVENT_MEM(ClientId);
    uint8 DTC_SubMemId;
    uint8 DTC_ParentMemId;
    uint16 DTC_MemId;
    Dem_SelectDTCState[ClientId] = DEM_IN_SELECT_DTC_CHECKING;
    if((Dem_SelectDTC_DTC[ClientId] == DEM_DTC_GROUP_ALL) || (Dem_SelectDTC_DTC[ClientId] == DEM_DTC_GROUP_EMISSION))
    {
        Dem_SelectDTCState[ClientId] = DEM_IN_SELECT_DTC_GROUP;
        Dem_SelectDTC_Index[ClientId] = (uint16)0;
        Result = E_OK;
    }

#if(DEM_NUM_OF_DTCGROUP > 0)
    if(Result != E_OK)
    {

        /*Check if the request DTC is a group DTC.*//*SWS_Dem_01254*/
        for(DtcIndex = (uint16)0; DtcIndex < (uint16)DEM_NUM_OF_DTCGROUP_MEMORY(MemSetId); DtcIndex++)
        {

            if(Dem_SelectDTC_DTC[ClientId] == (Dem_UdsDTCType)DEM_CFG_DTC_GROUPVALUE(MemSetId,DtcIndex))
            {
                DTC_MemId = DEM_CFG_GROUP_MEMORY_REF(MemSetId,DtcIndex);
                DTC_ParentMemId = DEM_GET_EVENTMEMORY_ID(DTC_MemId);
                DTC_SubMemId = DEM_GET_SUBMEMORY_ID(DTC_MemId);
                if((MemSetId == DTC_ParentMemId)\
                    && ((Dem_SelectDTC_DTCOrigin[ClientId] == DEM_DTC_ORIGIN_PRIMARY_MEMORY))\
                    && (DTC_SubMemId == (DEM_PRIMARY_MEMORY)))
                {
                    Dem_SelectDTCState[ClientId] = DEM_IN_SELECT_DTC_GROUP;
                    Dem_SelectDTC_Index[ClientId] = DtcIndex;
                    Dem_SelectDTC_ParentMem[ClientId] = DTC_ParentMemId;
                    Dem_SelectDTC_SubMem[ClientId] = DTC_SubMemId;
                    Result = E_OK;
                    break;
                }
#if(DEM_NUM_OF_USERDEF > 0)
                else if((MemSetId == DTC_ParentMemId)\
                    && ((Dem_SelectDTC_DTCOrigin[ClientId] & DEM_DTC_REQURE_USERDEFINED_MEMORY_ID)\
                    == DTC_SubMemId))
                {
                    Dem_SelectDTCState[ClientId] = DEM_IN_SELECT_DTC_GROUP;
                    Dem_SelectDTC_Index[ClientId] = DtcIndex;
                    Dem_SelectDTC_ParentMem[ClientId] = DTC_ParentMemId;
                    Dem_SelectDTC_SubMem[ClientId] = DTC_SubMemId;
                    Result = E_OK;
                    break;
                }
#endif
                else
                {
                    Dem_SelectDTCState[ClientId] = DEM_WRONG_DTCORIGIN;
                    break;
                }

            }

        }
    }
#endif

    /*if the request DTC not a group DTC, it should be a single DTC.*/
    if(Dem_SelectDTCState[ClientId] != DEM_IN_SELECT_DTC_GROUP)
    {

        /*SWS_Dem_00172*/
        for(DtcIndex = (uint16)0; DtcIndex < (uint16)DEM_NUM_OF_DTC; DtcIndex++)
        {
            if(((Dem_SelectDTC_DTCFormat[ClientId] == DEM_DTC_FORMAT_UDS) && (Dem_SelectDTC_DTC[ClientId] == DEM_CFG_DTC_VALUE(DtcIndex)))
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
                || ((Dem_SelectDTC_DTCFormat[ClientId] == DEM_DTC_FORMAT_OBD) && (DEM_CFG_DTC_OBDDTCREF(DtcIndex) != NULL_PTR) \
                    && (Dem_SelectDTC_DTC[ClientId] == DEM_CFG_DTC_OBD_VALUE(DtcIndex)))
#endif
#if(DEM_J1939_SUPPORT == STD_ON)
                || ((Dem_SelectDTC_DTCFormat[ClientId] == DEM_DTC_FORMAT_J1939) && (DEM_CFG_DTC_OBDDTCREF(DtcIndex) != NULL_PTR) \
                && (Dem_SelectDTC_DTC[ClientId] == DEM_CFG_DTC_J1939_VALUE(DtcIndex)))
#endif
			)
            {
                DTC_MemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcIndex);
                DTC_ParentMemId = DEM_GET_EVENTMEMORY_ID(DTC_MemId);
                DTC_SubMemId = DEM_GET_SUBMEMORY_ID(DTC_MemId);
                if((MemSetId == DTC_ParentMemId)\
                    && ((Dem_SelectDTC_DTCOrigin[ClientId] == DEM_DTC_ORIGIN_PRIMARY_MEMORY))\
                    && (DTC_SubMemId == (DEM_PRIMARY_MEMORY)))
                {
                    Dem_SelectDTC_ParentMem[ClientId] = DTC_ParentMemId;
                    Dem_SelectDTC_SubMem[ClientId] = DTC_SubMemId;
                    /*SWS_Dem_01261*/
                    Dem_SelectDTCState[ClientId] =  DEM_IN_SELECT_DTC_SINGLE;
                    Dem_SelectDTC_Index[ClientId] = DtcIndex;
                    Result = E_OK;
                    break;
                }
#if(DEM_NUM_OF_USERDEF > 0)
                else if((MemSetId == DTC_ParentMemId)\
                    && ((Dem_SelectDTC_DTCOrigin[ClientId] & DEM_DTC_REQURE_USERDEFINED_MEMORY_ID)\
                    == DTC_SubMemId))
                {
                    /*SWS_Dem_01261*/
                    Dem_SelectDTC_ParentMem[ClientId] = DTC_ParentMemId;
                    Dem_SelectDTC_SubMem[ClientId] = DTC_SubMemId;
                    Dem_SelectDTCState[ClientId] =  DEM_IN_SELECT_DTC_SINGLE;
                    Dem_SelectDTC_Index[ClientId] = DtcIndex;
                    Result = E_OK;
                    break;
                }
#endif
                else
                {
                    Dem_SelectDTCState[ClientId] = DEM_WRONG_DTCORIGIN;
                    break;
                }
            }
        }
    }
    /*SWS_Dem_01261*/
    if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_CHECKING)
    {
        Dem_SelectDTCState[ClientId] = DEM_WRONG_DTC;
        Result = E_NOT_OK;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_ClearDTCAllowed
*
* Description: Clear the RAM info of one DTC
*
* Inputs: DtcId
*
* Outputs: None
*
* Return: None
*
* Limitations: Used for UDS and J1939
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_ClearDTCAllowed
(
    Dem_EventIdType EventId
)
{
    Std_ReturnType ret = E_OK;
    boolean ClearAllowed = TRUE;

#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
        /*SWS_Dem_01108*/
        if(Dem_EventAvailable[EventId] == TRUE)
#endif
        {
            if(DEM_CFG_EVENT_CLEARALLOWED_CALLFNC(EventId) != NULL_PTR)
            {
                /*SWS_Dem_00514*//*SWS_Dem_00515*/
                ret = DEM_CFG_EVENT_CLEARALLOWED_CALLFNC(EventId)(&ClearAllowed);
            }
            if(ret == E_OK)
            {
                if(ClearAllowed != TRUE)
                {
                    ret = DEM_CLEAR_FAILED;
                }
            }
            else
            {
                ret = E_OK;
            }
        }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
        else
        {
            ret = DEM_CLEAR_FAILED;
        }
#endif

    return ret;

}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_ClearOneDTC
*
* Description: Clear the RAM info of one DTC
*
* Inputs: DtcId
*
* Outputs: None
*
* Return: None
*
* Limitations: Used for UDS and J1939
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_ClearOneDTC
(
    uint16 DtcId
)
{

    Dem_UdsStatusByteType DTCOldStatus;
    Dem_UdsStatusByteType DTCNewStatus;
    Dem_UdsStatusByteType EventOldStatus;
    Dem_UdsStatusByteType EventNewStatus;
    uint16 EventId;
    uint16 EventMemoryId;
    Std_ReturnType ret = E_OK;
    uint8 ParentMemId,SubMemId;
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
    uint8 EventNum = (uint8)0;
#endif
#if(DEM_CFG_EVENT_WITHOUT_REF_DTC_MEMORY != 0xFFFF)
    boolean EventWithoutRefDTC = FALSE;
    uint8 EventParentMemId;
    uint8 EventSubMemId;
#endif
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    DTCOldStatus = DEM_DTC_STATUS(DtcId);
    DTCNewStatus = DEM_DTC_STATUS(DtcId);

    EventMemoryId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId);
    ParentMemId = DEM_GET_EVENTMEMORY_ID(EventMemoryId);
    SubMemId = DEM_GET_SUBMEMORY_ID(EventMemoryId);
#if(DEM_CFG_EVENT_WITHOUT_REF_DTC_MEMORY != 0xFFFF)
    EventParentMemId = DEM_GET_EVENTMEMORY_ID(DEM_CFG_EVENT_WITHOUT_REF_DTC_MEMORY);
    EventSubMemId = DEM_GET_SUBMEMORY_ID(DEM_CFG_EVENT_WITHOUT_REF_DTC_MEMORY);
    if((EventParentMemId == ParentMemId) && (EventSubMemId == SubMemId))
    {
        EventWithoutRefDTC = TRUE;
    }
#endif

    do
    {
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
        if(DEM_IS_COMBINEDDTC(DtcId))
        {
            EventId = DEM_CFG_DTC_EVENTREF(DtcId,EventNum);
        }
        else
#endif
        {
            EventId = DEM_CFG_DTC_EVENTREF(DtcId);
        }
#if((DEM_CORE_NUMBER > 1) && (DEM_CLEAR_EVENT_ALLOWED_CALLBACK_SUPPORT == STD_ON))
        if(CoreId != DEM_CFG_EVENT_COREREF(EventId))
        {
            if(DEM_CFG_EVENT_CLEARALLOWED_CALLFNC(EventId) != NULL_PTR)
            {
                ret = DEM_CLEAR_EVENT_ALLOWED_RESULT(EventId);
            }
        }
        else
#endif
#if(DEM_CLEAR_EVENT_ALLOWED_CALLBACK_SUPPORT == STD_ON)
        {

            ret = DemInternal_ClearDTCAllowed(EventId);
        }
#endif
        if(ret != DEM_CLEAR_FAILED)
        {
            EventOldStatus = DEM_EVENT_STATUS(EventId);
            DemInternal_ClearOneEvent(EventId, FALSE);
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
            if(DEM_IS_COMBINEDDTC(DtcId))
            {

#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
                if(DEM_EVENT_DATAENTRYREF(EventId) != DEM_DATA_INVALID_U8)
                {
                    DemInternal_ClearOneMemoryEntry(ParentMemId,(DEM_EVENT_DATAENTRYREF(EventId)),SubMemId);
#if(DEM_CFG_CLEARDTCBEHAIOR == DEM_CLRRESP_VOLATILE)
                    DEM_EVENT_DATAENTRYREF(EventId) = DEM_DATA_INVALID_U8;
#endif
                }
#else
                /*SWS_Dem_00399*/
                if(DEM_DTC_DATAENTRYREF(DtcId) != DEM_DATA_INVALID_U8)
                {
                    /*SWS_Dem_00399*/
                    DemInternal_ClearOneMemoryEntry(ParentMemId,DEM_DTC_DATAENTRYREF(DtcId),SubMemId);
#if(DEM_CFG_CLEARDTCBEHAIOR == DEM_CLRRESP_VOLATILE)
                    DEM_DTC_DATAENTRYREF(DtcId) = DEM_DATA_INVALID_U8;
#endif
                }
#endif
                /*SWS_Dem_00659*//*SWS_Dem_00680*/ /*SWS_Dem_01332*/
                EventNewStatus = DEM_EVENT_STATUS(EventId);

            }
            else
#endif /*#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)*/
            {
                DEM_DTC_STATUS(DtcId) = DEM_STATUS_RESET;
#if(DEM_DTC_LASTSTATUS_SUPPORT == STD_ON)
                DEM_DTC_LASTSTATUS(DtcId) = DEM_STATUS_RESET;
#endif
                DEM_DTC_AGINGCNT(DtcId) = DEM_DATA_CLEAR;
#if(DEM_DTC_AGEDCNT_SUPPORT == STD_ON)
                DEM_DTC_AGEDCNT(DtcId) = DEM_DATA_CLEAR;
#endif
                if(DEM_DTC_DATAENTRYREF(DtcId) != DEM_DATA_INVALID_U8)
                {
                    DemInternal_ClearOneMemoryEntry(ParentMemId,DEM_DTC_DATAENTRYREF(DtcId),SubMemId);
#if(DEM_CFG_CLEARDTCBEHAIOR == DEM_CLRRESP_VOLATILE)
                    DEM_DTC_DATAENTRYREF(DtcId) = DEM_DATA_INVALID_U8;
#endif
                }
                EventNewStatus = DEM_EVENT_STATUS(EventId);
                DTCNewStatus = DEM_DTC_STATUS(DtcId);
            }
        }
        else
        {
            EventOldStatus = DEM_EVENT_STATUS(EventId);
            EventNewStatus = DEM_EVENT_STATUS(EventId);
            if(DEM_CFG_EVENT_CLEARALLOWED_BEHAVIOR(EventId) == DEM_ONLY_THIS_CYCLE_AND_READINESS)
            {
                /*bit1*/
                EventNewStatus = DEM_CLEAR_UDS_STATUS_TFTOC(EventNewStatus);
                /*bit4*/
                EventNewStatus = DEM_SET_UDS_STATUS_TNCSLC(EventNewStatus);
                /*bit5*/
                EventNewStatus = DEM_CLEAR_UDS_STATUS_TFSLC(EventNewStatus);
                /*bit6*/
                EventNewStatus = DEM_SET_UDS_STATUS_TNCTOC(EventNewStatus);
                DEM_EVENT_STATUS(EventId) = EventNewStatus;
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
                if(!DEM_IS_COMBINEDDTC(DtcId))
                {
                    DEM_DTC_STATUS(DtcId) = DEM_EVENT_STATUS(EventId);
                    DTCNewStatus = DEM_DTC_STATUS(DtcId);
                }
#endif
            }

        }
        if(EventOldStatus != EventNewStatus)
        {
            DemInternal_EventStatusChangedNotification(EventId,EventOldStatus, EventNewStatus);
        }
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
        if(DEM_IS_COMBINEDDTC(DtcId))
        {
            DTCNewStatus = DemInternal_UpdateCombinedDTC(EventId);
            if((EventNum + 1) < DEM_CFG_DTC_COMBINEDEVENTNUM(DtcId))
            {
                EventNum ++;
            }
            else
            {
                EventId = DEM_NUM_OF_EVENT;
            }
        }
        else
#endif
        {
            break;
        }
    }while (EventId != DEM_NUM_OF_EVENT);

    if(DTCNewStatus != DTCOldStatus)
    {
        DemInternal_DTCStatusChangedNotification(DEM_CFG_DTC_VALUE(DtcId), DTCOldStatus, DTCNewStatus);
    }
    /*SWS_Dem_01240*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
    if(ret != DEM_CLEAR_FAILED)
    {
        Dem_DTC_FirstFdcThreshold[DtcId] = FALSE;
    }
#endif
    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_ClearOneEvent
*
* Description: Clear data information of one event
*
* Inputs: EventId
*         Aging: TRUE-clear because of aging;
*                FALSE-Clear because of Clear Command
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_ClearOneEvent
(
    Dem_EventIdType EventId,
    boolean Aging
)
{
#if(DEM_NUM_OF_INDICATOR > 0)
    uint8 Index;
    uint8 IndicatorId;
    uint16 StatusPos;
#endif
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    DEM_EVENT_STATUS(EventId) = DEM_STATUS_RESET;
    DEM_EVENT_FCC(EventId) = DEM_DATA_CLEAR;
    DEM_EVENT_OCCCTR(EventId) = DEM_DATA_CLEAR;
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
    /*SWS_Dem_00343*/
    DEM_EVENT_DBC(EventId) = (sint16)DEM_DATA_CLEAR;
#endif

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
    DEM_EVENT_DBT(EventId) = (uint32)0;
    DEM_EVENT_TIMERDIRECTION(EventId) = DEM_DATA_INVALID_U8;
    Dem_EventDBTFreezeFlag[EventId] = FALSE;
#endif
#if(DEM_EVENT_MAXFDCDCC_SUPPORT == STD_ON)
    DEM_EVENT_MAXFDCDCC(EventId) = (sint8)0;
#endif
#if(DEM_EVENT_MAXFDCSLC_SUPPORT == STD_ON)
    /*SWS_Dem_00794*/
    DEM_EVENT_MAXFDCSLC(EventId) = (sint8)0;
#endif
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
    DEM_EVENT_AGINGCNT(EventId) = DEM_DATA_CLEAR;
#endif
#if(DEM_EVENT_CSLF_SUPPORT == STD_ON)
    DEM_EVENT_CSLF(EventId) = DEM_DATA_CLEAR;
#endif
#if(DEM_EVENT_CSFF_SUPPORT == STD_ON)
    DEM_EVENT_CSFF(EventId) = DEM_DATA_CLEAR;
#endif
#if(DEM_EVENT_FCSLC_SUPPORT == STD_ON)
    DEM_EVENT_FCSLC(EventId) = DEM_DATA_CLEAR;
#endif
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    DEM_EVENT_OBD_PCSLF(EventId) = DEM_DATA_CLEAR;
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    DEM_EVENT_CMA_PCSLF(EventId) = DEM_DATA_CLEAR;
    DEM_EVENT_CMA_STATUS(EventId) = DEM_DATA_CLEAR;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    if(DEM_CFG_EVENT_DTCREF(i) != DEM_DATA_INVALID_U16)
    {
        if(DEM_DTC_IS_OBD(DEM_CFG_EVENT_DTCREF(i)))
        {
            DEM_EVENT_CMA_STATUS(i) = (uint8)0x40;
        }
    }
#endif
#endif

    if(Aging == FALSE)
    {
#if(DEM_INITMFORE_CALLBACK_SUPPORT == STD_ON)
        if(DEM_CFG_EVENT_INITM_CALLFNC(EventId) != NULL_PTR)
        {
#if(DEM_CORE_NUMBER > 1)
            if(CoreId != DEM_CFG_EVENT_COREREF(EventId))
            {
                DEM_CFG_EVENT_INITM_FLAG(EventId) = TRUE;
                DEM_CFG_EVENT_INITM_REASON(EventId) = DEM_INIT_MONITOR_CLEAR;
            }
            else
#endif
            {
                DEM_CFG_EVENT_INITM_CALLFNC(EventId)(DEM_INIT_MONITOR_CLEAR);
            }
        }
#endif
#if(DEM_NUM_OF_INDICATOR > 0)
        if((DEM_CFG_EVENT_INDICATOR_NUM(EventId) > (uint8)0) \
            && (DEM_CFG_EVENT_INDICATOR(EventId) != NULL_PTR))
        {

            DEM_EVENT_IFCC(EventId) = DEM_DATA_CLEAR;
            DEM_EVENT_IHCC(EventId) = DEM_DATA_CLEAR;

            for(Index = (uint8)0; Index < DEM_CFG_EVENT_INDICATOR_NUM(EventId); Index++)
            {
                IndicatorId = DEM_CFG_EVENT_INDICATOR_ID(EventId,Index);
                StatusPos = DEM_CFG_EVENT_INDICATOR_OFFSET(EventId,Index) \
                                + DEM_CFG_INDICATOR_STATUS_START(IndicatorId);

                if(DEM_INDICATOR_STATUS(StatusPos) != DEM_INDICATOR_OFF)
                {
                    DEM_INDICATOR_STATUS(StatusPos) = DEM_INDICATOR_OFF;

                    if(DEM_CFG_INDICATOR_STATUS_FNC(IndicatorId) != NULL_PTR)
                    {
                        (void)DEM_CFG_INDICATOR_STATUS_FNC(IndicatorId)(EventId, DEM_INDICATOR_OFF);
                    }
                }
            }
        }/*if((DEM_CFG_EVENT_INDICATOR_NUM(EventId) > (uint8)0) \
              && (DEM_CFG_EVENT_INDICATOR(EventId) != NULL_PTR))*/
#endif/*#if(DEM_NUM_OF_INDICATOR > 0)*/

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
        DemInternal_ClearOBDFreezeFrame(EventId);
#endif

#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
        DEM_EVENT_OBD_CLEAR_FLAG(EventId) = TRUE;
#endif
    }/*if(Aging == FALSE)*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_DTCMemoryCheck
(
    uint16 DtcId
)
{
    uint16 DTC_MemoryId;
    uint8 Client_MemoryId;
    Std_ReturnType ret = E_NOT_OK;
    Client_MemoryId = DEM_CLIENT_EVENT_MEM(Dem_ClearDTC_Client);
    DTC_MemoryId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId);

    if(Dem_ClearDTC_DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
    {
        if(Dem_ClearDTC_DTCFormat == DEM_DTC_FORMAT_UDS)
        {
            if((DEM_GET_EVENTMEMORY_ID(DTC_MemoryId) == Client_MemoryId) \
                && (DEM_GET_SUBMEMORY_ID(DTC_MemoryId) == DEM_PRIMARY_MEMORY))
            {
                ret = E_OK;
            }
        }
    }
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)||(DEM_J1939_SUPPORT == STD_ON))
    else if(Dem_ClearDTC_DTCOrigin == DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY)
    {
        if(Dem_ClearDTC_DTCFormat == DEM_DTC_FORMAT_OBD)
        {
            if((DEM_GET_EVENTMEMORY_ID(DTC_MemoryId) == Client_MemoryId) \
            && (Client_MemoryId == DEM_CFG_OBD_EVENT_MEMORY_REF) \
            && (DEM_GET_SUBMEMORY_ID(DTC_MemoryId) == DEM_PRIMARY_MEMORY))
            {
                if(DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR)
                {
                    ret = E_OK;
                }
            }
        }
    }
#endif
    else
    {
        /*do nothing*/
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_ClearOneDTCGroup
(
    void
)
{
    Std_ReturnType Result = E_OK;
    uint16 DtcIndex;
    uint16 MaxIndexCurrentCycle;
    MaxIndexCurrentCycle = DemInternal_GetDTCGroupMaxIndex();

    for(DtcIndex = Dem_ClearDTC_Index; DtcIndex < MaxIndexCurrentCycle; DtcIndex++)
    {
        if(Dem_ClearDTCInfo.ClearDTCTable[DtcIndex] == TRUE)
        {
            if(E_OK == DemInternal_DTCMemoryCheck(DtcIndex))
            {
                Dem_ClearDTCInfo.ClearDTCNum++;
                if(Dem_ClearDTCState != DEM_IN_CLEAR_DTC_ERR)
                {
                    /*SWS_Dem_01202*/
                    Result = DemInternal_ClearOneDTC(DtcIndex);
                    if(Result != DEM_CLEAR_FAILED)
                    {
#if(DEM_CFG_CLEARDTCBEHAIOR != DEM_CLRRESP_VOLATILE)
                        DemInternal_ClearEntryInNvm(DtcIndex);
#endif
                    }
                    else
                    {
                        Dem_ClearDTCInfo.ClearDTCFailedNum ++;
                    }

                }
                else
                {
                    Dem_ClearDTCInfo.ClearDTCNum = (uint16)0;
                    Dem_ClearDTCInfo.ClearDTCFailedNum = (uint16)0;
                    break; /*clear failed*/
                }
            }
            Dem_ClearDTCInfo.ClearDTCTable[DtcIndex] = FALSE;
        }

    }
    /*PRQA S 2995 ++*/
    if(MaxIndexCurrentCycle == DEM_NUM_OF_DTC)
    {
        if((Dem_ClearDTCInfo.ClearDTCNum == Dem_ClearDTCInfo.ClearDTCFailedNum) && (Dem_ClearDTCInfo.ClearDTCNum != (uint16)0))
        {
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_FAILED;
        }
        else
        {
#if(DEM_CFG_CLEARDTCBEHAIOR == DEM_CLRRESP_VOLATILE)
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_OK;
            Dem_SelectDTCState[Dem_ClearDTC_Client] = DEM_IN_SELECT_DTC_IDLE;
#else
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_BUSY_GROUP;
#endif
        }
        Dem_ClearDTCInfo.ClearDTCNum = (uint16)0;
        Dem_ClearDTCInfo.ClearDTCFailedNum = (uint16)0;
        if((DEM_CFG_CLEAR_DTC_NOTIFICATION_FUN(DEM_CLIENT_EVENT_MEM(Dem_ClearDTC_Client)) != NULL_PTR) \
            &&(DEM_CFG_CLEAR_DTC_NOTIFICATION_TIME(DEM_CLIENT_EVENT_MEM(Dem_ClearDTC_Client)) == FINISH))
        {
            (void)DEM_CFG_CLEAR_DTC_NOTIFICATION_FUN(DEM_CLIENT_EVENT_MEM(Dem_ClearDTC_Client))(Dem_ClearDTC_DTC, Dem_ClearDTC_DTCFormat, Dem_ClearDTC_DTCOrigin);
        }


    }
    /*PRQA S 2995 --*/
    /*Update the start index value for the next cycle to clear DTC.*/
    Dem_ClearDTC_Index = MaxIndexCurrentCycle;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetEventFreezeFrameDataEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    uint16 DataId,
    uint8 *DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
    uint16 DtcId;
    Dem_MemIdType MemEntryId;
    uint8 *SrcDataPtr;
    uint8 i;
    uint8 j;
    uint8 k;
    uint8 RecIdx;
    uint8 DidIdx;
    uint16 DataIdx;
    uint8 MemId;
#endif
    uint16 DataSize = (uint16)0;

#if(DEM_MAX_FFSIZE_OF_DTC > 0)
#if(DEM_NUM_OF_FFRECCLASS > 0)

    DtcId = DEM_CFG_EVENT_DTCREF(EventId);

    if(DEM_CFG_DTC_FFRECNUMCLASSREF(DtcId) != NULL_PTR)
    {
        MemEntryId = DEM_DTC_DATAENTRYREF(DtcId);
        MemId = DEM_GET_EVENTMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId));
        SrcDataPtr = DEM_PRIMARY_FFDATA_PTR(MemId,MemEntryId);

        for(i = (uint8)0; i < (uint8)DEM_CFG_DTC_NUM_OF_FFREC(DtcId); i++)
        {
            RecIdx = (DEM_CFG_DTC_FFREC_ARRAY(DtcId)[i]);

            if(SrcDataPtr[0] == RecordNumber)
            {
                /*+ RecNum length(one byte) + RecordNumberOfIdentifiers length(one byte)*/
                SrcDataPtr += DEM_DATA_LENGTH_2;

                for(j = (uint8)0; j < (uint8)DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx); j++)
                {
                    /*Did length(two bytes)*/
                    SrcDataPtr += DEM_DATA_LENGTH_2;

                    DidIdx = (DEM_CFG_DIDARRAY_OF_FFRECNUM(RecIdx)[j]);
                    if(DataId == DEM_CFG_DID(DidIdx))
                    {
                        for(k = (uint8)0; k < (uint8)DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                        {
                            DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);
                            if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                            {
                                /*SWS_Dem_00817*/
                                DemInternal_GetDtcInternalData(DtcId, DataIdx, SrcDataPtr);
                                DataSize += DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                            }

                            if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                            {
                                DataSize += DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                            }
                        }
                        /*SWS_Dem_00991*/
                        if(*BufSize >= DataSize)
                        {
                            Bsw_MemCpy(DestBuffer, SrcDataPtr, (uint32)DataSize);
                            *BufSize = DataSize;
                        }
                        else
                        {
                            Result = E_NOT_OK;
                        }
                        break;
                    }
                    else
                    {
                        for(k = (uint8)0; k < DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                        {
                            DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);
                            if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                            {
                                /*SWS_Dem_00817*/
                                DemInternal_GetDtcInternalData(DtcId, DataIdx, SrcDataPtr);
                                SrcDataPtr += DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                            }

                            if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                            {
                                SrcDataPtr += DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                            }
                        }
                    }
                }
                break;
            }
            else
            {
                /*+ RecNum length(one byte) + RecordNumberOfIdentifiers length(one byte)*/
                SrcDataPtr += DEM_DATA_LENGTH_2;

                for(j = (uint8)0; j < (uint8)DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx); j++)
                {
                    /*Did length(two bytes)*/
                    SrcDataPtr += DEM_DATA_LENGTH_2;

                    DidIdx = (DEM_CFG_DIDARRAY_OF_FFRECNUM(RecIdx)[j]);
                    for(k = (uint8)0; k < (uint8)DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                    {
                        DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);
                        if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                        {
                            /*SWS_Dem_00817*/
                            DemInternal_GetDtcInternalData(DtcId, DataIdx, SrcDataPtr);
                            SrcDataPtr += DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                        }

                        if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                        {
                            SrcDataPtr += DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                        }
                    }
                }
            }
        }
    }
#endif
#endif
    if(DataSize == (uint16)0)
    {
        Result = E_NOT_OK;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetEventExtendedDataRecordEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
    uint16 DtcId;
    Dem_MemIdType MemEntryId;
    uint8 *SrcDataPtr;
    uint8 i;
    uint8 j;
    uint8 RecIdx;
    uint16 DataIdx;
    uint8 MemId;
#endif
    uint16 DataSize = (uint16)0;

#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
#if(DEM_NUM_OF_EXTDATACLASS > 0)

    DtcId = DEM_CFG_EVENT_DTCREF(EventId);

    if(DEM_CFG_DTC_EXTDATACLASSREF(DtcId) != NULL_PTR)
    {
        MemEntryId = DEM_DTC_DATAENTRYREF(DtcId);
        MemId = DEM_GET_EVENTMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId));
        SrcDataPtr = DEM_PRIMARY_EXTDATA_PTR(MemId,MemEntryId);

        for(i = (uint8)0; i < DEM_CFG_DTC_NUM_OF_EXTREC(DtcId); i++)
        {
            RecIdx = (DEM_CFG_DTC_EXTREC_ARRAY(DtcId)[i]);

            if(SrcDataPtr[0] == RecordNumber)
            {
                /*+ DataRecNum length(one byte)*/
                SrcDataPtr += 1;

                for(j = (uint8)0; j < DEM_CFG_NUMDATA_OF_EXTRECNUM(RecIdx); j++)
                {
                    DataIdx = (DEM_CFG_DATAARRAY_OF_EXTRECNUM(RecIdx)[j]);
                    if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                    {
                        /*SWS_Dem_00817*/
                    	DemInternal_GetDtcInternalData(DtcId, DataIdx, SrcDataPtr);
                        DataSize += DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                    }

                    if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                    {
                        DataSize += DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                    }
                }
                /*SWS_Dem_00989*/
                if(*BufSize >= DataSize)
                {
                    Bsw_MemCpy(DestBuffer, SrcDataPtr, (uint32)DataSize);
                    *BufSize = DataSize;
                }
                else
                {
                    Result = E_NOT_OK;
                }
                break;
            }
            else
            {
                /*+ DataRecNum length(one byte)*/
                SrcDataPtr += (uint32)1;

                for(j = (uint8)0; j < DEM_CFG_NUMDATA_OF_EXTRECNUM(RecIdx); j++)
                {
                    DataIdx = (DEM_CFG_DATAARRAY_OF_EXTRECNUM(RecIdx)[j]);
                    if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                    {
                        /*SWS_Dem_00817*/
                    	DemInternal_GetDtcInternalData(DtcId, DataIdx, SrcDataPtr);
                        SrcDataPtr += DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                    }

                    if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                    {
                        SrcDataPtr += DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                    }
                }
            }
        }
    }
#endif
#endif
    if(DataSize == 0)
    {
        Result = E_NOT_OK;
    }
    return Result;
}

#if(DEM_NUM_OF_INDICATOR > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_IndicatorOnCriteriaFulfilled
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_IndicatorOnCriteriaFulfilled
(
    Dem_EventIdType EventId,
    Dem_UdsStatusByteType EventOldStatus,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) EventNewStatus
)
{
    uint8 Index;
    uint8 IndicatorId;
    uint16 StatusPos;
    boolean SetWIRBit = FALSE;
    Dem_UdsStatusByteType NewStatus = *EventNewStatus;

    if((DEM_CFG_EVENT_INDICATOR_NUM(EventId) > (uint8)0) \
        && (DEM_CFG_EVENT_INDICATOR(EventId) != NULL_PTR))
    {
        if((DEM_TEST_UDS_STATUS_TFTOC(NewStatus))\
            &&(!DEM_TEST_UDS_STATUS_TFTOC(EventOldStatus)))
        {
            /*SWS_Dem_00506*/
            DEM_EVENT_IHCC(EventId) = DEM_DATA_CLEAR;

            if(DEM_EVENT_IFCC(EventId) < DEM_DATA_U8_FF)
            {
                DEM_EVENT_IFCC(EventId)++;
            }

            if(DEM_TEST_UDS_STATUS_CDTC(NewStatus))
            {
                DEM_EVENT_IFCC(EventId) = DEM_DATA_U8_FF;
            }
        }

        for(Index = (uint8)0; Index < DEM_CFG_EVENT_INDICATOR_NUM(EventId); Index++)
        {
            IndicatorId = DEM_CFG_EVENT_INDICATOR_ID(EventId,Index);
            StatusPos = DEM_CFG_EVENT_INDICATOR_OFFSET(EventId,Index) \
                            + DEM_CFG_INDICATOR_STATUS_START(IndicatorId);

            if((DEM_INDICATOR_STATUS(StatusPos) == DEM_INDICATOR_OFF) \
                && (DEM_EVENT_IFCC(EventId) >= DEM_CFG_EVENT_INDICATOR_F_THRESHOLD(EventId,Index)))
            {
                /*SWS_Dem_00501*/
                DEM_INDICATOR_STATUS(StatusPos) = DEM_CFG_EVENT_INDICATOR_BEHAVIOUR(EventId,Index);
                SetWIRBit = TRUE;

                if(DEM_CFG_INDICATOR_STATUS_FNC(IndicatorId) != NULL_PTR)
                {
                    (void)DEM_CFG_INDICATOR_STATUS_FNC(IndicatorId)(EventId, (DEM_INDICATOR_STATUS(StatusPos)));
                }
            }
        }

        if(SetWIRBit == TRUE)
        {
            /*SWS_Dem_00566*/
            NewStatus = DEM_SET_UDS_STATUS_WIR(NewStatus);
            *EventNewStatus = NewStatus;
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_IndicatorOffCriteriaFulfilled
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_IndicatorOffCriteriaFulfilled
(
    Dem_EventIdType EventId,
    Dem_IndicatorOffType OffReason,
    Dem_UdsStatusByteType EventOldStatus,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) EventNewStatus
)
{
    uint8 Index;
    uint8 IndicatorId;
    uint16 StatusPos;
    boolean ClearWIRBit = TRUE;
    Dem_UdsStatusByteType NewStatus = *EventNewStatus;

    if((DEM_CFG_EVENT_INDICATOR_NUM(EventId) > (uint8)0) \
        && (DEM_CFG_EVENT_INDICATOR(EventId) != NULL_PTR))
    {
        if((OffReason == DEM_CYCLE_END) \
            && (!DEM_TEST_UDS_STATUS_TNCTOC(EventOldStatus)) \
            && (!DEM_TEST_UDS_STATUS_TFTOC(EventOldStatus)))
        {
            /*SWS_Dem_00506*/
            DEM_EVENT_IFCC(EventId) = DEM_DATA_CLEAR;

            if((DEM_TEST_UDS_STATUS_WIR(EventOldStatus)) \
                && (DEM_EVENT_IHCC(EventId) < DEM_DATA_U8_FF))/*  */
            {
                DEM_EVENT_IHCC(EventId)++;
            }
        }

        for(Index = (uint8)0; Index < DEM_CFG_EVENT_INDICATOR_NUM(EventId); Index++)
        {
            IndicatorId = DEM_CFG_EVENT_INDICATOR_ID(EventId,Index);
            StatusPos = DEM_CFG_EVENT_INDICATOR_OFFSET(EventId,Index) \
                            + DEM_CFG_INDICATOR_STATUS_START(IndicatorId);

            if((DEM_INDICATOR_STATUS(StatusPos) != DEM_INDICATOR_OFF) \
                && (DEM_EVENT_IHCC(EventId) >= DEM_CFG_EVENT_INDICATOR_H_THRESHOLD(EventId,Index)))
            {
                /*SWS_Dem_00503*/ /*SWS_Dem_001233*/
                DEM_INDICATOR_STATUS(StatusPos) = DEM_INDICATOR_OFF;

                if(DEM_CFG_INDICATOR_STATUS_FNC(IndicatorId) != NULL_PTR)
                {
                    (void)DEM_CFG_INDICATOR_STATUS_FNC(IndicatorId)(EventId, (DEM_INDICATOR_STATUS(StatusPos)));
                }
            }
            if(DEM_INDICATOR_STATUS(StatusPos) != DEM_INDICATOR_OFF)
            {
                ClearWIRBit = FALSE;
            }
        }

        if(ClearWIRBit == TRUE)
        {
            /*SWS_Dem_00533*//*SWS_Dem_00835*/
            NewStatus = DEM_CLEAR_UDS_STATUS_WIR(NewStatus);
            *EventNewStatus = NewStatus;
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetIndicatorStatus
*
* Description: Get the indicator status internally.
*
* Inputs: IndicatorId
*
* Outputs: IndicatorStatus
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_GetIndicatorStatus
(
    uint8 IndicatorId,
    P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus
)
{
    uint16 Index;
    uint16 StartIndex;
    uint16 EndIndex;

    *IndicatorStatus = DEM_INDICATOR_OFF;

    StartIndex = DEM_CFG_INDICATOR_STATUS_START(IndicatorId);
    EndIndex = DEM_CFG_INDICATOR_STATUS_START(IndicatorId) + DEM_CFG_INDICATOR_STATUS_NUM(IndicatorId);

    for(Index = StartIndex; Index < EndIndex; Index++)
    {
        if(*IndicatorStatus == DEM_INDICATOR_OFF)
        {
            *IndicatorStatus = DEM_INDICATOR_STATUS(Index);
        }
        else if((DEM_INDICATOR_STATUS(Index) == DEM_INDICATOR_BLINK_CONT)\
            || (*IndicatorStatus == DEM_INDICATOR_BLINK_CONT))
        {
            *IndicatorStatus = DEM_INDICATOR_BLINK_CONT;
            break;
        }
        else if((DEM_INDICATOR_STATUS(Index) == DEM_INDICATOR_BLINKING)\
            && (*IndicatorStatus != DEM_INDICATOR_BLINKING))
        {
            *IndicatorStatus = DEM_INDICATOR_BLINKING;
        }
        else if((*IndicatorStatus != DEM_INDICATOR_BLINKING)\
            && (DEM_INDICATOR_STATUS(Index) == DEM_INDICATOR_FAST_FLASH))
        {
            *IndicatorStatus = DEM_INDICATOR_FAST_FLASH;
        }
        else if((*IndicatorStatus != DEM_INDICATOR_FAST_FLASH) \
            && (*IndicatorStatus != DEM_INDICATOR_BLINKING)\
            && (DEM_INDICATOR_STATUS(Index) == DEM_INDICATOR_SLOW_FLASH))
        {
            *IndicatorStatus = DEM_INDICATOR_SLOW_FLASH;
        }
        else if((*IndicatorStatus != DEM_INDICATOR_FAST_FLASH) \
            && (*IndicatorStatus != DEM_INDICATOR_BLINKING)\
            && (*IndicatorStatus != DEM_INDICATOR_SLOW_FLASH) \
            && (DEM_INDICATOR_STATUS(Index) == DEM_INDICATOR_CONTINUOUS))
        {
            *IndicatorStatus = DEM_INDICATOR_CONTINUOUS;
        }
        else if((*IndicatorStatus != DEM_INDICATOR_FAST_FLASH) \
            && (*IndicatorStatus != DEM_INDICATOR_BLINKING)\
            && (*IndicatorStatus != DEM_INDICATOR_SLOW_FLASH)\
            && (*IndicatorStatus != DEM_INDICATOR_CONTINUOUS) \
            && (DEM_INDICATOR_STATUS(Index) == DEM_INDICATOR_SHORT))
        {
            *IndicatorStatus = DEM_INDICATOR_SHORT;
        }
        else if((*IndicatorStatus != DEM_INDICATOR_FAST_FLASH) \
            && (*IndicatorStatus != DEM_INDICATOR_BLINKING)\
            && (*IndicatorStatus != DEM_INDICATOR_SLOW_FLASH)\
            && (*IndicatorStatus != DEM_INDICATOR_CONTINUOUS) \
            && (*IndicatorStatus != DEM_INDICATOR_SHORT)\
            && (DEM_INDICATOR_STATUS(Index) == DEM_INDICATOR_ON_DEMAND))
        {
            *IndicatorStatus = DEM_INDICATOR_ON_DEMAND;
        }
        else
        {
            /*do nothing*/
        }
    }
}
#endif/*#if(DEM_NUM_OF_INDICATOR > 0)*/

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_InitOBDData
*
* Description: Init data value of OBD function
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_InitOBDData
(
    void
)
{
    uint16 i;

    /*Used for PID01/41*/
    DEM_OBD_READINESSGROUP_STATUS[0] = (uint8)0x03;
    DEM_OBD_READINESSGROUP_STATUS[0] = (uint8)0xFF;
    /*Used for PID31.Unit:m, Range:0-65535000*/
    DEM_OBD_DISTANCE_SINCEDTCCLEARED = DEM_DATA_CLEAR;
    DEM_OBD_DISTANCE_MILACTIVATED = DEM_DATA_CLEAR;
    /*Data for Service 02*/
    DEM_OBD_FF_EVENT = DEM_EVENT_ID_INVALID;
    for(i = (uint16)0; i < DEM_CFG_OBD_FF_LENGTH; i++)
    {
        DEM_OBD_FF_DATA_BUF[i] = DEM_DATA_INVALID_U8;
    }
    /*Data for Service 09*/
#if(DEM_NUM_OF_RATIO > 0)
    DEM_OBD_RATIO_IGN_CNT = DEM_DATA_CLEAR;
    DEM_OBD_RATIO_GENDEN_CNT = DEM_DATA_CLEAR;
    DEM_OBD_RATIO_GENDEN_STATE = DEM_DATA_CLEAR;
    DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_GENERAL) = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
    DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_COLDSTART) = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
    DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_EVAP) = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
    DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_500MILL) = DEM_IUMPR_DEN_STATUS_NOT_REACHED;
    for(i = (uint16)0; i < DEM_NUM_OF_RATIO; i++)
    {
        DEM_OBD_RATIO_NUMERATOR(i) = DEM_DATA_CLEAR;
        DEM_OBD_RATIO_DENOMINATOR(i) = DEM_DATA_CLEAR;
        DEM_OBD_RATIO_STATE(i) = DEM_DATA_CLEAR;
    }
#endif

#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
    DEM_OBD_PFC_CYCLE_STATUS = FALSE;
#endif

}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_StoreOBDFreezeFrame
*
* Description: EventId, EventOldStatus, EventNewStatus
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_StoreOBDFreezeFrame
(
    Dem_EventIdType EventId,
    Dem_UdsStatusByteType EventOldStatus,
    Dem_UdsStatusByteType EventNewStatus
)
{
    uint8 PidIndex;
    uint8 DataIndex;/*Data index in PID*/
    uint8 i;
    uint16 DataEleIndex;/*Data index in DemDataElementClass*/
    Dem_PriorityType StoredEventPriority;
    Dem_PriorityType StoringEventPriority;
    uint8 *DataPtr;
    boolean UpdateFlag = FALSE;
    Std_ReturnType Result = E_OK;

    if(DEM_CFG_DTC_OBDDTCREF(DEM_CFG_EVENT_DTCREF(EventId)) != NULL_PTR)
    {
        if(DEM_OBD_FF_EVENT == DEM_EVENT_ID_INVALID)
        {
            /*The OBD freeze frame buffer is empty.*/
            UpdateFlag = TRUE;
        }
        else if(DEM_OBD_FF_EVENT == EventId)
        {
            if((DEM_TEST_UDS_STATUS_CDTC(EventNewStatus)) && (!DEM_TEST_UDS_STATUS_CDTC(EventOldStatus)))
            {
                /*The OBD freeze frame buffer needs update.*/
                UpdateFlag = TRUE;
            }
        }
        else
        {
            /*The OBD freeze frame buffer is full.*/
            StoredEventPriority = DEM_CFG_DTC_PRIORITY(DEM_CFG_EVENT_DTCREF(DEM_OBD_FF_EVENT));
            StoringEventPriority = DEM_CFG_DTC_PRIORITY(DEM_CFG_EVENT_DTCREF(EventId));

            if(StoringEventPriority < StoredEventPriority)
            {
                /*The priority of new event is higher than stored event.*/
                UpdateFlag = TRUE;
            }
        }
    }

    if(UpdateFlag == TRUE)
    {
        /*Update the OBD freeze frame buffer.*/
        DEM_OBD_FF_EVENT = EventId;
        DataPtr = DEM_OBD_FF_DATA_BUF;
#if(DEM_CFG_OBD_MAXNUM_OF_PID > 0)
        for(PidIndex = (uint8)0; PidIndex < DEM_CFG_OBD_NUM_OF_PID; PidIndex++)
        {
            *DataPtr = DEM_CFG_PID_ID(PidIndex);
            DataPtr++;

            for(DataIndex = (uint8)0; DataIndex < DEM_CFG_PID_NUM_OF_DATA(PidIndex); DataIndex++)
            {
                DataEleIndex = DEM_CFG_PID_DATA_CLASS(PidIndex)[DataIndex];
                if(DEM_CFG_DATA_IN_DATA(DataEleIndex) != NULL_PTR)
                {
                    /*SWS_Dem_00817*/
                    DemInternal_GetEventInternalData(EventId, DEM_CFG_DATA_IN_DATA_TYPE(DataEleIndex), DataPtr);
                    DataPtr += DEM_CFG_DATA_IN_DATA_SIZE(DataEleIndex);
                }

                if(DEM_CFG_DATA_CS_DATA(DataEleIndex) != NULL_PTR)
                {
                    Result = DEM_CFG_DATA_CS_DATA_READ_FNC(DataEleIndex)(DataPtr);

                    if(Result != E_OK)
                    {
                        for(i = (uint8)0; i < DEM_CFG_DATA_CS_DATA_SIZE(DataEleIndex); i++)
                        {
                            DataPtr[i] = DEM_DATA_INVALID_U8;
                        }
                    }

                    DataPtr += DEM_CFG_DATA_CS_DATA_SIZE(DataEleIndex);
                }


            }/*for(DataIndex = 0; DataIndex < DEM_CFG_PID_NUM_OF_DATA(PidIndex); DataIndex++)*/
        }/*for(PidIndex = 0; PidIndex < DEM_CFG_OBD_NUM_OF_PID; PidIndex++)*/
#endif
    }/*if(UpdateFlag == TRUE)*/
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_ClearOBDFreezeFrame
*
* Description: Clear the OBD Freeze Frame 0x00 when Event aged.
*
* Inputs: EventId
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_ClearOBDFreezeFrame
(
    Dem_EventIdType EventId
)
{
    uint16 i;
    if(DEM_OBD_FF_EVENT == EventId)
    {
        DEM_OBD_FF_EVENT = DEM_EVENT_ID_INVALID;

        for(i = (uint16)0; i < DEM_CFG_OBD_FF_LENGTH; i++)
        {
            DEM_OBD_FF_DATA_BUF[i] = DEM_DATA_INVALID_U8;
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_MainFnc_OBD
*
* Description: Main function to process task relevant OBD.
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_OBD
(
    void
)
{
    /*SWS_Dem_00703*/
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
    Dem_ObdTimesOneSecond++;
    /*1 second = 1000 millisecond*/
    if(Dem_ObdTimesOneSecond >= (uint16)(1000/DEM_TASK_TIME))
    {
        Dem_ObdTimesOneSecond = DEM_DATA_CLEAR;
        DemInternal_CalPID21_31_4D_4E_Data();
    }
#endif
}

#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_CalPID21_31_4D_4E_Data
*
* Description: Calculate data value of PID31.
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_CalPID21_31_4D_4E_Data
(
    void
)
{
    uint8 TimeBuf[2];
    uint16 TimeSinceEngineStart;/*Unit:s*/
    uint8 VehicleSpeed;/*Unit: km/h*/
    uint16 TimeDelta = (uint16)0;/*Unit:s*/
    Dem_DataElementReadFncType GetTimeFnc = NULL_PTR;
    Dem_DataElementReadFncType GetSpeedFnc = NULL_PTR;
    Dem_IndicatorStatusType IndicatorStatus;
    if(DEM_CFG_OBD_EVENT_MEMORY_REF != DEM_DATA_INVALID_U8)
    {
        DemInternal_GetIndicatorStatus(DEM_CFG_MILINDICATORREF(DEM_CFG_OBD_EVENT_MEMORY_REF), &IndicatorStatus);
    }
    if((DEM_CFG_OBD_TIME_SINCE_ENGINE_START != DEM_DATA_INVALID_U8) \
        && (DEM_CFG_OBD_IN_VEHICLE_SPEED != DEM_DATA_INVALID_U8)\
        && (DEM_CFG_OBD_TIME_SINCE_ENGINE_START != DEM_DATA_INVALID_U8)\
        && (DEM_CFG_OBD_IN_VEHICLE_SPEED != DEM_DATA_INVALID_U8)\
        && (DEM_CFG_DATA_CS_DATA(DEM_CFG_OBD_TIME_SINCE_ENGINE_START) != NULL_PTR) \
        && (DEM_CFG_DATA_CS_DATA(DEM_CFG_OBD_IN_VEHICLE_SPEED) != NULL_PTR))
    {
        GetTimeFnc = (*DEM_CFG_DATA_CS_DATA_READ_FNC(DEM_CFG_OBD_TIME_SINCE_ENGINE_START));
        GetSpeedFnc = (*DEM_CFG_DATA_CS_DATA_READ_FNC(DEM_CFG_OBD_IN_VEHICLE_SPEED));
        if((E_OK == GetTimeFnc(TimeBuf)) && (E_OK == GetSpeedFnc(&VehicleSpeed)))
        {
            TimeSinceEngineStart = (((uint16)TimeBuf[0]<<8) | ((uint16)TimeBuf[1]));

            if(TimeSinceEngineStart < Dem_ObdTimeSinceEngineStartLast)
            {
                Dem_ObdTimeSinceEngineStartLast = TimeSinceEngineStart;
                TimeDelta = TimeSinceEngineStart;
            }
            else
            {
                TimeDelta = TimeSinceEngineStart - Dem_ObdTimeSinceEngineStartLast;
                Dem_ObdTimeSinceEngineStartLast = TimeSinceEngineStart;
            }
            /*y km/h = y*1000/3600 m/s*/
            DEM_OBD_DISTANCE_SINCEDTCCLEARED += ((((uint32)VehicleSpeed)*1000/3600)*(uint32)TimeDelta);
            DEM_OBD_ENGINERUN_SINCEDTCCLEARED += TimeDelta;

            if(IndicatorStatus != DEM_INDICATOR_OFF)
            {
                DEM_OBD_DISTANCE_MILACTIVATED += ((((uint32)VehicleSpeed)*1000/3600)*(uint32)TimeDelta);
                DEM_OBD_ENGINERUN_MILACTIVATED += TimeDelta;
            }
            else
            {
                DEM_OBD_DISTANCE_MILACTIVATED = DEM_DATA_CLEAR;
                DEM_OBD_ENGINERUN_MILACTIVATED = DEM_DATA_CLEAR;
            }
            if(DEM_OBD_DISTANCE_SINCEDTCCLEARED > (uint32)65535000)
            {
                DEM_OBD_DISTANCE_SINCEDTCCLEARED = (uint32)65535000;
            }
            if(DEM_OBD_DISTANCE_MILACTIVATED > (uint32)65535000)
            {
                DEM_OBD_DISTANCE_MILACTIVATED = (uint32)65535000;
            }
            if(DEM_OBD_ENGINERUN_SINCEDTCCLEARED > (65535*60))
            {
                DEM_OBD_ENGINERUN_SINCEDTCCLEARED = (65535*60);
            }
            if(DEM_OBD_ENGINERUN_MILACTIVATED > (uint32)(65535*60))
            {
                DEM_OBD_ENGINERUN_MILACTIVATED = (uint32)(65535*60);
            }
        }
    }
}

#endif/*#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)*/
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/


#if(DEM_NUM_OF_RATIO > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_UpdateRatioNumerator
*
* Description: Only for monitors being configured with the option "observer",the
*              Dem module shall increment the numerator of the corresponding
*              monitor, if the assigned event gets tested/qualified (as passed
*              or failed).
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_UpdateRatioNumerator
(
    Dem_EventIdType EventId
)
{
    Dem_RatioIdType RatioID;
    Dem_UdsStatusByteType DtcStatus;

    for(RatioID = (Dem_RatioIdType)0; RatioID < DEM_NUM_OF_RATIO; RatioID++)
    {
        if(DEM_CFG_RATIO_EVENTREF(RatioID) == EventId)
        {
            DtcStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
            /*SWS_Dem_00359*//*SWS_Dem_00299*/
            if((DEM_CFG_RATIO_KIND(RatioID) == DEM_RATIO_OBSERVER) \
                && (!DEM_TEST_UDS_STATUS_TNCTOC(DtcStatus)) \
                && (!DEM_TEST_UDS_STATUS_PDTC(DtcStatus)))
            {
                /*SWS_Dem_01188*/
                if((DEM_OBD_RATIO_STATE(RatioID) & DEM_OBD_NUM_INCREASED_MASK) == (uint8)0)
                {
                    /*increase 1 to the numerator*/
                    DEM_OBD_RATIO_NUMERATOR(RatioID)++;
                    DEM_OBD_RATIO_STATE(RatioID) |= DEM_OBD_NUM_INCREASED_MASK;
                }

                if(DEM_OBD_RATIO_NUMERATOR(RatioID) >= DEM_OBD_NUMDEN_MAX_VALUE)
                {
                    DEM_OBD_RATIO_NUMERATOR(RatioID) = (DEM_OBD_RATIO_NUMERATOR(RatioID) >> (uint16)1);
                    DEM_OBD_RATIO_DENOMINATOR(RatioID) = (DEM_OBD_RATIO_DENOMINATOR(RatioID) >> (uint16)1);
                }
            }
            break;/*for(RatioID = 0; RatioID < DEM_NUM_OF_RATIO; RatioID++)*/
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_UpdateRatioDenominator
*
* Description: Update the denominator of all ratio.
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_UpdateRatioDenominator
(
    void
)
{
    Dem_RatioIdType RatioID;
    Dem_EventIdType EventId;
    Dem_UdsStatusByteType DtcStatus;
    Dem_IUMPRDenGroupType DenGroup = DEM_IUMPR_DEN_NONE;

    /*SWS_Dem_00712*/
    if(DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_GENERAL) == DEM_IUMPR_DEN_STATUS_REACHED)
    {
        for(RatioID = (Dem_RatioIdType)0; RatioID < DEM_NUM_OF_RATIO; RatioID++)
        {
            DenGroup = DEM_CFG_RATIO_IUMPR_DEN(RatioID);

            if(((DEM_OBD_RATIO_STATE(RatioID) & DEM_OBD_DEN_INCREASED_MASK) == (uint8)0) \
                && (((DenGroup != DEM_IUMPR_DEN_PHYS_API) \
                && (DEM_OBD_RATIO_DENOMCOND_STATUS(DenGroup) == DEM_IUMPR_DEN_STATUS_REACHED)) \
                || ((DenGroup == DEM_IUMPR_DEN_PHYS_API) \
                && ((DEM_OBD_RATIO_STATE(RatioID) & DEM_OBD_DEN_LOCK_MASK) == (uint8)0))))
            {
                EventId = DEM_CFG_RATIO_EVENTREF(RatioID);
                DtcStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
                /*SWS_Dem_00299*//*SWS_Dem_00709*/
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
                if((Dem_EventAvailable[EventId] == TRUE) && (!DEM_TEST_UDS_STATUS_PDTC(DtcStatus)))
#else
                if(!DEM_TEST_UDS_STATUS_PDTC(DtcStatus))
#endif
                {
                    DEM_OBD_RATIO_DENOMINATOR(RatioID)++;
                    DEM_OBD_RATIO_STATE(RatioID) |= DEM_OBD_DEN_INCREASED_MASK;
                }

                if(DEM_OBD_RATIO_DENOMINATOR(RatioID) >= DEM_OBD_NUMDEN_MAX_VALUE)
                {
                    DEM_OBD_RATIO_NUMERATOR(RatioID) = (DEM_OBD_RATIO_NUMERATOR(RatioID) >> (uint16)1);
                    DEM_OBD_RATIO_DENOMINATOR(RatioID) = (DEM_OBD_RATIO_DENOMINATOR(RatioID) >> (uint16)1);
                }
            }
        }/* for(RatioID = 0; RatioID < DEM_NUM_OF_RATIO; RatioID++)*/
    }/*if(DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_GENERAL) == DEM_IUMPR_DEN_STATUS_REACHED)*/
}
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/

#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_AddEventPermanentEntry
*
* Description: Add one event to the permanent memory entry.
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_AddEventPermanentEntry
(
    Dem_EventIdType EventId
)
{
    uint8 Index;
    uint8 IndicatorId;
    uint16 StatusPos;
    boolean MilOn = FALSE;
    boolean IgnOn = FALSE;
    uint16 DTCMemId;
    uint8 ParentMemId;
    uint8 FreeEntry;
    uint16 DtcId = DEM_CFG_EVENT_DTCREF(EventId);

    if(DtcId != DEM_DATA_INVALID_U16)
    {
        DTCMemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId);
        ParentMemId = DEM_GET_EVENTMEMORY_ID(DTCMemId);
        FreeEntry = DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT(ParentMemId);
        /*Check if drive operation cycle is start.*/
        if(DEM_CFG_OBD_DRIVING_CYCLE_REF != DEM_DATA_INVALID_U8)
        {
            if(DEM_CURRENT_OP_STATE(DEM_CFG_OBD_DRIVING_CYCLE_REF) == DEM_CYCLE_STATE_START)
            {
                IgnOn = TRUE;
            }
        }

        if((DEM_CFG_EVENT_INDICATOR_NUM(EventId) > (uint8)0) \
            && (DEM_CFG_EVENT_INDICATOR(EventId) != NULL_PTR) \
            && (IgnOn == TRUE))
        {
            for(Index = (uint8)0; Index < DEM_CFG_EVENT_INDICATOR_NUM(EventId); Index++)
            {
                IndicatorId = DEM_CFG_EVENT_INDICATOR_ID(EventId,Index);
                StatusPos = DEM_CFG_EVENT_INDICATOR_OFFSET(EventId,Index) \
                                + DEM_CFG_INDICATOR_STATUS_START(IndicatorId);

                if((DEM_INDICATOR_STATUS(StatusPos) != DEM_INDICATOR_OFF) \
                    && (IndicatorId == DEM_CFG_MILINDICATORREF(ParentMemId)))
                {
                    MilOn = TRUE;
                    break;
                }
            }
        }

        if(MilOn == TRUE)
        {
            for(Index = (uint8)0; Index < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT(ParentMemId); Index++)
            {
                if(DEM_PERMANENT_DATAENTRY_EVENTID(ParentMemId, Index) == EventId)
                {
                    break;
                }
                else if((DEM_PERMANENT_DATAENTRY_EVENTID(ParentMemId, Index) == DEM_EVENT_ID_INVALID) \
                    && (FreeEntry == DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT(ParentMemId)))
                {
                    FreeEntry = Index;
                }
                else
                {
                    /*do nothing*/
                }
            }

            if((Index == DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT(ParentMemId)) \
                && (FreeEntry < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT(ParentMemId)))
            {
                DEM_PERMANENT_DATAENTRY_EVENTID(ParentMemId,FreeEntry) = EventId;
                DEM_PERMANENT_DATAENTRY_USEDNUM(ParentMemId)++;
            }
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_RemoveEventPermanentEntry
*
* Description: Remove one event from the permanent memory entry.
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_RemoveEventPermanentEntry
(
    Dem_EventIdType EventId
)
{
    uint8 Index;
    uint8 IndicatorId;
    uint16 StatusPos;
    Dem_EventIdType EventIdx;
    boolean MilOff = FALSE;
    boolean ClearConditionSatisfied = FALSE;
    uint16 DTCMemId;
    uint8 ParentMemId;
    uint16 DtcId = DEM_CFG_EVENT_DTCREF(EventId);
    DTCMemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId);
    ParentMemId = DEM_GET_EVENTMEMORY_ID(DTCMemId);
    uint8 MemIdx = DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT(ParentMemId);
    if(DEM_EVENT_OBD_CLEAR_FLAG(EventId) == FALSE)
    {
        ClearConditionSatisfied = TRUE;
    }
    else
    {
        /*Check if WarmUp operation cycle is start.*/
        if(DEM_CFG_OBD_WARMUP_CYCLE_REF != DEM_DATA_INVALID_U8 )
        {
            if(DEM_CURRENT_OP_STATE(DEM_CFG_OBD_WARMUP_CYCLE_REF) == DEM_CYCLE_STATE_START)
            {
                ClearConditionSatisfied = TRUE;
            }
        }
    }

    if(ClearConditionSatisfied == TRUE)
    {
        for(Index = (uint8)0; Index < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT(ParentMemId); Index++)
        {
            if(DEM_PERMANENT_DATAENTRY_EVENTID(ParentMemId, Index) == EventId)
            {
                MemIdx = Index;
                break;
            }
        }

        if(MemIdx < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT(ParentMemId))
        {
            for(Index = (uint8)0; Index < DEM_CFG_EVENT_INDICATOR_NUM(EventId); Index++)
            {
                IndicatorId = DEM_CFG_EVENT_INDICATOR_ID(EventId,Index);
                StatusPos = DEM_CFG_EVENT_INDICATOR_OFFSET(EventId,Index) \
                                + DEM_CFG_INDICATOR_STATUS_START(IndicatorId);

                if((DEM_INDICATOR_STATUS(StatusPos) == DEM_INDICATOR_OFF) \
                    && (IndicatorId == DEM_CFG_MILINDICATORREF(ParentMemId)))
                {
                    MilOff = TRUE;
                    break;
                }
            }
        }

        if(MilOff == TRUE)
        {
            DEM_PERMANENT_DATAENTRY_EVENTID(ParentMemId,MemIdx) = DEM_EVENT_ID_INVALID;
            DEM_PERMANENT_DATAENTRY_USEDNUM(ParentMemId)--;

            /*If one event with MIL ON is not stored in permanent entry, now it can be stored.*/
            for(EventIdx = (Dem_EventIdType)0; EventIdx < DEM_NUM_OF_EVENT; EventIdx++)
            {
                DemInternal_AddEventPermanentEntry(EventIdx);
            }
        }
    }
}
#endif/*#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)*/

/*******************************************************************************
*   AUTOSAR Stabdard Api
*******************************************************************************/
#if(STD_ON == DEM_VERSION_INFO_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetVersionInfo
*
* Description: Returns the version information of this module.
*
* Inputs: None
*
* Outputs: versioninfo:Pointer to where to store the version information of
*                      this module.
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DEM_CODE) Dem_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DEM_APPL_DATA) versionInfo
)
{
    if(NULL_PTR == versionInfo)
    {
        DEM_DET_REPORT_ERROR(DEM_GETVERSIONINFO_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        versionInfo->vendorID = DEM_VENDOR_ID;
        versionInfo->moduleID = DEM_MODULE_ID;

        versionInfo->sw_major_version = (uint8)DEM_SW_MAJOR_VERSION;
        versionInfo->sw_minor_version = (uint8)DEM_SW_MINOR_VERSION;
        versionInfo->sw_patch_version = (uint8)DEM_SW_PATCH_VERSION;
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_PreInit
*
* Description: Initializes the internal states necessary to process events
*              reported by BSW-modules.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DEM_CODE) Dem_PreInit
(
    void
)
{

    uint16 i;
#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
    uint16 j;
#endif
#endif
#endif
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
    for(i = (uint16)0; i < DEM_MAXNUM_OF_DTC; i++)
    {
        Dem_DTCSuppressionState[i] = FALSE;
    }
#endif

#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
    for(i = (uint16)0; i < DEM_MAXNUM_OF_EVENT; i++)
    {
        if(DEM_CFG_EVENT_AVAILABLE(i) == TRUE)
        {
            Dem_EventAvailable[i] = TRUE;
        }
        else
        {
            Dem_EventAvailable[i] = FALSE;
            /*SWS_Dem_00915*/
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
            if(DEM_CFG_EVENT_DTCREF(i) != DEM_DTC_ID_INVALID)
            {
#if(DEM_EVENT_COMBINATION_SUPPORT  != DEM_EVCOMB_DISABLED)
                if(DEM_IS_COMBINEDDTC(DEM_CFG_EVENT_DTCREF(i)))
                {
                    Dem_DTCSuppressionState[DEM_CFG_EVENT_DTCREF(i)] = TRUE;
                    for(j = (uint16)0 ; j < DEM_MAXNUM_OF_EVENT; j++)
                    {
                        if((DEM_CFG_EVENT_DTCREF(i) == DEM_CFG_EVENT_DTCREF(j)) && (DEM_CFG_EVENT_AVAILABLE(j) == TRUE))
                        {
                            Dem_DTCSuppressionState[DEM_CFG_EVENT_DTCREF(i)] = FALSE;
                            break;
                        }
                    }
                }
                else
#endif
                {

                    Dem_DTCSuppressionState[DEM_CFG_EVENT_DTCREF(i)] = TRUE;
                }
            }
#endif
        }
    }

#endif

    for(i = (uint16)0; i < (uint16)DEM_MAXNUM_OF_EVENT; i++)
    {

#if(DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
        /*SWS_Dem_01242*/
        Dem_EventConfirmationCounter[i] = DEM_CFG_EVENT_CONFIRMATIONTHRESHOLD(i);
#endif
        /*reset the Dem-internal debounce algorithm*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
        DEM_EVENT_DBC(i) = 0;
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
        DEM_EVENT_DBT(i) = (uint32)0;
        DEM_EVENT_TIMERDIRECTION(i) = DEM_DATA_INVALID_U8;
        Dem_EventDBTFreezeFlag[i] = FALSE;
#endif
        Dem_EventStatusBuff[i] = DEM_DATA_CLEAR;
#if(DEM_CORE_NUMBER > 1)
        Dem_DebounceStatusBuff[i] = DEM_DATA_INVALID_U8;
        Dem_ResetEventStatusBuff[i] = FALSE;
#endif
    }
    /*init operation cycle state*//*SWS_Dem_00853*/
    for(i = (uint16)0; i < (uint16)DEM_NUM_OF_OPCYCLE; i++)
    {
        Dem_OpCycQualified[i] = DEM_OP_NOT_QUALIFIED;
        Dem_OpCycReq[i] = DEM_DATA_CLEAR;
    }
    /*init the status of enable conditions*/
#if(DEM_NUM_OF_EN_CONDITION > 0)
    for(i = (uint16)0; i < (uint16)DEM_NUM_OF_EN_CONDITION; i++)
    {
        if(DEM_CFG_EN_CONDITION_STATUS(i) == TRUE)
        {
            Dem_EventEnCondition[i] = TRUE;
        }
        else
        {
            Dem_EventEnCondition[i] = FALSE;
        }
#if(DEM_CORE_NUMBER > 1)
        Dem_EnConditionBuff[i] = DEM_DATA_INVALID_U8;
#endif
    }
#endif
    /*init the status of storage conditions*/
#if(DEM_NUM_OF_STOR_CONDITION > 0)
    for(i = (uint16)0; i < (uint16)DEM_NUM_OF_STOR_CONDITION; i++)
    {
        if(DEM_CFG_STOR_CONDITION_STATUS(i) == TRUE)
        {
            Dem_EventStorCondition[i] = TRUE;
        }
        else
        {
            Dem_EventStorCondition[i] = FALSE;
        }
#if(DEM_CORE_NUMBER > 1)
        Dem_StorConditionBuff[i] = DEM_DATA_INVALID_U8;
#endif
    }
#endif

#if(DEM_CFG_BSWERRORBUFFERSIZE > 0)
    for(i = (uint16)0; i < (uint16)DEM_CFG_BSWERRORBUFFERSIZE; i++)
    {
        DEM_REPORT_BSW_EVENT_ID(i) = DEM_DATA_INVALID_U16;
        DEM_REPORT_BSW_EVENT_STATU(i) = DEM_DATA_INVALID_U8;
    }
#endif
    /*SWS_Dem_00169*/
    DEM_SET_STATE(DEM_PREINIT);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_Init
*
* Description: Initializes or reinitializes this module.
*
* Inputs: ConfigPtr:Pointer to the configuration set in VARIANT-POSTBUILD.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DEM_CODE) Dem_Init
(
    P2CONST(Dem_ConfigType, AUTOMATIC, DEM_APPL_DATA) ConfigPtr
)
{
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    uint16 i;
    /*PRQA S 3205++*/
#if((DEM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
    uint16 j;
#endif
#endif
#endif
    /*PRQA S 3205--*/
#if(DEM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    if(NULL_PTR == ConfigPtr)
    {
        DEM_DET_REPORT_ERROR(DEM_INIT_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
#if(DEM_CORE_NUMBER > 1)
        if(CoreId == DEM_MASTER_COREID)
#endif
        {

            Dem_ConfigPtr = ConfigPtr;

        }


#else
    (void)ConfigPtr;
#endif
#if(DEM_CORE_NUMBER > 1)
        if(CoreId == DEM_MASTER_COREID)
#endif
        {

            /*Check if the value in Dem_StorageMem is valid*/
            DemInternal_CheckStorageMem();

            for(i = (uint16)0; i < (uint16)DEM_NUM_OF_DTC; i++)
            {
                /*Enable DTC setting*/
                Dem_EnableDtcSetting[i] = TRUE;
                /*Enable DTC Update*/
                Dem_DtcUpDateState[i] = TRUE;
                Dem_ClearDTCInfo.ClearDTCTable[i] = FALSE;
            }
            for(i = (uint16)0; i < (uint16)DEM_NUM_OF_EVENT; i++)
            {
#if((DEM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
                if(DEM_CFG_EVENT_AVAILABLE(i) == TRUE)
                {
                    Dem_EventAvailable[i] = TRUE;
                }
                else
                {
                    Dem_EventAvailable[i] = FALSE;
                    /*SWS_Dem_00915*/
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
                    if(DEM_CFG_EVENT_DTCREF(i) != DEM_DTC_ID_INVALID)
                    {
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
                        if(DEM_IS_COMBINEDDTC(DEM_CFG_EVENT_DTCREF(i)))
                        {
                            Dem_DTCSuppressionState[DEM_CFG_EVENT_DTCREF(i)] = TRUE;
                            for(j = (uint16)0 ; j < (uint16)DEM_NUM_OF_EVENT; j++)
                            {
                                if((DEM_CFG_EVENT_DTCREF(i) == DEM_CFG_EVENT_DTCREF(j)) && (DEM_CFG_EVENT_AVAILABLE(j) == TRUE))
                                {
                                    Dem_DTCSuppressionState[DEM_CFG_EVENT_DTCREF(i)] = FALSE;
                                    break;
                                }
                            }
                        }
                        else
#endif
                        {

                            Dem_DTCSuppressionState[DEM_CFG_EVENT_DTCREF(i)] = TRUE;
                        }
                    }
#endif
                }
#endif
#if(DEM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
                /*SWS_Dem_01242*/
                Dem_EventConfirmationCounter[i] = DEM_CFG_EVENT_CONFIRMATIONTHRESHOLD(i);
#endif
                /*Clear EventCaptureFlag*/
                DemInternal_ClrCaptureQueue(i);

            }

#if(DEM_CORE_NUMBER > 1)
            for(i = (uint8)0; i < (uint8)DEM_CORE_NUMBER; i++)
            {
                Dem_SelectDTC_State[i] = DEM_IN_SELECT_DTC_IDLE;
            }
#endif

            Dem_CapturePosition = (uint16)0;
            Dem_ClearDTCInfo.ClearDTCNum = (uint16)0;
            Dem_ClearDTCInfo.ClearDTCFailedNum = (uint16)0;
            Dem_ClearDTCInfo.ClearBlockNum = (uint16)0;
            for(i = (uint8)0; i < DEM_NUM_OF_CLIENT; i++)
            {
                Dem_DcmFilterInfo[i].FilteredValidFlag = FALSE;
                Dem_DcmFilterInfo[i].FilterProcess = DEM_NO_CLIENT_REQUEST;
                Dem_DTCIsSelected[i] = FALSE;
                Dem_SelectDTCState[i] = DEM_IN_SELECT_DTC_IDLE;
                Dem_SelectDTCRecordUpdate[i] = FALSE;
#if(STD_ON == DEM_CFG_J1939READING_DTC_SUPPORT)
                Dem_J1939DcmFilterInfo[i].FilteredValidFlag = FALSE;
#endif
#if((STD_ON == DEM_CFG_J1939EX_FF_SUPPORT)||(STD_ON == DEM_CFG_J1939_FF_SUPPORT))
                Dem_J1939DcmFilterFF[i].FilteredValidFlag = FALSE;
#endif
#if(STD_ON == DEM_CFG_J1939DM31_SUPPORT)
                Dem_J1939DcmFilterDM31[i].FilteredValidFlag = FALSE;
#endif
            }


#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
            Dem_ObdTimeSinceEngineStartLast = DEM_DATA_CLEAR;
            Dem_ObdTimesOneSecond = DEM_DATA_CLEAR;
#endif
#if(DEM_MAX_NUM_OF_DTR > 0)
            DemInternal_DtrInfoInit();
#endif
        }
        /*SWS_Dem_00340*/
        DEM_SET_STATE(DEM_NORMAL);
        /*SWS_Dem_01189*/
#if(DEM_FIM_SUPPORT == STD_ON)
        FiM_DemInit();
#endif
#if(DEM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    }
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_Shutdown
*
* Description: Shuts down this module.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DEM_CODE) Dem_Shutdown
(
    void
)
{
    uint8 i;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_0();

    if(DEM_GET_STATE != DEM_UNINIT)
    {
#if(DEM_CORE_NUMBER > 1)
        if(DEM_MASTER_COREID == CoreId)
        {
#endif
            for(i = (uint8)0; i < (uint8)DEM_NUM_OF_OPCYCLE; i++)
            {
                /*SWS_Dem_01078*/
                Dem_OpCycReq[i] = DEM_DATA_CLEAR;
                if(DEM_CURRENT_OP_STATE(i) == DEM_CYCLE_STATE_START)
                {
                    DEM_CURRENT_OP_STATE(i) = DEM_CYCLE_STATE_END;
                    DemInternal_CycleEndProcess(i);
                }
            }
#if(DEM_CORE_NUMBER > 1)
        }
#endif
        /*SWS_Dem_00368*/
        DEM_SET_STATE(DEM_PREINIT);
    }
    SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_0();
}


#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetEventAvailable
*
* Description: Set the available status of a specific Event.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         AvailableStatus: This parameter specifies whether the respective
*                          Event shall be available (TRUE) or not (FALSE).
*
* Outputs: None
*
* Return: E_OK: Operation was successful.
*         E_NOT_OK: change of available status not accepted
*
* Limitations: Non Reentrant
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00177*//*SWS_Dem_00687*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventAvailable
(
    Dem_EventIdType EventId,
    boolean AvailableStatus
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
    uint16 j;
#endif
#endif
    Dem_UdsStatusByteType EventOldStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE == DEM_UNINIT)
    {
        DEM_DET_REPORT_ERROR(DEM_SETEVENTAVAILABLE_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
    else if((DEM_TEST_UDS_STATUS_TF(EventOldStatus))\
        || (DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) != DEM_DATA_INVALID_U8)\
        || (DEM_EVENT_DATAENTRYREF(EventId) != DEM_DATA_INVALID_U8))
#else
    else if((DEM_TEST_UDS_STATUS_TF(EventOldStatus))\
        || (DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) != DEM_DATA_INVALID_U8))
#endif
    {
        /*SWS_Dem_01109*/
        Result = E_NOT_OK;
    }
    else
    {
        if(Dem_EventAvailable[EventId] == AvailableStatus)
        {
            /*state not changed*/
            Result = E_NOT_OK;
        }
        else if(AvailableStatus == TRUE)
        {
            Dem_EventAvailable[EventId] = TRUE;
#if(DEM_INITMFORE_CALLBACK_SUPPORT == STD_ON)
            if(DEM_CFG_EVENT_INITM_CALLFNC(EventId) != NULL_PTR)
            {
#if(DEM_CORE_NUMBER > 1)
                if(CoreId != DEM_CFG_EVENT_COREREF(EventId))
                {
                    DEM_CFG_EVENT_INITM_FLAG(EventId) = TRUE;
                    DEM_CFG_EVENT_INITM_REASON(EventId) = DEM_INIT_MONITOR_REENABLED;
                }
                else
#endif
                {
                    DEM_CFG_EVENT_INITM_CALLFNC(EventId)(DEM_INIT_MONITOR_REENABLED);
                }
            }
#endif
            if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
            {
                /*SWS_Dem_01111*/
                DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId)) = DEM_STATUS_RESET;
                DemInternal_DTCStatusChangedNotification(DEM_CFG_DTC_VALUE(DEM_CFG_EVENT_DTCREF(EventId)), DEM_DATA_CLEAR, DEM_STATUS_RESET);
            }
            DemInternal_EventStatusChangedNotification(EventId,DEM_DATA_CLEAR, DEM_STATUS_RESET);
        }
        else
        {
            /*SWS_Dem_01108*/
            Dem_EventAvailable[EventId] = FALSE;
            if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
            {
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)

                if(DEM_IS_COMBINEDDTC(DEM_CFG_EVENT_DTCREF(EventId)))
                {
                    Dem_DTCSuppressionState[DEM_CFG_EVENT_DTCREF(EventId)] = TRUE;
                    for(j = (uint16)0 ; j < DEM_NUM_OF_EVENT; j++)
                    {
                        if((DEM_CFG_EVENT_DTCREF(EventId) == DEM_CFG_EVENT_DTCREF(j)) && (Dem_EventAvailable[j] == TRUE))
                        {
                            Dem_DTCSuppressionState[DEM_CFG_EVENT_DTCREF(EventId)] = FALSE;
                            break;
                        }
                    }
                }
                else
#endif
                {

                    Dem_DTCSuppressionState[DEM_CFG_EVENT_DTCREF(EventId)] = TRUE;
                }
#endif
                /*SWS_Dem_01110*/
                DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId)) = DEM_DATA_CLEAR;
                DemInternal_DTCStatusChangedNotification(DEM_CFG_DTC_VALUE(DEM_CFG_EVENT_DTCREF(EventId)), EventOldStatus, DEM_DATA_CLEAR);
            }
            DemInternal_EventStatusChangedNotification(EventId,EventOldStatus, DEM_DATA_CLEAR);
        }
    }
    return Result;
}
#endif/*#if((DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD) \
    && (DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY))*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetEventStatus
*
* Description: Processes the events reported by SW-Cs via RTE. This API can only
*              be used through the RTE, and therefore no declaration is exported
*              via Dem.h. Some bits of the UDS DTC status byte changes
*              synchronously or asynchronously (refer to SWS_Dem_00036 and
*              SWS_Dem_00379).OBD Events Suppression shall be ignored for this
*              computation.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         EventStatus: Monitor test result
*
* Outputs: None
*
* Return: E_OK: set of event status was successful.
*         E_NOT_OK: set of event status failed or could not be accepted.
*                   (e.g.: the operation cycle configured for this event has not
*                   been started,an according enable condition has been disabled)
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus
)
{
    Std_ReturnType Result = E_NOT_OK;
    Dem_EventStatusType DemEventSta;
    if(DEM_GET_STATE == DEM_UNINIT)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETEVENTSTATUS_APIID, DEM_E_UNINIT);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_SETEVENTSTATUS_APIID, DEM_E_PARAM_DATA);
    }
    else if(DEM_CFG_EVENT_REPORTING_TYPE(EventId) != STANDARD_REPORTING)
    {
        DEM_DET_REPORT_ERROR(DEM_SETEVENTSTATUS_APIID, DEM_E_WRONG_CONFIGURATION);
    }
#if(DEM_CORE_NUMBER == 1)
    else if(E_NOT_OK == DemInternal_EventCheck(EventId))
    {

    }
#endif
    else if(((EventStatus == DEM_EVENT_STATUS_PREPASSED) \
        || (EventStatus == DEM_EVENT_STATUS_PREFAILED)) \
        && (DEM_CFG_EVENT_GET_FDC_FNC(EventId) != NULL_PTR))
    {
        /*SWS_Dem_00437*/
    }
    else if((DEM_GET_STATE == DEM_PREINIT) && ((DEM_CFG_EVENT_KIND(EventId) == DEM_EVENT_KIND_SWC)
        || (DEM_CFG_EVENT_REPBEHAVIOR(EventId) != DEM_REPORT_BEFORE_INIT)))
    {
        DEM_DET_REPORT_ERROR(DEM_SETEVENTSTATUS_APIID, DEM_E_WRONG_CONFIGURATION);
    }
    else if(DEM_GET_STATE == DEM_PREINIT)
    {
#if(DEM_CFG_BSWERRORBUFFERSIZE > 0)
        DemInternal_EventQueuing(EventId, EventStatus);
        Result = E_OK;
#endif
    }
    else
    {
        DemEventSta = (EventStatus | DEM_EVENT_STATUS_UPDATE_MASK);
        Dem_EventStatusBuff[EventId] = DemEventSta;
        Result = E_OK;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetEventStatusWithMonitorData
*
* Description: Processes the events reported by SW-Cs via RTE. This API can only
*              be used through the RTE, and therefore no declaration is exported
*              via Dem.h. Some bits of the UDS DTC status byte changes
*              synchronously or asynchronously (refer to SWS_Dem_00036 and
*              SWS_Dem_00379).OBD Events Suppression shall be ignored for this
*              computation.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         EventStatus: Monitor test result
*
* Outputs: None
*
* Return: E_OK: set of event status was successful.
*         E_NOT_OK: set of event status failed or could not be accepted.
*                   (e.g.: the operation cycle configured for this event has not
*                   been started,an according enable condition has been disabled)
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatusWithMonitorData
(
    Dem_EventIdType EventId,
    Dem_EventStatusType EventStatus,
    /*PRQA S 3206 ++*/
    /*
    This parameter is used when the specific condition is met.
    */
    Dem_MonitorDataType monitorData0,
    Dem_MonitorDataType monitorData1
    /*PRQA S 3206 --*/
)
{
    Std_ReturnType Result = E_NOT_OK;
    Dem_EventStatusType DemEventSta;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETEVENTSTATUSWITHMONITORDATA_APIID, DEM_E_UNINIT);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_SETEVENTSTATUSWITHMONITORDATA_APIID, DEM_E_PARAM_DATA);
    }
    else if(DEM_CFG_EVENT_REPORTING_TYPE(EventId) != STANDARD_REPORTING_WITH_MONITOR_DATA)
    {
        DEM_DET_REPORT_ERROR(DEM_SETEVENTSTATUSWITHMONITORDATA_APIID, DEM_E_WRONG_CONFIGURATION);
    }
    else if(((EventStatus == DEM_EVENT_STATUS_PREPASSED) \
        || (EventStatus == DEM_EVENT_STATUS_PREFAILED)) \
        && (DEM_CFG_EVENT_GET_FDC_FNC(EventId) != NULL_PTR))
    {
        /*SWS_Dem_00437*/
    }
    else
    {

        DemEventSta = (EventStatus | DEM_EVENT_STATUS_UPDATE_MASK);
        Dem_EventStatusBuff[EventId] = DemEventSta;
#if(DEM_MONITORDATA_SUPPORT == STD_ON)
        DEM_EVENT_MONITOR_DATA_0(EventId) = monitorData0;
        DEM_EVENT_MONITOR_DATA_1(EventId) = monitorData1;
#endif
        Result = E_OK;

    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_ResetEventDebounceStatus
*
* Description: Control the internal debounce counter/timer by BSW modules and SWCs.
*              The event qualification will not be affected by these debounce state
*              changes. This API is available for BSW modules as soon as Dem_PreInit
*              has been completed
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         DebounceResetStatus: Freeze or reset the internal debounce counter/timer
*                              of the specified event.
*
* Outputs: None
*
* Return: E_OK: Operation was successful
*         E_NOT_OK: Only on development error
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventDebounceStatus
(
    Dem_EventIdType EventId,
    Dem_DebounceResetStatusType DebounceResetStatus
)
{
    Std_ReturnType Result = E_OK;

#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(DEM_GET_STATE == DEM_UNINIT)
    {
        /*SWS_Dem_00364*/
        DEM_DET_REPORT_ERROR(DEM_RESETEVENTDEBOUNCESTATUS_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
    else if((DEM_GET_STATE != DEM_NORMAL) && (DEM_CFG_EVENT_DBC_STORAGE(EventId) == TRUE))
    {
        /*SWS_Dem_00676*//*SWS_Dem_00518*/
        DEM_DET_REPORT_ERROR(DEM_RESETEVENTDEBOUNCESTATUS_APIID, DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
#endif
    else
    {
#if(DEM_CORE_NUMBER > 1)

        Dem_DebounceStatusBuff[EventId] = DebounceResetStatus;
#else
        Result = DemInternal_ResetEventDebounceStatus(EventId, DebounceResetStatus);
#endif
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_ResetEventDebounceStatus
*
* Description:
*
*
* Inputs:
*
* Outputs: None
*
* Return:
*
*
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_ResetEventDebounceStatus
(
    Dem_EventIdType EventId,
    Dem_DebounceResetStatusType DebounceResetStatus
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    if(Dem_EventAvailable[EventId] != FALSE)
#endif
    {
        if(DebounceResetStatus == DEM_DEBOUNCE_STATUS_FREEZE)
        {
            /*SWS_Dem_00685*/
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
            Dem_EventDBTFreezeFlag[EventId] = TRUE;
#endif
        }
        else if(DebounceResetStatus == DEM_DEBOUNCE_STATUS_RESET)
        {
            /*SWS_Dem_00684*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
            DEM_EVENT_DBC(EventId) = (sint16)0;
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
            DEM_EVENT_DBT(EventId) = (uint32)0;
            DEM_EVENT_TIMERDIRECTION(EventId) = DEM_DATA_INVALID_U8;
            Dem_EventDBTFreezeFlag[EventId] = FALSE;
#endif
        }
        else
        {
            Result = E_NOT_OK;
        }
    }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    else
    {
        Result = E_NOT_OK;
    }
#endif
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_ResetEventStatus
*
* Description: Resets the event failed status. This API can only be used through
*              the RTE and therefore no declaration is exported via Dem.h.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: None
*
* Return: E_OK: reset of event status was successful
*         E_NOT_OK: reset of event status failed or is not allowed,because the
*                   event is already tested in this operation cycle
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventStatus
(
    Dem_EventIdType EventId
)
{

    Std_ReturnType Result = E_OK;
    if(DEM_GET_STATE == DEM_UNINIT)
    {
        /*SWS_Dem_01112*/
        DEM_DET_REPORT_ERROR(DEM_RESETEVENTSTATUS_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_RESETEVENTSTATUS_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
    else
    {
#if(DEM_CORE_NUMBER > 1)
        Dem_ResetEventStatusBuff[EventId] = TRUE;
#else
        Result = DemInternal_ResetEventStatus(EventId);
#endif

    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_ResetEventStatus
*
* Description: Resets the event failed status. This API can only be used through
*              the RTE and therefore no declaration is exported via Dem.h.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: None
*
* Return: E_OK: reset of event status was successful
*         E_NOT_OK: reset of event status failed or is not allowed,because the
*                   event is already tested in this operation cycle
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_ResetEventStatus
(
    Dem_EventIdType EventId
)
{
    Std_ReturnType Result = E_OK;
    Dem_UdsStatusByteType EventOldStatus;
    Dem_UdsStatusByteType EventNewStatus;
    Dem_UdsStatusByteType DTCOldStatus;
    Dem_UdsStatusByteType DTCNewStatus;
    if(E_OK == DemInternal_EventCheck(EventId))
    {
        EventOldStatus = DEM_EVENT_STATUS(EventId);
        if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
        {
            DTCOldStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
        }
        /*SWS_Dem_00638*//*SWS_Dem_00187*/
        if(DEM_TEST_UDS_STATUS_TNCTOC(EventOldStatus))
        {
            /*SWS_Dem_00386*/
            EventNewStatus = DEM_CLEAR_UDS_STATUS_TF(EventOldStatus);
            DEM_EVENT_STATUS(EventId) = EventNewStatus;
            if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
            {
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
                if(DEM_IS_COMBINEDDTC(DEM_CFG_EVENT_DTCREF(EventId)))
                {
                    DTCNewStatus = DemInternal_UpdateCombinedDTC(EventId);
                }
                else
#endif
                {
                    DTCNewStatus = EventNewStatus;
                    DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId)) = EventNewStatus;
                }
                if(DTCOldStatus != DTCNewStatus)
                {
                    DemInternal_DTCStatusChangedNotification(DEM_CFG_DTC_VALUE(DEM_CFG_EVENT_DTCREF(EventId)), DTCOldStatus, DTCNewStatus);
                }

            }

            if(EventNewStatus != EventOldStatus)
            {
                DemInternal_EventStatusChangedNotification(EventId,EventOldStatus, EventNewStatus);
            }
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
            /* Reset debounce counter. */
            DEM_EVENT_DBC(EventId) = (sint16)0;
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
            DEM_EVENT_DBT(EventId) = (uint32)0;
            DEM_EVENT_TIMERDIRECTION(EventId) = DEM_DATA_INVALID_U8;
            Dem_EventDBTFreezeFlag[EventId] = FALSE;
#endif
        }
        else
        {
            Result = E_NOT_OK;
        }
    }
    else
    {
        Result = E_NOT_OK;
    }
    return Result;
}

#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_PrestoreFreezeFrame
*
* Description: Captures the freeze frame data for a specific event. This API can
*              only be used through the RTE and therefore no declaration is
*              exported via Dem.h.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: None
*
* Return: E_OK: Freeze frame prestorage was successful
*         E_NOT_OK: Freeze frame prestorage failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_PrestoreFreezeFrame
(
    Dem_EventIdType EventId
)
{
    /*SWS_Dem_00334*//*SWS_Dem_00189*/
    Std_ReturnType Result = E_NOT_OK;
    uint8 EntryId;
    if(DEM_GET_STATE == DEM_UNINIT)
    {
        /*SWS_Dem_01112*/
        DEM_DET_REPORT_ERROR(DEM_PRESTOREFREEZEFRAME_APIID, DEM_E_UNINIT);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_PRESTOREFREEZEFRAME_APIID, DEM_E_PARAM_DATA);
    }
    else if(DEM_CFG_EVENT_PRESTORAGE(EventId) == FALSE)
    {
        DEM_DET_REPORT_ERROR(DEM_PRESTOREFREEZEFRAME_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
        if(Dem_UsedNumOfPreStorageFF < (uint8)DEM_CFG_MAXNUMBER_PRESTOREDFF)
        {
            if(DEM_EVEVT_PRESTO_FF_ENTRY(EventId) == DEM_ENTRY_ID_INVALID)
            {
                EntryId = DemInternal_GetFreePreStorageEntry(EventId);
                if(EntryId != DEM_ENTRY_ID_INVALID)
                {
                    DemInternal_PreStorageFFData(EventId,EntryId);
                    Dem_UsedNumOfPreStorageFF++;
                    Dem_PreStorageFFFlag[EventId] = TRUE;
                    Result = E_OK;
                }
            }
            else
            {
                DemInternal_PreStorageFFData(EventId,DEM_EVEVT_PRESTO_FF_ENTRY(EventId));
                Dem_PreStorageFFFlag[EventId] = TRUE;
                Result = E_OK;
            }
        }
        else
        {
            /*SWS_Dem_00808*/
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetFreePreStorageEntry
*
* Description: Captures the freeze frame data for a specific event. This API can
*              only be used through the RTE and therefore no declaration is
*              exported via Dem.h.DEM_RESETEVENTDEBOUNCESTATU
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: None
*
* Return: E_OK: Freeze frame prestorage was successful
*         E_NOT_OK: Freeze frame prestorage failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8 ,DEM_CODE)DemInternal_GetFreePreStorageEntry
(
    uint16 EventId
)
{
    uint8 i = DEM_ENTRY_ID_INVALID;
    for(i = (uint8)0; i < (uint8)DEM_CFG_MAXNUMBER_PRESTOREDFF; i++ )
    {
        if(DEM_PRESTORE_FFENTRY_USED(i) == FALSE)
        {
            DEM_PRESTORE_FFENTRY_EVENTID(i) = EventId;
            DEM_PRESTORE_FFENTRY_USED(i) = TRUE;
            break;
        }
    }
    return i ;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_ClearPrestoredFreezeFrame
*
* Description: Clears a prestored freeze frame of a specific event. This API can
*              only be used through the RTE and therefore no declaration is
*              exported via Dem.h.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: None
*
* Return: E_OK: Clear prestored freeze frame was successful
*         E_NOT_OK: Clear prestored freeze frame failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ClearPrestoredFreezeFrame
(
    Dem_EventIdType EventId
)
{
    /*SWS_Dem_00334*//*SWS_Dem_00050*/
    Std_ReturnType Result = E_NOT_OK;
    uint8 PreStoEntryId;
    uint16 i;

    if(DEM_GET_STATE == DEM_UNINIT)
    {
        /*SWS_Dem_01112*/
        DEM_DET_REPORT_ERROR(DEM_CLEARPRESTOREDFREEZEFRAME_APIID, DEM_E_UNINIT);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_CLEARPRESTOREDFREEZEFRAME_APIID, DEM_E_PARAM_DATA);
    }
    else if(DEM_CFG_EVENT_PRESTORAGE(EventId) == FALSE)
    {
        DEM_DET_REPORT_ERROR(DEM_CLEARPRESTOREDFREEZEFRAME_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
        PreStoEntryId = DEM_EVEVT_PRESTO_FF_ENTRY(EventId);
        if(PreStoEntryId != DEM_DATA_INVALID_U8)
        {
            DEM_PRESTORE_FFENTRY_EVENTID(PreStoEntryId) = (uint16)DEM_DATA_CLEAR;
            DEM_PRESTORE_FFENTRY_USED(PreStoEntryId) = FALSE;
            for(i = (uint16)0; i < (uint16)DEM_MAX_FFSIZE_OF_DTC; i++)
            {
                DEM_PRESTORE_FFENTRY(PreStoEntryId).PreStorageFFData[i] = (uint8)DEM_DATA_CLEAR;
            }
            DEM_EVEVT_PRESTO_FF_ENTRY(EventId) = DEM_DATA_INVALID_U8;
            Dem_PreStorageFFFlag[EventId] = FALSE;
            Dem_UsedNumOfPreStorageFF--;
        }
        Result = E_OK;

    }

    return Result;
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_RestartOperationCycle
*
* Description: Sets an operation cycle state. This API can only be used through
*              the RTE and therefore no declaration is exported via Dem.h. The
*              interface has an asynchronous behavior to avoid exceeding of typical
*              timing requirements on APIs if a large number of events has to be
*              processed and during the re-initializations of the related monitors.
*              The asynchronous acknowledgements are the related InitMonitorForEvent
*              callbacks.
*
* Inputs: OperationCycleId: Identification of operation cycle, like power cycle,
*                           driving cycle.
*         CycleState: New operation cycle state: (re-)start or end
*
* Outputs: None
*
* Return: E_OK: set of operation cycle was accepted and will be handled
*               asynchronously
*         E_NOT_OK: set of operation cycle was rejected
*
* Limitations: Asynchronous,Reentrant
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_RestartOperationCycle
(
    uint8 OperationCycleId
)
{
    /*SWS_Dem_00338*/
    Std_ReturnType Result = E_NOT_OK;
    /*SWS_Dem_01318*/
    if(DEM_GET_STATE == DEM_UNINIT)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_RESTARTOPERATIONCYCLE_APIID, DEM_E_UNINIT);
    }
    else if(OperationCycleId >= (uint8)DEM_NUM_OF_OPCYCLE)
    {
        DEM_DET_REPORT_ERROR(DEM_RESTARTOPERATIONCYCLE_APIID, DEM_E_PARAM_DATA);
    }
    else if(Dem_OpCycReq[OperationCycleId] != (Dem_OperationCycleStateType)DEM_DATA_CLEAR)
    {
        /*do nothing*/
    }
    else
    {

        DemInternal_OperationCycleHandle(OperationCycleId);
        Result = E_OK;

    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_RestartOperationCycle
*
* Description: Sets an operation cycle state. This API can only be used through
*              the RTE and therefore no declaration is exported via Dem.h. The
*              interface has an asynchronous behavior to avoid exceeding of typical
*              timing requirements on APIs if a large number of events has to be
*              processed and during the re-initializations of the related monitors.
*              The asynchronous acknowledgements are the related InitMonitorForEvent
*              callbacks.
*
* Inputs: OperationCycleId: Identification of operation cycle, like power cycle,
*                           driving cycle.
*         CycleState: New operation cycle state: (re-)start or end
*
* Outputs: None
*
* Return: E_OK: set of operation cycle was accepted and will be handled
*               asynchronously
*         E_NOT_OK: set of operation cycle was rejected
*
* Limitations: Asynchronous,Reentrant
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_RestartOperationCycle
(
    uint8 OperationCycleId,
    Dem_OperationCycleStateType OperationCycleState
)
{
    uint8 OpId;
    if(DEM_CFG_OPCYC_LEADING_REF(OperationCycleId) == DEM_DATA_INVALID_U8)/*normal operation cycle*/
    {
        for(OpId = (uint8)0; OpId < (uint8)DEM_NUM_OF_OPCYCLE; OpId++)
        {
            if((DEM_CFG_OPCYC_LEADING_REF(OpId) == OperationCycleId) \
                && (Dem_OpCycQualified[OpId] == DEM_OP_QUALIFIED) \
                && (Dem_OpCycReq[OpId] == (Dem_OperationCycleStateType)DEM_DATA_CLEAR))
            {
                /*SWS_Dem_01225*/
                if(DEM_CURRENT_OP_STATE(OpId) == DEM_CYCLE_STATE_END)
                {
                    Dem_OpCycReq[OpId] = DEM_CYCLE_STATE_START;
                    /*SWS_Dem_01225*/
                    Dem_OpCycQualified[OpId] = DEM_OP_NOT_QUALIFIED;
                }
                else
                {
                    Dem_OpCycReq[OpId] = DEM_CYCLE_STATE_RESTART;
                    /*SWS_Dem_01225*/
                    Dem_OpCycQualified[OpId] = DEM_OP_NOT_QUALIFIED;
                }
                Dem_OpCycQualified[OpId] = DEM_OP_NOT_QUALIFIED;
            }
        }
        Dem_OpCycReq[OperationCycleId] = OperationCycleState;
    }
    else  /*dependent operation cycle*/
    {
        if(Dem_OpCycQualified[OperationCycleId] == DEM_OP_QUALIFIED)
        {
            /*SWS_Dem_01225*/
            Dem_OpCycReq[OperationCycleId] = OperationCycleState;
            Dem_OpCycQualified[OperationCycleId] = DEM_OP_NOT_QUALIFIED;
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetCycleQualified                   SWS_Dem_91001
*
* Description: Sets a dependent operation cycle as qualified, so it may be
*              processed along with its leading cycle.
*
* Inputs: OperationCycleId: Identification of operation cycle, like power cycle,
*                           driving cycle.
*
* Outputs: None
*
* Return: E_OK: set of operation cycle was accepted and will be handled
*               asynchronously
*         E_NOT_OK: set of operation cycle was rejected
*
* Limitations: Asynchronous,Reentrant
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetCycleQualified
(
    uint8 OperationCycleId
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETCYCLEQUALIFIED_APIID, DEM_E_UNINIT);
    }
    else if(OperationCycleId >= (uint8)DEM_NUM_OF_OPCYCLE)
    {
        /*SWS_Dem_01222*/
        DEM_DET_REPORT_ERROR(DEM_SETCYCLEQUALIFIED_APIID, DEM_E_WRONG_CONFIGURATION);
    }
    else if((DEM_CFG_OPCYC_LEADING_REF(OperationCycleId) == DEM_DATA_INVALID_U8) \
        ||(Dem_OpCycQualified[OperationCycleId] == DEM_OP_QUALIFIED))
    {
        DEM_DET_REPORT_ERROR(DEM_SETCYCLEQUALIFIED_APIID, DEM_E_WRONG_CONFIGURATION);
    }
    else
    {
        Dem_OpCycQualified[OperationCycleId] = DEM_OP_QUALIFIED;
        ret = E_OK;
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetCycleQualified                   SWS_Dem_00740
*
* Description: Returns the qualification state of the dependent operation cycle
*
*
* Inputs: OperationCycleId: Identification of operation cycle, like power cycle,
*                           driving cycle.
*         isQualified     : TRUE: The dependent operation cylcle is qualified. FALSE: The
*                           qualification conditions of the dependent operation cylcle have
*                           not been met.
*
* Outputs: None
*
* Return: E_OK: Always E_OK is returned, as E_NOT_OK will never appear
*
*         E_NOT_OK:
*
* Limitations: Asynchronous,Reentrant
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetCycleQualified
(
    uint8 OperationCycleId,
    boolean* isQualified
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETCYCLEQUALIFIED_APIID, DEM_E_UNINIT);
    }
    else if(OperationCycleId >= (uint8)DEM_NUM_OF_OPCYCLE)
    {
        /*SWS_Dem_01235*/
        DEM_DET_REPORT_ERROR(DEM_GETCYCLEQUALIFIED_APIID, DEM_E_WRONG_CONFIGURATION);
    }
    else if(DEM_CFG_OPCYC_LEADING_REF(OperationCycleId) == DEM_DATA_INVALID_U8)
    {
        DEM_DET_REPORT_ERROR(DEM_GETCYCLEQUALIFIED_APIID, DEM_E_WRONG_CONFIGURATION);
    }
    else
    {
        if(Dem_OpCycQualified[OperationCycleId] != DEM_OP_NOT_QUALIFIED)
        {
            *isQualified = TRUE;
        }
        else
        {
            *isQualified = FALSE;
        }
        ret = E_OK;
    }
    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetWIRStatus
*
* Description: Sets the WIR status bit via failsafe SW-Cs.This API can only be
*              used through the RTE and therefore no declaration is exported via
*              Dem.h.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         WIRStatus: Requested status of event related WIR-bit (regarding to the
*                    current status of function inhibition)
*                    WIRStatus = TRUE -> WIR-bit shall be set to "1"
*                    WIRStatus = FALSE -> WIR-bit shall be set to "0"
*
* Outputs: None
*
* Return: E_OK: The request is accepted
*         E_NOT_OK: not be accepted (e.g. disabled controlDTCSetting) and should
*                   be repeated.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00831*//*SWS_Dem_00832*//*SWS_Dem_00839*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetWIRStatus
(
    Dem_EventIdType EventId,
    /*PRQA S 3206++*/
    boolean WIRStatus
    /*PRQA S 3206--*/
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_NUM_OF_INDICATOR > 0)
    Dem_UdsStatusByteType EventStatus;
    uint8 Index;
    uint8 IndicatorId;
    uint16 StatusPos;
    boolean ClearWIRBit = TRUE;
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETWIRSTATUS_APIID, DEM_E_UNINIT);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_SETWIRSTATUS_APIID, DEM_E_PARAM_DATA);
    }
    else if((DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)\
        && (Dem_EnableDtcSetting[DEM_CFG_EVENT_DTCREF(EventId)] == FALSE))
    {
        /*SWS_Dem_00836*/
    }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
#if(DEM_NUM_OF_INDICATOR > 0)
    else if((DEM_CFG_EVENT_INDICATOR_NUM(EventId) == 0) \
            || (DEM_CFG_EVENT_INDICATOR(EventId) == NULL_PTR))
    {
        /*Result = E_NOT_OK;*/
    }
    else
    {
        EventStatus = DEM_EVENT_STATUS(EventId);
        if(WIRStatus == TRUE)
        {
            /*SWS_Dem_00833*/
            EventStatus = DEM_SET_UDS_STATUS_WIR(EventStatus);
            DEM_EVENT_STATUS(EventId) = EventStatus;
            if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
            {
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
                if(DEM_IS_COMBINEDDTC(DEM_CFG_EVENT_DTCREF(EventId)))
                {
                    (void)DemInternal_UpdateCombinedDTC(EventId);
                }
                else
#endif
                {
                    DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId)) = EventStatus;
                }
            }
            for(Index = (uint8)0; Index < DEM_CFG_EVENT_INDICATOR_NUM(EventId); Index++)
            {
                IndicatorId = DEM_CFG_EVENT_INDICATOR_ID(EventId,Index);
                StatusPos = DEM_CFG_EVENT_INDICATOR_OFFSET(EventId,Index) \
                                + DEM_CFG_INDICATOR_STATUS_START(IndicatorId);
                DEM_INDICATOR_STATUS(StatusPos) = DEM_CFG_EVENT_INDICATOR_BEHAVIOUR(EventId,Index);
            }
            Result = E_OK;
        }
        else if(DEM_TEST_UDS_STATUS_WIR(EventStatus))
        {
            for(Index = (uint8)0; Index < DEM_CFG_EVENT_INDICATOR_NUM(EventId); Index++)
            {
                IndicatorId = DEM_CFG_EVENT_INDICATOR_ID(EventId,Index);
                StatusPos = DEM_CFG_EVENT_INDICATOR_OFFSET(EventId,Index) \
                                + DEM_CFG_INDICATOR_STATUS_START(IndicatorId);
                if(DEM_INDICATOR_STATUS(StatusPos) != DEM_INDICATOR_OFF)
                {
                    ClearWIRBit = FALSE;
                    break;
                }
            }

            if(ClearWIRBit == TRUE)
            {
                /*SWS_Dem_00834*/
                EventStatus = DEM_CLEAR_UDS_STATUS_WIR(EventStatus);
                DEM_EVENT_STATUS(EventId) = EventStatus;
                if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
                {
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
                    if(DEM_IS_COMBINEDDTC(DEM_CFG_EVENT_DTCREF(EventId)))
                    {
                        (void)DemInternal_UpdateCombinedDTC(EventId);
                    }
                    else
#endif
                    {
                        DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId)) = EventStatus;
                    }

                }
                Result = E_OK;
            }
        }
        else
        {
            /*WIR bit value is 0 now in EventStatus.*/
        }


    }
#else
    else
    {
        /*Result = E_NOT_OK;*/
    }
#endif/*#if(DEM_NUM_OF_INDICATOR > 0)*/

    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetEventUdsStatus                     SWS_Dem_91008
*
* Description: Gets the current extended event status of an event.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: EventStatusByte: UDS DTC status byte of the requested event (refer to
*                           chapter "Status bit support").If the return value of
*                           the function call is E_NOT_OK,this parameter does not
*                           contain valid data.
*
* Return: E_OK: get of event status was successful
*         E_NOT_OK: get of event status failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventUdsStatus
(
    Dem_EventIdType EventId,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) UDSStatusByte
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETEVENTUDSSTATUS_APIID, DEM_E_UNINIT);
    }
    else if(UDSStatusByte == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTUDSSTATUS_APIID, DEM_E_PARAM_POINTER);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTUDSSTATUS_APIID, DEM_E_PARAM_DATA);
    }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
    else
    {
        /*SWS_Dem_00051*/
        *UDSStatusByte = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
        Result = E_OK;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetMonitorStatus                     SWS_Dem_91008
*
* Description: Gets the current extended event status of an event.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: EventStatusByte: UDS DTC status byte of the requested event (refer to
*                           chapter "Status bit support").If the return value of
*                           the function call is E_NOT_OK,this parameter does not
*                           contain valid data.
*
* Return: E_OK: get of event status was successful
*         E_NOT_OK: get of event status failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetMonitorStatus
(
    Dem_EventIdType EventId,
    P2VAR(Dem_MonitorStatusType, AUTOMATIC, DEM_APPL_DATA) MonitorStatus
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETMONITORSTATUS_APIID, DEM_E_UNINIT);
    }
    else if(MonitorStatus == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETMONITORSTATUS_APIID, DEM_E_PARAM_POINTER);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETMONITORSTATUS_APIID, DEM_E_PARAM_DATA);
    }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
    else
    {
        /*SWS_Dem_00051*/
        *MonitorStatus = ((DEM_EVENT_STATUS(EventId) & DEM_UDS_STATUS_TNCTOC) >> DEM_UINT8_5);
        *MonitorStatus |= (DEM_EVENT_STATUS(EventId) & DEM_UDS_STATUS_TF);
        Result = E_OK;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetEventAvailable                  SWS_Dem_91040
*
* Description: Gets the event failed status of an event.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         AvailableStatus: TRUE if the event is available. FALSE if the event is not available
* Outputs: AvailableStatus: TRUE - event is available
*                       FALSE - event is not available
*
* Return: E_OK: Event availability has been obtained
*         E_NOT_OK: Event availability cannot be obtained
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventAvailable
(
    Dem_EventIdType EventId,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) AvailableStatus
)
{
    /*SWS_Dem_00333*/
    Std_ReturnType Result = E_NOT_OK;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETEVENTAVAILABLE_APIID, DEM_E_UNINIT);
    }
    else if(AvailableStatus == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTAVAILABLE_APIID, DEM_E_PARAM_POINTER);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTAVAILABLE_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
        *AvailableStatus = Dem_EventAvailable[EventId];
#endif
        Result = E_OK;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetEventConfirmationThresholdCounter  SWS_Dem_91004
*
* Description:Set the failure confirmation threshold of an event.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         FailureCycleCounterThreshold : Failure cycle counter threshold of event to be set
* Outputs:
*
*
* Return: E_OK: Change of threshold was successful
*         E_NOT_OK: Threshold cannot be changed as DemEvent
*                   ConfirmationThresholdCounterAdaptable is set to FALSE for this
*                   event.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventConfirmationThresholdCounter
(
    Dem_EventIdType EventId,
    uint8 FailureCycleCounterThreshold
)
{
    /*SWS_Dem_00333*/ /*SWS_Dem_01242*/
    Std_ReturnType Result = E_NOT_OK;
    Dem_UdsStatusByteType EventOldStatus;
    Dem_UdsStatusByteType EventNewStatus;
    Dem_UdsStatusByteType DTCOldStatus;
    Dem_UdsStatusByteType DTCNewStatus;

#if(DEM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
    if(DEM_GET_STATE == DEM_UNINIT)
#else
    if(DEM_GET_STATE != DEM_NORMAL)
#endif
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETEVENTCONFIRMATIONTHRESHOLDCOUNTER_APIID, DEM_E_UNINIT);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_SETEVENTCONFIRMATIONTHRESHOLDCOUNTER_APIID, DEM_E_PARAM_DATA);
    }
    else if(FailureCycleCounterThreshold == 0)
    {
        DEM_DET_REPORT_ERROR(DEM_SETEVENTCONFIRMATIONTHRESHOLDCOUNTER_APIID, DEM_E_PARAM_DATA);
    }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
    else
    {
        /*SWS_Dem_01243*/ /*SWS_Dem_01244*/ /*SWS_Dem_01245*/
        Dem_EventConfirmationCounter[EventId] = FailureCycleCounterThreshold;
        EventOldStatus = DEM_EVENT_STATUS(EventId);
        EventNewStatus = DEM_EVENT_STATUS(EventId);
        if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DATA_INVALID_U16)
        {
            DTCOldStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
            DTCNewStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
            if(DEM_EVENT_FCC(EventId) >= Dem_EventConfirmationCounter[EventId])
            {
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
                DEM_EVENT_FCC(EventId) = DEM_DATA_CLEAR;
#endif
                /*SWS_Dem_00391*/
                EventNewStatus = DEM_SET_UDS_STATUS_CDTC(EventNewStatus);
                DEM_EVENT_STATUS(EventId) = EventNewStatus;
                if(DEM_EVENT_FIRST_CONFIRMED == DEM_DATA_INVALID_U16)
                {
                    DEM_EVENT_FIRST_CONFIRMED = EventId;
                }

                if(!DEM_TEST_UDS_STATUS_CDTC(EventOldStatus))
                {
                    DEM_EVENT_RECENT_CONFIRMED = EventId;
                }
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
                if(DEM_IS_COMBINEDDTC(DEM_CFG_EVENT_DTCREF(EventId)))
                {
                    DTCNewStatus = DemInternal_UpdateCombinedDTC(EventId);
                }
                else
#endif
                {
                    DemInternal_SetCaptureQueue(EventId, DEM_TRIGGER_ON_CONFIRMED);
                    DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId)) = EventNewStatus;
                    DTCNewStatus = EventNewStatus;
                }

            }
            if(DTCOldStatus != DTCNewStatus)
            {
                DemInternal_DTCStatusChangedNotification(DEM_CFG_DTC_VALUE(DEM_CFG_EVENT_DTCREF(EventId)), DTCOldStatus, DTCNewStatus);
            }
        }
        if(EventNewStatus != EventOldStatus)
        {
            DemInternal_EventStatusChangedNotification(EventId,EventOldStatus, EventNewStatus);
        }
        Result = E_OK;

    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetDebouncingOfEvent
*
* Description: Gets the debouncing status of an event. This function shall not
*              be used for EventId with native debouncing within their functions.
*              It is rather for EventIds using debouncing within the Dem.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: DebouncingState
*
* Return: E_OK: get of debouncing status per event state successful
*         E_NOT_OK: get of debouncing per event state failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetDebouncingOfEvent
(
    Dem_EventIdType EventId,
    P2VAR(Dem_DebouncingStateType, AUTOMATIC, DEM_APPL_DATA) DebouncingState
)
{
    Std_ReturnType Result = E_OK;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETDEBOUNCINGOFEVENT_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if (DebouncingState == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDEBOUNCINGOFEVENT_APIID, DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDEBOUNCINGOFEVENT_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
        Result = E_NOT_OK;
    }
#endif
    else
    {
        /*SWS_Dem_00844*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
        if(DEM_CFG_EVENT_DBC(EventId) != NULL_PTR)
        {
            if((DEM_EVENT_DBC(EventId) > (sint16)0) \
                    && (DEM_EVENT_DBC(EventId) < DEM_CFG_EVENT_DBC_FAILTHRESHOLD(EventId)))
            {
                *DebouncingState = DEM_TEMPORARILY_DEFECTIVE;
            }
            else if((DEM_EVENT_DBC(EventId) < (sint16)0) \
                    && (DEM_EVENT_DBC(EventId) > DEM_CFG_EVENT_DBC_PASSTHRESHOLD(EventId)))
            {
                *DebouncingState = DEM_TEMPORARILY_HEALED;
            }
            else if(DEM_EVENT_DBC(EventId) <= DEM_CFG_EVENT_DBC_PASSTHRESHOLD(EventId))
            {
                *DebouncingState = DEM_TEST_COMPLETE;
            }
            else if(DEM_EVENT_DBC(EventId) >= DEM_CFG_EVENT_DBC_FAILTHRESHOLD(EventId))
            {
                if(DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) == DEM_DATA_INVALID_U8)
                {
                    *DebouncingState = DEM_FINALLY_DEFECTIVE;
                }
                else
                {
                    *DebouncingState = DEM_DTR_UPDATE;
                }
            }
            else
            {
                Result = E_NOT_OK;
            }
        }
#endif

#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
        if(DEM_CFG_EVENT_DBT(EventId) != NULL_PTR)
        {
            if(DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREFAILED)
            {
                *DebouncingState = DEM_TEMPORARILY_DEFECTIVE;
            }
            else if(DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREPASSED)
            {
                *DebouncingState = DEM_TEMPORARILY_HEALED;
            }
            else if(DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PASSED)
            {
                *DebouncingState = DEM_TEST_COMPLETE;
            }
            else if(DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_FAILED)
            {
                if(DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) == DEM_DATA_INVALID_U8)
                {
                    *DebouncingState = DEM_FINALLY_DEFECTIVE;
                }
                else
                {
                    *DebouncingState = DEM_DTR_UPDATE;
                }
            }
            else
            {
                Result = E_NOT_OK;
            }
        }
#endif
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetDTCOfEvent
*
* Description: Gets the DTC of an event.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         DTCFormat: Defines the output-format of the requested DTC value.
*
* Outputs: DTCOfEvent: Receives the DTC value in respective format returned by
*                      this function. If the return value of the function is
*                      other than E_OK this parameter does not contain valid data.
*
* Return: E_OK: get of DTC was successful
*         E_NOT_OK: the call was not successful
*
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCOfEvent
(
    Dem_EventIdType EventId,
    Dem_DTCFormatType DTCFormat,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTCOfEvent
)
{
    Std_ReturnType Result = E_OK;

    if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDTCOFEVENT_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
        Result = E_NOT_OK;
    }
#endif
    else
    {
        if(DTCFormat == DEM_DTC_FORMAT_UDS)
        {
            if(DEM_CFG_DTC_VALUE(DEM_CFG_EVENT_DTCREF(EventId)) != (uint32)0)
            {
                *DTCOfEvent = (uint32)DEM_CFG_DTC_VALUE(DEM_CFG_EVENT_DTCREF(EventId));
            }
        }
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
        else if(DTCFormat == DEM_DTC_FORMAT_OBD)
        {
            if((DEM_CFG_DTC_OBDDTCREF(DEM_CFG_EVENT_DTCREF(EventId)) != NULL_PTR) \
                && (DEM_CFG_DTC_OBD_VALUE(DEM_CFG_EVENT_DTCREF(EventId)) != (uint16)0))
            {
                *DTCOfEvent = (uint32)DEM_CFG_DTC_OBD_VALUE(DEM_CFG_EVENT_DTCREF(EventId));
            }
        }
#endif
#if(DEM_J1939_SUPPORT == STD_ON)
        else if(DTCFormat == DEM_DTC_FORMAT_J1939)
        {
            if((DEM_CFG_DTC_OBDDTCREF(DEM_CFG_EVENT_DTCREF(EventId)) != NULL_PTR) \
                && (DEM_CFG_DTC_J1939_VALUE(DEM_CFG_EVENT_DTCREF(EventId)) != (uint32)0))
            {
                *DTCOfEvent = DEM_CFG_DTC_J1939_VALUE(DEM_CFG_EVENT_DTCREF(EventId));
            }
        }
#endif
        else
        {
            Result = E_NOT_OK;
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SelectDTC
*
* Description: Selects a DTC or DTC group as target for further operations.
*
* Inputs: ClientId:  Unique client id, assigned to the instance of the calling module
*         DTC:       Defines the DTC in respective format that is selected
*         DTCFormat: Defines the output-format of the requested DTC value.
*         DTCOrigin: The event memory of the requested DTC or group of DTC
*
* Outputs:
*
*
*
* Return: E_OK: DTC successfully selected.
*         DEM_BUSY: Another Dem_SelectDTC or Dem_SelectDTC
*         dependent operation of this client is currently in progress.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (Std_ReturnType, DEM_CODE) Dem_SelectDTC
(
    uint8 ClientId,
    uint32 DTC,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        DEM_DET_REPORT_ERROR(DEM_SELECTDTC_APIID, DEM_E_UNINIT);
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    /*SWS_Dem_01306*//*SWS_Dem_01305*/
    else if((Dem_SelectDTCState[ClientId] != DEM_IN_SELECT_DTC_PROCESSING)\
        && (DEM_SELECT_DTC_STATE == DEM_IN_SELECT_DTC_IDLE))
    {
        DEM_SELECT_DTC_STATE = DEM_IN_SELECT_DTC_CHECKING;
        Dem_DTCIsSelected[ClientId] = TRUE;
        if((DTC == (uint32)0) || (DTC > DEM_DTC_GROUP_ALL))
        {
            DEM_DET_REPORT_ERROR(DEM_SELECTDTC_APIID, DEM_E_PARAM_DATA);
            Dem_SelectDTCState[ClientId] = DEM_WRONG_DTC;
        }
        else if((DTCFormat != DEM_DTC_FORMAT_OBD) \
            && (DTCFormat != DEM_DTC_FORMAT_UDS) \
            && (DTCFormat != DEM_DTC_FORMAT_J1939))
        {
            DEM_DET_REPORT_ERROR(DEM_SELECTDTC_APIID, DEM_E_PARAM_DATA);
            Dem_SelectDTCState[ClientId] = DEM_WRONG_DTC;
        }
        else if((DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY)\
            &&(DTCOrigin != DEM_DTC_ORIGIN_PERMANENT_MEMORY)\
            &&(DTCOrigin != DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY)\
            &&(((DTCOrigin & DEM_DTC_ORIGIN_USERDEFINED_MEMORY_XX) == (Dem_DTCOriginType)0)\
            || ((DTCOrigin & DEM_DTC_REQURE_USERDEFINED_MEMORY_ID) > (uint16)DEM_NUM_OF_USERDEF)))
        {
            DEM_DET_REPORT_ERROR(DEM_SELECTDTC_APIID, DEM_E_PARAM_DATA);
            Dem_SelectDTCState[ClientId] = DEM_WRONG_DTCORIGIN;
        }
        else
        {
            Dem_SelectDTC_DTC[ClientId] = (Dem_UdsDTCType)DTC;
            Dem_SelectDTC_DTCFormat[ClientId] = DTCFormat;
            Dem_SelectDTC_DTCOrigin[ClientId] = DTCOrigin;
            (void)DemInternal_CheckSelectDTC(ClientId);
        }
        DEM_SELECT_DTC_STATE = DEM_IN_SELECT_DTC_IDLE;
    }
    else
    {
        Result = DEM_BUSY;
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetDTCSelectionResult          SWS_Dem_91023
*
* Description: Provides information if the last call to Dem_SelectDTC has
*              selected a valid DTC or group of DTCs
*
* Inputs: ClientId:  Unique client id, assigned to the instance of the calling module
*
* Outputs:
*
* Return: E_OK: The DTC select parameter check is successful and the requested DTC
*               or group of DTC in the selected origin is selected for further operations.
*         E_NOT_OK: No DTC selected
*         DEM_WRONG_DTC: Selected DTC value in selected format does not exist.
*         DEM_WRONG_DTCORIGIN: Selected DTCOrigin does not exist.
*         DEM_PENDING: Checking the SelectDTC parameters is currently in progress.
*         DEM_BUSY: Another Dem_SelectDTC or Dem_SelectDTC dependent operation
*                    of this client is currently in progress.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (Std_ReturnType, DEM_CODE) Dem_GetDTCSelectionResult
(
    uint8 ClientId
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDTCSELECTIONRESUIT_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    /*SWS_Dem_01299*/
    else if(Dem_DTCIsSelected[ClientId] == FALSE)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDTCSELECTIONRESUIT_APIID, DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
    /*SWS_Dem_01256*/
    else if((Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_GROUP)\
        ||(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_SINGLE))
    {
        Result = E_OK;
    }
    else if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_CHECKING)
    {
        /*Checking the SelectDTC parameters is finished in Dem_SelectDTC,so do not retern DEM_PENDING*/
        Result = DEM_PENDING;
    }
    else if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PROCESSING)
    {
        Result = DEM_BUSY;
    }
    else
    {
        /*SWS_Dem_01257*//*SWS_Dem_01258*/
        Result = (Std_ReturnType)Dem_SelectDTCState[ClientId];
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetDTCSelectionResultForClearDTC          SWS_Dem_91020
*
* Description: Provides information if the last call to Dem_SelectDTC has .
*              selected a valid DTC or group of DTCs, respecting the settings
*              if the Dem shall clear only all DTCs.
* Inputs: ClientId:  Unique client id, assigned to the instance of the calling module
*
* Outputs:
*
* Return: E_OK: The DTC select parameter check is successful and the requested DTC
*               or group of DTC in the selected origin is selected for further operations.
*         E_NOT_OK: No DTC selected
*         DEM_WRONG_DTC: Selected DTC value in selected format does not exist.
*         DEM_WRONG_DTCORIGIN: Selected DTCOrigin does not exist.
*         DEM_PENDING: Checking the SelectDTC parameters is currently in progress.
*         DEM_BUSY: Another Dem_SelectDTC or Dem_SelectDTC dependent operation
*                    of this client is currently in progress.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (Std_ReturnType, DEM_CODE) Dem_GetDTCSelectionResultForClearDTC
(
    uint8 ClientId
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDTCSELECTIONRESUITFORCLEARDTC_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    /*SWS_Dem_01299*/
    else if(Dem_DTCIsSelected[ClientId] == FALSE)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDTCSELECTIONRESUITFORCLEARDTC_APIID, DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
    /*SWS_Dem_01256*/
    else if((Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_GROUP)\
        ||(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_SINGLE))
    {
        /*SWS_Dem_01296*/
#if(DEM_CFG_CLEARDTCLIMITATION == DEM_ONLY_CLEAR_ALL_DTCS)
        if(Dem_SelectDTC_DTC[ClientId] != DEM_DTC_GROUP_ALL)
        {
            Result = DEM_WRONG_DTC;
        }
#else
        Result = E_OK;
#endif

    }
    else if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_CHECKING)
    {
        /*Checking the SelectDTC parameters is finished in Dem_SelectDTC,so do not retern DEM_PENDING*/
        Result = DEM_PENDING;
    }
    else if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PROCESSING)
    {
        Result = DEM_BUSY;
    }
    else
    {
        /*SWS_Dem_01257*//*SWS_Dem_01258*/
        Result = (Std_ReturnType)Dem_SelectDTCState[ClientId];
    }
    return Result;
}
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetDTCSuppression
*
* Description: Returns the suppression status of a specific DTC
*
* Inputs: ClientId: Identification of an event by assigned EventId.
*         SuppressionStatus: Defines the output-format of the requested DTC value.
*
* Outputs: DTCOfEvent: Receives the DTC value in respective format returned by
*                      this function. If the return value of the function is
*                      other than E_OK this parameter does not contain valid data.
*
* Return: E_OK: get of DTC was successful
*         E_NOT_OK: the call was not successful
*         DEM_E_NO_DTC_AVAILABLE: there is no DTC configured in the requested
*                                 format
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC (Std_ReturnType, DEM_CODE) Dem_GetDTCSuppression
(
    uint8 ClientId,
    boolean* SuppressionStatus
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint16 DtcId;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDTCSUPPRESSION_APIID, DEM_E_UNINIT);
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if(Dem_DTCIsSelected[ClientId] == FALSE)
    {
        /*No DTC selected*/
        DEM_DET_REPORT_ERROR(DEM_GETDTCSUPPRESSION_APIID, DEM_E_WRONG_CONDITION);
    }
    else if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PROCESSING)
    {
        Result = DEM_BUSY;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_CHECKING)\
        ||(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PENDING))
    {
        Result = DEM_PENDING;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_WRONG_DTC)\
        ||(Dem_SelectDTCState[ClientId] == DEM_WRONG_DTCORIGIN))
    {
        Result = Dem_SelectDTCState[ClientId] ;
    }
    else
    {
        DtcId = Dem_SelectDTC_Index[ClientId];
        *SuppressionStatus = Dem_DTCSuppressionState[DtcId];
        Result = E_OK;
    }
    return Result;
}
#endif

#if(DEM_NUM_OF_EN_CONDITION > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetEnableCondition
*
* Description: Sets an enable condition.
*
* Inputs: EnableConditionID: This parameter identifies the enable condition.
*         ConditionFulfilled: This parameter specifies whether the enable
*                             condition assigned to the EnableConditionID is
*                             fulfilled (TRUE) or not fulfilled (FALSE).
*
* Outputs: None
*
* Return: E_OK: the enable condition could be set successfully
*         E_NOT_OK: the setting of the enable condition failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEnableCondition
(
    uint8 EnableConditionID,
    boolean ConditionFulfilled
)
{
    /*SWS_Dem_00202*/
    Std_ReturnType Result = E_OK;
    if(DEM_GET_STATE!= DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETENABLECONDITION_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if(EnableConditionID >= (uint8)DEM_NUM_OF_EN_CONDITION)
    {
        DEM_DET_REPORT_ERROR(DEM_SETENABLECONDITION_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
    else
    {
#if(DEM_CORE_NUMBER > 1)
        Dem_EnConditionBuff[EnableConditionID] = (uint8)ConditionFulfilled;
#else
        DemInternal_SetEnCondition(EnableConditionID,ConditionFulfilled);
#endif


    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_SetEnCondition
*
* Description: Sets an enable condition.
*
* Inputs: EnableConditionID: This parameter identifies the enable condition.
*         ConditionFulfilled: This parameter specifies whether the enable
*                             condition assigned to the EnableConditionID is
*                             fulfilled (TRUE) or not fulfilled (FALSE).
*
* Outputs: None
*
* Return: E_OK: the enable condition could be set successfully
*         E_NOT_OK: the setting of the enable condition failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_SetEnCondition
(
    uint8 EnableConditionID,
    boolean ConditionFulfilled
)
{

    Dem_EventIdType EventId;
    uint8 i;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if((ConditionFulfilled == TRUE) && (Dem_EventEnCondition[EnableConditionID] == FALSE))
    {
        Dem_EventEnCondition[EnableConditionID] = TRUE;
#if(DEM_NUM_OF_EN_GROUP > 0)
        /*SWS_Dem_00681*/
        for(EventId= (Dem_EventIdType)0; EventId < DEM_NUM_OF_EVENT;EventId++)
        {
            if(DEM_CFG_EVENT_EN(EventId) != NULL_PTR)
            {
                for( i = (uint8)0; i < (uint8)DEM_CFG_EVENT_EN_NUM(EventId); i++)
                {
                    if(Dem_EventEnCondition[DEM_CFG_EVENT_EN_REF(EventId)[i]]== FALSE)
                    {
                        break;
                    }
                }
                if(i == DEM_CFG_EVENT_EN_NUM(EventId))
                {
#if(DEM_INITMFORE_CALLBACK_SUPPORT == STD_ON)
                    if(DEM_CFG_EVENT_INITM_CALLFNC(EventId) != NULL_PTR)
                    {
#if(DEM_CORE_NUMBER > 1)
                        if(CoreId != DEM_CFG_EVENT_COREREF(EventId))
                        {
                            DEM_CFG_EVENT_INITM_FLAG(EventId) = TRUE;
                            DEM_CFG_EVENT_INITM_REASON(EventId) = DEM_INIT_MONITOR_REENABLED;
                        }
                        else
#endif
                        {
                            DEM_CFG_EVENT_INITM_CALLFNC(EventId)(DEM_INIT_MONITOR_REENABLED);
                        }
                    }
#endif
                }
            }
        }
#endif
    }
    else if((ConditionFulfilled == FALSE) && (Dem_EventEnCondition[EnableConditionID] == TRUE))
    {
        Dem_EventEnCondition[EnableConditionID] = FALSE;
#if(DEM_NUM_OF_EN_GROUP > 0)
        for(EventId = (Dem_EventIdType)0; EventId < (Dem_EventIdType)DEM_NUM_OF_EVENT; EventId++)
        {
            if(DEM_CFG_EVENT_EN(EventId) != NULL_PTR)
            {
                for(i = (uint8)0; i < (uint8)DEM_CFG_EVENT_EN_NUM(EventId); i++)
                {
                    if((DEM_CFG_EVENT_EN_REF(EventId)[i]) == EnableConditionID)
                    {
                        /*PRQA S 715 ++*/
                        /*
                        Nesting of control structures (statements) exceeds 15, without modification.
                        */
                        /*SWS_Dem_00654*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
                        if((DEM_CFG_EVENT_DBC(EventId) != NULL_PTR) \
                            && (DEM_CFG_EVENT_DBC_BEHAVIOR(EventId) == DEM_DEBOUNCE_RESET))
                        {
                            DEM_EVENT_DBC(EventId) = (sint16)0;
                        }
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
                        if((DEM_CFG_EVENT_DBT(EventId) != NULL_PTR) \
                            && (DEM_CFG_EVENT_DBT_BAHAVIOR(EventId) == DEM_DEBOUNCE_RESET))
                        {
                            DEM_EVENT_DBT(EventId) = (uint32)0;
                            DEM_EVENT_TIMERDIRECTION(EventId) = DEM_DATA_INVALID_U8;
                        }
#endif
                            /*PRQA S 715 --*/
                        break;
                    }
                }
            }/*if(DEM_CFG_EVENT_EN(EventId) != NULL_PTR)*/
        }
#endif
    }
    else
    {
        /*do nothing*/
    }
}

#endif/*#if(DEM_NUM_OF_EN_CONDITION > 0)*/

#if(DEM_NUM_OF_STOR_CONDITION > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetStorageCondition
*
* Description: Sets a storage condition.
*
* Inputs: StorageConditionID: This parameter identifies the storage condition.
*         ConditionFulfilled: This parameter specifies whether the storage
*                             condition assigned to the StorageConditionID is
*                             fulfilled (TRUE) or not fulfilled (FALSE).
*
* Outputs: None
*
* Return: E_OK: the storage condition could be set successfully
*         E_NOT_OK: the setting of the storage condition failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetStorageCondition
(
    uint8 StorageConditionID,
    boolean ConditionFulfilled
)
{

    /*SWS_Dem_00543*/
    Std_ReturnType Result = E_OK;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETSTORAGECONDITION_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if(StorageConditionID >= (uint8)DEM_NUM_OF_STOR_CONDITION)
    {
        DEM_DET_REPORT_ERROR(DEM_SETSTORAGECONDITION_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
    else
    {
#if(DEM_CORE_NUMBER > 1)
        Dem_StorConditionBuff[StorageConditionID] = StorageConditionID;
#else
        Result = DemInternal_SetStorCondition(StorageConditionID, ConditionFulfilled);
#endif

    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_MainFuc_SetStorageCondition
*
* Description: Sets a storage condition.
*
* Inputs:
*
* Outputs: None
*
* Return:
*
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_SetStorCondition
(
    uint8 StorageConditionID,
    boolean ConditionFulfilled
)
{
    uint8 i;
    Dem_EventIdType EventId;
    Std_ReturnType Result = E_OK;
    if((ConditionFulfilled == TRUE)&&(Dem_EventStorCondition[StorageConditionID] == FALSE))
    {
        Dem_EventStorCondition[StorageConditionID] = TRUE;
        /*SWS_Dem_01113*/
        for(EventId= (Dem_EventIdType)0; EventId < (Dem_EventIdType)DEM_NUM_OF_EVENT;EventId++)
        {
            if(DEM_CFG_EVENT_STOR(EventId) != NULL_PTR)
            {
                for(i = (uint8)0; i < (uint8)DEM_CFG_EVENT_STOR_NUM(EventId); i++)
                {
                    if(Dem_EventStorCondition[DEM_CFG_EVENT_STOR_REF(EventId)[i]]== FALSE)
                    {
                        break;
                    }
                }
                if(i == DEM_CFG_EVENT_STOR_NUM(EventId))
                {
#if(DEM_INITMFORE_CALLBACK_SUPPORT == STD_ON)
                    if(DEM_CFG_EVENT_INITM_CALLFNC(EventId) != NULL_PTR)
                    {
#if(DEM_CORE_NUMBER > 1)
                        if(CoreId != DEM_CFG_EVENT_COREREF(EventId))
                        {
                            DEM_CFG_EVENT_INITM_FLAG(EventId) = TRUE;
                            DEM_CFG_EVENT_INITM_REASON(EventId) = DEM_INIT_MONITOR_REENABLED;
                        }
                        else
#endif
                        {
                            DEM_CFG_EVENT_INITM_CALLFNC(EventId)(DEM_INIT_MONITOR_REENABLED);
                        }
                    }
#endif
                }
            }
        }
    }
    else if((ConditionFulfilled == FALSE)&&(Dem_EventStorCondition[StorageConditionID] == TRUE))
    {
        Dem_EventStorCondition[StorageConditionID] = FALSE;
    }
    else
    {
        Result = E_NOT_OK;
    }
    return Result;
}

#endif

#if(DEM_CORE_NUMBER > 1)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_MainFuc_SetStorageCondition
*
* Description: Sets a storage condition.
*
* Inputs:
*
* Outputs: None
*
* Return:
*
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_MainFnc_ServiceHandle
(
    void
)
{
    uint8 index;
    Dem_EventIdType EventId;
#if(DEM_NUM_OF_EN_CONDITION > 0)
    for(index = (uint8)0; index < DEM_NUM_OF_EN_CONDITION; index++ )
    {
        if(Dem_EnConditionBuff[index] != DEM_DATA_INVALID_U8)
        {
            DemInternal_SetEnCondition(index, Dem_EnConditionBuff[index]);
            Dem_EnConditionBuff[index] = DEM_DATA_INVALID_U8;
        }

    }
#endif
#if(DEM_NUM_OF_STOR_CONDITION > 0)
    for(index = (uint8)0; index < DEM_NUM_OF_STOR_CONDITION; index++ )
    {
        if(Dem_StorConditionBuff[index] != DEM_DATA_INVALID_U8)
        {
            DemInternal_SetStorCondition(index, Dem_StorConditionBuff[index]);
            Dem_StorConditionBuff[index] = DEM_DATA_INVALID_U8;
        }

    }
#endif
    for(EventId = 0; EventId < DEM_NUM_OF_EVENT; EventId++)
    {
        if(Dem_DebounceStatusBuff[EventId] != DEM_DATA_INVALID_U8)
        {
            DemInternal_ResetEventDebounceStatus(EventId, Dem_DebounceStatusBuff[EventId]);
            Dem_DebounceStatusBuff[EventId] = DEM_DATA_INVALID_U8;
        }
        if(Dem_ResetEventStatusBuff[EventId] != FALSE)
        {
            DemInternal_ResetEventStatus(EventId);
            Dem_ResetEventStatusBuff[EventId] = FALSE;
        }
    }

}
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetFaultDetectionCounter
*
* Description: Gets the fault detection counter of an event. This API can only
*              be used through the RTE, and therefore no declaration is exported
*              via Dem.h.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: FaultDetectionCounter: This parameter receives the Fault Detection
*                                 Counter information of the requested EventId.
*                                 If the return value of the function call is
*                                 other than E_OK this parameter does not
*                                 contain valid data.
*
* Return: E_OK: request was successful
*         E_NOT_OK: request failed
*         DEM_E_NO_FDC_AVAILABLE: there is no fault detection counter available
*                                 for the requested event.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetFaultDetectionCounter
(
    Dem_EventIdType EventId,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter
)
{
    Std_ReturnType Result = E_OK;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETFAULTDETECTIONCOUNTER_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETFAULTDETECTIONCOUNTER_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
    else if(FaultDetectionCounter == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETFAULTDETECTIONCOUNTER_APIID, DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
        Result = E_NOT_OK;
    }
#endif
    else
    {
        /*SWS_Dem_00204*/
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
        if(DEM_CFG_EVENT_DBC(EventId) != NULL_PTR)
        {
            if(DEM_EVENT_DBC(EventId) >= (sint16)0)
            {
                *FaultDetectionCounter = DEM_EVENT_DBC_F_FDC(EventId);
            }
            else
            {
                *FaultDetectionCounter = DEM_EVENT_DBC_P_FDC(EventId);
            }
        }
        else
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
        if(DEM_CFG_EVENT_DBT(EventId) != NULL_PTR)
        {
            if((DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_FAILED) \
                    || (DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREFAILED))
            /*PRQA S 4394 ++*/
            /*
            This converts the value of the time debounce counter to the range of -128 to 127, ignoring warnings about type coercion in compound expressions.
            */
            {
                *FaultDetectionCounter = DEM_EVENT_DBT_F_FDC(EventId);
            }
            else if((DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PASSED) \
                    || (DEM_EVENT_TIMERDIRECTION(EventId) == DEM_EVENT_STATUS_PREPASSED))
            {
                *FaultDetectionCounter = DEM_EVENT_DBT_P_FDC(EventId);
            }
            /*PRQA S 4394 -- */
            /*
            This converts the value of the time debounce counter to the range of -128 to 127, ignoring warnings about type coercion in compound expressions.
            */
            else
            {
                *FaultDetectionCounter = (sint8)0;
            }
        }
        else
#endif
        if(DEM_CFG_EVENT_GET_FDC_FNC(EventId) != NULL_PTR)
        {

            /*SWS_Dem_00264*//*SWS_Dem_00439*/
            Result = DEM_CFG_EVENT_GET_FDC_FNC(EventId)(FaultDetectionCounter);

        }
        else
        {
            /*SWS_Dem_00671*/
            Result = DEM_E_NO_FDC_AVAILABLE;
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetIndicatorStatus
*
* Description: Gets the indicator status derived from the event status.
*
* Inputs: IndicatorId: Number of indicator
*
* Outputs: IndicatorStatus: Status of the indicator, like off, on, or blinking.
*
* Return: E_OK: Operation was successful
*         E_NOT_OK: Operation failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetIndicatorStatus
(
    uint8 IndicatorId,
    P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus
)
{
    /*SWS_Dem_00046*/
    Std_ReturnType Result = E_NOT_OK;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETINDICATORSTATUS_APIID, DEM_E_UNINIT);
    }
    else if((uint8)DEM_NUM_OF_INDICATOR <= IndicatorId)
    {
        DEM_DET_REPORT_ERROR(DEM_GETINDICATORSTATUS_APIID, DEM_E_PARAM_DATA);
    }
    else if(IndicatorStatus == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETINDICATORSTATUS_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
#if(DEM_NUM_OF_INDICATOR > 0)
        DemInternal_GetIndicatorStatus(IndicatorId, IndicatorStatus);
        Result = E_OK;
#endif
    }
    return Result;
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetEventFreezeFrameDataEx
*
* Description: Gets the data of a freeze frame by event.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         RecordNumber: This parameter is a unique identifier for a freeze frame
*                       record as defined in ISO14229-1. 0xFF means most recent
*                       freeze frame record is returned. 0x00 is only supported
*                       if the Dem module supports WWH-OBD (refer to DemOBDSupport)
*         DataId: This parameter specifies the DID (ISO14229-1) that shall be
*                 copied to the destination buffer.
*         BufSize: When the function is called this parameter contains the maximum
*                  number of data bytes that can be written to the buffer.
*
* Outputs: BufSize: The function returns the actual number of written data bytes
*                   in this parameter.
*          DestBuffer: This parameter contains a byte pointer that points to the
*                      buffer, to which the freeze frame data record shall be
*                      written to. The format is raw hexadecimal values and
*                      contains no header-information.
*
* Return: E_OK: Operation was successful
*         E_NOT_OK: Operation could not be performed
*         DEM_NO_SUCH_ELEMENT: The requested event data is not currently stored
*                                (but the request was valid)
*         DEM_BUFFER_TOO_SMALL: The provided buffer size is too small
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFreezeFrameDataEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    uint16 DataId,
    uint8 *DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    /*SWS_Dem_01062*//*SWS_Dem_00479*//*SWS_Dem_00995*/
    Std_ReturnType Result = E_NOT_OK;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETEVENTFREEZEFRAMEDATAEX_APIID, DEM_E_UNINIT);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTFREEZEFRAMEDATAEX_APIID, DEM_E_PARAM_DATA);
    }
    else if((DestBuffer == NULL_PTR) || (BufSize == NULL_PTR) || (*BufSize == (uint16)0))
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTFREEZEFRAMEDATAEX_APIID, DEM_E_PARAM_POINTER);
    }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_00996*//*SWS_Dem_01108*/
    }
#endif
    else if(DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) == DEM_DATA_INVALID_U8)
    {
        /*Result = E_NOT_OK;*/
    }
    else
    {
        Result = DemInternal_GetEventFreezeFrameDataEx(EventId, RecordNumber, DataId, DestBuffer, BufSize);
    }
    return Result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetEventExtendedDataRecordEx
*
* Description: Gets the data of an extended data record by event.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*         RecordNumber: Identification of requested Extended data record.Valid
*                       values are between 0x01 and 0xEF as defined in ISO14229-1.
*         BufSize: When the function is called this parameter contains the maximum
*                  number of data bytes that can be written to the buffer.
*
* Outputs: BufSize: The function returns the actual number of written data bytes in
*                   this parameter.
*          DestBuffer: This parameter contains a byte pointer that points to the
*                      buffer, to which the freeze frame data record shall be written
*                      to. The format is raw hexadecimal values and contains no
*                      header-information.
*
* Return: E_OK: Operation was successful
*         E_NOT_OK: Operation could not be performed
*         DEM_NO_SUCH_ELEMENT: The requested event data is not currently stored
*                                (but the request was valid)
*         DEM_BUFFER_TOO_SMALL: The provided buffer size is too small
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventExtendedDataRecordEx
(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    /*SWS_Dem_01062*//*SWS_Dem_00477*//*SWS_Dem_00995*/
    Std_ReturnType Result = E_NOT_OK;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETEVENTEXTENDEDDATARECORDEX_APIID, DEM_E_UNINIT);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTEXTENDEDDATARECORDEX_APIID, DEM_E_PARAM_DATA);
    }
    else if((DestBuffer == NULL_PTR) || (BufSize == NULL_PTR) || (*BufSize == (uint16)0))
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTEXTENDEDDATARECORDEX_APIID, DEM_E_PARAM_POINTER);
    }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_00997*//*SWS_Dem_01108*/
    }
#endif
    else if(DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) == DEM_DATA_INVALID_U8)
    {
        /*Result = E_NOT_OK;*/
    }
    else
    {
        Result = DemInternal_GetEventExtendedDataRecordEx(EventId, RecordNumber, DestBuffer, BufSize);
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetEventMemoryOverflow
*
* Description: Control the internal debounce counter/timer by BSW modules and SWCs.
*              The event qualification will not be affected by these debounce state
*              changes. This API is available for BSW modules as soon as Dem_PreInit
*              has been completed
*
* Inputs: DTCOrigin: If the Dem supports more than one event memory this parameter
*                    is used to select the source memory the overflow indication
*                    shall be read from.
*
* Outputs: OverflowIndication: This parameter returns TRUE if the according event
*                              memory was overflowed, otherwise it returns FALSE.
*
* Return: E_OK: Operation was successful
*         E_NOT_OK: Operation failed or is not supported
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventMemoryOverflow
(
    uint8 ClientId,
    Dem_DTCOriginType DTCOrigin,
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) OverflowIndication
)
{
    /*SWS_Dem_00397*//*SWS_Dem_00398*/
    Std_ReturnType Result = E_OK;
    uint8 EventMemSetId;
#if(DEM_NUM_OF_USERDEF > 0)
    uint8 UserdefMemId;
#endif
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETEVENTMEMORYOVERFLOW_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if(ClientId >= DEM_NUM_OF_CLIENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTMEMORYOVERFLOW_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
    else if(OverflowIndication == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETEVENTMEMORYOVERFLOW_APIID, DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
    else
    {
        EventMemSetId = DEM_CLIENT_EVENT_MEM(ClientId);
        if(DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
        {
            if(DEM_PRIMARY_DATAENTRY_USEDNUM(EventMemSetId) < DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY(EventMemSetId))
            {
                *OverflowIndication = FALSE;
            }
            else
            {
                *OverflowIndication = TRUE;
            }
        }
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
        else if(DTCOrigin == DEM_DTC_ORIGIN_PERMANENT_MEMORY)
        {
            if(DEM_PERMANENT_DATAENTRY_USEDNUM(EventMemSetId) < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT(EventMemSetId))
            {
                *OverflowIndication = FALSE;
            }
            else
            {
                *OverflowIndication = TRUE;
            }
        }
#endif
#if(DEM_NUM_OF_USERDEF > 0)
        else if((DTCOrigin & DEM_DTC_ORIGIN_USERDEFINED_MEMORY_XX) != 0)
        {
            UserdefMemId = (uint8)(DTCOrigin & DEM_DTC_REQURE_USERDEFINED_MEMORY_ID);
            if(UserdefMemId >= (uint8)DEM_NUM_OF_USERDEF)
            {
                DEM_DET_REPORT_ERROR(DEM_GETEVENTMEMORYOVERFLOW_APIID, DEM_E_PARAM_DATA);
                Result = E_NOT_OK;
            }
            else
            {

                if(DEM_USER_DEFINED_DATAENTRY_USEDNUM(EventMemSetId,UserdefMemId) <  DEM_CFG_MAXNUMBEREVENTENTRY_USERDEFINED(UserdefMemId))
                {
                    *OverflowIndication = FALSE;
                }

            }
        }
#endif
        else
        {
            Result = E_NOT_OK;
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetNumberOfEventMemoryEntries
*
* Description: Returns the number of entries currently stored in the requested
*              event memory.
*
* Inputs: DTCOrigin: If the Dem supports more than one event memory this parameter
*                    is used to select the source memory the number of entries
*                    shall be read from.
*
* Outputs: NumberOfEventMemoryEntries: Number of entries currently stored in the
*                                      requested event memory.
*
* Return: E_OK: Operation was successful
*         E_NOT_OK: Operation failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetNumberOfEventMemoryEntries
(
    uint8 ClientId,
    Dem_DTCOriginType DTCOrigin,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfEventMemoryEntries
)
{
    /*SWS_Dem_00651*/
    Std_ReturnType Result = E_OK;
#if(DEM_NUM_OF_USERDEF > 0)
    uint8 UserdefMemId;
#endif
    uint8 EventMemSetId;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETNUMBEROFEVENTMEMORYENTRIES_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if(NumberOfEventMemoryEntries == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETNUMBEROFEVENTMEMORYENTRIES_APIID, DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
    else if(ClientId >= DEM_NUM_OF_CLIENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETNUMBEROFEVENTMEMORYENTRIES_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
    else
    {
        EventMemSetId = DEM_CLIENT_EVENT_MEM(ClientId);
        if(DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
        {
            *NumberOfEventMemoryEntries = DEM_PRIMARY_DATAENTRY_USEDNUM(EventMemSetId);
        }
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
        else if(DTCOrigin == DEM_DTC_ORIGIN_PERMANENT_MEMORY)
        {
            *NumberOfEventMemoryEntries = DEM_PERMANENT_DATAENTRY_USEDNUM(EventMemSetId);
        }
#endif
#if(DEM_NUM_OF_USERDEF > 0)
        else if((DTCOrigin & DEM_DTC_ORIGIN_USERDEFINED_MEMORY_XX) != (Dem_DTCOriginType)0)
        {
            UserdefMemId = DEM_GET_SUBMEMORY_ID(DTCOrigin);
            if(UserdefMemId >= (uint8)DEM_NUM_OF_USERDEF)
            {
                DEM_DET_REPORT_ERROR(DEM_GETNUMBEROFEVENTMEMORYENTRIES_APIID, DEM_E_PARAM_DATA);
                Result = E_NOT_OK;
            }
            else
            {
                *NumberOfEventMemoryEntries = DEM_USER_DEFINED_DATAENTRY_USEDNUM(EventMemSetId,UserdefMemId);
            }
        }
#endif
        else
        {
            Result = E_NOT_OK;
        }
    }
    return Result;
}

#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetDTCSuppression
*
* Description: Set the suppression status of a specific DTC.
*
* Inputs: DTC: Diagnostic Trouble Code
*         DTCFormat: Defines the input-format of the provided DTC value.
*         SuppressionStatus: This parameter specifies whether the respective DTC
*                            shall be disabled (TRUE) or enabled (FALSE).
*
* Outputs: None
*
* Return: E_OK: Operation was successful
*         E_NOT_OK: operation failed or event entry for this DTC still exists
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTCSuppression
(
    uint8 ClientId,
    boolean SuppressionStatus
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint16 DtcId;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        DEM_DET_REPORT_ERROR(DEM_SETDTCSUPPRESSION_APIID, DEM_E_UNINIT);
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if(Dem_DTCIsSelected[ClientId] == FALSE)
    {
        DEM_DET_REPORT_ERROR(DEM_SETDTCSUPPRESSION_APIID, DEM_E_WRONG_CONDITION);
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_CHECKING)\
        ||(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PENDING))
    {
        Result = DEM_PENDING;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_WRONG_DTC)\
        ||(Dem_SelectDTCState[ClientId] == DEM_WRONG_DTCORIGIN))
    {
        Result = Dem_SelectDTCState[ClientId];
    }
    else if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PROCESSING)
    {
        Result = DEM_BUSY;
    }
    else
    {
        DtcId = Dem_SelectDTC_Index[ClientId];
        Result = DemInternal_SetDTCSuppression(DtcId,SuppressionStatus);
    }
    return Result;
}
#endif
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemIntermal_SetDTCSuppression
*
* Description: Set the suppression status of a specific DTC.
*
* Inputs: DTC: Diagnostic Trouble Code
*         DTCFormat: Defines the input-format of the provided DTC value.
*         SuppressionStatus: This parameter specifies whether the respective DTC
*                            shall be disabled (TRUE) or enabled (FALSE).
*
* Outputs: None
*
* Return: E_OK: Operation was successful
*         E_NOT_OK: operation failed or event entry for this DTC still exists
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_SetDTCSuppression
(
    uint16 DtcId,
    boolean SuppressionStatus
)
{
    Std_ReturnType Result = E_NOT_OK;
    Dem_EventIdType EventId;
    if(SuppressionStatus == FALSE)
    {
        for(EventId = (Dem_EventIdType)0 ; EventId < DEM_NUM_OF_EVENT; EventId++)
        {
#if(DEM_EVENT_COMBINATION_SUPPORT  != DEM_EVCOMB_DISABLED)
            if(DEM_IS_COMBINEDDTC(DtcId))
            {
                if(DtcId == DEM_CFG_EVENT_DTCREF(EventId))
                {
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
                    if(Dem_EventAvailable[EventId] == TRUE)
#endif
                    {
                        Dem_DTCSuppressionState[DtcId] = SuppressionStatus;
                        Result = E_OK;
                        break;
                    }
                }

            }
            else
#endif
            {
                if(DtcId == DEM_CFG_EVENT_DTCREF(EventId))
                {
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
                    if(Dem_EventAvailable[EventId] == FALSE)
                    {
                        Result = E_NOT_OK;
                    }
                    else
#endif
                    {
                        Dem_DTCSuppressionState[DtcId] = SuppressionStatus;
                        Result = E_OK;
                    }
                    break;

                }
            }
        }
    }
    else
    {
        Dem_DTCSuppressionState[DtcId] = SuppressionStatus;
        Result = E_OK;
    }
    return  Result ;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_ClearDTCNew
*
* Description: Clears single DTCs, as well as groups of DTCs. This API is intended
*              for complex device driver. It can only be used through the RTE (due
*              to work-around described below SWS_Dem_00659), and therefore no
*              declaration is exported via Dem.h.
*
* Inputs: ClientId:
*
* Outputs: None
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ClearDTC
(
    uint8 ClientId
)
{
    /*SWS_Dem_00659*/
    Std_ReturnType Result = E_OK;

#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        DEM_DET_REPORT_ERROR(DEM_CLEARDTC_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if(Dem_DTCIsSelected[ClientId] == FALSE)
    {
        /*SWS_Dem_01299*/
        DEM_DET_REPORT_ERROR(DEM_CLEARDTC_APIID, DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_CHECKING)\
        ||(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PENDING))
    {
        Result = DEM_PENDING;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_WRONG_DTC)\
        ||(Dem_SelectDTCState[ClientId] == DEM_WRONG_DTCORIGIN))
    {
        Result = (Std_ReturnType)Dem_SelectDTCState[ClientId];
    }
    /*SWS_Dem_01042*/
    else if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_IDLE)
    {

#if(DEM_CFG_CLEARDTCLIMITATION == DEM_ONLY_CLEAR_ALL_DTCS)
        if(Dem_SelectDTC_DTC[ClientId] != DEM_DTC_GROUP_ALL)
        {
            /*SWS_Dem_00670*/
            Result = DEM_WRONG_DTC;
            Dem_SelectDTCState[ClientId] = DEM_WRONG_DTC;
        }
        else
#endif
        {
            /*SWS_Dem_00661*//*SWS_Dem_00569*/
            Dem_ClearDTC_Client = ClientId;
            Dem_ClearDTC_DTC = Dem_SelectDTC_DTC[ClientId];
            Dem_ClearDTC_DTCFormat = Dem_SelectDTC_DTCFormat[ClientId];
            Dem_ClearDTC_DTCOrigin = Dem_SelectDTC_DTCOrigin[ClientId];
            Dem_ClearDTCInfo.ClearBlockIndex = (uint16)0;
            if((DEM_CFG_CLEAR_DTC_NOTIFICATION_FUN(DEM_CLIENT_EVENT_MEM(Dem_ClearDTC_Client)) != NULL_PTR) \
                &&(DEM_CFG_CLEAR_DTC_NOTIFICATION_TIME(DEM_CLIENT_EVENT_MEM(Dem_ClearDTC_Client)) == START))
            {
                (void)DEM_CFG_CLEAR_DTC_NOTIFICATION_FUN(DEM_CLIENT_EVENT_MEM(Dem_ClearDTC_Client))(Dem_ClearDTC_DTC,Dem_ClearDTC_DTCFormat,Dem_ClearDTC_DTCOrigin);
            }
#if(DEM_CFG_CLEARDTCLIMITATION != DEM_ONLY_CLEAR_ALL_DTCS)
            if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_GROUP)
            {
                Dem_ClearDTC_Index = (uint16)0;
                Dem_ClearDTCState = DEM_IN_CLEAR_DTC_GROUP_WAIT;
                DemInternal_GetClearDTCFromGroup();
                Dem_SelectDTCState[ClientId] = DEM_IN_SELECT_DTC_PENDING;
                Result = DEM_PENDING;
#if(DEM_NUM_OF_DTCGROUP > 0)
                if((Dem_SelectDTC_DTC[ClientId] != DEM_DTC_GROUP_ALL) && (Dem_SelectDTC_DTC[ClientId] != DEM_DTC_GROUP_EMISSION))
                {
                    /*Check if the request DTC is a group DTC.*/
                    Dem_ClearDTC_GroupIndex = Dem_SelectDTC_Index[ClientId];
                }
#endif
            }
            /*if the request DTC not a group DTC, it should be a single DTC.*/
            else
            {
                /*SWS_Dem_00172*/
                /*Clear RAM info of one DTC*/
                Dem_ClearDTC_Index = Dem_SelectDTC_Index[ClientId];
                DemInternal_GetClearEvent(Dem_ClearDTC_Index);
                Dem_ClearDTCState = DEM_IN_CLEAR_DTC_SINGLE_WAIT;
                Dem_SelectDTCState[ClientId] = DEM_IN_SELECT_DTC_PENDING;
                Result = DEM_PENDING;
            }
#else/*(DEM_CFG_CLEARDTCLIMITATION != DEM_ONLY_CLEAR_ALL_DTCS)*/
            Dem_SelectDTCState[ClientId] = DEM_IN_SELECT_DTC_PENDING;
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_GROUP_WAIT;
            DemInternal_GetClearDTCFromGroup();
            Dem_ClearDTC_Index = (uint16)0;
            Result = DEM_PENDING;
#endif/*(DEM_CFG_CLEARDTCLIMITATION != DEM_ONLY_CLEAR_ALL_DTCS)*/
        }
    }
    else
    {
        if((Dem_ClearDTC_Client != ClientId)\
            || (Dem_ClearDTC_DTC != Dem_SelectDTC_DTC[ClientId])\
            || (Dem_ClearDTC_DTCFormat != Dem_SelectDTC_DTCFormat[ClientId])\
            || (Dem_ClearDTC_DTCOrigin != Dem_SelectDTC_DTCOrigin[ClientId]))
        {
            /*SWS_Dem_00662*//*SWS_Dem_00664*/
            Result = DEM_CLEAR_BUSY;
        }
        else
        {
            if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_OK)
            {
                Dem_ClearDTCState = DEM_IN_CLEAR_DTC_IDLE;
                Dem_SelectDTCState[ClientId] = DEM_IN_SELECT_DTC_IDLE;
                /*SWS_Dem_00572*/
                Result = E_OK;
            }
            else if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_ERR)
            {
                Dem_ClearDTCState = DEM_IN_CLEAR_DTC_IDLE;
                Dem_SelectDTCState[ClientId] = DEM_IN_SELECT_DTC_IDLE;
                /*SWS_Dem_01057*/
                Result = DEM_CLEAR_MEMORY_ERROR;
            }
            else if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_FAILED)
            {
                Dem_ClearDTCState = DEM_IN_CLEAR_DTC_IDLE;
                Dem_SelectDTCState[ClientId] = DEM_IN_SELECT_DTC_IDLE;
                Result = DEM_CLEAR_FAILED;
            }
            else
            {
                /*SWS_Dem_00663*/
                Result = DEM_PENDING;
            }
        }
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_MainFunction
*
* Description: Processes all not event based Dem internal functions.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DEM_CODE) Dem_MainFunction
(
    void
)
{
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    /*SWS_Dem_00125*/
    if(DEM_GET_STATE == DEM_NORMAL)
    {
#if(DEM_CORE_NUMBER > 1)
        if(CoreId == DEM_MASTER_COREID)
        {
#endif
            if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_IDLE)
            {
#if(DEM_CORE_NUMBER > 1)
                DemInternal_MainFnc_ServiceHandle();
#endif
                DemInternal_MainFnc_OperationCycle();
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
                DemInternal_MainFnc_DebounceTimer();
#endif
                DemInternal_MainFnc_UDSStatusHandle();
                /*SWS_Dem_00806*/
                DemInternal_MainFnc_CaptureData();
            }
            /*Clear the group DTC or Write the RAM info which has been cleared in nonvalatile memory.*/
            DemInternal_MainFnc_ClearDTC();

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
            DemInternal_MainFnc_OBD();
#endif
#if(DEM_CORE_NUMBER > 1)
        }
        else
        {
#if(DEM_CSDATA_IN_MASTER_SUPPORT != STD_ON)
            DemInternal_ObtainCSData();
#endif
#if(DEM_EVENT_CALLBACK_SUPPORT == STD_ON)
            DemInternal_MainFnc_Notification();
#endif
        }
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetEventStorageEntry
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventStorageEntry
(
    Dem_EventIdType EventId,
    P2VAR(Dem_MemIdType, AUTOMATIC, DEM_APPL_DATA) DataEntryId
)
{
    Std_ReturnType ret = E_NOT_OK;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        /*Result = E_NOT_OK;*/
    }
    else if (DataEntryId == NULL_PTR)
    {
        /* code */
    }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
    else
    {
        if(DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)
        {
            if(DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId)) != DEM_DATA_INVALID_U8)
            {
                *DataEntryId = DEM_DTC_DATAENTRYREF(DEM_CFG_EVENT_DTCREF(EventId));
                ret = E_OK;
            }

        }

    }
    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetEventInternalData
*
* Description: Get the internal data of one event.
*              It's not AUTOSAR standard interface.
*
* Inputs: EventId,DataType
*
* Outputs: DataValue
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventInternalData
(
    Dem_EventIdType EventId,
    Dem_InternalDataElementType DataType,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DataValue
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        /*Result = E_NOT_OK;*/
    }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
    else
    {
        DemInternal_GetEventInternalData(EventId, DataType, DataValue);
        Result = E_OK;
    }

    return Result;
}

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetEventDisabled
*
* Description: Service for reporting the event as disabled to the Dem for the
*              PID $41 computation.
*
* Inputs: EventId: Identification of an event by assigned EventId.
*
* Outputs: None
*
* Return: E_OK: set of event to disabled was successfull.
*         E_NOT_OK: set of event disabled failed.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00312*//*SWS_Dem_00294*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventDisabled
(
    Dem_EventIdType EventId
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
    Dem_EventOBDReadinessGroupType ReadinessGroup = DEM_OBD_RDY_NONE;
    uint8 BytePos;
    uint8 BitPos;
#endif
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETEVENTDISABLED_APIID, DEM_E_UNINIT);
    }
    else if(EventId >= DEM_NUM_OF_EVENT)
    {
        DEM_DET_REPORT_ERROR(DEM_SETEVENTDISABLED_APIID, DEM_E_PARAM_DATA);
    }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    else if(Dem_EventAvailable[EventId] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
    else
    {
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
        /*SWS_Dem_00348*/
        ReadinessGroup = DEM_CFG_DTC_OBD_READINESSGROUP(DEM_CFG_EVENT_DTCREF(EventId));

        if(ReadinessGroup != DEM_OBD_RDY_NONE)
        {
            BytePos = (ReadinessGroup/8);
            BitPos = (ReadinessGroup%8);

            DEM_OBD_READINESSGROUP_STATUS[BytePos] &= (~((uint8)0x01 << BitPos));

            Result = E_OK;
        }
#endif
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_RepIUMPRFaultDetect
*
* Description: Service for reporting that faults are possibly found because all
*              conditions are fullfilled.
*
* Inputs: RatioID: Ratio Identifier reporting that a respective monitor could
*                  have found a fault- only used when interface option "API"
*                  is selected.
*
* Outputs: None
*
* Return: E_OK: report of IUMPR result was successfully reported.
*         E_NOT_OK: report of IUMPR result failed.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00313*//*SWS_Dem_00360*//*SWS_Dem_00296*/
FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRFaultDetect
(
    Dem_RatioIdType RatioID
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_NUM_OF_RATIO > 0)
    Dem_EventIdType EventId;
    Dem_UdsStatusByteType DtcStatus;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRFAULTDETECT_APIID, DEM_E_UNINIT);
    }
    else if(RatioID >= DEM_NUM_OF_RATIO)
    {
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRFAULTDETECT_APIID, DEM_E_PARAM_DATA);
    }
    else if(DEM_CFG_RATIO_KIND(RatioID) != DEM_RATIO_API)
    {
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRFAULTDETECT_APIID, DEM_E_WRONG_CONFIGURATION);
    }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    else if(Dem_EventAvailable[DEM_CFG_RATIO_EVENTREF(RatioID)] == FALSE)
    {
        /*SWS_Dem_01108*//*SWS_Dem_00709*/
    }
#endif
    else
    {
        EventId = DEM_CFG_RATIO_EVENTREF(RatioID);
        DtcStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));

        /*SWS_Dem_00299*//*Check event status*/
        if(!DEM_TEST_UDS_STATUS_PDTC(DtcStatus))
        {
            /*SWS_Dem_01188*/
            if((DEM_OBD_RATIO_STATE(RatioID) & DEM_OBD_NUM_INCREASED_MASK) == (uint8)0)
            {
                /*increase 1 to the numerator*/
                DEM_OBD_RATIO_NUMERATOR(RatioID)++;
                DEM_OBD_RATIO_STATE(RatioID) |= DEM_OBD_NUM_INCREASED_MASK;
            }

            if(DEM_OBD_RATIO_NUMERATOR(RatioID) >= DEM_OBD_NUMDEN_MAX_VALUE)
            {
                DEM_OBD_RATIO_NUMERATOR(RatioID) = (DEM_OBD_RATIO_NUMERATOR(RatioID) >> (uint16)1);
                DEM_OBD_RATIO_DENOMINATOR(RatioID) = (DEM_OBD_RATIO_DENOMINATOR(RatioID) >> (uint16)1);
            }
        }

        Result = E_OK;
    }
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetIUMPRDenCondition
*
* Description: In order to communicate the status of the (additional) denominator
*              conditions among the OBD relevant ECUs, the API is used to forward
*              the condition status to a Dem of a particular ECU.
*
* Inputs: ConditionId: Identification of a IUMPR denominator condition ID
*                      (General Denominator, Cold start, EVAP, 500mi).
*         ConditionStatus: Status of the IUMPR denominator condition (Notreached,
*                          reached, not reachable / inhibited)
*
* Outputs: None
*
* Return: E_OK: set of IUMPR denominator condition was successful.
*         E_NOT_OK: set of IUMPR denominator condition failed or could not be
*                   accepted.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00733*//*SWS_Dem_00714*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetIUMPRDenCondition
(
    Dem_IumprDenomCondIdType ConditionId,
    Dem_IumprDenomCondStatusType ConditionStatus
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_NUM_OF_RATIO > 0)
    Dem_IumprDenomCondStatusType OldConditionStatus = DEM_IUMPR_DEN_STATUS_REACHED;
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETIUMPRDENCONDITION_APIID, DEM_E_UNINIT);
    }
    else
    {
#if(DEM_NUM_OF_RATIO > 0)
        OldConditionStatus = DEM_OBD_RATIO_DENOMCOND_STATUS(ConditionId);
        /*SWS_Dem_00717*//*Set and record the status*/
        DEM_OBD_RATIO_DENOMCOND_STATUS(ConditionId) = ConditionStatus;

        if(ConditionId == DEM_IUMPR_GENERAL_DENOMINATOR)
        {
            if((ConditionStatus == DEM_IUMPR_DEN_STATUS_REACHED) \
                && ((DEM_OBD_RATIO_GENDEN_STATE & DEM_OBD_DEN_INCREASED_MASK) == (uint8)0))
            {
                DEM_OBD_RATIO_GENDEN_CNT++;
                DEM_OBD_RATIO_GENDEN_STATE |= DEM_OBD_DEN_INCREASED_MASK;
            }
            else if(ConditionStatus == DEM_IUMPR_DEN_STATUS_INHIBITED)
            {
                DEM_OBD_RATIO_GENDEN_STATE |= DEM_OBD_DEN_INCREASED_MASK;
            }
            else
            {
                /*do nothing*/
            }
        }

        if((OldConditionStatus != ConditionStatus) \
            && (ConditionStatus == DEM_IUMPR_DEN_STATUS_REACHED))
        {
            DemInternal_UpdateRatioDenominator();
        }

        Result = E_OK;
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetIUMPRDenCondition
*
* Description: In order to communicate the status of the (additional) denominator
*              conditions among the OBD relevant ECUs, the API is used to retrieve
*              the condition status from the Dem of the ECU where the conditions
*              are computed.
*
* Inputs: ConditionId: Identification of a IUMPR denominator condition ID
*                      (General Denominator, Cold start, EVAP, 500mi).
*
* Outputs: ConditionStatus: Status of the IUMPR denominator condition (Notreached,
*                           reached, not reachable / inhibited)
*
* Return: E_OK: get of IUMPR denominator condition was successful.
*         E_NOT_OK: get of condition status failed.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00734*//*SWS_Dem_00966*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetIUMPRDenCondition
(
    Dem_IumprDenomCondIdType ConditionId,
    P2VAR(Dem_IumprDenomCondStatusType, AUTOMATIC, DEM_APPL_DATA) ConditionStatus
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETIUMPRDENCONDITION_APIID, DEM_E_UNINIT);
    }
    else if (ConditionStatus == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETIUMPRDENCONDITION_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
#if(DEM_NUM_OF_RATIO > 0)
        /*SWS_Dem_00716*//*Read the status*/
        *ConditionStatus = DEM_OBD_RATIO_DENOMCOND_STATUS(ConditionId);

        Result = E_OK;
#endif
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_RepIUMPRDenLock
*
* Description: Service is used to lock a denominator of a specific monitor.
*
* Inputs: RatioID: Ratio Identifier reporting that specific denominator is locked
*                  (for physical reasons - e.g. temperature conditions or minimum
*                  activity).
*
* Outputs: None.
*
* Return: E_OK: report of IUMPR denominator status was successfully reported.
*         E_NOT_OK: report of IUMPR denominator status was not successfully
*                   reported.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00314*//*SWS_Dem_00362*//*SWS_Dem_00297*/
FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenLock
(
    Dem_RatioIdType RatioID
)
{
    Std_ReturnType Result = E_NOT_OK;

#if(DEM_NUM_OF_RATIO > 0)
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRDENLOCK_APIID, DEM_E_UNINIT);
    }
    else if(RatioID >= DEM_NUM_OF_RATIO)
    {
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRDENLOCK_APIID, DEM_E_PARAM_DATA);
    }
    else if(DEM_CFG_RATIO_IUMPR_DEN(RatioID) != DEM_IUMPR_DEN_PHYS_API)
    {
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRDENLOCK_APIID, DEM_E_WRONG_CONFIGURATION);
    }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    else if(Dem_EventAvailable[DEM_CFG_RATIO_EVENTREF(RatioID)] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
    else
    {
        /*Recod the lock status*/
        DEM_OBD_RATIO_STATE(RatioID) |= DEM_OBD_DEN_LOCK_MASK;

        Result = E_OK;
    }
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_RepIUMPRDenRelease
*
* Description: Service is used to release a denominator of a specific monitor.
*
* Inputs: RatioID: Ratio Identifier reporting that specific denominator is released
*                  (for physical reasons - e.g. temperature conditions or minimum
*                  activity).
*
* Outputs: None.
*
* Return: E_OK: report of IUMPR denominator status was successfully reported.
*         E_NOT_OK: report of IUMPR denominator status was not successfully
*                   reported.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00315*//*SWS_Dem_00362*//*SWS_Dem_00308*/
FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenRelease
(
    Dem_RatioIdType RatioID
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_NUM_OF_RATIO > 0)
    Dem_EventIdType EventId;
    Dem_UdsStatusByteType DtcStatus;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRDENRELEASE_APIID, DEM_E_UNINIT);
    }
    else if(RatioID >= DEM_NUM_OF_RATIO)
    {
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRDENRELEASE_APIID, DEM_E_PARAM_DATA);
    }
    else if(DEM_CFG_RATIO_IUMPR_DEN(RatioID) != DEM_IUMPR_DEN_PHYS_API)
    {
        DEM_DET_REPORT_ERROR(DEM_REPIUMPRDENRELEASE_APIID, DEM_E_WRONG_CONFIGURATION);
    }
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    else if(Dem_EventAvailable[DEM_CFG_RATIO_EVENTREF(RatioID)] == FALSE)
    {
        /*SWS_Dem_01108*/
    }
#endif
    else
    {
        /*Reset the lock status*/
        DEM_OBD_RATIO_STATE(RatioID) &= (~DEM_OBD_DEN_LOCK_MASK);
        /*SWS_Dem_00712*/
        if((DEM_OBD_RATIO_DENOMCOND_STATUS(DEM_IUMPR_DEN_GENERAL) == DEM_IUMPR_DEN_STATUS_REACHED) \
            && ((DEM_OBD_RATIO_STATE(RatioID) & DEM_OBD_DEN_INCREASED_MASK) == (uint8)0))
        {
            EventId = DEM_CFG_RATIO_EVENTREF(RatioID);
            DtcStatus = DEM_DTC_STATUS(DEM_CFG_EVENT_DTCREF(EventId));
            /*SWS_Dem_00299*/
            if(!DEM_TEST_UDS_STATUS_PDTC(DtcStatus))
            {
                DEM_OBD_RATIO_DENOMINATOR(RatioID)++;
                DEM_OBD_RATIO_STATE(RatioID) |= DEM_OBD_DEN_INCREASED_MASK;
            }

            if(DEM_OBD_RATIO_DENOMINATOR(RatioID) >= DEM_OBD_NUMDEN_MAX_VALUE)
            {
                DEM_OBD_RATIO_NUMERATOR(RatioID) = (DEM_OBD_RATIO_NUMERATOR(RatioID) >> (uint16)1);
                DEM_OBD_RATIO_DENOMINATOR(RatioID) = (DEM_OBD_RATIO_DENOMINATOR(RatioID) >> (uint16)1);
            }
        }

        Result = E_OK;
    }
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetGeneralNumeratorAndDenominator
*
* Description: This interface is provided to user to get the General Numerator
*              and Denominator of one Ratio or Event.
*
* Inputs: None
*
* Outputs: Numerator, Denominator
*
* Return: E_OK, E_NOT_OK
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetGeneralNumeratorAndDenominator
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Numerator,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Denominator
)
{
    Std_ReturnType Result = E_OK;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        Result = E_NOT_OK;
    }
    else if((Numerator == NULL_PTR) || (Denominator == NULL_PTR))
    {
        Result = E_NOT_OK;
    }
    else
    {
#if(DEM_NUM_OF_RATIO > 0)
        *Numerator = DEM_OBD_RATIO_IGN_CNT;
        *Denominator = DEM_OBD_RATIO_GENDEN_CNT;
#else
        Result = E_NOT_OK;
#endif
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetNumeratorAndDenominator
*
* Description: This interface is provided to user to get the Numerator and
*              Denominator of one Ratio or Event.
*
* Inputs: RatioID
*
* Outputs: EventId, Numerator, Denominator
*
* Return: E_OK, E_NOT_OK
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetNumeratorAndDenominator
(
    Dem_RatioIdType RatioID,
    P2VAR(Dem_EventIdType, AUTOMATIC, DEM_APPL_DATA) EventId,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Numerator,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Denominator
)
{
    Std_ReturnType Result = E_NOT_OK;

#if(DEM_NUM_OF_RATIO > 0)
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*Result = E_NOT_OK;*/
    }
    else if(RatioID >= DEM_NUM_OF_RATIO)
    {
        /*Result = E_NOT_OK;*/
    }
    else if((EventId == NULL_PTR) || (Numerator == NULL_PTR) \
        || (Denominator == NULL_PTR))
    {
        /*Result = E_NOT_OK;*/
    }
    else
    {
        *EventId = DEM_CFG_RATIO_EVENTREF(RatioID);
        *Numerator = DEM_OBD_RATIO_NUMERATOR(RatioID);
        *Denominator = DEM_OBD_RATIO_DENOMINATOR(RatioID);

        Result = E_OK;
    }
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
    return Result;
}


#if(DEM_CFG_PTO_SUPPORT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetPtoStatus
*
* Description: Set the status of the PTO(PID 0x1E).
*
* Inputs: PtoStatus: sets the status of the PTO (TRUE==active; FALSE==inactive).
*
* Outputs: None.
*
* Return: Returns E_OK when the new PTO-status has been adopted by the Dem;
*         returns E_NOT_OK in all other cases.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00627*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetPtoStatus
(
    boolean PtoStatus
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETPTOSTATUS_APIID, DEM_E_UNINIT);
    }
    else if((PtoStatus != TRUE) && (PtoStatus != FALSE))
    {
        DEM_DET_REPORT_ERROR(DEM_SETPTOSTATUS_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
        /*Not implemented.*/
        Result = E_OK;
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_ReadDataOfPID01
*
* Description: Service to report the value of PID $01 computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID01value: Buffer containing the contents of PID $01 computed by
*                      the Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_01167*/
FUNC(Std_ReturnType, DEM_CODE) Dem_ReadDataOfPID01
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID01value
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
    Dem_EventIdType EventId;
    uint16 DtcId;
    Dem_UdsStatusByteType DtcStatus;
    uint8 BytePos;
    uint8 BitPos;
    Dem_IndicatorStatusType IndicatorStatus;
    uint16 DTCMemId;
    uint8 ParentMemId;
#endif


    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_READDATAOFPID01_APIID, DEM_E_UNINIT);
    }
    else if(PID01value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_READDATAOFPID01_APIID, DEM_E_PARAM_POINTER);
    }
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
    else if(Dem_DTCSuppressionState[DEM_CFG_EVENT_DTCREF(DEM_OBD_FF_EVENT)] != FALSE)
    {

    }
#endif
    else
    {
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
        PID01value[0U] = DEM_DATA_CLEAR;
        /*Set the value of engine type bit*/
        PID01value[1U] = (uint8)(DEM_CFG_OBD_ENGINE_TYPE << (uint8)3);
        PID01value[2U] = DEM_DATA_CLEAR;
        PID01value[3U] = DEM_DATA_CLEAR;

        for(EventId = (Dem_EventIdType)0; EventId < DEM_NUM_OF_EVENT; EventId++)
        {
            DtcId = DEM_CFG_EVENT_DTCREF(EventId);
            DTCMemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId);
            ParentMemId = DEM_GET_EVENTMEMORY_ID(DTCMemId);
            /*SWS_Dem_00354*/
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
            if((Dem_EventAvailable[EventId] == TRUE) \
                && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR) \
                && (DEM_CFG_DTC_OBD_READINESSGROUP(DtcId) != DEM_OBD_RDY_NONE))
#else
            if((DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR) \
                && (DEM_CFG_DTC_OBD_READINESSGROUP(DtcId) != DEM_OBD_RDY_NONE))
#endif
            {
                BytePos = (DEM_CFG_DTC_OBD_READINESSGROUP(DtcId) / (Dem_EventOBDReadinessGroupType)8);
                BitPos = (DEM_CFG_DTC_OBD_READINESSGROUP(DtcId) % (Dem_EventOBDReadinessGroupType)8);
                /*Set value of monitors supported bit*/
                PID01value[BytePos + (uint8)1] |= ((uint8)0x01 << BitPos);

                DtcStatus = DEM_DTC_STATUS(DtcId);
                /*Status of monitors since DTC cleared*/
                if(DEM_TEST_UDS_STATUS_TNCSLC(DtcStatus))
                {
                    switch(BytePos)
                    {
                    /*Set value of monitors compleate bit.
                    0 = monitor complete (YES)
                    0 = monitor not applicable (N/A)
                    1 =  monitor not complete (NO)*/
                    case 0:
                        PID01value[1] |= ((uint8)0x10 << BitPos);
                    break;

                    default:
                        PID01value[3] |= ((uint8)0x01 << BitPos);
                    break;
                    }
                }/*if(DEM_TEST_UDS_STATUS_TNCSLC(DtcStatus))*/

                if((DEM_TEST_UDS_STATUS_CDTC(DtcStatus)) && (PID01value[0] < (uint8)0x7F))
                {
                    PID01value[0]++;
                }
            }
        }/*for(EventId = 0; EventId < DEM_NUM_OF_EVENT; EventId++)*/

        DemInternal_GetIndicatorStatus(DEM_CFG_MILINDICATORREF(ParentMemId), &IndicatorStatus);

        if(IndicatorStatus != DEM_INDICATOR_OFF)
        {
            PID01value[0] |= (uint8)0x80;
        }

        Result = E_OK;
#endif/*#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)*/
    }
    return Result;
}

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU) \
    && (DEM_CFG_OBD_CENTRALIZED_PID21_HANDLING == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetDataOfPID21
*
* Description: Service to get the value of PID $21 from the Dem by a software
*              component.
*
* Inputs: None.
*
* Outputs: PID21value: Content of PID $21 as raw hex value.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral/
*              DemGeneralOBD.DemOBDCentralizedPID21Handling)}== true)
*              && ({ecuc(Dem/DemGeneral.DemOBDSupport)} == DEM_OBD_MASTER_ECU).
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_01093*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint16 Distance;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETDATAOFPID21_APIID, DEM_E_UNINIT);
    }
    else if(PID21value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDATAOFPID21_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        PID21value[DEM_INDEX_0] = DEM_DATA_CLEAR;
        PID21value[DEM_INDEX_1] = DEM_DATA_CLEAR;
        Distance = (uint16)(DEM_OBD_DISTANCE_MILACTIVATED / DEM_DATA_1000);
        PID21value[DEM_INDEX_0] = (uint8)(Distance >> (uint16)8);
        PID21value[DEM_INDEX_1] = (uint8)Distance;
        Result = E_OK;
    }
    return Result;
}
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU) \
            && (DEM_CFG_OBD_CENTRALIZED_PID21_HANDLING == STD_ON))*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetDataOfPID21
*
* Description: Service to set the value of PID $21 in the Dem by a software
*              component.
*
* Inputs: PID21value: Buffer containing the contents of PID $21.
*
* Outputs: None.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00735*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value
)
{
    Std_ReturnType Result = E_NOT_OK;

    uint32 Distance = (uint32)0;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETDATAOFPID21_APIID, DEM_E_UNINIT);
    }
    else if(PID21value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_SETDATAOFPID21_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        Distance |= ((uint16)PID21value[DEM_INDEX_0] << (uint16)8);
        Distance |= ((uint16) PID21value[DEM_INDEX_1]);
        DEM_OBD_DISTANCE_MILACTIVATED = ((uint32)Distance) * DEM_DATA_1000;
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetDataOfPID31
*
* Description: Service to set the value of PID $31 in the Dem by a software
*              component.
*
* Inputs: PID31value: Buffer containing the contents of PID $31.
*
* Outputs: None.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00736*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID31
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID31value
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint32 Distance = (uint32)0;


    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETDATAOFPID31_APIID, DEM_E_UNINIT);
    }
    else if(PID31value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_SETDATAOFPID31_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        Distance = (((uint32)PID31value[0] << (uint32)8) | ((uint32)PID31value[1]));
        DEM_OBD_DISTANCE_SINCEDTCCLEARED = (uint32)(Distance * (uint32)DEM_DATA_1000);

        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetDataOfPID4D
*
* Description: Service to set the value of PID $4D in the Dem by a software
*              component.
*
* Inputs: PID4Dvalue: Buffer containing the contents of PID $4D.
*
* Outputs: None.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00737*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4D
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Dvalue
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint16 EngineRunTime = (uint16)0;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETDATAOFPID4D_APIID, DEM_E_UNINIT);
    }
    else if(PID4Dvalue == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_SETDATAOFPID4D_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        EngineRunTime = (((uint16)PID4Dvalue[0] << (uint16)8) | ((uint16)PID4Dvalue[1]));
        DEM_OBD_ENGINERUN_MILACTIVATED = EngineRunTime;
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetDataOfPID4E
*
* Description: Service to set the value of PID $4E in the Dem by a software
*              component.
*
* Inputs: PID4Evalue: Buffer containing the contents of PID $4E.
*
* Outputs: None.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00738*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4E
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Evalue
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint16 EngineRunTime = (uint16)0;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETDATAOFPID4E_APIID, DEM_E_UNINIT);
    }
    else if(PID4Evalue == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_SETDATAOFPID4E_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        /*Not implemented.*/
        EngineRunTime = (((uint16)PID4Evalue[0] << (uint16)8) | ((uint16)PID4Evalue[1]));
        DEM_OBD_ENGINERUN_SINCEDTCCLEARED = EngineRunTime;
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetPfcCycleQualified
*
* Description: Marks the current OBD driving cycle as having met the criteria
*              for the PFC cycle.
*
* Inputs: None
*
* Outputs: None.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00739*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetPfcCycleQualified
(
    void
)
{
    Std_ReturnType Result = E_NOT_OK;


    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETPFCCYCLEQUALIFIED_APIID, DEM_E_UNINIT);
    }
    else
    {
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
        /*Not implemented.*/
        DEM_OBD_PFC_CYCLE_STATUS = TRUE;
        Result = E_OK;
#endif
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetPfcCycleQualified
*
* Description: Returns TRUE if the criteria for the PFC cycle have been met
*              during the current OBD driving cycle.
*
* Inputs: None
*
* Outputs: isqualified: TRUE: During the current OBD driving cycle the criteria
*                             for the PFC cycle have been met.
*                       FALSE: During the current OBD driving cycle the criteria
*                              for the PFC cycle have not been met.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00740*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetPfcCycleQualified
(
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) isqualified
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETPFCCYCLEQUALIFIED_APIID, DEM_E_UNINIT);
    }
    else if(isqualified == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETPFCCYCLEQUALIFIED_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
        *isqualified = DEM_OBD_PFC_CYCLE_STATUS;
        Result = E_OK;
#endif
    }
    return Result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetB1Counter
*
* Description: Service to report the value of the B1 counter computed by the Dem.
*              API is needed in WWH-OBD relevant ECUs only.
*
* Inputs: None.
*
* Outputs: B1Counter: Buffer containing the B1 counter.
*                     The buffer is provided by the application with the size
*                     of 2 bytes.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_01169*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetB1Counter
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) B1Counter
)
{
    Std_ReturnType Result = E_NOT_OK;

    /*Not implemented.*/

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetDTR
*
* Description: Reports a DTR result with lower and upper limit. The internal
*              eventstatus serves as master whether the DTR values are forwarded
*              or ignored, also taking the DTRUpdateKind into account.
*
* Inputs: DTRId: Identification of a DTR element by assigned DTRId.
*         TestResult: Test result of DTR
*         LowerLimit: Lower limit of DTR
*         UpperLimit: Upper limit of DTR
*         Ctrlval: Control value of the DTR to support its interpretation
*                  Dem-internally.
*
* Outputs: None.
*
* Return: E_OK: Report of DTR result successful
*         E_NOT_OK: Report of DTR result failed
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00765*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTR
(
    uint16 DTRId,
    sint32 TestResult,
    sint32 LowerLimit,
    sint32 UpperLimit,
    Dem_DTRControlType Ctrlval
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_MAX_NUM_OF_DTR > 0)
    Dem_EventIdType EventId;
    boolean CompuFlag = FALSE;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETDTR_APIID, DEM_E_UNINIT);
    }
    else if(DTRId >= DEM_NUM_OF_DTR)
    {
        DEM_DET_REPORT_ERROR(DEM_SETDTR_APIID, DEM_E_PARAM_DATA);
    }
    else if((Ctrlval == DEM_DTR_CTL_RESET)\
        || (Ctrlval == DEM_DTR_CTL_INVISIBLE))
    {

    }
    else
    {
        if(DEM_CFG_DTR_EVENTREF(DTRId) != DEM_EVENT_ID_INVALID)
        {
            EventId = DEM_CFG_DTR_EVENTREF(DTRId);
            if(E_OK == DemInternal_CheckEventCondition(EventId))
            {
                if(DEM_CFG_DTR_UPDATEKIND(DTRId) == DEM_DTR_UPDATE_ALWAYS)
                {
                    CompuFlag = TRUE;
                }
                else
                {
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
                    if((DEM_CFG_EVENT_DBC(EventId) != NULL_PTR)\
                        && ((DEM_EVENT_DBC(EventId) == DEM_CFG_EVENT_DBC_FAILTHRESHOLD(EventId))\
                        || (DEM_EVENT_DBC(EventId) == DEM_CFG_EVENT_DBC_PASSTHRESHOLD(EventId))))
                    {
                        CompuFlag = TRUE;
                    }
#endif
                    /*SWS_Dem_00431*/
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
                    if((DEM_CFG_EVENT_DBT(EventId) != NULL_PTR)\
                        && (DEM_EVENT_DBT(EventId) == DEM_CFG_EVENT_DBT_FAILED(EventId))\
                        || (DEM_EVENT_DBT(EventId) == DEM_CFG_EVENT_DBT_PASSED(EventId)))
                    {
                        CompuFlag = TRUE;
                    }
#endif
                }


            }

        }
        else
        {
            if(DEM_CFG_DTR_UPDATEKIND(DTRId) == DEM_DTR_UPDATE_ALWAYS)
            {
                CompuFlag = TRUE;
            }
        }
        if(CompuFlag == TRUE)
        {
            if(Ctrlval == DEM_DTR_CTL_NORMAL)
            {
                DEM_OBD_DTR_TESTRESULT(DTRId) = ((TestResult * DEM_CFG_DTR_COMPUNUMERATOR1(DTRId)) + DEM_CFG_DTR_COMPUNUMERATOR0(DTRId)) / DEM_CFG_DTR_COMPUDENOMINATOR0(DTRId);
                DEM_OBD_DTR_LOWERLIMIT(DTRId) = ((LowerLimit * DEM_CFG_DTR_COMPUNUMERATOR1(DTRId)) + DEM_CFG_DTR_COMPUNUMERATOR0(DTRId)) / DEM_CFG_DTR_COMPUDENOMINATOR0(DTRId);
                DEM_OBD_DTR_UPPERLIMIT(DTRId) = ((UpperLimit * DEM_CFG_DTR_COMPUNUMERATOR1(DTRId)) + DEM_CFG_DTR_COMPUNUMERATOR0(DTRId)) / DEM_CFG_DTR_COMPUDENOMINATOR0(DTRId);
            }
            else if(Ctrlval == DEM_DTR_CTL_NO_MAX)
            {
                DEM_OBD_DTR_TESTRESULT(DTRId) = ((TestResult * DEM_CFG_DTR_COMPUNUMERATOR1(DTRId)) + DEM_CFG_DTR_COMPUNUMERATOR0(DTRId)) / DEM_CFG_DTR_COMPUDENOMINATOR0(DTRId);
                DEM_OBD_DTR_LOWERLIMIT(DTRId) = ((LowerLimit * DEM_CFG_DTR_COMPUNUMERATOR1(DTRId)) + DEM_CFG_DTR_COMPUNUMERATOR0(DTRId)) / DEM_CFG_DTR_COMPUDENOMINATOR0(DTRId);
            }
            else
            {
                DEM_OBD_DTR_TESTRESULT(DTRId) = ((TestResult * DEM_CFG_DTR_COMPUNUMERATOR1(DTRId)) + DEM_CFG_DTR_COMPUNUMERATOR0(DTRId)) / DEM_CFG_DTR_COMPUDENOMINATOR0(DTRId);
                DEM_OBD_DTR_UPPERLIMIT(DTRId) = ((UpperLimit * DEM_CFG_DTR_COMPUNUMERATOR1(DTRId)) + DEM_CFG_DTR_COMPUNUMERATOR0(DTRId)) / DEM_CFG_DTR_COMPUDENOMINATOR0(DTRId);
            }
        }
    }
#endif

    /*Not implemented.*/

    return Result;
}
#if(DEM_MAX_NUM_OF_DTR > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_CheckEventCondition
*
* Description:
*
* Inputs:
*
*
* Outputs: None.
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_CheckEventCondition
(
    Dem_EventIdType EventId
)
{
#if((DEM_NUM_OF_EN_GROUP > 0)||(DEM_NUM_OF_STOR_GROUP > 0))
    uint8 i;
#endif
    Std_ReturnType ret = E_OK;
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
    if(Dem_EventAvailable[EventId] == TRUE)
#endif
    {
#if(DEM_NUM_OF_EN_GROUP > 0)
        if(DEM_CFG_EVENT_EN(EventId) != NULL_PTR)
        {
            for( i = (uint8)0; i < (uint8)DEM_CFG_EVENT_EN_NUM(EventId); i++)
            {
                if(Dem_EventEnCondition[DEM_CFG_EVENT_EN_REF(EventId)[i]]== FALSE)
                {
                    ret = E_NOT_OK;
                    break;
                }
            }
        }
#endif
#if(DEM_NUM_OF_STOR_GROUP > 0)
        if((DEM_CFG_EVENT_STOR(EventId) != NULL_PTR) && (ret != E_NOT_OK))
        {
            for( i = (uint8)0; i < (uint8)DEM_CFG_EVENT_STOR_NUM(EventId); i++)
            {
                if(Dem_EventEnCondition[DEM_CFG_EVENT_STOR_REF(EventId)[i]]== FALSE)
                {
                    ret = E_NOT_OK;
                    break;
                }
            }
        }
#endif
    }
    return ret;
}
#endif
#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
*   Dem_Dcm
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
*   Dem_Dcm  static Api declaration
*******************************************************************************/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_CheckDtcValid
(
    Dem_UdsDTCType DTC,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) DtcId
);

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetSizeOfExtendedData
(
    uint16 DtcId,
    uint8 ExtendedDataNumber,
    uint8 DataEntryId,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) ExtendedDataOffset
);

#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetNextExtendedData
(
    uint8 ClientId,
    uint16 DtcId,
    uint8 DataEntryId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize

);
#endif

STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetSizeOfFFData
(
    uint8 ClientId,
    uint8 RecordNumber,
    uint8 DataEntryId,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) FFDataOffset
);

#if(DEM_MAX_FFSIZE_OF_DTC > 0)
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetNextFFData
(
    uint8 ClientId,
    uint16 DtcId,
    uint8 DataEntryId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
#endif

/*******************************************************************************
*   Dem_Dcm  static Api definition
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_CheckDtcValid
(
    Dem_UdsDTCType DTC,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) DtcId
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint16 i;

    for(i = (uint16)0; i < (uint16)DEM_NUM_OF_DTC; i++)
    {
        if(DTC == DEM_CFG_DTC_VALUE(i))
        {
            *DtcId = i;
            Result = E_OK;
            break;
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetSizeOfExtendedData
(
    uint16 DtcId,
    uint8 ExtendedDataNumber,
    uint8 DataEntryId,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) ExtendedDataOffset

)
{
    Std_ReturnType Result = E_OK;
#if(DEM_NUM_OF_EXTDATACLASS > 0)
    uint8 i;
    uint8 j;
    uint8 RecIdx;
    uint16 DataIdx;
    uint8 RecNum;
    uint8 DataSize;
    uint8 *DataBufferPtr;
    uint16 RecDataSize;
    uint16 InvalidDataLength;
#endif
    if(DataEntryId == DEM_DATA_INVALID_U8)
    {
        *SizeOfExtendedDataRecord = (uint16)0;
        Result = DEM_NO_SUCH_ELEMENT;
#if(DEM_NUM_OF_EXTDATACLASS > 0)
        for(i = 0U; i < DEM_CFG_DTC_NUM_OF_EXTREC(DtcId); i++)
        {
            RecIdx = (DEM_CFG_DTC_EXTREC_ARRAY(DtcId)[i]);
            RecNum = DEM_CFG_DTC_EXTRECNUM(RecIdx);
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
            if(((ExtendedDataNumber == DEM_RECORED_NUMBER_FF) || (RecNum == ExtendedDataNumber)) \
                && (RecNum == DEM_FDC_10))
            {
                *SizeOfExtendedDataRecord = DEM_UINT16_2;
            }
#endif
            if(RecNum == ExtendedDataNumber)
            {
                Result = E_OK;
                break;
            }
        }

        if(ExtendedDataNumber == DEM_RECORED_NUMBER_FF)
        {
            Result = E_OK;
        }
#endif/*#if(DEM_NUM_OF_EXTDATACLASS > 0U)*/
    }
    else
    {
#if(DEM_NUM_OF_EXTDATACLASS > 0)
        *SizeOfExtendedDataRecord = 0U;
        *ExtendedDataOffset = 0U;
        InvalidDataLength = 0U;
#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
        if(DEM_GET_SUBMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId))== DEM_PRIMARY_MEMORY)
        {
            DataBufferPtr = DEM_PRIMARY_EXTDATA_PTR(DEM_GET_EVENTMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId)), DataEntryId);
        }
#if(DEM_NUM_OF_USERDEF > 0)
        else
        {
            DataBufferPtr = DEM_USERDEFINED_EXTDATA_PTR(DEM_GET_SUBMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId)), DataEntryId);
        }
#endif

        for(i = (uint8)0; i < DEM_CFG_DTC_NUM_OF_EXTREC(DtcId); i++)
        {
            RecIdx = (DEM_CFG_DTC_EXTREC_ARRAY(DtcId)[i]);
            RecNum = DEM_CFG_DTC_EXTRECNUM(RecIdx);
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
            if(RecNum == DEM_FDC_10)
            {
                *(DataBufferPtr + (*ExtendedDataOffset) + (*SizeOfExtendedDataRecord)) = DEM_FDC_10;
            }
#endif
            if(RecNum == ExtendedDataNumber)
            {
                if(*(DataBufferPtr + (*ExtendedDataOffset)) != DEM_DATA_INVALID_U8)
                {
                    /*+ RecNum length(one byte)*/

                    (*SizeOfExtendedDataRecord)++;

                    for(j =(uint8)0; j < DEM_CFG_NUMDATA_OF_EXTRECNUM(RecIdx); j++)
                    {
                        DataIdx = (DEM_CFG_DATAARRAY_OF_EXTRECNUM(RecIdx)[j]);
                        if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                        {
                            DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                            /*SWS_Dem_00817*/
                            DemInternal_GetDtcInternalData(DtcId, DataIdx, (DataBufferPtr + (*ExtendedDataOffset) + (*SizeOfExtendedDataRecord)));
                            *SizeOfExtendedDataRecord += (uint16)DataSize;
                        }

                        if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                        {
                            DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                            *SizeOfExtendedDataRecord += (uint16)DataSize;
                        }
                    }
                }
                break;
            }
            else
            {
                /*+ RecNum length(one byte)*/
                RecDataSize = (uint16)1;

                for(j = (uint8)0; j < DEM_CFG_NUMDATA_OF_EXTRECNUM(RecIdx); j++)
                {
                    DataIdx = (DEM_CFG_DATAARRAY_OF_EXTRECNUM(RecIdx)[j]);
                    if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                    {
                        DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                        /*SWS_Dem_00817*/
                        DemInternal_GetDtcInternalData(DtcId, DataIdx, (DataBufferPtr + (*ExtendedDataOffset) + RecDataSize));
                        RecDataSize += (uint16)DataSize;
                    }

                    if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                    {
                        DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                        RecDataSize += (uint16)DataSize;
                    }
                }

                if(*(DataBufferPtr + (*ExtendedDataOffset)) == DEM_DATA_INVALID_U8)
                {
                    InvalidDataLength += RecDataSize;
                }
                (*ExtendedDataOffset) += RecDataSize;
            }
        }
#endif
        if(ExtendedDataNumber == DEM_RECORED_NUMBER_FF)
        {
            *SizeOfExtendedDataRecord = (*ExtendedDataOffset - InvalidDataLength);
        }
        else if(i == DEM_CFG_DTC_NUM_OF_EXTREC(DtcId))
        {
            Result = DEM_NO_SUCH_ELEMENT;
        }
        else
        {
            /*do nothing*/
        }
#else
        Result = DEM_WRONG_DTC;
#endif
    }
    return Result;
}

#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetNextExtendedData
(
    uint8 ClientId,
    uint16 DtcId,
    uint8 DataEntryId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType Result = E_OK;
    uint8 i;
    uint8 j;
    uint8 RecIdx;
    uint16 DataIdx;
    uint8 DataSize;
    uint8 *SrcBufferPtr;
    uint8 RecNum = (uint8)0;
    uint16 SizeOfExRecData = (uint16)0;
    uint16 SumSizeOfExRecData = (uint16)0;
    uint8 MemId = DEM_CLIENT_EVENT_MEM(ClientId);
    uint16 DTC_MemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId);
    uint8 DTC_SubMemId = DEM_GET_SUBMEMORY_ID(DTC_MemId);

	if(DTC_SubMemId == DEM_PRIMARY_MEMORY)
	{
		SrcBufferPtr = DEM_PRIMARY_EXTDATA_PTR(MemId,DataEntryId);
	}
#if(DEM_NUM_OF_USERDEF > 0)
	else
	{
		SrcBufferPtr = DEM_USERDEFINED_EXTDATA_PTR(DTC_SubMemId, DataEntryId);
	}
#endif

    for(i = Dem_SelectDTC_ExDataNumIndex[ClientId]; i < DEM_CFG_DTC_NUM_OF_EXTREC(DtcId); i++)
    {
        RecIdx = (DEM_CFG_DTC_EXTREC_ARRAY(DtcId)[i]);
        RecNum = DEM_CFG_DTC_EXTRECNUM(RecIdx);
        if((*SrcBufferPtr != DEM_DATA_INVALID_U8) \
            && ((RecNum == Dem_SelectDTC_ExtendedDataNumber[ClientId]) \
            || (Dem_SelectDTC_ExtendedDataNumber[ClientId] == DEM_RECORED_NUMBER_FF)))
        {
            /*RecNum(one byte)*/
            SizeOfExRecData ++;
            for(j = (uint8)0; j < DEM_CFG_NUMDATA_OF_EXTRECNUM(RecIdx); j++)
            {
                DataIdx = (DEM_CFG_DATAARRAY_OF_EXTRECNUM(RecIdx)[j]);
                if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                {
                    DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                    SizeOfExRecData += (uint16)DataSize;
                }

                if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                {
                    DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                    SizeOfExRecData += (uint16)DataSize;
                }
            }
            SumSizeOfExRecData += SizeOfExRecData;
            if(*BufSize >= SumSizeOfExRecData)
            {
                Bsw_MemCpy(DestBuffer, SrcBufferPtr, (uint32)SizeOfExRecData);
                DestBuffer += SizeOfExRecData;
                SrcBufferPtr += SizeOfExRecData;
                SizeOfExRecData = (uint16)0;
            }
            else
            {
                Result = DEM_BUFFER_TOO_SMALL;
                break;
            }
        }
        else
        {
            /*RecNum(one byte)*/
            SrcBufferPtr++;

            for(j = (uint8)0; j < DEM_CFG_NUMDATA_OF_EXTRECNUM(RecIdx); j++)
            {
                DataIdx = (DEM_CFG_DATAARRAY_OF_EXTRECNUM(RecIdx)[j]);
                if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                {
                    DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                    SrcBufferPtr += DataSize;
                }

                if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                {
                    DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                    SrcBufferPtr += DataSize;
                }
            }
        }
    }

    if(Result == DEM_BUFFER_TOO_SMALL)
    {
        Dem_SelectDTC_ExDataNumIndex[ClientId] = (uint8)0;
    }
    else if(SumSizeOfExRecData == (uint16)0)
    {
        Result = DEM_NO_SUCH_ELEMENT;
        Dem_SelectDTC_ExDataNumIndex[ClientId] = (uint8)0;
    }
    else
    {
        Dem_SelectDTC_ExDataNumIndex[ClientId] = i;
        *BufSize = SumSizeOfExRecData;
    }
    return Result;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetSizeOfFFData
(
    uint8 ClientId,
    uint8 RecordNumber,
    uint8 DataEntryId,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) FFDataOffset
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_NUM_OF_FFRECCLASS > 0)
    uint8 i;
    uint8 j;
    uint8 k;
    uint8 RecIdx;
    uint8 DidIdx;
    uint16 DataIdx;
    uint8 RecNum = (uint8)0;
    uint8 DataSize;
    uint8 *DataBufferPtr;
    uint16 RecDataSize;
    uint16 InvalidDataLength;
#endif
    if(DataEntryId == DEM_DATA_INVALID_U8)
    {
        *SizeOfFreezeFrame = (uint16)0;
        Result = DEM_NO_SUCH_ELEMENT;
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
#if(DEM_NUM_OF_FFRECCLASS > 0)
        for(i = (uint8)0; i < DEM_CFG_DTC_NUM_OF_FFREC(Dem_SelectDTC_Index[ClientId]); i++)
        {
	        RecIdx = (DEM_CFG_DTC_FFREC_ARRAY(Dem_SelectDTC_Index[ClientId])[i]);
	        if(Dem_SelectDTC_SubMem[ClientId] == DEM_PRIMARY_MEMORY)
	        {
	            if(DEM_CFG_PRIMARY_TYPE_OF_FF_RECORD_NUMERATION(Dem_SelectDTC_ParentMem[ClientId]) == DEM_FF_RECNUM_CONFIGURED)
	            {
	                /*SWS_Dem_00582*/
	                RecNum = DEM_CFG_DTC_FFRECNUM(RecIdx);
	            }
	            else
	            {
	                /*SWS_Dem_00337*//*SWS_Dem_00581*/
	                RecNum++;

	            }
	        }

            if(RecNum == RecordNumber)
            {
                Result = E_OK;
                break;
            }
        }

        if(RecordNumber == DEM_RECORED_NUMBER_FF)
        {
            Result = E_OK;
        }
#endif/*#if(DEM_NUM_OF_FFRECCLASS > 0U)*/
    }
    else
    {
#if(DEM_NUM_OF_FFRECCLASS > 0)

        *SizeOfFreezeFrame = (uint16)0;
        *FFDataOffset = (uint16)0;
        InvalidDataLength = (uint16)0;
        if(Dem_SelectDTC_SubMem[ClientId] == DEM_PRIMARY_MEMORY)
        {
            DataBufferPtr = DEM_PRIMARY_FFDATA_PTR(Dem_SelectDTC_ParentMem[ClientId], DataEntryId);
        }
#if(DEM_NUM_OF_USERDEF > 0)
        else
        {
            DataBufferPtr = DEM_USERDEFINED_FFDATA_PTR(Dem_SelectDTC_SubMem[ClientId], DataEntryId);
        }
#endif

        for(i = (uint8)0; i < DEM_CFG_DTC_NUM_OF_FFREC(Dem_SelectDTC_Index[ClientId]); i++)
        {
            RecIdx = (DEM_CFG_DTC_FFREC_ARRAY(Dem_SelectDTC_Index[ClientId])[i]);
            if(Dem_SelectDTC_SubMem[ClientId] == DEM_PRIMARY_MEMORY)
            {
                if(DEM_CFG_PRIMARY_TYPE_OF_FF_RECORD_NUMERATION(Dem_SelectDTC_ParentMem[ClientId]) == DEM_FF_RECNUM_CONFIGURED)
                {
                    /*SWS_Dem_00582*/
                    RecNum = DEM_CFG_DTC_FFRECNUM(RecIdx);
                }
                else
                {
                    /*SWS_Dem_00337*//*SWS_Dem_00581*/
                    RecNum++;
                }
            }
            if(RecNum == RecordNumber)
            {
                if(*(DataBufferPtr + (*FFDataOffset)) != DEM_DATA_INVALID_U8)
                {
                    /*+ RecNum length(one byte) + RecordNumberOfIdentifiers length(one byte)*/
                    *SizeOfFreezeFrame += (uint16)DEM_DATA_LENGTH_2;

                    for(j = (uint8)0; j < DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx); j++)
                    {
                        /*Did length(two bytes)*/
                        *SizeOfFreezeFrame += (uint16)DEM_DATA_LENGTH_2;

                        DidIdx = (DEM_CFG_DIDARRAY_OF_FFRECNUM(RecIdx)[j]);
                        for(k = (uint8)0; k < DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                        {
                            DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);
                            if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                            {
                                DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                                /*SWS_Dem_00817*/
                                DemInternal_GetDtcInternalData(Dem_SelectDTC_Index[ClientId], DataIdx, (DataBufferPtr + (*FFDataOffset) + (*SizeOfFreezeFrame)));
                                *SizeOfFreezeFrame += (uint16)DataSize;
                            }

                            if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                            {
                                DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                                *SizeOfFreezeFrame += (uint16)DataSize;
                            }
                        }
                    }
                }
                break;
            }
            else
            {
                /*+ RecNum length(one byte) + RecordNumberOfIdentifiers length(one byte)*/
                RecDataSize = (uint16)DEM_DATA_LENGTH_2;

                for(j = (uint8)0; j < DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx); j++)
                {
                    /*Did length(two bytes)*/
                    RecDataSize += (uint16)DEM_DATA_LENGTH_2;

                    DidIdx = (DEM_CFG_DIDARRAY_OF_FFRECNUM(RecIdx)[j]);
                    for(k = (uint8)0; k < DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                    {
                        DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);
                        if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                        {
                            DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                            /*SWS_Dem_00817*/
                            DemInternal_GetDtcInternalData(Dem_SelectDTC_Index[ClientId], DataIdx, (DataBufferPtr + (*FFDataOffset) + RecDataSize));
                            RecDataSize += (uint16)DataSize;
                        }

                        if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                        {
                            DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                            RecDataSize += (uint16)DataSize;
                        }
                    }
                }

                if(*(DataBufferPtr + (*FFDataOffset)) == DEM_DATA_INVALID_U8)
                {
                    InvalidDataLength += RecDataSize;
                }
                (*FFDataOffset) += RecDataSize;
            }
        }

        if(RecordNumber == DEM_RECORED_NUMBER_FF)
        {
            *SizeOfFreezeFrame = (*FFDataOffset - InvalidDataLength);
        }
        else if(i == DEM_CFG_DTC_NUM_OF_FFREC(Dem_SelectDTC_Index[ClientId]))
        {
            Result = DEM_NO_SUCH_ELEMENT;
        }
        else
        {
            /*do nothing*/
        }
#endif
#else
        Result = DEM_NO_SUCH_ELEMENT;
#endif
    }
    return Result;
}

#if(DEM_MAX_FFSIZE_OF_DTC > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetNextFFData
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetNextFFData
(
    uint8 ClientId,
    uint16 DtcId,
    uint8 DataEntryId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType Result = E_OK;
    uint8 i;
    uint8 j;
    uint8 k;
    uint8 RecIdx;
    uint8 DidIdx;
    uint16 DataIdx;
    uint8 DataSize = (uint8)0;
    uint16 SizeOfFFData = (uint16)0;
    uint16 SumSizeOfFFData = (uint16)0;
    uint8 *SrcBufferPtr;
    uint8 RecNum = (uint8)0;
    if(Dem_SelectDTC_SubMem[ClientId] == DEM_PRIMARY_MEMORY)
    {
        SrcBufferPtr = DEM_PRIMARY_FFDATA_PTR(Dem_SelectDTC_ParentMem[ClientId],DataEntryId);
    }
#if(DEM_NUM_OF_USERDEF > 0)
    else
    {
        SrcBufferPtr = DEM_USERDEFINED_FFDATA_PTR(Dem_SelectDTC_SubMem[ClientId],DataEntryId);
    }
#endif

    for(i = Dem_SelectDTC_FFRecIndex[ClientId]; i < DEM_CFG_DTC_NUM_OF_FFREC(DtcId); i++)
    {
        RecIdx = (DEM_CFG_DTC_FFREC_ARRAY(DtcId)[i]);
        if(Dem_SelectDTC_SubMem[ClientId] == DEM_PRIMARY_MEMORY)
        {
            if(DEM_CFG_PRIMARY_TYPE_OF_FF_RECORD_NUMERATION(Dem_SelectDTC_ParentMem[ClientId]) == DEM_FF_RECNUM_CONFIGURED)
            {
                /*SWS_Dem_00582*/
                RecNum = DEM_CFG_DTC_FFRECNUM(RecIdx);
            }
            else
            {
                /*SWS_Dem_00337*//*SWS_Dem_00581*/
                RecNum++;
            }
        }
        if((*SrcBufferPtr != DEM_DATA_INVALID_U8)\
            && ((RecNum == Dem_SelectDTC_RecordNumber[ClientId]) \
            || (Dem_SelectDTC_RecordNumber[ClientId] == DEM_RECORED_NUMBER_FF)))
        {
            /*+ RecNum(one byte) + RecordNumberOfIdentifiers(one byte)*/
            SizeOfFFData += (uint16)DEM_DATA_LENGTH_2;
            for(j = (uint8)0; j < DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx); j++)
            {
                SizeOfFFData += (uint16)DEM_DATA_LENGTH_2;

                DidIdx = (DEM_CFG_DIDARRAY_OF_FFRECNUM(RecIdx)[j]);
                for(k = (uint8)0; k < DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                {
                    DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);
                    if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                    {
                        DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                        SizeOfFFData += (uint16)DataSize;
                    }

                    if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                    {
                        DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                        SizeOfFFData += (uint16)DataSize;
                    }
                }

            }
            SumSizeOfFFData += SizeOfFFData;
            if(*BufSize >= SumSizeOfFFData)
            {
                Bsw_MemCpy(DestBuffer, SrcBufferPtr, (uint32)SizeOfFFData);
                DestBuffer += SizeOfFFData;
                SrcBufferPtr += SizeOfFFData;
                SizeOfFFData = (uint16)0;
            }
            else
            {
                Result = DEM_BUFFER_TOO_SMALL;
                break;
            }
        }
        else
        {
            /*+ RecNum(one byte) + RecordNumberOfIdentifiers(one byte)*/
            SrcBufferPtr += DEM_DATA_LENGTH_2;

            for(j = (uint8)0; j < DEM_CFG_NUMDID_OF_FFRECNUM(RecIdx); j++)
            {
                /*Did(two bytes)*/
                SrcBufferPtr += DEM_DATA_LENGTH_2;

                DidIdx = (DEM_CFG_DIDARRAY_OF_FFRECNUM(RecIdx)[j]);
                for(k = (uint8)0; k < DEM_CFG_NUMDATA_OF_DID(DidIdx); k++)
                {
                    DataIdx = (DEM_CFG_DATAARRAY_OF_DID(DidIdx)[k]);
                    if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
                    {
                        DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
                        SrcBufferPtr += DataSize;
                    }

                    if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
                    {
                        DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
                        SrcBufferPtr += DataSize;
                    }
                }
            }
        }

    }
    if(Result == DEM_BUFFER_TOO_SMALL)
    {
        Dem_SelectDTC_FFRecIndex[ClientId] = (uint8)0;
    }
    else if(SumSizeOfFFData == (uint16)0)
    {
        Result = DEM_NO_SUCH_ELEMENT;
        Dem_SelectDTC_FFRecIndex[ClientId] = (uint8)0;
    }
    else
    {
        Dem_SelectDTC_FFRecIndex[ClientId] = i;
        *BufSize = SumSizeOfFFData;
    }
    return Result;
}
#endif

/*******************************************************************************
*   Dem_Dcm Api definition
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetTranslationType
*
* Description: Gets the supported DTC formats of the ECU. The supported formats are
*                  configured via DemTypeOfDTCSupported.
*
* Inputs: None
*
* Outputs: None
*
* Return: Dem_DTCTranslationFormatType: Returns the configured DTC translation format.
*                         A combination of different DTC formats is not possible.
*
* Limitations: Synchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Dem_DTCTranslationFormatType, DEM_CODE) Dem_GetTranslationType
(
    uint8 ClientId
)
{
    uint8 EventMemId;
    Dem_DTCTranslationFormatType DtcFormat = DEM_DTC_TRANSLATION_ISO14229_1;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        DEM_DET_REPORT_ERROR(DEM_GETTRANSLATIONTYPE_APIID, DEM_E_UNINIT);
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if(ClientId >= DEM_NUM_OF_CLIENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETTRANSLATIONTYPE_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
        EventMemId = DEM_CLIENT_EVENT_MEM(ClientId);
        /*SWS_Dem_00231*/
        DtcFormat = DEM_CFG_EVENT_TRANSLATION_TYPE(EventMemId);
    }
    return DtcFormat;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetDTCStatusAvailabilityMask
*
* Description: Gets the DTC Status availability mask.
*
* Inputs: None
*
* Outputs: DTCStatusMask: The value DTCStatusMask indicates the supported DTC status bits
*                                     from the Dem. All supported information is indicated by setting the
*                                     corresponding status bit to 1. See ISO14229-1.
*
* Return: Std_ReturnType: E_OK: get of DTC status mask was successful
*                                    E_NOT_OK: get of DTC status mask failed
*
* Limitations: Synchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCStatusAvailabilityMask
(
    uint8 ClientId,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatusMask,
    Dem_DTCOriginType DTCOrigin
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_NUM_OF_USERDEF > 0)
    uint8 UserdefMemId;
#endif
    uint16 EventMemId;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDTCSTATUSAVAILABILITYMASK_APIID, DEM_E_UNINIT);
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if(DTCStatusMask == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDTCSTATUSAVAILABILITYMASK_APIID, DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
    else if(ClientId >= DEM_NUM_OF_CLIENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDTCSTATUSAVAILABILITYMASK_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
    else
    {
        EventMemId = DEM_CLIENT_EVENT_MEM(ClientId);
        /*SWS_Dem_00060*/
        if(DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
        {
            *DTCStatusMask = DEM_CFG_DTCSTATU_MASK_PRIMARY(EventMemId);
        }
#if(DEM_NUM_OF_USERDEF > 0)
        else if((DTCOrigin & DEM_DTC_ORIGIN_USERDEFINED_MEMORY_XX) != 0)
        {
            UserdefMemId = DEM_GET_SUBMEMORY_ID(DTCOrigin);
            if(UserdefMemId >= (uint8)DEM_NUM_OF_USERDEF)
            {
                DEM_DET_REPORT_ERROR(DEM_GETDTCSTATUSAVAILABILITYMASK_APIID, DEM_E_PARAM_DATA);
                Result = E_NOT_OK;
            }
            else
            {

                *DTCStatusMask = DEM_CFG_DTCSTATU_MASK_USERDEFINED(UserdefMemId);
            }
        }
#endif
        else
        {
            Result = E_NOT_OK;
        }

    }
    return Result;
}

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetDTCSeverityAvailabilityMask
*
* Description: Gets the DTC Severity availability mask.
*
* Inputs: ClientId
*
* Outputs: DTCSeverityMask: The value DTCSeverityMask indicates the supported DTC severity bits
*                                     from the Dem. All supported information is indicated by setting the
*                                     corresponding severity bit to 1. See ISO14229-1.
*
* Return: Std_ReturnType: E_OK: get of DTC severity mask was successful
*                                    E_NOT_OK: get of DTC severity mask failed
*
* Limitations: Synchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCSeverityAvailabilityMask
(
    uint8 ClientId,
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverityMask
)
{
    Std_ReturnType Result = E_OK;
    uint16 i ;
    uint8 UserdefMemId;
    uint16 EventMemId;
    Dem_DTCSeverityType Severity = 0;

#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDTCSEVERITYAVAILABILITYMASK_APIID , DEM_E_UNINIT);
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if(DTCSeverityMask == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDTCSEVERITYAVAILABILITYMASK_APIID , DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
    else if(ClientId >= DEM_NUM_OF_CLIENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDTCSEVERITYAVAILABILITYMASK_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
    else
    {
        /*SWS_Dem_01177*/
        EventMemId = DEM_CLIENT_EVENT_MEM(ClientId);
        /*SWS_Dem_00060*/
        for(i = (uint16)0 ; i < DEM_NUM_OF_DTC; i++)
        {
            UserdefMemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(i) >> (uint16)8;
            if((DEM_CFG_DTC_OBDDTCREF(i) != NULL_PTR) && (UserdefMemId == EventMemId))
            {
                /*SWS_Dem_01181*/
                Severity |= DEM_CFG_DTC_SEVERITY(i);
                Severity |= DEM_CFG_DTC_OBDDTCCLASS(i);
            }
        }
        *DTCSeverityMask = Severity;
    }
    return Result;
}
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetStatusOfDTC
*
* Description: Gets the status of a DTC. The DTCs of OBD Events Suppression shall be
*                  reported as DEM_STATUS_WRONG_DTC.
*
* Inputs: DTC: Diagnostic Trouble Code in UDS format.
*            DTCOrigin: If the Dem supports more than one event memory this parameter is used
*                           to select the source memory the DTCs shall be read from.
*
* Outputs: DTCStatus: This parameter receives the status information of the requested DTC.
*                              If the return value of the function call is other than DEM_STATUS_OK
*                              this parameter does not contain valid data. 0x00...0xFF match
*                              DTCStatusMask as defined in ISO14229-1
*
* Return: Dem_ReturnGetStatusOfDTCType: Status of the operation
*
* Limitations: Synchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetStatusOfDTC
(
    uint8 ClientId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint8  EventMemId;
#if(DEM_NUM_OF_USERDEF > 0)
    uint8 UserdefMemId;
#endif
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
    uint8 Index;
    Dem_EventIdType EventId;
#endif

#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETSTATUSOFDTC_APIID, DEM_E_UNINIT);
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PROCESSING)
    {
        Result = DEM_BUSY;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_CHECKING)\
        ||(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PENDING))
    {
        Result = DEM_PENDING;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_WRONG_DTC)\
        ||(Dem_SelectDTCState[ClientId] == DEM_WRONG_DTCORIGIN))
    {
        Result = (Std_ReturnType)Dem_SelectDTCState[ClientId];
    }
    else if(Dem_DTCIsSelected[ClientId] != TRUE)
    {
        /*No DTC selected*/
        DEM_DET_REPORT_ERROR(DEM_GETSTATUSOFDTC_APIID, DEM_E_WRONG_CONDITION);
    }
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
    else if(Dem_DTCSuppressionState[Dem_SelectDTC_Index[ClientId]] == TRUE)
    {
        /*SWS_Dem_01100*/
        Result = DEM_WRONG_DTC;
    }
#endif
    else
    {
        EventMemId = DEM_CLIENT_EVENT_MEM(ClientId);
        /*SWS_Dem_00059*/
        if(Dem_SelectDTC_DTCOrigin[ClientId] == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
        {
            *DTCStatus = (uint8)((DEM_DTC_STATUS(Dem_SelectDTC_Index[ClientId])) & (DEM_CFG_DTCSTATU_MASK_PRIMARY(EventMemId)));
            Result = E_OK;
        }
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
        else if(Dem_SelectDTC_DTCOrigin[ClientId] == DEM_DTC_ORIGIN_PERMANENT_MEMORY)
        {
            for(Index = (uint8)0; Index < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT(EventMemId); Index++)
            {
                EventId = DEM_PERMANENT_DATAENTRY_EVENTID(EventMemId, Index);

                if((EventId != DEM_EVENT_ID_INVALID) \
                    && (Dem_SelectDTC_Index[ClientId] == DEM_CFG_EVENT_DTCREF(EventId)))
                {
                    *DTCStatus = (uint8)((DEM_DTC_STATUS(Dem_SelectDTC_Index[ClientId])) & (DEM_CFG_DTCSTATU_MASK_PRIMARY(EventMemId)));
                    break;
                }
            }

            if(Index == DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT(EventMemId))
            {
                Result = DEM_WRONG_DTCORIGIN;
            }
        }
#endif
#if(DEM_NUM_OF_USERDEF > 0)
        else if((Dem_SelectDTC_DTCOrigin[ClientId] & DEM_DTC_ORIGIN_USERDEFINED_MEMORY_XX) != (Dem_DTCOriginType)0)
        {
            UserdefMemId = DEM_GET_SUBMEMORY_ID(Dem_SelectDTC_DTCOrigin[ClientId]);
            if(UserdefMemId >= (uint8)DEM_NUM_OF_USERDEF)
            {
                DEM_DET_REPORT_ERROR(DEM_GETSTATUSOFDTC_APIID, DEM_E_PARAM_DATA);
            }
            else
            {
                *DTCStatus = (uint8)((DEM_DTC_STATUS(Dem_SelectDTC_Index[ClientId])) & (DEM_CFG_DTCSTATU_MASK_USERDEFINED(UserdefMemId)));
                Result = E_OK;
            }
        }
#endif
        else
        {
            Result = DEM_WRONG_DTCORIGIN;
        }
    }

    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetSeverityOfDTC
*
* Description: Gets the severity of the requested DTC.
*
* Inputs: DTC: Diagnostic Trouble Code in UDS format.
*
* Outputs: DTCSeverity: This parameter contains the DTCSeverity according to ISO 14229-1.
*
* Return: Dem_ReturnGetSeverityOfDTCType: Status of the operation
*
* Limitations: Synchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetSeverityOfDTC
(
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity,
    uint8 ClientId
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETSEVERITYOFDTC_APIID, DEM_E_UNINIT);
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if(DTCSeverity == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETSEVERITYOFDTC_APIID, DEM_E_PARAM_POINTER);
        Result = DEM_SEVERITY_NO_SEVERITY;
    }
    else if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PROCESSING)
    {
        Result = DEM_BUSY;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_CHECKING)\
        ||(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PENDING))
    {
        Result = DEM_PENDING;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_WRONG_DTC)\
        ||(Dem_SelectDTCState[ClientId] == DEM_WRONG_DTCORIGIN))
    {
        Result = (Std_ReturnType)Dem_SelectDTCState[ClientId];
    }
    else if(Dem_DTCIsSelected[ClientId] != TRUE)
    {
        /*No DTC selected*/
        DEM_DET_REPORT_ERROR(DEM_GETSEVERITYOFDTC_APIID, DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
    else if(Dem_DTCSuppressionState[Dem_SelectDTC_Index[ClientId]] == TRUE)
    {
        /*SWS_Dem_01100*/
        Result = DEM_WRONG_DTC;
    }
#endif
    else
    {
        /*SWS_Dem_01291*//*SWS_Dem_01292*/
        *DTCSeverity = DEM_CFG_DTC_SEVERITY(Dem_SelectDTC_Index[ClientId]);
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetFunctionalUnitOfDTC
*
* Description: Gets the functional unit of the requested DTC.
*
* Inputs: DTC: Diagnostic Trouble Code in UDS format.
*
* Outputs: DTCFunctionalUnit: Functional unit value of this DTC
*
* Return: Dem_ReturnGetFunctionalUnitOfDTCType: Status of the operation
*
* Limitations: Synchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetFunctionalUnitOfDTC
(
    uint8 ClientId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit
)
{
    Std_ReturnType Result = E_NOT_OK;

#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETFUNCTIONALUNITOFDTC_APIID, DEM_E_UNINIT);
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if(DTCFunctionalUnit == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETFUNCTIONALUNITOFDTC_APIID, DEM_E_PARAM_POINTER);
        /*SWS_Dem_00172*/
        Result = DEM_WRONG_DTC;
    }
    else if(Dem_DTCIsSelected[ClientId] != TRUE)
    {
        DEM_DET_REPORT_ERROR(DEM_GETFUNCTIONALUNITOFDTC_APIID, DEM_E_WRONG_CONDITION);
       /*No DTC selected*/
    }
    else if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PROCESSING)
    {
        Result = DEM_BUSY;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_CHECKING)\
        ||(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PENDING))
    {
        Result = DEM_PENDING;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_WRONG_DTC)\
        ||(Dem_SelectDTCState[ClientId] == DEM_WRONG_DTCORIGIN))
    {
        Result = (Std_ReturnType)Dem_SelectDTCState[ClientId];
    }
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
    else if(Dem_DTCSuppressionState[Dem_SelectDTC_Index[ClientId]] == TRUE)
    {
        /*SWS_Dem_01100*/
        Result = DEM_WRONG_DTC;
    }
#endif
    else
    {
        *DTCFunctionalUnit = DEM_CFG_DTC_FNCUNIT(Dem_SelectDTC_Index[ClientId]);
        Result = E_OK;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmSetDTCFilter
*
* Description: Sets the DTC Filter.
*
* Inputs: DTCStatusMask: Status-byte mask for DTC status-byte filtering
*         DTCKind: Defines the functional group of DTCs to be reported
*         DTCFormat: Defines the output-format of the requested DTC values for the sub-sequent API calls.
*         DTCOrigin: If the Dem supports more than one event memory this parameter is used
*                    to select the source memory the DTCs shall be read from.
*         FilterWithSeverity: This flag defines whether severity information shall be used for filtering.
*         DTCSeverityMask: This parameter contains the DTCSeverityMask according to ISO14229-1
*         FilterForFaultDetectionCounter: This flag defines whether the fault detection counter
*                                         information shall be used for filtering.
*
* Outputs: None
*
* Return: Std_ReturnType: Status of the operation to (re-)set a DTC filter.
*
* Limitations: Synchronous & Non Reentrant
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTCFilter
(
    uint8 ClientId,
    Dem_UdsStatusByteType DTCStatusMask,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin,
    boolean FilterWithSeverity,
    Dem_DTCSeverityType DTCSeverityMask,
    boolean FilterForFaultDetectionCounter/*no use*/
)
{

    uint8 StatusFilterMask;
    uint8 EventMemId;
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
    uint8 Index;
    uint16 DtcId;
#endif
    Std_ReturnType Result = E_OK;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETDTCFILTER_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if((DTCFormat != DEM_DTC_FORMAT_UDS) \
        && (DTCFormat != DEM_DTC_FORMAT_OBD) \
        && (DTCFormat != DEM_DTC_FORMAT_J1939))
    {
        /*SWS_Dem_01066*/
        DEM_DET_REPORT_ERROR(DEM_SETDTCFILTER_APIID, DEM_E_WRONG_CONFIGURATION);
        Result = E_NOT_OK;
    }
    else if((DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY) \
        && (DTCOrigin != DEM_DTC_ORIGIN_PERMANENT_MEMORY)\
        && (DTCOrigin != DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY) \
        && ((DTCOrigin & DEM_DTC_ORIGIN_USERDEFINED_MEMORY_XX) == (Dem_DTCOriginType)0))

    {
        /*SWS_Dem_01067*/
        DEM_DET_REPORT_ERROR(DEM_SETDTCFILTER_APIID, DEM_E_WRONG_CONFIGURATION);
        Result = E_NOT_OK;
    }
    else
    {
        /*SWS_Dem_00057*//*SWS_Dem_00649*/
        Dem_DcmFilterInfo[ClientId].DTCStatusMask = DTCStatusMask;
        Dem_DcmFilterInfo[ClientId].DTCFormat = DTCFormat;
        Dem_DcmFilterInfo[ClientId].DTCOrigin = DTCOrigin;
        Dem_DcmFilterInfo[ClientId].FilterWithSeverity = FilterWithSeverity;
        Dem_DcmFilterInfo[ClientId].DTCSeverityMask = DTCSeverityMask;
        /*If fault detection counter information is filter criteria, only those DTCs with a
        fault detection counter value between 1 and 0x7E shall be reported.*/
        /*But for geely, FDC value between -128 and 127 shall be reported.*/
        Dem_DcmFilterInfo[ClientId].FilterForFDC = FilterForFaultDetectionCounter;
        Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC = (uint16)0;
        Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex = (uint16)0;
        Dem_DcmFilterInfo[ClientId].FilterProcess = DEM_FILTER_PROCESSING;
        /*SWS_Dem_00657*//*SWS_Dem_01058*/
        EventMemId = DEM_CLIENT_EVENT_MEM(ClientId);

        if(DTCOrigin == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
        {
            StatusFilterMask = (uint8)(DTCStatusMask & DEM_CFG_DTCSTATU_MASK_PRIMARY(EventMemId));
            DemInternal_SetDTCFilter(ClientId,StatusFilterMask,EventMemId,DEM_PRIMARY_MEMORY);
        }
#if(DEM_NUM_OF_USERDEF > 0)
        else if((DTCOrigin & DEM_DTC_ORIGIN_USERDEFINED_MEMORY_XX) != (Dem_DTCOriginType)0)
        {
            if(DEM_GET_SUBMEMORY_ID(DTCOrigin) < (uint8)DEM_NUM_OF_USERDEF)
            {
                StatusFilterMask = (uint8)(DTCStatusMask & DEM_CFG_DTCSTATU_MASK_USERDEFINED(DEM_GET_SUBMEMORY_ID(DTCOrigin)));
                DemInternal_SetDTCFilter(ClientId,StatusFilterMask,EventMemId, DEM_GET_SUBMEMORY_ID(DTCOrigin));
            }
            else
            {
                Result = E_NOT_OK;
            }
        }
#endif
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
        else if(DTCOrigin == DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY)
        {
            StatusFilterMask = (DTCStatusMask & DEM_CFG_DTCSTATU_MASK_PRIMARY(EventMemId));
            DemInternal_SetDTCFilter(ClientId,StatusFilterMask,EventMemId,DEM_PRIMARY_MEMORY);
        }
#endif
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
        else if(DTCOrigin == DEM_DTC_ORIGIN_PERMANENT_MEMORY)
        {
            for(Index = (uint8)0; Index < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT(EventMemId); Index++)
            {
                if(DEM_PERMANENT_DATAENTRY_EVENTID(EventMemId, Index) != DEM_EVENT_ID_INVALID)
                {
                    DtcId = DEM_CFG_EVENT_DTCREF(DEM_PERMANENT_DATAENTRY_EVENTID(EventMemId, Index));
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
                    if(Dem_DTCSuppressionState[DtcId] != TRUE)
#endif
                    {

						Dem_DcmFilterInfo[ClientId].FilteredDTCIndexTable[Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC] = DtcId;
						Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC++;

                    }
                }
            }/*for(Index = 0; Index < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT; Index++)*/
        }
#endif
        else
        {
            Result = E_NOT_OK;
        }

        if(Result != E_NOT_OK)
        {
            Dem_DcmFilterInfo[ClientId].FilteredValidFlag = TRUE;
            Dem_DcmFilterInfo[ClientId].FilterProcess = DEM_FILTER_PROCESS_END;
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetDTCFilterByExtendedDataRecordNumber
*
* Description: Sets the DTC Filter based on a given extended data record on the primary fault memory.
*
* Inputs: ClientId:
*         DTCFormat: Defines the output-format of the requested DTC values for the sub-sequent API calls.
*         ExtendedDataRecordNumber: he extended data record number the filter is set for. Valid values
*                                   are within the range of 0x01 and 0xFD
*                   .
*
* Outputs: None
*
* Return: Std_ReturnType: Status of the operation to (re-)set a DTC filter.
*
* Limitations: Synchronous & Non Reentrant
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTCFilterByExtendedDataRecordNumber
(
    uint8 ClientId,
    Dem_DTCFormatType DTCFormat,
    uint8 ExtendedDataRecordNumber
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_NUM_OF_EXTDATACLASS > 0)
    uint16 DtcId;
    uint8 DataId;
    uint8 RecIdx;
#endif
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETDTCFILTERBYEXTENDEDDATERECORD_APIID, DEM_E_UNINIT);
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if((DTCFormat != DEM_DTC_FORMAT_UDS) \
        && (DTCFormat != DEM_DTC_FORMAT_OBD_3BYTE))
    {
        /*SWS_Dem_01066*/
        DEM_DET_REPORT_ERROR(DEM_SETDTCFILTERBYEXTENDEDDATERECORD_APIID, DEM_E_WRONG_CONFIGURATION);
    }
    else if((ExtendedDataRecordNumber == (uint8)0) || (ExtendedDataRecordNumber == DEM_RECORED_NUMBER_FD))
    {
        DEM_DET_REPORT_ERROR(DEM_SETDTCFILTERBYEXTENDEDDATERECORD_APIID, DEM_E_WRONG_CONFIGURATION);
    }
    else
    {
#if(DEM_NUM_OF_EXTDATACLASS > 0)
        /*SWS_Dem_00057*//*SWS_Dem_00649*/
        Dem_DcmFilterInfo[ClientId].DTCFormat = DTCFormat;
        Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC = (uint16)0;
        Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex = (uint16)0;
        /*SWS_Dem_00657*//*SWS_Dem_01058*/ /*SWS_Dem_01101*/ /*SWS_Dem_01377*/ /*SWS_Dem_01378*/
        if(DTCFormat == DEM_DTC_FORMAT_UDS)
        {
            for( DtcId = (uint16)0; DtcId < (uint16)DEM_NUM_OF_DTC; DtcId++)
            {
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
                if(((DEM_GET_SUBMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId))) == DEM_PRIMARY_MEMORY)\
                    && (DEM_CFG_DTC_EXTDATACLASSREF(DtcId) != NULL_PTR)
                    && (Dem_DTCSuppressionState[DtcId] != TRUE))
#else
                if((DEM_GET_SUBMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId)) == DEM_PRIMARY_MEMORY)\
                    && (DEM_CFG_DTC_EXTDATACLASSREF(DtcId) != NULL_PTR))
#endif
                {
                    for(DataId = (uint8)0; DataId < (uint8)DEM_CFG_DTC_NUM_OF_EXTREC(DtcId); DataId++)
                    {
                        RecIdx = (DEM_CFG_DTC_EXTREC_ARRAY(DtcId)[DataId]);
                        if(ExtendedDataRecordNumber == DEM_CFG_DTC_EXTRECNUM(RecIdx))
                        {
                            Dem_DcmFilterInfo[ClientId].FilteredDTCIndexTable[Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC] = DtcId;
                            Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC++;
                        }
                    }
                }
            }
            if(Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC > (uint16)0)
            {
                Dem_DcmFilterInfo[ClientId].FilteredValidFlag = TRUE;
                Result = E_OK;
            }
            else
            {
                Dem_DcmFilterInfo[ClientId].FilteredValidFlag = FALSE;
            }

        }
        else
        {
            DEM_DET_REPORT_ERROR(DEM_SETDTCFILTERBYEXTENDEDDATERECORD_APIID, DEM_E_PARAM_DATA);
        }
#endif

    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetDTCFilterByReadinessGroup
*
* Description: Sets the DTC Filter based on a given DTC readiness group on the primary fault memory.
*
* Inputs: ClientId: Status-byte mask for DTC status-byte filtering
*         DTCFormat: Defines the output-format of the requested DTC values for the sub-sequent API calls.
*         ExtendedDataRecordNumber: he extended data record number the filter is set for. Valid values
*                                   are within the range of 0x01 and 0xFD
*                   .
*
* Outputs: None
*
* Return: Dem_ReturnSetFilterType: Status of the operation to (re-)set a DTC filter.
*
* Limitations: Synchronous & Non Reentrant
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTCFilterByReadinessGroup
(
    uint8 ClientId,
    Dem_DTCFormatType DTCFormat,
    Dem_EventOBDReadinessGroupType ReadinessGroupNumber
)
{
    Std_ReturnType Result = E_NOT_OK;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    uint16 DtcId;
#endif
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETDTCFILTERBYREADINESSGROUP_APIID, DEM_E_UNINIT);
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if((DTCFormat != DEM_DTC_FORMAT_UDS) \
        && (DTCFormat != DEM_DTC_FORMAT_OBD_3BYTE))
    {
        /*SWS_Dem_01066*/
        DEM_DET_REPORT_ERROR(DEM_SETDTCFILTERBYREADINESSGROUP_APIID, DEM_E_WRONG_CONFIGURATION);
    }
    else if(DEM_IS_INVALIED_READINESSGROUP(ReadinessGroupNumber))
    {
        /*SWS_Dem_01066*/
        DEM_DET_REPORT_ERROR(DEM_SETDTCFILTERBYREADINESSGROUP_APIID, DEM_E_WRONG_CONDITION);
    }
    else
    {
         /*SWS_Dem_00057*//*SWS_Dem_00649*/
        Dem_DcmFilterInfo[ClientId].DTCFormat = DTCFormat;
        Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC = (uint16)0;
        Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex = (uint16)0;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
        /*SWS_Dem_01374*/ /*SWS_Dem_01375*/
        if(DTCFormat == DEM_DTC_FORMAT_UDS)
        {
            for( DtcId = (uint16)0; DtcId < DEM_NUM_OF_DTC; DtcId++)
            {
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
                if(((DEM_GET_SUBMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId))) == DEM_PRIMARY_MEMORY)\
                && (Dem_DTCSuppressionState[DtcId] != TRUE) \
                && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
#else
                if(((DEM_GET_SUBMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId))) == DEM_PRIMARY_MEMORY)\
                && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
#endif
                {
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
                    if(ReadinessGroupNumber == DEM_CFG_DTC_OBD_READINESSGROUP(DtcId))
                    {
                        Dem_DcmFilterInfo[ClientId].FilteredDTCIndexTable[Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC] = DtcId;
                        Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC++;
                    }
#endif

                }
            }
            Result = E_OK;
        }
        else
        {
            /*SWS_Dem_01376*/
            DEM_DET_REPORT_ERROR(DEM_SETDTCFILTERBYEXTENDEDDATERECORD_APIID, DEM_E_PARAM_DATA);
        }
        /*SWS_Dem_00657*//*SWS_Dem_01058*/
#endif
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetNumberOfFilteredDTC
*
* Description: Gets the number of a filtered DTC.
*
* Inputs: None
*
* Outputs: NumberOfFilteredDTC: The number of DTCs matching the defined status mask.
*
* Return: Dem_ReturnGetNumberOfFilteredDTCType: Status of the operation to retrieve a
*                                                                       number of DTC from the Dem
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetNumberOfFilteredDTC
(
    uint8 ClientId,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredDTC
)
{
    Std_ReturnType Result = E_OK;

#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETNUMBEROFFILTEREDDTC_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if(NumberOfFilteredDTC == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETNUMBEROFFILTEREDDTC_APIID, DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
    else if(Dem_DcmFilterInfo[ClientId].FilteredValidFlag != TRUE)
    {
        Result = E_NOT_OK;
    }
    else if(Dem_DcmFilterInfo[ClientId].FilterProcess == DEM_FILTER_PROCESSING)
    {
        Result = DEM_PENDING;
    }
    else
    {
        /*SWS_Dem_00061*/
        *NumberOfFilteredDTC = Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetNextFilteredDTC
*
* Description: Gets the next filtered DTC matching the filter criteria. For UDS services, the
*                  interface has an asynchronous behavior, because a large number of DTCs has to
*                  be processed.
*
* Inputs: None
*
* Outputs: DTC: Receives the DTC value in respective format of the filter returned by this function.
*              DTCStatus: This parameter receives the status information of the requested DTC.
*
* Return: Dem_ReturnGetNextFilteredElementType: Status of the operation to retrieve a
*                                                                       DTC from the Dem
*
* Limitations: Synchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetNextFilteredDTC
(
    uint8 ClientId,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatus
)
{
    /*SWS_Dem_00653*/
    Std_ReturnType Result = E_OK;
    uint16 DTCMemId;
    uint16 DtcId;
    uint8 EventMemId;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if((DTC == NULL_PTR) || (DTCStatus == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_GETNEXTFILTEREDDTC_APIID, DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if(Dem_DcmFilterInfo[ClientId].FilteredValidFlag != TRUE)
    {
        Result = DEM_NO_SUCH_ELEMENT;
    }
    else if(Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex >= Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC)
    {
        Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex = (uint16)0;
        Result = DEM_NO_SUCH_ELEMENT;
    }
    else if(Dem_DcmFilterInfo[ClientId].FilterProcess == DEM_FILTER_PROCESSING)
    {
        Result = DEM_PENDING;
    }
    else
    {
        /*SWS_Dem_00216*/
        DtcId = Dem_DcmFilterInfo[ClientId].FilteredDTCIndexTable[Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex];
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
        if(Dem_DTCSuppressionState[DtcId] != TRUE)
#endif
        {
            *DTC = (uint32)DEM_CFG_DTC_VALUE(DtcId);

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
            if((Dem_DcmFilterInfo[ClientId].DTCFormat == DEM_DTC_FORMAT_OBD) \
                && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
            {
                *DTC = (uint32)DEM_CFG_DTC_OBD_VALUE(DtcId);
            }
#endif
#if(DEM_J1939_SUPPORT == STD_ON)
            if((Dem_DcmFilterInfo[ClientId].DTCFormat == DEM_DTC_FORMAT_J1939) \
                && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
            {
                *DTC = (uint32)DEM_CFG_DTC_J1939_VALUE(DtcId);
            }
#endif
            EventMemId = DEM_CLIENT_EVENT_MEM(ClientId);
            DTCMemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId);
            if(DEM_GET_SUBMEMORY_ID(DTCMemId) == DEM_PRIMARY_MEMORY)
            {
                *DTCStatus = (Dem_UdsStatusByteType)((DEM_DTC_STATUS(DtcId)) & (DEM_CFG_DTCSTATU_MASK_PRIMARY(EventMemId)));
            }
#if(DEM_NUM_OF_USERDEF > 0)
            else
            {
                *DTCStatus = (Dem_UdsStatusByteType)((DEM_DTC_STATUS(DtcId)) & (DEM_CFG_DTCSTATU_MASK_USERDEFINED(DEM_GET_SUBMEMORY_ID(DTCMemId))));
            }
#endif
        }
        Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex++;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetNextFilteredDTCAndFDC
*
* Description: Gets the next filtered DTC and its associated Fault Detection Counter (FDC)
*                  matching the filter criteria.
*
* Inputs: None
*
* Outputs: DTC: Receives the DTC value in respective format of the filter returned by this function.
*              DTCFaultDetectionCounter: This parameter receives the Fault Detection Counter
*                                                    information of the requested DTC
*
* Return: Std_ReturnType: Status of the operation to retrieve a
*                                                                       DTC from the Dem
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetNextFilteredDTCAndFDC
(
    uint8 ClientId,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) DTCFaultDetectionCounter
)
{
    Std_ReturnType Result = E_OK;
    uint16 DtcId;
    Dem_EventIdType EventId;
    Std_ReturnType ret = E_OK;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if((DTC == NULL_PTR) || (DTCFaultDetectionCounter == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_GETNEXTFILTEREDDTCANDFDC_APIID, DEM_E_PARAM_POINTER);
        Result = DEM_NO_SUCH_ELEMENT;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if(Dem_DcmFilterInfo[ClientId].FilterProcess == DEM_FILTER_PROCESSING)
    {
        Result = DEM_PENDING;
    }
    else if((Dem_DcmFilterInfo[ClientId].FilteredValidFlag != TRUE) || (Dem_DcmFilterInfo[ClientId].FilterForFDC != TRUE))
    {
        /*SWS_Dem_00518*/
        DEM_DET_REPORT_ERROR(DEM_GETNEXTFILTEREDDTCANDFDC_APIID, DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
    else if(Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex >= Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC)
    {
        Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex = (uint16)0;
        Result = DEM_NO_SUCH_ELEMENT;
    }
    else
    {
        /*SWS_Dem_00228*/
        DtcId = Dem_DcmFilterInfo[ClientId].FilteredDTCIndexTable[Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex];
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
        if(Dem_DTCSuppressionState[DtcId] != TRUE)
#endif
        {
            *DTC = (uint32)DEM_CFG_DTC_VALUE(DtcId);

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
            if((Dem_DcmFilterInfo[ClientId].DTCFormat == DEM_DTC_FORMAT_OBD) \
                && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
            {
                *DTC = (uint32)DEM_CFG_DTC_OBD_VALUE(DtcId);
            }
#endif
#if(DEM_J1939_SUPPORT == STD_ON)
            if((Dem_DcmFilterInfo[ClientId].DTCFormat == DEM_DTC_FORMAT_J1939) \
                && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
            {
                *DTC = (uint32)DEM_CFG_DTC_J1939_VALUE(DtcId);
            }
#endif
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
            if(DEM_IS_COMBINEDDTC(DtcId))
            {
                *DTCFaultDetectionCounter = DEM_EVCOMB_FDC(DtcId);
            }
            else
#endif
            {
                EventId = DEM_CFG_DTC_EVENTREF(DtcId);
                ret = Dem_GetFaultDetectionCounter(EventId, DTCFaultDetectionCounter);
                if(ret != E_OK)
                {
                    Result = DEM_NO_SUCH_ELEMENT;
                }
            }
        }

        Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex++;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetNextFilteredDTCAndSeverity
*
* Description: Gets the next filtered DTC and its associated Severity matching the filter criteria.
*
* Inputs: None
*
* Outputs: DTC: Receives the DTC value in respective format of the filter returned by this function.
*              DTCStatus: This parameter receives the status information of the requested DTC.
*              DTCSeverity: Receives the severity value returned by the function.
*              DTCFunctionalUnit: Receives the functional unit value returned by the function.
*
* Return: Dem_ReturnGetNextFilteredElementType: Status of the operation to retrieve a
*                                                                       DTC from the Dem
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetNextFilteredDTCAndSeverity
(
    uint8 ClientId,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatus,
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit
)
{
    Std_ReturnType Result = E_OK;
    uint8 EventMemId;
    uint16 DtcId;
    uint16 DTCMemId;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if((DTC == NULL_PTR) || (DTCStatus == NULL_PTR) \
        || (DTCSeverity == NULL_PTR) || (DTCFunctionalUnit == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_GETNEXTFILTEREDDTCANDSEVERITY_APIID, DEM_E_PARAM_POINTER);
        Result = DEM_NO_SUCH_ELEMENT;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if(Dem_DcmFilterInfo[ClientId].FilteredValidFlag != TRUE)
    {
        Result = E_NOT_OK;
    }
    else if(Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex >= Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC)
    {
        Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex = (uint16)0;
        Result = DEM_NO_SUCH_ELEMENT;
    }
    else
    {
        /*SWS_Dem_00287*/
        DtcId = Dem_DcmFilterInfo[ClientId].FilteredDTCIndexTable[Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex];
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
        if(Dem_DTCSuppressionState[DtcId] != TRUE)
#endif
        {
            *DTC = (uint32)DEM_CFG_DTC_VALUE(DtcId);
            EventMemId = DEM_CLIENT_EVENT_MEM(ClientId);

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
            if((Dem_DcmFilterInfo[ClientId].DTCFormat == DEM_DTC_FORMAT_OBD) \
                && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
            {
                *DTC = (uint32)DEM_CFG_DTC_OBD_VALUE(DtcId);
            }
#endif
#if(DEM_J1939_SUPPORT == STD_ON)
            if((Dem_DcmFilterInfo[ClientId].DTCFormat == DEM_DTC_FORMAT_J1939) \
                && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
            {
                *DTC = (uint32)DEM_CFG_DTC_J1939_VALUE(DtcId);
            }
#endif
            DTCMemId = DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId);
            if(DEM_GET_SUBMEMORY_ID(DTCMemId) == DEM_PRIMARY_MEMORY)
            {
                *DTCStatus = (Dem_UdsStatusByteType)((DEM_DTC_STATUS(DtcId)) & (DEM_CFG_DTCSTATU_MASK_PRIMARY(EventMemId)));
            }
#if(DEM_NUM_OF_USERDEF > 0)
            else
            {
                *DTCStatus = (Dem_UdsStatusByteType)((DEM_DTC_STATUS(DtcId)) & (DEM_CFG_DTCSTATU_MASK_USERDEFINED(DTCMemId & DEM_DTC_REQURE_USERDEFINED_MEMORY_ID)));
            }
#endif
            *DTCSeverity = DEM_CFG_DTC_SEVERITY(DtcId);
            *DTCFunctionalUnit = DEM_CFG_DTC_FNCUNIT(DtcId);
        }
        Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex++;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SetFreezeFrameRecordFilter
*
* Description: Sets a freeze frame record filter.
*
* Inputs: DTCFormat: Defines the output-format of the requested DTC values for the sub-sequent API calls.
*
* Outputs: NumberOfFilteredRecords: Number of freeze frame records currently stored in the event memory.
*
* Return: Dem_ReturnSetFilterType: Status of the operation to (re-)set a freeze frame record filter.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetFreezeFrameRecordFilter
(
    uint8 ClientId,
    Dem_DTCFormatType DTCFormat
)
{
    /*SWS_Dem_00595*//*SWS_Dem_00650*/
    Std_ReturnType Result = E_OK;
#if(DEM_NUM_OF_FFRECCLASS > 0)
    uint16 i;
    uint8 j;
    uint8 RecordNumber;
    uint16 SizeOfFreezeFrame = (uint16)0;
    uint16 FFDataOffset = (uint16)0;
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
    Dem_EventIdType EventId;
#endif
#endif

#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_SETFREEZEFRAMERECORDFILTER_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if((DTCFormat != DEM_DTC_FORMAT_UDS) \
        && (DTCFormat != DEM_DTC_FORMAT_OBD))
    {
        DEM_DET_REPORT_ERROR(DEM_SETFREEZEFRAMERECORDFILTER_APIID, DEM_E_WRONG_CONFIGURATION);
        Result = E_NOT_OK;
    }
    else
    {
#if(DEM_NUM_OF_FFRECCLASS > 0)
        Dem_NumFFRecOfDTC[ClientId] = (uint8)0;
        Dem_DcmFilterInfo[ClientId].DTCFormat = DTCFormat;
        Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC = (uint16)0;
        Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex = (uint16)0;
        Dem_DcmFilterInfo[ClientId].NumberOfFreezeFrameRecord = (uint16)0;
        /*SWS_Dem_00210*/
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
        for(i = (uint16)0; i < (uint16)DEM_NUM_OF_DTC; i++)
        {
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
            if((DEM_CFG_DTC_VALUE(i) != (Dem_UdsDTCType)0) && ((DEM_DTC_DATAENTRYREF(i) != DEM_DATA_INVALID_U8)\
                || (DEM_DTC_DATAENTRYREF_NUM(i) > (uint8)0)) \
                && (DEM_CFG_DTC_FFRECNUMCLASSREF(i) != NULL_PTR))
#else
            if((DEM_CFG_DTC_VALUE(i) != (Dem_UdsDTCType)0) && (DEM_DTC_DATAENTRYREF(i) != DEM_DATA_INVALID_U8) \
                && (DEM_CFG_DTC_FFRECNUMCLASSREF(i) != NULL_PTR))
#endif
            {
                Dem_DcmFilterInfo[ClientId].FilteredDTCIndexTable[Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC] = i;
                Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC++;
                Dem_SelectDTC_SubMem[ClientId] = DEM_GET_SUBMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(i));
                for(j = (uint8)0; j < (uint8)DEM_CFG_DTC_NUM_OF_FFREC(i); j++)
                {
                    RecordNumber = DEM_CFG_DTC_FFRECNUM((DEM_CFG_DTC_FFREC_ARRAY(i)[j]));
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
                    if(DEM_DTC_DATAENTRYREF_NUM(i) > (uint8)0)
                    {
                        for(EventId = (Dem_EventIdType)0; EventId < DEM_NUM_OF_EVENT; EventId++)
                        {
                            if((DEM_EVENT_DATAENTRYREF(EventId) != DEM_DATA_INVALID_U8) && (i == DEM_CFG_EVENT_DTCREF(EventId)))
                            {
                                (void)DemInternal_GetSizeOfFFData(ClientId, RecordNumber, DEM_EVENT_DATAENTRYREF(EventId),&SizeOfFreezeFrame, &FFDataOffset);
                                /*PRQA S 715 ++*/
                                /*
                                Nesting of control structures (statements) exceeds 15, without modification.
                                */
                                if(SizeOfFreezeFrame != (uint16)0)
                                {
                                    Dem_DcmFilterInfo[ClientId].NumberOfFreezeFrameRecord++;
                                }
                                /*PRQA S 715 --*/
                            }
                        }
                    }
                    else
#endif
                    {
                        (void)DemInternal_GetSizeOfFFData(ClientId, RecordNumber, DEM_DTC_DATAENTRYREF(i),&SizeOfFreezeFrame, &FFDataOffset);
                        if(SizeOfFreezeFrame != (uint16)0)
                        {
                            Dem_DcmFilterInfo[ClientId].NumberOfFreezeFrameRecord++;
                        }
                    }

                }
            }
        }
#endif
        Dem_DcmFilterInfo[ClientId].FilteredValidFlag = TRUE;
#else
        Result = E_NOT_OK;
#endif
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetNumberOfFreezeFrameRecords
*
* Description: This function returns the number of all freeze frame records currently stored in the primary
*              event memory.
*
* Inputs: ClientId
*
* Outputs: NumberOfFilteredRecords: Number of all freeze frame records currently stored in the primary
*                   event memory.
*
*
* Return: Std_ReturnType: E_OK: Returned correctly the number of freeze frame records
*                         DEM_PENDING: The requested value is calculated asynchronously
*                         and currently not available. The caller can retrylater
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetNumberOfFreezeFrameRecords
(
    uint8 ClientId,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredRecords
)
{
    /*SWS_Dem_00225*/
    Std_ReturnType Result = E_OK;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(NumberOfFilteredRecords == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETNUMBEROFFREEZEFRAMERECORDS_APIID, DEM_E_PARAM_POINTER);
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {

    }
#endif
    else if(Dem_DcmFilterInfo[ClientId].FilteredValidFlag != TRUE)
    {
        /*SWS_Dem_01313*/
        DEM_DET_REPORT_ERROR(DEM_GETNUMBEROFFREEZEFRAMERECORDS_APIID, DEM_E_WRONG_CONDITION);
    }
    else
    {
        *NumberOfFilteredRecords = Dem_DcmFilterInfo[ClientId].NumberOfFreezeFrameRecord;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetNextFilteredRecord
*
* Description: Gets the next freeze frame record number and its associated DTC stored in the event memory.
*
* Inputs: None
*
* Outputs: DTC: Receives the DTC value in respective format of the filter returned by this function.
*              RecordNumber: Freeze frame record number of the reported DTC(relative addressing).
*
* Return: Std_ReturnType: Status of the operation to retrieve a DTC and
*                           its associated snapshot record number from the Dem.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetNextFilteredRecord
(
    uint8 ClientId,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) RecordNumber
)
{
    /*SWS_Dem_00225*/
    Std_ReturnType Result = E_OK;
#if(DEM_NUM_OF_FFRECCLASS > 0)
    uint16 DtcId;
    uint16 SizeOfFreezeFrame = (uint16)0;
    uint16 FFDataOffset = (uint16)0;
#endif
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if((DTC == NULL_PTR) || (RecordNumber == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_GETNEXTFILTEREDRECORD_APIID, DEM_E_PARAM_POINTER);
        Result = DEM_NO_SUCH_ELEMENT;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {
        Result = E_NOT_OK;
    }
#endif
    else if(Dem_DcmFilterInfo[ClientId].FilteredValidFlag != TRUE)
    {
        /*SWS_Dem_01313*/
        DEM_DET_REPORT_ERROR(DEM_GETNEXTFILTEREDRECORD_APIID, DEM_E_WRONG_CONDITION);
        Result = DEM_NO_SUCH_ELEMENT;
    }
    else if(Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex >= Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC)
    {
        Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex = (uint16)0;
        Result = DEM_NO_SUCH_ELEMENT;
    }
    else
    {
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
        /*PRQA S 2472 ++*/
        /*
        In the for loop statement satisfies condition Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex < Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC then the internal statement is executed all the time.
        */
        for(; (Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex < Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC);)
        {
            DtcId = Dem_DcmFilterInfo[ClientId].FilteredDTCIndexTable[Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex];
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
            if(Dem_DTCSuppressionState[DtcId] != TRUE)
#endif
            {
                if(Dem_NumFFRecOfDTC[ClientId] < DEM_CFG_DTC_NUM_OF_FFREC(DtcId))
                {
                    *DTC = (uint32)DEM_CFG_DTC_VALUE(DtcId);

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
                    if((Dem_DcmFilterInfo[ClientId].DTCFormat == DEM_DTC_FORMAT_OBD) \
                        && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
                    {
                        *DTC = DEM_CFG_DTC_OBD_VALUE(DtcId);
                    }
#endif
#if(DEM_J1939_SUPPORT == STD_ON)
                    if((Dem_DcmFilterInfo[ClientId].DTCFormat == DEM_DTC_FORMAT_J1939) \
                        && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR))
                    {
                        *DTC = DEM_CFG_DTC_J1939_VALUE(DtcId);
                    }
#endif
                    *RecordNumber = DEM_CFG_DTC_FFRECNUM(DEM_CFG_DTC_FFREC_ARRAY(DtcId)[Dem_NumFFRecOfDTC[ClientId]]);
                    (void)DemInternal_GetSizeOfFFData(ClientId, *RecordNumber,\
                                                    DEM_DTC_DATAENTRYREF(DtcId), &SizeOfFreezeFrame, &FFDataOffset);
                    Dem_NumFFRecOfDTC[ClientId]++;

                    if(Dem_NumFFRecOfDTC[ClientId] >= DEM_CFG_DTC_NUM_OF_FFREC(DtcId))
                    {
                        Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex++;
                        Dem_NumFFRecOfDTC[ClientId] = (uint8)0;
                    }

                    if(SizeOfFreezeFrame != (uint16)0)
                    {
                        break;
                    }
                }
                else
                {
                    Dem_DcmFilterInfo[ClientId].FilteredValidFlag = FALSE;
                    Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex = (uint16)0;
                    Dem_DcmFilterInfo[ClientId].NumberOfFilteredDTC = (uint16)0;

                    Result = DEM_NO_SUCH_ELEMENT;
                }
            }
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
            else
            {
                Dem_DcmFilterInfo[ClientId].NextFilteredDTCIndex++;
                Dem_NumFFRecOfDTC[ClientId] = (uint8)0;
            }
#endif
        }
        /*PRQA S 2472 --*/
#else
        Result = DEM_NO_SUCH_ELEMENT;
#endif
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetDTCByOccurrenceTime
*
* Description: Gets the DTC by occurrence time. There is no explicit parameter for the DTC-origin
*                  as the origin always is DEM_DTC_ORIGIN_PRIMARY_MEMORY.
*
* Inputs: DTCRequest: This parameter defines the request type of the DTC.
*
* Outputs: DTC: Receives the DTC value in respective format of the filter returned by this function.
*
* Return: Std_ReturnType: Status of the operation.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCByOccurrenceTime
(
    uint8 ClientId,
    Dem_DTCRequestType DTCRequest,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC
)
{
    Std_ReturnType Result = E_OK;
    Dem_EventIdType EventId = DEM_DATA_INVALID_U16;
    uint8 EventMemoryId;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETDTCBYOCCURRENCETIME_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if(DTC == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDTCBYOCCURRENCETIME_APIID, DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {
        Result = E_NOT_OK;
    }
#endif
    else if(ClientId >= DEM_NUM_OF_CLIENT)
    {
        DEM_DET_REPORT_ERROR(DEM_GETDTCBYOCCURRENCETIME_APIID, DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
    else
    {
        EventMemoryId = DEM_CLIENT_EVENT_MEM(ClientId);
        /*SWS_Dem_00219*/
        switch(DTCRequest)
        {
        case DEM_FIRST_FAILED_DTC:
            EventId = DEM_EVENT_FIRST_FAILED;
            break;

        case DEM_MOST_RECENT_FAILED_DTC:
            EventId = DEM_EVENT_RECENT_FAILED;
            break;

        case DEM_FIRST_DET_CONFIRMED_DTC:
            EventId = DEM_EVENT_FIRST_CONFIRMED;
            break;

        case DEM_MOST_REC_DET_CONFIRMED_DTC:
            EventId = DEM_EVENT_RECENT_CONFIRMED;
            break;
        /*PRQA S 2016++*/
        /*
        Names in core files may not follow relevant rules.
        */
        default:
            break;
        /*PRQA S 2016--*/
        }

        /*SWS_Dem_01101*/
        if((EventId < DEM_NUM_OF_EVENT) && (DEM_CFG_EVENT_DTCREF(EventId) != DEM_DTC_ID_INVALID)\
            && (EventMemoryId == (uint8)DEM_GET_EVENTMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DEM_CFG_EVENT_DTCREF(EventId)))))
        {
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
            if(Dem_DTCSuppressionState[DEM_CFG_EVENT_DTCREF(EventId)] != TRUE)
#endif
            {
                *DTC = (uint32)DEM_CFG_DTC_VALUE(DEM_CFG_EVENT_DTCREF(EventId));
            }
        }
        else
        {
            /*SWS_Dem_00221*/
            Result = DEM_NO_SUCH_ELEMENT;
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DisableDTCRecordUpdate
*
* Description: Disables the event memory update of a specific DTC (only one at one time).
*
* Inputs: DTC: Selects the DTC in UDS format, for which DTC record update shall be disabled.
*            DTCOrigin: If the Dem supports more than one event memory, this parameter is used
*                           to select the source memory for which DTC record update shall be disabled.
*
* Outputs: None
*
* Return: Std_ReturnType: Status of the operation to disable the
*                            event memory update of a specific DTC.
*
* Limitations: Synchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DisableDTCRecordUpdate
(
    uint8 ClientId
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DISABLEDTCRECORDUPDATE_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if(Dem_DTCIsSelected[ClientId] == FALSE)
    {
        /*SWS_Dem_01299*/
        DEM_DET_REPORT_ERROR(DEM_DISABLEDTCRECORDUPDATE_APIID, DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {
        Result = E_NOT_OK;
    }
#endif
    else if((Dem_SelectDTCState[ClientId] == DEM_WRONG_DTC)\
        ||(Dem_SelectDTCState[ClientId] == DEM_WRONG_DTCORIGIN))
    {
        Result = (Std_ReturnType)Dem_SelectDTCState[ClientId] ;
    }
    else if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_GROUP)
    {
        Result = DEM_WRONG_DTC;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_CHECKING)\
        ||(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PENDING))
    {
        Result = DEM_PENDING;
    }
    else if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PROCESSING)
    {
        Result = DEM_BUSY;
    }
    else if(Dem_SelectDTCRecordUpdate[ClientId] != FALSE )
    {
        /*SWS_Dem_00648*/
        DEM_DET_REPORT_ERROR(DEM_DISABLEDTCRECORDUPDATE_APIID, DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
    else
    {
        Dem_SelectDTCRecordUpdate[ClientId] = TRUE;
        SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_0();
        /*SWS_Dem_00270*/
        Dem_DtcUpDateState[Dem_SelectDTC_Index[ClientId]] = FALSE;
        SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_0();
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_EnableDTCRecordUpdate
*
* Description: Enables the event memory update of the DTC disabled by
*                  Dem_DcmDisableDTCRecordUpdate() before.
*
* Inputs: None
*
* Outputs: None
*
* Return: Std_ReturnType: Always E_OK is returned.
*
* Limitations: Asynchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_EnableDTCRecordUpdate
(
    uint8 ClientId
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_ENABLEDTCRECORDUPDATE_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if(Dem_DTCIsSelected[ClientId] == FALSE)
    {
        /*SWS_Dem_01299*/
        DEM_DET_REPORT_ERROR(DEM_ENABLEDTCRECORDUPDATE_APIID, DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {
        Result = E_NOT_OK;
    }
#endif
    else if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_GROUP)
    {
        Result = E_NOT_OK;
    }
    else
    {
        SchM_Enter_Dem_DEM_EXCLUSIVE_AREA_0();
        Dem_SelectDTCRecordUpdate[ClientId] = FALSE;
        Dem_DtcUpDateState[Dem_SelectDTC_Index[ClientId]] = TRUE;
        SchM_Exit_Dem_DEM_EXCLUSIVE_AREA_0();
    }

    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SelectFreezeFrameData                 SWS_Dem_91015
*
* Description: Sets the filter to be used by Dem_GetNextFreezeFrameData and
*              Dem_GetSizeOfFreezeFrame Selection
*
* Inputs: ClientId:Unique client id, assigned to the instance of the calling module
*         RecordNumber:Unique identifier for a snapshot record as defined in ISO
*         14229-1. The value 0xFF is a placeholder referencing all
*         snapshot records of the addressed DTC. The value 0x00
*         indicates the DTC-specific WWH-OBD snapshot record.
* Outputs: None
*
* Return: Std_ReturnType: E_OK: Freeze frame data successfully selected.
*       DEM_WRONG_DTC: Selected DTC value in selected format does not exist.
*       DEM_WRONG_DTCORIGIN: Selected DTCOrigin does not exist.
*       DEM_PENDING: Selecting the freeze frame is currently in progress.
*                    The caller shall call this function again at a later moment.
*       DEM_BUSY: A different Dem_SelectDTC dependent operation
*                 according to SWS_Dem_01253 of this client is currently in progress.
*
* Limitations: Asynchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SelectFreezeFrameData
(
    uint8 ClientId,
    uint8 RecordNumber
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        DEM_DET_REPORT_ERROR(DEM_SELECTFREEZEFRAMEDATA_APIID, DEM_E_UNINIT);
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {
        Result = E_NOT_OK;
    }
#endif
    else if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_GROUP)
    {
        /*SWS_Dem_01348*/
        Result = DEM_WRONG_DTC;
    }
    else if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PROCESSING)
    {
        Result = DEM_BUSY;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_CHECKING)\
        ||(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PENDING))
    {
        Result = DEM_PENDING;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_WRONG_DTC)\
        ||(Dem_SelectDTCState[ClientId] == DEM_WRONG_DTCORIGIN))
    {
        Result = (Std_ReturnType)Dem_SelectDTCState[ClientId] ;
    }
    else if(Dem_DTCIsSelected[ClientId] != TRUE)
    {
        DEM_DET_REPORT_ERROR(DEM_SELECTFREEZEFRAMEDATA_APIID, DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
    else
    {
        Dem_SelectDTC_RecordNumber[ClientId] = RecordNumber;
        Dem_SelectDTC_RecNumValidFlag[ClientId] = TRUE;
        Dem_SelectDTC_FFRecIndex[ClientId] = (uint8)0;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetNextFreezeFrameData
*
* Description: Gets freeze frame data by DTC. The function stores the data in the provided DestBuffer.
*
* Inputs: DTC: Diagnostic Trouble Code in UDS format.
*            DTCOrigin: If the Dem supports more than one event memory,this parameter is used
*                           to select the source memory the DTCs shall be read from.
*            RecordNumber: This parameter is a unique identifier for a freeze frame record as defined
*                                 in ISO 15031-5 and ISO 14229-1. This record number is unique per DTC
*                                 (relative addressing). The value 0xFF is not allowed. The value 0x00 indicates
*                                 the DTC-specific OBD freeze frame.
*            BufSize: When the function is called this parameter contains the maximum number of
*                        data bytes that can be written to the buffer.
*
* Outputs: BufSize: The function returns the actual number of written data bytes in this parameter.
*              DestBuffer: This parameter contains a byte pointer that points to the buffer, to which
*                              the freeze frame data record shall be written to. The format is: {RecordNumber,
*                              NumOfDIDs, DID[1], data[1], ..., DID[N], data[N]}
*
* Return: Dem_ReturnGetFreezeFrameDataByDTCType:Status of the operation to retrieve
*                                                                          freeze frame data by DTC.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetNextFreezeFrameData
(
    uint8 ClientId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
    Dem_EventIdType EventId;
    uint16 TempBuffSize;
    uint16 DataOffset = (uint16)0;
#endif
#endif
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_GETNEXTFREEZEFRAMEDATA_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if((DestBuffer == NULL_PTR) || (BufSize == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_GETNEXTFREEZEFRAMEDATA_APIID, DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {
        Result = E_NOT_OK;
    }
#endif
    else if(Dem_SelectDTC_RecNumValidFlag[ClientId] != TRUE)
    {
        DEM_DET_REPORT_ERROR(DEM_GETNEXTFREEZEFRAMEDATA_APIID, DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
    else
    {
#if(DEM_MAX_FFSIZE_OF_DTC > 0)
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
        if(DEM_DTC_DATAENTRYREF_NUM(Dem_SelectDTC_Index[ClientId]) > (uint8)0)
        {

            for(EventId = (Dem_EventIdType)0; EventId < DEM_NUM_OF_EVENT; EventId++)
            {
                if((DEM_CFG_EVENT_DTCREF(EventId) == Dem_SelectDTC_Index[ClientId])\
                    && (DEM_EVENT_DATAENTRYREF(EventId) != DEM_DATA_INVALID_U8))
                {
                    TempBuffSize = *BufSize;
                    Result = DemInternal_GetNextFFData(ClientId,Dem_SelectDTC_Index[ClientId], DEM_EVENT_DATAENTRYREF(EventId), (DestBuffer + DataOffset), &TempBuffSize);
                    if(Result == E_OK)
                    {
                        Dem_SelectDTC_FFRecIndex[ClientId] = (uint8)0;
                        DataOffset += TempBuffSize;
                        *BufSize -= TempBuffSize;
                    }
                    else
                    {
                        break;
                    }
                }

            }
            if(Result == E_OK)
            {
                *BufSize = DataOffset;
            }
        }
        else
#endif
        {
            if(DEM_DTC_DATAENTRYREF(Dem_SelectDTC_Index[ClientId]) != DEM_DATA_INVALID_U8)
            {
                Result = DemInternal_GetNextFFData(ClientId,Dem_SelectDTC_Index[ClientId], DEM_DTC_DATAENTRYREF(Dem_SelectDTC_Index[ClientId]), DestBuffer,BufSize);
            }
            else
            {
                Result = DEM_NO_SUCH_ELEMENT;
            }
        }
#endif
    }

    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetSizeOfFreezeFrameSelection
* Description: Gets the size of freeze frame data by DTC.
*
* Inputs: DTC: Diagnostic Trouble Code in UDS format.
*            DTCOrigin: If the Dem supports more than one event memory,this parameter is used
*                           to select the source memory the DTCs shall be read from.
*            RecordNumber: This parameter is a unique identifier for a freeze frame record as defined
*                                 in ISO 15031-5 and ISO 14229-1. This record number is unique per DTC
*                                 (relative addressing). The value 0xFF is explicitly allowed to request the
*                                 overall size.
*
* Outputs: SizeOfFreezeFrame: Number of bytes in the requested freeze frame record.
*
* Return: Std_ReturnType:Status of the operation to retrieve the size of
*                                                                 freeze frame data.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetSizeOfFreezeFrameSelection
(
    uint8 ClientId,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
)
{
    Std_ReturnType Result = E_OK;
    uint16 DtcId;

#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(Dem_SelectDTC_RecNumValidFlag[ClientId] != TRUE)
    {
        DEM_DET_REPORT_ERROR(DEM_GETSIZEOFFREEZEFRAMESELECTION_APIID,DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {
        Result = E_NOT_OK;
    }
#endif
    else if(SizeOfFreezeFrame == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETSIZEOFFREEZEFRAMESELECTION_APIID,DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
    else if((Dem_SelectDTC_DTCOrigin[ClientId] != DEM_DTC_ORIGIN_PRIMARY_MEMORY)\
            && (((Dem_SelectDTC_DTCOrigin[ClientId] & DEM_DTC_ORIGIN_USERDEFINED_MEMORY_XX) == (Dem_DTCOriginType)0)\
            || (((uint8)DEM_GET_SUBMEMORY_ID(Dem_SelectDTC_DTCOrigin[ClientId])) > (uint8)DEM_NUM_OF_USERDEF)))
    {
        /*SWS_Dem_00171*/
        Result = DEM_WRONG_DTCORIGIN;
    }
    else if(Dem_SelectDTC_RecordNumber[ClientId] == (uint8)0)
    {
        Result = DEM_NO_SUCH_ELEMENT;
    }
    else if(E_OK != DemInternal_CheckDtcValid(Dem_SelectDTC_DTC[ClientId], &DtcId))
    {
        /*SWS_Dem_00172*/
        Result = DEM_WRONG_DTC;
    }
#if(DEM_NUM_OF_FFRECCLASS > 0)
    else if(DEM_CFG_DTC_FFRECNUMCLASSREF(DtcId) == NULL_PTR)
    {
        Result = DEM_NO_SUCH_ELEMENT;
    }
#endif
    else
    {
        *SizeOfFreezeFrame = (uint32)0;
        Result = DemInternal_GetSizeOfFreezeFrameSelection(ClientId, DtcId,SizeOfFreezeFrame);
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetSizeOfFreezeFrameSelection
* Description: Gets the size of freeze frame data by DTC.
*
* Inputs: DTC: Diagnostic Trouble Code in UDS format.
*            DTCOrigin: If the Dem supports more than one event memory,this parameter is used
*                           to select the source memory the DTCs shall be read from.
*            RecordNumber: This parameter is a unique identifier for a freeze frame record as defined
*                                 in ISO 15031-5 and ISO 14229-1. This record number is unique per DTC
*                                 (relative addressing). The value 0xFF is explicitly allowed to request the
*                                 overall size.
*
* Outputs: SizeOfFreezeFrame: Number of bytes in the requested freeze frame record.
*
* Return: Std_ReturnType:Status of the operation to retrieve the size of
*                                                                 freeze frame data.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetSizeOfFreezeFrameSelection
(
    uint8 ClientId,
    uint16 DtcId,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
)
{
    Std_ReturnType Result = E_OK;
    uint16 FFDataOffset;
    uint16 SizeOfFFRecord1;
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
    Dem_EventIdType EventId;
    if(DEM_DTC_DATAENTRYREF_NUM(DtcId) > (uint8)0)
    {
        for( EventId = (Dem_EventIdType)0; EventId < DEM_NUM_OF_EVENT; EventId++)
        {
            if((DEM_CFG_EVENT_DTCREF(EventId) == DtcId) && (DEM_EVENT_DATAENTRYREF(EventId) != DEM_DATA_INVALID_U8))
            {
                /*SWS_Dem_00074*/
                Result = DemInternal_GetSizeOfFFData(ClientId, Dem_SelectDTC_RecordNumber[ClientId],DEM_EVENT_DATAENTRYREF(EventId), &SizeOfFFRecord1, &FFDataOffset);
                *SizeOfFreezeFrame += (uint32)SizeOfFFRecord1;
            }
        }
    }
    else
#endif
    {
        Result = DemInternal_GetSizeOfFFData(ClientId, Dem_SelectDTC_RecordNumber[ClientId],DEM_DTC_DATAENTRYREF(DtcId), &SizeOfFFRecord1, &FFDataOffset);
        *SizeOfFreezeFrame = (uint32)SizeOfFFRecord1;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_SelectExtendedDataRecord                 SWS_Dem_91017
*
* Description: Sets the filter to be used by Dem_GetNextFreezeFrameData and
*              Dem_GetSizeOfFreezeFrame Selection
*
* Inputs: ClientId:Unique client id, assigned to the instance of the calling module
*         RecordNumber:Unique identifier for a snapshot record as defined in ISO
*         14229-1. The value 0xFF is a placeholder referencing all
*         snapshot records of the addressed DTC. The value 0x00
*         indicates the DTC-specific WWH-OBD snapshot record.
* Outputs: None
*
* Return: Std_ReturnType: E_OK: Freeze frame data successfully selected.
*       DEM_WRONG_DTC: Selected DTC value in selected format does not exist.
*       DEM_WRONG_DTCORIGIN: Selected DTCOrigin does not exist.
*       DEM_PENDING: Selecting the freeze frame is currently in progress.
*                    The caller shall call this function again at a later moment.
*       DEM_BUSY: A different Dem_SelectDTC dependent operation
*                 according to SWS_Dem_01253 of this client is currently in progress.
*
* Limitations: Asynchronous
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SelectExtendedDataRecord
(
    uint8 ClientId,
    uint8 ExtendedDataNumber
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        DEM_DET_REPORT_ERROR(DEM_SELECTEXTENDEDDATARECORD_APIID, DEM_E_UNINIT);
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {
        Result = E_NOT_OK;
    }
#endif
    else if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_GROUP)
    {
        /*SWS_Dem_01348*/
        Result = DEM_WRONG_DTC;
    }
    else if(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PROCESSING)
    {
        Result = DEM_BUSY;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_CHECKING)\
        ||(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PENDING))
    {
        Result = DEM_PENDING;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_WRONG_DTC)\
        ||(Dem_SelectDTCState[ClientId] == DEM_WRONG_DTCORIGIN))
    {
        Result = (Std_ReturnType)Dem_SelectDTCState[ClientId];
    }
    else if(Dem_DTCIsSelected[ClientId] != TRUE)
    {
        DEM_DET_REPORT_ERROR(DEM_SELECTEXTENDEDDATARECORD_APIID, DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
    else
    {
        Dem_SelectDTC_ExtendedDataNumber[ClientId] = ExtendedDataNumber;
        Dem_SelectDTC_ExDaValidFlag[ClientId] = TRUE;
#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
        Dem_SelectDTC_ExDataNumIndex[ClientId] = (uint8)0;
#endif
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetNextExtendedDataRecord
*
* Description: Gets extended data by DTC. The function stores the data in the
*              provided DestBuffer.
*
* Inputs: DTC: Diagnostic Trouble Code in UDS format.
*         DTCOrigin: If the Dem supports more than one event memory,this parameter is used
*                    to select the source memory the DTCs shall be read from.
*         ExtendedDataNumber: Identification/Number of requested extended data record.
*                             The values 0xFE and 0xFF are not allowed.
*         BufSize: When the function is called this parameter contains the maximum number of
*                  data bytes that can be written to the buffer.
*
* Outputs: BufSize: The function returns the actual number of written data bytes in this parameter.
*          DestBuffer: This parameter contains a byte pointer that points to the buffer, to which
*                      the extended data record shall be written to. The format is raw
*                      hexadecimal values and contains no header-information.
*
* Return: Std_ReturnType:Status of the operation to retrieve
*         extended data by DTC.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetNextExtendedDataRecord
(
    uint8 ClientId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType Result = E_OK;
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
    Std_ReturnType ret = E_OK;
#endif
#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
    uint16 TempBuffSize;
    uint16 DataOffset = (uint16)0;
    Dem_EventIdType EventId;
#endif
#endif
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(DestBuffer == NULL_PTR)
    {
        Result = DEM_BUFFER_TOO_SMALL;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {
        Result = E_NOT_OK;
    }
#endif
    else if(Dem_SelectDTC_ExDaValidFlag[ClientId] != TRUE)
    {
        DEM_DET_REPORT_ERROR(DEM_GETNEXTEXTENDEDDATARECORD_APIID,DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_WRONG_DTC)\
        ||(Dem_SelectDTCState[ClientId] == DEM_WRONG_DTCORIGIN))
    {
        Result = (Std_ReturnType)Dem_SelectDTCState[ClientId] ;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_CHECKING)\
        ||(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PENDING))
    {
        Result = DEM_PENDING;
    }
    else
    {
#if(DEM_MAX_EXTSIZE_OF_DTC > 0)
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
        if(DEM_DTC_DATAENTRYREF_NUM(Dem_SelectDTC_Index[ClientId]) > (uint8)0)
        {
            for(EventId = (Dem_EventIdType)0; EventId < DEM_NUM_OF_EVENT; EventId++)
            {
                if((DEM_CFG_EVENT_DTCREF(EventId) == Dem_SelectDTC_Index[ClientId])\
                    && (DEM_EVENT_DATAENTRYREF(EventId) != DEM_DATA_INVALID_U8))
                {
                    TempBuffSize = *BufSize;
                    Result = DemInternal_GetNextExtendedData(ClientId,Dem_SelectDTC_Index[ClientId], DEM_EVENT_DATAENTRYREF(EventId), (DestBuffer + DataOffset), &TempBuffSize);
                    if(Result == E_OK)
                    {
                        Dem_SelectDTC_ExDataNumIndex[ClientId] = (uint8)0;
                        DataOffset += TempBuffSize;
                        *BufSize -= TempBuffSize;
                    }
                    else
                    {
                        break;
                    }
                }

            }
            if(Result == E_OK)
            {
                *BufSize = DataOffset;
            }
        }
        else
#endif
        {
            if(DEM_DTC_DATAENTRYREF(Dem_SelectDTC_Index[ClientId]) != DEM_DATA_INVALID_U8)
            {
                Result = DemInternal_GetNextExtendedData(ClientId,Dem_SelectDTC_Index[ClientId], DEM_DTC_DATAENTRYREF(Dem_SelectDTC_Index[ClientId]), DestBuffer, BufSize);
            }
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
            else if(((Dem_SelectDTC_ExtendedDataNumber[ClientId] == DEM_FDC_10)\
                || (Dem_SelectDTC_ExtendedDataNumber[ClientId] == DEM_RECORED_NUMBER_FF )) \
                && (Dem_SelectDTC_ExDataNumIndex[ClientId] == (uint8)0))
            {
                *DestBuffer = DEM_FDC_10;
                ret = Dem_GetFaultDetectionCounter(DEM_CFG_DTC_EVENTREF(Dem_SelectDTC_Index[ClientId]), (sint8*)(DestBuffer + 1));
                *BufSize = DEM_UINT16_2;
                if(ret != E_OK)
                {
                    *(DestBuffer + 1) = DEM_DATA_INVALID_U8;
                }
                Dem_SelectDTC_ExDataNumIndex[ClientId]++;
            }
#endif
            else
            {
                Result = DEM_NO_SUCH_ELEMENT;
            }
        }

#endif
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_GetSizeOfExtendedDataRecordSelection
*
* Description: Gets the size of extended data by DTC.
*
* Inputs: DTC: Diagnostic Trouble Code in UDS format.
*         DTCOrigin: If the Dem supports more than one event memory,this parameter
*                    is used to select the source memory the DTCs shall be read from.
*         ExtendedDataNumber: Identification/Number of requested extended data record.
*                             Additionally the values 0xFE and 0xFF are explicitly
*                             allowed to request the overall size of all OBD records
*                             / all records.
*
* Outputs: SizeOfExtendedDataRecord: Size of the requested extended data record(s)
*                                    including record number size
*
* Return: Std_ReturnType: Status of the operation to retrieve
*                                           the size of extended data.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_GetSizeOfExtendedDataRecordSelection
(
    uint8 ClientId,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord
)
{
    Std_ReturnType Result = E_OK;
    uint16 DtcId;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(Dem_SelectDTC_ExDaValidFlag[ClientId] != TRUE)
    {
        DEM_DET_REPORT_ERROR(DEM_GETSIZEOFEXTENDEDDATARECORDSELECTION_APIID, DEM_E_WRONG_CONDITION);
        Result = E_NOT_OK;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_WRONG_DTC)\
        ||(Dem_SelectDTCState[ClientId] == DEM_WRONG_DTCORIGIN))
    {
        Result = (Std_ReturnType)Dem_SelectDTCState[ClientId] ;
    }
    else if((Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_CHECKING)\
        ||(Dem_SelectDTCState[ClientId] == DEM_IN_SELECT_DTC_PENDING))
    {
        Result = DEM_PENDING;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {
        Result = E_NOT_OK;
    }
#endif
    else if(SizeOfExtendedDataRecord == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_GETSIZEOFEXTENDEDDATARECORDSELECTION_APIID, DEM_E_PARAM_POINTER);
        Result = E_NOT_OK;
    }
    else if((Dem_SelectDTC_ExtendedDataNumber[ClientId] == (uint8)0)\
        || ((Dem_SelectDTC_ExtendedDataNumber[ClientId] > DEM_RECORED_NUMBER_EF)\
        && (Dem_SelectDTC_ExtendedDataNumber[ClientId] < DEM_RECORED_NUMBER_FF)))
    {
        Result = DEM_NO_SUCH_ELEMENT;
    }
    else if(E_OK != DemInternal_CheckDtcValid(Dem_SelectDTC_DTC[ClientId], &DtcId))
    {
        /*SWS_Dem_00172*/
        Result = DEM_WRONG_DTC;
    }
#if(DEM_NUM_OF_EXTDATACLASS > 0)
    else if(DEM_CFG_DTC_EXTDATACLASSREF(DtcId) == NULL_PTR)
    {
        Result = DEM_NO_SUCH_ELEMENT;
    }
#endif
    else
    {
    	*SizeOfExtendedDataRecord = (uint32)0;
        Result = DemInternal_GetSizeOfExtendedDataRecordSelection(ClientId, DtcId,SizeOfExtendedDataRecord);
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetSizeOfExtendedDataRecordSelection
*
* Description: Gets the size of extended data by DTC.
*
* Inputs: DTC: Diagnostic Trouble Code in UDS format.
*         DTCOrigin: If the Dem supports more than one event memory,this parameter
*                    is used to select the source memory the DTCs shall be read from.
*         ExtendedDataNumber: Identification/Number of requested extended data record.
*                             Additionally the values 0xFE and 0xFF are explicitly
*                             allowed to request the overall size of all OBD records
*                             / all records.
*
* Outputs: SizeOfExtendedDataRecord: Size of the requested extended data record(s)
*                                    including record number size
*
* Return: Std_ReturnType: Status of the operation to retrieve
*                                           the size of extended data.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_GetSizeOfExtendedDataRecordSelection
(
    uint8 ClientId,
    uint16 DtcId,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord
)
{
    Std_ReturnType Result = E_OK;
    uint16 ExtDataOffset;
    uint16 SizeOfExtendedDataRecord1;
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
    Dem_EventIdType EventId;
    if(DEM_DTC_DATAENTRYREF_NUM(DtcId) > (uint8)0)
    {
        for( EventId = (Dem_EventIdType)0; EventId < DEM_NUM_OF_EVENT; EventId++)
        {
            if((DEM_CFG_EVENT_DTCREF(EventId) == DtcId) && (DEM_EVENT_DATAENTRYREF(EventId) != DEM_DATA_INVALID_U8))
            {
                /*SWS_Dem_00076*/
                Result = DemInternal_GetSizeOfExtendedData(Dem_SelectDTC_Index[ClientId],Dem_SelectDTC_ExtendedDataNumber[ClientId], \
                                            DEM_EVENT_DATAENTRYREF(EventId),&SizeOfExtendedDataRecord1, &ExtDataOffset);
                *SizeOfExtendedDataRecord += (uint32)SizeOfExtendedDataRecord1;
            }
        }
    }
    else
#endif
    {
        /*SWS_Dem_00076*/
        Result = DemInternal_GetSizeOfExtendedData(Dem_SelectDTC_Index[ClientId],Dem_SelectDTC_ExtendedDataNumber[ClientId], \
                            DEM_DTC_DATAENTRYREF(DtcId), &SizeOfExtendedDataRecord1, &ExtDataOffset);
        *SizeOfExtendedDataRecord = (uint32)SizeOfExtendedDataRecord1;
    }
    return Result;

}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DisableDTCSetting
*
* Description: Disables the DTC setting for all DTCs.
*
* Inputs: DTCGroup: Defines the group of DTC that shall be disabled to store in event memory.
*            DTCKind: This parameter defines the requested DTC kind, either only OBD-relevant
*                          DTCs or all DTCs
*
* Outputs: None
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DisableDTCSetting
(
    uint8 ClientId
)
{
    /*SWS_Dem_00035*/
    Std_ReturnType Result = E_OK;
    uint16 i;
    uint8 EventMemoryId;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        DEM_DET_REPORT_ERROR(DEM_DISABLEDTCSETTING_APIID, DEM_E_UNINIT);
    }
    else if(ClientId >= DEM_NUM_OF_CLIENT)
    {
        DEM_DET_REPORT_ERROR(DEM_DISABLEDTCSETTING_APIID, DEM_E_WRONG_CONDITION);
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {
        Result = E_NOT_OK;
    }
#endif
    else
    {
        EventMemoryId = DEM_CLIENT_EVENT_MEM(ClientId);
        for(i = (uint16)0; i < (uint16)DEM_NUM_OF_EVENT; i++)
        {
            if(DEM_CFG_EVENT_DTCREF(i) != DEM_DTC_ID_INVALID)
            {

                if(EventMemoryId == (uint8)DEM_GET_EVENTMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DEM_CFG_EVENT_DTCREF(i))))
                {
                    /*SWS_Dem_00079*/
                    Dem_EnableDtcSetting[DEM_CFG_EVENT_DTCREF(i)] = FALSE;
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
                    if((DEM_CFG_EVENT_DBC(i) != NULL_PTR) \
                            && (DEM_CFG_EVENT_DBC_BEHAVIOR(i) == DEM_DEBOUNCE_RESET))
                    {
                        /*SWS_Dem_00677*/
                        DEM_EVENT_DBC(i) = (sint16)0;
                    }
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
                    if((DEM_CFG_EVENT_DBT(i) != NULL_PTR) \
                            && (DEM_CFG_EVENT_DBT_BAHAVIOR(i) == DEM_DEBOUNCE_RESET))
                    {
                        /*SWS_Dem_00677*/
                        DEM_EVENT_DBT(i) = (uint32)0;
                        DEM_EVENT_TIMERDIRECTION(i) = DEM_DATA_INVALID_U8;
                    }
#endif

                }
            }
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_EnableDTCSetting
*
* Description: Enables the DTC setting for a DTC group.This API is intended for
*              the Dcm. It can only be used through the RTE(due to work-around
*              described below SWS_Dem_00035), and therefore no declaration is
*              exported via Dem_Dcm.h.
*
* Inputs: DTCGroup: Defines the group of DTC that shall be enabled to store in
*                   event memory.
*         DTCKind: This parameter defines the requested DTC kind, either only
*                  OBD-relevant DTCs or all DTCs
*
* Outputs: None
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_EnableDTCSetting
(
    uint8 ClientId
)
{
    /*SWS_Dem_00035*/
    Std_ReturnType Result = E_OK;
    uint16 i;
    uint8 EventMemoryId;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        DEM_DET_REPORT_ERROR(DEM_ENABLEDTCSETTING_APIID, DEM_E_UNINIT);
    }
    else if(ClientId >= DEM_NUM_OF_CLIENT)
    {
        DEM_DET_REPORT_ERROR(DEM_ENABLEDTCSETTING_APIID, DEM_E_WRONG_CONDITION);
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {
        Result = E_NOT_OK;
    }
#endif
    else
    {
        EventMemoryId = DEM_CLIENT_EVENT_MEM(ClientId);
        for(i = (uint16)0; i < (uint16)DEM_NUM_OF_DTC; i++)
        {
            if(EventMemoryId == (uint8)DEM_GET_EVENTMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(i)))
            {
                /*SWS_Dem_00080*/
                Dem_EnableDtcSetting[i] = TRUE;
            }
        }
        /*SWS_Dem_00682*/
        for(i = (uint16)0 ; i < (uint16)DEM_NUM_OF_EVENT; i++)
        {
            if((DEM_CFG_EVENT_DTCREF(i) != DEM_DTC_ID_INVALID)\
                && (EventMemoryId == (uint8)DEM_GET_EVENTMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DEM_CFG_EVENT_DTCREF(i)))))
            {
#if(DEM_INITMFORE_CALLBACK_SUPPORT == STD_ON)
                if(DEM_CFG_EVENT_INITM_CALLFNC(i) != NULL_PTR)
                {
#if(DEM_CORE_NUMBER > 1)
                    if(CoreId != DEM_CFG_EVENT_COREREF(i))
                    {
                        DEM_CFG_EVENT_INITM_FLAG(i) = TRUE;
                        DEM_CFG_EVENT_INITM_REASON(i) = DEM_INIT_MONITOR_REENABLED;
                    }
                    else
#endif
                    {
                        DEM_CFG_EVENT_INITM_CALLFNC(i)(DEM_INIT_MONITOR_REENABLED);
                    }
                }
#endif
            }
        }
    }
    return Result;
}


#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetInfoTypeValue08
*
* Description: Service is used for requesting IUMPR data according to Info-Type $08.
*
* Inputs: OpStatus: Only DCM_INITIAL will appear, because this API behaves synchronous.
*         Iumprdata08BufferSize: The maximum number of data bytes that can be
*                                written to the Iumprdata08 Buffer.
*
* Outputs: Iumprdata08BufferSize
*          Iumprdata08: Buffer containing the number of data elements (as defined
*                       in ISO-15031-5) and contents of InfoType $08. The buffer
*                       is provided by the Dcm.
*
* Return: Always E_OK is returned.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00316*//*SWS_Dem_00298*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue08
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08BufferSize
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_SPARK)
    Dem_RatioIdType RatioID;
    uint8 i;
    uint16 TempBuff[DEM_OBD_INFO08_DATA_LENGTH/2];
    uint32 CurrentRatio;
    uint32 ExistRatio;
#endif



    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMGETINFOTYPEVALUE08_APIID, DEM_E_UNINIT);
    }
    else if((Iumprdata08 == NULL_PTR) || (Iumprdata08BufferSize == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETINFOTYPEVALUE08_APIID, DEM_E_PARAM_POINTER);
    }
    else if(*Iumprdata08BufferSize < DEM_OBD_INFO08_DATA_LENGTH)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETINFOTYPEVALUE08_APIID, DEM_E_PARAM_LENGTH);
    }
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
    else if(Dem_DTCSuppressionState[DEM_CFG_EVENT_DTCREF(DEM_OBD_FF_EVENT)] != FALSE)
    {

    }
#endif
    else
    {
        /*SWS_Dem_00357*/
#if(DEM_NUM_OF_RATIO > 0)
#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_SPARK)
        for(i = (uint8)0; i < (uint8)(DEM_OBD_INFO08_DATA_LENGTH/2); i++)
        {
            TempBuff[i] = DEM_DATA_INVALID_U16;
        }
        /*Numerator:OBD Monitoring Conditions Encountered Counts*/
        TempBuff[0] = DEM_OBD_RATIO_GENDEN_CNT;
        /*Denominator:Ignition Cycle Counter*/
        TempBuff[1] = DEM_OBD_RATIO_IGN_CNT;

        for(RatioID = (Dem_RatioIdType)0; RatioID < DEM_NUM_OF_RATIO; RatioID++)
        {
            i = DEM_CFG_RATIO_IUMPR(RatioID);

            if(TempBuff[i*2] == DEM_DATA_INVALID_U16)
            {
                /*Numerator*/
                TempBuff[i*2] = DEM_OBD_RATIO_NUMERATOR(RatioID);
                /*Denominator*/
                TempBuff[i*2 + 1] = DEM_OBD_RATIO_DENOMINATOR(RatioID);
            }
            else
            {
                /*If one IUMPR group has been referenced by several Ratios,
                the IUMPR group value should same to the minimum value of the Ratios.*/
                CurrentRatio = (DEM_OBD_RATIO_NUMERATOR(RatioID)*(TempBuff[i*2 + 1]));
                ExistRatio = ((TempBuff[i*2])*DEM_OBD_RATIO_DENOMINATOR(RatioID));

                if((CurrentRatio < ExistRatio) \
                    || ((CurrentRatio == ExistRatio) \
                    && (DEM_OBD_RATIO_DENOMINATOR(RatioID) > (TempBuff[i*2 + 1]))))
                {
                    /*Numerator*/
                    TempBuff[i*2] = DEM_OBD_RATIO_NUMERATOR(RatioID);
                    /*Denominator*/
                    TempBuff[i*2 + 1] = DEM_OBD_RATIO_DENOMINATOR(RatioID);
                }
            }
        }

        for(i = (uint8)0; i < (uint8)(DEM_OBD_INFO08_DATA_LENGTH/2); i++)
        {
            Iumprdata08[i*2] = (uint8)(TempBuff[i] >> (uint16)8);
            Iumprdata08[i*2 + 1] = (uint8)(TempBuff[i]);
        }
        *Iumprdata08BufferSize = DEM_OBD_INFO08_DATA_LENGTH;

        Result = E_OK;
#endif/*#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_SPARK)*/
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetInfoTypeValue0B
*
* Description: Service is used for requesting IUMPR data according to Info-Type $0B.
*
* Inputs: OpStatus: Only DCM_INITIAL will appear, because this API behaves synchronous.
*         Iumprdata0BBufferSize: The maximum number of data bytes that can be
*                                written to the Iumprdata0B Buffer.
*
* Outputs: Iumprdata0BBufferSize
*          Iumprdata0B: Buffer containing the number of data elements (as defined
*                       in ISO-15031-5) and contents of InfoType $0B. The buffer
*                       is provided by the Dcm.
*
* Return: Always E_OK is returned.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00317*//*SWS_Dem_00298*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue0B
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0B,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0BBufferSize
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_NUM_OF_RATIO > 0)
#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_COMPRESSION)
    Dem_RatioIdType RatioID;
    uint8 i;
    uint16 TempBuff[DEM_OBD_INFO0B_DATA_LENGTH/2];
    uint32 CurrentRatio;
    uint32 ExistRatio;
#endif
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMGETINFOTYPEVALUE0B_APIID, DEM_E_UNINIT);
    }
    else if((Iumprdata0B == NULL_PTR) || (Iumprdata0BBufferSize == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETINFOTYPEVALUE0B_APIID, DEM_E_PARAM_POINTER);
    }
    else if(*Iumprdata0BBufferSize < DEM_OBD_INFO0B_DATA_LENGTH)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETINFOTYPEVALUE0B_APIID, DEM_E_PARAM_LENGTH);
    }
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
    else if(Dem_DTCSuppressionState[DEM_CFG_EVENT_DTCREF(DEM_OBD_FF_EVENT)] != FALSE)
    {

    }
#endif
    else
    {
        /*SWS_Dem_00358*/
#if(DEM_NUM_OF_RATIO > 0)
#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_COMPRESSION)
        for(i = (uint8)0; i < (uint8)(DEM_OBD_INFO0B_DATA_LENGTH/2); i++)
        {
            TempBuff[i] = DEM_DATA_INVALID_U16;
        }
        /*Numerator:OBD Monitoring Conditions Encountered Counts*/
        TempBuff[0] = DEM_OBD_RATIO_GENDEN_CNT;
        /*Denominator:Ignition Cycle Counter*/
        TempBuff[1] = DEM_OBD_RATIO_IGN_CNT;

        for(RatioID = (Dem_RatioIdType)0; RatioID < DEM_NUM_OF_RATIO; RatioID++)
        {
            i = DEM_CFG_RATIO_IUMPR(RatioID);

            if(TempBuff[i*2] == DEM_DATA_INVALID_U16)
            {
                /*Numerator*/
                TempBuff[i*2] = DEM_OBD_RATIO_NUMERATOR(RatioID);
                /*Denominator*/
                TempBuff[i*2 + 1] = DEM_OBD_RATIO_DENOMINATOR(RatioID);
            }
            else
            {
                /*If one IUMPR group has been referenced by several Ratios,
                the IUMPR group value should same to the minimum value of the Ratios.*/
                CurrentRatio = (DEM_OBD_RATIO_NUMERATOR(RatioID)*(TempBuff[i*2 + 1]));
                ExistRatio = ((TempBuff[i*2])*DEM_OBD_RATIO_DENOMINATOR(RatioID));

                if((CurrentRatio < ExistRatio) \
                    || ((CurrentRatio == ExistRatio) \
                    && (DEM_OBD_RATIO_DENOMINATOR(RatioID) > (TempBuff[i*2 + 1]))))
                {
                    /*Numerator*/
                    TempBuff[i*2] = DEM_OBD_RATIO_NUMERATOR(RatioID);
                    /*Denominator*/
                    TempBuff[i*2 + 1] = DEM_OBD_RATIO_DENOMINATOR(RatioID);
                }
            }
        }

        for(i = (uint8)0; i < (uint8)(DEM_OBD_INFO0B_DATA_LENGTH/2); i++)
        {
            Iumprdata0B[i*2] = (uint8)(TempBuff[i] >> (uint16)8);
            Iumprdata0B[i*2 + 1] = (uint8)(TempBuff[i]);
        }
        *Iumprdata0BBufferSize = DEM_OBD_INFO0B_DATA_LENGTH;

        Result = E_OK;
#endif/*#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_COMPRESSION)*/
#endif/*#if(DEM_NUM_OF_RATIO > 0)*/
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID01
*
* Description: Service to report the value of PID $01 computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID01value: Buffer containing the contents of PID $01 computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00318*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID01
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID01value
)
{
    Std_ReturnType Result = E_NOT_OK;

    Result = Dem_ReadDataOfPID01(PID01value);

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID1C
*
* Description: Service to report the value of PID $1C computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID1Cvalue: Buffer containing the contents of PID $1C computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00325*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID1C
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID1Cvalue
)
{
    Std_ReturnType Result = E_NOT_OK;


    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID1C_APIID, DEM_E_UNINIT);
    }
    else if(PID1Cvalue == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID1C_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        *PID1Cvalue = DEM_CFG_OBD_COMPLIANCY;
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID21
*
* Description: Service to report the value of PID $21 computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID21value: Buffer containing the contents of PID $21 computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00319*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value
)
{
    Std_ReturnType Result = E_NOT_OK;

    uint16 Distance;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID21_APIID, DEM_E_UNINIT);
    }
    else if(PID21value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID21_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        PID21value[DEM_INDEX_0] = DEM_DATA_CLEAR;
        PID21value[DEM_INDEX_1] = DEM_DATA_CLEAR;
        Distance = (uint16)(DEM_OBD_DISTANCE_MILACTIVATED / DEM_DATA_1000);
        PID21value[DEM_INDEX_0] = (uint8)(Distance >> (uint16)8);
        PID21value[DEM_INDEX_1] = (uint8)Distance;
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID30
*
* Description: Service to report the value of PID $30 computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID30value: Buffer containing the contents of PID $30 computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00320*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID30
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID30value
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID30_APIID, DEM_E_UNINIT);
    }
    else if(PID30value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID30_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        *PID30value = DEM_OBD_NUMWARMUP_SINCEDTCCLEARED;
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID31
*
* Description: Service to report the value of PID $31 computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID31value: Buffer containing the contents of PID $31 computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00321*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID31
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID31value
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint16 Distance;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID31_APIID, DEM_E_UNINIT);
    }
    else if(PID31value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID31_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        PID31value[DEM_INDEX_0] = DEM_DATA_CLEAR;
        PID31value[DEM_INDEX_1] = DEM_DATA_CLEAR;
        Distance = (uint16)(DEM_OBD_DISTANCE_SINCEDTCCLEARED / DEM_DATA_1000);
        PID31value[DEM_INDEX_0] = (uint8)(Distance >> (uint16)8);
        PID31value[DEM_INDEX_1] = (uint8)Distance;

        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID41
*
* Description: Service to report the value of PID $41 computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID41value: Buffer containing the contents of PID $41 computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00322*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID41
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID41value
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
    Dem_EventIdType EventId;
    uint16 DtcId;
    Dem_UdsStatusByteType DtcStatus;
    uint8 BytePos;
    uint8 BitPos;
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID41_APIID, DEM_E_UNINIT);
    }
    else if(PID41value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID41_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
        PID41value[0] = DEM_DATA_CLEAR;
        PID41value[1] = DEM_DATA_CLEAR;
        PID41value[2] = DEM_DATA_CLEAR;
        PID41value[3] = DEM_DATA_CLEAR;

        for(EventId = (Dem_EventIdType)0; EventId < DEM_NUM_OF_EVENT; EventId++)
        {
            DtcId = DEM_CFG_EVENT_DTCREF(EventId);
            /*SWS_Dem_00355*/
#if(DEM_CFG_AVAILABILITYSUPPORT == DEM_EVENT_AVAILABILITY)
            if((Dem_EventAvailable[EventId] == TRUE) \
                && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR) \
                && (DEM_CFG_DTC_OBD_READINESSGROUP(DtcId) != DEM_OBD_RDY_NONE))
#else
            if((DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR) \
                && (DEM_CFG_DTC_OBD_READINESSGROUP(DtcId) != DEM_OBD_RDY_NONE))
#endif
            {
                BytePos = (DEM_CFG_DTC_OBD_READINESSGROUP(DtcId) / (Dem_EventOBDReadinessGroupType)8);
                BitPos = (DEM_CFG_DTC_OBD_READINESSGROUP(DtcId) % (Dem_EventOBDReadinessGroupType)8);
                /*SWS_Dem_00356*/
                if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) != (uint8)0)
                {
                    /*Set value of monitors enable bit*/
                    PID41value[BytePos + 1] |= ((uint8)0x01 << BitPos);

                    DtcStatus = DEM_DTC_STATUS(DtcId);
                    /*Monitor status this driving cycle*/
                    if(DEM_TEST_UDS_STATUS_TNCTOC(DtcStatus))
                    {
                        switch(BytePos)
                        {
                            /*Set value of monitors compleate bit
                            0 = monitor complete this monitoring cycle (YES)
                            0 = monitor not supported (N/A)
                            1 = monitor not complete this monitoring cycle (NO)*/
                            case 0:
                                PID41value[1] |= ((uint8)0x40 << BitPos);
                            break;

                            default:
                                PID41value[3] |= ((uint8)0x01 << BitPos);
                            break;
                        }
                    }
                }/*if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) != (uint8)0)*/
            }
        }/*for(EventId = 0; EventId < DEM_NUM_OF_EVENT; EventId++)*/

        Result = E_OK;
#endif/*#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)*/
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID4D
*
* Description: Service to report the value of PID $4D computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID4Dvalue: Buffer containing the contents of PID $4D computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00323*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4D
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Dvalue
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint16 RunTime;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID4D_APIID, DEM_E_UNINIT);
    }
    else if(PID4Dvalue == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID4D_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        PID4Dvalue[DEM_INDEX_0] = DEM_DATA_CLEAR;
        PID4Dvalue[DEM_INDEX_1] = DEM_DATA_CLEAR;
        RunTime = (uint16)(DEM_OBD_ENGINERUN_MILACTIVATED / DEM_DATA_60);
        PID4Dvalue[DEM_INDEX_0] = (uint8)(RunTime >> (uint16)8);
        PID4Dvalue[DEM_INDEX_1] = (uint8)RunTime;

        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID4E
*
* Description: Service to report the value of PID $4E computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID4Evalue: Buffer containing the contents of PID $4E computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00324*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4E
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Evalue
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint16 RunTime;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID4E_APIID, DEM_E_UNINIT);
    }
    else if(PID4Evalue == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID4E_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        PID4Evalue[DEM_INDEX_0] = DEM_DATA_CLEAR;
        PID4Evalue[DEM_INDEX_1] = DEM_DATA_CLEAR;
        RunTime = (uint16)(DEM_OBD_ENGINERUN_SINCEDTCCLEARED / DEM_DATA_60);
        PID4Evalue[DEM_INDEX_0] = (uint8)(RunTime >> (uint16)8);
        PID4Evalue[DEM_INDEX_1] = (uint8)RunTime;
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfPID91
*
* Description: Service to report the value of PID $91 computed by the Dem.
*
* Inputs: None.
*
* Outputs: PID91value: Buffer containing the contents of PID $91 computed by the
*                      Dem.
*
* Return: Always E_OK is returned, as E_NOT_OK will never appear.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_01187*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID91
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID91value
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID91_APIID, DEM_E_UNINIT);
    }
    else if(PID91value == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFPID91_APIID, DEM_E_PARAM_POINTER);
    }
    else
    {
        /*Not implemented.*/
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmReadDataOfOBDFreezeFrame
*
* Description: Gets data element per PID and index of the most important freeze
*              frame being selected for the output of service $02.
*
* Inputs: PID: This parameter is an identifier for a PID as defined in ISO15031-5.
*         DataElementIndexOfPID: Data element index of this PID according to the
*                                Dcm configuration of service $02. It is zero-based
*                                and consecutive, and ordered by the data element
*                                positions.
*         DestBuffer: This parameter contains a byte pointer that points to the
*                     buffer, to which the data element of the PID shall be
*                     written to.
*         BufSize: When the function is called this parameter contains the maximum
*                  number of data bytes that can be written to the buffer.
*
* Outputs: DestBuffer
*          BufSize: The function returns the actual number of written data bytes
*                   in this parameter.
*
* Return: E_OK: Freeze frame data was successfully reported.
*         E_NOT_OK: Freeze frame data was not successfully reported.
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00327*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfOBDFreezeFrame
(
    uint8 PID,
    uint8 DataElementIndexOfPID,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint8 PidIndex;
    uint8 DataIndex;/*Data index of Pid*/
    uint8 DataIndexOfDataClass;/*Data index of DataElementClass*/
    uint8 *SrcDataPtr;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFOBDFREEZEFRAME_APIID, DEM_E_UNINIT);
    }
    else if((DestBuffer == NULL_PTR) || (BufSize == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFOBDFREEZEFRAME_APIID, DEM_E_PARAM_POINTER);
    }
    else if(DEM_OBD_FF_EVENT == DEM_EVENT_ID_INVALID)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFOBDFREEZEFRAME_APIID, DEM_E_NODATAAVAILABLE);
    }
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
    else if(Dem_DTCSuppressionState[DEM_CFG_EVENT_DTCREF(DEM_OBD_FF_EVENT)] != FALSE)
    {

    }
#endif
    else
    {
        SrcDataPtr = DEM_OBD_FF_DATA_BUF;
        /*SWS_Dem_00596*//*SWS_Dem_00597*/
        for(PidIndex = (uint8)0; PidIndex < DEM_CFG_OBD_NUM_OF_PID; PidIndex++)
        {
            SrcDataPtr++;/*PID length: one byte*/

            if((DEM_CFG_PID_ID(PidIndex) == PID) \
                && (DataElementIndexOfPID < DEM_CFG_PID_NUM_OF_DATA(PidIndex)))
            {
                DataIndexOfDataClass = DEM_CFG_PID_DATA_CLASS(PidIndex)[DataElementIndexOfPID];

                if(*BufSize < DEM_CFG_DATA_CS_DATA_SIZE(DataIndexOfDataClass))
                {
                    DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFOBDFREEZEFRAME_APIID, DEM_E_PARAM_LENGTH);
                }
                else
                {
                    for(DataIndex = (uint8)0; DataIndex < DEM_CFG_PID_NUM_OF_DATA(PidIndex); DataIndex++)
                    {
                        DataIndexOfDataClass = DEM_CFG_PID_DATA_CLASS(PidIndex)[DataIndex];

                        if(DataIndex == DataElementIndexOfPID)
                        {
                            *BufSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIndexOfDataClass);
                            Bsw_MemCpy(DestBuffer, SrcDataPtr, (*BufSize));
                        }
                        else
                        {
                            SrcDataPtr += DEM_CFG_DATA_CS_DATA_SIZE(DataIndexOfDataClass);
                        }
                    }
                    Result = E_OK;
                }
                break;
            }
            else
            {
                for(DataIndex = (uint8)0; DataIndex < DEM_CFG_PID_NUM_OF_DATA(PidIndex); DataIndex++)
                {
                    DataIndexOfDataClass = DEM_CFG_PID_DATA_CLASS(PidIndex)[DataIndex];
                    SrcDataPtr += DEM_CFG_DATA_CS_DATA_SIZE(DataIndexOfDataClass);
                }
            }
        }

        if(PidIndex == DEM_CFG_OBD_NUM_OF_PID)
        {
            DEM_DET_REPORT_ERROR(DEM_DCMREADDATAOFOBDFREEZEFRAME_APIID, DEM_E_PARAM_DATA);
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetDTCOfOBDFreezeFrame
*
* Description: Gets DTC by freeze frame record number.
*
* Inputs: FrameNumber: Unique identifier for a freeze frame record as defined in
*                      ISO 15031-5. The value 0x00 indicates the complete OBD
*                      freeze frame. Other values are reserved for future
*                      functionality.
*         DTCFormat: Output format of the DTC value.
*
* Outputs: DTC: Diagnostic Trouble Code in ODB format.
*
* Return: E_OK: operation was successful
*         E_NOT_OK: no DTC available
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00624*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCOfOBDFreezeFrame
(
    uint8 FrameNumber,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    Dem_DTCFormatType DTCFormat
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMGETDTCOFOBDFREEZEFRAME_APIID, DEM_E_UNINIT);
    }
    else if(DTC == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETDTCOFOBDFREEZEFRAME_APIID, DEM_E_PARAM_POINTER);
    }
    else if(DTCFormat != DEM_DTC_FORMAT_OBD)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETDTCOFOBDFREEZEFRAME_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
        /*SWS_Dem_00291*/
        if(FrameNumber == (uint8)0)
        {
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
            if((DEM_OBD_FF_EVENT != DEM_EVENT_ID_INVALID)\
                && (Dem_DTCSuppressionState[DEM_CFG_EVENT_DTCREF(DEM_OBD_FF_EVENT)] != TRUE))
#else
            if(DEM_OBD_FF_EVENT != DEM_EVENT_ID_INVALID)
#endif
            {
                /*SWS_Dem_00623*/
                *DTC = (uint32)DEM_CFG_DTC_OBD_VALUE(DEM_CFG_EVENT_DTCREF(DEM_OBD_FF_EVENT));
                Result = E_OK;
            }
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetAvailableOBDMIDs
*
* Description: Reports the value of a requested "availability-OBDMID" to the DCM
*              upon a Service $06 request.
*
* Inputs: Obdmid: Availablity OBDMID ($00,$20, $40...)
*
* Outputs: Obdmidvalue: Bit coded information on the support of OBDMIDs.
*
* Return: E_OK: Report of DTR result successful
*         E_NOT_OK: Report of DTR result failed
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00766*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetAvailableOBDMIDs
(
    uint8 Obdmid,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) Obdmidvalue
)
{
#if(DEM_MAX_NUM_OF_DTR > 0)
    uint8 DtrPos;
#endif
    Std_ReturnType Result = E_NOT_OK;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMGETNUMTIDSOFOBDMID_APIID, DEM_E_UNINIT);
    }
    else if(Obdmidvalue == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETNUMTIDSOFOBDMID_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
#if(DEM_MAX_NUM_OF_DTR > 0)
        *Obdmidvalue = (uint32)0;
        DtrPos = (Obdmid / DEM_OBD_BIT_NUM_PER_4BYTE);

        if((DtrPos == (uint8)0) || ((DEM_OBD_DTR_AVAIL_DTR((DtrPos - (uint8)1)) & (uint8)0x01) != (uint8)0))
        {
            *Obdmidvalue = DEM_OBD_DTR_AVAIL_DTR(DtrPos);
            Result = E_OK;
        }
#endif
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetNumTIDsOfOBDMID
*
* Description: Gets the number of TIDs per (functional) OBDMID.
*
* Inputs: Obdmid: OBDMID subject of the request to identify the number of
*                 assigned TIDs.
*
* Outputs: numberOfTIDs: Number of assigned TIDs for the requested OBDMID.
*
* Return: E_OK: get number of TIDs successful
*         E_NOT_OK: get number of TIDs failed
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00767*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetNumTIDsOfOBDMID
(
    uint8 Obdmid,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) numberOfTIDs
)
{

#if(DEM_MAX_NUM_OF_DTR > 0)
    uint16 DtrId;
    uint16 TidIndex = (uint16)0;
#endif
    Std_ReturnType Result = E_NOT_OK;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMGETNUMTIDSOFOBDMID_APIID, DEM_E_UNINIT);
    }
    else if(numberOfTIDs == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETNUMTIDSOFOBDMID_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
#if(DEM_MAX_NUM_OF_DTR > 0)
        for(DtrId = (uint16)0; DtrId < DEM_NUM_OF_DTR; DtrId++)
        {
            if(Obdmid == DEM_CFG_DTR_MID(DtrId))
            {
                TidIndex ++;
            }
        }
        *numberOfTIDs = TidIndex;
        Result = E_OK;
#endif
    }

    /*Not implemented.*/

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_DcmGetDTRData
*
* Description: Reports a DTR data along with TID-value, UaSID, test result with
*              lower and upper limit.
*
* Inputs: Obdmid: Identification of a DTR element by assigned DTRId.
*         TIDindex: Index of the TID within the DEM. Runs from 0 to "numberOfTIDs"
*                   obtained in the call to Dem_DcmGetNumTIDsOfOBDMID().
*
* Outputs: TIDvalue: TID to be put on the tester reponse.
*          UaSID: UaSID to be put on the tester reponse.
*          Testvalue: Latest test result.
*          Lowlimvalue: Lower limit value associated to the latest test result.
*          Upplimvalue: Upper limit value associated to the latest test result.
*
* Return: E_OK: get number of TIDs successful
*         E_NOT_OK: get number of TIDs failed
*
* Limitations: This API will be available only if ({ecuc(Dem/DemGeneral.DemOBD-
*              Support)} != DEM_OBD_NO_OBD_SUPPORT)
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00768*/
FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTRData
(
    uint8 Obdmid,
    uint8 TIDindex,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) TIDvalue,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) UaSID,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Testvalue,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Lowlimvalue,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Upplimvalue
)
{
	Std_ReturnType Result = E_NOT_OK;
#if(DEM_MAX_NUM_OF_DTR > 0)
	uint16 DtrId;
    DtrId = DemInternal_GetDtrId(Obdmid,TIDindex);
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_DCMGETDTRDATA_APIID, DEM_E_UNINIT);
    }
    else if(DtrId >= DEM_NUM_OF_DTR)
    {
        DEM_DET_REPORT_ERROR(DEM_DCMGETDTRDATA_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
        *TIDvalue = DEM_CFG_DTR_TID(DtrId);
        *UaSID = DEM_CFG_DTR_UASID(DtrId);
        *Testvalue = DEM_OBD_DTR_TESTRESULT(DtrId);
        *Lowlimvalue = DEM_OBD_DTR_LOWERLIMIT(DtrId);
        *Upplimvalue = DEM_OBD_DTR_UPPERLIMIT(DtrId);
        Result = E_OK;
    }
#endif

    return Result;
}
#if(DEM_MAX_NUM_OF_DTR > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_GetDtrId
*
* Description:
*
* Inputs:
*
*
* Outputs:
*
* Return:
*
*
* Limitations:
*
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint16, DEM_CODE) DemInternal_GetDtrId
(
    uint8 Obdmid,
    uint8 TIDindex
)
{
    uint16 DtrId ;
    uint8 TempTIDIndex = (uint8)0;
    for(DtrId = (uint16)0; DtrId < DEM_MAX_NUM_OF_DTR; DtrId++)
    {
        if(DEM_CFG_DTR_MID(DtrId) == Obdmid)
        {
            if(TIDindex == TempTIDIndex)
            {
                break;
            }
            else
            {
                TIDindex++;
            }
        }
    }
    return DtrId;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_DtrInfoInit
*
* Description:
*
* Inputs:
*
*
* Outputs:
*
* Return:
*
*
* Limitations:
*
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_DtrInfoInit(void)
{
    uint8 Idx;/*Index*/
    uint8 DataPos;
    uint8 BitPos;
    uint8 RowMax = (uint8)0;

    for(Idx = (uint8)0; Idx < DEM_OBD_AVAIL_PARA_LENGTH; Idx++)
    {
        Dem_OBD_AvailDTR[Idx] = DEM_DATA_CLEAR;
    }

    for(Idx = (uint16)0; Idx < DEM_MAX_NUM_OF_DTR; Idx++)
    {
        DataPos = ((DEM_CFG_DTR_MID(Idx) - (uint8)1) / DEM_OBD_BIT_NUM_PER_4BYTE);
        BitPos = ((DEM_CFG_DTR_MID(Idx) - (uint8)1) %  DEM_OBD_BIT_NUM_PER_4BYTE);
        BitPos = (DEM_OBD_BIT_NUM_PER_4BYTE - (uint8)1 - BitPos);

        DEM_OBD_DTR_AVAIL_DTR(DataPos) |= ((uint32)0x01 << BitPos);

        if(RowMax < DataPos)
        {
            RowMax = DataPos;
        }
    }

    for(Idx = (uint8)0; Idx <= RowMax; Idx++)
    {
        DEM_OBD_DTR_AVAIL_DTR(DataPos) |= ((uint32)0x01);
    }

}
#endif
#endif /*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"



/*******************************************************************************
*   Dem_NvM
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_NvM_InitStorageMem
(
    void
)
{
    uint8 EventMemId;
    uint16 i;
#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
    uint16 j;
#endif
    Dem_MemIdType k;

    DEM_EVENT_FIRST_FAILED = DEM_DATA_INVALID_U16;
    DEM_EVENT_RECENT_FAILED = DEM_DATA_INVALID_U16;
    DEM_EVENT_FIRST_CONFIRMED = DEM_DATA_INVALID_U16;
    DEM_EVENT_RECENT_CONFIRMED = DEM_DATA_INVALID_U16;

    for(EventMemId = (uint8)0; EventMemId < (uint8)DEM_NUM_OF_OPCYCLE; EventMemId++)
    {
        DEM_CURRENT_OP_STATE(EventMemId) = DEM_CYCLE_STATE_END;
    }

    for(i = (uint16)0; i < (uint16)DEM_NUM_OF_EVENT; i++)
    {
        DEM_EVENT_FCC(i) = DEM_DATA_CLEAR;
#if(DEM_NUM_OF_INDICATOR > 0)
        DEM_EVENT_IFCC(i) = DEM_DATA_CLEAR;
        DEM_EVENT_IHCC(i) = DEM_DATA_CLEAR;
#endif
        DEM_EVENT_OCCCTR(i) = DEM_DATA_CLEAR;
#if(DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT == STD_ON)
        DEM_EVENT_DBC(i) = (sint16)0;
#endif
#if(DEM_CFG_DEBOUNCETIMEBASEDSUPPORT == STD_ON)
        DEM_EVENT_DBT(i) = (uint32)0;
        DEM_EVENT_TIMERDIRECTION(i) = DEM_DATA_INVALID_U8;
#endif
#if(DEM_EVENT_MAXFDCDCC_SUPPORT == STD_ON)
        DEM_EVENT_MAXFDCDCC(i) = (sint8)0;
#endif
#if(DEM_EVENT_MAXFDCSLC_SUPPORT == STD_ON)
        DEM_EVENT_MAXFDCSLC(i) = (sint8)0;
#endif
#if(DEM_EVENT_CSLF_SUPPORT == STD_ON)
        DEM_EVENT_CSLF(i) = DEM_DATA_CLEAR;
#endif
#if(DEM_EVENT_CSFF_SUPPORT == STD_ON)
        DEM_EVENT_CSFF(i) = DEM_DATA_CLEAR;
#endif
#if(DEM_EVENT_FCSLC_SUPPORT == STD_ON)
        DEM_EVENT_FCSLC(i) = DEM_DATA_CLEAR;
#endif
        DEM_EVENT_STATUS(i) = DEM_STATUS_RESET;
        /*Only use for Combination Event*/
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
        DEM_EVENT_AGINGCNT(i) = DEM_DATA_CLEAR;
        DEM_EVENT_DATAENTRYREF(i) = DEM_DATA_INVALID_U8;
#endif
#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
        DEM_EVEVT_PRESTO_FF_ENTRY(i) = DEM_DATA_INVALID_U8;
#endif

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
        DEM_EVENT_OBD_PCSLF(i) = DEM_DATA_CLEAR;
#endif
#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
        DEM_EVENT_OBD_CLEAR_FLAG(i) = FALSE;
#endif
#if(STD_ON == DEM_CMA_PLATFORM_ENABLED)
        DEM_EVENT_CMA_PCSLF(i) = DEM_DATA_CLEAR;
        DEM_EVENT_CMA_STATUS(i) = DEM_DATA_CLEAR;
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
        if(DEM_CFG_EVENT_DTCREF(i) != DEM_DATA_INVALID_U16)
        {
            if(DEM_DTC_IS_OBD(DEM_CFG_EVENT_DTCREF(i)))
            {
                DEM_EVENT_CMA_STATUS(i) = (uint8)0x40;
            }
        }
#endif
#endif
    }

#if(DEM_CFG_MAXNUMBER_PRESTOREDFF > 0)
    for(i = (uint16)0; i < (uint16)DEM_CFG_MAXNUMBER_PRESTOREDFF; i++)
    {
        DEM_PRESTORE_FFENTRY_EVENTID(i) = DEM_DATA_CLEAR;
        DEM_PRESTORE_FFENTRY_USED(i) = FALSE;
        for(j = (uint16)0; j < (uint16)DEM_MAX_FFSIZE_OF_DTC; j++)
        {
            DEM_PRESTORE_FFENTRY(i).PreStorageFFData[j] = DEM_DATA_CLEAR;
        }
    }
#endif
    for(i = (uint16)0; i < (uint16)DEM_NUM_OF_DTC; i++)
    {
        DEM_DTC_STATUS(i) = DEM_STATUS_RESET;
#if(DEM_DTC_LASTSTATUS_SUPPORT == STD_ON)
        DEM_DTC_LASTSTATUS(i) = DEM_STATUS_RESET;
#endif
        DEM_DTC_AGINGCNT(i) = DEM_DATA_CLEAR;
#if(DEM_DTC_AGEDCNT_SUPPORT == STD_ON)
        DEM_DTC_AGEDCNT(i) = DEM_DATA_CLEAR;
#endif
        DEM_DTC_DATAENTRYREF(i) = DEM_DATA_INVALID_U8;
#if(DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONRETRIEVAL)
        DEM_DTC_DATAENTRYREF_NUM(i) = DEM_DATA_CLEAR;
#endif
#if(DEM_EVENT_COMBINATION_SUPPORT != DEM_EVCOMB_DISABLED)
        if(DEM_IS_COMBINEDDTC(i))
        {
            DEM_EVCOMB_FDC(i) = (sint8)DEM_DATA_CLEAR;
        }
#endif
    }

    for(EventMemId = (uint8)0; EventMemId < DEM_NUM_OF_EVENTMEMORYSET; EventMemId++)
    {
        DEM_PRIMARY_DATAENTRY_USEDNUM(EventMemId) = DEM_DATA_CLEAR;

        for(k = (Dem_MemIdType)0; k < DEM_CFG_MAXNUMBEREVENTENTRY_PRIMARY(EventMemId); k++)
        {
            DemInternal_ClearOneMemoryEntry(EventMemId, k, DEM_PRIMARY_MEMORY);
        }

        /*User defined memory clear*/
#if(DEM_NUM_OF_USERDEF > 0)
        for(i = (uint16)0; i < (uint16)DEM_NUM_OF_USERDEF; i++ )
        {

            DEM_USER_DEFINED_DATAENTRY_USEDNUM(EventMemId,i) = DEM_DATA_CLEAR;
            for(k = (Dem_MemIdType)0; k < DEM_CFG_MAXNUMBEREVENTENTRY_USERDEFINED(i); k++)
            {
                DemInternal_ClearOneMemoryEntry(EventMemId,k,(uint8)i);
            }
        }
#endif

#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)
        DEM_PERMANENT_DATAENTRY_USEDNUM(EventMemId) = DEM_DATA_CLEAR;

        for(i = (uint16)0; i < DEM_CFG_MAXNUMBEREVENTENTRY_PERMANENT(EventMemId); i++)
        {
            DEM_PERMANENT_DATAENTRY_EVENTID(EventMemId, i) = DEM_EVENT_ID_INVALID;
        }
#endif/*#if(DEM_MAX_NUMBER_EVENTENTRY_PERMANENT > 0)*/
    }
#if(DEM_NUM_OF_INDICATOR > 0)
    for(i = (uint16)0; i < DEM_NUM_OF_BYTE_RECORD_INDICATOR_STATE; i++)
    {
        DEM_INDICATOR_STATUS(i) = DEM_INDICATOR_OFF;
    }
#endif

#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    DemInternal_InitOBDData();
#endif

    return E_OK;
}

#if(STD_ON == DEM_NVM_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DEM_CODE) Dem_NvM_JobResultInd
(
    uint8 ServiceId,
    NvM_RequestResultType JobResult
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(((ServiceId == NVM_JOB_READ) || (ServiceId == NVM_JOB_READALL)) \
            && (JobResult != NVM_REQ_OK))
    {
        Result = Dem_NvM_InitStorageMem();
    }
    return Result;
}
#endif

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"



/*******************************************************************************
*   Dem_J1939Dcm
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/*******************************************************************************
* Access DTCs and Status Information
*******************************************************************************/
#if(STD_ON == DEM_CFG_J1939READING_DTC_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmSetDTCFilter
*
* Description: The function sets the DTC filter for a specific node and returns
*              the composite lamp status of the filtered DTCs.
*
* Inputs: DTCStatusFilter,DTCKind,node
*
* Outputs: LampStatus
*
* Return: Dem_ReturnSetFilterType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00970*/
FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmSetDTCFilter
(
    Dem_J1939DcmDTCStatusFilterType DTCStatusFilter,
    Dem_DTCKindType DTCKind,
    Dem_DTCOriginType DTCOrigin,
    uint8 ClientId,
    P2VAR(Dem_J1939DcmLampStatusType, AUTOMATIC, DEM_APPL_DATA) LampStatus
)
{
	Std_ReturnType Result = E_OK;
    uint16 i;
    Dem_UdsStatusByteType DTCStatus;
    uint8 ParentMemId;
    uint16 TemplampSta = DEM_J1939_LAMP_UNAVAILABLE;
#if(DEM_NUM_OF_INDICATOR > 0)
    Dem_IndicatorStatusType IndicatorStatus;
#endif

#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_J1939DCMSETDTCFILTER_APIID, DEM_E_UNINIT);
        Result = DEM_WRONG_DTC;
    }
    else if(DTCStatusFilter > DEM_J1939DTC_CURRENTLY_ACTIVE)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMSETDTCFILTER_APIID, DEM_E_PARAM_DATA);
        Result = DEM_WRONG_DTC;
    }
    else if(DTCKind != DEM_DTC_KIND_ALL_DTCS)
    {
        /*Only support DM01 and DM02*/
        DEM_DET_REPORT_ERROR(DEM_J1939DCMSETDTCFILTER_APIID, DEM_E_PARAM_DATA);
        Result = DEM_WRONG_DTC;
    }
    else if(ClientId >= DEM_NUM_OF_CLIENT)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMSETDTCFILTER_APIID, DEM_E_PARAM_DATA);
        Result = DEM_WRONG_DTC;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {
        Result = E_NOT_OK;
    }
#endif
    else
    {
        ParentMemId = DEM_CLIENT_EVENT_MEM(ClientId);
        /*SWS_Dem_00855*//*SWS_Dem_00856*/
        Dem_J1939DcmFilterInfo[ClientId].DTCStatusFilter = DTCStatusFilter;
        Dem_J1939DcmFilterInfo[ClientId].DTCKind = DTCKind;
        Dem_J1939DcmFilterInfo[ClientId].DTCOrigin = DTCOrigin;
        Dem_J1939DcmFilterInfo[ClientId].NumberOfFilteredDTC = DEM_DATA_CLEAR;
        Dem_J1939DcmFilterInfo[ClientId].NextFilteredDTCIndex = DEM_DATA_CLEAR;
        Dem_J1939DcmFilterInfo[ClientId].FreezeFrameKind = DEM_DATA_INVALID_U8;
#if(((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))||(DEM_J1939_SUPPORT == STD_ON))
        /*Only support DM01 and DM02*/
        for(i = (uint16)0; i < DEM_NUM_OF_DTC; i++)
        {
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
            if(Dem_DTCSuppressionState[i] != TRUE)
#endif
        	{

	            if((DEM_CFG_DTC_OBDDTCREF(i) != NULL_PTR) && (DEM_CFG_DTC_J1939_VALUE(i) != (uint32)0))
	            {
	                DTCStatus = DEM_DTC_STATUS(i);
	                if((DTCStatusFilter == DEM_J1939DTC_ACTIVE) \
	                        && (DEM_TEST_UDS_STATUS_TF(DTCStatus)) \
	                        && (DEM_TEST_UDS_STATUS_CDTC(DTCStatus)))
	                {
	                    /*Request by DM01*/
	                    Dem_J1939DcmFilterInfo[ClientId].FilteredDTCIndexTable[Dem_J1939DcmFilterInfo[ClientId].NumberOfFilteredDTC] = i;
	                    Dem_J1939DcmFilterInfo[ClientId].NumberOfFilteredDTC++;
	                }
	                else if((DTCStatusFilter == DEM_J1939DTC_PREVIOUSLY_ACTIVE) \
	                        && (!DEM_TEST_UDS_STATUS_TF(DTCStatus)) \
	                        && (DEM_TEST_UDS_STATUS_CDTC(DTCStatus)))
	                {
	                    /*Request by DM02*/
	                    Dem_J1939DcmFilterInfo[ClientId].FilteredDTCIndexTable[Dem_J1939DcmFilterInfo[ClientId].NumberOfFilteredDTC] = i;
	                    Dem_J1939DcmFilterInfo[ClientId].NumberOfFilteredDTC++;
	                }
	                else
	                {
	                    /*do nothing*/
	                }
	            }
	        }
        }
#endif
        /*SWS_Dem_00857*/
#if(DEM_NUM_OF_INDICATOR > 0)
        TemplampSta = DEM_J1939_MIL_OFF;
        /*Returns a composite lamp status of MIL.*/
        if(DEM_CFG_MILINDICATORREF(ParentMemId) < (uint8)DEM_NUM_OF_INDICATOR)
        {
            DemInternal_GetIndicatorStatus(DEM_CFG_MILINDICATORREF(ParentMemId), &IndicatorStatus);

            if(IndicatorStatus != DEM_INDICATOR_OFF)
            {
                /*SWS_Dem_00858 MIL status should be ON*/
                TemplampSta |= DEM_J1939_MIL_ON;
            }

            if(IndicatorStatus == DEM_INDICATOR_SLOW_FLASH)
            {
                /*SWS_Dem_00860 Flash MIL status should be SlowFlash, no need change*/
            }
            else if(IndicatorStatus == DEM_INDICATOR_FAST_FLASH)
            {
                /*SWS_Dem_00861 Flash MIL status should be FastFlash.*/
                TemplampSta |= DEM_J1939_FMIL_FF;
            }
            else
            {
                /*SWS_Dem_00859 Flash MIL status should be Unavailable/DoNotFlash.*/
                TemplampSta |= DEM_J1939_FMIL_UNAVAILABLE;
            }
        }
        else
        {
            /*MIL is unavailable*/
            TemplampSta |= DEM_J1939_MIL_UNAVAILABLE;
            TemplampSta |= DEM_J1939_FMIL_UNAVAILABLE;
        }

        /*Returns a composite lamp status of Red Stop lamp.*/
        if(DEM_CFG_RED_LAMP_REF(ParentMemId) < (uint8)DEM_NUM_OF_INDICATOR)
        {
            DemInternal_GetIndicatorStatus(DEM_CFG_RED_LAMP_REF(ParentMemId), &IndicatorStatus);

            if(IndicatorStatus != DEM_INDICATOR_OFF)
            {
                /*SWS_Dem_00862 Red Stop lamp status should be ON*/
                TemplampSta |= DEM_J1939_RSL_ON;
            }

            if(IndicatorStatus == DEM_INDICATOR_SLOW_FLASH)
            {
                /*SWS_Dem_00864 Flash Red Stop lamp status should be SlowFlash, no need change*/
            }
            else if(IndicatorStatus == DEM_INDICATOR_FAST_FLASH)
            {
                /*SWS_Dem_00865 Flash Red Stop lamp status should be FastFlash.*/
                TemplampSta |= DEM_J1939_FRSL_FF;
            }
            else
            {
                /*SWS_Dem_00863 Flash Red Stop lamp status should be Unavailable/DoNotFlash.*/
                TemplampSta |= DEM_J1939_FRSL_UNAVAILABLE;
            }
        }
        else
        {
            /*Red Stop lamp is unavailable*/
            TemplampSta |= DEM_J1939_RSL_UNAVAILABLE;
            TemplampSta |= DEM_J1939_FRSL_UNAVAILABLE;
        }

        /*Returns a composite lamp status of Amber Warning lamp.*/
        if(DEM_CFG_AMBER_LAMP_REF(ParentMemId) < (uint8)DEM_NUM_OF_INDICATOR)
        {
            DemInternal_GetIndicatorStatus(DEM_CFG_AMBER_LAMP_REF(ParentMemId), &IndicatorStatus);

            if(IndicatorStatus != DEM_INDICATOR_OFF)
            {
                /*SWS_Dem_00866 Amber Warning lamp status should be ON*/
                TemplampSta |= DEM_J1939_AWL_ON;
            }

            if(IndicatorStatus == DEM_INDICATOR_SLOW_FLASH)
            {
                /*SWS_Dem_00868 Flash Amber Warning lamp status should be SlowFlash, no need change*/
            }
            else if(IndicatorStatus == DEM_INDICATOR_FAST_FLASH)
            {
                /*SWS_Dem_00869 Flash Amber Warning lamp status should be FastFlash.*/
                TemplampSta |= DEM_J1939_FAWL_FF;
            }
            else
            {
                /*SWS_Dem_00867 Flash Amber Warning lamp status should be Unavailable/DoNotFlash.*/
                TemplampSta |= DEM_J1939_FAWL_UNAVAILABLE;
            }
        }
        else
        {
            /*Amber Warning lamp is unavailable*/
            TemplampSta |= DEM_J1939_AWL_UNAVAILABLE;
            TemplampSta |= DEM_J1939_FAWL_UNAVAILABLE;
        }

        /*Returns a composite lamp status of Protect lamp.*/
        if(DEM_CFG_PROTECT_LAMP_REF(ParentMemId) < (uint8)DEM_NUM_OF_INDICATOR)
        {
            DemInternal_GetIndicatorStatus(DEM_CFG_PROTECT_LAMP_REF(ParentMemId), &IndicatorStatus);

            if(IndicatorStatus != DEM_INDICATOR_OFF)
            {
                /*SWS_Dem_00870 Protect lamp status should be ON*/
                TemplampSta |= DEM_J1939_PL_ON;
            }

            if(IndicatorStatus == DEM_INDICATOR_SLOW_FLASH)
            {
                /*SWS_Dem_00872 Flash Protect lamp status should be SlowFlash, no need change*/
            }
            else if(IndicatorStatus == DEM_INDICATOR_FAST_FLASH)
            {
                /*SWS_Dem_00873 Flash Protect lamp status should be FastFlash.*/
                TemplampSta |= DEM_J1939_FPL_FF;
            }
            else
            {
                /*SWS_Dem_00871 Flash Protect lamp status should be Unavailable/DoNotFlash.*/
                TemplampSta |= DEM_J1939_FPL_UNAVAILABLE;
            }
        }
        else
        {
            /*Protect lamp is unavailable*/
            TemplampSta |= DEM_J1939_PL_UNAVAILABLE;
            TemplampSta |= DEM_J1939_FPL_UNAVAILABLE;
        }
        LampStatus->lampStatus = (uint8)(TemplampSta >> (uint16)8);
        LampStatus->FlashlampStatus = (uint8)(TemplampSta);
#else
        TemplampSta = DEM_J1939_LAMP_UNAVAILABLE;
        LampStatus->LampStatus = (uint8)(TemplampSta >> 8);
        LampStatus->FlashLampStatus = (uint8)(TemplampSta);
#endif

        Dem_J1939DcmFilterInfo[ClientId].FilteredValidFlag = TRUE;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmGetNumberOfFilteredDTC
*
* Description: Gets the number of currently filtered DTCs set by the function
*              Dem_J1939DcmSetDTCFilter.
*
* Inputs: None
*
* Outputs: NumberOfFilteredDTC
*
* Return: Dem_ReturnGetNumberOfFilteredDTCType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00972*/
FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmGetNumberOfFilteredDTC
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredDTC,
    uint8 ClientId
)
{
    Std_ReturnType Result = E_OK;

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_J1939DCMGETNUMBEROFFILTEREDDTC_APIID, DEM_E_UNINIT);
        Result = DEM_NO_SUCH_ELEMENT;
    }
    else if(NumberOfFilteredDTC == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMGETNUMBEROFFILTEREDDTC_APIID, DEM_E_PARAM_POINTER);
        Result = DEM_NO_SUCH_ELEMENT;
    }
    else if(Dem_J1939DcmFilterInfo[ClientId].FilteredValidFlag != TRUE)
    {
        Result = DEM_NO_SUCH_ELEMENT;
    }
    else
    {
        /*SWS_Dem_00874*/
        *NumberOfFilteredDTC = Dem_J1939DcmFilterInfo[ClientId].NumberOfFilteredDTC;
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmGetNextFilteredDTC
*
* Description: Gets the next filtered J1939 DTC.
*
* Inputs: None
*
* Outputs: J1939DTC,OccurenceCounter
*
* Return: Dem_ReturnGetNextFilteredElementType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00973*/
FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmGetNextFilteredDTC
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) J1939DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter,
    uint8 ClientId
)
{
    Std_ReturnType Result = E_OK;
    uint16 DtcId;
    uint16 EventId;

    if((J1939DTC == NULL_PTR) || (OccurenceCounter == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMGETNEXTFILTEREDDTC_APIID, DEM_E_PARAM_POINTER);
        Result = DEM_BUFFER_TOO_SMALL;
    }
    else if(Dem_J1939DcmFilterInfo[ClientId].FilteredValidFlag != TRUE)
    {
        Result = DEM_NO_SUCH_ELEMENT;
    }
    else if(Dem_J1939DcmFilterInfo[ClientId].NextFilteredDTCIndex >= Dem_J1939DcmFilterInfo[ClientId].NumberOfFilteredDTC)
    {
        /*SWS_Dem_00875*/
        Dem_J1939DcmFilterInfo[ClientId].FilteredValidFlag = FALSE;
        Dem_J1939DcmFilterInfo[ClientId].NextFilteredDTCIndex = (uint16)0;
        Dem_J1939DcmFilterInfo[ClientId].NumberOfFilteredDTC = (uint16)0;

        Result = DEM_NO_SUCH_ELEMENT;
    }
    else
    {
#if(DEM_J1939_SUPPORT == STD_ON)
        /*SWS_Dem_00875*//*SWS_Dem_00877*/
        DtcId = Dem_J1939DcmFilterInfo[ClientId].FilteredDTCIndexTable[Dem_J1939DcmFilterInfo[ClientId].NextFilteredDTCIndex];
        *J1939DTC = DEM_CFG_DTC_J1939_VALUE(DtcId);
        DemInternal_J1939GetOccurrenceCounter(DtcId, OccurenceCounter);
        Dem_J1939DcmFilterInfo[ClientId].NextFilteredDTCIndex++;
#else
        Result = DEM_NO_SUCH_ELEMENT;
#endif
    }
    return Result;
}

#endif


/*******************************************************************************
* DTC storage
*******************************************************************************/
#if(STD_ON == DEM_CFG_J1939CLEAR_DTC_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmClearDTC
*
* Description: Clears active DTCs as well as previously active DTCs.
*
* Inputs: DTCTypeFilter,node
*
* Outputs: None
*
* Return: Std_ReturnType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00976*/
FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmClearDTC
(
    Dem_J1939DcmSetClearFilterType DTCTypeFilter,
    Dem_DTCOriginType DTCOrigin,
    uint8 ClientId
)
{
    Std_ReturnType Result = E_OK;
    uint16 i;
    Dem_UdsStatusByteType DTCStatus;

#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMCLEARDTC_APIID, DEM_E_UNINIT);
        Result = DEM_CLEAR_FAILED;
    }
    else if(DTCTypeFilter > DEM_J1939DTC_CLEAR_ACTIVE_AND_PREVIOUSLY_ACTIVE)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMCLEARDTC_APIID, DEM_E_PARAM_DATA);
        Result = DEM_CLEAR_FAILED;
    }
    else if(ClientId >= DEM_NUM_OF_CLIENT)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMCLEARDTC_APIID, DEM_E_PARAM_DATA);
        Result = DEM_CLEAR_FAILED;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {
        Result = E_NOT_OK;
    }
#endif
    /*SWS_Dem_01042*/
    else if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_IDLE)
    {
#if(DEM_CFG_CLEARDTCBEHAIOR != DEM_CLRRESP_VOLATILE)
        Dem_ClearDTC_DTC = (Dem_UdsDTCType)0;
        Dem_ClearDTC_DTCFormat = DEM_DTC_FORMAT_J1939;
        Dem_ClearDTC_DTCOrigin = DEM_DTC_ORIGIN_PRIMARY_MEMORY;
#endif
        /*SWS_Dem_00878*/
        for(i = (uint16)0; i < DEM_NUM_OF_DTC; i++)
        {
            DTCStatus = DEM_DTC_STATUS(i);
            if((DTCTypeFilter == DEM_J1939DTC_CLEAR_ACTIVE)\
                && (DEM_TEST_UDS_STATUS_TF(DTCStatus))\
                && (DEM_TEST_UDS_STATUS_CDTC(DTCStatus)))
            {
                /*SWS_Dem_00879*/
                /*Clear RAM info of one DTC*/
                (void)DemInternal_ClearOneDTC(i);
            }
            else if((DTCTypeFilter == DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE)\
                &&(!DEM_TEST_UDS_STATUS_TF(DTCStatus)) \
                && (DEM_TEST_UDS_STATUS_CDTC(DTCStatus)))
            {
                /*previously active DTC*/
                /*SWS_Dem_00879*/
                /*Clear RAM info of one DTC*/
                (void)DemInternal_ClearOneDTC(i);
            }
            else if((DTCTypeFilter == DEM_J1939DTC_CLEAR_ACTIVE_AND_PREVIOUSLY_ACTIVE)\
                && (DEM_TEST_UDS_STATUS_CDTC(DTCStatus)))
            {
                (void)DemInternal_ClearOneDTC(i);
            }
            else
            {
                /*do nothing*/
            }
        }

#if(DEM_CFG_CLEARDTCBEHAIOR == DEM_CLRRESP_VOLATILE)
        /*SWS_Dem_00570*/
        Result =E_OK;
#else
        Dem_ClearDTCState = DEM_IN_CLEAR_EVENT_MEM;
        Result = DEM_PENDING;
#endif/*(DEM_CFG_CLEARDTCBEHAIOR == DEM_CLRRESP_VOLATILE)*/

    }
#if(DEM_CFG_CLEARDTCBEHAIOR != DEM_CLRRESP_VOLATILE)
    else if((Dem_ClearDTC_DTC != (Dem_UdsDTCType)0) || (Dem_ClearDTC_DTCFormat != DEM_DTC_FORMAT_J1939) \
        || (Dem_ClearDTC_DTCOrigin != DEM_DTC_ORIGIN_PRIMARY_MEMORY))
    {
        Result = DEM_CLEAR_BUSY;
    }
#endif/*(DEM_CFG_CLEARDTCBEHAIOR == DEM_CLRRESP_VOLATILE)*/
    else
    {
        if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_OK)
        {
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_IDLE;
            Result = E_OK;
        }
        else if(Dem_ClearDTCState == DEM_IN_CLEAR_DTC_ERR)
        {
            Dem_ClearDTCState = DEM_IN_CLEAR_DTC_IDLE;
            Result = DEM_CLEAR_MEMORY_ERROR;
        }
        else
        {
            Result = DEM_PENDING;
        }
    }
    return Result;
}
#endif

#if((STD_ON == DEM_CFG_J1939EX_FF_SUPPORT)||(STD_ON == DEM_CFG_J1939_FF_SUPPORT))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmSetFreezeFrameFilter
*
* Description: The function sets the FreezeFrame filter for a specific node.
*
* Inputs: FreezeFrameKind,node
*
* Outputs: None
*
* Return: Std_ReturnType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00977*/
FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmSetFreezeFrameFilter
(
    Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind,
    uint8 ClientId
)
{
    Std_ReturnType Result = E_OK;

#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif

    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_J1939DCMSETFREEZEFRAMEFILTER_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if((FreezeFrameKind != DEM_J1939DCM_FREEZEFRAME)\
        && (FreezeFrameKind != DEM_J1939DCM_EXPANDED_FREEZEFRAME))
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMSETFREEZEFRAMEFILTER_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
    else if(ClientId >= DEM_NUM_OF_CLIENT)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMSETFREEZEFRAMEFILTER_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {
        Result = E_NOT_OK;
    }
#endif
    else
    {
        /*SWS_Dem_00899*/
        Dem_J1939DcmFilterFF[ClientId].NumberOfFilteredDTC = DEM_DATA_CLEAR;
        Dem_J1939DcmFilterFF[ClientId].NextFilteredDTCIndex = DEM_DATA_CLEAR;
        Dem_J1939DcmFilterFF[ClientId].FreezeFrameKind = FreezeFrameKind;
        Dem_J1939DcmFilterFF[ClientId].FilteredValidFlag = TRUE;

    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmGetNextFreezeFrame
*
* Description: Gets next freeze frame data. The function stores the data in
*              the provided DestBuffer.
*
* Inputs: DestBuffer,BufSize
*
* Outputs: J1939DTC,OccurenceCounter,DestBuffer,BufSize
*
* Return: Dem_ReturnGetNextFilteredElementType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00978*/
FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmGetNextFreezeFrame
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) J1939DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize,
    uint8 ClientId
)
{
    uint8 ParentMemId;
    uint16 i;
    uint16 FFDataSize = (uint16)0;
    Std_ReturnType Result = E_OK;
    Std_ReturnType ret = E_OK;
#if(DEM_CORE_NUMBER > 1)
    CoreIdType CoreId = Bmc_GetCoreId();
#endif
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_J1939DCMGETNEXTFREEZEFRAME_APIID, DEM_E_UNINIT);
        Result = E_NOT_OK;
    }
    else if((J1939DTC == NULL_PTR)\
        || (OccurenceCounter == NULL_PTR)\
        || (DestBuffer == NULL_PTR)\
        || (BufSize == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMGETNEXTFREEZEFRAME_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
    else if(ClientId >= DEM_NUM_OF_CLIENT)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMGETNEXTFREEZEFRAME_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
#if(DEM_CORE_NUMBER > 1)
    else if(CoreId != DEM_CLIENT_REF_CORE(ClientId))
    {
        Result = E_NOT_OK;
    }
#endif
    else if(Dem_J1939DcmFilterFF[ClientId].FilteredValidFlag != TRUE)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMGETNEXTFREEZEFRAME_APIID, DEM_E_PARAM_DATA);
        Result = E_NOT_OK;
    }
    else
    {
        ParentMemId = DEM_CLIENT_EVENT_MEM(ClientId);
        for(i = Dem_J1939DcmFilterFF[ClientId].NextFilteredDTCIndex; i < DEM_NUM_OF_DTC; i++)
        {
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
            if((DEM_CFG_DTC_OBDDTCREF(i) != NULL_PTR) && (DEM_CFG_DTC_J1939_VALUE(i) != (uint32)0)\
                && (ParentMemId == (uint8)DEM_GET_EVENTMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(i)))\
                && (Dem_DTCSuppressionState[i] != TRUE))
#else
            if((DEM_CFG_DTC_OBDDTCREF(i) != NULL_PTR) && (DEM_CFG_DTC_J1939_VALUE(i) != (uint32)0)\
                && (ParentMemId == (uint8)DEM_GET_EVENTMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(i))))
#endif
            {
#if(STD_ON == DEM_CFG_J1939_FF_SUPPORT)
                if((Dem_J1939DcmFilterFF[ClientId].FreezeFrameKind ==  DEM_J1939DCM_FREEZEFRAME) \
                        && (DEM_CFG_J1939DTC_FFRECNUMCLASSREF(i) != NULL_PTR)
                        && (DEM_DTC_DATAENTRYREF(i) != DEM_DATA_INVALID_U8))
                {
                    ret = DemInternal_J1939GetSizeOfFreezeFrame(i, &FFDataSize);
                    if((*BufSize >= FFDataSize) && (ret == E_OK))
                    {
                        *BufSize = FFDataSize;
                        DemInternal_J1939GetDataOfFreezeFrame(i,DestBuffer);
                        *J1939DTC = DEM_CFG_DTC_J1939_VALUE(i);
                        DemInternal_J1939GetOccurrenceCounter(i, OccurenceCounter);
                        Dem_J1939DcmFilterFF[ClientId].NextFilteredDTCIndex++;
                        break;
                    }
                    else if((*BufSize < FFDataSize) && (ret == E_OK))
                    {
                        Result = DEM_BUFFER_TOO_SMALL;
                        break;
                    }
                    else
                    {
                        Result = DEM_NO_SUCH_ELEMENT;
                    }
                }
#endif
#if(STD_ON == DEM_CFG_J1939EX_FF_SUPPORT)
                if((Dem_J1939DcmFilterFF[ClientId].FreezeFrameKind == DEM_J1939DCM_EXPANDED_FREEZEFRAME) \
                        && (DEM_CFG_1939DTC_EXPFFRECNUMCLASSREF(i) != NULL_PTR) \
                        && (DEM_DTC_DATAENTRYREF(i) != DEM_DATA_INVALID_U8))
                {
                    ret = DemInternal_J1939ExpGetSizeOfFreezeFrame(i, &FFDataSize);
                    if((*BufSize >= FFDataSize) && (ret == E_OK))
                    {
                        *BufSize = FFDataSize;
                        DemInternal_J1939ExpGetDataOfFreezeFrame(i,DestBuffer);
                        *J1939DTC = DEM_CFG_DTC_J1939_VALUE(i);
                        DemInternal_J1939GetOccurrenceCounter(i, OccurenceCounter);
                        Dem_J1939DcmFilterFF[ClientId].NextFilteredDTCIndex++;
                        break;
                    }
                    else if((*BufSize < FFDataSize) && (ret == E_OK))
                    {
                        Result = DEM_BUFFER_TOO_SMALL;
                        break;
                    }
                    else
                    {
                        Result = DEM_NO_SUCH_ELEMENT;
                    }
                }
#endif
            }
            Dem_J1939DcmFilterFF[ClientId].NextFilteredDTCIndex++;
        }
        if(Dem_J1939DcmFilterFF[ClientId].NextFilteredDTCIndex >= DEM_NUM_OF_DTC)
        {
            Dem_J1939DcmFilterFF[ClientId].NextFilteredDTCIndex = DEM_DATA_CLEAR;
            Result = DEM_NO_SUCH_ELEMENT;
        }
    }
    return Result;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_J1939GetSizeOfFreezeFrame
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_J1939GetSizeOfFreezeFrame
(
    uint16 DtcId,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_MAX_J1939FFSIZE_OF_DTC > 0)
    uint8 i;
    uint16 SPNIndex;
    uint16 DataIdx;
    uint8 DataSize;
    uint8 *DataBufferPtr;
    uint8 DTC_SubMemId;
    uint8 DTC_ParentMemId;
    DTC_ParentMemId = DEM_GET_EVENTMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId));
    DTC_SubMemId = DEM_GET_SUBMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId));


    *SizeOfFreezeFrame = (uint16)0;
    if(DTC_SubMemId == DEM_PRIMARY_MEMORY)
    {
        DataBufferPtr = DEM_PRIMARY_J1939DTC_FFDATA_PTR(DTC_ParentMemId, DEM_DTC_DATAENTRYREF(DtcId));
    }
#if(DEM_NUM_OF_USERDEF > 0)
    else
    {
        DataBufferPtr = DEM_USERDEFINED_J1939DTC_FFDATA_PTR(DTC_SubMemId, DEM_DTC_DATAENTRYREF(DtcId));
    }
#endif

    for(i = (uint8)0; i < DEM_CFG_J1939DTC_NUM_OF_FFSPNC(DtcId); i++)
    {
        SPNIndex = DEM_CFG_J1939DTC_FFSPNC_ARRAY(DtcId)[i];
        DataIdx = DEM_CFG_DATAARRAY_OF_FFSPN(SPNIndex);
        if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
        {
            DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
            /*SWS_Dem_00817*/
            *SizeOfFreezeFrame += (uint16)DataSize;
        }

        if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
        {
            DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
            *SizeOfFreezeFrame += (uint16)DataSize;
        }
    }

#else
    Result = DEM_NO_SUCH_ELEMENT;
#endif

    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DemInternal_J1939ExpGetSizeOfFreezeFrame
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DEM_CODE) DemInternal_J1939ExpGetSizeOfFreezeFrame
(
    uint16 DtcId,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
)
{
    Std_ReturnType Result = E_OK;
#if(DEM_MAX_J1939FFSIZE_OF_DTC > 0)
    uint8 i;
    uint16 SPNIndex;
    uint16 DataIdx;
    uint8 DataSize;
    uint8 *DataBufferPtr;
    uint8 DTC_SubMemId;
    uint8 DTC_ParentMemId;
    DTC_ParentMemId = DEM_GET_EVENTMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId));
    DTC_SubMemId = DEM_GET_SUBMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId));

    *SizeOfFreezeFrame = (uint16)0;
    if(DTC_SubMemId == DEM_PRIMARY_MEMORY)
    {
        DataBufferPtr = DEM_PRIMARY_J1939DTC_EXPFFDATA_PTR(DTC_ParentMemId, DEM_DTC_DATAENTRYREF(DtcId));
    }
#if(DEM_NUM_OF_USERDEF > 0)
    else
    {
        DataBufferPtr = DEM_USERDEFINED_J1939DTC_EXPFFDATA_PTR(DTC_SubMemId, DEM_DTC_DATAENTRYREF(DtcId));
    }
#endif

    for(i = (uint8)0; i < DEM_CFG_J1939DTC_NUM_OF_EXPFFSPNC(DtcId); i++)
    {
        SPNIndex = DEM_CFG_J1939DTC_EXPFFSPNC_ARRAY(DtcId)[i];
        DataIdx = DEM_CFG_DATAARRAY_OF_FFSPN(SPNIndex);
        if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
        {
            DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
            /*SWS_Dem_00817*/
            *SizeOfFreezeFrame += (uint16)DataSize;
        }

        if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
        {
            DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
            *SizeOfFreezeFrame += (uint16)DataSize;
        }
    }

#else
    Result = DEM_NO_SUCH_ELEMENT;
#endif

    return Result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:DemInternal_J1939GetDataOfFreezeFrame
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_J1939GetDataOfFreezeFrame
(
    uint16 DtcId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer
)
{
#if(DEM_MAX_J1939FFSIZE_OF_DTC > 0)
    uint8 i;
    uint8 DataIdx;
    uint8 DataSize;
    uint8 *SrcBufferPtr;
    uint16 SPNIndex;
    uint8 DTC_SubMemId;
    uint8 DTC_ParentMemId;
    DTC_ParentMemId = DEM_GET_EVENTMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId));
    DTC_SubMemId = DEM_GET_SUBMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId));
    if(DTC_SubMemId == DEM_PRIMARY_MEMORY)
    {
        SrcBufferPtr = DEM_PRIMARY_J1939DTC_FFDATA_PTR(DTC_ParentMemId, DEM_DTC_DATAENTRYREF(DtcId));
    }
    else
    {
        SrcBufferPtr = DEM_USERDEFINED_J1939DTC_FFDATA_PTR(DTC_SubMemId, DEM_DTC_DATAENTRYREF(DtcId));
    }

    for(i = (uint8)0; i < DEM_CFG_J1939DTC_NUM_OF_FFSPNC(DtcId); i++)
    {
        SPNIndex = DEM_CFG_J1939DTC_FFSPNC_ARRAY(DtcId)[i];
        DataIdx = DEM_CFG_DATAARRAY_OF_FFSPN(SPNIndex);
        if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
        {
            DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
            Bsw_MemCpy(DestBuffer, SrcBufferPtr, DataSize);
            DestBuffer += DataSize;
            SrcBufferPtr += DataSize;
        }
        if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
        {
            DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
            Bsw_MemCpy(DestBuffer, SrcBufferPtr, DataSize);
            DestBuffer += DataSize;
            SrcBufferPtr += DataSize;
        }
    }
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:DemInternal_J1939ExpGetDataOfFreezeFrame
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_J1939ExpGetDataOfFreezeFrame
(
    uint16 DtcId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer
)
{
#if(DEM_MAX_J1939EXPFFSIZE_OF_DTC > 0)
    uint8 i;
    uint8 DataIdx;
    uint8 DataSize;
    uint8 *SrcBufferPtr;
    uint16 SPNIndex;
    uint8 DTC_SubMemId;
    uint8 DTC_ParentMemId;
    DTC_ParentMemId = DEM_GET_EVENTMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId));
    DTC_SubMemId = DEM_GET_SUBMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId));
    if(DTC_SubMemId == DEM_PRIMARY_MEMORY)
    {
        SrcBufferPtr = DEM_PRIMARY_J1939DTC_EXPFFDATA_PTR(DTC_ParentMemId, DEM_DTC_DATAENTRYREF(DtcId));
    }
    else
    {
        SrcBufferPtr = DEM_USERDEFINED_J1939DTC_EXPFFDATA_PTR(DTC_SubMemId, DEM_DTC_DATAENTRYREF(DtcId));
    }

    for(i = (uint8)0; i < DEM_CFG_J1939DTC_NUM_OF_EXPFFSPNC(DtcId); i++)
    {
        SPNIndex = DEM_CFG_J1939DTC_EXPFFSPNC_ARRAY(DtcId)[i];
        DataIdx = DEM_CFG_DATAARRAY_OF_FFSPN(SPNIndex);
        if(DEM_CFG_DATA_IN_DATA(DataIdx) != NULL_PTR)
        {
            DataSize = DEM_CFG_DATA_IN_DATA_SIZE(DataIdx);
            Bsw_MemCpy(DestBuffer, SrcBufferPtr, DataSize);
            DestBuffer += DataSize;
            SrcBufferPtr += DataSize;
        }
        if(DEM_CFG_DATA_CS_DATA(DataIdx) != NULL_PTR)
        {
            DataSize = DEM_CFG_DATA_CS_DATA_SIZE(DataIdx);
            Bsw_MemCpy(DestBuffer, SrcBufferPtr, DataSize);
            DestBuffer += DataSize;
            SrcBufferPtr += DataSize;
        }
    }
#endif
}

#endif
#if(DEM_J1939_SUPPORT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:DemInternal_J1939GetOccurrenceCounter
*
* Description:
*
* Inputs:
*
* Outputs:
*
* Return:
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DEM_CODE) DemInternal_J1939GetOccurrenceCounter
(
    uint16 DtcId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter
)
{
    Dem_EventIdType EventId;
    for(EventId = (Dem_EventIdType)0; EventId < DEM_NUM_OF_EVENT; EventId++)
    {
        if(DEM_CFG_EVENT_DTCREF(EventId) == DtcId)
        {
            *OccurenceCounter = DEM_EVENT_OCCCTR(EventId);
            break;
        }
    }
    if(*OccurenceCounter >= (uint8)0x7F)
    {
        *OccurenceCounter = (uint8)0x7E;
    }
}
#endif
#if(STD_ON == DEM_CFG_J1939DM31_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmFirstDTCwithLampStatus
*
* Description: The function sets the filter to the first applicable DTC for the
*              DM31 response for a specific node.
*
* Inputs: node
*
* Outputs: None
*
* Return: None
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00974*/
FUNC(void, DEM_CODE) Dem_J1939DcmFirstDTCwithLampStatus
(
    uint8 ClientId
)
{
    uint16 i;
    uint16 DtcId;
    uint8 MemoryId;
    uint8 DTCMemoryId;
    uint8 j;
    boolean flag = FALSE;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_J1939DCMFIRSTDTCWITHLAMPSTATUS_APIID, DEM_E_UNINIT);
    }
    else if(ClientId >= DEM_NUM_OF_CLIENT)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMFIRSTDTCWITHLAMPSTATUS_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
        Dem_J1939DcmFilterDM31[ClientId].NumberOfFilteredEvent = (uint16)0;
        Dem_J1939DcmFilterDM31[ClientId].NextFilteredEventIndex = (uint16)0;
        Dem_J1939DcmFilterDM31[ClientId].FilteredValidFlag = TRUE;
        MemoryId = DEM_CLIENT_EVENT_MEM(ClientId);
#if(DEM_NUM_OF_INDICATOR > 0)
        for(i = (uint16)0 ; i < DEM_NUM_OF_EVENT; i++)
        {
            if((DEM_CFG_EVENT_INDICATOR_NUM(i) > (uint8)0) && (DEM_CFG_EVENT_DTCREF(i) != DEM_DATA_INVALID_U16))
            {
                for(j = (uint8)0; j < DEM_CFG_EVENT_INDICATOR_NUM(i); j++)
                {
                    if((DEM_CFG_EVENT_INDICATOR_ID(i,j) == DEM_CFG_MILINDICATORREF(MemoryId))\
                        || (DEM_CFG_EVENT_INDICATOR_ID(i,j) == DEM_CFG_RED_LAMP_REF(MemoryId))\
                        || (DEM_CFG_EVENT_INDICATOR_ID(i,j) == DEM_CFG_PROTECT_LAMP_REF(MemoryId))\
                        || (DEM_CFG_EVENT_INDICATOR_ID(i,j) == DEM_CFG_AMBER_LAMP_REF(MemoryId)))
                    {
                        flag = TRUE;
                        break;
                    }
                }
                DtcId = DEM_CFG_EVENT_DTCREF(i);
                DTCMemoryId = DEM_GET_EVENTMEMORY_ID(DEM_CFG_DTC_MEMORY_DESTINATION_REF(DtcId));
                if((DTCMemoryId == MemoryId)
                    && (DEM_CFG_DTC_OBDDTCREF(DtcId) != NULL_PTR)
                    && (DEM_CFG_DTC_J1939_VALUE(DtcId) != (uint32)0)
                    && (flag == TRUE))
                {
                    Dem_J1939DcmFilterDM31[ClientId].FilteredEventIndexTable[Dem_J1939DcmFilterDM31[ClientId].NumberOfFilteredEvent] = i;
                    Dem_J1939DcmFilterDM31[ClientId].NumberOfFilteredEvent++;
                }
                flag = FALSE;
            }
        }
#endif
    }

}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmGetNextDTCwithLampStatus
*
* Description: Gets the next filtered J1939 DTC for DM31 including current
*              LampStatus.
*
* Inputs: None
*
* Outputs: LampStatus,J1939DTC,OccurenceCounter
*
* Return: Dem_ReturnGetNextFilteredElementType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00975*/
FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmGetNextDTCwithLampStatus
(
    P2VAR(Dem_J1939DcmLampStatusType, AUTOMATIC, DEM_APPL_DATA) LampStatus,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) J1939DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) OccurenceCounter,
    uint8 ClientId
)
{
    Std_ReturnType Result = E_OK;
    uint16 DtcId;
    uint16 EventId;
    uint8 j;
    uint8 MemoryId;
    uint16 TemplampSta = DEM_J1939_LAMP_UNAVAILABLE;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_J1939DCMGETNEXTDTCWITHLAMPSTATUS_APIID, DEM_E_UNINIT);
    }
    else if(ClientId >= DEM_NUM_OF_CLIENT)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMGETNEXTDTCWITHLAMPSTATUS_APIID, DEM_E_PARAM_DATA);
    }
    else if((J1939DTC == NULL_PTR)\
        || (LampStatus == NULL_PTR)\
        || (OccurenceCounter == NULL_PTR))
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMGETNEXTDTCWITHLAMPSTATUS_APIID, DEM_E_PARAM_DATA);
    }
    else if(Dem_J1939DcmFilterDM31[ClientId].FilteredValidFlag == FALSE)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMGETNEXTDTCWITHLAMPSTATUS_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
#if(DEM_NUM_OF_INDICATOR > 0)
        MemoryId = DEM_CLIENT_EVENT_MEM(ClientId);
        if((Dem_J1939DcmFilterDM31[ClientId].NumberOfFilteredEvent > (uint16)0) \
            && (Dem_J1939DcmFilterDM31[ClientId].NextFilteredEventIndex < Dem_J1939DcmFilterDM31[ClientId].NumberOfFilteredEvent))
        {
            EventId = Dem_J1939DcmFilterDM31[ClientId].FilteredEventIndexTable[Dem_J1939DcmFilterDM31[ClientId].NextFilteredEventIndex];
            DtcId = DEM_CFG_EVENT_DTCREF(EventId);
            *J1939DTC = DEM_CFG_DTC_J1939_VALUE(DtcId);
            DemInternal_J1939GetOccurrenceCounter(DtcId, OccurenceCounter);
            TemplampSta = DEM_J1939_MIL_OFF;
            for(j = (uint8)0; j < DEM_CFG_EVENT_INDICATOR_NUM(EventId); j++)
            {
                /*PRQA S 715 ++*/
                if(DEM_CFG_EVENT_INDICATOR_ID(EventId,j) == DEM_CFG_MILINDICATORREF(MemoryId))
                {
                    if(DEM_TEST_UDS_STATUS_WIR(DEM_EVENT_STATUS(EventId)))
                    {
                        TemplampSta |= DEM_J1939_MIL_ON;
                        if(DEM_CFG_EVENT_INDICATOR_BEHAVIOUR(EventId,j) == DEM_INDICATOR_SLOW_FLASH)
                        {
                            /*SWS_Dem_00860 Flash MIL status should be SlowFlash, no need change*/
                        }
                        else if(DEM_CFG_EVENT_INDICATOR_BEHAVIOUR(EventId,j) == DEM_INDICATOR_FAST_FLASH)
                        {
                            /*SWS_Dem_00861 Flash MIL status should be FastFlash.*/
                            TemplampSta |= DEM_J1939_FMIL_FF;
                        }
                        else
                        {
                            /*SWS_Dem_00859 Flash MIL status should be Unavailable/DoNotFlash.*/
                            TemplampSta |= DEM_J1939_FMIL_UNAVAILABLE;
                        }
                    }
                    else
                    {
                        TemplampSta |= DEM_J1939_MIL_OFF;
                    }

                }
                if(DEM_CFG_EVENT_INDICATOR_ID(EventId,j) == DEM_CFG_RED_LAMP_REF(MemoryId))
                {
                    if(DEM_TEST_UDS_STATUS_WIR(DEM_EVENT_STATUS(EventId)))
                    {
                        TemplampSta |= DEM_J1939_RSL_ON;
                        if(DEM_CFG_EVENT_INDICATOR_BEHAVIOUR(EventId,j) == DEM_INDICATOR_SLOW_FLASH)
                        {
                            /*SWS_Dem_00860 Flash MIL status should be SlowFlash, no need change*/
                        }
                        else if(DEM_CFG_EVENT_INDICATOR_BEHAVIOUR(EventId,j) == DEM_INDICATOR_FAST_FLASH)
                        {
                            /*SWS_Dem_00861 Flash MIL status should be FastFlash.*/
                            TemplampSta |= DEM_J1939_FRSL_FF;
                        }
                        else
                        {
                            /*SWS_Dem_00859 Flash MIL status should be Unavailable/DoNotFlash.*/
                            TemplampSta |= DEM_J1939_FRSL_UNAVAILABLE;
                        }
                    }
                    else
                    {
                        TemplampSta |= DEM_J1939_RSL_OFF;
                    }
                }
                if(DEM_CFG_EVENT_INDICATOR_ID(EventId,j) == DEM_CFG_PROTECT_LAMP_REF(MemoryId))
                {
                    if(DEM_TEST_UDS_STATUS_WIR(DEM_EVENT_STATUS(EventId)))
                    {
                        TemplampSta |= DEM_J1939_PL_ON;
                        if(DEM_CFG_EVENT_INDICATOR_BEHAVIOUR(EventId,j) == DEM_INDICATOR_SLOW_FLASH)
                        {
                            /*SWS_Dem_00860 Flash MIL status should be SlowFlash, no need change*/
                        }
                        else if(DEM_CFG_EVENT_INDICATOR_BEHAVIOUR(EventId,j) == DEM_INDICATOR_FAST_FLASH)
                        {
                            /*SWS_Dem_00861 Flash MIL status should be FastFlash.*/
                            TemplampSta |= DEM_J1939_FPL_FF;
                        }
                        else
                        {
                            /*SWS_Dem_00859 Flash MIL status should be Unavailable/DoNotFlash.*/
                           TemplampSta |= DEM_J1939_FPL_UNAVAILABLE;
                        }
                    }
                    else
                    {
                        TemplampSta |= DEM_J1939_PL_OFF;
                    }

                }
                if(DEM_CFG_EVENT_INDICATOR_ID(EventId,j) == DEM_CFG_AMBER_LAMP_REF(MemoryId))
                {
                    if(DEM_TEST_UDS_STATUS_WIR(DEM_EVENT_STATUS(EventId)))
                    {
                        TemplampSta |= DEM_J1939_AWL_ON;
                        if(DEM_CFG_EVENT_INDICATOR_BEHAVIOUR(EventId,j) == DEM_INDICATOR_SLOW_FLASH)
                        {
                            /*SWS_Dem_00860 Flash MIL status should be SlowFlash, no need change*/
                        }
                        else if(DEM_CFG_EVENT_INDICATOR_BEHAVIOUR(EventId,j) == DEM_INDICATOR_FAST_FLASH)
                        {
                            /*SWS_Dem_00861 Flash MIL status should be FastFlash.*/
                            TemplampSta |= DEM_J1939_FAWL_FF;
                        }
                        else
                        {
                            /*SWS_Dem_00859 Flash MIL status should be Unavailable/DoNotFlash.*/
                            TemplampSta |= DEM_J1939_FAWL_UNAVAILABLE;
                        }
                    }
                    else
                    {
                        TemplampSta|= DEM_J1939_AWL_OFF;
                    }
                }
                /*PRQA S 715 --*/
            }
            LampStatus->LampStatus = (uint8)(TemplampSta >> DEM_UINT16_8);
            LampStatus->FlashLampStatus = (uint8)(TemplampSta);
            Dem_J1939DcmFilterDM31[ClientId].NextFilteredEventIndex++;
        }
        else
        {
            Result = DEM_NO_SUCH_ELEMENT;
            Dem_J1939DcmFilterDM31[ClientId].NumberOfFilteredEvent = (uint16)0;
        }
#endif
    }

    return Result;
}
#endif

/*******************************************************************************
* Reporting
*******************************************************************************/
#if(STD_ON == DEM_CFG_J1939_RATIO_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmSetRatioFilter
*
* Description: The function sets the Ratio filter for a specific node and
*              returns the corresponding Ignition Cycle Counter and General
*              Denominator.
*
* Inputs: node
*
* Outputs: IgnitionCycleCounter,OBDMonitoringConditionsEncountered
*
* Return: Dem_ReturnSetFilterType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00980*/
FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmSetRatioFilter
(
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) IgnitionCycleCounter,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) OBDMonitoringConditionsEncountered,
    uint8 ClientId
)
{
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmGetNextFilteredRatio
*
* Description: Gets the next filtered Ratio.
*
* Inputs: None
*
* Outputs: SPN,Numerator,Denominator
*
* Return: Dem_ReturnGetNextFilteredElementType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00981*/
FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmGetNextFilteredRatio
(
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) SPN,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Numerator,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Denominator,
    uint8 ClientId
)
{
}
#endif

#if(DEM_J1939_SUPPORT == STD_ON)
#if(STD_ON == DEM_CFG_J1939READINESS_1_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmReadDiagnosticReadiness1
*
* Description: Service to report the value of Diagnostic Readiness 1
*              (DM05) computed by the Dem.
*
* Inputs: node
*
* Outputs: DataValue
*
* Return: Std_ReturnType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00982*/
FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmReadDiagnosticReadiness1
(
    P2VAR(Dem_J1939DcmDiagnosticReadiness1Type, AUTOMATIC, DEM_APPL_DATA) DataValue,
    uint8 ClientId
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint16 i;
    uint8 NumberOfActiveDTC = (uint8)0 ;
    uint8 NumberOfPreviouslyActiveDTC = (uint8)0;
    Dem_UdsStatusByteType DTCStatus;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_J1939DCMREADDIAGNOSTICREADINESS1_APIID, DEM_E_UNINIT);
    }
    else if(ClientId >= DEM_NUM_OF_CLIENT)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMREADDIAGNOSTICREADINESS1_APIID, DEM_E_PARAM_DATA);
    }
    else if(DataValue == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMREADDIAGNOSTICREADINESS1_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
        for(i = (uint16)0; i < DEM_NUM_OF_DTC; i++)
        {
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
            if(Dem_DTCSuppressionState[i] != TRUE)
#endif
        	{
	            if((DEM_CFG_DTC_OBDDTCREF(i) != NULL_PTR) && (DEM_CFG_DTC_J1939_VALUE(i) != (uint32)0))
	            {
	                DTCStatus = DEM_DTC_STATUS(i);
	                if((DEM_TEST_UDS_STATUS_TF(DTCStatus)) \
	                    && (DEM_TEST_UDS_STATUS_CDTC(DTCStatus)))
	                {
	                    NumberOfActiveDTC++;
	                }
	                else if((!DEM_TEST_UDS_STATUS_TF(DTCStatus)) \
	                    && (DEM_TEST_UDS_STATUS_CDTC(DTCStatus)))
	                {
	                    NumberOfPreviouslyActiveDTC++;
	                }
	                else
	                {
	                    /*do nothing*/
	                }
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
                    if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_CMPRCMPT)
                    {
                        DataValue->ContinuouslyMonitoredSystemsSupport_Status |= (uint8)0x04;
                        if(DEM_TEST_UDS_STATUS_TNCSLC(DTCStatus))
                        {
                            DataValue->ContinuouslyMonitoredSystemsSupport_Status |= (uint8)0x40;
                        }
                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_FLSYS)
                    {
                        DataValue->ContinuouslyMonitoredSystemsSupport_Status |= (uint8)0x02;
                        if(DEM_TEST_UDS_STATUS_TNCSLC(DTCStatus))
                        {
                            DataValue->ContinuouslyMonitoredSystemsSupport_Status |= (uint8)0x20;
                        }

                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_MISF)
                    {
                        DataValue->ContinuouslyMonitoredSystemsSupport_Status |= (uint8)0x01;
                        if(DEM_TEST_UDS_STATUS_TNCSLC(DTCStatus))
                        {
                            DataValue->ContinuouslyMonitoredSystemsSupport_Status |= (uint8)0x10;
                        }
                    }
                    else if((DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_EGR)\
                        || (DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_VVT))
                    {
                        DataValue->NonContinuouslyMonitoredSystemsSupport5 |= (uint8)0x80;
                        if(DEM_TEST_UDS_STATUS_TNCSLC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystemsStatus7 |= (uint8)0x80;
                        }
                    }

#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_SPARK)
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_AC)
                    {
                        DataValue->NonContinuouslyMonitoredSystemsSupport5 |= (uint8)0x10;
                        if(DEM_TEST_UDS_STATUS_TNCSLC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystemsStatus7 |= (uint8)0x10;
                        }

                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_SECAIR)
                    {
                        DataValue->NonContinuouslyMonitoredSystemsSupport5 |= (uint8)0x08;
                        if(DEM_TEST_UDS_STATUS_TNCSLC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystemsStatus7 |= (uint8)0x08;
                        }
                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_EVAP)
                    {
                        DataValue->NonContinuouslyMonitoredSystemsSupport5 |= (uint8)0x04;
                        if(DEM_TEST_UDS_STATUS_TNCSLC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystemsStatus7 |= (uint8)0x04;
                        }
                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_HTCAT)
                    {
                        DataValue->NonContinuouslyMonitoredSystemsSupport5 |= (uint8)0x02;
                        if(DEM_TEST_UDS_STATUS_TNCSLC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystemsStatus7 |= (uint8)0x02;
                        }
                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_CAT)
                    {
                        DataValue->NonContinuouslyMonitoredSystemsSupport5 |= (uint8)0x01;
                        if(DEM_TEST_UDS_STATUS_TNCSLC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystemsStatus7 |= (uint8)0x01;
                        }
                    }
#endif
#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_COMPRESSION)
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_HCCAT)
                    {
                        DataValue->NonContinuouslyMonitoredSystemsSupport6 |= (uint8)0x10;
                        if(DEM_TEST_UDS_STATUS_TNCSLC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystemsStatus8 |= (uint8)0x10;
                        }
                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_NOXCAT)
                    {
                        DataValue->NonContinuouslyMonitoredSystemsSupport6 |= (uint8)0x08;
                        if(DEM_TEST_UDS_STATUS_TNCSLC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystemsStatus8 |= (uint8)0x08;
                        }

                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_BOOSTPR)
                    {
                        DataValue->NonContinuouslyMonitoredSystemsSupport6 |= (uint8)0x02;
                        if(DEM_TEST_UDS_STATUS_TNCSLC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystemsStatus8 |= (uint8)0x02;
                        }

                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_EGSENS)
                    {
                        DataValue->NonContinuouslyMonitoredSystemsSupport5 |= (uint8)0x20;
                        if(DEM_TEST_UDS_STATUS_TNCSLC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystemsStatus7 |= (uint8)0x20;
                        }
                    }
#endif
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_CSER)
                    {
                        DataValue->NonContinuouslyMonitoredSystemsSupport6 |= (uint8)0x01;
                        if(DEM_TEST_UDS_STATUS_TNCSLC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystemsStatus8 |= (uint8)0x01;
                        }
                    }
                    else
	                {
	                    /*do nothing*/
	                }
#endif
	            }
	        }
        }
        DataValue->ActiveTroubleCodes = NumberOfActiveDTC;
        DataValue->PreviouslyActiveDiagnosticTroubleCodes = NumberOfPreviouslyActiveDTC;
#if(DEM_CFG_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
        DataValue->OBDCompliance = DEM_CFG_OBD_COMPLIANCY;
#else
        DataValue->OBDCompliance = DEM_UINT8_5;
#endif
        Result = E_OK;
    }
    return Result;
}
#endif


#if(STD_ON == DEM_CFG_J1939READINESS_2_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmReadDiagnosticReadiness2
*
* Description: Service to report the value of Diagnostic Readiness 2
*              (DM21) computed by the Dem.
*
* Inputs: node
*
* Outputs: DataValue
*
* Return: Std_ReturnType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00983*/
FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmReadDiagnosticReadiness2
(
    P2VAR(Dem_J1939DcmDiagnosticReadiness2Type, AUTOMATIC, DEM_APPL_DATA) DataValue,
    uint8 ClientId
)
{
    Std_ReturnType ret = E_NOT_OK;
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_J1939DCMREADDIAGNOSTICREADINESS2_APIID, DEM_E_UNINIT);
    }
    else if(ClientId >= DEM_NUM_OF_CLIENT)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMREADDIAGNOSTICREADINESS2_APIID, DEM_E_PARAM_DATA);
    }
    else if(DataValue == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMREADDIAGNOSTICREADINESS2_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
        if(DEM_CFG_OBD_EVENT_MEMORY_REF == DEM_CLIENT_EVENT_MEM(ClientId))
        {
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
            DataValue->DistanceTraveledWhileMILisActivated = (uint16)(DEM_OBD_DISTANCE_MILACTIVATED/1000);
            DataValue->DistanceSinceDTCsCleared = (uint16)(DEM_OBD_DISTANCE_SINCEDTCCLEARED/1000);
            DataValue->MinutesRunbyEngineWhileMILisActivated = (DEM_OBD_ENGINERUN_MILACTIVATED/60);
            DataValue->TimeSinceDiagnosticTroubleCodesCleared = (DEM_OBD_ENGINERUN_SINCEDTCCLEARED/60);
#endif
            ret = E_OK;
        }
    }
    return ret;
}
#endif

#if(STD_ON == DEM_CFG_J1939READINESS_3_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dem_J1939DcmReadDiagnosticReadiness3
*
* Description: Service to report the value of Diagnostic Readiness 3
*              (DM26) computed by the Dem.
*
* Inputs: node
*
* Outputs: DataValue
*
* Return: Std_ReturnType
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Dem_00770*/
FUNC(Std_ReturnType, DEM_CODE) Dem_J1939DcmReadDiagnosticReadiness3
(
    P2VAR(Dem_J1939DcmDiagnosticReadiness3Type, AUTOMATIC, DEM_APPL_DATA) DataValue,
    uint8 ClientId
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
    Dem_UdsStatusByteType DTCStatus;
    uint8 BytePos;
    uint8 BitPos;
#endif
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
    uint16 i;
    uint8 SinceEngineStartDataId = (uint8)0;
#endif
    if(DEM_GET_STATE != DEM_NORMAL)
    {
        /*SWS_Dem_01112*//*SWS_Dem_00124*/
        DEM_DET_REPORT_ERROR(DEM_J1939DCMREADDIAGNOSTICREADINESS3_APIID, DEM_E_UNINIT);
    }
    else if(ClientId >= DEM_NUM_OF_CLIENT)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMREADDIAGNOSTICREADINESS3_APIID, DEM_E_PARAM_DATA);
    }
    else if(DataValue == NULL_PTR)
    {
        DEM_DET_REPORT_ERROR(DEM_J1939DCMREADDIAGNOSTICREADINESS3_APIID, DEM_E_PARAM_DATA);
    }
    else
    {
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))

        if((DEM_CFG_OBD_TIME_SINCE_ENGINE_START != DEM_DATA_INVALID_U8) \
            && (DEM_CFG_DATA_CS_DATA(DEM_CFG_OBD_TIME_SINCE_ENGINE_START) != NULL_PTR))
        {
            /*SWS_Dem_00282*//*SWS_Dem_00918*//*SWS_Dem_00919*//*SWS_Dem_00920*/
            ret = (*DEM_CFG_DATA_CS_DATA_READ_FNC(DEM_CFG_OBD_TIME_SINCE_ENGINE_START))(DataValue->TimeSinceEngineStart);
            /*SWS_Dem_00463*/
            if(ret != E_OK)
            {
                /*SWS_Dem_00370*/
                DEM_DET_REPORT_ERROR(DEM_J1939DCMREADDIAGNOSTICREADINESS3_APIID, DEM_E_NODATAAVAILABLE);
            }
        }
        DataValue->NumberofWarmupsSinceDTCsCleared = DEM_OBD_NUMWARMUP_SINCEDTCCLEARED;
        for(i = (uint16)0; i < DEM_NUM_OF_DTC; i++)
        {
#if(DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
            if(Dem_DTCSuppressionState[i] != TRUE)
#endif
        	{
	            if((DEM_CFG_DTC_OBDDTCREF(i) != NULL_PTR) && (DEM_CFG_DTC_J1939_VALUE(i) != (uint32)0))
	            {
#if(DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
                    DTCStatus = DEM_DTC_STATUS(i);
                    BytePos = (DEM_CFG_DTC_OBD_READINESSGROUP(i) / (Dem_EventOBDReadinessGroupType)8);
                    BitPos = (DEM_CFG_DTC_OBD_READINESSGROUP(i) % (Dem_EventOBDReadinessGroupType)8);
                    if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_CMPRCMPT)
                    {
                        if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) != (uint8)0)
                        {
                            DataValue->ContinuouslyMonitoredSystemsEnableCompletedStatus |= (uint8)0x04;
                        }

                        if(DEM_TEST_UDS_STATUS_TNCTOC(DTCStatus))
                        {
                            DataValue->ContinuouslyMonitoredSystemsEnableCompletedStatus |= (uint8)0x40;
                        }
                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_FLSYS)
                    {
                        if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) != (uint8)0)
                        {
                            DataValue->ContinuouslyMonitoredSystemsEnableCompletedStatus |= (uint8)0x02;
                        }
                        if(DEM_TEST_UDS_STATUS_TNCTOC(DTCStatus))
                        {
                            DataValue->ContinuouslyMonitoredSystemsEnableCompletedStatus |= (uint8)0x20;
                        }

                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_MISF)
                    {
                        if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) != (uint8)0)
                        {
                            DataValue->ContinuouslyMonitoredSystemsEnableCompletedStatus |= (uint8)0x01;
                        }
                        if(DEM_TEST_UDS_STATUS_TNCTOC(DTCStatus))
                        {
                            DataValue->ContinuouslyMonitoredSystemsEnableCompletedStatus |= (uint8)0x10;
                        }
                    }
                    else if((DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_EGR)\
                        || (DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_VVT))
                    {
                        if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) != (uint8)0)
                        {
                            DataValue->NonContinuouslyMonitoredSystemsEnableStatus5 |= (uint8)0x80;
                        }
                        if(DEM_TEST_UDS_STATUS_TNCTOC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystems7 |= (uint8)0x80;
                        }
                    }
#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_SPARK)
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_AC)
                    {
                        if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) != (uint8)0)
                        {
                            DataValue->NonContinuouslyMonitoredSystemsEnableStatus5 |= (uint8)0x10;
                        }
                        if(DEM_TEST_UDS_STATUS_TNCTOC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystems7 |= (uint8)0x10;
                        }

                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_SECAIR)
                    {
                        if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) != (uint8)0)
                        {
                            DataValue->NonContinuouslyMonitoredSystemsEnableStatus5 |= (uint8)0x08;
                        }
                        if(DEM_TEST_UDS_STATUS_TNCTOC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystems7 |= (uint8)0x08;
                        }
                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_EVAP)
                    {

                        if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) != (uint8)0)
                        {
                            DataValue->NonContinuouslyMonitoredSystemsEnableStatus5 |= (uint8)0x04;
                        }
                        if(DEM_TEST_UDS_STATUS_TNCTOC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystems7 |= (uint8)0x04;
                        }
                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_HTCAT)
                    {
                        if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) != (uint8)0)
                        {
                            DataValue->NonContinuouslyMonitoredSystemsEnableStatus5 |= (uint8)0x02;
                        }
                        if(DEM_TEST_UDS_STATUS_TNCTOC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystems7 |= (uint8)0x02;
                        }
                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_CAT)
                    {
                        if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) != (uint8)0)
                        {
                            DataValue->NonContinuouslyMonitoredSystemsEnableStatus5 |= (uint8)0x01;
                        }
                        if(DEM_TEST_UDS_STATUS_TNCTOC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystems7 |= (uint8)0x01;
                        }
                    }
#endif
#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_COMPRESSION)
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_HCCAT)
                    {
                        if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) != (uint8)0)
                        {
                            DataValue->NonContinuouslyMonitoredSystemsEnableStatus6 |= (uint8)0x10;
                        }
                        if(DEM_TEST_UDS_STATUS_TNCTOC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystems8 |= (uint8)0x10;
                        }
                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_NOXCAT)
                    {
                        if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) !=(uint8)0)
                        {
                            DataValue->NonContinuouslyMonitoredSystemsEnableStatus6 |= (uint8)0x08;
                        }
                        if(DEM_TEST_UDS_STATUS_TNCTOC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystems8 |= (uint8)0x08;
                        }

                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_BOOSTPR)
                    {
                        if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) != (uint8)0)
                        {
                            DataValue->NonContinuouslyMonitoredSystemsEnableStatus6 |= (uint8)0x02;
                        }
                        if(DEM_TEST_UDS_STATUS_TNCTOC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystems8 |= (uint8)0x02;
                        }

                    }
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_EGSENS)
                    {

                        if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) != (uint8)0)
                        {
                            DataValue->NonContinuouslyMonitoredSystemsEnableStatus5 |= (uint8)0x20;
                        }
                        if(DEM_TEST_UDS_STATUS_TNCTOC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystems7 |= (uint8)0x20;
                        }
                    }
#endif
                    else if(DEM_CFG_DTC_OBD_READINESSGROUP(i) == DEM_OBD_RDY_CSER)
                    {
                        if((DEM_OBD_READINESSGROUP_STATUS[BytePos] & ((uint8)0x01 << BitPos)) != (uint8)0)
                        {
                            DataValue->NonContinuouslyMonitoredSystemsEnableStatus6 |= (uint8)0x01;
                        }
                        if(DEM_TEST_UDS_STATUS_TNCTOC(DTCStatus))
                        {
                            DataValue->NonContinuouslyMonitoredSystems8 |= (uint8)0x01;
                        }
                    }
                    else
	                {
	                    /*do nothing*/
	                }
#endif
                }
            }
        }
#endif
        ret = E_OK;
    }
    return ret;
}
#endif
#endif

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"



