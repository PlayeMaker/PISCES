/**
 * @file    Fee.h
 * @version V0.9.1
 *
 * @brief   AUTOSAR Fee module interface
 * @details API implementation for FEE driver
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

#ifndef FEE_H
#define FEE_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 1534 Rule 2.5:  A project should not contain unused macro definitions.
 *
 */
/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "Fee_Cfg.h"
#include "Fee_Types.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_VENDOR_ID                      (180)
#define FEE_AR_RELEASE_MAJOR_VERSION       (4)
#define FEE_AR_RELEASE_MINOR_VERSION       (4)
#define FEE_AR_RELEASE_REVISION_VERSION    (0)
#define FEE_SW_MAJOR_VERSION               (0)
#define FEE_SW_MINOR_VERSION               (9)
#define FEE_SW_PATCH_VERSION               (1)


/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and FEE configuration header file are of the same vendor */
#if (FEE_VENDOR_ID != FEE_VENDOR_ID_CFG)
#error "Fee.h and Fee_Cfg.h have different vendor ids"
#endif

/* Check if source file and FEE configuration header file are of the same Autosar version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION != FEE_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FEE_AR_RELEASE_MINOR_VERSION != FEE_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FEE_AR_RELEASE_REVISION_VERSION != FEE_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Fee.h and Fee_Cfg.h are different"
#endif

/* Check if source file and FEE configuration header file are of the same software version */
#if ((FEE_SW_MAJOR_VERSION != FEE_SW_MAJOR_VERSION_CFG) || \
     (FEE_SW_MINOR_VERSION != FEE_SW_MINOR_VERSION_CFG) || \
     (FEE_SW_PATCH_VERSION != FEE_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Fee.h and Fee_Cfg.h are different"
#endif

/* Check if source file and FEE type defined header file are of the same vendor */
#if (FEE_VENDOR_ID != FEE_TYPES_VENDOR_ID)
#error "Fee.h and Fee_Types.h have different vendor ids"
#endif

/* Check if source file and FEE type defined header file are of the same Autosar version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION != FEE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION != FEE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION != FEE_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Fee.h and Fee_Types.h are different"
#endif

/* Check if source file and FEE type defined header file are of the same software version */
#if ((FEE_SW_MAJOR_VERSION != FEE_TYPES_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION != FEE_TYPES_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION != FEE_TYPES_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Fee.h and Fee_Types.h are different"
#endif

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief FEE MODULE INSTANCE ID */
#define FEE_INSTANCE_ID ((uint8)0U)

/** @brief FEE MODULE ID */
#define FEE_MODULE_ID ((uint8)21U)


/**
 * @defgroup        Fee_SID
 * @brief           Service ID number for all FEE driver services
 * @{
 */
/* MR12 Rule 2.5 VIOLATION: These macros are AUTOSAR standard macros and cannot be deleted even
 *                          if not used. So it couldn't adhere to M3CM Rule-2.5
*/
/** @brief API Service ID for Fee_Init */
#define FEE_SID_INIT                                         ((uint8)0x00U)
/** @brief API Service ID for Fee_SetMode */
#define FEE_SID_SET_MODE                                     ((uint8)0x01U)
/** @brief API Service ID for Fee_Read */
#define FEE_SID_READ                                         ((uint8)0x02U)
/** @brief API Service ID for Fee_Write */
#define FEE_SID_WRITE                                        ((uint8)0x03U)
/** @brief API Service ID for Fee_Cancel */
#define FEE_SID_CANCEL                                       ((uint8)0x04U)
/** @brief API Service ID for Fee_GetStatus */
#define FEE_SID_GET_STATUS                                   ((uint8)0x05U) /*PRQA S 1534*/
/** @brief API Service ID for Fee_InvalidateBlock */
#define FEE_SID_INVALIDATE_BLOCK                             ((uint8)0x07U)
/** @brief API Service ID for Fee_GetJobResult */
#define FEE_SID_GET_JOB_RESULT                               ((uint8)0x06U)
/** @brief API Service ID for Fee_GetVersionInfo */
#define FEE_SID_GET_VERSION_INFO                             ((uint8)0x08U) /*PRQA S 1534*/
/** @brief API Service ID for Fee_EraseImmediateBlock */
#define FEE_SID_ERASE_IMMEDIATE_BLOCK                        ((uint8)0x09U)
/** @brief API Service ID for Fee_JobEndNotification */
#define FEE_SID_JOB_END_NOTIFICATION                         ((uint8)0x10U)
/** @brief API Service ID for Fee_JobErrorNotification */
#define FEE_SID_JOB_ERROR_NOTIFICATION                       ((uint8)0x11U)
/** @brief API Service ID for Fee_MainFunction */
#define FEE_SID_MAIN_FUNCTION                                ((uint8)0x12U) /*PRQA S 1534*/
/**  @brief service ID of function: Fee_GetRunTimeInfo. (passed to DET) */
#define FEE_SID_GET_RUNTIME_INFO                             ((uint8)0x13U)
/** @brief API service ID for Fee_ForceSwapOnNextWrite */
#define FEE_SID_FORCE_SWAP_ON_NEXT_WRITE                     ((uint8)0x14U)
/** @} */

/* Development error codes (passed to DET) */

/** @brief API called when module was not initialized */
#define FEE_E_UNINIT                   ((uint8)0x01U)

/** @brief API called with invalid block number */
#define FEE_E_INVALID_BLOCK_NO         ((uint8)0x02U)

/** @brief API called with invalid block offset */
#define FEE_E_INVALID_BLOCK_OFS        ((uint8)0x03U)

/** @brief API called with invalid data pointer */
#define FEE_E_PARAM_POINTER            ((uint8)0x04U)

/** @brief API called with invalid length information */
#define FEE_E_INVALID_BLOCK_LEN        ((uint8)0x05U)

/** @brief API called while module is busy processing a user request */
#define FEE_E_BUSY                     ((uint8)0x06U)

/** @brief API called while module is not busy because there is no job to cancel */
#define FEE_E_INVALID_CANCEL           ((uint8)0x08U)

/** @brief API Fee_init failed */
#define FEE_E_INIT_FAILED              ((uint8)0x09U)

/* Vendor Specific Definition */

#if (FEE_CANCEL_API == STD_OFF)
/** @brief API called when underlying driver has cancel API disabled */
#define FEE_E_CANCEL_API               ((uint8)0x0AU)
#endif

/** @brief API called with invalid cluster group index */
#define FEE_E_CLUSTER_GROUP_IDX        ((uint8)0x0BU)

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
/** @brief API number of foreign blocks from data flash exceeds the total number of blocks allowed which is FEE_MAX_NR_OF_BLOCKS */
#define FEE_E_FOREIGN_BLOCKS_OVF       ((uint8)0x0CU)
#endif



#if (FEE_SECTOR_RETIREMENT == STD_ON)
/* The number of bytes in a cluster header, used to store the sectors information */
#define FEE_CLUSTER_HEADER_SECTORINFO_SIZE    (8U)
/* The number of attempts when erasing each sector in the cluster in swap phase */
#define FEE_SECTOR_ERASE_RETRIES              (0U)

/* The number of attempts when erasing each sector in the cluster in swap phase */
#define FEE_NUMBER_OF_SECTORS_TO_RECOVER      (0U)
#endif

/*==================================================================================================
 *                                         EXTERNAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/



/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/


/**
 * @brief            Service to initialize the FEE module.
 * @details          The function Fee_Init shall initialize the Flash EEPROM
*                    Emulation module.
 * @param[in]        ConfigPtr Pointer to the selected configuration set.
 * @return           void
 */
void Fee_Init(const Fee_ConfigType *ConfigPtr);

#if( FEE_SETMODE_API_SUPPORTED == STD_ON )
/**
 * @brief            Function to switch the mode of the underlying Flash Driver
 * @details          This function is used to set the mode of the underlying Flash Driver
 * @param[in]        Mode Desired mode for the underlying flash driver
 * @return           void
 */
void Fee_SetMode(MemIf_ModeType Mode);
#endif /* FEE_SETMODE_API_SUPPORTED == STD_ON */
/**
 * @brief            Service to initiate a read job.
 * @details          The function Fee_Read initiate a read job for a block. It takes the block start address and
*                    offset and calculate the corresponding memory read address.
 * @param[in]        BlockNumber Number of logical block, also denoting start address of that block in flash memory.
 * @param[in]        BlockOffset Read address offset inside the block
 * @param[out]       DataBufferPtr Pointer to data buffer
 * @param[in]        Length Number of bytes to read
 * @return           Std_ReturnType
 */
Std_ReturnType Fee_Read(uint16 BlockNumber, uint16 BlockOffset, uint8 *DataBufferPtr, uint16 Length);

/**
 * @brief            Service to initiate a write job.
 * @details          The function Fee_Write initiate a write job for a block. It takes the block start address and
 *                  offset and calculate the corresponding memory write address.
 * @param[in]        BlockNumber Number of logical block, also denoting start address of that block in EEPROM.
 * @param[in]        DataBufferPtr Pointer to data buffer
 * @return           Std_ReturnType
 */
Std_ReturnType Fee_Write(uint16 BlockNumber, const uint8 *DataBufferPtr);

#if (FEE_CANCEL_API == STD_ON)
/**
 * @brief            Service to call the cancel function of the underlying flash driver.
 * @details          The function Fee_Cancel and the cancel function of the underlying flash driver are asynchronous
 *                   w.r.t. an ongoing read, erase or write job in the flash memory.
 * @return           void
 */
void Fee_Cancel(void);
#endif/* FEE_CANCEL_API == STD_ON */

/**
 * @brief            Service to invalidate a logical block.
 * @details          The function Fee_InvalidateBlock invalidate the block in the flash memory.
 * @param[in]        BlockNumber Number of logical block, also denoting start address of that block in flash memory.
 * @return           Std_ReturnType
 */
Std_ReturnType Fee_InvalidateBlock(uint16 BlockNumber);

/**
 * @brief            Service to erase a logical block.
 * @details          The function Fee_EraseImmediateBlock shall take the block number and calculate the corresponding
 *                   memory block address.The function Fee_EraseImmediateBlock shall ensure that the FEE module can
 *                   write immediate data. Whether this involves physically erasing a memory area and therefore calling
 *                   the erase function of the underlying driver depends on the implementation.If development error
 *                   detection for the FEE module is enabled,the function Fee_EraseImmediateBlock shall check whether the
 *                   addressed logical block is configured as containing immediate data (configuration parameter
 *                   FeeImmediateData == TRUE). If not, the function Fee_EraseImmediateBlock shall report the error
 *                   code FEE_E_INVALID_BLOCK_NO.
 * @param[in]        BlockNumber Number of logical block, also denoting start address of that block in EEPROM.
 * @return           Std_ReturnType
 */
Std_ReturnType Fee_EraseImmediateBlock(uint16 BlockNumber);

/**
 * @brief            Return the result of the last job.
 * @details          Return the result of the last job synchronously.
 * @return           MemIf_JobResultType
 */
MemIf_JobResultType Fee_GetJobResult(void);

/**
 * @brief            Service to return the status.
 * @details          Return the status of the FEE module.
 * @return           MemIf_StatusType
 */
MemIf_StatusType Fee_GetStatus(void);

/**
* @brief        Service to prepare the driver for a cluster swap in the selected cluster group.
* @details      While the computed amount of memory is allocated as a result of Fee_Write
*               call for plain data blocks, for immediate data blocks memory gets completely
*               pre-allocated through Fee_EraseImmediateBlock function (i.e. Fee_Write does
*               not change the remaining space).
*               As a result, swaps triggered by the planned Fee_ForceSwapOnNextWrite function
*               behave the same way, or in other words, an operation that really activates the
*               pysical swap must be either Fee_Write on plain FEE block or
*               Fee_EraseImmediateBlock on immediate data block.
*
* @param[in]    ClrGrpIndex    Index of the selected cluster group
* @return       Std_ReturnType
*/
extern Std_ReturnType Fee_ForceSwapOnNextWrite(uint8 ClrGrpIndex);

/**
* @brief        Service to read runtime information in the selected cluster.
*
* @param[in]    ClrGrpIndex    Index of the selected cluster group
* @param[out]   ClrGrpRTInfo   Pointer to point Fee cluster group run-time Information
*
* @return       Fee_ClusterGroupRuntimeInfoType
* @retval       ClusterTotalSpace current cluster total size
* @retval       ClusterFreeSpace current cluster available space.
* @retval       BlockHeaderOverhead the block header overhead (blk header, valid flag and inval flag),
* @retval       VirtualPageSize the virtual page size (the size of an allocation unit)
* @retval       NumberOfSwap number of cluster swap already performed
* @retval       SectorInfo sector information from all clusters in the selected cluster group (in sector retirement mode only)
*
* @pre          The module must be initialized, not busy and uClrGrpIndex must be valid
*
*/
extern void Fee_GetRunTimeInfo(uint8 ClrGrpIndex, Fee_ClusterGroupRuntimeInfoType *ClrGrpRTInfo);

/**
 * @brief            Service to handle the requested read / write / erase jobs and the internal management operations.
 * @details          The function shall asynchronously handle the requested read, write, or erase jobs respectively the
 *                   internal management operations. The function shall check, whether the block requested for reading
 *                   has been invalidated by the upper layer module. If so, the function shall set the job result to
 *                   MEMIF_BLOCK_INVALID and call the error notification routine of the upper layer if configured.
 *                   The function shall check the consistency of the logical block being read before notifying the
 *                   caller. If an inconsistency of the read data is detected, the function shall set the job result
 *                   to MEMIF_BLOCK_INCONSISTENT and call the error notification routine of the upper layer.
 * @return           void
 */
extern void Fee_MainFunction(void);

#if (((FEE_VERSION_INFO_API == STD_ON) && (FEE_DEV_ERROR_DETECT == STD_ON)))
/**
 * @brief            Returns the version information of this module.
 * @details          The function Fee_GetVersionInfo() shall return the version information of this module.
 * @param[out]       versioninfo Pointer to where to store version information of this module
 * @return           none
 */
#define Fee_GetVersionInfo(versioninfo)                                       \
    {                                                                          \
        /* Check for DET: FEE_E_PARAM_POINTER */                              \
        if ((versioninfo) == NULL_PTR)                                         \
        {                                                                      \
            /* Report FEE_E_PARAM_POINTER DET if service called with          \
               NULL_PTR                                                        \
            */                                                                 \
            Det_ReportError(                                                   \
                (uint16)FEE_MODULE_ID,                                        \
                FEE_INSTANCE_ID,                                              \
                FEE_SID_GET_VERSION_INFO,                                       \
                FEE_E_PARAM_POINTER);                                         \
        }                                                                      \
        else                                                                   \
        {                                                                      \
            /* Vendor ID information */                                        \
            ((Std_VersionInfoType *)(versioninfo))->vendorID = FEE_VENDOR_ID; \
            /* Fee module ID information */                                   \
            ((Std_VersionInfoType *)(versioninfo))->moduleID = FEE_MODULE_ID; \
            /* Fee module Software major version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_major_version =         \
                (uint8)FEE_SW_MAJOR_VERSION;                                  \
            /* Fee module Software minor version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =         \
                (uint8)FEE_SW_MINOR_VERSION;                                  \
            /* Fee module Software patch version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =         \
                (uint8)FEE_SW_PATCH_VERSION;                                  \
        }                                                                      \
    }/*PRQA S 1534*/
#elif (((FEE_VERSION_INFO_API == STD_ON) && (FEE_DEV_ERROR_DETECT == STD_OFF)))
#define Fee_GetVersionInfo(versioninfo)                                   \
    {                                                                      \
        /* Vendor ID information */                                        \
        ((Std_VersionInfoType *)(versioninfo))->vendorID = FEE_VENDOR_ID; \
        /* Fee module ID information */                                   \
        ((Std_VersionInfoType *)(versioninfo))->moduleID = FEE_MODULE_ID; \
        /* Fee module Software major version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_major_version =         \
            (uint8)FEE_SW_MAJOR_VERSION;                                  \
        /* Fee module Software minor version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =         \
            (uint8)FEE_SW_MINOR_VERSION;                                  \
        /* Fee module Software patch version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =         \
            (uint8)FEE_SW_PATCH_VERSION;                                  \
    }/*PRQA S 1534*/
#endif   /* FEE_VERSION_INFO_API == STD_ON && FEE_DEV_ERROR_DETECT == STD_ON */



#ifdef __cplusplus
}
#endif

#endif /* FEE_H */

/** @} */

