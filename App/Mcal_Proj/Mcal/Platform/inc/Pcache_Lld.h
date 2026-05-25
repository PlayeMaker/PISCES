/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : PCACHE
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 0.9.1
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
*
*   YUNTU Confidential. This software is owned or controlled by YUNTU and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef PCACHE_LLD_H_
#define PCACHE_LLD_H_

/**
*   @file
*
*   @internal
*   @addtogroup Pcache_Lld
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "Platform_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PCACHE_LLD_VENDOR_ID                      (180)
#define PCACHE_LLD_AR_RELEASE_MAJOR_VERSION       (4)
#define PCACHE_LLD_AR_RELEASE_MINOR_VERSION       (4)
#define PCACHE_LLD_AR_RELEASE_REVISION_VERSION    (0)
#define PCACHE_LLD_SW_MAJOR_VERSION               (0)
#define PCACHE_LLD_SW_MINOR_VERSION               (9)
#define PCACHE_LLD_SW_PATCH_VERSION               (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/



/**
 * @brief         Enables P-CACHE feature.
 *
 * @details       This function is non-reentrant and enables the P-CACHE.
 *
 * @return        void
 *
 * @api
 *
 * @implements    Pcache_Lld_EnableCache_Activity
 *
 * */
void Pcache_Lld_EnableCache(void);

/**
 * @brief         Disables P-CACHE feature.
 *
 * @details       This function is non-reentrant and disables the P-CACHE.
 *
 * @return        void
 *
 * @api
 *
 * @implements    Pcache_Lld_DisableCache_Activity
 *
 * */
void Pcache_Lld_DisableCache(void);

/**
 * @brief         Enables flash cache mode.
 *
 * @details       This function is non-reentrant and enables flash caching.
 *
 * @return        void
 *
 * @api
 *
 * @implements    Pcache_Lld_EnableFlashCache_Activity
 *
 * */
void Pcache_Lld_EnableFlashCache(void);

/**
 * @brief         Disables flash cache mode.
 *
 * @details       This function is non-reentrant and disables flash caching.
 *
 * @return        void
 *
 * @api
 *
 * @implements    Pcache_Lld_DisableFlashCache_Activity
 *
 * */
void Pcache_Lld_DisableFlashCache(void);

/**
 * @brief         Enables RAM cache mode.
 *
 * @details       This function is non-reentrant and enables RAM caching.
 *
 * @return        void
 *
 * @api
 *
 * @implements    Pcache_Lld_EnableRamCache_Activity
 *
 * */
void Pcache_Lld_EnableRamCache(void);

/**
 * @brief         Disables RAM cache mode.
 *
 * @details       This function is non-reentrant and disables RAM caching.
 *
 * @return        void
 *
 * @api
 *
 * @implements    Pcache_Lld_DisableRamCache_Activity
 *
 * */
void Pcache_Lld_DisableRamCache(void);

/**
 * @brief         Invalidates all cache lines.
 *
 * @details       This function is non-reentrant and invalidates all cache lines.
 *
 * @return        void
 *
 * @api
 *
 * @implements    Pcache_Lld_InvalidateAll_Activity
 *
 * */
void Pcache_Lld_InvalidateAll(void);

/**
 * @brief         Configures P-CACHE based on user configuration.
 *
 * @details       This function is non-reentrant and configures P-CACHE settings.
 *
 * @param[in]     FlashCacheEnable: TRUE - enable flash cache, FALSE - disable flash cache.
 * @param[in]     RamCacheEnable: TRUE - enable RAM cache, FALSE - disable RAM cache.
 * @return        void
 *
 * @api
 *
 * @implements    Pcache_Lld_Init_Activity
 *
 * */
void Pcache_Lld_Init(boolean FlashCacheEnable, boolean RamCacheEnable);


#ifdef __cplusplus
}
#endif

#endif /* PCACHE_LLD_H_ */

/** @} */
