/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file CryIf_cfg.h
 * @brief 
 * 
 */


#ifndef CRYIF_CFG_H
#define CRYIF_CFG_H


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "Csm_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYIF_VENDOR_ID_CFG                      (0xB4)
#define CRYIF_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define CRYIF_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define CRYIF_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define CRYIF_SW_MAJOR_VERSION_CFG               (0)
#define CRYIF_SW_MINOR_VERSION_CFG               (9)
#define CRYIF_SW_PATCH_VERSION_CFG               (1)



/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/
// CryIfChannel


/**
 * @brief        Identifier of the crypto channel.
 * @details      Specifies to which crypto channel the CSM queue is connected to. 
 * @ref          ECUC_CryIf_00004
 */
#define CRY_IF_CHANNEL_ID                           (integers)



// CryIfGeneral
/**
 * @brief        Switches the development error detection and notification on or off.
 * @details      true: detection and notification is enabled.
              false: detection and notification is disabled. 
 * @ref          ECUC_CryIf_00010
 */
#define CRY_IF_DEV_ERROR_DETECT                      (STD_ON)
/**
 * @brief        Pre-processor switch to enable and disable availability of the API CryIf_GetVersionInfo().
 * @details      True: API CryIf_GetVersionInfo() is available
              False: API CryIf_GetVersionInfo() is not available. 
 * @ref          ECUC_CryIf_00011
 */
#define CRY_IF_VERSION_INFO_API                      (STD_ON)





// CryIfKey


/**
 * @brief        Identifier of the CryIf key.
 * @details      Specifies to which CryIf key the CSM key is mapped to. 
 * @ref          ECUC_CryIf_00007
 */
#define CRY_IF_KEY_ID                               (integers)




/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/


#endif

