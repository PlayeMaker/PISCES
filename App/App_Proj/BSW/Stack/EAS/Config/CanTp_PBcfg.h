/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanTp_PBcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanTp module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanTp module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/
#ifndef CANTP_PBCFG_H
#define CANTP_PBCFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanTp_Types.h"

#define CANTP_MAIN_FUNCTION_PERIOD                          (CanTp_ConfigSet->CanTpMainFunctionPeriod)
#define CANTP_CHANNELS                                      (CanTp_ConfigSet->CanTp_ChannelNum)
#define CANTP_NUM_RX_CHANNELS                               (CanTp_ConfigSet->CanTp_RxChannelNum)
#define CANTP_NUM_TX_CHANNELS                               (CanTp_ConfigSet->CanTp_TxChannelNum)
#define CANTP_NUM_RX_SDUS                                   (CanTp_ConfigSet->CanTp_RxNsduNum)
#define CANTP_NUM_TX_SDUS                                   (CanTp_ConfigSet->CanTp_TxNsduNum)
#define CANTP_RXNSDUINFO(RxSduId)                           (CanTp_ConfigSet->CanTp_RxNsduCfg[RxSduId])
#define CANTP_TXNSDUINFO(TxSduId)                           (CanTp_ConfigSet->CanTp_TxNsduCfg[TxSduId])

/* Maximum number of Channels supported by the CanTp on this ECU */
#define CANTP_MAX_CHANNEL_NUM                               (2)
#define CANTP_MAX_NUM_RX_CHANNELS                           ((PduIdType)CANTP_MAX_CHANNEL_NUM)
#define CANTP_MAX_NUM_TX_CHANNELS                           ((PduIdType)CANTP_MAX_CHANNEL_NUM)
#define CANTP_MAX_NUM_RX_SDUS                               ((PduIdType)2)
#define CANTP_MAX_NUM_TX_SDUS                               ((PduIdType)1)

#define CANTP_CHANNELS_0                                    (2)
#define CANTP_NUM_RX_SDUS_0                                 ((PduIdType)2)
#define CANTP_NUM_TX_SDUS_0                                 ((PduIdType)1)

#define CANTP_CHANNELS_1                                    (2)
#define CANTP_NUM_RX_SDUS_1                                 ((PduIdType)2)
#define CANTP_NUM_TX_SDUS_1                                 ((PduIdType)1)


/*TxNPdu*/
/*Cfg_D*/
#define CanTp_CanIf_Cfg_D_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_D   CanIf_Cfg_D_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_D
/*Cfg_P*/
#define CanTp_CanIf_Cfg_P_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_P   CanIf_Cfg_P_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_P

/*RxNPdu*/
/*Cfg_D*/
#define CanTp_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_D          ((PduIdType)0)
#define CanTp_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU         ((PduIdType)1)
/*Cfg_P*/
#define CanTp_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_P          ((PduIdType)0)
#define CanTp_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU         ((PduIdType)1)

/*TxNSdu*/
/*Cfg_D*/
#define CanTp_PduR_Cfg_D_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_D    ((PduIdType)0)
/*Cfg_P*/
#define CanTp_PduR_Cfg_P_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_P    ((PduIdType)0)

/*RxNSdu*/
/*Cfg_D*/
#define CanTp_PduR_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_D     ((PduIdType)0)
#define CanTp_PduR_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU    ((PduIdType)1)
/*Cfg_P*/
#define CanTp_PduR_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_P     ((PduIdType)0)
#define CanTp_PduR_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU    ((PduIdType)1)

#define CANTP_START_SEC_CONFIG_DATA
#include "CanTp_MemMap.h"

extern CONST(CanTp_ConfigType, CANTP_CONST) CanTp_PBcfg[2];

#define CANTP_STOP_SEC_CONFIG_DATA
#include "CanTp_MemMap.h"


#endif /* CANTP_PBCFG_H */


