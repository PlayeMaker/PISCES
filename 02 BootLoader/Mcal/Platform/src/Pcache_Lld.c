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

/**
 * @file    Pcache_Lld.c
 * @version 0.9.1
 *
 * @brief   P-CACHE Low Level Driver implementation.
 * @details This file contains the implementation of the AUTOSAR P-CACHE driver.
 *
 * @addtogroup PCACHE
 * @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "OsIf.h"
#include "Platform_Cfg.h"
#include "Pcache_Lld.h"
#include "pSIP_Cache.h"

/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PCACHE_LLD_VENDOR_ID_C                      (180)
#define PCACHE_LLD_AR_RELEASE_MAJOR_VERSION_C       (4)
#define PCACHE_LLD_AR_RELEASE_MINOR_VERSION_C       (4)
#define PCACHE_LLD_AR_RELEASE_REVISION_VERSION_C    (0)
#define PCACHE_LLD_SW_MAJOR_VERSION_C               (0)
#define PCACHE_LLD_SW_MINOR_VERSION_C               (9)
#define PCACHE_LLD_SW_PATCH_VERSION_C               (1)

/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and PCACHE_LLD header file are of the same vendor */
#if (PCACHE_LLD_VENDOR_ID_C != PCACHE_LLD_VENDOR_ID)
#error "Pcache_Lld.c and Pcache_Lld.h have different vendor ids"
#endif

/* Check if source file and PCACHE_LLD header file are of the same Autosar version */
#if (( PCACHE_LLD_AR_RELEASE_MAJOR_VERSION_C != PCACHE_LLD_AR_RELEASE_MAJOR_VERSION) || \
      ( PCACHE_LLD_AR_RELEASE_MINOR_VERSION_C != PCACHE_LLD_AR_RELEASE_MINOR_VERSION) || \
      ( PCACHE_LLD_AR_RELEASE_REVISION_VERSION_C != PCACHE_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pcache_Lld.c and Pcache_Lld.h are different"
#endif

/* Check if source file and PCACHE_LLD header file are of the same Software version */
#if (( PCACHE_LLD_SW_MAJOR_VERSION_C != PCACHE_LLD_SW_MAJOR_VERSION) || \
      ( PCACHE_LLD_SW_MINOR_VERSION_C != PCACHE_LLD_SW_MINOR_VERSION) || \
      ( PCACHE_LLD_SW_PATCH_VERSION_C != PCACHE_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Pcache_Lld.c and Pcache_Lld.h are different"
#endif

/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                                LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                                LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                                LOCAL MACROS
==================================================================================================*/

#if ((STD_ON == PLATFORM_ENABLE_USER_MODE_SUPPORT) && (defined (MCAL_ENABLE_USER_MODE_SUPPORT)))
#define CALL_LLD_ENABLE_CACHE_PRIVILEGED()  \
                OsIf_Trusted_Call(Pcache_Lld_EnableCachePrivileged)
#define CALL_LLD_DISABLE_CACHE_PRIVILEGED()  \
                OsIf_Trusted_Call(Pcache_Lld_DisableCachePrivileged)
#define CALL_LLD_ENABLE_FLASH_CACHE_PRIVILEGED()  \
                OsIf_Trusted_Call(Pcache_Lld_EnableFlashCachePrivileged)
#define CALL_LLD_DISABLE_FLASH_CACHE_PRIVILEGED()  \
                OsIf_Trusted_Call(Pcache_Lld_DisableFlashCachePrivileged)
#define CALL_LLD_ENABLE_RAM_CACHE_PRIVILEGED()  \
                OsIf_Trusted_Call(Pcache_Lld_EnableRamCachePrivileged)
#define CALL_LLD_DISABLE_RAM_CACHE_PRIVILEGED()  \
                OsIf_Trusted_Call(Pcache_Lld_DisableRamCachePrivileged)
#define CALL_LLD_INVALIDATE_ALL_PRIVILEGED()  \
                OsIf_Trusted_Call(Pcache_Lld_InvalidateAllPrivileged)
#define CALL_LLD_INIT_PRIVILEGED(FlashCacheEnable, RamCacheEnable)  \
                OsIf_Trusted_Call2params(Pcache_Lld_InitPrivileged,(FlashCacheEnable), (RamCacheEnable))
#else
#define CALL_LLD_ENABLE_CACHE_PRIVILEGED()  \
                Pcache_Lld_EnableCachePrivileged()
#define CALL_LLD_DISABLE_CACHE_PRIVILEGED()  \
                Pcache_Lld_DisableCachePrivileged()
#define CALL_LLD_ENABLE_FLASH_CACHE_PRIVILEGED()  \
                Pcache_Lld_EnableFlashCachePrivileged()
#define CALL_LLD_DISABLE_FLASH_CACHE_PRIVILEGED()  \
                Pcache_Lld_DisableFlashCachePrivileged()
#define CALL_LLD_ENABLE_RAM_CACHE_PRIVILEGED()  \
                Pcache_Lld_EnableRamCachePrivileged()
#define CALL_LLD_DISABLE_RAM_CACHE_PRIVILEGED()  \
                Pcache_Lld_DisableRamCachePrivileged()
#define CALL_LLD_INVALIDATE_ALL_PRIVILEGED()  \
                Pcache_Lld_InvalidateAllPrivileged()
#define CALL_LLD_INIT_PRIVILEGED(FlashCacheEnable, RamCacheEnable)  \
                Pcache_Lld_InitPrivileged(FlashCacheEnable, RamCacheEnable)
#endif /* (STD_ON == PLATFORM_ENABLE_USER_MODE_SUPPORT) && (defined (MCAL_ENABLE_USER_MODE_SUPPORT)) */

/*==================================================================================================
                                                LOCAL FUNCTIONS
==================================================================================================*/

#define PLATFORM_START_SEC_CODE
#include "Platform_MemMap.h"

#if (PLATFORM_PCACHE == STD_ON)

/**
 * @brief         Enables P-CACHE feature (privileged mode).
 *
 * @details       This function is non-reentrant and enables the P-CACHE.
 *
 * @return        void
 *
 * @api
 *
 * @implements    Pcache_Lld_EnableCachePrivileged_Activity
 *
 * */
PLATFORM_FUNC static inline void Pcache_Lld_EnableCachePrivileged(void)
{
    __DSB();
    __ISB();
    CACHE->CACR |= CACHE_CACR_EN_MASK;
    __DSB();
    __ISB();
}

/**
 * @brief         Disables P-CACHE feature (privileged mode).
 *
 * @details       This function is non-reentrant and disables the P-CACHE.
 *
 * @return        void
 *
 * @api
 *
 * @implements    Pcache_Lld_DisableCachePrivileged_Activity
 *
 * */
PLATFORM_FUNC static inline void Pcache_Lld_DisableCachePrivileged(void)
{
    __DSB();
    __ISB();
    CACHE->CACR &= ~CACHE_CACR_EN_MASK;
    __DSB();
    __ISB();
}

/**
 * @brief         Enables flash cache mode (privileged mode).
 *
 * @details       This function is non-reentrant and enables flash caching.
 *
 * @return        void
 *
 * @api
 *
 * @implements    Pcache_Lld_EnableFlashCachePrivileged_Activity
 *
 * */
PLATFORM_FUNC static inline void Pcache_Lld_EnableFlashCachePrivileged(void)
{
    CACHE->CAMR |= CACHE_CAMR_PFLASHCM_MASK;
}

/**
 * @brief         Disables flash cache mode (privileged mode).
 *
 * @details       This function is non-reentrant and disables flash caching.
 *
 * @return        void
 *
 * @api
 *
 * @implements    Pcache_Lld_DisableFlashCachePrivileged_Activity
 *
 * */
PLATFORM_FUNC static inline void Pcache_Lld_DisableFlashCachePrivileged(void)
{
#if defined(CACHE)
    CACHE->CAMR &= ~CACHE_CAMR_PFLASHCM_MASK;
#endif
}

/**
 * @brief         Enables RAM cache mode (privileged mode).
 *
 * @details       This function is non-reentrant and enables RAM caching.
 *
 * @return        void
 *
 * @api
 *
 * @implements    Pcache_Lld_EnableRamCachePrivileged_Activity
 *
 * */
PLATFORM_FUNC static inline void Pcache_Lld_EnableRamCachePrivileged(void)
{
    CACHE->CAMR &= ~CACHE_CAMR_OCRAMCM_MASK;
}

/**
 * @brief         Disables RAM cache mode (privileged mode).
 *
 * @details       This function is non-reentrant and disables RAM caching.
 *
 * @return        void
 *
 * @api
 *
 * @implements    Pcache_Lld_DisableRamCachePrivileged_Activity
 *
 * */
PLATFORM_FUNC static inline void Pcache_Lld_DisableRamCachePrivileged(void)
{
    CACHE->CAMR |= CACHE_CAMR_OCRAMCM_MASK;
}

/**
 * @brief         Invalidates all cache lines (privileged mode).
 *
 * @details       This function is non-reentrant and invalidates all cache lines.
 *
 * @return        void
 *
 * @api
 *
 * @implements    Pcache_Lld_InvalidateAllPrivileged_Activity
 *
 * */
PLATFORM_FUNC static inline void Pcache_Lld_InvalidateAllPrivileged(void)
{
    __DSB();
    __ISB();
    /* Invalidate way0 and way1 */
    CACHE->CACR |= CACHE_CACR_IW0_MASK | CACHE_CACR_IW1_MASK | CACHE_CACR_CMDREQ_MASK;
    while ((CACHE->CACR & CACHE_CACR_CMDREQ_MASK) == CACHE_CACR_CMDREQ_MASK)
    {
        /* Wait until cache command request done */
    }
    __DSB();
    __ISB();
}

/**
 * @brief         Configures P-CACHE based on user configuration (privileged mode).
 *
 * @details       This function is non-reentrant and configures P-CACHE settings.
 *
 * @param[in]     FlashCacheEnable: TRUE - enable flash cache, FALSE - disable flash cache.
 * @param[in]     RamCacheEnable: TRUE - enable RAM cache, FALSE - disable RAM cache.
 * @return        void
 *
 * @api
 *
 * @implements    Pcache_Lld_InitPrivileged_Activity
 *
 * */
PLATFORM_FUNC static inline void Pcache_Lld_InitPrivileged(boolean FlashCacheEnable, boolean RamCacheEnable)
{
    /* Configure flash cache mode */
    if (TRUE == FlashCacheEnable)
    {
        Pcache_Lld_EnableFlashCachePrivileged();
    }
    else
    {
        Pcache_Lld_DisableFlashCachePrivileged();
    }
    /* Configure RAM cache mode */
    if (TRUE == RamCacheEnable)
    {
        Pcache_Lld_EnableRamCachePrivileged();
    }
    else
    {
        Pcache_Lld_DisableRamCachePrivileged();
    }
    /* Invalidate all cache lines */
    Pcache_Lld_InvalidateAllPrivileged();
    /* Enable cache if any cache mode is enabled */
    if ((TRUE == FlashCacheEnable) || (TRUE == RamCacheEnable))
    {
        Pcache_Lld_EnableCachePrivileged();
    }
    else
    {
        Pcache_Lld_DisableCachePrivileged();
    }
}

#endif /* (PLATFORM_PCACHE == STD_ON) */

/*==================================================================================================
                                                GLOBAL FUNCTIONS
==================================================================================================*/

#if (PLATFORM_PCACHE == STD_ON)

PLATFORM_FUNC void Pcache_Lld_EnableCache(void)
{
    CALL_LLD_ENABLE_CACHE_PRIVILEGED();
}

PLATFORM_FUNC void Pcache_Lld_DisableCache(void)
{
    CALL_LLD_DISABLE_CACHE_PRIVILEGED();
}

PLATFORM_FUNC void Pcache_Lld_EnableFlashCache(void)
{
    CALL_LLD_ENABLE_FLASH_CACHE_PRIVILEGED();
}

PLATFORM_FUNC void Pcache_Lld_DisableFlashCache(void)
{
    CALL_LLD_DISABLE_FLASH_CACHE_PRIVILEGED();
}

PLATFORM_FUNC void Pcache_Lld_EnableRamCache(void)
{
    CALL_LLD_ENABLE_RAM_CACHE_PRIVILEGED();
}

PLATFORM_FUNC void Pcache_Lld_DisableRamCache(void)
{
    CALL_LLD_DISABLE_RAM_CACHE_PRIVILEGED();
}

PLATFORM_FUNC void Pcache_Lld_InvalidateAll(void)
{
    CALL_LLD_INVALIDATE_ALL_PRIVILEGED();
}

PLATFORM_FUNC void Pcache_Lld_Init(boolean FlashCacheEnable, boolean RamCacheEnable)
{
    CALL_LLD_INIT_PRIVILEGED(FlashCacheEnable, RamCacheEnable);
}

#endif /* (PLATFORM_PCACHE == STD_ON) */

#define PLATFORM_STOP_SEC_CODE
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file Pcache_Lld.c */
