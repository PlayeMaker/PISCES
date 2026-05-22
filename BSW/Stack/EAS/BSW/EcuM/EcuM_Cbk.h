/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EcuM_Cbk.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : The ECU state manager
*   Author          : mingqing.tang
********************************************************************************
*   Description     : The header file EcuM.h contains the callbacks and callouts
*                     declaration of the EcuM module.
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
#ifndef ECUM_CBK_H
#define ECUM_CBK_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EcuM_Types.h"
#include "EcuM_Cfg.h"
#include "EcuM_Version.h"

/*******************************************************************************
*   SOURCE FILE VERSION INFORMATION
*******************************************************************************/
#define ECUM_CBK_VENDOR_ID                      STD_HIRAIN_VENDOR_ID
#define ECUM_CBK_MODULE_ID                      ((uint16)10)

#define ECUM_CBK_AR_RELEASE_MAJOR_VERSION       (4)
#define ECUM_CBK_AR_RELEASE_MINOR_VERSION       (2)
#define ECUM_CBK_AR_RELEASE_REVISION_VERSION    (2)
#define ECUM_CBK_SW_MAJOR_VERSION               (1)
#define ECUM_CBK_SW_MINOR_VERSION               (1)
#define ECUM_CBK_SW_PATCH_VERSION               (0)
/*******************************************************************************
*   Macro
*******************************************************************************/

/*******************************************************************************
*   Global Data Declaration
*******************************************************************************/

/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/
/*******************************************************************************
*   The Callback Function Declaration
*******************************************************************************/
#define ECUM_START_SEC_CODE
#include "EcuM_MemMap.h"
#if (ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
#if (ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
/*SWS_EcuM_02826*/
extern FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent
(
    EcuM_WakeupSourceType sources
);
#else
#define EcuM_SetWakeupEvent(src)    EcuM_ValidateWakeupEvent(src)
#endif /*ECUM_WAKEUPSOURCE_VALIDATION == STD_ON*/

/*SWS_EcuM_02829*/
extern FUNC(void, ECUM_CODE) EcuM_ValidateWakeupEvent
(
    EcuM_WakeupSourceType sources
);

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
extern FUNC(void, ECUM_CODE) EcuM_CheckClock
(
    void
);
#endif /*ECUM_ALARM_CLOCK_PRESENT == STD_ON*/
#endif /*ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON*/

/*******************************************************************************
*   The Callout Function Declaration
*******************************************************************************/
/*SWS_EcuM_02904*/
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_ErrorHook
(
    Std_ReturnType reason
);

/*SWS_EcuM_04085*/
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_SetProgrammableInterrupts
(
    void
);

/*SWS_EcuM_02095*/
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_DriverInitZero
(
    void
);

/*SWS_EcuM_02096*/
extern FUNC(const EcuM_ConfigType *, ECUM_CALLOUT_CODE) EcuM_DeterminePbConfiguration
(
    void
);

/*SWS_EcuM_02097*/
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_DriverInitOne
(
    void
);

/*SWS_EcuM_02916*/
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_OnGoOffOne
(
    void
);

/*SWS_EcuM_02917*/
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_OnGoOffTwo
(
    void
);

/*SWS_EcuM_02920*/
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_SwitchOff
(
    void
);

/*SWS_EcuM_04065*/
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_Reset
(
    EcuM_ResetType reset
);

#if(ECUM_CORE_NUMBER > 1)
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_NotifyInit
(
    CoreIdType CoreId
);
#if (ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
extern FUNC (void, ECUM_CODE) EcuM_NotifySet
(
    uint8 CoreId
);
#endif
#endif



extern FUNC(void,ECUM_CALLOUT_CODE) EcuM_CheckWakeupHook  
(
    EcuM_WakeupSourceType wakeupSource
);

#if (ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON)
/*SWS_EcuM_02918*/
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_EnableWakeupSources
(
    EcuM_WakeupSourceType wakeupSource
);

/*SWS_EcuM_02919*/
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_GenerateRamHash
(
    void
);

#if (ECUM_SLEEP_POLLING_MODE == STD_ON)
/*SWS_EcuM_02928*/
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_SleepActivity
(
    void
);

#endif /*ECUM_SLEEP_POLLING_MODE == STD_ON*/

/*SWS_EcuM_02929*/
extern FUNC(void, ECUM_CODE) EcuM_CheckWakeup
(
    EcuM_WakeupSourceType wakeupSource
);

/*SWS_EcuM_02921*/
extern FUNC(uint8, ECUM_CALLOUT_CODE) EcuM_CheckRamHash
(
    void
);

/*SWS_EcuM_02922*/
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_DisableWakeupSources
(
    EcuM_WakeupSourceType wakeupSource
);

/*SWS_EcuM_02923*/
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_DriverRestart
(
    void
);

#if (ECUM_WAKEUPSOURCE_VALIDATION == STD_ON)
/*SWS_EcuM_02924*/
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_StartWakeupSources
(
    EcuM_WakeupSourceType wakeupSource
);

/*SWS_EcuM_02925*/
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_CheckValidation
(
    EcuM_WakeupSourceType wakeupSource
);

/*SWS_EcuM_02926*/
extern FUNC(void, ECUM_CALLOUT_CODE) EcuM_StopWakeupSources
(
    EcuM_WakeupSourceType wakeupSource
);
#endif /*ECUM_WAKEUPSOURCE_VALIDATION == STD_ON*/

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
FUNC(void, ECUM_CALLOUT_CODE) EcuM_StartClock
(
    void
);

FUNC(void, ECUM_CALLOUT_CODE) EcuM_SetClockSleep
(
    void
);

FUNC(void, ECUM_CALLOUT_CODE) EcuM_SetClockNormal
(
    void
);

#endif /*ECUM_ALARM_CLOCK_PRESENT == STD_ON*/

#endif /*ECUM_SHUTDOWN_TARGET_SLEEP_SUPPORT == STD_ON*/

#define ECUM_STOP_SEC_CODE
#include "EcuM_MemMap.h"

#endif /* ECUM_CBK_H */

