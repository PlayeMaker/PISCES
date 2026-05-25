/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dcm_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Dcm module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Dcm module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/

#ifndef DCM_CFG_H
#define DCM_CFG_H
/***********************************************************************************
* Include files
***********************************************************************************/
#include "ComM_Cfg.h"

/***********************************************************************************
* Version
***********************************************************************************/

#define DCM_PRIVATE_VERSION_CHECK                           STD_ON
#define DCM_SW_MAJOR_VERSION_CFG                            4
#define DCM_SW_MINOR_VERSION_CFG                            2
#define DCM_SW_PATCH_VERSION_CFG                            0
#define DCM_AR_RELEASE_MAJOR_VERSION_CFG                    4
#define DCM_AR_RELEASE_MINOR_VERSION_CFG                    7
#define DCM_AR_RELEASE_REVISION_VERSION_CFG                 0

/***********************************************************************************
* The following are configurable
***********************************************************************************/
#define DCM_OBD_SUPPORT                                     STD_OFF
#define DCM_CAR_PLATFORM                                    DCM_NO_PLATFORM
#define DCM_COMM_SUPPORT                                    STD_ON
#define DCM_BSWM_SUPPORT                                    STD_ON
#define DCM_DEM_SUPPORT                                     STD_ON
#define DCM_NVM_SUPPORT                                     STD_ON
#define DCM_CONFIG_VARIANTS                                 STD_CONFIG_VARIANTS_POSTBUILD

/*DcmGeneral*/

#define DCM_MULTI_CORE_SUPPORT                              STD_OFF
#define DCM_RXFIFOBUFFER_ENABLED                            STD_OFF

/*ECUC_Dcm_00971*/
#define DCM_DDDID_STORAGE                                   STD_OFF
/*ECUC_Dcm_00823*/
#define DCM_DEV_ERROR_DETECT                                STD_OFF
/*ECUC_Dcm_00600*/
#define DCM_RESPOND_ALL_REQUEST                             STD_OFF
/*ECUC_Dcm_00820*/
#define DCM_TASK_TIME                                       10
/*ECUC_Dcm_00821*/
#define DCM_VERSION_INFO_API                                STD_OFF
/*ECUC_Dcm_00984*/
#define DCM_VIN_REF                                         DCM_INVALID_VIN_REF

#define DCM_RESPONSE_WITHP2TIMER                            STD_ON
/*ECUC_Dcm_00783*/
#define DCM_DSD_MANUFACTURER_NOTIFICATION_ENABLED           STD_OFF
/*ECUC_Dcm_00868*/
#define DCM_DSD_SUPPLIER_NOTIFICATION_ENABLED               STD_OFF

/*UDS 0x10 Service*/
#define DCM_UDS_10_ENABLED                                  STD_ON
#define DCM_UDS_10_SUPPORT_SUPPRESSPOSRESBIT                STD_ON

/*UDS 0x11 Service*/
#define DCM_UDS_11_ENABLED                                  STD_ON
#define DCM_UDS_11_SUPPORT_SUPPRESSPOSRESBIT                STD_ON

/*UDS 0x14 Service*/
#define DCM_UDS_14_ENABLED                                  STD_ON
#define DCM_APP_CLEARDTCCHECK_ENABLE                        STD_OFF

/*UDS 0x19 Service*/
#define DCM_UDS_19_ENABLED                                  STD_ON
#define DCM_UDS_19_SUPPORT_SUPPRESSPOSRESBIT                STD_OFF
#define DCM_CFG_OBD_UDS_DTC_SEPARATION                      STD_OFF
#define DCM_UDS_19_01_07_12_ENABLED                         STD_ON
#define DCM_UDS_19_02_0A_13_15_17_ENABLED                   STD_ON
#define DCM_UDS_19_03_ENABLED                               STD_OFF
#define DCM_UDS_19_04_18_ENABLED                            STD_ON
#define DCM_UDS_19_05_ENABLED                               STD_OFF
#define DCM_UDS_19_06_19_ENABLED                            STD_ON
#define DCM_UDS_19_08_ENABLED                               STD_OFF
#define DCM_UDS_19_09_ENABLED                               STD_OFF
#define DCM_UDS_19_0B_0C_0D_0E_ENABLED                      STD_OFF
#define DCM_UDS_19_14_ENABLED                               STD_OFF
#define DCM_UDS_19_1A_ENABLED                               STD_OFF
#define DCM_UDS_19_42_ENABLED                               STD_OFF
#define DCM_UDS_19_55_ENABLED                               STD_OFF
#define DCM_UDS_19_56_ENABLED                               STD_OFF

/*UDS 0x22 Service*/
#define DCM_UDS_22_ENABLED                                  STD_ON

/*UDS 0x23 Service*/
#define DCM_UDS_23_ENABLED                                  STD_OFF

/*UDS 0x27 Service*/
#define DCM_UDS_27_ENABLED                                  STD_ON
#define DCM_UDS_27_SUPPORT_SUPPRESSPOSRESBIT                STD_OFF
#define DCM_CFG_MANUFACTORY_MODE_SUPPORT                    STD_OFF
#define DCM_CFG_ADR_SUPPORT                                 STD_OFF
#define DCM_CFG_ACCESS_ATTEMPT_COUNTER_SUPPORT              STD_ON
#define DCM_UDS_27_NCR24AFTERZEROSEED                       STD_ON
#define DCM_UDS_27_REQUESTSEEDCONTINOUS                     STD_OFF
#define DCM_UDS_27_KEY_SIZE_ERR_EFFECT_ATTNUM               STD_ON

#define DCM_DSP_SECURITY_COUNTER_READOUT_TIME               2000
#define DCM_DSP_SECURITY_RST_CNT_ON_TIMEOUT                 FALSE

/*UDS 0x28 Service*/
#define DCM_UDS_28_ENABLED                                  STD_ON
#define DCM_UDS_28_SUPPORT_SUPPRESSPOSRESBIT                STD_ON
#define Dcm_Rte_CommunicationMode_CurrentState(Handle,Mode)     \
    BswM_Dcm_CommunicationMode_CurrentState(Handle,Mode)

/*UDS 0x29 Service*/
#define DCM_UDS_29_ENABLED                                  STD_OFF

/*UDS 0x2A Service*/
#define DCM_UDS_2A_ENABLED                                  STD_OFF

/*UDS 0x2C Service*/
#define DCM_UDS_2C_ENABLED                                  STD_OFF

/*UDS 0x2E Service*/
#define DCM_UDS_2E_ENABLED                                  STD_OFF

/*UDS 0x2F Service*/
#define DCM_UDS_2F_ENABLED                                  STD_OFF

/*UDS 0x31 Service*/
#define DCM_UDS_31_ENABLED                                  STD_ON
#define DCM_UDS_31_SUPPORT_SUPPRESSPOSRESBIT                STD_ON

/*UDS 0x34 Service*/
#define DCM_UDS_34_ENABLED                                  STD_OFF

/*UDS 0x35 Service*/
#define DCM_UDS_35_ENABLED                                  STD_OFF

/*UDS 0x36 Service*/
#define DCM_UDS_36_ENABLED                                  STD_OFF

/*UDS 0x37 Service*/
#define DCM_UDS_37_ENABLED                                  STD_OFF

/*UDS 0x38 Service*/
#define DCM_UDS_38_ENABLED                                  STD_OFF

/*UDS 0x3D Service*/
#define DCM_UDS_3D_ENABLED                                  STD_OFF

/*UDS 0x3E Service*/
#define DCM_UDS_3E_ENABLED                                  STD_ON
#define DCM_UDS_3E_SUPPORT_SUPPRESSPOSRESBIT                STD_ON

/*UDS 0x85 Service*/
#define DCM_UDS_85_ENABLED                                  STD_ON
#define DCM_UDS_85_SUPPORT_SUPPRESSPOSRESBIT                STD_ON
#define DCM_SUPPORT_DTC_RECORD                              STD_OFF

/*UDS 0x87 Service*/
#define DCM_UDS_87_ENABLED                                  STD_OFF



/*OBD 0x01 Service*/
#define DCM_OBD_01_ENABLED                                  STD_OFF

/*OBD 0x02 Service*/
#define DCM_OBD_02_ENABLED                                  STD_OFF

/*OBD 0x03 Service*/
#define DCM_OBD_03_ENABLED                                  STD_OFF

/*OBD 0x04 Service*/
#define DCM_OBD_04_ENABLED                                  STD_OFF

/*OBD 0x06 Service*/
#define DCM_OBD_06_ENABLED                                  STD_OFF

/*OBD 0x07 Service*/
#define DCM_OBD_07_ENABLED                                  STD_OFF

/*OBD 0x08 Service*/
#define DCM_OBD_08_ENABLED                                  STD_OFF

/*OBD 0x09 Service*/
#define DCM_OBD_09_ENABLED                                  STD_OFF

/*OBD 0x0A Service*/
#define DCM_OBD_0A_ENABLED                                  STD_OFF
/*Dsl Configuration*/
/*ECUC_Dcm_00693,DcmDslDiagRespMaxNumRespPend*/
#define DCM_CFG_RESP_PEND_MAX_NUM                           4
/*ECUC_Dcm_00914,DcmDslDiagRespOnSecondDeclinedRequest*/
#define DCM_CFG_RESP_ON_SECOND_REQ                          FALSE
/*Dsp Configuration*/
/*ECUC_Dcm_00966,DcmDspDDDIDcheckPerSourceDID*/
#define DCM_CFG_DSP_DDDID_CHECK_SRC_DID                     FALSE
/*ECUC_Dcm_00987,DcmDspDataDefaultEndianness*/
#define DCM_CFG_DSP_DEFAULT_ENDIANNESS                      DCM_OPAQUE
/*ECUC_Dcm_01061,DcmDspEnableObdMirror*/
#define DCM_CFG_DSP_EN_OBD_MIRROR                           FALSE
/*ECUC_Dcm_00638,DcmDspMaxDidToRead,1..65535*/
#define DCM_CFG_DSP_MAX_DID_READ                            1
/*ECUC_Dcm_00818,DcmDspPowerDownTime,valid:00-FE,unit:s*/
#define DCM_CFG_DSP_POWER_DOWN_TIME                         0
/*ECUC_Dcm_00956,DcmDspMaxPeriodicDidToRead,1..65535*/
#define DCM_CFG_DSP_MAX_PERIODIC_DID_READ                   1
#define DCM_NUM_COMM_CHANNEL                                COMM_NUM_OF_CHANNEL

#define DCM_CFG_NUM_OF_PROTOCOL                             (uint8)1
#define DCM_CFG_NUM_OF_STAB                                 (uint8)1
#define DCM_CFG_NUM_OF_CONNECTION                           (uint16)1

#define DCM_CFG_NUM_SECURITY_LEVEL                          1
#define DCM_CFG_RXPDU_NUM                                   (PduIdType)2
#define DCM_CFG_DDDID_NUM                                   (uint16)0
#define DCM_CFG_ALL_DDDID_ELEMENT_NUM                       0
#define DCM_CFG_RID_NUM                                     (uint16)1

#define DcmTransmit(DcmTxPduId,PduInfoPtr)    PduR_UpCallTransmit(DcmTxPduId,PduInfoPtr)
#define DcmCancelTransmit(DcmTxPduId)
#define DcmCancelReceive(DcmTxPduId)

#define Dcm_PduR_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU      ((PduIdType)0)
#define Dcm_PduR_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_D       ((PduIdType)1)

#define Dcm_PduR_Cfg_D_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_D      ((PduIdType)0)

#define Dcm_PduR_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU      ((PduIdType)0)
#define Dcm_PduR_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_P       ((PduIdType)1)

#define Dcm_PduR_Cfg_P_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_P      ((PduIdType)0)

#define Dcm_Dcm_DslConnection_BODY_LE1_CAN_Model_FunGroup0_DslMainConnection    ((uint16)0)

#endif

