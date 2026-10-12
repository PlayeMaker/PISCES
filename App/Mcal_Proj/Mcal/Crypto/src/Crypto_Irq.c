/**
* @file    Crypto_Irq.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Crypto_Irq
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

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Crypto_Lld_Hcu.h"
#include "OsIf.h"
/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_IRQ_VENDOR_ID_C                          (180)
#define CRYPTO_IRQ_AR_RELEASE_MAJOR_VERSION_C              (4)
#define CRYPTO_IRQ_AR_RELEASE_MINOR_VERSION_C              (4)
#define CRYPTO_IRQ_AR_RELEASE_REVISION_VERSION_C           (0)
#define CRYPTO_IRQ_SW_MAJOR_VERSION_C                      (0)
#define CRYPTO_IRQ_SW_MINOR_VERSION_C                      (9)
#define CRYPTO_IRQ_SW_PATCH_VERSION_C                      (1)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CRYPTO_LLD_HCU header file are of the same vendor */
#if (CRYPTO_IRQ_VENDOR_ID_C != CRYPTO_LLD_HCU_VENDOR_ID)
#error "Crypto_Irq.c and Crypto_Lld_Hcu.h have different vendor ids"
#endif

/* Check if source file and CRYPTO_LLD_HCU header file are of the same Autosar version */
#if (( CRYPTO_IRQ_AR_RELEASE_MAJOR_VERSION_C != CRYPTO_LLD_HCU_AR_RELEASE_MAJOR_VERSION) || \
      ( CRYPTO_IRQ_AR_RELEASE_MINOR_VERSION_C != CRYPTO_LLD_HCU_AR_RELEASE_MINOR_VERSION) || \
      ( CRYPTO_IRQ_AR_RELEASE_REVISION_VERSION_C != CRYPTO_LLD_HCU_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Crypto_Irq.c and Crypto_Lld_Hcu.h are different"
#endif

/* Check if source file and CRYPTO_LLD_HCU header file are of the same Software version */
#if (( CRYPTO_IRQ_SW_MAJOR_VERSION_C != CRYPTO_LLD_HCU_SW_MAJOR_VERSION) || \
      ( CRYPTO_IRQ_SW_MINOR_VERSION_C != CRYPTO_LLD_HCU_SW_MINOR_VERSION) || \
      ( CRYPTO_IRQ_SW_PATCH_VERSION_C != CRYPTO_LLD_HCU_SW_PATCH_VERSION))
#error "Software Version Numbers of Crypto_Irq.c and Crypto_Lld_Hcu.h are different"
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
#if (CRYPTO_METHOD_POLLING != CRYPTO_ASYNJOB_METHOD_SUPPORT)
ISR(HCU_IRQHandler);

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
/**
 * @brief HCU interrupt service routine.
 *
 * @param void
 * @return None
 */
CRYPTO_FUNC ISR(HCU_IRQHandler)
{
    Crypto_Lld_HcuIntHandle();
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#endif /* (CRYPTO_METHOD_POLLING != CRYPTO_ASYNJOB_METHOD_SUPPORT) */

#ifdef __cplusplus
}
#endif

/* End of file Crypto_Irq.c */
