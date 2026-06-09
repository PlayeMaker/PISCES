/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanIf_Cfg.h
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
/*PRQA S 791,792 EOF*/
/*
Names generated in configuration files may not follow relevant rules..
*/
#ifndef CANIF_CFG_H
#define CANIF_CFG_H

/*******************************************************************************
*   Common Macro
*******************************************************************************/
#define CANIF_FILTER_TYPE_DICH                              1
#define CANIF_FILTER_TYPE_INDEX                             2
#define CANIF_FILTER_TYPE_LINEAR                            3
#define CANIF_FILTER_TYPE_TABLE                             4
/* CanIf Dlc Check Type*/
#define CANIF_DLC_CHECK_AUTOSAR                             0
#define CANIF_DLC_CHECK_USER                                1
/*******************************************************************************
*   Non Autosar Standard
*******************************************************************************/
#define CANIF_CONFIG_VARIANTS                               STD_CONFIG_VARIANTS_POSTBUILD
#define CANIF_MAX_CONTROLLER_NUM                            1
#define CANIF_MAX_TRCV_NUM                                  0
#define CANIF_MAX_TXPDU_NUM                                 7
#define CANIF_MAX_RXPDU_NUM                                 13
#define CANIF_MAX_HTH_NUM                                   7
#define CANIF_MAX_HRH_NUM                                   13
#define CANIF_MAX_TXBUF_NUM                                 0
#define CANIF_MAX_DYNTXPDU_NUM                              0
#define CANIF_MAX_TXNOTIFY_NUM                              0
#define CANIF_MAX_RXBUF_NUM                                 0
#define CANIF_MAX_RXNOTIFY_NUM                              0
#define CANIF_MAX_TXTRIGGER_NUM                             0

#define CANIF_DLC_CHECK_TYPE                                CANIF_DLC_CHECK_AUTOSAR
#define CANIF_HRH_RANGE_FILTER_SUPPORT                      STD_OFF
#define CANIF_PRIVATE_VERSION_CHECK                         STD_ON
#define CANIF_HOH_OPTIMIZE_SUPPORT                          STD_OFF
#define CANIF_PUBLIC_MULTIPLE_TRCVDRV_SUPPORT               STD_OFF
#define CANIF_PRIVATE_CANFD_SUPPORT                         STD_OFF
#define CANIF_BUS_MIRRORING_SUPPORT                         STD_OFF

#define CANIF_CAN_VERSION_NEWER_THAN_422                    STD_ON
#define CANIF_SW_MAJOR_VERSION_CFG                          4
#define CANIF_SW_MINOR_VERSION_CFG                          2
#define CANIF_SW_PATCH_VERSION_CFG                          0
#define CANIF_AR_RELEASE_MAJOR_VERSION_CFG                  4
#define CANIF_AR_RELEASE_MINOR_VERSION_CFG                  7
#define CANIF_AR_RELEASE_REVISION_VERSION_CFG               0
/*******************************************************************************
*   CanIfPrivateCfg
*******************************************************************************/
#define CANIF_PRIVATE_DLC_CHECK                             STD_ON
#define CANIF_PRIVATE_SOFTWARE_FILTER_TYPE                  CANIF_FILTER_TYPE_INDEX
#define CANIF_SUPPORT_TTCAN                                 STD_OFF
#define CANIF_FIXED_BUFFER                                  STD_ON
#define CANIF_OSEKNM_SUPPORT                                STD_OFF
#define CANIF_PRIVATE_SWTXFIFO_SUPPORT                      STD_OFF
#define CANIF_PRIVATE_SWTXFIFO_DEBUG                        STD_OFF
#define CANIF_PRIVATE_SWTXFIFO_RETRY                        STD_OFF
#define CANIF_PRIVATE_SWTXFIFO_TXTIMEOUT_VAL                3
/*******************************************************************************
*   CanIfPublicCfg
*******************************************************************************/
#define CANIF_METADATA_SUPPORT                              STD_OFF
#define CANIF_SET_BAUDRATE_API                              STD_OFF
#define CANIF_PUBLIC_DEV_ERROR_DETECT                       STD_OFF
#define CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT                   STD_OFF
#define CANIF_PUBLIC_NUMBER_OF_CAN_HW_UNITS                 1
#define CANIF_PUBLIC_READRXPDU_DATA_API                     STD_OFF
#define CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API            STD_OFF
#define CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API            STD_OFF
#define CANIF_PUBLIC_SETDYNAMICTXID_API                     STD_OFF
#define CANIF_PUBLIC_TX_BUFFERING                           STD_OFF
#define CANIF_PUBLIC_VERSION_INFO_API                       STD_ON
#define CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT        STD_OFF
#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_CALLOUT          STD_OFF
#define CANIF_PUBLIC_PN_SUPPORT                             STD_OFF
#define CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT              STD_ON
#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM               STD_OFF
#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_OSEKNM           STD_OFF
#define CANIF_PUBLIC_ICOM_SUPPORT                           STD_OFF
#define CANIF_TRIGGER_TRANSMIT_SUPPORT                      STD_OFF
#define CANIF_TXOFF_ACTIVE_SUPPORT                          STD_OFF
#define CANIF_WAKEUP_SUPPORT                                STD_OFF
#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_PNNM             STD_OFF
/*******************************************************************************
*   ConfigSet handle
*******************************************************************************/
#define CanIf_Cfg_D                                         ((uint8)0)
#define CanIf_Cfg_P                                         ((uint8)1)
/*******************************************************************************
*   CanIfTxPduCfg
*******************************************************************************/
/*Cfg_D*/
#define CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6               ((PduIdType)0)
#define CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF               ((PduIdType)1)
#define CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0               ((PduIdType)2)
#define CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1               ((PduIdType)3)
#define CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8               ((PduIdType)4)
#define CanIf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC               ((PduIdType)5)
#define CanIf_Cfg_D_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_D         ((PduIdType)6)
/*Cfg_P*/
#define CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7               ((PduIdType)0)
#define CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2               ((PduIdType)1)
#define CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3               ((PduIdType)2)
#define CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4               ((PduIdType)3)
#define CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB               ((PduIdType)4)
#define CanIf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED               ((PduIdType)5)
#define CanIf_Cfg_P_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_P         ((PduIdType)6)
/*******************************************************************************
*   CanIfRxPduCfg
*******************************************************************************/
/*Cfg_D*/
#define CanIf_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E                 ((PduIdType)0)
#define CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C                ((PduIdType)1)
#define CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05             ((PduIdType)2)
#define CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9                ((PduIdType)3)
#define CanIf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01          ((PduIdType)4)
#define CanIf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02          ((PduIdType)5)
#define CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF                ((PduIdType)6)
#define CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9                ((PduIdType)7)
#define CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2                ((PduIdType)8)
#define CanIf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC                ((PduIdType)9)
#define CanIf_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0             ((PduIdType)10)
#define CanIf_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU         ((PduIdType)11)
#define CanIf_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_D          ((PduIdType)12)
/*Cfg_P*/
#define CanIf_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E                 ((PduIdType)0)
#define CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C                ((PduIdType)1)
#define CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06             ((PduIdType)2)
#define CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF                ((PduIdType)3)
#define CanIf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03          ((PduIdType)4)
#define CanIf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04          ((PduIdType)5)
#define CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF                ((PduIdType)6)
#define CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9                ((PduIdType)7)
#define CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2                ((PduIdType)8)
#define CanIf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC                ((PduIdType)9)
#define CanIf_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0             ((PduIdType)10)
#define CanIf_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU         ((PduIdType)11)
#define CanIf_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_P          ((PduIdType)12)
/*******************************************************************************
*   CanIfCtrl Trcv Cfg
*******************************************************************************/
#define CANIF_CTRL_WAKEUP_SUPPORT                           STD_OFF
#define CANIF_TRCV_WAKEUP_SUPPORT                           STD_OFF
/*Ctrl Handles*/
#define CanIf_CanIf_BODY_LE1_CAN                            ((uint8)0)
/*Trcv Handles*/
/*******************************************************************************
*   Access macro
*******************************************************************************/

#endif /* CANIF_CFG_H */


