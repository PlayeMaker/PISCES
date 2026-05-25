/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : PduR_PBcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : PduR module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : PduR module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "PduR_PBcfg.h"
#include "CanIf.h"
#include "Com_Cbk.h"
#include "Dcm_Cbk.h"

#include "CanTp.h"

#define PDUR_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_STOP_SEC_CONFIG_DATA
#include "PduR_MemMap.h"

#define PDUR_START_SEC_VAR_CLEARED_GLOBAL_8
#include "PduR_MemMap.h"

VAR(boolean, PDUR_VAR) PduR_PathConf[PDUR_MAX_NUMPDURROUTPATH];
#define PDUR_STOP_SEC_VAR_CLEARED_GLOBAL_8
#include "PduR_MemMap.h"

#define PDUR_START_SEC_CONFIG_DATA
#include "PduR_MemMap.h"

/*******************************************************************************
*	ModuleFunctions
*******************************************************************************/
CONST(PduR_ModuleFunc, PDUR_CONST) PduR_ModuleFunctions[MODULE_NUM] =
{
    /*Com*/
    {
        NULL_PTR,/*IfCancelTransmitFunc;*/
        NULL_PTR,/*IfTransmitFunc;*/
        NULL_PTR,/*TpCancelReceiveFunc;*/
        NULL_PTR,/*TpCancelTransmitFunc;*/
        NULL_PTR,/*TpTransmitFunc;*/
        &Com_RxIndication,/*UpIfRxIndicationFunc;*/
        &Com_TriggerTransmit,/*UpIfTriggerTransmitFunc;*/
        &Com_TxConfirmation,/*UpIfTxConfirmationFunc;*/
        &Com_CopyRxData,/*UpTpCopyRxDataFunc;*/
        &Com_CopyTxData,/*UpTpCopyTxDataFunc;*/
        &Com_StartOfReception,/*UpTpStartOfReceptionFunc;*/
        &Com_TpRxIndication,/*UpTpRxIndicationFunc;*/
        &Com_TpTxConfirmation/*UpTpTxConfirmationFunc;*/
    },
    /*Dcm*/
    {
        NULL_PTR,/*IfCancelTransmitFunc;*/
        NULL_PTR,/*IfTransmitFunc;*/
        NULL_PTR,/*TpCancelReceiveFunc;*/
        NULL_PTR,/*TpCancelTransmitFunc;*/
        NULL_PTR,/*TpTransmitFunc;*/
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        &Dcm_TxConfirmation,/*UpIfTxConfirmationFunc;*/
        &Dcm_CopyRxData,/*UpTpCopyRxDataFunc;*/
        &Dcm_CopyTxData,/*UpTpCopyTxDataFunc;*/
        &Dcm_StartOfReception,/*UpTpStartOfReceptionFunc;*/
        &Dcm_TpRxIndication,/*UpTpRxIndicationFunc;*/
        &Dcm_TpTxConfirmation/*UpTpTxConfirmationFunc;*/
    },
    /*CanIf*/
    {
        NULL_PTR,/*IfCancelTransmitFunc;*/
        &CanIf_Transmit,/*IfTransmitFunc;*/
        NULL_PTR,/*TpCancelReceiveFunc;*/
        NULL_PTR,/*TpCancelTransmitFunc;*/
        NULL_PTR,/*TpTransmitFunc;*/
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    },
    /*CanTp*/
    {
        NULL_PTR,/*IfCancelTransmitFunc;*/
        NULL_PTR,/*IfTransmitFunc;*/
        NULL_PTR,/*TpCancelReceiveFunc;*/
        NULL_PTR,/*TpCancelTransmitFunc;*/
        &CanTp_Transmit,/*TpTransmitFunc;*/
        NULL_PTR,/*UpIfRxIndicationFunc;*/
        NULL_PTR,/*UpIfTriggerTransmitFunc;*/
        NULL_PTR,/*UpIfTxConfirmationFunc;*/
        NULL_PTR,/*UpTpCopyRxDataFunc;*/
        NULL_PTR,/*UpTpCopyTxDataFunc;*/
        NULL_PTR,/*UpTpStartOfReceptionFunc;*/
        NULL_PTR,/*UpTpRxIndicationFunc;*/
        NULL_PTR/*UpTpTxConfirmationFunc;*/
    }
};

/*******************************************************************************
*	PduRRoutingTable 
*******************************************************************************/
STATIC CONST(PduRRoutingPathInfoType, PDUR_CONST) PduRRoutingTable_0[PDUR_NUMPDURROUTPATH_0] =
{
    /*0*/
    {
        {PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E, (PduR_RoutingPathIdType)0, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*1*/
    {
        {PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C, (PduR_RoutingPathIdType)1, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*2*/
    {
        {PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05, (PduR_RoutingPathIdType)2, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*3*/
    {
        {PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9, (PduR_RoutingPathIdType)3, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*4*/
    {
        {PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01, (PduR_RoutingPathIdType)4, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*5*/
    {
        {PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02, (PduR_RoutingPathIdType)5, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*6*/
    {
        {PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF, (PduR_RoutingPathIdType)6, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*7*/
    {
        {PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9, (PduR_RoutingPathIdType)7, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*8*/
    {
        {PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2, (PduR_RoutingPathIdType)8, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*9*/
    {
        {PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC, (PduR_RoutingPathIdType)9, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*10*/
    {
        {PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0, (PduR_RoutingPathIdType)10, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*11*/
    {
        {PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6, MODULE_COM, (uint8)0},
        {CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6, (PduR_RoutingPathIdType)11, MODULE_CANIF, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*12*/
    {
        {PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF, MODULE_COM, (uint8)0},
        {CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF, (PduR_RoutingPathIdType)12, MODULE_CANIF, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*13*/
    {
        {PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0, MODULE_COM, (uint8)0},
        {CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0, (PduR_RoutingPathIdType)13, MODULE_CANIF, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*14*/
    {
        {PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1, MODULE_COM, (uint8)0},
        {CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1, (PduR_RoutingPathIdType)14, MODULE_CANIF, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*15*/
    {
        {PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8, MODULE_COM, (uint8)0},
        {CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8, (PduR_RoutingPathIdType)15, MODULE_CANIF, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*16*/
    {
        {PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC, MODULE_COM, (uint8)0},
        {CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC, (PduR_RoutingPathIdType)16, MODULE_CANIF, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*17*/
    {
        {PduR_CanTp_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU, MODULE_CANTP, (uint8)0},
        {Dcm_PduR_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU, (PduR_RoutingPathIdType)17, MODULE_DCM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*18*/
    {
        {PduR_CanTp_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_D, MODULE_CANTP, (uint8)0},
        {Dcm_PduR_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_D, (PduR_RoutingPathIdType)18, MODULE_DCM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*19*/
    {
        {PduR_Dcm_Cfg_D_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_D, MODULE_DCM, (uint8)0},
        {CanTp_PduR_Cfg_D_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_D, (PduR_RoutingPathIdType)19, MODULE_CANTP, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

};

STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_0_0[1]={(PduR_RoutingPathIdType)11};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_0_1[1]={(PduR_RoutingPathIdType)12};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_0_2[1]={(PduR_RoutingPathIdType)13};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_0_3[1]={(PduR_RoutingPathIdType)14};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_0_4[1]={(PduR_RoutingPathIdType)15};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_0_5[1]={(PduR_RoutingPathIdType)16};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxDcmSrc_0_0[1]={(PduR_RoutingPathIdType)19};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_0_0[1]={(PduR_RoutingPathIdType)0};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_0_1[1]={(PduR_RoutingPathIdType)1};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_0_2[1]={(PduR_RoutingPathIdType)2};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_0_3[1]={(PduR_RoutingPathIdType)3};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_0_4[1]={(PduR_RoutingPathIdType)4};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_0_5[1]={(PduR_RoutingPathIdType)5};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_0_6[1]={(PduR_RoutingPathIdType)6};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_0_7[1]={(PduR_RoutingPathIdType)7};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_0_8[1]={(PduR_RoutingPathIdType)8};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_0_9[1]={(PduR_RoutingPathIdType)9};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_0_10[1]={(PduR_RoutingPathIdType)10};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanTpSrc_0_0[1]={(PduR_RoutingPathIdType)17};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanTpSrc_0_1[1]={(PduR_RoutingPathIdType)18};

/*******************************************************************************
*	PduRInfoTable 
*******************************************************************************/
STATIC CONST(PduRRoutingPduInfoType, PDUR_CONST) PduRTxPduInfo_0[7] =
{
    {(PduR_RoutingPathIdType)1,PduR_TblIdxComSrc_0_0, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxComSrc_0_1, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxComSrc_0_2, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxComSrc_0_3, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxComSrc_0_4, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxComSrc_0_5, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxDcmSrc_0_0, (PduR_MulticastMaskType)0x1}
};

STATIC CONST(PduRRoutingPduInfoType, PDUR_CONST) PduRRxPduInfo_0[13] =
{
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_0_0, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_0_1, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_0_2, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_0_3, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_0_4, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_0_5, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_0_6, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_0_7, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_0_8, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_0_9, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_0_10, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanTpSrc_0_0, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanTpSrc_0_1, (PduR_MulticastMaskType)0x1}
};

STATIC CONST(PduRTxConfMapping_Type, PDUR_CONST) PduRTxConfPduInfo_0[7] =
{
    {(PduR_RoutingPathIdType)11,Com_PduR_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6},
    {(PduR_RoutingPathIdType)12,Com_PduR_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF},
    {(PduR_RoutingPathIdType)13,Com_PduR_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0},
    {(PduR_RoutingPathIdType)14,Com_PduR_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1},
    {(PduR_RoutingPathIdType)15,Com_PduR_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8},
    {(PduR_RoutingPathIdType)16,Com_PduR_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC},
    {(PduR_RoutingPathIdType)19,Dcm_PduR_Cfg_D_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_D}
};

STATIC CONST(PduRRxCancelMapping_Type, PDUR_CONST) PduRCancelRxPduInfo_0[2] =
{
    {(PduR_RoutingPathIdType)17},
    {(PduR_RoutingPathIdType)18}
};

#define PDUR_STOP_SEC_CONFIG_DATA
#include "PduR_MemMap.h"


/*******************************************************************************
*	PduRRoutingPathGroup 
*******************************************************************************/

#define PDUR_START_SEC_CONFIG_DATA
#include "PduR_MemMap.h"

/*PDUR329_Conf*/
STATIC CONST(boolean, PDUR_CONST) PduR_RPGroupEnabledAtInit_0[PDUR_NUMOFROUTINGPATHGROUP_0] = {TRUE};
#define PDUR_STOP_SEC_CONFIG_DATA
#include "PduR_MemMap.h"

#define PDUR_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "PduR_MemMap.h"

#define PDUR_STOP_SEC_CONFIG_DATA
#include "PduR_MemMap.h"

#define PDUR_START_SEC_CONFIG_DATA
#include "PduR_MemMap.h"

/*******************************************************************************
*	PduRRoutingTable 
*******************************************************************************/
STATIC CONST(PduRRoutingPathInfoType, PDUR_CONST) PduRRoutingTable_1[PDUR_NUMPDURROUTPATH_1] =
{
    /*0*/
    {
        {PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E, (PduR_RoutingPathIdType)0, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*1*/
    {
        {PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C, (PduR_RoutingPathIdType)1, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*2*/
    {
        {PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06, (PduR_RoutingPathIdType)2, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*3*/
    {
        {PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF, (PduR_RoutingPathIdType)3, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*4*/
    {
        {PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03, (PduR_RoutingPathIdType)4, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*5*/
    {
        {PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04, (PduR_RoutingPathIdType)5, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*6*/
    {
        {PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF, (PduR_RoutingPathIdType)6, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*7*/
    {
        {PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9, (PduR_RoutingPathIdType)7, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*8*/
    {
        {PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2, (PduR_RoutingPathIdType)8, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*9*/
    {
        {PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC, (PduR_RoutingPathIdType)9, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*10*/
    {
        {PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0, MODULE_CANIF, (uint8)0},
        {Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0, (PduR_RoutingPathIdType)10, MODULE_COM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*11*/
    {
        {PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7, MODULE_COM, (uint8)0},
        {CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7, (PduR_RoutingPathIdType)11, MODULE_CANIF, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*12*/
    {
        {PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2, MODULE_COM, (uint8)0},
        {CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2, (PduR_RoutingPathIdType)12, MODULE_CANIF, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*13*/
    {
        {PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3, MODULE_COM, (uint8)0},
        {CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3, (PduR_RoutingPathIdType)13, MODULE_CANIF, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*14*/
    {
        {PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4, MODULE_COM, (uint8)0},
        {CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4, (PduR_RoutingPathIdType)14, MODULE_CANIF, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*15*/
    {
        {PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB, MODULE_COM, (uint8)0},
        {CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB, (PduR_RoutingPathIdType)15, MODULE_CANIF, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*16*/
    {
        {PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED, MODULE_COM, (uint8)0},
        {CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED, (PduR_RoutingPathIdType)16, MODULE_CANIF, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*17*/
    {
        {PduR_CanTp_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU, MODULE_CANTP, (uint8)0},
        {Dcm_PduR_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU, (PduR_RoutingPathIdType)17, MODULE_DCM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*18*/
    {
        {PduR_CanTp_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_P, MODULE_CANTP, (uint8)0},
        {Dcm_PduR_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_P, (PduR_RoutingPathIdType)18, MODULE_DCM, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

    /*19*/
    {
        {PduR_Dcm_Cfg_P_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_P, MODULE_DCM, (uint8)0},
        {CanTp_PduR_Cfg_P_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_P, (PduR_RoutingPathIdType)19, MODULE_CANTP, (PduLengthType)8, PDUR_DIRECT, (uint16)7, PDUR_TPGW_TRIGGER_IND, PDUR_RPGROUP_NONE},
        (PduR_MulticastMaskType)0x1
    },

};

STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_1_0[1]={(PduR_RoutingPathIdType)11};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_1_1[1]={(PduR_RoutingPathIdType)12};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_1_2[1]={(PduR_RoutingPathIdType)13};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_1_3[1]={(PduR_RoutingPathIdType)14};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_1_4[1]={(PduR_RoutingPathIdType)15};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxComSrc_1_5[1]={(PduR_RoutingPathIdType)16};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxDcmSrc_1_0[1]={(PduR_RoutingPathIdType)19};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_1_0[1]={(PduR_RoutingPathIdType)0};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_1_1[1]={(PduR_RoutingPathIdType)1};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_1_2[1]={(PduR_RoutingPathIdType)2};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_1_3[1]={(PduR_RoutingPathIdType)3};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_1_4[1]={(PduR_RoutingPathIdType)4};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_1_5[1]={(PduR_RoutingPathIdType)5};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_1_6[1]={(PduR_RoutingPathIdType)6};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_1_7[1]={(PduR_RoutingPathIdType)7};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_1_8[1]={(PduR_RoutingPathIdType)8};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_1_9[1]={(PduR_RoutingPathIdType)9};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanIfSrc_1_10[1]={(PduR_RoutingPathIdType)10};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanTpSrc_1_0[1]={(PduR_RoutingPathIdType)17};
STATIC CONST(PduR_RoutingPathIdType, PDUR_CONST) PduR_TblIdxCanTpSrc_1_1[1]={(PduR_RoutingPathIdType)18};

/*******************************************************************************
*	PduRInfoTable 
*******************************************************************************/
STATIC CONST(PduRRoutingPduInfoType, PDUR_CONST) PduRTxPduInfo_1[7] =
{
    {(PduR_RoutingPathIdType)1,PduR_TblIdxComSrc_1_0, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxComSrc_1_1, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxComSrc_1_2, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxComSrc_1_3, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxComSrc_1_4, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxComSrc_1_5, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxDcmSrc_1_0, (PduR_MulticastMaskType)0x1}
};

STATIC CONST(PduRRoutingPduInfoType, PDUR_CONST) PduRRxPduInfo_1[13] =
{
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_1_0, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_1_1, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_1_2, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_1_3, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_1_4, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_1_5, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_1_6, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_1_7, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_1_8, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_1_9, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanIfSrc_1_10, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanTpSrc_1_0, (PduR_MulticastMaskType)0x1},
    {(PduR_RoutingPathIdType)1,PduR_TblIdxCanTpSrc_1_1, (PduR_MulticastMaskType)0x1}
};

STATIC CONST(PduRTxConfMapping_Type, PDUR_CONST) PduRTxConfPduInfo_1[7] =
{
    {(PduR_RoutingPathIdType)11,Com_PduR_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7},
    {(PduR_RoutingPathIdType)12,Com_PduR_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2},
    {(PduR_RoutingPathIdType)13,Com_PduR_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3},
    {(PduR_RoutingPathIdType)14,Com_PduR_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4},
    {(PduR_RoutingPathIdType)15,Com_PduR_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB},
    {(PduR_RoutingPathIdType)16,Com_PduR_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED},
    {(PduR_RoutingPathIdType)19,Dcm_PduR_Cfg_P_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_P}
};

STATIC CONST(PduRRxCancelMapping_Type, PDUR_CONST) PduRCancelRxPduInfo_1[2] =
{
    {(PduR_RoutingPathIdType)17},
    {(PduR_RoutingPathIdType)18}
};

#define PDUR_STOP_SEC_CONFIG_DATA
#include "PduR_MemMap.h"


/*******************************************************************************
*	PduRRoutingPathGroup 
*******************************************************************************/

#define PDUR_START_SEC_CONFIG_DATA
#include "PduR_MemMap.h"

/*PDUR329_Conf*/
STATIC CONST(boolean, PDUR_CONST) PduR_RPGroupEnabledAtInit_1[PDUR_NUMOFROUTINGPATHGROUP_1] = {TRUE};
#define PDUR_STOP_SEC_CONFIG_DATA
#include "PduR_MemMap.h"

#define PDUR_START_SEC_CONFIG_DATA
#include "PduR_MemMap.h"


CONST(PduR_PBConfigType, PDUR_CONST) PduR_PBCfg_0 =
{
    (uint8)7,/*TxPduInfoNum*/
    (uint8)13,/*RxPduInfoNum*/
    (uint8)7,/*TxPduTxConfNum*/
    (uint8)2,/*RxPduCancelNum*/
    (uint8)0,/*PBConfigId*/
    PDUR_NUMPDURROUTPATH_0,/*RoutingPathNum*/
    PduRRoutingTable_0,/*pRoutingTbl*/
    PDUR_NUMOFROUTINGPATHGROUP_0,/*RoutingPathGroupNum*/
    PduR_RPGroupEnabledAtInit_0,/*RPGroupEnabledAtInit*/
    PduRTxPduInfo_0,/*TxPduInfo*/
    PduRRxPduInfo_0,/*RxPduInfo*/
    PduRTxConfPduInfo_0,/*TxConfPduInfo*/
    PduRCancelRxPduInfo_0/*CancelRxPduInfo*/
};
CONST(PduR_PBConfigType, PDUR_CONST) PduR_PBCfg_1 =
{
    (uint8)7,/*TxPduInfoNum*/
    (uint8)13,/*RxPduInfoNum*/
    (uint8)7,/*TxPduTxConfNum*/
    (uint8)2,/*RxPduCancelNum*/
    (uint8)1,/*PBConfigId*/
    PDUR_NUMPDURROUTPATH_1,/*RoutingPathNum*/
    PduRRoutingTable_1,/*pRoutingTbl*/
    PDUR_NUMOFROUTINGPATHGROUP_1,/*RoutingPathGroupNum*/
    PduR_RPGroupEnabledAtInit_1,/*RPGroupEnabledAtInit*/
    PduRTxPduInfo_1,/*TxPduInfo*/
    PduRRxPduInfo_1,/*RxPduInfo*/
    PduRTxConfPduInfo_1,/*TxConfPduInfo*/
    PduRCancelRxPduInfo_1/*CancelRxPduInfo*/
};
#define PDUR_STOP_SEC_CONFIG_DATA
#include "PduR_MemMap.h"



