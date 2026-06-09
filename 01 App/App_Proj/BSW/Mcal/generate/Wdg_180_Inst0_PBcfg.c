/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Wdg_180_Inst0_PBcfg.c
 * @brief 
 * 
 */


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                          INCLUDE FILES                                          
==================================================================================================*/
#include "Wdg_180_Inst0_PBcfg.h"
#include "Wdg_Lld_PBcfg.h"

/*==================================================================================================
 *                                 SOURCE FILE VERSION INFORMATION                                 
==================================================================================================*/
#define WDG_180_INST0_VENDOR_ID_PBCFG_C                      (180)
#define WDG_180_INST0_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define WDG_180_INST0_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define WDG_180_INST0_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define WDG_180_INST0_SW_MAJOR_VERSION_PBCFG_C               (0)
#define WDG_180_INST0_SW_MINOR_VERSION_PBCFG_C               (9)
#define WDG_180_INST0_SW_PATCH_VERSION_PBCFG_C               (1)

/*==================================================================================================
 *                                         LOCAL CONSTANTS                                         
==================================================================================================*/
#define WDG_180_INST0_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"

WDG_180_INST0_CONST static const Wdg_180_Inst0_ModeType Wdg_180_Inst0_OffModeSettings_Config = 
{
    .TriggerPeriod = 0UL,
    .WdgConfig = &Wdg_Lld_OffModeSettings_Config,
};

WDG_180_INST0_CONST static const Wdg_180_Inst0_ModeType Wdg_180_Inst0_SlowModeSettings_Config = 
{
    /* Service Wdg manually. */
    .TriggerPeriod = 0UL,
    .WdgConfig = &Wdg_Lld_SlowModeSettings_Config,
};

WDG_180_INST0_CONST static const Wdg_180_Inst0_ModeType Wdg_180_Inst0_FastModeSettings_Config = 
{
    /* Service Wdg manually. */
    .TriggerPeriod = 0UL,
    .WdgConfig = &Wdg_Lld_FastModeSettings_Config,
};

/*==================================================================================================
 *                                         GLOBAL CONSTANTS                                         
==================================================================================================*/
WDG_180_INST0_CONST const Wdg_180_Inst0_ConfigType Wdg_180_Inst0_Config = 
{
    .DefaultMode = WDGIF_SLOW_MODE,
#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
    /* Service Wdg manually. */
    .TimerChannel = 0U,
    .TriggerSourceClock = 0UL,
#endif
    .ModeSettings = 
    {
        [WDGIF_OFF_MODE] = &Wdg_180_Inst0_OffModeSettings_Config,
        [WDGIF_SLOW_MODE] = &Wdg_180_Inst0_SlowModeSettings_Config,
        [WDGIF_FAST_MODE] = &Wdg_180_Inst0_FastModeSettings_Config
    }
};

#define WDG_180_INST0_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

