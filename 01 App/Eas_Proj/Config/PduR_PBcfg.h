/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : PduR_PBcfg.h
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
/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 776 EOF*/
/*
Names in core files may not follow relevant rules.
*/

#ifndef PDUR_PBCFG_H
#define PDUR_PBCFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "PduR_Types.h"

#define MODULE_COM                                          ((uint8)0)
#define MODULE_DCM                                          ((uint8)1)
#define MODULE_CANIF                                        ((uint8)2)
#define MODULE_CANTP                                        ((uint8)3)
#define MODULE_NUM                                          ((uint8)4)

/*Cfg_D*/

#define PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6            ((PduIdType)0)
#define PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF            ((PduIdType)1)
#define PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0            ((PduIdType)2)
#define PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1            ((PduIdType)3)
#define PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8            ((PduIdType)4)
#define PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC            ((PduIdType)5)
#define PduR_Dcm_Cfg_D_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_D      ((PduIdType)6)

#define PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E            ((PduIdType)0)
#define PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C           ((PduIdType)1)
#define PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05        ((PduIdType)2)
#define PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9           ((PduIdType)3)
#define PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01     ((PduIdType)4)
#define PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02     ((PduIdType)5)
#define PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF           ((PduIdType)6)
#define PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9           ((PduIdType)7)
#define PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2           ((PduIdType)8)
#define PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC           ((PduIdType)9)
#define PduR_CanIf_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0        ((PduIdType)10)
#define PduR_CanTp_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU    ((PduIdType)11)
#define PduR_CanTp_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_D     ((PduIdType)12)

#define PduR_CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6          ((PduIdType)0)
#define PduR_CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF          ((PduIdType)1)
#define PduR_CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0          ((PduIdType)2)
#define PduR_CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1          ((PduIdType)3)
#define PduR_CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8          ((PduIdType)4)
#define PduR_CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC          ((PduIdType)5)
#define PduR_CanTp_Cfg_D_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_D    ((PduIdType)6)


#define PDUR_NUMPDURROUTPATH_0                              (20)


#define PDUR_NUMOFROUTINGPATHGROUP_0                        (1)
#define PDUR_NUMOFBUFFER_0                                  (0)


/*Cfg_P*/

#define PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7            ((PduIdType)0)
#define PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2            ((PduIdType)1)
#define PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3            ((PduIdType)2)
#define PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4            ((PduIdType)3)
#define PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB            ((PduIdType)4)
#define PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED            ((PduIdType)5)
#define PduR_Dcm_Cfg_P_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_P      ((PduIdType)6)

#define PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E            ((PduIdType)0)
#define PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C           ((PduIdType)1)
#define PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06        ((PduIdType)2)
#define PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF           ((PduIdType)3)
#define PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03     ((PduIdType)4)
#define PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04     ((PduIdType)5)
#define PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF           ((PduIdType)6)
#define PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9           ((PduIdType)7)
#define PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2           ((PduIdType)8)
#define PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC           ((PduIdType)9)
#define PduR_CanIf_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0        ((PduIdType)10)
#define PduR_CanTp_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU    ((PduIdType)11)
#define PduR_CanTp_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_P     ((PduIdType)12)

#define PduR_CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7          ((PduIdType)0)
#define PduR_CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2          ((PduIdType)1)
#define PduR_CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3          ((PduIdType)2)
#define PduR_CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4          ((PduIdType)3)
#define PduR_CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB          ((PduIdType)4)
#define PduR_CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED          ((PduIdType)5)
#define PduR_CanTp_Cfg_P_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_P    ((PduIdType)6)


#define PDUR_NUMPDURROUTPATH_1                              (20)


#define PDUR_NUMOFROUTINGPATHGROUP_1                        (1)
#define PDUR_NUMOFBUFFER_1                                  (0)

#define PDUR_MAX_NUMPDURROUTPATH                            PDUR_NUMPDURROUTPATH_1
#define PDUR_MAX_NUMOFROUTINGPATHGROUP                      PDUR_NUMOFROUTINGPATHGROUP_1
#define PDUR_MAX_NUMOFBUFFER                                PDUR_NUMOFBUFFER_1
#define PDUR_MAX_TXCONF_PDU                                 7
#define PDUR_MAX_TX_PDU_INFO                                7
#define PDUR_MAX_RX_PDU_INFO                                13
#define PDUR_MAX_CANCELRX_PDU                               2
#define PDUR_MULTICORE_SUPPORT                              STD_OFF
#define PDUR_MAX_CORE_NUM                                   1
#define PDUR_GET_CORE_ID()                                  GetCoreID()

#define PDUR_START_SEC_CONFIG_DATA
#include "PduR_MemMap.h"

extern CONST(PduR_PBConfigType, PDUR_CONST) PduR_PBCfg_0;

extern CONST(PduR_PBConfigType, PDUR_CONST) PduR_PBCfg_1;

extern CONST(PduR_ModuleFunc, PDUR_CONST) PduR_ModuleFunctions[MODULE_NUM];
#define PDUR_STOP_SEC_CONFIG_DATA
#include "PduR_MemMap.h"



#define PDUR_START_SEC_VAR_CLEARED_GLOBAL_8
#include "PduR_MemMap.h"

extern VAR(boolean, PDUR_VAR) PduR_PathConf[PDUR_MAX_NUMPDURROUTPATH];

#define PDUR_STOP_SEC_VAR_CLEARED_GLOBAL_8
#include "PduR_MemMap.h"


#endif


