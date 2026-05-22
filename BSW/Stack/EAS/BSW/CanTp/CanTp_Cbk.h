/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanTp_Cbk.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : CanTp Callback module Source File
*   Author          : Hirain
********************************************************************************
*   Description     : Callback header file of the AUTOSAR CAN Transport Protocol.
*                     The header file contains the declaration of the API used
*                     by CANIF module.
********************************************************************************
*   Limitations     :
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/
#ifndef CANTP_CBK_H
#define CANTP_CBK_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanTp_PBcfg.h"
#include "CanTp_Version.h"

/*******************************************************************************
* Prototypes of export functions
*******************************************************************************/
#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"

extern FUNC(void, CANTP_CODE) CanTp_RxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr
);

extern FUNC(void, CANTP_CODE) CanTp_TxConfirmation
(
    PduIdType TxPduId,
    Std_ReturnType result
);
#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"


#endif/* CANTP_CBK_H */

