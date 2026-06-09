/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_ComM.h
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


#ifndef RTE_COMM_H
#define RTE_COMM_H

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
#include "ComM.h"
#include "Rte_ComM_Type.h"
#define Rte_Call_UR_User0_GetCurrentComMode(ComMode)        ComM_GetCurrentComMode(ComM_USERID_User0, ComMode)
#define Rte_Call_UR_User0_GetCurrentPNCComMode(ComMode)     ComM_GetCurrentPNCComMode(ComM_USERID_User0, ComMode)
#define Rte_Call_UR_User0_GetMaxComMode(ComMode)            ComM_GetMaxComMode(ComM_USERID_User0, ComMode)
#define Rte_Call_UR_User0_GetRequestedComMode(ComMode)      ComM_GetRequestedComMode(ComM_USERID_User0, ComMode)
#define Rte_Call_UR_User0_RequestComMode(ComMode)           ComM_RequestComMode(ComM_USERID_User0, ComMode)
#define Rte_Switch_UM_User0_ComMMode                        Rte_Switch_ComM_UM_User0_ComMMode

/*******************************************************************************
*   MS Extended
*******************************************************************************/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_ComM_UM_User0_ComMMode
(
    CONST(Rte_ModeType_ComMMode, AUTOMATIC) nextMode
);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif  /*RTE_COMM_H*/


