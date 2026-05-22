/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanIf.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : CAN Interface module head File
*   Author          : HeYang
********************************************************************************
*   Description     : CAN Interface module head File
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

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 776 EOF*/
/*
Names  in Core files may not follow relevant rules.
*/

#ifndef CANIF_H
#define CANIF_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanIf_Lcfg.h"
#if(CANIF_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
#include "CanIf_PBcfg.h"
#endif
#include "SchM_CanIf.h"
#if(STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT)
#include "CanIf_TxSwFifo.h"
#endif
/*******************************************************************************
*   Macro
*******************************************************************************/
/* Development Error */
#if(STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
/* DET ERROR  CANIF154 */
#define CANIF_E_PARAM_CANID                       ((uint8)10)
#define CANIF_E_PARAM_HOH                         ((uint8)12)
#define CANIF_E_PARAM_LPDU                        ((uint8)13)
#define CANIF_E_PARAM_CONTROLLER                  ((uint8)14)
#define CANIF_E_PARAM_CONTROLLERID                ((uint8)15)
#define CANIF_E_PARAM_WAKEUPSOURCE                ((uint8)16)
#define CANIF_E_PARAM_TRCV                        ((uint8)17)
#define CANIF_E_PARAM_TRCVMODE                    ((uint8)18)
#define CANIF_E_PARAM_TRCVWAKEUPMODE              ((uint8)19)
#define CANIF_E_PARAM_CTRLMODE                    ((uint8)21)
#define CANIF_E_PARAM_PDU_MODE                    ((uint8)22)
#define CANIF_E_PARAM_POINTER                     ((uint8)20)
#define CANIF_E_UNINIT                            ((uint8)30)
#define CANIF_E_INVALID_TXPDUID                   ((uint8)50)
#define CANIF_E_INVALID_RXPDUID                   ((uint8)60)
#define CANIF_E_INVALID_DLC                       ((uint8)61)
#define CANIF_E_DATA_LENGTH_MISMATCH              ((uint8)62)
#define CANIF_E_STOPPED                           ((uint8)70)
#define CANIF_E_NOT_SLEEP                         ((uint8)71)
#define CANIF_E_INIT_FAILED                       ((uint8)80)
#define CANIF_E_TXPDU_LENGTH_EXCEEDED             ((uint8)90)

/* Non Autosar Standard */
#define CANIF_E_LINKAPINULL                       ((uint8)100)

/* API ID*/
#define CANIF_INIT_APIID                          ((uint8)0x01)
#define CANIF_SETCONTROLLERMODE_APIID             ((uint8)0x03)
#define CANIF_GETCONTROLLERMODE_APIID             ((uint8)0x04)

/*SWS_CANIF_00005*/
#define CANIF_TRANSMIT_APIID                      ((uint8)0x49)
#define CANIF_READRXPDUDATA_APIID                 ((uint8)0x06)
#define CANIF_READTXNOTIFSTATUS_APIID             ((uint8)0x07)
#define CANIF_READRXNOTIFSTATUS_APIID             ((uint8)0x08)
#define CANIF_SETPDUMODE_APIID                    ((uint8)0x09)
#define CANIF_GETPDUMODE_APIID                    ((uint8)0x0a)
#define CANIF_GETVERSIONINFO                      ((uint8)0x0b)
#define CANIF_SETDYNAMICTXID_APIID                ((uint8)0x0c)
#define CANIF_SETTRCVMODE_APIID                   ((uint8)0x0d)
#define CANIF_GETTRCVMODE_APIID                   ((uint8)0x0e)
#define CANIF_GETTRCVWUR_APIID                    ((uint8)0x0f)
#define CANIF_SETTRCVWUMODE_APIID                 ((uint8)0x10)
#define CANIF_CHECKWAKEUP_APIID                   ((uint8)0x11)
#define CANIF_CHECKVALIDATION_APIID               ((uint8)0x12)
#define CANIF_TXCONFIRMATION_APIID                ((uint8)0x13)
#define CANIF_RXINDICATION_APIID                  ((uint8)0x14)
#define CANIF_CANCELTXCONFIRMATION_APIID          ((uint8)0x15)
#define CANIF_CONTROLLERBUSOFF_APIID              ((uint8)0x16)
#define CANIF_CONTROLLERMODEINDICATION_APIID      ((uint8)0x17)
#define CANIF_CANCELTRANSMIT_APIID                ((uint8)0x18)
#define CANIF_GETTXCONFSTATE_APIID                ((uint8)0x19)
#define CANIF_CLEARTRCVWAKEUPFLAG_APIID           ((uint8)0x1e)
#define CANIF_CHECKTRCVWAKEUPFLAG_APIID           ((uint8)0x1f)
#define CANIF_CLEARTRCVWUFFIND_APIID              ((uint8)0x20)
#define CANIF_CHECKTRCVWUFFIND_APIID              ((uint8)0x21)
#define CANIF_CONFPNACTIVE_APIID                  ((uint8)0x1a)
#define CANIF_TRCVMODEIND_APIID                   ((uint8)0x22)
#define CANIF_SETBAUDRATE_APIID                   ((uint8)0x27)

#define CANIF_SETICOM_APIID                       ((uint8)0x25)
#define CANIF_TRIGGER_TRANSMIT_APIID              ((uint8)0x41)
#define CANIF_CURRENTICOM_APIID                   ((uint8)0x26)
#define CANIF_TXFIFOMAIN_APIID                    ((uint8)0x80)

#define CANIF_DEINIT_APIID                        ((uint8)0x02)
#define CANIF_ENABLEBUSMIRRORING_APIID            ((uint8)0X4c)
#define CANIF_GETCONTROLLERERRORSTATE_APIID       ((uint8)0x4b)
#define CANIF_GETCONTROLLERRXERRORCOUNTER_APIID   ((uint8)0x4d)
#define CANIF_GETCONTROLLERTXERRORCOUNTER_APIID   ((uint8)0x4e)

#endif

/*******************************************************************************
*   Global Vars Declaration
*******************************************************************************/
#define CANIF_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "CanIf_MemMap.h"
#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)
extern VAR(CanIf_MirrorBackupType, CANIF_VAR_NOINIT) CanIf_MirrorBackupSts[CANIF_MAX_HTH_NUM];
#endif
#define CANIF_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "CanIf_MemMap.h"


/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

extern FUNC(void, CANIF_CODE) CanIf_Init
(
    P2CONST(CanIf_ConfigType, AUTOMATIC, CANIF_CONST) ConfigPtr
);

extern FUNC(void, CANIF_CODE) CanIf_DeInit
(
    void
);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode
(
    uint8 ControllerId,
    P2VAR(CanIf_ControllerModeType, AUTOMATIC, CANIF_APPL_DATA) ControllerModePtr
);


extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit
(
    PduIdType CanTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
);

#if((STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API) && (CANIF_MAX_RXBUF_NUM > 0))
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReadRxPduData
(
    PduIdType CanRxPduId,
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
);
#endif

#if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)
#if(CANIF_MAX_TXNOTIFY_NUM > 0)
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadTxNotifStatus
(
    PduIdType CanTxPduId
);
#endif
#endif


#if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
#if(CANIF_MAX_RXNOTIFY_NUM > 0)
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadRxNotifStatus
(
    PduIdType CanRxPduId
);
#endif
#endif

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode
(
    uint8 ControllerId,
    CanIf_PduModeType PduModeRequest
);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetPduMode
(
    uint8 ControllerId,
    P2VAR(CanIf_PduModeType, AUTOMATIC, CANIF_APPL_DATA) PduModePtr
);

#if(STD_ON == CANIF_PUBLIC_VERSION_INFO_API)
extern FUNC(void, CANIF_CODE) CanIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CANIF_APPL_DATA) VersionInfo
);
#endif

#if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)
#if(CANIF_MAX_DYNTXPDU_NUM > 0)
extern FUNC(void, CANIF_CODE) CanIf_SetDynamicTxId
(
    PduIdType CanTxPduId,
    Can_IdType CanId
);
#endif
#endif

#if(CANIF_MAX_TRCV_NUM > 0)
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvMode
(
    uint8 TransceiverId,
    CanTrcv_TrcvModeType TranseiverMode
);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvMode
(
    uint8 TransceiverId,
    P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_APPL_DATA)  TransceiverModePtr
);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason
(
    uint8 TransceiverId,
    P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_APPL_DATA)  TrcvWuReasonPtr
);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvWakeupMode
(
    uint8 TransceiverId,
    CanTrcv_TrcvWakeupModeType TrcvWakeupMode
);
#endif

#if((STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) || (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT))
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup
(
    EcuM_WakeupSourceType WakeupSource
);

#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT)
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckValidation
(
    EcuM_WakeupSourceType WakeupSource
);
#endif
#endif

#if(STD_ON == CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT)
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_GetTxConfirmationState
(
    uint8 ControllerId
);
#endif

#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)
#if(CANIF_MAX_TRCV_NUM > 0)
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag
(
    uint8 TransceiverId
);
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTrcvWakeFlag
(
    uint8 TransceiverId
);
#endif
#endif

#if(STD_ON == CANIF_SET_BAUDRATE_API)
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetBaudrate
(
    uint8 ControllerId,
    const uint16 BaudRateConfigID
);
#endif


#if(STD_ON ==  CANIF_PUBLIC_ICOM_SUPPORT) /*SWS_CANIF_00875*/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetIcomConfiguration
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId
);
#endif

#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_EnableBusMirroring
(
    uint8 ControllerId,
    boolean MirroringActive
);
#endif


extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerErrorState
(
    uint8 ControllerId,
    P2VAR(Can_ErrorStateType, AUTOMATIC, CANIF_APPL_DATA) ErrorStatePtr
);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerRxErrorCounter
(
    uint8 ControllerId,
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) RxErrorCounterPtr
);

extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerTxErrorCounter
(
    uint8 ControllerId,
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) TxErrorCounterPtr
);

#if((CANIF_PRIVATE_SWTXFIFO_RETRY == STD_ON) && (CANIF_PRIVATE_SWTXFIFO_SUPPORT == STD_ON))
extern FUNC(void, CANIF_CODE) CanIf_MainFunction
(
    void
);
#endif

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#endif/*CANIF_H*/

