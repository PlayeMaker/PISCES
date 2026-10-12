/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : ComM_EcuM.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : ComM_EcuM.h
*   Author          : Hirain
********************************************************************************
*   Description     : The header file ComM_EcuM.h contains the declaration of
*                     functions which is called by the EcuM module
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

#ifndef COMM_ECUM_H
#define COMM_ECUM_H


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

/*SWS_ComM_00275*/
extern FUNC(void, COMM_CODE) ComM_EcuM_WakeUpIndication
(
    NetworkHandleType Channel
);

/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
/*SWS_ComM_91001*/
extern FUNC(void, COMM_CODE) ComM_EcuM_PNCWakeUpIndication
(
    PNCHandleType PNCid
);
#endif

#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"

#endif/*COMM_ECUM_H*/


