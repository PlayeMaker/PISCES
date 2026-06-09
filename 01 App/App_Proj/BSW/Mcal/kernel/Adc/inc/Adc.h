/**
 * @file    Adc.h
 * @version
 *
 * @brief   AUTOSAR Adc module interface
 * @details API implementation for ADC driver
 *
 * @addtogroup ADC_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Adc
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

#ifndef ADC_H
#define ADC_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Adc_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section Adc_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Adc_Types.h"
/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID                      (180)
#define ADC_AR_RELEASE_MAJOR_VERSION       (4)
#define ADC_AR_RELEASE_MINOR_VERSION       (4)
#define ADC_AR_RELEASE_REVISION_VERSION    (0)
#define ADC_SW_MAJOR_VERSION               (0)
#define ADC_SW_MINOR_VERSION               (9)
#define ADC_SW_PATCH_VERSION               (1)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ADC configuration header file are of the same vendor */
#if (ADC_VENDOR_ID != ADC_VENDOR_ID_CFG)
#error "Adc.h and Adc_Cfg.h have different vendor ids"
#endif

/* Check if source file and ADC configuration header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_REVISION_VERSION != ADC_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Adc.h and Adc_Cfg.h are different"
#endif

/* Check if source file and ADC configuration header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION_CFG) || \
     (ADC_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION_CFG) || \
     (ADC_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Adc.h and Adc_Cfg.h are different"
#endif

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief ADC MODULE INSTANCE ID */
#define ADC_INSTANCE_ID ((uint8)0U)

/** @brief ADC MODULE ID */
#define ADC_MODULE_ID ((uint8)123)


/**
 * @defgroup        Adc_DEV_ERROR
 * @brief           ADC development errors
 * @{
 */
/** @brief API called when module is not initialized */
#define ADC_E_UNINIT                         (0x0AU)
/** @brief API called while module is busy processing a user request. */
#define ADC_E_BUSY                           (0x0BU)
/** @brief API called while module is is idle. */
#define ADC_E_IDLE                           (0x0CU)
/** @brief API service for initialization called when already initialized. */
#define ADC_E_ALREADY_INITIALIZED            (0x0DU)
/** @brief API service called with wrong configuration. */
#define ADC_E_PARAM_CONFIG                   (0x0EU)
/** @brief API service called with wrong parameter. */
#define ADC_E_PARAM_POINTER                  (0x14U)
/** @brief API service called with invalid group id. */
#define ADC_E_PARAM_GROUP                    (0x15U)
/** @brief API service called with wrong conversion mode. */
#define ADC_E_WRONG_CONV_MODE                (0x16U)
/** @brief API service called with wrong trigger source. */
#define ADC_E_WRONG_TRIGG_SRC                (0x17U)
/** @brief Enable/disable notification function for a group whose configuration set has no notification available. */
#define ADC_E_NOTIF_CAPABILITY               (0x18U)
/** @brief Conversion started and result buffer pointer is not initialized. */
#define ADC_E_BUFFER_UNINIT                  (0x19U)
/** @brief One or more ADC group/channel not in IDLE state */
#define ADC_E_NOT_DISENGAGED                 (0x1AU)
/** @brief Unsupported power state request */
#define ADC_E_POWER_STATE_NOT_SUPPORTED      (0x1BU)
/** @brief Requested power state can not be reached directly */
#define ADC_E_TRANSITION_NOT_POSSIBLE        (0x1CU)
/** @brief ADC not prepared for target power state */
#define ADC_E_PERIPHERAL_NOT_PREPARED        (0x1DU)

/** @} */


/**
 * @defgroup        Adc_SID
 * @brief           Service ID number for all ADC driver services
 */
/** @{ */
/** @brief API Service ID for Adc_Init */
#define ADC_SID_INIT                                (0x00U)
/** @brief API Service ID for Adc_DeInit */
#define ADC_SID_DE_INIT                             (0x01U)
/** @brief API Service ID for Adc_StartGroupConversion */
#define ADC_SID_START_GROUP_CONVERSION              (0x02U)
/** @brief API Service ID for Adc_StopGroupConversion */
#define ADC_SID_STOP_GROUP_CONVERSION               (0x03U)
/** @brief API Service ID for Adc_ReadGroup */
#define ADC_SID_READ_GROUP                          (0x04U)
/** @brief API Service ID for Adc_EnableHardwareTrigger */
#define ADC_SID_ENABLE_HARDWARE_TRIGGER             (0x05U)
/** @brief API Service ID for Adc_DisableHardwareTrigger */
#define ADC_SID_DISABLE_HARDWARE_TRIGGER            (0x06U)
/** @brief API Service ID for Adc_EnableGroupNotification */
#define ADC_SID_ENABLE_GROUP_NOTIFICATION           (0x07U)
/** @brief API Service ID for Adc_DisableGroupNotification */
#define ADC_SID_DISABLE_GROUP_NOTIFICATION          (0x08U)
/** @brief API Service ID for Adc_GetGroupStatus */
#define ADC_SID_GET_GROUP_STATUS                    (0x09U)
/** @brief API Service ID for Adc_GetVersionInfo */
#define ADC_SID_GET_VERSION_INFO                    (0x0AU)
/** @brief API Service ID for Adc_GetStreamLastPointer */
#define ADC_SID_GET_STREAM_LAST_POINTER             (0x0BU)
/** @brief API Service ID for Adc_SetupResultBuffer */
#define ADC_SID_SETUP_RESULT_BUFFER                 (0x0CU)
#if (ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
/** @brief API service ID for Adc_SetPowerState function */
#define ADC_SID_SET_POWER_STATE                     (0x10U)
/** @brief API service ID for Adc_GetCurrentPowerState function */
#define ADC_SID_GET_CURRENT_POWER_STATE             (0x11U)
/** @brief API service ID for Adc_GetTargetPowerState function */
#define ADC_SID_GET_TARGET_POWER_STATE              (0x12U)
/**  @brief API service ID for Adc_PreparePowerState function */
#define ADC_SID_PREPARE_POWER_STATE                 (0x13U)
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */
/** @} */

/**
 * @brief Total number of hardware
 * @note Strong relationship to the hardware
 */
#define ADC_UNIT_TOTAL_NUMBER (uint8)(1U)

/*==================================================================================================
*                                         EXTERNAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/********************************************************************/
/* Global data extern*/
/* Variable Adc_ConfigPtr point to configuration data of ADC units */
extern const Adc_ConfigType *Adc_ConfigPtr;

/*ADC conversion result buffer*/
#if(ADC_FIXED_PB_CONFIG == STD_ON)
extern Adc_GroupResultType     Adc_GroupResult[ADC_GROUP_NUMBER];
#else
extern Adc_GroupResultType     Adc_GroupResult[ADC_MAX_GROUPS];
#endif

/*ADC hw status data*/
extern Adc_UnitStatusType Adc_HwStatus[ADC_MAX_HW_UNITS];




/*-----------------------------------------------------*/


/**
 * @brief            Initializes the ADC hardware units and driver.
 * @details          This function will initialize both the ADC HW unit and the driver structures.
 * @param[in]        ConfigPtr Pointer to configuration set in Variant PB
                    (Variant PC  requires a NULL_PTR).
 * @return           void
 */
void Adc_Init(const Adc_ConfigType *ConfigPtr);

/**
 * @brief            Initializes the result buffer for specific group.
 * @details          Initializes ADC driver with the group specific result buffer start address where
 *                   the conversion results will be stored. The application has to ensure that the
 *                   application  buffer, where DataBufferPtr points to, can hold all the conversion
 *                   results of the specified group. The initialization with Adc_SetupResultBuffer is
 *                   required after reset, before a group conversion can be started.
 * @param[in]        Group Numeric ID of requested ADC channel group.
 * @param[in]        DataBufferPtr pointer to result data buffer
 * @return           Std_ReturnType
 */
Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group, Adc_ValueGroupType *DataBufferPtr);


#if (ADC_DE_INIT_API == STD_ON)
/**
 * @brief            De-initializes all ADC HW Units.
 * @details          Returns all ADC HW Units to a state comparable to their power on reset state.
 * @return           void
 */
void Adc_DeInit(void);
#endif/*ADC_DE_INIT_API == STD_ON*/

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/**
 * @brief            Disables the notification for specific group.
 * @details          This function will disable the notification mechanism only for
 *                   the requested ADC channel group.
 * @param[in]        Group Numeric ID of requested ADC Channel group.
 * @return           void
 */
void Adc_DisableGroupNotification(Adc_GroupType Group);

/**
 * @brief            Enable the notification for specific group.
 * @details          This function will enable the notification mechanism only for
 *                    the requested ADC channel group.
 * @param[in]        Group Numeric ID of requested ADC Channel group.
 * @return           void
 */
void Adc_EnableGroupNotification(Adc_GroupType Group);
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

#if (ADC_HW_TRIGGER_API == STD_ON)
/**
 * @brief            Disables the hardware trigger for the requested group.
 * @details          This function will disable the HW trigger source for the requested
 *                   ADC channel group.
 * @param[in]        Group Numeric ID of requested ADC Channel group.
 * @return           void
 */
void Adc_DisableHardwareTrigger(Adc_GroupType Group);

/**
 * @brief            Enables the hardware trigger for the requested group.
 * @details          This function will enable the notification mechanism only for
 *                   the requested ADC channel group.
 * @param[in]        Group Numeric ID of requested ADC Channel group.
 * @return           void
 */
void Adc_EnableHardwareTrigger(Adc_GroupType Group);
#endif /* ADC_HW_TRIGGER_API == STD_ON */

#if (ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
/**
 * @brief            Get the current power state of the ADC HW unit.
 * @details          This API returns the current power state of the ADC HW unit.
 * @param[out]       CurrentPowerState The current power mode of the ADC HW Unit is returned in this
 *                    parameter
 * @param[out]       Result If the API returns E_OK:
                                               ADC_SERVICE_ACCEPTED: Current power mode was returned.
                            If the API returns E_NOT_OK:
                                               ADC_NOT_INIT: ADC Module not initialized.
 * @return           Std_ReturnType
 */
Std_ReturnType Adc_GetCurrentPowerState(Adc_PowerStateType *CurrentPowerState, Adc_PowerStateRequestResultType *Result);

/**
 * @brief            Get the target power state of the ADC HW unit.
 * @details          This API returns the Target power state of the ADC HW unit.
 * @param[out]       TargetPowerState The Target power mode of the ADC HW Unit is returned in this
 *                   parameter
 * @param[out]       Result If the API returns E_OK:
 *                                   ADC_SERVICE_ACCEPTED:Target power mode was returned.
 *                          If the API returns E_NOT_OK:
 *                                   ADC_NOT_INIT: ADC Module not initialized.
 * @return           Std_ReturnType
 */
Std_ReturnType Adc_GetTargetPowerState(Adc_PowerStateType *TargetPowerState, Adc_PowerStateRequestResultType *Result);

/**
 * @brief            Starts the needed process to allow the ADC HW module to enter the requested power state.
 * @details          This API starts the needed process to allow the ADC HW module to enter the requested
 *                   power state.
 * @param[in]        PowerState The target power state intended to be attained
 * @param[out]       Result If the API returns E_OK:
 *                   ADC_SERVICE_ACCEPTED: ADC Module power state preparation was started.
 *                   If the API returns E_NOT_OK:
 *                   ADC_NOT_INIT: ADC Module not initialized.
 *                   ADC_SEQUENCE_ERROR: wrong API call sequence (Current Power State = Target Power State).
 *                   ADC_POWER_STATE_NOT_SUPP: ADC Module does not support the requested power state.
 *                   ADC_TRANS_NOT_POSSIBLE: ADC Module cannot transition directly from the current power state to the
 *                   requested power state or the HW peripheral is still busy.
 * @return           Std_ReturnType
 */
Std_ReturnType Adc_PreparePowerState(Adc_PowerStateType PowerState, Adc_PowerStateRequestResultType *Result);

/**
 * @brief            Enters the already prepared power state.
 * @details          This API configures the Adc module so that it enters the already prepared power
 *                   state, chosen between a predefined set of configured ones.
 * @param[out]       Result If the API returns E_OK:
 *                               ADC_SERVICE_ACCEPTED: Power state change executed.
 *                           If the API returns E_NOT_OK:
 *                                ADC_NOT_INIT: ADC Module not initialized.
 *                                ADC_SEQUENCE_ERROR: wrong API call sequence.
 *                                ADC_HW_FAILURE: the HW module has a failure which
 *                                prevents it to enter the required power state.
 * @return           Std_ReturnType
 */
Std_ReturnType Adc_SetPowerState(Adc_PowerStateRequestResultType *Result);

#if (ADC_POWER_STATE_ASYNCH_TRANSITION_MODE == STD_ON)
/**
 * @brief            Cyclically called and supervises the power state transitions.
 * @details          This API is cyclically called and supervises the power state transitions,
 *                   checking for the readiness of the module and issuing the callbacks IoHwAb_
 *                   Adc_NotifyReadyForPowerState<Mode> (see AdcPowerStateReadyCbkRef configuration
 *                   parameter).
 * @return           void
 */
void Adc_Main_PowerTransitionManager(void);
#endif /*ADC_POWER_STATE_ASYNCH_TRANSITION_MODE == STD_ON*/
#endif /* ADC_LOW_POWER_STATES_SUPPORT == STD_ON */

/**
 * @brief            Returns the conversion status of the requested ADC Channel group.
 * @details          This function will return the conversion status of the requested
 *                    group.
 * @param[in]        Group Numeric ID of requested ADC Channel group.
 * @return           Adc_StatusType
 */
Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group);

/**
 * @brief            Returns the number of valid samples per channel.
 * @details          Returns the number of valid samples per channel, stored in the result buffer.
 *                   Reads a pointer, pointing to a position in the group result buffer. With the
 *                   pointer position, the  results of all group channels of the last completed
 *                   conversion round can be accessed. With the pointer and the return value, all
 *                   valid group conversion results can be accessed (the user has to take the
 *                   layout of the result buffer into account).
 * @param[in]        Group Numeric ID of requested ADC Channel group.
 * @param[out]       PtrToSamplePtr Pointer to result buffer pointer.
 * @return           Adc_StreamNumSampleType
 */
Adc_StreamNumSampleType Adc_GetStreamLastPointer(Adc_GroupType Group, Adc_ValueGroupType **PtrToSamplePtr);

#if (ADC_READ_GROUP_API == STD_ON)
/**
 * @brief            Reads the group conversion results.
 * @details          Reads the group conversion result of the  last completed conversion round of the
 *                   requested group and stores the channel values starting at the DataBufferPtr address.
 *                   The group channel values are stored in ascending channel number order ( in contrast
 *                   to the storage layout of the result buffer if streaming access is configured).
 * @param[in]        Group Numeric ID of requested ADC channel group.
 * @param[out]       DataBufferPtr ADC results of all channels of the selected group are stored in
 *                                 the data buffer addressed with the pointer.
 * @return           Std_ReturnType
 */
Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType *DataBufferPtr);
#endif /* ADC_READ_GROUP_API == STD_ON */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/**
 * @brief            Starts the conversion of a specific group.
 * @details          This function will start the SW conversion of the requested ADC group.
 * @param[in]        Group Numeric ID of requested ADC Channel group.
 * @return           void
 */
void Adc_StartGroupConversion(Adc_GroupType Group);

/**
 * @brief            Stops the conversion of a specific group.
 * @details          This function will stop the SW conversion of the requested ADC group.
 * @param[in]        Group Numeric ID of requested ADC Channel group.
 * @return           void
 */
void Adc_StopGroupConversion(Adc_GroupType Group);
#endif /* ADC_ENABLE_START_STOP_GROUP_API == STD_ON */

#if (((ADC_VERSION_INFO_API == STD_ON) && (ADC_DEV_ERROR_DETECT == STD_ON)))
/**
 * @brief            Returns the version information of this module.
 * @details
 * @param[out]       versioninfo Pointer to where to store version information of this module
 * @return           void
 */
#define Adc_GetVersionInfo(versioninfo)                                       \
    {                                                                         \
        /* Check for DET: ADC_E_PARAM_POINTER */                              \
        if ((versioninfo) == NULL_PTR)                                        \
        {                                                                     \
            /* Report ADC_E_PARAM_POINTER DET if service called with          \
               NULL_PTR                                                       \
            */                                                                \
            Det_ReportError(                                                  \
                (uint16)ADC_MODULE_ID,                                        \
                ADC_INSTANCE_ID,                                              \
                ADC_SID_GET_VERSION_INFO,                                     \
                ADC_E_PARAM_POINTER);                                         \
        }                                                                     \
        else                                                                  \
        {                                                                     \
            /* Vendor ID information */                                       \
            ((Std_VersionInfoType *)(versioninfo))->vendorID = ADC_VENDOR_ID; \
            /* Adc module ID information */                                   \
            ((Std_VersionInfoType *)(versioninfo))->moduleID = ADC_MODULE_ID; \
            /* Adc module Software major version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_major_version =        \
                (uint8)ADC_SW_MAJOR_VERSION;                                      \
            /* Adc module Software minor version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =        \
                (uint8)ADC_SW_MINOR_VERSION;                                      \
            /* Adc module Software patch version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =        \
                (uint8)ADC_SW_PATCH_VERSION;                                      \
        }                                                                     \
    }
#elif (((ADC_VERSION_INFO_API == STD_ON) && (ADC_DEV_ERROR_DETECT == STD_OFF)))
#define Adc_GetVersionInfo(versioninfo)                                   \
    {                                                                     \
        /* Vendor ID information */                                       \
        ((Std_VersionInfoType *)(versioninfo))->vendorID = ADC_VENDOR_ID; \
        /* Adc module ID information */                                   \
        ((Std_VersionInfoType *)(versioninfo))->moduleID = ADC_MODULE_ID; \
        /* Adc module Software major version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_major_version =        \
            (uint8)ADC_SW_MAJOR_VERSION;                                      \
        /* Adc module Software minor version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =        \
            (uint8)ADC_SW_MINOR_VERSION;                                      \
        /* Adc module Software patch version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =        \
            (uint8)ADC_SW_PATCH_VERSION;                                      \
    }
#endif /* ADC_VERSION_INFO_API == STD_ON && ADC_DEV_ERROR_DETECT == STD_ON */

#ifdef __cplusplus
}
#endif

#endif /* ADC_H */

/** @} */

