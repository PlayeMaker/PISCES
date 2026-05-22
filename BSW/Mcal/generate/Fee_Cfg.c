/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Fee_Cfg.c
 * @brief 
 * 
 */


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Fee.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_VENDOR_ID_CFG_C                      (180)
#define FEE_AR_RELEASE_MAJOR_VERSION_CFG_C       (4)
#define FEE_AR_RELEASE_MINOR_VERSION_CFG_C       (4)
#define FEE_AR_RELEASE_REVISION_VERSION_CFG_C    (0)
#define FEE_SW_MAJOR_VERSION_CFG_C               (0)
#define FEE_SW_MINOR_VERSION_CFG_C               (9)
#define FEE_SW_PATCH_VERSION_CFG_C               (1)

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Fee header file are of the same vendor */
#if (FEE_VENDOR_ID_CFG_C != FEE_VENDOR_ID)
    #error "Fee_Cfg.c and Fee.h have different vendor ids"
#endif
/* Check if current file and Fee header file are of the same Autosar version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION_CFG_C    != FEE_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_CFG_C    != FEE_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_CFG_C != FEE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fee_Cfg.c and Fee.h are different"
#endif
/* Check if current file and Fee header file are of the same Software version */
#if ((FEE_SW_MAJOR_VERSION_CFG_C != FEE_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_CFG_C != FEE_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_CFG_C != FEE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fee_Cfg.c and Fee.h are different"
#endif

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

#define FEE_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"

/* Configuration of cluster group FeeClusterGroup_0 */
FEE_CONST static const Fee_ClusterType Fee_FeeClusterGroup_0[2] = 
{
    /* FeeCluster_0 */
    {
    .StartAddr = 0x0U,
    .Length = 0x1000U,
    },
    /* FeeCluster_1 */
    {
    .StartAddr = 0x1000U,
    .Length = 0x1000U,
    },
};

/* Configuration of cluster group set */
FEE_CONST const Fee_ClusterGroupType Fee_ClrGrps[FEE_NUMBER_OF_CLUSTER_GROUPS] =
{
    /* FeeClusterGroup_0 */
    {
        .ClrPtr = Fee_FeeClusterGroup_0,
        .ClrCount = 2U,
        .ReservedSize = 0U,
    },
};

/* Configuration of Fee blocks */
FEE_CONST const Fee_BlockConfigType Fee_BlockConfig[FEE_CRT_CFG_NR_OF_BLOCKS] =
{
    /* The Fee Block 1 */
    {
        .BlockNumber = 1U,
        .BlockSize = 2U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 2 */
    {
        .BlockNumber = 2U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 3 */
    {
        .BlockNumber = 3U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 4 */
    {
        .BlockNumber = 4U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 5 */
    {
        .BlockNumber = 5U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 6 */
    {
        .BlockNumber = 6U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 7 */
    {
        .BlockNumber = 7U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 8 */
    {
        .BlockNumber = 8U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 9 */
    {
        .BlockNumber = 9U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 10 */
    {
        .BlockNumber = 10U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 11 */
    {
        .BlockNumber = 11U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 12 */
    {
        .BlockNumber = 12U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 13 */
    {
        .BlockNumber = 13U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 14 */
    {
        .BlockNumber = 14U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 15 */
    {
        .BlockNumber = 15U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 16 */
    {
        .BlockNumber = 16U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 17 */
    {
        .BlockNumber = 17U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 18 */
    {
        .BlockNumber = 18U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 19 */
    {
        .BlockNumber = 19U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 20 */
    {
        .BlockNumber = 20U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 21 */
    {
        .BlockNumber = 21U,
        .BlockSize = 19U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
    /* The Fee Block 22 */
    {
        .BlockNumber = 22U,
        .BlockSize = 156U,
        .ClrGrp = 0U,
        .ImmediateData = 0U,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        .BlockAssignment = FEE_PROJECT_APPLICATION,
#else
        .BlockAssignment = FEE_PROJECT_RESERVED,
#endif
    },
};

#define FEE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

