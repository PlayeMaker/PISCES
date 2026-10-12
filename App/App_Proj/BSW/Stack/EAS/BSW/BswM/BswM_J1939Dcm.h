/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM_J1939Dcm.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : BSWM module J1939Dcm ralated header File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file BswM_J1939Dcm.h contains the declaration of
*                     functions which is called by the J1939Dcm module
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

#ifndef BSWM_J1939DCM_H
#define BSWM_J1939DCM_H

/*******************************************************************************
*   Includes
*******************************************************************************/

#include "BswM_Cfg.h"
#include "BswM_Version.h"

#if(STD_ON == BSWM_J1939DCM_ENABLED)
#include "J1939DCM_Types.h"
/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"

extern FUNC(void, BSWM_CODE) BswM_J1939DcmBroadcastStatus
(
    uint16 NetworkMask
);

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
#endif


#endif/* BSWM_J1939DCM_H */

