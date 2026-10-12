/**
 * @file    Crypto_Lld_Trng.h
 *
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4 MCAL
 *   Platform             : ARM
 *   Peripheral           : Crypto TRNG
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


#ifndef CRYPTO_LLD_TRNG_H
#define CRYPTO_LLD_TRNG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "Crypto_Lld_Trng_Types.h"
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_LLD_TRNG_VENDOR_ID                                   (180)
#define CRYPTO_LLD_TRNG_AR_RELEASE_MAJOR_VERSION                    (4)
#define CRYPTO_LLD_TRNG_AR_RELEASE_MINOR_VERSION                    (4)
#define CRYPTO_LLD_TRNG_TYPES_AR_RELEASE_REVISION_VERSION           (0)
#define CRYPTO_LLD_TRNG_SW_MAJOR_VERSION                            (0)
#define CRYPTO_LLD_TRNG_SW_MINOR_VERSION                            (9)
#define CRYPTO_LLD_TRNG_SW_PATCH_VERSION                            (1)
/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/*Check the Crypto Lld Trng header file and  Crypto Lld Trng types defined header file are of the same vendor*/
#if (CRYPTO_LLD_TRNG_VENDOR_ID != CRYPTO_LLD_TRNG_TYPES_VENDOR_ID)
#error "Crypto_Lld_Trng.h and Crypto_Lld_Hcu_Types.h have different vendor ID"
#endif

/*Check the Crypto Lld Trng header file and  Crypto Lld Trng types defined header file are of the same AUTOSAR version*/
#if ((CRYPTO_LLD_TRNG_AR_RELEASE_MAJOR_VERSION != CRYPTO_LLD_TRNG_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_LLD_TRNG_AR_RELEASE_MINOR_VERSION != CRYPTO_LLD_TRNG_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_LLD_TRNG_AR_RELEASE_REVISION_VERSION != CRYPTO_LLD_TRNG_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Crypto_Lld_Trng.h and Crypto_Lld_Trng_Types.h are different"
#endif

/*Check the Crypto Lld Trng header file and  Crypto Lld Trng types defined header file are of the same software version */
#if ((CRYPTO_LLD_TRNG_SW_MAJOR_VERSION != CRYPTO_LLD_TRNG_TYPES_SW_MAJOR_VERSION) || \
     (CRYPTO_LLD_TRNG_SW_MINOR_VERSION != CRYPTO_LLD_TRNG_TYPES_SW_MINOR_VERSION) || \
     (CRYPTO_LLD_TRNG_SW_PATCH_VERSION != CRYPTO_LLD_TRNG_TYPES_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Crypto_Lld_Trng.h and Crypto_Lld_Trng_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/*TRNG*/
#define TRNG_INST              0
#define TRNG_ENTROPY_DELAY     0x0A00


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
/**
 * @brief   Initialize the TRNG module.
 *
 * @param[in] Instance     TRNG instance number.
 * @param[in] EntropyDelay Delay for entropy generation.
 * @return  void
 */
extern void Crypto_Lld_Trng_Init(uint32 Instance, uint32 EntropyDelay);

/**
 * @brief   Get random entropy from the TRNG module.
 *
 * @param[in] Instance     TRNG instance number.
 * @param[out] EntValuePtr Pointer to the buffer to store the entropy value.
 * @param[in] Length      Length of the entropy value to retrieve.
 * @return  void
 */
extern void Crypto_Lld_Trng_GetEnt(uint32 Instance, uint8 *EntValuePtr, uint32 Length);

/**
 * @brief   Get the status of the TRNG module.
 *
 * @param[in] Instance     TRNG instance number.
 * @return  Crypto_Lld_Trng_OptStatusType
 * @retval CRYPTO_TRNG_SUCCESS if entropy is valid.
 * @retval CRYPTO_TRNG_BUSY if generation is in progress.
 * @retval CRYPTO_TRNG_ERROR otherwise.
 */
extern Crypto_Lld_Trng_OptStatusType Crypto_Lld_Trng_GetStatus(uint32 Instance);



#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_IPW_H */


