/*
 * Copyright 2020-2025 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CACHE_DRIVER_H
#define CACHE_DRIVER_H

/*! @file cache_driver.h */

#include <stddef.h>
#include "device_registers.h"
#include "status.h"

/*!
 * @defgroup cache_driver cache Driver
 * @ingroup cache
 * @brief cache driver
 * @details This section describes the programming interface of the cache driver.
 * @{
 */
/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Cache mode enumeration.
 *
 * @details This enumeration defines the cache mode.
 */
typedef enum
{
    NO_CACHE_MODE = 0U,            /*!< No cache mode      */
    WRITE_THROUGH_MODE = 1U,       /*!< Write-through mode */
} cache_mode_t;

/*!
 * @brief Cache user configuration structure.
 *
 * This structure is used to configure the cache.
 *
 * Implements : cache_user_config_t_Class
 */
typedef struct
{
    cache_mode_t flashCacheMode;    /*!< The flash cache mode */
    cache_mode_t ocramCacheMode;    /*!< The OCRAM cache mode */
} cache_user_config_t;


/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @name CACHE DRIVER API
 * @{
 */
/*!
 * @brief Initializes the cache driver based on user configuration input.
 *
 * This function initializes the cache driver with the specified user configuration.
 *
 * @param instance The cache instance number.
 * @param userConfigPtr Pointer to the user configuration structure of type #cache_user_config_t.
 * @return STATUS_SUCCESS if successful; STATUS_ERROR if an error occurred.
 */
status_t CACHE_DRV_Init(uint32_t instance, const cache_user_config_t *userConfigPtr);

/*!
 * @brief De-initializes the cache driver.
 *
 * This function de-initializes the cache driver.
 *
 * @param instance The cache instance number.
 * @return STATUS_SUCCESS if successful; STATUS_ERROR if an error occurred.
 */
status_t CACHE_DRV_DeInit(uint32_t instance);

/*!
 * @brief Enables cache.
 *
 * This function enables cache.
 *
 * @param instance The cache instance number.
 * @return STATUS_SUCCESS if successful; STATUS_ERROR if an error occurred.
 */
status_t CACHE_DRV_Enable(uint32_t instance);

/*!
 * @brief Disables cache.
 *
 * This function disables cache.
 *
 * @param instance The cache instance number.
 * @return STATUS_SUCCESS if successful; STATUS_ERROR if an error occurred.
 */
status_t CACHE_DRV_Disable(uint32_t instance);

/*!
 * @brief Invalidates all cache lines.
 *
 * This function invalidates all cache lines.
 *
 * @param instance The cache instance number.
 * @return STATUS_SUCCESS if successful; STATUS_ERROR if an error occurred.
 */
status_t CACHE_DRV_InvalidateAll(uint32_t instance);

#if defined(__cplusplus)
extern "C" {
#endif

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* CACHE_DRIVER_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/
