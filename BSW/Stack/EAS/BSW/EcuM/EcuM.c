/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EcuM.c
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : The ECU state manager
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of EcuM module.
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------- ----------   ---------------
*   04.00.00    13/10/2023    Chaolimen.han N/A          Original
*   04.00.01    06/02/2024    Chaolimen.han N/A          Original
*   04.00.02    26/03/2024    Chaolimen.han N/A          EAS470_EcuM_20240326_01
*   04.00.03    05/06/2024    Chaolimen.han N/A          EAS470_EcuM_20240605_01
*   04.00.04    10/07/2024    Chaolimen.han N/A          EAS470_EcuM_20240710_01
*   04.00.05    22/09/2024    Chaolimen.han N/A          EAS470_EcuM_20240922_01
*   04.00.06    20/03/2025    Chaolimen.han N/A          EAS470_EcuM_20250320_01
********************************************************************************
********************************************************************************
* END_FILE_HDR*/

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 5087,3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "EcuM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in EcuM_MemMap.h
*/

/*PRQA S 3453,3429,857,380 EOF*/
/*
1.The unified requirement of EAS is that the error reporting functions of Det
and Dem moduls are accessed by macro functions.This part has been verified and
has no problem.
2.Macro functions are allowed to use to access parameters and do some simple operations.
3.Macro definitions exceed 1024.The number of macros is unlimited
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

/* S 3416 EOF*/
/*
There's no error when only one branch,but in a statement with &&,|| or multiple
branches,calling a function to determine the return value is not allowed.
*/

/*PRQA S 3212,3227,3204 EOF*/
/*
Unified requirements of EAS: constant shall be converted.
Read-only function input parameters may not be defined as const,it does not affect the function.
AUTOSAR API shall define standard input parameters according to specification requirements
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

/*PRQA S 2100,2101,2000 EOF*/
/*
Integer promotion related
*/
/*****************************************************************************
 *  EcuM QAC Suppression
 *****************************************************************************/
/*PRQA S 4640 EOF*/
/*
This waring is a false position. The 'errno.h' header file will not be used by the
EcuM module.
*/

/*PRQA S 3218 EOF*/
/*
This waring is a false position. The 'errno.h' header file will not be used by the
EcuM module.
*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Mcu.h"
#include "EcuM.h"
#include "BswM.h"
#include "BswM_EcuM.h"
#include "Rte_EcuM.h"
#include "SchM.h"
#if(ECUM_CORE_NUMBER > 1)
#if(ECUM_OS_USED == STD_ON)
#include "Os_Types.h"
#else
#include "Bmc.h"
#endif
#endif

#if(ECUM_COMM_WAKEUP_NOTIFICATION == STD_ON)
#include "ComM.h"
#include "ComM_EcuM.h"
#endif

#if(ECUM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(STD_ON == ECUM_VERSION_CHECK)

#if(ECUM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#error "The EcuM module only supports the Post-build Configuration. See SWS_EcuM_03007"
#endif

#if((ECUM_SW_MAJOR_VERSION != ECUM_SW_MAJOR_VERSION_CFG) \
    || (ECUM_SW_MINOR_VERSION != ECUM_SW_MINOR_VERSION_CFG))
#error "The version of EcuM_Version.h is NOT compatible with the EcuM_Cfg.h file."
#endif

#if(ECUM_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION_CFG)
#error "AUTOSAR Version Numbers of EcuM and its cfg file are different."
#endif

#if((ECUM_AR_RELEASE_MINOR_VERSION_422 != ECUM_AR_RELEASE_MINOR_VERSION_CFG) \
    && (ECUM_AR_RELEASE_MINOR_VERSION_431 != ECUM_AR_RELEASE_MINOR_VERSION_CFG) \
    && (ECUM_AR_RELEASE_MINOR_VERSION_440 != ECUM_AR_RELEASE_MINOR_VERSION_CFG)\
    && (ECUM_AR_RELEASE_MINOR_VERSION_470 != ECUM_AR_RELEASE_MINOR_VERSION_CFG))
#error "AUTOSAR Version Numbers of EcuM and its cfg file are different."
#endif

#if(ECUM_WKSOURCE_NUMBER < 5)
#error "The number of default wakeup source is five."
#endif

#if((ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_OFF) && (ECUM_ALARM_CLOCK_PRESENT == STD_ON))
#error "If the SLEEP is not supported, the alarm clock must be OFF."
#endif

#if((ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_OFF) && (ECUM_WAKEUPSOURCE_VALIDATION == STD_ON))
#error "If the SLEEP is not supported, there is not wakeup source can be validated."
#endif

#if((ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_OFF) && (ECUM_SLEEP_POLLING_MODE == STD_ON))
#error "If the SLEEP is not supported, there is not wakeup source can be polled."
#endif

#if((ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON) && (ECUM_SLEEP_MODE_NUMBER == 0))
#error "If the SLEEP is supported, the number of sleep mode must be greater than Zero."
#endif

#if((ECUM_ALARM_CLOCK_PRESENT == STD_ON) && (ECUM_ALARM_CLOCK_NUMBER == 0))
#error "If the alarm clock is present, the number of alarm clock must be greater than Zero."
#endif

#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
/*PRQA S 4588 ++*/
/*To implement the bit mainpulation of the autosar specific requirements (sws_ecum_04088), no change is required  */
#if((ECUM_ALARM_WAKEUP_SOURCE_MASK & (ECUM_ALARM_WAKEUP_SOURCE_MASK - 1)) != 0)
/*PRQA S 4588 --*/
#error "The ECUM_ALARM_WAKEUP_SOURCE_MASK must include only one wakeup source."
#endif
#endif


#if((STD_ON == ECUM_MODEHANDLING_SUPPORT) && (ECUM_USER_NUMBER == 0))
#error "There must be at least ONE user when ECUM_MODEHANDLING_SUPPORT has been ON."
#endif

#endif
/*******************************************************************************
*   Macro
*******************************************************************************/

#if(ECUM_DEV_ERROR_DETECT == STD_ON)
/*SWS_EcuM_03009*/
#define ECUM_DET_ERROR_DETECT(cond, ApiId, errcode)  \
    DET_ERROR_DETECT(cond, ECUM_MODULE_ID, ECUM_INSTANCE_ID, ApiId, errcode)

#define ECUM_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret) \
    DET_ERROR_DETECT_RET(cond, ECUM_MODULE_ID, ECUM_INSTANCE_ID, ApiId, errcode, ret)

#define ECUM_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(ECUM_MODULE_ID, ECUM_INSTANCE_ID, (ApiId), (errcode))
#else
#define ECUM_DET_ERROR_DETECT(cond, api, err)
#define ECUM_DET_ERROR_DETECT_RET(cond, api, err, ret)
#define ECUM_DET_REPORT_ERROR(api, err)
#endif /*ECUM_DEV_ERROR_DETECT == STD_ON*/

#if(ECUM_OS_RESOURCE_USED == STD_ON)
#if(ECUM_CORE_NUMBER == 1)
#define ECUM_GET_OS_RESOURCE(CoreId)    ECUM_OS_RESOURCE_ID
#else
#define ECUM_GET_OS_RESOURCE(CoreId)    EcuM_OsResourceTable[CoreId]
#endif
#endif

#if((ECUM_CORE_NUMBER > 1) && (ECUM_OS_USED != STD_ON))
#define GetCoreId()                     Bmc_GetCoreId()
#endif


        
/*The EcuM State*/
#if(ECUM_CORE_NUMBER == 1)
#define ECUM_SET_STATE(sta)             (EcuM_CurrentState = (sta))
#define ECUM_GET_STATE()                (EcuM_CurrentState)
#else
#define ECUM_SET_STATE(sta)             (EcuM_CurrentState[CoreId] = (sta))
#define ECUM_GET_STATE()                (EcuM_CurrentState[CoreId])
#endif

#define ECUM_STATE_IS_STARTUP_ONE()     (ECUM_GET_STATE() == ECUM_STATE_STARTUP_ONE)
#define ECUM_STATE_IS_GO_OFF_ONE()      (ECUM_GET_STATE() == ECUM_STATE_GO_OFF_ONE)
#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
#define ECUM_STATE_IS_RUN()             (ECUM_GET_STATE() == ECUM_STATE_RUN)
#define ECUM_STATE_IS_APP_RUN()         (ECUM_GET_STATE() == ECUM_STATE_APP_RUN)
#define ECUM_STATE_IS_SLEEP()           (ECUM_GET_STATE() == ECUM_STATE_SLEEP)
#endif
#define ECUM_IS_INITIALIZED()           (ECUM_GET_STATE() > ECUM_STATE_STARTUP)

#if(ECUM_CORE_NUMBER > 1)
#define ECUM_CORE_DEFINITION_ZERO(CoreId)    (CoreId == ECUM_DRIVER_INIT_LISTZERO_COREREF)
#define ECUM_CORE_DEFINITION_ONE(CoreId)    (CoreId == ECUM_DRIVER_INIT_LISTONE_COREREF)
#endif

#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
#define ECUM_SLEEP_TYPE_POLLING         ((uint8)0)
#define ECUM_SLEEP_TYPE_HALT            ((uint8)1)

/*The Wakeup Source*/

#define ECUM_WKSRC_SET_STATE(wkSrc,src)     ((wkSrc) |= (src))
#define ECUM_WKSRC_CLEAR_STATE(wkSrc,src)   ((wkSrc) &= ~(src))

#define ECUM_WKSRC_GET_VALIDATED_SRC()      (EcuM_WkVaildated)
#define ECUM_WKSRC_GET_ENABLED_SRC()        (EcuM_WkEnabled)
#define ECUM_WKSRC_SET_VALIDATED_SRC(src)   ECUM_WKSRC_SET_STATE(EcuM_WkVaildated,src)
#define ECUM_WKSRC_SET_ENABLED_SRC(src)     ECUM_WKSRC_SET_STATE(EcuM_WkEnabled,src)

#define ECUM_WKSRC_CLEAR_VALIDATED_SRC(src) ECUM_WKSRC_CLEAR_STATE(EcuM_WkVaildated,src)
#define ECUM_WKSRC_CLEAR_ENABLED_SRC(src)   ECUM_WKSRC_CLEAR_STATE(EcuM_WkEnabled,src)

#if(ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
#define ECUM_WKSRC_GET_PENDING_SRC()        (EcuM_WkPending)
#define ECUM_WKSRC_GET_CACHEDPENDING()      (EcuM_WkCachedPending)
#define ECUM_WKSRC_GET_EXPIRED_SRC()        (EcuM_WkExpired)

#define ECUM_WKSRC_SET_PENDING_SRC(src)     ECUM_WKSRC_SET_STATE(EcuM_WkPending,src)
#define ECUM_WKSRC_SET_CACHEDPENDING(src)   ECUM_WKSRC_SET_STATE(EcuM_WkCachedPending,src)
#define ECUM_WKSRC_SET_EXPIRED_SRC(src)     ECUM_WKSRC_SET_STATE(EcuM_WkExpired,src)

#define ECUM_WKSRC_CLEAR_PENDING_SRC(src)   ECUM_WKSRC_CLEAR_STATE(EcuM_WkPending,src)
#define ECUM_WKSRC_CLEAR_EXPIRED_SRC(src)   ECUM_WKSRC_CLEAR_STATE(EcuM_WkExpired,src)
#define ECUM_WKSRC_CLEAR_CACHEDPENDING(src) ECUM_WKSRC_CLEAR_STATE(EcuM_WkCachedPending,src)

#else
#define ECUM_WKSRC_GET_PENDING_SRC()        ECUM_WKSTATUS_NONE
#define ECUM_WKSRC_GET_CACHEDPENDING()      ECUM_WKSTATUS_NONE
#define ECUM_WKSRC_GET_EXPIRED_SRC()        ECUM_WKSTATUS_NONE

#define ECUM_WKSRC_SET_PENDING_SRC(src)     ECUM_USED(src)
#define ECUM_WKSRC_SET_CACHEDPENDING(src)   ECUM_USED(src)
#define ECUM_WKSRC_SET_EXPIRED_SRC(src)     ECUM_USED(src)

#define ECUM_WKSRC_CLEAR_PENDING_SRC(src)   ECUM_USED(src)
#define ECUM_WKSRC_CLEAR_EXPIRED_SRC(src)   ECUM_USED(src)
#define ECUM_WKSRC_CLEAR_CACHEDPENDING(src) ECUM_USED(src)

#endif /*ECUM_WAKEUPSOURCE_VALIDATION == STD_ON*/

#define ECUM_WKSRC_GET_DETECTED_SRC()       (ECUM_WKSRC_GET_PENDING_SRC() | ECUM_WKSRC_GET_VALIDATED_SRC())

#if(ECUM_GODOWN_USER_NUMBER > 0)
#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
#define ECUM_WKSRC_IS_DETECTED_SRC()        (ECUM_WKSRC_GET_DETECTED_SRC() > (EcuM_WakeupSourceType)0)
#endif
#endif
#define ECUM_WKSRC_IS_VALIDATED_SRC()       (ECUM_WKSRC_GET_VALIDATED_SRC() > (EcuM_WakeupSourceType)0)

#define ECUM_WKSRC_IS_VALID_SRC(src)        (((src) & ECUM_WKSOURCE_VALID_MASK) > (EcuM_WakeupSourceType)0)
/*PRQA S 3435,3456 ++*/
/*There is no need to modify the specific method */
#define ECUM_WKSRC_IS_ONLY_SRC(src)         (((src) & ((src) - (EcuM_WakeupSourceType)1)) == (EcuM_WakeupSourceType)0)
/*PRQA S 3435,3456 --*/
#define ECUM_WKSRC_GET_TIMEOUT(srcId)       (EcuM_WkSrcConfigTable[srcId].ValidationTimeout)
#define ECUM_WKUP_CHECK_TIMEOUT(srcId)      (EcuM_WkSrcConfigTable[srcId].CheckTimeout)


#if(ECUM_COMM_WAKEUP_NOTIFICATION == STD_ON)

#if(ECUM_WKSRC_COMM_CHANNEL_SUPPORT == STD_ON)
#define ECUM_WKSRC_GET_COMM_CHANNEL(Index)  (EcuM_WkSrcChannelTable[Index])
#define ECUM_WKSRC_COMM_CHANNEL_NUM(srcId)  (EcuM_WkSrcConfigTable[srcId].ComMChannelNum)
#define ECUM_WKSRC_COMM_CHANNEL_START(srcId)  (EcuM_WkSrcConfigTable[srcId].ChannelStartNumber)
#endif

#if(ECUM_WKSRC_COMM_PNC_SUPPORT == STD_ON)
#define ECUM_WKSRC_GET_COMM_PNC(Index)      (EcuM_WkSrcPNCTable[Index])
#define ECUM_WKSRC_COMM_PNC_NUM(srcId)      (EcuM_WkSrcConfigTable[srcId].ComMPNCNum)
#define ECUM_WKSRC_COMM_PNC_START(srcId)      (EcuM_WkSrcConfigTable[srcId].PNCStartNumber)
#endif

#endif
/*Sleep mode*/
#define ECUM_GET_SLEEP_MODE(id)             (&EcuM_SleepModeTable[id])

#endif /* ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON */



#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
/*The Alarm Clock*/
#define ECUM_ALARM_INVALID_TIME         (0xFFFFFFFF)

#define ECUM_ALARM_SET_TIME(id,time)    (EcuM_AlarmTime[id] = (time))
#define ECUM_ALARM_GET_TIME(id)         (EcuM_AlarmTime[id])
#define ECUM_ALARM_CLEAR_TIME(id)       ECUM_ALARM_SET_TIME(id,(EcuM_TimeType)0)

#define ECUM_ALARM_SET_MASTER(id)       (EcuM_MasterAlarmId = (id))

#define ECUM_ALARM_IS_VALID(id)         ((id) < (EcuMAlarmIdType)ECUM_ALARM_CLOCK_NUMBER)
#define ECUM_ALARM_IS_MASTER(id)        (EcuM_MasterAlarmId == (id))
#endif /*ECUM_ALARM_CLOCK_PRESENT == STD_ON*/

#if(ECUM_CORE_NUMBER > 1)
#define ECUM_CORE_TASKID(CoreId)                 (EcuM_CoreShutdownInfo[CoreId].TaskId)

#if(ECUM_USED_EXTEND_TASK == STD_ON)
#define ECUM_CORE_SHUTDOWM_EVENT_MASK(CoreId)    (EcuM_CoreShutdownInfo[CoreId].ShutdownEventMask)
#define ECUM_CORE_SLEEP_EVENT_MASK(CoreId)       (EcuM_CoreShutdownInfo[CoreId].SleepEventMask)
#endif

#define ECUM_CORE_WAKEUPSOURCEMASK(CoreId)       (EcuM_CoreWakeupSourceMask[CoreId])
#endif

#if(ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
#if(ECUM_CORE_NUMBER == 1)
#define ECUM_GET_VALIDATION_TIMEOUT         (EcuM_WkSrcValidationTimeout)
#define ECUM_CHECK_VALIDATION_TIMEOUT       (EcuM_WkSrcValidationTimeout > 0U)
#define ECUM_RUN_VALIDATION_TIMEOUT         (EcuM_WkSrcValidationTimeout--)
#define ECUM_GET_CHECKWKUP_TIMEOUT          (EcuM_WkupCheckTimeout)
#define ECUM_RUN_CHECKWKUP_TIMEOUT          (EcuM_WkupCheckTimeout--)
#define ECUM_SET_CHECKWKUP_FLAG             (EcuM_WkupCheckFlag)
#else
#define ECUM_GET_VALIDATION_TIMEOUT         (EcuM_WkSrcValidationTimeout[CoreId])
#define ECUM_CHECK_VALIDATION_TIMEOUT       (EcuM_WkSrcValidationTimeout[CoreId] > 0U)
#define ECUM_RUN_VALIDATION_TIMEOUT         (EcuM_WkSrcValidationTimeout[CoreId]--)
#define ECUM_GET_CHECKWKUP_TIMEOUT          (EcuM_WkupCheckTimeout[CoreId])
#define ECUM_RUN_CHECKWKUP_TIMEOUT          (EcuM_WkupCheckTimeout[CoreId]--)
#define ECUM_SET_CHECKWKUP_FLAG             (EcuM_WkupCheckFlag[CoreId])
#endif /*ECUM_CORE_NUMBER == 1*/
#endif /*ECUM_WAKEUPSOURCE_VALIDATION == STD_ON*/

#define ECUM_USED(param)                    ((void)(param))

/*******************************************************************************
*   Local Data Declaration
*******************************************************************************/

#define ECUM_START_SEC_VAR_CLEARED_GLOBAL_8
#include "EcuM_MemMap.h"

#if(STD_ON == ECUM_MODEHANDLING_SUPPORT)
STATIC VAR(uint8, ECUM_VAR) EcuMRunUserCnt;
STATIC VAR(uint8, ECUM_VAR) EcuMPostRunUserCnt;
STATIC VAR(EcuM_RunStatusType, ECUM_VAR) EcuM_UserRunRequest[ECUM_USER_NUMBER];
STATIC VAR(EcuM_RunStatusType, ECUM_VAR) EcuM_UserPostRunRequest[ECUM_USER_NUMBER];
#endif /*STD_ON == ECUM_MODEHANDLING_SUPPORT*/

STATIC VAR(EcuM_BootTargetType, ECUM_VAR) EcuM_BootTarget;
STATIC VAR(EcuM_ShutdownCauseType, ECUM_VAR) EcuM_CurrentShutdownCause;
STATIC VAR(EcuM_ShutdownTargetType, ECUM_VAR) EcuM_CurrentShutdownTarget;
STATIC VAR(EcuM_ShutdownTargetType, ECUM_VAR) EcuM_LastShutdownTarget;

#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
STATIC VAR(EcuMAlarmIdType, ECUM_VAR) EcuM_MasterAlarmId;
#endif
#endif

#define ECUM_STOP_SEC_VAR_CLEARED_GLOBAL_8
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_VAR_CLEARED_GLOBAL_16
#include "EcuM_MemMap.h"

STATIC VAR(EcuM_ShutdownModeType, ECUM_VAR) EcuM_CurrentShutdownMode;
STATIC VAR(EcuM_ShutdownModeType, ECUM_VAR_NOINIT) EcuM_LastShutdownMode;

#define ECUM_STOP_SEC_VAR_CLEARED_GLOBAL_16
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_VAR_CLEARED_GLOBAL_32
#include "EcuM_MemMap.h"

#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
/* Store wkupsrc that occur during the startup before BswM & ComM is initialized */
#if(ECUM_COMM_WAKEUP_NOTIFICATION == STD_ON)
STATIC VAR(EcuM_WakeupSourceType, ECUM_VAR) EcuM_ComM_StoredWakeups;
#endif

STATIC VAR(EcuM_WakeupSourceType, ECUM_VAR) EcuM_BswM_StoredWakeups;
STATIC VAR(EcuM_WakeupSourceType, ECUM_VAR) EcuM_WkEnabled;
STATIC VAR(EcuM_WakeupSourceType, ECUM_VAR) EcuM_WkVaildated;

#if(ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
STATIC VAR(EcuM_WakeupSourceType, ECUM_VAR) EcuM_WkPending;
STATIC VAR(EcuM_WakeupSourceType, ECUM_VAR) EcuM_WkExpired;
STATIC VAR(EcuM_WakeupSourceType, ECUM_VAR) EcuM_WkCachedPending;
#endif

#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
STATIC VAR(EcuM_TimeType, ECUM_VAR) EcuM_CurrentClock;
STATIC VAR(EcuM_TimeType, ECUM_VAR) EcuM_AlarmTime[ECUM_ALARM_CLOCK_NUMBER];
#endif
#endif  /*#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)*/

#define ECUM_START_SEC_VAR_CLEARED_GLOBAL_32
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "EcuM_MemMap.h"
STATIC P2CONST(EcuM_ConfigType, ECUM_VAR, ECUM_VAR) EcuM_PBConfig;
#define ECUM_STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "EcuM_MemMap.h"


#if(ECUM_CORE_NUMBER == 1)
#define ECUM_START_SEC_VAR_CLEARED_LOCAL_8
#include "EcuM_MemMap.h"

STATIC VAR(EcuM_StateType, ECUM_VAR) EcuM_CurrentState;
#if(ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
STATIC VAR(boolean, ECUM_VAR) EcuM_WkupCheckFlag;
#endif

#define ECUM_STOP_SEC_VAR_CLEARED_LOCAL_8
#include "EcuM_MemMap.h"


#define ECUM_START_SEC_VAR_CLEARED_LOCAL_16
#include "EcuM_MemMap.h"

#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
#if(ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
STATIC VAR(uint16, ECUM_VAR) EcuM_WkupCheckTimeout;
#endif
#endif  /*#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)*/
#define ECUM_STOP_SEC_VAR_CLEARED_LOCAL_16
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_VAR_CLEARED_LOCAL_32
#include "EcuM_MemMap.h"

#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
#if(ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
STATIC VAR(uint32, ECUM_VAR) EcuM_WkSrcValidationTimeout;
#endif
#endif  /*#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)*/

#define ECUM_STOP_SEC_VAR_CLEARED_LOCAL_32
#include "EcuM_MemMap.h"
#endif   /*#if(ECUM_CORE_NUMBER == 1)*/

#if(ECUM_CORE_NUMBER > 1)
#define ECUM_START_SEC_VAR_CLEARED_LOCAL_8
#include "EcuM_MemMap.h"

STATIC VAR(EcuM_StateType, ECUM_VAR) EcuM_CurrentState[ECUM_CORE_NUMBER];
#if(ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
STATIC VAR(boolean, ECUM_VAR) EcuM_WkupCheckFlag[ECUM_CORE_NUMBER];
#endif

#define ECUM_STOP_SEC_VAR_CLEARED_LOCAL_8
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_VAR_INIT_GLOBAL_8
#include "EcuM_MemMap.h"

STATIC VAR(boolean, ECUM_VAR) EcuMShutdownFlag = FALSE;

#define ECUM_STOP_SEC_VAR_INIT_GLOBAL_8
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_VAR_CLEARED_LOCAL_16
#include "EcuM_MemMap.h"

#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
#if(ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
STATIC VAR(uint16, ECUM_VAR) EcuM_WkupCheckTimeout[ECUM_CORE_NUMBER];
#endif
#endif  /*#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)*/
#define ECUM_STOP_SEC_VAR_CLEARED_LOCAL_16
#include "EcuM_MemMap.h"

#define ECUM_START_SEC_VAR_CLEARED_LOCAL_32
#include "EcuM_MemMap.h"

#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
#if(ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
STATIC VAR(uint32, ECUM_VAR) EcuM_WkSrcValidationTimeout[ECUM_CORE_NUMBER];
#endif
#endif  /*#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)*/

#define ECUM_START_SEC_VAR_CLEARED_LOCAL_32
#include "EcuM_MemMap.h"

#endif /*#if(ECUM_CORE_NUMBER > 1)*/


#define ECUM_START_SEC_CODE
#include "EcuM_MemMap.h"

/*******************************************************************************
*   Local Functions define
*******************************************************************************/
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckConfigConsistency
(
    P2CONST(EcuM_ConfigType, AUTOMATIC, AUTOMATIC) config
);

#if(STD_ON == ECUM_WAKEUPSOURCE_RESETREASON)
STATIC FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetLastWakeupSource
(
    void
);
#endif

#if(ECUM_GODOWN_USER_NUMBER > 0)
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckGoDownUser
(
    EcuM_UserType user
);
#endif

STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoDown
(
    EcuM_UserType caller
);


#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
STATIC FUNC(void, ECUM_CODE) EcuM_NotifyBswMWkup
(
    EcuM_WakeupSourceType wkSrc,
    EcuM_WakeupStatusType status
);

STATIC FUNC(uint8, ECUM_CODE) EcuM_MakeWakeupSourceId
(
    P2VAR(EcuM_WakeupSourceType, AUTOMATIC, ECUM_APPL_DATA) source
);

#if(ECUM_COMM_WAKEUP_NOTIFICATION == STD_ON)
STATIC FUNC(void, ECUM_CODE) EcuM_NotifyComMWkup
(
    uint8 wkSrcId
);
#endif

#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
#if(ECUM_ALARM_CLOCK_NUMBER > 1)
STATIC FUNC(EcuMAlarmIdType, ECUM_CODE) EcuM_FindEarliestUserAlarm
(
    void
);
#endif

STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetWakeupAlarm
(
    EcuM_UserType user,
    EcuM_TimeType timeout
);

STATIC FUNC(void, ECUM_CODE) EcuM_CheckAlarmTimeout
(
    void
);

STATIC FUNC(void, ECUM_CODE) EcuM_UpdateClock
(
    void
);

STATIC FUNC(void, ECUM_CODE) EcuM_CancelAllAlarmClock
(
    void
);

STATIC FUNC(void, ECUM_CODE) EcuM_AbortAllWakeupAlarm
(
    void
);

#if(ECUM_SETCLOCK_USER_NUMBER > 1)
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckSetClockUser
(
    EcuM_UserType user
);
#endif
#endif

STATIC FUNC(void, ECUM_CODE) EcuM_GoHaltSleep
(
    P2CONST(EcuM_SleepModeType, AUTOMATIC, AUTOMATIC) sleepMode
);

STATIC FUNC(void, ECUM_CODE) EcuM_GoSleep
(
    P2CONST(EcuM_SleepModeType, AUTOMATIC, AUTOMATIC) sleepMode,
    uint8 sleepType
);

#if(ECUM_SLEEP_POLLING_MODE == STD_ON)
STATIC FUNC(void, ECUM_CODE) EcuM_GoPollSleep
(
    P2CONST(EcuM_SleepModeType, AUTOMATIC, AUTOMATIC) sleepMode
);
#endif

#if(ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
STATIC FUNC(void, ECUM_CODE) EcuM_StartValidationTimer
(
    uint8 wkSrcId
);

STATIC FUNC(void, ECUM_CODE) EcuM_StopValidationTimer
(
    void
);

STATIC FUNC(void, ECUM_CODE) EcuM_EvaluateWakeupEvent
(
    void
);
#endif

STATIC FUNC(void, ECUM_CODE) EcuM_ValidateWakeupSource
(
    uint8 wkSrcId
);
#endif

STATIC FUNC(void, ECUM_CODE) EcuM_InitMaster
(
    void
);

#if(ECUM_CORE_NUMBER > 1)
STATIC FUNC(void, ECUM_CODE) EcuM_InitSlave
(
    uint8 CoreId
);

#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_CheckConfigConsistency
*
* Description:   Check if the HASH is consistency.
*
* Inputs:        config - The Post-Build config with Hash value.
*
* Outputs:       If the hash is consistency returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckConfigConsistency
(
   P2CONST(EcuM_ConfigType, AUTOMATIC, AUTOMATIC) config
)
{
    Std_ReturnType ret = E_OK;
    uint8 i;

    if((config != NULL_PTR) \
        && (config->ConfigHashPtr != NULL_PTR) \
        && (ECUM_CONFIG_HASH_LEN == config->HashLength))
    {
        for(i = 0U; i < ECUM_CONFIG_HASH_LEN; i++)
        {
            if(config->ConfigHashPtr[i] != EcuM_ConfigConsistencyHash[i])
            {
                ret = E_NOT_OK;
                break;
            }
        }
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;
}

#if(STD_ON == ECUM_WAKEUPSOURCE_RESETREASON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_GetLastWakeupSource
*
* Description:   Get last wakeupsource.
*
* Inputs:        config - The Post-Build config with Hash value.
*
* Outputs:       If MCU driver return an ResetReason than match a wakeupsource,
*                then this wakeupsource will be returned, otherwise return
*                ECUM_WKSOURCE_RESET as default value.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetLastWakeupSource
(
    void
)
{
    Mcu_ResetType reason;
    uint8 i;
    EcuM_WakeupSourceType wkSrc = 0U;

    reason = Mcu_GetResetReason();

    for(i = (uint8)0; i < (uint8)ECUM_WKSOURCE_NUMBER; i++)
    {
        if(EcuM_WkSrcConfigTable[i].ResetReason == reason)
        {
            wkSrc = ECUM_MAKE_WAKEUPSOURCE(i);
            break;
        }
    }
    /* Nothing detected by hardware, report ECUM_WKSOURCE_RESET. */
    if(i >= (uint8)ECUM_WKSOURCE_NUMBER)
    {
        wkSrc = ECUM_WKSOURCE_RESET;
    }

    return wkSrc;
}
#endif

#if(ECUM_GODOWN_USER_NUMBER > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_CheckGoDownUser
*
* Description:   Check if the user has authorization.
*
* Inputs:        user - the user
*
* Outputs:       If the user is authorized returns E_OK, otherwise returns
*                E_NOT_OK
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckGoDownUser
(
    EcuM_UserType user
)
{
    EcuM_UserType i;
    Std_ReturnType ret = E_NOT_OK;

    for(i = 0U; i < (EcuM_UserType)ECUM_GODOWN_USER_NUMBER; i++)
    {
        if(EcuM_GoDownUserTable[i] == user)
        {
            ret = E_OK;
            break;
        }
    }
    
    return ret;
}
#endif

#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_NotifyBswMWkup
*
* Description:   Notify a wakeup source to BswM.
*
* Inputs:        wkSrcId - the Id of a wakeup source
*
* Outputs:       None.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ECUM_CODE) EcuM_NotifyBswMWkup
(
    EcuM_WakeupSourceType wkSrc,
    EcuM_WakeupStatusType status
)
{
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(ECUM_GET_STATE() > ECUM_STATE_STARTUP_TWO)
    {
        BswM_EcuM_CurrentWakeup(wkSrc, status);
        EcuM_BswM_StoredWakeups &= ~wkSrc;
    }
    else
    {
        EcuM_BswM_StoredWakeups |= wkSrc;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_MakeWakeupSourceId
*
* Description:   Make the wakeup source Id.
*
* Inputs:        source - the wakeup source
*
* Outputs:       the wakeup source id.
*
* Limitations:   the sources must be greater than zero and only includes one
*                source.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, ECUM_CODE) EcuM_MakeWakeupSourceId
(
    P2VAR(EcuM_WakeupSourceType, AUTOMATIC, ECUM_APPL_DATA) source
)
{
    uint8 id = 0U;

#if(ECUM_WKSOURCE_NUMBER > 16)
    if(((*source) & KECUM_SPECIAL_MASK_ONE) > (EcuM_WakeupSourceType)0)
    {
        (*source) >>= (EcuM_WakeupSourceType)ECUM_NUM_SIXTEEN ;
        id += (uint8)ECUM_NUM_SIXTEEN ;
    }
#endif
#if(ECUM_WKSOURCE_NUMBER > 8)
    if(((*source) & KECUM_SPECIAL_MASK_TWO) > (EcuM_WakeupSourceType)0)
    {
        (*source) >>= (EcuM_WakeupSourceType)ECUM_NUM_EIGHT ;
        id += (uint8)ECUM_NUM_EIGHT ;
    }
#endif

    if(((*source) & KECUM_SPECIAL_MASK_FIVE) > (EcuM_WakeupSourceType)0)
    {
        (*source) >>= (EcuM_WakeupSourceType)ECUM_NUM_FOUR;
        id = id + (uint8)ECUM_NUM_FOUR;
    }

    if(((*source) & KECUM_SPECIAL_MASK_THREE) > (EcuM_WakeupSourceType)0)
    {
        (*source) >>= (EcuM_WakeupSourceType)ECUM_NUM_TWO;
        id = id + (uint8)ECUM_NUM_TWO;
    }

    if(((*source) & KECUM_SPECIAL_MASK_FOUR) > (EcuM_WakeupSourceType)0)
    {
        id = id + (uint8)ECUM_NUM_ONE;
    }

    return id;
}

#if(ECUM_COMM_WAKEUP_NOTIFICATION == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_NotifyComMWkup
*
* Description:   Notify a wakeup source to ComM.
*
* Inputs:        wkSrcId - the Id of a wakeup source
*
* Outputs:       None.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ECUM_CODE) EcuM_NotifyComMWkup
(
    uint8 wkSrcId
)
{
    ComM_InitStatusType ComMStatus;
    uint16 StartIndex;

    EcuM_WakeupSourceType wkSrc = ECUM_MAKE_WAKEUPSOURCE(wkSrcId);
    uint16 i;
    /*SWS_EcuM_02790*//*SWS_EcuM_02791*/
    (void)ComM_GetStatus(&ComMStatus);
    if(COMM_INIT == ComMStatus)
    {
#if(ECUM_WKSRC_COMM_CHANNEL_SUPPORT == STD_ON)
        if(ECUM_WKSRC_COMM_CHANNEL_NUM(wkSrcId) > (uint8)0)
        {
            StartIndex = ECUM_WKSRC_COMM_CHANNEL_START(wkSrcId);
            for(i = StartIndex; i < (StartIndex + ECUM_WKSRC_COMM_CHANNEL_NUM(wkSrcId)); i++)
            {
                ComM_EcuM_WakeUpIndication(ECUM_WKSRC_GET_COMM_CHANNEL(i));
            }
        }
#endif
#if(ECUM_WKSRC_COMM_PNC_SUPPORT == STD_ON)
        if(ECUM_WKSRC_COMM_PNC_NUM(wkSrcId) > 0)
        {
            StartIndex = ECUM_WKSRC_COMM_PNC_START(wkSrcId);
            for(i = StartIndex; i < (StartIndex + ECUM_WKSRC_COMM_PNC_NUM(wkSrcId)); i++)
            {
                ComM_EcuM_PNCWakeUpIndication(ECUM_WKSRC_GET_COMM_PNC(i));
            }  
        }
#endif
        
        EcuM_ComM_StoredWakeups &= ~wkSrc;
    }
    else
    {
        EcuM_ComM_StoredWakeups |= wkSrc;
    }
    
}
#endif

#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
#if(ECUM_ALARM_CLOCK_NUMBER > 1)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_FindEarliestUserAlarm
*
* Description:   Find the miniut user's wakeup alarm Id.
*
* Inputs:        None
*
* Outputs:       if the user is found returns it's id, otherwise returns
*                ECUM_INVALID_ALARMID.
*
* Limitations:   ECUM_ALARM_CLOCK_NUMBER must be greater than One.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(EcuMAlarmIdType, ECUM_CODE) EcuM_FindEarliestUserAlarm
(
    void
)
{
    EcuMAlarmIdType id;
    EcuMAlarmIdType ret = ECUM_INVALID_ALARMID;
    EcuM_TimeType earlierTime = ECUM_ALARM_INVALID_TIME;

    for(id = 0; id < ECUM_ALARM_CLOCK_NUMBER; id++)
    {
        if((ECUM_ALARM_GET_TIME(id) != (EcuM_TimeType)0) \
            && (ECUM_ALARM_GET_TIME(id) < earlierTime))
        {
            earlierTime = ECUM_ALARM_GET_TIME(id);
            ret = id;
        }
    }

    return ret;
}
#endif /*ECUM_ALARM_CLOCK_NUMBER > 1*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_SetWakeupAlarm
*
* Description:   Sets the user's wakeup alarm to an absolute point in time.
*
* Inputs:        user       - The user that wants to set the wakeup alarm.
*                timeout    - Absolute time in seconds. Note that, absolute
*                             alarms use knowledge of the current time.
*
* Outputs:       if this service has succeeded returns E_OK, otherwise returns
*                E_NOT_OK.
*                If the relative time from now is later than the current wakeup
*                time, return ECUM_E_EARLIER_ACTIVE.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetWakeupAlarm
(
    EcuM_UserType user,
    EcuM_TimeType timeout
)
{
    Std_ReturnType ret = E_NOT_OK;
    EcuM_TimeType Cur_Clock;
    EcuMAlarmIdType alarm;

    alarm = EcuM_UserAlarm[user]; /*SWS_EcuM_04071*/

    if(ECUM_ALARM_IS_VALID(alarm))
    {
        SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_1();
        Cur_Clock = EcuM_CurrentClock;
        SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_1();

        if(timeout <= Cur_Clock)
        {
            /*SWS_EcuM_04060*/
            ret = ECUM_E_PAST;
        }
        else if((ECUM_ALARM_GET_TIME(alarm) != (EcuM_TimeType)0) \
            && (ECUM_ALARM_GET_TIME(alarm) <= timeout))
        {
            /*SWS_EcuM_04056, SWS_EcuM_04059*/
            ret = ECUM_E_EARLIER_ACTIVE;
        }
        else
        {
            SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_2();
            /*SWS_EcuM_04055, SWS_EcuM_04058*/
            ECUM_ALARM_SET_TIME(alarm, timeout);
            /*Refresh MasterAlarm  SWS_EcuM_04072*/
#if(ECUM_ALARM_CLOCK_NUMBER == 1)
            ECUM_ALARM_SET_MASTER(alarm);
#else
            ECUM_ALARM_SET_MASTER(EcuM_FindEarliestUserAlarm());
#endif
            SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_2();
            ret = E_OK;
        }
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_CheckAlarmTimeout
*
* Description:   Check if the master alarm is timeout.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   ECUM_ALARM_CLOCK_PRESENT must be STD_ON
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ECUM_CODE) EcuM_CheckAlarmTimeout
(
    void
)
{
    EcuM_TimeType Cur_Clock;

    SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_1();
    Cur_Clock = EcuM_CurrentClock;
    SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_1();

    SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_2();
    /*PRQA S 2481 ++*/
    /*The parameters are processed inside the loop without modification*/
    while(ECUM_ALARM_IS_VALID(EcuM_MasterAlarmId))
    /*PRQA S 2481 --*/
    {
        if(Cur_Clock >= ECUM_ALARM_GET_TIME(EcuM_MasterAlarmId))
        {
            ECUM_ALARM_CLEAR_TIME(EcuM_MasterAlarmId);
#if(ECUM_ALARM_CLOCK_NUMBER == 1)
            ECUM_ALARM_SET_MASTER(ECUM_INVALID_ALARMID);
#else
            ECUM_ALARM_SET_MASTER(EcuM_FindEarliestUserAlarm()); /*SWS_EcuM_04072*/
#endif
        }
        else
        {
            /*Master alarm is not timeout yet, system wakeup for other reasons*/
            break;
        }
    }
    SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_2();
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_UpdateClock
*
* Description:   Update the EcuM clock.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   ECUM_ALARM_CLOCK_PRESENT must be STD_ON
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ECUM_CODE) EcuM_UpdateClock
(
    void
)
{
    SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_1();
    /*PRQA S 3383 ++*/
    /*This parameter is large enough, and the code does not need to be modified considering the actual usage of the situation */
    EcuM_CurrentClock += (EcuM_TimeType)1;
    /*PRQA S 3383 --*/
    SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_1();
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_CancelAllAlarmClock
*
* Description:   Cancel all user alarm and clear master alarm.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   ECUM_ALARM_CLOCK_PRESENT must be STD_ON
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ECUM_CODE) EcuM_CancelAllAlarmClock
(
    void
)
{
    EcuMAlarmIdType i = 0U;

#if(ECUM_ALARM_CLOCK_NUMBER > 1)
    for(i = 0U; i < ECUM_ALARM_CLOCK_NUMBER; i++)
#endif
    {
        ECUM_ALARM_CLEAR_TIME(i);
    }

    ECUM_ALARM_SET_MASTER(ECUM_INVALID_ALARMID);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_AbortAllWakeupAlarm
*
* Description:   Aborts all wakeup alarm and clear master alarm.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   ECUM_ALARM_CLOCK_PRESENT must be STD_ON
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ECUM_CODE) EcuM_AbortAllWakeupAlarm
(
    void
)
{
    SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_2();
    EcuM_CancelAllAlarmClock();
    SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_2();
}

#if(ECUM_SETCLOCK_USER_NUMBER > 1)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_CheckSetClockUser
*
* Description:   Check if the user is privileged.
*
* Inputs:        user - The user that wants to set Clock.
*
* Outputs:       if the user is privileged returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   4073
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_CheckSetClockUser
(
    EcuM_UserType user
)
{
    uint8 i;
    Std_ReturnType ret = E_NOT_OK;

    for(i = 0; i < ECUM_SETCLOCK_USER_NUMBER; i++)
    {
        if(EcuM_SetClockUserTable[i] == user)
        {
            ret = E_OK;
            break;
        }
    }

    return ret;
}
#endif /*ECUM_SETCLOCK_USER_NUMBER > 1*/
#endif /*ECUM_ALARM_CLOCK_PRESENT == STD_ON*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_GoHaltSleep
*
* Description:   Instructs the ECU State Manager module to go into a sleep mode
*                where the microcontroller is halted.
*
* Inputs:        sleepMode  - The Sleep Mode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ECUM_CODE) EcuM_GoHaltSleep
(
    P2CONST(EcuM_SleepModeType, AUTOMATIC, AUTOMATIC) sleepMode
)
{
    EcuM_WakeupSourceType wkSrc;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId;
    EcuM_WakeupSourceType CoreWkSrcMask;
#endif
    wkSrc = sleepMode->WkSourceMask;
#if(ECUM_CORE_NUMBER > 1)
    /*Multi-Core Support*/
    CoreId = GetCoreID();
    CoreWkSrcMask = ECUM_CORE_WAKEUPSOURCEMASK(CoreId);
    wkSrc &= CoreWkSrcMask;
    if(CoreId == ECUM_CORE_MASTER_ID)
#endif
    {
#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
        wkSrc |= (EcuM_WakeupSourceType)ECUM_ALARM_WAKEUP_SOURCE_MASK;
#endif
    }
    /*PRQA S 3892 ++*/
    /*
    All types are EcuM_WakeupSourceType, and they don't cause a type of strong rotation.
    */
    while((ECUM_WKSRC_GET_DETECTED_SRC() & wkSrc) == (EcuM_WakeupSourceType)0)
    /*PRQA S 3892 --*/
    {
        EcuM_DisableAllInterrupts();
        EcuM_GenerateRamHash(); /*SWS_EcuM_02961*/
        Mcu_SetMode(sleepMode->McuMode);
        EcuM_EnableAllInterrupts();

        EcuM_DisableAllInterrupts();
        /*if mcu is woken up falsely, the following check will be done additionally, 
          while it is unnecessary. The user must process the RAM_CHECK_FAILED status in 
          function EcuM_ErrorHook, reset the mcu for example.*/
        if(EcuM_CheckRamHash() == (uint8)0)
        {
            EcuM_ErrorHook(ECUM_E_RAM_CHECK_FAILED);
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_GoSleep
*
* Description:   Configures hardware for the upcoming sleep phase and sets the
*                ECU up for the next wakeup event.
*
* Inputs:        sleepMode  - The Sleep Mode
*                sleepType  - halt or polling
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ECUM_CODE) EcuM_GoSleep
(
    P2CONST(EcuM_SleepModeType, AUTOMATIC, AUTOMATIC) sleepMode,
    uint8 sleepType
)
{
    
    EcuM_WakeupSourceType enabledWkSrc;
    EcuM_WakeupSourceType wkSrc;
#if(ECUM_CORE_NUMBER > 1)
    Std_ReturnType ret = E_NOT_OK;
    /*Multi-Core Support*/
    uint8 EcuM_CoreId;
    uint8 CoreId = GetCoreID();
    EcuM_WakeupSourceType CoreWkSrcMask = ECUM_CORE_WAKEUPSOURCEMASK(CoreId);
#endif

    SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_0();

    /*Disable all sources that are enabled but not supported in this mode.*/
    wkSrc = ECUM_WKSRC_GET_ENABLED_SRC();
    enabledWkSrc = (wkSrc & sleepMode->WkSourceMask);
    wkSrc ^= enabledWkSrc;
#if(ECUM_CORE_NUMBER > 1)
    wkSrc &= CoreWkSrcMask;
#endif
    if(ECUM_WKSRC_IS_VALID_SRC(wkSrc))
    {
        ECUM_WKSRC_CLEAR_ENABLED_SRC(wkSrc);
        EcuM_DisableWakeupSources(wkSrc);

        EcuM_NotifyBswMWkup(wkSrc, ECUM_WKSTATUS_DISABLED);
    }

    wkSrc = sleepMode->WkSourceMask;
#if(ECUM_CORE_NUMBER > 1)
    wkSrc &= CoreWkSrcMask;
    enabledWkSrc &= CoreWkSrcMask;
#endif
    /*Do not gosleep when valid or pending wakeup source exists*/
    /*PRQA S 3892 ++*/
    /*
    All types are EcuM_WakeupSourceType, and they don't cause a type of strong rotation.
    */
    if((ECUM_WKSRC_GET_DETECTED_SRC() & wkSrc) == (EcuM_WakeupSourceType)0)
     /*PRQA S 3892 --*/
    {
        ECUM_WKSRC_SET_ENABLED_SRC(wkSrc);        

        /*SLEEP Phase - GoSleep Sequence.-------lbx--------*/
        /*SWS_EcuM_04023*//*SWS_EcuM_04027*/
        EcuM_NotifyBswMWkup(wkSrc, ECUM_WKSTATUS_ENABLED);
        EcuM_EnableWakeupSources(((wkSrc ^ enabledWkSrc)));

#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
#if(ECUM_CORE_NUMBER > 1)
        if(CoreId == ECUM_CORE_MASTER_ID)
#endif
        {
            EcuM_SetClockSleep();
        }
#endif
        SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_0();

#if((ECUM_OS_RESOURCE_USED == STD_ON) && (ECUM_OS_USED == STD_ON))
        /*SWS_EcuM_03010*/
#if(ECUM_CORE_NUMBER > 1)
        (void)GetResource(ECUM_GET_OS_RESOURCE(CoreId)); 
#else
        (void)GetResource(ECUM_GET_OS_RESOURCE(0U));
#endif
#endif
        EcuM_LastShutdownTarget = EcuM_CurrentShutdownTarget;
        EcuM_LastShutdownMode = EcuM_CurrentShutdownMode;
        /*SWS_EcuM_04024*//*SWS_EcuM_04025*//*SWS_EcuM_04028*//*SWS_EcuM_04029*/
#if((ECUM_CORE_NUMBER > 1) && (ECUM_USED_EXTEND_TASK == STD_ON))
        if(CoreId == ECUM_CORE_MASTER_ID)
        {
            EcuMShutdownFlag = TRUE;
            for(EcuM_CoreId = 0U; EcuM_CoreId < (uint8)ECUM_CORE_NUMBER; EcuM_CoreId++)
            {
                if(EcuM_CoreId != ECUM_CORE_MASTER_ID)
                {
                    ret = WaitEvent(ECUM_CORE_SLEEP_EVENT_MASK(EcuM_CoreId));
                    if(ret != E_OK)
                    {
                        EcuM_ErrorHook(ECUM_E_OS_CALL_FAILED);
                    }
                }
            }
            EcuMShutdownFlag = FALSE;
        }
        else
        {
            do
            {
                if(EcuMShutdownFlag == TRUE)
                {
                    ret = SetEvent(ECUM_CORE_TASKID(ECUM_CORE_MASTER_ID), ECUM_CORE_SLEEP_EVENT_MASK(CoreId));
                    if(ret != E_OK)
                    {
                        EcuM_ErrorHook(ECUM_E_OS_CALL_FAILED);
                    }
                }
            } while (ret != E_OK);
        }
#endif
        /*SLEEP Phase - GoHalt or GoPoll Sequence.*/

#if(ECUM_SLEEP_POLLING_MODE == STD_ON)
        if((ECUM_SLEEP_TYPE_POLLING == sleepType)\
                && ((boolean)FALSE == sleepMode->ModeSuspend))
        {
            EcuM_GoPollSleep(sleepMode);
        }
        else
#endif
        {
            EcuM_GoHaltSleep(sleepMode);
        }
        EcuM_EnableAllInterrupts();


        if(ECUM_WKSRC_IS_VALIDATED_SRC())
        {
            /*The BswM module has been Notified by EcuM_ValidateWakeupEvent*/
            /*TODO: clear all pending event?*/
#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
#if(ECUM_CORE_NUMBER > 1)
            if(CoreId == ECUM_CORE_MASTER_ID)
#endif
            {
                EcuM_SetClockNormal();
            }
            EcuM_AbortAllWakeupAlarm(); /*SWS_EcuM_04009*/
#endif
        }
        /*SWS_EcuM_04026*//*SWS_EcuM_04030*/
        EcuM_DisableAllInterrupts();
        Mcu_SetMode((uint8)ECUM_NORMAL_MCU_MODE);
        EcuM_EnableAllInterrupts();

#if((ECUM_CORE_NUMBER > 1) && (ECUM_USED_EXTEND_TASK == STD_ON))
        if(CoreId == ECUM_CORE_MASTER_ID)
	    {
		    ret = ClearEvent(ECUM_SLEEP_EVENT_MASK);
		    if(ret != E_OK)
		    {
			    EcuM_ErrorHook(ECUM_E_OS_CALL_FAILED);
		    }
	    }
        for(EcuM_CoreId = 0U; EcuM_CoreId < (uint8)ECUM_CORE_NUMBER; EcuM_CoreId++)
        {
            if((EcuM_CoreId != ECUM_CORE_MASTER_ID) && (EcuM_CoreId != CoreId))
            {
                EcuM_NotifySet(EcuM_CoreId);
            }
        }
#endif
       

#if(ECUM_CORE_NUMBER > 1)
        if(CoreId == ECUM_CORE_MASTER_ID)
#endif
        {
            EcuM_AL_DriverRestart();
        }

#if(ECUM_OS_RESOURCE_USED == STD_ON)
#if(ECUM_CORE_NUMBER > 1)
        (void)ReleaseResource(ECUM_GET_OS_RESOURCE(CoreId));
#else
        (void)ReleaseResource(ECUM_GET_OS_RESOURCE(0U));
#endif
#endif
    }
    else
    {
        SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_0();
    }
}


#if(ECUM_SLEEP_POLLING_MODE == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_GoPollSleep
*
* Description:   Instructs the EcuM module to go into a polling sleep mode.
*
* Inputs:        sleepMode  - The Sleep Mode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ECUM_CODE) EcuM_GoPollSleep
(
    P2CONST(EcuM_SleepModeType, AUTOMATIC, AUTOMATIC) sleepMode
)
{
    EcuM_WakeupSourceType wkSrc;
    wkSrc = sleepMode->WkSourceMask;
#if(ECUM_CORE_NUMBER > 1)
    /*Multi-Core Support*/
    uint8 CoreId = GetCoreID();
    EcuM_WakeupSourceType CoreWkSrcMask = ECUM_CORE_WAKEUPSOURCEMASK(CoreId);
    wkSrc &= CoreWkSrcMask;
    if(CoreId == ECUM_CORE_MASTER_ID)
#endif
    {
#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
        wkSrc |= (EcuM_WakeupSourceType)ECUM_ALARM_WAKEUP_SOURCE_MASK;
#endif
    }

    EcuM_DisableAllInterrupts();
    Mcu_SetMode(sleepMode->McuMode);

    EcuM_EnableAllInterrupts();
    /*SWS_EcuM_04148*/
    /*PRQA S 3892 ++*/
    /*
    All types are EcuM_WakeupSourceType, and they don't cause a type of strong rotation.
    */
    while((ECUM_WKSRC_GET_DETECTED_SRC() & wkSrc) ==(EcuM_WakeupSourceType)0 )
    /*PRQA S 3892 --*/
    {
        EcuM_SleepActivity();

        EcuM_CheckWakeupHook(wkSrc);
    }

    EcuM_DisableAllInterrupts();
}
#endif /*ECUM_SLEEP_POLLING_MODE == STD_ON*/

#if(ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_StartValidationTimer
*
* Description:   Starts the validation timer of a wakeup source.
*
* Inputs:        wkSrcId - the Id of a wakeup source
*
* Outputs:       None.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ECUM_CODE) EcuM_StartValidationTimer
(
    uint8 wkSrcId
)
{
    EcuM_WakeupSourceType wkSrc = ECUM_MAKE_WAKEUPSOURCE(wkSrcId);
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
    EcuM_WakeupSourceType CoreWkSrcMask = ECUM_CORE_WAKEUPSOURCEMASK(CoreId);
    wkSrc &= CoreWkSrcMask;
#endif
    /*SWS_EcuM_02712*/
    if((ECUM_WKSRC_GET_PENDING_SRC() & wkSrc) == (EcuM_WakeupSourceType)0)
    {
        SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_3();
        /*SWS_EcuM_04004 There is only one timer used for pending wakeup source.*/
        /*SWS_EcuM_02707,SWS_EcuM_02709*/
        if(ECUM_GET_VALIDATION_TIMEOUT < ECUM_WKSRC_GET_TIMEOUT(wkSrcId))
        {
            ECUM_GET_VALIDATION_TIMEOUT = ECUM_WKSRC_GET_TIMEOUT(wkSrcId);
        }
        SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_3();
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_StopValidationTimer
*
* Description:   Stops the validation timer of a wakeup source.
*
* Inputs:        wkSrcId - the Id of a wakeup source
*
* Outputs:       None.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ECUM_CODE) EcuM_StopValidationTimer
(
    void
)
{
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif

    SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_3();
    ECUM_GET_VALIDATION_TIMEOUT = 0U;
    SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_3();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_EvaluateWakeupEvent
*
* Description:   Evaluate the pending wakeup event.
*
* Inputs:        None.
*
* Outputs:       None.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ECUM_CODE) EcuM_EvaluateWakeupEvent
(
    void
)
{
    EcuM_WakeupSourceType cachedSrc;
    EcuM_WakeupSourceType wkSrc;
#if(ECUM_CORE_NUMBER > 1)
    /*Multi-Core Support*/
    uint8 CoreId;
    EcuM_WakeupSourceType CoreWkSrcMask;
#endif
    SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_0();
    cachedSrc = ECUM_WKSRC_GET_CACHEDPENDING();
    wkSrc = ECUM_WKSRC_GET_PENDING_SRC();
    SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_0();
#if(ECUM_CORE_NUMBER > 1)
    /*Multi-Core Support*/ /*SWS_EcuM_04012*/
    CoreId = GetCoreID();
    CoreWkSrcMask = ECUM_CORE_WAKEUPSOURCEMASK(CoreId);
    wkSrc &= CoreWkSrcMask;
    cachedSrc &= CoreWkSrcMask;
#endif

    if(wkSrc != (EcuM_WakeupSourceType)0)
    {
        if(cachedSrc != (EcuM_WakeupSourceType)0)
        {
            SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_0();
            ECUM_WKSRC_CLEAR_CACHEDPENDING(cachedSrc);
            SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_0();
            EcuM_StartWakeupSources(cachedSrc);
        }

        EcuM_CheckValidation(wkSrc);

        wkSrc = ((ECUM_WKSRC_GET_PENDING_SRC()) & (ECUM_WKSRC_GET_VALIDATED_SRC()));
#if(ECUM_CORE_NUMBER > 1)
        wkSrc &= CoreWkSrcMask;
#endif
        if(ECUM_WKSRC_IS_VALID_SRC(wkSrc))
        {
            /*The BswM module has been Notified by EcuM_ValidateWakeupEvent*/
            /*clear validated pending event*/
            SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_0();
            ECUM_WKSRC_CLEAR_PENDING_SRC(wkSrc);
            SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_0();

            EcuM_StopWakeupSources(wkSrc);
#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
            EcuM_AbortAllWakeupAlarm(); /*SWS_EcuM_04009*/
#endif
        }
        else
        {
            SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_3();
            if(ECUM_CHECK_VALIDATION_TIMEOUT)
            {
                ECUM_RUN_VALIDATION_TIMEOUT;
            }


            if(ECUM_GET_VALIDATION_TIMEOUT == 0U)
            {
                SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_3();

                SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_0();
                wkSrc = ECUM_WKSRC_GET_PENDING_SRC();
#if(ECUM_CORE_NUMBER > 1)
                wkSrc &= CoreWkSrcMask;
#endif
                ECUM_WKSRC_CLEAR_PENDING_SRC(wkSrc);
                ECUM_WKSRC_SET_EXPIRED_SRC(wkSrc);
                SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_0();
                EcuM_StopWakeupSources(wkSrc);
                EcuM_NotifyBswMWkup(wkSrc, ECUM_WKSTATUS_EXPIRED);
                SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_3();
            }
            SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_3();
        }
    }
}
#endif /*ECUM_WAKEUPSOURCE_VALIDATION == STD_ON*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_ValidateWakeupSource
*
* Description:   Validate a wakeup source.
*
* Inputs:        wkSrcId - the Id of a wakeup source
*
* Outputs:       None.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ECUM_CODE) EcuM_ValidateWakeupSource
(
    uint8 wkSrcId
)
{
    EcuM_WakeupSourceType wkSrc = ECUM_MAKE_WAKEUPSOURCE(wkSrcId);

    ECUM_WKSRC_SET_VALIDATED_SRC(wkSrc);
#if(ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
    EcuM_StopValidationTimer();
#endif

#if(ECUM_COMM_WAKEUP_NOTIFICATION == STD_ON)
    /*SWS_EcuM_02645*/
    EcuM_NotifyComMWkup(wkSrcId);
#endif
    /*SWS_EcuM_04079*/
    EcuM_NotifyBswMWkup(wkSrc, ECUM_WKSTATUS_VALIDATED);
}
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_InitMaster
*
* Description:   Initializes the EcuM Master and carries out the startup
*                procedure.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ECUM_CODE) EcuM_InitMaster
(
    void
)
{
    EcuM_WakeupSourceType lastWkSrc;
    uint8 i;
#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
    uint8 wkSrcId;
#endif
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = ECUM_CORE_MASTER_ID;
    StatusType CoreStatus = E_OK;
#endif
    ECUM_SET_STATE(ECUM_STATE_STARTUP);

    /*Initializes the variables of the EcuM modules*/
    EcuM_BootTarget = ECUM_BOOT_TARGET_DEFAULT;
    EcuM_CurrentShutdownCause = ECUM_CAUSE_UNKNOWN;
    EcuMRunUserCnt = 0U;
    EcuMPostRunUserCnt = 0U;
#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
    EcuM_BswM_StoredWakeups = 0U;
#if(ECUM_COMM_WAKEUP_NOTIFICATION == STD_ON)
    EcuM_ComM_StoredWakeups = 0U;
#endif
#endif

#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
    EcuM_AbortAllWakeupAlarm(); /*SWS_EcuM_04010*/
#endif

    ECUM_SET_STATE(ECUM_STATE_STARTUP_ONE);
    
    for(i = (uint8)0; i < (uint8)ECUM_USER_NUMBER; i++)
    {
        EcuM_UserRunRequest[i] = ECUM_RUNSTATUS_UNKNOWN;
        EcuM_UserPostRunRequest[i] = ECUM_RUNSTATUS_UNKNOWN;
    }
#if(ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
#if(ECUM_CORE_NUMBER > 1)
    for(i =(uint8) 0; i < (uint8)ECUM_CORE_NUMBER; i++)
    {
        EcuM_WkupCheckFlag[i] = FALSE;
    }
#else
        EcuM_WkupCheckFlag = FALSE;
#endif
#endif
    /*STARTUP Phase - StartPreOS Sequence. SWS_EcuM_02411,SWS_EcuM_02684*/
#if(STD_ON == EcuM_SETPROGRAMMABLEINTERRUPTS_SUPPORT)
    EcuM_AL_SetProgrammableInterrupts();
#endif
    EcuM_AL_DriverInitZero();

    EcuM_PBConfig = EcuM_DeterminePbConfiguration();
    /*SWS_EcuM_02798*/
    if(NULL_PTR == EcuM_PBConfig)
    {
        EcuM_ErrorHook(ECUM_E_CONFIGURATION_DATA_INCONSISTENT);
    }
    else
    {
        if(EcuM_CheckConfigConsistency(EcuM_PBConfig) != E_OK)
        {
            EcuM_ErrorHook(ECUM_E_CONFIGURATION_DATA_INCONSISTENT);
        }
    
        EcuM_AL_DriverInitOne();   

#if(STD_ON == ECUM_WAKEUPSOURCE_RESETREASON)
        /*Get the last wakeup source*/
        lastWkSrc = EcuM_GetLastWakeupSource();/*SWS_EcuM_02623*/
#else
        /*Nothing detected by hardware, report ECUM_WKSOURCE_RESET.*/
        lastWkSrc = ECUM_WKSOURCE_RESET;/*SWS_EcuM_02601*/
#endif
        if(ECUM_WKSOURCE_POWER == lastWkSrc)
        {
            /*Initialize the "EcuM RAM"*/
#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
            EcuM_CurrentClock = 0U;
#endif
        }

#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
        wkSrcId = EcuM_MakeWakeupSourceId(&lastWkSrc);
        /*Donot disable wakeup sources that power on*/
        /*EcuM_DisableWakeupSources(lastWkSrc);*/
        EcuM_ValidateWakeupSource(wkSrcId);
#endif

        /*SWS_EcuM_02181*/
        /*EcuM_CurrentShutdownTarget = EcuM_PBConfig->DefaultTarget;*/
        /*EcuM_CurrentShutdownMode = EcuM_PBConfig->DefaultMode;*/
        (void)EcuM_SelectShutdownTarget((EcuM_PBConfig->DefaultTarget), (EcuM_PBConfig->DefaultMode));

#if(STD_ON == ECUM_RESET_LOOP_DETECTION)
        EcuM_LoopDetection();
#endif
#if(ECUM_CORE_NUMBER > 1)
        /*TODO: Multi-Core Support*/
#if(ECUM_OS_USED == STD_ON)
        for(CoreId = 0U; CoreId < (uint8)ECUM_CORE_NUMBER; CoreId++)
        {
            if(CoreId != ECUM_CORE_MASTER_ID)
            {
                StartCore(CoreId, &CoreStatus);
            }

            if(CoreStatus != E_OK)
            {
                EcuM_ErrorHook(ECUM_E_INIT_FAILED);
            }
        }
#endif
#endif
    }
}

#if(ECUM_CORE_NUMBER > 1)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_InitSlave
*
* Description:   Initializes the EcuM Slave and carries out the startup
*                procedure.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, ECUM_CODE) EcuM_InitSlave
(
    uint8 CoreId
)
{
    /*TODO: Multi-Core Support*/
#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
    EcuM_AbortAllWakeupAlarm(); /*SWS_EcuM_04010*/
#endif

    ECUM_SET_STATE(ECUM_STATE_STARTUP_ONE);
    /*STARTUP Phase - StartPreOS Sequence. SWS_EcuM_02411,SWS_EcuM_02684*/
#if(STD_ON == EcuM_SETPROGRAMMABLEINTERRUPTS_SUPPORT)
    EcuM_AL_SetProgrammableInterrupts();
#endif
    /*SWS_EcuM_04146*/   
    EcuM_AL_DriverInitZero();
    EcuM_PBConfig = EcuM_DeterminePbConfiguration();
    /*SWS_EcuM_02798*/
    if(NULL_PTR == EcuM_PBConfig)
    {
        EcuM_ErrorHook(ECUM_E_CONFIGURATION_DATA_INCONSISTENT);
    }
    else
    {
        if(EcuM_CheckConfigConsistency(EcuM_PBConfig) != E_OK)
        {
            EcuM_ErrorHook(ECUM_E_CONFIGURATION_DATA_INCONSISTENT);
        }
        EcuM_AL_DriverInitOne();
    }
    

}

#endif

#define ECUM_STOP_SEC_CODE
#include "EcuM_MemMap.h"

/*******************************************************************************
*  PUBLIC Functions define
*******************************************************************************/
#define ECUM_START_SEC_CODE
#include "EcuM_MemMap.h"
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_Init    SWS_EcuM_02811
*
* Description:   Initializes the ECU state manager and carries out the startup
*                procedure.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   The function will never return.(it calls StartOs)
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CODE) EcuM_Init
(
    void
)
{
    
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
    if(ECUM_CORE_MASTER_ID != CoreId)
    {
        /*SWS_EcuM_04017*/
        EcuM_InitSlave(CoreId);
    }
    else
#endif
    {
        /*SWS_EcuM_04015*/
        EcuM_InitMaster();
    }
#if(ECUM_CORE_NUMBER > 1)
    EcuM_NotifyInit(CoreId);
    while (NULL_PTR == EcuM_PBConfig)
    {
        /*wait Mastercore*/
    }
#endif 
#if(ECUM_OS_USED == STD_ON)
    /*SWS_EcuM_02603*//*SWS_EcuM_04093*/
    StartOS(EcuM_PBConfig->AppMode);
    /*NEVER return*/
#endif
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_StartupTwo
*
* Description:   Implements the STARTUP II state.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_02838
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CODE) EcuM_StartupTwo
(
    void
)
{
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_STATE_IS_STARTUP_ONE())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_STARTUPTWO, ECUM_E_STATE_PAR_OUT_OF_RANGE);
    }
    else
    {
#if(ECUM_CORE_NUMBER > 1)
        if(ECUM_CORE_MASTER_ID == CoreId)
#endif
        {
            /*STARTUP Phase - StartPostOS Sequence. SWS_EcuM_02932,SWS_EcuM_04016*/
#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
            EcuM_StartClock();
#endif

#if(ECUM_AR_RELEASE_MINOR_VERSION_CFG == ECUM_AR_RELEASE_MINOR_VERSION_422)
            SchM_Init();
            BswM_Init(EcuM_PBConfig->ModuleConfigPtr->BswMConfigPtr);/*SWS_EcuM_04014*/
#else
            /*SchM_Start();*/ /*Depend on whether SchM implements this interface.*/
            BswM_Init(EcuM_PBConfig->ModuleConfigPtr->BswMConfigPtr);
            SchM_Init(0);
            /*SchM_StartTiming();*/ /*Depend on whether SchM implements this interface.*/
#endif

#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
            /* Validated wkupsrc stored, notify to BswM. */
            if(EcuM_BswM_StoredWakeups != 0U)
            {
                if(0U != (ECUM_WKSRC_GET_VALIDATED_SRC() & EcuM_BswM_StoredWakeups))
                {
                    EcuM_NotifyBswMWkup(ECUM_WKSRC_GET_VALIDATED_SRC() & EcuM_BswM_StoredWakeups, ECUM_WKSTATUS_VALIDATED);
                }
            }
#endif
        }
#if(ECUM_CORE_NUMBER > 1)
        else
        {
            /*Slave Core StartPostOS Sequence - SWS_EcuM_04018*/
#if(ECUM_AR_RELEASE_MINOR_VERSION_CFG == ECUM_AR_RELEASE_MINOR_VERSION_422)
            SchM_Init();
            BswM_Init(EcuM_PBConfig->ModuleConfigPtr->BswMConfigPtr); /*SWS_EcuM_04014*/
#else
            /*SchM_Start();*/ /*Depend on whether SchM implements this interface.*/
            BswM_Init(EcuM_PBConfig->ModuleConfigPtr->BswMConfigPtr);
            SchM_Init();
            /*SchM_StartTiming();*/ /*Depend on whether SchM implements this interface.*/
#endif
        }
#endif/*#if(ECUM_CORE_NUMBER > 1)*/
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_Shutdown
*
* Description:   Shutdown the ECU. Typically called from the shutdown hook.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_02812
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CODE) EcuM_Shutdown
(
    void
)
{
#if(ECUM_CORE_NUMBER > 1)
    /*Multi-Core Support*/
    uint8 CoreId = GetCoreID();

    if(ECUM_CORE_MASTER_ID == CoreId)
    {
#endif
        /*PRQA S 2201 ++*/
        /*Consider the multi-nuclear situation here without modification */
        if(!ECUM_STATE_IS_GO_OFF_ONE())
        {
            ECUM_DET_REPORT_ERROR(ECUM_API_SHUTDOWN, ECUM_E_STATE_PAR_OUT_OF_RANGE);
        }
        else
        /*PRQA S 2201 --*/
        {
            /*SHUTDOWN Phase - OffPostOs Sequence. */ /*SWS_EcuM_04020*/
            ECUM_SET_STATE(ECUM_STATE_GO_OFF_TWO);
            EcuM_OnGoOffTwo();

            switch (EcuM_CurrentShutdownTarget)
            {
            case ECUM_SHUTDOWN_TARGET_OFF:   /*SWS_EcuM_04075*/
                EcuM_AL_SwitchOff();
                break;
            case ECUM_SHUTDOWN_TARGET_RESET: /*SWS_EcuM_04074*/
                EcuM_AL_Reset((EcuM_ResetType)EcuM_CurrentShutdownMode);
                break;
            default:
                /**/
                EcuM_ErrorHook(ECUM_E_STATE_PAR_OUT_OF_RANGE);
                break;
            }
        }
#if(ECUM_CORE_NUMBER > 1)
    }
    else
    {
        /*SWS_EcuM_04022*/
        EcuM_OnGoOffTwo();
    }
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_GoDown
*
* Description:   Instructs the ECU State Manager module to perform a power off
*                or a reset depending on the selected shutdown target.
*
* Inputs:        caller - Module ID of the calling module.
*
* Outputs:       If the request was not accepted returns E_NOT_OK.
*
* Limitations:   Only special modules are allowed to call this function.SWS_EcuM_04046
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoDown
(
    /*PRQA S 3206 ++*/
    /*This parameter caller is only used when the ECUM_GODOWN_USER_NUMBER is greater than zero*/
    EcuM_UserType caller
    /*PRQA S 3206 --*/
)
{
#if(ECUM_CORE_NUMBER > 1)
    Std_ReturnType ret = E_NOT_OK;
    /*Multi-Core Support*/
    uint8 EcuMCoreId;
    StatusType Error = 0U;
    uint8 CoreId = GetCoreID();
#endif

    if((EcuM_CurrentShutdownTarget != ECUM_SHUTDOWN_TARGET_RESET)
        && (EcuM_CurrentShutdownTarget != ECUM_SHUTDOWN_TARGET_OFF))
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_GODOWN, ECUM_E_SERVICE_DISABLED);
    }
#if(ECUM_GODOWN_USER_NUMBER > 0)
    /*SWS_EcuM_04047*/
    else if(EcuM_CheckGoDownUser((EcuM_UserType)caller) == E_OK)
    {
        /*SHUTDOWN Phase - OffPreOs Sequence. EcuM3021,EcuM3022*/
#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
        EcuM_AbortAllWakeupAlarm(); /*SWS_EcuM_04010*/
#endif

        ECUM_SET_STATE(ECUM_STATE_GO_OFF_ONE);
        /*SWS_EcuM_04019*//*SWS_EcuM_04021*/
        EcuM_OnGoOffOne();
        /*loop over every BswM running in this core*/
#if(ECUM_CORE_NUMBER > 1)
        if(ECUM_CORE_MASTER_ID == CoreId)
#endif
        {
#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
            /*ECUC_EcuM_04151*/ /*ECUC_EcuM_04152*/
            if(EcuM_PBConfig->IgnoreWakeupEvValOffPreOS == TRUE)
            {
                if(ECUM_WKSRC_IS_VALIDATED_SRC())
                {
                    /*SWS_EcuM_02756*/
                    (void)EcuM_SelectShutdownTarget(ECUM_SHUTDOWN_TARGET_RESET, (EcuM_ShutdownModeType)ECUM_RESET_MCU);
                }

            }
            else
            {
                if(ECUM_WKSRC_IS_DETECTED_SRC())
                {
                    /*SWS_EcuM_02756*/
                    (void)EcuM_SelectShutdownTarget(ECUM_SHUTDOWN_TARGET_RESET, (EcuM_ShutdownModeType)ECUM_RESET_MCU);
                }
            }
            
#endif
            EcuM_LastShutdownTarget = EcuM_CurrentShutdownTarget;
            EcuM_LastShutdownMode = EcuM_CurrentShutdownMode;

            /*SWS_EcuM_02952*/

#if((ECUM_CORE_NUMBER > 1)&&(ECUM_USED_EXTEND_TASK == STD_ON))
            EcuMShutdownFlag = TRUE;
            for(EcuMCoreId = 0U; EcuMCoreId < (uint8)ECUM_CORE_NUMBER; EcuMCoreId++)
            {
                if(EcuMCoreId != ECUM_CORE_MASTER_ID)
                {
                    ret = WaitEvent(ECUM_CORE_SHUTDOWM_EVENT_MASK(EcuMCoreId));
                    if(ret != E_OK)
                    {
                        EcuM_ErrorHook(ECUM_E_OS_CALL_FAILED);
                    }
                }
            }
            EcuMShutdownFlag = FALSE;
#endif
            BswM_Deinit();
            SchM_Deinit();
#if(ECUM_OS_USED == STD_ON)
#if(ECUM_CORE_NUMBER > 1)
            ShutdownAllCores(Error);
#else
            ShutdownOS(0U);
#endif
#endif
            /*NEVER return*/
        }
#if((ECUM_CORE_NUMBER > 1) && (ECUM_USED_EXTEND_TASK == STD_ON))
        else
        {
            do
            {
                if(EcuMShutdownFlag == TRUE)
                {
                    ret = SetEvent(ECUM_CORE_TASKID(ECUM_CORE_MASTER_ID), ECUM_CORE_SHUTDOWM_EVENT_MASK(CoreId));
                    if(ret != E_OK)
                    {
                        EcuM_ErrorHook(ECUM_E_OS_CALL_FAILED);
                    }
                }
            } while(ret != E_OK);
        }
#endif
    }
#endif/*#if(ECUM_GODOWN_USER_NUMBER > 0)*/
    else
    {
    }
    return E_NOT_OK;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_GoDownHaltPoll    SWS_EcuM_91002
*
* Description:   Instructs the ECU State Manager module to go into a sleep mode,
*                Reset or OFF depending on the previously selected shutdown target.
*
* Inputs:        caller - Module ID of the calling module. Only special modules
*                         are allowed to call this function and only valid when
*                         shutdown target is RESET or OFF.
*
* Outputs:       E_NOT_OK: The request was not accepted.
*                E_OK: If the ShutdownTargetType is SLEEP the call successfully
*                      returns, the ECU has left the sleep again. If the
*                      ShutdownTargetType is RESET or OFF this call will not return.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoDownHaltPoll
(
    EcuM_UserType UserID
)
{
#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
    P2CONST(EcuM_SleepModeType, AUTOMATIC, ECUM_VAR) sleepMode;
#endif
    Std_ReturnType ret = E_NOT_OK;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_GODOWNHALTPOLL, ECUM_E_UNINIT);
    }
    else if((EcuM_CurrentShutdownTarget == ECUM_SHUTDOWN_TARGET_RESET) \
        || (EcuM_CurrentShutdownTarget == ECUM_SHUTDOWN_TARGET_OFF))
    {
        ret = EcuM_GoDown(UserID);
    }
#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
    else if((EcuM_CurrentShutdownTarget == ECUM_SHUTDOWN_TARGET_SLEEP) \
        && (EcuM_CurrentShutdownMode < (EcuM_ShutdownModeType)ECUM_SLEEP_MODE_NUMBER))
    {
        sleepMode = ECUM_GET_SLEEP_MODE(EcuM_CurrentShutdownMode);

        if((boolean)FALSE == (sleepMode->ModeSuspend))
        {
            EcuM_GoSleep(sleepMode, ECUM_SLEEP_TYPE_POLLING);
        }
        else
        {
            EcuM_GoSleep(sleepMode, ECUM_SLEEP_TYPE_HALT);
        }
    }
#endif
    else
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_GODOWNHALTPOLL, ECUM_E_STATE_PAR_OUT_OF_RANGE);
    }
    
    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_SetState    SWS_EcuM_04122
*
* Description:   Function called by BswM to notify about State Switch.
*
* Inputs:        state - State indicated by BswM
*
* Outputs:       None.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CODE) EcuM_SetState
(
    EcuM_StateType state
)
{
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SETSTATE, ECUM_E_UNINIT);
    }
    else if((state != ECUM_STATE_STARTUP)
            && (state != ECUM_STATE_RUN)
            && (state != ECUM_STATE_APP_RUN)
            && (state != ECUM_STATE_APP_POST_RUN)
            && (state != ECUM_STATE_SHUTDOWN)
            && (state != ECUM_STATE_SLEEP))
    {
        /*SWS_EcuM_04123*/
        ECUM_DET_REPORT_ERROR(ECUM_API_SETSTATE, ECUM_E_STATE_PAR_OUT_OF_RANGE);
    }
    else
    {
        ECUM_SET_STATE(state);
        /*SWS_EcuM_04116*/  
        switch(state)
        {
        case ECUM_STATE_STARTUP:
            (void)Rte_Switch_currentMode_currentMode(RTE_MODE_EcuM_Mode_STARTUP);
            break;

        case ECUM_STATE_APP_RUN:
            (void)Rte_Switch_currentMode_currentMode(RTE_MODE_EcuM_Mode_RUN);
            break;

        case ECUM_STATE_APP_POST_RUN:
            (void)Rte_Switch_currentMode_currentMode(RTE_MODE_EcuM_Mode_POST_RUN);
            break;

        case ECUM_STATE_SHUTDOWN:
            (void)Rte_Switch_currentMode_currentMode(RTE_MODE_EcuM_Mode_SHUTDOWN);
            break;

        case ECUM_STATE_SLEEP:
            (void)Rte_Switch_currentMode_currentMode(RTE_MODE_EcuM_Mode_SLEEP);
            break;
        /*PRQA S 2016 ++*/
        /*The program does not do anything by default without modification */
        default:
        /*PRQA S 2016 --*/
            break;
        }    
    }
}

#if(STD_ON == ECUM_MODEHANDLING_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_RequestRUN    SWS_EcuM_04124
*
* Description:   Places a request for the RUN state. Requests can be placed by
*                every user made known to the state manager at configuration time.
*
* Inputs:        user - ID of the entity requesting the RUN state.
*
* Outputs:       None.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_RequestRUN
(
    EcuM_UserType user
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_REQUESTRUN, ECUM_E_UNINIT);
    }
    else if(user >= (EcuM_UserType)ECUM_USER_NUMBER)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_REQUESTRUN, ECUM_E_INVALID_PAR);
    }
    else if(EcuM_UserRunRequest[user] == ECUM_RUNSTATUS_REQUESTED) /*SWS_EcuM_03024*/
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_REQUESTRUN, ECUM_E_MULTIPLE_RUN_REQUESTS);
    }
    else
    {
        SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_4();
        EcuM_UserRunRequest[user] = ECUM_RUNSTATUS_REQUESTED;
        /*PRQA S 3383 ++*/
        /*This parameter is relevant to the number of users and the type of user is consistent with the parameter, so there will be no overflow.*/
        EcuMRunUserCnt++;
        /*PRQA S 3383 --*/
        /*SWS_EcuM_04118*/

        if((uint8)1 == EcuMRunUserCnt)
        {
            BswM_EcuM_RequestedState(ECUM_STATE_APP_RUN, ECUM_RUNSTATUS_REQUESTED);
        }
        else
        {
            
        }
        SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_4();
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_ReleaseRUN    SWS_EcuM_04127
*
* Description:   Releases a RUN request previously done with a call to EcuM_RequestRUN.
*                The service is intended for implementing AUTOSAR ports.
*
* Inputs:        user - ID of the entity releasing the RUN state.
*
* Outputs:       None.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_ReleaseRUN
(
    EcuM_UserType user
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_RELEASERUN, ECUM_E_UNINIT);
    }
    else if(user >= (EcuM_UserType)ECUM_USER_NUMBER)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_RELEASERUN, ECUM_E_INVALID_PAR);
    }
    else if(EcuM_UserRunRequest[user] != ECUM_RUNSTATUS_REQUESTED) /*SWS_EcuM_03023*/
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_RELEASERUN, ECUM_E_MISMATCHED_RUN_RELEASE);
    }
    else
    {
        SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_4();
        EcuM_UserRunRequest[user] = ECUM_RUNSTATUS_RELEASED;
        /*PRQA S 3383 ++*/
        /*This parameter is relevant to the number of users and the type of user is consistent with the parameter, so there will be no overflow.*/
        EcuMRunUserCnt--;
        /*PRQA S 3383 --*/
        /*SWS_EcuM_04117*/
        if(((uint8)0 == EcuMRunUserCnt) && (EcuMPostRunUserCnt > (uint8)0))
        {
            BswM_EcuM_RequestedState(ECUM_STATE_APP_POST_RUN, ECUM_RUNSTATUS_RELEASED);
        }
        /*SWS_EcuM_04119*/
        else if(((uint8)0 == EcuMPostRunUserCnt) && ((uint8)0 == EcuMRunUserCnt))
        {
            BswM_EcuM_RequestedState(ECUM_STATE_SHUTDOWN, ECUM_RUNSTATUS_RELEASED);
        }
        else
        {
            
        }
     
        SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_4();
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_RequestPOST_RUN    SWS_EcuM_04128
*
* Description:   Places a request for the POST RUN state. Requests can be placed
*                by every user made known to the state manager at configuration time.
*                Requests for RUN and POST RUN must be tracked independently (in other
*                words: two independent variables).
*                The service is intended for implementing AUTOSAR ports.
*
* Inputs:        user - ID of the entity requesting the POST RUN state.
*
* Outputs:       None.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_RequestPOST_RUN
(
    EcuM_UserType user
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_REQUESTPOSTRUN, ECUM_E_UNINIT);
    }
    else if(user >= (EcuM_UserType)ECUM_USER_NUMBER)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_REQUESTPOSTRUN, ECUM_E_INVALID_PAR);
    }
    else if(EcuM_UserPostRunRequest[user] == ECUM_RUNSTATUS_REQUESTED) /*SWS_EcuM_03025*/
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_REQUESTPOSTRUN, ECUM_E_MULTIPLE_RUN_REQUESTS);
    }
    else
    {
        SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_4();
        EcuM_UserPostRunRequest[user] = ECUM_RUNSTATUS_REQUESTED;
        /*PRQA S 3383 ++*/
        /*This parameter is relevant to the number of users and the type of user is consistent with the parameter, so there will be no overflow.*/
        EcuMPostRunUserCnt++;
        /*PRQA S 3383 --*/
        SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_4();
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_ReleasePOST_RUN    SWS_EcuM_04129
*
* Description:   Releases a POST RUN request previously done with a call to
*                EcuM_RequestPOST_RUN. The service is intended for implementing
*                AUTOSAR ports.
*
* Inputs:        user - ID of the entity requesting the POST RUN state.
*
* Outputs:       None.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_ReleasePOST_RUN
(
    EcuM_UserType user
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_RELEASEPOSTRUN, ECUM_E_UNINIT);
    }
    else if(user >= (EcuM_UserType)ECUM_USER_NUMBER)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_RELEASEPOSTRUN, ECUM_E_INVALID_PAR);
    }
    else if(EcuM_UserPostRunRequest[user] != ECUM_RUNSTATUS_REQUESTED) /*SWS_EcuM_03026*/
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_RELEASEPOSTRUN, ECUM_E_MISMATCHED_RUN_RELEASE);
    }
    else
    {
        SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_4();
        EcuM_UserPostRunRequest[user] = ECUM_RUNSTATUS_RELEASED;
        /*PRQA S 3383 ++*/
        /*This parameter is relevant to the number of users and the type of user is consistent with the parameter, so there will be no overflow.*/
        EcuMPostRunUserCnt--;
        /*PRQA S 3383 --*/
        /*SWS_EcuM_04119*/

        if(((uint8)0 == EcuMPostRunUserCnt) && ((uint8)0 == EcuMRunUserCnt))
        {
            BswM_EcuM_RequestedState(ECUM_STATE_SHUTDOWN, ECUM_RUNSTATUS_RELEASED);
        }
        else
        {

        }
        SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_4();
        ret = E_OK;
    }

    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_SelectShutdownTarget    SWS_EcuM_02822
*
* Description:   Selects the shutdown target.
*
* Inputs:        shutdownTarget - The selected shutdown target
*                shutdownMode   - The identfier of a sleep mode (if target is
*                                 ECUM_STATE_SLEEP) or a reset mechanism (if target
*                                 is ECUM_STATE_RESET) as defined by configuration.
*
* Outputs:       If this service has succeeded returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownTarget
(
    EcuM_ShutdownTargetType shutdownTarget,
    EcuM_ShutdownModeType shutdownMode
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SELECTSHUTDOWNTARGET, ECUM_E_UNINIT);
    }
    else if((shutdownTarget != ECUM_SHUTDOWN_TARGET_OFF)
#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
            && (shutdownTarget != ECUM_SHUTDOWN_TARGET_SLEEP)
#endif
            && (shutdownTarget != ECUM_SHUTDOWN_TARGET_RESET))
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SELECTSHUTDOWNTARGET, ECUM_E_STATE_PAR_OUT_OF_RANGE);
    }
#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
    else if((ECUM_SHUTDOWN_TARGET_SLEEP == shutdownTarget)
            && (shutdownMode >= (EcuM_ShutdownModeType)ECUM_SLEEP_MODE_NUMBER))
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SELECTSHUTDOWNTARGET, ECUM_E_INVALID_PAR);
    }
#endif
    else if((ECUM_SHUTDOWN_TARGET_RESET == shutdownTarget)
            && (shutdownMode >= (EcuM_ShutdownModeType)ECUM_RESET_NUMBER))
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SELECTSHUTDOWNTARGET, ECUM_E_INVALID_PAR);
    }
    else
    {
        /*SWS_EcuM_00624 SWS_EcuM_02185 SWS_EcuM_02585*/
        EcuM_CurrentShutdownTarget = shutdownTarget;
        EcuM_CurrentShutdownMode = shutdownMode;
        ret = E_OK;
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_GetShutdownTarget    SWS_EcuM_02824
*
* Description:   Returns the currently selected shutdown target as set by
*                EcuM_SelectShutdownTarget.
*
* Inputs:        None
*
* Outputs:       shutdownTarget - The shutdown target
*                shutdownMode   - If the out parameter "shutdownTarget" is
*                                 ECUM_STATE_SLEEP,sleepMode tells which of the
*                                 configured sleep modes was actually chosen.
*                                 If "shutdownTarget" is ECUM_STATE_RESET,
*                                 sleepMode tells which of the configured reset
*                                 modes was actually chosen.
*                If this service has succeeded returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownTarget
(
    P2VAR(EcuM_ShutdownTargetType, AUTOMATIC, ECUM_APPL_DATA) shutdownTarget,
    P2VAR(EcuM_ShutdownModeType, AUTOMATIC, ECUM_APPL_DATA) shutdownMode
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_GETLASTSHUTDOWNTARGET, ECUM_E_UNINIT);
    }
    else if(NULL_PTR == shutdownTarget)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_GETLASTSHUTDOWNTARGET, ECUM_E_NULL_POINTER);
    }
    else
    {
        *shutdownTarget = EcuM_CurrentShutdownTarget;
        if(shutdownMode != NULL_PTR)
        {
            *shutdownMode = EcuM_CurrentShutdownMode;
        }
        else
        {
            /*SWS_EcuM_02788*/
            ECUM_DET_REPORT_ERROR(ECUM_API_GETLASTSHUTDOWNTARGET, ECUM_E_NULL_POINTER);
        }
        ret = E_OK;
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_GetLastShutdownTarget    SWS_EcuM_02825
*
* Description:   Returns the shutdown target of the previous shutdown process.
*
* Inputs:        None
*
* Outputs:       shutdownTarget - The shutdown target
*                shutdownMode   - If the out parameter "shutdownTarget" is
*                                 ECUM_STATE_SLEEP,sleepMode tells which of the
*                                 configured sleep modes was actually chosen.
*                                 If "shutdownTarget" is ECUM_STATE_RESET,
*                                 sleepMode tells which of the configured reset
*                                 modes was actually chosen.
*                If this service has succeeded returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetLastShutdownTarget
(
    P2VAR(EcuM_ShutdownTargetType, AUTOMATIC, ECUM_APPL_DATA) shutdownTarget,
    P2VAR(EcuM_ShutdownModeType, AUTOMATIC, ECUM_APPL_DATA) shutdownMode
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_GETLASTSHUTDOWNTARGET, ECUM_E_UNINIT);
    }
    else if(NULL_PTR == shutdownTarget)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_GETLASTSHUTDOWNTARGET, ECUM_E_NULL_POINTER);
    }
    else
    {
        /*SWS_EcuM_02156 SWS_EcuM_02336*/
        *shutdownTarget = EcuM_LastShutdownTarget;
        if(shutdownMode != NULL_PTR)
        {
            *shutdownMode = EcuM_LastShutdownMode;
        }
        else
        {
            /*SWS_EcuM_02337*/
            ECUM_DET_REPORT_ERROR(ECUM_API_GETLASTSHUTDOWNTARGET, ECUM_E_NULL_POINTER);
        }
        ret = E_OK;
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_SelectShutdownCause    SWS_EcuM_04050
*
* Description:   EcuM_SelectShutdownCause selects the cause for a shutdown
*
* Inputs:        cause - The selected cause.
*
* Outputs:       If this service has succeeded returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownCause
(
    EcuM_ShutdownCauseType target
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SELECTSHUTDOWNCAUSE, ECUM_E_UNINIT);
    }
    else if(target >= (EcuM_ShutdownCauseType)ECUM_CAUSE_NUMBER)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SELECTSHUTDOWNCAUSE, ECUM_E_INVALID_PAR);
    }
    else
    {
        EcuM_CurrentShutdownCause = target;
        ret = E_OK;
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_GetShutdownCause    SWS_EcuM_04051
*
* Description:   Returns the selected shutdown cause.
*
* Inputs:        None
*
* Outputs:       cause - The selected cause of the next shutdown.
*                If this service has succeeded returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownCause
(
    P2VAR(EcuM_ShutdownCauseType, AUTOMATIC, ECUM_APPL_DATA) shutdownCause
)
{

    Std_ReturnType ret = E_NOT_OK;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_GETSHUTDOWNCAUSE, ECUM_E_UNINIT);
    }
    else if(NULL_PTR == shutdownCause)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_GETSHUTDOWNCAUSE, ECUM_E_NULL_POINTER);
    }
    else
    {
        *shutdownCause = EcuM_CurrentShutdownCause;
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_SelectBootTarget    SWS_EcuM_02835
*
* Description:   Selects a boot target.
*
* Inputs:        target -  The selected boot target.
*
* Outputs:       If the boot target was accepted returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectBootTarget
(
    EcuM_BootTargetType target
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SELECTBOOTTARGET, ECUM_E_UNINIT);
    }
    else if(target >= ECUM_BOOT_TARGET_MAX_NUMBER)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SELECTBOOTTARGET, ECUM_E_INVALID_PAR);
    }
    else
    {
        /*SWS_EcuM_04051 SWS_EcuM_03000*/
        EcuM_BootTarget = target;
        ret = E_OK;
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_GetBootTarget    SWS_EcuM_02836
*
* Description:   Returns the current boot target.
*
* Inputs:        None
*
* Outputs:       target - The currently selected boot target.
*
* Limitations:   This function always succeeds.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetBootTarget
(
    P2VAR(EcuM_BootTargetType, AUTOMATIC, ECUM_APPL_DATA) target
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_GETBOOTTARGET, ECUM_E_UNINIT);
    }
    else if(NULL_PTR == target)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_GETBOOTTARGET, ECUM_E_NULL_POINTER);
    }
    else
    {
        *target = EcuM_BootTarget;
        ret = E_OK;
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_MainFunction    SWS_EcuM_02837
*
* Description:   This function is used to implement all activities of the EcuM
*                while the OS is up and running.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CODE) EcuM_MainFunction
(
    void
)
{
#if(ECUM_COMM_WAKEUP_NOTIFICATION == STD_ON)
    uint8 wkSrcId = (uint8)ECUM_WKSOURCE_NUMBER;
#endif
#if(ECUM_CORE_NUMBER > 1)
    Std_ReturnType ret = E_NOT_OK;
    /*Multi-Core Support*//*SWS_EcuM_04011*/
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_MAINFUNCTION, ECUM_E_UNINIT);
    }
    else
    {
#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
#if(ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
        /*SWS_EcuM_04149*//*SWS_EcuM_04150*/
        if(ECUM_SET_CHECKWKUP_FLAG == (boolean)TRUE)
        {
            if(ECUM_GET_CHECKWKUP_TIMEOUT > (uint16)0)
            {
                ECUM_RUN_CHECKWKUP_TIMEOUT;
            }
            else
            {
                ECUM_DET_REPORT_ERROR(ECUM_API_MAINFUNCTION, ECUM_E_WAKEUP_TIMEOUT);
            }
        }

        EcuM_EvaluateWakeupEvent();
#endif

#if(ECUM_COMM_WAKEUP_NOTIFICATION == STD_ON)
#if(ECUM_CORE_NUMBER > 1)
        if(CoreId == ECUM_CORE_MASTER_ID)
#endif
        {
            /* Process stored wakeups to notifying the ComM*/
            while((EcuM_ComM_StoredWakeups != 0u) && (wkSrcId > (uint8)0))
            {
                wkSrcId--;
                if((((EcuM_WakeupSourceType)1 << wkSrcId) & EcuM_ComM_StoredWakeups) != 0U)
                {
                    EcuM_NotifyComMWkup(wkSrcId);
                }
            }
            
#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
            if(ECUM_STATE_IS_RUN() || ECUM_STATE_IS_APP_RUN())
            {
                EcuM_CheckAlarmTimeout();
            }
#endif
        }
#endif
#endif

    }
}

#if(ECUM_VERSION_INFO_API == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_GetVersionInfo    SWS_EcuM_02813
*
* Description:   This function returns the version information of EcuM module.
*
* Inputs:        versioninfo - Pointer to where to store the version information
*                              of this module
*
* Outputs:       None
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CODE) EcuM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, ECUM_APPL_DATA) versioninfo
)
{
    /*This interface does NOT check if the EcuM is initialized.*/
    if(NULL_PTR == versioninfo)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_GETVERSIONINFO, ECUM_E_NULL_POINTER);
    }
    else
    {
        /*SWS_EcuM_02728*/
        versioninfo->moduleID = ECUM_MODULE_ID;
        versioninfo->vendorID = ECUM_VENDOR_ID;
        versioninfo->sw_major_version = (uint8)ECUM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)ECUM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)ECUM_SW_PATCH_VERSION;
    }
}
#endif /*ECUM_VERSION_INFO_API == STD_ON*/

#if(ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_GetValidatedWakeupEvents    SWS_EcuM_02830
*
* Description:   Returns the VALIDATED wakeup events.
*
* Inputs:        None
*
* Outputs:       The VALIDATED wakeup events
*
* Limitations:   Non-Reentrant, Non-Interruptible.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetValidatedWakeupEvents
(
    void
)
{
    EcuM_WakeupSourceType wkEvents;

    SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_0();
    wkEvents = ECUM_WKSRC_GET_VALIDATED_SRC();
    SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_0();

    return wkEvents;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_ClearWakeupEvent    SWS_EcuM_02828
*
* Description:   Clears wakeup events.
*
* Inputs:        sources - Events to be cleared
*
* Outputs:       None
*
* Limitations:   Non-Reentrant, Non-Interruptible.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CODE) EcuM_ClearWakeupEvent
(
    EcuM_WakeupSourceType sources
)
{
    if(ECUM_WKSRC_IS_VALID_SRC(sources))
    {
        /*PRQA S 3112 ++*/
        /*When ECUM_WAKEUPSOURCE_VALIDATION == STD_OFF, there do nothing  */
        SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_0();
        ECUM_WKSRC_CLEAR_PENDING_SRC(sources);
        ECUM_WKSRC_CLEAR_VALIDATED_SRC(sources);
        ECUM_WKSRC_CLEAR_EXPIRED_SRC(sources);
        SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_0();
        EcuM_NotifyBswMWkup(sources, ECUM_WKSTATUS_NONE);
        /*PRQA S 3112 --*/
    }
}

#if(ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_GetPendingWakeupEvents    SWS_EcuM_02827
*
* Description:   Returns the PENDING wakeup events.
*
* Inputs:        None
*
* Outputs:       The PENDING wakeup events
*
* Limitations:   Non-Reentrant, Non-Interruptible.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetPendingWakeupEvents
(
    void
)
{
    EcuM_WakeupSourceType wkEvents;

    SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_0();
    wkEvents = ECUM_WKSRC_GET_PENDING_SRC();
    SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_0();

    return wkEvents;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_GetExpiredWakeupEvents    SWS_EcuM_02831
*
* Description:   Returns the EXPIRED wakeup events.
*
* Inputs:        None
*
* Outputs:       The EXPIRED wakeup events
*
* Limitations:   Non-Reentrant, Non-Interruptible.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetExpiredWakeupEvents
(
    void
)
{
    EcuM_WakeupSourceType wkEvents;

    SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_0();
    wkEvents = ECUM_WKSRC_GET_EXPIRED_SRC();
    SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_0();

    return wkEvents;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_SetWakeupEvent    SWS_EcuM_02826
*
* Description:   Sets the wakeup event
*
* Inputs:        sources - the source.
*
* Outputs:       None
*
* Limitations:   the sources only includes one source.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent
(
    VAR(EcuM_WakeupSourceType, ECUM_APPL_DATA) sources
)
{
    uint8 wkSrcId;
    P2CONST(EcuM_SleepModeType, AUTOMATIC, ECUM_VAR) sleepMode;
#if(ECUM_CORE_NUMBER > 1)
    /*Multi-Core Support*//*SWS_EcuM_04011*/
    uint8 CoreId = GetCoreID();
#endif

    EcuM_WakeupSourceType WkSrc = sources;

    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SETWAKEUPEVENT, ECUM_E_UNINIT);
    }
    /*PRQA S 3383 ++*/
    /*This parameter is large enough, and the code does not need to be modified considering the actual usage of the situation */
    else if((!ECUM_WKSRC_IS_VALID_SRC(sources))
        || (!ECUM_WKSRC_IS_ONLY_SRC(sources)))
    /*PRQA S 3383 --*/
    {
        /*SWS_EcuM_02867*/
        ECUM_DET_REPORT_ERROR(ECUM_API_SETWAKEUPEVENT, ECUM_E_UNKNOWN_WAKEUP_SOURCE);
    }
    else if(EcuM_CurrentShutdownTarget != ECUM_SHUTDOWN_TARGET_SLEEP)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SETWAKEUPEVENT, ECUM_E_STATE_PAR_OUT_OF_RANGE);
    }
    else if(EcuM_CurrentShutdownMode >= (EcuM_ShutdownModeType)ECUM_SLEEP_MODE_NUMBER)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SETWAKEUPEVENT, ECUM_E_STATE_PAR_OUT_OF_RANGE);
    }
    else
    {
        sleepMode = ECUM_GET_SLEEP_MODE(EcuM_CurrentShutdownMode);
        /*SWS_EcuM_04138*/
        if(ECUM_IS_WAKEUPSOURCE(WkSrc, (sleepMode->WkSourceMask)))
        {
            if(ECUM_SET_CHECKWKUP_FLAG == TRUE)
            {
                ECUM_SET_CHECKWKUP_FLAG = FALSE;
                ECUM_GET_CHECKWKUP_TIMEOUT = 0U;
            }
            /*ECUM_WKSRC_CLEAR_ENABLED_SRC() and EcuM_DisableWakeupSources() should be called at the same time.*/
            ECUM_WKSRC_CLEAR_ENABLED_SRC(sources);
            EcuM_DisableWakeupSources(sources);
            wkSrcId = EcuM_MakeWakeupSourceId(&WkSrc);

            if(ECUM_WKSRC_GET_TIMEOUT(wkSrcId) != (EcuM_WakeupSourceType)0)
            {
                /*SWS_EcuM_02707*/
                EcuM_StartValidationTimer(wkSrcId);
                SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_0();
                /*SWS_EcuM_01117*/
                ECUM_WKSRC_SET_PENDING_SRC(sources);
                ECUM_WKSRC_SET_CACHEDPENDING(sources);
                EcuM_NotifyBswMWkup(sources, ECUM_WKSTATUS_PENDING);
                SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_0();
            }
            else
            {
                EcuM_ValidateWakeupSource(wkSrcId);
            }
        }
        else
        {
            /*SWS_EcuM_02867*/
            ECUM_DET_REPORT_ERROR(ECUM_API_SETWAKEUPEVENT, ECUM_E_UNKNOWN_WAKEUP_SOURCE);
        }
    }
}
#endif /*ECUM_WAKEUPSOURCE_VALIDATION == STD_ON*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_ValidateWakeupEvent    SWS_EcuM_02829
*
* Description:   This API service is used to indicate to the ECU Manager module
*                that the wakeup events indicated in the sources parameter have
*                been validated.
*
* Inputs:        sources - the sources will be validated.
*
* Outputs:       None
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CODE) EcuM_ValidateWakeupEvent
(
    VAR(EcuM_WakeupSourceType, ECUM_APPL_DATA) sources
)
{
    uint8 wkSrcId;
    EcuM_WakeupSourceType WkSrc = sources;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_VALIDATEWAKEUPEVENT, ECUM_E_UNINIT);
    }
    /*PRQA S 3383 ++*/
    /*This parameter is large enough, and the code does not need to be modified considering the actual usage of the situation */
    else if((!ECUM_WKSRC_IS_VALID_SRC(sources)) /*SWS_EcuM_02868*/
            || (!ECUM_WKSRC_IS_ONLY_SRC(sources)))
    /*PRQA S 3383 --*/
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_VALIDATEWAKEUPEVENT, ECUM_E_UNKNOWN_WAKEUP_SOURCE);
    }
    else
    {
        ECUM_WKSRC_CLEAR_ENABLED_SRC(sources);
        EcuM_DisableWakeupSources(sources);
        wkSrcId = EcuM_MakeWakeupSourceId(&WkSrc);
        /*SWS_EcuM_04078*/
        EcuM_ValidateWakeupSource(wkSrcId);
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_CheckWakeup    SWS_EcuM_91007
*
* Description:   This function can be called to check the given wakeup sources. 
*                It will pass the argument to the integrator function EcuM_CheckWakeupHook. 
*                It can also be called by the ISR of a wakeup
*                source to set up the PLL and check other wakeup sources that may be 
*                connected to the same interrupt.
*
* Inputs:        sources 
*
* Outputs:       None
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CODE) EcuM_CheckWakeup 
(
    EcuM_WakeupSourceType wakeupSource
)
{
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
    EcuM_WakeupSourceType CoreWkSrcMask = ECUM_CORE_WAKEUPSOURCEMASK(CoreId);
    wakeupSource &= CoreWkSrcMask;
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_CHECKWAKEUP, ECUM_E_UNINIT);
    }
    else
    {
        EcuM_CheckWakeupHook(wakeupSource);
    }
}

#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_SetRelWakeupAlarm    SWS_EcuM_04054
*
* Description:   Sets a user's wakeup alarm relative to the current point in
*                time.
*
* Inputs:        user - The user that wants to set the wakeup alarm.
*                time - Relative time from now in seconds.
*
* Outputs:       if this service has succeeded returns E_OK, otherwise returns
*                E_NOT_OK
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetRelWakeupAlarm
(
    EcuM_UserType user,
    EcuM_TimeType time
)
{
    Std_ReturnType ret = E_NOT_OK;
    EcuM_TimeType Cur_Clock;

    SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_1();
    Cur_Clock = EcuM_CurrentClock;
    SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_1();
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SETRELWAKEUPALARM, ECUM_E_UNINIT);
    }
    else if(user >= (EcuM_UserType)ECUM_USER_NUMBER)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SETRELWAKEUPALARM, ECUM_E_INVALID_PAR);
    }
    /*PRQA S 3383 ++*/
    /*This parameter(Cur_Clock) is large enough, and the code does not need to be modified considering the actual usage of the situation*/
    else if((Cur_Clock + time) <= Cur_Clock)
    /*PRQA S 3383 --*/
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SETRELWAKEUPALARM, ECUM_E_INVALID_PAR);
    }
    else
    {
        /*PRQA S 3383 ++*/
        /*This parameter(Cur_Clock) is large enough, and the code does not need to be modified considering the actual usage of the situation*/
        ret = EcuM_SetWakeupAlarm(user, Cur_Clock + time);
        /*PRQA S 3383 --*/
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_SetAbsWakeupAlarm    SWS_EcuM_04057
*
* Description:   Sets the user's wakeup alarm to an absolute point in time.
*
* Inputs:        user - The user that wants to set the wakeup alarm.
*                time - Absolute time in seconds. Note that, absolute alarms use
*                       knowledge of the current time.
*
* Outputs:       if this service has succeeded returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetAbsWakeupAlarm
(
    EcuM_UserType user,
    EcuM_TimeType time
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SETABSWAKEUPALARM, ECUM_E_UNINIT);
    }
    else if(user >= (EcuM_UserType)ECUM_USER_NUMBER)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SETABSWAKEUPALARM, ECUM_E_INVALID_PAR);
    }
    else
    {
        ret = EcuM_SetWakeupAlarm(user, time);
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_AbortWakeupAlarm    SWS_EcuM_04061
*
* Description:   Aborts the wakeup alarm previously set by this user.
*
* Inputs:        user - The user that wants to cancel the wakeup alarm.
*
* Outputs:       if this service has succeeded returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_AbortWakeupAlarm
(
    EcuM_UserType user
)
{
    EcuMAlarmIdType alarm;
    Std_ReturnType ret = E_NOT_OK;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_ABORTWAKEUPALARM, ECUM_E_UNINIT);
    }
    else if(user >= (EcuM_UserType)ECUM_USER_NUMBER)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_ABORTWAKEUPALARM, ECUM_E_INVALID_PAR);
    }
    else
    {
        alarm = EcuM_UserAlarm[user];

        if(!ECUM_ALARM_IS_VALID(alarm))
        {
            /*ret = E_NOT_OK;*/
        }
        else if(ECUM_ALARM_GET_TIME(alarm) == (EcuM_TimeType)0)
        {
            ret = ECUM_E_NOT_ACTIVE;
        }
        else
        {
            SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_2();
            ECUM_ALARM_CLEAR_TIME(alarm);
            if(ECUM_ALARM_IS_MASTER(alarm))
            {
                /*SWS_EcuM_04072*/
#if(ECUM_ALARM_CLOCK_NUMBER == 1)
                ECUM_ALARM_SET_MASTER(ECUM_INVALID_ALARMID);
#else
                ECUM_ALARM_SET_MASTER(EcuM_FindEarliestUserAlarm());
#endif
            }
            SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_2();
            ret = E_OK;
        }
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_GetCurrentTime    SWS_EcuM_04062
*
* Description:   Returns the current value of the EcuM clock.
*
* Inputs:        None
*
* Outputs:       time - Absolute time in seconds since battery connect.
*                if this service has succeeded returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetCurrentTime
(
    P2VAR(EcuM_TimeType, AUTOMATIC, ECUM_APPL_DATA) time
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_GETCURRENTTIME, ECUM_E_UNINIT);
    }
    else if(NULL_PTR == time)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_GETCURRENTTIME, ECUM_E_NULL_POINTER);
    }
    else
    {
        SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_1();
        *time = EcuM_CurrentClock;
        SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_1();
        ret = E_OK;
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_GetWakeupTime    SWS_EcuM_04063
*
* Description:   Returns the current value of the master alarm clock
*
* Inputs:        None
*
* Outputs:       time - Absolute time in seconds for next wakeup.
*                if this service has succeeded returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetWakeupTime
(
    P2VAR(EcuM_TimeType, AUTOMATIC, ECUM_APPL_DATA) time
)
{

    Std_ReturnType ret = E_NOT_OK;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_GETWAKEUPTIME, ECUM_E_UNINIT);
    }
    else if(NULL_PTR == time)
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_GETWAKEUPTIME, ECUM_E_NULL_POINTER);
    }
    else
    {
        if(ECUM_ALARM_IS_VALID(EcuM_MasterAlarmId))
        {
            SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_2();
            *time = ECUM_ALARM_GET_TIME(EcuM_MasterAlarmId);
            SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_2();
        }
        else
        {
            *time = ECUM_ALARM_INVALID_TIME;
        }
        ret = E_OK;
    }

    return ret;
}

#if(ECUM_SETCLOCK_USER_NUMBER > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_SetClock    SWS_EcuM_04064
*
* Description:   Sets the EcuM clock time to the provided value. This API is
*                useful for testing the alarm services.
*
* Inputs:        user - User that wants to set the clock
*                time - Absolute time in seconds since battery connect
*
* Outputs:       If the service has succeeded returns E_OK, otherwise returns
*                E_NOT_OK.
*
* Limitations:   This API is only used by BSW modules.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetClock
(
    EcuM_UserType user,
    EcuM_TimeType time
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_SETCLOCK, ECUM_E_UNINIT);
    }
    else
    {
#if(ECUM_SETCLOCK_USER_NUMBER == 1)
        if((EcuM_UserType)ECUM_SETCLOCK_USER_ID == user)
        {
            ret = E_OK;
        }
        else
        {
            ret = E_NOT_OK;
        }
#else
        ret = EcuM_CheckSetClockUser(user);
#endif
        if(E_OK == ret)
        {
            SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_1();
            EcuM_CurrentClock = time;
            SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_1();
        }
    }

    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_CheckClock
*
* Description:   Updates the EcuM Clock time and Checks if the master alarm is
*                timedout.
*
* Inputs:        none
*
* Outputs:       none
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CODE) EcuM_CheckClock
(
    void
)
{
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
#endif
    EcuM_UpdateClock();
    if(ECUM_STATE_IS_SLEEP()
            && ECUM_ALARM_IS_VALID(EcuM_MasterAlarmId)
            && (EcuM_CurrentClock >= ECUM_ALARM_GET_TIME(EcuM_MasterAlarmId)))
    {
        EcuM_ValidateWakeupEvent((EcuM_WakeupSourceType)ECUM_ALARM_WAKEUP_SOURCE_MASK);
    }
}
#endif /*ECUM_ALARM_CLOCK_PRESENT == STD_ON*/

#if(ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_StartCheckWakeup         SWS_EcuM_04096
*
* Description:   This API is called by the ECU Firmware to start the CheckWakeupTimer
*                for the corresponding WakeupSource.
*
* Inputs:        none
*
* Outputs:       none
*
* Limitations:
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CODE) EcuM_StartCheckWakeup
(
    EcuM_WakeupSourceType WakeupSource
)
{
#if(ECUM_CORE_NUMBER > 1)
    uint8 CoreId = GetCoreID();
    EcuM_WakeupSourceType CoreWkSrcMask = ECUM_CORE_WAKEUPSOURCEMASK(CoreId);
    WakeupSource &= CoreWkSrcMask;
#endif
    if(!ECUM_IS_INITIALIZED())
    {
        ECUM_DET_REPORT_ERROR(ECUM_API_STARTCHECKWAKEUP, ECUM_E_UNINIT);
    }
    else
    {
        if(ECUM_WKUP_CHECK_TIMEOUT(WakeupSource) > (EcuM_WakeupSourceType)0)
        {
            ECUM_SET_CHECKWKUP_FLAG = TRUE; 
            ECUM_GET_CHECKWKUP_TIMEOUT = ECUM_WKUP_CHECK_TIMEOUT(WakeupSource);
        }
    }
   
    
}
#endif
#endif /*ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON*/


#define ECUM_STOP_SEC_CODE
#include "EcuM_MemMap.h"

