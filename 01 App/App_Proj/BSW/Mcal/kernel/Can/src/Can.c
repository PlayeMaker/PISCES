/**
 *   @file    Can.c
 *   @version V0.9.1
 *
 *   @brief   AUTOSAR Can module interface
 *   @details API implementation for CAN driver
 *
 *   @addtogroup CAN_MODULE
 *   @{
 */
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Can
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : V0.9.1
*
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "CanIf.h"
#include "CanIf_Cbk.h"
#include "Can_Lld.h"
#include "Can_Drv.h"
#include "Can.h"
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
#include "OsIf.h"
#endif

#if (CAN_WAKEUP_SUPPORT == STD_ON)
#include "EcuM.h"
#endif

#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_VENDOR_ID_C                      (180)
#define CAN_AR_RELEASE_MAJOR_VERSION_C       (4)
#define CAN_AR_RELEASE_MINOR_VERSION_C       (4)
#define CAN_AR_RELEASE_REVISION_VERSION_C    (0)
#define CAN_SW_MAJOR_VERSION_C               (0)
#define CAN_SW_MINOR_VERSION_C               (9)
#define CAN_SW_PATCH_VERSION_C               (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CAN header file are of the same vendor */
#if (CAN_VENDOR_ID_C != CAN_VENDOR_ID)
#error "Can.c and Can.h have different vendor ids"
#endif

/* Check if source file and CAN header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_C != CAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_AR_RELEASE_MINOR_VERSION_C != CAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_AR_RELEASE_REVISION_VERSION_C != CAN_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Can.c and Can.h are different"
#endif

/* Check if source file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_C != CAN_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_C != CAN_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_C != CAN_SW_PATCH_VERSION))
#error "Software Version Numbers of Can.c and Can.h are different"
#endif

#if (CAN_FIXED_PB_CONFIG == STD_ON)
extern const Can_ConfigType Can_PreCompileConfig;
#endif
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define CAN_START_SEC_VAR_INIT_8
#include "Can_MemMap.h"
CAN_VAR static uint8 Can_LocDrvState = CAN_UNINIT;
CAN_VAR static uint8 Can_LocInstDisableIntLv[CAN_CHANNEL_USED_NUM] =
{
    0U,
#if(1U < CAN_CHANNEL_USED_NUM)
    0U,
#endif
#if(2U < CAN_CHANNEL_USED_NUM)
    0U,
#endif
#if(3U < CAN_CHANNEL_USED_NUM)
    0U,
#endif
#if(4U < CAN_CHANNEL_USED_NUM)
    0U,
#endif
#if(5U < CAN_CHANNEL_USED_NUM)
    0U,
#endif
#if(6U < CAN_CHANNEL_USED_NUM)
    0U,
#endif
#if(7U < CAN_CHANNEL_USED_NUM)
    0U,
#endif
};

CAN_VAR static Can_ControllerStateType Can_LocInstState[CAN_CHANNEL_USED_NUM] =
{
    CAN_CS_UNINIT,
#if(1U < CAN_CHANNEL_USED_NUM)
    CAN_CS_UNINIT,
#endif
#if(2U < CAN_CHANNEL_USED_NUM)
    CAN_CS_UNINIT,
#endif
#if(3U < CAN_CHANNEL_USED_NUM)
    CAN_CS_UNINIT,
#endif
#if(4U < CAN_CHANNEL_USED_NUM)
    CAN_CS_UNINIT,
#endif
#if(5U < CAN_CHANNEL_USED_NUM)
    CAN_CS_UNINIT,
#endif
#if(6U < CAN_CHANNEL_USED_NUM)
    CAN_CS_UNINIT,
#endif
#if(7U < CAN_CHANNEL_USED_NUM)
    CAN_CS_UNINIT,
#endif
};

#define CAN_STOP_SEC_VAR_INIT_8
#include "Can_MemMap.h"/*memory map finish*/

#define CAN_START_SEC_VAR_INIT_BOOLEAN
#include "Can_MemMap.h"
CAN_VAR static boolean Can_LocStateChanged[CAN_CHANNEL_USED_NUM] =
{
    FALSE,
#if(1U < CAN_CHANNEL_USED_NUM)
    FALSE,
#endif
#if(2U < CAN_CHANNEL_USED_NUM)
    FALSE,
#endif
#if(3U < CAN_CHANNEL_USED_NUM)
    FALSE,
#endif
#if(4U < CAN_CHANNEL_USED_NUM)
    FALSE,
#endif
#if(5U < CAN_CHANNEL_USED_NUM)
    FALSE,
#endif
#if(6U < CAN_CHANNEL_USED_NUM)
    FALSE,
#endif
#if(7U < CAN_CHANNEL_USED_NUM)
    FALSE,
#endif
};

CAN_VAR static boolean Can_LocInstIntState[CAN_CHANNEL_USED_NUM] =
{
    FALSE,
#if(1U < CAN_CHANNEL_USED_NUM)
    FALSE,
#endif
#if(2U < CAN_CHANNEL_USED_NUM)
    FALSE,
#endif
#if(3U < CAN_CHANNEL_USED_NUM)
    FALSE,
#endif
#if(4U < CAN_CHANNEL_USED_NUM)
    FALSE,
#endif
#if(5U < CAN_CHANNEL_USED_NUM)
    FALSE,
#endif
#if(6U < CAN_CHANNEL_USED_NUM)
    FALSE,
#endif
#if(7U < CAN_CHANNEL_USED_NUM)
    FALSE,
#endif

};

#define CAN_STOP_SEC_VAR_INIT_BOOLEAN
#include "Can_MemMap.h"/*memory map finish*/

#define CAN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"
CAN_VAR static const Can_ConfigType * Can_LocCfgPtr;

CAN_VAR static const Can_BdrConfigType * Can_LocCurrentBdr[CAN_CHANNEL_USED_NUM];

#define CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"/*memory map finish*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if 0
LOCAL_INLINE Std_ReturnType Can_LocConfigParaCheck(void);
#endif

LOCAL_INLINE void Can_LocInitAllCanController(void);

LOCAL_INLINE boolean Can_LocGetFdFlag(Can_HwHandleType Hth);

LOCAL_INLINE Std_ReturnType Can_LocSetInstToStarted(uint8 Controller, Can_ControllerStateType State);

LOCAL_INLINE Std_ReturnType Can_LocSetInstToStopped(uint8 Controller, Can_ControllerStateType State);

LOCAL_INLINE Std_ReturnType Can_LocSetInstToSleep(uint8 Controller, Can_ControllerStateType State);

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_FUNC void Can_Init(const Can_ConfigType *Config)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    if ((uint8)CAN_READY == Can_LocDrvState)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the Can driver State
           Trace : SWS_Can_00174 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, CAN_INSTANCE_ALL_ID,
                                CAN_SID_INIT, CAN_E_TRANSITION);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
#if (CAN_FIXED_PB_CONFIG == STD_ON)
        if (NULL_PTR != Config)
        {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            /* Invalid pointer */
            (void)Det_ReportError((uint16)CAN_MODULE_ID, CAN_INSTANCE_ALL_ID,
                                CAN_SID_INIT, CAN_E_PARAM_POINTER);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        }
        else 
        {
            CAN_UNUSED_PARAM(Config); /* To avoid compiler warning */
            Can_LocCfgPtr = &Can_PreCompileConfig;
            RetVal = (Std_ReturnType)E_OK;
        }
#else /* (CAN_FIXED_PB_CONFIG == STD_OFF) */
        if (NULL_PTR == Config)
        {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            /* Invalid pointer */
            (void)Det_ReportError((uint16)CAN_MODULE_ID, CAN_INSTANCE_ALL_ID,
                                CAN_SID_INIT, CAN_E_PARAM_POINTER);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            Can_LocCfgPtr = Config;
            RetVal = (Std_ReturnType)E_OK;
        }
#endif /* (CAN_FIXED_PB_CONFIG == STD_ON) */
    }
    if((Std_ReturnType)E_OK == RetVal)
    {
        Can_Lld_InstallConfigPtr(Can_LocCfgPtr);
        (void)Can_LocInitAllCanController();
        Can_LocDrvState = (uint8)CAN_READY;
    }
}

#if (CAN_WAKEUP_FUNCTIONALITY_API == STD_ON)
CAN_FUNC Std_ReturnType Can_CheckWakeup (uint8 ChnLogicId)
{
    /* The function Can_CheckWakeup shall be pre compile time configurable On/Off by the
       configuration parameter: CanWakeupFunctionalityAPI
       Trace : SWS_Can_00485 */
    Std_ReturnType RetVal;
    if ((uint8)CAN_UNINIT == Can_LocDrvState)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the Can driver State
           Trace : SWS_Can_00362 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, ChnLogicId,
                        CAN_SID_CHECK_WAKEUP, CAN_E_UNINIT);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (Can_LocCfgPtr->CanChannelNum <= ChnLogicId)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the function parameters <Controller>
           Trace : SWS_Can_00363 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, ChnLogicId,
                        CAN_SID_CHECK_WAKEUP, CAN_E_PARAM_CONTROLLER);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if(FALSE == Can_LocCfgPtr->CanChCfgPtr[ChnLogicId].CanWakeupFunctionalityAPI)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#if (CAN_WAKEUP_SUPPORT == STD_ON)
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
        if(OsIf_Trusted_Call_Return1param(Can_Lld_CheckWakeupOccur, &Can_LocCfgPtr->CanChCfgPtr[ChnLogicId]) == TRUE)
#else
        if(Can_Lld_CheckWakeupOccur(&Can_LocCfgPtr->CanChCfgPtr[ChnLogicId]) == TRUE)
#endif
        {
            /**
             * The function Can_CheckWakeup shall check if the requested CAN controller has detected
             * a wakeup. If a wakeup event was successfully detected, reporting shall be done to
             * EcuM via API EcuM_SetWakeupEvent 
             * Trace : SWS_Can_00361
             */
            EcuM_SetWakeupEvent(Can_LocCfgPtr->CanChCfgPtr[ChnLogicId].EcuMWakeupSource);
        }
#endif /* (CAN_WAKEUP_SUPPORT == STD_ON) */
        RetVal = (Std_ReturnType)E_OK;
    }
    return RetVal;
}
#endif

#if (CAN_API_DEINIT_ENABLE == STD_ON)
CAN_FUNC void Can_DeInit(void)
{
    uint8 ChnIdIndex;
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    if ((uint8)CAN_UNINIT == Can_LocDrvState)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* If development error detection for the Can module is enabled: The function Can_DeInit
           shall raise the error CAN_E_TRANSITION if the driver is not in State CAN_READY
           Trace : SWS_Can_91011 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, CAN_INSTANCE_ALL_ID,
                         CAN_SID_DE_INIT, CAN_E_TRANSITION);
#endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        for (ChnIdIndex = 0; ChnIdIndex < Can_LocCfgPtr->CanChannelNum; ++ChnIdIndex)
        {
            if(CAN_CS_STARTED == Can_LocInstState[ChnIdIndex]) /*NOSONAR,There are no memory overruns here*/
            {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
                /* If development error detection for the Can module is enabled: The function
                   Can_DeInit shall raise the error CAN_E_TRANSITION if any of the CAN
                   controllers is in State STARTED
                   Trace : SWS_Can_91012 */
                (void)Det_ReportError((uint16)CAN_MODULE_ID, ChnIdIndex,
                                 CAN_SID_DE_INIT, CAN_E_TRANSITION);
#endif
                RetVal = (Std_ReturnType)E_NOT_OK;
            }
        }
    }
    if((Std_ReturnType)E_OK == RetVal)
    {
        for (ChnIdIndex = 0; ChnIdIndex < Can_LocCfgPtr->CanChannelNum; ++ChnIdIndex)
        {
            Can_LocInstDisableIntLv[ChnIdIndex] = 0U;
            Can_LocInstIntState[ChnIdIndex] = FALSE;
            Can_LocCurrentBdr[ChnIdIndex] = NULL_PTR;
            Can_LocStateChanged[ChnIdIndex] = FALSE;
            Can_LocInstState[ChnIdIndex] = CAN_CS_UNINIT;
        }
        Can_LocCfgPtr = NULL_PTR;
        Can_Lld_UnInstallConfigPtr();
        /* The function Can_DeInit shall change the module State to CAN_UNINIT before
           de-initializing all controllers inside the HW unit
           Trace : SWS_Can_91010 */
        Can_LocDrvState = (uint8)CAN_UNINIT;
    }
}
#endif

#if (CAN_API_DISABLE_CONTROLLER_INTERRUPTS == STD_ON)
CAN_FUNC void Can_DisableControllerInterrupts(uint8 Controller)
{
    if ((uint8)CAN_UNINIT == Can_LocDrvState)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /*     Check the driver State
            Trace : SWS_Can_00205 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_DISABLE_CONTROLLER_INTERRUPTS, CAN_E_UNINIT);
#endif
    }
    else if (Can_LocCfgPtr->CanChannelNum <= Controller)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the function parameters <Controller>
        Trace : SWS_Can_00206 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_DISABLE_CONTROLLER_INTERRUPTS, CAN_E_PARAM_CONTROLLER);
#endif
    }
    else
    {
        /* The function Can_DisableControllerInterrupts shall access the CAN controller
           registers to disable all interrupts for that CAN controller only, if interrupts
           for that CAN Controller are enabled.
           Trace : SWS_Can_00049 */
        if(TRUE == Can_LocInstIntState[Controller])
        {
            /* [to do]Suspend all interrupts */
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call1param(Can_Lld_DisableInterrupts, Controller);
#else
            Can_Lld_DisableInterrupts(Controller);
#endif
        }
        /* When Can_DisableControllerInterrupts has been called several times,
           Can_EnableControllerInterrupts must be called as many times before the interrupts
           are re-enabled
           Trace : SWS_Can_00202 */
        ++Can_LocInstDisableIntLv[Controller];
        /* [to do]Resume all interrupts */
    }
}
#endif

#if (CAN_API_ENABLE_CONTROLLER_INTERRUPTS == STD_ON)
CAN_FUNC void Can_EnableControllerInterrupts(uint8 Controller)
{
    if ((uint8)CAN_UNINIT == Can_LocDrvState)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the driver State
           Trace : SWS_Can_00209 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_ENABLE_CONTROLLER_INTERRUPTS, CAN_E_UNINIT);
#endif
    }
    else if (Can_LocCfgPtr->CanChannelNum <= Controller)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the function parameters <Controller>
        Trace : SWS_Can_00210 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_ENABLE_CONTROLLER_INTERRUPTS, CAN_E_PARAM_CONTROLLER);
#endif
    }
    else
    {
        /* Perform no action when Can_DisableControllerInterrupts has not been called before
              Trace : SWS_Can_00208 */
        if(0U < Can_LocInstDisableIntLv[Controller])
        {
            --Can_LocInstDisableIntLv[Controller];
        }
        if ((uint8)0 == Can_LocInstDisableIntLv[Controller])
        {
            if ((CAN_CS_STARTED == Can_LocInstState[Controller]) && \
                (FALSE == Can_LocInstIntState[Controller]))
            {
                /* The function Can_EnableControllerInterrupts shall enable all interrupts that must
                be enabled according the current software status.
                Trace : SWS_Can_00050 */
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
                OsIf_Trusted_Call1param(Can_Lld_EnableInterrupts, Controller);
#else
                Can_Lld_EnableInterrupts(Controller);
#endif
                Can_LocInstIntState[Controller] = TRUE;
            }
        }
    }
    /* [to do]Resume all interrupts */
}
#endif

#if (CAN_API_GET_CONTROLLER_ERROR_STATE == STD_ON)
CAN_FUNC Std_ReturnType Can_GetControllerErrorState(uint8 ControllerId, Can_ErrorStateType * ErrorStatePtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    if ((uint8)CAN_UNINIT == Can_LocDrvState)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the Can driver State
           Trace : SWS_Can_91005 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, ControllerId,
                        CAN_SID_GET_CONTROLLER_ERROR_STATE, CAN_E_UNINIT);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (Can_LocCfgPtr->CanChannelNum <= ControllerId)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the function parameters <Controller>
           Trace : SWS_Can_91006 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, ControllerId,
                        CAN_SID_GET_CONTROLLER_ERROR_STATE, CAN_E_PARAM_CONTROLLER);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == ErrorStatePtr)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the pointer
           Trace : SWS_Can_91007 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, ControllerId,
                        CAN_SID_GET_CONTROLLER_ERROR_STATE, CAN_E_PARAM_POINTER);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* When the API Can_GetControllerErrorState() is called with Controller Id as input
           parameter then Can driver shall read the error State register of Can Controller and
           shall return the error status to upper layer.
           Trace : SWS_Can_91008 */
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
        *ErrorStatePtr = (Can_ErrorStateType)OsIf_Trusted_Call_Return1param(Can_Lld_GetInstErrState, Can_LocCfgPtr->CanChCfgPtr[ControllerId].ChBaseAddr);
#else
        *ErrorStatePtr = Can_Lld_GetInstErrState(Can_LocCfgPtr->CanChCfgPtr[ControllerId].ChBaseAddr);
#endif
        RetVal = (Std_ReturnType)E_OK;
    }
    return RetVal;
}
#endif

#if (CAN_API_GET_CONTROLLER_MODE == STD_ON)
CAN_FUNC Std_ReturnType Can_GetControllerMode(uint8 Controller, Can_ControllerStateType * ControllerModePtr)
 {
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    if ((uint8)CAN_UNINIT == Can_LocDrvState)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the Can driver State
           Trace : SWS_Can_91016 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_GET_CONTROLLER_MODE, CAN_E_UNINIT);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (Can_LocCfgPtr->CanChannelNum <= Controller)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the function parameters <Controller>
           Trace : SWS_Can_91017 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_GET_CONTROLLER_MODE, CAN_E_PARAM_CONTROLLER);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == ControllerModePtr)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the pointer
          Trace : SWS_Can_91018 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_GET_CONTROLLER_MODE, CAN_E_PARAM_POINTER);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* The service Can_GetControllerMode shall return the mode of the requested CAN controller
           Trace : SWS_Can_91015 */
        *ControllerModePtr = Can_LocInstState[Controller];
        RetVal = (Std_ReturnType)E_OK;
    }
    return RetVal;
}
#endif

#if (CAN_API_GET_CONTROLLER_RX_ERROR_COUNTER == STD_ON)
CAN_FUNC Std_ReturnType Can_GetControllerRxErrorCounter(uint8 ControllerId, uint8 * RxErrorCounterPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    if ((uint8)CAN_UNINIT == Can_LocDrvState)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the Can driver State
           Trace : SWS_Can_00512 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, ControllerId,
                        CAN_SID_GET_CONTROLLER_RX_ERROR_COUNTER, CAN_E_UNINIT);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;

    }
    else if (Can_LocCfgPtr->CanChannelNum <= ControllerId)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the function parameters <Controller>
           Trace : SWS_Can_00513 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, ControllerId,
                        CAN_SID_GET_CONTROLLER_RX_ERROR_COUNTER, CAN_E_PARAM_CONTROLLER);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == RxErrorCounterPtr)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the pointer
           Trace : SWS_Can_00514 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, ControllerId,
                        CAN_SID_GET_CONTROLLER_RX_ERROR_COUNTER, CAN_E_PARAM_POINTER);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* When the API Can_GetControllerRxErrorCounter is called with Controller Id as input
           parameter then Can driver shall read the Rx error counter register of Can Controller
           and shall return the Rx error count to upper layer
           Trace: SWS_Can_00515 */
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
        *RxErrorCounterPtr = OsIf_Trusted_Call_Return1param(Can_Lld_GetInstRxErrCounter, Can_LocCfgPtr->CanChCfgPtr[ControllerId].ChBaseAddr);
#else
        *RxErrorCounterPtr = Can_Lld_GetInstRxErrCounter(Can_LocCfgPtr->CanChCfgPtr[ControllerId].ChBaseAddr);
#endif
        RetVal = (Std_ReturnType)E_OK;
    }
    return RetVal;
}
#endif

#if (CAN_API_GET_CONTROLLER_TX_ERROR_COUNTER == STD_ON)
CAN_FUNC Std_ReturnType Can_GetControllerTxErrorCounter (uint8 ControllerId, uint8 * TxErrorCounterPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    if ((uint8)CAN_UNINIT == Can_LocDrvState)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the Can driver State
           Trace : SWS_Can_00517 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, ControllerId,
                        CAN_SID_GET_CONTROLLER_TX_ERROR_COUNTER, CAN_E_UNINIT);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (Can_LocCfgPtr->CanChannelNum <= ControllerId)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the function parameters <Controller>
           Trace : SWS_Can_00518 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, ControllerId,
                        CAN_SID_GET_CONTROLLER_TX_ERROR_COUNTER, CAN_E_PARAM_CONTROLLER);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == TxErrorCounterPtr)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the pointer
           Trace : SWS_Can_00519 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, ControllerId,
                        CAN_SID_GET_CONTROLLER_TX_ERROR_COUNTER, CAN_E_PARAM_POINTER);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* When the API Can_GetControllerTxErrorCounter is called with Controller Id as input
           parameter then Can driver shall read the Tx error counter register of Can Controller
           and shall return the Tx error count to upper layer
           Trace : SWS_Can_00520 */
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
        *TxErrorCounterPtr = OsIf_Trusted_Call_Return1param(Can_Lld_GetInstTxErrCounter, Can_LocCfgPtr->CanChCfgPtr[ControllerId].ChBaseAddr);
#else
        *TxErrorCounterPtr = Can_Lld_GetInstTxErrCounter(Can_LocCfgPtr->CanChCfgPtr[ControllerId].ChBaseAddr);
#endif
        RetVal = (Std_ReturnType)E_OK;
    }
    return RetVal;
}
#endif

#if (CAN_BUSOFF_PROCESS_HAS_POLLING == STD_ON)
CAN_FUNC void Can_MainFunction_BusOff (void)
{
    /* The Can module may implement the function Can_MainFunction_BusOff as empty define in case
       no polling at all is used
       Trace : SWS_Can_00183 */
    if (((uint8)CAN_READY == Can_LocDrvState))
    {
        for (uint8 InstId = 0U; InstId < Can_LocCfgPtr->CanChannelNum; ++InstId)
        {
            /*  The function Can_MainFunction_BusOff shall perform the polling of bus-off events
                that are configured statically as 'to be polled'.
                Trace : SWS_Can_00109 */
            if ((TRUE == Can_LocCfgPtr->CanChCfgPtr[InstId].CanChActivation) && \
                (Can_LocCfgPtr->CanChCfgPtr[InstId].CanBusoffProcessing == CAN_PROCESS_POLLING))
            {
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
                if(TRUE == OsIf_Trusted_Call_Return1param(Can_Lld_GetBusOffFlags, InstId))
#else
                if(TRUE == Can_Lld_GetBusOffFlags(InstId))
#endif
                {
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
                    OsIf_Trusted_Call1param(Can_Lld_BusoffPolling, InstId);
#else
                    Can_Lld_BusoffPolling(InstId);
#endif
                }
                /*     triggered by hardware if the CAN controller reaches bus-off State, The CanIf
                    module is notified with the function CanIf_ControllerBusOff after STOPPED
                    State is reached referring to the corresponding CAN controller with the
                    abstract CanIf ControllerId.
                    Trace : SWS_Can_00020 */
            }
        }
    }
}
#endif

CAN_FUNC void Can_MainFunction_Mode(void)
{
    /* The function Can_MainFunction_Mode shall implement the polling of CAN status register
       flags to detect transition of CAN Controller State.
       Trace : SWS_Can_00369 */
    if (((uint8)CAN_READY == Can_LocDrvState))
    {
        for(uint8 InstId = 0U; InstId < Can_LocCfgPtr->CanChannelNum; ++InstId)
        {
            if ((TRUE == Can_LocCfgPtr->CanChCfgPtr[InstId].CanChActivation) && \
                (TRUE == Can_LocStateChanged[InstId])) /*NOSONAR,There are no memory overruns here*/
            {
                Can_LocStateChanged[InstId] = FALSE;
                CanIf_ControllerModeIndication(InstId, Can_LocInstState[InstId]);
            }
        }
    }
}

#if (CAN_API_MAINFUNCTION_WAKEUP == STD_ON)
CAN_FUNC void Can_MainFunction_Wakeup (void)
{
#if 0
#if (CAN_WAKEUP_SUPPORT == STD_ON)
     the CAN module of YTM32B1ME series IC would wakeup by interrupt necessary, and the Wakeup
       event would been informed to the CanIf by the function EcuM_CheckWakeup always in irq.
     The Can module may implement the function Can_MainFunction_Wakeup as empty define in case
       no polling at all is used.
       Trace : SWS_Can_00185
    if (((uint8)CAN_READY == Can_LocDrvState))
    {
        uint8 InstId;
        for (InstId = 0; InstId < Can_LocCfgPtr->CanChannelNum; ++InstId)
        {
            if (TRUE == Can_LocCfgPtr->CanChCfgPtr[InstId].CanChActivation)
            {
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
                if(OsIf_Trusted_Call_Return2param(Can_Lld_CheckWakeupOccur, InstId, Can_LocCfgPtr) == TRUE)
#else
                if(Can_Lld_CheckWakeupOccur(InstId, Can_LocCfgPtr) == TRUE)
#endif
                {
#if (CAN_WAKEUP_SUPPORT == STD_ON)
                    EcuM_SetWakeupEvent(Can_LocCfgPtr->CanChCfgPtr[InstId].EcuMWakeupSource);
#endif
                }
            }
        }
    }
#endif
#endif
}
#endif

#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM == 1U)
CAN_FUNC void Can_MainFunction_Read (void)
{
    /* The Can module may implement the function Can_MainFunction_Read as empty define in case
       no polling at all is used.
       Trace : SWS_Can_00180 */
    if (((uint8)CAN_READY == Can_LocDrvState) && (NULL_PTR != Can_LocCfgPtr->CanHrhPolPeriodPtr[0].CanPolTablePtr))
    {
        for(uint8 HrhIndex = 0u; HrhIndex < Can_LocCfgPtr->CanHrhPolPeriodPtr[0].CanHohNum; ++HrhIndex)
        {
            if (CAN_CS_STARTED == Can_LocInstState[Can_LocCfgPtr->CanHohCfgPtr[HrhIndex].CanChannelId])
            {
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
                if(TRUE == OsIf_Trusted_Call_Return1param(Can_Lld_GetPollingState, &(Can_LocCfgPtr->CanHrhPolPeriodPtr[0].CanPolTablePtr[HrhIndex])))
#else
                if(TRUE == Can_Lld_GetPollingState(&(Can_LocCfgPtr->CanHrhPolPeriodPtr[0].CanPolTablePtr[HrhIndex])))
#endif
                {
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
                    OsIf_Trusted_Call1param(Can_Lld_PeriodPollingRead, Can_LocCfgPtr->CanHrhPolPeriodPtr[0].CanPolTablePtr[HrhIndex].CanHohId);
#else
                    Can_Lld_PeriodPollingRead(Can_LocCfgPtr->CanHrhPolPeriodPtr[0].CanPolTablePtr[HrhIndex].CanHohId);
#endif
                }
            }
        }
    }
}

#elif(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 1U)
CAN_FUNC void Can_MainFunction_SpecificRead(uint8 PeriodId)
{
    /* If more than one main function period is configured by CanMainFunctionRWPeriods (see
       ECUC_Can_00437), the name of the Can_MainFunction_Read() functions shall be
       Can_MainFunction_Read_<CanMainFunctionRWPeriods.ShortName>() for each
       CanMainFunctionRWPeriods that is referenced by at least one RECEIVE CanHardwareObject
       Trace : SWS_Can_00442 */
    Can_HwHandleType Hrh;
    if (((uint8)CAN_READY == Can_LocDrvState) && (NULL_PTR != Can_LocCfgPtr->CanHrhPolPeriodPtr[PeriodId].CanPolTablePtr))
        
    {
        for(uint8 HrhIndex = 0; HrhIndex < Can_LocCfgPtr->CanHrhPolPeriodPtr[PeriodId].CanHohNum; ++HrhIndex)
        {
            Hrh = Can_LocCfgPtr->CanHrhPolPeriodPtr[PeriodId].CanPolTablePtr[HrhIndex].CanHohId;
            if (CAN_CS_STARTED == Can_LocInstState[Can_LocCfgPtr->CanHohCfgPtr[Hrh].CanChannelId])
            {
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
                if(TRUE == OsIf_Trusted_Call_Return1param(Can_Lld_GetPollingState, &(Can_LocCfgPtr->CanHrhPolPeriodPtr[PeriodId].CanPolTablePtr[HrhIndex])))
#else
                if(TRUE == Can_Lld_GetPollingState(&(Can_LocCfgPtr->CanHrhPolPeriodPtr[PeriodId].CanPolTablePtr[HrhIndex])))
#endif
                {
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
                    OsIf_Trusted_Call1param(Can_Lld_PeriodPollingRead,Can_LocCfgPtr->CanHrhPolPeriodPtr[PeriodId].CanPolTablePtr[HrhIndex].CanHohId);
#else
                    Can_Lld_PeriodPollingRead(Can_LocCfgPtr->CanHrhPolPeriodPtr[PeriodId].CanPolTablePtr[HrhIndex].CanHohId);
#endif
                }
            }
        }
    }
}
CAN_FUNC void Can_MainFunction_Read_Period_0(void){Can_MainFunction_SpecificRead(0);}
CAN_FUNC void Can_MainFunction_Read_Period_1(void){Can_MainFunction_SpecificRead(1);}
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 2U)
CAN_FUNC void Can_MainFunction_Read_Period_2(void){Can_MainFunction_SpecificRead(2);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 3U)
CAN_FUNC void Can_MainFunction_Read_Period_3(void){Can_MainFunction_SpecificRead(3);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 4U)
CAN_FUNC void Can_MainFunction_Read_Period_4(void){Can_MainFunction_SpecificRead(4);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 5U)
CAN_FUNC void Can_MainFunction_Read_Period_5(void){Can_MainFunction_SpecificRead(5);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 6U)
CAN_FUNC void Can_MainFunction_Read_Period_6(void){Can_MainFunction_SpecificRead(6);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 7U)
CAN_FUNC void Can_MainFunction_Read_Period_7(void){Can_MainFunction_SpecificRead(7);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 8U)
CAN_FUNC void Can_MainFunction_Read_Period_8(void){Can_MainFunction_SpecificRead(8);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 9U)
CAN_FUNC void Can_MainFunction_Read_Period_9(void){Can_MainFunction_SpecificRead(9);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 10U)
CAN_FUNC void Can_MainFunction_Read_Period_10(void){Can_MainFunction_SpecificRead(10);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 11U)
CAN_FUNC void Can_MainFunction_Read_Period_11(void){Can_MainFunction_SpecificRead(11);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 12U)
CAN_FUNC void Can_MainFunction_Read_Period_12(void){Can_MainFunction_SpecificRead(12);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 13U)
CAN_FUNC void Can_MainFunction_Read_Period_13(void){Can_MainFunction_SpecificRead(13);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 14U)
CAN_FUNC void Can_MainFunction_Read_Period_14(void){Can_MainFunction_SpecificRead(14);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 15U)
CAN_FUNC void Can_MainFunction_Read_Period_15(void){Can_MainFunction_SpecificRead(15);}
#endif
#endif /* #if (CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM == 1U) */
#endif

#if (CAN_TX_PROCESS_HAS_POLLING == STD_ON)
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM == 1U)
CAN_FUNC void Can_MainFunction_Write (void)
{
    /* The Can module may implement the function Can_MainFunction_Write as empty define in case
       no polling at all is used
       Trace : SWS_Can_00178 */
    if (((uint8)CAN_READY == Can_LocDrvState) && (NULL_PTR != Can_LocCfgPtr->CanHthPolPeriodPtr[0].CanPolTablePtr))
    {
        for(uint8 HthIndex = 0; HthIndex < Can_LocCfgPtr->CanHthPolPeriodPtr[0].CanHohNum; ++HthIndex)
        {
            if (CAN_CS_STARTED == Can_LocInstState[Can_LocCfgPtr->CanHohCfgPtr[HthIndex].CanChannelId])
            {
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
                if(TRUE == OsIf_Trusted_Call_Return1param(Can_Lld_GetPollingState, &(Can_LocCfgPtr->CanHthPolPeriodPtr[0].CanPolTablePtr[HthIndex])))
#else
                if(TRUE == Can_Lld_GetPollingState(&(Can_LocCfgPtr->CanHthPolPeriodPtr[0].CanPolTablePtr[HthIndex])))
#endif
                {
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
                    OsIf_Trusted_Call1param(Can_Lld_PeriodPollingWrite, Can_LocCfgPtr->CanHthPolPeriodPtr[0].CanPolTablePtr[HthIndex].CanHohId);
#else
                    Can_Lld_PeriodPollingWrite(Can_LocCfgPtr->CanHthPolPeriodPtr[0].CanPolTablePtr[HthIndex].CanHohId);
#endif
                }
            }
        }
    }
}

#elif(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 1U)
CAN_FUNC void Can_MainFunction_SpecificWrite(uint8 PeriodId)
{
    /* If more than one main function period is configured by CanMainFunctionRWPeriods (see
       ECUC_Can_00437), the name of the Can_MainFunction_Write() functions shall be
       Can_MainFunction_Write_<CanMainFunctionRWPeriods.ShortName>() for each
       CanMainFunctionRWPeriods that is referenced by at least one TRANSMIT CanHardwareObject
       Trace : SWS_Can_00441 */
    Can_HwHandleType Hth;
    if (((uint8)CAN_READY == Can_LocDrvState) && (NULL_PTR != Can_LocCfgPtr->CanHthPolPeriodPtr[PeriodId].CanPolTablePtr))
    {
        for(uint8 HthIndex = 0; HthIndex < Can_LocCfgPtr->CanHthPolPeriodPtr[PeriodId].CanHohNum; ++HthIndex)
        {
            Hth = Can_LocCfgPtr->CanHthPolPeriodPtr[PeriodId].CanPolTablePtr[HthIndex].CanHohId;
            if (CAN_CS_STARTED == Can_LocInstState[Can_LocCfgPtr->CanHohCfgPtr[Hth].CanChannelId])
            {
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
                if(TRUE == OsIf_Trusted_Call_Return1param(Can_Lld_GetPollingState, &(Can_LocCfgPtr->CanHthPolPeriodPtr[PeriodId].CanPolTablePtr[HthIndex])))
#else
                if(TRUE == Can_Lld_GetPollingState(&(Can_LocCfgPtr->CanHthPolPeriodPtr[PeriodId].CanPolTablePtr[HthIndex])))
#endif
                {
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
                    OsIf_Trusted_Call1param(Can_Lld_PeriodPollingWrite,Can_LocCfgPtr->CanHthPolPeriodPtr[PeriodId].CanPolTablePtr[HthIndex].CanHohId);
#else
                    Can_Lld_PeriodPollingWrite(Can_LocCfgPtr->CanHthPolPeriodPtr[PeriodId].CanPolTablePtr[HthIndex].CanHohId);
#endif
                }
            }
        }
    }
}
CAN_FUNC void Can_MainFunction_Write_Period_0(void){Can_MainFunction_SpecificWrite(0);}
CAN_FUNC void Can_MainFunction_Write_Period_1(void){Can_MainFunction_SpecificWrite(1);}
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 2U)
CAN_FUNC void Can_MainFunction_Write_Period_2(void){Can_MainFunction_SpecificWrite(2);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 3U)
CAN_FUNC void Can_MainFunction_Write_Period_3(void){Can_MainFunction_SpecificWrite(3);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 4U)
CAN_FUNC void Can_MainFunction_Write_Period_4(void){Can_MainFunction_SpecificWrite(4);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 5U)
CAN_FUNC void Can_MainFunction_Write_Period_5(void){Can_MainFunction_SpecificWrite(5);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 6U)
CAN_FUNC void Can_MainFunction_Write_Period_6(void){Can_MainFunction_SpecificWrite(6);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 7U)
CAN_FUNC void Can_MainFunction_Write_Period_7(void){Can_MainFunction_SpecificWrite(7);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 8U)
CAN_FUNC void Can_MainFunction_Write_Period_8(void){Can_MainFunction_SpecificWrite(8);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 9U)
CAN_FUNC void Can_MainFunction_Write_Period_9(void){Can_MainFunction_SpecificWrite(9);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 10U)
CAN_FUNC void Can_MainFunction_Write_Period_10(void){Can_MainFunction_SpecificWrite(10);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 11U)
CAN_FUNC void Can_MainFunction_Write_Period_11(void){Can_MainFunction_SpecificWrite(11);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 12U)
CAN_FUNC void Can_MainFunction_Write_Period_12(void){Can_MainFunction_SpecificWrite(12);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 13U)
CAN_FUNC void Can_MainFunction_Write_Period_13(void){Can_MainFunction_SpecificWrite(13);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 14U)
CAN_FUNC void Can_MainFunction_Write_Period_14(void){Can_MainFunction_SpecificWrite(14);}
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 15U)
CAN_FUNC void Can_MainFunction_Write_Period_15(void){Can_MainFunction_SpecificWrite(15);}
#endif
#endif /* #if (CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM == 1U) */
#endif

#if (CAN_SET_BAUDRATE_API == STD_ON)
CAN_FUNC Std_ReturnType Can_SetBaudrate(uint8 Controller, uint16 BaudrateConfigID)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    if ((uint8)CAN_UNINIT == Can_LocDrvState)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the driver State
           Trace : SWS_Can_00492 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_SET_BAUDRATE, CAN_E_UNINIT);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (Can_LocCfgPtr->CanChannelNum <= Controller)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the controller Id <Controller>
           Trace : SWS_Can_00494 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_SET_BAUDRATE, CAN_E_PARAM_CONTROLLER);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (Can_LocCfgPtr->CanChCfgPtr[Controller].ChBaudrateNum <= BaudrateConfigID)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the function parameters <BaudrateConfigID>
           Trace : SWS_Can_00493 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_SET_BAUDRATE, CAN_E_PARAM_BAUDRATE);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if(Can_LocInstState[Controller] != CAN_CS_STOPPED)
    {
        /* Do not support Can_SetBaudrate use in CAN_CS_SLEEP mode */
        /* If the requested baud rate change can not performed without a re-initialization of
           the CAN Controller E_NO_OK shall be returned.
           Trace : SWS_Can_00500 */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* If re-initialization is necessary the function Can_SetBaudrate shall ensure that any
           settings that will cause the CAN controller to participate in the network are not set.
           Trace : SWS_Can_00422 */
        Can_LocCurrentBdr[Controller] = &(Can_LocCfgPtr->CanChCfgPtr[Controller].BdrConfigPtr[BaudrateConfigID]);
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call2params(Can_Lld_SetBaudrate, &Can_LocCfgPtr->CanChCfgPtr[Controller], Can_LocCurrentBdr[Controller]);
#else
        Can_Lld_SetBaudrate(&Can_LocCfgPtr->CanChCfgPtr[Controller], Can_LocCurrentBdr[Controller]);
#endif
        RetVal = (Std_ReturnType)E_OK;
    }
    return RetVal;
}
#endif

CAN_FUNC Std_ReturnType Can_SetControllerMode(uint8 Controller, Can_ControllerStateType Transition)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    if ((uint8)CAN_UNINIT == Can_LocDrvState)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the driver State
               Trace : SWS_Can_00198 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_SET_CONTROLLER_MODE, CAN_E_UNINIT);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (Can_LocCfgPtr->CanChannelNum <= Controller)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the function parameters <Controller>
        Trace : SWS_Can_00199 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_SET_CONTROLLER_MODE, CAN_E_PARAM_CONTROLLER);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if(Transition == CAN_CS_UNINIT)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the controller State transition supported
           Trace : SWS_Can_00200 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                CAN_SID_SET_CONTROLLER_MODE, CAN_E_TRANSITION);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if(Transition == CAN_CS_STARTED)
    {
        RetVal =  Can_LocSetInstToStarted(Controller, Can_LocInstState[Controller]);
    }
    else if(Transition == CAN_CS_STOPPED)
    {
        RetVal =  Can_LocSetInstToStopped(Controller, Can_LocInstState[Controller]);
    }
    else
    {
        RetVal = Can_LocSetInstToSleep(Controller, Can_LocInstState[Controller]);
    }
    if((Std_ReturnType)E_OK == RetVal)
    {
        Can_LocStateChanged[Controller] = TRUE;
        CanIf_ControllerModeIndication(Controller, Can_LocInstState[Controller]);
    }
    return RetVal;
}

#if (CAN_ICOM_USAGE == STD_ON)
CAN_FUNC Std_ReturnType Can_SetIcomConfiguration (uint8 Controller, IcomConfigIdType ConfigurationId)
{
    /* Can_SetIcomConfiguration() shall be pre compile time configurable ON/OFF by the configuration
       parameter CAN_PUBLIC_ICOM_SUPPORT SWS_Can_00495 */
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    IcomSwitch_ErrorType Error = ICOM_SWITCH_E_FAILED;
    if((uint8)CAN_ICOM_CONFIG_TYPE_COUNT <= ConfigurationId)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the driver State
           Trace : SWS_Can_00475 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_SET_ICOM_CONFIGURATION, CAN_E_ICOM_CONFIG_INVALID);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((uint8)CAN_UNINIT == Can_LocDrvState)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the function parameters <Controller>
           Trace : SWS_Can_ not defined*/
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_SET_ICOM_CONFIGURATION, CAN_E_UNINIT);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (Can_LocCfgPtr->CanChannelNum <= Controller)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the function parameters <Controller>
           Trace : SWS_Can_ not defined*/
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_SET_ICOM_CONFIGURATION, CAN_E_PARAM_CONTROLLER);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if(Can_LocInstState[Controller] != CAN_CS_STOPPED)
    {
        /* Check the driver State
              Trace : SWS_Can_ */
        RetVal = E_NOT_OK;
    }
    else if (FALSE == Can_LocCfgPtr->CanChCfgPtr[Controller].IsoModeUsage)
    {
        /* only Hardware CAN0 has hardware pretend network in YTM32B1ME series IC*/
        RetVal = E_NOT_OK;
    }
    else
    {
        /* If the requested ConfigurationId is not 0, the function Can_SetIcomConfiguration()
           shall reconfigure the controller with the ICOM configuration parameters of the
           CanIcomConfig container which CanIcomConfigId matches the requested ConfigurationId
           Trace : SWS_Can_00480,SWS_Can_00481 */
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call3params(Can_Lld_SetControllerIcom, Controller, ConfigurationId, Can_LocCfgPtr);
#else
        Can_Lld_SetControllerIcom(Controller, ConfigurationId, Can_LocCfgPtr);
#endif
        Error = ICOM_SWITCH_E_OK;
        RetVal = E_OK;
    }
    /* If activation was successful then CanIf_CurrentIcomConfiguration shall be called with the
       parameter Error set to ICOM_SWITCH_E_OK referring to the corresponding CAN controller with
       the abstract CanIf ControllerId. If activation was not successful then
       CanIf_CurrentIcomConfiguration shall be called with the parameter Error set to
       ICOM_SWITCH_E_FAILED referring to the corresponding CAN controller with the abstract CanIf
       ControllerId.
       Trace : SWS_Can_00467 SWS_Can_00474 */
    CanIf_CurrentIcomConfiguration(Controller, ConfigurationId, Error);
    return RetVal;
}
#endif

CAN_FUNC Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType *PduInfo)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint8 MsgBufId;
    if ((uint8)CAN_UNINIT == Can_LocDrvState)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* If development error detection for the Can module is enabled: The function Can_Write
           shall raise the error CAN_E_UNINIT and shall return E_NOT_OK if the driver is not yet
           initialized.
           Trace: SWS_Can_00216 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, CAN_HTH_ERROR_ID,
                        CAN_SID_WRITE, CAN_E_UNINIT);
#endif
    }
    else if((Hth >= Can_LocCfgPtr->CanHohNum) || (CAN_TRANSMIT != Can_LocCfgPtr->CanHohCfgPtr[Hth].ObjectType))
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check hardware trasmission handle : Hth must less than total number of hardware obj
            Trace: SWS_Can_00217 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, CAN_HTH_ERROR_ID,
                                CAN_SID_WRITE, CAN_E_PARAM_HANDLE);
#endif
    }
    else if (CAN_CS_STARTED != Can_LocInstState[Can_LocCfgPtr->CanHohCfgPtr[Hth].CanChannelId])
    {
        /* Map to controller and hardware obj */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /*  If development error detection for the Can module is enabled: The function Can_Write
            shall raise the error CAN_E_UNINIT and shall return E_NOT_OK if the driver is not yet
            initialized.
            Trace: SWS_Can_00216 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Can_LocCfgPtr->CanHohCfgPtr[Hth].CanChannelId,
                        CAN_SID_WRITE, CAN_E_UNINIT);
#endif
    }
    else if (NULL_PTR == PduInfo)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* If development error detection for CanLld_ is enabled: Can_Write() shall raise
           CAN_E_PARAM_POINTER and shall return E_NOT_OK if the parameter PduInfo is a null pointer
           Trace: SWS_Can_00219 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, CAN_HTH_ERROR_ID,
                        CAN_SID_WRITE, CAN_E_PARAM_POINTER);
#endif
    }
    else if(CAN_CONST_FRAME_64_BYTE_FORMAT < PduInfo->length)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /*  CAN FD flag in Can_PduType->id is set but the CAN controller is not in CAN FD mode */
        /*  The function Can_Write shall return E_NOT_OK and if development error detection
            for the CAN module is enabled shall raise the error CAN_E_PARAM_DATA_LENGTH
            ...If the length is more than 64 byte.
            ...If the length is more than 8 byte and the CAN frame is in CAN FD frame,
            but the CAN FD flag in Can_PduType->id is not set.
            ...If the length is more than 8 byte and the CAN controller is not in CAN FD mode
            Trace SWS_Can_00218 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, CAN_HTH_ERROR_ID,
                        CAN_SID_WRITE, CAN_E_PARAM_DATA_LENGTH);
#endif
    }
    else if((CAN_CONST_FRAME_8_BYTE_FORMAT < PduInfo->length) && (FALSE == Can_LocGetFdFlag(Hth)))
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, CAN_HTH_ERROR_ID,
                        CAN_SID_WRITE, CAN_E_PARAM_DATA_LENGTH);
#endif
    }
    else if((CAN_CONST_FRAME_8_BYTE_FORMAT < PduInfo->length) && (0U == (PduInfo->id & CAN_ID_TYPE_FD_FRAME_MASK)))
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, CAN_HTH_ERROR_ID,
                        CAN_SID_WRITE, CAN_E_PARAM_DATA_LENGTH);
#endif
    }
    else if((FALSE == Can_LocGetFdFlag(Hth)) && (0U != (PduInfo->id & CAN_ID_TYPE_FD_FRAME_MASK)))
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CAN_MODULE_ID, CAN_HTH_ERROR_ID,
                        CAN_SID_WRITE, CAN_E_PARAM_DATA_LENGTH);
#endif
    }
    else
    {
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
        RetVal = OsIf_Trusted_Call_Return2param(Can_Lld_GetMbState, Hth, &MsgBufId);
#else
        RetVal = Can_Lld_GetMbState(Hth, &MsgBufId);
#endif
    }
    if ((Std_ReturnType)E_OK == RetVal)
    {
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call3params(Can_Lld_WriteMailBox, Hth, MsgBufId, PduInfo);
#else
        Can_Lld_WriteMailBox(Hth, MsgBufId, PduInfo);
#endif
    }
    return RetVal;
}

#if (CAN_API_ABORT_CONTROLLER_PENDING_MESSAGE == STD_ON)
CAN_FUNC Std_ReturnType Can_AbortControllerPendingMsg(uint8 Controller)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    if ((uint8)CAN_UNINIT == Can_LocDrvState)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* If development error detection for the Can module is enabled: The function
           Can_AbortControllerPendingMsg() shall raise the error CAN_E_UNINIT and shall
           return E_NOT_OK if the driver is not yet initialized.
           Trace: Additional API */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_ABORT_CONTROLLER_PENDING_MESSAGE, CAN_E_UNINIT);
#endif
    }
    else if (Can_LocCfgPtr->CanChannelNum <= Controller)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the function parameters <Controller>
        Trace : SWS_Can_ */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_ABORT_CONTROLLER_PENDING_MESSAGE, CAN_E_PARAM_CONTROLLER);
#endif
    }
    else if (Can_LocInstState[Controller] != CAN_CS_STARTED)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            /* Check the driver State
               Trace : SWS_Can_00 */
            (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                        CAN_SID_ABORT_CONTROLLER_PENDING_MESSAGE, CAN_E_TRANSITION);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(Can_Lld_AbortPendingMsg, &Can_LocCfgPtr->CanChCfgPtr[Controller]);
#else
        Can_Lld_AbortPendingMsg(&Can_LocCfgPtr->CanChCfgPtr[Controller]);
#endif
        RetVal = (Std_ReturnType)E_OK;
    }
    return RetVal;
}
#endif

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if 0
CAN_FUNC LOCAL_INLINE Std_ReturnType Can_LocConfigParaCheck(void)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    if(0U < Can_LocCfgPtr->CanChannelNum)
    {
        RetVal = (Std_ReturnType)E_OK;
    }
    return RetVal;
}
#endif

CAN_FUNC LOCAL_INLINE void Can_LocInitAllCanController(void)
{
    for (uint8 ChnIdIndex = 0U; ChnIdIndex < Can_LocCfgPtr->CanChannelNum; ++ChnIdIndex)
    {
        /* Only initializes the CAN controller which was acticatived */
        if (TRUE == Can_LocCfgPtr->CanChCfgPtr[ChnIdIndex].CanChActivation)
        {

#ifdef CAN_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call1param(Can_Lld_DisableInterrupts, ChnIdIndex);
#else
            Can_Lld_DisableInterrupts(ChnIdIndex);
#endif
            Can_LocInstIntState[ChnIdIndex] = FALSE;/*NOSONAR,There are no memory overruns here*/
            Can_LocCurrentBdr[ChnIdIndex] = Can_LocCfgPtr->CanChCfgPtr[ChnIdIndex].DefaultBdrConfig; /*NOSONAR,There are no memory overruns here*/
            /* The function Can_Init shall initialize all CAN controllers according to their
               configuration
               Trace : SWS_Can_00245 */
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
            if((Std_ReturnType)E_OK == \
            OsIf_Trusted_Call_Return2param(Can_Lld_ChnInit, ChnIdIndex, Can_LocCurrentBdr[ChnIdIndex]))
#else
            if((Std_ReturnType)E_OK == Can_Lld_ChnInit(ChnIdIndex, Can_LocCurrentBdr[ChnIdIndex]))
#endif
            {
                /* The function Can_Init shall set all CAN controllers in the State STOPPED
                      Trace : SWS_CAN_00259 */
                Can_LocInstState[ChnIdIndex] = CAN_CS_STOPPED;
            }
        }
    }
}

CAN_FUNC LOCAL_INLINE boolean Can_LocGetFdFlag(Can_HwHandleType Hth)
{
    boolean RetVal = FALSE;
#if (CAN_FD_USAGE == STD_ON)
    uint8 ChnLogicId = Can_LocCfgPtr->CanHohCfgPtr[Hth].CanChannelId;
    RetVal = Can_LocCfgPtr->CanChCfgPtr[ChnLogicId].FdUsage;
#endif
    return RetVal;
}

CAN_FUNC LOCAL_INLINE Std_ReturnType Can_LocSetInstToStarted(uint8 Controller, Can_ControllerStateType State)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    /** [SWS_Can_00409]
     * When the function Can_SetControllerMode (CAN_CS_STARTED) is entered and the CAN controller is
     * not in state STOPPED it shall detect a invalid state transition (Compare to SWS_Can_00200).
     */
    if(State == CAN_CS_STOPPED)
    {
        /* Re-Init controller SWS_Can_00384 */
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(Can_Lld_DisableInterrupts, Controller);
        RetVal = OsIf_Trusted_Call_Return2param(Can_Lld_ChnInit, Controller, Can_LocCurrentBdr[Controller]);
#else
        Can_Lld_DisableInterrupts(Controller);
        RetVal = Can_Lld_ChnInit(Controller, Can_LocCurrentBdr[Controller]);
#endif
        if((Std_ReturnType)E_OK == RetVal)
        {
#if (CAN_ICOM_USAGE == STD_ON)
            /* The CAN driver shall deactivate Pretended Networking before the CAN
                Controller is started by SetControllerMode
                SWS_Can_00498 */
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call3params(Can_Lld_SetControllerIcom, Controller, (IcomConfigIdType)0U, Can_LocCfgPtr);
#else
            Can_Lld_SetControllerIcom(Controller, (IcomConfigIdType)0U, Can_LocCfgPtr);
#endif
#endif /* #if (CAN_ICOM_USAGE == STD_ON)  */
        }
        if((Std_ReturnType)E_OK == RetVal)
        {
            /* Trace : SWS_Can_00017 */
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
            RetVal = OsIf_Trusted_Call_Return1param(Can_Lld_ModeStoppedToStarted, Controller);
#else
            RetVal = Can_Lld_ModeStoppedToStarted(Controller);
#endif
        }
        if((Std_ReturnType)E_OK == RetVal)
        {
            Can_LocInstState[Controller] = CAN_CS_STARTED;
            /* Enabling of CAN interrupts shall not be executed, when CAN interrupts have
                been disabled by function Can_DisableControllerInterrupts
                Trace : SWS_Can_00425 */
            if ((uint8)0 == Can_LocInstDisableIntLv[Controller])
            {
                /* The function Can_SetControllerMode shall enable interrupts that are
                    needed in the new State
                    Trace : SWS_Can_00196 */
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
                OsIf_Trusted_Call1param(Can_Lld_EnableInterrupts, Controller);
#else
                Can_Lld_EnableInterrupts(Controller);
#endif
                Can_LocInstIntState[Controller] = TRUE;
            }
        }
    }
    else
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the driver State
            Trace : SWS_Can_00200 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                    CAN_SID_SET_CONTROLLER_MODE, CAN_E_TRANSITION);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    return RetVal;
}

CAN_FUNC LOCAL_INLINE Std_ReturnType Can_LocSetInstToStopped(uint8 Controller, Can_ControllerStateType State)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    if(State == CAN_CS_UNINIT)
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the driver State
            Trace : SWS_Can_00200 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                    CAN_SID_SET_CONTROLLER_MODE, CAN_E_TRANSITION);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if(State == CAN_CS_STOPPED)
    {
        RetVal = (Std_ReturnType)E_OK;
        Can_LocInstState[Controller] = CAN_CS_STOPPED;
    }
    else if(State == CAN_CS_SLEEP)
    {
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
        RetVal = OsIf_Trusted_Call_Return1param(Can_Lld_ModeSleepToStopped, Controller);
#else
        RetVal = Can_Lld_ModeSleepToStopped(Controller);
#endif
        if((Std_ReturnType)E_OK == RetVal)
        {
            Can_LocInstState[Controller] = CAN_CS_STOPPED;
        }
    }
    else
    {
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
        RetVal = OsIf_Trusted_Call_Return1param(Can_Lld_ModeStartedToStopped, Controller);
#else
        RetVal = Can_Lld_ModeStartedToStopped(Controller);
#endif
        Can_LocInstState[Controller] = CAN_CS_STOPPED;
    }
    return RetVal;
}

CAN_FUNC LOCAL_INLINE Std_ReturnType Can_LocSetInstToSleep(uint8 Controller, Can_ControllerStateType State)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    /** SWS_Can_00294
     * The function Can_SetControllerMode shall disable the wake-up interrupt, while checking the 
     * wake-up status
     */
    if(State == CAN_CS_STOPPED)
    {
        /* Trace : SWS_Can_00017 */
#ifdef CAN_ENABLE_USER_MODE_SUPPORT
        RetVal = OsIf_Trusted_Call_Return1param(Can_Lld_ModeStoppedToSleep, Controller);
#else
        RetVal = Can_Lld_ModeStoppedToSleep(Controller);
#endif
        if((Std_ReturnType)E_OK == RetVal)
        {
            Can_LocInstState[Controller] = CAN_CS_SLEEP;
        }
    }
    else if(State == CAN_CS_SLEEP)
    {
        RetVal = (Std_ReturnType)E_OK;
        Can_LocInstState[Controller] = CAN_CS_SLEEP;
    }
    else
    {
#if (CAN_DEV_ERROR_DETECT == STD_ON)
        /* Check the driver State
            Trace : SWS_Can_00200 */
        (void)Det_ReportError((uint16)CAN_MODULE_ID, Controller,
                    CAN_SID_SET_CONTROLLER_MODE, CAN_E_TRANSITION);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    return RetVal;
}

/*==================================================================================================
*                                        Back API
==================================================================================================*/
CAN_FUNC uint8 Can_Bak_GetDriveState(void)
{
    return Can_LocDrvState;
}

CAN_FUNC const Can_ConfigType *Can_Bak_GetCfgPtr(void)
{
    return Can_LocCfgPtr;
}

CAN_FUNC void Can_Bak_CallDatalost(uint8 ChnLogicId)
{
    /* Can module shall raise the runtime error CAN_E_DATALOST in case of "overwrite" or
       "overrun" event detection.
       Trace SWS_Can_00395 */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportRuntimeError((uint16)CAN_MODULE_ID, ChnLogicId,
                                      CAN_SID_DATALOST, CAN_E_DATALOST);
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */
}

CAN_FUNC Std_ReturnType Can_Bak_SetCanStatusToStopped(uint8 ChnLogicId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    if(CAN_CS_STARTED == Can_LocInstState[ChnLogicId])
    {
        Can_LocInstState[ChnLogicId] = CAN_CS_STOPPED;
        Can_LocStateChanged[ChnLogicId] = TRUE;
        Can_LocInstIntState[ChnLogicId] = FALSE;
        RetVal = (Std_ReturnType)E_OK;
    }
    return RetVal;
}

CAN_FUNC uint8 Can_Bak_GetCanInstIdByHrh(Can_HwHandleType Hrh)
{
    return Can_LocCfgPtr->CanHohCfgPtr[Hrh].CanChannelId;
}

CAN_FUNC boolean Can_Bak_GetInterruptState(uint8 ChnLogicId)
{
    return Can_LocInstIntState[ChnLogicId];
}

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */

