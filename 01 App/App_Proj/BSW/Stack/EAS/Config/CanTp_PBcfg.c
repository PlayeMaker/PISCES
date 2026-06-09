/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanTp_PBcfg.c
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
/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 0862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address 
segments in the files of each module,#include "CanTp_MemMap.h" is required.Defined 
XXX_START_SEC_ will undefine in CanTp_MemMap.h

*/
/*PRQA S 0553 EOF*/
/*
Particularity of configuration files,the file can be void in some situations.
*/
/*PRQA S 857 EOF*/
/*
Macro definitions exceed 1024.The number of macros is unlimited
*/


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanTp_PBcfg.h"
#include "CanIf.h"
#include "PduR.h"
#define CANTP_START_SEC_CONFIG_DATA
#include "CanTp_MemMap.h"

#define CANTP_STOP_SEC_CONFIG_DATA
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CONFIG_DATA
#include "CanTp_MemMap.h"


/*******************************************************************************
*   RxNsdu
*******************************************************************************/
/*Cfg_D*/
STATIC CONST(CanTp_RxNsduCfgType, CANTP_CONST) CanTp_RxNsduPBCfg0[CANTP_NUM_RX_SDUS_0] =
{
    /* NSDU ID 0:RxNSdu_DIAG_REQ_MCM_D */
    {
        (CanTp_ChannelIdType)0,    /* Tp Channel Num */
        CanTp_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_D,    /* CANTP_RXNPDU_ID; from  CanIf */
        CanIf_Cfg_D_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_D,    /* CANTP_TXFC_NPDU_ID; to CanIf */
        PduR_CanTp_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_D,    /* to PduR */
        (uint16)100,    /* CANTP_NAR */
        (uint16)6,    /* CANTP_NBR (N_Br+N_Ar) < 0.9*N_Bs */
        (uint16)100,    /* CANTP_NCR */
        (uint8)0,    /* CANTP_BS */
        (uint8)20,    /* CANTP_STMIN */
        (uint8)0,    /* CANTP_WFTMAX */
        (PduLengthType)8,
        CANTP_PHYSICAL,    
    },
    /* NSDU ID 1:RxNSdu_DIAG_REQ_AllECU */
    {
        (CanTp_ChannelIdType)1,    /* Tp Channel Num */
        CanTp_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU,    /* CANTP_RXNPDU_ID; from  CanIf */
        COMSTACK_INVALID_PDUID,    /* CANTP_TXFC_NPDU_ID; to CanIf */
        PduR_CanTp_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU,    /* to PduR */
        (uint16)100,    /* CANTP_NAR */
        (uint16)6,    /* CANTP_NBR (N_Br+N_Ar) < 0.9*N_Bs */
        (uint16)100,    /* CANTP_NCR */
        (uint8)0,    /* CANTP_BS */
        (uint8)20,    /* CANTP_STMIN */
        (uint8)0,    /* CANTP_WFTMAX */
        (PduLengthType)8,
        CANTP_FUNCTIONAL,    
    }
};

/*Cfg_P*/
STATIC CONST(CanTp_RxNsduCfgType, CANTP_CONST) CanTp_RxNsduPBCfg1[CANTP_NUM_RX_SDUS_1] =
{
    /* NSDU ID 0:RxNSdu_DIAG_REQ_MCM_P */
    {
        (CanTp_ChannelIdType)0,    /* Tp Channel Num */
        CanTp_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_P,    /* CANTP_RXNPDU_ID; from  CanIf */
        CanIf_Cfg_P_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_P,    /* CANTP_TXFC_NPDU_ID; to CanIf */
        PduR_CanTp_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_P,    /* to PduR */
        (uint16)100,    /* CANTP_NAR */
        (uint16)6,    /* CANTP_NBR (N_Br+N_Ar) < 0.9*N_Bs */
        (uint16)100,    /* CANTP_NCR */
        (uint8)0,    /* CANTP_BS */
        (uint8)20,    /* CANTP_STMIN */
        (uint8)0,    /* CANTP_WFTMAX */
        (PduLengthType)8,
        CANTP_PHYSICAL,    
    },
    /* NSDU ID 1:RxNSdu_DIAG_REQ_AllECU */
    {
        (CanTp_ChannelIdType)1,    /* Tp Channel Num */
        CanTp_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU,    /* CANTP_RXNPDU_ID; from  CanIf */
        COMSTACK_INVALID_PDUID,    /* CANTP_TXFC_NPDU_ID; to CanIf */
        PduR_CanTp_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU,    /* to PduR */
        (uint16)100,    /* CANTP_NAR */
        (uint16)6,    /* CANTP_NBR (N_Br+N_Ar) < 0.9*N_Bs */
        (uint16)100,    /* CANTP_NCR */
        (uint8)0,    /* CANTP_BS */
        (uint8)20,    /* CANTP_STMIN */
        (uint8)0,    /* CANTP_WFTMAX */
        (PduLengthType)8,
        CANTP_FUNCTIONAL,    
    }
};



/*******************************************************************************
*   TxNsdu
*******************************************************************************/
/*Cfg_D*/
STATIC CONST(CanTp_TxNsduCfgType, CANTP_CONST) CanTp_TxNsduPBCfg0[CANTP_NUM_TX_SDUS_0] =
{
    /* NSDU ID 0:TxNSdu_DIAG_RESP_MCM_D */
    {
        (CanTp_ChannelIdType)0,    /* Tp Channel Num */
        CanIf_Cfg_D_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_D,    /*  CANTP_TXNPDU_ID; to CanIf and conf from CanIf */
        CanTp_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_D,    /* CANTP_RXFC_NPDU_ID; from CanIf */
        PduR_CanTp_Cfg_D_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_D,    /* to PduR*/
        (uint16)100,    /* CANTP_NAS */
        (uint16)100,    /* CANTP_NBS (N_Br+N_Ar) < 0.9*N_Bs */
        (uint16)6,    /* CANTP_NCS */
        (PduLengthType)8, 
        CANTP_PHYSICAL,    
    }
};


/*Cfg_P*/
STATIC CONST(CanTp_TxNsduCfgType, CANTP_CONST) CanTp_TxNsduPBCfg1[CANTP_NUM_TX_SDUS_1] =
{
    /* NSDU ID 0:TxNSdu_DIAG_RESP_MCM_P */
    {
        (CanTp_ChannelIdType)0,    /* Tp Channel Num */
        CanIf_Cfg_P_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_P,    /*  CANTP_TXNPDU_ID; to CanIf and conf from CanIf */
        CanTp_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_P,    /* CANTP_RXFC_NPDU_ID; from CanIf */
        PduR_CanTp_Cfg_P_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_P,    /* to PduR*/
        (uint16)100,    /* CANTP_NAS */
        (uint16)100,    /* CANTP_NBS (N_Br+N_Ar) < 0.9*N_Bs */
        (uint16)6,    /* CANTP_NCS */
        (PduLengthType)8, 
        CANTP_PHYSICAL,    
    }
};




/*******************************************************************************
*   CanTp Channel Mode
*******************************************************************************/
CONST(CanTp_ConfigType, CANTP_CONST) CanTp_PBcfg[2] =
{
    {
        10,
        CANTP_CHANNELS_0,
        CANTP_CHANNELS_0,
        CANTP_CHANNELS_0,
        CANTP_NUM_RX_SDUS_0,
        CANTP_NUM_TX_SDUS_0,
        CanTp_RxNsduPBCfg0,
        CanTp_TxNsduPBCfg0,
    },
    {
        10,
        CANTP_CHANNELS_1,
        CANTP_CHANNELS_1,
        CANTP_CHANNELS_1,
        CANTP_NUM_RX_SDUS_1,
        CANTP_NUM_TX_SDUS_1,
        CanTp_RxNsduPBCfg1,
        CanTp_TxNsduPBCfg1,
    }
};



/*******************************************************************************
*   MutliCoreSupport
*******************************************************************************/
#define CANTP_STOP_SEC_CONFIG_DATA
#include "CanTp_MemMap.h"




