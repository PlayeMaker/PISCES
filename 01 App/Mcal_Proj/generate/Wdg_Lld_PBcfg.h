/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Wdg_Lld_PBcfg.h
 * @brief 
 * 
 */


#ifndef WDG_LLD_PBCFG_H
#define WDG_LLD_PBCFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                          INCLUDE FILES                                          
==================================================================================================*/
#include "Wdg_Lld_Types.h"

/*==================================================================================================
 *                                 SOURCE FILE VERSION INFORMATION                                 
==================================================================================================*/
#define WDG_LLD_PBCFG_VENDOR_ID                      (180)
#define WDG_LLD_PBCFG_AR_RELEASE_MAJOR_VERSION       (4)
#define WDG_LLD_PBCFG_AR_RELEASE_MINOR_VERSION       (4)
#define WDG_LLD_PBCFG_AR_RELEASE_REVISION_VERSION    (0)
#define WDG_LLD_PBCFG_SW_MAJOR_VERSION               (0)
#define WDG_LLD_PBCFG_SW_MINOR_VERSION               (9)
#define WDG_LLD_PBCFG_SW_PATCH_VERSION               (1)    

/*==================================================================================================
 *                                  GLOBAL CONSTANTS DECLARATIONS                                  
==================================================================================================*/
#define WDG_180_INST0_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"

WDG_180_INST0_CONST extern const Wdg_Lld_ConfigType Wdg_Lld_OffModeSettings_Config;
WDG_180_INST0_CONST extern const Wdg_Lld_ConfigType Wdg_Lld_SlowModeSettings_Config;
WDG_180_INST0_CONST extern const Wdg_Lld_ConfigType Wdg_Lld_FastModeSettings_Config;

#define WDG_180_INST0_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"

/*==================================================================================================
 *                                      FUNCTION PROTOTYPES
==================================================================================================*/
/**
 * @brief WDG callback notification.
 */
void Wdg_180_Inst0_Callback(void);

#ifdef __cplusplus
}
#endif

#endif /* WDG_LLD_PBCFG_H */

/** @} */

