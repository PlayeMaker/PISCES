/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : ComM_BswM.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : ComM_BswM.h
*   Author          : Hirain
********************************************************************************
*   Description     : The header file ComM_BswM.h contains the declaration of
*                     functions which is called by the BswM module
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

#ifndef COMM_BSWM_H
#define COMM_BSWM_H


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComM_Cfg.h"
#include "ComM_Version.h"

/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define COMM_START_SEC_CODE
#include "ComM_MemMap.h"

/*SWS_ComM_00871*/
extern FUNC(void, COMM_CODE) ComM_CommunicationAllowed
(
    NetworkHandleType Channel,
    boolean Allowed
);

#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"

#endif/*COMM_BSWM_H*/


