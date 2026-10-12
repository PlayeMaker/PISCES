/**
* @file    CddDma_Lld.c
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

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @page misra_violations MISRA-C:2012 violations List
 * PRQA S 2985 Rule 2.2:  The operation here is redundant as the result's Value is always that of the left-hand operand.
 */

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "CddDma.h"
#include "CddDma_Lld.h"
#include "CddDma_Lld_Reg.h"
#include "SchM_CddDma.h"
#include "OsIf.h"

/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDDDMA_LLD_VENDOR_ID_C                      (180)
#define CDDDMA_LLD_AR_RELEASE_MAJOR_VERSION_C       (4)
#define CDDDMA_LLD_AR_RELEASE_MINOR_VERSION_C       (4)
#define CDDDMA_LLD_AR_RELEASE_REVISION_VERSION_C    (0)
#define CDDDMA_LLD_SW_MAJOR_VERSION_C               (0)
#define CDDDMA_LLD_SW_MINOR_VERSION_C               (9)
#define CDDDMA_LLD_SW_PATCH_VERSION_C               (1)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if Source file and CDDDMA_LLD header file are of the same vendor */
#if (CDDDMA_LLD_VENDOR_ID_C != CDDDMA_LLD_VENDOR_ID)
#error "CddDma_Lld.c and CddDma_Lld.h have different vendor ids"
#endif

/* Check if Source file and CDDDMA_LLD header file are of the same Autosar version */
#if (( CDDDMA_LLD_AR_RELEASE_MAJOR_VERSION_C != CDDDMA_LLD_AR_RELEASE_MAJOR_VERSION) || \
      ( CDDDMA_LLD_AR_RELEASE_MINOR_VERSION_C != CDDDMA_LLD_AR_RELEASE_MINOR_VERSION) || \
      ( CDDDMA_LLD_AR_RELEASE_REVISION_VERSION_C != CDDDMA_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CddDma_Lld.c and CddDma_Lld.h are different"
#endif

/* Check if Source file and CDDDMA_LLD header file are of the same Software version */
#if (( CDDDMA_LLD_SW_MAJOR_VERSION_C != CDDDMA_LLD_SW_MAJOR_VERSION) || \
      ( CDDDMA_LLD_SW_MINOR_VERSION_C != CDDDMA_LLD_SW_MINOR_VERSION) || \
      ( CDDDMA_LLD_SW_PATCH_VERSION_C != CDDDMA_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of CddDma_Lld.c and CddDma_Lld.h are different"
#endif

/* Check if Source file and CddDma_Lld_Reg header file are of the same vendor */
#if (CDDDMA_LLD_VENDOR_ID_C != CDDDMA_LLD_REG_VENDOR_ID)
#error "CddDma_Lld.c and CddDma_Lld_Reg.h have different vendor ids"
#endif

/* Check if Source file and CddDma_Lld_Reg header file are of the same Autosar version */
#if (( CDDDMA_LLD_AR_RELEASE_MAJOR_VERSION_C != CDDDMA_LLD_REG_AR_RELEASE_MAJOR_VERSION) || \
      ( CDDDMA_LLD_AR_RELEASE_MINOR_VERSION_C != CDDDMA_LLD_REG_AR_RELEASE_MINOR_VERSION) || \
      ( CDDDMA_LLD_AR_RELEASE_REVISION_VERSION_C != CDDDMA_LLD_REG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CddDma_Lld.c and CddDma_Lld_Reg.h are different"
#endif

/* Check if Source file and CddDma_Lld_Reg header file are of the same Software version */
#if (( CDDDMA_LLD_SW_MAJOR_VERSION_C != CDDDMA_LLD_REG_SW_MAJOR_VERSION) || \
      ( CDDDMA_LLD_SW_MINOR_VERSION_C != CDDDMA_LLD_REG_SW_MINOR_VERSION) || \
      ( CDDDMA_LLD_SW_PATCH_VERSION_C != CDDDMA_LLD_REG_SW_PATCH_VERSION))
#error "Software Version Numbers of CddDma_Lld.c and CddDma_Lld_Reg.h are different"
#endif

/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/
extern CddDma_ChannelStatusType CddDmaChStatus[CDDDMA_CHANNEL_CONFIG_COUNT];
/*==================================================================================================
                                                LOCAL VARIABLES
==================================================================================================*/
#define CDDDMA_START_SEC_CONST_UNSPECIFIED
#include "CddDma_MemMap.h"

/*! @brief Array of Base addresses for DMA instances. */
CDDDMA_CONST static volatile DMA_Type *const DmaBase[DMA_INSTANCE_COUNT] = DMA_BASE_PTRS;

#define CDDDMA_STOP_SEC_CONST_UNSPECIFIED
#include "CddDma_MemMap.h"

/*==================================================================================================
                                                LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                                LOCAL FUNCTIONS
==================================================================================================*/

#define CDDDMA_START_SEC_CODE
#include "CddDma_MemMap.h"

/**
* @brief         Configures the DMA request for the DMAMUX Channel by setting the DMA Source routed to a DMA Channel.
* @autosar       N/A
*
* @details       Service ID: N/A (Internal Function)
*                Sync/Async: Synchronous
*                Reentrancy: Non Reentrant
*                Available via: CddDma_Lld.c
*
* @param[in] Base: Register Base Address for DMAMUX module.
* @param[in] Channel: DMAMUX Channel number.
* @param[in] Source: DMA request Source.
* @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetChannelMux(volatile DMA_Type *Base, uint8 Channel, uint8 Source)
{
    Base->CHMUX[Channel] = Source;
}

/**
* @brief         Clear the DMA request for the DMAMUX Channel by disabling the DMA request source.
* @autosar       N/A
*
* @details       Service ID: N/A (Internal Function)
*                Sync/Async: Synchronous
*                Reentrancy: Non Reentrant
*                Available via: CddDma_Lld.c
*
* @param[in] Base: Register Base Address for DMAMUX module.
* @param[in] Channel: DMAMUX Channel number.
* @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_ClearChannelMux(volatile DMA_Type *Base, uint8 Channel)
{
    Base->CHMUX[Channel] = (uint8)DMA_REQ_DISABLED;
}

/**
* @brief         Halts or does not halt the DMA module when an error occurs. Error causes the HALT bit to be set. Subsequently,
*                all service requests are ignored until the HALT bit is cleared.
* @autosar       N/A
*
* @details       Service ID: N/A (Internal Function)
*                Sync/Async: Synchronous
*                Reentrancy: Non Reentrant
*                Available via: CddDma_Lld.c
*
* @param[in] Base: Register Base Address for DMA module.
* @param[in] HaltOnError: Halts (true) or not halt (false) DMA module when an error occurs.
* @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetHaltOnErrorCmd(volatile DMA_Type *Base, boolean HaltOnError)
{
    uint32 RegValTemp;
    RegValTemp = Base->CTRL;
    RegValTemp &= ~DMA_CTRL_POE_MASK;
    RegValTemp |= DMA_CTRL_POE(HaltOnError);
    Base->CTRL = RegValTemp;
}

/*!
 * @brief Enables/Disables the DMA Debug mode.
 *
 * @details
 *
 * @param[in] Base  Register Base Address for DMA module.
 * @param[in] Debug Enable (true) or disable (false) DMA module.
 *
 * @return void
 */
/**
* @brief         Enables/Disables the DMA Debug mode. When in debug mode, the DMA stalls the start of a new channel.
*                Executing channels are allowed to complete.
* @autosar       N/A
*
* @details       Service ID: N/A (Internal Function)
*                Sync/Async: Synchronous
*                Reentrancy: Non Reentrant
*                Available via: CddDma_Lld.c
*
* @param[in] Base: Register Base Address for DMA module.
* @param[in] Debug: Enable (true) or disable (false) DMA debug mode.
* @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetDebugMode(volatile DMA_Type *Base, boolean Debug)
{
    uint32 RegValTemp;
    RegValTemp = Base->CTRL;
    RegValTemp &= ~DMA_CTRL_DBGDIS_MASK;
    RegValTemp |= DMA_CTRL_DBGDIS(Debug);
    Base->CTRL = RegValTemp;
}

/**
* @brief         Enables/Disables the transfer loop mapping feature. If enabled, the BCNT is redefined to include the individual Enable fields and
*                the BCNT field. The individual Enable fields allow the transfer loop Offset to be applied to the Source Address, the destination
*                Address, or both. The BCNT field is reduced when either Offset is enabled.
* @autosar       N/A
*
* @details       Service ID: N/A (Internal Function)
*                Sync/Async: Synchronous
*                Reentrancy: Non Reentrant
*                Available via: CddDma_Lld.c
*
* @param[in] Base: Register Base Address for DMA module.
* @param[in] Enable: Enables (true) or Disable (false) transfer loop mapping.
* @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetTransferLoopMappingCmd(volatile DMA_Type *Base, boolean Enable)
{
    uint32 RegValTemp;
    RegValTemp = Base->CTRL;
    RegValTemp &= ~DMA_CTRL_LOEN_MASK;
    RegValTemp |= DMA_CTRL_LOEN(Enable);
    Base->CTRL = RegValTemp;
}

/**
* @brief         Configure error interrupt for channels by enabling or disabling error interrupt functionality for a specific DMA channel.
* @autosar       N/A
*
* @details       Service ID: N/A (Internal Function)
*                Sync/Async: Synchronous
*                Reentrancy: Non Reentrant
*                Available via: CddDma_Lld.c
*
* @param[in] Base: Register Base Address for DMA module.
* @param[in] Channel: DMA Channel number.
* @param[in] Enable: Interrupt Enable (true) or Disable (false).
* @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetErrorIntCmd(volatile DMA_Type *Base, uint8 Channel, boolean Enable)
{
    if (TRUE == Enable)
    {
        Base->CHEIE |= (uint32) 0x01U << Channel;
    }
    else
    {
        Base->CHEIE &= ~((uint32)0x01U << Channel);
    }
}

/**
* @brief         Enables/Disables the half complete interrupt for the CTS. If set, the Channel generates an interrupt request by setting the
*                appropriate bit in the interrupt register when the current major iteration Count reaches the halfway point. Specifically,
*                the comparison performed by the DMA engine is (TCNT == (TCNTRV >> 1)). This half-way point interrupt request is provided to
*                support the double-buffered schemes or other types of data movement where the processor needs an early indication of the
*                transfer's process.
* @autosar       N/A
*
* @details       Service ID: N/A (Internal Function)
*                Sync/Async: Synchronous
*                Reentrancy: Non Reentrant
*                Available via: CddDma_Lld.c
*
* @param[in] Base: Register Base Address for DMA module.
* @param[in] Channel: DMA Channel number.
* @param[in] Enable: Enable (true) /Disable (false) half complete interrupt.
* @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetMajorHalfCompleteIntCmd(volatile DMA_Type *Base, uint8 Channel, boolean Enable)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= (uint16) ~DMA_CTS_CSR_THDINT_MASK;
    RegValTemp |= (uint16) DMA_CTS_CSR_THDINT(Enable);
    Base->CTS[Channel].CSR = RegValTemp;
}

/**
 * @brief         Enables/Disables the interrupt after the trigger loop completes for the CTS. If enabled, the Channel generates an interrupt
 *                request by setting the appropriate bit in the interrupt register when the current major iteration Count reaches zero.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[in] Channel: DMA Channel number.
 * @param[in] Enable: Enable (true) /Disable (false) interrupt after CTS done.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetCtsMajorCompleteIntCmd(volatile DMA_Type *Base, uint8 Channel, boolean Enable)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= (uint16) ~DMA_CTS_CSR_TDINT_MASK;
    RegValTemp |= (uint16) DMA_CTS_CSR_TDINT(Enable);
    Base->CTS[Channel].CSR = RegValTemp;
}

/**
 * @brief         Gets the current channel's trigger loop done interrupt enable state.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[in] Channel: DMA Channel number.
 * @return boolean TRUE: if the trigger loop done interrupt is enabled;
 *                 FALSE: otherwise.
*/
CDDDMA_FUNC LOCAL_INLINE boolean CddDma_Lld_GetCtsMajorCompleteIntCmd(const volatile DMA_Type *Base, uint8 Channel)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    return (((RegValTemp & DMA_CTS_CSR_TDINT_MASK) != 0U) ? TRUE : FALSE);
}

/**
 * @brief         Configures DMA engine to stall for a number of cycles after each R/W operation. This function controls the bandwidth control (BWC)
 *                feature to introduce deliberate delays between read/write operations.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[in] Channel: DMA Channel number.
 * @param[in] Cycles: Number of cycles the DMA engine is stalled after each R/W operation.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetCtsEngineStall(volatile DMA_Type *Base, uint8 Channel, CddDma_EngineStallType Cycles)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= ~DMA_CTS_CSR_BWC_MASK;
    RegValTemp |= (uint16)DMA_CTS_CSR_BWC(Cycles);
    Base->CTS[Channel].CSR = RegValTemp;
}

/**
 * @brief         Gets CTS active bit Value of DMA Channel. Returns the current active status indicating whether the channel is currently executing a
 *                transfer operation.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[in] Channel: DMA Channel number.
 * @param[out] PValue: Active bit Value - TRUE if channel is active, FALSE if inactive.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_GetCtsActiveStatus(const volatile DMA_Type *Base, uint8 Channel, boolean *PValue)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= DMA_CTS_CSR_ACTIVE_MASK;
    *PValue = (((RegValTemp >> DMA_CTS_CSR_ACTIVE_SHIFT) != 0U) ? TRUE : FALSE);
}

/**
 * @brief         Gets CTS Done bit Value of DMA Channel. Returns the current completion status indicating whether the channel has finished its
 *                transfer operation.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[in] Channel: DMA Channel number.
 * @param[out] PValue: Done bit Value - TRUE if channel transfer is complete, FALSE if still in progress or not started.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_GetCtsDoneStatus(const volatile DMA_Type *Base, uint8 Channel, boolean *PValue)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= DMA_CTS_CSR_DONE_MASK;
    *PValue = (((RegValTemp >> DMA_CTS_CSR_DONE_SHIFT) != 0U) ? TRUE : FALSE);
}

/**
 * @brief         Gets the DMA error status by reading the ERS (Error Status) register, which contains flags indicating which channels have
 *                encountered errors.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[out] Value: ERS register's Value - contains error status flags for all channels.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_GetErrorStatus(const volatile DMA_Type *Base, uint32 *Value)
{
    *Value = Base->ERS;
}

/**
 * @brief         Configures the Source Address for the hardware CTS of a specific DMA channel.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[in] Channel: DMA Channel number.
 * @param[in] Address: The pointer to the Source memory Address.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetCtsSrcAddr(volatile DMA_Type *Base, uint8 Channel, uint32 Address)
{
    Base->CTS[Channel].SADDR = Address;
}

/**
 * @brief         Configures the destination Address for the CTS of a specific DMA channel.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[in] Channel: DMA Channel number.
 * @param[in] Address: The pointer to the destination Address.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetCtsDestAddr(volatile DMA_Type *Base, uint8 Channel, uint32 Address)
{
    Base->CTS[Channel].DADDR = Address;
}

/**
 * @brief         Configures the destination Address signed Offset for the CTS of a specific DMA channel.
 *                Sign-extended Offset applied to the current destination Address to form the next-state Value as each destination write is complete.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[in] Channel: DMA Channel number.
 * @param[in] Offset: Signed-offset applied to destination address after each write operation.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetCtsDestOffset(volatile DMA_Type *Base, uint8 Channel, sint16 Offset)
{
    Base->CTS[Channel].DOFF = (uint16) Offset;
}

/**
 * @brief         Configures the Source Address signed Offset for the hardware CTS of a specific DMA channel.
 *                Sign-extended Offset applied to the current Source Address to form the next-state Value as each Source read is complete.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[in] Channel: DMA Channel number.
 * @param[in] Offset: Signed-offset applied to source address after each read operation.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetCtsSrcOffset(volatile DMA_Type *Base, uint8 Channel, sint16 Offset)
{
    Base->CTS[Channel].SOFF = (uint16) Offset;
}

/**
 * @brief         Configures the last Source Address adjustment for the CTS of a specific DMA channel.
 *                Adjustment Value added to the Source Address at the completion of the major iteration Count. This Value can be applied to restore
 *                the Source Address to the initial Value, or Adjust the Address to reference the next data structure.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[in] Channel: DMA Channel number.
 * @param[in] Adjust: Adjustment Value added to the Source Address at completion of major iteration.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetCtsSrcLastAdjust(volatile DMA_Type *Base, uint8 Channel, sint32 Adjust)
{
    Base->CTS[Channel].STO = (uint32) Adjust;
}

/**
 * @brief         Configures the last destination Address adjustment for the CTS of a specific DMA channel.
 *                Adjustment Value added to the destination Address at the completion of the major iteration Count. This Value can be applied to
 *                restore the destination Address to the initial Value, or Adjust the Address to reference the next data structure.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[in] Channel: DMA Channel number.
 * @param[in] Adjust: Adjustment Value added to the destination Address at completion of major iteration.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetCtsDestLastAdjust(volatile DMA_Type *Base, uint8 Channel, sint32 Adjust)
{
    Base->CTS[Channel].DTO_RLD.DTO = (uint32) Adjust;
}

/**
 * @brief         Enables/Disables the ram reload feature for the CTS of a specific DMA channel.
 *                When enabled, the DMA channel can automatically load the next transfer descriptor from memory upon completion of the current
 *                transfer, enabling chained transfers without CPU intervention.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[in] Channel: DMA Channel number.
 * @param[in] Enable: Enables (true) /Disables (false) ram reload feature.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetCtsRamReloadCmd(volatile DMA_Type *Base, uint8 Channel, boolean Enable)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= (uint16) ~DMA_CTS_CSR_RLDEN_MASK;
    RegValTemp |= (uint16) DMA_CTS_CSR_RLDEN(Enable);
    Base->CTS[Channel].CSR = RegValTemp;
}

/**
 * @brief         Gets the enable state of the RAM reload feature for the CTS of a specific DMA channel.
 *                Returns whether the automatic descriptor loading feature is currently enabled for the specified channel.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[in] Channel: DMA Channel number.
 * @return boolean TRUE: if ram reload feature is enabled;
 *                 FALSE: otherwise
*/
CDDDMA_FUNC LOCAL_INLINE boolean CddDma_Lld_GetCtsRamReloadCmd(const volatile DMA_Type *Base, uint8 Channel)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    return (((RegValTemp & DMA_CTS_CSR_RLDEN_MASK) != 0U) ? TRUE : FALSE);
}

/**
 * @brief         Configures the memory Address for the next transfer CTS for the specified channel.
 *                This Address points to the beginning of a 32-byte aligned region containing the next transfer CTS to be loaded into this Channel.
 *                The Channel reload is performed as the major iteration Count completes. The ram reload Address must be 32-byte aligned.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[in] Channel: DMA Channel number.
 * @param[in] NextCTSAddr: The Address of the next CTS to be linked to this CTS.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetCtsRamReloadLink(volatile DMA_Type *Base, uint8 Channel, uint32 NextCTSAddr)
{
    Base->CTS[Channel].DTO_RLD.RLD = NextCTSAddr;
}

/**
* @brief         Enables/disables the Source transfer loop Offset feature for the CTS of a specific DMA channel.
*                Configures whether the transfer loop Offset is applied to the Source Address upon transfer loop completion.
*                NOTE: LOEN bit needs to be enabled prior to calling this function, otherwise it has no effect.
* @autosar       N/A
*
* @details       Service ID: N/A (Internal Function)
*                Sync/Async: Synchronous
*                Reentrancy: Non Reentrant
*                Available via: CddDma_Lld.c
*
* @param[in] Base: Register Base Address for DMA module.
* @param[in] Channel: DMA Channel number.
* @param[in] Enable: Enables (true) or disables (false) Source transfer loop Offset.
* @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetCtsSrcMinorLoopOffsetCmd(volatile DMA_Type *Base, uint8 Channel, boolean Enable)
{
    if (((Base->CTRL >> DMA_CTRL_LOEN_SHIFT) & 1U) != 0U)
    {
        uint32 RegValTemp;
        RegValTemp = Base->CTS[Channel].BCNT.LOEN;
        RegValTemp &= ~DMA_CTS_BCNT_LOEN_SLOE_MASK;
        /* MR12 RULE 2.2 VIOLATION: The operation here is redundant as the result's Value is always that of the left-hand operand. This is used to
           improve code readability and maintain consistency in bit manipulation operations. */
        RegValTemp |= DMA_CTS_BCNT_LOEN_SLOE(Enable); /*PRQA S 2985*/
        Base->CTS[Channel].BCNT.LOEN = RegValTemp;
    }
    else
    {
        /* Do nothing*/
    }
}

/**
 * @brief         Enables/disables the destination transfer loop Offset feature for the CTS of a specific DMA channel.
 *                Configures whether the transfer loop Offset is applied to the destination Address upon transfer loop completion.
 *                NOTE: LOEN bit needs to be enabled prior to calling this function, otherwise it has no effect.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[in] Channel: DMA Channel number.
 * @param[in] Enable: Enables (true) or disables (false) destination transfer loop Offset.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetCtsDstMinorLoopOffsetCmd(volatile DMA_Type *Base, uint8 Channel, boolean Enable)
{
    if (((Base->CTRL >> DMA_CTRL_LOEN_SHIFT) & 1U) != 0U)
    {
        uint32 RegValTemp;
        RegValTemp = Base->CTS[Channel].BCNT.LOEN;
        RegValTemp &= ~DMA_CTS_BCNT_LOEN_DLOE_MASK;
        RegValTemp |= DMA_CTS_BCNT_LOEN_DLOE(Enable);
        Base->CTS[Channel].BCNT.LOEN = RegValTemp;
    }
    else
    {
        /* Do nothing*/
    }
}

/**
 * @brief         Enables/Disables the major link for the CTS of a specific DMA channel.
 *                When enabled, the major link allows the current channel to trigger another channel upon completion of its transfer.
 *                The major link is configured by setting the TLKCH field to the desired channel number and enabling the TLKEN field.
 *                NOTE: The major link channel must be different from the current channel to avoid self-triggering.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[in] Channel: DMA Channel number.
 * @param[in] LinkChannel: The Channel number to be linked to current Channel.
 * @param[in] Enable: Enables (true) or Disables (false) Channel major link.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetCtsChannelTriggerLink(volatile DMA_Type *Base, uint8 Channel, uint8 LinkChannel, boolean Enable)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= (uint16) ~DMA_CTS_CSR_TLKCH_MASK;
    RegValTemp |= (uint16) DMA_CTS_CSR_TLKCH(LinkChannel);
    Base->CTS[Channel].CSR = RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= (uint16) ~DMA_CTS_CSR_TLKEN_MASK;
    RegValTemp |= (uint16) DMA_CTS_CSR_TLKEN(Enable);
    Base->CTS[Channel].CSR = RegValTemp;
}

/**
 * @brief         Configures the major iteration count for DMA channel transfer operations. This function adapts its behavior based on
 *                the channel's link configuration state, automatically selecting the appropriate register format and enforcing corresponding count
 *                limitations to ensure optimal transfer performance.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: Register Base Address for DMA module.
 * @param[in] Channel: Target DMA channel identifier specifying which channel's major iteration count will be configured.
 * @param[in] Count: Major iteration count value defining the number of complete transfer loops to execute.
 *                   Valid range depends on channel link configuration: 0-511 for linked channels, 0-32767 for non-linked channels.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_SetCtsTriggerCount(volatile DMA_Type *Base, uint8 Channel, uint32 Count)
{
    uint16 RegValTemp;
    if (DMA_CTS_TCNT_LKDIS_LKEN_MASK == (Base->CTS[Channel].TCNTRV & DMA_CTS_TCNT_LKDIS_LKEN_MASK))
    {
        RegValTemp = Base->CTS[Channel].TCNTRV;
        RegValTemp &= (uint16) ~DMA_CTS_TCNT_LKEN_TCNT_MASK;
        /* MR12 RULE 2.2 VIOLATION: The operation here is redundant as the result's Value is always that of the left-hand operand. This is used to
           improve code readability and maintain consistency in bit manipulation operations. */
        RegValTemp |= (uint16) DMA_CTS_TCNT_LKEN_TCNT(Count); /*PRQA S 2985*/
        Base->CTS[Channel].TCNTRV = RegValTemp;
        RegValTemp = Base->CTS[Channel].TCNT.LKEN;
        RegValTemp &= (uint16) ~DMA_CTS_TCNT_LKEN_TCNT_MASK;
        RegValTemp |= (uint16) DMA_CTS_TCNT_LKEN_TCNT(Count); /*PRQA S 2985*/
        Base->CTS[Channel].TCNT.LKEN = RegValTemp;
    }
    else
    {
        RegValTemp = Base->CTS[Channel].TCNTRV;
        RegValTemp &= (uint16) ~DMA_CTS_TCNT_LKDIS_TCNT_MASK;
        RegValTemp |= (uint16) DMA_CTS_TCNT_LKDIS_TCNT(Count); /*PRQA S 2985*/
        Base->CTS[Channel].TCNTRV = RegValTemp;
        RegValTemp = Base->CTS[Channel].TCNT.LKDIS;
        RegValTemp &= (uint16) ~DMA_CTS_TCNT_LKDIS_TCNT_MASK;
        RegValTemp |= (uint16) DMA_CTS_TCNT_LKDIS_TCNT(Count); /*PRQA S 2985*/
        Base->CTS[Channel].TCNT.LKDIS = RegValTemp;
    }
}

/**
 * @brief         Retrieves the current major iteration count for DMA channel transfer operations.
 *                This function adapts its behavior based on the channel's link configuration state, automatically selecting the appropriate
 *                register format to return the accurate remaining iteration count.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base:Register Base Address for DMA module.
 * @param[in] Channel: DMA Channel number to query for its current major iteration count.
 * @return uint32: Current major iteration count remaining for the specified channel.
*/
CDDDMA_FUNC LOCAL_INLINE uint32 CddDma_Lld_GetCtsCurrentTriggerCount(const volatile DMA_Type *Base, uint8 Channel)
{
    uint16 TriggerCount = 0U;
    if (DMA_CTS_TCNT_LKDIS_LKEN_MASK == (Base->CTS[Channel].TCNTRV & DMA_CTS_TCNT_LKDIS_LKEN_MASK))
    {
        TriggerCount = (Base->CTS[Channel].TCNT.LKEN & DMA_CTS_TCNT_LKEN_TCNT_MASK) >> DMA_CTS_TCNT_LKEN_TCNT_SHIFT;
    }
    else
    {
        TriggerCount = (Base->CTS[Channel].TCNT.LKDIS & DMA_CTS_TCNT_LKDIS_TCNT_MASK) >> DMA_CTS_TCNT_LKDIS_TCNT_SHIFT;
    }
    return (uint32)TriggerCount;
}

/**
 * @brief         Disables/Enables the DMA request after the trigger loop completes for the CTS of a specific DMA channel.
 *                If disabled, the DMA hardware automatically clears the corresponding DMA request when the current major iteration count
 *                reaches zero.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: DMA controller register base address.
 * @param[in] Channel: DMA channel number.
 * @param[in] Disable: Disable (true)/Enable (false) DMA request after CTS complete.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_DisDmaReqAfterCtsDoneCmd(volatile DMA_Type *Base, uint8 Channel, boolean Disable)
{
    uint16 RegValTemp;
    RegValTemp = Base->CTS[Channel].CSR;
    RegValTemp &= (uint16) ~DMA_CTS_CSR_DREQ_MASK;
    RegValTemp |= (uint16) DMA_CTS_CSR_DREQ(Disable);
    Base->CTS[Channel].CSR = RegValTemp;
}

/**
 * @brief         Clears the transfer completion status flag for a specific DMA channel.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: DMA controller register base address.
 * @param[in] Channel: DMA channel number.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_ClearDoneStatusFlag(volatile DMA_Type *Base, uint8 Channel)
{
    Base->DONE = (uint32) 0x01U << Channel;
}

/**
 * @brief         Clears the interrupt trigger done status flag for a specific DMA channel.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: DMA controller register base address.
 * @param[in] Channel: DMA channel number.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_ClearITriggerDoneStatusFlag(volatile DMA_Type *Base, uint8 Channel)
{
    Base->CHTLDIF = (uint32) 0x01U << Channel;
}

/**
* @brief         Retrieves the DMA error interrupt status flags for all channels by reading the CHEIF (Channel Error Interrupt Flag) register.
* @autosar       N/A
*
* @details       Service ID: N/A (Internal Function)
*                Sync/Async: Synchronous
*                Reentrancy: Reentrant
*                Available via: CddDma_Lld.c
*
* @param[in] Base: DMA controller register base address.
* @return uint32: 32-bit value indicating error interrupt status for all channels.
*                 If error interrupt occurs on DMA channel n, bit n is set to '1', otherwise '0'.
*/
CDDDMA_FUNC LOCAL_INLINE uint32 CddDma_Lld_GetErrorIntStatusFlag(const volatile DMA_Type *Base)
{
    return Base->CHEIF;
}

/**
 * @brief         Clears the error interrupt status flag for a specific DMA channel.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: DMA controller register base address.
 * @param[in] Channel: DMA channel number.
 * @return void
*/
CDDDMA_FUNC LOCAL_INLINE void CddDma_Lld_ClearErrorIntStatusFlag(volatile DMA_Type *Base, uint8 Channel)
{
    Base->CHEIF = (uint32) 0x01U << Channel;
}

#ifndef CPU_YTM32B1HA0
/**
 * @brief         Initializes a memory structure to zero state by clearing all bytes within the specified size range.
 *                This utility function provides safe memory initialization for DMA control structures and configuration data.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] StructPtr: Pointer to structure to be initialized.
 * @param[in] Size: Size in bytes for initialization.
 * @return void
*/
CDDDMA_FUNC static void CddDma_Lld_ClearStructure(uint8 *StructPtr, uint32 Size)
{
    uint8 *TmpPtr = StructPtr;
    uint32 TmpSize = Size;
    while (TmpSize > 0U)
    {
        *TmpPtr = 0;
        ++TmpPtr;
        --TmpSize;
    }
}
#endif

/**
 * @brief         Resets all hardware CTS registers to zero state for a specific DMA channel.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: DMA controller register base address.
 * @param[in] Channel: DMA Channel number.
 * @return void
*/
CDDDMA_FUNC static void CddDma_Lld_ClearCtsReg(volatile DMA_Type *Base, uint8 Channel)
{
    Base->CTS[Channel].BCNT.BCNT = 0U;
    Base->CTS[Channel].SADDR = 0U;
    Base->CTS[Channel].SOFF = 0;
    Base->CTS[Channel].TCR = 0U;
    Base->CTS[Channel].STO = 0;
    Base->CTS[Channel].DADDR = 0U;
    Base->CTS[Channel].DOFF = 0;
    Base->CTS[Channel].TCNT.LKDIS = 0U;
    Base->CTS[Channel].DTO_RLD.DTO = 0;
    Base->CTS[Channel].CSR = 0U;
    Base->CTS[Channel].TCNTRV = 0U;
}

/**
 * @brief         Initializes DMA module to a known state by clearing key control registers and resetting all channels.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: DMA controller register base address.
 * @return void
*/
CDDDMA_FUNC static void CddDma_Lld_ClearInstance(volatile DMA_Type *Base)
{
    /* Clear the bit of CR register */
    uint32 RegValTemp;
    RegValTemp = Base->CTRL;
    RegValTemp &= ~DMA_CTRL_CLM_MASK;       /* Clear continuous link mode */
    RegValTemp &= ~DMA_CTRL_CX_MASK;        /* Clear cancel transfer */
    RegValTemp &= ~DMA_CTRL_ECX_MASK;       /* Clear error cancel transfer */
    RegValTemp &= ~DMA_CTRL_DBGDIS_MASK;    /* Clear debug disable */
    RegValTemp &= ~DMA_CTRL_LOEN_MASK;      /* Clear loop offset enable */
    Base->CTRL = RegValTemp;
    Base->CHEIE = 0x0;                      /* Clear channel error interrupt enable */

    for (uint8 Channel = 0; Channel < CDDDMA_CHANNEL_CONFIG_COUNT; ++Channel)
    {
        /* Disables the DMA Channel request*/
        CddDma_Lld_SetDmaRequestCmd(Channel, FALSE);
        /* Clears all registers of DMA->CTS */
        CddDma_Lld_ClearCtsReg(Base, Channel);
        /* Clear all DMA hardware request*/
        CddDma_Lld_ClearChannelMux(Base, Channel);
    }
}

/**
 * @brief         Sets DMA request source for specified channel via DMAMUX routing.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Channel: DMA channel number.
 * @param[in] Source: DMA request source.
 * @return void
*/
CDDDMA_FUNC static void CddDma_Lld_SetChannelSourceRequest(uint8 Channel, CddDma_RequestSourceType Source)
{
    uint8 DmaInstance;
    volatile DMA_Type *DmaRegBase = NULL_PTR;
    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = DmaBase[DmaInstance];
    /* Set request and the trigger*/
    CddDma_Lld_SetChannelMux(DmaRegBase, Channel, (uint8)Source);
}

/**
 * @brief         Configures DMA channel interrupt settings.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Channel: DMA channel number.
 * @param[in] IntSrc: Interrupt configuration structure containing enable flags for different interrupt types.
 * @return void
*/
CDDDMA_FUNC static void CddDma_Lld_ConfigChannelInterrupt(uint8 Channel, CddDma_ChanInterruptType IntSrc)
{
    uint8 DmaInstance;
    volatile DMA_Type *DmaRegBase = NULL_PTR;
    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = DmaBase[DmaInstance];
    CddDma_Lld_SetErrorIntCmd(DmaRegBase, Channel, IntSrc.EnErrInt);
    CddDma_Lld_SetMajorHalfCompleteIntCmd(DmaRegBase, Channel, IntSrc.EnHalfMajorInt);
    CddDma_Lld_SetCtsMajorCompleteIntCmd(DmaRegBase, Channel, IntSrc.EnMajorInt);
}

/**
 * @brief         Configures the minor loop offset for CTS transfer operations when loop offset features are enabled.
 *                NOTE: LOEN bit needs to be enabled prior to calling this function, otherwise it has no effect.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: DMA controller register base address.
 * @param[in] Channel: DMA channel number.
 * @param[in] Offset: Minor loop offset value.
 * @return void
*/
CDDDMA_FUNC static void CddDma_Lld_SetCtsTransferLoopOffset(volatile DMA_Type *Base, uint8 Channel, sint32 Offset)
{
    uint32 RegValTemp;
    if (((Base->CTRL & DMA_CTRL_LOEN_MASK) >> DMA_CTRL_LOEN_SHIFT) != 0UL)
    {
        if ((((Base->CTS[Channel].BCNT.LODIS & DMA_CTS_BCNT_LODIS_SLOE_MASK) >> DMA_CTS_BCNT_LODIS_SLOE_SHIFT) != 0UL) ||
                (((Base->CTS[Channel].BCNT.LODIS & DMA_CTS_BCNT_LODIS_DLOE_MASK) >> DMA_CTS_BCNT_LODIS_DLOE_SHIFT) != 0UL))
        {
            RegValTemp = Base->CTS[Channel].BCNT.LOEN;
            RegValTemp &= ~DMA_CTS_BCNT_LOEN_OFFSET_MASK;
            RegValTemp |= DMA_CTS_BCNT_LOEN_OFFSET(Offset);
            Base->CTS[Channel].BCNT.LOEN = RegValTemp;
        }
    }
    else
    {
        /* Do nothing*/
    }
}

/**
 * @brief         Configures the number of bytes to transfer in each minor loop for a DMA channel, adapting to loop offset configuration state.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: DMA controller register base address.
 * @param[in] Channel: DMA channel number.
 * @param[in] Nbytes: Number of bytes to be transferred in each minor loop.
 * @return void
*/
CDDDMA_FUNC static void CddDma_Lld_SetCtsNbytes(volatile DMA_Type *Base, uint8 Channel, uint32 Nbytes)
{
    /* Only proceed if transfer loop mapping enabled */
    if (((Base->CTRL & DMA_CTRL_LOEN_MASK) >> DMA_CTRL_LOEN_SHIFT) != 0UL)
    {
        uint32 LodisReg = Base->CTS[Channel].BCNT.LODIS;
        uint32 Sloe = (LodisReg & DMA_CTS_BCNT_LODIS_SLOE_MASK) >> DMA_CTS_BCNT_LODIS_SLOE_SHIFT;
        uint32 Dloe = (LodisReg & DMA_CTS_BCNT_LODIS_DLOE_MASK) >> DMA_CTS_BCNT_LODIS_DLOE_SHIFT;

        /* If both SLOE and DLOE are disabled, write BCNT to LODIS; otherwise update LOEN.BCNT */
        if ((Sloe == 0UL) && (Dloe == 0UL))
        {
            Base->CTS[Channel].BCNT.LODIS = (Nbytes & DMA_CTS_BCNT_LODIS_BCNT_MASK);
        }
        else
        {
            uint32 RegValTemp = Base->CTS[Channel].BCNT.LOEN;
            RegValTemp &= ~DMA_CTS_BCNT_LOEN_BCNT_MASK;
            /* MR12 RULE 2.2 VIOLATION: The operation is redundant because the result value is always that of the left-hand operand.
               This is intentional to improve readability and portability across platforms. */
            RegValTemp |= DMA_CTS_BCNT_LOEN_BCNT(Nbytes); /*PRQA S 2985*/
            Base->CTS[Channel].BCNT.LOEN = RegValTemp;
        }
    }
#if 0 /* This branch is unreachable as LOEN is enabled by default */
    else
    {
        Base->CTS[Channel].BCNT.BCNT = Nbytes;
    }
#endif
}

/**
 * @brief         Configures minor loop channel linking for CTS transfer operations, enabling automatic channel triggering upon
 *                each minor loop completion.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: DMA controller register base address.
 * @param[in] Channel: DMA channel number.
 * @param[in] LinkChannel: The Channel number to be linked to current Channel.
 * @param[in] Enable: Enable (true)/Disable (false) channel minor link.
 * @return void
*/
CDDDMA_FUNC static void CddDma_Lld_SetCtsChannelLoopLink(volatile DMA_Type *Base, uint8 Channel, uint8 LinkChannel, boolean Enable)
{
    uint16 RegValTemp;

    /* Set the Link Enable bit to TCNTRV */
    RegValTemp = Base->CTS[Channel].TCNTRV;
    RegValTemp &= (uint16) ~DMA_CTS_TCNT_LKEN_LKEN_MASK;
    RegValTemp |= (uint16) DMA_CTS_TCNT_LKEN_LKEN(Enable);
    Base->CTS[Channel].TCNTRV = RegValTemp;

    /* Set the Link Enable bit to TCNT.LKEN */
    RegValTemp = Base->CTS[Channel].TCNT.LKEN;
    RegValTemp &= (uint16) ~DMA_CTS_TCNT_LKEN_LKEN_MASK;
    RegValTemp |= (uint16) DMA_CTS_TCNT_LKEN_LKEN(Enable);
    Base->CTS[Channel].TCNT.LKEN = RegValTemp;
    if (TRUE == Enable)
    {
        /* Set the Link Channel field to TCNTRV */
        RegValTemp = Base->CTS[Channel].TCNTRV;
        RegValTemp &= (uint16) ~DMA_CTS_TCNT_LKEN_LKCH_MASK;
        RegValTemp |= (uint16) DMA_CTS_TCNT_LKEN_LKCH(LinkChannel);
        Base->CTS[Channel].TCNTRV = RegValTemp;

        /* Set the Link Channel field to TCNT.LKEN */
        RegValTemp = Base->CTS[Channel].TCNT.LKEN;
        RegValTemp &= (uint16) ~DMA_CTS_TCNT_LKEN_LKCH_MASK;
        RegValTemp |= (uint16) DMA_CTS_TCNT_LKEN_LKCH(LinkChannel);
        Base->CTS[Channel].TCNT.LKEN = RegValTemp;
    }
}

/**
 * @brief         Configures transfer attributes for DMA channel including source/destination modulo settings and transfer sizes.
 *                NOTE: If modulo is enabled, the source and destination addresses must be aligned to the modulo Size.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: DMA controller register base address.
 * @param[in] Channel: DMA channel number.
 * @param[in] SrcModulo: Source modulo configuration for circular buffer addressing.
 * @param[in] DestModulo: Destination modulo configuration for circular buffer addressing.
 * @param[in] SrcTransferSize: Source transfer size per operation.
 * @param[in] DestTransferSize: Destination transfer size per operation.
 * @return void
*/
CDDDMA_FUNC static void CddDma_Lld_SetCtsAttribute(volatile DMA_Type *Base,
        uint8 Channel,
        CddDma_ModuloType SrcModulo,
        CddDma_ModuloType DestModulo,
        CddDma_TransferSizeType SrcTransferSize,
        CddDma_TransferSizeType DestTransferSize)
{
    uint16 RegValTemp;
    RegValTemp = (uint16)(DMA_CTS_TCR_SMOD(SrcModulo) | DMA_CTS_TCR_SSIZE(SrcTransferSize));
    /* MR12 RULE 2.2 VIOLATION: The operation here is redundant as the result's Value is always that of the left-hand operand. This is used to
       improve code readability and maintain consistency in bit manipulation operations. */
    RegValTemp |= (uint16)(DMA_CTS_TCR_DMOD(DestModulo) | DMA_CTS_TCR_DSIZE(DestTransferSize)); /*PRQA S 2985*/
    Base->CTS[Channel].TCR = RegValTemp;
}

/**
 * @brief         Copies comprehensive DMA channel configuration from software structure to hardware registers.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @param[in] Base: DMA controller register base address.
 * @param[in] Channel: DMA Channel number.
 * @param[in] CtsConfig: Pointer to transfer configuration structure.
 * @return void
*/
CDDDMA_FUNC static void CddDma_Lld_PushConfigToReg(volatile DMA_Type *Base, uint8 Channel, const CddDma_TransferConfigType *CtsConfig)
{
    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_01();
    /* Configure the DMA Engine to stall for a number of Cycles after each R/W */
    CddDma_Lld_SetCtsEngineStall(Base, Channel, CtsConfig->EngineStall);
    /* Set Source and destination addresses */
    CddDma_Lld_SetCtsSrcAddr(Base, Channel, CtsConfig->SrcAddr);
    CddDma_Lld_SetCtsDestAddr(Base, Channel, CtsConfig->DestAddr);
    /* Set Source/destination modulo feature and transfer Size */
    CddDma_Lld_SetCtsAttribute(Base, Channel, CtsConfig->SrcModulo, CtsConfig->DestModulo,
                               CtsConfig->SrcTransferSize, CtsConfig->DestTransferSize);
    /* Set Source/destination Offset and last adjustment; for ram reload operation, destination
     * last adjustment is the Address of the next CTS structure to be loaded by the DMA engine */
    CddDma_Lld_SetCtsSrcOffset(Base, Channel, CtsConfig->SrcOffset);
    CddDma_Lld_SetCtsDestOffset(Base, Channel, CtsConfig->DestOffset);

    CddDma_Lld_SetCtsSrcMinorLoopOffsetCmd(Base, Channel, CtsConfig->LoopTransferConfig->SrcOffsetEnable);
    CddDma_Lld_SetCtsDstMinorLoopOffsetCmd(Base, Channel, CtsConfig->LoopTransferConfig->DestOffsetEnable);
    CddDma_Lld_SetCtsTransferLoopOffset(Base, Channel, CtsConfig->LoopTransferConfig->TriggerLoopOffset);

    CddDma_Lld_SetCtsSrcLastAdjust(Base, Channel, CtsConfig->SrcLastAddrAdjust);
    if (TRUE == CtsConfig->ChannelPollingMode)
    {
        CddDma_Lld_SetErrorIntCmd(Base, Channel, FALSE);
        CddDma_Lld_SetMajorHalfCompleteIntCmd(Base, Channel, FALSE);
        CddDma_Lld_SetCtsMajorCompleteIntCmd(Base, Channel, FALSE);
    }
    else
    {
        CddDma_Lld_SetErrorIntCmd(Base, Channel, TRUE);
        CddDma_Lld_SetCtsMajorCompleteIntCmd(Base, Channel, TRUE);
    }
    if (TRUE == CtsConfig->RamReloadEnable)
    {
        CddDma_Lld_SetCtsRamReloadCmd(Base, Channel, TRUE);
        CddDma_Lld_SetCtsRamReloadLink(Base, Channel, CtsConfig->RamReloadNextDescAddr);
        CddDma_Lld_SetCtsMajorCompleteIntCmd(Base, Channel, CtsConfig->RamReloadIntEnable);
    }
    else
    {
        CddDma_Lld_SetCtsRamReloadCmd(Base, Channel, FALSE);
        CddDma_Lld_SetCtsDestLastAdjust(Base, Channel, CtsConfig->DestLastAddrAdjust);
    }
    /* If loop configuration is available, copy transfer/trigger loop setup to registers */
    if ((TRUE == CtsConfig->LoopTransferConfig->TriggerLoopChnLinkEnable) || (TRUE == CtsConfig->LoopTransferConfig->TransferLoopChnLinkEnable))
    {
        CddDma_Lld_SetCtsChannelLoopLink(Base, Channel, CtsConfig->LoopTransferConfig->TransferLoopChnLinkNumber,
                                         CtsConfig->LoopTransferConfig->TransferLoopChnLinkEnable);
        CddDma_Lld_SetCtsChannelTriggerLink(Base, Channel, CtsConfig->LoopTransferConfig->TriggerLoopChnLinkNumber,
                                            CtsConfig->LoopTransferConfig->TriggerLoopChnLinkEnable);
        CddDma_Lld_SetCtsTriggerCount(Base, Channel, CtsConfig->LoopTransferConfig->TriggerLoopIterationCount);
    }
    else
    {
        /* Set the number of trigger Count */
        CddDma_Lld_SetCtsTriggerCount(Base, Channel, CtsConfig->TriggerCount);
    }
    /* Set the number of data counts to be transferred in each trigger loop */
    CddDma_Lld_SetCtsNbytes(Base, Channel, CtsConfig->TransferLoopByteCount);
    CddDma_Lld_DisDmaReqAfterCtsDoneCmd(Base, Channel, CtsConfig->DisableReqOnCompletion);
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_01();
}

/**
 * @brief         Performs software reset of DMA controller by asserting and de-asserting the software reset control via IPC interface.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Internal Function)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld.c
 *
 * @return void
*/
CDDDMA_FUNC static void CddDma_Lld_SoftwareDeInit(void)
{
    /*Asserted a software reset*/
    IPC->CTRL[IPC_DMA_INDEX] |= (uint32)IPC_CTRL_SWREN_MASK;
    /*De-assert the software reset*/
    IPC->CTRL[IPC_DMA_INDEX] &= (uint32)(~IPC_CTRL_SWREN_MASK);
}

/*==================================================================================================
                                                GLOBAL FUNCTIONS
==================================================================================================*/
CDDDMA_FUNC void CddDma_Lld_Init(const CddDma_ConfigType *ConfigPtr)
{
    volatile DMA_Type *DmaRegBase = NULL_PTR;
    uint8 Channel;
    uint8 DmaInstance = 0;
    DmaRegBase = DmaBase[DmaInstance];
    CddDma_Lld_ClearInstance(DmaRegBase);
    /* Set configuration of 'Halt on error'*/
    CddDma_Lld_SetHaltOnErrorCmd(DmaRegBase, ConfigPtr->HaltOnError);
    CddDma_Lld_SetDebugMode(DmaRegBase, ConfigPtr->EnDebug);
    CddDma_Lld_SetTransferLoopMappingCmd(DmaRegBase, TRUE);
    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_02();
    for (uint8 ChnCount = 0; ChnCount < ConfigPtr->ChannelCount; ++ChnCount)
    {
        Channel = (uint8)ConfigPtr->ChannelConfigPtr[ChnCount].VirtualChannel;

        CddDma_Lld_SetChannelSourceRequest(Channel, ConfigPtr->ChannelConfigPtr[ChnCount].RequestSource);
        CddDma_Lld_ConfigChannelInterrupt(Channel, ConfigPtr->ChannelConfigPtr[ChnCount].ChanIntRequest);
        /* Copy and set configuration to global state */
        CddDmaChStatus[Channel].Callback = ConfigPtr->ChannelConfigPtr[ChnCount].Callback;
        CddDmaChStatus[Channel].CallbackParam = ConfigPtr->ChannelConfigPtr[ChnCount].CallbackParam;
        CddDmaChStatus[Channel].ErrorCallback = ConfigPtr->ChannelConfigPtr[ChnCount].ErrorCallback;
        CddDmaChStatus[Channel].ErrorCallbackParam = ConfigPtr->ChannelConfigPtr[ChnCount].ErrorCallbackParam;
        CddDmaChStatus[Channel].Status = DMA_CHN_NORMAL;
    }
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_02();
}

CDDDMA_FUNC void CddDma_Lld_Deinit(void)
{
    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_03();
    CddDma_Lld_SoftwareDeInit();
    /* Reset the channels state*/
    for (uint8 Channel = 0; Channel < CDDDMA_CHANNEL_CONFIG_COUNT; ++Channel)
    {
        CddDmaChStatus[Channel].Callback = NULL_PTR;
        CddDmaChStatus[Channel].CallbackParam = CDDDMA_UNDEFINED_PARAMETER;
        CddDmaChStatus[Channel].ErrorCallback = NULL_PTR;
        CddDmaChStatus[Channel].ErrorCallbackParam = CDDDMA_UNDEFINED_PARAMETER;
        CddDmaChStatus[Channel].Status = DMA_CHN_UNINIT;
    }
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_03();
}

CDDDMA_FUNC void CddDma_Lld_SetDmaRequestCmd(uint8 Channel, boolean Enable)
{
    uint8 DmaInstance;
    volatile DMA_Type *DmaRegBase = NULL_PTR;
    uint8 DmaActiveTimeout = 50U;
    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = DmaBase[DmaInstance];

#if defined (CPU_YTM32B1MD2)
    (void)DmaActiveTimeout; /* Avoid unused variable warning */
    /* For YTM32B1MD2, REQSET/REQCLR is used */
    if (TRUE == Enable)
    {
        DmaRegBase->REQSET = (0x01UL << Channel);
    }
    else
    {
        DmaRegBase->REQCLR = (0x01UL << Channel);
    }
#else
    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_04();
    /* Hardware clear of ReqEn causes inconsistent data writeback. It is necessary to add a DMA HALT,
     * then wait for several clock cycles before performing read and write operations.*/
    /* Halt DMA before changing the REQEN register*/
    DmaRegBase->CTRL |= 1UL << DMA_CTRL_PAUSE_SHIFT;
    /* Wait DMA active done*/
    while ((DmaRegBase->CTRL & DMA_CTRL_ACTIVE_MASK) != 0U)
    {
        --DmaActiveTimeout;
        if (0U == DmaActiveTimeout)
        {
            break;
        }
    }
    if (TRUE == Enable)
    {
        DmaRegBase->REQEN |= (0x01UL << Channel);
    }
    else
    {
        DmaRegBase->REQEN &= ~(0x01UL << Channel);
    }
    /* Resume DMA*/
    DmaRegBase->CTRL &= ~(1UL << DMA_CTRL_PAUSE_SHIFT);
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_04();
#endif /* CPU_YTM32B1MD2 */
}

CDDDMA_FUNC void CddDma_Lld_TriggerChannelStart(uint8 Channel)
{
    uint8 DmaInstance;
    volatile DMA_Type *DmaRegBase = NULL_PTR;
    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = DmaBase[DmaInstance];
    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_05();
    DmaRegBase->CTS[Channel].CSR |= DMA_CTS_CSR_START_MASK;
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_05();
}

CDDDMA_FUNC void CddDma_Lld_SetChannelTransfer(uint8 Channel, const CddDma_TransferConfigType *TransferConfig)
{
    uint8 DmaInstance;
    volatile DMA_Type *DmaRegBase = NULL_PTR;
    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = DmaBase[DmaInstance];
    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_06();
    /* Write the configuration in the transfer control descriptor registers */
    CddDma_Lld_PushConfigToReg(DmaRegBase, Channel, TransferConfig);
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_06();
}

CDDDMA_FUNC void CddDma_Lld_GetChannelStatus(uint8 Channel, CddDma_ChannelStatusReturnType *ChannelStatus)
{
    const volatile DMA_Type *DmaRegBase = NULL_PTR;
    uint8 DmaInstance;
    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = DmaBase[DmaInstance];
    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_07();
    ChannelStatus->ChannelStateValue = CddDmaChStatus[Channel].Status;
    CddDma_Lld_GetCtsActiveStatus(DmaRegBase, Channel, &ChannelStatus->Active);
    CddDma_Lld_GetCtsDoneStatus(DmaRegBase, Channel, &ChannelStatus->Done);
    CddDma_Lld_GetErrorStatus(DmaRegBase, &ChannelStatus->Errors);
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_07();
}

CDDDMA_FUNC void CddDma_Lld_ClearChannelDoneStatus(uint8 Channel)
{
    volatile DMA_Type *DmaRegBase = NULL_PTR;
    uint8 DmaInstance;
    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = DmaBase[DmaInstance];
    CddDma_Lld_ClearDoneStatusFlag(DmaRegBase, Channel);
}

CDDDMA_FUNC uint32 CddDma_Lld_GetRemainingTriggerCount(uint8 Channel)
{
    uint32 TriggerCount = 0U;
    uint8 DmaInstance;
    const volatile DMA_Type *DmaRegBase = NULL_PTR;
    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = DmaBase[DmaInstance];
    TriggerCount = CddDma_Lld_GetCtsCurrentTriggerCount(DmaRegBase, Channel);
    return TriggerCount;
}

#ifndef CPU_YTM32B1HA0
CDDDMA_FUNC void CddDma_Lld_PushConfigToScts(const CddDma_TransferConfigType *TransferConfig, CddDma_SoftwareCtsType *Scts)
{
    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_08();
    CddDma_Lld_ClearStructure((uint8 *) Scts, sizeof(CddDma_SoftwareCtsType));
    /* Set the software CTS fields */
    /* MR12 RULE 2.2 VIOLATION: The operation is redundant because the result value is always that of the left-hand operand.
       This is intentional to improve readability and portability across platforms. */
    Scts->ATTR = (uint16)(DMA_CTS_TCR_SMOD(TransferConfig->SrcModulo) | DMA_CTS_TCR_SSIZE(TransferConfig->SrcTransferSize) |
                          DMA_CTS_TCR_DMOD(TransferConfig->DestModulo) | DMA_CTS_TCR_DSIZE(TransferConfig->DestTransferSize)); /*PRQA S 2985*/
    Scts->SADDR = TransferConfig->SrcAddr;
    Scts->SOFF = TransferConfig->SrcOffset;
    Scts->STO = TransferConfig->SrcLastAddrAdjust;
    Scts->DADDR = TransferConfig->DestAddr;
    Scts->DOFF = TransferConfig->DestOffset;
    if (TRUE == TransferConfig->RamReloadEnable)
    {
        Scts->RamLoadAddr = (sint32) TransferConfig->RamReloadNextDescAddr;
    }
    else
    {
        Scts->RamLoadAddr = TransferConfig->DestLastAddrAdjust;
    }
    Scts->CSR = (uint16)(DMA_CTS_CSR_TDINT(TransferConfig->RamReloadIntEnable) |
                         DMA_CTS_CSR_RLDEN(TransferConfig->RamReloadEnable) |
                         DMA_CTS_CSR_DREQ(TransferConfig->DisableReqOnCompletion) |
                         DMA_CTS_CSR_BWC(TransferConfig->EngineStall));

    if ((TRUE == TransferConfig->LoopTransferConfig->SrcOffsetEnable) ||
            (TRUE == TransferConfig->LoopTransferConfig->DestOffsetEnable))
    {
        Scts->BCNT = DMA_CTS_BCNT_LOEN_SLOE(TransferConfig->LoopTransferConfig->SrcOffsetEnable) | /* PRQA S 2985 */
                     DMA_CTS_BCNT_LOEN_DLOE(TransferConfig->LoopTransferConfig->DestOffsetEnable) |
                     DMA_CTS_BCNT_LOEN_OFFSET(TransferConfig->LoopTransferConfig->TriggerLoopOffset) |
                     DMA_CTS_BCNT_LOEN_BCNT(TransferConfig->TransferLoopByteCount); /* PRQA S 2985 */
    }
    else
    {
        Scts->BCNT = DMA_CTS_BCNT_LODIS_BCNT(TransferConfig->TransferLoopByteCount); /* PRQA S 2985 */
    }
    if ((TRUE == TransferConfig->LoopTransferConfig->TransferLoopChnLinkEnable) ||
            (TRUE == TransferConfig->LoopTransferConfig->TriggerLoopChnLinkEnable))
    {
        Scts->TCNTRV = (uint16)TransferConfig->LoopTransferConfig->TriggerLoopIterationCount;
    }
    else
    {
        Scts->TCNT = (uint16)TransferConfig->TriggerCount;
    }
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_08();
}
#endif

CDDDMA_FUNC void CddDma_Lld_InstallCallback(uint8 Channel, CddDma_CallbackType Callback, uint32 Parameter)
{
    CddDma_ChannelStatusType *ChannelState;
    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_09();
    ChannelState = &CddDmaChStatus[Channel];
    ChannelState->Callback = Callback;
    ChannelState->CallbackParam = Parameter;
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_09();
}

CDDDMA_FUNC void CddDma_Lld_InstallErrorCallback(uint8 Channel, CddDma_CallbackType Callback, uint32 Parameter)
{
    CddDma_ChannelStatusType *ChannelState;
    SchM_Enter_CddDma_CDDDMA_EXCLUSIVE_AREA_10();
    ChannelState = &CddDmaChStatus[Channel];
    ChannelState->ErrorCallback = Callback;
    ChannelState->ErrorCallbackParam = Parameter;
    SchM_Exit_CddDma_CDDDMA_EXCLUSIVE_AREA_10();
}

/*!
* @brief This function is IRQ handler for DMA driver.
* @details
*
* @param[in] Channel  DMA virtual Channel number.
*
* @return void
*/
CDDDMA_FUNC void CddDma_Lld_IrqHandler(uint8 Channel)
{
    uint8 DmaInstance;
    boolean DoneState;
    volatile DMA_Type *DmaRegBase = NULL_PTR;
    /* Get DMA instance from virtual Channel */
    DmaInstance = (uint8) FEATURE_DMA_VCH_TO_INSTANCE(Channel);
    DmaRegBase = DmaBase[DmaInstance];

    CddDma_Lld_GetCtsDoneStatus(DmaRegBase, Channel, &DoneState);
    /* If Ram Reload command is active and loop mode is true:
       After one loop ends, the interrupt enable bit in the first block reloaded by CTS is disabled,
       so the interrupt enable bit cannot be used for judgment */
    if ((TRUE == CddDma_Lld_GetCtsRamReloadCmd(DmaRegBase, Channel)) && (TRUE == DoneState))
    {
        /* Clear Done */
        CddDma_Lld_ClearDoneStatusFlag(DmaRegBase, Channel);
        /* Clear the interrupt Status */
        CddDma_Lld_ClearITriggerDoneStatusFlag(DmaRegBase, Channel);
        if (NULL_PTR != CddDmaChStatus[Channel].Callback)
        {
            /* Callback for interrupt */
            CddDmaChStatus[Channel].Callback(CddDmaChStatus[Channel].CallbackParam);
        }
    }
    /* Check whether the interrupt's enable flag and status flag are both set */
    else if ((TRUE == CddDma_Lld_GetCtsMajorCompleteIntCmd(DmaRegBase, Channel)) && (TRUE == DoneState))
    {
        /* Clear Done */
        CddDma_Lld_ClearDoneStatusFlag(DmaRegBase, Channel);
        /* Clear the interrupt Status */
        CddDma_Lld_ClearITriggerDoneStatusFlag(DmaRegBase, Channel);
        if (NULL_PTR != CddDmaChStatus[Channel].Callback)
        {
            /* Callback for interrupt */
            CddDmaChStatus[Channel].Callback(CddDmaChStatus[Channel].CallbackParam);
        }
    }
    else
    {
        /* unwanted interrupt, do nothing */
    }

}

/*!
* @brief This function is the DMA Error IRQ handler for DMA driver.
* @details
*
* @param[in] Instance  DMA instance ID.
*
* @return void
*/
CDDDMA_FUNC void CddDma_Lld_Error_IrqHandler(uint8 Instance)
{
    volatile DMA_Type *DmaRegBase = NULL_PTR;
    uint32 ErrorStatus;
    DmaRegBase = DmaBase[Instance];
    ErrorStatus = CddDma_Lld_GetErrorIntStatusFlag(DmaRegBase);
    for (uint8 Channel = 0; Channel < CDDDMA_CHANNEL_CONFIG_COUNT; ++Channel)
    {
        /* Check whether the Error interrupt's enable flag and status flag are both set */
        if (((ErrorStatus & ((uint32)1U << Channel)) != 0U) && ((DmaRegBase->CHEIE & ((uint32)1U << Channel)) != 0U))
        {
            CddDma_Lld_SetDmaRequestCmd(Channel, FALSE);
            CddDmaChStatus[Channel].Status = DMA_CHN_ERROR;
            if (NULL_PTR != CddDmaChStatus[Channel].ErrorCallback)
            {
                /* Callback for interrupt */
                CddDmaChStatus[Channel].ErrorCallback(CddDmaChStatus[Channel].ErrorCallbackParam);
            }
            CddDma_Lld_ClearErrorIntStatusFlag(DmaRegBase, Channel);
            break;
        }
    }
}

#define CDDDMA_STOP_SEC_CODE
#include "CddDma_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file CddDma_Lld.c */

