/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Det.c
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2 AUTOSAR 4.7.0
*   Title           : Default Error Tracer Source File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of Default Error Tracer   .
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
*   04.00.00    01/08/2022    wenbo.cui     N/A          Beta
********************************************************************************
* END_FILE_HDR*/

/*******************************************************************************
*  General QAC Suppression
*******************************************************************************/
/*PRQA S 3614,3214,0862,1503 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address 
segments in the files of each module,#include "Det_MemMap.h" is required.Defined 
XXX_START_SEC_ will undefine in Det_MemMap.h
*/

/*PRQA S 3119 EOF*/
/*
No unified input parameter processing is used
*/

/*PRQA S 3432 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no 
need to revise.
*/
/*PRQA S 3200 EOF*/
/*
AUTOSAR stipulates that the return value of the called function is E_OK because
service needs,so it is unneessary to value the return value.
*/
/*PRQA S 3109,3138 EOF*/
/*
AUTOSAR stipulates that the return value of the called function is E_OK because
service needs,so it is unneessary to value the return value.
*/

/*PRQA S 3206 EOF*/
/*
Read-only local variables may not be defined as const,this does not affect the function
*/

/*PRQA S 3227 EOF*/
/*
Read-only function input parameters may not be defined as const,it does not affect the function.
AUTOSAR API shall define standard input parameters according to specification requirements
*/

/*PRQA S 2000 EOF*/
/*
When there is only one If,there can be no else.
*/

/*PRQA S 857 EOF*/
/*
Macro definitions exceed 1024.The number of macros is unlimited
*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Det.h"
#include "Det_Externals.h"

#include "SchM_Det.h" /*SWS_Det_00033*/
#if(STD_ON == DET_FORWARD_TO_DLT)
#include "Dlt.h" /*SWS_Det_00042*/
#endif



/*******************************************************************************
*   Version Check
*******************************************************************************/
/*CANIF021  CANIF728*/
#if(STD_ON == DET_VERSION_CHECK)
/* check Version with other import module */


/* check Version with cfg file */
#if ((DET_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (DET_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of Det and its cfg file are different"
#endif

#if ((DET_SW_MAJOR_VERSION != DET_SW_MAJOR_VERSION_CFG) || \
   (DET_SW_MINOR_VERSION != DET_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of Det and its cfg file are different"
#endif

#endif/*#if(STD_ON == DET_VERSION_CHECK)*/

#define DET_START_SEC_VAR_INIT_GLOBAL_8
#include "Det_MemMap.h"

/*used for DET */
STATIC VAR(Std_InitStateType, DET_VAR)  Det_InitStatus = STD_UNINITIALIZED;

/* Det_Error is only used for debug
   User must turn it off when debug is finish
*/
#define DET_STOP_SEC_VAR_INIT_GLOBAL_8
#include "Det_MemMap.h"


#define DET_START_SEC_CODE
/*SWS_Det_00006*/
#include "Det_MemMap.h"

/*******************************************************************************
*   Global Function Define
*******************************************************************************/
uint16 Det_ModuleId;
uint8 Det_ApiId;
uint8 Det_InstanceId;
uint8 Det_ErrorId;
uint16 Det_TotalError;
/*SWS_Det_00008*//*SWS_Det_00019*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Det_Init    
*
* Description:   Service to initialize the Default Error Tracer..
*
* Inputs:        ConfigPtr Pointer to the selected configuration set
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DET_CODE) Det_Init
(
    P2CONST(Det_ConfigType, AUTOMATIC, DET_CONST) ConfigPtr
)
{
    /*SWS_Det_00070*/
    (void)ConfigPtr;
    Det_InitStatus = STD_INITIALIZED;
}
/*SWS_Det_00010*//*SWS_Det_00025*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Det_Start   
*
* Description:   Service to start the Development Error Tracer.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DET_CODE) Det_Start(void)
{
    /*empty funtion*/
}


/*SWS_Det_00009*//*SWS_Det_00013*//*SWS_Det_00061*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Det_ReportError    
*
* Description:   Service to report development errors.
*
* Inputs:        ModuleId InstanceId ApiId ErrorId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

 /* PRQA S 1505 ++ */
FUNC(Std_ReturnType, DET_CODE) Det_ReportError
(
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 ErrorId
)
{
    /*SWS_Det_00024*/
    if(STD_UNINITIALIZED != Det_InitStatus)
    {
#ifdef DET_ERROR_HOOK
        /*SWS_Det_00027 SWS_Det_00052*/
        /*SWS_Det_00035 SWS_Det_00014*/
        /*SWS_Det_00018 SWS_Det_00017*/ 
        (void)DET_ERROR_HOOK;
#endif


#if(STD_ON == DET_FORWARD_TO_DLT)
        Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, ErrorId);
#endif

/*SWS_Det_00015*/
#if(STD_ON == DET_ERROR_LOOP)
        /* PRQA S 2740,2870 ++ */
        while(1)
        {
            /* loop forever */
        }
        /* PRQA S 2740,2870 -- */
#endif
    }

    return E_OK;
}
 /* PRQA S 1505 -- */
/*SWS_Det_01001*//*SWS_Det_00013*//*SWS_Det_00062*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Det_ReportRuntimeError    
*
* Description:   Service to report runtime errors.
*
* Inputs:        ModuleId InstanceId ApiId ErrorId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

FUNC(Std_ReturnType, DET_CODE) Det_ReportRuntimeError
(
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 ErrorId
)
{
    /*SWS_Det_00024*/
    if(STD_UNINITIALIZED != Det_InitStatus)
    {
#ifdef DET_RUNTIME_ERROR_HOOK
        /*SWS_Det_00027 SWS_Det_00052*/
        /*SWS_Det_00035 SWS_Det_00014 SWS_Det_00018 SWS_Det_00017*/
        (void)DET_RUNTIME_ERROR_HOOK;
#endif


#if(STD_ON == DET_FORWARD_TO_DLT)
        Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, ErrorId);
#endif

/*SWS_Det_00015*/
#if(STD_ON == DET_ERROR_LOOP)
        /* PRQA S 2740,2870 ++ */
        while(1)
        {
            /* loop forever */
        }
	    /* PRQA S 2740,2870 -- */
#endif
    }

    return E_OK;
}

/*SWS_Det_01003*//*SWS_Det_00013*//*SWS_Det_00063*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Det_ReportTransientError    
*
* Description:   Service to report transient faults.
*
* Inputs:        ModuleId InstanceId ApiId ErrorId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/

FUNC(Std_ReturnType, DET_CODE) Det_ReportTransientError
(
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 FaultId
)
{
    /*SWS_Det_00024*/
    if(STD_UNINITIALIZED != Det_InitStatus)
    {
#ifdef DET_TRANSIENT_ERROR_HOOK
        /*SWS_Det_00027 SWS_Det_00052*/
        /*SWS_Det_00035 SWS_Det_00014 SWS_Det_00018 SWS_Det_00017*/
        (void)DET_TRANSIENT_ERROR_HOOK;
#endif


#if(STD_ON == DET_FORWARD_TO_DLT)
        Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, FaultId);
#endif

/*SWS_Det_00015*/
#if(STD_ON == DET_ERROR_LOOP)
        /* PRQA S 2740,2870 ++ */
        while(1)
        {
            /* loop forever */
        }
        /* PRQA S 2740,2870 -- */
#endif
    }

    return E_OK;
}

/*SWS_Det_00011*//*SWS_Det_00022*//*SWS_Det_00012*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Det_GetVersionInfo 
*
* Description:   Returns the version information of this module.
*
* Inputs:        VersionInfo Pointer to where to store the version information of this module
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/*SWS_Det_00028*/
#if(STD_ON == DET_VERSION_INFO_API)
FUNC(void, DET_CODE) Det_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DET_APPL_DATA) VersionInfo
)
{

    if(NULL_PTR == VersionInfo)
    {
        /*SWS_Det_00023 SWS_Det_00051*/
        (void)Det_ReportError(DET_MODULE_ID, DET_INSTANCE_ID, DET_GETVERSION_APIID, DET_E_PARAM_POINTER);
    }
    else
    {
        VersionInfo->vendorID = DET_VENDOR_ID;
        VersionInfo->moduleID = DET_MODULE_ID;

        VersionInfo->sw_major_version = (uint8)DET_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)DET_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)DET_SW_PATCH_VERSION;
    }

}
#endif


Std_ReturnType Det_ReportTransientFault (uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 FaultId)
{
    Det_ModuleId = ModuleId;
    Det_ApiId = ApiId;
    Det_InstanceId = InstanceId;
    Det_ErrorId = FaultId;
    Det_TotalError++;
    return (Std_ReturnType)0;
}


#define DET_STOP_SEC_CODE
#include "Det_MemMap.h"


