/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : NvM_JobProc.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : NvM module header File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of Non-Volatile RAM manager.
*
********************************************************************************
*   Limitations     :
*
********************************************************************************
*
********************************************************************************
*   Revision History
*   Reference to NvM.c File
********************************************************************************
* END_FILE_HDR*/

/*PRQA S 3429,3453 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no need to revise
*/

#ifndef NvM_JOBPROC_H
#define NvM_JOBPROC_H

/*******************************************************************************
*   include
*******************************************************************************/
#include "NvM_Lcfg.h"
#if(STD_ON == NVM_DEV_ERROR_DETECT)
#include "Det.h"
#endif
/*******************************************************************************
*   NvM Internal Data define
*******************************************************************************/
#define NVM_START_SEC_VAR_INIT_GLOBAL_8
#include "NvM_MemMap.h"
extern VAR(NvM_State_Type, NVM_VAR)  NvM_TaskState;
#define NVM_STOP_SEC_VAR_INIT_GLOBAL_8
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_LOCAL_8
#include "NvM_MemMap.h"
extern VAR(boolean, NVM_VAR_NOINIT) NvM_CancelWriteAllFlag;

extern VAR(boolean, NVM_VAR_NOINIT) NvM_CfgIdMatch;
#define NVM_STOP_SEC_VAR_CLEARED_LOCAL_8
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "NvM_MemMap.h"
extern VAR(NvM_QueBuf_Type, NVM_VAR_NOINIT) NvM_CurrentJobInfo;
extern VAR(NvM_QueBuf_Type, NVM_VAR_NOINIT) NvM_MultiJob;
#if(STD_ON == NVM_IMM_BLOCK_SUPPORT)
extern VAR(NvM_Que_Type, NVM_VAR_NOINIT) NvM_ImmQueue;
extern VAR(NvM_QueBuf_Type, NVM_VAR_NOINIT) NvM_PreemptJob;
#endif

#define NVM_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "NvM_MemMap.h"


/*******************************************************************************
*   MACRO
*******************************************************************************/
#define NVM_CRC_INITVALUE               ((uint32)0xFFFFFFFF)
#define NVM_USER_BLOCKID_START          ((NvM_BlockIdType)1)
#define NVM_WRITEALL_BLOCKID_START      ((NvM_BlockIdType)2)
#define NVM_CFGID_BLOCK_HANDLE          ((NvM_BlockIdType)1)


#define NVM_USER_JOB_PENDING            ((uint8)3)
#define NVM_AGENT_JOB_IDLE              ((uint8)0)
#define NVM_AGENT_JOB_DONE              ((uint8)1)

#define NVM_READ_IMPLICIT_REC_MASK     ((NvM_RequestResultType)0x80)
#define NVM_READ_IMPLICIT_REC_CMASK    ((NvM_RequestResultType)0x7F)


#define NVM_NOT_SKIPREADALL            ((uint8)0)
#define NVM_NORMAL_SKIPREADALL         ((uint8)1)
#define NVM_VALID_SKIPREADALL          ((uint8)2)

#define NVM_FIRSTINITALL_BLOCKID_START      ((NvM_BlockIdType)2)

#if(STD_ON == NVM_DEV_ERROR_DETECT)

#define  NVM_DET_ERROR_DETECT(cond, ApiId, errcode)  \
    DET_ERROR_DETECT((cond), NVM_MODULE_ID, NVM_INSTANCE_ID,(ApiId),(errcode))

#define  NVM_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret) \
    DET_ERROR_DETECT_RET((cond), NVM_MODULE_ID,NVM_INSTANCE_ID,(ApiId),(errcode), (ret))

#define  NVM_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(NVM_MODULE_ID, NVM_INSTANCE_ID, (ApiId), (errcode))

#else

#define  NVM_DET_ERROR_DETECT(cond, ApiId, errcode)
#define  NVM_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret)
#define  NVM_DET_REPORT_ERROR(ApiId, errcode)

#endif

/*******************************************************************************
*   Function declare
*******************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

extern FUNC(void, NVM_CODE) NvM_SetBlockAttibute
(
    const NvM_BlockIdType BlockId,
    const boolean valid,
    const boolean changed
);
extern FUNC(void, NVM_CODE) NvM_ResetJobState(void);

extern FUNC(void, NVM_CODE) NvM_InitSubState
(
    const NvM_BlockIdType BlockId,
    const uint8 ServiceId
);

extern FUNC(void, NVM_CODE)  NvM_WriteAllJobProcess(void);
extern FUNC(void, NVM_CODE)  NvM_ReadAllJobProcess(void);
extern FUNC(void, NVM_CODE)  NvM_FirstInitAllJobProcess(void);

extern FUNC(void, NVM_CODE)  NvM_ReadJobProcess
(
    const NvM_BlockIdType BlockId
);
extern FUNC(void, NVM_CODE)  NvM_WriteJobProcess
(
    const NvM_BlockIdType BlockId
);
#if((NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) || (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2))
extern FUNC(void, NVM_CODE)  NvM_RestoreProcess
(
    const NvM_BlockIdType BlockId
);
extern FUNC(void, NVM_CODE)  NvM_ValidateAllJobProcess(void);
#endif


#if((STD_ON == NVM_CRC_ENABLE) && (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON))
extern FUNC(void, NVM_CODE)  NvM_SetRamStatusProcess
(
    const NvM_BlockIdType BlockId
);
#endif

#if(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)

#if(STD_ON == NVM_ERASE_API)
extern FUNC(void, NVM_CODE)  NvM_EraseProcess
(
    const NvM_BlockIdType BlockId
);
#endif

#if(STD_ON == NVM_INVALID_NVBLOCK_API)
extern FUNC(void, NVM_CODE)  NvM_InvalidProcess
(
    const NvM_BlockIdType BlockId
);
#endif
#endif

extern FUNC(void, NVM_CODE)  NvM_JobNotification(void);

#if(STD_ON == NVM_CIPHER_ENABLE)
extern FUNC(void, NVM_CODE)  NvM_JobCryptEndNotification(void);
extern FUNC(void, NVM_CODE)  NvM_JobCryptErrorNotification(void);
#endif

extern FUNC(uint8, NVM_CODE)  NvM_CheckPerRamConfig
(
    NvM_BlockIdType BlockId,
    P2P2VAR(uint8, AUTOMATIC, AUTOMATIC) dataPtr
);

extern FUNC(void, NVM_CODE) NvM_ReplaceWithImmJob(void);

extern FUNC(NvM_BlockRequestType, NVM_CODE) NvM_ServiceIdMapBlockRequest
(
    const uint8 ServiceId
);

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"


/*******************************************************************************
*   MACRO
*******************************************************************************/
/*******************************************************************************
* PRQA S 3453 MISRA-C:2004 Rule 19.7
* A function could probably be used instead of this function-like macro.
* These function-like macros make code easy to read.
* This part of code is verified manually and has no impact.
*******************************************************************************/
#define NVM_VALID_BIT(BlockId)  NvM_AdmBlock[BlockId].NvRamAttributes.A.NvValid
#define NVM_CHANGED_BIT(BlockId)  NvM_AdmBlock[BlockId].NvRamAttributes.A.NvChanged
#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
#define NVM_PROTECTED_BIT(BlockId)  NvM_AdmBlock[BlockId].NvRamAttributes.A.NvWriteProtect
#define NVM_WRITEONCE_READFIRST_BIT(BlockId)  NvM_AdmBlock[BlockId].NvRamAttributes.A.NvWriteOnceReadFirst
#endif
#if(STD_ON == NVM_SET_BLOCK_LOCK_API)
#define NVM_LOCK_BIT(BlockId)  NvM_AdmBlock[BlockId].NvRamAttributes.A.NvBlockLock
#endif

#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
#define NVM_LOSSR_BIT(BlockId)  NvM_AdmBlock[BlockId].NvRamAttributes.A.lossRedundant
#endif



#define NVM_SET_VALID_UNCHANGED(BlockId)    NvM_SetBlockAttibute(BlockId, TRUE, FALSE)
#define NVM_SET_VALID_CHANGED(BlockId)      NvM_SetBlockAttibute(BlockId, TRUE, TRUE)
#define NVM_SET_INVALID_UNCHANGED(BlockId)  NvM_SetBlockAttibute(BlockId, FALSE, FALSE)
#define NVM_SET_INVALID_CHANGED(BlockId)    NvM_SetBlockAttibute(BlockId, FALSE, TRUE)

#endif /* #ifndef _NvM_JobProc_H */


