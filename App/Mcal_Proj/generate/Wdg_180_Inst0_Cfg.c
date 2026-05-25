/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Wdg_180_Inst0_Cfg.c
 * @brief 
 * 
 */


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                          INCLUDE FILES
==================================================================================================*/
#include "Wdg_180_Inst0_Cfg.h"

/*==================================================================================================
 *                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_180_INST0_VENDOR_ID_CFG_C                      (180)
#define WDG_180_INST0_AR_RELEASE_MAJOR_VERSION_CFG_C       (4)
#define WDG_180_INST0_AR_RELEASE_MINOR_VERSION_CFG_C       (4)
#define WDG_180_INST0_AR_RELEASE_REVISION_VERSION_CFG_C    (0)
#define WDG_180_INST0_SW_MAJOR_VERSION_CFG_C               (0)
#define WDG_180_INST0_SW_MINOR_VERSION_CFG_C               (9)
#define WDG_180_INST0_SW_PATCH_VERSION_CFG_C               (1)

/*==================================================================================================
 *                                         GLOBAL CONSTANTS
==================================================================================================*/
#define WDG_180_INST0_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"

WDG_180_INST0_CONST const uint16 Wdg_180_Inst0_InitialTimeoutCfg = WDG_180_INST0_INITIAL_TIMEOUT;

WDG_180_INST0_CONST const uint16 Wdg_180_Inst0_MaxTimeoutCfg = WDG_180_INST0_MAX_TIMEOUT;

#define WDG_180_INST0_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"

#define WDG_180_INST0_START_SEC_CONST_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"

WDG_180_INST0_CONST const Wdg_180_Inst0_DemErrorType Wdg_180_Inst0_E_Disable_Rejected =
{
    .State = STD_OFF,
    .Id = (uint32)0U
};

WDG_180_INST0_CONST const Wdg_180_Inst0_DemErrorType Wdg_180_Inst0_E_Mode_Failed =
{
    .State = STD_OFF,
    .Id = (uint32)0U
};
#define WDG_180_INST0_STOP_SEC_CONST_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

