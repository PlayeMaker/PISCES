/*
* @file    CddDma_Types.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : CddDma_Types
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_RELEASE_4_4_REV_0000
*   SW Version           : V0.9.1
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef CDDDMA_TYPES_H
#define CDDDMA_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "CddDma_Cfg.h"
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define CDDDMA_TYPES_VENDOR_ID                         (180)
#define CDDDMA_TYPES_AR_RELEASE_MAJOR_VERSION          (4)
#define CDDDMA_TYPES_AR_RELEASE_MINOR_VERSION          (4)
#define CDDDMA_TYPES_AR_RELEASE_REVISION_VERSION       (0)
#define CDDDMA_TYPES_SW_MAJOR_VERSION                  (0)
#define CDDDMA_TYPES_SW_MINOR_VERSION                  (9)
#define CDDDMA_TYPES_SW_PATCH_VERSION                  (1)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Std_Types.h file are of the same Autosar version */
#if ((CDDDMA_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (CDDDMA_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) || \
     (CDDDMA_TYPES_AR_RELEASE_REVISION_VERSION != STD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CddDma_Types.h and Std_Types.h are different"
#endif

/* Check if source file and DMA configuration header file are of the same vendor */
#if (CDDDMA_TYPES_VENDOR_ID != CDDDMA_VENDOR_ID_CFG)
#error "CddDma_Types.h and CddDma_Cfg.h have different vendor ids"
#endif
/* Check if source file and DMA configuration header file are of the same Autosar version */
#if ((CDDDMA_TYPES_AR_RELEASE_MAJOR_VERSION != CDDDMA_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (CDDDMA_TYPES_AR_RELEASE_MINOR_VERSION != CDDDMA_AR_RELEASE_MINOR_VERSION_CFG) || \
     (CDDDMA_TYPES_AR_RELEASE_REVISION_VERSION != CDDDMA_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of CddDma_Types.h and CddDma_Cfg.h are different"
#endif
/* Check if source file and DMA configuration header file are of the same software version */
#if ((CDDDMA_TYPES_SW_MAJOR_VERSION != CDDDMA_SW_MAJOR_VERSION_CFG) || \
     (CDDDMA_TYPES_SW_MINOR_VERSION != CDDDMA_SW_MINOR_VERSION_CFG) || \
     (CDDDMA_TYPES_SW_PATCH_VERSION != CDDDMA_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of CddDma_Types.h and CddDma_Cfg.h are different"
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
/**
 * @brief          Enumeration representing the state of a DMA channel in the CddDma module.
 */
typedef enum
{
    DMA_CHN_UNINIT = 0U,          /** @brief DMA channel is not initialized. */
    DMA_CHN_NORMAL = 1U,          /** @brief DMA channel normal state. */
    DMA_CHN_ERROR  = 2U,          /** @brief At least one error occurred in the DMA channel. */
} CddDma_ChannelStateType;

/**
 * @brief          Enumeration representing the initialization state of the DMA module.
 */
typedef enum
{
    DMA_STATE_UNINIT = 0U,        /** @brief The DMA is not initialized. */
    DMA_STATE_INIT   = 1U,        /** @brief The DMA is initialized. */
} CddDma_StateType;

/**
 * @brief          Enumeration for DMA transfer sizes, specifying the number of bytes transferred in each DMA operation.
 */
typedef enum
{
    DMA_TRANSFER_SIZE_1_BYTE  = 0x0U,        /** @brief DMA transfer 1 byte */
    DMA_TRANSFER_SIZE_2_BYTE  = 0x1U,        /** @brief DMA transfer 2 bytes */
    DMA_TRANSFER_SIZE_4_BYTE  = 0x2U,        /** @brief DMA transfer 4 bytes */
    DMA_TRANSFER_SIZE_16_BYTE = 0x4U,        /** @brief DMA transfer 16 bytes */
    DMA_TRANSFER_SIZE_32_BYTE = 0x5U,        /** @brief DMA transfer 32 bytes */
} CddDma_TransferSizeType;

/**
 * @brief          Enumeration for DMA bandwidth control, specifying the number of wait cycles the DMA engine inserts between
 *                 each read/write operation to balance bus loading.
 */
typedef enum
{
    DMA_ENGINE_STALL_0_CYCLES = 0U,        /** @brief DMA transfer data continuous (no wait cycles between R/W operations). */
    DMA_ENGINE_STALL_4_CYCLES = 2U,        /** @brief DMA engine waits 4 cycles after each read/write operation. */
    DMA_ENGINE_STALL_8_CYCLES = 3U,        /** @brief DMA engine waits 8 cycles after each read/write operation. */
} CddDma_EngineStallType;

/**
 * @brief          Enumeration for DMA transfer addressing mode. Specifies the modulo value for source/destination address adjustment after
 *                 each DMA transfer size is completed.
 * @note           If modulo is enabled, the address shall be aligned to the modulo size.
 */
typedef enum
{
    DMA_MODULO_OFF   = 0U,          /** @brief No modulo adjustment; address increments normally. */
    DMA_MODULO_2B    = 1U,          /** @brief Modulo 2 bytes. */
    DMA_MODULO_4B    = 2U,          /** @brief Modulo 4 bytes. */
    DMA_MODULO_8B    = 3U,          /** @brief Modulo 8 bytes. */
    DMA_MODULO_16B   = 4U,          /** @brief Modulo 16 bytes. */
    DMA_MODULO_32B   = 5U,          /** @brief Modulo 32 bytes. */
    DMA_MODULO_64B   = 6U,          /** @brief Modulo 64 bytes. */
    DMA_MODULO_128B  = 7U,          /** @brief Modulo 128 bytes. */
    DMA_MODULO_256B  = 8U,          /** @brief Modulo 256 bytes. */
    DMA_MODULO_512B  = 9U,          /** @brief Modulo 512 bytes. */
    DMA_MODULO_1KB   = 10U,         /** @brief Modulo 1 KB. */
    DMA_MODULO_2KB   = 11U,         /** @brief Modulo 2 KB. */
    DMA_MODULO_4KB   = 12U,         /** @brief Modulo 4 KB. */
    DMA_MODULO_8KB   = 13U,         /** @brief Modulo 8 KB. */
    DMA_MODULO_16KB  = 14U,         /** @brief Modulo 16 KB. */
    DMA_MODULO_32KB  = 15U,         /** @brief Modulo 32 KB. */
    DMA_MODULO_64KB  = 16U,         /** @brief Modulo 64 KB. */
    DMA_MODULO_128KB = 17U,         /** @brief Modulo 128 KB. */
    DMA_MODULO_256KB = 18U,         /** @brief Modulo 256 KB. */
    DMA_MODULO_512KB = 19U,         /** @brief Modulo 512 KB. */
    DMA_MODULO_1MB   = 20U,         /** @brief Modulo 1 MB. */
    DMA_MODULO_2MB   = 21U,         /** @brief Modulo 2 MB. */
    DMA_MODULO_4MB   = 22U,         /** @brief Modulo 4 MB. */
    DMA_MODULO_8MB   = 23U,         /** @brief Modulo 8 MB. */
    DMA_MODULO_16MB  = 24U,         /** @brief Modulo 16 MB. */
    DMA_MODULO_32MB  = 25U,         /** @brief Modulo 32 MB. */
    DMA_MODULO_64MB  = 26U,         /** @brief Modulo 64 MB. */
    DMA_MODULO_128MB = 27U,         /** @brief Modulo 128 MB. */
    DMA_MODULO_256MB = 28U,         /** @brief Modulo 256 MB. */
    DMA_MODULO_512MB = 29U,         /** @brief Modulo 512 MB. */
    DMA_MODULO_1GB   = 30U,         /** @brief Modulo 1 GB. */
    DMA_MODULO_2GB   = 31U,         /** @brief Modulo 2 GB. */
} CddDma_ModuloType;

/*==================================================================================================
                                                TYPEDEF AND STRUCTURES
==================================================================================================*/
/**
 * @brief          Type definition for DMA channel number in the CddDma module.
 */
typedef uint8 CddDma_ChannelType;

/**
 * @brief          Type definition for the count of DMA channels for initialization.
 */
typedef uint8 CddDma_ChannelCountType;

/**
 * @brief          Definition for the DMA channel callback function. This type represents a pointer to a function that
 *                 takes a uint32 parameter and returns void.
 */
typedef void (*CddDma_CallbackType)(uint32 Parameter);

/**
 * @brief          Type definition for halting the DMA operation upon encountering an error.
 */
typedef boolean CddDma_HaltOnErrorType;

/**
 * @brief          Type definition for the debug mode of the DMA module.
 */
typedef boolean CddDma_DebugType;

/**
 * @brief          Indicates whether the DMA hardware request should be disabled automatically when trigger loop completed.
 */
typedef boolean CddDma_DisReqOnCompletionType;

/**
 * @brief          Type definition for the address for transfer.
 */
typedef uint32 CddDma_TransferAddressType;

/**
 * @brief          Structure for configuring DMA channel linking during transfer operations.
 *                 Defines attributes for channel-to-channel linking, including trigger loop iteration count,
 *                 offset application to source/destination addresses, and channel link enable/number settings.
 *                 Used to control advanced DMA transfer behaviors such as automatic channel chaining and address adjustment
 *                 after transfer or trigger loop completion.
 */
typedef struct
{
    uint32 TriggerLoopIterationCount;   /**< Number of trigger loop iterations */
    boolean SrcOffsetEnable;            /**< Selects whether the transfer loop offset is applied to the
                                             source address upon transfer loop completion */
    boolean DestOffsetEnable;           /**< Selects whether the transfer loop offset is applied to the
                                             destination address upon transfer loop completion */
    sint32 TriggerLoopOffset;           /**< Sign-extended offset applied to the source or destination address
                                             to form the next-state value after the transfer loop completes */
    boolean TransferLoopChnLinkEnable;  /**< Enables channel-to-channel linking on transfer loop complete */
    uint8 TransferLoopChnLinkNumber;    /**< The number of the next channel to be started by DMA
                                             engine when transfer loop completes */
    boolean TriggerLoopChnLinkEnable;   /**< Enables channel-to-channel linking on trigger loop complete */
    uint8 TriggerLoopChnLinkNumber;     /**< The number of the next channel to be started by DMA
                                             engine when trigger loop completes */
} CddDma_LoopTransferConfigType;

/**
 * @brief          DMA transfer configuration structure. Configures the basic source/destination transfer attributes for a DMA channel.
 */
typedef struct
{
    CddDma_TransferAddressType SrcAddr;                        /**< Memory address pointing to the source data. */
    CddDma_TransferAddressType DestAddr;                       /**< Memory address pointing to the destination data. */
    CddDma_TransferSizeType SrcTransferSize;                   /**< Source data transfer size. */
    CddDma_TransferSizeType DestTransferSize;                  /**< Destination data transfer size. */
    sint16 SrcOffset;                                          /**< Sign-extended offset Bytes applied to the current source address
                                                                    to form the next-state value as each source read/write is completed. */
    sint16 DestOffset;                                         /**< Sign-extended offset Bytes applied to the current destination
                                                                    address to form the next-state value as each source
                                                                    read/write is completed. */
    sint32 SrcLastAddrAdjust;                                  /**< Last source address adjustment. */
    sint32 DestLastAddrAdjust;                                 /**< Last destination address adjustment. Note here it is only
                                                                    valid when ram reload feature is not enabled. */
    CddDma_ModuloType SrcModulo;                               /**< Source address modulo. */
    CddDma_ModuloType DestModulo;                              /**< Destination address modulo. */
    uint32 TransferLoopByteCount;                              /**< Number of bytes to be transferred in each service request of the channel.
                                                                    If minor loop offset is enabled, this value must less than or equal to 0x3FF,
                                                                    Otherwise it must less than or equal to 0x7FFFFFFF */
    uint32 TriggerCount;                                       /**< Number of major interation count.
                                                                    If channel link is not enabled, this value must less than or equal to 0x7FFF,
                                                                    Otherwise it must less than or equal to 0x1FF */
    CddDma_DisReqOnCompletionType DisableReqOnCompletion;      /**< Disables the DMA request after the trigger loop completes for the CTS*/
    boolean ChannelPollingMode;                                /**< If TRUE will disable the interrupt of Error and trigger loop done or half done*/
    boolean RamReloadEnable;                                   /**< Enable ram reload feature */
    uint32 RamReloadNextDescAddr;                              /**< The address of the next descriptor to be used, when ram reload feature is enabled.
                                                                    Note: this value is not used when ram reload feature is disabled. */
    boolean RamReloadIntEnable;                                /**< Enable/disable the interrupt request for RamReload configuration*/
    const CddDma_LoopTransferConfigType *LoopTransferConfig;   /**< Pointer to loop transfer configuration structure
                                                                    (defines transfer/trigger loop attributes)
                                                                    Note: this field is only used when transfer loop mapping is
                                                                    enabled from DMA configuration. */
    CddDma_EngineStallType EngineStall;                        /**< DMA channel bandwidth control. */
} CddDma_TransferConfigType;

/**
 * @brief          Structure representing the status information of a DMA channel, including state, error count, and activity flags.
 */
typedef struct
{
    CddDma_ChannelStateType ChannelStateValue;   /**< The channel state value read from the internal DMA Driver Channel State Machine. */
    uint32  Errors;                              /**< The error data read from the DMA Channel Error Register (CHx_ERS). */
    boolean Active;                              /**< Indicates if the channel is active, read from the DMA Channel
                                                      Control and Status Register (CHx_CSR) field ACTIVE. */
    boolean Done;                                /**< Indicates if the channel transfer is done, read from the DMA Channel
                                                      Control and Status Register (CHx_CSR) field DONE. */
} CddDma_ChannelStatusReturnType;

#ifndef CPU_YTM32B1HA0
/**
 * @brief          Structure for DMA RAM reload list configuration. Contains source and destination memory addresses for DMA transfer operations
 *                 when RAM reload feature is enabled.
 */
typedef struct
{
    CddDma_TransferAddressType SrcAddr;    /** @brief Memory address pointing to the source data. */
    CddDma_TransferAddressType DestAddr;   /** @brief Memory address pointing to the destination data. */
} CddDma_RamReloadListType;

/**
 * @brief          DMA Channel Transfer Service (CTS) structure, representing the configuration registers for a DMA channel transfer.
 *                 This structure is used to configure and reflect the hardware settings for source/destination addresses, offsets,
 *                 transfer attributes, loop counts, RAM reload, and control/status information.
 */
typedef struct
{
    uint32 SADDR;        /** @brief Source address for the DMA transfer. */
    sint16 SOFF;         /** @brief Offset applied to the source address after each transfer. */
    uint16 ATTR;         /** @brief Transfer attributes, such as data width and modulo settings. */
    uint32 BCNT;         /** @brief Byte count for each service request of the channel. */
    sint32 STO;          /** @brief Source trigger loop offset, applied after each trigger loop completes. */
    uint32 DADDR;        /** @brief Destination address for the DMA transfer. */
    sint16 DOFF;         /** @brief Offset applied to the destination address after each transfer. */
    uint16 TCNT;         /** @brief Trigger loop transfer count (number of minor loop iterations per major loop). */
    sint32 RamLoadAddr;  /** @brief RAM load address for descriptor reload operations. */
    uint16 CSR;          /** @brief Control/status register for the DMA channel. */
    uint16 TCNTRV;       /** @brief Trigger loop counter value. */
} CddDma_SoftwareCtsType;
#endif

/**
 * @brief          Structure representing the interrupt configuration for a DMA channel. Allows enabling error, major loop complete,
 *                 and half major loop complete interrupts for the channel.
 */
typedef struct
{
    boolean EnErrInt;              /**< Enables the error interrupt for the specified channel */
    boolean EnMajorInt;            /**< Enables interrupt after the trigger loop completes for the CTS */
    boolean EnHalfMajorInt;        /**< Enables the half complete interrupt for the CTS */
} CddDma_ChanInterruptType;

/**
 * @brief          Description: DMA channel configuration structure. Defines the virtual channel number, request source, interrupt configuration,
 *                 and callback functions for normal and error events.
 */
typedef struct
{
    CddDma_ChannelType VirtualChannel;              /**< DMA virtual channel number */
    CddDma_RequestSourceType RequestSource;         /**< Selects the source of the DMA request for this channel */
    CddDma_ChanInterruptType ChanIntRequest;        /**< Channel interrupt configuration */
    CddDma_CallbackType Callback;                   /**< Callback that will be registered for this channel */
    uint32 CallbackParam;                           /**< Parameter passed to the channel callback */
    CddDma_CallbackType ErrorCallback;              /**< Error Callback that will be registered for this channel */
    uint32 ErrorCallbackParam;                      /**< Parameter passed to the channel callback */
} CddDma_ChannelConfigType;

/** @brief The user state structure for the DMA channel state */
typedef struct
{
    CddDma_CallbackType Callback;                   /**< Callback that will be registered for this channel */
    uint32 CallbackParam;                           /**< Parameter passed to the channel callback */
    CddDma_CallbackType ErrorCallback;              /**< Error Callback that will be registered for this channel */
    uint32 ErrorCallbackParam;                      /**< Parameter passed to the channel callback */
    CddDma_ChannelStateType Status;                 /**< DMA channel status */
} CddDma_ChannelStatusType;

/**
 * @brief          The user configuration structure for the DMA config. Contains DMA channel configuration, error handling, and debug settings.
 */
typedef struct
{
    CddDma_ChannelCountType ChannelCount;                /**< DMA channel count to be configured */
    const CddDma_ChannelConfigType *ChannelConfigPtr;    /**< Pointer to DMA channel configuration */
    CddDma_HaltOnErrorType HaltOnError;                  /**< If DMA halting when error occurs */
    CddDma_DebugType EnDebug;                            /**< When in debug mode, DMA stalls the start of a new channel. Executing channels are
                                                              allowed to complete.*/
} CddDma_ConfigType;

#ifdef __cplusplus
}
#endif

#endif /* End of file CddDma_Types.h */
