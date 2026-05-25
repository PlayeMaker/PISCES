/**
* @file    CddDma.c
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

#include "Compiler.h"
#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @page misra_violations MISRA-C:2012 violations List
 * PRQA S 0306 Rule-11.4: A conversion should not be performed between a pointer to object and an integer type.
 * PRQA S 3408 Rule-8.4: A compatible declaration shall be visible when an object or function with external linkage is defined.
 */
/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "CddDma.h"
#include "CddDma_Lld.h"
#include "SchM_CddDma.h"
#include "OsIf.h"

#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* CDDDMA_DEV_ERROR_DETECT == STD_ON */
/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDDDMA_VENDOR_ID_C                      (180)
#define CDDDMA_AR_RELEASE_MAJOR_VERSION_C       (4)
#define CDDDMA_AR_RELEASE_MINOR_VERSION_C       (4)
#define CDDDMA_AR_RELEASE_REVISION_VERSION_C    (0)
#define CDDDMA_SW_MAJOR_VERSION_C               (0)
#define CDDDMA_SW_MINOR_VERSION_C               (9)
#define CDDDMA_SW_PATCH_VERSION_C               (1)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CddDma.h file are of the same vendor */
#if (CDDDMA_VENDOR_ID_C != CDDDMA_VENDOR_ID)
#error "CddDma.c and CddDma.h have different vendor ids"
#endif
/* Check if source file and CddDma.h file are of the same Autosar version */
#if (( CDDDMA_AR_RELEASE_MAJOR_VERSION_C != CDDDMA_AR_RELEASE_MAJOR_VERSION) || \
      ( CDDDMA_AR_RELEASE_MINOR_VERSION_C != CDDDMA_AR_RELEASE_MINOR_VERSION) || \
      ( CDDDMA_AR_RELEASE_REVISION_VERSION_C != CDDDMA_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CddDma.c and CddDma.h are different"
#endif
/* Check if source file and CddDma.h file are of the same Software version */
#if (( CDDDMA_SW_MAJOR_VERSION_C != CDDDMA_SW_MAJOR_VERSION) || \
      ( CDDDMA_SW_MINOR_VERSION_C != CDDDMA_SW_MINOR_VERSION) || \
      ( CDDDMA_SW_PATCH_VERSION_C != CDDDMA_SW_PATCH_VERSION))
#error "Software Version Numbers of CddDma.c and CddDma.h are different"
#endif

/* Check if source file and CddDma_Lld.h file are of the same vendor */
#if (CDDDMA_VENDOR_ID_C != CDDDMA_LLD_VENDOR_ID)
#error "CddDma.c and CddDma_Lld.h have different vendor ids"
#endif
/* Check if source file and CddDma_Lld.h file are of the same Autosar version */
#if ((CDDDMA_AR_RELEASE_MAJOR_VERSION_C != CDDDMA_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (CDDDMA_AR_RELEASE_MINOR_VERSION_C != CDDDMA_LLD_AR_RELEASE_MINOR_VERSION) || \
     (CDDDMA_AR_RELEASE_REVISION_VERSION_C != CDDDMA_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CddDma.c and CddDma_Lld.h are different"
#endif
/* Check if source file and CddDma_Lld.h file are of the same Software version */
#if ((CDDDMA_SW_MAJOR_VERSION_C != CDDDMA_LLD_SW_MAJOR_VERSION) || \
     (CDDDMA_SW_MINOR_VERSION_C != CDDDMA_LLD_SW_MINOR_VERSION) || \
     (CDDDMA_SW_PATCH_VERSION_C != CDDDMA_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of CddDma.c and CddDma_Lld.h are different"
#endif

/*==================================================================================================
                                                EXTERNAL VARIABLES
==================================================================================================*/
#if (CDDDMA_PRECOMPILE_SUPPORT == STD_ON)
extern const CddDma_ConfigType CddDma_PreCompileConfig;
#endif
/*==================================================================================================
                                                LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
                                                LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL MACROS
==================================================================================================*/
#define ALIGNED_32B_MASK                       (0x1FU)  /**@brief MASK for 32Bytes aligned*/
/*==================================================================================================
 *                                          VARIATES
==================================================================================================*/

#define CDDDMA_START_SEC_VAR_INIT_UNSPECIFIED
#include "CddDma_MemMap.h"

CDDDMA_VAR static const CddDma_ConfigType *CddDmaConfigPtr = NULL_PTR;
CDDDMA_VAR static CddDma_StateType CddDmaState = DMA_STATE_UNINIT;

#define CDDDMA_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CddDma_MemMap.h"

#define CDDDMA_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CddDma_MemMap.h"

/** @brief Global state to save information */
/* MR12 RULE 8.4 VIOLATION: A compatible declaration shall be visible when an object or function with external linkage is defined.
 * The variable will used in low level of the CddDma module only, therefore, couldn't be followed in this specific case
 */
CDDDMA_VAR CddDma_ChannelStatusType CddDmaChStatus[CDDDMA_CHANNEL_CONFIG_COUNT]; /*PRQA S 3408*/

#define CDDDMA_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CddDma_MemMap.h"


/*==================================================================================================
 *                                   LOCAL FUNCTION DECLARATION
==================================================================================================*/

/*==================================================================================================
                                                LOCAL FUNCTIONS
==================================================================================================*/
#define CDDDMA_START_SEC_CODE
#include "CddDma_MemMap.h"

#ifndef CPU_YTM32B1HA0
/**
 * @brief         Configures the software CTS (Channel Transfer Service) descriptor for single count mode, setting up RAM reload parameters based on
 *                loop mode configuration.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma.c
 *
 * @param[in] Scts: Pointer to the software CTS descriptor array.
 * @param[in] LoopMode: Flag indicating whether loop mode is enabled (TRUE) or disabled (FALSE).
 * @param[in,out] SctsConfigPtr: Pointer to the transfer configuration structure to be modified with RAM reload settings.
 * @return void
*/
CDDDMA_FUNC static inline void CddDma_ConfigCtsSignalCount(CddDma_TransferConfigType *SctsConfigPtr,
        const CddDma_SoftwareCtsType *Scts,
        const boolean LoopMode)
{
    if (TRUE == LoopMode)
    {
        /* Link the software struct of CTS to itself */
        SctsConfigPtr->RamReloadEnable = TRUE;
        /* MR12 RULE 11.4 VIOLATION: Here a cast is made between an object pointer and an integer type. In this specific case,
         * needs to obtain the integer value of the stcs address, thus, couldn't adhere to M3CM Rule-11.4
         */
        SctsConfigPtr->RamReloadNextDescAddr = (uint32)&Scts[0]; /* PRQA S 0306 */
    }
    else
    {
        SctsConfigPtr->RamReloadEnable = FALSE;
        SctsConfigPtr->RamReloadNextDescAddr = 0;
    }
    SctsConfigPtr->RamReloadIntEnable = TRUE;
}

/**
 * @brief         Configures software CTS (Channel Transfer Service) descriptors for multi-count mode, creating a linked list of transfer descriptors
 *                with proper RAM reload chaining based on the current descriptor position and loop mode setting.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma.c
 *
 * @param[in] ReloadCount: Current descriptor index being configured (0-based).
 * @param[in] Scts: Pointer to the software CTS descriptor array.
 * @param[in] CtsCount: Total number of CTS descriptors in the array.
 * @param[in] LoopMode: Flag indicating whether loop mode is enabled (TRUE) or disabled (FALSE).
 * @param[in,out] SctsConfigPtr: Pointer to the transfer configuration structure to be modified with RAM reload linking settings.
 * @return void
*/
CDDDMA_FUNC static inline void CddDma_ConfigCtsMultiCount(uint8 ReloadCount,
        CddDma_TransferConfigType *SctsConfigPtr,
        const CddDma_SoftwareCtsType *Scts,
        const uint8 CtsCount,
        const boolean LoopMode)
{
    if (ReloadCount < (CtsCount - 1U))
    {
        /* Link the software struct of CTS to next one */
        SctsConfigPtr->RamReloadIntEnable = FALSE;
        SctsConfigPtr->RamReloadEnable = TRUE;
        /* MR12 RULE 11.4 VIOLATION: Here a cast is made between an object pointer and an integer type. In this specific case,
         * needs to obtain the integer value of the stcs address, thus, couldn't adhere to M3CM Rule-11.4
         */
        SctsConfigPtr->RamReloadNextDescAddr = (uint32) &Scts[ReloadCount + 1U]; /* PRQA S 0306 */
    }
    else
    {
        if (TRUE == LoopMode)
        {
            /* Link the last CTS's RamReloadNextDescAddr to the first one */
            SctsConfigPtr->RamReloadEnable = TRUE;
            /* MR12 RULE 11.4 VIOLATION: Here a cast is made between an object pointer and an integer type. In this specific case,
             * needs to obtain the integer value of the stcs address, thus, couldn't adhere to M3CM Rule-11.4.
             */
            SctsConfigPtr->RamReloadNextDescAddr = (uint32) &Scts[0]; /* PRQA S 0306 */
        }
        else
        {
            SctsConfigPtr->RamReloadEnable = FALSE;
            SctsConfigPtr->RamReloadNextDescAddr = 0;
        }
        SctsConfigPtr->RamReloadIntEnable = TRUE;
    }
}
/**
 * @brief         Configures RAM reload functionality for DMA transfers by setting up software CTS descriptors with source/destination addresses
 *                from the reload list and establishing proper descriptor chaining based on count and loop mode.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma.c
 *
 * @param[in] List: Pointer to array of source/destination address pairs for each CTS descriptor.
 * @param[in] Scts: Pointer to software CTS descriptor array to be configured.
 * @param[in] CtsCount: Total number of CTS descriptors to configure (array size).
 * @param[in] LoopMode: Flag indicating whether loop mode is enabled (TRUE) for continuous operation or disabled (FALSE) for single-pass.
 * @param[in,out] TransferConfig: Base transfer configuration template that gets modified and applied to each CTS descriptor.
 * @return void
*/
CDDDMA_FUNC static inline void CddDma_ConfigRamReload(const CddDma_RamReloadListType *List,
        CddDma_TransferConfigType *TransferConfig,
        CddDma_SoftwareCtsType *Scts,
        uint8 CtsCount,
        boolean LoopMode)
{
    CddDma_TransferConfigType SctsConfig = *TransferConfig;
    CddDma_TransferConfigType *SctsConfigPtr = TransferConfig;
    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_11();
    for (uint8 ReloadCount = 0; ReloadCount < CtsCount; ++ReloadCount)
    {
        SctsConfig.SrcAddr = List[ReloadCount].SrcAddr;
        SctsConfig.DestAddr = List[ReloadCount].DestAddr;
        if (1U == CtsCount)
        {
            CddDma_ConfigCtsSignalCount(&SctsConfig, Scts, LoopMode);
        }
        else
        {
            CddDma_ConfigCtsMultiCount(ReloadCount, &SctsConfig, Scts, CtsCount, LoopMode);
        }
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call2params(CddDma_Lld_PushConfigToScts, &SctsConfig, &Scts[ReloadCount]);
#else
        CddDma_Lld_PushConfigToScts(&SctsConfig, &Scts[ReloadCount]);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
    }
    /* Disable the interrupt and set the next ram reload addr to the original CTS*/
    SctsConfigPtr->RamReloadIntEnable = FALSE;
    SctsConfigPtr->RamReloadEnable = TRUE;
    /* MR12 RULE 11.4 VIOLATION: Here a cast is made between an object pointer and an integer type. In this specific case,
     * needs to obtain the integer value of the stcs address, thus, couldn't adhere to M3CM Rule-11.4
     */
    SctsConfigPtr->RamReloadNextDescAddr = (uint32) &Scts[0];  /* PRQA S 0306 */
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_11();
}
#endif

/*==================================================================================================
 *                                   GLOBAL FUNCTIONS
==================================================================================================*/

CDDDMA_FUNC void CddDma_Init(const CddDma_ConfigType *ConfigPtr)
{
#if (CDDDMA_PRECOMPILE_SUPPORT == STD_ON)
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != ConfigPtr)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_INIT, CDDDMA_E_PARAM_POINTER);
    }
    else if (DMA_STATE_INIT == CddDmaState)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_INIT, CDDDMA_E_ALREADY_INITIALIZED);
    }
    else
    {
#endif /* #if (CDDDMA_DEV_ERROR_DETECT == STD_ON) */
        CddDmaConfigPtr = &CddDma_PreCompileConfig;
        (void)ConfigPtr;
#else
    CddDmaConfigPtr = ConfigPtr;
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == CddDmaConfigPtr)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_INIT, CDDDMA_E_PARAM_POINTER);
    }
    else if (DMA_STATE_INIT == CddDmaState)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_INIT, CDDDMA_E_ALREADY_INITIALIZED);
    }
    else
    {
#endif /* #if (CDDDMA_DEV_ERROR_DETECT == STD_ON) */
#endif
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(CddDma_Lld_Init, CddDmaConfigPtr);
#else
        CddDma_Lld_Init(CddDmaConfigPtr);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */

        CddDmaState = DMA_STATE_INIT;
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    }
#endif  /* #if (CDDDMA_DEV_ERROR_DETECT == STD_ON) */
}

CDDDMA_FUNC void CddDma_DeInit(void)
{
    if (DMA_STATE_INIT == CddDmaState)
    {
        /* Deinitialize the DMA controller and release all DMA channels*/
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call(CddDma_Lld_Deinit);
#else
        CddDma_Lld_Deinit();
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
        SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_00();
        CddDmaConfigPtr = NULL_PTR;
        CddDmaState = DMA_STATE_UNINIT;
        SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_00();
    }
    else
    {
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_DEINIT, CDDDMA_E_UNINIT);
#endif /* #if (CDDDMA_DEV_ERROR_DETECT == STD_ON)*/
    }
}

CDDDMA_FUNC StatusType CddDma_SetLogicChannelTransfer(CddDma_ChannelType Channel,
        uint32 SrcAddr,
        uint32 DestAddr,
        const CddDma_TransferConfigType *TransferConfig)
{
    StatusType ReStatus = E_NOT_OK;
    CddDma_TransferConfigType ChannelTransferConfig;
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= Channel)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_SET_LOGIC_CHANNEL_TRANSFER, CDDDMA_E_OUT_OF_RANGE);
    }
    else if (DMA_CHN_UNINIT == CddDmaChStatus[Channel].Status)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_SET_LOGIC_CHANNEL_TRANSFER, CDDDMA_E_UNINIT);
    }
    else if (NULL_PTR == TransferConfig)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_SET_LOGIC_CHANNEL_TRANSFER, CDDDMA_E_PARAM_POINTER);
    }
    else
    {
        if ((0U == SrcAddr) || (0U == DestAddr))
        {
            (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_SET_LOGIC_CHANNEL_TRANSFER, CDDDMA_E_ADDR_INVALID);
        }
        else if ((TRUE == TransferConfig->RamReloadEnable) && ((TransferConfig->RamReloadNextDescAddr & ALIGNED_32B_MASK) != 0U))
        {
            (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_SET_LOGIC_CHANNEL_TRANSFER, CDDDMA_E_RAMRELOAD_ADDR_UNALIGNED);
        }
        /* Check that the address are aligned*/
        else if (((SrcAddr % ((uint32)1U << (uint32)TransferConfig->SrcTransferSize)) != 0U) ||
                 ((DestAddr % ((uint32)1U << (uint32)TransferConfig->DestTransferSize)) != 0U))
        {
            (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_SET_LOGIC_CHANNEL_TRANSFER, CDDDMA_E_ADDR_UNALIGNED);
        }
        else if (((TransferConfig->TransferLoopByteCount % ((uint32)1U << (uint32)TransferConfig->SrcTransferSize)) != 0U) ||
                 ((TransferConfig->TransferLoopByteCount % ((uint32)1U << (uint32)TransferConfig->DestTransferSize)) != 0U))
        {
            (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_SET_LOGIC_CHANNEL_TRANSFER, CDDDMA_E_LOOPCOUNT_INVALID);
        }
        else
#endif /* #if (CDDDMA_DEV_ERROR_DETECT == STD_ON)*/
        {
            ChannelTransferConfig = *TransferConfig;
            ChannelTransferConfig.SrcAddr = SrcAddr;
            ChannelTransferConfig.DestAddr = DestAddr;
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
            OsIf_Trusted_Call2params(CddDma_Lld_SetChannelTransfer, Channel, &ChannelTransferConfig);
#else
            CddDma_Lld_SetChannelTransfer(Channel, &ChannelTransferConfig);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
            ReStatus = E_OK;
        }
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* #if (CDDDMA_DEV_ERROR_DETECT == STD_ON)*/
    return ReStatus;
}

CDDDMA_FUNC void CddDma_StartChannel(CddDma_ChannelType Channel)
{
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= Channel)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_START_CHANNEL, CDDDMA_E_OUT_OF_RANGE);
    }
    /* Check current channel of DMA must be initialed */
    else if (DMA_CHN_UNINIT == CddDmaChStatus[Channel].Status)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_START_CHANNEL, CDDDMA_E_UNINIT);
    }
    else
#endif
    {
        /* Enable requests for current channel */
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call2params(CddDma_Lld_SetDmaRequestCmd, Channel, TRUE);
#else
        CddDma_Lld_SetDmaRequestCmd(Channel, TRUE);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
    }
}

CDDDMA_FUNC void CddDma_StopChannel(CddDma_ChannelType Channel)
{
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= Channel)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_STOP_CHANNEL, CDDDMA_E_OUT_OF_RANGE);
    }
    /* Check current channel of DMA must be initialed */
    else if (DMA_CHN_UNINIT == CddDmaChStatus[Channel].Status)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_STOP_CHANNEL, CDDDMA_E_UNINIT);
    }
    else
#endif
    {
        /* Disable requests for current channel */
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call2params(CddDma_Lld_SetDmaRequestCmd, Channel, FALSE);
#else
        CddDma_Lld_SetDmaRequestCmd(Channel, FALSE);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
    }
}

CDDDMA_FUNC void CddDma_SoftTrigger(CddDma_ChannelType Channel)
{
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= Channel)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_SOFT_TRIGGER, CDDDMA_E_OUT_OF_RANGE);
    }
    /* Check current channel of DMA must be initialed */
    else if (DMA_CHN_UNINIT == CddDmaChStatus[Channel].Status)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_SOFT_TRIGGER, CDDDMA_E_UNINIT);
    }
    else
#endif
    {
        /* Triggers a sw request for the current channel. */
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(CddDma_Lld_TriggerChannelStart, Channel);
#else
        CddDma_Lld_TriggerChannelStart(Channel);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
    }
}

#ifndef CPU_YTM32B1HA0
CDDDMA_FUNC void CddDma_ChannelRamReloadConfig(CddDma_ChannelType Channel,
        const CddDma_RamReloadListType *List,
        CddDma_TransferConfigType *TransferConfig,
        CddDma_SoftwareCtsType *Scts,
        uint8 CtsCount,
        boolean LoopMode)
{
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= Channel)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_CONFIG_RAM_RELOAD, CDDDMA_E_OUT_OF_RANGE);
    }
    else if (DMA_CHN_UNINIT == CddDmaChStatus[Channel].Status)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_CONFIG_RAM_RELOAD, CDDDMA_E_UNINIT);
    }
    else
    {
        if (NULL_PTR == List)
        {
            (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_CONFIG_RAM_RELOAD, CDDDMA_E_PARAM_POINTER);
        }
        else if (0U == CtsCount)
        {
            (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_CONFIG_RAM_RELOAD, CDDDMA_E_OUT_OF_RANGE);
        }
        /* MR12 RULE 11.4 VIOLATION: Here a cast is made between an object pointer and an integer type. In this specific case,
         * needs to obtain the integer value of the Scts address, thus, couldn't adhere to M3CM Rule-11.4
         */
        else if ((((uint32)Scts & ALIGNED_32B_MASK) != 0U) || (Scts == NULL_PTR)) /* PRQA S 0306 */
        {
            (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_CONFIG_RAM_RELOAD, CDDDMA_E_ADDR_UNALIGNED);
        }
        else if (NULL_PTR == TransferConfig)
        {
            (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_CONFIG_RAM_RELOAD, CDDDMA_E_PARAM_POINTER);
        }
        else
#endif
        {
            CddDma_ConfigRamReload(List, TransferConfig, Scts, CtsCount, LoopMode);
        }
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif

CDDDMA_FUNC void CddDma_InstallCallback(CddDma_ChannelType Channel, CddDma_CallbackType Callback, uint32 Parameter)
{
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= Channel)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_INSTALL_CALLBACK, CDDDMA_E_OUT_OF_RANGE);
    }
    /* Check current channel of DMA must be initialed */
    else if (DMA_CHN_UNINIT == CddDmaChStatus[Channel].Status)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_INSTALL_CALLBACK, CDDDMA_E_UNINIT);
    }
    /* Check the Parameter of Callback is valid*/
    else if (NULL_PTR == Callback)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_INSTALL_CALLBACK, CDDDMA_E_PARAM_POINTER);
    }
    else
#endif
    {
        CddDma_Lld_InstallCallback(Channel, Callback, Parameter);
    }
}

CDDDMA_FUNC void CddDma_InstallErrorCallback(CddDma_ChannelType Channel, CddDma_CallbackType Callback, uint32 Parameter)
{
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= Channel)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_INSTALL_ERROR_CALLBACK, CDDDMA_E_OUT_OF_RANGE);
    }
    /* Check current channel of DMA must be initialed */
    else if (DMA_CHN_UNINIT == CddDmaChStatus[Channel].Status)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_INSTALL_ERROR_CALLBACK, CDDDMA_E_UNINIT);
    }
    /* Check the Parameter of Callback is valid*/
    else if (NULL_PTR == Callback)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_INSTALL_ERROR_CALLBACK, CDDDMA_E_PARAM_POINTER);
    }
    else
#endif
    {
        CddDma_Lld_InstallErrorCallback(Channel, Callback, Parameter);
    }
}

CDDDMA_FUNC void CddDma_GetChannelStatus(CddDma_ChannelType Channel, CddDma_ChannelStatusReturnType *ChannelStatus)
{
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= Channel)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_GET_CHANNEL_STATUS, CDDDMA_E_OUT_OF_RANGE);
    }
    /* Check current channel of DMA must be initialed */
    else if (DMA_CHN_UNINIT == CddDmaChStatus[Channel].Status)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_GET_CHANNEL_STATUS, CDDDMA_E_UNINIT);
    }
    else if (NULL_PTR == ChannelStatus)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_GET_CHANNEL_STATUS, CDDDMA_E_PARAM_POINTER);
    }
    else
#endif
    {
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call2params(CddDma_Lld_GetChannelStatus, Channel, ChannelStatus);
#else
        CddDma_Lld_GetChannelStatus(Channel, ChannelStatus);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
    }
}

CDDDMA_FUNC void CddDma_ClearChannelDoneStatus(CddDma_ChannelType Channel)
{
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= Channel)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_CLEAR_CHANNEL_DONE_STATUS, CDDDMA_E_OUT_OF_RANGE);
    }
    else if (DMA_CHN_UNINIT == CddDmaChStatus[Channel].Status)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_CLEAR_CHANNEL_DONE_STATUS, CDDDMA_E_UNINIT);
    }
    else
#endif
    {
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(CddDma_Lld_ClearChannelDoneStatus, Channel);
#else
        CddDma_Lld_ClearChannelDoneStatus(Channel);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
    }
}

CDDDMA_FUNC uint32 CddDma_GetChannelRemainingTriggerCount(CddDma_ChannelType Channel)
{
    uint32 RemainingCount = 0U;
#if (CDDDMA_DEV_ERROR_DETECT == STD_ON)
    if (CDDDMA_CHANNEL_CONFIG_COUNT <= Channel)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_GET_REMAINING_TRIGGER_COUNT, CDDDMA_E_OUT_OF_RANGE);
    }
    else if (DMA_CHN_UNINIT == CddDmaChStatus[Channel].Status)
    {
        (void)Det_ReportError(CDDDMA_MODULE_ID, CDDDMA_INSTANCE_ID, CDDDMA_SID_GET_REMAINING_TRIGGER_COUNT, CDDDMA_E_UNINIT);
    }
    else
#endif
    {
#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
        RemainingCount = OsIf_Trusted_Call_Return1param(CddDma_Lld_GetRemainingTriggerCount, Channel);
#else
        RemainingCount = CddDma_Lld_GetRemainingTriggerCount(Channel);
#endif /* CDDDMA_ENABLE_USER_MODE_SUPPORT */
    }
    return RemainingCount;
}

#define CDDDMA_STOP_SEC_CODE
#include "CddDma_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file CddDma.c */

