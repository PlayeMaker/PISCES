/*
* @file    CddDma_Lld.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : CddDma_Lld
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V0.9.1
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef CDDDMA_LLD_H
#define CDDDMA_LLD_H

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
#define CDDDMA_LLD_VENDOR_ID                      (180)
#define CDDDMA_LLD_AR_RELEASE_MAJOR_VERSION       (4)
#define CDDDMA_LLD_AR_RELEASE_MINOR_VERSION       (4)
#define CDDDMA_LLD_AR_RELEASE_REVISION_VERSION    (0)
#define CDDDMA_LLD_SW_MAJOR_VERSION               (0)
#define CDDDMA_LLD_SW_MINOR_VERSION               (9)
#define CDDDMA_LLD_SW_PATCH_VERSION               (1)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CddDma_Types.h file are of the same vendor */
#if (CDDDMA_LLD_VENDOR_ID != CDDDMA_TYPES_VENDOR_ID)
#error "CddDma_Lld.h and CddDma_Types.h have different vendor ids"
#endif

/* Check if source file and CddDma_Types.h file are of the same Autosar version */
#if ((CDDDMA_LLD_AR_RELEASE_MAJOR_VERSION != CDDDMA_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CDDDMA_LLD_AR_RELEASE_MINOR_VERSION != CDDDMA_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CDDDMA_LLD_AR_RELEASE_REVISION_VERSION != CDDDMA_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CddDma_Lld.h and CddDma_Types.h are different"
#endif

/* Check if source file and DMA configuration header file are of the same software version */
#if ((CDDDMA_LLD_SW_MAJOR_VERSION != CDDDMA_TYPES_SW_MAJOR_VERSION) || \
     (CDDDMA_LLD_SW_MINOR_VERSION != CDDDMA_TYPES_SW_MINOR_VERSION) || \
     (CDDDMA_LLD_SW_PATCH_VERSION != CDDDMA_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of CddDma_Lld.h and CddDma_Types.h are different"
#endif

/*==================================================================================================
                                                DEFINES AND MACROS
==================================================================================================*/
/*==================================================================================================
                                                EXTERNAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                ENUMS
==================================================================================================*/
/*==================================================================================================
                                                FUNCTION PROTOTYPES
==================================================================================================*/

/**
* @brief         Initializes the DMA low-level driver by configuring hardware registers and setting up channel state management structures.
* @autosar       N/A
*
* @details       Service ID: N/A (Internal Function)
*                Sync/Async: Synchronous
*                Reentrancy: Non Reentrant
*                Available via: CddDma_Lld.h
*
* @param[in] ConfigPtr: Pointer to DMA configuration structure containing initialization parameters.
* @return void
*/
void CddDma_Lld_Init(const CddDma_ConfigType *ConfigPtr);

/**
 * @brief         Deinitializes the DMA low-level driver by performing hardware reset and clearing all software channel state information.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.h
 *
 * @return void
*/
void CddDma_Lld_Deinit(void);

/**
 * @brief         Enables or disables DMA request functionality for a specific channel with platform-specific hardware request control mechanisms.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma_Lld.h
 *
 * @param[in] Channel: DMA channel number.
 * @param[in] Enable: Enable (true) or disable (false) DMA request.
 * @return void
*/
void CddDma_Lld_SetDmaRequestCmd(uint8 Channel, boolean Enable);

/**
 * @brief         Triggers the start of a DMA transfer on a specified channel by software.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma_Lld.h
 *
 * @param[in] Channel: DMA channel number.
 * @return void
*/
void CddDma_Lld_TriggerChannelStart(uint8 Channel);

/**
 * @brief         Configures comprehensive DMA transfer parameters by copying configuration structure to hardware registers.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma_Lld.h
 *
 * @param[in] Channel: DMA channel number.
 * @param[in] TransferConfig: Pointer to transfer configuration structure containing all transfer properties including basic settings and
 *                            optional loop chain configurations.
 * @return void
*/
void CddDma_Lld_SetChannelTransfer(uint8 Channel, const CddDma_TransferConfigType *TransferConfig);

/**
* @brief         Retrieves the remaining trigger count for a DMA channel, indicating how many major loop iterations are left to complete.
* @autosar       N/A
*
* @details       Service ID: N/A (Internal Function)
*                Sync/Async: Synchronous
*                Reentrancy: Reentrant
*                Available via: CddDma_Lld.h
*
* @param[in] Channel: DMA channel number.
* @return uint32 Remaining trigger count of the DMA channel.
*/
uint32 CddDma_Lld_GetRemainingTriggerCount(uint8 Channel);

#ifndef CPU_YTM32B1HA0
/**
 * @brief         Copies the Channel transfer configuration to the software CTS structure for scatter-gather DMA operations.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma_Lld.h
 *
 * @param[in] TransferConfig: Pointer to the Channel transfer configuration structure.
 * @param[in,out] Scts: Pointer to the software CTS structure to be populated.
 * @return void
*/
void CddDma_Lld_PushConfigToScts(const CddDma_TransferConfigType *TransferConfig, CddDma_SoftwareCtsType *Scts);
#endif

/**
 * @brief         Registers the IRQ callback function and the parameter for a specific channel.
 *                The callback function is called when the channel transfer completes.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma_Lld.h
 *
 * @param[in] Channel: DMA Channel number.
 * @param[in] Callback: The pointer to the callback function.
 * @param[in] Parameter: The value to the callback function's parameter.
 * @return void
*/
void CddDma_Lld_InstallCallback(uint8 Channel, CddDma_CallbackType Callback, uint32 Parameter);

/**
 * @brief         Registers the Error IRQ callback function and the parameter for DMA Channel.
 *                The callback function is called when the Channel error event occurs.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma_Lld.h
 *
 * @param[in] Channel: DMA Channel number.
 * @param[in] Callback: The pointer to the callback function.
 * @param[in] Parameter: The value to the callback function's parameter.
 * @return void
*/
void CddDma_Lld_InstallErrorCallback(uint8 Channel, CddDma_CallbackType Callback, uint32 Parameter);

/**
 * @brief         Retrieves comprehensive DMA channel status information including channel state, active status, completion status, and error flags.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma_Lld.h
 *
 * @param[in] Channel: Selection value of the Logic Channel.
 * @param[out] ChannelStatus: Pointer to the DMA Channel status structure to be populated with current channel information.
 * @return void
*/
void CddDma_Lld_GetChannelStatus(uint8 Channel, CddDma_ChannelStatusReturnType *ChannelStatus);

/**
 * @brief         Clears the DMA Channel's Done status flag to reset the completion state.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma_Lld.h
 *
 * @param[in] Channel: DMA Channel number.
 * @return void
*/
void CddDma_Lld_ClearChannelDoneStatus(uint8 Channel);

/**
 * @brief         Error Interrupt Service Handler that processes DMA error interrupts for all channels within a DMA instance,
 *                automatically disabling problematic channels and invoking registered error callbacks.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Interrupt Handler)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.h
 *
 * @param[in] Instance: DMA instance ID.
 * @return void
*/
void CddDma_Lld_Error_IrqHandler(uint8 Instance);

/**
 * @brief         DMA Interrupt Service Handler that processes channel completion interrupts and invokes registered callbacks for
 *                successful transfer completion.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Interrupt Handler)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.h
 *
 * @param[in] Channel: DMA Channel number.
 * @return void
*/
void CddDma_Lld_IrqHandler(uint8 Channel);

#ifdef __cplusplus
}
#endif

#endif /* End of file CddDma_Lld.h */

