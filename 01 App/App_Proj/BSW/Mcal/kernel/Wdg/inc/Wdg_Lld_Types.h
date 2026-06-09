/**
 * @file    Wdg_Lld_Types.h
 * @version V0.9.1
 *
 * @brief   YUNTU Wdg_Lld module interface
 * @details API implementation for Wdg_Lld driver
 *
 * @addtogroup WDG_LLD_MODULE
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

#ifndef WDG_LLD_TYPES_H
#define WDG_LLD_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                      INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_LLD_TYPES_VENDOR_ID                      (180)
#define WDG_LLD_TYPES_MODULE_ID             (102)
#define WDG_LLD_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define WDG_LLD_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define WDG_LLD_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define WDG_LLD_TYPES_SW_MAJOR_VERSION               (0)
#define WDG_LLD_TYPES_SW_MINOR_VERSION               (9)
#define WDG_LLD_TYPES_SW_PATCH_VERSION               (1)

/*==================================================================================================
 *                                          ENUMS
==================================================================================================*/
/**
 * @brief   WDG clock sources.
 */
typedef enum
{
#if defined(CPU_YTM32B1ME0)
    WDG_LLD_CLKSRC_SIRC  = 0x00U,   /**< SIRC clock */
    WDG_LLD_CLKSRC_SXOSC = 0x01U    /**< SXOSC clock */
#elif defined(CPU_YTM32B1MD1) || defined(CPU_YTM32B1HA0)
    WDG_LLD_CLKSRC_IPC  = 0x00U,    /**< IPC clock */
    WDG_LLD_CLKSRC_BUS  = 0x01U     /**< BUS clock */
#elif defined(CPU_YTM32B1MC0)
    WDG_LLD_CLKSRC_LPO  = 0x00U,    /**< LPO clock */
    WDG_LLD_CLKSRC_SIRC = 0x01U,    /**< SIRC clock */
    WDG_LLD_CLKSRC_IPC  = 0x02U     /**< IPC clock */
#elif defined(CPU_YTM32B1MD2)
    WDG_LLD_CLKSRC_LPO  = 0x00U,    /**< LPO clock */
    WDG_LLD_CLKSRC_SIRC = 0x01U,    /**< SIRC clock */
    WDG_LLD_CLKSRC_IPC  = 0x02U,    /**< IPC clock */
    WDG_LLD_CLKSRC_BUS  = 0x03U     /**< BUS clock */
#else
#error "Wrong MCU part number or no MCU part number selected!"
#endif
} Wdg_Lld_ClkSrcType;

/**
 * @brief   WDG lock types.
 */
typedef enum
{
    WDG_LLD_UNLOCK   = 0x00U,   /**< Unlock the watchdog. */
    WDG_LLD_SOFTLOCK = 0x01U,   /**< Soft lock the watchdog. */
    WDG_LLD_HARDLOCK = 0x02U    /**< Hard lock the watchdog. */
} Wdg_Lld_LockType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief   WDG callback type.
 */
typedef void (*Wdg_Lld_CallbackType)(void);

/**
 * @brief   WDG configuration structure.
 */
typedef struct
{
    boolean ResetInvalidApbEnable;      /**< Enable reset for invalid APB access. */
    boolean WindowMode;                 /**< Enable window mode. */
    boolean InterruptBeforeReset;       /**< Enable interrupt before reset function. */
    Wdg_Lld_ClkSrcType ClockSource;     /**< Clock source. */
    boolean DisableInDeepSleepMode;     /**< Enable or disable watchdog in deepsleep mode. */
    boolean DisableInDebugMode;         /**< Enable or disable watchdog in debug mode. */
#if defined(CPU_YTM32B1MC0)
    uint16  TimerOverflowValue;         /**< The timer overflow value. */
#else
    uint32  TimerOverflowValue;         /**< The timer overflow value. */
#endif
    uint32  WindowValue;                /**< The window value. */
    Wdg_Lld_LockType Lock;              /**< Lock type. */
    Wdg_Lld_CallbackType WdgCallback;   /**< Callback function. */
} Wdg_Lld_ConfigType;

#ifdef __cplusplus
}
#endif

#endif /* WDG_LLD_TYPES_H */

/** @} */

