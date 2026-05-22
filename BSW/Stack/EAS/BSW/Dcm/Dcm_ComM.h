/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dcm_ComM.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : Dcm_ComM.h
*   Author          : Hirain
********************************************************************************
*   Description: Callback header file of the AUTOSAR Dcm Module.
*
********************************************************************************
*   Limitations: None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR */

/*PRQA S 776 EOF*/
/*
Names in this file may not follow relevant rules.
*/

#ifndef DCM_COMM_H
#define DCM_COMM_H

/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dcm_Types.h"
#include "Dcm_Version.h"

/*******************************************************************************
* Global Function Prototype
*******************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

#if(DCM_COMM_SUPPORT == STD_ON)
/*SWS_Dcm_00356*/
extern FUNC(void, DCM_CODE) Dcm_ComM_NoComModeEntered
(
    NetworkHandleType NetworkId
);

/*SWS_Dcm_00358*/
extern FUNC(void, DCM_CODE) Dcm_ComM_SilentComModeEntered
(
    NetworkHandleType NetworkId
);

/*SWS_Dcm_00360*/
extern FUNC(void, DCM_CODE) Dcm_ComM_FullComModeEntered
(
    NetworkHandleType NetworkId
);
#endif/*(DCM_COMM_SUPPORT == STD_ON)*/

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"


#endif/*DCM_COMM_H*/


