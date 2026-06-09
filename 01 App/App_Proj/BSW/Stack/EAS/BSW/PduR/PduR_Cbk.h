/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name:       PduR_Cbk.h
********************************************************************************
*   Project/Product: AUTOSAR R21-11
*   Title:           PduR_Cbk.h
*   Author:          Hirain
********************************************************************************
*   Description:     Defination of Interface for Application Layer
*
********************************************************************************
*   Limitations:      None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
*END_FILE_HDR*/

#ifndef PDUR_CBK_H
#define PDUR_CBK_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "PduR_PBcfg.h"

/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

extern FUNC(void, PDUR_CODE) PduR_LoIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);

extern FUNC(void, PDUR_CODE) PduR_LoIfTxConfirmation
(
    PduIdType TxPduId,
    Std_ReturnType result
);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_LoIfTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

extern FUNC(void, PDUR_CODE) PduR_LoTpRxIndication
(
    PduIdType id,
    Std_ReturnType result
);

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);

extern FUNC(void, PDUR_CODE) PduR_LoTpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
);

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

#endif
