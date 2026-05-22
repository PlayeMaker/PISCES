/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : ComM_DCM.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : ComM module Dcm ralated header File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file ComM_DCM.h contains the declaration of
*                     functions which is called by the DCM module
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

#ifndef COMM_DCM_H
#define COMM_DCM_H

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

#if(STD_ON == COMM_DCM_SUPPORT)
/*SWS_ComM_00873*/
extern FUNC(void, COMM_CODE) ComM_DCM_ActiveDiagnostic
(
    NetworkHandleType Channel
);

/*SWS_ComM_00874*/
extern FUNC(void, COMM_CODE) ComM_DCM_InactiveDiagnostic
(
    NetworkHandleType Channel
);
#endif

#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"


#endif/*COMM_DCM_H*/

