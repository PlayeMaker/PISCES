/* BEGIN_FILE_HDR
********************************************************************************
* NOTICE
* This software is the property of HiRain Technologies. Any information
* contained in this doc should not be reproduced, or used, or disclosed
* without the written authorization from HiRain Technologies.
********************************************************************************
* File Name:       CanIf_TxSwFifo.h
********************************************************************************
* Project/Product: AUTOSAR  PROJECT
* Title:           CanIf_TxSwFifo.h
* Author:          Hirain
********************************************************************************
* Description:     
*
********************************************************************************
* Limitations     : None
*
********************************************************************************
*
********************************************************************************
* Revision History:
*
********************************************************************************
* END_FILE_HDR*/

#ifndef CANIF_TXSWFIFO_H
#define CANIF_TXSWFIFO_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanIf_Types.h"

#if(STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT)


/*****************************************************************************
*   Functions Declare
******************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"
extern FUNC(void, CANIF_CODE) CanIf_TxSwFifo_ResetFifo
(
    Can_HwHandleType Hth
);

extern FUNC(Can_ReturnType, CANIF_CODE) CanIf_TxSwFifo_Write
(
    Can_HwHandleType Hth,
    P2CONST(Can_PduType, AUTOMATIC, CAN_APPL_DATA) PduInfo
);

extern FUNC(void, CANIF_CODE) CanIf_TxSwFifo_TxConfirmation
(
    PduIdType CanTxPduId
);
#if(CANIF_PRIVATE_SWTXFIFO_RETRY == STD_ON)
extern FUNC(void, CANIF_CODE) CanIf_TxSwFifo_MainFunction(void);
#endif

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#endif/*#if(STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT)*/

#endif/* #ifndef CANIF_TXSWFIFO_H */
