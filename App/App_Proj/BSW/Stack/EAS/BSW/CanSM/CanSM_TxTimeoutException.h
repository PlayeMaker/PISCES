/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanSM_TxTimeoutException.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2
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
********************************************************************************
* END_FILE_HDR*/

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 776 EOF*/
/*
Names in core files may not follow relevant rules.
*/

#ifndef CANSM_TXTIMEOUTEXCEPTION_H
#define CANSM_TXTIMEOUTEXCEPTION_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanSM_Types.h"

/*******************************************************************************
*   API Declare SWS_CanSM_00549
*******************************************************************************/
#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.h"

#if(STD_ON == CANSM_PNC_SUPPORT)
extern FUNC(void, CANSM_CODE) CanSM_TxTimeoutException
(
    NetworkHandleType Channel
);
#endif

#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.h"


#endif /*#ifndef CANSM_TXTIMEOUTEXCEPTION_H*/

