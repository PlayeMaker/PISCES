/**
* @file    CddDma_Irq.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : CddDma_Irq
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_RELEASE_4_4_REV_0000
*   SW Version           : V0.9.1
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "CddDma_Lld.h"
#include "OsIf.h"
/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDDDMA_IRQ_VENDOR_ID_C                             (180)
#define CDDDMA_IRQ_AR_RELEASE_MAJOR_VERSION_C              (4)
#define CDDDMA_IRQ_AR_RELEASE_MINOR_VERSION_C              (4)
#define CDDDMA_IRQ_AR_RELEASE_REVISION_VERSION_C           (0)
#define CDDDMA_IRQ_SW_MAJOR_VERSION_C                      (0)
#define CDDDMA_IRQ_SW_MINOR_VERSION_C                      (9)
#define CDDDMA_IRQ_SW_PATCH_VERSION_C                      (1)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CddDma_Lld.h file are of the same vendor */
#if (CDDDMA_IRQ_VENDOR_ID_C != CDDDMA_LLD_VENDOR_ID)
#error "CddDma_Irq.c and CddDma_Lld.h have different vendor ids"
#endif

/* Check if source file and CddDma_Lld.h file are of the same Autosar version */
#if (( CDDDMA_IRQ_AR_RELEASE_MAJOR_VERSION_C != CDDDMA_LLD_AR_RELEASE_MAJOR_VERSION) || \
      ( CDDDMA_IRQ_AR_RELEASE_MINOR_VERSION_C != CDDDMA_LLD_AR_RELEASE_MINOR_VERSION) || \
      ( CDDDMA_IRQ_AR_RELEASE_REVISION_VERSION_C != CDDDMA_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CddDma_Irq.c and CddDma_Lld.h are different"
#endif

/* Check if source file and CddDma_Lld.h file are of the same Software version */
#if (( CDDDMA_IRQ_SW_MAJOR_VERSION_C != CDDDMA_LLD_SW_MAJOR_VERSION) || \
      ( CDDDMA_IRQ_SW_MINOR_VERSION_C != CDDDMA_LLD_SW_MINOR_VERSION) || \
      ( CDDDMA_IRQ_SW_PATCH_VERSION_C != CDDDMA_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of CddDma_Irq.c and CddDma_Lld.h are different"
#endif

/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
                                                LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
                                                LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
                                                GLOBAL FUNCTIONS
==================================================================================================*/

ISR(DMA_Error_IRQHandler);
ISR(DMA0_IRQHandler);
ISR(DMA1_IRQHandler);
ISR(DMA2_IRQHandler);
ISR(DMA3_IRQHandler);
#if (CDDDMA_MAX_CHANNEL_NUM > 4U)
ISR(DMA4_IRQHandler);
ISR(DMA5_IRQHandler);
ISR(DMA6_IRQHandler);
ISR(DMA7_IRQHandler);
#endif /* (CDDDMA_MAX_CHANNEL_NUM > 4U) */
#if (CDDDMA_MAX_CHANNEL_NUM > 8U)
ISR(DMA8_IRQHandler);
ISR(DMA9_IRQHandler);
ISR(DMA10_IRQHandler);
ISR(DMA11_IRQHandler);
ISR(DMA12_IRQHandler);
ISR(DMA13_IRQHandler);
ISR(DMA14_IRQHandler);
ISR(DMA15_IRQHandler);
#endif /* (CDDDMA_MAX_CHANNEL_NUM > 8U) */
#if (CDDDMA_MAX_CHANNEL_NUM > 16U)
ISR(DMA16_IRQHandler);
ISR(DMA17_IRQHandler);
ISR(DMA18_IRQHandler);
ISR(DMA19_IRQHandler);
ISR(DMA20_IRQHandler);
ISR(DMA21_IRQHandler);
ISR(DMA22_IRQHandler);
ISR(DMA23_IRQHandler);
ISR(DMA24_IRQHandler);
ISR(DMA25_IRQHandler);
ISR(DMA26_IRQHandler);
ISR(DMA27_IRQHandler);
ISR(DMA28_IRQHandler);
ISR(DMA29_IRQHandler);
ISR(DMA30_IRQHandler);
ISR(DMA31_IRQHandler);
#endif /* (CDDDMA_MAX_CHANNEL_NUM > 16U) */

#define CDDDMA_START_SEC_CODE
#include "CddDma_MemMap.h"

/**
 * @brief         DMA Error Interrupt Service Handler that processes DMA error interrupts and performs error handling for the
 *                specified DMA controller.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Interrupt Handler)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld_Irq.c
 * @return void
*/
CDDDMA_FUNC ISR(DMA_Error_IRQHandler)
{
    CddDma_Lld_Error_IrqHandler(0U);
}

/**
 * @brief         DMA Channel x Interrupt Service Handler that processes DMA channel x completion interrupts and invokes the corresponding handler
 *                for successful transfer completion.
 * @note          'x' is the channel number (0 to CDDDMA_MAX_CHANNEL_NUM - 1) and each channel has its own IRQ handler.
 * @autosar       N/A
 *
 * @details       Service ID: N/A (Interrupt Handler)
 *                Sync/Async: Synchronous
 *                Reentrancy: Non Reentrant
 *                Available via: CddDma_Lld_Irq.c
 * @return void
*/
CDDDMA_FUNC ISR(DMA0_IRQHandler)
{
    CddDma_Lld_IrqHandler(0U);
}

/*! @brief DMA Channel 1 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA1_IRQHandler)
{
    CddDma_Lld_IrqHandler(1U);
}

/*! @brief DMA Channel 2 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA2_IRQHandler)
{
    CddDma_Lld_IrqHandler(2U);
}

/*! @brief DMA Channel 3 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA3_IRQHandler)
{
    CddDma_Lld_IrqHandler(3U);
}

#if (CDDDMA_MAX_CHANNEL_NUM > 4U)

/*! @brief DMA Channel 4 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA4_IRQHandler)
{
    CddDma_Lld_IrqHandler(4U);
}

/*! @brief DMA Channel 5 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA5_IRQHandler)
{
    CddDma_Lld_IrqHandler(5U);
}

/*! @brief DMA Channel 6 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA6_IRQHandler)
{
    CddDma_Lld_IrqHandler(6U);
}

/*! @brief DMA Channel 7 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA7_IRQHandler)
{
    CddDma_Lld_IrqHandler(7U);
}

#endif /* (CDDDMA_MAX_CHANNEL_NUM > 4U) */
#if (CDDDMA_MAX_CHANNEL_NUM > 8U)

/*! @brief DMA Channel 8 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA8_IRQHandler)
{
    CddDma_Lld_IrqHandler(8U);
}

/*! @brief DMA Channel 9 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA9_IRQHandler)
{
    CddDma_Lld_IrqHandler(9U);
}

/*! @brief DMA Channel 10 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA10_IRQHandler)
{
    CddDma_Lld_IrqHandler(10U);
}

/*! @brief DMA Channel 11 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA11_IRQHandler)
{
    CddDma_Lld_IrqHandler(11U);
}

/*! @brief DMA Channel 12 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA12_IRQHandler)
{
    CddDma_Lld_IrqHandler(12U);
}

/*! @brief DMA Channel 13 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA13_IRQHandler)
{
    CddDma_Lld_IrqHandler(13U);
}

/*! @brief DMA Channel 14 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA14_IRQHandler)
{
    CddDma_Lld_IrqHandler(14U);
}

/*! @brief DMA Channel 15 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA15_IRQHandler)
{
    CddDma_Lld_IrqHandler(15U);
}

#endif /* (CDDDMA_MAX_CHANNEL_NUM > 8U) */
#if (CDDDMA_MAX_CHANNEL_NUM > 16U)
/*! @brief DMA Channel 16 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA16_IRQHandler)
{
    CddDma_Lld_IrqHandler(16U);
}

/*! @brief DMA Channel 17 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA17_IRQHandler)
{
    CddDma_Lld_IrqHandler(17U);
}

/*! @brief DMA Channel 18 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA18_IRQHandler)
{
    CddDma_Lld_IrqHandler(18U);
}

/*! @brief DMA Channel 19 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA19_IRQHandler)
{
    CddDma_Lld_IrqHandler(19U);
}

/*! @brief DMA Channel 20 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA20_IRQHandler)
{
    CddDma_Lld_IrqHandler(20U);
}

/*! @brief DMA Channel 21 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA21_IRQHandler)
{
    CddDma_Lld_IrqHandler(21U);
}

/*! @brief DMA Channel 22 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA22_IRQHandler)
{
    CddDma_Lld_IrqHandler(22U);
}

/*! @brief DMA Channel 23 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA23_IRQHandler)
{
    CddDma_Lld_IrqHandler(23U);
}

/*! @brief DMA Channel 24 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA24_IRQHandler)
{
    CddDma_Lld_IrqHandler(24U);
}

/*! @brief DMA Channel 25 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA25_IRQHandler)
{
    CddDma_Lld_IrqHandler(25U);
}

/*! @brief DMA Channel 26 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA26_IRQHandler)
{
    CddDma_Lld_IrqHandler(26U);
}

/*! @brief DMA Channel 27 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA27_IRQHandler)
{
    CddDma_Lld_IrqHandler(27U);
}

/*! @brief DMA Channel 28 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA28_IRQHandler)
{
    CddDma_Lld_IrqHandler(28U);
}

/*! @brief DMA Channel 29 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA29_IRQHandler)
{
    CddDma_Lld_IrqHandler(29U);
}

/*! @brief DMA Channel 30 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA30_IRQHandler)
{
    CddDma_Lld_IrqHandler(30U);
}

/*! @brief DMA Channel 31 IRQ handler with the same name in the startup code*/
CDDDMA_FUNC ISR(DMA31_IRQHandler)
{
    CddDma_Lld_IrqHandler(31U);
}
#endif /* (CDDDMA_MAX_CHANNEL_NUM > 16U) */

#define CDDDMA_STOP_SEC_CODE
#include "CddDma_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file CddDma_Irq.c */
