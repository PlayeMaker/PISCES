/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanIf_Cbk.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : CAN Interface module call back head File
*   Author          : HeYang
********************************************************************************
*   Description     : The header file CanIf_Cbk.h contains the declaration of
*                     callback functions which is called by the Can module
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

/*PRQA S 776 EOF*/
/*
Names  in Core files may not follow relevant rules.
*/

#ifndef CANIF_CBK_H
#define CANIF_CBK_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanIf_Types.h"


#define CANIF_CBK_AR_RELEASE_MAJOR_VERSION (4)
#define CANIF_CBK_AR_RELEASE_MINOR_VERSION (7)


/*******************************************************************************
*   Callback Function Declaration
*******************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(void, CANIF_CODE) CanIf_TxConfirmation
(
    PduIdType CanTxPduId
);

extern FUNC(void, CANIF_CODE) CanIf_RxIndication
(
    P2CONST(Can_HwType, AUTOMATIC, CANIF_APPL_DATA) Mailbox,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
);


extern FUNC(void, CANIF_CODE) CanIf_ControllerBusOff
(
    uint8 ControllerId
);

#if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)
#if(CANIF_MAX_TRCV_NUM > 0)
extern FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability
(
    uint8 TransceiverId
);

extern FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication
(
    uint8 TransceiverId
);

extern FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication
(
    uint8 TransceiverId
);
#endif
#endif

extern FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
);

#if(CANIF_MAX_TRCV_NUM > 0)
extern FUNC(void, CANIF_CODE) CanIf_TrcvModeIndication
(
    uint8 TransceiverId,
    CanTrcv_TrcvModeType TransceiverMode
);
#endif


#if(STD_ON ==  CANIF_PUBLIC_ICOM_SUPPORT) /*SWS_CANIF_00876*/
extern FUNC(void, CANIF_CODE) CanIf_CurrentIcomConfiguration
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId,
    IcomSwitch_ErrorType Error
);
#endif

#if(STD_ON ==  CANIF_TRIGGER_TRANSMIT_SUPPORT) /*SWS_CANIF_00884*/
#if(CANIF_MAX_TXTRIGGER_NUM > 0)
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_TriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
);
#endif
#endif

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#endif/*CANIF_CBK_H*/

