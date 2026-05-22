/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dcm_Cbk.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : Dcm_Cbk.h
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

#ifndef DCM_CBK_H
#define DCM_CBK_H

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

/*SWS_Dcm_00094*/
extern FUNC(BufReq_ReturnType, DCM_CODE) Dcm_StartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) bufferSizePtr
);

/*SWS_Dcm_00556*/
extern FUNC(BufReq_ReturnType, DCM_CODE) Dcm_CopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) bufferSizePtr
);

/*SWS_Dcm_00093*/
extern FUNC(void, DCM_CODE) Dcm_TpRxIndication
(
    PduIdType id,
    Std_ReturnType result
);

/*SWS_Dcm_00092*/
extern FUNC(BufReq_ReturnType, DCM_CODE) Dcm_CopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,
    P2CONST(RetryInfoType, AUTOMATIC, DCM_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) availableDataPtr
);

/*SWS_Dcm_00351*/
extern FUNC(void, DCM_CODE) Dcm_TpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
);

/*SWS_Dcm_01092*/
extern FUNC(void, DCM_CODE) Dcm_TxConfirmation
(
    PduIdType TxPduId,
    Std_ReturnType result
);

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif/*DCM_CBK_H*/


