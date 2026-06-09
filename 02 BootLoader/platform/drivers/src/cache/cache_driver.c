/*
 * Copyright 2020-2025 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file cache_driver.c
 */

#include "device_registers.h"
#include "cache_hw_access.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Table of base addresses for CACHE instances. */
static CACHE_Type *const s_cacheBase[] = CACHE_BASE_PTRS;

/*******************************************************************************
 * Code
 ******************************************************************************/
/*FUNCTION**********************************************************************
 *
 * Function Name : CACHE_DRV_Init
 * Description   : This function initializes CACHE driver based on user configuration input.
 * The user must make sure that the clock is enabled.
 *
 * Implements    : CACHE_DRV_Init_Activity
 *END**************************************************************************/
status_t CACHE_DRV_Init(uint32_t instance, const cache_user_config_t *userConfigPtr)
{
    CACHE_Type *base = s_cacheBase[instance];
    status_t status = STATUS_SUCCESS;

    CACHE_SetFlashCacheMode(base, userConfigPtr->flashCacheMode);
    CACHE_SetOcramCacheMode(base, userConfigPtr->ocramCacheMode);

    CACHE_InvalidateAll(base);
    if (userConfigPtr->flashCacheMode != NO_CACHE_MODE || userConfigPtr->ocramCacheMode != NO_CACHE_MODE)
    {
        CACHE_Enable(base);
    }
    else
    {
        CACHE_Disable(base);
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CACHE_DRV_Deinit
 * Description   : This function sets the default configuration.
 *
 * Implements    : CACHE_DRV_Deinit_Activity
 *END**************************************************************************/
status_t CACHE_DRV_Deinit(uint32_t instance)
{
    CACHE_Type *base = s_cacheBase[instance];

    CACHE_Disable(base);
    CACHE_SetFlashCacheMode(base, WRITE_THROUGH_MODE);
    CACHE_SetOcramCacheMode(base, NO_CACHE_MODE);

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CACHE_DRV_Enable
 * Description   : This function enables cache.
 *
 * Implements    : CACHE_DRV_Enable_Activity
 *END**************************************************************************/
status_t CACHE_DRV_Enable(uint32_t instance)
{
    CACHE_Type *base = s_cacheBase[instance];

    CACHE_InvalidateAll(base);
    CACHE_Enable(base);

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CACHE_DRV_Disable
 * Description   : This function disables cache.
 *
 * Implements    : CACHE_DRV_Disable_Activity
 *END**************************************************************************/
status_t CACHE_DRV_Disable(uint32_t instance)
{
    CACHE_Type *base = s_cacheBase[instance];

    CACHE_Disable(base);
    CACHE_InvalidateAll(base);

    return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CACHE_DRV_InvalidateAll
 * Description   : This function invalidates all cache lines.
 *
 * Implements    : CACHE_DRV_InvalidateAll_Activity
 *END**************************************************************************/
status_t CACHE_DRV_InvalidateAll(uint32_t instance)
{
    CACHE_Type *base = s_cacheBase[instance];

    CACHE_InvalidateAll(base);

    return STATUS_SUCCESS;
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
