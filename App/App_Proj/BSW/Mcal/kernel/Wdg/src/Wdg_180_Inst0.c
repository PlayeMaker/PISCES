/**
 * @file    Wdg_180_Inst0.c
 * @version V0.9.1
 *
 * @brief   YUNTU Wdg_180_Inst0 module interface
 * @details API implementation for Wdg_180_Inst0 driver
 *
 * @addtogroup WDG_180_INST0_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : WDG
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V0.9.1
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                          INCLUDE FILES
==================================================================================================*/
#include "Wdg_180_Inst0.h"
#include "Wdg_180_Inst0_Types.h"
#include "SchM_Wdg_180_Inst0.h"
#include "Wdg_Lld.h"
#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
#include "Gpt.h"
#endif
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#if (WDG_180_INST0_DISABLE_DEM == STD_OFF)
#include "Dem.h"
#endif
#if (WDG_180_INST0_USER_MODE_SUPPORT == STD_ON)
#include "OsIf.h"
#endif

#ifdef WDG_180_INST0_ENABLE
#if (WDG_180_INST0_ENABLE == STD_ON)

/*==================================================================================================
 *                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_180_INST0_VENDOR_ID_C                      (180)
#define WDG_180_INST0_AR_RELEASE_MAJOR_VERSION_C       (4)
#define WDG_180_INST0_AR_RELEASE_MINOR_VERSION_C       (4)
#define WDG_180_INST0_AR_RELEASE_REVISION_VERSION_C    (0)
#define WDG_180_INST0_SW_MAJOR_VERSION_C               (0)
#define WDG_180_INST0_SW_MINOR_VERSION_C               (9)
#define WDG_180_INST0_SW_PATCH_VERSION_C               (1)

/*==================================================================================================
 *                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Wdg_180_Inst0.c and Wdg_180_Inst0.h are of the same vendor */
#if (WDG_180_INST0_VENDOR_ID_C != WDG_180_INST0_VENDOR_ID)
#error "Wdg_180_Inst0.c and Wdg_180_Inst0.h have different vendor ids"
#endif

/* Check if Wdg_180_Inst0.c and Wdg_180_Inst0.h are of the same Autosar version */
#if ((WDG_180_INST0_AR_RELEASE_MAJOR_VERSION_C != WDG_180_INST0_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_180_INST0_AR_RELEASE_MINOR_VERSION_C != WDG_180_INST0_AR_RELEASE_MINOR_VERSION) || \
     (WDG_180_INST0_AR_RELEASE_REVISION_VERSION_C != WDG_180_INST0_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_180_Inst0.c and Wdg_180_Inst0.h are different"
#endif

/* Check if Wdg_180_Inst0.c and Wdg_180_Inst0.h are of the same Software version */
#if ((WDG_180_INST0_SW_MAJOR_VERSION_C != WDG_180_INST0_SW_MAJOR_VERSION) || \
     (WDG_180_INST0_SW_MINOR_VERSION_C != WDG_180_INST0_SW_MINOR_VERSION) || \
     (WDG_180_INST0_SW_PATCH_VERSION_C != WDG_180_INST0_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_180_Inst0.c and Wdg_180_Inst0.h are different"
#endif

/* Check if Wdg_180_Inst0.c and Wdg_180_Inst0_Types.h are of the same vendor */
#if (WDG_180_INST0_VENDOR_ID_C != WDG_180_INST0_TYPES_VENDOR_ID)
#error "Wdg_180_Inst0.c and Wdg_180_Inst0_Types.h have different vendor ids"
#endif

/* Check if Wdg_180_Inst0.c and Wdg_180_Inst0_Types.h are of the same Autosar version */
#if ((WDG_180_INST0_AR_RELEASE_MAJOR_VERSION_C != WDG_180_INST0_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_180_INST0_AR_RELEASE_MINOR_VERSION_C != WDG_180_INST0_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_180_INST0_AR_RELEASE_REVISION_VERSION_C != WDG_180_INST0_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_180_Inst0.c and Wdg_180_Inst0_Types.h are different"
#endif

/* Check if Wdg_180_Inst0.c and Wdg_180_Inst0_Types.h are of the same Software version */
#if ((WDG_180_INST0_SW_MAJOR_VERSION_C != WDG_180_INST0_TYPES_SW_MAJOR_VERSION) || \
     (WDG_180_INST0_SW_MINOR_VERSION_C != WDG_180_INST0_TYPES_SW_MINOR_VERSION) || \
     (WDG_180_INST0_SW_PATCH_VERSION_C != WDG_180_INST0_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_180_Inst0.c and Wdg_180_Inst0_Types.h are different"
#endif

/*==================================================================================================
 *                                        LOCAL CONSTANTS
==================================================================================================*/
#define WDG_180_INST0_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"

/**
 * @brief   Configuration pointer for the WDG driver
 */
WDG_180_INST0_VAR static const Wdg_180_Inst0_ConfigType *Wdg_180_Inst0_ConfigPtr;

#define WDG_180_INST0_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"           /* NOSONAR, memory map */

/*==================================================================================================
 *                                        LOCAL VARIABLES
==================================================================================================*/
#define WDG_180_INST0_START_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"           /* NOSONAR, memory map */

/**
 * @brief   Variable that indicates the last Wdg Mode
 */
WDG_180_INST0_VAR static WdgIf_ModeType Wdg_180_Inst0_PreviousMode = WDGIF_OFF_MODE;

#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief   Status of the WDG driver
 */
WDG_180_INST0_VAR static Wdg_180_Inst0_StatusType Wdg_180_Inst0_Status = WDG_180_INST0_UNINIT;

#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
/**
 * @brief   Variable that indicates the current Wdg Mode
 */
WDG_180_INST0_VAR static WdgIf_ModeType Wdg_180_Inst0_CurrentMode = WDGIF_OFF_MODE;
#endif /* #if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF) */
#endif /* #if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON) */

#define WDG_180_INST0_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"

#define WDG_180_INST0_START_SEC_VAR_CLEARED_32
#include "Wdg_180_Inst0_MemMap.h"

#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
/**
 * @brief   Timeout value for the trigger counter
 */
WDG_180_INST0_VAR static uint32 Wdg_180_Inst0_Timeout;
#endif /* #if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF) */

#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
/**
 * @brief   Gpt period value
 */
WDG_180_INST0_VAR static uint32 Wdg_180_Inst0_GptPeriod;
#endif /* #if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF) */

#define WDG_180_INST0_STOP_SEC_VAR_CLEARED_32
#include "Wdg_180_Inst0_MemMap.h"

/*==================================================================================================
 *                                        LOCAL FUNCTIONS
==================================================================================================*/
#if (WDG_180_INST0_RUN_ON_ROM == STD_ON)
#define WDG_180_INST0_START_SEC_CODE
#else
#define WDG_180_INST0_START_SEC_RAMCODE
#endif
#include "Wdg_180_Inst0_MemMap.h"           /* NOSONAR, memory map */

#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief       This function validates the global call
 * @details     This service is a non reentrant function used for validating the calls for functions
 *              that uses all the channels - Wdg_Init, Wdg_SetTriggerCondition, Wdg_SetMode.
 * @param[in]   ServiceId ID of the service
 * @return      Std_ReturnType
 * @retval      E_OK The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 */
WDG_180_INST0_FUNC static Std_ReturnType Wdg_Inst0_ValidateGlobalCall(uint8 ServiceId)
{
    Std_ReturnType Ret = E_NOT_OK;

    /* SWS_Wdg_00040 */
    SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_00();
    if (((WDG_180_INST0_UNINIT == Wdg_180_Inst0_Status) && (WDG_180_INST0_SID_INIT != ServiceId)) ||
            (WDG_180_INST0_INITIALIZING == Wdg_180_Inst0_Status) ||
            (WDG_180_INST0_BUSY == Wdg_180_Inst0_Status))
    {
        SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_00();
        /* SWS_Wdg_00035 */
        (void)Det_ReportError
        (
            (uint16)WDG_180_INST0_MODULE_ID,
            WDG_180_INST0_INDEX,
            ServiceId,
            (uint8)WDG_180_INST0_E_DRIVER_STATE
        );
    }
    else
    {
        if (WDG_180_INST0_SID_INIT == ServiceId)
        {
            Wdg_180_Inst0_Status = WDG_180_INST0_INITIALIZING;
        }
        else
        {
            /* SWS_Wdg_00052 */
            Wdg_180_Inst0_Status = WDG_180_INST0_BUSY;
        }
        SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_00();
        Ret = E_OK;
    }

    return Ret;
}
#endif /* #if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON) */

#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief       This function ends the validation of the global call.
 * @details     This service is a non reentrant function used for end the validation the calls for
 *              functions that uses all the channels - Wdg_Init, Wdg_SetTriggerCondition,
 *              Wdg_SetMode.
 * @param[in]   Status Status of the service
 * @return      void
 */
WDG_180_INST0_FUNC static void Wdg_Inst0_EndValidateGlobalCall(Std_ReturnType Status)
{
    /* SWS_Wdg_00040 */
    SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_01();
    /* SWS_Wdg_00052 */
    if ((Std_ReturnType)E_OK == Status)
    {
        Wdg_180_Inst0_Status = WDG_180_INST0_IDLE;
    }
    else
    {
        if (WDG_180_INST0_BUSY == Wdg_180_Inst0_Status)
        {
            Wdg_180_Inst0_Status = WDG_180_INST0_IDLE;
        }
        else
        {
            if (NULL_PTR == Wdg_180_Inst0_ConfigPtr)
            {
                Wdg_180_Inst0_Status = WDG_180_INST0_UNINIT;
            }
            else
            {
                Wdg_180_Inst0_Status = WDG_180_INST0_IDLE;
            }
        }
    }
    SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_01();
}
#endif /* #if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON) */

#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief       Validates the pointer to the configuration structure
 * @details     This function validates the pointer to the configuration structure
 * @param[in]   ConfigPtr Pointer to the configuration structure
 * @return      Std_ReturnType
 * @retval      E_OK The pointer to the configuration structure is valid
 * @retval      E_NOT_OK The pointer to the configuration structure is invalid
 */
WDG_180_INST0_FUNC static Std_ReturnType Wdg_Inst0_ValidatePtrInit(const Wdg_180_Inst0_ConfigType *const ConfigPtr)
{
    Std_ReturnType Ret = E_OK;

#if (WDG_180_INST0_PRECOMPILE_SUPPORT == STD_ON)
    if (NULL_PTR != ConfigPtr)
#else
    if (NULL_PTR == ConfigPtr)
#endif
    {
        (void)Det_ReportError
        (
            (uint16)WDG_180_INST0_MODULE_ID,
            WDG_180_INST0_INDEX,
            (uint8)WDG_180_INST0_SID_INIT,
            (uint8)WDG_180_INST0_E_INIT_FAILED
        );
        Ret = E_NOT_OK;
    }
    return Ret;
}
#endif /* #if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON) */

/**
 * @brief       Validates the mode
 * @details     This function validates the mode
 * @param[in]   Mode Mode to be validated
 * @param[in]   ServiceId ID of the service
 * @param[in]   ErrorId ID of the error
 * @return      Std_ReturnType
 * @retval      E_OK The mode is valid
 * @retval      E_NOT_OK The mode is invalid
 */
WDG_180_INST0_FUNC static Std_ReturnType Wdg_Inst0_ValidateMode
(
    WdgIf_ModeType Mode,
    uint8 ServiceId,
    uint8 ErrorId
)
{
    Std_ReturnType Ret = E_OK;
    boolean DisableRejectedErrActive = (boolean)FALSE;
    boolean ModeFailedErrActive = (boolean)FALSE;

#if (WDG_180_INST0_DISABLE_ALLOWED == STD_OFF)
    /* SWS_Wdg_00026 */
    if (WDGIF_OFF_MODE == Mode)
    {
        DisableRejectedErrActive = TRUE;
        Ret = E_NOT_OK;
    }
#endif
    /* Some peripherals (e.g. EWDG) do not support all modes, so this corresponding struct member
     * is generated as NULL.
     */
    if ((!((WDGIF_OFF_MODE == Mode) || (WDGIF_FAST_MODE == Mode) || (WDGIF_SLOW_MODE == Mode))) ||
            (NULL_PTR == Wdg_180_Inst0_ConfigPtr->ModeSettings[Mode]))
    {
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)WDG_180_INST0_MODULE_ID,
            WDG_180_INST0_INDEX,
            ServiceId,
            ErrorId
        );
#else
        (void)ServiceId;
        (void)ErrorId;
#endif
        ModeFailedErrActive = (boolean)TRUE;
        Ret = E_NOT_OK;
    }

#if (WDG_180_INST0_DISABLE_DEM == STD_OFF)
    if (STD_ON == Wdg_180_Inst0_E_Disable_Rejected.State)
    {
#if (WDG_180_INST0_DISABLE_ALLOWED == STD_OFF)
        /* SWS_Wdg_00182, SWS_Wdg_00183 */
        if (TRUE == DisableRejectedErrActive)
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_180_Inst0_E_Disable_Rejected.Id, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_180_Inst0_E_Disable_Rejected.Id, DEM_EVENT_STATUS_PASSED);
        }
#else
        (void)DisableRejectedErrActive;
#endif /* #if (WDG_180_INST0_DISABLE_ALLOWED == STD_OFF) */
    }
    /* SWS_Wdg_00180, SWS_Wdg_00181 */
    if (STD_ON == Wdg_180_Inst0_E_Mode_Failed.State)
    {
        if (TRUE == ModeFailedErrActive)
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_180_Inst0_E_Mode_Failed.Id, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_180_Inst0_E_Mode_Failed.Id, DEM_EVENT_STATUS_PASSED);
        }
    }
#else
    (void)ModeFailedErrActive;
    (void)DisableRejectedErrActive;
#endif /* #if (WDG_180_INST0_DISABLE_DEM == STD_OFF) */

    return Ret;
} /* Wdg_Inst_ValidateMode */

/**
 * @brief       Validates the hardware settings
 * @details     This function validates the hardware settings
 * @param[in]   Status Status of the hardware settings
 * @return      void
 */
WDG_180_INST0_FUNC static void Wdg_Inst0_ValidateHwInit(Std_ReturnType Status)
{
    if ((Std_ReturnType)E_NOT_OK == Status)
    {
        /* Hardware settings are not valid */
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError
        (
            (uint16)WDG_180_INST0_MODULE_ID,
            WDG_180_INST0_INDEX,
            (uint8)WDG_180_INST0_SID_INIT,
            (uint8)WDG_180_INST0_E_PARAM_MODE
        );
#endif
#if (WDG_180_INST0_DISABLE_DEM == STD_OFF)
        /* SWS_Wdg_00180 */
        if (STD_ON == Wdg_180_Inst0_E_Mode_Failed.State)
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_180_Inst0_E_Mode_Failed.Id, DEM_EVENT_STATUS_FAILED);
        }
#endif
        Wdg_180_Inst0_ConfigPtr = NULL_PTR;
    }
    else
    {
        /* Hardware settings are valid */
#if (WDG_180_INST0_DISABLE_DEM == STD_OFF)
        /* SWS_Wdg_00181 */
        if (STD_ON == Wdg_180_Inst0_E_Mode_Failed.State)
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_180_Inst0_E_Mode_Failed.Id, DEM_EVENT_STATUS_PASSED);
        }
#endif
    }
}

#if ((WDG_180_INST0_DEV_ERROR_DETECT == STD_ON) && (WDG_180_INST0_VERSION_INFO_API == STD_ON))
/**
 * @brief       Validates the pointer to the version info
 * @details     This function validates the pointer to the version info
 * @param[in]   VersionInfo Pointer to the version info
 * @return      Std_ReturnType
 * @retval      E_OK Pointer is valid
 * @retval      E_NOT_OK Pointer is not valid
 */
WDG_180_INST0_FUNC static Std_ReturnType Wdg_Inst0_ValidatePtrVersion(const Std_VersionInfoType *VersionInfo)
{
    Std_ReturnType Ret = E_OK;

    if (NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError
        (
            (uint16)WDG_180_INST0_MODULE_ID,
            WDG_180_INST0_INDEX,
            (uint8)WDG_180_INST0_SID_GET_VERSION_INFO,
            (uint8)WDG_180_INST0_E_PARAM_POINTER
        );
        Ret = E_NOT_OK;
    }

    return Ret;
}
#endif /* #if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON) && (WDG_180_INST0_VERSION_INFO_API == STD_ON) */

#if ((WDG_180_INST0_MANUAL_SERVICE == STD_OFF) && (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON))
/**
 * @brief       This function validates the call of Wdg_ChannelSetTriggerCondition function.
 * @details     This service is a function used for validating the calls for
                Wdg_ChannelSetTriggerCondition.
 * @return      Std_ReturnType
 * @retval      E_OK The call is valid
 * @retval      E_NOT_OK The call is not valid
 */
WDG_180_INST0_FUNC static Std_ReturnType Wdg_Inst0_ValidateTriggerCondition(void)
{
    Std_ReturnType Ret = E_OK;

    /* SWS_Wdg_00040 */
    SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_02();
    if ((WDG_180_INST0_UNINIT == Wdg_180_Inst0_Status) ||
            (WDG_180_INST0_INITIALIZING == Wdg_180_Inst0_Status))
    {
        SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_02();
        /* SWS_Wdg_00035 */
        (void)Det_ReportError
        (
            (uint16)WDG_180_INST0_MODULE_ID,
            WDG_180_INST0_INDEX,
            (uint8)WDG_180_INST0_SID_SET_TRIGGER_CONDITION,
            (uint8)WDG_180_INST0_E_DRIVER_STATE
        );
        Ret = E_NOT_OK;
    }
    else
    {
        SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_02();
    }

    return Ret;
}
#endif /* #if ((WDG_180_INST0_MANUAL_SERVICE == STD_OFF) && (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)) */

#if ((WDG_180_INST0_MANUAL_SERVICE == STD_OFF) && (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON))
/**
 * @brief       This function validates the timeout value.
 * @details     This service is a function used for validating the timeout value.
 * @param[in]   Timeout Timeout value
 * @return      Std_ReturnType
 * @retval      E_OK The call is valid
 * @retval      E_NOT_OK The call is not valid
 */
WDG_180_INST0_FUNC static Std_ReturnType Wdg_Inst0_ValidateTimeout(uint16 Timeout)
{
    Std_ReturnType Ret = E_OK;

    if (Timeout > WDG_180_INST0_MAX_TIMEOUT)
    {
        (void)Det_ReportError
        (
            (uint16)WDG_180_INST0_MODULE_ID,
            WDG_180_INST0_INDEX,
            (uint8)WDG_180_INST0_SID_SET_TRIGGER_CONDITION,
            (uint8)WDG_180_INST0_E_PARAM_TIMEOUT
        );
        Ret = E_NOT_OK;
    }

    return Ret;
}
#endif /* #if ((WDG_180_INST0_MANUAL_SERVICE == STD_OFF) && (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)) */

/**
 * @brief       Initializes the WDG hardware
 * @details     This function initializes the WDG hardware
 * @return      Std_ReturnType
 * @retval      E_OK The hardware was initialized successfully
 * @retval      E_NOT_OK The hardware was not initialized successfully
 */
WDG_180_INST0_FUNC static Std_ReturnType Wdg_Inst0_InitHw(void)
{
    Std_ReturnType Ret;

    if (WDGIF_OFF_MODE == Wdg_180_Inst0_ConfigPtr->DefaultMode)
    {
#if (WDG_180_INST0_DISABLE_ALLOWED == (STD_ON))
#if (WDG_180_INST0_USER_MODE_SUPPORT == STD_ON)
        Ret = (Std_ReturnType)OsIf_Trusted_Call_Return2param
              (
                  Wdg_Lld_Config,
                  (uint8)0U,
                  Wdg_180_Inst0_ConfigPtr->ModeSettings[Wdg_180_Inst0_ConfigPtr->DefaultMode]->WdgConfig
              );
#else
        Ret = Wdg_Lld_Config((uint8)0U, Wdg_180_Inst0_ConfigPtr->ModeSettings[Wdg_180_Inst0_ConfigPtr->DefaultMode]->WdgConfig);
#endif
#else
        Ret = E_NOT_OK;
#endif
    }
    else
    {
#if (WDG_180_INST0_USER_MODE_SUPPORT == STD_ON)
        Ret = (Std_ReturnType)OsIf_Trusted_Call_Return2param
              (
                  Wdg_Lld_Init,
                  (uint8)0U,
                  Wdg_180_Inst0_ConfigPtr->ModeSettings[Wdg_180_Inst0_ConfigPtr->DefaultMode]->WdgConfig
              );
#else
        Ret = Wdg_Lld_Init((uint8)0U, Wdg_180_Inst0_ConfigPtr->ModeSettings[Wdg_180_Inst0_ConfigPtr->DefaultMode]->WdgConfig);
#endif
    }

    return Ret;
}

#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
/**
 * @brief       Starts the GPT timer
 * @details     This function starts the GPT timer
 * @return      void
 */
WDG_180_INST0_FUNC static void Wdg_Inst0_StartGpt(void)
{
    Gpt_StopTimer(Wdg_180_Inst0_ConfigPtr->TimerChannel);

    /* SWS_Wdg_00040 */
    Wdg_180_Inst0_GptPeriod = Wdg_180_Inst0_ConfigPtr->ModeSettings[Wdg_180_Inst0_ConfigPtr->DefaultMode]->TriggerPeriod;

    Gpt_EnableNotification(Wdg_180_Inst0_ConfigPtr->TimerChannel);
    /* Start the timer channel only if the mode is not off mode. */
    if (WDGIF_OFF_MODE != Wdg_180_Inst0_ConfigPtr->DefaultMode)
    {
        Gpt_StartTimer(Wdg_180_Inst0_ConfigPtr->TimerChannel, Wdg_180_Inst0_GptPeriod);
    }

    /* SWS_Wdg_00040 */
    SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_03();
    Wdg_180_Inst0_Timeout = (Wdg_180_Inst0_InitialTimeoutCfg * Wdg_180_Inst0_ConfigPtr->TriggerSourceClock);
    SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_03();
}
#endif /* #if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF) */

/**
 * @brief       This function sets the mode of the WDG driver.
 * @details     This service is a function used for setting the mode of the WDG driver.
 * @param[in]   Mode WDGIF_OFF_MODE or WDGIF_SLOW_MODE or WDGIF_FAST_MODE
 * @return      Std_ReturnType
 * @retval      E_OK The call is valid
 * @retval      E_NOT_OK The call is not valid
 */
WDG_180_INST0_FUNC static Std_ReturnType Wdg_Inst0_DoSetMode(WdgIf_ModeType Mode)
{
    Std_ReturnType Ret;

    /* SWS_Wdg_00031 */
    if (WDGIF_OFF_MODE == Mode)
    {
#if (WDG_180_INST0_DISABLE_ALLOWED == STD_ON)
#if (WDG_180_INST0_USER_MODE_SUPPORT == STD_ON)
        Ret = (Std_ReturnType)OsIf_Trusted_Call_Return1param
              (
                  Wdg_Lld_StopTimer,
                  (uint8)0U
              );
#else
        Ret = Wdg_Lld_StopTimer(0U);
#endif

        if (E_OK == Ret)
        {
#if (WDG_180_INST0_USER_MODE_SUPPORT == STD_ON)
            Ret = (Std_ReturnType)OsIf_Trusted_Call_Return2param
                  (
                      Wdg_Lld_Config,
                      (uint8)0U,
                      Wdg_180_Inst0_ConfigPtr->ModeSettings[Mode]->WdgConfig
                  );
#else
            Ret = Wdg_Lld_Config((uint8)0U, Wdg_180_Inst0_ConfigPtr->ModeSettings[Mode]->WdgConfig);
#endif
        }
#else
        Ret = E_NOT_OK;
#endif
    }
    else
    {
#if (WDG_180_INST0_USER_MODE_SUPPORT == STD_ON)
        Ret = (Std_ReturnType)OsIf_Trusted_Call_Return2param
              (
                  Wdg_Lld_Config,
                  (uint8)0U,
                  Wdg_180_Inst0_ConfigPtr->ModeSettings[Mode]->WdgConfig
              );
#else
        Ret = Wdg_Lld_Config((uint8)0U, Wdg_180_Inst0_ConfigPtr->ModeSettings[Mode]->WdgConfig);
#endif
        /* If the Wdg was in OFF Mode, the Wdg needs to be initialized again. */
        if ((E_OK == Ret) && (WDGIF_OFF_MODE == Wdg_180_Inst0_PreviousMode))
        {
#if (WDG_180_INST0_USER_MODE_SUPPORT == STD_ON)
            Ret = (Std_ReturnType)OsIf_Trusted_Call_Return1param
                  (
                      Wdg_Lld_StartTimer,
                      (uint8)0U
                  );
#else
            Ret = Wdg_Lld_StartTimer(0U);
#endif
        }
    }

    return Ret;
}

/**
 * @brief       This function validates the channel mode setting for wdg.
 * @param[in]   Mode WDGIF_OFF_MODE or WDGIF_SLOW_MODE or WDGIF_FAST_MODE
 * @param[in]   Status E_OK or E_NOT_OK
 * @return      Std_ReturnType
 * @retval      E_OK The call is valid
 * @retval      E_NOT_OK The call is not valid
 */
WDG_180_INST0_FUNC static Std_ReturnType Wdg_Inst0_ValidateDoSetMode
(
    WdgIf_ModeType Mode,
    Std_ReturnType Status
)
{
    Std_ReturnType Ret = E_NOT_OK;

#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
    Gpt_ValueType ElapsedTime;
    uint32 Temp;
#endif

    if ((Std_ReturnType)E_NOT_OK == Status)
    {
        /* Hardware settings are not valid */
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
        /* SWS_Wdg_00091, SWS_Wdg_00092 */
        (void)Det_ReportError
        (
            (uint16)WDG_180_INST0_MODULE_ID,
            WDG_180_INST0_INDEX,
            (uint8)WDG_180_INST0_SID_SET_MODE,
            (uint8)WDG_180_INST0_E_PARAM_MODE
        );
#endif

#if (WDG_180_INST0_DISABLE_DEM == STD_OFF)
        if (STD_ON == Wdg_180_Inst0_E_Mode_Failed.State)
        {
            /* SWS_Wdg_00016 */
            (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_180_Inst0_E_Mode_Failed.Id, DEM_EVENT_STATUS_FAILED);
        }
#endif
    }
    else
    {
        /* Hardware settings are valid */
#if (WDG_180_INST0_DISABLE_DEM == STD_OFF)
        if (STD_ON == Wdg_180_Inst0_E_Mode_Failed.State)
        {
            (void)Dem_SetEventStatus((Dem_EventIdType)Wdg_180_Inst0_E_Mode_Failed.Id, DEM_EVENT_STATUS_PASSED);
        }
#endif

#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
        Gpt_StopTimer(Wdg_180_Inst0_ConfigPtr->TimerChannel);
        ElapsedTime =  Gpt_GetTimeElapsed(Wdg_180_Inst0_ConfigPtr->TimerChannel);
        /* Update timeout */
        /* SWS_Wdg_00040 */
        SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_04();
        if (Wdg_180_Inst0_Timeout < ElapsedTime)
        {
            Temp = 0;
        }
        else
        {
            Temp = Wdg_180_Inst0_Timeout - ElapsedTime;
        }
        Wdg_180_Inst0_Timeout = Temp;
        Wdg_180_Inst0_GptPeriod = Wdg_180_Inst0_ConfigPtr->ModeSettings[Mode]->TriggerPeriod;
        SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_04();
        /* Start the timer only if the mode is not off mode*/
        if (WDGIF_OFF_MODE != Mode)
        {
            /* Enable interrupt of Gpt channel */
            Gpt_EnableNotification(Wdg_180_Inst0_ConfigPtr->TimerChannel);
            /* Start the Gpt channel. */
            Gpt_StartTimer(Wdg_180_Inst0_ConfigPtr->TimerChannel, Wdg_180_Inst0_GptPeriod);
        }
#endif
        /* SWS_Wdg_00103 */
        Ret = E_OK;
        /* Remember the last Wdg Mode */
        Wdg_180_Inst0_PreviousMode = Mode;
    }

    return Ret;
} /* Wdg_Inst0_ValidateDoSetMode */


/*==================================================================================================
 *                                   GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/
#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
/**
 * @brief       Wdg callback function for GPT notification.
 * @return      void
 */
WDG_180_INST0_FUNC void Wdg_180_Inst0_Cbk_GptNotification(void);
#endif

/*==================================================================================================
 *                                        GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief       Initializes the WDG module.
 * @param[in]   ConfigPtr Pointer to configuration set
 * @return      void
 */
WDG_180_INST0_FUNC void Wdg_180_Inst0_Init(const Wdg_180_Inst0_ConfigType *ConfigPtr)
{
    Std_ReturnType Ret;

#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
    Ret = Wdg_Inst0_ValidateGlobalCall(WDG_180_INST0_SID_INIT);
    if (E_OK == Ret)
#endif
    {
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
        /* SWS_Wdg_00086, SWS_Wdg_00090 */
        Ret = Wdg_Inst0_ValidatePtrInit(ConfigPtr);
        if (E_OK == Ret)
#endif
        {
            /* SWS_Wdg_00001 */
#if (WDG_180_INST0_PRECOMPILE_SUPPORT == STD_ON)
            (void)ConfigPtr;
            Wdg_180_Inst0_ConfigPtr = Wdg_Inst0_Config;
#else
            Wdg_180_Inst0_ConfigPtr = ConfigPtr;
#endif
#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
            /* SWS_Wdg_00100 */
            Wdg_180_Inst0_CurrentMode = Wdg_180_Inst0_ConfigPtr->DefaultMode;
#endif
            /* Wdg needs to have been in OFF Mode in order to be initialized. */
            if ((WDGIF_OFF_MODE == Wdg_180_Inst0_PreviousMode) &&
                    (Wdg_180_Inst0_InitialTimeoutCfg > 0U))
#else
            if (WDGIF_OFF_MODE == Wdg_180_Inst0_PreviousMode)
#endif
            {
                /* SWS_Wdg_00025, SWS_Wdg_00173 */
                Ret = Wdg_Inst0_ValidateMode
                      (
                          Wdg_180_Inst0_ConfigPtr->DefaultMode,
                          WDG_180_INST0_SID_INIT,
                          WDG_180_INST0_E_PARAM_MODE
                      );
            }
            else
            {
                Ret = E_NOT_OK;
            }
            if (E_OK == Ret)
            {
                /* SWS_Wdg_00001, SWS_Wdg_00101 */
                Ret = Wdg_Inst0_InitHw();
                Wdg_Inst0_ValidateHwInit(Ret);
                if (E_OK == Ret)
                {
                    /* Hardware settings are valid */
#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
                    /* SWS_Wdg_00100 */
                    Wdg_Inst0_StartGpt();
#endif
                    /* SWS_Wdg_00100, Remember the last Wdg Mode */
                    Wdg_180_Inst0_PreviousMode = Wdg_180_Inst0_ConfigPtr->DefaultMode;
                }
            }
        }
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
        /* SWS_Wdg_00019 */
        Wdg_Inst0_EndValidateGlobalCall(Ret);
#endif
    }
}

/**
 * @brief       Switches the watchdog into the mode Mode.
 * @param[in]   Mode WDGIF_OFF_MODE, WDGIF_SLOW_MODE, WDGIF_FAST_MODE
 * @return      Std_ReturnType
 * @retval      E_OK Mode switch was successful.
 * @retval      E_NOT_OK Mode switch was not successful.
 */
WDG_180_INST0_FUNC Std_ReturnType Wdg_180_Inst0_SetMode(WdgIf_ModeType Mode)
{
    Std_ReturnType Ret;

#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
    /* SWS_Wdg_00017 */
    Ret = Wdg_Inst0_ValidateGlobalCall(WDG_180_INST0_SID_SET_MODE);
    if (E_OK == Ret)
#endif
    {
        /* SWS_Wdg_00091, SWS_Wdg_00092 */
        Ret = Wdg_Inst0_ValidateMode(Mode, WDG_180_INST0_SID_SET_MODE, WDG_180_INST0_E_PARAM_MODE);
        if (E_OK == Ret)
        {
#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
            Wdg_180_Inst0_CurrentMode = Mode;
#endif
#endif
            /* SWS_Wdg_00160 */
            Ret = Wdg_Inst0_DoSetMode(Mode);
            /* SWS_Wdg_00145 */
            Ret = Wdg_Inst0_ValidateDoSetMode(Mode, Ret);
        }
    }
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
    /* SWS_Wdg_00018 */
    Wdg_Inst0_EndValidateGlobalCall(Ret);
#endif

    return Ret;
}

#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
/**
 * @brief       Sets the timeout value for the trigger counter.
 * @param[in]   Timeout Timeout value (milliseconds) for setting the trigger counter.
 * @return      void
 */
WDG_180_INST0_FUNC void Wdg_180_Inst0_SetTriggerCondition(uint16 Timeout)
{
    Gpt_ValueType ElapsedTime;

#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Ret;

    Ret = Wdg_Inst0_ValidateTriggerCondition();
    if (E_OK == Ret)
#endif
    {
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
        /* SWS_Wdg_00146 */
        Ret =  Wdg_Inst0_ValidateTimeout(Timeout);
        if (E_OK == Ret)
#endif
        {
            /* SWS_Wdg_00040 */
            SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_05();
            ElapsedTime = Gpt_GetTimeElapsed(Wdg_180_Inst0_ConfigPtr->TimerChannel);
            /* SWS_Wdg_00136 */
            if ((ElapsedTime > Wdg_180_Inst0_Timeout) || (0U == Timeout))
            {
                /* SWS_Wdg_00140 */
                Wdg_180_Inst0_Timeout = 0;
                SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_05();
                Gpt_StopTimer(Wdg_180_Inst0_ConfigPtr->TimerChannel);
            }
            else
            {
                /* SWS_Wdg_00136, SWS_Wdg_00138, SWS_Wdg_00139 */
                Wdg_180_Inst0_Timeout =
                    (Timeout * Wdg_180_Inst0_ConfigPtr->TriggerSourceClock) + ElapsedTime;
                SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_05();
            }
        }
    }
}
#endif

#if (WDG_180_INST0_MANUAL_SERVICE == STD_ON)
/**
 * @brief       Refreshes the watchdog timer Manually.
 * @return      void
 */
WDG_180_INST0_FUNC void Wdg_180_Inst0_Service(void)
{
#if (WDG_180_INST0_USER_MODE_SUPPORT == STD_ON)
    OsIf_Trusted_Call1param
    (
        Wdg_Lld_Service,
        0U
    );
#else
    Wdg_Lld_Service((uint8)0U);
#endif
}
#endif

#if (WDG_180_INST0_VERSION_INFO_API == STD_ON)
/**
 * @brief       Returns the version information of the module.
 * @param[out]  VersionInfo Pointer to where to store the version information of this module.
 * @return      void
 */
WDG_180_INST0_FUNC void Wdg_180_Inst0_GetVersionInfo(Std_VersionInfoType *VersionInfo)
{
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Ret;

    /* SWS_Wdg_00174 */
    Ret = Wdg_Inst0_ValidatePtrVersion(VersionInfo);
    if (E_OK == Ret)
#endif
    {
        VersionInfo->vendorID = (uint16)WDG_180_INST0_VENDOR_ID;
        VersionInfo->moduleID = (uint16)WDG_180_INST0_MODULE_ID;
        VersionInfo->sw_major_version = (uint8)WDG_180_INST0_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)WDG_180_INST0_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)WDG_180_INST0_SW_PATCH_VERSION;
    }
}
#endif

#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
/**
 * @brief       Wdg callback function for GPT notification.
 * @return      void
 */
WDG_180_INST0_FUNC void Wdg_180_Inst0_Cbk_GptNotification(void)
{
    uint32 Temp;

#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
    Std_ReturnType Ret;

    Ret = Wdg_Inst0_ValidateGlobalCall(WDG_180_INST0_SID_TRIGGER);
    if (E_OK == Ret)
#endif
    {
        /* SWS_Wdg_00040 */
        SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_06();
        /* SWS_Wdg_00134, SWS_Wdg_00135 */
        if (Wdg_180_Inst0_Timeout < Wdg_180_Inst0_GptPeriod)
        {
            SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_06();
            Gpt_StopTimer(Wdg_180_Inst0_ConfigPtr->TimerChannel);
        }
        else
        {
            Temp = Wdg_180_Inst0_Timeout - Wdg_180_Inst0_GptPeriod;
            Wdg_180_Inst0_Timeout = Temp;

#if (WDG_180_INST0_USER_MODE_SUPPORT == STD_ON)
            OsIf_Trusted_Call1param
            (
                Wdg_Lld_Service,
                (uint8)0U
            );
#else
            Wdg_Lld_Service((uint8)0U);
#endif
            SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_06();
        }
    }
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
    Wdg_Inst0_EndValidateGlobalCall(Ret);
#endif
}
#endif

#if (WDG_180_INST0_RUN_ON_ROM == STD_ON)
#define WDG_180_INST0_STOP_SEC_CODE
#else
#define WDG_180_INST0_STOP_SEC_RAMCODE
#endif
#include "Wdg_180_Inst0_MemMap.h"    /* NOSONAR, memory map */

#endif /* #if (WDG_180_INST0_ENABLE == STD_ON) */
#endif /* #ifdef WDG_180_INST0_ENABLE */

#ifdef __cplusplus
}
#endif

/** @} */

