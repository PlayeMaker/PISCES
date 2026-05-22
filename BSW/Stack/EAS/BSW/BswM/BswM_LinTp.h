/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM_LinTp.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : BswM_LinTp.h
*   Author          : Hirain
********************************************************************************
*   Description     : The header file BswM_LinTp.h contains the declaration of
*                     functions which is called by the LinTp module
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

#ifndef BSWM_LINTP_H
#define BSWM_LINTP_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "BswM_Cfg.h"
#include "BswM_Version.h"

#if(STD_ON == BSWM_LINTP_ENABLED)
#include "LinTp_Types.h"
/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"

extern FUNC(void, BSWM_CODE) BswM_LinTp_RequestMode
(
    NetworkHandleType Network,
    LinTp_Mode LinTpRequestMode
);

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"
#endif

#endif/* BSWM_LINTP_H */


