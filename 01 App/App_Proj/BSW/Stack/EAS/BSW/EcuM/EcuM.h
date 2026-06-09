/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EcuM.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : The ECU state manager
*   Author          : mingqing.tang
********************************************************************************
*   Description     : The header file EcuM.h contains the declaration of the
*                     EcuM module API, 'extern' declarations of constants,
*                     global data,type definitions and services that are
*                     specified in the EcuM module SWS.
*
********************************************************************************
*   Limitations     : only used for AUTOSAR R21-11 version
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 3608, 776 EOF*/
/*
Allowed use #elif
Names in core files may not follow relevant rules.
*/

#ifndef ECUM_H
#define ECUM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EcuM_Cbk.h"
#include "SchM_EcuM.h"

/*******************************************************************************
*   Macro
*******************************************************************************/
/*SWS_EcuM_03019*/
#define ECUM_E_EARLIER_ACTIVE                   ((uint8)3)
#define ECUM_E_PAST                             ((uint8)4)
#define ECUM_E_NOT_ACTIVE                       ((uint8)5)
#define ECUM_E_RAM_CHECK_FAILED                 ((uint8)6)
#define ECUM_E_CONFIGURATION_DATA_INCONSISTENT  ((uint8)7)
#define ECUM_E_IMPROPER_CALLER                  ((uint8)8)

/*SWS_EcuM_04033*/
#define ECUM_E_OS_CALL_FAILED                   ((uint8)9)

/*SWS_EcuM_91003*/
#define ECUM_E_WAKEUP_TIMEOUT                   ((uint8)14)

#define ECUM_E_UNINIT                           ((uint8)0x10)
#define ECUM_E_SERVICE_DISABLED                 ((uint8)0x11)
#define ECUM_E_NULL_POINTER                     ((uint8)0x12)
#define ECUM_E_INVALID_PAR                      ((uint8)0x13)
#define ECUM_E_STATE_PAR_OUT_OF_RANGE           ((uint8)0x16)
#define ECUM_E_UNKNOWN_WAKEUP_SOURCE            ((uint8)0x17)
#define ECUM_E_INIT_FAILED                      ((uint8)0x18)
#define ECUM_E_MULTIPLE_RUN_REQUESTS            ((uint8)0x19)
#define ECUM_E_MISMATCHED_RUN_RELEASE           ((uint8)0x20)

#define ECUM_API_STARTCHECKWAKEUP               ((uint8)0x00)
#define ECUM_API_GETVERSIONINFO                 ((uint8)0x00)
#define ECUM_API_INIT                           ((uint8)0x01)
#define ECUM_API_SHUTDOWN                       ((uint8)0x02)
#define ECUM_API_STARTUPTWO                     ((uint8)0x1A)
#define ECUM_API_GODOWN                         ((uint8)0x1F)
#define ECUM_API_GODOWNHALTPOLL                 ((uint8)0x2C)
#define ECUM_API_SETSTATE                       ((uint8)0x2B)
#define ECUM_API_REQUESTRUN                     ((uint8)0x03)
#define ECUM_API_RELEASERUN                     ((uint8)0x04)
#define ECUM_API_REQUESTPOSTRUN                 ((uint8)0x0A)
#define ECUM_API_RELEASEPOSTRUN                 ((uint8)0x0B)
#define ECUM_API_SELECTSHUTDOWNTARGET           ((uint8)0x06)
#define ECUM_API_GETLASTSHUTDOWNTARGET          ((uint8)0x08)
#define ECUM_API_GETSHUTDOWNTARGET              ((uint8)0x09)
#define ECUM_API_SELECTSHUTDOWNCAUSE            ((uint8)0x1B)
#define ECUM_API_GETSHUTDOWNCAUSE               ((uint8)0x1C)
#define ECUM_API_GETPENDINGWAKEUPEVENTS         ((uint8)0x0D)
#define ECUM_API_GETVALIDATEDWAKEUPEVENTS       ((uint8)0x15)
#define ECUM_API_CLEARWAKEUPEVENTS              ((uint8)0x16)
#define ECUM_API_GETEXPIREDWAKEUPEVENTS         ((uint8)0x19)
#define ECUM_API_SELECTBOOTTARGET               ((uint8)0x12)
#define ECUM_API_GETBOOTTARGET                  ((uint8)0x13)
#define ECUM_API_MAINFUNCTION                   ((uint8)0x18)
#define ECUM_API_SETWAKEUPEVENT                 ((uint8)0x0C)
#define ECUM_API_VALIDATEWAKEUPEVENT            ((uint8)0x14)
#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
#define ECUM_API_SETRELWAKEUPALARM              ((uint8)0x22)
#define ECUM_API_SETABSWAKEUPALARM              ((uint8)0x23)
#define ECUM_API_ABORTWAKEUPALARM               ((uint8)0x24)
#define ECUM_API_GETCURRENTTIME                 ((uint8)0x25)
#define ECUM_API_GETWAKEUPTIME                  ((uint8)0x26)
#define ECUM_API_SETCLOCK                       ((uint8)0x27)
#endif
#define ECUM_API_CHECKWAKEUP                    ((uint8)0x49)

#if (ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_OFF)



#if (ECUM_WAKEUPSOURCE_VALIDATION == STD_OFF)
#define EcuM_GetExpiredWakeupEvents()           ECUM_WKSTATUS_NONE
#define EcuM_GetPendingWakeupEvents()           ECUM_WKSTATUS_NONE
#endif

#if (ECUM_ALARM_CLOCK_PRESENT == STD_OFF)
#define EcuM_SetRelWakeupAlarm(user,time)       E_NOT_OK
#define EcuM_SetAbsWakeupAlarm(user,time)       E_NOT_OK
#define EcuM_AbortWakeupAlarm(user)             E_NOT_OK
#define EcuM_GetCurrentTime(time)               E_NOT_OK
#define EcuM_GetWakeupTime(time)                E_NOT_OK
#define EcuM_SetClock(user,time)                E_NOT_OK
#elif (ECUM_SETCLOCK_USER_NUMBER == 0)
#define EcuM_SetClock(user,time)                E_NOT_OK
#endif /*ECUM_ALARM_CLOCK_PRESENT == STD_OFF*/
#endif /*ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_OFF*/


/*******************************************************************************
*   Global Data Declaration
*******************************************************************************/

/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/
#define ECUM_START_SEC_CODE
#include "EcuM_MemMap.h"
/*SWS_EcuM_02811*/
extern FUNC(void, ECUM_CODE) EcuM_Init
(
    void
);

/*SWS_EcuM_02838*/
extern FUNC(void, ECUM_CODE) EcuM_StartupTwo
(
    void
);

/*SWS_EcuM_02812*/
extern FUNC(void, ECUM_CODE) EcuM_Shutdown
(
    void
);



#if (ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
/*SWS_EcuM_04048*/
extern FUNC(void, ECUM_CODE) EcuM_StartCheckWakeup
(
    EcuM_WakeupSourceType WakeupSource
);

#endif

/*SWS_EcuM_91002*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoDownHaltPoll
(
		EcuM_UserType UserID
);

/*SWS_EcuM_04122*/
extern FUNC(void, ECUM_CODE) EcuM_SetState
(
    EcuM_StateType state
);

/*SWS_EcuM_04124*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_RequestRUN
(
    EcuM_UserType user
);

/*SWS_EcuM_04127*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_ReleaseRUN
(
    EcuM_UserType user
);


/*SWS_EcuM_04128*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_RequestPOST_RUN
(
    EcuM_UserType user
);

/*SWS_EcuM_04129*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_ReleasePOST_RUN
(
    EcuM_UserType user
);

/*SWS_EcuM_02822*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownTarget
(
    EcuM_ShutdownTargetType shutdownTarget,
    EcuM_ShutdownModeType shutdownMode
);

/*SWS_EcuM_02824*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownTarget
(
    P2VAR(EcuM_ShutdownTargetType, AUTOMATIC, ECUM_APPL_DATA) shutdownTarget,
    P2VAR(EcuM_ShutdownModeType, AUTOMATIC, ECUM_APPL_DATA) shutdownMode
);

/*SWS_EcuM_02825*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetLastShutdownTarget
(
    P2VAR(EcuM_ShutdownTargetType, AUTOMATIC, ECUM_APPL_DATA) shutdownTarget,
    P2VAR(EcuM_ShutdownModeType, AUTOMATIC, ECUM_APPL_DATA) shutdownMode
);

/*SWS_EcuM_04050*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownCause
(
    EcuM_ShutdownCauseType target
);

/*SWS_EcuM_04051*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownCause
(
    P2VAR(EcuM_ShutdownCauseType, AUTOMATIC, ECUM_APPL_DATA) shutdownCause
);


/*SWS_EcuM_02835*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectBootTarget
(
    EcuM_BootTargetType target
);

/*SWS_EcuM_02836*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetBootTarget
(
    P2VAR(EcuM_BootTargetType, AUTOMATIC, ECUM_APPL_DATA) target
);

/*SWS_EcuM_02837*/
extern FUNC(void, ECUM_CODE) EcuM_MainFunction
(
    void
);

#if (ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
/*SWS_EcuM_02828*/
extern FUNC(void, ECUM_CODE) EcuM_ClearWakeupEvent
(
    EcuM_WakeupSourceType sources
);

/*SWS_EcuM_02830*/
extern FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetValidatedWakeupEvents
(
    void
);

#if (ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
/*SWS_EcuM_02831*/
extern FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetExpiredWakeupEvents
(
    void
);

/*SWS_EcuM_02827*/
extern FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetPendingWakeupEvents
(
    void
);

#endif /*ECUM_WAKEUPSOURCE_VALIDATION == STD_ON*/

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
/*SWS_EcuM_04054*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetRelWakeupAlarm
(
    EcuM_UserType user,
    EcuM_TimeType time
);


/*SWS_EcuM_04057*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetAbsWakeupAlarm
(
    EcuM_UserType user,
    EcuM_TimeType time
);

/*SWS_EcuM_04061*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_AbortWakeupAlarm
(
    EcuM_UserType user
);

/*SWS_EcuM_04062*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetCurrentTime
(
    P2VAR(EcuM_TimeType, AUTOMATIC, ECUM_APPL_DATA) time
);

/*SWS_EcuM_04063*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetWakeupTime
(
    P2VAR(EcuM_TimeType, AUTOMATIC, ECUM_APPL_DATA) time
);

#if (ECUM_SETCLOCK_USER_NUMBER > 0)
/*SWS_EcuM_04064*/
extern FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetClock
(
    EcuM_UserType user,
    EcuM_TimeType time
);
#endif
#endif /*ECUM_ALARM_CLOCK_PRESENT == STD_ON*/
#endif /*ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON*/

#if (ECUM_VERSION_INFO_API == STD_ON)
/*SWS_EcuM_02813*/
extern FUNC(void, ECUM_CODE) EcuM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, ECUM_APPL_DATA) versioninfo
);
#endif

#define ECUM_STOP_SEC_CODE
#include "EcuM_MemMap.h"

#endif /* ECUM_H */

