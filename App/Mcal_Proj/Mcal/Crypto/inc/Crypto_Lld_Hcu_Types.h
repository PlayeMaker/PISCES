/**
 * @file    Crypto_Lld_Hcu_Types.h
 * @version
 *
 * @brief   AUTOSAR Crypto module interface
 * @details API implementation for CRYPTO driver
 *
 * @addtogroup CRYPTO_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4 MCAL
 *   Platform             : ARM
 *   Peripheral           : Crypto
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
/*==================================================================================================
==================================================================================================*/


#ifndef CRYPTO_LLD_HCU_TYPES_H
#define CRYPTO_LLD_HCU_TYPES_H

/**
*   @file
*
*   @internal
*   @addtogroup CRYPTO
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_LLD_HCU_TYPES_VENDOR_ID                      (180)
#define CRYPTO_LLD_HCU_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define CRYPTO_LLD_HCU_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define CRYPTO_LLD_HCU_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define CRYPTO_LLD_HCU_TYPES_SW_MAJOR_VERSION               (0)
#define CRYPTO_LLD_HCU_TYPES_SW_MINOR_VERSION               (9)
#define CRYPTO_LLD_HCU_TYPES_SW_PATCH_VERSION               (1)

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define HCU_KEY_NULL        HCU_NVR_ADDR

/*! @brief Macro used for checking buffer length */
#define HCU_BUFF_LEN_CHECK_MASK   0x10U

/*! @brief Macro used for checking buffer address */
#define HCU_BUFF_ADDR_CHECK_MASK   0x03U

/*! @brief Macro used to convert buffer length in bytes to number of 128-bits blocks */
#define HCU_BUFF_BLOCK_COUNT(x)   ((x) >> 4U)

/*! @brief Macro used for setting  */
#define HCU_AES_KeyLength_128bits    0x80U
/*! @brief Macro used for setting  */
#define HCU_AES_KeyLength_192bits    0xC0U
/*! @brief Macro used for setting  */
#define HCU_AES_KeyLength_256bits    0x100U
/*! @brief Macro used for setting SHA-256 block size */
#define HCU_SHA_256_BLOCK_SIZE    0x40U

/*! @brief Macro used for setting SHA-384 block size */
#define HCU_SHA_384_BLOCK_SIZE    0x80U

typedef enum
{
    MODE_SWAPPING_NO        = 0U,          /*!< No swapping */
    MODE_SWAPPING_HALFWORD  = 1U,          /*!< Half-word swapping */
    MODE_SWAPPING_BYTE      = 2U,          /*!< Byte swapping */
    MODE_SWAPPING_BIT       = 3U,          /*!< Bit swapping */
} Crypto_Lld_Hcu_SwappingType;
typedef enum
{
    HCU_USING_POLLING         = 0U,          /*!< Carry data by polling */
    HCU_USING_INTERRUPT       = 1U,          /*!< Carry data by interrupt */
    HCU_USING_DMA             = 2U,          /*!< Carry data by DMA */
} Crypto_Lld_Hcu_CarryType;
/*! @brief HCU engine selection */
typedef enum
{
    ENG_DISABLE = 0U,   /*!< HCU engine disable */
    ENG_AES = 1U,       /*!< HCU engine AES */
    ENG_SM4 = 2U,       /*!< HCU engine SM4 */
    ENG_SHA = 3U,        /*!< HCU engine SHA */
    ENG_PKE = 4U        /*!< HCU engine PKE */
} Crypto_Lld_Hcu_EngineType;
/*! @brief HCU algorithm selection */
typedef enum
{
    ALG_AES_ECB = 0U,
    ALG_AES_CBC = 1U,
    ALG_AES_CTR = 2U,
    ALG_AES_CCM = 3U,
    ALG_AES_CMAC = 4U,
    ALG_AES_GCM = 5U
} Crypto_Lld_Hcu_AesModeType;
typedef enum
{
    HCU_SHA_256 = 0x01U,       /*!< SHA 256 algorithm */
    HCU_SHA_384 = 0x02U        /*!< SHA 384 algorithm */
} Crypto_Lld_Hcu_ShaType;

/*! @brief HCU mode selection */
typedef enum
{
    MODE_ENC = 1U,          /*!< Encryption mode */
    MODE_DEC = 0U           /*!< Decryption mode */
} Crypto_Lld_Hcu_EngineModeType;
typedef enum
{
    KEY_SIZE_128_BITS = 0x00U, /*!< 128-bit key size */
    KEY_SIZE_192_BITS = 0x01U, /*!< 192-bit key size */
    KEY_SIZE_256_BITS = 0x02U, /*!< 256-bit key size */
} Crypto_Lld_Hcu_KeySizeType;
typedef enum
{
    MSG_START = 0x02U,       /*!< Start of a message block */
    MSG_END = 0x01U,        /*!< End of a message block */
    MSG_ALL = 0x03U,        /*!< All message in one block */
    MSG_MIDDLE = 0x00U,     /*!< Middle message block */
} Crypto_Lld_Hcu_MsgType;

/*! @brief HCU status flag */
typedef enum
{
    OPERATION_DONE_FLAG = 0U,
    AES_MAC_VALID_FLAG = 1U,
    SHA_HASH_INVALID_FLAG = 2U,
    OUTPUT_FIFO_EMPTY_FLAG = 8U,
    OUTPUT_FIFO_FULL_FLAG = 9U,
    INPUT_FIFO_EMPTY_FLAG = 10U,
    INPUT_FIFO_FULL_FLAG = 11U,
    OUTPUT_FIFO_OVERFLOW_FLAG = 12U,
    INPUT_FIFO_OVERFLOW_FLAG = 13U,
    OUTPUT_FIFO_WATERMARK_FLAG = 14U,
    INPUT_FIFO_WATERMARK_FLAG = 15U,
    SHA_CTX_READY_FLAG = 20U,
    SHA_CTX_WAIT_FLAG = 21U,
    SHA_ICV_WAIT_FLAG = 22U,
    AES_IV_READY_FLAG = 23U,
    AES_CV_READY_FLAG = 24U,
    AES_CV_WAIT_FLAG = 25U,
    AES_MAC_WAIT_FLAG = 26U,
    AES_MAC_READY_FLAG = 27U,
    AES_IV_WAIT_FLAG = 28U,
    KEY_WAIT_FLAG = 29U,
    OUTPUT_MESSAGE_READY_FLAG = 30U,
    INPUT_MESSAGE_WAIT_FLAG = 31U
} Crypto_Lld_Hcu_IntcFlagType;
/* Enumeration of the Run Status. */
typedef enum
{
    HCU_IDLE            = 0U,
    HCU_STARTING        = 1U,
    HCU_STARTED         = 2U,
    HCU_UPDATING        = 3U,
    HCU_UPDATEIDLE      = 4U,
    HCU_UPDATEFINISH    = 5U,
    HCU_FINISHING       = 6U,
    HCU_FILLDATA        = 7U,
    HCU_FINISHED        = 8U,
    HCU_BUSY            = 9U
} Crypto_Lld_Hcu_RunStatusType;

typedef enum
{
    HCU_ERRO_NOP        = 0x01U,   /*!< No operation error */
    HCU_ERRO_NODATA     = 0x02U,   /*!< No data error */
    HCU_ERRO_BUSY       = 0x03U,   /*!< Busy error */
    HCU_ERRO_FAIL       = 0x04U    /*!< Fail error */
} Crypto_Lld_Hcu_ErrorType;

typedef enum
{
    HCU_JOB_IDLE = 0U,       /*!< Job is idle */
    HCU_JOB_RUNNING = 1U,    /*!< Job is running */
    HCU_JOB_COMPLETED = 2U,  /*!< Job is completed */
    HCU_JOB_ERROR = 3U       /*!< Job is failed */

} Crypto_Lld_Hcu_JobStatusType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CRYPTO_TYPES_H */

