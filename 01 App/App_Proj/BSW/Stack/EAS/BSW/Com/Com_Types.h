/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name:       Com_Type.h
********************************************************************************
*   Project/Product: AUTOSAR R21-11
*   Title:           Com_Type.h
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


/*******************************************************************************
*    Macro define
*******************************************************************************/
#ifndef COM_TYPES_H
#define COM_TYPES_H

#include "ComStack_Types.h"
#include "Com_Cfg.h"
#include "Com_Version.h"
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
#include "Bmc.h"
#endif

#define COM_NO_TXMODE_SWITCH            ((uint8)0)
#define COM_TXMODE_SWITCH_SEND_SIGNAL   ((uint8)1)
#define COM_TXMODE_SWITCH_API_FALSE     ((uint8)2)
#define COM_TXMODE_SWITCH_API_TRUE      ((uint8)3)


#define COM_NO_TRIGGER               ((uint8)0)
#define COM_TRIGGER                  ((uint8)1)
#define COM_TRIGGER_REP              ((uint8)2)

#define COM_RX_TIMEOUT_NONE         ((uint8)0)
#define COM_RX_TIMEOUT_REPLACE      ((uint8)1)
#define COM_RX_TIMEOUT_SUBSTITUTE   ((uint8)2)

#define COM_INVALID_IFACTIVE_OFFSET_VALUE  ((uint8)0xFF)
/*******************************************************************************
*   data type definitions
*******************************************************************************/
#if(STD_ON == COM_DEM_EVENT_SET_SUPPORT)
typedef uint16 Com_EventIdType;
typedef uint8 Com_EventStatusType;
#define COM_INVALID_EVENT_ID            ((Com_EventIdType)0xFFFF)
#define COM_DEM_EVENT_STATUS_PREPASSED  ((Com_EventStatusType)0x02)
#define COM_DEM_EVENT_STATUS_PREFAILED  ((Com_EventStatusType)0x03)
#endif
/*SWS_Com_00819*/
typedef enum
{
    COM_UNINIT  = 0,
    COM_INIT    = 1
} Com_StatusType ;

typedef enum
{
    COM_OPAQUE          = 0,
    COM_LITTLE_ENDIAN   = 1,
    COM_BIG_ENDIAN      = 2
} Com_EndiannessType;

typedef uint16 Com_IpduGroupIdType;/*SWS_Com_00822*/
typedef uint16 Com_SignalIdType;/*SWS_Com_00820*/
typedef uint16 Com_SignalGroupIdType;/*SWS_Com_00821*/
typedef uint8  Com_ServiceIdType;/*SWS_Com_00824*/
#define COM_INVALID_SIG_GRP_ID ((Com_SignalGroupIdType)0xFFFF)

typedef enum
{
    COM_NOTIFY  = 0,
    COM_REPLACE = 1,
    COM_NONE    = 2
} Com_SigInvalidActionType ;

typedef enum
{
    COM_PENDING                                = 0,
    COM_TRIGGERED                              = 1,
    COM_TRIGGERED_WITHOUT_REPETITION           = 2,
    COM_TRIGGERED_ON_CHANGE                    = 3,
    COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION = 4,
    COM_IFACTIVE_SIG                           = 5,
    COM_IFACTIVE_ON_CHANGE_SIG                 = 6
} Com_SignalTxPropertyType ;

typedef enum
{
    COM_ALWAYS                           = 0,
    COM_MASKED_NEW_DIFFERS_MASKED_OLD    = 1,
    COM_MASKED_NEW_DIFFERS_X             = 2,
    COM_MASKED_NEW_EQUALS_X              = 3,
    COM_NEVER                            = 4,
    COM_NEW_IS_OUTSIDE                   = 5,
    COM_NEW_IS_WITHIN                    = 6,
    COM_ONE_EVERY_N                      = 7
} Com_FilterAlgorithmType ;

typedef enum
{
    COM_DIRECT       = 0,
    COM_MIXED        = 1,
    COM_PDU_NONE     = 2,
    COM_PERIODIC     = 3,
    COM_IFACTIVE_PDU  = 4
} Com_IpduTxPropertyType;


typedef enum
{
    COM_CUB_CONF         = 0,
    COM_CUB_TX           = 1,
    COM_CUB_TRIGGER      = 2,
    COM_CUB_NONE         = 3
} Com_ClearUpdateBitType;


typedef enum
{
    COM_SIG_U8            = 0,
    COM_SIG_U16           = 1,
    COM_SIG_U32           = 2,
    COM_SIG_BOOLEAN       = 3,
    COM_SIG_S8            = 4,
    COM_SIG_S16           = 5,
    COM_SIG_S32           = 6,
    COM_SIG_F32           = 7,
    COM_SIG_DYN           = 8,
    COM_SIG_U8N           = 9,
    COM_SIG_U64           = 10,
    COM_SIG_S64           = 11,
    COM_SIG_F64           = 12
} Com_SigType ;


typedef enum
{
    COM_TXPDU_STOP                  = 0,
    COM_TXPDU_START_IDLE            = 1,
    COM_TXPDU_START_BUSY            = 2, /* set when Tx Req is accept but no TxConf is back */
    COM_TXPDU_START_RETX            = 3, /* set when need retransmit*/
    COM_TXPDU_START_TXOK            = 4, /* set when tx conf is received, and result is ok */
    COM_TXPDU_START_TXNOTOK         = 5 /* set when tx conf is received, and result is not ok */
} Com_TxPduStateType ;

typedef enum
{
    COM_RXPDU_STOP          = 0,
    COM_RXPDU_START_IDLE    = 1,
    COM_RXPDU_START_BUSY    = 2,/* only used when Tp Rx is procesing*/
    COM_RXPDU_START_RXOK    = 3, /* set when data is received but not processed*/
    COM_RXPDU_START_RXNOTOK = 4, /* set only when tp packet  is received ,and result is not ok, */
    COM_RXPDU_START_RXSTOP  = 5 /* set when data is received ,but ipduCallout returns false */
} Com_RxPduStateType ;


/* in within withot: Par1 = min  Par2 = =max
   mask:  Par1 = FilterX   Par2 = Mask

   1EveryN : Par1 = =offset  Par2 = Peirod
*/

/*******************************************************************************
*   Share Buffer
*******************************************************************************/
typedef enum
{
    COM_NO_SEND         = 0,
    COM_SIG             = 1,
    COM_SIG_GRP         = 2,
    COM_SIG_GRP_INV     = 3,
    COM_SIG_GRP_ARRAY   = 4
} Com_TxSigSendModeType;

typedef struct
{
    Com_FilterAlgorithmType                FilterType;
    P2CONST(void, TYPEDEF, COM_CONST)      Par1;
    P2CONST(void, TYPEDEF, COM_CONST)      Par2;
    P2VAR(void, TYPEDEF, COM_VAR)          Par3;
#if (COM_MAX_FILTER_OCCURRENCE_NUM > 0)
    Com_SignalIdType                       OccIndex;
#endif
} Com_CfgSigFilterParsType;

typedef struct
{
    PduIdType PduId;
    uint16 PduStartByte;
}Com_PduQueueInfoType;

typedef CONSTP2VAR(Com_PduQueueInfoType, TYPEDEF, COM_VAR) Com_PduQueueInfoPtrType;
typedef CONSTP2VAR(uint8, TYPEDEF, COM_VAR) Com_PduQueueDataPtrType;
typedef struct
{
    Com_PduQueueInfoPtrType PduInfoPtr;
    Com_PduQueueDataPtrType PduDataPtr;
}Com_CfgPduQueueTableType;

typedef struct
{
    uint16 Head;
    uint16 Tail;
    boolean IsSameCycle;
}Com_RingQueueStateType;

/*Pdu Callouts*/
typedef P2FUNC(void, TYPEDEF, Com_RxSigCbkRxAckType)(void);
typedef P2FUNC(void, TYPEDEF, Com_RxSigCbkInvType)(void);
typedef P2FUNC(void, TYPEDEF, Com_RxSigCbkRxTOutType)(void);
typedef P2FUNC(void, TYPEDEF, Com_TxSigTxErrType) (void);
typedef P2FUNC(void, TYPEDEF, Com_TOIndicationType) (void);
typedef P2FUNC(void, TYPEDEF, Com_TxSigCbkTxAckType) (void);
typedef P2FUNC(void, TYPEDEF, Com_RxPduCbkRxTOutType)(void);
typedef P2FUNC(Std_ReturnType, TYPEDEF, Com_TxTriggerCalloutType)
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, TYPEDEF, COM_APPL_DATA) PduInfoPtr
);
typedef P2FUNC(boolean, TYPEDEF, Com_TxIpduCalloutType)/*SWS_Com_00700*/
(
    PduIdType PduId,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);

/* remove the const of the PduInfoPtr, as e2e may need to change the cyc byte of rxdata */
typedef P2FUNC(boolean, TYPEDEF, Com_RxIpduCalloutType)/*SWS_Com_00346*/
(
    PduIdType PduId,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
);


/*******************************************************************************
*   Core
*******************************************************************************/
typedef struct
{
#if(STD_ON == COM_TXPDU_FUN)
    PduIdType                                       CoreTxPduNum;
    P2CONST(PduIdType, AUTOMATIC, COM_CONST)        CoreTxPduTable;
#endif
#if(STD_ON == COM_RXPDU_FUN)
    PduIdType                                       CoreRxPduNum;
    P2CONST(PduIdType, AUTOMATIC, COM_CONST)        CoreRxPduTable;
#endif
} Com_CfgCoreTableType;

/*******************************************************************************
*   TX Type define
*******************************************************************************/
typedef struct
{
    Com_IpduTxPropertyType      TxModeMode;
    uint8                       TxModeNumberOfRepetitions;
    uint16                      TxModeRepetitionPeriod;
    uint16                      TxModeTimeOffset;
    uint16                      TxModeTimePeriod;
} Com_CfgTxModeTableType;

typedef struct
{
    boolean                         IpduTMSFlag; /* save the current txmode of pdu*/

    uint16                          TxModeTimePeriod;/* main cycle counter of txPdu */
    uint16                          TxModeTimeOffset;/* cycle offset */

#if (STD_ON == COM_MDT_CYCLIC_TRANSMISSION)
    uint16                          MininumDelayTimer;/*min Pdu delay timer*/
    boolean                         txMinDelayReqBackUp;/* if send req is delayed, it will be saved here */
#endif


#if (STD_ON == COM_TXMODE_REPTITION)
    uint16                          TimePeriodBackUp;/* Fast cycle counter of txPdu */
    uint8                           TxModeNumOfRep;/* Fast cycle num counter of txPdu */
    uint8                           TxConfNumOfRep;/* used to caculate the conf num of req tx */
#endif

#if (STD_ON == COM_THIRD_HANDLE_MIXED)
    boolean                         txReqBackUp;/* not used in this version*/
#endif

#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
    uint16                          TxIpduTimeOut;
#endif

#if(STD_ON == COM_TX_LONG_PDU_FUN)
    PduLengthType                   tpPduIndex;  /* only used when send tp packet*/
#endif
    P2CONST(Com_CfgTxModeTableType, TYPEDEF, COM_CONST)      TxModeSelectPtr;

#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
    PduLengthType                   TxDynLength; /* used to save the runtime pdu length of dyn pdu*/
#endif
#if (STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
    uint32  txActiveFlag; /*indicate pdu active or not, max support 32 signals ifactive in current version*/
    boolean  txActiveChangeFlag;
#endif
} Com_TxPduType;



typedef struct
{
    PduLengthType                                UpdateByteIndex;
    uint8                                        UpdateMaskValue;
    Com_SignalIdType                             UpdateSignalId;
#if(STD_ON == COM_TX_UB_CLEAR_DELAY_SUPPORT)
    P2VAR(uint8, TYPEDEF, COM_VAR)               UpdateDelayCntPtr;
#endif
}Com_CfgTxUpdateBitInfoType;

typedef struct
{
    PduLengthType                                UpdateByteIndex;
    uint8                                        UpdateMaskValue;
    Com_SignalIdType                             UpdateSignalId;
#if(STD_ON == COM_RX_SIGNAL_UB_TIMEOUT_SUPPORT)
    P2VAR(uint16, TYPEDEF, COM_VAR)              UpdateTimeoutCntPtr;
#endif
}Com_CfgRxUpdateBitInfoType;

typedef struct
{
#if(STD_ON == COM_TX_IMMEDIATE_SUPPORT)
    boolean                           isImmProcess;
#endif
#if (STD_ON == COM_MDT_CYCLIC_TRANSMISSION)
    uint16                            MinimumDelayTime;     /*ECUC_Com_00181*/
#endif
    Com_SignalIdType                  SignalStartNum;
    Com_SignalIdType                  SignalStopNum;
#if (STD_ON == COM_TX_TIMEOUT_MONITOR)
    uint16                            PeriodTimeOut;
    boolean                           TimeOutMonitorFlag;
#endif
#if (STD_ON == COM_IPDU_GROUP_FUN)
    boolean                           TxIPDUGroupFlag;
    Com_IpduGroupIdType                         numOfPduGrp;/* how many pdugroups  contains this pdu*/
    P2CONST(Com_IpduGroupIdType, AUTOMATIC, COM_CONST)       PduGrpPtr;
#endif
    PduIdType                         IpduMapPdur;
#if (STD_ON == COM_TX_FILTER_SUPPORT)
    P2VAR(uint8, TYPEDEF, COM_VAR)    TMCFilterFlagPtr;
    Com_SignalIdType                  FilterByteNum;/* 1 bit per signal, this byte num of TMCFilterFlagPtr*/
#endif

    P2VAR(void, TYPEDEF, COM_VAR)     SduDataPtr;
    PduLengthType   SduLength;

    P2CONST(Com_CfgTxModeTableType, TYPEDEF, COM_CONST) TxModeTrueCfgTablePtr;
    P2CONST(Com_CfgTxModeTableType, TYPEDEF, COM_CONST) TxModeFalseCfgTablePtr;
#if (STD_ON == COM_TX_DYN_PDU_SUPPORT)
    boolean                           isTxDynPdu;
#endif

#if (STD_ON == COM_TXIPDU_CALLOUT)
    Com_TxIpduCalloutType             Callout;
#endif
#if (STD_ON == COM_TX_TRIGGER_CALLOUT_SUPPORT)
    Com_TxTriggerCalloutType          TxTriggerCallout;
#endif

#if (STD_ON == COM_CANCEL_SUPPORT)
    boolean                           TxCancelTransmitSupportFlag;
#endif

#if(STD_ON == COM_TX_UPDATEBIT_SUPPORT)
    Com_ClearUpdateBitType            cubType;
    uint16                            updateBitNum;
    P2CONST(Com_CfgTxUpdateBitInfoType, TYPEDEF, COM_CONST) updateBitInfo;
#endif
#if(STD_ON == COM_TX_LONG_PDU_FUN)
    boolean                           isTpPdu;
#endif
    uint8                             unusedAreaByte;

#if(STD_ON == COM_MetaDataSupport)
    P2VAR(uint8, TYPEDEF, COM_VAR)    MetaDataDefaultPtr;     /*ECUC_Com_10005*/
    PduIdType                         GlobalPduId;
#endif

#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8                             CoreId;
#endif
#if (STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
    boolean                           IsInActiveCyclic;
#endif
} Com_CfgTxPduTableType;


typedef struct
{
    PduIdType                                       TxPduId;
    CONSTP2VAR(void, TYPEDEF, COM_VAR)              TxSigShareBufPtr;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    CONSTP2VAR(Com_TxSigSendModeType, TYPEDEF, COM_VAR) TxSigShareFlagPtr;
#endif
    Com_SignalTxPropertyType                        SigTransferProperty;
    Com_SigType                                     SigType;
    P2CONST(void, TYPEDEF, COM_CONST)               InitValPtr;
    PduLengthType                                   SigStartByteIndex; /* startbyte, only used in  U8N and Dyn sig,short signa always = 0*/
    PduLengthType                                   SigLen;/* length in byte*/
    Com_EndiannessType                              Endianness;
    uint16                                          BitSize;
    uint16                                          StartBit;
    uint8                                           MaskLsb;
    uint8                                           MaskMsb;
#if (STD_ON == COM_TX_INVALID_SUPPORT)
    P2CONST(void, TYPEDEF, COM_CONST)               InvalidValPtr;
#endif

#if (STD_ON == COM_TX_DYN_PDU_SUPPORT)
    PduLengthType                                   InitLen;   /* only for dyn signal */
#if (STD_ON == COM_TX_INVALID_SUPPORT)
    PduLengthType                                   InvalidLen;/* only for dyn signal */
#endif
#endif

#if(COM_TX_SIGNAL_GROUP_SUPPORT == STD_ON)
    boolean                                         isGroupSignal;
    Com_SignalGroupIdType                           groupId;
#if (STD_ON == COM_TX_DYN_PDU_SUPPORT)
    P2VAR(PduLengthType, TYPEDEF, COM_VAR)          GroupDynSigLengthBuf;
#endif
#endif

#if(COM_TX_UPDATEBIT_SUPPORT == STD_ON)
    uint16                                          updateBitIndex;  /* update info index in Pdu*/
#endif

#if(COM_TX_FILTER_SUPPORT == STD_ON)
    P2CONST(Com_CfgSigFilterParsType, TYPEDEF, COM_CONST)       TxSigFilter;
#endif

#if (STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
    uint8  txActiveFlagOffset; /*indicate the offset of ifactive signal of==in single pdu, 0xff when signal if not ifactive type*/
    P2CONST(void, TYPEDEF, COM_CONST)               InActiveValPtr;
#endif

#if(STD_ON == COM_TX_SIGNAL_ACK_FUNC_SUPPORT)
    CONST(Com_TxSigCbkTxAckType, COM_CONST)         SigCbkTxAckFun;
#endif
#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
    CONST(Com_TOIndicationType, COM_CONST)          SigTxTOIndicationFun;
#endif
#if(STD_ON == COM_TX_SIGNAL_ERR_FUNC_SUPPORT)
    CONST(Com_TxSigTxErrType, COM_CONST)            CbkTxErrFun;
#endif
} Com_CfgTxSigTableType;

/*******************************************************************************
*   RX Type define
*******************************************************************************/
typedef struct
{
#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)
    PduLengthType               dynLength;   /* only for dyn pdu, fix pdu keep 0*/
#endif

    PduLengthType               tempLength;   /* Used to save tem length before rxdata confirmed(such as rx filter or tp packet)*/

#if(STD_ON == COM_RX_LONG_PDU_FUN)
    PduLengthType               tpPduIndex;/* Used to Rx Tp Packet*/
#endif


#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
    boolean                     RxIpduTimeoutMonitorFlag;
    uint16                      RxPeriodTimeOut;
#endif
} Com_RxPduType;



typedef struct
{
#if(STD_ON == COM_RX_IMMEDIATE_SUPPORT)
    boolean                     isImmProcess;
#endif
    Com_SignalIdType            SignalStartNum;
    Com_SignalIdType            SignalStopNum;
#if (STD_ON == COM_IPDU_GROUP_FUN)
    boolean                     RxIPDUGroupFlag;
    Com_IpduGroupIdType                   numOfPduGrp;    /* how many pdugroups  contains this pdu*/
    P2CONST(Com_IpduGroupIdType, AUTOMATIC, COM_CONST)       PduGrpPtr;
#endif

#if (STD_ON == COM_RX_TIMEOUT_MONITOR)
    boolean                     RxIpduTimeoutMonitorFlag;
    uint16                      RxFirstTimeOut;
    uint16                      RxPeriodTimeOut;
#if (STD_ON == COM_RX_TIMEOUT_PDU_CBK_SUPPORT)
    CONST(Com_RxPduCbkRxTOutType, COM_CONST)    RxPduCbkRxTOutFun;
#endif
#endif

#if (STD_ON == COM_RX_DYN_PDU_SUPPORT)
    PduLengthType               RxPduFixLength;  /* fix part of pdu*/
    boolean                     isRxDynPdu;
#endif

#if (STD_ON == COM_RXIPDU_CALLOUT)
    Com_RxIpduCalloutType             Callout;
#endif

#if(STD_ON == COM_RX_UPDATEBIT_SUPPORT)
    Com_SignalIdType                            updateBitNum;
    P2CONST(Com_CfgRxUpdateBitInfoType, TYPEDEF, COM_CONST) updateBitInfo;
#endif


#if (STD_OFF == COM_RX_DIRECT_COPY)
    boolean                           RxIsDirectCopy;
#endif

    P2VAR(void, TYPEDEF, COM_VAR)     SduDataPtr;
    PduLengthType                     SduLength;
#if(STD_ON == COM_RX_LONG_PDU_FUN)
    boolean                           isTpPdu;
#endif
#if(STD_ON == COM_MetaDataSupport)
    PduIdType                         GlobalPduId;
#endif
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8                             CoreId;
#endif
} Com_CfgRxPduTableType;


typedef struct
{
    PduIdType                                         RxPduId;
    P2VAR(void, TYPEDEF, COM_VAR)                     RxSigShareBufPtr;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    Com_RxSigLockIndexType                            RxSigLockIndex;
#endif
    Com_SigType                                       SigType;
    P2CONST(void, TYPEDEF, COM_CONST)                 InitValPtr;
#if(STD_ON == COM_RX_SIGNAL_SUBSTITUTE_SUPPORT)
    P2CONST(void, TYPEDEF, COM_CONST)                 SubValPtr;
#endif
    PduLengthType                                     SigStartByteIndex; /* startbyte, only used in  U8N and Dyn sig,short signa always = 0*/
    PduLengthType                                     SigLen;/* length in byte, only used in    U8N and Dyn sig,short signa always = 0*/
    Com_EndiannessType                                Endianness;
    uint16                                            BitSize;
    uint16                                            StartBit;
    uint64                                            Mask;
#if (STD_ON == COM_RX_DYN_PDU_SUPPORT)
    PduLengthType                                     InitLen;   /* only for dyn signal */
    PduLengthType                                     SubLen;   /* only for dyn signal */
#endif

#if (STD_ON == COM_RX_INVALID_SUPPORT)
    Com_SigInvalidActionType                          DataInvalidAction;
    P2CONST(void, TYPEDEF, COM_CONST)                 InvalidValPtr;
#endif



#if (STD_ON == COM_GW_FUN)
    Com_SignalIdType                                  GwSigIndex;
#endif



#if(COM_RX_FILTER_SUPPORT == STD_ON)
    P2CONST(Com_CfgSigFilterParsType, TYPEDEF, COM_CONST) RxSigFilter;
#endif


#if(COM_RX_UPDATEBIT_SUPPORT == STD_ON)
    Com_SignalIdType                                  updateBitIndex;
#if (STD_ON == COM_RX_TIMEOUT_MONITOR)
    uint16                                            RxFirstTimeOut;
    uint16                                            RxPeriodTimeOut;
#endif
#endif
#if (STD_ON == COM_RX_TIMEOUT_MONITOR)
    uint8                                           TimeoutAct;
#endif


#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    boolean                                         isGroupSignal;
    Com_SignalGroupIdType                           groupId;
    P2VAR(void, TYPEDEF, COM_VAR)                   GroupSigTempBuf;
#if (STD_ON == COM_RX_DYN_PDU_SUPPORT)
    P2VAR(PduLengthType, TYPEDEF, COM_VAR)          GroupDynSigLengthBuf;
#endif

#endif

#if(STD_ON == COM_PADDING_SUPPORT)
    PduLengthType                                   MinSigByte;/* min length that can process this rx signal*/
#endif
#if(STD_ON == COM_DEM_EVENT_SET_SUPPORT)
    Com_EventIdType                                 DemEventId;
#endif
    CONST(Com_RxSigCbkRxAckType, COM_CONST)         RxSigCbkRxAckFun;
#if(STD_ON == COM_RX_INVALID_SUPPORT)
    CONST(Com_RxSigCbkInvType, COM_CONST)           RxSigCbkInvFun;
#endif
#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
    CONST(Com_RxSigCbkRxTOutType, COM_CONST)        RxSigCbkRxTOutFun;
#endif
} Com_CfgRxSigTableType;

typedef struct
{
    P2CONST(PduIdType, AUTOMATIC, COM_CONST)                 TxIpduGroupPtr; /* txPduIds in this group, include related txPduid*/
    PduIdType                                                TxIpduGroupNum;  /* number without related txpdu*/
    P2CONST(PduIdType, AUTOMATIC, COM_CONST)                 RxIpduGroupPtr;
    PduIdType                                                RxIpduGroupNum;
} Com_CfgPduGroupTableType;





typedef struct
{
    PduIdType                   PduId;
    Com_SignalTxPropertyType    SigGrpTransferProperty;
    boolean                     isArrayAccessSupport;
    Com_SignalIdType            SignalStartNum;
    Com_SignalIdType            SignalStopNum;
#if(COM_Enable_SignalGroupArrayApi == STD_ON)
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    CONSTP2VAR(uint8, TYPEDEF, COM_VAR) TxSigGrpShareBufPtr;
#endif
    uint16                      StartByte;
    uint16                      ByteNum;
#endif
    Com_SignalIdType            updateBitIndex;
    boolean                     hasInValidVal;
    boolean                     hasFilter;
} Com_CfgTxSigGroupType;

typedef struct
{
    PduIdType                   PduId;
    Com_SignalTxPropertyType    SigGrpTransferProperty;
    boolean                     isArrayAccessSupport;
    Com_SignalIdType            SignalStartNum;
    Com_SignalIdType            SignalStopNum;
#if(COM_Enable_SignalGroupArrayApi == STD_ON)
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    CONSTP2VAR(uint8, TYPEDEF, COM_VAR) TxSigGrpShareBufPtr;
#endif
    uint16                      StartByte;
    uint16                      ByteNum;
#endif
    Com_SignalIdType            updateBitIndex;
    boolean                     hasInValidVal;
    boolean                     hasFilter;
} Com_CfgRxSigGroupType;


#if((COM_RX_MULTI_MAINFUNCTION_ENABLE == STD_ON) || (COM_TX_MULTI_MAINFUNCTION_ENABLE == STD_ON))
typedef struct
{
#if(COM_MULTI_CORE_SUPPORT == STD_ON)
    uint8 CoreRef;
#endif
    PduIdType PduNum;
    P2CONST(PduIdType, AUTOMATIC, COM_CONST) PduIdPtr;
} Com_MainfunctionCfgType;
#endif


typedef struct
{
    Com_SignalIdType    GwTxSignalId;
    boolean             GwIsSigGrp;
}Com_CfgGwTxSigTableType;

typedef struct
{
    Com_SignalIdType        GwRxSignalId;
    Com_SignalIdType        GwTxSignalNum;
    P2CONST(Com_CfgGwTxSigTableType, AUTOMATIC, COM_CONST) GwTxSignalTable;
}Com_CfgGwSigType;

typedef struct
{
    uint32                       PBConfigId;
    PduIdType                    RxPduNum;
    Com_SignalIdType             RxSigNum;
    PduIdType                    TxPduNum;
    Com_SignalIdType             TxSigNum;
    Com_SignalGroupIdType        TxSigGrpNum;
    Com_SignalGroupIdType        RxSigGrpNum;
    Com_IpduGroupIdType          PduGroupNum;
    Com_SignalIdType             GWSigNum;
    uint8                        CoreNum;
    CONSTP2CONST(Com_CfgTxPduTableType, TYPEDEF, COM_CONST)     TxPduCfg;
    CONSTP2CONST(Com_CfgTxSigTableType, TYPEDEF, COM_CONST)     TxSigCfg;
    CONSTP2CONST(Com_CfgRxPduTableType, TYPEDEF, COM_CONST)     RxPduCfg;
    CONSTP2CONST(Com_CfgRxSigTableType, TYPEDEF, COM_CONST)     RxSigCfg;
    CONSTP2CONST(Com_CfgPduGroupTableType, TYPEDEF, COM_CONST)  PduGroupCfg;
    CONSTP2CONST(Com_CfgRxSigGroupType, TYPEDEF, COM_CONST)       RxSignalGroupCfg;
    CONSTP2CONST(Com_CfgTxSigGroupType, TYPEDEF, COM_CONST)     TxSignalGroupCfg;
    CONSTP2CONST(Com_CfgGwSigType, TYPEDEF, COM_CONST)          GWSigCfg;
    CONSTP2CONST(Com_CfgCoreTableType, TYPEDEF, COM_CONST)      CoreCfg;
} Com_ConfigType;

#endif
