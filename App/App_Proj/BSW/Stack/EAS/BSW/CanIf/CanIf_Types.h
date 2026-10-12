/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanIf_Types.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : CAN Interface module type definitions head File
*   Author          : HeYang
********************************************************************************
*   Description     : The header file CanIf_Types.h contains the  common type
*                     definitions of the module Can Interface
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

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 4641,3436 EOF*/
/*
Specific naming methods.
Existence condition #ifndef Can_ReturnType.
*/

#ifndef CANIF_TYPES_H
#define CANIF_TYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Can_GeneralTypes_Cfg.h"
#include "CanIf_Cfg.h"
#include "CanIf_Version.h"


/*******************************************************************************
*   Typedef
*******************************************************************************/
#if(CANIF_CAN_VERSION_NEWER_THAN_422 == STD_OFF)
/*Operating modes of the CAN Controller and CAN Driver SWS_CANIF_00136*/
typedef enum
{
    /*UNINIT mode. Default mode of the CAN Driver and all CAN controllers
    connected to one CAN network after power on. */
    CANIF_CS_UNINIT = 0,
    /*SLEEP mode. At least one of all CAN controllers connected to one CAN
    network are set into the SLEEP mode and can be woken up by request of the
    CAN Driver or by a network event (must be supported by CAN hardware) */
    CANIF_CS_SLEEP = 1,
    /*STARTED mode. All CAN controllers connected to one CAN network are started

    by the CAN Driver and in full-operational mode. */
    CANIF_CS_STARTED = 2,
    /*STOPPED mode. At least one of all CAN controllers connected to one CAN
    network is halted and does not operate on the network. */
    CANIF_CS_STOPPED = 3

} CanIf_ControllerModeType;

#else

#define CanIf_ControllerModeType            Can_ControllerStateType
#define CANIF_CS_UNINIT                     CAN_CS_UNINIT
#define CANIF_CS_SLEEP                      CAN_CS_SLEEP
#define CANIF_CS_STARTED                    CAN_CS_STARTED
#define CANIF_CS_STOPPED                    CAN_CS_STOPPED

#define Can_StateTransitionType             Can_ControllerStateType
#define CAN_T_START                         CAN_CS_STARTED
#define CAN_T_STOP                          CAN_CS_STOPPED
#define CAN_T_SLEEP                         CAN_CS_SLEEP
#define CAN_T_WAKEUP                        CAN_CS_STOPPED

#endif

#ifndef Can_ReturnType
#define Can_ReturnType                      Std_ReturnType
#define CAN_OK                              E_OK
#define CAN_NOT_OK                          E_NOT_OK
#endif

#define CANIF_CAN_MAX_DLC                   ((uint8)8)
#define CANIF_CANFD_MAX_DLC                 ((uint8)64)

/*SWS_CANIF_00137*/
typedef enum
{

    CANIF_OFFLINE           = 0,
    CANIF_TX_OFFLINE_ACTIVE = 1,
    CANIF_TX_OFFLINE        = 2,
    CANIF_ONLINE            = 3
} CanIf_PduModeType ;


typedef enum
{

    EXTENDED_CAN,
    EXTENDED_FD_CAN,
    EXTENDED_NO_FD_CAN,
    STANDARD_CAN,
    STANDARD_FD_CAN,
    STANDARD_NO_FD_CAN
} CanIf_PduCanIdType ;




/*Return value of CAN L-PDU notification status.SWS_CANIF_00201*/
typedef enum
{
    /*No transmit or receive event occurred for the requested L-PDU.*/
    CANIF_NO_NOTIFICATION    = 0,
    /*The requested Rx/Tx CAN L-PDU was successfully transmitted or received.*/
    CANIF_TX_RX_NOTIFICATION = 1
} CanIf_NotifStatusType ;

typedef P2FUNC(void, TYPEDEF, CanIf_User_RxIndicationType)
(
    PduIdType CanUserRxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
);

typedef P2FUNC(void, TYPEDEF, CanIf_User_TxConfirmationType)
(
    PduIdType CanUserTxPduId,
    Std_ReturnType result
);

typedef P2FUNC(Std_ReturnType, TYPEDEF, CanIf_User_TriggerTransmitType)
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
);

#if(STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT)
#define CANIF_TXSWFIFO_INVALID_POS           ((uint8)0xFF)

typedef struct
{
    uint8                 Header;
    uint8                 Tail;
} CanIf_TxSwFifo_Que_Type;

typedef struct
{
    Can_IdType  id ;
    PduIdType   swPduHandle;
    uint8       length ;
    P2VAR(uint8, TYPEDEF, CANIF_VAR_NOINIT) sdu; /* use pointer to reduce ram cost*/
} CanIf_TxSwFifo_Buf_Type;

#endif

typedef struct
{
    uint8                   CanIfCtrlIdRef;  /*CANIF625_Conf */
    boolean                 isFullCanType; /*CANIF626_Conf*/
    Can_HwHandleType        HthIdSymRef;   /*CANIF627_Conf*/
#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
    PduIdType               FirstBufIndexHth;
    PduIdType               TxBufSize;
#endif
#if(STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT)
    P2VAR(CanIf_TxSwFifo_Buf_Type, TYPEDEF, CANIF_VAR_NOINIT) fifoBuf;
    P2VAR(uint8, TYPEDEF, CANIF_VAR_NOINIT) fifoData;
    P2VAR(CanIf_TxSwFifo_Que_Type, TYPEDEF, CANIF_VAR_NOINIT) fifoCtrl;
    uint8 quedepth;
    uint8 sbufsize; /* single msg buf size*/
#endif
} CanIf_HthCfgType;


/* config pdu structs types */
typedef struct
{
    /* CANIF591_Conf CanIfTxPduId is contained in this struct */
    Can_IdType              CanId;                  /* CANIF592_Conf CANIF590_Conf*/
    CanIf_PduCanIdType      CanIdType;              /* CANIF590_Conf */
    uint8                   Length;                 /* CANIF594_Conf DLC */
#if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)
    boolean                 TxPduReadNotifyStatus;  /* CANIF589_Conf*/
    PduIdType               TxNotifyIndex;
#endif
#if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)
    boolean                 isDynPduType;           /* CANIF593_Conf */
    PduIdType               DynPduIndex;
#endif
#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
    PduIdType               TxBufIndex;
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) dataBuf;
#endif
#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)
    boolean                 isPnFilterPdu;          /*CANIF773_Conf*/
#endif
#if(STD_ON == CANIF_TRIGGER_TRANSMIT_SUPPORT)
    boolean                 isTriggerPdu;
    uint8                   TriggerTransmit;
#endif
    Can_HwHandleType        HthRef;
    uint8                   TxConfirmation;         /* CANIF527_Conf */
    PduIdType               PduRef;                 /* CANIF603_Conf handle for uplayyer module */
    boolean                 TxPduTruncation;        /* ECUC_CanIf_00845 */
#if(STD_ON == CANIF_METADATA_SUPPORT)
    PduIdType               GlobalPduId;
#endif
#if((STD_ON == CANIF_METADATA_SUPPORT) || (STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API))
    Can_IdType               TxPduCanIdMask;
#endif
} CanIf_TxPduCfgType;


#if(STD_ON == CANIF_HRH_RANGE_FILTER_SUPPORT)
typedef struct
{
    /*CANIF745_Conf*/
    Can_IdType                      LowerCanId;
    /*CANIF744_Conf*/
    Can_IdType                      UpperCanId;
} CanIf_RxPduCanIdRangeCfgType;
#endif


typedef struct
{
    uint8                   CanIfCtrlIdRef;  /*CANIF625_Conf */
    boolean                 isFullCanType; /*CANIF626_Conf*/
    Can_HwHandleType        HrhIdSymRef;   /*CANIF627_Conf*/
#if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
    PduIdType               FirstRxPduIdInHrh;
#endif

#if(CANIF_FILTER_TYPE_DICH == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
    PduIdType               pduNumInHrh;
    CONSTP2CONST(PduIdType, TYPEDEF, CANIF_CONST) pduList;
#endif

} CanIf_HrhCfgType;


typedef struct
{
    /* CANIF597_Conf CanIfRxPduId is contained in this struct */
    Can_IdType                    CanId;            /* CANIF598_Conf */
    Can_IdType                    CanIdMask;
    CanIf_PduCanIdType            CanIdType;        /* CANIF596_Conf */
    uint8                         Length;           /* CANIF599_Conf */
#if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
    boolean                       RxPduReadData;    /* CANIF600_Conf */
    PduIdType                     RxBufIndex;
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) dataBuf;
#endif
#if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
    boolean                       RxPduReadNotifyStatus; /* CANIF595_Conf */
    PduIdType                     RxNotifyIndex;
#endif
#if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
    PduIdType                     NextPduId;      /*  */
#endif
#if(STD_ON == CANIF_HRH_RANGE_FILTER_SUPPORT)
    CONSTP2CONST(CanIf_RxPduCanIdRangeCfgType, TYPEDEF, CANIF_CONST) IdRange;
#endif
#if(STD_ON == CANIF_PRIVATE_DLC_CHECK)
    boolean                       needDlcCheck;     /* ECUC_CanIf_00846 */
#endif
    uint8                         RxIndication;     /* CANIF529_Conf  */
    PduIdType                     PduRef;           /* CANIF601_Conf handle for uplayyer module */
    Can_HwHandleType              HrhRef;           /* CANIF602_Conf  */
#if(STD_ON == CANIF_METADATA_SUPPORT)
    PduIdType                     GlobalPduId;
#endif
} CanIf_RxPduCfgType;


#if(CANIF_FILTER_TYPE_TABLE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
typedef uint8 CanIf_ContrllerPduIndexCfgType;
typedef P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) CanIf_RxPduTableCfgType;
#endif


/*SWS_CANIF_00378*/

typedef P2FUNC(Can_ReturnType, TYPEDEF, CanIf_CanWriteType)
(
    Can_HwHandleType Hth,
    P2CONST(Can_PduType, AUTOMATIC, CANIF_APPL_DATA) PduInfo
);

typedef P2FUNC(Can_ReturnType, TYPEDEF, CanIf_CanSetControllerModeType)
(
    uint8 Controller,
    Can_StateTransitionType Transition
);

typedef P2FUNC(Can_ReturnType, TYPEDEF, CanIf_CanCheckWakeupType)
(
    uint8 Controller
);
#if(STD_ON == CANIF_SET_BAUDRATE_API)
typedef P2FUNC(Std_ReturnType, TYPEDEF, CanIf_CanChangeBaudrateType)
(
    uint8 Controller,
    const uint16 Baudrate
);
#endif


typedef P2FUNC(Std_ReturnType, TYPEDEF, CanIf_CanSetIComConfigrationType)
(
    uint8 Controller,
    IcomConfigIdType ConfigurationId
);

typedef P2FUNC(Std_ReturnType, TYPEDEF, CanIf_CanGetControllerErrorState)
(
    uint8 ControllerId,
    P2VAR(Can_ErrorStateType, AUTOMATIC, CANIF_APPL_DATA) ErrorStatePtr
);

typedef P2FUNC(Std_ReturnType, TYPEDEF, CanIf_CanGetControllerRxErrorCounter)
(
    uint8 ControllerId,
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) RxErrorCounterPtr
);

typedef P2FUNC(Std_ReturnType, TYPEDEF, CanIf_CanGetControllerTxErrorCounter)
(
    uint8 ControllerId,
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) TxErrorCounterPtr
);

typedef struct
{
    /* CANIF647_Conf CANIF_CTRL_ID is contained in this struct */
    boolean                       isWakeupSupport;   /* CANIF637_Conf, 0 means no wakeup support */
#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_PNNM)
    NetworkHandleType             CanIfToNmChannel;
#endif
    uint8                         CanDrvIndex;
    uint8                         CanCtrlIdRef;      /* CANIF636_Conf, each canDrv start from 0 */
#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)
    boolean                       isPnFilter;        /* adjust for Nm first message  1025 */
#endif
} CanIf_CtrlCfgType;


typedef struct
{
    /* CANIF654_Conf CANIF_TRCV_ID is contained in this struct */
    boolean                       isWakeupSupport;   /* CANIF606_Conf, 0 means no wakeup support  */
    uint8                         TrcvDrvIndex;
    uint8                         CanTrcvRef ;       /* CANIF605_Conf */
} CanIf_TrcvCfgType;


#if((STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) || (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT))
/* used in checkwakeup and wakeup validation
   trcv wakeup must related 1 Ctrl Wakeup this is used in validation
   may not support 1 Trcv connect to muti Ctrls, or 1 Ctrl connect to muti Trcvs
   only support single trcv with single Ctrl case
*/
typedef struct
{
    uint32         				  Source;            /* Wakeup Source from EcuM*/
    uint8                         CanIfCtrlIndex;    /* Ctrl Index: used in both type */
#if(STD_ON == CANIF_TRCV_WAKEUP_SUPPORT)
    uint8                         CanIfTrcvIndex;    /* Trcv Index: used only when src is Trcv type*/
    boolean                       isCtrlWakeupType;  /* Trcv WakeSrc or Ctrl WakeSrc*/
#endif
} CanIf_WakeupCfgType;
#endif



/*SWS_CANIF_00144 523*/
typedef struct
{
    PduIdType   NumOfRxPdu;          /*CANIF621_Conf*/
    PduIdType   NumOfTxPdu;          /*CANIF622_Conf  CANIF623_Conf*/
    Can_HwHandleType  NumOfHrh;
    Can_HwHandleType  NumOfHth;

#if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
    PduIdType    NumOfRxBuf;
#endif
#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
    PduIdType   NumOfTxBuf;
#endif
#if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)
    PduIdType   NumOfTxNotify;
#endif
#if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
    PduIdType    NumOfRxNotify;
#endif
#if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)
    PduIdType    NumOfDynTxPdu;
#endif

    CONSTP2CONST(CanIf_TxPduCfgType, TYPEDEF, CANIF_CONST) TxPduCfg;
    CONSTP2CONST(CanIf_RxPduCfgType, TYPEDEF, CANIF_CONST) RxPduCfg;
    CONSTP2CONST(CanIf_HthCfgType, TYPEDEF, CANIF_CONST) HthCfg;
    CONSTP2CONST(CanIf_HrhCfgType, TYPEDEF, CANIF_CONST) HrhCfg;
} CanIf_ConfigType;

/*For Funciton Mirror_ReportCanFrame*/
#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)
typedef struct
{
    Can_IdType      CanID;
    uint8           length;
#if(STD_ON == CANIF_PRIVATE_CANFD_SUPPORT)
    uint8           MirrorHthBuffer[CANIF_CANFD_MAX_DLC];
#else
    uint8           MirrorHthBuffer[CANIF_CAN_MAX_DLC];
#endif
} CanIf_MirrorBackupType;
#endif

#if(CANIF_MAX_TRCV_NUM > 0)
/* Function types for trcv Drv */
typedef P2FUNC(Std_ReturnType, TYPEDEF, CanIf_TrcvSetOpModeType)
(
    uint8 Transceiver,
    CanTrcv_TrcvModeType OpMode
);
typedef P2FUNC(Std_ReturnType, TYPEDEF, CanIf_TrcvGetOpModeType)
(
    uint8 Transceiver,
    P2VAR( CanTrcv_TrcvModeType, AUTOMATIC, CANIF_APPL_DATA ) OpMode
);
typedef P2FUNC(Std_ReturnType, TYPEDEF, CanIf_TrcvGetBusWuRType)
(
    uint8 Transceiver,
    P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_APPL_DATA ) Reason
);
typedef P2FUNC(Std_ReturnType, TYPEDEF, CanIf_TrcvSetWuModeType)
(
    uint8 Transceiver,
    CanTrcv_TrcvWakeupModeType TrcvWakeupMode
);

typedef P2FUNC( Std_ReturnType, TYPEDEF, CanIf_CBWakeupByBusType)
(
    uint8 Transceiver
);

typedef P2FUNC(Std_ReturnType, TYPEDEF, CanIf_TrcvCheckWakeupType)
(
    uint8 Transceiver
);


#if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)
typedef P2FUNC(Std_ReturnType, TYPEDEF, CanIf_ClearTrcvWufFlagType)
(
    uint8 Transceiver
);
typedef P2FUNC(Std_ReturnType, TYPEDEF, CanIf_CheckTrcvWakeFlagType)
(
    uint8 Transceiver
);

typedef P2FUNC(void, TYPEDEF, CanIf_TrcvPnIndType)
(
    uint8 Transceiver
);

#endif

#endif

#endif/*CANIF_TYPE_H*/
