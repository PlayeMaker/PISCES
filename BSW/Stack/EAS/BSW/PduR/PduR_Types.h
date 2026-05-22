/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name         : PduR_Types.h
********************************************************************************
*     Project/Product : AUTOSAR R21-11
*     Title           : PduR_Types.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file PduR_Types.h contains the declaration of
*                       types which is used by the PduR module
*
********************************************************************************
*     Limitations     : None
*
********************************************************************************
*
********************************************************************************
*     Revision History:
*     Reference to Core C File
********************************************************************************
* END_FILE_HDR*/
#ifndef PDUR_TYPES_H
#define PDUR_TYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "PduR_Cfg.h"


#define PDUR_UNUSED    ((PduIdType)0xFFFF)

/*SWS_PduR_00771*/
typedef uint8 PduR_PBConfigIdType;
#define PDUR_INVALID_CONFIG_ID  (0xff)

typedef uint16 PduR_MulticastMaskType;
typedef PduIdType PduR_RoutingPathIdType;
typedef PduIdType PduR_BufferIdType;
typedef PduIdType PduR_BufferPoolIdType;
/*SWS_PduR_00654*/
typedef uint16 PduR_RoutingPathGroupIdType;
#define PDUR_RPGROUP_NONE    ((PduR_RoutingPathGroupType*)NULL_PTR)
#define PDUR_BUFFER_NO_PATH  ((PduR_RoutingPathIdType)(0xffff))
#define PDUR_BUFFER_NO_FLAG  (NULL_PTR)

typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TransmitFctPtrType) (PduIdType TxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr);
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TriggerTransmitFctPtrType) (PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA)PduInfoPtr);
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_IfRxIndicationType) (PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr);
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_IfTxConfirmationFctPtrType) (PduIdType TxPduId, Std_ReturnType result);

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_StartOfReceptionFctPtrType) \
                                    (PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, \
                                    PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyRxDataFctPtrType) \
                                    (PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, \
                                    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr);

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyTxDataFctPtrType) \
                                    (PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, \
                                    P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) avaiableDataPtr);
                                    
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpRxIndicationFctPtrType) (PduIdType id, Std_ReturnType result);
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpTxConfirmationFctPtrType) (PduIdType id, Std_ReturnType result);
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_CancelTransmitFctPtrType)(PduIdType TxPduId);
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TpCancelReceiveFctPtrType) (PduIdType RxPduId);

typedef struct
{
    PduR_CancelTransmitFctPtrType IfCancelTransmitFunc;
    PduR_TransmitFctPtrType IfTransmitFunc;
    PduR_TpCancelReceiveFctPtrType TpCancelReceiveFunc;
    PduR_CancelTransmitFctPtrType TpCancelTransmitFunc;
    PduR_TransmitFctPtrType TpTransmitFunc;
    PduR_IfRxIndicationType UpIfRxIndicationFunc;
    PduR_TriggerTransmitFctPtrType UpIfTriggerTransmitFunc;
    PduR_IfTxConfirmationFctPtrType UpIfTxConfirmationFunc;
    PduR_CopyRxDataFctPtrType UpTpCopyRxDataFunc;
    PduR_CopyTxDataFctPtrType UpTpCopyTxDataFunc;
    PduR_StartOfReceptionFctPtrType UpTpStartOfReceptionFunc;
    PduR_TpRxIndicationFctPtrType UpTpRxIndicationFunc;
    PduR_TpTxConfirmationFctPtrType UpTpTxConfirmationFunc;
} PduR_ModuleFunc;
typedef struct{
    uint8* BufferPool;
    uint32 PoolSize;
    uint32 BufferSize;
    uint64 *BufferInUse;
}BufferPoolType;

typedef struct
{
    uint8 AllocatedBufferPool;
    uint8 AllocatedBufferIndex;
    PduLengthType AllocatedBufferLen;
    PduLengthType ValidLen;
    PduLengthType ReceivedLen;
    PduLengthType AvailableLen;
    PduLengthType WritePos;
    PduLengthType ReadPos;
    uint8  BufState;
    PduLengthType TotalLen;
    uint8 RxFail;
    PduR_RoutingPathIdType PathIdx;
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
    boolean TxAllowFlag; 
    uint8 UpTpTransmit;
    uint8 UpTpReceive;
    uint8 UpIfTransmit;
    uint32 PduFlag;
#endif

#if(STD_ON == PDUR_METADATA_SUPPORT)
    P2VAR(uint8, AUTOMATIC, PDUR_VAR) MetaDataPtr;
    boolean IsStore;
#endif

} PduRBuffInfoType;

typedef enum
{
    PDUR_NO_CROSSCOREDATA  = 0,         /*PDU Router not initialised*/
    PDUR_WITH_CROSSCOREDATA  = 1,       /*PDU Router initialized successfully*/
    PDUR_FIRST_WAIT_TXCONFIRMATION  = 2
} PduR_CrossCoreBufferStatus;

typedef struct
{
    PduLengthType RearPos;
    PduLengthType FrontPos;
    PduLengthType QueueAvailableLen;
    uint8 CrossCoreStatus;
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
    uint32 QueueInfoFlag;
#endif
} PduRBufferQueueInfoType;

typedef enum
{
    PDUR_DIRECT = 0,            /*not buffer the I-PDU*/
    PDUR_TRIGGERTRANSMIT = 1    /*The destination module will request the I-PDU using the
                                 triggerTransmit function. The I-PDU is shall be buffered.*/
} PduR_DestProvisionType;

#define PDUR_TPGW_TRIGGER_IND   ((uint16)2)
#define PDUR_TPGW_TRIGGER_FLY   ((uint16)1)

/*SWS_PduR_00324 SWS_PduR_00742*/
typedef enum
{
    PDUR_UNINIT  = 0,    /*PDU Router not initialised*/
    PDUR_ONLINE  = 1     /*PDU Router initialized successfully*/
} PduR_StateType;

typedef struct
{
    PduIdType                  PduRSrcPduHandleId;
    uint8                      PduRSrcModuleType;
    uint8                      PduRSrcPduCore;
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
    PduIdType                  UpperPduId;
#endif
} PduRSrcPdu_Type;

typedef struct
{
    P2CONST(PduR_RoutingPathGroupIdType, AUTOMATIC, PDUR_CONST) PduRRoutingGroup;
    PduR_RoutingPathGroupIdType PduRRoutingGroupMaxNum;
} PduR_RoutingPathGroupType;


typedef struct
{
    PduIdType                     PduRDestPduId;
    PduR_RoutingPathIdType        PduRDestPduConfIndex;
    uint8                         PduRDestModuleType;
    PduLengthType                 PduRDestLength;                              
    PduR_DestProvisionType        PduRDestPduDataProvision;
    uint16                        PduRTpThreshold;
    uint16                        PduRTpGWTrigger;
#if(PDUR_PDU_BUFFER_SUPPORT == STD_ON)
    PduR_BufferIdType             PduRDestTxBufferId;
    PduR_BufferPoolIdType         PdurDestTxBufferPoolId;
#endif
    P2CONST(PduR_RoutingPathGroupType, AUTOMATIC, PDUR_CONST) PduRRoutingGroup;
#if(PDUR_MULTICORE_SUPPORT == STD_ON)
    uint8                         PduRDestPduCore;
#endif
} PduRDestPdu_Type;


typedef struct
{
    P2P2VAR(uint8, AUTOMATIC, PDUR_VAR) PduPtr;
    P2VAR(PduRBuffInfoType, AUTOMATIC, PDUR_VAR) BufferInfo;
    PduLengthType DeepLen;
    PduLengthType BufferLen;
#if(PDUR_MULTICORE_SUPPORT == STD_ON)
    P2VAR(uint8, AUTOMATIC, PDUR_VAR) PduFlag;
#endif
} PduRBuffer_Type;


typedef struct
{
    CONST(PduRSrcPdu_Type, PDUR_CONST)  PduRSrcPdu;     /*for up-to-ower, id of TxPduId
                                                          for lower, id of RxPduId*/
    CONST(PduRDestPdu_Type, PDUR_CONST) PduRDestPdu;
    CONST(PduR_MulticastMaskType, PDUR_CONST) ConfMask; /*for up-to-lower, each dest of the same src takes one bit;
                                             for lower-to-up, always zero
                                             for lower-to-lower, each buffered dest of the same src takes one bit*/
} PduRRoutingPathInfoType;


typedef struct
{
    CONST(PduR_RoutingPathIdType, PDUR_CONST)  NumPaths;
    P2CONST(PduR_RoutingPathIdType, AUTOMATIC, PDUR_CONST) PathIdx;  /*pointer to an array containning path ids*/
    CONST(PduR_MulticastMaskType, PDUR_CONST)  ConfMask; /*sum of paths' ConfMask*/
} PduRRoutingPduInfoType;

typedef struct
{

    PduR_RoutingPathIdType PathId;    /*ECUC_PduR_00322*/
    PduIdType              UpperPduId;
} PduRTxConfMapping_Type;

typedef struct
{
    PduIdType NumTxPdu;
    P2VAR(PduR_MulticastMaskType, AUTOMATIC, PDUR_VAR) TxErrorMask;
    P2VAR(PduR_MulticastMaskType, AUTOMATIC, PDUR_VAR) TxConfMask;
    P2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) TxConfMap;
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) RountingInfo;
}PduR_TxPduInfo;

typedef struct
{
    PduR_RoutingPathIdType PathId;
} PduRRxCancelMapping_Type;

typedef struct
{
    PduIdType NumRxPdu;
    P2CONST(PduRRxCancelMapping_Type, AUTOMATIC, PDUR_CONST) RxCancelMap;
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) RountingInfo;
}PduR_RxPduInfo;

/*SWS_PduR_00743 SWS_PduR_00241*/
typedef struct
{
    CONST(PduIdType, PDUR_CONST) TxPduInfoNum;
    CONST(PduIdType, PDUR_CONST) RxPduInfoNum;
    CONST(PduIdType, PDUR_CONST) TxPduTxConfNum;
    CONST(PduIdType, PDUR_CONST) RxPduCancleNum;
    CONST(PduR_PBConfigIdType, PDUR_CONST) PBConfigId;/*ECUC_PduR_00327*/
    CONST(PduR_RoutingPathIdType, PDUR_CONST) RoutingPathNum;
    CONSTP2CONST(PduRRoutingPathInfoType, AUTOMATIC, PDUR_CONST) pRoutingTbl;
    CONST(PduR_RoutingPathGroupIdType, PDUR_CONST) RoutingPathGroupNum;
    P2CONST(boolean, AUTOMATIC, PDUR_CONST) RPGroupEnabledAtInit;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) TxPduInfo;
    CONSTP2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) RxPduInfo;
    CONSTP2CONST(PduRTxConfMapping_Type, AUTOMATIC, PDUR_CONST) TxConfPduInfo;
    CONSTP2CONST(PduRRxCancelMapping_Type, AUTOMATIC, PDUR_CONST) CancelRxPduInfo;
#if(PDUR_PDU_BUFFER_SUPPORT == STD_ON)
    CONST(PduR_BufferIdType, PDUR_CONST) BufferNum;
    P2CONST(PduRBuffer_Type, AUTOMATIC, PDUR_CONST) Buffer;
#endif
} PduR_PBConfigType;

typedef struct
{
    uint8 ErrorType;
    PduR_BufferIdType ErrorBufferId;
    PduRBuffInfoType ErrorBufferInfo;
    PduRBufferQueueInfoType ErrorBufferQueueInfo;
    uint64 BufferPoolUsage;
    uint8 PduContent[5];

}PduR_ErrorInfoType; 

#if(PDUR_MULTICORE_SUPPORT == STD_ON)
typedef struct
{
    PduR_RoutingPathIdType CrossCorePathNum;
    PduR_RoutingPathIdType *CrossCorePathIdx;
}PduR_CrossCorePathType;
#endif

typedef struct
{
    uint8 CoreId;
    P2CONST(BufferPoolType, AUTOMATIC, PDUR_CONST) BufferPoolSet;
    uint8 NumOfBufferPool;
}BufferPoolSetType;

#endif /* PDUR_TYPES_H */

