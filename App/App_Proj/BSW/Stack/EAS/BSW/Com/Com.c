/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name:       Com.c
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title:          : Com module Source File
*   Author:         : Hirain
********************************************************************************
*   Description:      Implementation of Com provided functionality
*
********************************************************************************
*   Limitations:      None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version    Date        Initials         CR#        Descriptions
*   --------   ----------  -------------    -------    -------------------
*   04.00.00   17/05/2022  Ziyi.Zhao        N/A        Original
*   04.00.01   14/08/2023  Keyu.Wu          N/A        EASR21-11_COM_20230814_01
*   04.00.02   03/06/2024  Keyu.Wu          N/A        EASR21-11_COM_20240603_01
*   04.01.00   02/08/2024  Keyu.Wu          N/A        EASR21-11_COM_20240802_01
*   04.01.01   09/08/2024  Keyu.Wu          N/A        EASR21-11_COM_20240809_01
********************************************************************************
*END_FILE_HDR*/

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 5087,3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "EcuM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in EcuM_MemMap.h
*/

/*PRQA S 3453,3429 EOF*/
/*
1.The unified requirement of EAS is that the error reporting functions of Det
and Dem moduls are accessed by macro functions.This part has been verified and
has no problem.
2.Macro functions are allowed to use to access parameters and do some simple operations.
*/

/*PRQA S 3432,3410,3409 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no
need to revise.
*/

/*PRQA S 3673,4603 EOF*/
/*
Parameters in AUTOSAR standard APIs,they may not follow this rule.
*/

/*PRQA S 3212 EOF*/
/*
Unified requirements of EAS: constant shall be converted.
*/

/*PRQA S 3119 EOF*/
/*
No unified input parameter processing is used
*/

/*PRQA S 3197 EOF*/
/*
Redundant initialization will not cause functional problems,there is no need to
revise.And it is the requirement of programming specification to initialize
local variables.
*/

/*PRQA S 3138,3141 EOF*/
/*
The code of critical segments can be configured as void when QAC testing.
Note:When called by Det,Dem or BswM, the critical segments must be enabled when
QAC testing.Reasons are needed for special circumstances not enabled.
*/

/*PRQA S 3416 EOF*/
/*
In a If statement,calling a function to directly determine the return value is 
allowed if there is only one judge branch.
*/

/*PRQA S 0857,0380 EOF*/
/*
Macro definitions exceed 1024. The number of macros is unlimited
*/

/*****************************************************************************
 *  Com QAC Suppression
 *****************************************************************************/

/*PRQA S 3227,3204 EOF*/
/*
Read-only function input parameters may not be defined as const,it does not affect the function.
AUTOSAR API shall define standard input parameters according to specification requirements
*/

/*PRQA S 2100,2101 EOF*/
/*
Integer promotion related
*/

/*PRQA S 2000 EOF*/
/*
When there is only one If,there can be no else.
*/

/*PRQA S 3206,3220 EOF*/
/*
Particularity of configuration files
*/

/*PRQA S 316,315 EOF*/
/*
Allows the void pointer type to be converted into other pointer types.
*/

/*******************************************************************************
*    Includes
*******************************************************************************/
#include "SchM_Com.h"
#include "Com.h"
#include "Com_Cbk.h"
#include "Com_Data.h"
#if(STD_ON == COM_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#if(STD_ON == COM_MetaDataSupport)
#include "Ecuc.h"
#endif
#if((STD_ON == COM_TX_CONFIRMATION_CALLOUT_SUPPORT) || (STD_ON == COM_RX_INDICATION_CALLOUT_SUPPORT) || (STD_ON == COM_TX_E2E_TRIGGER_CALLOUT_SUPPORT))
#include "E2EPW_Pro.h"
#endif

#if(STD_ON == COM_DEM_EVENT_SET_SUPPORT)
#include "Dem.h"
#endif

/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(STD_ON == COM_VERSION_CHECK)
/* check Version with cfg file */
#if ((COM_AR_RELEASE_MAJOR_VERSION != COM_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (COM_AR_RELEASE_MINOR_VERSION != COM_AR_RELEASE_MINOR_VERSION_CFG))

#error "AutoSar Version Numbers of Com and its cfg file are different"
#endif

#if ((COM_SW_MAJOR_VERSION != COM_SW_MAJOR_VERSION_CFG) || \
   (COM_SW_MINOR_VERSION != COM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of Com and its cfg file are different"
#endif
#endif

/*******************************************************************************
*   Private Data
*******************************************************************************/
#define COM_START_SEC_VAR_INIT_GLOBAL_8
#include "Com_MemMap.h"
STATIC VAR(Com_StatusType, COM_VAR) Com_InitStateFlag = COM_UNINIT;
#define COM_STOP_SEC_VAR_INIT_GLOBAL_8
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_INIT_GLOBAL_8
#include "Com_MemMap.h"
STATIC VAR(boolean, COM_VAR) Com_TxSigIsSameValue[COM_TXSIG_MAX_NUM];
#define COM_STOP_SEC_VAR_INIT_GLOBAL_8
#include "Com_MemMap.h"

#if(COM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
#define COM_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "Com_MemMap.h"
P2CONST(Com_ConfigType, COM_VAR, COM_CONST) Com_PBConfig;
#define COM_STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "Com_MemMap.h"
#endif

/*******************************************************************************
*   Macro Core
*******************************************************************************/
#if(STD_ON == COM_MULTI_CORE_SUPPORT)

#if(STD_ON == COM_TXPDU_FUN)
#define COM_CFG_CORE_TXPDU_NUM(CoreId)              (COM_CFG_CORE_INFO[CoreId].CoreTxPduNum)
#define COM_CFG_CORE_TXPDU_TABLE(CoreId)            (COM_CFG_CORE_INFO[CoreId].CoreTxPduTable)
#endif
#if(STD_ON == COM_RXPDU_FUN)
#define COM_CFG_CORE_RXPDU_NUM(CoreId)              (COM_CFG_CORE_INFO[CoreId].CoreRxPduNum)
#define COM_CFG_CORE_RXPDU_TABLE(CoreId)            (COM_CFG_CORE_INFO[CoreId].CoreRxPduTable)
#endif

#endif

/*******************************************************************************
*   Macro Tx
*******************************************************************************/
/* tx Pdu reg access  */
#define COM_TXPDU_TMS_FLAG(TxIpduId)             (Com_TxPduTable[TxIpduId].IpduTMSFlag)
#define COM_TXPDU_PERIOD(TxIpduId)               (Com_TxPduTable[TxIpduId].TxModeTimePeriod)
#define COM_TXPDU_TXTIME_OFFSET(TxIpduId)        (Com_TxPduTable[TxIpduId].TxModeTimeOffset)
#define COM_TXPDU_MIN_DELAY_TIMER(TxIpduId)      (Com_TxPduTable[TxIpduId].MininumDelayTimer)
#define COM_TXPDU_REP_NUM(TxIpduId)              (Com_TxPduTable[TxIpduId].TxModeNumOfRep)
#define COM_TXPDU_PERIOD_BACKUP(TxIpduId)        (Com_TxPduTable[TxIpduId].TimePeriodBackUp)
#define COM_TXPDU_TIMEOUT(TxIpduId)              (Com_TxPduTable[TxIpduId].TxIpduTimeOut)
#define COM_TXPDU_TXMODE_PTR(TxIpduId)           (Com_TxPduTable[TxIpduId].TxModeSelectPtr)
#define COM_TXPDU_DYN_LENGTH(TxIpduId)           (Com_TxPduTable[TxIpduId].TxDynLength)
#define COM_TXPDU_REQ_CONF_NUM(TxIpduId)         (Com_TxPduTable[TxIpduId].TxConfNumOfRep)
#define COM_TXPDU_TX_REQ_MINDELAY_BACKUP(TxIpduId)  (Com_TxPduTable[TxIpduId].txMinDelayReqBackUp)
#define COM_TXPDU_TP_INDEX(TxIpduId)                (Com_TxPduTable[TxIpduId].tpPduIndex)
#if (STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
#define COM_TXPDU_IFACTIVE_FLAG(TxIpduId)                (Com_TxPduTable[TxIpduId].txActiveFlag)
#define COM_TXPDU_IFACTIVE_CHANGE_FLAG(TxIpduId)         (Com_TxPduTable[TxIpduId].txActiveChangeFlag)
#endif

#define COM_TXPDU_TXMODE(TxIpduId)               (Com_TxPduTable[TxIpduId].TxModeSelectPtr->TxModeMode)
#define COM_TXPDU_TXMODE_PERIOD(TxIpduId)        (Com_TxPduTable[TxIpduId].TxModeSelectPtr->TxModeTimePeriod)
#define COM_TXPDU_TXMODE_REP_NUM(TxIpduId)       (Com_TxPduTable[TxIpduId].TxModeSelectPtr->TxModeNumberOfRepetitions)
#define COM_TXPDU_TXMOD_REP_PERIOD(TxIpduId)     (Com_TxPduTable[TxIpduId].TxModeSelectPtr->TxModeRepetitionPeriod)
/*#define COM_TXPDU_TXMOD_TXTIME_OFFSET(TxIpduId)  (Com_TxPduTable[TxIpduId].TxModeSelectPtr->TxModeTimeOffset)not used in this version*/


/* tx Pdu cfg access  */
#if(STD_ON == COM_TX_IMMEDIATE_SUPPORT)
#define COM_CFG_TXPDU_IS_IMM_PROCESSING(TxIpduId)    (COM_CFG_TXPDU_INFO[TxIpduId].isImmProcess)
#endif
#define COM_CFG_TXPDU_SIG_START_NUM(TxIpduId)        (COM_CFG_TXPDU_INFO[TxIpduId].SignalStartNum)
#define COM_CFG_TXPDU_SIG_STOP_NUM(TxIpduId)         (COM_CFG_TXPDU_INFO[TxIpduId].SignalStopNum)
#define COM_CFG_TXPDU_MIN_DELAY_TIMER(TxIpduId)      (COM_CFG_TXPDU_INFO[TxIpduId].MinimumDelayTime)
#define COM_CFG_TXPDU_PERIOD_TIMEOUT(TxIpduId)       (COM_CFG_TXPDU_INFO[TxIpduId].PeriodTimeOut)
#define COM_CFG_TXPDU_TIMEOUT_MONITOR_FLAG(TxIpduId) (COM_CFG_TXPDU_INFO[TxIpduId].TimeOutMonitorFlag)
#define COM_CFG_TXPDUGROUP_FLAG(TxIpduId)            (COM_CFG_TXPDU_INFO[TxIpduId].TxIPDUGroupFlag)
#define COM_CFG_TXPDU_MAP_PDUR(TxIpduId)             (COM_CFG_TXPDU_INFO[TxIpduId].IpduMapPdur)
#define COM_CFG_TXPDU_FILTER_SIZE(TxIpduId)          (COM_CFG_TXPDU_INFO[TxIpduId].FilterByteNum)
#define COM_CFG_TXPDU_FILTER_PTR(TxIpduId)           (COM_CFG_TXPDU_INFO[TxIpduId].TMCFilterFlagPtr)
#define COM_CFG_TXPDU_DATA_PTR(TxIpduId)             (COM_CFG_TXPDU_INFO[TxIpduId].SduDataPtr)
#define COM_CFG_TXPDU_LENGTH(TxIpduId)               (COM_CFG_TXPDU_INFO[TxIpduId].SduLength)
#define COM_CFG_TXPDU_TXMODE_TRUE_PTR(TxIpduId)      (COM_CFG_TXPDU_INFO[TxIpduId].TxModeTrueCfgTablePtr)
#define COM_CFG_TXPDU_TXMODE_FALSE_PTR(TxIpduId)     (COM_CFG_TXPDU_INFO[TxIpduId].TxModeFalseCfgTablePtr)
#define COM_CFG_TXPDU_IS_DYN(TxIpduId)               (COM_CFG_TXPDU_INFO[TxIpduId].isTxDynPdu)
#if(STD_ON == COM_TX_LONG_PDU_FUN)
#define COM_CFG_TXPDU_IS_TP_PDU(TxIpduId)            (COM_CFG_TXPDU_INFO[TxIpduId].isTpPdu)
#endif
#define COM_CFG_TXPDU_CALLOUT(TxIpduId)              (COM_CFG_TXPDU_INFO[TxIpduId].Callout)
#define COM_CFG_TXPDU_CANCEL_TRANSMIT_FLAG(TxIpduId) (COM_CFG_TXPDU_INFO[TxIpduId].TxCancelTransmitSupportFlag)
#define COM_CFG_TXPDU_TRIGGER_CALLOUT(TxIpduId)      (COM_CFG_TXPDU_INFO[TxIpduId].TxTriggerCallout)
#define COM_CFG_TXPDU_UPDATEBIT_INFO(TxIpduId)       (COM_CFG_TXPDU_INFO[TxIpduId].updateBitInfo)
#define COM_CFG_TXPDU_UPDATEBIT_NUM(TxIpduId)        (COM_CFG_TXPDU_INFO[TxIpduId].updateBitNum)
#define COM_CFG_TXPDU_UPDATEBIT_CLEARTYPE(TxIpduId)  (COM_CFG_TXPDU_INFO[TxIpduId].cubType)
#define COM_CFG_TXPDU_UNUSED_BYTE(TxIpduId)          (COM_CFG_TXPDU_INFO[TxIpduId].unusedAreaByte)
/*#define COM_CFG_TX_TRUE_MODE(TxIpduId)               (COM_CFG_TXPDU_TXMODE_TRUE_PTR(TxIpduId)->TxModeMode) not used in this version*/
/*#define COM_CFG_TX_FALSE_MODE(TxIpduId)              (COM_CFG_TXPDU_TXMODE_FALSE_PTR(TxIpduId)->TxModeMode) not used in this version*/
#if(STD_ON == COM_MetaDataSupport)
#define COM_CFG_TXPDU_GLOBAL_PDUID(TxIpduId)         (COM_CFG_TXPDU_INFO[TxIpduId].GlobalPduId)
#define COM_CFG_TXPDU_METADATA_DEFAULT_PTR(TxIpduId) (COM_CFG_TXPDU_INFO[TxIpduId].MetaDataDefaultPtr)
#endif
#define COM_CFG_TXPDU_IN_PDUGRP_NUM(TxIpduId)        (COM_CFG_TXPDU_INFO[TxIpduId].numOfPduGrp)
#define COM_CFG_TXPDU_IN_PDUGRP_PTR(TxIpduId)        (COM_CFG_TXPDU_INFO[TxIpduId].PduGrpPtr)
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
#define COM_CFG_TXPDU_CORE_ID(TxIpduId)              (COM_CFG_TXPDU_INFO[TxIpduId].CoreId)
#endif
#if (STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
#define COM_CFG_TXPDU_IS_INACTIVE_CYCLIC(TxIpduId)    (COM_CFG_TXPDU_INFO[TxIpduId].IsInActiveCyclic)
#endif

/* tx signal cfg access  */
#define COM_CFG_TXSIG_TXPDU_ID(TxSigId)             (COM_CFG_TXSIG_INFO[TxSigId].TxPduId)
#define COM_CFG_TXSIG_SHARE_BUF_PTR(TxSigId)        (COM_CFG_TXSIG_INFO[TxSigId].TxSigShareBufPtr)
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
#define COM_CFG_TXSIG_SHARE_FLAG_PTR(TxSigId)       (COM_CFG_TXSIG_INFO[TxSigId].TxSigShareFlagPtr)
#endif
#define COM_CFG_TXSIG_TRANSPROPERTY(TxSigId)        (COM_CFG_TXSIG_INFO[TxSigId].SigTransferProperty)
#define COM_CFG_TXSIG_TYPE(TxSigId)                 (COM_CFG_TXSIG_INFO[TxSigId].SigType)
#define COM_CFG_TXSIG_LENGTH(TxSigId)               (COM_CFG_TXSIG_INFO[TxSigId].SigLen)
#define COM_CFG_TXSIG_ENDIANNESS(TxSigId)           (COM_CFG_TXSIG_INFO[TxSigId].Endianness)
#define COM_CFG_TXSIG_BIT_SIZE(TxSigId)             (COM_CFG_TXSIG_INFO[TxSigId].BitSize)
#define COM_CFG_TXSIG_START_BIT(TxSigId)            (COM_CFG_TXSIG_INFO[TxSigId].StartBit)
#define COM_CFG_TXSIG_MASK_LSB(TxSigId)             (COM_CFG_TXSIG_INFO[TxSigId].MaskLsb)
#define COM_CFG_TXSIG_MASK_MSB(TxSigId)             (COM_CFG_TXSIG_INFO[TxSigId].MaskMsb)
#define COM_CFG_TXSIG_START_BYTE_INDEX(TxSigId)     (COM_CFG_TXSIG_INFO[TxSigId].SigStartByteIndex)
#define COM_CFG_TXSIG_INIT_VALUE_PTR(TxSigId)       (COM_CFG_TXSIG_INFO[TxSigId].InitValPtr)
#define COM_CFG_TXSIG_INIT_VALUE_LEN(TxSigId)       (COM_CFG_TXSIG_INFO[TxSigId].InitLen)
#define COM_CFG_TXSIG_INVALID_VALUE_PTR(TxSigId)    (COM_CFG_TXSIG_INFO[TxSigId].InvalidValPtr)
#define COM_CFG_TXSIG_INVALID_VALUE_LEN(TxSigId)    (COM_CFG_TXSIG_INFO[TxSigId].InvalidLen)
#define COM_CFG_TXSIG_IS_GROUP_SIGNAL(TxSigId)      (COM_CFG_TXSIG_INFO[TxSigId].isGroupSignal)
#define COM_CFG_TXSIG_GET_SIGGROUPID(TxSigId)       (COM_CFG_TXSIG_INFO[TxSigId].groupId)
#define COM_CFG_TXSIG_GROUP_TEMPLENGTH_PTR(TxSigId) (COM_CFG_TXSIG_INFO[TxSigId].GroupDynSigLengthBuf)
#define COM_CFG_TXSIG_UPDATEBIT_INDEX(TxSigId)      (COM_CFG_TXSIG_INFO[TxSigId].updateBitIndex)
#if(COM_TX_FILTER_SUPPORT == STD_ON)
#define COM_CFG_TXSIG_FILTER_PTR(TxSigId)           (COM_CFG_TXSIG_INFO[TxSigId].TxSigFilter)
#endif
#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
#define COM_CFG_TXSIG_INACTIVE_VALUE_PTR(TxSigId)    (COM_CFG_TXSIG_INFO[TxSigId].InActiveValPtr)
#define COM_CFG_TXSIG_INACTIVE_OFFSET(TxSigId)    (COM_CFG_TXSIG_INFO[TxSigId].txActiveFlagOffset)
#endif
#define COM_CFG_TXSIG_TXTOINDICATION_FUN(TxSigId)   (COM_CFG_TXSIG_INFO[TxSigId].SigTxTOIndicationFun)
#define COM_CFG_TXSIG_CBKTXACK_FUN(TxSigId)         (COM_CFG_TXSIG_INFO[TxSigId].SigCbkTxAckFun)
#define COM_CFG_TXSIG_TXERR_FUN(TxSigId)            (COM_CFG_TXSIG_INFO[TxSigId].CbkTxErrFun)



/*******************************************************************************
*   Macro Rx
*******************************************************************************/
/* rx Pdu reg access  */
#define COM_RXPDU_TP_INDEX(RxIpduId)          (Com_RxPduTable[RxIpduId].tpPduIndex)
#define COM_RXPDU_TIMEOUT(RxIpduId)           (Com_RxPduTable[RxIpduId].RxPeriodTimeOut)
#define COM_RXPDU_MONITOR_FLAG(RxIpduId)      (Com_RxPduTable[RxIpduId].RxIpduTimeoutMonitorFlag)
#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)
#define COM_RXPDU_DYN_LENGTH(RxIpduId)        (Com_RxPduTable[RxIpduId].dynLength)
#endif
#define COM_RXPDU_TEMP_LENGTH(RxIpduId)       (Com_RxPduTable[RxIpduId].tempLength)


/* rx Pdu cfg access  */
#if(STD_ON == COM_RX_IMMEDIATE_SUPPORT)
#define COM_CFG_RXPDU_IS_IMM_PROCESSING(RxIpduId)   (COM_CFG_RXPDU_INFO[RxIpduId].isImmProcess)
#endif
#define COM_CFG_RXPDU_SIG_STOP_NUM(RxIpduId)        (COM_CFG_RXPDU_INFO[RxIpduId].SignalStopNum)
#define COM_CFG_RXPDU_SIG_START_NUM(RxIpduId)       (COM_CFG_RXPDU_INFO[RxIpduId].SignalStartNum)
#if (STD_ON == COM_RX_TIMEOUT_MONITOR)
#define COM_CFG_RXPDU_PERIOD_TIMEOUT(RxIpduId)      (COM_CFG_RXPDU_INFO[RxIpduId].RxPeriodTimeOut)
#define COM_CFG_RXPDU_FIRST_TIMEOUT(RxIpduId)       (COM_CFG_RXPDU_INFO[RxIpduId].RxFirstTimeOut)
#define COM_CFG_RXPDU_MONITOR_FLAG(RxIpduId)        (COM_CFG_RXPDU_INFO[RxIpduId].RxIpduTimeoutMonitorFlag)
#if (STD_ON == COM_RX_TIMEOUT_PDU_CBK_SUPPORT)
#define COM_CFG_RXPDU_CBKRXTOUT_FUN(RxIpduId)       (COM_CFG_RXPDU_INFO[RxIpduId].RxPduCbkRxTOutFun)
#endif
#endif
#define COM_CFG_RXPDU_DATA_PTR(RxIpduId)            (COM_CFG_RXPDU_INFO[RxIpduId].SduDataPtr)
#define COM_CFG_RXPDU_LENGTH(RxIpduId)              (COM_CFG_RXPDU_INFO[RxIpduId].SduLength)
#define COM_CFG_RXPDUGROUP_FLAG(RxIpduId)           (COM_CFG_RXPDU_INFO[RxIpduId].RxIPDUGroupFlag)
#if(STD_ON == COM_RX_LONG_PDU_FUN)
#define COM_CFG_RXPDU_IS_TP_PDU(RxIpduId)           (COM_CFG_RXPDU_INFO[RxIpduId].isTpPdu)
#endif
#define COM_CFG_RXPDU_CALLOUT(RxIpduId)             (COM_CFG_RXPDU_INFO[RxIpduId].Callout)
#define COM_CFG_RXPDU_IS_DYN(RxIpduId)              (COM_CFG_RXPDU_INFO[RxIpduId].isRxDynPdu)
#define COM_CFG_RXPDU_FIX_LENGTH(RxIpduId)          (COM_CFG_RXPDU_INFO[RxIpduId].RxPduFixLength)
#define COM_CFG_RXPDU_IS_DIRECT_COPY(RxIpduId)      (COM_CFG_RXPDU_INFO[RxIpduId].RxIsDirectCopy)
#define COM_CFG_RXPDU_UPDATEBIT_INFO(RxIpduId)      (COM_CFG_RXPDU_INFO[RxIpduId].updateBitInfo)
#define COM_CFG_RXPDU_UPDATEBIT_NUM(RxIpduId)       (COM_CFG_RXPDU_INFO[RxIpduId].updateBitNum)
#if(STD_ON == COM_MetaDataSupport)
#define COM_CFG_RXPDU_GLOBAL_PDUID(RxIpduId)        (COM_CFG_RXPDU_INFO[RxIpduId].GlobalPduId)
#endif
#define COM_CFG_RXPDU_IN_PDUGRP_NUM(RxIpduId)       (COM_CFG_RXPDU_INFO[RxIpduId].numOfPduGrp)
#define COM_CFG_RXPDU_IN_PDUGRP_PTR(RxIpduId)       (COM_CFG_RXPDU_INFO[RxIpduId].PduGrpPtr)
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
#define COM_CFG_RXPDU_CORE_ID(RxIpduId)             (COM_CFG_RXPDU_INFO[RxIpduId].CoreId)
#endif


/* rx sig cfg access  */
#define COM_CFG_RXSIG_RXPDU_ID(RxSigId)            (COM_CFG_RXSIG_INFO[RxSigId].RxPduId)
#define COM_CFG_RXSIG_DATA_PTR(RxSigId)            (COM_CFG_RXSIG_INFO[RxSigId].RxSigShareBufPtr)
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
#define COM_CFG_RXSIG_LOCK_INDEX(RxSigId)          (COM_CFG_RXSIG_INFO[RxSigId].RxSigLockIndex)
#endif
#define COM_CFG_RXSIG_TYPE(RxSigId)                (COM_CFG_RXSIG_INFO[RxSigId].SigType)
#define COM_CFG_RXSIG_LENGTH(RxSigId)              (COM_CFG_RXSIG_INFO[RxSigId].SigLen)
#define COM_CFG_RXSIG_ENDIANNESS(RxSigId)          (COM_CFG_RXSIG_INFO[RxSigId].Endianness)
#define COM_CFG_RXSIG_BIT_SIZE(RxSigId)            (COM_CFG_RXSIG_INFO[RxSigId].BitSize)
#define COM_CFG_RXSIG_START_BIT(RxSigId)           (COM_CFG_RXSIG_INFO[RxSigId].StartBit)
#define COM_CFG_RXSIG_MASK(RxSigId)                (COM_CFG_RXSIG_INFO[RxSigId].Mask)
#define COM_CFG_RXSIG_START_BYTE_INDEX(RxSigId)    (COM_CFG_RXSIG_INFO[RxSigId].SigStartByteIndex)
#define COM_CFG_RXSIG_INIT_VALUE_PTR(RxSigId)      (COM_CFG_RXSIG_INFO[RxSigId].InitValPtr)
#define COM_CFG_RXSIG_INIT_VALUE_LEN(RxSigId)      (COM_CFG_RXSIG_INFO[RxSigId].InitLen)
#define COM_CFG_RXSIG_SUB_VALUE_PTR(RxSigId)       (COM_CFG_RXSIG_INFO[RxSigId].SubValPtr)
#define COM_CFG_RXSIG_SUB_VALUE_LEN(RxSigId)       (COM_CFG_RXSIG_INFO[RxSigId].SubLen)
#define COM_CFG_RXSIG_INVALID_ACTION(RxSigId)      (COM_CFG_RXSIG_INFO[RxSigId].DataInvalidAction)
#define COM_CFG_RXSIG_INVALID_VALUE_PTR(RxSigId)   (COM_CFG_RXSIG_INFO[RxSigId].InvalidValPtr)
/*#define COM_CFG_RXSIG_INVALID_VALUE_LEN(RxSigId)   (COM_CFG_RXSIG_INFO[RxSigId].InvalidLen) not used in this version*/
#define COM_CFG_RXSIG_GW_INDEX(RxSigId)            (COM_CFG_RXSIG_INFO[RxSigId].GwSigIndex)
#if(COM_RX_FILTER_SUPPORT == STD_ON)
#define COM_CFG_RXSIG_FILTER_PTR(RxSigId)          (COM_CFG_RXSIG_INFO[RxSigId].RxSigFilter)
#endif
#define COM_CFG_RXSIG_UPDATEBIT_INDEX(RxSigId)     (COM_CFG_RXSIG_INFO[RxSigId].updateBitIndex)
#define COM_CFG_RXSIG_UPTO_PERIOD(RxSigId)         (COM_CFG_RXSIG_INFO[RxSigId].RxPeriodTimeOut)
#define COM_CFG_RXSIG_UPTO_FIRSTPERIOD(RxSigId)    (COM_CFG_RXSIG_INFO[RxSigId].RxFirstTimeOut)
#define COM_CFG_RXSIG_TO_TIMEOUT_ACT(RxSigId)      (COM_CFG_RXSIG_INFO[RxSigId].TimeoutAct)

#define COM_CFG_RXSIG_IS_GROUP_SIGNAL(RxSigId)       (COM_CFG_RXSIG_INFO[RxSigId].isGroupSignal)
#define COM_CFG_RXSIG_GET_SIGGROUPID(RxSigId)        (COM_CFG_RXSIG_INFO[RxSigId].groupId)
#define COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId)        (COM_CFG_RXSIG_INFO[RxSigId].GroupSigTempBuf)
#define COM_CFG_RXSIG_GROUP_TEMPLENGTH_PTR(RxSigId)  (COM_CFG_RXSIG_INFO[RxSigId].GroupDynSigLengthBuf)

#define COM_CFG_RXSIG_MIN_BYTE(RxSigId)              (COM_CFG_RXSIG_INFO[RxSigId].MinSigByte)
#if(STD_ON==COM_DEM_EVENT_SET_SUPPORT)
#define COM_CFG_RXSIG_DEM_EVENT_ID(RxSigId)         (COM_CFG_RXSIG_INFO[RxSigId].DemEventId)
#endif
#define COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId)         (COM_CFG_RXSIG_INFO[RxSigId].RxSigCbkRxAckFun)
#if(STD_ON == COM_RX_INVALID_SUPPORT)
#define COM_CFG_RXSIG_CBKINV_FUN(RxSigId)           (COM_CFG_RXSIG_INFO[RxSigId].RxSigCbkInvFun)
#endif
#define COM_CFG_RXSIG_CBKRXTOUT_FUN(RxSigId)        (COM_CFG_RXSIG_INFO[RxSigId].RxSigCbkRxTOutFun)


/*******************************************************************************
*   Macro ipdu group
*******************************************************************************/
#if (STD_ON == COM_IPDU_GROUP_FUN)
#define COM_CFG_TX_PDUGROUP_PTR(IpduGroupId)                (COM_CFG_PDU_GROUP_INFO[IpduGroupId].TxIpduGroupPtr)
#define COM_CFG_TX_PDUGROUP_NUM(IpduGroupId)                (COM_CFG_PDU_GROUP_INFO[IpduGroupId].TxIpduGroupNum)


#define COM_CFG_RX_PDUGROUP_PTR(IpduGroupId)                (COM_CFG_PDU_GROUP_INFO[IpduGroupId].RxIpduGroupPtr)
#define COM_CFG_RX_PDUGROUP_NUM(IpduGroupId)                (COM_CFG_PDU_GROUP_INFO[IpduGroupId].RxIpduGroupNum)

#endif


/*******************************************************************************
*   Macro signal group
*******************************************************************************/
/* Signal Group Access*/
#define COM_CFG_TXSIGGRP_SUPPORT_ARRAY(SigGrpId)         (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].isArrayAccessSupport)
#define COM_CFG_TXSIGGRP_SIGSTOP(SigGrpId)               (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].SignalStopNum)
#define COM_CFG_TXSIGGRP_SIGSTART(SigGrpId)              (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].SignalStartNum)
#define COM_CFG_TXSIGGRP_UPDATEBIT_INDEX(SigGrpId)       (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].updateBitIndex)
#define COM_CFG_TXSIGGRP_TRPROP(SigGrpId)                (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].SigGrpTransferProperty)
#define COM_CFG_TXSIGGRP_PDUID(SigGrpId)                 (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].PduId)
#if(COM_Enable_SignalGroupArrayApi == STD_ON)
#define COM_CFG_TXSIGGRP_STARTBYTE(SigGrpId)             (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].StartByte)
#define COM_CFG_TXSIGGRP_SIZE(SigGrpId)                  (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].ByteNum)
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
#define COM_CFG_TXSIG_GRP_SHARE_BUF_PTR(SigGrpId)        (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].TxSigGrpShareBufPtr)
#endif
#endif
#define COM_CFG_TXSIGGRP_HAS_INVALID_VAL(SigGrpId)       (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].hasInValidVal)
/*#define COM_CFG_TXSIGGRP_HAS_FILTER(SigGrpId)            (COM_CFG_TXSIG_GROUP_INFO[SigGrpId].hasFilter) not used in this version*/


#define COM_CFG_RXSIGGRP_SUPPORT_ARRAY(SigGrpId)         (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].isArrayAccessSupport)
#define COM_CFG_RXSIGGRP_SIGSTOP(SigGrpId)               (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].SignalStopNum)
#define COM_CFG_RXSIGGRP_SIGSTART(SigGrpId)              (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].SignalStartNum)
/*#define COM_CFG_RXSIGGRP_UPDATEBIT_INDEX(SigGrpId)       (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].updateBitIndex)not used in this version*/
/*#define COM_CFG_RXSIGGRP_TRPROP(SigGrpId)                (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].SigGrpTransferProperty)not used in this version*/
#define COM_CFG_RXSIGGRP_PDUID(SigGrpId)                 (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].PduId)
#if(COM_Enable_SignalGroupArrayApi == STD_ON)
#define COM_CFG_RXSIGGRP_STARTBYTE(SigGrpId)             (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].StartByte)
#define COM_CFG_RXSIGGRP_SIZE(SigGrpId)                  (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].ByteNum)
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
#define COM_CFG_RXSIG_GRP_SHARE_BUF_PTR(SigGrpId)         (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].RxSigGrpShareBufPtr)
#endif
#endif
#define COM_CFG_RXSIGGRP_HAS_INVALID_VAL(SigGrpId)       (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].hasInValidVal)
#define COM_CFG_RXSIGGRP_HAS_FILTER(SigGrpId)            (COM_CFG_RXSIG_GROUP_INFO[SigGrpId].hasFilter)

/*******************************************************************************
*   Macro GW Signal 
*******************************************************************************/
#define COM_CFG_GW_SIGNAL_ID(GWSigId)                   (COM_CFG_GWSIG_INFO[GWSigId].GwRxSignalId)
#define COM_CFG_GW_TX_SIGNAL_NUM(GWSigId)               (COM_CFG_GWSIG_INFO[GWSigId].GwTxSignalNum)
#define COM_CFG_GW_TX_SIGNAL_TABLE(GWSigId)             (COM_CFG_GWSIG_INFO[GWSigId].GwTxSignalTable)

/*******************************************************************************
*   Macro Rx Ring Buffer
*******************************************************************************/
#define COM_CFG_RX_RING_QUEUE_INFO_PTR(CoreId)          (COM_CFG_RX_RING_QUEUE[CoreId].PduInfoPtr)
#define COM_CFG_RX_RING_QUEUE_DATA_PTR(CoreId)          (COM_CFG_RX_RING_QUEUE[CoreId].PduDataPtr)

#define COM_RX_RING_QUEUE_INFO_STATE_PTR(CoreId)        (&ComRxPduInfoQueueState[CoreId])
#define COM_RX_RING_QUEUE_DATA_STATE_PTR(CoreId)        (&ComRxPduDataQueueState[CoreId])

#define COM_RX_RING_QUEUE_PDU_NUM(CoreId)               (ComRxPduQueuePduNum[CoreId])

/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == COM_DEV_ERROR_DETECT)

#define  COM_DET_ERROR_DETECT(cond, ApiId, errcode)  \
    DET_ERROR_DETECT((cond), COM_MODULE_ID, COM_INSTANCE_ID,(ApiId),(errcode))

#define  COM_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret) \
    DET_ERROR_DETECT_RET((cond), COM_MODULE_ID,COM_INSTANCE_ID,(ApiId),(errcode), (ret))

#define  COM_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(COM_MODULE_ID, COM_INSTANCE_ID, (ApiId), (errcode))

#define  COM_DET_REPORT_RUNTIME_ERROR(ApiId, errcode)  \
    DET_REPORT_RUNTIME_ERROR(COM_MODULE_ID, COM_INSTANCE_ID, (ApiId), (errcode))

#else

#define  COM_DET_ERROR_DETECT(cond, ApiId, errcode)
#define  COM_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret)
#define  COM_DET_REPORT_ERROR(ApiId, errcode)
#define  COM_DET_REPORT_RUNTIME_ERROR(ApiId, errcode)

#endif


/*******************************************************************************
*   Static Api of Com
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

#if(STD_ON == COM_TXPDU_FUN)
STATIC FUNC(void, COM_CODE) Com_InitTxPdu
(
    PduIdType TxIpduId,
    boolean   isStartFlag
);

STATIC FUNC(void, COM_CODE) Com_InitTxPduValue
(
    PduIdType TxIpduId
);

#if((STD_ON == COM_TX_FILTER_SUPPORT) && (COM_MAX_FILTER_OCCURRENCE_NUM > 0))
STATIC FUNC(void, COM_CODE) Com_InitTxOccOfPdu
(
    PduIdType TxIpduId
);
#endif


#if(STD_ON == COM_IPDU_GROUP_FUN)
STATIC FUNC(void, COM_CODE) Com_SwitchTxPduMode
(
    PduIdType TxIpduId,
    boolean   isStartFlag,
    boolean   InitFlag
);
#if(STD_ON == COM_TX_SIGNAL_ERR_FUNC_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_CbkTxErrAck_PDU
(
    PduIdType TxIpduId
);
#endif
#endif

STATIC FUNC(void, COM_CODE) Com_TxInit(void);

#if (STD_ON == COM_TX_FILTER_SUPPORT)
STATIC FUNC(boolean, COM_CODE) Com_GetTMSResult
(
    PduIdType TxIpduId
);
#endif

STATIC FUNC(void, COM_CODE) Com_SelectPduTxMode
(
    PduIdType TxIpduId,
    uint8 TxSendSwitchTxModeFlag
);

#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
STATIC FUNC(void, COM_CODE) Com_StartTxDeadlineMotitor
(
    PduIdType TxIpduId,
    boolean needRestartTimer
);
#endif

#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
STATIC FUNC(uint8, COM_CODE) Com_HandleDirect
(
    PduIdType TxIpduId
);
#endif

#if((STD_ON == COM_TXMODE_PERIODIC) || (STD_ON == COM_TXMODE_MIXED))
STATIC FUNC(boolean, COM_CODE) Com_HandlePeriod
(
    PduIdType TxIpduId
);
#endif

#if(STD_ON == COM_TXMODE_MIXED)
STATIC FUNC(boolean, COM_CODE) Com_HandleMixed
(
    PduIdType TxIpduId
);
#endif

#if(STD_ON == COM_TXMODE_NONE)
STATIC FUNC(void, COM_CODE) Com_HandleNone
(
    PduIdType TxIpduId
);
#endif

#if (STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_CheckTxSigIfActive
(
    PduIdType TxIpduId,
    Com_SignalIdType TxSigId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) newDataPtr,
    P2CONST(void, AUTOMATIC, COM_CONST)     cfgInActiveValPtr
);

STATIC FUNC(boolean, COM_CODE) Com_HandleIfActive
(
    PduIdType TxIpduId
);

#endif


STATIC FUNC(boolean, COM_CODE) Com_TxModeProcess
(
    PduIdType TxIpduId
);

STATIC FUNC(void, COM_CODE) Com_TransmitPdu
(
    PduIdType TxIpduId
);

#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
STATIC FUNC(void, COM_CODE) Com_CbkTxTOut_PDU
(
    PduIdType TxIpduId
);
STATIC FUNC(void, COM_CODE) Com_TxTimerOutMonitor
(
    PduIdType TxIpduId
);
#endif
#if(STD_ON == COM_TX_SIGNAL_ACK_FUNC_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_CbkTxAck_PDU
(
    PduIdType TxIpduId
);
#endif


#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
STATIC FUNC(void, COM_CODE) Com_SetIpduTrigRepFlag
(
    Com_SignalTxPropertyType txProperty,
    PduIdType TxIpduId,
    boolean changeFlag
);
#endif


#if(STD_ON == COM_TX_FILTER_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_TxSignalFilterProcess
(
    Com_SignalIdType  ComTxSigId,
    Com_SigType SigType,
    P2CONST(void, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);

#endif

#if(STD_ON == COM_TX_UPDATEBIT_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_SetSigUpdateBit
(
    PduIdType TxIpduId,
    uint16  index
);


STATIC FUNC(void, COM_CODE) Com_ClearUpdateBit
(
    PduIdType TxIpduId
);

#endif


STATIC FUNC(void, COM_CODE) Com_ProcessTxConf
(
    PduIdType TxIpduId,
    Com_TxPduStateType pduState
);

#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
STATIC FUNC(uint8, COM_CODE) Com_SendSignalGroup_Internal
(
    Com_SignalGroupIdType SignalGroupId
);
#if(STD_ON == COM_TX_INVALID_SUPPORT)
STATIC FUNC(uint8, COM_CODE) Com_InvalidateSignalGroup_Internal
(
    Com_SignalGroupIdType SignalGroupId
);
#endif
#if(STD_ON == COM_Enable_SignalGroupArrayApi)
STATIC FUNC(uint8, COM_CODE) Com_SendSignalGroupArray_Internal
(
    Com_SignalGroupIdType SignalGroupId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)  SignalGroupArrayPtr
);
#endif
#endif

#endif/*#if(STD_ON == COM_TXPDU_FUN)*/


#if(STD_ON == COM_RXPDU_FUN)


#if (STD_ON == COM_RX_INVALID_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_RxPduInvalid
(
    PduIdType RxPduId
);
#endif

STATIC FUNC(boolean, COM_CODE) Com_CheckRxLength
(
    PduIdType RxPduId,
    PduLengthType length
);


STATIC FUNC(void, COM_CODE) Com_ReplaceRxSignalWithInit
(
    PduIdType RxPduId,
    Com_SignalIdType RxSigId,
    boolean NeedRoutOut
);

#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
#if(STD_ON == COM_RX_SIGNAL_SUBSTITUTE_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_ReplaceRxSignalWithSubstitute
(
    PduIdType RxPduId,
    Com_SignalIdType sigId
);
#endif
#endif

STATIC FUNC(void, COM_CODE) Com_InitRxPdu
(
    PduIdType RxIpduId,
    boolean   isStartFlag
);


#if(STD_ON == COM_IPDU_GROUP_FUN)
STATIC FUNC(void, COM_CODE) Com_SwitchRxPduMode
(
    PduIdType RxIpduId,
    boolean   isStartFlag,
    boolean   InitFlag
);
#endif

STATIC FUNC(void, COM_CODE) Com_RxInit
(
    void
);

#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
STATIC FUNC(void, COM_CODE) Com_RxTimerOutMonitor
(
    PduIdType RxIpduId
);
#if(STD_ON == COM_RX_SIGNAL_UB_TIMEOUT_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_ResetUpdateRxToTimer
(
    PduIdType RxIpduId
);

STATIC FUNC(void, COM_CODE) Com_UpdateRxTimerOutMonitor
(
    PduIdType RxIpduId
);
#endif
#endif

#if(STD_ON == COM_RX_UPDATEBIT_SUPPORT)
STATIC FUNC(boolean, COM_CODE) Com_CheckSigUpdateBit
(
    PduIdType RxIpduId,
    Com_SignalIdType index,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);
#endif

#if((COM_RX_FILTER_SUPPORT == STD_ON) && (COM_MAX_FILTER_OCCURRENCE_NUM > 0))
STATIC FUNC(void, COM_CODE) Com_InitRxOccOfPdu
(
    PduIdType RxIpduId
);
#endif



STATIC FUNC(void, COM_CODE) Com_InitRxPduValue
(
    PduIdType RxIpduId
);
#if 0
STATIC FUNC(void, COM_CODE) Com_HandleRxPdu_DirectCopy
(
    PduIdType RxPduId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);
#endif
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
#if((COM_RX_FILTER_SUPPORT == STD_ON) || (STD_ON == COM_RX_INVALID_SUPPORT))
STATIC FUNC(uint8, COM_CODE) Com_CheckRxSignalGroup_Invalid_Filter
(
    Com_SignalGroupIdType RxSigGrpId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);
#endif

STATIC FUNC(void, COM_CODE) Com_RxSignalGroup_ProcessAfterCheck
(
    PduIdType RxPduId,
    uint8 filterResult,
    Com_SignalIdType RxSigId,
    Com_SignalGroupIdType SigGrpId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);
#endif

#if((COM_RX_FILTER_SUPPORT == STD_ON) || (STD_ON == COM_RX_INVALID_SUPPORT))
STATIC FUNC(uint8, COM_CODE) Com_RxSignalFilter
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);
#endif

STATIC FUNC(void, COM_CODE) Com_RxSignal_ProcessAfterCheck
(
    uint8 filterResult,
    PduIdType RxPduId,
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);

STATIC FUNC(void, COM_CODE) Com_HandleRxPdu
(
    PduIdType RxPduId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);




#endif/*#if(STD_ON == COM_RXPDU_FUN)*/


#if(STD_ON == COM_IPDU_GROUP_FUN)
STATIC FUNC(void, COM_CODE) Com_IpduGroupStart_Internal
(
    Com_IpduGroupIdType IpduGroupId,
    boolean Initialize
);
STATIC FUNC(void, COM_CODE) Com_IpduGroupStop_Internal
(
    Com_IpduGroupIdType IpduGroupId
);
STATIC FUNC(boolean, COM_CODE) Com_IsPduStart
(
    PduIdType pduId,
    boolean isTx
);
#endif
#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
STATIC FUNC(boolean, COM_CODE) Com_IsPduDMEnable_Internal
(
    PduIdType pduId
);
#endif

STATIC FUNC(void, COM_CODE) Com_CopySignal
(
    P2CONST(void, AUTOMATIC, COM_CONST) SrcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) DestPtr,
    Com_SigType SigType,
    PduLengthType ByteLength,
    Com_SignalIdType SignalId
);
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_CrossCoreTxSignalsTack
(
    PduIdType TxSigPduId
);
#endif/*#if(STD_ON == COM_MULTI_CORE_SUPPORT)*/

#if(STD_ON == COM_GW_FUN)
STATIC FUNC(void, COM_CODE) Com_GateWaySignal
(
    Com_SignalIdType GwSignalIndex,
    P2VAR(void, AUTOMATIC, COM_VAR) ValuePtr
);
#endif

STATIC FUNC(void, COM_CODE) Com_HandleRxSig_U8
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_S8
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_U16
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_S16
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_U32
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_S32
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_F32
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_U64
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_S64
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_F64
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);
#if(COM_RX_SIG_MAX_ARRAY_SZIE > 0)
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_U8N
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);
#endif
STATIC FUNC(void, COM_CODE) Com_HandleRxSig
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
);

#if(STD_ON == COM_IPDU_GROUP_FUN)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_IsPduStart
*
* Description:   This service check if pdu need to be started based on pdu group state
*
* Inputs:        pduId, isTx
*
* Outputs:       boolean
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_IsPduStart
(
    PduIdType pduId,
    boolean isTx
)
{
    boolean flag = FALSE;
    Com_IpduGroupIdType grpIdx = (Com_IpduGroupIdType)0;
    Com_IpduGroupIdType tmpNum = (Com_IpduGroupIdType)0;
    P2CONST(Com_IpduGroupIdType, AUTOMATIC, COM_CONST) tmpPtr = NULL_PTR;

    if(TRUE == isTx)
    {
#if(STD_ON == COM_TXPDU_FUN)
        tmpNum = COM_CFG_TXPDU_IN_PDUGRP_NUM(pduId);
        tmpPtr = COM_CFG_TXPDU_IN_PDUGRP_PTR(pduId);
#endif
    }
    else
    {
#if(STD_ON == COM_RXPDU_FUN)
        tmpNum = COM_CFG_RXPDU_IN_PDUGRP_NUM(pduId);
        tmpPtr = COM_CFG_RXPDU_IN_PDUGRP_PTR(pduId);
#endif
    }

    /* search all pdugroup which contains thia pdu, if any one is start, retuan True = Start*/
    for(grpIdx = (Com_IpduGroupIdType)0; grpIdx < tmpNum; grpIdx++)
    {
        if(TRUE == Com_IpduGroupStartFlag[tmpPtr[grpIdx]])
        {
            flag = TRUE;
            break;
        }
    }


    return flag;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_IpduGroupStart_Internal SWS_Com_00751 792
*
* Description:   start target group and keep other group unchange
*
* Inputs:        IpduGroupId
*                Initialize
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_IpduGroupStart_Internal
(
    Com_IpduGroupIdType IpduGroupId,
    boolean Initialize
)
{
    PduIdType pduIndex = (PduIdType)0;
    PduIdType pduId = (PduIdType)0;
#if(STD_ON == COM_TXPDU_FUN)
    P2CONST(PduIdType, AUTOMATIC, COM_CONST) tmpTxGrpPtr = NULL_PTR;
#endif
#if(STD_ON == COM_RXPDU_FUN)
    P2CONST(PduIdType, AUTOMATIC, COM_CONST) tmpRxGrpPtr = NULL_PTR;
#endif
    /* SWS_COM 7.3.5.2, starts group if it was previously stopped*/
    if(FALSE == Com_IpduGroupStartFlag[IpduGroupId])
    {

        Com_IpduGroupStartFlag[IpduGroupId] = TRUE;
#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
        Com_IpduGroupDMEnableFlag[IpduGroupId] = TRUE;
#endif
    /* start group  */
#if(STD_ON == COM_TXPDU_FUN)
        tmpTxGrpPtr = COM_CFG_TX_PDUGROUP_PTR(IpduGroupId);
        for(pduIndex = (PduIdType)0; pduIndex < COM_CFG_TX_PDUGROUP_NUM(IpduGroupId); pduIndex++)
        {
            pduId = tmpTxGrpPtr[pduIndex];
            if(Com_TxPduState[pduId] == COM_TXPDU_STOP)
            {
                Com_SwitchTxPduMode(pduId, TRUE, Initialize);
            }
            /* when pdu is already in start state, do nothing even Initialize = true, donot reset signal value or tx period*/


        }
#endif
#if(STD_ON == COM_RXPDU_FUN)
        tmpRxGrpPtr = COM_CFG_RX_PDUGROUP_PTR(IpduGroupId);
        for(pduIndex = (PduIdType)0; pduIndex < COM_CFG_RX_PDUGROUP_NUM(IpduGroupId); pduIndex++)
        {
            pduId = tmpRxGrpPtr[pduIndex];
            if(Com_RxPduState[pduId] == COM_RXPDU_STOP)
            {
                Com_SwitchRxPduMode(pduId, TRUE, Initialize);
            }
            /* when pdu is already in start state, do nothing even Initialize = true, donot reset signal value */
        
        }
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_IpduGroupStop_Internal SWS_Com_00751 792
*
* Description:   stop target group and keep other group unchange
*
* Inputs:        IpduGroupId
*
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_IpduGroupStop_Internal
(
    Com_IpduGroupIdType IpduGroupId
)
{
    PduIdType pduIndex = (PduIdType)0;
    PduIdType pduId = (PduIdType)0;
    boolean tmpPduStartFlag = FALSE;
#if(STD_ON == COM_TXPDU_FUN)
    P2CONST(PduIdType, AUTOMATIC, COM_CONST) tmpTxGrpPtr = NULL_PTR;
#endif
#if(STD_ON == COM_RXPDU_FUN)
    P2CONST(PduIdType, AUTOMATIC, COM_CONST) tmpRxGrpPtr = NULL_PTR;
#endif
    /* SWS_COM 7.3.5.3, stop group if it was previously started*/
    if(TRUE == Com_IpduGroupStartFlag[IpduGroupId])
    {
        /* must set group = false first , as following code will use this flag to decide the pdu state*/
        Com_IpduGroupStartFlag[IpduGroupId] = FALSE;
#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
        Com_IpduGroupDMEnableFlag[IpduGroupId] = FALSE;
#endif
#if(STD_ON == COM_TXPDU_FUN)
        /* Stop group  */
        tmpTxGrpPtr = COM_CFG_TX_PDUGROUP_PTR(IpduGroupId);
        for(pduIndex = (PduIdType)0; pduIndex < COM_CFG_TX_PDUGROUP_NUM(IpduGroupId); pduIndex++)
        {
            pduId = tmpTxGrpPtr[pduIndex];

            /* search all pdugroup which contains thia pdu, if any one is start, retuan True*/
            tmpPduStartFlag = Com_IsPduStart(pduId, TRUE);

            if((tmpPduStartFlag == FALSE) && (Com_TxPduState[pduId] != COM_TXPDU_STOP))
            {
                Com_SwitchTxPduMode(pduId, FALSE, FALSE);
#if(STD_ON == COM_TX_SIGNAL_ERR_FUNC_SUPPORT)
                /* Err Ack when pdu is sending out*/
                if((COM_TXPDU_START_BUSY == Com_TxPduState[pduId])
                        || (COM_TXPDU_START_RETX == Com_TxPduState[pduId]))
                {
                    Com_CbkTxErrAck_PDU(pduId);
                }
#endif
            }

            /* if pdu already in stop state  do nothing*/
            /* if pdu need to keep start ,  do nothing*/

        }
#endif
#if(STD_ON == COM_RXPDU_FUN)
        tmpRxGrpPtr = COM_CFG_RX_PDUGROUP_PTR(IpduGroupId);
        for(pduIndex = (PduIdType)0; pduIndex < COM_CFG_RX_PDUGROUP_NUM(IpduGroupId); pduIndex++)
        {
            pduId = tmpRxGrpPtr[pduIndex];
            /* search all pdugroup which contains thia pdu, if any one is start, retuan True*/
            tmpPduStartFlag = Com_IsPduStart(pduId, FALSE);

            if((tmpPduStartFlag == FALSE) && (Com_RxPduState[pduId] != COM_RXPDU_STOP))
            {
                Com_SwitchRxPduMode(pduId, FALSE, FALSE);
            }

            /* if pdu already in stop state  do nothing*/
            /* if pdu need to keep start ,  do nothing*/
        }
#endif
    }
}

#endif/* #if(STD_ON == COM_IPDU_GROUP_FUN) */


#if(STD_ON == COM_MetaDataSupport)
STATIC FUNC(Std_ReturnType, COM_CODE) Com_SetMetadata
(
    PduIdType PduId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) MetaDataPtr
);

STATIC FUNC(Std_ReturnType, COM_CODE) Com_GetMetadata
(
    PduIdType PduId,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) MetaDataPtr
);
#endif




#if(STD_ON == COM_TXPDU_FUN)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_WriteSignal_Internal
*
* Description:   This service write signal into txbuf or shadow buffer
*
* Inputs:        SignalId, SignalDataPtr, length
*
* Outputs:       uint8
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_WriteSignal_Internal
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    PduLengthType length
)
{
    const PduIdType TxIpduId = COM_CFG_TXSIG_TXPDU_ID(SignalId);
    Com_EndiannessType Endianness;
    Com_SigType SigType;
    uint16 BitSize;
    uint16 StartBit;
    uint8 MaskLsb;
    uint8 MaskMsb;
    uint8 result = COM_SERVICE_NOT_AVAILABLE;
#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
    boolean IfActiveChangeFlag = FALSE;
#endif
#if(STD_ON == COM_TX_FILTER_SUPPORT)
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr = NULL_PTR;
#endif
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
    boolean ChangeFlag = FALSE;
#endif

#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    if(FALSE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(SignalId))
#endif
    {
        /* SWS_Com_00334, signal can be updated when pdu is stop
           in stop mode, tms result, txmode and data will be saved
           but trigger will not be saved,
           so that the msg will not be send at once when pdu is started
        */
#if(STD_ON == COM_TX_LONG_PDU_FUN)
        if((COM_TXPDU_START_BUSY == Com_TxPduState[TxIpduId]) && (TRUE == COM_CFG_TXPDU_IS_TP_PDU(TxIpduId)))
        {
            result = COM_BUSY;
        }
        else
#endif
        {
#if 0/* Not use in this version 2024/10/12*/
#if(STD_ON == COM_TXSIG_ON_CHANGE_SUPPORT)
            if( ( COM_CFG_TXSIG_TRANSPROPERTY(SignalId) >= COM_TRIGGERED_ON_CHANGE ) && ( COM_CFG_TXSIG_TRANSPROPERTY(SignalId) < COM_IFACTIVE_SIG ) )
            {
                ChangeFlag = Com_CheckChangeSignalInPdu(SignalDataPtr, COM_CFG_TXPDU_DATA_PTR(TxIpduId), Endianness, SigType, BitSize, StartBit, Mask, length);
            }
#endif
#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
                if(COM_CFG_TXSIG_TRANSPROPERTY(SignalId) == COM_IFACTIVE_ON_CHANGE_SIG)
                {
                    if(FALSE == IfActiveChangeFlag)
                    {
                        IfActiveChangeFlag = Com_CheckChangeSignalInPdu(SignalDataPtr, COM_CFG_TXPDU_DATA_PTR(TxIpduId), Endianness, SigType, Mask, BitSize, StartBit, length);
                    }
                }
#endif
#endif
            SigType = COM_CFG_TXSIG_TYPE(SignalId);
            /* do Tx Filter if configured , must filter before write data , as maybe mask oldNew*/
#if(STD_ON == COM_TX_FILTER_SUPPORT)
            AlgPtr = COM_CFG_TXSIG_FILTER_PTR(SignalId);
            if(NULL_PTR != AlgPtr)
            {
                Com_TxSignalFilterProcess(SignalId, SigType, SignalDataPtr, AlgPtr);
            }
#endif
            if(FALSE == Com_TxSigIsSameValue[SignalId])
            {
#if(STD_ON == COM_TX_FILTER_SUPPORT)
                if(NULL_PTR != AlgPtr)
                {
                    if(NULL_PTR != AlgPtr->Par3)
                    {
                        Com_CopySignalWithOutLock(SignalDataPtr, AlgPtr->Par3, SigType, length);
                    }
                }
#endif
                Endianness = COM_CFG_TXSIG_ENDIANNESS(SignalId);
                BitSize = COM_CFG_TXSIG_BIT_SIZE(SignalId);
                StartBit = COM_CFG_TXSIG_START_BIT(SignalId);
                MaskLsb = COM_CFG_TXSIG_MASK_LSB(SignalId);
                MaskMsb = COM_CFG_TXSIG_MASK_MSB(SignalId);
                Com_WriteSignal(SignalDataPtr, COM_CFG_TXPDU_DATA_PTR(TxIpduId), Endianness, SigType, BitSize, StartBit, MaskLsb, MaskMsb, length);
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
                ChangeFlag = TRUE;
#endif
            }
            else
            {
                Com_TxSigIsSameValue[SignalId] = FALSE;
            }

#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
            Com_CheckTxSigIfActive(TxIpduId, SignalId,SignalDataPtr, COM_CFG_TXSIG_INACTIVE_VALUE_PTR(SignalId));
            if(COM_CFG_TXSIG_TRANSPROPERTY(SignalId) == COM_IFACTIVE_ON_CHANGE_SIG) 
            {
                if(FALSE == Com_TxSigIsSameValue[SignalId])
                {
                    if((uint32)0 != COM_TXPDU_IFACTIVE_FLAG(TxIpduId))
                    {
                        COM_TXPDU_IFACTIVE_CHANGE_FLAG(TxIpduId) = TRUE;
                    }
                }
            }
#endif



#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
            if(COM_SIG_DYN == COM_CFG_TXSIG_TYPE(SignalId))
            {
                COM_TXPDU_DYN_LENGTH(TxIpduId) = COM_CFG_TXSIG_START_BYTE_INDEX(SignalId) + length;
            }
#endif

#if(COM_TX_UPDATEBIT_SUPPORT == STD_ON)
            /* set update bit if configured*/
            if(COM_INVALID_SIG_INDEX != COM_CFG_TXSIG_UPDATEBIT_INDEX(SignalId))
            {
                Com_SetSigUpdateBit(TxIpduId, COM_CFG_TXSIG_UPDATEBIT_INDEX(SignalId));
            }
#endif

            /* this Asr req Page54 Table3, when pdu is stop, data canbe updated, but return COM_SERVICE_NOT_AVAILABLE*/
            /*SWS_Com_334 dont save trigger when stop*/
            if(COM_TXPDU_STOP != Com_TxPduState[TxIpduId])
            {
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
                Com_SetIpduTrigRepFlag(COM_CFG_TXSIG_TRANSPROPERTY(SignalId), TxIpduId, ChangeFlag);
#endif
                result = E_OK;
            }



        }
    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    else/* Not use in this version 2024/10/12*/
    {
        /* if group signal, only update shadow buffer */
        /*shadow buffer can be updated even txstate is busy*/
        /* if group enable array access, dont do anything here*/
        if(FALSE == COM_CFG_TXSIGGRP_SUPPORT_ARRAY(COM_CFG_TXSIG_GET_SIGGROUPID(SignalId)))
        {
            SigType = COM_CFG_TXSIG_TYPE(SignalId);
            /* Com_CopySignalWithOutLock(SignalDataPtr, COM_CFG_TXSIG_GROUP_TEMP_BUF(SignalId), SigType, length); */
            Com_CopySignalWithOutLock(SignalDataPtr, COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), SigType, length);
#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
            if(COM_SIG_DYN == COM_CFG_TXSIG_TYPE(SignalId))
            {
                *COM_CFG_TXSIG_GROUP_TEMPLENGTH_PTR(SignalId) = length;
            }
#endif
            /* this Asr req Page54 Table3, when pdu is stop, data canbe updated, but return COM_SERVICE_NOT_AVAILABLE*/
            if(COM_TXPDU_STOP != Com_TxPduState[TxIpduId])
            {
                result = E_OK;
            }
        }
    }
#endif

    return result;

}



#if(STD_ON == COM_TX_UPDATEBIT_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SetSigUpdateBit
*
* Description:   This service set target update bits of signal
*
* Inputs:        TxIpduId, index
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(void, COM_CODE) Com_SetSigUpdateBit
(
    PduIdType TxIpduId,
    uint16  Index
)
{
    PduLengthType tempByteIndex = COM_CFG_TXPDU_UPDATEBIT_INFO(TxIpduId)[Index].UpdateByteIndex;
    uint8 tempMaskValue = COM_CFG_TXPDU_UPDATEBIT_INFO(TxIpduId)[Index].UpdateMaskValue;
#if(STD_ON == COM_TX_UB_CLEAR_DELAY_SUPPORT)
    P2VAR(uint8, TYPEDEF, COM_VAR) tempDelayCntPtr = COM_CFG_TXPDU_UPDATEBIT_INFO(TxIpduId)[Index].UpdateDelayCntPtr;
#endif

    tempMaskValue = (uint8)(~tempMaskValue);

    ((uint8 *)COM_CFG_TXPDU_DATA_PTR(TxIpduId))[tempByteIndex] |= tempMaskValue;
#if(STD_ON == COM_TX_UB_CLEAR_DELAY_SUPPORT)
    *tempDelayCntPtr = COM_UB_DELAY_CLEAR_NUM;
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ClearUpdateBit
*
* Description:   This service clear all update bits of pdu
*
* Inputs:        TxIpduId:
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_ClearUpdateBit
(
    PduIdType TxIpduId
)
{
    uint16 Index = (uint16)0;
    PduLengthType tempByteIndex;
    uint8 tempMaskValue;
    P2CONST(Com_CfgTxUpdateBitInfoType, AUTOMATIC, COM_CONST) tmpTxUpBitPtr = NULL_PTR;
    P2VAR(uint8, AUTOMATIC, COM_CONST) tmpTxDataPtr = NULL_PTR;
#if(STD_ON == COM_TX_UB_CLEAR_DELAY_SUPPORT)
    P2VAR(uint8, TYPEDEF, COM_VAR) tempDelayCntPtr = NULL_PTR;
#endif

    tmpTxDataPtr = (uint8 *)COM_CFG_TXPDU_DATA_PTR(TxIpduId);
    tmpTxUpBitPtr = COM_CFG_TXPDU_UPDATEBIT_INFO(TxIpduId);
    for(Index = (uint16)0; Index < COM_CFG_TXPDU_UPDATEBIT_NUM(TxIpduId); Index++)
    {
#if(STD_ON == COM_TX_UB_CLEAR_DELAY_SUPPORT)
        tempDelayCntPtr = tmpTxUpBitPtr[Index].UpdateDelayCntPtr;
        if(*tempDelayCntPtr > (uint8)0)
        {
            (*tempDelayCntPtr)--;
        }
        if(*tempDelayCntPtr == (uint8)0)
        {
            tempByteIndex = tmpTxUpBitPtr[Index].UpdateByteIndex;
            tempMaskValue = tmpTxUpBitPtr[Index].UpdateMaskValue;
            tmpTxDataPtr[tempByteIndex] &= tempMaskValue;
        }
        
#else
        tempByteIndex = tmpTxUpBitPtr[Index].UpdateByteIndex;
        tempMaskValue = tmpTxUpBitPtr[Index].UpdateMaskValue;
        tmpTxDataPtr[tempByteIndex] &= tempMaskValue;
#endif
    }
}
#endif/*COM_TX_UPDATEBIT_SUPPORT*/



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_InitTxOccOfPdu
*
* Description:   Init Tx signal's occ counter to 0, if configured
*
* Inputs:        TxIpduId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if((STD_ON == COM_TX_FILTER_SUPPORT) && (COM_MAX_FILTER_OCCURRENCE_NUM > 0))
STATIC FUNC(void, COM_CODE) Com_InitTxOccOfPdu
(
    PduIdType TxIpduId
)
{
    Com_SignalIdType SigIndex = (Com_SignalIdType)0;
    Com_SignalIdType OccIndex = (Com_SignalIdType)0;

    for(SigIndex = COM_CFG_TXPDU_SIG_START_NUM(TxIpduId); SigIndex <= COM_CFG_TXPDU_SIG_STOP_NUM(TxIpduId); SigIndex++)
    {
        if(NULL_PTR != COM_CFG_TXSIG_FILTER_PTR(SigIndex))
        {
            OccIndex = COM_CFG_TXSIG_FILTER_PTR(SigIndex)->OccIndex;
            if(COM_INVALID_SIG_INDEX != OccIndex)
            {
                Com_Sig_Occurrence[OccIndex] = (Com_SignalIdType)0;
            }
        }
    }
}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_InitTxPduValue
*
* Description:   Init Rx Pdu values
*
* Inputs:        RxIpduId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_InitTxPduValue
(
    PduIdType TxIpduId
)
{
    PduLengthType IndexData = (PduLengthType)0;
    Com_SignalIdType SigIndex = (Com_SignalIdType)0;
    PduLengthType SigLen = (PduLengthType)0;
    Com_EndiannessType Endianness;
    Com_SigType SigType;
    uint16 BitSize;
    uint16 StartBit;
    uint8 MaskLsb;
    uint8 MaskMsb;
    P2VAR(void, AUTOMATIC, COM_VAR) tmpTxDataPtr = NULL_PTR;

    tmpTxDataPtr = COM_CFG_TXPDU_DATA_PTR(TxIpduId);
    /* Step 1 set all byte to unused byte*/
    for(IndexData = (PduLengthType)0; IndexData < COM_CFG_TXPDU_LENGTH(TxIpduId); IndexData++)
    {
        ((uint8 *)tmpTxDataPtr)[IndexData] = COM_CFG_TXPDU_UNUSED_BYTE(TxIpduId);
    }
    /* Step 2 init all signals of this pdu*/
    for(SigIndex = COM_CFG_TXPDU_SIG_START_NUM(TxIpduId); SigIndex <= COM_CFG_TXPDU_SIG_STOP_NUM(TxIpduId); SigIndex++)
    {
        Com_TxSigIsSameValue[SigIndex] = FALSE;
        Endianness = COM_CFG_TXSIG_ENDIANNESS(SigIndex);
        SigType = COM_CFG_TXSIG_TYPE(SigIndex);
        BitSize = COM_CFG_TXSIG_BIT_SIZE(SigIndex);
        StartBit = COM_CFG_TXSIG_START_BIT(SigIndex);
        MaskLsb = COM_CFG_TXSIG_MASK_LSB(SigIndex);
        MaskMsb = COM_CFG_TXSIG_MASK_MSB(SigIndex);
#if ((STD_ON == COM_TX_DYN_PDU_SUPPORT) || (STD_ON == COM_TX_U8N_SUPPORT))
        SigLen = COM_CFG_TXSIG_LENGTH(SigIndex);
#if (STD_ON == COM_TX_DYN_PDU_SUPPORT)
        if(COM_SIG_DYN == COM_CFG_TXSIG_TYPE(SigIndex))
        {
            SigLen = COM_CFG_TXSIG_INIT_VALUE_LEN(SigIndex);
            COM_TXPDU_DYN_LENGTH(TxIpduId) = COM_CFG_TXSIG_START_BYTE_INDEX(SigIndex) + SigLen ;
        }
#endif
#endif

        /* copy init value to real buffer*/
        Com_WriteSignal(COM_CFG_TXSIG_INIT_VALUE_PTR(SigIndex), tmpTxDataPtr, Endianness, SigType, BitSize, StartBit, MaskLsb, MaskMsb, SigLen);
        Com_CopySignalWithOutLock(COM_CFG_TXSIG_INIT_VALUE_PTR(SigIndex), COM_CFG_TXSIG_SHARE_BUF_PTR(SigIndex), SigType, SigLen);
#if (STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
#if (STD_ON == COM_TX_DYN_PDU_SUPPORT)
        if(NULL_PTR != COM_CFG_TXSIG_GROUP_TEMPLENGTH_PTR(SigIndex))
        {
            *COM_CFG_TXSIG_GROUP_TEMPLENGTH_PTR(SigIndex) = SigLen;
        }
#endif
#endif
#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
        if(TRUE == COM_CFG_TXPDU_IS_INACTIVE_CYCLIC(TxIpduId))
        {
            Com_CheckTxSigIfActive(TxIpduId, SigIndex, COM_CFG_TXSIG_INIT_VALUE_PTR(SigIndex), COM_CFG_TXSIG_INACTIVE_VALUE_PTR(SigIndex));
        }
#endif
    }
    /* Step 3 clear all update bit*/
#if (STD_ON == COM_TX_UPDATEBIT_SUPPORT)
    Com_ClearUpdateBit(TxIpduId);
#endif

}




/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_InitTxPdu
*
* Description:   used to Init TxPduRegs, only called when Init
*
* Inputs:         TxIpduId,isStartFlag
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_InitTxPdu
(
    PduIdType TxIpduId,
    boolean   isStartFlag
)
{
#if(STD_ON == COM_TX_UB_CLEAR_DELAY_SUPPORT)
    uint16 Index = (uint16)0;
    P2CONST(Com_CfgTxUpdateBitInfoType, AUTOMATIC, COM_CONST) tmpTxUpBitPtr = COM_CFG_TXPDU_UPDATEBIT_INFO(TxIpduId);
#endif
    /*TxMode Init*/
    COM_TXPDU_TMS_FLAG(TxIpduId) = TRUE;
    Com_SendSwitchTxModeFlag[TxIpduId] = COM_NO_TXMODE_SWITCH;

    COM_TXPDU_TXMODE_PTR(TxIpduId) = COM_CFG_TXPDU_TXMODE_TRUE_PTR(TxIpduId);


    /*Timer Init*/
    COM_TXPDU_PERIOD(TxIpduId) = COM_TIMER_STOP_VAL;/* tx period will be Init in Tx Main */
    COM_TXPDU_TXTIME_OFFSET(TxIpduId) = COM_TXPDU_TXMODE_PTR(TxIpduId)->TxModeTimeOffset;

#if (STD_ON == COM_MDT_CYCLIC_TRANSMISSION)
    COM_TXPDU_MIN_DELAY_TIMER(TxIpduId) = COM_TIMER_STOP_VAL;
    COM_TXPDU_TX_REQ_MINDELAY_BACKUP(TxIpduId) = FALSE;
#endif

#if (STD_ON == COM_TXMODE_REPTITION)
    COM_TXPDU_REP_NUM(TxIpduId) = (uint8)0;
    COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_TIMER_STOP_VAL;
    COM_TXPDU_REQ_CONF_NUM(TxIpduId) = (uint8)0;
#endif

#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
    Com_PDUTrigRepFlag[TxIpduId] = COM_NO_TRIGGER;
#endif

#if(STD_ON ==     COM_TX_TIMEOUT_MONITOR)
    /* dont need to check if txto is enable for this pdu*/
    COM_TXPDU_TIMEOUT(TxIpduId) = COM_TIMER_STOP_VAL;
#endif

#if(STD_ON == COM_TX_LONG_PDU_FUN)
    COM_TXPDU_TP_INDEX(TxIpduId) = (PduLengthType)0;
#endif

#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
    COM_TXPDU_IFACTIVE_FLAG(TxIpduId) = (uint32)0;
    COM_TXPDU_IFACTIVE_CHANGE_FLAG(TxIpduId) = FALSE;
#endif

#if(STD_ON == COM_TX_UB_CLEAR_DELAY_SUPPORT)
    for(Index = (uint16)0; Index < COM_CFG_TXPDU_UPDATEBIT_NUM(TxIpduId); Index++)
    {
        *(tmpTxUpBitPtr[Index].UpdateDelayCntPtr) = (uint8)0;
    }
#endif
    /*Pdu Data Length Init*/
    Com_InitTxPduValue(TxIpduId);

#if(STD_ON == COM_TriggerIPDUSend_API)
    Com_TriggerPDUSendFlag[TxIpduId] = FALSE;
#endif

#if(STD_ON == COM_MetaDataSupport)
    if(COM_CFG_TXPDU_METADATA_DEFAULT_PTR(TxIpduId) != NULL_PTR)
    {
        (void)Com_SetMetadata(TxIpduId, COM_CFG_TXPDU_METADATA_DEFAULT_PTR(TxIpduId));
    }
#endif

    if(FALSE == isStartFlag)
    {
        Com_TxPduState[TxIpduId] = COM_TXPDU_STOP;/*SWS_Com_444 all group stop at Init*/
    }
    else
    {
        Com_TxPduState[TxIpduId] = COM_TXPDU_START_IDLE;/*SWS_Com_840*/
    }
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SwitchTxPduMode
*
* Description:   used to Init TxPduRegs when pdu mode switch,
*
* Inputs:          TxIpduId,isStartFlag,InitFlag
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_IPDU_GROUP_FUN)
STATIC FUNC(void, COM_CODE) Com_SwitchTxPduMode
(
    PduIdType TxIpduId,
    boolean   isStartFlag,
    boolean   InitFlag
)
{

#if(STD_ON == COM_TX_LONG_PDU_FUN)
    COM_TXPDU_TP_INDEX(TxIpduId) = (PduLengthType)0;
#endif

#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
    Com_PDUTrigRepFlag[TxIpduId] = COM_NO_TRIGGER;
#endif

    /*Timer Init
      Start->Stop, Stop-Start,timers will all stop.
      except txOffset timer, will keep unchange, until restart

      data and length
      keep unchange until restart with init

      trigger flag and rep num must reset

    */
    COM_TXPDU_PERIOD(TxIpduId) = COM_TIMER_STOP_VAL;/* tx period will be Init in Tx Main */
    /* offset will reset when pdu restart, so that, the pdu will send like init SWS_Com_00222 -4*/
    COM_TXPDU_TXTIME_OFFSET(TxIpduId) = COM_TXPDU_TXMODE_PTR(TxIpduId)->TxModeTimeOffset;

#if (STD_ON == COM_MDT_CYCLIC_TRANSMISSION)/*SWS_Com_00787-1*/
    COM_TXPDU_MIN_DELAY_TIMER(TxIpduId) = COM_TIMER_STOP_VAL;
    COM_TXPDU_TX_REQ_MINDELAY_BACKUP(TxIpduId) = FALSE;
#endif

#if (STD_ON == COM_TXMODE_REPTITION)
    COM_TXPDU_REP_NUM(TxIpduId) = (uint8)0;
    COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_TIMER_STOP_VAL;
    COM_TXPDU_REQ_CONF_NUM(TxIpduId) = (uint8)0;
#endif


#if(STD_ON ==     COM_TX_TIMEOUT_MONITOR)
    /* dont need to check if txto is enable for this pdu*/
    COM_TXPDU_TIMEOUT(TxIpduId) = COM_TIMER_STOP_VAL;/*SWS_Com_00787-2*/
#endif


#if(STD_ON == COM_TriggerIPDUSend_API)
    Com_TriggerPDUSendFlag[TxIpduId] = FALSE;
#endif


#if((STD_ON == COM_TX_FILTER_SUPPORT) && (COM_MAX_FILTER_OCCURRENCE_NUM > 0))
    Com_InitTxOccOfPdu(TxIpduId);/*SWS_Com_00787-4*/
#endif

    /* if InitFlag = false, the value write when pdu stop will keep ,alsp the updatebit and Com_SendSwitchTxModeFlag will keep
       so that the TMS will be caculated in next mainfunctiontx
    */

    if((TRUE == isStartFlag) && (TRUE == InitFlag))
    {
        /*TxMode Init*/

        COM_TXPDU_TMS_FLAG(TxIpduId) = TRUE;
        Com_SendSwitchTxModeFlag[TxIpduId] = COM_NO_TXMODE_SWITCH;

        COM_TXPDU_TXMODE_PTR(TxIpduId) = COM_CFG_TXPDU_TXMODE_TRUE_PTR(TxIpduId);

        /*Pdu Data Length Init SWS_Com_00222 -1-2-3*/
        Com_InitTxPduValue(TxIpduId);

    }

    if(FALSE == isStartFlag)
    {
        Com_TxPduState[TxIpduId] = COM_TXPDU_STOP;/*SWS_Com_444 all group stop at Init*/
    }
    else
    {
        Com_TxPduState[TxIpduId] = COM_TXPDU_START_IDLE;/*SWS_Com_114*/
    }

}



/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CbkTxErrAck_PDU
*
* Description:   Called when Pdu is Stoped, but msg is onGoing
*
* Inputs:        TxIpduId
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_TX_SIGNAL_ERR_FUNC_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_CbkTxErrAck_PDU
(
    PduIdType TxIpduId
)
{

    Com_SignalIdType TxSigId = (Com_SignalIdType)0;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType SignalGroupId = (Com_SignalGroupIdType)0;
#endif


    for(TxSigId = COM_CFG_TXPDU_SIG_START_NUM(TxIpduId);
            TxSigId <= COM_CFG_TXPDU_SIG_STOP_NUM(TxIpduId);
            TxSigId++)
    {
        if(NULL_PTR != COM_CFG_TXSIG_TXERR_FUN(TxSigId))
        {
            COM_CFG_TXSIG_TXERR_FUN(TxSigId)();
        }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
        if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(TxSigId))
        {
            SignalGroupId = COM_CFG_TXSIG_GET_SIGGROUPID(TxSigId);
            /* set sigId to the end of this group, 1 group only ack once */
	  /*PRQA S 2469 ++*/
            /*
            Loop control variable can be modified in this case.
            */
            TxSigId = COM_CFG_TXSIGGRP_SIGSTOP(SignalGroupId);
            /*PRQA S 2469 --*/
        }
#endif


    }
}
#endif

#endif/* #if(STD_ON == COM_IPDU_GROUP_FUN)*/



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_TxInit
*
* Description:   Tx initialize.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_TxInit
(
    void
)
{

    PduIdType IpduIndex = (PduIdType)0;

    for(IpduIndex = (PduIdType)0; IpduIndex < COM_TXPDU_NUM; IpduIndex++)
    {
#if (STD_ON == COM_IPDU_GROUP_FUN)
        if(TRUE == COM_CFG_TXPDUGROUP_FLAG(IpduIndex))
        {
            Com_InitTxPdu(IpduIndex, FALSE);
        }
        else
#endif
        {
            Com_InitTxPdu(IpduIndex, TRUE);
        }
    }
}


/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_GetTMSResult
*
* Description:   get tms result when tx sig updated
*
* Inputs:        TxIpduId: Ipdu Id
*
* Outputs:       boolean
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == COM_TX_FILTER_SUPPORT)
STATIC FUNC(boolean, COM_CODE) Com_GetTMSResult
(
    PduIdType TxIpduId
)
{

    Com_SignalIdType Index;
    boolean Result = FALSE;
    P2VAR(uint8, AUTOMATIC, COM_CONST) tmpTxFilterPtr = NULL_PTR;

    tmpTxFilterPtr = COM_CFG_TXPDU_FILTER_PTR(TxIpduId);
    for(Index = (Com_SignalIdType)0; Index < COM_CFG_TXPDU_FILTER_SIZE(TxIpduId); Index++)
    {
        if((uint8)0 != tmpTxFilterPtr[Index])
        {
            Result = TRUE;
            break;
        }
    }

    return Result;
}
#endif


/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_SelectPduTxMode
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_SelectPduTxMode
(
    PduIdType TxIpduId,
    uint8 TxSendSwitchTxModeFlag
)
{
#if (STD_ON == COM_TX_FILTER_SUPPORT)
    boolean CurrentTMSResult = FALSE;
#endif
    boolean result = FALSE;

    if(COM_NO_TXMODE_SWITCH != TxSendSwitchTxModeFlag)
    {
#if (STD_ON == COM_TX_FILTER_SUPPORT)
        if(COM_TXMODE_SWITCH_SEND_SIGNAL == TxSendSwitchTxModeFlag)
        {
            CurrentTMSResult = Com_GetTMSResult(TxIpduId);
        }
        if(((COM_TXMODE_SWITCH_SEND_SIGNAL == TxSendSwitchTxModeFlag)
                && (FALSE == CurrentTMSResult))
                || (COM_TXMODE_SWITCH_API_FALSE == TxSendSwitchTxModeFlag))
#else
        if(COM_TXMODE_SWITCH_API_FALSE == TxSendSwitchTxModeFlag)
#endif
        {
            /* SWS_Com_799 TMS true->false*/
            if((TRUE == COM_TXPDU_TMS_FLAG(TxIpduId))&&(NULL_PTR != COM_CFG_TXPDU_TXMODE_FALSE_PTR(TxIpduId)))
            {
                COM_TXPDU_TXMODE_PTR(TxIpduId) = COM_CFG_TXPDU_TXMODE_FALSE_PTR(TxIpduId);
                COM_TXPDU_TMS_FLAG(TxIpduId) = FALSE;
                result = TRUE;
            }
        }
        else
        {
            /* SWS_Com_032 TMS false->true*/
            if((FALSE == COM_TXPDU_TMS_FLAG(TxIpduId))&&(NULL_PTR != COM_CFG_TXPDU_TXMODE_TRUE_PTR(TxIpduId)))
            {
                COM_TXPDU_TXMODE_PTR(TxIpduId) = COM_CFG_TXPDU_TXMODE_TRUE_PTR(TxIpduId);
                COM_TXPDU_TMS_FLAG(TxIpduId) = TRUE;
                result = TRUE;
            }
        }
    }

    /* Mode Switch, reset all mode AttriButes*/
    /* should not clear occ counter here, as it may cause mode swith back*/
    /* dont clear Com_PDUTrigRepFlag as the request need be process at  once after mode switch */

    if(TRUE == result)
    {
        COM_TXPDU_PERIOD(TxIpduId) = COM_TIMER_STOP_VAL;/* STOP Val will cause period Msg tx at once in this cycle */
        COM_TXPDU_TXTIME_OFFSET(TxIpduId) = COM_TXPDU_TXMODE_PTR(TxIpduId)->TxModeTimeOffset; /*SWS_Com_00495 set new offset as mode may be changed in offset time segment*/
#if (STD_ON == COM_MDT_CYCLIC_TRANSMISSION)
        /*COM_TXPDU_MIN_DELAY_TIMER(TxIpduId) = COM_TIMER_STOP_VAL;  do not reset mindelay when mode switch SWS_Com_00495*/
        COM_TXPDU_TX_REQ_MINDELAY_BACKUP(TxIpduId) = FALSE;

#endif

#if (STD_ON == COM_TXMODE_REPTITION)
        COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_TIMER_STOP_VAL;
        COM_TXPDU_REP_NUM(TxIpduId) = (uint8)0;
        COM_TXPDU_REQ_CONF_NUM(TxIpduId) = (uint8)0;
#endif

#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
        COM_TXPDU_TIMEOUT(TxIpduId) = COM_TIMER_STOP_VAL;
#endif

#if(STD_ON == COM_TX_LONG_PDU_FUN)
        COM_TXPDU_TP_INDEX(TxIpduId) = (PduLengthType)0;
#endif
        Com_TxPduState[TxIpduId] = COM_TXPDU_START_IDLE;/* return idle if state is busy or RETX, SWS_Com_00773 is not affected by transmission mode changes.*/


    }
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_StartTxDeadlineMotitor
*
* Description:   start deadlne monitor when sendreq is set
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
STATIC FUNC(void, COM_CODE) Com_StartTxDeadlineMotitor
(
    PduIdType TxIpduId,
    boolean needRestartTimer
)
{
    if(TRUE == COM_CFG_TXPDU_TIMEOUT_MONITOR_FLAG(TxIpduId))
    {
        if((COM_TIMER_STOP_VAL == COM_TXPDU_TIMEOUT(TxIpduId))
                || (TRUE == needRestartTimer))
        {
            COM_TXPDU_TIMEOUT(TxIpduId) = COM_CFG_TXPDU_PERIOD_TIMEOUT(TxIpduId);
        }
    }

}
#endif


/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleDirect
*
* Description:   process the tx Msg in Direct Mode
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
STATIC FUNC(uint8, COM_CODE) Com_HandleDirect
(
    PduIdType TxIpduId
)
{
    uint8 result = COM_EVENT_TX_NONE;

    if(COM_TRIGGER == Com_PDUTrigRepFlag[TxIpduId])
    {
        result = COM_EVENT_TX_ONCE;
#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
        Com_StartTxDeadlineMotitor(TxIpduId, FALSE);
#endif

    }
#if(STD_ON == COM_TXMODE_REPTITION)
    else if(COM_TRIGGER_REP == Com_PDUTrigRepFlag[TxIpduId])
    {
        /* SWS_Com_00279 anytime get rep triger, reset all rep counter */
        result = COM_EVENT_TX_REP;
        if(COM_TXPDU_TXMODE_REP_NUM(TxIpduId) > (uint8)0)
        {
            COM_TXPDU_REP_NUM(TxIpduId) = COM_TXPDU_TXMODE_REP_NUM(TxIpduId);/*SWS_Com_00305  ComTxModeNumberOfRepetitions + 1*/
        }
        else
        {
            COM_TXPDU_REP_NUM(TxIpduId) = (uint8)0;
        }

        COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_TXPDU_TXMOD_REP_PERIOD(TxIpduId);
        /*SWS_Com_00305  ComTxModeNumberOfRepetitions + 1*/
        COM_TXPDU_REQ_CONF_NUM(TxIpduId) = COM_TXPDU_TXMODE_REP_NUM(TxIpduId) + (uint8)1;
#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
        Com_StartTxDeadlineMotitor(TxIpduId, TRUE);/*SWS_Com_00739, restart deadline monitor, when new trigger is get */
#endif

    }
    else
    {
        /* no new trigger*/
        if((uint8)0 != COM_TXPDU_REP_NUM(TxIpduId))
        {
            result = COM_EVENT_NOTX_REP;
            if( COM_TXPDU_PERIOD_BACKUP(TxIpduId) > (uint16)0)
            {
                COM_TXPDU_PERIOD_BACKUP(TxIpduId)--;
            }

            if((uint16)0 == COM_TXPDU_PERIOD_BACKUP(TxIpduId))
            {
                COM_TXPDU_REP_NUM(TxIpduId)--;
                if((uint8)0 != COM_TXPDU_REP_NUM(TxIpduId))
                {
                    COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_TXPDU_TXMOD_REP_PERIOD(TxIpduId);
                }
                else
                {
                    COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_TIMER_STOP_VAL;
                }

                result = COM_EVENT_TX_REP;
            }
        }
    }
#endif
    Com_PDUTrigRepFlag[TxIpduId] = COM_NO_TRIGGER;

    return result;

}
#endif

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandlePeriod
*
* Description:   process the tx Msg in Period Mode
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if((STD_ON == COM_TXMODE_PERIODIC) || (STD_ON == COM_TXMODE_MIXED))
STATIC FUNC(boolean, COM_CODE) Com_HandlePeriod
(
    PduIdType TxIpduId
)
{
    boolean sendFlag = FALSE;

    if((uint16)0 == COM_TXPDU_TXTIME_OFFSET(TxIpduId))
    {
        if(COM_TIMER_STOP_VAL == COM_TXPDU_PERIOD(TxIpduId))
        {
            /* first start, Init period = 0, Send 1 frame at once */
            COM_TXPDU_PERIOD(TxIpduId) = (uint16)0;
        }

        if(COM_TXPDU_PERIOD(TxIpduId) > (uint16)0)
        {
            COM_TXPDU_PERIOD(TxIpduId)--;
        }

        if((uint16)0 == COM_TXPDU_PERIOD(TxIpduId))
        {
            COM_TXPDU_PERIOD(TxIpduId) = COM_TXPDU_TXMODE_PERIOD(TxIpduId);
            sendFlag = TRUE;
#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
            Com_StartTxDeadlineMotitor(TxIpduId, FALSE);
#endif
        }

    }
    if(COM_TXPDU_TXTIME_OFFSET(TxIpduId) > (uint16)0)
    {
        COM_TXPDU_TXTIME_OFFSET(TxIpduId)--;
    }
    return sendFlag;

}
#endif


/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleMixed
*
* Description:   process the tx Msg in mix Mode
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_TXMODE_MIXED)
STATIC FUNC(boolean, COM_CODE) Com_HandleMixed
(
    PduIdType TxIpduId
)
{
    /*
        mix mode 1: when overlap , stop period counter, only process tigger event. period will not restart until rep tx end
        mix mode 2: when overlap , keep running period counter, period request will consider as  triger
        mix mode 3 not support yet : when overlap , keep running period counter,  process triger and period only with limit of MDT
    */

    uint8 triggerSendFlag = COM_EVENT_TX_NONE;
    boolean result = FALSE;

    if((uint16)0 == COM_TXPDU_TXTIME_OFFSET(TxIpduId))
    {
        triggerSendFlag = Com_HandleDirect(TxIpduId);

#if(STD_ON == COM_FIRST_HANDLE_MIXED)
        /* rep or trigger is active, normal cycle is stop */
        if(triggerSendFlag != COM_EVENT_TX_NONE)
        {
            COM_TXPDU_PERIOD(TxIpduId) = COM_TXPDU_TXMODE_PERIOD(TxIpduId);
            if(triggerSendFlag > COM_EVENT_NOTX_REP)
            {
                result = TRUE;
            }
        }
        else
        {
            result = Com_HandlePeriod(TxIpduId);

        }
#endif

#if (STD_ON == COM_SECOND_HANDLE_MIXED)/* 2nd options  SWS_Com_00494*/
        /* rep or trigger is active, normal cycle is running but ignor send request */
        if(triggerSendFlag != COM_EVENT_TX_NONE)
        {
            (void)Com_HandlePeriod(TxIpduId);
            if(triggerSendFlag > COM_EVENT_NOTX_REP)
            {
                result = TRUE;
            }
        }
        else
        {
            result = Com_HandlePeriod(TxIpduId);
        }
#endif
    }
    else
    {
        COM_TXPDU_TXTIME_OFFSET(TxIpduId)--;
    }
    /*save trigger info before offset arrived, it may cause multipul transmission */
    /*Com_PDUTrigRepFlag[TxIpduId] = (uint8)0;*/
    return result;


}
#endif

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleNone
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_TXMODE_NONE)
STATIC FUNC(void, COM_CODE) Com_HandleNone
(
    PduIdType TxIpduId
)
{
#if(STD_OFF == COM_TX_TIMEOUT_MONITOR)
    (void)TxIpduId;
#endif
    /* None only, Start tx deadline motitor  SWS_Com_00696
       not none only, stop tx deadline motitor  SWS_Com_00835

       so that, lin  signals can be monitored by com

       this use false_ptr = null , to define the pdu has none mode only

    */
#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
    if(NULL_PTR == COM_CFG_TXPDU_TXMODE_FALSE_PTR(TxIpduId))
    {
        Com_StartTxDeadlineMotitor(TxIpduId, FALSE);
    }
    else
    {
        COM_TXPDU_TIMEOUT(TxIpduId) = COM_TIMER_STOP_VAL;

    }
#endif


}
#endif



#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CheckTxSigIfActive
*
* Description:   if active, set target pdu flag bit active, other wise clear target pdu flag bit
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_CheckTxSigIfActive
(
    PduIdType TxIpduId,
    Com_SignalIdType TxSigId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) newDataPtr,
    P2CONST(void, AUTOMATIC, COM_CONST)     cfgInActiveValPtr
)
{
    Com_SigType type  = COM_CFG_TXSIG_TYPE(TxSigId);
    boolean flag = FALSE;
    PduLengthType sigIdx = (PduLengthType)0;

    if(((COM_CFG_TXSIG_TRANSPROPERTY(TxSigId) == COM_IFACTIVE_SIG) || (COM_CFG_TXSIG_TRANSPROPERTY(TxSigId) == COM_IFACTIVE_ON_CHANGE_SIG))
        && (COM_TXPDU_TXMODE(TxIpduId) == COM_IFACTIVE_PDU)
        &&(COM_CFG_TXSIG_INACTIVE_OFFSET(TxSigId)!= COM_INVALID_IFACTIVE_OFFSET_VALUE)
        &&(cfgInActiveValPtr != NULL_PTR)
        &&(newDataPtr != NULL_PTR))
    {
        switch(type)
        {
        case COM_SIG_U8:
            if(*(uint8 *)newDataPtr != * (uint8 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_U16:
            if(*(uint16 *)newDataPtr != * (uint16 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_U32:
            if(*(uint32 *)newDataPtr != * (uint32 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_BOOLEAN:
            if(*(boolean *)newDataPtr != * (boolean *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_S8:
            if(*(sint8 *)newDataPtr != * (sint8 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_S16:
            if(*(sint16 *)newDataPtr != * (sint16 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_S32:
            if(*(sint32 *)newDataPtr != * (sint32 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_F32:
            if(*(float32 *)newDataPtr != * (float32 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_U64:
            if(*(uint64 *)newDataPtr != * (uint64 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;
        case COM_SIG_S64:
            if(*(sint64 *)newDataPtr != * (sint64 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;

        case COM_SIG_F64:
            if(*(float64 *)newDataPtr != * (float64 *)cfgInActiveValPtr)
            {
                flag = TRUE;
            }
            break;

        case COM_SIG_U8N:
            for(sigIdx = (PduLengthType)0; sigIdx < COM_CFG_TXSIG_LENGTH(TxSigId); sigIdx++)
            {
                if( ((uint8*)newDataPtr)[sigIdx] != ((uint8*)cfgInActiveValPtr)[sigIdx])
                {
                    flag = TRUE;
                    break;
                }
            }
            break;
        /*DYN not support */

        default:
            break;
        }

        if(flag == TRUE)
        {
            COM_TXPDU_IFACTIVE_FLAG(TxIpduId) |= (uint32)((uint8)1 << COM_CFG_TXSIG_INACTIVE_OFFSET(TxSigId));
        }
        else
        {
            COM_TXPDU_IFACTIVE_FLAG(TxIpduId) &= (uint32)(~((uint8)1 << COM_CFG_TXSIG_INACTIVE_OFFSET(TxSigId)));
        }
    }
}



/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleIfActive
*
* Description:
*
* Inputs:        None
*
* Outputs:       boolean pdu send, false pdu not send
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(boolean, COM_CODE) Com_HandleIfActive
(
    PduIdType TxIpduId
)
{
    boolean result = FALSE;
    if(TRUE == COM_CFG_TXPDU_IS_INACTIVE_CYCLIC(TxIpduId))
    {
        if(COM_TXPDU_TXTIME_OFFSET(TxIpduId) == (uint16)0)
        {
            if(((uint32)0 == COM_TXPDU_IFACTIVE_FLAG(TxIpduId)) && (COM_TXPDU_REP_NUM(TxIpduId) == (uint8)0))
            {
                if(COM_TIMER_STOP_VAL == COM_TXPDU_PERIOD(TxIpduId))
                {
                    COM_TXPDU_PERIOD(TxIpduId) = (uint16)0;
                }
                if(COM_TXPDU_PERIOD(TxIpduId) > (uint16)0)
                {
                    COM_TXPDU_PERIOD(TxIpduId)--;
                }
                if((uint16)0 == COM_TXPDU_PERIOD(TxIpduId))
                {
                    COM_TXPDU_PERIOD(TxIpduId) = COM_TXPDU_TXMODE_PERIOD(TxIpduId);
                    COM_TXPDU_PERIOD_BACKUP(TxIpduId) = (uint16)0;
                    result = TRUE;
#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
                    Com_StartTxDeadlineMotitor(TxIpduId, FALSE);
#endif
                }
            }
            else
            {
                if(COM_TIMER_STOP_VAL == COM_TXPDU_PERIOD_BACKUP(TxIpduId))
                {
                    COM_TXPDU_PERIOD_BACKUP(TxIpduId) = (uint16)0;
                }
                if(TRUE == COM_TXPDU_IFACTIVE_CHANGE_FLAG(TxIpduId))
                {
                    COM_TXPDU_PERIOD_BACKUP(TxIpduId) = (uint16)0;
                    COM_TXPDU_IFACTIVE_CHANGE_FLAG(TxIpduId) = FALSE;
                }
                if(COM_TXPDU_PERIOD_BACKUP(TxIpduId) > (uint16)0)
                {
                    COM_TXPDU_PERIOD_BACKUP(TxIpduId)--;
                }
                if((uint16)0 == COM_TXPDU_PERIOD_BACKUP(TxIpduId))
                {
                    COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_TXPDU_TXMOD_REP_PERIOD(TxIpduId);
                    COM_TXPDU_PERIOD(TxIpduId) = (uint16)0;
                    result = TRUE;
#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
                    Com_StartTxDeadlineMotitor(TxIpduId, FALSE);
#endif
                    if((uint32)0 != COM_TXPDU_IFACTIVE_FLAG(TxIpduId))
                    {
                        COM_TXPDU_REP_NUM(TxIpduId) = COM_TXPDU_TXMODE_REP_NUM(TxIpduId);
                    }
                    else
                    {
                        if(COM_TXPDU_REP_NUM(TxIpduId) > (uint8)0)
                        {
                            COM_TXPDU_REP_NUM(TxIpduId)--;
                        }
                    }
                }
            }
        }
        if(COM_TXPDU_TXTIME_OFFSET(TxIpduId) > (uint16)0)
        {
            COM_TXPDU_TXTIME_OFFSET(TxIpduId)--;
        }
    }
    else
    {
        if(((uint32)0 == COM_TXPDU_IFACTIVE_FLAG(TxIpduId)) && (COM_TXPDU_REP_NUM(TxIpduId) == (uint8)0))
        {
            /* inactive mode and no rep number, do nothing, just set period to stop value*/
            COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_TIMER_STOP_VAL;
        }
        else
        {
            /* if-active mode do not send out when init, so dont check time offset here */
            /* actvive or rep>0. need to count the period */
            if(COM_TIMER_STOP_VAL == COM_TXPDU_PERIOD_BACKUP(TxIpduId))
            {
                /* first start, Init period = 0, Send 1 frame at once */
                COM_TXPDU_PERIOD_BACKUP(TxIpduId) = (uint16)0;
            }
            if(TRUE == COM_TXPDU_IFACTIVE_CHANGE_FLAG(TxIpduId))
            {
                COM_TXPDU_PERIOD_BACKUP(TxIpduId) = (uint16)0;
                COM_TXPDU_IFACTIVE_CHANGE_FLAG(TxIpduId) = FALSE;
            }
            if(COM_TXPDU_PERIOD_BACKUP(TxIpduId) > (uint16)0)
            {
                COM_TXPDU_PERIOD_BACKUP(TxIpduId)--;
            }

            if((uint16)0 == COM_TXPDU_PERIOD_BACKUP(TxIpduId))
            {
                COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_TXPDU_TXMOD_REP_PERIOD(TxIpduId);
                result = TRUE;
#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
                Com_StartTxDeadlineMotitor(TxIpduId, FALSE);
#endif
                if((uint32)0 != COM_TXPDU_IFACTIVE_FLAG(TxIpduId)) /* active mode */
                {
                    /*when active, keep rep num as init value */
                    COM_TXPDU_REP_NUM(TxIpduId) = COM_TXPDU_TXMODE_REP_NUM(TxIpduId);
                }
                else /* inacive mode*/
                {
                    if(COM_TXPDU_REP_NUM(TxIpduId) > (uint8)0)
                    {
                        COM_TXPDU_REP_NUM(TxIpduId)--;
                        if(COM_TXPDU_REP_NUM(TxIpduId) == (uint8)0)
                        {
                            COM_TXPDU_PERIOD_BACKUP(TxIpduId) = COM_TIMER_STOP_VAL;
                        }
                    }
                    
                }

            }
        }
    }
    return result;


}
#endif

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_TxModeProcess
*
* Description:   Called in MainTx, decide if the Pdu can be send out this cycle
*
* Inputs:        TxIpduId,TxIPDUTrigRepFlag
*
* Outputs:       TRUE: PDU need to be sendout
*                  FALSE: PDU need not to be sendout
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_TxModeProcess
(
    PduIdType TxIpduId
)
{

    boolean sendFlag = FALSE;

    /* SWS_Com_239   new tx Mode will be used at once*/
    switch(COM_TXPDU_TXMODE(TxIpduId))
    {
#if    (STD_ON == COM_TXMODE_DIRECT)
    case COM_DIRECT:
        if(Com_HandleDirect(TxIpduId) > COM_EVENT_NOTX_REP)/* COM_EVENT_TX_ONCE or COM_EVENT_TX_REP*/
        {
            sendFlag = TRUE;
        }
        break;
#endif

#if    (STD_ON == COM_TXMODE_PERIODIC)
    case COM_PERIODIC:
        sendFlag = Com_HandlePeriod(TxIpduId);
        break;
#endif

#if    (STD_ON == COM_TXMODE_MIXED)
    case COM_MIXED:
        sendFlag = Com_HandleMixed(TxIpduId);
        break;
#endif

#if    (STD_ON == COM_TXMODE_NONE)
    case COM_PDU_NONE:
        Com_HandleNone(TxIpduId);
        break;
#endif

#if    (STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
    case COM_IFACTIVE_PDU:
    	sendFlag = Com_HandleIfActive(TxIpduId);
        break;
#endif


    default:
        /* NONE */
        break;

    }

    /* other reason may enable tx request */
#if (STD_ON == COM_TriggerIPDUSend_API)
    if(TRUE == Com_TriggerPDUSendFlag[TxIpduId])
    {
        sendFlag = TRUE;
        Com_TriggerPDUSendFlag[TxIpduId] = FALSE;
    }
#endif

#if (STD_ON == COM_RETRY_TRANSMIT_REQUESTS)
    if(COM_TXPDU_START_RETX == Com_TxPduState[TxIpduId])
    {
        sendFlag = TRUE;
    }
#endif

#if (STD_ON == COM_MDT_CYCLIC_TRANSMISSION)
    if(TRUE == COM_TXPDU_TX_REQ_MINDELAY_BACKUP(TxIpduId))
    {
        sendFlag = TRUE;
        COM_TXPDU_TX_REQ_MINDELAY_BACKUP(TxIpduId) = FALSE;
    }
#endif

    return sendFlag;
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_TransmitPdu
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_TransmitPdu
(
    PduIdType TxIpduId
)
{


    PduInfoType PduInfo;
    Std_ReturnType txReqResult = E_NOT_OK;

#if (COM_TXIPDU_CALLOUT == STD_ON)
    boolean TxIpduCalloutResultFlag = TRUE;
#endif


    PduInfo.SduDataPtr = (SduDataPtrType)COM_CFG_TXPDU_DATA_PTR(TxIpduId);
    PduInfo.SduLength = COM_CFG_TXPDU_LENGTH(TxIpduId);
#if (COM_TX_DYN_PDU_SUPPORT == STD_ON)
    if(TRUE == COM_CFG_TXPDU_IS_DYN(TxIpduId))
    {
        PduInfo.SduLength = COM_TXPDU_DYN_LENGTH(TxIpduId);
    }
#endif

#if(STD_ON == COM_MetaDataSupport)
    if(E_OK == Ecuc_CheckMetaDataSupport(COM_CFG_TXPDU_GLOBAL_PDUID(TxIpduId), ECUC_ENUM_ANYONE_ACT))
    {
        (void)Com_GetMetadata(TxIpduId, PduInfo.MetaDataPtr);
    }
#endif

#if (COM_TXIPDU_CALLOUT == STD_ON)
    if(NULL_PTR != COM_CFG_TXPDU_CALLOUT(TxIpduId))
    {
        TxIpduCalloutResultFlag = COM_CFG_TXPDU_CALLOUT(TxIpduId)(TxIpduId, &PduInfo);/*SWS_Com_00492*/
    }

    if(TRUE == TxIpduCalloutResultFlag)
#endif
    {
        /*SWS_Com_00138 759 760*/
        txReqResult = PduR_UpCallTransmit(COM_CFG_TXPDU_MAP_PDUR(TxIpduId), &PduInfo);

        if(E_OK == txReqResult)
        {
#if(COM_TX_UPDATEBIT_SUPPORT == STD_ON)
            if(COM_CUB_TX == COM_CFG_TXPDU_UPDATEBIT_CLEARTYPE(TxIpduId))
            {
                Com_ClearUpdateBit(TxIpduId);
            }
#endif

            Com_TxPduState[TxIpduId] = COM_TXPDU_START_BUSY;
#if(STD_ON == COM_TX_LONG_PDU_FUN)
            COM_TXPDU_TP_INDEX(TxIpduId) = (PduLengthType)0;
#endif

#if(STD_ON == COM_MDT_CYCLIC_TRANSMISSION)
            if(COM_CFG_TXPDU_MIN_DELAY_TIMER(TxIpduId) > (uint16)0)
            {
                COM_TXPDU_MIN_DELAY_TIMER(TxIpduId) = COM_CFG_TXPDU_MIN_DELAY_TIMER(TxIpduId);/* start MDT*/
            }
#endif
        }
        else
        {
#if(STD_ON == COM_RETRY_TRANSMIT_REQUESTS)/*SWS_Com_00698 828 */
            /* if PduR_UpCallTransmit retrun notok, and last msg is not finish,
               new txReq will be ignor, keep sending last msg
            */
            if(COM_TXPDU_START_BUSY != Com_TxPduState[TxIpduId])
            {
                Com_TxPduState[TxIpduId] = COM_TXPDU_START_RETX;
            }
#else
            Com_ProcessTxConf(TxIpduId, COM_TXPDU_START_TXNOTOK);/*consider it as tx not ok*/
#endif
        }
    }

}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CbkTxTOut_PDU
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
STATIC FUNC(void, COM_CODE) Com_CbkTxTOut_PDU
(
    PduIdType TxIpduId
)
{

    Com_SignalIdType SigId = (Com_SignalIdType)0;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType SignalGroupId = (Com_SignalGroupIdType)0;
#endif



    for(SigId = COM_CFG_TXPDU_SIG_START_NUM(TxIpduId);
            SigId <= COM_CFG_TXPDU_SIG_STOP_NUM(TxIpduId);
            SigId++)
    {

        if(NULL_PTR != COM_CFG_TXSIG_TXTOINDICATION_FUN(SigId))
        {
            COM_CFG_TXSIG_TXTOINDICATION_FUN(SigId)();
        }

#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
        if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(SigId))
        {
            SignalGroupId = COM_CFG_TXSIG_GET_SIGGROUPID(SigId);
            /* set sigId to the end of this group, 1 group only ack once */
            SigId = COM_CFG_TXSIGGRP_SIGSTOP(SignalGroupId);
        }
#endif

    }
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_TxTimerOutMonitor
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_TxTimerOutMonitor
(
    PduIdType TxIpduId
)
{

    if((TRUE == COM_CFG_TXPDU_TIMEOUT_MONITOR_FLAG(TxIpduId))
            && (COM_TIMER_STOP_VAL != COM_TXPDU_TIMEOUT(TxIpduId)))
    {
        /*SWS_Com_00445 */
        if((uint16)0 != COM_TXPDU_TIMEOUT(TxIpduId))
        {
            COM_TXPDU_TIMEOUT(TxIpduId)--;
        }

        if((uint16)0 == COM_TXPDU_TIMEOUT(TxIpduId))
        {
#if(STD_ON == COM_CANCEL_SUPPORT)
            if(TRUE == COM_CFG_TXPDU_CANCEL_TRANSMIT_FLAG(TxIpduId))
            {
                (void)PduR_UpCallCancelTransmit(COM_CFG_TXPDU_MAP_PDUR(TxIpduId));/*SWS_Com_00708*/
            }
#endif

            COM_TXPDU_TIMEOUT(TxIpduId) = COM_TIMER_STOP_VAL;
            Com_TxPduState[TxIpduId] = COM_TXPDU_START_IDLE;/* SWS_Com_00775no Tx any more*/
#if(STD_ON == COM_TXMODE_REPTITION)
            COM_TXPDU_REQ_CONF_NUM(TxIpduId) = (uint8)0;
            COM_TXPDU_REP_NUM(TxIpduId) = (uint8)0;/*SWS_Com_00392 ignor rest repetition tx*/
#endif

#if (STD_ON == COM_MDT_CYCLIC_TRANSMISSION)
            COM_TXPDU_MIN_DELAY_TIMER(TxIpduId) = COM_TIMER_STOP_VAL;/* SWS_Com_00812 Stop MDT if TxTimeout */
#endif

            /*SWS_Com_00812 do not reset Pengding txRequest, when txTimeout,
              like COM_TXPDU_TX_REQ_BACKUP  COM_TXPDU_TX_REQ_MINDELAY_BACKUP
            */

#if(STD_ON == COM_TX_LONG_PDU_FUN)
            COM_TXPDU_TP_INDEX(TxIpduId) = (PduLengthType)0;
#endif


            Com_CbkTxTOut_PDU(TxIpduId);/*SWS_Com_00304*/

        }
    }
}
#endif
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CbkTxAck_PDU
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_TX_SIGNAL_ACK_FUNC_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_CbkTxAck_PDU
(
    PduIdType TxIpduId
)
{

    Com_SignalIdType TxSigId = (Com_SignalIdType)0;

#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType SignalGroupId = (Com_SignalGroupIdType)0;
#endif

    for(TxSigId = COM_CFG_TXPDU_SIG_START_NUM(TxIpduId);
            TxSigId <= COM_CFG_TXPDU_SIG_STOP_NUM(TxIpduId);
            TxSigId++)
    {
        if(NULL_PTR != COM_CFG_TXSIG_CBKTXACK_FUN(TxSigId))
        {
            COM_CFG_TXSIG_CBKTXACK_FUN(TxSigId)();
        }

#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
        if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(TxSigId))
        {
            SignalGroupId = COM_CFG_TXSIG_GET_SIGGROUPID(TxSigId);
            /* set sigId to the end of this group, 1 group only ack once */
            /*PRQA S 2469 ++*/
            /*
            Loop control variable can be modified in this case.
            */
            TxSigId = COM_CFG_TXSIGGRP_SIGSTOP(SignalGroupId);
            /*PRQA S 2469 --*/
        }
#endif




    }
}
#endif


/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ProcessTxConf
*
* Description:   process tx confirmation
*
* Inputs:        TxIpduId,pduState
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_ProcessTxConf
(
    PduIdType TxIpduId,
    Com_TxPduStateType pduState
)
{
    Com_TxPduStateType tmpState = pduState;

#if(STD_ON == COM_TX_CONFIRMATION_CALLOUT_SUPPORT)
    if(pduState == COM_TXPDU_START_TXOK)
    {
        Com_E2E_TxConfirmationCallout(TxIpduId);
    }
#endif
#if(STD_ON == COM_TXMODE_REPTITION)
    /* if notok, the error confirmation dont count*/
    /* confnum <= repnum, means unexpected frame may insert to repetition transmission, like tx from Com_TriggerIPDUSend, in this case, this confirmation dont count*/
    if((tmpState == COM_TXPDU_START_TXOK)
        && (COM_TXPDU_REQ_CONF_NUM(TxIpduId) > COM_TXPDU_REP_NUM(TxIpduId)))/* this also cover the COM_TXPDU_REQ_CONF_NUM(TxIpduId) > 0, as repnum is unsigned*/
    {
        COM_TXPDU_REQ_CONF_NUM(TxIpduId)--;
    }
    if((uint8)0 == COM_TXPDU_REP_NUM(TxIpduId))
    {
        if(COM_TXPDU_REQ_CONF_NUM(TxIpduId) > (uint8)0)
        {
            COM_TXPDU_REQ_CONF_NUM(TxIpduId) = (uint8)0;
            COM_TXPDU_REP_NUM(TxIpduId) = (uint8)0;
            /*rep = 0, but confrep > 0 means lost txconf  */
            tmpState = COM_TXPDU_START_TXNOTOK;
        }
    }
#endif

    if(tmpState == COM_TXPDU_START_TXOK)
    {
#if(STD_ON == COM_TX_SIGNAL_ACK_FUNC_SUPPORT)
        Com_CbkTxAck_PDU(TxIpduId);
#endif
    }
    else
    {
#if(STD_ON == COM_TX_SIGNAL_ERR_FUNC_SUPPORT)
#if(STD_ON == COM_IPDU_GROUP_FUN)
        Com_CbkTxErrAck_PDU(TxIpduId);
#endif
#endif
    }

#if(COM_TX_TIMEOUT_MONITOR == STD_ON)
    /* Stop Tx Time out monitor*/
    /*SWS_Com_00308, rep txpdu, deadline is stopped when all rep is send out*/
    if(TRUE == COM_CFG_TXPDU_TIMEOUT_MONITOR_FLAG(TxIpduId))
    {
        COM_TXPDU_TIMEOUT(TxIpduId) = COM_TIMER_STOP_VAL;
    }
#endif

    Com_TxPduState[TxIpduId] = COM_TXPDU_START_IDLE;

}



#endif/*#if(STD_ON == COM_TXPDU_FUN)*/

#if(STD_ON == COM_RXPDU_FUN)


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_CheckRxLength
*
* Description:   check if rx length is valid
*
* Inputs:        RxPduId,length
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_CheckRxLength
(
    PduIdType RxPduId,
    PduLengthType length
)
{
    boolean ret = FALSE;

    /*length check */ /*SWS_Com_00574*/
#if (STD_ON == COM_PADDING_SUPPORT)
    if(length <= COM_CFG_RXPDU_LENGTH(RxPduId))
    {
        ret = TRUE;
    }
#else

#if (STD_ON == COM_RX_DYN_PDU_SUPPORT)
    if(TRUE == COM_CFG_RXPDU_IS_DYN(RxPduId))
    {
        if((length <= COM_CFG_RXPDU_LENGTH(RxPduId)) && (length >= COM_CFG_RXPDU_FIX_LENGTH(RxPduId)))
        {
            ret = TRUE;
        }
    }
    else
#endif
    {
        if(length == COM_CFG_RXPDU_LENGTH(RxPduId))
        {
            ret = TRUE;
        }
    }
#endif/* #if (STD_ON == COM_PADDING_SUPPORT) */

    return ret;

}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_CheckSigUpdateBit
*
* Description:   This service check if rx  signal's update bit is set
*
* Inputs:        RxIpduId, index
*
* Outputs:       boolean
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_RX_UPDATEBIT_SUPPORT)
STATIC FUNC(boolean, COM_CODE) Com_CheckSigUpdateBit
(
    PduIdType RxIpduId,
    Com_SignalIdType index,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    boolean ret = FALSE;
    PduLengthType tempByteIndex = COM_CFG_RXPDU_UPDATEBIT_INFO(RxIpduId)[index].UpdateByteIndex;
    uint8 tempMaskValue = (uint8)(~(COM_CFG_RXPDU_UPDATEBIT_INFO(RxIpduId)[index].UpdateMaskValue));
    uint8 tempValue = PduPtr[tempByteIndex];

    /* update bit will only copied in temp rx buffer, it will not copy to real buffer*/
    if((uint8)0 != (uint8)(tempValue & tempMaskValue))
    {
        ret = TRUE;
    }
    return ret;

}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_InitRxOccOfPdu
*
* Description:   Init Rx signal's occ counter to 0, if configured
*
* Inputs:        sigId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if((COM_RX_FILTER_SUPPORT == STD_ON) && (COM_MAX_FILTER_OCCURRENCE_NUM > 0))
STATIC FUNC(void, COM_CODE) Com_InitRxOccOfPdu
(
    PduIdType RxIpduId
)
{
    Com_SignalIdType SigIndex = (Com_SignalIdType)0;
    Com_SignalIdType OccIndex = (Com_SignalIdType)0;

    for(SigIndex = COM_CFG_RXPDU_SIG_START_NUM(RxIpduId); SigIndex <= COM_CFG_RXPDU_SIG_STOP_NUM(RxIpduId); SigIndex++)
    {
        if(NULL_PTR != COM_CFG_RXSIG_FILTER_PTR(SigIndex))
        {
            OccIndex = COM_CFG_RXSIG_FILTER_PTR(SigIndex)->OccIndex;
            if(COM_INVALID_SIG_INDEX != OccIndex)
            {
                Com_Sig_Occurrence[OccIndex] = (uint16)0;
            }
        }
    }
}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_InitRxPduValue
*
* Description:   Init Rx Pdu values
*
* Inputs:        RxIpduId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_InitRxPduValue
(
    PduIdType RxIpduId
)
{
    PduLengthType IndexData = (PduLengthType)0;
    Com_SignalIdType SigIndex = (Com_SignalIdType)0;
    P2VAR(void, AUTOMATIC, COM_VAR) tmpRxDataPtr = NULL_PTR;
    tmpRxDataPtr = COM_CFG_RXPDU_DATA_PTR(RxIpduId);
    /* Step 1 clear all byte to 0*/
    for(IndexData = (PduLengthType)0; IndexData < COM_CFG_RXPDU_LENGTH(RxIpduId); IndexData++)
    {
        ((uint8 *)tmpRxDataPtr)[IndexData] = (uint8)0;
    }
    /* Step 2 init all signals of this pdu*/
    for(SigIndex = COM_CFG_RXPDU_SIG_START_NUM(RxIpduId); SigIndex <= COM_CFG_RXPDU_SIG_STOP_NUM(RxIpduId); SigIndex++)
    {
        Com_ReplaceRxSignalWithInit(RxIpduId, SigIndex, FALSE);
#if(COM_RX_FILTER_SUPPORT == STD_ON)
        if(NULL_PTR != COM_CFG_RXSIG_FILTER_PTR(SigIndex))
        {
            if(NULL_PTR != COM_CFG_RXSIG_FILTER_PTR(SigIndex)->Par3)
            {
                Com_CopySignalWithOutLock(COM_CFG_RXSIG_INIT_VALUE_PTR(SigIndex), COM_CFG_RXSIG_FILTER_PTR(SigIndex)->Par3,  COM_CFG_RXSIG_TYPE(SigIndex), COM_CFG_RXSIG_LENGTH(SigIndex));
            }
        }
#endif
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_InitRxPdu
*
* Description:   Init Rx Pdu Regs, called when Init only
*
* Inputs:         RxIpduId, isStartFlag,InitFlag
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(void, COM_CODE) Com_InitRxPdu
(
    PduIdType RxIpduId,
    boolean   isStartFlag
)
{




#if(STD_ON == COM_RX_LONG_PDU_FUN)
    COM_RXPDU_TP_INDEX(RxIpduId) = (PduLengthType)0;
#endif


    COM_RXPDU_TEMP_LENGTH(RxIpduId) = (PduLengthType)0;


    /* time out monitor Init*/
#if (STD_ON == COM_RX_TIMEOUT_MONITOR)
    COM_RXPDU_TIMEOUT(RxIpduId) = COM_TIMER_STOP_VAL;
#if(STD_ON == COM_RX_SIGNAL_UB_TIMEOUT_SUPPORT)
    Com_ResetUpdateRxToTimer(RxIpduId);
#endif
    if(FALSE == isStartFlag)
    {
        COM_RXPDU_MONITOR_FLAG(RxIpduId) = FALSE;
    }
    else
    {
        COM_RXPDU_MONITOR_FLAG(RxIpduId) = COM_CFG_RXPDU_MONITOR_FLAG(RxIpduId);
    }
#endif

    /*Pdu Data Length Init*/
    Com_InitRxPduValue(RxIpduId);


    if(FALSE == isStartFlag)
    {
        Com_RxPduState[RxIpduId] = COM_RXPDU_STOP;/*SWS_Com_444 all group stop at Init*/
    }
    else
    {
        Com_RxPduState[RxIpduId] = COM_RXPDU_START_IDLE;/*SWS_Com_840*/
    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SwitchRxPduMode
*
* Description:   Init Rx Pdu Regs When PduGroupMode Switch, called PduMode Switch
*
* Inputs:         RxIpduId, isStartFlag,InitFlag
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_IPDU_GROUP_FUN)
STATIC FUNC(void, COM_CODE) Com_SwitchRxPduMode
(
    PduIdType RxIpduId,
    boolean   isStartFlag,
    boolean   InitFlag
)
{
    COM_RXPDU_TEMP_LENGTH(RxIpduId) = (PduLengthType)0;

#if(STD_ON == COM_RX_LONG_PDU_FUN)
    COM_RXPDU_TP_INDEX(RxIpduId) = (PduLengthType)0;
#endif



    /*Pdu Data Length Init
      Start-> Stop keep payload data unchange
      Stop->start, decide by InitFlag SWS_Com_222
    */

    if((TRUE == isStartFlag) && (TRUE == InitFlag))
    {
        Com_InitRxPduValue(RxIpduId);
    }

#if((COM_RX_FILTER_SUPPORT == STD_ON) && (COM_MAX_FILTER_OCCURRENCE_NUM > 0))
    /* clear all occ signal's occ counter of this pdu */
    Com_InitRxOccOfPdu(RxIpduId);/*SWS_Com_00787-4*/
#endif



#if (STD_ON == COM_RX_TIMEOUT_MONITOR)
    COM_RXPDU_TIMEOUT(RxIpduId) = COM_TIMER_STOP_VAL;/*SWS_Com_00787-2*/

    if(FALSE == isStartFlag)/* SWS_Com_685 ,Start-> Stop, time monitor is disable*/
    {
        COM_RXPDU_MONITOR_FLAG(RxIpduId) = FALSE;
    }
    else
    {
        /*SWS_Com_787 stop->start, timer must be restart*/
        COM_RXPDU_MONITOR_FLAG(RxIpduId) = COM_CFG_RXPDU_MONITOR_FLAG(RxIpduId);
    }
#endif

    if(FALSE == isStartFlag)
    {
        Com_RxPduState[RxIpduId] = COM_RXPDU_STOP;
    }
    else
    {
        Com_RxPduState[RxIpduId] = COM_RXPDU_START_IDLE;/*SWS_Com_114*/
    }


}
#endif/* #if(STD_ON == COM_IPDU_GROUP_FUN)*/



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_RxInit
*
* Description:   rx initialize.
*
* Inputs:         None
*
* Outputs:          None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_RxInit
(
    void
)
{

    PduIdType IpduIndex = (PduIdType)0;

    for(IpduIndex = (PduIdType)0; IpduIndex < COM_RXPDU_NUM; IpduIndex++)
    {

#if (STD_ON == COM_IPDU_GROUP_FUN)
        if(TRUE == COM_CFG_RXPDUGROUP_FLAG(IpduIndex))
        {
            Com_InitRxPdu(IpduIndex, FALSE);
        }
        else
#endif
        {
            Com_InitRxPdu(IpduIndex, TRUE);
        }
    }

}




/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ReplaceRxSignalWithInit
*
* Description:   replace signal with init value, called when init or rxsignal timeout
*
* Inputs:        sigId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_ReplaceRxSignalWithInit
(
    PduIdType RxPduId,
    Com_SignalIdType RxSigId,
    boolean NeedRoutOut
)
{
    PduLengthType SigLen = (PduLengthType)0;
#if (STD_ON == COM_GW_FUN)
    Com_SignalIdType GWSigIndex;
#endif
    Com_SigType SigType;

    SigLen = COM_CFG_RXSIG_LENGTH(RxSigId);
    SigType = COM_CFG_RXSIG_TYPE(RxSigId);
#if (STD_ON == COM_RX_DYN_PDU_SUPPORT)
    if(COM_SIG_DYN == SigType)
    {
        SigLen = COM_CFG_RXSIG_INIT_VALUE_LEN(RxSigId);
        COM_RXPDU_DYN_LENGTH(RxPduId) = COM_CFG_RXSIG_START_BYTE_INDEX(RxSigId) + SigLen;
    }
#endif

#if(STD_OFF == COM_RX_GROUP_SIG_RECEIVE_IMM)
#if (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    /* Also copy to shadow buffer*/
    if(NULL_PTR != COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId))
    {
        Com_CopySignal(COM_CFG_RXSIG_INIT_VALUE_PTR(RxSigId), COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId), SigType, SigLen, RxSigId);
    }
    else
#endif
#endif
    {
        /* copy init value to real buffer*/
        Com_CopySignal(COM_CFG_RXSIG_INIT_VALUE_PTR(RxSigId), COM_CFG_RXSIG_DATA_PTR(RxSigId), SigType, SigLen, RxSigId);
    }
#if (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
#if (STD_ON == COM_RX_DYN_PDU_SUPPORT)
    if(NULL_PTR != COM_CFG_RXSIG_GROUP_TEMPLENGTH_PTR(RxSigId))
    {
        *COM_CFG_RXSIG_GROUP_TEMPLENGTH_PTR(RxSigId) = SigLen;
    }
#endif
#endif

#if(STD_ON == COM_GW_FUN)
    if(TRUE == NeedRoutOut)
    {
        /*if signal is rx ok, set GwFlag, GwFlag will only be cleared*/
        GWSigIndex = COM_CFG_RXSIG_GW_INDEX(RxSigId);
        if(COM_INVALID_SIG_INDEX != GWSigIndex)
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_5();

            Com_GateWaySignal(GWSigIndex, (void *)COM_CFG_RXSIG_INIT_VALUE_PTR(RxSigId));

            SchM_Exit_Com_COM_EXCLUSIVE_AREA_5();
        }
    }
#endif

}


#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
#if(STD_ON == COM_RX_SIGNAL_SUBSTITUTE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ReplaceRxSignalWithSubstitute
*
* Description:   replace signal with Substitute value, called when rxsignal timeout
*
* Inputs:        sigId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_ReplaceRxSignalWithSubstitute
(
    PduIdType RxPduId,
    Com_SignalIdType RxSigId
)
{
    PduLengthType SigLen = (PduLengthType)0;
#if (STD_ON == COM_GW_FUN)
    Com_SignalIdType GWSigIndex;
#endif
    Com_SigType SigType;

    SigLen = COM_CFG_RXSIG_LENGTH(RxSigId);
    SigType = COM_CFG_RXSIG_TYPE(RxSigId);

#if (STD_ON == COM_RX_DYN_PDU_SUPPORT)
    if(COM_SIG_DYN == SigType)
    {
        SigLen = COM_CFG_RXSIG_SUB_VALUE_LEN(RxSigId);
        COM_RXPDU_DYN_LENGTH(RxPduId) = COM_CFG_RXSIG_START_BYTE_INDEX(RxSigId) + SigLen;
    }
#endif
#if(STD_OFF == COM_RX_GROUP_SIG_RECEIVE_IMM)
#if (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    /* Also copy to shadow buffer*/
    if(NULL_PTR != COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId))
    {
        Com_CopySignal(COM_CFG_RXSIG_SUB_VALUE_PTR(RxSigId), COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId), SigType, SigLen, RxSigId);
    }
    else
#endif
#endif
    {
        /* copy init value to real buffer*/
        Com_CopySignal(COM_CFG_RXSIG_SUB_VALUE_PTR(RxSigId), COM_CFG_RXSIG_DATA_PTR(RxSigId), SigType, SigLen, RxSigId);
    }
#if (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
#if (STD_ON == COM_RX_DYN_PDU_SUPPORT)
    if(NULL_PTR != COM_CFG_RXSIG_GROUP_TEMPLENGTH_PTR(RxSigId))
    {
        *COM_CFG_RXSIG_GROUP_TEMPLENGTH_PTR(RxSigId) = SigLen;
    }
#endif
#endif

#if (STD_ON == COM_GW_FUN)
    /*if signal is rx ok, set GwFlag, GwFlag will only be cleared*/
    GWSigIndex = COM_CFG_RXSIG_GW_INDEX(RxSigId);
    if(COM_INVALID_SIG_INDEX != GWSigIndex)
    {
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_5();

        Com_GateWaySignal(GWSigIndex, (void *)COM_CFG_RXSIG_SUB_VALUE_PTR(RxSigId));

        SchM_Exit_Com_COM_EXCLUSIVE_AREA_5();
    }
#endif

}
#endif
#endif

#if (STD_ON == COM_RX_INVALID_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_RxPduInvalid
*
* Description:   do all invalid action when rx pdu got following cases:
*                1.rxCallout return not ok
*                2.tp rx result is not ok
*
* Inputs:        RxPduId:
*                invalidFlag:tp packet result only
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_RxPduInvalid
(
    PduIdType RxPduId
)
{
    Com_SignalIdType signalIndex =  (Com_SignalIdType)0;
#if (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    Com_SignalIdType grpSigIndex = (Com_SignalIdType)0;
    Com_SignalGroupIdType grpId = (Com_SignalGroupIdType)0;
#endif

    for(signalIndex = COM_CFG_RXPDU_SIG_START_NUM(RxPduId); signalIndex <= COM_CFG_RXPDU_SIG_STOP_NUM(RxPduId); signalIndex++)
    {
        if(COM_NOTIFY == COM_CFG_RXSIG_INVALID_ACTION(signalIndex))
        {
            COM_CFG_RXSIG_CBKINV_FUN(signalIndex)();
        }
        else if(COM_REPLACE == COM_CFG_RXSIG_INVALID_ACTION(signalIndex))
        {

#if (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
            if(TRUE == COM_CFG_RXSIG_IS_GROUP_SIGNAL(signalIndex))
            {
                grpId = COM_CFG_RXSIG_GET_SIGGROUPID(signalIndex);
                for(grpSigIndex = COM_CFG_RXSIGGRP_SIGSTART(grpId); grpSigIndex <= COM_CFG_RXSIGGRP_SIGSTOP(grpId); grpSigIndex++)
                {
                    Com_ReplaceRxSignalWithInit(RxPduId, grpSigIndex, TRUE);
                }
            }
            else
#endif
            {
                Com_ReplaceRxSignalWithInit(RxPduId, signalIndex, TRUE);
            }

        }
        else
        {
            /* do nothing*/
        }

#if (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
        if(TRUE == COM_CFG_RXSIG_IS_GROUP_SIGNAL(signalIndex))
        {
            grpId = COM_CFG_RXSIG_GET_SIGGROUPID(signalIndex);
            /* set sigId to the end of this group */
            signalIndex = COM_CFG_RXSIGGRP_SIGSTOP(grpId);
        }
#endif

    }
}
#endif

#if((COM_RX_FILTER_SUPPORT == STD_ON) || (STD_ON == COM_RX_INVALID_SUPPORT))
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_RxSignalFilter
*
* Description:   Filter signal.
*
* Inputs:        RxSigId
*                PduPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_RxSignalFilter
(
    Com_SignalIdType  RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    uint8 result = COM_SIGNAL_VALID;
    Com_EndiannessType Endianness = COM_CFG_RXSIG_ENDIANNESS(RxSigId);
    Com_SigType SigType = COM_CFG_RXSIG_TYPE(RxSigId);
    uint16 BitSize = COM_CFG_RXSIG_BIT_SIZE(RxSigId);
    uint16 StartBit = COM_CFG_RXSIG_START_BIT(RxSigId);
    uint64 Mask = COM_CFG_RXSIG_MASK(RxSigId);
#if(COM_RX_FILTER_SUPPORT == STD_ON)
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr = COM_CFG_RXSIG_FILTER_PTR(RxSigId);
#endif
#if(STD_ON == COM_RX_INVALID_SUPPORT)
    P2CONST(void, TYPEDEF, COM_CONST) InvalidValPtr = COM_CFG_RXSIG_INVALID_VALUE_PTR(RxSigId);
    float32 Value_F32 = (float32)0;
    float64 Value_F64 = (float64)0;
#if(COM_RX_SIG_MAX_ARRAY_SZIE > 0)
    uint8 Value_U8N[COM_RX_SIG_MAX_ARRAY_SZIE] = {(uint8)0};
    uint16 ByteLength = COM_CFG_RXSIG_LENGTH(RxSigId);
#endif
#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)
    PduIdType RxIpduId = COM_CFG_RXSIG_RXPDU_ID(RxSigId);
#endif
#endif
    uint8 Value_U8 = (uint8)0;
    uint16 Value_U16 = (uint16)0;
    uint32 Value_U32 = (uint32)0;
    uint64 Value_U64 = (uint64)0;
    sint8 Value_S8 = (sint8)0;
    sint16 Value_S16 = (sint16)0;
    sint32 Value_S32 = (sint32)0;
    sint64 Value_S64 = (sint64)0;

    switch(SigType)
    {
    case COM_SIG_BOOLEAN:
    case COM_SIG_U8:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleU8(&Value_U8, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigU8(&Value_U8, PduPtr, BitSize, StartBit, Mask);
        }
#if(STD_ON == COM_RX_INVALID_SUPPORT)
        if(NULL_PTR != InvalidValPtr)
        {
            if(Value_U8 == *(uint8*)InvalidValPtr)
            {
                result = COM_SIGNAL_INVALID;
            }
        }
#endif
#if(COM_RX_FILTER_SUPPORT == STD_ON)
        if(COM_SIGNAL_VALID == result)
        {
            if(NULL_PTR != AlgPtr)
            {
                if(NULL_PTR != AlgPtr->Par3)
                {
                    *(uint8*)(AlgPtr->Par3) = *(uint8*)COM_CFG_RXSIG_DATA_PTR(RxSigId);
                }
                result = Com_SignalFilter_U8(&Value_U8, AlgPtr);
            }
        }
#endif
        break;
    case COM_SIG_S8:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleS8(&Value_S8, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigS8(&Value_S8, PduPtr, BitSize, StartBit, Mask);
        }
#if(STD_ON == COM_RX_INVALID_SUPPORT)
        if(NULL_PTR != InvalidValPtr)
        {
            if(Value_S8 == *(sint8*)InvalidValPtr)
            {
                result = COM_SIGNAL_INVALID;
            }
        }
#endif
#if(COM_RX_FILTER_SUPPORT == STD_ON)
        if(COM_SIGNAL_VALID == result)
        {
            if(NULL_PTR != AlgPtr)
            {
                if(NULL_PTR != AlgPtr->Par3)
                {
                    *(sint8*)(AlgPtr->Par3) = *(sint8*)COM_CFG_RXSIG_DATA_PTR(RxSigId);
                }
                result = Com_SignalFilter_S8(&Value_S8, AlgPtr);
            }
        }
#endif
        break;
    case COM_SIG_U16:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleU16(&Value_U16, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigU16(&Value_U16, PduPtr, BitSize, StartBit, Mask);
        }
#if(STD_ON == COM_RX_INVALID_SUPPORT)
        if(NULL_PTR != InvalidValPtr)
        {
            if(Value_U16 == *(uint16*)InvalidValPtr)
            {
                result = COM_SIGNAL_INVALID;
            }
        }
#endif
#if(COM_RX_FILTER_SUPPORT == STD_ON)
        if(COM_SIGNAL_VALID == result)
        {
            if(NULL_PTR != AlgPtr)
            {
                if(NULL_PTR != AlgPtr->Par3)
                {
                    *(uint16*)(AlgPtr->Par3) = *(uint16*)COM_CFG_RXSIG_DATA_PTR(RxSigId);
                }
                result = Com_SignalFilter_U16(&Value_U16, AlgPtr);
            }
        }
#endif
        break;
    case COM_SIG_S16:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleS16(&Value_S16, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigS16(&Value_S16, PduPtr, BitSize, StartBit, Mask);
        }
#if(STD_ON == COM_RX_INVALID_SUPPORT)
        if(NULL_PTR != InvalidValPtr)
        {
            if(Value_S16 == *(sint16*)InvalidValPtr)
            {
                result = COM_SIGNAL_INVALID;
            }
        }
#endif
#if(COM_RX_FILTER_SUPPORT == STD_ON)
        if(COM_SIGNAL_VALID == result)
        {
            if(NULL_PTR != AlgPtr)
            {
                if(NULL_PTR != AlgPtr->Par3)
                {
                    *(sint16*)(AlgPtr->Par3) = *(sint16*)COM_CFG_RXSIG_DATA_PTR(RxSigId);
                }
                result = Com_SignalFilter_S16(&Value_S16, AlgPtr);
            }
        }
#endif
        break;
    case COM_SIG_U32:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleU32(&Value_U32, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigU32(&Value_U32, PduPtr, BitSize, StartBit, Mask);
        }
#if(STD_ON == COM_RX_INVALID_SUPPORT)
        if(NULL_PTR != InvalidValPtr)
        {
            if(Value_U32 == *(uint32*)InvalidValPtr)
            {
                result = COM_SIGNAL_INVALID;
            }
        }
#endif
#if(COM_RX_FILTER_SUPPORT == STD_ON)
        if(COM_SIGNAL_VALID == result)
        {
            if(NULL_PTR != AlgPtr)
            {
                if(NULL_PTR != AlgPtr->Par3)
                {
                    *(uint32*)(AlgPtr->Par3) = *(uint32*)COM_CFG_RXSIG_DATA_PTR(RxSigId);
                }
                result = Com_SignalFilter_U32(&Value_U32, AlgPtr);
            }
        }
#endif
        break;
    case COM_SIG_S32:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleS32(&Value_S32, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigS32(&Value_S32, PduPtr, BitSize, StartBit, Mask);
        }
#if(STD_ON == COM_RX_INVALID_SUPPORT)
        if(NULL_PTR != InvalidValPtr)
        {
            if(Value_S32 == *(sint32*)InvalidValPtr)
            {
                result = COM_SIGNAL_INVALID;
            }
        }
#endif
#if(COM_RX_FILTER_SUPPORT == STD_ON)
        if(COM_SIGNAL_VALID == result)
        {
            if(NULL_PTR != AlgPtr)
            {
                if(NULL_PTR != AlgPtr->Par3)
                {
                    *(sint32*)(AlgPtr->Par3) = *(sint32*)COM_CFG_RXSIG_DATA_PTR(RxSigId);
                }
                result = Com_SignalFilter_S32(&Value_S32, AlgPtr);
            }
        }
#endif
        break;
    case COM_SIG_U64:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleU64(&Value_U64, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigU64(&Value_U64, PduPtr, BitSize, StartBit, Mask);
        }
#if(STD_ON == COM_RX_INVALID_SUPPORT)
        if(NULL_PTR != InvalidValPtr)
        {
            if(Value_U64 == *(uint64*)InvalidValPtr)
            {
                result = COM_SIGNAL_INVALID;
            }
        }
#endif
#if(COM_RX_FILTER_SUPPORT == STD_ON)
        if(COM_SIGNAL_VALID == result)
        {
            if(NULL_PTR != AlgPtr)
            {
                if(NULL_PTR != AlgPtr->Par3)
                {
                    *(uint64*)(AlgPtr->Par3) = *(uint64*)COM_CFG_RXSIG_DATA_PTR(RxSigId);
                }
                result = Com_SignalFilter_U64(&Value_U64, AlgPtr);
            }
        }
#endif
        break;
    case COM_SIG_S64:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleS64(&Value_S64, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigS64(&Value_S64, PduPtr, BitSize, StartBit, Mask);
        }
#if(STD_ON == COM_RX_INVALID_SUPPORT)
        if(NULL_PTR != InvalidValPtr)
        {
            if(Value_S64 == *(sint64*)InvalidValPtr)
            {
                result = COM_SIGNAL_INVALID;
            }
        }
#endif
#if(COM_RX_FILTER_SUPPORT == STD_ON)
        if(COM_SIGNAL_VALID == result)
        {
            if(NULL_PTR != AlgPtr)
            {
                if(NULL_PTR != AlgPtr->Par3)
                {
                    *(sint64*)(AlgPtr->Par3) = *(sint64*)COM_CFG_RXSIG_DATA_PTR(RxSigId);
                }
                result = Com_SignalFilter_S64(&Value_S64, AlgPtr);
            }
        }
#endif
        break;
    case COM_SIG_F32:
#if(STD_ON == COM_RX_INVALID_SUPPORT)
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleF32(&Value_F32, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigF32(&Value_F32, PduPtr, BitSize, StartBit, Mask);
        }
        if(NULL_PTR != InvalidValPtr)
        {
            if(Value_F32 == *(float32*)InvalidValPtr)
            {
                result = COM_SIGNAL_INVALID;
            }
        }
#endif
#if(COM_RX_FILTER_SUPPORT == STD_ON)
        if(COM_SIGNAL_VALID == result)
        {
            if(NULL_PTR != AlgPtr)
            {
                result = Com_SignalFilter_F32F64U8N(AlgPtr);
            }
        }
#endif
        break;
    case COM_SIG_F64:
#if(STD_ON == COM_RX_INVALID_SUPPORT)
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleF64(&Value_F64, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigF64(&Value_F64, PduPtr, BitSize, StartBit, Mask);
        }
        if(NULL_PTR != InvalidValPtr)
        {
            if(Value_F64 == *(float64*)InvalidValPtr)
            {
                result = COM_SIGNAL_INVALID;
            }
        }
#endif
#if(COM_RX_FILTER_SUPPORT == STD_ON)
        if(COM_SIGNAL_VALID == result)
        {
            if(NULL_PTR != AlgPtr)
            {
                result = Com_SignalFilter_F32F64U8N(AlgPtr);
            }
        }
#endif
        break;
#if(COM_RX_SIG_MAX_ARRAY_SZIE > 0)
    case COM_SIG_U8N:
#if(STD_ON == COM_RX_INVALID_SUPPORT)
        Com_ReadSignal_U8N(Value_U8N, PduPtr, ByteLength, StartBit);
        if(NULL_PTR != InvalidValPtr)
        {
            if(FALSE == Com_CheckChangeSignal_U8N(Value_U8N, (uint8*)InvalidValPtr, ByteLength, (uint16)0))
            {
                result = COM_SIGNAL_INVALID;
            }
        }
#endif
#if(COM_RX_FILTER_SUPPORT == STD_ON)
        if(COM_SIGNAL_VALID == result)
        {
            if(NULL_PTR != AlgPtr)
            {
                result = Com_SignalFilter_F32F64U8N(AlgPtr);
            }
        }
#endif
        break;
#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)
    case COM_SIG_DYN:
#if(STD_ON == COM_RX_INVALID_SUPPORT)
        ByteLength = COM_RXPDU_DYN_LENGTH(RxIpduId) - COM_CFG_RXSIG_START_BYTE_INDEX(RxSigId);
        Com_ReadSignal_U8N(Value_U8N, PduPtr, ByteLength, StartBit);
        if(NULL_PTR != InvalidValPtr)
        {
            if(FALSE == Com_CheckChangeSignal_U8N(Value_U8N, (uint8*)InvalidValPtr, ByteLength, (uint16)0))
            {
                result = COM_SIGNAL_INVALID;
            }
        }
#endif
#if(COM_RX_FILTER_SUPPORT == STD_ON)
        if(COM_SIGNAL_VALID == result)
        {
            if(NULL_PTR != AlgPtr)
            {
                result = Com_SignalFilter_F32F64U8N(AlgPtr);
            }
        }
#endif
        break;
#endif
#endif/*#if(COM_RX_SIG_MAX_ARRAY_SZIE > 0)*/
    default:
        break;
    }
    return result;
}
#endif

#if 0
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_HandleRxPdu_DirectCopy
*
* Description:   Rx process if directcopy rx pdu is received
*
* Inputs:        RxPduId
*                PduPtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_HandleRxPdu_DirectCopy
(
    PduIdType RxPduId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    Com_SignalIdType RxSigId = (Com_SignalIdType)0;

    for(RxSigId = COM_CFG_RXPDU_SIG_START_NUM(RxPduId);
            RxSigId <= COM_CFG_RXPDU_SIG_STOP_NUM(RxPduId);
            RxSigId++)
    {
#if(STD_ON == COM_PADDING_SUPPORT)
        if(COM_CFG_RXSIG_MIN_BYTE(RxSigId) <= COM_RXPDU_TEMP_LENGTH(RxPduId))/* rx data length may be smaller than cfg length*/
#endif
        {
            Com_HandleRxSig(RxSigId, PduPtr);
            if(NULL_PTR != COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId))
            {
                COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId)();/*SWS_Com_00574*/
            }
#if(STD_ON == COM_DEM_EVENT_SET_SUPPORT)
            if(COM_INVALID_EVENT_ID != COM_CFG_RXSIG_DEM_EVENT_ID(RxSigId))
            {
                Dem_SetEventStatus(COM_CFG_RXSIG_DEM_EVENT_ID(RxSigId), COM_DEM_EVENT_STATUS_PREPASSED);
            }
#endif
        }
    }
}
#endif

/*
 0-OK,
 1- NO UPDATED
 2- INVALID VALUE RX
 3- FILTER FAIL

*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_CheckRxSignalGroup_Invalid_Filter
*
* Description:   check all signals within a signal group
*
* Inputs:        RxPduId:
*
* Outputs:       uint8
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
#if((COM_RX_FILTER_SUPPORT == STD_ON) || (STD_ON == COM_RX_INVALID_SUPPORT))
STATIC FUNC(uint8, COM_CODE) Com_CheckRxSignalGroup_Invalid_Filter
(
    Com_SignalGroupIdType SigGrpId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    uint8 ret = COM_SIGNAL_VALID;
    Com_SignalIdType signalIndex =  (Com_SignalIdType)0;

    if((TRUE == COM_CFG_RXSIGGRP_HAS_INVALID_VAL(SigGrpId)) || (TRUE == COM_CFG_RXSIGGRP_HAS_FILTER(SigGrpId)))
    {
        for(signalIndex = COM_CFG_RXSIGGRP_SIGSTART(SigGrpId); signalIndex <= COM_CFG_RXSIGGRP_SIGSTOP(SigGrpId);  signalIndex++)
        {
            ret |= Com_RxSignalFilter(signalIndex, PduPtr);
        }
    }

    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_RxSignalGroup_ProcessAfterCheck
*
* Description:   process ack indication  after signal group check
*
* Inputs:        RxPduId, filterResult,RxSigId,SigGrpId
*
* Outputs:       uint8
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_RxSignalGroup_ProcessAfterCheck
(
    PduIdType RxPduId,
    uint8 filterResult,
    Com_SignalIdType RxSigId,
    Com_SignalGroupIdType SigGrpId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    Com_SignalIdType signalIndex =  (Com_SignalIdType)0;

    if(COM_SIGNAL_VALID == filterResult)
    {
        /* COPY RX DATA*/
        for(signalIndex = COM_CFG_RXSIGGRP_SIGSTART(SigGrpId); signalIndex <= COM_CFG_RXSIGGRP_SIGSTOP(SigGrpId); signalIndex++)
        {
            Com_HandleRxSig(signalIndex, PduPtr);
#if (STD_ON == COM_RX_DYN_PDU_SUPPORT)
            if(COM_SIG_DYN == COM_CFG_RXSIG_TYPE(signalIndex))
            {
                COM_RXPDU_DYN_LENGTH(RxPduId) = COM_RXPDU_TEMP_LENGTH(RxPduId);
            }
#endif
        }

        SchM_Enter_Com_COM_EXCLUSIVE_AREA_12();

#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        COM_GETSPINLOCK(&(Com_SpinLock_RxSigGroup[SigGrpId]));
#endif
        for(signalIndex = COM_CFG_RXSIGGRP_SIGSTART(SigGrpId); signalIndex <= COM_CFG_RXSIGGRP_SIGSTOP(SigGrpId); signalIndex++)
        {
            Com_CopySignal(COM_CFG_RXSIG_GROUP_TEMP_BUF(signalIndex), COM_CFG_RXSIG_DATA_PTR(signalIndex), COM_CFG_RXSIG_TYPE(signalIndex), COM_CFG_RXSIG_LENGTH(signalIndex), signalIndex);
        }
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        COM_RELEASESPINLOCK(&(Com_SpinLock_RxSigGroup[SigGrpId]));
#endif

        SchM_Exit_Com_COM_EXCLUSIVE_AREA_12();

        if(NULL_PTR != COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId))
        {
            COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId)();/*SWS_Com_00574*/
        }
#if(STD_ON == COM_DEM_EVENT_SET_SUPPORT)
        if(COM_INVALID_EVENT_ID != COM_CFG_RXSIG_DEM_EVENT_ID(RxSigId))
        {
            Dem_SetEventStatus(COM_CFG_RXSIG_DEM_EVENT_ID(RxSigId), COM_DEM_EVENT_STATUS_PREPASSED);
        }
#endif
    }
#if (STD_ON == COM_RX_INVALID_SUPPORT)
    else if(COM_SIGNAL_INVALID == filterResult)
    {
        if(COM_NOTIFY == COM_CFG_RXSIG_INVALID_ACTION(RxSigId))
        {
            COM_CFG_RXSIG_CBKINV_FUN(RxSigId)();
        }
        else if(COM_REPLACE == COM_CFG_RXSIG_INVALID_ACTION(RxSigId))
        {
            /* replace data*/
            for(signalIndex = COM_CFG_RXSIGGRP_SIGSTART(SigGrpId); signalIndex <= COM_CFG_RXSIGGRP_SIGSTOP(SigGrpId);  signalIndex++)
            {
                /* SWS_Com_00683*/
                Com_ReplaceRxSignalWithInit(RxPduId, signalIndex, TRUE);
            }
            if(NULL_PTR != COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId))
            {
                COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId)();/*SWS_Com_00683*/
            }
#if(STD_ON == COM_DEM_EVENT_SET_SUPPORT)
            if(COM_INVALID_EVENT_ID != COM_CFG_RXSIG_DEM_EVENT_ID(RxSigId))
            {
                Dem_SetEventStatus(COM_CFG_RXSIG_DEM_EVENT_ID(RxSigId), COM_DEM_EVENT_STATUS_PREPASSED);
            }
#endif
        }
        else
        {
            /* do nothing*/
        }

    }
#endif
    /* SWS_Com_00273 COM_SIGNAL_NOT_PASS_FILTER == filterResult */
    else
    {
        /* just ignor sgnal when rxfilter not pass */
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_RxSignal_ProcessAfterCheck
*
* Description:   process ack indication  after signal check
*
* Inputs:        filterResult,RxSigId
*
* Outputs:       uint8
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(void, COM_CODE) Com_RxSignal_ProcessAfterCheck
(
    uint8 filterResult,
    PduIdType RxPduId,
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    if(COM_SIGNAL_VALID == filterResult)
    {
        Com_HandleRxSig(RxSigId, PduPtr);
#if (STD_ON == COM_RX_DYN_PDU_SUPPORT)
        if(COM_SIG_DYN == COM_CFG_RXSIG_TYPE(RxSigId))
        {
            COM_RXPDU_DYN_LENGTH(RxPduId) = COM_RXPDU_TEMP_LENGTH(RxPduId);
        }
#endif
        if(NULL_PTR != COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId))
        {
            COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId)();/*SWS_Com_00574*/
        }
#if(STD_ON == COM_DEM_EVENT_SET_SUPPORT)
        if(COM_INVALID_EVENT_ID != COM_CFG_RXSIG_DEM_EVENT_ID(RxSigId))
        {
            Dem_SetEventStatus(COM_CFG_RXSIG_DEM_EVENT_ID(RxSigId), COM_DEM_EVENT_STATUS_PREPASSED);
        }
#endif
    }
#if (STD_ON == COM_RX_INVALID_SUPPORT)
    else if(COM_SIGNAL_INVALID == filterResult)
    {
        if(COM_NOTIFY == COM_CFG_RXSIG_INVALID_ACTION(RxSigId))
        {
            COM_CFG_RXSIG_CBKINV_FUN(RxSigId)();
        }
        else if(COM_REPLACE == COM_CFG_RXSIG_INVALID_ACTION(RxSigId))
        {
            /* replace data with Init SWS_COM_00681*/
            Com_ReplaceRxSignalWithInit(RxPduId, RxSigId, TRUE);

            if(NULL_PTR != COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId))
            {
                COM_CFG_RXSIG_CBKRXACK_FUN(RxSigId)();
            }
#if(STD_ON == COM_DEM_EVENT_SET_SUPPORT)
            if(COM_INVALID_EVENT_ID != COM_CFG_RXSIG_DEM_EVENT_ID(RxSigId))
            {
                Dem_SetEventStatus(COM_CFG_RXSIG_DEM_EVENT_ID(RxSigId), COM_DEM_EVENT_STATUS_PREPASSED);
            }
#endif
        }
        else
        {
            /* do nothing*/
        }

    }
#endif
    /* SWS_Com_00273 COM_SIGNAL_NOT_PASS_FILTER == filterResult */
    else
    {
        /* just ignor sgnal when rxfilter not pass */
    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_HandleRxPdu
*
* Description:   rx indication when rx Ipdu.
*
* Inputs:        RxPduId:
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_HandleRxPdu
(
    PduIdType RxPduId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    Com_SignalIdType RxSigId = COM_CFG_RXPDU_SIG_START_NUM(RxPduId);
    uint8 filterResult;
#if(COM_RX_UPDATEBIT_SUPPORT == STD_ON)
    boolean updateflag = TRUE;
    Com_SignalIdType UpdateBitIndex;
#if(STD_ON == COM_RX_SIGNAL_UB_TIMEOUT_SUPPORT)
    P2VAR(uint16, TYPEDEF, COM_VAR) UpdateTimeoutCntPtr = NULL_PTR;
#endif
#endif

    while(RxSigId <= COM_CFG_RXPDU_SIG_STOP_NUM(RxPduId))
    {
        filterResult = COM_SIGNAL_VALID;
#if(STD_ON == COM_PADDING_SUPPORT)
        if(COM_CFG_RXSIG_MIN_BYTE(RxSigId) <= COM_RXPDU_TEMP_LENGTH(RxPduId))/* rx data length may be smaller than cfg length*/
#endif
        {
#if(COM_RX_UPDATEBIT_SUPPORT == STD_ON)
            updateflag = TRUE;
            UpdateBitIndex = COM_CFG_RXSIG_UPDATEBIT_INDEX(RxSigId);
            /* set update bit if configured*/
            if(COM_INVALID_SIG_INDEX != UpdateBitIndex)
            {
                if(FALSE == Com_CheckSigUpdateBit(RxPduId, UpdateBitIndex, PduPtr))
                {
                    updateflag = FALSE;
#if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                    if(TRUE == COM_CFG_RXSIG_IS_GROUP_SIGNAL(RxSigId))
                    {
                        RxSigId = COM_CFG_RXSIGGRP_SIGSTOP(COM_CFG_RXSIG_GET_SIGGROUPID(RxSigId));
                    }
#endif
                }
#if(STD_ON == COM_RX_SIGNAL_UB_TIMEOUT_SUPPORT)
                else
                {
                    UpdateTimeoutCntPtr = COM_CFG_RXPDU_UPDATEBIT_INFO(RxPduId)[UpdateBitIndex].UpdateTimeoutCntPtr;
                    if((NULL_PTR != UpdateTimeoutCntPtr)
                            && (COM_TIMER_STOP_VAL != *UpdateTimeoutCntPtr))
                    {
                        /* reset signal rx timeout timer*/
                        *UpdateTimeoutCntPtr = COM_CFG_RXSIG_UPTO_PERIOD(RxSigId);
                    }
                }
#endif
            }
            if(TRUE == updateflag)
#endif
            {
                /* reset timerout first */
#if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
                if(TRUE == COM_CFG_RXSIG_IS_GROUP_SIGNAL(RxSigId))
                {
#if((COM_RX_FILTER_SUPPORT == STD_ON) || (STD_ON == COM_RX_INVALID_SUPPORT))
                    filterResult = Com_CheckRxSignalGroup_Invalid_Filter(COM_CFG_RXSIG_GET_SIGGROUPID(RxSigId), PduPtr);
#endif
                    Com_RxSignalGroup_ProcessAfterCheck(RxPduId, filterResult, RxSigId, COM_CFG_RXSIG_GET_SIGGROUPID(RxSigId), PduPtr);
                    RxSigId = COM_CFG_RXSIGGRP_SIGSTOP(COM_CFG_RXSIG_GET_SIGGROUPID(RxSigId));
                }
                else
#endif
                {
#if((COM_RX_FILTER_SUPPORT == STD_ON) || (STD_ON == COM_RX_INVALID_SUPPORT))
                    filterResult = Com_RxSignalFilter(RxSigId, PduPtr);
#endif
                    Com_RxSignal_ProcessAfterCheck(filterResult, RxPduId, RxSigId, PduPtr);
                }
            }
        }
        RxSigId++;
    }



}

#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ResetUpdateRxToTimer
*
* Description:   stop  timeout of signals with update bit, when DM is disabled or pdu is stopped
*
* Inputs:        RxIpduId
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_RX_SIGNAL_UB_TIMEOUT_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_ResetUpdateRxToTimer
(
    PduIdType RxIpduId
)
{
    Com_SignalIdType RxIndex = (Com_SignalIdType)0;
    uint16 upIndex = (uint16)0;
    P2CONST(Com_CfgRxUpdateBitInfoType, AUTOMATIC, COM_CONST) tmpRxUpBitPtr = NULL_PTR;
    P2VAR(uint16, TYPEDEF, COM_VAR) UpdateTimeoutCntPtr = NULL_PTR;

    tmpRxUpBitPtr = COM_CFG_RXPDU_UPDATEBIT_INFO(RxIpduId);
    if(COM_CFG_RXPDU_UPDATEBIT_NUM(RxIpduId) > (Com_SignalIdType)0)
    {
        for(RxIndex = (Com_SignalIdType)0; RxIndex < COM_CFG_RXPDU_UPDATEBIT_NUM(RxIpduId); RxIndex++)
        {
            UpdateTimeoutCntPtr = tmpRxUpBitPtr[RxIndex].UpdateTimeoutCntPtr;
            if(NULL_PTR != UpdateTimeoutCntPtr)
            {
                *UpdateTimeoutCntPtr = COM_TIMER_STOP_VAL;
            }
        }
    }
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_UpdateRxTimerOutMonitor
*
* Description:   process rx timeout of signals with update bit
*
* Inputs:        RxIpduId
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(void, COM_CODE) Com_UpdateRxTimerOutMonitor
(
    PduIdType RxIpduId
)
{
    Com_SignalIdType RxSigId = (Com_SignalIdType)0;
    Com_SignalIdType RxIndex = (Com_SignalIdType)0;
    uint16 upIndex = (uint16)0;
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    Com_SignalIdType grpSignalIndex = (Com_SignalIdType)0;
    Com_SignalGroupIdType SigGrpId = (Com_SignalGroupIdType)0;
#endif
    P2CONST(Com_CfgRxUpdateBitInfoType, AUTOMATIC, COM_CONST) tmpRxUpBitPtr = NULL_PTR;
    P2VAR(uint16, TYPEDEF, COM_VAR) UpdateTimeoutCntPtr = NULL_PTR;

    tmpRxUpBitPtr = COM_CFG_RXPDU_UPDATEBIT_INFO(RxIpduId);
    if(COM_CFG_RXPDU_UPDATEBIT_NUM(RxIpduId) > (Com_SignalIdType)0)
    {
        for(RxIndex = (Com_SignalIdType)0; RxIndex < COM_CFG_RXPDU_UPDATEBIT_NUM(RxIpduId); RxIndex++)
        {
            RxSigId = tmpRxUpBitPtr[RxIndex].UpdateSignalId;
            UpdateTimeoutCntPtr = tmpRxUpBitPtr[RxIndex].UpdateTimeoutCntPtr;
            if(NULL_PTR != UpdateTimeoutCntPtr)/* may be no timeout */
            {
                if(COM_TIMER_STOP_VAL == *UpdateTimeoutCntPtr)
                {
                    *UpdateTimeoutCntPtr = COM_CFG_RXSIG_UPTO_FIRSTPERIOD(RxSigId);
                }
                if((uint16)0 != *UpdateTimeoutCntPtr)
                {
                    (*UpdateTimeoutCntPtr)--;
                }
                if((uint16)0 == *UpdateTimeoutCntPtr)
                {
                    *UpdateTimeoutCntPtr = COM_CFG_RXSIG_UPTO_PERIOD(RxSigId);

#if(STD_ON == COM_RX_TIMEOUT_ACTION_SUPPORT)
                    if(COM_RX_TIMEOUT_REPLACE == COM_CFG_RXSIG_TO_TIMEOUT_ACT(RxSigId))
                    {
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
                        if(TRUE == COM_CFG_RXSIG_IS_GROUP_SIGNAL(RxSigId))
                        {
                            SigGrpId = COM_CFG_RXSIG_GET_SIGGROUPID(RxSigId);
                            for(grpSignalIndex = COM_CFG_RXSIGGRP_SIGSTART(SigGrpId); grpSignalIndex <= COM_CFG_RXSIGGRP_SIGSTOP(SigGrpId);  grpSignalIndex++)
                            {
                                Com_ReplaceRxSignalWithInit(RxIpduId, grpSignalIndex, TRUE);
                            }
                        }
                        else
#endif
                        {
                            Com_ReplaceRxSignalWithInit(RxIpduId, RxSigId, TRUE);
                        }
                    }
#if(STD_ON == COM_RX_SIGNAL_SUBSTITUTE_SUPPORT)
                    else if(COM_RX_TIMEOUT_SUBSTITUTE == COM_CFG_RXSIG_TO_TIMEOUT_ACT(RxSigId))
                    {
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
                        if(TRUE == COM_CFG_RXSIG_IS_GROUP_SIGNAL(RxSigId))
                        {
                            SigGrpId = COM_CFG_RXSIG_GET_SIGGROUPID(RxSigId);
                            for(grpSignalIndex = COM_CFG_RXSIGGRP_SIGSTART(SigGrpId); grpSignalIndex <= COM_CFG_RXSIGGRP_SIGSTOP(SigGrpId);  grpSignalIndex++)
                            {
                                Com_ReplaceRxSignalWithSubstitute(RxIpduId, grpSignalIndex);
                            }
                        }
                        else
#endif
                        {
                            Com_ReplaceRxSignalWithSubstitute(RxIpduId, RxSigId);
                        }
                    }
#endif
                    else
                    {
                        /*Do Nothing*/
                    }
#endif
                    if(NULL_PTR != COM_CFG_RXSIG_CBKRXTOUT_FUN(RxSigId))
                    {
                        COM_CFG_RXSIG_CBKRXTOUT_FUN(RxSigId)();
                    }
#if(STD_ON == COM_DEM_EVENT_SET_SUPPORT)
                    if(COM_INVALID_EVENT_ID != COM_CFG_RXSIG_DEM_EVENT_ID(RxSigId))
                    {
                        Dem_SetEventStatus(COM_CFG_RXSIG_DEM_EVENT_ID(RxSigId), COM_DEM_EVENT_STATUS_PREFAILED);
                    }
#endif
                }
            }
        }
    }
}
#endif



/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_RxTimerOutMonitor
*
* Description:   process rx timeout
*
* Inputs:        RxIpduId
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(void, COM_CODE) Com_RxTimerOutMonitor
(
    PduIdType RxIpduId
)
{

    Com_SignalIdType RxSigId = (Com_SignalIdType)0;
#if(STD_ON == COM_RX_UPDATEBIT_SUPPORT)
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType grpId = (Com_SignalGroupIdType)0;
#endif
    Com_SignalIdType UpdateBitIndex;
#if(STD_ON == COM_RX_SIGNAL_UB_TIMEOUT_SUPPORT)
    P2VAR(uint16, TYPEDEF, COM_VAR) UpdateTimeoutCntPtr = NULL_PTR;
#endif
#endif

    if(COM_TIMER_STOP_VAL == COM_RXPDU_TIMEOUT(RxIpduId))
    {
        if((uint16)0 != COM_CFG_RXPDU_FIRST_TIMEOUT(RxIpduId))
        {
            COM_RXPDU_TIMEOUT(RxIpduId) =
                COM_CFG_RXPDU_FIRST_TIMEOUT(RxIpduId);/* First time start*/
        }
        else if((uint16)0 != COM_CFG_RXPDU_PERIOD_TIMEOUT(RxIpduId))
        {
            COM_RXPDU_TIMEOUT(RxIpduId) =
                COM_CFG_RXPDU_PERIOD_TIMEOUT(RxIpduId);
        }
    }
    if(COM_TIMER_STOP_VAL == COM_RXPDU_TIMEOUT(RxIpduId))
    {
        /*do nothing*/
    }
    else if((uint16)0 != COM_RXPDU_TIMEOUT(RxIpduId))
    {
        COM_RXPDU_TIMEOUT(RxIpduId)--;
    }
    else
    {
        COM_RXPDU_TIMEOUT(RxIpduId) = COM_CFG_RXPDU_PERIOD_TIMEOUT(RxIpduId);
        COM_RXPDU_TIMEOUT(RxIpduId)--;

        /* SWS_Com_00290 291 all signal timeout is monitor by pdu*/
        for(RxSigId = COM_CFG_RXPDU_SIG_START_NUM(RxIpduId);
                RxSigId <= COM_CFG_RXPDU_SIG_STOP_NUM(RxIpduId);
                RxSigId++)
        {
            /*SWS_Com_00744 first ComRxDataTimeoutAction then ComTimeoutNotification*/
            /* can not copy all pdu's init value, as some sig may be configed not replace*/

#if(STD_ON == COM_RX_SIGNAL_UB_TIMEOUT_SUPPORT)
            UpdateBitIndex = COM_CFG_RXSIG_UPDATEBIT_INDEX(RxSigId);
            if(COM_INVALID_SIG_INDEX != UpdateBitIndex)
            {
                UpdateTimeoutCntPtr = COM_CFG_RXPDU_UPDATEBIT_INFO(RxIpduId)[UpdateBitIndex].UpdateTimeoutCntPtr;
            }
            if(NULL_PTR == UpdateTimeoutCntPtr)
#endif
            {
                /* replace attibute will generated for all signal of group ,  not only for the first signal,
                   so no need to replace all group signal here
                */
#if(STD_ON == COM_RX_TIMEOUT_ACTION_SUPPORT)
                if(COM_RX_TIMEOUT_REPLACE == COM_CFG_RXSIG_TO_TIMEOUT_ACT(RxSigId))
                {
                    Com_ReplaceRxSignalWithInit(RxIpduId, RxSigId, TRUE);
                }
#if(STD_ON == COM_RX_SIGNAL_SUBSTITUTE_SUPPORT)
                else if(COM_RX_TIMEOUT_SUBSTITUTE == COM_CFG_RXSIG_TO_TIMEOUT_ACT(RxSigId))
                {
                    Com_ReplaceRxSignalWithSubstitute(RxIpduId, RxSigId);
                }
#endif
                else
                {
                    /*Do Nothing*/
                }
#endif
                /*SWS_Com_00470 500 513*/
                if(NULL_PTR != COM_CFG_RXSIG_CBKRXTOUT_FUN(RxSigId))
                {
                    COM_CFG_RXSIG_CBKRXTOUT_FUN(RxSigId)();
                }
#if(STD_ON == COM_DEM_EVENT_SET_SUPPORT)
                if(COM_INVALID_EVENT_ID != COM_CFG_RXSIG_DEM_EVENT_ID(RxSigId))
                {
                    Dem_SetEventStatus(COM_CFG_RXSIG_DEM_EVENT_ID(RxSigId), COM_DEM_EVENT_STATUS_PREFAILED);
                }
#endif
            }
#if(STD_ON == COM_RX_SIGNAL_UB_TIMEOUT_SUPPORT)
            else
            {
                /* has updatebit and this is signal group , jump all groupsiganl*/
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
                if(TRUE == COM_CFG_RXSIG_IS_GROUP_SIGNAL(RxSigId))
                {
                    grpId = COM_CFG_RXSIG_GET_SIGGROUPID(RxSigId);
                    RxSigId = COM_CFG_RXSIGGRP_SIGSTOP(grpId);/* set sigId to the end of this group */
                }
#endif
            }
#endif
        }
#if(STD_ON == COM_RX_TIMEOUT_PDU_CBK_SUPPORT)
        if(NULL_PTR != COM_CFG_RXPDU_CBKRXTOUT_FUN(RxIpduId))
        {
            COM_CFG_RXPDU_CBKRXTOUT_FUN(RxIpduId)();
        }
#endif
#if(STD_ON == COM_RX_LONG_PDU_FUN)
        /*This is only useful when the TP message is in the BUSY state. 
        Non-TP type messages may cause the interrupt reception to be reset.*/
        if(TRUE == COM_CFG_RXPDU_IS_TP_PDU(RxIpduId))
        {
            /* time out reset */
            Com_RxPduState[RxIpduId] = COM_RXPDU_START_IDLE;
            COM_RXPDU_TEMP_LENGTH(RxIpduId) = (PduLengthType)0;
            COM_RXPDU_TP_INDEX(RxIpduId) = (PduLengthType)0;
        }
#endif
    }

}
#endif



#endif/*#if(STD_ON == COM_RXPDU_FUN)*/


/*******************************************************************************
*   Api Used by generate file
*******************************************************************************/

#if(STD_ON == COM_TX_FILTER_SUPPORT)
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_TxSignalFilter
*
* Description:   only called when tx signal's value updated, this funtion only
*                caculate single signal's filter result, the whole Pdu result will
*                be caculated in mainfunction tx
* Inputs:        ComTxSigId, ComSigValuePtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_TxSignalFilterProcess
(
    Com_SignalIdType  ComTxSigId,
    Com_SigType SigType,
    P2CONST(void, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{

    PduIdType TxIpduId = (PduIdType)0;
    uint16 TxSigSetBitNum = (uint16)0;
    uint8 TxSigFilterResult = COM_SIGNAL_NOT_PASS_FILTER;
    uint8 Position_Bit = (uint8)0;
    uint16 Position_Byte = (uint16)0;
    uint8 tempByte = (uint8)0;


    TxIpduId = COM_CFG_TXSIG_TXPDU_ID(ComTxSigId);
    TxSigFilterResult = Com_TxSignalFilter(ValuePtr, AlgPtr, SigType);
    TxSigSetBitNum = ComTxSigId - COM_CFG_TXPDU_SIG_START_NUM(TxIpduId);
    Position_Byte = (TxSigSetBitNum >> COM_GET_BYTEINX_SHIFT_VALUE);
    Position_Bit = (uint8)(TxSigSetBitNum % COM_GET_BITPOS_RES_VALUE);
    tempByte = (uint8)(((uint8)1) << Position_Bit);

    if(COM_SIGNAL_VALID != TxSigFilterResult)
    {
        tempByte = (uint8)~tempByte;
        COM_CFG_TXPDU_FILTER_PTR(TxIpduId)[Position_Byte] &= tempByte;
    }
    else
    {
        COM_CFG_TXPDU_FILTER_PTR(TxIpduId)[Position_Byte] |= tempByte;
    }

    Com_SendSwitchTxModeFlag[TxIpduId] = COM_TXMODE_SWITCH_SEND_SIGNAL;

}
#endif/*#if(STD_ON == COM_TX_FILTER_SUPPORT)*/

#if(STD_ON == COM_TXPDU_FUN)
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_SetIpduTrigRepFlag
*
* Description:   only called when tx signal's value updated, this funtion only
*                set trigger and reptition flag, the flag will
*                be caculated in mainfunction tx
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_SetIpduTrigRepFlag
(
    Com_SignalTxPropertyType txProperty,
    PduIdType TxIpduId,
    boolean changeFlag
)
{
    switch(txProperty)
    {
#if(STD_ON == COM_TXMODE_REPTITION)
    case COM_TRIGGERED:
        Com_PDUTrigRepFlag[TxIpduId] = COM_TRIGGER_REP;
        if((uint8)0 == COM_TXPDU_TXMODE_REP_NUM(TxIpduId))
        {
            Com_PDUTrigRepFlag[TxIpduId] = COM_TRIGGER;
        }
        break;

    case COM_TRIGGERED_ON_CHANGE:
        if(TRUE == changeFlag)
        {
            Com_PDUTrigRepFlag[TxIpduId] = COM_TRIGGER_REP;
            if((uint8)0 == COM_TXPDU_TXMODE_REP_NUM(TxIpduId))
            {
                Com_PDUTrigRepFlag[TxIpduId] = COM_TRIGGER;
            }
        }
        break;
#endif

    case COM_TRIGGERED_WITHOUT_REPETITION:
        Com_PDUTrigRepFlag[TxIpduId] = COM_TRIGGER;
        break;

    case COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION:
        if(TRUE == changeFlag)
        {
            Com_PDUTrigRepFlag[TxIpduId] = COM_TRIGGER;
        }
        break;

    default:
        /* pending do nothing*/
        break;


    }

}
#endif/*#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)*/
#endif/*#if(STD_ON == COM_TXPDU_FUN)*/


/*******************************************************************************
*   Asr Stabdard Api
*******************************************************************************/


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_Init SWS_Com_432
*
* Description:   tx/rx initialize.  SWS_Com_128
*
* Inputs:        ConfigPtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_Init
(
    P2CONST(Com_ConfigType, AUTOMATIC, COM_CONST) ConfigPtr
)
{
#if (STD_ON == COM_IPDU_GROUP_FUN)
    Com_IpduGroupIdType grpIdx = (Com_IpduGroupIdType)0;
#endif
#if (COM_MAX_FILTER_OCCURRENCE_NUM > 0)
    Com_SignalIdType Index = (Com_SignalIdType)0;
#endif
#if(STD_ON == COM_MULTI_CORE_SUPPORT)

    if(COM_MASTER_CORE_ID == COM_GETCOREID())
#endif
    {
#if(COM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        if(NULL_PTR == ConfigPtr)
        {
            COM_DET_REPORT_ERROR(COMSERVICEID_INIT, COM_E_PARAM_POINTER);
        }
        else
#endif
        {
#if(COM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
            Com_PBConfig = ConfigPtr;
#else
            (void)ConfigPtr;
#endif

#if (STD_ON == COM_RXPDU_FUN)
            Com_RxInit();
#endif

#if (STD_ON == COM_TXPDU_FUN)
            Com_TxInit();
#endif

#if (STD_ON == COM_IPDU_GROUP_FUN)      
            for(grpIdx = (Com_IpduGroupIdType)0; grpIdx < (Com_IpduGroupIdType)COM_PDUGROUP_MAX_NUM; grpIdx++)
            {
                Com_IpduGroupStartFlag[grpIdx] = FALSE;
            }
#endif

#if ((STD_ON == COM_RX_TIMEOUT_MONITOR)&&(STD_ON == COM_IPDU_GROUP_FUN))
            for(grpIdx = (Com_IpduGroupIdType)0; grpIdx < (Com_IpduGroupIdType)COM_PDUGROUP_MAX_NUM; grpIdx++)
            {
                Com_IpduGroupDMEnableFlag[grpIdx] = TRUE;
            }
        
#endif
          
#if (COM_MAX_FILTER_OCCURRENCE_NUM > 0)
            /* Occurrence is only used in config file, so there is no offset index reg for pdu*/
            for(Index = (uint16)0; Index < (uint16)COM_MAX_FILTER_OCCURRENCE_NUM; Index++)
            {
                Com_Sig_Occurrence[Index] = (uint16)0;
            }
#endif
            Com_InitStateFlag = COM_INIT;

        }
    }
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    else
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_INIT, COM_E_CALLED_IN_WRONG_CORE);
    }
#endif

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_DeInit SWS_Com_130
*
* Description:   tx/rx Deinitialize.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_DeInit
(
    void
)
{

    PduIdType IpduIndex = (PduIdType)0;/* sigID PduId will not exceed u16*/
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    if(COM_MASTER_CORE_ID == COM_GETCOREID())
#endif
    {
#if (COM_MAX_FILTER_OCCURRENCE_NUM > 0)
        Com_SignalIdType Index = (Com_SignalIdType)0;
#endif


        /*SWS_Com_129*/
#if (COM_RXPDU_MAX_NUM > 0)
        for(IpduIndex = (PduIdType)0; IpduIndex < COM_RXPDU_NUM; IpduIndex++)
        {
            Com_InitRxPdu(IpduIndex, FALSE);
        }
#endif

#if (COM_TXPDU_MAX_NUM > 0)
        for(IpduIndex = (PduIdType)0; IpduIndex < COM_TXPDU_NUM; IpduIndex++)
        {
            Com_InitTxPdu(IpduIndex, FALSE);
        }
#endif


#if (COM_MAX_FILTER_OCCURRENCE_NUM > 0)
        /* Occurrence is only used in config file, so there is no offset index reg for pdu*/
        for(Index = (uint16)0; Index < (uint16)COM_MAX_FILTER_OCCURRENCE_NUM; Index++)
        {
            Com_Sig_Occurrence[Index] = (uint16)0;
        }
#endif

        Com_InitStateFlag = COM_UNINIT;
    }
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    else
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_DEINIT, COM_E_CALLED_IN_WRONG_CORE);
    }
#endif
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_GetStatus SWS_Com_00194
*
* Description:   Get If Com is Init
*
* Inputs:        None
*
* Outputs:       Com_StatusType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Com_StatusType, COM_CODE) Com_GetStatus
(
    void
)
{
    return Com_InitStateFlag;
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SendSignal SWS_Com_00197
*
* Description:   This service updates the signal object identified by
*                SignalId with the signal referenced by the SignalDataPtr
*                parameter
*
* Inputs:        SignalId: Signal handle
*                SignalDataPtr: Reference to the Signal data to be transmitted
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
                                            large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_SendSignal
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
#endif

#if(STD_ON == COM_TXPDU_FUN)
    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL, COM_E_UNINIT);
    }
    else if(SignalId >= COM_TXSIG_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL, COM_E_PARAM);
    }
    else if(COM_SIG_DYN == COM_CFG_TXSIG_TYPE(SignalId))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL, COM_E_PARAM);
    }
    else if(NULL_PTR == SignalDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL, COM_E_PARAM_POINTER);
    }
    else
    {
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        TxSigCoreId = COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(SignalId));
        ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
        if(TxSigCoreId != ComLogicCoreId)
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_9();

            tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(SignalId);
            if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
            {
                if(TRUE == Com_CheckChangeSignal((void*)SignalDataPtr, COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), COM_CFG_TXSIG_LENGTH(SignalId)))
                {
                    Com_TxSigIsSameValue[SignalId] = FALSE;
                    Com_CopySignalWithOutLock(SignalDataPtr, COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), COM_CFG_TXSIG_LENGTH(SignalId));
                }
                else
                {
                    Com_TxSigIsSameValue[SignalId] = TRUE;
                }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                if(FALSE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(SignalId))
#endif
                {
                    *tempTxSigShareFlagPtr = COM_SIG;
                }
                result = E_OK;
            }

            SchM_Exit_Com_COM_EXCLUSIVE_AREA_9();
        }
        else
#endif
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
            if(TRUE == Com_CheckChangeSignal((void*)SignalDataPtr, COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), COM_CFG_TXSIG_LENGTH(SignalId)))
            {
                Com_TxSigIsSameValue[SignalId] = FALSE;
                Com_CopySignalWithOutLock(SignalDataPtr, COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), COM_CFG_TXSIG_LENGTH(SignalId));
            }
            else
            {
                Com_TxSigIsSameValue[SignalId] = TRUE;
            }
            result = Com_WriteSignal_Internal(SignalId, SignalDataPtr, COM_CFG_TXSIG_LENGTH(SignalId));
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();
        }
    }
#endif/*#if(STD_ON == COM_TXPDU_FUN)*/

    return  result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_InvalidateSignal  SWS_Com_00203
*
* Description:   This service copies the invalid data of signal identified by CFG
*
* Inputs:        SignalId: ignal handle
*
* Outputs:       E_OK
*                COM_SERVICE_NOT_AVAILABLE
*                COM_BUSY
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_InvalidateSignal
(
    Com_SignalIdType SignalId
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;
#if((STD_ON == COM_TXPDU_FUN) && (STD_ON == COM_TX_INVALID_SUPPORT))
    PduLengthType length = (PduLengthType)0;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    Com_SignalGroupIdType TxSigGrpId = COM_INVALID_SIG_GRP_ID;
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
#endif
#endif

#if((STD_ON == COM_TXPDU_FUN) && (STD_ON == COM_TX_INVALID_SUPPORT))
    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_INVALIDATE_SIGNAL, COM_E_UNINIT);
    }
    else if(SignalId >= COM_TXSIG_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_INVALIDATE_SIGNAL, COM_E_PARAM);
    }
    else if(NULL_PTR == COM_CFG_TXSIG_INVALID_VALUE_PTR(SignalId))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_INVALIDATE_SIGNAL, COM_E_PARAM);
    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    /* in this version, only invalidateSignalGrp is allowed*/
    else if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(SignalId))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_INVALIDATE_SIGNAL, COM_E_PARAM);
    }
#endif
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    else if(COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(SignalId)) != COM_GETCOREID())
    {
        /* do nothing */
    }
#endif
    else
    {
        length = COM_CFG_TXSIG_LENGTH(SignalId);
#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
        if(COM_SIG_DYN == COM_CFG_TXSIG_TYPE(SignalId))
        {
            length = COM_CFG_TXSIG_INVALID_VALUE_LEN(SignalId);
        }
#endif

#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        TxSigCoreId = COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(SignalId));
        ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
        if(TxSigCoreId == ComLogicCoreId)
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_9();
            tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(SignalId);
            if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
            {
                Com_CopySignalWithOutLock(COM_CFG_TXSIG_INVALID_VALUE_PTR(SignalId), COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), length);
                Com_TxSigIsSameValue[SignalId] = FALSE;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                if(FALSE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(SignalId))
#endif
                {
                    *tempTxSigShareFlagPtr = COM_SIG;
                }
                result = E_OK;
            }
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_9();
        }
        else
#endif
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
            Com_CopySignalWithOutLock(COM_CFG_TXSIG_INVALID_VALUE_PTR(SignalId), COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), length);
            Com_TxSigIsSameValue[SignalId] = FALSE;
            result = Com_WriteSignal_Internal(SignalId, COM_CFG_TXSIG_INVALID_VALUE_PTR(SignalId), length);
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();
        }

    }
#endif/*#if((STD_ON == COM_TXPDU_FUN) && (STD_ON == COM_TX_INVALID_SUPPORT))*/

    return    result;

}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SendDynSignal  SWS_Com_00627
*
* Description:   This service updates the signal object identified by
*                SignalId with the signal referenced by the SignalDataPtr
*                parameter
*
* Inputs:        SignalId: Signal handle
*                SignalDataPtr: Reference to the Signal data to be transmitted
*                Length: Dyn-Signal length
*
* Outputs:       E_OK
*                COM_SERVICE_NOT_AVAILABLE
*                COM_BUSY
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_SendDynSignal
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    uint16 Length
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;
#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    Com_SignalGroupIdType TxSigGrpId = COM_INVALID_SIG_GRP_ID;
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
#endif
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_DYNSIGNAL, COM_E_UNINIT);
    }
#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
    else if((SignalId >= COM_TXSIG_NUM)
            || (COM_SIG_DYN != COM_CFG_TXSIG_TYPE(SignalId)))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_DYNSIGNAL, COM_E_PARAM);
    }
    else if(NULL_PTR == SignalDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_DYNSIGNAL, COM_E_PARAM_POINTER);
    }
    else
    {
        /* SWS_Com_00334, signal can be updated when pdu is stop
           in stop mode, tms result, txmode and data will be saved
           but trigger will not be saved,
           so that the msg will not be send at once when pdu is started
        */
        if(Length > COM_CFG_TXSIG_LENGTH(SignalId))
        {
            COM_DET_REPORT_ERROR(COMSERVICEID_SEND_DYNSIGNAL, COM_E_PARAM);
            result = E_NOT_OK;
        }
        else
        {
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
            TxSigCoreId = COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(SignalId));
            ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
            if(TxSigCoreId != ComLogicCoreId)
            {
                SchM_Enter_Com_COM_EXCLUSIVE_AREA_9();

                tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(SignalId);
                if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
                {
                    if(TRUE == Com_CheckChangeSignal((void*)SignalDataPtr, COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), COM_CFG_TXSIG_LENGTH(SignalId)))
                    {
                        Com_TxSigIsSameValue[SignalId] = FALSE;
                        Com_CopySignalWithOutLock(SignalDataPtr, COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), COM_CFG_TXSIG_LENGTH(SignalId));
                    }
                    else
                    {
                        Com_TxSigIsSameValue[SignalId] = TRUE;
                    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                    if(FALSE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(SignalId))
#endif
                    {
                        *tempTxSigShareFlagPtr = COM_SIG;
                    }
                    result = E_OK;
                }

                SchM_Exit_Com_COM_EXCLUSIVE_AREA_9();
            }
            else
#endif
            {
                SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
                if(TRUE == Com_CheckChangeSignal((void*)SignalDataPtr, COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), COM_CFG_TXSIG_LENGTH(SignalId)))
                {
                    Com_TxSigIsSameValue[SignalId] = FALSE;
                    Com_CopySignalWithOutLock(SignalDataPtr, COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), COM_CFG_TXSIG_LENGTH(SignalId));
                }
                else
                {
                    Com_TxSigIsSameValue[SignalId] = TRUE;
                }
                result = Com_WriteSignal_Internal(SignalId, SignalDataPtr, Length);
                SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();
            }

        }
    }
#else
    else
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_DYNSIGNAL, COM_E_PARAM);
    }
#endif/*#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)*/



    return  result;

}


/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_TxConfirmation SWS_Com_00124
*
* Description:   tx confirmation when transmit successful.
*
* Inputs:        TxPduId, Result
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_TxConfirmation
(
    PduIdType TxPduId,
    Std_ReturnType Result
)
{
    Com_TxPduStateType pduState;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
#endif
    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TX_CONFIRMATION, COM_E_UNINIT);
    }
#if(STD_ON == COM_TXPDU_FUN)
    else if(TxPduId >= COM_TXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TX_CONFIRMATION, COM_E_PARAM);
    }
#if(STD_ON == COM_TX_LONG_PDU_FUN)
    else if(TRUE == COM_CFG_TXPDU_IS_TP_PDU(TxPduId))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TX_CONFIRMATION, COM_E_PARAM);
    }
#endif
    else
    {
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        TxSigCoreId = COM_CFG_TXPDU_CORE_ID(TxPduId);
        ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
        if(TxSigCoreId != ComLogicCoreId)
        {
            /*do nothing*/
        }
        /* None type Pdu like Lin Pdu, is controlled by other module like linif,
           but com may need to monitor timeout with this txconfirmation ,
           also need to call rte_TxAck to uplayer module*/
        /*SWS_Com_00800 STOP Pdu ignor txConf*/
        else
#endif
        if(COM_TXPDU_STOP == Com_TxPduState[TxPduId])
        {
            /*do nothing*/
        }
        else if((COM_TXPDU_START_BUSY == Com_TxPduState[TxPduId]) || (COM_TXPDU_TXMODE(TxPduId) == COM_PDU_NONE))
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_1();
            if(E_OK == Result)
            {
                pduState = COM_TXPDU_START_TXOK;
            }
            else
            {
                pduState = COM_TXPDU_START_TXNOTOK;/*TXNOTOK not used in this version*/
            }
#if(STD_ON == COM_TX_IMMEDIATE_SUPPORT)
            if(TRUE == COM_CFG_TXPDU_IS_IMM_PROCESSING(TxPduId))
            {
                /* switch IDLE in this fucntion as nothinf need to do in mainfuntionTx*/
                Com_ProcessTxConf(TxPduId, pduState);
            }
            else
#endif
            {
                /* set to OK, process will be done in mainfuntionTx*/
                Com_TxPduState[TxPduId] = pduState;
            }
#if(COM_TX_UPDATEBIT_SUPPORT == STD_ON)
            /*SWS_Com_00577*/
            if(COM_CUB_CONF == COM_CFG_TXPDU_UPDATEBIT_CLEARTYPE(TxPduId))
            {
                Com_ClearUpdateBit(TxPduId);
            }
#endif

#if(STD_ON == COM_MDT_CYCLIC_TRANSMISSION)/*SWS_Com_00469, reset min delay timer when txConf is received*/
            if((COM_TXPDU_TXMODE(TxPduId) != COM_PDU_NONE)
                    && (COM_CFG_TXPDU_MIN_DELAY_TIMER(TxPduId) > (uint16)0)
                    && (COM_TXPDU_MIN_DELAY_TIMER(TxPduId) != (uint16)0)
                    && (COM_TXPDU_MIN_DELAY_TIMER(TxPduId) != COM_TIMER_STOP_VAL))
            {
                /* no MDT for NONE pdu*/
                COM_TXPDU_MIN_DELAY_TIMER(TxPduId) = COM_CFG_TXPDU_MIN_DELAY_TIMER(TxPduId);
            }
#endif
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_1();
        }
    }

#endif/*#if(STD_ON == COM_TXPDU_FUN)*/
}


/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_MainFunctionTx SWS_Com_00399
*
* Description:    process tx msg of com
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_MainFunctionTx
(
#if(COM_TX_MULTI_MAINFUNCTION_ENABLE == STD_ON)
    uint8 CycleIndex
#else
    void
#endif
)
{
#if(STD_ON == COM_TXPDU_FUN)
    PduIdType TxIpduId = (PduIdType)0;
    boolean sendFlag = FALSE;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 ComPhyCoreId = COM_GETCOREID();
    uint8 ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
#endif
#if((STD_ON == COM_MULTI_CORE_SUPPORT) || (COM_TX_MULTI_MAINFUNCTION_ENABLE == STD_ON))
    PduIdType TxIpduIdIndex;
    PduIdType TxPduNum;
    P2CONST(PduIdType, AUTOMATIC, COM_CONST) tmpTxPduPtr = NULL_PTR;
#endif
#endif

    if(COM_INIT != Com_InitStateFlag) /*SWS_Com_00665*/
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_MAIN_FUNCTION_TX, COM_E_UNINIT);
    }
#if(STD_ON == COM_TXPDU_FUN)
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    else if((COM_INVALID_CORE_ID == ComLogicCoreId) || ((PduIdType)0 == COM_CFG_CORE_TXPDU_NUM(ComLogicCoreId)))
    {
        /* do nothing */
    }
#if(COM_TX_MULTI_MAINFUNCTION_ENABLE == STD_ON)
    else if((CycleIndex >= COM_TX_MAINFUNCTION_NUMBER) || (Com_MainTxCfg[CycleIndex].CoreRef != ComLogicCoreId))
    {
        /* do nothing */
    }
#endif
#endif
    else
    {
#if(COM_TX_MULTI_MAINFUNCTION_ENABLE == STD_ON)
        tmpTxPduPtr = Com_MainTxCfg[CycleIndex].PduIdPtr;
        TxPduNum = Com_MainTxCfg[CycleIndex].PduNum;
        for(TxIpduIdIndex = (PduIdType)0; TxIpduIdIndex < TxPduNum; TxIpduIdIndex++)
#elif(STD_ON == COM_MULTI_CORE_SUPPORT)
        tmpTxPduPtr = COM_CFG_CORE_TXPDU_TABLE(ComLogicCoreId);
        TxPduNum = COM_CFG_CORE_TXPDU_NUM(ComLogicCoreId);
        for(TxIpduIdIndex = (PduIdType)0; TxIpduIdIndex < TxPduNum; TxIpduIdIndex++)
#else
        for(TxIpduId = (PduIdType)0; TxIpduId < COM_TXPDU_NUM; TxIpduId++)
#endif
        {
#if((STD_ON == COM_MULTI_CORE_SUPPORT) || (COM_TX_MULTI_MAINFUNCTION_ENABLE == STD_ON))
            TxIpduId = tmpTxPduPtr[TxIpduIdIndex];
#endif
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_9();
            Com_CrossCoreTxSignalsTack(TxIpduId);
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_9();
#endif

            if(COM_TXPDU_STOP != Com_TxPduState[TxIpduId])
            {
                SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();

                if(Com_TxPduState[TxIpduId] >= COM_TXPDU_START_TXOK)
                {
#if(STD_ON == COM_TX_IMMEDIATE_SUPPORT)
                    if(FALSE == COM_CFG_TXPDU_IS_IMM_PROCESSING(TxIpduId))
#endif
                    {
                        Com_ProcessTxConf(TxIpduId, Com_TxPduState[TxIpduId]);
                    }
                }

#if(STD_ON == COM_TX_TIMEOUT_MONITOR)
                Com_TxTimerOutMonitor(TxIpduId);
#endif

                /* switch txMode if needed, reset TxRegs acrroding to the new TxMode*/
                Com_SelectPduTxMode(TxIpduId, Com_SendSwitchTxModeFlag[TxIpduId]);
                Com_SendSwitchTxModeFlag[TxIpduId] = COM_NO_TXMODE_SWITCH;

                /* check if there is tx request this cycle*/
                sendFlag = Com_TxModeProcess(TxIpduId);

#if(STD_ON == COM_MDT_CYCLIC_TRANSMISSION)
                if(COM_TIMER_STOP_VAL != COM_TXPDU_MIN_DELAY_TIMER(TxIpduId))
                {
                    if((uint16)0 != COM_TXPDU_MIN_DELAY_TIMER(TxIpduId))
                    {
                        COM_TXPDU_MIN_DELAY_TIMER(TxIpduId)--;
                    }
                    if((uint16)0 == COM_TXPDU_MIN_DELAY_TIMER(TxIpduId))
                    {
                        COM_TXPDU_MIN_DELAY_TIMER(TxIpduId) = COM_TIMER_STOP_VAL;
                    }
                    else
                    {
                        if(TRUE == sendFlag)
                        {
                            COM_TXPDU_TX_REQ_MINDELAY_BACKUP(TxIpduId) = TRUE;
                        }

                        sendFlag = FALSE;

                    }
                }
#endif

#if(STD_ON == COM_TX_LONG_PDU_FUN)/*SWS_Com_00863*/
                if((TRUE == sendFlag)
                        && (TRUE == COM_CFG_TXPDU_IS_TP_PDU(TxIpduId))
                        && (COM_TXPDU_START_BUSY == Com_TxPduState[TxIpduId]))
                {
                    sendFlag = FALSE;
                    COM_DET_REPORT_RUNTIME_ERROR(COMSERVICEID_MAIN_FUNCTION_TX, COM_E_SKIP_TRANSMISSION);
                }
#endif

                if(TRUE == sendFlag)
                {
                    Com_TransmitPdu(TxIpduId);/*SWS_Com_478*/
                }
                SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();

            }
        }
    }
#endif /*#if(STD_ON == COM_TXPDU_FUN)*/
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_RxIndication  SWS_Com_00123
*
* Description:   rx indication when rx Ipdu.
*
* Inputs:        RxPduId,PduInfoPtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_RxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
)
{
#if(COM_RXIPDU_CALLOUT == STD_ON)
    boolean Com_RxCalResult = TRUE;
#endif
#if(COM_RXIPDU_CALLOUT == STD_ON)
    /* this ptr must remove const as e2e may need change*/
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) tempPduInfoPtr = (PduInfoType *)PduInfoPtr;
#endif
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 RxPduCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
#endif
#if(STD_ON == COM_RX_IMMEDIATE_SUPPORT)
    uint8 PduTempBuffer[COM_RX_PDU_MAX_ARRAY_SZIE] = {(uint8)0};
#endif
    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RX_INDICATION, COM_E_UNINIT);
    }
    else if(RxPduId >= COM_RXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RX_INDICATION, COM_E_PARAM);
    }
    else if(PduInfoPtr == NULL_PTR)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RX_INDICATION, COM_E_PARAM_POINTER);
    }
    else if(PduInfoPtr->SduDataPtr == NULL_PTR)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RX_INDICATION, COM_E_PARAM_POINTER);
    }
#if(STD_ON == COM_RXPDU_FUN)
#if(STD_ON == COM_RX_LONG_PDU_FUN)
    else if(TRUE == COM_CFG_RXPDU_IS_TP_PDU(RxPduId))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RX_INDICATION, COM_E_PARAM);
    }
#endif
    else if(FALSE == Com_CheckRxLength(RxPduId, PduInfoPtr->SduLength))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RX_INDICATION, COM_E_PARAM);
    }
    else
    {
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        RxPduCoreId = COM_CFG_RXPDU_CORE_ID(RxPduId);
        ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
        if(RxPduCoreId != ComLogicCoreId)
        {
            /*do nothing*/
        }
        else
#endif
        if(COM_RXPDU_START_IDLE == Com_RxPduState[RxPduId])
        {
            /* when imm pdu, reset timeout at once*/
#if((STD_ON == COM_RX_TIMEOUT_MONITOR) && (STD_ON == COM_RX_IMMEDIATE_SUPPORT))
            if((TRUE == COM_RXPDU_MONITOR_FLAG(RxPduId)) && (TRUE == COM_CFG_RXPDU_IS_IMM_PROCESSING(RxPduId)))
            {
                COM_RXPDU_TIMEOUT(RxPduId) = COM_CFG_RXPDU_PERIOD_TIMEOUT(RxPduId);/*SWS_Com_00715*/
            }
#endif
#if(COM_RXIPDU_CALLOUT == STD_ON)
            if(NULL_PTR != COM_CFG_RXPDU_CALLOUT(RxPduId))
            {
                Com_RxCalResult = COM_CFG_RXPDU_CALLOUT(RxPduId)(RxPduId, tempPduInfoPtr);
            }
            if(FALSE == Com_RxCalResult)
            {
                Com_RxPduState[RxPduId] = COM_RXPDU_START_RXSTOP;
#if ((STD_ON == COM_RX_INVALID_SUPPORT) && (STD_ON == COM_RX_IMMEDIATE_SUPPORT))
                if(TRUE == COM_CFG_RXPDU_IS_IMM_PROCESSING(RxPduId))
                {
                    /*call invalid ack, or replace invalid value to signal SWS_Com_00839*/
                    Com_RxPduInvalid(RxPduId);
                    Com_RxPduState[RxPduId] = COM_RXPDU_START_IDLE;
#if(STD_ON == COM_RX_INDICATION_CALLOUT_SUPPORT)
                    Com_E2E_RxIndicationCallout(RxPduId);
#endif
                }
#endif
            }
            else
#endif
            {
                SchM_Enter_Com_COM_EXCLUSIVE_AREA_3();
                Com_RxPduState[RxPduId] = COM_RXPDU_START_RXOK;

                /* temp buf is not null, copy to temp first
                   data may need to be copy in following cases:
                   1. need rx filter
                   2. need check invalid
                   3. has update bit
                */
                /* Copy data and length, if pdu is dyn pdu, dyn length also copied*/
                /* process if imm*/
                COM_RXPDU_TEMP_LENGTH(RxPduId)  = PduInfoPtr->SduLength;
                Bsw_MemCpy((uint8 *)COM_CFG_RXPDU_DATA_PTR(RxPduId), PduInfoPtr->SduDataPtr, (uint32)PduInfoPtr->SduLength);
#if(STD_ON == COM_RX_IMMEDIATE_SUPPORT)
                Bsw_MemCpy(PduTempBuffer, COM_CFG_RXPDU_DATA_PTR(RxPduId), (uint32)COM_CFG_RXPDU_LENGTH(RxPduId));
#endif
                SchM_Exit_Com_COM_EXCLUSIVE_AREA_3();
#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)/* dynlength must be copy here too*/
                if(TRUE == COM_CFG_RXPDU_IS_DYN(RxPduId))
                {
                    COM_RXPDU_DYN_LENGTH(RxPduId) = COM_RXPDU_TEMP_LENGTH(RxPduId);
                }
#endif
#if(STD_ON == COM_RX_IMMEDIATE_SUPPORT)
                if(TRUE == COM_CFG_RXPDU_IS_IMM_PROCESSING(RxPduId))/*SWS_Com_00300*/
                {
                    Com_HandleRxPdu(RxPduId, PduTempBuffer);
                    Com_RxPduState[RxPduId] = COM_RXPDU_START_IDLE;
#if(STD_ON == COM_RX_INDICATION_CALLOUT_SUPPORT)
                    Com_E2E_RxIndicationCallout(RxPduId);
#endif
                }
#endif
            }

        }
    }
#endif/* #if(STD_ON == COM_RXPDU_FUN) */
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_MainFunctionRx SWS_Com_0039
*
* Description:   process rx msg of com
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_MainFunctionRx
(
#if(COM_RX_MULTI_MAINFUNCTION_ENABLE == STD_ON)
    uint8 CycleIndex
#else
    void
#endif
)
{
    uint8 PduTempBuffer[COM_RX_PDU_MAX_ARRAY_SZIE] = {(uint8)0};
#if(STD_ON == COM_RXPDU_FUN)
    PduIdType RxIpduId = (PduIdType)0;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 ComPhyCoreId = COM_GETCOREID();
    uint8 ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
#endif
#if((STD_ON == COM_MULTI_CORE_SUPPORT) || (COM_RX_MULTI_MAINFUNCTION_ENABLE == STD_ON))
    PduIdType RxIpduIdIndex;
    PduIdType RxPduNum;
    P2CONST(PduIdType, AUTOMATIC, COM_CONST) tmpRxPduPtr = NULL_PTR;
#endif
#endif

    if(COM_INIT != Com_InitStateFlag)/*SWS_Com_00664*/
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_MAIN_FUNCTION_RX, COM_E_UNINIT);
    }
#if(STD_ON == COM_RXPDU_FUN)
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    else if((COM_INVALID_CORE_ID == ComLogicCoreId) || ((PduIdType)0 == COM_CFG_CORE_RXPDU_NUM(ComLogicCoreId)))
    {
        /* do nothing */
    }
#if(COM_RX_MULTI_MAINFUNCTION_ENABLE == STD_ON)
    else if((CycleIndex >= COM_RX_MAINFUNCTION_NUMBER) || (Com_MainRxCfg[CycleIndex].CoreRef != ComLogicCoreId))
    {
        /* do nothing */
    }
#endif
#endif
    else
    {
#if(COM_RX_MULTI_MAINFUNCTION_ENABLE == STD_ON)
        tmpRxPduPtr = Com_MainRxCfg[CycleIndex].PduIdPtr;
        RxPduNum = Com_MainRxCfg[CycleIndex].PduNum;
        for(RxIpduIdIndex = (PduIdType)0; RxIpduIdIndex < RxPduNum; RxIpduIdIndex++)
#elif(STD_ON == COM_MULTI_CORE_SUPPORT)
        tmpRxPduPtr = COM_CFG_CORE_RXPDU_TABLE(ComLogicCoreId);
        RxPduNum = COM_CFG_CORE_RXPDU_NUM(ComLogicCoreId);
        for(RxIpduIdIndex = (PduIdType)0; RxIpduIdIndex < RxPduNum; RxIpduIdIndex++)
#else
        for(RxIpduId = (PduIdType)0; RxIpduId < COM_RXPDU_NUM; RxIpduId++)
#endif
        {
#if((STD_ON == COM_MULTI_CORE_SUPPORT) || (COM_RX_MULTI_MAINFUNCTION_ENABLE == STD_ON))
            RxIpduId = tmpRxPduPtr[RxIpduIdIndex];
#endif
            if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
            {
#if(STD_ON == COM_RX_IMMEDIATE_SUPPORT)
                if((Com_RxPduState[RxIpduId] >= COM_RXPDU_START_RXOK)
                    &&(FALSE == COM_CFG_RXPDU_IS_IMM_PROCESSING(RxIpduId)))
#else
                if(Com_RxPduState[RxIpduId] >= COM_RXPDU_START_RXOK)
#endif
                {
#if(STD_ON == COM_RX_LONG_PDU_FUN)
                    COM_RXPDU_TP_INDEX(RxIpduId) = (PduLengthType)0;
#endif
#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
                    if(TRUE == COM_RXPDU_MONITOR_FLAG(RxIpduId))
                    {
                        COM_RXPDU_TIMEOUT(RxIpduId) = COM_CFG_RXPDU_PERIOD_TIMEOUT(RxIpduId);/*SWS_Com_00715*/
                    }
#endif
                    if(Com_RxPduState[RxIpduId] == COM_RXPDU_START_RXOK)
                    {
                        SchM_Enter_Com_COM_EXCLUSIVE_AREA_2();
                        Bsw_MemCpy(PduTempBuffer, COM_CFG_RXPDU_DATA_PTR(RxIpduId), (uint32)COM_CFG_RXPDU_LENGTH(RxIpduId));
                        SchM_Exit_Com_COM_EXCLUSIVE_AREA_2();
                        Com_HandleRxPdu(RxIpduId, PduTempBuffer);
                    }
                    /* RXSTOP or NOTOK, do invalid action*/
#if(STD_ON == COM_RX_INVALID_SUPPORT)
                    else
                    {
                        Com_RxPduInvalid(RxIpduId);/*SWS_Com_00839*/
                    }
#endif
                    Com_RxPduState[RxIpduId] = COM_RXPDU_START_IDLE;
#if(STD_ON == COM_RX_INDICATION_CALLOUT_SUPPORT)
                    Com_E2E_RxIndicationCallout(RxIpduId);
#endif
                }

#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
                if(TRUE == COM_RXPDU_MONITOR_FLAG(RxIpduId))
                {
                    Com_RxTimerOutMonitor(RxIpduId);
#if(STD_ON == COM_RX_SIGNAL_UB_TIMEOUT_SUPPORT)
                    Com_UpdateRxTimerOutMonitor(RxIpduId);
#endif
                }
#endif
            }
        }
    }
#endif/* #if(STD_ON == COM_RXPDU_FUN)*/
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ReceivedSignal
*
* Description:   This service copies the data of signal identified by SignalId
*                to the location specified by SignalDataPtr
*
* Inputs:        SignalId: ignal handle
*                SignalDataPtr: Reference to the location where the received
*                               signal data shall be stored
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
*                                           large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_ReceiveSignal
(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr
)
{

    uint8 result = COM_SERVICE_NOT_AVAILABLE;
#if(STD_ON == COM_RXPDU_FUN)
    PduIdType RxIpduId;
    PduLengthType SigLen = (PduLengthType)0;
    Com_SigType SigType;
    P2VAR(void, AUTOMATIC, COM_VAR) tempRxSigBuf = NULL_PTR;
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL, COM_E_UNINIT);
    }
    else if(SignalId >= COM_RXSIG_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL, COM_E_PARAM);
    }
#if(STD_ON == COM_RXPDU_FUN)
    else if(COM_SIG_DYN == COM_CFG_RXSIG_TYPE(SignalId))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL, COM_E_PARAM);
    }
    else if(NULL_PTR == SignalDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL, COM_E_PARAM_POINTER);
    }
    else
    {
        RxIpduId = COM_CFG_RXSIG_RXPDU_ID(SignalId);
        /* dont need report busy , as copy process is protected by Area2
           and always read old data
        */

        SigLen = COM_CFG_RXSIG_LENGTH(SignalId);
        SigType = COM_CFG_RXSIG_TYPE(SignalId);
        tempRxSigBuf = COM_CFG_RXSIG_DATA_PTR(SignalId);
        Com_CopySignal(tempRxSigBuf, SignalDataPtr, SigType, SigLen, SignalId);

        /*
           when stop , read old data but return COM_SERVICE_NOT_AVAILABLE, no det err
           See Page54 Table3
        */

        if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
        {
            result = E_OK;
        }

    }

#endif/* #if(STD_ON == COM_RXPDU_FUN)*/
    return    result;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ReceiveDynSignal
*
* Description:   This service copies the data of signal identified by SignalId
*                to the location specified by SignalDataPtr
*
* Inputs:        SignalId: ignal handle
*                SignalDataPtr: Reference to the location where the received
*                               signal data shall be stored
*                Length
*
* Outputs:       E_OK:                      service has been accepted
*                E_NOT_OK:                  in case the Length (as in-parameter) 
*                                           is smaller than the received length 
*                                           of the dynamic length signal
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
*                                           large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_ReceiveDynSignal
(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    P2VAR(uint16, AUTOMATIC, COM_APPL_DATA) Length
)
{

    uint8 result = E_NOT_OK;
#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)
    PduIdType RxIpduId;
    Com_SigType SigType;
    PduLengthType dynlength = (PduLengthType)0;
    /* as dyn signal must be byte aligned, so the temp srcDataPtr canbe uint8 * Ptr*/
    PduLengthType tempRxPduDynLen = (PduLengthType)0;
    P2VAR(uint8, AUTOMATIC, COM_VAR) srcDataPtr = NULL_PTR;
    P2VAR(void, AUTOMATIC, COM_VAR) tempRxSigBuf = NULL_PTR;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    Com_RxSigLockIndexType RxSigLockIndex = COM_CFG_RXSIG_LOCK_INDEX(SignalId);
#endif
#endif
    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_DYNSIGNAL, COM_E_UNINIT);
    }
#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)
    else if(SignalId >= COM_RXSIG_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_DYNSIGNAL, COM_E_PARAM);
    }
    else if(COM_SIG_DYN != COM_CFG_RXSIG_TYPE(SignalId))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_DYNSIGNAL, COM_E_PARAM);
    }

    else if(NULL_PTR == SignalDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL, COM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == Length)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL, COM_E_PARAM_POINTER);
    }
    else
    {
        /* dont need report busy , as copy process is protected by Area2
           and always read old data
        */
        RxIpduId = COM_CFG_RXSIG_RXPDU_ID(SignalId);
        SigType = COM_CFG_RXSIG_TYPE(SignalId);
        tempRxSigBuf = COM_CFG_RXSIG_DATA_PTR(SignalId);
        srcDataPtr = (uint8 *)tempRxSigBuf;
        if(*Length < dynlength)
        {
            COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_DYNSIGNAL, COM_E_PARAM);
        }
        else
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_13();
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
            COM_GETSPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
            tempRxPduDynLen = COM_RXPDU_DYN_LENGTH(RxIpduId);
            dynlength = tempRxPduDynLen - COM_CFG_RXSIG_START_BYTE_INDEX(SignalId);
            Bsw_MemCpy((uint8 *)SignalDataPtr, srcDataPtr, (uint32)dynlength);
            *Length = dynlength;
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
            COM_RELEASESPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_13();
            /*
                when stop , read old data but return COM_SERVICE_NOT_AVAILABLE, no det err
                See Page54 Table3
            */
            if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
            {
                result = E_OK;
            }
            else
            {
                result = COM_SERVICE_NOT_AVAILABLE;
            }
        }

    }
#else
    else
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_DYNSIGNAL, COM_E_PARAM);
    }
#endif/*#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)*/

    return    result;

}





/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SwitchIpduTxMode SWS_Com_00784
*
* Description:   This service copies the data of signal identified by SignalId
*                to the location specified by SignalDataPtr
*
* Inputs:        PduId
*                Mode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_SwitchIpduTxMode
(
    PduIdType PduId,
    boolean Mode
)
{
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 ComPhyCoreId = COM_GETCOREID();
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SWITCH_IPDU_TX_MODE, COM_E_UNINIT);
    }
    else if(PduId >= COM_TXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SWITCH_IPDU_TX_MODE, COM_E_PARAM);
    }
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    else if(COM_CFG_TXPDU_CORE_ID(PduId) != ComCfgCorePhyMapLogic[ComPhyCoreId])
    {
        /* do nothing */
    }
#endif
    else
    {
#if(STD_ON == COM_TXPDU_FUN)
        /*
            Can switch mode when pdu is stop
            new txmode will be active when pdu is restart
        */
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
        if(TRUE == Mode)
        {
            if(NULL_PTR != COM_CFG_TXPDU_TXMODE_TRUE_PTR(PduId))
            {
                Com_SendSwitchTxModeFlag[PduId] = COM_TXMODE_SWITCH_API_TRUE;
            }
        }
        else
        {
            if(NULL_PTR != COM_CFG_TXPDU_TXMODE_FALSE_PTR(PduId))
            {
                Com_SendSwitchTxModeFlag[PduId] = COM_TXMODE_SWITCH_API_FALSE;
            }

        }
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();
#endif
    }
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_TriggerIPDUSend SWS_Com_00348
*
* Description:
*
* Inputs:        PduId: ignal handle
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COM_CODE) Com_TriggerIPDUSend
(
    PduIdType PduId
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 ComPhyCoreId = COM_GETCOREID();
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TRIGGER_IPDU_SEND, COM_E_UNINIT);
    }
    else if(PduId >= COM_TXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TRIGGER_IPDU_SEND, COM_E_PARAM);
    }
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    else if(COM_CFG_TXPDU_CORE_ID(PduId) != ComCfgCorePhyMapLogic[ComPhyCoreId])
    {
        /* do nothing */
    }
#endif
    else
    {
#if(STD_ON == COM_TriggerIPDUSend_API)
        if(COM_TXPDU_STOP != Com_TxPduState[PduId])/*SWS_Com_00861*/
        {
            Com_TriggerPDUSendFlag[PduId] = TRUE;
            ret = E_OK;
        }
#endif
    }

    return ret;
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_TriggerTransmit SWS_Com_00001
*
* Description:   This service copies the data  to  PduInfoPtr
*
* Inputs:        TxPduId: ignal handle
*                PduInfoPtr: Reference to the location where the tx
*                            data shall be stored
*
* Outputs:       E_OK
*                E_NOT_OK
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COM_CODE)Com_TriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
)
{

    Std_ReturnType result = E_NOT_OK;
#if(STD_ON == COM_TXPDU_FUN)
    PduLengthType length = (PduLengthType)0;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 ComPhyCoreId = COM_GETCOREID();
#endif
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TRIGGER_TRANSMIT, COM_E_UNINIT);
    }
#if(STD_ON == COM_TXPDU_FUN)
    else if(TxPduId >= COM_TXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TRIGGER_TRANSMIT, COM_E_PARAM);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TRIGGER_TRANSMIT, COM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == (PduInfoPtr->SduDataPtr))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TRIGGER_TRANSMIT, COM_E_PARAM_POINTER);
    }
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    else if(COM_CFG_TXPDU_CORE_ID(TxPduId) != ComCfgCorePhyMapLogic[ComPhyCoreId])
    {
        /* do nothing only return notok*/
    }
#endif
    else
    {
        /*length check */ /*SWS_Com_869*/
        length = COM_CFG_TXPDU_LENGTH(TxPduId);
#if (STD_ON == COM_TX_DYN_PDU_SUPPORT)
        if(TRUE == COM_CFG_TXPDU_IS_DYN(TxPduId))
        {
            length = COM_TXPDU_DYN_LENGTH(TxPduId);
        }
#endif

        if(PduInfoPtr->SduLength < length)
        {
            COM_DET_REPORT_ERROR(COMSERVICEID_TRIGGER_TRANSMIT, COM_E_PARAM);
        }
        else
        {
            if(COM_TXPDU_STOP != Com_TxPduState[TxPduId])
            {
                SchM_Enter_Com_COM_EXCLUSIVE_AREA_6();
#if(STD_ON == COM_TX_TRIGGER_CALLOUT_SUPPORT)
                if(NULL_PTR != COM_CFG_TXPDU_TRIGGER_CALLOUT(TxPduId))
                {
                    /*SWS_Com_395 ignor the return value of this callout. why?*/
                    (void)COM_CFG_TXPDU_TRIGGER_CALLOUT(TxPduId)(TxPduId, PduInfoPtr); /*SWS_Com_766 */
                }
#elif(STD_ON == COM_TX_E2E_TRIGGER_CALLOUT_SUPPORT)
                E2E_Com_TransmitCallout(TxPduId);
#endif
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
                Com_CrossCoreTxSignalsTack(TxPduId);
#endif
                /*SWS_Com_647*/
                Bsw_MemCpy(PduInfoPtr->SduDataPtr, (uint8 *)COM_CFG_TXPDU_DATA_PTR(TxPduId), (uint32)length);
                PduInfoPtr->SduLength = length;
#if(COM_TX_UPDATEBIT_SUPPORT == STD_ON)
                if(COM_CUB_TRIGGER == COM_CFG_TXPDU_UPDATEBIT_CLEARTYPE(TxPduId))
                {
                    Com_ClearUpdateBit(TxPduId);
                }
#endif

                SchM_Exit_Com_COM_EXCLUSIVE_AREA_6();

                result = E_OK;
            }

        }
    }
#endif/*#if(STD_ON == COM_TXPDU_FUN)*/
    return result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_TpTxConfirmation SWS_Com_00725
*
* Description:   Callbak function Com provided by Com to Tp
*
* Inputs:        PduId:  Receive PduId
*                Result: NTFRSLT_OK means the complete N-PDU has been eceived
*                        and is stored in the receive buffer.Any other value
*                        means the N_PDU has not been received,
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_TpTxConfirmation
(
    PduIdType TxPduId,
    Std_ReturnType Result
)
{
#if(STD_ON == COM_TX_LONG_PDU_FUN)
    Com_TxPduStateType pduState;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 ComPhyCoreId = COM_GETCOREID();
#endif
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TP_TX_CONFIGURATION, COM_E_UNINIT);
    }
#if(STD_ON == COM_TX_LONG_PDU_FUN)
    else if(TxPduId >= COM_TXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TP_TX_CONFIGURATION, COM_E_PARAM);
    }
    else if(FALSE == COM_CFG_TXPDU_IS_TP_PDU(TxPduId))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TP_TX_CONFIGURATION, COM_E_PARAM);
    }
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    else if(COM_CFG_TXPDU_CORE_ID(TxPduId) != ComCfgCorePhyMapLogic[ComPhyCoreId])
    {
        /* do nothing */
    }
#endif
    else
    {
        /* dont consider None Pdu here as  tp will callCopyTxDta first*/
        /*SWS_Com_00800 STOP Pdu ignor txConf*/
        if(COM_TXPDU_START_BUSY == Com_TxPduState[TxPduId])
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_10();
            if(E_OK == Result)
            {
                pduState = COM_TXPDU_START_TXOK;

            }
            else
            {
                pduState = COM_TXPDU_START_TXNOTOK;/*TXNOTOK not used in this version*/
            }
#if(STD_ON == COM_TX_IMMEDIATE_SUPPORT)
            if(TRUE == COM_CFG_TXPDU_IS_IMM_PROCESSING(TxPduId))
            {
                /* switch IDLE in this fucntion as nothinf need to do in mainfuntionTx*/
                Com_ProcessTxConf(TxPduId, pduState);
            }
            else
#endif
            {
                /* set to OK or notok, process will be done in mainfuntionTx*/
                Com_TxPduState[TxPduId] = pduState;
            }
#if(COM_TX_UPDATEBIT_SUPPORT == STD_ON)
            /*SWS_Com_00577*/
            if(COM_CUB_CONF == COM_CFG_TXPDU_UPDATEBIT_CLEARTYPE(TxPduId))
            {
                Com_ClearUpdateBit(TxPduId);
            }
#endif

#if(STD_ON == COM_MDT_CYCLIC_TRANSMISSION)/*SWS_Com_00469, reset min delay timer when txConf is received*/
            if((COM_TXPDU_TXMODE(TxPduId) != COM_PDU_NONE)
                    && (COM_CFG_TXPDU_MIN_DELAY_TIMER(TxPduId) > (uint16)0)
                    && (COM_TXPDU_MIN_DELAY_TIMER(TxPduId) != (uint16)0)
                    && (COM_TXPDU_MIN_DELAY_TIMER(TxPduId) != COM_TIMER_STOP_VAL))
            {
                /* no MDT for NONE pdu*/
                COM_TXPDU_MIN_DELAY_TIMER(TxPduId) = COM_CFG_TXPDU_MIN_DELAY_TIMER(TxPduId);
            }
#endif
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_10();

        }
    }
#else
    else
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TP_TX_CONFIGURATION, COM_E_PARAM);
    }
#endif /*#if(STD_ON == COM_TX_LONG_PDU_FUN)*/

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_CopyTxData SWS_Com_00693
*
* Description:   Callbak function Com provided by Com to Tp
*
* Inputs:        PduId:   Transmitt PduId
*                PduInfoPtr:   Pointer to a PduInfoType, which indicates the
*                              number of bytes to be copied (SduLength) and the
*                              location where the data have to be copied to
*                              SduDataPtr).
*                RetryInfoPtr: None used
*                TxDataCntPtr: Remaining Tx data after completion of this call
*
* Outputs:       BUFREQ_OK, BUFREQ_E_NOT_OK
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, COM_CODE) Com_CopyTxData
(
    PduIdType PduId,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr,
    P2CONST(RetryInfoType, AUTOMATIC, COM_APPL_DATA) RetryInfoPtr,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) TxDataCntPtr
)
{

    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#if(STD_ON == COM_TX_LONG_PDU_FUN)
    PduLengthType maxLength;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 ComPhyCoreId = COM_GETCOREID();
#endif
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_COPY_TX_DATA, COM_E_UNINIT);
    }
#if(STD_ON == COM_TX_LONG_PDU_FUN)
    else if(PduId >= COM_TXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_COPY_TX_DATA, COM_E_PARAM);
    }
    else if(FALSE == COM_CFG_TXPDU_IS_TP_PDU(PduId))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_COPY_TX_DATA, COM_E_PARAM);
    }
    else if(COM_TXPDU_STOP == Com_TxPduState[PduId])/*SWS_Com_00783*/
    {
        /* do nothing only return notok*/
    }
    else if(NULL_PTR == TxDataCntPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_COPY_TX_DATA, COM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_COPY_TX_DATA, COM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == PduInfoPtr->SduDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_COPY_TX_DATA, COM_E_PARAM_POINTER);
    }
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    else if(COM_CFG_TXPDU_CORE_ID(PduId) != ComCfgCorePhyMapLogic[ComPhyCoreId])
    {
        /* do nothing only return notok*/
    }
#endif
    else
    {
        (void)RetryInfoPtr;
        /* 1.current version com dont support LinTp  message
           2.normally LinTp dont tx tp packet by itsself, if support lintp, com need to start tp tx request bu call LinTp_Transmit
           so here we dont consider NONE type pdu.
        */
        if(COM_TXPDU_START_BUSY == Com_TxPduState[PduId])
        {

            maxLength = COM_CFG_TXPDU_LENGTH(PduId);

#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
            if(TRUE == COM_CFG_TXPDU_IS_DYN(PduId))
            {
                maxLength = COM_TXPDU_DYN_LENGTH(PduId);

            }
#endif

            if((COM_TXPDU_TP_INDEX(PduId) + PduInfoPtr->SduLength) > maxLength)
            {
                COM_DET_REPORT_ERROR(COMSERVICEID_COPY_TX_DATA, COM_E_PARAM);
            }
            else
            {
                /* no Exclusive  Area, as the tp buffer is locked by busy state */
                Bsw_MemCpy(PduInfoPtr->SduDataPtr, &(((uint8 *)COM_CFG_TXPDU_DATA_PTR(PduId))[COM_TXPDU_TP_INDEX(PduId)]), (uint32)PduInfoPtr->SduLength);
                COM_TXPDU_TP_INDEX(PduId) += (PduInfoPtr->SduLength);
                *TxDataCntPtr =  maxLength - COM_TXPDU_TP_INDEX(PduId);
                result = BUFREQ_OK;
            }
        }
    }
#else
    else
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_COPY_TX_DATA, COM_E_PARAM);
    }
#endif /*#if(STD_ON == COM_TX_LONG_PDU_FUN)*/

    return result;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_StartOfReception SWS_Com_00691
*
* Description:   Callbak function Com provided by Com to J1939Tp
*
* Inputs:        RxPduId:      Receive PduId
*                TpSduLength:     Length in Single Frame or Fist Frame
*                RxBufferSizePtr: Avaliable buffer size Com can provided
*
* Outputs:       BUFREQ_E_NOT_OK, BUFREQ_E_BUSY and BUFREQ_E_OVFL
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, COM_CODE) Com_StartOfReception
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPointer,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) RxBufferSizePtr
)
{

    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 ComPhyCoreId = COM_GETCOREID();
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_START_OF_RECEPTION, COM_E_UNINIT);
    }
#if(STD_ON == COM_RX_LONG_PDU_FUN)
    else if((RxPduId >= COM_RXPDU_NUM)
            || (FALSE == COM_CFG_RXPDU_IS_TP_PDU(RxPduId)))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_START_OF_RECEPTION, COM_E_PARAM);
    }
    else if(COM_RXPDU_STOP == Com_RxPduState[RxPduId])
    {
        /*SWS_Com_00721  SWS_Com_00684 713 do nothing, only return BUFREQ_E_NOT_OK*/
    }
    else if(NULL_PTR == RxBufferSizePtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_START_OF_RECEPTION, COM_E_PARAM_POINTER);
    }
    else if(COM_RXPDU_START_BUSY == Com_RxPduState[RxPduId])
    {
        result = BUFREQ_E_BUSY;
    }
    /*length check */ /*SWS_Com_00574*/
    else if(TpSduLength > COM_CFG_RXPDU_LENGTH(RxPduId))
    {
        result = BUFREQ_E_OVFL;/* SWS_Com_00654 655*/
        COM_DET_REPORT_ERROR(COMSERVICEID_START_OF_RECEPTION, COM_E_PARAM);
    }
    else if(FALSE == Com_CheckRxLength(RxPduId, TpSduLength))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_START_OF_RECEPTION, COM_E_PARAM);
    }
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    else if(COM_CFG_RXPDU_CORE_ID(RxPduId) != ComCfgCorePhyMapLogic[ComPhyCoreId])
    {
        /* do nothing only return notok*/
    }
#endif
    else
    {
        (void)PduInfoPointer;/* dont support metaData in this version, ignor this parameter*/

        Com_RxPduState[RxPduId] = COM_RXPDU_START_BUSY;
        COM_RXPDU_TP_INDEX(RxPduId) = (PduLengthType)0;

        /* save length to tempLength reg, both for dyn or fix pdu
             as the rx length may be smaller than cfg length*/
        COM_RXPDU_TEMP_LENGTH(RxPduId) = TpSduLength;

        if(TpSduLength == 0)
        {
            *RxBufferSizePtr = COM_CFG_RXPDU_LENGTH(RxPduId);
        }
        else
        {
            *RxBufferSizePtr = TpSduLength;/* if dyn pdu , only tell the dyn length*/
        }
        result = BUFREQ_OK;
    }
#else
    else
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_START_OF_RECEPTION, COM_E_PARAM);
    }
#endif/*#if(STD_ON == COM_RX_LONG_PDU_FUN)*/

    return result;

}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_CopyRxData SWS_Com_00692
*
* Description:   Callbak function Comm provided by Comm to J1939Tp
*
* Inputs:        PduId:     Receive PduId
*                PduInfoPointer:  Pointer to a PduInfoType which indicates
*                                 the number of bytes to be copied (SduLength)
*                                 and the location of the source data
*                                 (SduDataPtr).
*                RxBufferSizePtr: Remaining free place in receive buffer after
*                                 completion of this call.
*
* Outputs:       BUFREQ_OK, BUFREQ_E_BUSY
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, COM_CODE) Com_CopyRxData
(
    PduIdType PduId,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPointer,
    P2VAR(PduLengthType, AUTOMATIC, COM_APPL_DATA) RxBufferSizePtr
)
{

    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#if(STD_ON == COM_RX_LONG_PDU_FUN)
    PduLengthType maxLength = (PduLengthType)0;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 ComPhyCoreId = COM_GETCOREID();
#endif
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_COPY_RX_DATA, COM_E_UNINIT);
    }
#if(STD_ON == COM_RX_LONG_PDU_FUN)
    else if((PduId >= COM_RXPDU_NUM)
            || (FALSE == COM_CFG_RXPDU_IS_TP_PDU(PduId)))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_COPY_RX_DATA, COM_E_PARAM);
    }
    else if(COM_RXPDU_START_BUSY != Com_RxPduState[PduId])
    {
        /*SWS_Com_00782  SWS_Com_00684 713 do nothing, only return BUFREQ_E_NOT_OK*/
        /* Only copy data when buffer is lock by startofrx */
    }
    else if(NULL_PTR == RxBufferSizePtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_COPY_RX_DATA, COM_E_PARAM_POINTER);

    }
    else if(NULL_PTR == PduInfoPointer)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_COPY_RX_DATA, COM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == PduInfoPointer->SduDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_COPY_RX_DATA, COM_E_PARAM_POINTER);
    }
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    else if(COM_CFG_RXPDU_CORE_ID(PduId) != ComCfgCorePhyMapLogic[ComPhyCoreId])
    {
        /* do nothing only return notok*/
    }
#endif
    else
    {

        maxLength = COM_RXPDU_TEMP_LENGTH(PduId);

        if((COM_RXPDU_TP_INDEX(PduId) + PduInfoPointer->SduLength) > maxLength)
        {
            /* dont reset rxState here, as com will expected a rxTpIndication with result = notok*/
            result = BUFREQ_E_OVFL;
        }
        else
        {
            Bsw_MemCpy(&(((uint8 *)COM_CFG_RXPDU_DATA_PTR(PduId))[COM_RXPDU_TP_INDEX(PduId)]), PduInfoPointer->SduDataPtr, (uint32)PduInfoPointer->SduLength);

            COM_RXPDU_TP_INDEX(PduId) += (PduInfoPointer->SduLength);

            *RxBufferSizePtr = maxLength - COM_RXPDU_TP_INDEX(PduId);
            result = BUFREQ_OK;

        }

    }
#else
    else
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_COPY_RX_DATA, COM_E_PARAM);
    }
#endif/*#if(STD_ON == COM_RX_LONG_PDU_FUN)*/


    return result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_TpRxIndication SWS_Com_00650
*
* Description:   Callbak function Com provided by Com to J1939Tp
*
* Inputs:        PduId:  Receive PduId
*                Result: NTFRSLT_OK means the complete N-PDU has been eceived
*                        and is stored in the receive buffer.Any other value
*                        means the N_PDU has not been received,
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_TpRxIndication
(
    PduIdType PduId,
    Std_ReturnType Result
)
{
#if(STD_ON == COM_RX_LONG_PDU_FUN)
#if(COM_RXIPDU_CALLOUT == STD_ON)
    boolean Com_RxCalResult = TRUE;
    PduInfoType PduInfo;
#endif
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 ComPhyCoreId = COM_GETCOREID();
#endif
#if(STD_ON == COM_RX_IMMEDIATE_SUPPORT)
    uint8 PduTempBuffer[COM_RX_PDU_MAX_ARRAY_SZIE] = {(uint8)0};
#endif
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TP_RX_INDICATION, COM_E_UNINIT);
    }
#if(STD_ON == COM_RX_LONG_PDU_FUN)
    else if((PduId >= COM_RXPDU_NUM)
            || (FALSE == COM_CFG_RXPDU_IS_TP_PDU(PduId)))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TP_RX_INDICATION, COM_E_PARAM);
    }
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    else if(COM_CFG_RXPDU_CORE_ID(PduId) != ComCfgCorePhyMapLogic[ComPhyCoreId])
    {
        /* do nothing */
    }
#endif
    else
    {
        if(COM_RXPDU_START_BUSY == Com_RxPduState[PduId])/*SWS_Com_00684 713*/
        {
#if((STD_ON == COM_RX_TIMEOUT_MONITOR) && (STD_ON == COM_RX_IMMEDIATE_SUPPORT))
            if((TRUE == COM_RXPDU_MONITOR_FLAG(PduId)) && (TRUE == COM_CFG_RXPDU_IS_IMM_PROCESSING(PduId)))
            {
                COM_RXPDU_TIMEOUT(PduId) = COM_CFG_RXPDU_PERIOD_TIMEOUT(PduId);/*SWS_Com_00715*/
            }
#endif
            /* not reset tempDynLength, as it will not affect anything*/
            if(E_OK == Result)
            {
                /* Ipdu received */
#if(COM_RXIPDU_CALLOUT == STD_ON)
                if(NULL_PTR != COM_CFG_RXPDU_CALLOUT(PduId))
                {
                    PduInfo.SduLength = COM_RXPDU_TEMP_LENGTH(PduId);
                    PduInfo.SduDataPtr = (SduDataPtrType)COM_CFG_RXPDU_DATA_PTR(PduId);
                    Com_RxCalResult = COM_CFG_RXPDU_CALLOUT(PduId)(PduId, &PduInfo);
                }

                if(FALSE == Com_RxCalResult)
                {
                    Com_RxPduState[PduId] = COM_RXPDU_START_RXSTOP;
#if ((STD_ON == COM_RX_INVALID_SUPPORT) && (STD_ON == COM_RX_IMMEDIATE_SUPPORT))
                    if(TRUE == COM_CFG_RXPDU_IS_IMM_PROCESSING(PduId))
                    {
                        /*call invalid ack, or replace invalid value to signa l SWS_Com_00839*/
                        Com_RxPduInvalid(PduId);
                        Com_RxPduState[PduId] = COM_RXPDU_START_IDLE;
#if(STD_ON == COM_RX_INDICATION_CALLOUT_SUPPORT)
                        Com_E2E_RxIndicationCallout(RxPduId);
#endif
                    }
#endif
                }
                else
#endif
                {
                    SchM_Enter_Com_COM_EXCLUSIVE_AREA_11();
                    Com_RxPduState[PduId] = COM_RXPDU_START_RXOK;
#if(STD_ON == COM_RX_IMMEDIATE_SUPPORT)
                    Bsw_MemCpy(PduTempBuffer, COM_CFG_RXPDU_DATA_PTR(RxPduId), (uint32)COM_CFG_RXPDU_LENGTH(RxPduId));
#endif
                    SchM_Exit_Com_COM_EXCLUSIVE_AREA_11();
                    /* data and length has been saved in temp buffer*/
#if(STD_ON == COM_RX_IMMEDIATE_SUPPORT)
                    if(TRUE == COM_CFG_RXPDU_IS_IMM_PROCESSING(PduId))
                    {
                        Com_HandleRxPdu(PduId, PduTempBuffer);/*SWS_Com_00300*/
                        Com_RxPduState[PduId] = COM_RXPDU_START_IDLE;
#if(STD_ON == COM_RX_INDICATION_CALLOUT_SUPPORT)
                        Com_E2E_RxIndicationCallout(RxPduId);
#endif
                    }
#endif
                }
            }
            else
            {
                /* can not reset dynRxLength, as old data may be read again*/
                Com_RxPduState[PduId] = COM_RXPDU_START_RXNOTOK;
#if ((STD_ON == COM_RX_INVALID_SUPPORT) && (STD_ON == COM_RX_IMMEDIATE_SUPPORT))
                if(TRUE == COM_CFG_RXPDU_IS_IMM_PROCESSING(PduId))
                {
                    Com_RxPduInvalid(PduId);/*SWS_Com_00838*/
                    Com_RxPduState[PduId] = COM_RXPDU_START_IDLE;
#if(STD_ON == COM_RX_INDICATION_CALLOUT_SUPPORT)
                    Com_E2E_RxIndicationCallout(RxPduId);
#endif
                }
#endif
            }


        }
    }
#else
    else
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TP_RX_INDICATION, COM_E_PARAM);
    }
#endif/*#if(STD_ON == COM_RX_LONG_PDU_FUN)*/

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ClearIpduGroupVector SWS_Com_00749
*
* Description:
*
* Inputs:        ipduGroupVector: ignal handle
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == COM_IPDU_GROUP_FUN)
FUNC(void, COM_CODE) Com_ClearIpduGroupVector
(
    Com_IpduGroupVector ipduGroupVector
)
{

    uint16 Index = (uint16)0;
    uint16 PduGroupVectorSize = COM_PDU_GROUP_NUM - (uint16)1;

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_CLEAR_IPDU_GROUP_VECTOR, COM_E_UNINIT);
    }
    else if(NULL_PTR == ipduGroupVector)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_CLEAR_IPDU_GROUP_VECTOR, COM_E_PARAM_POINTER);
    }
    else
    {
        PduGroupVectorSize = PduGroupVectorSize >> COM_GET_BYTEINX_SHIFT_VALUE;
        PduGroupVectorSize = PduGroupVectorSize + (uint16)1;

        SchM_Enter_Com_COM_EXCLUSIVE_AREA_7();
        for(Index = (uint16)0; Index < PduGroupVectorSize; Index++)
        {
            ipduGroupVector[Index] = (uint8)0;
        }
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_7();
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SetIpduGroup SWS_Com_00750
*
* Description:
*
* Inputs:        ipduGroupVector
*                IpduGroupId
*                bitval
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_SetIpduGroup
(
    Com_IpduGroupVector ipduGroupVector,
    Com_IpduGroupIdType  ipduGroupId,
    boolean bitval
)
{

    uint8 Position_Bit = (uint8)0;
    uint16 Position_Byte = (uint16)0;
    uint8 tempByte = (uint8)0;

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SET_IPDU_GROUP, COM_E_UNINIT);
    }
    else if(NULL_PTR == ipduGroupVector)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SET_IPDU_GROUP, COM_E_PARAM_POINTER);
    }
    else if(ipduGroupId >= COM_PDU_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SET_IPDU_GROUP, COM_E_PARAM);
    }
    else
    {
        /*SWS_Com_00623*/
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_7();
        Position_Byte = (ipduGroupId >> COM_GET_BYTEINX_SHIFT_VALUE);
        Position_Bit = (uint8)(ipduGroupId % COM_GET_BITPOS_RES_VALUE);

        tempByte = (uint8)(((uint32)1) << Position_Bit);

        if(FALSE == bitval)
        {
            tempByte = (uint8)(~(uint32)tempByte);
            ipduGroupVector[Position_Byte] &= tempByte;
        }
        else
        {
            ipduGroupVector[Position_Byte] |= tempByte;
        }

        SchM_Exit_Com_COM_EXCLUSIVE_AREA_7();
    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_IpduGroupControl SWS_Com_00751 792
*
* Description:
*
* Inputs:        ipduGroupVector
*                Initialize
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_IpduGroupControl
(
    Com_IpduGroupVector ipduGroupVector,
    boolean Initialize
)
{

    Com_IpduGroupIdType GroupIDIndex = (Com_IpduGroupIdType)0;
    uint8 Position_Bit = (uint8)0;
    uint16 Position_Byte = (uint16)0;
    uint8 tempByte = (uint8)0;

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_IPDU_GROUP_CONTROL, COM_E_UNINIT);
    }
    else if(NULL_PTR == ipduGroupVector)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_IPDU_GROUP_CONTROL, COM_E_PARAM_POINTER);
    }
    else
    {
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_8();
        /*
         * first process stop -> start group 
         * 2nd  process start -> stop group 
         * this order make sure that if txpdu keep start in this call cycle,  nothing will affect this txpdu 
         */
        /* if group state not change,  do nothing */

        for(GroupIDIndex = (Com_IpduGroupIdType)0; GroupIDIndex < COM_PDU_GROUP_NUM; GroupIDIndex++)
        {
            Position_Byte = (GroupIDIndex >> COM_GET_BYTEINX_SHIFT_VALUE);
            Position_Bit = (uint8)(GroupIDIndex % COM_GET_BITPOS_RES_VALUE);
            tempByte = (uint8)(((uint32)1) << Position_Bit);
            /* if group state switch from 0 to 1,  call Com_IpduGroupStart */
            if(((uint8)0 != (uint8)(ipduGroupVector[Position_Byte] & tempByte)) && (FALSE == Com_IpduGroupStartFlag[GroupIDIndex]))
            {
                Com_IpduGroupStart_Internal(GroupIDIndex, Initialize);
            }
        }

        for(GroupIDIndex = (Com_IpduGroupIdType)0; GroupIDIndex < COM_PDU_GROUP_NUM; GroupIDIndex++)
        {
            Position_Byte = (GroupIDIndex >> COM_GET_BYTEINX_SHIFT_VALUE);
            Position_Bit = (uint8)(GroupIDIndex % COM_GET_BITPOS_RES_VALUE);
            tempByte = (uint8)(((uint32)1) << Position_Bit);
            /* if group state switch from 1 to 0,  call Com_IpduGroupStop */
            if(((uint8)0 == (uint8)(ipduGroupVector[Position_Byte] & tempByte)) && (TRUE == Com_IpduGroupStartFlag[GroupIDIndex]))
            {
                Com_IpduGroupStop_Internal(GroupIDIndex);
            }
           
        }

        SchM_Exit_Com_COM_EXCLUSIVE_AREA_8();
    }

}
#endif/*#if (STD_ON == COM_IPDU_GROUP_FUN)*/





#if (STD_ON == COM_IPDU_GROUP_FUN)
#if (STD_ON == COM_GROUP_API_R3_SUPPORT)

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_IpduGroupStart SWS_Com_00751 792
*
* Description:   start target group and keep other group unchange
*
* Inputs:        IpduGroupId
*                Initialize
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_IpduGroupStart
(
    Com_IpduGroupIdType IpduGroupId,
    boolean Initialize
)
{
    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERCIVEID_START_GROUP, COM_E_UNINIT);
    }
    else if(IpduGroupId >= COM_PDU_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERCIVEID_START_GROUP, COM_E_PARAM);
    }
    else
    {
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_8();

        Com_IpduGroupStart_Internal(IpduGroupId, Initialize);
        
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_8();

    }

}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_IpduGroupStop SWS_Com_00751 792
*
* Description:   stop target group and keep other group unchange
*
* Inputs:        IpduGroupId
*
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_IpduGroupStop
(
    Com_IpduGroupIdType IpduGroupId
)
{
    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERCIVEID_STOP_GROUP, COM_E_UNINIT);
    }
    else if(IpduGroupId >= COM_PDU_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERCIVEID_STOP_GROUP, COM_E_PARAM);
    }
    else
    {
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_8();

        Com_IpduGroupStop_Internal(IpduGroupId);

        SchM_Exit_Com_COM_EXCLUSIVE_AREA_8();

    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_GetIpduGroupState 
*
* Description:   return start or stop state of IpduGroup
*
* Inputs:        IpduGroupId
*
*
* Outputs:       boolean
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(boolean, COM_CODE) Com_GetIpduGroupState
(
    Com_IpduGroupIdType IpduGroupId
)
{
    boolean flag = FALSE;


    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERCIVEID_GET_IPDU_GROUP_STATE, COM_E_UNINIT);
    }
    else if(IpduGroupId >= COM_PDU_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERCIVEID_GET_IPDU_GROUP_STATE, COM_E_PARAM);
    }
    else
    {
        flag = Com_IpduGroupStartFlag[IpduGroupId];
    }

    return flag;
}

#if(STD_ON == COM_RX_TIMEOUT_MONITOR)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_IsPduDMEnable_Internal
*
* Description:   This interface is used to check if the PduDM can be enabled
*
* Inputs:        pduId
*
* Outputs:       boolean
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_IsPduDMEnable_Internal
(
    PduIdType RxIpduId
)
{
    boolean flag = FALSE;
    Com_IpduGroupIdType grpIdx = (Com_IpduGroupIdType)0;
    Com_IpduGroupIdType tmpNum = (PduIdType)0;
    P2CONST(Com_IpduGroupIdType, AUTOMATIC, COM_CONST) tmpPtr = NULL_PTR;
    tmpNum = COM_CFG_RXPDU_IN_PDUGRP_NUM(RxIpduId);
    tmpPtr = COM_CFG_RXPDU_IN_PDUGRP_PTR(RxIpduId);
    /* search all pdugroup which contains this pdu, if any one is enable, retuan TRUE(Enable)*/
    for(grpIdx =  (Com_IpduGroupIdType)0; grpIdx < tmpNum; grpIdx++)
    {
        if(TRUE == Com_IpduGroupDMEnableFlag[tmpPtr[grpIdx]])
        {
            flag = TRUE;
            break;
        }
    }
    return flag;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_EnableReceptionDM
*
* Description:   Used to start rx time out monitor of group's rxPdu
*
* Inputs:        IpduGroupId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_EnableReceptionDM
(
    Com_IpduGroupIdType IpduGroupId
)
{

    PduIdType RxIpduIdIndex = (PduIdType)0;
    PduIdType RxIpduId = (PduIdType)0;
    P2CONST(PduIdType, AUTOMATIC, COM_CONST) tmpRxPduGrpPtr = NULL_PTR;

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERCIVEID_START_RX_DMGROUP, COM_E_UNINIT);
    }
    else if(IpduGroupId >= COM_PDU_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERCIVEID_START_RX_DMGROUP, COM_E_PARAM);
    }
    else
    {


        SchM_Enter_Com_COM_EXCLUSIVE_AREA_8();
        if((PduIdType)0 != COM_CFG_RX_PDUGROUP_NUM(IpduGroupId))
        {
            Com_IpduGroupDMEnableFlag[IpduGroupId] = TRUE;
            tmpRxPduGrpPtr = COM_CFG_RX_PDUGROUP_PTR(IpduGroupId);
            /*SWS_Com_00534 ignor txPdu of this group*/
            for(RxIpduIdIndex = (PduIdType)0;
                    RxIpduIdIndex < COM_CFG_RX_PDUGROUP_NUM(IpduGroupId);
                    RxIpduIdIndex++)
            {
                RxIpduId = tmpRxPduGrpPtr[RxIpduIdIndex];

                if(TRUE == COM_CFG_RXPDU_MONITOR_FLAG(RxIpduId))
                {
                    /* when pdu stop, time out monitor must be disable*/
                    if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
                    {
                        /*SWS_Com_00224 486 225 616 617 618 process only when state change*/
                        if(COM_RXPDU_MONITOR_FLAG(RxIpduId) != TRUE)
                        {
                            COM_RXPDU_MONITOR_FLAG(RxIpduId) = TRUE;
                            COM_RXPDU_TIMEOUT(RxIpduId) = COM_TIMER_STOP_VAL;
#if(STD_ON == COM_RX_SIGNAL_UB_TIMEOUT_SUPPORT)
                            Com_ResetUpdateRxToTimer(RxIpduId);
#endif
                        }
                    }
                }
            }
        }
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_8();
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_DisableReceptionDM
*
* Description:   Used to stOP rx time out monitor of group's rxPdu
*
* Inputs:        IpduGroupId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_DisableReceptionDM
(
    Com_IpduGroupIdType IpduGroupId
)
{

    PduIdType RxIpduIdIndex = (PduIdType)0;
    PduIdType RxIpduId = (PduIdType)0;
    boolean tmpPduDMEnableFlag = TRUE;
    P2CONST(PduIdType, AUTOMATIC, COM_CONST) tmpRxPduGrpPtr = NULL_PTR;

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERCIVEID_STOP_RX_DMGROUP, COM_E_UNINIT);
    }
    else if(IpduGroupId >= COM_PDU_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERCIVEID_STOP_RX_DMGROUP, COM_E_PARAM);
    }
    else
    {


        SchM_Enter_Com_COM_EXCLUSIVE_AREA_8();
        if((PduIdType)0 != COM_CFG_RX_PDUGROUP_NUM(IpduGroupId))
        {
            Com_IpduGroupDMEnableFlag[IpduGroupId] = FALSE;
            tmpRxPduGrpPtr = COM_CFG_RX_PDUGROUP_PTR(IpduGroupId);
            /*SWS_Com_00534 ignor txPdu of this group*/
            for(RxIpduIdIndex = (PduIdType)0;
                    RxIpduIdIndex < COM_CFG_RX_PDUGROUP_NUM(IpduGroupId);
                    RxIpduIdIndex++)
            {
                RxIpduId = tmpRxPduGrpPtr[RxIpduIdIndex];

                if(TRUE == COM_CFG_RXPDU_MONITOR_FLAG(RxIpduId))
                {
                    /* when pdu stop, time out monitor must be disable*/
                    if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
                    {
                        tmpPduDMEnableFlag = Com_IsPduDMEnable_Internal(RxIpduId);
                        /*SWS_Com_00224 486 225 616 617 618 process only when state change*/
                        if((COM_RXPDU_MONITOR_FLAG(RxIpduId) != FALSE) && (tmpPduDMEnableFlag == FALSE))
                        {
                            COM_RXPDU_MONITOR_FLAG(RxIpduId) = FALSE;
                            COM_RXPDU_TIMEOUT(RxIpduId) = COM_TIMER_STOP_VAL;
#if(STD_ON == COM_RX_SIGNAL_UB_TIMEOUT_SUPPORT)
                            Com_ResetUpdateRxToTimer(RxIpduId);
#endif
                        }
                    }
                }
            }
        }
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_8();
    }
}


#endif
#endif
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_GetVersionInfo  SWS_Com_00426
*
* Description:   This service returns the version information of the called
*                CAN Interface module
*
* Inputs:        VersionInfo  Pointer to where to store the version information
*                             of this module.DLC and pointer to CAN L-SDU buffer
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON == COM_PUBLIC_VERSION_INFO_API)
FUNC(void, COM_CODE) Com_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, COM_APPL_DATA) VersionInfo
)
{

    if(NULL_PTR == VersionInfo)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_GET_VERSION_INFO, COM_E_PARAM_POINTER);
    }
    else
    {
        VersionInfo->vendorID = COM_VENDOR_ID;
        VersionInfo->moduleID = COM_MODULE_ID;

        VersionInfo->sw_major_version = (uint8)COM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)COM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)COM_SW_PATCH_VERSION;
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SendSignalGroup_Internal
*
* Description:   This service updates the signal object identified by
*                SignalId with the signal referenced by the SignalDataPtr
*                parameter
*
* Inputs:        SignalId: Signal handle
*                SignalDataPtr: Reference to the Signal data to be transmitted
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
                                            large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, COM_CODE) Com_SendSignalGroup_Internal
(
    Com_SignalGroupIdType SignalGroupId
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;/* return not available when det err*/

#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    PduIdType TxIpduId = COM_CFG_TXSIGGRP_PDUID(SignalGroupId);
    Com_SignalIdType GrpSigIndex;
    P2VAR(void, AUTOMATIC, COM_VAR) destDataPtr = NULL_PTR;
    PduLengthType length = (PduLengthType)0;
    Com_EndiannessType Endianness;
    Com_SigType SigType;
    uint16 BitSize;
    uint16 StartBit;
    uint8 MaskLsb;
    uint8 MaskMsb;
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
    boolean ChangeFlag = FALSE;
#endif
#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
    boolean IfActiveChangeFlag = FALSE;
#endif
#if(STD_ON == COM_TX_FILTER_SUPPORT)
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr = NULL_PTR;
#endif
#endif

#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
#if(STD_ON == COM_TX_LONG_PDU_FUN)
    if((COM_TXPDU_START_BUSY == Com_TxPduState[TxIpduId]) && (TRUE == COM_CFG_TXPDU_IS_TP_PDU(TxIpduId)))
    {
        result = COM_BUSY;
    }
    else
#endif
    {
        for(GrpSigIndex = COM_CFG_TXSIGGRP_SIGSTART(SignalGroupId); GrpSigIndex <= COM_CFG_TXSIGGRP_SIGSTOP(SignalGroupId); GrpSigIndex++)
        {
            /* destDataPtr = COM_CFG_TXSIG_GROUP_TEMP_BUF(GrpSigIndex); */
            destDataPtr = COM_CFG_TXSIG_SHARE_BUF_PTR(GrpSigIndex);
            length = COM_CFG_TXSIG_LENGTH(GrpSigIndex);
#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
            if(COM_CFG_TXSIG_TYPE(GrpSigIndex) == COM_SIG_DYN)
            {
                length = *COM_CFG_TXSIG_GROUP_TEMPLENGTH_PTR(GrpSigIndex);
                COM_TXPDU_DYN_LENGTH(TxIpduId) = length + COM_CFG_TXSIG_START_BYTE_INDEX(GrpSigIndex);
            }
#endif

#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
            if((COM_CFG_TXSIG_TRANSPROPERTY(GrpSigIndex) >= COM_TRIGGERED_ON_CHANGE) && (COM_CFG_TXSIG_TRANSPROPERTY(GrpSigIndex) < COM_IFACTIVE_SIG))
            {
                if(FALSE == Com_TxSigIsSameValue[GrpSigIndex])
                {
                    ChangeFlag = TRUE;
                }
            }
#endif

#if 0/* Not use in this version 2024/10/12*/
#if(STD_ON == COM_TXSIG_ON_CHANGE_SUPPORT)
            if((COM_CFG_TXSIG_TRANSPROPERTY(GrpSigIndex) >= COM_TRIGGERED_ON_CHANGE) && (COM_CFG_TXSIG_TRANSPROPERTY(GrpSigIndex) < COM_IFACTIVE_SIG))
            {
                if(FALSE == changeflag)
                {
                    changeflag = Com_CheckChangeSignalInPdu(destDataPtr, COM_CFG_TXPDU_DATA_PTR(TxIpduId), Endianness, SigType, BitSize, StartBit, Mask, length);
                }
            }
#endif

#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
            if(COM_CFG_TXSIG_TRANSPROPERTY(GrpSigIndex) == COM_IFACTIVE_ON_CHANGE_SIG)
            {
                if(FALSE == IfActiveChangeFlag)
                {
                    IfActiveChangeFlag = Com_CheckChangeSignalInPdu(destDataPtr, COM_CFG_TXPDU_DATA_PTR(TxIpduId), Endianness, SigType, BitSize, StartBit, Mask, length);
                }
            }
#endif
#endif

            SigType = COM_CFG_TXSIG_TYPE(GrpSigIndex);
#if(STD_ON == COM_TX_FILTER_SUPPORT)
            AlgPtr = COM_CFG_TXSIG_FILTER_PTR(GrpSigIndex);
            if(NULL_PTR != AlgPtr)
            {
                Com_TxSignalFilterProcess(GrpSigIndex, SigType, destDataPtr, AlgPtr);
            }
#endif
            if(FALSE == Com_TxSigIsSameValue[GrpSigIndex])
            {
#if(STD_ON == COM_TX_FILTER_SUPPORT)
                if(NULL_PTR != AlgPtr)
                {
                    if(NULL_PTR != AlgPtr->Par3)
                    {
                        Com_CopySignalWithOutLock(destDataPtr, AlgPtr->Par3, SigType, length);
                    }
                }
#endif
                Endianness = COM_CFG_TXSIG_ENDIANNESS(GrpSigIndex);
                BitSize = COM_CFG_TXSIG_BIT_SIZE(GrpSigIndex);
                StartBit = COM_CFG_TXSIG_START_BIT(GrpSigIndex);
                MaskLsb = COM_CFG_TXSIG_MASK_LSB(GrpSigIndex);
                MaskMsb = COM_CFG_TXSIG_MASK_MSB(GrpSigIndex);
                Com_WriteSignal(destDataPtr, COM_CFG_TXPDU_DATA_PTR(TxIpduId), Endianness, SigType, BitSize, StartBit, MaskLsb, MaskMsb, length);
            }
            else
            {
                Com_TxSigIsSameValue[GrpSigIndex] = FALSE;    
            }
            
#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
            Com_CheckTxSigIfActive(TxIpduId, GrpSigIndex,destDataPtr, COM_CFG_TXSIG_INACTIVE_VALUE_PTR(GrpSigIndex));
            if(COM_CFG_TXSIG_TRANSPROPERTY(GrpSigIndex) == COM_IFACTIVE_ON_CHANGE_SIG)
            {
                if(FALSE == Com_TxSigIsSameValue[GrpSigIndex])
                {
                    if((uint32)0 != COM_TXPDU_IFACTIVE_FLAG(TxIpduId))
                    {
                        COM_TXPDU_IFACTIVE_CHANGE_FLAG(TxIpduId) = TRUE;
                    }
                }
            }
#endif
        }

#if(COM_TX_UPDATEBIT_SUPPORT == STD_ON)
        /* set update bit if configured*/
        if(COM_INVALID_SIG_INDEX != COM_CFG_TXSIGGRP_UPDATEBIT_INDEX(SignalGroupId))
        {
            Com_SetSigUpdateBit(TxIpduId, COM_CFG_TXSIGGRP_UPDATEBIT_INDEX(SignalGroupId));
        }
#endif

        /* this Asr req, when pdu is stop, data canbe updated, but return COM_SERVICE_NOT_AVAILABLE*/
        /*SWS_Com_334 dont save trigger when stop*/
        if(COM_TXPDU_STOP != Com_TxPduState[TxIpduId])
        {
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
            Com_SetIpduTrigRepFlag(COM_CFG_TXSIGGRP_TRPROP(SignalGroupId), TxIpduId, ChangeFlag);
#endif
            result = E_OK;
        }
    }
#endif/*#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)*/

    return result;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SendSignalGroup SWS_Com_00197
*
* Description:   This service updates the signal object identified by
*                SignalId with the signal referenced by the SignalDataPtr
*                parameter
*
* Inputs:        SignalId: Signal handle
*                SignalDataPtr: Reference to the Signal data to be transmitted
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
                                            large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_SendSignalGroup
(
    Com_SignalGroupIdType SignalGroupId
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;/* return not available when det err*/

#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    PduIdType TxIpduId;
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
    Com_SignalIdType TxGroupStartSig;
#endif
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_GROUP, COM_E_UNINIT);
    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    else if(SignalGroupId >= COM_TXSIG_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_GROUP, COM_E_PARAM);
    }
    else if(COM_CFG_TXSIGGRP_SUPPORT_ARRAY(SignalGroupId) == TRUE)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_GROUP, COM_E_PARAM);
    }
    else
    {
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        TxIpduId = COM_CFG_TXSIGGRP_PDUID(SignalGroupId);
        TxSigCoreId = COM_CFG_TXPDU_CORE_ID(TxIpduId);
        ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
        if(TxSigCoreId != ComLogicCoreId)
        {
	        SchM_Enter_Com_COM_EXCLUSIVE_AREA_9();

	        TxGroupStartSig = COM_CFG_TXSIGGRP_SIGSTART(SignalGroupId);
	        tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(TxGroupStartSig);
	        if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
	        {
	            *tempTxSigShareFlagPtr = COM_SIG_GRP;
                result = E_OK;
	        }
	        SchM_Exit_Com_COM_EXCLUSIVE_AREA_9();
        }
        else
#endif
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
            result = Com_SendSignalGroup_Internal(SignalGroupId);
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();
        }
    }
#endif/*#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)*/

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_InvalidateSignalGroup_Internal
*
* Description:   This service updates all group signal to invalid value
* Inputs:        SignalGroupId: Signal group handle
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
                                            large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if((STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT) && (STD_ON == COM_TX_INVALID_SUPPORT))
STATIC FUNC(uint8, COM_CODE) Com_InvalidateSignalGroup_Internal
(
    Com_SignalGroupIdType SignalGroupId
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;/* return not available when det err*/
    PduIdType TxIpduId;
    Com_SignalIdType GrpSigIndex = (Com_SignalIdType)0;
    P2VAR(void, AUTOMATIC, COM_VAR) destDataPtr = NULL_PTR;
    P2CONST(void, AUTOMATIC, COM_CONST) srcDataPtr = NULL_PTR;
    PduLengthType length = (PduLengthType)0;
    Com_EndiannessType Endianness;
    Com_SigType SigType;
    uint16 BitSize;
    uint16 StartBit;
    uint8 MaskLsb;
    uint8 MaskMsb;
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
    boolean ChangeFlag = FALSE;
#endif
#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
    boolean IfActiveChangeFlag = FALSE;
#endif
#if(STD_ON == COM_TX_FILTER_SUPPORT)
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr = NULL_PTR;
#endif
    if(COM_TXPDU_START_BUSY == Com_TxPduState[TxIpduId])
    {
        result = COM_BUSY;
    }
    else
    {
        for(GrpSigIndex = COM_CFG_TXSIGGRP_SIGSTART(SignalGroupId); GrpSigIndex <= COM_CFG_TXSIGGRP_SIGSTOP(SignalGroupId); GrpSigIndex++)
        {
            if(NULL_PTR != COM_CFG_TXSIG_INVALID_VALUE_PTR(GrpSigIndex))
            {
                /* destDataPtr = COM_CFG_TXSIG_GROUP_TEMP_BUF(GrpSigIndex); */
                destDataPtr = COM_CFG_TXSIG_SHARE_BUF_PTR(GrpSigIndex);
                srcDataPtr = COM_CFG_TXSIG_INVALID_VALUE_PTR(GrpSigIndex);
                length = COM_CFG_TXSIG_LENGTH(GrpSigIndex);
                Endianness = COM_CFG_TXSIG_ENDIANNESS(GrpSigIndex);
                SigType = COM_CFG_TXSIG_TYPE(GrpSigIndex);
                BitSize = COM_CFG_TXSIG_BIT_SIZE(GrpSigIndex);
                StartBit = COM_CFG_TXSIG_START_BIT(GrpSigIndex);
                MaskLsb = COM_CFG_TXSIG_MASK_LSB(GrpSigIndex);
                MaskMsb = COM_CFG_TXSIG_MASK_MSB(GrpSigIndex);
#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
                if(COM_CFG_TXSIG_TYPE(GrpSigIndex) == COM_SIG_DYN)
                {
                    length = COM_CFG_TXSIG_INVALID_VALUE_LEN(GrpSigIndex);
                    COM_TXPDU_DYN_LENGTH(TxIpduId) = length + COM_CFG_TXSIG_START_BYTE_INDEX(GrpSigIndex);
                }
#endif

#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
                if((COM_CFG_TXSIG_TRANSPROPERTY(GrpSigIndex) >= COM_TRIGGERED_ON_CHANGE) && (COM_CFG_TXSIG_TRANSPROPERTY(GrpSigIndex) < COM_IFACTIVE_SIG))
                {
                    if(FALSE == Com_TxSigIsSameValue[GrpSigIndex])
                    {
                        ChangeFlag = TRUE;
                    }
                }
#endif
#if 0/* Not use in this version 2024/10/12*/
#if(STD_ON == COM_TXSIG_ON_CHANGE_SUPPORT)
                if((COM_CFG_TXSIG_TRANSPROPERTY(GrpSigIndex) >= COM_TRIGGERED_ON_CHANGE) && (COM_CFG_TXSIG_TRANSPROPERTY(GrpSigIndex) < COM_IFACTIVE_SIG))
                {
                    ChangeFlag = Com_CheckChangeSignalInPdu(destDataPtr, COM_CFG_TXPDU_DATA_PTR(TxIpduId), Endianness, SigType, BitSize, StartBit, Mask, length);
                }
#endif
#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
            if(COM_CFG_TXSIG_TRANSPROPERTY(GrpSigIndex) == COM_IFACTIVE_ON_CHANGE_SIG)
            {
                if(FALSE == IfActiveChangeFlag)
                {
                    IfActiveChangeFlag = Com_CheckChangeSignalInPdu(destDataPtr, COM_CFG_TXPDU_DATA_PTR(TxIpduId), Endianness, SigType, BitSize, StartBit, Mask, length);
                }
            }
#endif
#endif

                SigType = COM_CFG_TXSIG_TYPE(GrpSigIndex);
#if(STD_ON == COM_TX_FILTER_SUPPORT)
                AlgPtr = COM_CFG_TXSIG_FILTER_PTR(GrpSigIndex);
                if(NULL_PTR != AlgPtr)
                {
                    Com_TxSignalFilterProcess(GrpSigIndex, SigType, srcDataPtr, AlgPtr);
                    if(NULL_PTR != AlgPtr->Par3)
                    {
                        Com_CopySignalWithOutLock(srcDataPtr, AlgPtr->Par3, SigType, length);
                    }
                }
#endif
                Com_WriteSignal(srcDataPtr, COM_CFG_TXPDU_DATA_PTR(TxIpduId), Endianness, SigType, BitSize, StartBit, MaskLsb, MaskMsb, length);
                if(NULL_PTR != destDataPtr)
                {
                    Com_CopySignalWithOutLock(srcDataPtr, destDataPtr, SigType, length);
                }

#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
                Com_CheckTxSigIfActive(TxIpduId, GrpSigIndex,srcDataPtr, COM_CFG_TXSIG_INACTIVE_VALUE_PTR(GrpSigIndex));
                if(COM_CFG_TXSIG_TRANSPROPERTY(GrpSigIndex) == COM_IFACTIVE_ON_CHANGE_SIG) 
                {
                    if(FALSE == Com_TxSigIsSameValue[GrpSigIndex])
                    {
                        if((uint32)0 != COM_TXPDU_IFACTIVE_FLAG(TxIpduId))
                        {
                            COM_TXPDU_IFACTIVE_CHANGE_FLAG(TxIpduId) = TRUE;
                        }
                    }
                }
#endif

            }

        }

#if(COM_TX_UPDATEBIT_SUPPORT == STD_ON)
        /* set update bit if configured*/
        if(COM_INVALID_SIG_INDEX != COM_CFG_TXSIGGRP_UPDATEBIT_INDEX(SignalGroupId))
        {
            Com_SetSigUpdateBit(TxIpduId, COM_CFG_TXSIGGRP_UPDATEBIT_INDEX(SignalGroupId));
        }
#endif

        /* this Asr req, when pdu is stop, data canbe updated, but return COM_SERVICE_NOT_AVAILABLE*/
        /*SWS_Com_334 dont save trigger when stop*/
        if(COM_TXPDU_STOP != Com_TxPduState[TxIpduId])
        {
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
            Com_SetIpduTrigRepFlag(COM_CFG_TXSIGGRP_TRPROP(SignalGroupId), TxIpduId, ChangeFlag);
#endif
            result = E_OK;
        }
    }


    return  result;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_InvalidateSignalGroup SWS_Com_00557
*
* Description:   This service updates all group signal to invalid value
* Inputs:        SignalGroupId: Signal group handle
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
                                            large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_InvalidateSignalGroup
(
    Com_SignalGroupIdType SignalGroupId
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;/* return not available when det err*/
#if((STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT) && (STD_ON == COM_TX_INVALID_SUPPORT))
    PduIdType TxIpduId;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
    Com_SignalIdType TxGroupStartSig;
#endif
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_INVALIDATE_SIGNAL_GROUP, COM_E_UNINIT);
    }
#if((STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT) && (STD_ON == COM_TX_INVALID_SUPPORT))
    else if(SignalGroupId >= COM_TXSIG_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_INVALIDATE_SIGNAL_GROUP, COM_E_PARAM);
    }
    else if(FALSE == COM_CFG_TXSIGGRP_HAS_INVALID_VAL(SignalGroupId))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_INVALIDATE_SIGNAL_GROUP, COM_E_PARAM);
    }
    /* this api support array signal group*/
    else
    {
        TxIpduId = COM_CFG_TXSIGGRP_PDUID(SignalGroupId);
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        TxSigCoreId = COM_CFG_TXPDU_CORE_ID(TxIpduId);
        ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
        if(TxSigCoreId != ComLogicCoreId)
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_9();
            TxGroupStartSig = COM_CFG_TXSIGGRP_SIGSTART(SignalGroupId);
            tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(TxGroupStartSig);
            if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
            {
                *tempTxSigShareFlagPtr = COM_SIG_GRP_INV;
            }
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_9();
        }
        else
#endif
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
            result = Com_InvalidateSignalGroup_Internal(SignalGroupId);
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();
        }
    }
#endif/*#if((STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT) && (STD_ON == COM_TX_INVALID_SUPPORT))*/

    return  result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SendSignalGroupArray_Internal
*
* Description:   This service send signal group data in array type
*
* Inputs:        SignalGroupId: Signal group handle
*                SignalGroupArrayPtr: Reference to the Signal data to be read
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
                                            large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

#if((STD_ON == COM_Enable_SignalGroupArrayApi) && (STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT))
STATIC FUNC(uint8, COM_CODE) Com_SendSignalGroupArray_Internal
(
    Com_SignalGroupIdType SignalGroupId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)  SignalGroupArrayPtr
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;/* return not available when det err*/
    P2VAR(uint8, AUTOMATIC, COM_VAR) destDataPtr = NULL_PTR;
    PduIdType TxIpduId;

    TxIpduId = COM_CFG_TXSIGGRP_PDUID(SignalGroupId);
#if(STD_ON == COM_TX_LONG_PDU_FUN)
    if((COM_TXPDU_START_BUSY == Com_TxPduState[TxIpduId]) && (TRUE == COM_CFG_TXPDU_IS_TP_PDU(TxIpduId)))
    {
        result = COM_BUSY;
    }
    else
#endif
    {
        destDataPtr = &((uint8 *)COM_CFG_TXPDU_DATA_PTR(TxIpduId))[COM_CFG_TXSIGGRP_STARTBYTE(SignalGroupId)];

        Bsw_MemCpy(destDataPtr, SignalGroupArrayPtr, (uint32)COM_CFG_TXSIGGRP_SIZE(SignalGroupId));

        /* No filter and onchange check not support this version */

#if(COM_TX_UPDATEBIT_SUPPORT == STD_ON)
        /* set update bit if configured*/
        if(COM_INVALID_SIG_INDEX != COM_CFG_TXSIGGRP_UPDATEBIT_INDEX(SignalGroupId))
        {
            Com_SetSigUpdateBit(TxIpduId, COM_CFG_TXSIGGRP_UPDATEBIT_INDEX(SignalGroupId));
        }
#endif

        /* this Asr req, when pdu is stop, data canbe updated, but return COM_SERVICE_NOT_AVAILABLE*/
        /*SWS_Com_334 dont save trigger when stop*/
        if(COM_TXPDU_STOP != Com_TxPduState[TxIpduId])
        {
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
            Com_SetIpduTrigRepFlag(COM_CFG_TXSIGGRP_TRPROP(SignalGroupId), TxIpduId, FALSE);
#endif
            result = E_OK;
        }
    }

    return result;
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SendSignalGroupArray SWS_Com_00851
*
* Description:   This service send signal group data in array type
*
* Inputs:        SignalGroupId: Signal group handle
*                SignalGroupArrayPtr: Reference to the Signal data to be read
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
                                            large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

FUNC(uint8, COM_CODE) Com_SendSignalGroupArray
(
    Com_SignalGroupIdType SignalGroupId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA)  SignalGroupArrayPtr
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;/* return not available when det err*/
#if((STD_ON == COM_Enable_SignalGroupArrayApi) && (STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT))
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    PduIdType TxIpduId;
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
    Com_SignalIdType TxGroupStartSig;
#endif
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_GROUP_ARRAY, COM_E_UNINIT);
    }
#if((STD_ON == COM_Enable_SignalGroupArrayApi) && (STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT))
    else if(SignalGroupId >= COM_TXSIG_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_GROUP_ARRAY, COM_E_PARAM);
    }
    else if(SignalGroupArrayPtr == NULL_PTR)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_GROUP_ARRAY, COM_E_PARAM);
    }
    else if(COM_CFG_TXSIGGRP_SUPPORT_ARRAY(SignalGroupId) == FALSE)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_GROUP_ARRAY, COM_E_PARAM);
    }
    else
    {
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        TxIpduId = COM_CFG_TXSIGGRP_PDUID(SignalGroupId);
        TxSigCoreId = COM_CFG_TXPDU_CORE_ID(TxIpduId);
        ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
        if(TxSigCoreId != ComLogicCoreId)
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_9();
            TxGroupStartSig = COM_CFG_TXSIGGRP_SIGSTART(SignalGroupId);
            tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(TxGroupStartSig);
            if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
            {
                *tempTxSigShareFlagPtr = COM_SIG_GRP;
                result = E_OK;
            }
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_9();
        }
        else
#endif
        {
            Com_SendSignalGroupArray_Internal(SignalGroupId, SignalGroupArrayPtr);
        }
    }
#endif
    return result;
}





/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ReceiveSignalGroup SWS_Com_00201
*
* Description:   This service updates the signal object identified by
*                SignalId with the signal referenced by the SignalDataPtr
*                parameter
*
* Inputs:        SignalId: Signal handle
*                SignalDataPtr: Reference to the Signal data to be transmitted
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
*                                           large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_ReceiveSignalGroup
(
    Com_SignalGroupIdType SignalGroupId
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;/* return not available when det err*/
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    PduIdType RxIpduId;
    Com_SignalIdType GrpSigIndex = (Com_SignalIdType)0;
    P2VAR(void, AUTOMATIC, COM_VAR) destDataPtr = NULL_PTR;
    PduLengthType length = (PduLengthType)0;
    Com_SigType SigType;
    P2VAR(void, AUTOMATIC, COM_VAR) tempRxSigBuf = NULL_PTR;
#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)
    PduLengthType tempRxPduDynLen = (PduLengthType)0;
    P2VAR(PduLengthType, AUTOMATIC, COM_VAR) tempRxSigGrpDynLen = NULL_PTR;
#endif
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_GROUP, COM_E_UNINIT);
    }
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    else if(SignalGroupId >= COM_RXSIG_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_GROUP, COM_E_PARAM);
    }
    else if(COM_CFG_RXSIGGRP_SUPPORT_ARRAY(SignalGroupId) == TRUE)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_GROUP, COM_E_PARAM);
    }
    else
    {
        /* dont need report busy , as copy process is protected by Area2
           and always read old data
        */
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_12();

#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        COM_GETSPINLOCK(&(Com_SpinLock_RxSigGroup[SignalGroupId]));
#endif
        for(GrpSigIndex = COM_CFG_RXSIGGRP_SIGSTART(SignalGroupId); GrpSigIndex <= COM_CFG_RXSIGGRP_SIGSTOP(SignalGroupId); GrpSigIndex++)
        {
            destDataPtr = COM_CFG_RXSIG_GROUP_TEMP_BUF(GrpSigIndex);
            tempRxSigBuf = COM_CFG_RXSIG_DATA_PTR(GrpSigIndex);
            length = COM_CFG_RXSIG_LENGTH(GrpSigIndex);
            SigType = COM_CFG_RXSIG_TYPE(GrpSigIndex);
            RxIpduId = COM_CFG_RXSIG_RXPDU_ID(GrpSigIndex);
#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)
            tempRxSigGrpDynLen = COM_CFG_RXSIG_GROUP_TEMPLENGTH_PTR(GrpSigIndex);
            tempRxPduDynLen = COM_RXPDU_DYN_LENGTH(RxIpduId);
            if(COM_SIG_DYN == COM_CFG_RXSIG_TYPE(GrpSigIndex))
            {
                length = tempRxPduDynLen - COM_CFG_RXSIG_START_BYTE_INDEX(GrpSigIndex);
                *tempRxSigGrpDynLen = length;
            }
#endif
            Com_CopySignal(destDataPtr, tempRxSigBuf, SigType, length, GrpSigIndex);
        }
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        COM_RELEASESPINLOCK(&(Com_SpinLock_RxSigGroup[SignalGroupId]));
#endif

        SchM_Exit_Com_COM_EXCLUSIVE_AREA_12();

        /*
           when stop , read old data but return COM_SERVICE_NOT_AVAILABLE, no det err
           See Page54 Table3
        */

        if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
        {
            result = E_OK;
        }

    }
#endif
    return result;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ReceiveSignalGroupArray SWS_Com_00854
*
* Description:   This service copy signal group data in array type
*
* Inputs:        SignalGroupId: Signal group handle
*                SignalGroupArrayPtr: Reference to the Signal data to be read
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped
*                COM_BUSY:                  in case the TP-Buffer is lock for
                                            large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if((STD_ON == COM_Enable_SignalGroupArrayApi) && (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT))
FUNC(uint8, COM_CODE) Com_ReceiveSignalGroupArray
(
    Com_SignalGroupIdType SignalGroupId,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA)  SignalGroupArrayPtr
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;/* return not available when det err*/
    P2VAR(uint8, AUTOMATIC, COM_VAR) srcDataPtr = NULL_PTR;
    PduIdType RxIpduId = COM_CFG_RXSIGGRP_PDUID(SignalGroupId);



    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_GROUP_ARRAY, COM_E_UNINIT);
    }
    else if(SignalGroupId >= COM_RXSIG_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_GROUP_ARRAY, COM_E_PARAM);
    }
    else if(SignalGroupArrayPtr == NULL_PTR)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_GROUP_ARRAY, COM_E_PARAM);
    }
    else if(COM_CFG_RXSIGGRP_SUPPORT_ARRAY(SignalGroupId) == FALSE)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_GROUP_ARRAY, COM_E_PARAM);
    }
    else
    {
        /* dont need report busy , as copy process is protected by Area2
           and always read old data
        */
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_12();

        srcDataPtr = &((uint8 *)COM_CFG_RXPDU_DATA_PTR(RxIpduId))[COM_CFG_RXSIGGRP_STARTBYTE(SignalGroupId)];
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        COM_GETSPINLOCK(&(Com_SpinLock_RxSigGroup[SignalGroupId]));
#endif
        Bsw_MemCpy(SignalGroupArrayPtr, srcDataPtr, (uint32)COM_CFG_RXSIGGRP_SIZE(SignalGroupId));
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        COM_RELEASESPINLOCK(&(Com_SpinLock_RxSigGroup[SignalGroupId]));
#endif

        SchM_Exit_Com_COM_EXCLUSIVE_AREA_12();

        /*
           when stop , read old data but return COM_SERVICE_NOT_AVAILABLE, no det err
           See Page54 Table3
        */

        if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
        {
            result = E_OK;
        }

    }

    return result;
}

#endif



#if(STD_ON == COM_TXPDU_FUN)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_GetTxIpduState 
*
* Description:   return start or stop state of PDU
*
* Inputs:        TxPduId
*
*
* Outputs:       boolean
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(boolean, COM_CODE) Com_GetTxIpduState
(
     PduIdType TxPduId
)
{
    boolean flag = FALSE;


    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERCIVEID_GET_TX_IPDU_STATE, COM_E_UNINIT);
    }
    else if(TxPduId >= COM_TXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERCIVEID_GET_TX_IPDU_STATE, COM_E_PARAM);
    }
    else
    {
        if(COM_TXPDU_STOP != Com_TxPduState[TxPduId])
        {
            flag = TRUE;
        }
    }

    return flag;
}
#endif


#if(STD_ON == COM_RXPDU_FUN)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_GetRxIpduState 
*
* Description:   return start or stop state of PDU
*
* Inputs:        RxPduId
*
*
* Outputs:       boolean
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COM_CODE) Com_GetRxIpduState
(
    PduIdType RxPduId,
    P2VAR(boolean, AUTOMATIC, COM_APPL_DATA) IsRxPduStart
)
{
    Std_ReturnType result = E_NOT_OK;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 RxPduCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
#endif
    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERCIVEID_GET_RX_IPDU_STATE, COM_E_UNINIT);
    }
    else if(RxPduId >= COM_RXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERCIVEID_GET_RX_IPDU_STATE, COM_E_PARAM);
    }
    else
    {
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        RxPduCoreId = COM_CFG_RXPDU_CORE_ID(RxPduId);
        ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
        if(RxPduCoreId != ComLogicCoreId)
        {
            /*do nothing*/
        }
        else
#endif
        {
            if(COM_RXPDU_STOP == Com_RxPduState[RxPduId])
            {
                *IsRxPduStart = FALSE;
            }
            else
            {
                *IsRxPduStart = TRUE;
            }
            result = E_OK;
        }
    }

    return result;
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SetMetadata
*
* Description:   This function sets the global PDU MetaData
*
* Inputs:        PduId, MetaDataPtr
*
* Outputs:       E_OK: Metadata has been stored
*                E_NOT_OK: Metadata has not been stored
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_MetaDataSupport)
STATIC FUNC(Std_ReturnType, COM_CODE) Com_SetMetadata
(
    PduIdType PduId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) MetaDataPtr
)
{
    Std_ReturnType result = E_NOT_OK;

    if(E_OK == Ecuc_CheckMetaDataSupport(COM_CFG_TXPDU_GLOBAL_PDUID(PduId), ECUC_ENUM_ANYONE_ACT))
    {
        result = Ecuc_SetMetaDataPtr(COM_CFG_TXPDU_GLOBAL_PDUID(PduId), MetaDataPtr);
    }

    return result;
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_GetMetadata
*
* Description:   This function gets the global PDU MetaData
*
* Inputs:        PduId, MetaDataPtr
*
* Outputs:       E_OK: Metadata has been stored
*                E_NOT_OK: Metadata has not been stored
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_MetaDataSupport)
STATIC FUNC(Std_ReturnType, COM_CODE) Com_GetMetadata
(
    PduIdType PduId,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) MetaDataPtr
)
{
    Std_ReturnType result = E_NOT_OK;
    uint8 MetaDataLength;
    uint32 MetaDataPtrTemp;

    result = Ecuc_GetMetaDataPtr(COM_CFG_RXPDU_GLOBAL_PDUID(PduId), &MetaDataPtrTemp);

    if(result == E_OK)
    {
        (void)Ecuc_GetMetaDataLength(COM_CFG_RXPDU_GLOBAL_PDUID(PduId), &MetaDataLength);
        Bsw_MemCpy(MetaDataPtr, (uint8*)MetaDataPtrTemp, (uint32)MetaDataLength);
    }

    return result;
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_TriggerIPDUSendWithMetaData
*
* Description:   Set metadata and trigger the function Com_TriggerIPDUSend
*
* Inputs:        PduId: Sending message handle
*                MetaData: Sending Metadata pointer
*
* Outputs:       E_OK: IPDU trigger transmission is accepted
*                E_NOT_OK: the IPDU is in the stop state or the trigger
*                          transmission is not accepted or metadata ser fail
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_MetaDataSupport)
FUNC(Std_ReturnType, COM_CODE) Com_TriggerIPDUSendWithMetaData
(
    PduIdType PduId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) MetaData
)
{
    uint8 result = E_NOT_OK;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 ComPhyCoreId = COM_GETCOREID();
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TRIGGER_IPDU_SEND_WITH_META_DATA, COM_E_UNINIT);
    }
    else if(PduId >= COM_TXPDU_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TRIGGER_IPDU_SEND_WITH_META_DATA, COM_E_PARAM);
    }
    else if(NULL_PTR == MetaData)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TRIGGER_IPDU_SEND_WITH_META_DATA, COM_E_PARAM_POINTER);
    }
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    else if(COM_CFG_TXPDU_CORE_ID(PduId) != ComCfgCorePhyMapLogic[ComPhyCoreId])
    {
        /* do nothing */
    }
#endif
    else if(E_NOT_OK == Com_SetMetadata(PduId, MetaData))
    {
        /*Set Metadata*/
    }
    else
    {
#if(STD_ON == COM_TriggerIPDUSend_API)
        if(COM_TXPDU_STOP != Com_TxPduState[PduId])/*SWS_Com_00861*/
        {
            Com_TriggerPDUSendFlag[PduId] = TRUE;
            result = E_OK;
        }
#endif
    }

    return result;
}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SendSignalWithMetaData
*
* Description:   Set metadata and trigger the function Com_SendSignal
*
* Inputs:        SignalId: The Id of specified signal
*                SignalDataPtr: Points to the data to be written
*                MetaDataPtr: Sending Metadata pointer
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped or metadata ser fail
*                COM_BUSY:                  in case the TP-Buffer is lock for
*                                           large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_MetaDataSupport)
FUNC(uint8, COM_CODE) Com_SendSignalWithMetaData
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) MetaDataPtr
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    Com_SignalGroupIdType TxSigGrpId = COM_INVALID_SIG_GRP_ID;
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
#endif

#if(STD_ON == COM_TXPDU_FUN)
    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_WITH_META_DATA, COM_E_UNINIT);
    }
    else if(SignalId >= COM_TXSIG_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_WITH_META_DATA, COM_E_PARAM);
    }
    else if(COM_SIG_DYN == COM_CFG_TXSIG_TYPE(SignalId))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_WITH_META_DATA, COM_E_PARAM);
    }
    else if(NULL_PTR == SignalDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_WITH_META_DATA, COM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == MetaDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_TRIGGER_IPDU_SEND_WITH_META_DATA, COM_E_PARAM_POINTER);
    }
    else if(E_NOT_OK == Com_SetMetadata(COM_CFG_TXSIG_TXPDU_ID(SignalId), MetaDataPtr))
    {
        /*Set Metadata*/
    }
    else
    {
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        TxSigCoreId = COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(SignalId));
        ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
        if(TxSigCoreId != ComLogicCoreId)
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_9();
            tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(SignalId);
            if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
            {
                if(TRUE == Com_CheckChangeSignal((void*)SignalDataPtr, COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), COM_CFG_TXSIG_LENGTH(SignalId)))
                {
                    Com_TxSigIsSameValue[SignalId] = FALSE;
                    Com_CopySignalWithOutLock(SignalDataPtr, COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), COM_CFG_TXSIG_LENGTH(SignalId));
                }
                else
                {
                    Com_TxSigIsSameValue[SignalId] = TRUE;
                }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                if(FALSE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(SignalId))
#endif
                {
                    *tempTxSigShareFlagPtr = COM_SIG;
                }
            }
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_9();
        }
        else
#endif
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
            if(TRUE == Com_CheckChangeSignal((void*)SignalDataPtr, COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), COM_CFG_TXSIG_LENGTH(SignalId)))
            {
                Com_TxSigIsSameValue[SignalId] = FALSE;
                Com_CopySignalWithOutLock(SignalDataPtr, COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), COM_CFG_TXSIG_LENGTH(SignalId));
            }
            else
            {
                Com_TxSigIsSameValue[SignalId] = TRUE;
            }
            result = Com_WriteSignal_Internal(SignalId, SignalDataPtr, COM_CFG_TXSIG_LENGTH(SignalId));
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();
        }
    }
#endif/*#if(STD_ON == COM_TXPDU_FUN)*/

    return  result;

}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SendDynSignalWithMetaData
*
* Description:   Set metadata and trigger the function Com_SendDynSignal
*
* Inputs:        SignalId: Signal handle
*                SignalDataPtr: Reference to the Signal data to be transmitted
*                Length: Dyn-Signal length
*                MetaDataPtr: Sending Metadata pointer
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped or metadata set fail
*                COM_BUSY:                  in case the TP-Buffer is lock for
*                                           large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_MetaDataSupport)
FUNC(uint8, COM_CODE) Com_SendDynSignalWithMetaData
(
    Com_SignalIdType SignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    uint16 Length,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) MetaDataPtr
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;
#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    Com_SignalGroupIdType TxSigGrpId = COM_INVALID_SIG_GRP_ID;
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
#endif
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_DYNSIGNAL_WITH_META_DATA, COM_E_UNINIT);
    }
#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
    else if((SignalId >= COM_TXSIG_NUM)
            || (COM_SIG_DYN != COM_CFG_TXSIG_TYPE(SignalId)))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_DYNSIGNAL_WITH_META_DATA, COM_E_PARAM);
    }
    else if(NULL_PTR == SignalDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_DYNSIGNAL_WITH_META_DATA, COM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == MetaDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_DYNSIGNAL_WITH_META_DATA, COM_E_PARAM_POINTER);
    }
    /*Set Metadata*/
    else if(E_NOT_OK == Com_SetMetadata(COM_CFG_TXSIG_TXPDU_ID(SignalId), MetaDataPtr))
    {
        /*Metadata is not configured*/
    }
    else
    {
        /* SWS_Com_00334, signal can be updated when pdu is stop
           in stop mode, tms result, txmode and data will be saved
           but trigger will not be saved,
           so that the msg will not be send at once when pdu is started
        */
        if(Length > COM_CFG_TXSIG_LENGTH(SignalId))
        {
            COM_DET_REPORT_ERROR(COMSERVICEID_SEND_DYNSIGNAL_WITH_META_DATA, COM_E_PARAM);
            result = E_NOT_OK;
        }
        else
        {
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
            TxSigCoreId = COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(SignalId));
            ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
            if(TxSigCoreId != ComLogicCoreId)
            {
                SchM_Enter_Com_COM_EXCLUSIVE_AREA_9();
                tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(SignalId);
                if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
                {
                    if(TRUE == Com_CheckChangeSignal((void*)SignalDataPtr, COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), COM_CFG_TXSIG_LENGTH(SignalId)))
                    {
                        Com_TxSigIsSameValue[SignalId] = FALSE;
                        Com_CopySignalWithOutLock(SignalDataPtr, COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), COM_CFG_TXSIG_LENGTH(SignalId));
                    }
                    else
                    {
                        Com_TxSigIsSameValue[SignalId] = TRUE;
                    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                    if(FALSE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(SignalId))
#endif
                    {
                        *tempTxSigShareFlagPtr = COM_SIG;
                    }
                }
                SchM_Exit_Com_COM_EXCLUSIVE_AREA_9();
            }
            else
#endif
            {
                SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
                if(TRUE == Com_CheckChangeSignal((void*)SignalDataPtr, COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), COM_CFG_TXSIG_LENGTH(SignalId)))
                {
                    Com_TxSigIsSameValue[SignalId] = FALSE;
                    Com_CopySignalWithOutLock(SignalDataPtr, COM_CFG_TXSIG_SHARE_BUF_PTR(SignalId), COM_CFG_TXSIG_TYPE(SignalId), COM_CFG_TXSIG_LENGTH(SignalId));
                }
                else
                {
                    Com_TxSigIsSameValue[SignalId] = TRUE;
                }
                result = Com_WriteSignal_Internal(SignalId, SignalDataPtr, Length);
                SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();
            }
            
        }
    }
#else
    else
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_DYNSIGNAL_WITH_META_DATA, COM_E_PARAM);
    }
#endif/*#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)*/

    return  result;
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SendSignalGroupWithMetaData
*
* Description:   Set metadata and trigger the function Com_SendSignalGroup
*
* Inputs:        SignalId: Signal handle
*                SignalDataPtr: Reference to the Signal data to be transmitted
*                MetaDataPtr: Sending Metadata pointer
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped or metadata set fail
*                COM_BUSY:                  in case the TP-Buffer is lock for
*                                           large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_MetaDataSupport)
FUNC(uint8, COM_CODE) Com_SendSignalGroupWithMetaData
(
    Com_SignalGroupIdType SignalGroupId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) MetaDataPtr
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;/* return not available when det err*/

#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    PduIdType TxIpduId;
    Com_SignalIdType GrpSigIndex = (Com_SignalIdType)0;
    P2VAR(void, AUTOMATIC, COM_VAR) destDataPtr = NULL_PTR;
    PduLengthType length = (PduLengthType)0;
    Com_EndiannessType Endianness;
    Com_SigType SigType;
    uint16 BitSize;
    uint16 StartBit;
    uint8 MaskLsb;
    uint8 MaskMsb;
    uint64 Mask;
#if(STD_OFF == COM_TXMODE_PERIODIC_ONLY)
    boolean changeflag = FALSE;
#endif
#if(STD_ON == COM_TXMODE_IFACTIVE_SUPPORT)
    boolean IfActiveChangeFlag = FALSE;
#endif
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
    Com_SignalIdType TxGroupStartSig;
#endif
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_GROUP_WITH_META_DATA, COM_E_UNINIT);
    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    else if(SignalGroupId >= COM_TXSIG_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_GROUP_WITH_META_DATA, COM_E_PARAM);
    }
    else if(COM_CFG_TXSIGGRP_SUPPORT_ARRAY(SignalGroupId) == TRUE)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_GROUP_WITH_META_DATA, COM_E_PARAM);
    }
    else if(NULL_PTR == MetaDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_GROUP_WITH_META_DATA, COM_E_PARAM_POINTER);
    }
    /*Set Metadata*/
    else if(E_NOT_OK == Com_SetMetadata(COM_CFG_TXSIGGRP_PDUID(SignalGroupId), MetaDataPtr))
    {
        /*Metadata is not configured*/
    }
    else
    {
        TxIpduId = COM_CFG_TXSIGGRP_PDUID(SignalGroupId);
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        TxSigCoreId = COM_CFG_TXPDU_CORE_ID(TxIpduId);
        ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
        if(TxSigCoreId != ComLogicCoreId)
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_9();
            TxGroupStartSig = COM_CFG_TXSIGGRP_SIGSTART(SignalGroupId);
            tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(TxGroupStartSig);
            if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
            {
                *tempTxSigShareFlagPtr = COM_SIG_GRP;
            }
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_9();
        }
        else
#endif
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
            result = Com_SendSignalGroup_Internal(SignalGroupId);
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();
        }

    }
#endif/*#if(STD_ON == COM_TXPDU_FUN)*/


    return  result;

}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_SendSignalGroupArrayWithMetaData
*
* Description:   Set metadata and trigger the function
*                Com_SendSignalGroupArray
*
* Inputs:        SignalGroupId: Signal group handle
*                SignalGroupArrayPtr: Reference to the Signal data to be read
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped or metadata set fail
*                COM_BUSY:                  in case the TP-Buffer is lock for
*                                           large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

#if((STD_ON == COM_Enable_SignalGroupArrayApi) && (STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT) && (STD_ON == COM_MetaDataSupport))
FUNC(uint8, COM_CODE) Com_SendSignalGroupArrayWithMetaData
(
    Com_SignalGroupIdType SignalGroupId,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) SignalGroupArrayPtr,
    P2CONST(uint8, AUTOMATIC, COM_APPL_DATA) MetaDataPtr
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;/* return not available when det err*/
    P2VAR(uint8, AUTOMATIC, COM_VAR) destDataPtr = NULL_PTR;
    PduIdType TxIpduId;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
    Com_SignalIdType TxGroupStartSig;
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_GROUP_ARRAY_WITH_META_DATA, COM_E_UNINIT);
    }
    else if(SignalGroupId >= COM_TXSIG_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_GROUP_ARRAY_WITH_META_DATA, COM_E_PARAM);
    }
    else if(SignalGroupArrayPtr == NULL_PTR)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_GROUP_ARRAY_WITH_META_DATA, COM_E_PARAM);
    }
    else if(COM_CFG_TXSIGGRP_SUPPORT_ARRAY(SignalGroupId) == FALSE)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_GROUP_ARRAY_WITH_META_DATA, COM_E_PARAM);
    }
    else if(NULL_PTR == MetaDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_SEND_SIGNAL_GROUP_ARRAY_WITH_META_DATA, COM_E_PARAM_POINTER);
    }
    /*Set Metadata*/
    else if(E_NOT_OK == Com_SetMetadata(COM_CFG_TXSIGGRP_PDUID(SignalGroupId), MetaDataPtr))
    {
        /*Metadata is not configured*/
    }
    else
    {
        TxIpduId = COM_CFG_TXSIGGRP_PDUID(SignalGroupId);
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        TxSigCoreId = COM_CFG_TXPDU_CORE_ID(TxIpduId);
        ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
        if(TxSigCoreId != ComLogicCoreId)
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_9();
            TxGroupStartSig = COM_CFG_TXSIGGRP_SIGSTART(SignalGroupId);
            tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(TxGroupStartSig);
            if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
            {
                Com_CopySignalWithOutLock(SignalGroupArrayPtr, COM_CFG_TXSIG_GRP_SHARE_BUF_PTR(SignalGroupId), COM_SIG_U8N, (PduLengthType)COM_CFG_TXSIGGRP_SIZE(SignalGroupId));
                *tempTxSigShareFlagPtr = COM_SIG_GRP_ARRAY;
            }
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_9();
        }
        else
#endif
#if(STD_ON == COM_TX_LONG_PDU_FUN)
        if((COM_TXPDU_START_BUSY == Com_TxPduState[TxIpduId]) && (TRUE == COM_CFG_TXPDU_IS_TP_PDU(TxIpduId)))
        {
            result = COM_BUSY;
        }
        else
#endif
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_0();
            Com_SendSignalGroupArray_Internal(SignalGroupId, SignalGroupArrayPtr);
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_0();
        }
    }

    return result;
}
#endif
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ReceiveDynSignalWithMetaData
*
* Description:   Get metadata and trigger the function of Com_ReceiveDynSignal
*
* Inputs:        SignalId: ignal handle
*                SignalDataPtr: Reference to the location where the received
*                               signal data shall be stored
*                Length: Input: receive signal container size
*                        Output: receive dynamic signal size
*                MetaDataPtr: Receive Metadata pointer
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped or MetaData get fail
*                COM_BUSY:                  in case the TP-Buffer is lock for
*                                           large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_MetaDataSupport)
FUNC(uint8, COM_CODE) Com_ReceiveDynSignalWithMetaData
(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    P2VAR(uint16, AUTOMATIC, COM_APPL_DATA) Length,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA)  MetaDataPtr
)
{

    uint8 result = COM_SERVICE_NOT_AVAILABLE;
#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)
    PduIdType RxIpduId;
    Com_SigType SigType;
    PduLengthType dynlength = (PduLengthType)0;
    /* as dyn signal must be byte aligned, so the temp srcDataPtr canbe uint8 * Ptr*/
    PduLengthType tempRxPduDynLen = (PduLengthType)0;
    P2VAR(uint8, AUTOMATIC, COM_VAR) srcDataPtr = NULL_PTR;
    P2VAR(void, AUTOMATIC, COM_VAR) tempRxSigBuf = NULL_PTR;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    Com_RxSigLockIndexType RxSigLockIndex = COM_CFG_RXSIG_LOCK_INDEX(SignalId);
#endif
#if(COM_RX_SIGNAL_GROUP_SUPPORT == STD_ON)
    P2VAR(PduLengthType, AUTOMATIC, COM_VAR) tempRxSigGrpDynLen = NULL_PTR;
#endif
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_DYNSIGNAL_WITH_META_DATA, COM_E_UNINIT);
    }
#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)
    else if(SignalId >= COM_RXSIG_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_DYNSIGNAL_WITH_META_DATA, COM_E_PARAM);
    }
    else if(COM_SIG_DYN != COM_CFG_RXSIG_TYPE(SignalId))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_DYNSIGNAL_WITH_META_DATA, COM_E_PARAM);
    }
    else if(NULL_PTR == SignalDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_DYNSIGNAL_WITH_META_DATA, COM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == Length)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_DYNSIGNAL_WITH_META_DATA, COM_E_PARAM_POINTER);
    }
    else if (NULL_PTR == MetaDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_DYNSIGNAL_WITH_META_DATA, COM_E_PARAM_POINTER);
    }
    /*Get Metadata*/
    else if (E_NOT_OK == Com_GetMetadata(COM_CFG_RXSIG_RXPDU_ID(SignalId), MetaDataPtr))
    {
        /*Metadata is not configured*/
    }
    else
    {
        /* dont need report busy , as copy process is protected by Area2
           and always read old data
        */
        RxIpduId = COM_CFG_RXSIG_RXPDU_ID(SignalId);
        SigType = COM_CFG_RXSIG_TYPE(SignalId);
        tempRxSigBuf = COM_CFG_RXSIG_DATA_PTR(SignalId);
        srcDataPtr = (uint8 *)tempRxSigBuf;
        if(*Length < dynlength)
        {
            COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_DYNSIGNAL_WITH_META_DATA, COM_E_PARAM);
            result = E_NOT_OK;
        }
        else
        {
            SchM_Enter_Com_COM_EXCLUSIVE_AREA_13();
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
            COM_GETSPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
            tempRxPduDynLen = COM_RXPDU_DYN_LENGTH(RxIpduId);
            dynlength = tempRxPduDynLen - COM_CFG_RXSIG_START_BYTE_INDEX(SignalId);
            Bsw_MemCpy((uint8 *)SignalDataPtr, srcDataPtr, (uint32)dynlength);
            *Length = dynlength;
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
            COM_RELEASESPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
            SchM_Exit_Com_COM_EXCLUSIVE_AREA_13();
        }
        /*
           when stop , read old data but return COM_SERVICE_NOT_AVAILABLE, no det err
           See Page54 Table3
        */
        if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
        {
            result = E_OK;
        }
    }
#else
    else
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_DYNSIGNAL, COM_E_PARAM);
    }
#endif/*#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)*/

    return    result;

}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ReceiveSignalWithMetaData
*
* Description:   Get metadata and trigger the function of Com_ReceiveSignal
*
* Inputs:        SignalId: ignal handle
*                SignalDataPtr: Reference to the location where the received
*                               signal data shall be stored
*                MetaDataPtr: Receive Metadata pointer
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped or MetaData get fail
*                COM_BUSY:                  in case the TP-Buffer is lock for
*                                           large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_MetaDataSupport)
FUNC(uint8, COM_CODE) Com_ReceiveSignalWithMetaData
(
    Com_SignalIdType SignalId,
    P2VAR(void, AUTOMATIC, COM_APPL_DATA) SignalDataPtr,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA)  MetaDataPtr
)
{

    uint8 result = COM_SERVICE_NOT_AVAILABLE;
#if(STD_ON == COM_RXPDU_FUN)
    PduIdType RxIpduId;
    PduLengthType SigLen = (PduLengthType)0;
    Com_SigType SigType;
    P2VAR(void, AUTOMATIC, COM_VAR) tempRxSigBuf = NULL_PTR;
#endif


    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_WITH_META_DATA, COM_E_UNINIT);
    }
    else if(SignalId >= COM_RXSIG_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_WITH_META_DATA, COM_E_PARAM);
    }
#if(STD_ON == COM_RXPDU_FUN)
    else if(COM_SIG_DYN == COM_CFG_RXSIG_TYPE(SignalId))
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_WITH_META_DATA, COM_E_PARAM);
    }
    else if(NULL_PTR == SignalDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_WITH_META_DATA, COM_E_PARAM_POINTER);
    }
    else if(NULL_PTR == MetaDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_WITH_META_DATA, COM_E_PARAM_POINTER);
    }
    /*Get Metadata*/
    else if(E_NOT_OK == Com_GetMetadata(COM_CFG_RXSIG_RXPDU_ID(SignalId), MetaDataPtr))
    {
        /*Metadata is not configured*/
    }
    else
    {

        /* dont need report busy , as copy process is protected by Area2
           and always read old data
        */
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_2();
        SigLen = COM_CFG_RXSIG_LENGTH(SignalId);
        SigType = COM_CFG_RXSIG_TYPE(SignalId);
        RxIpduId = COM_CFG_RXSIG_RXPDU_ID(SignalId);
        tempRxSigBuf = COM_CFG_RXSIG_DATA_PTR(SignalId);
        Com_CopySignal(tempRxSigBuf, SignalDataPtr, SigType, SigLen, SignalId);
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_2();

        /*
           when stop , read old data but return COM_SERVICE_NOT_AVAILABLE, no det err
           See Page54 Table3
        */

        if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
        {
            result = E_OK;
        }

    }

#endif/* #if(STD_ON == COM_RXPDU_FUN)*/
    return    result;

}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ReceiveSignalGroupWithMetaData
*
* Description:   Get metadata and trigger the function of Com_ReceiveSignalGroup
*
* Inputs:        SignalId: Signal handle
*                SignalDataPtr: Reference to the Signal data to be transmitted
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped or MetaData get fail
*                COM_BUSY:                  in case the TP-Buffer is lock for
*                                           large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_MetaDataSupport)
FUNC(uint8, COM_CODE) Com_ReceiveSignalGroupWithMetaData
(
    Com_SignalGroupIdType SignalGroupId,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA)  MetaDataPtr
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;/* return not available when det err*/
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    PduIdType RxIpduId = COM_CFG_RXSIGGRP_PDUID(SignalGroupId);
    Com_SignalIdType GrpSigIndex = (Com_SignalIdType)0;
    P2VAR(void, AUTOMATIC, COM_VAR) destDataPtr = NULL_PTR;
    PduLengthType length = (PduLengthType)0;
    Com_SigType SigType;
    P2VAR(void, AUTOMATIC, COM_VAR) tempRxSigBuf = NULL_PTR;
#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)
    PduLengthType tempRxPduDynLen = (PduLengthType)0;
    P2VAR(PduLengthType, AUTOMATIC, COM_VAR) tempRxSigGrpDynLen = NULL_PTR;
#endif
#endif

    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_GROUP_WITH_META_DATA, COM_E_UNINIT);
    }
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    else if(SignalGroupId >= COM_RXSIG_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_GROUP_WITH_META_DATA, COM_E_PARAM);
    }
    else if(COM_CFG_RXSIGGRP_SUPPORT_ARRAY(SignalGroupId) == TRUE)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_GROUP_WITH_META_DATA, COM_E_PARAM);
    }
    else if(NULL_PTR == MetaDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_GROUP_WITH_META_DATA, COM_E_PARAM_POINTER);
    }
    /*Get Metadata*/
    else if(E_NOT_OK == Com_GetMetadata(RxIpduId, MetaDataPtr))
    {
        /*Metadata is not configured*/
    }
    else
    {
        /* dont need report busy , as copy process is protected by Area2
           and always read old data
        */

        SchM_Enter_Com_COM_EXCLUSIVE_AREA_12();

#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        COM_GETSPINLOCK(&(Com_SpinLock_RxSigGroup[SignalGroupId]));
#endif
        for(GrpSigIndex = COM_CFG_RXSIGGRP_SIGSTART(SignalGroupId); GrpSigIndex <= COM_CFG_RXSIGGRP_SIGSTOP(SignalGroupId); GrpSigIndex++)
        {
            destDataPtr = COM_CFG_RXSIG_GROUP_TEMP_BUF(GrpSigIndex);
            tempRxSigBuf = COM_CFG_RXSIG_DATA_PTR(GrpSigIndex);
            length = COM_CFG_RXSIG_LENGTH(GrpSigIndex);
            SigType = COM_CFG_RXSIG_TYPE(GrpSigIndex);
            RxIpduId = COM_CFG_RXSIG_RXPDU_ID(GrpSigIndex);
#if(STD_ON == COM_RX_DYN_PDU_SUPPORT)
            tempRxSigGrpDynLen = COM_CFG_RXSIG_GROUP_TEMPLENGTH_PTR(GrpSigIndex);
            tempRxPduDynLen = COM_RXPDU_DYN_LENGTH(RxIpduId);
            if(COM_SIG_DYN == COM_CFG_RXSIG_TYPE(GrpSigIndex))
            {
                length = tempRxPduDynLen - COM_CFG_RXSIG_START_BYTE_INDEX(GrpSigIndex);
                *tempRxSigGrpDynLen = length;
            }
#endif
            Com_CopySignal(destDataPtr, tempRxSigBuf, SigType, length, GrpSigIndex);
        }
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        COM_RELEASESPINLOCK(&(Com_SpinLock_RxSigGroup[SignalGroupId]));
#endif

        SchM_Exit_Com_COM_EXCLUSIVE_AREA_12();

        /*
           when stop , read old data but return COM_SERVICE_NOT_AVAILABLE, no det err
           See Page54 Table3
        */

        if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
        {
            result = E_OK;
        }

    }
#endif
    return result;

}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_ReceiveSignalGroupArrayWithMetaData
*
* Description:   Get metadata and trigger the function of Com_ReceiveSignalGroupArray
*
* Inputs:        SignalGroupId: Signal group handle
*                SignalGroupArrayPtr: Reference to the Signal data to be read
*
* Outputs:       E_OK:                      service has been accepted
*                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was
*                                           stopped or MetaData get fail
*                COM_BUSY:                  in case the TP-Buffer is lock for
*                                           large data type handling
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if((STD_ON == COM_Enable_SignalGroupArrayApi) && (STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT) && (STD_ON == COM_MetaDataSupport))
FUNC(uint8, COM_CODE) Com_ReceiveSignalGroupArrayWithMetaData
(
    Com_SignalGroupIdType SignalGroupId,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA)  SignalGroupArrayPtr,
    P2VAR(uint8, AUTOMATIC, COM_APPL_DATA)  MetaDataPtr
)
{
    uint8 result = COM_SERVICE_NOT_AVAILABLE;/* return not available when det err*/
    P2VAR(uint8, AUTOMATIC, COM_VAR) srcDataPtr = NULL_PTR;
    PduIdType RxIpduId = COM_CFG_RXSIGGRP_PDUID(SignalGroupId);



    if(COM_INIT != Com_InitStateFlag)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_GROUP_ARRAY_WITH_META_DATA, COM_E_UNINIT);
    }
    else if(SignalGroupId >= COM_RXSIG_GROUP_NUM)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_GROUP_ARRAY_WITH_META_DATA, COM_E_PARAM);
    }
    else if(SignalGroupArrayPtr == NULL_PTR)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_GROUP_ARRAY_WITH_META_DATA, COM_E_PARAM);
    }
    else if(COM_CFG_RXSIGGRP_SUPPORT_ARRAY(SignalGroupId) == FALSE)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_GROUP_ARRAY_WITH_META_DATA, COM_E_PARAM);
    }
    else if(NULL_PTR == MetaDataPtr)
    {
        COM_DET_REPORT_ERROR(COMSERVICEID_RECEIVE_SIGNAL_GROUP_ARRAY_WITH_META_DATA, COM_E_PARAM_POINTER);
    }
    /*Get Metadata*/
    else if(E_NOT_OK == Com_GetMetadata(RxIpduId, MetaDataPtr))
    {
        /*Metadata is not configured*/
    }
    else
    {
        /* dont need report busy , as copy process is protected by Area2
           and always read old data
        */

        SchM_Enter_Com_COM_EXCLUSIVE_AREA_12();

#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        COM_GETSPINLOCK(&(Com_SpinLock_RxSigGroup[SignalGroupId]));
#endif
        Bsw_MemCpy(SignalGroupArrayPtr, srcDataPtr, (uint32)COM_CFG_RXSIGGRP_SIZE(SignalGroupId));
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
        COM_RELEASESPINLOCK(&(Com_SpinLock_RxSigGroup[SignalGroupId]));
#endif

        SchM_Exit_Com_COM_EXCLUSIVE_AREA_12();

        /*
           when stop , read old data but return COM_SERVICE_NOT_AVAILABLE, no det err
           See Page54 Table3
        */

        if(COM_RXPDU_STOP != Com_RxPduState[RxIpduId])
        {
            result = E_OK;
        }

    }

    return result;
}

#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_BusValueToPhyValue_64
*
* Description:   U64 Type signal convert S64.
*
* Inputs:        value
*                lastbit
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(sint64, COM_CODE) Com_BusValueToPhyValue_64
(
    uint64 value,
    uint8 lastbit
)
{
    sint64 ret = (sint64)value;
    uint64 initvalue = (uint64)0xFFFFFFFFFFFFFFFF;
    uint64 mask = (uint64)0;

    if(lastbit < (uint8)63)
    {
        mask = (uint64)1 << (uint64)lastbit;
        if((uint64)0 != (value & mask))
        {
            ret = (sint64)(value | (initvalue << lastbit));
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_BusValueToPhyValue_32
*
* Description:   U32 Type signal convert S32.
*
* Inputs:        value
*                lastbit
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(sint32, COM_CODE) Com_BusValueToPhyValue_32
(
    uint32 value,
    uint8 lastbit
)
{
    sint32 ret = (sint32)value;
    uint32 initvalue = (uint32)0xFFFFFFFF;
    uint32 mask = (uint32)0;

    if(lastbit < (uint8)31)
    {
        mask = (uint32)1 << (uint32)lastbit;
        if((uint32)0 != (value & mask))
        {
            ret = (sint32)(value | (initvalue << lastbit));
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_BusValueToPhyValue_16
*
* Description:   U16 Type signal convert S16.
*
* Inputs:        value
*                lastbit
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(sint16, COM_CODE) Com_BusValueToPhyValue_16
(
    uint16 value,
    uint8 lastbit
)
{
    sint16 ret = (sint16)value;
    uint16 initvalue = (uint16)0xFFFF;
    uint16 mask = (uint16)0;

    if(lastbit < (uint8)15)
    {
        mask = (uint16)((uint16)1 << (uint16)lastbit);
        if((uint16)0 != (uint16)(value & mask))
        {
            ret = (sint16)(value | ((uint16)(initvalue << lastbit)));
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_BusValueToPhyValue_8
*
* Description:   U8 Type signal convert S8.
*
* Inputs:        value
*                lastbit
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(sint8, COM_CODE) Com_BusValueToPhyValue_8
(
    uint8 value,
    uint8 lastbit
)
{
    sint8 ret = (sint8)value;
    uint8 initvalue = (uint8)0xFF;
    uint8 mask = (uint8)0;

    if(lastbit < (uint8)7)
    {
        mask = (uint8)((uint8)1 << lastbit);
        if((uint8)0 != (uint8)(value & mask))
        {
            ret = (sint8)(value | ((uint8)(initvalue << lastbit)));
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_GateWaySignal
*
* Description:   GateWay signal process.
*
* Inputs:        GwSignalIndex
*                ValuePtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_GW_FUN)
STATIC FUNC(void, COM_CODE) Com_GateWaySignal
(
    Com_SignalIdType GwSignalIndex,
    P2VAR(void, AUTOMATIC, COM_VAR) ValuePtr
)
{
    Com_SignalIdType SrcSignalId;
    uint16 ByteLength;
    Com_SignalIdType DestSignalNum;
    Com_SignalIdType DestSigId;
    Com_SignalIdType DestSigIndex;
    P2CONST(Com_CfgGwTxSigTableType, AUTOMATIC, COM_CONST) DestSignalTable;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType DestSigGrpId;
    boolean IsSigGrpGw;
#endif
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
#endif

    SrcSignalId = COM_CFG_GW_SIGNAL_ID(GwSignalIndex);
    DestSignalNum = COM_CFG_GW_TX_SIGNAL_NUM(GwSignalIndex);
    DestSignalTable = COM_CFG_GW_TX_SIGNAL_TABLE(GwSignalIndex);
    ByteLength = COM_CFG_RXSIG_LENGTH(SrcSignalId);

    for(DestSigIndex = 0; DestSigIndex < DestSignalNum; DestSigIndex++)
    {
        DestSigId = DestSignalTable[DestSigIndex].GwTxSignalId;
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
        TxSigCoreId = COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(DestSigId));
        ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
        if(TxSigCoreId != ComLogicCoreId)
        {
            tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(DestSigId);
            if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
            {
                if(TRUE == Com_CheckChangeSignal(ValuePtr, COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId), COM_CFG_TXSIG_TYPE(DestSigId), COM_CFG_TXSIG_LENGTH(DestSigId)))
                {
                    Com_TxSigIsSameValue[DestSigId] = FALSE;
                    Com_CopySignalWithOutLock(ValuePtr, COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId), COM_CFG_TXSIG_TYPE(DestSigId), COM_CFG_TXSIG_LENGTH(DestSigId));
                }
                else
                {
                    Com_TxSigIsSameValue[DestSigId] = TRUE;
                }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                {
#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
                    if(COM_SIG_DYN == COM_CFG_TXSIG_TYPE(DestSigId))
                    {
                        *COM_CFG_TXSIG_GROUP_TEMPLENGTH_PTR(DestSigId) = ByteLength;
                    }
#endif
                    IsSigGrpGw = DestSignalTable[DestSigIndex].GwIsSigGrp;
                    if(FALSE == IsSigGrpGw)
                    {
                        *tempTxSigShareFlagPtr = COM_SIG_GRP;
                    }
                    else
                    {
                        DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                        if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                        {
                            *tempTxSigShareFlagPtr = COM_SIG_GRP;
                        }
                    }
                }
                else
#endif
                {
                    *tempTxSigShareFlagPtr = COM_SIG;
                }
            }
        }
        else
#endif
        {
            if(TRUE == Com_CheckChangeSignal(ValuePtr, COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId), COM_CFG_TXSIG_TYPE(DestSigId), COM_CFG_TXSIG_LENGTH(DestSigId)))
            {
                Com_TxSigIsSameValue[DestSigId] = FALSE;
                Com_CopySignalWithOutLock(ValuePtr, COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId), COM_CFG_TXSIG_TYPE(DestSigId), COM_CFG_TXSIG_LENGTH(DestSigId));
            }
            else
            {
                Com_TxSigIsSameValue[DestSigId] = TRUE;
            }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
            if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
            {
#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
                if(COM_SIG_DYN == COM_CFG_TXSIG_TYPE(DestSigId))
                {
                    *COM_CFG_TXSIG_GROUP_TEMPLENGTH_PTR(DestSigId) = ByteLength;
                }
#endif
                DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                if(FALSE == IsSigGrpGw)
                {
                    Com_SendSignalGroup_Internal(DestSigGrpId);
                }
                else
                {
                    if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                    {
                        Com_SendSignalGroup_Internal(DestSigGrpId);
                    }
                }
            }
            else
#endif
            {
                (void)Com_WriteSignal_Internal(DestSigId, ValuePtr, (PduLengthType)ByteLength);
            }
        }
    }
}
#endif

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleRxSig_U8
*
* Description:   Rx signal copy and gateway.
*
* Inputs:        RxSigId
*                RxPduPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_U8
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    uint8 Value_U8 = (uint8)0;

    Com_EndiannessType Endianness;
    uint16 BitSize;
    uint16 StartBit;
    uint64 Mask;
#if(STD_ON == COM_GW_FUN)
    Com_SignalIdType GWSigIndex;
    Com_SignalIdType DestSignalNum;
    P2CONST(Com_CfgGwTxSigTableType, AUTOMATIC, COM_CONST) DestSignalTable;
    Com_SignalIdType DestSigId;
    Com_SignalIdType DestSigIndex;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType DestSigGrpId;
    boolean IsSigGrpGw;
#endif
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
#endif
#endif

    Endianness = COM_CFG_RXSIG_ENDIANNESS(RxSigId);
    BitSize = COM_CFG_RXSIG_BIT_SIZE(RxSigId);
    StartBit = COM_CFG_RXSIG_START_BIT(RxSigId);
    Mask = COM_CFG_RXSIG_MASK(RxSigId);

    /*Copy SigValue from Pdu*/
#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleU8(&Value_U8, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigU8(&Value_U8, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleU8(&Value_U8, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigU8(&Value_U8, PduPtr, BitSize, StartBit, Mask);
#endif

    /*Copy SigValue to Buffer*/
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    if(NULL_PTR != COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId))
    {
        *(uint8*)COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId) = Value_U8;
    }
    else
#endif
    {
        *(uint8*)COM_CFG_RXSIG_DATA_PTR(RxSigId) = Value_U8;
    }

#if(STD_ON == COM_GW_FUN)
    /*Sig GW*/
    SchM_Enter_Com_COM_EXCLUSIVE_AREA_5();
    GWSigIndex = COM_CFG_RXSIG_GW_INDEX(RxSigId);
    if(COM_INVALID_SIG_INDEX != GWSigIndex)
    {
        DestSignalNum = COM_CFG_GW_TX_SIGNAL_NUM(GWSigIndex);
        DestSignalTable = COM_CFG_GW_TX_SIGNAL_TABLE(GWSigIndex);
        for(DestSigIndex = 0; DestSigIndex < DestSignalNum; DestSigIndex++)
        {
            DestSigId = DestSignalTable[DestSigIndex].GwTxSignalId;
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
            TxSigCoreId = COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(DestSigId));
            ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
            if(TxSigCoreId != ComLogicCoreId)
            {
                tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(DestSigId);
                if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
                {
                    /*Whether it is the same value as the old share tx buffer*/
                    if(Value_U8 == *(uint8*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                    {
                        Com_TxSigIsSameValue[DestSigId] = TRUE;
                    }
                    else
                    {
                        Com_TxSigIsSameValue[DestSigId] = FALSE;
                        *(uint8*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_U8;
                    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                    if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                    {
                        IsSigGrpGw = DestSignalTable[DestSigIndex].GwIsSigGrp;
                        if(FALSE == IsSigGrpGw)
                        {
                            *tempTxSigShareFlagPtr = COM_SIG_GRP;
                        }
                        else
                        {
                            DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                            if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                            {
                                *tempTxSigShareFlagPtr = COM_SIG_GRP;
                            }
                        }
                    }
                    else
#endif
                    {
                        *tempTxSigShareFlagPtr = COM_SIG;
                    }
                }
            }
            else
#endif
            {
                /*Whether it is the same value as the old share tx buffer*/
                if(Value_U8 == *(uint8*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                {
                    Com_TxSigIsSameValue[DestSigId] = TRUE;
                }
                else
                {
                    Com_TxSigIsSameValue[DestSigId] = FALSE;
                    *(uint8*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_U8;
                }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                {
                    DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                    if(FALSE == IsSigGrpGw)
                    {
                        Com_SendSignalGroup_Internal(DestSigGrpId);
                    }
                    else
                    {
                        if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                        {
                            Com_SendSignalGroup_Internal(DestSigGrpId);
                        }
                    }
                }
                else
#endif
                {
                    (void)Com_WriteSignal_Internal(DestSigId, &Value_U8, (PduLengthType)0);
                }
            }
        }
    }
    SchM_Exit_Com_COM_EXCLUSIVE_AREA_5();
#endif
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleRxSig_S8
*
* Description:   Rx signal copy and gateway.
*
* Inputs:        RxSigId
*                RxPduPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_S8
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    sint8 Value_S8 = (uint8)0;
    uint8 Value_U8 = (uint8)0;
    uint8 Lastbit = (uint8)0;
    Com_EndiannessType Endianness;
    uint16 BitSize;
    uint16 StartBit;
    uint64 Mask;
#if(STD_ON == COM_GW_FUN)
    Com_SignalIdType GWSigIndex;
    Com_SignalIdType DestSignalNum;
    P2CONST(Com_CfgGwTxSigTableType, AUTOMATIC, COM_CONST) DestSignalTable;
    Com_SignalIdType DestSigId;
    Com_SignalIdType DestSigIndex;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType DestSigGrpId;
    boolean IsSigGrpGw;
#endif
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
#endif
#endif

    Endianness = COM_CFG_RXSIG_ENDIANNESS(RxSigId);
    BitSize = COM_CFG_RXSIG_BIT_SIZE(RxSigId);
    StartBit = COM_CFG_RXSIG_START_BIT(RxSigId);
    Mask = COM_CFG_RXSIG_MASK(RxSigId);
    Lastbit = (uint8)(BitSize - (uint16)1);
    /*Copy SigValue from Pdu*/
#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleU8(&Value_U8, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigU8(&Value_U8, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleU8(&Value_U8, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigU8(&Value_U8, PduPtr, BitSize, StartBit, Mask);
#endif
    /*Read signed signals symbol bit need to be transferre, but not need when write signal!!!!!!!*/
    Value_S8 = Com_BusValueToPhyValue_8(Value_U8, Lastbit);

    /*Copy SigValue to Buffer*/
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    if(NULL_PTR != COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId))
    {
        *(sint8*)COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId) = Value_S8;
    }
    else
#endif
    {
        *(sint8*)COM_CFG_RXSIG_DATA_PTR(RxSigId) = Value_S8;
    }

#if(STD_ON == COM_GW_FUN)
    /*Sig GW*/
    SchM_Enter_Com_COM_EXCLUSIVE_AREA_5();
    GWSigIndex = COM_CFG_RXSIG_GW_INDEX(RxSigId);
    if(COM_INVALID_SIG_INDEX != GWSigIndex)
    {
        DestSignalNum = COM_CFG_GW_TX_SIGNAL_NUM(GWSigIndex);
        DestSignalTable = COM_CFG_GW_TX_SIGNAL_TABLE(GWSigIndex);
        for(DestSigIndex = 0; DestSigIndex < DestSignalNum; DestSigIndex++)
        {
            DestSigId = DestSignalTable[DestSigIndex].GwTxSignalId;
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
            TxSigCoreId = COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(DestSigId));
            ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
            if(TxSigCoreId != ComLogicCoreId)
            {
                tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(DestSigId);
                if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
                {
                    /*Whether it is the same value as the old share tx buffer*/
                    if(Value_S8 == *(sint8*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                    {
                        Com_TxSigIsSameValue[DestSigId] = TRUE;
                    }
                    else
                    {
                        Com_TxSigIsSameValue[DestSigId] = FALSE;
                        *(sint8*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_S8;
                    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                    if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                    {
                        IsSigGrpGw = DestSignalTable[DestSigIndex].GwIsSigGrp;
                        if(FALSE == IsSigGrpGw)
                        {
                            *tempTxSigShareFlagPtr = COM_SIG_GRP;
                        }
                        else
                        {
                            DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                            if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                            {
                                *tempTxSigShareFlagPtr = COM_SIG_GRP;
                            }
                        }
                    }
                    else
#endif
                    {
                        *tempTxSigShareFlagPtr = COM_SIG;
                    }
                }
            }
            else
#endif
            {
                /*Whether it is the same value as the old share tx buffer*/
                if(Value_S8 == *(sint8*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                {
                    Com_TxSigIsSameValue[DestSigId] = TRUE;
                }
                else
                {
                    Com_TxSigIsSameValue[DestSigId] = FALSE;
                    *(sint8*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_S8;
                }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                {
                    DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                    if(FALSE == IsSigGrpGw)
                    {
                        Com_SendSignalGroup_Internal(DestSigGrpId);
                    }
                    else
                    {
                        if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                        {
                            Com_SendSignalGroup_Internal(DestSigGrpId);
                        }
                    }
                }
                else
#endif
                {
                    (void)Com_WriteSignal_Internal(DestSigId, &Value_S8, (PduLengthType)0);
                }
            }
        }
    }
    SchM_Exit_Com_COM_EXCLUSIVE_AREA_5();
#endif
}


/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleRxSig_U16
*
* Description:   Rx signal copy and gateway.
*
* Inputs:        RxSigId
*                RxPduPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_U16
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    uint16 Value_U16 = (uint8)0;

    Com_EndiannessType Endianness;
    uint16 BitSize;
    uint16 StartBit;
    uint64 Mask;
#if(STD_ON == COM_GW_FUN)
    Com_SignalIdType GWSigIndex;
    Com_SignalIdType DestSignalNum;
    P2CONST(Com_CfgGwTxSigTableType, AUTOMATIC, COM_CONST) DestSignalTable;
    Com_SignalIdType DestSigId;
    Com_SignalIdType DestSigIndex;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType DestSigGrpId;
    boolean IsSigGrpGw;
#endif
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
#endif
#endif

    Endianness = COM_CFG_RXSIG_ENDIANNESS(RxSigId);
    BitSize = COM_CFG_RXSIG_BIT_SIZE(RxSigId);
    StartBit = COM_CFG_RXSIG_START_BIT(RxSigId);
    Mask = COM_CFG_RXSIG_MASK(RxSigId);

    /*Copy SigValue from Pdu*/
#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleU16(&Value_U16, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigU16(&Value_U16, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleU16(&Value_U16, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigU16(&Value_U16, PduPtr, BitSize, StartBit, Mask);
#endif

    /*Copy SigValue to Buffer*/
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    if(NULL_PTR != COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId))
    {
        *(uint16*)COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId) = Value_U16;
    }
    else
#endif
    {
        *(uint16*)COM_CFG_RXSIG_DATA_PTR(RxSigId) = Value_U16;
    }

#if(STD_ON == COM_GW_FUN)
    /*Sig GW*/
    SchM_Enter_Com_COM_EXCLUSIVE_AREA_5();
    GWSigIndex = COM_CFG_RXSIG_GW_INDEX(RxSigId);
    if(COM_INVALID_SIG_INDEX != GWSigIndex)
    {
        DestSignalNum = COM_CFG_GW_TX_SIGNAL_NUM(GWSigIndex);
        DestSignalTable = COM_CFG_GW_TX_SIGNAL_TABLE(GWSigIndex);
        for(DestSigIndex = 0; DestSigIndex < DestSignalNum; DestSigIndex++)
        {
            DestSigId = DestSignalTable[DestSigIndex].GwTxSignalId;
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
            TxSigCoreId = COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(DestSigId));
            ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
            if(TxSigCoreId != ComLogicCoreId)
            {
                tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(DestSigId);
                if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
                {
                    /*Whether it is the same value as the old share tx buffer*/
                    if(Value_U16 == *(uint16*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                    {
                        Com_TxSigIsSameValue[DestSigId] = TRUE;
                    }
                    else
                    {
                        Com_TxSigIsSameValue[DestSigId] = FALSE;
                        *(uint16*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_U16;
                    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                    if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                    {
                        IsSigGrpGw = DestSignalTable[DestSigIndex].GwIsSigGrp;
                        if(FALSE == IsSigGrpGw)
                        {
                            *tempTxSigShareFlagPtr = COM_SIG_GRP;
                        }
                        else
                        {
                            DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                            if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                            {
                                *tempTxSigShareFlagPtr = COM_SIG_GRP;
                            }
                        }
                    }
                    else
#endif
                    {
                        *tempTxSigShareFlagPtr = COM_SIG;
                    }
                }
            }
            else
#endif
            {
                    /*Whether it is the same value as the old share tx buffer*/
                    if(Value_U16 == *(uint16*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                    {
                        Com_TxSigIsSameValue[DestSigId] = TRUE;
                    }
                    else
                    {
                        Com_TxSigIsSameValue[DestSigId] = FALSE;
                        *(uint16*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_U16;
                    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                {
                    DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                    if(FALSE == IsSigGrpGw)
                    {
                        Com_SendSignalGroup_Internal(DestSigGrpId);
                    }
                    else
                    {
                        if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                        {
                            Com_SendSignalGroup_Internal(DestSigGrpId);
                        }
                    }
                }
                else
#endif
                {
                    (void)Com_WriteSignal_Internal(DestSigId, &Value_U16, (PduLengthType)0);
                }
            }
        }
    }
    SchM_Exit_Com_COM_EXCLUSIVE_AREA_5();
#endif
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleRxSig_S16
*
* Description:   Rx signal copy and gateway.
*
* Inputs:        RxSigId
*                RxPduPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_S16
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    sint16 Value_S16 = (uint8)0;
    uint16 Value_U16 = (uint16)0;
    uint8 Lastbit = (uint8)0;
    Com_EndiannessType Endianness;
    uint16 BitSize;
    uint16 StartBit;
    uint64 Mask;
#if(STD_ON == COM_GW_FUN)
    Com_SignalIdType GWSigIndex;
    Com_SignalIdType DestSignalNum;
    P2CONST(Com_CfgGwTxSigTableType, AUTOMATIC, COM_CONST) DestSignalTable;
    Com_SignalIdType DestSigId;
    Com_SignalIdType DestSigIndex;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType DestSigGrpId;
    boolean IsSigGrpGw;
#endif
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
#endif
#endif

    Endianness = COM_CFG_RXSIG_ENDIANNESS(RxSigId);
    BitSize = COM_CFG_RXSIG_BIT_SIZE(RxSigId);
    StartBit = COM_CFG_RXSIG_START_BIT(RxSigId);
    Mask = COM_CFG_RXSIG_MASK(RxSigId);
    Lastbit = (uint8)(BitSize - (uint16)1);
    /*Copy SigValue from Pdu*/
#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleU16(&Value_U16, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigU16(&Value_U16, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleU16(&Value_U16, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigU16(&Value_U16, PduPtr, BitSize, StartBit, Mask);
#endif
    /*Read signed signals symbol bit need to be transferre, but not need when write signal!!!!!!!*/
    Value_S16 = Com_BusValueToPhyValue_16(Value_U16, Lastbit);

    /*Copy SigValue to Buffer*/
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    if(NULL_PTR != COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId))
    {
        *(sint16*)COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId) = Value_S16;
    }
    else
#endif
    {
        *(sint16*)COM_CFG_RXSIG_DATA_PTR(RxSigId) = Value_S16;
    }

#if(STD_ON == COM_GW_FUN)
    /*Sig GW*/
    SchM_Enter_Com_COM_EXCLUSIVE_AREA_5();
    GWSigIndex = COM_CFG_RXSIG_GW_INDEX(RxSigId);
    if(COM_INVALID_SIG_INDEX != GWSigIndex)
    {
        DestSignalNum = COM_CFG_GW_TX_SIGNAL_NUM(GWSigIndex);
        DestSignalTable = COM_CFG_GW_TX_SIGNAL_TABLE(GWSigIndex);
        for(DestSigIndex = 0; DestSigIndex < DestSignalNum; DestSigIndex++)
        {
            DestSigId = DestSignalTable[DestSigIndex].GwTxSignalId;
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
            TxSigCoreId = COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(DestSigId));
            ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
            if(TxSigCoreId != ComLogicCoreId)
            {
                tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(DestSigId);
                if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
                {
                    /*Whether it is the same value as the old share tx buffer*/
                    if(Value_S16 ==  *(sint16*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                    {
                        Com_TxSigIsSameValue[DestSigId] = TRUE;
                    }
                    else
                    {
                        Com_TxSigIsSameValue[DestSigId] = FALSE;
                        *(sint16*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_S16;
                    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                    if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                    {
                        IsSigGrpGw = DestSignalTable[DestSigIndex].GwIsSigGrp;
                        if(FALSE == IsSigGrpGw)
                        {
                            *tempTxSigShareFlagPtr = COM_SIG_GRP;
                        }
                        else
                        {
                            DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                            if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                            {
                                *tempTxSigShareFlagPtr = COM_SIG_GRP;
                            }
                        }
                    }
                    else
#endif
                    {
                        *tempTxSigShareFlagPtr = COM_SIG;
                    }
                }
            }
            else
#endif
            {
                /*Whether it is the same value as the old share tx buffer*/
                if(Value_S16 ==  *(sint16*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                {
                    Com_TxSigIsSameValue[DestSigId] = TRUE;
                }
                else
                {
                    Com_TxSigIsSameValue[DestSigId] = FALSE;
                    *(sint16*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_S16;
                }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                {
                    DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                    if(FALSE == IsSigGrpGw)
                    {
                        Com_SendSignalGroup_Internal(DestSigGrpId);
                    }
                    else
                    {
                        if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                        {
                            Com_SendSignalGroup_Internal(DestSigGrpId);
                        }
                    }
                }
                else
#endif
                {
                    (void)Com_WriteSignal_Internal(DestSigId, &Value_S16, (PduLengthType)0);
                }
            }
        }
    }
    SchM_Exit_Com_COM_EXCLUSIVE_AREA_5();
#endif
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleRxSig_U32
*
* Description:   Rx signal copy and gateway.
*
* Inputs:        RxSigId
*                RxPduPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_U32
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    uint32 Value_U32 = (uint8)0;

    Com_EndiannessType Endianness;
    uint16 BitSize;
    uint16 StartBit;
    uint64 Mask;
#if(STD_ON == COM_GW_FUN)
    Com_SignalIdType GWSigIndex;
    Com_SignalIdType DestSignalNum;
    P2CONST(Com_CfgGwTxSigTableType, AUTOMATIC, COM_CONST) DestSignalTable;
    Com_SignalIdType DestSigId;
    Com_SignalIdType DestSigIndex;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType DestSigGrpId;
    boolean IsSigGrpGw;
#endif
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
#endif
#endif

    Endianness = COM_CFG_RXSIG_ENDIANNESS(RxSigId);
    BitSize = COM_CFG_RXSIG_BIT_SIZE(RxSigId);
    StartBit = COM_CFG_RXSIG_START_BIT(RxSigId);
    Mask = COM_CFG_RXSIG_MASK(RxSigId);

    /*Copy SigValue from Pdu*/
#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleU32(&Value_U32, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigU32(&Value_U32, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleU32(&Value_U32, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigU32(&Value_U32, PduPtr, BitSize, StartBit, Mask);
#endif

    /*Copy SigValue to Buffer*/
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    if(NULL_PTR != COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId))
    {
        *(uint32*)COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId) = Value_U32;
    }
    else
#endif
    {
        *(uint32*)COM_CFG_RXSIG_DATA_PTR(RxSigId) = Value_U32;
    }

#if(STD_ON == COM_GW_FUN)
    /*Sig GW*/
    SchM_Enter_Com_COM_EXCLUSIVE_AREA_5();
    GWSigIndex = COM_CFG_RXSIG_GW_INDEX(RxSigId);
    if(COM_INVALID_SIG_INDEX != GWSigIndex)
    {
        DestSignalNum = COM_CFG_GW_TX_SIGNAL_NUM(GWSigIndex);
        DestSignalTable = COM_CFG_GW_TX_SIGNAL_TABLE(GWSigIndex);
        for(DestSigIndex = 0; DestSigIndex < DestSignalNum; DestSigIndex++)
        {
            DestSigId = DestSignalTable[DestSigIndex].GwTxSignalId;
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
            TxSigCoreId = COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(DestSigId));
            ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
            if(TxSigCoreId != ComLogicCoreId)
            {
                tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(DestSigId);
                if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
                {
                    /*Whether it is the same value as the old share tx buffer*/
                    if(Value_U32 ==  *(uint32*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                    {
                        Com_TxSigIsSameValue[DestSigId] = TRUE;
                    }
                    else
                    {
                        Com_TxSigIsSameValue[DestSigId] = FALSE;
                        *(uint32*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_U32;
                    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                    if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                    {
                        IsSigGrpGw = DestSignalTable[DestSigIndex].GwIsSigGrp;
                        if(FALSE == IsSigGrpGw)
                        {
                            *tempTxSigShareFlagPtr = COM_SIG_GRP;
                        }
                        else
                        {
                            DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                            if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                            {
                                *tempTxSigShareFlagPtr = COM_SIG_GRP;
                            }
                        }
                    }
                    else
#endif
                    {
                        *tempTxSigShareFlagPtr = COM_SIG;
                    }
                }
            }
            else
#endif
            {
                /*Whether it is the same value as the old share tx buffer*/
                if(Value_U32 ==  *(uint32*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                {
                    Com_TxSigIsSameValue[DestSigId] = TRUE;
                }
                else
                {
                    Com_TxSigIsSameValue[DestSigId] = FALSE;
                    *(uint32*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_U32;
                }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                {
                    DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                    if(FALSE == IsSigGrpGw)
                    {
                        Com_SendSignalGroup_Internal(DestSigGrpId);
                    }
                    else
                    {
                        if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                        {
                            Com_SendSignalGroup_Internal(DestSigGrpId);
                        }
                    }
                }
                else
#endif
                {
                    (void)Com_WriteSignal_Internal(DestSigId, &Value_U32, (PduLengthType)0);
                }
            }
        }
    }
    SchM_Exit_Com_COM_EXCLUSIVE_AREA_5();
#endif
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleRxSig_S32
*
* Description:   Rx signal copy and gateway.
*
* Inputs:        RxSigId
*                RxPduPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_S32
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    sint32 Value_S32 = (uint8)0;
    uint32 Value_U32 = (uint16)0;
    uint8 Lastbit = (uint8)0;
    Com_EndiannessType Endianness;
    uint16 BitSize;
    uint16 StartBit;
    uint64 Mask;
#if(STD_ON == COM_GW_FUN)
    Com_SignalIdType GWSigIndex;
    Com_SignalIdType DestSignalNum;
    P2CONST(Com_CfgGwTxSigTableType, AUTOMATIC, COM_CONST) DestSignalTable;
    Com_SignalIdType DestSigId;
    Com_SignalIdType DestSigIndex;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType DestSigGrpId;
    boolean IsSigGrpGw;
#endif
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
#endif
#endif

    Endianness = COM_CFG_RXSIG_ENDIANNESS(RxSigId);
    BitSize = COM_CFG_RXSIG_BIT_SIZE(RxSigId);
    StartBit = COM_CFG_RXSIG_START_BIT(RxSigId);
    Mask = COM_CFG_RXSIG_MASK(RxSigId);
    Lastbit = (uint8)(BitSize - (uint16)1);
    /*Copy SigValue from Pdu*/
#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleU32(&Value_U32, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigU32(&Value_U32, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleU32(&Value_U32, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigU32(&Value_U32, PduPtr, BitSize, StartBit, Mask);
#endif
    /*Read signed signals symbol bit need to be transferre, but not need when write signal!!!!!!!*/
    Value_S32 = Com_BusValueToPhyValue_32(Value_U32, Lastbit);

    /*Copy SigValue to Buffer*/
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    if(NULL_PTR != COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId))
    {
        *(sint32*)COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId) = Value_S32;
    }
    else
#endif
    {
        *(sint32*)COM_CFG_RXSIG_DATA_PTR(RxSigId) = Value_S32;
    }

#if(STD_ON == COM_GW_FUN)
    /*Sig GW*/
    SchM_Enter_Com_COM_EXCLUSIVE_AREA_5();
    GWSigIndex = COM_CFG_RXSIG_GW_INDEX(RxSigId);
    if(COM_INVALID_SIG_INDEX != GWSigIndex)
    {
        DestSignalNum = COM_CFG_GW_TX_SIGNAL_NUM(GWSigIndex);
        DestSignalTable = COM_CFG_GW_TX_SIGNAL_TABLE(GWSigIndex);
        for(DestSigIndex = 0; DestSigIndex < DestSignalNum; DestSigIndex++)
        {
            DestSigId = DestSignalTable[DestSigIndex].GwTxSignalId;
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
            TxSigCoreId = COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(DestSigId));
            ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
            if(TxSigCoreId != ComLogicCoreId)
            {
                tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(DestSigId);
                if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
                {
                    /*Whether it is the same value as the old share tx buffer*/
                    if(Value_S32 ==  *(sint32*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                    {
                        Com_TxSigIsSameValue[DestSigId] = TRUE;
                    }
                    else
                    {
                        Com_TxSigIsSameValue[DestSigId] = FALSE;
                        *(sint32*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_S32;
                    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                    if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                    {
                        IsSigGrpGw = DestSignalTable[DestSigIndex].GwIsSigGrp;
                        if(FALSE == IsSigGrpGw)
                        {
                            *tempTxSigShareFlagPtr = COM_SIG_GRP;
                        }
                        else
                        {
                            DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                            if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                            {
                                *tempTxSigShareFlagPtr = COM_SIG_GRP;
                            }
                        }
                    }
                    else
#endif
                    {
                        *tempTxSigShareFlagPtr = COM_SIG;
                    }
                }
            }
            else
#endif
            {
                *(sint32*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_S32;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                {
                    DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                    if(FALSE == IsSigGrpGw)
                    {
                        Com_SendSignalGroup_Internal(DestSigGrpId);
                    }
                    else
                    {
                        if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                        {
                            Com_SendSignalGroup_Internal(DestSigGrpId);
                        }
                    }
                }
                else
#endif
                {
                    (void)Com_WriteSignal_Internal(DestSigId, &Value_S32, (PduLengthType)0);
                }
            }
        }
    }
    SchM_Exit_Com_COM_EXCLUSIVE_AREA_5();
#endif
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleRxSig_F32
*
* Description:   Rx signal copy and gateway.
*
* Inputs:        RxSigId
*                RxPduPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_F32
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    float32 Value_F32 = (uint8)0;

    Com_EndiannessType Endianness;
    uint16 BitSize;
    uint16 StartBit;
    uint64 Mask;
#if(STD_ON == COM_GW_FUN)
    Com_SignalIdType GWSigIndex;
    Com_SignalIdType DestSignalNum;
    P2CONST(Com_CfgGwTxSigTableType, AUTOMATIC, COM_CONST) DestSignalTable;
    Com_SignalIdType DestSigId;
    Com_SignalIdType DestSigIndex;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType DestSigGrpId;
    boolean IsSigGrpGw;
#endif
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
#endif
#endif

    Endianness = COM_CFG_RXSIG_ENDIANNESS(RxSigId);
    BitSize = COM_CFG_RXSIG_BIT_SIZE(RxSigId);
    StartBit = COM_CFG_RXSIG_START_BIT(RxSigId);
    Mask = COM_CFG_RXSIG_MASK(RxSigId);

    /*Copy SigValue from Pdu*/
#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleF32(&Value_F32, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigF32(&Value_F32, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleF32(&Value_F32, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigF32(&Value_F32, PduPtr, BitSize, StartBit, Mask);
#endif

    /*Copy SigValue to Buffer*/
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    if(NULL_PTR != COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId))
    {
        *(float32*)COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId) = Value_F32;
    }
    else
#endif
    {
        *(float32*)COM_CFG_RXSIG_DATA_PTR(RxSigId) = Value_F32;
    }

#if(STD_ON == COM_GW_FUN)
    /*Sig GW*/
    SchM_Enter_Com_COM_EXCLUSIVE_AREA_5();
    GWSigIndex = COM_CFG_RXSIG_GW_INDEX(RxSigId);
    if(COM_INVALID_SIG_INDEX != GWSigIndex)
    {
        DestSignalNum = COM_CFG_GW_TX_SIGNAL_NUM(GWSigIndex);
        DestSignalTable = COM_CFG_GW_TX_SIGNAL_TABLE(GWSigIndex);
        for(DestSigIndex = 0; DestSigIndex < DestSignalNum; DestSigIndex++)
        {
            DestSigId = DestSignalTable[DestSigIndex].GwTxSignalId;
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
            TxSigCoreId = COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(DestSigId));
            ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
            if(TxSigCoreId != ComLogicCoreId)
            {
                tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(DestSigId);
                if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
                {
                    /*Whether it is the same value as the old share tx buffer*/
                    if(Value_F32 ==  *(float32*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                    {
                        Com_TxSigIsSameValue[DestSigId] = TRUE;
                    }
                    else
                    {
                        Com_TxSigIsSameValue[DestSigId] = FALSE;
                        *(float32*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_F32;
                    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                    if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                    {
                        IsSigGrpGw = DestSignalTable[DestSigIndex].GwIsSigGrp;
                        if(FALSE == IsSigGrpGw)
                        {

                            *tempTxSigShareFlagPtr = COM_SIG_GRP;
                        }
                        else
                        {
                            DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                            if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                            {
                                *tempTxSigShareFlagPtr = COM_SIG_GRP;
                            }
                        }
                    }
                    else
#endif
                    {
                        *tempTxSigShareFlagPtr = COM_SIG;
                    }
                }
            }
            else
#endif
            {
                /*Whether it is the same value as the old share tx buffer*/
                if(Value_F32 ==  *(float32*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                {
                    Com_TxSigIsSameValue[DestSigId] = TRUE;
                }
                else
                {
                    Com_TxSigIsSameValue[DestSigId] = FALSE;
                    *(float32*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_F32;
                }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                {
                    DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                    if(FALSE == IsSigGrpGw)
                    {
                        Com_SendSignalGroup_Internal(DestSigGrpId);
                    }
                    else
                    {
                        if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                        {
                            Com_SendSignalGroup_Internal(DestSigGrpId);
                        }
                    }
                }
                else
#endif
                {
                    (void)Com_WriteSignal_Internal(DestSigId, &Value_F32, (PduLengthType)0);
                }
            }
        }
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_5();
    }
    SchM_Exit_Com_COM_EXCLUSIVE_AREA_5();
#endif
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleRxSig_U64
*
* Description:   Rx signal copy and gateway.
*
* Inputs:        RxSigId
*                RxPduPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_U64
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    uint64 Value_U64 = (uint8)0;

    Com_EndiannessType Endianness;
    uint16 BitSize;
    uint16 StartBit;
    uint64 Mask;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    Com_RxSigLockIndexType RxSigLockIndex = COM_CFG_RXSIG_LOCK_INDEX(RxSigId);
#endif
#if(STD_ON == COM_GW_FUN)
    Com_SignalIdType GWSigIndex;
    Com_SignalIdType DestSignalNum;
    P2CONST(Com_CfgGwTxSigTableType, AUTOMATIC, COM_CONST) DestSignalTable;
    Com_SignalIdType DestSigId;
    Com_SignalIdType DestSigIndex;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType DestSigGrpId;
    boolean IsSigGrpGw;
#endif
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
#endif
#endif

    Endianness = COM_CFG_RXSIG_ENDIANNESS(RxSigId);
    BitSize = COM_CFG_RXSIG_BIT_SIZE(RxSigId);
    StartBit = COM_CFG_RXSIG_START_BIT(RxSigId);
    Mask = COM_CFG_RXSIG_MASK(RxSigId);

    /*Copy SigValue from Pdu*/
#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleU64(&Value_U64, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigU64(&Value_U64, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleU64(&Value_U64, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigU64(&Value_U64, PduPtr, BitSize, StartBit, Mask);
#endif

    SchM_Enter_Com_COM_EXCLUSIVE_AREA_13();

    /*Copy SigValue to Buffer*/
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    if(NULL_PTR != COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId))
    {
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_GETSPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
        *(uint64*)COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId) = Value_U64;
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_RELEASESPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
    }
    else
#endif
    {
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_GETSPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
        *(uint64*)COM_CFG_RXSIG_DATA_PTR(RxSigId) = Value_U64;
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_RELEASESPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
    }

    SchM_Exit_Com_COM_EXCLUSIVE_AREA_13();

#if(STD_ON == COM_GW_FUN)
    /*Sig GW*/
    SchM_Enter_Com_COM_EXCLUSIVE_AREA_5();
    GWSigIndex = COM_CFG_RXSIG_GW_INDEX(RxSigId);
    if(COM_INVALID_SIG_INDEX != GWSigIndex)
    {
        DestSignalNum = COM_CFG_GW_TX_SIGNAL_NUM(GWSigIndex);
        DestSignalTable = COM_CFG_GW_TX_SIGNAL_TABLE(GWSigIndex);
        for(DestSigIndex = 0; DestSigIndex < DestSignalNum; DestSigIndex++)
        {
            DestSigId = DestSignalTable[DestSigIndex].GwTxSignalId;
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
            TxSigCoreId = COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(DestSigId));
            ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
            if(TxSigCoreId != ComLogicCoreId)
            {
                tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(DestSigId);
                if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
                {
                    /*Whether it is the same value as the old share tx buffer*/
                    if(Value_U64 ==  *(uint64*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                    {
                        Com_TxSigIsSameValue[DestSigId] = TRUE;
                    }
                    else
                    {
                        Com_TxSigIsSameValue[DestSigId] = FALSE;
                        *(uint64*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_U64;
                    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                    if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                    {
                        IsSigGrpGw = DestSignalTable[DestSigIndex].GwIsSigGrp;
                        if(FALSE == IsSigGrpGw)
                        {
                            *tempTxSigShareFlagPtr = COM_SIG_GRP;
                        }
                        else
                        {
                            DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                            if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                            {
                                *tempTxSigShareFlagPtr = COM_SIG_GRP;
                            }
                        }
                    }
                    else
#endif
                    {
                        *tempTxSigShareFlagPtr = COM_SIG;
                    }
                }
            }
            else
#endif
            {
                /*Whether it is the same value as the old share tx buffer*/
                if(Value_U64 ==  *(uint64*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                {
                    Com_TxSigIsSameValue[DestSigId] = TRUE;
                }
                else
                {
                    Com_TxSigIsSameValue[DestSigId] = FALSE;
                    *(uint64*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_U64;
                }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                {
                    DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                    if(FALSE == IsSigGrpGw)
                    {
                        Com_SendSignalGroup_Internal(DestSigGrpId);
                    }
                    else
                    {
                        if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                        {
                            Com_SendSignalGroup_Internal(DestSigGrpId);
                        }
                    }
                }
                else
#endif
                {
                    (void)Com_WriteSignal_Internal(DestSigId, &Value_U64, (PduLengthType)0);
                }
            }
        }
    }
    SchM_Exit_Com_COM_EXCLUSIVE_AREA_5();
#endif
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleRxSig_S64
*
* Description:   Rx signal copy and gateway.
*
* Inputs:        RxSigId
*                RxPduPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_S64
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    sint64 Value_S64 = (uint8)0;
    uint64 Value_U64 = (uint16)0;
    uint8 Lastbit = (uint8)0;
    Com_EndiannessType Endianness;
    uint16 BitSize;
    uint16 StartBit;
    uint64 Mask;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    Com_RxSigLockIndexType RxSigLockIndex = COM_CFG_RXSIG_LOCK_INDEX(RxSigId);
#endif
#if(STD_ON == COM_GW_FUN)
    Com_SignalIdType GWSigIndex;
    Com_SignalIdType DestSignalNum;
    P2CONST(Com_CfgGwTxSigTableType, AUTOMATIC, COM_CONST) DestSignalTable;
    Com_SignalIdType DestSigId;
    Com_SignalIdType DestSigIndex;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType DestSigGrpId;
    boolean IsSigGrpGw;
#endif
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
#endif
#endif

    Endianness = COM_CFG_RXSIG_ENDIANNESS(RxSigId);
    BitSize = COM_CFG_RXSIG_BIT_SIZE(RxSigId);
    StartBit = COM_CFG_RXSIG_START_BIT(RxSigId);
    Mask = COM_CFG_RXSIG_MASK(RxSigId);
    Lastbit = (uint8)(BitSize - (uint16)1);
    /*Copy SigValue from Pdu*/
#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleU64(&Value_U64, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigU64(&Value_U64, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleU64(&Value_U64, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigU64(&Value_U64, PduPtr, BitSize, StartBit, Mask);
#endif

    /*Read signed signals symbol bit need to be transferre, but not need when write signal!!!!!!!*/
    Value_S64 = Com_BusValueToPhyValue_64(Value_U64, Lastbit);

    SchM_Enter_Com_COM_EXCLUSIVE_AREA_13();

    /*Copy SigValue to Buffer*/
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    if(NULL_PTR != COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId))
    {
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_GETSPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
        *(sint64*)COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId) = Value_S64;
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_RELEASESPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
    }
    else
#endif
    {
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_GETSPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
        *(sint64*)COM_CFG_RXSIG_DATA_PTR(RxSigId) = Value_S64;
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_RELEASESPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
    }

    SchM_Exit_Com_COM_EXCLUSIVE_AREA_13();

#if(STD_ON == COM_GW_FUN)
    /*Sig GW*/
    SchM_Enter_Com_COM_EXCLUSIVE_AREA_5();
    GWSigIndex = COM_CFG_RXSIG_GW_INDEX(RxSigId);
    if(COM_INVALID_SIG_INDEX != GWSigIndex)
    {
        DestSignalNum = COM_CFG_GW_TX_SIGNAL_NUM(GWSigIndex);
        DestSignalTable = COM_CFG_GW_TX_SIGNAL_TABLE(GWSigIndex);
        for(DestSigIndex = 0; DestSigIndex < DestSignalNum; DestSigIndex++)
        {
            DestSigId = DestSignalTable[DestSigIndex].GwTxSignalId;
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
            TxSigCoreId = COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(DestSigId));
            ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
            if(TxSigCoreId != ComLogicCoreId)
            {
                tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(DestSigId);
                if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
                {
                    /*Whether it is the same value as the old share tx buffer*/
                    if(Value_S64 ==  *(sint64*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                    {
                        Com_TxSigIsSameValue[DestSigId] = TRUE;
                    }
                    else
                    {
                        Com_TxSigIsSameValue[DestSigId] = FALSE;
                        *(sint64*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_S64;
                    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                    if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                    {
                        IsSigGrpGw = DestSignalTable[DestSigIndex].GwIsSigGrp;
                        if(FALSE == IsSigGrpGw)
                        {

                            *tempTxSigShareFlagPtr = COM_SIG_GRP;
                        }
                        else
                        {
                            DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                            if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                            {
                                *tempTxSigShareFlagPtr = COM_SIG_GRP;
                            }
                        }
                    }
                    else
#endif
                    {
                        *tempTxSigShareFlagPtr = COM_SIG;
                    }
                }
            }
            else
#endif
            {
                /*Whether it is the same value as the old share tx buffer*/
                if(Value_S64 ==  *(sint64*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                {
                    Com_TxSigIsSameValue[DestSigId] = TRUE;
                }
                else
                {
                    Com_TxSigIsSameValue[DestSigId] = FALSE;
                    *(sint64*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_S64;
                }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                {
                    DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                    if(FALSE == IsSigGrpGw)
                    {
                        Com_SendSignalGroup_Internal(DestSigGrpId);
                    }
                    else
                    {
                        if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                        {
                            Com_SendSignalGroup_Internal(DestSigGrpId);
                        }
                    }
                }
                else
#endif
                {
                    (void)Com_WriteSignal_Internal(DestSigId, &Value_S64, (PduLengthType)0);
                }
            }
        }
    }
    SchM_Exit_Com_COM_EXCLUSIVE_AREA_5();
#endif
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleRxSig_F64
*
* Description:   Rx signal copy and gateway.
*
* Inputs:        RxSigId
*                RxPduPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_F64
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    float64 Value_F64 = (uint8)0;

    Com_EndiannessType Endianness;
    uint16 BitSize;
    uint16 StartBit;
    uint64 Mask;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    Com_RxSigLockIndexType RxSigLockIndex = COM_CFG_RXSIG_LOCK_INDEX(RxSigId);
#endif
#if(STD_ON == COM_GW_FUN)
    Com_SignalIdType GWSigIndex;
    Com_SignalIdType DestSignalNum;
    P2CONST(Com_CfgGwTxSigTableType, AUTOMATIC, COM_CONST) DestSignalTable;
    Com_SignalIdType DestSigId;
    Com_SignalIdType DestSigIndex;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType DestSigGrpId;
    boolean IsSigGrpGw;
#endif
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
#endif
#endif

    Endianness = COM_CFG_RXSIG_ENDIANNESS(RxSigId);
    BitSize = COM_CFG_RXSIG_BIT_SIZE(RxSigId);
    StartBit = COM_CFG_RXSIG_START_BIT(RxSigId);
    Mask = COM_CFG_RXSIG_MASK(RxSigId);

    /*Copy SigValue from Pdu*/
#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleF64(&Value_F64, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigF64(&Value_F64, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleF64(&Value_F64, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigF64(&Value_F64, PduPtr, BitSize, StartBit, Mask);
#endif

    SchM_Enter_Com_COM_EXCLUSIVE_AREA_13();
    /*Copy SigValue to Buffer*/
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    if(NULL_PTR != COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId))
    {
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_GETSPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
        *(float64*)COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId) = Value_F64;
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_RELEASESPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
    }
    else
#endif
    {
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_GETSPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
        *(float64*)COM_CFG_RXSIG_DATA_PTR(RxSigId) = Value_F64;
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_RELEASESPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
    }

    SchM_Exit_Com_COM_EXCLUSIVE_AREA_13();

#if(STD_ON == COM_GW_FUN)
    /*Sig GW*/
    SchM_Enter_Com_COM_EXCLUSIVE_AREA_5();
    GWSigIndex = COM_CFG_RXSIG_GW_INDEX(RxSigId);
    if(COM_INVALID_SIG_INDEX != GWSigIndex)
    {
        DestSignalNum = COM_CFG_GW_TX_SIGNAL_NUM(GWSigIndex);
        DestSignalTable = COM_CFG_GW_TX_SIGNAL_TABLE(GWSigIndex);
        for(DestSigIndex = 0; DestSigIndex < DestSignalNum; DestSigIndex++)
        {
            DestSigId = DestSignalTable[DestSigIndex].GwTxSignalId;
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
            TxSigCoreId = COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(DestSigId));
            ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
            if(TxSigCoreId != ComLogicCoreId)
            {
                tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(DestSigId);
                if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
                {
                    /*Whether it is the same value as the old share tx buffer*/
                    if(Value_F64 == *(float64*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                    {
                        Com_TxSigIsSameValue[DestSigId] = TRUE;
                    }
                    else
                    {
                        Com_TxSigIsSameValue[DestSigId] = FALSE;
                        *(float64*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_F64;
                    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                    if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                    {
                        IsSigGrpGw = DestSignalTable[DestSigIndex].GwIsSigGrp;
                        if(FALSE == IsSigGrpGw)
                        {
                            *tempTxSigShareFlagPtr = COM_SIG_GRP;
                        }
                        else
                        {
                            DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                            if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                            {
                                *tempTxSigShareFlagPtr = COM_SIG_GRP;
                            }
                        }
                    }
                    else
#endif
                    {
                        *tempTxSigShareFlagPtr = COM_SIG;
                    }
                }
            }
            else
#endif
            {
                /*Whether it is the same value as the old share tx buffer*/
                if(Value_F64 == *(float64*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId))
                {
                    Com_TxSigIsSameValue[DestSigId] = TRUE;
                }
                else
                {
                    Com_TxSigIsSameValue[DestSigId] = FALSE;
                    *(float64*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId) = Value_F64;
                }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                {
                    DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                    if(FALSE == IsSigGrpGw)
                    {
                        Com_SendSignalGroup_Internal(DestSigGrpId);
                    }
                    else
                    {
                        if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                        {
                            Com_SendSignalGroup_Internal(DestSigGrpId);
                        }
                    }
                }
                else
#endif
                {
                    (void)Com_WriteSignal_Internal(DestSigId, &Value_F64, (PduLengthType)0);
                }
            }
        }
    }
    SchM_Exit_Com_COM_EXCLUSIVE_AREA_5();
#endif
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleRxSig_U8N
*
* Description:   Rx signal copy and gateway.
*
* Inputs:        RxSigId
*                RxPduPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(COM_RX_SIG_MAX_ARRAY_SZIE > 0)
STATIC FUNC(void, COM_CODE) Com_HandleRxSig_U8N
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    uint8 Value_U8N[COM_RX_SIG_MAX_ARRAY_SZIE] = {(uint8)0};

    uint16 StartBit;
    PduLengthType ByteLength;
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    Com_RxSigLockIndexType RxSigLockIndex = COM_CFG_RXSIG_LOCK_INDEX(RxSigId);
#endif
#if(STD_ON == COM_GW_FUN)
    boolean IsSameValue = FALSE;
    PduLengthType ByteOffset;
    Com_SignalIdType GWSigIndex;
    Com_SignalIdType DestSignalNum;
    P2CONST(Com_CfgGwTxSigTableType, AUTOMATIC, COM_CONST) DestSignalTable;
    Com_SignalIdType DestSigId;
    Com_SignalIdType DestSigIndex;
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
    Com_SignalGroupIdType DestSigGrpId;
    boolean IsSigGrpGw;
#endif
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
    uint8 TxSigCoreId;
    uint8 ComLogicCoreId;
    uint8 ComPhyCoreId = COM_GETCOREID();
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
#endif
#endif

    ByteLength = COM_CFG_RXSIG_LENGTH(RxSigId);
    StartBit = COM_CFG_RXSIG_START_BIT(RxSigId);

    /*Copy SigValue from Pdu*/
    Com_ReadSignal_U8N(Value_U8N, PduPtr, ByteLength, StartBit);

    SchM_Enter_Com_COM_EXCLUSIVE_AREA_13();

    /*Copy SigValue to Buffer*/
#if(STD_ON == COM_RX_SIGNAL_GROUP_SUPPORT)
    if(NULL_PTR != COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId))
    {
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_GETSPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
        Bsw_MemCpy(COM_CFG_RXSIG_GROUP_TEMP_BUF(RxSigId), Value_U8N, (uint32)ByteLength);
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_RELEASESPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
    }
    else
#endif
    {
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_GETSPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
        Bsw_MemCpy(COM_CFG_RXSIG_DATA_PTR(RxSigId), Value_U8N, (uint32)ByteLength);
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_RELEASESPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
    }

    SchM_Exit_Com_COM_EXCLUSIVE_AREA_13();

#if(STD_ON == COM_GW_FUN)
    /*Sig GW*/
    SchM_Enter_Com_COM_EXCLUSIVE_AREA_5();
    GWSigIndex = COM_CFG_RXSIG_GW_INDEX(RxSigId);
    if(COM_INVALID_SIG_INDEX != GWSigIndex)
    {
        DestSignalNum = COM_CFG_GW_TX_SIGNAL_NUM(GWSigIndex);
        DestSignalTable = COM_CFG_GW_TX_SIGNAL_TABLE(GWSigIndex);
        for(DestSigIndex = 0; DestSigIndex < DestSignalNum; DestSigIndex++)
        {
            DestSigId = DestSignalTable[DestSigIndex].GwTxSignalId;
#if(STD_ON == COM_MULTI_CORE_GW_SUPPORT)
            TxSigCoreId = COM_CFG_TXPDU_CORE_ID(COM_CFG_TXSIG_TXPDU_ID(DestSigId));
            ComLogicCoreId = ComCfgCorePhyMapLogic[ComPhyCoreId];
            if(TxSigCoreId != ComLogicCoreId)
            {
                tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(DestSigId);
                if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND == *tempTxSigShareFlagPtr))
                {
                    /*Whether it is the same value as the old share tx buffer*/
                    for(ByteOffset = (PduLengthType)0; ByteOffset < ByteLength; ByteOffset++)
                    {
                        if(FALSE == Com_CheckChangeSignal_U8N(Value_U8N, (uint8*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId), ByteLength, (uint16)0))
                        {
                            IsSameValue = TRUE;
                            break;
                        }
                    }
                    if(TRUE == IsSameValue)
                    {
                        Com_TxSigIsSameValue[DestSigId] = TRUE;
                    }
                    else
                    {
                        Com_TxSigIsSameValue[DestSigId] = FALSE;
                        Bsw_MemCpy(COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId), Value_U8N, (uint32)ByteLength);
                    }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                    if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                    {
#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
                        if(COM_SIG_DYN == COM_CFG_TXSIG_TYPE(DestSigId))
                        {
                            *COM_CFG_TXSIG_GROUP_TEMPLENGTH_PTR(DestSigId) = ByteLength;
                        }
#endif
                        IsSigGrpGw = DestSignalTable[DestSigIndex].GwIsSigGrp;
                        if(FALSE == IsSigGrpGw)
                        {
                            *tempTxSigShareFlagPtr = COM_SIG_GRP;
                        }
                        else
                        {
                            DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                            if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                            {
                                *tempTxSigShareFlagPtr = COM_SIG_GRP;
                            }
                        }
                    }
                    else
#endif
                    {
                        *tempTxSigShareFlagPtr = COM_SIG;
                    }
                }
            }
            else
#endif
            {
                /*Whether it is the same value as the old share tx buffer*/
                for(ByteOffset = (PduLengthType)0; ByteOffset < ByteLength; ByteOffset++)
                {
                    if(FALSE == Com_CheckChangeSignal_U8N(Value_U8N, (uint8*)COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId), ByteLength, (uint16)0))
                    {
                        IsSameValue = TRUE;
                        break;
                    }
                }
                if(TRUE == IsSameValue)
                {
                    Com_TxSigIsSameValue[DestSigId] = TRUE;
                }
                else
                {
                    Com_TxSigIsSameValue[DestSigId] = FALSE;
                    Bsw_MemCpy(COM_CFG_TXSIG_SHARE_BUF_PTR(DestSigId), Value_U8N, (uint32)ByteLength);
                }
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
                if(TRUE == COM_CFG_TXSIG_IS_GROUP_SIGNAL(DestSigId))
                {
#if(STD_ON == COM_TX_DYN_PDU_SUPPORT)
                    if(COM_SIG_DYN == COM_CFG_TXSIG_TYPE(DestSigId))
                    {
                        *COM_CFG_TXSIG_GROUP_TEMPLENGTH_PTR(DestSigId) = ByteLength;
                    }
#endif
                    DestSigGrpId = COM_CFG_TXSIG_GET_SIGGROUPID(DestSigId);
                    if(FALSE == IsSigGrpGw)
                    {
                        Com_SendSignalGroup_Internal(DestSigGrpId);
                    }
                    else
                    {
                        if(DestSigId == COM_CFG_TXSIGGRP_SIGSTOP(DestSigGrpId))
                        {
                            Com_SendSignalGroup_Internal(DestSigGrpId);
                        }
                    }
                }
                else
#endif
                {
                    (void)Com_WriteSignal_Internal(DestSigId, Value_U8N, (PduLengthType)0);
                }
            }
        }
    }
    SchM_Exit_Com_COM_EXCLUSIVE_AREA_5();
#endif
}
#endif/*#if(COM_RX_SIG_MAX_ARRAY_SZIE > 0)*/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_HandleRxSig
*
* Description:   Rx signal copy and gateway.
*
* Inputs:        RxSigId
*                RxPduPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_HandleRxSig
(
    Com_SignalIdType RxSigId,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr
)
{
    Com_SigType SigType;

    SigType = COM_CFG_RXSIG_TYPE(RxSigId);

    switch(SigType)
    {
    case COM_SIG_U8:
    case COM_SIG_BOOLEAN:
        Com_HandleRxSig_U8(RxSigId, PduPtr);
        break;
    case COM_SIG_S8:
        Com_HandleRxSig_S8(RxSigId, PduPtr);
        break;
    case COM_SIG_U16:
        Com_HandleRxSig_U16(RxSigId, PduPtr);
        break;
    case COM_SIG_S16:
        Com_HandleRxSig_S16(RxSigId, PduPtr);
        break;
    case COM_SIG_U32:
        Com_HandleRxSig_U32(RxSigId, PduPtr);
        break;
    case COM_SIG_S32:
        Com_HandleRxSig_S32(RxSigId, PduPtr);
        break;
    case COM_SIG_F32:
        Com_HandleRxSig_F32(RxSigId, PduPtr);
        break;
    case COM_SIG_U64:
        Com_HandleRxSig_U64(RxSigId, PduPtr);
        break;
    case COM_SIG_S64:
        Com_HandleRxSig_S64(RxSigId, PduPtr);
        break;
    case COM_SIG_F64:
        Com_HandleRxSig_F64(RxSigId, PduPtr);
        break;
#if(COM_RX_SIG_MAX_ARRAY_SZIE > 0)
    case COM_SIG_U8N:
    case COM_SIG_DYN:
        Com_HandleRxSig_U8N(RxSigId, PduPtr);
        break;
#endif
    default:
        break;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_CopySignalWithOutLock
*
* Description:   Put source signal.
*
* Inputs:        SigType
*                SrcDataSize
*                SrcValuePtr
*                DestValuePtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_CopySignal
(
    P2CONST(void, AUTOMATIC, COM_CONST) SrcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) DestPtr,
    Com_SigType SigType,
    PduLengthType ByteLength,
    Com_SignalIdType SignalId
)
{
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
    Com_RxSigLockIndexType RxSigLockIndex = COM_CFG_RXSIG_LOCK_INDEX(SignalId);
#endif
    switch(SigType)
    {
    case COM_SIG_U8:
        *(uint8*)DestPtr = *(const uint8*)SrcPtr;
        break;
    case COM_SIG_S8:
        *(sint8*)DestPtr = *(const sint8*)SrcPtr;
        break;
    case COM_SIG_BOOLEAN:
        *(boolean*)DestPtr = *(const boolean*)SrcPtr;
        break;
    case COM_SIG_U16:
        *(uint16*)DestPtr = *(const uint16*)SrcPtr;
        break;
    case COM_SIG_S16:
        *(sint16*)DestPtr = *(const sint16*)SrcPtr;
        break;
    case COM_SIG_U32:
        *(uint32*)DestPtr = *(const uint32*)SrcPtr;
        break;
    case COM_SIG_S32:
        *(sint32*)DestPtr = *(const sint32*)SrcPtr;
        break;
    case COM_SIG_F32:
        *(float32*)DestPtr = *(const float32*)SrcPtr;
        break;

    case COM_SIG_U64:
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_13();
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_GETSPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
        *(uint64*)DestPtr = *(const uint64*)SrcPtr;
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_RELEASESPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_13();
        break;

    case COM_SIG_S64:
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_13();
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_GETSPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
        *(sint64*)DestPtr = *(const sint64*)SrcPtr;
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_RELEASESPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_13();
        break;

    case COM_SIG_F64:
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_13();
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_GETSPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
        *(float64*)DestPtr = *(const float64*)SrcPtr;
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_RELEASESPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_13();
        break;

    case COM_SIG_U8N:
    case COM_SIG_DYN:
        SchM_Enter_Com_COM_EXCLUSIVE_AREA_13();
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_GETSPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
        Bsw_MemCpy((uint8 *)DestPtr, (const uint8 *)SrcPtr, (uint32)ByteLength);
#if((STD_ON == COM_MULTI_CORE_SUPPORT)&&(0 < COM_RX_SIG_LONG_DATA_NUM))
        COM_RELEASESPINLOCK(&(Rte_Com_SpinLock_RxSigLongData[RxSigLockIndex]));
#endif
        SchM_Exit_Com_COM_EXCLUSIVE_AREA_13();
        break;
    default:
        break;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Com_CrossCoreTxSignalsTack
*
* Description:   Send signal handle.
*
* Inputs:        ComCurrentCoreId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_MULTI_CORE_SUPPORT)
STATIC FUNC(void, COM_CODE) Com_CrossCoreTxSignalsTack
(
    PduIdType TxSigPduId
)
{
    Com_SignalIdType TxSigId;
    Com_SignalGroupIdType TxSigGroupId;
    P2VAR(Com_TxSigSendModeType, AUTOMATIC, COM_VAR) tempTxSigShareFlagPtr = NULL_PTR;
    Com_SignalIdType TxSigNumber = COM_CFG_TXPDU_SIG_STOP_NUM(TxSigPduId);


    for(TxSigId = COM_CFG_TXPDU_SIG_START_NUM(TxSigPduId); TxSigId <= TxSigNumber; TxSigId++)
    {
        tempTxSigShareFlagPtr = COM_CFG_TXSIG_SHARE_FLAG_PTR(TxSigId);
        if((tempTxSigShareFlagPtr != NULL_PTR) && (COM_NO_SEND != *tempTxSigShareFlagPtr))
        {
#if(STD_ON == COM_TX_SIGNAL_GROUP_SUPPORT)
            if(COM_SIG_GRP == *tempTxSigShareFlagPtr)
            {
                TxSigGroupId = COM_CFG_TXSIG_GET_SIGGROUPID(TxSigId);
                Com_SendSignalGroup_Internal(TxSigGroupId);
                TxSigId = COM_CFG_TXSIGGRP_SIGSTOP(TxSigGroupId);
            }
#if(STD_ON == COM_TX_INVALID_SUPPORT)
            else if(COM_SIG_GRP_INV == *tempTxSigShareFlagPtr)
            {
                TxSigGroupId = COM_CFG_TXSIG_GET_SIGGROUPID(TxSigId);
                Com_InvalidateSignalGroup_Internal(TxSigGroupId);
                TxSigId = COM_CFG_TXSIGGRP_SIGSTOP(TxSigGroupId);
            }
#endif
#if(STD_ON == COM_Enable_SignalGroupArrayApi)
            else if(COM_SIG_GRP_ARRAY == *tempTxSigShareFlagPtr)
            {
                TxSigGroupId = COM_CFG_TXSIG_GET_SIGGROUPID(TxSigId);
                Com_SendSignalGroupArray_Internal(TxSigGroupId, COM_CFG_TXSIG_GRP_SHARE_BUF_PTR(TxSigGroupId));
                TxSigId = COM_CFG_TXSIGGRP_SIGSTOP(TxSigGroupId);
            }
#endif
            else
#endif
            {
                Com_WriteSignal_Internal(TxSigId, COM_CFG_TXSIG_SHARE_BUF_PTR(TxSigId), COM_CFG_TXSIG_LENGTH(TxSigId));
            }
            *tempTxSigShareFlagPtr = COM_NO_SEND;
        }
    }
}
#endif

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"





