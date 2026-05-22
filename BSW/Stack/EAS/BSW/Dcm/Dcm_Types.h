/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dcm_Types.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : Dcm module head File
*   Author          : Hirain
********************************************************************************
*   Description: Main source file of the AUTOSAR Diagnositc communcation manager,
*               according to AUTOSAR_SWS_DiagnosticCommunicationManager.pdf
*               (Release R21-11) and ISO14229-1(2020).pdf.
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

#ifndef DCM_TYPES_H
#define DCM_TYPES_H

/*******************************************************************************
* Include files
*******************************************************************************/
#include "Rte_Dcm_Type.h"
#include "SchM_Dcm_Type.h"
/*SWS_Dcm_00333*/
#include "ComStack_Types.h"
#include "Dcm_Cfg.h"
#if(DCM_UDS_29_ENABLED == STD_ON)
#include "Csm_Types.h"
#include "KeyM_Types.h"
#endif

/*******************************************************************************
* Typedef
*******************************************************************************/
/*SWS_Dcm_00976*/
typedef uint8 Dcm_StatusType;
#define DCM_E_OK                            ((Dcm_StatusType)0x00)
#define DCM_E_ROE_NOT_ACCEPTED              ((Dcm_StatusType)0x06)
#define DCM_E_PERIODICID_NOT_ACCEPTED       ((Dcm_StatusType)0x07)

/*SWS_Dcm_00981*/
typedef uint8 Dcm_CommunicationModeType;
#define DCM_ENABLE_RX_TX_NORM               ((Dcm_CommunicationModeType)0x00)
#define DCM_ENABLE_RX_DISABLE_TX_NORM       ((Dcm_CommunicationModeType)0x01)
#define DCM_DISABLE_RX_ENABLE_TX_NORM       ((Dcm_CommunicationModeType)0x02)
#define DCM_DISABLE_RX_TX_NORMAL            ((Dcm_CommunicationModeType)0x03)
#define DCM_ENABLE_RX_TX_NM                 ((Dcm_CommunicationModeType)0x04)
#define DCM_ENABLE_RX_DISABLE_TX_NM         ((Dcm_CommunicationModeType)0x05)
#define DCM_DISABLE_RX_ENABLE_TX_NM         ((Dcm_CommunicationModeType)0x06)
#define DCM_DISABLE_RX_TX_NM                ((Dcm_CommunicationModeType)0x07)
#define DCM_ENABLE_RX_TX_NORM_NM            ((Dcm_CommunicationModeType)0x08)
#define DCM_ENABLE_RX_DISABLE_TX_NORM_NM    ((Dcm_CommunicationModeType)0x09)
#define DCM_DISABLE_RX_ENABLE_TX_NORM_NM    ((Dcm_CommunicationModeType)0x0A)
#define DCM_DISABLE_RX_TX_NORM_NM           ((Dcm_CommunicationModeType)0x0B)

/*SWS_Dcm_00985*/
typedef uint8 Dcm_ReturnReadMemoryType;
#define DCM_READ_OK                         ((Dcm_ReturnReadMemoryType)0x00)
#define DCM_READ_PENDIN                     ((Dcm_ReturnReadMemoryType)0x01)
#define DCM_READ_FAILED                     ((Dcm_ReturnReadMemoryType)0x02)
#define DCM_READ_FORCE_RCRRP                ((Dcm_ReturnReadMemoryType)0x03)

/*SWS_Dcm_00986*/
typedef uint8 Dcm_ReturnWriteMemoryType;
#define DCM_WRITE_OK                        ((Dcm_ReturnWriteMemoryType)0x00)
#define DCM_WRITE_PENDIN                    ((Dcm_ReturnWriteMemoryType)0x01)
#define DCM_WRITE_FAILED                    ((Dcm_ReturnWriteMemoryType)0x02)
#define DCM_WRITE_FORCE_RCRRP               ((Dcm_ReturnWriteMemoryType)0x03)

/*SWS_Dcm_00987*/
typedef uint8 Dcm_EcuStartModeType;
#define DCM_COLD_START                      ((Dcm_EcuStartModeType)0x00)
#define DCM_WARM_START                      ((Dcm_EcuStartModeType)0x01)

/*SWS_Dcm_00988*/
typedef struct
{
    uint16  ConnectionId;
    uint16  TesterAddr;
    uint8   Sid;
    uint8   SubFncId;
    boolean ReprogramingRequest;
    boolean ApplUpdated;
    boolean ResponseRequired;
} Dcm_ProgConditionsType;

/*SWS_Dcm_00989*/
typedef uint8 Dcm_MsgItemType;
/*SWS_Dcm_00990*/
typedef P2VAR(Dcm_MsgItemType, AUTOMATIC, DCM_APPL_DATA) Dcm_MsgType;
/*SWS_Dcm_00991*/
typedef uint32 Dcm_MsgLenType;

#define DCM_PHYSICAL_TYPE    (uint8)0
#define DCM_FUNCTIONAL_TYPE  (uint8)1

/*SWS_Dcm_00992*/
typedef struct
{
    /* 0: physical request
       1: functional request*/
    uint8 reqType;
    /* FALSE: do not suppress
       TRUE: no positive response will be sent */
    boolean suppressPosResponse;
} Dcm_MsgAddInfoType;

#define DCM_REQ_PHY_MASK      ((uint8)0x01)
#define DCM_REQ_FUN_MASK      ((uint8)0x02)
#define DCM_REQ_PHY_FUN_MASK  ((uint8)0x03)

/*SWS_Dcm_00993*/
typedef uint8 Dcm_IdContextType;

/*SWS_Dcm_00994*/
typedef struct
{
    Dcm_MsgType        reqData;
    Dcm_MsgLenType     reqDataLen;
    Dcm_MsgType        resData;
    Dcm_MsgLenType     resDataLen;
    Dcm_MsgAddInfoType msgAddInfo;
    Dcm_MsgLenType     resMaxDataLen;
    Dcm_IdContextType  idContext;
    PduIdType          dcmRxPduId;
} Dcm_MsgContextType;

typedef struct Dcm_BufferList
{
    struct Dcm_BufferList     *nextPtr;
    Dcm_MsgType               reqData;
    Dcm_MsgLenType            reqDataLen;
    Dcm_MsgType               resData;
    Dcm_MsgAddInfoType        msgAddInfo;
    uint8                     rxBufferIndex;
    boolean                   bufferIsUesd;
} Dcm_BufferListType;

/*SWS_Dcm_91015*/
typedef uint8 Dcm_ExtendedOpStatusType;
/*#define DCM_INITIAL                (Dcm_ExtendedOpStatusType)0x00*/
/*#define DCM_PENDING                (Dcm_ExtendedOpStatusType)0x01*/
/*#define DCM_CANCEL                 (Dcm_ExtendedOpStatusType)0x02*/
/*#define DCM_FORCE_RCRRP_OK         (Dcm_ExtendedOpStatusType)0x03*/
#define DCM_POS_RESPONSE_SENT      (Dcm_ExtendedOpStatusType)0x04
#define DCM_POS_RESPONSE_FAILED    (Dcm_ExtendedOpStatusType)0x05
#define DCM_NEG_RESPONSE_SENT      (Dcm_ExtendedOpStatusType)0x06
#define DCM_NEG_RESPONSE_FAILED    (Dcm_ExtendedOpStatusType)0x07

/*Car platform types*/
#define DCM_NO_PLATFORM        0
#define DCM_GAC_PLATFORM       1
#define DCM_HYUNDAI_PLATFORM   2
#define DCM_GEELY_PLATFORM     3
#define DCM_RNDS_PLATFORM      4
#define DCM_NISSAN_PLATFORM    5
#define DCM_FAW_PLATFORM       6
#define DCM_SAIC_PLATFORM      7
#define DCM_IVECO_PLATFORM     8
#define DCM_MI_PLATFORM        9


typedef uint32 Dcm_SecurityMaskType;
typedef uint32 Dcm_SessionMaskType;
/*Type of authentication role mask*/
typedef uint32 Dcm_AuRoleMaskType;

/*UDS service ID*/
#define DCM_10_SERVICE         ((uint8)0x10)
#define DCM_11_SERVICE         ((uint8)0x11)
#define DCM_14_SERVICE         ((uint8)0x14)
#define DCM_19_SERVICE         ((uint8)0x19)
#define DCM_22_SERVICE         ((uint8)0x22)
#define DCM_23_SERVICE         ((uint8)0x23)
#define DCM_24_SERVICE         ((uint8)0x24)
#define DCM_27_SERVICE         ((uint8)0x27)
#define DCM_28_SERVICE         ((uint8)0x28)
#define DCM_29_SERVICE         ((uint8)0x29)
#define DCM_2A_SERVICE         ((uint8)0x2A)
#define DCM_2C_SERVICE         ((uint8)0x2C)
#define DCM_2E_SERVICE         ((uint8)0x2E)
#define DCM_2F_SERVICE         ((uint8)0x2F)
#define DCM_31_SERVICE         ((uint8)0x31)
#define DCM_34_SERVICE         ((uint8)0x34)
#define DCM_35_SERVICE         ((uint8)0x35)
#define DCM_36_SERVICE         ((uint8)0x36)
#define DCM_37_SERVICE         ((uint8)0x37)
#define DCM_38_SERVICE         ((uint8)0x38)
#define DCM_3D_SERVICE         ((uint8)0x3D)
#define DCM_3E_SERVICE         ((uint8)0x3E)
#define DCM_83_SERVICE         ((uint8)0x83)
#define DCM_84_SERVICE         ((uint8)0x84)
#define DCM_85_SERVICE         ((uint8)0x85)
#define DCM_86_SERVICE         ((uint8)0x86)
#define DCM_87_SERVICE         ((uint8)0x87)
/*OBD service ID*/
#define DCM_01_SERVICE         ((uint8)0x01)
#define DCM_02_SERVICE         ((uint8)0x02)
#define DCM_03_SERVICE         ((uint8)0x03)
#define DCM_04_SERVICE         ((uint8)0x04)
#define DCM_05_SERVICE         ((uint8)0x05)
#define DCM_06_SERVICE         ((uint8)0x06)
#define DCM_07_SERVICE         ((uint8)0x07)
#define DCM_08_SERVICE         ((uint8)0x08)
#define DCM_09_SERVICE         ((uint8)0x09)
#define DCM_0A_SERVICE         ((uint8)0x0A)

/*Dcm return type*/
/*SWS_Dcm_00690*/
#define DCM_E_PENDING               ((Std_ReturnType)10)/*0xA*/
#define DCM_E_FORCE_RCRRP           ((Std_ReturnType)12)/*0xC*/
/*SWS_Dcm_00685*/
#define DCM_E_COMPARE_KEY_FAILED    ((Std_ReturnType)11)
/*SWS_Dcm_00694*/
#define DCM_E_REQUEST_NOT_ACCEPTED  ((Std_ReturnType)8)


/*Used by DcmVinRef. The 16 high-significant bits of the DcmVinRef data represent
the Protocol index value, and the 16 low-significant bits represent the index value
of the associated DID in the DID list*/
#define DCM_INVALID_VIN_REF         (0xFFFFFFFFU)


#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
/*SWS_Dcm_01190 SWS_Dcm_00674 API User_StartProtocol()/User_StopProtocol() doesn't return E_OK*/
#define DCM_NRC22_REASON_0              ((uint8)1)
/*SWS_Dcm_01175 Can not be switched jumptobootloader or jumptosyssupplierbootloader*/
#define DCM_NRC22_REASON_1              ((uint8)2)
/*SWS_Dcm_00715 API Dcm_SetProgConditions() return E_NOT_OK*/
#define DCM_NRC22_REASON_2              ((uint8)3)
/* SWS_Dcm_01267 While not all Xxx_GetSecurityAttemptCounter operations have returned a final status
and the operation chain has not been cancelled, the conditionsNotCorrect (0x22) NRC shall be returned
to any SecurityAccess (0x27) requestSeed subfunction request.*/
#define DCM_NRC22_REASON_3              ((uint8)4)
/*SWS_Dcm_00704 SWS_Dcm_00967 SWS_Dcm_01067 Dem Clear DTC Failed*/
#define DCM_NRC22_REASON_4              ((uint8)5)

#define DCM_NRC22_REASON_8              ((uint8)9)	/*SWS_Dcm_01192 OBD Service 08 TID Error*/
#define DCM_NRC22_REASON_9              ((uint8)10)	/*SWS_Dcm_01191 OBD Service 09 InfoType Data Error*/
#endif

/*******************************************************************************
* for Dsd SubModule
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFunctionServiceFncDef)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);

/*ECUC_Dcm_00802*/
typedef struct
{
    /*ECUC_Dcm_00803*/
    uint8 DcmDsdSubServiceId;
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
    /*ECUC_Dcm_01047*/
    boolean DcmDsdSubServiceUsed;
#endif
    uint8 DcmDsdSubServiceSupportAddress;
    /*ECUC_Dcm_00812*/
#if(STD_ON == DCM_UDS_27_ENABLED)
    Dcm_SecurityMaskType DcmDsdSubServiceSecurityLevelRef;
#endif
    /*ECUC_Dcm_00804*/
    Dcm_SessionMaskType DcmDsdSubServiceSessionLevelRef;
#if(STD_ON == DCM_UDS_29_ENABLED)
    /*ECUC_Dcm_01140 0..32*/
    Dcm_AuRoleMaskType DcmDsdSubServiceRoleRef;
#endif
    /*ECUC_Dcm_00942*/
    EcucFunctionServiceFncDef DcmDsdSubServiceFnc;
} Dcm_DsdSubServiceType;

/*ECUC_Dcm_00689*//*ECUC_Dcm_00732*/
typedef struct
{
    /*ECUC_Dcm_00735*//*constr_6047*/
    uint8 DcmDsdSidTabServiceId; /*0..255*/
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
    /*ECUC_Dcm_01044*/
    boolean DcmDsdServiceUsed;
#endif
    uint8 DcmDsdServiceSupportAddress;
    uint16 DcmDsdServiceMinLength;
    /*ECUC_Dcm_00777*/
    EcucFunctionServiceFncDef DcmDsdSidTabFnc;
    /*ECUC_Dcm_00737*/
    boolean DcmDsdSidTabSubfuncAvail;
    /*ECUC_Dcm_00733*/
#if(STD_ON == DCM_UDS_27_ENABLED)
    Dcm_SecurityMaskType DcmDsdSidTabSecurityLevelRef;
#endif
    /*ECUC_Dcm_00734*/
    Dcm_SessionMaskType DcmDsdSidTabSessionLevelRef;
    uint8 NumOfSubService;
    uint16 StartIndexOfSubService;
#if(STD_ON == DCM_UDS_29_ENABLED)
    /*ECUC_Dcm_01139 0..32*/
    Dcm_AuRoleMaskType DcmDsdServiceRoleRef;
#endif
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
    uint32 P4ServerMax;
#endif
} Dcm_DsdServiceType;

/*ECUC_Dcm_00732*/
typedef struct
{
    /*ECUC_Dcm_00736*/
    uint8 DcmDsdSidTabId;/*0..255*/
    /*ECUC_Dcm_00689*/
    uint8 NumOfService;
    const Dcm_DsdServiceType *DcmDsdService;
    uint16 NumOfSubService;
    const Dcm_DsdSubServiceType *DcmDsdSubService;
} Dcm_DsdServiceTableType;


/*******************************************************************************
* for Dsl SubModule
*******************************************************************************/
/*ECUC_Dcm_00739*/
typedef struct
{
    /*ECUC_Dcm_00738*/
    Dcm_MsgLenType DcmDslBufferSize; /*8..0xFFFFFFFE(4294967294)*/
    Dcm_MsgType DataPtr;
} Dcm_DslBufferType;


typedef enum
{
    DCM_TYPE1 = 0,
    DCM_TYPE2 = 1
} Dcm_DslProtocolTransType;


/*ECUC_Dcm_00709*/
typedef struct
{
    /*ECUC_Dcm_00710*/
    uint8 DcmDslProtocolRxAddrType;
    /*ECUC_Dcm_00687*/
    PduIdType DcmDslProtocolRxPduId;
} Dcm_DslProtocolRxType;

/*ECUC_Dcm_00711*/
typedef struct
{
    /*ECUC_Dcm_00864*/
    PduIdType DcmDslTxConfirmationPduId;
    /*ECUC_Dcm_00772*/
    PduIdType DcmDslProtocolTxPduRef;
} Dcm_DslProtocolTxType;


/*ECUC_Dcm_00897*/
typedef struct
{
    /*ECUC_Dcm_00862*/
    PduIdType DcmDslPeriodicTxConfirmationPduId;
    /*ECUC_Dcm_00742*/
    PduIdType DcmDslPeriodicTxPduRef;
} Dcm_DslPeriodicConnectionType;


/*ECUC_Dcm_00741*/
typedef struct
{
    uint8 NumOfPeriodicConnection;
    const Dcm_DslPeriodicConnectionType *DcmDslPeriodicConnection;
} Dcm_DslPeriodicTransmissionType;

/*ECUC_Dcm_00706*/
typedef struct
{
    /*ECUC_Dcm_00826 Range: 0-65535*/
    uint16 DcmDslProtocolRxConnectionId;
    /*ECUC_Dcm_01115 Range: 0-65535*/
    uint16 DcmDslProtocolRxTesterSourceAddr;
    /*ECUC_Dcm_00952*/
    NetworkHandleType DcmDslProtocolComMChannelRef;
#if(STD_ON == DCM_UDS_29_ENABLED)
    uint8 DcmDslAuthenticationConnectionRef;
#endif
    uint8 NumOfRxPdu;/*1..**/
    const Dcm_DslProtocolRxType *DcmDslProtocolRx;
    const Dcm_DslProtocolTxType *DcmDslProtocolTx;
} Dcm_DslMainConnectionType;

/*ECUC_Dcm_00705*/
typedef struct
{
    const Dcm_DslMainConnectionType *DcmDslMainConnection;
    const Dcm_DslPeriodicTransmissionType *DcmDslPeriodicTransmission;
} Dcm_DslConnectionType;

/*ECUC_Dcm_00694*//*ECUC_Dcm_00695*/
typedef struct
{
    /*ECUC_Dcm_01110*/
    Dcm_ProtocolType DcmDslProtocolType;
    /*ECUC_Dcm_00699 Lower numeric values represent higher protocol priority*/
    uint8 DcmDslProtocolPriority; /*0 .. 255*/
    /*ECUC_Dcm_00729 Guarantee that the diagnostic response is available on the bus
    before reaching P2 by adjusting the current DcmDspSessionP2ServerMax.*/
    uint16 DcmTimStrP2ServerAdjust; /*0 .. 1000, unit:ms*/
    /*ECUC_Dcm_00728 Guarantee that the diagnostic response is available on the bus
    before reaching P2Star by adjusting the current DcmDspSessionP2StarServerMax.*/
    uint16 DcmTimStrP2StarServerAdjust; /*0 .. 5000, unit:ms*/
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
    /*ECUC_Dcm_01043:Allows to activate or deactivate the usage of a Protocol.
    This parameter can be used for multi-purpose ECUs.*/
    boolean DcmDslProtocolRowUsed;
#endif
    /*ECUC_Dcm_01081*/
    uint16 DcmDspProtocolEcuAddr; /*0..65535*/
    /*ECUC_Dcm_00700*/
    Dcm_DslProtocolTransType DcmDslProtocolTransType; /*TYPE1 or TYPE2*/
    /*ECUC_Dcm_01114*/
    boolean DcmSendRespPendOnRestart;
#if(DCM_DEM_SUPPORT == STD_ON)
    /*ECUC_Dcm_01083*/
    uint8 DcmDemClientRef; /*0..255*/
#endif
    /*ECUC_Dcm_00701*/
    Dcm_DslBufferType DcmDslProtocolRxBufferRef;
    /*ECUC_Dcm_00704*/
    Dcm_DslBufferType DcmDslProtocolTxBufferRef;
    /*ECUC_Dcm_00702*/
    uint8 DcmDslProtocolSIDTable;
    uint8 NumOfConnection;
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
    const Dcm_DslConnectionType *DcmDslConnection;/*1..**/
#endif
    uint32 S3Server;
#if(DCM_RXFIFOBUFFER_ENABLED == STD_ON)
    uint8 DcmDslNumofRxFifoBuffer;
    boolean DcmTxRxSameBuffer;
#endif
} Dcm_DslProtocolRowType;


/*******************************************************************************
* for Dsp SubModule
*******************************************************************************/
typedef enum
{
    DCM_OPAQUE        = 0,
    DCM_BIG_ENDIAN    = 1,
    DCM_LITTLE_ENDIAN = 2
} Dcm_DataEndiannessType;

typedef enum
{
    DCM_BOOLEAN          = 0,
    DCM_FLOAT            = 1,
    DCM_FLOAT_N          = 2,
    DCM_SINT16           = 3,
    DCM_SINT16_N         = 4,
    DCM_SINT32           = 5,
    DCM_SINT32_N         = 6,
    DCM_SINT8            = 7,
    DCM_SINT8_N          = 8,
    DCM_UINT16           = 9,
    DCM_UINT16_N         = 10,
    DCM_UINT32           = 11,
    DCM_UINT32_N         = 12,
    DCM_UINT8            = 13,
    DCM_UINT8_DYN        = 14, /*Only used by signal of Data ID*/
    DCM_UINT8_N          = 15,
    DCM_VARIABLE_LENGTH  = 16  /*Only used by signal of Routine ID*/
} Dcm_DataType;


/*******************************************************************************
* for UDS 10 Service
*******************************************************************************/
#if(DCM_UDS_10_ENABLED == STD_ON)
/*ECUC_Dcm_00815*/
typedef enum
{
    DCM_NO_BOOT = 0,
    DCM_OEM_BOOT,
    DCM_OEM_BOOT_RESPAPP,
    DCM_SYS_BOOT,
    DCM_SYS_BOOT_RESPAPP
} Dcm_DspSessionForBootType;

/*ECUC_Dcm_00767*/
typedef struct
{
    /*ECUC_Dcm_00815*/
    Dcm_DspSessionForBootType DcmDspSessionBoot;
    /*ECUC_Dcm_00765 subFunction value of the DiagnosticSession*/
    Dcm_SesCtrlType DcmDspSessionLevel;
    Dcm_SessionMaskType DcmDspSessionMask;
    /*ECUC_Dcm_00766*/
    uint16 DcmDspSessionP2ServerMax;/*unit:ms*/
    /*ECUC_Dcm_00768*/
    uint32 DcmDspSessionP2StarServerMax;/*unit:ms*/
    Rte_ModeType_DcmDiagnosticSessionControl DcmDspSessionSchMMode;
} Dcm_DspSessionRowType;

/*ECUC_Dcm_00769*/
typedef struct
{
    uint8 NumOfSessionRow;
    const Dcm_DspSessionRowType *DcmDspSessionRow;
} Dcm_DspSessionType;
#endif

/*******************************************************************************
* for UDS 11 Service
*******************************************************************************/
#if(DCM_UDS_11_ENABLED == STD_ON)
/*ECUC_Dcm_01039*/
typedef enum
{
    DCM_AFTER_RESET  = 0,
    DCM_BEFORE_RESET = 1
} Dcm_ResponseToEcuResetType;

/*ECUC_Dcm_01112*/
typedef struct
{
    /*ECUC_Dcm_01113*/
    uint8 DcmDspEcuResetId;
    /*ECUC_Dcm_01039*/
    Dcm_ResponseToEcuResetType DcmResponseToEcuReset;
} Dcm_DspEcuResetRowType;

/*ECUC_Dcm_01111*/
typedef struct
{
    uint8 NumOfEcuResetRow;
    const Dcm_DspEcuResetRowType *DcmDspEcuResetRow;
} Dcm_DspEcuResetType;
#endif

/*******************************************************************************
* for UDS 23 Service
*******************************************************************************/
/*******************************************************************************
* for UDS 3D Service
*******************************************************************************/
/*******************************************************************************
* for UDS 34 Service
*******************************************************************************/
/*******************************************************************************
* for UDS 35 Service
*******************************************************************************/
#define DCM_INVALID_MEMORY_ID   ((uint8)0xFF)

#if((DCM_UDS_23_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON))
/*ECUC_Dcm_00785*/
typedef struct
{
    /*ECUC_Dcm_00787 Range: 0..4294967294(0xFFFF FFFE)*/
    uint32 DcmDspReadMemoryRangeHigh;
    /*ECUC_Dcm_00786 Range: 0..4294967294(0xFFFF FFFE)*/
    uint32 DcmDspReadMemoryRangeLow;
#if(STD_ON == DCM_UDS_27_ENABLED)
    /*ECUC_Dcm_00788*/
    Dcm_SecurityMaskType DcmDspReadMemoryRangeSecurityLevelRef;
#endif
#if(STD_ON == DCM_UDS_29_ENABLED)
    /*EAS defined*/
    Dcm_AuRoleMaskType DcmDspReadMemoryRangeRoleRef;
#endif
    /*ECUC_Dcm_01086*/
    Dcm_SessionMaskType DcmDspReadMemoryRangeSessionLevelRef;
} Dcm_DspReadMemoryRangeInfoType;
#endif

#if((DCM_UDS_3D_ENABLED == STD_ON) || (DCM_UDS_34_ENABLED == STD_ON))
/*ECUC_Dcm_00789*/
typedef struct
{
    /*ECUC_Dcm_00791 Range: 0..4294967294(0xFFFF FFFE)*/
    uint32 DcmDspWriteMemoryRangeHigh;
    /*ECUC_Dcm_00790 Range: 0..4294967294(0xFFFF FFFE)*/
    uint32 DcmDspWriteMemoryRangeLow;
#if(STD_ON == DCM_UDS_27_ENABLED)
    /*ECUC_Dcm_00793*/
    Dcm_SecurityMaskType DcmDspWriteMemoryRangeSecurityLevelRef;
#endif
#if(STD_ON == DCM_UDS_29_ENABLED)
    /*EAS defined*/
    Dcm_AuRoleMaskType DcmDspWriteMemoryRangeRoleRef;
#endif
    /*ECUC_Dcm_01076*/
    Dcm_SessionMaskType DcmDspWriteMemoryRangeSessionLevelRef;
} Dcm_DspWriteMemoryRangeInfoType;
#endif

#if((DCM_UDS_23_ENABLED == STD_ON) || (DCM_UDS_3D_ENABLED == STD_ON) || (DCM_UDS_34_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON))
/*ECUC_Dcm_00911*/
typedef struct
{
    /*ECUC_Dcm_00913 Range: 0..255*/
    uint8 DcmDspMemoryIdValue;
#if((DCM_UDS_23_ENABLED == STD_ON) || (DCM_UDS_35_ENABLED == STD_ON))
    uint16 NumofReadMemory;
    const Dcm_DspReadMemoryRangeInfoType *DcmDspReadMemoryRangeInfo;
#endif
#if((DCM_UDS_3D_ENABLED == STD_ON) || (DCM_UDS_34_ENABLED == STD_ON))
    uint16 NumofWriteMemory;
    const Dcm_DspWriteMemoryRangeInfoType *DcmDspWriteMemoryRangeInfo;
#endif
} Dcm_DspMemoryIdInfoType;

/*ECUC_Dcm_00784*/
typedef struct
{
    /*ECUC_Dcm_00963, ECUC_Dcm_00964 Range: 0..255*/
    uint8 NumOfFormat;
    const uint8 *DcmDspSupportedAddressAndLengthFormatIdentifier;
    /*ECUC_Dcm_00911*/
    uint8 NumOfMemoryId;
    const Dcm_DspMemoryIdInfoType *DcmDspMemoryIdInfo;
} Dcm_DspMemoryType;
#endif


/*******************************************************************************
* for UDS 27 Service
*******************************************************************************/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncGetSeedDef)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode
);
/*SWS_Dcm_91004*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncCompareKeyDef)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_APPL_DATA) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) pErrorCode
);
/*SWS_Dcm_01152*/
#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
    typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncGetAttemptCounterDef)
    (
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) AttemptCounter,
        P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) KeyCounter,
        P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) SeedCounter
    );
#else
    typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncGetAttemptCounterDef)
    (
        Dcm_OpStatusType OpStatus,
        P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) AttemptCounter
    );
#endif

/*SWS_Dcm_01153*/
#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
    typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncSetAttemptCounterDef)
    (
        Dcm_OpStatusType OpStatus,
        uint8 AttemptCounter,
        uint8 KeytCounter,
        uint8 SeedCounter
    );
#else
    typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncSetAttemptCounterDef)
    (
        Dcm_OpStatusType OpStatus,
        uint8 AttemptCounter
    );
#endif
/*ECUC_Dcm_00759*/
typedef struct
{
    /*ECUC_Dcm_00754*/
    /*Value of Security level,SecurityLevel = (SecurityAccessType (requestSeed) + 1) / 2*/
    Dcm_SecLevelType DcmDspSecurityLevel;
    /*ECUC_Dcm_00762 Range: 1 .. 255*/
    uint8 DcmDspSecurityNumAttDelay;
#if(DCM_CAR_PLATFORM == DCM_MI_PLATFORM)
    uint8 DcmDspSecurityNumKeyAttDelay;
    uint8 DcmDspSecurityNumSeedAttDelay;
#endif
#if(STD_ON == DCM_CFG_ADR_SUPPORT)
    /*ECUC_Dcm_00725 Range: 1 .. 4294967295, 0 is the invalid value*/
    uint32 DcmDspSecurityADRSize;
#endif
    /*ECUC_Dcm_00755*/
    uint32 DcmDspSecuritySeedSize;
    /*ECUC_Dcm_00760*/
    uint32 DcmDspSecurityKeySize;
    /*ECUC_Dcm_00757 Range: 0..65535000 ms*/
    uint32 DcmDspSecurityDelayTime;
    /*ECUC_Dcm_00726 Range: 0..65535000 ms*/
    uint32 DcmDspSecurityDelayTimeOnBoot;
    /*ECUC_Dcm_00968*/
    EcucFncGetSeedDef DcmDspSecurityGetSeedFnc;
    /*ECUC_Dcm_00969*/
    EcucFncCompareKeyDef DcmDspSecurityCompareKeyFnc;
#if(STD_ON == DCM_CFG_ACCESS_ATTEMPT_COUNTER_SUPPORT)
    /*ECUC_Dcm_01050*/
    boolean DcmDspSecurityAttemptCounterEnabled;
    /*ECUC_Dcm_01048*/
    EcucFncGetAttemptCounterDef DcmDspSecurityGetAttemptCounterFnc;
    /*ECUC_Dcm_01049*/
    EcucFncSetAttemptCounterDef DcmDspSecuritySetAttemptCounterFnc;
#endif
    Dcm_SecurityMaskType DcmDspSecurityMask;
} Dcm_DspSecurityRowType;

/*ECUC_Dcm_00764*/
typedef struct
{
    uint8 NumOfSecurityRow;
    const Dcm_DspSecurityRowType *DcmDspSecurityRow;
} Dcm_DspSecurityType;

/*******************************************************************************
* for UDS 28 Service
*******************************************************************************/
#if(DCM_UDS_28_ENABLED == STD_ON)
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucSwitchFncCommunicationControl)
(
    uint8 nextMode
);
/*ECUC_Dcm_00901*/
typedef struct
{
    /*ECUC_Dcm_01045*/
    boolean DcmDspComControlAllChannelUsed;
    /*ECUC_Dcm_00902*/
    uint8 DcmDspAllComMChannelRef;
    EcucSwitchFncCommunicationControl SwitchCommunicationControlAllChannelFnc;
} Dcm_DspComControlAllChannelType;

/*ECUC_Dcm_00903*/
typedef struct
{
    /*ECUC_Dcm_01046*/
    boolean DcmDspComControlSpecificChannelUsed;
    /*ECUC_Dcm_00905*/
    uint8 DcmDspSubnetNumber;/*1..14*/
    /*ECUC_Dcm_00904*/
    uint8 DcmDspComMChannelRef;
    EcucSwitchFncCommunicationControl SwitchCommunicationControlSpecificChannelFnc;
} Dcm_DspComControlSpecificChannelType;

/*ECUC_Dcm_01033*/
typedef struct
{
    /*ECUC_Dcm_01031*/
    uint16 DcmDspComControlSubNodeId;/*1..65535*/
    /*ECUC_Dcm_01032*/
    boolean DcmDspComControlSubNodeUsed;
    /*ECUC_Dcm_01030*/
    uint8 DcmDspComControlSubNodeComMChannelRef;
    EcucSwitchFncCommunicationControl SwitchCommunicationControlSubNodeFnc;
} Dcm_DspComControlSubNodeType;

/*ECUC_Dcm_00900*/
typedef struct
{
    uint8 NumOfControlAllChannel;/*0..255*/
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
    const Dcm_DspComControlAllChannelType *DcmDspComControlAllChannel;
#endif
    uint8 NumOfControlSpecificChannel;/*0..14*/
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
    const Dcm_DspComControlSpecificChannelType *DcmDspComControlSpecificChannel;
#endif
    uint16 NumOfControlSubNode;/*0..65535*/
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
    const Dcm_DspComControlSubNodeType *DcmDspComControlSubNode;
#endif
} Dcm_DspComControlType;
#endif

/*******************************************************************************
* for UDS 29 Service
*******************************************************************************/
#if(DCM_UDS_29_ENABLED == STD_ON)
/*ECUC_Dcm_01151 DcmDspAuthentication*/
/*ECUC_Dcm_01211 DcmDspAuthenticationRow*/
/*ECUC_Dcm_01212 DcmDspAuthenticationRoleBitPosition*/

typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucSwitchFncAuthenticationState)
(
    uint8 nextMode
);

/*ECUC_Dcm_01162 DcmDspAuthenticationConnection*/
typedef struct
{
    /*ECUC_Dcm_01163 DcmDspAuthenticationConnectionMainConnectionRef*/
    /*ECUC_Dcm_01186 Range:1-65535*/
    uint16 DcmDspAuthenticationEcuChallengeLength;
    /*TRUE indicates that the RandomJob is synchronous.*/
    boolean DcmDspAuthenticationRandomJobIsSync;
    /*ECUC_Dcm_01173 Reference to CsmJob*/
    uint32 DcmDspAuthenticationRandomJobRef;
    /*ECUC_Dcm_01176 DcmDspAuthenticationCertificatePublicKeyStoreJobRef The parameter has no defined function, so it is no implemented.*/
    /*ECUC_Dcm_01174 Reference to a Csmjob used to sign the client challenge.*/
    uint32 DcmDspAuthenticationClientChallengeSignJobRef;
    /*ECUC_Dcm_01175 Reference to CsmJob*/
    uint32 DcmDspAuthenticationVerifyProofOfOwnerShipClientJobRef;

    /*ECUC_Dcm_01164 Reference to a KeyMCertificate used to store the certificate within the KeyM.*/
    KeyM_CertificateIdType DcmDspAuthenticationConnectionCertificateRef;
    /*ECUC_Dcm_01177 0..1, Reference to KeyMCertificate, only for 02 sub service*/
    KeyM_CertificateIdType DcmDspAuthenticationECUCertificateRef;

    /*ECUC_Dcm_01178 0..1, DcmDspAuthenticationECUCertificateKeyElementRef The parameter has no defined function, so it is no implemented.*/
    /*ECUC_Dcm_01166 DcmDspAuthenticationPublicKeyElementRef The parameter has no defined function, so it is no implemented.*/

    /*The high 16 bits represent the identifier of KeyMCertificate, and the low 16 bits represent the
      identifier of KeyMCertificateElement*/
    /*ECUC_Dcm_01167 DcmDspAuthenticationRoleElementRef, Reference to KeyMCertificateElement*/
    uint32 RoleRef;
#if(DCM_DSP_AUTHENTICATION_SERVICE_MAX_SIZE > 0)
    /*ECUC_Dcm_01168 0..1, DcmDspAuthenticationWhiteListServicesElementRef, Reference to KeyMCertificateElement*/
    uint32 WhiteListServicesRef;
#endif
#if(DCM_DSP_AUTHENTICATION_DID_MAX_SIZE > 0)
    /*ECUC_Dcm_01169 0..1, DcmDspAuthenticationWhiteListDIDElementRef, Reference to KeyMCertificateElement*/
    uint32 WhiteListDIDRef;
#endif
#if(DCM_DSP_AUTHENTICATION_RID_MAX_SIZE > 0)
    /*ECUC_Dcm_01170 0..1, DcmDspAuthenticationWhiteListRIDElementRef, Reference to KeyMCertificateElement*/
    uint32 WhiteListRIDRef;
#endif
#if(DCM_DSP_AUTHENTICATION_MEM_MAX_SIZE > 0)
    /*ECUC_Dcm_01171 0..1, DcmDspAuthenticationWhiteListMemorySelectionElementRef, Reference to KeyMCertificateElement*/
    uint32 WhiteListMemorySelectionRef;
#endif
    EcucSwitchFncAuthenticationState AuthenticationStateModeSwitchInterface;
} Dcm_DspAuthenticationConnectionType;
#endif

/*******************************************************************************
* for UDS 2A Service
*******************************************************************************/
#if(DCM_UDS_2A_ENABLED == STD_ON)
/*ECUC_Dcm_01180*/
typedef enum
{
    DCM_SCHEDULER_TYPE1  = 0,
    DCM_SCHEDULER_TYPE2  = 1
} Dcm_DspPeriodicTransmissionSchedulerType;

typedef struct
{
    uint8 PeriodicDid;/*low byte of the DID*/
    uint16 PeriodicDidIndex;/*Did index in the Did table*/
    uint16 PeriodicTimer;
    uint8 PeriodicRate;
    uint8 PeriodicDidDataBuffer[DCM_PERIODIC_BUFFER_LEN];
} Dcm_PeriodicScheduleType;
#endif

/*******************************************************************************
* for UDS 2C Service
*******************************************************************************/
#if(DCM_UDS_2C_ENABLED == STD_ON)
typedef struct
{
    uint16 DcmDspDDDIDSourceDidIndex;
    /*Converte byte position in request message to bit position*/
    uint16 DcmDspDDDIDDataPositionInSourceDid;
    uint16 DcmDspDataIndex;
    uint8 DcmDspDDDIDMemoryId;
    uint32 DcmDspDDDIDDataMemoryAddress;
    uint32 DcmDspDDDIDDataSize;
} Dcm_DspDDDIDElementInfoType;

typedef struct
{
    uint16 DcmDspDDDIDIndex;
    boolean DcmDspDDDIDDefined;
    uint8 DcmDspDDDIDElementUsedNum;
    Dcm_DspDDDIDElementInfoType *DcmDspDDDIDElementPtr;
} Dcm_DspDDDIDType;
#endif

/*******************************************************************************
* for UDS 31 Service
*******************************************************************************/
#if(DCM_UDS_31_ENABLED == STD_ON)
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncRoutineControlFncDef)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataIn,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataOut,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,/*In&Out parameter*/
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

typedef struct
{
    /*ECUC_Dcm_01119*//*ECUC_Dcm_00838*//*ECUC_Dcm_00847*//*ECUC_Dcm_00850*//*ECUC_Dcm_00841*//*ECUC_Dcm_00844*/
    /*Provide the size of a RoutineControl parameter in bytes*/
    uint16 DcmDspRoutineParameterSize;
    /*ECUC_Dcm_01120*//*ECUC_Dcm_00881*//*ECUC_Dcm_00884*//*ECUC_Dcm_00885*//*ECUC_Dcm_00882*//*ECUC_Dcm_00883*/
    Dcm_DataType DcmDspRoutineSignalType;
} Dcm_DspRoutineSignalType;

/*ECUC_Dcm_01025*/
typedef struct
{
    /*ECUC_Dcm_01028*/
    uint8 DcmDspCommonAuthorizationSupportAddress;
#if(STD_ON == DCM_UDS_27_ENABLED)
    /*ECUC_Dcm_01026*/
    Dcm_SecurityMaskType DcmDspCommonAuthorizationSecurityLevelRef;
#endif
#if(STD_ON == DCM_UDS_29_ENABLED)
    /*ECUC_Dcm_01144*//*ECUC_Dcm_01145*//*ECUC_Dcm_01146*/
    Dcm_AuRoleMaskType DcmDspRequestRoutineRoleRef;
#endif
    /*ECUC_Dcm_01027*/
    Dcm_SessionMaskType DcmDspCommonAuthorizationSessionRef;
} Dcm_DspCommonAuthorizationType;

/*ECUC_Dcm_01021*//*ECUC_Dcm_01022*//*ECUC_Dcm_01023*/
typedef struct
{
    /*ECUC_Dcm_00664*//*ECUC_Dcm_00752*//*ECUC_Dcm_00753*/
    EcucFncRoutineControlFncDef DcmDspRoutineControlFnc;
    /*ECUC_Dcm_01052*//*ECUC_Dcm_01053*//*ECUC_Dcm_01054*/
    const Dcm_DspCommonAuthorizationType *DcmDspRoutineControlCommonAuthorizationRef;
    /*ECUC_Dcm_00834*//*ECUC_Dcm_00845*//*ECUC_Dcm_00832*//*ECUC_Dcm_00839*//*ECUC_Dcm_01116*//*ECUC_Dcm_01117*/
    Dcm_DspRoutineSignalType DcmDspRoutineControlInSignal;
    /*ECUC_Dcm_00835*//*ECUC_Dcm_00848*//*ECUC_Dcm_00833*//*ECUC_Dcm_00842*//*ECUC_Dcm_00831*//*ECUC_Dcm_00836*/
    Dcm_DspRoutineSignalType DcmDspRoutineControlOutSignal;
#if((DCM_CAR_PLATFORM == DCM_GEELY_PLATFORM) || (DCM_CAR_PLATFORM == DCM_MI_PLATFORM))
    uint32 P4ServerMax;
#endif
} Dcm_DspRoutineControlType;

typedef struct
{
    /*ECUC_Dcm_00641*/
    uint16 DcmDspRoutineIdentifier;
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
    /*ECUC_Dcm_00807*/
    boolean DcmDspRoutineUsed;
#endif
    const Dcm_DspRoutineControlType *DcmDspStartRoutine;
    const Dcm_DspRoutineControlType *DcmDspStopRoutine;
    const Dcm_DspRoutineControlType *DcmDspRequestRoutineResults;
} Dcm_DspRoutineIdInfoType;

/*ECUC_Dcm_00640*/
typedef struct
{
    uint16 NumOfRoutineId;
    const Dcm_DspRoutineIdInfoType *DcmDspRoutineIdInfo;
} Dcm_DspRoutineType;
#endif


/*******************************************************************************
* DID definition for UDS 22/2A/2C/2E/2F service
*******************************************************************************/
/*ECUC_Dcm_00713*/
typedef enum
{
    DCM_USE_BLOCK_ID                          = 0,
    DCM_USE_DATA_ASYNCH_CLIENT_SERVER         = 1,
    DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR   = 2,
    DCM_USE_DATA_ASYNCH_FNC                   = 3,
    DCM_USE_DATA_ASYNCH_FNC_ERROR             = 4,
    DCM_USE_DATA_SENDER_RECEIVER              = 5,
    DCM_USE_DATA_SENDER_RECEIVER_AS_SERVICE   = 6,
    DCM_USE_DATA_SYNCH_CLIENT_SERVER          = 7,
    DCM_USE_DATA_SYNCH_FNC                    = 8,
    DCM_USE_ECU_SIGNAL                        = 9
} Dcm_DspDataUsePortType;

#if(STD_ON == DCM_UDS_2F_ENABLED)
/*ECUC_Dcm_01059*/
typedef enum
{
    DCM_CONTROLMASK_EXTERNAL = 0,
    DCM_CONTROLMASK_INTERNAL = 1,
    DCM_CONTROLMASK_NO       = 2
} Dcm_DspDidControlMaskType;

/*ECUC_Dcm_01057*/
typedef struct
{
    /*ECUC_Dcm_01058*/
    uint16 DcmDspDidControlMaskBitPosition;
} Dcm_DspDidControlEnableMaskType;

/*ECUC_Dcm_00619*/
typedef struct
{
    /*ECUC_Dcm_01059*/
    Dcm_DspDidControlMaskType DcmDspDidControlMask;
    /*ECUC_Dcm_01060*//*The value defines the size of the controlEnableMaskRecord in bytes.*/
    /*The scope of this parameter defined in Chapter 10 is 1.. 4294967294, but the data type
    used by the related function in Chapter 8 is uint8. For context, it defines this parameter using uint8.*/
    uint8 DcmDspDidControlMaskSize;
    /*ECUC_Dcm_00624*/
    boolean DcmDspDidFreezeCurrentState;
    /*ECUC_Dcm_00623*/
    boolean DcmDspDidResetToDefault;
    /*ECUC_Dcm_00625*/
    boolean DcmDspDidShortTermAdjustment;
    /*ECUC_Dcm_00923*/
    /*DcmDspDidControlModeRuleRef;*/
    uint8 DcmDspDidControlSupportAddress;
    /*ECUC_Dcm_00620*/
#if(STD_ON == DCM_UDS_27_ENABLED)
    Dcm_SecurityMaskType DcmDspDidControlSecurityLevelRef;
#endif
    /*ECUC_Dcm_01143*/
#if(STD_ON == DCM_UDS_29_ENABLED)
    Dcm_AuRoleMaskType DcmDspDidControlRoleRef;
#endif
    /*ECUC_Dcm_00621*/
    Dcm_SessionMaskType DcmDspDidControlSessionRef;
    /*ECUC_Dcm_01057*/
    uint16 NumOfControlEnableMask;/*0..65535*//*The value is equal to NumOfDidSignal*/
    const Dcm_DspDidControlEnableMaskType *DcmDspDidControlEnableMask;
} Dcm_DspDidControlType;


typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesReturnControlToECUDef)
(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) controlMask,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);

typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesResetToDefaultDef)
(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) controlMask,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);

typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesFreezeCurrentStateDef)
(
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) controlMask,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);

typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesShortTermAdjustmentDef)
(
    P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) ControlStateInfo,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2CONST(uint8, AUTOMATIC, DCM_APPL_DATA) controlMask,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);
#endif/*#if(STD_ON == DCM_UDS_2F_ENABLED)*/


/*ECUC_Dcm_00613*/
typedef struct
{
    /*ECUC_Dcm_00917*/
    /*DcmDspDidReadModeRuleRef;*/
    uint8 DcmDspDidReadSupportAddress;
    /*ECUC_Dcm_00614*/
#if(STD_ON == DCM_UDS_27_ENABLED)
    Dcm_SecurityMaskType DcmDspDidReadSecurityLevelRef;
#endif
    /*ECUC_Dcm_01141*/
#if(STD_ON == DCM_UDS_29_ENABLED)
    Dcm_AuRoleMaskType DcmDspDidReadRoleRef;
#endif
    /*ECUC_Dcm_00615*/
    Dcm_SessionMaskType DcmDspDidReadSessionRef;
} Dcm_DspDidReadType;

#if(STD_ON == DCM_UDS_2E_ENABLED)
/*ECUC_Dcm_00616*/
typedef struct
{
    /*ECUC_Dcm_00922*/
    /*DcmDspDidWriteModeRuleRef;*/
    uint8 DcmDspDidWriteSupportAddress;
    /*ECUC_Dcm_00617*/
#if(STD_ON == DCM_UDS_27_ENABLED)
    Dcm_SecurityMaskType DcmDspDidWriteSecurityLevelRef;
#endif
    /*ECUC_Dcm_01142*/
#if(STD_ON == DCM_UDS_29_ENABLED)
    Dcm_AuRoleMaskType DcmDspDidWriteRoleRef;
#endif
    /*ECUC_Dcm_00618*/
    Dcm_SessionMaskType DcmDspDidWriteSessionRef;
} Dcm_DspDidWriteType;

typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesWriteDataDef)
(
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data,
    uint16 DataLength,
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);
#endif


#if((DCM_UDS_2C_ENABLED == STD_ON) || (DCM_UDS_2F_ENABLED == STD_ON) || (DCM_UDS_22_ENABLED == STD_ON) \
    || (DCM_UDS_2E_ENABLED == STD_ON) || (DCM_UDS_2A_ENABLED == STD_ON))
/*ECUC_Dcm_00607*/
typedef struct
{
#if(DCM_UDS_2C_ENABLED == STD_ON)
    /*ECUC_Dcm_00970*/
    /*Maximum number of source elements of a DDDID.*/
    uint8 DcmDspDDDIDMaxElements;
    /*ECUC_Dcm_00612*/
    boolean DcmDspDidDynamicallyDefined;
    uint16 DcmDspDDDIDBufferIndex;
#endif
#if(DCM_UDS_2F_ENABLED == STD_ON)
    const Dcm_DspDidControlType *DcmDspDidControl;
#endif
#if((DCM_UDS_22_ENABLED == STD_ON) || (DCM_UDS_2A_ENABLED == STD_ON))
    const Dcm_DspDidReadType *DcmDspDidRead;
#endif
#if(DCM_UDS_2E_ENABLED == STD_ON)
    const Dcm_DspDidWriteType *DcmDspDidWrite;
#endif
} Dcm_DspDidInfoType;

#if((DCM_UDS_22_ENABLED == STD_ON) || (DCM_UDS_2A_ENABLED == STD_ON) || (DCM_UDS_2F_ENABLED == STD_ON))
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesConditionCheckReadDef)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);

typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesReadDataDef)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_APPL_DATA) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_APPL_DATA) ErrorCode
);

typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncDataServicesReadDataLengthDef)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint16, AUTOMATIC, DCM_APPL_DATA) DataLength
);
#endif

/*ECUC_Dcm_00869*/
typedef struct
{
    /*ECUC_Dcm_01106*//*Defines the array length in bytes or the the maximum array length for variable datalengths.*/
    uint16 DcmDspDataByteSize;
    /*ECUC_Dcm_00985*/
    Dcm_DataType DcmDspDataType;
    /*ECUC_Dcm_00713*/
    Dcm_DspDataUsePortType DcmDspDataUsePort;
#if((DCM_UDS_22_ENABLED == STD_ON) || (DCM_UDS_2A_ENABLED == STD_ON) || (DCM_UDS_2F_ENABLED == STD_ON))
    /*ECUC_Dcm_00955*/
    boolean DcmDspDataConditionCheckReadFncUsed;
    /*ECUC_Dcm_00677*/
    EcucFncDataServicesConditionCheckReadDef DcmDspDataConditionCheckReadFnc;
    /*ECUC_Dcm_00671*/
    EcucFncDataServicesReadDataLengthDef DcmDspDataReadDataLengthFnc;
    /*ECUC_Dcm_00669*/
    EcucFncDataServicesReadDataDef DcmDspDataReadFnc;
#endif
#if(DCM_UDS_2F_ENABLED == STD_ON)
    /*ECUC_Dcm_00672*/
    EcucFncDataServicesReturnControlToECUDef DcmDspDataReturnControlToECUFnc;
    /*ECUC_Dcm_00673*/
    EcucFncDataServicesResetToDefaultDef DcmDspDataResetToDefaultFnc;
    /*ECUC_Dcm_00674*/
    EcucFncDataServicesFreezeCurrentStateDef DcmDspDataFreezeCurrentStateFnc;
    /*ECUC_Dcm_00675*/
    EcucFncDataServicesShortTermAdjustmentDef DcmDspDataShortTermAdjustmentFnc;
#endif
#if(DCM_UDS_2E_ENABLED == STD_ON)
    /*ECUC_Dcm_00670*/
    EcucFncDataServicesWriteDataDef DcmDspDataWriteFnc;
#endif
#if(DCM_NVM_SUPPORT == STD_ON)
    /*ECUC_Dcm_00809*/
    NvM_BlockIdType DcmDspDataBlockIdRef;
#endif
} Dcm_DspDataTableType;

typedef struct
{
    uint16 NumOfDidData;
    const Dcm_DspDataTableType *DcmDspDataTable;
} Dcm_DspDataType;

/*ECUC_Dcm_00813*/
typedef struct
{
    /*ECUC_Dcm_01105*//*Defines the absolute byte offset of the data defined by
    DcmDspDidDataRef reference to DcmDspData container in the DID.*/
    uint16 DcmDspDidByteOffset;
    /*ECUC_Dcm_00808*/
    uint16 DcmDspDidDataRef;/*Reference to DcmDspData*/
} Dcm_DspDidSignalType;


/*ECUC_Dcm_00601*/
typedef struct
{
    /*ECUC_Dcm_00602*/
    uint16 DcmDspDidIdentifier;
    /*ECUC_Dcm_01099 Length of a DID in byte(s).*/
    uint16 DcmDspDidSize;
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
    /*ECUC_Dcm_00805*/
    boolean DcmDspDidUsed;
#endif
    /*ECUC_Dcm_00604*/
    Dcm_DspDidInfoType DcmDspDidInfoRef;

    uint16 NumOfDidSignal;
    const Dcm_DspDidSignalType *DcmDspDidSignal;
} Dcm_DspDidTableType;

typedef struct
{
    uint16 NumOfDid;
    const Dcm_DspDidTableType *Dcm_DspDidTable;
} Dcm_DspDidType;
#endif


/*******************************************************************************
* OBD type define start
*******************************************************************************/
#if((DCM_OBD_01_ENABLED == STD_ON) || (DCM_OBD_02_ENABLED == STD_ON))

/*ECUC_Dcm_00893*/
typedef enum
{
    DCM_SERVICE_01      = 0U,
    DCM_SERVICE_01_02   = 1U,
    DCM_SERVICE_02      = 2U
} Dcm_DspPidServiceType;

#if(DCM_OBD_01_ENABLED == STD_ON)
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncPidDataReadDef)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data
);
/*ECUC_Dcm_00894*/
typedef struct
{
    /*ECUC_Dcm_01012*/
    Dcm_DataEndiannessType DcmDspPidDataEndianness;
    /*ECUC_Dcm_00629*/
    EcucFncPidDataReadDef DcmDspPidDataReadFnc;
    /*ECUC_Dcm_01018*/
    Dcm_DataType DcmDspPidDataType;
    /*ECUC_Dcm_00720*/
    Dcm_DspDataUsePortType DcmDspPidDataUsePort;
} Dcm_DspPidService01Type;
#endif

#if(DCM_OBD_02_ENABLED == STD_ON)
/*ECUC_Dcm_00895*/
typedef struct
{
    /*ECUC_Dcm_00887*/
    uint8 DcmDspPidDataDemRef;/*Reference to DemPidDataElement in DEM configuration.*/
} Dcm_DspPidService02Type;
#endif

/*ECUC_Dcm_00874*/
typedef struct
{
    /*ECUC_Dcm_00876*/
    uint8 DcmDspPidDataSupportInfoBit;/*Referenced Bit of the SupportInfo. Range:0..255*/
    /*ECUC_Dcm_00875*/
    uint8 DcmDspPidDataSupportInfoRef;/*Reference to DcmDspPidSupportInfo.*/
} Dcm_DspPidDataSupportInfoType;

/*ECUC_Dcm_00865*/
typedef struct
{
    /*ECUC_Dcm_01107*//*Position in bytes of the PID structure. Range:0..255*/
    uint8 DcmDspPidByteOffset;
    /*ECUC_Dcm_01108*//*Defines the array length in bytes or the the maximum array length for variable datalengths. Range:0..255*/
    uint8 DcmDspPidDataByteSize;
    /*ECUC_Dcm_00874*/
    /*const Dcm_DspPidDataSupportInfoType *DcmDspPidDataSupportInfo;*/
#if(DCM_OBD_01_ENABLED == STD_ON)
    /*ECUC_Dcm_00894*/
    const Dcm_DspPidService01Type *DcmDspPidService01;
#endif
#if(DCM_OBD_02_ENABLED == STD_ON)
    /*ECUC_Dcm_00895*/
    /*const Dcm_DspPidService02Type *DcmDspPidService02;*/
#endif
} Dcm_DspPidDataType;

/*ECUC_Dcm_00871*/
typedef struct
{
    /*ECUC_Dcm_00873*/
    uint8 DcmDspPidSupportInfoLen;/*Length of the support information in bytes. Range:0..255*/
    /*ECUC_Dcm_00872*/
    uint8 DcmDspPidSupportInfoPos;/*Position of the support information in bytes. Range:0..255*/
} Dcm_DspPidSupportInfoType;

/*ECUC_Dcm_00626*/
typedef struct
{
    /*ECUC_Dcm_00627*/
    uint8 DcmDspPidIdentifier;/*Range:0..255*/
    /*ECUC_Dcm_00893*/
    Dcm_DspPidServiceType DcmDspPidService;
    /*ECUC_Dcm_00870*/
    uint8 DcmDspPidSize;/*Length of a PID in byte(s). Range:0..255*/
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
    /*ECUC_Dcm_00806*/
    boolean DcmDspPidUsed;
#endif
    /*ECUC_Dcm_00865*/
    uint8 NumOfPidData;/*Range:1..255*/
    const Dcm_DspPidDataType *DcmDspPidData;
    /*ECUC_Dcm_00871*/
    /*uint8 NumOfPidSupportInfo;*//*Range:0..255*/
    /*const Dcm_DspPidSupportInfoType *DcmDspPidSupportInfo;*/
} Dcm_DspPidInfoType;

typedef struct
{
    uint8 NumOfPid;
    const Dcm_DspPidInfoType *Dcm_DspPidTable;
} Dcm_DspPidType;

#endif


#if(DCM_OBD_08_ENABLED == STD_ON)
/*SWS_Dcm_01338*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncTIDRequestControlDef)
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) OutBuffer,
	P2CONST(uint8, AUTOMATIC, DCM_VAR) InBuffer
);

/*ECUC_Dcm_00637*/
typedef struct
{
    /*ECUC_Dcm_00722*/
    uint8 DcmDspRequestControlInBufferSize;/*Number of bytes. Range:0..255*/
    /*ECUC_Dcm_01078 Manufacturer specific value reported to the tester for the record identifiers 0xE000 to OxE1FF. (WWH-OBD use cases).*/
    uint8 DcmDspRequestControlInfoByte;/*Range:0..255*/
    /*ECUC_Dcm_00723*/
    uint8 DcmDspRequestControlOutBufferSize;/*Number of bytes. Range:0..255*/
    /*ECUC_Dcm_00656*/
    uint8 DcmDspRequestControlTestId;/*Test Id for Service 0x08. Range:0..255*/
    /*Function used to control the TID*/
    EcucFncTIDRequestControlDef DcmDspRequestControlFunction;
} Dcm_DspRequestControlInfoType;

typedef struct
{
    uint8 NumOfTid;
    const Dcm_DspRequestControlInfoType *Dcm_DspRequestControlTable;
} Dcm_DspRequestControlType;
#endif


#if(DCM_OBD_09_ENABLED == STD_ON)

/*ECUC_Dcm_00889*//*SWS_Dcm_00688*//*SWS_Dcm_91014*/
typedef P2FUNC(Std_ReturnType, DCM_CODE, EcucFncVehInfoDataReadDef)
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataValueBuffer,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataValueBufferSize
);

/*ECUC_Dcm_00888*/
typedef struct
{
    /*ECUC_Dcm_00891*/
    uint8 DcmDspVehInfoDataOrder;/*Defines the order of the data item in the InfoType.*/
    /*ECUC_Dcm_00889*/
    EcucFncVehInfoDataReadDef DcmDspVehInfoDataReadFnc;
    /*ECUC_Dcm_00890*/
    uint8 DcmDspVehInfoDataSize;/*Size in bytes of the InfoType data item. Range:0..255*/
    /*ECUC_Dcm_00727*/
    boolean DcmDspVehInfoDataUsePort;
} Dcm_DspVehInfoDataType;

/*ECUC_Dcm_00630*/
typedef struct
{
    /*ECUC_Dcm_00631*/
    uint8 DcmDspVehInfoInfoType;/*Value of InfoType. Range:0..255*/
    /*ECUC_Dcm_01051*/
    boolean DcmDspVehInfoNODIProvResp;
    /*ECUC_Dcm_00888*/
    uint8 NumOfVehInfoData;/*Range:1..255*/
    const Dcm_DspVehInfoDataType *DcmDspVehInfoData;
} Dcm_DspVehInfoInfoType;

typedef struct
{
    uint8 NumOfVehInfo;
    const Dcm_DspVehInfoInfoType *Dcm_DspVehInfoTable;
} Dcm_DspVehInfoType;
#endif

/*******************************************************************************
* OBD type define end
*******************************************************************************/
#if(DCM_MULTI_CORE_SUPPORT == STD_ON)
typedef P2FUNC(void, DCM_CODE, Dcm_SlaveMainFunctionType)
(
    void
);
#endif


#if(DCM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_LINKTIME)
typedef struct
{
    /*ECUC_Dcm_00820 Range: 1-100, unit: ms*/
    uint8 DcmTaskTime;

    /*ECUC_Dcm_00691 DcmDslDiagResp*/
    /*ECUC_Dcm_00693 Range: 0-255*/
    uint8 DcmDslDiagRespMaxNumRespPend;
    /*ECUC_Dcm_00914*/
    boolean DcmDslDiagRespOnSecondDeclinedRequest;

    /*ECUC_Dcm_00712 DcmDsp*/
    /*ECUC_Dcm_00987*/
    Dcm_DataEndiannessType DcmDspDataDefaultEndianness;
#if(DCM_UDS_2C_ENABLED == STD_ON)
    /*ECUC_Dcm_00966*/
    boolean DcmDspDDDIDcheckPerSourceDID;
#endif
    /*ECUC_Dcm_01061*/
    boolean DcmDspEnableObdMirror;
#if(DCM_UDS_22_ENABLED == STD_ON)
    /*ECUC_Dcm_00638 Range: 1..65535*/
    uint16 DcmDspMaxDidToRead;
#endif
#if(DCM_UDS_2A_ENABLED == STD_ON)
    /*ECUC_Dcm_00956 Range: 1..65535*/
    uint16 DcmDspMaxPeriodicDidToRead;
    /*ECUC_Dcm_00957*/
    /*ECUC_Dcm_00962 Range: 1..255 Defines the maximum number of periodicDataIdentifiers that can be scheduled concurrently.*/
    uint8 DcmDspMaxPeriodicDidScheduler;
    /*ECUC_Dcm_00960 uint:ms range:1..1000, 0 means the transmission mode not supported*/
    uint16 DcmDspPeriodicTransmissionFastRate;
    /*ECUC_Dcm_00959 uint:ms range:1..1000, 0 means the transmission mode not supported*/
    uint16 DcmDspPeriodicTransmissionMediumRate;
    /*ECUC_Dcm_00958 uint:ms range:1..1000, 0 means the transmission mode not supported*/
    uint16 DcmDspPeriodicTransmissionSlowRate;
#endif
#if(DCM_UDS_11_ENABLED == STD_ON)
    /*ECUC_Dcm_00818 unit:s range:0...254, 255 indicates a failure or time not available.*/
    uint32 DcmDspPowerDownTime;
#endif
#if(DCM_UDS_19_ENABLED == STD_ON)
    /*ECUC_Dcm_01214*/
    boolean DcmDspReadDTCInformationSupportedObdUdsDtcSeparation;
#endif
#if(DCM_UDS_27_ENABLED == STD_ON)
    /*ECUC_Dcm_01101 Range: 0..65535000 ms*/
    uint32 DcmDspSecurityMaxAttemptCounterReadoutTime;
    /*ECUC_Dcm_01210*/
    boolean DcmDspSecurityResetAttemptCounterOnTimeout;
#endif
} Dcm_LConfigType;
#endif


/*SWS_Dcm_00982*/
typedef struct
{
#if(DCM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    /*ECUC_Dcm_01043*/
    boolean DcmDslProtocolRowUsed[DCM_CFG_NUM_OF_PROTOCOL];
    const Dcm_DslConnectionType *DcmDslConnection[DCM_CFG_NUM_OF_PROTOCOL];
    /*ECUC_Dcm_01044*/
    const boolean *DcmDsdServiceUsed[DCM_CFG_NUM_OF_STAB];
    /*ECUC_Dcm_01047*/
    const boolean *DcmDsdSubServiceUsed[DCM_CFG_NUM_OF_STAB];
#if(DCM_UDS_28_ENABLED == STD_ON)
    const Dcm_DspComControlAllChannelType *DcmDspComControlAllChannel[DCM_CFG_NUM_OF_STAB];
    const Dcm_DspComControlSpecificChannelType *DcmDspComControlSpecificChannel[DCM_CFG_NUM_OF_STAB];
    const Dcm_DspComControlSubNodeType *DcmDspComControlSubNode[DCM_CFG_NUM_OF_STAB];
#endif
#if((DCM_UDS_2C_ENABLED == STD_ON) || (DCM_UDS_2F_ENABLED == STD_ON) || (DCM_UDS_22_ENABLED == STD_ON) \
    || (DCM_UDS_2E_ENABLED == STD_ON) || (DCM_UDS_2A_ENABLED == STD_ON))
    /*ECUC_Dcm_00805*/
    const boolean *DcmDspDidUsed[DCM_CFG_NUM_OF_STAB];
#endif
#if(DCM_UDS_31_ENABLED == STD_ON)
    /*ECUC_Dcm_00807*/
    const boolean *DcmDspRoutineUsed[DCM_CFG_NUM_OF_STAB];
#endif
#if((DCM_OBD_01_ENABLED == STD_ON) || (DCM_OBD_02_ENABLED == STD_ON))
    /*ECUC_Dcm_00806*/
    const boolean *DcmDspPidUsed[DCM_CFG_NUM_OF_STAB];
#endif


#else
    uint8 PreventEmpty;
#endif
} Dcm_ConfigType;



#endif/*DCM_TYPES_H*/

