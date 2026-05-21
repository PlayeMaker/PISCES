/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Fee_Cfg.h
 * @brief 
 * 
 */


#ifndef FEE_CFG_H
#define FEE_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_VENDOR_ID_CFG                      (180)
#define FEE_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define FEE_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define FEE_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define FEE_SW_MAJOR_VERSION_CFG               (0)
#define FEE_SW_MINOR_VERSION_CFG               (9)
#define FEE_SW_PATCH_VERSION_CFG               (1)

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/
    
/*==================================================================================================
 *                                       FeeGeneral
==================================================================================================*/
/**
 * @brief   Switches the development error detection and notification on or off.
 * @details true: detection and notification is enabled.
            false: detection and notification is disabled. 
 * @ref     ECUC_Fee_00111
 */
#define FEE_DEV_ERROR_DETECT                (STD_OFF)

/**
 * @brief   Compile switch to enable / disable the version information API
 * @details true: API enabled
            false: API disabled 
 * @ref     ECUC_Fee_00115
 */
#define FEE_VERSION_INFO_API                (STD_ON)

/**
 * @brief   Pre-processor switch to enable and disable the polling mode for this module.
 * @details unused
 *          true: Polling mode enabled, callback functions (provided to FLS module) disabled.
            false: Polling mode disabled, callback functions (provided to FLS module) enabled.
 * @ref     ECUC_Fee_00114
 */
#define FEE_POLLING_MODE                    (STD_OFF)

/**
 * @brief   Compiler switch to enable/disable the 'SetMode' functionality of the FEE module.
 * @details true: SetMode functionality supported / code present
            false: SetMode functionality not supported / code not present.
 * @ref     ECUC_Fee_00119
 */
#define FEE_SETMODE_API_SUPPORTED           (STD_ON)

/**
 * @brief   Compiler switch to enable/disable the Fls_Cancel function of the FEE module.
 * @details true: API enabled
            false: API disabled 
 */
#define FEE_CANCEL_API                      (STD_ON)

/**
 * @brief   If reset, power loss etc. occurs here, neither newly nor previously written data is available.
 */
#define FEE_BLOCK_ALWAYS_AVAILABLE          (STD_ON)

/**
 * @brief   Behavior of Fee_ImmediateBlockErase.
 */
#define FEE_LEGACY_IMM_ERASE_MODE           (STD_ON)

/**
 * @brief   This configuration defines whether Fee should swap foreign blocks found in flash at swap or not.
 */
#define FEE_SWAP_FOREIGN_BLOCKS_ENABLED     (STD_ON)

/**
 * @brief   This configuration defines for which project the Fee configuration is used.
 */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
#define FEE_BOOTLOADER_CONFIG               (STD_OFF)
#endif

/**
 * @brief   This configuration defines if the status for the never written blocks must be INVALID or INCONSISTENT.
 */
#define FEE_MARK_EMPTY_BLOCKS_INVALID       (STD_ON)

/**
 * @brief This configuration defines the schm is supported or not.
*/

#define FEE_SCHM_SUPPORT                    (STD_ON)

/* This configuration enables the sector retirement feature */
#define FEE_SECTOR_RETIREMENT               (STD_OFF)

/**
 * @brief   Number of configured Fee blocks.
 */
#define FEE_CRT_CFG_NR_OF_BLOCKS            (22U)

/**
 * @brief   Maximum number of Fee blocks in all project versions and configurations.
 */
#define FEE_MAX_NR_OF_BLOCKS                (30U)

/**
 * @brief   The size in bytes to which logical blocks shall be aligned.
 * @details 0-65535
 * @ref     ECUC_Fee_00116
 */
#define FEE_VIRTUAL_PAGE_SIZE               (8U)

/**
 * @brief   Size of the data buffer in bytes.
 */
#define FEE_DATA_BUFFER_SIZE                (32U)
/**
 * @brief   The period between successive calls to the main function in seconds.
 * @details unused
 * @ref     ECUC_Fee_00153
 */
#define FEE_MAIN_FUNCTION_PERIOD            (0.005)

/**
 * @brief   Mapped to the job end notification routine provided by the upper layer module (NvM_JobEndNotification).
 * @ref     ECUC_Fee_00112
 */
#define FEE_NVM_JOB_END_NOTIFICATION        NvM_JobEndNotification()

/**
 * @brief   Mapped to the job error notification routine provided by the upper layer module (NvM_JobErrorNotification).
 * @ref     ECUC_Fee_00113
 */
#define FEE_NVM_JOB_ERROR_NOTIFICATION      NvM_JobErrorNotification()


/*==================================================================================================
 *                                       FeePublishedInformation
==================================================================================================*/

/**
 * @brief   Management overhead per logical block in bytes.
 */
#define FEE_BLOCK_OVERHEAD                  (32U)

/**
 * @brief   Management overhead per logical cluster in bytes.
 */
#define FEE_CLUSTER_OVERHEAD                (32U)

/*==================================================================================================
 *                                       FeeClusterGroup
==================================================================================================*/

/**
 * @brief   Number of configured Fee cluster group.
 */
#define FEE_NUMBER_OF_CLUSTER_GROUPS        (1U)

/*==================================================================================================
 *                                       FeeDefault (DO NOT MODIFY MANUALLY!)
==================================================================================================*/

/**
 * @brief   The contents of an erased flash memory cell.
 */
#define FEE_ERASED_VALUE                    (0xFFU)

/**
 * @brief   Value of the block and cluster validation flag.
 */
#define FEE_VALIDATED_VALUE                 (0x81U)

/**
 * @brief   Value of the block and cluster invalidation flag.
 */
#define FEE_INVALIDATED_VALUE               (0x18U)

/*==================================================================================================
 *                                       FeeBlockConfiguration
==================================================================================================*/

/**
 * @brief   Symbolic names of configured Fee block's number and block's size.
 */
#define FeeConf_FeeBlockConfiguration_Block_CfgID   (1U)

#define FeeConf_FeeBlockConfiguration_Block_CfgID_BlockSize   (2U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_0   (2U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_0_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_1   (3U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_1_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_2   (4U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_2_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_3   (5U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_3_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_4   (6U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_4_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_5   (7U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_5_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_6   (8U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_6_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_7   (9U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_7_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_8   (10U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_8_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_9   (11U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_9_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_10   (12U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_10_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_11   (13U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_11_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_12   (14U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_12_BlockSize   (1U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_13   (15U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_13_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_14   (16U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_14_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_15   (17U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_15_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_16   (18U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_16_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_17   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_17_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_18   (20U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_18_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_19   (21U)

#define FeeConf_FeeBlockConfiguration_FEE_PrimaryDataEntry_0_19_BlockSize   (19U)

#define FeeConf_FeeBlockConfiguration_FEE_Dem_StorageMem   (22U)

#define FeeConf_FeeBlockConfiguration_FEE_Dem_StorageMem_BlockSize   (156U)


/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                   FUNCTION PROTOTYPES
==================================================================================================*/

/**
 * @brief   Job end notification routine provided by the upper layer module (declaration).
 */
extern void NvM_JobEndNotification(void);

/**
 * @brief   Job error notification routine provided by the upper layer module (declaration).
 */
extern void NvM_JobErrorNotification(void);

#ifdef __cplusplus
}
#endif

#endif /* FEE_CFG_H */

/** @} */

