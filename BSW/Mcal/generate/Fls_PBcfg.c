/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file undefined
 * @brief 
 * 
 */

#include "Fls_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_PBCFG_C                      (180)
#define FLS_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define FLS_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define FLS_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define FLS_SW_MAJOR_VERSION_PBCFG_C               (0)
#define FLS_SW_MINOR_VERSION_PBCFG_C               (9)
#define FLS_SW_PATCH_VERSION_PBCFG_C               (1)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/*==================================================================================================
 *                                       Function Prototypes
==================================================================================================*/

#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"
/*================================================================================================== */
FLS_CONST const Fls_SectorType Fls_SectorConfig[2] ={
    {
        .SectorId = FlsConf_FlsConfigSet_FlsSector_0,
        .SectorStartAddress = 0x0U,
        .SectorSize = 0x1000U,
        .PageSize = 0x4U,
        .SectorHwStartAddress = 0x2000000U,
        .PhySectorSize = 0x200U,
        .AsyncAccess = TRUE,
        .SectorHwCh = FLS_CH_INTERN,
    },
    {
        .SectorId = FlsConf_FlsConfigSet_FlsSector_1,
        .SectorStartAddress = 0x1000U,
        .SectorSize = 0x1000U,
        .PageSize = 0x4U,
        .SectorHwStartAddress = 0x2001000U,
        .PhySectorSize = 0x200U,
        .AsyncAccess = TRUE,
        .SectorHwCh = FLS_CH_INTERN,
    },
};

FLS_CONST const Fls_SectorProtectType Fls_SectorProtectConfig[FLS_INTERNAL_BLOCK_NUM] ={

    0x0U,
    0x0U,
    0x0U,
};


FLS_CONST const Fls_ConfigType Fls_Config = {
    .AcEraseFunPtr = NULL_PTR,
    .AcWriteFunPtr = NULL_PTR,
    .JobEndNotificationFunPtr = NULL_PTR,
    .JobErrorNotificationFunPtr = NULL_PTR,
    .DefaultMode = MEMIF_MODE_SLOW,
    .MaxReadFastMode = 10240U,
    .MaxReadNormalMode = 1024U,
    .MaxWriteFastMode = 256U,
    .MaxWriteNormalMode = 4U,
    .ConfiguredSectorNumber = 2U,
    .SectorList = Fls_SectorConfig,
    .SectorProtection = Fls_SectorProtectConfig,
};

#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fls_MemMap.h"

