/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanIf_PBcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanIf module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanIf module configuration File
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
#include "CanIf.h"
#include "Can.h"

/*******************************************************************************
*   Config Parameters
*******************************************************************************/
#define CANIF_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "CanIf_MemMap.h"
#define CANIF_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "CanIf_MemMap.h"


#define CANIF_START_SEC_CONFIG_DATA
#include "CanIf_MemMap.h"
STATIC CONST(CanIf_HthCfgType, CANIF_CONST) CanIf_HthCfg_Cfg_D[7] =
{
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, 13},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, 14},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, 15},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, 16},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, 17},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, 18},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, 19}
};
STATIC CONST(CanIf_TxPduCfgType, CANIF_CONST) CanIf_TxPduCfg_Cfg_D[7] =
{
    /*0 Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6*/
    {
        (Can_IdType)0x1b6,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (Can_HwHandleType)1,/*HthRef*/
        (uint8)0,/*TxConfUL*/
        PduR_CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6,/*uplayyer handle*/
        TRUE,/*CanIfTxPduTruncation*/
    },
    /*1 Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF*/
    {
        (Can_IdType)0x1df,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (Can_HwHandleType)2,/*HthRef*/
        (uint8)0,/*TxConfUL*/
        PduR_CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF,/*uplayyer handle*/
        TRUE,/*CanIfTxPduTruncation*/
    },
    /*2 Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0*/
    {
        (Can_IdType)0x1e0,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (Can_HwHandleType)3,/*HthRef*/
        (uint8)0,/*TxConfUL*/
        PduR_CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0,/*uplayyer handle*/
        TRUE,/*CanIfTxPduTruncation*/
    },
    /*3 Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1*/
    {
        (Can_IdType)0x1e1,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (Can_HwHandleType)4,/*HthRef*/
        (uint8)0,/*TxConfUL*/
        PduR_CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1,/*uplayyer handle*/
        TRUE,/*CanIfTxPduTruncation*/
    },
    /*4 Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8*/
    {
        (Can_IdType)0x1e8,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (Can_HwHandleType)5,/*HthRef*/
        (uint8)0,/*TxConfUL*/
        PduR_CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8,/*uplayyer handle*/
        TRUE,/*CanIfTxPduTruncation*/
    },
    /*5 Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC*/
    {
        (Can_IdType)0x1ec,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (Can_HwHandleType)6,/*HthRef*/
        (uint8)0,/*TxConfUL*/
        PduR_CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC,/*uplayyer handle*/
        TRUE,/*CanIfTxPduTruncation*/
    },
    /*6 Cfg_D_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_D*/
    {
        (Can_IdType)0x6a3,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (Can_HwHandleType)0,/*HthRef*/
        (uint8)1,/*TxConfUL*/
        CanTp_CanIf_Cfg_D_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_D,/*uplayyer handle*/
        TRUE,/*CanIfTxPduTruncation*/
    }
};
STATIC CONST(CanIf_HrhCfgType, CANIF_CONST) CanIf_HrhCfg_Cfg_D[13] =
{
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)0, (PduIdType)0},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)1, (PduIdType)11},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)2, (PduIdType)12},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)3, (PduIdType)10},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)4, (PduIdType)1},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)5, (PduIdType)3},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)6, (PduIdType)6},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)7, (PduIdType)7},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)8, (PduIdType)8},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)9, (PduIdType)4},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)10, (PduIdType)5},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)11, (PduIdType)2},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)12, (PduIdType)9},
};
STATIC CONST(CanIf_RxPduCfgType, CANIF_CONST) CanIf_RxPduCfg_Cfg_D[13] =
{
    /*0 Cfg_D_Rx_BODY_LE1_CAN_BCU_11E*/
    {
        (Can_IdType)0x11e,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E,/*uplayyer handle*/
        (Can_HwHandleType)0/*hrhref*/
    },
    /*1 Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C*/
    {
        (Can_IdType)0x13c,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C,/*uplayyer handle*/
        (Can_HwHandleType)4/*hrhref*/
    },
    /*2 Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05*/
    {
        (Can_IdType)0x1b4,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05,/*uplayyer handle*/
        (Can_HwHandleType)11/*hrhref*/
    },
    /*3 Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9*/
    {
        (Can_IdType)0x1c9,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9,/*uplayyer handle*/
        (Can_HwHandleType)5/*hrhref*/
    },
    /*4 Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01*/
    {
        (Can_IdType)0x1d1,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01,/*uplayyer handle*/
        (Can_HwHandleType)9/*hrhref*/
    },
    /*5 Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02*/
    {
        (Can_IdType)0x1d2,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02,/*uplayyer handle*/
        (Can_HwHandleType)10/*hrhref*/
    },
    /*6 Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF*/
    {
        (Can_IdType)0x2ef,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF,/*uplayyer handle*/
        (Can_HwHandleType)6/*hrhref*/
    },
    /*7 Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9*/
    {
        (Can_IdType)0x3a9,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9,/*uplayyer handle*/
        (Can_HwHandleType)7/*hrhref*/
    },
    /*8 Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2*/
    {
        (Can_IdType)0x3b2,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2,/*uplayyer handle*/
        (Can_HwHandleType)8/*hrhref*/
    },
    /*9 Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC*/
    {
        (Can_IdType)0x4f7,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC,/*uplayyer handle*/
        (Can_HwHandleType)12/*hrhref*/
    },
    /*10 Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0*/
    {
        (Can_IdType)0x5e0,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0,/*uplayyer handle*/
        (Can_HwHandleType)3/*hrhref*/
    },
    /*11 Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU*/
    {
        (Can_IdType)0x601,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)1,/*RxIndUL*/
        CanTp_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU,/*uplayyer handle*/
        (Can_HwHandleType)1/*hrhref*/
    },
    /*12 Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_D*/
    {
        (Can_IdType)0x623,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)1,/*RxIndUL*/
        CanTp_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_D,/*uplayyer handle*/
        (Can_HwHandleType)2/*hrhref*/
    }
};
STATIC CONST(CanIf_HthCfgType, CANIF_CONST) CanIf_HthCfg_Cfg_P[7] =
{
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, 13},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, 14},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, 15},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, 16},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, 17},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, 18},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, 19}
};
STATIC CONST(CanIf_TxPduCfgType, CANIF_CONST) CanIf_TxPduCfg_Cfg_P[7] =
{
    /*0 Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7*/
    {
        (Can_IdType)0x1b7,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (Can_HwHandleType)1,/*HthRef*/
        (uint8)0,/*TxConfUL*/
        PduR_CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7,/*uplayyer handle*/
        TRUE,/*CanIfTxPduTruncation*/
    },
    /*1 Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2*/
    {
        (Can_IdType)0x1e2,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (Can_HwHandleType)2,/*HthRef*/
        (uint8)0,/*TxConfUL*/
        PduR_CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2,/*uplayyer handle*/
        TRUE,/*CanIfTxPduTruncation*/
    },
    /*2 Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3*/
    {
        (Can_IdType)0x1e3,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (Can_HwHandleType)3,/*HthRef*/
        (uint8)0,/*TxConfUL*/
        PduR_CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3,/*uplayyer handle*/
        TRUE,/*CanIfTxPduTruncation*/
    },
    /*3 Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4*/
    {
        (Can_IdType)0x1e4,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (Can_HwHandleType)4,/*HthRef*/
        (uint8)0,/*TxConfUL*/
        PduR_CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4,/*uplayyer handle*/
        TRUE,/*CanIfTxPduTruncation*/
    },
    /*4 Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB*/
    {
        (Can_IdType)0x1eb,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (Can_HwHandleType)5,/*HthRef*/
        (uint8)0,/*TxConfUL*/
        PduR_CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB,/*uplayyer handle*/
        TRUE,/*CanIfTxPduTruncation*/
    },
    /*5 Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED*/
    {
        (Can_IdType)0x1ed,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (Can_HwHandleType)6,/*HthRef*/
        (uint8)0,/*TxConfUL*/
        PduR_CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED,/*uplayyer handle*/
        TRUE,/*CanIfTxPduTruncation*/
    },
    /*6 Cfg_P_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_P*/
    {
        (Can_IdType)0x6a4,/*CanId*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        (Can_HwHandleType)0,/*HthRef*/
        (uint8)1,/*TxConfUL*/
        CanTp_CanIf_Cfg_P_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_P,/*uplayyer handle*/
        TRUE,/*CanIfTxPduTruncation*/
    }
};
STATIC CONST(CanIf_HrhCfgType, CANIF_CONST) CanIf_HrhCfg_Cfg_P[13] =
{
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)0, (PduIdType)0},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)1, (PduIdType)11},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)2, (PduIdType)12},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)3, (PduIdType)10},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)4, (PduIdType)1},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)5, (PduIdType)3},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)6, (PduIdType)6},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)7, (PduIdType)7},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)8, (PduIdType)8},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)9, (PduIdType)4},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)10, (PduIdType)5},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)11, (PduIdType)2},
    {CanIf_CanIf_BODY_LE1_CAN, TRUE, (Can_HwHandleType)12, (PduIdType)9},
};
STATIC CONST(CanIf_RxPduCfgType, CANIF_CONST) CanIf_RxPduCfg_Cfg_P[13] =
{
    /*0 Cfg_P_Rx_BODY_LE1_CAN_BCU_11E*/
    {
        (Can_IdType)0x11e,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E,/*uplayyer handle*/
        (Can_HwHandleType)0/*hrhref*/
    },
    /*1 Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C*/
    {
        (Can_IdType)0x13c,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C,/*uplayyer handle*/
        (Can_HwHandleType)4/*hrhref*/
    },
    /*2 Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06*/
    {
        (Can_IdType)0x1b5,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06,/*uplayyer handle*/
        (Can_HwHandleType)11/*hrhref*/
    },
    /*3 Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF*/
    {
        (Can_IdType)0x1cf,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF,/*uplayyer handle*/
        (Can_HwHandleType)5/*hrhref*/
    },
    /*4 Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03*/
    {
        (Can_IdType)0x1d3,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03,/*uplayyer handle*/
        (Can_HwHandleType)9/*hrhref*/
    },
    /*5 Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04*/
    {
        (Can_IdType)0x1d4,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04,/*uplayyer handle*/
        (Can_HwHandleType)10/*hrhref*/
    },
    /*6 Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF*/
    {
        (Can_IdType)0x2ef,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF,/*uplayyer handle*/
        (Can_HwHandleType)6/*hrhref*/
    },
    /*7 Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9*/
    {
        (Can_IdType)0x3a9,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9,/*uplayyer handle*/
        (Can_HwHandleType)7/*hrhref*/
    },
    /*8 Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2*/
    {
        (Can_IdType)0x3b2,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2,/*uplayyer handle*/
        (Can_HwHandleType)8/*hrhref*/
    },
    /*9 Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC*/
    {
        (Can_IdType)0x4f7,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC,/*uplayyer handle*/
        (Can_HwHandleType)12/*hrhref*/
    },
    /*10 Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0*/
    {
        (Can_IdType)0x5e0,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)0,/*RxIndUL*/
        PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0,/*uplayyer handle*/
        (Can_HwHandleType)3/*hrhref*/
    },
    /*11 Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU*/
    {
        (Can_IdType)0x601,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)1,/*RxIndUL*/
        CanTp_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU,/*uplayyer handle*/
        (Can_HwHandleType)1/*hrhref*/
    },
    /*12 Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_P*/
    {
        (Can_IdType)0x624,/*CanId*/
        (Can_IdType)0xc7ff,/*CanIdMask*/
        STANDARD_NO_FD_CAN,/*CanIdType*/
        (uint8)8,/*dlc*/
        COMSTACK_INVALID_PDUID,/*nextPduIndex*/
        FALSE,/*isRxDlcCheck*/
        (uint8)1,/*RxIndUL*/
        CanTp_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_P,/*uplayyer handle*/
        (Can_HwHandleType)2/*hrhref*/
    }
};
CONST(CanIf_ConfigType, CANIF_CONST) CanIf_InitCfgSet[2] =
{
    {
        (PduIdType)13,    /*NumOfRxPdu*/
        (PduIdType)7,    /*NumOfTxPdu*/
        (Can_HwHandleType)13,    /*NumOfHrh*/
        (Can_HwHandleType)7,    /*NumOfHth*/
        CanIf_TxPduCfg_Cfg_D,    /*TxPduCfg*/
        CanIf_RxPduCfg_Cfg_D,    /*RxPduCfg*/
        CanIf_HthCfg_Cfg_D,    /*HthCfg*/
        CanIf_HrhCfg_Cfg_D    /*HrhCfg*/
    },
    {
        (PduIdType)13,    /*NumOfRxPdu*/
        (PduIdType)7,    /*NumOfTxPdu*/
        (Can_HwHandleType)13,    /*NumOfHrh*/
        (Can_HwHandleType)7,    /*NumOfHth*/
        CanIf_TxPduCfg_Cfg_P,    /*TxPduCfg*/
        CanIf_RxPduCfg_Cfg_P,    /*RxPduCfg*/
        CanIf_HthCfg_Cfg_P,    /*HthCfg*/
        CanIf_HrhCfg_Cfg_P    /*HrhCfg*/
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA
#include "CanIf_MemMap.h"
