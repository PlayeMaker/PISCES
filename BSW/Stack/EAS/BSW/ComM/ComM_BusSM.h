/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : ComM_BusSM.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : ComM_BusSM.h
*   Author          : Hirain
********************************************************************************
*   Description     : The header file ComM_BusSM.h contains the declaration of
*                     functions which is called by the CanSM, LinSM .etc module
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

#ifndef COMM_BUSSM_H
#define COMM_BUSSM_H

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

/*SWS_ComM_00675*/
extern FUNC(void, COMM_CODE) ComM_BusSM_ModeIndication
(
    NetworkHandleType Channel,
    ComM_ModeType ComMode
);

#if((STD_ON == COMM_NMVARIANT_SLAVE_A_ENABLED) || (STD_ON == COMM_NMVARIANT_SLAVE_P_ENABLED))
/*SWS_ComM_91000*/
extern FUNC(void, COMM_CODE) ComM_BusSM_BusSleepMode
(
    NetworkHandleType Channel
);
#endif

#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"


#endif/* COMM_BUSSM_H */

