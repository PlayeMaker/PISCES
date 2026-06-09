/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_EcuM.h
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


#ifndef RTE_ECUM_H
#define RTE_ECUM_H

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
#include "EcuM.h"
#include "Rte_EcuM_Type.h"
#define Rte_Call_BootTarget_User0_GetBootTarget(target)     EcuM_GetBootTarget(target)
#define Rte_Call_BootTarget_User0_SelectBootTarget(target)  EcuM_SelectBootTarget(target)
#define Rte_Call_ShutdownTarget_User0_GetLastShutdownTarget(shutdownTarget, shutdownMode) EcuM_GetLastShutdownTarget(shutdownTarget, shutdownMode)
#define Rte_Call_ShutdownTarget_User0_GetShutdownTarget(shutdownTarget, shutdownMode)     EcuM_GetShutdownTarget(shutdownTarget, shutdownMode)
#define Rte_Call_ShutdownTarget_User0_SelectShutdownTarget(shutdownTarget, shutdownMode)  EcuM_SelectShutdownTarget(shutdownTarget, shutdownMode)
#define Rte_Call_ShutdownTarget_User0_GetShutdownCause(shutdownCause) EcuM_GetShutdownCause(shutdownCause)
#define Rte_Call_ShutdownTarget_User0_SelectShutdownCause(shutdownCause)        EcuM_SelectShutdownCause(shutdownCause)
#define Rte_Call_StateRequest_User0_ReleasePOSTRUN()        EcuM_ReleasePOST_RUN(ECUM_USER0)
#define Rte_Call_StateRequest_User0_ReleaseRUN()            EcuM_ReleaseRUN(ECUM_USER0)
#define Rte_Call_StateRequest_User0_RequestPOSTRUN()        EcuM_RequestPOST_RUN(ECUM_USER0)
#define Rte_Call_StateRequest_User0_RequestRUN()            EcuM_RequestRUN(ECUM_USER0)
#define Rte_Call_time_GetCurrentTime(time)                  EcuM_GetCurrentTime(time)
#define Rte_Call_time_GetWakeupTime(time)                   EcuM_GetWakeupTime(time)
#define Rte_Switch_currentMode_currentMode                  Rte_Switch_EcuM_currentMode_currentMode

/*******************************************************************************
*   MS Extended
*******************************************************************************/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_EcuM_currentMode_currentMode
(
    CONST(Rte_ModeType_EcuM_Mode, AUTOMATIC) nextMode
);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif  /*RTE_ECUM_H*/


