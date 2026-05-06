/**
 * @file    Wdg_180_Inst0_Types.h
 * @version V0.9.1
 *
 * @brief   AUTOSAR Wdg module interface
 * @details API implementation for Wdg driver
 *
 * @addtogroup WDG_MODULE
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

#ifndef WDG_180_INST0_TYPES_H
#define WDG_180_INST0_TYPES_H

#include "Platform_Types.h"
#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                      INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "WdgIf_Types.h"
#include "Wdg_180_Inst0_Cfg_Defines.h"
#include "Wdg_Lld_Types.h"
#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
#include "Gpt_Types.h"
#endif

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_180_INST0_TYPES_VENDOR_ID                      (180)
#define WDG_180_INST0_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define WDG_180_INST0_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define WDG_180_INST0_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define WDG_180_INST0_TYPES_SW_MAJOR_VERSION               (0)
#define WDG_180_INST0_TYPES_SW_MINOR_VERSION               (9)
#define WDG_180_INST0_TYPES_SW_PATCH_VERSION               (1)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/


/* Check if Wdg_180_Inst0_Types.h and Wdg_Lld_Types.h are of the same vendor */
#if (WDG_180_INST0_TYPES_VENDOR_ID != WDG_LLD_TYPES_VENDOR_ID)
#error "Wdg_180_Inst0_Types.h and Wdg_Lld_Types.h have different vendor ids"
#endif

/* Check if Wdg_180_Inst0_Types.h and Wdg_Lld_Types.h are of the same Autosar version */
#if ((WDG_180_INST0_TYPES_AR_RELEASE_MAJOR_VERSION != WDG_LLD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_180_INST0_TYPES_AR_RELEASE_MINOR_VERSION != WDG_LLD_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_180_INST0_TYPES_AR_RELEASE_REVISION_VERSION != WDG_LLD_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_180_Inst0_Types.h and Wdg_Lld_Types.h are different"
#endif

/* Check if Wdg_180_Inst0_Types.h and Wdg_Lld_Types.h are of the same software version */
#if ((WDG_180_INST0_TYPES_SW_MAJOR_VERSION != WDG_LLD_TYPES_SW_MAJOR_VERSION) || \
     (WDG_180_INST0_TYPES_SW_MINOR_VERSION != WDG_LLD_TYPES_SW_MINOR_VERSION) || \
     (WDG_180_INST0_TYPES_SW_PATCH_VERSION != WDG_LLD_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_180_Inst0_Types.h and Wdg_Lld_Types.h are different"
#endif

#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
/* Check if Wdg_180_Inst0_Types.h and Gpt_Types.h are of the same vendor */
#if (WDG_180_INST0_TYPES_VENDOR_ID != GPT_TYPES_VENDOR_ID)
#error "Wdg_180_Inst0_Types.h and Gpt_Types.h have different vendor ids"
#endif

/* Check if Wdg_180_Inst0_Types.h and Gpt_Types.h are of the same Autosar version */
#if ((WDG_180_INST0_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_180_INST0_TYPES_AR_RELEASE_MINOR_VERSION != GPT_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_180_INST0_TYPES_AR_RELEASE_REVISION_VERSION != GPT_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_180_Inst0_Types.h and Gpt_Types.h are different"
#endif

/* Check if Wdg_180_Inst0_Types.h and Gpt_Types.h are of the same software version */
#if ((WDG_180_INST0_TYPES_SW_MAJOR_VERSION != GPT_TYPES_SW_MAJOR_VERSION) || \
     (WDG_180_INST0_TYPES_SW_MINOR_VERSION != GPT_TYPES_SW_MINOR_VERSION) || \
     (WDG_180_INST0_TYPES_SW_PATCH_VERSION != GPT_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_180_Inst0_Types.h and Gpt_Types.h are different"
#endif
#endif

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/**
 * @brief   Service ID number for all WDG driver services
 */
/**< API Service ID for Wdg_180_Inst0_Init. */
#define WDG_180_INST0_SID_INIT                    (0x00U)
/**< API Service ID for Wdg_180_Inst0_SetMode. */
#define WDG_180_INST0_SID_SET_MODE                (0x01U)
/**< API Service ID for Wdg_180_Inst0_Trigger. */
#define WDG_180_INST0_SID_TRIGGER                 (0x02U)
/**< API Service ID for Wdg_180_Inst0_SetTriggerCondition. */
#define WDG_180_INST0_SID_SET_TRIGGER_CONDITION   (0x03U)
/**< API Service ID for Wdg_GetVersionInfo. */
#define WDG_180_INST0_SID_GET_VERSION_INFO        (0x04U)

/**
 * @brief   Wdg development errors
 */
/**< API service used in wrong context (e.g. module not initialized). */
#define WDG_180_INST0_E_DRIVER_STATE              (0x10U)
/**< API service called with wrong / inconsistent parameter(s). */
#define WDG_180_INST0_E_PARAM_MODE                (0x11U)
/**< API service called with wrong / inconsistent parameter(s). */
#define WDG_180_INST0_E_PARAM_CONFIG              (0x12U)
/**< The passed timeout value is higher than the maximum timeout value. */
#define WDG_180_INST0_E_PARAM_TIMEOUT             (0x13U)
/**< API is called with wrong pointer value (e.g.NULL pointer). */
#define WDG_180_INST0_E_PARAM_POINTER             (0x14U)
/**< Invalid configuration set selection. */
#define WDG_180_INST0_E_INIT_FAILED               (0x15U)

/*==================================================================================================
 *                                          ENUMS
==================================================================================================*/
/**
 * @brief   This enumerated type will contain the watchdog driver's possible states
 */
typedef enum
{
    WDG_180_INST0_UNINIT          = 0x00U, /**< The watchdog driver is not uninitialized. */
    WDG_180_INST0_IDLE            = 0x01U, /**< The watchdog driver is currently idle, i.e not being triggered
                                    or mode changed. */
    WDG_180_INST0_BUSY            = 0x02U, /**< The watchdog driver is currently busy, i.e triggered or
                                    switched between modes. */
    WDG_180_INST0_INITIALIZING    = 0x03U  /**< The watchdog driver is currently initializing. */
} Wdg_180_Inst0_StatusType;

/*==================================================================================================
 *                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * @brief   Typedef for DEM error management implemented by Wdg drivers
 */
typedef struct
{
    boolean State;  /**< enabling/disabling the DEM error: Active=STD_ON/ Inactive=STD_OFF */
    uint32 Id;      /**< ID of DEM error (0 if STD_OFF) */
} Wdg_180_Inst0_DemErrorType;


/**
 * @brief   Structure to hold the watchdog driver configuration set in different modes.
 */
typedef struct
{
    uint32 TriggerPeriod;                   /**< The watchdog trigger period in milliseconds. */
    const Wdg_Lld_ConfigType *WdgConfig;    /**< WDG configuration */
} Wdg_180_Inst0_ModeType;

/**
 * @brief   Structure to hold the watchdog driver configuration set.
 */
typedef struct
{
    WdgIf_ModeType DefaultMode;                 /**< The default mode. */
#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
    Gpt_ChannelType TimerChannel;               /**< Gpt Channel configured. */
    uint32 TriggerSourceClock;                  /**< The frequency of the configured timer channel, KHz. */
#endif
    const Wdg_180_Inst0_ModeType *const ModeSettings[3U]; /**< Pointer to Watchdog Specific implementation details. */
} Wdg_180_Inst0_ConfigType;

#ifdef __cplusplus
}
#endif

#endif /* WDG_180_INST0_TYPES_H */

/** @} */


