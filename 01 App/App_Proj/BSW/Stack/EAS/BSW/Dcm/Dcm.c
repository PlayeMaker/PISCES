/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dcm.c
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : Dcm.c
*   Author          : Hirain
********************************************************************************
*   Description: Main source file of the AUTOSAR Diagnositc communcation manager,
*                according to AUTOSAR_SWS_DiagnosticCommunicationManager.pdf
*                (Release R21-11) and ISO14229-1(2020).pdf.
*
********************************************************************************
*   Limitations: None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version      Date         Initials          CR#       Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   04.00.00    20/01/2023    Feixiang.Dong     N/A       Original
*   04.00.01    20/03/2024    Feixiang.Dong     N/A       QAC
*   04.00.02    05/08/2024    Feixiang.Dong     N/A       Tessy&OBD
*   04.01.00    18/09/2024    Feixiang.Dong     N/A       P2Adjust
*   04.01.01    20/05/2025    Feixiang.Dong     N/A       CrossCoreInfo&29Service&27Service
*   04.02.00    10/07/2025    Linru.Du          N/A       RxFifoBufferSupport
********************************************************************************
* END_FILE_HDR*/

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 857 EOF*/

/*PRQA S 791,792 EOF*/
/*
Names in this file may not follow relevant rules.
*/

/*PRQA S 1503,1504,1505 EOF*/
/*
Functions such as Dcm_Init() are defined to be used by other modules.
*/

/*PRQA S 2000 EOF*/
/*
When there is only one If,there can be no else.
*/

/*PRQA S 2100,2101 EOF*/
/*
Logical judgment needs to be done.
*/

/*PRQA S 2201 EOF*/
/*
Indentation is reserved for certain special functions.
*/

/*PRQA S 2814,2824 EOF*/
/*
When this statements are excuted, none of these parameters (pErrorCode,pMsgContext,DCM_SUBSERVICE_FNC and so on) will be null pointers..
*/

/*PRQA S 2841,2842,2843,2844 EOF*/
/*
When this function is called, ProtocolId/DCM_SES_IDX/NetworkId must have become valid and there will be no invalid pointer.
*/

/*PRQA S 2877 EOF*/
/*
The loop will be be excuted more than once if the parameter is configured to be greater than 1.
*/

/*PRQA S 2981,2982 EOF*/
/*
This initialization/assignment is redundant.
*/

/*PRQA S 2984 EOF*/
/*
It is necessary to use constants for arithmetic operations.
*/

/*PRQA S 3119 EOF*/
/*
'(void)Parameter' is used to eliminate the compilation warning.
*/

/*PRQA S 3138,3141 EOF*/
/*
The relevant macrofunctions can be used or configured based on actual requirements, which is reserved.
*/

/*PRQA S 3204,3206 EOF*/
/*
Though the variable '%s' is only set once but it could not be declared with the 'const' qualifier.
*/

/*PRQA S 3227,3673 EOF*/
/*
Read-only function input parameters may not be defined as const,it does not affect the function.
AUTOSAR API shall define standard input parameters according to specification requirements.
*/

/*PRQA S 3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "Dcm_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in Dcm_MemMap.h
*/

/*PRQA S 3383,3384 EOF*/
/*
Addition and subtraction operations on internal variables of dcm doesn't overflow.
*/

/*PRQA S 3453,3429 EOF*/
/*
1.The unified requirement of EAS is that the error reporting functions of Det
and Dem moduls are accessed by macro functions.This part has been verified and
has no problem.
2.Macro functions are allowed to use to access parameters and do some simple operations.
*/

/*PRQA S 3432,3410 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no need to revise.
*/

/*PRQA S 3416 EOF*/
/*
In a If statement,calling a function to directly determine the return value is allowed.
*/

/*PRQA S 3892 EOF*/
/*
The implementation of the function needs to be handled this way.
*/

/*PRQA S 4110,4130,4397,4399,4558,4570,4571 EOF*/
/*
Permission ! operator, specific implementation methods.
Permission ~ operator, specific implementation methods.
Permission << operator, specific implementation methods.
Bitwise operations on signed data will give implementation defined results.
*/

/*PRQA S 4599 EOF*/
/*
Operands of binary operator '%1s' have the same type '%2s' but distinct type names '%3s' and '%4s'.
*/
/*******************************************************************************
* Includes
*******************************************************************************/
#include "Dcm.h"
#if(STD_ON == DCM_OBD_SUPPORT)
#include "Dcm_OBD.h"
#endif
#include "Dcm_Cbk.h"
#include "Dcm_ComM.h"
#include "Dcm_Csm.h"
#include "Dcm_KeyM.h"
#include "Dcm_Callout.h"
#include "Dcm_Lcfg.h"
#if(DCM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
#include "Dcm_PBcfg.h"
#endif
#if(STD_ON == DCM_DEM_SUPPORT)
#include "Dem.h"
#include "Dem_Dcm.h"
#endif
#if(STD_ON == DCM_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#if(STD_ON == DCM_COMM_SUPPORT)
#include "ComM_Dcm.h"
#endif
#if(STD_ON == DCM_NVM_SUPPORT)
#include "NvM.h"
#endif
#if(STD_ON == DCM_BSWM_SUPPORT)
#include "BswM_Dcm.h"
#endif
#if(STD_ON == DCM_UDS_29_ENABLED)
#include "Csm.h"
#include "KeyM.h"
#endif
#include "SchM_Dcm.h"
#include "Rte_Dcm.h"
#include "Bsw_Common.h"
#include "PduR.h"
#include "Dcm_Code.h"
/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(STD_ON == DCM_PRIVATE_VERSION_CHECK)
/* Check version of source file with cfg file */
#if((DCM_AR_RELEASE_MAJOR_VERSION != DCM_AR_RELEASE_MAJOR_VERSION_CFG)|| \
    (DCM_AR_RELEASE_MINOR_VERSION != DCM_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of Dcm and its cfg file are different"
#endif

#if((DCM_SW_MAJOR_VERSION != DCM_SW_MAJOR_VERSION_CFG)|| \
    (DCM_SW_MINOR_VERSION != DCM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of Dcm and its cfg file are different"
#endif
#endif/*#if(STD_ON == DCM_PRIVATE_VERSION_CHECK)*/

/*******************************************************************************
*   Macros
*******************************************************************************/
#if(STD_ON == DCM_DEV_ERROR_DETECT)
#define DCM_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(DCM_MODULE_ID,DCM_INSTANCE_ID,(ApiId),(errcode))
#define DCM_DET_REPORT_RUNTIME_ERROR(ApiId, errcode)  \
    DET_REPORT_RUNTIME_ERROR(DCM_MODULE_ID,DCM_INSTANCE_ID,(ApiId),(errcode))
#else
#define DCM_DET_REPORT_ERROR(ApiId, errcode)
#define DCM_DET_REPORT_RUNTIME_ERROR(ApiId, errcode)
#endif

#if(DCM_COMM_SUPPORT == STD_ON)
/*SWS_Dcm_91001*//*SWS_Dcm_01376*//*SWS_Dcm_01377*/
#define COMM_DCM_ACTIVEDIAGNOSTIC(i,j)     ComM_DCM_ActiveDiagnostic(DCM_CFG_PCL_CONNECTION_MAIN_COMM_CHN(i,j))
#define COMM_DCM_INACTIVEDIAGNOSTIC(i,j)   ComM_DCM_InactiveDiagnostic(DCM_CFG_PCL_CONNECTION_MAIN_COMM_CHN(i,j))
#else
#define COMM_DCM_ACTIVEDIAGNOSTIC(i,j)
#define COMM_DCM_INACTIVEDIAGNOSTIC(i,j)
#endif

/*******************UDS 10 Service********************************************/
#if(DCM_UDS_10_ENABLED == STD_ON)
#if(DCM_RESPONSE_WITHP2TIMER==STD_ON)
#define DCM_P2_STAR_RESOLUTION                             ((uint16)10)
#endif
#endif
/*******************UDS 11 Service********************************************/
#if(DCM_UDS_11_ENABLED == STD_ON)
#define DCM_HARD_RESET                                     ((uint8)0x01)
#define DCM_KEYOFFON_RESET                                 ((uint8)0x02)
#define DCM_SOFT_RESET                                     ((uint8)0x03)
#endif
/*******************UDS 19 Service********************************************/
#if(DCM_UDS_19_ENABLED == STD_ON)
/*reportNumberOfDTCByStatusMask*/
#define DCM_READ_DTC_01                                    ((uint8)0x01)
/*reportDTCByStatusMask*/
#define DCM_READ_DTC_02                                    ((uint8)0x02)
/*reportDTCSnapshotIdentification*/
#define DCM_READ_DTC_03                                    ((uint8)0x03)
/*reportDTCSnapshotRecordByDTCNumber*/
#define DCM_READ_DTC_04                                    ((uint8)0x04)
/*reportDTCStoredDataByRecordNumber*/
#define DCM_READ_DTC_05                                    ((uint8)0x05)
/*reportDTCExtDataRecordByDTCNumber*/
#define DCM_READ_DTC_06                                    ((uint8)0x06)
/*reportNumberOfDTCBySeverityMaskRecord*/
#define DCM_READ_DTC_07                                    ((uint8)0x07)
/*reportDTCBySeverityMaskRecord*/
#define DCM_READ_DTC_08                                    ((uint8)0x08)
/*reportSeverityInformationOfDTC*/
#define DCM_READ_DTC_09                                    ((uint8)0x09)
/*reportSupportedDTC*/
#define DCM_READ_DTC_0A                                    ((uint8)0x0A)
/*reportFirstTestFailedDTC*/
#define DCM_READ_DTC_0B                                    ((uint8)0x0B)
/*reportFirstConfirmedDTC*/
#define DCM_READ_DTC_0C                                    ((uint8)0x0C)
/*reportMostRecentTestFailedDTC*/
#define DCM_READ_DTC_0D                                    ((uint8)0x0D)
/*reportMostRecentConfirmedDTC*/
#define DCM_READ_DTC_0E                                    ((uint8)0x0E)
/*reportNumberOfEmissionsRelatedOBDDTCByStatusMask*/
#define DCM_READ_DTC_12                                    ((uint8)0x12)
/*reportEmissionsOBDDTCByStatusMask*/
#define DCM_READ_DTC_13                                    ((uint8)0x13)
/*reportDTCFaultDetectionCounter*/
#define DCM_READ_DTC_14                                    ((uint8)0x14)
/*reportDTCWithPermanentStatus*/
#define DCM_READ_DTC_15                                    ((uint8)0x15)
/*reportUserDefMemoryDTCByStatusMask*/
#define DCM_READ_DTC_17                                    ((uint8)0x17)
/*reportUserDefMemoryDTCSnapshotRecordByDTCNumber*/
#define DCM_READ_DTC_18                                    ((uint8)0x18)
/*reportUserDefMemoryDTCExtDataRecordByDTCNumber*/
#define DCM_READ_DTC_19                                    ((uint8)0x19)
/*reportDTCExtendedDataRecordIdentification*/
#define DCM_READ_DTC_1A                                    ((uint8)0x1A)
/*reportWWHOBDDTCByMaskRecord*/
#define DCM_READ_DTC_42                                    ((uint8)0x42)
/*reportWWHOBDDTCWithPermanentStatus*/
#define DCM_READ_DTC_55                                    ((uint8)0x55)
/*reportDTCInformationByDTCReadinessGroupIdentifier*/
#define DCM_READ_DTC_56                                    ((uint8)0x56)

#define DCM_USER_MEMORY_OFFSET                             0x0100
#define DCM_OBD_PID_02                                     ((uint8)0x02)
#define DCM_OBD_PID_MSB                                    ((uint8)0xF4)
/*Functional Group Identifier*/
#define DCM_DTC_FGID_33                                    ((uint8)0x33)
#endif
/*******************UDS 27 Service********************************************/
#if(DCM_UDS_27_ENABLED == STD_ON)
#define DCM_SECURITY_LOCKED_IDX                            ((uint8)254)
#define DCM_SECURITY_ALL_IDX                               ((uint8)255)
#endif
/*******************UDS 28 Service********************************************/
#if(DCM_UDS_28_ENABLED == STD_ON)
#define DCM_ENABLE_RX_TX                                   ((uint8)0x00)
#define DCM_ENABLE_RX_DISABLE_TX                           ((uint8)0x01)
#define DCM_DISABLE_RX_ENABLE_TX                           ((uint8)0x02)
#define DCM_DISABLE_RX_TX                                  ((uint8)0x03)
#define DCM_ENABLE_RX_DISABLE_TX_ENHANCED                  ((uint8)0x04)
#define DCM_ENABLE_RX_TX_ENHANCED                          ((uint8)0x05)
/*Message type*/
#define DCM_NORMAL_MSG                                     ((uint8)0x01)
#define DCM_NM_MSG                                         ((uint8)0x02)
#define DCM_NM_NORMAL_MSG                                  ((uint8)0x03)
#define DCM_MSG_MASK                                       ((uint8)0x0F)
#define DCM_SUBNET_MASK                                    ((uint8)0xF0)
#define DCM_SUBNET_RECEIVEED_ON                            ((uint8)0x0F)
#define DCM_COM_MODE_OFFSET                                ((uint8)0x04)
#endif
/*******************UDS 29 Service********************************************/
#if(DCM_UDS_29_ENABLED == STD_ON)
/*deAuthenticate*/
#define DCM_AUTHENTICATION_00                              ((uint8)0x00)
/*verifyCertificateUnidirectional*/
#define DCM_AUTHENTICATION_01                              ((uint8)0x01)
/*verifyCertificateBidirectional*/
#define DCM_AUTHENTICATION_02                              ((uint8)0x02)
/*proofOfOwnership*/
#define DCM_AUTHENTICATION_03                              ((uint8)0x03)
/*authenticationConfiguration*/
#define DCM_AUTHENTICATION_08                              ((uint8)0x08)

/*authenticationReturnParameter definitions*/
#define DCM_AU_REQUESTACCEPTED                             ((uint8)0x00)
#define DCM_AU_GENERALREJECT                               ((uint8)0x01)
#define DCM_AU_CONFIGURATIONAPCE                           ((uint8)0x02)
#define DCM_AU_CONFIGURATIONACRWITHASYMMETRIC              ((uint8)0x03)
#define DCM_AU_CONFIGURATIONACRWITHSYMMETRIC               ((uint8)0x04)
#define DCM_AU_DEAUTHENTICATIONSUCCESSFUL                  ((uint8)0x10)
#define DCM_AU_OWNERSHIPVERIFICATIONNECESSARY              ((uint8)0x11)
#define DCM_AU_AUTHENTICATIONCOMPLETE                      ((uint8)0x12)
#define DCM_AU_CERTIFICATEVERIFIED                         ((uint8)0x13)
/*ModeDeclarationGroup SWS_Dcm_91067*/
#define DCM_DEAUTHENTICATED                                ((uint8)0)
#define DCM_AUTHENTICATED                                  ((uint8)1)
#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
/*Initial lockout duration is 2 seconds*/
#define DCM_AU_INITIAL_DELAY_TIME                          ((uint32)2000)
/*The cap of lockout duration is 3600 seconds*/
#define DCM_AU_MAX_DELAY_TIME                              ((uint32)3600000)
/*The maximum number of consecutive failures is 1800*/
#define DCM_AU_FAILED_COUNTER_MAX_VALUE                    ((uint16)1800)
#endif
#endif
/*******************UDS 2A Service********************************************/
#if(DCM_UDS_2A_ENABLED == STD_ON)
#define DCM_2A_HIGHBYTE                                    ((uint8)0xF2)
#define DCM_2A_SENDATSLOWRATE                              ((uint8)0x01)
#define DCM_2A_SENDATMEDIUMRATE                            ((uint8)0x02)
#define DCM_2A_SENDATFASTRATE                              ((uint8)0x03)
#define DCM_2A_STOPSENDING                                 ((uint8)0x04)
#endif
/*******************UDS 2C Service********************************************/
#if(DCM_UDS_2C_ENABLED == STD_ON)
#define DCM_2C_BY_IDENTIFIER                               ((uint8)0x01)
#define DCM_2C_BY_MEMORYADDR                               ((uint8)0x02)
#define DCM_2C_CLEAR_DDDID                                 ((uint8)0x03)
#endif
/*******************UDS 23, 3D, 34, 35 Service********************************/
#if((DCM_UDS_23_ENABLED == STD_ON) || (DCM_UDS_3D_ENABLED == STD_ON) || (DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON))
#define DCM_MEM_FORMAT_ADDR_MASK                           ((uint8)0x0F)
#define DCM_MEM_FORMAT_SIZE_MASK                           ((uint8)0xF0)
#endif
/*******************UDS 34, 35, 38 Service***********************************/
#if((DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON) || (DCM_UDS_38_ENABLED == STD_ON))
/*define the init value and max value of block sequence counter*/
#define DCM_BSC_INIT_VALUE                                 ((uint8)0x01)
#define DCM_BSC_MAX_VALUE                                  ((uint8)0xFF)
/*Length format identifier for 34, 35*/
#define DCM_LENGTH_FORMAT_IDENTIFIER                       ((uint8)0x40)
#endif
/*******************UDS 31 Service********************************************/
#if(DCM_UDS_31_ENABLED == STD_ON)
#define DCM_START_ROUTINE                                  ((uint8)0x01)
#define DCM_STOP_ROUTINE                                   ((uint8)0x02)
#define DCM_REQUEST_ROUTINE_RESULTS                        ((uint8)0x03)
#endif
/*******************UDS 38 Service********************************************/
#if(DCM_UDS_38_ENABLED == STD_ON)
#define DCM_ADD_FILE                                       ((uint8)0x01)
#define DCM_DELETE_FILE                                    ((uint8)0x02)
#define DCM_REPLACE_FILE                                   ((uint8)0x03)
#define DCM_READ_FILE                                      ((uint8)0x04)
#define DCM_READ_DIR                                       ((uint8)0x05)
/*14229-1 2020 has defined 06, but autosar does not support.*/
#define DCM_RESUME_FILE                                    ((uint8)0x06)
#endif
/*******************UDS 85 Service********************************************/
#if(DCM_UDS_85_ENABLED == STD_ON)
#define DCM_DTC_SETTING_ON                                 ((uint8)0x01)
#define DCM_DTC_SETTING_OFF                                ((uint8)0x02)
#endif
/*******************UDS 87 Service********************************************/
#if(DCM_UDS_87_ENABLED == STD_ON)
#define DCM_VERIFY_FIXED_PARAMETER                         ((uint8)0x01)
#define DCM_VERIFY_SPECIFIC_PARAMETER                      ((uint8)0x02)
#define DCM_TRANSITION_MODE                                ((uint8)0x03)
#endif



/*******************Common #define********************************************/
#define DCM_UDS_NEG_RES_LEN                    (PduLengthType)3
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
#define DCM_UDS_WITH_NRC22_RES_LEN             (PduLengthType)4
#endif

#define DCM_RESPONSE_ID_40                     (uint8)0x40
#define DCM_RESPONSE_ID_7F                     (uint8)0x7F
#define DCM_RESPONSE_ID_C0                     (uint8)0xC0

#define DCM_SUB_SID_INDEX                      (Dcm_MsgLenType)1

#define DCM_SID_RESP_OFFSET                    ((uint8)0x40)
#define DCM_SUPPRESS_POS_RSP_MASK              ((uint8)0x80)
#define DCM_HIGH_BIT_MASK                      ((uint8)0x80)

/*execution steps*/
#define DCM_EXE_STEP_ONE                       ((uint8)1)
#define DCM_EXE_STEP_TWO                       ((uint8)2)
#define DCM_EXE_STEP_THREE                     ((uint8)3)
#define DCM_EXE_STEP_FOUR                      ((uint8)4)
#define DCM_EXE_STEP_FIVE                      ((uint8)5)
#define DCM_EXE_STEP_SIX                       ((uint8)6)
#define DCM_EXE_STEP_SEVEN                     ((uint8)7)
#define DCM_EXE_STEP_EIGHT                     ((uint8)8)
#define DCM_EXE_STEP_OVER                      ((uint8)255)

#if((DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM) || (DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM))
#define DCM_RNDS_READ_LENGTH                   (Dcm_MsgLenType)3
#define DCM_NISSAN_READ_LENGTH                 (Dcm_MsgLenType)4
#define DCM_RNDS_READ_DATA_LENGTH              (Dcm_MsgLenType)32
#define DCM_RNDS_READ_READ_ID                  ((uint8)0xDF)
#define DCM_RNDS_READ_WRITE_ID                 ((uint8)0xEC)
#define DCM_RNDS_READ_IO_ID                    ((uint8)0xED)
#define DCM_RNDS_READ_ROUTINE_ID               ((uint8)0xEE)
#define DCM_RNDS_READ_ID_HIGH_BYTE             ((uint8)0xDF)
#define DCM_RNDS_ID_HIGH_MASK                  ((uint16)0xFF00)
#define DCM_RNDS_ID_LOW_MASK                   ((uint16)0x00FF)
#endif


/*Used by Did service and routine service*/
#define DCM_INVALID_IDX   ((uint16)0xFFFF)

#define Make16Bit(HiByte, LoByte)              \
    (uint16)(((uint16)(HiByte) << DCM_SHIFT_8) | ((uint16)(LoByte)))
#define DcmMakeDTC(HiByte, MiByte, LoByte)     \
    (((uint32)(HiByte) << DCM_SHIFT_16) | ((uint32)(MiByte) << (uint32)DCM_SHIFT_8) | ((uint32)(LoByte)))



/*******************Configuration parameters**********************************/

#if(DCM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_LINKTIME)
#define DCM_TASK_TIME                          (Dcm_LConfig.DcmTaskTime)
#define DCM_CFG_RESP_PEND_MAX_NUM              (Dcm_LConfig.DcmDslDiagRespMaxNumRespPend)
#define DCM_CFG_RESP_ON_SECOND_REQ             (Dcm_LConfig.DcmDslDiagRespOnSecondDeclinedRequest)
#define DCM_CFG_DSP_DEFAULT_ENDIANNESS         (Dcm_LConfig.DcmDspDataDefaultEndianness)
#if(DCM_UDS_2C_ENABLED == STD_ON)
#define DCM_CFG_DSP_DDDID_CHECK_SRC_DID        (Dcm_LConfig.DcmDspDDDIDcheckPerSourceDID)
#endif
#define DCM_CFG_DSP_EN_OBD_MIRROR              (Dcm_LConfig.DcmDspEnableObdMirror)
#if(DCM_UDS_22_ENABLED == STD_ON)
#define DCM_CFG_DSP_MAX_DID_READ               (Dcm_LConfig.DcmDspMaxDidToRead)
#endif
#if(DCM_UDS_2A_ENABLED == STD_ON)
#define DCM_CFG_DSP_MAX_PERIODIC_DID_READ      (Dcm_LConfig.DcmDspMaxPeriodicDidToRead)
#define DCM_CFG_2A_MAX_SCHEDULER               (Dcm_LConfig.DcmDspMaxPeriodicDidScheduler)
#define DCM_CFG_2A_FAST_RATE                   (Dcm_LConfig.DcmDspPeriodicTransmissionFastRate)
#define DCM_CFG_2A_MEDIUM_RATE                 (Dcm_LConfig.DcmDspPeriodicTransmissionMediumRate)
#define DCM_CFG_2A_SLOW_RATE                   (Dcm_LConfig.DcmDspPeriodicTransmissionSlowRate)
#endif
#if(DCM_UDS_11_ENABLED == STD_ON)
#define DCM_CFG_DSP_POWER_DOWN_TIME            (Dcm_LConfig.DcmDspPowerDownTime)
#endif
#if(DCM_UDS_19_ENABLED == STD_ON)
#define DCM_CFG_OBD_UDS_DTC_SEPARATION         (Dcm_LConfig.DcmDspReadDTCInformationSupportedObdUdsDtcSeparation)
#endif

#if(DCM_UDS_27_ENABLED == STD_ON)
#define DCM_DSP_SECURITY_COUNTER_READOUT_TIME  (Dcm_LConfig.DcmDspSecurityMaxAttemptCounterReadoutTime)
#define DCM_DSP_SECURITY_RST_CNT_ON_TIMEOUT    (Dcm_LConfig.DcmDspSecurityResetAttemptCounterOnTimeout)
#endif
#endif


#define DCM_CFG_RXPDU_TO_PCL_MAP(i)            (Dcm_RxPduToProtocolMap[i])

#define DCM_CFG_PCL_TYPE(i)                    (Dcm_DslProtocolRow[i].DcmDslProtocolType)
#define DCM_CFG_PCL_PRIORITY(i)                (Dcm_DslProtocolRow[i].DcmDslProtocolPriority)
#define DCM_CFG_P2_ADJUST(i)                   (Dcm_DslProtocolRow[i].DcmTimStrP2ServerAdjust)
#define DCM_CFG_P2STAR_ADJUST(i)               (Dcm_DslProtocolRow[i].DcmTimStrP2StarServerAdjust)
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#define DCM_CFG_PCL_USED(i)                    (Dcm_DslProtocolRow[i].DcmDslProtocolRowUsed)
#else
#define DCM_CFG_PCL_USED(i)                    (Dcm_PBConfig->DcmDslProtocolRowUsed[i])
#endif
#define DCM_CFG_PCL_ECU_ADDR(i)                (Dcm_DslProtocolRow[i].DcmDspProtocolEcuAddr)
#define DCM_CFG_PCL_TRANS_TYPE(i)              (Dcm_DslProtocolRow[i].DcmDslProtocolTransType)
#define DCM_CFG_PCL_SEND_78_ON_RESTART(i)      (Dcm_DslProtocolRow[i].DcmSendRespPendOnRestart)
#if(DCM_DEM_SUPPORT == STD_ON)
#define DCM_CFG_PCL_DEM_CLIENT(i)              (Dcm_DslProtocolRow[i].DcmDemClientRef)
#endif
#define DCM_CFG_PCL_RXBUFFER_SIZE(i)           (Dcm_DslProtocolRow[i].DcmDslProtocolRxBufferRef.DcmDslBufferSize)
#define DCM_CFG_PCL_RXBUFFER(i)                (Dcm_DslProtocolRow[i].DcmDslProtocolRxBufferRef.DataPtr)
#define DCM_CFG_PCL_TXBUFFER_SIZE(i)           (Dcm_DslProtocolRow[i].DcmDslProtocolTxBufferRef.DcmDslBufferSize)
#define DCM_CFG_PCL_TXBUFFER(i)                (Dcm_DslProtocolRow[i].DcmDslProtocolTxBufferRef.DataPtr)

#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
#define DCM_CFG_PCL_RXBUFFER_NUM(i)            (Dcm_DslProtocolRow[i].DcmDslNumofRxFifoBuffer)
#define DCM_CFG_PCL_RXBUFFERLISTPTR            (DcmRxFifoBufferList)
#define DCM_CFG_PCL_RXFIFOBUFFER(i,j)          (&(Dcm_DslProtocolRow[i].DcmDslProtocolRxBufferRef.DataPtr[(j)*(DCM_CFG_PCL_RXBUFFER_SIZE(i))]))
#define DCM_CFG_PCL_TXRXBUFFERSAME(i)          (Dcm_DslProtocolRow[i].DcmTxRxSameBuffer)
#endif

#define DCM_CFG_PCL_S3(i)                      (Dcm_DslProtocolRow[i].S3Server)

#define DCM_CFG_PCL_CONNECTION_NUM(i)          (Dcm_DslProtocolRow[i].NumOfConnection)
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#define DCM_CFG_PCL_CONNECTION(i)              (Dcm_DslProtocolRow[i].DcmDslConnection)
#define DCM_CFG_PCL_CONNECTION_MAIN(i,j)       (Dcm_DslProtocolRow[i].DcmDslConnection[j].DcmDslMainConnection)
#else
#define DCM_CFG_PCL_CONNECTION(i)              (Dcm_PBConfig->DcmDslConnection[i])
#define DCM_CFG_PCL_CONNECTION_MAIN(i,j)       (Dcm_PBConfig->DcmDslConnection[i][j].DcmDslMainConnection)
#endif
#define DCM_CFG_PCL_CONNECTION_MAIN_CON_ID(i,j)         (DCM_CFG_PCL_CONNECTION_MAIN(i,j)->DcmDslProtocolRxConnectionId)
#define DCM_CFG_PCL_CONNECTION_MAIN_TESTER_ADDR(i,j)    (DCM_CFG_PCL_CONNECTION_MAIN(i,j)->DcmDslProtocolRxTesterSourceAddr)
#define DCM_CFG_PCL_CONNECTION_MAIN_COMM_CHN(i,j)       (DCM_CFG_PCL_CONNECTION_MAIN(i,j)->DcmDslProtocolComMChannelRef)
#if(STD_ON == DCM_UDS_29_ENABLED)
#define DCM_CFG_PCL_CONNECTION_MAIN_AU_CONNECTION(i,j)  (DCM_CFG_PCL_CONNECTION_MAIN(i,j)->DcmDslAuthenticationConnectionRef)
#endif
#define DCM_CFG_PCL_CONNECTION_MAIN_RX_NUM(i,j)         (DCM_CFG_PCL_CONNECTION_MAIN(i,j)->NumOfRxPdu)
#define DCM_CFG_PCL_CONNECTION_MAIN_RX(i,j)             (DCM_CFG_PCL_CONNECTION_MAIN(i,j)->DcmDslProtocolRx)
#define DCM_CFG_PCL_CONNECTION_MAIN_RX_PDUID(i,j,k)     (DCM_CFG_PCL_CONNECTION_MAIN(i,j)->DcmDslProtocolRx[k].DcmDslProtocolRxPduId)
#define DCM_CFG_PCL_CONNECTION_MAIN_RX_ADDR_TYPE(i,j,k) (DCM_CFG_PCL_CONNECTION_MAIN(i,j)->DcmDslProtocolRx[k].DcmDslProtocolRxAddrType)
#define DCM_CFG_PCL_CONNECTION_MAIN_TX(i,j)             (DCM_CFG_PCL_CONNECTION_MAIN(i,j)->DcmDslProtocolTx)
#define DCM_CFG_PCL_CONNECTION_MAIN_TX_PDUID(i,j)       (DCM_CFG_PCL_CONNECTION_MAIN(i,j)->DcmDslProtocolTx[0U].DcmDslProtocolTxPduRef)
#define DCM_CFG_PCL_CONNECTION_MAIN_TX_CONID(i,j)       (DCM_CFG_PCL_CONNECTION_MAIN(i,j)->DcmDslProtocolTx[0U].DcmDslTxConfirmationPduId)
#if(DCM_UDS_2A_ENABLED == STD_ON)
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#define DCM_CFG_PCL_CONNECTION_PERIODIC(i,j)            (Dcm_DslProtocolRow[i].DcmDslConnection[j].DcmDslPeriodicTransmission)
#else
#define DCM_CFG_PCL_CONNECTION_PERIODIC(i,j)            (Dcm_PBConfig->DcmDslConnection[i][j].DcmDslPeriodicTransmission)
#endif
#define DCM_CFG_PCL_CONNECTION_PERIODIC_NUM(i,j)        (DCM_CFG_PCL_CONNECTION_PERIODIC(i,j)->NumOfPeriodicConnection)
#define DCM_CFG_PCL_CONNECTION_PERIODIC_TX_PDUID(i,j,k) (DCM_CFG_PCL_CONNECTION_PERIODIC(i,j)->DcmDslPeriodicConnection[k].DcmDslPeriodicTxPduRef)
#define DCM_CFG_PCL_CONNECTION_PERIODIC_TX_CONID(i,j,k) (DCM_CFG_PCL_CONNECTION_PERIODIC(i,j)->DcmDslPeriodicConnection[k].DcmDslPeriodicTxConfirmationPduId)
#endif

#define DCM_CFG_STAB_ID               (Dcm_DsdServiceTable[DCM_CURRENT_STAB].DcmDsdSidTabId)
/*S means Service*/
#define DCM_CFG_STAB_S_NUM            (Dcm_DsdServiceTable[DCM_CURRENT_STAB].NumOfService)
#define DCM_CFG_STAB_S_INFO(Idx)      (Dcm_DsdServiceTable[DCM_CURRENT_STAB].DcmDsdService[Idx])
#define DCM_CFG_STAB_S_ID(Idx)        (DCM_CFG_STAB_S_INFO(Idx).DcmDsdSidTabServiceId)
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#define DCM_CFG_STAB_S_USED(Idx)      (DCM_CFG_STAB_S_INFO(Idx).DcmDsdServiceUsed)
#else
#define DCM_CFG_STAB_S_USED(Idx)      (Dcm_PBConfig->DcmDsdServiceUsed[DCM_CURRENT_STAB][Idx])
#endif
/*SS means Sub Service*/
#define DCM_CFG_STAB_SS_NUM           (Dcm_DsdServiceTable[DCM_CURRENT_STAB].NumOfSubService)
#define DCM_CFG_STAB_SS_INFO(Idx)     (Dcm_DsdServiceTable[DCM_CURRENT_STAB].DcmDsdSubService[Idx])
#define DCM_CFG_STAB_SS_ID(Idx)       (DCM_CFG_STAB_SS_INFO(Idx).DcmDsdSubServiceId)
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#define DCM_CFG_STAB_SS_USED(Idx)     (DCM_CFG_STAB_SS_INFO(Idx).DcmDsdSubServiceUsed)
#else
#define DCM_CFG_STAB_SS_USED(Idx)     (Dcm_PBConfig->DcmDsdSubServiceUsed[DCM_CURRENT_STAB][Idx])
#endif


#if(DCM_UDS_10_ENABLED == STD_ON)
#define DCM_CFG_SESSION_NUM             (Dcm_DspSession[DCM_CURRENT_STAB].NumOfSessionRow)
#define DCM_CFG_SESSION_ROW             (Dcm_DspSession[DCM_CURRENT_STAB].DcmDspSessionRow)
#define DCM_CFG_SESSION_BOOT(SesIdx)    (DCM_CFG_SESSION_ROW[SesIdx].DcmDspSessionBoot)
#define DCM_CFG_SESSION_LEVEL(SesIdx)   (DCM_CFG_SESSION_ROW[SesIdx].DcmDspSessionLevel)
#define DCM_CFG_SESSION_MASK(SesIdx)    (DCM_CFG_SESSION_ROW[SesIdx].DcmDspSessionMask)
#define DCM_CFG_SESSION_P2(SesIdx)      (DCM_CFG_SESSION_ROW[SesIdx].DcmDspSessionP2ServerMax)
#define DCM_CFG_SESSION_P2STAR(SesIdx)  (DCM_CFG_SESSION_ROW[SesIdx].DcmDspSessionP2StarServerMax)
#define DCM_CFG_SESSION_MODE(SesIdx)    (DCM_CFG_SESSION_ROW[SesIdx].DcmDspSessionSchMMode)
#else
#define DCM_CFG_SESSION_MASK(SesIdx)    (Dcm_SessionMaskType)0x00000001
#endif

#if(DCM_UDS_11_ENABLED == STD_ON)
#define DCM_CFG_RESET_NUM               (Dcm_DspEcuReset[DCM_CURRENT_STAB].NumOfEcuResetRow)
#define DCM_CFG_RESET_ROW               (Dcm_DspEcuReset[DCM_CURRENT_STAB].DcmDspEcuResetRow)
#define DCM_CFG_RESET_ID(Idx)           (DCM_CFG_RESET_ROW[Idx].DcmDspEcuResetId)
#define DCM_CFG_RESET_RESPONSE(Idx)     (DCM_CFG_RESET_ROW[Idx].DcmResponseToEcuReset)
#endif

#if(DCM_UDS_27_ENABLED == STD_ON)
#define DCM_CFG_SEC_NUM(StabIdx)                        (Dcm_DspSecurity[StabIdx].NumOfSecurityRow)
#define DCM_CFG_SEC_ROW(StabIdx)                        (Dcm_DspSecurity[StabIdx].DcmDspSecurityRow)
#define DCM_CFG_SEC_LEVEL(StabIdx, SecIdx)              (DCM_CFG_SEC_ROW(StabIdx)[SecIdx].DcmDspSecurityLevel)
#define DCM_CFG_SEC_ATT_NUM(StabIdx, SecIdx)            (DCM_CFG_SEC_ROW(StabIdx)[SecIdx].DcmDspSecurityNumAttDelay)

#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
#define DCM_CFG_SEC_KEY_ATT_NUM(StabIdx, SecIdx)        (DCM_CFG_SEC_ROW(StabIdx)[SecIdx].DcmDspSecurityNumKeyAttDelay)
#define DCM_CFG_SEC_SEED_ATT_NUM(StabIdx, SecIdx)       (DCM_CFG_SEC_ROW(StabIdx)[SecIdx].DcmDspSecurityNumSeedAttDelay)
#endif

#if(STD_ON == DCM_CFG_ADR_SUPPORT)
#define DCM_CFG_SEC_ADR_SIZE(StabIdx, SecIdx)           (DCM_CFG_SEC_ROW(StabIdx)[SecIdx].DcmDspSecurityADRSize)
#else
#define DCM_CFG_SEC_ADR_SIZE(StabIdx, SecIdx)           (Dcm_MsgLenType)0
#endif
#define DCM_CFG_SEC_SEED_SIZE(StabIdx, SecIdx)          (DCM_CFG_SEC_ROW(StabIdx)[SecIdx].DcmDspSecuritySeedSize)
#define DCM_CFG_SEC_KEY_SIZE(StabIdx, SecIdx)           (DCM_CFG_SEC_ROW(StabIdx)[SecIdx].DcmDspSecurityKeySize)
#define DCM_CFG_SEC_DELAYTIME(StabIdx, SecIdx)          ((DCM_CFG_SEC_ROW(StabIdx)[SecIdx].DcmDspSecurityDelayTime)/(uint32)DCM_TASK_TIME)
#define DCM_CFG_SEC_DELAYTIMEONBOOT(StabIdx, SecIdx)    ((DCM_CFG_SEC_ROW(StabIdx)[SecIdx].DcmDspSecurityDelayTimeOnBoot)/(uint32)DCM_TASK_TIME)
#define DCM_CFG_SEC_GETSEED_FNC(StabIdx, SecIdx)        (DCM_CFG_SEC_ROW(StabIdx)[SecIdx].DcmDspSecurityGetSeedFnc)
#define DCM_CFG_SEC_COMPAREKEY_FNC(StabIdx, SecIdx)     (DCM_CFG_SEC_ROW(StabIdx)[SecIdx].DcmDspSecurityCompareKeyFnc)
#if(STD_ON == DCM_CFG_ACCESS_ATTEMPT_COUNTER_SUPPORT)
#define DCM_CFG_SEC_ATT_EN(StabIdx, SecIdx)             (DCM_CFG_SEC_ROW(StabIdx)[SecIdx].DcmDspSecurityAttemptCounterEnabled)
#define DCM_CFG_SEC_GET_ATT_FNC(StabIdx, SecIdx)        (DCM_CFG_SEC_ROW(StabIdx)[SecIdx].DcmDspSecurityGetAttemptCounterFnc)
#define DCM_CFG_SEC_SET_ATT_FNC(StabIdx, SecIdx)        (DCM_CFG_SEC_ROW(StabIdx)[SecIdx].DcmDspSecuritySetAttemptCounterFnc)
#endif
#define DCM_CFG_SEC_MASK(StabIdx, SecIdx)               (DCM_CFG_SEC_ROW(StabIdx)[SecIdx].DcmDspSecurityMask)
#endif

#if(DCM_UDS_28_ENABLED == STD_ON)
#define DCM_CFG_COM_ALLCHL_NUM                 (Dcm_DspComControl[DCM_CURRENT_STAB].NumOfControlAllChannel)
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#define DCM_CFG_COM_ALLCHL                     (Dcm_DspComControl[DCM_CURRENT_STAB].DcmDspComControlAllChannel)
#else
#define DCM_CFG_COM_ALLCHL                     (Dcm_PBConfig->DcmDspComControlAllChannel[DCM_CURRENT_STAB])
#endif
#define DCM_CFG_COM_ALLCHL_USED(i)             (DCM_CFG_COM_ALLCHL[i].DcmDspComControlAllChannelUsed)
#define DCM_CFG_COM_ALLCHL_REF(i)              (DCM_CFG_COM_ALLCHL[i].DcmDspAllComMChannelRef)
#define DCM_CFG_COM_ALLCHL_SWITCH_FNC(i)       (DCM_CFG_COM_ALLCHL[i].SwitchCommunicationControlAllChannelFnc)

#define DCM_CFG_COM_SPECHL_NUM                 (Dcm_DspComControl[DCM_CURRENT_STAB].NumOfControlSpecificChannel)
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#define DCM_CFG_COM_SPECHL                     (Dcm_DspComControl[DCM_CURRENT_STAB].DcmDspComControlSpecificChannel)
#else
#define DCM_CFG_COM_SPECHL                     (Dcm_PBConfig->DcmDspComControlSpecificChannel[DCM_CURRENT_STAB])
#endif
#define DCM_CFG_COM_SPECHL_USED(i)             (DCM_CFG_COM_SPECHL[i].DcmDspComControlSpecificChannelUsed)
#define DCM_CFG_COM_SPECHL_REF(i)              (DCM_CFG_COM_SPECHL[i].DcmDspComMChannelRef)
#define DCM_CFG_COM_SPECHL_SWITCH_FNC(i)       (DCM_CFG_COM_SPECHL[i].SwitchCommunicationControlSpecificChannelFnc)
#define DCM_CFG_COM_SPECHL_NETNUN(i)           (DCM_CFG_COM_SPECHL[i].DcmDspSubnetNumber)

#define DCM_CFG_COM_SUBNODE_NUM                (Dcm_DspComControl[DCM_CURRENT_STAB].NumOfControlSubNode)
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#define DCM_CFG_COM_SUBNODE                    (Dcm_DspComControl[DCM_CURRENT_STAB].DcmDspComControlSubNode)
#else
#define DCM_CFG_COM_SUBNODE                    (Dcm_PBConfig->DcmDspComControlSubNode[DCM_CURRENT_STAB])
#endif
#define DCM_CFG_COM_SUBNODE_USED(i)            (DCM_CFG_COM_SUBNODE[i].DcmDspComControlSubNodeUsed)
#define DCM_CFG_COM_SUBNODE_CHLREF(i)          (DCM_CFG_COM_SUBNODE[i].DcmDspComControlSubNodeComMChannelRef)
#define DCM_CFG_COM_SUBNODE_CHL_SWITCH_FNC(i)  (DCM_CFG_COM_SUBNODE[i].SwitchCommunicationControlSubNodeFnc)
#define DCM_CFG_COM_SUBNODE_ID(i)              (DCM_CFG_COM_SUBNODE[i].DcmDspComControlSubNodeId)
#endif

#if(DCM_UDS_29_ENABLED == STD_ON)
#define DCM_CFG_AU_CHALLENGE_LEN(ConId)        (Dcm_DspAuthenticationConnection[ConId].DcmDspAuthenticationEcuChallengeLength)
#define DCM_CFG_AU_RANDOM_IS_SYNC(ConId)       (Dcm_DspAuthenticationConnection[ConId].DcmDspAuthenticationRandomJobIsSync)
#define DCM_CFG_AU_RANDOM_JOB(ConId)           (Dcm_DspAuthenticationConnection[ConId].DcmDspAuthenticationRandomJobRef)
#define DCM_CFG_AU_SIGN_JOB(ConId)             (Dcm_DspAuthenticationConnection[ConId].DcmDspAuthenticationClientChallengeSignJobRef)
#define DCM_CFG_AU_VERIFY_JOB(ConId)           (Dcm_DspAuthenticationConnection[ConId].DcmDspAuthenticationVerifyProofOfOwnerShipClientJobRef)
#define DCM_CFG_AU_CONNECTION_CERT(ConId)      (Dcm_DspAuthenticationConnection[ConId].DcmDspAuthenticationConnectionCertificateRef)
#define DCM_CFG_AU_ECU_CERT(ConId)             (Dcm_DspAuthenticationConnection[ConId].DcmDspAuthenticationECUCertificateRef)
#define DCM_CFG_AU_ROLE_REF(ConId)             (Dcm_DspAuthenticationConnection[ConId].RoleRef)
#if(DCM_DSP_AUTHENTICATION_SERVICE_MAX_SIZE > 0)
#define DCM_CFG_AU_SERVICE_REF(ConId)          (Dcm_DspAuthenticationConnection[ConId].WhiteListServicesRef)
#endif
#if(DCM_DSP_AUTHENTICATION_DID_MAX_SIZE > 0)
#define DCM_CFG_AU_DID_REF(ConId)              (Dcm_DspAuthenticationConnection[ConId].WhiteListDIDRef)
#endif
#if(DCM_DSP_AUTHENTICATION_RID_MAX_SIZE > 0)
#define DCM_CFG_AU_RID_REF(ConId)              (Dcm_DspAuthenticationConnection[ConId].WhiteListRIDRef)
#endif
#if(DCM_DSP_AUTHENTICATION_MEM_MAX_SIZE > 0)
#define DCM_CFG_AU_MEM_REF(ConId)              (Dcm_DspAuthenticationConnection[ConId].WhiteListMemorySelectionRef)
#endif
#define DCM_CFG_AU_MODE_FNC(ConId)             (Dcm_DspAuthenticationConnection[ConId].AuthenticationStateModeSwitchInterface)
#endif/*#if(DCM_UDS_29_ENABLED == STD_ON)*/

#if((DCM_UDS_22_ENABLED == STD_ON) || (DCM_UDS_2A_ENABLED == STD_ON) || (DCM_UDS_2C_ENABLED == STD_ON) \
    ||(DCM_UDS_2E_ENABLED == STD_ON) || (DCM_UDS_2F_ENABLED == STD_ON))
#define DCM_CFG_DID_NUM               (Dcm_DspDid[DCM_CURRENT_STAB].NumOfDid)
#define DCM_CFG_DID_TABLE             (Dcm_DspDid[DCM_CURRENT_STAB].Dcm_DspDidTable)
#define DCM_CFG_DATA_NUM              (Dcm_DspData[DCM_CURRENT_STAB].NumOfDidData)
#define DCM_CFG_DATA_TABLE            (Dcm_DspData[DCM_CURRENT_STAB].DcmDspDataTable)

#define DCM_CFG_DID_ID(DidIdx)        (DCM_CFG_DID_TABLE[DidIdx].DcmDspDidIdentifier)
#define DCM_CFG_DID_SIZE(DidIdx)      (DCM_CFG_DID_TABLE[DidIdx].DcmDspDidSize)
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#define DCM_CFG_DID_USED(DidIdx)      (DCM_CFG_DID_TABLE[DidIdx].DcmDspDidUsed)
#else
#define DCM_CFG_DID_USED(DidIdx)      (Dcm_PBConfig->DcmDspDidUsed[DCM_CURRENT_STAB][DidIdx])
#endif
#define DCM_CFG_DID_SIG_NUM(DidIdx)   (DCM_CFG_DID_TABLE[DidIdx].NumOfDidSignal)
#define DCM_CFG_DID_SIG_OFFSET(DidIdx, SigIdx) (DCM_CFG_DID_TABLE[DidIdx].DcmDspDidSignal[SigIdx].DcmDspDidByteOffset)
#define DCM_CFG_DID_SIG_REF(DidIdx, SigIdx)    (DCM_CFG_DID_TABLE[DidIdx].DcmDspDidSignal[SigIdx].DcmDspDidDataRef)


#define DCM_CFG_DATA_SIZE(DataIdx)             (DCM_CFG_DATA_TABLE[DataIdx].DcmDspDataByteSize)
#define DCM_CFG_DATA_TYPE(DataIdx)             (DCM_CFG_DATA_TABLE[DataIdx].DcmDspDataType)
#define DCM_CFG_DATA_USEPORT(DataIdx)          (DCM_CFG_DATA_TABLE[DataIdx].DcmDspDataUsePort)
#if(DCM_NVM_SUPPORT == STD_ON)
#define DCM_CFG_DATA_BLOCKID(DataIdx)          (DCM_CFG_DATA_TABLE[DataIdx].DcmDspDataBlockIdRef)
#endif
#endif

#if((DCM_UDS_22_ENABLED == STD_ON) || (DCM_UDS_2A_ENABLED == STD_ON))
#define DCM_CFG_DID_INFO_READ(DidIdx)          (DCM_CFG_DID_TABLE[DidIdx].DcmDspDidInfoRef.DcmDspDidRead)
#endif
#if((DCM_UDS_22_ENABLED == STD_ON) || (DCM_UDS_2A_ENABLED == STD_ON) || (DCM_UDS_2F_ENABLED == STD_ON))
#define DCM_CFG_DATA_CON_EN(DataIdx)           (DCM_CFG_DATA_TABLE[DataIdx].DcmDspDataConditionCheckReadFncUsed)
#define DCM_CFG_DATA_CON_CHECK_FNC(DataIdx)    (DCM_CFG_DATA_TABLE[DataIdx].DcmDspDataConditionCheckReadFnc)
#define DCM_CFG_DATA_LENGTH_FNC(DataIdx)       (DCM_CFG_DATA_TABLE[DataIdx].DcmDspDataReadDataLengthFnc)
#define DCM_CFG_DATA_READ_FNC(DataIdx)         (DCM_CFG_DATA_TABLE[DataIdx].DcmDspDataReadFnc)
#endif

#if(DCM_UDS_2C_ENABLED == STD_ON)
#define DCM_CFG_DID_INFO_DDDID_MAX_ELE(DidIdx)      (DCM_CFG_DID_TABLE[DidIdx].DcmDspDidInfoRef.DcmDspDDDIDMaxElements)
#define DCM_CFG_DID_INFO_DYN_DEF(DidIdx)            (DCM_CFG_DID_TABLE[DidIdx].DcmDspDidInfoRef.DcmDspDidDynamicallyDefined)
#define DCM_CFG_DID_INFO_DDDID_BUF_IDX(DidIdx)      (DCM_CFG_DID_TABLE[DidIdx].DcmDspDidInfoRef.DcmDspDDDIDBufferIndex)
#endif

#if(DCM_UDS_2E_ENABLED == STD_ON)
#define DCM_CFG_DID_INFO_WRITE(DidIdx)              (DCM_CFG_DID_TABLE[DidIdx].DcmDspDidInfoRef.DcmDspDidWrite)
#define DCM_CFG_DATA_WRITE_FNC(DataIdx)             (DCM_CFG_DATA_TABLE[DataIdx].DcmDspDataWriteFnc)
#endif

#if(DCM_UDS_2F_ENABLED == STD_ON)
#define DCM_CFG_DID_INFO_CONTROL(DidIdx)            (DCM_CFG_DID_TABLE[DidIdx].DcmDspDidInfoRef.DcmDspDidControl)
#define DCM_CFG_DID_CONTROL_MASK(DidIdx)            (DCM_CFG_DID_INFO_CONTROL(DidIdx)->DcmDspDidControlMask)
#define DCM_CFG_DID_CONTROL_MASK_SIZE(DidIdx)       (DCM_CFG_DID_INFO_CONTROL(DidIdx)->DcmDspDidControlMaskSize)
#define DCM_CFG_DID_CONTROL_FREEZE(DidIdx)          (DCM_CFG_DID_INFO_CONTROL(DidIdx)->DcmDspDidFreezeCurrentState)
#define DCM_CFG_DID_CONTROL_RESET(DidIdx)           (DCM_CFG_DID_INFO_CONTROL(DidIdx)->DcmDspDidResetToDefault)
#define DCM_CFG_DID_CONTROL_SHORT(DidIdx)           (DCM_CFG_DID_INFO_CONTROL(DidIdx)->DcmDspDidShortTermAdjustment)
#define DCM_CFG_DID_CONTROL_EN_MASK_NUM(DidIdx)     (DCM_CFG_DID_INFO_CONTROL(DidIdx)->NumOfControlEnableMask)
#define DCM_CFG_DID_CONTROL_EN_MASK(DidIdx)         (DCM_CFG_DID_INFO_CONTROL(DidIdx)->DcmDspDidControlEnableMask)
#define DCM_CFG_DID_CONTROL_EN_MASK_POS(DidIdx, Idx)   (DCM_CFG_DID_CONTROL_EN_MASK(DidIdx)[Idx].DcmDspDidControlMaskBitPosition)
#define DCM_CFG_DID_CONTROL_ADDRREF(DidIdx)         (DCM_CFG_DID_INFO_CONTROL(DidIdx)->DcmDspDidControlSupportAddress)
#define DCM_CFG_DID_CONTROL_SESREF(DidIdx)          (DCM_CFG_DID_INFO_CONTROL(DidIdx)->DcmDspDidControlSessionRef)
#if(DCM_UDS_27_ENABLED == STD_ON)
#define DCM_CFG_DID_CONTROL_SECREF(DidIdx)          (DCM_CFG_DID_INFO_CONTROL(DidIdx)->DcmDspDidControlSecurityLevelRef)
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
#define  DCM_CFG_DID_CONTROL_ROLEREF(DidIdx)         (DCM_CFG_DID_INFO_CONTROL(DidIdx)->DcmDspDidControlRoleRef)
#endif
#define DCM_CFG_DATA_RETURN_FNC(DataIdx)            (DCM_CFG_DATA_TABLE[DataIdx].DcmDspDataReturnControlToECUFnc)
#define DCM_CFG_DATA_RESET_FNC(DataIdx)             (DCM_CFG_DATA_TABLE[DataIdx].DcmDspDataResetToDefaultFnc)
#define DCM_CFG_DATA_FREEZE_FNC(DataIdx)            (DCM_CFG_DATA_TABLE[DataIdx].DcmDspDataFreezeCurrentStateFnc)
#define DCM_CFG_DATA_SHORT_FNC(DataIdx)             (DCM_CFG_DATA_TABLE[DataIdx].DcmDspDataShortTermAdjustmentFnc)
#endif/*#if(DCM_UDS_2F_ENABLED == STD_ON)*/

#if((DCM_UDS_23_ENABLED == STD_ON) || (DCM_UDS_3D_ENABLED == STD_ON) || (DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON))
#define DCM_CFG_MEM                     (Dcm_DspMemory[DCM_CURRENT_STAB])
#define DCM_CFG_MEM_FORMAT_NUM          (DCM_CFG_MEM.NumOfFormat)
#define DCM_CFG_MEM_FORMAT(MemIdx)      (DCM_CFG_MEM.DcmDspSupportedAddressAndLengthFormatIdentifier[MemIdx])
#define DCM_CFG_MEM_ID_NUM              (DCM_CFG_MEM.NumOfMemoryId)
#define DCM_CFG_MEM_ID_INFO(MemIdx)     (DCM_CFG_MEM.DcmDspMemoryIdInfo[MemIdx])
#define DCM_CFG_MEM_ID_VALUE(MemIdx)    (DCM_CFG_MEM_ID_INFO(MemIdx).DcmDspMemoryIdValue)
#endif

#if((DCM_UDS_23_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON))
#define DCM_CFG_MEM_ID_READ_NUM(MemIdx)           (DCM_CFG_MEM_ID_INFO(MemIdx).NumofReadMemory)
#define DCM_CFG_MEM_ID_READ_INFO(MemIdx)          (DCM_CFG_MEM_ID_INFO(MemIdx).DcmDspReadMemoryRangeInfo)
#define DCM_CFG_MEM_ID_READ_HIGH(MemIdx, Idx)     (DCM_CFG_MEM_ID_INFO(MemIdx).DcmDspReadMemoryRangeInfo[Idx].DcmDspReadMemoryRangeHigh)
#define DCM_CFG_MEM_ID_READ_LOW(MemIdx, Idx)      (DCM_CFG_MEM_ID_INFO(MemIdx).DcmDspReadMemoryRangeInfo[Idx].DcmDspReadMemoryRangeLow)
#if(STD_ON == DCM_UDS_27_ENABLED)
#define DCM_CFG_MEM_ID_READ_SECREF(MemIdx, Idx)   (DCM_CFG_MEM_ID_INFO(MemIdx).DcmDspReadMemoryRangeInfo[Idx].DcmDspReadMemoryRangeSecurityLevelRef)
#endif
#if(STD_ON == DCM_UDS_29_ENABLED)
#define DCM_CFG_MEM_ID_READ_ROLEREF(MemIdx, Idx)  (DCM_CFG_MEM_ID_INFO(MemIdx).DcmDspReadMemoryRangeInfo[Idx].DcmDspReadMemoryRangeRoleRef)
#endif
#define DCM_CFG_MEM_ID_READ_SESREF(MemIdx, Idx)   (DCM_CFG_MEM_ID_INFO(MemIdx).DcmDspReadMemoryRangeInfo[Idx].DcmDspReadMemoryRangeSessionLevelRef)
#endif

#if((DCM_UDS_3D_ENABLED == STD_ON) || (DCM_UDS_34_ENABLED == STD_ON))
#define DCM_CFG_MEM_ID_WRITE_NUM(MemIdx)          (DCM_CFG_MEM_ID_INFO(MemIdx).NumofWriteMemory)
#define DCM_CFG_MEM_ID_WRITE_INFO(MemIdx)         (DCM_CFG_MEM_ID_INFO(MemIdx).DcmDspWriteMemoryRangeInfo)
#define DCM_CFG_MEM_ID_WRITE_HIGH(MemIdx, Idx)    (DCM_CFG_MEM_ID_INFO(MemIdx).DcmDspWriteMemoryRangeInfo[Idx].DcmDspWriteMemoryRangeHigh)
#define DCM_CFG_MEM_ID_WRITE_LOW(MemIdx, Idx)     (DCM_CFG_MEM_ID_INFO(MemIdx).DcmDspWriteMemoryRangeInfo[Idx].DcmDspWriteMemoryRangeLow)
#if(STD_ON == DCM_UDS_27_ENABLED)
#define DCM_CFG_MEM_ID_WRITE_SECREF(MemIdx, Idx)  (DCM_CFG_MEM_ID_INFO(MemIdx).DcmDspWriteMemoryRangeInfo[Idx].DcmDspWriteMemoryRangeSecurityLevelRef)
#endif
#if(STD_ON == DCM_UDS_29_ENABLED)
#define DCM_CFG_MEM_ID_WRITE_ROLEREF(MemIdx, Idx) (DCM_CFG_MEM_ID_INFO(MemIdx).DcmDspWriteMemoryRangeInfo[Idx].DcmDspWriteMemoryRangeRoleRef)
#endif
#define DCM_CFG_MEM_ID_WRITE_SESREF(MemIdx, Idx)  (DCM_CFG_MEM_ID_INFO(MemIdx).DcmDspWriteMemoryRangeInfo[Idx].DcmDspWriteMemoryRangeSessionLevelRef)
#endif


#if(STD_ON == DCM_UDS_31_ENABLED)
#define DCM_CFG_ROUTINE                 (Dcm_DspRoutine[DCM_CURRENT_STAB])
#define DCM_CFG_ROUTINE_NUM             (DCM_CFG_ROUTINE.NumOfRoutineId)
#define DCM_CFG_ROUTINE_INFO            (DCM_CFG_ROUTINE.DcmDspRoutineIdInfo)
#define DCM_CFG_ROUTINE_ID(Idx)         (DCM_CFG_ROUTINE_INFO[Idx].DcmDspRoutineIdentifier)
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#define DCM_CFG_ROUTINE_USED(Idx)       (DCM_CFG_ROUTINE_INFO[Idx].DcmDspRoutineUsed)
#else
#define DCM_CFG_ROUTINE_USED(Idx)       (Dcm_PBConfig->DcmDspRoutineUsed[DCM_CURRENT_STAB][Idx])
#endif
#define DCM_CFG_ROUTINE_START(Idx)      (DCM_CFG_ROUTINE_INFO[Idx].DcmDspStartRoutine)
#define DCM_CFG_ROUTINE_STOP(Idx)       (DCM_CFG_ROUTINE_INFO[Idx].DcmDspStopRoutine)
#define DCM_CFG_ROUTINE_RESULT(Idx)     (DCM_CFG_ROUTINE_INFO[Idx].DcmDspRequestRoutineResults)
#endif/*#if(STD_ON == DCM_UDS_31_ENABLED)*/



/*******************************************************************************
* typedef of static vars
*******************************************************************************/
/*Running state of Dcm module */
typedef uint16 Dcm_RunningStateType;
#define DCM_IDLE                    ((Dcm_RunningStateType)0x0000)
#define DCM_PROCESSING              ((Dcm_RunningStateType)0x0002)
#define DCM_PROCESSING_DONE         ((Dcm_RunningStateType)0x0004)
#define DCM_RCRRP                   ((Dcm_RunningStateType)0x0008)
#define DCM_RCRRP_FORCE             ((Dcm_RunningStateType)0x0010)
#define DCM_RCRRP_FORCE_OK          ((Dcm_RunningStateType)0x0020)
#define DCM_PERIODIC_TX             ((Dcm_RunningStateType)0x0040)
/*#define DCM_RCRRP_REPEATTX          ((Dcm_RunningStateType)0x0080)*/

#if(DCM_COMM_SUPPORT == STD_ON)
/*Dcm_ComM_ModeType*/
typedef enum
{
    DCM_COMM_NOCOM     = 0,
    DCM_COMM_SILENTCOM = 1,
    DCM_COMM_FULLCOM   = 2
} Dcm_ComM_ModeType;
#endif

#if((DCM_DEM_SUPPORT == STD_ON) && ((DCM_UDS_14_ENABLED == STD_ON) || (DCM_UDS_19_ENABLED == STD_ON)))
typedef struct
{
    uint8 DtcStatus;
    Dem_DTCSeverityType DtcSeverity;
    uint8 DtcRecordNum;
    uint16 DtcCounter;
    uint32 Dtc;
} Dcm_DtcInfoType;
#endif

#if(DCM_UDS_27_ENABLED == STD_ON)
typedef struct
{
    /*This parameter indicates whether a security level has been initialized*/
    boolean SecurityLevelInitialized;
    uint8 AcessAttempNum;
#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
    uint8 AcessKeyAttempNum;
    uint8 AcessSeedAttempNum;
#endif
    boolean DelayTimeOnBoot;
    boolean AcessSequence;
    uint32 AcessDelayTime;
} Dcm_SecLevelStateType;

typedef struct
{
    /*Index of SecurityRow[]*/
    uint8 SecurityIndex;
    /*This parameter indicates whether the 0x27 service is initialized*/
    boolean SecurityInitialized;
    Dcm_SecLevelStateType SecLevelState[DCM_CFG_NUM_OF_STAB][DCM_CFG_NUM_SECURITY_LEVEL];
    uint32 ReadoutTimer;
} Dcm_SecurityContextType;
#endif

#if((DCM_UDS_22_ENABLED == STD_ON) || (DCM_UDS_2A_ENABLED == STD_ON) || (DCM_UDS_2C_ENABLED == STD_ON) \
    || (DCM_UDS_2E_ENABLED == STD_ON) || (DCM_UDS_2F_ENABLED == STD_ON))
typedef struct
{
#if(DCM_UDS_22_ENABLED == STD_ON)
    uint16 DidCounter;
    uint16 DidPos;/*Did Position of DidIndexList*/
#endif
#if((DCM_UDS_22_ENABLED == STD_ON) || (DCM_UDS_2F_ENABLED == STD_ON))
    uint16 DidDataLength;/*include Did length and all data(signals) length*/
    Dcm_MsgType DidRespDataPtr;
    Dcm_MsgLenType DidRespDataLen;
#endif
#if((DCM_UDS_22_ENABLED == STD_ON) || (DCM_UDS_2E_ENABLED == STD_ON) || (DCM_UDS_2F_ENABLED == STD_ON))
    uint16 DidSignalIndex;/*Signal index in one DID*/
    Dcm_OpStatusType DidOpStatus;/*Operation status of DID*/
#endif
#if(DCM_UDS_2A_ENABLED == STD_ON)
    uint8 CurrentDidService;
    uint8 PeriodicSchedulerIndex;
    uint8 PeriodicSchedulerUsedNum;
#endif
#if(DCM_UDS_2C_ENABLED == STD_ON)
    Dcm_DspDDDIDType DcmDspDDDID[DCM_CFG_DDDID_NUM];
    Dcm_DspDDDIDElementInfoType DcmDspDDDIDElement[DCM_CFG_ALL_DDDID_ELEMENT_NUM];
#endif
#if((DCM_UDS_2E_ENABLED == STD_ON) || (DCM_UDS_2F_ENABLED == STD_ON))
    uint16 WriteControlDidIndex;
#endif
#if(DCM_UDS_2F_ENABLED == STD_ON)
    uint8 InputOutputControlParameter;
#endif
} Dcm_DidContextType;
#endif

#if(DCM_UDS_28_ENABLED == STD_ON)
typedef struct
{
    uint8 ComControlNmMessageState[DCM_NUM_COMM_CHANNEL];
    uint8 ComControlAppMessageState[DCM_NUM_COMM_CHANNEL];
    uint8 ComControlReqSubService;
    Dcm_SessionMaskType ComControlServiceSupportSession;
    uint8 ComControlReqMsgType;
    uint8 ComControlReqSubNet;
    uint16 ComControlReqSubNode;
} Dcm_ComCtrlContextType;
#endif

#if(DCM_UDS_29_ENABLED == STD_ON)
typedef uint8 Dcm_AuthenticationStateType;

#define DCM_AU_STATE_DEAUTHENTICATED   (Dcm_AuthenticationStateType)0x00
#define DCM_AU_STATE_CERTIFICATE_U     (Dcm_AuthenticationStateType)0x01
#define DCM_AU_STATE_CERTIFICATE_B     (Dcm_AuthenticationStateType)0x02
#define DCM_AU_STATE_AUTHENTICATED     (Dcm_AuthenticationStateType)0x04

typedef struct
{
    Dcm_AuRoleMaskType AuthenticationDeauthenticatedRole[DCM_CFG_NUM_OF_CONNECTION];
#if(DCM_DSP_AUTHENTICATION_SERVICE_MAX_SIZE > 0)
    uint8 AuthenticationWhiteListService[DCM_DSP_AUTHENTICATION_SERVICE_MAX_SIZE];
#endif
#if(DCM_DSP_AUTHENTICATION_DID_MAX_SIZE > 0)
    uint8 AuthenticationWhiteListDID[DCM_DSP_AUTHENTICATION_DID_MAX_SIZE];
#endif
#if(DCM_DSP_AUTHENTICATION_RID_MAX_SIZE > 0)
    uint8 AuthenticationWhiteListRID[DCM_DSP_AUTHENTICATION_RID_MAX_SIZE];
#endif
#if(DCM_DSP_AUTHENTICATION_MEM_MAX_SIZE > 0)
    uint8 AuthenticationWhiteListMem[DCM_DSP_AUTHENTICATION_MEM_MAX_SIZE];
#endif
    Dcm_AuthenticationStateType AuthenticationState;
    boolean AuthenticationDevelopmentStateEnabled;
    boolean AuthenticationResultIndicated;
    KeyM_CertificateIdType AuthenticationCertID;
    KeyM_CertificateStatusType AuthenticationCertResult;
    Crypto_ResultType AuthenticationCsmResult;
    Crypto_VerifyResultType AuthenticationVerifyResult;
    uint32 AuthenticationDataLength;
    uint8 AuthenticationChallenge[DCM_CFG_MAX_CHALLENGE_LENGTH];
    uint8 AuthenticationProof[DCM_CFG_MAX_PROOF_LENGTH];
    Dcm_AuRoleMaskType AuthenticationCurrentRole;
    uint32 AuthenticationTimeoutTimer;
#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
    uint16 AuConsecutiveFailedCounter[DCM_CFG_NUM_OF_CONNECTION];
    uint32 AuDelayTimer[DCM_CFG_NUM_OF_CONNECTION];
    uint32 AuChallengeResponseTimeoutTimer;
    uint32 AuAbsoluteTimeoutTimer;
#endif
} Dcm_AuthenticationContextType;
#endif

#if((DCM_UDS_23_ENABLED == STD_ON) || (DCM_UDS_3D_ENABLED == STD_ON))
typedef struct
{
    uint32 MemoryStartAddr;
    uint32 MemorySize;
    uint8 MemoryId;
    uint8 *MemoryDataPtr;
} Dcm_MemoryContextType;
#endif

#if((DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON) || (DCM_UDS_38_ENABLED == STD_ON))
typedef enum
{
    DCM_LOAD_NONE           = 0,
    DCM_LOAD_DOWN           = 1,
    DCM_LOAD_UP             = 2,
    DCM_LOAD_FILE_TRANSFER  = 3
} Dcm_LoadStatusType;

typedef struct
{
#if((DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON))
    uint32 DownUpLoadMemoryAddress;
    uint32 DownUpLoadMemorySize;
    uint32 MaxNumberOfBytesForWriteReadMemory;
    uint8 DownUpLoadMemoryId;
#endif
#if(DCM_UDS_38_ENABLED == STD_ON)
    uint8 ModeOfOperation;
    uint16 FilePathAndNameLength;
    P2VAR(uint8, AUTOMATIC, DCM_VAR) FilePathAndName;
    uint64 FileSizeUncompressed;
    uint64 FileSizeCompressed;
    uint64 MaxNumberOfBlockLength;
#endif
    uint8 DownUpLoadNextBlockSequenceCounter;
    uint8 DownUpLoadPreviousBlockSequenceCounter;
    uint8 DataFormatIdentifier;
    Dcm_LoadStatusType LoadStatus;
} Dcm_DownUpLoadContextType;
#endif/*#if((DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON) || (DCM_UDS_38_ENABLED == STD_ON))*/


#if(DCM_UDS_31_ENABLED == STD_ON)
typedef enum
{
    DCM_ROUTINE_NONE     = 0,
    DCM_ROUTINE_STARTED  = 1,
    DCM_ROUTINE_STOPPED  = 2
} Dcm_RoutineStatusType;

typedef struct
{
    uint16 RoutineIdIndex;
    P2CONST(Dcm_DspRoutineControlType, AUTOMATIC, DCM_APPL_DATA) RoutineControlInfo;
    Dcm_RoutineStatusType RoutineStatus[DCM_CFG_RID_NUM];
} Dcm_RoutineContextType;
#endif

typedef struct
{
    PduIdType RxPduId;
    Dcm_MsgLenType reqDataLen;
    Dcm_MsgLenType CopyDataIndex;
    uint8 ConnectionId;
    uint8 RxId;
    Dcm_NegativeResponseCodeType ErrorCode;
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
    uint8 NegativeRespBuffer[DCM_UDS_WITH_NRC22_RES_LEN];
#else
    uint8 NegativeRespBuffer[DCM_UDS_NEG_RES_LEN];
#endif
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
    uint8 *RxBufferPtr;
    Dcm_MsgLenType CopyTxDataIndex;
    uint8 RxBufferIndex;
#endif
} Dcm_ProtocolInfoType;

typedef struct
{
    Dcm_RunningStateType ModuleRunningState;
    boolean RxIndicationFlag;
    uint8 ResponsePendingCounter;
    uint8 CurrentExecutionStep;
    uint32 P2Timer;
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
    uint32 P4Timer;
#endif
    uint32 S3Timer;
#if(DCM_COMM_SUPPORT == STD_ON)
    boolean ActiveDiagnostic;
    Dcm_ComM_ModeType ComMMode[DCM_NUM_COMM_CHANNEL];
#endif
    uint8 ProtocolRxId;
    uint8 ProtocolFunctionAddressRxId;
    /*It is used to record diagnostic requests and negative responses related to protocols*/
    Dcm_ProtocolInfoType ProtocolInfo[DCM_CFG_NUM_OF_PROTOCOL];

    Dcm_OpStatusType OpStatus;
    Dcm_MsgContextType MsgContext;
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
    Dcm_BufferListType *RxMsgContextList;
#endif
    uint8 ReqService;
    const Dcm_DsdServiceType *ReqServiceInfo;
    EcucFunctionServiceFncDef ServiceFnc;
    uint8 RowIndex;
    uint8 ReqSubService;
    const Dcm_DsdSubServiceType *ReqSubServiceInfo;
    EcucFunctionServiceFncDef SubServiceFnc;
    Dcm_NegativeResponseCodeType *pErrorCode;
} Dcm_ContextType;


/*******************************************************************************
* Static vars
*******************************************************************************/
#define DCM_START_SEC_VAR_INIT_GLOBAL_8
#include "Dcm_MemMap.h"
STATIC VAR(Std_InitStateType, DCM_VAR) Dcm_InitState = STD_UNINITIALIZED;
#define DCM_STOP_SEC_VAR_INIT_GLOBAL_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_INIT_LOCAL_8
#include "Dcm_MemMap.h"
#if(DCM_UDS_87_ENABLED == STD_ON)
STATIC VAR(uint8, DCM_VAR) Dcm_LinkControlVerifiedService = DCM_DATA_CLEAR;
#endif
#define DCM_STOP_SEC_VAR_INIT_LOCAL_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_LOCAL_8
#include "Dcm_MemMap.h"
VAR(uint8, DCM_VAR) Dcm_ProtocolId;
VAR(uint8, DCM_VAR) Dcm_ProtocolConnectionId;/*Index of a connection in a protocaol*/
/*Index of SessionRow[]*/
VAR(uint8, DCM_VAR) Dcm_SessionIndex;
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
VAR(boolean, DCM_VAR) Dcm_RxPduProcessingStatus[DCM_CFG_RXPDU_NUM];
#endif
#define DCM_STOP_SEC_VAR_CLEARED_LOCAL_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "Dcm_MemMap.h"

#if(DCM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
P2CONST(Dcm_ConfigType, DCM_VAR, DCM_CONST) Dcm_PBConfig;
#endif

/*Common parameters*/
STATIC VAR(Dcm_ContextType, DCM_VAR) Dcm_Context;

#if((DCM_DEM_SUPPORT == STD_ON) && ((DCM_UDS_14_ENABLED == STD_ON) || (DCM_UDS_19_ENABLED == STD_ON)))
STATIC VAR(Dcm_DtcInfoType, DCM_VAR) Dcm_DtcInfo;
#endif

#if(DCM_UDS_27_ENABLED == STD_ON)
STATIC VAR(Dcm_SecurityContextType, DCM_VAR) Dcm_SecurityContext;
#endif
#if((DCM_UDS_22_ENABLED == STD_ON) || (DCM_UDS_2A_ENABLED == STD_ON) || (DCM_UDS_2C_ENABLED == STD_ON) \
    || (DCM_UDS_2E_ENABLED == STD_ON) || (DCM_UDS_2F_ENABLED == STD_ON))
STATIC VAR(Dcm_DidContextType, DCM_VAR) Dcm_DidContext;
#endif
#if(DCM_UDS_28_ENABLED == STD_ON)
STATIC VAR(Dcm_ComCtrlContextType, DCM_VAR) Dcm_ComCtrlContext;
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
STATIC VAR(Dcm_AuthenticationContextType, DCM_VAR) Dcm_AuthenticationContext;
#endif
#if((DCM_UDS_23_ENABLED == STD_ON) || (DCM_UDS_3D_ENABLED == STD_ON))
STATIC VAR(Dcm_MemoryContextType, DCM_VAR) Dcm_MemoryContext;
#endif
#if((DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON) || (DCM_UDS_38_ENABLED == STD_ON))
STATIC VAR(Dcm_DownUpLoadContextType, DCM_VAR) Dcm_DownUpLoadContext;
#endif
#if(DCM_UDS_31_ENABLED == STD_ON)
STATIC VAR(Dcm_RoutineContextType, DCM_VAR) Dcm_RoutineContext;
#endif

#define DCM_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_LOCAL_32
#include "Dcm_MemMap.h"
#if(DCM_UDS_85_ENABLED == STD_ON)
STATIC VAR(Dcm_SessionMaskType, DCM_VAR) Dcm_DtcSettingSubServiceSessionRef;
#endif
#define DCM_STOP_SEC_VAR_CLEARED_LOCAL_32
#include "Dcm_MemMap.h"
/*******************************************************************************
* Macros of static vars
*******************************************************************************/
#if((DCM_DEM_SUPPORT == STD_ON) && ((DCM_UDS_14_ENABLED == STD_ON) || (DCM_UDS_19_ENABLED == STD_ON)))
#define DCM_DTC_STATUS                (Dcm_DtcInfo.DtcStatus)
#define DCM_DTC_SEVERITY              (Dcm_DtcInfo.DtcSeverity)
#define DCM_DTC_RECORDNUM             (Dcm_DtcInfo.DtcRecordNum)
#define DCM_DTC_COUNTER               (Dcm_DtcInfo.DtcCounter)
#define DCM_DTC_DTC                   (Dcm_DtcInfo.Dtc)
#endif

#if(DCM_UDS_22_ENABLED == STD_ON)
#define DCM_DID_COUNTER               (Dcm_DidContext.DidCounter)
#define DCM_DID_POS                   (Dcm_DidContext.DidPos)
#define DCM_DID_INDEX_LIST            (Dcm_DidIndexList)
#endif
#if((DCM_UDS_22_ENABLED == STD_ON) || (DCM_UDS_2F_ENABLED == STD_ON))
#define DCM_DID_DATA_LEN              (Dcm_DidContext.DidDataLength)
#define DCM_DID_RESP_DATA             (Dcm_DidContext.DidRespDataPtr)
#define DCM_DID_RESP_LEN              (Dcm_DidContext.DidRespDataLen)
#endif
#if((DCM_UDS_22_ENABLED == STD_ON) || (DCM_UDS_2E_ENABLED == STD_ON) || (DCM_UDS_2F_ENABLED == STD_ON))
#define DCM_DID_SIG_IDX               (Dcm_DidContext.DidSignalIndex)
#define DCM_DID_OPSTATUS              (Dcm_DidContext.DidOpStatus)
#endif
#if(DCM_UDS_2A_ENABLED == STD_ON)
#define DCM_CURRENT_DID_SERVICE       (Dcm_DidContext.CurrentDidService)
#define DCM_PERIODIC_SCHEDULE_INDEX   (Dcm_DidContext.PeriodicSchedulerIndex)
#define DCM_PERIODIC_SCHEDULE_USEDNUM (Dcm_DidContext.PeriodicSchedulerUsedNum)
#define DCM_PERIODIC_SCHEDULE         (Dcm_PeriodicSchedule)
#define DCM_PERIODIC_DID(Idx)         (DCM_PERIODIC_SCHEDULE[Idx].PeriodicDid)
#define DCM_PERIODIC_DID_INDEX(Idx)   (DCM_PERIODIC_SCHEDULE[Idx].PeriodicDidIndex)
#define DCM_PERIODIC_TIMER(Idx)       (DCM_PERIODIC_SCHEDULE[Idx].PeriodicTimer)
#define DCM_PERIODIC_RATE(Idx)        (DCM_PERIODIC_SCHEDULE[Idx].PeriodicRate)
#define DCM_PERIODIC_BUFFER(Idx)      (DCM_PERIODIC_SCHEDULE[Idx].PeriodicDidDataBuffer)
#endif

#if(DCM_UDS_2C_ENABLED == STD_ON)
#define DCM_DDDID_INDEX(Idx)                  (Dcm_DidContext.DcmDspDDDID[Idx].DcmDspDDDIDIndex)
#define DCM_DDDID_DEFINED(Idx)                (Dcm_DidContext.DcmDspDDDID[Idx].DcmDspDDDIDDefined)
#define DCM_DDDID_ELE_USED_NUM(Idx)           (Dcm_DidContext.DcmDspDDDID[Idx].DcmDspDDDIDElementUsedNum)
#define DCM_DDDID_ELE_PTR(Idx)                (Dcm_DidContext.DcmDspDDDID[Idx].DcmDspDDDIDElementPtr)
#define DCM_DDDID_ELE_SDID_IDX(Idx, EleIdx)   (DCM_DDDID_ELE_PTR(Idx)[EleIdx].DcmDspDDDIDSourceDidIndex)
#define DCM_DDDID_ELE_SDID_POS(Idx, EleIdx)   (DCM_DDDID_ELE_PTR(Idx)[EleIdx].DcmDspDDDIDDataPositionInSourceDid)
#define DCM_DDDID_ELE_DATA_IDX(Idx, EleIdx)   (DCM_DDDID_ELE_PTR(Idx)[EleIdx].DcmDspDataIndex)
#define DCM_DDDID_ELE_MEM_ID(Idx, EleIdx)     (DCM_DDDID_ELE_PTR(Idx)[EleIdx].DcmDspDDDIDMemoryId)
#define DCM_DDDID_ELE_MEM_ADDR(Idx, EleIdx)   (DCM_DDDID_ELE_PTR(Idx)[EleIdx].DcmDspDDDIDDataMemoryAddress)
#define DCM_DDDID_ELE_DATA_SIZE(Idx, EleIdx)  (DCM_DDDID_ELE_PTR(Idx)[EleIdx].DcmDspDDDIDDataSize)
#define DCM_DDDID_ELEMENT(Idx)                (Dcm_DidContext.DcmDspDDDIDElement[Idx])
#endif
#if((DCM_UDS_2E_ENABLED == STD_ON) || (DCM_UDS_2F_ENABLED == STD_ON))
#define DCM_DID_2E2F_IDX              (Dcm_DidContext.WriteControlDidIndex)
#endif
#if(DCM_UDS_2F_ENABLED == STD_ON)
#define DCM_REQ_IOCONTROL             (Dcm_DidContext.InputOutputControlParameter)
#endif

#if(DCM_UDS_27_ENABLED == STD_ON)
#define DCM_SEC_IDX                            (Dcm_SecurityContext.SecurityIndex)
#define DCM_SEC_ALL_INIT                       (Dcm_SecurityContext.SecurityInitialized)
#define DCM_SEC_READ_TIMER                     (Dcm_SecurityContext.ReadoutTimer)
#define DCM_SEC_LEV_INIT(StabIdx, SecIdx)      (Dcm_SecurityContext.SecLevelState[StabIdx][SecIdx].SecurityLevelInitialized)
#define DCM_SEC_ATT_NUM(StabIdx, SecIdx)       (Dcm_SecurityContext.SecLevelState[StabIdx][SecIdx].AcessAttempNum)
#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
#define DCM_SEC_KEY_ATT_NUM(StabIdx, SecIdx)   (Dcm_SecurityContext.SecLevelState[StabIdx][SecIdx].AcessKeyAttempNum)
#define DCM_SEC_SEED_ATT_NUM(StabIdx, SecIdx)  (Dcm_SecurityContext.SecLevelState[StabIdx][SecIdx].AcessSeedAttempNum)
#endif
#define DCM_SEC_DELAY_TIME(StabIdx, SecIdx)    (Dcm_SecurityContext.SecLevelState[StabIdx][SecIdx].AcessDelayTime)
#define DCM_SEC_SEQ(StabIdx, SecIdx)           (Dcm_SecurityContext.SecLevelState[StabIdx][SecIdx].AcessSequence)
#define DCM_SEC_DELAY_ON_BOOT(StabIdx, SecIdx) (Dcm_SecurityContext.SecLevelState[StabIdx][SecIdx].DelayTimeOnBoot)
#endif

#if(DCM_UDS_28_ENABLED == STD_ON)
#define DCM_COM_REQSUBSERVICE            (Dcm_ComCtrlContext.ComControlReqSubService)
#define DCM_COM_SERVICE_SESSION          (Dcm_ComCtrlContext.ComControlServiceSupportSession)
#define DCM_COM_REQMSGTYPE               (Dcm_ComCtrlContext.ComControlReqMsgType)
#define DCM_COM_REQSUBNET                (Dcm_ComCtrlContext.ComControlReqSubNet)
#define DCM_COM_REQSUBNODE               (Dcm_ComCtrlContext.ComControlReqSubNode)
#define DCM_COM_NM_MSG_STATE(Channel)    (Dcm_ComCtrlContext.ComControlNmMessageState[Channel])
#define DCM_COM_APP_MSG_STATE(Channel)   (Dcm_ComCtrlContext.ComControlAppMessageState[Channel])
#endif

#if(DCM_UDS_29_ENABLED == STD_ON)
#define DCM_AU_STATE                  (Dcm_AuthenticationContext.AuthenticationState)
#define DCM_AU_DEVELOP_ENABLED        (Dcm_AuthenticationContext.AuthenticationDevelopmentStateEnabled)
#define DCM_AU_RESULT_IND             (Dcm_AuthenticationContext.AuthenticationResultIndicated)
#define DCM_AU_CERT_ID                (Dcm_AuthenticationContext.AuthenticationCertID)
#define DCM_AU_CERT_RESULT            (Dcm_AuthenticationContext.AuthenticationCertResult)
#define DCM_AU_CSM_RESULT             (Dcm_AuthenticationContext.AuthenticationCsmResult)
#define DCM_AU_VERIFY_RESULT          (Dcm_AuthenticationContext.AuthenticationVerifyResult)
#define DCM_AU_DATA_LEN               (Dcm_AuthenticationContext.AuthenticationDataLength)
#define DCM_AU_CHALLENGE_PTR          (Dcm_AuthenticationContext.AuthenticationChallenge)
#define DCM_AU_PROOF_PTR              (Dcm_AuthenticationContext.AuthenticationProof)
#define DCM_AU_CUR_ROLE               (Dcm_AuthenticationContext.AuthenticationCurrentRole)
#define DCM_AU_TO_TIMER               (Dcm_AuthenticationContext.AuthenticationTimeoutTimer)
#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
#define DCM_AU_FAILED_CNT(ConnectionId)   (Dcm_AuthenticationContext.AuConsecutiveFailedCounter[ConnectionId])
#define DCM_AU_DELAY_TIMER(ConnectionId)  (Dcm_AuthenticationContext.AuDelayTimer[ConnectionId])
#define DCM_AU_CHAL_RESP_TIMER        (Dcm_AuthenticationContext.AuChallengeResponseTimeoutTimer)
#define DCM_AU_ABSOLUTE_TIMER         (Dcm_AuthenticationContext.AuAbsoluteTimeoutTimer)
#endif
#define DCM_AU_DE_ROLE(ConnectionId)  (Dcm_AuthenticationContext.AuthenticationDeauthenticatedRole[ConnectionId])
#if(DCM_DSP_AUTHENTICATION_SERVICE_MAX_SIZE > 0)
#define DCM_AU_SERVICE_PTR            (Dcm_AuthenticationContext.AuthenticationWhiteListService)
#endif
#if(DCM_DSP_AUTHENTICATION_DID_MAX_SIZE > 0)
#define DCM_AU_DID_PTR                (Dcm_AuthenticationContext.AuthenticationWhiteListDID)
#endif
#if(DCM_DSP_AUTHENTICATION_RID_MAX_SIZE > 0)
#define DCM_AU_RID_PTR                (Dcm_AuthenticationContext.AuthenticationWhiteListRID)
#endif
#if(DCM_DSP_AUTHENTICATION_MEM_MAX_SIZE > 0)
#define DCM_AU_MEM_PTR                (Dcm_AuthenticationContext.AuthenticationWhiteListMem)
#endif
#endif

#if((DCM_UDS_23_ENABLED == STD_ON) || (DCM_UDS_3D_ENABLED == STD_ON))
#define DCM_MEM_START_ADDR            (Dcm_MemoryContext.MemoryStartAddr)
#define DCM_MEM_SIZE                  (Dcm_MemoryContext.MemorySize)
#define DCM_MEM_ID                    (Dcm_MemoryContext.MemoryId)
#define DCM_MEM_DATA_PTR              (Dcm_MemoryContext.MemoryDataPtr)
#endif

#if((DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON))
#define DCM_DOWN_UP_LOAD_MA           (Dcm_DownUpLoadContext.DownUpLoadMemoryAddress)
#define DCM_DOWN_UP_LOAD_MS           (Dcm_DownUpLoadContext.DownUpLoadMemorySize)
#define DCM_DOWN_UP_LOAD_MI           (Dcm_DownUpLoadContext.DownUpLoadMemoryId)
#define DCM_DOWN_UP_LOAD_MNOBFWRM     (Dcm_DownUpLoadContext.MaxNumberOfBytesForWriteReadMemory)
#endif
#if(DCM_UDS_38_ENABLED == STD_ON)
#define DCM_FILE_TRANSFER_MOOP        (Dcm_DownUpLoadContext.ModeOfOperation)
#define DCM_FILE_TRANSFER_FPL         (Dcm_DownUpLoadContext.FilePathAndNameLength)
#define DCM_FILE_TRANSFER_FP          (Dcm_DownUpLoadContext.FilePathAndName)
#define DCM_FILE_TRANSFER_FSUC        (Dcm_DownUpLoadContext.FileSizeUncompressed)
#define DCM_FILE_TRANSFER_FSC         (Dcm_DownUpLoadContext.FileSizeCompressed)
#define DCM_FILE_TRANSFER_MNROB       (Dcm_DownUpLoadContext.MaxNumberOfBlockLength)
#endif
#if((DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON) || (DCM_UDS_38_ENABLED == STD_ON))
#define DCM_DOWN_UP_LOAD_NEXT_BSC     (Dcm_DownUpLoadContext.DownUpLoadNextBlockSequenceCounter)
#define DCM_DOWN_UP_LOAD_PRE_BSC      (Dcm_DownUpLoadContext.DownUpLoadPreviousBlockSequenceCounter)
#define DCM_DOWN_UP_LOAD_DFI          (Dcm_DownUpLoadContext.DataFormatIdentifier)
#define DCM_DOWN_UP_LOAD_STATUS       (Dcm_DownUpLoadContext.LoadStatus)
#endif

#if(DCM_UDS_31_ENABLED == STD_ON)
#define DCM_RID_IDX                   (Dcm_RoutineContext.RoutineIdIndex)
#define DCM_RID_CTRL_INFO             (Dcm_RoutineContext.RoutineControlInfo)
#define DCM_RID_STATUS(Idx)           (Dcm_RoutineContext.RoutineStatus[Idx])
#endif

#if(DCM_UDS_85_ENABLED == STD_ON)
#define DCM_85_SUB_SESREF             (Dcm_DtcSettingSubServiceSessionRef)
#endif

#if(DCM_UDS_87_ENABLED == STD_ON)
#define DCM_87_VERIFIED               (Dcm_LinkControlVerifiedService)
#endif

#define DCM_STATE                     (Dcm_Context.ModuleRunningState)
#define DCM_RX_IND_FLAG               (Dcm_Context.RxIndicationFlag)
#define DCM_RESP_PEND_COUNTER         (Dcm_Context.ResponsePendingCounter)
#define DCM_CURRENT_EXE_STEP          (Dcm_Context.CurrentExecutionStep)
#define DCM_P2_TIMER                  (Dcm_Context.P2Timer)
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
#define DCM_P4_TIMER                  (Dcm_Context.P4Timer)
#endif
#define DCM_S3_TIMER                  (Dcm_Context.S3Timer)
#if(DCM_COMM_SUPPORT == STD_ON)
#define DCM_ACTIVE_DIAGNOSTIC         (Dcm_Context.ActiveDiagnostic)
#define DCM_COMM_CHANNEL_MODE(i)      (Dcm_Context.ComMMode[i])
#endif

#define DCM_ACTIVE_RX_ID              (Dcm_Context.ProtocolRxId)
#define DCM_ACTIVE_FUN_ADDR_RX_ID     (Dcm_Context.ProtocolFunctionAddressRxId)

#define DCM_OP_STATUS                 (Dcm_Context.OpStatus)
#define DCM_MSGCONTEXT                (Dcm_Context.MsgContext)

#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
#define DCM_RXMSGCONTEXTLIST          (Dcm_Context.RxMsgContextList)
#endif

#define DCM_REQ_SERVICE               (Dcm_Context.ReqService)
#define DCM_REQ_SERVICEINFO           (Dcm_Context.ReqServiceInfo)
#define DCM_SERVICE_FNC               (Dcm_Context.ServiceFnc)

#define DCM_REQ_ROW_IDX               (Dcm_Context.RowIndex)
#define DCM_REQ_SUBSERVICE            (Dcm_Context.ReqSubService)
#define DCM_REQ_SUBSERVICEINFO        (Dcm_Context.ReqSubServiceInfo)
#define DCM_SUBSERVICE_FNC            (Dcm_Context.SubServiceFnc)

#define DCM_P_ERRORCODE               (Dcm_Context.pErrorCode)
#define DCM_ERRORCODE                 (*(Dcm_Context.pErrorCode))

/*Temporary information of the protocol*/
#define DCM_PCL_RX_PDU_ID(Idx)        (Dcm_Context.ProtocolInfo[Idx].RxPduId)
#define DCM_PCL_RX_DATA_LEN(Idx)      (Dcm_Context.ProtocolInfo[Idx].reqDataLen)
#define DCM_PCL_DATA_INDEX(Idx)       (Dcm_Context.ProtocolInfo[Idx].CopyDataIndex)
#define DCM_PCL_RX_CON_ID(Idx)        (Dcm_Context.ProtocolInfo[Idx].ConnectionId)
#define DCM_PCL_RX_ID(Idx)            (Dcm_Context.ProtocolInfo[Idx].RxId)
#define DCM_PCL_ERROR_CODE(Idx)       (Dcm_Context.ProtocolInfo[Idx].ErrorCode)
#define DCM_PCL_NEG_BUFFER(Idx)       (Dcm_Context.ProtocolInfo[Idx].NegativeRespBuffer)

#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
#define DCM_PCL_TXDATA_INDEX(Idx)     (Dcm_Context.ProtocolInfo[Idx].CopyTxDataIndex)
#define DCM_PCL_RX_BUFFER(Idx)        (Dcm_Context.ProtocolInfo[Idx].RxBufferPtr)
#define DCM_PCL_RX_BUFFERIDX(Idx)     (Dcm_Context.ProtocolInfo[Idx].RxBufferIndex)
#define DCM_RX_PDU_PROCESSING         (Dcm_RxPduProcessingStatus)
#endif

#define ClearSuppressPosRespBit()     (DCM_MSGCONTEXT.msgAddInfo.suppressPosResponse = FALSE)
#define SetSuppressPosRespBit()       (DCM_MSGCONTEXT.msgAddInfo.suppressPosResponse = TRUE)
#define CheckSuppressPosRespBit()     (DCM_MSGCONTEXT.msgAddInfo.suppressPosResponse == TRUE)

#define SetDcmState(State)            (DCM_STATE |= (State))
#define ClearDcmState(State)          (DCM_STATE &= (Dcm_RunningStateType)(~(State)))
#define ResetDcmState()               (DCM_STATE = DCM_IDLE)
#define CheckDcmState(State)          ((Dcm_RunningStateType)(DCM_STATE & (State)) != (Dcm_RunningStateType)0)

#define SetRespPendCounter(Counter)   (DCM_RESP_PEND_COUNTER = (uint8)(Counter))
#define RunRespPendCounter()          (DCM_RESP_PEND_COUNTER--)
#define ClearRespPendCounter()        (DCM_RESP_PEND_COUNTER = (uint8)0)
#define CheckRespPendCounter()        (DCM_RESP_PEND_COUNTER == (uint8)0)

/*SWS_Dcm_00024 Send a negative response with NRC 0x78 (Response pending) when reaching the response time
(DcmDspSessionP2ServerMax - DcmTimStrP2ServerAdjust respectively DcmDspSessionP2StarServerMax - DcmTimStrP2StarServerAdjust).*/
#define SetP2Timer(time)              (DCM_P2_TIMER = ((time - (uint32)DCM_CFG_P2_ADJUST(DCM_ACTIVE_PCL_ID)) / (uint32)DCM_TASK_TIME))
#define SetP2StarTimer(time)          (DCM_P2_TIMER = ((time - DCM_CFG_P2STAR_ADJUST(DCM_ACTIVE_PCL_ID)) / (uint32)DCM_TASK_TIME))
#define RunP2Timer()                  (DCM_P2_TIMER--)
#define ClearP2Timer()                (DCM_P2_TIMER = (uint32)0)
#define CheckP2Timer()                (DCM_P2_TIMER > (uint32)0)

#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
#define SetP4Timer(time)              (DCM_P4_TIMER = (time/DCM_TASK_TIME))
#define RunP4Timer()                  (DCM_P4_TIMER--)
#define ClearP4Timer()                (DCM_P4_TIMER = (uint32)0)
#define CheckP4Timer()                (DCM_P4_TIMER > (uint32)0)
#endif

#define SetS3Timer(time)              (DCM_S3_TIMER = (time/(uint32)DCM_TASK_TIME))
#define RunS3Timer()                  (DCM_S3_TIMER--)
#define ClearS3Timer()                (DCM_S3_TIMER = (uint32)0)
#define CheckS3Timer()                (DCM_S3_TIMER <= (uint32)0)

#if(STD_ON == DCM_UDS_29_ENABLED)
#define SetAuthenticationTimer()      (DCM_AU_TO_TIMER = (DCM_DSP_AUTHENTICATION_TIME_OUT/(uint32)DCM_TASK_TIME))
#define RunAuthenticationTimer()      (DCM_AU_TO_TIMER--)
#define ClearAuthenticationTimer()    (DCM_AU_TO_TIMER = (uint32)0)
#define CheckAuthenticationTimer()    (DCM_AU_TO_TIMER <= (uint32)0)
#endif
/*PRQA S 3412,3435,3456 ++*/
/*Set the definition of the negating response cache area.*/
#define ResetNegRespBuffer(Idx)         DCM_PCL_NEG_BUFFER(Idx)[DCM_INDEX_0] = DCM_DATA_CLEAR; \
                                        DCM_PCL_NEG_BUFFER(Idx)[DCM_INDEX_1] = DCM_DATA_CLEAR; \
                                        DCM_PCL_NEG_BUFFER(Idx)[DCM_INDEX_2] = DCM_POS_RESP
#define SetNegRespBuffer(Idx,Sid,Error) DCM_PCL_NEG_BUFFER(Idx)[DCM_INDEX_0] = DCM_RESPONSE_ID_7F; \
                                        DCM_PCL_NEG_BUFFER(Idx)[DCM_INDEX_1] = Sid;   \
                                        DCM_PCL_NEG_BUFFER(Idx)[DCM_INDEX_2] = Error
/*PRQA S 3412,3435,3456 --*/


#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
STATIC FUNC(void, DCM_CODE) DcmInternal_InitMsgContext
(
    void
);
STATIC FUNC(void, DCM_CODE) DcmInternal_InitDcmContext
(
    void
);

/*******************************************************************************
* DSL:Internal interfaces
*******************************************************************************/
#if(DCM_UDS_10_ENABLED == STD_ON)
STATIC FUNC(void, DCM_CODE) DslInternal_SetSesCtrlType
(
    uint8 SessionRowIndex
);
#endif

#if(DCM_UDS_27_ENABLED == STD_ON)
STATIC FUNC(void, DCM_CODE) DslInternal_RecoverAttemptCounter
(
    void
);
STATIC FUNC(void, DCM_CODE) DslInternal_Init_SecurityLevel
(
    void
);
STATIC FUNC(void, DCM_CODE) DslInternal_ManageDelayTimer
(
    void
);
STATIC FUNC(void, DCM_CODE) DslInternal_SetSecurityLevel
(
    uint8 SecurityRowIndex
);
STATIC FUNC(Dcm_SecurityMaskType, DCM_CODE) DslInternal_GetSecurityMask
(
    void
);
#endif

STATIC FUNC(void, DCM_CODE) DslInternal_MainFunction
(
    void
);

STATIC FUNC(void, DCM_CODE) DslInternal_CheckProtocolPermission
(
    uint8 ProtocolId
);
/*******************************************************************************
* DSD:Internal interfaces
*******************************************************************************/
STATIC FUNC(Std_ReturnType, DCM_CODE) DsdInternal_PreCheck
(
    void
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DsdInternal_ServiceCheck
(
    void
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DsdInternal_PostCheck
(
    void
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DsdInternal_CheckSubServiceId
(
    void
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DsdInternal_MatchServiceFnc
(
    void
);
STATIC FUNC(void, DCM_CODE) DsdInternal_DcmConfirmation
(
    Dcm_IdContextType idContext,
    uint16 SourceAddress,
    Dcm_ConfirmationStatusType status
);
STATIC FUNC(void, DCM_CODE) DsdInternal_CreatNegResponse
(
    void
);
STATIC FUNC(void, DCM_CODE) DsdInternal_RCRResponsePending
(
    boolean ForceRCRRP
);
STATIC FUNC(void, DCM_CODE) DsdInternal_ProcessingDone
(
    void
);

STATIC FUNC(void, DCM_CODE) DsdInternal_MainFunction
(
    void
);

STATIC FUNC(Std_ReturnType, DCM_CODE) DsdInternal_AddrSesSecCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
/*******************************************************************************
* DSP:Internal interfaces
*******************************************************************************/
STATIC FUNC(void, DCM_CODE) DspInternal_MainFunction
(
    void
);
STATIC FUNC(void, DCM_CODE) DspInternal_DcmConfirmation
(
    Dcm_IdContextType idContext,
    uint16 SourceAddress,
    Dcm_ConfirmationStatusType status
);
STATIC FUNC(void, DCM_CODE) DspInternal_PostProcessor
(
    void
);

#if(DCM_UDS_10_ENABLED == STD_ON)
/*10 Service*//*SWS_Dcm_00250*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_10_DiagnosticSessionControl
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_10_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(void, DCM_CODE) DspInternal_10_Sub_Post
(
    void
);
#endif

#if(DCM_UDS_11_ENABLED == STD_ON)
/*11 Service*//*SWS_Dcm_00260*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_11_ECUReset
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_11_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if((DCM_UDS_14_ENABLED == STD_ON) && (DCM_DEM_SUPPORT == STD_ON))
/*14 Service*//*SWS_Dcm_00247*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_14_ClearDiagnosticInformation
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_19_ENABLED == STD_ON)
/*19 Service*//*SWS_Dcm_00248*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_ReadDTCInformation
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#if(DCM_DEM_SUPPORT == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#if(DCM_UDS_19_01_07_12_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_01_07_12_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif
#if(DCM_UDS_19_02_0A_13_15_17_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_02_0A_13_15_17_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif
#if(DCM_UDS_19_06_19_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_06_19_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif
#if(DCM_UDS_19_08_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_08_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif
#if(DCM_UDS_19_09_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_09_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif
#if(DCM_UDS_19_03_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_03_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif
#if(DCM_UDS_19_04_18_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_04_18_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif
#if(DCM_UDS_19_05_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_05_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif
#if(DCM_UDS_19_0B_0C_0D_0E_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_0B_0C_0D_0E_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif
#if(DCM_UDS_19_14_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_14_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif
#if(DCM_UDS_19_1A_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_1A_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif
#if(DCM_UDS_19_42_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_42_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif
#if(DCM_UDS_19_55_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_55_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif
#if(DCM_UDS_19_56_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_56_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif
#endif/*#if(DCM_DEM_SUPPORT == STD_ON)*/
#endif/*#if(DCM_UDS_19_ENABLED == STD_ON)*/

#if(DCM_UDS_22_ENABLED == STD_ON)
/*22 Service*//*SWS_Dcm_00253*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_22_ReadDataByIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_22_CheckReadDid
(
    uint16 ReqDid,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) pDidIndex
);

#if(DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_Rnds_ReadSupportedIdentifier
(
    uint8 DidHighByte,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif/*#if(DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM)*/

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
STATIC FUNC(Std_ReturnType, RTE_CODE) DspInternal_22_ReadSupportedIdentifier
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif/*#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)*/

#endif/*#if(DCM_UDS_22_ENABLED == STD_ON)*/

#if((DCM_UDS_22_ENABLED == STD_ON) || (DCM_UDS_2F_ENABLED == STD_ON))
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_DidReadAllRefData
(
    uint16 DidIndex,
    uint32 MaxBufferSize,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_23_ENABLED == STD_ON)
/*23 Service*//*SWS_Dcm_00492*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_23_ReadMemoryByAddress
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_27_ENABLED == STD_ON)
/*27 Service*//*SWS_Dcm_00252*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_27_SecurityAccess
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);

STATIC FUNC(void, DCM_CODE) DspInternal_27_ResetSequence
(
    uint8 StabId
);
#endif

#if(DCM_UDS_28_ENABLED == STD_ON)
/*28 Service*//*SWS_Dcm_00511*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_28_CommunicationControl
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(void, DCM_CODE) DspInternal_Init_CommunicationState
(
    void
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_28_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_28_EnhancedSub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(void, DCM_CODE) DspInternal_28_Sub_Post
(
    void
);
STATIC FUNC(void, DCM_CODE) DspInternal_28_ResumeCommunication
(
    void
);
#endif

#if(DCM_UDS_29_ENABLED == STD_ON)
/*29 Service*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_Authentication
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(void, DCM_CODE) DspInternal_Init_Authentication
(
    void
);
STATIC FUNC(void, DCM_CODE) DspInternal_Reset_Authentication
(
    uint8 AuConId
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_CheckSubServiceLength
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_00_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_01_02_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_03_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_08_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_StartVerifyClientCertificate
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_WaitKeyMJobResult
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_CreateServerChallenge
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_WaitCsmJobResult
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_SignClientChallenge
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_StartVerifyProof
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_ReadRoleElement
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
FUNC(void, DCM_CODE) DspInternal_29_UpdateFailedCounterAndStartDelay
(
    uint16 ConId,
    boolean UpdateFailedCounter
);
#endif
#endif/*#if(DCM_UDS_29_ENABLED == STD_ON)*/

#if(DCM_UDS_2A_ENABLED == STD_ON)
/*2A Service*//*SWS_Dcm_01613*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2A_ReadDataByPeriodicIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(void, DCM_CODE) DspInternal_Reset_PeriodicDid
(
    void
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2A_StopSending
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(void, DCM_CODE) DspInternal_2A_StopOneScheduler
(
    uint8 SchIdx
);
STATIC FUNC(void, DCM_CODE) DspInternal_2A_SetRateTimer
(
    uint8 SchIdx
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2A_RequestSending
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(void, DCM_CODE) DspInternal_2A_PeriodicTransmission
(
    void
);
#endif

#if(DCM_UDS_2C_ENABLED == STD_ON)
/*2C Service*//*SWS_Dcm_00259*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_DynamicallyDefineDataIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(void, DCM_CODE) DspInternal_Reset_DynamicDid
(
    void
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_CheckDDDID
(
    P2VAR(uint16, AUTOMATIC, DCM_VAR) DDDidPos,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_01_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_SearchSourceDid
(
    uint16 SourceDid,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) DidIndex
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_02_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_03_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(void, DCM_CODE) DspInternal_2C_ClearOneDDDID
(
    uint16 BufIdx
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_DDDidReadAllRefData
(
    uint16 DidIndex,
    uint32 MaxBufferSize,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_2E_ENABLED == STD_ON)
/*2E Service*//*SWS_Dcm_00255*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2E_WriteDataByIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
STATIC FUNC(Std_ReturnType, RTE_CODE) DspInternal_2E_ReadSupportedIdentifier
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif/*#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)*/

#endif

#if(DCM_UDS_2F_ENABLED == STD_ON)
/*2F Service*//*SWS_Dcm_00256*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2F_InputOutputControlByIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2F_IOControlProcess
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
STATIC FUNC(Std_ReturnType, RTE_CODE) DspInternal_2F_ReadSupportedIdentifier
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif/*#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)*/

#endif

#if(DCM_UDS_31_ENABLED == STD_ON)
/*31 Service*//*SWS_Dcm_00257*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_31_RoutineControl
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
STATIC FUNC(void, DCM_CODE) DspInternal_Reset_RoutineStatus
(
    void
);
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_31_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
STATIC FUNC(Std_ReturnType, RTE_CODE) DspInternal_31_ReadSupportedIdentifier
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif/*#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)*/

#endif

#if(DCM_UDS_34_ENABLED == STD_ON)
/*34 Service*//*SWS_Dcm_00496*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_34_RequestDownload
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if((DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_3D_ENABLED == STD_ON))
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_WriteMemory
(
    uint8 ServiceId,
    Dcm_OpStatusType OpStatus,
    uint8 MemoryIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    uint8* MemoryData,
    Dcm_NegativeResponseCodeType* ErrorCode
);
#endif

#if((DCM_UDS_23_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON))
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_ReadMemory
(
    uint8 ServiceId,
    Dcm_OpStatusType OpStatus,
    uint8 MemoryIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    uint8* MemoryData,
    Dcm_NegativeResponseCodeType* ErrorCode
);
#endif

#if(DCM_UDS_35_ENABLED == STD_ON)
/*35 Service*//*SWS_Dcm_00499*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_35_RequestUpload
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_36_ENABLED == STD_ON)
/*36 Service*//*SWS_Dcm_00502*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_36_TransferData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#if((DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON))
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_36_UpDownData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif
#if(DCM_UDS_38_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_36_FileData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif
#endif

#if(DCM_UDS_37_ENABLED == STD_ON)
/*37 Service*//*SWS_Dcm_00505*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_37_RequestTransferExit
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_38_ENABLED == STD_ON)
/*38 Service*//*SWS_Dcm_01083*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_38_RequestFileTransfer
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);

STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_38_FullLengthCheck
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);

STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_38_ProcessFileTransfer
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_3D_ENABLED == STD_ON)
/*3D Service*//*SWS_Dcm_00488*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_3D_WriteMemoryByAddress
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_3E_ENABLED == STD_ON)
/*3E Service*//*SWS_Dcm_00251*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_3E_TesterPresent
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_85_ENABLED == STD_ON)
/*85 Service*//*SWS_Dcm_00249*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_85_ControlDTCSetting
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_UDS_87_ENABLED == STD_ON)
/*87 Service*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_87_LinkControl
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) Dcm_GetBufferIndex
(
    uint8 *bufferIndex,
    uint8 ProtocolId
);

STATIC FUNC(void, TCPIP_CODE) Dcm_InsertFifoBuffer
(
    P2P2VAR(Dcm_BufferListType, AUTOMATIC, AUTOMATIC) ListPtr,
    P2VAR(Dcm_BufferListType, AUTOMATIC, AUTOMATIC) msgContextPtr
);

STATIC FUNC(Dcm_BufferListType*, TCPIP_CODE) Dcm_GetNextFifoBuffer
(
    P2P2VAR(Dcm_BufferListType, AUTOMATIC, AUTOMATIC) ListPtr
);

STATIC FUNC(void, DCM_CODE) Dcm_UpdateMsgContext
(
    P2VAR(Dcm_BufferListType, AUTOMATIC, AUTOMATIC) bufferPtr
);
STATIC FUNC(void, DCM_CODE) Dcm_ResetRxFifoBufferStatus
(
    void
);
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DcmInternal_InitMsgContext
*
* Description: Init message context
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DcmInternal_InitMsgContext
(
    void
)
{
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
    Dcm_BufferListType *buffer = NULL_PTR;
#endif
    DCM_MSGCONTEXT.reqData = NULL_PTR;
    DCM_MSGCONTEXT.reqDataLen = (Dcm_MsgLenType)0;
    DCM_MSGCONTEXT.resData = NULL_PTR;
    DCM_MSGCONTEXT.resDataLen = (Dcm_MsgLenType)0;
    DCM_MSGCONTEXT.msgAddInfo.reqType = DCM_PHYSICAL_TYPE;
    ClearSuppressPosRespBit();
    DCM_MSGCONTEXT.resMaxDataLen = (Dcm_MsgLenType)0;
    DCM_MSGCONTEXT.idContext = DCM_DATA_CLEAR;
    DCM_MSGCONTEXT.dcmRxPduId = DCM_DATA_CLEAR;
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
    /* find next buffer */
    buffer = Dcm_GetNextFifoBuffer(&DCM_RXMSGCONTEXTLIST);
    if(buffer != NULL_PTR)
    {
        /* update DCM_MSGCONTEXT */
        Dcm_UpdateMsgContext(buffer);
        /* clear s3 and 29 timer */
        /*SWS_Dcm_00141*/
        ClearS3Timer();
#if(STD_ON == DCM_UDS_29_ENABLED)
        ClearAuthenticationTimer();
#endif
    }
    else
#endif
    {
        /*Since this function is called at various points in the code that do not require
        a response, the following statement is most appropriate here.*/
        /*Clear the received PDUs of the protocol means the protocol is idle.*/
        if(DCM_ACTIVE_PCL_ID < DCM_CFG_NUM_OF_PROTOCOL)
        {
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
            if((DCM_PCL_RX_PDU_ID(DCM_ACTIVE_PCL_ID) != COMSTACK_INVALID_PDUID) \
            && (DCM_RX_PDU_PROCESSING[DCM_PCL_RX_PDU_ID(DCM_ACTIVE_PCL_ID)] == FALSE))
#endif
            {
                DCM_PCL_RX_PDU_ID(DCM_ACTIVE_PCL_ID) = COMSTACK_INVALID_PDUID;
            }
        }
    }

#if(DCM_UDS_2A_ENABLED == STD_ON)
    DCM_CURRENT_DID_SERVICE = DCM_DATA_CLEAR;
#endif
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DcmInternal_InitDcmContext
*
* Description: Init context of Dcm module
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DcmInternal_InitDcmContext
(
    void
)
{
#if(DCM_COMM_SUPPORT == STD_ON)
    uint8 channel;
#endif
    uint8 ProtocolId;
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
    PduIdType RxPduIdx;
#endif
    /*Reset running state of Dcm module.*/
    ResetDcmState();
    /*Init the rx indication flag*/
    DCM_RX_IND_FLAG = FALSE;
    /*Clear the response pending counter*/
    ClearRespPendCounter();
    /*Clear P2 timer*/
    ClearP2Timer();
    /*Clear S3 timer*/
    ClearS3Timer();

#if(DCM_COMM_SUPPORT == STD_ON)
    /*SWS_Dcm_01069*//*Init the active diagnostic flag and all channels' state*/
    DCM_ACTIVE_DIAGNOSTIC = TRUE;

    for(channel = (uint8)0; channel < DCM_NUM_COMM_CHANNEL; channel++)
    {
        DCM_COMM_CHANNEL_MODE(channel) = DCM_COMM_NOCOM;
    }
#endif

    for(ProtocolId = (uint8)0; ProtocolId < DCM_CFG_NUM_OF_PROTOCOL; ProtocolId++)
    {
        DCM_PCL_RX_PDU_ID(ProtocolId) = COMSTACK_INVALID_PDUID;
        DCM_PCL_ERROR_CODE(ProtocolId) = DCM_POS_RESP;
        ResetNegRespBuffer(ProtocolId);
    }

    DCM_ACTIVE_PCL_ID = DCM_CFG_NUM_OF_PROTOCOL;  /*ProtocolId*/
    DCM_ACTIVE_CON_ID = DCM_DATA_CLEAR;           /*ProtocolConnectionId*/
    DCM_ACTIVE_RX_ID = DCM_DATA_CLEAR;            /*ProtocolRxId*/
    DCM_OP_STATUS = DCM_INITIAL;                  /*OpStatus*/

    DCM_REQ_SERVICE = DCM_DATA_CLEAR;             /*ReqService*/
    DCM_REQ_SERVICEINFO = NULL_PTR;               /*ReqServiceInfo*/
    DCM_SERVICE_FNC = NULL_PTR;                   /*ServiceFnc*/
    DCM_REQ_SUBSERVICE = DCM_DATA_CLEAR;          /*ReqSubService*/
    DCM_REQ_SUBSERVICEINFO = NULL_PTR;            /*ReqSubServiceInfo*/
    DCM_SUBSERVICE_FNC = NULL_PTR;                /*SubServiceFnc*/
    DCM_P_ERRORCODE = NULL_PTR;                   /*pErrorCode*/
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
    for(RxPduIdx = 0; RxPduIdx < DCM_CFG_RXPDU_NUM; RxPduIdx++)
    {
        DCM_RX_PDU_PROCESSING[RxPduIdx] = FALSE;
    }
    Dcm_ResetRxFifoBufferStatus();
    DCM_RXMSGCONTEXTLIST = NULL_PTR;
#endif
    DcmInternal_InitMsgContext();                 /*MsgContext*/
}

#if(DCM_UDS_10_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DslInternal_SetSesCtrlType
*
* Description: Record the index value of current session and reset some operations
*              that are affected by session switching
*
* Inputs: SessionRowIndex
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DslInternal_SetSesCtrlType
(
    uint8 SessionRowIndex
)
{
    uint8 StabId = DCM_CURRENT_STAB;
    Rte_ModeType_DcmDiagnosticSessionControl SchMMode;
#if(DCM_UDS_31_ENABLED == STD_ON)
    uint16 Idx;
#endif
#if((DCM_UDS_85_ENABLED == STD_ON) && (DCM_DEM_SUPPORT == STD_ON))
    uint8 DemClient = DCM_CFG_PCL_DEM_CLIENT(DCM_ACTIVE_PCL_ID);
#endif

    /*SWS_Dcm_00022*/
    DCM_SES_IDX = SessionRowIndex;
    SchMMode = DCM_CFG_SESSION_MODE(DCM_SES_IDX);
    (void)SchM_Switch_DcmDiagnosticSessionControl(SchMMode);

#if(DCM_UDS_27_ENABLED == STD_ON)
#if(DCM_CFG_MANUFACTORY_MODE_SUPPORT == STD_ON)
    if(FALSE == Dcm_CheckManufactoryMode())
#endif
    {
        DspInternal_27_ResetSequence(StabId);
        /*SWS_Dcm_00139*/
        DslInternal_SetSecurityLevel(DCM_SECURITY_LOCKED_IDX);
    }
#endif/*#if(DCM_UDS_27_ENABLED == STD_ON)*/

#if(DCM_UDS_28_ENABLED == STD_ON)
    DspInternal_28_ResumeCommunication();
#endif

#if(DCM_UDS_2A_ENABLED == STD_ON)
    /*SWS_Dcm_01111*/
    /*PRQA S 2742,2880 ++*/
    /*The parameter can be of type Link-Time, then this 'if' controlling expression will not be a constant expression.*/
    if(TRUE == DCM_CFG_DSP_DDDID_CHECK_SRC_DID)
    {
        DspInternal_Reset_PeriodicDid();
    }
    /*PRQA S 2742,2880 --*/
#endif

#if(DCM_UDS_2F_ENABLED == STD_ON)
    /*SWS_Dcm_00858*/
#endif

#if(DCM_UDS_31_ENABLED == STD_ON)
    for(Idx = (uint16)0; Idx < DCM_CFG_ROUTINE_NUM; Idx++)
    {
#if(DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM)
        if((DCM_RID_STATUS(Idx) == DCM_ROUTINE_STARTED) && (DCM_CFG_ROUTINE_STOP(Idx) != NULL_PTR))
        {
            Dcm_StopRoutine_Callout(DCM_CFG_ROUTINE_ID(Idx));
        }
        DCM_RID_STATUS(Idx) = DCM_ROUTINE_NONE;
#else
        if(DCM_RID_STATUS(Idx) != DCM_ROUTINE_NONE)
        {
            DCM_RID_STATUS(Idx) = DCM_ROUTINE_STOPPED;
        }
#endif
    }
#endif
#if((DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON))
    DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_NONE;
#endif

#if(DCM_UDS_85_ENABLED == STD_ON)
    if(!(DCM_CFG_SESSION_MASK(DCM_SES_IDX) & DCM_85_SUB_SESREF))
    {
#if(DCM_DEM_SUPPORT == STD_ON)
        /*SWS_Dcm_00751*/
        (void)Dem_EnableDTCSetting(DemClient);
#else
        Dcm_Rte_ControlDTCSetting_EnableDtcSetting();
#endif
        (void)SchM_Switch_DcmControlDtcSetting(RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING);
    }
#endif
}
#endif

#if(DCM_UDS_27_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DslInternal_RecoverAttemptCounter
*
* Description: This function is used to restore AttemptCounter from non-volatile
*              memory during Dcm initialization, or to restore AttemptCounter
*              directly from configuration data
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DslInternal_RecoverAttemptCounter
(
    void
)
{
    uint8 StabIdx;/*Service table index*/
    uint8 SecIdx;/*Security row index*/
#if(STD_ON == DCM_CFG_ACCESS_ATTEMPT_COUNTER_SUPPORT)
    Std_ReturnType ret = E_OK;
#endif

    if(DCM_SEC_ALL_INIT == FALSE)
    {
        DCM_SEC_ALL_INIT = TRUE;

        for(StabIdx = (uint8)0; StabIdx < DCM_CFG_NUM_OF_STAB; StabIdx++)
        {
            for(SecIdx = (uint8)0; SecIdx < DCM_CFG_SEC_NUM(StabIdx); SecIdx++)
            {
                if(DCM_SEC_LEV_INIT(StabIdx, SecIdx) == FALSE)
                {
#if(STD_ON == DCM_CFG_ACCESS_ATTEMPT_COUNTER_SUPPORT)
                    /*SWS_Dcm_01157*/
                    if(DCM_CFG_SEC_ATT_EN(StabIdx, SecIdx) == TRUE)
                    {
                        if(DCM_SEC_READ_TIMER == (uint32)0)
                        {
                            /*SWS_Dcm_01352*/
#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
                            (void)DCM_CFG_SEC_GET_ATT_FNC(StabIdx, SecIdx)(DCM_CANCEL,&(DCM_SEC_ATT_NUM(StabIdx, SecIdx)),&(DCM_SEC_KEY_ATT_NUM(StabIdx, SecIdx)),&(DCM_SEC_SEED_ATT_NUM(StabIdx, SecIdx)));
#else
                            (void)DCM_CFG_SEC_GET_ATT_FNC(StabIdx, SecIdx)(DCM_CANCEL, &(DCM_SEC_ATT_NUM(StabIdx, SecIdx)));
#endif
                            /*SWS_Dcm_01353*/
                            ret = E_NOT_OK;
                        }
                        else
                        {
                            /*SWS_Dcm_01154*/
#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
                            ret = DCM_CFG_SEC_GET_ATT_FNC(StabIdx, SecIdx)(DCM_INITIAL, &(DCM_SEC_ATT_NUM(StabIdx, SecIdx)),&(DCM_SEC_KEY_ATT_NUM(StabIdx, SecIdx)),&(DCM_SEC_SEED_ATT_NUM(StabIdx, SecIdx)));
#else
                            ret = DCM_CFG_SEC_GET_ATT_FNC(StabIdx, SecIdx)(DCM_INITIAL, &(DCM_SEC_ATT_NUM(StabIdx, SecIdx)));
#endif   
                        }

                        if(ret == E_NOT_OK)
                        {
                            /*SWS_Dcm_01156*//*SWS_Dcm_01353*/
                            /*The implementation logic of this parameter is: each time an unlock attempt occurs, the parameter is
                            subtracted by one. So here it should be initialized to 0.*/
                            DCM_SEC_ATT_NUM(StabIdx, SecIdx) = (uint8)0;

#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
                            DCM_SEC_KEY_ATT_NUM(StabIdx, SecIdx) = (uint8)0;
                            DCM_SEC_SEED_ATT_NUM(StabIdx, SecIdx) = (uint8)0;
#endif
                            DCM_SEC_DELAY_TIME(StabIdx, SecIdx) = DCM_CFG_SEC_DELAYTIME(StabIdx, SecIdx);
                            DCM_SEC_DELAY_ON_BOOT(StabIdx, SecIdx) = FALSE;
                            /*A security level has been initialized*/
                            DCM_SEC_LEV_INIT(StabIdx, SecIdx) = TRUE;
                        }
                        else if(ret == E_OK)
                        {
                            DCM_SEC_DELAY_TIME(StabIdx, SecIdx) = DCM_CFG_SEC_DELAYTIME(StabIdx, SecIdx);
                            DCM_SEC_DELAY_ON_BOOT(StabIdx, SecIdx) = FALSE;
                            /*A security level has been initialized*/
                            DCM_SEC_LEV_INIT(StabIdx, SecIdx) = TRUE;
                        }
                        else/*ret == DCM_E_PENDING*/
                        {
                            /*SWS_Dcm_01351 Dcm shall interrupt calling the Xxx_GetSecurityAttemptCounter() in order to
                            resume this chain of calls within the next Dcm_MainFunction() cycle.*/
                            DCM_SEC_ALL_INIT = FALSE;
                        }
                    }
                    else
#endif
                    {
                        DCM_SEC_ATT_NUM(StabIdx, SecIdx) = DCM_CFG_SEC_ATT_NUM(StabIdx, SecIdx);

#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
                        DCM_SEC_KEY_ATT_NUM(StabIdx, SecIdx) = DCM_CFG_SEC_KEY_ATT_NUM(StabIdx, SecIdx);
                        DCM_SEC_SEED_ATT_NUM(StabIdx, SecIdx) = DCM_CFG_SEC_SEED_ATT_NUM(StabIdx, SecIdx);
#endif
                        DCM_SEC_DELAY_TIME(StabIdx, SecIdx) = DCM_CFG_SEC_DELAYTIMEONBOOT(StabIdx, SecIdx);
                        DCM_SEC_DELAY_ON_BOOT(StabIdx, SecIdx) = TRUE;
                        /*A security level has been initialized*/
                        DCM_SEC_LEV_INIT(StabIdx, SecIdx) = TRUE;
                    }
                    /*Resets the order flag for security access.*/
                    DCM_SEC_SEQ(StabIdx, SecIdx) = FALSE;

                    /*SWS_Dcm_01355*/
                    if((DCM_SEC_LEV_INIT(StabIdx, SecIdx) == TRUE) && (DCM_SEC_ATT_NUM(StabIdx, SecIdx) == (uint8)0))
                    {
                        if(DCM_CFG_SEC_DELAYTIME(StabIdx, SecIdx) >= DCM_CFG_SEC_DELAYTIMEONBOOT(StabIdx, SecIdx))
                        {
                            DCM_SEC_DELAY_TIME(StabIdx, SecIdx) = DCM_CFG_SEC_DELAYTIME(StabIdx, SecIdx);
                        }
                        else
                        {
                            DCM_SEC_DELAY_TIME(StabIdx, SecIdx) = DCM_CFG_SEC_DELAYTIMEONBOOT(StabIdx, SecIdx);
                        }
                    }
                }
            }
        }

        if(DCM_SEC_READ_TIMER > (uint32)0)
        {
            DCM_SEC_READ_TIMER--;
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DslInternal_Init_SecurityLevel
*
* Description: This function is called during Dcm initialization to initialize
*              parameters such as the attempt counter, the delay time, and so on
*              for each security level.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DslInternal_Init_SecurityLevel
(
    void
)
{
    /*Set 0x27 service to uninitialized state*/
    DCM_SEC_ALL_INIT = FALSE;
    /*SWS_Dcm_01356*//*Set the timeout period for restoring AttemptCounter*/
    DCM_SEC_READ_TIMER = (uint32)(DCM_DSP_SECURITY_COUNTER_READOUT_TIME / DCM_TASK_TIME);
    /*Restore the value of AttemptCounter for each security level*/
    DslInternal_RecoverAttemptCounter();
    /*Reset the timeout because subtraction was done in the previous function*/
    DCM_SEC_READ_TIMER = (uint32)(DCM_DSP_SECURITY_COUNTER_READOUT_TIME / DCM_TASK_TIME);

#if(DCM_CFG_MANUFACTORY_MODE_SUPPORT == STD_ON)
    if(TRUE == Dcm_CheckManufactoryMode())
    {
        DslInternal_SetSecurityLevel(DCM_SECURITY_ALL_IDX);
    }
    else
#endif
    {
        /*SWS_Dcm_00033*/
        DslInternal_SetSecurityLevel(DCM_SECURITY_LOCKED_IDX);
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DslInternal_ManageDelayTimer
*
* Description: This function is used to manage the delay time for each security
*              level of the 0x27 service, and to assign a value to AttemptCounter
*              after the delay time ends.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DslInternal_ManageDelayTimer
(
    void
)
{
    uint8 StabId;
    uint8 SecIdx;

    if(DCM_SEC_ALL_INIT == TRUE)
    {
        /*0x27, DelayTimeOnBoot, DelayTime*/
        for(StabId = (uint8)0; StabId < DCM_CFG_NUM_OF_STAB; StabId++)
        {
            for(SecIdx = (uint8)0; SecIdx < DCM_CFG_SEC_NUM(StabId); SecIdx++)
            {
                if((DCM_SEC_ATT_NUM(StabId, SecIdx) == (uint8)0) || (DCM_SEC_DELAY_ON_BOOT(StabId, SecIdx) == TRUE))
                {
                    if(DCM_SEC_DELAY_TIME(StabId, SecIdx) != (uint32)0)
                    {
                        DCM_SEC_DELAY_TIME(StabId, SecIdx)--;
                    }
                    else
                    {
                        /*SWS_Dcm_01356*/
                        if(DCM_SEC_DELAY_ON_BOOT(StabId, SecIdx) == TRUE)
                        {
                            DCM_SEC_DELAY_ON_BOOT(StabId, SecIdx) = FALSE;
                        }
                        else
                        {
                            /*SWS_Dcm_01599*/
                            /*PRQA S 2741,2880 ++*/
                            /*DCM_DSP_SECURITY_RST_CNT_ON_TIMEOUT can be a link-time parameter. The "else" code is reachable.*/
                            if(DCM_DSP_SECURITY_RST_CNT_ON_TIMEOUT == FALSE)
                            {
                                DCM_SEC_ATT_NUM(StabId, SecIdx) = (uint8)1;
#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
                                if(DCM_SEC_KEY_ATT_NUM(StabId, SecIdx) == (uint8)0)
                                {
                                    DCM_SEC_KEY_ATT_NUM(StabId, SecIdx) = (uint8)1;
                                }
                                if(DCM_SEC_SEED_ATT_NUM(StabId, SecIdx) == (uint8)0)
                                {
                                    DCM_SEC_SEED_ATT_NUM(StabId, SecIdx) = (uint8)1; 
                                }
#endif
                            }
                            else
                            {
                                DCM_SEC_ATT_NUM(StabId, SecIdx) = DCM_CFG_SEC_ATT_NUM(StabId, SecIdx);

#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
                                DCM_SEC_KEY_ATT_NUM(StabId, SecIdx) = DCM_CFG_SEC_KEY_ATT_NUM(StabId, SecIdx);
                                DCM_SEC_SEED_ATT_NUM(StabId, SecIdx) = DCM_CFG_SEC_SEED_ATT_NUM(StabId, SecIdx);
#endif
                            }
                            /*PRQA S 2741,2880 --*/
#if(STD_ON == DCM_CFG_ACCESS_ATTEMPT_COUNTER_SUPPORT)
                            /*SWS_Dcm_01155*/
                            if(DCM_CFG_SEC_ATT_EN(StabId, SecIdx) == TRUE)
                            {
#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
                                (void)DCM_CFG_SEC_SET_ATT_FNC(StabId, SecIdx)(DCM_INITIAL, DCM_SEC_ATT_NUM(StabId, SecIdx),DCM_SEC_KEY_ATT_NUM(StabId, SecIdx),DCM_SEC_SEED_ATT_NUM(StabId, SecIdx));
#else
                                (void)DCM_CFG_SEC_SET_ATT_FNC(StabId, SecIdx)(DCM_INITIAL, DCM_SEC_ATT_NUM(StabId, SecIdx));
#endif
                            }
#endif
                        }
                        DCM_SEC_DELAY_TIME(StabId, SecIdx) = DCM_CFG_SEC_DELAYTIME(StabId, SecIdx);
                        DCM_SEC_SEQ(StabId, SecIdx) = FALSE;
                    }
                }
            }
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DslInternal_SetSecurityLevel
*
* Description: This function records the index value of the currently unlocked
*              security level in the SecurityRow array
*
* Inputs: SecurityRowIndex
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DslInternal_SetSecurityLevel
(
    uint8 SecurityRowIndex
)
{
    Dcm_SecLevelType SecLevel;
    uint8 StabId;

    /*SWS_Dcm_00020*/
    DCM_SEC_IDX = SecurityRowIndex;

    /*SWS_Dcm_01329 Update the ModeDeclarationGroup DcmSecurityAccess with the new security level.*/
    if(DCM_SEC_IDX == DCM_SECURITY_LOCKED_IDX)
    {
        SecLevel = DCM_SEC_LEV_LOCKED;
    }
    else if(DCM_SEC_IDX == DCM_SECURITY_ALL_IDX)
    {
        SecLevel = DCM_SEC_LEV_ALL;
    }
    else
    {
        StabId = DCM_CURRENT_STAB;

        SecLevel = DCM_CFG_SEC_LEVEL(StabId, DCM_SEC_IDX);
    }

#if(DCM_UDS_2A_ENABLED == STD_ON)
    /*SWS_Dcm_01112*/
    /*PRQA S 2742,2880 ++*/
    /*The parameter can be of type Link-Time, then this 'if' controlling expression will not be a constant expression.*/
    if(TRUE == DCM_CFG_DSP_DDDID_CHECK_SRC_DID)
    {
        DspInternal_Reset_PeriodicDid();
    }
    /*PRQA S 2742,2880 --*/
#endif

    (void)SchM_Switch_DcmSecurityAccess(SecLevel);
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DslInternal_GetSecurityMask
*
* Description: Get the security mask of current security level
*
* Inputs: None
*
* Outputs: None
*
* Return: The mask value
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Dcm_SecurityMaskType, DCM_CODE) DslInternal_GetSecurityMask
(
    void
)
{
    Dcm_SecurityMaskType Mask;
    uint8 StabId;

    if(DCM_SEC_IDX == DCM_SECURITY_ALL_IDX)
    {
        Mask = DCM_ALL_MASK;
    }
    else if(DCM_SEC_IDX == DCM_SECURITY_LOCKED_IDX)
    {
        Mask = DCM_LOCKED_MASK;
    }
    else
    {
        StabId = DCM_CURRENT_STAB;

        Mask = DCM_CFG_SEC_MASK(StabId, DCM_SEC_IDX);
    }
    return Mask;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DslInternal_MainFunction
*
* Description: Munction to process timing parameters
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DslInternal_MainFunction
(
    void
)
{
#if(STD_ON == DCM_UDS_29_ENABLED)
    uint8 AuConId;
#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
    uint16 ConId;
#endif
#endif

#if(DCM_UDS_27_ENABLED == STD_ON)
    DslInternal_ManageDelayTimer();
#endif

    SchM_Enter_Dcm_DCM_EXCLUSIVE_AREA_1();
#if(DCM_UDS_10_ENABLED == STD_ON)
    /*S3 Server*/
    if(!CheckS3Timer())
    {
        RunS3Timer();
        if(CheckS3Timer())
        {
            /*SWS_Dcm_01374*//*SWS_Dcm_01375*/
            COMM_DCM_INACTIVEDIAGNOSTIC(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
            /*SWS_Dcm_00140*/
            DslInternal_SetSesCtrlType(DCM_DEFAULT_IDX);
#if(STD_ON == DCM_UDS_29_ENABLED)
            AuConId = DCM_CFG_PCL_CONNECTION_MAIN_AU_CONNECTION(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
            /*SWS_Dcm_01483*/
            DspInternal_Reset_Authentication(AuConId);
#endif
        }
    }
#endif

#if(STD_ON == DCM_UDS_29_ENABLED)
    /*AuthenticationDefaultSessionTimeOut*/
    if(!CheckAuthenticationTimer())
    {
        RunAuthenticationTimer();
        if(CheckAuthenticationTimer())
        {
            AuConId = DCM_CFG_PCL_CONNECTION_MAIN_AU_CONNECTION(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
            /*SWS_Dcm_01482*/
            DspInternal_Reset_Authentication(AuConId);
        }
    }
#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
    for(ConId = (uint16)0; ConId < DCM_CFG_NUM_OF_CONNECTION; ConId++)
    {
        if(DCM_AU_DELAY_TIMER(ConId) != (uint32)0)
        {
            DCM_AU_DELAY_TIMER(ConId)--;
        }
    }

    if(DCM_AU_CHAL_RESP_TIMER != (uint32)0)
    {
        DCM_AU_CHAL_RESP_TIMER--;
        if(DCM_AU_CHAL_RESP_TIMER == (uint32)0)
        {
            DCM_AU_STATE = DCM_AU_STATE_DEAUTHENTICATED;
        }
    }

    if(DCM_AU_ABSOLUTE_TIMER != (uint32)0)
    {
        DCM_AU_ABSOLUTE_TIMER--;
        if(DCM_AU_ABSOLUTE_TIMER == (uint32)0)
        {
            AuConId = DCM_CFG_PCL_CONNECTION_MAIN_AU_CONNECTION(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
            DspInternal_Reset_Authentication(AuConId);
        }
    }
#endif
#endif/*#if(STD_ON == DCM_UDS_29_ENABLED)*/
    SchM_Exit_Dcm_DCM_EXCLUSIVE_AREA_1();

#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
    /*P4Server*/
    if(CheckP4Timer())
    {
        RunP4Timer();
        if(!CheckP4Timer())
        {
            ClearP2Timer();
            ClearRespPendCounter();
            /*SWS_Dcm_01413 The return values shall be ignored*/
            (void)(*DCM_SERVICE_FNC)(DCM_CANCEL, &DCM_MSGCONTEXT, DCM_P_ERRORCODE);

#if(DCM_MULTI_CORE_SUPPORT == STD_ON)
            Dcm_MultiCore_CrossingInfoClear();
#endif
            ResetDcmState();
            SetDcmState(DCM_PROCESSING);
            DCM_ERRORCODE = DCM_E_CONDITIONSNOTCORRECT;
            DsdInternal_CreatNegResponse();
            DsdInternal_ProcessingDone();
        }
    }
#endif

#if(DCM_UDS_10_ENABLED == STD_ON)
    /*P2Server and P2StarServer*/
    if(CheckP2Timer())
    {
        RunP2Timer();
        if((!CheckP2Timer()) && (!CheckDcmState((DCM_RCRRP_FORCE))))
        {
            /*SWS_Dcm_00024*/
            DsdInternal_RCRResponsePending(FALSE);
        }
    }
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DslInternal_CheckProtocolPermission
*
* Description: Determines whether the newly received diagnostic request can be
*              processed.
*
* Inputs: ProtocolId: Protocol to which the newly received diagnostic request belongs
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(void, DCM_CODE) DslInternal_CheckProtocolPermission
(
    uint8 ProtocolId
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduIdType TxPduId;
    PduInfoType TransmitPdu;
    Dcm_ProtocolType ProtocolType;
    uint16 TesterSourceAddress;
    uint16 ConnectionId;
#if(DCM_UDS_10_ENABLED == STD_ON)
    uint8 Idx;
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
    uint8 PreviousProtocolId = DCM_ACTIVE_PCL_ID;
    uint16 PreviousConnectionId = DCM_ACTIVE_CON_ID;
    uint8 AuConId;
#endif
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
    uint8 TmpRxBufferIndex;
    Dcm_BufferListType *TmpRxBufferPtr;
#endif
#if(DCM_RXFIFOBUFFER_ENABLED == STD_OFF)
     /* fix for empty NegResp when enabled rx fifo buffer */
    ResetNegRespBuffer(ProtocolId);
#endif

    /*Step 1: Check whether any protocol is currently activated and compare its
    priority with the protocol for receiving new diagnostic request.*/
    if(DCM_ACTIVE_PCL_ID >= DCM_CFG_NUM_OF_PROTOCOL)
    {
        /*SWS_Dcm_00036*/
        /*No protocol is activated.*/
        ret = E_OK;
    }
    else if(DCM_ACTIVE_PCL_ID == ProtocolId)
    {
        /*New request belongs to the current active protocol.*/
        ret = E_OK;
    }
    else if((DCM_PCL_RX_PDU_ID(DCM_ACTIVE_PCL_ID) == COMSTACK_INVALID_PDUID) && (DCM_SES_IDX == DCM_DEFAULT_IDX))
    {
        ProtocolType = DCM_CFG_PCL_TYPE(DCM_ACTIVE_PCL_ID);
        ConnectionId = DCM_PCL_RX_CON_ID(DCM_ACTIVE_PCL_ID);
        TesterSourceAddress = DCM_CFG_PCL_CONNECTION_MAIN_TESTER_ADDR(DCM_ACTIVE_PCL_ID, ConnectionId);
        /*SWS_Dcm_00459*//*SWS_Dcm_00625*//*SWS_Dcm_00728*/
        /*The current active protocol is in default session and no active request is in execution phase.*/
        ret = Dcm_Rte_CallbackDCMRequestServices_User_StopProtocol(ProtocolType, TesterSourceAddress, ConnectionId);

        if(ret != E_OK)
        {
            /*SWS_Dcm_01190*//*Negative response with NRC 0x22 will be issued.*/
            SetNegRespBuffer(ProtocolId, (DCM_CFG_PCL_RXBUFFER(ProtocolId)[DCM_SID_INDEX]), DCM_E_CONDITIONSNOTCORRECT);
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
            Dcm_SetNRC22Reason(DCM_NRC22_REASON_0);
#endif
        }
    }
    else
    {
        /*SWS_Dcm_00015*/
        /*Lower numeric values represent higher protocol priority: 0-Highest protocol priority, 255-Lowest protocol priority.*/
        /*SWS_Dcm_01144*/
        /*Protocol preemption can't be activated with a concurrent TesterPresent of a higher priority protocol*/
        if((DCM_CFG_PCL_PRIORITY(DCM_ACTIVE_PCL_ID) > DCM_CFG_PCL_PRIORITY(ProtocolId)) \
            && (DCM_CFG_PCL_RXBUFFER(ProtocolId)[DCM_SID_INDEX] != DCM_3E_SERVICE))
        {
            ProtocolType = DCM_CFG_PCL_TYPE(DCM_ACTIVE_PCL_ID);
            ConnectionId = DCM_PCL_RX_CON_ID(DCM_ACTIVE_PCL_ID);
            TesterSourceAddress = DCM_CFG_PCL_CONNECTION_MAIN_TESTER_ADDR(DCM_ACTIVE_PCL_ID, ConnectionId);
            /*SWS_Dcm_00459*/
            ret = Dcm_Rte_CallbackDCMRequestServices_User_StopProtocol(ProtocolType, TesterSourceAddress, ConnectionId);

            if(ret != E_OK)
            {
                /*SWS_Dcm_01190*//*Negative response with NRC 0x22 will be issued.*/
                SetNegRespBuffer(ProtocolId, (DCM_CFG_PCL_RXBUFFER(ProtocolId)[DCM_SID_INDEX]), DCM_E_CONDITIONSNOTCORRECT);
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
                Dcm_SetNRC22Reason(DCM_NRC22_REASON_0);
#endif
            }
            else
            {
                if(CheckDcmState(DCM_PROCESSING_DONE | DCM_RCRRP | DCM_RCRRP_FORCE))
                {
                    /*SWS_Dcm_00079*/
                    TxPduId = DCM_CFG_PCL_CONNECTION_MAIN_TX_PDUID(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
                    /*SWS_Dcm_00460*//*Canceling the transmit will be always successful*/
                    DcmCancelTransmit(TxPduId);
                }

                if((CheckDcmState(DCM_PROCESSING)) && (DCM_SERVICE_FNC != NULL_PTR))
                {
                    /*SWS_Dcm_01046*//*SWS_Dcm_01413 The return values shall be ignored*/
                    (void)(*DCM_SERVICE_FNC)(DCM_CANCEL, &DCM_MSGCONTEXT, DCM_P_ERRORCODE);
                }

                if(DCM_PCL_RX_PDU_ID(DCM_ACTIVE_PCL_ID) != COMSTACK_INVALID_PDUID)
                {
                    /*SWS_Dcm_00575*//*SWS_Dcm_00576*/
                    /*Canceling the reception will be always successful*/
                    DcmCancelReceive(DCM_PCL_RX_PDU_ID(DCM_ACTIVE_PCL_ID));
                }

                if(DCM_SES_IDX != DCM_DEFAULT_IDX)
                {
                    (void)Dcm_ResetToDefaultSession();
                }
                /*Reset Dcm state*/
                ResetDcmState();
                /*Clear the received pdu info of current active protocol.*/
                DCM_PCL_RX_PDU_ID(DCM_ACTIVE_PCL_ID) = COMSTACK_INVALID_PDUID;
            }
        }
        else
        {
            /*Negative response with NRC 0x21 will be issued.*/
            SetNegRespBuffer(ProtocolId, (DCM_CFG_PCL_RXBUFFER(ProtocolId)[DCM_SID_INDEX]), DCM_E_BUSYREPEATREQUEST);
        }
    }

    /*Step2: Start the protocol to which the new receive diagnostic request belongs.*/
    if((ret == E_OK) && (DCM_ACTIVE_PCL_ID != ProtocolId))
    {
        /*Clear the current active protocol*/
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
        if(DCM_ACTIVE_PCL_ID < DCM_CFG_NUM_OF_PROTOCOL)
        {
            Dcm_ResetRxFifoBufferStatus();
            DCM_RXMSGCONTEXTLIST = NULL_PTR;
        }
#endif
        DCM_ACTIVE_PCL_ID = DCM_CFG_NUM_OF_PROTOCOL;
        /*SWS_Dcm_00036*/
        ProtocolType = DCM_CFG_PCL_TYPE(ProtocolId);
        ConnectionId = DCM_PCL_RX_CON_ID(ProtocolId);
        TesterSourceAddress = DCM_CFG_PCL_CONNECTION_MAIN_TESTER_ADDR(ProtocolId, ConnectionId);

        ret = Dcm_Rte_CallbackDCMRequestServices_User_StartProtocol(ProtocolType, TesterSourceAddress, ConnectionId);

        if(ret != E_OK)
        {
            /*SWS_Dcm_00674*//*Negative response with NRC 0x22 will be issued.*/
            SetNegRespBuffer(ProtocolId, (DCM_CFG_PCL_RXBUFFER(ProtocolId)[DCM_SID_INDEX]), DCM_E_CONDITIONSNOTCORRECT);
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
            Dcm_SetNRC22Reason(DCM_NRC22_REASON_0);
#endif
        }
        else
        {
            /*SWS_Dcm_00145*//*The service table can be accessed directly with the DCM_ACTIVE_PCL_ID parameter.*/
            DCM_ACTIVE_PCL_ID = ProtocolId;
            /*Setting current protocol should be in front of Resetting PeriodicDid and DynamicDid   */
#if(DCM_UDS_2A_ENABLED == STD_ON)
            DspInternal_Reset_PeriodicDid();
#endif
#if(DCM_UDS_2C_ENABLED == STD_ON)
            DspInternal_Reset_DynamicDid();
#endif
        }
    }

    /*Step3: Initializes the diagnostic request processing flow.*/
    if(ret == E_OK)
    {
        DCM_ACTIVE_CON_ID = DCM_PCL_RX_CON_ID(ProtocolId);
#if(DCM_UDS_29_ENABLED == STD_ON)
        if(((DCM_ACTIVE_PCL_ID != PreviousProtocolId) || (DCM_ACTIVE_CON_ID != PreviousConnectionId)) \
            && (PreviousProtocolId < DCM_CFG_NUM_OF_PROTOCOL))
        {
            AuConId = DCM_CFG_PCL_CONNECTION_MAIN_AU_CONNECTION(PreviousProtocolId, PreviousConnectionId);
            DspInternal_Reset_Authentication(AuConId);
        }
#endif

#if(DCM_UDS_3E_ENABLED == STD_ON)
        /*SWS_Dcm_00112*//*SWS_Dcm_00113*/
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
        if((DCM_PCL_RX_BUFFER(ProtocolId)[DCM_SID_INDEX] == DCM_3E_SERVICE) \
            && (DCM_PCL_RX_BUFFER(ProtocolId)[DCM_SUB_SID_INDEX] == DCM_SUPPRESS_POS_RSP_MASK) \
            && (DCM_PCL_RX_DATA_LEN(ProtocolId) == DCM_LENGTH_2_BYTE))
        {
            /* if rx buffer list is not empty should not process 0x3E80 */
            DCM_RX_PDU_PROCESSING[DCM_PCL_RX_ID(ProtocolId)] = FALSE;
            if(DCM_RXMSGCONTEXTLIST == NULL_PTR)
            {
                DsdInternal_ResetWithoutChangeSessionAndSendResponse();
            }
        }
#else
        if((DCM_CFG_PCL_RXBUFFER(ProtocolId)[DCM_SID_INDEX] == DCM_3E_SERVICE) \
            && (DCM_CFG_PCL_RXBUFFER(ProtocolId)[DCM_SUB_SID_INDEX] == DCM_SUPPRESS_POS_RSP_MASK) \
            && (DCM_PCL_RX_DATA_LEN(ProtocolId) == DCM_LENGTH_2_BYTE))
        {
            DsdInternal_ResetWithoutChangeSessionAndSendResponse();
        }
#endif
        else
#endif
        {
            DCM_P_ERRORCODE = &(DCM_PCL_ERROR_CODE(ProtocolId));
            DCM_ACTIVE_RX_ID = DCM_PCL_RX_ID(ProtocolId);

#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
            TmpRxBufferIndex = DCM_PCL_RX_BUFFERIDX(ProtocolId);
            DCM_CFG_PCL_RXBUFFERLISTPTR[TmpRxBufferIndex].bufferIsUesd = TRUE;
            TmpRxBufferPtr = &(DCM_CFG_PCL_RXBUFFERLISTPTR[TmpRxBufferIndex]);
            TmpRxBufferPtr->reqDataLen = DCM_PCL_RX_DATA_LEN(ProtocolId);
            TmpRxBufferPtr->reqData = DCM_PCL_RX_BUFFER(ProtocolId);
            /* if use rx buffer as tx buffer */
            if(DCM_CFG_PCL_TXRXBUFFERSAME(ProtocolId) == TRUE)
            {
                TmpRxBufferPtr->resData = DCM_PCL_RX_BUFFER(ProtocolId);
            }
            else
            {
                TmpRxBufferPtr->resData = DCM_CFG_PCL_TXBUFFER(ProtocolId);
            }
            TmpRxBufferPtr->msgAddInfo.reqType = DCM_CFG_PCL_CONNECTION_MAIN_RX_ADDR_TYPE(ProtocolId, DCM_ACTIVE_CON_ID, DCM_ACTIVE_RX_ID);
            TmpRxBufferPtr->rxBufferIndex = DCM_PCL_RX_BUFFERIDX(ProtocolId);
            Dcm_InsertFifoBuffer(&DCM_RXMSGCONTEXTLIST, TmpRxBufferPtr);
#else

            DCM_MSGCONTEXT.reqDataLen = DCM_PCL_RX_DATA_LEN(ProtocolId);
            DCM_MSGCONTEXT.dcmRxPduId = DCM_PCL_RX_PDU_ID(ProtocolId);
            DCM_MSGCONTEXT.reqData = DCM_CFG_PCL_RXBUFFER(ProtocolId);
            DCM_MSGCONTEXT.resData = DCM_CFG_PCL_TXBUFFER(ProtocolId);
            DCM_MSGCONTEXT.resDataLen = (Dcm_MsgLenType)0;
            DCM_MSGCONTEXT.msgAddInfo.reqType = DCM_CFG_PCL_CONNECTION_MAIN_RX_ADDR_TYPE(ProtocolId, DCM_ACTIVE_CON_ID, DCM_ACTIVE_RX_ID);
            DCM_MSGCONTEXT.resMaxDataLen = DCM_CFG_PCL_TXBUFFER_SIZE(ProtocolId);


            /*SWS_Dcm_00146*//*Generally, the security level is activated in a non-default session. Therefore, when priority
            preemption occurs, the session must be converted to the default session. Therefore, there is no need to reset the
            security level.*/
            /*SWS_Dcm_00147*//*When switching to the default session, the SchM_Switch function has already been called.*/

            DCM_RX_IND_FLAG = TRUE;
#if(DCM_UDS_10_ENABLED == STD_ON)
            for(Idx = (uint8)0; Idx < DCM_CFG_STAB_S_NUM; Idx++)
            {
                if(DCM_CFG_STAB_S_ID(Idx) == DCM_10_SERVICE)
                {
                    if(DCM_CFG_STAB_S_USED(Idx) == TRUE)
                    {
                        /*SWS_Dcm_00144*/
                        SetP2Timer(DCM_CFG_SESSION_P2(DCM_SES_IDX));
                    }
                    break;
                }
            }
#endif
            SetRespPendCounter(DCM_CFG_RESP_PEND_MAX_NUM);
#if(DCM_COMM_SUPPORT == STD_ON)
            /*SWS_Dcm_00169*//*SWS_Dcm_01373*//*SWS_Dcm_01376*/
            if((DCM_SES_IDX == DCM_DEFAULT_IDX) && (DCM_ACTIVE_DIAGNOSTIC == TRUE))
            {
                COMM_DCM_ACTIVEDIAGNOSTIC(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
            }
#endif /* DCM_COMM_SUPPORT == STD_ON */
#endif /* DCM_RXFIFOBUFFER_ENABLED == STD_ON */
        }
    }
    else
    {
        /*SWS_Dcm_00727*/
        if((TRUE == DCM_CFG_RESP_ON_SECOND_REQ) || (DCM_PCL_NEG_BUFFER(ProtocolId)[DCM_INDEX_2] != DCM_E_BUSYREPEATREQUEST))
        {
            TransmitPdu.SduDataPtr = DCM_PCL_NEG_BUFFER(ProtocolId);
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
            if(DCM_PCL_NEG_BUFFER(ProtocolId)[DCM_INDEX_2] == DCM_E_CONDITIONSNOTCORRECT)
            {
                TransmitPdu.SduLength = DCM_UDS_WITH_NRC22_RES_LEN;
            }
            else
#endif
            {
                TransmitPdu.SduLength  = DCM_UDS_NEG_RES_LEN;
            }
            TransmitPdu.MetaDataPtr = NULL_PTR;
            TxPduId = DCM_CFG_PCL_CONNECTION_MAIN_TX_PDUID(ProtocolId, DCM_PCL_RX_CON_ID(ProtocolId));
            (void)DcmTransmit(TxPduId, &TransmitPdu);
        }
        else
        {
            /*SWS_Dcm_01605*/
            /*Reset the state of the protocol.*/
            DCM_PCL_RX_PDU_ID(ProtocolId) = COMSTACK_INVALID_PDUID;
        }
    }
}
/*PRQA S 4700 --*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_PreCheck
*
* Description: Pre condition check: Manufacture condition, Range of service id
*
* Inputs: None
*
* Outputs: None
*
* Return: E_OK: Pre condition check passed
*         E_NOT_OK: Pre condition check failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DsdInternal_PreCheck
(
    void
)
{
    Std_ReturnType Result = E_OK;

    SetDcmState(DCM_PROCESSING);
    /*SWS_Dcm_00527*//*SWS_Dcm_00732*/
    DCM_OP_STATUS = DCM_INITIAL;
    DCM_ERRORCODE = DCM_POS_RESP;
    /*SWS_Dcm_00198*/
    DCM_REQ_SERVICE = DCM_MSGCONTEXT.reqData[DCM_SID_INDEX];

    /*SWS_Dcm_01535*/
#if(DCM_DSD_MANUFACTURER_NOTIFICATION_ENABLED == STD_ON)
    /*SWS_Dcm_00218*//*SWS_Dcm_01341*/
    /*Second parameter: RequestData: Complete request data, except the service ID*/
    /*Third parameter: DataSize: Number of valid bytes in the RequestData parameter*/
    Result = Dcm_Rte_ServiceRequestManufacturerNotification_Indication(DCM_REQ_SERVICE, &(DCM_MSGCONTEXT.reqData[DCM_INDEX_1]),
            ((uint16)DCM_MSGCONTEXT.reqDataLen - (uint16)DCM_LENGTH_1_BYTE), (DCM_MSGCONTEXT.msgAddInfo.reqType), (uint16)DCM_ACTIVE_CON_ID,
            DCM_P_ERRORCODE, DCM_CFG_PCL_TYPE(DCM_ACTIVE_PCL_ID), DCM_CFG_PCL_CONNECTION_MAIN_TESTER_ADDR(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID));

    if(Result == E_OK)
#endif
    {
        /*ECUC_Dcm_00600*//*SWS_Dcm_00084*/
#if(DCM_RESPOND_ALL_REQUEST == STD_OFF)
        if(((DCM_RESPONSE_ID_40 <= DCM_REQ_SERVICE) && (DCM_REQ_SERVICE <= DCM_RESPONSE_ID_7F)) || (DCM_RESPONSE_ID_C0 <= DCM_REQ_SERVICE))
        {
            Result = DCM_E_REQUEST_NOT_ACCEPTED;
        }
#endif
    }

#if((DCM_DSD_MANUFACTURER_NOTIFICATION_ENABLED == STD_ON) || (DCM_RESPOND_ALL_REQUEST == STD_OFF))
    /*SWS_Dcm_00462*//*SWS_Dcm_00677*/
    if(Result == DCM_E_REQUEST_NOT_ACCEPTED)
    {
        DsdInternal_ResetWithoutChangeSessionAndSendResponse();
    }
    /*SWS_Dcm_00463, SWS_Dcm_01321, SWS_Dcm_00678, Result = E_NOT_OK, Trigger a negative response*/
    /*Result = E_OK*/
#endif

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_ServiceCheck
*
* Description: Check the request service id and its address/session/security/role
*              are supported or not
*
* Inputs: None
*
* Outputs: None
*
* Return: E_OK: service check passed
*         E_NOT_OK: service check failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DsdInternal_ServiceCheck
(
    void
)
{
    uint8 Idx;
    uint8 SupportAddr;
#if(DCM_UDS_10_ENABLED == STD_ON)
    Dcm_SessionMaskType SesLevelRef;
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
    Dcm_SecurityMaskType SecLevelRef;
    Dcm_SecurityMaskType CurSecMask;
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
    Dcm_AuRoleMaskType AuRoleMask;
#endif
    Std_ReturnType Result = E_NOT_OK;

    for(Idx = (uint8)0; Idx < DCM_CFG_STAB_S_NUM; Idx++)
    {
        /*SWS_Dcm_00193*//*SWS_Dcm_00195*//*SWS_Dcm_00035*/
        if((DCM_REQ_SERVICE == DCM_CFG_STAB_S_ID(Idx)) && (TRUE == DCM_CFG_STAB_S_USED(Idx)))
        {
            DCM_REQ_SERVICEINFO = &DCM_CFG_STAB_S_INFO(Idx);
            /*SWS_Dcm_00221*/
            Result = DsdInternal_MatchServiceFnc();
            break;
        }
    }

    if(Result == E_NOT_OK)
    {
        /*SWS_Dcm_00197*/
        DCM_ERRORCODE = DCM_E_SERVICENOTSUPPORTED;
    }
    else
    {
        SupportAddr = (DCM_REQ_SERVICEINFO->DcmDsdServiceSupportAddress);
#if(DCM_UDS_10_ENABLED == STD_ON)
        SesLevelRef = (DCM_REQ_SERVICEINFO->DcmDsdSidTabSessionLevelRef);
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
        CurSecMask = DslInternal_GetSecurityMask();
        SecLevelRef = (DCM_REQ_SERVICEINFO->DcmDsdSidTabSecurityLevelRef);
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
        AuRoleMask = (DCM_REQ_SERVICEINFO->DcmDsdServiceRoleRef);
#endif
        if(!(SupportAddr & ((uint8)0x01 << DCM_MSGCONTEXT.msgAddInfo.reqType)))
        {
            /*check support addressing type*/
            DCM_ERRORCODE = DCM_E_SERVICENOTSUPPORTED;
            Result = E_NOT_OK;
        }
#if(STD_ON == DCM_UDS_29_ENABLED)
        else if(!(DCM_AU_CUR_ROLE & AuRoleMask))
        {
            /*SWS_Dcm_01544*//*SWS_Dcm_01522*//*SWS_Dcm_01523*/
            DCM_ERRORCODE = DCM_E_AUTHENTICATIONREQUIRED;
            Result = E_NOT_OK;
        }
#endif
#if(DCM_UDS_10_ENABLED == STD_ON)
        else if(!(DCM_CFG_SESSION_MASK(DCM_SES_IDX) & SesLevelRef))
        {
            /*SWS_Dcm_00211*/
            DCM_ERRORCODE = DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION;
            Result = E_NOT_OK;
        }
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
        else if(!(CurSecMask & SecLevelRef))
        {
            /*SWS_Dcm_00217*/
            DCM_ERRORCODE = DCM_E_SECURITYACCESSDENIED;
            Result = E_NOT_OK;
        }
#endif
        else
        {
            /*Result = E_OK;*/
        }
    }

    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_PostCheck
*
* Description: Post condition check: Suppier condition, minimum length of request message,
*
* Inputs: None
*
* Outputs: None
*
* Return: E_OK: Post condition check passed
*         E_NOT_OK: Post condition check failed
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DsdInternal_PostCheck
(
    void
)
{
    Std_ReturnType Result = E_OK;

#if(DCM_DSD_SUPPLIER_NOTIFICATION_ENABLED == STD_ON)
    Result = Dcm_Rte_ServiceRequestSupplierNotification_Indication(DCM_REQ_SERVICE, &(DCM_MSGCONTEXT.reqData[DCM_INDEX_1]),
           ((uint16)DCM_MSGCONTEXT.reqDataLen - (uint16)DCM_LENGTH_1_BYTE), (DCM_MSGCONTEXT.msgAddInfo.reqType), (uint16)DCM_ACTIVE_CON_ID,
            DCM_P_ERRORCODE, DCM_CFG_PCL_TYPE(DCM_ACTIVE_PCL_ID), DCM_CFG_PCL_CONNECTION_MAIN_TESTER_ADDR(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID));
    /*SWS_Dcm_00517*//*SWS_Dcm_00677*/
    if(Result == DCM_E_REQUEST_NOT_ACCEPTED)
    {
        DsdInternal_ResetWithoutChangeSessionAndSendResponse();
    }
    else if(Result == E_NOT_OK)
    {
        /*SWS_Dcm_00518, SWS_Dcm_01322, SWS_Dcm_00678, Result = E_NOT_OK, Trigger a negative response*/
    }
    else/*Result = E_OK*/
#endif
    {
        /*SWS_Dcm_00696*/
        if(DCM_MSGCONTEXT.reqDataLen < (DCM_REQ_SERVICEINFO->DcmDsdServiceMinLength))
        {
            DCM_ERRORCODE = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
    }

    /*SWS_Dcm_00204*/
    if((Result == E_OK) && ((DCM_REQ_SERVICEINFO->DcmDsdSidTabSubfuncAvail) == TRUE))
    {
        DCM_REQ_SUBSERVICE = (DCM_MSGCONTEXT.reqData[DCM_SUB_SID_INDEX]);
        if((uint8)(DCM_REQ_SUBSERVICE & DCM_SUPPRESS_POS_RSP_MASK) != (uint8)0)
        {
            /*SWS_Dcm_00202*/
            SetSuppressPosRespBit();
            /*SWS_Dcm_00201*/
            DCM_REQ_SUBSERVICE &= (~DCM_SUPPRESS_POS_RSP_MASK);
            DCM_MSGCONTEXT.reqData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
        }
        /*PRQA S 3415 ++*/
        /*Allow right hand operand of '&&' is an expression.*/
        /*Check if sub service is supported*/
        if(DCM_REQ_SERVICE != DCM_31_SERVICE)
        {
            if(E_NOT_OK == DsdInternal_CheckSubServiceId())
            {
                /*SWS_Dcm_00273*//*SWS_Dcm_00307*//*SWS_Dcm_00321*/
                DCM_ERRORCODE = DCM_E_SUBFUNCTIONNOTSUPPORTED;
                Result = E_NOT_OK;
            }
            else
            {
                Result = DsdInternal_AddrSesSecCheck(DCM_P_ERRORCODE);
            }
        }
        /*PRQA S 3415 --*/
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_CheckSubServiceId
*
* Description: Check the request sub service id is supported or not
*
* Inputs: None
*
* Outputs: None
*
* Return: E_OK:sub service is supported
*         E_NOT_OK:sub service isn't supported
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DsdInternal_CheckSubServiceId
(
    void
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint8 Offset;
    uint16 Idx;

    for(Offset = (uint8)0; Offset < (DCM_REQ_SERVICEINFO->NumOfSubService); Offset++)
    {
        Idx = (DCM_REQ_SERVICEINFO->StartIndexOfSubService + (uint16)Offset);

        if((DCM_REQ_SUBSERVICE == DCM_CFG_STAB_SS_ID(Idx)) && (TRUE == DCM_CFG_STAB_SS_USED(Idx)))
        {
            DCM_REQ_SUBSERVICEINFO = &(DCM_CFG_STAB_SS_INFO(Idx));
            Result = E_OK;
            break;
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_MatchServiceFnc
*
* Description: Match the service handler
*
* Inputs: None
*
* Outputs: None
*
* Return: E_OK:service handler is matched
*         E_NOT_OK:service handler isn't matched
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DsdInternal_MatchServiceFnc
(
    void
)
{
    Std_ReturnType Result = E_OK;
    /*SWS_Dcm_00196*/
    switch(DCM_REQ_SERVICE)
    {
        /*OBD services*/
#if(DCM_OBD_01_ENABLED == STD_ON)
    case DCM_01_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_01_RequestCurrentPowertrainDiagnosticData);
        break;
#endif
#if(DCM_OBD_02_ENABLED == STD_ON)
    case DCM_02_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_02_RequestPowertrainFreezeFrameData);
        break;
#endif
#if((DCM_OBD_03_ENABLED == STD_ON) || (DCM_OBD_07_ENABLED == STD_ON) || (DCM_OBD_0A_ENABLED == STD_ON))
    case DCM_03_SERVICE:
    case DCM_07_SERVICE:
    case DCM_0A_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_03_07_0A_ObtainingDTC);
        break;
#endif
#if(DCM_OBD_04_ENABLED == STD_ON)
    case DCM_04_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_04_ClearEmissionRelatedDiagnosticInformation);
        break;
#endif
#if(DCM_OBD_06_ENABLED == STD_ON)
    case DCM_06_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_06_RequestOnBoardMonitoringTestResults);
        break;
#endif
#if(DCM_OBD_08_ENABLED == STD_ON)
    case DCM_08_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_08_RequestControlOfOnBoardSystem);
        break;
#endif
#if(DCM_OBD_09_ENABLED == STD_ON)
    case DCM_09_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_09_RequestVehicleInformation);
        break;
#endif
    /*UDS Services*/
#if(DCM_UDS_10_ENABLED == STD_ON)
    case DCM_10_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_10_DiagnosticSessionControl);
        break;
#endif
#if(DCM_UDS_11_ENABLED == STD_ON)
    case DCM_11_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_11_ECUReset);
        break;
#endif
#if((DCM_UDS_14_ENABLED == STD_ON) && (DCM_DEM_SUPPORT == STD_ON))
    case DCM_14_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_14_ClearDiagnosticInformation);
        break;
#endif
#if(DCM_UDS_19_ENABLED == STD_ON)
    case DCM_19_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_19_ReadDTCInformation);
        break;
#endif
#if(DCM_UDS_22_ENABLED == STD_ON)
    case DCM_22_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_22_ReadDataByIdentifier);
        break;
#endif
#if(DCM_UDS_23_ENABLED == STD_ON)
    case DCM_23_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_23_ReadMemoryByAddress);
        break;
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
    case DCM_27_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_27_SecurityAccess);
        break;
#endif
#if(DCM_UDS_28_ENABLED == STD_ON)
    case DCM_28_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_28_CommunicationControl);
        break;
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
    case DCM_29_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_29_Authentication);
        break;
#endif
#if(DCM_UDS_2A_ENABLED == STD_ON)
    case DCM_2A_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_2A_ReadDataByPeriodicIdentifier);
        break;
#endif
#if(DCM_UDS_2C_ENABLED == STD_ON)
    case DCM_2C_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_2C_DynamicallyDefineDataIdentifier);
        break;
#endif
#if(DCM_UDS_2E_ENABLED == STD_ON)
    case DCM_2E_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_2E_WriteDataByIdentifier);
        break;
#endif
#if(DCM_UDS_2F_ENABLED == STD_ON)
    case DCM_2F_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_2F_InputOutputControlByIdentifier);
        break;
#endif
#if(DCM_UDS_31_ENABLED == STD_ON)
    case DCM_31_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_31_RoutineControl);
        break;
#endif
#if(DCM_UDS_34_ENABLED == STD_ON)
    case DCM_34_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_34_RequestDownload);
        break;
#endif
#if(DCM_UDS_35_ENABLED == STD_ON)
    case DCM_35_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_35_RequestUpload);
        break;
#endif
#if(DCM_UDS_36_ENABLED == STD_ON)
    case DCM_36_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_36_TransferData);
        break;
#endif
#if(DCM_UDS_37_ENABLED == STD_ON)
    case DCM_37_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_37_RequestTransferExit);
        break;
#endif
#if(DCM_UDS_38_ENABLED == STD_ON)
    case DCM_38_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_38_RequestFileTransfer);
        break;
#endif
#if(DCM_UDS_3D_ENABLED == STD_ON)
    case DCM_3D_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_3D_WriteMemoryByAddress);
        break;
#endif
#if(DCM_UDS_3E_ENABLED == STD_ON)
    case DCM_3E_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_3E_TesterPresent);
        break;
#endif
#if(DCM_UDS_85_ENABLED == STD_ON)
    case DCM_85_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_85_ControlDTCSetting);
        break;
#endif
#if(DCM_UDS_87_ENABLED == STD_ON)
    case DCM_87_SERVICE:
        DCM_SERVICE_FNC = &(DspInternal_87_LinkControl);
        break;
#endif
    default:
        DCM_SERVICE_FNC = (DCM_REQ_SERVICEINFO->DcmDsdSidTabFnc);
        if(DCM_SERVICE_FNC == NULL_PTR)
        {
            Result = E_NOT_OK;
        }
        break;
    }
    return Result;
}
/*PRQA S 4700 --*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_DcmConfirmation
*
* Description: None
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DsdInternal_DcmConfirmation
(
    Dcm_IdContextType idContext,
    uint16 SourceAddress,
    Dcm_ConfirmationStatusType status
)
{
    /*SWS_Dcm_00236*/
    DspInternal_DcmConfirmation(idContext, SourceAddress, status);
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_CreatNegResponse
*
* Description: Creat the negtive response message
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DsdInternal_CreatNegResponse
(
    void
)
{
#if(STD_ON == DCM_UDS_27_ENABLED)
    uint8 StabId = DCM_CURRENT_STAB;
#endif

    SetNegRespBuffer(DCM_ACTIVE_PCL_ID, DCM_REQ_SERVICE, DCM_ERRORCODE);
    DCM_MSGCONTEXT.resData = DCM_PCL_NEG_BUFFER(DCM_ACTIVE_PCL_ID);
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
    if(DCM_ERRORCODE == DCM_E_CONDITIONSNOTCORRECT)
    {
        DCM_MSGCONTEXT.resDataLen = DCM_UDS_WITH_NRC22_RES_LEN;
    }
    else
#endif
    {
        DCM_MSGCONTEXT.resDataLen = (Dcm_MsgLenType)DCM_UDS_NEG_RES_LEN;
    }

#if(STD_ON == DCM_UDS_27_ENABLED)
    if(DCM_REQ_SERVICE == DCM_27_SERVICE)
    {
        DspInternal_27_ResetSequence(StabId);
    }
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_RCRResponsePending
*
* Description: Forced to send a response pengding message
*
* Inputs: ForceRCRRP
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DsdInternal_RCRResponsePending
(
    boolean ForceRCRRP
)
{
    PduInfoType TxRCRRP;
    PduIdType id;

    if(!CheckDcmState((DCM_PROCESSING_DONE | DCM_RCRRP_FORCE | DCM_RCRRP)))
    {
        /*SWS_Dcm_00203 Clear suppress positive response bit*/
        ClearSuppressPosRespBit();

        if(!CheckRespPendCounter())
        {
            /*SWS_Dcm_00119*/
            SetNegRespBuffer(DCM_ACTIVE_PCL_ID, DCM_REQ_SERVICE, DCM_E_RESPONSEPENDING);
            TxRCRRP.SduDataPtr = DCM_PCL_NEG_BUFFER(DCM_ACTIVE_PCL_ID);
            TxRCRRP.MetaDataPtr = NULL_PTR;
            TxRCRRP.SduLength = DCM_UDS_NEG_RES_LEN;

            if(ForceRCRRP == TRUE)
            {
                ClearDcmState(DCM_RCRRP_FORCE_OK);
                /*do not ReTx*/
                SetDcmState(DCM_RCRRP_FORCE);
            }
            else
            {
                /*do not ReTx*/
                SetDcmState(DCM_RCRRP);
            }
            /*Transmite 0x78 negative response(NR)*/
            id = DCM_CFG_PCL_CONNECTION_MAIN_TX_PDUID(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
            if(E_OK != DcmTransmit(id, &TxRCRRP))
            {
                DsdInternal_ResetWithoutChangeSessionAndSendResponse();
            }
        }
        else/*SWS_Dcm_00120*/
        {
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
            ClearP4Timer();
#endif
            /*SWS_Dcm_00733*//*SWS_Dcm_00735*//*SWS_Dcm_01413 The return values shall be ignored*/
            (void)(*DCM_SERVICE_FNC)(DCM_CANCEL, &DCM_MSGCONTEXT, DCM_P_ERRORCODE);
            DCM_SERVICE_FNC = NULL_PTR;
            DCM_SUBSERVICE_FNC = NULL_PTR;
            DCM_DET_REPORT_RUNTIME_ERROR(DCM_SID_MAINFUNCTION, DCM_E_INTERFACE_TIMEOUT);
#if(DCM_MULTI_CORE_SUPPORT == STD_ON)
            Dcm_MultiCore_CrossingInfoClear();
#endif
            ResetDcmState();
            SetDcmState(DCM_PROCESSING);
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
            DCM_ERRORCODE = DCM_E_CONDITIONSNOTCORRECT;
#else
            DCM_ERRORCODE = DCM_E_GENERALREJECT;
#endif
            DsdInternal_CreatNegResponse();
            DsdInternal_ProcessingDone();
        }
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_ProcessingDone
*
* Description: Means the processing is complete, the final response packet will
*              be sent.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DsdInternal_ProcessingDone
(
    void
)
{
    PduInfoType TransmitPdu;
    PduIdType id;
    uint16 SourceAddress;
    boolean RespFlag = FALSE;

    if((CheckDcmState(DCM_PROCESSING)) && (!CheckDcmState(DCM_PROCESSING_DONE)))
    {
        ClearDcmState(DCM_PROCESSING);
        SetDcmState(DCM_PROCESSING_DONE);

        /*SWS_Dcm_01059 Check whether the response is longer than the resMaxDataLen*/
        if((DCM_MSGCONTEXT.resDataLen) > (DCM_MSGCONTEXT.resMaxDataLen))
        {
            DCM_ERRORCODE = DCM_E_RESPONSETOOLONG;
            DsdInternal_CreatNegResponse();
        }
        /*SWS_Dcm_00222*/
        if(DCM_ERRORCODE == DCM_POS_RESP)
        {
            DCM_MSGCONTEXT.resData[DCM_SID_INDEX] = (DCM_REQ_SERVICE + DCM_SID_RESP_OFFSET);
            /*SWS_Dcm_00231*/
            if(CheckSuppressPosRespBit())
            {
                /*SWS_Dcm_00200, Not send a positive response message*/
            }
            else
            {
                /*Send Positive Response*/
                RespFlag = TRUE;
            }
        }
        else
        {
            if(((DCM_MSGCONTEXT.msgAddInfo.reqType) == DCM_FUNCTIONAL_TYPE) && ((DCM_ERRORCODE == DCM_E_SERVICENOTSUPPORTED) \
                || (DCM_ERRORCODE == DCM_E_SUBFUNCTIONNOTSUPPORTED) || (DCM_ERRORCODE == DCM_E_REQUESTOUTOFRANGE) \
                || (DCM_ERRORCODE == DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION) \
                || (DCM_ERRORCODE == DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION)))
            {
                /*SWS_Dcm_00001 In case of functional addressing the DSD submodule shall suppress the negative response
                for NRC 0x11, 0x12, 0x31, 0x7E and 0x7F*/
            }
            else
            {
                /*Send Negative Response*/
                RespFlag = TRUE;
            }
        }

        ClearP2Timer();/*These line of code should be placed before the Dcm reset to idle. If this line of code is placed after
        the Dcm reset to idle, it may successfully received a new diagnostic request and set P2 in the interrupt beyween resetting
        Dcm idle and clearing P2. After returning from the interrupt, P2 wwill be cleared, causing the inability to send NRC78.*/
        ClearRespPendCounter();

        if(RespFlag == FALSE)
        {
            /*SWS_Dcm_00238 Not transmit any response*/
            /*SWS_Dcm_00141*//*Start S3 Timer*/
            if(DCM_SES_IDX != DCM_DEFAULT_IDX)
            {
                SetS3Timer(DCM_CFG_PCL_S3(DCM_ACTIVE_PCL_ID));
            }
            else if(((DCM_REQ_SERVICE != DCM_10_SERVICE) && (DCM_REQ_SERVICE != DCM_11_SERVICE)) \
                || (DCM_ERRORCODE != DCM_POS_RESP))
            {
                /*SWS_Dcm_00697*//*SWS_Dcm_01374*/
                COMM_DCM_INACTIVEDIAGNOSTIC(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
            }
            else
            {
                /*ComM_DCM_InactiveDiagnostic of 0x10,0x11 will be executed in their ServicePostFunction*/
            }

            if(DCM_ERRORCODE == DCM_POS_RESP)
            {
                SourceAddress = DCM_CFG_PCL_CONNECTION_MAIN_TESTER_ADDR(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
                /*SWS_Dcm_00240*/
                DspInternal_DcmConfirmation(DCM_MSGCONTEXT.idContext, SourceAddress, DCM_RES_POS_OK);
            }
            else
            {
                DCM_ERRORCODE = DCM_POS_RESP;
                DcmInternal_InitMsgContext();
                ResetDcmState();
            }

            /*SWS_Dcm_01482*/
#if(STD_ON == DCM_UDS_29_ENABLED)
            if((DCM_SES_IDX == DCM_DEFAULT_IDX) && ((DCM_AU_STATE & DCM_AU_STATE_AUTHENTICATED) != DCM_AU_STATE_DEAUTHENTICATED))
            {
                SetAuthenticationTimer();
            }
#endif
        }
        else
        {
            /* Positive response or negative response */
            TransmitPdu.SduDataPtr = DCM_MSGCONTEXT.resData;
            TransmitPdu.MetaDataPtr = NULL_PTR;
            TransmitPdu.SduLength  = (uint16)(DCM_MSGCONTEXT.resDataLen);
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
            /*Reset the CopyDataIndex value to 0.*/
            DCM_PCL_TXDATA_INDEX(DCM_ACTIVE_PCL_ID) = (Dcm_MsgLenType)0;
#else
            DCM_PCL_DATA_INDEX(DCM_ACTIVE_PCL_ID) = (Dcm_MsgLenType)0;
#endif
            /*SWS_Dcm_00114*//*SWS_Dcm_00115*//*SWS_Dcm_00118*/
            id = DCM_CFG_PCL_CONNECTION_MAIN_TX_PDUID(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
            /*SWS_Dcm_00225*//*SWS_Dcm_00232*//*SWS_Dcm_00237*/
            if(E_OK != DcmTransmit(id, &TransmitPdu))
            {
                DsdInternal_ResetWithoutChangeSessionAndSendResponse();
            }
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_MainFunction
*
* Description: Mainfunction to check the service is supported or not.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DsdInternal_MainFunction
(
    void
)
{
    Std_ReturnType Result = E_OK;

    if(DCM_RX_IND_FLAG == TRUE)
    {
        /*Clear the rx indication flag.*/
        DCM_RX_IND_FLAG = FALSE;
        /*SWS_Dcm_00827*/
        Result = DsdInternal_PreCheck();

        if(Result == E_OK)
        {
            /*SWS_Dcm_00178*//*SWS_Dcm_00192*/
            Result = DsdInternal_ServiceCheck();
        }

        if(Result == E_OK)
        {
            /*SWS_Dcm_00516*/
            Result = DsdInternal_PostCheck();
        }
        
        /*send negative reponse, process over*/
        if(Result == E_NOT_OK)
        {
            /*SWS_Dcm_01414*//*SWS_Dcm_01415*/
            if((DCM_ERRORCODE == DCM_POS_RESP) || (DCM_ERRORCODE == DCM_E_RESPONSEPENDING))
            {
                DCM_DET_REPORT_RUNTIME_ERROR(DCM_SID_MAINFUNCTION, DCM_E_INVALID_VALUE);
                DCM_ERRORCODE = DCM_E_GENERALREJECT;
            }
            DsdInternal_CreatNegResponse();
            DsdInternal_ProcessingDone();
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_MainFunction
*
* Description: Mainfunction to check if sub-service is supported or not and 
*              the subsequent processing
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DspInternal_MainFunction
(
    void
)
{
    Std_ReturnType Result = E_OK;

    if((DCM_SERVICE_FNC != NULL_PTR) && (CheckDcmState(DCM_PROCESSING)) \
        && (!CheckDcmState((DCM_RCRRP | DCM_RCRRP_FORCE))))
    {
#if(DCM_UDS_2A_ENABLED == STD_ON)
        if((DCM_CURRENT_DID_SERVICE == DCM_2A_SERVICE) && ((DCM_REQ_SERVICE == DCM_22_SERVICE) || (DCM_REQ_SERVICE == DCM_23_SERVICE) \
            || (DCM_REQ_SERVICE == DCM_2E_SERVICE) || (DCM_REQ_SERVICE == DCM_2F_SERVICE)))
        {
            DCM_ERRORCODE = DCM_E_GENERALREJECT;
            /*send negative response*/
            DsdInternal_CreatNegResponse();
            DsdInternal_ProcessingDone();
        }
        else
#endif
        {
#if(DCM_UDS_2A_ENABLED == STD_ON)
            if((DCM_REQ_SERVICE == DCM_22_SERVICE) || (DCM_REQ_SERVICE == DCM_23_SERVICE) \
                || (DCM_REQ_SERVICE == DCM_2E_SERVICE) || (DCM_REQ_SERVICE == DCM_2F_SERVICE))
            {
                DCM_CURRENT_DID_SERVICE = DCM_REQ_SERVICE;
            }
#endif
            Result = (*DCM_SERVICE_FNC)(DCM_OP_STATUS, &DCM_MSGCONTEXT, DCM_P_ERRORCODE);

            if(DCM_OP_STATUS != DCM_CANCEL)
            {
                if(Result == E_OK)
                {
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
                    ClearP4Timer();
#endif
                    DCM_ERRORCODE = DCM_POS_RESP;
                    /*send postive response*/
                    DsdInternal_ProcessingDone();
                }
                else if(Result == DCM_E_PENDING)
                {
                    /*SWS_Dcm_00530*/
                    DCM_OP_STATUS = DCM_PENDING;
                }
                else if(Result == DCM_E_FORCE_RCRRP)
                {
                    /*SWS_Dcm_00528*/
                    DsdInternal_RCRResponsePending(TRUE);
                }
                else/*Result == E_NOT_OK*/
                {
                    /*SWS_Dcm_01414*//*SWS_Dcm_01415*/
                    if((DCM_ERRORCODE == DCM_POS_RESP) || (DCM_ERRORCODE == DCM_E_RESPONSEPENDING))
                    {
                        DCM_DET_REPORT_RUNTIME_ERROR(DCM_SID_MAINFUNCTION, DCM_E_INVALID_VALUE);
                        DCM_ERRORCODE = DCM_E_GENERALREJECT;
                    }
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
                    ClearP4Timer();
#endif
                    /*send negative response*/
                    DsdInternal_CreatNegResponse();
                    DsdInternal_ProcessingDone();
                }
            }
            else
            {
                /*No need to send response*/
                DcmInternal_InitMsgContext();
                ResetDcmState();
            }
        }
    }

#if(DCM_UDS_2A_ENABLED == STD_ON)
    if(DCM_ACTIVE_PCL_ID < DCM_CFG_NUM_OF_PROTOCOL)
    {
        DspInternal_2A_PeriodicTransmission();
    }
#endif
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_DcmConfirmation
*
* Description: Processing after response is sent or suppressed.
*
* Inputs: idContext, SourceAddress, status
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DspInternal_DcmConfirmation
(
    Dcm_IdContextType idContext,
    uint16 SourceAddress,
    Dcm_ConfirmationStatusType status
)
{
    (void)idContext;
    (void)SourceAddress;

    switch(status)
    {
    case DCM_RES_POS_OK:
        DspInternal_PostProcessor();
        break;

    case DCM_RES_POS_NOT_OK:
    case DCM_RES_NEG_OK:
    case DCM_RES_NEG_NOT_OK:
    default:
        /*do nothing*/
        break;
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_PostProcessor
*
* Description: Processing after positive response is sent or suppressed.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DspInternal_PostProcessor
(
    void
)
{
    switch(DCM_REQ_SERVICE)
    {
#if(DCM_UDS_10_ENABLED == STD_ON)
    case DCM_10_SERVICE:/*Session Transition*/
        DspInternal_10_Sub_Post();
        break;
#endif
#if(DCM_UDS_11_ENABLED == STD_ON)
    case DCM_11_SERVICE:
        /*SWS_Dcm_00594*/
        (void)SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_EXECUTE);
        (void)Dcm_ResetToDefaultSession();
        break;
#endif
#if(DCM_UDS_28_ENABLED == STD_ON)
    case DCM_28_SERVICE:
        DspInternal_28_Sub_Post();
        break;
#endif
    default:
        /*do nothing*/
        break;
    }
    DcmInternal_InitMsgContext();
    ResetDcmState();
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_AddrSesSecCheck
*
* Description: This function is used to check whether the requested subservice
*              is supported under the current addressing mode, session mode, and
*              security level
*
* Inputs: None
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DsdInternal_AddrSesSecCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_NOT_OK;

    uint8 SupportAddress = (DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceSupportAddress);
#if(DCM_UDS_10_ENABLED == STD_ON)
    Dcm_SessionMaskType SesLevelRef = (DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceSessionLevelRef);
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
    Dcm_SecurityMaskType SecLevelRef = (DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceSecurityLevelRef);
    Dcm_SecurityMaskType CurSecMask = DslInternal_GetSecurityMask();
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
    Dcm_AuRoleMaskType AuRoleMask = (DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceRoleRef);
#endif

    if(!(SupportAddress & ((uint8)0x01 << DCM_MSGCONTEXT.msgAddInfo.reqType)))
    {
        *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
    }
#if(STD_ON == DCM_UDS_29_ENABLED)
    else if(!(DCM_AU_CUR_ROLE & AuRoleMask))
    {
        /*SWS_Dcm_01544*/
        *pErrorCode = DCM_E_AUTHENTICATIONREQUIRED;
    }
#endif
#if(DCM_UDS_10_ENABLED == STD_ON)
    else if(!(DCM_CFG_SESSION_MASK(DCM_SES_IDX) & SesLevelRef))
    {
        /*SWS_Dcm_00616*/
        *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
    }
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
    else if(!(CurSecMask & SecLevelRef))
    {
        /*SWS_Dcm_00617*/
        *pErrorCode = DCM_E_SECURITYACCESSDENIED;
    }
#endif
    else
    {
        Result = E_OK;
    }
    return Result;
}

#if(DCM_UDS_10_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_10_DiagnosticSessionControl SWS_Dcm_00250
*
* Description: This function is the code implementation of the processing logic
*              for the 0x10 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_10_DiagnosticSessionControl
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 Idx;

    if(OpStatus == DCM_INITIAL)
    {
#if(DCM_UDS_10_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
        ClearSuppressPosRespBit();
#endif
        DCM_REQ_ROW_IDX = DCM_DATA_CLEAR;

        if((pMsgContext->reqDataLen) != DCM_LENGTH_2_BYTE)
        {
            /*SWS_Dcm_00272*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
            SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
            /*Find the corresponding session row*/
            for(Idx = (uint8)0; Idx < DCM_CFG_SESSION_NUM; Idx++)
            {
                if(DCM_REQ_SUBSERVICE == DCM_CFG_SESSION_LEVEL(Idx))
                {
                    DCM_REQ_ROW_IDX = Idx;
                    break;
                }
            }
            DCM_SUBSERVICE_FNC = &(DspInternal_10_Sub_Processor);
        }
    }

    if((OpStatus != DCM_CANCEL) && (Result == E_OK))
    {
        Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);

        if(Result == E_OK)
        {
            pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
#if(DCM_RESPONSE_WITHP2TIMER==STD_ON)
            pMsgContext->resData[DCM_INDEX_2] = (Dcm_MsgItemType)(DCM_CFG_SESSION_P2(DCM_REQ_ROW_IDX) >> DCM_SHIFT_8);
            pMsgContext->resData[DCM_INDEX_3] = (Dcm_MsgItemType)(DCM_CFG_SESSION_P2(DCM_REQ_ROW_IDX));
            pMsgContext->resData[DCM_INDEX_4] = \
                (Dcm_MsgItemType)((uint16)(DCM_CFG_SESSION_P2STAR(DCM_REQ_ROW_IDX) / DCM_P2_STAR_RESOLUTION) >> DCM_SHIFT_8);
            pMsgContext->resData[DCM_INDEX_5] = (Dcm_MsgItemType)(DCM_CFG_SESSION_P2STAR(DCM_REQ_ROW_IDX) / DCM_P2_STAR_RESOLUTION);
            pMsgContext->resDataLen = DCM_LENGTH_6_BYTE;
#else
            pMsgContext->resDataLen = DCM_LENGTH_2_BYTE;
#endif
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_10_Sub_Processor
*
* Description: This function is the code implementation of the processing logic
*              for the subservice of 0x10 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_10_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 SrcAddr;
    Dcm_ProgConditionsType ProgConditions;

    (void)pMsgContext;

    if(OpStatus == DCM_INITIAL)
    {
        /*Reset the execution step information*/
        DCM_CURRENT_EXE_STEP = DCM_DATA_CLEAR;

        if(DCM_CFG_SESSION_BOOT(DCM_REQ_ROW_IDX) == DCM_NO_BOOT)
        {
            /*Result = E_OK; positive response*/
        }
        else
        {
            /*Set the step to one to ask SchM if jumping to Bootloader is allowed*/
            DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_ONE;
        }
    }

    if(OpStatus != DCM_CANCEL)
    {
        /*Step 1: Ask SchM if jumping to Bootloader is allowed*/
        if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_ONE)
        {
            switch(DCM_CFG_SESSION_BOOT(DCM_REQ_ROW_IDX))
            {
            case DCM_OEM_BOOT:
            case DCM_OEM_BOOT_RESPAPP:
                /*SWS_Dcm_00532*/
                Result = SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER);
                break;

            default:
                /*SWS_Dcm_00592*/
                Result = SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER);
                break;
            }

            if(Result == E_OK)
            {
                /*SWS_Dcm_00654*//*SWS_Dcm_00720*//*SWS_Dcm_01177*//*SWS_Dcm_01178*/
                if(DCM_CFG_PCL_SEND_78_ON_RESTART(DCM_ACTIVE_PCL_ID) == TRUE)
                {
                    Result = DCM_E_FORCE_RCRRP;
                }

                if((DCM_CFG_SESSION_BOOT(DCM_REQ_ROW_IDX) == DCM_OEM_BOOT) || (DCM_CFG_SESSION_BOOT(DCM_REQ_ROW_IDX) == DCM_SYS_BOOT))
                {
                    /*Next step: Set conditions on which the jump to bootloader has been requested.*/
                    DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_TWO;
                }
                else
                {
                    /*Next step: Initiate the final response after a successful transmission of NRC 0x78
                    or Send the final response directly*/
                    DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_OVER;
                }
            }
            else if(Result == E_NOT_OK)
            {
                /*SWS_Dcm_01175*/
                *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
                Dcm_SetNRC22Reason(DCM_NRC22_REASON_1);
#endif
            }
            else
            {
                /*Result = DCM_E_PENDING*/
            }
        }

        /*Step 2: Store relevant information prior to jumping to bootloader for DCM_OEM_BOOT or DCM_SYS_BOOT*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_TWO))
        {
            SrcAddr = DCM_CFG_PCL_CONNECTION_MAIN_TESTER_ADDR(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
            ProgConditions.ConnectionId = DCM_ACTIVE_CON_ID;
            ProgConditions.TesterAddr = SrcAddr;
            ProgConditions.Sid = DCM_REQ_SERVICE;
            ProgConditions.SubFncId = DCM_REQ_SUBSERVICE;
            ProgConditions.ReprogramingRequest = TRUE;
            ProgConditions.ApplUpdated = FALSE;
            if(CheckSuppressPosRespBit())
            {
                ProgConditions.ResponseRequired = FALSE;
            }
            else
            {
                ProgConditions.ResponseRequired = TRUE;
            }
            /*SWS_Dcm_00535*/
            Result = Dcm_SetProgConditions(OpStatus, &ProgConditions);

            if(Result == E_OK)
            {
                /*SWS_Dcm_01163*//*SWS_Dcm_00719*/
                (void)SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_EXECUTE);
                ResetDcmState();
                ClearP2Timer();
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
                ClearP4Timer();
#endif
            }
            else if(Result == E_NOT_OK)
            {
                /*SWS_Dcm_00715*/
                *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
                Dcm_SetNRC22Reason(DCM_NRC22_REASON_2);
#endif
            }
            else
            {
                /*SWS_Dcm_01184, Result = DCM_E_PENDING*/
            }
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_10_Sub_Post
*
* Description: This function is used to complete the processing after the positive
*              response of the 0x10 service is successfully sent
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DspInternal_10_Sub_Post
(
    void
)
{
    Dcm_ProgConditionsType ProgConditions;
    uint16 SrcAddr;
    Std_ReturnType ret = E_OK;

    if(DCM_REQ_SUBSERVICE == DCM_DEFAULT_SESSION)
    {
        ClearS3Timer();

        /*SWS_Dcm_01374*/
        COMM_DCM_INACTIVEDIAGNOSTIC(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
    }
    else
    {
        /*non default session*/
        SetS3Timer(DCM_CFG_PCL_S3(DCM_ACTIVE_PCL_ID));
    }
    /*SWS_Dcm_00311 Set current session level*/
    DslInternal_SetSesCtrlType(DCM_REQ_ROW_IDX);

    if((DCM_CFG_SESSION_BOOT(DCM_SES_IDX) == DCM_OEM_BOOT_RESPAPP) || (DCM_CFG_SESSION_BOOT(DCM_SES_IDX) == DCM_SYS_BOOT_RESPAPP))
    {
        SrcAddr = DCM_CFG_PCL_CONNECTION_MAIN_TESTER_ADDR(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
        ProgConditions.ConnectionId = DCM_ACTIVE_CON_ID;
        ProgConditions.TesterAddr = SrcAddr;
        ProgConditions.Sid = DCM_REQ_SERVICE;
        ProgConditions.SubFncId = DCM_REQ_SUBSERVICE;
        ProgConditions.ReprogramingRequest = TRUE;
        ProgConditions.ApplUpdated = FALSE;
        ProgConditions.ResponseRequired = FALSE;
        /*SWS_Dcm_01179*/
        ret = Dcm_SetProgConditions(DCM_INITIAL, &ProgConditions);
        if(ret == E_OK)
        {
            /*SWS_Dcm_01180*/
            (void)SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_EXECUTE);
        }
        else
        {
            /*SWS_Dcm_01181 Dcm shall not request any reset*/
            /*ret = E_NOT_OK/ret = DCM_E_PENDING*/
        }
    }
}
#endif

#if(DCM_UDS_11_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_11_ECUReset SWS_Dcm_00260
*
* Description: This function is the code implementation of the processing logic
*              for the 0x11 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_11_ECUReset
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 Idx;

    if(OpStatus == DCM_INITIAL)
    {
#if(DCM_UDS_11_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
        ClearSuppressPosRespBit();
#endif
        DCM_REQ_ROW_IDX = DCM_DATA_CLEAR;

        if((pMsgContext->reqDataLen) != DCM_LENGTH_2_BYTE)
        {
            /*SWS_Dcm_00272*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
            SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
            /*Find the corresponding reset row*/
            for(Idx = (uint8)0; Idx < DCM_CFG_RESET_NUM; Idx++)
            {
                if(DCM_REQ_SUBSERVICE == DCM_CFG_RESET_ID(Idx))
                {
                    DCM_REQ_ROW_IDX = Idx;
                    break;
                }
            }
            DCM_SUBSERVICE_FNC = &(DspInternal_11_Sub_Processor);
        }
    }

    if((OpStatus != DCM_CANCEL) && (Result == E_OK))
    {
        Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);

        if(Result == E_OK)
        {
            pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
            pMsgContext->resDataLen = DCM_LENGTH_2_BYTE;
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_11_Sub_Processor
*
* Description: This function is the code implementation of the processing logic
*              for the subservice of 0x11 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_11_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 SrcAddr;
    Dcm_ProgConditionsType ProgConditions;

    (void)pMsgContext;

    if(OpStatus == DCM_INITIAL)
    {
        /*Set the step to one to ask SchM if reset is allowed*/
        DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_ONE;
    }
    
    if(OpStatus != DCM_CANCEL)
    {
        /*Step 1: Ask SchM if reset is allowed*/
        if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_ONE)
        {
            /*SWS_Dcm_00373*/
            if(DCM_REQ_SUBSERVICE == DCM_HARD_RESET)
            {
                Result = SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_HARD);
            }
            else if(DCM_REQ_SUBSERVICE == DCM_KEYOFFON_RESET)
            {
                Result = SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_KEYONOFF);
            }
            else/*(DCM_REQ_SUBSERVICE == DCM_SOFT_RESET)*/
            {
                Result = SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_SOFT);
            }

            if(Result == E_OK)
            {
                if(DCM_CFG_RESET_RESPONSE(DCM_REQ_ROW_IDX) == DCM_AFTER_RESET)
                {
                    /*Next step: Set conditions on which the reset has been requested.*/
                    DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_TWO;
                }
                else
                {
                    /*Next step: Initiate the final response*/
                    DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_OVER;
                }
            }
        }

        /*Step 2: Store relevant information prior to reset*/
        if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_TWO)
        {
            SrcAddr = DCM_CFG_PCL_CONNECTION_MAIN_TESTER_ADDR(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
            ProgConditions.ConnectionId = DCM_ACTIVE_CON_ID;
            ProgConditions.TesterAddr = SrcAddr;
            ProgConditions.Sid = DCM_REQ_SERVICE;
            ProgConditions.SubFncId = DCM_REQ_SUBSERVICE;
            ProgConditions.ReprogramingRequest = FALSE;
            ProgConditions.ApplUpdated = FALSE;

            if(CheckSuppressPosRespBit())
            {
                ProgConditions.ResponseRequired = FALSE;
            }
            else
            {
                ProgConditions.ResponseRequired = TRUE;
            }
            /*Jump due to ECUReset*//*SWS_Dcm_01184*/
            Result = Dcm_SetProgConditions(OpStatus, &ProgConditions);

            if(Result == E_OK)
            {
                /*By setting the suppression of the positive response bit, the purpose of not sending a positive response is achieved.*/
                SetSuppressPosRespBit();
            }
        }
    }

    if(Result == E_NOT_OK)
    {
        *pErrorCode = DCM_E_GENERALREJECT;
    }
    return Result;
}
#endif

#if((DCM_UDS_14_ENABLED == STD_ON) && (DCM_DEM_SUPPORT == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_14_ClearDiagnosticInformation SWS_Dcm_00247
*
* Description: This function is the code implementation of the processing logic
*              for the 0x14 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_14_ClearDiagnosticInformation
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 DemClient = DCM_CFG_PCL_DEM_CLIENT(DCM_ACTIVE_PCL_ID);

    if(OpStatus == DCM_INITIAL)
    {
        /*Reset the execution step information*/
        DCM_CURRENT_EXE_STEP = DCM_DATA_CLEAR;
        /*SWS_Dcm_00272 Check message length*/
        if((pMsgContext->reqDataLen) != DCM_LENGTH_4_BYTE)
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
            /*Get the requested DTC group*/
            DCM_DTC_DTC = DcmMakeDTC(pMsgContext->reqData[DCM_INDEX_1], pMsgContext->reqData[DCM_INDEX_2], pMsgContext->reqData[DCM_INDEX_3]);
            /*Next step*/
            DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_ONE;

#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
            SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
        }
    }/*if(OpStatus == DCM_INITIAL)*/

    if(OpStatus != DCM_CANCEL)
    {
        /*Step 1: Select requested DTC or DTC group*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_ONE))
        {
            /*SWS_Dcm_01263*/
            Result = Dem_SelectDTC(DemClient, DCM_DTC_DTC, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
            /*Dem_SelectDTC has only two return values: E_OK and DEM_BUSY.*/
            if(Result == DEM_BUSY)
            {
                Result = DCM_E_PENDING;
            }
            else
            {
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_TWO;
            }
        }

        /*Step 2: Get DTC selection result*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_TWO))
        {
            /*SWS_Dcm_01400*/
            Result = Dem_GetDTCSelectionResultForClearDTC(DemClient);
            switch(Result)
            {
            case DEM_PENDING:
            case DEM_BUSY:
                Result = DCM_E_PENDING;
                break;
            /*SWS_Dcm_01265*/
            case DEM_WRONG_DTC:
            case DEM_WRONG_DTCORIGIN:
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
                break;

            case E_NOT_OK:
                *pErrorCode = DCM_E_GENERALREJECT;
                break;

            default:/*E_OK*/
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_THREE;
                break;
            }
        }

#if(DCM_APP_CLEARDTCCHECK_ENABLE == STD_ON)
        if(Result == E_OK)
        {
            /*SWS_Dcm_01268*//*SWS_Dcm_01270*/
            /*The function has only two return values:E_OK and E_NOT_OK.*/
            Result = Dcm_Rte_ClearDiagnosticInformation_ClearDTCCheckFnc(DCM_DTC_DTC, pErrorCode);
        }
#endif
        /*Step 3: Clear the requested DTC or DTC group*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_THREE))
        {
            /*SWS_Dcm_00005*/
            Result = Dem_ClearDTC(DemClient);
            switch(Result)
            {
            /*SWS_Dcm_00706*/
            case DEM_PENDING:
            case DEM_BUSY:
                Result = DCM_E_PENDING;
                break;
            /*SWS_Dcm_00708*/
            case DEM_WRONG_DTC:
            case DEM_WRONG_DTCORIGIN:
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
                break;
            /*SWS_Dcm_00707*/
            case DEM_CLEAR_FAILED:
            /*SWS_Dcm_00966*/
            case DEM_CLEAR_BUSY:
                *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
                Dcm_SetNRC22Reason(DCM_NRC22_REASON_4);
#endif
                Result = E_NOT_OK;
                break;
            /*SWS_Dcm_01060*/
            case DEM_CLEAR_MEMORY_ERROR:
                *pErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                Result = E_NOT_OK;
                break;

            case E_NOT_OK:
                *pErrorCode = DCM_E_GENERALREJECT;
                break;
            /*SWS_Dcm_00705*/
            default:/*E_OK*/
                /*Send positive response*/
                break;
            }
        }

        if(Result == E_OK)
        {
            pMsgContext->resDataLen = DCM_LENGTH_1_BYTE;
        }
    }
    return Result;
}
/*PRQA S 4700 --*/
#endif

#if(DCM_UDS_19_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_19_ReadDTCInformation SWS_Dcm_00248
*
* Description: This function is the code implementation of the processing logic
*              for the 0x19 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_ReadDTCInformation
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    if(OpStatus == DCM_INITIAL)
    {
#if(DCM_UDS_19_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
        ClearSuppressPosRespBit();
#endif

        /*Check whether the length of the request message is correct based on the subservice.*/
        if((DCM_REQ_SUBSERVICE == DCM_READ_DTC_01) || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_02) \
            || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_05) || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_12) \
            || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_13) || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_1A) \
            || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_55))
        {
            if((pMsgContext->reqDataLen) != DCM_LENGTH_3_BYTE)
            {
                Result = E_NOT_OK;
            }
        }
        else if((DCM_REQ_SUBSERVICE == DCM_READ_DTC_03) || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_0A) \
            || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_0B) || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_0C) \
            || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_0D) || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_0E) \
            || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_14) || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_15))
        {
            if((pMsgContext->reqDataLen) != DCM_LENGTH_2_BYTE)
            {
                Result = E_NOT_OK;
            }
        }
        else if((DCM_REQ_SUBSERVICE == DCM_READ_DTC_04) || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_06))
        {
            if((pMsgContext->reqDataLen) != DCM_LENGTH_6_BYTE)
            {
                Result = E_NOT_OK;
            }
        }
        else if((DCM_REQ_SUBSERVICE == DCM_READ_DTC_07) || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_08) \
            || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_17) || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_56))
        {
            if((pMsgContext->reqDataLen) != DCM_LENGTH_4_BYTE)
            {
                Result = E_NOT_OK;
            }
        }
        else if((DCM_REQ_SUBSERVICE == DCM_READ_DTC_09) || (DCM_REQ_SUBSERVICE == DCM_READ_DTC_42))
        {
            if((pMsgContext->reqDataLen) != DCM_LENGTH_5_BYTE)
            {
                Result = E_NOT_OK;
            }
        }
        else/*DCM_READ_DTC_18, DCM_READ_DTC_19*/
        {
            if((pMsgContext->reqDataLen) != DCM_LENGTH_7_BYTE)
            {
                Result = E_NOT_OK;
            }
        }

        if(Result == E_NOT_OK)
        {
            /*SWS_Dcm_00272*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        }
        else/*Matches the entry function of the requested subservice*/
        {
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
            SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
#if(DCM_DEM_SUPPORT == STD_ON)
            DCM_SUBSERVICE_FNC = &(DspInternal_19_Sub_Processor);
#else
            if((DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceFnc) == NULL_PTR)
            {
                *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
                Result = E_NOT_OK;
            }
            else
            {
                DCM_SUBSERVICE_FNC = (DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceFnc);
            }
#endif
        }
    }/*if(OpStatus == DCM_INITIAL)*/

    /*Executive subservice*/
    if(Result == E_OK)
    {
        Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
    }

    /*Send positive response*/
    if(Result == E_OK)
    {
        pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
    }
    return Result;
}
/*PRQA S 4700 --*/

#if(DCM_DEM_SUPPORT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_19_Sub_Processor
*
* Description: This function is used to match the handler of the subservice of
*              the 0x19 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    switch(DCM_REQ_SUBSERVICE)
    {
#if(DCM_UDS_19_01_07_12_ENABLED == STD_ON)
    case DCM_READ_DTC_01:
    case DCM_READ_DTC_07:
    case DCM_READ_DTC_12:
        Result = DspInternal_19_01_07_12_Processor(OpStatus, pMsgContext, pErrorCode);
        break;
#endif
#if(DCM_UDS_19_02_0A_13_15_17_ENABLED == STD_ON)
    case DCM_READ_DTC_02:
    case DCM_READ_DTC_0A:
    case DCM_READ_DTC_13:
    case DCM_READ_DTC_15:
    case DCM_READ_DTC_17:
        Result = DspInternal_19_02_0A_13_15_17_Processor(OpStatus, pMsgContext, pErrorCode);
        break;
#endif
#if(DCM_UDS_19_03_ENABLED == STD_ON)
    case DCM_READ_DTC_03:
        Result = DspInternal_19_03_Processor(OpStatus, pMsgContext, pErrorCode);
        break;
#endif
#if(DCM_UDS_19_04_18_ENABLED == STD_ON)
    case DCM_READ_DTC_04:
    case DCM_READ_DTC_18:
        Result = DspInternal_19_04_18_Processor(OpStatus, pMsgContext, pErrorCode);
        break;
#endif
#if(DCM_UDS_19_05_ENABLED == STD_ON)
    case DCM_READ_DTC_05:
        Result = DspInternal_19_05_Processor(OpStatus, pMsgContext, pErrorCode);
        break;
#endif
#if(DCM_UDS_19_06_19_ENABLED == STD_ON)
    case DCM_READ_DTC_06:
    case DCM_READ_DTC_19:
        Result = DspInternal_19_06_19_Processor(OpStatus, pMsgContext, pErrorCode);
        break;
#endif
#if(DCM_UDS_19_08_ENABLED == STD_ON)
    case DCM_READ_DTC_08:
        Result = DspInternal_19_08_Processor(OpStatus, pMsgContext, pErrorCode);
        break;
#endif
#if(DCM_UDS_19_09_ENABLED == STD_ON)
    case DCM_READ_DTC_09:
        Result = DspInternal_19_09_Processor(OpStatus, pMsgContext, pErrorCode);
        break;
#endif
#if(DCM_UDS_19_0B_0C_0D_0E_ENABLED == STD_ON)
    case DCM_READ_DTC_0B:
    case DCM_READ_DTC_0C:
    case DCM_READ_DTC_0D:
    case DCM_READ_DTC_0E:
        DspInternal_19_0B_0C_0D_0E_Processor(OpStatus, pMsgContext, pErrorCode);
        break;
#endif
#if(DCM_UDS_19_14_ENABLED == STD_ON)
    case DCM_READ_DTC_14:
        Result = DspInternal_19_14_Processor(OpStatus, pMsgContext, pErrorCode);
        break;
#endif
#if(DCM_UDS_19_1A_ENABLED == STD_ON)
    case DCM_READ_DTC_1A:
        Result = DspInternal_19_1A_Processor(OpStatus, pMsgContext, pErrorCode);
        break;
#endif
#if(DCM_UDS_19_42_ENABLED == STD_ON)
    case DCM_READ_DTC_42:
        Result = DspInternal_19_42_Processor(OpStatus, pMsgContext, pErrorCode);
        break;
#endif
#if(DCM_UDS_19_55_ENABLED == STD_ON)
    case DCM_READ_DTC_55:
        Result = DspInternal_19_55_Processor(OpStatus, pMsgContext, pErrorCode);
        break;
#endif
#if(DCM_UDS_19_56_ENABLED == STD_ON)
    case DCM_READ_DTC_56:
        Result = DspInternal_19_56_Processor(OpStatus, pMsgContext, pErrorCode);
        break;
#endif
    default:
        Result = E_NOT_OK;
        *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        break;
    }
    return Result;
}

#if(DCM_UDS_19_01_07_12_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_19_01_07_12_Processor
*
* Description: This function is used to implement the processing logic of the 01,
*              07 and 12 subservices of the 19 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_01_07_12_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 DemClient = DCM_CFG_PCL_DEM_CLIENT(DCM_ACTIVE_PCL_ID);
    Dem_UdsStatusByteType AvailableMask;
    uint16 DTCCounter = (uint16)0;

    if(OpStatus == DCM_INITIAL)
    {
        /*Get the request DTC status mask.*/
        if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_07)
        {
            DCM_DTC_STATUS = pMsgContext->reqData[DCM_INDEX_3];
            /*Get the request DTC severity mask.*/
            DCM_DTC_SEVERITY = pMsgContext->reqData[DCM_INDEX_2];
        }
        else
        {
            DCM_DTC_STATUS = pMsgContext->reqData[DCM_INDEX_2];
            /*Set DTCSeverity to a non-zero value.*/
            DCM_DTC_SEVERITY = (Dem_DTCSeverityType)0x01;
        }

        /*Set filter*//*SWS_Dcm_00700*/
        if(DCM_DTC_STATUS != (uint8)0x00)
        {
            /*SWS_Dcm_00835*//*SWS_Dcm_00293*/
            if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_01)
            {
                Result = Dem_SetDTCFilter(DemClient, DCM_DTC_STATUS, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY, \
                                        FALSE, (Dem_DTCSeverityType)0, FALSE);
            }
            else if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_07)
            {
                /*SWS_Dcm_01160*/
                if(DCM_DTC_SEVERITY != (Dem_DTCSeverityType)0x00)
                {
                    Result = Dem_SetDTCFilter(DemClient, DCM_DTC_STATUS, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY, \
                                            TRUE, DCM_DTC_SEVERITY, FALSE);
                }
            }
            else/*(DCM_REQ_SUBSERVICE == DCM_READ_DTC_12)*/
            {
                Result = Dem_SetDTCFilter(DemClient, DCM_DTC_STATUS, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY, \
                                        FALSE, (Dem_DTCSeverityType)0, FALSE);
            }

            if(Result == E_NOT_OK)
            {
                /*SWS_Dcm_01043*//*SWS_Dcm_01255*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
        }
    }

    if(OpStatus != DCM_CANCEL)
    {
        /*When the DTC status mask in the request message is not 0, the number of DTCS that pass filtering is read.*/
        if((Result == E_OK) && (DCM_DTC_STATUS != (uint8)0x00) && (DCM_DTC_SEVERITY != (Dem_DTCSeverityType)0x00))
        {
            /*SWS_Dcm_00293*/
            Result = Dem_GetNumberOfFilteredDTC(DemClient, &DTCCounter);

            if(Result == E_NOT_OK)
            {
                /*SWS_Dcm_00271 The AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
            else if(Result == DEM_PENDING)
            {
                /*SWS_Dcm_01412*/
                Result = DCM_E_PENDING;
            }
            else/*Result == E_OK*/
            {
                /*Continue*/
            }
        }

        /*Get DTC status available mask.*/
        if(Result == E_OK)
        {
            /*SWS_Dcm_00700*//*SWS_Dcm_01160*//*SWS_Dcm_00007*/
            if(DCM_REQ_SUBSERVICE != DCM_READ_DTC_12)
            {
                Result = Dem_GetDTCStatusAvailabilityMask(DemClient, &AvailableMask, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
            }
            else/*(DCM_REQ_SUBSERVICE == DCM_READ_DTC_12)*/
            {
                Result = Dem_GetDTCStatusAvailabilityMask(DemClient, &AvailableMask, DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY);
            }

            if(Result == E_OK)
            {
                /*SWS_Dcm_00376*/
                pMsgContext->resData[DCM_INDEX_2] = AvailableMask;
                /*Get DTC Format*/
                pMsgContext->resData[DCM_INDEX_3] = Dem_GetTranslationType(DemClient);
                pMsgContext->resData[DCM_INDEX_4] = (uint8)(DTCCounter >> DCM_SHIFT_8);
                pMsgContext->resData[DCM_INDEX_5] = (uint8)(DTCCounter);
                /*The reponse data length is always 6.*/
                pMsgContext->resDataLen = DCM_LENGTH_6_BYTE;
            }
            else
            {
                /*SWS_Dcm_00271 AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
        }
    }
    return Result;
}
/*PRQA S 4700 --*/
#endif

#if(DCM_UDS_19_02_0A_13_15_17_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_19_02_0A_13_15_17_Processor
*
* Description: This function is used to implement the processing logic of the 02,
*              0A, 13, 15 and 17 subservices of the 19 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_02_0A_13_15_17_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 DemClient = DCM_CFG_PCL_DEM_CLIENT(DCM_ACTIVE_PCL_ID);
    Dem_DTCOriginType UserMemory;
    Dem_UdsStatusByteType AvailableMask;
    uint8 GetDtcStatus;
    Dcm_MsgType DestPtr;
    Dcm_MsgLenType AddrOffset;
    uint32 GetDtc;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_DTC_COUNTER = (uint16)0;
        /*Set DTCStatus to a non-zero value.*/
        DCM_DTC_STATUS = (uint8)0x01;

        /*SWS_Dcm_00378*/
        if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_0A)
        {
            Result = Dem_SetDTCFilter(DemClient, (uint8)0, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY, \
                                    FALSE, (Dem_DTCSeverityType)0, FALSE);
        }
        else if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_15)
        {
            Result = Dem_SetDTCFilter(DemClient, (uint8)0, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PERMANENT_MEMORY, \
                                    FALSE, (Dem_DTCSeverityType)0, FALSE);
        }
        else
        {
            /*Subservice 0A and 15 doesn't have the DTCStatusMask data*/
            DCM_DTC_STATUS = pMsgContext->reqData[DCM_INDEX_2];

            if(DCM_DTC_STATUS != (uint8)0x00)
            {
                if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_02)
                {
                    Result = Dem_SetDTCFilter(DemClient, DCM_DTC_STATUS, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY, \
                                            FALSE, (Dem_DTCSeverityType)0, FALSE);
                }
                else if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_13)
                {
                    Result = Dem_SetDTCFilter(DemClient, DCM_DTC_STATUS, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY, \
                                            FALSE, (Dem_DTCSeverityType)0, FALSE);
                }
                else/*(DCM_REQ_SUBSERVICE == DCM_READ_DTC_17)*/
                {
                    /*MemorySelection from request + 0x0100*/
                    UserMemory = (Dem_DTCOriginType)DCM_USER_MEMORY_OFFSET + (Dem_DTCOriginType)(pMsgContext->reqData[DCM_INDEX_3]);
                    
                    Result = Dem_SetDTCFilter(DemClient, DCM_DTC_STATUS, DEM_DTC_FORMAT_UDS, UserMemory, \
                                            FALSE, (Dem_DTCSeverityType)0, FALSE);
                }
            }
        }

        if(Result == E_NOT_OK)
        {
            /*SWS_Dcm_01043*//*SWS_Dcm_01255*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }

    /*Get all the filtered DTC.*/
    if(OpStatus != DCM_CANCEL)
    {
        if((Result == E_OK) && (DCM_DTC_STATUS != (uint8)0x00))
        {
            if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_17)
            {
                DestPtr = &(pMsgContext->resData[DCM_INDEX_4]);
            }
            else
            {
                DestPtr = &(pMsgContext->resData[DCM_INDEX_3]);
            }

            /*The filtered DTCS are read one by one.*/
            do
            {
                /*SWS_Dcm_00378*/
                Result = Dem_GetNextFilteredDTC(DemClient, &GetDtc, &GetDtcStatus);
                /*SWS_Dcm_00828*/
                if(Result == E_OK)
                {
                    AddrOffset = (DCM_DTC_COUNTER * DCM_LENGTH_4_BYTE);
                    /*SWS_Dcm_00377*/
                    DestPtr[AddrOffset] = (uint8)(GetDtc >> DCM_SHIFT_16);
                    DestPtr[DCM_INDEX_1 + AddrOffset] = (uint8)(GetDtc >> (uint32)DCM_SHIFT_8);
                    DestPtr[DCM_INDEX_2 + AddrOffset] = (uint8)(GetDtc);
                    DestPtr[DCM_INDEX_3 + AddrOffset] = GetDtcStatus;

                    DCM_DTC_COUNTER++;
                }
                else if(Result == DEM_PENDING)
                {
                    /*SWS_Dcm_01412*/
                    Result = DCM_E_PENDING;
                }
                else if(Result == DEM_NO_SUCH_ELEMENT)
                {
                    /*GetNextFilteredDTC is over*/
                }
                else/*(Result == E_NOT_OK)*/
                {
                    /*SWS_Dcm_00271 AUTOSAR specification is not defined.*/
                    *pErrorCode = DCM_E_GENERALREJECT;
                }

            } while(Result == E_OK);
        }

        /*Get DTC status available mask.*/
        if((Result == E_OK) || (Result == DEM_NO_SUCH_ELEMENT))
        {
            /*SWS_Dcm_00700*//*SWS_Dcm_00007*/
            if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_13)
            {
                Result = Dem_GetDTCStatusAvailabilityMask(DemClient, &AvailableMask, DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY);
            }
            else if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_15)
            {
                Result = Dem_GetDTCStatusAvailabilityMask(DemClient, &AvailableMask, DEM_DTC_ORIGIN_PERMANENT_MEMORY);
            }
            else if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_17)
            {
                /*MemorySelection from request + 0x0100*/
                UserMemory = (Dem_DTCOriginType)DCM_USER_MEMORY_OFFSET + (Dem_DTCOriginType)(pMsgContext->reqData[DCM_INDEX_3]);

                Result = Dem_GetDTCStatusAvailabilityMask(DemClient, &AvailableMask, UserMemory);
            }
            else/*(DCM_REQ_SUBSERVICE == DCM_READ_DTC_02/0A)*/
            {
                Result = Dem_GetDTCStatusAvailabilityMask(DemClient, &AvailableMask, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
            }

            /*Integrated response data*/
            if(Result == E_OK)
            {
                /*SWS_Dcm_01229*//*SWS_Dcm_01230*//*SWS_Dcm_00008*/
                if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_17)
                {
                    /*MemorySelection*/
                    pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_3];
                    /*DTC status available mask*/
                    pMsgContext->resData[DCM_INDEX_3] = AvailableMask;
                    /*Total response data length*/
                    pMsgContext->resDataLen = (DCM_LENGTH_4_BYTE + (DCM_DTC_COUNTER * DCM_LENGTH_4_BYTE));
                }
                else
                {
                    pMsgContext->resData[DCM_INDEX_2] = AvailableMask;
                    pMsgContext->resDataLen = (DCM_LENGTH_3_BYTE + (DCM_DTC_COUNTER * DCM_LENGTH_4_BYTE));
                }
            }
            else
            {
                /*SWS_Dcm_00271 AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
        }
    }
    return Result;
}
/*PRQA S 4700 --*/
#endif

#if(DCM_UDS_19_06_19_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_19_06_19_Processor
*
* Description: This function is used to implement the processing logic of the 06
*              and 19 subservices of the 19 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_06_19_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 DemClient = DCM_CFG_PCL_DEM_CLIENT(DCM_ACTIVE_PCL_ID);
    uint8 *DestPtr = NULL_PTR;
    Dem_DTCOriginType UserMemory;
    uint8 GetStatus;
    uint16 BuffSize;
    uint32 RecordSize;

    if(OpStatus == DCM_INITIAL)
    {
        /*Get requested DTC and extended data record*/
        DCM_DTC_DTC = DcmMakeDTC(pMsgContext->reqData[DCM_INDEX_2], pMsgContext->reqData[DCM_INDEX_3], pMsgContext->reqData[DCM_INDEX_4]);
        DCM_DTC_RECORDNUM = pMsgContext->reqData[DCM_INDEX_5];

        /*Set the execution step to 1*/
        DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_ONE;
    }

    if(OpStatus != DCM_CANCEL)
    {
        /*Step 1: Select the requested DTC*/
        if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_ONE)
        {
            /*SWS_Dcm_00295*/
            if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_06)
            {
                Result = Dem_SelectDTC(DemClient, DCM_DTC_DTC, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
            }
            else
            {
                /*MemorySelection from request + 0x0100*/
                UserMemory = (Dem_DTCOriginType)DCM_USER_MEMORY_OFFSET + (Dem_DTCOriginType)(pMsgContext->reqData[DCM_INDEX_6]);
                Result = Dem_SelectDTC(DemClient, DCM_DTC_DTC, DEM_DTC_FORMAT_UDS, UserMemory);
            }
            /*Dem_SelectDTC has only two return values: E_OK and DEM_BUSY.*/
            if(Result == DEM_BUSY)
            {
                Result = DCM_E_PENDING;
            }
            else
            {
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_TWO;
            }
        }

        /*Step 2: Retrieve the status of the selected DTC.*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_TWO))
        {
            /*SWS_Dcm_00295*/
            Result = Dem_GetStatusOfDTC(DemClient, &GetStatus);

            if(Result == E_NOT_OK)
            {
                /*SWS_Dcm_00271 AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
            else if((Result == DEM_WRONG_DTC) || (Result == DEM_WRONG_DTCORIGIN) || (Result == DEM_NO_SUCH_ELEMENT))
            {
                /*SWS_Dcm_01250*//*SWS_Dcm_01409:This requirement does not apply to the subservices because of ISO 14229(2020).*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else if((Result == DEM_PENDING) || (Result == DEM_BUSY))
            {
                Result = DCM_E_PENDING;
            }
            else/*Result = E_OK*/
            {
                if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_06)
                {
                    /*DTC in the request message is assigned to the buffer of the sent message to prevent overwriting.*/
                    pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
                    pMsgContext->resData[DCM_INDEX_3] = pMsgContext->reqData[DCM_INDEX_3];
                    pMsgContext->resData[DCM_INDEX_4] = pMsgContext->reqData[DCM_INDEX_4];
                    /*Put the DTC status in the send buffer.*/
                    pMsgContext->resData[DCM_INDEX_5] = GetStatus;
                    /*Set the response data length*/
                    pMsgContext->resDataLen = DCM_LENGTH_6_BYTE;
                }
                else
                {
                    /*DTC*/
                    pMsgContext->resData[DCM_INDEX_5] = pMsgContext->reqData[DCM_INDEX_4];
                    pMsgContext->resData[DCM_INDEX_4] = pMsgContext->reqData[DCM_INDEX_3];
                    pMsgContext->resData[DCM_INDEX_3] = pMsgContext->reqData[DCM_INDEX_2];
                    /*MemorySelection*/
                    pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_6];
                    /*DTC status*/
                    pMsgContext->resData[DCM_INDEX_6] = GetStatus;
                    /*Response data length*/
                    pMsgContext->resDataLen = DCM_LENGTH_7_BYTE;
                }
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_THREE;
            }
        }

        /*Step 3: To ensure consistent event related data during the reading sequence, the Dcm module shall
        lock the update of event related data before reading freeze frames or extended data records.*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_THREE))
        {
            /*SWS_Dcm_00371*/
            Result = Dem_DisableDTCRecordUpdate(DemClient);

            if(Result == E_NOT_OK)
            {
                /*SWS_Dcm_00271 AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
            else if((Result == DEM_PENDING) || (Result == DEM_BUSY))
            {
                /*SWS_Dcm_00702*/
                Result = DCM_E_PENDING;
            }
            else if((Result == DEM_WRONG_DTC) || (Result == DEM_WRONG_DTCORIGIN))
            {
                /*SWS_Dcm_01212*//*SWS_Dcm_01213*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else/*(Result == E_OK)*/
            {
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_FOUR;
            }
        }

        /*Step 4: Select the requested extended data record number*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_FOUR))
        {
            /*SWS_Dcm_00382*/
            Result = Dem_SelectExtendedDataRecord(DemClient, DCM_DTC_RECORDNUM);

            if((Result == DEM_PENDING) || (Result == DEM_BUSY))
            {
                Result = DCM_E_PENDING;
            }
            else if((Result == DEM_WRONG_DTC) || (Result == DEM_WRONG_DTCORIGIN))
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else/*(Result == E_OK)*/
            {
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_FIVE;
            }
        }

        /*Step 5: Obtain the size of the extended data record*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_FIVE))
        {
            /*SWS_Dcm_00382*/
            Result = Dem_GetSizeOfExtendedDataRecordSelection(DemClient, &RecordSize);

            if(Result == E_NOT_OK)
            {
                /*SWS_Dcm_00271 AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
            else if(Result == DEM_PENDING)
            {
                /*SWS_Dcm_01412*/
                Result = DCM_E_PENDING;
            }
            else if((Result == DEM_WRONG_DTC) || (Result == DEM_WRONG_DTCORIGIN) || (Result == DEM_NO_SUCH_ELEMENT))
            {
                /*SWS_Dcm_01242*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else/*(Result == E_OK)*/
            {
                /*6 is 1(0x19)+1(06)+3(DTC)+1(DTCStatus)*/
                /*7 is 1(0x19)+1(19)+1(MemorySelection)+3(DTC)+1(DTCStatus)*/
                if(RecordSize > ((pMsgContext->resMaxDataLen) - (pMsgContext->resDataLen)))
                {
                    *pErrorCode = DCM_E_RESPONSETOOLONG;
                    Result = E_NOT_OK;
                }
                else if(RecordSize == (uint32)0)
                {
                    /*SWS_Dcm_00841*//*No need to read extended data*/
                    /*Next step*/
                    DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_OVER;
                }
                else
                {
                    /*Next step*/
                    DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_SIX;
                }
            }
        }

        /*Step 6: Read the extended data*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_SIX))
        {
            /*SWS_Dcm_00382*//*SWS_Dcm_00386*/
            BuffSize = (uint16)((pMsgContext->resMaxDataLen) - (pMsgContext->resDataLen));
            DestPtr = &(pMsgContext->resData[(pMsgContext->resDataLen)]);

            do
            {
                Result = Dem_GetNextExtendedDataRecord(DemClient, DestPtr, &BuffSize);

                if(Result == E_NOT_OK)
                {
                    /*SWS_Dcm_00271 AUTOSAR specification is not defined.*/
                    *pErrorCode = DCM_E_GENERALREJECT;
                }
                else if(Result == DEM_PENDING)
                {
                    Result = DCM_E_PENDING;
                }
                else if((Result == DEM_WRONG_DTC) || (Result == DEM_WRONG_DTCORIGIN))
                {
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
                else if(Result == DEM_BUFFER_TOO_SMALL)
                {
                    *pErrorCode = DCM_E_RESPONSETOOLONG;
                    Result = E_NOT_OK;
                }
                else if(Result == DEM_NO_SUCH_ELEMENT)
                {
                    /*The process of reading data ends.*/
                }
                else/*(Result == E_OK)*/
                {
                    pMsgContext->resDataLen += BuffSize;
                    BuffSize = (uint16)((pMsgContext->resMaxDataLen) - (pMsgContext->resDataLen));
                    DestPtr = &(pMsgContext->resData[(pMsgContext->resDataLen)]);
                }
            } while(Result == E_OK);

            if(Result == DEM_NO_SUCH_ELEMENT)
            {
                /*The process of reading data ends.*/
                Result = E_OK;
            }
        }

        /*EnableDTCRecordUpdate and return*/
        if((Result != DCM_E_PENDING) && (DCM_CURRENT_EXE_STEP > DCM_EXE_STEP_THREE))
        {
            (void)Dem_EnableDTCRecordUpdate(DemClient);
        }
    }

    return Result;
}
/*PRQA S 4700 --*/
#endif

#if(DCM_UDS_19_08_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_19_08_Processor
*
* Description: This function is used to implement the processing logic of the 08
*              subservices of the 19 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_08_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 DemClient = DCM_CFG_PCL_DEM_CLIENT(DCM_ACTIVE_PCL_ID);
    Dem_UdsStatusByteType AvailableMask;
    uint8 GetStatus;
    Dem_DTCSeverityType GetSeverity;
    uint8 GetFunc;
    uint32 GetDtc;
    Dcm_MsgType DestPtr;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_DTC_COUNTER = (uint16)0;
        /*Get the requested DTCStatusMask and DTCSeverityMask.*/
        DCM_DTC_SEVERITY = pMsgContext->reqData[DCM_INDEX_2];
        DCM_DTC_STATUS = pMsgContext->reqData[DCM_INDEX_3];
        
        /*Set filter*//*SWS_Dcm_00700*//*SWS_Dcm_01160*/
        if((DCM_DTC_STATUS != (uint8)0x00) && (DCM_DTC_SEVERITY != (Dem_DTCSeverityType)0x00))
        {
            /*SWS_Dcm_00835*//*SWS_Dcm_00380*/
            Result = Dem_SetDTCFilter(DemClient, DCM_DTC_STATUS, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY, \
                                    TRUE, DCM_DTC_SEVERITY, FALSE);
            if(Result == E_NOT_OK)
            {
                /*SWS_Dcm_01043*//*SWS_Dcm_01255*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
        }
    }

    if(OpStatus != DCM_CANCEL)
    {
        /*When the DTC status and severity mask in the request message are not 0, the DTCS that pass filtering will be read.*/
        if((Result == E_OK) && (DCM_DTC_STATUS != (uint8)0x00) && (DCM_DTC_SEVERITY != (Dem_DTCSeverityType)0x00))
        {
            /*The filtered DTCS are read one by one.*/
            do
            {
                /*SWS_Dcm_00380*/
                Result = Dem_GetNextFilteredDTCAndSeverity(DemClient, &GetDtc, &GetStatus, &GetSeverity, &GetFunc);

                if(Result == E_OK)
                {
                    DestPtr = &(pMsgContext->resData[DCM_INDEX_3 + (DCM_DTC_COUNTER * DCM_LENGTH_6_BYTE)]);
                    /*SWS_Dcm_00379*/
                    DestPtr[DCM_INDEX_0] = (uint8)GetSeverity;
                    DestPtr[DCM_INDEX_1] = GetFunc;
                    DestPtr[DCM_INDEX_2] = (uint8)(GetDtc >> DCM_SHIFT_16);
                    DestPtr[DCM_INDEX_3] = (uint8)(GetDtc >> DCM_SHIFT_8);
                    DestPtr[DCM_INDEX_4] = (uint8)(GetDtc);
                    DestPtr[DCM_INDEX_5] = GetStatus;

                    DCM_DTC_COUNTER++;
                }
                else if(Result == DEM_PENDING)
                {
                    Result = DCM_E_PENDING;
                }
                else if(Result == DEM_NO_SUCH_ELEMENT)
                {
                    /*SWS_Dcm_01234, SWS_Dcm_01235 GetNextFilteredDTCAndSeverity is over*/
                }
                else/*(Result == E_NOT_OK)*/
                {
                    /*AUTOSAR specification is not defined.*/
                    *pErrorCode = DCM_E_GENERALREJECT;
                }
            } while(Result == E_OK);
        }

        /*Get DTC status available mask.*/
        if((Result == E_OK) || (Result == DEM_NO_SUCH_ELEMENT))
        {
            /*SWS_Dcm_00700*//*SWS_Dcm_01160*//*SWS_Dcm_00007*/
            Result = Dem_GetDTCStatusAvailabilityMask(DemClient, &AvailableMask, DEM_DTC_ORIGIN_PRIMARY_MEMORY);

            /*Integrated response data*/
            if(Result == E_OK)
            {
                pMsgContext->resData[DCM_INDEX_2] = AvailableMask;
                pMsgContext->resDataLen = (DCM_LENGTH_3_BYTE + (DCM_DTC_COUNTER * DCM_LENGTH_6_BYTE));
            }
            else
            {
                /*AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
        }
    }
    return Result;
}
#endif

#if(DCM_UDS_19_09_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_19_09_Processor
*
* Description: This function is used to implement the processing logic of the 09
*              subservices of the 19 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_09_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 DemClient = DCM_CFG_PCL_DEM_CLIENT(DCM_ACTIVE_PCL_ID);
    Dem_UdsStatusByteType AvailableMask;
    uint8 GetStatus;
    Dem_DTCSeverityType GetSeverity;
    uint8 GetFunc;

    if(OpStatus == DCM_INITIAL)
    {
        /*Get the requested DTC.*/
        DCM_DTC_DTC = DcmMakeDTC(pMsgContext->reqData[DCM_INDEX_2],  pMsgContext->reqData[DCM_INDEX_3], pMsgContext->reqData[DCM_INDEX_4]);

        /*Set the execution step to 1*/
        DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_ONE;
    }

    if(OpStatus != DCM_CANCEL)
    {
        /*Step 1: Select the requested DTC*/
        if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_ONE)
        {
            /*SWS_Dcm_01402*/
            Result = Dem_SelectDTC(DemClient, DCM_DTC_DTC, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
            /*Dem_SelectDTC has only two return values: E_OK and DEM_BUSY.*/
            if(Result == DEM_BUSY)
            {
                Result = DCM_E_PENDING;
            }
            else
            {
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_TWO;
            }
        }

        /*Step 2: Retrieve the status of the selected DTC.*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_TWO))
        {
            /*SWS_Dcm_01405*/
            Result = Dem_GetStatusOfDTC(DemClient, &GetStatus);

            if(Result == E_NOT_OK)
            {
                /*AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
            else if((Result == DEM_WRONG_DTC) || (Result == DEM_WRONG_DTCORIGIN))
            {
                /*SWS_Dcm_01406*//*SWS_Dcm_01250*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else if((Result == DEM_PENDING) || (Result == DEM_BUSY))
            {
                Result = DCM_E_PENDING;
            }
            else if(Result == DEM_NO_SUCH_ELEMENT)
            {
                /*SWS_Dcm_01409*/
                Result = E_OK;
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_OVER;
            }
            else/*Result = E_OK*/
            {
                pMsgContext->resData[DCM_INDEX_8] = GetStatus;
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_THREE;
            }
        }

        /*Step 3: Retrieve the DTCSeverityMask of the selected DTC.*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_THREE))
        {
            /*SWS_Dcm_01403*/
            Result = Dem_GetSeverityOfDTC(&GetSeverity, DemClient);

            if(Result == E_NOT_OK)
            {
                /*AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
            else if((Result == DEM_WRONG_DTC) || (Result == DEM_WRONG_DTCORIGIN))
            {
                /*SWS_Dcm_01240*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
            else if((Result == DEM_PENDING) || (Result == DEM_BUSY))
            {
                Result = DCM_E_PENDING;
            }
            else/*Result = E_OK*/
            {
                pMsgContext->resData[DCM_INDEX_3] = (uint8)GetSeverity;
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_FOUR;
            }
        }

        /*Step 4: Retrieve the DTCFunctionalUnit of the selected DTC.*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_FOUR))
        {
            /*SWS_Dcm_01404*/
            Result = Dem_GetFunctionalUnitOfDTC(DemClient, &GetFunc);

            if(Result == E_NOT_OK)
            {
                /*AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
            else if((Result == DEM_WRONG_DTC) || (Result == DEM_WRONG_DTCORIGIN))
            {
                /*SWS_Dcm_01226*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else if((Result == DEM_PENDING) || (Result == DEM_BUSY))
            {
                Result = DCM_E_PENDING;
            }
            else/*Result = E_OK*/
            {
                pMsgContext->resData[DCM_INDEX_4] = GetFunc;
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_FIVE;
            }
        }

        /*Step 5: Get DTC status available mask.*/
        if(Result == E_OK)
        {
            /*SWS_Dcm_00007*/
            Result = Dem_GetDTCStatusAvailabilityMask(DemClient, &AvailableMask, DEM_DTC_ORIGIN_PRIMARY_MEMORY);

            /*Integrated response data*/
            if(Result == E_OK)
            {
                pMsgContext->resData[DCM_INDEX_2] = AvailableMask;

                /*DCM_CURRENT_EXE_STEP is OVER means the return value of Dem_GetStatusOfDTC is DEM_NO_SUCH_ELEMENT.*/
                if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_OVER)
                {
                    /*SWS_Dcm_01409*//*Dcm shall send a positive response only for service and subservice.*/
                    pMsgContext->resDataLen = DCM_LENGTH_3_BYTE;
                }
                else
                {
                    /*Set the requested DTC to send data.*/
                    pMsgContext->resData[DCM_INDEX_5] = (uint8)(DCM_DTC_DTC >> DCM_SHIFT_16);
                    pMsgContext->resData[DCM_INDEX_6] = (uint8)(DCM_DTC_DTC >> DCM_SHIFT_8);
                    pMsgContext->resData[DCM_INDEX_7] = (uint8)(DCM_DTC_DTC);
                    pMsgContext->resDataLen = DCM_LENGTH_9_BYTE;
                }
            }
            else
            {
                /*AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
        }
    }
    return Result;
}
#endif

#if(DCM_UDS_19_03_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_19_03_Processor
*
* Description: This function is used to implement the processing logic of the 03
*              subservices of the 19 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_03_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 DemClient = DCM_CFG_PCL_DEM_CLIENT(DCM_ACTIVE_PCL_ID);
    uint8 RecordNumber;
    uint16 NumOfFilteredRecords;
    uint32 Dtc;
    Dcm_MsgType DestPtr;

    if(OpStatus == DCM_INITIAL)
    {
        /*Reset the execution step information*/
        DCM_CURRENT_EXE_STEP = DCM_DATA_CLEAR;
        /*Reset counter*/
        DCM_DTC_COUNTER = (uint16)0;
        /*SWS_Dcm_00298*//*SWS_Dcm_00836*/
        Result = Dem_SetFreezeFrameRecordFilter(DemClient, DEM_DTC_FORMAT_UDS);
        /*The function has only two return values: E_OK and E_NOT_OK.*/
        if(Result == E_NOT_OK)
        {
            /*SWS_Dcm_01256*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else
        {
            /*Next step*/
            DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_ONE;
        }
    }

    if(OpStatus != DCM_CANCEL)
    {
        /*Setp 1: Get number of freeze frame records*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_ONE))
        {
            /*SWS_Dcm_00298*/
            Result = Dem_GetNumberOfFreezeFrameRecords(DemClient, &NumOfFilteredRecords);
            /*The function has only two return values: E_OK and DEM_PENDING.*/
            if(Result == DEM_PENDING)
            {
                Result = DCM_E_PENDING;
            }
            else
            {
                if((NumOfFilteredRecords * DCM_LENGTH_4_BYTE) > (pMsgContext->resMaxDataLen - DCM_LENGTH_2_BYTE))
                {
                    *pErrorCode = DCM_E_RESPONSETOOLONG;
                    Result = E_NOT_OK;
                }
                else
                {
                    /*Next step*/
                    DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_TWO;
                }
            }
        }

        /*Step 2: Obtain the consecutive DTCs and DTCSnapshotRecordNumbers*/
        if(Result == E_OK)
        {
            /*SWS_Dcm_00299*/
            do
            {
                Result = Dem_GetNextFilteredRecord(DemClient, &Dtc, &RecordNumber);

                if(Result == E_OK)
                {
                    DestPtr = &(pMsgContext->resData[DCM_INDEX_2 + (DCM_DTC_COUNTER * DCM_LENGTH_4_BYTE)]);
                    /*SWS_Dcm_00300*/
                    DestPtr[DCM_INDEX_0] = (uint8)(Dtc >> DCM_SHIFT_16);
                    DestPtr[DCM_INDEX_1] = (uint8)(Dtc >> (uint32)DCM_SHIFT_8);
                    DestPtr[DCM_INDEX_2] = (uint8)(Dtc);
                    DestPtr[DCM_INDEX_3] = RecordNumber;
                    DCM_DTC_COUNTER++;
                }
                else if(Result == DEM_PENDING)
                {
                    /*SWS_Dcm_01231*/
                    Result = DCM_E_PENDING;
                }
                else/*Result == DEM_NO_SUCH_ELEMENT*/
                {
                    /*The process of reading data ends.*/
                }
            } while(Result == E_OK);
        }

        if(Result == DEM_NO_SUCH_ELEMENT)
        {
            /*SWS_Dcm_01237*//*SWS_Dcm_01238*/
            pMsgContext->resDataLen = (DCM_LENGTH_2_BYTE + (DCM_DTC_COUNTER * DCM_LENGTH_4_BYTE));
            Result = E_OK;
        }
    }
    return Result;
}
#endif

#if(DCM_UDS_19_04_18_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_19_04_18_Processor
*
* Description: This function is used to implement the processing logic of the 04
*              and 18 subservices of the 19 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_04_18_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 DemClient = DCM_CFG_PCL_DEM_CLIENT(DCM_ACTIVE_PCL_ID);
    uint8 *DestPtr = NULL_PTR;
    Dem_DTCOriginType UserMemory;
    uint8 GetStatus;
    uint16 BuffSize;
    uint32 RecordSize;

    if(OpStatus == DCM_INITIAL)
    {
        /*Get requested DTC and snapshot record number*/
        DCM_DTC_DTC = DcmMakeDTC(pMsgContext->reqData[DCM_INDEX_2], pMsgContext->reqData[DCM_INDEX_3], pMsgContext->reqData[DCM_INDEX_4]);
        DCM_DTC_RECORDNUM = pMsgContext->reqData[DCM_INDEX_5];

        /*Set the execution step to 1*/
        DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_ONE;
    }

    if(OpStatus != DCM_CANCEL)
    {
        /*Step 1: Select the requested DTC*/
        if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_ONE)
        {
            /*SWS_Dcm_00383*//*SWS_Dcm_01147*/
            if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_04)
            {
                Result = Dem_SelectDTC(DemClient, DCM_DTC_DTC, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
            }
            else
            {
                /*MemorySelection from request + 0x0100*/
                UserMemory = (Dem_DTCOriginType)DCM_USER_MEMORY_OFFSET + (Dem_DTCOriginType)(pMsgContext->reqData[DCM_INDEX_6]);
                Result = Dem_SelectDTC(DemClient, DCM_DTC_DTC, DEM_DTC_FORMAT_UDS, UserMemory);
            }
            /*Dem_SelectDTC has only two return values: E_OK and DEM_BUSY.*/
            if(Result == DEM_BUSY)
            {
                Result = DCM_E_PENDING;
            }
            else
            {
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_TWO;
            }
        }

        /*Step 2: Retrieve the status of the selected DTC.*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_TWO))
        {
            Result = Dem_GetStatusOfDTC(DemClient, &GetStatus);

            if(Result == E_NOT_OK)
            {
                /*AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
            else if((Result == DEM_WRONG_DTC) || (Result == DEM_WRONG_DTCORIGIN) || (Result == DEM_NO_SUCH_ELEMENT))
            {
                /*SWS_Dcm_01250*//*SWS_Dcm_01409:This requirement does not apply to the two subservices because of ISO 14229(2020).*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else if((Result == DEM_PENDING) || (Result == DEM_BUSY))
            {
                Result = DCM_E_PENDING;
            }
            else/*Result = E_OK*/
            {
                if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_04)
                {
                    /*DTC in the request message is assigned to the buffer of the sent message to prevent overwriting.*/
                    pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
                    pMsgContext->resData[DCM_INDEX_3] = pMsgContext->reqData[DCM_INDEX_3];
                    pMsgContext->resData[DCM_INDEX_4] = pMsgContext->reqData[DCM_INDEX_4];
                    /*Put the DTC status in the send buffer.*/
                    pMsgContext->resData[DCM_INDEX_5] = GetStatus;
                    /*Set the response data length*/
                    pMsgContext->resDataLen = DCM_LENGTH_6_BYTE;
                }
                else
                {
                    /*DTC*/
                    pMsgContext->resData[DCM_INDEX_5] = pMsgContext->reqData[DCM_INDEX_4];
                    pMsgContext->resData[DCM_INDEX_4] = pMsgContext->reqData[DCM_INDEX_3];
                    pMsgContext->resData[DCM_INDEX_3] = pMsgContext->reqData[DCM_INDEX_2];
                    /*MemorySelection*/
                    pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_6];
                    /*DTC status*/
                    pMsgContext->resData[DCM_INDEX_6] = GetStatus;
                    /*Response data length*/
                    pMsgContext->resDataLen = DCM_LENGTH_7_BYTE;
                }
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_THREE;
            }
        }

        /*Step 3: To ensure consistent event related data during the reading sequence, the Dcm module shall
        lock the update of event related data before reading freeze frames or extended data records.*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_THREE))
        {
            /*SWS_Dcm_00371*/
            Result = Dem_DisableDTCRecordUpdate(DemClient);

            if(Result == E_NOT_OK)
            {
                /*AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
            else if((Result == DEM_PENDING) || (Result == DEM_BUSY))
            {
                /*SWS_Dcm_00702*/
                Result = DCM_E_PENDING;
            }
            else if((Result == DEM_WRONG_DTC) || (Result == DEM_WRONG_DTCORIGIN))
            {
                /*SWS_Dcm_01212*//*SWS_Dcm_01213*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else/*(Result == E_OK)*/
            {
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_FOUR;
            }
        }

        /*Step 4: Select the requested snapshot record number*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_FOUR))
        {
            /*SWS_Dcm_01430*/
            Result = Dem_SelectFreezeFrameData(DemClient, DCM_DTC_RECORDNUM);

            if((Result == DEM_PENDING) || (Result == DEM_BUSY))
            {
                Result = DCM_E_PENDING;
            }
            else if((Result == DEM_WRONG_DTC) || (Result == DEM_WRONG_DTCORIGIN))
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else/*(Result == E_OK)*/
            {
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_FIVE;
            }
        }

        /*Step 5: Obtain the size of the snapshot data*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_FIVE))
        {
            /*SWS_Dcm_00441*/
            Result = Dem_GetSizeOfFreezeFrameSelection(DemClient, &RecordSize);

            if(Result == E_NOT_OK)
            {
                /*AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
            else if(Result == DEM_PENDING)
            {
                Result = DCM_E_PENDING;
            }
            else if((Result == DEM_WRONG_DTC) || (Result == DEM_WRONG_DTCORIGIN) || (Result == DEM_NO_SUCH_ELEMENT))
            {
                /*SWS_Dcm_01246*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else/*(Result == E_OK)*/
            {
                /*6 is 1(0x19)+1(06)+3(DTC)+1(DTCStatus)*/
                /*7 is 1(0x19)+1(19)+1(MemorySelection)+3(DTC)+1(DTCStatus)*/
                if(RecordSize > ((pMsgContext->resMaxDataLen) - (pMsgContext->resDataLen)))
                {
                    *pErrorCode = DCM_E_RESPONSETOOLONG;
                    Result = E_NOT_OK;
                }
                else if(RecordSize == (uint32)0)
                {
                    /*SWS_Dcm_01224*//*No need to read snapshot data*/
                    /*Next step*/
                    DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_OVER;
                }
                else
                {
                    /*Next step*/
                    DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_SIX;
                }
            }
        }

        /*Step 6: Read the extended data*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_SIX))
        {
            /*SWS_Dcm_00302*//*SWS_Dcm_00384*/
            BuffSize = (uint16)((pMsgContext->resMaxDataLen) - (pMsgContext->resDataLen));
            DestPtr = &(pMsgContext->resData[(pMsgContext->resDataLen)]);

            do
            {
                Result = Dem_GetNextFreezeFrameData(DemClient, DestPtr, &BuffSize);

                if(Result == E_NOT_OK)
                {
                    /*AUTOSAR specification is not defined.*/
                    *pErrorCode = DCM_E_GENERALREJECT;
                }
                else if(Result == DEM_PENDING)
                {
                    Result = DCM_E_PENDING;
                }
                else if((Result == DEM_WRONG_DTC) || (Result == DEM_WRONG_DTCORIGIN))
                {
                    /*SWS_Dcm_01220*/
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
                else if(Result == DEM_BUFFER_TOO_SMALL)
                {
                    *pErrorCode = DCM_E_RESPONSETOOLONG;
                    Result = E_NOT_OK;
                }
                else if(Result == DEM_NO_SUCH_ELEMENT)
                {
                    /*The process of reading data ends.*/
                }
                else/*(Result == E_OK)*/
                {
                    pMsgContext->resDataLen += BuffSize;
                    BuffSize = (uint16)((pMsgContext->resMaxDataLen) - (pMsgContext->resDataLen));
                    DestPtr = &(pMsgContext->resData[(pMsgContext->resDataLen)]);
                }
            } while(Result == E_OK);

            if(Result == DEM_NO_SUCH_ELEMENT)
            {
                /*The process of reading data ends.*/
                Result = E_OK;
            }
        }

        /*EnableDTCRecordUpdate and return*/
        if((Result != DCM_E_PENDING) && (DCM_CURRENT_EXE_STEP > DCM_EXE_STEP_THREE))
        {
            (void)Dem_EnableDTCRecordUpdate(DemClient);
        }
    }
    return Result;
}
/*PRQA S 4700 --*/
#endif

#if(DCM_UDS_19_05_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_19_05_Processor
*
* Description: This function is used to implement the processing logic of the 05
*              subservices of the 19 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_05_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
#if((DCM_OBD_SUPPORT == STD_ON) && (DCM_OBD_02_ENABLED == STD_ON))
    uint8 DemClient = DCM_CFG_PCL_DEM_CLIENT(DCM_ACTIVE_PCL_ID);
    uint8 *DestPtr = NULL_PTR;
    uint8 *DestBuffer = NULL_PTR;
    uint8 PidIdx;
    uint8 DataIdx;
    uint8 DataOffset;
    uint8 GetStatus;
    uint16 BuffSize;

    if(OpStatus == DCM_INITIAL)
    {
        /*Reset the execution step information*/
        DCM_CURRENT_EXE_STEP = DCM_DATA_CLEAR;
        /*Reset counter*/
        DCM_DTC_COUNTER = (uint16)0;
        
        /*SWS_Dcm_00632*//*The requested record number should be 0x00.*/
        if((pMsgContext->reqData[DCM_INDEX_2]) != (Dcm_MsgItemType)0x00)
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else
        {
            /* SWS_Dcm_01193 */
            if(E_NOT_OK == Dem_DcmGetDTCOfOBDFreezeFrame((uint8)0x00, &DCM_DTC_DTC, DEM_DTC_FORMAT_UDS))
            {
                /*E_NOT_OK means no DTC available. Send positive response.*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_OVER;
            }
            else
            {
                /*Set the requested record number to response buffer.*/
                pMsgContext->resData[DCM_INDEX_2] = (uint8)0;
                /*Set the DTC to response buffer.*/
                pMsgContext->resData[DCM_INDEX_3] = (uint8)(DCM_DTC_DTC >> DCM_SHIFT_16);
                pMsgContext->resData[DCM_INDEX_4] = (uint8)(DCM_DTC_DTC >> DCM_SHIFT_8);
                pMsgContext->resData[DCM_INDEX_5] = (uint8)(DCM_DTC_DTC);
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_ONE;
            }
        }

    }

    if(OpStatus != DCM_CANCEL)
    {
        /*Step 1: Select the DTC*/
        if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_ONE)
        {
            /*SWS_Dcm_00389*/
            Result = Dem_SelectDTC(DemClient, DCM_DTC_DTC, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
            /*Dem_SelectDTC has only two return values: E_OK and DEM_BUSY.*/
            if(Result == DEM_BUSY)
            {
                Result = DCM_E_PENDING;
            }
            else
            {
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_TWO;
            }
        }

        /*Step 2: Retrieve the status of the selected DTC.*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_TWO))
        {
            /*SWS_Dcm_00389*/
            Result = Dem_GetStatusOfDTC(DemClient, &GetStatus);

            if(Result == E_NOT_OK)
            {
                /*AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
            else if((Result == DEM_WRONG_DTC) || (Result == DEM_WRONG_DTCORIGIN) || (Result == DEM_NO_SUCH_ELEMENT))
            {
                /*SWS_Dcm_01250*//*SWS_Dcm_01409:This requirement does not apply to the subservices because of ISO 14229(2020).*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else if((Result == DEM_PENDING) || (Result == DEM_BUSY))
            {
                Result = DCM_E_PENDING;
            }
            else/*Result = E_OK*/
            {
                /*Put the DTC status in the response buffer.*/
                pMsgContext->resData[DCM_INDEX_6] = GetStatus;
                pMsgContext->resDataLen = DCM_LENGTH_7_BYTE;
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_THREE;
            }
        }

        /*Step 3: Loop all DcmDspPid and collecting all DcmDspPidData which are configured for service 0x02.*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_THREE))
        {
            DestPtr = &(pMsgContext->resData[(pMsgContext->resDataLen)]);

            for(PidIdx = (uint8)0; PidIdx < DCM_CFG_PID_NUM; PidIdx++)
            {
                if((DCM_CFG_PID_USED(PidIdx) == TRUE) && (DCM_CFG_PID_SERVICE(PidIdx) != DCM_SERVICE_01))
                {
                    /*Set the PID to response buffer.*/
                    DestPtr[DCM_INDEX_0] = DCM_OBD_PID_MSB;
                    DestPtr[DCM_INDEX_1] = DCM_CFG_PID_ID(PidIdx);
                    /*Add the PID length to response length.*/
                    pMsgContext->resDataLen += DCM_LENGTH_2_BYTE;

                    /*Read the data value of the PID.*/
                    if(DCM_CFG_PID_ID(PidIdx) == DCM_OBD_PID_02)
                    {
                        /*SWS_Dcm_00279*//*Special PID need processed specially.*/
                        (void)Dem_DcmGetDTCOfOBDFreezeFrame((uint8)0, &DCM_DTC_DTC, DEM_DTC_FORMAT_OBD))
                        DestPtr[DCM_INDEX_2] = (uint8)(DCM_DTC_DTC >> DCM_SHIFT_8);
                        DestPtr[DCM_INDEX_3] = (uint8)DCM_DTC_DTC;
                    }
                    else
                    {
                        for(DataIdx = (uint8)0; DataIdx < DCM_CFG_PID_DATA_NUM(PidIdx); DataIdx++)
                        {
                            DataOffset = (Dcm_DspPid[DCM_CURRENT_STAB].Dcm_DspPidTable[PidIdx].DcmDspPidData[DataIdx].DcmDspPidByteOffset);
                            DestBuffer = (DestPtr + DataOffset));
                            BuffSize = (pMsgContext->resMaxDataLen - pMsgContext->resDataLen - DataOffset);
                            /* SWS_Dcm_00388 */
                            Result = Dem_DcmReadDataOfOBDFreezeFrame(DCM_CFG_PID_ID(PidIdx), DataIdx, DestBuffer, &BuffSize);
                            if(Result != E_OK)
                            {
                                /*AUTOSAR specification is not defined.*/
                                *pErrorCode = DCM_E_GENERALREJECT;
                                Result = E_NOT_OK;
                                break;
                            }
                        }
                    }

                    if(Result == E_OK)
                    {
                        /*Add the PID data length to response length.*/
                        pMsgContext->resDataLen += DCM_CFG_PID_SIZE(PidIdx);
                    }
                    else
                    {
                        /*for(PidIdx = (uint8)0; PidIdx < DCM_CFG_PID_NUM; PidIdx++)*/
                        break;
                    }
                }
            }
        }

        /*Last Step: Determines the length of the positive response*/
        if(Result == E_OK)
        {
            /*Put the requested RecordNumber into the response buffer.*/
            pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];

            if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_OVER)
            {
                pMsgContext->resDataLen = DCM_RESP_LEGTH_3_BYTEs;
            }
        }
    }
#else
    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
    Result = E_NOT_OK;
#endif
    return Result;
}
#endif
#if(DCM_UDS_19_0B_0C_0D_0E_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_19_0B_0C_0D_0E_Processor
*
* Description: This function is used to implement the processing logic of the 0B,
*              0C, 0D and 0E subservices of the 19 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_0B_0C_0D_0E_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 DemClient = DCM_CFG_PCL_DEM_CLIENT(DCM_ACTIVE_PCL_ID);
    Dem_UdsStatusByteType AvailableMask;
    uint8 GetStatus;

    if(OpStatus == DCM_INITIAL)
    {
        /*Reset the execution step information*/
        DCM_CURRENT_EXE_STEP = DCM_DATA_CLEAR;

        /*SWS_Dcm_00466*//*Obtain the DTC with Dem_GetDTCByOccurrenceTime()*/
        if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_0B)
        {
            Result = Dem_GetDTCByOccurrenceTime(DemClient, DEM_FIRST_FAILED_DTC, &DCM_DTC_DTC);
        }
        else if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_0C)
        {
            Result = Dem_GetDTCByOccurrenceTime(DemClient, DEM_FIRST_DET_CONFIRMED_DTC, &DCM_DTC_DTC);
        }
        else if(DCM_REQ_SUBSERVICE == DCM_READ_DTC_0D)
        {
            Result = Dem_GetDTCByOccurrenceTime(DemClient, DEM_MOST_RECENT_FAILED_DTC, &DCM_DTC_DTC);
        }
        else
        {
            Result = Dem_GetDTCByOccurrenceTime(DemClient, DEM_MOST_REC_DET_CONFIRMED_DTC, &DCM_DTC_DTC);
        }

        if(Result == E_OK)
        {
            /*Next Step*/
            DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_ONE;
        }
        else if(Result == DEM_NO_SUCH_ELEMENT)
        {
            /*SWS_Dcm_00766*/
            DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_OVER;
        }
        else/*Result == E_NOT_OK*/
        {
            /*AUTOSAR specification is not defined.*/
            *pErrorCode = DCM_E_GENERALREJECT;
        }
    }

    if(OpStatus != DCM_CANCEL)
    {
        /*Step 1: Select the obtained DTC*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_ONE))
        {
            Result = Dem_SelectDTC(DemClient, DCM_DTC_DTC, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY);

            /*Dem_SelectDTC has only two return values: E_OK and DEM_BUSY.*/
            if(Result == DEM_BUSY)
            {
                Result = DCM_E_PENDING;
            }
            else
            {
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_TWO;
            }
        }

        /*Step 2: Retrieve the status of the obtained DTC.*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_TWO))
        {
            /*SWS_Dcm_00393*/
            Result = Dem_GetStatusOfDTC(DemClient, &GetStatus);

            if(Result == E_NOT_OK)
            {
                /*AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
            else if((Result == DEM_WRONG_DTC) || (Result == DEM_WRONG_DTCORIGIN))
            {
                /*SWS_Dcm_01250*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else if((Result == DEM_PENDING) || (Result == DEM_BUSY))
            {
                Result = DCM_E_PENDING;
            }
            else if(Result == DEM_NO_SUCH_ELEMENT)
            {
                /*SWS_Dcm_01409*//*Send a positive response only for service and subservice.*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_OVER;
            }
            else/*Result = E_OK*/
            {
                /*Put the obtained DTC into the response buffer.*/
                pMsgContext->resData[DCM_INDEX_3] = (uint8)(DCM_DTC_DTC >> DCM_SHIFT_16);
                pMsgContext->resData[DCM_INDEX_4] = (uint8)(DCM_DTC_DTC >> DCM_SHIFT_8);
                pMsgContext->resData[DCM_INDEX_5] = (uint8)(DCM_DTC_DTC);
                /*Put the DTC status into the response buffer.*/
                pMsgContext->resData[DCM_INDEX_6] = GetStatus;
                /*Next step*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_THREE;
            }
        }

        /*Step 3: Get DTC status available mask.*/
        if((Result == E_OK) || (Result == DEM_NO_SUCH_ELEMENT))
        {
            /*SWS_Dcm_00392*//*SWS_Dcm_00007*/
            Result = Dem_GetDTCStatusAvailabilityMask(DemClient, &AvailableMask, DEM_DTC_ORIGIN_PRIMARY_MEMORY);

            /*Integrated response data*/
            if(Result == E_OK)
            {
                pMsgContext->resData[DCM_INDEX_2] = AvailableMask;

                /*Set the response data length*/
                if(DCM_CURRENT_EXE_STEP != DCM_EXE_STEP_OVER)
                {
                    pMsgContext->resDataLen = DCM_LENGTH_7_BYTE;
                }
                else
                {
                    pMsgContext->resDataLen = DCM_LENGTH_3_BYTE;
                }
            }
            else
            {
                /*AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
        }
    }
    return Result;
}
#endif

#if(DCM_UDS_19_14_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_19_14_Processor
*
* Description: This function is used to implement the processing logic of the 14
*              subservices of the 19 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_14_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 DemClient = DCM_CFG_PCL_DEM_CLIENT(DCM_ACTIVE_PCL_ID);
    sint8 GetDtcFdc;
    uint32 GetDtc;
    Dcm_MsgType DestPtr;

    if(OpStatus == DCM_INITIAL)
    {
        /*Reset counter*/
        DCM_DTC_COUNTER = (uint16)0;

        /*Set Filter*//*SWS_Dcm_00465*//*SWS_Dcm_00519*/
        Result = Dem_SetDTCFilter(DemClient, (uint8)0, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PRIMARY_MEMORY, \
                                FALSE, (Dem_DTCSeverityType)0, TRUE);
        if(Result == E_NOT_OK)
        {
            /*SWS_Dcm_01043*//*SWS_Dcm_01255*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }

    if(OpStatus != DCM_CANCEL)
    {
        /*Obtain the DTCFaultCounter of every DTCs with status "prefailed".*/
        if(Result == E_OK)
        {
            do
            {
                Result = Dem_GetNextFilteredDTCAndFDC(DemClient, &GetDtc, &GetDtcFdc);

                if(Result == E_OK)
                {
                    DestPtr = &(pMsgContext->resData[DCM_INDEX_2 + (DCM_DTC_COUNTER * DCM_LENGTH_4_BYTE)]);
                    /*SWS_Dcm_00464*/
                    DestPtr[DCM_INDEX_0] = (uint8)(GetDtc >> DCM_SHIFT_16);
                    DestPtr[DCM_INDEX_1] = (uint8)(GetDtc >> DCM_SHIFT_8);
                    DestPtr[DCM_INDEX_2] = (uint8)(GetDtc);
                    DestPtr[DCM_INDEX_3] = GetDtcFdc;
                    DCM_DTC_COUNTER++;
                }
                else if(Result == DEM_PENDING)
                {
                    Result = DCM_E_PENDING;
                }
                else if(Result == DEM_NO_SUCH_ELEMENT)
                {
                    /*The process of reading data ends.*/
                }
                else/*(Result == E_NOT_OK)*/
                {
                    /*AUTOSAR specification is not defined.*/
                    *pErrorCode = DCM_E_GENERALREJECT;
                }
            } while(Result == E_OK);
        }

        /*Set the length of positive response.*/
        if((Result == E_OK) || (Result == DEM_NO_SUCH_ELEMENT))
        {
            /*SWS_Dcm_01232*//*SWS_Dcm_01233*/
            pMsgContext->resDataLen = (DCM_LENGTH_2_BYTE + (DCM_DTC_COUNTER * DCM_LENGTH_4_BYTE));
            Result = E_OK;
        }
    }
    return Result;
}
#endif
#if(DCM_UDS_19_1A_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_19_1A_Processor
*
* Description: This function is used to implement the processing logic of the 1A
*              subservices of the 19 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_1A_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 DemClient = DCM_CFG_PCL_DEM_CLIENT(DCM_ACTIVE_PCL_ID);
    uint8 DtcStatus;
    Dem_UdsStatusByteType AvailableMask;
    uint32 Dtc;
    Dcm_MsgType DestPtr;

    if(OpStatus == DCM_INITIAL)
    {
        /*Reset counter*/
        DCM_DTC_COUNTER = (uint16)0;

        /*Get requested extended data record*/
        DCM_DTC_RECORDNUM = pMsgContext->reqData[DCM_INDEX_2];

        /*SWS_Dcm_01607*/
        Result = Dem_SetDTCFilterByExtendedDataRecordNumber(DemClient, DEM_DTC_FORMAT_UDS, DCM_DTC_RECORDNUM);
        /*The function has only two return values: E_OK and E_NOT_OK.*/
        if(Result == E_NOT_OK)
        {
            /*SWS_Dcm_01609*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
    }

    if(OpStatus != DCM_CANCEL)
    {
        /*Retrieve the DTCs that support the requested extended data record.*/
        if(Result == E_OK)
        {
            /*SWS_Dcm_01607*/
            do
            {
                Result = Dem_GetNextFilteredDTC(DemClient, &Dtc, &DtcStatus);

                if(Result == E_OK)
                {
                    DestPtr = &(pMsgContext->resData[DCM_INDEX_4 + (DCM_DTC_COUNTER * DCM_LENGTH_4_BYTE)]);

                    DestPtr[DCM_INDEX_0] = (uint8)(Dtc >> DCM_SHIFT_16);
                    DestPtr[DCM_INDEX_1] = (uint8)(Dtc >> DCM_SHIFT_8);
                    DestPtr[DCM_INDEX_2] = (uint8)(Dtc);
                    DestPtr[DCM_INDEX_3] = DtcStatus;
                    DCM_DTC_COUNTER++;
                }
                else if(Result == DEM_PENDING)
                {
                    Result = DCM_E_PENDING;
                }
                else if(Result == DEM_NO_SUCH_ELEMENT)
                {
                    /*The process of reading data ends.*/
                }
                else/*(Result == E_NOT_OK)*/
                {
                    /*AUTOSAR specification is not defined.*/
                    *pErrorCode = DCM_E_GENERALREJECT;
                }
            } while(Result == E_OK);
        }

        /*SWS_Dcm_01609*//*If no DTC supports the requested extended data record,
        the Dcm shall send a negative response with NRC 0x31*/
        if((Result == DEM_NO_SUCH_ELEMENT) && (DCM_DTC_COUNTER == (uint16)0))
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }

        /*SWS_Dcm_01608*//*If one or more DTCs support the requested extended data record,
        the Dcm shall send a positive response including all DTCs and the DTC status.*/
        if((Result == E_OK) || (Result == DEM_NO_SUCH_ELEMENT))
        {
            Result = Dem_GetDTCStatusAvailabilityMask(DemClient, &AvailableMask, DEM_DTC_ORIGIN_PRIMARY_MEMORY);

            /*Integrated response data*/
            if(Result == E_OK)
            {
                pMsgContext->resData[DCM_INDEX_2] = AvailableMask;
                pMsgContext->resData[DCM_INDEX_3] = DCM_DTC_RECORDNUM;
                /*Set the length of positive response.*/
                pMsgContext->resDataLen = (DCM_LENGTH_4_BYTE + (DCM_DTC_COUNTER * DCM_LENGTH_4_BYTE));
   
            }
            else
            {
                /*AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
        }
    }
    return Result;
}
#endif

#if(DCM_UDS_19_42_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_19_42_Processor
*
* Description: This function is used to implement the processing logic of the 42
*              subservices of the 19 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_42_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 DemClient = DCM_CFG_PCL_DEM_CLIENT(DCM_ACTIVE_PCL_ID);
    uint8 GetStatus;
    Dem_DTCSeverityType GetSeverity;
    uint8 GetFunc;
    uint32 GetDtc;
    Dem_UdsStatusByteType AvailStatusMask;
    uint8 AvailSeverityMask;
    Dcm_MsgType DestPtr;

    if(OpStatus == DCM_INITIAL)
    {
        /*Reset counter*/
        DCM_DTC_COUNTER = (uint16)0;

        /*Dcm shall reject request messages with FunctionalGroupIdentifier unequal to 0x33 by returning NRC 0x31.*/
        if((pMsgContext->reqData[DCM_INDEX_2]) != DCM_DTC_FGID_33)
        {
            /*SWS_Dcm_01128*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else
        {
            /*Get requested data*/
            DCM_DTC_STATUS = pMsgContext->reqData[DCM_INDEX_3];
            DCM_DTC_SEVERITY = pMsgContext->reqData[DCM_INDEX_4];

            /*Set filter*//*SWS_Dcm_00700*//*SWS_Dcm_01160*/
            if((DCM_DTC_STATUS != (uint8)0x00) && (DCM_DTC_SEVERITY != (Dem_DTCSeverityType)0x00))
            {
                /*SWS_Dcm_01130*/
                Result = Dem_SetDTCFilter(DemClient, DCM_DTC_STATUS, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY, \
                                        TRUE, DCM_DTC_SEVERITY, FALSE);
                if(Result == E_NOT_OK)
                {
                    /*SWS_Dcm_01043*//*SWS_Dcm_01255*/
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                }
            }
        }
    }

    if(OpStatus != DCM_CANCEL)
    {
        /*When the DTC status and severity mask in the request message are not 0, the DTCS that pass filtering will be read.*/
        if((Result == E_OK) && (DCM_DTC_STATUS != (uint8)0x00) && (DCM_DTC_SEVERITY != (Dem_DTCSeverityType)0x00))
        {
            /*The filtered DTCS are read one by one.*/
            do
            {
                /*SWS_Dcm_01130*/
                Result = Dem_GetNextFilteredDTCAndSeverity(DemClient, &GetDtc, &GetStatus, &GetSeverity, &GetFunc);

                if(Result == E_OK)
                {
                    DestPtr = &(pMsgContext->resData[DCM_INDEX_6 + (DCM_DTC_COUNTER * DCM_LENGTH_5_BYTE)]);
                    /*SWS_Dcm_01131*/
                    DestPtr[DCM_INDEX_0] = (uint8)GetSeverity;
                    DestPtr[DCM_INDEX_1] = (uint8)(GetDtc >> DCM_SHIFT_16);
                    DestPtr[DCM_INDEX_2] = (uint8)(GetDtc >> DCM_SHIFT_8);
                    DestPtr[DCM_INDEX_3] = (uint8)(GetDtc);
                    DestPtr[DCM_INDEX_4] = GetStatus;

                    DCM_DTC_COUNTER++;
                }
                else if(Result == DEM_PENDING)
                {
                    Result = DCM_E_PENDING;
                }
                else if(Result == DEM_NO_SUCH_ELEMENT)
                {
                    /*SWS_Dcm_01234, SWS_Dcm_01235 GetNextFilteredDTCAndSeverity is over*/
                }
                else/*(Result == E_NOT_OK)*/
                {
                    /*AUTOSAR specification is not defined.*/
                    *pErrorCode = DCM_E_GENERALREJECT;
                }
            } while(Result == E_OK);
        }

        /*Get DTC status available mask.*/
        if((Result == E_OK) || (Result == DEM_NO_SUCH_ELEMENT))
        {
            Result = Dem_GetDTCStatusAvailabilityMask(DemClient, &AvailStatusMask, DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY);

            if(Result == E_NOT_OK)
            {
                /*AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
        }

        /*Get DTC severity available mask.*/
        if(Result == E_OK)
        {
            /*SWS_Dcm_01127*/
            Result = Dem_GetDTCSeverityAvailabilityMask(DemClient, &AvailSeverityMask);

            /*Integrated response data*/
            if(Result == E_OK)
            {
                /*SWS_Dcm_01129*/
                pMsgContext->resData[DCM_INDEX_2] = DCM_DTC_FGID_33;
                pMsgContext->resData[DCM_INDEX_3] = AvailStatusMask;
                pMsgContext->resData[DCM_INDEX_4] = AvailSeverityMask;
                pMsgContext->resData[DCM_INDEX_5] = Dem_GetTranslationType(DemClient);
                pMsgContext->resDataLen = (DCM_LENGTH_6_BYTE + (DCM_DTC_COUNTER * DCM_LENGTH_5_BYTE));
            }
            else
            {
                /*AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
        }
    }
    return Result;
}
#endif

#if(DCM_UDS_19_55_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_19_55_Processor
*
* Description: This function is used to implement the processing logic of the 55
*              subservices of the 19 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_55_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 DemClient = DCM_CFG_PCL_DEM_CLIENT(DCM_ACTIVE_PCL_ID);
    uint8 DtcStatus;
    Dem_UdsStatusByteType AvailableMask;
    Dem_DTCTranslationFormatType FormatType;
    uint32 Dtc;
    Dcm_MsgType DestPtr;

    if(OpStatus == DCM_INITIAL)
    {
        /*Reset counter*/
        DCM_DTC_COUNTER = (uint16)0;

        /*TBD: Dcm rejects request messages with FunctionalGroupIdentifier unequal to 0x33 by returning NRC 0x31.*/
        if((pMsgContext->reqData[DCM_INDEX_2]) != DCM_DTC_FGID_33)
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else
        {
            /*Set filter*//*SWS_Dcm_01345*/
            Result = Dem_SetDTCFilter(DemClient, (uint8)0, DEM_DTC_FORMAT_UDS, DEM_DTC_ORIGIN_PERMANENT_MEMORY, \
                                    FALSE, (Dem_DTCSeverityType)0, FALSE);
            if(Result == E_NOT_OK)
            {
                /*SWS_Dcm_01043*//*SWS_Dcm_01255*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
        }
    }

    if(OpStatus != DCM_CANCEL)
    {
        /*Obtain the DTCAndStatusRecords by repeatedly calling Dem_GetNextFilteredDTC()*/
        if(Result == E_OK)
        {
            do
            {
                /*SWS_Dcm_01345*/
                Result = Dem_GetNextFilteredDTC(DemClient, &Dtc, &DtcStatus);

                if(Result == E_OK)
                {
                    DestPtr = &(pMsgContext->resData[DCM_INDEX_5 + (DCM_DTC_COUNTER * DCM_LENGTH_4_BYTE)]);
                    DestPtr[DCM_INDEX_0] = (uint8)(Dtc >> DCM_SHIFT_16);
                    DestPtr[DCM_INDEX_1] = (uint8)(Dtc >> DCM_SHIFT_8);
                    DestPtr[DCM_INDEX_2] = (uint8)(Dtc);
                    DestPtr[DCM_INDEX_3] = DtcStatus;

                    DCM_DTC_COUNTER++;
                }
                else if(Result == DEM_PENDING)
                {
                    Result = DCM_E_PENDING;
                }
                else if(Result == DEM_NO_SUCH_ELEMENT)
                {
                    /*Dem_GetNextFilteredDTC is over*/
                }
                else/*(Result == E_NOT_OK)*/
                {
                    /*AUTOSAR specification is not defined.*/
                    *pErrorCode = DCM_E_GENERALREJECT;
                }
            } while(Result == E_OK);
        }

        /*Get DTC status available mask.*/
        if((Result == E_OK) || (Result == DEM_NO_SUCH_ELEMENT))
        {
            Result = Dem_GetDTCStatusAvailabilityMask(DemClient, &AvailableMask, DEM_DTC_ORIGIN_PERMANENT_MEMORY);

            if(Result == E_NOT_OK)
            {
                /*AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
        }

        /*Get DTC translation format type.*/
        if(Result == E_OK)
        {
            FormatType = Dem_GetTranslationType(DemClient);

            /*Integrated response data*/
            if((FormatType == DEM_DTC_TRANSLATION_SAEJ1939_73) || (FormatType == DEM_DTC_TRANSLATION_J2012DA_FORMAT_04))
            {
                pMsgContext->resData[DCM_INDEX_2] = DCM_DTC_FGID_33;
                pMsgContext->resData[DCM_INDEX_3] = AvailableMask;
                pMsgContext->resData[DCM_INDEX_4] = FormatType;
                pMsgContext->resDataLen = (DCM_LENGTH_5_BYTE + (DCM_DTC_COUNTER * DCM_LENGTH_4_BYTE));
            }
            else
            {
                /*SWS_Dcm_01346*/
                *pErrorCode = DCM_E_GENERALREJECT;
                Result = E_NOT_OK;
            }
        }
    }
    return Result;
}
#endif

#if(DCM_UDS_19_56_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_19_56_Processor SWS_Dcm_01610
*
* Description: This function is used to implement the processing logic of the 56
*              subservices of the 19 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_19_56_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 DemClient = DCM_CFG_PCL_DEM_CLIENT(DCM_ACTIVE_PCL_ID);
    uint8 DtcStatus;
    Dem_UdsStatusByteType AvailableMask;
    uint32 Dtc;
    Dcm_MsgType DestPtr;

    if(OpStatus == DCM_INITIAL)
    {
        /*Reset counter*/
        DCM_DTC_COUNTER = (uint16)0;

        /*TBD: Dcm rejects request messages with FunctionalGroupIdentifier unequal to 0x33 by returning NRC 0x31.*/
        if((pMsgContext->reqData[DCM_INDEX_2]) != DCM_DTC_FGID_33)
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else
        {
            /*Set filter*//*SWS_Dcm_01610*/
            Result = Dem_SetDTCFilterByReadinessGroup(DemClient, DEM_DTC_FORMAT_UDS, (pMsgContext->reqData[DCM_INDEX_3]));
            if(Result == E_NOT_OK)
            {
                /*AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
        }
    }

    if(OpStatus != DCM_CANCEL)
    {
        /*Obtain the DTCAndStatusRecords by repeatedly calling Dem_GetNextFilteredDTC()*/
        if(Result == E_OK)
        {
            do
            {
                /*SWS_Dcm_01610*/
                Result = Dem_GetNextFilteredDTC(DemClient, &Dtc, &DtcStatus);

                if(Result == E_OK)
                {
                    DestPtr = &(pMsgContext->resData[DCM_INDEX_6 + (DCM_DTC_COUNTER * DCM_LENGTH_4_BYTE)]);
                    DestPtr[DCM_INDEX_0] = (uint8)(Dtc >> DCM_SHIFT_16);
                    DestPtr[DCM_INDEX_1] = (uint8)(Dtc >> DCM_SHIFT_8);
                    DestPtr[DCM_INDEX_2] = (uint8)(Dtc);
                    DestPtr[DCM_INDEX_3] = DtcStatus;

                    DCM_DTC_COUNTER++;
                }
                else if(Result == DEM_PENDING)
                {
                    Result = DCM_E_PENDING;
                }
                else if(Result == DEM_NO_SUCH_ELEMENT)
                {
                    /*Dem_GetNextFilteredDTC is over*/
                }
                else/*(Result == E_NOT_OK)*/
                {
                    /*AUTOSAR specification is not defined.*/
                    *pErrorCode = DCM_E_GENERALREJECT;
                }
            } while(Result == E_OK);
        }

        /*SWS_Dcm_01612*//*If no DTC supports the requested DTC readiness group,
        the Dcm shall send a negative response with NRC 0x31.*/
        if((Result == DEM_NO_SUCH_ELEMENT) && (DCM_DTC_COUNTER == (uint16)0))
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }

        /*Get DTC status available mask.*//*SWS_Dcm_01611*/
        if((Result == E_OK) || (Result == DEM_NO_SUCH_ELEMENT))
        {
            Result = Dem_GetDTCStatusAvailabilityMask(DemClient, &AvailableMask, DEM_DTC_ORIGIN_PERMANENT_MEMORY);

            /*Integrated response data*/
            if(Result == E_OK)
            {
                pMsgContext->resData[DCM_INDEX_2] = DCM_DTC_FGID_33;
                /*Copy readiness group from request buffer to response buffer.*/
                pMsgContext->resData[DCM_INDEX_5] = pMsgContext->reqData[DCM_INDEX_3];
                pMsgContext->resData[DCM_INDEX_3] = AvailableMask;
                pMsgContext->resData[DCM_INDEX_4] = Dem_GetTranslationType(DemClient);
                pMsgContext->resDataLen = (DCM_LENGTH_6_BYTE + (DCM_DTC_COUNTER * DCM_LENGTH_4_BYTE));
            }
            else
            {
                /*AUTOSAR specification is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
        }
    }
    return Result;
}
#endif
#endif/*#if(DCM_DEM_SUPPORT == STD_ON)*/
#endif/*#if(DCM_UDS_19_ENABLED == STD_ON)*/

#if(DCM_UDS_22_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_22_ReadDataByIdentifier SWS_Dcm_00253
*
* Description: This function is the code implementation of the processing logic
*              for the 0x22 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_22_ReadDataByIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 Did;
    uint16 DidIdx;
    Dcm_MsgLenType DataIdx;
#if((DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM)||(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM))
    uint8 DidHighByte;
    boolean ReadSupportedId = FALSE;
#endif

    if(OpStatus == DCM_INITIAL)
    {
#if((DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM) || (DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM))
        DidHighByte = (pMsgContext->reqData[DCM_INDEX_1]);
#endif
        if(!((pMsgContext->reqDataLen) & (Dcm_MsgLenType)0x01))
        {
            /*SWS_Dcm_00272 The correct request length should be even number and bigger than 0*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else if(((pMsgContext->reqDataLen) >> (Dcm_MsgLenType)1) > (Dcm_MsgLenType)DCM_CFG_DSP_MAX_DID_READ)
        {
            /*SWS_Dcm_01335*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
#if(DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM)
        else if((DidHighByte == DCM_RNDS_READ_READ_ID) || (DidHighByte == DCM_RNDS_READ_WRITE_ID) \
            || (DidHighByte == DCM_RNDS_READ_IO_ID) || (DidHighByte == DCM_RNDS_READ_ROUTINE_ID))
        {
            /*Getting Identifiers supported by the ECU*/
            Result = DspInternal_Rnds_ReadSupportedIdentifier(DidHighByte, pMsgContext, pErrorCode);
            ReadSupportedId = TRUE;
        }
#endif
#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
        else if(DidHighByte == DCM_RNDS_READ_ID_HIGH_BYTE)
        {
            /*Getting Identifiers supported by the ECU*/
            Result = DspInternal_22_ReadSupportedIdentifier(pMsgContext, pErrorCode);
            ReadSupportedId = TRUE;
        }
#endif
        else
        {
            /*Reset the execution step information*/
            DCM_CURRENT_EXE_STEP = DCM_DATA_CLEAR;
            /*Reset related parameters*/
            DCM_DID_COUNTER = (uint16)0;
            DCM_DID_POS = (uint16)0;
            DCM_DID_SIG_IDX = (uint16)0;
            DCM_DID_OPSTATUS = DCM_INITIAL;
            /*Set the positive response length of service data(0x22).*/
            DCM_DID_RESP_LEN = DCM_LENGTH_1_BYTE;

            /*Check whether all requested DIDs are supported*/
            for(DataIdx = DCM_INDEX_1; DataIdx < (pMsgContext->reqDataLen); DataIdx += DCM_LENGTH_2_BYTE)
            {
                Did = Make16Bit(pMsgContext->reqData[DataIdx], pMsgContext->reqData[DataIdx + DCM_LENGTH_1_BYTE]);

                Result = DspInternal_22_CheckReadDid(Did, pErrorCode, &DidIdx);
                if(Result == E_OK)
                {
                    DCM_DID_INDEX_LIST[DCM_DID_COUNTER] = DidIdx;
                    DCM_DID_COUNTER++;
                }
                else if((Result == E_NOT_OK) && (*pErrorCode != DCM_POS_RESP))
                {
                    break;
                }
                else
                {
                    /*Continue to check the next request DID*/
                    Result = E_OK;
                }
            }

            if((Result == E_OK) && (DCM_DID_COUNTER == (uint16)0))
            {
                /*SWS_Dcm_00438*//*SWS_Dcm_00433*//*SWS_Dcm_00434*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
        }
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
        SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
    }

#if((DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM) || (DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM))
    if((OpStatus != DCM_CANCEL) && (ReadSupportedId == FALSE) && (Result == E_OK))
#else
    if((OpStatus != DCM_CANCEL) && (Result == E_OK))
#endif
    {
        /*PRQA S 2461 ++*/
        /*DCM_DID_POS is file scope variable.*/

        /*Step2: Read data of request did that check passed*/
        for( ; DCM_DID_POS < DCM_DID_COUNTER; )
        {
            if(DCM_CURRENT_EXE_STEP == DCM_DATA_CLEAR)
            {
                /*Next step: Read data of DID*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_ONE;
                /*Reset the DidOpStatus to start reading data of next DID*/
                DCM_DID_OPSTATUS = DCM_INITIAL;
                
                Did = DCM_CFG_DID_ID(DCM_DID_INDEX_LIST[DCM_DID_POS]);
                DCM_DID_RESP_DATA = &(pMsgContext->resData[DCM_DID_RESP_LEN]);
                DCM_DID_RESP_DATA[DCM_INDEX_0] = (uint8)(Did >> DCM_SHIFT_8); /*Did high byte*/
                DCM_DID_RESP_DATA[DCM_INDEX_1] = (uint8)Did;                  /*Did low byte*/
                DCM_DID_DATA_LEN = (uint16)DCM_LENGTH_2_BYTE;
                DCM_DID_RESP_DATA = &(pMsgContext->resData[DCM_DID_RESP_LEN + DCM_DID_DATA_LEN]);
            }

            /*read all reference data*/
#if(DCM_UDS_2C_ENABLED == STD_ON)
            if(TRUE == DCM_CFG_DID_INFO_DYN_DEF(DCM_DID_INDEX_LIST[DCM_DID_POS]))
            {
                /*SWS_Dcm_00652*/
                Result = DspInternal_DDDidReadAllRefData(DCM_DID_INDEX_LIST[DCM_DID_POS], (pMsgContext->resMaxDataLen), pErrorCode);
            }
            else
#endif
            {
                Result = DspInternal_DidReadAllRefData(DCM_DID_INDEX_LIST[DCM_DID_POS], (pMsgContext->resMaxDataLen), pErrorCode);
            }

            if(Result == E_OK)
            {
                /*continue read next Did*/
                DCM_DID_POS++;
                DCM_DID_RESP_LEN += DCM_DID_DATA_LEN;
                DCM_CURRENT_EXE_STEP = DCM_DATA_CLEAR;
            }
            else if(Result == E_NOT_OK)
            {
                DCM_DID_POS = DCM_DID_COUNTER;
            }
            else/*Result == DCM_E_PENDING*/
            {
                /*Called again in next mainfunction*/
                DCM_DID_OPSTATUS = DCM_PENDING;
                break;
            }
        }/*for( ; DCM_DID_POS < DCM_DID_COUNTER; )*/
        /*PRQA S 2461 --*/

        /*Step3: Send response*/
        if(Result == E_OK)
        {
            pMsgContext->resDataLen = DCM_DID_RESP_LEN;
        }
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_22_CheckReadDid
*
* Description: This function checks whether the requested DID is supported and readable.
*
* Inputs: ReqDid
*
* Outputs: pErrorCode, pDidIndex
*
* Return: E_OK, E_NOT_OK
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_22_CheckReadDid
(
    uint16 ReqDid,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) pDidIndex
)
{
    Std_ReturnType Result = E_NOT_OK;
    /*Index of DID*/
    uint16 DidIdx;
#if(DCM_UDS_2C_ENABLED == STD_ON)
    uint16 BufIdx;
    uint8 DataIdx;
    /*Source DID's index of dynamic DID*/
    uint16 SDidIdx;
#endif
    uint8 SupportAddress;
    Dcm_SessionMaskType SesLevelRef;
#if(DCM_UDS_27_ENABLED == STD_ON)
    Dcm_SecurityMaskType SecLevelRef;
    Dcm_SecurityMaskType CurSecMask;
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
    Dcm_AuRoleMaskType AuRoleMask;
#endif
    /*PRQA S 2469 ++*/
    /*Loop control variable in this 'for' statement, DidIdx, modified in the body of the loop is intended to terminate the for loop.*/
    for(DidIdx = (uint16)0; DidIdx < DCM_CFG_DID_NUM; DidIdx++)
    {
        /*SWS_Dcm_00438*//*SWS_Dcm_00561*//*SWS_Dcm_00433*//*SWS_Dcm_01096*/
        if((ReqDid == DCM_CFG_DID_ID(DidIdx)) && (TRUE == DCM_CFG_DID_USED(DidIdx)) && (NULL_PTR != DCM_CFG_DID_INFO_READ(DidIdx)))
        {
#if(DCM_UDS_2C_ENABLED == STD_ON)
            BufIdx = DCM_CFG_DID_INFO_DDDID_BUF_IDX(DidIdx);
            if((TRUE == DCM_CFG_DID_INFO_DYN_DEF(DidIdx)) && (FALSE == DCM_DDDID_DEFINED(BufIdx)))
            {
                /*SWS_Dcm_00651*//*End the query, return E NOT OK and set the negtive response code.*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                DidIdx = DCM_CFG_DID_NUM;
            }
            else
#endif
            {
                /*Next step: Check address&session&security*/
                Result = E_OK;
            }
        }

        if(Result == E_OK)
        {
            /*Check address&session&security*/
            SupportAddress = (DCM_CFG_DID_INFO_READ(DidIdx)->DcmDspDidReadSupportAddress);
            SesLevelRef = (DCM_CFG_DID_INFO_READ(DidIdx)->DcmDspDidReadSessionRef);
#if(DCM_UDS_27_ENABLED == STD_ON)
            CurSecMask = DslInternal_GetSecurityMask();
            SecLevelRef = (DCM_CFG_DID_INFO_READ(DidIdx)->DcmDspDidReadSecurityLevelRef);
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
            AuRoleMask = (DCM_CFG_DID_INFO_READ(DidIdx)->DcmDspDidReadRoleRef);
#endif
            if(!(SupportAddress & ((uint8)0x01 << DCM_MSGCONTEXT.msgAddInfo.reqType)))
            {
                /*End the query and return E NOT OK*/
                DidIdx = DCM_CFG_DID_NUM;
                Result = E_NOT_OK;
            }
#if(DCM_UDS_10_ENABLED == STD_ON)
            else if(!(DCM_CFG_SESSION_MASK(DCM_SES_IDX) & SesLevelRef))
            {
                /*SWS_Dcm_00434*//*SWS_Dcm_00721*/
                /*End the query and return E NOT OK*/
                DidIdx = DCM_CFG_DID_NUM;
                Result = E_NOT_OK;
            }
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
            else if(!(DCM_AU_CUR_ROLE & AuRoleMask))
            {
                /*SWS_Dcm_01548*//*SWS_Dcm_01552*//*SWS_Dcm_01544*/
                /*End the query, return E NOT OK and set the negtive response code.*/
                *pErrorCode = DCM_E_AUTHENTICATIONREQUIRED;
                DidIdx = DCM_CFG_DID_NUM;
                Result = E_NOT_OK;
            }
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
            else if(!(CurSecMask & SecLevelRef))
            {
                /*SWS_Dcm_00435*//*SWS_Dcm_00722*/
                /*End the query, return E NOT OK and set the negtive response code.*/
                *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                DidIdx = DCM_CFG_DID_NUM;
                Result = E_NOT_OK;
            }
#endif
            else
            {
                /*do nothing*/
                *pDidIndex = DidIdx;
            }
        }

        /*SWS_Dcm_00864, SWS_Dcm_00865*//*SWS_Dcm_01097*//*Check session, security for all source DIDs*/
#if(DCM_UDS_2C_ENABLED == STD_ON)
        /*PRQA S 2880,2992 ++*/
        /*The DCM_CFG_DSP_DDDID_CHECK_SRC_DID parameter can be of type Link-Time, then this 'if' controlling expression will not be a constant expression.*/
        if((Result == E_OK) && (DCM_CFG_DSP_DDDID_CHECK_SRC_DID == TRUE) && (TRUE == DCM_CFG_DID_INFO_DYN_DEF(DidIdx)))
        /*PRQA S 2880,2992 ++*/
        {
            for(DataIdx = (uint8)0; DataIdx < DCM_DDDID_ELE_USED_NUM(BufIdx); DataIdx++)
            {
                if(DCM_DDDID_ELE_SDID_IDX(BufIdx, DataIdx) != DCM_INVALID_IDX)
                {
                    SDidIdx = DCM_DDDID_ELE_SDID_IDX(BufIdx, DataIdx);
                    /*Check address&session&security of source DID*/
                    SupportAddress = (DCM_CFG_DID_INFO_READ(SDidIdx)->DcmDspDidReadSupportAddress);
                    SesLevelRef = (DCM_CFG_DID_INFO_READ(SDidIdx)->DcmDspDidReadSessionRef);
#if(DCM_UDS_27_ENABLED == STD_ON)
                    CurSecMask = DslInternal_GetSecurityMask();
                    SecLevelRef = (DCM_CFG_DID_INFO_READ(SDidIdx)->DcmDspDidReadSecurityLevelRef);
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
                    AuRoleMask = (DCM_CFG_DID_INFO_READ(SDidIdx)->DcmDspDidReadRoleRef);
#endif
                    if(!(SupportAddress & ((uint8)0x01 << DCM_MSGCONTEXT.msgAddInfo.reqType)))
                    {
                        DidIdx = DCM_CFG_DID_NUM;
                        Result = E_NOT_OK;
                    }
#if(DCM_UDS_10_ENABLED == STD_ON)
                    else if(!(DCM_CFG_SESSION_MASK(DCM_SES_IDX) & SesLevelRef))
                    {
                        /*SWS_Dcm_00434*/
                        DidIdx = DCM_CFG_DID_NUM;
                        Result = E_NOT_OK;
                    }
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
                    else if(!(DCM_AU_CUR_ROLE & AuRoleMask))
                    {
                        /*SWS_Dcm_01549*//*SWS_Dcm_01553*//*SWS_Dcm_01544*/
                        /*End the query, return E NOT OK and set the negtive response code.*/
                        *pErrorCode = DCM_E_AUTHENTICATIONREQUIRED;
                        DidIdx = DCM_CFG_DID_NUM;
                        Result = E_NOT_OK;
                    }
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
                    else if(!(CurSecMask & SecLevelRef))
                    {
                        /*SWS_Dcm_00435*/
                        *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                        DidIdx = DCM_CFG_DID_NUM;
                        Result = E_NOT_OK;
                    }
#endif
                    else
                    {
                        /*do nothing*/
                    }

                    if(Result == E_NOT_OK)
                    {
                        break;
                    }
                }
            }/*for(DataIdx = (uint8)0; DataIdx < DCM_DDDID_ELE_USED_NUM(BufIdx); DataIdx++)*/
        }
#endif

        if(Result == E_OK)
        {
            /*End the query*/
            DidIdx = DCM_CFG_DID_NUM;
        }
    }/*for(DidIdx = (uint16)0; DidIdx < DCM_CFG_DID_NUM; DidIdx++)*/
    /*PRQA S 2469 --*/
    return Result;
}
/*PRQA S 4700 --*/
#if(DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_Rnds_ReadSupportedIdentifier
*
* Description: Read supported identifier of 0x22/0x2E/0x2F/0x31 service.
*
* Inputs: DidHighByte, pMsgContext, pErrorCode
*
* Outputs: None
*
* Return: Std_ReturnType
*
* Limitations: Only used to meet Renault's specification
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_Rnds_ReadSupportedIdentifier
(
    uint8 DidHighByte,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    uint16 i;
    uint8 BytePos;
    uint8 BitPos;
    uint8 ResponseData[DCM_RNDS_READ_DATA_LENGTH];
    Std_ReturnType Result = E_OK;
    uint8 DidLowByte = (pMsgContext->reqData[DCM_INDEX_2]);

    if((pMsgContext->reqDataLen) != DCM_RNDS_READ_LENGTH)
    {
        /*the correct request length should be 3?*/
        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        Result = E_NOT_OK;
    }
    else
    {
        for(i = (uint16)0; i < DCM_RNDS_READ_DATA_LENGTH; i++)
        {
            /*reset the data value with zero*/
            ResponseData[i] = DCM_DATA_CLEAR;
        }

        switch(DidHighByte)
        {
        case DCM_RNDS_READ_READ_ID:
            if(DCM_RNDS_READ_ID_HIGH_BYTE == DidLowByte)
            {
                for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
                {
                    if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_READ(i)))
                    {
                        BytePos = (uint8)(DCM_CFG_DID_ID(i) >> DCM_SHIFT_11);
                        BitPos = (uint8)((DCM_CFG_DID_ID(i) >> DCM_SHIFT_8) % DCM_SHIFT_8);
                        ResponseData[BytePos] |= (DCM_HIGH_BIT_MASK >> BitPos);
                    }
                }
            }
            else
            {
                for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
                {
                    if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_READ(i)) \
                        && (((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_HIGH_MASK) >> DCM_SHIFT_8) == DidLowByte))
                    {
                        BytePos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) / DCM_SHIFT_8);
                        BitPos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) % DCM_SHIFT_8);
                        ResponseData[BytePos] |= (DCM_HIGH_BIT_MASK >> BitPos);
                    }
                }
            }
            break;

#if(DCM_UDS_2E_ENABLED == STD_ON)
        case DCM_RNDS_READ_WRITE_ID:
            if(DCM_RNDS_READ_ID_HIGH_BYTE == DidLowByte)
            {
                for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
                {
                    if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_WRITE(i)))
                    {
                        BytePos = (uint8)(DCM_CFG_DID_ID(i) >> DCM_SHIFT_11);
                        BitPos = (uint8)((DCM_CFG_DID_ID(i) >> DCM_SHIFT_8) % DCM_SHIFT_8);
                        ResponseData[BytePos] |= (DCM_HIGH_BIT_MASK >> BitPos);
                    }
                }
            }
            else
            {
                for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
                {
                    if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_WRITE(i)) \
                        && (((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_HIGH_MASK) >> DCM_SHIFT_8) == DidLowByte))
                    {
                        BytePos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) / DCM_SHIFT_8);
                        BitPos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) % DCM_SHIFT_8);
                        ResponseData[BytePos] |= (DCM_HIGH_BIT_MASK >> BitPos);
                    }
                }
            }
            break;
#endif
#if(DCM_UDS_2F_ENABLED == STD_ON)
        case DCM_RNDS_READ_IO_ID:
            if(DCM_RNDS_READ_ID_HIGH_BYTE == DidLowByte)
            {
                for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
                {
                    if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_CONTROL(i)))
                    {
                        BytePos = (uint8)(DCM_CFG_DID_ID(i) >> DCM_SHIFT_11);
                        BitPos = (uint8)((DCM_CFG_DID_ID(i) >> DCM_SHIFT_8) % DCM_SHIFT_8);
                        ResponseData[BytePos] |= (DCM_HIGH_BIT_MASK >> BitPos);
                    }
                }
            }
            else
            {
                for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
                {
                    if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_CONTROL(i)) \
                        && (((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_HIGH_MASK) >> DCM_SHIFT_8) == DidLowByte))
                    {
                        BytePos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) / DCM_SHIFT_8);
                        BitPos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) % DCM_SHIFT_8);
                        ResponseData[BytePos] |= (DCM_HIGH_BIT_MASK >> BitPos);
                    }
                }
            }
            break;
#endif
#if(DCM_UDS_31_ENABLED == STD_ON)
        case DCM_RNDS_READ_ROUTINE_ID:
            if(DCM_RNDS_READ_ID_HIGH_BYTE == DidLowByte)
            {
                for(i = (uint16)0; i < DCM_CFG_ROUTINE_NUM; i++)
                {
                    if(TRUE == DCM_CFG_ROUTINE_USED(i))
                    {
                        BytePos = (uint8)(DCM_CFG_ROUTINE_ID(i) >> DCM_SHIFT_11);
                        BitPos = (uint8)((DCM_CFG_ROUTINE_ID(i) >> DCM_SHIFT_8) % DCM_SHIFT_8);
                        ResponseData[BytePos] |= (DCM_HIGH_BIT_MASK >> BitPos);
                    }
                }
            }
            else
            {
                for(i = (uint16)0; i < DCM_CFG_ROUTINE_NUM; i++)
                {
                    if((TRUE == DCM_CFG_ROUTINE_USED(i)) \
                        && (((DCM_CFG_ROUTINE_ID(i) & DCM_RNDS_ID_HIGH_MASK) >> DCM_SHIFT_8) == DidLowByte))
                    {
                        BytePos = (uint8)((DCM_CFG_ROUTINE_ID(i) & DCM_RNDS_ID_LOW_MASK) / DCM_SHIFT_8);
                        BitPos = (uint8)((DCM_CFG_ROUTINE_ID(i) & DCM_RNDS_ID_LOW_MASK) % DCM_SHIFT_8);
                        ResponseData[BytePos] |= (DCM_HIGH_BIT_MASK >> BitPos);
                    }
                }
            }
            break;
#endif
        default:
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
            break;
        }
    }

    if(Result == E_OK)
    {
        /*Copy the data to the response buffer*/
        Bsw_MemCpy(&(pMsgContext->resData[DCM_INDEX_3]), ResponseData, DCM_RNDS_READ_DATA_LENGTH);

        pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
        pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
        pMsgContext->resDataLen = (DCM_LENGTH_3_BYTE + DCM_RNDS_READ_DATA_LENGTH);
    }
    return Result;
}
#endif/*#if(DCM_CAR_PLATFORM == DCM_RNDS_PLATFORM)*/

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_22_ReadSupportedIdentifier
*
* Description: Read supported identifier of 0x22 service.
*
* Inputs: pMsgContext, pErrorCode
*
* Outputs: None
*
* Return: E_OK, E_NOT_OK
*
* Limitations: Only used to meet nissan specification
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_22_ReadSupportedIdentifier
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    uint16 i;
    uint8 BytePos;
    uint8 BitPos;
    uint8 ResponseData[DCM_RNDS_READ_DATA_LENGTH];
    Std_ReturnType Result = E_OK;
    uint8 DidLowByte = (pMsgContext->reqData[DCM_INDEX_2]);

    if((pMsgContext->reqDataLen) != DCM_RNDS_READ_LENGTH)
    {
        /*the correct request length should be 2*/
        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        Result = E_NOT_OK;
    }
    else
    {
        for(i = (uint16)0; i < DCM_RNDS_READ_DATA_LENGTH; i++)
        {
            /*reset the data value with zero*/
            ResponseData[i] = DCM_DATA_CLEAR;
        }

        if(DCM_RNDS_READ_ID_HIGH_BYTE == DidLowByte)
        {
            for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
            {
                if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_READ(i)))
                {
                    BytePos = (uint8)(DCM_CFG_DID_ID(i) >> DCM_SHIFT_11);
                    BitPos = (uint8)((DCM_CFG_DID_ID(i) >> DCM_SHIFT_8) % DCM_SHIFT_8);
                    ResponseData[BytePos] |= (DCM_HIGH_BIT_MASK >> BitPos);
                }
            }
        }
        else
        {
            for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
            {
                if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_READ(i)) \
                    && (((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_HIGH_MASK) >> DCM_SHIFT_8) == DidLowByte))
                {
                    BytePos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) / DCM_SHIFT_8);
                    BitPos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) % DCM_SHIFT_8);
                    ResponseData[BytePos] |= (DCM_HIGH_BIT_MASK >> BitPos);
                }
            }
        }
    }

    if(Result == E_OK)
    {
        /*Copy the data to the response buffer*/
        Bsw_MemCpy(&(pMsgContext->resData[DCM_INDEX_3]), ResponseData, DCM_RNDS_READ_DATA_LENGTH);

        pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
        pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
        pMsgContext->resDataLen = (DCM_LENGTH_3_BYTE + DCM_RNDS_READ_DATA_LENGTH);
    }
    return Result;
}
#endif/*#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)*/

#endif/*#if(DCM_UDS_22_ENABLED == STD_ON)*/

#if((DCM_UDS_22_ENABLED == STD_ON) || (DCM_UDS_2F_ENABLED == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_DidReadAllRefData
*
* Description: This function is used to read all the data of a DID.
*
* Inputs: DidIndex, MaxBufferSize
*
* Outputs: pErrorCode
*
* Return: E_OK, E_NOT_OK, DCM_E_PENDING
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_DidReadAllRefData
(
    uint16 DidIndex,
    uint32 MaxBufferSize,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 DataOffset;
    uint16 DataRef;
    uint16 DataLength = (uint16)0;
#if(DCM_NVM_SUPPORT == STD_ON)
    NvM_RequestResultType NvMResult = NVM_REQ_OK;
#endif
    /*PRQA S 2472 ++*/
    /*
    In the for loop statement satisfies condition DCM_DID_SIG_IDX < DCM_CFG_DID_SIG_NUM(DidIndex) then the internal statement is executed all the time.
    */
    /*read all reference data*/
    for( ; DCM_DID_SIG_IDX < DCM_CFG_DID_SIG_NUM(DidIndex); )
    {
        DataOffset = DCM_CFG_DID_SIG_OFFSET(DidIndex, DCM_DID_SIG_IDX);
        DataRef = DCM_CFG_DID_SIG_REF(DidIndex, DCM_DID_SIG_IDX);

        /*Step1: Condition check read*//*SWS_Dcm_00439*/
        if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_ONE)
        {
            if(TRUE == DCM_CFG_DATA_CON_EN(DataRef))
            {
                Result = DCM_CFG_DATA_CON_CHECK_FNC(DataRef)(DCM_DID_OPSTATUS, pErrorCode);
            }

            if(Result == E_OK)
            {
                /*Next step: Get the data length*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_TWO;
                /*Reset the DidOpStatus to start next step*/
                DCM_DID_OPSTATUS = DCM_INITIAL;
            }
        }

        /*Step2: Get the data length*//*SWS_Dcm_00436*//*SWS_Dcm_01099*/
        if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_TWO)
        {
            if(DCM_UINT8_DYN == DCM_CFG_DATA_TYPE(DataRef))
            {
                Result = DCM_CFG_DATA_LENGTH_FNC(DataRef)(DCM_DID_OPSTATUS, &DataLength);
            }
            else
            {
                DataLength = DCM_CFG_DATA_SIZE(DataRef);
            }

            if(Result == E_OK)
            {
                /*compare data length with the response buffer max length*/
                if((DCM_DID_RESP_LEN + DCM_DID_DATA_LEN + DataLength) <= MaxBufferSize)
                {
                    DCM_DID_DATA_LEN += DataLength;
                    /*Next step: Read data*/
                    DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_THREE;
                    /*Reset the DidOpStatus to start next step*/
                    DCM_DID_OPSTATUS = DCM_INITIAL;
                }
                else
                {
                    *pErrorCode = DCM_E_RESPONSETOOLONG;
                    Result = E_NOT_OK;
                }
            }
        }

        /*Step3: Read data*//*SWS_Dcm_00437*//*SWS_Dcm_01432*//*SWS_Dcm_00560*/
        if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_THREE)
        {
#if(DCM_NVM_SUPPORT == STD_ON)
            if(DCM_USE_BLOCK_ID == DCM_CFG_DATA_USEPORT(DataRef))
            {
                /*PRQA S 315,488 ++*/
                /*NvM_ReadBlock is an autosar standard interface. Allow pointer arithmetic.*/
                Result = NvM_ReadBlock(DCM_CFG_DATA_BLOCKID(DataRef), (DCM_DID_RESP_DATA + DataOffset));
                /*PRQA S 315,488 --*/
                if(Result == E_OK)
                {
                    /*Next step: Call NvM_GetErrorStatus*/
                    DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_FOUR;
                    Result = DCM_E_PENDING;
                }
            }
            else
#endif
            {
                Result = DCM_CFG_DATA_READ_FNC(DataRef)(DCM_DID_OPSTATUS, &(DCM_DID_RESP_DATA[DataOffset]), pErrorCode);
            }
        }

#if(DCM_NVM_SUPPORT == STD_ON)
        /*Step4: Call NvM_GetErrorStatus*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_FOUR))
        {
            /*SWS_Dcm_00870*/
            Result = NvM_GetErrorStatus(DCM_CFG_DATA_BLOCKID(DataRef), &NvMResult);
            if((Result == E_OK) && (NvMResult == NVM_REQ_OK))
            {
                /*continue read next signal*/
            }
            else if((Result == E_OK) && (NvMResult == NVM_REQ_PENDING))
            {
                /*Call again next mainfunction*/
                Result = DCM_E_PENDING;
            }
            else
            {
                /*AUTOSAR standard is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
                Result = E_NOT_OK;
            }
        }
#endif

        if(Result == E_OK)
        {
            /*continue read next signal*/
            DCM_DID_SIG_IDX++;
            DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_ONE;
            /*Reset the DidOpStatus to start reading next data of current DID*/
            DCM_DID_OPSTATUS = DCM_INITIAL;
        }
        else
        {
            /*Result == DCM_E_PENDING, The fuction will be called again in next mainfunction cycle.*/
            /*Result == Other value, send negative response*/
            break;
        }
    }/*for( ; DCM_DID_SIG_IDX < DCM_CFG_DID_SIG_NUM(DidIndex); )*/
    /*PRQA S 2472 --*/
    if((Result == E_OK) || (Result == E_NOT_OK))
    {
        DCM_DID_SIG_IDX = (uint16)0;
    }
    return Result;
}
/*PRQA S 4700 --*/
#endif

#if(DCM_UDS_23_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_23_ReadMemoryByAddress SWS_Dcm_00492
*
* Description: This function is the code implementation of the processing logic
*              for the 0x22 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_23_ReadMemoryByAddress
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    Dcm_SessionMaskType SesLevelRef;
#if(DCM_UDS_27_ENABLED == STD_ON)
    Dcm_SecurityMaskType SecLevelRef;
    Dcm_SecurityMaskType CurSecMask;
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
    Dcm_AuRoleMaskType AuRoleMask;
#endif

    uint8 AddrSizeFormat;
    uint8 AddrLength;
    uint8 SizeLength;
    uint8 Idx;/*Index*/
    uint16 MemRangeIdx = (uint16)0;/*Index of memory range info*/

    if(OpStatus == DCM_INITIAL)
    {
        DCM_MEM_START_ADDR = (uint32)0;
        DCM_MEM_SIZE = (uint32)0;
        DCM_MEM_ID = DCM_DATA_CLEAR;
        AddrSizeFormat = (pMsgContext->reqData[DCM_INDEX_1]);
        AddrLength = (AddrSizeFormat & DCM_MEM_FORMAT_ADDR_MASK);
        SizeLength = ((AddrSizeFormat & DCM_MEM_FORMAT_SIZE_MASK) >> DCM_SHIFT_4);
        /*SWS_Dcm_00853,Check addressAndLengthFormatIdentifier*/
        if(DCM_CFG_MEM_FORMAT_NUM != DCM_DATA_CLEAR)
        {
            Result = E_NOT_OK;
            for(Idx = (uint8)0; Idx < DCM_CFG_MEM_FORMAT_NUM; Idx++)
            {
                if(AddrSizeFormat == DCM_CFG_MEM_FORMAT(Idx))
                {
                    Result = E_OK;
                    break;
                }
            }
        }

        if((Result == E_NOT_OK) || (AddrLength == DCM_DATA_CLEAR) || (SizeLength == DCM_DATA_CLEAR))
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        /*total length check*/
        else if((pMsgContext->reqDataLen) != (DCM_LENGTH_2_BYTE + AddrLength + SizeLength))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
            /*Calculate start address*/
            for(Idx = (uint8)0; Idx < AddrLength; Idx++)
            {
                DCM_MEM_START_ADDR |= (uint32)(pMsgContext->reqData[DCM_INDEX_2 + Idx]) << (uint8)(DCM_SHIFT_8 * (AddrLength - DCM_INDEX_1 - Idx));
            }

            /*Calculate size*/
            for(Idx = (uint8)0; Idx < SizeLength; Idx++)
            {
                DCM_MEM_SIZE |= (uint32)(pMsgContext->reqData[DCM_INDEX_2 + AddrLength + Idx]) << (uint8)(DCM_SHIFT_8 * (SizeLength - DCM_INDEX_1 - Idx));
            }

            /*Value memory size should greater than 0.*/
            if(DCM_MEM_SIZE == (uint32)0)
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
        }

        /*check memory range & security & session*/
        if(Result == E_OK)
        {
            Result = E_NOT_OK;
            /*SWS_Dcm_00493*//*SWS_Dcm_01053*/
            for(Idx = (uint8)0; Idx < DCM_CFG_MEM_ID_NUM; Idx++)
            {
                for(MemRangeIdx = (uint16)0; MemRangeIdx < DCM_CFG_MEM_ID_READ_NUM(Idx); MemRangeIdx++)
                {
                    if((DCM_MEM_START_ADDR <= DCM_CFG_MEM_ID_READ_HIGH(Idx, MemRangeIdx)) \
                        && (DCM_MEM_START_ADDR >= DCM_CFG_MEM_ID_READ_LOW(Idx, MemRangeIdx)) \
                        && (((DCM_MEM_START_ADDR + DCM_MEM_SIZE) - DCM_LENGTH_1_BYTE) <= DCM_CFG_MEM_ID_READ_HIGH(Idx, MemRangeIdx)))
                    {
                        DCM_MEM_ID = DCM_CFG_MEM_ID_VALUE(Idx);
                        Result = E_OK;
                        break;
                    }
                }

                if(Result == E_OK)
                {
                    break;
                }
            }

            if(Result == E_NOT_OK)
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
            else
            {
                /*check security & session*/
                SesLevelRef = DCM_CFG_MEM_ID_READ_SESREF(Idx, MemRangeIdx);
#if(DCM_UDS_27_ENABLED == STD_ON)
                SecLevelRef = DCM_CFG_MEM_ID_READ_SECREF(Idx, MemRangeIdx);
                CurSecMask = DslInternal_GetSecurityMask();
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
                AuRoleMask = DCM_CFG_MEM_ID_READ_ROLEREF(Idx, MemRangeIdx);
#endif
                if(!(DCM_CFG_SESSION_MASK(DCM_SES_IDX) & SesLevelRef))
                {
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
#if(DCM_UDS_29_ENABLED == STD_ON)
                else if(!(DCM_AU_CUR_ROLE & AuRoleMask))
                {
                    /*SWS_Dcm_01551*/
                    *pErrorCode = DCM_E_AUTHENTICATIONREQUIRED;
                    Result = E_NOT_OK;
                }
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
                else if(!(CurSecMask & SecLevelRef))
                {
                    /*SWS_Dcm_00494*/
                    *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
#endif
                else
                {
                    DCM_MEM_DATA_PTR = &(pMsgContext->resData[DCM_INDEX_1]);
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
                    SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
                    /*Call Dcm_ReadMemory()*/
                }
            }
        }
    }/*if(OpStatus == DCM_INITIAL)*/

    if((OpStatus != DCM_CANCEL) && (Result == E_OK))
    {
        /*SWS_Dcm_00495*/
        Result = DspInternal_ReadMemory(DCM_23_SERVICE, OpStatus, DCM_MEM_ID, DCM_MEM_START_ADDR, DCM_MEM_SIZE, DCM_MEM_DATA_PTR, pErrorCode);

        if(Result == E_OK)
        {
            pMsgContext->resDataLen = DCM_LENGTH_1_BYTE + DCM_MEM_SIZE;
        }
    }
    return Result;
}
/*PRQA S 4700 --*/
#endif

#if(DCM_UDS_27_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_27_SecurityAccess SWS_Dcm_00252
*
* Description: This function is the code implementation of the processing logic
*              for the 0x27 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_27_SecurityAccess
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
#if(STD_ON == DCM_CFG_ACCESS_ATTEMPT_COUNTER_SUPPORT)
    boolean CounterChanged = FALSE;
#endif
    boolean EndProcess = FALSE;
    uint8 StabId = DCM_CURRENT_STAB;
    Dcm_SecLevelType ReqSecLevel;
    uint8 SecRowIdx;
    uint32 Idx;
    boolean TempAcessSequence;
    if(OpStatus == DCM_INITIAL)
    {
#if(DCM_UDS_27_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
        ClearSuppressPosRespBit();
#endif
        DCM_REQ_ROW_IDX = DCM_DATA_CLEAR;

        /*Check Length & AttemptCounter & Sequence*/
        /****************************** Request Seed ******************************/
        if((uint8)(DCM_REQ_SUBSERVICE & (uint8)0x01) != (uint8)0)
        {
            ReqSecLevel = ((DCM_REQ_SUBSERVICE + (uint8)1) >> (uint8)1);
            /*Find the corresponding security row*/
            for(SecRowIdx = (uint8)0; SecRowIdx < DCM_CFG_SEC_NUM(StabId); SecRowIdx++)
            {
                if(ReqSecLevel == DCM_CFG_SEC_LEVEL(StabId, SecRowIdx))
                {
                    DCM_REQ_ROW_IDX = SecRowIdx;
                    break;
                }
            }

            TempAcessSequence = DCM_SEC_SEQ(StabId, DCM_REQ_ROW_IDX);
            DspInternal_27_ResetSequence(StabId);

            /*SWS_Dcm_00272 Trigger NRC 0x13 when the analysis of the request message results in formatting or length failure.*/
            if(pMsgContext->reqDataLen != (DCM_CFG_SEC_ADR_SIZE(StabId, DCM_REQ_ROW_IDX) + DCM_LENGTH_2_BYTE))
            {
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                Result = E_NOT_OK;
            }
            else if (DCM_SEC_ALL_INIT == FALSE)
            {
                /*SWS_Dcm_01354*/
                *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
                Dcm_SetNRC22Reason(DCM_NRC22_REASON_3);
#endif
                Result = E_NOT_OK;
            }
            else if((DCM_SEC_DELAY_ON_BOOT(StabId, DCM_REQ_ROW_IDX) != FALSE) \
                || (DCM_SEC_ATT_NUM(StabId, DCM_REQ_ROW_IDX) == DCM_DATA_CLEAR))
            {
                /*SWS_Dcm_01350*/
                *pErrorCode = DCM_E_REQUIREDTIMEDELAYNOTEXPIRED;
                Result = E_NOT_OK;
            }
            else if((DCM_SEC_IDX == DCM_REQ_ROW_IDX) || (DCM_SEC_IDX == DCM_SECURITY_ALL_IDX))
            {
                /*SWS_Dcm_00323*/
                for(Idx = (uint32)0; Idx < DCM_CFG_SEC_SEED_SIZE(StabId, DCM_REQ_ROW_IDX); Idx++)
                {
                    pMsgContext->resData[DCM_INDEX_2 + Idx] = (uint8)0;
                }
#if(DCM_UDS_27_NCR24AFTERZEROSEED == STD_OFF)
                DCM_SEC_SEQ(StabId, DCM_REQ_ROW_IDX) = TRUE;
#endif
                pMsgContext->resDataLen = DCM_CFG_SEC_SEED_SIZE(StabId, DCM_REQ_ROW_IDX) + DCM_LENGTH_2_BYTE;
                /*Send positive response directly*/
                EndProcess = TRUE;
            }
            else
            {
#if(DCM_UDS_27_REQUESTSEEDCONTINOUS == STD_ON)
                if(TempAcessSequence == TRUE)
                {
                    /*DCM_SEC_SEQ(StabId, DCM_REQ_ROW_IDX) = FALSE;*/
#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
                    if(DCM_SEC_SEED_ATT_NUM(StabId, DCM_REQ_ROW_IDX) != (uint8)0)
                    {
                        DCM_SEC_SEED_ATT_NUM(StabId, DCM_REQ_ROW_IDX)--;
                    }
#else
                    DCM_SEC_ATT_NUM(StabId, DCM_REQ_ROW_IDX)--;
#endif
#if(STD_ON == DCM_CFG_ACCESS_ATTEMPT_COUNTER_SUPPORT)
                    CounterChanged = TRUE;
#endif
                }

                if(DCM_SEC_ATT_NUM(StabId, DCM_REQ_ROW_IDX) == DCM_DATA_CLEAR)
                {
                    *pErrorCode = DCM_E_REQUIREDTIMEDELAYNOTEXPIRED;
                    Result = E_NOT_OK;
                }
#endif
                /*Call the GetSeed function.*/
            }
        }
        else/****************************** Receive Key ******************************/
        {
            ReqSecLevel = (DCM_REQ_SUBSERVICE >> (uint8)1);
            /*Find the corresponding security row*/
            for(SecRowIdx = (uint8)0; SecRowIdx < DCM_CFG_SEC_NUM(StabId); SecRowIdx++)
            {
                if(ReqSecLevel == DCM_CFG_SEC_LEVEL(StabId, SecRowIdx))
                {
                    DCM_REQ_ROW_IDX = SecRowIdx;
                    break;
                }
            }

            if(DCM_SEC_SEQ(StabId, DCM_REQ_ROW_IDX) != TRUE)
            {
                /*Reset the request sequence in DsdInternal_CreatNegResponse()*/
                *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                Result = E_NOT_OK;
            }
            else if(pMsgContext->reqDataLen != (DCM_CFG_SEC_KEY_SIZE(StabId, DCM_REQ_ROW_IDX) + DCM_LENGTH_2_BYTE))
            {
#if(STD_ON == DCM_UDS_27_KEY_SIZE_ERR_EFFECT_ATTNUM)
                /*Reset the request sequence in DsdInternal_CreatNegResponse()*/
                if((DCM_SEC_IDX != DCM_REQ_ROW_IDX) && (DCM_SEC_IDX != DCM_SECURITY_ALL_IDX))
                {
                    /*Decrease allowed attmept number */
#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
                    DCM_SEC_KEY_ATT_NUM(StabId, DCM_REQ_ROW_IDX)--;
                    if(DCM_SEC_KEY_ATT_NUM(StabId, DCM_REQ_ROW_IDX) == (uint8)0)
                    {
                        DCM_SEC_ATT_NUM(StabId, DCM_REQ_ROW_IDX) = DCM_DATA_CLEAR;
                    }
#else
                    DCM_SEC_ATT_NUM(StabId, DCM_REQ_ROW_IDX)--;
#endif
#if(STD_ON == DCM_CFG_ACCESS_ATTEMPT_COUNTER_SUPPORT)
                    CounterChanged = TRUE;
#endif
                }

                if(DCM_SEC_ATT_NUM(StabId, DCM_REQ_ROW_IDX) == DCM_DATA_CLEAR)
                {
                    *pErrorCode = DCM_E_EXCEEDNUMBEROFATTEMPTS;
                }
                else
#endif /* STD_ON == DCM_UDS_27_KEY_SIZE_ERR_EFFECT_ATTNUM */
                {
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
                    *pErrorCode = DCM_E_INVALIDKEY;
#else
                    *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
#endif
                }
                Result = E_NOT_OK;
            }
            else if((DCM_SEC_IDX == DCM_REQ_ROW_IDX) || (DCM_SEC_IDX == DCM_SECURITY_ALL_IDX))
            {
                /*Check if the requested security level has already been unlocked, if so, send positive response directly.*/
                pMsgContext->resDataLen = DCM_LENGTH_2_BYTE;
                EndProcess = TRUE;
            }
            else
            {
                /*Call the CompareKey function*/
            }
        }

#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
        SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
    }

    if((OpStatus != DCM_CANCEL) && (Result == E_OK) && (EndProcess == FALSE))
    {
        /*SWS_Dcm_00324*/
        if((uint8)(DCM_REQ_SUBSERVICE & (uint8)0x01) != (uint8)0)
        {
            /*SWS_Dcm_00862 Call the configured Xxx_GetSeed() function*/
            Result = DCM_CFG_SEC_GETSEED_FNC(StabId, DCM_REQ_ROW_IDX)(OpStatus, pMsgContext, pErrorCode);

            if(Result == E_OK)
            {
                /*Record that the GetSeed has been successfully requested*/
                DCM_SEC_SEQ(StabId, DCM_REQ_ROW_IDX) = TRUE;
                /*Set the positive response data length.*/
                pMsgContext->resDataLen = DCM_CFG_SEC_SEED_SIZE(StabId, DCM_REQ_ROW_IDX) + DCM_LENGTH_2_BYTE;
#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
                if(DCM_SEC_SEED_ATT_NUM(StabId, DCM_REQ_ROW_IDX) == (uint8)0)
                {
                    DCM_SEC_ATT_NUM(StabId, DCM_REQ_ROW_IDX) = DCM_DATA_CLEAR;
                    DCM_SEC_SEQ(StabId, DCM_REQ_ROW_IDX) = FALSE;
#if(STD_ON == DCM_CFG_ACCESS_ATTEMPT_COUNTER_SUPPORT)
                    CounterChanged = TRUE;
#endif
                }
#endif
            }
            /*SWS_Dcm_00659 If Xxx_GetSeed() returns value E_NOT_OK, the Dcm module shall send a negative response
            with NRC code equal to the ErrorCode parameter value.*/
        }
        else
        {
            /*SWS_Dcm_00863 Call the configured Xxx_CompareKey() function*/
            Result = DCM_CFG_SEC_COMPAREKEY_FNC(StabId, DCM_REQ_ROW_IDX)(OpStatus, pMsgContext, pErrorCode);

            if(Result == DCM_E_COMPARE_KEY_FAILED)
            {
                /*Reset the request sequence in DsdInternal_CreatNegResponse()*/
                /*SWS_Dcm_01397 If key is not valid, decrease allowed attmept number */
#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
                DCM_SEC_KEY_ATT_NUM(StabId, DCM_REQ_ROW_IDX)--;
                if(DCM_SEC_KEY_ATT_NUM(StabId, DCM_REQ_ROW_IDX) == (uint8)0)
                {
                    DCM_SEC_ATT_NUM(StabId, DCM_REQ_ROW_IDX) = DCM_DATA_CLEAR;
                }
#else
                DCM_SEC_ATT_NUM(StabId, DCM_REQ_ROW_IDX)--;
#endif
#if(STD_ON == DCM_CFG_ACCESS_ATTEMPT_COUNTER_SUPPORT)
                CounterChanged = TRUE;
#endif
                if(DCM_SEC_ATT_NUM(StabId, DCM_REQ_ROW_IDX) == DCM_DATA_CLEAR)
                {
                    /*SWS_Dcm_01349 Send a negative response with NRC 0x36 (exceededNumberOfAttempts)*/
                    *pErrorCode = DCM_E_EXCEEDNUMBEROFATTEMPTS;
                }
                else
                {
                    /*SWS_Dcm_00660 Send a negative response with NRC 0x35 (InvalidKey)*/
                    *pErrorCode = DCM_E_INVALIDKEY;
                }
            }
            else if(Result == E_NOT_OK)
            {
                /*Reset the request sequence in DsdInternal_CreatNegResponse()*/
                /*SWS_Dcm_01150 Send a negative response with NRC code equal to the ErrorCode parameter value
                and shall not change the attempt counter*/
            }
            else if(Result == E_OK)
            {
                if(DCM_SEC_ATT_NUM(StabId, DCM_REQ_ROW_IDX) != DCM_CFG_SEC_ATT_NUM(StabId, DCM_REQ_ROW_IDX))
                {
                    /*SWS_Dcm_01357*/
                    DCM_SEC_ATT_NUM(StabId, DCM_REQ_ROW_IDX) = DCM_CFG_SEC_ATT_NUM(StabId, DCM_REQ_ROW_IDX);
#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
                    DCM_SEC_KEY_ATT_NUM(StabId, DCM_REQ_ROW_IDX)  = DCM_CFG_SEC_KEY_ATT_NUM(StabId, DCM_REQ_ROW_IDX);
                    DCM_SEC_SEED_ATT_NUM(StabId, DCM_REQ_ROW_IDX) = DCM_CFG_SEC_SEED_ATT_NUM(StabId, DCM_REQ_ROW_IDX);
#endif
#if(STD_ON == DCM_CFG_ACCESS_ATTEMPT_COUNTER_SUPPORT)
                    CounterChanged = TRUE;
#endif
                }
                DCM_SEC_DELAY_TIME(StabId, DCM_REQ_ROW_IDX) = DCM_CFG_SEC_DELAYTIME(StabId, DCM_REQ_ROW_IDX);
                DCM_SEC_SEQ(StabId, DCM_REQ_ROW_IDX) = FALSE;
                /*SWS_Dcm_00325 Update the current security level*/
                DslInternal_SetSecurityLevel(DCM_REQ_ROW_IDX);
                /*Set the positive response data length.*/
                pMsgContext->resDataLen = DCM_LENGTH_2_BYTE;
            }
            else
            {
                /*Call CompareKey function again in next mainfunction*/
            }
        }

#if(STD_ON == DCM_CFG_ACCESS_ATTEMPT_COUNTER_SUPPORT)
        /*SWS_Dcm_01155*/
        if((CounterChanged == TRUE) && (DCM_CFG_SEC_ATT_EN(StabId, DCM_REQ_ROW_IDX) == TRUE))
        {
#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
            (void)DCM_CFG_SEC_SET_ATT_FNC(StabId, DCM_REQ_ROW_IDX)(OpStatus, DCM_SEC_ATT_NUM(StabId, DCM_REQ_ROW_IDX),DCM_SEC_KEY_ATT_NUM(StabId, DCM_REQ_ROW_IDX),DCM_SEC_SEED_ATT_NUM(StabId, DCM_REQ_ROW_IDX));
#else
            (void)DCM_CFG_SEC_SET_ATT_FNC(StabId, DCM_REQ_ROW_IDX)(OpStatus, DCM_SEC_ATT_NUM(StabId, DCM_REQ_ROW_IDX));
#endif
        }
#endif
    }
    if(Result == E_OK)
    {
        pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
    }
    return Result;
}
/*PRQA S 4700 --*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_27_ResetSequence SWS_Dcm_00511
*
* Description: This function is used to reset the sequence of each security of
*              current active protocol.
*
* Inputs: StabId: Service table of current active protocol
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DspInternal_27_ResetSequence
(
    uint8 StabId
)
{
    uint8 SecRowIdx;

    for(SecRowIdx = (uint8)0; SecRowIdx < DCM_CFG_SEC_NUM(StabId); SecRowIdx++)
    {
        DCM_SEC_SEQ(StabId, SecRowIdx) = FALSE;
    }
}
#endif/*#if(DCM_UDS_27_ENABLED == STD_ON)*/

#if(DCM_UDS_28_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_28_CommunicationControl SWS_Dcm_00511
*
* Description: This function is the code implementation of the processing logic
*              for the 0x28 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_28_CommunicationControl
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

#if(DCM_UDS_28_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
    ClearSuppressPosRespBit();
#endif
    /*Record the sessions supported by this service to determine whether communication
    needs to be restored when switching sessions.*/
    DCM_COM_SERVICE_SESSION = (DCM_REQ_SERVICEINFO->DcmDsdSidTabSessionLevelRef);

    /*SWS_Dcm_00272 Trigger NRC 0x13 when the analysis of the request message results in formatting or length failure.*/
    if((DCM_REQ_SUBSERVICE == DCM_ENABLE_RX_TX) || (DCM_REQ_SUBSERVICE == DCM_ENABLE_RX_DISABLE_TX) \
        || (DCM_REQ_SUBSERVICE == DCM_DISABLE_RX_ENABLE_TX) || (DCM_REQ_SUBSERVICE == DCM_DISABLE_RX_TX))
    {
        if((pMsgContext->reqDataLen) != DCM_LENGTH_3_BYTE)
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
    }
    else/*DCM_ENABLE_RX_DISABLE_TX_ENHANCED, DCM_ENABLE_RX_TX_ENHANCED*/
    {
        if((pMsgContext->reqDataLen) != DCM_LENGTH_5_BYTE)
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
    }

    /*check Message Type*/
    if(Result == E_OK)
    {
#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
        DCM_COM_REQMSGTYPE = ((pMsgContext->reqData[DCM_INDEX_2]));
#else
        DCM_COM_REQMSGTYPE = ((pMsgContext->reqData[DCM_INDEX_2]) & DCM_MSG_MASK);
#endif
        if((DCM_COM_REQMSGTYPE < DCM_NORMAL_MSG) || (DCM_COM_REQMSGTYPE > DCM_NM_NORMAL_MSG))
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else
        {
            switch(DCM_REQ_SUBSERVICE)
            {
            case DCM_ENABLE_RX_TX:
            case DCM_ENABLE_RX_DISABLE_TX:
            case DCM_DISABLE_RX_ENABLE_TX:
            case DCM_DISABLE_RX_TX:
                Result = DspInternal_28_Sub_Processor(OpStatus, pMsgContext, pErrorCode);
                break;

            default:
                Result = DspInternal_28_EnhancedSub_Processor(OpStatus, pMsgContext, pErrorCode);
                break;
            }
        }
    }
    /*Send positive response*/
    if(Result == E_OK)
    {
        DCM_COM_REQSUBSERVICE = DCM_REQ_SUBSERVICE;
        pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
        pMsgContext->resDataLen = DCM_LENGTH_2_BYTE;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_Init_CommunicationState
*
* Description: This function is used to initialize the communication control state.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DspInternal_Init_CommunicationState
(
    void
)
{
    NetworkHandleType Channel;

    /*Reset the last executed subservice of 0x28.*/
    DCM_COM_REQSUBSERVICE = DCM_DATA_U8_MAX;
    /*Reset communication state of all channel.*/
    for(Channel = (NetworkHandleType)0; Channel < DCM_NUM_COMM_CHANNEL; Channel++)
    {
        DCM_COM_NM_MSG_STATE(Channel) = DCM_ENABLE_RX_TX_NM;
        DCM_COM_APP_MSG_STATE(Channel) = DCM_ENABLE_RX_TX_NORM;
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_28_Sub_Processor
*
* Description: This function is the code implementation of the processing logic
*              for the subservices 00 & 01 & 02 & 03 of 0x28 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_28_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 ChnIdx;

    (void)OpStatus;
    DCM_COM_REQSUBNET = (((pMsgContext->reqData[DCM_INDEX_2]) & DCM_SUBNET_MASK) >> DCM_SHIFT_4);

    if(DCM_COM_REQSUBNET == DCM_DATA_CLEAR)
    {
        if((DCM_CFG_COM_ALLCHL_NUM == DCM_DATA_CLEAR) || (DCM_CFG_COM_ALLCHL == NULL_PTR))
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
    }
    else if(DCM_COM_REQSUBNET == DCM_SUBNET_RECEIVEED_ON)
    {
        /*Result = E_OK;*/
    }
    else/*0 < ReqSubNet < 0x0F*/
    {
        if((DCM_CFG_COM_SPECHL_NUM == DCM_DATA_CLEAR) || (DCM_CFG_COM_SPECHL == NULL_PTR))
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else
        {
            for(ChnIdx = (uint8)0; ChnIdx < DCM_CFG_COM_SPECHL_NUM; ChnIdx++)
            {
                if((DCM_COM_REQSUBNET == DCM_CFG_COM_SPECHL_NETNUN(ChnIdx)) && (TRUE == DCM_CFG_COM_SPECHL_USED(ChnIdx)))
                {
                    break;
                }
            }

            if(ChnIdx >= DCM_CFG_COM_SPECHL_NUM)
            {
                /*SWS_Dcm_00786*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_28_EnhancedSub_Processor
*
* Description: This function is the code implementation of the processing logic
*              for the subservices 04 & 05 of 0x28 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_28_EnhancedSub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 NodeIdx;

    (void)OpStatus;
    DCM_COM_REQSUBNODE = Make16Bit(pMsgContext->reqData[DCM_INDEX_3], pMsgContext->reqData[DCM_INDEX_4]);

    if((DCM_CFG_COM_SUBNODE_NUM == (uint16)0) || (DCM_CFG_COM_SUBNODE == NULL_PTR))
    {
        /*SWS_Dcm_01078*//*SWS_Dcm_01080*//*SWS_Dcm_01081*//*SWS_Dcm_01082*/
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        Result = E_NOT_OK;
    }
    else
    {
        for(NodeIdx = (uint16)0; NodeIdx < DCM_CFG_COM_SUBNODE_NUM; NodeIdx++)
        {
            if((DCM_COM_REQSUBNODE == DCM_CFG_COM_SUBNODE_ID(NodeIdx)) && (TRUE == DCM_CFG_COM_SUBNODE_USED(NodeIdx)))
            {
                break;
            }
        }

        if(NodeIdx >= DCM_CFG_COM_SUBNODE_NUM)
        {
            /*SWS_Dcm_01078*//*SWS_Dcm_01080*//*SWS_Dcm_01081*//*SWS_Dcm_01082*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_28_Sub_Post
*
* Description: This function is used to complete the processing after the positive
*              response of the 0x28 service is successfully sent
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*There is not limit on the number of lines of function code and the number of local variable assignments.*/
STATIC FUNC(void, DCM_CODE) DspInternal_28_Sub_Post
(
    void
)
{
    uint8 ChnIdx;
    NetworkHandleType NetworkHandle;
    Dcm_CommunicationModeType ReqMode;
    uint8 TempSubService;
    uint16 NodeIdx;

    switch(DCM_COM_REQSUBSERVICE)
    {
    case DCM_ENABLE_RX_TX:
    case DCM_ENABLE_RX_DISABLE_TX:
    case DCM_DISABLE_RX_ENABLE_TX:
    case DCM_DISABLE_RX_TX:
        ReqMode = (((DCM_COM_REQMSGTYPE << DCM_SHIFT_2) | DCM_COM_REQSUBSERVICE) - DCM_COM_MODE_OFFSET);

        if(DCM_COM_REQSUBNET == DCM_DATA_CLEAR)
        {
            /*SWS_Dcm_00512*/
            for(ChnIdx = (uint8)0; ChnIdx < DCM_CFG_COM_ALLCHL_NUM; ChnIdx++)
            {
                if(TRUE == DCM_CFG_COM_ALLCHL_USED(ChnIdx))
                {
                    NetworkHandle = DCM_CFG_COM_ALLCHL_REF(ChnIdx);

                    if((uint8)(DCM_COM_REQMSGTYPE & DCM_NM_MSG) != (uint8)0)
                    {
                        DCM_COM_NM_MSG_STATE(NetworkHandle) |= DCM_COM_REQSUBSERVICE;
                        DCM_COM_NM_MSG_STATE(NetworkHandle) &= (DCM_COM_MODE_OFFSET | DCM_COM_REQSUBSERVICE);
                    }

                    if((uint8)(DCM_COM_REQMSGTYPE & DCM_NORMAL_MSG) != (uint8)0)
                    {
                        DCM_COM_APP_MSG_STATE(NetworkHandle) |= DCM_COM_REQSUBSERVICE;
                        DCM_COM_APP_MSG_STATE(NetworkHandle) &= DCM_COM_REQSUBSERVICE;
                    }

                    (void)DCM_CFG_COM_ALLCHL_SWITCH_FNC(ChnIdx)(ReqMode);
                    (void)Dcm_Rte_CommunicationMode_CurrentState(NetworkHandle, ReqMode);
                }
            }
        }
        else if(DCM_COM_REQSUBNET == DCM_SUBNET_RECEIVEED_ON)
        {
            /*SWS_Dcm_00785*/
            NetworkHandle = DCM_CFG_PCL_CONNECTION_MAIN_COMM_CHN(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
            for(ChnIdx = (uint8)0; ChnIdx < DCM_CFG_COM_ALLCHL_NUM; ChnIdx++)
            {
                if((TRUE == DCM_CFG_COM_ALLCHL_USED(ChnIdx)) && (NetworkHandle == DCM_CFG_COM_ALLCHL_REF(ChnIdx)))
                {
                    if((uint8)(DCM_COM_REQMSGTYPE & DCM_NM_MSG) != (uint8)0)
                    {
                        DCM_COM_NM_MSG_STATE(NetworkHandle) |= DCM_COM_REQSUBSERVICE;
                        DCM_COM_NM_MSG_STATE(NetworkHandle) &= (DCM_COM_MODE_OFFSET | DCM_COM_REQSUBSERVICE);
                    }

                    if((uint8)(DCM_COM_REQMSGTYPE & DCM_NORMAL_MSG) != (uint8)0)
                    {
                        DCM_COM_APP_MSG_STATE(NetworkHandle) |= DCM_COM_REQSUBSERVICE;
                        DCM_COM_APP_MSG_STATE(NetworkHandle) &= DCM_COM_REQSUBSERVICE;
                    }

                    (void)DCM_CFG_COM_ALLCHL_SWITCH_FNC(ChnIdx)(ReqMode);
                    (void)Dcm_Rte_CommunicationMode_CurrentState(NetworkHandle, ReqMode);
                    break;
                }
            }
        }
        else/*0 < DCM_COM_REQSUBNET < 0x0F*/
        {
            /*SWS_Dcm_00786*/
            for(ChnIdx = (uint8)0; ChnIdx < DCM_CFG_COM_SPECHL_NUM; ChnIdx++)
            {
                if(DCM_COM_REQSUBNET == DCM_CFG_COM_SPECHL_NETNUN(ChnIdx))
                {
                    NetworkHandle = DCM_CFG_COM_SPECHL_REF(ChnIdx);

                    if((uint8)(DCM_COM_REQMSGTYPE & DCM_NM_MSG) != (uint8)0)
                    {
                        DCM_COM_NM_MSG_STATE(NetworkHandle) |= DCM_COM_REQSUBSERVICE;
                        DCM_COM_NM_MSG_STATE(NetworkHandle) &= (DCM_COM_MODE_OFFSET | DCM_COM_REQSUBSERVICE);
                    }

                    if((uint8)(DCM_COM_REQMSGTYPE & DCM_NORMAL_MSG) != (uint8)0)
                    {
                        DCM_COM_APP_MSG_STATE(NetworkHandle) |= DCM_COM_REQSUBSERVICE;
                        DCM_COM_APP_MSG_STATE(NetworkHandle) &= DCM_COM_REQSUBSERVICE;
                    }

                    (void)DCM_CFG_COM_SPECHL_SWITCH_FNC(ChnIdx)(ReqMode);
                    (void)Dcm_Rte_CommunicationMode_CurrentState(NetworkHandle, ReqMode);
                    break;
                }
            }
        }
        break;

    default:
        if(DCM_COM_REQSUBSERVICE == DCM_ENABLE_RX_TX_ENHANCED)
        {
            /*ReqMode = (((DCM_COM_REQMSGTYPE << DCM_SHIFT_2) | DCM_ENABLE_RX_TX) - DCM_COM_MODE_OFFSET);*/
            ReqMode = ((DCM_COM_REQMSGTYPE << DCM_SHIFT_2) - DCM_COM_MODE_OFFSET);/*QAC*/
            TempSubService = DCM_ENABLE_RX_TX;
        }
        else
        {
            ReqMode = (((DCM_COM_REQMSGTYPE << DCM_SHIFT_2) | DCM_ENABLE_RX_DISABLE_TX) - DCM_COM_MODE_OFFSET);
            TempSubService = DCM_ENABLE_RX_DISABLE_TX;
        }

        for(NodeIdx = (uint16)0; NodeIdx < DCM_CFG_COM_SUBNODE_NUM; NodeIdx++)
        {
            /*SWS_Dcm_01077*//*SWS_Dcm_01079*/
            if(DCM_COM_REQSUBNODE == DCM_CFG_COM_SUBNODE_ID(NodeIdx))
            {
                NetworkHandle = DCM_CFG_COM_SUBNODE_CHLREF(NodeIdx);

                if((uint8)(DCM_COM_REQMSGTYPE & DCM_NM_MSG) != (uint8)0)
                {
                    DCM_COM_NM_MSG_STATE(NetworkHandle) |= TempSubService;
                    DCM_COM_NM_MSG_STATE(NetworkHandle) &= (DCM_COM_MODE_OFFSET | TempSubService);
                }

                if((uint8)(DCM_COM_REQMSGTYPE & DCM_NORMAL_MSG) != (uint8)0)
                {
                    DCM_COM_APP_MSG_STATE(NetworkHandle) |= TempSubService;
                    DCM_COM_APP_MSG_STATE(NetworkHandle) &= TempSubService;
                }

                (void)DCM_CFG_COM_SUBNODE_CHL_SWITCH_FNC(NodeIdx)(ReqMode);
                (void)Dcm_Rte_CommunicationMode_CurrentState(NetworkHandle, ReqMode);
                break;
            }
        }
        break;
    }
}
/*PRQA S 4700 --*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_28_ResumeCommunication
*
* Description: This function is used to restore forbidden communication when the
*              session is switched.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DspInternal_28_ResumeCommunication
(
    void
)
{
    uint8 ChnIdx;
    uint8 NetworkHandle;
    Dcm_CommunicationModeType ReqMode;
    uint16 NodeIdx;

    /*SWS_Dcm_00860*/
    if(((!(DCM_CFG_SESSION_MASK(DCM_SES_IDX) & DCM_COM_SERVICE_SESSION)) \
        || (DCM_SES_IDX == DCM_DEFAULT_IDX)) && (DCM_COM_REQSUBSERVICE != DCM_DATA_U8_MAX))
    {
        ReqMode = DCM_ENABLE_RX_TX_NORM_NM;

        /*Restore communication for all channels associated with DcmDspAllComMChannelRef parameters*/
        for(ChnIdx = (uint8)0; ChnIdx < DCM_CFG_COM_ALLCHL_NUM; ChnIdx++)
        {
            NetworkHandle = DCM_CFG_COM_ALLCHL_REF(ChnIdx);

            if((DCM_COM_NM_MSG_STATE(NetworkHandle) != DCM_ENABLE_RX_TX_NM) || (DCM_COM_APP_MSG_STATE(NetworkHandle) != DCM_ENABLE_RX_TX_NORM))
            {
                DCM_COM_NM_MSG_STATE(NetworkHandle) = DCM_ENABLE_RX_TX_NM;
                DCM_COM_APP_MSG_STATE(NetworkHandle) = DCM_ENABLE_RX_TX_NORM;

                (void)DCM_CFG_COM_ALLCHL_SWITCH_FNC(ChnIdx)(ReqMode);
                (void)Dcm_Rte_CommunicationMode_CurrentState(NetworkHandle, ReqMode);
            }
        }

        /*Restore communication for all channels associated with DcmDspSpecificComMChannelRef parameters*/
        for(ChnIdx = (uint8)0; ChnIdx < DCM_CFG_COM_SPECHL_NUM; ChnIdx++)
        {
            NetworkHandle = DCM_CFG_COM_SPECHL_REF(ChnIdx);

            if((DCM_COM_NM_MSG_STATE(NetworkHandle) != DCM_ENABLE_RX_TX_NM) || (DCM_COM_APP_MSG_STATE(NetworkHandle) != DCM_ENABLE_RX_TX_NORM))
            {
                DCM_COM_NM_MSG_STATE(NetworkHandle) = DCM_ENABLE_RX_TX_NM;
                DCM_COM_APP_MSG_STATE(NetworkHandle) = DCM_ENABLE_RX_TX_NORM;
                
                (void)DCM_CFG_COM_SPECHL_SWITCH_FNC(ChnIdx)(ReqMode);
                (void)Dcm_Rte_CommunicationMode_CurrentState(NetworkHandle, ReqMode);
            }
        }

        /*Restore communication for all channels associated with DcmDspComControlSubNodeComMChannelRef parameters*/
        for(NodeIdx = (uint16)0; NodeIdx < DCM_CFG_COM_SUBNODE_NUM; NodeIdx++)
        {
            NetworkHandle = DCM_CFG_COM_SUBNODE_CHLREF(NodeIdx);

            if((DCM_COM_NM_MSG_STATE(NetworkHandle) != DCM_ENABLE_RX_TX_NM) || (DCM_COM_APP_MSG_STATE(NetworkHandle) != DCM_ENABLE_RX_TX_NORM))
            {
                DCM_COM_NM_MSG_STATE(NetworkHandle) = DCM_ENABLE_RX_TX_NM;
                DCM_COM_APP_MSG_STATE(NetworkHandle) = DCM_ENABLE_RX_TX_NORM;

                (void)DCM_CFG_COM_SUBNODE_CHL_SWITCH_FNC(NodeIdx)(ReqMode);
                (void)Dcm_Rte_CommunicationMode_CurrentState(NetworkHandle, ReqMode);
            }
        }

        DCM_COM_REQSUBSERVICE = DCM_DATA_U8_MAX;
    }
}
#endif/*#if(DCM_UDS_28_ENABLED == STD_ON)*/

#if(DCM_UDS_29_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_29_Authentication
*
* Description: This function is the code implementation of the processing logic
*              for the 0x29 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_Authentication
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
    uint16 ConId = DCM_CFG_PCL_CONNECTION_MAIN_CON_ID(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
#endif

    if(OpStatus == DCM_INITIAL)
    {
#if(DCM_UDS_29_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
        ClearSuppressPosRespBit();
#endif

#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
        if(DCM_AU_DELAY_TIMER(ConId) != (uint32)0)
        {
            /*Reset to the previous value*/
            DspInternal_29_UpdateFailedCounterAndStartDelay(ConId, FALSE);
            /*Send negative response with NRC0x37*/
            *pErrorCode = DCM_E_REQUIREDTIMEDELAYNOTEXPIRED;
            Result = E_NOT_OK;
        }
        else
#endif
        {
            /*SWS_Dcm_01551*/
            /*Check whether the length of the request message is correct based on the subservice.*/
            Result = DspInternal_29_CheckSubServiceLength(pMsgContext, pErrorCode);
        }

        /*Matches the entry function of the requested subservice*/
        if(Result == E_OK)
        {
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
            SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
            /*SWS_Dcm_01559*/
            switch(DCM_REQ_SUBSERVICE)
            {
            case DCM_AUTHENTICATION_00:
                DCM_SUBSERVICE_FNC = &(DspInternal_29_00_Processor);
                break;

            case DCM_AUTHENTICATION_01:
            case DCM_AUTHENTICATION_02:
                DCM_SUBSERVICE_FNC = &(DspInternal_29_01_02_Processor);
                break;

            case DCM_AUTHENTICATION_03:
                DCM_SUBSERVICE_FNC = &(DspInternal_29_03_Processor);
                break;

            default:/*DCM_AUTHENTICATION_08*/
                DCM_SUBSERVICE_FNC = &(DspInternal_29_08_Processor);
                break;
            }
        }
    }/*if(OpStatus == DCM_INITIAL)*/

    /*Executive subservice*/
    if(Result == E_OK)
    {
        Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
    }

    /*Send positive response*/
    if(Result == E_OK)
    {
        pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
    }
    else
    {
        if((Result == E_NOT_OK) && (DCM_AU_DEVELOP_ENABLED == FALSE))
        {
            *pErrorCode = DCM_DSP_AUTHENTICATION_GENERAL_NRC;
        }
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_Init_Authentication
*
* Description: This function is used to initialize the variable parameters
*              associated with the 0x29 service.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DspInternal_Init_Authentication
(
    void
)
{
    uint16 ConId;/*ID of Connection*/
#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
    boolean IsAuthenticated = FALSE;
    Std_ReturnType ret = E_OK;
#endif

    DCM_AU_STATE = DCM_AU_STATE_DEAUTHENTICATED;
    DCM_AU_DEVELOP_ENABLED = FALSE;
    DCM_AU_RESULT_IND = FALSE;
    /*SWS_Dcm_01489*/
    DCM_AU_CUR_ROLE = DCM_DSP_DEAUTHENTICATED_ROLE;
    ClearAuthenticationTimer();

#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
    DCM_AU_CHAL_RESP_TIMER = (uint32)0;

    ret = Dcm_RecoveryAuthenticationStoredInfo(&DCM_ACTIVE_PCL_ID, &DCM_ACTIVE_CON_ID, &IsAuthenticated, \
            &DCM_AU_CUR_ROLE, &DCM_AU_FAILED_CNT(0), &DCM_AU_ABSOLUTE_TIMER);
    if(ret == E_OK)
    {
        if(IsAuthenticated == TRUE)
        {
            DCM_AU_STATE = DCM_AU_STATE_AUTHENTICATED;
        }

        for(ConId = (uint16)0; ConId < DCM_CFG_NUM_OF_CONNECTION; ConId++)
        {
            DspInternal_29_UpdateFailedCounterAndStartDelay(ConId, FALSE);
        }
    }
    else
    {
        for(ConId = (uint16)0; ConId < DCM_CFG_NUM_OF_CONNECTION; ConId++)
        {
            DCM_AU_FAILED_CNT(ConId) = (uint32)0;
            DCM_AU_DELAY_TIMER(ConId) = (uint32)0;
        }
        DCM_AU_ABSOLUTE_TIMER = (uint32)0;
    }
#endif

    for(ConId = (uint16)0; ConId < DCM_CFG_NUM_OF_CONNECTION; ConId++)
    {
        /*SWS_Dcm_01489*/
        DCM_AU_DE_ROLE(ConId) = DCM_DSP_DEAUTHENTICATED_ROLE;
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_Reset_Authentication
*
* Description: This function is used to reset the authentication state.
*
* Inputs: AuConId
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DspInternal_Reset_Authentication
(
    uint8 AuConId
)
{
    uint16 ConId = DCM_CFG_PCL_CONNECTION_MAIN_CON_ID(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);

    if((DCM_AU_STATE & DCM_AU_STATE_AUTHENTICATED) != DCM_AU_STATE_DEAUTHENTICATED)
    {
        /*Mode switch indication*/  /* SWS_Dcm_01478 */
        (void)DCM_CFG_AU_MODE_FNC(AuConId)(DCM_DEAUTHENTICATED);
    }

    DCM_AU_STATE = DCM_AU_STATE_DEAUTHENTICATED;
    DCM_AU_RESULT_IND = FALSE;
    /*SWS_Dcm_01485*//*SWS_Dcm_01486*/
    DCM_AU_CUR_ROLE = DCM_AU_DE_ROLE(ConId);
    ClearAuthenticationTimer();
#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
    DCM_AU_CHAL_RESP_TIMER = (uint32)0;
    DCM_AU_ABSOLUTE_TIMER = (uint32)0;
#endif
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_29_CheckSubServiceLength
*
* Description: This function is used to check if the length of the request data
*              is correct.
*
* Inputs: pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_CheckSubServiceLength
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 CertLen;/*Length Of Certificate Client*/
    uint16 ChalLen;/*Length Of Challenge Client*/
    uint16 OwnerLen;/*length Of Proof Of Ownership Client*/
    uint16 PbKeyLen;/*length Of Ephemeral Public Key Client*/
#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
    uint16 ConId = DCM_CFG_PCL_CONNECTION_MAIN_CON_ID(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
#endif

    if((DCM_REQ_SUBSERVICE == DCM_AUTHENTICATION_00) || (DCM_REQ_SUBSERVICE == DCM_AUTHENTICATION_08))
    {
        if((pMsgContext->reqDataLen) != DCM_LENGTH_2_BYTE)
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
    }
    else if((DCM_REQ_SUBSERVICE == DCM_AUTHENTICATION_01) || (DCM_REQ_SUBSERVICE == DCM_AUTHENTICATION_02))
    {
        CertLen = Make16Bit((pMsgContext->reqData[DCM_INDEX_3]), (pMsgContext->reqData[DCM_INDEX_4]));

        /*1 Service + 1 SubService + 1 CommunicationConfiguration + 2 lengthOfCertificateClient + 2 lengthOfChallengeClient = 7 byte*/
        if((CertLen == (uint16)0) || ((pMsgContext->reqDataLen) < (CertLen + DCM_LENGTH_7_BYTE)))
        {
            /*SWS_Dcm_01579*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
            ChalLen = Make16Bit((pMsgContext->reqData[CertLen + DCM_INDEX_5]), (pMsgContext->reqData[CertLen + DCM_INDEX_6]));

            if((pMsgContext->reqDataLen) != ((Dcm_MsgLenType)CertLen + (Dcm_MsgLenType)ChalLen + DCM_LENGTH_7_BYTE))
            {
                /*SWS_Dcm_01460*//*SWS_Dcm_01461*/
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                Result = E_NOT_OK;
            }
            else if((DCM_REQ_SUBSERVICE == DCM_AUTHENTICATION_01) && (ChalLen != (uint16)0))
            {
                /*SWS_Dcm_01460*/
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                Result = E_NOT_OK;
            }
            else if((DCM_REQ_SUBSERVICE == DCM_AUTHENTICATION_02) && (ChalLen == (uint16)0))
            {
                /*SWS_Dcm_01461*/
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                Result = E_NOT_OK;
            }
            else
            {
                /*do nothing*/
            }
        }

#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
        if((Result == E_NOT_OK) && (DCM_AU_STATE == DCM_AU_STATE_DEAUTHENTICATED))
        {
            /*Update the consecutive failed counter value and start delay timer*/
            DspInternal_29_UpdateFailedCounterAndStartDelay(ConId, TRUE);
        }
#endif
    }
    else if(DCM_REQ_SUBSERVICE == DCM_AUTHENTICATION_03)
    {
#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
        /*Stop the Challenge Response timeout timer*/
        DCM_AU_CHAL_RESP_TIMER = (uint32)0;
#endif
        OwnerLen = Make16Bit((pMsgContext->reqData[DCM_INDEX_2]), (pMsgContext->reqData[DCM_INDEX_3]));

        /*1 Service + 1 SubService + 2 lengthOfProofOfOwnershipClient + 2 lengthOfEphemeralPublicKeyClient = 6 byte*/
        if((OwnerLen == (uint16)0) || ((pMsgContext->reqDataLen) < (OwnerLen + DCM_LENGTH_6_BYTE)))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
            PbKeyLen = Make16Bit((pMsgContext->reqData[OwnerLen + DCM_INDEX_4]), (pMsgContext->reqData[OwnerLen + DCM_INDEX_5]));

            if((pMsgContext->reqDataLen) != ((Dcm_MsgLenType)OwnerLen + (Dcm_MsgLenType)PbKeyLen + DCM_LENGTH_6_BYTE))
            {
                /*SWS_Dcm_01510*/
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                Result = E_NOT_OK;
            }
        }

        if(Result == E_NOT_OK)
        {
            DCM_AU_STATE &= DCM_AU_STATE_AUTHENTICATED;

#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
            /*Update the consecutive failed counter value and start delay timer*/
            DspInternal_29_UpdateFailedCounterAndStartDelay(ConId, TRUE);
#endif
        }
    }
    else
    {
        /*Sub service not support*/
        *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        Result = E_NOT_OK;
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_29_00_Processor
*
* Description: This function is used to implement the processing logic of the 00
*              subservices of the 29 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_00_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 AuConId = DCM_CFG_PCL_CONNECTION_MAIN_AU_CONNECTION(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);

    (void)OpStatus;
    (void)pErrorCode;

    /*SWS_Dcm_01561*/
    DspInternal_Reset_Authentication(AuConId);

    /*SWS_Dcm_01565*/
    pMsgContext->resData[DCM_INDEX_2] = DCM_AU_DEAUTHENTICATIONSUCCESSFUL;
    /*Set positive response length*/
    pMsgContext->resDataLen = DCM_LENGTH_3_BYTE;

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_29_01_02_Processor
*
* Description: This function is used to implement the processing logic of the 01
*              and 02 subservices of the 29 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*There is not limit on the number of lines of function code and the number of local variable assignments.*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_01_02_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 AuConId = DCM_CFG_PCL_CONNECTION_MAIN_AU_CONNECTION(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
    KeyM_CertDataType DcmCertData;
#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
    uint16 ConId = DCM_CFG_PCL_CONNECTION_MAIN_CON_ID(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
#endif

    if(OpStatus == DCM_INITIAL)
    {
        /*Reset the execution step information*/
        DCM_CURRENT_EXE_STEP = DCM_DATA_CLEAR;

        if((pMsgContext->reqData[DCM_INDEX_2]) != (uint8)0)
        {
            /*SWS_Dcm_01459*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else
        {
            /*Set the execution step to 1*/
            DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_ONE;
        }
    }

    if(OpStatus != DCM_CANCEL)
    {
        /*Step 1: SWS_Dcm_01463,SWS_Dcm_01468 Store and start verify the client certificate within KeyM module.*/
        if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_ONE)
        {
            Result = DspInternal_29_StartVerifyClientCertificate(pMsgContext, pErrorCode);
        }

        /*Step 2: SWS_Dcm_01467 Wait until the callback has been called, indicating a successful job termination.*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_TWO))
        {
            Result = DspInternal_29_WaitKeyMJobResult(pErrorCode);
        }

        /*Step 3: SWS_Dcm_01588, SWS_Dcm_01493 Create a server challenge by using the Csm*/
        if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_THREE)
        {
            Result = DspInternal_29_CreateServerChallenge(pErrorCode);
        }

        /*Step 4: SWS_Dcm_01467 Wait until the asynchronous Csm job has terminated*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_FOUR))
        {
            Result = DspInternal_29_WaitCsmJobResult(pErrorCode);
        }

        /*Step 5: SWS_Dcm_01504 Sign the received client challenge only for 02 subservice*/
        if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_FIVE)
        {
            Result = DspInternal_29_SignClientChallenge(pMsgContext, pErrorCode);
        }

        /*Step 6: SWS_Dcm_01467 Wait until the asynchronous job has terminated only for 02 subservice*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_SIX))
        {
            Result = DspInternal_29_WaitCsmJobResult(pErrorCode);
        }

        /*Step 7: SWS_Dcm_01506 Get the server certificate only for 02 subservice*/
        if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_SEVEN)
        {
            /*Subtract fixed bytes*/
            DcmCertData.certDataLength = (pMsgContext->resMaxDataLen - DCM_LENGTH_3_BYTE - DCM_LENGTH_8_BYTE);
            /*Subtract the length of challengeServer and proofOfOwnershipServer*/
            DcmCertData.certDataLength -= (DCM_CFG_AU_CHALLENGE_LEN(AuConId) + DCM_AU_DATA_LEN);
            DcmCertData.certData = &(pMsgContext->resData[DCM_CFG_AU_CHALLENGE_LEN(AuConId) + DCM_INDEX_7]);

            Result = KeyM_GetCertificate(DCM_CFG_AU_ECU_CERT(AuConId), &DcmCertData);

            if(Result == E_OK)
            {
                /*Next step: Send positive response*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_OVER;
            }
            else
            {
                /*SWS_Dcm_01466*//*SWS_Dcm_01507*/
                *pErrorCode = DCM_E_GENERALREJECT;
                Result = E_NOT_OK;
            }
        }

        /*Step over: SWS_Dcm_01503, SWS_Dcm_01508 Send positive response*/
        if(Result == E_OK)
        {
            /*authenticationReturnParameter*/
            pMsgContext->resData[DCM_INDEX_2] = DCM_AU_OWNERSHIPVERIFICATIONNECESSARY;
            /*lengtfOfChallengeServer*/
            pMsgContext->resData[DCM_INDEX_3] = (uint8)(DCM_CFG_AU_CHALLENGE_LEN(AuConId) >> DCM_SHIFT_8);
            pMsgContext->resData[DCM_INDEX_4] = (uint8)DCM_CFG_AU_CHALLENGE_LEN(AuConId);
            /*challengeServer*/
            Bsw_MemCpy(&(pMsgContext->resData[DCM_INDEX_5]), DCM_AU_CHALLENGE_PTR, (uint32)DCM_CFG_AU_CHALLENGE_LEN(AuConId));
            /*Update positive response length*/
            pMsgContext->resDataLen = (DCM_CFG_AU_CHALLENGE_LEN(AuConId) + DCM_LENGTH_5_BYTE);

            if(DCM_REQ_SUBSERVICE == DCM_AUTHENTICATION_02)
            {
                /*PRQA S 2962 ++*/
                /*lengthOfCertificateServer, DcmCertData.certDataLength has been assigned a value in the previous step.*/
                pMsgContext->resData[(pMsgContext->resDataLen)] = (uint8)(DcmCertData.certDataLength >> DCM_SHIFT_8);
                /*PRQA S 2962 --*/
                pMsgContext->resData[(pMsgContext->resDataLen + DCM_LENGTH_1_BYTE)] = (uint8)DcmCertData.certDataLength;
                /*Update positive response length*/
                pMsgContext->resDataLen += DCM_LENGTH_2_BYTE;
                /*certificateServer: The data has been written to the response buffer when calling the KeyM_GetCertificate() in the previous step.*/
                /*Update positive response length*/
                pMsgContext->resDataLen += DcmCertData.certDataLength;
                /*lengthOfProofOfOwnershipServer*/
                pMsgContext->resData[(pMsgContext->resDataLen)] = (uint8)(DCM_AU_DATA_LEN >> DCM_SHIFT_8);
                pMsgContext->resData[(pMsgContext->resDataLen + DCM_LENGTH_1_BYTE)] = (uint8)DCM_AU_DATA_LEN;
                /*Update positive response length*/
                pMsgContext->resDataLen += DCM_LENGTH_2_BYTE;
                /*proofOfOwnershipServer*/
                Bsw_MemCpy(&(pMsgContext->resData[(pMsgContext->resDataLen)]), DCM_AU_PROOF_PTR, DCM_AU_DATA_LEN);
                /*Update positive response length*/
                pMsgContext->resDataLen += DCM_AU_DATA_LEN;

                /*Set the authentication state*/
                DCM_AU_STATE &= DCM_AU_STATE_AUTHENTICATED;
                DCM_AU_STATE |= DCM_AU_STATE_CERTIFICATE_B;
            }
            else
            {
                /*Set the authentication state*/
            	DCM_AU_STATE &= DCM_AU_STATE_AUTHENTICATED;
                DCM_AU_STATE |= DCM_AU_STATE_CERTIFICATE_U;
            }
            /*lengthOfEphemeralPublicKeyServer for 01 subervice*//*lengthOfEphemeralPublicKeyServer for 02 subervice*/
            pMsgContext->resData[(pMsgContext->resDataLen)] = (uint8)0;
            pMsgContext->resData[(pMsgContext->resDataLen + DCM_LENGTH_1_BYTE)] = (uint8)0;
            /*Set positive response length*/
            pMsgContext->resDataLen += DCM_LENGTH_2_BYTE;

#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
            /*Start the Challenge Response timeout timer*/
            DCM_AU_CHAL_RESP_TIMER = (uint32)(DCM_DSP_AU_CHALLENGE_RESPONSE_TIME_OUT / DCM_TASK_TIME);
#endif
        }
#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
        else if(Result == E_NOT_OK)
        {
            if(DCM_CURRENT_EXE_STEP >= DCM_EXE_STEP_ONE)
            {
                DspInternal_29_UpdateFailedCounterAndStartDelay(ConId, TRUE);
            }
        }
#endif
        else
        {
            /*do nothing*/
        }
    }

    return Result;
}
/*PRQA S 4700 --*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_29_03_Processor
*
* Description: This function is used to implement the processing logic of the 03
*              subservices of the 29 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_03_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 AuConId = DCM_CFG_PCL_CONNECTION_MAIN_AU_CONNECTION(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
    uint16 ConId = DCM_CFG_PCL_CONNECTION_MAIN_CON_ID(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
#endif

    if(OpStatus == DCM_INITIAL)
    {
        /*Reset the execution step information*/
        DCM_CURRENT_EXE_STEP = DCM_DATA_CLEAR;

        /*The condition in the if expression below come from the "Authenticated state transitions without persistent states"
          state transition table in the Dcm specification.*/
        if((DCM_AU_STATE & (DCM_AU_STATE_CERTIFICATE_U | DCM_AU_STATE_CERTIFICATE_B)) == DCM_AU_STATE_DEAUTHENTICATED)
        {
            /*SWS_Dcm_01509*/
            *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
            Result = E_NOT_OK;
        }
        else
        {
            /*Set the execution step to 1*/
            DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_ONE;
        }
    }

    if(OpStatus != DCM_CANCEL)
    {
        /*Step 1: SWS_Dcm_01511 Verify the client's proof of ownership data */
        if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_ONE)
        {
            Result = DspInternal_29_StartVerifyProof(pMsgContext, pErrorCode);
        }

        /*Step 2: Wait until the callback has been called, indicating a successful job termination.*/
        if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_TWO))
        {
            Result = DspInternal_29_WaitCsmJobResult(pErrorCode);
        }

        /*Step 3: SWS_Dcm_01514 Update the current role*/
        if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_THREE)
        {
            Result = DspInternal_29_ReadRoleElement(pErrorCode);
        }

        /*Step over: Send positive response*/
        if(Result == E_OK)
        {
            /*SWS_Dcm_01529*//*authenticationReturnParameter*/
            pMsgContext->resData[DCM_INDEX_2] = DCM_AU_AUTHENTICATIONCOMPLETE;
            /*SWS_Dcm_01513*//* lengthOfSessionKeyInfo*/
            pMsgContext->resData[DCM_INDEX_3] = (uint8)0;
            pMsgContext->resData[DCM_INDEX_4] = (uint8)0;
            /*Set positive response length*/
            pMsgContext->resDataLen = DCM_LENGTH_5_BYTE;

#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
            /*Clear the consecutive failed counter after valid authentication*/
            DCM_AU_FAILED_CNT(ConId) = (uint16)0;
            /*Start the AbsoluteMaxTime timer*/
            DCM_AU_ABSOLUTE_TIMER = (uint32)(DCM_DSP_AU_ABSOLUTE_MAX_TIME / DCM_TASK_TIME);
#endif
            /*Set the authentication state*/
            DCM_AU_STATE = DCM_AU_STATE_AUTHENTICATED;
            /*Mode switch indication*/  /* SWS_Dcm_01478 */
            (void)DCM_CFG_AU_MODE_FNC(AuConId)(DCM_AUTHENTICATED);
        }
        else if(Result == E_NOT_OK)
        {
#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
            if(DCM_CURRENT_EXE_STEP >= DCM_EXE_STEP_ONE)
            {
                DspInternal_29_UpdateFailedCounterAndStartDelay(ConId, TRUE);
            }
#endif
            DCM_AU_STATE &= DCM_AU_STATE_AUTHENTICATED;
        }
        else
        {
            /*Called in next mainfunction*/
        }
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_29_08_Processor
*
* Description: This function is used to implement the processing logic of the 08
*              subservices of the 29 service.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_08_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    (void)OpStatus;
    (void)pErrorCode;

    /*SWS_Dcm_01533*//*authenticationReturnParameter*/
    pMsgContext->resData[DCM_INDEX_2] = DCM_AU_CONFIGURATIONAPCE;
    /*Set positive response length*/
    pMsgContext->resDataLen = DCM_LENGTH_3_BYTE;

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_29_StartVerifyClientCertificate
*
* Description: This function is used to store and start verify the client certificate.
*
* Inputs: pMsgContext
*
* Outputs: pErrorCode
*
* Return: E_OK, E_NOT_OK, DCM_E_PENDING
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_StartVerifyClientCertificate
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 AuConId = DCM_CFG_PCL_CONNECTION_MAIN_AU_CONNECTION(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
    KeyM_CertDataType DcmCertData;

    DcmCertData.certDataLength = 0U;
    DcmCertData.certData = &(pMsgContext->reqData[DCM_INDEX_5]);
    (void)KeyM_SetCertificate(DCM_CFG_AU_CONNECTION_CERT(AuConId), &DcmCertData);
    DcmCertData.certDataLength = (uint32)Make16Bit((pMsgContext->reqData[DCM_INDEX_3]), (pMsgContext->reqData[DCM_INDEX_4]));
    /*Store the client certificate*/
    Result = KeyM_SetCertificate(DCM_CFG_AU_CONNECTION_CERT(AuConId), &DcmCertData);

    if(Result == E_OK)
    {
        /*Clear the result indication flag*/
        DCM_AU_RESULT_IND = FALSE;
        /*Start verify the certificate*/
        Result = KeyM_VerifyCertificate(DCM_CFG_AU_CONNECTION_CERT(AuConId));

        if(Result == E_OK)
        {
            /*Next step: Wait until the callback has been called, indicating a successful job termination.*/
            DCM_CURRENT_EXE_STEP++;
            /*Jump out of diagnostic execution*/
            Result = DCM_E_PENDING;
        }
        else if(Result == KEYM_E_BUSY)
        {
            /*SWS_Dcm_01465*/
            *pErrorCode = DCM_E_BUSYREPEATREQUEST;
            Result = E_NOT_OK;
        }
        else
        {
            /*SWS_Dcm_01466*/
            *pErrorCode = DCM_E_GENERALREJECT;
            Result = E_NOT_OK;
        }
    }
    else if(Result == KEYM_E_KEY_CERT_SIZE_MISMATCH)
    {
        /*SWS_Dcm_01464*/
        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        Result = E_NOT_OK;
    }
    else
    {
        /*SWS_Dcm_01466*/
        *pErrorCode = DCM_E_GENERALREJECT;
        Result = E_NOT_OK;
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_29_WaitKeyMJobResult
*
* Description: This function is used to wait and check the job result from KeyM.
*
* Inputs: None
*
* Outputs: pErrorCode
*
* Return: E_OK, E_NOT_OK, DCM_E_PENDING
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_WaitKeyMJobResult
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint8 AuConId = DCM_CFG_PCL_CONNECTION_MAIN_AU_CONNECTION(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);

    if(DCM_AU_RESULT_IND == FALSE)
    {
        /*Continue to wait for KeyM feedback result*/
        Result = DCM_E_PENDING;
    }
    else
    {
        if(DCM_AU_CERT_ID == DCM_CFG_AU_CONNECTION_CERT(AuConId))
        {
            if(DCM_AU_CERT_RESULT == KEYM_CERTIFICATE_VALID)
            {
                /*Next step: Create a server challenge*/
                DCM_CURRENT_EXE_STEP++;
                Result = E_OK;
            }
            else if(DCM_AU_CERT_RESULT == KEYM_E_CERTIFICATE_SIGNATURE_FAIL)
            {
                /*SWS_Dcm_01469*/
                *pErrorCode = DCM_E_CERTIFICATEVERIFICATIONFAILED_INVALIDSIGNATURE;
            }
            else if(DCM_AU_CERT_RESULT == KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST)
            {
                /*SWS_Dcm_01470*/
                *pErrorCode = DCM_E_CERTIFICATEVERIFICATIONFAILED_INVALIDCHAINOFTRUST;
            }
            else if(DCM_AU_CERT_RESULT == KEYM_E_CERTIFICATE_INVALID_TYPE)
            {
                /*SWS_Dcm_01471*/
                *pErrorCode = DCM_E_CERTIFICATEVERIFICATIONFAILED_INVALIDTYPE;
            }
            else if(DCM_AU_CERT_RESULT == KEYM_E_CERTIFICATE_INVALID_FORMAT)
            {
                /*SWS_Dcm_01472*/
                *pErrorCode = DCM_E_CERTIFICATEVERIFICATIONFAILED_INVALIDFORMAT;
            }
            else if(DCM_AU_CERT_RESULT == KEYM_E_CERTIFICATE_INVALID_CONTENT)
            {
                /*SWS_Dcm_01473*/
                *pErrorCode = DCM_E_CERTIFICATEVERIFICATIONFAILED_INVALIDSCOPE;
            }
            else if(DCM_AU_CERT_RESULT == KEYM_E_CERTIFICATE_REVOKED)
            {
                /*SWS_Dcm_01475*/
                *pErrorCode = DCM_E_CERTIFICATEVERIFICATIONFAILED_INVALIDCERTIFICATE;
            }
            else if(DCM_AU_CERT_RESULT == KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL)
            {
                /*SWS_Dcm_01476*/
                *pErrorCode = DCM_E_CERTIFICATEVERIFICATIONFAILED_INVALIDTIMEPERIOD;
            }
            else
            {
                /*SWS_Dcm_01466*/
                *pErrorCode = DCM_E_GENERALREJECT;
            }
        }
        else
        {
            /*SWS_Dcm_01466*/
            *pErrorCode = DCM_E_GENERALREJECT;
        }
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_29_CreateServerChallenge
*
* Description: This function is used to create a server challenge.
*
* Inputs: None
*
* Outputs: pErrorCode
*
* Return: E_OK, E_NOT_OK, DCM_E_PENDING
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_CreateServerChallenge
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 AuConId = DCM_CFG_PCL_CONNECTION_MAIN_AU_CONNECTION(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);

    /*Clear the result indication flag*/
    DCM_AU_RESULT_IND = FALSE;
    /*Set the available buffer length for random data*/
    DCM_AU_DATA_LEN = (uint32)DCM_CFG_MAX_CHALLENGE_LENGTH;

    Result = Csm_RandomGenerate(DCM_CFG_AU_RANDOM_JOB(AuConId), DCM_AU_CHALLENGE_PTR, &DCM_AU_DATA_LEN);

    if(Result == E_OK)
    {
        if(DCM_CFG_AU_RANDOM_IS_SYNC(AuConId) == FALSE)
        {
            /*Next step: Wait until the asynchronous Csm job has terminated*/
            DCM_CURRENT_EXE_STEP++;
            /*Jump out of diagnostic execution*/
            Result = DCM_E_PENDING;
        }
        else
        {
            if(DCM_REQ_SUBSERVICE == DCM_AUTHENTICATION_01)
            {
                /*Next step: Send positive response*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_OVER;
            }
            else
            {
                /*Next step: Sign the received client challenge*/
                DCM_CURRENT_EXE_STEP += DCM_EXE_STEP_TWO;
            }
        }
    }
    else if(Result == CRYPTO_E_BUSY)
    {
        /*SWS_Dcm_01465*/
        *pErrorCode = DCM_E_BUSYREPEATREQUEST;
        Result = E_NOT_OK;
    }
    else
    {
        /*SWS_Dcm_01466*/
        *pErrorCode = DCM_E_GENERALREJECT;
        Result = E_NOT_OK;
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_29_WaitCsmJobResult
*
* Description: This function is used to wait and check the job result from Csm.
*
* Inputs: None
*
* Outputs: pErrorCode
*
* Return: E_OK, E_NOT_OK, DCM_E_PENDING
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_WaitCsmJobResult
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 AuConId = DCM_CFG_PCL_CONNECTION_MAIN_AU_CONNECTION(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);

    if(DCM_AU_RESULT_IND == FALSE)
    {
        /*Continue to wait for Csm feedback result*/
        Result = DCM_E_PENDING;
    }
    else
    {
        /*SWS_Dcm_01588*/
        if(DCM_AU_CSM_RESULT == E_OK)
        {
            if((DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_FOUR) && (DCM_AU_DATA_LEN != DCM_CFG_AU_CHALLENGE_LEN(AuConId)))
            {
                /*SWS_Dcm_01466*/
                *pErrorCode = DCM_E_GENERALREJECT;
                Result = E_NOT_OK;
            }
            else if(DCM_REQ_SUBSERVICE == DCM_AUTHENTICATION_01)
            {
                /*Next step: Sending positive response*/
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_OVER;
            }
            else if(DCM_REQ_SUBSERVICE == DCM_AUTHENTICATION_03)
            {
                if(DCM_AU_VERIFY_RESULT == CRYPTO_E_VER_NOT_OK)
                {
                    /*SWS_Dcm_01512*/
                    *pErrorCode = DCM_E_OWNERSHIPVERFICATIONFAILED;
                    Result = E_NOT_OK;
                }
                else
                {
                    /*Next step: Update the current role*/
                    DCM_CURRENT_EXE_STEP++;
                }
            }
            else
            {
                /*Next step: Sign the received client challenge or Get the server certificate*/
                DCM_CURRENT_EXE_STEP++;
            }
        }
        else if(DCM_AU_CSM_RESULT == CRYPTO_E_BUSY)
        {
            /*SWS_Dcm_01465*/
            *pErrorCode = DCM_E_BUSYREPEATREQUEST;
            Result = E_NOT_OK;
        }
        else
        {
            /*SWS_Dcm_01466*/
            *pErrorCode = DCM_E_GENERALREJECT;
            Result = E_NOT_OK;
        }
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_29_SignClientChallenge
*
* Description: This function is used to sign client challenge and get proof of
*              ownership server.
*
* Inputs: pMsgContext
*
* Outputs: pErrorCode
*
* Return: E_NOT_OK, DCM_E_PENDING
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_SignClientChallenge
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 AuConId = DCM_CFG_PCL_CONNECTION_MAIN_AU_CONNECTION(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
    uint16 CertLen;/*Length Of Certificate Client*/
    uint16 ChalLen;/*Length Of Challenge Client*/
    uint8* DataPtr;

    /*Clear the result indication flag*/
    DCM_AU_RESULT_IND = FALSE;
    /*Set the available buffer length for random data*/
    DCM_AU_DATA_LEN = (uint32)DCM_CFG_MAX_PROOF_LENGTH;

    CertLen = Make16Bit((pMsgContext->reqData[DCM_INDEX_3]), (pMsgContext->reqData[DCM_INDEX_4]));
    ChalLen = Make16Bit((pMsgContext->reqData[CertLen + DCM_INDEX_5]), (pMsgContext->reqData[CertLen + DCM_INDEX_6]));
    DataPtr = &(pMsgContext->resData[CertLen + DCM_INDEX_7]);

    Result = Csm_SignatureGenerate(DCM_CFG_AU_SIGN_JOB(AuConId), CRYPTO_OPERATIONMODE_SINGLECALL, \
                                    DataPtr, (uint32)ChalLen, DCM_AU_PROOF_PTR, &DCM_AU_DATA_LEN);

    if(Result == E_OK)
    {
        /*Next step: Wait until the asynchronous job has terminated*/
        DCM_CURRENT_EXE_STEP++;
        /*Jump out of diagnostic execution*/
        Result = DCM_E_PENDING;
    }
    else if(Result == CRYPTO_E_BUSY)
    {
        /*SWS_Dcm_01465*/
        *pErrorCode = DCM_E_BUSYREPEATREQUEST;
        Result = E_NOT_OK;
    }
    else
    {
        /*SWS_Dcm_01466*/
        *pErrorCode = DCM_E_GENERALREJECT;
        Result = E_NOT_OK;
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_29_StartVerifyProof
*
* Description: This function is used to verify the client's proof of ownership
*              data provide in the request.
*
* Inputs: pMsgContext
*
* Outputs: pErrorCode
*
* Return: E_NOT_OK, DCM_E_PENDING
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_StartVerifyProof
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 AuConId = DCM_CFG_PCL_CONNECTION_MAIN_AU_CONNECTION(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
    uint16 OwnerLen;/*length Of Proof Of Ownership Client*/

    /*Clear the result indication flag*/
    DCM_AU_RESULT_IND = FALSE;
    /*Set the available buffer length for random data*/
    DCM_AU_DATA_LEN = (uint32)DCM_CFG_MAX_PROOF_LENGTH;

    OwnerLen = Make16Bit((pMsgContext->reqData[DCM_INDEX_2]), (pMsgContext->reqData[DCM_INDEX_3]));

    Result = Csm_SignatureVerify(DCM_CFG_AU_VERIFY_JOB(AuConId), CRYPTO_OPERATIONMODE_SINGLECALL, DCM_AU_CHALLENGE_PTR, \
                                (uint32)DCM_CFG_AU_CHALLENGE_LEN(AuConId), &(pMsgContext->reqData[DCM_INDEX_4]), (uint32)OwnerLen, &DCM_AU_VERIFY_RESULT);

    if(Result == E_OK)
    {
        /*Next step: Wait until the asynchronous job has terminated*/
        DCM_CURRENT_EXE_STEP++;
        /*Jump out of diagnostic execution*/
        Result = DCM_E_PENDING;
    }
    else if(Result == CRYPTO_E_BUSY)
    {
        /*SWS_Dcm_01465*/
        *pErrorCode = DCM_E_BUSYREPEATREQUEST;
        Result = E_NOT_OK;
    }
    else
    {
        /*SWS_Dcm_01466*/
        *pErrorCode = DCM_E_GENERALREJECT;
        Result = E_NOT_OK;
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_29_ReadRoleElement
*
* Description: This function is used to read role info from the certificate.
*
* Inputs: None
*
* Outputs: pErrorCode
*
* Return: E_NOT_OK, DCM_E_PENDING
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_29_ReadRoleElement
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 AuConId = DCM_CFG_PCL_CONNECTION_MAIN_AU_CONNECTION(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
    KeyM_CertificateIdType CertId = (KeyM_CertificateIdType)(DCM_CFG_AU_ROLE_REF(AuConId) >> DCM_SHIFT_16);
    KeyM_CertElementIdType CertElementId = (KeyM_CertElementIdType)(DCM_CFG_AU_ROLE_REF(AuConId));
    uint8 RoleData[DCM_DSP_AUTHENTICATION_ROLE_SIZE];
    uint32 RoleLength = (uint32)DCM_DSP_AUTHENTICATION_ROLE_SIZE;

    Result = KeyM_CertElementGet(CertId, CertElementId, RoleData, &RoleLength);

    if(Result == E_OK)
    {
        /*SWS_Dcm_CONSTR_06088*/
        if(RoleLength == (uint32)DCM_DSP_AUTHENTICATION_ROLE_SIZE)
        {
            /*SWS_Dcm_01521*/
#if(DCM_DSP_AUTHENTICATION_ROLE_SIZE >= 1)
            DCM_AU_CUR_ROLE = (Dcm_AuRoleMaskType)(RoleData[DCM_INDEX_0]);
#endif
#if(DCM_DSP_AUTHENTICATION_ROLE_SIZE >= 2)
            DCM_AU_CUR_ROLE |= ((Dcm_AuRoleMaskType)(RoleData[DCM_INDEX_1]) << DCM_SHIFT_8);
#endif
#if(DCM_DSP_AUTHENTICATION_ROLE_SIZE >= 3)
            DCM_AU_CUR_ROLE |= ((Dcm_AuRoleMaskType)(RoleData[DCM_INDEX_2]) << DCM_SHIFT_16);
#endif
#if(DCM_DSP_AUTHENTICATION_ROLE_SIZE >= 4)
            DCM_AU_CUR_ROLE |= ((Dcm_AuRoleMaskType)(RoleData[DCM_INDEX_3]) << DCM_SHIFT_24);
#endif

            /*Next step: Send positive response*/
            DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_OVER;
        }
        else
        {
            /*SWS_Dcm_01515*/
            *pErrorCode = DCM_E_CERTIFICATEVERIFICATIONFAILED_INVALIDCONTENT;
            Result = E_NOT_OK;
        }
    }
    else
    {
        /*SWS_Dcm_01466*/
        *pErrorCode = DCM_E_GENERALREJECT;
        Result = E_NOT_OK;
    }

    return Result;
}

#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_29_UpdateFailedCounterAndStartDelay
*
* Description: This function is used to update the consecutive failed counter
*              value and start delay timer.
*
* Inputs: ConId: Connection ID
*         UpdateFailedCounter:TRUE means update counter and start delay
*                             FALSE means only resart delay
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DspInternal_29_UpdateFailedCounterAndStartDelay
(
    uint16 ConId,
    boolean UpdateFailedCounter
)
{
    if(DCM_AU_FAILED_CNT(ConId) >= DCM_AU_FAILED_COUNTER_MAX_VALUE)
    {
        DCM_AU_DELAY_TIMER(ConId) = (uint32)(DCM_AU_MAX_DELAY_TIME / (uint32)DCM_TASK_TIME);
    }
    else
    {
        if(UpdateFailedCounter == TRUE)
        {
            DCM_AU_FAILED_CNT(ConId)++;
        }
        DCM_AU_DELAY_TIMER(ConId) = (uint32)(DCM_AU_INITIAL_DELAY_TIME * (uint32)DCM_AU_FAILED_CNT(ConId));
        DCM_AU_DELAY_TIMER(ConId) /= (uint32)DCM_TASK_TIME;
    }
}
#endif
#endif/*#if(DCM_UDS_29_ENABLED == STD_ON)*/

#if(DCM_UDS_2A_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2A_ReadDataByPeriodicIdentifier SWS_Dcm_01613
*
* Description: This function is the code implementation of the processing logic
*              for the 0x2A service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2A_ReadDataByPeriodicIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 TransmissionMode;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_DID_COUNTER = (uint16)0;
        DCM_DID_POS = (uint16)0;
        TransmissionMode = (pMsgContext->reqData[DCM_INDEX_1]);

        if((pMsgContext->reqDataLen - DCM_LENGTH_2_BYTE) > (Dcm_MsgLenType)DCM_CFG_DSP_MAX_PERIODIC_DID_READ)
        {
            /*SWS_Dcm_00843*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else if((TransmissionMode != DCM_2A_STOPSENDING) && ((pMsgContext->reqDataLen) < DCM_LENGTH_3_BYTE))
        {
            /*SWS_Dcm_01093*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else if((TransmissionMode < DCM_2A_SENDATSLOWRATE) || (TransmissionMode > DCM_2A_STOPSENDING))
        {
            /*SWS_Dcm_01094*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        /*PRQA S 2880,2992 ++*/
        /*Prevent parameters DCM_CFG_2A_SLOW_RATE/DCM_CFG_2A_MEDIUM_RATE/DCM_CFG_2A_FAST_RATE from being configured to 0.*/
        else if(((TransmissionMode == DCM_2A_SENDATSLOWRATE) && (DCM_CFG_2A_SLOW_RATE == (uint16)0)) \
            || ((TransmissionMode == DCM_2A_SENDATMEDIUMRATE) && (DCM_CFG_2A_MEDIUM_RATE == (uint16)0)) \
            || ((TransmissionMode == DCM_2A_SENDATFASTRATE) && (DCM_CFG_2A_FAST_RATE == (uint16)0)))
        {
            /*SWS_Dcm_01094*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        /*PRQA S 2880,2992 --*/
        else
        {
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
            SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
            switch(TransmissionMode)
            {
            case DCM_2A_SENDATSLOWRATE:
            case DCM_2A_SENDATMEDIUMRATE:
            case DCM_2A_SENDATFASTRATE:
                DCM_SUBSERVICE_FNC = &(DspInternal_2A_RequestSending);
                break;

            default:
                DCM_SUBSERVICE_FNC = &(DspInternal_2A_StopSending);
                break;
            }
        }
    }/*if(OpStatus == DCM_INITIAL)*/
    
    if((OpStatus != DCM_CANCEL) && (Result == E_OK))
    {
        Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
    }

    if(Result == E_OK)
    {
        pMsgContext->resDataLen = DCM_LENGTH_1_BYTE;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_Reset_PeriodicDid
*
* Description: This function is used to initialize or reset the variable parameters
*              associated with the 0x2A service.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DspInternal_Reset_PeriodicDid
(
    void
)
{
    uint8 SchIdx;/*Index of periodic did schedulers*/

    DCM_PERIODIC_SCHEDULE_INDEX = DCM_DATA_CLEAR;
    DCM_PERIODIC_SCHEDULE_USEDNUM = DCM_DATA_CLEAR;

    for(SchIdx = (uint8)0; SchIdx < DCM_CFG_2A_MAX_SCHEDULER; SchIdx++)
    {
        DspInternal_2A_StopOneScheduler(SchIdx);
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2A_StopSending
*
* Description: This function is called when a StopSending request is received
*              to stop the periodic sending process of one or all DIDs.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: E_OK, E_NOT_OK
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2A_StopSending
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    Dcm_MsgLenType DataIdx;
    uint8 SchIdx;
    uint8 ReqDid;

    (void)OpStatus;

    /*SWS_Dcm_01100*/
    if((pMsgContext->reqDataLen) == DCM_LENGTH_2_BYTE)
    {
        DspInternal_Reset_PeriodicDid();
    }
    else
    {
        Result = E_NOT_OK;

        for(DataIdx = (Dcm_MsgLenType)DCM_INDEX_2; DataIdx < (pMsgContext->reqDataLen); DataIdx++)
        {
            ReqDid = (pMsgContext->reqData[DataIdx]);
            for(SchIdx = (uint8)0; SchIdx < DCM_CFG_2A_MAX_SCHEDULER; SchIdx++)
            {
                if((ReqDid == DCM_PERIODIC_DID(SchIdx)) && (DCM_PERIODIC_RATE(SchIdx) != DCM_2A_STOPSENDING))
                {
                    DspInternal_2A_StopOneScheduler(SchIdx);
                    
                    Result = E_OK;
                }
            }
        }

        if(Result == E_NOT_OK)
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2A_StopOneScheduler
*
* Description: This function is used to stop the periodic sending process of Did.
*
* Inputs: SchIdx: Index of one periodic did scheduler
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DspInternal_2A_StopOneScheduler
(
    uint8 SchIdx
)
{
    DCM_PERIODIC_DID(SchIdx) = DCM_DATA_CLEAR;
    DCM_PERIODIC_DID_INDEX(SchIdx) = DCM_DATA_CLEAR;
    DCM_PERIODIC_TIMER(SchIdx) = DCM_DATA_CLEAR;
    DCM_PERIODIC_RATE(SchIdx) = DCM_2A_STOPSENDING;

    if(DCM_PERIODIC_SCHEDULE_USEDNUM > (uint8)0)
    {
        DCM_PERIODIC_SCHEDULE_USEDNUM--;
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2A_SetRateTimer
*
* Description: This function resets the Scheduler's timer
*
* Inputs: SchIdx
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DspInternal_2A_SetRateTimer
(
    uint8 SchIdx
)
{
    switch(DCM_PERIODIC_RATE(SchIdx))
    {
    case DCM_2A_SENDATSLOWRATE:
        DCM_PERIODIC_TIMER(SchIdx) = (DCM_CFG_2A_SLOW_RATE / (uint16)DCM_TASK_TIME);
        break;

    case DCM_2A_SENDATMEDIUMRATE:
        DCM_PERIODIC_TIMER(SchIdx) = (DCM_CFG_2A_MEDIUM_RATE / (uint16)DCM_TASK_TIME);
        break;

    case DCM_2A_SENDATFASTRATE:
        DCM_PERIODIC_TIMER(SchIdx) = (DCM_CFG_2A_FAST_RATE / (uint16)DCM_TASK_TIME);
        break;

    default:
        DCM_PERIODIC_TIMER(SchIdx) = DCM_DATA_CLEAR;
        break;
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2A_RequestSending
*
* Description: This function is used to implement the 01,02,03 sub-service request
*              for the 2A service: check that DID is supported and readable, and
*              set the periodic send timer.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2A_RequestSending
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    Dcm_MsgLenType DataIdx;
    uint16 ReqDid;
    uint16 DidIdx;
    uint8 SchIdx;/*Index of scheduler*/
    uint8 TransmissionMode = (pMsgContext->reqData[DCM_INDEX_1]);

    (void)OpStatus;

    if((pMsgContext->reqDataLen - DCM_LENGTH_2_BYTE) > ((Dcm_MsgLenType)DCM_CFG_2A_MAX_SCHEDULER - (Dcm_MsgLenType)DCM_PERIODIC_SCHEDULE_USEDNUM))
    {
        /*SWS_Dcm_00851*/
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        Result = E_NOT_OK;
    }
    else
    {
        for(DataIdx = DCM_INDEX_2; DataIdx < (pMsgContext->reqDataLen); DataIdx++)
        {
            ReqDid = Make16Bit(DCM_2A_HIGHBYTE, (pMsgContext->reqData[DataIdx]));
            Result = DspInternal_22_CheckReadDid(ReqDid, pErrorCode, &DidIdx);
            if(Result == E_OK)
            {
                DCM_DID_INDEX_LIST[DCM_DID_COUNTER] = DidIdx;
                DCM_DID_COUNTER++;
            }
            else if((Result == E_NOT_OK) && (*pErrorCode != DCM_POS_RESP))
            {
                break;
            }
            else
            {
                /*Continue to check the next request DID*/
                Result = E_OK;
            }
        }
    }

    if((Result == E_OK) && (DCM_DID_COUNTER == (uint16)0))
    {
        /*SWS_Dcm_01095*//*SWS_Dcm_00721*/
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        Result = E_NOT_OK;
    }

    /*Put the valid Did into the Scheduler*/
    if(Result == E_OK)
    {
        for(DidIdx = (uint16)0; DidIdx < DCM_DID_COUNTER; DidIdx++)
        {
            /*Check if requested Did currently in the periodic scheduler*/
            for(SchIdx = (uint8)0; SchIdx < DCM_CFG_2A_MAX_SCHEDULER; SchIdx++)
            {
                if((DCM_PERIODIC_DID_INDEX(SchIdx) == DCM_DID_INDEX_LIST[DidIdx]) && (DCM_PERIODIC_RATE(SchIdx) != DCM_2A_STOPSENDING))
                {
                    DCM_PERIODIC_RATE(SchIdx) = TransmissionMode;
                    Result = E_OK;
                    break;
                }
            }
            /*Requested Did not currently in the periodic scheduler*/
            if(SchIdx >= DCM_CFG_2A_MAX_SCHEDULER)
            {
                for(SchIdx = (uint8)0; SchIdx < DCM_CFG_2A_MAX_SCHEDULER; SchIdx++)
                {
                    if(DCM_PERIODIC_RATE(SchIdx) == DCM_2A_STOPSENDING)
                    {
                        DCM_PERIODIC_DID(SchIdx) = ((uint8)DCM_CFG_DID_ID(DCM_DID_INDEX_LIST[DidIdx]));
                        DCM_PERIODIC_DID_INDEX(SchIdx) = DCM_DID_INDEX_LIST[DidIdx];
                        DCM_PERIODIC_RATE(SchIdx) = TransmissionMode;
                        /*Set the periodic timer*/
                        DspInternal_2A_SetRateTimer(SchIdx);
                        /*Added 1 to occupied schedulers*/
                        if(DCM_PERIODIC_SCHEDULE_USEDNUM < DCM_CFG_2A_MAX_SCHEDULER)
                        {
                            DCM_PERIODIC_SCHEDULE_USEDNUM++;
                        }
                        break;
                    }
                }
            }
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2A_PeriodicTransmission
*
* Description: This function is called in the main function to periodically send
*              the DID started by the 2A service.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DspInternal_2A_PeriodicTransmission
(
    void
)
{
    uint8 SchIdx;/*Index of scheduler*/
    uint8 ConIdx;/*Index of connection*/
    uint8 SchStartIdx;
    uint16 DidIndex;
    PduIdType DcmTxPduId;
    PduInfoType PduInfo;
    boolean TransmitFlag;
    Dcm_NegativeResponseCodeType ErrorCode = DCM_POS_RESP;

    /*Manage the rate timer*/
    for(SchIdx = (uint8)0; SchIdx < DCM_CFG_2A_MAX_SCHEDULER; SchIdx++)
    {
        if((DCM_PERIODIC_RATE(SchIdx) != DCM_2A_STOPSENDING) && (DCM_PERIODIC_TIMER(SchIdx) != DCM_DATA_CLEAR))
        {
            DCM_PERIODIC_TIMER(SchIdx)--;
        }
    }

    /*Transmit periodic pdu*/
    if((DCM_CURRENT_DID_SERVICE == DCM_DATA_CLEAR) || (DCM_CURRENT_DID_SERVICE == DCM_2A_SERVICE))
    {
        DCM_CURRENT_DID_SERVICE = DCM_2A_SERVICE;
        SchStartIdx = DCM_PERIODIC_SCHEDULE_INDEX;

        for(ConIdx = (uint8)0; ConIdx < DCM_CFG_PCL_CONNECTION_PERIODIC_NUM(DCM_ACTIVE_PCL_ID, 0U); ConIdx++)
        {
            do
            {
                TransmitFlag = FALSE;
                /*SWS_Dcm_01113*//*SWS_Dcm_01114*//*SWS_Dcm_01117*/
                if((DCM_PERIODIC_RATE(DCM_PERIODIC_SCHEDULE_INDEX) != DCM_2A_STOPSENDING) \
                    && (DCM_PERIODIC_TIMER(DCM_PERIODIC_SCHEDULE_INDEX) == DCM_DATA_CLEAR))
                {
                    TransmitFlag = TRUE;
                    /*SWS_Dcm_01102*/
                    DspInternal_2A_SetRateTimer(DCM_PERIODIC_SCHEDULE_INDEX);
                    DidIndex = DCM_PERIODIC_DID_INDEX(DCM_PERIODIC_SCHEDULE_INDEX);
                    DCM_DID_RESP_LEN = DCM_DATA_CLEAR;
                    DCM_DID_DATA_LEN = (uint16)DCM_LENGTH_2_BYTE;
                    /*SWS_Dcm_00122*/
                    DCM_DID_RESP_DATA = DCM_PERIODIC_BUFFER(DCM_PERIODIC_SCHEDULE_INDEX);
                    DCM_DID_RESP_DATA[DCM_INDEX_1] = DCM_PERIODIC_DID(DCM_PERIODIC_SCHEDULE_INDEX);
                    DCM_DID_RESP_DATA = &DCM_DID_RESP_DATA[DCM_DID_DATA_LEN];
                    /*Start reading*/
                    DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_ONE;
                    DCM_DID_OPSTATUS = DCM_INITIAL;
                    /*SWS_Dcm_01106*/
#if(DCM_UDS_2C_ENABLED == STD_ON)
                    if((TRUE == DCM_CFG_DID_INFO_DYN_DEF(DidIndex)) \
                        && (TRUE == DCM_DDDID_DEFINED(DCM_CFG_DID_INFO_DDDID_BUF_IDX(DidIndex))))
                    {
                        /*Max length of IF-PDUs is 8U for Can,and 64U for CanFD.*/
                        (void)DspInternal_DDDidReadAllRefData(DidIndex, (uint32)DCM_PERIODIC_BUFFER_LEN, &ErrorCode);
                    }
                    else if(TRUE == DCM_CFG_DID_INFO_DYN_DEF(DidIndex))
                    {
                        TransmitFlag = FALSE;
                        DspInternal_2A_StopOneScheduler(DCM_PERIODIC_SCHEDULE_INDEX);
                    }
                    else
#endif
                    {
                        (void)DspInternal_DidReadAllRefData(DidIndex, (uint32)DCM_PERIODIC_BUFFER_LEN, &ErrorCode);
                    }

                    if(TransmitFlag == TRUE)
                    {
                        /*SWS_Dcm_01105*//*Transmit IF-PDU*/
                        PduInfo.SduDataPtr = &(DCM_PERIODIC_BUFFER(DCM_PERIODIC_SCHEDULE_INDEX)[DCM_INDEX_1]);
                        PduInfo.MetaDataPtr = NULL_PTR;
                        PduInfo.SduLength = (PduLengthType)(DCM_DID_DATA_LEN - DCM_LENGTH_1_BYTE);
                        /*SWS_Dcm_01101*/
                        DcmTxPduId = DCM_CFG_PCL_CONNECTION_PERIODIC_TX_PDUID(DCM_ACTIVE_PCL_ID, 0U, ConIdx);
                        /*SWS_Dcm_01072*//*SWS_Dcm_00125*//*SWS_Dcm_01118*/
                        (void)DcmTransmit(DcmTxPduId, &PduInfo);
                    }
                }
                else
                {
                    /*do nothing*/
                }
                DCM_PERIODIC_SCHEDULE_INDEX++;

                if(DCM_PERIODIC_SCHEDULE_INDEX >= DCM_CFG_2A_MAX_SCHEDULER)
                {
                    DCM_PERIODIC_SCHEDULE_INDEX = DCM_DATA_CLEAR;
                }
            }
            while((TransmitFlag == FALSE) && (SchStartIdx != DCM_PERIODIC_SCHEDULE_INDEX));

            if(SchStartIdx == DCM_PERIODIC_SCHEDULE_INDEX)
            {
                break;
            }
        }
        DCM_CURRENT_DID_SERVICE = DCM_DATA_CLEAR;
    }
}
#endif/*#if(DCM_UDS_2A_ENABLED == STD_ON)*/

#if(DCM_UDS_2C_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2C_DynamicallyDefineDataIdentifier SWS_Dcm_00259
*
* Description: This function is the code implementation of the processing logic
*              for the 0x2C service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_DynamicallyDefineDataIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 AddrSizeFormat;
    uint8 AddrLength;
    uint8 SizeLength;

    if(OpStatus == DCM_INITIAL)
    {
#if(DCM_UDS_2C_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
        ClearSuppressPosRespBit();
#endif
        /*SWS_Dcm_00272 Trigger NRC 0x13 when the analysis of the request message results in formatting or length failure.*/
        if((DCM_REQ_SUBSERVICE == DCM_2C_BY_IDENTIFIER) && (((pMsgContext->reqDataLen) < DCM_LENGTH_8_BYTE) \
            || (((pMsgContext->reqDataLen) % DCM_LENGTH_4_BYTE) != DCM_DATA_CLEAR)))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else if(DCM_REQ_SUBSERVICE == DCM_2C_BY_MEMORYADDR)
        {
            AddrSizeFormat = (pMsgContext->reqData[DCM_INDEX_4]);
            AddrLength = (AddrSizeFormat & DCM_MEM_FORMAT_ADDR_MASK);
            SizeLength = ((AddrSizeFormat & DCM_MEM_FORMAT_SIZE_MASK) >> DCM_SHIFT_4);

            if((pMsgContext->reqDataLen) < DCM_LENGTH_7_BYTE)
            {
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                Result = E_NOT_OK;
            }
            else if((AddrLength == (uint8)0) || (SizeLength == (uint8)0))
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else if(((pMsgContext->reqDataLen - DCM_LENGTH_5_BYTE) % ((Dcm_MsgLenType)AddrLength + (Dcm_MsgLenType)SizeLength)) != (Dcm_MsgLenType)0)
            {
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                Result = E_NOT_OK;
            }
            else
            {
                /*Continue*/
            }
        }
        else if((DCM_REQ_SUBSERVICE == DCM_2C_CLEAR_DDDID) && (((pMsgContext->reqDataLen) % DCM_LENGTH_2_BYTE) != DCM_DATA_CLEAR))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
            /*Continue*/
        }

        if(Result == E_OK)
        {
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
            SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
            switch(DCM_REQ_SUBSERVICE)
            {
            case DCM_2C_BY_IDENTIFIER:
                DCM_SUBSERVICE_FNC = &(DspInternal_2C_01_Processor);
                break;

            case DCM_2C_BY_MEMORYADDR:
                DCM_SUBSERVICE_FNC = &(DspInternal_2C_02_Processor);
                break;

            default:
                DCM_SUBSERVICE_FNC = &(DspInternal_2C_03_Processor);
                break;
            }
        }
    }
    
    if((OpStatus != DCM_CANCEL) && (Result == E_OK))
    {
        Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
    }

    if(Result == E_OK)
    {
        if((pMsgContext->reqDataLen) > DCM_LENGTH_2_BYTE)
        {
            pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
            pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
            pMsgContext->resData[DCM_INDEX_3] = pMsgContext->reqData[DCM_INDEX_3];
            pMsgContext->resDataLen = DCM_LENGTH_4_BYTE;
        }
        else
        {
            pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
            pMsgContext->resDataLen = DCM_LENGTH_2_BYTE;
        }
    }
    else
    {
        /*Result = E_NOT_OK/DCM_E_PENDING*/
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_Reset_DynamicDid
*
* Description: This function is the used to reset all dinamic defined Dids.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DspInternal_Reset_DynamicDid
(
    void
)
{
    uint16 DidIdx;
    uint16 BufIdx;
    uint16 EleIdx = (uint16)0;/*Element index*/

    for(DidIdx = (uint16)0; DidIdx < DCM_CFG_DID_NUM; DidIdx++)
    {
        if(TRUE == DCM_CFG_DID_INFO_DYN_DEF(DidIdx))
        {
            BufIdx = DCM_CFG_DID_INFO_DDDID_BUF_IDX(DidIdx);
            DCM_DDDID_INDEX(BufIdx) = DidIdx;
            /*PRQA S 2934 ++*/
            /*The tool calculates a total that is guaranteed not to overflow.*/
            DCM_DDDID_ELE_PTR(BufIdx) = &(DCM_DDDID_ELEMENT(EleIdx));
            /*PRQA S 2934 --*/
            /*SWS_Dcm_00866*/
            DspInternal_2C_ClearOneDDDID(BufIdx);

            EleIdx += DCM_CFG_DID_INFO_DDDID_MAX_ELE(DidIdx);
        }
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2C_CheckDDDID
*
* Description: This function checks whether the requested dynamic definition DID
*              is supported and readable.
*
* Inputs: pMsgContext
*
* Outputs: DDDidPos, pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_CheckDDDID
(
    P2VAR(uint16, AUTOMATIC, DCM_VAR) DDDidPos,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint16 Idx;/*Index of the index of the DDDID*/
    uint16 DidIdx;/*Index of the DDDID*/
    uint16 DDDid;
    uint8 ReqElements;
    uint8 RemainElements;
    uint8 AddrSizeFormat;
    uint8 AddrLength;
    uint8 SizeLength;

    uint8 SupportAddress;
    Dcm_SessionMaskType SesLevelRef;
#if(DCM_UDS_27_ENABLED == STD_ON)
    Dcm_SecurityMaskType SecLevelRef;
    Dcm_SecurityMaskType CurSecMask;
#endif

    DDDid = Make16Bit(pMsgContext->reqData[DCM_INDEX_2], pMsgContext->reqData[DCM_INDEX_3]);
    for(Idx = (uint16)0; Idx < DCM_CFG_DDDID_NUM; Idx++)
    {
        DidIdx = DCM_DDDID_INDEX(Idx);
        if((DDDid == DCM_CFG_DID_ID(DidIdx)) && (TRUE == DCM_CFG_DID_USED(DidIdx)))
        {
            *DDDidPos = Idx;
            RemainElements = (DCM_CFG_DID_INFO_DDDID_MAX_ELE(DidIdx) - DCM_DDDID_ELE_USED_NUM(Idx));

            if(DCM_REQ_SUBSERVICE == DCM_2C_BY_IDENTIFIER)
            {
                ReqElements = (uint8)(((pMsgContext->reqDataLen) / DCM_LENGTH_4_BYTE) - DCM_LENGTH_1_BYTE);
            }
            else
            {
                AddrSizeFormat = (pMsgContext->reqData[DCM_INDEX_4]);
                AddrLength = (AddrSizeFormat & DCM_MEM_FORMAT_ADDR_MASK);
                SizeLength = ((AddrSizeFormat & DCM_MEM_FORMAT_SIZE_MASK) >> DCM_SHIFT_4);
                /*PRQA S 2834 ++*/
                /*AddrLength and SizeLength have been verified in the DspInternal_2C_DynamicallyDefineDataIdentifier.*/
                ReqElements = (uint8)((pMsgContext->reqDataLen - DCM_LENGTH_5_BYTE) / ((Dcm_MsgLenType)AddrLength + (Dcm_MsgLenType)SizeLength));
                /*PRQA S 2834 --*/
            }

            if(ReqElements <= RemainElements)
            {
                Result = E_OK;
            }
            break;
        }
    }

    if(Result == E_NOT_OK)
    {
        /*SWS_Dcm_00861*/
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    else/*Check Address,Session and Security of DDDID*/
    {
        SupportAddress = (DCM_CFG_DID_INFO_READ(DidIdx)->DcmDspDidReadSupportAddress);
        SesLevelRef = (DCM_CFG_DID_INFO_READ(DidIdx)->DcmDspDidReadSessionRef);
#if(DCM_UDS_27_ENABLED == STD_ON)
        CurSecMask = DslInternal_GetSecurityMask();
        SecLevelRef = (DCM_CFG_DID_INFO_READ(DidIdx)->DcmDspDidReadSecurityLevelRef);
#endif
        if(!(SupportAddress & ((uint8)0x01 << (pMsgContext->msgAddInfo.reqType))))
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
#if(DCM_UDS_10_ENABLED == STD_ON)
        else if(!(DCM_CFG_SESSION_MASK(DCM_SES_IDX) & SesLevelRef))
        {
            /*SWS_Dcm_00723*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
        else if(!(CurSecMask & SecLevelRef))
        {
            /*SWS_Dcm_00724*/
            *pErrorCode = DCM_E_SECURITYACCESSDENIED;
            Result = E_NOT_OK;
        }
#endif
        else
        {
            /*do nothing*/
        }
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2C_01_Processor
*
* Description: This function is used to implement the 01 sub-service function of
*              the 2C service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_01_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 DDDidPos;
    Dcm_MsgLenType DataIdx;
    uint16 DidIdx;
    uint16 SigIdx;
    uint16 SourceDid;
    uint16 DataPos;
    uint16 DataRef;
    uint8 DataSize;
    uint8 SupportAddress;
    Dcm_SessionMaskType SesLevelRef;
#if(DCM_UDS_27_ENABLED == STD_ON)
    Dcm_SecurityMaskType SecLevelRef;
    Dcm_SecurityMaskType CurSecMask;
#endif

    (void)OpStatus;

    Result = DspInternal_2C_CheckDDDID(&DDDidPos, pMsgContext, pErrorCode);
    /*Check ID,DataPosition,Address,Session and Security of Source DID*/
    if(Result == E_OK)
    {
        for(DataIdx = DCM_LENGTH_4_BYTE; DataIdx < (pMsgContext->reqDataLen); DataIdx += DCM_LENGTH_4_BYTE)
        {
            SourceDid = Make16Bit(pMsgContext->reqData[DataIdx], pMsgContext->reqData[DataIdx + DCM_LENGTH_1_BYTE]);
            DataPos = (pMsgContext->reqData[DataIdx + DCM_LENGTH_2_BYTE]);
            /*PRQA S 3415 ++*/
            /*DspInternal_2C_SearchSourceDid no need to be excuted if DataPos equals to 0.*/
            if((DataPos != DCM_DATA_CLEAR) && (E_OK == DspInternal_2C_SearchSourceDid(SourceDid, &DidIdx)))
            /*PRQA S 3415 --*/
            {
                /* Check address&session&security of Source DID*/
                SupportAddress = (DCM_CFG_DID_INFO_READ(DidIdx)->DcmDspDidReadSupportAddress);
                SesLevelRef = (DCM_CFG_DID_INFO_READ(DidIdx)->DcmDspDidReadSessionRef);
#if(DCM_UDS_27_ENABLED == STD_ON)
                CurSecMask = DslInternal_GetSecurityMask();
                SecLevelRef = (DCM_CFG_DID_INFO_READ(DidIdx)->DcmDspDidReadSecurityLevelRef);
#endif
                if(!(SupportAddress & ((uint8)0x01 << (pMsgContext->msgAddInfo.reqType))))
                {
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
#if(DCM_UDS_10_ENABLED == STD_ON)
                else if(!(DCM_CFG_SESSION_MASK(DCM_SES_IDX) & SesLevelRef))
                {
                    /*SWS_Dcm_00725*/
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
                else if(!(CurSecMask & SecLevelRef))
                {
                    /*SWS_Dcm_00726*/
                    *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
#endif
                else
                {
                    /*Converte byte position*/
                    DataPos = (DataPos - (uint16)DCM_INDEX_1);
                    /*unit:byte*/
                    DataSize = (pMsgContext->reqData[DataIdx + DCM_LENGTH_3_BYTE]);

                    /*Check data position and data size*/
                    for(SigIdx = (uint16)0; SigIdx < DCM_CFG_DID_SIG_NUM(DidIdx); SigIdx++)
                    {
                        DataRef = DCM_CFG_DID_SIG_REF(DidIdx, SigIdx);
                        if((DataPos == DCM_CFG_DID_SIG_OFFSET(DidIdx, SigIdx)) && (DataSize == DCM_CFG_DATA_SIZE(DataRef)))
                        {
                            /*SWS_Dcm_00646*/
                            DCM_DDDID_ELE_SDID_IDX(DDDidPos, DCM_DDDID_ELE_USED_NUM(DDDidPos)) = DidIdx;
                            DCM_DDDID_ELE_SDID_POS(DDDidPos, DCM_DDDID_ELE_USED_NUM(DDDidPos)) = DataPos;
                            DCM_DDDID_ELE_DATA_IDX(DDDidPos, DCM_DDDID_ELE_USED_NUM(DDDidPos)) = DataRef;
                            DCM_DDDID_ELE_DATA_SIZE(DDDidPos, DCM_DDDID_ELE_USED_NUM(DDDidPos)) = DataSize;
                            DCM_DDDID_ELE_USED_NUM(DDDidPos)++;
                            DCM_DDDID_DEFINED(DDDidPos) = TRUE;
                            break;
                        }
                    }

                    if(SigIdx >= DCM_CFG_DID_SIG_NUM(DidIdx))
                    {
                        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                        Result = E_NOT_OK;
                    }
                }
            }
            else
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }

            if(Result == E_NOT_OK)
            {
                /*DataIdx is not equal to 4, which means that the DID in the new request has been set to the DDDID.
                At this time, the entire DDDID needs to be cleared.*/
                if(DataIdx != DCM_LENGTH_4_BYTE)
                {
                    DspInternal_2C_ClearOneDDDID(DDDidPos);
                }
                break;
            }
        }/*(DataIdx = DCM_LENGTH_4_BYTE; DataIdx < (pMsgContext->reqDataLen); DataIdx += DCM_LENGTH_4_BYTE)*/
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2C_SearchSourceDid
*
* Description: This function is used to find out whether the source did has been
*              configured and can be read.
*
* Inputs: SourceDid
*
* Outputs: DidIndex
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_SearchSourceDid
(
    uint16 SourceDid,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) DidIndex
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint16 DidIdx;

    for(DidIdx = (uint16)0; DidIdx < DCM_CFG_DID_NUM; DidIdx++)
    {
        if(SourceDid == DCM_CFG_DID_ID(DidIdx))
        {
            *DidIndex = DidIdx;
            break;
        }
    }

    if(DidIdx < DCM_CFG_DID_NUM)
    {
        if((TRUE == DCM_CFG_DID_USED(DidIdx)) && (NULL_PTR != DCM_CFG_DID_INFO_READ(DidIdx)))
        {
            Result = E_OK;
        }
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2C_02_Processor
*
* Description: This function is used to implement the 02 sub-service function of
*              the 2C service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_02_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 Idx;
    uint8 AddrSizeFormat;
    uint8 AddrLength;
    uint8 SizeLength;
    Dcm_MsgLenType DataIdx;
    uint16 MemIdx = (uint16)0;
    uint16 DDDidPos;
    
    Dcm_SessionMaskType SesLevelRef;
#if(DCM_UDS_27_ENABLED == STD_ON)
    Dcm_SecurityMaskType SecLevelRef;
    Dcm_SecurityMaskType CurSecMask;
#endif

    (void)OpStatus;

    Result = DspInternal_2C_CheckDDDID(&DDDidPos, pMsgContext, pErrorCode);
    /*Check Memory address&length format of Source Memory*/
    if(Result == E_OK)
    {
        DCM_MEM_START_ADDR = (uint32)0;
        DCM_MEM_SIZE = (uint32)0;
        DCM_MEM_ID = DCM_DATA_CLEAR;
        AddrSizeFormat = (pMsgContext->reqData[DCM_INDEX_4]);

        /*Check addressAndLengthFormatIdentifier*/
        if(DCM_CFG_MEM_FORMAT_NUM != DCM_DATA_CLEAR)
        {
            for(Idx = (uint8)0; Idx < DCM_CFG_MEM_FORMAT_NUM; Idx++)
            {
                if(AddrSizeFormat == DCM_CFG_MEM_FORMAT(Idx))
                {
                    break;
                }
            }

            if(Idx >= DCM_CFG_MEM_FORMAT_NUM)
            {
                /*SWS_Dcm_00854*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
        }
    }

    /*Check MemoryAddress,MemorySize,Address,Session and Security of Source Memory*/
    if(Result == E_OK)
    {
        AddrLength = (AddrSizeFormat & DCM_MEM_FORMAT_ADDR_MASK);
        SizeLength = ((AddrSizeFormat & DCM_MEM_FORMAT_SIZE_MASK) >> DCM_SHIFT_4);

        for(DataIdx = DCM_LENGTH_5_BYTE; DataIdx < (pMsgContext->reqDataLen); DataIdx += ((Dcm_MsgLenType)AddrLength + (Dcm_MsgLenType)SizeLength))
        {
            /*Calculate start address*/
            for(Idx = (uint8)0; Idx < AddrLength; Idx++)
            {
                DCM_MEM_START_ADDR |= (uint32)(pMsgContext->reqData[DataIdx + Idx]) << (uint8)(DCM_SHIFT_8 * (AddrLength - DCM_INDEX_1 - Idx));
            }
            /*Calculate size*/
            for(Idx = (uint8)0; Idx < SizeLength; Idx++)
            {
                DCM_MEM_SIZE |= (uint32)(pMsgContext->reqData[DataIdx + AddrLength + Idx]) << (uint8)(DCM_SHIFT_8 * (SizeLength - DCM_INDEX_1 - Idx));
            }

            /* memoryAddress and memorySize are correct? */
            if(DCM_MEM_SIZE == DCM_DATA_CLEAR)
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else
            {
                /*check memory range*/
                for(Idx = (uint8)0; Idx < DCM_CFG_MEM_ID_NUM; Idx++)
                {
                    for(MemIdx = (uint16)0; MemIdx < DCM_CFG_MEM_ID_READ_NUM(Idx); MemIdx++)
                    {
                        if((DCM_MEM_START_ADDR <= DCM_CFG_MEM_ID_READ_HIGH(Idx, MemIdx)) && (DCM_MEM_START_ADDR >= DCM_CFG_MEM_ID_READ_LOW(Idx, MemIdx)) \
                            && (((DCM_MEM_START_ADDR + DCM_MEM_SIZE) - DCM_LENGTH_1_BYTE) <= DCM_CFG_MEM_ID_READ_HIGH(Idx, MemIdx)))
                        {
                            break;
                        }
                    }

                    if(MemIdx < DCM_CFG_MEM_ID_READ_NUM(Idx))
                    {
                        DCM_MEM_ID = DCM_CFG_MEM_ID_VALUE(Idx);
                        break;
                    }
                }/*for(Idx = (uint8)0; Idx < DCM_CFG_MEM_ID_NUM; Idx++)*/

                if(Idx >= DCM_CFG_MEM_ID_NUM)
                {
                    /*SWS_Dcm_01051*/
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
            }

            /*check security & session*/
            if(Result == E_OK)
            {
                /*check security & session*/
                SesLevelRef = DCM_CFG_MEM_ID_READ_SESREF(Idx, MemIdx);
#if(DCM_UDS_27_ENABLED == STD_ON)
                SecLevelRef = DCM_CFG_MEM_ID_READ_SECREF(Idx, MemIdx);
                CurSecMask = DslInternal_GetSecurityMask();
#endif
                if(!(DCM_CFG_SESSION_MASK(DCM_SES_IDX) & SesLevelRef))
                {
                    /*SWS_Dcm_00725*/
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
#if(DCM_UDS_27_ENABLED == STD_ON)
                else if(!(CurSecMask & SecLevelRef))
                {
                    /*SWS_Dcm_00726*/
                    *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
#endif
                else
                {
                    /*SWS_Dcm_00646*/
                    DCM_DDDID_ELE_MEM_ID(DDDidPos, DCM_DDDID_ELE_USED_NUM(DDDidPos)) = DCM_MEM_ID;
                    DCM_DDDID_ELE_MEM_ADDR(DDDidPos, DCM_DDDID_ELE_USED_NUM(DDDidPos)) = DCM_MEM_START_ADDR;
                    DCM_DDDID_ELE_DATA_SIZE(DDDidPos, DCM_DDDID_ELE_USED_NUM(DDDidPos)) = DCM_MEM_SIZE;
                    DCM_DDDID_ELE_USED_NUM(DDDidPos)++;
                    DCM_DDDID_DEFINED(DDDidPos) = TRUE;
                }
            }

            if(Result == E_NOT_OK)
            {
                /*DataIdx is not equal to 5, which means that the Memory in the new request has been set to the DDDID.
                At this time, the entire DDDID needs to be cleared.*/
                if(DataIdx != DCM_LENGTH_5_BYTE)
                {
                    DspInternal_2C_ClearOneDDDID(DDDidPos);
                }
                break;
            }
        }/*(DataIdx = DCM_LENGTH_5_BYTE; DataIdx < (pMsgContext->reqDataLen); DataIdx += (AddrLength + SizeLength))*/
    }
    return Result;
}
/*PRQA S 4700 --*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2C_03_Processor
*
* Description: This function is used to implement the 03 sub-service function of
*              the 2C service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2C_03_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    /*SWS_Dcm_00647*/
    Std_ReturnType Result = E_NOT_OK;
    uint16 Idx;
    uint16 DDDid;

    (void)OpStatus;

    if((pMsgContext->reqDataLen) == DCM_LENGTH_2_BYTE)
    {
        for(Idx = (uint16)0; Idx < DCM_CFG_DDDID_NUM; Idx++)
        {
            DspInternal_2C_ClearOneDDDID(Idx);
        }
        Result = E_OK;
    }
    else/*((pMsgContext->reqDataLen) > DCM_LENGTH_2_BYTE)*/
    {
        DDDid = Make16Bit(pMsgContext->reqData[DCM_INDEX_2], pMsgContext->reqData[DCM_INDEX_3]);
        for(Idx = (uint16)0; Idx < DCM_CFG_DDDID_NUM; Idx++)
        {
            if(DDDid == DCM_CFG_DID_ID(DCM_DDDID_INDEX(Idx)))
            {
                if(TRUE == DCM_DDDID_DEFINED(Idx))
                {
                    DspInternal_2C_ClearOneDDDID(Idx);
                }
                Result = E_OK;
                break;
            }
        }
    }

    if(Result == E_NOT_OK)
    {
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2C_ClearOneDDDID
*
* Description: This function is used to clear all dynamic information for a
*              dynamically defined DID
*
* Inputs: BufIdx: Index of DDDID buffer
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DspInternal_2C_ClearOneDDDID
(
    uint16 BufIdx
)
{
    uint16 Idx;

    DCM_DDDID_DEFINED(BufIdx) = FALSE;
    DCM_DDDID_ELE_USED_NUM(BufIdx) = DCM_DATA_CLEAR;

    for(Idx = (uint16)0; Idx < DCM_CFG_DID_INFO_DDDID_MAX_ELE(DCM_DDDID_INDEX(BufIdx)); Idx++)
    {
        DCM_DDDID_ELE_SDID_IDX(BufIdx, Idx) = DCM_INVALID_IDX;
        DCM_DDDID_ELE_SDID_POS(BufIdx, Idx) = DCM_DATA_CLEAR;
        DCM_DDDID_ELE_DATA_IDX(BufIdx, Idx) = DCM_DATA_CLEAR;
        DCM_DDDID_ELE_MEM_ID(BufIdx, Idx) = DCM_INVALID_MEMORY_ID;
        DCM_DDDID_ELE_MEM_ADDR(BufIdx, Idx) = DCM_DATA_CLEAR;
        DCM_DDDID_ELE_DATA_SIZE(BufIdx, Idx) = DCM_DATA_CLEAR;
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_DDDidReadAllRefData
*
* Description: This function is used to read all the data for a dynamically defined DID.
*
* Inputs: DidIndex, MaxBufferSize
*
* Outputs: pErrorCode
*
* Return: E_OK, E_NOT_OK, DCM_E_PENDING
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_DDDidReadAllRefData
(
    uint16 DidIndex,
    uint32 MaxBufferSize,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 BufIdx;
    uint16 DataRef;
    Dcm_MsgType DestPtr;
#if(DCM_NVM_SUPPORT == STD_ON)
    NvM_RequestResultType NvMResult = NVM_REQ_OK;
#endif

    BufIdx = DCM_CFG_DID_INFO_DDDID_BUF_IDX(DidIndex);

    /*read all reference data*/
    /*PRQA S 2472 ++*/
    /*It has been confirmed that there is only one loop control variable*/
    for( ; DCM_DID_SIG_IDX < DCM_CFG_DID_INFO_DDDID_MAX_ELE(DidIndex); )
    /*PRQA S 2472 --*/
    {
        if(DCM_INVALID_IDX != DCM_DDDID_ELE_SDID_IDX(BufIdx, DCM_DID_SIG_IDX))
        {
            /*Read DcmDspData*/
            DataRef = DCM_DDDID_ELE_DATA_IDX(BufIdx, DCM_DID_SIG_IDX);

            /*Step1: Condition check read*/
            if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_ONE)
            {
                if(TRUE == DCM_CFG_DATA_CON_EN(DataRef))
                {
                    Result = DCM_CFG_DATA_CON_CHECK_FNC(DataRef)(DCM_DID_OPSTATUS, pErrorCode);
                }

                if(Result == E_OK)
                {
                    /*Next step: Get the data length*/
                    DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_TWO;
                    /*Reset the DidOpStatus to start next step*/
                    DCM_DID_OPSTATUS = DCM_INITIAL;
                }
            }

            /*Step2: Get the data length*/
            if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_TWO)
            {
                /*compare data length with the response buffer max length*/
                if((DCM_DID_RESP_LEN + DCM_DID_DATA_LEN + DCM_DDDID_ELE_DATA_SIZE(BufIdx, DCM_DID_SIG_IDX)) <= MaxBufferSize)
                {
                    DCM_DID_DATA_LEN += (uint16)DCM_DDDID_ELE_DATA_SIZE(BufIdx, DCM_DID_SIG_IDX);
                    /*Next step: Read data*/
                    DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_THREE;
                }
                else
                {
                    *pErrorCode = DCM_E_RESPONSETOOLONG;
                    Result = E_NOT_OK;
                }
            }

            /*Step3: Read data*/
            if(DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_THREE)
            {
                DestPtr = &DCM_DID_RESP_DATA[(DCM_DID_DATA_LEN - DCM_LENGTH_2_BYTE - DCM_DDDID_ELE_DATA_SIZE(BufIdx, DCM_DID_SIG_IDX))];
#if(DCM_NVM_SUPPORT == STD_ON)
                if(DCM_USE_BLOCK_ID == DCM_CFG_DATA_USEPORT(DataRef))
                {
                    /*PRQA S 315,488 ++*/
                    /*NvM_ReadBlock is an autosar standard interface. Allow pointer arithmetic.*/
                    Result = NvM_ReadBlock(DCM_CFG_DATA_BLOCKID(DataRef), DestPtr);
                    /*PRQA S 315,488 --*/
                    if(Result == E_OK)
                    {
                        /*Next step: Call NvM_GetErrorStatus*/
                        DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_FOUR;
                        Result = DCM_E_PENDING;
                    }
                }
                else
#endif
                {
                    Result = DCM_CFG_DATA_READ_FNC(DataRef)(DCM_DID_OPSTATUS, DestPtr, pErrorCode);
                }
            }

#if(DCM_NVM_SUPPORT == STD_ON)
            /*Step4: Call NvM_GetErrorStatus*/
            if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_FOUR))
            {
                Result = NvM_GetErrorStatus(DCM_CFG_DATA_BLOCKID(DataRef), &NvMResult);
                if((Result == E_OK) && (NvMResult == NVM_REQ_OK))
                {
                    /*continue read next signal*/
                }
                else if((Result == E_OK) && (NvMResult == NVM_REQ_PENDING))
                {
                    /*Call again next mainfunction*/
                    Result = DCM_E_PENDING;
                }
                else
                {
                    /*AUTOSAR standard is not defined.*/
                    *pErrorCode = DCM_E_GENERALREJECT;
                    Result = E_NOT_OK;
                }
            }
#endif
        }
        else if(DCM_INVALID_MEMORY_ID != DCM_DDDID_ELE_MEM_ID(BufIdx, DCM_DID_SIG_IDX))
        {
            /*compare response length with the response buffer max length*/
            if((DCM_DID_RESP_LEN + DCM_DID_DATA_LEN + DCM_DDDID_ELE_DATA_SIZE(BufIdx, DCM_DID_SIG_IDX)) > MaxBufferSize)
            {
                *pErrorCode = DCM_E_RESPONSETOOLONG;
                Result = E_NOT_OK;
            }
            else
            {
                /*SWS_Dcm_00653*//*Read DcmDspMemory*/
                Result = DspInternal_ReadMemory(DCM_23_SERVICE, DCM_DID_OPSTATUS, DCM_DDDID_ELE_MEM_ID(BufIdx, DCM_DID_SIG_IDX), \
                            DCM_DDDID_ELE_MEM_ADDR(BufIdx, DCM_DID_SIG_IDX), DCM_DDDID_ELE_DATA_SIZE(BufIdx, DCM_DID_SIG_IDX), \
                            &(DCM_DID_RESP_DATA[(DCM_DID_DATA_LEN - DCM_LENGTH_2_BYTE)]), pErrorCode);
                if(Result == E_OK)
                {
                    DCM_DID_DATA_LEN += (uint16)DCM_DDDID_ELE_DATA_SIZE(BufIdx, DCM_DID_SIG_IDX);
                }
            }
        }
        else
        {
            /*All data has been read. Break out of the for loop.*/
            DCM_DID_SIG_IDX = DCM_CFG_DID_INFO_DDDID_MAX_ELE(DidIndex);
        }

        if(Result == E_OK)
        {
            /*continue read next signal*/
            if(DCM_DID_SIG_IDX < DCM_CFG_DID_INFO_DDDID_MAX_ELE(DidIndex))
            {
                DCM_DID_SIG_IDX++;
                DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_ONE;
                /*Reset the DidOpStatus to start reading next data of current DID*/
                DCM_DID_OPSTATUS = DCM_INITIAL;
            }
            else
            {
                /*Send positive response*/
            }
        }
        else if(Result == DCM_E_PENDING)
        {
            /*The fuction will be called again in next mainfunction cycle.*/
            break;
        }
        else
        {
            /*Break out of the for loop and send negative response*/
            DCM_DID_SIG_IDX = DCM_CFG_DID_INFO_DDDID_MAX_ELE(DidIndex);
        }
    }/*for( ; DCM_DID_SIG_IDX < DCM_CFG_DID_SIG_NUM(DCM_DID_INDEX_LIST[DCM_DID_POS]); )*/

    if((Result == E_OK) || (Result == E_NOT_OK))
    {
        DCM_DID_SIG_IDX = (uint16)0;
    }
    return Result;
}
/*PRQA S 4700 --*/
#endif/*#if(DCM_UDS_2C_ENABLED == STD_ON)*/

#if(DCM_UDS_2E_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2E_WriteDataByIdentifier SWS_Dcm_00255
*
* Description: This function is the code implementation of the processing logic
*              for the 0x2E service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2E_WriteDataByIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    boolean HasDynData = FALSE;
    uint16 ReqDID;
    uint16 Idx;
    uint16 DataLength;
    uint16 DataRef;
    uint16 DataPos;
    Dcm_MsgType DataPtr;
    uint8 SupportAddress;
    Dcm_SessionMaskType SesLevelRef;
#if(DCM_UDS_27_ENABLED == STD_ON)
    Dcm_SecurityMaskType SecLevelRef;
    Dcm_SecurityMaskType CurSecMask;
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
    Dcm_AuRoleMaskType AuRoleMask;
#endif
#if(DCM_NVM_SUPPORT == STD_ON)
    NvM_RequestResultType NvMResult = NVM_REQ_OK;
#endif

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
    uint8 DidHighByte = (pMsgContext->reqData[DCM_INDEX_1]);

    if(DidHighByte == DCM_RNDS_READ_ID_HIGH_BYTE)
    {
        /*Getting Identifiers supported by the ECU*/
        Result = DspInternal_2E_ReadSupportedIdentifier(pMsgContext, pErrorCode);
    }
    else
    {
#endif
        if(OpStatus == DCM_INITIAL)
        {
            DCM_DID_2E2F_IDX = DCM_INVALID_IDX;
            DCM_DID_SIG_IDX = (uint16)0;
#if(DCM_NVM_SUPPORT == STD_ON)
            DCM_CURRENT_EXE_STEP = DCM_DATA_CLEAR;
#endif
            /*Reset the DidOpStatus*/
            DCM_DID_OPSTATUS = DCM_INITIAL;

            ReqDID = Make16Bit(pMsgContext->reqData[DCM_INDEX_1], pMsgContext->reqData[DCM_INDEX_2]);

            for(Idx = (uint16)0; Idx < DCM_CFG_DID_NUM; Idx++)
            {
                if(ReqDID == DCM_CFG_DID_ID(Idx))
                {
                    if((TRUE == DCM_CFG_DID_USED(Idx)) && (NULL_PTR != DCM_CFG_DID_INFO_WRITE(Idx)))
                    {
                        DCM_DID_2E2F_IDX = Idx;
                    }
                    break;
                }
            }

            if(DCM_DID_2E2F_IDX == DCM_INVALID_IDX)
            {
                /*SWS_Dcm_00467*//*SWS_Dcm_00562*//*SWS_Dcm_00468*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else
            {
                SupportAddress = (DCM_CFG_DID_INFO_WRITE(DCM_DID_2E2F_IDX)->DcmDspDidWriteSupportAddress);
                SesLevelRef = (DCM_CFG_DID_INFO_WRITE(DCM_DID_2E2F_IDX)->DcmDspDidWriteSessionRef);

                if(!(SupportAddress & ((uint8)0x01 << (pMsgContext->msgAddInfo.reqType))))
                {
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
#if(DCM_UDS_10_ENABLED == STD_ON)
                else if(!(DCM_CFG_SESSION_MASK(DCM_SES_IDX) & SesLevelRef))
                {
                    /*SWS_Dcm_00469*/
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
#endif
                else
                {
                    /*to check the total length*/
                }
            }

            /*total length check*/
            if(Result == E_OK)
            {
                for(Idx = (uint16)0; Idx < DCM_CFG_DID_SIG_NUM(DCM_DID_2E2F_IDX); Idx++)
                {
                    DataRef = DCM_CFG_DID_SIG_REF(DCM_DID_2E2F_IDX, Idx);

                    if(DCM_CFG_DATA_TYPE(DataRef) == DCM_UINT8_DYN)
                    {
                        HasDynData = TRUE;
                        break;
                    }
                }

                if(((HasDynData == FALSE) && (pMsgContext->reqDataLen != (DCM_LENGTH_3_BYTE + DCM_CFG_DID_SIZE(DCM_DID_2E2F_IDX)))) \
                    || ((pMsgContext->reqDataLen) > (DCM_LENGTH_3_BYTE + DCM_CFG_DID_SIZE(DCM_DID_2E2F_IDX))))
                {
                    /*SWS_Dcm_00473*/
                    *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    Result = E_NOT_OK;
                }
            }
#if(DCM_UDS_29_ENABLED == STD_ON)
            /*Authentication check*/
            if(Result == E_OK)
            {
                AuRoleMask = (DCM_CFG_DID_INFO_WRITE(DCM_DID_2E2F_IDX)->DcmDspDidWriteRoleRef);

                if(!(DCM_AU_CUR_ROLE & AuRoleMask))
                {
                    /*SWS_Dcm_01496*//*SWS_Dcm_01544*/
                    *pErrorCode = DCM_E_AUTHENTICATIONREQUIRED;
                    Result = E_NOT_OK;
                }
            }
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
            /*DID security check*/
            if(Result == E_OK)
            {
                CurSecMask = DslInternal_GetSecurityMask();
                SecLevelRef = (DCM_CFG_DID_INFO_WRITE(DCM_DID_2E2F_IDX)->DcmDspDidWriteSecurityLevelRef);

                if(!(CurSecMask & SecLevelRef))
                {
                    /*SWS_Dcm_00470*/
                    *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
            }
#endif
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
            SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
        }/*if(OpStatus == DCM_INITIAL)*/

        /*SWS_Dcm_00395 Write all the signals (DcmDspDidSignal) of the DID*/
        if((OpStatus != DCM_CANCEL) && (Result == E_OK))
        {
            /*PRQA S 2472 ++*/
            /*
            In the for loop statement satisfies condition DCM_DID_SIG_IDX < DCM_CFG_DID_SIG_NUM(DCM_DID_2E2F_IDX)
            then the internal statement is executed all the time.
            */
            for( ; DCM_DID_SIG_IDX < DCM_CFG_DID_SIG_NUM(DCM_DID_2E2F_IDX); )
            {
                DataPos = DCM_CFG_DID_SIG_OFFSET(DCM_DID_2E2F_IDX, DCM_DID_SIG_IDX);
                DataRef = DCM_CFG_DID_SIG_REF(DCM_DID_2E2F_IDX, DCM_DID_SIG_IDX);

                DataPtr = &(pMsgContext->reqData[DCM_INDEX_3 + DataPos]);

                if(DCM_UINT8_DYN != DCM_CFG_DATA_TYPE(DataRef))
                {
                    DataLength = DCM_CFG_DATA_SIZE(DataRef);
                }
                else
                {
                    DataLength = (uint16)((pMsgContext->reqDataLen) - DCM_LENGTH_3_BYTE - DataPos);
                }

#if(DCM_NVM_SUPPORT == STD_ON)
                if(DCM_USE_BLOCK_ID == DCM_CFG_DATA_USEPORT(DataRef))
                {
                    if(DCM_CURRENT_EXE_STEP == DCM_DATA_CLEAR)
                    {
                        /*PRQA S 315 ++*/
                        /*Implicit conversion from a pointer to object type to a pointer to void.*/
                        Result = NvM_WriteBlock(DCM_CFG_DATA_BLOCKID(DataRef), DataPtr);
                        /*PRQA S 315 --*/
                        if(Result == E_OK)
                        {
                            /*Next step: Call NvM_GetErrorStatus*/
                            DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_ONE;
                            Result = DCM_E_PENDING;
                        }
                    }
                }
                else
#endif
                {
                    Result = DCM_CFG_DATA_WRITE_FNC(DataRef)(DataPtr, DataLength, DCM_DID_OPSTATUS, pErrorCode);
                }

#if(DCM_NVM_SUPPORT == STD_ON)
                /*Step1: Call NvM_GetErrorStatus*/
                if((Result == E_OK) && (DCM_CURRENT_EXE_STEP == DCM_EXE_STEP_ONE))
                {
                    Result = NvM_GetErrorStatus(DCM_CFG_DATA_BLOCKID(DataRef), &NvMResult);
                    if((Result == E_OK) && (NvMResult == NVM_REQ_OK))
                    {
                        /*continue write next signal*/
                    }
                    else if((Result == E_OK) && (NvMResult == NVM_REQ_PENDING))
                    {
                        /*Call again next mainfunction*/
                        Result = DCM_E_PENDING;
                    }
                    else
                    {
                        /*SWS_Dcm_00541 Trigger a negative response with NRC 0x72*/
                        *pErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                        Result = E_NOT_OK;
                    }
                }
#endif

                if(Result == E_OK)
                {
                    /*continue write next signal*/
                    DCM_DID_SIG_IDX++;
#if(DCM_NVM_SUPPORT == STD_ON)
                    DCM_CURRENT_EXE_STEP = DCM_DATA_CLEAR;
#endif
                    /*Reset the DidOpStatus to start writting next data of the DID*/
                    DCM_DID_OPSTATUS = DCM_INITIAL;
                }
                else
                {
                    if(Result == DCM_E_PENDING)
                    {
                        /*The fuction will be called again next mainfunction cycle.*/
                        DCM_DID_OPSTATUS = DCM_PENDING;
                    }
                    else
                    {
                        /*send negative response*/
                        Result = E_NOT_OK;
                    }
                    break;
                }
            }/*for( ; DCM_DID_SIG_IDX < DCM_CFG_DID_SIG_NUM(DCM_DID_2E2F_IDX); )*/
        }

        if(Result == E_OK)
        {
            pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
            pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
            pMsgContext->resDataLen = DCM_LENGTH_3_BYTE;
        }
#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
    }
#endif
    return Result;
}
/*PRQA S 4700 --*/

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2E_ReadSupportedIdentifier
*
* Description: Read supported identifier of 0x2E service.
*
* Inputs: pMsgContext, pErrorCode
*
* Outputs: None
*
* Return: E_OK, E_NOT_OK
*
* Limitations: Only used to meet nissan specification
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_2E_ReadSupportedIdentifier
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    uint16 i;
    uint8 BytePos;
    uint8 BitPos;
    uint8 ResponseData[DCM_RNDS_READ_DATA_LENGTH];
    Std_ReturnType Result = E_OK;
    uint8 DidLowByte = (pMsgContext->reqData[DCM_INDEX_2]);
    uint8 SubData = (pMsgContext->reqData[DCM_INDEX_3]);

    if((pMsgContext->reqDataLen) != DCM_NISSAN_READ_LENGTH)
    {
        /*the correct request length should be 3*/
        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        Result = E_NOT_OK;
    }
    else if(SubData != 0U)
    {
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        Result = E_NOT_OK;
    }
    else
    {
        for(i = 0U; i < DCM_RNDS_READ_DATA_LENGTH; i++)
        {
            /*reset the data value with zero*/
            ResponseData[i] = DCM_DATA_CLEAR;
        }

        if(DCM_RNDS_READ_ID_HIGH_BYTE == DidLowByte)
        {
            for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
            {
                if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_WRITE(i)))
                {
                    BytePos = (uint8)(DCM_CFG_DID_ID(i) >> DCM_SHIFT_11);
                    BitPos = (uint8)((DCM_CFG_DID_ID(i) >> DCM_SHIFT_8) % DCM_SHIFT_8);
                    ResponseData[BytePos] |= (DCM_HIGH_BIT_MASK >> BitPos);
                }
            }
        }
        else
        {
            for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
            {
                if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_WRITE(i)) \
                    && (((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_HIGH_MASK) >> DCM_SHIFT_8) == DidLowByte))
                {
                    BytePos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) / DCM_SHIFT_8);
                    BitPos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) % DCM_SHIFT_8);
                    ResponseData[BytePos] |= (DCM_HIGH_BIT_MASK >> BitPos);
                }
            }
        }
    }

    if(Result == E_OK)
    {
        /*Copy the data to the response buffer*/
        Bsw_MemCpy(&(pMsgContext->resData[DCM_INDEX_3]), ResponseData, DCM_RNDS_READ_DATA_LENGTH);

        pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
        pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
        pMsgContext->resDataLen = (DCM_INDEX_3 + DCM_RNDS_READ_DATA_LENGTH);
    }
    return Result;
}
#endif/*#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)*/
#endif/*#if(DCM_UDS_2E_ENABLED == STD_ON)*/

#if(DCM_UDS_2F_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2F_InputOutputControlByIdentifier SWS_Dcm_00256
*
* Description: This function is the code implementation of the processing logic
*              for the 0x2F service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2F_InputOutputControlByIdentifier
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 ReqDID;
    uint16 Idx;

    uint8 SupportAddress = (uint8)0;
    Dcm_SessionMaskType SesLevelRef = (Dcm_SessionMaskType)0;
#if(DCM_UDS_27_ENABLED == STD_ON)
    Dcm_SecurityMaskType SecLevelRef;
    Dcm_SecurityMaskType CurSecMask;
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
    Dcm_AuRoleMaskType AuRoleMask;
#endif
#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
    uint8 DidHighByte = (pMsgContext->reqData[DCM_INDEX_1]);

    if(DidHighByte == DCM_RNDS_READ_ID_HIGH_BYTE)
    {
        /*Getting Identifiers supported by the ECU from App*/
        Result = DspInternal_2F_ReadSupportedIdentifier(pMsgContext, pErrorCode);
    }
    else
    {
#endif
        if(OpStatus == DCM_INITIAL)
        {
            /*Reset the execution step information*/
            DCM_CURRENT_EXE_STEP = DCM_DATA_CLEAR;
            /*Reset related parameters*/
            DCM_DID_2E2F_IDX = DCM_INVALID_IDX;
            DCM_DID_SIG_IDX = (uint16)0;

            ReqDID = Make16Bit(pMsgContext->reqData[DCM_INDEX_1], pMsgContext->reqData[DCM_INDEX_2]);
            DCM_REQ_IOCONTROL = (pMsgContext->reqData[DCM_INDEX_3]);

            for(Idx = (uint16)0; Idx < DCM_CFG_DID_NUM; Idx++)
            {
                if(ReqDID == DCM_CFG_DID_ID(Idx))
                {
                    if((TRUE == DCM_CFG_DID_USED(Idx)) && (NULL_PTR != DCM_CFG_DID_INFO_CONTROL(Idx)))
                    {
                        DCM_DID_2E2F_IDX = Idx;
                        SupportAddress = DCM_CFG_DID_CONTROL_ADDRREF(Idx);
                        SesLevelRef = DCM_CFG_DID_CONTROL_SESREF(Idx);
                    }
                    break;
                }
            }

            if(DCM_DID_2E2F_IDX == DCM_INVALID_IDX)
            {
                /*SWS_Dcm_00563*//*SWS_Dcm_00564*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            /*check the support address type*/
            else if(!(SupportAddress & ((uint8)0x01 << (pMsgContext->msgAddInfo.reqType))))
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
#if(DCM_UDS_10_ENABLED == STD_ON)
            /*check the support session level*/
            else if(!(DCM_CFG_SESSION_MASK(DCM_SES_IDX) & SesLevelRef))
            {
                /*SWS_Dcm_00566*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
#endif
            /*SWS_Dcm_00579*/
            /*check if support ResetToDefault inputOutputControlParameter*/
            else if((DCM_REQ_IOCONTROL == DCM_RESET_TO_DEFAULT) && (DCM_CFG_DID_CONTROL_RESET(DCM_DID_2E2F_IDX) == FALSE))
            {
                /*SWS_Dcm_00565*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            /*check if support FreezeCurrentState inputOutputControlParameter*/
            else if((DCM_REQ_IOCONTROL == DCM_FREEZE_CURRENT_STATE) && (DCM_CFG_DID_CONTROL_FREEZE(DCM_DID_2E2F_IDX) == FALSE))
            {
                /*SWS_Dcm_00565*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            /*check if support ShortTermAdjustment inputOutputControlParameter*/
            else if((DCM_REQ_IOCONTROL == DCM_SHORT_TERM_ADJUSTMENT) && (DCM_CFG_DID_CONTROL_SHORT(DCM_DID_2E2F_IDX) == FALSE))
            {
                /*SWS_Dcm_00565*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else if(DCM_REQ_IOCONTROL > DCM_SHORT_TERM_ADJUSTMENT)
            {
                /*SWS_Dcm_00565*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            /*check request length*//*DCM_LENGTH_4_BYTE is 0x2F + DID + IOControl*/
            /*SWS_Dcm_01273*//*SWS_Dcm_01274*/
            else if(((DCM_REQ_IOCONTROL == DCM_RETURN_CONTROL_TO_ECU) || (DCM_REQ_IOCONTROL == DCM_RESET_TO_DEFAULT) \
                || (DCM_REQ_IOCONTROL == DCM_FREEZE_CURRENT_STATE)) \
                && ((pMsgContext->reqDataLen) != (DCM_LENGTH_4_BYTE + DCM_CFG_DID_CONTROL_MASK_SIZE(DCM_DID_2E2F_IDX))))
            {
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                Result = E_NOT_OK;
            }
            else if(DCM_REQ_IOCONTROL == DCM_SHORT_TERM_ADJUSTMENT)
            {
                for(Idx = (uint16)0; Idx < DCM_CFG_DID_SIG_NUM(DCM_DID_2E2F_IDX); Idx++)
                {
                    /*PRQA S 715 ++*/
                    /*
                    Nesting of control structures (statements) exceeds 15, without modification.
                    */
                    if(DCM_UINT8_DYN == DCM_CFG_DATA_TYPE(Idx))
                    {
                        break;
                    }
                    /*PRQA S 715 --*/
                }

                if((Idx <= DCM_CFG_DID_SIG_NUM(DCM_DID_2E2F_IDX)) \
                    && ((pMsgContext->reqDataLen) > (DCM_LENGTH_4_BYTE + DCM_CFG_DID_SIZE(DCM_DID_2E2F_IDX) + DCM_CFG_DID_CONTROL_MASK_SIZE(DCM_DID_2E2F_IDX))))
                {
                    *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    Result = E_NOT_OK;
                }
                else if((pMsgContext->reqDataLen) != (DCM_LENGTH_4_BYTE + DCM_CFG_DID_SIZE(DCM_DID_2E2F_IDX) + DCM_CFG_DID_CONTROL_MASK_SIZE(DCM_DID_2E2F_IDX)))
                {
                    *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    Result = E_NOT_OK;
                }
                else
                {
                    /*length is valid*/
                }
            }
            else
            {
                /*do nothing*/
            }

#if(DCM_UDS_29_ENABLED == STD_ON)
            /*Authentication check*/
            if(Result == E_OK)
            {
                AuRoleMask = DCM_CFG_DID_CONTROL_ROLEREF(DCM_DID_2E2F_IDX);

                if(!(DCM_AU_CUR_ROLE & AuRoleMask))
                {
                    /*SWS_Dcm_01554*//*SWS_Dcm_01544*/
                    *pErrorCode = DCM_E_AUTHENTICATIONREQUIRED;
                    Result = E_NOT_OK;
                }
            }
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
            /*check the support security level*/
            if(Result == E_OK)
            {
                CurSecMask = DslInternal_GetSecurityMask();
                SecLevelRef = DCM_CFG_DID_CONTROL_SECREF(DCM_DID_2E2F_IDX);
                if(!(CurSecMask & SecLevelRef))
                {
                    /*SWS_Dcm_00567*/
                    *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
            }
#endif
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
            SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
        }/*if(OpStatus == DCM_INITIAL)*/

        if((OpStatus != DCM_CANCEL) && (Result == E_OK))
        {
            /*IO Control*/
            if(DCM_CURRENT_EXE_STEP == DCM_DATA_CLEAR)
            {
                /*IO Control process*/
                Result = DspInternal_2F_IOControlProcess(OpStatus, pMsgContext, pErrorCode);

                if(Result == E_OK)
                {
                    DCM_DID_SIG_IDX = (uint16)0;
                    /*Next Step*/
                    DCM_CURRENT_EXE_STEP = DCM_EXE_STEP_ONE;
                    /*Set the length and address for reading controlState*/
                    DCM_DID_RESP_LEN = DCM_LENGTH_2_BYTE;/*0x2F + IOControl*/
                    DCM_DID_DATA_LEN = (uint16)DCM_LENGTH_2_BYTE;/*DID length*/
                    /*PRQA S 488 ++*/
                    /* Allow pointer arithmetic.*/
                    DCM_DID_RESP_DATA = (pMsgContext->resData + DCM_DID_RESP_LEN + DCM_DID_DATA_LEN);
                    /*PRQA S 488 --*/
                    /*Reset the OpStatus to start reading data(control state)*/
                    DCM_DID_OPSTATUS = DCM_INITIAL;
                }
            }

            /*SWS_Dcm_00682,Read the controlState*/
            if(Result == E_OK)
            {
                /*read all reference data*/
                Result = DspInternal_DidReadAllRefData(DCM_DID_2E2F_IDX, (pMsgContext->resMaxDataLen), pErrorCode);
                if(Result == E_OK)
                {
                    DCM_DID_RESP_LEN += DCM_DID_DATA_LEN;

                    pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
                    pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
                    pMsgContext->resData[DCM_INDEX_3] = DCM_REQ_IOCONTROL;
                    pMsgContext->resDataLen = DCM_DID_RESP_LEN;
                }
                else if(Result == DCM_E_PENDING)
                {
                    DCM_DID_OPSTATUS = DCM_PENDING;
                }
                else
                {
                    /*Send negative response*/
                    Result = E_NOT_OK;
                }
            }
        }
#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
    }
#endif
    return Result;
}
/*PRQA S 4700 --*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2F_IOControlProcess
*
* Description: This function is used to implement the logical processing of
*              input/output control
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_2F_IOControlProcess
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    boolean CallInterface;/*Whether an external interface needs to be invoked*/
    uint16 DataLength;
    uint16 DataPos;
    uint16 DataRef;
    uint8 *ControlStateInfo = NULL_PTR;
    uint8 *ControlMask = NULL_PTR;
    uint32 MaskBitPos;
    uint32 MaskBytePos;

    ControlMask = &(pMsgContext->reqData[(pMsgContext->reqDataLen - DCM_CFG_DID_CONTROL_MASK_SIZE(DCM_DID_2E2F_IDX))]);
    /*PRQA S 2472 ++*/
    /*
    In the for loop statement satisfies condition DCM_DID_SIG_IDX < DCM_CFG_DID_SIG_NUM(DCM_DID_2E2F_IDX) then the internal statement is executed all the time.
    */
    for( ; DCM_DID_SIG_IDX < DCM_CFG_DID_SIG_NUM(DCM_DID_2E2F_IDX); )
    {
        DataRef = DCM_CFG_DID_SIG_REF(DCM_DID_2E2F_IDX, DCM_DID_SIG_IDX);

        if(DCM_CONTROLMASK_INTERNAL == DCM_CFG_DID_CONTROL_MASK(DCM_DID_2E2F_IDX))
        {
            MaskBitPos = DCM_CFG_DID_CONTROL_EN_MASK_POS(DCM_DID_2E2F_IDX, DCM_DID_SIG_IDX);
            MaskBytePos = (MaskBitPos / DCM_SHIFT_8);
            MaskBitPos = (MaskBitPos % DCM_SHIFT_8);
            /* SWS_Dcm_00581 */
            if((ControlMask[MaskBytePos] & (DCM_HIGH_BIT_MASK >> MaskBitPos)) != (uint8)0)
            {
                CallInterface = TRUE;
            }
            else
            {
                CallInterface = FALSE;
            }
        }
        else
        {
            CallInterface = TRUE;
        }

        if(CallInterface == TRUE)
        {
            switch(DCM_REQ_IOCONTROL)
            {
            case DCM_RETURN_CONTROL_TO_ECU:
                Result = DCM_CFG_DATA_RETURN_FNC(DataRef)(OpStatus, ControlMask, pErrorCode);
                break;

            case DCM_RESET_TO_DEFAULT:
                Result = DCM_CFG_DATA_RESET_FNC(DataRef)(OpStatus, ControlMask, pErrorCode);
                break;

            case DCM_FREEZE_CURRENT_STATE:
                Result = DCM_CFG_DATA_FREEZE_FNC(DataRef)(OpStatus, ControlMask, pErrorCode);
                break;

            default:
                /*Get the data offset of current signal in the DID*/
                DataPos = DCM_CFG_DID_SIG_OFFSET(DCM_DID_2E2F_IDX, DCM_DID_SIG_IDX);
                /*Get the request data length of current signal*/
                if(DCM_UINT8_DYN == DCM_CFG_DATA_TYPE(DataRef))
                {
                    DataLength = (uint16)(pMsgContext->reqDataLen - DCM_LENGTH_4_BYTE - DataPos - DCM_CFG_DID_CONTROL_MASK_SIZE(DCM_DID_2E2F_IDX));
                }
                else
                {
                    DataLength = DCM_CFG_DATA_SIZE(DataRef);
                }

                ControlStateInfo = &(pMsgContext->reqData[(DCM_LENGTH_4_BYTE + DataPos)]);

                Result = DCM_CFG_DATA_SHORT_FNC(DataRef)(ControlStateInfo, DataLength, OpStatus, ControlMask, pErrorCode);
                break;
            }

            if(Result == E_OK)
            {
                DCM_DID_SIG_IDX++;
            }
            else
            {
                break;
            }
        }
        else
        {
            DCM_DID_SIG_IDX++;
        }
    }
    /*PRQA S 2472 --*/
    return Result;
}

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_2F_ReadSupportedIdentifier
*
* Description: Read supported identifier of 0x2F service.
*
* Inputs: pMsgContext, pErrorCode
*
* Outputs: None
*
* Return: E_OK, E_NOT_OK
*
* Limitations: Only used to meet nissan specification
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_2F_ReadSupportedIdentifier
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    uint16 i;
    uint8 BytePos;
    uint8 BitPos;
    uint8 ResponseData[DCM_RNDS_READ_DATA_LENGTH];
    Std_ReturnType Result = E_OK;
    uint8 DidLowByte = (pMsgContext->reqData[DCM_INDEX_2]);
    uint8 SubData = (pMsgContext->reqData[DCM_INDEX_3]);

    if((pMsgContext->reqDataLen) != DCM_NISSAN_READ_LENGTH)
    {
        /*the correct request length should be 3*/
        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        Result = E_NOT_OK;
    }
    else if(SubData != DCM_SHORT_TERM_ADJUSTMENT)
    {
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        Result = E_NOT_OK;
    }
    else
    {
        for(i = 0U; i < DCM_RNDS_READ_DATA_LENGTH; i++)
        {
            /*reset the data value with zero*/
            ResponseData[i] = DCM_DATA_CLEAR;
        }

        if(DCM_RNDS_READ_ID_HIGH_BYTE == DidLowByte)
        {
            for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
            {
                if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_CONTROL(i)))
                {
                    BytePos = (uint8)(DCM_CFG_DID_ID(i) >> DCM_SHIFT_11);
                    BitPos = (uint8)((DCM_CFG_DID_ID(i) >> DCM_SHIFT_8) % DCM_SHIFT_8);
                    ResponseData[BytePos] |= (DCM_HIGH_BIT_MASK >> BitPos);
                }
            }
        }
        else
        {
            for(i = (uint16)0; i < DCM_CFG_DID_NUM; i++)
            {
                if((TRUE == DCM_CFG_DID_USED(i)) && (NULL_PTR != DCM_CFG_DID_INFO_CONTROL(i)) \
                    && (((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_HIGH_MASK) >> DCM_SHIFT_8) == DidLowByte))
                {
                    BytePos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) / DCM_SHIFT_8);
                    BitPos = (uint8)((DCM_CFG_DID_ID(i) & DCM_RNDS_ID_LOW_MASK) % DCM_SHIFT_8);
                    ResponseData[BytePos] |= (DCM_HIGH_BIT_MASK >> BitPos);
                }
            }
        }
    }

    if(Result == E_OK)
    {
        /*Copy the data to the response buffer*/
        Bsw_MemCpy(&(pMsgContext->resData[DCM_INDEX_4]), ResponseData, DCM_RNDS_READ_DATA_LENGTH);

        pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
        pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
        pMsgContext->resData[DCM_INDEX_3] = pMsgContext->reqData[DCM_INDEX_3];
        pMsgContext->resDataLen = (DCM_INDEX_4 + DCM_RNDS_READ_DATA_LENGTH);
    }
    return Result;
}
#endif/*#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)*/
#endif/*#if(DCM_UDS_2F_ENABLED == STD_ON)*/

#if(DCM_UDS_31_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_31_RoutineControl SWS_Dcm_00257
*
* Description: This function is the code implementation of the processing logic
*              for the 0x31 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_31_RoutineControl
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint16 RID;
    uint16 Idx;
    Dcm_SessionMaskType SesLevelRef = (Dcm_SessionMaskType)0;
#if(DCM_UDS_27_ENABLED == STD_ON)
    Dcm_SecurityMaskType SecLevelRef = (Dcm_SecurityMaskType)0;
    Dcm_SecurityMaskType CurSecMask = DslInternal_GetSecurityMask();
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
    Dcm_AuRoleMaskType AuRoleMask = (Dcm_AuRoleMaskType)0;
#endif
    uint8 SupportAddress = DCM_DATA_CLEAR;

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
    uint8 RidHighByte = (pMsgContext->reqData[DCM_INDEX_2]);

    if(RidHighByte == DCM_RNDS_READ_ID_HIGH_BYTE)
    {
        /*Getting Identifiers supported by the ECU from App*/
        Result = DspInternal_31_ReadSupportedIdentifier(pMsgContext, pErrorCode);
    }
    else
    {
#endif
/*PRQA S 2201 ++*/
/*
Partial if conditions are deposited in certain conditions.
*/
        if(OpStatus == DCM_INITIAL)
/*PRQA S 2201 --*/
        {
#if(DCM_UDS_31_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
            ClearSuppressPosRespBit();
#endif
            /*Reset related parameters*/
            DCM_RID_IDX = DCM_INVALID_IDX;
            DCM_RID_CTRL_INFO = NULL_PTR;
            /*Get the requested routine ID.*/
            RID = Make16Bit(pMsgContext->reqData[DCM_INDEX_2], pMsgContext->reqData[DCM_INDEX_3]);
   
            for(Idx = (uint16)0; Idx < DCM_CFG_ROUTINE_NUM; Idx++)
            {
                if(RID == DCM_CFG_ROUTINE_ID(Idx))
                {
                    if(TRUE == DCM_CFG_ROUTINE_USED(Idx))
                    {
                        DCM_RID_IDX = Idx;
                    }
                    break;
                }
            }

            /*SWS_Dcm_01139*/
            if(DCM_RID_IDX == DCM_INVALID_IDX)
            {
                /*SWS_Dcm_00568*//*SWS_Dcm_00569*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else if((DCM_REQ_SUBSERVICE < DCM_START_ROUTINE) || (DCM_REQ_SUBSERVICE > DCM_REQUEST_ROUTINE_RESULTS))
            {
                *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
                Result = E_NOT_OK;
            }
            else
            {
                switch(DCM_REQ_SUBSERVICE)
                {
                case DCM_START_ROUTINE:
                    DCM_RID_CTRL_INFO = DCM_CFG_ROUTINE_START(DCM_RID_IDX);
                    break;
                
                case DCM_STOP_ROUTINE:
                    DCM_RID_CTRL_INFO = DCM_CFG_ROUTINE_STOP(DCM_RID_IDX);
                    break;

                default:
                    DCM_RID_CTRL_INFO = DCM_CFG_ROUTINE_RESULT(DCM_RID_IDX);
                    break;
                }

                if(NULL_PTR == DCM_RID_CTRL_INFO)
                {
                    /*SWS_Dcm_00869*/
                    *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
                    Result = E_NOT_OK;
                }
                /*Get configured Authorization(Session, Security, address).*/
                else if(NULL_PTR != (DCM_RID_CTRL_INFO->DcmDspRoutineControlCommonAuthorizationRef))
                {
                    /*Next step: Address & Session & Security check*/
                    SupportAddress = (DCM_RID_CTRL_INFO->DcmDspRoutineControlCommonAuthorizationRef->DcmDspCommonAuthorizationSupportAddress);
                    SesLevelRef = (DCM_RID_CTRL_INFO->DcmDspRoutineControlCommonAuthorizationRef->DcmDspCommonAuthorizationSessionRef);
#if(DCM_UDS_27_ENABLED == STD_ON)
                    SecLevelRef = (DCM_RID_CTRL_INFO->DcmDspRoutineControlCommonAuthorizationRef->DcmDspCommonAuthorizationSecurityLevelRef);
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
                    AuRoleMask = (DCM_RID_CTRL_INFO->DcmDspRoutineControlCommonAuthorizationRef->DcmDspRequestRoutineRoleRef);
#endif
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
                    SetP4Timer((DCM_RID_CTRL_INFO->P4ServerMax));
#endif
                }
                else
                {
                    /*Address & Session & Security don't need check*/
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
                    SetP4Timer((DCM_RID_CTRL_INFO->P4ServerMax));
#endif
                }
            }

            /*Address & Session & Security check*/
            if((Result == E_OK) && (SupportAddress != DCM_DATA_CLEAR))
            {
                if(!(SupportAddress & ((uint8)0x01 << (pMsgContext->msgAddInfo.reqType))))
                {
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
#if(DCM_UDS_10_ENABLED == STD_ON)
                else if(!(DCM_CFG_SESSION_MASK(DCM_SES_IDX) & SesLevelRef))
                {
                    /*SWS_Dcm_00570*/
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
                else if(!(DCM_AU_CUR_ROLE & AuRoleMask))
                {
                    /*SWS_Dcm_01555*//*SWS_Dcm_01556*//*SWS_Dcm_01557*//*SWS_Dcm_01544*/
                    *pErrorCode = DCM_E_AUTHENTICATIONREQUIRED;
                    Result = E_NOT_OK;
                }
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
                else if(!(CurSecMask & SecLevelRef))
                {
                    /*SWS_Dcm_00571*/
                    *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
#endif
                else
                {
                    /*Next step: check request length*/
                }
            }

            /*check request length*//*SWS_Dcm_01140*/
            if(Result == E_OK)
            {
                if((DCM_VARIABLE_LENGTH != (DCM_RID_CTRL_INFO->DcmDspRoutineControlInSignal.DcmDspRoutineSignalType)) \
                    && (pMsgContext->reqDataLen != (DCM_LENGTH_4_BYTE + (DCM_RID_CTRL_INFO->DcmDspRoutineControlInSignal.DcmDspRoutineParameterSize))))
                {
                    *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    Result = E_NOT_OK;
                }
                else if(pMsgContext->reqDataLen > (DCM_LENGTH_4_BYTE + (DCM_RID_CTRL_INFO->DcmDspRoutineControlInSignal.DcmDspRoutineParameterSize)))
                {
                    *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    Result = E_NOT_OK;
                }
                else
                {
                    /*Next step: Check routine sequence*/
                }
            }

            /*Check routine sequence*/
            if(Result == E_OK)
            {
                if((DCM_REQ_SUBSERVICE == DCM_STOP_ROUTINE) && (DCM_ROUTINE_STARTED != DCM_RID_STATUS(DCM_RID_IDX)))
                {
                    *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                    Result = E_NOT_OK;
                }
                else if((DCM_REQ_SUBSERVICE == DCM_REQUEST_ROUTINE_RESULTS) && (DCM_ROUTINE_NONE == DCM_RID_STATUS(DCM_RID_IDX)))
                {
                    *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                    Result = E_NOT_OK;
                }
                else
                {
                    /*do nothing*/
                }
            }
        }/*if(OpStatus == DCM_INITIAL)*/

/*PRQA S 2201 ++*/
/*
Partial if conditions are deposited in certain conditions.
*/
        if((OpStatus != DCM_CANCEL) && (Result == E_OK))
/*PRQA S 2201 --*/
        {
            Result = DspInternal_31_Sub_Processor(OpStatus, pMsgContext, pErrorCode);

            /*Creat the positive response*/
            if(Result == E_OK)
            {
                if(DCM_REQ_SUBSERVICE == DCM_START_ROUTINE)
                {
                    DCM_RID_STATUS(DCM_RID_IDX) = DCM_ROUTINE_STARTED;
                }
                else if(DCM_REQ_SUBSERVICE == DCM_STOP_ROUTINE)
                {
                    DCM_RID_STATUS(DCM_RID_IDX) = DCM_ROUTINE_STOPPED;
                }
                else
                {
                    /*do nothing*/
                }
                pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
                pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
                pMsgContext->resData[DCM_INDEX_3] = pMsgContext->reqData[DCM_INDEX_3];
            }
        }
#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
    }
#endif
    return Result;
}
/*PRQA S 4700 --*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_Reset_RoutineStatus
*
* Description: This function is used to initialize or reset the variable parameters
*              associated with the 0x31 service.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) DspInternal_Reset_RoutineStatus
(
    void
)
{
    uint16 Idx;

    for(Idx = (uint16)0; Idx < DCM_CFG_RID_NUM; Idx++)
    {
        DCM_RID_STATUS(Idx) = DCM_ROUTINE_NONE;
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_31_Sub_Processor
*
* Description: This function actually implements the processing of the subservice,
*              namely, calls the Rte function interface to complete the routine control.
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_31_Sub_Processor
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 *DataIn = &(pMsgContext->reqData[DCM_INDEX_4]);
    uint8 *DataOut = &(pMsgContext->resData[DCM_INDEX_4]);
    uint16 currentDataLength = (uint16)(pMsgContext->reqDataLen - DCM_LENGTH_4_BYTE);

    Result = (DCM_RID_CTRL_INFO->DcmDspRoutineControlFnc)(DataIn, OpStatus, DataOut, &currentDataLength, pErrorCode);

    /*Calculate the positive response*/
    if(Result == E_OK)
    {
        if(DCM_VARIABLE_LENGTH != (DCM_RID_CTRL_INFO->DcmDspRoutineControlOutSignal.DcmDspRoutineSignalType))
        {
            currentDataLength = (DCM_RID_CTRL_INFO->DcmDspRoutineControlOutSignal.DcmDspRoutineParameterSize);
        }

        pMsgContext->resDataLen = (DCM_LENGTH_4_BYTE + currentDataLength);
    }
    return Result;
}

#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_31_ReadSupportedIdentifier
*
* Description: Read supported identifier of 0x31 service.
*
* Inputs: pMsgContext, pErrorCode
*
* Outputs: None
*
* Return: E_OK, E_NOT_OK
*
* Limitations: Only used to meet nissan specification
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_31_ReadSupportedIdentifier
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    uint16 i;
    uint8 BytePos;
    uint8 BitPos;
    uint8 ResponseData[DCM_RNDS_READ_DATA_LENGTH];
    Std_ReturnType Result = E_OK;
    uint8 RidLowByte = (pMsgContext->reqData[DCM_INDEX_3]);
    uint8 SubData = (pMsgContext->reqData[DCM_INDEX_1]);

    if((pMsgContext->reqDataLen) != DCM_NISSAN_READ_LENGTH)
    {
        /*the correct request length should be 4*/
        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        Result = E_NOT_OK;
    }
    else if(SubData != DCM_START_ROUTINE)
    {
        *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
        Result = E_NOT_OK;
    }
    else
    {
        for(i = 0U; i < DCM_RNDS_READ_DATA_LENGTH; i++)
        {
            /*reset the data value with zero*/
            ResponseData[i] = DCM_DATA_CLEAR;
        }

        if(DCM_RNDS_READ_ID_HIGH_BYTE == RidLowByte)
        {
            for(i = (uint16)0; i < DCM_CFG_ROUTINE_NUM; i++)
            {
                if(TRUE == DCM_CFG_ROUTINE_USED(i))
                {
                    BytePos = (uint8)(DCM_CFG_ROUTINE_ID(i) >> DCM_SHIFT_11);
                    BitPos = (uint8)((DCM_CFG_ROUTINE_ID(i) >> DCM_SHIFT_8) % DCM_SHIFT_8);
                    ResponseData[BytePos] |= (DCM_HIGH_BIT_MASK >> BitPos);
                }
            }
        }
        else
        {
            for(i = (uint16)0; i < DCM_CFG_ROUTINE_NUM; i++)
            {
                if((TRUE == DCM_CFG_ROUTINE_USED(i)) \
                    && (((DCM_CFG_ROUTINE_ID(i) & DCM_RNDS_ID_HIGH_MASK) >> DCM_SHIFT_8) == RidLowByte))
                {
                    BytePos = (uint8)((DCM_CFG_ROUTINE_ID(i) & DCM_RNDS_ID_LOW_MASK) / DCM_SHIFT_8);
                    BitPos = (uint8)((DCM_CFG_ROUTINE_ID(i) & DCM_RNDS_ID_LOW_MASK) % DCM_SHIFT_8);
                    ResponseData[BytePos] |= (DCM_HIGH_BIT_MASK >> BitPos);
                }
            }
        }
    }

    if(Result == E_OK)
    {
        /*Copy the data to the response buffer*/
        Bsw_MemCpy(&(pMsgContext->resData[DCM_INDEX_4]), ResponseData, DCM_RNDS_READ_DATA_LENGTH);

        pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
        pMsgContext->resData[DCM_INDEX_2] = pMsgContext->reqData[DCM_INDEX_2];
        pMsgContext->resData[DCM_INDEX_3] = pMsgContext->reqData[DCM_INDEX_3];
        pMsgContext->resDataLen = (DCM_INDEX_4 + DCM_RNDS_READ_DATA_LENGTH);
    }
    return Result;
}
#endif/*#if(DCM_CAR_PLATFORM == DCM_NISSAN_PLATFORM)*/

#endif

#if(DCM_UDS_34_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_34_RequestDownload
*
* Description: Processing function of UDS 0x34 service.
*
* Inputs: OpStatus,pMsgContext
*
* Outputs: pMsgContext,pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: Only used by UDS 0x34 service
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*There is not limit on the number of lines of function code and the number of local variable assignments.*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_34_RequestDownload
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    Dcm_SessionMaskType SesLevelRef;
#if(DCM_UDS_27_ENABLED == STD_ON)
    Dcm_SecurityMaskType SecLevelRef;
    Dcm_SecurityMaskType CurSecMask;
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
    Dcm_AuRoleMaskType AuRoleMask;
#endif
    uint8 AddrSizeFormat;
    uint8 AddrLength;
    uint8 SizeLength;
    uint8 Idx;/*Index*/
    uint16 MemRangeIdx = (uint16)0;/*Index of memory range info*/
    uint32 MaxNumberOfBlockLength;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_DOWN_UP_LOAD_MA = (uint32)0;
        DCM_DOWN_UP_LOAD_MS = (uint32)0;
        DCM_DOWN_UP_LOAD_MI = DCM_DATA_CLEAR;
        DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_NONE;
        /*SWS_Dcm_01417*/
        DCM_DOWN_UP_LOAD_MNOBFWRM = (uint32)((DCM_CFG_PCL_RXBUFFER_SIZE(DCM_ACTIVE_PCL_ID)) - DCM_LENGTH_2_BYTE);
        DCM_DOWN_UP_LOAD_DFI = (pMsgContext->reqData[DCM_INDEX_1]);
        AddrSizeFormat = (pMsgContext->reqData[DCM_INDEX_2]);
        AddrLength = (AddrSizeFormat & DCM_MEM_FORMAT_ADDR_MASK);
        SizeLength = ((AddrSizeFormat & DCM_MEM_FORMAT_SIZE_MASK) >> DCM_SHIFT_4);

        /*SWS_Dcm_00856, Check addressAndLengthFormatIdentifier*/
        if(DCM_CFG_MEM_FORMAT_NUM != DCM_DATA_CLEAR)
        {
            Result = E_NOT_OK;
            for(Idx = (uint8)0; Idx < DCM_CFG_MEM_FORMAT_NUM; Idx++)
            {
                if(AddrSizeFormat == DCM_CFG_MEM_FORMAT(Idx))
                {
                    Result = E_OK;
                    break;
                }
            }
        }
        else
        {
            /*Dcm shall accept all possible AddressAndLengthFormatIdentifiers.*/
        }

        if((Result == E_NOT_OK) || (AddrLength == DCM_DATA_CLEAR) || (SizeLength == DCM_DATA_CLEAR))
        {
            /*SWS_Dcm_00856*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else if(pMsgContext->reqDataLen != (DCM_LENGTH_3_BYTE + AddrLength + SizeLength))
        {
            /*Full length check*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
            /* Calculate start address */
            for(Idx = (uint8)0; Idx < AddrLength; Idx++)
            {
                DCM_DOWN_UP_LOAD_MA |= (uint32)(pMsgContext->reqData[DCM_INDEX_3 + Idx]) << (uint8)(DCM_SHIFT_8 * (AddrLength - DCM_INDEX_1 - Idx));
            }
            /* Calculate size */
            for(Idx = (uint8)0; Idx < SizeLength; Idx++)
            {
                DCM_DOWN_UP_LOAD_MS |= (uint32)(pMsgContext->reqData[DCM_INDEX_3 + AddrLength + Idx]) << (uint8)(DCM_SHIFT_8 * (SizeLength - DCM_INDEX_1 - Idx));
            }
            /*Memory length check*/
            if(DCM_DOWN_UP_LOAD_MS == (uint32)0)
            {
                /*NRC 0x31*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else
            {
                /*check memory range & security & session*/
            }
        }
        /*check memory range & security & session*/
        if(Result == E_OK)
        {
            Result = E_NOT_OK;
            /*SWS_Dcm_01057*/
            for(Idx = (uint8)0; Idx < DCM_CFG_MEM_ID_NUM; Idx++)
            {
                for(MemRangeIdx = (uint16)0; MemRangeIdx < DCM_CFG_MEM_ID_WRITE_NUM(Idx); MemRangeIdx++)
                {
                    /*PRQA S 3393 ++*/
                    /*An arithmetic operation (* / + -) is the operand of a different operator with the same precedence.*/
                    if((DCM_DOWN_UP_LOAD_MA <= DCM_CFG_MEM_ID_WRITE_HIGH(Idx, MemRangeIdx)) \
                        && (DCM_DOWN_UP_LOAD_MA >= DCM_CFG_MEM_ID_WRITE_LOW(Idx, MemRangeIdx)) \
                        && ((DCM_DOWN_UP_LOAD_MA + DCM_DOWN_UP_LOAD_MS - DCM_LENGTH_1_BYTE) <= DCM_CFG_MEM_ID_WRITE_HIGH(Idx, MemRangeIdx)))
                    {
                        DCM_DOWN_UP_LOAD_MI = DCM_CFG_MEM_ID_VALUE(Idx);
                        Result = E_OK;
                        break;
                    }
                    /*PRQA S 3393 --*/
                }

                if(Result == E_OK)
                {
                    break;
                }
            }

            if(Result != E_OK)
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
            else
            {
                /*check security & session*/
                SesLevelRef = DCM_CFG_MEM_ID_WRITE_SESREF(Idx, MemRangeIdx);
#if(DCM_UDS_27_ENABLED == STD_ON)
                SecLevelRef = DCM_CFG_MEM_ID_WRITE_SECREF(Idx, MemRangeIdx);
                CurSecMask = DslInternal_GetSecurityMask();
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
                AuRoleMask = DCM_CFG_MEM_ID_WRITE_ROLEREF(Idx, MemRangeIdx);
#endif
                if(!(DCM_CFG_SESSION_MASK(DCM_SES_IDX) & SesLevelRef))
                {
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
#if(DCM_UDS_29_ENABLED == STD_ON)
                else if(!(DCM_AU_CUR_ROLE & AuRoleMask))
                {
                    /*SWS_Dcm_01551*/
                    *pErrorCode = DCM_E_AUTHENTICATIONREQUIRED;
                    Result = E_NOT_OK;
                }
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
                else if(!(CurSecMask & SecLevelRef))
                {
                    *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
#endif
                else
                {
                    /*Call Dcm_ProcessRequestDownload()*/
                }
            }
        }
    }/*if(OpStatus == DCM_INITIAL)*/

    if((OpStatus != DCM_CANCEL) && (Result == E_OK))
    {
        /*SWS_Dcm_01132*//*SWS_Dcm_00757*/
        Result = Dcm_ProcessRequestDownload(OpStatus, DCM_DOWN_UP_LOAD_DFI, DCM_DOWN_UP_LOAD_MI, DCM_DOWN_UP_LOAD_MA, \
                    DCM_DOWN_UP_LOAD_MS, &DCM_DOWN_UP_LOAD_MNOBFWRM, pErrorCode);

        if(Result == E_OK)
        {
            if(DCM_DOWN_UP_LOAD_MNOBFWRM > (uint32)((DCM_CFG_PCL_RXBUFFER_SIZE(DCM_ACTIVE_PCL_ID)) - DCM_LENGTH_2_BYTE))
            {
                /*SWS_Dcm_01418*/
                DCM_DET_REPORT_RUNTIME_ERROR(DCM_SID_MAINFUNCTION, DCM_E_INTERFACE_BUFFER_OVERFLOW);
                /*AUTOSAR standard is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
                Result = E_NOT_OK;
            }
            else
            {
                DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_DOWN;
                DCM_DOWN_UP_LOAD_PRE_BSC = DCM_BSC_INIT_VALUE;
                DCM_DOWN_UP_LOAD_NEXT_BSC = DCM_BSC_INIT_VALUE;
                /*MaxNumberOfBlockLength in positive response reflects the complete message length, including the service
                identifier and the data-parameters present in the TransferData request message*/
                MaxNumberOfBlockLength = DCM_DOWN_UP_LOAD_MNOBFWRM + DCM_LENGTH_2_BYTE;
                /*Creat the response data*/
                pMsgContext->resData[DCM_INDEX_1] = DCM_LENGTH_FORMAT_IDENTIFIER;/*Length format identifier*/
                /*SWS_Dcm_01419*/
                pMsgContext->resData[DCM_INDEX_2] = (uint8)(MaxNumberOfBlockLength >> DCM_SHIFT_24);
                pMsgContext->resData[DCM_INDEX_3] = (uint8)(MaxNumberOfBlockLength >> DCM_SHIFT_16);
                pMsgContext->resData[DCM_INDEX_4] = (uint8)(MaxNumberOfBlockLength >> DCM_SHIFT_8);
                pMsgContext->resData[DCM_INDEX_5] = (uint8)MaxNumberOfBlockLength;
                pMsgContext->resDataLen = DCM_LENGTH_6_BYTE;
            }
        }
    }

    return Result;
}
/*PRQA S 4700 --*/
#endif

#if((DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_3D_ENABLED == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_WriteMemory
*
* Description: Call the Dcm_WriteMemory() or Dcm_ProcessTransferDataWrite() function
*              and change the return value to Std_ReturnType.
*
* Inputs: ServiceId,OpStatus,MemoryIdentifier,MemoryAddress,MemorySize,MemoryData
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: Used for writing memory
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_WriteMemory
(
    uint8 ServiceId,
    Dcm_OpStatusType OpStatus,
    uint8 MemoryIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    uint8* MemoryData,
    Dcm_NegativeResponseCodeType* ErrorCode
)
{
    Std_ReturnType Result = E_OK;
    Dcm_ReturnWriteMemoryType WriteResult = DCM_WRITE_OK;

#if(DCM_UDS_3D_ENABLED == STD_ON)
    if(ServiceId == DCM_3D_SERVICE)
    {
        WriteResult = Dcm_WriteMemory(OpStatus, MemoryIdentifier, MemoryAddress, MemorySize, MemoryData, ErrorCode);
    }
#endif
#if(DCM_UDS_34_ENABLED == STD_ON)
    if(ServiceId == DCM_34_SERVICE)
    {
        WriteResult = Dcm_ProcessTransferDataWrite(OpStatus, MemoryIdentifier, MemoryAddress, MemorySize, MemoryData, ErrorCode);
    }
#endif

    switch(WriteResult)
    {
    case DCM_WRITE_OK:
        Result = E_OK;
        break;

    case DCM_WRITE_PENDIN:
        Result = DCM_E_PENDING;
        break;

    case DCM_WRITE_FAILED:
        Result = E_NOT_OK;
        break;

    case DCM_WRITE_FORCE_RCRRP:
        Result = DCM_E_FORCE_RCRRP;
        break;

    default:
        *ErrorCode = DCM_E_GENERALREJECT;
        Result = E_NOT_OK;
        break;
    }

    return Result;
}
#endif

#if((DCM_UDS_23_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_ReadMemory
*
* Description: Call the Dcm_ReadMemory() or Dcm_ProcessTransferDataRead() function
*              and change the return value to Std_ReturnType.
*
* Inputs: ServiceId, OpStatus,MemoryIdentifier,MemoryAddress,MemorySize
*
* Outputs: MemoryData,pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: Used for reading memory
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_ReadMemory
(
    uint8 ServiceId,
    Dcm_OpStatusType OpStatus,
    uint8 MemoryIdentifier,
    uint32 MemoryAddress,
    uint32 MemorySize,
    uint8* MemoryData,
    Dcm_NegativeResponseCodeType* ErrorCode
)
{
    Std_ReturnType Result = E_OK;
    Dcm_ReturnReadMemoryType ReadResult = DCM_READ_OK;

#if(DCM_UDS_23_ENABLED == STD_ON)
    if(ServiceId == DCM_23_SERVICE)
    {
        ReadResult = Dcm_ReadMemory(OpStatus, MemoryIdentifier, MemoryAddress, MemorySize, MemoryData, ErrorCode);
    }
#endif
#if(DCM_UDS_35_ENABLED == STD_ON)
    if(ServiceId == DCM_35_SERVICE)
    {
        /*PRQA S 2784 ++*/
        /*The available address range of the MemoryData pointer is determined by the MemorySize parameter.*/
        ReadResult = Dcm_ProcessTransferDataRead(OpStatus, MemoryIdentifier, MemoryAddress, MemorySize, MemoryData, ErrorCode);
        /*PRQA S 2784 --*/
    }
#endif

    switch(ReadResult)
    {
    case DCM_READ_OK:
        Result = E_OK;
        break;

    case DCM_READ_PENDIN:
        Result = DCM_E_PENDING;
        break;

    case DCM_READ_FAILED:
        Result = E_NOT_OK;
        break;

    case DCM_READ_FORCE_RCRRP:
        Result = DCM_E_FORCE_RCRRP;
        break;

    default:
        *ErrorCode = DCM_E_GENERALREJECT;
        Result = E_NOT_OK;
        break;
    }

    return Result;
}
#endif

#if(DCM_UDS_35_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_35_RequestUpload
*
* Description: Processing function of UDS 0x35 service.
*
* Inputs: OpStatus,pMsgContext
*
* Outputs: pMsgContext,pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: Only used by UDS 0x35 service
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*There is not limit on the number of lines of function code and the number of local variable assignments.*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_35_RequestUpload
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    Dcm_SessionMaskType SesLevelRef;
#if(DCM_UDS_27_ENABLED == STD_ON)
    Dcm_SecurityMaskType SecLevelRef;
    Dcm_SecurityMaskType CurSecMask;
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
    Dcm_AuRoleMaskType AuRoleMask;
#endif
    uint8 AddrSizeFormat;
    uint8 AddrLength;
    uint8 SizeLength;
    uint8 Idx;/*Index*/
    uint16 MemRangeIdx = (uint16)0;/*Index of memory range info*/
    uint32 MaxNumberOfBlockLength;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_DOWN_UP_LOAD_MA = (uint32)0;
        DCM_DOWN_UP_LOAD_MS = (uint32)0;
        DCM_DOWN_UP_LOAD_MI = DCM_DATA_CLEAR;
        DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_NONE;
        /*SWS_Dcm_01420*/
        DCM_DOWN_UP_LOAD_MNOBFWRM = (uint32)((pMsgContext->resMaxDataLen) - DCM_LENGTH_2_BYTE);
        DCM_DOWN_UP_LOAD_DFI = (pMsgContext->reqData[DCM_INDEX_1]);
        AddrSizeFormat = (pMsgContext->reqData[DCM_INDEX_2]);
        AddrLength = (AddrSizeFormat & DCM_MEM_FORMAT_ADDR_MASK);
        SizeLength = ((AddrSizeFormat & DCM_MEM_FORMAT_SIZE_MASK) >> DCM_SHIFT_4);
        /*SWS_Dcm_00857, Check addressAndLengthFormatIdentifier*/
        if(DCM_CFG_MEM_FORMAT_NUM != DCM_DATA_CLEAR)
        {
            Result = E_NOT_OK;
            for(Idx = (uint8)0; Idx < DCM_CFG_MEM_FORMAT_NUM; Idx++)
            {
                if(AddrSizeFormat == DCM_CFG_MEM_FORMAT(Idx))
                {
                    Result = E_OK;
                    break;
                }
            }
        }
        else
        {
            /*Dcm shall accept all possible AddressAndLengthFormatIdentifiers.*/
        }

        if((Result == E_NOT_OK) || (AddrLength == DCM_DATA_CLEAR) || (SizeLength == DCM_DATA_CLEAR))
        {
            /*SWS_Dcm_00857*/
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else if(pMsgContext->reqDataLen != (DCM_LENGTH_3_BYTE + AddrLength + SizeLength))
        {
            /*Full length check*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
            /* Calculate start address */
            for(Idx = (uint8)0; Idx < AddrLength; Idx++)
            {
                DCM_DOWN_UP_LOAD_MA |= (uint32)(pMsgContext->reqData[DCM_INDEX_3 + Idx]) << (uint8)(DCM_SHIFT_8 * (AddrLength - DCM_INDEX_1 - Idx));
            }
            /* Calculate size */
            for(Idx = (uint8)0; Idx < SizeLength; Idx++)
            {
                DCM_DOWN_UP_LOAD_MS |= (uint32)(pMsgContext->reqData[DCM_INDEX_3 + AddrLength + Idx]) << (uint8)(DCM_SHIFT_8 * (SizeLength - DCM_INDEX_1 - Idx));
            }
            /*Memory length check*/
            if(DCM_DOWN_UP_LOAD_MS == (uint32)0)
            {
                /*NRC 0x31*/
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else
            {
                /*check memory range & security & session*/
            }
        }
        /*check memory range & security & session*/
        if(Result == E_OK)
        {
            Result = E_NOT_OK;
            /*SWS_Dcm_01055*/
            for(Idx = (uint8)0; Idx < DCM_CFG_MEM_ID_NUM; Idx++)
            {
                for(MemRangeIdx = (uint16)0; MemRangeIdx < DCM_CFG_MEM_ID_READ_NUM(Idx); MemRangeIdx++)
                {
                    /*PRQA S 3393 ++*/
                    /*An arithmetic operation (* / + -) is the operand of a different operator with the same precedence.*/
                    if((DCM_DOWN_UP_LOAD_MA <= DCM_CFG_MEM_ID_READ_HIGH(Idx, MemRangeIdx)) \
                        && (DCM_DOWN_UP_LOAD_MA >= DCM_CFG_MEM_ID_READ_LOW(Idx, MemRangeIdx)) \
                        && ((DCM_DOWN_UP_LOAD_MA + DCM_DOWN_UP_LOAD_MS - DCM_LENGTH_1_BYTE) <= DCM_CFG_MEM_ID_READ_HIGH(Idx, MemRangeIdx)))
                    {
                        DCM_DOWN_UP_LOAD_MI = DCM_CFG_MEM_ID_VALUE(Idx);
                        Result = E_OK;
                        break;
                    }
                    /*PRQA S 3393 --*/
                }

                if(Result == E_OK)
                {
                    break;
                }
            }

            if(Result != E_OK)
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
            else
            {
                /*check security & session*/
                SesLevelRef = DCM_CFG_MEM_ID_READ_SESREF(Idx, MemRangeIdx);
#if(DCM_UDS_27_ENABLED == STD_ON)
                SecLevelRef = DCM_CFG_MEM_ID_READ_SECREF(Idx, MemRangeIdx);
                CurSecMask = DslInternal_GetSecurityMask();
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
                AuRoleMask = DCM_CFG_MEM_ID_READ_ROLEREF(Idx, MemRangeIdx);
#endif
                if(!(DCM_CFG_SESSION_MASK(DCM_SES_IDX) & SesLevelRef))
                {
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
#if(DCM_UDS_29_ENABLED == STD_ON)
                else if(!(DCM_AU_CUR_ROLE & AuRoleMask))
                {
                    /*SWS_Dcm_01551*/
                    *pErrorCode = DCM_E_AUTHENTICATIONREQUIRED;
                    Result = E_NOT_OK;
                }
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
                else if(!(CurSecMask & SecLevelRef))
                {
                    *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
#endif
                else
                {
                    /*Call Dcm_ProcessRequestUpload()*/
                }
            }
        }
    }/*if(OpStatus == DCM_INITIAL)*/

    if(Result == E_OK)
    {
        /*SWS_Dcm_01133*//*SWS_Dcm_00758*/
        Result = Dcm_ProcessRequestUpload(OpStatus, DCM_DOWN_UP_LOAD_DFI, DCM_DOWN_UP_LOAD_MI, DCM_DOWN_UP_LOAD_MA, \
                    DCM_DOWN_UP_LOAD_MS, &DCM_DOWN_UP_LOAD_MNOBFWRM, pErrorCode);

        if(Result == E_OK)
        {
            if(DCM_DOWN_UP_LOAD_MNOBFWRM > (uint32)((pMsgContext->resMaxDataLen) - DCM_LENGTH_2_BYTE))
            {
                /*SWS_Dcm_01421*/
                DCM_DET_REPORT_RUNTIME_ERROR(DCM_SID_MAINFUNCTION, DCM_E_INTERFACE_BUFFER_OVERFLOW);
                /*AUTOSAR standard is not defined.*/
                *pErrorCode = DCM_E_GENERALREJECT;
                Result = E_NOT_OK;
            }
            else
            {
                DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_UP;
                DCM_DOWN_UP_LOAD_PRE_BSC = DCM_BSC_INIT_VALUE;
                DCM_DOWN_UP_LOAD_NEXT_BSC = DCM_BSC_INIT_VALUE;
                /*MaxNumberOfBlockLength in positive response reflects the complete message length, including the service
                identifier and the data-parameters present in the TransferData request message,*/
                MaxNumberOfBlockLength = DCM_DOWN_UP_LOAD_MNOBFWRM + DCM_LENGTH_2_BYTE;
                /*Creat the response data*/
                pMsgContext->resData[DCM_INDEX_1] = DCM_LENGTH_FORMAT_IDENTIFIER;/*Length format identifier*/
                /*SWS_Dcm_01422*/
                pMsgContext->resData[DCM_INDEX_2] = (uint8)(MaxNumberOfBlockLength >> DCM_SHIFT_24);
                pMsgContext->resData[DCM_INDEX_3] = (uint8)(MaxNumberOfBlockLength >> DCM_SHIFT_16);
                pMsgContext->resData[DCM_INDEX_4] = (uint8)(MaxNumberOfBlockLength >> DCM_SHIFT_8);
                pMsgContext->resData[DCM_INDEX_5] = (uint8)MaxNumberOfBlockLength;
                pMsgContext->resDataLen = DCM_LENGTH_6_BYTE;
            }
        }
    }

    return Result;
}
/*PRQA S 4700 --*/
#endif

#if(DCM_UDS_36_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_36_TransferData SWS_Dcm_00502
*
* Description: Processing function of UDS 0x36 service.
*
* Inputs: OpStatus,pMsgContext
*
* Outputs: pMsgContext,pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: Only used by UDS 0x36 service
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_36_TransferData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

#if((DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON))
    if((DCM_DOWN_UP_LOAD_STATUS == DCM_LOAD_DOWN) || (DCM_DOWN_UP_LOAD_STATUS == DCM_LOAD_UP))
    {
        Result = DspInternal_36_UpDownData(OpStatus, pMsgContext, pErrorCode);
    }
    else
#endif
#if(DCM_UDS_38_ENABLED == STD_ON)
    if(DCM_DOWN_UP_LOAD_STATUS == DCM_LOAD_FILE_TRANSFER)
    {
        Result = DspInternal_36_FileData(OpStatus, pMsgContext, pErrorCode);
    }
    else
#endif
    {
        /*Sequence error*/
        *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        Result = E_NOT_OK;
    }

    return Result;
}
#if((DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_36_UpDownData
*
* Description: Implement data upload and download.
*
* Inputs: OpStatus,pMsgContext
*
* Outputs: pMsgContext,pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: Only used by UDS 0x36 service for 0x34 and 0x35.
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*There is not limit on the number of lines of function code and the number of local variable assignments.*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_36_UpDownData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint32 DataSize = (uint32)0;

    if(OpStatus == DCM_INITIAL)
    {
        /*If the RequestDownload or RequestUpload service is active, but the server has already received all data as determined
        by the memorySize parameter in the active RequestDownload or RequestUpload service, the NRC24 should be sent.*/
        if(DCM_DOWN_UP_LOAD_MS == (uint32)0)
        {
            if((pMsgContext->reqData[DCM_INDEX_1]) != DCM_DOWN_UP_LOAD_PRE_BSC)
            {
                /*SWS_Dcm_01173*//*Sequence error*/
                *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                Result = E_NOT_OK;
            }
        }
        else
        {
            /*Check if the received block sequence counter equals to the expected value.*/
            if(((pMsgContext->reqData[DCM_INDEX_1]) != DCM_DOWN_UP_LOAD_NEXT_BSC) \
                && ((pMsgContext->reqData[DCM_INDEX_1]) != DCM_DOWN_UP_LOAD_PRE_BSC))
            {
                /*SWS_Dcm_00645*/
                *pErrorCode = DCM_E_WRONGBLOCKSEQUENCECOUNTER;
                Result = E_NOT_OK;
            }
        }

#if(DCM_UDS_34_ENABLED == STD_ON)
        if((Result == E_OK) && (DCM_DOWN_UP_LOAD_STATUS == DCM_LOAD_DOWN))
        {
            if(DCM_DOWN_UP_LOAD_MS > DCM_DOWN_UP_LOAD_MNOBFWRM)
            {
                /*If the message is not the last frame, the data length should equal to the
                MaxNumberOfBlockLength returned in the positive response to the 0x34 service.*/
                if((pMsgContext->reqDataLen) != (DCM_LENGTH_2_BYTE + DCM_DOWN_UP_LOAD_MNOBFWRM))
                {
                    *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    Result = E_NOT_OK;
                }
            }
            else
            {
                /*If the message is the last frame, the data length should equal to the
                length of the remaining unreceived data.*/
                if((pMsgContext->reqData[DCM_INDEX_1]) == DCM_DOWN_UP_LOAD_NEXT_BSC)
                {
                    if((pMsgContext->reqDataLen) != (DCM_LENGTH_2_BYTE + DCM_DOWN_UP_LOAD_MS))
                    {
                        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                        Result = E_NOT_OK;
                    }
                }
                else
                {
                    /*TransferData request is repeated.*/
                    if((pMsgContext->reqDataLen) != (DCM_LENGTH_2_BYTE + DCM_DOWN_UP_LOAD_MNOBFWRM))
                    {
                        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                        Result = E_NOT_OK;
                    }
                }
            }
        }
#endif

#if(DCM_UDS_35_ENABLED == STD_ON)
        if((Result == E_OK) && (DCM_DOWN_UP_LOAD_STATUS == DCM_LOAD_UP))
        {
            /*if the previous request is RequestUpload(0x35 service), the length of current request message should be 2 bytes.*/
            if((pMsgContext->reqDataLen) != DCM_LENGTH_2_BYTE)
            {
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                Result = E_NOT_OK;
            }
        }
#endif
    }

    if(Result == E_OK)
    {
#if(DCM_UDS_34_ENABLED == STD_ON)
        if(DCM_DOWN_UP_LOAD_STATUS == DCM_LOAD_DOWN)
        {
            /*SWS_Dcm_00503*/
            if((pMsgContext->reqData[DCM_INDEX_1]) == DCM_DOWN_UP_LOAD_NEXT_BSC)
            {
                DataSize = (pMsgContext->reqDataLen - DCM_LENGTH_2_BYTE);

                Result = DspInternal_WriteMemory(DCM_34_SERVICE, OpStatus, DCM_DOWN_UP_LOAD_MI, DCM_DOWN_UP_LOAD_MA, DataSize, \
                                &(pMsgContext->reqData[DCM_INDEX_2]), pErrorCode);
                if(Result == E_OK)
                {
                    DCM_DOWN_UP_LOAD_MS -= DataSize;
                    DCM_DOWN_UP_LOAD_MA += DataSize;
                    /*Assign the last data length to the DCM_DOWN_UP_LOAD_MNOBFWRM variable to realize the data retransmission function.*/
                    DCM_DOWN_UP_LOAD_MNOBFWRM = DataSize;

                    DCM_DOWN_UP_LOAD_PRE_BSC = DCM_DOWN_UP_LOAD_NEXT_BSC;
                    DCM_DOWN_UP_LOAD_NEXT_BSC++;

                    pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
                    pMsgContext->resDataLen = DCM_LENGTH_2_BYTE;
                }
            }
            else
            {
                /*The server would send positive response message immediately without writing the data once again inte its memory.*/
                pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
                pMsgContext->resDataLen = DCM_LENGTH_2_BYTE;
            }
            
        }
        else
#endif
        {
            /*Read memory*/
#if(DCM_UDS_35_ENABLED == STD_ON)
            if((pMsgContext->reqData[DCM_INDEX_1]) == DCM_DOWN_UP_LOAD_NEXT_BSC)
            {
                if(DCM_DOWN_UP_LOAD_MS > DCM_DOWN_UP_LOAD_MNOBFWRM)
                {
                    /*If the message is not the last frame, the data length should equal to the
                    MaxNumberOfBlockLength returned in the positive response to the 0x34 service.*/
                    DataSize = DCM_DOWN_UP_LOAD_MNOBFWRM;
                }
                else
                {
                    /*If the message is the last frame, the data length should equal to the
                    length of the remaining unreceived data.*/
                    DataSize = DCM_DOWN_UP_LOAD_MS;
                }
                /*SWS_Dcm_00504*/
                Result = DspInternal_ReadMemory(DCM_35_SERVICE, OpStatus, DCM_DOWN_UP_LOAD_MI, DCM_DOWN_UP_LOAD_MA, DataSize, \
                                &(pMsgContext->resData[DCM_INDEX_2]), pErrorCode);
                if(Result == E_OK)
                {
                    DCM_DOWN_UP_LOAD_MS -= DataSize;
                    DCM_DOWN_UP_LOAD_MA += DataSize;
                    /*Assign the last data length to the DCM_DOWN_UP_LOAD_MNOBFWRM variable to realize the data retransmission function.*/
                    DCM_DOWN_UP_LOAD_MNOBFWRM = DataSize;

                    DCM_DOWN_UP_LOAD_PRE_BSC = DCM_DOWN_UP_LOAD_NEXT_BSC;
                    DCM_DOWN_UP_LOAD_NEXT_BSC++;

                    pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
                    pMsgContext->resDataLen = (DCM_LENGTH_2_BYTE + DataSize);
                }
            }
            else
            {
                /*The length of the last frame of data is stored in the DCM_DOWN_UP_LOAD_MNOBFWRM parameter.*/
                DataSize = DCM_DOWN_UP_LOAD_MNOBFWRM;
                /*Read the data once again in its memory.*/
                Result = DspInternal_ReadMemory(DCM_35_SERVICE, OpStatus, DCM_DOWN_UP_LOAD_MI, (DCM_DOWN_UP_LOAD_MA - DataSize), DataSize, \
                                &(pMsgContext->resData[DCM_INDEX_2]), pErrorCode);
                if(Result == E_OK)
                {
                    pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];
                    pMsgContext->resDataLen = (DCM_LENGTH_2_BYTE + DataSize);
                }
            }
#endif
        }
    }

    if((Result == E_NOT_OK) && (*pErrorCode != DCM_E_WRONGBLOCKSEQUENCECOUNTER))
    {
        DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_NONE;
    }

    return Result;
}
/*PRQA S 4700 --*/
#endif

#if(DCM_UDS_38_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_36_FileData
*
* Description: Implement file transfer.
*
* Inputs: OpStatus,pMsgContext
*
* Outputs: pMsgContext,pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: Only used by UDS 0x36 service for 0x38.
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*There is not limit on the number of lines of function code and the number of local variable assignments.*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_36_FileData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint64 DataSize;
    uint64 RemainingDataSize;

    if(OpStatus == DCM_INITIAL)
    {
        if((uint8)0 != (DCM_DOWN_UP_LOAD_DFI >> DCM_SHIFT_4))
        {
            RemainingDataSize = DCM_FILE_TRANSFER_FSC;
        }
        else
        {
            RemainingDataSize = DCM_FILE_TRANSFER_FSUC;
        }

        /*If the server has already transfered all file data, the NRC24 should be sent.*/
        if(RemainingDataSize == (uint64)0)
        {
            /*SWS_Dcm_01173*//*Sequence error*/
            *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
            Result = E_NOT_OK;
        }
        /*Check if the received block sequence counter equals to the expected value.*/
        else if((pMsgContext->reqData[DCM_INDEX_1]) != DCM_DOWN_UP_LOAD_NEXT_BSC)
        {
            /*SWS_Dcm_00645*/
            *pErrorCode = DCM_E_WRONGBLOCKSEQUENCECOUNTER;
            Result = E_NOT_OK;
        }
        else if((DCM_FILE_TRANSFER_MOOP == DCM_ADD_FILE) || (DCM_FILE_TRANSFER_MOOP == DCM_REPLACE_FILE))
        {
            if((RemainingDataSize + DCM_LENGTH_2_BYTE) > DCM_FILE_TRANSFER_MNROB)
            {
                /*If the message is not the last frame, the data length should equal to the MaxNumberOfBlockLength
                 returned in the positive response to the 0x38 service.*/
                if((pMsgContext->reqDataLen) != DCM_FILE_TRANSFER_MNROB)
                {
                    *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    Result = E_NOT_OK;
                }
            }
            else
            {
                /*If the message is the last frame, the data length should equal to the length of the remaining data.*/
                if((pMsgContext->reqDataLen) != (RemainingDataSize + DCM_LENGTH_2_BYTE))
                {
                    *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                    Result = E_NOT_OK;
                }
            }
        }
        else/*DCM_FILE_TRANSFER_MOOP equals to DCM_READ_FILE or DCM_READ_DIR*/
        {
            if((pMsgContext->reqDataLen) != DCM_LENGTH_2_BYTE)
            {
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                Result = E_NOT_OK;
            }
        }
    }

    if(Result == E_OK)
    {
        if((DCM_FILE_TRANSFER_MOOP == DCM_ADD_FILE) || (DCM_FILE_TRANSFER_MOOP == DCM_REPLACE_FILE))
        {
            DataSize = (uint64)(pMsgContext->reqDataLen) - (uint64)DCM_LENGTH_2_BYTE;
            /*SWS_Dcm_01444*/
            Result = Dcm_WriteFile(OpStatus, DataSize, &(pMsgContext->reqData[DCM_INDEX_2]), pErrorCode);
        }
        else/*DCM_FILE_TRANSFER_MOOP equals to DCM_READ_FILE or DCM_READ_DIR*/
        {
            if((uint8)0 != (DCM_DOWN_UP_LOAD_DFI >> DCM_SHIFT_4))
            {
                RemainingDataSize = DCM_FILE_TRANSFER_FSC;
            }
            else
            {
                RemainingDataSize = DCM_FILE_TRANSFER_FSUC;
            }

            if((RemainingDataSize + DCM_LENGTH_2_BYTE) > DCM_FILE_TRANSFER_MNROB)
            {
                /*If the message is not the last frame, the data length should equal to the MaxNumberOfBlockLength
                 returned in the positive response to the 0x38 service.*/
                DataSize = DCM_FILE_TRANSFER_MNROB;
            }
            else
            {
                /*If the message is the last frame, the data length should equal to the length of the remaining data.*/
                DataSize = RemainingDataSize;
            }
            /*SWS_Dcm_01445*/
            Result = Dcm_ReadFileOrDir(OpStatus, &DataSize, &(pMsgContext->resData[DCM_INDEX_2]), pErrorCode);
        }

        if(Result == E_OK)
        {
            if((uint8)0 != (DCM_DOWN_UP_LOAD_DFI >> DCM_SHIFT_4))
            {
                DCM_FILE_TRANSFER_FSC -= DataSize;
            }
            else
            {
                DCM_FILE_TRANSFER_FSC -= DataSize;
            }
            /*Update the sequence counter*/
            DCM_DOWN_UP_LOAD_PRE_BSC = DCM_DOWN_UP_LOAD_NEXT_BSC;
            DCM_DOWN_UP_LOAD_NEXT_BSC++;
            /*Creat positive response.*/
            pMsgContext->resData[DCM_INDEX_1] = pMsgContext->reqData[DCM_INDEX_1];

            if((DCM_FILE_TRANSFER_MOOP == DCM_ADD_FILE) || (DCM_FILE_TRANSFER_MOOP == DCM_REPLACE_FILE))
            {
                pMsgContext->resDataLen = DCM_LENGTH_2_BYTE;
            }
            else
            {
                pMsgContext->resDataLen = (DCM_LENGTH_2_BYTE + (Dcm_MsgLenType)DataSize);
            }
        }
    }

    if(Result == E_NOT_OK)
    {
        DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_NONE;
    }

    return Result;
}
/*PRQA S 4700 --*/
#endif
#endif/*#if(DCM_UDS_36_ENABLED == STD_ON)*/

#if(DCM_UDS_37_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_37_RequestTransferExit SWS_Dcm_00505
*
* Description: Processing function of UDS 0x37 service.
*
* Inputs: OpStatus,pMsgContext
*
* Outputs: pMsgContext,pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: Only used by UDS 0x37 service
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_37_RequestTransferExit
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint32 ReqRecSize = (uint32)0;
    uint32 ResRecSize = (uint32)0;
#if(DCM_UDS_38_ENABLED == STD_ON)
    uint64 RemainingDataSize;
#endif
    if(OpStatus == DCM_INITIAL)
    {
        if((DCM_DOWN_UP_LOAD_STATUS == DCM_LOAD_NONE))
        {
            /*Sequence error*/
            *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
            Result = E_NOT_OK;
        }
#if(DCM_UDS_38_ENABLED == STD_ON)
        else if(DCM_DOWN_UP_LOAD_STATUS == DCM_LOAD_FILE_TRANSFER)
        {
            if((uint8)0 != (DCM_DOWN_UP_LOAD_DFI >> DCM_SHIFT_4))
            {
                RemainingDataSize = DCM_FILE_TRANSFER_FSC;
            }
            else
            {
                RemainingDataSize = DCM_FILE_TRANSFER_FSC;
            }

            if(RemainingDataSize != (uint64)0)
            {
                /*Sequence error*/
                *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                Result = E_NOT_OK;
            }
        }
#endif
        else
        {
#if((DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON))
            if(DCM_DOWN_UP_LOAD_MS != (uint32)0)
            {
                /*Sequence error*/
                *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                Result = E_NOT_OK;
            }
#endif
        }
    }

    if(Result == E_OK)
    {
        ReqRecSize = (pMsgContext->reqDataLen - DCM_LENGTH_1_BYTE);
        /*SWS_Dcm_01593*//*SWS_Dcm_01594*/
        Result = Dcm_ProcessRequestTransferExit(OpStatus, &(pMsgContext->reqData[DCM_INDEX_1]), ReqRecSize, \
                    &(pMsgContext->resData[DCM_INDEX_1]), &ResRecSize, pErrorCode);
        
        if(Result == E_OK)
        {
            /*Reset the Down/Up load state.*/
            DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_NONE;

            /*Calculate the positive response message length.*/
            pMsgContext->resDataLen = (DCM_LENGTH_1_BYTE + ResRecSize);
        }
        /*SWS_Dcm_00759*/
    }

    if((Result == E_NOT_OK) && (*pErrorCode != DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT))
    {
        /*Stop the data transmission.*/
        DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_NONE;
    }

    return Result;
}
#endif


#if(DCM_UDS_38_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_38_RequestFileTransfer SWS_Dcm_01083
*
* Description: Request the start of a file transfer process according to ISO-14229-1.
*
* Inputs: OpStatus,pMsgContext
*
* Outputs: pMsgContext,pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: Only used by UDS 0x38 service
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_38_RequestFileTransfer
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_NONE;
        DCM_FILE_TRANSFER_FP = NULL_PTR;
        DCM_FILE_TRANSFER_FSUC = (uint64)0;
        DCM_FILE_TRANSFER_FSC = (uint64)0;
        DCM_FILE_TRANSFER_MNROB = (uint64)0;
        DCM_FILE_TRANSFER_MOOP = (pMsgContext->reqData[DCM_INDEX_1]);
        DCM_FILE_TRANSFER_FPL = Make16Bit(pMsgContext->reqData[DCM_INDEX_2], pMsgContext->reqData[DCM_INDEX_3]);

        /*SWS_Dcm_01449, If the modeOfOperation parameter is not supported (0x00 or greater than 0x05),
        the Dcm shall send a negative response with NRC 0x31.*/
        if((DCM_FILE_TRANSFER_MOOP < DCM_ADD_FILE) || (DCM_FILE_TRANSFER_MOOP > DCM_READ_DIR))
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else if((DCM_FILE_TRANSFER_FPL == (uint16)0) || (DCM_FILE_TRANSFER_FPL > DCM_DSP_RFT_MAX_FILE_AND_DIR_NAME))
        {
            /*Length check*/
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
            /*Full length check*/
            Result = DspInternal_38_FullLengthCheck(pMsgContext, pErrorCode);
        }
    }/*if(OpStatus == DCM_INITIAL)*/

    if((OpStatus != DCM_CANCEL) && (Result == E_OK))
    {
        Result = DspInternal_38_ProcessFileTransfer(OpStatus, pMsgContext, pErrorCode);

        if(Result == E_OK)
        {
            if(DCM_FILE_TRANSFER_MOOP != DCM_DELETE_FILE)
            {
                DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_FILE_TRANSFER;
            }
            DCM_DOWN_UP_LOAD_PRE_BSC = DCM_BSC_INIT_VALUE;
            DCM_DOWN_UP_LOAD_NEXT_BSC = DCM_BSC_INIT_VALUE;
            /*Creat the response data*/
            pMsgContext->resData[DCM_INDEX_1] = DCM_FILE_TRANSFER_MOOP;/*Length format identifier*/
        }
        else
        {
            /*E_NOT_OK SWS_Dcm_01088 send a negative response with NRC code equal to the parameter ErrorCode parameter value.*/
            /*DCM_E_PENDING: Request is not yet finished*/
            /*DCM_E_FORCE_RCRRP: Send NRC 0x78*/
        }
    }

    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_38_FullLengthCheck
*
* Description: Used to verify in detail whether the length of diagnostic
*              request data is valid.
*
* Inputs: pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: Only used by UDS 0x38 service
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_38_FullLengthCheck
(
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 FileSizeParameterLength;

    switch(DCM_FILE_TRANSFER_MOOP)
    {
    case DCM_ADD_FILE:
    case DCM_REPLACE_FILE:
        /*DCM_LENGTH_8_BYTE: SID 1 byte + MOOP 1 byte + FPL 2 bytes + DFI 1 byte + FSL 1 byte
         + FSUC at lease 1 byte + FSC at lease 1 byte*/
        if((pMsgContext->reqDataLen) < (DCM_FILE_TRANSFER_FPL + DCM_LENGTH_8_BYTE))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else
        {
            FileSizeParameterLength = pMsgContext->reqData[(DCM_FILE_TRANSFER_FPL + DCM_INDEX_5)];

            /*SWS_Dcm_01448 If the fileSizeParameterLength parameter in request is outside the closed
             interval [0x01..0x08], the Dcm shall send a negative response with NRC 0x31.*/
            if((FileSizeParameterLength == (uint8)0) || (FileSizeParameterLength > DCM_LENGTH_8_BYTE))
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
            else if((pMsgContext->reqDataLen) != (DCM_FILE_TRANSFER_FPL + DCM_LENGTH_6_BYTE + FileSizeParameterLength + FileSizeParameterLength))
            {
                /*DCM_LENGTH_6_BYTE: SID 1 byte + MOOP 1 byte + FPL 2 bytes + DFI 1 byte + FSL 1 byte*/
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                Result = E_NOT_OK;
            }
            else
            {
                /*Length is valid.*/
            }
        }
        break;

    case DCM_DELETE_FILE:
    case DCM_READ_DIR:
        /*DCM_LENGTH_4_BYTE: SID 1 byte + MOOP 1 byte + FPL 2 bytes*/
        if((pMsgContext->reqDataLen) != (DCM_FILE_TRANSFER_FPL + DCM_LENGTH_4_BYTE))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        break;

    default:/*DCM_READ_FILE*/
        /*DCM_LENGTH_5_BYTE: SID 1 byte + MOOP 1 byte + FPL 2 bytes + DFI 1 byte*/
        if((pMsgContext->reqDataLen) != (DCM_FILE_TRANSFER_FPL + DCM_LENGTH_5_BYTE))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        break;
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_38_ProcessFileTransfer
*
* Description: Call the specific function based on the ModeOfOperation and create positive response data.
*
* Inputs: OpStatus,pMsgContext
*
* Outputs: pMsgContext,pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: Only used by UDS 0x38 service
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 2790 ++*/
/*The value range of DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER and DCM_DSP_RFT_FILESIZE_DIRINFO_PARAMETER_LENGTH are both 1-4.
So all right hand operand of shift operator are fine.*/

/*PRQA S 2880,2992,2996 ++*/
/*The value of DCM_FILE_TRANSFER_MNROB,DCM_FILE_TRANSFER_FSUC,DCM_FILE_TRANSFER_FSC come from APP and may be langer than
the maximum value that can be represented by a 32-bit unsigned number.*/

/*PRQA S 4700 ++*/
/*There is not limit on the number of lines of function code and the number of local variable assignments.*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_38_ProcessFileTransfer
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 FileSizeParameterLength;
    uint8 Idx;
    uint8* DataPtr;

    switch(DCM_FILE_TRANSFER_MOOP)
    {
    case DCM_ADD_FILE:
    case DCM_REPLACE_FILE:
        if(OpStatus == DCM_INITIAL)
        {
            DCM_FILE_TRANSFER_FP = &(pMsgContext->reqData[DCM_INDEX_4]);
            DCM_DOWN_UP_LOAD_DFI = pMsgContext->reqData[(DCM_FILE_TRANSFER_FPL + DCM_INDEX_4)];
            FileSizeParameterLength = pMsgContext->reqData[(DCM_FILE_TRANSFER_FPL + DCM_INDEX_5)];
            DataPtr = &(pMsgContext->reqData[(DCM_FILE_TRANSFER_FPL + DCM_INDEX_6)]);

            for(Idx = (uint8)0; Idx < FileSizeParameterLength; Idx++)
            {
                DCM_FILE_TRANSFER_FSUC |= ((uint64)(DataPtr[Idx]) << (uint8)(DCM_SHIFT_8 * (FileSizeParameterLength - DCM_INDEX_1 - Idx)));
            }

            DataPtr = &(pMsgContext->reqData[(DCM_FILE_TRANSFER_FPL + DCM_INDEX_6 + FileSizeParameterLength)]);

            for(Idx = (uint8)0; Idx < FileSizeParameterLength; Idx++)
            {
                DCM_FILE_TRANSFER_FSC |= ((uint64)(DataPtr[Idx]) << (uint8)(DCM_SHIFT_8 * (FileSizeParameterLength - DCM_INDEX_1 - Idx)));
            }
        }

        if(DCM_ADD_FILE == DCM_FILE_TRANSFER_MOOP)
        {
            /*SWS_Dcm_01450*/
            Result = Dcm_ProcessRequestAddFile(OpStatus, DCM_FILE_TRANSFER_FPL, DCM_FILE_TRANSFER_FP, DCM_DOWN_UP_LOAD_DFI, \
                        DCM_FILE_TRANSFER_FSUC, DCM_FILE_TRANSFER_FSC, &DCM_FILE_TRANSFER_MNROB, pErrorCode);
        }
        else
        {
            /*SWS_Dcm_01452*/
            Result = Dcm_ProcessRequestReplaceFile(OpStatus, DCM_FILE_TRANSFER_FPL, DCM_FILE_TRANSFER_FP, DCM_DOWN_UP_LOAD_DFI, \
                        DCM_FILE_TRANSFER_FSUC, DCM_FILE_TRANSFER_FSC, &DCM_FILE_TRANSFER_MNROB, pErrorCode);
        }

        if(Result == E_OK)
        {
            if((uint64)0 != (DCM_FILE_TRANSFER_MNROB >> (uint8)(DCM_SHIFT_8 * DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER)))
            {
                /*SWS_Dcm_01457*/
                *pErrorCode = DCM_E_GENERALREJECT;
                Result = E_NOT_OK;
            }
            else
            {
                /*Creat positive response data*/
                /*SWS_Dcm_01456*/
                pMsgContext->resData[DCM_INDEX_2] = DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER;
                /*SWS_Dcm_01091*/
                DataPtr = &(pMsgContext->resData[DCM_INDEX_3]);

                for(Idx = (uint8)0; Idx < DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER; Idx++)
                {
                    /*PRQA S 1891 ++*/
                    DataPtr[Idx] = (uint8)(DCM_FILE_TRANSFER_MNROB >> (DCM_SHIFT_8 * (DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER - (uint8)DCM_INDEX_1 - Idx)));
                    /*PRQA S 1891 --*/
                }

                pMsgContext->resData[DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER + DCM_INDEX_3] = DCM_DOWN_UP_LOAD_DFI;
                /*Set the positive response length*/
                pMsgContext->resDataLen = (DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER + DCM_LENGTH_4_BYTE);
            }
        }
        break;

    case DCM_DELETE_FILE:
        if(OpStatus == DCM_INITIAL)
        {
            DCM_FILE_TRANSFER_FP = &(pMsgContext->reqData[DCM_INDEX_4]);
        }
        /*SWS_Dcm_01451*/
        Result = Dcm_ProcessRequestDeleteFile(OpStatus, DCM_FILE_TRANSFER_FPL, DCM_FILE_TRANSFER_FP, pErrorCode);

        if(Result == E_OK)
        {
            /*Set the positive response length*/
            pMsgContext->resDataLen =  DCM_LENGTH_2_BYTE;
        }
        break;

    case DCM_READ_FILE:
        if(OpStatus == DCM_INITIAL)
        {
            DCM_FILE_TRANSFER_FP = &(pMsgContext->reqData[DCM_INDEX_4]);
            DCM_DOWN_UP_LOAD_DFI = pMsgContext->reqData[(DCM_FILE_TRANSFER_FPL + DCM_INDEX_4)];
        }
        /*SWS_Dcm_01453*/
        Result = Dcm_ProcessRequestReadFile(OpStatus, DCM_FILE_TRANSFER_FPL, DCM_FILE_TRANSFER_FP, DCM_DOWN_UP_LOAD_DFI, \
                        &DCM_FILE_TRANSFER_FSUC, &DCM_FILE_TRANSFER_FSC, &DCM_FILE_TRANSFER_MNROB, pErrorCode);
        
        if(Result == E_OK)
        {
            if((uint64)0 != (DCM_FILE_TRANSFER_MNROB >> (uint8)(DCM_SHIFT_8 * DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER)))
            {
                /*SWS_Dcm_01457*/
                *pErrorCode = DCM_E_GENERALREJECT;
                Result = E_NOT_OK;
            }
            else if(((uint64)0 != (DCM_FILE_TRANSFER_FSUC >> (uint8)(DCM_SHIFT_8 * DCM_DSP_RFT_FILESIZE_DIRINFO_PARAMETER_LENGTH))) \
                || ((uint64)0 != (DCM_FILE_TRANSFER_FSC >> (uint8)(DCM_SHIFT_8 * DCM_DSP_RFT_FILESIZE_DIRINFO_PARAMETER_LENGTH))))
            {
                /*SWS_Dcm_01458*/
                *pErrorCode = DCM_E_GENERALREJECT;
                Result = E_NOT_OK;
            }
            else
            {
                /*Creat positive response data*/
                /*SWS_Dcm_01456*/
                pMsgContext->resData[DCM_INDEX_2] = DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER;
                /*SWS_Dcm_01091*/
                DataPtr = &(pMsgContext->resData[DCM_INDEX_3]);

                for(Idx = (uint8)0; Idx < DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER; Idx++)
                {
                    /*PRQA S 1891 ++*/
                    DataPtr[Idx] = (uint8)(DCM_FILE_TRANSFER_MNROB >> (DCM_SHIFT_8 * (DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER - (uint8)DCM_INDEX_1 - Idx)));
                    /*PRQA S 1891 --*/
                }

                pMsgContext->resData[DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER + DCM_INDEX_3] = DCM_DOWN_UP_LOAD_DFI;
                /*SWS_Dcm_01455*/
                pMsgContext->resData[DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER + DCM_INDEX_4] = (uint8)0;
                pMsgContext->resData[DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER + DCM_INDEX_5] = DCM_DSP_RFT_FILESIZE_DIRINFO_PARAMETER_LENGTH;
                /*SWS_Dcm_01090*/
                DataPtr = &(pMsgContext->resData[DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER + DCM_INDEX_6]);

                for(Idx = (uint8)0; Idx < DCM_DSP_RFT_FILESIZE_DIRINFO_PARAMETER_LENGTH; Idx++)
                {
                    /*PRQA S 1891 ++*/
                    DataPtr[Idx] = (uint8)(DCM_FILE_TRANSFER_FSUC >> (DCM_SHIFT_8 * (DCM_DSP_RFT_FILESIZE_DIRINFO_PARAMETER_LENGTH - (uint8)DCM_INDEX_1 - Idx)));
                    /*PRQA S 1891 --*/
                }

                DataPtr = &(DataPtr[DCM_DSP_RFT_FILESIZE_DIRINFO_PARAMETER_LENGTH]);

                for(Idx = (uint8)0; Idx < DCM_DSP_RFT_FILESIZE_DIRINFO_PARAMETER_LENGTH; Idx++)
                {
                    /*PRQA S 1891 ++*/
                    DataPtr[Idx] = (uint8)(DCM_FILE_TRANSFER_FSC >> (DCM_SHIFT_8 * (DCM_DSP_RFT_FILESIZE_DIRINFO_PARAMETER_LENGTH - (uint8)DCM_INDEX_1 - Idx)));
                    /*PRQA S 1891 --*/
                }

                /*Set the positive response length*/
                pMsgContext->resDataLen = DCM_LENGTH_6_BYTE;
                pMsgContext->resDataLen += DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER;/*maxNumberOfBlockLength*/
                pMsgContext->resDataLen += DCM_DSP_RFT_FILESIZE_DIRINFO_PARAMETER_LENGTH;/*fileSizeUncompressedOrDirInfoLength*/
                pMsgContext->resDataLen += DCM_DSP_RFT_FILESIZE_DIRINFO_PARAMETER_LENGTH;/*fileSizeCompressed*/
            }
        }
        break;

    default:/*DCM_READ_DIR*/
        if(OpStatus == DCM_INITIAL)
        {
            DCM_FILE_TRANSFER_FP = &(pMsgContext->reqData[DCM_INDEX_4]);
        }
        /*SWS_Dcm_01454*/
        Result = Dcm_ProcessRequestReadDir(OpStatus, DCM_FILE_TRANSFER_FPL, DCM_FILE_TRANSFER_FP, &DCM_FILE_TRANSFER_FSUC, \
                    &DCM_FILE_TRANSFER_MNROB, pErrorCode);
        
        if(Result == E_OK)
        {
            if((uint64)0 != (DCM_FILE_TRANSFER_MNROB >> (uint8)(DCM_SHIFT_8 * DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER)))
            {
                /*SWS_Dcm_01457*/
                *pErrorCode = DCM_E_GENERALREJECT;
                Result = E_NOT_OK;
            }
            else if((uint64)0 != (DCM_FILE_TRANSFER_FSUC >> (uint8)(DCM_SHIFT_8 * DCM_DSP_RFT_FILESIZE_DIRINFO_PARAMETER_LENGTH)))
            {
                /*SWS_Dcm_01458*/
                *pErrorCode = DCM_E_GENERALREJECT;
                Result = E_NOT_OK;
            }
            else
            {
                /*Creat positive response data*/
                /*SWS_Dcm_01456*/
                pMsgContext->resData[DCM_INDEX_2] = DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER;
                /*SWS_Dcm_01091*/
                DataPtr = &(pMsgContext->resData[DCM_INDEX_3]);

                for(Idx = (uint8)0; Idx < DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER; Idx++)
                {
                    /*PRQA S 1891 ++*/
                    DataPtr[Idx] = (uint8)(DCM_FILE_TRANSFER_MNROB >> (DCM_SHIFT_8 * (DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER - (uint8)DCM_INDEX_1 - Idx)));
                    /*PRQA S 1891 --*/
                }

                pMsgContext->resData[DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER + DCM_INDEX_3] = (uint8)0;
                /*SWS_Dcm_01455*/
                pMsgContext->resData[DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER + DCM_INDEX_4] = (uint8)0;
                pMsgContext->resData[DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER + DCM_INDEX_5] = DCM_DSP_RFT_FILESIZE_DIRINFO_PARAMETER_LENGTH;
                /*SWS_Dcm_01090*/
                DataPtr = &(pMsgContext->resData[DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER + DCM_INDEX_6]);

                for(Idx = (uint8)0; Idx < DCM_DSP_RFT_FILESIZE_DIRINFO_PARAMETER_LENGTH; Idx++)
                {
                    /*PRQA S 1891 ++*/
                    DataPtr[Idx] = (uint8)(DCM_FILE_TRANSFER_FSUC >> (DCM_SHIFT_8 * (DCM_DSP_RFT_FILESIZE_DIRINFO_PARAMETER_LENGTH - (uint8)DCM_INDEX_1 - Idx)));
                    /*PRQA S 1891 --*/
                }

                /*Set the positive response length*/
                pMsgContext->resDataLen = DCM_LENGTH_6_BYTE;
                pMsgContext->resDataLen += DCM_DSP_RFT_LENGTH_FORMAT_IDENTIFIER;/*maxNumberOfBlockLength*/
                pMsgContext->resDataLen += DCM_DSP_RFT_FILESIZE_DIRINFO_PARAMETER_LENGTH;/*fileSizeUncompressedOrDirInfoLength*/
            }
        }
        break;
    }

    return Result;
}
/*PRQA S 4700 --*/
/*PRQA S 2880,2992,2996 --*/
/*PRQA S 2790 --*/
#endif/*#if(DCM_UDS_38_ENABLED == STD_ON)*/

#if(DCM_UDS_3D_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_3D_WriteMemoryByAddress SWS_Dcm_00488
*
* Description: This function is the code implementation of the processing logic
*              for the 0x3D service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_3D_WriteMemoryByAddress
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    Dcm_SessionMaskType SesLevelRef;
#if(DCM_UDS_27_ENABLED == STD_ON)
    Dcm_SecurityMaskType SecLevelRef;
    Dcm_SecurityMaskType CurSecMask;
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
    Dcm_AuRoleMaskType AuRoleMask;
#endif
    uint8 AddrSizeFormat;
    uint8 AddrLength;
    uint8 SizeLength;
    uint8 Idx;/*Index*/
    uint16 MemRangeIdx = (uint16)0;/*Index of memory range info*/

    if(OpStatus == DCM_INITIAL)
    {
        DCM_MEM_START_ADDR = (uint32)0;
        DCM_MEM_SIZE = (uint32)0;
        DCM_MEM_ID = DCM_DATA_CLEAR;
        AddrSizeFormat = (pMsgContext->reqData[DCM_INDEX_1]);
        AddrLength = (AddrSizeFormat & (DCM_MEM_FORMAT_ADDR_MASK));
        SizeLength = ((AddrSizeFormat & (DCM_MEM_FORMAT_SIZE_MASK)) >> DCM_SHIFT_4);
        /*SWS_Dcm_00855,Check addressAndLengthFormatIdentifier*/
        if(DCM_CFG_MEM_FORMAT_NUM != DCM_DATA_CLEAR)
        {
            Result = E_NOT_OK;
            for(Idx = (uint8)0; Idx < DCM_CFG_MEM_FORMAT_NUM; Idx++)
            {
                if(AddrSizeFormat == DCM_CFG_MEM_FORMAT(Idx))
                {
                    Result = E_OK;
                    break;
                }
            }
        }

        if((Result == E_NOT_OK) || (AddrLength == DCM_DATA_CLEAR) || (SizeLength == DCM_DATA_CLEAR))
        {
            *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Result = E_NOT_OK;
        }
        else
        {
            /* Calculate start address */
            for(Idx = (uint8)0; Idx < AddrLength; Idx++)
            {
                DCM_MEM_START_ADDR |= (uint32)(pMsgContext->reqData[DCM_INDEX_2 + Idx]) << (uint8)(DCM_SHIFT_8 * (AddrLength - DCM_INDEX_1 - Idx));
            }

            /*Calculate size*/
            for(Idx = (uint8)0; Idx < SizeLength; Idx++)
            {
                DCM_MEM_SIZE |= (uint32)(pMsgContext->reqData[DCM_INDEX_2 + AddrLength + Idx]) << (uint8)(DCM_SHIFT_8 * (SizeLength - DCM_INDEX_1 - Idx));
            }

            /*total length check*/
            if(((pMsgContext->reqDataLen) != (DCM_LENGTH_2_BYTE + AddrLength + SizeLength + DCM_MEM_SIZE)) \
                || (DCM_MEM_SIZE == (uint32)0))
            {
                *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                Result = E_NOT_OK;
            }
        }
        /*check memory range & security & session*/
        if(Result == E_OK)
        {
            Result = E_NOT_OK;
            /*SWS_Dcm_00489*//*SWS_Dcm_01052*/
            for(Idx = (uint8)0; Idx < DCM_CFG_MEM_ID_NUM; Idx++)
            {
                for(MemRangeIdx = (uint16)0; MemRangeIdx < DCM_CFG_MEM_ID_WRITE_NUM(Idx); MemRangeIdx++)
                {
                    if((DCM_MEM_START_ADDR <= DCM_CFG_MEM_ID_WRITE_HIGH(Idx, MemRangeIdx)) \
                        && (DCM_MEM_START_ADDR >= DCM_CFG_MEM_ID_WRITE_LOW(Idx, MemRangeIdx)) \
                        && (((DCM_MEM_START_ADDR + DCM_MEM_SIZE) - DCM_LENGTH_1_BYTE) <= DCM_CFG_MEM_ID_WRITE_HIGH(Idx, MemRangeIdx)))
                    {
                        DCM_MEM_ID = DCM_CFG_MEM_ID_VALUE(Idx);
                        Result = E_OK;
                        break;
                    }
                }

                if(Result == E_OK)
                {
                    break;
                }
            }

            if(Result == E_NOT_OK)
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
            }
            else
            {
                /*check security & session*/
                SesLevelRef = DCM_CFG_MEM_ID_WRITE_SESREF(Idx, MemRangeIdx);
#if(DCM_UDS_27_ENABLED == STD_ON)
                SecLevelRef = DCM_CFG_MEM_ID_WRITE_SECREF(Idx, MemRangeIdx);
                CurSecMask = DslInternal_GetSecurityMask();
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
                AuRoleMask = DCM_CFG_MEM_ID_WRITE_ROLEREF(Idx, MemRangeIdx);
#endif
                if(!(DCM_CFG_SESSION_MASK(DCM_SES_IDX) & SesLevelRef))
                {
                    *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    Result = E_NOT_OK;
                }
#if(DCM_UDS_29_ENABLED == STD_ON)
                else if(!(DCM_AU_CUR_ROLE & AuRoleMask))
                {
                    /*SWS_Dcm_01551*/
                    *pErrorCode = DCM_E_AUTHENTICATIONREQUIRED;
                    Result = E_NOT_OK;
                }
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
                else if(!(CurSecMask & SecLevelRef))
                {
                    /*SWS_Dcm_00490*/
                    *pErrorCode = DCM_E_SECURITYACCESSDENIED;
                    Result = E_NOT_OK;
                }
#endif
                else
                {
                    DCM_MEM_DATA_PTR = &(pMsgContext->reqData[DCM_INDEX_2 + AddrLength + SizeLength]);
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
                    SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif
                    /*Call Dcm_WriteMemory()*/
                }
            }
        }
    }/*if(OpStatus == DCM_INITIAL)*/

    if((OpStatus != DCM_CANCEL) && (Result == E_OK))
    {
        /*SWS_Dcm_00491*/
        Result = DspInternal_WriteMemory(DCM_3D_SERVICE, OpStatus, DCM_MEM_ID, DCM_MEM_START_ADDR, DCM_MEM_SIZE, DCM_MEM_DATA_PTR, pErrorCode);

        if(Result == E_OK)
        {
            AddrSizeFormat = (pMsgContext->reqData[DCM_INDEX_1]);
            AddrLength = (AddrSizeFormat & (DCM_MEM_FORMAT_ADDR_MASK));
            SizeLength = ((AddrSizeFormat & (DCM_MEM_FORMAT_SIZE_MASK)) >> DCM_SHIFT_4);
            /*Set the response length*/
            pMsgContext->resDataLen = (DCM_LENGTH_2_BYTE + AddrLength + SizeLength);
            /*Copy the request address and size info of write data from request buffer to response buffer.*/
            Bsw_MemCpy((pMsgContext->resData), (pMsgContext->reqData), (pMsgContext->resDataLen));
        }
    }
    return Result;
}
/*PRQA S 4700 --*/

#endif

#if(DCM_UDS_3E_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_3E_TesterPresent
*
* Description: This function is the code implementation of the processing logic
*              for the 0x3E service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_3E_TesterPresent
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    (void)OpStatus;
#if(DCM_UDS_3E_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
    ClearSuppressPosRespBit();
#endif

    if((pMsgContext->reqDataLen) != DCM_LENGTH_2_BYTE)
    {
        *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        Result = E_NOT_OK;
    }
    else
    {
        pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
        pMsgContext->resDataLen = DCM_LENGTH_2_BYTE;
    }
    return Result;
}
#endif

#if(DCM_UDS_85_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_85_ControlDTCSetting SWS_Dcm_00249
*
* Description: This function is the code implementation of the processing logic
*              for the 0x85 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_85_ControlDTCSetting
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
#if(DCM_DEM_SUPPORT == STD_ON)
    uint8 DemClient = DCM_CFG_PCL_DEM_CLIENT(DCM_ACTIVE_PCL_ID);
#endif

    if(OpStatus == DCM_INITIAL)
    {
#if(DCM_UDS_85_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
        ClearSuppressPosRespBit();
#endif
#if(DCM_DEM_SUPPORT == STD_OFF)
        if((DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceFnc) == NULL_PTR)
        {
            *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
            Result = E_NOT_OK;
        }
        else
#endif
#if(DCM_SUPPORT_DTC_RECORD == STD_OFF)
        /*SWS_Dcm_00852*//*SWS_Dcm_01564*/
        if((pMsgContext->reqDataLen) != DCM_LENGTH_2_BYTE)
#else
        /*SWS_Dcm_00829*/
        if((pMsgContext->reqDataLen) != DCM_LENGTH_5_BYTE)
#endif
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
#if(DCM_SUPPORT_DTC_RECORD == STD_ON)
        else
        {
            /*SWS_Dcm_01399*/
            if(((pMsgContext->reqData[DCM_INDEX_2]) != DCM_DATA_U8_MAX) || ((pMsgContext->reqData[DCM_INDEX_3]) != DCM_DATA_U8_MAX) \
                || ((pMsgContext->reqData[DCM_INDEX_4]) != DCM_DATA_U8_MAX))
            {
                *pErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Result = E_NOT_OK;
            }
        }
#endif
    }

    if((OpStatus != DCM_CANCEL) && (Result == E_OK))
    {
#if(DCM_DEM_SUPPORT == STD_ON)
        switch(DCM_REQ_SUBSERVICE)
        {
        case DCM_DTC_SETTING_ON:
            /*SWS_Dcm_01063*/
            Result = Dem_EnableDTCSetting(DemClient);

            if(Result == E_OK)
            {
                /*SWS_Dcm_00783*/
                (void)SchM_Switch_DcmControlDtcSetting(RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING);
            }
            break;

        case DCM_DTC_SETTING_OFF:
            /*SWS_Dcm_00406*/
            Result = Dem_DisableDTCSetting(DemClient);

            if(Result == E_OK)
            {
                /*SWS_Dcm_00784*/
                (void)SchM_Switch_DcmControlDtcSetting(RTE_MODE_DcmControlDtcSetting_DISABLEDTCSETTING);
            }
            break;

        default:
            *pErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
            Result = E_NOT_OK;
            break;
        }

        if(Result == DEM_PENDING)
        {
            Result = DCM_E_PENDING;
        }
#else
        DCM_SUBSERVICE_FNC = (DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceFnc);
        Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
#endif/*#if(DCM_DEM_SUPPORT == STD_ON)*/
    }

    if(Result == E_OK)
    {
#if(DCM_UDS_10_ENABLED == STD_ON)
        DCM_85_SUB_SESREF = (DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceSessionLevelRef);
#endif
        pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
        pMsgContext->resDataLen = DCM_LENGTH_2_BYTE;
    }
    return Result;
}
#endif

#if(DCM_UDS_87_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_87_LinkControl
*
* Description: This function is the code implementation of the processing logic
*              for the 0x87 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_87_LinkControl
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

    if(OpStatus == DCM_INITIAL)
    {
#if(DCM_UDS_87_SUPPORT_SUPPRESSPOSRESBIT != STD_ON)
        ClearSuppressPosRespBit();
#endif
        /*SWS_Dcm_00272 Trigger NRC 0x13 when the analysis of the request message results in formatting or length failure.*/
        if((DCM_REQ_SUBSERVICE == DCM_VERIFY_FIXED_PARAMETER) && (pMsgContext->reqDataLen != DCM_LENGTH_3_BYTE))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else if((DCM_REQ_SUBSERVICE == DCM_VERIFY_SPECIFIC_PARAMETER) && (pMsgContext->reqDataLen != DCM_LENGTH_5_BYTE))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        else if((DCM_REQ_SUBSERVICE == DCM_TRANSITION_MODE) && (pMsgContext->reqDataLen != DCM_LENGTH_2_BYTE))
        {
            *pErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Result = E_NOT_OK;
        }
        /*Check sequence*/
        else if((DCM_REQ_SUBSERVICE == DCM_TRANSITION_MODE) && (DCM_87_VERIFIED == DCM_DATA_CLEAR))
        {
            *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
            Result = E_NOT_OK;
        }
        /*Get the sub service function*/
        else
        {
            if(NULL_PTR != (DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceFnc))
            {
                DCM_SUBSERVICE_FNC = (DCM_REQ_SUBSERVICEINFO->DcmDsdSubServiceFnc);
            }
            else
            {
                *pErrorCode = DCM_E_REQUESTSEQUENCEERROR;
                Result = E_NOT_OK;
            }
        }
    }/*if(OpStatus == DCM_INITIAL)*/

    if((OpStatus != DCM_CANCEL) && (Result == E_OK))
    {
        Result = (*DCM_SUBSERVICE_FNC)(OpStatus, pMsgContext, pErrorCode);
    }

    /*Send positive response*/
    if(Result == E_OK)
    {
        if(DCM_REQ_SUBSERVICE != DCM_TRANSITION_MODE)
        {
            DCM_87_VERIFIED = DCM_REQ_SUBSERVICE;
        }
        else
        {
            DCM_87_VERIFIED = DCM_DATA_CLEAR;
        }
        pMsgContext->resData[DCM_SUB_SID_INDEX] = DCM_REQ_SUBSERVICE;
        pMsgContext->resDataLen = DCM_LENGTH_2_BYTE;
    }
    return Result;
}
#endif


/*******************************************************************************
* Local Function definition
*******************************************************************************/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DsdInternal_ResetWithoutChangeSessionAndSendResponse
*
* Description: Used to reset Dcm state to IDLE, will not change session state
*              and send any response.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DsdInternal_ResetWithoutChangeSessionAndSendResponse
(
    void
)
{
    if(DCM_SES_IDX != DCM_DEFAULT_IDX)
    {
        /*Start S3 Timer*/
        SetS3Timer(DCM_CFG_PCL_S3(DCM_ACTIVE_PCL_ID));
    }
    else
    {
        /*SWS_Dcm_01482*/
#if(STD_ON == DCM_UDS_29_ENABLED)
        if((DCM_AU_STATE & DCM_AU_STATE_AUTHENTICATED) != DCM_AU_STATE_DEAUTHENTICATED)
        {
            SetAuthenticationTimer();
        }
#endif
        /*SWS_Dcm_01374*/
        COMM_DCM_INACTIVEDIAGNOSTIC(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
    }
    DcmInternal_InitMsgContext();
    ClearP2Timer();
    ClearRespPendCounter();
    ResetDcmState();
}

/*******************************************************************************
* Global Function definition
*******************************************************************************/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_Init SWS_Dcm_00037
*
* Description: Service for basic initialization of DCM module.
*
* Inputs: ConfigPtr: Pointer to configuration set in Variant Post-Build.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) Dcm_Init
(
    P2CONST(Dcm_ConfigType, AUTOMATIC, DCM_APPL_DATA) ConfigPtr
)
{
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
    (void)ConfigPtr;
#else
    Dcm_PBConfig = ConfigPtr;

    if(NULL_PTR == Dcm_PBConfig)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_INIT, DCM_E_PARAM_POINTER);
    }
    else
#endif
    {
        /*SWS_Dcm_00034 During Dcm initialization, the session state is set to the value 0x01 ("DefaultSession").*/
        DCM_SES_IDX = DCM_DEFAULT_IDX;
        /*Init Dcm context*/
        DcmInternal_InitDcmContext();

#if(DCM_UDS_27_ENABLED == STD_ON)
        DslInternal_Init_SecurityLevel();
#endif
#if(DCM_UDS_28_ENABLED == STD_ON)
        DspInternal_Init_CommunicationState();
#endif
#if(DCM_UDS_29_ENABLED == STD_ON)
        DspInternal_Init_Authentication();
#endif

#if(DCM_UDS_2A_ENABLED == STD_ON)
        DspInternal_Reset_PeriodicDid();
#endif

#if(DCM_UDS_31_ENABLED == STD_ON)
        DspInternal_Reset_RoutineStatus();
#endif

#if((DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON) || (DCM_UDS_38_ENABLED == STD_ON))
        DCM_DOWN_UP_LOAD_STATUS = DCM_LOAD_NONE;
#endif

#if((DCM_OBD_01_ENABLED == STD_ON) || (DCM_OBD_02_ENABLED == STD_ON) \
    || (DCM_OBD_08_ENABLED == STD_ON) || (DCM_OBD_09_ENABLED == STD_ON))
        DcmInternal_Init_AvailabilityParameters();
#endif

#if(DCM_UDS_27_ENABLED == STD_ON)
        if(DCM_SEC_ALL_INIT == TRUE)
#endif
        {
            Dcm_InitState = STD_INITIALIZED;
        }
    }
}


#if(STD_ON == DCM_VERSION_INFO_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_GetVersionInfo SWS_Dcm_00065
*
* Description: Returns the version information of this module
*
* Inputs: None
*
* Outputs: versionInfo:Pointer to where to store the version information of
*          this module.
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) Dcm_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DCM_APPL_DATA) versionInfo
)
{
    if(NULL_PTR == versionInfo)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETVERSIONINFO, DCM_E_PARAM_POINTER);
    }
    else
    {
        versionInfo->vendorID = DCM_VENDOR_ID;
        versionInfo->moduleID = DCM_MODULE_ID;

        versionInfo->sw_major_version = (uint8)DCM_SW_MAJOR_VERSION;
        versionInfo->sw_minor_version = (uint8)DCM_SW_MINOR_VERSION;
        versionInfo->sw_patch_version = (uint8)DCM_SW_PATCH_VERSION;
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_GetVin SWS_Dcm_00950
*
* Description: Function to get the VIN (as defined in SAE J1979-DA)
*
* Inputs: None
*
* Outputs: Data: Pointer to where to store the VIN
*
* Return: E_OK: The Data pointer has been filled with valid VIN
*         E_NOT_OK: The default VIN will be used in the DoIP
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_GetVin
(
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data
)
{
    Std_ReturnType Result = E_NOT_OK;
#if((DCM_UDS_22_ENABLED == STD_ON) && (DCM_VIN_REF != DCM_INVALID_VIN_REF))
    uint8 ProtocolId = (uint8)(DCM_VIN_REF >> DCM_SHIFT_16);
    uint16 DidIdx = (uint16)DCM_VIN_REF;
    uint8 StabId;
    uint16 DataNum;
    uint16 DataIdx;
    uint16 DataPos;
    uint16 DataRef;
    Dcm_NegativeResponseCodeType ErrorCode;/*useless*/

    if(Data == NULL_PTR)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETVIN, DCM_E_PARAM_POINTER);
    }
    else if(ProtocolId >= DCM_CFG_NUM_OF_PROTOCOL)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETVIN, DCM_E_PARAM);
    }
    else
    {
        StabId = DCM_CFG_PCL_STAB_IDX(ProtocolId);

        if(DidIdx >= (Dcm_DspDid[StabId].NumOfDid))
        {
            DCM_DET_REPORT_ERROR(DCM_SID_GETVIN, DCM_E_PARAM);
        }
        else
        {
            /*read all reference data*/
            for(DataIdx = (uint16)0; DataIdx < (Dcm_DspDid[StabId].Dcm_DspDidTable[DidIdx].NumOfDidSignal); DataIdx++)
            {
                DataPos = (Dcm_DspDid[StabId].Dcm_DspDidTable[DidIdx].DcmDspDidSignal[DataIdx].DcmDspDidByteOffset);
                DataRef = (Dcm_DspDid[StabId].Dcm_DspDidTable[DidIdx].DcmDspDidSignal[DataIdx].DcmDspDidDataRef);

                Result = (Dcm_DspData[StabId].DcmDspDataTable[DataRef].DcmDspDataReadFnc)(DCM_INITIAL, (Data + DataPos), &ErrorCode);

                if(Result != E_OK)
                {
                    Result = E_NOT_OK;
                    break;
                }
            }
        }
    }
#else
    (void)Data;
#endif
    return Result;
}

#if(STD_ON == DCM_UDS_29_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_SetDeauthenticatedRole SWS_Dcm_91069
*
* Description: Sets a new role used in deauthenticated state for that connection.
*              The set role is valid until the connection switches into authenticated
*              state or the ECU is reset.
*
* Inputs: connectionId: Unique connection identifier identifiying the connection
*                       for which a deauthenticated roles is set.
*         deauthenticatedRole: New deauthenticated role that is assigned to that
*                              connection
*
* Outputs: None
*
* Return: E_OK, E_NOT_OK
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_SetDeauthenticatedRole
(
    uint16 connectionId,
    Dcm_AuthenticationRoleType deauthenticatedRole
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(STD_UNINITIALIZED == Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_SETDEAUTHENTICATEDROLE, DCM_E_UNINIT);
    }
    else if(connectionId >= DCM_CFG_NUM_OF_CONNECTION)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_SETDEAUTHENTICATEDROLE, DCM_E_PARAM);
    }
    /*PRQA S 2880,2992,2996 ++*/
    /*Prevent users from passin in null pointer.*/
    else if(deauthenticatedRole == NULL_PTR)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_SETDEAUTHENTICATEDROLE, DCM_E_PARAM_POINTER);
    }
    /*PRQA S 2880,2992,2996 --*/
    else
    {
        if((DCM_ACTIVE_PCL_ID < DCM_CFG_NUM_OF_PROTOCOL) \
            && (DCM_CFG_PCL_CONNECTION_MAIN_CON_ID(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID) == connectionId) \
            && (DCM_AU_STATE != DCM_AU_STATE_DEAUTHENTICATED))
        {
            /*SWS_Dcm_01487*//*SWS_Dcm_01488*/
            /*A deauthenticated role set by Dcm_SetDeauthenticatedRole is discarded*/
        }
        else
        {
            /*SWS_Dcm_01486*/
#if(DCM_DSP_AUTHENTICATION_ROLE_SIZE >= 1)
            DCM_AU_DE_ROLE(connectionId) = (Dcm_AuRoleMaskType)(deauthenticatedRole[DCM_INDEX_0]);
#endif
#if(DCM_DSP_AUTHENTICATION_ROLE_SIZE >= 2)
            DCM_AU_DE_ROLE(connectionId) |= ((Dcm_AuRoleMaskType)(deauthenticatedRole[DCM_INDEX_1]) << DCM_SHIFT_8);
#endif
#if(DCM_DSP_AUTHENTICATION_ROLE_SIZE >= 3)
            DCM_AU_DE_ROLE(connectionId) |= ((Dcm_AuRoleMaskType)(deauthenticatedRole[DCM_INDEX_2]) << DCM_SHIFT_16);
#endif
#if(DCM_DSP_AUTHENTICATION_ROLE_SIZE >= 4)
            DCM_AU_DE_ROLE(connectionId) |= ((Dcm_AuRoleMaskType)(deauthenticatedRole[DCM_INDEX_3]) << DCM_SHIFT_24);
#endif

            Result = E_OK;
        }
    }

    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_SetAuthenticationDevelopmentState
*
* Description: Sets a new role used in deauthenticated state for that connection.
*              The set role is valid until the connection switches into authenticated
*              state or the ECU is reset.
*
* Inputs: TRUE means "Development State" is enabled, Service 0x29 will give detailed
*              negative response code.
*         FALSE means "Development State" is disabled, the generic fixed negative
*               response shall be: 7F 29 DcmDspAuthenticationGeneralNRC.
*
* Outputs: None
*
* Return: E_OK, E_NOT_OK
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_SetAuthenticationDevelopmentState
(
    boolean DevelopmentStateEnabled
)
{
    Std_ReturnType Result = E_NOT_OK;

    if(STD_UNINITIALIZED == Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_SETAUTHENTICATIONDEVELOPMENTSTATE, DCM_E_UNINIT);
    }
    else
    {
        DCM_AU_DEVELOP_ENABLED = DevelopmentStateEnabled;
        Result = E_OK;
    }

    return Result;
}

#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_ResetAuthenticationState
*
* Description: This API can be called by APP befor to force the ECU to enter the
*              unauthenticated state.
*
* Inputs: None
*
* Outputs: None
*
* Return: E_OK, E_NOT_OK
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_ResetAuthenticationState
(
    void
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint8 AuConId;

    if(STD_UNINITIALIZED == Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_RESETAUTHENTICATIONNSTATE, DCM_E_UNINIT);
    }
    else
    {
        if(DCM_AU_STATE != DCM_AU_STATE_DEAUTHENTICATED)
        {
            AuConId = DCM_CFG_PCL_CONNECTION_MAIN_AU_CONNECTION(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
            DspInternal_Reset_Authentication(AuConId);
        }
        Result = E_OK;
    }
    return Result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_GetAuthenticationNeedStoredInfo
*
* Description: This API will be called by APP befor ECU sleep or reset and APP should
*              store the acquired information in non-volatile memeory.
*
* Inputs: None
*
* Outputs: *ProtocolId, *ConnectionId
*          *IsAuthenticated: Indicates whether the ECU and tester have completed verification.
*          *CurrentRole: Role of the current connected tester.
*          AuConsecutiveFailedCounter[]: Array. Record the current number of consecutive
*                                       failures for each authentication connection.
*          *AuAbsoluteTimeoutTimer: If *IsAuthenticated is TRUE, the parameter indicates the
*                                   maximum remaining time to remain in the authenticated state.
*
* Return: E_OK, E_NOT_OK
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_GetAuthenticationNeedStoredInfo
(
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) ProtocolId,
    P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) ConnectionId,
    P2VAR(boolean, AUTOMATIC, DCM_APPL_DATA) IsAuthenticated,
    P2VAR(Dcm_AuRoleMaskType, AUTOMATIC, DCM_APPL_DATA) CurrentRole,
    P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) AuConsecutiveFailedCounter,
    P2VAR(uint32, AUTOMATIC, DCM_APPL_DATA) AuAbsoluteTimeoutTimer
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint16 ConId;

    if(STD_UNINITIALIZED == Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETAUTHENTICATIONNEEDSTOREDINFO, DCM_E_UNINIT);
    }
    else if((ProtocolId == NULL_PTR) || (ConnectionId == NULL_PTR) || (IsAuthenticated == NULL_PTR) || (CurrentRole == NULL_PTR) \
        || (AuConsecutiveFailedCounter == NULL_PTR) || (AuAbsoluteTimeoutTimer == NULL_PTR))
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETAUTHENTICATIONNEEDSTOREDINFO, DCM_E_PARAM_POINTER);
    }
    else
    {
        *ProtocolId = DCM_ACTIVE_PCL_ID;
        *ConnectionId = DCM_ACTIVE_CON_ID;

        if((DCM_AU_STATE & DCM_AU_STATE_AUTHENTICATED) != DCM_AU_STATE_DEAUTHENTICATED)
        {
            *IsAuthenticated = TRUE;
        }
        else
        {
            *IsAuthenticated = FALSE;
        }

        *CurrentRole = DCM_AU_CUR_ROLE;

        for(ConId = (uint16)0; ConId < DCM_CFG_NUM_OF_CONNECTION; ConId++)
        {
            AuConsecutiveFailedCounter[ConId] = DCM_AU_FAILED_CNT(ConId);
        }

        *AuAbsoluteTimeoutTimer = DCM_AU_ABSOLUTE_TIMER;

        Result = E_OK;
    }
    return Result;
}
#endif
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_GetSecurityLevel SWS_Dcm_00338
*
* Description: This function provides the active security level value.
*
* Inputs: None
*
* Outputs: Active Security Level value
*
* Return: E_OK: this value is always returned.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_GetSecurityLevel
(
    P2VAR(Dcm_SecLevelType, AUTOMATIC, DCM_APPL_DATA) SecLevel
)
{
    Std_ReturnType Result = E_NOT_OK;
#if(DCM_UDS_27_ENABLED == STD_ON)
    uint8 StabId;

    if(STD_UNINITIALIZED == Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETSECURITYLEVEL, DCM_E_UNINIT);
    }
    else if(SecLevel == NULL_PTR)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETSECURITYLEVEL, DCM_E_PARAM_POINTER);
    }
    else
    {
        if(DCM_SEC_IDX == DCM_SECURITY_LOCKED_IDX)
        {
            *SecLevel = DCM_SEC_LEV_LOCKED;
        }
        else if(DCM_SEC_IDX == DCM_SECURITY_ALL_IDX)
        {
            *SecLevel = DCM_SEC_LEV_ALL;
        }
        else
        {
            StabId = DCM_CURRENT_STAB;

            *SecLevel = DCM_CFG_SEC_LEVEL(StabId, DCM_SEC_IDX);
        }
        Result = E_OK;
    }
#endif
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_GetSesCtrlType SWS_Dcm_00339
*
* Description: This function provides the active session control type value.
*
* Inputs: None
*
* Outputs: Active Session Control Type value
*
* Return: E_OK: this value is always returned.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_GetSesCtrlType
(
    P2VAR(Dcm_SesCtrlType, AUTOMATIC, DCM_APPL_DATA) SesCtrlType
)
{
    Std_ReturnType Result = E_NOT_OK;

#if(DCM_UDS_10_ENABLED == STD_ON)
    if(STD_UNINITIALIZED == Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETSESCTRLTYPE, DCM_E_UNINIT);
    }
    else if(SesCtrlType == NULL_PTR)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_GETSESCTRLTYPE, DCM_E_PARAM_POINTER);
    }
    else
    {
        /*SWS_Dcm_00022*/
        if(DCM_ACTIVE_PCL_ID >= DCM_CFG_NUM_OF_PROTOCOL)
        {
            *SesCtrlType = DCM_DEFAULT_SESSION;
        }
        else
        {
            *SesCtrlType = DCM_CFG_SESSION_LEVEL(DCM_SES_IDX);
        }
        Result = E_OK;
    }
#endif
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_ResetToDefaultSession SWS_Dcm_00520
*
* Description: The call to this function allows the application to reset the
*              current session to Default session.
*
* Inputs: None
*
* Outputs: None
*
* Return: E_OK, E_NOT_OK
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_ResetToDefaultSession
(
    void
)
{
    Std_ReturnType Result = E_NOT_OK;

#if(DCM_UDS_10_ENABLED == STD_ON)
    if(STD_INITIALIZED != Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_RESETTODEFAULTSESSION, DCM_E_UNINIT);
    }
    else if(DCM_ACTIVE_PCL_ID >= DCM_CFG_NUM_OF_PROTOCOL)
    {
        Result = E_OK;
    }
    else
    {
        ClearS3Timer();

        if(DCM_SES_IDX != DCM_DEFAULT_IDX)
        {
            /*SWS_Dcm_01374*/
            COMM_DCM_INACTIVEDIAGNOSTIC(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
        }
        /*SWS_Dcm_01062*/
        DslInternal_SetSesCtrlType(DCM_DEFAULT_IDX);

        Result = E_OK;
    }
#endif
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_SetActiveDiagnostic SWS_Dcm_01068
*
* Description: Allows to activate and deactivate the call of
*              ComM_DCM_ActiveDiagnostic() function.
*
* Inputs: active: If false Dcm shall not call ComM_DCM_ActiveDiagnostic().
*                 If true Dcm will call ComM_DCM_ActiveDiagnostic().
*
* Outputs: None
*
* Return: E_OK: this value is always returned.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_SetActiveDiagnostic
(
    boolean active
)
{
    Std_ReturnType Result = E_NOT_OK;

#if(DCM_COMM_SUPPORT == STD_ON)
    if(STD_INITIALIZED != Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_SETACTIVEDIAGNOSTIC, DCM_E_UNINIT);
    }
    else
    {
        /*SWS_Dcm_CONSTR_06027*//*SWS_Dcm_01070*//*SWS_Dcm_01071*/
        DCM_ACTIVE_DIAGNOSTIC = active;
        Result = E_OK;
    }
#endif
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_StartOfReception SWS_Dcm_00094
*
* Description: This function is called at the start of receiving an N-SDU. The
*              N-SDU might be fragmented into multiple N-PDUs (FF with one or more
*              following CFs) or might consist of a single N-PDU (SF).
*
* Inputs: id: Identification of the I-PDU.
*         info: Pointer to a PduInfoType structure containing the payload data
*               (without protocol information) and payload length of the first
*               frame or single frame of a transport protocol I-PDU reception.
*         TpSduLength: Total length of the N-SDU to be received.
*
* Outputs: bufferSizePtr: Available receive buffer in the receiving module.This
*                         parameter will be used to compute the Block Size (BS)
*                         in the transport protocol module.
*
* Return: BUFREQ_OK: Connection has been accepted.
*         BUFREQ_E_NOT_OK: Connection has been rejected.
*         BUFREQ_E_OVFL: No buffer of the required length can be provided.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*There is not limit on the number of lines of function code and the number of local variable assignments.*/
FUNC(BufReq_ReturnType, DCM_CODE) Dcm_StartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) bufferSizePtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    BufReq_ReturnType Result = BUFREQ_E_NOT_OK;
    uint8 ProtocolId = (uint8)0;
    uint8 ConIdx = (uint8)0;/*Index of connection*/
    uint8 RxIdx = (uint8)0;/*Index of rx pdu*/
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
    uint8 bufferIndex;
#endif

    (void)info;

    if(STD_INITIALIZED != Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_STARTOFRECEPTION, DCM_E_UNINIT);
    }
    else if((id >= DCM_CFG_RXPDU_NUM) || (TpSduLength == (PduLengthType)0))
    {
        /*SWS_Dcm_00642*/
        DCM_DET_REPORT_ERROR(DCM_SID_STARTOFRECEPTION, DCM_E_PARAM);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_STARTOFRECEPTION, DCM_E_PARAM_POINTER);
    }
    else if((DCM_CFG_RXPDU_TO_PCL_MAP(id) > DCM_CFG_NUM_OF_PROTOCOL) || (DCM_CFG_PCL_USED(DCM_CFG_RXPDU_TO_PCL_MAP(id)) == FALSE))
    {
        /*Result = BUFREQ_E_NOT_OK;*/
    }
    else if((NULL_PTR == DCM_CFG_PCL_CONNECTION(DCM_CFG_RXPDU_TO_PCL_MAP(id))) \
        || (DCM_CFG_PCL_CONNECTION_NUM(DCM_CFG_RXPDU_TO_PCL_MAP(id)) == (uint8)0))
    {
        /*Result = BUFREQ_E_NOT_OK;*/
    }
    else
    {
        ProtocolId = DCM_CFG_RXPDU_TO_PCL_MAP(id);

        for(ConIdx = (uint8)0U; ConIdx < DCM_CFG_PCL_CONNECTION_NUM(ProtocolId); ConIdx++)
        {
            if(NULL_PTR != (DCM_CFG_PCL_CONNECTION_MAIN(ProtocolId, ConIdx)))
            {
                for(RxIdx = (uint8)0; RxIdx < DCM_CFG_PCL_CONNECTION_MAIN_RX_NUM(ProtocolId, ConIdx); RxIdx++)
                {
                    if((NULL_PTR != DCM_CFG_PCL_CONNECTION_MAIN_RX(ProtocolId, ConIdx)) \
                        && (id == DCM_CFG_PCL_CONNECTION_MAIN_RX_PDUID(ProtocolId, ConIdx, RxIdx)))
                    {
                        ret = E_OK;
                        break;
                    }
                }
            }

            if(ret == E_OK)
            {
                break;
            }
        }
    }

    if(ret == E_OK)
    {
        if(DCM_PCL_RX_PDU_ID(ProtocolId) != COMSTACK_INVALID_PDUID)
        {
            /*SWS_Dcm_00241*//*Result = BUFREQ_E_NOT_OK;*/
            if(DCM_PCL_RX_PDU_ID(ProtocolId) == id)
            {
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
                if(E_OK == Dcm_GetBufferIndex(&bufferIndex, ProtocolId))
                {
                    DCM_RX_PDU_PROCESSING[id] = TRUE;
                    DCM_PCL_RX_DATA_LEN(ProtocolId) = TpSduLength;
                    DCM_PCL_DATA_INDEX(ProtocolId) = (Dcm_MsgLenType)0;
                    DCM_PCL_RX_CON_ID(ProtocolId) = ConIdx;
                    DCM_PCL_RX_ID(ProtocolId) = RxIdx;
                    DCM_PCL_RX_BUFFERIDX(ProtocolId) = bufferIndex;
                    DCM_PCL_RX_BUFFER(ProtocolId) = DCM_CFG_PCL_RXFIFOBUFFER(ProtocolId, bufferIndex);

                    *bufferSizePtr = (PduLengthType)DCM_CFG_PCL_RXBUFFER_SIZE(ProtocolId);
                    Result = BUFREQ_OK;
                }
                else
#endif
                {
                    /*Result = BUFREQ_E_NOT_OK;*/
                }
            }
            else if((DCM_ACTIVE_PCL_ID == ProtocolId) && (DCM_CFG_PCL_CONNECTION_MAIN_RX_ADDR_TYPE(ProtocolId, ConIdx, RxIdx) == DCM_FUNCTIONAL_TYPE) \
                && (TpSduLength == DCM_LENGTH_2_BYTE))
            {
                /*Parallel processing function addressing request 3E 80.*/
                DCM_ACTIVE_FUN_ADDR_RX_ID = id;
                Result = BUFREQ_OK;
            }
            else
            {
                /*Result = BUFREQ_E_NOT_OK;*/
            }
        }
        else if((TpSduLength > DCM_CFG_PCL_RXBUFFER_SIZE(ProtocolId)) || (NULL_PTR == DCM_CFG_PCL_RXBUFFER(ProtocolId)))
        {
            /*SWS_Dcm_00444*/
            Result = BUFREQ_E_OVFL;
        }
        else
        {
            DCM_PCL_RX_PDU_ID(ProtocolId) = id;
            DCM_PCL_RX_DATA_LEN(ProtocolId) = TpSduLength;
            DCM_PCL_DATA_INDEX(ProtocolId) = (Dcm_MsgLenType)0;
            DCM_PCL_RX_CON_ID(ProtocolId) = ConIdx;
            DCM_PCL_RX_ID(ProtocolId) = RxIdx;

#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
            DCM_PCL_RX_BUFFERIDX(ProtocolId) = 0;
            DCM_PCL_RX_BUFFER(ProtocolId) = DCM_CFG_PCL_RXFIFOBUFFER(ProtocolId, 0);
#endif
            *bufferSizePtr = (PduLengthType)DCM_CFG_PCL_RXBUFFER_SIZE(ProtocolId);
            /*SWS_Dcm_00141*/
            if(DCM_ACTIVE_PCL_ID == ProtocolId)
            {
                ClearS3Timer();
#if(STD_ON == DCM_UDS_29_ENABLED)
                ClearAuthenticationTimer();
#endif
            }

            Result = BUFREQ_OK;
        }
    }
    return Result;
}
/*PRQA S 4700 --*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_CopyRxData SWS_Dcm_00556
*
* Description: This function is called to provide the received data of an I-PDU
*              segment (N-PDU) to the upper layer.Each call to this function
*              provides the next part of the I-PDU data.The size of the remaining
*              data is written to the position indicated by bufferSizePtr.
*
* Inputs: id: Identification of the received I-PDU.
*         info: Provides the source buffer (SduDataPtr) and the number of bytes
*               to be copied (SduLength)
*
* Outputs: bufferSizePtr: Available receive buffer after data has been copied.
*
* Return: BUFREQ_OK: Data copied successfully
*         BUFREQ_E_NOT_OK: Data was not copied because an error occurred.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, DCM_CODE) Dcm_CopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType Result = BUFREQ_E_NOT_OK;
    uint8 *DestPtr = NULL_PTR;
    uint8 ProtocolId;

    if(STD_INITIALIZED != Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COPYRXDATA, DCM_E_UNINIT);
    }
    else if(id >= DCM_CFG_RXPDU_NUM)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COPYRXDATA, DCM_E_PARAM);
    }
    else if((NULL_PTR == info) || (NULL_PTR == (info->SduDataPtr)) || (NULL_PTR == bufferSizePtr))
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COPYRXDATA, DCM_E_PARAM_POINTER);
    }
    else
    {
        ProtocolId = DCM_CFG_RXPDU_TO_PCL_MAP(id);

        if(DCM_PCL_RX_PDU_ID(ProtocolId) == id)
        {
            if((PduLengthType)0 == (info->SduLength))
            {
                /*SWS_Dcm_00996*/
                *bufferSizePtr = (PduLengthType)(DCM_PCL_RX_DATA_LEN(ProtocolId) - DCM_PCL_DATA_INDEX(ProtocolId));
                Result = BUFREQ_OK;
            }
            else if((info->SduLength) > (DCM_PCL_RX_DATA_LEN(ProtocolId) - DCM_PCL_DATA_INDEX(ProtocolId)))
            {
                *bufferSizePtr = (PduLengthType)(DCM_PCL_RX_DATA_LEN(ProtocolId) - DCM_PCL_DATA_INDEX(ProtocolId));
                Result = BUFREQ_E_OVFL;
            }
            else
            {
                SchM_Enter_Dcm_DCM_EXCLUSIVE_AREA_0();
                /*PRQA S 488 ++*/
                /*
                Allow pointer arithmetic.
                */

#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
                DestPtr = (DCM_PCL_RX_BUFFER(ProtocolId) + DCM_PCL_DATA_INDEX(ProtocolId));
#else
                DestPtr = (DCM_CFG_PCL_RXBUFFER(ProtocolId) + DCM_PCL_DATA_INDEX(ProtocolId));
#endif

                /*PRQA S 488 --*/
                Bsw_MemCpy(DestPtr, info->SduDataPtr, (uint32)(info->SduLength));
                DCM_PCL_DATA_INDEX(ProtocolId) += (info->SduLength);
                /*SWS_Dcm_00443*/
                *bufferSizePtr = (PduLengthType)(DCM_PCL_RX_DATA_LEN(ProtocolId) - DCM_PCL_DATA_INDEX(ProtocolId));

                SchM_Exit_Dcm_DCM_EXCLUSIVE_AREA_0();

                Result = BUFREQ_OK;
            }
        }
        else
        {
            if(DCM_ACTIVE_FUN_ADDR_RX_ID == id)
            {
                if((DCM_LENGTH_2_BYTE == (info->SduLength)) && (info->SduDataPtr[DCM_SID_INDEX] == DCM_3E_SERVICE) \
                    && (info->SduDataPtr[DCM_SUB_SID_INDEX] == DCM_SUPPRESS_POS_RSP_MASK))
                {
                    Result = BUFREQ_OK;
                }
                else
                {
                    DCM_ACTIVE_FUN_ADDR_RX_ID = DCM_CFG_RXPDU_NUM;
                }
            }
        }
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_TpRxIndication SWS_Dcm_00093
*
* Description: Called after an I-PDU has been received via the TP API, the
*              result indicates whether the transmission was successful or not.
*
* Inputs: id: Identification of the received I-PDU.
*         result: Result of the reception.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) Dcm_TpRxIndication
(
    PduIdType id,
    Std_ReturnType result
)
{
    uint8 ProtocolId;

    if(STD_INITIALIZED != Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_TPRXINDICATION, DCM_E_UNINIT);
    }
    else if(id >= DCM_CFG_RXPDU_NUM)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_TPRXINDICATION, DCM_E_PARAM);
    }
    else
    {
        ProtocolId = DCM_CFG_RXPDU_TO_PCL_MAP(id);

        if(DCM_PCL_RX_PDU_ID(ProtocolId) == id)
        {
            /*SWS_Dcm_00344*/
            if(result == E_OK)
            {
                /*SWS_Dcm_00111*//*SWS_Dcm_00241*/
                DslInternal_CheckProtocolPermission(ProtocolId);
            }
            else
            {
                if(DCM_ACTIVE_PCL_ID == ProtocolId)
                {
                    /*SWS_Dcm_00141*/
#if(DCM_UDS_10_ENABLED == STD_ON)
                    if(DCM_SES_IDX != DCM_DEFAULT_IDX)
                    {
                        SetS3Timer(DCM_CFG_PCL_S3(DCM_ACTIVE_PCL_ID));
                    }
#endif
                    /*SWS_Dcm_01482*/
#if(STD_ON == DCM_UDS_29_ENABLED)
                    if((DCM_SES_IDX == DCM_DEFAULT_IDX) && ((DCM_AU_STATE & DCM_AU_STATE_AUTHENTICATED) != DCM_AU_STATE_DEAUTHENTICATED))
                    {
                        SetAuthenticationTimer();
                    }
#endif
                }

                /*Clear the new received pdu info of protocol identified by ProtocolId.*/
                DCM_PCL_RX_PDU_ID(ProtocolId) = COMSTACK_INVALID_PDUID;
            }
        }
        else
        {
            if(DCM_ACTIVE_FUN_ADDR_RX_ID == id)
            {
                /*Diagnosis is currently in progress and 3E 80 of the functional addressing request
                does need to be processed any further.*/
                DCM_ACTIVE_FUN_ADDR_RX_ID = DCM_CFG_RXPDU_NUM;
            }
        }
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
        DCM_RX_PDU_PROCESSING[id] = FALSE;
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_CopyTxData SWS_Dcm_00092
*
* Description: This function is called to acquire the transmit data of an I-PDU
*              segment (N-PDU).
*
* Inputs: id: Identification of the transmitted I-PDU.
*         info: Provides the destination buffer (SduDataPtr) and the number of
*               bytes to be copied (SduLength).
*         retry: This parameter is used to acknowledge transmitted data or to
*                retransmit data after transmission problems.
*
* Outputs: availableDataPtr: Indicates the remaining number of bytes that are
*                            available in the upper layer module's Tx buffer.
*
* Return: BUFREQ_OK: Data has been copied to the transmit buffer completely as
*                    requested.
*         BUFREQ_E_BUSY: Request could not be fulfilled, because the required
*                        amount of Tx data is not available. The lower layer
*                        module may retry this call later on. No data has been
*                        copied.
*         BUFREQ_E_NOT_OK: Data has not been copied. Request failed.
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, DCM_CODE) Dcm_CopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_APPL_DATA) info,
    P2CONST(RetryInfoType, AUTOMATIC, DCM_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, DCM_APPL_DATA) availableDataPtr
)
{
    BufReq_ReturnType Result = BUFREQ_E_NOT_OK;
    uint8 *SrcPtr = NULL_PTR;
    uint8 ProtocolId;
    PduLengthType TempLength;
    Dcm_MsgLenType *TxDataIndex = NULL_PTR;

    (void)retry;
    if(STD_INITIALIZED != Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COPYTXDATA, DCM_E_UNINIT);
    }
    else if(NULL_PTR == info)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COPYTXDATA, DCM_E_PARAM_POINTER);
    }
    else if(((PduLengthType)0 != (info->SduLength)) && (NULL_PTR == info->SduDataPtr))
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COPYTXDATA, DCM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == availableDataPtr)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COPYTXDATA, DCM_E_PARAM_POINTER);
    }
    else
    {
        SchM_Enter_Dcm_DCM_EXCLUSIVE_AREA_0();

        if((DCM_ACTIVE_PCL_ID < DCM_CFG_NUM_OF_PROTOCOL) \
            && (id == DCM_CFG_PCL_CONNECTION_MAIN_TX_CONID(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID)))
        {
            if((CheckDcmState((DCM_RCRRP | DCM_RCRRP_FORCE))) || (DCM_ERRORCODE != DCM_POS_RESP))
            {
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
                if(DCM_ERRORCODE == DCM_E_CONDITIONSNOTCORRECT)
                {
                    TempLength = DCM_UDS_WITH_NRC22_RES_LEN;
                }
                else
#endif
                {
                    TempLength = DCM_UDS_NEG_RES_LEN;
                }

                if((PduLengthType)0 == (info->SduLength))
                {
                    *availableDataPtr = TempLength;
                }
                else
                {
                    Bsw_MemCpy(info->SduDataPtr, DCM_PCL_NEG_BUFFER(DCM_ACTIVE_PCL_ID), (uint32)TempLength);
                    *availableDataPtr = (PduLengthType)0;
                }
            }
            else
            {
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
                TxDataIndex = &(DCM_PCL_TXDATA_INDEX(DCM_ACTIVE_PCL_ID));
#else
                TxDataIndex = &(DCM_PCL_DATA_INDEX(DCM_ACTIVE_PCL_ID));
#endif
                if((PduLengthType)0 == (info->SduLength))
                {
                    /*SWS_Dcm_00350*/
                    *availableDataPtr = (PduLengthType)(DCM_MSGCONTEXT.resDataLen - *TxDataIndex);
                }
                else
                {
                    /*PRQA S 488 ++*/
                    /*
                    Allow pointer arithmetic.
                    */
                    SrcPtr = (DCM_MSGCONTEXT.resData + *TxDataIndex);
                    /*PRQA S 488 --*/
                    Bsw_MemCpy(info->SduDataPtr, SrcPtr, (uint32)(info->SduLength));
                    *TxDataIndex += (info->SduLength);
                    /*SWS_Dcm_00350*/
                    *availableDataPtr = (PduLengthType)(DCM_MSGCONTEXT.resDataLen - *TxDataIndex);
                }
            }
            /*SWS_Dcm_00346*/
            Result = BUFREQ_OK;
        }
        else
        {
            for(ProtocolId = (uint8)0; ProtocolId < DCM_CFG_NUM_OF_PROTOCOL; ProtocolId++)
            {
                if((DCM_PCL_RX_PDU_ID(ProtocolId) != COMSTACK_INVALID_PDUID) \
                    && (id == DCM_CFG_PCL_CONNECTION_MAIN_TX_CONID(ProtocolId, DCM_PCL_RX_CON_ID(ProtocolId))))
                {
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
                    if(DCM_PCL_NEG_BUFFER(ProtocolId)[DCM_INDEX_2] == DCM_E_CONDITIONSNOTCORRECT)
                    {
                        TempLength = DCM_UDS_WITH_NRC22_RES_LEN;
                    }
                    else
#endif
                    {
                        TempLength = DCM_UDS_NEG_RES_LEN;
                    }

                    if((PduLengthType)0 == (info->SduLength))
                    {
                        *availableDataPtr = TempLength;
                    }
                    else
                    {
                        Bsw_MemCpy(info->SduDataPtr, DCM_PCL_NEG_BUFFER(ProtocolId), (uint32)TempLength);
                        *availableDataPtr = (PduLengthType)0;
                    }
                    Result = BUFREQ_OK;

                    break;
                }
            }
        }
        SchM_Exit_Dcm_DCM_EXCLUSIVE_AREA_0();
    }
    return Result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_TpTxConfirmation SWS_Dcm_00351
*
* Description: This function is called after the I-PDU has been transmitted on
*              its network, the result indicates whether the transmission was
*              successful or not.
*
* Inputs: id: Identification of the transmitted I-PDU.
*         result: Result of the transmission of the I-PDU.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) Dcm_TpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
)
{
    uint16 SourceAddress;
    uint8 ProtocolId;

    if(STD_INITIALIZED != Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_TPTXCONFIRMATION, DCM_E_UNINIT);
    }
    else
    {
        if((DCM_ACTIVE_PCL_ID < DCM_CFG_NUM_OF_PROTOCOL) \
            && (id == DCM_CFG_PCL_CONNECTION_MAIN_TX_CONID(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID)))
        {
            if(CheckDcmState((DCM_RCRRP | DCM_RCRRP_FORCE)))
            {
                if(result == E_OK)
                {
                    if(CheckDcmState(DCM_RCRRP_FORCE))
                    {
                        SetDcmState(DCM_RCRRP_FORCE_OK);
                        /*SWS_Dcm_00529*/
                        DCM_OP_STATUS = DCM_FORCE_RCRRP_OK;
                    }
#if(DCM_UDS_10_ENABLED == STD_ON)
                    SetP2StarTimer(DCM_CFG_SESSION_P2STAR(DCM_SES_IDX));
#endif
                    if(!CheckRespPendCounter())
                    {
                        RunRespPendCounter();
                    }
                }
                else
                {
                    DCM_OP_STATUS = DCM_CANCEL;
                }
                ClearDcmState((DCM_RCRRP | DCM_RCRRP_FORCE));
            }
            else/*Positive response or other negative response*/
            {
                /*SWS_Dcm_00141*/
                if(DCM_SES_IDX != DCM_DEFAULT_IDX)
                {
                    SetS3Timer(DCM_CFG_PCL_S3(DCM_ACTIVE_PCL_ID));
                }
                else if(((DCM_REQ_SERVICE != DCM_10_SERVICE) && (DCM_REQ_SERVICE != DCM_11_SERVICE)) \
                    || (result != E_OK) || (DCM_ERRORCODE != DCM_POS_RESP))
                {
                    /*SWS_Dcm_01374*/
                    COMM_DCM_INACTIVEDIAGNOSTIC(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
                }
                else
                {
                    /*ComM_DCM_InactiveDiagnostic of 0x10, 0x11 will be executed in their ServicePostFunction*/
                }

                /*SWS_Dcm_00352*/
                if((result == E_OK) && (DCM_ERRORCODE == DCM_POS_RESP))
                {
                    SourceAddress = DCM_CFG_PCL_CONNECTION_MAIN_TESTER_ADDR(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
                    /*SWS_Dcm_00117*//*SWS_Dcm_00235*/
                    DsdInternal_DcmConfirmation(DCM_MSGCONTEXT.idContext, SourceAddress, DCM_RES_POS_OK);
                }
                else
                {
                    DCM_ERRORCODE = DCM_POS_RESP;
                    DcmInternal_InitMsgContext();
                    ResetDcmState();
                }

                /*SWS_Dcm_01482*/
#if(STD_ON == DCM_UDS_29_ENABLED)
                if((DCM_SES_IDX == DCM_DEFAULT_IDX) && ((DCM_AU_STATE & DCM_AU_STATE_AUTHENTICATED) != DCM_AU_STATE_DEAUTHENTICATED))
                {
                    SetAuthenticationTimer();
                }
#endif
            }
        }
        else
        {
            for(ProtocolId = (uint8)0; ProtocolId < DCM_CFG_NUM_OF_PROTOCOL; ProtocolId++)
            {
                if((DCM_PCL_RX_PDU_ID(ProtocolId) != COMSTACK_INVALID_PDUID) \
                    && (id == DCM_CFG_PCL_CONNECTION_MAIN_TX_CONID(ProtocolId, DCM_PCL_RX_CON_ID(ProtocolId))))
                {
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
                    if(DCM_RX_PDU_PROCESSING[DCM_PCL_RX_PDU_ID(ProtocolId)] == FALSE)
#endif
                    {
                        /*SWS_Dcm_00352*/
                        DCM_PCL_RX_PDU_ID(ProtocolId) = COMSTACK_INVALID_PDUID;
                    }
                    break;
                }
            }
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_TxConfirmation SWS_Dcm_01092
*
* Description: The lower layer communication interface module confirms the
*              transmission of a PDU, or the failure to transmit a PDU. This
*              function might be called in interrupt context.
*
* Inputs: TxPduId: ID of the PDU that has been transmitted.
*         result: E_OK: The PDU was transmitted. E_NOT_OK: Transmission of
*                 the PDU failed.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) Dcm_TxConfirmation
(
    PduIdType TxPduId,
    Std_ReturnType result
)
{
    (void)TxPduId;
    (void)result;
}


#if(DCM_COMM_SUPPORT == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_ComM_NoComModeEntered SWS_Dcm_00356
*
* Description: This call informs the Dcm module about a ComM mode change to
*              COMM_NO_COMMUNICATION.
*
* Inputs: NetworkId: Identifier of the network concerned by the mode change
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) Dcm_ComM_NoComModeEntered
(
    NetworkHandleType NetworkId
)
{
    if(STD_INITIALIZED != Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COMMNOCOMMODEENTERED, DCM_E_UNINIT);
    }
    else if(NetworkId >= DCM_NUM_COMM_CHANNEL)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COMMNOCOMMODEENTERED, DCM_E_PARAM);
    }
    else
    {
        DCM_COMM_CHANNEL_MODE(NetworkId) = DCM_COMM_NOCOM;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_ComM_SilentComModeEntered SWS_Dcm_00358
*
* Description: This call informs the Dcm module about a ComM mode change to
*              COMM_SILENT_COMMUNICATION.
*
* Inputs: NetworkId: Identifier of the network concerned by the mode change
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) Dcm_ComM_SilentComModeEntered
(
    NetworkHandleType NetworkId
)
{
    if(STD_INITIALIZED != Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COMMSILENTCOMMODEENTERED, DCM_E_UNINIT);
    }
    else if(NetworkId >= DCM_NUM_COMM_CHANNEL)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COMMSILENTCOMMODEENTERED, DCM_E_PARAM);
    }
    else
    {
        DCM_COMM_CHANNEL_MODE(NetworkId) = DCM_COMM_SILENTCOM;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_ComM_FullComModeEntered SWS_Dcm_00360
*
* Description: This call informs the Dcm module about a ComM mode change to
*              COMM_FULL_COMMUNICATION.
*
* Inputs: NetworkId: Identifier of the network concerned by the mode change
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) Dcm_ComM_FullComModeEntered
(
    NetworkHandleType NetworkId
)
{
    if(STD_INITIALIZED != Dcm_InitState)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COMMFULLCOMMODEENTERED, DCM_E_UNINIT);
    }
    else if(NetworkId >= DCM_NUM_COMM_CHANNEL)
    {
        DCM_DET_REPORT_ERROR(DCM_SID_COMMFULLCOMMODEENTERED, DCM_E_PARAM);
    }
    else
    {
        DCM_COMM_CHANNEL_MODE(NetworkId) = DCM_COMM_FULLCOM;
    }
}
#endif/*(DCM_COMM_SUPPORT == STD_ON)*/


#if(DCM_UDS_29_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_CsmAsyncJobFinished SWS_Dcm_91076
*
* Description: Can be called from Csm upon finishing an asynchronous job processing.
*
* Inputs: result: Return value of the asynchronous job
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) Dcm_CsmAsyncJobFinished
(
    uint32 JobId,/*To meet the call format of Csm*/
    Crypto_ResultType result
)
{
    (void)JobId;

    if(STD_INITIALIZED == Dcm_InitState)
    {
        if(DCM_AU_RESULT_IND == FALSE)
        {
            DCM_AU_CSM_RESULT = result;
            DCM_AU_RESULT_IND = TRUE;
        }
    }

}
#endif


#if(DCM_UDS_29_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_KeyMAsyncCertificateVerifyFinished SWS_Dcm_91076
*
* Description: Can be called from Key upon finishing an asynchronous certificate verification.
*
* Inputs: CertID: Certificate identifier that has finished the verification
*         Result: Return value of the asynchronous job
*
* Outputs: None
*
* Return: E_OK
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_KeyMAsyncCertificateVerifyFinished
(
    KeyM_CertificateIdType CertID,
    KeyM_CertificateStatusType Result
)
{
    if(STD_INITIALIZED == Dcm_InitState)
    {
        if(DCM_AU_RESULT_IND == FALSE)
        {
            DCM_AU_CERT_ID = CertID;
            DCM_AU_CERT_RESULT = Result;
            DCM_AU_RESULT_IND = TRUE;
        }
    }

    return E_OK;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_MainFunction SWS_Dcm_00053
*
* Description: This service is used for processing the tasks of the main loop.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) Dcm_MainFunction
(
    void
)
{
#if(DCM_MULTI_CORE_SUPPORT == STD_ON)
    uint8 CoreId = DCM_GET_COREID();

    if(CoreId == DCM_MASTER_CORE_ID)
    {
#endif
        if(STD_UNINITIALIZED != Dcm_InitState)
        {
            DsdInternal_MainFunction();
            DspInternal_MainFunction();
            DslInternal_MainFunction();
        }
        else
        {
#if((DCM_UDS_27_ENABLED == STD_ON) && (STD_ON == DCM_CFG_ACCESS_ATTEMPT_COUNTER_SUPPORT))
            DslInternal_RecoverAttemptCounter();

            if(DCM_SEC_ALL_INIT == TRUE)
            {
                Dcm_InitState = STD_INITIALIZED;
            }
#endif
        }
#if(DCM_MULTI_CORE_SUPPORT == STD_ON)
    }
    else
    {
        if(Dcm_SlaveCoreMainFunction[CoreId] != NULL_PTR)
        {
            Dcm_SlaveCoreMainFunction[CoreId]();
        }
    }
#endif
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_ExternalSubServiceCheck
*
* Description: This function is used to check whether subservices of non-UDS
*              standard services are supported, and whether they can be executed
*              under the current session, security level, and addressing mode.
*
* Inputs: None
*
* Outputs: pErrorCode
*
* Return: E_OK, E_NOT_OK
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_ExternalSubServiceCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;

#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
    SetP4Timer(DCM_REQ_SERVICEINFO->P4ServerMax);
#endif

    return Result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_GetCommunicationState
*
* Description: The application layer calls this function to obtain the communication
*              status of Nm message and app message in a certain channel.
*
* Inputs: Channel: ComM channel
*
* Outputs: NmMessageState, AppMessageState
*
* Return: E_OK, E_NOT_OK
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) Dcm_GetCommunicationState
(
    NetworkHandleType Channel,
    P2VAR(Dcm_CommunicationModeType, AUTOMATIC, DCM_VAR) NmMessageState,
    P2VAR(Dcm_CommunicationModeType, AUTOMATIC, DCM_VAR) AppMessageState
)
{
    Std_ReturnType Result = E_OK;

    if(STD_INITIALIZED != Dcm_InitState)
    {
        Result = E_NOT_OK;
    }
    else if(Channel >= DCM_NUM_COMM_CHANNEL)
    {
        Result = E_NOT_OK;
    }
    else if((NmMessageState == NULL_PTR) || (AppMessageState == NULL_PTR))
    {
        Result = E_NOT_OK;
    }
    else
    {
        *NmMessageState = DCM_COM_NM_MSG_STATE(Channel);
        *AppMessageState = DCM_COM_APP_MSG_STATE(Channel);
    }
    return Result;
}

#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_SetNRC22Reason
*
* Description: This function is only applicable to projects specified by SAIC. When
*              performing diagnostic service processing, if the application layer
*              determines that NRC22 needs to be returned, the application layer needs
*              to call this function to set the reason for returning NRC22.
*
* Inputs: Reason: Indicates the reason for returning the 0x22 negative response code.
*
* Outputs: None
*
* Return: None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) Dcm_SetNRC22Reason
(
    uint8 Reason
)
{
    if((STD_INITIALIZED == Dcm_InitState) && (DCM_ACTIVE_PROTOCOL_ID < DCM_CFG_NUM_OF_PROTOCOL))
    {
        DCM_PCL_NEG_BUFFER(DCM_ACTIVE_PROTOCOL_ID)[DCM_INDEX_3] = Reason;
    }
}
#endif


#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_GetBufferIndex
*
* Description: This function is used to get a idle rx buffer index
*
* Inputs: ProtocolId
*
* Outputs: bufferIndexs
*
* Return: E_OK: The index of the free buffer was successfully obtained
          E_NOT_OK: There are no free buffers to use
*
* Limitations: Only available when DCM_RXFIFOBUFFER_ENABLED is STD_ON
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, DCM_CODE) Dcm_GetBufferIndex
(
    uint8 *bufferIndex,
    uint8 ProtocolId
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 i;
    
    for(i = (uint8)0; i < DCM_CFG_PCL_RXBUFFER_NUM(ProtocolId); i++)
    {
        if(DCM_CFG_PCL_RXBUFFERLISTPTR[i].bufferIsUesd == FALSE)
        {
            *bufferIndex = i;
            ret = E_OK;
            break;
        }
    }
    
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_InsertFifoBuffer
*
* Description: This function is used to insert a new buffer to list
*
* Inputs: msgContextPtr 
*
* Outputs: ListPtr
*
* Return: None
*
* Limitations: Only available when DCM_RXFIFOBUFFER_ENABLED is STD_ON
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, TCPIP_CODE) Dcm_InsertFifoBuffer
(
    P2P2VAR(Dcm_BufferListType, AUTOMATIC, AUTOMATIC) ListPtr,
    P2VAR(Dcm_BufferListType, AUTOMATIC, AUTOMATIC) msgContextPtr
)
{
    P2VAR(Dcm_BufferListType, AUTOMATIC, AUTOMATIC) AvailablePtr;
    SchM_Enter_Dcm_DCM_EXCLUSIVE_AREA_2();
    if (*ListPtr == NULL_PTR)
    {
        *ListPtr = msgContextPtr;
        (*ListPtr)->nextPtr = NULL_PTR;
        Dcm_UpdateMsgContext(msgContextPtr);
    }
	else
    {
        for(AvailablePtr = (*ListPtr); AvailablePtr->nextPtr != NULL_PTR;)
        {
            AvailablePtr = (Dcm_BufferListType*)AvailablePtr->nextPtr;
        }

        AvailablePtr->nextPtr = (struct Dcm_BufferListType *)msgContextPtr;
        AvailablePtr->nextPtr->nextPtr = NULL_PTR;
    }
    SchM_Exit_Dcm_DCM_EXCLUSIVE_AREA_2();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_GetNextFifoBuffer
*
* Description: This function is used to get the next member in the list
*
* Inputs: ListPtr
*
* Outputs: ListPtr
*
* Return: buffer
*
* Limitations: Only available when DCM_RXFIFOBUFFER_ENABLED is STD_ON
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Dcm_BufferListType*, TCPIP_CODE) Dcm_GetNextFifoBuffer
(
    P2P2VAR(Dcm_BufferListType, AUTOMATIC, AUTOMATIC) ListPtr
)
{
    Dcm_BufferListType *buffer = NULL_PTR;
    uint8 bufferIndex;

    if (*ListPtr != NULL_PTR)
    {
        bufferIndex = (*ListPtr)->rxBufferIndex;
        DCM_CFG_PCL_RXBUFFERLISTPTR[bufferIndex].bufferIsUesd = FALSE;
        *ListPtr = (*ListPtr)->nextPtr;
        buffer = *ListPtr;
    }
    
    return buffer;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_UpdateMsgContext
*
* Description: This function is used to update DCM_MSGCONTEXT
*
* Inputs: bufferPtr
*
* Outputs: None
*
* Return: None
*
* Limitations: Only available when DCM_RXFIFOBUFFER_ENABLED is STD_ON
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) Dcm_UpdateMsgContext
(
    P2VAR(Dcm_BufferListType, AUTOMATIC, AUTOMATIC) bufferPtr
)
{
#if(DCM_UDS_10_ENABLED == STD_ON)
    uint8 Idx;
#endif
    
    DCM_MSGCONTEXT.reqData = bufferPtr->reqData;
    DCM_MSGCONTEXT.reqDataLen = (Dcm_MsgLenType)bufferPtr->reqDataLen;
    DCM_MSGCONTEXT.resData = bufferPtr->resData;
    DCM_MSGCONTEXT.resDataLen = (Dcm_MsgLenType)0;
    DCM_MSGCONTEXT.msgAddInfo.reqType = bufferPtr->msgAddInfo.reqType;
    DCM_MSGCONTEXT.resMaxDataLen = DCM_CFG_PCL_TXBUFFER_SIZE(DCM_ACTIVE_PCL_ID);
    DCM_MSGCONTEXT.dcmRxPduId = DCM_PCL_RX_PDU_ID(DCM_ACTIVE_PCL_ID);
    /*SWS_Dcm_00146*//*Generally, the security level is activated in a non-default session. Therefore, when priority
    preemption occurs, the session must be converted to the default session. Therefore, there is no need to reset the
    security level.*/
    /*SWS_Dcm_00147*//*When switching to the default session, the SchM_Switch function has already been called.*/

    DCM_RX_IND_FLAG = TRUE;
#if(DCM_UDS_10_ENABLED == STD_ON)
    for(Idx = (uint8)0; Idx < DCM_CFG_STAB_S_NUM; Idx++)
    {
        if(DCM_CFG_STAB_S_ID(Idx) == DCM_10_SERVICE)
        {
            if(DCM_CFG_STAB_S_USED(Idx) == TRUE)
            {
                /*SWS_Dcm_00144*/
                SetP2Timer(DCM_CFG_SESSION_P2(DCM_SES_IDX));
            }
            break;
        }
    }
#endif
    SetRespPendCounter(DCM_CFG_RESP_PEND_MAX_NUM);
#if(DCM_COMM_SUPPORT == STD_ON)
    /*SWS_Dcm_00169*//*SWS_Dcm_01373*//*SWS_Dcm_01376*/
    if((DCM_SES_IDX == DCM_DEFAULT_IDX) && (DCM_ACTIVE_DIAGNOSTIC == TRUE))
    {
        COMM_DCM_ACTIVEDIAGNOSTIC(DCM_ACTIVE_PCL_ID, DCM_ACTIVE_CON_ID);
    }
#endif

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Dcm_ResetRxFifoBufferStatus
*
* Description: This function is used to reset rx fifo buffer status
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: Only available when DCM_RXFIFOBUFFER_ENABLED is STD_ON
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, DCM_CODE) Dcm_ResetRxFifoBufferStatus
(
    void
)
{
    uint8 i;
    
    for(i = (uint8)0; i < DCM_RXFIFOBUFFER_MAX; i++)
    {
        DCM_CFG_PCL_RXBUFFERLISTPTR[i].bufferIsUesd = FALSE;
    }
}

#endif

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"




