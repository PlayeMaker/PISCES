/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : SchM_Dcm_Type.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : SchM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : SchM module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/

/*PRQA S 789,793 EOF*/
/*
Names in this file may not follow relevant rules.
*/

#ifndef SCHM_DCM_TYPE_H
#define SCHM_DCM_TYPE_H
/*******************************************************************************
*   Include
*******************************************************************************/
#include "ComStack_Types.h"
#ifndef RTE_MODETYPE_DcmCommunicationControl_ComM_BODY_LE1_CAN
#define RTE_MODETYPE_DcmCommunicationControl_ComM_BODY_LE1_CAN
typedef uint8 Rte_ModeType_DcmCommunicationControl_ComM_BODY_LE1_CAN;
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_ENABLE_RX_TX_NORM
#define RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_ENABLE_RX_TX_NORM          (Rte_ModeType_DcmCommunicationControl_ComM_BODY_LE1_CAN)0
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_ENABLE_RX_DISABLE_TX_NORM
#define RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_ENABLE_RX_DISABLE_TX_NORM  (Rte_ModeType_DcmCommunicationControl_ComM_BODY_LE1_CAN)1
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_DISABLE_RX_ENABLE_TX_NORM
#define RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_DISABLE_RX_ENABLE_TX_NORM  (Rte_ModeType_DcmCommunicationControl_ComM_BODY_LE1_CAN)2
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_DISABLE_RX_TX_NORMAL
#define RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_DISABLE_RX_TX_NORMAL       (Rte_ModeType_DcmCommunicationControl_ComM_BODY_LE1_CAN)3
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_ENABLE_RX_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_ENABLE_RX_TX_NM  (Rte_ModeType_DcmCommunicationControl_ComM_BODY_LE1_CAN)4
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_ENABLE_RX_DISABLE_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_ENABLE_RX_DISABLE_TX_NM    (Rte_ModeType_DcmCommunicationControl_ComM_BODY_LE1_CAN)5
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_DISABLE_RX_ENABLE_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_DISABLE_RX_ENABLE_TX_NM    (Rte_ModeType_DcmCommunicationControl_ComM_BODY_LE1_CAN)6
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_DISABLE_RX_TX_NM
#define RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_DISABLE_RX_TX_NM (Rte_ModeType_DcmCommunicationControl_ComM_BODY_LE1_CAN)7
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_ENABLE_RX_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_ENABLE_RX_TX_NORM_NM       (Rte_ModeType_DcmCommunicationControl_ComM_BODY_LE1_CAN)8
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_ENABLE_RX_DISABLE_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_ENABLE_RX_DISABLE_TX_NORM_NM         (Rte_ModeType_DcmCommunicationControl_ComM_BODY_LE1_CAN)9
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_DISABLE_RX_ENABLE_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_DISABLE_RX_ENABLE_TX_NORM_NM         (Rte_ModeType_DcmCommunicationControl_ComM_BODY_LE1_CAN)10
#endif
#ifndef RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_DISABLE_RX_TX_NORM_NM
#define RTE_MODE_DcmCommunicationControl_ComM_BODY_LE1_CAN_DCM_DISABLE_RX_TX_NORM_NM      (Rte_ModeType_DcmCommunicationControl_ComM_BODY_LE1_CAN)11
#endif
#ifndef RTE_TRANSITION_DcmCommunicationControl_ComM_BODY_LE1_CAN
#define RTE_TRANSITION_DcmCommunicationControl_ComM_BODY_LE1_CAN      (Rte_ModeType_DcmCommunicationControl_ComM_BODY_LE1_CAN)255
#endif

#ifndef RTE_MODETYPE_DcmControlDtcSetting
#define RTE_MODETYPE_DcmControlDtcSetting
typedef uint8 Rte_ModeType_DcmControlDtcSetting;
#endif
#ifndef RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING
#define RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING      (Rte_ModeType_DcmControlDtcSetting)0
#endif
#ifndef RTE_MODE_DcmControlDtcSetting_DISABLEDTCSETTING
#define RTE_MODE_DcmControlDtcSetting_DISABLEDTCSETTING     (Rte_ModeType_DcmControlDtcSetting)1
#endif
#ifndef RTE_TRANSITION_DcmControlDtcSetting
#define RTE_TRANSITION_DcmControlDtcSetting                 (Rte_ModeType_DcmControlDtcSetting)255
#endif

#ifndef RTE_MODETYPE_DcmDiagnosticSessionControl
#define RTE_MODETYPE_DcmDiagnosticSessionControl
typedef uint8 Rte_ModeType_DcmDiagnosticSessionControl;
#endif
#ifndef RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION
#define RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION          (Rte_ModeType_DcmDiagnosticSessionControl)0
#endif
#ifndef RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION
#define RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION      (Rte_ModeType_DcmDiagnosticSessionControl)1
#endif
#ifndef RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_DIAGNOSTIC_SESSION
#define RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_DIAGNOSTIC_SESSION        (Rte_ModeType_DcmDiagnosticSessionControl)2
#endif
#ifndef RTE_TRANSITION_DcmDiagnosticSessionControl
#define RTE_TRANSITION_DcmDiagnosticSessionControl          (Rte_ModeType_DcmDiagnosticSessionControl)255
#endif

#ifndef RTE_MODETYPE_DcmEcuReset
#define RTE_MODETYPE_DcmEcuReset
typedef uint8 Rte_ModeType_DcmEcuReset;
#endif
#ifndef RTE_MODE_DcmEcuReset_NONE
#define RTE_MODE_DcmEcuReset_NONE                           (Rte_ModeType_DcmEcuReset)0
#endif
#ifndef RTE_MODE_DcmEcuReset_HARD
#define RTE_MODE_DcmEcuReset_HARD                           (Rte_ModeType_DcmEcuReset)1
#endif
#ifndef RTE_MODE_DcmEcuReset_KEYONOFF
#define RTE_MODE_DcmEcuReset_KEYONOFF                       (Rte_ModeType_DcmEcuReset)2
#endif
#ifndef RTE_MODE_DcmEcuReset_SOFT
#define RTE_MODE_DcmEcuReset_SOFT                           (Rte_ModeType_DcmEcuReset)3
#endif
#ifndef RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER
#define RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER               (Rte_ModeType_DcmEcuReset)4
#endif
#ifndef RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER
#define RTE_MODE_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER    (Rte_ModeType_DcmEcuReset)5
#endif
#ifndef RTE_MODE_DcmEcuReset_EXECUTE
#define RTE_MODE_DcmEcuReset_EXECUTE                        (Rte_ModeType_DcmEcuReset)6
#endif
#ifndef RTE_TRANSITION_DcmEcuReset
#define RTE_TRANSITION_DcmEcuReset                          (Rte_ModeType_DcmEcuReset)255
#endif

#ifndef RTE_MODETYPE_DcmSecurityAccess
#define RTE_MODETYPE_DcmSecurityAccess
typedef uint8 Rte_ModeType_DcmSecurityAccess;
#endif
#ifndef RTE_MODE_DcmSecurityAccess_SEC_LEV_LOCKED
#define RTE_MODE_DcmSecurityAccess_SEC_LEV_LOCKED           (Rte_ModeType_DcmSecurityAccess)0
#endif
#ifndef RTE_TRANSITION_DcmSecurityAccess
#define RTE_TRANSITION_DcmSecurityAccess                    (Rte_ModeType_DcmSecurityAccess)255
#endif

#endif



