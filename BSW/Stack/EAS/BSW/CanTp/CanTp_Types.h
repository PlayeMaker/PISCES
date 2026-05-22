/*  BEGIN_FILE_HDR
********************************************************************************
*     NOTICE
*     This software is the property of HiRain Technologies. Any information
*     contained in this doc should not be reproduced, or used, or disclosed
*     without the written authorization from HiRain Technologies.
********************************************************************************
*     File Name         : CanTp_Types.h
********************************************************************************
*     Project/Product : AUTOSAR R21-11
*     Title             : CanTp_Types.h
*     Author          : Hirain
********************************************************************************
*     Description     : The header file CanTp_Types.h contains the declaration of
*                       types which is used by the CanTp module
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
#ifndef CANTP_TYPES_H
#define CANTP_TYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanTp_Cfg.h"

#if(STD_ON == CANTP_CANFD_SUPPORT)
#define CANTP_MAX_FRAME_LENGTH            ((PduLengthType)64)   /* CAN frame max length*/
#else
#define CANTP_MAX_FRAME_LENGTH            ((PduLengthType)8)    /* CAN frame max length*/
#endif

typedef enum
{
    CANTP_MODE_HALF_DUPLEX = 0,
    CANTP_MODE_FULL_DUPLEX = 1
} CanTp_ChannelModeType;

/*SWS_CanTp_00027*/
typedef enum
{
    CANTP_OFF = 0,
    CANTP_ON = 1
} CanTp_InitStatusType;

typedef enum
{
    CANTP_STANDARD = 0,
    CANTP_EXTENDED = 1,
    CANTP_MIXED = 2,
    CANTP_MIXED29BIT = 3,
    CANTP_NORMALFIXED = 4
} CanTp_AddressingFormatType;

typedef enum
{
    CANTP_PHYSICAL = 0,
    CANTP_FUNCTIONAL = 1,
    CANTP_CANFD_PHYSICAL = 2,
    CANTP_CANFD_FUNCTIONAL = 3
} CanTp_TaType;

typedef struct
{
    uint8 CanTpBs;
    uint8 CanTpSTmin;
} CanTp_ChangeParType;


/*ECUC_CanTp_00137*/
typedef struct /*RxNsdu(ROM)*/
{
    CanTp_ChannelIdType CanTpChannelId;
    PduIdType      CanTpRxNPduId;    /*ECUC_CanTp_00258*//* from CanIf */
    PduIdType      CanTpTxFcNPduId;  /*ECUC_CanTp_00287*//* to   CanIf */
    PduIdType      UpperLayerPduId;  /*to PduR */
    uint16         CanTpNar;       /*ECUC_CanTp_00277*/
    uint16         CanTpNbr;       /*ECUC_CanTp_00245*/
    uint16         CanTpNcr;       /*ECUC_CanTp_00279*/
    uint8          CanTpBs;        /*ECUC_CanTp_00276*/
    uint8          CanTpSTmin;     /*ECUC_CanTp_00252*/
    uint8          CanTpRxWftMax;  /*ECUC_CanTp_00251*/
	PduLengthType  MaxCanLen;
#if(CANTP_RXSDU_PADDING_MODE == CANTP_SDU_PADDING_VARIES)
    boolean        CanTpRxPaddingActive;    /*ECUC_CanTp_00249*/
#endif
    CanTp_TaType   CanTpRxTaType;  /*ECUC_CanTp_00250*/
#if(CANTP_RX_NAI_ADDRESSING == STD_ON)
    CanTp_AddressingFormatType   CanTpRxAddrFormat;  /*ECUC_CanTp_00281*/
    PduLengthType  CanTpNPciOffset;
    uint8          CanTpRxNAe;       /*ECUC_CanTp_00285*/
    uint8          CanTpRxNSa;       /*ECUC_CanTp_00254*/
    uint8          CanTpRxNTa;       /*ECUC_CanTp_00255*/
#endif
} CanTp_RxNsduCfgType;


/*ECUC_CanTp_00138*/
typedef struct /*TxNsdu(ROM)*/
{
    CanTp_ChannelIdType CanTpChannelId;
    PduIdType      CanTpTxNPduId;    /*ECUC_CanTp_00286*//* to CanIf and conf from CanIf */
    PduIdType      CanTpRxFcNPduId;  /*ECUC_CanTp_00273*//* from CanIf */
    PduIdType      UpperLayerPduId;  /*to PduR*/
    uint16         CanTpNas;        /*ECUC_CanTp_00263*/
    uint16         CanTpNbs;        /*ECUC_CanTp_00264*/
    uint16         CanTpNcs;        /*ECUC_CanTp_00265*/
    PduLengthType  MaxCanLen;
#if(CANTP_TXSDU_PADDING_MODE == CANTP_SDU_PADDING_VARIES)
    boolean        CanTpTxPaddingActive;    /*ECUC_CanTp_00269*/
#endif
    CanTp_TaType   CanTpTxTaType;   /*ECUC_CanTp_00270*/
#if(CANTP_TX_NAI_ADDRESSING == STD_ON)
    CanTp_AddressingFormatType  CanTpTxAddrFormat;  /*ECUC_CanTp_00262*/
    PduLengthType  CanTpNPciOffset;
    uint8          CanTpTxNAe;     /*ECUC_CanTp_00285*/
    uint8          CanTpTxNSa;     /*ECUC_CanTp_00254*/
    uint8          CanTpTxNTa;     /*ECUC_CanTp_00255*/
#endif
} CanTp_TxNsduCfgType;


/*SWS_CanTp_00340*/
typedef struct /* Struct to hold the Post-Build CanTp-configuration */
{
#if(CANTP_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    uint8 CanTpMainFunctionPeriod;
    CONST (CanTp_ChannelIdType, TYPEDEF) CanTp_ChannelNum;  /*max of CanTp_RxChannelNum and CanTp_TxChannelNum*/
    CONST (CanTp_ChannelIdType, TYPEDEF) CanTp_RxChannelNum;
    CONST (CanTp_ChannelIdType, TYPEDEF) CanTp_TxChannelNum;
    CONST (PduIdType, TYPEDEF) CanTp_RxNsduNum;
    CONST (PduIdType, TYPEDEF) CanTp_TxNsduNum;
#if(CANTP_DUPLEX_MODE == CANTP_CHANNEL_DUPLEX_VARIES)
    CONSTP2CONST (CanTp_ChannelModeType, CANTP_CONST, TYPEDEF) CanTp_ChannelMode;
#endif
#endif
    CONSTP2CONST (CanTp_RxNsduCfgType, CANTP_CONST, TYPEDEF) CanTp_RxNsduCfg;
    CONSTP2CONST (CanTp_TxNsduCfgType, CANTP_CONST, TYPEDEF) CanTp_TxNsduCfg;
} CanTp_ConfigType;

typedef struct
{
    PduIdType     CurrentRxSduId;
    PduLengthType DataLength;
    PduLengthType NextBlockLen;
    uint16        Timer;
    uint8         ChannelState;/* activation status */
    uint8         WFTCounter;
    uint8         BlockSizeCounter;  /* actual values */
    uint8         FlowStatus;
    uint8         ExpectedSN;
    PduLengthType FFCanDlc;
} CanTp_RxStateType;

typedef struct
{
    PduIdType     CurrentTxNSduId;
    PduLengthType DataLength;
    uint16        Timer;
    uint8         ChannelState;
    uint8         BlockSizeCounter;
    uint8         STMin;
    uint8         SeqNumber;
#if(CANTP_CAR_PLATFORM == CANTP_NISSAN_PLATFORM)
    boolean       FirstFCFlag;
    uint8         FixedBlockSize;
#endif
} CanTp_TxStateType;


#endif /* CANTP_TYPES_H */

