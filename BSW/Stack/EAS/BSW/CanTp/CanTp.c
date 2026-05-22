/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanTp.c
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : CanTp.c
*   Author          : HiRain
********************************************************************************
*   Description     : Source of AUTOSAR Basic Software module CAN Transport
*                     Layer (CanTp).
********************************************************************************
*   Limitations     :
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials          CR#          Descriptions
*   ---------   ----------    ---------------  ----------   ---------------
*   04.00.00    06/01/2023    Tiantian.Liang    N/A          Original
*   04.00.01    05/03/2024    Feixiang.Dong     N/A          EAS470_CanTp_20240305_01
*   04.00.02    18/04/2024    Wenbo.Cui         N/A          EAS470_CanTp_20240418_01
*   04.00.03    01/08/2024    Feixiang.Dong     N/A          EAS470_CanTp_20240801_01
********************************************************************************
* END_FILE_HDR*/

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 5087,3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "EcuM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in EcuM_MemMap.h
*/

/*PRQA S 3453,3429 EOF*/
/*
1.The unified requirement of EAS is that the error reporting functions of Det
and Dem moduls are accessed by macro functions.This part has been verified and
has no problem.
2.Macro functions are allowed to use to access parameters and do some simple operations.
*/

/*PRQA S 3432,3410,3409 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no
need to revise.
*/

/*PRQA S 3673,4603 EOF*/
/*
Parameters in AUTOSAR standard APIs,they may not follow this rule.
*/

/*PRQA S 3212 EOF*/
/*
Unified requirements of EAS: constant shall be converted.
*/

/*PRQA S 3119 EOF*/
/*
No unified input parameter processing is used
*/

/*PRQA S 3197 EOF*/
/*
Redundant initialization will not cause functional problems,there is no need to
revise.And it is the requirement of programming specification to initialize
local variables.
*/

/*PRQA S 3138,3141 EOF*/
/*
The code of critical segments can be configured as void when QAC testing.
Note:When called by Det,Dem or BswM, the critical segments must be enabled when
QAC testing.Reasons are needed for special circumstances not enabled.
*/

/*PRQA S 3416 EOF*/
/*
In a If statement,calling a function to directly determine the return value is 
allowed if there is only one judge branch.
*/

/*PRQA S 0857,0380 EOF*/
/*
Macro definitions exceed 1024. The number of macros is unlimited
*/

/*****************************************************************************
 *  CanTp QAC Suppression
 *****************************************************************************/

/*PRQA S 3227,3204 EOF*/
/*
Read-only function input parameters may not be defined as const,it does not affect the function.
AUTOSAR API shall define standard input parameters according to specification requirements
*/

/*PRQA S 3435,3456 EOF*/
/*
Functional based implementation.
*/

/*PRQA S 2100,2101 EOF*/
/*
Integer promotion related.
*/

/*PRQA S 2000 EOF*/
/*
When there is only one If,there can be no else..
*/

/*PRQA S 2741,2742 EOF*/
/*
Particularity of configuration files.
*/

/*PRQA S 3892 EOF*/
/*
Specific implementation methods.
*/

/*PRQA S 3383 EOF*/
/*
Addition and subtraction operations on internal variables of CanTp doesn't overflow.
*/
/*PRQA S 3344 ++*/
/*
Specific implementation methods.
*/
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanTp.h"
#include "CanIf.h"
#include "PduR.h"
#if(STD_ON == CANTP_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#include "SchM_CanTp.h"
#include "Bsw_Common.h"

/*******************************************************************************
*   QAC Suppression
*******************************************************************************/
/*PRQA S 0277,3393,0488,0489,1504,3450,3201,3206,3197,3325,3356,3359,3112 EOF*/

/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(STD_ON == CANTP_VERSION_CHECK)
/* check Version with other import module */
/* check Version with cfg file */
#if((CANTP_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) && \
    (CANTP_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD))
#error "The CanTp module only supports Pre-Compile and Post-Build Configuration."
#endif

/* check Version with cfg file */
#if((CANTP_AR_RELEASE_MAJOR_VERSION != CANTP_AR_RELEASE_MAJOR_VERSION_CFG) || \
    (CANTP_AR_RELEASE_MINOR_VERSION != CANTP_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of CanTp and its cfg file are different"
#endif

#if((CANTP_SW_MAJOR_VERSION != CANTP_SW_MAJOR_VERSION_CFG) || \
       (CANTP_SW_MINOR_VERSION != CANTP_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of CanTp and its cfg file are different"
#endif


#endif/*#if(STD_ON == CANTP_VERSION_CHECK)*/

/*Cfg compatibility check*/

#if(0 == CANTP_MAX_CHANNEL_NUM)
#error "The CANTP_MAX_CHANNEL_NUM should not be 0"
#endif



/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == CANTP_DEV_ERROR_DETECT)
#define  CANTP_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(CANTP_MODULE_ID, CANTP_INSTANCE_ID, ((uint8)ApiId), ((uint8)errcode))
#else
#define  CANTP_DET_REPORT_ERROR(ApiId, errcode)
#endif

#define CANTP_STMINABSOLUTEMASK               ((uint8)(0x80))
#define CANTP_STMINRELATIVEMIN                ((uint8)(0xF1))
#define CANTP_STMINRELATIVEMAX                ((uint8)(0xF9))

/*******************************************************************************
*   Macros
*******************************************************************************/

/* Internal and iso 15765-2 compliant */
/* CanTp_FrameType */
#define CANTP_SF                   ((uint8)0x00)
#define CANTP_FF                   ((uint8)0x10)
#define CANTP_CF                   ((uint8)0x20)
#define CANTP_FC                   ((uint8)0x30)
#define CANTP_FC_FS_CTS            ((uint8)0x00)
#define CANTP_FC_FS_WT             ((uint8)0x01)
#define CANTP_FC_FS_OVFLW          ((uint8)0x02)

/* Masks for frame parsing */
#define CANTP_DLMASK_SF            ((uint8)0x0F)
#define CANTP_DLMASK_FF            ((uint8)0x0F)
#define CANTP_FTMASK               ((uint8)0xF0)
#define CANTP_FSMASK               ((uint8)0x0F)
#define CANTP_SNMASK               ((uint8)0x0F)
#define CANTP_MAXSNNUM             ((uint8)0x0F)
/* Start value for sequence number counter*/
#define CANTP_SN_INITVAL           ((uint8)0x01)
#if(STD_ON == CANTP_TX_NAI_ADDRESSING)
#define CANTP_EXTMIX_OFFSET        ((PduLengthType)0)
#endif
#define CANTP_FC_DATALEN           ((PduLengthType)3)

/* common length values */
#define CANTP_CAN20_FRAME_LENGTH   ((PduLengthType)8)         /* CAN 2.0 frame length */
#define CANTP_CANFD_MAX_LENGTH     ((PduLengthType)64)        /* CAN FD frame max length */
#define CANTP_FF_DL_12BIT          ((PduLengthType)4095)      /* max message length for FF with 12Bit DL */

#define CANTP_INDEX_1              ((PduLengthType)1)
#define CANTP_INDEX_2              ((PduLengthType)2)
#define CANTP_INDEX_3              ((PduLengthType)3)
#define CANTP_INDEX_4              ((PduLengthType)4)
#define CANTP_INDEX_5              ((PduLengthType)5)
#define CANTP_INDEX_6              ((PduLengthType)6)
#define CANTP_INDEX_7              ((PduLengthType)7)
#define CANTP_INDEX_8              ((uint8)8)
#define CANTP_INDEX_9              ((uint8)9)
#define CANTP_INDEX_16             ((uint8)16)
#define CANTP_INDEX_24             ((uint8)24)


/*******************************************************************************
*   Transport protocol global status codes
*******************************************************************************/
/* CanTp_RxStateType */
/* Rx Idle state must be zero due to optimization */
#define CANTP_RXSTATE_IDLE                       ((uint8)0x00)
#define CANTP_RXSTATE_WAITBUFF_NEXTBLOCK         ((uint8)0x08)
#define CANTP_RXSTATE_TXFC                       ((uint8)0x0a)
#define CANTP_RXSTATE_WAITFCCONF                 ((uint8)0x0b)
#define CANTP_RXSTATE_WAITCF                     ((uint8)0x0c)


/* CanTp_TxStateType */
/* Tx Idle state must be zero due to optimization */
#define CANTP_TXSTATE_IDLE                          ((uint8)0x00)
#define CANTP_TXSTATE_WAITFC                        ((uint8)0x01)
#define CANTP_TXSTATE_WAITTXCF                      ((uint8)0x02)
#define CANTP_TXSTATE_TXSTART                       ((uint8)0x04)
#define CANTP_TXSTATE_RECOPY                        ((uint8)0x08)
#define CANTP_TXSTATE_WAITLASTCONF                  ((uint8)0x10)
#define CANTP_TXSTATE_WAITFFCONF                    ((uint8)0x20)
#define CANTP_TXSTATE_WAITCFCONF                    ((uint8)0x30)

/*******************************************************************************
*   TP ISO NPCI offsets
*******************************************************************************/
#if(CANTP_RX_NAI_ADDRESSING == STD_ON)
#define CANTP_RX_NPCI_OFFSET(RxSduId)               (CANTP_RXNSDUINFO(RxSduId).CanTpNPciOffset)
#else
#define CANTP_RX_NPCI_OFFSET(RxSduId)               ((PduLengthType)0)
#endif

#if(CANTP_TX_NAI_ADDRESSING == STD_ON)
#define CANTP_TX_NPCI_OFFSET(TxSduId)               (CANTP_TXNSDUINFO(TxSduId).CanTpNPciOffset)
#else
#define CANTP_TX_NPCI_OFFSET(TxSduId)               ((PduLengthType)0)
#endif

/*******************************************************************************
* CanTp_RxNsduCfgInfo
*******************************************************************************/
#define CANTP_RXTPCHANNEL_ID(RxSduId)        (CANTP_RXNSDUINFO(RxSduId).CanTpChannelId)
#define CANTP_RXNPDU_ID(RxSduId)             (CANTP_RXNSDUINFO(RxSduId).CanTpRxNPduId)
#define CANTP_UPPDU_ID(RxSduId)              (CANTP_RXNSDUINFO(RxSduId).UpperLayerPduId)
#define CANTP_TXFC_NPDU_ID(RxSduId)          (CANTP_RXNSDUINFO(RxSduId).CanTpTxFcNPduId)
#define CANTP_NAR(RxSduId)                   ((uint16)(CANTP_RXNSDUINFO(RxSduId).CanTpNar))
#define CANTP_NBR(RxSduId)                   ((uint16)(CANTP_RXNSDUINFO(RxSduId).CanTpNbr))
#define CANTP_NCR(RxSduId)                   ((uint16)(CANTP_RXNSDUINFO(RxSduId).CanTpNcr))
#define CANTP_WFTMAX(RxSduId)                (CANTP_RXNSDUINFO(RxSduId).CanTpRxWftMax)
#define CANTP_RX_MAXCANLEN(RxSduId)          (CANTP_RXNSDUINFO(RxSduId).MaxCanLen)

#if(STD_ON == CANTP_CHANGE_PARAMETER_API)
#define CANTP_BS(RxSduId)                    (CanTp_ParamInfo[RxSduId].CanTpBs)
#define CANTP_STMIN(RxSduId)                 (CanTp_ParamInfo[RxSduId].CanTpSTmin)
#else
#define CANTP_BS(RxSduId)                    (CANTP_RXNSDUINFO(RxSduId).CanTpBs)
#define CANTP_STMIN(RxSduId)                 (CANTP_RXNSDUINFO(RxSduId).CanTpSTmin)
#endif

#define CANTP_RX_TA_TYPE(RxSduId)            (CANTP_RXNSDUINFO(RxSduId).CanTpRxTaType)
#if(CANTP_RX_NAI_ADDRESSING == STD_ON)
#define CANTP_RX_ADDRFORM(RxSduId)           (CANTP_RXNSDUINFO(RxSduId).CanTpRxAddrFormat)
#define CANTP_RX_NAE(RxSduId)                (CANTP_RXNSDUINFO(RxSduId).CanTpRxNAe)
#define CANTP_RX_NSA(RxSduId)                (CANTP_RXNSDUINFO(RxSduId).CanTpRxNSa)
#define CANTP_RX_NTA(RxSduId)                (CANTP_RXNSDUINFO(RxSduId).CanTpRxNTa)
#endif
/*******************************************************************************
* CanTp_TxNsduCfgInfo
*******************************************************************************/
#define CANTP_TXTPCHANNEL_ID(TxSduId)        (CANTP_TXNSDUINFO(TxSduId).CanTpChannelId)
#define CANTP_TXNPDU_ID(TxSduId)             (CANTP_TXNSDUINFO(TxSduId).CanTpTxNPduId)
#define CANTP_RXFC_NPDU_ID(TxSduId)          (CANTP_TXNSDUINFO(TxSduId).CanTpRxFcNPduId)
#define CANTP_CONFPDU_ID(TxSduId)            (CANTP_TXNSDUINFO(TxSduId).UpperLayerPduId)
#define CANTP_TX_MAXCANLEN(TxSduId)          (CANTP_TXNSDUINFO(TxSduId).MaxCanLen)
#define CANTP_NAS(TxSduId)                   ((uint16)(CANTP_TXNSDUINFO(TxSduId).CanTpNas))
#define CANTP_NBS(TxSduId)                   ((uint16)(CANTP_TXNSDUINFO(TxSduId).CanTpNbs))
#define CANTP_NCS(TxSduId)                   ((uint16)(CANTP_TXNSDUINFO(TxSduId).CanTpNcs))

#define CANTP_TX_TA_TYPE(TxSduId)            (CANTP_TXNSDUINFO(TxSduId).CanTpTxTaType)
#if(CANTP_TX_NAI_ADDRESSING == STD_ON)
#define CANTP_TX_ADDRFORM(TxSduId)           (CANTP_TXNSDUINFO(TxSduId).CanTpTxAddrFormat)
#define CANTP_TX_NAE(TxSduId)                (CANTP_TXNSDUINFO(TxSduId).CanTpTxNAe)
#define CANTP_TX_NSA(TxSduId)                (CANTP_TXNSDUINFO(TxSduId).CanTpTxNSa)
#define CANTP_TX_NTA(TxSduId)                (CANTP_TXNSDUINFO(TxSduId).CanTpTxNTa)
#endif

#if(CANTP_RXSDU_PADDING_MODE == CANTP_SDU_PADDING_VARIES)
#define CANTP_IS_RXSDU_PADDING_ENABLE(RxSduId)   (TRUE == CANTP_RXNSDUINFO(RxSduId).CanTpRxPaddingActive)
#else
#define CANTP_IS_RXSDU_PADDING_ENABLE(RxSduId)   (CANTP_RXSDU_PADDING_MODE == CANTP_RXSDU_PADDING_ENABLED)
#endif


#if(CANTP_TXSDU_PADDING_MODE == CANTP_SDU_PADDING_VARIES)
#define CANTP_IS_TXSDU_PADDING_ENABLE(TxSduId)   (TRUE == CANTP_TXNSDUINFO(TxSduId).CanTpTxPaddingActive)
#else
#define CANTP_IS_TXSDU_PADDING_ENABLE(TxSduId)   (CANTP_TXSDU_PADDING_MODE == CANTP_TXSDU_PADDING_ENABLED)
#endif

/*******************************************************************************
* CanTp_RxState
*******************************************************************************/
#define CANTP_RX_CHANNEL_STATE(ChannelId)        (CanTp_RxState[ChannelId].ChannelState)
#define CANTP_RX_CHANNEL_CURID(ChannelId)        (CanTp_RxState[ChannelId].CurrentRxSduId)
#define CANTP_RX_CHANNEL_DATALEN(ChannelId)      (CanTp_RxState[ChannelId].DataLength)
#define CANTP_RX_CHANNEL_NEXTBLKLEN(ChannelId)   (CanTp_RxState[ChannelId].NextBlockLen)
#define CANTP_RX_CHANNEL_FS(ChannelId)           (CanTp_RxState[ChannelId].FlowStatus)
#define CANTP_RX_CHANNEL_TIMER(ChannelId)        (CanTp_RxState[ChannelId].Timer)
#define CANTP_RX_CHANNEL_IS_TIMER_EXP(ChannelId) ((uint16)0 == CanTp_RxState[ChannelId].Timer)
#define CANTP_RX_CHANNEL_WFTCNT(ChannelId)       (CanTp_RxState[ChannelId].WFTCounter)
#define CANTP_RX_CHANNEL_BSCNT(ChannelId)        (CanTp_RxState[ChannelId].BlockSizeCounter)
#define CANTP_RX_CHANNEL_NEXTSN(ChannelId)       (CanTp_RxState[ChannelId].ExpectedSN)
#define CANTP_RX_CHANNEL_FFDLC(ChannelId)        (CanTp_RxState[ChannelId].FFCanDlc)

/*******************************************************************************
* CanTp_TxState
*******************************************************************************/
#define CANTP_TX_CHANNEL_STATE(ChannelId)        (CanTp_TxState[ChannelId].ChannelState)
#define CANTP_TX_CHANNEL_CURID(ChannelId)        (CanTp_TxState[ChannelId].CurrentTxNSduId)
#define CANTP_TX_CHANNEL_DATALEN(ChannelId)      (CanTp_TxState[ChannelId].DataLength)
#define CANTP_TX_CHANNEL_SEQNUM(ChannelId)       (CanTp_TxState[ChannelId].SeqNumber)
#define CANTP_TX_CHANNEL_BSCNT(ChannelId)        (CanTp_TxState[ChannelId].BlockSizeCounter)
#define CANTP_TX_CHANNEL_STMIN(ChannelId)        (CanTp_TxState[ChannelId].STMin)
#define CANTP_TX_CHANNEL_TIMER(ChannelId)        (CanTp_TxState[ChannelId].Timer)
#define CANTP_TX_CHANNEL_IS_TIMER_EXP(ChannelId) ((uint16)0 == CanTp_TxState[ChannelId].Timer)
#if(CANTP_CAR_PLATFORM == CANTP_NISSAN_PLATFORM)
#define CANTP_TX_CHANNEL_INITIAL_FC_FLAG(ChannelId) (CanTp_TxState[ChannelId].FirstFCFlag)
#define CANTP_TX_CHANNEL_FIX_BSCNT(ChannelId)     (CanTp_TxState[ChannelId].FixedBlockSize)
#endif

/*******************************************************************************
* CanTp_ChannelModeInfo
*******************************************************************************/

/*PRQA S 3608 ++*/
/*
Allows #elif is being used.
*/
#if(CANTP_DUPLEX_MODE == CANTP_CHANNEL_DUPLEX_VARIES)
#define CANTP_IS_DUPLEX_FULL(ChannelId)        (CANTP_CHANNEL_MODE(ChannelId) == CANTP_MODE_FULL_DUPLEX) 
#elif(CANTP_DUPLEX_MODE == CANTP_CHANNEL_FULL_DUPLEX_ONLY)
#define CANTP_IS_DUPLEX_FULL(ChannelId)        (TRUE)
#else
#define CANTP_IS_DUPLEX_FULL(ChannelId)        (FALSE)
#endif
/*PRQA S 3608 --*/
#if(STD_ON == CANTP_MULTI_CORE_SUPPORT)
#define CANTP_CHANNEL_CORE_INFO(ChannelId)           (CanTp_ChannelCoreInfo[ChannelId])
#endif
/*Initialization status*/
#define CANTP_IS_INITIALIZED()                       (CANTP_ON == CanTp_InitStatus)
#define CANTP_SET_INITIALIZED()                      (CanTp_InitStatus = CANTP_ON)
#define CANTP_SET_UNINITIALIZED()                    (CanTp_InitStatus = CANTP_OFF)


/* -----------------------------------------------------------------------------
  Gloable Data definitions
 ----------------------------------------------------------------------------- */
#define CANTP_START_SEC_VAR_INIT_GLOBAL_8
#include "CanTp_MemMap.h"

/*SWS_CanTp_00253 SWS_CanTp_00168*/
STATIC VAR(CanTp_InitStatusType, CANTP_VAR) CanTp_InitStatus = CANTP_OFF;

#define CANTP_STOP_SEC_VAR_INIT_GLOBAL_8
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "CanTp_MemMap.h"
#if(CANTP_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
STATIC P2CONST(CanTp_ConfigType, CANTP_VAR_NOINIT, CANTP_CONST) CanTp_ConfigSet;
#endif
#define CANTP_STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "CanTp_MemMap.h"
/* Channel-, connection-state data */
STATIC VAR(CanTp_RxStateType, CANTP_VAR) CanTp_RxState[CANTP_MAX_CHANNEL_NUM];
STATIC VAR(CanTp_TxStateType, CANTP_VAR) CanTp_TxState[CANTP_MAX_CHANNEL_NUM];
#if(STD_ON == CANTP_CHANGE_PARAMETER_API)
STATIC CanTp_ChangeParType CanTp_ParamInfo[CANTP_MAX_NUM_RX_SDUS];
#endif
#define CANTP_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "CanTp_MemMap.h"

/*******************************************************************************
*   Local Functions define
*******************************************************************************/
#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"

STATIC FUNC(void, CANTP_CODE) CanTp_RxChannelInit
(
    CanTp_ChannelIdType ChannelId
);

STATIC FUNC(void, CANTP_CODE) CanTp_TxChannelInit
(
    CanTp_ChannelIdType ChannelId
);

STATIC FUNC(void, CANTP_CODE) CanTp_TransmitFC
(
    CanTp_ChannelIdType ChannelId
);

STATIC FUNC(void, CANTP_CODE) CanTp_TxSduCreatePCI
(
    PduIdType TxSduId,
    CanTp_ChannelIdType ChannelId,
    CONSTP2VAR(uint8, AUTOMATIC, CANTP_CONST) TpBuff,
    uint8 FrameType
);

STATIC FUNC(void, CANTP_CODE) CanTp_StartTransmit
(
    CanTp_ChannelIdType ChannelId
);

STATIC FUNC(void, CANTP_CODE) CanTp_CFTransmit
(
    CanTp_ChannelIdType ChannelId
);

STATIC FUNC(void, CANTP_CODE) CanTp_GetNextBlockLen
(
    CanTp_ChannelIdType ChannelId
);

STATIC FUNC(void, CANTP_CODE) CanTp_RxMainFunction
(
    CanTp_ChannelIdType ChannelId
);

STATIC FUNC(void, CANTP_CODE) CanTp_TxMainFunction
(
    CanTp_ChannelIdType ChannelId
);

STATIC FUNC(Std_ReturnType, CANTP_CODE) CanTp_RxChannelCheck
(
    CanTp_ChannelIdType ChannelId
);

STATIC FUNC(Std_ReturnType, CANTP_CODE) CanTp_TxChannelCheck
(
    CanTp_ChannelIdType ChannelId
);

STATIC FUNC(Std_ReturnType, CANTP_CODE) CanTp_GetSFValidData
(
    PduIdType RxSduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr,
    P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) APduInfoPtr
);

STATIC FUNC(Std_ReturnType, CANTP_CODE) CanTp_GetFFValidData
(
    PduIdType RxSduId,
    CanTp_ChannelIdType ChannelId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr,
    P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) APduInfoPtr,
    PduLengthType *MFLen
);

STATIC FUNC(Std_ReturnType, CANTP_CODE) CanTp_GetCFValidData
(
    CanTp_ChannelIdType ChannelId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr,
    P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) APduInfoPtr
);

STATIC FUNC(Std_ReturnType, CANTP_CODE) CanTp_GetFCValidData
(
    CanTp_ChannelIdType ChannelId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, CANTP_APPL_DATA) FrameLen
);

STATIC FUNC(void, CANTP_CODE) CanTp_RxSFPdu
(
    PduIdType RxSduId,
    CanTp_ChannelIdType ChannelId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr
);

STATIC FUNC(void, CANTP_CODE) CanTp_RxFFPdu
(
    PduIdType RxSduId,
    CanTp_ChannelIdType ChannelId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr
);

STATIC FUNC(void, CANTP_CODE) CanTp_RxCFPdu
(
    PduIdType RxSduId,
    CanTp_ChannelIdType ChannelId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr
);

STATIC FUNC(void, CANTP_CODE) CanTp_RxFCPdu
(
    CanTp_ChannelIdType ChannelId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr
);

STATIC FUNC(void, CANTP_CODE) CanTp_TxStateChangedAfterTxConfirm
(
    CanTp_ChannelIdType ChannelId,
    PduIdType TxSduId
);

STATIC FUNC(void, CANTP_CODE) CanTp_RxStateChangedAfterTxConfirm
(
    CanTp_ChannelIdType ChannelId,
    PduIdType RxSduId
);
STATIC FUNC(void, CANTP_CODE) CanTp_CheckTxNsdu
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr
);
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_RxChannelInit

* Description  : This function initializes the CanTp module
*
* Inputs       : tpChannelType: Tx or Rx Tp Channel,range:CANTP_RX_CHANNEL and
*                               CANTP_TX_CHANNEL.
*                tpChannel    : The init Tp Channel number.

* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANTP_CODE) CanTp_RxChannelInit
(
    CanTp_ChannelIdType ChannelId
)
{
    CANTP_RX_CHANNEL_CURID(ChannelId) = COMSTACK_INVALID_PDUID;
    /* activation status */
    CANTP_RX_CHANNEL_TIMER(ChannelId) = (uint16)0;
    CANTP_RX_CHANNEL_STATE(ChannelId) = CANTP_RXSTATE_IDLE;
    /* Lengths */
    CANTP_RX_CHANNEL_DATALEN(ChannelId) = (PduLengthType)0;
    CANTP_RX_CHANNEL_NEXTBLKLEN(ChannelId) = (PduLengthType)0;
    CANTP_RX_CHANNEL_FFDLC(ChannelId) = (PduLengthType)0;
    /* buffer admin */
    CANTP_RX_CHANNEL_WFTCNT(ChannelId) = (uint8)0;
    /* actual values */
    CANTP_RX_CHANNEL_BSCNT(ChannelId) = (uint8)0;
    /* Bittypes */
    CANTP_RX_CHANNEL_NEXTSN(ChannelId) = (uint8)0;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_TxChannelInit

* Description  : This function initializes the CanTp module
*
* Inputs       : tpChannelType: Tx or Rx Tp Channel,range:CANTP_RX_CHANNEL and
*                               CANTP_TX_CHANNEL.
*                tpChannel    : The init Tp Channel number.

* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANTP_CODE) CanTp_TxChannelInit
(
    CanTp_ChannelIdType ChannelId
)
{
    CANTP_TX_CHANNEL_CURID(ChannelId) = COMSTACK_INVALID_PDUID;

    /* activation status */
    CANTP_TX_CHANNEL_TIMER(ChannelId) = (uint16)0;
    CANTP_TX_CHANNEL_STATE(ChannelId) = CANTP_TXSTATE_IDLE;
    /* Lengths */
    CANTP_TX_CHANNEL_DATALEN(ChannelId) = (PduLengthType)0;
    /* actual values */
    CANTP_TX_CHANNEL_BSCNT(ChannelId) = (uint8)0;
    CANTP_TX_CHANNEL_STMIN(ChannelId) = (uint8)0;
    /* Bittypes */
    CANTP_TX_CHANNEL_SEQNUM(ChannelId) = CANTP_SN_INITVAL;
#if(CANTP_CAR_PLATFORM == CANTP_NISSAN_PLATFORM)
    CANTP_TX_CHANNEL_INITIAL_FC_FLAG(ChannelId) = TRUE;
    CANTP_TX_CHANNEL_FIX_BSCNT(ChannelId) = (uint8)0;
#endif
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_TransmitFC

* Description  : After receiving FF , this function is called to assemble FC .

* Inputs       : CanTpRxChannelId,FlowStatus
*
* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANTP_CODE) CanTp_TransmitFC
(
    CanTp_ChannelIdType ChannelId
)
{
    PduIdType RxSduId = CANTP_RX_CHANNEL_CURID(ChannelId);
    uint8 CanTp_TxBuff[CANTP_MAX_FRAME_LENGTH];
    PduInfoType TxFCPduInfo;
    Std_ReturnType ret;
    PduLengthType NpciOffset = CANTP_RX_NPCI_OFFSET(RxSduId);

#if(CANTP_RX_NAI_ADDRESSING == STD_ON)
    if(CANTP_EXTENDED == CANTP_RX_ADDRFORM(RxSduId))
    {
        CanTp_TxBuff[CANTP_EXTMIX_OFFSET] = CANTP_RX_NSA(RxSduId);
    }
    else
    {
        /*MIXED or MIXED29BIT*/
        CanTp_TxBuff[CANTP_EXTMIX_OFFSET] = CANTP_RX_NAE(RxSduId);
    }
#endif

    /*SWS_CanTp_00067*/
    CanTp_TxBuff[NpciOffset] = (uint8)(CANTP_FC | CANTP_RX_CHANNEL_FS(ChannelId));
    CanTp_TxBuff[NpciOffset + CANTP_INDEX_1] = CANTP_BS(RxSduId);
    CanTp_TxBuff[NpciOffset + CANTP_INDEX_2] = CANTP_STMIN(RxSduId);

    TxFCPduInfo.SduDataPtr = (SduDataPtrType)CanTp_TxBuff;

    if(CANTP_IS_RXSDU_PADDING_ENABLE(RxSduId))
    {
        /*SWS_CanTp_00347 SWS_CanTp_00059*/
        Bsw_MemSet(&(CanTp_TxBuff[NpciOffset + CANTP_INDEX_3]), CANTP_PADDING_BYTE, (uint32)(CANTP_CAN20_FRAME_LENGTH - CANTP_RX_NPCI_OFFSET(RxSduId) - CANTP_INDEX_3));
        TxFCPduInfo.SduLength = CANTP_CAN20_FRAME_LENGTH;
    }
    else
    {
        TxFCPduInfo.SduLength = NpciOffset + CANTP_INDEX_3;
    }

    CANTP_RX_CHANNEL_STATE(ChannelId) = CANTP_RXSTATE_WAITFCCONF;
    CANTP_RX_CHANNEL_TIMER(ChannelId) = CANTP_NAR(RxSduId);

    /*SWS_CanTp_00342*/
    ret = CanIf_Transmit(CANTP_TXFC_NPDU_ID(RxSduId), &TxFCPduInfo);

    if(E_OK != ret)
    {
        CanTp_RxChannelInit(ChannelId);
        (void)PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_NOT_OK);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_TxSduCreatePCI

* Description  : This function is called by CanTp_MainFunction to handle N_As,
*                N_Bs and N_Cs.

* Inputs       : CanTpTxChannelId: Channel number of the Transimmit TpChannel.
*
* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANTP_CODE) CanTp_TxSduCreatePCI
(
    PduIdType TxSduId,
    CanTp_ChannelIdType ChannelId,
    CONSTP2VAR(uint8, AUTOMATIC, CANTP_CONST) TpBuff,
    uint8 FrameType
)
{
    uint8 Seq;

#if(CANTP_TX_NAI_ADDRESSING == STD_ON)
    if(CANTP_EXTENDED == CANTP_TX_ADDRFORM(TxSduId))
    {
        TpBuff[CANTP_EXTMIX_OFFSET] = CANTP_TX_NTA(TxSduId); /*Extended Address*/
    }
    else
    {
        /*MIXED or MIXED29BIT*/
        TpBuff[CANTP_EXTMIX_OFFSET] = CANTP_TX_NAE(TxSduId); /*AE Address */
    }

#endif

    if(CANTP_SF == FrameType)
    {
#if(STD_ON == CANTP_CANFD_SUPPORT)
        if((CANTP_TX_CHANNEL_DATALEN(ChannelId) + CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_1) > CANTP_CAN20_FRAME_LENGTH)
        {
            /*CANFD*/
            TpBuff[CANTP_TX_NPCI_OFFSET(TxSduId)] = (uint8)0;
            TpBuff[CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_1] = (uint8)(CANTP_TX_CHANNEL_DATALEN(ChannelId));
        }
        else
#endif
        {
            /*CANFD & CAN2.0*/
            TpBuff[CANTP_TX_NPCI_OFFSET(TxSduId)] = (uint8)(CANTP_TX_CHANNEL_DATALEN(ChannelId));
        }
    }
    else if(CANTP_FF == FrameType)
    {
#if(STD_ON == CANTP_LONGFF_SUPPORT)

        if(CANTP_TX_CHANNEL_DATALEN(ChannelId) > CANTP_FF_DL_12BIT)
        {
            TpBuff[CANTP_TX_NPCI_OFFSET(TxSduId)] = CANTP_FF;
            TpBuff[CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_1] = (uint8)0;
            TpBuff[CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_5] = (uint8)(CANTP_TX_CHANNEL_DATALEN(ChannelId));
            TpBuff[CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_4] = (uint8)((CANTP_TX_CHANNEL_DATALEN(ChannelId)) >> CANTP_INDEX_8);
            TpBuff[CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_3] = (uint8)((CANTP_TX_CHANNEL_DATALEN(ChannelId)) >> CANTP_INDEX_16);
            TpBuff[CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_2] = (uint8)((CANTP_TX_CHANNEL_DATALEN(ChannelId)) >> CANTP_INDEX_24);
        }
        else
#endif
        {
            TpBuff[CANTP_TX_NPCI_OFFSET(TxSduId)] = (CANTP_FF) | ((uint8)((CANTP_TX_CHANNEL_DATALEN(ChannelId)) >> CANTP_INDEX_8));
            TpBuff[CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_1] = (uint8)(CANTP_TX_CHANNEL_DATALEN(ChannelId));
        }
    }
    else if(CANTP_CF == FrameType)
    {
        Seq = CANTP_TX_CHANNEL_SEQNUM(ChannelId);
        TpBuff[CANTP_TX_NPCI_OFFSET(TxSduId)] = (CANTP_CF) | Seq;

        if(Seq == CANTP_MAXSNNUM)
        {
            CANTP_TX_CHANNEL_SEQNUM(ChannelId) = (uint8)0;
        }
        else
        {
            CANTP_TX_CHANNEL_SEQNUM(ChannelId) += (uint8)1;
        }
    }
    else
    {
        /*do nothing*/
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_StartTransmit

* Description  : This function is called by CanTp_MainFunction to handle N_As,
*                N_Bs and N_Cs.

* Inputs       : CanTpTxChannelId: Channel number of the Transimmit TpChannel.
*
* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANTP_CODE) CanTp_StartTransmit
(
    CanTp_ChannelIdType ChannelId
)
{
    BufReq_ReturnType Result;
    Std_ReturnType ret = E_NOT_OK;
    PduInfoType CanTpTxNPduInfo;
    uint8 FrameType;
    uint8 PaddingLen;
    uint8 CanTp_TxBuff[CANTP_MAX_FRAME_LENGTH];
    PduIdType TxSduId = CANTP_TX_CHANNEL_CURID(ChannelId);
    PduInfoType TxNPduInfo;
    PduLengthType SFMaxLen;
    PduLengthType RemainTxDataCnt = (PduLengthType)0;
#if(STD_ON == CANTP_CANFD_SUPPORT)
    uint8 NextPossibleDlc = (uint8)0;
#endif

    if((CANTP_IS_DUPLEX_FULL(ChannelId)) && (CANTP_RX_CHANNEL_STATE(ChannelId) == CANTP_RXSTATE_WAITFCCONF))
    {
        /*Retry next mainfunction*/
        CANTP_TX_CHANNEL_STATE(ChannelId) |= CANTP_TXSTATE_RECOPY;
    }
    else
    {
#if(STD_ON == CANTP_CANFD_SUPPORT)
        if(CANTP_TX_MAXCANLEN(TxSduId) > CANTP_CAN20_FRAME_LENGTH)
        {
            /*CANFD*/
            SFMaxLen = CANTP_TX_MAXCANLEN(TxSduId) - CANTP_TX_NPCI_OFFSET(TxSduId) - CANTP_INDEX_2;
        }
        else
#endif
        {
            /*CAN2.0*/
            SFMaxLen = CANTP_TX_MAXCANLEN(TxSduId) - CANTP_TX_NPCI_OFFSET(TxSduId) - CANTP_INDEX_1;
        }

        if(CANTP_TX_CHANNEL_DATALEN(ChannelId) <= SFMaxLen)
        {
            /*SingleFrame*/
            /*SWS_CanTp_00231*/
            FrameType = CANTP_SF;
#if(STD_ON == CANTP_CANFD_SUPPORT)
            if((CANTP_TX_CHANNEL_DATALEN(ChannelId) + CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_1) > CANTP_CAN20_FRAME_LENGTH)
            {
                /*CANFD*/
                CanTpTxNPduInfo.SduDataPtr = (SduDataPtrType)&(CanTp_TxBuff[CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_2]);
                CanTpTxNPduInfo.SduLength = CANTP_TX_CHANNEL_DATALEN(ChannelId);
            }
            else
#endif
            {
                /*CAN2.0 or CANFD*/
                CanTpTxNPduInfo.SduDataPtr = (SduDataPtrType)&(CanTp_TxBuff[CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_1]);
                CanTpTxNPduInfo.SduLength = CANTP_TX_CHANNEL_DATALEN(ChannelId);
            }
        }
        else
        {
            /*SWS_CanTp_00232*/
            /*CANFD & CAN2.0*/
            FrameType = CANTP_FF;
#if(STD_ON == CANTP_LONGFF_SUPPORT)
            if(CANTP_TX_CHANNEL_DATALEN(ChannelId) > CANTP_FF_DL_12BIT)
            {
                CanTpTxNPduInfo.SduDataPtr = &(CanTp_TxBuff[CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_6]);
                CanTpTxNPduInfo.SduLength = CANTP_TX_MAXCANLEN(TxSduId) - CANTP_TX_NPCI_OFFSET(TxSduId) - (PduLengthType)6;
            }
            else
#endif
            {
                CanTpTxNPduInfo.SduDataPtr = (SduDataPtrType)&(CanTp_TxBuff[CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_2]);
                CanTpTxNPduInfo.SduLength = CANTP_TX_MAXCANLEN(TxSduId) - CANTP_TX_NPCI_OFFSET(TxSduId) - CANTP_INDEX_2;
            }
        }

        /*SWS_CanTp_00086 CANTP226 SWS_CanTp_00272 SWS_CanTp_00298 SWS_CanTp_00299*/
        Result = PduR_LoTpCopyTxData(CANTP_CONFPDU_ID(TxSduId), &CanTpTxNPduInfo, NULL_PTR, &RemainTxDataCnt);

        if(BUFREQ_E_BUSY == Result)
        {
            /*SWS_CanTp_00184*/
            CANTP_TX_CHANNEL_STATE(ChannelId) |= CANTP_TXSTATE_RECOPY;
        }
        else if(BUFREQ_E_NOT_OK == Result)
        {
            /*SWS_CanTp_00087 SWS_CanTp_00177*/
            CanTp_TxChannelInit(ChannelId);
            PduR_LoTpTxConfirmation(CANTP_CONFPDU_ID(TxSduId), E_NOT_OK);
        }
        else/*BUFREQ_E_OK*/
        {
            CanTp_TxSduCreatePCI(TxSduId, ChannelId, CanTp_TxBuff, FrameType);

            if(FrameType == CANTP_SF)
            {
                CANTP_TX_CHANNEL_STATE(ChannelId) = CANTP_TXSTATE_WAITLASTCONF;

                /*SWS_CanTp_00348*/
                if((CANTP_TX_CHANNEL_DATALEN(ChannelId) + CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_1) <= CANTP_CAN20_FRAME_LENGTH)
                {
                    if(CANTP_IS_TXSDU_PADDING_ENABLE(TxSduId))
                    {
                        TxNPduInfo.SduLength = CANTP_CAN20_FRAME_LENGTH;
                        PaddingLen = (uint8)(CANTP_CAN20_FRAME_LENGTH - (CANTP_TX_CHANNEL_DATALEN(ChannelId) + CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_1));
                        /*SWS_CanTp_00059*/
                        /* MISRA RULE 12.1 violated:
                        operator + and - are with the same precedence, calculate from left to right..*/
                        if(PaddingLen > (uint8)0)
                        {
                            Bsw_MemSet(&(CanTp_TxBuff[CANTP_CAN20_FRAME_LENGTH - PaddingLen]), CANTP_PADDING_BYTE, (uint32)PaddingLen);
                        }
                    }
                    else
                    {
                        TxNPduInfo.SduLength = CANTP_TX_CHANNEL_DATALEN(ChannelId) + CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_1;
                    }
                }
#if(STD_ON == CANTP_CANFD_SUPPORT)
                else
                {
                    /*SWS_CanTp_00351 Sending DLC must be 0..8, 12, 16, 20, 24, 32, 48, or 64*/
                    TxNPduInfo.SduLength = CANTP_TX_CHANNEL_DATALEN(ChannelId) + CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_2;

                    for(NextPossibleDlc = CANTP_INDEX_9; NextPossibleDlc < CANTP_INDEX_16; NextPossibleDlc++)
                    {
                        if(TxNPduInfo.SduLength <= Bsw_CanFDDlcMap[NextPossibleDlc])
                        {
                            PaddingLen = Bsw_CanFDDlcMap[NextPossibleDlc] - (uint8)(TxNPduInfo.SduLength);

                            if(PaddingLen > (uint8)0)
                            {
                                Bsw_MemSet(&(CanTp_TxBuff[TxNPduInfo.SduLength]), CANTP_PADDING_BYTE, (uint32)PaddingLen);
                            }

                            TxNPduInfo.SduLength = Bsw_CanFDDlcMap[NextPossibleDlc];
                            break;
                        }
                    }
                }
#endif
            }
            else
            {
                /*FF*/
                CANTP_TX_CHANNEL_DATALEN(ChannelId) -= CanTpTxNPduInfo.SduLength;
                CANTP_TX_CHANNEL_STATE(ChannelId) = CANTP_TXSTATE_WAITFFCONF;
                TxNPduInfo.SduLength = CANTP_TX_MAXCANLEN(TxSduId);
            }

            TxNPduInfo.SduDataPtr = (SduDataPtrType)CanTp_TxBuff;

            CANTP_TX_CHANNEL_TIMER(ChannelId) = CANTP_NAS(TxSduId);
            /*SWS_CanTp_00343*/
            ret = CanIf_Transmit(CANTP_TXNPDU_ID(TxSduId), &TxNPduInfo);

            if(E_OK != ret)
            {
                /*SWS_CanTp_00177*/
                CanTp_TxChannelInit(ChannelId);
                PduR_LoTpTxConfirmation(CANTP_CONFPDU_ID(TxSduId), E_NOT_OK);
            }

        }
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_CFTransmit

* Description  : This function is called by CanTp_MainFunction to handle N_As,
*                N_Bs and N_Cs.

* Inputs       : CanTpTxChannelId: Channel number of the Transimmit TpChannel.
*
* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANTP_CODE) CanTp_CFTransmit
(
    CanTp_ChannelIdType ChannelId
)
{
    BufReq_ReturnType Result;
    Std_ReturnType ret = E_NOT_OK;
    uint8 CanTp_TxBuff[CANTP_MAX_FRAME_LENGTH];
    PduInfoType CanTpTxNPduInfo;
    PduLengthType PaddingLen;
    PduLengthType CFMaxLen;
    PduIdType TxSduId = CANTP_TX_CHANNEL_CURID(ChannelId);
    PduLengthType RemainTxDataCnt = (PduLengthType)0;
    PduInfoType TxNPduInfo;
#if(STD_ON == CANTP_CANFD_SUPPORT)
    uint8 NextPossibleDlc = (uint8)0;
#endif

    if((CANTP_IS_DUPLEX_FULL(ChannelId)) && (CANTP_RX_CHANNEL_STATE(ChannelId) == CANTP_RXSTATE_WAITFCCONF))
    {
        /*Retry next mainfunction*/
        CANTP_TX_CHANNEL_STATE(ChannelId) |= CANTP_TXSTATE_RECOPY;
    }
    else
    {
        CFMaxLen = CANTP_TX_MAXCANLEN(TxSduId) - CANTP_TX_NPCI_OFFSET(TxSduId) - CANTP_INDEX_1;
        CanTpTxNPduInfo.SduDataPtr = (SduDataPtrType)&(CanTp_TxBuff[CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_1]);

        if(CANTP_TX_CHANNEL_DATALEN(ChannelId) <= CFMaxLen)
        {
            /* the last CF */
            CanTpTxNPduInfo.SduLength = CANTP_TX_CHANNEL_DATALEN(ChannelId);
        }
        else
        {
            /* not the last CF */
            CanTpTxNPduInfo.SduLength = CFMaxLen;
        }

        /*SWS_CanTp_00086 SWS_CanTp_00272*/
        Result = PduR_LoTpCopyTxData(CANTP_CONFPDU_ID(TxSduId), &CanTpTxNPduInfo, NULL_PTR, &RemainTxDataCnt);

        if(BUFREQ_E_BUSY == Result)
        {
            /*SWS_CanTp_00184*/
            CANTP_TX_CHANNEL_STATE(ChannelId) |= CANTP_TXSTATE_RECOPY;
        }
        else if(BUFREQ_E_NOT_OK == Result)
        {
            /*SWS_CanTp_00087 SWS_CanTp_00177*/
            CanTp_TxChannelInit(ChannelId);
            PduR_LoTpTxConfirmation(CANTP_CONFPDU_ID(TxSduId), E_NOT_OK);
        }
        else/*BUFREQ_E_OK*/
        {
            CanTp_TxSduCreatePCI(TxSduId, ChannelId, CanTp_TxBuff, CANTP_CF);

            if(CANTP_TX_CHANNEL_DATALEN(ChannelId) <= CFMaxLen)
            {
                /*the last CF*/
                CANTP_TX_CHANNEL_STATE(ChannelId) = CANTP_TXSTATE_WAITLASTCONF;

                if((CANTP_TX_CHANNEL_DATALEN(ChannelId) + CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_1) <= CANTP_CAN20_FRAME_LENGTH)
                {
                    if(CANTP_IS_TXSDU_PADDING_ENABLE(TxSduId) )
                    {
                        TxNPduInfo.SduLength = CANTP_CAN20_FRAME_LENGTH;
                        PaddingLen = CANTP_CAN20_FRAME_LENGTH - (CANTP_TX_CHANNEL_DATALEN(ChannelId) + CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_1);
                        /*SWS_CanTp_00059*/
                        /* MISRA RULE 12.1 violated:
                        operator + and - are with the same precedence, calculate from left to right..*/
                        if(PaddingLen > (uint8)0)
                        {
                            Bsw_MemSet(&(CanTp_TxBuff[CANTP_CAN20_FRAME_LENGTH - PaddingLen]), CANTP_PADDING_BYTE, (uint32)PaddingLen);
                        }
                    }
                    else
                    {
                        TxNPduInfo.SduLength = CANTP_TX_CHANNEL_DATALEN(ChannelId) + CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_1;
                    }
                }
#if(STD_ON == CANTP_CANFD_SUPPORT)
                else
                {
                    /*SWS_CanTp_00351 Sending DLC must be 0..8, 12, 16, 20, 24, 32, 48, or 64*/
                    TxNPduInfo.SduLength = CANTP_TX_CHANNEL_DATALEN(ChannelId) + CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_1;

                    for(NextPossibleDlc = CANTP_INDEX_9; NextPossibleDlc < CANTP_INDEX_16; NextPossibleDlc++)
                    {
                        if(TxNPduInfo.SduLength <= Bsw_CanFDDlcMap[NextPossibleDlc])
                        {
                            PaddingLen = Bsw_CanFDDlcMap[NextPossibleDlc] - TxNPduInfo.SduLength;

                            if(PaddingLen > (uint8)0)
                            {
                                Bsw_MemSet(&(CanTp_TxBuff[TxNPduInfo.SduLength]), CANTP_PADDING_BYTE, (uint32)PaddingLen);
                            }

                            TxNPduInfo.SduLength = Bsw_CanFDDlcMap[NextPossibleDlc];
                            break;
                        }
                    }
                }
#endif   
            }
            else
            {
                /*not the last CF*/
                CANTP_TX_CHANNEL_STATE(ChannelId) = CANTP_TXSTATE_WAITCFCONF;
                CANTP_TX_CHANNEL_DATALEN(ChannelId) -= CFMaxLen;
                TxNPduInfo.SduLength = CANTP_TX_MAXCANLEN(TxSduId);
            }

            TxNPduInfo.SduDataPtr = (SduDataPtrType)CanTp_TxBuff;
            CANTP_TX_CHANNEL_TIMER(ChannelId) = CANTP_NAS(TxSduId);
            /*SWS_CanTp_00343*/
            ret = CanIf_Transmit(CANTP_TXNPDU_ID(TxSduId), &TxNPduInfo);

            if(E_OK != ret)
            {
                /*SWS_CanTp_00177*/
                CanTp_TxChannelInit(ChannelId);
                (void)PduR_LoTpTxConfirmation(CANTP_CONFPDU_ID(TxSduId), E_NOT_OK);
            }
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_GetNextBlockLen

* Description  : This function is called by CanTp_MainFunction to handle N_Ar,
*                N_Br,N_Cr and STMmin.

* Inputs       : CanTpRxChannelId: Channel number of the received TpChannel.
*
* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANTP_CODE) CanTp_GetNextBlockLen
(
    CanTp_ChannelIdType ChannelId
)
{
    PduLengthType minlen;
    PduIdType RxSduId = CANTP_RX_CHANNEL_CURID(ChannelId);

    if(CANTP_BS(RxSduId) == (uint8)0)
    {
        minlen = CANTP_RX_CHANNEL_DATALEN(ChannelId);
    }
    else
    {
        minlen = (PduLengthType)(CANTP_RX_CHANNEL_FFDLC(ChannelId) - CANTP_RX_NPCI_OFFSET(RxSduId) - (PduLengthType)1) * (PduLengthType) CANTP_BS(RxSduId);

        if(minlen > CANTP_RX_CHANNEL_DATALEN(ChannelId) )
        {
            minlen = CANTP_RX_CHANNEL_DATALEN(ChannelId);
        }
    }

    CANTP_RX_CHANNEL_NEXTBLKLEN(ChannelId) = minlen;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_RxMainFunction

* Description  : This function is called by CanTp_MainFunction to handle N_Ar,
*                N_Br,N_Cr and STMmin.

* Inputs       : CanTpRxChannelId: Channel number of the received TpChannel.
*
* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANTP_CODE) CanTp_RxMainFunction
(
    CanTp_ChannelIdType ChannelId
)
{
    PduInfoType RxNPduInfo;
    PduIdType RxSduId = CANTP_RX_CHANNEL_CURID(ChannelId);
    PduLengthType AvailableBufLen = (PduLengthType)0;
    BufReq_ReturnType Result = BUFREQ_E_NOT_OK;

    SchM_Enter_CanTp_CANTP_EXCLUSIVE_AREA_0();

    if(!CANTP_RX_CHANNEL_IS_TIMER_EXP(ChannelId))
    {
        CANTP_RX_CHANNEL_TIMER(ChannelId) -= (uint16)1;
    }

    SchM_Exit_CanTp_CANTP_EXCLUSIVE_AREA_0();

    if(CANTP_RX_CHANNEL_STATE(ChannelId) == CANTP_RXSTATE_WAITBUFF_NEXTBLOCK)
    {
        /*SWS_CanTp_00222*/
        RxNPduInfo.SduDataPtr = NULL_PTR;
        RxNPduInfo.SduLength = (PduLengthType)0;
        /*poll whether buffer is ready*/
        Result = (BufReq_ReturnType)PduR_LoTpCopyRxData(CANTP_UPPDU_ID(RxSduId), &RxNPduInfo, &AvailableBufLen);

        if((BUFREQ_OK == Result) && (AvailableBufLen >= CANTP_RX_CHANNEL_NEXTBLKLEN(ChannelId)))
        {
            if((CANTP_IS_DUPLEX_FULL(ChannelId)) && ((CANTP_TXSTATE_WAITFFCONF == CANTP_TX_CHANNEL_STATE(ChannelId)) \
                || (CANTP_TXSTATE_WAITCFCONF == CANTP_TX_CHANNEL_STATE(ChannelId)) \
                || (CANTP_TXSTATE_WAITLASTCONF == CANTP_TX_CHANNEL_STATE(ChannelId))))
            {
                /*Retry next mainfunction*/
            }
            else
            {
                /*SWS_CanTp_00224*/
                CANTP_RX_CHANNEL_STATE(ChannelId) = CANTP_RXSTATE_TXFC;
                CANTP_RX_CHANNEL_FS(ChannelId) = CANTP_FC_FS_CTS;
                CANTP_RX_CHANNEL_TIMER(ChannelId) = (uint16)0; /*Tx FC in the current task*/
            }
        }
        else if(BUFREQ_E_NOT_OK == Result)
        {
            /*Send FC with FS_OVFLW can be immediately reset the state of Sender*/
            PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_NOT_OK);
            CANTP_RX_CHANNEL_STATE(ChannelId) = CANTP_RXSTATE_TXFC;
            CANTP_RX_CHANNEL_FS(ChannelId) = CANTP_FC_FS_OVFLW;
            CANTP_RX_CHANNEL_TIMER(ChannelId) = (uint16)0;
        }
        else
        {
            /*do nothing*/
        }
    }

    if(CANTP_RX_CHANNEL_IS_TIMER_EXP(ChannelId))
    {
        switch (CANTP_RX_CHANNEL_STATE(ChannelId))
        {
        case CANTP_RXSTATE_WAITBUFF_NEXTBLOCK:

            /*Send FC Wait after N_Br expiration*/
            /*SWS_CanTp_00341*/
            if(CANTP_WFTMAX(RxSduId) <= CANTP_RX_CHANNEL_WFTCNT(ChannelId))
            {
                /*SWS_CanTp_00223 SWS_CanTp_00084*/
                CanTp_RxChannelInit(ChannelId);
                PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_NOT_OK);
                CANTP_DET_REPORT_ERROR(CANTP_SID_MAINFUNCTIONRX, CANTP_E_RX_COM);/*SWS_CanTp_00229*/
            }
            else if((CANTP_IS_DUPLEX_FULL(ChannelId)) && ((CANTP_TXSTATE_WAITFFCONF == CANTP_TX_CHANNEL_STATE(ChannelId)) \
                || (CANTP_TXSTATE_WAITCFCONF == CANTP_TX_CHANNEL_STATE(ChannelId)) \
                || (CANTP_TXSTATE_WAITLASTCONF == CANTP_TX_CHANNEL_STATE(ChannelId))))
            {
                CanTp_RxChannelInit(ChannelId);
                PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_NOT_OK);
            }
            else
            {
                /*SWS_CanTp_00278*/
                CANTP_RX_CHANNEL_FS(ChannelId) = CANTP_FC_FS_WT;
                CanTp_TransmitFC(ChannelId);
            }

            break;

        case CANTP_RXSTATE_TXFC:
            /*SWS_CanTp_00278*/
            CanTp_TransmitFC(ChannelId);
            break;

        case CANTP_RXSTATE_WAITCF:
            /*SWS_CanTp_00313 SWS_CanTp_00084*/
            CanTp_RxChannelInit(ChannelId);
            PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_NOT_OK);
            CANTP_DET_REPORT_ERROR(CANTP_SID_MAINFUNCTIONRX, CANTP_E_RX_COM);/*SWS_CanTp_00229*/
            break;

        case CANTP_RXSTATE_WAITFCCONF:
            /*SWS_CanTp_00311 SWS_CanTp_00084*/
            CanTp_RxChannelInit(ChannelId);
            PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_NOT_OK);
            CANTP_DET_REPORT_ERROR(CANTP_SID_MAINFUNCTIONRX, CANTP_E_RX_COM);/*SWS_CanTp_00229*/
            break;

        default:
            CanTp_RxChannelInit(ChannelId);
            break;
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_TxMainFunction

* Description  : This function is called by CanTp_MainFunction to handle N_As,
*                N_Bs and N_Cs.

* Inputs       : CanTpTxChannelId: Channel number of the Transimmit TpChannel.
*
* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANTP_CODE) CanTp_TxMainFunction
(
    CanTp_ChannelIdType ChannelId
)
{
    uint8 State;
    PduIdType TxSduId = CANTP_TX_CHANNEL_CURID(ChannelId);

    SchM_Enter_CanTp_CANTP_EXCLUSIVE_AREA_0();

    if(!CANTP_TX_CHANNEL_IS_TIMER_EXP(ChannelId))
    {
        CANTP_TX_CHANNEL_TIMER(ChannelId) -= (uint16)1;
    }

    SchM_Exit_CanTp_CANTP_EXCLUSIVE_AREA_0();

    if(CANTP_TX_CHANNEL_IS_TIMER_EXP(ChannelId))
    {
        State = CANTP_TX_CHANNEL_STATE(ChannelId);

        if((State & CANTP_TXSTATE_RECOPY) != (uint8)0)
        {
            /*SWS_CanTp_00280 SWS_CanTp_00177*/
            /*N_Cs timeout*/
            CanTp_TxChannelInit(ChannelId);
            PduR_LoTpTxConfirmation(CANTP_CONFPDU_ID(TxSduId), E_NOT_OK);
            CANTP_DET_REPORT_ERROR(CANTP_SID_MAINFUNCTIONTX, CANTP_E_TX_COM);/*SWS_CanTp_00229*/
        }
        else if((State == CANTP_TXSTATE_WAITLASTCONF)
                  || (State == CANTP_TXSTATE_WAITFFCONF)
                  || (State == CANTP_TXSTATE_WAITCFCONF))
        {
            /*SWS_CanTp_00310 SWS_CanTp_00075 SWS_CanTp_00177*/
            /*N_As timeout*/
            CanTp_TxChannelInit(ChannelId);
            PduR_LoTpTxConfirmation(CANTP_CONFPDU_ID(TxSduId), E_NOT_OK);
            CANTP_DET_REPORT_ERROR(CANTP_SID_MAINFUNCTIONTX, CANTP_E_TX_COM);/*SWS_CanTp_00229*/
        }
        else if(State == CANTP_TXSTATE_WAITFC)
        {
            /*SWS_CanTp_00316 SWS_CanTp_00177*/
            /*N_Bs timeout*/
            CanTp_TxChannelInit(ChannelId);
            PduR_LoTpTxConfirmation(CANTP_CONFPDU_ID(TxSduId), E_NOT_OK);
            CANTP_DET_REPORT_ERROR(CANTP_SID_MAINFUNCTIONTX, CANTP_E_TX_COM);/*SWS_CanTp_00229*/
        }
        else if(State == CANTP_TXSTATE_TXSTART)
        {
            /*first try*/
            /*SWS_CanTp_00167*/
            CANTP_TX_CHANNEL_TIMER(ChannelId) = CANTP_NCS(TxSduId);
            CanTp_StartTransmit(ChannelId);
        }
        else if(State == CANTP_TXSTATE_WAITTXCF)
        {
            /*first try*/
            /*SWS_CanTp_00167*/
            CANTP_TX_CHANNEL_TIMER(ChannelId) = CANTP_NCS(TxSduId);
            CanTp_CFTransmit(ChannelId);
        }
        else
        {
            /* not possible */
        }
    }
    else if((CANTP_TX_CHANNEL_STATE(ChannelId) & CANTP_TXSTATE_RECOPY) != (uint8)0)
    {
        State = CANTP_TX_CHANNEL_STATE(ChannelId);
        /*PRQA S 4570 ++*/
        /*
        Allow the uint8 type to be done ~ oprator.
        */
        State &= (uint8)(~CANTP_TXSTATE_RECOPY);
        /*PRQA S 4570 --*/

        /*SWS_CanTp_00089*/
        if(State == CANTP_TXSTATE_TXSTART)
        {
            CanTp_StartTransmit(ChannelId);
        }
        else if(State == CANTP_TXSTATE_WAITTXCF)
        {
            CanTp_CFTransmit(ChannelId);
        }
        else
        {
            /* not possible */
        }
    }
    else
    {
        /* wait for STmin */
    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_RxChannelCheck

* Description  : This function is called by CanTp_MainFunction to handle N_As,
*                N_Bs and N_Cs.

* Inputs       : CanTpTxChannelId: Channel number of the Transimmit TpChannel.
*
* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, CANTP_CODE) CanTp_RxChannelCheck
(
    CanTp_ChannelIdType ChannelId
)
{
    Std_ReturnType ret = E_NOT_OK;


    if(CANTP_IS_DUPLEX_FULL(ChannelId))
    {
        ret = E_OK;
    }
    else if(CANTP_RX_CHANNEL_STATE(ChannelId) == CANTP_RXSTATE_IDLE)
    {
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_TxChannelCheck

* Description  : This function is called by CanTp_MainFunction to handle N_As,
*                N_Bs and N_Cs.

* Inputs       : CanTpTxChannelId: Channel number of the Transimmit TpChannel.
*
* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, CANTP_CODE) CanTp_TxChannelCheck
(
    CanTp_ChannelIdType ChannelId
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(CANTP_IS_DUPLEX_FULL(ChannelId) )
    {
        ret = E_OK;
    }
    else if(CANTP_TX_CHANNEL_STATE(ChannelId) == CANTP_TXSTATE_IDLE)
    {
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_GetSFValidData

* Description  : Get and validate frame length.
*
* Inputs       : ChannelId,PduInfoPtr, FrameType
*
* Outputs      : FrameLen.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, CANTP_CODE) CanTp_GetSFValidData
(
    PduIdType RxSduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr,
    P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) APduInfoPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduLengthType DataLen = (PduLengthType)0;
    PduLengthType CanLen = PduInfoPtr->SduLength;
    uint8 pci;
    PduLengthType NpciOffset = CANTP_RX_NPCI_OFFSET(RxSduId);
#if(STD_ON == CANTP_CANFD_SUPPORT)
    uint8 CanFD_Index;
#endif

    /*SWS_CanTp_00116*/
    if(CanLen <= CANTP_CAN20_FRAME_LENGTH)
    {
        /*SWS_CanTp_00344 SWS_CanTp_00345*/
        if( (CANTP_IS_RXSDU_PADDING_ENABLE(RxSduId) ) && (CanLen != CANTP_CAN20_FRAME_LENGTH) )
        {
            CANTP_DET_REPORT_ERROR(CANTP_SID_RXINDICATION, CANTP_E_PADDING);
        }
        else
        {
            pci = PduInfoPtr->SduDataPtr[NpciOffset];
            DataLen = ((PduLengthType)pci & (PduLengthType)CANTP_DLMASK_SF);
            if((DataLen > (PduLengthType)0) && (DataLen <= (CanLen - NpciOffset - CANTP_INDEX_1)))
            {
                APduInfoPtr->SduDataPtr = (SduDataPtrType)&(PduInfoPtr->SduDataPtr[NpciOffset + CANTP_INDEX_1]);
                APduInfoPtr->SduLength = DataLen;
                ret = E_OK;
            }
        }
    }

#if(STD_ON == CANTP_CANFD_SUPPORT)
    else
    {
        pci = PduInfoPtr->SduDataPtr[NpciOffset];

        if(pci == (uint8)0)
        {
            DataLen = PduInfoPtr->SduDataPtr[NpciOffset + CANTP_INDEX_1];

            for(CanFD_Index = (uint8)0; CanFD_Index < BSW_CANFD_LENGTH_TABLE_SIZE; CanFD_Index++)
            {
                if(Bsw_CanFDDlcMap[CanFD_Index] == CanLen)
                {
#if(CANTP_CAR_PLATFORM == CANTP_DEEPAL_PLATFORM)
                    if(DataLen <= (CanLen - NpciOffset - CANTP_INDEX_2))
#else
                    if((DataLen > CANTP_INDEX_7) && (DataLen <= (CanLen - NpciOffset - CANTP_INDEX_2)) \
                        && (DataLen > (Bsw_CanFDDlcMap[CanFD_Index - (uint8)1] - NpciOffset - CANTP_INDEX_2)))
#endif
                    {
                        APduInfoPtr->SduDataPtr = (SduDataPtrType)&(PduInfoPtr->SduDataPtr[NpciOffset + CANTP_INDEX_2]);
                        APduInfoPtr->SduLength = DataLen;
                        ret = E_OK;
                    }
                    break;
                }
            }
        }
    }
#endif

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_GetFFValidData

* Description  : Get and validate frame length.
*
* Inputs       : ChannelId,PduInfoPtr, FrameType
*
* Outputs      : FrameLen.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, CANTP_CODE) CanTp_GetFFValidData
(
	PduIdType RxSduId,
    CanTp_ChannelIdType ChannelId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr,
    P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) APduInfoPtr,
    PduLengthType *MFLen
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(STD_ON == CANTP_CANFD_SUPPORT)
    Std_ReturnType temp_ret = E_NOT_OK;
    uint8 CanFD_Index;
#endif
    PduLengthType DataLen = (PduLengthType)0;
    PduLengthType CanLen = PduInfoPtr->SduLength;
    PduLengthType PciLen;
    PduLengthType FF_DLmin;

    PduLengthType NpciOffset = CANTP_RX_NPCI_OFFSET(RxSduId);

    /*check CAN DLC*/
#if(CANTP_CAR_PLATFORM == CANTP_NIO_PLATFORM)
    if(CanLen == CANTP_RX_MAXCANLEN(RxSduId))
#endif
#if(CANTP_CAR_PLATFORM == CANTP_DEEPAL_PLATFORM)
    if((CanLen == CANTP_CAN20_FRAME_LENGTH) || (CanLen == CANTP_CANFD_MAX_LENGTH))
#endif
#if(CANTP_CAR_PLATFORM == CANTP_NO_PLATFORM)
    if(CanLen == CANTP_CAN20_FRAME_LENGTH)
#if(STD_ON == CANTP_CANFD_SUPPORT)
    {
        temp_ret = E_OK;
    }
    else
    {
        for(CanFD_Index = CANTP_INDEX_9; CanFD_Index < BSW_CANFD_LENGTH_TABLE_SIZE; CanFD_Index++)
        {
            if(Bsw_CanFDDlcMap[CanFD_Index] == CanLen)
            {
                temp_ret = E_OK;
                break;
            }
        }
    }

    if(temp_ret == E_OK)
#endif
#endif
    {
        /*SWS_CanTp_00350 CANTP116*/
        DataLen = (PduLengthType) (* (PduInfoPtr->SduDataPtr + NpciOffset + CANTP_INDEX_1) );
        /*PRQA S 4571,4391 ++*/
        /*
        Allow the uint8 type to be done << oprator.
        A composite expression of essentially unsigned type has been cast to a wider unsigned integer type. 
        */
        DataLen |=  (PduLengthType)( ( (PduLengthType) ( (* (PduInfoPtr->SduDataPtr + NpciOffset) ) & CANTP_DLMASK_FF) ) << (PduLengthType)CANTP_INDEX_8);
        /*PRQA S 4571,4391 --*/
#if(STD_ON == CANTP_LONGFF_SUPPORT)
        if(DataLen == (PduLengthType)0)
        {
            DataLen = (PduLengthType) (* (PduInfoPtr->SduDataPtr + NpciOffset + CANTP_INDEX_5) );
            DataLen |= ( (PduLengthType) (* (PduInfoPtr->SduDataPtr + NpciOffset + CANTP_INDEX_4) ) ) << CANTP_INDEX_8;
            DataLen |= ( (PduLengthType) (* (PduInfoPtr->SduDataPtr + NpciOffset + CANTP_INDEX_3) ) ) << CANTP_INDEX_16;
            DataLen |= ( (PduLengthType) (* (PduInfoPtr->SduDataPtr + NpciOffset + CANTP_INDEX_2) ) ) << CANTP_INDEX_24;
            if(DataLen > CANTP_FF_DL_12BIT)
            {
                PciLen = (PduLengthType)6;
                /*SWS_CanTp_00350*/
                CANTP_RX_CHANNEL_FFDLC(ChannelId) = CanLen;
                *MFLen = DataLen;
                APduInfoPtr->SduDataPtr = (SduDataPtrType)&(PduInfoPtr->SduDataPtr[NpciOffset + PciLen]);
                APduInfoPtr->SduLength = CanLen - NpciOffset - PciLen;
                ret = E_OK;
            }
        }
        else
#endif
        {
#if(STD_ON == CANTP_CANFD_SUPPORT)
            /*FF_DLmin equals the max length that can be carried by SF in the same CanLen plus 1*/
            if(CanLen == CANTP_CAN20_FRAME_LENGTH)
            {
                FF_DLmin = CANTP_CAN20_FRAME_LENGTH - NpciOffset;
            }
            else
            {
                FF_DLmin = CanLen - NpciOffset - CANTP_INDEX_1;
            }
#else
			FF_DLmin = CANTP_CAN20_FRAME_LENGTH - NpciOffset;
#endif
            PciLen = CANTP_INDEX_2;

            if(DataLen >= FF_DLmin)
            {
                /*SWS_CanTp_00350*/
                CANTP_RX_CHANNEL_FFDLC(ChannelId) = CanLen;
                *MFLen = DataLen;
                APduInfoPtr->SduDataPtr = (SduDataPtrType)&(PduInfoPtr->SduDataPtr[NpciOffset + PciLen]);
                APduInfoPtr->SduLength = CanLen - NpciOffset - PciLen;
                ret = E_OK;
            }
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_GetCFValidData

* Description  : Get and validate frame length.
*
* Inputs       : ChannelId,PduInfoPtr, FrameType
*
* Outputs      : FrameLen.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, CANTP_CODE) CanTp_GetCFValidData
(
    CanTp_ChannelIdType ChannelId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr,
    P2VAR(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) APduInfoPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduLengthType DataLen = (PduLengthType)0;
    PduLengthType CanLen = PduInfoPtr->SduLength;
#if(STD_ON == CANTP_CANFD_SUPPORT)
    uint8 CanFD_Index;
#endif
#if((CANTP_RX_NAI_ADDRESSING == STD_ON) || (CANTP_RXSDU_PADDING_MODE == CANTP_SDU_PADDING_VARIES))
    PduIdType RxSduId = CANTP_RX_CHANNEL_CURID(ChannelId);
#endif
    PduLengthType NpciOffset = CANTP_RX_NPCI_OFFSET(RxSduId);

    /*Last CF*/
    if(CANTP_RX_CHANNEL_DATALEN(ChannelId) <= (CANTP_RX_CHANNEL_FFDLC(ChannelId) - NpciOffset - CANTP_INDEX_1))
    {
        DataLen = CANTP_RX_CHANNEL_DATALEN(ChannelId);

#if(STD_ON == CANTP_CANFD_SUPPORT)
        for(CanFD_Index = (uint8)0; CanFD_Index < BSW_CANFD_LENGTH_TABLE_SIZE; CanFD_Index++)
        {
            if(Bsw_CanFDDlcMap[CanFD_Index] == CanLen)
            {
#endif
                if(CanLen <= CANTP_CAN20_FRAME_LENGTH)
                {
                    if((CANTP_IS_RXSDU_PADDING_ENABLE(RxSduId) ) && (CanLen != CANTP_CAN20_FRAME_LENGTH))
                    {
                        /*SWS_CanTp_00346*/
                        CANTP_DET_REPORT_ERROR(CANTP_SID_RXINDICATION, CANTP_E_PADDING);
                    }
                    else
                    {
                        if(CanLen >= (DataLen + NpciOffset + CANTP_INDEX_1))
                        {
                            APduInfoPtr->SduDataPtr = (SduDataPtrType)&(PduInfoPtr->SduDataPtr[NpciOffset + CANTP_INDEX_1]);
                            APduInfoPtr->SduLength = DataLen;
                            ret = E_OK;
                        }
                    }
                }
#if(STD_ON == CANTP_CANFD_SUPPORT)
                else
                {
                    if((DataLen <= (CanLen - NpciOffset - CANTP_INDEX_1)) \
                        && (DataLen > (Bsw_CanFDDlcMap[CanFD_Index - (uint8)1] - NpciOffset - CANTP_INDEX_1)))
                    {
                        APduInfoPtr->SduDataPtr = (SduDataPtrType)&(PduInfoPtr->SduDataPtr[NpciOffset + CANTP_INDEX_1]);
                        APduInfoPtr->SduLength = DataLen;
                        ret = E_OK;
                    }
                }
                break;
            }
        }
#endif
    }
    else/*not last CF*/
    {
        if(CanLen == CANTP_RX_CHANNEL_FFDLC(ChannelId))
        {
            APduInfoPtr->SduDataPtr = (SduDataPtrType)&(PduInfoPtr->SduDataPtr[NpciOffset + CANTP_INDEX_1]);
            APduInfoPtr->SduLength = CanLen - NpciOffset - CANTP_INDEX_1;
            ret = E_OK;
        }
    }

    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_GetFCValidData

* Description  : Get and validate frame length.
*
* Inputs       : ChannelId,PduInfoPtr, FrameType
*
* Outputs      : FrameLen.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, CANTP_CODE) CanTp_GetFCValidData
(
    CanTp_ChannelIdType ChannelId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, CANTP_APPL_DATA) FrameLen
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduLengthType CanLen = PduInfoPtr->SduLength;
#if((CANTP_TXSDU_PADDING_MODE == CANTP_SDU_PADDING_VARIES) \
     || (CANTP_TX_NAI_ADDRESSING == STD_ON))
    PduIdType RxSduId = CANTP_RX_CHANNEL_CURID(ChannelId);
    PduIdType TxSduId = CANTP_TXFC_NPDU_ID(RxSduId);
#endif

    /*SWS_CanTp_00349*/
    /*check CAN DLC*/
    if( (CANTP_IS_TXSDU_PADDING_ENABLE(TxSduId) ) && (CanLen < CANTP_CAN20_FRAME_LENGTH) )
    {
        ret = E_NOT_OK;
    }
    else if(CanLen <  (CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_3))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *FrameLen = CANTP_FC_DATALEN;
        ret = E_OK;
    }

    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_RxSFPdu

* Description  : This function is called by CanTp_RxIndication after receive a SF-PDU.
*
* Inputs       : RxSduId, ChannelId, PduInfoPtr
*
* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANTP_CODE) CanTp_RxSFPdu
(
    PduIdType RxSduId,
    CanTp_ChannelIdType ChannelId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr
)
{
    PduInfoType APduInfo;
    BufReq_ReturnType Result;
    PduLengthType AvailableBufLen;

    if(E_OK != CanTp_GetSFValidData(RxSduId, PduInfoPtr, &APduInfo) )
    {
        /*Ignore*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_RXINDICATION, CANTP_E_INVALID_RX_LENGTH);
    }
    else if(E_OK == CanTp_TxChannelCheck(ChannelId) )
    {
        /*SWS_CanTp_00124*/
        if(CANTP_RX_CHANNEL_CURID(ChannelId) == RxSduId)
        {
            CanTp_RxChannelInit(ChannelId);
            PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_NOT_OK);
        }

        /*SWS_CanTp_00353 SWS_CanTp_00079 SWS_CanTp_00329 SWS_CanTp_00080*/
        Result = PduR_LoTpStartOfReception(CANTP_UPPDU_ID(RxSduId), &APduInfo, APduInfo.SduLength, &AvailableBufLen);

        if(Result == BUFREQ_OK)
        {
            if(AvailableBufLen < APduInfo.SduLength)
            {
                /*SWS_CanTp_00339 SWS_CanTp_00084*/
                PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_NOT_OK);
            }
            else
            {
                Result = PduR_LoTpCopyRxData(CANTP_UPPDU_ID(RxSduId), &APduInfo, &AvailableBufLen);

                /*SWS_CanTp_00084*/
                if(Result == BUFREQ_OK)
                {
                    PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_OK);
                }
                else
                {
                    PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_NOT_OK);
                }
            }
        }
    }
    else
    {
        /*Ignore*/
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_RxFFPdu

* Description  : This function is called by CanTp_RxIndication after successful
*                reception a FF-PDU.
*
* Inputs       : RxSduId,CanTpRxChannelId,PduInfoPtr
*
* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANTP_CODE) CanTp_RxFFPdu
(
    PduIdType RxSduId,
    CanTp_ChannelIdType ChannelId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr
)
{
    PduLengthType MFLen = (PduLengthType)0;
    PduInfoType APduInfo;
    BufReq_ReturnType Result;
    PduLengthType AvailableBufLen = (PduLengthType)0;

    if( (CANTP_RX_TA_TYPE(RxSduId) == CANTP_FUNCTIONAL) || (CANTP_RX_TA_TYPE(RxSduId) == CANTP_CANFD_FUNCTIONAL) ) /*Target Addressing Format*/
    {
        /*SWS_CanTp_00093*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_RXINDICATION, CANTP_E_INVALID_TATYPE);
    }
    else if(E_OK != CanTp_GetFFValidData(RxSduId, ChannelId, PduInfoPtr, &APduInfo, &MFLen) )
    {
        CANTP_DET_REPORT_ERROR(CANTP_SID_RXINDICATION, CANTP_E_INVALID_RX_LENGTH);
    }
    else if(E_OK == CanTp_TxChannelCheck(ChannelId) )
    {
        /*SWS_CanTp_00124*/
        if( (CANTP_RX_CHANNEL_STATE(ChannelId) == CANTP_RXSTATE_IDLE) || (CANTP_RX_CHANNEL_CURID(ChannelId) == RxSduId) )
        {
            if(CANTP_RX_CHANNEL_CURID(ChannelId) == RxSduId)
            {
                /*SWS_CanTp_00057 SWS_CanTp_00084*/
                CanTp_RxChannelInit(ChannelId);
                PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_NOT_OK);
            }

            CANTP_RX_CHANNEL_FFDLC(ChannelId) = PduInfoPtr->SduLength;
            CANTP_RX_CHANNEL_CURID(ChannelId) = RxSduId;
            CANTP_RX_CHANNEL_DATALEN(ChannelId) = MFLen;
            CANTP_RX_CHANNEL_NEXTSN(ChannelId) = CANTP_SN_INITVAL;

            /*SWS_CanTp_00079 SWS_CanTp_00329 SWS_CanTp_00080*/
            Result = PduR_LoTpStartOfReception(CANTP_UPPDU_ID(RxSduId), &APduInfo, MFLen, &AvailableBufLen);

            if(Result == BUFREQ_OK)
            {
                if(AvailableBufLen < APduInfo.SduLength)
                {
                    /*SWS_CanTp_00339 SWS_CanTp_00084*/
                    CanTp_RxChannelInit(ChannelId);
                    PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_NOT_OK);
                }
                else
                {
                    CANTP_RX_CHANNEL_BSCNT(ChannelId) = CANTP_BS(RxSduId);
                    Result = (BufReq_ReturnType)PduR_LoTpCopyRxData(CANTP_UPPDU_ID(RxSduId), &APduInfo, &AvailableBufLen);

                    if(Result == BUFREQ_OK)
                    {
                        CANTP_RX_CHANNEL_DATALEN(ChannelId) -= APduInfo.SduLength;
                        CanTp_GetNextBlockLen(ChannelId);

                        if(AvailableBufLen >= CANTP_RX_CHANNEL_NEXTBLKLEN(ChannelId))
                        {
                            /*SWS_CanTp_00224*/
                            CANTP_RX_CHANNEL_STATE(ChannelId) = CANTP_RXSTATE_TXFC;
                            CANTP_RX_CHANNEL_FS(ChannelId) = CANTP_FC_FS_CTS;
                            CANTP_RX_CHANNEL_TIMER(ChannelId) = (uint16)0; /*Transmit FC in the task immediately*/
                        }
                        else
                        {
                            /*SWS_CanTp_00082*/
                            CANTP_RX_CHANNEL_TIMER(ChannelId) = CANTP_NBR(RxSduId);
                            CANTP_RX_CHANNEL_STATE(ChannelId) =  CANTP_RXSTATE_WAITBUFF_NEXTBLOCK;
                            CANTP_RX_CHANNEL_WFTCNT(ChannelId) = (uint8)0;
                        }
                    }
                    else/*BUFREQ_E_NOT_OK*/
                    {
                        /*abort*/
                        /*SWS_CanTp_00084*/
                        PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_NOT_OK);
                        CANTP_RX_CHANNEL_STATE(ChannelId) = CANTP_RXSTATE_TXFC;
                        CANTP_RX_CHANNEL_FS(ChannelId) = CANTP_FC_FS_OVFLW;
                        CANTP_RX_CHANNEL_TIMER(ChannelId) = (uint16)0; /*Transmit FC in the mainfunction immediately*/
                    }
                }
            }
            else if(Result == BUFREQ_E_OVFL)
            {
                /*SWS_CanTp_00318*/
                CANTP_RX_CHANNEL_STATE(ChannelId) = CANTP_RXSTATE_TXFC;
                CANTP_RX_CHANNEL_FS(ChannelId) = CANTP_FC_FS_OVFLW;
                CANTP_RX_CHANNEL_TIMER(ChannelId) = (uint16)0; /*Transmit FC in the mainfunction immediately*/
            }
            else/*BUFREQ_E_NOT_OK*/
            {
                /*SWS_CanTp_00081*/
                /*abort*/
                CanTp_RxChannelInit(ChannelId);
            }
        }
        else
        {
            /*SWS_CanTp_00124*/
            /*receive a FirstFrame with another connection is going on, ignore*/
        }
    }
    else
    {
        /*Ignore*/
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_RxCFPdu

* Description  : This function is called by CanTp_RxIndication after successful
*                reception a CF-PDU.
*
* Inputs       : RxSduId,CanTpRxChannelId,PduInfoPtr
*
* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANTP_CODE) CanTp_RxCFPdu
(
    PduIdType RxSduId,
    CanTp_ChannelIdType ChannelId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr
)
{
    uint8 CFPci;
    PduInfoType APduInfo;
    BufReq_ReturnType Result;
    PduLengthType AvailableBufLen;

    CFPci = (uint8)PduInfoPtr->SduDataPtr[CANTP_RX_NPCI_OFFSET(RxSduId)];

    if(CANTP_RX_CHANNEL_CURID(ChannelId) != RxSduId)
    {
        /*Ignore, do not inform upper layer */
    }
    else if(CANTP_RX_CHANNEL_STATE(ChannelId) != CANTP_RXSTATE_WAITCF)
    {
        /*maybe current state is CANTP_RXSTATE_TXFC.. or others*/
        /*Ignore, do not inform upper layer */
    }
    else if(E_OK != CanTp_GetCFValidData(ChannelId, PduInfoPtr, &APduInfo) )
    {
        /*Base on the requirement from Figure 9 ¡ª State flow ¨C Verifying received CAN frames of 15765-2(2015),
        CanTp shall ignore the frame when length is invalid.*/
    }
    else if( (CFPci & CANTP_SNMASK) != CANTP_RX_CHANNEL_NEXTSN(ChannelId) )
    {
        /*SWS_CanTp_00314 SWS_CanTp_00084*/
        CanTp_RxChannelInit(ChannelId);
        PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_NOT_OK);
    }
    else
    {
        if(CANTP_RX_CHANNEL_DATALEN(ChannelId) <= APduInfo.SduLength) /*the last CF*/
        {
            /*SWS_CanTp_00269*/
            Result = (BufReq_ReturnType)PduR_LoTpCopyRxData(CANTP_UPPDU_ID(RxSduId), &APduInfo, &AvailableBufLen);

            if(Result == BUFREQ_OK)
            {
                /*SWS_CanTp_00084*/
                CanTp_RxChannelInit(ChannelId);
                PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_OK);
            }
            else/*BUFREQ_E_NOT_OK */
            {
                /*SWS_CanTp_00084 SWS_CanTp_00271*/
                CanTp_RxChannelInit(ChannelId);
                PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_NOT_OK);
            }
        }
        else /*is not last CF*/
        {
            /*process NEXTSN */
            if(CANTP_RX_CHANNEL_NEXTSN(ChannelId) < CANTP_SNMASK)
            {
                CANTP_RX_CHANNEL_NEXTSN(ChannelId) += (uint8)1;
            }
            else
            {
                CANTP_RX_CHANNEL_NEXTSN(ChannelId) = (uint8)0;
            }

            /*check BS */
            if(CANTP_RX_CHANNEL_BSCNT(ChannelId) == (uint8)1) /*the last CF of block*/
            {
                CANTP_RX_CHANNEL_BSCNT(ChannelId) = CANTP_BS(RxSduId);
                /*SWS_CanTp_00166 start N_Br later*/
                /*SWS_CanTp_00269*/
                Result = PduR_LoTpCopyRxData(CANTP_UPPDU_ID(RxSduId), &APduInfo, &AvailableBufLen);

                if(Result == BUFREQ_OK)
                {
                    CANTP_RX_CHANNEL_DATALEN(ChannelId) -= APduInfo.SduLength;
                    CanTp_GetNextBlockLen(ChannelId);

                    if(AvailableBufLen >= CANTP_RX_CHANNEL_NEXTBLKLEN(ChannelId) )
                    {
                        /*SWS_CanTp_00224*/
                        CANTP_RX_CHANNEL_STATE(ChannelId) = CANTP_RXSTATE_TXFC;
                        CANTP_RX_CHANNEL_FS(ChannelId) = CANTP_FC_FS_CTS;
                        CANTP_RX_CHANNEL_TIMER(ChannelId) = (uint16)0; /*Transmit FC in the task immediately*/
                    }
                    else
                    {
                        /*SWS_CanTp_00325*/
                        CANTP_RX_CHANNEL_TIMER(ChannelId) = CANTP_NBR(RxSduId);
                        CANTP_RX_CHANNEL_STATE(ChannelId) =  CANTP_RXSTATE_WAITBUFF_NEXTBLOCK;
                        CANTP_RX_CHANNEL_WFTCNT(ChannelId) = (uint8)0;
                    }
                }
                else/*BUFREQ_E_NOT_OK*/
                {
                    /*SWS_CanTp_00084 SWS_CanTp_00271*/
                    PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_NOT_OK);
                    CANTP_RX_CHANNEL_STATE(ChannelId) = CANTP_RXSTATE_TXFC;
                    CANTP_RX_CHANNEL_FS(ChannelId) = CANTP_FC_FS_OVFLW;
                    CANTP_RX_CHANNEL_TIMER(ChannelId) = (uint16)0; /*Transmit FC in the task */
                }
            }
            else/*is NOT the last CF of block or BS=0*/
            {
                if(CANTP_RX_CHANNEL_BSCNT(ChannelId) != (uint8)0)
                {
                    CANTP_RX_CHANNEL_BSCNT(ChannelId) -= (uint8)1;
                }
                /*SWS_CanTp_00312*/
                CANTP_RX_CHANNEL_TIMER(ChannelId) = CANTP_NCR(RxSduId);

                /*SWS_CanTp_00269*/
                Result = PduR_LoTpCopyRxData(CANTP_UPPDU_ID(RxSduId), &APduInfo, &AvailableBufLen);

                if(Result == BUFREQ_OK)
                {
                    CANTP_RX_CHANNEL_DATALEN(ChannelId) -= APduInfo.SduLength;
                }
                else /*BUFREQ_E_NOT_OK*/
                {
                    /*SWS_CanTp_00271 SWS_CanTp_00084*/
                    CanTp_RxChannelInit(ChannelId);
                    PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_NOT_OK);
                }
            }
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_RxFCPdu

* Description  : This function is called by CanTp_RxIndication after successful
*                reception a FC-PDU.
*
* Inputs       : RxSduId,CanTpRxChannelId,PduInfoPtr
*
* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANTP_CODE) CanTp_RxFCPdu
(
    CanTp_ChannelIdType ChannelId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr
)
{
    uint8 FS;
    uint8 BS;
    uint8 STmin;
    PduLengthType FCLen;
    PduIdType TxSduId = CANTP_TX_CHANNEL_CURID(ChannelId);

    if(E_OK != CanTp_GetFCValidData(ChannelId, PduInfoPtr, &FCLen) )
    {
        CanTp_TxChannelInit(ChannelId);
        PduR_LoTpTxConfirmation(CANTP_CONFPDU_ID(TxSduId), E_NOT_OK);
    }
    else if(CANTP_TX_TA_TYPE(TxSduId) == CANTP_FUNCTIONAL) /*Target Addressing Format*/
    {
        /*SWS_CanTp_00093*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_RXINDICATION, CANTP_E_INVALID_TATYPE);
        CanTp_TxChannelInit(ChannelId);
        PduR_LoTpTxConfirmation(CANTP_CONFPDU_ID(TxSduId), E_NOT_OK);
    }
    else if(E_OK == CanTp_RxChannelCheck(ChannelId) )
    {
        FS = PduInfoPtr->SduDataPtr[CANTP_TX_NPCI_OFFSET(TxSduId)];
        FS &= CANTP_FSMASK;

        BS = PduInfoPtr->SduDataPtr[CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_1];
        STmin = PduInfoPtr->SduDataPtr[CANTP_TX_NPCI_OFFSET(TxSduId) + CANTP_INDEX_2];

        if(FS == CANTP_FC_FS_CTS)
        {
            CANTP_TX_CHANNEL_STATE(ChannelId) = CANTP_TXSTATE_WAITTXCF;
#if(CANTP_CAR_PLATFORM == CANTP_NISSAN_PLATFORM)
            if(TRUE == CANTP_TX_CHANNEL_INITIAL_FC_FLAG(ChannelId))
            {
                CANTP_TX_CHANNEL_INITIAL_FC_FLAG(ChannelId) = FALSE;
                CANTP_TX_CHANNEL_FIX_BSCNT(ChannelId) = BS;
                CANTP_TX_CHANNEL_BSCNT(ChannelId) = BS;
            }
            else
            {
                CANTP_TX_CHANNEL_BSCNT(ChannelId) = CANTP_TX_CHANNEL_FIX_BSCNT(ChannelId);
            }
#else
            CANTP_TX_CHANNEL_BSCNT(ChannelId) = BS;
#endif

            if(STmin == (uint8)0)
            {
                CANTP_TX_CHANNEL_STMIN(ChannelId) = (uint8)0;
            }
            else if(STmin < CANTP_STMINABSOLUTEMASK)
            {
                /*00 - 7F,STmin range:0 ms -127 ms*/
                CANTP_TX_CHANNEL_STMIN(ChannelId) = (uint8) (STmin / CANTP_MAIN_FUNCTION_PERIOD);

                /*Add by one for diva test*/
                /*if((STmin % CANTP_MAIN_FUNCTION_PERIOD) != 0)*/
                {
                    CANTP_TX_CHANNEL_STMIN(ChannelId) += (uint8)1;
                }
            }
            else if( (STmin >= CANTP_STMINRELATIVEMIN) && (STmin <= CANTP_STMINRELATIVEMAX) ) /*F1 - F9: STmin range: 100us - 900us*/
            {
                /*F1 - F9 100 us - 900 us*/
                CANTP_TX_CHANNEL_STMIN(ChannelId) = (uint8)1;
            }
            else
            {
                /*80 - F0,FA - FF Reserved*/
                CANTP_TX_CHANNEL_STMIN(ChannelId) = (uint8) ( ( (uint16)CANTP_STMINABSOLUTEMASK - (uint16)1) / CANTP_MAIN_FUNCTION_PERIOD); /* Max STmin time */

                if( ( (CANTP_STMINABSOLUTEMASK - (uint8)1) % ( (uint8)CANTP_MAIN_FUNCTION_PERIOD) ) != (uint8)0)
                {
                    CANTP_TX_CHANNEL_STMIN(ChannelId) += (uint8)1;
                }
            }

            CANTP_TX_CHANNEL_TIMER(ChannelId) = (uint16)0; /*Transmit CF in as fast as possible */
        }
        else if(FS == CANTP_FC_FS_WT)
        {
            /*SWS_CanTp_00315*/
            CANTP_TX_CHANNEL_STATE(ChannelId) = CANTP_TXSTATE_WAITFC;
            CANTP_TX_CHANNEL_TIMER(ChannelId) = CANTP_NBS(TxSduId);
        }
        else
        {
            /*CANTP_FC_FS_OVFLW or invalid FS*/
            /*SWS_CanTp_00177 SWS_CanTp_00309 SWS_CanTp_00317*/
            CanTp_TxChannelInit(ChannelId);
            PduR_LoTpTxConfirmation(CANTP_CONFPDU_ID(TxSduId), E_NOT_OK);
        }
    }
    else
    {
        /*Ignore*/
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_TxStateChangedAfterTxConfirm

* Description  : This function is called by CanTp_TxConfirmation after successful
*                transmition a SF/FF/CF-PDU.
*
* Inputs       : ChannelId,TxSduId
*
* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANTP_CODE) CanTp_TxStateChangedAfterTxConfirm
(
    CanTp_ChannelIdType ChannelId,
    PduIdType TxSduId
)
{
    if(CANTP_TXSTATE_WAITFFCONF == CANTP_TX_CHANNEL_STATE(ChannelId) )
    {
        /*SWS_CanTp_00315*/
        CANTP_TX_CHANNEL_STATE(ChannelId) = CANTP_TXSTATE_WAITFC;
        CANTP_TX_CHANNEL_TIMER(ChannelId) = CANTP_NBS(TxSduId);
    }
    else if(CANTP_TXSTATE_WAITCFCONF == CANTP_TX_CHANNEL_STATE(ChannelId) )
    {
        if(CANTP_TX_CHANNEL_BSCNT(ChannelId) != (uint8)0)
        {
            CANTP_TX_CHANNEL_BSCNT(ChannelId) -= (uint8)1;

            if(CANTP_TX_CHANNEL_BSCNT(ChannelId) == (uint8)0)
            {
                /*SWS_CanTp_00315*/
                CANTP_TX_CHANNEL_STATE(ChannelId) = CANTP_TXSTATE_WAITFC;
                CANTP_TX_CHANNEL_TIMER(ChannelId) = CANTP_NBS(TxSduId);
            }
            else if(CANTP_TX_CHANNEL_STMIN(ChannelId) > (uint8)0)
            {
                CANTP_TX_CHANNEL_STATE(ChannelId) = CANTP_TXSTATE_WAITTXCF;
                CANTP_TX_CHANNEL_TIMER(ChannelId) = CANTP_TX_CHANNEL_STMIN(ChannelId);
            }
            else
            {
                /*Send the next consecutive frame immediately*/
                CANTP_TX_CHANNEL_STATE(ChannelId) = CANTP_TXSTATE_WAITTXCF;
                CANTP_TX_CHANNEL_TIMER(ChannelId) = CANTP_NCS(TxSduId);
                CanTp_CFTransmit(ChannelId);
            }
        }
        else
        {
            if(CANTP_TX_CHANNEL_STMIN(ChannelId) > (uint8)0)
            {
                CANTP_TX_CHANNEL_STATE(ChannelId) = CANTP_TXSTATE_WAITTXCF;
                CANTP_TX_CHANNEL_TIMER(ChannelId) = CANTP_TX_CHANNEL_STMIN(ChannelId);
            }
            else
            {
                /*Send the next consecutive frame immediately*/
                CANTP_TX_CHANNEL_STATE(ChannelId) = CANTP_TXSTATE_WAITTXCF;
                CANTP_TX_CHANNEL_TIMER(ChannelId) = CANTP_NCS(TxSduId);
                CanTp_CFTransmit(ChannelId);
            }
        }
    }
    else if(CANTP_TXSTATE_WAITLASTCONF == CANTP_TX_CHANNEL_STATE(ChannelId) )
    {
        /*SWS_CanTp_00090 SWS_CanTp_00177*/
        CanTp_TxChannelInit(ChannelId);
        PduR_LoTpTxConfirmation(CANTP_CONFPDU_ID(TxSduId), E_OK);
    }
    else
    {
        /*SWS_CanTp_00075*/
        /*TxConfirmation comes too late, ignore*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_RxStateChangedAfterTxConfirm

* Description  : This function is called by CanTp_TxConfirmation after successful
*                transmition a FC-PDU.
*
* Inputs       : ChannelId,RxSduId
*
* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANTP_CODE) CanTp_RxStateChangedAfterTxConfirm
(
    CanTp_ChannelIdType ChannelId,
    PduIdType RxSduId
)
{
    /*other states ignore*/
    if(CANTP_RXSTATE_WAITFCCONF == CANTP_RX_CHANNEL_STATE(ChannelId) )
    {
        if(CANTP_FC_FS_CTS == CANTP_RX_CHANNEL_FS(ChannelId) )
        {
            CANTP_RX_CHANNEL_STATE(ChannelId) = CANTP_RXSTATE_WAITCF;
            /*SWS_CanTp_00312*/
            CANTP_RX_CHANNEL_TIMER(ChannelId) = CANTP_NCR(RxSduId);
        }
        else if(CANTP_FC_FS_WT == CANTP_RX_CHANNEL_FS(ChannelId) )
        {
            CANTP_RX_CHANNEL_WFTCNT(ChannelId) = CANTP_RX_CHANNEL_WFTCNT(ChannelId) + (uint8)1;
            CANTP_RX_CHANNEL_STATE(ChannelId) = CANTP_RXSTATE_WAITBUFF_NEXTBLOCK;
            CANTP_RX_CHANNEL_TIMER(ChannelId) = CANTP_NBR(RxSduId);
        }
        else
        {
            /*CANTP_FC_FS_OVFLW or invalid FS*/
            CanTp_RxChannelInit(ChannelId);
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_CheckTxNsdu

* Description  : This function is called by CanTp_RxIndication.
*
* Inputs       : RxPduId,PduInfoPtr
*
* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANTP_CODE) CanTp_CheckTxNsdu
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr
)
{
    PduIdType TxSduId;
    PduIdType SduId = COMSTACK_INVALID_PDUID;
    CanTp_ChannelIdType ChannelId = COMSTACK_INVALID_PDUID;
    PduLengthType NPciOffset = (PduLengthType)0;
    uint8 FrameType;

    for(TxSduId = (PduIdType)0; TxSduId < CANTP_NUM_TX_SDUS; TxSduId++)
    {
        if(RxPduId == CANTP_RXFC_NPDU_ID(TxSduId) )
        {
#if(STD_ON == CANTP_TX_NAI_ADDRESSING)
            if(CANTP_EXTENDED == CANTP_TX_ADDRFORM(TxSduId) )
            {
                if(PduInfoPtr->SduDataPtr[CANTP_EXTMIX_OFFSET] == CANTP_TX_NSA(TxSduId) ) /*Check Source Address */
                {
                    break;
                }
            }
            else if( (CANTP_MIXED == CANTP_TX_ADDRFORM(TxSduId) ) || (CANTP_MIXED29BIT == CANTP_TX_ADDRFORM(TxSduId) ) )
            {
                if(PduInfoPtr->SduDataPtr[CANTP_EXTMIX_OFFSET] == CANTP_TX_NAE(TxSduId) ) /*Check Extend Address */
                {
                    break;
                }
            }
            else
#endif
            {
                /*STANDARD*/
                break;
            }
        }
    }

    if(TxSduId < CANTP_NUM_TX_SDUS) /*found TxSduId*/
    {
        SduId = TxSduId;
        ChannelId = CANTP_TXTPCHANNEL_ID(TxSduId);
        NPciOffset = CANTP_TX_NPCI_OFFSET(TxSduId);
        FrameType = PduInfoPtr->SduDataPtr[NPciOffset] & CANTP_FTMASK;

        SchM_Enter_CanTp_CANTP_EXCLUSIVE_AREA_1();

        if( (FrameType == CANTP_FC) && (CANTP_TX_CHANNEL_STATE(ChannelId) == CANTP_TXSTATE_WAITFC) )
        {
            if(CANTP_TX_CHANNEL_CURID(ChannelId) == SduId)
            {
                CanTp_RxFCPdu (ChannelId, PduInfoPtr);
            }
        }
        else
        {
            /*FrameType error or coming too late, ignore*/
        }

        SchM_Exit_CanTp_CANTP_EXCLUSIVE_AREA_1();
    }
    else
    {
        CANTP_DET_REPORT_ERROR(CANTP_SID_RXINDICATION, CANTP_E_INVALID_RX_ID);
    }
}
/*******************************************************************************
*  PUBLIC Functions define
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_Init  SWS_CanTp_00208
*
* Description  : This function initializes the CanTp module.
*
* Inputs       : CfgPtr: Pointer to the CanTp post-build configuration data.
*
* Outputs      : None.
*
* Limitations  : None.
********************************************************************************
 END_FUNCTION_HDR*/
FUNC(void, CANTP_CODE) CanTp_Init
(
    CONSTP2CONST(CanTp_ConfigType, CANTP_APPL_CONST, AUTOMATIC) CfgPtr
)
{
    CanTp_ChannelIdType ChannelId;
#if(STD_ON == CANTP_DEV_ERROR_DETECT)
    PduIdType TxSduId;
#endif
#if((STD_ON == CANTP_CHANGE_PARAMETER_API) || (STD_ON == CANTP_DEV_ERROR_DETECT))
    PduIdType RxSduId;
#endif

    /*Cfg compatibility check*/
#if(STD_ON == CANTP_DEV_ERROR_DETECT)
    for(TxSduId = (PduIdType)0; TxSduId < CANTP_NUM_TX_SDUS; TxSduId++)
    {
        if(CANTP_TXTPCHANNEL_ID(TxSduId) >= CANTP_NUM_TX_CHANNELS)
        {
            CANTP_DET_REPORT_ERROR(CANTP_SID_INIT, CANTP_E_INVALID_CHANNEL);
        }

        if( (CANTP_TX_TA_TYPE(TxSduId) == CANTP_PHYSICAL)
                && (COMSTACK_INVALID_PDUID == CANTP_RXFC_NPDU_ID(TxSduId) ) )
        {
            CANTP_DET_REPORT_ERROR(CANTP_SID_INIT, CANTP_E_INVALID_TATYPE);
        }

        if( (CANTP_TX_TA_TYPE(TxSduId) == CANTP_FUNCTIONAL)
                && (COMSTACK_INVALID_PDUID != CANTP_RXFC_NPDU_ID(TxSduId) ) )
        {
            CANTP_DET_REPORT_ERROR(CANTP_SID_INIT, CANTP_E_INVALID_TATYPE);
        }

#if(CANTP_TX_NAI_ADDRESSING == STD_ON)
        if( (CANTP_TX_NPCI_OFFSET(TxSduId) != (PduLengthType)0) && (CANTP_TX_NPCI_OFFSET(TxSduId) != (PduLengthType)1) )
        {
            CANTP_DET_REPORT_ERROR(CANTP_SID_INIT, CANTP_E_INVALID_NPCI_OFFSET);
        }

#endif
    }

    for(RxSduId = (PduIdType)0; RxSduId < CANTP_NUM_RX_SDUS; RxSduId++)
    {
        if(CANTP_RXTPCHANNEL_ID(RxSduId) >= CANTP_NUM_RX_CHANNELS)
        {
            CANTP_DET_REPORT_ERROR(CANTP_SID_INIT, CANTP_E_INVALID_CHANNEL);
        }

        if( ( (CANTP_RX_TA_TYPE(RxSduId) == CANTP_PHYSICAL) || (CANTP_RX_TA_TYPE(RxSduId) == CANTP_CANFD_PHYSICAL) )
                && (COMSTACK_INVALID_PDUID == CANTP_TXFC_NPDU_ID(RxSduId) ) )
        {
            CANTP_DET_REPORT_ERROR(CANTP_SID_INIT, CANTP_E_INVALID_TATYPE);
        }

        if( ( (CANTP_RX_TA_TYPE(RxSduId) == CANTP_FUNCTIONAL) || (CANTP_RX_TA_TYPE(RxSduId) == CANTP_CANFD_FUNCTIONAL) )
                && (COMSTACK_INVALID_PDUID != CANTP_TXFC_NPDU_ID(RxSduId) ) )
        {
            CANTP_DET_REPORT_ERROR(CANTP_SID_INIT, CANTP_E_INVALID_TATYPE);
        }

#if(CANTP_RX_NAI_ADDRESSING == STD_ON)
        if( (CANTP_RX_NPCI_OFFSET(RxSduId) != (PduLengthType)0) && (CANTP_RX_NPCI_OFFSET(RxSduId) != (PduLengthType)1) )
        {
            CANTP_DET_REPORT_ERROR(CANTP_SID_INIT, CANTP_E_INVALID_NPCI_OFFSET);
        }

#endif
    }

#endif

#if(CANTP_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    if(NULL_PTR == CfgPtr)
    {
        CANTP_DET_REPORT_ERROR(CANTP_SID_INIT, CANTP_E_PARAM_POINTER);
    }
    else
#else
    /* MISRA RULE 14.2 violated:
    this statement is used to reduce the compiler warnning on the unused parameters..*/
    (void) CfgPtr;

#endif
    {
        /*SWS_CanTp_00169 SWS_CanTp_00111 SWS_CanTp_00273*/
#if(CANTP_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        CanTp_ConfigSet = CfgPtr;
#endif

        /*SWS_CanTp_00030*/
        for(ChannelId = (CanTp_ChannelIdType)0; ChannelId < CANTP_NUM_RX_CHANNELS; ChannelId++)
        {
            CanTp_RxChannelInit(ChannelId);
        }

        for(ChannelId = (CanTp_ChannelIdType)0; ChannelId < CANTP_NUM_TX_CHANNELS; ChannelId++)
        {
            CanTp_TxChannelInit(ChannelId);
        }

#if(STD_ON == CANTP_CHANGE_PARAMETER_API)
        /*init CanTp_ParamInfo*/
        for(RxSduId = (PduIdType)0; RxSduId < CANTP_NUM_RX_SDUS; RxSduId++)
        {
            CanTp_ParamInfo[RxSduId].CanTpBs = CANTP_RXNSDUINFO(RxSduId).CanTpBs;
            CanTp_ParamInfo[RxSduId].CanTpSTmin = CANTP_RXNSDUINFO(RxSduId).CanTpSTmin;
        }
#endif

        /*SWS_CanTp_00170*/
        CANTP_SET_INITIALIZED();
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_Shutdown   SWS_CanTp_00211
*
* Description  : This function is called to shutdown the CanTp module.
*
* Inputs       : None
*
* Outputs      : None
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANTP_CODE) CanTp_Shutdown
(
    void
)
{
    CanTp_ChannelIdType ChannelId;

    /*SWS_CanTp_00010*/
    for(ChannelId = (CanTp_ChannelIdType)0; ChannelId < CANTP_NUM_RX_CHANNELS; ChannelId++)
    {
        CanTp_RxChannelInit(ChannelId);
    }

    for(ChannelId = (CanTp_ChannelIdType)0; ChannelId < CANTP_NUM_TX_CHANNELS; ChannelId++)
    {
        CanTp_TxChannelInit(ChannelId);
    }

    /*SWS_CanTp_00202 SWS_CanTp_00200*/
    CANTP_SET_UNINITIALIZED();
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_Transmit  SWS_CanTp_00212
*
* Description  : This service is used to request the transfer of segmented data.
*
* Inputs       : CanTpTxSduId  : This parameter contains the unique CanTp module
*                                identifier of the CAN N-SDU to be transmitted.
*                                Range[0,(maximum number of L-PDU IDs received)
*                                -1]
*                CanTpTxInfoPtr: An indicator of a structure with CAN N-SDU rel-
*                                ated data:indicator of a CAN N-SDU buffer and
*                                the length of this buffer.
*
* Outputs      : E_OK    : request is accepted.
*                E_NOT_OK: request is not accepted.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANTP_CODE) CanTp_Transmit
(
    PduIdType CanTpTxSduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) CanTpTxInfoPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    CanTp_ChannelIdType ChannelId;
    PduLengthType SFMaxLen;

    /*SWS_CanTp_00238*/
    if(!CANTP_IS_INITIALIZED() )
    {
        /*SWS_CanTp_00031*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_TRANSMIT, CANTP_E_UNINIT);
    }
    else if(CanTpTxSduId >= CANTP_NUM_TX_SDUS)
    {
        CANTP_DET_REPORT_ERROR(CANTP_SID_TRANSMIT, CANTP_E_INVALID_TX_ID);
    }
    else if(NULL_PTR == CanTpTxInfoPtr)
    {
        /*SWS_CanTp_00321*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_TRANSMIT, CANTP_E_PARAM_POINTER);
    }
    else if(CanTpTxInfoPtr->SduLength == (PduLengthType)0)
    {
        CANTP_DET_REPORT_ERROR(CANTP_SID_TRANSMIT, CANTP_E_INVALID_TX_LENGTH);
    }

#if(STD_OFF == CANTP_LONGFF_SUPPORT)
    else if(CanTpTxInfoPtr->SduLength > CANTP_FF_DL_12BIT)
    {
        CANTP_DET_REPORT_ERROR(CANTP_SID_TRANSMIT, CANTP_E_INVALID_TX_LENGTH);
    }
#endif
    else
    {
        ChannelId = CANTP_TXTPCHANNEL_ID(CanTpTxSduId);

        SchM_Enter_CanTp_CANTP_EXCLUSIVE_AREA_0();

        /*SWS_CanTp_00206 SWS_CanTp_00123*/
        if(CANTP_TX_CHANNEL_STATE(ChannelId) == CANTP_TXSTATE_IDLE)
        {
            if(CANTP_TX_MAXCANLEN(CanTpTxSduId) > CANTP_CAN20_FRAME_LENGTH)
            {
                /*CANFD*/
                SFMaxLen = CANTP_TX_MAXCANLEN(CanTpTxSduId) - CANTP_TX_NPCI_OFFSET(CanTpTxSduId) - CANTP_INDEX_2;
            }
            else
            {
                SFMaxLen = CANTP_TX_MAXCANLEN(CanTpTxSduId) - CANTP_TX_NPCI_OFFSET(CanTpTxSduId) - CANTP_INDEX_1;
            }

            /*FUNCTION must be SF*/
            /*SWS_CanTp_00093*/
            if( (CANTP_TX_TA_TYPE(CanTpTxSduId) == CANTP_FUNCTIONAL)
                    && (CanTpTxInfoPtr->SduLength > SFMaxLen) )
            {
                CANTP_DET_REPORT_ERROR(CANTP_SID_TRANSMIT, CANTP_E_INVALID_TATYPE);
            }
            else
            {
                if(E_OK == CanTp_RxChannelCheck(ChannelId) )
                {
                    /*SWS_CanTp_00176*/
                    CanTp_TxChannelInit(ChannelId);

                    CANTP_TX_CHANNEL_CURID(ChannelId) = CanTpTxSduId;
                    CANTP_TX_CHANNEL_TIMER(ChannelId) = (uint16)0;
                    /*SWS_CanTp_00225*/
                    CANTP_TX_CHANNEL_DATALEN(ChannelId) = CanTpTxInfoPtr->SduLength;
                    CANTP_TX_CHANNEL_STATE(ChannelId) = CANTP_TXSTATE_TXSTART;
                    ret = E_OK;
                }
            }
        }

        SchM_Exit_CanTp_CANTP_EXCLUSIVE_AREA_0();
    }

    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_RxIndication  SWS_CanTp_00214 SWS_CanTp_00078
*
* Description  : This function is called by the CAN Interface after a successful
*                reception of a Rx CAN L-PDU.
*
* Inputs       : CanTpRxPduId : ID of CAN L-PDU that has been received.Identifi-
*                               es the data that has been received.Range: 0..(m-
*                               aximum number of L-PDU IDs received ) - 1
*                CanTpRxPduPtr: Indicator of structure with received L-SDU (pay-
*                               load) and data length.
*
* Outputs      : None.
*
* Limitations  : (SWS_CanTp_00235)The function CanTp_RxIndication shall be callable in
*                interrupt context (it could be called from the CAN receive
*                interrupt).
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANTP_CODE) CanTp_RxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_DATA) PduInfoPtr
)
{
    boolean ProcessOK = FALSE;
    PduIdType RxSduId;
    PduIdType SduId = COMSTACK_INVALID_PDUID;
    CanTp_ChannelIdType ChannelId = COMSTACK_INVALID_PDUID;
    PduLengthType NPciOffset = (PduLengthType)0;
    uint8 FrameType;

    /*SWS_CanTp_00238*/
    if(!CANTP_IS_INITIALIZED() )
    {
        /*SWS_CanTp_00031*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_RXINDICATION, CANTP_E_UNINIT);
    }
    else if( (PduInfoPtr == NULL_PTR) || (PduInfoPtr->SduDataPtr == NULL_PTR) )
    {
        /*SWS_CanTp_00322*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_RXINDICATION, CANTP_E_PARAM_POINTER);
    }
    else if((CANTP_MAX_FRAME_LENGTH < PduInfoPtr->SduLength) || ((uint16)0 == PduInfoPtr->SduLength))
    {
        CANTP_DET_REPORT_ERROR(CANTP_SID_RXINDICATION, CANTP_E_INVALID_RX_LENGTH);
    }
    else
    {
        /***************************  check CanTp_RxNsduCfg first ******************************/
        for(RxSduId = (PduIdType)0; RxSduId < CANTP_NUM_RX_SDUS; RxSduId++)
        {
            if(RxPduId == CANTP_RXNPDU_ID(RxSduId) )
            {
#if(STD_ON == CANTP_RX_NAI_ADDRESSING)
                if(CANTP_EXTENDED == CANTP_RX_ADDRFORM(RxSduId) )
                {
                    if(PduInfoPtr->SduDataPtr[CANTP_EXTMIX_OFFSET] == CANTP_RX_NTA(RxSduId) ) /*Check Target Address */
                    {
                        break;
                    }
                }
                else if( (CANTP_MIXED == CANTP_RX_ADDRFORM(RxSduId) ) || (CANTP_MIXED29BIT == CANTP_RX_ADDRFORM(RxSduId) ) )
                {
                    /*MIXED or MIXED29BIT*/
                    if(PduInfoPtr->SduDataPtr[CANTP_EXTMIX_OFFSET] == CANTP_RX_NAE(RxSduId) ) /*Check Extend Address */
                    {
                        break;
                    }
                }
                else
#endif
                {
                    /*STANDARD or NORMALFIXED*/
                    break;
                }
            }
        }

        if(RxSduId < CANTP_NUM_RX_SDUS) /*found match RxSduId*/
        {
            SduId = RxSduId;
            ChannelId = CANTP_RXTPCHANNEL_ID(RxSduId);
            NPciOffset = CANTP_RX_NPCI_OFFSET(RxSduId);
            FrameType = PduInfoPtr->SduDataPtr[NPciOffset] & CANTP_FTMASK;

            if((FrameType == CANTP_CF) || (FrameType == CANTP_SF) || (FrameType == CANTP_FF))
            {
                ProcessOK = TRUE;
                SchM_Enter_CanTp_CANTP_EXCLUSIVE_AREA_1();

                if(FrameType == CANTP_CF)
                {
                    CanTp_RxCFPdu (SduId, ChannelId, PduInfoPtr);
                }
                else if(FrameType == CANTP_SF)
                {
                    CanTp_RxSFPdu (SduId, ChannelId, PduInfoPtr);
                }
                else /*FrameType == CANTP_FF*/
                {
                    CanTp_RxFFPdu (SduId, ChannelId, PduInfoPtr);
                }

                SchM_Exit_CanTp_CANTP_EXCLUSIVE_AREA_1();
            }
        }

        /***************************   check CanTp_RxNsduCfg End  ******************************/

        /***************************   check CanTp_TxNsduCfg Start ******************************/
        if(TRUE != ProcessOK)
        {
            CanTp_CheckTxNsdu(RxPduId, PduInfoPtr);
        }
        /***************************   check CanTp_TxNsduCfg End ******************************/

    }

}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_TxConfirmation  SWS_CanTp_00215 SWS_CanTp_00076
*
* Description  : All transmitted CAN frames(SF, FF, CF, FC) belonging to the CAN
*                Transport will be confirmed by this function.
*
* Inputs       : TxPduId: ID of CAN L-PDU that has been transmitted. Range:
*                         0..(maximum number of L-PDU IDs received ) - 1
*                result:  E_OK: The PDU was transmitted. 
*                         E_NOT_OK: Transmission of the PDU failed.
* Outputs      : None.
*
* Limitations  : (SWS_CanTp_00236)The function CanTp_TxConfirmation shall be callable
*                in interrupt context (it could be called from the CAN transmit
*                interrupt).
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANTP_CODE) CanTp_TxConfirmation
(
    PduIdType TxPduId,
    Std_ReturnType result
)
{
    CanTp_ChannelIdType ChannelId;
    PduIdType TxSduId, RxSduId;
    boolean ProcessDone = FALSE;

    if(!CANTP_IS_INITIALIZED() )
    {
        /*SWS_CanTp_00031*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_TXCONFIRMATION, CANTP_E_UNINIT);
    }
    else
    {
        for(ChannelId = (CanTp_ChannelIdType)0; ChannelId < CANTP_NUM_TX_CHANNELS; ChannelId++)
        {
            TxSduId = CANTP_TX_CHANNEL_CURID(ChannelId);

            if(TxSduId != COMSTACK_INVALID_PDUID)
            {
                if(CANTP_TXNPDU_ID(TxSduId) == TxPduId)
                {
                    if((CANTP_TXSTATE_WAITFFCONF == CANTP_TX_CHANNEL_STATE(ChannelId)) \
                        || (CANTP_TXSTATE_WAITCFCONF == CANTP_TX_CHANNEL_STATE(ChannelId)) \
                        || (CANTP_TXSTATE_WAITLASTCONF == CANTP_TX_CHANNEL_STATE(ChannelId)))
                    {
                        SchM_Enter_CanTp_CANTP_EXCLUSIVE_AREA_1();

                        if(E_NOT_OK == result)
                        {
                            /*SWS_CanTp_00355 SWS_CanTp_00177*/
                            CanTp_TxChannelInit(ChannelId);
                            PduR_LoTpTxConfirmation(CANTP_CONFPDU_ID(TxSduId), E_NOT_OK);
                        }
                        else
                        {
                            /*SWS_CanTp_00315 SWS_CanTp_00090 SWS_CanTp_00177*/
                            CanTp_TxStateChangedAfterTxConfirm(ChannelId, TxSduId);
                        }

                        SchM_Exit_CanTp_CANTP_EXCLUSIVE_AREA_1();

                        ProcessDone = TRUE;
                    }
                    break;
                }
            }
        }

        if(TRUE != ProcessDone)
        {
            for(ChannelId = (CanTp_ChannelIdType)0; ChannelId < CANTP_NUM_RX_CHANNELS; ChannelId++)
            {
                RxSduId = CANTP_RX_CHANNEL_CURID(ChannelId);

                if(RxSduId != COMSTACK_INVALID_PDUID)
                {
                    if(CANTP_TXFC_NPDU_ID(RxSduId) == TxPduId)
                    {
                        SchM_Enter_CanTp_CANTP_EXCLUSIVE_AREA_1();

                        if(E_NOT_OK == result)
                        {
                            /*SWS_CanTp_00355 SWS_CanTp_00177*/
                            CanTp_RxChannelInit(ChannelId);
                            (void)PduR_LoTpRxIndication(CANTP_UPPDU_ID(RxSduId), E_NOT_OK);
                        }
                        else
                        {
                            /*SWS_CanTp_00312*/
                            CanTp_RxStateChangedAfterTxConfirm(ChannelId, RxSduId);
                        }

                        SchM_Exit_CanTp_CANTP_EXCLUSIVE_AREA_1();

                        break;
                    }
                }
            }
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_MainFunction  SWS_CanTp_00213
*
* Description  : The main function for scheduling the CAN TP.
*
* Inputs       : None.
*
* Outputs      : None.
*
* Limitations  : (SWS_CanTp_00164)The main function for scheduling the CAN TP (Entry
*                point for scheduling)The main function will be called by the
*                Schedule Manager or by the Free Running Timer module according
*                of the call period needed. CanTp_MainFunction is involved in
*                handling of CAN TP timeouts N_As, N_Bs, N_Cs, N_Ar, N_Br,N_Cr
*                and STMmin.(SWS_CanTp_00300)The function CanTp_MainFunction is affect-
*                ed by configurationparameter CanTpMainFunctionPeriod.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANTP_CODE) CanTp_MainFunction
(
    void
)
{
    CanTp_ChannelIdType ChannelId;

    if(!CANTP_IS_INITIALIZED() )
    {
        /*CANTP031*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_MAINFUNCTION, CANTP_E_UNINIT);
    }
    else
    {
        /*****Rx Task******************/
        for(ChannelId = (CanTp_ChannelIdType)0; ChannelId < (CanTp_ChannelIdType)CANTP_CHANNELS; ChannelId++)
        {
#if(STD_ON == CANTP_MULTI_CORE_SUPPORT)
            if(CANTP_CHANNEL_CORE_INFO(ChannelId) == CANTP_GETCOREID())
#endif
            {
                if(CANTP_RX_CHANNEL_STATE(ChannelId) != CANTP_RXSTATE_IDLE)
                {
                    CanTp_RxMainFunction(ChannelId);
                }
            }
        }

        /*****Tx Task******************/
        for(ChannelId = (CanTp_ChannelIdType)0; ChannelId < (CanTp_ChannelIdType)CANTP_CHANNELS; ChannelId++)
        {
#if(STD_ON == CANTP_MULTI_CORE_SUPPORT)
            if(CANTP_CHANNEL_CORE_INFO(ChannelId) == CANTP_GETCOREID())
#endif
            {
                if(CANTP_TX_CHANNEL_STATE(ChannelId) != CANTP_TXSTATE_IDLE)
                {
                    CanTp_TxMainFunction(ChannelId);
                }
            }
        }

    }
}
#if(CANTP_VERSION_INFO_API == STD_ON)  /*CANTP163 CANTP297*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_GetVersionInfo   SWS_CanTp_00210
*
* Description  : This function returns the version information of the CanTp
*                module.
*
* Inputs       : versionInfo: Indicator as to where to store the version infor-
*                              mation of this module.
*
* Outputs      : None.
*
* Limitations  : The function CanTp_GetVersionInfo shall be pre compile timef
*                configurable On or Off by the configuration parameter:CANTP_VE-
*                RSION_INFO_API.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANTP_CODE) CanTp_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CANTP_APPL_DATA) versioninfo
)
{
    if(NULL_PTR == versioninfo)
    {
        /*SWS_CanTp_00319*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_GETVERSIONINFO, CANTP_E_PARAM_POINTER);
    }
    else
    {
        versioninfo->vendorID = CANTP_VENDOR_ID;
        versioninfo->moduleID = CANTP_MODULE_ID;

        versioninfo->sw_major_version = CANTP_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = CANTP_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = CANTP_SW_PATCH_VERSION;
    }
}
#endif

#if(CANTP_TC == STD_ON)/*SWS_CanTp_00242*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_CancelTransmit  SWS_CanTp_00246 SWS_CanTp_00274
*
* Description  : This service is used to cancel the transmission of an N-SDU
*                that has already requested for transmission by calling CanTp_T-
*                ransmit service.
*
* Inputs       : CanTpTxSduId: This parameter contains the unique CanTp module
*                              identifier of the N-SDU to be cancelled for tran-
*                              smission.Range:0..(maximum number of L-PDU IDs t-
*                              ransmmited ) - 1.
*
* Outputs      : E_OK    : Cancellation request of the specified N-SDU is
*                          accepted.
*                E_NOT_OK: Cancellation request is rejected; the reason can be
*                          that request is issued for an N-SDU that is not segm-
*                          ented,request is issued after the last CF has been
*                          requested for transmission or cancellation is not
*                          possible for the related N-SDU due to configuration.
*
* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANTP_CODE) CanTp_CancelTransmit
(
    PduIdType CanTpTxSduId
)
{
    Std_ReturnType ret = E_NOT_OK;
    CanTp_ChannelIdType ChannelId;
    uint8 State;

    if(!CANTP_IS_INITIALIZED())
    {
        /*SWS_CanTp_00031*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_CANCELTRANSMIT, CANTP_E_UNINIT);
    }
    else if(CanTpTxSduId >= CANTP_NUM_TX_SDUS)
    {
        /*SWS_CanTp_00254*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_CANCELTRANSMIT, CANTP_E_PARAM_ID);
    }
    else
    {
        ChannelId = CANTP_TXTPCHANNEL_ID(CanTpTxSduId);
        State = CANTP_TX_CHANNEL_STATE(ChannelId);

        SchM_Enter_CanTp_CANTP_EXCLUSIVE_AREA_0();

        if( (State == CANTP_TXSTATE_IDLE) || (CANTP_TX_CHANNEL_CURID(ChannelId) != CanTpTxSduId) )
        {
            /*SWS_CanTp_00254*/
            CANTP_DET_REPORT_ERROR(CANTP_SID_CANCELTRANSMIT, CANTP_E_OPER_NOT_SUPPORTED);
        }
        else
        {
            /*SWS_CanTp_00256 SWS_CanTp_00243*/
            CanTp_TxChannelInit(ChannelId);
            /*SWS_CanTp_00255 SWS_CanTp_00177*/
            PduR_LoTpTxConfirmation(CANTP_CONFPDU_ID(CanTpTxSduId), E_NOT_OK);
            ret = E_OK;
        }

        SchM_Exit_CanTp_CANTP_EXCLUSIVE_AREA_0();
    }

    return ret;
}
#endif

#if(CANTP_RC == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_CancelReceive  SWS_CanTp_00257
*
* Description  : This service is used to cancel the reception of an ongoing N-SDU.
*
* Inputs       : CanTpRxSduId: Identifier of the received N-SDU.Range: 0..(maxi-
*                mum number of L-PDU IDs received ) - 1.
*
* Outputs      : E_OK    : Cancellation request of the specified N-SDU is
*                          accepted.
*                E_NOT_OK: Cancellation request is rejected; the reason can be
*                          that request is issued for an N-SDU that is not segm-
*                          ented,request is issued after the last CF has been
*                          requested for transmission or cancellation is not
*                          possible for the related N-SDU due to configuration.

* Limitations  : None.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANTP_CODE) CanTp_CancelReceive
(
    PduIdType CanTpRxSduId
)
{
    Std_ReturnType ret = E_NOT_OK;
    CanTp_ChannelIdType ChannelId;
    uint8 State;

    if(!CANTP_IS_INITIALIZED() )
    {
        /*SWS_CanTp_00031*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_MAINFUNCTION, CANTP_E_UNINIT);
    }
    else if(CanTpRxSduId >= CANTP_NUM_RX_SDUS)
    {
        /*SWS_CanTp_00260*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_CANCELRECEIVE, CANTP_E_PARAM_ID);
    }
    else
    {
        ChannelId = CANTP_RXTPCHANNEL_ID(CanTpRxSduId);
        State = CANTP_RX_CHANNEL_STATE(ChannelId);

        SchM_Enter_CanTp_CANTP_EXCLUSIVE_AREA_0();

        if( (State == CANTP_RXSTATE_IDLE) || (CANTP_RX_CHANNEL_CURID(ChannelId) != CanTpRxSduId) )
        {
            /*SWS_CanTp_00260*/
            CANTP_DET_REPORT_ERROR(CANTP_SID_CANCELRECEIVE, CANTP_E_OPER_NOT_SUPPORTED);
        }
        else
        {
            /*SWS_CanTp_00262*/
            /*SWS_CanTp_00261*/
            CanTp_RxChannelInit(ChannelId);
            /*SWS_CanTp_00263 SWS_CanTp_00084*/
            PduR_LoTpRxIndication(CANTP_UPPDU_ID(CanTpRxSduId), E_NOT_OK);
            ret = E_OK;
        }

        SchM_Exit_CanTp_CANTP_EXCLUSIVE_AREA_0();
    }

    return ret;
}
#endif

#if(STD_ON == CANTP_CHANGE_PARAMETER_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_ChangeParameter  SWS_CanTp_00302 SWS_CanTp_00091
*
* Description  : This service is used to request the change of reception
*                parameters BS and STmin for a specified N-SDU.

* Inputs       : id: Identifier of the received N-SDU on which the
*                            reception parameter has to be changed.
*                parameter : Specify the parameter to which the value has to be
*                            changed (BS or STmin).
*                value     : The new value of the parameter.
*
* Outputs      : E_OK    : request is accepted.
*                E_NOT_OK: request is not accepted.
*
* Limitations  : (CANTP303)A parameter change is only possible if the related
*                N-SDU is not in the process of reception , i.e. a change of
*                parameter value it is not possible after reception of FF until
*                indication for last CF reception of the related N-SDU.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANTP_CODE) CanTp_ChangeParameter
(
    PduIdType id,
    TPParameterType parameter,
    uint16 value
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduIdType ChannelId;

    if(!CANTP_IS_INITIALIZED() )
    {
        /*SWS_CanTp_00031*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_CHANGEPARAMETER, CANTP_E_UNINIT);
    }
    else if(id >= CANTP_NUM_RX_SDUS)
    {
        /*SWS_CanTp_00305*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_CHANGEPARAMETER, CANTP_E_PARAM_ID);
    }
    else if( (TP_STMIN != parameter) && (TP_BS != parameter) )
    {
        /*SWS_CanTp_00305*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_CHANGEPARAMETER, CANTP_E_PARAM_ID);
    }
    else
    {
        ChannelId = CANTP_RXTPCHANNEL_ID(id);

        if(CANTP_RX_CHANNEL_STATE(ChannelId) == CANTP_RXSTATE_IDLE)
        {
            /*SWS_CanTp_00303 SWS_CanTp_00304*/
            if(parameter == TP_BS)
            {
                if(value > CANTP_BSMAX)
                {
                    /*SWS_CanTp_00305*/
                    CANTP_DET_REPORT_ERROR(CANTP_SID_CHANGEPARAMETER, CANTP_E_PARAM_ID);
                }
                else
                {
                    CanTp_ParamInfo[id].CanTpBs = (uint8) value;
                    ret = E_OK;
                }

            }
            else /*TP_STMIN*/
            {
                CanTp_ParamInfo[id].CanTpSTmin = (uint8) value;
                ret = E_OK;
            }
        }
    }

    return ret;
}
#endif

#if(STD_ON == CANTP_READ_PARAMETER_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanTp_ReadParameter  SWS_CanTp_00323
*
* Description  : This service is used to read the current value of reception
*                parameters BS and STmin for a specified N-SDU.
*
* Inputs       : id: Identifier of the received N-SDU on which the
*                            reception parameter are read.
*                parameter : Specify the parameter to which the value has to be
*                            read (BS or STmin).
*                value     : Pointer where the parameter value will be provided
*
* Outputs      : E_OK    : request is accepted.
*                E_NOT_OK: request is not accepted.
*
* Limitations  : None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANTP_CODE) CanTp_ReadParameter
(
    PduIdType id,
    TPParameterType parameter,
    P2VAR(uint16, AUTOMATIC, CANTP_APPL_DATA) value
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!CANTP_IS_INITIALIZED() )
    {
        /*SWS_CanTp_00031*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_READPARAMETER, CANTP_E_UNINIT);
    }
    else if(id >= CANTP_NUM_RX_SDUS)
    {
        /*SWS_CanTp_00324*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_READPARAMETER, CANTP_E_PARAM_ID);
    }
    else if( (TP_BS != parameter) && (TP_STMIN != parameter) )
    {
        /*SWS_CanTp_00324*/
        CANTP_DET_REPORT_ERROR(CANTP_SID_READPARAMETER, CANTP_E_PARAM_ID);
    }
    else if(NULL_PTR == value)
    {
        CANTP_DET_REPORT_ERROR(CANTP_SID_READPARAMETER, CANTP_E_PARAM_POINTER);
    }
    else
    {
        if(parameter == TP_BS)
        {
            *value = CANTP_BS(id);
        }
        else /*TP_STMIN*/
        {
            *value = CANTP_STMIN(id);
        }

        ret = E_OK;
    }

    return ret;
}
#endif


#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"

