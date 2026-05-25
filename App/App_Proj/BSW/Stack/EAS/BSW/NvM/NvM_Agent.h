/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : NvM_Agent.h
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
*   Reference to NvM_Agent File
********************************************************************************
* END_FILE_HDR*/

/*PRQA S 3429,3453 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no need to revise
*/

#ifndef NvM_AGENT_H
#define NvM_AGENT_H

/*******************************************************************************
*   include
*******************************************************************************/

/*******************************************************************************
    Type Definition
*******************************************************************************/

/*******************************************************************************
*   NvM Internal Data define
*******************************************************************************/

/*******************************************************************************
*   Marco
*******************************************************************************/
#define NVM_AGENT_JOB_BLOCK_ID(Index)                       (NvM_AgentJobInfo[Index].BlockId)
#define NVM_AGENT_JOB_SERVICE_FLAG_PTR(Index)               (NvM_AgentJobInfo[Index].ServiceFlagPtr)

#if(NVM_AGENT_BACK_JOB_MAX_NUM > 0)
#define NVM_AGENT_BACK_JOB_BLOCK_ID(BakIndex)               (NvM_AgentBackJobInfo[BakIndex].BlockId)
#define NVM_AGENT_BACK_JOB_SERVICE_FLAG_PTR(BakIndex)       (NvM_AgentBackJobInfo[BakIndex].BackServiceFlagPtr)
#define NVM_AGENT_BACK_JOB_RESULT_PTR(BakIndex)             (NvM_AgentBackJobInfo[BakIndex].BackResultPtr)
#endif

#define NVM_AGENT_BACK_JOB_NONE                             ((uint8)0)
#define NVM_AGENT_BACK_JOB_MIRROR_WRITE_CALLBACK            ((uint8)1)
#define NVM_AGENT_BACK_JOB_MIRROR_READ_CALLBACK             ((uint8)2)
#define NVM_AGENT_BACK_JOB_INIT_CALLBACK                    ((uint8)3)

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"
/*******************************************************************************
*   Function declare
*******************************************************************************/
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
extern FUNC(void, NVM_CODE)  NvM_AgentInit
(
    void
);
extern FUNC(void, NVM_CODE)  NvM_AgentCallBackMainfunction
(
    uint8 CurrentCoreId
);
extern FUNC(void, NVM_CODE)  NvM_AgentMasterMainfunction
(
    void
);
extern FUNC(Std_ReturnType, NVM_CODE)  NvM_AgentCmdAsync
(
    uint8 LogicCore,
    uint8 ServiceId,
    uint8 Cmd,
    NvM_BlockIdType BlockId,
    P2VAR(uint8, TYPEDEF, TYPEDEF) RamAddr,
    NvM_RequestResultType Result,
    NvM_InitBlockRequestType InitReq
);
#endif

#endif /*#ifndef NvM_AGENT_H*/

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
