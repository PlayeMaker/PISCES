/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : NvM_JobProc.c
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : NvM module source File
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
*   Revision History:
*   Reference to NvM.c File
********************************************************************************
* END_FILE_HDR*/

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 5087,3614,3214,862,857,3892,3206 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "EcuM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in EcuM_MemMap.h.
Macro definitions exceed 1024.The number of macros is unlimited.
*/

/*PRQA S 2100,2101,2000,2111 EOF*/
/*
Integer promotion related
*/

/*PRQA S 3212,3227,3204,3352 EOF*/
/*
Unified requirements of EAS: constant shall be converted.
Read-only function input parameters may not be defined as const,it does not affect the function.
AUTOSAR API shall define standard input parameters according to specification requirements
*/

/*PRQA S 3138,3141 EOF*/
/*
The code of critical segments can be configured as void when QAC testing.
Note:When called by Det,Dem or BswM, the critical segments must be enabled when
QAC testing.Reasons are needed for special circumstances not enabled.
*/

/*PRQA S 3416,3432,3429,3453 EOF*/
/*
In a If statement,calling a function to directly determine the return value is allowed if there is only one judge branch.
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no need to revise.
Macro functions are allowed to use to access configuration parameters.
*/

/*PRQA S 3383 EOF*/
/*
Addition and subtraction operations on internal variables of dcm doesn't overflow.
*/

/*PRQA S 776 EOF*/
/*
Names in core files may not follow relevant rules..
*/

/*PRQA S 4599,4571 EOF*/
/*
Specific implementation methods.
*/

/*******************************************************************************
*   include  NVM554
*******************************************************************************/
#include "NvM.h"
#include "NvM_Lcfg.h"
#include "Bsw_Common.h"
#if(STD_ON == NVM_BSWM_SUPPORT)
#include "BswM_NvM.h"
#endif
#if(NVM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"/*NVM556*/
#endif
#if(STD_ON == NVM_DEM_SUPPORT)
#include "Dem.h"
#endif
#if(STD_ON == NVM_CIPHER_ENABLE)
#include "Csm.h"
#endif
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
#include "NvM_Agent.h"
#endif
/*******************************************************************************
*   Macro
*******************************************************************************/


/*******************************************************************************
*   NvM Internal Data define
*******************************************************************************/
#define NVM_START_SEC_VAR_INIT_GLOBAL_8
#include "NvM_MemMap.h"
VAR(NvM_State_Type, NVM_VAR)     NvM_TaskState = NVM_STATE_UNINIT;
#define NVM_STOP_SEC_VAR_INIT_GLOBAL_8
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_LOCAL_8
#include "NvM_MemMap.h"

VAR(boolean, NVM_VAR_NOINIT)    NvM_CancelWriteAllFlag;

STATIC VAR(NvM_JobSubState_Type, NVM_VAR_NOINIT) NvM_JobSubState;
VAR(boolean, NVM_VAR_NOINIT) NvM_CfgIdMatch;
#if((STD_ON == NVM_AUTO_WRITE_RETRY) || (STD_ON == NVM_AUTO_READ_RETRY))
STATIC VAR(uint8, NVM_VAR_NOINIT) NvM_OpRetryNum;
#endif
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
STATIC VAR(uint8, NVM_VAR_NOINIT) NvM_MirrorOpNum;
#endif

STATIC VAR(NvM_RequestResultType, NVM_VAR_NOINIT)  NvM_TempNvErrStatus;
#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
STATIC VAR(NvM_RequestResultType, NVM_VAR_NOINIT)  NvM_savedNv0ResultType;
#endif


#define NVM_STOP_SEC_VAR_CLEARED_LOCAL_8
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_LOCAL_16
#include "NvM_MemMap.h"
STATIC VAR(uint16, NVM_VAR_NOINIT) NvM_OpDataIndex;
STATIC VAR(uint16, NVM_VAR_NOINIT) NvM_OpLeftLength;

#define NVM_STOP_SEC_VAR_CLEARED_LOCAL_16
#include "NvM_MemMap.h"

#if(STD_ON == NVM_CRC_ENABLE)
#define NVM_START_SEC_VAR_CLEARED_LOCAL_32
#include "NvM_MemMap.h"
STATIC VAR(uint32, NVM_VAR_NOINIT) NvM_NvCrcResult;
#define NVM_STOP_SEC_VAR_CLEARED_LOCAL_32
#include "NvM_MemMap.h"
#endif

#define NVM_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "NvM_MemMap.h"
VAR(NvM_QueBuf_Type, NVM_VAR_NOINIT)    NvM_CurrentJobInfo;
#define NVM_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "NvM_MemMap.h"

#define NVM_DATA_8         8


/*******************************************************************************
*   NvM Internal function define
*******************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
STATIC FUNC(void, NVM_CODE) NvM_SingleJobStop
(
    const NvM_BlockIdType BlockId,
    const NvM_RequestResultType ReqResult
);
STATIC FUNC(uint8, NVM_CODE) NvM_GetUsedRamBlockType
(
    const NvM_BlockIdType BlockId
);
#if(STD_ON == NVM_CRC_ENABLE)
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_CRC_Process
(
    const NvM_BlockIdType BlockId
);

STATIC FUNC(uint32, NVM_CODE)  NvM_ReadRamCrcResult
(
    const NvM_BlockIdType BlockId
);

STATIC FUNC(void, NVM_CODE) NvM_WriteCrcResultToRam
(
    const NvM_BlockIdType BlockId
);
#endif
#if(STD_ON == NVM_CRC_COMP_ENABLE)
STATIC FUNC(boolean, NVM_CODE)  NvM_CompareCrcIsDifferent
(
    NvM_BlockIdType BlockId
);
#endif
STATIC FUNC(NvM_RequestResultType, NVM_CODE) NvM_GetMultiReqResult(void);
STATIC FUNC(void, NVM_CODE) NvM_MultiFirstInitAllEndProcess(void);

#if((STD_CONFIG_VARIANTS_PRECOMPILE != NVM_CONFIG_VARIANTS) || (NVM_DATASET_SELECTION_BITS > 0))
STATIC FUNC(NvM_BlockIdType, NVM_CODE) NvM_GetPhyBlockId
(
    const NvM_BlockIdType BlockId
);
#endif
#if(STD_ON == NVM_BLOCKID_CHECK)
STATIC FUNC(void, NVM_CODE) NvM_FillBlockId
(
    const NvM_BlockIdType BlockId
);
#endif
#if((STD_ON == NVM_BLOCKID_CHECK) || (STD_ON == NVM_CRC_ENABLE) || (STD_ON == NVM_CIPHER_ENABLE))
STATIC FUNC(uint16, NVM_CODE)  NvM_GetBlockLength
(
    const NvM_BlockIdType BlockId
);
#endif
#if(STD_ON == NVM_BLOCKID_CHECK)
STATIC FUNC(boolean, NVM_CODE) NvM_CheckStaticId
(
    const NvM_BlockIdType BlockId
);
#endif
STATIC FUNC(void, NVM_CODE) NvM_ReadBlockEndNotification
(
    const NvM_BlockIdType BlockId,
    const MemIf_JobResultType JobResult
);

STATIC FUNC(boolean, NVM_CODE)  NvM_ReadPreEndProcess
(
    const NvM_BlockIdType BlockId
);
STATIC FUNC(Std_ReturnType, NVM_CODE)  NvM_CopyRomToRam
(
    const NvM_BlockIdType BlockId
);
STATIC FUNC(boolean, NVM_CODE)  NvM_RetryWrite
(
    const NvM_BlockIdType BlockId
);
#if(STD_ON == NVM_WRITE_VER)
STATIC FUNC(void, NVM_CODE) NvM_ReadBackEndNotification
(
    const NvM_BlockIdType BlockId
);
#endif

STATIC FUNC(void, NVM_CODE) NvM_MultiReadJobEndProcess(void);
STATIC FUNC(void, NVM_CODE) NvM_MultiWriteJobEndProcess(void);

#if((NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) || (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2))
STATIC FUNC(void, NVM_CODE) NvM_Restore_DataReadEnd
(
    const NvM_BlockIdType BlockId
);
#endif


#ifdef  NVM_E_REQ_FAILED_EVENTID
STATIC FUNC(void, NVM_CODE) NvM_DemCheckReqFailEvent(NvM_RequestResultType reqResult);
#endif

#ifdef  NVM_E_INTEGRITY_FAILED_EVENTID
STATIC FUNC(void, NVM_CODE) NvM_DemCheckInteFailEvent(NvM_RequestResultType reqResult);
#endif

#ifdef  NVM_E_WRONGID_EVENTID
STATIC FUNC(void, NVM_CODE) NvM_DemCheckWrongIdEvent(NvM_RequestResultType reqResult);
#endif


#ifdef  NVM_E_VERIFY_FAILED_EVENTID
STATIC FUNC(void, NVM_CODE) NvM_DemCheckVerFailEvent(NvM_RequestResultType reqResult);
#endif


#ifdef  NVM_E_LOSS_R_EVENTID
STATIC FUNC(void, NVM_CODE) NvM_DemCheckLossREvent(boolean lossFlag);
#endif

#ifdef  NVM_E_HARDWARE
STATIC FUNC(void, NVM_CODE) NvM_DemCheckHardwareError(NvM_RequestResultType reqResult);
#endif

STATIC FUNC(void, NVM_CODE) NvM_ReadEnd
(
    const NvM_BlockIdType BlockId
);
STATIC FUNC(void, NVM_CODE) NvM_MultiJobStop
(
    const NvM_RequestResultType reqResult
);

#if(STD_ON == NVM_IMM_BLOCK_SUPPORT)
STATIC FUNC(boolean, NVM_CODE) NvM_CheckPendingWhenImmJobFinish
(
    const NvM_BlockIdType BlockId
);
#endif

STATIC FUNC(void, NVM_CODE) NvM_MultiValidateJobEndProcess(void);

STATIC FUNC(uint8, NVM_CODE)  NvM_isSkipReadAll
(
    NvM_BlockIdType BlockId
);

STATIC FUNC(boolean, NVM_CODE)  NvM_isSkipWriteAll
(
    NvM_BlockIdType BlockId
);

STATIC FUNC(void, NVM_CODE) NvM_InitBlocksPendingInMultiJob(void);

STATIC FUNC(void, NVM_CODE)  NvM_InitImplicitRestore
(
    NvM_BlockIdType BlockId
);

#if(STD_ON == NVM_DYNAMIC_CONFIGURATION)
STATIC FUNC(void, NVM_CODE)  NvM_CheckCfgIdMisMatch
(
    P2VAR(NvM_RequestResultType, AUTOMATIC, AUTOMATIC) result
);
#endif

#if(STD_ON == NVM_USE_SYNC_MECHANISM)
STATIC FUNC(boolean, NVM_CODE)  NvM_CallReadRamCbkProcess
(
    NvM_BlockIdType BlockId,
    NvM_JobSubState_Type substate,
    NvM_JobSubState_Type failsubstate
);
STATIC FUNC(boolean, NVM_CODE)  NvM_CallWriteRamCbkProcess
(
    NvM_BlockIdType BlockId,
    NvM_JobSubState_Type substate,
    NvM_JobSubState_Type failsubstate
);
#endif

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
STATIC FUNC(void, NVM_CODE) NvM_FisrtInitALL_Restore_DataReadEnd
(
    const NvM_BlockIdType BlockId
);
#if(STD_ON == NVM_FIRST_INIT_ALL_SUPPORT)
STATIC FUNC(boolean, NVM_CODE)  NvM_isSkipFirstInitAll
(
    NvM_BlockIdType BlockId
);
#endif
#endif


#if(STD_ON == NVM_CIPHER_ENABLE)
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_Encrypt_Process
(
    const NvM_BlockIdType BlockId
);
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_Decrypt_Process
(
    const NvM_BlockIdType BlockId
);
#endif

#if(STD_ON == NVM_COMPRESSION_ENABLE)
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_Compression_Process
(
    const NvM_BlockIdType BlockId
);
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_Decompression_Process
(
    const NvM_BlockIdType BlockId
);
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_DemReport
*
* Description:  funtion to report event to dem
*
* Inputs:       BlockId
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
#ifdef  NVM_E_REQ_FAILED_EVENTID
STATIC FUNC(void, NVM_CODE) NvM_DemCheckReqFailEvent(NvM_RequestResultType reqResult)
{
    if(NVM_REQ_NOT_OK == reqResult)
    {
        NVM_DEM_REPORT_E_REQ_FAILED(DEM_EVENT_STATUS_FAILED);
    }
    else
    {
        NVM_DEM_REPORT_E_REQ_FAILED(DEM_EVENT_STATUS_PASSED);
    }
}
#else
#define  NvM_DemCheckReqFailEvent(reqResult)
#endif

#ifdef  NVM_E_INTEGRITY_FAILED_EVENTID
STATIC FUNC(void, NVM_CODE) NvM_DemCheckInteFailEvent(NvM_RequestResultType reqResult)
{
    if((NVM_REQ_INTEGRITY_FAILED == reqResult)
            || (NVM_REQ_CFGID_MISMATCH == reqResult))
    {
        NVM_DEM_REPORT_E_INTEGRITY_FAILED(DEM_EVENT_STATUS_FAILED);
    }
    else
    {
        NVM_DEM_REPORT_E_INTEGRITY_FAILED(DEM_EVENT_STATUS_PASSED);
    }
}
#else
#define  NvM_DemCheckInteFailEvent(reqResult)
#endif

#ifdef  NVM_E_WRONGID_EVENTID
STATIC FUNC(void, NVM_CODE) NvM_DemCheckWrongIdEvent(NvM_RequestResultType reqResult)
{
    if(NVM_REQ_WRONGID == reqResult)
    {
        NVM_DEM_REPORT_E_WRONG_BLOCK_ID(DEM_EVENT_STATUS_FAILED);
    }
    else
    {
        NVM_DEM_REPORT_E_WRONG_BLOCK_ID(DEM_EVENT_STATUS_PASSED);
    }
}
#else
#define  NvM_DemCheckWrongIdEvent(reqResult)
#endif


#ifdef  NVM_E_VERIFY_FAILED_EVENTID
STATIC FUNC(void, NVM_CODE) NvM_DemCheckVerFailEvent(NvM_RequestResultType reqResult)
{
    if(NVM_REQ_VERIFY_FAILED == reqResult)
    {
        NVM_DEM_REPORT_E_VERIFY_FAILED(DEM_EVENT_STATUS_FAILED);
    }
    else
    {
        NVM_DEM_REPORT_E_VERIFY_FAILED(DEM_EVENT_STATUS_PASSED);
    }
}
#else
#define  NvM_DemCheckVerFailEvent(reqResult)
#endif


#ifdef  NVM_E_LOSS_R_EVENTID
STATIC FUNC(void, NVM_CODE) NvM_DemCheckLossREvent(boolean lossFlag)
{
    if(TRUE == lossFlag)
    {
        NVM_DEM_REPORT_E_LOSS_OF_REDUNDANCY(DEM_EVENT_STATUS_FAILED);
    }
    else
    {
        NVM_DEM_REPORT_E_LOSS_OF_REDUNDANCY(DEM_EVENT_STATUS_PASSED);
    }
}
#else
#define  NvM_DemCheckLossREvent(lossFlag)
#endif


#ifdef  NVM_E_HARDWARE
STATIC FUNC(void, NVM_CODE) NvM_DemCheckHardwareError(NvM_RequestResultType reqResult)
{
    if((NVM_REQ_NOT_OK == reqResult)
            || (NVM_REQ_INTEGRITY_FAILED == reqResult))
    {
        NVM_DEM_REPORT_E_HARDWARE(DEM_EVENT_STATUS_FAILED);
    }
    else
    {
        NVM_DEM_REPORT_E_HARDWARE(DEM_EVENT_STATUS_PASSED);
    }
}
#else
#define  NvM_DemCheckHardwareError(reqResult)
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ReadEnd
*
* Description:  funtion to process when read job is finish
*
* Inputs:       BlockId
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, NVM_CODE) NvM_ReadEnd
(
    const NvM_BlockIdType BlockId
)
{
    NvM_RequestResultType ReqResult;


    if(NVM_READ_IMPLICIT_REC_MASK == ((NvM_RequestResultType)(NvM_TempNvErrStatus & NVM_READ_IMPLICIT_REC_MASK)))
    {
        ReqResult = NVM_REQ_RESTORED_DEFAULTS;
        NvM_TempNvErrStatus &= NVM_READ_IMPLICIT_REC_CMASK;
    }
    else
    {
        ReqResult = NvM_TempNvErrStatus;
    }

    NvM_DemCheckReqFailEvent(NvM_TempNvErrStatus);
    NvM_DemCheckInteFailEvent(NvM_TempNvErrStatus);
    NvM_DemCheckWrongIdEvent(NvM_TempNvErrStatus);
    NvM_DemCheckHardwareError(NvM_TempNvErrStatus);
#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
    if(NVM_BLOCK_REDUNDANT == NvM_Config[BlockId].BlockType)
    {
        NvM_DemCheckLossREvent(NVM_LOSSR_BIT(BlockId));
    }
#endif

    if(NvM_GetUsedRamBlockType(BlockId) >= NVM_PROCESS_PER_RAM_BLOCK)
    {
        if(NVM_REQ_OK == ReqResult)
        {
            NVM_SET_VALID_UNCHANGED(BlockId);    /*NVM228*/
        }
        else if(NVM_REQ_RESTORED_DEFAULTS == ReqResult)
        {
            NVM_SET_VALID_CHANGED(BlockId);
        }
        else
        {
            NVM_SET_INVALID_UNCHANGED(BlockId);
        }
    }


#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
    /*NVM314 316*/
    if(TRUE == NvM_Config[BlockId].EnWriteOnce)
    {
        if(NVM_REQ_OK == ReqResult)
        {
            NVM_PROTECTED_BIT(BlockId) = TRUE;
        }
        else
        {
            /*need to dicuss*/
            if(TRUE == (boolean)NVM_PROTECTED_BIT(BlockId))
            {
                if((NVM_REQ_NOT_OK == ReqResult)
                        || (NVM_REQ_INTEGRITY_FAILED == ReqResult)
                        || (NVM_REQ_NV_INVALIDATED == ReqResult)
                        || (NVM_REQ_RESTORED_DEFAULTS == ReqResult)
                        || (NVM_REQ_WRONGID == ReqResult))
                {
                    NVM_PROTECTED_BIT(BlockId) = FALSE;
                }
            }

        }
        NVM_WRITEONCE_READFIRST_BIT(BlockId) = TRUE;
    }
#endif

#if(STD_ON == NVM_DYNAMIC_CONFIGURATION)
    NvM_CheckCfgIdMisMatch(&ReqResult);
#endif

    NvM_SingleJobStop(BlockId, ReqResult);

}


/* BEGIN_FUNCTION_HDR
****************************************************
* Function Name: NvM_CheckPendingWhenImmJobFinish
*
* Description:  when immjob is finish, check if the same block is pending in
*               Standard queue or multi job
*
* Inputs:       BlockId
*
* Outputs:      boolean
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == NVM_IMM_BLOCK_SUPPORT)
STATIC FUNC(boolean, NVM_CODE) NvM_CheckPendingWhenImmJobFinish
(
    const NvM_BlockIdType BlockId
)
{
    boolean ret = FALSE;

    ret =  NvM_CheckBlockPending(BlockId, FALSE);
    if(FALSE == ret)
    {
        if((NVM_JOB_READALL == NvM_MultiJob.ServiceId)
                || (NVM_JOB_VALIDATEALL == NvM_MultiJob.ServiceId))
        {
            if(NvM_MultiJob.BlockId < BlockId)
            {
                ret = TRUE;
            }
        }
        else if(NVM_JOB_WRITEALL == NvM_MultiJob.ServiceId)
        {

            if(BlockId == NVM_CFGID_BLOCK_HANDLE)
            {
                ret = TRUE;
            }
            else if(NVM_CFGID_BLOCK_HANDLE == NvM_MultiJob.BlockId)
            {
                ret = FALSE;
            }
            else
            {
                if(NvM_MultiJob.BlockId < BlockId)
                {
                    ret = TRUE;
                }
            }
        }
        else
        {
            ret = FALSE;
        }
    }

    return ret;

}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ServiceIdMapBlockRequest
*
* Description:  Correspond to ServiceId through BlockRequest
*
* Inputs:       ServiceId
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(NvM_BlockRequestType, NVM_CODE) NvM_ServiceIdMapBlockRequest
(
    const uint8 ServiceId
)
{
    NvM_BlockRequestType BlockRequest = (uint8)0xFF;
    switch(ServiceId)
    {
    case NVM_READ_BLOCK_APIID:
    case NVM_READ_PRAMBLOCK:
        BlockRequest = NVM_READ_BLOCK;
    break;
    case NVM_WRITE_BLOCK_APIID:
    case NVM_WRITE_PRAMBLOCK:
        BlockRequest = NVM_WRITE_BLOCK;
    break;
    case NVM_RESTORE_BLOCK_DEFAULTS_APIID:
    case NVM_RESTORE_PRAMBLOCK:
        BlockRequest = NVM_RESTORE_BLOCK_DEFAULTS;
    break;
    case NVM_ERASE_BLOCK:
        BlockRequest = NVM_ERASE_NV_BLOCK;
    break;
    case NVM_INVALIDATE_NV_BLOCK_APIID:
        BlockRequest = NVM_INVALIDATE_NV_BLOCK;
    break;
    case NVM_READ_ALL:
        BlockRequest = NVM_READ_ALL_BLOCK;
    break;
    case NVM_WRITE_ALL:
        BlockRequest = NVM_WRITE_ALL_BLOCK;
    break;
    default:
    break;
    }
    return BlockRequest;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_SingleJobStop
*
* Description:  funtion to process single job end
*
* Inputs:       BlockId,JobResult
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, NVM_CODE) NvM_SingleJobStop
(
    const NvM_BlockIdType BlockId,
    const NvM_RequestResultType ReqResult
)
{
    uint8 SevId = NvM_CurrentJobInfo.ServiceId;
    NvM_BlockRequestType BlockRequest = (NvM_BlockRequestType)0xFF;
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
    uint8 AgentBackJobIndex;
    P2VAR(uint8, AUTOMATIC, NVM_VAR) tempBackServiceFlagPtr = NULL_PTR;
    P2VAR(NvM_RequestResultType, AUTOMATIC, NVM_VAR) tempBackResultPtr = NULL_PTR;
#endif

    NvM_TempNvErrStatus = NVM_REQ_OK;
#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
    if(NVM_BLOCK_DATASET != NvM_Config[BlockId].BlockType)
    {
        NvM_AdmBlock[BlockId].NvDataIndex = (uint8)0;
    }
    NvM_savedNv0ResultType = NVM_REQ_OK;
#endif

    /*NvM_AdmBlock[BlockId].NvErrStatus has been write before */

    /* single job reset state before call out*/
    if((NVM_JOB_READALL != NvM_CurrentJobInfo.ServiceId)
            && (NVM_JOB_WRITEALL != NvM_CurrentJobInfo.ServiceId)
            && (NVM_JOB_VALIDATEALL != NvM_CurrentJobInfo.ServiceId)
            &&(NVM_JOB_FIRSTINITALL != NvM_CurrentJobInfo.ServiceId))
    {
        /* not multi job reset job queue state */
        NvM_AdmBlock[BlockId].NvErrStatus = ReqResult;
#if(STD_ON == NVM_BSWM_SUPPORT)
        /* only reprot bswM when single job is finish, report real result here first*/
        if(TRUE == NvM_Config[BlockId].EnReportBswM)
        {
            BswM_NvM_CurrentBlockMode(BlockId, ReqResult);
        }
#endif


#if(STD_ON == NVM_IMM_BLOCK_SUPPORT)
        /* if immjob finish, check if multi and Standard queue still has this block*/
        if(((uint8)0 == NvM_Config[BlockId].BlockPri)
                && ((NVM_JOB_WRITE == NvM_CurrentJobInfo.ServiceId) || (NVM_JOB_WRITE_PRAMBLOCK == NvM_CurrentJobInfo.ServiceId)))
        {
            SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
            if(TRUE == NvM_CheckPendingWhenImmJobFinish(BlockId))
            {
                NvM_AdmBlock[BlockId].NvErrStatus = NVM_REQ_PENDING;
#if(STD_ON == NVM_BSWM_SUPPORT)
                /* report pending at once if there is still same block job pending*/
                if(TRUE == NvM_Config[BlockId].EnReportBswM)
                {
                    BswM_NvM_CurrentBlockMode(BlockId, NVM_REQ_PENDING);
                }
#endif
            }
            SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();
        }
#endif

        NvM_ResetJobState();


    }
    else
    {
        /*write all or readall*/
        NvM_AdmBlock[BlockId].multiNvErrStatus = ReqResult;
        SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
        if(TRUE == NvM_CheckBlockPending(BlockId, FALSE))
        {
            NvM_AdmBlock[BlockId].NvErrStatus = NVM_REQ_PENDING;
        }
        else
        {
            NvM_AdmBlock[BlockId].NvErrStatus = ReqResult;
        }
        SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();
    }


    /* since Block0 and Block1 will never config single call back */
    if(NvM_SingleCallBackFunPtr[BlockId] != NVM_NULL)
    {
        /*
        NVM467 NvM_SingleCallBackFunPtr will always return E_OK
        */
#if(NVM_AGENT_BACK_JOB_MAX_NUM > 0)
       if(CurrentCoreId != NvM_Config[BlockId].PhyCoreId)
       {
            // NvM_AgentCmdSync(LogicCoreId, SevId, BlockId, ReqResult);
            AgentBackJobIndex = NvM_Config[BlockId].AgentBackJobIndex;
            if(NVM_INVALID_AGENT_JOB_INDEX != AgentBackJobIndex)
            {
                tempBackServiceFlagPtr = NVM_AGENT_BACK_JOB_SERVICE_FLAG_PTR(AgentBackJobIndex);
                if(NVM_NO_SERVICE == *tempBackServiceFlagPtr)
                {
                    tempBackResultPtr = NVM_AGENT_BACK_JOB_RESULT_PTR(AgentBackJobIndex);
                    *tempBackServiceFlagPtr = SevId;
                    *tempBackResultPtr = ReqResult;
                }
            }
       }
       else
#endif
        {
            BlockRequest = NvM_ServiceIdMapBlockRequest(SevId);
            (void)NvM_SingleCallBackFunPtr[BlockId](BlockRequest, ReqResult);
        }

    }

    if(NVM_JOB_READALL == NvM_CurrentJobInfo.ServiceId)
    {
        NvM_MultiReadJobEndProcess();
    }
    else if(NVM_JOB_WRITEALL == NvM_CurrentJobInfo.ServiceId)
    {
        NvM_MultiWriteJobEndProcess();
    }
    else if(NVM_JOB_VALIDATEALL == NvM_CurrentJobInfo.ServiceId)
    {
        NvM_MultiValidateJobEndProcess();
    }
    else if(NVM_JOB_FIRSTINITALL == NvM_CurrentJobInfo.ServiceId)
    {
        NvM_MultiFirstInitAllEndProcess();
    }
    else
    {
        /* do nothing */ 
    }


}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_GetUsedRamBlockType
*
* Description:  Function to check if need to opration the valid&change bit
*
* Inputs:       BlockId
*
* Outputs:      0- No ram block
*               1- Temp Ram Block
*               2- user Ram Block
*               3- mirror Ram Block
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, NVM_CODE) NvM_GetUsedRamBlockType
(
    const NvM_BlockIdType BlockId
)
{
    uint8 ret = NVM_PROCESS_TEMP_RAM_BLOCK;


    if(NVM_NULL == NvM_CurrentJobInfo.RamAddr)
    {
        ret = NVM_PROCESS_NORAM_BLOCK;
    }
    else if(NvM_Config[BlockId].RamAddr == NvM_CurrentJobInfo.RamAddr)
    {
        ret = NVM_PROCESS_PER_RAM_BLOCK;
    }
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
    else if((TRUE == NvM_Config[BlockId].EnUseSynM) && (NvM_MirrorBuffer == NvM_CurrentJobInfo.RamAddr))
    {
        ret = NVM_PROCESS_SYN_RAM_BLOCK;
    }
#endif
    else
    {
    }

    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_GetMultiReqResult
*
* Description:  Function to get multi job end reesult
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(NvM_RequestResultType, NVM_CODE) NvM_GetMultiReqResult(void)
{
    NvM_BlockIdType idIndex;
    NvM_RequestResultType result = NVM_REQ_OK;
    NvM_RequestResultType JobResult;


    for(idIndex = NVM_USER_BLOCKID_START; idIndex < NVM_TOTAL_NUM_OF_NVRAM_BLOCKS; idIndex++)
    {
        JobResult = NvM_AdmBlock[idIndex].multiNvErrStatus;
        if((JobResult != NVM_REQ_OK)
                && (JobResult != NVM_REQ_BLOCK_SKIPPED)
                && (JobResult != NVM_REQ_CANCELED)
                && (JobResult != NVM_REQ_NV_INVALIDATED)) /* single block may pengding when multi job is ongoing*/
        {
            result = NVM_REQ_NOT_OK;/*NVM301 NVM318 one bock fail, multi job fail*/
            break;
        }
    }


    /*clear multi result*/
    for(idIndex = NVM_USER_BLOCKID_START; idIndex < NVM_TOTAL_NUM_OF_NVRAM_BLOCKS; idIndex++)
    {
        NvM_AdmBlock[idIndex].multiNvErrStatus = NVM_REQ_OK;
    }

    return result;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_GetBlockLength
*
* Description:  get real block length, eith CRC and header
*
* Inputs:       BlockId
*
* Outputs:      length
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
#if((STD_OFF == NVM_BLOCKID_CHECK) && (STD_OFF == NVM_CRC_ENABLE) && (STD_OFF == NVM_CIPHER_ENABLE))
#define NvM_GetBlockLength(BlockId)   NvM_Config[(BlockId)].Length
#else
STATIC FUNC(uint16, NVM_CODE)  NvM_GetBlockLength
(
    const NvM_BlockIdType BlockId
)
{
    uint16 length;

    length = NvM_Config[(BlockId)].Length;
#if(STD_ON == NVM_CIPHER_ENABLE)
    if(TRUE == NvM_Config[BlockId].EnCipher)
    {
        length = NvM_Config[BlockId].NvM_Cipher->Length;
    }
#endif

#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)
    /* read dataset rom block, no header and crc bytes */
    if((NVM_BLOCK_DATASET == NvM_Config[BlockId].BlockType)
            && (NvM_AdmBlock[BlockId].NvDataIndex >= NvM_Config[BlockId].NvBlockNum))
    {
        length = NvM_Config[BlockId].Length;
    }
    else
#endif
    {
#if(STD_ON == NVM_BLOCKID_CHECK)
        if(TRUE == NvM_Config[BlockId].EnIdCheck)
        {
            length = length + NVM_BLOCKID_BYTES;
        }
#endif

#if(STD_ON == NVM_CRC_ENABLE)
        if(TRUE == NvM_Config[BlockId].EnCrc)
        {
            length = length + NvM_Config[BlockId].CrcType;
        }
#endif
    }

    return length;
}
#endif




#if(STD_ON == NVM_CRC_ENABLE)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_CRC_Process
*
* Description:  caculate CRC
*
* Inputs:       BlockId
*
* Outputs:      Std_ReturnType caculate finish or not
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_CRC_Process
(
    const NvM_BlockIdType BlockId
)
{
    Std_ReturnType ret = E_OK;
    CONSTP2CONST(uint8, AUTOMATIC, AUTOMATIC) data = NvM_CurrentJobInfo.RamAddr;
    const uint16 crcType = NvM_Config[BlockId].CrcType;
    uint16 templen;
    boolean firstFlag = FALSE;



    /* first time call CRC */
    if((uint16)0 == NvM_OpDataIndex)
    {
        NvM_OpLeftLength = NvM_Config[BlockId].Length;
#if(STD_ON == NVM_CIPHER_ENABLE)
        if(TRUE == NvM_Config[BlockId].EnCipher)
        {
            NvM_OpLeftLength = NvM_Config[BlockId].NvM_Cipher->Length;
        }
#endif
        NvM_NvCrcResult = NVM_CRC_INITVALUE;

        firstFlag = TRUE;
    }


    if(NvM_OpLeftLength > (uint16)0)
    {
        templen = NvM_OpLeftLength;
        if(templen >= NVM_CRC_NUM_OF_BYTES)
        {
            templen = NVM_CRC_NUM_OF_BYTES;
        }

#if(STD_ON ==NVM_CRC8_SUPPORT)
        if(NVM_CRC8 == crcType)
        {
            NvM_NvCrcResult =
                NvM_Crc8CalculateCallout(&data[NvM_OpDataIndex],
                                         (uint32)templen,
                                         (uint8)NvM_NvCrcResult,
                                         firstFlag);

        }
#endif
#if(STD_ON ==NVM_CRC16_SUPPORT)
        if(NVM_CRC16 == crcType)
        {
            NvM_NvCrcResult =
                NvM_Crc16CalculateCallout(&data[NvM_OpDataIndex],
                                          (uint32)templen,
                                          (uint16)NvM_NvCrcResult,
                                          firstFlag);
        }
#endif

#if(STD_ON ==NVM_CRC32_SUPPORT)
        if(NVM_CRC32 == crcType)
        {
            NvM_NvCrcResult =
                NvM_Crc32CalculateCallout(&data[NvM_OpDataIndex],
                                          (uint32)templen,
                                          NvM_NvCrcResult,
                                          firstFlag);
        }
#endif


        if(NvM_OpLeftLength > NVM_CRC_NUM_OF_BYTES)
        {
            NvM_OpLeftLength = NvM_OpLeftLength - NVM_CRC_NUM_OF_BYTES;
            NvM_OpDataIndex = NvM_OpDataIndex + NVM_CRC_NUM_OF_BYTES;
            ret = E_NOT_OK;
        }
        else
        {
            NvM_OpLeftLength = (uint16)0;
            NvM_OpDataIndex = (uint16)0;
            ret = E_OK;
        }
    }

    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ReadRamCrcResult
*
* Description:  read a CRC from ram .
*
* Inputs:       BlockId
*
* Outputs:      crcResult
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint32, NVM_CODE)  NvM_ReadRamCrcResult
(
    const NvM_BlockIdType BlockId
)
{
    CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) RamAddress = NvM_CurrentJobInfo.RamAddr;
    uint16 len;
    const uint16 crcType = NvM_Config[BlockId].CrcType;
    uint32 crcResult;

    len = NvM_Config[BlockId].Length;
#if(STD_ON == NVM_CIPHER_ENABLE)
    if(TRUE == NvM_Config[BlockId].EnCipher)
    {
        len = NvM_Config[BlockId].NvM_Cipher->Length;
    }
#endif

#if(STD_ON ==NVM_CRC32_SUPPORT)
    uint32 temp1;
    uint32 temp2;
#endif

#if(STD_ON == NVM_BLOCKID_CHECK)
    if(TRUE == NvM_Config[BlockId].EnIdCheck)
    {
        len = len + NVM_BLOCKID_BYTES;
    }
#endif

#if(STD_ON ==NVM_CRC8_SUPPORT)
    if(NVM_CRC8 == crcType)
    {
        crcResult = RamAddress[len];
    }
#endif

#if(STD_ON ==NVM_CRC16_SUPPORT)
    if(NVM_CRC16 == crcType)
    {
        crcResult = RamAddress[len];
        crcResult = crcResult << (uint32)8;
        crcResult = crcResult | RamAddress[len + (uint16)1];
    }
#endif

#if(STD_ON ==NVM_CRC32_SUPPORT)
    if(NVM_CRC32 == crcType)
    {
        crcResult = RamAddress[len];
        crcResult = crcResult << (uint32)24;
        temp1 = RamAddress[len + (uint16)1];
        temp1 = temp1 << (uint32)16;
        temp2 = RamAddress[len + (uint16)2];
        temp2 = temp2 << (uint32)8;
        crcResult = crcResult | temp1 | temp2 | RamAddress[len + (uint16)3];
    }
#endif

    return crcResult;
}

#if(STD_ON == NVM_CRC_COMP_ENABLE)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_CompareCrcIsDifferent
*
* Description:  Read a CRC from CRC buffer or ram and compare.
*
* Inputs:       BlockId
*
* Outputs:      Result
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, NVM_CODE)  NvM_CompareCrcIsDifferent
(
    NvM_BlockIdType BlockId
)
{
    boolean Result = TRUE;
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) CRCCompAddr = NvM_Config[BlockId].CRCCompAddr;
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) RamAddr = NvM_Config[BlockId].RamAddr;
    uint16 CrcType = NvM_Config[BlockId].CrcType;
    uint32 CrcOld;

    if(NULL_PTR != CRCCompAddr)
    {
        if(NVM_CRC8 == CrcType)
        {
            CrcOld = *CRCCompAddr;
        }
        else if(NVM_CRC16 == CrcType)
        {
            CrcOld = ((uint32)CRCCompAddr[1] | ((uint32)CRCCompAddr[0] << (uint32)8));
        }
        else if(NVM_CRC32 == CrcType)
        {
            CrcOld = ((uint32)CRCCompAddr[3] | ((uint32)CRCCompAddr[2] << (uint32)8) \
                | ((uint32)CRCCompAddr[1] << (uint32)16) | ((uint32)CRCCompAddr[0] << (uint32)24));
        }
        else
        {
            /*do nothing*/
        }
    }
    else if(NULL_PTR !=  RamAddr)
    {
        CrcOld = NvM_ReadRamCrcResult(BlockId);
    }
    else
    {
        /*do nothing*/
    }
    if(CrcOld == NvM_NvCrcResult)
    {
        Result = FALSE;
    }

    return Result;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_WriteCrcResultToRam
*
* Description:  Write CRC result to ram block.
*
* Inputs:       BlockId,
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, NVM_CODE) NvM_WriteCrcResultToRam
(
    const NvM_BlockIdType BlockId
)
{
    CONSTP2VAR(uint8, AUTOMATIC, AUTOMATIC) RamAddress = NvM_CurrentJobInfo.RamAddr;
    uint16 len;
    const uint16 crcType = NvM_Config[BlockId].CrcType;

    len = NvM_Config[BlockId].Length;
#if(STD_ON == NVM_CIPHER_ENABLE)
    if(TRUE == NvM_Config[BlockId].EnCipher)
    {
        len = NvM_Config[BlockId].NvM_Cipher->Length;
    }
#endif

#if(STD_ON == NVM_BLOCKID_CHECK)
    if(TRUE == NvM_Config[BlockId].EnIdCheck)
    {
        len = len + NVM_BLOCKID_BYTES;
    }
#endif

#if(STD_ON ==NVM_CRC8_SUPPORT)
    if(NVM_CRC8 == crcType)
    {
        RamAddress[len] = (uint8)NvM_NvCrcResult;
    }
#endif

#if(STD_ON ==NVM_CRC16_SUPPORT)
    if(NVM_CRC16 == crcType)
    {
        RamAddress[len + (uint16)1] = (uint8)NvM_NvCrcResult;
        RamAddress[len] = (uint8)(NvM_NvCrcResult >> (uint32)8);
    }
#endif

#if(STD_ON ==NVM_CRC32_SUPPORT)
    if(NVM_CRC32 == crcType)
    {
        RamAddress[len + (uint16)3] = (uint8)NvM_NvCrcResult;
        RamAddress[len + (uint16)2] = (uint8)(NvM_NvCrcResult >> (uint32)8);
        RamAddress[len + (uint16)1] = (uint8)(NvM_NvCrcResult >> (uint32)16);
        RamAddress[len] = (uint8)(NvM_NvCrcResult >> (uint32)24);
    }
#endif
}
#endif/*#if(STD_ON == NVM_CRC_ENABLE)*/


#if(STD_ON == NVM_COMPRESSION_ENABLE)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_Compression_Process
*
* Description:  Block Compression
*
* Inputs:       BlockId
*
* Outputs:      Std_ReturnType process finish or not
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_Compression_Process
(
    const NvM_BlockIdType BlockId
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8* NvM_Databuf = NvM_Config[BlockId].NvM_Compression->CompressionBuffer;
    uint16 Comprelength = NvM_Config[BlockId].NvM_Compression->CompressionLength;
    uint16 Decomprelength;
    uint32 NvM_Lengthbuf;

    Decomprelength = NvM_GetBlockLength(BlockId);

    ret = NvM_Compression(BlockId, NvM_CurrentJobInfo.RamAddr, (uint32)Decomprelength, NvM_Databuf, &NvM_Lengthbuf);
    if(E_OK == ret)
    {
        if(Comprelength == (uint16)NvM_Lengthbuf)
        {
            Bsw_MemCpy(NvM_CurrentJobInfo.RamAddr, NvM_Databuf, NvM_Lengthbuf);
        }
        else
        {
            ret = E_NOT_OK;
        }
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_Decompression_Process
*
* Description:  Block Decompression
*
* Inputs:       BlockId
*
* Outputs:      Std_ReturnType process finish or not
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_Decompression_Process
(
    const NvM_BlockIdType BlockId
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8* NvM_Databuf = NvM_Config[BlockId].NvM_Compression->CompressionBuffer;
    uint16 Comprelength = NvM_Config[BlockId].NvM_Compression->CompressionLength;
    uint16 Decomprelength;
    uint32 NvM_Lengthbuf;

    Decomprelength = NvM_GetBlockLength(BlockId);
    ret = NvM_Decompression(BlockId, NvM_CurrentJobInfo.RamAddr, (uint32)Comprelength, NvM_Databuf, &NvM_Lengthbuf);
    if(E_OK == ret)
    {
        if(Decomprelength == (uint16)NvM_Lengthbuf)
        {
            Bsw_MemCpy(NvM_CurrentJobInfo.RamAddr, NvM_Databuf, NvM_Lengthbuf);
        }
        else
        {
            ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif



#if(STD_ON == NVM_CIPHER_ENABLE)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_Encrypt_Process
*
* Description:  Block Encrypt
*
* Inputs:       BlockId
*
* Outputs:      Std_ReturnType process finish or not
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_Encrypt_Process
(
    const NvM_BlockIdType BlockId
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint32 jobId = NvM_Config[BlockId].NvM_Cipher->EncryptionJobId;
    uint8* NvM_Databuf = NvM_Config[BlockId].CipherBuffer;
    uint16 length = NvM_Config[BlockId].Length;
    boolean loopFlag;
    Std_ReturnType ret;
    uint32 NvM_Lengthbuf;
    uint16 retryCount = (uint16)0;

    do{
        loopFlag = FALSE;
        ret = Csm_Encrypt(jobId, CRYPTO_OPERATIONMODE_SINGLECALL, NvM_CurrentJobInfo.RamAddr, (uint32)length, NvM_Databuf, &NvM_Lengthbuf);
        if(ret == E_OK)
        {
            if(NvM_Config[BlockId].NvM_Cipher->Length != (uint16)NvM_Lengthbuf)
            {
                NVM_DET_REPORT_ERROR(NVM_INTERNAL_WRITEPROC_APIID, NVM_E_BLOCK_CHIPHER_LENGTH_MISSMATCH);
            }
            else
            {
                Bsw_MemCpy(NvM_CurrentJobInfo.RamAddr, NvM_Databuf, NvM_Lengthbuf);
                Result = E_OK;
            }
        }
        else if(ret == CRYPTO_E_BUSY)
        {
            if(retryCount < NvM_CSM_RETRY_COUNTER)
            {
                loopFlag = TRUE;
                retryCount++;
            }
        }
        else
        {
            /*do nothing*/
        }
    }while(loopFlag);

    return Result;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_Decrypt_Process
*
* Description:  Block Decrypt
*
* Inputs:       BlockId
*
* Outputs:      Std_ReturnType process finish or not
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, NVM_CODE) NvM_Decrypt_Process
(
    const NvM_BlockIdType BlockId
)
{
    Std_ReturnType Result = E_NOT_OK;
    uint32 jobId = NvM_Config[BlockId].NvM_Cipher->DecryptionJobId;
    uint8* NvM_Databuf = NvM_Config[BlockId].CipherBuffer;
    uint16 length = NvM_Config[BlockId].NvM_Cipher->Length;
    boolean loopFlag;
    Std_ReturnType ret;
    uint32 NvM_Lengthbuf = 0;
    uint16 retryCount = (uint16)0;

    do{
        loopFlag = FALSE;
        ret = Csm_Decrypt(jobId, CRYPTO_OPERATIONMODE_SINGLECALL, NvM_CurrentJobInfo.RamAddr, length, NvM_Databuf, &NvM_Lengthbuf);
        if(ret == E_OK)
        {
            if(NvM_Config[BlockId].Length != (uint16)NvM_Lengthbuf)
            {
                NVM_DET_REPORT_ERROR(NVM_INTERNAL_READPROC_APIID, NVM_E_BLOCK_CHIPHER_LENGTH_MISSMATCH);
            }
            else
            {
                Bsw_MemCpy(NvM_CurrentJobInfo.RamAddr, NvM_Databuf, (uint32)NvM_Lengthbuf);
                Result = E_OK;
            }
        }
        else if(ret == CRYPTO_E_BUSY)
        {
            if(retryCount < NvM_CSM_RETRY_COUNTER)
            {
                retryCount++;
                loopFlag = TRUE;
            }
        }
        else
        {
            /*do nothing*/
        }
    }while(loopFlag);

    return Result;
}


#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ResetJobState
*
* Description:  Function to reset All job state
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE) NvM_ResetJobState(void)
{
    
    NvM_JobSubState = NVM_SUBSTATE_IDLE;
    NvM_CurrentJobInfo.BlockId   = NVM_INVALID_BLOCKID;
    NvM_CurrentJobInfo.ServiceId = NVM_JOB_IDLE;
    NvM_CurrentJobInfo.RamAddr = NVM_NULL;
#if((STD_ON == NVM_AUTO_WRITE_RETRY) || (STD_ON == NVM_AUTO_READ_RETRY))
    NvM_OpRetryNum = (uint8)0;
#endif
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
    NvM_MirrorOpNum = (uint8)0;
#endif
    NvM_OpDataIndex = (uint16)0;
    NvM_OpLeftLength = (uint16)0;


#if(STD_ON == NVM_CRC_ENABLE)
    NvM_NvCrcResult = NVM_CRC_INITVALUE;
#endif

    NvM_TempNvErrStatus = NVM_REQ_OK;
#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
    NvM_savedNv0ResultType = NVM_REQ_OK;
#endif
    /* put this state at last line of this function to make sure that 
    other core can only start job after master core init */
    NvM_TaskState = NVM_STATE_IDLE;

}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_SetBlockAttibute
*
* Description:  Function to set block's state
*
* Inputs:       BlockId,valid,changed
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE) NvM_SetBlockAttibute
(
    const NvM_BlockIdType BlockId,
    const boolean valid,
    const boolean changed
)
{
    NVM_VALID_BIT(BlockId) = valid;
    NVM_CHANGED_BIT(BlockId) = changed;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_InitBlocksPendingInMultiJob
*
* Description:  Function to set block's state when multi job starts
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, NVM_CODE) NvM_InitBlocksPendingInMultiJob(void)
{
    NvM_BlockIdType idIndex = (NvM_BlockIdType)0;

    /* when back from imm job, NvM_CurrentJobInfo.BlockId!= 0;*/
    if((NvM_BlockIdType)0 == NvM_CurrentJobInfo.BlockId)
    {
        /*NVM861*/
        NvM_AdmBlock[0].NvErrStatus = NVM_REQ_PENDING;

        /*NVM667*//*NVM356*//*NVM549*//* NVM858*/
        for(idIndex = NVM_USER_BLOCKID_START; idIndex < NVM_TOTAL_NUM_OF_NVRAM_BLOCKS; idIndex++)
        {
            NvM_AdmBlock[idIndex].NvErrStatus = NVM_REQ_PENDING;
        }
    }
}





/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_InitSubState
*
* Description:  Init Job sub state when get a job from queue
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE) NvM_InitSubState
(
    const NvM_BlockIdType BlockId,
    const uint8 ServiceId
)
{
    uint8 useRamType = (uint8)0;

    switch(ServiceId)
    {
#if((NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)\
 ||(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2))

    case NVM_JOB_READ:
    case NVM_JOB_READ_PRAMBLOCK:
        NvM_JobSubState = NVM_SUBSTATE_READ_DATA;
        break;

    case NVM_JOB_WRITE:
    case NVM_JOB_WRITE_PRAMBLOCK:
        useRamType = NvM_GetUsedRamBlockType(BlockId);
        if(useRamType >= NVM_PROCESS_PER_RAM_BLOCK)
        {
            /* assume that block is valid and changed by user
             if write Ok, block will be valid&unchanged
             if write fail, block will keep valid&changed,so the write all may rewrite this block
             NVM303
            */
            NVM_SET_VALID_CHANGED(BlockId);
        }



#if(STD_ON == NVM_USE_SYNC_MECHANISM)
        if(NVM_PROCESS_SYN_RAM_BLOCK == useRamType)
        {
            NvM_JobSubState = NVM_SUBSTATE_WRITE_SYN;
        }
        else
#endif
        {
            NvM_JobSubState = NVM_SUBSTATE_WRITE_DATA;
#if(STD_ON == NVM_CIPHER_ENABLE)
            if(TRUE == NvM_Config[BlockId].EnCipher)
            {
                NvM_JobSubState = NVM_SUBSTATE_WRITE_ENCRYPT;
            }
            else
#endif
            {
#if(STD_ON == NVM_CRC_ENABLE)
                if(TRUE == NvM_Config[BlockId].EnCrc)
                {
                    NvM_JobSubState = NVM_SUBSTATE_WRITE_CALCRC;
                }
                else
#endif
                {
#if(STD_ON == NVM_COMPRESSION_ENABLE)
                    if(TRUE == NvM_Config[BlockId].EnCompression)
                    {
                        NvM_JobSubState = NVM_SUBSTATE_WRITE_COMPRESSION;
                    }
#endif
                }
            }
        }
        break;

    case NVM_JOB_RESTORE:
    case NVM_JOB_RESTORE_PRAMBLOCK:
        /* before restore, the block will be invalid
           if restore Ok, block will be valid&changed
           if restore fail, block will keep invalid&unchanged,to avoid user use uncorrect data
           crc will be recalulated after restore
           but no need to match CRC
           NVM227
        */
        if(NvM_GetUsedRamBlockType(BlockId) >= NVM_PROCESS_PER_RAM_BLOCK)
        {
            NVM_SET_INVALID_UNCHANGED(BlockId);
        }

        NvM_JobSubState = NVM_SUBSTATE_RESTOREDATA;
        break;


#endif


#if((STD_ON == NVM_CRC_ENABLE) && (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON))
    case NVM_JOB_SET_RAMSTA:

        useRamType = NvM_GetUsedRamBlockType(BlockId);

        if(NVM_PROCESS_PER_RAM_BLOCK == useRamType)
        {
            NvM_JobSubState = NVM_SUBSTATE_SETRAM_CRC;
        }
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
        else if(NVM_PROCESS_SYN_RAM_BLOCK == useRamType)
        {
            NvM_JobSubState = NVM_SUBSTATE_SETRAM_SYN_READIN;
        }
#endif
        else
        {
            /* should not enter this */
        }

        break;
#endif




#if(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)

#if(STD_ON == NVM_ERASE_API)
    case NVM_JOB_ERASE:
        NvM_JobSubState = NVM_SUBSTATE_ERASE;
        break;
#endif

#if(STD_ON == NVM_INVALID_NVBLOCK_API)
    case NVM_JOB_INVALID:
        NvM_JobSubState = NVM_SUBSTATE_INVALID;
        break;
#endif

    case NVM_JOB_FIRSTINITALL:
        NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL;
        NvM_InitBlocksPendingInMultiJob();
#if(STD_ON == NVM_DRV_MODE_SWITCH)
#if(STD_CONFIG_VARIANTS_LINKTIME == NVM_CONFIG_VARIANTS)
        if(TRUE == NvM_DrvModeSwitch)
#endif
        {
            MemIf_SetMode(MEMIF_MODE_FAST);
        }
#endif
        break;
#endif



    case NVM_JOB_READALL:
        NvM_JobSubState = NVM_SUBSTATE_READALL;
        NvM_InitBlocksPendingInMultiJob();
#if(STD_ON == NVM_DRV_MODE_SWITCH)
#if(STD_CONFIG_VARIANTS_LINKTIME == NVM_CONFIG_VARIANTS)
        if(TRUE == NvM_DrvModeSwitch)
#endif
        {
            MemIf_SetMode(MEMIF_MODE_FAST);
        }
#endif
        break;


    case NVM_JOB_WRITEALL:
        NvM_JobSubState = NVM_SUBSTATE_WRITEALL;
        NvM_InitBlocksPendingInMultiJob();
#if(STD_ON == NVM_DRV_MODE_SWITCH)
#if(STD_CONFIG_VARIANTS_LINKTIME == NVM_CONFIG_VARIANTS)
        if(TRUE == NvM_DrvModeSwitch)
#endif
        {
            MemIf_SetMode(MEMIF_MODE_FAST);
        }
#endif
        break;


    case NVM_JOB_VALIDATEALL:
        NvM_JobSubState = NVM_SUBSTATE_VALIDATEDALL;
        NvM_InitBlocksPendingInMultiJob();
        break;


    default:
        /* Unexpected case, report error, reset job to make other job running possible*/
        NvM_ResetJobState();
        NVM_DET_REPORT_ERROR(NVM_INTERNAL_INITSUBSTATE_APIID, NVM_E_UNEXPECTED_CASE);
        break;

    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_GetPhyBlockId
*
* Description:  get blockid passed to memif
*
* Inputs:       BlockId
*
* Outputs:      PhyBlockId
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
#if((STD_CONFIG_VARIANTS_PRECOMPILE == NVM_CONFIG_VARIANTS) && (0 == NVM_DATASET_SELECTION_BITS))
#define NvM_GetPhyBlockId(BlockId)   NvM_Config[(BlockId)].BaseNumber
#else
STATIC FUNC(NvM_BlockIdType, NVM_CODE) NvM_GetPhyBlockId
(
    const NvM_BlockIdType BlockId
)
{
    NvM_BlockIdType phyBlockId;

    phyBlockId = (NvM_Config[BlockId].BaseNumber << (uint16)NVM_DATASET_SELECTION_BITS);
    phyBlockId = phyBlockId + NvM_AdmBlock[BlockId].NvDataIndex;

    return phyBlockId;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_FillBlockId
*
* Description:  auto fill the ramblock header with blockId
*
* Inputs:       BlockId
*
* Outputs:      Offset of ramblock
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_OFF == NVM_BLOCKID_CHECK)
#define NvM_FillBlockId(BlockId)
#else
STATIC FUNC(void, NVM_CODE) NvM_FillBlockId
(
    const NvM_BlockIdType BlockId
)
{
    NvM_BlockIdType savedId = BlockId;
    uint16 len;
    if(TRUE == NvM_Config[BlockId].EnIdCheck)
    {
        len = NvM_Config[BlockId].Length;
#if(STD_ON == NVM_CIPHER_ENABLE)
        if(TRUE == NvM_Config[BlockId].EnCipher)
        {
            len = NvM_Config[BlockId].NvM_Cipher->Length;
        }
#endif
#if(STD_ON == NVM_LOW_STATIC_ID_CHECK)
        savedId = NvM_GetPhyBlockId(BlockId);
#endif
        NvM_CurrentJobInfo.RamAddr[len] = (uint8)(savedId >> (NvM_BlockIdType)NVM_DATA_8);
        NvM_CurrentJobInfo.RamAddr[len + (uint16)1] = (uint8)savedId;
    }

}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_CheckStaticId
*
* Description:  check if the read Block Id is valid
*
* Inputs:       BlockId
*
* Outputs:      boolean
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == NVM_BLOCKID_CHECK)
STATIC FUNC(boolean, NVM_CODE) NvM_CheckStaticId
(
    const NvM_BlockIdType BlockId
)
{
    boolean ret = FALSE;
    NvM_BlockIdType readOutId;
    uint16 len = NvM_Config[BlockId].Length;
#if(STD_ON == NVM_LOW_STATIC_ID_CHECK)
    NvM_BlockIdType phyBlockId;
#endif
#if(STD_ON == NVM_CIPHER_ENABLE)
    if(TRUE == NvM_Config[BlockId].EnCipher)
    {
        len = NvM_Config[BlockId].NvM_Cipher->Length;
    }
#endif
    readOutId =  NvM_CurrentJobInfo.RamAddr[len];
    readOutId =  (readOutId << (uint16)NVM_DATA_8) ;
    readOutId =  (readOutId | NvM_CurrentJobInfo.RamAddr[len + (uint16)1]);

#if(STD_ON == NVM_LOW_STATIC_ID_CHECK)
    phyBlockId = NvM_GetPhyBlockId(BlockId);
    if(readOutId == phyBlockId)
#else
    if(readOutId == BlockId)
#endif
    {
        ret = TRUE;
    }

    return ret;
}

#endif





/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ReadBlockEndNotification
*
* Description:  process when read job get MemifOk.
*
* Inputs:       BlockId
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, NVM_CODE) NvM_ReadBlockEndNotification
(
    const NvM_BlockIdType BlockId,
    const MemIf_JobResultType JobResult
)
{
    NvM_JobSubState = NVM_SUBSTATE_READ_PREEND;

    if(MEMIF_JOB_OK == JobResult)
    {
#if(STD_ON == NVM_COMPRESSION_ENABLE)
        if(TRUE == NvM_Config[BlockId].EnCompression)
        {
            NvM_JobSubState = NVM_SUBSTATE_READ_DECOMPRESSION;
        }
        else
#endif
        {
#if(STD_ON == NVM_BLOCKID_CHECK)
            if(TRUE == NvM_Config[BlockId].EnIdCheck)
            {
                if(FALSE == NvM_CheckStaticId(BlockId))
                {
                    NvM_TempNvErrStatus = NVM_REQ_WRONGID;
                }
                else
                {
                    NvM_TempNvErrStatus = NVM_REQ_OK;
                }
            }
#endif
            if(NvM_TempNvErrStatus != NVM_REQ_WRONGID)
            {
#if(STD_ON == NVM_CRC_ENABLE)
                if(TRUE == NvM_Config[BlockId].EnCrc)
                {
                    NvM_JobSubState = NVM_SUBSTATE_READ_CALCRC;
                }
                else
#endif
                {
#if(STD_ON == NVM_CIPHER_ENABLE)
                    if(TRUE == NvM_Config[BlockId].EnCipher)
                    {
                        NvM_JobSubState = NVM_SUBSTATE_READ_DECRYPT;
                    }
                    else
#endif
                    {
                        NvM_TempNvErrStatus = NVM_REQ_OK;
                    }
                }
            }
        }
    }
    else if(MEMIF_JOB_CANCELED == JobResult)
    {
        NvM_TempNvErrStatus = NVM_REQ_CANCELED;
    }
    else if(MEMIF_BLOCK_INVALID == JobResult)
    {
        NvM_TempNvErrStatus = NVM_REQ_NV_INVALIDATED;
    }
    else if(MEMIF_BLOCK_INCONSISTENT == JobResult)
    {

        NvM_TempNvErrStatus = NVM_REQ_INTEGRITY_FAILED;
    }
    else
    {
        NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
    }

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_RetryRead
*
* Description:  when read job fail, check if need to retry read
*
* Inputs:       BlockId
*
* Outputs:      boolean
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, NVM_CODE)  NvM_ReadPreEndProcess
(
    const NvM_BlockIdType BlockId

)
{

    boolean loopFlag = TRUE;

    if(NVM_REQ_CANCELED == NvM_TempNvErrStatus)
    {
        NvM_JobSubState = NVM_SUBSTATE_READ_END;
    }
    else if(NVM_REQ_OK == NvM_TempNvErrStatus)
    {
        NvM_JobSubState = NVM_SUBSTATE_READ_END;

#if(STD_ON == NVM_USE_SYNC_MECHANISM)
        if(NVM_PROCESS_SYN_RAM_BLOCK == NvM_GetUsedRamBlockType(BlockId))
        {
            NvM_JobSubState = NVM_SUBSTATE_READ_SYN;
        }
#endif

    }
    else if(NVM_REQ_NV_INVALIDATED == NvM_TempNvErrStatus)
    {
#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
        if((NVM_BLOCK_REDUNDANT == NvM_Config[BlockId].BlockType)
                && ((uint8)0 == NvM_AdmBlock[BlockId].NvDataIndex))
        {
            NvM_AdmBlock[BlockId].NvDataIndex = (uint8)1;
            NvM_JobSubState = NVM_SUBSTATE_READ_DATA;/*try again*/
            NvM_savedNv0ResultType = NvM_TempNvErrStatus;
            loopFlag = FALSE;
#if(STD_ON == NVM_AUTO_READ_RETRY)
            NvM_OpRetryNum = (uint8)0;
#endif

        }
        else
#endif
        {
            if(NVM_BLOCK_DATASET != NvM_Config[BlockId].BlockType)
            {
                NvM_InitImplicitRestore(BlockId);
            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_READ_END;
            }
        }
    }
    else/* NotOK,WrongId, CrcWrong*/
    {
#if(STD_ON == NVM_AUTO_READ_RETRY)

        NvM_OpRetryNum++;
        if(NvM_OpRetryNum <= NvM_Config[BlockId].MaxReReadNum)
        {
            NvM_JobSubState = NVM_SUBSTATE_READ_DATA;/*try again*/
            loopFlag = FALSE;
        }
        else
#endif
        {
            /* NVM526, redundant block, nv0 retry all first, then nv1 */
#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
            if((NVM_BLOCK_REDUNDANT == NvM_Config[BlockId].BlockType)
                    && ((uint8)0 == NvM_AdmBlock[BlockId].NvDataIndex))
            {
                NvM_AdmBlock[BlockId].NvDataIndex = (uint8)1;
                NvM_savedNv0ResultType = NvM_TempNvErrStatus;
                NvM_JobSubState = NVM_SUBSTATE_READ_DATA;/*try again*/
                loopFlag = FALSE;
#if(STD_ON == NVM_AUTO_READ_RETRY)
                NvM_OpRetryNum = (uint8)0;
#endif
            }
            else
#endif
            {
                if(NVM_BLOCK_DATASET != NvM_Config[BlockId].BlockType)
                {
                    NvM_InitImplicitRestore(BlockId);
                }
                else
                {
                    NvM_JobSubState = NVM_SUBSTATE_READ_END;
                }
                
            }
        }
    }


    /*loopFlag = true , means dont need to retry
      here will caculate the final job result , based On redundant 2 Nv Block result
      final result will saved in NvM_TempNvErrStatus
    */
#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
    if((TRUE == loopFlag) && (NVM_BLOCK_REDUNDANT == NvM_Config[BlockId].BlockType))
    {
        if((NVM_REQ_CANCELED != NvM_TempNvErrStatus)
                && (NVM_REQ_OK != NvM_TempNvErrStatus))
        {
            if(NvM_savedNv0ResultType != NvM_TempNvErrStatus)
            {
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
            }
        }

        /* keep loss bit when cancel*/
        if(NVM_REQ_CANCELED != NvM_TempNvErrStatus)
        {
            if(NVM_REQ_NV_INVALIDATED == NvM_TempNvErrStatus)
            {
            	NVM_LOSSR_BIT(BlockId) = FALSE;
            }
            else if((NVM_REQ_OK == NvM_TempNvErrStatus) && ((uint8)0 == NvM_AdmBlock[BlockId].NvDataIndex))
            {
                NVM_LOSSR_BIT(BlockId) = FALSE;
            }
            else
            {
                NVM_LOSSR_BIT(BlockId) = TRUE;
            }
        }
    }
#endif

    return loopFlag;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_CopyRomToRam
*
* Description:  copy data from rom block to ran block
*
* Inputs:       BlockId
*
* Outputs:      Std_ReturnType
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, NVM_CODE)  NvM_CopyRomToRam
(
    const NvM_BlockIdType BlockId
)
{
    uint16 length  = NvM_Config[BlockId].Length;
    Std_ReturnType ret = E_OK;
    uint16 index  = (uint16)0;

#if(NVM_READ_ROM_BYTES > 0)
    /* first time read */
    if((uint16)0 == NvM_OpDataIndex)
    {
        NvM_OpLeftLength = NvM_Config[BlockId].Length;
#if(STD_ON == NVM_CIPHER_ENABLE)
        if(TRUE == NvM_Config[BlockId].EnCipher)
        {
            NvM_OpLeftLength = NvM_Config[BlockId].NvM_Cipher->Length;
        }
#endif
    }

    if(NvM_OpLeftLength > (uint16)NVM_READ_ROM_BYTES)
    {
        length = (uint16)NVM_READ_ROM_BYTES;
    }
    else
    {
        length = NvM_OpLeftLength;
    }

    index = NvM_OpDataIndex;
#endif


#if(STD_OFF == NVM_SPECIAL_READ_ROM)
    Bsw_MemCpy(&NvM_CurrentJobInfo.RamAddr[index],
               &NvM_Config[BlockId].RomAddr[index],
               (uint32)length);
#else
    ret = NvM_ReadRomCallout(&NvM_CurrentJobInfo.RamAddr[index],
                             &NvM_Config[BlockId].RomAddr[index],
                             length);
#endif

#if(NVM_READ_ROM_BYTES > 0)
    if(E_OK == ret)
    {
        NvM_OpLeftLength = NvM_OpLeftLength - length;
        if((uint16)0 == NvM_OpLeftLength)
        {
            ret = E_OK;
            NvM_OpDataIndex = (uint16)0;
        }
        else
        {
            NvM_OpDataIndex = NvM_OpDataIndex + length;
            ret = NVM_USER_JOB_PENDING;
        }
    }
    else
    {
        NvM_OpDataIndex = (uint16)0;
        NvM_OpLeftLength = (uint16)0;
    }
#endif
    return ret;


}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_CallReadRamCbkProcess
*
* Description:  Call NvM_ReadRamBlockFromNvmFunPtr
*
* Inputs:       BlockId
*
* Outputs:      boolean, loop end or continue
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
STATIC FUNC(boolean, NVM_CODE)  NvM_CallReadRamCbkProcess
(
    NvM_BlockIdType BlockId,
    NvM_JobSubState_Type substate,
    NvM_JobSubState_Type failsubstate
)
{
    Std_ReturnType Result;
    boolean flag = FALSE;

#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
    uint8 LogicCoreId;

    if(CurrentCoreId != NvM_Config[BlockId].PhyCoreId)
    {
        LogicCoreId = NvM_Config[BlockId].LogicCoreId;
        Result = NvM_AgentCmdAsync(LogicCoreId, NVM_NO_SERVICE, NVM_AGENT_BACK_JOB_MIRROR_READ_CALLBACK, BlockId, NvM_MirrorBuffer, (NvM_RequestResultType)0, (NvM_InitBlockRequestType)0);
    }
    else
#endif
    {
        Result = NvM_ReadRamBlockFromNvmFunPtr[BlockId](NvM_MirrorBuffer);
    }

    if(NVM_USER_JOB_PENDING != Result)
    {
        if(E_OK == Result)
        {
            NvM_JobSubState = substate;
            flag = TRUE;
        }
        else
        {

            NvM_MirrorOpNum++;
            if(NvM_MirrorOpNum > NVM_REPEAT_MIRROR_OPERATIONS)
            {
                NvM_JobSubState = failsubstate;
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                flag = TRUE;
            }
        }
    }

    return flag;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_CallWriteRamCbkProcess
*
* Description:  Call NvM_WriteRamBlockToNvmFunPtr
*
* Inputs:       BlockId
*
* Outputs:      Std_ReturnType
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/

STATIC FUNC(boolean, NVM_CODE)  NvM_CallWriteRamCbkProcess
(
    NvM_BlockIdType BlockId,
    NvM_JobSubState_Type substate,
    NvM_JobSubState_Type failsubstate
)
{
    Std_ReturnType Result;
    boolean flag = FALSE;

#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
    uint8 LogicCoreId;

    if(CurrentCoreId != NvM_Config[BlockId].PhyCoreId)
    {
        LogicCoreId = NvM_Config[BlockId].LogicCoreId;
        Result = NvM_AgentCmdAsync(LogicCoreId, NVM_NO_SERVICE, NVM_AGENT_BACK_JOB_MIRROR_WRITE_CALLBACK, BlockId, NvM_MirrorBuffer, (NvM_RequestResultType)0, (NvM_InitBlockRequestType)0);
    }
    else
#endif
    {
        Result = NvM_WriteRamBlockToNvmFunPtr[BlockId](NvM_MirrorBuffer);
    }


    if(NVM_USER_JOB_PENDING != Result)
    {
        if(E_OK == Result)
        {
            NvM_JobSubState = substate;
            flag = TRUE;
        }
        else
        {

            NvM_MirrorOpNum++;
            if(NvM_MirrorOpNum > NVM_REPEAT_MIRROR_OPERATIONS)
            {
                NvM_JobSubState = failsubstate;
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;/*NVM579 837 report not ok when mirror write fail*/
                flag = TRUE;
            }
        }
    }
    return flag;


}



#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ReadJobProcess
*
* Description:  process a read request.
*
* Inputs:       BlockId
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
FUNC(void, NVM_CODE)  NvM_ReadJobProcess
(
    const NvM_BlockIdType BlockId
)
{
    NvM_BlockIdType phyBlockId;
    Std_ReturnType Result;
    uint16 length;
    MemIf_JobResultType JobResult;
    boolean loopFlag;
    NvM_InitBlockRequestType InitReq;

#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
    uint8 LogicCoreId;
#endif
    do
    {
        loopFlag = FALSE;
        switch(NvM_JobSubState)
        {


        case NVM_SUBSTATE_READ_DATA:

            /* assume that block is invalid and unchanged,
             if read Ok, block will be valid&unchanged,
             if read fail, this block can not be used any more
             block will keep invalid&unchanged,so the read all may reread this block
             NVM198 invalidate a permanent RAM block immediately when the block is successfully enqueued
             NVM658 read failed and no default value , keep invalid

             set invalid&changed here only when using perRam
             if syn ram is used, this will be done just before call readRamCbk

            */
            if(NVM_PROCESS_PER_RAM_BLOCK == NvM_GetUsedRamBlockType(BlockId))
            {
                NVM_SET_INVALID_UNCHANGED(BlockId);
            }

            phyBlockId = NvM_GetPhyBlockId(BlockId);
#if(STD_ON == NVM_COMPRESSION_ENABLE)
            if(TRUE == NvM_Config[BlockId].EnCompression)
            {
                length = NvM_Config[BlockId].NvM_Compression->CompressionLength;
            }
            else
            {
                length = NvM_GetBlockLength(BlockId);
            }
#else
            length = NvM_GetBlockLength(BlockId);
#endif

            Result = MemIf_Read(NvM_Config[BlockId].DeviceId,
                                phyBlockId,
                                (uint16)0,
                                NvM_CurrentJobInfo.RamAddr,
                                length);

            if(E_NOT_OK == Result)
            {
                NvM_JobSubState = NVM_SUBSTATE_READ_PREEND;
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_READDATA_WAIT;
            }

            break;

        case NVM_SUBSTATE_READDATA_WAIT:
#if(STD_ON == NVM_POLLING_MODE)
            JobResult = MemIf_GetJobResult(NvM_Config[BlockId].DeviceId);
            if(MEMIF_JOB_PENDING != JobResult)
            {
                loopFlag = TRUE;
                NvM_JobSubState = NVM_SUBSTATE_READDATA_WAIT_IND;
            }
#endif
            break;

        case NVM_SUBSTATE_READDATA_WAIT_IND:
            JobResult = MemIf_GetJobResult(NvM_Config[BlockId].DeviceId);
            loopFlag = TRUE;
            NvM_ReadBlockEndNotification(BlockId, JobResult);

            break;

#if(STD_ON == NVM_COMPRESSION_ENABLE)
        case NVM_SUBSTATE_READ_DECOMPRESSION:
            NvM_JobSubState = NVM_SUBSTATE_READ_PREEND;
            Result = NvM_Decompression_Process(BlockId);
            if(E_OK != Result)
            {
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
            }
            else
            {
#if(STD_ON == NVM_BLOCKID_CHECK)
                if(TRUE == NvM_Config[BlockId].EnIdCheck)
                {
                    if(FALSE == NvM_CheckStaticId(BlockId))
                    {
                        NvM_TempNvErrStatus = NVM_REQ_WRONGID;
                    }
                    else
                    {
                        NvM_TempNvErrStatus = NVM_REQ_OK;
                    }
                }
#endif
#if(STD_ON == NVM_CRC_ENABLE)
                if(NVM_REQ_WRONGID != NvM_TempNvErrStatus)
                {
                    if(TRUE == NvM_Config[BlockId].EnCrc)
                    {
                        NvM_JobSubState = NVM_SUBSTATE_READ_CALCRC;
                    }
                    else
#endif
                    {
#if(STD_ON == NVM_CIPHER_ENABLE)
                        if(TRUE == NvM_Config[BlockId].EnCipher)
                        {
                            NvM_JobSubState = NVM_SUBSTATE_READ_DECRYPT;
                        }
#endif
                    }
                }
            }
            loopFlag = TRUE;
            break;
#endif

#if(STD_ON == NVM_CRC_ENABLE)/*NVM201*/
        case NVM_SUBSTATE_READ_CALCRC:
            Result = NvM_CRC_Process(BlockId);
            if(E_OK == Result)
            {
                loopFlag = TRUE;
                NvM_JobSubState = NVM_SUBSTATE_READ_PREEND;
                if(NvM_NvCrcResult == NvM_ReadRamCrcResult(BlockId))
                {
                    NvM_TempNvErrStatus = NVM_REQ_OK;
#if(STD_ON == NVM_CIPHER_ENABLE)
                    if(TRUE == NvM_Config[BlockId].EnCipher)
                    {
                        NvM_JobSubState = NVM_SUBSTATE_READ_DECRYPT;
                    }
#endif
                }
                else
                {
                    NvM_TempNvErrStatus = NVM_REQ_INTEGRITY_FAILED;
                }
            }
            break;
#endif

#if(STD_ON == NVM_CIPHER_ENABLE)
        case NVM_SUBSTATE_READ_DECRYPT:
            Result = NvM_Decrypt_Process(BlockId);
#if(STD_ON == NVM_POLLING_MODE)
            if(E_OK != Result)
            {
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
            }
            else
            {
                NvM_TempNvErrStatus = NVM_REQ_OK;
            }
            loopFlag = TRUE;
            NvM_JobSubState = NVM_SUBSTATE_READ_PREEND;
#else
            if(E_OK != Result)
            {
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                NvM_JobSubState = NVM_SUBSTATE_READ_PREEND;
            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_READ_DECRYPT_WAIT;
            }
#endif
        break;

        case NVM_SUBSTATE_READ_DECRYPT_WAIT:
            break;
#endif

        case NVM_SUBSTATE_READ_PREEND:
            loopFlag = NvM_ReadPreEndProcess(BlockId);
            break;


        case NVM_SUBSTATE_READ_RESTORE_USER:
            /*NVM369
              In callback, user must fill crc and blockid, as nvm dont not know
              the ram block address. NVM266
            */

            if(NVM_JOB_READALL == NvM_CurrentJobInfo.ServiceId)
            {
                InitReq = NVM_INIT_READ_ALL_BLOCK;
            }
            else
            {
                InitReq = NVM_INIT_READ_BLOCK;                
            }
            
#if (STD_ON == NVM_MULTI_CORE_SUPPORT)   
            if(CurrentCoreId != NvM_Config[BlockId].PhyCoreId)
            {
                LogicCoreId = NvM_Config[BlockId].LogicCoreId;
                Result = NvM_AgentCmdAsync(LogicCoreId, NVM_NO_SERVICE, NVM_AGENT_BACK_JOB_INIT_CALLBACK, BlockId, NULL_PTR, (NvM_RequestResultType)0, InitReq);
            }
            else
#endif
            {
                Result = NvM_InitBlockCallBackFunPtr[BlockId](InitReq);
            }


            
            if(NVM_USER_JOB_PENDING != Result)
            {
                loopFlag = TRUE;
                NvM_JobSubState = NVM_SUBSTATE_READ_END;
                if(E_OK == Result)
                {
                    NvM_TempNvErrStatus |= NVM_READ_IMPLICIT_REC_MASK;
                }
                /* else restore fail, keep NvM_TempNvErrStatus unchange*/
            }
            /* else do nothing , wait for next main cycle */
            break;


        case NVM_SUBSTATE_READ_RESTORE:
            Result = NvM_CopyRomToRam(BlockId);
            if(NVM_USER_JOB_PENDING != Result)
            {
                loopFlag = TRUE;
                if(E_OK == Result)
                {
                    NvM_TempNvErrStatus |= NVM_READ_IMPLICIT_REC_MASK;
#if(STD_ON == NVM_CRC_ENABLE)
                    if(TRUE == NvM_Config[BlockId].EnCrc)
                    {

                        NvM_JobSubState = NVM_SUBSTATE_READ_RESTORECRC;
                    }
                    else
#endif
                    {
                        /* restore ok, keep errcode unchange? */
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
                        if(NVM_PROCESS_SYN_RAM_BLOCK == NvM_GetUsedRamBlockType(BlockId))
                        {
                            NvM_JobSubState = NVM_SUBSTATE_READ_SYN;
                        }
                        else
#endif
                        {
                            NvM_JobSubState = NVM_SUBSTATE_READ_END;
                        }
                    }
                }
                else
                {
                    /* recorvery fail, dont try again
                    keep errcode unchange*/
                    NvM_JobSubState = NVM_SUBSTATE_READ_END;
                }
            }
            break;

#if(STD_ON == NVM_CRC_ENABLE)
        case NVM_SUBSTATE_READ_RESTORECRC:
            Result = NvM_CRC_Process(BlockId);
            if(E_OK == Result)
            {
                NvM_WriteCrcResultToRam(BlockId);
                /* restore ok, keep errcode unchange? */
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
                if(NVM_PROCESS_SYN_RAM_BLOCK == NvM_GetUsedRamBlockType(BlockId))
                {
                    NvM_JobSubState = NVM_SUBSTATE_READ_SYN;
                }
                else
#endif
                {
                    NvM_JobSubState = NVM_SUBSTATE_READ_END;
                }
            }
            break;
#endif


#if(STD_ON == NVM_USE_SYNC_MECHANISM)
        case NVM_SUBSTATE_READ_SYN:

            /* syn mirror is used, set invalid just before the data copy*/
            if(NVM_PROCESS_SYN_RAM_BLOCK == NvM_GetUsedRamBlockType(BlockId))
            {
                NVM_SET_INVALID_UNCHANGED(BlockId);
            }

            loopFlag = NvM_CallReadRamCbkProcess(BlockId, NVM_SUBSTATE_READ_END, NVM_SUBSTATE_READ_END);

            break;
#endif


        case NVM_SUBSTATE_READ_END:
            NvM_ReadEnd(BlockId);
            break;



        default:
            /* Unexpected case, report error, reset job to make other job running possible*/
            NvM_ResetJobState();
            NVM_DET_REPORT_ERROR(NVM_INTERNAL_READPROC_APIID, NVM_E_UNEXPECTED_CASE);
            break;

        }

    }
    while(TRUE == loopFlag);

}
/*PRQA S 4700 --*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_RetryWrite
*
* Description:  when write job fail, check if need to retry write
*
* Inputs:       BlockId
*
* Outputs:      boolean
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, NVM_CODE)  NvM_RetryWrite
(
    const NvM_BlockIdType BlockId
)
{
    boolean retryFlag = FALSE;

#if(STD_ON == NVM_AUTO_WRITE_RETRY)
    NvM_OpRetryNum++;
    if(NvM_OpRetryNum <= NvM_Config[BlockId].MaxReWriteNum)
    {
        retryFlag = TRUE;/*try again*/
        NvM_JobSubState = NVM_SUBSTATE_WRITE_DATA;
    }
    else
#endif

    {
        NvM_JobSubState = NVM_SUBSTATE_WRITE_END;
    }

    return retryFlag;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ReadBackEndNotification
*
* Description:  process when Write verify, and data is read back
*
* Inputs:       BlockId
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == NVM_WRITE_VER)
STATIC FUNC(void, NVM_CODE) NvM_ReadBackEndNotification
(
    const NvM_BlockIdType BlockId
)
{
    uint16 verLength;
    uint16 bufIndex;
    boolean verFlag = TRUE;

    if(NvM_OpLeftLength > NvM_Config[BlockId].MaxVerNum)
    {
        verLength = NvM_Config[BlockId].MaxVerNum;
    }
    else
    {
        verLength = NvM_OpLeftLength;
    }

    /*compare*/
    for(bufIndex = (uint16)0; bufIndex < verLength; bufIndex++)
    {
        if(NvM_ReadBackBuf[bufIndex] != NvM_CurrentJobInfo.RamAddr[NvM_OpDataIndex + bufIndex])
        {
            verFlag = FALSE;
            break;
        }
    }

    if(TRUE == verFlag)
    {
        if(NvM_OpLeftLength > NvM_Config[BlockId].MaxVerNum)
        {
            NvM_OpLeftLength = NvM_OpLeftLength - NvM_Config[BlockId].MaxVerNum;
            NvM_OpDataIndex = NvM_OpDataIndex + NvM_Config[BlockId].MaxVerNum;
            NvM_JobSubState = NVM_SUBSTATE_WRITE_VER;
        }
        else
        {
            NvM_OpDataIndex = (uint16)0;
            NvM_OpLeftLength = (uint16)0;
            NvM_JobSubState = NVM_SUBSTATE_WRITE_END;
            NvM_TempNvErrStatus = NVM_REQ_OK;
        }

    }
    else
    {
        NvM_OpDataIndex = (uint16)0;
        NvM_OpLeftLength = (uint16)0;
        if(FALSE == NvM_RetryWrite(BlockId))
        {
            NvM_TempNvErrStatus = NVM_REQ_VERIFY_FAILED;
        }
    }
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_WriteJobProcess
*
* Description:  process a Write request.
*
* Inputs:       BlockId
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
/*PRQA S 4700 ++*/
/*
There is not limit on the number of lines of function code and the number of local variable assignments.
*/
FUNC(void, NVM_CODE)  NvM_WriteJobProcess
(
    const NvM_BlockIdType BlockId
)
{
    NvM_BlockIdType phyBlockId;
    Std_ReturnType Result;
    MemIf_JobResultType JobResult;
    boolean loopFlag;


#if(STD_ON == NVM_WRITE_VER)
    uint16 verLength;
#endif

    do
    {
        loopFlag = FALSE;
        switch(NvM_JobSubState)
        {
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
        case NVM_SUBSTATE_WRITE_SYN:
#if(STD_ON == NVM_CIPHER_ENABLE)
            if(TRUE == NvM_Config[BlockId].EnCipher)
            {
                loopFlag = NvM_CallWriteRamCbkProcess(BlockId, NVM_SUBSTATE_WRITE_ENCRYPT, NVM_SUBSTATE_WRITE_END);
            }
            else
#endif
            {
#if(STD_ON == NVM_CRC_ENABLE)
                if(TRUE == NvM_Config[BlockId].EnCrc)
                {
                    loopFlag = NvM_CallWriteRamCbkProcess(BlockId, NVM_SUBSTATE_WRITE_CALCRC, NVM_SUBSTATE_WRITE_END);
                }
                else
#endif
                {
#if(STD_ON == NVM_COMPRESSION_ENABLE)
                    if(TRUE == NvM_Config[BlockId].EnCompression)
                    {
                        loopFlag = NvM_CallWriteRamCbkProcess(BlockId, NVM_SUBSTATE_WRITE_COMPRESSION, NVM_SUBSTATE_WRITE_END);
                    }
                    else
#endif
                    {
                        loopFlag = NvM_CallWriteRamCbkProcess(BlockId, NVM_SUBSTATE_WRITE_DATA, NVM_SUBSTATE_WRITE_END);
                    }
                }
            }
            break;
#endif

#if(STD_ON == NVM_CIPHER_ENABLE)
        case NVM_SUBSTATE_WRITE_ENCRYPT:
            Result = NvM_Encrypt_Process(BlockId);
#if(STD_ON == NVM_POLLING_MODE)
            if(E_OK != Result)
            {
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                NvM_JobSubState = NVM_SUBSTATE_WRITE_END;
            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_WRITE_DATA;
#if(STD_ON == NVM_CRC_ENABLE)
                if(TRUE == NvM_Config[BlockId].EnCrc)
                {
                    NvM_JobSubState = NVM_SUBSTATE_WRITE_CALCRC;
                }
                else
#endif
                {
#if(STD_ON == NVM_COMPRESSION_ENABLE)
                    if(TRUE == NvM_Config[BlockId].EnCompression)
                    {
                        NvM_JobSubState = NVM_SUBSTATE_WRITE_COMPRESSION;
                    }
#endif
                }
            }
            loopFlag = TRUE;
#else
            if(E_OK != Result)
            {
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                NvM_JobSubState = NVM_SUBSTATE_WRITE_END;
            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_WRITE_ENCRYPT_WAIT;
            }
#endif
            break;

#if(STD_OFF == NVM_POLLING_MODE)
        case NVM_SUBSTATE_WRITE_ENCRYPT_WAIT:
            break;

        case NVM_SUBSTATE_WRITE_ENCRYPT_END:
            NvM_JobSubState = NVM_SUBSTATE_WRITE_DATA;
#if(STD_ON == NVM_CRC_ENABLE)
            if(TRUE == NvM_Config[BlockId].EnCrc)
            {
                NvM_JobSubState = NVM_SUBSTATE_WRITE_CALCRC;
            }
            else
#endif
            {
#if(STD_ON == NVM_COMPRESSION_ENABLE)
                if(TRUE == NvM_Config[BlockId].EnCompression)
                {
                    NvM_JobSubState = NVM_SUBSTATE_WRITE_COMPRESSION;
                }
#endif
            }
            loopFlag = TRUE;
            break;
#endif
#endif


#if(STD_ON == NVM_CRC_ENABLE)/*NVM212*/
        case NVM_SUBSTATE_WRITE_CALCRC:
            Result = NvM_CRC_Process(BlockId);
            if(E_OK == Result)
            {
#if(STD_ON == NVM_CRC_COMP_ENABLE)
                if((FALSE == NvM_CompareCrcIsDifferent(BlockId))&&(TRUE == NvM_Config[BlockId].UseCRCCompMechanism))//Wky_CRCComp0123
                {
                    NvM_TempNvErrStatus = NVM_REQ_OK;
                    if(NvM_GetUsedRamBlockType(BlockId) >= NVM_PROCESS_PER_RAM_BLOCK)
                    {
                        NVM_SET_VALID_UNCHANGED(BlockId);
                    }
                    NvM_SingleJobStop(BlockId, NvM_TempNvErrStatus);
                }
                else
#endif
                {
                    NvM_WriteCrcResultToRam(BlockId);
                    NvM_JobSubState = NVM_SUBSTATE_WRITE_DATA;
#if(STD_ON == NVM_COMPRESSION_ENABLE)
                    if(TRUE == NvM_Config[BlockId].EnCompression)
                    {
                        NvM_JobSubState = NVM_SUBSTATE_WRITE_COMPRESSION;
                    }

#endif
                }

            }
            break;
#endif

#if(STD_ON == NVM_COMPRESSION_ENABLE)
    case NVM_SUBSTATE_WRITE_COMPRESSION:
            NvM_FillBlockId(BlockId);
            Result = NvM_Compression_Process(NvM_CurrentJobInfo.BlockId);
            if(E_OK != Result)
            {
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                NvM_JobSubState = NVM_SUBSTATE_WRITE_END;
            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_WRITE_DATA;
            }
            loopFlag = TRUE;
    break;
#endif


        case NVM_SUBSTATE_WRITE_DATA:
            phyBlockId = NvM_GetPhyBlockId(BlockId);
#if(STD_ON == NVM_COMPRESSION_ENABLE)
            if(FALSE == NvM_Config[BlockId].EnCompression)
            {
                NvM_FillBlockId(BlockId);
            }
#else
            NvM_FillBlockId(BlockId);
#endif
            Result = MemIf_Write(NvM_Config[BlockId].DeviceId,
                                 phyBlockId,
                                 NvM_CurrentJobInfo.RamAddr);

            if(E_NOT_OK == Result)
            {
                if(FALSE == NvM_RetryWrite(BlockId))
                {
                    NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                    loopFlag = TRUE;
                }
            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_WRITE_WAIT;
            }

            break;

        case NVM_SUBSTATE_WRITE_WAIT:
#if(STD_ON == NVM_POLLING_MODE)
            JobResult = MemIf_GetJobResult(NvM_Config[BlockId].DeviceId);
            if(MEMIF_JOB_PENDING != JobResult)
            {
                loopFlag = TRUE;
                NvM_JobSubState = NVM_SUBSTATE_WRITE_WAIT_IND;
            }
#endif
            break;

        case NVM_SUBSTATE_WRITE_WAIT_IND:
            JobResult = MemIf_GetJobResult(NvM_Config[BlockId].DeviceId);
            loopFlag = TRUE;

            if(MEMIF_JOB_OK == JobResult)
            {
#if(STD_ON == NVM_WRITE_VER)
                if(TRUE == NvM_Config[BlockId].EnVer)
                {
                    NvM_JobSubState = NVM_SUBSTATE_WRITE_VER;
                }
                else
#endif
                {
                    NvM_JobSubState = NVM_SUBSTATE_WRITE_END;
                    NvM_TempNvErrStatus = NVM_REQ_OK;
                }

            }
            else if(MEMIF_JOB_CANCELED == JobResult)
            {
                NvM_TempNvErrStatus = NVM_REQ_CANCELED;
                NvM_JobSubState = NVM_SUBSTATE_WRITE_END;
            }
            else
            {
                if(FALSE == NvM_RetryWrite(BlockId))
                {
                    /* only failed is possible when read*/
                    NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                }
            }
            break;

#if(STD_ON == NVM_WRITE_VER)
        case NVM_SUBSTATE_WRITE_VER:
            /* if reduant block, the index can not be changed*/
            phyBlockId = NvM_GetPhyBlockId(BlockId);

            if((uint16)0 == NvM_OpLeftLength)
            {
                NvM_OpLeftLength = NvM_GetBlockLength(BlockId);
            }
            if(NvM_OpLeftLength > NvM_Config[BlockId].MaxVerNum)
            {
                verLength = NvM_Config[BlockId].MaxVerNum;
            }
            else
            {
                verLength = NvM_OpLeftLength;
            }
            Result = MemIf_Read(NvM_Config[BlockId].DeviceId,
                                phyBlockId,
                                NvM_OpDataIndex,
                                NvM_ReadBackBuf,
                                verLength);

            if(E_NOT_OK == Result)
            {
                if(FALSE == NvM_RetryWrite(BlockId))
                {
                    NvM_TempNvErrStatus = NVM_REQ_VERIFY_FAILED;
                }
            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_WRITE_VER_WAIT;
            }

            break;

        case NVM_SUBSTATE_WRITE_VER_WAIT:
#if(STD_ON == NVM_POLLING_MODE)
            JobResult = MemIf_GetJobResult(NvM_Config[BlockId].DeviceId);
            if(MEMIF_JOB_PENDING != JobResult)
            {
                loopFlag = TRUE;
                NvM_JobSubState = NVM_SUBSTATE_WRITE_VER_WAIT_IND;
            }
#endif
            break;

        case NVM_SUBSTATE_WRITE_VER_WAIT_IND:
            JobResult = MemIf_GetJobResult(NvM_Config[BlockId].DeviceId);
            loopFlag = TRUE;

            if(MEMIF_JOB_OK == JobResult)
            {
                NvM_ReadBackEndNotification(BlockId);
            }
            else if(MEMIF_JOB_CANCELED == JobResult)
            {
                NvM_TempNvErrStatus = NVM_REQ_CANCELED;
                NvM_JobSubState = NVM_SUBSTATE_WRITE_END;
            }
            else
            {
                /*all other are NVM_REQ_NOT_OK*/
                if(FALSE == NvM_RetryWrite(BlockId))
                {
                    NvM_TempNvErrStatus = NVM_REQ_VERIFY_FAILED;
                }
            }
            break;
#endif/*#if(STD_ON == NVM_WRITE_VER)*/


        case NVM_SUBSTATE_WRITE_END:
#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
            if((NVM_BLOCK_REDUNDANT == NvM_Config[BlockId].BlockType)
                    && ((uint8)0 == NvM_AdmBlock[BlockId].NvDataIndex)
                    && (NVM_REQ_CANCELED != NvM_TempNvErrStatus))
            {
                NvM_AdmBlock[BlockId].NvDataIndex = (uint8)1;
                NvM_savedNv0ResultType = NvM_TempNvErrStatus;
                NvM_TempNvErrStatus = NVM_REQ_OK;
                NvM_JobSubState = NVM_SUBSTATE_WRITE_DATA;
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
                if(TRUE == NvM_Config[BlockId].EnUseSynM)
                {
                    NvM_JobSubState = NVM_SUBSTATE_WRITE_SYN;
                }
#endif
#if(STD_ON == NVM_AUTO_WRITE_RETRY)
                NvM_OpRetryNum = (uint8)0;
#endif
                loopFlag = TRUE;
            }
            else
#endif
            {
#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
                if((NVM_BLOCK_REDUNDANT == NvM_Config[BlockId].BlockType)
                        && (NVM_REQ_CANCELED != NvM_TempNvErrStatus))
                {
                    if((NVM_REQ_OK != NvM_TempNvErrStatus)
                            && (NVM_REQ_OK != NvM_savedNv0ResultType))
                    {

                        if((NVM_REQ_VERIFY_FAILED == NvM_TempNvErrStatus)
                                && (NVM_REQ_VERIFY_FAILED == NvM_savedNv0ResultType))
                        {
                            NvM_TempNvErrStatus = NVM_REQ_VERIFY_FAILED;
                        }
                        else
                        {
                            NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                        }
                    }
                    else
                    {
                        NvM_TempNvErrStatus = NVM_REQ_OK;
                    }
                }

#endif


                NvM_DemCheckReqFailEvent(NvM_TempNvErrStatus);
                NvM_DemCheckHardwareError(NvM_TempNvErrStatus);
                NvM_DemCheckVerFailEvent(NvM_TempNvErrStatus);

                if(NVM_REQ_OK == NvM_TempNvErrStatus)
                {
                    if(NvM_GetUsedRamBlockType(BlockId) >= NVM_PROCESS_PER_RAM_BLOCK)
                    {
                        NVM_SET_VALID_UNCHANGED(BlockId);
                    }
#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
                    if(TRUE == NvM_Config[BlockId].EnWriteOnce)
                    {
                        NVM_PROTECTED_BIT(BlockId) = TRUE;/*NVM328*/
                    }
#endif
                }
                else
                {
                    if(NvM_GetUsedRamBlockType(BlockId) >= NVM_PROCESS_PER_RAM_BLOCK)
                    {
                        NVM_SET_INVALID_UNCHANGED(BlockId);
                    }
                }
                NvM_SingleJobStop(BlockId, NvM_TempNvErrStatus);
            }
            break;


        default:
            /* Unexpected case, report error, reset job to make other job running possible*/
            NvM_ResetJobState();
            NVM_DET_REPORT_ERROR(NVM_INTERNAL_WRITEPROC_APIID, NVM_E_UNEXPECTED_CASE);
            break;

        }
    }
    while(TRUE == loopFlag);
}


#if((NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) || (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_Restore_DataReadEnd
*
* Description:  process when  restore data is finish.
*
* Inputs:       BlockId
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, NVM_CODE) NvM_Restore_DataReadEnd
(
    const NvM_BlockIdType BlockId
)
{
#if(STD_ON == NVM_CRC_ENABLE)/*NVM229*/
    if(TRUE == NvM_Config[BlockId].EnCrc)
    {
        NvM_JobSubState = NVM_SUBSTATE_RESTORECRC;
    }
    else
#endif
    {
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
        if(NVM_PROCESS_SYN_RAM_BLOCK == NvM_GetUsedRamBlockType(BlockId))
        {
            NvM_JobSubState = NVM_SUBSTATE_RESTOREDATA_SYN;
        }
        else
#endif
        {
            NvM_JobSubState = NVM_SUBSTATE_RESTOREDATA_END;
            NvM_TempNvErrStatus = NVM_REQ_RESTORED_DEFAULTS;

        }
    }

}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_RestoreProcess
*
* Description:  restore job  process.
*
* Inputs:       BlockId
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE)  NvM_RestoreProcess
(
    const NvM_BlockIdType BlockId
)
{
    Std_ReturnType Result;
    boolean loopFlag = FALSE;
#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)
    MemIf_JobResultType JobResult;
    NvM_BlockIdType phyBlockId;
#endif
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
    uint8 LogicCoreId;
#endif

    if(NvM_JobSubState == NVM_SUBSTATE_RESTOREDATA)
    {
        /* user restore  call back has highest priority */
        if(NvM_InitBlockCallBackFunPtr[BlockId] != NVM_NULL)
        {
            NvM_JobSubState = NVM_SUBSTATE_RESTORE_USER;
        }
        else
        {
#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)
            if((NVM_BLOCK_DATASET == NvM_Config[BlockId].BlockType)
                    && (NvM_Config[BlockId].RomBlockNum > (uint8)0)
                    && (NvM_AdmBlock[BlockId].NvDataIndex >= NvM_Config[BlockId].NvBlockNum))
            {
                /* dont consider dataindex here ,as dataindex is ensured in NvM_RestoreBlockDefaults*/
                NvM_JobSubState = NVM_SUBSTATE_RESTORE_ROMBLOCK;
            }
            else
#endif
            {
                NvM_JobSubState = NVM_SUBSTATE_RESTORE_ROMADDR;
            }

        }
    }

    do
    {
        loopFlag = FALSE;
        switch(NvM_JobSubState)
        {

        case NVM_SUBSTATE_RESTORE_USER:
            /*NVM369 NvM_InitBlockCallBackFunPtr will always return E_OK
              In callback, user must fill crc and blockid, as nvm dont not know
              the ram block address. NVM266
            */

#if (STD_ON == NVM_MULTI_CORE_SUPPORT)   
            if(CurrentCoreId != NvM_Config[BlockId].PhyCoreId)
            {
                LogicCoreId = NvM_Config[BlockId].LogicCoreId;
                Result = NvM_AgentCmdAsync(LogicCoreId, NVM_NO_SERVICE, NVM_AGENT_BACK_JOB_INIT_CALLBACK, BlockId, NULL_PTR, (NvM_RequestResultType)0, NVM_INIT_RESTORE_BLOCK_DEFAULTS);
            }
            else
#endif
            {
                Result = NvM_InitBlockCallBackFunPtr[BlockId](NVM_INIT_RESTORE_BLOCK_DEFAULTS);
            }
            if(NVM_USER_JOB_PENDING != Result)
            {
                loopFlag = TRUE;
                NvM_JobSubState = NVM_SUBSTATE_RESTOREDATA_END;
                if(E_OK == Result)
                {
                    NvM_TempNvErrStatus = NVM_REQ_RESTORED_DEFAULTS;
                }
                else
                {
                    NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                }
            }
            /* else do nothing , wait for next main cycle */
            break;


        case NVM_SUBSTATE_RESTORE_ROMADDR:/*NVM267*/
            Result = NvM_CopyRomToRam(BlockId);
            if(NVM_USER_JOB_PENDING != Result)
            {
                loopFlag = TRUE;
                if(E_OK == Result)
                {
                    NvM_Restore_DataReadEnd(BlockId);
                }
                else
                {
                    NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                    NvM_JobSubState = NVM_SUBSTATE_RESTOREDATA_END;
                }
            }
            break;

#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)
        case NVM_SUBSTATE_RESTORE_ROMBLOCK:

            phyBlockId = NvM_GetPhyBlockId(BlockId);

            Result = MemIf_Read(NvM_Config[BlockId].DeviceId,
                                phyBlockId,
                                (uint16)0,
                                NvM_CurrentJobInfo.RamAddr,
                                NvM_Config[BlockId].Length);

            if(E_NOT_OK == Result)
            {
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                NvM_JobSubState = NVM_SUBSTATE_RESTOREDATA_END;
                loopFlag = TRUE;
            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_RESTORE_READ_WAIT;
            }

            break;

        case NVM_SUBSTATE_RESTORE_READ_WAIT:
#if(STD_ON == NVM_POLLING_MODE)
            JobResult = MemIf_GetJobResult(NvM_Config[BlockId].DeviceId);
            if(MEMIF_JOB_PENDING != JobResult)
            {
                loopFlag = TRUE;
                NvM_JobSubState = NVM_SUBSTATE_RESTORE_READ_WAIT_IND;
            }
#endif
            break;

        case NVM_SUBSTATE_RESTORE_READ_WAIT_IND:
            JobResult = MemIf_GetJobResult(NvM_Config[BlockId].DeviceId);
            loopFlag = TRUE;
            if(MEMIF_JOB_OK == JobResult)
            {
                NvM_Restore_DataReadEnd(BlockId);
            }
            else if(MEMIF_JOB_CANCELED == JobResult)
            {
                NvM_TempNvErrStatus = NVM_REQ_CANCELED;
                NvM_JobSubState = NVM_SUBSTATE_RESTOREDATA_END;
            }
            else
            {
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                NvM_JobSubState = NVM_SUBSTATE_RESTOREDATA_END;
            }
            break;
#endif/*#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)*/

#if(STD_ON == NVM_CRC_ENABLE)/*NVM229*/
        case NVM_SUBSTATE_RESTORECRC:
            Result = NvM_CRC_Process(BlockId);
            if(E_OK == Result)
            {
                loopFlag = TRUE;
                NvM_WriteCrcResultToRam(BlockId);
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
                if(NVM_PROCESS_SYN_RAM_BLOCK == NvM_GetUsedRamBlockType(BlockId))
                {
                    NvM_JobSubState = NVM_SUBSTATE_RESTOREDATA_SYN;
                }
                else
#endif
                {
                    NvM_TempNvErrStatus = NVM_REQ_RESTORED_DEFAULTS;
                    NvM_JobSubState = NVM_SUBSTATE_RESTOREDATA_END;
                }
            }
            break;
#endif

#if(STD_ON == NVM_USE_SYNC_MECHANISM)
        case NVM_SUBSTATE_RESTOREDATA_SYN:
            /* syn mirror is used, set invalid just before the data copy NVM227*/
            if(NVM_PROCESS_SYN_RAM_BLOCK == NvM_GetUsedRamBlockType(BlockId))
            {
                NVM_SET_INVALID_UNCHANGED(BlockId);
            }
            NvM_TempNvErrStatus = NVM_REQ_RESTORED_DEFAULTS;
            loopFlag = NvM_CallReadRamCbkProcess(BlockId, NVM_SUBSTATE_RESTOREDATA_END, NVM_SUBSTATE_RESTOREDATA_END);
            break;
#endif

        case NVM_SUBSTATE_RESTOREDATA_END:
            NvM_DemCheckReqFailEvent(NvM_TempNvErrStatus);

            if(NVM_REQ_RESTORED_DEFAULTS == NvM_TempNvErrStatus)
            {
                if(NvM_GetUsedRamBlockType(BlockId) >= NVM_PROCESS_PER_RAM_BLOCK)
                {
                    NVM_SET_VALID_CHANGED(BlockId);  /*NVM228*/
                }
            }
            NvM_SingleJobStop(BlockId, NvM_TempNvErrStatus);

            break;

        default:
            /* Unexpected case, report error, reset job to make other job running possible*/
            NvM_ResetJobState();
            NVM_DET_REPORT_ERROR(NVM_INTERNAL_RESTOREPROC_APIID, NVM_E_UNEXPECTED_CASE);
            break;

        }
    }
    while(TRUE == loopFlag);

}

#endif/*#if((NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) || (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2))*/





/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_MultiJobStop
*
* Description:  Multi  job end process.
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, NVM_CODE) NvM_MultiJobStop
(
    const NvM_RequestResultType reqResult
)
{
    uint8 serId = NvM_CurrentJobInfo.ServiceId;


    /* follow 2 code must be in this order*/
    NvM_AdmBlock[0].NvErrStatus = reqResult;
    NvM_ResetJobState();
#if(STD_ON == NVM_DRV_MODE_SWITCH)
#if(STD_CONFIG_VARIANTS_LINKTIME == NVM_CONFIG_VARIANTS)
    if(TRUE == NvM_DrvModeSwitch)
#endif
    {
        if(serId != NVM_JOB_VALIDATEALL)
        {
            MemIf_SetMode(MEMIF_MODE_SLOW);
        }
    }
#endif



#if(STD_ON == NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION)
#if(STD_CONFIG_VARIANTS_LINKTIME == NVM_CONFIG_VARIANTS)
    if(TRUE == NvM_BswMMultiBlockJobStatusInformation)
#endif
    {
        BswM_NvM_CurrentJobMode(serId, reqResult);
    }
#endif


    if(NvM_MultiCallBackFunPtr != NVM_NULL)
    {
        /*NVM260*/
        NvM_MultiCallBackFunPtr(serId, reqResult);
    }

}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_MutiReadJobEndProcess
*
* Description:  Multi read job end process.
*
* Inputs:       BlockId , JobResult
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, NVM_CODE) NvM_MultiReadJobEndProcess(void)
{
    NvM_RequestResultType reqResult;

    if(NvM_CurrentJobInfo.BlockId >= (NVM_TOTAL_NUM_OF_NVRAM_BLOCKS - (NvM_BlockIdType)1))
    {
        /* last block */
        /* When no readAll is running match is always false
           it will recaculate in each readall
        */
        NvM_CfgIdMatch = FALSE;
        reqResult = NvM_GetMultiReqResult();
        NvM_MultiJobStop(reqResult);
    }
    else
    {
        /* prepare for next block */
        NvM_JobSubState  = NVM_SUBSTATE_READALL;
        NvM_CurrentJobInfo.BlockId++;
    }

}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_CheckPerRamConfig
*
* Description:  check per ram config of block, if per ram is valid, output the ram pointer
*
* Inputs:       BlockId
*
* Outputs:      uint8, 0-no per rom config, 1-per ram config, 2-syn ram config
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, NVM_CODE)  NvM_CheckPerRamConfig
(
    NvM_BlockIdType BlockId,
    P2P2VAR(uint8, AUTOMATIC, AUTOMATIC) dataPtr
)
{
    uint8 ret = NVM_CONFIG_NO_PERRAM;

#if(STD_ON == NVM_USE_SYNC_MECHANISM)
    if(TRUE == NvM_Config[BlockId].EnUseSynM)
    {
        *dataPtr = NvM_MirrorBuffer;
        ret = NVM_CONFIG_SYN_PERRAM;
    }
    else
#endif
    {
        if(NVM_NULL != NvM_Config[BlockId].RamAddr)
        {
            *dataPtr = NvM_Config[BlockId].RamAddr;
            ret = NVM_CONFIG_PERRAM;
        }
        else
        {
            *dataPtr = NULL_PTR;
        }
    }
    return ret;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_isSkipReadAll
*
* Description:  check if block can skip readall job. If can not skip, switch sunbstate
*
* Inputs:       BlockId
*
* Outputs:      boolean
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, NVM_CODE)  NvM_isSkipReadAll
(
    NvM_BlockIdType BlockId
)
{
    uint8 skipFlag = NVM_NOT_SKIPREADALL;
    uint8 result = (uint8)0;

    if(FALSE == NvM_Config[BlockId].EnReadAll)
    {
        skipFlag = NVM_NORMAL_SKIPREADALL;
    }
#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)
    /* dont read dataset block in read all NVM245*/
    else if(NVM_BLOCK_DATASET == NvM_Config[BlockId].BlockType)
    {
        skipFlag = NVM_NORMAL_SKIPREADALL;
    }
#endif
    else
    {
        /* all condition pass, check if perram or syn is correct*/
        result = NvM_CheckPerRamConfig(BlockId, &NvM_CurrentJobInfo.RamAddr);
        if(NVM_CONFIG_NO_PERRAM == result)
        {
            skipFlag = NVM_NORMAL_SKIPREADALL;
        }
        else
        {
            if(TRUE == (boolean)NVM_VALID_BIT(BlockId))
            {
#if (STD_ON == NVM_CRC_ENABLE)
                if(TRUE == NvM_Config[BlockId].EnCrc)
                {
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
                    if(NVM_CONFIG_SYN_PERRAM == result)
                    {
                        NvM_JobSubState = NVM_SUBSTATE_READALL_PRECRC_READIN;
                    }
                    else
#endif
                    {
                        NvM_JobSubState = NVM_SUBSTATE_READALL_PRECRC;
                    }
                }
                else
#endif
                {
                    skipFlag = NVM_VALID_SKIPREADALL;
                }
            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_READ_DATA;
            }


        }


    }


    return skipFlag;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ReadAllJobProcess
*
* Description:  read all block process.
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, NVM_CODE)  NvM_InitImplicitRestore
(
    NvM_BlockIdType BlockId
)
{
    /* end read if no data can restore*/
    NvM_JobSubState = NVM_SUBSTATE_READ_END;

    /* dont restore data when ramblock is valid*/
    if(FALSE == (boolean)NVM_VALID_BIT(BlockId))
    {
        if(NULL_PTR != NvM_InitBlockCallBackFunPtr[BlockId])
        {
            NvM_JobSubState = NVM_SUBSTATE_READ_RESTORE_USER;
        }
        else if(NULL_PTR != NvM_Config[BlockId].RomAddr)
        {
            NvM_JobSubState = NVM_SUBSTATE_READ_RESTORE;
        }
        else
        {
            /*do nothing, keep NvM_JobSubState = NVM_SUBSTATE_READ_END*/
        }
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_CheckCfgIdMisMatch
*
* Description:  check if cfgid mismatch
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == NVM_DYNAMIC_CONFIGURATION)
STATIC FUNC(void, NVM_CODE)  NvM_CheckCfgIdMisMatch
(
    P2VAR(NvM_RequestResultType, AUTOMATIC, AUTOMATIC) result
)
{
    if((NVM_CFGID_BLOCK_HANDLE == NvM_CurrentJobInfo.BlockId)
            && (NVM_READ_ALL == NvM_CurrentJobInfo.ServiceId))
    {
        /* readok and CfgId match
           if block1 is skip or cancel, also set false
        */
        if((NVM_REQ_OK == NvM_TempNvErrStatus)
                && (NvM_CfgIDBuffer[0] == NvM_CompiledConfigId[0])
                && (NvM_CfgIDBuffer[1] == NvM_CompiledConfigId[1]))
        {
            NvM_CfgIdMatch = TRUE;
        }
        else
        {
            NvM_CfgIdMatch = FALSE;
            /* mismatch occur, SWS_NvM_00310 auto set CfgId to default
               and set ramStatus to changed, so tat the new cfgid will be write into nv block during writeall
               also crc will be cacultaed during write job
            */
            NvM_CfgIDBuffer[0] = NvM_CompiledConfigId[0];
            NvM_CfgIDBuffer[1] = NvM_CompiledConfigId[1];
            NVM_SET_VALID_CHANGED(NVM_CFGID_BLOCK_HANDLE);
            /* set state to restroe if mismatch */
            *result = NVM_REQ_RESTORED_DEFAULTS;


        }
    }
}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ReadAllJobProcess
*
* Description:  read all block process.
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE)  NvM_ReadAllJobProcess(void)
{
    NvM_BlockIdType tempBlockId;
    uint8 skipFlag = NVM_NOT_SKIPREADALL;
#if(STD_ON == NVM_CRC_ENABLE)
    Std_ReturnType Result;
    uint32 crcR;
#endif
    /*PRQA S 2488,2481 ++*/
    /*
    Loop control variable in this 'while' statement, is not modified inside loop but has file scope.
    */
    /* search next read block */
    while(NVM_SUBSTATE_READALL == NvM_JobSubState)
    {
        if((NvM_BlockIdType)0 == NvM_CurrentJobInfo.BlockId)
        {
            NvM_CurrentJobInfo.BlockId = NVM_USER_BLOCKID_START;/*NVM244*/
        }

        tempBlockId = NvM_CurrentJobInfo.BlockId;

        skipFlag = NvM_isSkipReadAll(tempBlockId);

        if(NVM_NOT_SKIPREADALL == skipFlag)
        {
            /* check CfgId misMatch */
#if(STD_ON == NVM_DYNAMIC_CONFIGURATION)
            if((NVM_CFGID_BLOCK_HANDLE != tempBlockId)
                    && (FALSE == NvM_CfgIdMatch)
                    && (FALSE == NvM_Config[tempBlockId].EnResistChged))
            {
                NvM_TempNvErrStatus = NVM_REQ_INTEGRITY_FAILED;
                /*mismatch occurs, restore data*/
                NvM_InitImplicitRestore(tempBlockId);
            }
#endif

        }
        else if(NVM_NORMAL_SKIPREADALL == skipFlag)
        {
            NvM_SingleJobStop(tempBlockId, NVM_REQ_BLOCK_SKIPPED);/*NVM287*/
        }
        else
        {
            NvM_SingleJobStop(tempBlockId, NVM_REQ_OK);/*NVM364*/

        }
    }
    /*PRQA S 2488,2481 --*/


#if(STD_ON == NVM_CRC_ENABLE)
    /* readall preCrc */
    if(NVM_SUBSTATE_READALL_PRECRC == NvM_JobSubState)
    {
        tempBlockId = NvM_CurrentJobInfo.BlockId;
        Result = NvM_CRC_Process(tempBlockId);
        if(E_OK == Result)
        {
            crcR = NvM_ReadRamCrcResult(tempBlockId);
            if(crcR == NvM_NvCrcResult)
            {
                /*NVM00364  crc match, skip read this block,  job = OK */
#if(STD_ON == NVM_DYNAMIC_CONFIGURATION)
            	if(tempBlockId == NVM_CFGID_BLOCK_HANDLE)
            	{
                    /*PRQA S 432 ++*/
                    /*
                    Specific implementation methods.
                    */
            	    NvM_CheckCfgIdMisMatch(NVM_REQ_OK);
                    /*PRQA S 432 --*/
            	}
#endif
                NvM_SingleJobStop(tempBlockId, NVM_REQ_OK);

            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_READ_DATA;
            }
        }

    }
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
    else if(NVM_SUBSTATE_READALL_PRECRC_READIN == NvM_JobSubState)
    {
        (void)NvM_CallWriteRamCbkProcess(tempBlockId, NVM_SUBSTATE_READALL_PRECRC,
                                                      NVM_SUBSTATE_READ_DATA);
    }
#endif
    else
#endif
    {
        if(NVM_SUBSTATE_IDLE != NvM_JobSubState)
        {
            tempBlockId = NvM_CurrentJobInfo.BlockId;
            NvM_ReadJobProcess(tempBlockId);
        }

    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_MultiWriteJobEndProcess
*
* Description:  multi write job end process.
*
* Inputs:       BlockId,JobResult
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, NVM_CODE) NvM_MultiWriteJobEndProcess(void)
{
    NvM_BlockIdType tempBlockId = NvM_CurrentJobInfo.BlockId;

    if(tempBlockId == NVM_CFGID_BLOCK_HANDLE)
    {
        /* last block is block1*/
        NvM_JobSubState = NVM_SUBSTATE_WRITEALL_WAIT_LOWIDLE;
    }
    else if(tempBlockId >= (NVM_TOTAL_NUM_OF_NVRAM_BLOCKS - (NvM_BlockIdType)1))
    {
        NvM_JobSubState  = NVM_SUBSTATE_WRITEALL;
        NvM_CurrentJobInfo.BlockId = NVM_CFGID_BLOCK_HANDLE;
    }
    else
    {
        /* prepare for next block */
        NvM_JobSubState  = NVM_SUBSTATE_WRITEALL;
        NvM_CurrentJobInfo.BlockId++;
    }

}







/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_isSkipWriteAll
*
* Description:  check if block can skip writeall job. If can not skip, switch sunbstate
*
* Inputs:       BlockId
*
* Outputs:      boolean
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, NVM_CODE)  NvM_isSkipWriteAll
(
    NvM_BlockIdType BlockId
)
{
    boolean skipFlag = FALSE;
    uint8 result = NvM_CheckPerRamConfig(BlockId, &NvM_CurrentJobInfo.RamAddr);
    boolean lossR = FALSE;


#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
    if ((NVM_BLOCK_REDUNDANT == NvM_Config[BlockId].BlockType) && (TRUE == (boolean)NVM_LOSSR_BIT(BlockId)))
    {
        lossR = TRUE;
    }
#endif

    /* user config
       ram addr not null
       attributes is valid and changed
       not protected, canbe write
       dataset not index to rom block
       NVM252 NVM432 NVM682 NVM433 NVM434
    */
    if(FALSE == NvM_Config[BlockId].EnWriteAll)
    {
        skipFlag = TRUE;
    }
    else if(NVM_CONFIG_NO_PERRAM == result)
    {
        skipFlag = TRUE;
    }

#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)
    else if((NVM_BLOCK_DATASET == NvM_Config[BlockId].BlockType)
            && (NvM_AdmBlock[BlockId].NvDataIndex >= NvM_Config[BlockId].NvBlockNum))
    {
        skipFlag = TRUE;
    }
#endif
#if(STD_ON == NVM_SET_BLOCK_LOCK_API)
    else if(TRUE == (boolean)NVM_LOCK_BIT(BlockId))
    {
        skipFlag = TRUE;
    }
#endif
#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
    /*
        NVM474
        block will not skip if lossRed is true even if protect bit is true
        or changebit is false, as lossRed must be repaired here.
       */
    else if((TRUE == (boolean)NVM_PROTECTED_BIT(BlockId)) && (FALSE == lossR))
    {
        skipFlag = TRUE;
    }
#endif
    else if((TRUE == NvM_Config[BlockId].UseSetRamBlockStatus)/*NVM344*/
            && ((FALSE == (boolean)NVM_VALID_BIT(BlockId)) || (FALSE == (boolean)NVM_CHANGED_BIT(BlockId)))
            && (FALSE == lossR))
    {
        skipFlag = TRUE;
    }
    else
    {
        /* all condition pass, check if perram or syn */
        if(NVM_CONFIG_PERRAM == result)
        {
#if (STD_ON == NVM_CRC_ENABLE)
            if(TRUE == NvM_Config[BlockId].EnCrc)
            {
                NvM_JobSubState = NVM_SUBSTATE_WRITE_CALCRC;
            }
            else
#endif
            {
                NvM_JobSubState = NVM_SUBSTATE_WRITE_DATA;
            }
        }
        else/* only NVM_CONFIG_SYN_PERRAM possible here */
        {
            NvM_JobSubState = NVM_SUBSTATE_WRITE_SYN;
        }

        /* NVM344 start write this block, need set status first */
        NVM_SET_VALID_CHANGED(BlockId);
    }

    return skipFlag;

}




/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_WriteAllJobProcess
*
* Description:  write  all block process.
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE)  NvM_WriteAllJobProcess(void)
{
    NvM_BlockIdType tempBlockId;
    boolean skipFlag = FALSE;

    MemIf_StatusType status;
    NvM_RequestResultType reqResult;

    /*PRQA S 2488,2481 ++*/
    /*
    Loop control variable in this 'while' statement, is not modified inside loop but has file scope.
    */
    /* search next write block */
    while(NVM_SUBSTATE_WRITEALL == NvM_JobSubState)
    {
        if(TRUE == NvM_CancelWriteAllFlag)/*NVM235 NVM238*/
        {
            SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
            tempBlockId = NvM_CurrentJobInfo.BlockId;


            while(tempBlockId < NVM_TOTAL_NUM_OF_NVRAM_BLOCKS)
            {
                /*NVM236*/
                if(FALSE == NvM_CheckBlockPending(tempBlockId, FALSE))
                {
                    NvM_AdmBlock[tempBlockId].NvErrStatus = NVM_REQ_CANCELED;
                }

                tempBlockId++;
            }

            if(FALSE == NvM_CheckBlockPending(NVM_CFGID_BLOCK_HANDLE, FALSE))
            {
                NvM_AdmBlock[NVM_CFGID_BLOCK_HANDLE].NvErrStatus = NVM_REQ_CANCELED;
            }


            /* follow 2 code must be in this order */
            NvM_MultiJobStop(NVM_REQ_CANCELED);  /*NVM237*/

            NvM_CancelWriteAllFlag = FALSE;
            SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();


            skipFlag = TRUE;
        }
        else
        {
            if((NvM_BlockIdType)0 == NvM_CurrentJobInfo.BlockId)
            {
                NvM_CurrentJobInfo.BlockId = NVM_WRITEALL_BLOCKID_START;
            }

            tempBlockId = NvM_CurrentJobInfo.BlockId;

            skipFlag = NvM_isSkipWriteAll(tempBlockId);

            if(TRUE == skipFlag)
            {
                NvM_SingleJobStop(tempBlockId, NVM_REQ_BLOCK_SKIPPED); /*NVM298*/
            }

        }
    }
    /*PRQA S 2488,2481 --*/

    /* NvM350, WriteAll finish, waiting for lowlayyer module idle*/
    if(NvM_JobSubState == NVM_SUBSTATE_WRITEALL_WAIT_LOWIDLE)
    {
        status = MemIf_GetStatus(MEMIF_BROADCAST_ID);
        if((MEMIF_IDLE == status) || (MEMIF_UNINIT == status))
        {
            reqResult = NvM_GetMultiReqResult();
            NvM_MultiJobStop(reqResult);
        }
    }
    else
    {
        if(NvM_JobSubState != NVM_SUBSTATE_IDLE)
        {
            tempBlockId = NvM_CurrentJobInfo.BlockId;
            NvM_WriteJobProcess(tempBlockId);
        }

    }



}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_SetRamStatusProcess
*
* Description:  when set block changed, need recaculate CRC
*
* Inputs:       BlockId
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
#if((STD_ON == NVM_CRC_ENABLE) && (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON))
FUNC(void, NVM_CODE)  NvM_SetRamStatusProcess
(
    const NvM_BlockIdType BlockId
)
{
    Std_ReturnType Result;
    boolean loopFlag = FALSE;


    do
    {
        loopFlag = FALSE;
        switch(NvM_JobSubState)
        {
        case NVM_SUBSTATE_SETRAM_CRC:
            Result = NvM_CRC_Process(BlockId);
            if(E_OK == Result)
            {
                NvM_WriteCrcResultToRam(BlockId);
                loopFlag = TRUE;
                NvM_TempNvErrStatus = NVM_REQ_OK;

                if(NVM_PROCESS_SYN_RAM_BLOCK == NvM_GetUsedRamBlockType(BlockId))
                {
                    NvM_JobSubState = NVM_SUBSTATE_SETRAM_SYN_WRITEOUT;
                }
                else
                {
                    NvM_JobSubState = NVM_SUBSTATE_SETRAM_END;
                }

            }
            break;

#if(STD_ON == NVM_USE_SYNC_MECHANISM)

        case NVM_SUBSTATE_SETRAM_SYN_READIN:

            loopFlag = NvM_CallWriteRamCbkProcess(BlockId, NVM_SUBSTATE_SETRAM_CRC,
                                                           NVM_SUBSTATE_SETRAM_END);

            break;

        case NVM_SUBSTATE_SETRAM_SYN_WRITEOUT:
            loopFlag = NvM_CallReadRamCbkProcess(BlockId, NVM_SUBSTATE_SETRAM_END, NVM_SUBSTATE_SETRAM_END);

            break;

        case NVM_SUBSTATE_SETRAM_END:
            NvM_DemCheckReqFailEvent(NvM_TempNvErrStatus);
            NvM_SingleJobStop(BlockId, NvM_TempNvErrStatus);
            break;
#endif
        default:
            /* Unexpected case, report error, reset job to make other job running possible*/
            NvM_ResetJobState();
            NVM_DET_REPORT_ERROR(NVM_INTERNAL_SETRAMPROC_APIID, NVM_E_UNEXPECTED_CASE);
            break;



        }
    }
    while(TRUE == loopFlag);




}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_EraseProcess
*
* Description:  process earse job
*
* Inputs:       BlockId
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
#if(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)

#if(STD_ON == NVM_ERASE_API)
FUNC(void, NVM_CODE)  NvM_EraseProcess
(
    const NvM_BlockIdType BlockId
)
{
    NvM_BlockIdType phyBlockId;
    Std_ReturnType Result;
    MemIf_JobResultType JobResult;
    boolean loopFlag;

    do
    {
        loopFlag = FALSE;
        switch(NvM_JobSubState)
        {
        case NVM_SUBSTATE_ERASE:

            phyBlockId = NvM_GetPhyBlockId(BlockId);
            Result = MemIf_EraseImmediateBlock(NvM_Config[BlockId].DeviceId,
                                               phyBlockId);

            if(E_NOT_OK == Result)
            {
                NvM_JobSubState = NVM_SUBSTATE_ERASE_END;
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                loopFlag = TRUE;
            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_ERASE_WAIT;
            }

            break;

        case NVM_SUBSTATE_ERASE_WAIT:
#if(STD_ON == NVM_POLLING_MODE)
            JobResult = MemIf_GetJobResult(NvM_Config[BlockId].DeviceId);
            if(MEMIF_JOB_PENDING != JobResult)
            {
                loopFlag = TRUE;
                NvM_JobSubState = NVM_SUBSTATE_ERASE_WAIT_IND;
            }
#endif
            break;

        case NVM_SUBSTATE_ERASE_WAIT_IND:
            JobResult = MemIf_GetJobResult(NvM_Config[BlockId].DeviceId);
            loopFlag = TRUE;

            if(MEMIF_JOB_OK == JobResult)
            {
#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
                if((NVM_BLOCK_REDUNDANT == NvM_Config[BlockId].BlockType)
                        && ((uint8)0 == NvM_AdmBlock[BlockId].NvDataIndex))
                {
                    NvM_AdmBlock[BlockId].NvDataIndex = (uint8)1;
                    NvM_JobSubState = NVM_SUBSTATE_ERASE;
                }
                else
#endif
                {
                    NvM_JobSubState = NVM_SUBSTATE_ERASE_END;
                    NvM_TempNvErrStatus = NVM_REQ_OK;
                }
            }
            else if(MEMIF_JOB_CANCELED == JobResult)
            {
                NvM_JobSubState = NVM_SUBSTATE_ERASE_END;
                NvM_TempNvErrStatus = NVM_REQ_CANCELED;
            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_ERASE_END;
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
            }

            break;

        case NVM_SUBSTATE_ERASE_END:
            /* ref 7.2.2.14
               dont need to check if per ram is used,as all block can be set to invalid & unchanged
            */
            if(NVM_REQ_OK == NvM_TempNvErrStatus)
            {
                NVM_SET_INVALID_UNCHANGED(BlockId);
            }

            NvM_DemCheckReqFailEvent(NvM_TempNvErrStatus);
            NvM_DemCheckHardwareError(NvM_TempNvErrStatus);
            NvM_SingleJobStop(BlockId, NvM_TempNvErrStatus);


            break;

        default:
            /* Unexpected case, report error, reset job to make other job running possible*/
            NvM_ResetJobState();
            NVM_DET_REPORT_ERROR(NVM_INTERNAL_ERASEPROC_APIID, NVM_E_UNEXPECTED_CASE);
            break;
        }
    }
    while(TRUE == loopFlag);

}

#endif/*#if(STD_ON == NVM_ERASE_API)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_InvalidProcess
*
* Description:  process invalid job
*
* Inputs:       BlockId
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == NVM_INVALID_NVBLOCK_API)
FUNC(void, NVM_CODE)  NvM_InvalidProcess
(
    const NvM_BlockIdType BlockId
)
{
    NvM_BlockIdType phyBlockId;
    Std_ReturnType Result;
    MemIf_JobResultType JobResult;
    boolean loopFlag;

    do
    {
        loopFlag = FALSE;
        switch(NvM_JobSubState)
        {
        case NVM_SUBSTATE_INVALID:

            phyBlockId = NvM_GetPhyBlockId(BlockId);
            Result = MemIf_InvalidateBlock(NvM_Config[BlockId].DeviceId,
                                           phyBlockId);

            if(E_NOT_OK == Result)
            {
                NvM_JobSubState = NVM_SUBSTATE_INVALID_END;
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                loopFlag = TRUE;
            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_INVALID_WAIT;
            }

            break;

        case NVM_SUBSTATE_INVALID_WAIT:
#if(STD_ON == NVM_POLLING_MODE)
            JobResult = MemIf_GetJobResult(NvM_Config[BlockId].DeviceId);
            if(MEMIF_JOB_PENDING != JobResult)
            {
                loopFlag = TRUE;
                NvM_JobSubState = NVM_SUBSTATE_INVALID_WAIT_IND;
            }
#endif
            break;

        case NVM_SUBSTATE_INVALID_WAIT_IND:
            JobResult = MemIf_GetJobResult(NvM_Config[BlockId].DeviceId);
            loopFlag = TRUE;

            if(MEMIF_JOB_OK == JobResult)
            {
#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
                if((NVM_BLOCK_REDUNDANT == NvM_Config[BlockId].BlockType)
                        && ((uint8)0 == NvM_AdmBlock[BlockId].NvDataIndex))
                {
                    NvM_AdmBlock[BlockId].NvDataIndex = (uint8)1;
                    NvM_JobSubState = NVM_SUBSTATE_INVALID;
                }
                else
#endif
                {
                    NvM_JobSubState = NVM_SUBSTATE_INVALID_END;
                    NvM_TempNvErrStatus = NVM_REQ_OK;
                }
            }
            else if(MEMIF_JOB_CANCELED == JobResult)
            {
                NvM_JobSubState = NVM_SUBSTATE_INVALID_END;
                NvM_TempNvErrStatus = NVM_REQ_CANCELED;
            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_INVALID_END;
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
            }

            break;

        case NVM_SUBSTATE_INVALID_END:
            /* ref 7.2.2.14
               dont need to check if per ram is used,as all block can be set to invalid & unchanged
            */
            if(NVM_REQ_OK == NvM_TempNvErrStatus)
            {
                NVM_SET_INVALID_UNCHANGED(BlockId);
            }
            NvM_DemCheckReqFailEvent(NvM_TempNvErrStatus);
            NvM_DemCheckHardwareError(NvM_TempNvErrStatus);
            NvM_SingleJobStop(BlockId, NvM_TempNvErrStatus);
            break;
        default:
            /* Unexpected case, report error, reset job to make other job running possible*/
            NvM_ResetJobState();
            NVM_DET_REPORT_ERROR(NVM_INTERNAL_INVALIDPROC_APIID, NVM_E_UNEXPECTED_CASE);            
            break;
        }

    }
    while(TRUE == loopFlag);

}

#endif/*#if(STD_ON == NVM_INVALID_NVBLOCK_API)*/

#endif/*#if(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)*/


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_JobNotification
*
* Description:  Error notification from unlayyer
*
* Inputs:       BlockId , ServiceId, JobResult
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE)  NvM_JobNotification(void)
{
    if(NVM_STATE_BUSY == NvM_TaskState)
    {
        switch(NvM_CurrentJobInfo.ServiceId)
        {

        case NVM_JOB_READALL:
            if(NVM_SUBSTATE_READDATA_WAIT == NvM_JobSubState)
            {
                NvM_JobSubState = NVM_SUBSTATE_READDATA_WAIT_IND;
            }
            break;

        case NVM_JOB_WRITEALL:
            if(NVM_SUBSTATE_WRITE_WAIT == NvM_JobSubState)
            {
                NvM_JobSubState = NVM_SUBSTATE_WRITE_WAIT_IND;
            }
            else if(NVM_SUBSTATE_WRITE_VER_WAIT == NvM_JobSubState)
            {
                NvM_JobSubState = NVM_SUBSTATE_WRITE_VER_WAIT_IND;
            }
            else
            {
                /*do nothing, ignor this notification */ 		
            }
            break;

        case NVM_JOB_FIRSTINITALL:
            if(NVM_SUBSTATE_FIRSTINITALL_WRITE_WAIT == NvM_JobSubState)
            {
                NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_WRITE_WAIT_IND;
            }
            else if(NVM_SUBSTATE_FIRSTINITALL_INVALID_WAIT == NvM_JobSubState)
            {
                NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_INVALID_WAIT_IND;		
            }
            else
            {
                /*do nothing, ignor this notification */ 
            }
            
            break;
#if((NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) || (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2))
        case NVM_JOB_READ:
        case NVM_JOB_READ_PRAMBLOCK:
            if(NVM_SUBSTATE_READDATA_WAIT == NvM_JobSubState)
            {
                NvM_JobSubState = NVM_SUBSTATE_READDATA_WAIT_IND;
            }
            break;


        case NVM_JOB_WRITE:
        case NVM_JOB_WRITE_PRAMBLOCK:
            if(NVM_SUBSTATE_WRITE_WAIT == NvM_JobSubState)
            {
                NvM_JobSubState = NVM_SUBSTATE_WRITE_WAIT_IND;
            }
            else if(NVM_SUBSTATE_WRITE_VER_WAIT == NvM_JobSubState)
            {
                NvM_JobSubState = NVM_SUBSTATE_WRITE_VER_WAIT_IND;
            }
            else
            {
                /*do nothing, ignor this notification */ 
            }
            break;

        case NVM_JOB_RESTORE:
        case NVM_JOB_RESTORE_PRAMBLOCK:
#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)
            if(NVM_SUBSTATE_RESTORE_READ_WAIT == NvM_JobSubState)
            {
                NvM_JobSubState = NVM_SUBSTATE_RESTORE_READ_WAIT_IND;
            }
#endif
            break;
#endif

#if(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)

#if(STD_ON == NVM_ERASE_API)
        case NVM_JOB_ERASE:
            if(NVM_SUBSTATE_ERASE_WAIT == NvM_JobSubState)
            {
                NvM_JobSubState = NVM_SUBSTATE_ERASE_WAIT_IND;
            }
            break;
#endif

#if(STD_ON == NVM_INVALID_NVBLOCK_API)
        case NVM_JOB_INVALID:
            if(NVM_SUBSTATE_INVALID_WAIT == NvM_JobSubState)
            {
                NvM_JobSubState = NVM_SUBSTATE_INVALID_WAIT_IND;
            }
            break;
#endif

#endif

        default:
            /* Unexpected case, report error, reset job to make other job running possible*/
            NvM_ResetJobState();
            NVM_DET_REPORT_ERROR(NVM_INTERNAL_NOTIFICATION_APIID, NVM_E_UNEXPECTED_CASE); 
            break;
        }
    }

}

#if(STD_ON == NVM_CIPHER_ENABLE)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_JobCryptEndNotification
*
* Description:  Crypt end notification from unlayyer
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE)  NvM_JobCryptEndNotification(void)
{
    if(NVM_STATE_BUSY == NvM_TaskState)
    {
        switch(NvM_CurrentJobInfo.ServiceId)
        {
        case NVM_JOB_READALL:
            if(NVM_SUBSTATE_READ_DECRYPT_WAIT == NvM_JobSubState)
            {
                NvM_JobSubState = NVM_SUBSTATE_READ_PREEND;
            }
            break;

        case NVM_JOB_WRITEALL:
            if(NVM_SUBSTATE_WRITE_ENCRYPT_WAIT == NvM_JobSubState)
            {
                NvM_JobSubState = NVM_SUBSTATE_WRITE_ENCRYPT_END;
            }
            break;

#if((NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) || (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2))
        case NVM_JOB_READ:
        case NVM_JOB_READ_PRAMBLOCK:
            if(NVM_SUBSTATE_READ_DECRYPT_WAIT == NvM_JobSubState)
            {
                NvM_JobSubState = NVM_SUBSTATE_READ_PREEND;
            }
            break;

        case NVM_JOB_WRITE:
        case NVM_JOB_WRITE_PRAMBLOCK:
            if(NVM_SUBSTATE_WRITE_ENCRYPT_WAIT == NvM_JobSubState)
            {
                NvM_JobSubState = NVM_SUBSTATE_WRITE_ENCRYPT_END;
            }
            break;

#endif
        default:
            break;
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_JobCryptErrorNotification
*
* Description:  Crypt error notification from unlayyer
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE)  NvM_JobCryptErrorNotification(void)
{
    if(NVM_STATE_BUSY == NvM_TaskState)
    {
        switch(NvM_CurrentJobInfo.ServiceId)
        {
        case NVM_JOB_READALL:
            if(NVM_SUBSTATE_READ_DECRYPT_WAIT == NvM_JobSubState)
            {
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                NvM_JobSubState = NVM_SUBSTATE_READ_PREEND;
            }
            break;

        case NVM_JOB_WRITEALL:
            if(NVM_SUBSTATE_WRITE_ENCRYPT_WAIT == NvM_JobSubState)
            {
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                NvM_JobSubState = NVM_SUBSTATE_WRITE_END;
            }
            break;

#if((NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) || (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2))
        case NVM_JOB_READ:
        case NVM_JOB_READ_PRAMBLOCK:
            if(NVM_SUBSTATE_READ_DECRYPT_WAIT == NvM_JobSubState)
            {
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                NvM_JobSubState = NVM_SUBSTATE_READ_PREEND;
            }
            break;

        case NVM_JOB_WRITE:
        case NVM_JOB_WRITE_PRAMBLOCK:
            if(NVM_SUBSTATE_WRITE_ENCRYPT_WAIT == NvM_JobSubState)
            {
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                NvM_JobSubState = NVM_SUBSTATE_WRITE_END;
            }
            break;

#endif
        default:
            break;
        }
    }
}
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_MultiValidateJobEndProcess
*
* Description:  Multi Validate job end process.
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, NVM_CODE) NvM_MultiValidateJobEndProcess(void)
{
    if(NvM_CurrentJobInfo.BlockId >= (NVM_TOTAL_NUM_OF_NVRAM_BLOCKS - (NvM_BlockIdType)1))
    {
        /* last block */
        /* Validate job , always report OK*/
        /*reqResult = NvM_GetMultiReqResult();*/
        NvM_MultiJobStop(NVM_REQ_OK);
    }
    else
    {
        /* prepare for next block */
        NvM_JobSubState  = NVM_SUBSTATE_VALIDATEDALL;
        NvM_CurrentJobInfo.BlockId++;
    }

}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ValidateAllJobProcess
*
* Description:  write  all block process.
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE)  NvM_ValidateAllJobProcess(void)
{
    NvM_BlockIdType tempBlockId;
    uint8 result = (uint8)0;
    /*PRQA S 2481 ++*/
    /*
    Loop control variable in this 'while' statement, is not modified inside loop but has file scope.
    */
    /* search next write block */
    while(NVM_SUBSTATE_VALIDATEDALL == NvM_JobSubState)
    {
        if((NvM_BlockIdType)0 == NvM_CurrentJobInfo.BlockId)
        {
            NvM_CurrentJobInfo.BlockId = NVM_USER_BLOCKID_START;
        }

        tempBlockId = NvM_CurrentJobInfo.BlockId;

        /* NVM860  NVM856
           ram addr not null or synmirror is enable
           not protected or lock, can change status
                         attributes is valid and changed
        */

        result = NvM_CheckPerRamConfig(tempBlockId, &NvM_CurrentJobInfo.RamAddr);

        if((NVM_CONFIG_NO_PERRAM != result)
#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
                && (FALSE == (boolean)NVM_PROTECTED_BIT(tempBlockId))
#endif

#if(STD_ON == NVM_SET_BLOCK_LOCK_API)
                && (FALSE == (boolean)NVM_LOCK_BIT(tempBlockId))
#endif
                && (TRUE == NvM_Config[tempBlockId].AutoValidation))
        {
            NVM_SET_VALID_CHANGED(tempBlockId);
#if(STD_ON == NVM_CRC_ENABLE)
            if(TRUE == NvM_Config[tempBlockId].EnCrc)
            {
                if(NVM_CONFIG_PERRAM == result)
                {
                    NvM_JobSubState = NVM_SUBSTATE_SETRAM_CRC;
                }
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
                else
                {
                    NvM_JobSubState = NVM_SUBSTATE_SETRAM_SYN_READIN;
                }
#endif
            }
            else
#endif
            {
                NvM_SingleJobStop(tempBlockId, NVM_REQ_OK);
            }
        }
        else
        {
            /* block not support validate, skip to next block*/
            NvM_SingleJobStop(tempBlockId, NVM_REQ_BLOCK_SKIPPED);
        }
    }
    /*PRQA S 2481 --*/
#if((STD_ON == NVM_CRC_ENABLE) && (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON))

    if(NVM_SUBSTATE_IDLE != NvM_JobSubState)
    {
        (void)NvM_SetRamStatusProcess(tempBlockId);
    }
#endif
}





/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ReplaceWithImmJob
*
* Description:  check and replace low pri job  with imm job ,
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == NVM_IMM_BLOCK_SUPPORT)
FUNC(void, NVM_CODE) NvM_ReplaceWithImmJob(void)
{

    if((NvM_ImmQueue.Header != NVM_QUE_INVALID_POS)  /*imm queue is not  empty */
            && (NVM_STATE_BUSY == NvM_TaskState)
            && (NVM_JOB_IDLE != NvM_CurrentJobInfo.ServiceId)) /* there is job running*/
    {
        /* if none immjob is ongoing, imm block write must be handled first
           none immjob will be cancel,and pengding on queue,it will be restart after immjob is finish
           NVM300  nvm258
         */
        if(((NVM_JOB_WRITE != NvM_CurrentJobInfo.ServiceId) && (NVM_JOB_WRITE_PRAMBLOCK != NvM_CurrentJobInfo.ServiceId))
                || ((uint8)0 != NvM_Config[NvM_CurrentJobInfo.BlockId].BlockPri))
        {
            /* cancel at once */
            MemIf_Cancel(NvM_Config[NvM_CurrentJobInfo.BlockId].DeviceId);
            /* put ongoing job into preempt buffer*/
            NvM_PreemptJob.BlockId = NvM_CurrentJobInfo.BlockId;
            NvM_PreemptJob.ServiceId = NvM_CurrentJobInfo.ServiceId;
            NvM_PreemptJob.RamAddr = NvM_CurrentJobInfo.RamAddr;

            /* preempt job will restart after immjob, so the job is still pending, and dont need to report cancel to uplayyer*/

            /* reset interrupt block status */
            NvM_AdmBlock[NvM_CurrentJobInfo.BlockId].multiNvErrStatus = NVM_REQ_OK;
#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
            if(NVM_BLOCK_DATASET != NvM_Config[NvM_CurrentJobInfo.BlockId].BlockType)
            {
                NvM_AdmBlock[NvM_CurrentJobInfo.BlockId].NvDataIndex = (uint8)0;
            }
#endif

            /* cancelWriteAll and cfgidMsmath must be saved to ensure the follwing multi job is corect*/
            NvM_ResetJobState();
        }
    }
}

#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_MultiFistInitAllEndProcess
*
* Description:  first init  all block end process.
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, NVM_CODE) NvM_MultiFirstInitAllEndProcess(void)
{
    NvM_RequestResultType reqResult = NVM_REQ_OK;
    if(NvM_CurrentJobInfo.BlockId >= (NVM_TOTAL_NUM_OF_NVRAM_BLOCKS - (NvM_BlockIdType)1))
    {
        /* last block */
    	reqResult = NvM_GetMultiReqResult();
        NvM_MultiJobStop(reqResult);
    }
    else
    {
        /* prepare for next block */
        NvM_JobSubState  = NVM_SUBSTATE_FIRSTINITALL;
        NvM_CurrentJobInfo.BlockId++;
    }
}

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_FisrtInitALL_Restore_DataReadEnd
*
* Description:  check if block can skip first init all job. If can not skip, switch substate
*
* Inputs:       BlockId
*
* Outputs:      boolean
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, NVM_CODE) NvM_FisrtInitALL_Restore_DataReadEnd
(
    const NvM_BlockIdType BlockId
)
{
#if(STD_ON == NVM_CRC_ENABLE)/*NVM229*/
    if(TRUE == NvM_Config[BlockId].EnCrc)
    {
        NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_RESTORECRC;
    }
    else
#endif
    {
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
        if(NVM_PROCESS_SYN_RAM_BLOCK == NvM_GetUsedRamBlockType(BlockId))
        {
            NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_RESTOREDATA_SYN;
        
        }
        else
#endif
        {
            NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_RESTOREDATA_END;
            NvM_TempNvErrStatus = NVM_REQ_RESTORED_DEFAULTS;

        }
    }

}

#if(STD_ON == NVM_FIRST_INIT_ALL_SUPPORT)
STATIC FUNC(boolean, NVM_CODE)  NvM_isSkipFirstInitAll
(
    NvM_BlockIdType BlockId
)
{
    boolean skipFlag = FALSE;
    (void)NvM_CheckPerRamConfig(BlockId, &NvM_CurrentJobInfo.RamAddr);

    if(FALSE == NvM_Config[BlockId].EnFirstInitAll)
    {
        skipFlag = TRUE;
    }
#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
    else if(TRUE ==  NvM_Config[BlockId].EnWriteOnce)
    {
        skipFlag = TRUE;
    } 
#endif
    else
    {
        if(NvM_CurrentJobInfo.RamAddr == NVM_NULL)
        {
            NvM_CurrentJobInfo.RamAddr = &NvM_FirstInitAllTempBuff[0];
        }
        if((NvM_InitBlockCallBackFunPtr[BlockId] == NVM_NULL)&&(NvM_Config[BlockId].RomAddr == NVM_NULL))
        {
            NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_INVALID;
        }
        else
        {
#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)
            if(NVM_BLOCK_DATASET == NvM_Config[BlockId].BlockType)
            {
                /* dont consider dataindex here ,as dataindex is ensured in NvM_RestoreBlockDefaults*/
                NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_INVALID;
            }
            else
#endif
            {
                if(NvM_InitBlockCallBackFunPtr[BlockId] != NVM_NULL)
                {
                    NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_RESTORE_USER;
                }
                if(NvM_Config[BlockId].RomAddr != NVM_NULL)
                {
                    NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_RESTORE_ROMADDR;
                }
            }
        }
    }   
    return skipFlag;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_FirstInitAllJobProcess
*
* Description:  The function initiates a multi block first initialization request
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE) NvM_FirstInitAllJobProcess(void)
{
    NvM_BlockIdType tempBlockId;
    NvM_BlockIdType phyBlockId;
    boolean skipFlag = FALSE;
    Std_ReturnType Result;
    boolean loopFlag = TRUE;
    MemIf_JobResultType JobResult;
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
    uint8 LogicCoreId;
#endif

    /*PRQA S 2488,2481 ++*/
    /*
    Loop control variable in this 'while' statement, is not modified inside loop but has file scope.
    */
    /* search next init block */
    while(NVM_SUBSTATE_FIRSTINITALL == NvM_JobSubState)
    {
        if((NvM_BlockIdType)0 == NvM_CurrentJobInfo.BlockId)
        {
#if(STD_ON == NVM_DYNAMIC_CONFIGURATION)
            NvM_CurrentJobInfo.BlockId = NVM_USER_BLOCKID_START;
#else
            NvM_CurrentJobInfo.BlockId = NVM_WRITEALL_BLOCKID_START;
#endif
        }

        tempBlockId = NvM_CurrentJobInfo.BlockId;
#if(STD_ON == NVM_FIRST_INIT_ALL_SUPPORT)
        skipFlag = NvM_isSkipFirstInitAll(tempBlockId);
#else
        skipFlag = TRUE;
#endif
        if(TRUE == skipFlag)
        {
            NvM_SingleJobStop(tempBlockId, NVM_REQ_BLOCK_SKIPPED); /*NVM298*/
        }
    }
    /*PRQA S 2488,2481 --*/
    tempBlockId = NvM_CurrentJobInfo.BlockId;
    do
    {
        loopFlag = FALSE;
        switch(NvM_JobSubState)
        {
        case NVM_SUBSTATE_FIRSTINITALL_RESTORE_USER:
            /*NVM369 NvM_InitBlockCallBackFunPtr will always return E_OK
              In callback, user must fill crc and blockid, as nvm dont not know
              the ram block address. NVM266
            */
#if (STD_ON == NVM_MULTI_CORE_SUPPORT)
            if(CurrentCoreId != NvM_Config[tempBlockId].PhyCoreId)
            {
                LogicCoreId = NvM_Config[tempBlockId].LogicCoreId;
                Result = NvM_AgentCmdAsync(LogicCoreId, NVM_NO_SERVICE, NVM_AGENT_BACK_JOB_INIT_CALLBACK, tempBlockId, NULL_PTR, (NvM_RequestResultType)0, NVM_INIT_FIRST_INIT_ALL);
            }
            else
#endif
            {
                Result = NvM_InitBlockCallBackFunPtr[tempBlockId](NVM_INIT_FIRST_INIT_ALL);
            }


            if(NVM_USER_JOB_PENDING != Result)
            {
                loopFlag = TRUE;
                if(E_OK == Result)
                {
                    NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_RESTOREDATA_END;
                    NvM_TempNvErrStatus = NVM_REQ_RESTORED_DEFAULTS;
                }
                else
                {
                    NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                    NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_INVALID;
                }
            }
            /* else do nothing , wait for next main cycle */
            break;


        case NVM_SUBSTATE_FIRSTINITALL_RESTORE_ROMADDR:/*NVM267*/
            Result = NvM_CopyRomToRam(tempBlockId);
            if(NVM_USER_JOB_PENDING != Result)
            {
                loopFlag = TRUE;
                if(E_OK == Result)
                {
                    NvM_FisrtInitALL_Restore_DataReadEnd(tempBlockId);
                }
                else
                {
                    NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                    NvM_JobSubState = NVM_SUBSTATE_RESTOREDATA_END;
                }
            }
            break;

#if(STD_ON == NVM_CRC_ENABLE)/*NVM229*/
        case NVM_SUBSTATE_FIRSTINITALL_RESTORECRC:
            Result = NvM_CRC_Process(tempBlockId);
            if(E_OK == Result)
            {
                loopFlag = TRUE;
                NvM_WriteCrcResultToRam(tempBlockId);
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
                if(NVM_PROCESS_SYN_RAM_BLOCK == NvM_GetUsedRamBlockType(tempBlockId))
                {
                    NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_RESTOREDATA_SYN;
                }
                else
#endif
                {
                    NvM_TempNvErrStatus = NVM_REQ_RESTORED_DEFAULTS;
                    NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_RESTOREDATA_END;
                }
            }
            break;
#endif

#if(STD_ON == NVM_USE_SYNC_MECHANISM)
        case NVM_SUBSTATE_FIRSTINITALL_RESTOREDATA_SYN:
            /* syn mirror is used, set invalid just before the data copy NVM227*/
            if(NVM_PROCESS_SYN_RAM_BLOCK == NvM_GetUsedRamBlockType(tempBlockId))
            {
                NVM_SET_INVALID_UNCHANGED(tempBlockId);
            }
            NvM_TempNvErrStatus = NVM_REQ_RESTORED_DEFAULTS;
            loopFlag = NvM_CallReadRamCbkProcess(tempBlockId, NVM_SUBSTATE_FIRSTINITALL_RESTOREDATA_END, NVM_SUBSTATE_FIRSTINITALL_RESTOREDATA_END);
            break;
#endif

        case NVM_SUBSTATE_FIRSTINITALL_RESTOREDATA_END:

            if(NVM_REQ_RESTORED_DEFAULTS == NvM_TempNvErrStatus)
            {
                if(NvM_GetUsedRamBlockType(tempBlockId) >= NVM_PROCESS_PER_RAM_BLOCK)
                {
                    NVM_SET_VALID_CHANGED(tempBlockId);  /*NVM228*/
                    NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_WRITE_DATA;
                    loopFlag = TRUE;
                }
            }

            break;
        case NVM_SUBSTATE_FIRSTINITALL_WRITE_DATA:
            phyBlockId = NvM_GetPhyBlockId(tempBlockId);
            NvM_FillBlockId(tempBlockId);

            Result = MemIf_Write(NvM_Config[tempBlockId].DeviceId,
                                 phyBlockId,
                                 NvM_CurrentJobInfo.RamAddr);

            if(E_NOT_OK == Result)
            {
                NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_END;
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                loopFlag = TRUE;
            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_WRITE_WAIT;
            }

            break;

        case NVM_SUBSTATE_FIRSTINITALL_WRITE_WAIT:
#if(STD_ON == NVM_POLLING_MODE)
            JobResult = MemIf_GetJobResult(NvM_Config[tempBlockId].DeviceId);
            if(MEMIF_JOB_PENDING != JobResult)
            {
                loopFlag = TRUE;
                NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_WRITE_WAIT_IND;
            }
#endif
            break;

        case NVM_SUBSTATE_FIRSTINITALL_WRITE_WAIT_IND:
            JobResult = MemIf_GetJobResult(NvM_Config[tempBlockId].DeviceId);
            loopFlag = TRUE;

            if(MEMIF_JOB_OK == JobResult)
            {
                NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_WRITE_END;
                NvM_TempNvErrStatus = NVM_REQ_OK;

            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_WRITE_END;
                    /* only failed is possible when read*/
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
            }
            break;
        case NVM_SUBSTATE_FIRSTINITALL_WRITE_END:
#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
            if((NVM_BLOCK_REDUNDANT == NvM_Config[tempBlockId].BlockType)
                    && ((uint8)0 == NvM_AdmBlock[tempBlockId].NvDataIndex))
            {
                NvM_AdmBlock[tempBlockId].NvDataIndex = (uint8)1;
                NvM_savedNv0ResultType = NvM_TempNvErrStatus;
                NvM_TempNvErrStatus = NVM_REQ_OK;
                NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_WRITE_DATA;
                loopFlag = TRUE;
            }
            else
#endif
            {
#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
                if(NVM_BLOCK_REDUNDANT == NvM_Config[tempBlockId].BlockType)
                {
                    if((NVM_REQ_OK != NvM_TempNvErrStatus)
                            && (NVM_REQ_OK != NvM_savedNv0ResultType))
                    {

                        NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                    }
                    else
                    {
                        NvM_TempNvErrStatus = NVM_REQ_OK;
                    }
                }

#endif
                if(NVM_REQ_OK == NvM_TempNvErrStatus)
                {
                    if(NvM_GetUsedRamBlockType(tempBlockId) >= NVM_PROCESS_PER_RAM_BLOCK)
                    {
                        NVM_SET_VALID_UNCHANGED(tempBlockId);
                    }
                }
                NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_END;
                loopFlag = TRUE;
            }
            break;
        case NVM_SUBSTATE_FIRSTINITALL_INVALID:
            phyBlockId = NvM_GetPhyBlockId(tempBlockId);
            Result = MemIf_InvalidateBlock(NvM_Config[tempBlockId].DeviceId,
                                           phyBlockId);
            if(E_NOT_OK == Result)
            {
                NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_INVALID_END;
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
                loopFlag = TRUE;
            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_INVALID_WAIT;
            }

            break;

        case NVM_SUBSTATE_FIRSTINITALL_INVALID_WAIT:
#if(STD_ON == NVM_POLLING_MODE)
            JobResult = MemIf_GetJobResult(NvM_Config[tempBlockId].DeviceId);
            if(MEMIF_JOB_PENDING != JobResult)
            {
                loopFlag = TRUE;
                NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_INVALID_WAIT_IND;
            }
#endif
            break;

        case NVM_SUBSTATE_FIRSTINITALL_INVALID_WAIT_IND:
            JobResult = MemIf_GetJobResult(NvM_Config[tempBlockId].DeviceId);
            loopFlag = TRUE;
            if(MEMIF_JOB_OK == JobResult)
            {
#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
                if((NVM_BLOCK_REDUNDANT == NvM_Config[tempBlockId].BlockType)
                        && ((uint8)0 == NvM_AdmBlock[tempBlockId].NvDataIndex))
                {
                    NvM_AdmBlock[tempBlockId].NvDataIndex = (uint8)1;
                    NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_INVALID;
                }
                else
#endif
#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)
                if((NVM_BLOCK_DATASET == NvM_Config[tempBlockId].BlockType)
                        && (NvM_AdmBlock[tempBlockId].NvDataIndex< NvM_Config[tempBlockId].NvBlockNum))
                {
                    NvM_AdmBlock[tempBlockId].NvDataIndex++;
                    NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_INVALID;
                }
                else
#endif
                {
                    NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_INVALID_END;
                    NvM_TempNvErrStatus = NVM_REQ_OK;
                }
            }
            else
            {
                NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_INVALID_END;
                NvM_TempNvErrStatus = NVM_REQ_NOT_OK;
            }

            break;

        case NVM_SUBSTATE_FIRSTINITALL_INVALID_END:
            if(NVM_REQ_OK == NvM_TempNvErrStatus)
            {
                NVM_SET_INVALID_UNCHANGED(tempBlockId);
            }
            NvM_JobSubState = NVM_SUBSTATE_FIRSTINITALL_END;
            loopFlag = TRUE;
            break;
        case NVM_SUBSTATE_FIRSTINITALL_END:
            NvM_SingleJobStop(tempBlockId, NvM_TempNvErrStatus);
            break;
        default:
            /* Unexpected case, report error, reset job to make other job running possible*/
            NvM_ResetJobState();
            NVM_DET_REPORT_ERROR(NVM_INTERNAL_FIRSTINITALLPROC_APIID, NVM_E_UNEXPECTED_CASE);
            break;

        }
    }while(TRUE == loopFlag);
}
#endif


#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
