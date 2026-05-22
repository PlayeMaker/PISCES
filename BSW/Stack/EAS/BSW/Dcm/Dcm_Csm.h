/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dcm_Csm.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : Dcm_Csm.h
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

#ifndef DCM_CSM_H
#define DCM_CSM_H

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

#if(DCM_UDS_29_ENABLED == STD_ON)
/*SWS_Dcm_91076*/
extern FUNC(void, DCM_CODE) Dcm_CsmAsyncJobFinished
(
	uint32 JobId,/*To meet the call format of Csm*/
    Crypto_ResultType result
);
#endif

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif/*DCM_CSM_H*/


