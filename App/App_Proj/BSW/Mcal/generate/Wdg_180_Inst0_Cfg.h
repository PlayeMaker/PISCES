/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Wdg_180_Inst0_Cfg.h
 * @brief 
 * 
 */


#ifndef WDG_180_INST0_CFG_H
#define WDG_180_INST0_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                         INCLUDE FILES                                         
==================================================================================================*/
#include "Std_Types.h"
#include "Wdg_180_Inst0_Types.h"

/*==================================================================================================
 *                                 SOURCE FILE VERSION INFORMATION                                 
==================================================================================================*/
#define WDG_180_INST0_VENDOR_ID_CFG                      (180)
#define WDG_180_INST0_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define WDG_180_INST0_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define WDG_180_INST0_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define WDG_180_INST0_SW_MAJOR_VERSION_CFG               (0)
#define WDG_180_INST0_SW_MINOR_VERSION_CFG               (9)
#define WDG_180_INST0_SW_PATCH_VERSION_CFG               (1)

/*==================================================================================================
 *                                       DEFINES AND MACROS                                       
==================================================================================================*/
/**
 * @brief   WDG development error detection
 */
#define WDG_180_INST0_DEV_ERROR_DETECT    (STD_OFF)

/**
 * @brief   WDG interrupt used
 */
#define WDG_180_INST0_ISR_USED            (STD_ON)

/**
 * @brief   Represents the watchdog driver execution area is either from ROM(Flash) or RAM as
 *          required with the particular microcontroller.
 * @details 1 Watchdog driver to be executed out of ROM area.
 *          0 Watchdog driver to be executed out of RAM area.
 * @ref     ECUC_Wdg_00147, SWS_Wdg_00168
 */
#define WDG_180_INST0_RUN_ON_ROM          (STD_ON)

/**
 * @brief   Compile switch to allow / forbid disabling the watchdog driver during runtime.
 * @ref     ECUC_Wdg_00116
 */
#define WDG_180_INST0_DISABLE_ALLOWED          (STD_OFF)

/**
 * @brief   WDG timeout count
 */
#define WDG_180_INST0_TIMEOUT_COUNT       (65535UL)

/*==================================================================================================
 *                                          WdgPrecompile                                          
==================================================================================================*/
/**
 * @brief   Configuration of the Wdg (Watchdog driver) module.
 * @ref     ECUC_Wdg_00073
 */
#define WDG_180_INST0_PRECOMPILE_SUPPORT          (STD_OFF)

/*==================================================================================================
 *                                           WdgGeneral                                           
==================================================================================================*/

/**
 * @brief   Specifies the InstanceId of this module instance. If only one instance is present it 
 *          shall have the Id 0.
 * @ref     ECUC_Wdg_00117
 */
#define WDG_180_INST0_INDEX             (0U)

/**
 * @brief   The initial timeout (miliseconds) for the trigger condition to be initialized during
 *          Init function. It shall be not larger than WdgMaxTimeout.
 * @ref     ECUC_Wdg_00130
 */
#define WDG_180_INST0_INITIAL_TIMEOUT   (1000U)

/**
 * @brief   The maximum timeout (miliseconds) to which the watchdog trigger condition can be
 *          initialized.
 * @ref     ECUC_Wdg_00131
 */
#define WDG_180_INST0_MAX_TIMEOUT       (10000U)

/**
 * @brief   Compile switch to enable / disable the version information API.
 * @ref     ECUC_Wdg_00119
 */
#define WDG_180_INST0_VERSION_INFO_API  (STD_ON)

/*==================================================================================================
 *                                           WdgExt                                           
==================================================================================================*/
/**
 * @brief   This define indicate the number of HW IPs available on the Platform.
 */
#define WDG_NO_OF_INSTANCES             (2U)

/**
 * @brief   WDG INST0 disable DEM reporting.
 */
#define WDG_180_INST0_DISABLE_DEM       (STD_ON)

/**
 * @brief   WDG INST0 enable SchM support.
 */
#define WDG_180_INST0_SCHM_SUPPORT      (STD_OFF)

/**
 * @brief   WDG INST0 enable user mode support.
 */
#define WDG_180_INST0_USER_MODE_SUPPORT (STD_OFF)

#if (WDG_180_INST0_USER_MODE_SUPPORT == STD_ON)
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
#error "Must define MCAL_ENABLE_USER_MODE_SUPPORT if WDG_USER_MODE_SUPPORT is enabled."
#endif
#endif

/*==================================================================================================
 *                                         GLOBAL CONSTANTS
==================================================================================================*/

#define WDG_180_INST0_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"

WDG_180_INST0_CONST extern const uint16 Wdg_180_Inst0_InitialTimeoutCfg;

#define WDG_180_INST0_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"

#define WDG_180_INST0_START_SEC_CONST_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"

#define WDG_180_INST0_STOP_SEC_CONST_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* WDG_180_INST0_CFG_H */

/** @} */

