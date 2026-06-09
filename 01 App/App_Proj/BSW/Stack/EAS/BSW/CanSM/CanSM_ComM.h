/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanSM_ComM.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : CanSM module Header File
*   Author          : Hirain
********************************************************************************
*   Description     : CanSM module Header File
*
********************************************************************************
*   Limitations     : None
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
/*PRQA S 776 EOF*/
/*
Names in core files may not follow relevant rules.
*/

#ifndef CANSM_COMM_H
#define CANSM_COMM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanSM_Types.h"

/*******************************************************************************
*   API Declare
*******************************************************************************/
#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.h"
/*SWS_CanSM_00009*/
extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_RequestComMode
(
    NetworkHandleType network,
    ComM_ModeType ComM_Mode
);
extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetCurrentComMode
(
    NetworkHandleType network,
    P2VAR(ComM_ModeType, AUTOMATIC, CANSM_APPL_DATA) ComM_ModePtr
);
#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.h"


#endif /*#ifndef CANSM_COMM_H*/

