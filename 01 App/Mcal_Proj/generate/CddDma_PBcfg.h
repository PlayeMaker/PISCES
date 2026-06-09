/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file CddDma_PBcfg.h
 * @brief 
 * 
 */


#ifndef CDDDMA_PB_CFG_H
#define CDDDMA_PB_CFG_H


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDDDMA_VENDOR_ID_PBCFG                      (180)
#define CDDDMA_AR_RELEASE_MAJOR_VERSION_PBCFG       (4)
#define CDDDMA_AR_RELEASE_MINOR_VERSION_PBCFG       (4)
#define CDDDMA_AR_RELEASE_REVISION_VERSION_PBCFG    (0)
#define CDDDMA_SW_MAJOR_VERSION_PBCFG               (0)
#define CDDDMA_SW_MINOR_VERSION_PBCFG               (9)
#define CDDDMA_SW_PATCH_VERSION_PBCFG               (1)

/*==================================================================================================
*                                       DEFINITIONS AND MACROS
==================================================================================================*/
/* Logic Channel 0 */
#define CddDmaConf_CddDmaConfig_dmaLogicChannel_Type_0             (0U)
/* Logic Channel 1 */
#define CddDmaConf_CddDmaConfig_dmaLogicChannel_Type_1             (1U)

#define CDDDMA_CONFIG_PB \
    extern const CddDma_ConfigType CddDma_Config;

#endif

