/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM_CanSM.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : BSWM module CanSM ralated header File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file BswM_CanSM.h contains the declaration of
*                     functions which is called by the CanSM module
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

#ifndef BSWM_CANSM_H
#define BSWM_CANSM_H

/*******************************************************************************
*   Includes
*******************************************************************************/

#include "BswM_Cfg.h"
#include "BswM_Version.h"

#if(STD_ON == BSWM_CANSM_ENABLED)
#include "CanSM_Types.h"
/*******************************************************************************
*   API Declaration
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"

extern FUNC(void, BSWM_CODE) BswM_CanSM_CurrentState
(
    NetworkHandleType Network,
    CanSM_BswMCurrentStateType CurrentState
);

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
#endif

#endif/* BSWM_CANSM_H */

