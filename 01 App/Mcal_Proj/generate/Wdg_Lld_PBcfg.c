/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Wdg_Lld_PBcfg.c
 * @brief 
 * 
 */


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                          INCLUDE FILES                                          
==================================================================================================*/
#include "Wdg_Lld_PBcfg.h"

/*==================================================================================================
 *                                 SOURCE FILE VERSION INFORMATION                                 
==================================================================================================*/
#define WDG_LLD_PBCFG_VENDOR_ID_C                      (180)
#define WDG_LLD_PBCFG_AR_RELEASE_MAJOR_VERSION_C       (4)
#define WDG_LLD_PBCFG_AR_RELEASE_MINOR_VERSION_C       (4)
#define WDG_LLD_PBCFG_AR_RELEASE_REVISION_VERSION_C    (0)
#define WDG_LLD_PBCFG_SW_MAJOR_VERSION_C               (0)
#define WDG_LLD_PBCFG_SW_MINOR_VERSION_C               (9)
#define WDG_LLD_PBCFG_SW_PATCH_VERSION_C               (1)

/*==================================================================================================
 *                                         GLOBAL CONSTANTS                                         
==================================================================================================*/
#define WDG_180_INST0_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"

WDG_180_INST0_CONST const Wdg_Lld_ConfigType Wdg_Lld_OffModeSettings_Config = 
{
    .ResetInvalidApbEnable = TRUE,
    .WindowMode = FALSE,
    .InterruptBeforeReset = FALSE,
    .ClockSource = WDG_LLD_CLKSRC_IPC,
    .DisableInDeepSleepMode = FALSE,
    .DisableInDebugMode = TRUE,
#if defined(CPU_YTM32B1MC0)
    .TimerOverflowValue = 0xC00UL,
#else
    .TimerOverflowValue = 0x300UL,
#endif
    .WindowValue = 0UL,
    .Lock = WDG_LLD_SOFTLOCK,
    .WdgCallback = NULL_PTR
};

WDG_180_INST0_CONST const Wdg_Lld_ConfigType Wdg_Lld_SlowModeSettings_Config = 
{
    .ResetInvalidApbEnable = TRUE,
    .WindowMode = FALSE,
    .InterruptBeforeReset = FALSE,
    .ClockSource = WDG_LLD_CLKSRC_LPO,
    .DisableInDeepSleepMode = FALSE,
    .DisableInDebugMode = TRUE,
    .TimerOverflowValue = 64000UL,
    .WindowValue = 0UL,
    .Lock = WDG_LLD_SOFTLOCK,
    .WdgCallback = NULL_PTR
};

WDG_180_INST0_CONST const Wdg_Lld_ConfigType Wdg_Lld_FastModeSettings_Config = 
{
    .ResetInvalidApbEnable = TRUE,
    .WindowMode = FALSE,
    .InterruptBeforeReset = FALSE,
    .ClockSource = WDG_LLD_CLKSRC_LPO,
    .DisableInDeepSleepMode = FALSE,
    .DisableInDebugMode = TRUE,
    .TimerOverflowValue = 6400UL,
    .WindowValue = 0UL,
    .Lock = WDG_LLD_SOFTLOCK,
    .WdgCallback = NULL_PTR
};

#define WDG_180_INST0_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

