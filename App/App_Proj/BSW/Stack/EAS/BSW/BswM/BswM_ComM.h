/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM_ComM.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : BSWM module ComM ralated header File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file BswM_ComM.h contains the declaration of
*                     functions which is called by the ComM module
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

#ifndef BSWM_COMM_H
#define BSWM_COMM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "BswM_Cfg.h"
#include "BswM_Version.h"

#if(STD_ON == BSWM_COMM_ENABLED)
#include "ComM_Types.h"
/*******************************************************************************
*   API Declaration
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"

extern FUNC(void, BSWM_CODE) BswM_ComM_CurrentMode
(
    NetworkHandleType Network,
    ComM_ModeType RequestedMode
);
extern FUNC(void, BSWM_CODE) BswM_ComM_CurrentPNCMode
(
    PNCHandleType PNC,
    ComM_PncModeType CurrentPncMode
);
extern FUNC(void, BSWM_CODE) BswM_ComM_InitiateReset
(
    void
);

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
#endif

#endif/* BSWM_COMM_H */

