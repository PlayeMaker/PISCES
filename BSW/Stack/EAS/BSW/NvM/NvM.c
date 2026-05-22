/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : NvM.c
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : NvM module Source File
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
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   04.00.00    06/25/2022    Zhuoran.Lu    N/A          Original
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
/*******************************************************************************
*   Include
*******************************************************************************/
#include "NvM.h"
#include "NvM_Cbk.h"
#if(NVM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"/*NVM556*/
#endif
#if(STD_ON == NVM_BSWM_SUPPORT)
#include "BswM_NvM.h"
#endif
#if(STD_ON == NVM_DEM_SUPPORT)
#include "Dem.h"
#endif
#if(STD_ON == NVM_CIPHER_ENABLE)
#include "NvM_JobProc.h"
#endif
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
#include "NvM_Agent.h"
#endif
/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(STD_ON == NVM_VERSION_CHECK)
/* check Version with other import module */


/* check Version with cfg file */
#if (NVM_AR_RELEASE_MAJOR_VERSION != NVM_AR_RELEASE_MAJOR_VERSION_CFG) 
#error "AutoSar Version Numbers of Nvm and its cfg file are different"
#endif

#if (NVM_AR_RELEASE_MINOR_VERSION != NVM_AR_RELEASE_MINOR_VERSION_CFG)

#error "AutoSar Version Numbers of Nvm and its cfg file are different"
#endif

#if ((NVM_SW_MAJOR_VERSION != NVM_SW_MAJOR_VERSION_CFG) || \
   (NVM_SW_MINOR_VERSION != NVM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of Nvm  and its cfg file are different"
#endif

#endif

/*******************************************************************************
*   Macro
*******************************************************************************/

#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

/*******************************************************************************
*   Internal Function  Definition
*******************************************************************************/

STATIC FUNC(uint8, NVM_CODE)  NvM_CheckPar
(
    const NvM_BlockIdType BlockId
);
STATIC FUNC(uint8, NVM_CODE)  NvM_CheckPending
(
    const NvM_BlockIdType BlockId,
    const boolean isWriteJob
);
STATIC FUNC(uint8, NVM_CODE) NvM_WriteBlockCheck
(
    NvM_BlockIdType BlockId,
    CONSTP2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_SrcPtr
);
STATIC FUNC(uint8, NVM_CODE) NvM_ReadBlockCheck
(
    NvM_BlockIdType BlockId,
    CONSTP2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr
);
STATIC FUNC(uint8, NVM_CODE) NvM_RestoreBlockCheck
(
    NvM_BlockIdType BlockId,
    CONSTP2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_DestPtr
);

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_CheckPar
*
* Description: Common check input parameters
*
* Inputs:      BlockId: Block ID
*
* Outputs:     None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, NVM_CODE)  NvM_CheckPar
(
    const NvM_BlockIdType BlockId
)
{
    uint8 ret;

    /* Check if NvM was initialized. */
    if(NvM_TaskState == NVM_STATE_UNINIT)
    {
        ret = NVM_E_UNINIT;

    }
    /* Check BlockId out of range. */
    else if((BlockId >= NVM_TOTAL_NUM_OF_NVRAM_BLOCKS)
            || (BlockId < NVM_USER_BLOCKID_START))
    {
        ret = NVM_E_PARAM_BLOCK_ID;

    }
#if(STD_OFF == NVM_DYNAMIC_CONFIGURATION)
    /* block 1 is invalid  when dynconfig is off*/
    else if(BlockId == NVM_USER_BLOCKID_START)/* NVM311*/
    {
        ret = NVM_E_PARAM_BLOCK_ID;

    }
#endif
    else
    {
        ret = NVM_E_NO_ERROR;
    }

    return ret;


}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_Check_WriteOnce_ReadFirst
*
* Description: Common check the job of the function when the processing of a block 
* configured with  NVM_WRITE_BLOCK_ONCE (TRUE) for which no read request was made prior 
* to this.
*
* Inputs:      BlockId: Block ID
*
* Outputs:     None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
STATIC FUNC(uint8, NVM_CODE)  NvM_Check_WriteOnce_ReadFirst
(
    const NvM_BlockIdType BlockId
)
{
    uint8 ret;

    /* Check if NvM was initialized. */
    if(TRUE == NvM_Config[BlockId].EnWriteOnce)
    {
        if(NVM_WRITEONCE_READFIRST_BIT(BlockId) == FALSE)
        {
            ret = NVM_E_WRITE_ONCE_STATUS_UNKNOWN;
        }
        else
        {
            ret = NVM_E_NO_ERROR;
        }
    }
    else
    {
        ret = NVM_E_NO_ERROR;
    }

    return ret;


}
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_CheckPar
*
* Description: Common check input parameters
*
* Inputs:      BlockId: Block ID
*
* Outputs:     None
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, NVM_CODE)  NvM_CheckPending
(
    const NvM_BlockIdType BlockId,
    const boolean isWriteJob
)
{
    uint8 ret = NVM_E_NO_ERROR;


    if((NvM_CurrentJobInfo.BlockId == BlockId)
            && (NvM_CurrentJobInfo.ServiceId != NVM_JOB_READALL)
            && (NvM_CurrentJobInfo.ServiceId != NVM_JOB_WRITEALL)
            && (NvM_CurrentJobInfo.ServiceId != NVM_JOB_VALIDATEALL))
    {
        ret = NVM_E_BLOCK_PENDING;
#if(STD_ON == NVM_IMM_BLOCK_SUPPORT)
        if((TRUE == isWriteJob)
                && ((uint8)0 == NvM_Config[BlockId].BlockPri)
                && (NvM_CurrentJobInfo.ServiceId != NVM_JOB_WRITE)
                && (NvM_CurrentJobInfo.ServiceId != NVM_JOB_WRITE_PRAMBLOCK))
        {
            ret = NVM_E_NO_ERROR;
        }
#endif
    }
    else if(TRUE == NvM_CheckBlockPending(BlockId, isWriteJob))
    {
        ret = NVM_E_BLOCK_PENDING;
    }
    else
    {
        ret = NVM_E_NO_ERROR;
    }


    return ret;
}


/*******************************************************************************
*   Public Function  Definition
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_Init  NVM447
*
* Description:  This function uses to switch the mode of  Memory Abstraction
                Modules.
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE) NvM_Init
(
    P2CONST(NvM_ConfigType, AUTOMATIC, NVM_CONST) ConfigPtr
)
{
    NvM_BlockIdType BlockID;
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();

    if(CurrentCoreId != NVM_MASTER_CORE_ID)
    {
        NVM_DET_REPORT_ERROR(NVM_INIT, NVM_E_CORE_LIMIT);
    }
    else
#endif
    {
        /*PRQA S 3119 ++*/
        /*
        The functions that are specified in the specification are not used in the precompile mode.
        */
        (void)ConfigPtr;/*NVM881*/
        /*PRQA S 3119 --*/

        /*NVM399 NVM400 NVM193*/
        for(BlockID = (NvM_BlockIdType)0; BlockID < NVM_TOTAL_NUM_OF_NVRAM_BLOCKS; BlockID++)
        {
            NvM_AdmBlock[BlockID].NvErrStatus = NVM_REQ_OK;
            NvM_AdmBlock[BlockID].multiNvErrStatus = NVM_REQ_OK;

#if((STD_ON == NVM_DATASET_BLOCK_SUPPORT)||(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT))
            /*NVM192 init dataset to 0
            */
            NvM_AdmBlock[BlockID].NvDataIndex = (uint8)0;
#endif

            NvM_AdmBlock[BlockID].NvRamAttributes.AttriByte = (uint8)0;/* contain invalid unchange unlock unlossR */

#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
            NVM_PROTECTED_BIT(BlockID) = NvM_Config[BlockID].InitWriteProt;
            NVM_WRITEONCE_READFIRST_BIT(BlockID) = FALSE;
#endif


        }
        NvM_CfgIdMatch = FALSE;
        NvM_CancelWriteAllFlag = FALSE;
        NvM_ClearJob();

        /* put this state at last line of this function to make sure that 
        other core can only start job after master core init */
        NvM_ResetJobState();
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
        NvM_AgentInit();
#endif
    }

}

#if ((NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)\
||(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2))
#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_SetDataIndex NVM448
*
* Description:  This function uses to Setting the DataIndex of a dataset
*               NVRAM block.
*
* Inputs:       BlockId: Block ID
*               DataIndex:Data Index
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_SetDataIndex
(
    NvM_BlockIdType BlockId,
    uint8 DataIndex
)
{

    Std_ReturnType ret;
    uint8 detErrCode;

    /*NVM264 NVM707 NVM598 NVM601*/
    detErrCode = NvM_CheckPar(BlockId);
    if(detErrCode == NVM_E_NO_ERROR)
    {
        /* Check for block management type DATASET. NVM600 */
        if(NVM_BLOCK_DATASET != NvM_Config[BlockId].BlockType)
        {
            detErrCode = NVM_E_PARAM_BLOCK_TYPE;
        }
        else if(DataIndex >= (NvM_Config[BlockId].NvBlockNum + NvM_Config[BlockId].RomBlockNum))
        {
            detErrCode = NVM_E_PARAM_BLOCK_DATA_IDX;/*NVM599*/
        }
        else if(NVM_REQ_PENDING == NvM_AdmBlock[BlockId].NvErrStatus)
        {
            detErrCode = NVM_E_BLOCK_PENDING;
        }
        else
        {
            detErrCode = NVM_E_NO_ERROR;
        }
    }

    if(detErrCode != NVM_E_NO_ERROR)
    {
        NVM_DET_REPORT_ERROR(NVM_SET_DATA_INDEX, detErrCode);
        ret = E_NOT_OK;
    }
    else
    {

        NvM_AdmBlock[BlockId].NvDataIndex = DataIndex;/*NVM014 NVM263*/
        ret = E_OK;
    }

    return  ret;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_GetDataIndex NVM449
*
* Description:  Getting the currently set DataIndex of a dataset NVRAM block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      DataIndexPtr:DataIndex Pointer
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_GetDataIndex
(
    NvM_BlockIdType BlockId,
    P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) DataIndexPtr
)
{

    Std_ReturnType ret;

    uint8 detErrCode;

    /*NVM708 NVM602 NVM604*/
    detErrCode = NvM_CheckPar(BlockId);
    if(detErrCode == NVM_E_NO_ERROR)
    {
        /* Check for NULL pointer. */
        if(DataIndexPtr == NVM_NULL)
        {

            detErrCode = NVM_E_PARAM_DATA;/*NVM605 not pointer*/
        }
        /* Check for block management type DATASET. NVM603*/
        else if(NVM_BLOCK_DATASET != NvM_Config[BlockId].BlockType)
        {
            detErrCode = NVM_E_PARAM_BLOCK_TYPE;
            *DataIndexPtr = (uint8)0;/*NVM265*/
        }
        else
        {
            detErrCode = NVM_E_NO_ERROR;
        }
    }

    if(detErrCode != NVM_E_NO_ERROR)
    {
        NVM_DET_REPORT_ERROR(NVM_GET_DATA_INDEX, detErrCode);
        ret = E_NOT_OK;
    }
    else
    {
        *DataIndexPtr = NvM_AdmBlock[BlockId].NvDataIndex ;/*NVM021*/

        ret = E_OK;
    }

    return  ret;

}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ReadBlockCheck
*
* Description:  check read job valid or not
*
* Inputs:       BlockId, NvM_SrcPtr
*
* Outputs:      uint8
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, NVM_CODE) NvM_ReadBlockCheck
(
    NvM_BlockIdType BlockId,
    CONSTP2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr
)
{
    uint8 detErrCode = NVM_E_NO_ERROR;

    /* Check for RAM block NULL pointer. NVM196 NVM616*/
    if((NvM_DstPtr == NVM_NULL)
            && (NvM_Config[BlockId].RamAddr == NVM_NULL))
    {

#if(STD_ON == NVM_USE_SYNC_MECHANISM)
        if(FALSE == NvM_Config[BlockId].EnUseSynM)
        {
            detErrCode = NVM_E_PARAM_ADDRESS;
        }
        else
        {
            if(NULL_PTR == NvM_ReadRamBlockFromNvmFunPtr[BlockId])
            {
                detErrCode = NVM_E_BLOCK_CONFIG;
            }
        }

#else
        detErrCode = NVM_E_PARAM_ADDRESS;
#endif

    }
#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)
    else if(NVM_BLOCK_DATASET == NvM_Config[BlockId].BlockType)
    {
        /* rom block can also be read */
        if(NvM_AdmBlock[BlockId].NvDataIndex >=
                (NvM_Config[BlockId].NvBlockNum + NvM_Config[BlockId].RomBlockNum))/*NVM355*/
        {
            detErrCode = NVM_E_PARAM_BLOCK_DATA_IDX;
        }
    }
#endif
    else
    {
        detErrCode = NVM_E_NO_ERROR;
    }
    return detErrCode;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ReadBlock NVM454
*
* Description:  Copy the data of the NV block to its corresponding RAM block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      NvM_DstPtr:Pointer to RAM data block
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_ReadBlock
(
    NvM_BlockIdType BlockId,
    P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr
)
{
    Std_ReturnType ret;
    uint8 detErrCode;
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
    P2VAR(uint8, AUTOMATIC, NVM_VAR) tempServiceFlagPtr = NULL_PTR;
#endif

    /*NVM712 NVM614 NVM615 NVM618*/
    detErrCode = NvM_CheckPar(BlockId);
    if(detErrCode == NVM_E_NO_ERROR)
    {
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
        if(CurrentCoreId == NvM_Config[BlockId].PhyCoreId)
        {
            if(CurrentCoreId != NVM_MASTER_CORE_ID)
            {
                if((NvM_DstPtr == NVM_NULL) && (NvM_Config[BlockId].RamAddr != NVM_NULL))
                {
                    if(NVM_INVALID_AGENT_JOB_INDEX != NvM_Config[BlockId].AgentJobIndex)
                    {
                        tempServiceFlagPtr = NVM_AGENT_JOB_SERVICE_FLAG_PTR(NvM_Config[BlockId].AgentJobIndex);
                        if(NVM_NO_SERVICE == *tempServiceFlagPtr)
                        {
                            *tempServiceFlagPtr = NVM_READ_BLOCK_APIID;
                            ret = E_OK;
                        }
                        else
                        {
                            ret = NVM_E_BLOCK_PENDING;
                        }
                    }
                    else
                    {
                        ret = E_NOT_OK;
                    }
                }
                else
                {
                    detErrCode = NVM_E_CORE_LIMIT;
                }
            }
            else
            {
                ret = NvM_ReadBlockAgent(BlockId, NvM_DstPtr);
            }
        }
        else
        {
            detErrCode = NVM_E_CORE_LIMIT;
        }
#else
        ret = NvM_ReadBlockAgent(BlockId, NvM_DstPtr);
#endif
    }
    if(NVM_E_NO_ERROR != detErrCode)
    {
        NVM_DET_REPORT_ERROR(NVM_READ_BLOCK_APIID, detErrCode);
    }
    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ReadBlockAgent NVM454
*
* Description:  Copy the data of the NV block to its corresponding RAM block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      NvM_DstPtr:Pointer to RAM data block
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_ReadBlockAgent
(
    NvM_BlockIdType BlockId,
    P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr
)
{
    Std_ReturnType ret;
    uint8 detErrCode;
    P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA)  saveRamAddr;

    detErrCode = NvM_ReadBlockCheck(BlockId, NvM_DstPtr);
    /* check pending must be protected, as the queue may be interrupt by other request */
    SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
    if(detErrCode == NVM_E_NO_ERROR)
    {
        detErrCode = NvM_CheckPending(BlockId, FALSE);
    }

    if(detErrCode == NVM_E_NO_ERROR)
    {
        if(NVM_NULL != NvM_DstPtr)
        {
            /*PRQA S 317 ++*/
            /*
            Specific implementation methods.
           */
            /*Temporary RAM address first NVM278*/
            saveRamAddr = (uint8*)NvM_DstPtr;
            /*PRQA S 317 --*/
        }
        else
        {
            /* return value is check before*/
            (void)NvM_CheckPerRamConfig(BlockId, &saveRamAddr);
        }

        ret = NvM_QueueJob(BlockId, NVM_JOB_READ, saveRamAddr);/*NVM195*/
        if (E_OK == ret)
        {
            NvM_AdmBlock[BlockId].NvErrStatus = NVM_REQ_PENDING;
        }
        else
        {
            detErrCode = NVM_E_QUEUE_FULL;
        }
    }
    SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();


    if(NVM_E_NO_ERROR != detErrCode)
    {
        ret = E_NOT_OK;
#if(STD_ON == NVM_DEM_SUPPORT)
        if(NVM_E_QUEUE_FULL == detErrCode)
        {
            NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_FAILED);
        }
        else
#endif
        {
            NVM_DET_REPORT_ERROR(NVM_READ_BLOCK_APIID, detErrCode);
        }
    }
    else
    {
        ret = E_OK;
        NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_PASSED);
    }

    return ret;
}



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_WriteBlockCheck
*
* Description:  check write job valid or not
*
* Inputs:       BlockId, NvM_SrcPtr
*
* Outputs:      uint8
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, NVM_CODE) NvM_WriteBlockCheck
(
    NvM_BlockIdType BlockId,
    CONSTP2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_SrcPtr
)
{

    uint8 detErrCode  = NVM_E_NO_ERROR;

    /* Check for RAM block NULL pointer. NVM210 NVM280 NVM622 NVM624*/
    if((NvM_SrcPtr == NVM_NULL)
            && (NvM_Config[BlockId].RamAddr == NVM_NULL))
    {
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
        if(FALSE == NvM_Config[BlockId].EnUseSynM)
        {
            detErrCode = NVM_E_PARAM_ADDRESS;
        }
        else
        {
            if(NULL_PTR == NvM_WriteRamBlockToNvmFunPtr[BlockId])
            {
                detErrCode = NVM_E_BLOCK_CONFIG;
            }
        }
#else
        detErrCode = NVM_E_PARAM_ADDRESS;
#endif

    }
#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)
    if(detErrCode == NVM_E_NO_ERROR)
    {
        if(NVM_BLOCK_DATASET == NvM_Config[BlockId].BlockType)
        {
            if(NvM_AdmBlock[BlockId].NvDataIndex >= (NvM_Config[BlockId].NvBlockNum + NvM_Config[BlockId].RomBlockNum))
            {
                detErrCode = NVM_E_PARAM_BLOCK_DATA_IDX;
            }
            else
            {
                if(NvM_AdmBlock[BlockId].NvDataIndex >= NvM_Config[BlockId].NvBlockNum)
                {
                    detErrCode = NVM_E_WRITE_PROTECTED_DET;
                }
            }
        }
    }
#endif

#if(STD_ON == NVM_SET_BLOCK_LOCK_API)
    if(detErrCode == NVM_E_NO_ERROR)
    {
        if(TRUE == (boolean)NVM_LOCK_BIT(BlockId))
        {
            detErrCode = NVM_E_BLOCK_LOCKED;/*NVM747 748 NVM830 797*/
        }
    }
#endif
#if(NVM_WRITE_PROTECTED_SUPPORT == STD_ON)
    /* DEM check protected NVM795 799 */
    if(detErrCode == NVM_E_NO_ERROR)
    {
        if(TRUE == (boolean)NVM_PROTECTED_BIT(BlockId))
        {
#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
            if((NVM_BLOCK_REDUNDANT == NvM_Config[BlockId].BlockType) && (TRUE == (boolean)NVM_LOSSR_BIT(BlockId)))
            {
                detErrCode = NVM_E_NO_ERROR;
            }
            else
#endif
            {
                detErrCode = NVM_E_WRITE_PROTECTED_DET;
            }
        }
    }
#endif

    return detErrCode;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_WriteBlock  NVM455
*
* Description:  Copy the data of the RAM block to its corresponding NV block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      NvM_SrcPtr:Pointer to RAM data block
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_WriteBlock
(
    NvM_BlockIdType BlockId,
    P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_SrcPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 detErrCode = NVM_E_NO_ERROR;
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
    P2VAR(uint8, AUTOMATIC, NVM_VAR) tempServiceFlagPtr = NULL_PTR;
#endif

    /*NVM713 NVM619 NVM620*/
    detErrCode = NvM_CheckPar(BlockId);
    if(detErrCode == NVM_E_NO_ERROR)
    {
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
        if(CurrentCoreId == NvM_Config[BlockId].PhyCoreId)
        {
            if(CurrentCoreId != NVM_MASTER_CORE_ID)
            {
                if((NvM_SrcPtr == NVM_NULL) && (NvM_Config[BlockId].RamAddr != NVM_NULL))
                {
                    if(NVM_INVALID_AGENT_JOB_INDEX != NvM_Config[BlockId].AgentJobIndex)
                    {
                        tempServiceFlagPtr = NVM_AGENT_JOB_SERVICE_FLAG_PTR(NvM_Config[BlockId].AgentJobIndex);
                        if(NVM_NO_SERVICE == *tempServiceFlagPtr)
                        {
                            *tempServiceFlagPtr = NVM_WRITE_BLOCK_APIID;
                            ret = E_OK;
                        }
                        else
                        {
                            ret = NVM_E_BLOCK_PENDING;
                        }
                    }
                    else
                    {
                        ret = E_NOT_OK;
                    }
                }
                else
                {
                    detErrCode = NVM_E_CORE_LIMIT;
                }
            }
            else
            {
                ret = NvM_WriteBlockAgent(BlockId, NvM_SrcPtr);
            }
        }
        else
        {
            detErrCode = NVM_E_CORE_LIMIT;
        }
#else
        ret = NvM_WriteBlockAgent(BlockId, NvM_SrcPtr);
#endif
    }
    if(NVM_E_NO_ERROR != detErrCode)
    {
        NVM_DET_REPORT_ERROR(NVM_WRITE_BLOCK_APIID, detErrCode);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_WriteBlockAgent  NVM455
*
* Description:  Copy the data of the RAM block to its corresponding NV block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      NvM_SrcPtr:Pointer to RAM data block
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_WriteBlockAgent
(
    NvM_BlockIdType BlockId,
    P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_SrcPtr
)
{
    Std_ReturnType ret = E_OK;
    uint8 detErrCode = NVM_E_NO_ERROR;;
    P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA)  saveRamAddr;

#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
    detErrCode = NvM_Check_WriteOnce_ReadFirst(BlockId);
#endif

    if(detErrCode == NVM_E_NO_ERROR)
    {
        detErrCode = NvM_WriteBlockCheck(BlockId, NvM_SrcPtr);
    }

    /* check pending must be protected, as the queue may be interrupt by other request */
    SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
    if(detErrCode == NVM_E_NO_ERROR)
    {
        detErrCode = NvM_CheckPending(BlockId, TRUE);
    }


    if(detErrCode == NVM_E_NO_ERROR)
    {
        if(NVM_NULL != NvM_SrcPtr)
        {
            /*PRQA S 317 ++*/
            /*
            Specific implementation methods.
            */
            /*Temporary RAM address*/
            saveRamAddr = (uint8*)NvM_SrcPtr;/*NVM280*/
            /*PRQA S 317 --*/
        }
        else
        {
            /*PRQA S 432 ++*/
            /*
            Specific implementation methods.
            */
            /* return value is check before*/
            (void)NvM_CheckPerRamConfig(BlockId, &saveRamAddr);
            /*PRQA S 432 --*/
        }
        /*PRQA S 431 ++*/
        /*
        Specific implementation methods.
        */
        ret = NvM_QueueJob(BlockId, NVM_JOB_WRITE, saveRamAddr);/*NVM208*/
        /*PRQA S 431 --*/
		
        if(E_OK == ret)
        {
            NvM_AdmBlock[BlockId].NvErrStatus = NVM_REQ_PENDING;
        }
        else
        {
            detErrCode = NVM_E_QUEUE_FULL;
        }
    }
    SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();

    if(NVM_E_NO_ERROR != detErrCode)
    {
        ret = E_NOT_OK;
#if(STD_ON == NVM_DEM_SUPPORT)
        if(NVM_E_WRITE_PROTECTED_DET == detErrCode)
        {
            NVM_DEM_REPORT_E_WRITE_PROTECTED(DEM_EVENT_STATUS_FAILED);
        }
        else if(NVM_E_QUEUE_FULL == detErrCode)
        {
            NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_FAILED);
        }
        else
#endif
        {
            NVM_DET_REPORT_ERROR(NVM_WRITE_BLOCK_APIID, detErrCode);
        }
    }
    else
    {
        ret = E_OK;
        NVM_DEM_REPORT_E_WRITE_PROTECTED(DEM_EVENT_STATUS_PASSED);
        NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_PASSED);
    }

    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ReadPRAMBlock NVM764
*
* Description:  Copy the data of the NV block to its permanent corresponding RAM block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_ReadPRAMBlock
(
    NvM_BlockIdType BlockId
)
{
    Std_ReturnType ret;
    uint8 detErrCode;
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
    P2VAR(uint8, AUTOMATIC, NVM_VAR) tempServiceFlagPtr = NULL_PTR;
#endif

    /*NVM823 826*/
    detErrCode = NvM_CheckPar(BlockId);

    if(detErrCode == NVM_E_NO_ERROR)
    {
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
        if(CurrentCoreId == NvM_Config[BlockId].PhyCoreId)
        {
            if(CurrentCoreId != NVM_MASTER_CORE_ID)
            {
                if(NVM_INVALID_AGENT_JOB_INDEX != NvM_Config[BlockId].AgentJobIndex)
                {
                    tempServiceFlagPtr = NVM_AGENT_JOB_SERVICE_FLAG_PTR(NvM_Config[BlockId].AgentJobIndex);
                    if(NVM_NO_SERVICE == *tempServiceFlagPtr)
                    {
                        *tempServiceFlagPtr = NVM_READ_PRAMBLOCK;
                        ret = E_OK;
                    }
                    else
                    {
                        ret = NVM_E_BLOCK_PENDING;
                    }
                }
                else
                {
                    ret = E_NOT_OK;
                }
            }
            else
            {
                ret = NvM_ReadPRAMBlockAgent(BlockId);
            }
        }
        else
        {
            detErrCode = NVM_E_CORE_LIMIT;
        }
#else
        ret = NvM_ReadPRAMBlockAgent(BlockId);
#endif
    }
    if(NVM_E_NO_ERROR != detErrCode)
    {
        NVM_DET_REPORT_ERROR(NVM_READ_PRAMBLOCK, detErrCode);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ReadPRAMBlockAgent NVM764
*
* Description:  Copy the data of the NV block to its permanent corresponding RAM block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_ReadPRAMBlockAgent
(
    NvM_BlockIdType BlockId
)
{
    Std_ReturnType ret;
    uint8 detErrCode;
    P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA)  saveRamAddr;

    detErrCode = NvM_ReadBlockCheck(BlockId, NULL_PTR);
    /* check pending must be protected, as the queue may be interrupt by other request */
    SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
    if(detErrCode == NVM_E_NO_ERROR)
    {
        detErrCode = NvM_CheckPending(BlockId, FALSE);
    }

    if(detErrCode == NVM_E_NO_ERROR)
    {
        /* return value is check before*/
        (void)NvM_CheckPerRamConfig(BlockId, &saveRamAddr);

        ret = NvM_QueueJob(BlockId, NVM_JOB_READ_PRAMBLOCK, saveRamAddr);/*NVM766*/
        if (E_OK == ret)
        {
            NvM_AdmBlock[BlockId].NvErrStatus = NVM_REQ_PENDING;
            NVM_SET_INVALID_UNCHANGED(BlockId);
        }
        else
        {
            detErrCode = NVM_E_QUEUE_FULL;
        }
    }
    SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();


    if(NVM_E_NO_ERROR != detErrCode)
    {
        ret = E_NOT_OK;
#if(STD_ON == NVM_DEM_SUPPORT)
        if(NVM_E_QUEUE_FULL == detErrCode)
        {
            NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_FAILED);
        }
        else
#endif
        {
            NVM_DET_REPORT_ERROR(NVM_READ_PRAMBLOCK, detErrCode);
        }
    }
    else
    {
        ret = E_OK;
        NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_PASSED);
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_WritePRAMBlock  NVM793
*
* Description:  Copy the data of the RAM block to its corresponding NV block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_WritePRAMBlock
(
    NvM_BlockIdType BlockId
)
{
    Std_ReturnType ret = E_OK;
    uint8 detErrCode;
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
    P2VAR(uint8, AUTOMATIC, NVM_VAR) tempServiceFlagPtr = NULL_PTR;
#endif

    /*NVM827 829*/
    detErrCode = NvM_CheckPar(BlockId);
    if(detErrCode == NVM_E_NO_ERROR)
    {
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
        if(CurrentCoreId == NvM_Config[BlockId].PhyCoreId)
        {
            if(CurrentCoreId != NVM_MASTER_CORE_ID)
            {
                if(NVM_INVALID_AGENT_JOB_INDEX != NvM_Config[BlockId].AgentJobIndex)
                {
                    tempServiceFlagPtr = NVM_AGENT_JOB_SERVICE_FLAG_PTR(NvM_Config[BlockId].AgentJobIndex);
                    if(NVM_NO_SERVICE == *tempServiceFlagPtr)
                    {
                        *tempServiceFlagPtr = NVM_WRITE_PRAMBLOCK;
                        ret = E_OK;
                    }
                    else
                    {
                        ret = NVM_E_BLOCK_PENDING;
                    }
                }
                else
                {
                    ret = E_NOT_OK;
                }
            }
            else
            {
                ret = NvM_WritePRAMBlockAgent(BlockId);
            }
        }
        else
        {
            detErrCode = NVM_E_CORE_LIMIT;
        }
#else
        ret = NvM_WritePRAMBlockAgent(BlockId);
#endif
    }
    if(NVM_E_NO_ERROR != detErrCode)
    {
        NVM_DET_REPORT_ERROR(NVM_WRITE_PRAMBLOCK, detErrCode);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_WritePRAMBlockAgent  NVM793
*
* Description:  Copy the data of the RAM block to its corresponding NV block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_WritePRAMBlockAgent
(
    NvM_BlockIdType BlockId
)
{
    Std_ReturnType ret = E_OK;
    uint8 detErrCode = NVM_E_NO_ERROR;;
    P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA)  saveRamAddr;

#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
    detErrCode = NvM_Check_WriteOnce_ReadFirst(BlockId);
#endif

    if(detErrCode == NVM_E_NO_ERROR)
    {
        /* Check for RAM block NULL pointer*/
        detErrCode = NvM_WriteBlockCheck(BlockId, NULL_PTR);
    }


    /* check pending must be protected, as the queue may be interrupt by other request */
    SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
    if(detErrCode == NVM_E_NO_ERROR)
    {
        detErrCode = NvM_CheckPending(BlockId, TRUE);
    }


    if(detErrCode == NVM_E_NO_ERROR)
    {

        /* return value is check before*/
        (void)NvM_CheckPerRamConfig(BlockId, &saveRamAddr);


        ret = NvM_QueueJob(BlockId, NVM_JOB_WRITE_PRAMBLOCK, saveRamAddr); /*NVM798*/
        if(E_OK == ret)
        {
            NvM_AdmBlock[BlockId].NvErrStatus = NVM_REQ_PENDING;
            NVM_SET_VALID_CHANGED(BlockId);
        }
        else
        {
            detErrCode = NVM_E_QUEUE_FULL;
        }
    }
    SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();

    if(NVM_E_NO_ERROR != detErrCode)
    {
        ret = E_NOT_OK;
#if(STD_ON == NVM_DEM_SUPPORT)
        if(NVM_E_WRITE_PROTECTED_DET == detErrCode)
        {
            NVM_DEM_REPORT_E_WRITE_PROTECTED(DEM_EVENT_STATUS_FAILED);
        }
        else if(NVM_E_QUEUE_FULL == detErrCode)
        {
            NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_FAILED);
        }
        else
#endif
        {
            NVM_DET_REPORT_ERROR(NVM_WRITE_PRAMBLOCK, detErrCode);
        }
    }
    else
    {
        ret = E_OK;
        NVM_DEM_REPORT_E_WRITE_PROTECTED(DEM_EVENT_STATUS_PASSED);
        NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_PASSED);
    }

    return ret;
}


#if(STD_ON == NVM_CANCELJOB_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_CancelJobs NVM535
*
* Description:  Cancel all the job request of a Block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_CancelJobs
(
    NvM_BlockIdType BlockId
)
{
    Std_ReturnType ret = E_OK;
    uint8 detErrCode;


    detErrCode = NvM_CheckPar(BlockId);/*NVM648 NVM649*/

    if(detErrCode != NVM_E_NO_ERROR)
    {
        NVM_DET_REPORT_ERROR(NVM_CANCEL_JOBS, detErrCode);
        ret = E_NOT_OK;
    }
    else
    {

        /* only pending jobs can be canceled
           Busy ongoing Job can not be cancel
           NvM_DeleteAllPengdingJobOfBlock only check queue without NvM_CurrentJobInfo

           NVM537
        */
        SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();

        ret = NvM_DeleteAllPengdingJobOfBlock(BlockId);
        if(E_OK == ret)
        {
            if(NvM_CurrentJobInfo.BlockId != BlockId)
            {
                NvM_AdmBlock[BlockId].NvErrStatus = NVM_REQ_CANCELED; /*NVM536 NVM225*/
                NVM_SET_INVALID_UNCHANGED(BlockId);
            }


#if(STD_ON == NVM_BSWM_SUPPORT)
            if(TRUE == NvM_Config[BlockId].EnReportBswM)
            {
                BswM_NvM_CurrentBlockMode(BlockId, NVM_REQ_CANCELED);
            }
#endif
        }

        SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();

    }
    return ret;
}
#endif/*#if(STD_ON == NVM_CANCELJOB_API)*/


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_RestoreBlockCheck
*
* Description:  check restore job valid or not
*
* Inputs:       BlockId, NvM_SrcPtr
*
* Outputs:      uint8
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(uint8, NVM_CODE) NvM_RestoreBlockCheck
(
    NvM_BlockIdType BlockId,
    CONSTP2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_DestPtr
)
{
    uint8 detErrCode = NVM_E_NO_ERROR;

    /* if initfun is cfg, no ram is need */
    if(NvM_InitBlockCallBackFunPtr[BlockId] == NVM_NULL)
    {
        /* Check for RAM block NULL pointer. NVM435 NVM629*/
        if((NvM_DestPtr == NVM_NULL)
                && (NvM_Config[BlockId].RamAddr == NVM_NULL))
        {
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
            if(FALSE == NvM_Config[BlockId].EnUseSynM)
            {
                detErrCode = NVM_E_PARAM_ADDRESS;
            }
            else
            {   
                if(NULL_PTR == NvM_ReadRamBlockFromNvmFunPtr[BlockId])
                {

                    detErrCode = NVM_E_PARAM_ADDRESS;

                }
            }

#else
            detErrCode = NVM_E_PARAM_ADDRESS;
#endif

        }
    }

    /* check restor cfg method is valid*/
    if(detErrCode == NVM_E_NO_ERROR)
    {
        /* if initfun is cfg, no other restore method check */
        if(NvM_InitBlockCallBackFunPtr[BlockId] == NVM_NULL)
        {
            if(NvM_Config[BlockId].RomAddr == NVM_NULL)
            {
                /* no supported rom block or call back error NVM628*/

                /* dataset block , rom block has high priority to restore NVM353*/
#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)
                if(NVM_BLOCK_DATASET == NvM_Config[BlockId].BlockType)
                {
                    if(NvM_Config[BlockId].RomBlockNum > (uint8)0)
                    {
                        /* only dataindex of rom index canbe restore NVM818*/
                        if((NvM_AdmBlock[BlockId].NvDataIndex >=
                                (NvM_Config[BlockId].NvBlockNum + NvM_Config[BlockId].RomBlockNum))
                                || (NvM_AdmBlock[BlockId].NvDataIndex < NvM_Config[BlockId].NvBlockNum))
                        {
                            detErrCode = NVM_E_PARAM_BLOCK_DATA_IDX;
                        }
                    }
                    else
                    {
                        detErrCode = NVM_E_BLOCK_WITHOUT_DEFAULTS;/*NVM883 885 887 NVM833 884 886*/
                    }
                }
                else
#endif
                {
                    detErrCode = NVM_E_BLOCK_WITHOUT_DEFAULTS;
                }
            }
        }
    }

    return detErrCode;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_RestoreBlockDefaults NVM456
*
* Description:  Restore the default data to its corresponding RAM block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      NvM_DestPtr:Pointer to RAM data block
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_RestoreBlockDefaults
(
    NvM_BlockIdType BlockId,
    P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DestPtr
)
{
    Std_ReturnType ret;
    uint8 detErrCode;
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
    P2VAR(uint8, AUTOMATIC, NVM_VAR) tempServiceFlagPtr = NULL_PTR;
#endif

    /*NVM714 NVM625 NVM626 NVM630*/
    detErrCode = NvM_CheckPar(BlockId);
    if(detErrCode == NVM_E_NO_ERROR)
    {
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
        if(CurrentCoreId == NvM_Config[BlockId].PhyCoreId)
        {
            if(CurrentCoreId != NVM_MASTER_CORE_ID)
            {
                if((NvM_DestPtr == NVM_NULL) && (NvM_Config[BlockId].RamAddr != NVM_NULL))
                {
                    if(NVM_INVALID_AGENT_JOB_INDEX != NvM_Config[BlockId].AgentJobIndex)
                    {
                        tempServiceFlagPtr = NVM_AGENT_JOB_SERVICE_FLAG_PTR(NvM_Config[BlockId].AgentJobIndex);
                        if(NVM_NO_SERVICE == *tempServiceFlagPtr)
                        {
                            *tempServiceFlagPtr = NVM_RESTORE_BLOCK_DEFAULTS_APIID;
                            ret = E_OK;
                        }
                        else
                        {
                            ret = NVM_E_BLOCK_PENDING;
                        }
                    }
                    else
                    {
                        ret = E_NOT_OK;
                    }
                }
                else
                {
                    detErrCode = NVM_E_CORE_LIMIT;
                }
            }
            else
            {
                ret = NvM_RestoreBlockDefaultsAgent(BlockId, NvM_DestPtr);
            }
        }
        else
        {
            detErrCode = NVM_E_CORE_LIMIT;
        }
#else
        ret = NvM_RestoreBlockDefaultsAgent(BlockId, NvM_DestPtr);
#endif
    }
    if(NVM_E_NO_ERROR != detErrCode)
    {
        NVM_DET_REPORT_ERROR(NVM_RESTORE_BLOCK_DEFAULTS_APIID, detErrCode);
    }
    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_RestoreBlockDefaultsAgent NVM456
*
* Description:  Restore the default data to its corresponding RAM block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      NvM_DestPtr:Pointer to RAM data block
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_RestoreBlockDefaultsAgent
(
    NvM_BlockIdType BlockId,
    P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DestPtr
)
{
    Std_ReturnType ret;
    uint8 detErrCode;
    P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA)  saveRamAddr;

    detErrCode = NvM_RestoreBlockCheck(BlockId, NvM_DestPtr);
    SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
    /* check pending must be protected, as the queue may be interrupt by other request */
    if(detErrCode == NVM_E_NO_ERROR)
    {
        detErrCode = NvM_CheckPending(BlockId, FALSE);
    }

    if(detErrCode == NVM_E_NO_ERROR)
    {
        if(NvM_InitBlockCallBackFunPtr[BlockId] != NVM_NULL)
        {
            saveRamAddr = NVM_NULL;
        }
        else if(NVM_NULL != NvM_DestPtr)
        {
            /*PRQA S 317 ++*/
            /*
            Specific implementation methods.
           */
            /*Temporary RAM address*/
            saveRamAddr = (uint8*)NvM_DestPtr;/*NVM436*/
            /*PRQA S 317 --*/
        }
        else
        {
            /* return value is check before*/
            (void)NvM_CheckPerRamConfig(BlockId, &saveRamAddr);
        }

        ret = NvM_QueueJob(BlockId, NVM_JOB_RESTORE, saveRamAddr); /*NVM224*/
        if(E_OK == ret)
        {
            NvM_AdmBlock[BlockId].NvErrStatus = NVM_REQ_PENDING;
            NVM_SET_INVALID_UNCHANGED(BlockId);
        }
        else
        {
            detErrCode = NVM_E_QUEUE_FULL;
        }
    }
    SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();

    if(NVM_E_NO_ERROR != detErrCode)
    {
        ret = E_NOT_OK;
#if(STD_ON == NVM_DEM_SUPPORT)
        if(NVM_E_QUEUE_FULL == detErrCode)
        {
            NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_FAILED);
        }
        else
#endif
        {
            NVM_DET_REPORT_ERROR(NVM_RESTORE_BLOCK_DEFAULTS_APIID, detErrCode);
        }
    }
    else
    {
        ret = E_OK;
        NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_PASSED);
    }

    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_RestorePRAMBlockDefaults NVM813
*
* Description:  Restore the default data to its corresponding RAM block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_RestorePRAMBlockDefaults
(
    NvM_BlockIdType BlockId
)
{
    Std_ReturnType ret;
    uint8 detErrCode;
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
    P2VAR(uint8, AUTOMATIC, NVM_VAR) tempServiceFlagPtr = NULL_PTR;
#endif

    /*NVM831 834*/
    detErrCode = NvM_CheckPar(BlockId);
    if(detErrCode == NVM_E_NO_ERROR)
    {
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
        if(CurrentCoreId == NvM_Config[BlockId].PhyCoreId)
        {
            if(CurrentCoreId != NVM_MASTER_CORE_ID)
            {
                if(NVM_INVALID_AGENT_JOB_INDEX != NvM_Config[BlockId].AgentJobIndex)
                {
                    tempServiceFlagPtr = NVM_AGENT_JOB_SERVICE_FLAG_PTR(NvM_Config[BlockId].AgentJobIndex);
                    if(NVM_NO_SERVICE == *tempServiceFlagPtr)
                    {
                        *tempServiceFlagPtr = NVM_RESTORE_PRAMBLOCK;
                        ret = E_OK;
                    }
                    else
                    {
                        ret = NVM_E_BLOCK_PENDING;
                    }
                }
                else
                {
                    ret = E_NOT_OK;
                }
            }
            else
            {
                ret = NvM_RestorePRAMBlockDefaultsAgent(BlockId);
            }
        }
        else
        {
            detErrCode = NVM_E_CORE_LIMIT;
        }
#else
        ret = NvM_RestorePRAMBlockDefaultsAgent(BlockId);
#endif
    }
    if(NVM_E_NO_ERROR != detErrCode)
    {
        NVM_DET_REPORT_ERROR(NVM_RESTORE_PRAMBLOCK, detErrCode);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_RestorePRAMBlockDefaultsAgent NVM813
*
* Description:  Restore the default data to its corresponding RAM block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_RestorePRAMBlockDefaultsAgent
(
    NvM_BlockIdType BlockId
)
{
    Std_ReturnType ret;
    uint8 detErrCode;
    P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA)  saveRamAddr;

    detErrCode = NvM_RestoreBlockCheck(BlockId, NULL_PTR);
    SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
    /* check pending must be protected, as the queue may be interrupt by other request */
    if(detErrCode == NVM_E_NO_ERROR)
    {
        detErrCode = NvM_CheckPending(BlockId, FALSE);
    }

    if(detErrCode == NVM_E_NO_ERROR)
    {
        if(NvM_InitBlockCallBackFunPtr[BlockId] != NVM_NULL)
        {
            saveRamAddr = NVM_NULL;
        }
        else
        {
            /* return value is check before*/
            (void)NvM_CheckPerRamConfig(BlockId, &saveRamAddr);
        }

        ret = NvM_QueueJob(BlockId, NVM_JOB_RESTORE_PRAMBLOCK, saveRamAddr); /*NVM815*/
        if(E_OK == ret)
        {
            NvM_AdmBlock[BlockId].NvErrStatus = NVM_REQ_PENDING;
            NVM_SET_INVALID_UNCHANGED(BlockId);
        }
        else
        {
            detErrCode = NVM_E_QUEUE_FULL;
        }
    }
    SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();

    if(NVM_E_NO_ERROR != detErrCode)
    {
        ret = E_NOT_OK;
#if(STD_ON == NVM_DEM_SUPPORT)
        if(NVM_E_QUEUE_FULL == detErrCode)
        {
            NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_FAILED);
        }
        else
#endif
        {
            NVM_DET_REPORT_ERROR(NVM_RESTORE_PRAMBLOCK, detErrCode);
        }
    }
    else
    {
        ret = E_OK;
        NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_PASSED);
    }

    return ret;
}

#endif


#if(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_SetBlockProtection NVM450
*
* Description:  Setting/resetting the write protection for a NV block.
*
* Inputs:       BlockId: Block ID
*     ProtectionEnabled: Write Protection should be enable or disable
                         TRUE/FALSE
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_SetBlockProtection
(
    NvM_BlockIdType BlockId,
    boolean ProtectionEnabled
)
{
    Std_ReturnType  ret;
    uint8 detErrCode;

    /*NVM709 704 NVM606 NVM607 NVM609*/
    detErrCode = NvM_CheckPar(BlockId);

    if(detErrCode == NVM_E_NO_ERROR)
    {

        if(NVM_REQ_PENDING == NvM_AdmBlock[BlockId].NvErrStatus)
        {
            detErrCode = NVM_E_BLOCK_PENDING;
        }

        /* Check if NVRAM block is configured with NVM_WRITE_BLOCK_ONCE == TRUE.*/
        /* write once block can not set write protect by user NVM608*/

        else if(NvM_Config[BlockId].EnWriteOnce == TRUE)
        {
            detErrCode = NVM_E_BLOCK_CONFIG;
        }
        else
        {
            /* no err keep detErrCode no err*/
        }
    }

#if(STD_ON == NVM_SET_BLOCK_LOCK_API)
    if(detErrCode == NVM_E_NO_ERROR)
    {
        if(TRUE == (boolean)NVM_LOCK_BIT(BlockId))
        {
            detErrCode = NVM_E_BLOCK_LOCKED;/*NVM747 759*/
        }
    }
#endif



    if(detErrCode != NVM_E_NO_ERROR)
    {
        NVM_DET_REPORT_ERROR(NVM_SET_BLOCK_PROTECTION, detErrCode);
        ret = E_NOT_OK;
    }
    else
    {

        NVM_PROTECTED_BIT(BlockId) = ProtectionEnabled;/*NVM016*/
        ret = E_OK;
    }

    return  ret;

}
#endif

#if(STD_ON == NVM_ERASE_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_EraseNvBlock
*
* Description:  Erase a NV block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_EraseNvBlock
(
    NvM_BlockIdType BlockId
)
{
    Std_ReturnType  ret  = E_OK;
    uint8 detErrCode;
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
    P2VAR(uint8, AUTOMATIC, NVM_VAR) tempServiceFlagPtr = NULL_PTR;
#endif

    /*NVM713 NVM631 NVM632 NVM635*/
    detErrCode = NvM_CheckPar(BlockId);
    if(detErrCode == NVM_E_NO_ERROR)
    {
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
        if(CurrentCoreId == NvM_Config[BlockId].PhyCoreId)
        {
            if(CurrentCoreId != NVM_MASTER_CORE_ID)
            {
                if(NVM_INVALID_AGENT_JOB_INDEX != NvM_Config[BlockId].AgentJobIndex)
                {
                    tempServiceFlagPtr = NVM_AGENT_JOB_SERVICE_FLAG_PTR(NvM_Config[BlockId].AgentJobIndex);
                    if(NVM_NO_SERVICE == *tempServiceFlagPtr)
                    {
                        *tempServiceFlagPtr = NVM_ERASE_BLOCK;
                        ret = E_OK;
                    }
                    else
                    {
                        ret = NVM_E_BLOCK_PENDING;
                    }
                }
                else
                {
                    ret = E_NOT_OK;
                }
            }
            else
            {
                ret = NvM_EraseNvBlockAgent(BlockId);
            }
        }
        else
        {
            detErrCode = NVM_E_CORE_LIMIT;
        }
#else
        ret = NvM_EraseNvBlockAgent(BlockId);
#endif
    }
    if(NVM_E_NO_ERROR != detErrCode)
    {
        NVM_DET_REPORT_ERROR(NVM_ERASE_BLOCK, detErrCode);
    }
    return ret;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_EraseNvBlockAgent
*
* Description:  Erase a NV block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_EraseNvBlockAgent
(
    NvM_BlockIdType BlockId
)
{
    Std_ReturnType  ret  = E_OK;
    uint8 detErrCode;

#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
    detErrCode = NvM_Check_WriteOnce_ReadFirst(BlockId);
#else
    detErrCode = NVM_E_NO_ERROR;
#endif
    if(detErrCode == NVM_E_NO_ERROR)
    {
        /* NVM357 */
        if(NvM_Config[BlockId].BlockPri > (uint8)0)
        {
            detErrCode = NVM_E_BLOCK_CONFIG; /*NVM636*/
        }
#if(STD_ON == NVM_SET_BLOCK_LOCK_API)
        else if(TRUE == (boolean)NVM_LOCK_BIT(BlockId))
        {
            detErrCode = NVM_E_BLOCK_LOCKED;/*NVM747 757*/
        }
#endif
#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
        /*NVM262*/
        else if(TRUE == (boolean)NVM_PROTECTED_BIT(BlockId))
        {
            detErrCode = NVM_E_WRITE_PROTECTED_DET;
        }
        else
        {
            /*do nothing*/
        }
#endif
    }
#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)
    if(detErrCode == NVM_E_NO_ERROR)
    {
        /*NVM661*/
        if(NVM_BLOCK_DATASET == NvM_Config[BlockId].BlockType)
        {
            if(NvM_AdmBlock[BlockId].NvDataIndex >= NvM_Config[BlockId].NvBlockNum)
            {
                detErrCode = NVM_E_PARAM_BLOCK_DATA_IDX;
            }
        }
    }
#endif

    SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
    /* check pending must be protected, as the queue may be interrupt by other request */
    if(detErrCode == NVM_E_NO_ERROR)
    {
        detErrCode = NvM_CheckPending(BlockId, FALSE);
    }


    if(detErrCode == NVM_E_NO_ERROR)
    {
        ret = NvM_QueueJob(BlockId, NVM_JOB_ERASE, NVM_NULL);
        if(E_OK == ret)
        {
            NvM_AdmBlock[BlockId].NvErrStatus = NVM_REQ_PENDING;
        }
        else
        {
            detErrCode = NVM_E_QUEUE_FULL;
        }

    }
    SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();


    if(NVM_E_NO_ERROR != detErrCode)
    {
        ret = E_NOT_OK;
#if(STD_ON == NVM_DEM_SUPPORT)
        if(NVM_E_WRITE_PROTECTED_DET == detErrCode)
        {
            NVM_DEM_REPORT_E_WRITE_PROTECTED(DEM_EVENT_STATUS_FAILED);
        }
        else if(NVM_E_QUEUE_FULL == detErrCode)
        {
            NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_FAILED);
        }
        else
#endif
        {
            NVM_DET_REPORT_ERROR(NVM_ERASE_BLOCK, detErrCode);
        }
    }
    else
    {
        ret = E_OK;
        NVM_DEM_REPORT_E_WRITE_PROTECTED(DEM_EVENT_STATUS_PASSED);
        NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_PASSED);
    }


    return ret;
}
#endif

#if(STD_ON == NVM_INVALID_NVBLOCK_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_InvalidateNvBlock
*
* Description:  Service to invalidate a NV block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_InvalidateNvBlock
(
    NvM_BlockIdType BlockId
)
{
    Std_ReturnType  ret  = E_NOT_OK;
    uint8 detErrCode;

#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
    P2VAR(uint8, AUTOMATIC, NVM_VAR) tempServiceFlagPtr = NULL_PTR;
#endif

    /*NVM713 NVM638 NVM639 NVM642*/
    detErrCode = NvM_CheckPar(BlockId);
    if(detErrCode == NVM_E_NO_ERROR)
    {
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
        if(CurrentCoreId == NvM_Config[BlockId].PhyCoreId)
        {
            if(CurrentCoreId != NVM_MASTER_CORE_ID)
            {
                if(NVM_INVALID_AGENT_JOB_INDEX != NvM_Config[BlockId].AgentJobIndex)
                {
                    tempServiceFlagPtr = NVM_AGENT_JOB_SERVICE_FLAG_PTR(NvM_Config[BlockId].AgentJobIndex);
                    if(NVM_NO_SERVICE == *tempServiceFlagPtr)
                    {
                        *tempServiceFlagPtr = NVM_INVALIDATE_NV_BLOCK_APIID;
                        ret = E_OK;
                    }
                    else
                    {
                        ret = NVM_E_BLOCK_PENDING;
                    }
                }
                else
                {
                    ret = E_NOT_OK;
                }
            }
            else
            {
                ret = NvM_InvalidateNvBlockAgent(BlockId);
            }
        }
        else
        {
            detErrCode = NVM_E_CORE_LIMIT;
        }
#else
        ret = NvM_InvalidateNvBlockAgent(BlockId);
#endif
    }
    if(NVM_E_NO_ERROR != detErrCode)
    {
        NVM_DET_REPORT_ERROR(NVM_INVALIDATE_NV_BLOCK_APIID, detErrCode);
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_InvalidateNvBlockAgent
*
* Description:  Service to invalidate a NV block.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_InvalidateNvBlockAgent
(
    NvM_BlockIdType BlockId
)
{
    Std_ReturnType  ret  = E_NOT_OK;
    uint8 detErrCode = NVM_E_NO_ERROR;;

#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
    detErrCode = NvM_Check_WriteOnce_ReadFirst(BlockId);
#endif

#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)
    if(detErrCode == NVM_E_NO_ERROR)
    {
        if(NVM_BLOCK_DATASET == NvM_Config[BlockId].BlockType)
        {
            if(NvM_AdmBlock[BlockId].NvDataIndex >= NvM_Config[BlockId].NvBlockNum)
            {
                detErrCode = NVM_E_PARAM_BLOCK_DATA_IDX;
            }
        }

    }
#endif

#if(STD_ON == NVM_SET_BLOCK_LOCK_API)
    if(detErrCode == NVM_E_NO_ERROR)
    {
        if(TRUE == (boolean)NVM_LOCK_BIT(BlockId))
        {
            detErrCode = NVM_E_BLOCK_LOCKED;/*NVM747 756*/
        }
    }
#endif


#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
    if(detErrCode == NVM_E_NO_ERROR)
    {
        /*NVM423*/
        if(TRUE == (boolean)NVM_PROTECTED_BIT(BlockId))
        {
            detErrCode = NVM_E_WRITE_PROTECTED_DET;
        }
    }
#endif

    SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
    /* check pending must be protected, as the queue may be interrupt by other request */
    if(detErrCode == NVM_E_NO_ERROR)
    {
        detErrCode = NvM_CheckPending(BlockId, FALSE);
    }


    if(detErrCode == NVM_E_NO_ERROR)
    {
        ret = NvM_QueueJob(BlockId, NVM_JOB_INVALID, NVM_NULL);
        if(E_OK == ret)
        {
            NvM_AdmBlock[BlockId].NvErrStatus = NVM_REQ_PENDING;
        }
        else
        {
            detErrCode = NVM_E_QUEUE_FULL;
        }
    }
    SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();



    if(NVM_E_NO_ERROR != detErrCode)
    {
        ret = E_NOT_OK;
#if(STD_ON == NVM_DEM_SUPPORT)
        if(NVM_E_WRITE_PROTECTED_DET == detErrCode)
        {
            NVM_DEM_REPORT_E_WRITE_PROTECTED(DEM_EVENT_STATUS_FAILED);
        }
        else if(NVM_E_QUEUE_FULL == detErrCode)
        {
            NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_FAILED);
        }
        else
#endif
        {
            NVM_DET_REPORT_ERROR(NVM_INVALIDATE_NV_BLOCK_APIID, detErrCode);
        }
    }
    else
    {
        ret = E_OK;
        NVM_DEM_REPORT_E_WRITE_PROTECTED(DEM_EVENT_STATUS_PASSED);
        NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_PASSED);
    }

    return ret;
}
#endif

#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_GetErrorStatus  NVM451
*
* Description:  Service to read the block dependent error/status information.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      RequestResultPtr:pointer to where to store request result
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_GetErrorStatus
(
    NvM_BlockIdType BlockId,
    P2VAR(NvM_RequestResultType, AUTOMATIC, NVM_APPL_DATA) RequestResultPtr
)
{
    Std_ReturnType ret;
    NvM_RequestResultType tempresult;
    uint8 detErrCode;

    /* NVM710 NVM610  Check if NvM was initialized. */
    if(NvM_TaskState == NVM_STATE_UNINIT)
    {
        detErrCode = NVM_E_UNINIT;
    }
    /* Check BlockId out of range. 1 is not valid
       0 is used to get multi job stats NVM611
    */
    else if(BlockId >= NVM_TOTAL_NUM_OF_NVRAM_BLOCKS)
    {
        detErrCode = NVM_E_PARAM_BLOCK_ID;

    }
    /* Check for NULL pointer. NVM612 */
    else if(RequestResultPtr == NVM_NULL)
    {
        detErrCode = NVM_E_PARAM_DATA;

    }
    else
    {
        detErrCode = NVM_E_NO_ERROR;
    }


    if(detErrCode != NVM_E_NO_ERROR)
    {
        NVM_DET_REPORT_ERROR(NVM_GET_ERROR_STATUS, detErrCode);
        ret = E_NOT_OK;
    }
    else
    {
        /* consider this as atomic opration */
        /* when call this function from slave core it will not cause any problem */
        tempresult = NvM_AdmBlock[BlockId].NvErrStatus;
        /*NVM394*/ 
        /*when blockid =0  return multijob result which store in block 0 */

        *RequestResultPtr = tempresult;/*NVM015*/
        ret = E_OK;

    }

    return ret;
}

#if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)/*NVM408*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_SetRamBlockStatus NVM453
*
* Description:  Setting the RAM block status of an NVRAM block.
*
* Inputs:       BlockId: Block ID
*          BlockChanged:Ram Block as changed or unchanged
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, NVM_CODE) NvM_SetRamBlockStatus
(
    NvM_BlockIdType BlockId,
    boolean BlockChanged
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 detErrCode;
    P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA)  saveRamAddr;
    uint8 result = (uint8)0;

    /*NVM711 704 NVM643 NVM644 NVM645*/
    detErrCode = NvM_CheckPar(BlockId);

    if(detErrCode == NVM_E_NO_ERROR)
    {
        if(NVM_REQ_PENDING == NvM_AdmBlock[BlockId].NvErrStatus)
        {
            detErrCode = NVM_E_BLOCK_PENDING;
        }
    }

#if(STD_ON == NVM_SET_BLOCK_LOCK_API)
    if(detErrCode == NVM_E_NO_ERROR)
    {
        if(TRUE == (boolean)NVM_LOCK_BIT(BlockId))
        {
            detErrCode = NVM_E_BLOCK_LOCKED;/*NVM747 758*/
        }
    }
#endif

    if(NVM_E_NO_ERROR != detErrCode)
    {
        /* don othing */
    }
    /* SWS_NvM_00240 */
    else if(FALSE == NvM_Config[BlockId].UseSetRamBlockStatus)
    {
        detErrCode = NVM_E_BLOCK_CONFIG;
    }
    else
    {

        result = NvM_CheckPerRamConfig(BlockId, &saveRamAddr);
        if(result != NVM_CONFIG_NO_PERRAM)
        {
            SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
            if(TRUE == BlockChanged)
            {
                /* as CRC is only recalculate, dont need to match with other
                so the result will always ok
                set block changed and valid
                NVM241 NVM406 assume that the change is valid
                */
                NVM_SET_VALID_CHANGED(BlockId);

                ret = E_OK;

#if(STD_ON == NVM_CRC_ENABLE)
                if(TRUE == NvM_Config[BlockId].EnCrc)
                {
                    /*NVM121 Request CRC Calculate*/
                    ret = NvM_QueueJob(BlockId, NVM_JOB_SET_RAMSTA, saveRamAddr);
                    if (E_OK == ret)
                    {
                        NvM_AdmBlock[BlockId].NvErrStatus = NVM_REQ_PENDING;
                    }
                    else
                    {
                        detErrCode = NVM_E_QUEUE_FULL;
                    }

                }
#endif
            }
            else
            {
                /* set block unchanged
                   keep valid bit NVM405
                */
                NVM_CHANGED_BIT(BlockId) = FALSE;
                ret = E_OK;
            }
            SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();
        }
        else
        {
            /* SWS_NvM_00240 */
            detErrCode = NVM_E_BLOCK_CONFIG;
        }
    }


    if(NVM_E_NO_ERROR != detErrCode)
    {
        ret = E_NOT_OK;
#if(STD_ON == NVM_DEM_SUPPORT)
        if(NVM_E_QUEUE_FULL == detErrCode)
        {
            NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_FAILED);
        }
        else
#endif
        {
            NVM_DET_REPORT_ERROR(NVM_SET_RAM_BLOCK_STATUS_APIID, detErrCode);
        }
    }
    else
    {
        ret = E_OK;
        NVM_DEM_REPORT_E_QUEUE_OVERFLOW(DEM_EVENT_STATUS_PASSED);
    }

    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ReadAll NVM460
*
* Description:  Initiates a multi block read request.
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE) NvM_ReadAll( void )
{
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
#endif
    Std_ReturnType ret = E_OK;
    SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
    if(NvM_TaskState == NVM_STATE_UNINIT)/*NVM719 NVM646*/
    {
        NVM_DET_REPORT_ERROR(NVM_READ_ALL, NVM_E_UNINIT);

    }/* Check if NvM was initialized. */
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    else if(CurrentCoreId != NVM_MASTER_CORE_ID)
    {
        NVM_DET_REPORT_ERROR(NVM_READ_ALL, NVM_E_CORE_LIMIT);
    }
#endif
    else if(FALSE == NvM_IsMultiJobEmpty())
    {
        NVM_DET_REPORT_ERROR(NVM_READ_ALL, NVM_E_BLOCK_PENDING);

    }/* Check for other multi job pending */
    else
    {
        /* NVM243*/
        ret = NvM_QueueJob((NvM_BlockIdType)0, NVM_JOB_READALL, NVM_NULL);
        if(E_OK == ret)
        {
            NvM_AdmBlock[0].NvErrStatus = NVM_REQ_PENDING;
        }             
    }
    SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_WriteAll NVM461
*
* Description:  Initiates a multi block write request.
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE) NvM_WriteAll
(
    void
)
{
#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
    uint8 detErrCode = NVM_E_NO_ERROR;
    NvM_BlockIdType BlockId;
#endif
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
#endif
    Std_ReturnType ret = E_OK;

    SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
    if(NvM_TaskState == NVM_STATE_UNINIT)/*NVM720 NVM647*/
    {
        NVM_DET_REPORT_ERROR(NVM_WRITE_ALL, NVM_E_UNINIT);

    }/* Check if NvM was initialized. */
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    else if(CurrentCoreId != NVM_MASTER_CORE_ID)
    {
        NVM_DET_REPORT_ERROR(NVM_WRITE_ALL, NVM_E_CORE_LIMIT);
    }
#endif
    else if(FALSE == NvM_IsMultiJobEmpty())
    {
        NVM_DET_REPORT_ERROR(NVM_WRITE_ALL, NVM_E_BLOCK_PENDING);

    }/* Check for other multi job pending */
    else
    { 
#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
        for(BlockId = NVM_WRITEALL_BLOCKID_START;BlockId < NVM_TOTAL_NUM_OF_NVRAM_BLOCKS;BlockId++)
        {
            detErrCode = NvM_Check_WriteOnce_ReadFirst(BlockId);
            if(detErrCode != NVM_E_NO_ERROR)
            {
                NVM_DET_REPORT_ERROR(NVM_WRITE_ALL, detErrCode);
            }
        }
#endif
             /* NVM254*/
        ret = NvM_QueueJob((NvM_BlockIdType)0, NVM_JOB_WRITEALL, NVM_NULL);
        if(E_OK == ret)
        {
            NvM_AdmBlock[0].NvErrStatus = NVM_REQ_PENDING;
        }  

    }
    SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_ValidateAll
*
* Description:  Initiates a multi block write request.
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
#if ((NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)\
||(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2))
FUNC(void, NVM_CODE) NvM_ValidateAll ( void )
{
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
#endif
    Std_ReturnType ret = E_OK;
    SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
    if(NvM_TaskState == NVM_STATE_UNINIT)/*NVM859*/
    {
        NVM_DET_REPORT_ERROR(NVM_VALIDATE_ALL, NVM_E_UNINIT);
    }/* Check if NvM was initialized. */
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    else if(CurrentCoreId != NVM_MASTER_CORE_ID)
    {
        NVM_DET_REPORT_ERROR(NVM_VALIDATE_ALL, NVM_E_CORE_LIMIT);
    }
#endif
    else if(FALSE == NvM_IsMultiJobEmpty())
    {
        NVM_DET_REPORT_ERROR(NVM_VALIDATE_ALL, NVM_E_BLOCK_PENDING);

    }/* Check for other multi job pending */
    else
    {
        /* NVM858*/
        ret = NvM_QueueJob((NvM_BlockIdType)0, NVM_VALIDATE_ALL, NVM_NULL);
        if(E_OK == ret)
        {
            NvM_AdmBlock[0].NvErrStatus = NVM_REQ_PENDING;
        }  
    }
    SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_CancelWriteAll NVM458
*
* Description:  Cancel running NvM_WriteAll request.
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE) NvM_CancelWriteAll( void )
{
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
#endif
    if(NvM_TaskState == NVM_STATE_UNINIT)/*NVM716 NVM637*/
    {
        NVM_DET_REPORT_ERROR(NVM_CANCEL_ALL, NVM_E_UNINIT);
    }/* Check if NvM was initialized. */
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    else if(CurrentCoreId != NVM_MASTER_CORE_ID)
    {
        NVM_DET_REPORT_ERROR(NVM_CANCEL_ALL, NVM_E_CORE_LIMIT);
    }
#endif
    else
    {
        /*only cancel when writeAll is pending or busying
          just set cancel flag here

          when WriteAll is pending, its in queue,NvM_CurrentJobInfo is empty
          when WriteAll is busying, it has been pop out from queue to NvM_CurrentJobInfo

          cancel writeAll will be done in mainfunction
        */
        /*NVM232
          NVM420  no need to queue the cancelwriteall job
        */
        SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();

        if((NVM_JOB_WRITEALL == NvM_MultiJob.ServiceId)
                || (NVM_JOB_WRITEALL == NvM_CurrentJobInfo.ServiceId))
        {
            NvM_CancelWriteAllFlag = TRUE;
        }
        else
        {
            NvM_CancelWriteAllFlag = FALSE;
        }
        SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();
    }

}

#if(STD_ON == NVM_SET_BLOCK_LOCK_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_SetBlockLockStatus
*
* Description:  set Block status lock or not.To be used by DCM and complex
*               device drivers,The function is not included in the serviceport interface
*
* Inputs:       BlockId: Block ID
*               BlockLocked:
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE) NvM_SetBlockLockStatus
(
    NvM_BlockIdType BlockId,
    boolean BlockLocked
)
{
    uint8 detErrCode;

    detErrCode = NvM_CheckPar(BlockId);/*NVM728 NVM729 NVM731*/


    if(NVM_E_NO_ERROR == detErrCode)
    {
        if(NVM_REQ_PENDING == NvM_AdmBlock[BlockId].NvErrStatus)
        {
            detErrCode = NVM_E_BLOCK_PENDING;
        }
        else if((NULL_PTR == NvM_Config[BlockId].RamAddr)/*NVM732*/
#if(STD_ON == NVM_USE_SYNC_MECHANISM)
                && (FALSE == NvM_Config[BlockId].EnUseSynM)
#endif
               )
        {
            detErrCode = NVM_E_PARAM_ADDRESS;
        }
#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
        else if(TRUE == NvM_Config[BlockId].EnWriteOnce)
        {
            detErrCode = NVM_E_BLOCK_CONFIG;/*NVM730*/
        }
#endif
        else
        {
            /*PRQA S 4599 ++*/
            NVM_LOCK_BIT(BlockId) = BlockLocked;
            /*PRQA S 4599 --*/
        }
    }

    if(NVM_E_NO_ERROR != detErrCode)
    {
        NVM_DET_REPORT_ERROR(NVM_SET_BLOCK_LOCK_STATUS, detErrCode);
    }
}
#endif

#if(NVM_VERSION_INFO_API == STD_ON)/*NVM286 NVM650*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_GetVersionInfo NVM452
*
* Description:   This function is used get  NVM's version
*
* Inputs:        VersioninfoPtr: pointer
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE) NvM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, NVM_APPL_DATA) versioninfo
)
{
    if (versioninfo == NVM_NULL)
    {
        NVM_DET_REPORT_ERROR(NVM_GET_VERSION_INFO, NVM_E_PARAM_POINTER);

    }/* Check for NULL pointer.NVM613 */
    else
    {
        /*NVM285*/
        /* Copy the vendor Id */
        versioninfo->vendorID = NVM_VENDOR_ID;
        /* Copy the module Id */
        versioninfo->moduleID = NVM_MODULE_ID;
        /* Copy Software Major Version */
        versioninfo->sw_major_version = (uint8)NVM_SW_MAJOR_VERSION;
        /* Copy Software Minor Version */
        versioninfo->sw_minor_version = (uint8)NVM_SW_MINOR_VERSION;
        /* Copy Software Patch Version */
        versioninfo->sw_patch_version = (uint8)NVM_SW_PATCH_VERSION;
    }
}
#endif

#if (NVM_POLLING_MODE == STD_OFF)/*NVM440 NVM441*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_JobEndNotification NVM438 NVM462 NVM111
*
* Description:  Function to be used by the underlying memory abstraction to
                signal end of job without error.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE) NvM_JobEndNotification( void )
{
    NvM_JobNotification();
#if(STD_ON == NVM_CIPHER_ENABLE)
    NvM_JobCryptEndNotification();
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_JobErrorNotification NVM463 NVM112
*
* Description:  Function to be used by the underlying memory abstraction to
                signal end of job with error.
*
* Inputs:       BlockId: Block ID
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE) NvM_JobErrorNotification( void )
{
    NvM_JobNotification();
#if(STD_ON == NVM_CIPHER_ENABLE)
    NvM_JobCryptErrorNotification();
#endif
}
#endif


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_FirstInitAll 
*
* Description:  The function initiates a multi block first initialization request. The job of the function
*                does not care if a block exists in the non-volatile memory or not OR if it is valid
*               (i.e. not corrupted) or not, when processing it.
*
* Inputs:       None
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
FUNC(void, NVM_CODE) NvM_FirstInitAll( void )
{
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
#endif
    Std_ReturnType ret = E_OK;

    SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
    if(NvM_TaskState == NVM_STATE_UNINIT)/*NVM720 NVM647*/
    {
        NVM_DET_REPORT_ERROR(NVM_FIRSTINIT_ALL, NVM_E_UNINIT);
    }/* Check if NvM was initialized. */
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    else if(CurrentCoreId != NVM_MASTER_CORE_ID)
    {
        NVM_DET_REPORT_ERROR(NVM_FIRSTINIT_ALL, NVM_E_CORE_LIMIT);
    }
#endif
    else if(FALSE == NvM_IsMultiJobEmpty())
    {
        NVM_DET_REPORT_ERROR(NVM_FIRSTINIT_ALL, NVM_E_BLOCK_PENDING);

    }/* Check for other multi job pending */
    else
    { 
             /* NVM254*/
        ret = NvM_QueueJob((NvM_BlockIdType)0, NVM_JOB_FIRSTINITALL, NVM_NULL);
        if(E_OK == ret)
        {
            NvM_AdmBlock[0].NvErrStatus = NVM_REQ_PENDING;
        }  

    }
    SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();

}
#endif

FUNC(void, NVM_CODE) NvM_MainFunction_Process(void)
{
    Std_ReturnType ret;
    boolean isEmpty = FALSE;

    /*NVM256 NVM349*/
    SchM_Enter_NvM_NVM_EXCLUSIVE_AREA_0();
#if(STD_ON == NVM_IMM_BLOCK_SUPPORT)
    NvM_ReplaceWithImmJob();
#endif

    isEmpty = NvM_IsQueueEmpty();
    if((NVM_STATE_IDLE == NvM_TaskState) && (FALSE == isEmpty))
    {
        if(MEMIF_IDLE == MemIf_GetStatus(MEMIF_BROADCAST_ID))
        {
            ret = NvM_GetJob(&NvM_CurrentJobInfo);
            if(E_OK == ret)
            {
                NvM_TaskState = NVM_STATE_BUSY;

                NvM_InitSubState(NvM_CurrentJobInfo.BlockId, NvM_CurrentJobInfo.ServiceId);
            }
        }
    }
    SchM_Exit_NvM_NVM_EXCLUSIVE_AREA_0();


    if(NVM_STATE_BUSY == NvM_TaskState)
    {
        switch(NvM_CurrentJobInfo.ServiceId)
        {

#if((NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) || (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2))

        case NVM_JOB_READ:
        case NVM_JOB_READ_PRAMBLOCK:
            NvM_ReadJobProcess(NvM_CurrentJobInfo.BlockId);
            break;
        case NVM_JOB_WRITE:
        case NVM_JOB_WRITE_PRAMBLOCK:
            NvM_WriteJobProcess(NvM_CurrentJobInfo.BlockId);
            break;

        case NVM_JOB_RESTORE:
        case NVM_JOB_RESTORE_PRAMBLOCK:
            NvM_RestoreProcess(NvM_CurrentJobInfo.BlockId);
            break;
#endif

#if(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)

#if(STD_ON == NVM_ERASE_API)
        case NVM_JOB_ERASE:
            NvM_EraseProcess(NvM_CurrentJobInfo.BlockId);
            break;
#endif

#if(STD_ON == NVM_INVALID_NVBLOCK_API)
        case NVM_JOB_INVALID:
            NvM_InvalidProcess(NvM_CurrentJobInfo.BlockId);
            break;
#endif

#endif

#if((STD_ON == NVM_CRC_ENABLE) && (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON))
        case NVM_JOB_SET_RAMSTA:
            NvM_SetRamStatusProcess(NvM_CurrentJobInfo.BlockId);
            break;
#endif
        case NVM_JOB_READALL:
            NvM_ReadAllJobProcess();
            break;
        case NVM_JOB_WRITEALL:
            NvM_WriteAllJobProcess();
            break;
#if((NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3) || (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2))
        case NVM_JOB_VALIDATEALL:
            NvM_ValidateAllJobProcess();
            break;
#endif
#if((NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3))
        case NVM_JOB_FIRSTINITALL:
            NvM_FirstInitAllJobProcess();
            break;
#endif

        default:
            /* Unexpected case, report error, reset job to make other job running possible*/
            NvM_ResetJobState();
            NVM_DET_REPORT_ERROR(NVM_MAINFUNCTION, NVM_E_UNEXPECTED_CASE);
            break;
        }
    }
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: NvM_MainFunction NVM464
*
* Description:   Performing the processing of the NvM's job
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, NVM_CODE) NvM_MainFunction(void)
{
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 CurrentCoreId = NVM_GETCOREID();
#endif

    /* Check if NvM was initialized. NVM257*/
    if(NvM_TaskState == NVM_STATE_UNINIT)
    {
        NVM_DET_REPORT_ERROR(NVM_MAINFUNCTION, NVM_E_UNINIT);
    }
    else
    {
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
        if(CurrentCoreId != NVM_MASTER_CORE_ID)
        {
            NvM_AgentCallBackMainfunction(CurrentCoreId);
        }
        else
#endif
        {
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
            NvM_AgentMasterMainfunction();
#endif
            NvM_MainFunction_Process();
        }
    }

}

#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"
