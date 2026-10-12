/**
 * @file    Crypto_Lld_Trng_Types.h
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
#ifndef CRYPTO_LLD_TRNG_ITYPES_H
#define CRYPTO_LLD_TRNG_ITYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
*                                 HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_LLD_TRNG_TYPES_VENDOR_ID                       (180)
#define CRYPTO_LLD_TRNG_TYPES_AR_RELEASE_MAJOR_VERSION              (4)
#define CRYPTO_LLD_TRNG_TYPES_AR_RELEASE_MINOR_VERSION              (4)
#define CRYPTO_LLD_TRNG_TYPES_AR_RELEASE_REVISION_VERSION           (0)
#define CRYPTO_LLD_TRNG_TYPES_SW_MAJOR_VERSION                  (0)
#define CRYPTO_LLD_TRNG_TYPES_SW_MINOR_VERSION                  (9)
#define CRYPTO_LLD_TRNG_TYPES_SW_PATCH_VERSION                  (1)
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/*!
 * @brief TRNG status flags.
 */
typedef enum
{
    TRNG_FREQUENCY_COUNT_VALID              = 0x1,      /*!< Frequency Count Valid. */
    TRNG_BUSY                               = 0x5,      /*!< IDLE flag. */
    TRNG_HARDWARE_ERROR                     = 0x6,      /*!< Hardware Error Interrupt Flag */
    TRNG_ENTROPY_VALID                      = 0x9,      /*!< Entropy Valid Interrupt Flag. */
    TRNG_FREQUENCY_COUNT_FAIL               = 0x0A,     /*!< Frequency Count Fail Interrupt Flag*/
    TRNG_ALL_STATUS                         = 0x722,    /*!< Used for clearing all trng status flags */
} Crypto_Lld_Trng_StatusFlagType;

/*!
 * @brief Prescaler values for TRNG OSC clock source.
 */
typedef enum
{
    TRNG_OSC_NO_DEVIDER = 0,            /*!< No devider.*/
    TRNG_OSC_DIV_2 = 1,                 /*!< Ring OSC divided by 2.*/
    TRNG_OSC_DIV_4 = 2,                 /*!< Ring OSC divided by 4.*/
    TRNG_OSC_DIV_8 = 3,                 /*!< Ring OSC divided by 8.*/
} Crypto_Lld_Trng_OscDivType;

/*!
 * @brief Data structure containing information about a trng.
 *
 * The user must populate these members to set up the trng.
 * Implements : Crypto_Lld_Trng_ConfigType_Class
 */
typedef struct
{
    uint32          RunMax;   /*!< the largest allowable number of consecutive samples of all 1 or all 0 during the entropy generation.*/
    uint8           RetryCnt;           /*!< indecates the number of times a retry should occur before generating an error. */
    boolean         ForceSystemClockEn;      /*!< the system clock is used to operate the TRNG instead of the ring OSC.*/
    boolean         ClkOutputEn;             /*!< After divided by 4, trng_osc_clk is output for test.*/
    Crypto_Lld_Trng_OscDivType  OSCDiv;     /*!< OSC Divider*/
    boolean         FrqCntInterruptEn;     /*!< Frequency Count Fail Interrupt Enable*/
    boolean         EntroptValidInterruptEn; /*!< Entropy Valid Interrupt Enable*/
    boolean         HwErrInterruptEn;      /*!< Hardware Error Interrupt Enable*/

    uint32           SampleSize;        /*!< Defines the total number of entropy samples */
    uint32           EntropyDelay;      /*!< Entropy delay*/

    uint32            FrqMin;            /*!< Frequency minimum limit value*/
    uint32            FrqMax;            /*!< Frequency Maximum Limit Value*/

    uint32            MonobitRange;      /*!< Monobit Range*/
    uint32            MonobitMax;        /*!< Monobit Maximum Limit*/
    uint32            *EntValuePtr;        /*!< the pointer for reading entropy Value*/
} Crypto_Lld_Trng_ConfigType;

/**
 * @brief Status codes for TRNG operations.
 */
typedef enum
{
    CRYPTO_TRNG_SUCCESS                         = 0x000U,    /*!< Random generate success status */
    CRYPTO_TRNG_ERROR                           = 0x001U,    /*!< Random generate failure status */
    CRYPTO_TRNG_BUSY                            = 0x002U,    /*!< Random generate busy status */
} Crypto_Lld_Trng_OptStatusType;
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

#endif /* CRYPTO_TYPES_H */

