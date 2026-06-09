/**
 * @file    Wdg_Lld_Irq.c
 * @version V0.9.1
 *
 * @brief   YUNTU Wdg_Lld module interface
 * @details API implementation for Wdg_Lld driver
 *
 * @addtogroup WDG_LLD_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : WDG
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V0.9.1
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Wdg_Lld.h"
#include "OsIf.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_LLD_IRQ_VENDOR_ID_C                      (180)
#define WDG_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C       (4)
#define WDG_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C       (4)
#define WDG_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C    (0)
#define WDG_LLD_IRQ_SW_MAJOR_VERSION_C               (0)
#define WDG_LLD_IRQ_SW_MINOR_VERSION_C               (9)
#define WDG_LLD_IRQ_SW_PATCH_VERSION_C               (1)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Wdg_Lld_Irq.c and Wdg_Lld.h are of the same vendor */
#if (WDG_LLD_IRQ_VENDOR_ID_C != WDG_LLD_VENDOR_ID)
#error "Wdg_Lld_Irq.c and Wdg_Lld.h have different vendor ids"
#endif

/* Check if Wdg_Lld_Irq.c and Wdg_Lld.h are of the same Autosar version */
#if ((WDG_LLD_IRQ_AR_RELEASE_MAJOR_VERSION_C != WDG_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_LLD_IRQ_AR_RELEASE_MINOR_VERSION_C != WDG_LLD_AR_RELEASE_MINOR_VERSION) || \
     (WDG_LLD_IRQ_AR_RELEASE_REVISION_VERSION_C != WDG_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_Lld_Irq.c and Wdg_Lld.h are different"
#endif

/* Check if Wdg_Lld_Irq.c and Wdg_Lld.h are of the same software version */
#if ((WDG_LLD_IRQ_SW_MAJOR_VERSION_C != WDG_LLD_SW_MAJOR_VERSION) || \
     (WDG_LLD_IRQ_SW_MINOR_VERSION_C != WDG_LLD_SW_MINOR_VERSION) || \
     (WDG_LLD_IRQ_SW_PATCH_VERSION_C != WDG_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Lld_Irq.c and Wdg_Lld.h are different"
#endif

#if (WDG_180_INST0_ENABLE == STD_ON)

#if (WDG_180_INST0_RUN_ON_ROM == STD_ON)
#define WDG_180_INST0_START_SEC_CODE
#else
#define WDG_180_INST0_START_SEC_RAMCODE
#endif
#include "Wdg_180_Inst0_MemMap.h"

#if (WDG_180_INST0_ISR_USED == STD_ON)
/*==================================================================================================
 *                                   GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/
WDG_180_INST0_FUNC ISR(Wdg_Lld_Isr);

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief   WDG interrupt handler.
 * @details This function handles the WDG interrupt. The IRQ numbers of EWDG and WDG are the same.
 * @return  void
 */
WDG_180_INST0_FUNC ISR(Wdg_Lld_Isr)
{
    Wdg_Lld_IrqHandler(0U);
}
#endif /* #if (WDG_180_INST0_ISR_USED == STD_ON) */

#if (WDG_180_INST0_RUN_ON_ROM == STD_ON)
#define WDG_180_INST0_STOP_SEC_CODE
#else
#define WDG_180_INST0_STOP_SEC_RAMCODE
#endif
#include "Wdg_180_Inst0_MemMap.h"      /* NOSONAR, memory map */

#endif /* #if (WDG_180_INST0_ENABLE == STD_ON) */

#ifdef __cplusplus
}
#endif

/** @} */

