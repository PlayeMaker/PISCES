/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : MemIf.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : Memory Abstration Interface Module head File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file MemIf.h contains the declaration of the MemIf
*                     module API;contains 'extern' declarations of constants,
*                     global data,type definitions and services that are
*                     specified in the MemIf module SWS.
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to MemIf.c File
********************************************************************************
* END_FILE_HDR*/

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 3432 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no need to revise.
*/
#ifndef MEMIF_H
#define MEMIF_H

/*******************************************************************************
*   Include Files
*******************************************************************************/
#include "MemIf_Cfg.h"
#include "Std_Types.h"

/*******************************************************************************
*   Macro Definition
*******************************************************************************/

#if (MEMIF_DEV_ERROR_DETECT == STD_ON )
/*SWS_MemIf_00006 API Service called with wrong device index parameter;Development*/
#define MEMIF_E_PARAM_DEVICE            ((uint8)0x01)
#define MEMIF_E_PARAM_POINTER           ((uint8)0x02)
#define MEMIF_E_INCOMPATIBLE_VERSIONS   ((uint8)0x03)

#define MEMIF_SETMODE_APIID              ((uint8)0x01)
#define MEMIF_READ_APIID                 ((uint8)0x02)
#define MEMIF_WRITE_APIID                ((uint8)0x03)
#define MEMIF_CANCEL_APIID               ((uint8)0x04)
#define MEMIF_GETSTATUS_APIID            ((uint8)0x05)
#define MEMIF_GETJOBREASULT_APIID        ((uint8)0x06)
#define MEMIF_INVALIDATEBLOCK_APIID      ((uint8)0x07)
#define MEMIF_GETVERSIONINFO_APIID       ((uint8)0x08)
#define MEMIF_ERASEIMMEDIATEBLOCK_APIID  ((uint8)0x09)
#endif


/*******************************************************************************
*   Type Definition
*******************************************************************************/
#if(MEMIF_NUMBER_OF_DEVICE > 1)

typedef void (*MemIfSetModeFctPtrTyp)(MemIf_ModeType Mode);
typedef Std_ReturnType (*MemIfReadFctPtrTyp)
(uint16 BlockNumber, uint16 BlockOffset, P2VAR(uint8, TYPEDEF, TYPEDEF) DataBufferPtr, uint16 Length);
typedef Std_ReturnType (*MemIfWriteFctPtrTyp)(uint16 BlockNumber, P2CONST(uint8, TYPEDEF, TYPEDEF) DataBufferPtr);
typedef void (*MemIfCancelFctPtrTyp)(void);
typedef MemIf_StatusType (*MemIfGetStatusFctPtrTyp)(void);
typedef Std_ReturnType (*MemIfInvalidateBlockFctPtrTyp)(uint16 BlockNumber);
typedef MemIf_JobResultType (*MemIfGetJobResultFctPtrTyp)(void);
typedef Std_ReturnType (*MemIfEraseImmediateBlockFctPtrTyp)(uint16 BlockNumber);


#define MEMIF_START_SEC_CONFIG_DATA
#include "MemIf_MemMap.h"

extern CONST(MemIfSetModeFctPtrTyp, MEMIF_CONST)
MemIfSetModeFctPtrCfg[MEMIF_NUMBER_OF_DEVICE];
extern CONST(MemIfReadFctPtrTyp, MEMIF_CONST)
MemIfReadFctPtrCfg[MEMIF_NUMBER_OF_DEVICE];
extern CONST(MemIfWriteFctPtrTyp, MEMIF_CONST)
MemIfWriteFctPtrCfg[MEMIF_NUMBER_OF_DEVICE];
extern CONST(MemIfCancelFctPtrTyp, MEMIF_CONST)
MemIfCancelFctPtrCfg[MEMIF_NUMBER_OF_DEVICE];
extern CONST(MemIfGetStatusFctPtrTyp, MEMIF_CONST)
MemIfGetStatusFctPtrCfg[MEMIF_NUMBER_OF_DEVICE];
extern CONST(MemIfInvalidateBlockFctPtrTyp, MEMIF_CONST)
MemIfInvalidateBlockFctPtrCfg[MEMIF_NUMBER_OF_DEVICE];
extern CONST(MemIfGetJobResultFctPtrTyp, MEMIF_CONST)
MemIfGetJobResultFctPtrCfg[MEMIF_NUMBER_OF_DEVICE];
extern CONST(MemIfEraseImmediateBlockFctPtrTyp, MEMIF_CONST)
MemIfEraseImmediateBlockFctPtrCfg[MEMIF_NUMBER_OF_DEVICE];

#define MEMIF_STOP_SEC_CONFIG_DATA
#include "MemIf_MemMap.h"

/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/
#define MEMIF_START_SEC_CODE
#include "MemIf_MemMap.h"

extern FUNC(void, MEMIF_CODE) MemIf_SetMode
(
    MemIf_ModeType Mode
);
extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Read
(
    uint16 DeviceIndex,
    uint16 BlockNumber,
    uint16 BlockOffset,
    P2VAR(uint8, AUTOMATIC, MEMIF_APPL_DATA)DataBufferPtr,
    uint16 Length
);
extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Write
(
    uint16 DeviceIndex,
    uint16 BlockNumber,
    P2CONST(uint8, AUTOMATIC, MEMIF_APPL_DATA) DataBufferPtr
);
extern FUNC(void, MEMIF_CODE) MemIf_Cancel
(
    uint16 DeviceIndex
);
extern FUNC(MemIf_StatusType, MEMIF_CODE) MemIf_GetStatus
(
    uint16 DeviceIndex
);
extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_InvalidateBlock
(
    uint16 DeviceIndex,
    uint16 BlockNumber
);
extern FUNC(MemIf_JobResultType, MEMIF_CODE) MemIf_GetJobResult
(
    uint16 DeviceIndex
);
extern FUNC(Std_ReturnType, MEMIF_CODE) MemIf_EraseImmediateBlock
(
    uint16 DeviceIndex,
    uint16 BlockNumber
);

#define MEMIF_STOP_SEC_CODE
#include "MemIf_MemMap.h"

#endif

#if (STD_ON ==  MEMIF_VERSION_INFO_API)
#define MEMIF_START_SEC_CODE
#include "MemIf_MemMap.h"

extern FUNC(void, MEMIF_CODE) MemIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, MEMIF_APPL_DATA) VersionInfoPtr
);

#define MEMIF_STOP_SEC_CODE
#include "MemIf_MemMap.h"

#endif

#endif /* #ifndef _MEMIF_H */
