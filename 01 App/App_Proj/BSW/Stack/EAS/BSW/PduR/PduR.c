/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : PduR.c
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : PduR.c
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of PDUR
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   04.00.00    08/03/2023    Wenbo.Cui       N/A          Beta
*   04.00.03    19/06/2024    chaolimen.Han   N/A          QAC
********************************************************************************
* END_FILE_HDR*/

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

/*PRQA S 3111,2213,3131,3211,0914,3120 EOF*/
/*
Source file does not end with a newline character.

Extra comma is allowed at the end of arrays in configuration files.
{} is allowed to be in the same line in arrays of configuration files.
The length of arrays in configuration files can be a constant.
Variables defined in configuration files can be used in the core file instead of this file .
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
 *  PduR QAC Suppression
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

/*PRQA S 3206,3220,2741 EOF*/
/*
Particularity of configuration files
*/

/*PRQA S 3218 EOF*/
/*
Allow static variables that are only used once
*/

/*PRQA S 4570 EOF*/
/*
Permission ~ operator, specific implementation methods.
*/

/*PRQA S 3383 EOF*/
/*
Addition and subtraction operations on internal variables of PduR doesn't overflow.
*/

/*PRQA S 3435,3456 EOF*/
/*
Allow multiple use parameters in macros
*/
/*PRQA S 0488 EOF*/
/*

*/
/*PRQA S 2905 EOF*/
/*
The meaning of PDUR_BUFFER_NO_PATH and PDUR_UNUSED are the max value of PduIdType, PduIdType generate uint8
or uint16 based on configuration.
*/

/*PRQA S 2844,2814,2824 EOF*/
/*
All array input elements are with in their length.
Null pointer checks performed when retrieving data from Pointers.
*/

/*PRQA S 1503 EOF*/
/*
Function declared externally are called by the user.
Variable declared externally are used by the user.
*/

/*PRQA S 2880,2877,2995,2889,2976 EOF*/
/*
An internal statement is executed only when the configuration meets the if condition.
Depends on configuration.
Multiple return are allowed.
*/
/*PRQA S 791,792 EOF*/
/*
Relevant names of macros may not follow relevant naming rules,
for example: PDUR_CROSSCORE_TX_IDLE
*/
/*PRQA S 2841, 2842,2843,4700 EOF*/
/*
Relevant expression will not exceed the bounds of Relevant array.
*/
/*PRQA S 1272 EOF*/
/*
There is no redundant leading zeros on the constant PDUR_BUFFER_FULL.
*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "PduR.h"
#include "SchM_PduR.h"
#include "Bsw_Common.h"
#ifdef MODULE_COM
#include "Com.h"
#endif
#if(STD_ON == PDUR_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#if (STD_ON == PDUR_TEST_ENABLE)
#include "CanIf.h"
#endif

/*******************************************************************************
*   Version Check
*******************************************************************************/
/*ComM0136 */
#if(STD_ON == PDUR_VERSION_CHECK)
/* check Version with other import module */

/* check Version with cfg file */
#if ((PDUR_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) && \
    (PDUR_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD))
#error "The PduR module only supports Pre-Compile and Post-Build Configuration."
#endif

#if ((PDUR_AR_RELEASE_MAJOR_VERSION != PDUR_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (PDUR_AR_RELEASE_MINOR_VERSION != PDUR_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of PduR and its cfg file are incompatible"
#endif

#if ((PDUR_SW_MAJOR_VERSION != PDUR_SW_MAJOR_VERSION_CFG) || \
   (PDUR_SW_MINOR_VERSION != PDUR_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of PduR and its cfg file are incompatible"
#endif
#endif/*#if(STD_ON == PDUR_VERSION_CHECK)*/

/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == PDUR_DEV_ERROR_DETECT)

#define  PDUR_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(PDUR_MODULE_ID, PDUR_INSTANCE_ID, ((uint8)ApiId), ((uint8)errcode))

#else

#define  PDUR_DET_REPORT_ERROR(ApiId, errcode)

#endif

#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
/*PDUR Dest dedicated Buffer State */
#define PDUR_BUFFER_IDLE                   ((uint8)0x00)
#define PDUR_BUFFER_TRANSMITING            ((uint8)0x01)
#define PDUR_BUFFER_RECEIVING              ((uint8)0x02)
#define PDUR_BUFFER_GW_FLYING              ((uint8)0x04)
#define PDUR_BUFFER_WAIT_TXCONFIRM         ((uint8)0x08)
#endif

#define PDUR_CROSSCORE_TX_IDLE              ((uint8)0x00)
#define PDUR_CROSSCORE_TX_UP_TRANSMITTING    ((uint8)0x01)
#define PDUR_CROSSCORE_TX_WAIT_LO_TRANSMIT  ((uint8)0x02)
#define PDUR_CROSSCORE_TX_LO_TRANSMITTING   ((uint8)0x04)
#define PDUR_CROSSCORE_TX_WAIT_TX_CONFIRM_OK   ((uint8)0x08)
#define PDUR_CROSSCORE_TX_WAIT_TX_CONFIRM_NOT_OK   ((uint8)0x10)
#define PDUR_CROSSCORE_TX_WAIT_CANCEL_TRANSMIT   ((uint8)0x20)

#define PDUR_CROSSCORE_RX_IDLE              ((uint8)0x00)
#define PDUR_CROSSCORE_RX_LO_RECEIVING    ((uint8)0x01)
#define PDUR_CROSSCORE_RX_WAIT_UP_RECEIVE  ((uint8)0x02)
#define PDUR_CROSSCORE_RX_UP_RECEIVING   ((uint8)0x04)
#define PDUR_CROSSCORE_RX_WAIT_RX_INDICATION_OK   ((uint8)0x08)
#define PDUR_CROSSCORE_RX_WAIT_RX_INDICATION_NOT_OK   ((uint8)0x10)

#define PDUR_BUFFER_FULL                 ((uint64)0xFFFFFFFFFFFFFFFF)

#if(PDUR_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_PRECOMPILE)
#define PDUR_GET_NUM_ROUTPATH()                     ((PduR_RoutingPathIdType)PDUR_NUMPDURROUTPATH)
#define PDUR_GET_NUM_ROUTPATHGROUP()                ((PduR_RoutingPathGroupIdType)PDUR_NUMOFROUTINGPATHGROUP)
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
#define PDUR_GET_NUM_BUFFER()                       ((PduR_BufferIdType)PDUR_NUMOFBUFFER)
#endif


#define PDUR_ROUTINGPATHINFO(PathId)                (PduRRoutingTable[PathId])
#define PDUR_GET_RPGROUP_ENABLED_ATINIT(GroupId)    (PduR_RPGroupEnabledAtInit[GroupId])

#if(PDUR_MAX_TX_PDU_INFO > 0)
#define PDUR_TX_PDU_INFO_PTR(PduId)                 (PduRTxPduInfo[PduId])
#endif
#if(PDUR_MAX_RX_PDU_INFO > 0)
#define PDUR_RX_PDU_INFO_PTR(PduId)                 (PduRRxPduInfo[PduId])
#endif
#if(PDUR_MAX_TXCONF_PDU > 0)
#define PDUR_TX_CONF_PDU_INFO_PTR(PduId)            (PduRTxConfPduInfo[PduId])
#endif
#if(PDUR_MAX_CANCELRX_PDU > 0)
#define PDUR_RX_CANCEL_PDU_INFO_PTR(PduId)          (PduRCancelRxPduInfo[PduId])
#endif

#if(PDUR_PDU_BUFFER_SUPPORT == STD_ON)
#define PDUR_BUFFER_PTR(BufferId)                   (PduR_Cfg_Buffer[BufferId])
#define PDUR_BUFFER_LEN(BufferId)                   (PduR_Cfg_Buffer[BufferId].BufferLen) 
#define PDUR_BUFFER_PDUPTR(BufferId, Deep, Pos)     ((PduR_Cfg_Buffer[BufferId].PduPtr)\
                                                    + (PDUR_BUFFER_LEN(BufferId) * Deep) + (Pos))
#define PDUR_BUFFER_INFO(BufferId,Deep)             (PduR_Cfg_Buffer[BufferId].BufferInfo[Deep])
#define PDUR_BUFFER_DEPTH(BufferId)                 (PduR_Cfg_Buffer[BufferId].DeepLen)
#if(PDUR_MULTICORE_SUPPORT == STD_ON)
#define PDUR_BUFFER_FLAG_PTR(BufferId,DeepIndex)              (&PduR_Cfg_Buffer[BufferId].BufferInfo[DeepIndex].PduFlag)
#define PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId)                  (&PduRBufferQueueInfo[BufferId].QueueInfoFlag)
#endif
#endif

#else
#define PDUR_GET_NUM_ROUTPATH()                     (PduR_ConfigSet->RoutingPathNum)
#define PDUR_GET_NUM_ROUTPATHGROUP()                (PduR_ConfigSet->RoutingPathGroupNum)
#define PDUR_MAX_TX_PDU_INFO_NUM                    (PduR_ConfigSet->TxPduInfoNum)
#define PDUR_MAX_RX_PDU_INFO_NUM                    (PduR_ConfigSet->RxPduInfoNum)
#define PDUR_MAX_TXCONF_PDU_NUM                     (PduR_ConfigSet->TxPduTxConfNum)
#define PDUR_MAX_CANCELRX_PDU_NUM                   (PduR_ConfigSet->RxPduCancleNum)
#define PDUR_ROUTINGPATHINFO(PathId)                (PduR_ConfigSet->pRoutingTbl[PathId])
#define PDUR_GET_RPGROUP_ENABLED_ATINIT(GroupId)    (PduR_ConfigSet->RPGroupEnabledAtInit[GroupId])
#define PDUR_TX_PDU_INFO_PTR(PduId)                 (PduR_ConfigSet->TxPduInfo[PduId])
#define PDUR_RX_PDU_INFO_PTR(PduId)                 (PduR_ConfigSet->RxPduInfo[PduId])
#define PDUR_RX_CANCEL_PDU_INFO_PTR(PduId)          (PduR_ConfigSet->CancelRxPduInfo[PduId])
#define PDUR_TX_CONF_PDU_INFO_PTR(PduId)            (PduR_ConfigSet->TxConfPduInfo[PduId])
#if(PDUR_PDU_BUFFER_SUPPORT == STD_ON)            
#define PDUR_BUFFER_PTR(i)                          (PduR_ConfigSet->Buffer[i])
#define PDUR_BUFFER_PDUPTR(BufferId, Deep, Pos)     ((PduR_ConfigSet->Buffer[BufferId].PduPtr)\
                                                    + (PDUR_BUFFER_LEN(BufferId) * Deep) + (Pos))
#define PDUR_BUFFER_INFO(BufferId,Deep)             (PduR_ConfigSet->Buffer[BufferId].BufferInfo[Deep])
#define PDUR_BUFFER_DEPTH(BufferId)                 (PduR_ConfigSet->Buffer[BufferId].DeepLen)
#define PDUR_BUFFER_LEN(BufferId)                   (PduR_ConfigSet->Buffer[BufferId].BufferLen)
#define PDUR_GET_NUM_BUFFER()                       (PduR_ConfigSet->BufferNum)
#endif
#endif

/*Initialization status*/
#define PDUR_IS_INITIALIZED()                       (PDUR_ONLINE == PduR_InitStatus)
#define PDUR_SET_INITIALIZED()                      (PduR_InitStatus = PDUR_ONLINE)
#define PDUR_SET_UNINITIALIZED()                    (PduR_InitStatus = PDUR_UNINIT)

/*******************************************************************************
*   Local Data Define
*******************************************************************************/
#define PDUR_START_SEC_VAR_INIT_GLOBAL_8
#include "PduR_MemMap.h"
/*PDUR global state*/
/*SWS_PduR_00325*/
STATIC VAR(PduR_StateType, PDUR_VAR) PduR_InitStatus = PDUR_UNINIT;

#if(PDUR_MAX_TX_PDU_INFO > 0)
STATIC VAR(uint8, PDUR_VAR) PduR_FanOutConunt[PDUR_MAX_TX_PDU_INFO] = {0};
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) TxConfMask[PDUR_MAX_TX_PDU_INFO] = {0};
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) TxErrorMask[PDUR_MAX_TX_PDU_INFO] = {0};
#endif/*#if(PDUR_MAX_TX_PDU_INFO > 0)*/

STATIC VAR(boolean, PDUR_VAR) PduR_RoutingPathEnbale[PDUR_MAX_NUMPDURROUTPATH];
STATIC VAR(boolean, PDUR_VAR) PduR_RoutingPathGroupEnabled[PDUR_MAX_NUMOFROUTINGPATHGROUP];

#if(PDUR_MAX_RX_PDU_INFO > 0)
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) RxErrorMask[PDUR_MAX_RX_PDU_INFO] = {0};
STATIC VAR(PduR_MulticastMaskType, PDUR_VAR) RxStartOfReceptionErrorMask[PDUR_MAX_RX_PDU_INFO] = {0};
#endif/*#if(PDUR_MAX_RX_PDU_INFO > 0)*/

#define PDUR_STOP_SEC_VAR_INIT_GLOBAL_8
#include "PduR_MemMap.h"


#define PDUR_START_SEC_VAR_CLEARED_GLOBAL_16
#include "PduR_MemMap.h"

#if(PDUR_MAX_TX_PDU_INFO > 0)
STATIC VAR(PduLengthType, PDUR_VAR) PduR_TpTxAvailableLength[PDUR_MAX_TX_PDU_INFO];
#endif/*#if(PDUR_MAX_TX_PDU_INFO > 0)*/

#define PDUR_STOP_SEC_VAR_CLEARED_GLOBAL_16
#include "PduR_MemMap.h"


#define PDUR_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "PduR_MemMap.h"

#if(PDUR_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
STATIC P2CONST(PduR_PBConfigType, PDUR_VAR_NOINIT, PDUR_CONST) PduR_ConfigSet;
#endif

#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
STATIC VAR(PduRBufferQueueInfoType, PDUR_VAR) PduRBufferQueueInfo[PDUR_MAX_NUMOFBUFFER];
#endif

#define PDUR_STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "PduR_MemMap.h"

/*******************************************************************************
*   Test Variable define
*******************************************************************************/
#if(STD_ON == PDUR_TEST_ENABLE)
#define PDUR_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "PduR_MemMap.h"

uint8 ErrorCount = 0;
PduR_ErrorInfoType ErrorInfo[20];

#define PDUR_STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "PduR_MemMap.h"
#endif
/*******************************************************************************
*   Local Functions define
*******************************************************************************/
#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
STATIC FUNC(void, PDUR_CODE) PduR_BufferInit
(
    PduR_BufferIdType BufferId,
    uint16 DeepIndex
);

STATIC FUNC(void, PDUR_CODE) PduR_UpdateFIFOInfo
(
    PduR_BufferIdType BufferId,
    boolean IsInsert
);

STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_InsertQueue
(
    CONST(PduR_BufferIdType, PDUR_CONST) BufferId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    CONST(PduLengthType, PDUR_CONST) CopySduLength
);

STATIC FUNC(boolean, PDUR_CODE) PduR_MatchPos
(
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId,
    CONST(PduR_BufferIdType, PDUR_CONST) BufferId
);

STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_ExportQueue
(
    PduR_BufferIdType BufferId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_VAR) PduInfoPtr,
    PduLengthType CopyLength

);

#if(STD_ON == PDUR_GW_IF_SUPPORT)
STATIC FUNC(void, PDUR_CODE) PduR_IfModuleGwTrigger
(
    PduR_BufferIdType BufferId,
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);

STATIC FUNC(void, PDUR_CODE) PduR_IfModuleDirect
(
    PduR_BufferIdType BufferId,
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);
#endif /*#if(STD_ON == PDUR_GW_IF_SUPPORT)*/

#if(PDUR_MAX_RX_PDU_INFO > 0)
#if(STD_ON == PDUR_GW_TP_SUPPORT)
STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_TpGWStartOfReception
(
    PduR_BufferIdType BufferId,
    PduR_RoutingPathIdType PathId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);
STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_TpGWCopyRxData
(
    PduR_BufferIdType BufferId,
    PduR_RoutingPathIdType PathId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

STATIC FUNC(void, PDUR_CODE) PduR_BufferRelease
(
    PduR_RoutingPathIdType PathId, 
    PduR_BufferIdType BufferId, 
    PduLengthType DeepIndex
);

STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_BufferAllocate
(
    PduR_RoutingPathIdType PathId, 
    PduR_BufferIdType BufferId, 
    PduLengthType DeepIndex,
    PduLengthType Length
);
#endif /*#if(STD_ON == PDUR_GW_TP_SUPPORT)*/
#endif /*#if(PDUR_MAX_RX_PDU_INFO > 0)*/

#endif /*#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)*/

#if(PDUR_MAX_RX_PDU_INFO > 0)
STATIC FUNC(void, PDUR_CODE) PduR_LowerIfRxIndication
(
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);
#endif

#if(PDUR_MAX_TXCONF_PDU > 0)
STATIC FUNC(void, PDUR_CODE) PduR_LowerIfTxConfirmation
(
    PduR_RoutingPathIdType PathId,
    PduIdType ConfId,
    Std_ReturnType results
);

STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_LowerIfTriggerTransmit
(
    PduR_RoutingPathIdType PathId,
    PduIdType ConfId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);
#endif
#if(PDUR_MAX_RX_PDU_INFO > 0)
STATIC FUNC(void, PDUR_CODE) PduR_LowerIfMultiRxIndication
(
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);
#endif
#if(PDUR_MAX_TX_PDU_INFO > 0)
STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_UpTransmit
(
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info
);
#endif
#if(PDUR_MAX_TX_PDU_INFO > 0 || STD_ON == PDUR_GW_TP_SUPPORT)
STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_UpCancelTransmit
(
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId
);
#endif

#if(PDUR_MAX_CANCELRX_PDU > 0)
STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_UpCancelReceive
(
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId
);
#endif

#if(PDUR_MAX_RX_PDU_INFO > 0)
STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LowerTpStartOfReception
(
    PduR_RoutingPathIdType PathId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LowerTpCopyRxData
(
    PduR_RoutingPathIdType PathId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

STATIC FUNC(void, PDUR_CODE) PduR_LowerTpRxIndication
(
    PduR_RoutingPathIdType PathId,
    Std_ReturnType result
);
#endif
STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LowerTpCopyTxData
(
    PduR_RoutingPathIdType PathId,
    PduIdType ConfId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
);

STATIC FUNC(void, PDUR_CODE) PduR_LowerTpTxConfirmation
(
    PduR_RoutingPathIdType PathId,
    PduIdType ConfId,
    Std_ReturnType Result
);
#if(PDUR_MAX_RX_PDU_INFO > 0)
STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LowerTpMultiStartOfReception
(
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LowerTpMultiCopyRxData
(
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
);

STATIC FUNC(void, PDUR_CODE) PduR_LowerTpMultiRxIndication
(
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo,
    Std_ReturnType result
);
#endif


#if(STD_ON == PDUR_DEV_ERROR_DETECT)
STATIC FUNC(void, PDUR_CODE) PduR_TxCompatibilityCheck
(
    void
);

STATIC FUNC(void, PDUR_CODE) PduR_RxCompatibilityCheck
(
    void
);
#endif

STATIC FUNC(void, PDUR_CODE) PduR_SwitchRountingPath
(
    void
);

#if(STD_ON == PDUR_TEST_ENABLE)

void PduR_SendErrorInfo()
{
    uint8 ErrorPdu[64] = {0};
    PduInfoType ErrorPduInfo;
    ErrorPdu[0] = ErrorInfo[ErrorCount].ErrorType;
    ErrorPdu[1] = (uint8)ErrorInfo[ErrorCount].ErrorBufferId;
    ErrorPdu[2] =  (uint8)ErrorInfo[ErrorCount].ErrorBufferQueueInfo.RearPos;
    ErrorPdu[3] =  (uint8)ErrorInfo[ErrorCount].ErrorBufferQueueInfo.FrontPos;
    ErrorPdu[4] =  (uint8)ErrorInfo[ErrorCount].ErrorBufferQueueInfo.QueueAvailableLen;
    ErrorPdu[5] =  (uint8)ErrorInfo[ErrorCount].ErrorBufferInfo.AllocatedBufferPool;
    ErrorPdu[6] =  (uint8)ErrorInfo[ErrorCount].ErrorBufferInfo.AllocatedBufferIndex;
    ErrorPdu[7] =  (uint8)ErrorInfo[ErrorCount].ErrorBufferInfo.BufState;
    Bsw_MemCpy(&(ErrorPdu[8]), ErrorInfo[ErrorCount].PduContent, 5);
    ErrorPduInfo.SduDataPtr = (SduDataPtrType)ErrorPdu;
    ErrorPduInfo.SduLength = 64;
    CanIf_Transmit(84, &ErrorPduInfo);
};

#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_BufferAllocate
*
* Description:     This function is called to allocate a dynamic buffer
*
* Inputs:          PathId   : The Path Index
*                  BufferId : The Index of the buffer.
*                  DeepIndex: The deep index of the buffer.
*
* Outputs:         result:  : The result of the allocation 
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/

#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_BufferAllocate
(
    PduR_RoutingPathIdType PathId, 
    PduR_BufferIdType BufferId, 
    PduLengthType DeepIndex,
    PduLengthType Length
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    uint8 i;

    uint8 BufferPoolIndex = (uint8)0xFF;
    uint64 Mask;
    uint64 BufferInUseSize;
    uint8 BufferInUseIndex;
    PduLengthType BufferLength;
    uint8 BufferAllocateSuccess = (uint8)0;
    uint8 BufferPoolAvaliable = (uint8)0;
    const BufferPoolType* BufferPoolSet;
    uint8 NumBufferPool = (uint8)0xFF;
    uint32 TempOffset;
    if(PDUR_BUFFER_PTR(BufferId).BufferLen !=  (PduLengthType)0)
    {
        BufferLength = PDUR_BUFFER_PTR(BufferId).BufferLen;
    }
    else
    {
        BufferLength = Length;
    }

    for(i = (uint8)0; i < (uint8)PDUR_MAX_CORE_NUM ; i++)
    {
        if(PduR_AllBufferPoolSet[i].CoreId == PDUR_GET_CORE_ID())
        {
            BufferPoolSet = PduR_AllBufferPoolSet[i].BufferPoolSet;
            NumBufferPool = PduR_AllBufferPoolSet[i].NumOfBufferPool;
            break;
        }

    }



    for (i = (uint8)0; i < NumBufferPool; i++)
    {
        /*PRQA S 2962 ++*/
        /*
        BufferPoolSet is always initialized
        */
        if(BufferLength <= BufferPoolSet[i].BufferSize)
        {
            BufferInUseSize = (BufferPoolSet[i].PoolSize-(uint64)1);
            BufferInUseSize = BufferInUseSize/(uint64)64;
            BufferInUseSize = BufferInUseSize + (uint64)1;
            for(BufferInUseIndex = (uint8)0; BufferInUseIndex < BufferInUseSize; BufferInUseIndex++)
            {
                /*PRQA S 0580 ++*/
                /*
                Constant  PDUR_BUFFER_FULL can be represented by uint64
                */
                if(BufferPoolSet[i].BufferInUse[BufferInUseIndex] != PDUR_BUFFER_FULL)
                {

                    BufferPoolAvaliable = (uint8)1;
                    break;
                }
                /*PRQA S 0580 --*/
            }

            if(BufferPoolAvaliable == (uint8)1)
            {
                BufferPoolIndex = i;
                break;
            }
        }
        /*PRQA S 2962 --*/
    }

    if(BufferPoolIndex != (uint8)0xFF)
    {
        BufferInUseSize = (BufferPoolSet[BufferPoolIndex].PoolSize-(uint64)1);
        BufferInUseSize = BufferInUseSize/(uint64)64;
        BufferInUseSize = BufferInUseSize+(uint64)1;

        for(BufferInUseIndex =  (uint8)0; BufferInUseIndex < BufferInUseSize; BufferInUseIndex++)
        {
            /*PRQA S 0580 ++*/
            /*
            Constant  PDUR_BUFFER_FULL can be represented by uint64
            */
            if(BufferPoolSet[BufferPoolIndex].BufferInUse[BufferInUseIndex] == PDUR_BUFFER_FULL)
            {

            }
            /*PRQA S 0580 --*/
            else if(BufferAllocateSuccess == (uint8)0)
            {
                for (i = (uint8)0; i<BufferPoolSet[BufferPoolIndex].PoolSize; i++)
                {
                    Mask = (uint64)1<<i;
                    if((uint64)0 == (BufferPoolSet[BufferPoolIndex].BufferInUse[BufferInUseIndex] & Mask))
                    {
                        result = BUFREQ_OK;
                        BufferPoolSet[BufferPoolIndex].BufferInUse[BufferInUseIndex]|= ((uint64)1<<i);
                        TempOffset = (uint32)BufferInUseIndex*(uint32)64;
                        TempOffset = (uint32)(TempOffset + i);
                        TempOffset = (uint32)(TempOffset*BufferPoolSet[BufferPoolIndex].BufferSize);
                        (PduR_Cfg_Buffer[BufferId].PduPtr[DeepIndex]) = (uint8*)(&BufferPoolSet[BufferPoolIndex].BufferPool[0] + TempOffset);
                        PDUR_BUFFER_INFO(BufferId, DeepIndex).AllocatedBufferIndex = (uint8)(BufferInUseIndex*(uint8)64);
                        PDUR_BUFFER_INFO(BufferId, DeepIndex).AllocatedBufferIndex = PDUR_BUFFER_INFO(BufferId, DeepIndex).AllocatedBufferIndex+i;
                        PDUR_BUFFER_INFO(BufferId, DeepIndex).AllocatedBufferPool = BufferPoolIndex;
                        PDUR_BUFFER_INFO(BufferId, DeepIndex).AllocatedBufferLen = (PduLengthType)BufferPoolSet[BufferPoolIndex].BufferSize;
                        PDUR_BUFFER_INFO(BufferId, DeepIndex).AvailableLen = (PduLengthType)BufferPoolSet[BufferPoolIndex].BufferSize;
                        BufferAllocateSuccess = (uint8)1;
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        /*do nothing*/
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_BufferAllocate
*
* Description:     This function is called to released an allocated dynamic buffer
*
* Inputs:          PathId   : The Path Index
*                  BufferId : The Index of the buffer.
*                  DeepIndex: The deep index of the buffer.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, PDUR_CODE) PduR_BufferRelease
(
    PduR_RoutingPathIdType PathId, 
    PduR_BufferIdType BufferId, 
    PduLengthType DeepIndex
)
{
    uint8 i;
    const BufferPoolType* BufferPoolSet;
    uint8 BufferPoolIndex;
    uint8 AllocatedBufferIndex;
    uint8 temp;
    uint8 BufferInUseIndex;
    for(i = (uint8)0; i < (uint8)PDUR_MAX_CORE_NUM ; i++)
    {
        if(PduR_AllBufferPoolSet[i].CoreId == PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduCore)
        {
            BufferPoolSet = PduR_AllBufferPoolSet[i].BufferPoolSet;
            break;
        }
    }

    BufferPoolIndex = PDUR_BUFFER_INFO(BufferId, DeepIndex).AllocatedBufferPool;
    AllocatedBufferIndex =  PDUR_BUFFER_INFO(BufferId, DeepIndex).AllocatedBufferIndex;
    BufferInUseIndex = AllocatedBufferIndex/(uint8)64;
    temp = BufferInUseIndex*(uint8)64;
    AllocatedBufferIndex = AllocatedBufferIndex - temp;
    /*PRQA S 2962 ++*/
    /*
    BufferPoolSet is always initialized
    */
    BufferPoolSet[BufferPoolIndex].BufferInUse[BufferInUseIndex]&= ~((uint64)1<<AllocatedBufferIndex);
    /*PRQA S 2962 --*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_BufferInit
*
* Description:     Init the dedicated buffer
*
* Inputs:          BufferId : The number of the buffer.
*                  DeepIndex: The number of the buffer deep.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, PDUR_CODE) PduR_BufferInit
(
    PduR_BufferIdType BufferId,
    uint16 DeepIndex
)
{
    PduR_Cfg_Buffer[BufferId].PduPtr[DeepIndex] = NULL_PTR;
    PDUR_BUFFER_INFO(BufferId,DeepIndex).ValidLen = (PduLengthType)0;
    PDUR_BUFFER_INFO(BufferId,DeepIndex).ReceivedLen = (PduLengthType)0;
    if(PDUR_BUFFER_LEN(BufferId) != (PduLengthType)0)
    {
        PDUR_BUFFER_INFO(BufferId,DeepIndex).AvailableLen = PDUR_BUFFER_LEN(BufferId);
    }
    else
    {
        PDUR_BUFFER_INFO(BufferId,DeepIndex).AvailableLen = (PduLengthType)PDUR_MAX_BUFFER_SIZE;
    }

    PDUR_BUFFER_INFO(BufferId,DeepIndex).WritePos = (PduLengthType)0;
    PDUR_BUFFER_INFO(BufferId,DeepIndex).ReadPos = (PduLengthType)0;
    PDUR_BUFFER_INFO(BufferId,DeepIndex).BufState = PDUR_BUFFER_IDLE;
    PDUR_BUFFER_INFO(BufferId,DeepIndex).TotalLen = (PduLengthType)0;
    PDUR_BUFFER_INFO(BufferId,DeepIndex).AllocatedBufferIndex = (uint8)0xFF;
    PDUR_BUFFER_INFO(BufferId,DeepIndex).AllocatedBufferPool = (uint8)0xFF;
    PDUR_BUFFER_INFO(BufferId,DeepIndex).AllocatedBufferLen = (PduLengthType)0;
    PDUR_BUFFER_INFO(BufferId,DeepIndex).RxFail = (uint8)0;

    /*PRQA S 2905 ++*/
    /*
    The meaning of PDUR_BUFFER_NO_PATH is the max value of PduIdType, PduIdType generate uint8
    or uint16 based on configuration.
    */
    PDUR_BUFFER_INFO(BufferId,DeepIndex).PathIdx = PDUR_BUFFER_NO_PATH;
    /*PRQA S 2905 --*/
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
    PDUR_BUFFER_INFO(BufferId,DeepIndex).TxAllowFlag = FALSE;
    PDUR_BUFFER_INFO(BufferId,DeepIndex).UpTpTransmit = PDUR_CROSSCORE_TX_IDLE;
    PDUR_BUFFER_INFO(BufferId,DeepIndex).UpTpReceive = PDUR_CROSSCORE_RX_IDLE;
    PDUR_BUFFER_INFO(BufferId,DeepIndex).UpIfTransmit = PDUR_CROSSCORE_TX_IDLE;
#endif

#if(STD_ON == PDUR_METADATA_SUPPORT)
    PDUR_BUFFER_INFO(BufferId, DeepIndex).IsStore = FALSE;
#endif

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_UpdateFIFOInfo
*
* Description:     Init the dedicated buffer
*
* Inputs:          BufferId : The number of the buffer.
*                  IsInsert : Is it inserted into the buffer.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, PDUR_CODE) PduR_UpdateFIFOInfo
(
    PduR_BufferIdType BufferId,
    boolean IsInsert
)
{
    uint8 i;
    uint8 PathStatus = PDUR_BUFFER_IDLE;
    if(IsInsert == TRUE)
    {
        /*Successfully inserted into queue*/
        /*Queue available depth minus 1*/
        PduRBufferQueueInfo[BufferId].QueueAvailableLen--;
        /*If the queue can still store data next time, Update the write deep address*/
        if(PduRBufferQueueInfo[BufferId].QueueAvailableLen != (PduLengthType)0)
        {
            PduRBufferQueueInfo[BufferId].RearPos++;
            if(PduRBufferQueueInfo[BufferId].RearPos == PDUR_BUFFER_DEPTH(BufferId))
            {
                PduRBufferQueueInfo[BufferId].RearPos = (PduLengthType)0;
            }
        }       
    }
    else
    {
        if(PduRBufferQueueInfo[BufferId].QueueAvailableLen == (PduLengthType)0)
        {
            PduRBufferQueueInfo[BufferId].RearPos++;
            if(PduRBufferQueueInfo[BufferId].RearPos == PDUR_BUFFER_DEPTH(BufferId))
            {
                PduRBufferQueueInfo[BufferId].RearPos = (PduLengthType)0;
            }
        }
        /*Successfully exited the queue*/
        /*Queue available depth add 1*/
        if(PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).RxFail == (uint8)0)
        {
            PduRBufferQueueInfo[BufferId].QueueAvailableLen++;
        }
        if(PduRBufferQueueInfo[BufferId].QueueAvailableLen >= PDUR_BUFFER_DEPTH(BufferId))
        {

            PduRBufferQueueInfo[BufferId].QueueAvailableLen = PDUR_BUFFER_DEPTH(BufferId);

        }
        for(i = (uint8)0; i < PDUR_BUFFER_DEPTH(BufferId); i++)
        {
            PathStatus |= PDUR_BUFFER_INFO(BufferId,i).BufState;
        }
        if(PathStatus == PDUR_BUFFER_IDLE)
        {
            /*The queue is empty, reset queue*/
            PduRBufferQueueInfo[BufferId].FrontPos = (PduLengthType)0;
            PduRBufferQueueInfo[BufferId].RearPos = (PduLengthType)0;
        }
        else
        {
            PduRBufferQueueInfo[BufferId].FrontPos++;
            if(PduRBufferQueueInfo[BufferId].FrontPos == PDUR_BUFFER_DEPTH(BufferId))
            {
                PduRBufferQueueInfo[BufferId].FrontPos = (PduLengthType)0;
            }
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_InsertQueue
*
* Description:   Data insertion buffer.
*
* Inputs:        BufferId     : The number of the buffer.
*                info         : Insert data into queue.
*                CopySduLength: The length of data inserted into the queue.
*
* Outputs:       None
*
* ReturnValue:   Is the insert successful.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_InsertQueue
(
    CONST(PduR_BufferIdType, PDUR_CONST) BufferId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    CONST(PduLengthType, PDUR_CONST) CopySduLength
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduLengthType RearPos = PduRBufferQueueInfo[BufferId].RearPos;
    PduLengthType WritePos = PDUR_BUFFER_INFO(BufferId, RearPos).WritePos;
    PduLengthType TailDataLen = (PduLengthType)0;

    if(PduRBufferQueueInfo[BufferId].QueueAvailableLen != (PduLengthType)0)
    {
        if(PDUR_BUFFER_INFO(BufferId, RearPos).AvailableLen >= CopySduLength)
        {
            /*there is no data stored in the current write address,Can store data*/
            /*[- - - 0 1 - - -]*/
            TailDataLen = PDUR_BUFFER_INFO(BufferId,RearPos).AllocatedBufferLen - WritePos;
            if(CopySduLength < TailDataLen)
            {
                /*[- - - 0 1 2 3 -]*/
                Bsw_MemCpy((uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[RearPos])+WritePos, info->SduDataPtr, (uint32)CopySduLength);
                /*Update the write byte address information of the current insertion address*/
                PDUR_BUFFER_INFO(BufferId, RearPos).WritePos += CopySduLength;
            }
            else
            {
                /*[- - - 0 1 2 3 4]*/
                Bsw_MemCpy((uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[RearPos])+WritePos, info->SduDataPtr, (uint32)TailDataLen);
                /*[5 6 - 0 1 2 3 4]*/
                /*PRQA S 4391 ++*/
                Bsw_MemCpy((uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[RearPos])+(PduLengthType)0, (info->SduDataPtr + TailDataLen), (uint32)(CopySduLength - TailDataLen));
                /*PRQA S 4391 --*/
                /*Update the write byte address information of the current insertion address*/
                PDUR_BUFFER_INFO(BufferId, RearPos).WritePos = CopySduLength - TailDataLen;
            }

#if(STD_ON == PDUR_METADATA_SUPPORT)
            if(PDUR_BUFFER_INFO(BufferId, RearPos).IsStore == FALSE)
            {
                PDUR_BUFFER_INFO(BufferId, RearPos).MetaDataPtr = info->MetaDataPtr;
                PDUR_BUFFER_INFO(BufferId, RearPos).IsStore = TRUE;
            }    
#endif

            /*The data saved this time is complete*/
            /*Write data to the new write address next time*/
            ret = E_OK;
        }
        else
        {
            /*The length of the Buffer does not meet the length of the stored data,
            so the single frame data cannot be stored*/
        }
    }
    else
    {
        /*The queue is full and cannot store data*/
    }
    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_MatchPos
*
* Description:   Match depth based on path
*
* Inputs:        PathId   : Routing path.
*                BufferId : Associated FIFO.
*
* Outputs:       None
*
* ReturnValue:   Is the match successful
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, PDUR_CODE) PduR_MatchPos
(
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId,
    CONST(PduR_BufferIdType, PDUR_CONST) BufferId
)
{
    boolean MatchFlag = FALSE;
    PduLengthType RearPosCount;
    PduLengthType RearPos = PduRBufferQueueInfo[BufferId].RearPos;

    for(RearPosCount = (PduLengthType)0; RearPosCount < PDUR_BUFFER_DEPTH(BufferId); RearPosCount++)
    {
        if(PDUR_BUFFER_INFO(BufferId, RearPos).PathIdx == PathId)
        {
            PduRBufferQueueInfo[BufferId].RearPos = RearPos;
            MatchFlag = TRUE;
            break;
        }
        RearPos++;
        if(RearPos == PDUR_BUFFER_DEPTH(BufferId))
        {
            RearPos = (PduLengthType)0;
        }
    }
    return MatchFlag;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_ExportQueue
*
* Description:   Match path based on handle
*
* Inputs:        BufferId     : The number of the buffer.         
*                CopySduLength: The length of data inserted into the queue.
*
* InOutputs:     PduInfoPtr   : Data exported from the queue.
*
* Outputs:       None
*
* ReturnValue:   Is the export successful.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_ExportQueue
(
    PduR_BufferIdType BufferId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_VAR) PduInfoPtr,
    PduLengthType CopyLength

)
{
    Std_ReturnType ret = E_OK;
    PduLengthType FrontPos = PduRBufferQueueInfo[BufferId].FrontPos;
    PduLengthType ReadPos = PDUR_BUFFER_INFO(BufferId, FrontPos).ReadPos;
    PduLengthType TailDataLen = (PduLengthType)0;

    if((CopyLength != (PduLengthType)0) && (PDUR_BUFFER_INFO(BufferId, FrontPos).ValidLen >= CopyLength))
    {
        /*Data is available, get data*/
        
        if(PduInfoPtr->SduDataPtr != NULL_PTR)
        {
            /*[3 4 5 - - 0 1 2]*/
            TailDataLen = PDUR_BUFFER_INFO(BufferId, FrontPos).AllocatedBufferLen - ReadPos;
            if(CopyLength < TailDataLen)
            {
                /*[1 2 3 - - - - 0]*/
                Bsw_MemCpy(PduInfoPtr->SduDataPtr, (uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[FrontPos])+ReadPos, (uint32)CopyLength);
                PDUR_BUFFER_INFO(BufferId,FrontPos).ReadPos += CopyLength;
            }
            else
            {
                /*[0 1 2 - - - - -]*/
                Bsw_MemCpy(PduInfoPtr->SduDataPtr, (uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[FrontPos])+ReadPos, (uint32)TailDataLen);
                /*[- - 0 - - - - -]*/
                /*PRQA S 4391 ++*/
                Bsw_MemCpy(PduInfoPtr->SduDataPtr + TailDataLen, (uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[FrontPos])+0,(uint32)(CopyLength - TailDataLen));
                /*PRQA S 4391 --*/
                PDUR_BUFFER_INFO(BufferId,FrontPos).ReadPos = CopyLength - TailDataLen;
            }
        }
        else
        {
            PduInfoPtr->SduDataPtr =(uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[FrontPos])+ReadPos;
        }

#if(STD_ON == PDUR_METADATA_SUPPORT)
        if(PDUR_BUFFER_INFO(BufferId,FrontPos).IsStore == TRUE)
        {
            PduInfoPtr->MetaDataPtr = PDUR_BUFFER_INFO(BufferId, FrontPos).MetaDataPtr;
        }
#endif

    }
    else
    {
        /*The queue is empty, No data available*/
        ret = E_NOT_OK;
    }
    return ret;
}
#if(STD_ON == PDUR_GW_IF_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_IfModuleGwTrigger
*
* Description:   Communication Interface Gatewaying in trigger mode.
*
* Inputs:        BufferId : The number of the buffer.
*                PathId   : Routing path.
*
* InOutputs:     PduInfoPtr   : Data exported from the queue.
*
* Outputs:       None
*
* ReturnValue:   None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, PDUR_CODE) PduR_IfModuleGwTrigger
(
    PduR_BufferIdType BufferId,
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{
    PduIdType DestPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;
    uint8 DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;

    PduR_RoutingPathIdType ConfIndex = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduConfIndex;

    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    PduLengthType RearPos;
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
    if(PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduCore != PDUR_GET_CORE_ID())
    {


        result = PduR_BufferAllocate(PathId, BufferId, PduRBufferQueueInfo[BufferId].RearPos, PduInfoPtr->SduLength);

        if(result == BUFREQ_E_NOT_OK)
        {

        }
        else
        {
            if(E_OK == PduR_InsertQueue(BufferId, PduInfoPtr, PduInfoPtr->SduLength))
            {
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).PathIdx = PathId;

                PduR_PathConf[ConfIndex] = FALSE;
                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos));
                }

                /*Update the stored data length of the current write address*/
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).ValidLen += PduInfoPtr->SduLength;
                /*Update the remaining length of the current write address*/
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).AvailableLen -= PduInfoPtr->SduLength;
                /*Update the receive length information of the current inserted address*/
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).ReceivedLen += PduInfoPtr->SduLength;

                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos));
                }
                
                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
                RearPos = PduRBufferQueueInfo[BufferId].RearPos;
                PduR_UpdateFIFOInfo(BufferId, TRUE);
                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
                PDUR_BUFFER_INFO(BufferId, RearPos).TxAllowFlag = TRUE;
            }
            else
            {
                PduR_BufferRelease(PathId, BufferId, PduRBufferQueueInfo[BufferId].RearPos);
                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos));
                }
                PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].RearPos);
                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos));
                }
            }
        }
    }
    else
#endif
    {

        result = PduR_BufferAllocate(PathId, BufferId, PduRBufferQueueInfo[BufferId].RearPos, PduInfoPtr->SduLength);

        if(result == BUFREQ_E_NOT_OK)
        {

        }
        else
        {
            if(E_OK == PduR_InsertQueue(BufferId, PduInfoPtr, PduInfoPtr->SduLength))
            {
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).PathIdx = PathId;
                /*Update the stored data length of the current write address*/
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).ValidLen += PduInfoPtr->SduLength;
                /*Update the remaining length of the current write address*/
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).AvailableLen -= PduInfoPtr->SduLength;
                /*Update the receive length information of the current inserted address*/
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).ReceivedLen += PduInfoPtr->SduLength;

                PduR_UpdateFIFOInfo(BufferId, TRUE);
                /*SWS_PduR_00665*/
                (void)PduR_ModuleFunctions[DestModuleType].IfTransmitFunc(DestPduId, PduInfoPtr);  

            }
            else
            {
                PduR_BufferRelease(PathId, BufferId, PduRBufferQueueInfo[BufferId].RearPos);

                PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].RearPos);

            }
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_IfModuleDirect
*
* Description:   Transport Protocol Gatewaying in driect mode.
*
* Inputs:        BufferId : The number of the buffer.
*                PathId   : Routing path.
*
* InOutputs:     PduInfoPtr   : Data exported from the queue.
*
* Outputs:       None
*
* ReturnValue:   None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, PDUR_CODE) PduR_IfModuleDirect
(
    PduR_BufferIdType BufferId,
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{
    PduIdType DestPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;
    uint8 DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;
    PduR_RoutingPathIdType ConfIndex = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduConfIndex;
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    PduLengthType RearPos;

    result = PduR_BufferAllocate(PathId, BufferId, PduRBufferQueueInfo[BufferId].RearPos, PduInfoPtr->SduLength);

    if(result == BUFREQ_E_NOT_OK)
    {
        
    }
    else
    {
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
        if(PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduCore != PDUR_GET_CORE_ID())
        {
            if(E_OK == PduR_InsertQueue(BufferId, PduInfoPtr, PduInfoPtr->SduLength))
            {
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).PathIdx = PathId;
                
                PduR_PathConf[ConfIndex] = FALSE;


                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos));
                }

                /*Update the stored data length of the current write address*/
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).ValidLen += PduInfoPtr->SduLength;
                /*Update the remaining length of the current write address*/
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).AvailableLen -= PduInfoPtr->SduLength;
                /*Update the receive length information of the current inserted address*/
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).ReceivedLen += PduInfoPtr->SduLength;

                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos));
                }

                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
                RearPos = PduRBufferQueueInfo[BufferId].RearPos;
                PduR_UpdateFIFOInfo(BufferId, TRUE);
                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
                PDUR_BUFFER_INFO(BufferId, RearPos).TxAllowFlag = TRUE;

            }
            else
            {
                PduR_BufferRelease(PathId, BufferId, PduRBufferQueueInfo[BufferId].RearPos);
                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos));
                }
                PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].RearPos);
                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos));
                }
            }
        }
        else
#endif
        {
            /*direct data provision is used with a FIFO*/
            if(PduR_PathConf[ConfIndex] == FALSE)
            {
                /*PduR_<DstLo>TxConfirmation has not yet been confirmed*/
                /*SWS_PduR_00793*/ 
                if(E_OK == PduR_InsertQueue(BufferId, PduInfoPtr, PduInfoPtr->SduLength))
                {
                    PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).PathIdx = PathId;
                    PduR_UpdateFIFOInfo(BufferId, TRUE);
                }
                else
                {
                    PDUR_DET_REPORT_ERROR(PDUR_MODULE_IF_RXINDICATION_APIID, PDUR_E_PDU_INSTANCES_LOST);
                }
            }
            else
            {
                /*PduR_<DstLo>TxConfirmation has been confirmed*/
                PduR_PathConf[ConfIndex] = FALSE;
                /*SWS_PduR_00665*/
                (void)PduR_ModuleFunctions[DestModuleType].IfTransmitFunc(DestPduId, PduInfoPtr);
                PduR_BufferRelease(PathId, BufferId, PduRBufferQueueInfo[BufferId].RearPos);
            }
        }
    }
}
#endif /*#if(STD_ON == PDUR_GW_IF_SUPPORT)*/

#if(PDUR_MAX_RX_PDU_INFO > 0)
#if(STD_ON == PDUR_GW_TP_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_TpGWStartOfReception
*
* Description:   Transport Protocol Gatewaying starts receiving.
*
* Inputs:        BufferId : The number of the buffer.
*                PathId   : Routing path.
*                info   : Data exported from the queue.
*                TpSduLength : Total length of the N-SDU to be received.
*
* InOutputs:     info   : Data exported from the queue.
*                bufferSizePtr: Available receive buffer in the receiving module.
*
* Outputs:       None
*
* ReturnValue:   BufReq_ReturnType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_TpGWStartOfReception
(
    PduR_BufferIdType BufferId,
    PduR_RoutingPathIdType PathId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{

    BufReq_ReturnType result = BUFREQ_E_NOT_OK;

    uint8 DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;
    PduIdType DestPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;
    uint16 PduRTpThreshold = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRTpThreshold;
    PduInfoType TxPduInfo;
    PduR_RoutingPathIdType ConfIndex = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduConfIndex;
    PduLengthType RearPos;
    PduLengthType RearPosCount;
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
    if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
    {
        PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
    }
#endif
    RearPos = PduRBufferQueueInfo[BufferId].RearPos;
    RearPosCount = PduRBufferQueueInfo[BufferId].QueueAvailableLen;
    while (PDUR_BUFFER_IDLE != PDUR_BUFFER_INFO(BufferId, RearPos).BufState)
    {
        if(RearPosCount == (PduLengthType)0)
        {
            RearPosCount = (PduLengthType)0xFFFF;
            break;
        }
        else
        {
            /*SWS_PduR_00832*/
            RearPosCount--;
            RearPos++;
            if(RearPos == PDUR_BUFFER_DEPTH(BufferId))
            {
                RearPos = (PduLengthType)0;
            }
        }
    }
    if(RearPosCount != (PduLengthType)0xFFFF)
    {

    }
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
    if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
    {
        PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
    }
#endif

    if(RearPosCount != (PduLengthType)0xFFFF)
    {
        if(PDUR_BUFFER_INFO(BufferId, RearPos).AvailableLen < info->SduLength)
        {
            /*SWS_PduR_00799*/
            result = BUFREQ_E_OVFL;
#if(STD_ON == PDUR_TEST_ENABLE)
            /*ErrorType 2*/
            ErrorInfo[ErrorCount].ErrorType = 2;
            ErrorInfo[ErrorCount].ErrorBufferId = BufferId;
            ErrorInfo[ErrorCount].ErrorBufferInfo = PDUR_BUFFER_INFO(BufferId, RearPos);
            ErrorInfo[ErrorCount].ErrorBufferQueueInfo = PduRBufferQueueInfo[BufferId];
            ErrorInfo[ErrorCount].BufferPoolUsage = PduR_BufferPoolSet[PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PdurDestTxBufferPoolId].BufferInUse[0];
            /*
            Bsw_MemCpy(ErrorInfo[ErrorCount].PduContent, info->SduDataPtr, 5);
            */
            PduR_SendErrorInfo();
            ErrorCount++;
            if(ErrorCount == 20)
            {
                ErrorCount = 0;
            }
#endif
        }
        else
        {
            PDUR_BUFFER_INFO(BufferId, RearPos).PathIdx = PathId;
            if(((PduLengthType)0 == PduRTpThreshold))
            {
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                if(PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduCore != PDUR_GET_CORE_ID())
                {


                    result = PduR_BufferAllocate(PathId, BufferId, RearPos, TpSduLength);


                    if(result == BUFREQ_OK)
                    {
                        *bufferSizePtr = PDUR_BUFFER_INFO(BufferId, RearPos).AvailableLen;
                        PDUR_BUFFER_INFO(BufferId, RearPos).BufState = PDUR_BUFFER_RECEIVING;
                        result = BUFREQ_OK;
                        PDUR_BUFFER_INFO(BufferId, RearPos).TxAllowFlag = TRUE;

                    }
                }
                else
#endif
                if(PduR_PathConf[ConfIndex] == TRUE)
                {
                    TxPduInfo.SduLength = TpSduLength;
                    PDUR_BUFFER_INFO(BufferId, RearPos).TotalLen = TpSduLength;
                    /*!!!CAUTION!!! TpTransmitFunc must not read data for now*/
                    TxPduInfo.SduDataPtr =(SduDataPtrType)(PduR_Cfg_Buffer[BufferId].PduPtr[RearPos]);

                    /*SWS_PDUR_00811*//*directly call <DstLoTp>_Transmit if PduRTpThreshold = 0*/
                    if(E_OK == PduR_ModuleFunctions[DestModuleType].TpTransmitFunc(DestPduId, &TxPduInfo))
                    {
                        /*PduR_<DstLo>TxConfirmation has been confirmed*/

                        result = PduR_BufferAllocate(PathId, BufferId, RearPos, TpSduLength);
                        if (result == BUFREQ_OK)
                        {
                            PduR_PathConf[ConfIndex] = FALSE;
                            *bufferSizePtr = PDUR_BUFFER_INFO(BufferId, RearPos).AvailableLen;
                            PDUR_BUFFER_INFO(BufferId, RearPos).BufState = PDUR_BUFFER_RECEIVING | PDUR_BUFFER_TRANSMITING;
                        }
                        else
                        {
                            PduR_BufferInit(BufferId, RearPos);
                            /*SWS_PDUR_00807*/
                            PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_STARTOFRECEPTION_APIID, PDUR_E_PDU_INSTANCES_LOST);
                        }
                    }
                    else
                    {
                        PduR_BufferInit(BufferId, RearPos);
                        /*SWS_PDUR_00807*/
                        PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_STARTOFRECEPTION_APIID, PDUR_E_PDU_INSTANCES_LOST);
                    }
                }
                else
                {
                    /*do nothing*/
                }
            }
            else
            {

                result = PduR_BufferAllocate(PathId, BufferId, RearPos,TpSduLength);

                if (result == BUFREQ_OK)
                {
                    PDUR_BUFFER_INFO(BufferId, RearPos).BufState = PDUR_BUFFER_RECEIVING;
                    *bufferSizePtr = PDUR_BUFFER_INFO(BufferId, RearPos).AvailableLen;
                    PDUR_BUFFER_INFO(BufferId, RearPos).TotalLen = TpSduLength;
                    
                }
                else
                {
#if(STD_ON == PDUR_TEST_ENABLE)
                    /*ErrorType 4*/
                    ErrorInfo[ErrorCount].ErrorType = 4;
                    ErrorInfo[ErrorCount].ErrorBufferId = BufferId;
                    ErrorInfo[ErrorCount].ErrorBufferInfo = PDUR_BUFFER_INFO(BufferId, RearPos);
                    ErrorInfo[ErrorCount].ErrorBufferQueueInfo = PduRBufferQueueInfo[BufferId];
                    ErrorInfo[ErrorCount].BufferPoolUsage = PduR_BufferPoolSet[PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PdurDestTxBufferPoolId].BufferInUse[0];
                    /*
                    Bsw_MemCpy(ErrorInfo[ErrorCount].PduContent, info->SduDataPtr, 5);
                    */
                    PduR_SendErrorInfo();
                    ErrorCount++;
                    if(ErrorCount == 20)
                    {
                        ErrorCount = 0;
                    }

#endif
                    PduR_BufferInit(BufferId, RearPos);
                    /*SWS_PDUR_00807*/
                    PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_STARTOFRECEPTION_APIID, PDUR_E_PDU_INSTANCES_LOST);

                }
            }
        }
    }
#if(STD_ON == PDUR_TEST_ENABLE)
    else
    {
        /*ErrorType 1*/
        ErrorInfo[ErrorCount].ErrorType = 1;
        ErrorInfo[ErrorCount].ErrorBufferId = BufferId;
        ErrorInfo[ErrorCount].ErrorBufferInfo = PDUR_BUFFER_INFO(BufferId, RearPos);
        ErrorInfo[ErrorCount].ErrorBufferQueueInfo = PduRBufferQueueInfo[BufferId];
        ErrorInfo[ErrorCount].BufferPoolUsage = PduR_BufferPoolSet[PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PdurDestTxBufferPoolId].BufferInUse[0];
        /*
        Bsw_MemCpy(ErrorInfo[ErrorCount].PduContent, info->SduDataPtr, 5);
        */
        PduR_SendErrorInfo();
        ErrorCount++;
        if(ErrorCount == 20)
        {
            ErrorCount = 0;
        }
    }
#endif
    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_TpGWCopyRxData
*
* Description:   Tp gateway Copy Rx Data
*
* Inputs:        
*
* Outputs:       None
*
*ReturnValue:    BufReq_ReturnType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_TpGWCopyRxData
(
    PduR_BufferIdType BufferId,
    PduR_RoutingPathIdType PathId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    PduLengthType RearPos = PduRBufferQueueInfo[BufferId].RearPos;
    uint16 PduRTpThreshold = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRTpThreshold;
    PduIdType DestPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;
    uint8 DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;
    PduInfoType TxPduInfo;
    PduLengthType FrontPos;
    PduLengthType ReadPos;
    PduR_RoutingPathIdType ConfIndex = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduConfIndex;

    /*GW*/
    if(E_OK != PduR_InsertQueue(BufferId, info, info->SduLength))
    {
        /*Cancel transport*//*The available length of the Buffer is less than the storage length*/
        /*SWS_PduR_00687*/
        result = BUFREQ_E_NOT_OK;
#if(STD_ON == PDUR_TEST_ENABLE)
        /*ErrorType 5*/
        ErrorInfo[ErrorCount].ErrorType = 5;
        ErrorInfo[ErrorCount].ErrorBufferId = BufferId;
        ErrorInfo[ErrorCount].ErrorBufferInfo = PDUR_BUFFER_INFO(BufferId, RearPos);
        ErrorInfo[ErrorCount].ErrorBufferQueueInfo = PduRBufferQueueInfo[BufferId];
        ErrorInfo[ErrorCount].BufferPoolUsage = PduR_BufferPoolSet[PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PdurDestTxBufferPoolId].BufferInUse[0];

        Bsw_MemCpy(ErrorInfo[ErrorCount].PduContent, (uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[RearPos]), 5);
        PduR_SendErrorInfo();

        ErrorCount++;
        if(ErrorCount == 20)
        {
            ErrorCount = 0;
        }
#endif
    }
    else
    {
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
        if(PDUR_BUFFER_FLAG_PTR(BufferId,RearPos) != NULL_PTR)
        {
            PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId,RearPos));
        }
#endif
        /*Update the stored data length of the current write address*/
        PDUR_BUFFER_INFO(BufferId, RearPos).ValidLen += info->SduLength;
        /*Update the remaining length of the current write address*/
        PDUR_BUFFER_INFO(BufferId, RearPos).AvailableLen -= info->SduLength;
        /*Update the receive length information of the current inserted address*/
        PDUR_BUFFER_INFO(BufferId, RearPos).ReceivedLen += info->SduLength;
        /*Successfully Enqueue*/
        *bufferSizePtr = PDUR_BUFFER_INFO(BufferId, RearPos).AvailableLen;
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
        if(PDUR_BUFFER_FLAG_PTR(BufferId,RearPos) != NULL_PTR)
        {
            PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId,RearPos));
        }
#endif

        if((PDUR_BUFFER_INFO(BufferId, RearPos).ReceivedLen >= (PduLengthType)PduRTpThreshold)\
            && ((PDUR_BUFFER_INFO(BufferId, RearPos).ReceivedLen - info->SduLength) < PduRTpThreshold))
        {
            /*First time getting above the threshold*/
#if(STD_ON == PDUR_MULTICORE_SUPPORT)

            if(PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduCore != PDUR_GET_CORE_ID())
            {
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).TxAllowFlag = TRUE;

                result = BUFREQ_OK;
            }
            else
#endif

            if((PduR_PathConf[ConfIndex] == TRUE))
            {
                /*SWS_PduR_00317*/
                TxPduInfo.SduLength = PDUR_BUFFER_INFO(BufferId, RearPos).TotalLen;
                /*!!!CAUTION!!! TpTransmitFunc must not read data for now*/
                FrontPos = PduRBufferQueueInfo[BufferId].FrontPos;
                ReadPos = PDUR_BUFFER_INFO(BufferId, FrontPos).ReadPos;
                TxPduInfo.SduDataPtr =(uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[FrontPos])+ReadPos;

                if(E_OK == PduR_ModuleFunctions[DestModuleType].TpTransmitFunc(DestPduId, &TxPduInfo))
                {

                    PduR_PathConf[ConfIndex] = FALSE;
                    PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).BufState |= PDUR_BUFFER_TRANSMITING;
                    result = BUFREQ_OK;
                }
                else
                {
#if(STD_ON == PDUR_TEST_ENABLE)
                    /*ErrorType 6*/
                    ErrorInfo[ErrorCount].ErrorType = 6;
                    ErrorInfo[ErrorCount].ErrorBufferId = BufferId;
                    ErrorInfo[ErrorCount].ErrorBufferInfo = PDUR_BUFFER_INFO(BufferId, RearPos);
                    ErrorInfo[ErrorCount].ErrorBufferQueueInfo = PduRBufferQueueInfo[BufferId];
                    ErrorInfo[ErrorCount].BufferPoolUsage = PduR_BufferPoolSet[PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PdurDestTxBufferPoolId].BufferInUse[0];

                    Bsw_MemCpy(ErrorInfo[ErrorCount].PduContent, (uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[RearPos]), 5);
                    PduR_SendErrorInfo();
                    ErrorCount++;
                    if(ErrorCount == 20)
                    {
                        ErrorCount = 0;
                    }
#endif
                    PduR_BufferRelease(PathId, BufferId, RearPos);
                    PduR_BufferInit(BufferId, RearPos);
                    /*SWS_PDUR_00807*/
                    PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_COPYRXDATA_APIID, PDUR_E_PDU_INSTANCES_LOST);
                }
            }
            else
            {
                result = BUFREQ_OK;
            }

        }
        else
        {
            /*Not satisfied with On the fly gateway*//*Keep receiving*/
            result = BUFREQ_OK;
        }
    }
    return result;
}
#endif /*#if(STD_ON == PDUR_GW_TP_SUPPORT)*/
#endif /*#if(PDUR_MAX_RX_PDU_INFO > 0)*/

#if(STD_ON == PDUR_MULTICORE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_CrossCoreTxMainfunction
*
* Description:   Match path based on handle
*
* Inputs:        PduId :    Identification of the I-PDU.
*                PduIdMax : Maximum number of IdUs
*                PduIdList: Match in this list
*
* Outputs:       None
*
*ReturnValue:    Matched Path
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_CrossCoreTxMainfunction
(
    void
)
{
    PduR_BufferIdType BufferId;
    PduLengthType DeepIndex;
    PduR_RoutingPathIdType PathIndex;
    uint8 DestModuleType;
    PduIdType DestPduId;
    PduLengthType PduLength;
    PduInfoType PduInfo;
    uint8 CoreId = PDUR_GET_CORE_ID();
    PduR_RoutingPathIdType CrossCorePathNum;
    uint8 i;
    PduR_RoutingPathIdType ConfIndex;
    PduLengthType TailDataLen = (PduLengthType)0;
    PduLengthType bufferSizePtr;
    CrossCorePathNum = PduR_CrossCorePath_Dest_Table[CoreId].CrossCorePathNum;

    for(i = (uint8)0; i < (uint8)CrossCorePathNum; i++)
    {
        PathIndex = PduR_CrossCorePath_Dest_Table[CoreId].CrossCorePathIdx[i];
        /*Get the path in the current core*/
        BufferId = PDUR_ROUTINGPATHINFO(PathIndex).PduRDestPdu.PduRDestTxBufferId;
        if((PDUR_ROUTINGPATHINFO(PathIndex).PduRDestPdu.PduRDestPduCore == PDUR_GET_CORE_ID())\
            && (BufferId != PDUR_UNUSED))
        {
            /*Get current data information*/
            DeepIndex = PduRBufferQueueInfo[BufferId].FrontPos;
            DestModuleType = PDUR_ROUTINGPATHINFO(PathIndex).PduRDestPdu.PduRDestModuleType;
            DestPduId = PDUR_ROUTINGPATHINFO(PathIndex).PduRDestPdu.PduRDestPduId;
            PduLength = PDUR_BUFFER_INFO(BufferId, DeepIndex).ReceivedLen;
            ConfIndex = PDUR_ROUTINGPATHINFO(PathIndex).PduRDestPdu.PduRDestPduConfIndex;
            if(PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).TxAllowFlag == TRUE)
            {

                /*The current data to be sent in the buffer is cross core data*/


                PDUR_BUFFER_INFO(BufferId,DeepIndex).TxAllowFlag = FALSE;

                /*Get data and send*/
                if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].IfTransmitFunc)
                {
                    if(PDUR_ROUTINGPATHINFO(PathIndex).PduRDestPdu.PduRDestPduDataProvision == PDUR_TRIGGERTRANSMIT)
                    {
                        PduInfo.SduLength = PduLength;
                        PduInfo.SduDataPtr = NULL_PTR;
                        (void)PduR_ModuleFunctions[DestModuleType].IfTransmitFunc(DestPduId, &PduInfo);
                    }
                    else
                    {
                        PduInfo.SduDataPtr = (SduDataPtrType)(PduR_Cfg_Buffer[BufferId].PduPtr[DeepIndex]);
                        if((PduLength != (PduLengthType)0) && (PDUR_BUFFER_INFO(BufferId, DeepIndex).ValidLen >= PduLength))
                        {
                            PduInfo.SduLength = PduLength;
                            (void)PduR_ModuleFunctions[DestModuleType].IfTransmitFunc(DestPduId, &PduInfo);
                        }
                        else
                        {

                        }

                        PduR_BufferRelease(PathIndex, BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
                        if(PDUR_BUFFER_FLAG_PTR(BufferId,DeepIndex) != NULL_PTR)
                        {
                            PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId,DeepIndex));
                        }
                        PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
                        if(PDUR_BUFFER_FLAG_PTR(BufferId,DeepIndex) != NULL_PTR)
                        {
                            PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId,DeepIndex));
                        }

                        if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                        {
                            PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                        }
                        PduR_UpdateFIFOInfo(BufferId,FALSE);
                        if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                        {
                            PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                        }

                    }

                }
#if(PDUR_MAX_TX_PDU_INFO > 0 || STD_ON == PDUR_GW_TP_SUPPORT)
                else if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].TpTransmitFunc)
                {
                    /*Tp module*/
                    PduInfo.SduDataPtr = NULL_PTR;
                    PduInfo.SduLength = PDUR_BUFFER_INFO(BufferId, DeepIndex).TotalLen;
                    if(PduR_PathConf[ConfIndex] == TRUE)
                    {
                        if((uint8)(PDUR_BUFFER_INFO(BufferId, DeepIndex).UpTpTransmit & PDUR_CROSSCORE_TX_WAIT_CANCEL_TRANSMIT) != (uint8)0)
                        {
                            (void)PduR_UpCancelTransmit(PathIndex);
                            PDUR_BUFFER_INFO(BufferId, DeepIndex).UpTpTransmit &= (uint8)(~PDUR_CROSSCORE_TX_WAIT_CANCEL_TRANSMIT);
                        }

                        if(E_OK == PduR_ModuleFunctions[DestModuleType].TpTransmitFunc(DestPduId, &PduInfo))
                        {
                            PDUR_BUFFER_INFO(BufferId, DeepIndex).BufState |= PDUR_BUFFER_TRANSMITING;
                            PDUR_BUFFER_INFO(BufferId, DeepIndex).UpTpTransmit |= PDUR_CROSSCORE_TX_LO_TRANSMITTING;
                            PDUR_BUFFER_INFO(BufferId, DeepIndex).UpTpTransmit &= (uint8)(~PDUR_CROSSCORE_TX_WAIT_LO_TRANSMIT);
                            PduR_PathConf[ConfIndex] = FALSE;
                        }
                        else
                        {
                            PduR_BufferRelease(PathIndex, BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
                            if(PDUR_BUFFER_FLAG_PTR(BufferId,DeepIndex) != NULL_PTR)
                            {
                                PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId,DeepIndex));
                            }

                            PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].FrontPos);

                            if(PDUR_BUFFER_FLAG_PTR(BufferId,DeepIndex) != NULL_PTR)
                            {
                                PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId,DeepIndex));
                            }
                            if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                            {
                                PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                            }
                            PduR_UpdateFIFOInfo(BufferId,FALSE);
                            if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                            {
                                PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                            }
                            /*SWS_PDUR_00807*/
                            PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_STARTOFRECEPTION_APIID, PDUR_E_PDU_INSTANCES_LOST);
                        }
                    }
                    else
                    {
                        PDUR_BUFFER_INFO(BufferId,DeepIndex).TxAllowFlag = TRUE;
                    }
                }
#endif
                else if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].UpIfRxIndicationFunc)
                {

                    PduInfo.SduDataPtr = (SduDataPtrType)(PduR_Cfg_Buffer[BufferId].PduPtr[DeepIndex]);
                    if((PduLength != (PduLengthType)0) && (PDUR_BUFFER_INFO(BufferId, DeepIndex).ValidLen >= PduLength))
                    {
                        PduInfo.SduLength = PduLength;
                        PduR_ModuleFunctions[DestModuleType].UpIfRxIndicationFunc(DestPduId, &PduInfo);
                    }

                    PduR_BufferRelease(PathIndex, BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
                    if(PDUR_BUFFER_FLAG_PTR(BufferId,DeepIndex) != NULL_PTR)
                    {
                        PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId,DeepIndex));
                    }
                    PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
                    if(PDUR_BUFFER_FLAG_PTR(BufferId,DeepIndex) != NULL_PTR)
                    {
                        PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId,DeepIndex));
                    }

                    if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                    {
                        PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                    }
                    PduR_UpdateFIFOInfo(BufferId,FALSE);
                    if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                    {
                        PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                    }
                }
                else if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].UpTpRxIndicationFunc)
                {
                    PduInfo.SduLength = PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).TotalLen;
                    PduInfo.SduDataPtr = NULL_PTR;
                    PduR_ModuleFunctions[DestModuleType].UpTpStartOfReceptionFunc(DestPduId,&PduInfo,PduLength,&bufferSizePtr);
                    PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).UpTpReceive |= PDUR_CROSSCORE_RX_UP_RECEIVING;
                    PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).UpTpReceive &= (uint8)(~PDUR_CROSSCORE_RX_WAIT_UP_RECEIVE);
                }
                else
                {
                    /*Do nothings*/
                }
            }
            else if((uint8)(PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).UpTpReceive & PDUR_CROSSCORE_RX_UP_RECEIVING) != (uint8)0 )
            {
                if(PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).ValidLen != (PduLengthType)0)
                {

                    PduInfo.SduLength = PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).ValidLen;
                    TailDataLen = PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).AllocatedBufferLen - PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).ReadPos;
                    if(PduInfo.SduLength < TailDataLen)
                    {
                        /*[1 2 3 - - - - 0]*/
                        PduInfo.SduDataPtr = (uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[PduRBufferQueueInfo[BufferId].FrontPos])+PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).ReadPos;
                        PduR_ModuleFunctions[DestModuleType].UpTpCopyRxDataFunc(DestPduId, &PduInfo, &bufferSizePtr);
                        PDUR_BUFFER_INFO(BufferId,PduRBufferQueueInfo[BufferId].FrontPos).ReadPos += PduInfo.SduLength;
                    }
                    else
                    {

                        /*[0 1 2 - - - - -]*/

                        PduInfo.SduDataPtr = (uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[PduRBufferQueueInfo[BufferId].FrontPos])+PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).ReadPos;
                        PduInfo.SduLength = TailDataLen;
                        PduR_ModuleFunctions[DestModuleType].UpTpCopyRxDataFunc(DestPduId, &PduInfo, &bufferSizePtr);

                        /*[- - 0 - - - - -]*/
                        /*PRQA S 4391 ++*/
                        PduInfo.SduDataPtr = (SduDataPtrType)(PduR_Cfg_Buffer[BufferId].PduPtr[PduRBufferQueueInfo[BufferId].FrontPos]);
                        PduInfo.SduLength = PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).ValidLen - TailDataLen;
                        PduR_ModuleFunctions[DestModuleType].UpTpCopyRxDataFunc(DestPduId, &PduInfo, &bufferSizePtr);
                        /*PRQA S 4391 --*/
                        PDUR_BUFFER_INFO(BufferId,PduRBufferQueueInfo[BufferId].FrontPos).ReadPos = PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).ValidLen - TailDataLen;
                    }




                    if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                    {
                        PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                    }
                    /*SWS_PduR_00696*/
                    PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).ValidLen -= PduInfo.SduLength;
                    /*Update the remaining length of the current Front address*/
                    PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).AvailableLen += PduInfo.SduLength;

                    if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                    {
                        PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                    }
                }
                else if ((uint8)(PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).UpTpReceive & PDUR_CROSSCORE_RX_WAIT_RX_INDICATION_OK) != (uint8)0)
                {

                    PduR_BufferRelease(PathIndex, BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
                    if(PDUR_BUFFER_FLAG_PTR(BufferId,DeepIndex) != NULL_PTR)
                    {
                        PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId,DeepIndex));
                    }
                    PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
                    if(PDUR_BUFFER_FLAG_PTR(BufferId,DeepIndex) != NULL_PTR)
                    {
                        PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId,DeepIndex));
                    }

                    if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                    {
                        PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                    }
                    PduR_UpdateFIFOInfo(BufferId,FALSE);
                    if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                    {
                        PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                    }
                    PduR_ModuleFunctions[DestModuleType].UpTpRxIndicationFunc(DestPduId, E_OK);
                }
                else if((uint8)(PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).UpTpReceive & PDUR_CROSSCORE_RX_WAIT_RX_INDICATION_NOT_OK) != (uint8)0)
                {
                    PduR_BufferRelease(PathIndex, BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
                    if(PDUR_BUFFER_FLAG_PTR(BufferId,PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                    {
                        PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId,PduRBufferQueueInfo[BufferId].FrontPos));
                    }
                    PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
                    if(PDUR_BUFFER_FLAG_PTR(BufferId,PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                    {
                        PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId,PduRBufferQueueInfo[BufferId].FrontPos));
                    }
                    PduR_ModuleFunctions[DestModuleType].UpTpRxIndicationFunc(DestPduId, E_NOT_OK);

                }
                else
                {
                    /*do nothing*/
                }

            }
            else
            {
                /*do nothing*/
            }
        }
    }
}
#ifdef PDUR_SRC_MAINFUNCTION_ENABLE
FUNC(void, PDUR_CODE) PduR_CrossCoreSrcMainfunction
(
    void
)
{
    PduR_BufferIdType BufferId;

    PduR_RoutingPathIdType PathIndex;
    uint8 SrcModuleType;
    PduIdType SrcPduId;
    PduIdType UpperPduId;
    uint8 CoreId = PDUR_GET_CORE_ID();
    PduR_RoutingPathIdType CrossCorePathNum;
    PduR_RoutingPathIdType i;
    PduR_RoutingPathIdType ConfIndex;
    PduLengthType TailDataLen = (PduLengthType)0;
    PduLengthType TempDataLen;
    CrossCorePathNum = PduR_CrossCorePath_Src_Table[CoreId].CrossCorePathNum;

    for(i = (PduR_RoutingPathIdType)0; i < CrossCorePathNum; i++)
    {
        PathIndex = PduR_CrossCorePath_Src_Table[CoreId].CrossCorePathIdx[i];
        /*Get the path in the current core*/
        BufferId = PDUR_ROUTINGPATHINFO(PathIndex).PduRDestPdu.PduRDestTxBufferId;
        SrcModuleType = PDUR_ROUTINGPATHINFO(PathIndex).PduRSrcPdu.PduRSrcModuleType;
        SrcPduId = PDUR_ROUTINGPATHINFO(PathIndex).PduRSrcPdu.PduRSrcPduHandleId;
        UpperPduId = PDUR_ROUTINGPATHINFO(PathIndex).PduRSrcPdu.UpperPduId;
        ConfIndex = PDUR_ROUTINGPATHINFO(PathIndex).PduRDestPdu.PduRDestPduConfIndex;
        if((PDUR_ROUTINGPATHINFO(PathIndex).PduRSrcPdu.PduRSrcPduCore == PDUR_GET_CORE_ID())\
            && (BufferId != PDUR_UNUSED))
        {

            if(PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).UpTpTransmit == PDUR_CROSSCORE_TX_UP_TRANSMITTING)
            {

                PduLengthType availableData;
                PduInfoType CopyTxPduInfo;

                availableData = PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).TotalLen;
                if(availableData>PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).AvailableLen)
                {
                    CopyTxPduInfo.SduLength = PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).AvailableLen;
                }
                else
                {
                    CopyTxPduInfo.SduLength = availableData;
                }
                TempDataLen = CopyTxPduInfo.SduLength;
                TailDataLen = PDUR_BUFFER_INFO(BufferId,PduRBufferQueueInfo[BufferId].RearPos).AllocatedBufferLen - PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).WritePos;
                if(CopyTxPduInfo.SduLength < TailDataLen)
                {
                    /*[- - - 0 1 2 3 -]*/
                    CopyTxPduInfo.SduDataPtr = PduR_Cfg_Buffer[BufferId].PduPtr[PduRBufferQueueInfo[BufferId].RearPos] + PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).WritePos;
                    (void)PduR_ModuleFunctions[SrcModuleType].UpTpCopyTxDataFunc(UpperPduId, &CopyTxPduInfo, NULL_PTR, &availableData);
                    /*Update the write byte address information of the current insertion address*/
                    PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).WritePos += CopyTxPduInfo.SduLength;
                }
                else
                {
                    /*[- - - 0 1 2 3 4]*/
                    CopyTxPduInfo.SduDataPtr = PduR_Cfg_Buffer[BufferId].PduPtr[PduRBufferQueueInfo[BufferId].RearPos] + PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).WritePos;
                    CopyTxPduInfo.SduLength = TailDataLen;
                    (void)PduR_ModuleFunctions[SrcModuleType].UpTpCopyTxDataFunc(UpperPduId, &CopyTxPduInfo, NULL_PTR, &availableData);
                    /*[5 6 - 0 1 2 3 4]*/
                    /*PRQA S 4391 ++*/
                    CopyTxPduInfo.SduDataPtr = (SduDataPtrType)PduR_Cfg_Buffer[BufferId].PduPtr[PduRBufferQueueInfo[BufferId].RearPos];
                    CopyTxPduInfo.SduLength = TempDataLen - TailDataLen;
                    (void)PduR_ModuleFunctions[SrcModuleType].UpTpCopyTxDataFunc(UpperPduId, &CopyTxPduInfo, NULL_PTR, &availableData);
                    /*PRQA S 4391 --*/
                    /*Update the write byte address information of the current insertion address*/
                    PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).WritePos = CopyTxPduInfo.SduLength;
                }

                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos));
                }

                /*Update the stored data length of the current write address*/
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).ValidLen += CopyTxPduInfo.SduLength;
                /*Update the remaining length of the current write address*/
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).AvailableLen -= CopyTxPduInfo.SduLength;
                /*Update the receive length information of the current inserted address*/
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).ReceivedLen += CopyTxPduInfo.SduLength;
                if((uint8)(PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).UpTpTransmit & PDUR_CROSSCORE_TX_LO_TRANSMITTING) == (uint8)0)
                {
                    if((uint8)(PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).UpTpTransmit & PDUR_CROSSCORE_TX_WAIT_LO_TRANSMIT) == (uint8)0)
                    {
                        PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).UpTpTransmit |= PDUR_CROSSCORE_TX_WAIT_LO_TRANSMIT;
                        PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).TxAllowFlag = TRUE;
                    }
                }
                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos));
                }
                if(availableData == (PduLengthType)0)
                {
                    PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).UpTpTransmit &= (uint8)(~PDUR_CROSSCORE_TX_UP_TRANSMITTING);
                }

            }
            else if((uint8)(PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).UpTpTransmit & PDUR_CROSSCORE_TX_WAIT_TX_CONFIRM_OK) != (uint8)0)
            {
                PduR_BufferRelease(PathIndex, BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                }
                PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].FrontPos);

                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                }
                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
                PduR_UpdateFIFOInfo(BufferId,FALSE);
                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
                PduR_ModuleFunctions[SrcModuleType].UpTpTxConfirmationFunc(UpperPduId, E_OK);
                PduR_PathConf[ConfIndex] = TRUE;
            }
            else if((uint8)(PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).UpTpTransmit & PDUR_CROSSCORE_TX_WAIT_TX_CONFIRM_NOT_OK) != (uint8)0)
            {
                PduR_BufferRelease(PathIndex, BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                }
                PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].FrontPos);

                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                }
                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
                PduR_UpdateFIFOInfo(BufferId,FALSE);
                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
                PduR_ModuleFunctions[SrcModuleType].UpTpTxConfirmationFunc(UpperPduId, E_NOT_OK);
                PduR_PathConf[ConfIndex] = TRUE;
            }
            else if((uint8)(PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).UpIfTransmit & PDUR_CROSSCORE_TX_WAIT_TX_CONFIRM_OK) != (uint8)0)
            {
                PduR_BufferRelease(PathIndex, BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                }
                PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].FrontPos);

                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                }
                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
                PduR_UpdateFIFOInfo(BufferId,FALSE);
                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
                PduR_ModuleFunctions[SrcModuleType].UpIfTxConfirmationFunc(UpperPduId, E_OK);
                PduR_PathConf[ConfIndex] = TRUE;
            }
            else if((uint8)(PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).UpIfTransmit & PDUR_CROSSCORE_TX_WAIT_TX_CONFIRM_NOT_OK) != (uint8)0)
            {
                PduR_BufferRelease(PathIndex, BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                }
                PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].FrontPos);

                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                }
                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
                PduR_UpdateFIFOInfo(BufferId,FALSE);
                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
                PduR_ModuleFunctions[SrcModuleType].UpIfTxConfirmationFunc(UpperPduId, E_NOT_OK);
                PduR_PathConf[ConfIndex] = TRUE;
            }
            else
            {
                /*do nothing*/
            }


        }
    }
}
#endif/*PDUR_SRCMAINFUNCTION_ENABLE*/
#endif/*STD_ON == PDUR_MULTICORE_SUPPORT)*/


#endif /*#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)*/



#if(PDUR_MAX_RX_PDU_INFO > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerIfRxIndication
*
* Description:   RxIndication processing of lower interface module
*
* Inputs:        PathId     id of the routing path
*                PduInfoPtr Data info of received data
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 2755 ++*/
STATIC FUNC(void, PDUR_CODE) PduR_LowerIfRxIndication
(
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{

    PduIdType DestPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;
    uint8 DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;
    boolean PduR_CoreMatchFalg = TRUE;
    PduR_RoutingPathIdType ConfIndex = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduConfIndex;
    
#if((STD_ON == PDUR_GW_IF_SUPPORT) || (STD_ON == PDUR_PDU_BUFFER_SUPPORT))
    PduR_BufferIdType BufferId = PDUR_UNUSED;
    PduLengthType DestLength = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestLength;
    PduInfoType CopyPduInfo;
    PduLengthType FrontPos;
    PduLengthType RearPos;
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
#endif
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
    BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
#endif
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
    if(PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduCore != PDUR_GET_CORE_ID())
    {
        PduR_CoreMatchFalg = FALSE;
    }
#endif
    if((NULL_PTR != PduR_ModuleFunctions[DestModuleType].UpIfRxIndicationFunc)\
       && (PduR_CoreMatchFalg == TRUE))
    {
        if(PduR_PathConf[ConfIndex] == FALSE)
        {
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)        
            if(PDUR_UNUSED != BufferId)
            {
                result = PduR_BufferAllocate(PathId, BufferId, PduRBufferQueueInfo[BufferId].RearPos ,PduInfoPtr->SduLength);
                if(BUFREQ_OK == result)
                {
                    /*SWS_PduR_00904*//*SWS_PduR_00902*/
                    if(E_NOT_OK == PduR_InsertQueue(BufferId, PduInfoPtr, PduInfoPtr->SduLength))
                    {
                        PduR_BufferRelease(PathId, BufferId, PduRBufferQueueInfo[BufferId].RearPos);
                        PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].RearPos);
                        PDUR_DET_REPORT_ERROR(PDUR_MODULE_IF_RXINDICATION_APIID, PDUR_E_PDU_INSTANCES_LOST);
                    }
                    else
                    {
                        /*Queue available depth minus 1*/
                        PduR_UpdateFIFOInfo(BufferId, TRUE);
                        /*The data saved this time is complete*/
                        /*Write data to the new write address next time*/
                    }
                }
            }
            else
            {
                PDUR_DET_REPORT_ERROR(PDUR_MODULE_IF_RXINDICATION_APIID, PDUR_E_PDU_INSTANCES_LOST);
            }  
#else
            /*SWS_PduR_00903*/
            PDUR_DET_REPORT_ERROR(PDUR_MODULE_IF_RXINDICATION_APIID, PDUR_E_PDU_INSTANCES_LOST);
#endif
        }
        else
        {
            PduR_PathConf[ConfIndex] = FALSE;
            /*Up modules*/
            /*SWS_PduR_00621 SWS_PduR_00744*//*SWS_PduR_00901*/
            PduR_ModuleFunctions[DestModuleType].UpIfRxIndicationFunc(DestPduId, PduInfoPtr);           
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT) 
            if(PDUR_UNUSED != BufferId)
            { 
                /*SWS_PduR_00905*/
                while (PduRBufferQueueInfo[BufferId].QueueAvailableLen != PDUR_BUFFER_DEPTH(BufferId))
                {
                    PduR_PathConf[ConfIndex] = FALSE;
                    FrontPos = PduRBufferQueueInfo[BufferId].FrontPos;
                    CopyPduInfo.SduDataPtr = NULL_PTR;
                    CopyPduInfo.SduLength = PDUR_BUFFER_INFO(BufferId, FrontPos).ValidLen;
                    if(E_OK == PduR_ExportQueue(BufferId, &CopyPduInfo, CopyPduInfo.SduLength))
                    {
                        PduR_ModuleFunctions[DestModuleType].UpIfRxIndicationFunc(DestPduId, &CopyPduInfo);
                        /*Update the stored data length of the current Front address*/
                        PduR_BufferInit(BufferId, FrontPos); 
                        PduR_UpdateFIFOInfo(BufferId,FALSE);
                        /*The data retrieved this time is complete*/
                        /*Read data to the new Front address next time*/
                    }
                    if(PduRBufferQueueInfo[BufferId].QueueAvailableLen == PDUR_BUFFER_DEPTH(BufferId))
                    {
                        PduR_PathConf[ConfIndex] = TRUE;
                    }
                }
            }
#endif
            PduR_PathConf[ConfIndex] = TRUE;
        }
    }
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
    else if((NULL_PTR != PduR_ModuleFunctions[DestModuleType].UpIfRxIndicationFunc)\
    && (PduR_CoreMatchFalg == FALSE))
    {
        if((PDUR_UNUSED != BufferId) && (PduRBufferQueueInfo[BufferId].QueueAvailableLen != (PduLengthType)0))
        {

            result = PduR_BufferAllocate(PathId, BufferId, PduRBufferQueueInfo[BufferId].RearPos ,PduInfoPtr->SduLength);

            if(BUFREQ_OK == result)
            {
                /*SWS_PduR_00904*//*SWS_PduR_00902*/
                if(E_NOT_OK == PduR_InsertQueue(BufferId, PduInfoPtr, PduInfoPtr->SduLength))
                {
                    PduR_BufferRelease(PathId, BufferId, PduRBufferQueueInfo[BufferId].RearPos);
                    PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].RearPos);
                    PDUR_DET_REPORT_ERROR(PDUR_MODULE_IF_RXINDICATION_APIID, PDUR_E_PDU_INSTANCES_LOST);
                }
                else
                {
                    if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos) != NULL_PTR)
                    {
                        PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos));
                    }

                    /*Update the stored data length of the current write address*/
                    PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).ValidLen += PduInfoPtr->SduLength;
                    /*Update the remaining length of the current write address*/
                    PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).AvailableLen -= PduInfoPtr->SduLength;
                    /*Update the receive length information of the current inserted address*/
                    PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).ReceivedLen += PduInfoPtr->SduLength;
                    
                    if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos) != NULL_PTR)
                    {
                        PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos));
                    }

                    if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                    {
                        PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                    }
                    RearPos = PduRBufferQueueInfo[BufferId].RearPos;
                    PduR_UpdateFIFOInfo(BufferId, TRUE);

                    if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                    {
                        PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                    }
                    PDUR_BUFFER_INFO(BufferId, RearPos).TxAllowFlag = TRUE;
                }
            }
        }
    }
#endif
#if(STD_ON == PDUR_GW_IF_SUPPORT)
    else if((NULL_PTR !=  PduR_ModuleFunctions[DestModuleType].IfTransmitFunc))
    {
        CopyPduInfo.SduDataPtr = PduInfoPtr->SduDataPtr;
        CopyPduInfo.SduLength = PduInfoPtr->SduLength;

#if(STD_ON ==PDUR_METADATA_SUPPORT)
        CopyPduInfo.MetaDataPtr = PduInfoPtr->MetaDataPtr;
#endif

        /*Interface modules*/
        if(PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduDataProvision == PDUR_TRIGGERTRANSMIT)
        {
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
            if(PDUR_UNUSED != BufferId)
            {
                if(PduRBufferQueueInfo[BufferId].QueueAvailableLen != (PduLengthType)0)
                {
                    PduR_IfModuleGwTrigger(BufferId, PathId, &CopyPduInfo);
                }
            }
#endif
        }
        else
        {
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
            /*DIRECT*/
            if(PDUR_UNUSED != BufferId)
            {
                if(PduRBufferQueueInfo[BufferId].QueueAvailableLen != (PduLengthType)0)
                {
                    PduR_IfModuleDirect(BufferId, PathId, &CopyPduInfo);
                }
            }
            else
#endif
            {
                /*SWS_PduR_00783*/
                if(PduInfoPtr->SduLength > DestLength)
                {
                    CopyPduInfo.SduLength = DestLength;
                }
                /*SWS_PduR_00303  SWS_PduR_00256*/
                (void)PduR_ModuleFunctions[DestModuleType].IfTransmitFunc(DestPduId, &CopyPduInfo);
            }   

        }
    }
#endif
    else
    {
    }
}
/*PRQA S 2755 --*/
#endif

#if(PDUR_MAX_TXCONF_PDU > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerIfTxConfirmation
*
* Description:     This function is called by the communication interface module to
*                 confirm the transmit data of an I-PDU.
*
* Inputs:         PathId   Identification of the transmitted path.
*                 ConfId   Identification passed to up layer.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, PDUR_CODE) PduR_LowerIfTxConfirmation
(
    PduR_RoutingPathIdType PathId,
    PduIdType ConfId,
    Std_ReturnType results
)
{
    uint8 SrcModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType;
    boolean PduR_CoreMatchFalg = TRUE;
#if(PDUR_MAX_TX_PDU_INFO > 0)
    PduIdType SrcPduId = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId;
    PduR_MulticastMaskType mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
    PduR_MulticastMaskType ConfirmFinishMask;
#endif
#if(STD_ON == PDUR_GW_IF_SUPPORT)
    PduIdType DestPduId;
    uint8 DestModuleType;
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
    PduR_BufferIdType BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
    PduLengthType FrontPos;
    PduInfoType CopyPduInfo;
    PduR_RoutingPathIdType PathIdInBuffer;
    PduR_RoutingPathIdType ConfIndex = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduConfIndex;
#endif
#endif
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
    if(PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduCore != PDUR_GET_CORE_ID())
    {
        PduR_CoreMatchFalg = FALSE;
    }
#endif
    if((NULL_PTR != PduR_ModuleFunctions[SrcModuleType].UpIfTxConfirmationFunc))
    {
#if(PDUR_MAX_TX_PDU_INFO > 0)
        if(PduR_CoreMatchFalg == TRUE)
        {
            /*Up module*/
            if((PduIdType)PDUR_MAX_TX_PDU_INFO_NUM > (PduIdType)0)
            {
                /*Setting mask as path finished*/
                ConfirmFinishMask = PDUR_TX_PDU_INFO_PTR(SrcPduId).ConfMask;
                TxConfMask[SrcPduId] |= mask;
                if(results == E_NOT_OK)
                {
                    /*Record error path information*/
                    TxErrorMask[SrcPduId] |= mask;
                }
                
                if(TxConfMask[SrcPduId] == ConfirmFinishMask)
                {
                    /*SWS_PduR_00589*//*SWS_PduR_00627*/
                    if(TxErrorMask[SrcPduId] == ConfirmFinishMask)
                    {
                        /*All paths report errors*/
                        PduR_ModuleFunctions[SrcModuleType].UpIfTxConfirmationFunc(ConfId, E_NOT_OK);
                    }
                    else
                    {
                        /*The PDU Router reports E_OK for a Transmit request from an upper layer 
                        if at least one destination lower layer reports E_OK.*/
                        PduR_ModuleFunctions[SrcModuleType].UpIfTxConfirmationFunc(ConfId, E_OK);
                    }
                    TxErrorMask[SrcPduId] = (PduR_MulticastMaskType)0;
                    TxConfMask[SrcPduId] = (PduR_MulticastMaskType)0;
                }
            }
        }
#if((STD_ON == PDUR_MULTICORE_SUPPORT) && (STD_ON == PDUR_PDU_BUFFER_SUPPORT))
        else
        {
            if(E_NOT_OK == results)
            {
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).UpIfTransmit |= PDUR_CROSSCORE_TX_WAIT_TX_CONFIRM_NOT_OK;
            }
            else
            {
                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).UpIfTransmit |= PDUR_CROSSCORE_TX_WAIT_TX_CONFIRM_OK;
            }
        }
#endif
#endif/*#if(PDUR_MAX_TX_PDU_INFO > 0)*/
    }
#if(STD_ON == PDUR_GW_IF_SUPPORT)
    else
    {
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
        if((PDUR_UNUSED != BufferId) \
            && (PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduDataProvision == PDUR_DIRECT))
        {
            /*SWS_PduR_00667*//*SWS_PduR_00784*/
            FrontPos = PduRBufferQueueInfo[BufferId].FrontPos;
            CopyPduInfo.SduDataPtr = NULL_PTR;

            /*FIFO queue is not empty <DstLo>_Transmit shall be called with the oldest I-PDU of the FIFO.*/
            if(E_OK == PduR_ExportQueue(BufferId, &CopyPduInfo, PDUR_BUFFER_INFO(BufferId, FrontPos).ValidLen))
            {
                PduR_BufferRelease(PathId, BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
                PathIdInBuffer = PDUR_BUFFER_INFO(BufferId, FrontPos).PathIdx;
                CopyPduInfo.SduLength = PDUR_BUFFER_INFO(BufferId, FrontPos).ValidLen;
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                }
#endif
                PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                }

                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
#endif
                PduR_UpdateFIFOInfo(BufferId,FALSE);
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
#endif
                DestPduId = PDUR_ROUTINGPATHINFO(PathIdInBuffer).PduRDestPdu.PduRDestPduId;
                DestModuleType = PDUR_ROUTINGPATHINFO(PathIdInBuffer).PduRDestPdu.PduRDestModuleType;
                if(E_NOT_OK == PduR_ModuleFunctions[DestModuleType].IfTransmitFunc(DestPduId, &CopyPduInfo))
                {
                    /*SWS_PduR_00807*/
                    PDUR_DET_REPORT_ERROR(PDUR_MODULE_IF_TXCONFIRMATION_APIID, PDUR_E_PDU_INSTANCES_LOST);
                    /*The PDU Router module shall not retry transmission 
                    if the Communication Interface destination module returns E_NOT_OK 
                    after calling <DstLo>_Transmit.*/
                    /*SWS_PduR_00256*/
                }
            }
            else
            {
                PduR_PathConf[ConfIndex] = TRUE;
            }
        }
        else
        {
            /*SWS_PduR_00640*/
        }
#endif
    }
#endif

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerIfTriggerTransmit
*
* Description:     This function is called by the communication interface module to
*                 confirm the transmit data of an I-PDU.
*
* Inputs:         PathId   Identification of the transmitted path.
*                 ConfId   Identification passed to up layer.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_LowerIfTriggerTransmit
(
    PduR_RoutingPathIdType PathId, 
    PduIdType ConfId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 SrcModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType;
#if(PDUR_MAX_TX_PDU_INFO > 0)
    PduIdType SrcPduId = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId;
    PduR_MulticastMaskType mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
#endif
#if(STD_ON == PDUR_GW_IF_SUPPORT)
#if(PDUR_MAX_NUMOFBUFFER > 0)
    PduR_BufferIdType BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
#endif

    PduLengthType Copylength;
#endif

    if(NULL_PTR != PduR_ModuleFunctions[SrcModuleType].UpIfTriggerTransmitFunc)
    {
        /*SWS_PduR_00430 SWS_PduR_00661*/
        ret = PduR_ModuleFunctions[SrcModuleType].UpIfTriggerTransmitFunc(ConfId, PduInfoPtr);
        if(E_OK != ret)
        {
#if(PDUR_MAX_TX_PDU_INFO > 0)
            TxConfMask[SrcPduId] |= mask;
            TxErrorMask[SrcPduId] |= mask;
#endif
        }
    }
#if(STD_ON == PDUR_GW_IF_SUPPORT)
#if(PDUR_MAX_NUMOFBUFFER > 0)
    else if((PDUR_UNUSED != BufferId)\
            && (PduRBufferQueueInfo[BufferId].QueueAvailableLen != PDUR_BUFFER_DEPTH(BufferId)))
    {

        Copylength = PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).ValidLen;
        /*There is data in Buffer*//*GW, Copy Txbuff to PduInfoPtr*/
        /*SWS_PduR_00306 SWS_PDUR_00819*/
        /*check whether the valid data fits into PduInfoPtr->SduLength*/
        if(Copylength <= PduInfoPtr->SduLength)
        {
            /*Do not remove data after copy*/
            /*SWS_PduR_00666*/
            ret = PduR_ExportQueue(BufferId, PduInfoPtr, Copylength);
            PduR_BufferRelease(PathId, BufferId, PduRBufferQueueInfo[BufferId].FrontPos);

            PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
            if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
            {
                PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
            }

            if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
            {
                PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
            }
#endif
            PduR_UpdateFIFOInfo(BufferId,FALSE);
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
            if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
            {
                PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
            }
#endif

        }
        else
        {
            /*SWS_PduR_00662*/
            ret = E_NOT_OK;
        }

    }
#endif
#endif
    else
    {
    }
    return ret;
}
#endif/*#if(PDUR_MAX_TXCONF_PDU > 0)*/

#if(PDUR_MAX_RX_PDU_INFO > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerIfMultiRxIndication
*
* Description:   RxIndication processing of lower interface module
*
* Inputs:        PathId     id of the routing path
*                PduInfoPtr Data info of received data
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, PDUR_CODE) PduR_LowerIfMultiRxIndication
(
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{
    PduR_RoutingPathIdType i;
    PduR_RoutingPathIdType PathId;

    /*SWS_PduR_00164*/
    for(i = (PduR_RoutingPathIdType)0; i < pRxPduInfo->NumPaths; i++)
    {
        PathId = pRxPduInfo->PathIdx[i];
        if(PduR_RoutingPathEnbale[PathId] == TRUE)
        {
            PduR_LowerIfRxIndication(PathId, PduInfoPtr);
        }
    }
}
#endif
#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

/*******************************************************************************
*  PUBLIC Functions define
*******************************************************************************/
#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

#if(PDUR_MAX_TX_PDU_INFO > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_UpTransmit
*
* Description:   Transmit of up module
*
* Inputs:        idx id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_UpTransmit
(
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) info
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduIdType DestPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
    PduIdType UpperPduId = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.UpperPduId;
#endif
    uint8 DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
    uint8 SrcModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType;
#endif
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
    PduR_BufferIdType BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
    BufReq_ReturnType result;
    PduLengthType RearPos;
#endif
    /*SWS_PduR_00629 SWS_PduR_00745 SWS_PduR_00717*/
    if(PduR_RoutingPathEnbale[PathId] == TRUE)
    {
        if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].IfTransmitFunc)
        {
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
            if(PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduCore != PDUR_GET_CORE_ID())
            {
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
                if(PDUR_UNUSED != BufferId)
                {
                    result = PduR_BufferAllocate(PathId, BufferId, PduRBufferQueueInfo[BufferId].RearPos ,info->SduLength);

                    if(BUFREQ_OK == result)
                    {
                        /*SWS_PduR_00904*//*SWS_PduR_00902*/
                        if(E_NOT_OK == PduR_InsertQueue(BufferId, info, info->SduLength))
                        {
                            PduR_BufferRelease(PathId, BufferId, PduRBufferQueueInfo[BufferId].RearPos);
                            if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos) != NULL_PTR)
                            {
                                PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos));
                            }
                            PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].RearPos);
                            if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos) != NULL_PTR)
                            {
                                PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos));
                            }                            
                            PDUR_DET_REPORT_ERROR(PDUR_MODULE_IF_RXINDICATION_APIID, PDUR_E_PDU_INSTANCES_LOST);
                        }
                        else
                        {
                            if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos) != NULL_PTR)
                            {
                                PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos));
                            }

                            /*Update the stored data length of the current write address*/
                            PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).ValidLen += info->SduLength;
                            /*Update the remaining length of the current write address*/
                            PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).AvailableLen -= info->SduLength;
                            /*Update the receive length information of the current inserted address*/
                            PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).ReceivedLen += info->SduLength;
                            
                            
                            if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos) != NULL_PTR)
                            {
                                PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].RearPos));
                            }

                            if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                            {
                                PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                            }
                            RearPos = PduRBufferQueueInfo[BufferId].RearPos;
                            PduR_UpdateFIFOInfo(BufferId, TRUE);
                            if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                            {
                                PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                            }
                            PDUR_BUFFER_INFO(BufferId, RearPos).TxAllowFlag = TRUE;
                            ret = E_OK;
                        }
                    }
                }
#endif/*#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)*/
            }
            else
#endif
            {
                /*Interface module*/
                /*SWS_PduR_00625 SWS_PduR_00626 SWS_PduR_00432*/
                ret = PduR_ModuleFunctions[DestModuleType].IfTransmitFunc(DestPduId, info);
            }
        }
        else if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].TpTransmitFunc)
        {
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
            if(PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduCore != PDUR_GET_CORE_ID())
            {
                if(PDUR_UNUSED != BufferId)
                {

                    result = PduR_BufferAllocate(PathId, BufferId, PduRBufferQueueInfo[BufferId].RearPos ,info->SduLength);

                    if(BUFREQ_OK == result)
                    {

                        
                        PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).TotalLen = info->SduLength;
                        PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).UpTpTransmit |= PDUR_CROSSCORE_TX_UP_TRANSMITTING;
                        ret = E_OK;

                    }
                    else
                    {
                        PduR_ModuleFunctions[SrcModuleType].UpTpTxConfirmationFunc(UpperPduId, E_NOT_OK);
                        PDUR_DET_REPORT_ERROR(PDUR_MODULE_IF_RXINDICATION_APIID, PDUR_E_PDU_INSTANCES_LOST);
                    }
                }
            }
            else
#endif
            {
                /*Tp module*/
                /*SWS_PduR_00634*/
                ret = PduR_ModuleFunctions[DestModuleType].TpTransmitFunc(DestPduId, info);
            }
        }
        else
        {
            /* Intentionally Empty */
        }
    }
    return ret;
}
#endif/*#if(PDUR_MAX_TX_PDU_INFO > 0)*/

#if(PDUR_MAX_TX_PDU_INFO > 0 || STD_ON == PDUR_GW_TP_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_UpCancelTransmit
*
* Description:   CancelTransmit of up module
*
* Inputs:        idx id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_UpCancelTransmit
(
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduIdType DstPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;
    uint8 DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;


    /*SWS_PduR_00710 SWS_PduR_00717*/
    if(PduR_RoutingPathEnbale[PathId] == TRUE)
    {
        if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].IfCancelTransmitFunc)
        {
            /*Interface module*/
            /*SWS_PduR_00721 SWS_PduR_00723 SWS_PduR_00700*/
            ret = PduR_ModuleFunctions[DestModuleType].IfCancelTransmitFunc(DstPduId);
        }
        else if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].TpCancelTransmitFunc)
        {
            /*Tp module*/
            /*SWS_PduR_00722 SWS_PduR_00724*/
            ret = PduR_ModuleFunctions[DestModuleType].TpCancelTransmitFunc(DstPduId);
        }
        else
        {
            /* Intentionally Empty */
        }
    }

    return ret;
}
#endif/*#if(PDUR_MAX_TX_PDU_INFO > 0||STD_ON == PDUR_GW_TP_SUPPORT)*/

#if(PDUR_MAX_CANCELRX_PDU > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_UpCancelReceive
*
* Description:   CancelReceive of up module
*
* Inputs:        idx id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, PDUR_CODE) PduR_UpCancelReceive
(
    CONST(PduR_RoutingPathIdType, PDUR_CONST) PathId
)
{
    Std_ReturnType ret = E_NOT_OK;
    /*Tp CancelReceive id same as rx id*/
    PduIdType SrcPduId = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId;
    uint8 SrcModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType;

    /*SWS_PduR_00726 SWS_PduR_00717*/
    if((PduR_RoutingPathEnbale[PathId] == TRUE)\
        && (NULL_PTR != PduR_ModuleFunctions[SrcModuleType].TpCancelReceiveFunc))
    {
        /*SWS_PduR_00727 SWS_PduR_00732*/
        ret = PduR_ModuleFunctions[SrcModuleType].TpCancelReceiveFunc(SrcPduId);
    }


    return ret;
}
#endif /*#if(PDUR_MAX_CANCELRX_PDU > 0)*/

#if(PDUR_MAX_RX_PDU_INFO > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerTpStartOfReception
*
* Description:   StartOfReception processing of lower Tp module
*
* Inputs:        PathId id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LowerTpStartOfReception
(
    PduR_RoutingPathIdType PathId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    uint8 DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;
    PduIdType DestPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
    PduR_BufferIdType BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;

#endif

    if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].UpTpStartOfReceptionFunc)
    {
#if(PDUR_MULTICORE_SUPPORT ==STD_ON)
        if(PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduCore != PDUR_GET_CORE_ID())
        {
            PduLengthType RearPos = PduRBufferQueueInfo[BufferId].RearPos;
            PduLengthType RearPosCount = PduRBufferQueueInfo[BufferId].QueueAvailableLen;
            if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
            {
                PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
            }
            while (PDUR_BUFFER_IDLE != PDUR_BUFFER_INFO(BufferId, RearPos).BufState)
            {
                if(RearPosCount == (PduLengthType)0)
                {
                    RearPosCount = (PduLengthType)0xFFFF;
                    break;
                }
                else
                {
                    /*SWS_PduR_00832*/
                    RearPosCount--;
                    RearPos++;
                    if(RearPos == PDUR_BUFFER_DEPTH(BufferId))
                    {
                        RearPos = (PduLengthType)0;
                    }
                }
            }
            if(RearPosCount != (PduLengthType)0xFFFF)
            {
                PDUR_BUFFER_INFO(BufferId, RearPos).BufState = PDUR_BUFFER_RECEIVING;
            }

            if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
            {
                PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
            }

        
            if(RearPosCount != (PduLengthType)0xFFFF)
            {
                if(PDUR_BUFFER_INFO(BufferId, RearPos).AvailableLen < info->SduLength)
                {
                    /*SWS_PduR_00799*/
                    result = BUFREQ_E_OVFL;
                }
                else
                {
                    PDUR_BUFFER_INFO(BufferId, RearPos).PathIdx = PathId;



                    result = PduR_BufferAllocate(PathId, BufferId, RearPos,TpSduLength);



                    if (result == BUFREQ_OK)
                    {
                        
                        PDUR_BUFFER_INFO(BufferId, RearPos).BufState = PDUR_BUFFER_RECEIVING;
                        *bufferSizePtr = PDUR_BUFFER_INFO(BufferId, RearPos).AvailableLen;
                        PDUR_BUFFER_INFO(BufferId, RearPos).TotalLen = TpSduLength;
                    }
                }
            }
        }
        else
#endif
        {
            /*Up modules*/
            /*SWS_PduR_00549 SWS_PduR_00623*//*SWS_PduR_00821*/
            result = PduR_ModuleFunctions[DestModuleType].UpTpStartOfReceptionFunc(DestPduId, info, TpSduLength, bufferSizePtr);
        }
    }
#if(STD_ON == PDUR_GW_TP_SUPPORT)
#if(PDUR_MAX_NUMOFBUFFER > 0)
    else if(PDUR_UNUSED != BufferId)
    {
        /*Tp modules*/
        result = PduR_TpGWStartOfReception(BufferId, PathId, info, TpSduLength, bufferSizePtr);        
    }
#endif
#endif
    else
    {
        /* Intentionally Empty */
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerTpCopyRxData
*
* Description:   CopyRxData processing of lower Tp module
*
* Inputs:        PathId id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LowerTpCopyRxData
(
    PduR_RoutingPathIdType PathId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    uint8 DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;
    PduIdType DestPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;
#if((STD_ON == PDUR_GW_TP_SUPPORT) || (PDUR_MULTICORE_SUPPORT ==STD_ON))
    PduR_BufferIdType BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
    PduLengthType RearPos;
#endif

    if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].UpTpCopyRxDataFunc)
    {
#if(PDUR_MULTICORE_SUPPORT ==STD_ON)
        if(PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduCore != PDUR_GET_CORE_ID())
        {
            RearPos = PduRBufferQueueInfo[BufferId].RearPos;
            if(E_OK != PduR_InsertQueue(BufferId, info, info->SduLength))
            {
                /*Cancel transport*//*The available length of the Buffer is less than the storage length*/
                /*SWS_PduR_00687*/
                result = BUFREQ_E_NOT_OK;
            }
            else
            {

                result = BUFREQ_OK;
                if(PDUR_BUFFER_FLAG_PTR(BufferId,RearPos) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId,RearPos));
                }

                /*Update the stored data length of the current write address*/
                PDUR_BUFFER_INFO(BufferId, RearPos).ValidLen += info->SduLength;
                /*Update the remaining length of the current write address*/
                PDUR_BUFFER_INFO(BufferId, RearPos).AvailableLen -= info->SduLength;
                /*Update the receive length information of the current inserted address*/
                PDUR_BUFFER_INFO(BufferId, RearPos).ReceivedLen += info->SduLength;
                /*Successfully Enqueue*/
                *bufferSizePtr = PDUR_BUFFER_INFO(BufferId, RearPos).AvailableLen;

                if(PDUR_BUFFER_FLAG_PTR(BufferId,RearPos) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId,RearPos));
                }

                if((uint8)(PDUR_BUFFER_INFO(BufferId, RearPos).UpTpReceive & PDUR_CROSSCORE_RX_WAIT_UP_RECEIVE) == (uint8)0)
                {
                    if((uint8)(PDUR_BUFFER_INFO(BufferId, RearPos).UpTpReceive & PDUR_CROSSCORE_RX_UP_RECEIVING) == (uint8)0)
                    {
                        PDUR_BUFFER_INFO(BufferId, RearPos).UpTpReceive |= PDUR_CROSSCORE_RX_WAIT_UP_RECEIVE;
                        PDUR_BUFFER_INFO(BufferId, RearPos).TxAllowFlag = TRUE;
                    }
                }
            }

        }
        else
#endif
        {
            /*Up modules*/
            /*SWS_PduR_00428*/
            result = PduR_ModuleFunctions[DestModuleType].UpTpCopyRxDataFunc(DestPduId, info, bufferSizePtr);
        }
    }
#if(STD_ON == PDUR_GW_TP_SUPPORT)
#if(PDUR_MAX_NUMOFBUFFER > 0)
    else if((PDUR_UNUSED == (PduIdType)BufferId))
    {
        /*No buffer configured, do not continue gateway operation*/
    }
    else if(TRUE == PduR_MatchPos(PathId, BufferId))
    {
        RearPos = PduRBufferQueueInfo[BufferId].RearPos;
        if((uint8)0 != (uint8)(PDUR_BUFFER_INFO(BufferId, RearPos).BufState & PDUR_BUFFER_RECEIVING))
        {
            /*The current stored Buffer is in receive state or on-the-fly gatewaying*/
            if((PduLengthType)0 == info->SduLength)
            {
                /*SWS_PduR_00740*/
                *bufferSizePtr = PDUR_BUFFER_INFO(BufferId, RearPos).AvailableLen;
                result = BUFREQ_OK;
            }
            else
            {
                result = PduR_TpGWCopyRxData(BufferId, PathId, info, bufferSizePtr);
            }
        }  
    }
#endif
#endif
    else
    {
        /* Intentionally Empty or StartOfReception never Called, Non compliant with the process*/
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerTpRxIndication
*
* Description:   RxIndication processing of lower Tp module
*
* Inputs:        PathId id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, PDUR_CODE) PduR_LowerTpRxIndication
(
    PduR_RoutingPathIdType PathId,
    Std_ReturnType result
)
{
    uint8 DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;
    PduIdType DestPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;
#if((STD_ON == PDUR_GW_TP_SUPPORT) || (PDUR_MULTICORE_SUPPORT ==STD_ON))
    PduR_BufferIdType BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
    uint16 PduRTpThreshold = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRTpThreshold;
    PduLengthType RearPos;
    PduInfoType TxPduInfo;
    PduLengthType FrontPos;
    PduLengthType ReadPos;
    Std_ReturnType Txret = E_OK;
    PduR_RoutingPathIdType ConfIndex = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduConfIndex;
#endif

    if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].UpTpRxIndicationFunc)
    {
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
        if(PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduCore != PDUR_GET_CORE_ID())
        {
            RearPos = PduRBufferQueueInfo[BufferId].RearPos;
            if(result == E_NOT_OK)
            {
                PDUR_BUFFER_INFO(BufferId, RearPos).UpTpReceive |= PDUR_CROSSCORE_RX_WAIT_RX_INDICATION_NOT_OK;

                PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].RearPos).TxAllowFlag = TRUE;
            }
            else
            {
                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
                PduR_UpdateFIFOInfo(BufferId, TRUE);

                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
                PDUR_BUFFER_INFO(BufferId, RearPos).UpTpReceive |= PDUR_CROSSCORE_RX_WAIT_RX_INDICATION_OK;
                PDUR_BUFFER_INFO(BufferId, RearPos).TxAllowFlag = TRUE;

            }
        }
        else
#endif
        {
            /*Up modules*/
            /*SWS_PduR_00429 SWS_PduR_00207*/
            PduR_ModuleFunctions[DestModuleType].UpTpRxIndicationFunc(DestPduId, result);
        }
    }
#if(STD_ON == PDUR_GW_TP_SUPPORT)
#if(PDUR_MAX_NUMOFBUFFER > 0)
    else if((PDUR_UNUSED == (PduIdType)BufferId))
    {
        /*No buffer configured, do not continue gateway operation*/
    }
    else if(TRUE == PduR_MatchPos(PathId, BufferId))
    {
        RearPos = PduRBufferQueueInfo[BufferId].RearPos;
        /*GW*/
        if(result == E_NOT_OK)
        {
            /*SWS_PduR_00689*/
            if(((uint8)0 != (uint8)(PDUR_BUFFER_INFO(BufferId, RearPos).BufState & PDUR_BUFFER_RECEIVING)) \
                && ((uint8)0 == (uint8)(PDUR_BUFFER_INFO(BufferId, RearPos).BufState & PDUR_BUFFER_TRANSMITING)))
            {
#if(STD_ON == PDUR_TEST_ENABLE)
                /*ErrorType 7*/
                ErrorInfo[ErrorCount].ErrorType = 7;
                ErrorInfo[ErrorCount].ErrorBufferId = BufferId;
                ErrorInfo[ErrorCount].ErrorBufferInfo = PDUR_BUFFER_INFO(BufferId, RearPos);
                ErrorInfo[ErrorCount].ErrorBufferQueueInfo = PduRBufferQueueInfo[BufferId];
                ErrorInfo[ErrorCount].BufferPoolUsage = PduR_BufferPoolSet[PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PdurDestTxBufferPoolId].BufferInUse[0];

                Bsw_MemCpy(ErrorInfo[ErrorCount].PduContent, (uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[RearPos]), 5);
                PduR_SendErrorInfo();
                ErrorCount++;
                if(ErrorCount == 20)
                {
                    ErrorCount = 0;
                }
#endif

                PduR_BufferRelease(PathId, BufferId, RearPos);
                PduR_BufferInit(BufferId, RearPos);
            }
            else if((uint8)0 != (uint8)(PDUR_BUFFER_INFO(BufferId, RearPos).BufState & PDUR_BUFFER_TRANSMITING))
            {
                PDUR_BUFFER_INFO(BufferId, RearPos).RxFail = (uint8)1; 
#if(STD_ON == PDUR_TEST_ENABLE)
                /*ErrorType 8*/
                ErrorInfo[ErrorCount].ErrorType = 8;
                ErrorInfo[ErrorCount].ErrorBufferId = BufferId;
                ErrorInfo[ErrorCount].ErrorBufferInfo = PDUR_BUFFER_INFO(BufferId, RearPos);
                ErrorInfo[ErrorCount].ErrorBufferQueueInfo = PduRBufferQueueInfo[BufferId];
                ErrorInfo[ErrorCount].BufferPoolUsage = PduR_BufferPoolSet[PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PdurDestTxBufferPoolId].BufferInUse[0];
                Bsw_MemCpy(ErrorInfo[ErrorCount].PduContent, (uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[RearPos]), 5);
                PduR_SendErrorInfo();
                ErrorCount++;
                if(ErrorCount == 20)
                {
                    ErrorCount = 0;
                }
#endif

#if(STD_ON == PDUR_MULTICORE_SUPPORT)

                if(PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduCore != PDUR_GET_CORE_ID())
                {
                    PDUR_BUFFER_INFO(BufferId, RearPos).UpTpTransmit |= PDUR_CROSSCORE_TX_WAIT_CANCEL_TRANSMIT;
                    PduR_BufferRelease(PathId, BufferId, RearPos);

                    if(PDUR_BUFFER_FLAG_PTR(BufferId, RearPos) != NULL_PTR)
                    {
                        PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, RearPos));
                    }

                    PduR_BufferInit(BufferId, RearPos);
                    if(PDUR_BUFFER_FLAG_PTR(BufferId, RearPos) != NULL_PTR)
                    {
                        PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, RearPos));
                    }
                }
                else
#endif
                {
                    (void)PduR_UpCancelTransmit(PathId);
                }

            }
            else
            {
                /*do nothing*/
            }


        }
        else if((uint8)0 != (uint8)(PDUR_BUFFER_INFO(BufferId, RearPos).BufState & PDUR_BUFFER_RECEIVING))
        {
            /*Clear receiving flag*/
            PDUR_BUFFER_INFO(BufferId, RearPos).BufState &= (uint8)(~PDUR_BUFFER_RECEIVING);
            PDUR_BUFFER_INFO(BufferId, RearPos).BufState |= PDUR_BUFFER_WAIT_TXCONFIRM;
            if((PDUR_BUFFER_INFO(BufferId, RearPos).ReceivedLen < (PduLengthType)PduRTpThreshold))
            {
                /*Never getting above the threshold before, start now*/
#if(STD_ON == PDUR_MULTICORE_SUPPORT)

                if(PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduCore != PDUR_GET_CORE_ID())
                {
                    /*do nothing*/
                }
                else
#endif
                if(PduR_PathConf[ConfIndex] == TRUE)
                {
                    /*SWS_PDUR_00808*/
                    TxPduInfo.SduLength = PDUR_BUFFER_INFO(BufferId, RearPos).ValidLen;
                    /*!!!CAUTION!!! TpTransmitFunc must not read data for now*/
                    FrontPos = PduRBufferQueueInfo[BufferId].FrontPos;
                    ReadPos = PDUR_BUFFER_INFO(BufferId, FrontPos).ReadPos;
                    TxPduInfo.SduDataPtr = (uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[FrontPos])+ReadPos;

                    /*SWS_PDUR_00551*//*If result is E_OK, The <DstLoTp>_Transmit shall be called*/
                    if(E_OK == PduR_ModuleFunctions[DestModuleType].TpTransmitFunc(DestPduId, &TxPduInfo))
                    {

                        PduR_PathConf[ConfIndex] = FALSE;
                        PDUR_BUFFER_INFO(BufferId, RearPos).BufState |= PDUR_BUFFER_TRANSMITING;                           
                    }
                    else
                    {
                        Txret = E_NOT_OK;
#if(STD_ON == PDUR_TEST_ENABLE)
                        /*ErrorType 9*/
                        ErrorInfo[ErrorCount].ErrorType = 9;
                        ErrorInfo[ErrorCount].ErrorBufferId = BufferId;
                        ErrorInfo[ErrorCount].ErrorBufferInfo = PDUR_BUFFER_INFO(BufferId, RearPos);
                        ErrorInfo[ErrorCount].ErrorBufferQueueInfo = PduRBufferQueueInfo[BufferId];
                        ErrorInfo[ErrorCount].BufferPoolUsage = PduR_BufferPoolSet[PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PdurDestTxBufferPoolId].BufferInUse[0];
                        Bsw_MemCpy(ErrorInfo[ErrorCount].PduContent, (uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[RearPos]), 5);
                        PduR_SendErrorInfo();
                        ErrorCount++;
                        if(ErrorCount == 20)
                        {
                            ErrorCount = 0;
                        }
#endif
                    }
                }
                else
                {
                    /*do nothing*/
                }

            }
            else
            {
                /*TpTransmitFunc has been called*/
            }
            if(Txret == E_OK)
            {
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
#endif
                RearPos = PduRBufferQueueInfo[BufferId].RearPos;
                PduR_UpdateFIFOInfo(BufferId, TRUE);
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
                if(PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduCore != PDUR_GET_CORE_ID())
                {
                    PDUR_BUFFER_INFO(BufferId, RearPos).TxAllowFlag = TRUE;

                }
#endif
            }
            else
            {
                /*SWS_PDUR_00807*/
                PduR_BufferRelease(PathId, BufferId, RearPos);
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                if(PDUR_BUFFER_FLAG_PTR(BufferId, RearPos) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, RearPos));
                }
#endif
                PduR_BufferInit(BufferId, RearPos);
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                if(PDUR_BUFFER_FLAG_PTR(BufferId, RearPos) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, RearPos));
                }
#endif

                PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_RXINDICATION_APIID, PDUR_E_PDU_INSTANCES_LOST);
            }
            
        }
        else
        {
            /*StartOfReception never Called, Non compliant with the process*/
        }
    }
#endif/*#if(PDUR_MAX_NUMOFBUFFER > 0)*/
#endif/*#if(STD_ON == PDUR_GW_TP_SUPPORT)*/
    else
    {
        /* Intentionally Empty */
    }

}
#endif

#if(PDUR_MAX_TXCONF_PDU > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerTpCopyTxData
*
* Description:   CopyTxData of lower tp module
*
* Inputs:        pRoutPath pointer to the routing path
*                info infomation of rx pdu
*
* Outputs:       availableDataPtr pointer to buffersize
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LowerTpCopyTxData
(
    PduR_RoutingPathIdType PathId,
    PduIdType ConfId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    uint8 SrcModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType;
#if(PDUR_MAX_TX_PDU_INFO > 0)
    PduR_MulticastMaskType mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
    PduIdType TxPduId = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId;
    RetryInfoType PduRRetry;
    PduR_MulticastMaskType CopyFinishMask;
#endif
#if((STD_ON == PDUR_GW_TP_SUPPORT) || (PDUR_MULTICORE_SUPPORT ==STD_ON))
    PduR_BufferIdType BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
    PduLengthType FrontPos;
    PduInfoType Pinfo;
#endif
    (void)retry;
    if(NULL_PTR != PduR_ModuleFunctions[SrcModuleType].UpTpCopyTxDataFunc)
    {
#if(PDUR_MAX_TX_PDU_INFO > 0)
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
        if(PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduCore != PDUR_GET_CORE_ID())
        {
            FrontPos = PduRBufferQueueInfo[BufferId].FrontPos;
            Pinfo.SduDataPtr = info->SduDataPtr;

            if(E_OK == PduR_ExportQueue(BufferId, &Pinfo, info->SduLength))
            {
                if(PDUR_BUFFER_FLAG_PTR(BufferId, FrontPos) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, FrontPos));
                }
                /*SWS_PduR_00696*/
                PDUR_BUFFER_INFO(BufferId, FrontPos).ValidLen -= info->SduLength;
                /*Update the remaining length of the current Front address*/
                PDUR_BUFFER_INFO(BufferId, FrontPos).AvailableLen += info->SduLength;

                if(PDUR_BUFFER_FLAG_PTR(BufferId, FrontPos) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, FrontPos));
                }
                result = BUFREQ_OK;
            }
        }
        else
#endif
        {
        
            /*Up module*/
            /*PRQA S 2742 ++*/
            /*
            Postbuild,PDUR_MAX_TX_PDU_INFO_NUM may be 0
            */
            
            if((PduIdType)PDUR_MAX_TX_PDU_INFO_NUM == (PduIdType)0)
            {
                /*Postbuild, Path not configured*/
                result = BUFREQ_E_NOT_OK;
            }
            /*PRQA S 2742 --*/
            else if((PduR_MulticastMaskType)0 != (PduR_MulticastMaskType)(TxConfMask[TxPduId] & mask))
            {
                /*already copied or error occurred*/
                result = BUFREQ_E_NOT_OK;
            }
            else
            {
                CopyFinishMask = PDUR_TX_PDU_INFO_PTR(TxPduId).ConfMask;
                if(TxErrorMask[TxPduId] == TxConfMask[TxPduId])
                {
                    /*First copy*/
                    /*SWS_PduR_00631*/
                    PduRRetry.TpDataState = TP_CONFPENDING;
                    PduR_TpTxAvailableLength[TxPduId] = (PduLengthType)0;
                }
                else
                {
                    /*Assume that every copy use the same SduLength*/
                    /*SWS_PduR_00632*/
                    PduRRetry.TpDataState = TP_DATARETRY;
                    PduRRetry.TxTpDataCnt = info->SduLength;
                    /*SWS_PduR_00872*/
                    if(info->SduLength > PduR_TpTxAvailableLength[TxPduId])
                    {
                        return BUFREQ_E_BUSY;
                    }
                }

                TxConfMask[TxPduId] |= mask;
                if(TxConfMask[TxPduId] == CopyFinishMask)
                {
                    /*The last copy*/
                    PduRRetry.TpDataState = TP_DATACONF;
                }
                /*SWS_PduR_00299 SWS_PduR_00676*/
                result = PduR_ModuleFunctions[SrcModuleType].UpTpCopyTxDataFunc(ConfId, info, &PduRRetry, availableDataPtr);
                PduR_TpTxAvailableLength[TxPduId] = *availableDataPtr;
                if(BUFREQ_E_NOT_OK == result)
                {
                    /*Record this error, and not processing this path any more*/
                    TxErrorMask[TxPduId] |= mask;
                }
                else if(BUFREQ_E_BUSY == result)
                {
                    /*Clear TxConfMask to recopy*/
                    TxConfMask[TxPduId] &= (PduR_MulticastMaskType)(~mask);
                }
                else
                {
                    /*result == E_OK, Do Nothing*/
                }
                /*The last copy of this piece of data, clear successed paths*/
                if(TxConfMask[TxPduId] == CopyFinishMask)
                {
                    TxConfMask[TxPduId] = TxErrorMask[TxPduId];
                }
            }
        }
#endif
    }
#if(STD_ON == PDUR_GW_TP_SUPPORT)
#if(PDUR_MAX_NUMOFBUFFER > 0)
    else if(PDUR_UNUSED != BufferId)
    {
        FrontPos = PduRBufferQueueInfo[BufferId].FrontPos;

        /*SWS_PduR_00707 SWS_PduR_00696*/
        if((uint8)0 != (uint8)(PDUR_BUFFER_INFO(BufferId, FrontPos).BufState & PDUR_BUFFER_TRANSMITING))
        {
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
            if((uint8)(PDUR_BUFFER_INFO(BufferId, FrontPos).UpTpTransmit & PDUR_CROSSCORE_TX_WAIT_CANCEL_TRANSMIT) != (uint8)0)
            {
                result = BUFREQ_E_NOT_OK;
            }
            else
#endif
            {
                SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_2();
                Pinfo.SduDataPtr = info->SduDataPtr;
                if(E_OK == PduR_ExportQueue(BufferId, &Pinfo, info->SduLength))
                {
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                    if(PDUR_BUFFER_FLAG_PTR(BufferId, FrontPos) != NULL_PTR)
                    {
                        PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, FrontPos));
                    }
#endif
                    /*SWS_PduR_00696*/
                    PDUR_BUFFER_INFO(BufferId, FrontPos).ValidLen -= info->SduLength;
                    /*Update the remaining length of the current Front address*/
                    PDUR_BUFFER_INFO(BufferId, FrontPos).AvailableLen += info->SduLength;
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                    if(PDUR_BUFFER_FLAG_PTR(BufferId, FrontPos) != NULL_PTR)
                    {
                        PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, FrontPos));
                    }
#endif

                    result = BUFREQ_OK;
                }
                else
                {
#if(STD_ON == PDUR_TEST_ENABLE)
                    /*ErrorType 10*/
                    ErrorInfo[ErrorCount].ErrorType = 10;
                    ErrorInfo[ErrorCount].ErrorBufferId = BufferId;
                    ErrorInfo[ErrorCount].ErrorBufferInfo = PDUR_BUFFER_INFO(BufferId, FrontPos);
                    ErrorInfo[ErrorCount].ErrorBufferQueueInfo = PduRBufferQueueInfo[BufferId];
                    ErrorInfo[ErrorCount].BufferPoolUsage = PduR_BufferPoolSet[PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PdurDestTxBufferPoolId].BufferInUse[0];
                    Bsw_MemCpy(ErrorInfo[ErrorCount].PduContent, (uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[FrontPos]), 5);
                    PduR_SendErrorInfo();
                    ErrorCount++;
                    if(ErrorCount == 20)
                    {
                        ErrorCount = 0;
                    }
#endif
                    /*SWS_PduR_00697*//*SWS_PDUR_00814*/
                    result = BUFREQ_E_BUSY;
                }
                *availableDataPtr = PDUR_BUFFER_INFO(BufferId, FrontPos).ValidLen;
                SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_2();
            }
        }
        else
        {
#if(STD_ON == PDUR_TEST_ENABLE)
            /*ErrorType 11*/
            ErrorInfo[ErrorCount].ErrorType = 11;
            ErrorInfo[ErrorCount].ErrorBufferId = BufferId;
            ErrorInfo[ErrorCount].ErrorBufferInfo = PDUR_BUFFER_INFO(BufferId, FrontPos);
            ErrorInfo[ErrorCount].ErrorBufferQueueInfo = PduRBufferQueueInfo[BufferId];
            ErrorInfo[ErrorCount].BufferPoolUsage = PduR_BufferPoolSet[PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PdurDestTxBufferPoolId].BufferInUse[0];
            Bsw_MemCpy(ErrorInfo[ErrorCount].PduContent, (uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[FrontPos]), 5);
            PduR_SendErrorInfo();
            ErrorCount++;
            if(ErrorCount == 20)
            {
                ErrorCount = 0;
            }
#endif
            /*PduR_BufferInit(BufferId, FrontPos);*/
            result = BUFREQ_E_NOT_OK;
        }
    }
#endif
#endif
    else
    {
        /* Intentionally Empty */
    }

    return result;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerTpTxConfirmation
*
* Description:   TxConfirmation of lower tp module
*
* Inputs:        pRoutPath pointer to the routing path
*                info infomation of rx pdu
*
* Outputs:       availableDataPtr pointer to buffersize
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(void, PDUR_CODE) PduR_LowerTpTxConfirmation
(
    PduR_RoutingPathIdType PathId,
    PduIdType ConfId,
    Std_ReturnType Result
)
{

    uint8 SrcModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcModuleType;
#if(PDUR_MAX_TX_PDU_INFO > 0)
    PduIdType TxPduId = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId;
    PduR_MulticastMaskType mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;

    PduR_MulticastMaskType ConfirmFinishMask;
#endif
#if((STD_ON == PDUR_GW_TP_SUPPORT) || (PDUR_MULTICORE_SUPPORT ==STD_ON))
    PduR_BufferIdType BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
    PduInfoType TxPduInfo;
    PduR_RoutingPathIdType PathIdx;
    uint16 PduRTpThreshold;
    PduLengthType FrontPos;
    PduLengthType ReadPos;
    PduLengthType ReceivedLen;
    uint8 DestModuleType;
    PduIdType DestPduId;
    PduR_RoutingPathIdType ConfIndex = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduConfIndex;
#endif

    if(NULL_PTR != PduR_ModuleFunctions[SrcModuleType].UpTpTxConfirmationFunc)
    {
#if(PDUR_MAX_TX_PDU_INFO > 0)
        if((PduIdType)PDUR_MAX_TX_PDU_INFO_NUM > (PduIdType)0)
        {
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
            if(PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduCore != PDUR_GET_CORE_ID())
            {

                if(E_NOT_OK == Result)
                {
                    PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).UpTpTransmit |= PDUR_CROSSCORE_TX_WAIT_TX_CONFIRM_NOT_OK;
                }
                else
                {
                    PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).UpTpTransmit |= PDUR_CROSSCORE_TX_WAIT_TX_CONFIRM_OK;
                }
            }
            else
#endif
            {
                ConfirmFinishMask = PDUR_TX_PDU_INFO_PTR(TxPduId).ConfMask;
                PduR_FanOutConunt[TxPduId]--;
                if(E_NOT_OK == Result)
                {
                    TxErrorMask[TxPduId] |= mask;
                }
                if(PduR_FanOutConunt[TxPduId] == (uint8)0)
                {
                    if(TxErrorMask[TxPduId] == ConfirmFinishMask)
                    {
                        /*All paths failed, call TxConfirmation with E_NOT_OK*/
                        PduR_ModuleFunctions[SrcModuleType].UpTpTxConfirmationFunc(ConfId, Result);
                    }
                    else
                    {
                        /*SWS_PduR_00765*/
                        PduR_ModuleFunctions[SrcModuleType].UpTpTxConfirmationFunc(ConfId, E_OK);
                    }
                }
                TxConfMask[TxPduId] |= mask;
                if(TxConfMask[TxPduId] == ConfirmFinishMask)
                {
                    /*The last TxConfirmation*/
                    TxConfMask[TxPduId] = (PduR_MulticastMaskType)0;
                    TxErrorMask[TxPduId] = (PduR_MulticastMaskType)0;
                }
            }
        }

#endif
    }
#if(STD_ON == PDUR_GW_TP_SUPPORT)
#if(PDUR_MAX_NUMOFBUFFER > 0)
    else if(PDUR_UNUSED != BufferId)
    {
#if(STD_ON == PDUR_TEST_ENABLE)
        if(Result != E_OK)
        {

            /*ErrorType 12*/
            ErrorInfo[ErrorCount].ErrorType = 12;
            ErrorInfo[ErrorCount].ErrorBufferId = BufferId;
            ErrorInfo[ErrorCount].ErrorBufferInfo = PDUR_BUFFER_INFO(BufferId, FrontPos);
            ErrorInfo[ErrorCount].ErrorBufferQueueInfo = PduRBufferQueueInfo[BufferId];
            ErrorInfo[ErrorCount].BufferPoolUsage = PduR_BufferPoolSet[PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PdurDestTxBufferPoolId].BufferInUse[0];
            Bsw_MemCpy(ErrorInfo[ErrorCount].PduContent, (uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[FrontPos]), 5);
            PduR_SendErrorInfo();
            ErrorCount++;
            if(ErrorCount == 20)
            {
                ErrorCount = 0;
            }
        }
#endif

#if(STD_ON == PDUR_MULTICORE_SUPPORT)
        if((uint8)(PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).UpTpTransmit & PDUR_CROSSCORE_TX_WAIT_CANCEL_TRANSMIT) != (uint8)0)
        {
            /*do nothing*/
        }
        else
#endif
        {
        /*SWS_PduR_00637*/
            if((uint8)0 != (uint8)(PDUR_BUFFER_INFO(BufferId, PduRBufferQueueInfo[BufferId].FrontPos).BufState & PDUR_BUFFER_TRANSMITING))
            {
                PduR_BufferRelease(PathId, BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                }
#endif

                PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].FrontPos);

#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                }
#endif
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
#endif
                PduR_UpdateFIFOInfo(BufferId,FALSE);
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                {
                    PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                }
#endif
            }

        
            FrontPos = PduRBufferQueueInfo[BufferId].FrontPos;
            while(((uint8)(PDUR_BUFFER_INFO(BufferId, FrontPos).BufState & PDUR_BUFFER_RECEIVING) != (uint8)0)||(PduRBufferQueueInfo[BufferId].QueueAvailableLen != PDUR_BUFFER_DEPTH(BufferId)))
            {
                FrontPos = PduRBufferQueueInfo[BufferId].FrontPos;
                PathIdx = PDUR_BUFFER_INFO(BufferId, FrontPos).PathIdx;
                PduRTpThreshold = PDUR_ROUTINGPATHINFO(PathIdx).PduRDestPdu.PduRTpThreshold;
                ReceivedLen = PDUR_BUFFER_INFO(BufferId, FrontPos).ReceivedLen;
                if((ReceivedLen >= (PduLengthType)PduRTpThreshold)\
                    || ((uint8)(PDUR_BUFFER_INFO(BufferId, FrontPos).BufState & PDUR_BUFFER_WAIT_TXCONFIRM) != (uint8)0))
                {
                    DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;
                    DestPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;

                    FrontPos = PduRBufferQueueInfo[BufferId].FrontPos;
                    ReadPos = PDUR_BUFFER_INFO(BufferId, FrontPos).ReadPos;

                    TxPduInfo.SduLength = PDUR_BUFFER_INFO(BufferId, FrontPos).TotalLen;
                    TxPduInfo.SduDataPtr = (uint8*)(PduR_Cfg_Buffer[BufferId].PduPtr[FrontPos])+ReadPos;
                    if(E_OK == PduR_ModuleFunctions[DestModuleType].TpTransmitFunc(DestPduId, &TxPduInfo))
                    {
                        PDUR_BUFFER_INFO(BufferId, FrontPos).BufState |= PDUR_BUFFER_TRANSMITING;
                        break;
                    }
                    else
                    {
#if(STD_ON == PDUR_TEST_ENABLE)
                        /*ErrorType 13*/
                        ErrorInfo[ErrorCount].ErrorType = 13;
                        ErrorInfo[ErrorCount].ErrorBufferId = BufferId;
                        ErrorInfo[ErrorCount].ErrorBufferInfo = PDUR_BUFFER_INFO(BufferId, FrontPos);
                        ErrorInfo[ErrorCount].ErrorBufferQueueInfo = PduRBufferQueueInfo[BufferId];
                        ErrorInfo[ErrorCount].BufferPoolUsage = PduR_BufferPoolSet[PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PdurDestTxBufferPoolId].BufferInUse[0];
                        PduR_SendErrorInfo();
                        ErrorCount++;
                        if(ErrorCount == 20)
                        {
                            ErrorCount = 0;
                        }

#endif
                        PduR_BufferRelease(PathId, BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                        if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                        {
                            PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                        }
#endif
                        PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].FrontPos);

#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                        if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                        {
                            PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                        }
#endif
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                        if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                        {
                            PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                        }
#endif
                        PduR_UpdateFIFOInfo(BufferId,FALSE);
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                        if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                        {
                            PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                        }
#endif
                    /*SWS_PDUR_00807*/
                        PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_STARTOFRECEPTION_APIID, PDUR_E_PDU_INSTANCES_LOST);
                        PduR_PathConf[ConfIndex] = TRUE;

                    }
                }
                else
                {
                    PduR_PathConf[ConfIndex] = TRUE;
                    /*PRQA S 0771 ++*/
                    /*When there is no data to send, needs to ues this break to abort*/
                    break;
                    /*PRQA S 0771 --*/
                }
            }
            FrontPos = PduRBufferQueueInfo[BufferId].FrontPos;
            if((PduRBufferQueueInfo[BufferId].QueueAvailableLen == PDUR_BUFFER_DEPTH(BufferId))&&((uint8)(PDUR_BUFFER_INFO(BufferId, FrontPos).BufState & PDUR_BUFFER_RECEIVING) == (uint8)0))
            {
                PduR_PathConf[ConfIndex] = TRUE;
            }
        }
    }
#endif
#endif
    else
    {
        /* Intentionally Empty */
    }
}
#endif/*#if(PDUR_MAX_TXCONF_PDU > 0)*/

#if(PDUR_MAX_RX_PDU_INFO > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerTpMultiStartOfReception
*
* Description:   StartOfReception processing of lower Tp module
*
* Inputs:        PathId id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LowerTpMultiStartOfReception
(
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathIdType i;
    boolean Flag = FALSE;
    PduLengthType LargestBuffSize = (PduLengthType)0;
    PduIdType PduId;

    /*SWS_PduR_00803*/
    for(i = (PduR_RoutingPathIdType)0; i < pRxPduInfo->NumPaths; i++)
    {
        PathId = pRxPduInfo->PathIdx[i];

        /*SWS_PduR_00717*/
        if(PduR_RoutingPathEnbale[PathId] == TRUE)
        {           
            result = PduR_LowerTpStartOfReception(PathId, info, TpSduLength, bufferSizePtr);
        }
        if(BUFREQ_OK == result)
        {
            Flag = TRUE;
            /*return the largest*/
            if(*bufferSizePtr > LargestBuffSize)
            {
                LargestBuffSize = *bufferSizePtr;
            }
        }
        else
        {
            PduId = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId;
            RxErrorMask[PduId] |= PDUR_ROUTINGPATHINFO(PathId).ConfMask;
            RxStartOfReceptionErrorMask[PduId]|= PDUR_ROUTINGPATHINFO(PathId).ConfMask;
        }
        
    }
    /*SWS_PduR_00804*/
    if(TRUE == Flag)
    {
        result = BUFREQ_OK;
        *bufferSizePtr = LargestBuffSize;
    }

    return result;
}
#endif
#if(PDUR_MAX_RX_PDU_INFO > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerTpMultiCopyRxData
*
* Description:   CopyRxData processing of lower Tp module
*
* Inputs:        PathId id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LowerTpMultiCopyRxData
(
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    PduR_RoutingPathIdType PathId;
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    PduR_RoutingPathIdType  PathIndex;
    boolean Flag = FALSE;
    PduLengthType LargestBuffSize = (PduLengthType)0;
    PduIdType PduId;
    PduR_MulticastMaskType PathMask;
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
    PduR_BufferIdType BufferId;
    PduLengthType RearPos;
#endif

    /*SWS_PduR_00803*/
    for(PathIndex = (PduR_RoutingPathIdType)0; PathIndex < pRxPduInfo->NumPaths; PathIndex++)
    {
        
        PathId = pRxPduInfo->PathIdx[PathIndex];
        PduId = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId;
        PathMask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
        /*SWS_PduR_00717*/
        if((PduR_RoutingPathEnbale[PathId] == TRUE) &&\
            ((PduR_MulticastMaskType)0 == (PduR_MulticastMaskType)(RxErrorMask[PduId] & PathMask)))
        {
            result = PduR_LowerTpCopyRxData(PathId, info, bufferSizePtr);
        }
        else
        {
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
            BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
            if((PduIdType)BufferId == PDUR_UNUSED)
            {
                /*No buffer configured, do not continue gateway operation*/
            }
#if(STD_ON == PDUR_GW_TP_SUPPORT)
            else if(TRUE == PduR_MatchPos(PathId, BufferId))
            {
                /*SWS_PduR_00663*/
                RearPos = PduRBufferQueueInfo[BufferId].RearPos;

                if(((uint8)0 != (uint8)(PDUR_BUFFER_INFO(BufferId, RearPos).BufState & PDUR_BUFFER_RECEIVING)) \
                   && ((uint8)0 == (uint8)(PDUR_BUFFER_INFO(BufferId, RearPos).BufState & PDUR_BUFFER_TRANSMITING)))
                {
                    PduR_BufferRelease(PathId, BufferId, PduRBufferQueueInfo[BufferId].RearPos);
                    PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].RearPos);
                    PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_RXINDICATION_APIID, PDUR_E_PDU_INSTANCES_LOST);
                }
            }
#endif
            else
            {
                /*do nothing*/
            }
#endif
        }
        if(BUFREQ_OK == result)
        {
            Flag = TRUE;
            /*return the largest*/
            if(*bufferSizePtr > LargestBuffSize)
            {
                LargestBuffSize = *bufferSizePtr;
            }
        }
        else
        {
            RxErrorMask[PduId] |= PathMask;
        }
    }

    /*SWS_PduR_00804*/
    if(TRUE == Flag)
    {
        result = BUFREQ_OK;
        *bufferSizePtr = LargestBuffSize;
    }
    else
    {
        result = BUFREQ_E_NOT_OK;
    }
    return result;
}
#endif
#if(PDUR_MAX_RX_PDU_INFO > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LowerTpMultiRxIndication
*
* Description:   RxIndication processing of lower Tp module
*
* Inputs:        PathId id of the routing path
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, PDUR_CODE) PduR_LowerTpMultiRxIndication
(
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo,
    Std_ReturnType result
)
{
    PduR_RoutingPathIdType PathId;
    PduR_RoutingPathIdType PathIndex;
    PduIdType PduId;
    PduR_MulticastMaskType PathMask;

#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
    PduR_BufferIdType BufferId;
#endif

    for(PathIndex = (PduR_RoutingPathIdType)0; PathIndex < pRxPduInfo->NumPaths; PathIndex++)
    {
        PathId = pRxPduInfo->PathIdx[PathIndex];
        PduId = PDUR_ROUTINGPATHINFO(PathId).PduRSrcPdu.PduRSrcPduHandleId;
        PathMask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;

        /*SWS_PduR_00717*/
        if(PduR_RoutingPathEnbale[PathId] == TRUE)
        {
            if((PduR_MulticastMaskType)0 == (PduR_MulticastMaskType)(RxErrorMask[PduId] & PathMask))
            {
                PduR_LowerTpRxIndication(PathId, result);
            }
            else if((PduR_MulticastMaskType)0 == (PduR_MulticastMaskType)(RxStartOfReceptionErrorMask[PduId] & PathMask))
            {
                PduR_LowerTpRxIndication(PathId, E_NOT_OK);
            }
            else
            {
                /*do nothing*/
            }
        }
        else
        {
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
            BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
            if((PduIdType)BufferId == PDUR_UNUSED)
            {
                /*No buffer configured, do not continue gateway operation*/
            }
            else if(TRUE == PduR_MatchPos(PathId, BufferId))
            {
                /*SWS_PduR_00663*/
                PduR_BufferRelease(PathId, BufferId, PduRBufferQueueInfo[BufferId].RearPos);
                PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].RearPos);
                
                PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_RXINDICATION_APIID, PDUR_E_PDU_INSTANCES_LOST);
            }
            else
            {
                /*do nothing*/
            }
#endif
        }
    }
}
#endif/*#if(PDUR_MAX_RX_PDU_INFO > 0)*/

#if(STD_ON == PDUR_DEV_ERROR_DETECT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_TxCompatibilityCheck
*
* Description:   Cfg compatibility check
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, PDUR_CODE) PduR_TxCompatibilityCheck
(
    void
)
{
#if(PDUR_MAX_TX_PDU_INFO > 0)
    PduIdType Index;
    PduR_RoutingPathIdType PathId;

    for(Index = (PduIdType)0; Index < (PduIdType)PDUR_MAX_TX_PDU_INFO_NUM; Index++)
    {
        for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_TX_PDU_INFO_PTR(Index).NumPaths; PathId++)
        {
            if(PDUR_TX_PDU_INFO_PTR(Index).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
            {
                PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
            }
        }
    }
#endif
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_RxCompatibilityCheck
*
* Description:   Cfg compatibility check
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, PDUR_CODE) PduR_RxCompatibilityCheck
(
    void
)
{
#if(PDUR_MAX_RX_PDU_INFO > 0)
    PduIdType Index; 
    PduR_RoutingPathIdType PathId;

    for(Index = (PduIdType)0; Index < (PduIdType)PDUR_MAX_RX_PDU_INFO_NUM; Index++)
    {
        for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_RX_PDU_INFO_PTR(Index).NumPaths; PathId++)
        {
            if(PDUR_RX_PDU_INFO_PTR(Index).PathIdx[PathId] >= PDUR_GET_NUM_ROUTPATH())
            {
                PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PDU_ID_INVALID);
            }
        }
    }
#endif
}
#endif/*(STD_ON == PDUR_DEV_ERROR_DETECT)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_SwitchRountingPath
*
* Description:   Enable paths based on routing groups.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, PDUR_CODE) PduR_SwitchRountingPath
(
    void
)
{
    PduR_RoutingPathIdType PathIndex = (PduR_RoutingPathIdType)0;
    P2CONST(PduR_RoutingPathGroupType, AUTOMATIC, PDUR_CONST) GroupPtr;
    PduR_RoutingPathGroupIdType GroupIndex;
    PduR_RoutingPathGroupIdType GroupId;
    boolean EnableFlag;

    for(PathIndex = (PduR_RoutingPathIdType)0; PathIndex < PDUR_GET_NUM_ROUTPATH(); PathIndex++)
    {
        if(PDUR_RPGROUP_NONE != PDUR_ROUTINGPATHINFO(PathIndex).PduRDestPdu.PduRRoutingGroup)
        {
            GroupPtr = PDUR_ROUTINGPATHINFO(PathIndex).PduRDestPdu.PduRRoutingGroup;
            /*Initialize EnableFlag in each path*/
            EnableFlag = FALSE;
            if(GroupPtr != NULL_PTR)
            {
                for(GroupIndex = (PduR_RoutingPathGroupIdType)0; GroupIndex < GroupPtr->PduRRoutingGroupMaxNum; GroupIndex++)
                {
                    GroupId = GroupPtr->PduRRoutingGroup[GroupIndex];
                    EnableFlag |= PduR_RoutingPathGroupEnabled[GroupId];
                    if(EnableFlag == TRUE)
                    {
                        break;
                    }
                }
            }
            PduR_RoutingPathEnbale[PathIndex] = EnableFlag;
            
        }
        else
        {
            PduR_RoutingPathEnbale[PathIndex] = TRUE;
        }
    }
}

/*******************************************************************************
*  PUBLIC Functions define
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_Init    SWS_PduR_00334
*
* Description:     Initializes the PDU Router.
*
* Inputs:         ConfigPtr Pointer to post build configuration
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_Init
(
    P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_CONST) ConfigPtr
)
{
    PduR_RoutingPathIdType PathId = (PduR_RoutingPathIdType)0;

#if(PDUR_MAX_NUMOFROUTINGPATHGROUP > 0)
    PduR_RoutingPathGroupIdType GroupId = (PduR_RoutingPathGroupIdType)0;
#endif
#if(PDUR_MAX_NUMOFBUFFER > 0)
    PduR_BufferIdType BufferId;
    PduLengthType DeepIndex;
    PduR_BufferIdType BufferPoolId;
    uint8 Core;
    const BufferPoolType* BufferPoolSet;
#endif

    if(PDUR_IS_INITIALIZED())
    {
        /*delete it, since PduR has no deinit*/
        PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_UNINIT);
    }
    else
    {
#if(PDUR_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        if(NULL_PTR == ConfigPtr)
        {
            PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_PARAM_POINTER);
        }
        else
#else
        (void)ConfigPtr;
#endif
        {
#if(PDUR_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
            PduR_ConfigSet = ConfigPtr;
#endif
            /*Cfg compatibility check*/
#if(STD_ON == PDUR_DEV_ERROR_DETECT)
            PduR_TxCompatibilityCheck();
            PduR_RxCompatibilityCheck();

            for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_GET_NUM_ROUTPATH(); PathId++)
            {
#if(PDUR_MAX_NUMOFBUFFER > 0)
                if((PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId != PDUR_UNUSED)
                        && (PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId >= PDUR_GET_NUM_BUFFER()))
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_DEST_TXBUF_ID_INVALID);
                }
#endif
                if((PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRTpGWTrigger != PDUR_TPGW_TRIGGER_FLY)
                        && (PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRTpGWTrigger != PDUR_TPGW_TRIGGER_IND))
                {
                    PDUR_DET_REPORT_ERROR(PDUR_INIT_APIID, PDUR_E_DEST_TRIGGER_INVALID);
                }
            }
#endif
            for(PathId = (PduR_RoutingPathIdType)0; PathId < PDUR_GET_NUM_ROUTPATH(); PathId++)
            {
                PduR_PathConf[PathId] = TRUE;
            }
#if(PDUR_MAX_NUMOFBUFFER > 0)
            for(BufferId = (PduR_BufferIdType)0; BufferId < (PduR_BufferIdType)PDUR_GET_NUM_BUFFER(); BufferId++)
            {
                PduRBufferQueueInfo[BufferId].FrontPos = (PduLengthType)0;
                PduRBufferQueueInfo[BufferId].RearPos = (PduLengthType)0;
                PduRBufferQueueInfo[BufferId].QueueAvailableLen = PDUR_BUFFER_DEPTH(BufferId);

                for(DeepIndex = (PduLengthType)0; DeepIndex < PDUR_BUFFER_DEPTH(BufferId); DeepIndex++)
                {
                    /*SWS_PduR_00645 SWS_PduR_00308*/
                    PduR_BufferInit(BufferId, DeepIndex);
                }
            }
#endif
#if(PDUR_NUMOFBUFFERPOOLSET>0)
            for(Core = (uint8)0; Core < (uint8)PDUR_MAX_CORE_NUM; Core++)
            {
                BufferPoolSet = PduR_AllBufferPoolSet[Core].BufferPoolSet;
                for(BufferPoolId = (PduR_BufferIdType)0; BufferPoolId < (PduR_BufferIdType)PduR_AllBufferPoolSet[Core].NumOfBufferPool; BufferPoolId++)
                {
                    BufferPoolSet[BufferPoolId].BufferInUse[0] = ((uint64)1<<BufferPoolSet[BufferPoolId].PoolSize);
                    BufferPoolSet[BufferPoolId].BufferInUse[0] = BufferPoolSet[BufferPoolId].BufferInUse[0]-(uint64)1;
                    BufferPoolSet[BufferPoolId].BufferInUse[0] = ~(BufferPoolSet[BufferPoolId].BufferInUse[0]);
                }
            }

#endif
#if(PDUR_MAX_NUMOFROUTINGPATHGROUP > 0)
            /*SWS_PduR_00709*/
            for(GroupId = (PduR_RoutingPathGroupIdType)0; GroupId < PDUR_GET_NUM_ROUTPATHGROUP(); GroupId++)
            {
                PduR_RoutingPathGroupEnabled[GroupId] = PDUR_GET_RPGROUP_ENABLED_ATINIT(GroupId);
            }
#endif
            PduR_SwitchRountingPath();
            /*SWS_PduR_00326*/
            PDUR_SET_INITIALIZED();
        }
    }
}


#if(STD_ON == PDUR_VERSION_INFO_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_GetVersionInfo  SWS_PduR_00338
*
* Description:   Returns the version information of this module
*
* Inputs:        None
*
* Outputs:       VersionInfo  Pointer to where to store the version information
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, PDUR_APPL_DATA) versionInfo
)
{
    if(NULL_PTR == versionInfo)
    {
        PDUR_DET_REPORT_ERROR(PDUR_GETVERSIONINFO_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
        versionInfo->vendorID = PDUR_VENDOR_ID;
        versionInfo->moduleID = PDUR_MODULE_ID;

        versionInfo->sw_major_version = (uint8)PDUR_SW_MAJOR_VERSION;
        versionInfo->sw_minor_version = (uint8)PDUR_SW_MINOR_VERSION;
        versionInfo->sw_patch_version = (uint8)PDUR_SW_PATCH_VERSION;
    }
}
#endif
/*SWS_PduR_00341*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_GetConfigurationId  
*
* Description:   Returns the unique identifier of the post-build time configuration
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(PduR_PBConfigIdType, PDUR_CODE) PduR_GetConfigurationId
(
    void
)
{
    PduR_PBConfigIdType retId = (PduR_PBConfigIdType)PDUR_INVALID_CONFIG_ID;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_GETCONFIGURATIONID_APIID, PDUR_E_UNINIT);
    }
    else
    {
        /*SWS_PduR_00280*/
#if(PDUR_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        retId = PduR_ConfigSet->PBConfigId;
#endif
    }
    return retId;
}

/*SWS_PduR_00615*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_EnableRouting  
*
* Description:   Enables a routing path table.
*
* Inputs:        id Identification of the routing path group.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_EnableRouting
(
    PduR_RoutingPathGroupIdType id
)
{

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_ENABLE_ROUTING_APIID, PDUR_E_UNINIT);
    }
    else if(id >= PDUR_GET_NUM_ROUTPATHGROUP())
    {
        /*SWS_PduR_00647 SWS_PduR_00648*/
        PDUR_DET_REPORT_ERROR(PDUR_ENABLE_ROUTING_APIID, PDUR_E_ROUTING_PATH_GROUP_ID_INVALID);
    }
    else
    {
        /*SWS_PduR_00715*//*SWS_PduR_00899*/
        if(PduR_RoutingPathGroupEnabled[id] == FALSE)
        {
            PduR_RoutingPathGroupEnabled[id] = TRUE;
            PduR_SwitchRountingPath();
        }
    }
}

/*SWS_PduR_00617*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_DisableRouting  
*
* Description:   Disables a routing path table.
*
* Inputs:        id Identification of the routing path group.
*                initialize - true: initialize single buffers to the default value
*                             false: retain current value of single buffers
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_DisableRouting
(
    PduR_RoutingPathGroupIdType id,
    boolean initialize
)
{
    (void) initialize;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_DISABLE_ROUTING_APIID, PDUR_E_UNINIT);
    }
    else if(id >= PDUR_GET_NUM_ROUTPATHGROUP())
    {
        /*SWS_PduR_00716 SWS_PduR_00649*/
        PDUR_DET_REPORT_ERROR(PDUR_DISABLE_ROUTING_APIID, PDUR_E_ROUTING_PATH_GROUP_ID_INVALID);
    }
    else
    {
        /*SWS_PduR_00646 SWS_PDUR_00805 SWS_PDUR_00810*//*SWS_PduR_00896*/
        if(PduR_RoutingPathGroupEnabled[id] == TRUE)
        {
            PduR_RoutingPathGroupEnabled[id] = FALSE;
            PduR_SwitchRountingPath();
        }

    }

}

/*SWS_PduR_00406*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_UpCallTransmit    
*
* Description:     Requests transmission of an I-PDU.
*
* Inputs:          TxPduId    :Identification of the I-PDU.
*                  PduInfoPtr :Length and pointer to the buffer of the I-PDU
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_UpCallTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{

    Std_ReturnType ret = E_NOT_OK;
    boolean Flag = FALSE;
#if(PDUR_MAX_TX_PDU_INFO > 0)
    PduR_RoutingPathIdType i;
    PduR_MulticastMaskType mask;
    PduR_RoutingPathIdType PathId;
#endif
    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_UP_TRANSMIT_APIID, PDUR_E_UNINIT);
    }
    else if(TxPduId >= (PduIdType)PDUR_MAX_TX_PDU_INFO_NUM)
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_UP_TRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_UP_TRANSMIT_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_TX_PDU_INFO > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        if((PduIdType)PDUR_MAX_TX_PDU_INFO_NUM > (PduIdType)0)
        {
            TxErrorMask[TxPduId] = (PduR_MulticastMaskType)0;
            TxConfMask[TxPduId] = (PduR_MulticastMaskType)0;
            PduR_FanOutConunt[TxPduId] = (uint8)PDUR_TX_PDU_INFO_PTR(TxPduId).NumPaths;
            for(i = (PduR_RoutingPathIdType)0; i < PDUR_TX_PDU_INFO_PTR(TxPduId).NumPaths; i++)
            {
                PathId = PDUR_TX_PDU_INFO_PTR(TxPduId).PathIdx[i];
                mask = PDUR_ROUTINGPATHINFO(PathId).ConfMask;
                ret = PduR_UpTransmit(PathId, PduInfoPtr);
                if(ret == E_OK)
                {
                    Flag = TRUE;
                }
                else
                {
                    /*Set mask as if the wrong path has finished*/
                    TxConfMask[TxPduId] |= mask;
                    TxErrorMask[TxPduId] |= mask;
                    PduR_FanOutConunt[TxPduId]--;
                } 
            }
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    /*SWS_PduR_00218*/
    if(TRUE == Flag)
    {
        ret = E_OK;
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}

/*SWS_PduR_00769*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name:   PduR_UpCallCancelTransmit
*
* Description:     Request for cancellation of an ongoing transmission of an I-Pdu
*                  in transport protocol or communication interface.
*
* Inputs:          TxPduId  :Identification of the I-PDU to be cancelled.
*
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_UpCallCancelTransmit
(
    PduIdType TxPduId
)
{
    Std_ReturnType ret = E_NOT_OK;
    boolean ErrorFlag = FALSE;

#if(PDUR_MAX_TX_PDU_INFO > 0)
    PduR_RoutingPathIdType i;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_UP_CANCEL_TRANSMIT_APIID, PDUR_E_UNINIT);
    }
    else if(TxPduId >= (PduIdType)PDUR_MAX_TX_PDU_INFO_NUM)
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_UP_CANCEL_TRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
#if(PDUR_MAX_TX_PDU_INFO > 0)
        if((PduIdType)PDUR_MAX_TX_PDU_INFO_NUM > (PduIdType)0)
        {
            for(i = (PduR_RoutingPathIdType)0; i < PDUR_TX_PDU_INFO_PTR(TxPduId).NumPaths; i++)
            {
                ret = PduR_UpCancelTransmit(PDUR_TX_PDU_INFO_PTR(TxPduId).PathIdx[i]);
                if(ret != E_OK)
                {
                    ErrorFlag = TRUE;
                }
            }
        }
#endif
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
    }
    /*SWS_PduR_00701*/
    if(ErrorFlag == TRUE)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = E_OK;
    }
    return ret;
}

/*SWS_PduR_00767*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_UpCallCancelReceive   
*
* Description:     Requests for cancellation of an ongoing reception of an I-Pdu
*                  in transport protocol
*
* Inputs:          RxPduId  :Identification of the I-PDU.
*
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_UpCallCancelReceive
(
    PduIdType RxPduId
)
{
    Std_ReturnType ret = E_NOT_OK;   

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_UP_CANCEL_RECEIVE_APIID, PDUR_E_UNINIT);
    }
    else if(RxPduId >= (PduIdType)PDUR_MAX_RX_PDU_INFO_NUM)
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_UP_CANCEL_RECEIVE_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
#if(PDUR_MAX_CANCELRX_PDU > 0)
        /*SWS_PduR_00736*/
        if((PduIdType)PDUR_MAX_CANCELRX_PDU_NUM > (PduIdType)0)
        {
            ret = PduR_UpCancelReceive(PDUR_RX_CANCEL_PDU_INFO_PTR(RxPduId).PathId);
        }
#endif
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
    }
    return ret;
}

/*SWS_PduR_00362*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LoIfRxIndication 
*
* Description:     Indication of a received I-PDU from a lower layer communication module.
*
* Inputs:          RxPduId   : Identification of the transmitted I-PDU.
*                  PduInfoPtr: Contains the length (SduLength) of the received I-PDU
*                              and a pointer to a buffer (SduDataPtr) containing the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/ 
FUNC(void, PDUR_CODE) PduR_LoIfRxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_IF_RXINDICATION_APIID, PDUR_E_UNINIT);
    }
    else if(RxPduId >= (PduIdType)PDUR_MAX_RX_PDU_INFO_NUM)
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_IF_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_IF_RXINDICATION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_RX_PDU_INFO > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        if((PduIdType)PDUR_MAX_RX_PDU_INFO_NUM > (PduIdType)0)
        {
            pRxPduInfo = &PDUR_RX_PDU_INFO_PTR(RxPduId);
            PduR_LowerIfMultiRxIndication(pRxPduInfo, PduInfoPtr);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

}

/*SWS_PduR_00365*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LoIfTxConfirmation    
*
* Description:     The lower layer communication module confirms the transmission
*                  of an I-PDU.
*
* Inputs:          TxPduId  : ID of the I-PDU that has been transmitted.
*                  result   : E_OK: The PDU was transmitted. 
*                             E_NOT_OK: Transmission of the PDU failed.
*
* Outputs:     
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_LoIfTxConfirmation
(
    PduIdType TxPduId,
    Std_ReturnType result
)
{
    PduR_RoutingPathIdType PathId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_IF_TXCONFIRMATION_APIID, PDUR_E_UNINIT);
    }
    else if(TxPduId >= (PduIdType)PDUR_MAX_TXCONF_PDU_NUM)
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_IF_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
#if(PDUR_MAX_TXCONF_PDU > 0)
        if((PduIdType)PDUR_MAX_TXCONF_PDU_NUM > (PduIdType)0)
        {
            PathId = PDUR_TX_CONF_PDU_INFO_PTR(TxPduId).PathId;
            if(PduR_RoutingPathEnbale[PathId] == TRUE)
            {
                PduR_LowerIfTxConfirmation(PathId, PDUR_TX_CONF_PDU_INFO_PTR(TxPduId).UpperPduId, result);
            }
        }
#endif
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();

    }
}

/*SWS_PduR_00369*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LoIfTriggerTransmit    
*
* Description:     The lower layer communication module requests the buffer of the
*                  SDU for transmission from the upper layer module.
*
* Inputs:         TxPduId    : ID of the SDU that is requested to be transmitted.
*                 PduInfoPtr : Contains a pointer to a buffer (SduDataPtr) to where
*                              the SDU shall be copied to. On return, the service will
*                              indicate the length of the copied SDU data in SduLength
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_LoIfTriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    PduR_RoutingPathIdType PathId;
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
    PduR_BufferIdType BufferId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_IF_TRIGGERTRANSMIT_APIID, PDUR_E_UNINIT);
    }
    else if(TxPduId >= (PduIdType)PDUR_MAX_TXCONF_PDU_NUM)
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_IF_TRIGGERTRANSMIT_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_IF_TRIGGERTRANSMIT_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
#if(PDUR_MAX_TXCONF_PDU > 0)
        if((PduIdType)PDUR_MAX_TXCONF_PDU_NUM > (PduIdType)0)
        {
            PathId = PDUR_TX_CONF_PDU_INFO_PTR(TxPduId).PathId;

            if(PduR_RoutingPathEnbale[PathId] == TRUE)
            {
                ret = PduR_LowerIfTriggerTransmit(PathId, PDUR_TX_CONF_PDU_INFO_PTR(TxPduId).UpperPduId, PduInfoPtr);
            }
            else
            {
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
                BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
                if(BufferId != PDUR_UNUSED)
                {
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                    /*SWS_PduR_00663*/
                    if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                    {
                        PDUR_GET_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                    }
#endif
                    PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                    if(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos) != NULL_PTR)
                    {
                        PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_FLAG_PTR(BufferId, PduRBufferQueueInfo[BufferId].FrontPos));
                    }

                    if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                    {
                        PDUR_GET_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                    }
#endif
                    PduR_UpdateFIFOInfo(BufferId,FALSE);
#if(STD_ON == PDUR_MULTICORE_SUPPORT)
                    if(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId) != NULL_PTR)
                    {
                        PDUR_RELEALSE_SPINLOCK(PDUR_BUFFER_QUEUE_FLAG_PTR(BufferId));
                    }
#endif
                    PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_RXINDICATION_APIID, PDUR_E_PDU_INSTANCES_LOST);
                }
#endif
            }
        }
#endif
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
    }

    return ret;
}

/*SWS_PduR_00507*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LoTpStartOfReception    
*
* Description:     This function is called at the start of receiving an N-SDU.
*                  The N-SDU might be fragmented into multiple N-PDUs (FF with one
*                  or more following CFs) or might consist of a single N-PDU (SF).
*
* Inputs:          id          : Identification of the I-PDU.
*                  TpSduLength : Total length of the PDU to be received.
*
* Outputs:         bufferSizePtr : Available receive buffer in the receiving module.
*                                  This parameter will be used to compute the Block
*                                  Size (BS) in the transport protocol module
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpStartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_STARTOFRECEPTION_APIID, PDUR_E_UNINIT);
    }
    else if(id >= (PduIdType)PDUR_MAX_RX_PDU_INFO_NUM)
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_STARTOFRECEPTION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == bufferSizePtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_STARTOFRECEPTION_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_RX_PDU_INFO > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        if((PduIdType)PDUR_MAX_RX_PDU_INFO_NUM > (PduIdType)0)
        {
            pRxPduInfo = &(PDUR_RX_PDU_INFO_PTR(id));
            RxErrorMask[id] = (PduR_MulticastMaskType)0;

            result = PduR_LowerTpMultiStartOfReception(pRxPduInfo, info, TpSduLength, bufferSizePtr);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }

    return result;
}

/*SWS_PduR_00512*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LoTpCopyRxData    
*
* Description:     This function is called when a transport protocol module has data
*                  to copy for the receiving module. Several calls may be made during
*                  one transportation of an I-PDU.
*
* Inputs:          id  : Identification of the transmitted I-PDU.
*                  info: Pointer to the buffer (SduDataPtr) and its length (SduLength)
*                        containing the data to be copied by PDU Router module in case
*                        of gateway or upper layer module in case of reception
*
* Outputs:         bufferSizePtr:    Available receive buffer after data has been copied.
*
* Return value:    BufReq_ReturnType:  BUFREQ_OK: Data copied successfully
*                                      BUFREQ_E_NOT_OK: Data was not copied because  
*                                      an error occurred.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_COPYRXDATA_APIID, PDUR_E_UNINIT);
    }
    else if(id >= (PduIdType)PDUR_MAX_RX_PDU_INFO_NUM)
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_COPYRXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_COPYRXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
#if(PDUR_MAX_RX_PDU_INFO > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        if((PduIdType)PDUR_MAX_RX_PDU_INFO_NUM > (PduIdType)0)
        {
            pRxPduInfo = &PDUR_RX_PDU_INFO_PTR(id);
            result = PduR_LowerTpMultiCopyRxData(pRxPduInfo, info, bufferSizePtr);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
    return result;
}

/*SWS_PduR_00375*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LoTpRxIndication    
*
* Description:     Called after an I-PDU has been received via the TP API, 
*                  the result indicates whether the transmission was successful or not
*
* Inputs:         id     : Identification of the received I-PDU.
*                 result : Result of the reception.
*
* Outputs:         bufferSizePtr : vailable receive buffer after data has been copied.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_LoTpRxIndication
(
    PduIdType id,
    Std_ReturnType result
)
{
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_RXINDICATION_APIID, PDUR_E_UNINIT);
    }
    else if(id >= (PduIdType)PDUR_MAX_RX_PDU_INFO_NUM)
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_RXINDICATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
#if(PDUR_MAX_RX_PDU_INFO > 0)
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
        if((PduIdType)PDUR_MAX_RX_PDU_INFO_NUM > (PduIdType)0)
        {
            pRxPduInfo = &(PDUR_RX_PDU_INFO_PTR(id));
            PduR_LowerTpMultiRxIndication(pRxPduInfo, result);
        }
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
#endif
    }
}



/*SWS_PduR_00518*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LoTpCopyTxData    
*
* Description:     This function is called by the transport protocol module to query
*                  the transmit data of an I-PDU segment.
*
* Inputs:          id       : Identification of the transmitted I-PDU.
*                  info     : Provides destination buffer and the number of bytes to copy.
*                             In case of gateway the PDU Router module will copy, otherwise
*                             the source upper layer module will copy the data. If not enough
*                             transmit data is available, no data is copied. The transport
*                             protocol module will retry. A copy size of 0 can be used to
*                             indicate state changes in the retry parameter.
*                  retry    : This parameter is used to retransmit data because problems
*                             during the last service call.
*
* Outputs:         availableDataPtr : Indicates the remaining number of bytes that are
*                                     available in the PduR Tx buffer. AvailableTxDataCntPtr
*                                     can be used by TP modules that support dynamic payload
*                                     lengths (e.g. Iso FrTp) to determine the size of the
*                                     following CFs.
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_LoTpCopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr
)
{
    BufReq_ReturnType result = BUFREQ_E_NOT_OK;
    PduR_RoutingPathIdType PathId;
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
    PduR_BufferIdType BufferId;
#endif

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_COPYTXDATA_APIID, PDUR_E_UNINIT);
    }
    else if(id >= (PduIdType)PDUR_MAX_TXCONF_PDU_NUM)
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_COPYTXDATA_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(NULL_PTR == info)
    {
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == availableDataPtr)
    {
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_COPYTXDATA_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {
        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
#if(PDUR_MAX_TXCONF_PDU > 0)
        if((PduIdType)PDUR_MAX_TXCONF_PDU_NUM > (PduIdType)0)
        {
            PathId = PDUR_TX_CONF_PDU_INFO_PTR(id).PathId;

            if(PduR_RoutingPathEnbale[PathId] == TRUE)
            {
                result = PduR_LowerTpCopyTxData\
                        (PathId, PDUR_TX_CONF_PDU_INFO_PTR(id).UpperPduId, info, retry, availableDataPtr);
            }
            else
            {
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
                BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;
                if(BufferId != PDUR_UNUSED)
                {

                    if(PduRBufferQueueInfo[BufferId].QueueAvailableLen != PDUR_BUFFER_DEPTH(BufferId))
                    {
                        /*SWS_PduR_00663*/
                        PduR_BufferRelease(PathId, BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
                        PduR_BufferInit(BufferId, PduRBufferQueueInfo[BufferId].FrontPos);
                        PduR_UpdateFIFOInfo(BufferId, FALSE);
                        PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_RXINDICATION_APIID, PDUR_E_PDU_INSTANCES_LOST);
                    }
                }
#endif
            }
        }
#endif
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
    }
    return result;
}

/*SWS_PduR_00381*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_LoTpTxConfirmation    
*
* Description:     This function is called after the I-PDU has been transmitted on
*                  its network, the result indicates whether the transmission was
*                  successful or not
*
* Inputs:          id       : Identification of the transmitted I-PDU.
*                  result   : Result of the transmission of the I-PDU.
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, PDUR_CODE) PduR_LoTpTxConfirmation
(
    PduIdType id,
    Std_ReturnType result
)
{
    PduR_RoutingPathIdType PathId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_TXCONFIRMATION_APIID, PDUR_E_UNINIT);
    }
    else if(id >= (PduIdType)PDUR_MAX_TXCONF_PDU_NUM)
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_MODULE_TP_TXCONFIRMATION_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {

        SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
#if(PDUR_MAX_TXCONF_PDU > 0)
        if((PduIdType)PDUR_MAX_TXCONF_PDU_NUM > (PduIdType)0)
        {
            PathId = PDUR_TX_CONF_PDU_INFO_PTR(id).PathId;

            if(PduR_RoutingPathEnbale[PathId] == TRUE)
            {
                PduR_LowerTpTxConfirmation(PathId, PDUR_TX_CONF_PDU_INFO_PTR(id).UpperPduId, result);
            }
        }
#endif
        SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();

    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_GetPathState    
*
* Description:     Get path state according to pathID
*
* Inputs:          PathId     : PathId of the path to be checked

*
* Outputs:         PathStatus : Status of the path, 
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
FUNC(Std_ReturnType, PDUR_CODE) PduR_GetPathState
(
    PduIdType id,
    uint8* PathStatus
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 i;
    PduR_RoutingPathIdType PathId;
    PduR_BufferIdType BufferId;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_GETPATHSTATE_APIID, PDUR_E_UNINIT);
    }
    else if(id >= (PduIdType)PDUR_MAX_TXCONF_PDU_NUM)
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_GETPATHSTATE_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else if(PathStatus == NULL_PTR)
    {
        PDUR_DET_REPORT_ERROR(PDUR_GETPATHSTATE_APIID, PDUR_E_PARAM_POINTER);
    }
    else
    {

#if(PDUR_MAX_TXCONF_PDU > 0)
        if((PduIdType)PDUR_MAX_TXCONF_PDU_NUM > (PduIdType)0)
        {
            *PathStatus = PDUR_BUFFER_IDLE;

            PathId = PDUR_TX_CONF_PDU_INFO_PTR(id).PathId;                                              
            BufferId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestTxBufferId;

            for(i = (uint8)0; i < PDUR_BUFFER_DEPTH(BufferId); i++)
            {
                *PathStatus |= PDUR_BUFFER_INFO(BufferId,i).BufState;
            }

            ret = E_OK;
        }
#endif
    }
    return ret;
}
#endif

#if(PDUR_MAX_RX_PDU_INFO > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: PduR_GetRxPduState
*
* Description:     Get RxPdu state
*
* Inputs:          id : Rx pdu Id
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, PDUR_CODE) PduR_GetRxPduState
(
    PduIdType id
)
{
    boolean IsRxPduStart;
    P2CONST(PduRRoutingPduInfoType, AUTOMATIC, PDUR_CONST) pRxPduInfo;
    PduR_RoutingPathIdType i;
    PduR_RoutingPathIdType PathId;
    PduIdType DestPduId;
    uint8 DestModuleType;
    Std_ReturnType ret = E_NOT_OK;
    Std_ReturnType r;

    if(!PDUR_IS_INITIALIZED())
    {
        /*SWS_PduR_00328 SWS_PduR_00330 SWS_PduR_00119*/
        PDUR_DET_REPORT_ERROR(PDUR_PDUR_GETRXPDUSTATE_APIID, PDUR_E_UNINIT);
    }
    else if(id >= (PduIdType)PDUR_MAX_RX_PDU_INFO_NUM)
    {
        /*SWS_PduR_00221*/
        PDUR_DET_REPORT_ERROR(PDUR_PDUR_GETRXPDUSTATE_APIID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {

        pRxPduInfo = &PDUR_RX_PDU_INFO_PTR(id);

        for(i = (PduR_RoutingPathIdType)0; i < pRxPduInfo->NumPaths; i++)
        {
            PathId = pRxPduInfo->PathIdx[i];
            DestPduId = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestPduId;
            DestModuleType = PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType;
            if(PduR_RoutingPathEnbale[PathId] == TRUE)
            {
                if(NULL_PTR != PduR_ModuleFunctions[DestModuleType].UpIfRxIndicationFunc)
                {
#ifdef MODULE_COM
                    if(PDUR_ROUTINGPATHINFO(PathId).PduRDestPdu.PduRDestModuleType == MODULE_COM)
                    {
                        r = Com_GetRxIpduState(DestPduId, &IsRxPduStart);
                        if((r == E_OK) && (IsRxPduStart == TRUE))
                        {
                            ret = E_OK;

                        }
                    }
                    else
#endif
                    {
                        ret = E_OK;
                    }

                }
#if(STD_ON == PDUR_GW_IF_SUPPORT)
                else if(NULL_PTR !=  PduR_ModuleFunctions[DestModuleType].IfTransmitFunc)
                {
                    ret = E_OK;
                }
#endif
                else
                {

                }
            }
        }
    }
    return ret;
}
#endif
#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

