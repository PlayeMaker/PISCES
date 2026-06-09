/*
* @file    CddDma.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : CddDma
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V0.9.1
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef CDDDMA_H
#define CDDDMA_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "CddDma_Types.h"
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define CDDDMA_VENDOR_ID                      (180)
#define CDDDMA_AR_RELEASE_MAJOR_VERSION       (4)
#define CDDDMA_AR_RELEASE_MINOR_VERSION       (4)
#define CDDDMA_AR_RELEASE_REVISION_VERSION    (0)
#define CDDDMA_SW_MAJOR_VERSION               (0)
#define CDDDMA_SW_MINOR_VERSION               (9)
#define CDDDMA_SW_PATCH_VERSION               (1)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CddDma_Types.h file are of the same vendor */
#if (CDDDMA_VENDOR_ID != CDDDMA_TYPES_VENDOR_ID)
#error "CddDma.h and CddDma_Types.h have different vendor ids"
#endif
/* Check if source file and CddDma_Types.h file are of the same Autosar version */
#if ((CDDDMA_AR_RELEASE_MAJOR_VERSION != CDDDMA_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CDDDMA_AR_RELEASE_MINOR_VERSION != CDDDMA_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CDDDMA_AR_RELEASE_REVISION_VERSION != CDDDMA_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CddDma.h and CddDma_Types.h are different"
#endif
/* Check if source file and DMA configuration header file are of the same software version */
#if ((CDDDMA_SW_MAJOR_VERSION != CDDDMA_TYPES_SW_MAJOR_VERSION) || \
     (CDDDMA_SW_MINOR_VERSION != CDDDMA_TYPES_SW_MINOR_VERSION) || \
     (CDDDMA_SW_PATCH_VERSION != CDDDMA_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of CddDma.h and CddDma_Types.h are different"
#endif
/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/

#define CDDDMA_UNDEFINED_PARAMETER             (0xDEADBEEFU)  /** @brief Undefined callback parameter value */

#define CDDDMA_INSTANCE_ID                     ((uint8)0U)     /** @brief CDDDMA MODULE INSTANCE ID */
#define CDDDMA_MODULE_ID                       ((uint16)256U)  /** @brief CDDDMA MODULE ID */

#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
/**
 * @defgroup        CDDDMA_DEV_ERROR
 * @brief           CddDma development errors
 * @{
 */
#define CDDDMA_E_ALREADY_INITIALIZED           ((uint8)0x10)  /** @brief The CddDma module is already initialized */
#define CDDDMA_E_OUT_OF_RANGE                  ((uint8)0x11)  /** @brief The specified DMA channel number is out of the valid range. */
#define CDDDMA_E_ADDR_INVALID                  ((uint8)0x12)  /** @brief The provided transfer address is not valid for DMA operation */
#define CDDDMA_E_PARAM_POINTER                 ((uint8)0x13)  /** @brief API called with an invalid (NULL) pointer parameter.*/
#define CDDDMA_E_RAMRELOAD_ADDR_UNALIGNED      ((uint8)0x14)  /** @brief The address of TCD for ram reload is not 32Byte aligned*/
#define CDDDMA_E_ADDR_UNALIGNED                ((uint8)0x15)  /** @brief The address of source or destination is not aligned */
#define CDDDMA_E_LOOPCOUNT_INVALID             ((uint8)0x16)  /** @brief The parameter of transfer loop count is invalid */
#define CDDDMA_E_UNINIT                        ((uint8)0x17)  /** @brief API called without module initialization */
/** @} */
#endif

/**
 * @defgroup        CDDDMA_SID
 * @brief           CddDma API Service IDs
 * @{
 */
#define CDDDMA_SID_INIT                        (0x01U)  /** @brief API Service ID for CddDma_Init */
#define CDDDMA_SID_DEINIT                      (0x02U)  /** @brief API Service ID for CddDma_DeInit */
#define CDDDMA_SID_SET_LOGIC_CHANNEL_TRANSFER  (0x03U)  /** @brief API Service ID for CddDma_SetLogicChannelTransfer */
#define CDDDMA_SID_START_CHANNEL               (0x04U)  /** @brief API Service ID for CddDma_StartChannel */
#define CDDDMA_SID_STOP_CHANNEL                (0x05U)  /** @brief API Service ID for CddDma_StopChannel */
#define CDDDMA_SID_SOFT_TRIGGER                (0x06U)  /** @brief API Service ID for CddDma_SoftTrigger */
#define CDDDMA_SID_CONFIG_RAM_RELOAD           (0x07U)  /** @brief API Service ID for CddDma_ChannelRamReloadConfig */
#define CDDDMA_SID_INSTALL_CALLBACK            (0x08U)  /** @brief API Service ID for CddDma_InstallCallback */
#define CDDDMA_SID_INSTALL_ERROR_CALLBACK      (0x09U)  /** @brief API Service ID for CddDma_InstallErrorCallback */
#define CDDDMA_SID_GET_CHANNEL_STATUS          (0x0AU)  /** @brief API Service ID for CddDma_GetChannelStatus */
#define CDDDMA_SID_CLEAR_CHANNEL_DONE_STATUS   (0x0BU)  /** @brief API Service ID for CddDma_ClearChannelDoneStatus */
#define CDDDMA_SID_GET_VERSION_INFO            (0x0CU)  /** @brief API Service ID for CddDma_GetVersionInfo */
#define CDDDMA_SID_GET_REMAINING_TRIGGER_COUNT (0x0DU)  /** @brief API Service ID for CddDma_GetRemainingTriggerCount */
/** @} */

/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/*==================================================================================================
 *                                             TYPEDEF
==================================================================================================*/
/*==================================================================================================
 *                                             VARIATES
==================================================================================================*/
/*==================================================================================================
 *                                             EXTERNAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
 *                                             GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief         Initializes the DMA module and its run-time state structure, sets the DMA hardware, and applies user-defined and default settings.
 *                Allocates, releases, protects, and tracks the state for all DMA channels.
 *
 * @details       Service ID: 0x01
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma.h
 *
 * @param[in] ConfigPtr: Pointer to user configuration structure for DMA peripheral drivers.
 * @return void
*/
void CddDma_Init(const CddDma_ConfigType *ConfigPtr);

/**
 * @brief         Resets the DMA module to its power-on state and resets all global variables and internal state.
 *
 * @details       Service ID: 0x02
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma.h
 *
 * @return void
*/
void CddDma_DeInit(void);

/**
 * @brief         Enables the DMA hardware request to start the DMA transfer operation for the specified channel.
 *
 * @details       Service ID: 0x04
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma.h
 *
 * @param[in] Channel: DMA channel number.
 * @return void
*/
void CddDma_StartChannel(CddDma_ChannelType Channel);

/**
 * @brief         Disables the DMA hardware request for the specified channel.
 *
 * @details       Service ID: 0x05
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma.h
 *
 * @param[in] Channel: DMA channel number.
 * @return void
*/
void CddDma_StopChannel(CddDma_ChannelType Channel);

/**
 * @brief         Starts a DMA transfer on the specified channel by issuing a software trigger request.
 *
 * @details       Service ID: 0x06
 *                Sync/Async: Asynchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma.h
 *
 * @param[in] Channel: DMA channel number.
 * @return void
*/
void CddDma_SoftTrigger(CddDma_ChannelType Channel);

/**
* @brief         Configures the DMA transfer settings for a specified channel, supporting loop chain or multi-block transfer. Updates the
*                Channel Transfer Structure (CTS) with user-defined parameters, including source/destination addresses, transfer size, offsets,
*                and loop properties.
*
* @details       Service ID: 0x03
*                Sync/Async: Synchronous
*                Reentrancy: Reentrant
*                Available via: CddDma.h
*
* @param[in] Channel: DMA channel number.
* @param[in] SrcAddr: Source register or memory address.
* @param[in] DestAddr: Destination register or memory address.
* @param[in] TransferConfig: Pointer to transfer configuration structure, including loop chain properties.
* @return StatusType
* @retval E_OK is returned if the DMA channel is configured successfully
* @retval E_NOT_OK is returned if the DMA channel configuration is not asserted
*/
StatusType CddDma_SetLogicChannelTransfer(CddDma_ChannelType Channel,
        uint32 SrcAddr,
        uint32 DestAddr,
        const CddDma_TransferConfigType *TransferConfig);

#ifndef CPU_YTM32B1HA0
/**
 * @brief         Configures the CTS descriptors into a single linked List or circular linked List. The user passes blocks of memory into this
 *                function. The loop done interrupt is triggered only when the last memory block is completed, if loop mode is enabled the loop done
 *                interrupt is triggered every time when a loop is completed. The memory block information is passed with the CddDma_RamReloadListType
 *                data structure, which can tell the memory source and destination address.
 *                NOTE: Expect for the source/destination address, all other parameters related to the transmission(such as offset, BCNT, TCNT,
 *                      TCNTRV..) are consistent with the third input parameter 'TransferConfig'.
 *
 * @details       Service ID: 0x07
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma.h
 *
 * @param[in] Channel: DMA channel number.
 * @param[in] List: Pointer to data structure storing the source and destination addresses for each memory block.
 * @param[in] TransferConfig: Pointer to transfer configuration structure, defines basic transfer and loop chain properties.
 * @param[in] Scts: Array of empty software CTS structures, user must prepare this memory block (32-byte aligned).
 * @param[in] CtsCount: Number of CTS memory blocks contained in the ram reload list.
 * @param[in] LoopMode: Enable/disable cycle mode for circular linked list operation.  Such as
 *                      [first TransferConfig]->[Scts 0]->[Scts 1]->...[Scts n] or [first TransferConfig]->[Scts 0]->[Scts 1]->...[Scts n]->NULL_PTR;
 *                                                 |                        v
 *                                                 |____________<___________|
 * @return void
*/
void CddDma_ChannelRamReloadConfig(CddDma_ChannelType Channel,
                                   const CddDma_RamReloadListType *List,
                                   CddDma_TransferConfigType *TransferConfig,
                                   CddDma_SoftwareCtsType *Scts,
                                   uint8 CtsCount,
                                   boolean LoopMode);
#endif

/**
 * @brief         Registers a user callback function and parameter for a specified DMA channel.
 *                The callback is invoked when the channel completes a transfer.
 *
 * @details       Service ID: 0x08
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma.h
 *
 * @param[in] Channel: DMA channel number.
 * @param[in] Callback: Pointer to the user callback function.
 * @param[in] Parameter: Parameter value passed to the callback function.
 * @return void
*/
void CddDma_InstallCallback(CddDma_ChannelType Channel, CddDma_CallbackType Callback, uint32 Parameter);

/**
 * @brief         Registers a user error callback function and parameter for a specified DMA channel.
 *                The callback is invoked when a channel error event occurs during DMA transfer.
 *
 * @details       Service ID: 0x09
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma.h
 *
 * @param[in] Channel: DMA channel number.
 * @param[in] Callback: Pointer to the user error callback function.
 * @param[in] Parameter: Parameter value passed to the error callback function.
 * @return void
*/
void CddDma_InstallErrorCallback(CddDma_ChannelType Channel, CddDma_CallbackType Callback, uint32 Parameter);

/**
 * @brief         Gets the DMA channel status. This service reads and returns the current status of the specified DMA channel.
 *
 * @details       Service ID: 0x0A
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma.h
 *
 * @param[in] Channel: DMA channel number.
 * @param[out] ChannelStatus: Pointer to the DMA channel status structure to be filled.
 * @return void
*/
void CddDma_GetChannelStatus(CddDma_ChannelType Channel, CddDma_ChannelStatusReturnType *ChannelStatus);

/**
 * @brief         Clears the 'Done' status flag for the specified DMA channel.
 *                This function is typically used in polling mode.
 * @details       Service ID: 0x0B
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma.h
 *
 * @param[in] Channel: DMA channel number.
 * @return void
 */
void CddDma_ClearChannelDoneStatus(CddDma_ChannelType Channel);

/**
 * @brief         Returns the remaining trigger count of the specified DMA channel, indicating how many transfer requests are left to be processed.
 * @autosar       N/A
 *
 * @details       Service ID: 0x0D
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma.h
 *
 * @param[in] Channel: DMA channel number.
 * @return uint32 - Remaining trigger count for the specified DMA channel.
*/
uint32 CddDma_GetChannelRemainingTriggerCount(CddDma_ChannelType Channel);

#if (((CDDDMA_VERSION_INFO_API == STD_ON) && (CDDDMA_DEV_ERROR_DETECT == STD_ON)))
/**
* @brief         Returns the version information of the CddDma module, including vendor ID, module ID, and software version numbers.
*
* @details       Service ID: 0x0C
*                Sync/Async: Synchronous
*                Reentrancy: Reentrant
*                Available via: CddDma.h
*
* @param[out] Versioninfo: Pointer to where to store version information of this module.
* @return void
*/
#define CddDma_GetVersionInfo(Versioninfo)                                        \
    {                                                                             \
        /* Check for DET: CDDDMA_E_PARAM_POINTER */                               \
        if ((Versioninfo) == NULL_PTR)                                            \
        {                                                                         \
            /* Report CDDDMA_E_PARAM_POINTER DET if service called with           \
               NULL_PTR                                                           \
            */                                                                    \
            Det_ReportError(                                                      \
                (uint16)CDDDMA_MODULE_ID,                                         \
                CDDDMA_INSTANCE_ID,                                               \
                CDDDMA_SID_GET_VERSION_INFO,                                      \
                CDDDMA_E_PARAM_POINTER);                                          \
        }                                                                         \
        else                                                                      \
        {                                                                         \
            /* Vendor ID information */                                           \
            ((Std_VersionInfoType *)(Versioninfo))->vendorID = CDDDMA_VENDOR_ID;  \
            /* CddDma module ID information */                                    \
            ((Std_VersionInfoType *)(Versioninfo))->moduleID = CDDDMA_MODULE_ID;  \
            /* CddDma module Software major version information */                \
            ((Std_VersionInfoType *)(Versioninfo))->sw_major_version =            \
                (uint8)CDDDMA_SW_MAJOR_VERSION;                                   \
            /* CddDma module Software minor version information */                \
            ((Std_VersionInfoType *)(Versioninfo))->sw_minor_version =            \
                (uint8)CDDDMA_SW_MINOR_VERSION;                                   \
            /* CddDma module Software patch version information */                \
            ((Std_VersionInfoType *)(Versioninfo))->sw_patch_version =            \
                (uint8)CDDDMA_SW_PATCH_VERSION;                                   \
        }                                                                         \
    }
#elif (((CDDDMA_VERSION_INFO_API == STD_ON) && (CDDDMA_DEV_ERROR_DETECT == STD_OFF)))
#define CddDma_GetVersionInfo(Versioninfo)                                        \
    {                                                                             \
        /* Vendor ID information */                                               \
        ((Std_VersionInfoType *)(Versioninfo))->vendorID = CDDDMA_VENDOR_ID;      \
        /* CddDma module ID information */                                        \
        ((Std_VersionInfoType *)(Versioninfo))->moduleID = CDDDMA_MODULE_ID;      \
        /* CddDma module Software major version information */                    \
        ((Std_VersionInfoType *)(Versioninfo))->sw_major_version =                \
            (uint8)CDDDMA_SW_MAJOR_VERSION;                                       \
        /* CddDma module Software minor version information */                    \
        ((Std_VersionInfoType *)(Versioninfo))->sw_minor_version =                \
            (uint8)CDDDMA_SW_MINOR_VERSION;                                       \
        /* CddDma module Software patch version information */                    \
        ((Std_VersionInfoType *)(Versioninfo))->sw_patch_version =                \
            (uint8)CDDDMA_SW_PATCH_VERSION;                                       \
    }
#endif /* CDDDMA_VERSION_INFO_API == STD_ON && CDDDMA_DEV_ERROR_DETECT == STD_ON */
#ifdef __cplusplus
}
#endif

#endif /* End of file CddDma.h */

