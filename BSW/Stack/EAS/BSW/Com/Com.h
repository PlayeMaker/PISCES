/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name      : Com.h
********************************************************************************
*   Project/Product: AUTOSAR R21-11
*   Title          : Com.h
*   Author         : Hirain
********************************************************************************
*   Description:     Com module head File
*
********************************************************************************
*   Limitations:      None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
*END_FILE_HDR*/

#ifndef COM_H
#define COM_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Bsw_Common.h"

#include "Com_Lcfg.h"

#if(STD_CONFIG_VARIANTS_POSTBUILD == COM_CONFIG_VARIANTS)
#include "Com_PBcfg.h"
#endif

#include "PduR.h"


/*******************************************************************************
*   Macro
*******************************************************************************/
/* Det Error SWS_Com_00804 804 805 837 864*/
#define COM_E_PARAM                    ((uint8)0x01)
#define COM_E_UNINIT                   ((uint8)0x02)
#define COM_E_PARAM_POINTER            ((uint8)0x03)
#define COM_E_INIT_FAILED              ((uint8)0x04)
#define COM_E_SKIP_TRANSMISSION        ((uint8)0x05)
/* Non Autosar Standard */
#define COM_E_SHARED_BUFFER_BUSY       ((uint8)0xFE)
#define COM_E_CALLED_IN_WRONG_CORE     ((uint8)0xFF)

/* API ID*/
#define COMSERVICEID_INIT                                      ((uint8)0x01)
#define COMSERVICEID_DEINIT                                    ((uint8)0x02)
#if (STD_ON == COM_IPDU_GROUP_FUN)
#define COMSERVICEID_IPDU_GROUP_CONTROL                        ((uint8)0x03)
#define COMSERVICEID_RECEPTION_DMCONTROL                       ((uint8)0x06)
#endif

#define COMSERVICEID_GET_STATUS                                ((uint8)0x07)
#define COMSERVICEID_GET_CONFIGURATION_ID                      ((uint8)0x08)
#define COMSERVICEID_GET_VERSION_INFO                          ((uint8)0x09)
#define COMSERVICEID_SEND_SIGNAL                               ((uint8)0x0A)
#define COMSERVICEID_RECEIVE_SIGNAL                            ((uint8)0x0B)
#define COMSERVICEID_UPDATE_SHADOW_SIGNAL                      ((uint8)0x0C)
#define COMSERVICEID_SEND_SIGNAL_GROUP                         ((uint8)0x0D)
#define COMSERVICEID_RECEIVE_SIGNAL_GROUP                      ((uint8)0x0E)
#define COMSERVICEID_RECEIVE_SHADOW_SIGNAL                     ((uint8)0x0F)
#define COMSERVICEID_INVALIDATE_SIGNAL                         ((uint8)0x10)
#define COMSERVICEID_INVALIDATE_SHADOW_SIGNAL                  ((uint8)0x16)
#define COMSERVICEID_TRIGGER_IPDU_SEND                         ((uint8)0x17)
#define COMSERVICEID_MAIN_FUNCTION_RX                          ((uint8)0x18)
#define COMSERVICEID_MAIN_FUNCTION_TX                          ((uint8)0x19)
#define COMSERVICEID_MAIN_FUNCTION_ROUTESIGNALS                ((uint8)0x1A)
#define COMSERVICEID_INVALIDATE_SIGNAL_GROUP                   ((uint8)0x1B)

#define COMSERVICEID_RECEIVE_SIGNAL_GROUP_ARRAY                ((uint8)0x24)
#define COMSERVICEID_SEND_SIGNAL_GROUP_ARRAY                   ((uint8)0x23)

#if (STD_ON == COM_IPDU_GROUP_FUN)
#define COMSERVICEID_CLEAR_IPDU_GROUP_VECTOR                   ((uint8)0x1C)
#define COMSERVICEID_SET_IPDU_GROUP                            ((uint8)0x1D)
#endif
#define COMSERVICEID_TP_RX_INDICATION                          ((uint8)0x1E)
#define COMSERVICEID_SEND_DYNSIGNAL                            ((uint8)0x21)
#define COMSERVICEID_RECEIVE_DYNSIGNAL                         ((uint8)0x22)
#define COMSERVICEID_COPY_RX_DATA                              ((uint8)0x23)
#define COMSERVICEID_COPY_TX_DATA                              ((uint8)0x24)
#define COMSERVICEID_START_OF_RECEPTION                        ((uint8)0x25)
#define COMSERVICEID_TP_TX_CONFIGURATION                       ((uint8)0x26)
#define COMSERVICEID_SWITCH_IPDU_TX_MODE                       ((uint8)0x27)
#define COMSERVICEID_TX_CONFIRMATION                           ((uint8)0x40)
#define COMSERVICEID_TRIGGER_TRANSMIT                          ((uint8)0x41)
#define COMSERVICEID_RX_INDICATION                             ((uint8)0x42)

#if (STD_ON == COM_MetaDataSupport)
#define COMSERVICEID_TRIGGER_IPDU_SEND_WITH_META_DATA          ((uint8)0x28)
#define COMSERVICEID_SEND_SIGNAL_WITH_META_DATA                ((uint8)0x4d)
#define COMSERVICEID_SEND_DYNSIGNAL_WITH_META_DATA             ((uint8)0x4e)
#define COMSERVICEID_SEND_SIGNAL_GROUP_WITH_META_DATA          ((uint8)0x4f)
#define COMSERVICEID_SEND_SIGNAL_GROUP_ARRAY_WITH_META_DATA    ((uint8)0x50)
#define COMSERVICEID_RECEIVE_DYNSIGNAL_WITH_META_DATA          ((uint8)0x4a)
#define COMSERVICEID_RECEIVE_SIGNAL_WITH_META_DATA             ((uint8)0x49)
#define COMSERVICEID_RECEIVE_SIGNAL_GROUP_WITH_META_DATA       ((uint8)0x4b)
#define COMSERVICEID_RECEIVE_SIGNAL_GROUP_ARRAY_WITH_META_DATA ((uint8)0x4c)
#endif

#define COMSERCIVEID_START_GROUP                               ((uint8)0x51)
#define COMSERCIVEID_STOP_GROUP                                ((uint8)0x52)
#define COMSERCIVEID_START_RX_DMGROUP                          ((uint8)0x53)
#define COMSERCIVEID_STOP_RX_DMGROUP                           ((uint8)0x54)

#define COMSERCIVEID_GET_IPDU_GROUP_STATE                      ((uint8)0xF0)
#define COMSERCIVEID_GET_TX_IPDU_STATE                         ((uint8)0xF1)
#define COMSERCIVEID_GET_RX_IPDU_STATE                         ((uint8)0xF2)

/* SWS_Com_00865 */
#define COM_SERVICE_NOT_AVAILABLE                       ((uint8)0x80)
#define COM_BUSY                                        ((uint8)0x81)

#define COM_TIMER_STOP_VAL                              ((uint16)0xFFFF)
#define COM_INVALID_SIG_INDEX                           ((Com_SignalIdType)0xFFFF)


#define COM_SIGNAL_VALID                                ((uint8)0)
#define COM_SIGNAL_INVALID                              ((uint8)1)
#define COM_SIGNAL_NOT_PASS_FILTER                      ((uint8)2)

#define COM_GET_BYTEINX_SHIFT_VALUE                     ((uint16)3)
#define COM_GET_BITPOS_RES_VALUE                        ((uint16)8)


#define COM_EVENT_TX_NONE                               ((uint8)0)
#define COM_EVENT_NOTX_REP                              ((uint8)1)
#define COM_EVENT_TX_ONCE                               ((uint8)2)
#define COM_EVENT_TX_REP                                ((uint8)3)

#if(COM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
#define COM_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "Com_MemMap.h"
extern P2CONST(Com_ConfigType, COM_VAR, COM_CONST) Com_PBConfig;
#define COM_STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "Com_MemMap.h"
#endif

/*******************************************************************************
*   Api
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"


extern FUNC(void, COM_CODE) Com_Init
(
    P2CONST(Com_ConfigType, AUTOMATIC, COM_CONST) ConfigPtr
);

extern FUNC(void, COM_CODE) Com_DeInit
(
    void
);

extern FUNC(Com_StatusType, COM_CODE) Com_GetStatus
(
    void
);

extern FUNC(uint8, COM_CODE) Com_SendSignal
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);
extern FUNC(uint8, COM_CODE) Com_SendDynSignal
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    uint16 Length
);
extern FUNC(uint8, COM_CODE) Com_InvalidateSignal
(
    Com_SignalIdType SignalId
);
extern FUNC(Std_ReturnType, COM_CODE) Com_TriggerIPDUSend
(
    PduIdType PduId
);
extern FUNC(void, COM_CODE) Com_SwitchIpduTxMode
(
    PduIdType PduId,
    boolean Mode
);

extern FUNC(uint8, COM_CODE) Com_ReceiveSignal
(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
);

extern FUNC(uint8, COM_CODE) Com_ReceiveDynSignal
(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    P2VAR(uint16, AUTOMATIC, COM_APPL_DATA) Length
);

extern FUNC(void, COM_CODE) Com_MainFunctionRx
(
#if(COM_RX_MULTI_MAINFUNCTION_ENABLE == STD_ON)
    uint8 CycleIndex
#else
    void
#endif
);

extern FUNC(void, COM_CODE) Com_MainFunctionTx
(
#if(COM_TX_MULTI_MAINFUNCTION_ENABLE == STD_ON)
    uint8 CycleIndex
#else
    void
#endif
);


#if(STD_ON == COM_IPDU_GROUP_FUN)
extern FUNC(void, COM_CODE) Com_IpduGroupControl
(
    Com_IpduGroupVector ipduGroupVector,
    boolean Initialize
);


extern FUNC(void, COM_CODE) Com_ClearIpduGroupVector
(
    Com_IpduGroupVector ipduGroupVector
);
extern FUNC(void, COM_CODE) Com_SetIpduGroup
(
    Com_IpduGroupVector ipduGroupVector,
    Com_IpduGroupIdType ipduGroupId,
    boolean bitval
);

#endif


#if(STD_ON == COM_PUBLIC_VERSION_INFO_API)
extern FUNC(void, COM_CODE) Com_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, COM_APPL_DATA) VersionInfo
);
#endif




#if (STD_ON == COM_IPDU_GROUP_FUN)

extern FUNC(boolean, COM_CODE) Com_GetIpduGroupState
(
    Com_IpduGroupIdType IpduGroupId
);

#if (STD_ON == COM_GROUP_API_R3_SUPPORT)
extern FUNC(void, COM_CODE) Com_IpduGroupStart
(
    Com_IpduGroupIdType IpduGroupId,
    boolean Initialize
);

extern FUNC(void, COM_CODE) Com_IpduGroupStop
(
    Com_IpduGroupIdType IpduGroupId
);

#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
extern FUNC(void, COM_CODE) Com_EnableReceptionDM
(
    Com_IpduGroupIdType IpduGroupId
);
extern FUNC(void, COM_CODE) Com_DisableReceptionDM
(
    Com_IpduGroupIdType IpduGroupId
);
#endif
#endif
#endif


extern FUNC(uint8, COM_CODE) Com_SendSignalGroup
(
    Com_SignalGroupIdType SignalGroupId
);

extern FUNC(uint8, COM_CODE) Com_InvalidateSignalGroup
(
    Com_SignalGroupIdType SignalGroupId
);

#if((STD_ON == COM_Enable_SignalGroupArrayApi) && (STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT))
extern FUNC(uint8, COM_CODE) Com_SendSignalGroupArray
(
    Com_SignalGroupIdType SignalGroupId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)  SignalGroupArrayPtr
);
#endif


extern FUNC(uint8, COM_CODE) Com_ReceiveSignalGroup
(
    Com_SignalGroupIdType SignalGroupId
);


#if((STD_ON == COM_Enable_SignalGroupArrayApi) && (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT))
extern FUNC(uint8, COM_CODE) Com_ReceiveSignalGroupArray
(
    Com_SignalGroupIdType SignalGroupId,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA)  SignalGroupArrayPtr
);
#endif

#if(STD_ON == COM_TXPDU_FUN)
extern FUNC(uint8, COM_CODE) Com_WriteSignal_Internal
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    PduLengthType length
);
#endif

#if(STD_ON == COM_TXPDU_FUN)
extern FUNC(boolean, COM_CODE) Com_GetTxIpduState
(
     PduIdType TxPduId
);
#endif

#if(STD_ON == COM_RXPDU_FUN)
extern FUNC(Std_ReturnType, COM_CODE) Com_GetRxIpduState
(
    PduIdType RxPduId,
    P2VAR(boolean, AUTOMATIC, COM_APPL_DATA) IsRxPduStart
);
#endif

#if (STD_ON == COM_MetaDataSupport)
extern FUNC(Std_ReturnType, COM_CODE) Com_TriggerIPDUSendWithMetaData
(
    PduIdType PduId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) MetaData
);

extern FUNC(uint8, COM_CODE) Com_SendSignalWithMetaData
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) MetaDataPtr
);

extern FUNC(uint8, COM_CODE) Com_SendDynSignalWithMetaData
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    uint16 Length,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) MetaDataPtr
);

extern FUNC(uint8, COM_CODE) Com_SendSignalGroupWithMetaData
(
    Com_SignalGroupIdType SignalGroupId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) MetaDataPtr
);

#if((STD_ON == COM_Enable_SignalGroupArrayApi) && (STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT))
extern FUNC(uint8, COM_CODE) Com_SendSignalGroupArrayWithMetaData
(
    Com_SignalGroupIdType SignalGroupId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) SignalGroupArrayPtr,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) MetaDataPtr
);
#endif

extern FUNC(uint8, COM_CODE) Com_ReceiveDynSignalWithMetaData
(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    P2VAR(uint16, AUTOMATIC, COM_APPL_DATA) Length,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA)  MetaDataPtr
);

extern FUNC(uint8, COM_CODE) Com_ReceiveSignalWithMetaData
(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA)  MetaDataPtr
);

extern FUNC(uint8, COM_CODE) Com_ReceiveSignalGroupWithMetaData 
(
    Com_SignalGroupIdType SignalGroupId,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA)  MetaDataPtr
);

#if((STD_ON == COM_Enable_SignalGroupArrayApi) && (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT))
extern FUNC(uint8, COM_CODE) Com_ReceiveSignalGroupArrayWithMetaData
(
    Com_SignalGroupIdType SignalGroupId,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA)  SignalGroupArrayPtr,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA)  MetaDataPtr
);
#endif
#endif/*(STD_ON == COM_MetaDataSupport)*/

extern FUNC(sint64, COM_CODE) Com_BusValueToPhyValue_64
(
    uint64 value,
    uint8 lastbit
);
extern FUNC(sint32, COM_CODE) Com_BusValueToPhyValue_32
(
    uint32 value,
    uint8 lastbit
);
extern FUNC(sint16, COM_CODE) Com_BusValueToPhyValue_16
(
    uint16 value,
    uint8 lastbit
);
extern FUNC(sint8, COM_CODE) Com_BusValueToPhyValue_8
(
    uint8 value,
    uint8 lastbit
);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"


#endif/*#ifndef _COM_H_*/
