/*
* @file    Crypto_Mld.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Crypto_Mld
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V0.9.1
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef CRYPTO_MLD_H
#define CRYPTO_MLD_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "Crypto_Types.h"
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_MLD_VENDOR_ID                      (180)
#define CRYPTO_MLD_AR_RELEASE_MAJOR_VERSION              (4)
#define CRYPTO_MLD_AR_RELEASE_MINOR_VERSION              (4)
#define CRYPTO_MLD_AR_RELEASE_REVISION_VERSION           (0)
#define CRYPTO_MLD_SW_MAJOR_VERSION                  (0)
#define CRYPTO_MLD_SW_MINOR_VERSION                  (9)
#define CRYPTO_MLD_SW_PATCH_VERSION                  (1)
/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Crypto types defined header file are of the same vendor */
#if (CRYPTO_MLD_VENDOR_ID != CRYPTO_VENDOR_ID_TYPES)
#error "Crypto_Mld.h and Crypto_Types.h have different vendor ids"
#endif

/* Check if source file and Crypto types defined header file are of the same AUTOSAR version */
#if ((CRYPTO_MLD_AR_RELEASE_MAJOR_VERSION != CRYPTO_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (CRYPTO_MLD_AR_RELEASE_MINOR_VERSION != CRYPTO_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (CRYPTO_MLD_AR_RELEASE_REVISION_VERSION != CRYPTO_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
#error "AutoSar Version Numbers of Crypto_Mld.h and Crypto_Types.h are different"
#endif

/* Check if source file and Crypto types defined header file are of the same software version */
#if ((CRYPTO_MLD_SW_MAJOR_VERSION != CRYPTO_SW_MAJOR_VERSION_TYPES) || \
     (CRYPTO_MLD_SW_MINOR_VERSION != CRYPTO_SW_MINOR_VERSION_TYPES) || \
     (CRYPTO_MLD_SW_PATCH_VERSION != CRYPTO_SW_PATCH_VERSION_TYPES) \
    )
#error "Software Version Numbers of Crypto_Mld.h and Crypto_Types.h are different"
#endif

/*==================================================================================================
                                                DEFINES AND MACROS
==================================================================================================*/
/*==================================================================================================
                                                EXTERNAL CONSTANTS
==================================================================================================*/
extern Crypto_RunningDataType Crypto_RunningData;
/*==================================================================================================
                                                ENUMS
==================================================================================================*/
/*==================================================================================================
                                                FUNCTION PROTOTYPES
==================================================================================================*/
/**
 * @brief Initialize the Crypto module.
 *
 * @param[in] SwapCfg The swapping configuration
 * @return None
 */
extern void Crypto_Mld_Init(Crypto_Lld_Hcu_SwappingType SwapCfg);

/**
 * @brief This function starts a new HCU job according to the specified operation type.
 *
 * @param[in] CallType The type of the operation to perform
 * @return uint8
 */
extern uint8 Crypto_Mld_HcuStart(Crypto_OperationType CallType);

/**
 * @brief This function updates the status or data of an ongoing HCU job
 * according to the specified operation type.
 *
 * @param[in] CallType The type of the operation to perform
 * @return uint8
 */
extern uint8 Crypto_Mld_HcuUpdate(Crypto_OperationType CallType);

/**
 * @brief This function completes the current HCU job according to the specified operation type.
 *
 * @param[in] CallType The type of the operation to perform
 * @return uint8
 */
extern uint8 Crypto_Mld_HcuFinish(Crypto_OperationType CallType);

/**
 * @brief This function synchronously processes a HCU job.
 *
 * @param[in] CallType The type of the operation to perform
 * @return uint8
 */
extern uint8 Crypto_Mld_HcuSyncSingleCall(Crypto_OperationType CallType);

/**
 * @brief   This function processes an asynchronous single job for the HCU.
 *
 * @param[in]   CallType   The type of the operation to perform
 * @return  uint8
 */
extern uint8 Crypto_Mld_HcuAsyncSingleCall(Crypto_OperationType CallType);

/**
 * @brief   This function processes a random job.
 *
 * @param[in]   Length     Length of the random data to generate
 * @param[out]  OutputPtr  Pointer to the buffer where the generated random data will be stored
 * @return  Std_ReturnType
 * @retval  E_OK          The random generation was successful.
 * @retval  E_NOT_OK      The random generation failed.
 */
extern Std_ReturnType Crypto_Mld_ProcessJobRandom(uint32 Length, uint8 *OutputPtr);


#ifdef __cplusplus
}
#endif

#endif /* End of file Crypto_Mld.h */

