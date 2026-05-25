/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : NvM_Agent.c
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
*   Revision History
*   Reference to NvM_Agent.c File
********************************************************************************
* END_FILE_HDR*/

/*****************************************************************************
 *  General QAC Suppression
*****************************************************************************/
/*PRQA S 5087,3614,3214,862,857 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "EcuM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in EcuM_MemMap.h.
Macro definitions exceed 1024.The number of macros is unlimited.
*/

/*PRQA S 2100,2101,2000 EOF*/
/*
Integer promotion related
*/

/*PRQA S 3212,3227,3204 EOF*/
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

/*PRQA S 3416,3432 EOF*/
/*
In a If statement,calling a function to directly determine the return value is allowed if there is only one judge branch.
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no need to revise.
*/

/*PRQA S 3383,3206 EOF*/
/*
Addition and subtraction operations on internal variables of dcm doesn't overflow.
*/

/*******************************************************************************
    Include Files
*******************************************************************************/
#include "NvM.h"
#include "NvM_Agent.h"

/*******************************************************************
* PRQA S 506
* Dereferencing pointer value that is possibly NULL.
* PRQA S 3869
* Indexing array with value that will apparently be out of bounds.
* MISRA-C:2004 Rule 21.1;
* All functions in this file is called by NvM's API, All the parameters will
* be checked in NVM API, no need to check again.
* This part of code is verified manually and has no impact.
*******************************************************************/

/*******************************************************************************
    Variable  Definition
*******************************************************************************/
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)

/*******************************************************************************
*   Macro Definition
*******************************************************************************/
#define NVM_AGENT_BACK_BLOCK_ID(CoreId)                 (NvM_AgentBackBuf[CoreId].BlockId)
#define NVM_AGENT_BACK_SERVICE_ID(CoreId)               (NvM_AgentBackBuf[CoreId].ServiceId)
#define NVM_AGENT_BACK_CMD(CoreId)                      (NvM_AgentBackBuf[CoreId].AgentCmd)
#define NVM_AGENT_BACK_RESULT(CoreId)                   (NvM_AgentBackBuf[CoreId].Result)
#define NVM_AGENT_BACK_INIT_REQ(CoreId)                 (NvM_AgentBackBuf[CoreId].InitReq)
#define NVM_AGENT_BACK_RAM_ADDR(CoreId)                 (NvM_AgentBackBuf[CoreId].RamAddr)
#define NVM_AGENT_BACK_CMD_STATE(CoreId)                (NvM_AgentBackBuf[CoreId].CmdRunState)
#define NVM_AGENT_BACK_CMD_RESULT(CoreId)               (NvM_AgentBackBuf[CoreId].CmdResult)

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/*******************************************************************************
*   Internal Function  Definition
*******************************************************************************/
#if(NVM_AGENT_BACK_JOB_MAX_NUM > 0)
STATIC FUNC(void, NVM_CODE)  NvM_AgentCallBackJobProcess
(
    void
);
#endif

#if(NVM_AGENT_BACK_JOB_MAX_NUM > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_AgentCallBackJobProcess
*
* Description: Single call back job process
*
* Inputs:      None
*
* Outputs:     None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, NVM_CODE)  NvM_AgentCallBackJobProcess
(
    void
)
{
    NvM_BlockIdType BlockId;
    NvM_BlockIdType AgentBackJobIndex;
    uint8 tempBackServiceFlag;
    NvM_RequestResultType tempBackResult;
    NvM_BlockRequestType BlockRequest = (NvM_BlockRequestType)0xFF;

    for(AgentBackJobIndex = (NvM_BlockIdType)0; AgentBackJobIndex < (NvM_BlockIdType)NVM_AGENT_BACK_JOB_MAX_NUM; AgentBackJobIndex++)
    {
        tempBackServiceFlag = *NVM_AGENT_BACK_JOB_SERVICE_FLAG_PTR(AgentBackJobIndex);
        *NVM_AGENT_BACK_JOB_SERVICE_FLAG_PTR(AgentBackJobIndex) = NVM_NO_SERVICE;
        if(NVM_NO_SERVICE != tempBackServiceFlag)
        {
            BlockId = NVM_AGENT_BACK_JOB_BLOCK_ID(AgentBackJobIndex);
            tempBackResult = *NVM_AGENT_BACK_JOB_RESULT_PTR(AgentBackJobIndex);
            if(NULL_PTR != NvM_SingleCallBackFunPtr[BlockId])
            {
                BlockRequest = NvM_ServiceIdMapBlockRequest(tempBackServiceFlag);
                (void)NvM_SingleCallBackFunPtr[BlockId](BlockRequest, tempBackResult);
            }
        }
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_AgentInit
*
* Description: Agent parameter init
*
* Inputs:      None
*
* Outputs:     None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE)  NvM_AgentInit
(
    void
)
{
    uint8 CoreId;
    NvM_BlockIdType AgentJobIndex;
#if(NVM_AGENT_BACK_JOB_MAX_NUM > 0)
    NvM_BlockIdType AgentBackJobIndex;
#endif

    for(CoreId = (uint8)0; CoreId < NVM_LOGIC_CORE_NUM; CoreId++)
    {
        NVM_AGENT_BACK_BLOCK_ID(CoreId) = NVM_INVALID_BLOCKID;
        NVM_AGENT_BACK_SERVICE_ID(CoreId) = (uint8)0;
        NVM_AGENT_BACK_CMD(CoreId) = NVM_AGENT_BACK_JOB_NONE;
        NVM_AGENT_BACK_RESULT(CoreId) = NVM_REQ_OK;
        NVM_AGENT_BACK_INIT_REQ(CoreId) = (NvM_InitBlockRequestType)0;
        NVM_AGENT_BACK_RAM_ADDR(CoreId) = NULL_PTR;
        NVM_AGENT_BACK_CMD_STATE(CoreId) = NVM_AGENT_JOB_IDLE;
        NVM_AGENT_BACK_CMD_RESULT(CoreId) = E_NOT_OK;
    }
    for(AgentJobIndex = (NvM_BlockIdType)0; AgentJobIndex < NVM_AGENT_JOB_MAX_NUM; AgentJobIndex++)
    {
        *NVM_AGENT_JOB_SERVICE_FLAG_PTR(AgentJobIndex) = NVM_NO_SERVICE;
    }
#if(NVM_AGENT_BACK_JOB_MAX_NUM > 0)
    for(AgentBackJobIndex = (NvM_BlockIdType)0; AgentBackJobIndex < (NvM_BlockIdType)NVM_AGENT_BACK_JOB_MAX_NUM; AgentBackJobIndex++)
    {
        *NVM_AGENT_BACK_JOB_SERVICE_FLAG_PTR(AgentBackJobIndex) = NVM_NO_SERVICE;
        *NVM_AGENT_BACK_JOB_RESULT_PTR(AgentBackJobIndex) = NVM_REQ_OK;
    }
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_AgentMasterMainfunction
*
* Description: Agent job main function
*
* Inputs:      None
*
* Outputs:     None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE)  NvM_AgentMasterMainfunction
(
    void
)
{
    NvM_BlockIdType AgentJobIndex;
    NvM_BlockIdType BlockId;
    uint8 tempServiceFlag = NVM_NO_SERVICE;

    for(AgentJobIndex = (NvM_BlockIdType)0; AgentJobIndex < NVM_AGENT_JOB_MAX_NUM; AgentJobIndex++)
    {
        tempServiceFlag = *NVM_AGENT_JOB_SERVICE_FLAG_PTR(AgentJobIndex);
        if(NVM_NO_SERVICE != tempServiceFlag)
        {
            BlockId = NVM_AGENT_JOB_BLOCK_ID(AgentJobIndex);
            switch(tempServiceFlag)
            {
            case NVM_WRITE_BLOCK_APIID:
                NvM_WriteBlockAgent(BlockId, NULL_PTR);
            break;
            case NVM_READ_BLOCK_APIID:
                NvM_ReadBlockAgent(BlockId, NULL_PTR);
            break;
            case NVM_RESTORE_BLOCK_DEFAULTS_APIID:
                NvM_RestoreBlockDefaultsAgent(BlockId, NULL_PTR);
            break;
            case NVM_WRITE_PRAMBLOCK:
                NvM_WritePRAMBlockAgent(BlockId);
            break;
            case NVM_READ_PRAMBLOCK:
                NvM_ReadPRAMBlockAgent(BlockId);
            break;
            case NVM_RESTORE_PRAMBLOCK:
                NvM_RestorePRAMBlockDefaultsAgent(BlockId);
            break;
#if(STD_ON == NVM_ERASE_API)
            case NVM_ERASE_BLOCK:
                NvM_EraseNvBlockAgent(BlockId);
            break;
#endif
#if(STD_ON == NVM_INVALID_NVBLOCK_API)
            case NVM_INVALIDATE_NV_BLOCK_APIID:
                NvM_InvalidateNvBlockAgent(BlockId);
            break;
#endif
            default:
            break;
            }
            /* Ensure that the agent core request can receive busy result */
            *NVM_AGENT_JOB_SERVICE_FLAG_PTR(AgentJobIndex) = NVM_NO_SERVICE;
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_AgentCmdAsync
*
* Description: Add async command
*
* Inputs:      LogicCore
*              Cmd
*              BlockId
*              RamAddr
*              Result
*              InitReq
*
* Outputs:     tempCmdState
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE)  NvM_AgentCmdAsync
(
    uint8 LogicCore,
    uint8 ServiceId,
    uint8 Cmd,
    NvM_BlockIdType BlockId,
    P2VAR(uint8, TYPEDEF, TYPEDEF) RamAddr,
    NvM_RequestResultType Result,
    NvM_InitBlockRequestType InitReq
)
{
    Std_ReturnType tempCmdState = NVM_USER_JOB_PENDING;
    if(NVM_AGENT_JOB_IDLE == NVM_AGENT_BACK_CMD_STATE(LogicCore))
    {
        NVM_AGENT_BACK_CMD(LogicCore) = Cmd;
        NVM_AGENT_BACK_SERVICE_ID(LogicCore) = ServiceId;
        NVM_AGENT_BACK_BLOCK_ID(LogicCore) = BlockId;
        NVM_AGENT_BACK_RAM_ADDR(LogicCore) = RamAddr;
        NVM_AGENT_BACK_INIT_REQ(LogicCore) = InitReq;
        NVM_AGENT_BACK_RESULT(LogicCore) = Result;
        NVM_AGENT_BACK_CMD_STATE(LogicCore) = NVM_USER_JOB_PENDING;
    }
    else if(NVM_AGENT_JOB_DONE == NVM_AGENT_BACK_CMD_STATE(LogicCore))
    {
        tempCmdState = NVM_AGENT_BACK_CMD_RESULT(LogicCore);
        NVM_AGENT_BACK_CMD_STATE(LogicCore) = NVM_AGENT_JOB_IDLE;
    }
    else
    {
        /*NVM_AGENT_BACK_CMD_STATE is NVM_USER_JOB_PENDING*/
    }

    return tempCmdState;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_AgentCallBackMainfunction
*
* Description: Agent call back job main function
*
* Inputs:      CurrentCoreId
*
* Outputs:     None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE)  NvM_AgentCallBackMainfunction
(
    uint8 CurrentCoreId
)
{
    uint8 tempCmdResult = E_NOT_OK;
    P2VAR(NvM_AgentBackBufType, AUTOMATIC, NVM_VAR) tempAgentBackBufPtr = NULL_PTR;
    NvM_BlockIdType BlockId;
    uint8 LogicCore = NvMCfgCorePhyMapLogic[CurrentCoreId];

    if(NVM_USER_JOB_PENDING == NVM_AGENT_BACK_CMD_STATE(LogicCore))
    {
        tempAgentBackBufPtr = &(NvM_AgentBackBuf[LogicCore]);
        BlockId = tempAgentBackBufPtr->BlockId;
        switch(tempAgentBackBufPtr->AgentCmd)
        {
        case NVM_AGENT_BACK_JOB_MIRROR_WRITE_CALLBACK:
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
            if(NULL_PTR != NvM_WriteRamBlockToNvmFunPtr[BlockId])
            {
                tempCmdResult = NvM_WriteRamBlockToNvmFunPtr[BlockId](tempAgentBackBufPtr->RamAddr);
            }
#endif
        break;

        case NVM_AGENT_BACK_JOB_MIRROR_READ_CALLBACK:
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
            if(NULL_PTR != NvM_ReadRamBlockFromNvmFunPtr[BlockId])
            {
                tempCmdResult = NvM_ReadRamBlockFromNvmFunPtr[BlockId](tempAgentBackBufPtr->RamAddr);
            }
#endif
        break;
        case NVM_AGENT_BACK_JOB_INIT_CALLBACK:
            if(NULL_PTR != NvM_InitBlockCallBackFunPtr[BlockId])
            {
                tempCmdResult = NvM_InitBlockCallBackFunPtr[BlockId](tempAgentBackBufPtr->InitReq);
            }
        break;

        default:
            /*do nothing */
        break;
        }
        NVM_AGENT_BACK_CMD_RESULT(LogicCore) = tempCmdResult;
        if(NVM_USER_JOB_PENDING != tempCmdResult)
        {
            NVM_AGENT_BACK_CMD(LogicCore) = NVM_AGENT_BACK_JOB_NONE;
            NVM_AGENT_BACK_CMD_STATE(LogicCore) = NVM_AGENT_JOB_DONE;
        }
    }

#if(NVM_AGENT_BACK_JOB_MAX_NUM > 0)
    NvM_AgentCallBackJobProcess();
#endif
}

#endif/*#if(STD_ON == NVM_MULTI_CORE_SUPPORT)*/

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"


