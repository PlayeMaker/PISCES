/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Com_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Com module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Com module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/
#ifndef COM_CFG_H
#define COM_CFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#define COM_CONFIG_VARIANTS                                 STD_CONFIG_VARIANTS_POSTBUILD
#define COM_DEV_ERROR_DETECT                                STD_ON
#define COM_CANCEL_SUPPORT                                  STD_ON
#define COM_MDT_CYCLIC_TRANSMISSION                         STD_ON
#define COM_RETRY_TRANSMIT_REQUESTS                         STD_OFF
#define COM_Enable_SignalGroupArrayApi                      STD_OFF
#define COM_MetaDataSupport                                 STD_OFF
#define COM_PUBLIC_VERSION_INFO_API                         STD_OFF
#define COM_PADDING_SUPPORT                                 STD_OFF
#define COM_GROUP_API_R3_SUPPORT                            STD_ON

/*******************************************************************************
*   EasSpecal
*******************************************************************************/
#define COM_IPDU_GROUP_FUN                                  STD_ON
#define COM_GW_FUN                                          STD_OFF
#define COM_TriggerIPDUSend_API                             STD_OFF
#define COM_TX_TRIGGER_CALLOUT_SUPPORT                      STD_OFF
#define COM_TX_TP_RETRYINFO_SUPPORT                         STD_OFF
#define COM_RXPDU_FUN                                       STD_ON
#define COM_TXPDU_FUN                                       STD_ON
#define COM_RX_LONG_PDU_FUN                                 STD_OFF
#define COM_TX_LONG_PDU_FUN                                 STD_OFF
#define COM_RXIPDU_CALLOUT                                  STD_OFF
#define COM_TXIPDU_CALLOUT                                  STD_OFF
#define COM_RX_TIMEOUT_MONITOR                              STD_ON
#define COM_TX_TIMEOUT_MONITOR                              STD_OFF
#define COM_RX_FILTER_SUPPORT                               STD_OFF
#define COM_TX_FILTER_SUPPORT                               STD_OFF
#define COM_RX_DIRECT_COPY                                  STD_ON
#define COM_RX_DYN_PDU_SUPPORT                              STD_OFF
#define COM_TX_DYN_PDU_SUPPORT                              STD_OFF
#define COM_TXMODE_NONE                                     STD_OFF
#define COM_TXMODE_PERIODIC                                 STD_ON
#define COM_TXMODE_DIRECT                                   STD_OFF
#define COM_TXMODE_MIXED                                    STD_OFF
#define COM_TXMODE_REPTITION                                STD_OFF
#define COM_TXMODE_PERIODIC_ONLY                            STD_ON
#define COM_FIRST_HANDLE_MIXED                              STD_OFF
#define COM_SECOND_HANDLE_MIXED                             STD_OFF
#define COM_TX_SIGNAL_GROUP_SUPPORT                         STD_OFF
#define COM_TX_UPDATEBIT_SUPPORT                            STD_OFF
#define COM_RX_SIGNAL_GROUP_SUPPORT                         STD_OFF
#define COM_RX_UPDATEBIT_SUPPORT                            STD_OFF
#define COM_TX_INVALID_SUPPORT                              STD_OFF
#define COM_RX_INVALID_SUPPORT                              STD_OFF
#define COM_TXSIG_ON_CHANGE_SUPPORT                         STD_OFF
#define COM_TX_U8N_SUPPORT                                  STD_OFF
#define COM_RX_U8N_SUPPORT                                  STD_OFF
#define COM_MULTI_CORE_SUPPORT                              STD_OFF
#define COM_TXMODE_IFACTIVE_SUPPORT                         STD_OFF
#define COM_MULTI_CORE_GW_SUPPORT                           STD_OFF
#define COM_TX_IMMEDIATE_SUPPORT                            STD_OFF
#define COM_RX_IMMEDIATE_SUPPORT                            STD_OFF
#define COM_RX_TIMEOUT_ACTION_SUPPORT                       STD_OFF
#define COM_RX_TIMEOUT_PDU_CBK_SUPPORT                      STD_ON
#define COM_SUPPORT_BIG_ENDIAN                              STD_ON
#define COM_SUPPORT_LITTLE_ENDIAN                           STD_OFF
#define COM_TX_UB_CLEAR_DELAY_SUPPORT                       STD_OFF
#define COM_TX_CONFIRMATION_CALLOUT_SUPPORT                 STD_OFF
#define COM_RX_INDICATION_CALLOUT_SUPPORT                   STD_OFF
#define COM_DEM_EVENT_SET_SUPPORT                           STD_OFF
#define COM_TX_SIGNAL_ACK_FUNC_SUPPORT                      STD_ON
#define COM_TX_SIGNAL_ERR_FUNC_SUPPORT                      STD_OFF
#define COM_RX_SIGNAL_SUBSTITUTE_SUPPORT                    STD_OFF
#define COM_RX_SIGNAL_UB_TIMEOUT_SUPPORT                    STD_OFF
#define COM_TX_E2E_TRIGGER_CALLOUT_SUPPORT                  STD_OFF

/* generate tool's version*/
#define COM_VERSION_CHECK                                   STD_ON
#define COM_SW_MAJOR_VERSION_CFG                            4
#define COM_SW_MINOR_VERSION_CFG                            2
#define COM_SW_PATCH_VERSION_CFG                            0
#define COM_AR_RELEASE_MAJOR_VERSION_CFG                    4
#define COM_AR_RELEASE_MINOR_VERSION_CFG                    7
#define COM_AR_RELEASE_REVISION_VERSION_CFG                 0
#define COM_RXPDU_MAX_NUM                                   (11)
#define COM_RXSIG_MAX_NUM                                   (135)

#define COM_TXPDU_MAX_NUM                                   (6)
#define COM_TXSIG_MAX_NUM                                   (66)

#define COM_PDUGROUP_MAX_NUM                                (2)

#define COM_GWSIG_MAX_NUM                                   (0)
#define COM_MAX_FILTER_OCCURRENCE_NUM                       (0)
#define COM_MAX_RX_UPDATEBIT_NUM                            (0)

/*******************************************************************************
*   Handles of RX PDU ID
*******************************************************************************/
/*Cfg_D*/
#define Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E              ((PduIdType)0)
#define Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C             ((PduIdType)1)
#define Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05          ((PduIdType)2)
#define Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9             ((PduIdType)3)
#define Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01       ((PduIdType)4)
#define Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02       ((PduIdType)5)
#define Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF             ((PduIdType)6)
#define Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9             ((PduIdType)7)
#define Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2             ((PduIdType)8)
#define Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC             ((PduIdType)9)
#define Com_PduR_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0          ((PduIdType)10)
/*Cfg_P*/
#define Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E              ((PduIdType)0)
#define Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C             ((PduIdType)1)
#define Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06          ((PduIdType)2)
#define Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF             ((PduIdType)3)
#define Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03       ((PduIdType)4)
#define Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04       ((PduIdType)5)
#define Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF             ((PduIdType)6)
#define Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9             ((PduIdType)7)
#define Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2             ((PduIdType)8)
#define Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC             ((PduIdType)9)
#define Com_PduR_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0          ((PduIdType)10)

/*******************************************************************************
*   Handles of RX signals
*******************************************************************************/
/*Cfg_D*/
#define Com_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1   ((Com_SignalIdType)0)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1      ((Com_SignalIdType)1)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC     ((Com_SignalIdType)2)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr ((Com_SignalIdType)3)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts       ((Com_SignalIdType)4)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts  ((Com_SignalIdType)5)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts    ((Com_SignalIdType)6)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState         ((Com_SignalIdType)7)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState    ((Com_SignalIdType)8)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed ((Com_SignalIdType)9)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef       ((Com_SignalIdType)10)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd5        ((Com_SignalIdType)11)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd5         ((Com_SignalIdType)12)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd5 ((Com_SignalIdType)13)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd6 ((Com_SignalIdType)14)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd7 ((Com_SignalIdType)15)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd8 ((Com_SignalIdType)16)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd6        ((Com_SignalIdType)17)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd6         ((Com_SignalIdType)18)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd7        ((Com_SignalIdType)19)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd7         ((Com_SignalIdType)20)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd8        ((Com_SignalIdType)21)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd8         ((Com_SignalIdType)22)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd9        ((Com_SignalIdType)23)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd9         ((Com_SignalIdType)24)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd9 ((Com_SignalIdType)25)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd10          ((Com_SignalIdType)26)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd10        ((Com_SignalIdType)27)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd10       ((Com_SignalIdType)28)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat1_pct     ((Com_SignalIdType)29)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat2_pct     ((Com_SignalIdType)30)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat3_pct     ((Com_SignalIdType)31)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat4_pct     ((Com_SignalIdType)32)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat5_pct     ((Com_SignalIdType)33)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat6_pct     ((Com_SignalIdType)34)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve1Cmd          ((Com_SignalIdType)35)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve2Cmd          ((Com_SignalIdType)36)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve3Cmd          ((Com_SignalIdType)37)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve4Cmd          ((Com_SignalIdType)38)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve5Cmd          ((Com_SignalIdType)39)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve6Cmd          ((Com_SignalIdType)40)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve7Cmd          ((Com_SignalIdType)41)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve8Cmd          ((Com_SignalIdType)42)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve9Cmd          ((Com_SignalIdType)43)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve10Cmd         ((Com_SignalIdType)44)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve11Cmd         ((Com_SignalIdType)45)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve12Cmd         ((Com_SignalIdType)46)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat1Cmd ((Com_SignalIdType)47)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat2Cmd ((Com_SignalIdType)48)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat3Cmd ((Com_SignalIdType)49)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat4Cmd ((Com_SignalIdType)50)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat5Cmd ((Com_SignalIdType)51)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat6Cmd ((Com_SignalIdType)52)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat7Cmd ((Com_SignalIdType)53)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat8Cmd ((Com_SignalIdType)54)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat9Cmd ((Com_SignalIdType)55)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat10Cmd          ((Com_SignalIdType)56)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat11Cmd          ((Com_SignalIdType)57)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat12Cmd          ((Com_SignalIdType)58)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarTopValue1Cmd      ((Com_SignalIdType)59)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarMidValue2Cmd      ((Com_SignalIdType)60)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarBottomValue3Cmd   ((Com_SignalIdType)61)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBLCmd       ((Com_SignalIdType)62)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBRCmd       ((Com_SignalIdType)63)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue6Cmd        ((Com_SignalIdType)64)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue5Cmd        ((Com_SignalIdType)65)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue4Cmd        ((Com_SignalIdType)66)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvPumpCmd ((Com_SignalIdType)67)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueLCmd          ((Com_SignalIdType)68)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueMCmd          ((Com_SignalIdType)69)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue2Cmd        ((Com_SignalIdType)70)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueRCmd          ((Com_SignalIdType)71)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue3Cmd        ((Com_SignalIdType)72)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue1Cmd        ((Com_SignalIdType)73)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR    ((Com_SignalIdType)74)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer      ((Com_SignalIdType)75)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Yr               ((Com_SignalIdType)76)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Mth              ((Com_SignalIdType)77)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Day              ((Com_SignalIdType)78)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Hr               ((Com_SignalIdType)79)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Min              ((Com_SignalIdType)80)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Sec              ((Com_SignalIdType)81)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_MSec             ((Com_SignalIdType)82)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT          ((Com_SignalIdType)83)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts         ((Com_SignalIdType)84)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts         ((Com_SignalIdType)85)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts         ((Com_SignalIdType)86)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts         ((Com_SignalIdType)87)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts         ((Com_SignalIdType)88)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts         ((Com_SignalIdType)89)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts         ((Com_SignalIdType)90)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts         ((Com_SignalIdType)91)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts         ((Com_SignalIdType)92)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts        ((Com_SignalIdType)93)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts        ((Com_SignalIdType)94)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts        ((Com_SignalIdType)95)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts        ((Com_SignalIdType)96)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts        ((Com_SignalIdType)97)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts        ((Com_SignalIdType)98)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts        ((Com_SignalIdType)99)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts        ((Com_SignalIdType)100)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts        ((Com_SignalIdType)101)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts        ((Com_SignalIdType)102)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts        ((Com_SignalIdType)103)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts        ((Com_SignalIdType)104)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts        ((Com_SignalIdType)105)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts        ((Com_SignalIdType)106)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts        ((Com_SignalIdType)107)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts        ((Com_SignalIdType)108)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts        ((Com_SignalIdType)109)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts        ((Com_SignalIdType)110)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts        ((Com_SignalIdType)111)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts        ((Com_SignalIdType)112)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts        ((Com_SignalIdType)113)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts        ((Com_SignalIdType)114)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts        ((Com_SignalIdType)115)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts        ((Com_SignalIdType)116)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts        ((Com_SignalIdType)117)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts        ((Com_SignalIdType)118)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts        ((Com_SignalIdType)119)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts        ((Com_SignalIdType)120)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts        ((Com_SignalIdType)121)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts        ((Com_SignalIdType)122)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts        ((Com_SignalIdType)123)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts        ((Com_SignalIdType)124)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts        ((Com_SignalIdType)125)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts        ((Com_SignalIdType)126)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts        ((Com_SignalIdType)127)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts        ((Com_SignalIdType)128)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts        ((Com_SignalIdType)129)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts        ((Com_SignalIdType)130)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts        ((Com_SignalIdType)131)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC         ((Com_SignalIdType)132)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr     ((Com_SignalIdType)133)
#define Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload     ((Com_SignalIdType)134)
/*Cfg_P*/
#define Com_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1   ((Com_SignalIdType)0)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1      ((Com_SignalIdType)1)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC     ((Com_SignalIdType)2)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr ((Com_SignalIdType)3)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts       ((Com_SignalIdType)4)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts  ((Com_SignalIdType)5)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts    ((Com_SignalIdType)6)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState         ((Com_SignalIdType)7)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState    ((Com_SignalIdType)8)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed ((Com_SignalIdType)9)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef       ((Com_SignalIdType)10)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd5       ((Com_SignalIdType)11)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd5        ((Com_SignalIdType)12)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd5          ((Com_SignalIdType)13)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd6          ((Com_SignalIdType)14)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd7          ((Com_SignalIdType)15)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd8          ((Com_SignalIdType)16)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd6       ((Com_SignalIdType)17)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd6        ((Com_SignalIdType)18)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd7       ((Com_SignalIdType)19)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd7        ((Com_SignalIdType)20)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd8       ((Com_SignalIdType)21)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd8        ((Com_SignalIdType)22)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd9       ((Com_SignalIdType)23)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd9        ((Com_SignalIdType)24)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd10      ((Com_SignalIdType)25)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd10       ((Com_SignalIdType)26)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd9          ((Com_SignalIdType)27)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd10         ((Com_SignalIdType)28)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat1_pct    ((Com_SignalIdType)29)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat2_pct    ((Com_SignalIdType)30)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat3_pct    ((Com_SignalIdType)31)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat4_pct    ((Com_SignalIdType)32)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat5_pct    ((Com_SignalIdType)33)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat6_pct    ((Com_SignalIdType)34)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve1Cmd         ((Com_SignalIdType)35)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve2Cmd         ((Com_SignalIdType)36)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve3Cmd         ((Com_SignalIdType)37)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve4Cmd         ((Com_SignalIdType)38)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve5Cmd         ((Com_SignalIdType)39)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve6Cmd         ((Com_SignalIdType)40)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve7Cmd         ((Com_SignalIdType)41)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve8Cmd         ((Com_SignalIdType)42)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve9Cmd         ((Com_SignalIdType)43)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve10Cmd        ((Com_SignalIdType)44)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve11Cmd        ((Com_SignalIdType)45)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve12Cmd        ((Com_SignalIdType)46)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat1Cmd          ((Com_SignalIdType)47)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat2Cmd          ((Com_SignalIdType)48)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat3Cmd          ((Com_SignalIdType)49)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat4Cmd          ((Com_SignalIdType)50)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat5Cmd          ((Com_SignalIdType)51)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat6Cmd          ((Com_SignalIdType)52)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat7Cmd          ((Com_SignalIdType)53)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat8Cmd          ((Com_SignalIdType)54)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat9Cmd          ((Com_SignalIdType)55)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat10Cmd         ((Com_SignalIdType)56)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat11Cmd         ((Com_SignalIdType)57)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat12Cmd         ((Com_SignalIdType)58)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarTopValue1Cmd     ((Com_SignalIdType)59)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarMidValue2Cmd     ((Com_SignalIdType)60)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarBottomValue3Cmd  ((Com_SignalIdType)61)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBLCmd      ((Com_SignalIdType)62)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBRCmd      ((Com_SignalIdType)63)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue6Cmd       ((Com_SignalIdType)64)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue5Cmd       ((Com_SignalIdType)65)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue4Cmd       ((Com_SignalIdType)66)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassPumpCmd          ((Com_SignalIdType)67)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueLCmd         ((Com_SignalIdType)68)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueMCmd         ((Com_SignalIdType)69)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueRCmd         ((Com_SignalIdType)70)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue2Cmd       ((Com_SignalIdType)71)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue3Cmd       ((Com_SignalIdType)72)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue1Cmd       ((Com_SignalIdType)73)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR    ((Com_SignalIdType)74)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer      ((Com_SignalIdType)75)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Yr               ((Com_SignalIdType)76)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Mth              ((Com_SignalIdType)77)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Day              ((Com_SignalIdType)78)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Hr               ((Com_SignalIdType)79)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Min              ((Com_SignalIdType)80)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Sec              ((Com_SignalIdType)81)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_MSec             ((Com_SignalIdType)82)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT          ((Com_SignalIdType)83)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts         ((Com_SignalIdType)84)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts         ((Com_SignalIdType)85)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts         ((Com_SignalIdType)86)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts         ((Com_SignalIdType)87)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts         ((Com_SignalIdType)88)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts         ((Com_SignalIdType)89)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts         ((Com_SignalIdType)90)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts         ((Com_SignalIdType)91)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts         ((Com_SignalIdType)92)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts        ((Com_SignalIdType)93)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts        ((Com_SignalIdType)94)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts        ((Com_SignalIdType)95)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts        ((Com_SignalIdType)96)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts        ((Com_SignalIdType)97)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts        ((Com_SignalIdType)98)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts        ((Com_SignalIdType)99)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts        ((Com_SignalIdType)100)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts        ((Com_SignalIdType)101)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts        ((Com_SignalIdType)102)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts        ((Com_SignalIdType)103)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts        ((Com_SignalIdType)104)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts        ((Com_SignalIdType)105)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts        ((Com_SignalIdType)106)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts        ((Com_SignalIdType)107)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts        ((Com_SignalIdType)108)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts        ((Com_SignalIdType)109)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts        ((Com_SignalIdType)110)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts        ((Com_SignalIdType)111)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts        ((Com_SignalIdType)112)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts        ((Com_SignalIdType)113)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts        ((Com_SignalIdType)114)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts        ((Com_SignalIdType)115)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts        ((Com_SignalIdType)116)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts        ((Com_SignalIdType)117)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts        ((Com_SignalIdType)118)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts        ((Com_SignalIdType)119)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts        ((Com_SignalIdType)120)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts        ((Com_SignalIdType)121)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts        ((Com_SignalIdType)122)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts        ((Com_SignalIdType)123)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts        ((Com_SignalIdType)124)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts        ((Com_SignalIdType)125)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts        ((Com_SignalIdType)126)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts        ((Com_SignalIdType)127)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts        ((Com_SignalIdType)128)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts        ((Com_SignalIdType)129)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts        ((Com_SignalIdType)130)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts        ((Com_SignalIdType)131)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC         ((Com_SignalIdType)132)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr     ((Com_SignalIdType)133)
#define Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload     ((Com_SignalIdType)134)

/*******************************************************************************
*   Handles of RxSigLongData
*******************************************************************************/
/*Cfg_D*/
#define Com_RxSigLongData_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload ((Com_RxSigLockIndexType)0)
/*Cfg_P*/
#define Com_RxSigLongData_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload ((Com_RxSigLockIndexType)0)

/*******************************************************************************
*   Handles of TX PDU ID
*******************************************************************************/
/*Cfg_D*/
#define Com_PduR_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6            ((PduIdType)0)
#define Com_PduR_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF            ((PduIdType)1)
#define Com_PduR_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0            ((PduIdType)2)
#define Com_PduR_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1            ((PduIdType)3)
#define Com_PduR_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8            ((PduIdType)4)
#define Com_PduR_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC            ((PduIdType)5)
/*Cfg_P*/
#define Com_PduR_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7            ((PduIdType)0)
#define Com_PduR_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2            ((PduIdType)1)
#define Com_PduR_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3            ((PduIdType)2)
#define Com_PduR_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4            ((PduIdType)3)
#define Com_PduR_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB            ((PduIdType)4)
#define Com_PduR_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED            ((PduIdType)5)

/*******************************************************************************
*   Handles of TX signals
*******************************************************************************/
/*Cfg_D*/
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts5          ((Com_SignalIdType)0)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts6          ((Com_SignalIdType)1)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts5   ((Com_SignalIdType)2)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts6   ((Com_SignalIdType)3)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts7   ((Com_SignalIdType)4)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts8   ((Com_SignalIdType)5)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts7          ((Com_SignalIdType)6)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts8          ((Com_SignalIdType)7)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime8     ((Com_SignalIdType)8)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime5     ((Com_SignalIdType)9)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime6     ((Com_SignalIdType)10)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime7     ((Com_SignalIdType)11)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvMassSwitchSts          ((Com_SignalIdType)12)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgHeatCSts      ((Com_SignalIdType)13)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarValueSts     ((Com_SignalIdType)14)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgValveSts      ((Com_SignalIdType)15)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatUpperValueSts      ((Com_SignalIdType)16)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValueSts    ((Com_SignalIdType)17)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBlosterValueSts    ((Com_SignalIdType)18)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarTopPos       ((Com_SignalIdType)19)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarMidPos       ((Com_SignalIdType)20)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarBottomPos    ((Com_SignalIdType)21)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBLPos  ((Com_SignalIdType)22)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBRPos  ((Com_SignalIdType)23)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValue6Pos   ((Com_SignalIdType)24)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue5Pos   ((Com_SignalIdType)25)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue4Pos   ((Com_SignalIdType)26)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue2Pos   ((Com_SignalIdType)27)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue1Pos   ((Com_SignalIdType)28)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueLPos     ((Com_SignalIdType)29)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueMPos     ((Com_SignalIdType)30)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueRPos     ((Com_SignalIdType)31)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvPumpSts      ((Com_SignalIdType)32)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgSkillsSts9          ((Com_SignalIdType)33)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumControlSts          ((Com_SignalIdType)34)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumSwitchSts ((Com_SignalIdType)35)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSystemFailr  ((Com_SignalIdType)36)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatMassFailr          ((Com_SignalIdType)37)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatCushionValue3Pos   ((Com_SignalIdType)38)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarTopWorkSts       ((Com_SignalIdType)39)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarMidWorkSts       ((Com_SignalIdType)40)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarBottomWorkSts    ((Com_SignalIdType)41)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat1Sts     ((Com_SignalIdType)42)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat2Sts     ((Com_SignalIdType)43)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat3Sts     ((Com_SignalIdType)44)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat4Sts     ((Com_SignalIdType)45)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5Sts     ((Com_SignalIdType)46)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat6Sts     ((Com_SignalIdType)47)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5ErrSts  ((Com_SignalIdType)48)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassglvlSts9   ((Com_SignalIdType)49)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgTime9     ((Com_SignalIdType)50)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgTime10    ((Com_SignalIdType)51)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgSkillsSts10         ((Com_SignalIdType)52)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassglvlSts10  ((Com_SignalIdType)53)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC1        ((Com_SignalIdType)54)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC2        ((Com_SignalIdType)55)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC3        ((Com_SignalIdType)56)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC4        ((Com_SignalIdType)57)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC5        ((Com_SignalIdType)58)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC6        ((Com_SignalIdType)59)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC7        ((Com_SignalIdType)60)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC8        ((Com_SignalIdType)61)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC9        ((Com_SignalIdType)62)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC10       ((Com_SignalIdType)63)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC11       ((Com_SignalIdType)64)
#define Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC12       ((Com_SignalIdType)65)
/*Cfg_P*/
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts5         ((Com_SignalIdType)0)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts5  ((Com_SignalIdType)1)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts6  ((Com_SignalIdType)2)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime5    ((Com_SignalIdType)3)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts6         ((Com_SignalIdType)4)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts7         ((Com_SignalIdType)5)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime6    ((Com_SignalIdType)6)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime7    ((Com_SignalIdType)7)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts8         ((Com_SignalIdType)8)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts7  ((Com_SignalIdType)9)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts8  ((Com_SignalIdType)10)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime8    ((Com_SignalIdType)11)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgValveSts     ((Com_SignalIdType)12)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgHeatCSts     ((Com_SignalIdType)13)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarValueSts    ((Com_SignalIdType)14)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatUpperValueSts     ((Com_SignalIdType)15)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValueSts   ((Com_SignalIdType)16)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBlosterValueSts   ((Com_SignalIdType)17)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassMassSwitchSts         ((Com_SignalIdType)18)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarTopPos      ((Com_SignalIdType)19)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarMidPos      ((Com_SignalIdType)20)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarBottomPos   ((Com_SignalIdType)21)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBLPos ((Com_SignalIdType)22)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBRPos ((Com_SignalIdType)23)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValue6Pos  ((Com_SignalIdType)24)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue5Pos  ((Com_SignalIdType)25)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue4Pos  ((Com_SignalIdType)26)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue2Pos  ((Com_SignalIdType)27)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue1Pos  ((Com_SignalIdType)28)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueLPos    ((Com_SignalIdType)29)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueMPos    ((Com_SignalIdType)30)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueRPos    ((Com_SignalIdType)31)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassPumpSts     ((Com_SignalIdType)32)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgSkillsSts9         ((Com_SignalIdType)33)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumControlSts         ((Com_SignalIdType)34)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumSwitchSts          ((Com_SignalIdType)35)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSystemFailr ((Com_SignalIdType)36)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatMassFailr         ((Com_SignalIdType)37)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatCushionValue3Pos  ((Com_SignalIdType)38)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarTopWorkSts      ((Com_SignalIdType)39)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarMidWorkSts      ((Com_SignalIdType)40)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarBottomWorkSts   ((Com_SignalIdType)41)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat1Sts    ((Com_SignalIdType)42)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat2Sts    ((Com_SignalIdType)43)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat3Sts    ((Com_SignalIdType)44)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat4Sts    ((Com_SignalIdType)45)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5Sts    ((Com_SignalIdType)46)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat6Sts    ((Com_SignalIdType)47)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5ErrSts ((Com_SignalIdType)48)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgLvlSts9  ((Com_SignalIdType)49)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgTime9    ((Com_SignalIdType)50)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgTime10   ((Com_SignalIdType)51)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgSkillsSts10        ((Com_SignalIdType)52)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgLvlSts10 ((Com_SignalIdType)53)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC1       ((Com_SignalIdType)54)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC2       ((Com_SignalIdType)55)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC3       ((Com_SignalIdType)56)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC4       ((Com_SignalIdType)57)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC5       ((Com_SignalIdType)58)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC6       ((Com_SignalIdType)59)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC7       ((Com_SignalIdType)60)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC8       ((Com_SignalIdType)61)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC9       ((Com_SignalIdType)62)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC10      ((Com_SignalIdType)63)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC11      ((Com_SignalIdType)64)
#define Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC12      ((Com_SignalIdType)65)

/*******************************************************************************
*   Handles of PduGroup
*******************************************************************************/
#define Com_BODY_LE1_CANTx                                  ((Com_IpduGroupIdType)0)
#define Com_BODY_LE1_CANRx                                  ((Com_IpduGroupIdType)1)

/*******************************************************************************
*   Handles of signalGroup
*******************************************************************************/
/*Cfg_D*/
/*Cfg_P*/

/*******************************************************************************
*   Access Macro
*******************************************************************************/
#define COM_RX_PDU_MAX_ARRAY_SZIE                           ((uint8)8)
#define COM_RX_SIG_MAX_ARRAY_SZIE                           (0)
typedef uint8 Com_RxSigLockIndexType;
#define COM_RX_SIG_LONG_DATA_NUM                            (1)
/*******************************************************************************
*   Tx Main function
*******************************************************************************/
#define COM_TX_MULTI_MAINFUNCTION_ENABLE                    STD_OFF
#define COM_TX_MAINFUNCTION_NUMBER                          0
/*******************************************************************************
*   Rx Main function
*******************************************************************************/
#define COM_RX_MULTI_MAINFUNCTION_ENABLE                    STD_OFF
#define COM_RX_MAINFUNCTION_NUMBER                          0
/*******************************************************************************
*   Tx Main function
*******************************************************************************/
#define COM_TX_MULTI_MAINFUNCTION_ENABLE                    STD_OFF
#define COM_TX_MAINFUNCTION_NUMBER                          0
/*******************************************************************************
*   Rx Main function
*******************************************************************************/
#define COM_RX_MULTI_MAINFUNCTION_ENABLE                    STD_OFF
#define COM_RX_MAINFUNCTION_NUMBER                          0

#endif

