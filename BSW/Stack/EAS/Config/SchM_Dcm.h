/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : SchM_Dcm.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : SchM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : SchM module configuration File
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
/*PRQA S 776,777,778,779,789,791,792,793 EOF*/
/*
Names in this file may not follow relevant rules.
*/
/*PRQA S 3429 EOF*/
/*
A function-like macro is being defined. But this form is prescribed by autosar.
*/


#ifndef SCHM_DCM_H
#define SCHM_DCM_H
/*******************************************************************************
*   Include
*******************************************************************************/
#include "SchM_Dcm_Type.h"

/*******************************************************************************
*   exclusive Area
*******************************************************************************/
#define SchM_Enter_Dcm_DCM_EXCLUSIVE_AREA_0()
#define SchM_Exit_Dcm_DCM_EXCLUSIVE_AREA_0()


#define SchM_Enter_Dcm_DCM_EXCLUSIVE_AREA_1()
#define SchM_Exit_Dcm_DCM_EXCLUSIVE_AREA_1()


#define SchM_Enter_Dcm_DCM_EXCLUSIVE_AREA_2()
#define SchM_Exit_Dcm_DCM_EXCLUSIVE_AREA_2()


#define SchM_Switch_DcmCommunicationControl_ComM_BODY_LE1_CAN         SchM_Switch_Dcm_DcmCommunicationControl_ComM_BODY_LE1_CAN
#define SchM_Switch_DcmControlDtcSetting                    SchM_Switch_Dcm_DcmControlDtcSetting
#define SchM_Switch_DcmDiagnosticSessionControl             SchM_Switch_Dcm_DcmDiagnosticSessionControl
#define SchM_Switch_DcmEcuReset                             SchM_Switch_Dcm_DcmEcuReset
#define SchM_Switch_DcmSecurityAccess                       SchM_Switch_Dcm_DcmSecurityAccess
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmCommunicationControl_ComM_BODY_LE1_CAN
(
    CONST(Rte_ModeType_DcmCommunicationControl_ComM_BODY_LE1_CAN, AUTOMATIC) nextMode
);
extern FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmControlDtcSetting
(
    CONST(Rte_ModeType_DcmControlDtcSetting, AUTOMATIC) nextMode
);
extern FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmDiagnosticSessionControl
(
    CONST(Rte_ModeType_DcmDiagnosticSessionControl, AUTOMATIC) nextMode
);
extern FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmEcuReset
(
    CONST(Rte_ModeType_DcmEcuReset, AUTOMATIC) nextMode
);
extern FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmSecurityAccess
(
    CONST(Rte_ModeType_DcmSecurityAccess, AUTOMATIC) nextMode
);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#endif



