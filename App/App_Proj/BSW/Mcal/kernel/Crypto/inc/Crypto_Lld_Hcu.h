/*
* @file    Crypto_Lld_Hcu.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Crypto_Lld_Hcu
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V0.9.1
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef CRYPTO_LLD_HCU_H
#define CRYPTO_LLD_HCU_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Crypto_Lld_Hcu_Types.h"
#include "Crypto_Types.h"

/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_LLD_HCU_VENDOR_ID                              (180)
#define CRYPTO_LLD_HCU_AR_RELEASE_MAJOR_VERSION              (4)
#define CRYPTO_LLD_HCU_AR_RELEASE_MINOR_VERSION              (4)
#define CRYPTO_LLD_HCU_AR_RELEASE_REVISION_VERSION           (0)
#define CRYPTO_LLD_HCU_SW_MAJOR_VERSION                      (0)
#define CRYPTO_LLD_HCU_SW_MINOR_VERSION                      (9)
#define CRYPTO_LLD_HCU_SW_PATCH_VERSION                      (1)
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Crypto_Lld_Hcu.h file and Crypto_Lld_Hcu_Types.h file are of the same vendor */
#if (CRYPTO_LLD_HCU_VENDOR_ID != CRYPTO_LLD_HCU_TYPES_VENDOR_ID)
#error "Crypto_Lld_Hcu.h and Crypto_Lld_Hcu_Types.h have different vendor ids"
#endif

/* Check if Crypto_Lld_Hcu.h file and Crypto_Lld_Hcu_Types.h file are of the same AUTOSAR version */
#if (CRYPTO_LLD_HCU_AR_RELEASE_MAJOR_VERSION != CRYPTO_LLD_HCU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
    (CRYPTO_LLD_HCU_AR_RELEASE_MINOR_VERSION != CRYPTO_LLD_HCU_TYPES_AR_RELEASE_MINOR_VERSION) || \
    (CRYPTO_LLD_HCU_AR_RELEASE_REVISION_VERSION != CRYPTO_LLD_HCU_TYPES_AR_RELEASE_REVISION_VERSION)
#error "Version mismatch between Crypto_Lld_Hcu.h and Crypto_Lld_Hcu_Types.h"
#endif

/* Check if Crypto_Lld_Hcu.h file and Crypto_Lld_Hcu_Types.h file are of the same software version */
#if (CRYPTO_LLD_HCU_SW_MAJOR_VERSION != CRYPTO_LLD_HCU_TYPES_SW_MAJOR_VERSION) || \
    (CRYPTO_LLD_HCU_SW_MINOR_VERSION != CRYPTO_LLD_HCU_TYPES_SW_MINOR_VERSION) || \
    (CRYPTO_LLD_HCU_SW_PATCH_VERSION != CRYPTO_LLD_HCU_TYPES_SW_PATCH_VERSION)
#error "Version mismatch between Crypto_Lld_Hcu.h and Crypto_Types.h"
#endif

/*==================================================================================================
                                                DEFINES AND MACROS
==================================================================================================*/
#define HCU_MAXSIZE_WRITEONCE           (0x7C00U)

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
 * @brief This function initializes the HCU with the specified configuration.
 *
 * @param[in] Cfg The data swapping configuration to be set.
 * @return None
 */
extern void Crypto_Lld_HcuInit(Crypto_Lld_Hcu_SwappingType Cfg);

/**
 * @brief  This function loads input data into the HCU for cryptographic processing.
 *
 * @param[in] DataProcessType  The type of processing (synchronous or asynchronous).
 * @param[in] MsgIndexType     The message index type (e.g., start, middle, end).
 * @return uint8
 */
extern uint8 Crypto_Lld_HcuSetInputData(Crypto_ProcessingType DataProcessType, Crypto_Lld_Hcu_MsgType MsgIndexType);

/**
 * @brief This function configures the HCU with the length of input data to be processed,
 * based on the message type and operation type.
 *
 * @param[in] MsgType   The message index type (e.g., start, middle, end).
 * @param[in] CallType  The type of cryptographic operation (e.g., single, stream, multi).
 * @return uint8
 */
extern uint8 Crypto_Lld_HcuSetInputDataLength(Crypto_Lld_Hcu_MsgType MsgType, Crypto_OperationType CallType);

#if defined (HCU_SUPPORT_TOTAL_MSG_LENGTH_SET)
/**
 * @brief This function sets the total message length for the HCU.
 *
 * @param[in] MsgTotalLen The total message length to be set.
 * @return None
 */
extern void Crypto_Lld_HcuSetMsgTotalLength(uint32 MsgTotalLen);
#endif

/**
 * @brief  This function sets up the Hardware Crypto Unit (HCU) for a new operation by configuring the engine,
 * algorithm, encryption mode, and total message length. It also initializes FIFO watermarks, key, and MAC length
 * as needed for the selected operation type.
 *
 * @param[in] CallType     The type of cryptographic operation to perform (e.g., single, stream, multi).
 * @param[in] Engine       The HCU engine to use (e.g., AES, SHA).
 * @param[in] Algorithm    The cryptographic algorithm to use.
 * @param[in] Encrypt      The job mode for engine (encryption or decryption).
 * @param[in] MsgTotalLen  The total length of the message to be processed.
 * @return None
 */
extern void Crypto_Lld_HcuStartPrepare(Crypto_OperationType CallType,
                                       Crypto_Lld_Hcu_EngineType Engine,
                                       Crypto_Lld_Hcu_AesModeType Algorithm,
                                       Crypto_Lld_Hcu_EngineModeType Encrypt,
                                       uint32 MsgTotalLen);

#if(CRYPTO_METHOD_POLLING != CRYPTO_ASYNJOB_METHOD_SUPPORT)
/**
 * @brief  This function handles interrupexternts for the HCU, checking the status of various flags and taking appropriate action.
 *
 * @param void
 * @return None
 */
extern void Crypto_Lld_HcuIntHandle(void);
#endif /* (CRYPTO_METHOD_POLLING != CRYPTO_ASYNJOB_METHOD_SUPPORT) */

#ifdef __cplusplus
}
#endif

#endif /* End of file Crypto_Lld_Hcu.h */

