/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : BswM_Callout.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : BswM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : BswM module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/
/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 5087,3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "BswM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in BswM_MemMap.h
*/

/*PRQA S 0857 EOF*/
/*
Macro definitions exceed 1024. The number of macros is unlimited
*/

/*PRQA S 0776 EOF*/
/*
The first 6 characters shall be different.But AUTOSAR requires prefixes must be the same,so this is ignored.
*/

/*PRQA S 380 EOF*/
/*
Number of macro definitions exceeds 4095 -program does not conform strictly to ISO:C99.
*/

/*PRQA S 3408 EOF*/
/*
'XXX' has external Linkage and is being defined without any previous declaration.
*/
/*****************************************************************************
 *  BswM QAC Suppression
 *****************************************************************************/
/*PRQA S 1532 EOF*/
/*
The callout functions require user integration implementation.
*/


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "BswM_Cfg.h"
#include "BswM_Lcfg.h"
/*Input File User Code start*/
#include "EcuM.h"
#include "ComM.h"
#include "CanIf.h"
#include "Dem.h"
#include "Dcm.h"
#include "CanSM.h"
#include "CanTp.h"
#include "NvM.h"
#include "Com.h"
#include "Mcal.h"
#include "BSW_APP.h"
/*Input File User Code end*/

#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_InitBlockIICallout_Core0
*
* Description:   None
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE)  BswM_InitBlockIICallout_Core0(void)
{
    /*Initialiaze memory stack modules such as Eep/Ea/Fls/Fee/NvM.
      This function will be called only once after power-on.
    */
    /*BswM_InitBlockIICallout_Core0 User Code start*/
    CanIf_Init(&CanIf_InitCfgSet[CURRENT_ECU]);
    CanSM_Init(&CanSM_CfgSet[CURRENT_ECU]);
    CanTp_Init(&CanTp_PBcfg[CURRENT_ECU]);
    Com_Init(&Com_InitCfgSet[CURRENT_ECU]);
    ComM_Init(&ComM_PBConfig[CURRENT_ECU]);  
    PduR_Init(PduR_InitCfgSet[CURRENT_ECU]);
 
    Dcm_Init(&Dcm_PB_Config[CURRENT_ECU]);
    NvM_Init(NULL_PTR);

    Dflash_Init();
    /*BswM_InitBlockIICallout_Core0 User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_StartBswTaskCallout_Core0
*
* Description:   None
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE)  BswM_StartBswTaskCallout_Core0(void)
{
    /*BswM_StartBswTaskCallout_Core0 User Code start*/

    /*BswM_StartBswTaskCallout_Core0 User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_PostReadAllCallout_Core0
*
* Description:   None
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE)  BswM_PostReadAllCallout_Core0(void)
{
    /*Non-volatile data has been restored to RAM. Initialize modules and SWCs that
      rely on those data. This function will be called after power-on and every wakeup,
      so make sure modules are initialized only once.
    */
    /*BswM_PostReadAllCallout_Core0 User Code start*/
    Dem_Init(&Dem_PBCfgSet[CURRENT_ECU]);
    /*BswM_PostReadAllCallout_Core0 User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_PreShutdownCallout_Core0
*
* Description:   None
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE)  BswM_PreShutdownCallout_Core0(void)
{
    /*BswM_PreShutdownCallout_Core0 User Code start*/

    /*BswM_PreShutdownCallout_Core0 User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_WakeupToSleepCallout_Core0
*
* Description:   None
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE)  BswM_WakeupToSleepCallout_Core0(void)
{
    /*Call EcuM_GoDownHaltPoll() to set system back to sleep.
    */
    /*BswM_WakeupToSleepCallout_Core0 User Code start*/

    /*BswM_WakeupToSleepCallout_Core0 User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_WriteNvMToSleepCallout_Core0
*
* Description:   None
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE)  BswM_WriteNvMToSleepCallout_Core0(void)
{
    /*Call EcuM_GoDownHaltPoll() to set system to sleep or shutdown
      to set system to shutdown.
    */
    /*BswM_WriteNvMToSleepCallout_Core0 User Code start*/

    /*BswM_WriteNvMToSleepCallout_Core0 User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_ClearWakeupEventCallout_Core0
*
* Description:   None
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE)  BswM_ClearWakeupEventCallout_Core0(void)
{
    /*Call EcuM_ClearWakeupEvent() to clear all validated wakeup sources.
    This is an example:
    EcuM_WakeupSourceType sources;
    sources = EcuM_GetValidatedWakeupEvents();
    EcuM_ClearWakeupEvent(sources);
    */
    /*BswM_ClearWakeupEventCallout_Core0 User Code start*/

    /*BswM_ClearWakeupEventCallout_Core0 User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_NvMReadAllCallout_Core0
*
* Description:   None
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE)  BswM_NvMReadAllCallout_Core0(void)
{
    /*Call NvM_ReadAll() to restore data from non-volatile devices. This function
      will be called after power-on and after wakeup, so you should decide when
      to read or not.
    */
    /*BswM_NvMReadAllCallout_Core0 User Code start*/
    NvM_RequestResultType Result = NVM_REQ_NOT_OK;
    uint32 ReadAllTimeout = 0U;

    NvM_ReadAll();
    do
    {
      NvM_MainFunction();
      Fee_MainFunction();
      Fls_MainFunction();
      NvM_GetErrorStatus(0, &Result);
      ReadAllTimeout++;
    }while((Result == NVM_REQ_PENDING) && (ReadAllTimeout< 0xFFFFFFFFU));
    /*BswM_NvMReadAllCallout_Core0 User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_NvMWriteAllCallout_Core0
*
* Description:   None
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE)  BswM_NvMWriteAllCallout_Core0(void)
{
    /*Call NvM_WriteAll() to save data to non-volatile devices. This function
      will be called before power-off and sleep, so you should decide when
      to write or not.
    */
    /*BswM_NvMWriteAllCallout_Core0 User Code start*/
    NvM_RequestResultType Result = NVM_REQ_NOT_OK;
    uint32 WriteAllTimeout = 0U;
    Dem_Shutdown();    
    NvM_WriteAll();
    do
    {
      NvM_MainFunction();
      Fee_MainFunction();
      Fls_MainFunction();
      NvM_GetErrorStatus(0, &Result);
      WriteAllTimeout++;
    }while((Result == NVM_REQ_PENDING) &&(WriteAllTimeout < 0xFFFFFFFFU));
    /*BswM_NvMWriteAllCallout_Core0 User Code end*/
}
#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"




