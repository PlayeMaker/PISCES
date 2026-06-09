/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : BswM_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : BswM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : BswM module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/
#ifndef BSWM_CFG_H
#define BSWM_CFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/


/*******************************************************************************
*   Common Macro
*******************************************************************************/
/*The configuration variant and version informations*/
#define BSWM_CONFIG_VARIANTS                                STD_CONFIG_VARIANTS_POSTBUILD


/*******************************************************************************
*   Non Autosar Standard
*******************************************************************************/
/* only used when postbuild is selected  */

/* EAS special */
#define BSWM_VERSION_CHECK                                  STD_ON


/*******************************************************************************
*   BswMGeneral
*******************************************************************************/
/* ECUC_BswM_00811 */
#define BSWM_DEV_ERROR_DETECT                               STD_ON
/* ECUC_BswM_00812 */
#define BSWM_VERSION_INFO_API                               STD_ON
/* ECUC_BswM_00813 */
#define BSWM_MAINFUNCTION_PERIOD                            5

/* ECUC_BswM_00938 */
#define BSWM_CANSM_ENABLED                                  STD_ON
/* ECUC_BswM_00939 */
#define BSWM_COMM_ENABLED                                   STD_ON
/* ECUC_BswM_00940 */
#define BSWM_DCM_ENABLED                                    STD_ON
/* ECUC_BswM_00941 */
#define BSWM_ECUM_ENABLED                                   STD_ON
/* ECUC_BswM_00942 */
#define BSWM_ETHSM_ENABLED                                  STD_OFF
/* ECUC_BswM_00943 */
#define BSWM_FRSM_ENABLED                                   STD_OFF
/* ECUC_BswM_00944 */
#define BSWM_LINSM_ENABLED                                  STD_OFF
/* ECUC_BswM_00945 */
#define BSWM_LINTP_ENABLED                                  STD_OFF
/* ECUC_BswM_00946 */
#define BSWM_NVM_ENABLED                                    STD_ON
/* ECUC_BswM_00947 */
#define BSWM_SCHM_ENABLED                                   STD_OFF
/* ECUC_BswM_00949 */
#define BSWM_GENERIC_REQUEST_ENABLED                        STD_ON

/* ECUC_BswM_01072 */
#define BSWM_ETHIF_ENABLED                                  STD_OFF

#define BSWM_SOAD_ENABLED                                   STD_OFF

/* ECUC_BswM_00987 */
#define BSWM_J1939DCM_ENABLED                               STD_OFF
/* ECUC_BswM_00965 */
#define BSWM_J1939NM_ENABLED                                STD_OFF
/* ECUC_BswM_01047 */
#define BSWM_SD_ENABLED                                     STD_OFF
/* ECUC_BswM_01071 */
#define BSWM_NM_ENABLED                                     STD_OFF

#define BSWM_TIMER_ENABLED                                  STD_ON
#define BSWM_MAX_TIMER_NUM                                  (uint8)1

#define BSWM_ECUM_WKUPSRC_ENABLED                           STD_OFF
#define BSWM_DEM_ENABLED                                    STD_OFF
#define BSWM_ABORTONFAIL_ENABLED                            STD_OFF
#define BSWM_MODEINITVALUE_ENABLED                          STD_ON
#define BSWM_ERRORID_ENABLED                                STD_OFF

#define BSWM_NVM_READALL_SUPPORT                            STD_ON
#define BSWM_NVM_WRITEALL_SUPPORT                           STD_ON
#define BSWM_NVM_CANCEL_WRITE_ALL_SUPPORT                   STD_OFF
#define BSWM_NVM_FIRST_INIT_ALL_SUPPORT                     STD_OFF
#define BSWM_NVM_VALIDATE_ALL_SUPPORT                       STD_OFF

#define BSWM_COMM_PNC_ENABLED                               STD_OFF
#define BSWM_COMM_RESET_ENABLED                             STD_OFF
#define BSWM_MULTIPATITION_ENABLED                          STD_OFF

/* generate tool's version*/
#define BSWM_SW_MAJOR_VERSION_CFG                           4
#define BSWM_SW_MINOR_VERSION_CFG                           1
#define BSWM_SW_PATCH_VERSION_CFG                           0
#define BSWM_AR_RELEASE_MAJOR_VERSION_CFG                   4
#define BSWM_AR_RELEASE_MINOR_VERSION_CFG                   7
#define BSWM_AR_RELEASE_REVISION_VERSION_CFG                0



/*******************************************************************************
*   Macro
*******************************************************************************/


#define BSWM_MAX_ACTIONLIST_NUM                             (15)
#define BSWM_MAX_RULE_NUM                                   (16)
#define BSWM_BSWMSWITCHPORT_ERROR_NUM                       (0)
#define BSWM_BSWMSWITCHPORT_ACK_NUM                         (0)
#define BSWM_MAX_PRIORITY_NUM                               (1)


/*PortNum*/
#define BSWM_ECUM_PORT_NUM                                  (1)
#define BSWM_LINSM_PORT_NUM                                 (0)
#define BSWM_FRSM_PORT_NUM                                  (0)
#define BSWM_ETHSM_PORT_NUM                                 (0)
#define BSWM_ETHIF_PORT_NUM                                 (0)
#define BSWM_CANSM_PORT_NUM                                 (1)
#define BSWM_DCM_PORT_NUM                                   (1)
#define BSWM_DCM_APP_UPDATE_PORT_NUM                        (0)
#define BSWM_COMM_PORT_NUM                                  (1)
#define BSWM_COMM_PNC_PORT_NUM                              (0)
#define BSWM_COMM_RESET_PORT_NUM                            (0)
#define BSWM_NVM_BLOCK_PORT_NUM                             (0)
#define BSWM_NVM_JOB_PORT_NUM                               (2)
#define BSWM_LINTP_PORT_NUM                                 (0)
#define BSWM_LINSM_SCH_PORT_NUM                             (0)
#define BSWM_NM_CAR_WKUP_PORT_NUM                           (0)
#define BSWM_NM_STATECHANGENOTIFICATION_PORT_NUM            (0)
#define BSWM_GENERAL_PORT_NUM                               (1)
#define BSWM_TIMER_PORT_NUM                                 (1)
#define BSWM_ECUM_WKUPSRC_PORT_NUM                          (0)
#define BSWM_J1939DCM_PORT_NUM                              (0)
#define BSWM_J1939NM_PORT_NUM                               (0)
#define BSWM_SD_CS_PORT_NUM                                 (0)
#define BSWM_SD_EVENTGROUP_PORT_NUM                         (0)
#define BSWM_SD_EVENTHANDLER_PORT_NUM                       (0)
#define BSWM_SOAD_SOCONMODECHG_PORT_NUM                     (0)
#define BSWM_SWC_MODE_NOTIFY_PORT_NUM                       (0)
#define BSWM_BSW_MODE_NOTIFY_PORT_NUM                       (0)
#define BSWM_SWC_MODE_REQUEST_PORT_NUM                      (0)
#define BSWM_ECUM_INDICATION_PORT_NUM                       (0)
#define BSWM_EVENT_REQUEST_PORT_NUM                         (0)
#define BSWM_PARTITION_RESTARTED_PORT_NUM                   (0)

#define BSWM_MAX_PORT_NUM                                   (8)
/*MAP*/
#define BSWM_MAP_ECUM_TO_PORT()                             ((BswMPortType)0)
#define BSWM_MAP_ECUM_MODE_IND_TO_PORT()                    ((BswMPortType)1)
#define BSWM_MAP_LINSM_TO_PORT(Network)                     ((BswMPortType)1 + (Network))
#define BSWM_MAP_FRSM_TO_PORT(Network)                      ((BswMPortType)1 + (Network))
#define BSWM_MAP_ETHSM_TO_PORT(Network)                     ((BswMPortType)1 + (Network))
#define BSWM_MAP_ETHIF_LINKSTATECHG_TO_PORT(PortGroupIdx)   ((BswMPortType)1 + (PortGroupIdx))
#define BSWM_MAP_CANSM_TO_PORT(Network)                     ((BswMPortType)1 + (Network))
#define BSWM_MAP_DCM_TO_PORT(Network)                       ((BswMPortType)2 + (Network))
#define BSWM_MAP_DCM_APP_UPDATE_TO_PORT()                   ((BswMPortType)3)
#define BSWM_MAP_COMM_TO_PORT(Network)                      ((BswMPortType)3 + (Network))
#define BSWM_MAP_COMM_PNC_TO_PORT(PNC)                      ((BswMPortType)4 + (PNC))
#define BSWM_MAP_COMM_RESET_TO_PORT()                       ((BswMPortType)4)
#define BSWM_MAP_NVM_BLOCK_TO_PORT(Block)                   ((BswMPortType)4 + (Block))
#define BSWM_MAP_NVM_READ_ALL_JOB_TO_PORT()                 ((BswMPortType)4)
#define BSWM_MAP_NVM_WRITE_ALL_JOB_TO_PORT()                ((BswMPortType)5)
#define BSWM_MAP_NVM_CANCEL_WRITE_ALL_JOB_TO_PORT()         ((BswMPortType)6)
#define BSWM_MAP_NVM_FIRST_INIT_ALL_JOB_TO_PORT()           ((BswMPortType)6)
#define BSWM_MAP_NVM_VALIDDATE_ALL_JOB_TO_PORT()            ((BswMPortType)6)
#define BSWM_MAP_LINTP_TO_PORT(Network)                     ((BswMPortType)6 + (Network))
#define BSWM_MAP_LINSM_SCH_TO_PORT(Network)                 ((BswMPortType)6 + (Network))
#define BSWM_MAP_NM_CAR_WKUP_TO_PORT(Network)               ((BswMPortType)6 + (Network))
#define BSWM_MAP_NM_STATECHANGENOTIFICATION_PORT(Network)   ((BswMPortType)6 + (Network))
#define BSWM_MAP_SOAD_SOCONMODECHG_TO_PORT(SoConId)         ((BswMPortType)6 + (SoConId))
#define BSWM_MAP_PARTITION_RESTARTED_TO_PORT(PartitionID)   ((BswMPortType)6 + (PartitionID))
#define BSWM_MAP_BSWM_GENERAL_TO_PORT(user)                 ((BswMPortType)6 + (user))
#define BSWM_MAP_TIMER_TO_PORT(Timer)                       ((BswMPortType)7 + (Timer))
#define BSWM_MAP_ECUM_WKUPSRC_TO_PORT(src)                  ((BswMPortType)8 + (src))
#define BSWM_MAP_J1939_DCM_TO_PORT(Network)                 ((BswMPortType)8 + (Network))
#define BSWM_MAP_J1939NM_TO_PORT(Network)                   ((BswMPortType)8 + (Network))
#define BSWM_MAP_SD_CS_TO_PORT(SdClientServiceHandleId)     ((BswMPortType)8 + (SdClientServiceHandleId))
#define BSWM_MAP_SD_EVENTGROUP_TO_PORT(SdConsumedEventGroupHandleId)  ((BswMPortType)8 + (SdConsumedEventGroupHandleId))
#define BSWM_MAP_SD_EVENTHANDLER_TO_PORT(SdEventHandlerHandleId)      ((BswMPortType)8 + (SdEventHandlerHandleId))
#define BSWM_MAP_SWC_MODE_NOTIFY_TO_PORT(Port)              ((BswMPortType)8 + (Port))
#define BSWM_MAP_BSW_MODE_NOTIFY_TO_PORT(Port)              ((BswMPortType)8 + (Port))
#define BSWM_MAP_SWC_MODE_REQUEST_TO_PORT(Port)             ((BswMPortType)8 + (Port))
#define BSWM_MAP_MODE_SWITCH_ERROE_EVENT_TO_PORT(Port)      ((BswMPortType)8 + (Port))
#define BSWM_MAP_SWITCH_ACK_NOTIFICATION_TO_PORT(Port)      ((BswMPortType)8 + (Port))
#define BSWM_MAX_PORT_MAPPING_RULE_NUM                      (BswM_ConfigSet->PortMappingRuleNum)

#define BSWM_ACTIONLIST_NULL                                ((BswMActionListIdType)65535)
#define BSWM_RULE_NULL                                      ((BswMRuleType)65535)





#define BSWM_GENERIC_MODE_INIT                              ((BswM_ModeType)0x00)
#define BSWM_GENERIC_MODE_WAKEUP                            ((BswM_ModeType)0x01)
#define BSWM_GENERIC_MODE_READ_NVM                          ((BswM_ModeType)0x02)
#define BSWM_GENERIC_MODE_WRITE_NVM                         ((BswM_ModeType)0x03)
#define BSWM_GENERIC_MODE_APP_RUN                           ((BswM_ModeType)0x04)
#define BSWM_GENERIC_MODE_POST_RUN                          ((BswM_ModeType)0x05)
#define BSWM_GENERIC_MODE_PREP_SHUTDOWN                     ((BswM_ModeType)0x06)
#define BSWM_GENERIC_MODE_SLEEP                             ((BswM_ModeType)0x07)
#define BSWM_GENERIC_MODE_SHUTDOWN                          ((BswM_ModeType)0x08)

#define BswM_SysState_Core0                                 0U


#define BSWM_MULTI_CORE_SUPPORT                             STD_OFF

#define BSWM_ATOMIC_READ(Address)                           *Address
#define BSWM_ATOMIC_WRITE(Address, Value)                   *Address = Value
#define BSWM_USED_CORE_NUMBER                               (uint8)1


#define BswMPortMappingRulesStart                           (BswM_ConfigSet->PortMappingRulesStart)
#define BswMPortMappingRulesNum                             (BswM_ConfigSet->PortMappingRulesNum)
#define BswMPortMappingRules                                (BswM_ConfigSet->PortMappingRules)
#define BswMAvailableRules                                  (BswM_ConfigSet->AvailableRules)

#endif /* BSWM_CFG_H */



