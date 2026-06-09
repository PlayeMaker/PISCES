/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dcm_Callout.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Dcm module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Dcm module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/

/*PRQA S 776 EOF*/
/*
Names in this file may not follow relevant rules.
*/

#ifndef DCM_CALLOUT_H
#define DCM_CALLOUT_H

/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dcm_Types.h"
#include "Rte_Dcm.h"
/*Dcm_Callout.h User Code start*/

/*Dcm_Callout.h User Code end*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

/*SWS_Dcm_00543*/
extern FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_SetProgConditions
(
    Dcm_OpStatusType OpStatus, 
    P2CONST(Dcm_ProgConditionsType, AUTOMATIC, DCM_APPL_DATA) ProgConditions
);

/*SWS_Dcm_00544*/
extern FUNC(Dcm_EcuStartModeType, DCM_CALLOUT_CODE) Dcm_GetProgConditions
(
    P2VAR(Dcm_ProgConditionsType, AUTOMATIC, DCM_APPL_DATA) ProgConditions
);

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif/*DCM_CALLOUT_H*/

