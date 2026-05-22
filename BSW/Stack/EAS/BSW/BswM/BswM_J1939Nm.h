/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM_J1939Nm.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : BSWM module J1939Nm ralated header File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file BswM_J1939Nm.h contains the declaration of
*                     functions which is called by the J1939Nm module
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

#ifndef BSWM_J1939NM_H
#define BSWM_J1939NM_H

/*******************************************************************************
*   Includes
*******************************************************************************/

#include "BswM_Cfg.h"
#include "BswM_Version.h"

#if(STD_ON == BSWM_J1939NM_ENABLED)
#include "J1939Nm_Types.h"
/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"

extern FUNC(void, BSWM_CODE) BswM_J1939Nm_StateChangeNotification
(
    NetworkHandleType Network,
    uint8 Node,
    Nm_StateType NmState
);

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
#endif

#endif/* BSWM_J1939NM_H */

