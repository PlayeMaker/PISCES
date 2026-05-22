/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name:       Com_Cbk.h
********************************************************************************
*   Project/Product: AUTOSAR R21-11
*   Title:           Com_Cbk.h
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

#ifndef COM_CBK_H
#define COM_CBK_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Com_Types.h"

/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

extern FUNC(Std_ReturnType, COM_CODE)Com_TriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);
extern FUNC(void, COM_CODE) Com_RxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);

extern FUNC(void, COM_CODE) Com_TxConfirmation
(
    PduIdType TxPduId,
    Std_ReturnType Result
);

extern FUNC(void, COM_CODE) Com_TpTxConfirmation
(
    PduIdType TxPduId,
    Std_ReturnType Result
);

extern FUNC(BufReq_ReturnType, COM_CODE) Com_CopyTxData
(
    PduIdType PduId,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr,
    P2CONST(RetryInfoType, AUTOMATIC, COM_APPL_DATA) RetryInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) TxDataCntPtr
);

extern FUNC(void, COM_CODE) Com_TpRxIndication
(
    PduIdType PduId,
    Std_ReturnType Result
);

extern FUNC(BufReq_ReturnType, COM_CODE) Com_StartOfReception
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPointer,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) RxBufferSizePtr
);


extern FUNC(BufReq_ReturnType, COM_CODE) Com_CopyRxData
(
    PduIdType PduId,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPointer,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) RxBufferSizePtr
);

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#endif
