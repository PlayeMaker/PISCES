/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : MemIf.c
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : Memory Abstration Interface Module Source File.
*   Author          : Hirain
********************************************************************************
*   Description     : API Implementation of Memory Abstration Interface Module.
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
*   04.00.00    05/24/2023    Zhuoran.Lu    N/A          Original
********************************************************************************
* END_FILE_HDR*/

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 3614,3214,0862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "EcuM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in EcuM_MemMap.h
*/

/*PRQA S 3429, 3453, 3432 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no need to revise.
*/

/*PRQA S 1503 EOF*/
/*
These extern function will be call by other module, thus no used within this project.
*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "MemIf.h"

#if (STD_ON == MEMIF_DEV_ERROR_DETECT)
#include "Det.h"
#endif

#include "SchM_MemIf.h"


/*******************************************************************************
*   Version Check
*******************************************************************************/
/*MEMIFIF021  MEMIFIF728*/
#if(STD_ON == MEMIF_VERSION_CHECK)
/* check Version with other import module */


/* check Version with cfg file */
#if ((MEMIF_AR_RELEASE_MAJOR_VERSION != MEMIF_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (MEMIF_AR_RELEASE_MINOR_VERSION != MEMIF_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of MemIf and its cfg file are different"
#endif

#if ((MEMIF_SW_MAJOR_VERSION != MEMIF_SW_MAJOR_VERSION_CFG) || \
   (MEMIF_SW_MINOR_VERSION != MEMIF_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of MemIf and its cfg file are different"
#endif
#endif

/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == MEMIF_DEV_ERROR_DETECT)

#define  MEMIF_DET_ERROR_DETECT(cond, ApiId, errcode)  \
    DET_ERROR_DETECT((cond), MEMIF_MODULE_ID, MEMIF_INSTANCE_ID,(ApiId),(errcode))

#define  MEMIF_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret) \
    DET_ERROR_DETECT_RET((cond), MEMIF_MODULE_ID,MEMIF_INSTANCE_ID,(ApiId),(errcode), (ret))

#define  MEMIF_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(MEMIF_MODULE_ID, MEMIF_INSTANCE_ID, (ApiId), (errcode))

#else

#define  MEMIF_DET_ERROR_DETECT(cond, ApiId, errcode)
#define  MEMIF_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret)
#define  MEMIF_DET_REPORT_ERROR(ApiId, errcode)

#endif


/*******************************************************************************
*   PUBLIC Function  Definition
*******************************************************************************/
#define MEMIF_START_SEC_CODE
#include "MemIf_MemMap.h"

#if (MEMIF_NUMBER_OF_DEVICE > 1)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: MemIf_SetMode SWS_MemIf_00038
*
* Description:  This function uses to switch the mode of  Memory Abstraction
                Modules.
*
* Inputs:       Mode:Memory Abstraction Modules for which the status
*                    shall be changed.
*
* Outputs:      None
*
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, MEMIF_CODE) MemIf_SetMode
(
    MemIf_ModeType Mode
)
{
    uint16 DeviceIndex_Init;

    for(DeviceIndex_Init = ((uint16)0); DeviceIndex_Init < ((uint16)MEMIF_NUMBER_OF_DEVICE);
            DeviceIndex_Init++)
    {
        if(NULL_PTR != MemIfSetModeFctPtrCfg[DeviceIndex_Init])
        {
            MemIfSetModeFctPtrCfg[DeviceIndex_Init](Mode);
        }  
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: MemIf_Read SWS_MemIf_00039
*
* Description:  This function uses to read block data of  Memory Abstraction Modules.
*
* Inputs:       DeviceIndex: A handle of Memory Abstraction Modules to be read.
*               BlockNumber: A logic Block number of Memory Abstraction Modules.
*               BlockOffset:  The offset number of Block data.
*               DataBufferPtr:Pointer to a Block related data.
*               Length:      Data length to be read.
*
* Outputs:      Std_ReturnType:In case development error detection is enabled
                for the Memory Abstraction Interface and a development error is detected
*               it shal return E_NOT_OK else it shall return the value of called
*               function of the underlying module.
* Limitations:  None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Read
(
    uint16 DeviceIndex,
    uint16 BlockNumber,
    uint16 BlockOffset,
    P2VAR(uint8, AUTOMATIC, MEMIF_APPL_DATA) DataBufferPtr,
    uint16 Length
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(DeviceIndex >= ((uint16)MEMIF_NUMBER_OF_DEVICE))
    {
        MEMIF_DET_REPORT_ERROR(MEMIF_READ_APIID, MEMIF_E_PARAM_DEVICE);
    }
    else if(NULL_PTR == DataBufferPtr)
    {
        MEMIF_DET_REPORT_ERROR(MEMIF_READ_APIID, MEMIF_E_PARAM_POINTER);
    }
    else
    {
        if(NULL_PTR != MemIfReadFctPtrCfg[DeviceIndex])
        {
            ret = MemIfReadFctPtrCfg[DeviceIndex]
                  (BlockNumber, BlockOffset, DataBufferPtr, Length);
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: MemIf_Write SWS_MemIf_00040
*
* Description:   This function uses to write block data of  Memory Abstraction Modules.
*
* Inputs:        DeviceIndex:  A handle of Memory Abstraction Modules to be write.
*                BlockNumber:  A logic Block number of Memory Abstraction Modules.
*                DataBufferPtr:Pointer to a Block related data.
*
* Outputs:       Std_ReturnType:In case development error detection is enabled for the Memory
*                               Abstraction Interface and a development error is detected
*                               it shal return E_NOT_OK else it shall return the value of called
*                               function of the underlying module.
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, MEMIF_CODE) MemIf_Write
(
    uint16 DeviceIndex,
    uint16 BlockNumber,
    P2CONST(uint8, AUTOMATIC, MEMIF_APPL_DATA) DataBufferPtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(DeviceIndex >= ((uint16)MEMIF_NUMBER_OF_DEVICE))
    {
        MEMIF_DET_REPORT_ERROR(MEMIF_WRITE_APIID, MEMIF_E_PARAM_DEVICE);
    }
    else if(NULL_PTR == DataBufferPtr)
    {
        MEMIF_DET_REPORT_ERROR(MEMIF_WRITE_APIID, MEMIF_E_PARAM_POINTER);
    }
    else
    {
        if(NULL_PTR != MemIfWriteFctPtrCfg[DeviceIndex])
        {
            ret = MemIfWriteFctPtrCfg[DeviceIndex](BlockNumber, DataBufferPtr);
        } 
    }

    return ret;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: MemIf_Cancel SWS_MemIf_00041
*
* Description:   This function uses to cancel a block job request of  Memory Abstraction Modules.
*
* Inputs:        DeviceIndex: A handle of Memory Abstraction Modules to be request.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, MEMIF_CODE) MemIf_Cancel
(
    uint16 DeviceIndex
)
{
    if(DeviceIndex >= ((uint16)MEMIF_NUMBER_OF_DEVICE))
    {
        MEMIF_DET_REPORT_ERROR(MEMIF_CANCEL_APIID, MEMIF_E_PARAM_DEVICE);
    }
    else
    {
        if(NULL_PTR != MemIfCancelFctPtrCfg[DeviceIndex])
        {
            MemIfCancelFctPtrCfg[DeviceIndex]();
        }
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: MemIf_GetStatus SWS_MemIf_00042
*
* Description:   This function uses to get the status of Memory Abstraction Module.
*
* Inputs:        DeviceIndex: A handle of Memory Abstraction Modules to be request.
*
* Outputs:       MemIf_StatusType:MEMIF_UNINIT/MEMIF_BUSY/MEMIF_BUSY_INTERNAL/
*                                               MEMIF_IDLE
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(MemIf_StatusType, MEMIF_CODE) MemIf_GetStatus
(
    uint16 DeviceIndex
)
{
    MemIf_StatusType ret = MEMIF_IDLE;
    MemIf_StatusType ret_temp;
    uint16 DeviceIndex_Init;


    /* SWS_MemIf_00024 if device is invalid, return MEMIF_UNINIT */
    if((DeviceIndex >= ((uint16)MEMIF_NUMBER_OF_DEVICE))
            && (DeviceIndex != (uint16)MEMIF_BROADCAST_ID))
    {
        MEMIF_DET_REPORT_ERROR(MEMIF_GETSTATUS_APIID, MEMIF_E_PARAM_DEVICE);
        ret = MEMIF_UNINIT;/*SWS_MemIf_00024*/
    }
    else
    {
        if(DeviceIndex == (uint16)MEMIF_BROADCAST_ID)
        {
            for(DeviceIndex_Init = ((uint16)0); DeviceIndex_Init < ((uint16)MEMIF_NUMBER_OF_DEVICE); DeviceIndex_Init++)
            {
                if(NULL_PTR != MemIfGetStatusFctPtrCfg[DeviceIndex_Init])
                {
                    ret_temp = MemIfGetStatusFctPtrCfg[DeviceIndex_Init]();
                }
                else
                {
                    ret_temp = MEMIF_UNINIT;/* if getstatus not config, consider it as not init */
                }
                
                /*SWS_MemIf_00035*/
                if(MEMIF_UNINIT == ret_temp)
                {
                    ret = MEMIF_UNINIT;
                    break;
                }
                else if(MEMIF_BUSY == ret_temp)
                {
                    ret = MEMIF_BUSY;
                }
                else if(MEMIF_BUSY_INTERNAL == ret_temp)
                {
                    if(MEMIF_IDLE == ret)
                    {
                        ret = MEMIF_BUSY_INTERNAL;
                    }
                }
                else
                {
                    /* this device is idle */
                    /* if last device is not idle, keep last status */
                    /* if last device is idle, also keep idle */
                }
            }
        }
        else
        {
            if(NULL_PTR != MemIfGetStatusFctPtrCfg[DeviceIndex])
            {
                ret = MemIfGetStatusFctPtrCfg[DeviceIndex]();
            }           
        }

    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: MemIf_InvalidateBlock SWS_MemIf_00044
*
* Description:   This function invokes the underlying memory abstraction module selected by the
*                    parameter DeviceIndex.
*
* Inputs:         DeviceIndex: A handle of Memory Abstraction Modules to be request.
*                 BlockNumber: A logic Block number of Memory Abstraction Modules.
*
* Outputs:       Std_ReturnType:In case development error detection is enabled for the Memory
*                               Abstraction Interface and a development error is detected
*                               it shal return E_NOT_OK else it shall return the value of called
*                               function of the underlying module.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, MEMIF_CODE) MemIf_InvalidateBlock
(
    uint16 DeviceIndex,
    uint16 BlockNumber
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(DeviceIndex >= ((uint16)MEMIF_NUMBER_OF_DEVICE))
    {
        MEMIF_DET_REPORT_ERROR(MEMIF_INVALIDATEBLOCK_APIID, MEMIF_E_PARAM_DEVICE);
    }
    else
    {
        if(NULL_PTR != MemIfInvalidateBlockFctPtrCfg[DeviceIndex])
        {
            ret = MemIfInvalidateBlockFctPtrCfg[DeviceIndex](BlockNumber);
        } 
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: MemIf_GetJobResult SWS_MemIf_00043
*
* Description:   This function uses to get the job process result of Memory Abstraction Module.
*
* Inputs:        DeviceIndex: A handle of Memory Abstraction Modules to be request.
*
* Outputs:       MemIf_JobResultType:In case development error detection is enabled for the
*                                    Memory Abstraction Interface and a development error is detected
*                                    it shal return E_JOB_FAILED else it shall return the value of called
*                                    function of the underlying module.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(MemIf_JobResultType, MEMIF_CODE) MemIf_GetJobResult
(
    uint16 DeviceIndex
)
{
    MemIf_JobResultType ret = MEMIF_JOB_FAILED;

    /* SWS_MemIf_00024 if device is invalid, return MEMIF_JOB_FAILED */

    if(DeviceIndex >= ((uint16)MEMIF_NUMBER_OF_DEVICE))
    {
        MEMIF_DET_REPORT_ERROR(MEMIF_GETJOBREASULT_APIID, MEMIF_E_PARAM_DEVICE);
    }
    else
    {
        if(NULL_PTR != MemIfGetJobResultFctPtrCfg[DeviceIndex])
        {
            ret = MemIfGetJobResultFctPtrCfg[DeviceIndex]();
        } 
    }

    return ret;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: MemIf_EraseImmediateBlock SWS_MemIf_00046
*
* Description:   This function invokes the "EraseImmediateBlock" of the underlying of Memory
*                    Abstraction Module .
*
* Inputs:        DeviceIndex: A handle of Memory Abstraction Modules to be request.
*                BlockNumber: A logic Block number of Memory Abstraction Modules.
*
* Outputs:       Std_ReturnType:In case development error detection is enabled for the Memory
*                               Abstraction Interface and a development error is detected
*                               it shal return E_NOT_OK else it shall return the value of called
*                               function of the underlying module.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, MEMIF_CODE) MemIf_EraseImmediateBlock
(
    uint16 DeviceIndex,
    uint16 BlockNumber
)
{
    Std_ReturnType ret = E_NOT_OK;


    if(DeviceIndex >= ((uint16)MEMIF_NUMBER_OF_DEVICE))
    {
        MEMIF_DET_REPORT_ERROR(MEMIF_ERASEIMMEDIATEBLOCK_APIID, MEMIF_E_PARAM_DEVICE);
    }
    else
    {
        if(NULL_PTR != MemIfEraseImmediateBlockFctPtrCfg[DeviceIndex])
        {
            ret = MemIfEraseImmediateBlockFctPtrCfg[DeviceIndex](BlockNumber);
        }       
    }

    return ret;
}
#endif/*#if (MEMIF_NUMBER_OF_DEVICE > 1)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: MemIf_GetVersionInfo SWS_MemIf_00045
*
* Description:   Return the version information.
*
* Inputs:        None
*
* Outputs:       VersionInfoPtr:Poniter to where to store the version information of the module.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if (STD_ON ==  MEMIF_VERSION_INFO_API)/*SWS_MemIf_00057*/
FUNC(void, MEMIF_CODE) MemIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, MEMIF_APPL_DATA) VersionInfoPtr
)
{
    if(NULL_PTR == VersionInfoPtr)/*SWS_MemIf_00063*/
    {
        MEMIF_DET_REPORT_ERROR(MEMIF_GETVERSIONINFO_APIID, MEMIF_E_PARAM_POINTER);
    }
    else
    {
        /* Copy the vendor Id */
        VersionInfoPtr->vendorID   = MEMIF_VENDOR_ID;
        /* Copy the module Id */
        VersionInfoPtr->moduleID   = MEMIF_MODULE_ID;
        /* Copy Software Major Version */
        VersionInfoPtr->sw_major_version = (uint8)MEMIF_SW_MAJOR_VERSION;
        /* Copy Software Minor Version */
        VersionInfoPtr->sw_minor_version = (uint8)MEMIF_SW_MINOR_VERSION;
        /* Copy Software Patch Version */
        VersionInfoPtr->sw_patch_version = (uint8)MEMIF_SW_PATCH_VERSION;
    }
}
#endif

#define MEMIF_STOP_SEC_CODE
#include "MemIf_MemMap.h"
