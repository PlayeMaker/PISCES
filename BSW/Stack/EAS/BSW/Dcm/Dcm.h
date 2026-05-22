/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dcm.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : Dcm.h
*   Author          : Hirain
********************************************************************************
*   Description: Dcm.h
*
********************************************************************************
*   Limitations: None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/

/*PRQA S 776 EOF*/
/*
Names in this file may not follow relevant rules.
*/

#ifndef DCM_H
#define DCM_H

/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dcm_Types.h"
#include "Dcm_Version.h"


/*******************************************************************************
* Macros and Typedef
*******************************************************************************/
/*Service ID*/
#define DCM_SID_INIT                       (uint8)0x01
#define DCM_SID_GETVERSIONINFO             (uint8)0x24
#define DCM_SID_DEMTRIGGERONDTCSTATUC      (uint8)0x2B
#define DCM_SID_GETVIN                     (uint8)0x07
#define DCM_SID_BNDMWRITEBLOCKFINISH       (uint8)0x7a

#define DCM_SID_SETDEAUTHENTICATEDROLE     (uint8)0x79
#define DCM_SID_GETSECURITYLEVEL           (uint8)0x0d
#define DCM_SID_GETSESCTRLTYPE             (uint8)0x06
#define DCM_SID_RESETTODEFAULTSESSION      (uint8)0x2a
#define DCM_SID_TRIGGERONEVENT             (uint8)0x2D
#define DCM_SID_SETACTIVEDIAGNOSTIC        (uint8)0x56

#define DCM_SID_STARTOFRECEPTION           (uint8)0x46
#define DCM_SID_COPYRXDATA                 (uint8)0x44
#define DCM_SID_TPRXINDICATION             (uint8)0x45
#define DCM_SID_COPYTXDATA                 (uint8)0x43
#define DCM_SID_TPTXCONFIRMATION           (uint8)0x48
#define DCM_SID_TXCONFIRMATION             (uint8)0x40

#define DCM_SID_COMMNOCOMMODEENTERED       (uint8)0x21
#define DCM_SID_COMMSILENTCOMMODEENTERED   (uint8)0x22
#define DCM_SID_COMMFULLCOMMODEENTERED     (uint8)0x23

#define DCM_SID_CSMASYNCJOBFINISHED                  (uint8)0x30
#define DCM_SID_KEYMASYNCCERTIFICATEVERIFYFINISHED   (uint8)0x31

#define DCM_SID_MAINFUNCTION               (uint8)0x25

/*EAS define API*/
#define DCM_SID_SETAUTHENTICATIONDEVELOPMENTSTATE    (uint8)0x80
#define DCM_SID_RESETAUTHENTICATIONNSTATE            (uint8)0x81
#define DCM_SID_GETAUTHENTICATIONNEEDSTOREDINFO      (uint8)0x82

/*SWS_Dcm_00044*//*SWS_Dcm_00040 Development Errors*/
#define DCM_E_INVALID_VALUE                (uint8)0x02
#define DCM_E_INTERFACE_RETURN_VALUE       (uint8)0x02
#define DCM_E_UNINIT                       (uint8)0x05
#define DCM_E_PARAM                        (uint8)0x06
#define DCM_E_PARAM_POINTER                (uint8)0x07
#define DCM_E_INIT_FAILED                  (uint8)0x08
#define DCM_E_SET_PROG_CONDITIONS_FAIL     (uint8)0x09
/*SWS_Dcm_01416 Runtime Errors*/
#define DCM_E_INTERFACE_TIMEOUT            (uint8)0x01
#define DCM_E_INTERFACE_BUFFER_OVERFLOW    (uint8)0x03


/*******************Common #define********************************************/
#define DCM_DATA_CLEAR                           (uint8)0
#define DCM_DATA_U8_MAX                          (uint8)0xFF
/*default session index*/
#define DCM_DEFAULT_IDX                          ((uint8)0)
/*Request/Response data index*/
#define DCM_SID_INDEX                            (Dcm_MsgLenType)0
#define DCM_INDEX_0                              (Dcm_MsgLenType)0
#define DCM_INDEX_1                              (Dcm_MsgLenType)1
#define DCM_INDEX_2                              (Dcm_MsgLenType)2
#define DCM_INDEX_3                              (Dcm_MsgLenType)3
#define DCM_INDEX_4                              (Dcm_MsgLenType)4
#define DCM_INDEX_5                              (Dcm_MsgLenType)5
#define DCM_INDEX_6                              (Dcm_MsgLenType)6
#define DCM_INDEX_7                              (Dcm_MsgLenType)7
#define DCM_INDEX_8                              (Dcm_MsgLenType)8
/*UDS Service length:fixed*/
#define DCM_LENGTH_1_BYTE                        ((Dcm_MsgLenType)1)
#define DCM_LENGTH_2_BYTE                        ((Dcm_MsgLenType)2)
#define DCM_LENGTH_3_BYTE                        ((Dcm_MsgLenType)3)
#define DCM_LENGTH_4_BYTE                        ((Dcm_MsgLenType)4)
#define DCM_LENGTH_5_BYTE                        ((Dcm_MsgLenType)5)
#define DCM_LENGTH_6_BYTE                        ((Dcm_MsgLenType)6)
#define DCM_LENGTH_7_BYTE                        ((Dcm_MsgLenType)7)
#define DCM_LENGTH_8_BYTE                        ((Dcm_MsgLenType)8)
#define DCM_LENGTH_9_BYTE                        ((Dcm_MsgLenType)9)

#define DCM_SHIFT_2                              (uint8)2
#define DCM_SHIFT_4                              (uint8)4
#define DCM_SHIFT_8                              (uint16)8
#define DCM_SHIFT_11                             (uint16)11
#define DCM_SHIFT_16                             (uint32)16
#define DCM_SHIFT_24                             (uint32)24


/*******************************************************************************
* Global parameter
*******************************************************************************/
#define DCM_START_SEC_VAR_CLEARED_LOCAL_8
#include "Dcm_MemMap.h"
extern VAR(uint8, DCM_VAR) Dcm_ProtocolId;
extern VAR(uint8, DCM_VAR) Dcm_ProtocolConnectionId;/*Index of a connection in a protocaol*/
/*Index of SessionRow[]*/
extern VAR(uint8, DCM_VAR) Dcm_SessionIndex;
#define DCM_STOP_SEC_VAR_CLEARED_LOCAL_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "Dcm_MemMap.h"
#if(DCM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
extern P2CONST(Dcm_ConfigType, DCM_VAR, DCM_CONST) Dcm_PBConfig;
#endif
#define DCM_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "Dcm_MemMap.h"
/*******************************************************************************
* Global Macros of variable parameters
*******************************************************************************/
#define DCM_ACTIVE_PCL_ID                        (Dcm_ProtocolId)
#define DCM_ACTIVE_CON_ID                        (Dcm_ProtocolConnectionId)
#define DCM_SES_IDX                              (Dcm_SessionIndex)



/*******************************************************************************
* Global Macros of configure parameters
*******************************************************************************/
#define DCM_CFG_PCL_STAB_IDX(i)                (Dcm_DslProtocolRow[i].DcmDslProtocolSIDTable)
#define DCM_CURRENT_STAB                       (DCM_CFG_PCL_STAB_IDX(DCM_ACTIVE_PCL_ID))





#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/*******************************************************************************
* Local Function Prototype: Only be called internally by Dcm itself.
*******************************************************************************/
FUNC(void, DCM_CODE) DsdInternal_ResetWithoutChangeSessionAndSendResponse
(
    void
);

/*******************************************************************************
* Global Function Prototype: Can be called by APP or other module.
*******************************************************************************/

/*SWS_Dcm_00037*/
extern FUNC(void, DCM_CODE) Dcm_Init
(
    P2CONST(Dcm_ConfigType, AUTOMATIC, DCM_APPL_DATA) ConfigPtr
);

#if(STD_ON == DCM_VERSION_INFO_API)
/*SWS_Dcm_00065*/
extern FUNC(void, DCM_CODE) Dcm_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DCM_APPL_DATA) versionInfo
);
#endif

/*SWS_Dcm_00950*/
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetVin
(
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data
);

#if(STD_ON == DCM_UDS_29_ENABLED)
/*SWS_Dcm_91069*/
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_SetDeauthenticatedRole
(
    uint16 connectionId,
    Dcm_AuthenticationRoleType deauthenticatedRole
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_SetAuthenticationDevelopmentState
(
    boolean DevelopmentStateEnabled
);
#if(DCM_CAR_PLATFORM == DCM_IVECO_PLATFORM)
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_ResetAuthenticationState
(
    void
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetAuthenticationNeedStoredInfo
(
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) ProtocolId,
    P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) ConnectionId,
    P2VAR(boolean, AUTOMATIC, DCM_APPL_DATA) IsAuthenticated,
    P2VAR(Dcm_AuRoleMaskType, AUTOMATIC, DCM_APPL_DATA) CurrentRole,
    P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) AuConsecutiveFailedCounter,
    P2VAR(uint32, AUTOMATIC, DCM_APPL_DATA) AuAbsoluteTimeoutTimer
);
#endif
#endif

/*SWS_Dcm_00338*/
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetSecurityLevel
(
    P2VAR(Dcm_SecLevelType, AUTOMATIC, DCM_APPL_DATA) SecLevel
);

/*SWS_Dcm_00339*/
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetSesCtrlType
(
    P2VAR(Dcm_SesCtrlType, AUTOMATIC, DCM_APPL_DATA) SesCtrlType
);

/*SWS_Dcm_00520*/
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_ResetToDefaultSession
(
    void
);

/*SWS_Dcm_01068*/
extern FUNC(Std_ReturnType, DCM_CODE) Dcm_SetActiveDiagnostic
(
    boolean active
);

/*SWS_Dcm_00053*/
extern FUNC(void, DCM_CODE) Dcm_MainFunction
(
    void
);


extern FUNC(Std_ReturnType, DCM_CODE) Dcm_ExternalSubServiceCheck
(
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_GetCommunicationState
(
    NetworkHandleType Channel,
    P2VAR(Dcm_CommunicationModeType, AUTOMATIC, DCM_VAR) NmMessageState,
    P2VAR(Dcm_CommunicationModeType, AUTOMATIC, DCM_VAR) AppMessageState
);

#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
extern FUNC(void, DCM_CODE) Dcm_SetNRC22Reason
(
    uint8 Reason
);
#endif


#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif/*DCM_H*/


