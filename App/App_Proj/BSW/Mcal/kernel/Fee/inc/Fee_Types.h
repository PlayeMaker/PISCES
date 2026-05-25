/**
 * @file    Fee_Types.h
 * @version V0.9.1
 *
 * @brief   AUTOSAR Fee module interface
 * @details API implementation for Fee driver
 *
 * @addtogroup FEE_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Fee
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V0.9.1
 *
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef FEE_TYPES_H
#define FEE_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif


/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Fee_Cfg.h"
#include "Std_Types.h"
#include "MemIf_Types.h"
#include "Fls.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_TYPES_VENDOR_ID                      (180)
#define FEE_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define FEE_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define FEE_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define FEE_TYPES_SW_MAJOR_VERSION               (0)
#define FEE_TYPES_SW_MINOR_VERSION               (9)
#define FEE_TYPES_SW_PATCH_VERSION               (1)


/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
 *                                         EXTERNAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/**
* @brief Fee block assignment type
*
*/
typedef enum
{
    FEE_PROJECT_SHARED          = 0x01U,     /**< block is used for all the projects */
    FEE_PROJECT_APPLICATION     = 0x02U,     /**< block is used for the application project */
    FEE_PROJECT_BOOTLOADER      = 0x03U,     /**< block is used for the bootloader project */
    FEE_PROJECT_RESERVED        = 0xFFU      /**< the value is reserved */
} Fee_BlockAssignmentType;

/**
* @brief        Fee block configuration structure
*
*/
typedef struct
{
    uint16 BlockNumber;                         /**< @brief Fee block number */
    uint16 BlockSize;                           /**< @brief Size of Fee block in bytes */
    uint8 ClrGrp;                               /**< @brief  Index of cluster group the Fee block belongs to */
    boolean ImmediateData;                      /**< @brief TRUE if immediate data block */
    Fee_BlockAssignmentType BlockAssignment;    /**< @brief specifies which project uses this block */
} Fee_BlockConfigType;

/**
* @brief Fee cluster configuration structure
*
*/
typedef struct
{
    Fls_AddressType StartAddr;   /**< @brief Address of Fee cluster in flash */

    Fls_LengthType Length;       /**< @brief Size of Fee cluster in bytes */
} Fee_ClusterType;

/**
* @brief Fee cluster group configuration structure
*
* @implements   Fee_ClusterGroupType_struct
*/
typedef struct
{
    const Fee_ClusterType *const ClrPtr;  /**< @brief Pointer to array of Fee cluster configurations */
    uint32 ClrCount;                      /**< @brief Number of clusters in cluster group */
    Fls_LengthType ReservedSize;          /**< @brief Size of reserved area in the given cluster group (memory occupied by immediate blocks) */
} Fee_ClusterGroupType;

/**
* @brief        Fee Configuration type is a stub type, not used, but required by ASR 4.2.2.
*
*/
typedef Fee_BlockConfigType Fee_ConfigType;

/**
* @brief        Fee block header configuration structure. This consists of block number and length of block and Type of Fee block
*
*/
typedef struct
{
    uint16  BlockNumber;     /**< @brief Number of block */
    uint16  Length;          /**< @brief Length of block */
    boolean ImmediateBlock;  /**< @brief Type of Fee block. Set to TRUE for immediate block */
} Fee_BlockType;

/**
* @brief        Fee cluster header configuration structure.
*
*/
typedef struct
{
    uint32                        ClrID;              /**< @brief 32-bit cluster ID */
    Fls_AddressType               StartAddr;          /**< @brief Start address of Fee cluster in Fls address space */
    Fls_LengthType                Length;             /**< @brief Length of Fee cluster in bytes */
} Fee_ClusterHeaderType;

/**
* @brief        Status of Fee block header
*/
typedef enum
{
    FEE_BLOCK_VALID = 0U,         /**< @brief Fee block is valid */
    FEE_BLOCK_INVALID = 1U,           /**< @brief Fee block is invalid (has been invalidated) */
    FEE_BLOCK_INCONSISTENT = 2U,      /**< @brief Fee block is inconsistent (contains bogus data) */
    FEE_BLOCK_HEADER_INVALID = 3U,    /**< @brief Fee block header is garbled */
    FEE_BLOCK_INVALIDATED = 4U,       /**< @brief Fee block header is invalidated by Fee_InvalidateBlock(BlockNumber)(not used when
                                      FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF) */
    FEE_BLOCK_HEADER_BLANK = 5U,      /**< @brief Fee block header is blank, it is used to mark the end of Fee block header list
                                      when parsing the memory at initialization*/
#if (FEE_MARK_EMPTY_BLOCKS_INVALID == STD_ON)
    FEE_BLOCK_INCONSISTENT_COPY = 6U  /**< @brief FEE data read error during swap (ie data area was allocated) */
#else
    FEE_BLOCK_INCONSISTENT_COPY = 6U, /**< @brief FEE data read error during swap (ie data area was allocated) */
    FEE_BLOCK_NEVER_WRITTEN = 7U      /**< @brief FEE block was never written in data flash */
#endif
} Fee_BlockStatusType;

/**
* @brief        Status of Fee cluster header
*
*/
typedef enum
{
    FEE_CLUSTER_VALID = 0U,       /**< @brief Fee cluster is valid */
    FEE_CLUSTER_INVALID = 1U,         /**< @brief Fee cluster is invalid */
    FEE_CLUSTER_INCONSISTENT = 3U,    /**< @brief Fee cluster is inconsistent (contains bogus data) */
    FEE_CLUSTER_HEADER_INVALID = 4U   /**< @brief Fee cluster header is garbled */
} Fee_ClusterStatusType;

/**
* @brief        Type of job currently executed by Fee_MainFunction
*
*/
typedef enum
{
    /* Fee_Read() related jobs */
    FEE_JOB_READ = 0U,                /**< @brief Read Fee block */
    /* Fee_Write() related jobs */
    FEE_JOB_WRITE = 1U,                   /**< @brief Write Fee block to flash */
    FEE_JOB_WRITE_DATA = 2U,              /**< @brief Write Fee block data to flash */
    FEE_JOB_WRITE_UNALIGNED_DATA = 3U,    /**< @brief Write unaligned rest of Fee block data to flash */
    FEE_JOB_WRITE_VALIDATE = 4U,          /**< @brief Validate Fee block by writing validation flag to flash */
    FEE_JOB_WRITE_DONE = 5U,              /**< @brief Finalize validation of Fee block */

    /* Fee_InvalidateBlock() related jobs */
    FEE_JOB_INVAL_BLOCK = 6U,             /**< @brief Invalidate Fee block by writing the invalidation flag to flash */
    FEE_JOB_INVAL_BLOCK_DONE = 7U,        /**< @brief Finalize invalidation of Fee block */

    /* Fee_EraseImmediateBlock() related jobs */
    FEE_JOB_ERASE_IMMEDIATE = 8U,         /**< @brief Erase (pre-allocate) immediate Fee block */

    /* Fee_Init() realted jobs */
    FEE_JOB_INT_SCAN = 9U,                /**< @brief Initialize the cluster scan job */
    FEE_JOB_INT_SCAN_CLR = 10U,            /**< @brief Scan active cluster of current cluster group */
    FEE_JOB_INT_SCAN_CLR_HDR_PARSE = 11U,  /**< @brief Parse Fee cluster header */
    FEE_JOB_INT_SCAN_CLR_FMT = 12U,        /**< @brief Format first Fee cluster */
    FEE_JOB_INT_SCAN_CLR_FMT_DONE = 13U,   /**< @brief Finalize format of first Fee cluster */
    FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE = 14U,/**< @brief Parse Fee block header */

    /* Internal swap jobs */
    FEE_JOB_INT_SWAP_CLR_FMT = 15U,        /**< @brief Format current Fee cluster in current Fee cluster group */
    FEE_JOB_INT_SWAP_BLOCK = 16U,          /**< @brief Copy next block from source to target cluster */
    FEE_JOB_INT_SWAP_DATA_READ = 17U,      /**< @brief Read data from source cluster to internal Fee buffer */
    FEE_JOB_INT_SWAP_DATA_WRITE = 18U,     /**< @brief Write data from internal Fee buffer to target cluster */
    FEE_JOB_INT_SWAP_CLR_VLD_DONE = 19U,   /**< @brief Finalize cluster validation */

    /* Fee system jobs */
    FEE_JOB_DONE = 20U,                    /**< @brief No more subsequent jobs to schedule */

    /* Fee_Setmode() related job */
    FEE_JOB_SETMODE = 21U,                 /**< @brief Setmode to fls */

    /*Fee Waiting Block Hdr write*/
    FEE_JOB_WRITE_BLOCK_HDR = 22U          /**< @brief Write Fee block header to flash */
} Fee_JobType;

/**
* @brief        Fee cluster group run-time Information
*/
typedef struct
{
    Fls_AddressType  ClusterTotalSpace;    /**< @brief Total space in the selected cluster group */
    Fls_AddressType  ClusterFreeSpace;     /**< @brief Free space in the selected cluster group */
    uint16           BlockHeaderOverhead; /**< @brief Block Overhead (header valid and inval flag)*/
    uint16           VirtualPageSize;     /**< @brief Fee Virtual Page Size */
    uint32           NumberOfSwap;         /**< @brief Number of cluster swap performed in the
                                                      selected cluster group */
#if (FEE_SECTOR_RETIREMENT == STD_ON)
    Fee_SectorRuntimeInfoType *SectorInfo; /**< @brief Pointer to the sector runtime information data structure */
#endif
} Fee_ClusterGroupRuntimeInfoType;

/**
* @brief        Fee cluster group run-time status
*
*/
typedef struct
{
    Fls_AddressType DataAddrIt;        /**< @brief Address of current Fee data block in flash */
    Fls_AddressType HdrAddrIt;         /**< @brief Address of current Fee block header in flash */
    uint32 ActClrID;                   /**< @brief ID of active cluster */
    uint8 ActClr;                      /**< @brief Index of active cluster */
} Fee_ClusterGroupInfoType;

/**
* @brief        Fee block run-time status
*
*/
typedef struct
{
    Fls_AddressType DataAddr;          /**< @brief Address of Fee block data in flash */
    Fls_AddressType InvalidAddr;       /**< @brief Address of Fee block invalidation field in flash */
    Fee_BlockStatusType BlockStatus;   /**< @brief Current status of Fee block */
} Fee_BlockInfoType;

#ifdef __cplusplus
}
#endif

#endif /* FEE_TYPES_H */

/** @} */

