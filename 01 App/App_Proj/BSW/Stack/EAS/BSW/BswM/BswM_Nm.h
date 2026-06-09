/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM_Nm.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : BSWM module Nm ralated header File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file BswM_Nm.h contains the declaration of
*                     functions which is called by the Nm module
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

#ifndef BSWM_NM_H
#define BSWM_NM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "BswM_Cfg.h"
#include "BswM_Version.h"

#if(STD_ON == BSWM_NM_ENABLED)
#include "NmStack_Types.h"
/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"

extern FUNC(void, BSWM_CODE) BswM_Nm_CarWakeUpIndication
(
    NetworkHandleType Network
);
extern FUNC(void, BSWM_CODE) BswM_Nm_StateChangeNotification                          
(
    NetworkHandleType Network,
    Nm_StateType currentState
);

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
#endif

#endif/* BSWM_NM_H */

