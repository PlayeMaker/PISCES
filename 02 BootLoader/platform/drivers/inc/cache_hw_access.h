/*
 * Copyright 2020-2025 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CACHE_HW_ACCESS_H
#define CACHE_HW_ACCESS_H

/*! @file cache_hw_access.h */

#include "cache_driver.h"

/*!

 * @brief Cache Hardware Access.
 *
 * This section describes the programming interface of the CACHE HW ACCESS.
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @name CACHE HW ACCESS API
 * @{
 */

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Set the flash cache mode.
 * @param base Pointer to the CACHE peripheral base address.
 * @param mode The cache mode to set
 */
static inline void CACHE_SetFlashCacheMode(CACHE_Type *const base, cache_mode_t mode)
{
    if (mode == NO_CACHE_MODE)
    {
        base->CAMR &= ~CACHE_CAMR_PFLASHCM_MASK;
    }
    else
    {
        base->CAMR |= CACHE_CAMR_PFLASHCM_MASK;
    }
}

/*!
 * @brief Set the OCRAM cache mode.
 * @param base Pointer to the CACHE peripheral base address.
 * @param mode The cache mode to set
 */
static inline void CACHE_SetOcramCacheMode(CACHE_Type *const base, cache_mode_t mode)
{
    if (mode == NO_CACHE_MODE)
    {
        base->CAMR |= CACHE_CAMR_OCRAMCM_MASK;
    }
    else
    {
        base->CAMR &= ~CACHE_CAMR_OCRAMCM_MASK;
    }
}

/*!
 * @brief Invalidate Cache.
 * @param base Pointer to the CACHE peripheral base address.
 */
static inline void CACHE_InvalidateAll(CACHE_Type *const base)
{
    __DSB();
    __ISB();
    /* Invalidate way0 and way1 */
    base->CACR |= CACHE_CACR_IW0_MASK | CACHE_CACR_IW1_MASK | CACHE_CACR_CMDREQ_MASK;
    while((base->CACR & CACHE_CACR_CMDREQ_MASK) == CACHE_CACR_CMDREQ_MASK)
    {
        /* Wait until cache command request done */
    }
    __DSB();
    __ISB();
}

/*!
 * @brief Enable Cache.
 * @param base Pointer to the CACHE peripheral base address.
 */
static inline void CACHE_Enable(CACHE_Type *const base)
{
    __DSB();
    __ISB();
    base->CACR |= CACHE_CACR_EN_MASK;
    __DSB();
    __ISB();
}

/*!
 * @brief Disable Cache.
 * @param base Pointer to the CACHE peripheral base address.
 */
static inline void CACHE_Disable(CACHE_Type *const base)
{
    __DSB();
    __ISB();
    base->CACR &= ~CACHE_CACR_EN_MASK;
    __DSB();
    __ISB();
}

/*!
 * @brief Check if Cache is enabled.
 * @param base Pointer to the CACHE peripheral base address.
 * @return true Cache is enabled.
 *         false Cache is disabled.
 */
static inline bool CACHE_IsEnabled(CACHE_Type *const base)
{
    return ((base->CACR & CACHE_CACR_EN_MASK) == CACHE_CACR_EN_MASK) ? true : false;
}
/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* CACHE_HW_ACCESS_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/
