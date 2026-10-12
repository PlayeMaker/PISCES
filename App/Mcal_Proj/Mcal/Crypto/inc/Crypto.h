/**
 * @file    Crypto.h
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

#ifndef CRYPTO_H
#define CRYPTO_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Crypto_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section Crypto_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */


/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Crypto_Types.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_VENDOR_ID                      (180)
#define CRYPTO_AR_RELEASE_MAJOR_VERSION       (4)
#define CRYPTO_AR_RELEASE_MINOR_VERSION       (4)
#define CRYPTO_AR_RELEASE_REVISION_VERSION    (0)
#define CRYPTO_SW_MAJOR_VERSION               (0)
#define CRYPTO_SW_MINOR_VERSION               (9)
#define CRYPTO_SW_PATCH_VERSION               (1)


/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Crypto types defined header file are of the same vendor */
#if (CRYPTO_VENDOR_ID != CRYPTO_VENDOR_ID_TYPES)
#error "Crypto.h and Crypto_Types.h have different vendor ids"
#endif

/* Check if source file and Crypto types defined header file are of the same Autosar version */
#if ((CRYPTO_AR_RELEASE_MAJOR_VERSION != CRYPTO_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (CRYPTO_AR_RELEASE_MINOR_VERSION != CRYPTO_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (CRYPTO_AR_RELEASE_REVISION_VERSION != CRYPTO_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
#error "AutoSar Version Numbers of Crypto.h and Crypto_Cfg.h are different"
#endif

/* Check if source file and Crypto types defined header file are of the same software version */
#if ((CRYPTO_SW_MAJOR_VERSION != CRYPTO_SW_MAJOR_VERSION_TYPES) || \
     (CRYPTO_SW_MINOR_VERSION != CRYPTO_SW_MINOR_VERSION_TYPES) || \
     (CRYPTO_SW_PATCH_VERSION != CRYPTO_SW_PATCH_VERSION_TYPES) \
    )
#error "Software Version Numbers of Crypto.h and Crypto_Cfg.h are different"
#endif


/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief CRYPTO MODULE ID */
#define CRYPTO_MODULE_ID ((uint8)114U)

#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
/**
 * @defgroup        Crypto_DEV_ERROR
 * @brief           CRYPTO development errors
 * @{
 */
/**
* @brief API request called before initialization of Crypto Driver.
* @implements    CRYPTO_DET_ERRORS_define
* */

#define CRYPTO_E_UNINIT                     ((uint8)0x00U)
/**
* @brief Initiation of Crypto Driver failed.
* */
#define CRYPTO_E_INIT_FAILED                ((uint8)0x01U)

/**
* @brief API request called with invalid parameter (Nullpointer).
* */
#define CRYPTO_E_PARAM_POINTER              ((uint8)0x02U)

/**
* @brief API request called with invalid parameter (out of range).
* */
#define CRYPTO_E_PARAM_HANDLE               ((uint8)0x04U)

/**
* @brief API request called with invalid parameter (invalid value).
* */
#define CRYPTO_E_PARAM_VALUE                ((uint8)0x05U)

/* The service request failed because timeout occurred */
#define CRYPTO_E_OPERATION_TIMEOUT          ((Std_ReturnType)0x80U)
/**
* @brief The service request failed because it is not supported by the driver (Extension of Development Errors).
* */
#define CRYPTO_E_NOT_SUPPORTED              ((uint8)0x81)

/**
* @brief The service request failed because at least one parameter is invalid (Extension of Development Errors).
* */
#define CRYPTO_E_INVALID_PARAM              ((uint8)0x82)
/** @} */
#endif

/**
 * @defgroup        Crypto_SID
 * @brief           Service ID number for all CRYPTO driver services
 * @{
 */
/** @brief API Service ID for Crypto_CancelJob */
#define CRYPTO_SID_CANCEL_JOB                                (0x0eU)
/** @brief API Service ID for Crypto_CertificateParse */
#define CRYPTO_SID_CERTIFICATE_PARSE                         (0x0bU)
/** @brief API Service ID for Crypto_CertificateVerify */
#define CRYPTO_SID_CERTIFICATE_VERIFY                        (0x12U)
/** @brief API Service ID for Crypto_GetVersionInfo */
#define CRYPTO_SID_GET_VERSION_INFO                          (0x01U)
/** @brief API Service ID for Crypto_Init */
#define CRYPTO_SID_INIT                                      (0x00U)
/** @brief API Service ID for Crypto_KeyCopy */
#define CRYPTO_SID_KEY_COPY                                  (0x10U)
/** @brief API Service ID for Crypto_KeyDerive */
#define CRYPTO_SID_KEY_DERIVE                                (0x08U)
/** @brief API Service ID for Crypto_KeyElementCopy */
#define CRYPTO_SID_KEY_ELEMENT_COPY                          (0x0fU)
/** @brief API Service ID for Crypto_KeyElementCopyPartial */
#define CRYPTO_SID_KEY_ELEMENT_COPY_PARTIAL                  (0x13U)
/** @brief API Service ID for Crypto_KeyElementGet */
#define CRYPTO_SID_KEY_ELEMENT_GET                           (0x06U)
/** @brief API Service ID for Crypto_KeyElementIdsGet */
#define CRYPTO_SID_KEY_ELEMENT_IDS_GET                       (0x11U)
/** @brief API Service ID for Crypto_KeyElementSet */
#define CRYPTO_SID_KEY_ELEMENT_SET                           (0x04U)
/** @brief API Service ID for Crypto_KeyExchangeCalcPubVal */
#define CRYPTO_SID_KEY_EXCHANGE_CALC_PUB_VAL                 (0x09U)
/** @brief API Service ID for Crypto_KeyExchangeCalcSecret */
#define CRYPTO_SID_KEY_EXCHANGE_CALC_SECRET                  (0x0aU)
/** @brief API Service ID for Crypto_KeyGenerate */
#define CRYPTO_SID_KEY_GENERATE                              (0x07U)
/** @brief API Service ID for Crypto_KeySetValid */
#define CRYPTO_SID_KEY_SET_VALID                             (0x05U)

/** @brief API Service ID for Crypto_KeySetInValid */
#define CRYPTO_SID_KEY_SET_INVALID                            (0x15U)
/** @brief API Service ID for Crypto_MainFunction */
#define CRYPTO_SID_MAIN_FUNCTION                             (0x0cU)
/** @brief API Service ID for Crypto_ProcessJob */
#define CRYPTO_SID_PROCESS_JOB                               (0x03U)
/** @brief API Service ID for Crypto_RandomSeed */
#define CRYPTO_SID_RANDOM_SEED                               (0x0dU)
/** @} */
/*==================================================================================================
 *                                         EXTERNAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/**
 * @brief            This interface removes the provided job from the queue and cancels the processing of the job if possible.
 * @details
 * @param[in]        objectId Holds the identifier of the Crypto Driver Object.
 * @param[in]        job Pointer to the configuration of the job. Contains structures with job and primitive relevant information.
 * @return           Std_ReturnType
 */
Std_ReturnType Crypto_CancelJob(uint32 objectId, Crypto_JobInfoType *job);

/**
 * @brief            Parses the certificate data stored in the key element CRYPTO_KE_CERT_DATA and fills the key elements CRYPTO_KE_CERT_SIGNEDDATA, CRYPTO_KE_CERT_PARSEDPUBLICKEY and CRYPTO_KE_CERT_SIGNATURE.
 * @details
 * @param[in]        cryptoKeyId Holds the identifier of the key which shall be parsed.
 * @return           Std_ReturnType
 */
Std_ReturnType Crypto_CertificateParse(uint32 cryptoKeyId);

/**
 * @brief            Verifies the certificate stored in the key referenced by cryptoValidateKeyId with the certificate stored in the key referenced by cryptoKeyId.
 * @details
 * @param[in]        cryptoKeyId Holds the identifier of the key which shall be used to validate the certificate.
 * @param[in]        verifyCryptoKeyId Holds the identifier of the key contain
 * @param[out]       verifyPtr Holds a pointer to the memory location which will contain the result of the certificate verification.
 * @return           Std_ReturnType
 */
Std_ReturnType Crypto_CertificateVerify(uint32 cryptoKeyId, uint32 verifyCryptoKeyId, Crypto_VerifyResultType *verifyPtr);

/**
 * @brief            Initializes the Crypto Driver.
 * @details
 * @param[in]        configPtr Pointer to a selected configuration structure
 * @return           void
 */
void Crypto_Init(const Crypto_ConfigType *configPtr);

/**
 * @brief            Copies a key with all its elements to another key in the same crypto driver.
                Note:
                If the actual key element is directly mapped to flash memory, there could be a bigger delay when calling this function (synchronous operation)
 * @details
 * @param[in]        cryptoKeyId Holds the identifier of the key whose key element shall be the source element.
 * @param[in]        targetCryptoKeyId Holds the identifier of the key whose key element shall be the destination element.
 * @return           Std_ReturnType
 */
Std_ReturnType Crypto_KeyCopy(uint32 cryptoKeyId, uint32 targetCryptoKeyId);

/**
 * @brief            Derives a new key by using the key elements in the given key identified by the cryptoKeyId. The given key contains the key elements for the password, salt. The derived key is stored in the key element with the id 1 of the key identified by targetCryptoKeyId. The number of iterations is given in the key element CRYPTO_KE_KEYDERIVATION_ITERATIONS.
 * @details
 * @param[in]        cryptoKeyId Holds the identifier of the key which is used for key derivation.
 * @param[in]        targetCryptoKeyId Holds the identifier of the key which is used to store the derived key.
 * @return           Std_ReturnType
 */
Std_ReturnType Crypto_KeyDerive(uint32 cryptoKeyId, uint32 targetCryptoKeyId);

/**
 * @brief            Copies a key element to another key element in the same crypto driver.
                Note:
                If the actual key element is directly mapped to flash memory, there could be a bigger delay when calling this function (synchronous operation)
 * @details
 * @param[in]        cryptoKeyId Holds the identifier of the key whose key element shall be the source element.
 * @param[in]        keyElementId Holds the identifier of the key element which shall be the source for the copy operation.
 * @param[in]        targetCryptoKeyId Holds the identifier of the key whose key element shall be the destination element.
 * @param[in]        targetKeyElementId Holds the identifier of the key element which shall be the destination for the copy operation.
 * @return           Std_ReturnType
 */
Std_ReturnType Crypto_KeyElementCopy(uint32 cryptoKeyId, uint32 keyElementId, uint32 targetCryptoKeyId, uint32 targetKeyElementId);

/**
 * @brief            Copies a key element to another key element in the same crypto driver. The keyElementSourceOffset and keyElementCopyLength allows to copy just a part of the source key element into the destination. The offset of the target key is also specified with this function.
 * @details
 * @param[in]        cryptoKeyId Holds the identifier of the key whose key element shall be the source element.
 * @param[in]        keyElementId Holds the identifier of the key element which shall be the source for the copy operation.
 * @param[in]        keyElementSourceOffset is the offset of the of the source key element indicating the start index of the copy operation.
 * @param[in]        keyElementTargetOffset This is the offset of the of the target key element indicating the start index of the copy operation.
 * @param[in]        keyElementCopyLength Specifies the number of bytes that shall be copied.
 * @param[in]        targetCryptoKeyId Holds the identifier of the key whose key element shall be the destination element.
 * @param[in]        targetKeyElementId Holds the identifier of the key element which shall be the destination for the copy operation.
 * @return           Std_ReturnType
 */
Std_ReturnType Crypto_KeyElementCopyPartial(uint32 cryptoKeyId, uint32 keyElementId, uint32 keyElementSourceOffset, uint32 keyElementTargetOffset, uint32 keyElementCopyLength, uint32 targetCryptoKeyId, uint32 targetKeyElementId);

/**
 * @brief            This interface shall be used to get a key element of the key identified by the cryptoKeyId and store the key element in the memory location pointed by the result pointer.
                Note:
                If the actual key element is directly mapped to flash memory, there could be a bigger delay when calling this function (synchronous operation).
 * @details
 * @param[in]        cryptoKeyId Holds the identifier of the key whose key element shall be returned.
 * @param[in]        keyElementId Holds the identifier of the key element which shall be returned.
 * @param[out]       resultPtr Holds the pointer of the buffer for the returned key element
 * @param[inout]     resultLengthPtr Holds a pointer to a memory location in which the length information is stored. On calling this function this parameter shall contain the size of the buffer provided by resultPtr. If the key element is configured to allow partial access, this parameter contains the amount of data which should be read from the key element. The size may not be equal to the size of the provided buffer anymore. When the request has finished, the amount of data that has been stored shall be stored.
 * @return           Std_ReturnType
 */
Std_ReturnType Crypto_KeyElementGet(uint32 cryptoKeyId, uint32 keyElementId, uint8 *resultPtr, uint32 *resultLengthPtr);

/**
 * @brief            Used to retrieve information which key elements are available in a given key.
 * @details
 * @param[in]        cryptoKeyId Holds the identifier of the key whose available element ids shall be exported.
 * @param[out]       keyElementIdsPtr Contains the pointer to the array where the ids of the key elements shall be stored.
 * @param[in]        keyElementIdsLengthPtr Holds a pointer to the memory location in which the number of key elements in the given key is stored. On calling this function, this parameter shall contain the size of the buffer provided by keyElementIdsPtr. When the request has finished, the actual number of key elements shall be stored.
 * @return           Std_ReturnType
 */
Std_ReturnType Crypto_KeyElementIdsGet(uint32 cryptoKeyId, uint32 *keyElementIdsPtr, uint32 *keyElementIdsLengthPtr);

/**
 * @brief            Sets the given key element bytes to the key identified by cryptoKeyId.
 * @details
 * @param[in]        cryptoKeyId Holds the identifier of the key whose key element shall be set.
 * @param[in]        keyElementId Holds the identifier of the key element which shall be set.
 * @param[in]        keyPtr Holds the pointer to the key data which shall be set as key element.
 * @param[in]        keyLength Contains the length of the key element in bytes.
 * @return           Std_ReturnType
 */
Std_ReturnType Crypto_KeyElementSet(uint32 cryptoKeyId, uint32 keyElementId, const uint8 *keyPtr, uint32 keyLength);

/**
 * @brief            Calculates the public value for the key exchange and stores the public key in the memory location pointed by the public value pointer.
 * @details
 * @param[in]        cryptoKeyId Holds the identifier of the key which shall be used for the key exchange protocol.
 * @param[out]       publicValuePtr Contains the pointer to the data where the public value shall be stored.
 * @param[inout]     publicValueLengthPtr Holds a pointer to the memory location in which the public value length information is stored. On calling this function, this parameter shall contain the size of the buffer provided by publicValuePtr. When the request has finished, the actual length of the returned value shall be stored.
 * @return           Std_ReturnType
 */
Std_ReturnType Crypto_KeyExchangeCalcPubVal(uint32 cryptoKeyId, uint8 *publicValuePtr, uint32 *publicValueLengthPtr);

/**
 * @brief            Calculates the shared secret key for the key exchange with the key material of the key identified by the cryptoKeyId and the partner public key. The shared secret key is stored as a key element in the same key.
 * @details
 * @param[in]        cryptoKeyId Holds the identifier of the key which shall be used for the key exchange protocol.
 * @param[in]        partnerPublicValuePtr Holds the pointer to the memory location which contains the partner's public value.
 * @param[in]        partnerPublicValueLength Contains the length of the partner's public value in bytes.
 * @return           Std_ReturnType
 */
Std_ReturnType Crypto_KeyExchangeCalcSecret(uint32 cryptoKeyId, const uint8 *partnerPublicValuePtr, uint32 partnerPublicValueLength);

/**
 * @brief            Generates new key material store it in the key identified by cryptoKeyId.
 * @details
 * @param[in]        cryptoKeyId Holds the identifier of the key which is to be updated with the generated value.
 * @return           Std_ReturnType
 */
Std_ReturnType Crypto_KeyGenerate(uint32 cryptoKeyId);

/**
 * @brief            Sets the key state of the key identified by cryptoKeyId to valid.
 * @details
 * @param[in]        cryptoKeyId Holds the identifier of the key which shall be set to valid.
 * @return           Std_ReturnType
 */
Std_ReturnType Crypto_KeySetValid(uint32 cryptoKeyId);
/**
 * @brief            Sets the key state of the key identified by cryptoKeyId to Invalid.
 * @details
 * @param[in]        cryptoKeyId Holds the identifier of the key which shall be set to Invalid.
 * @return           Std_ReturnType
 */
Std_ReturnType Crypto_KeySetInValid(uint32 cryptoKeyId);
/**
 * @brief            If asynchronous job processing is configured and there are job queues, the function is called cyclically to process queued jobs.
 * @details
 * @return           void
 */
void Crypto_MainFunction(void);

/**
 * @brief            Performs the crypto primitive, that is configured in the job parameter.
 * @details
 * @param[in]        objectId Holds the identifier of the Crypto Driver Object.
 * @param[inout]     job Pointer to the configuration of the job. Contains structures with job and primitive relevant information but also pointer to result buffers.
 * @return           Std_ReturnType
 */
Std_ReturnType Crypto_ProcessJob(uint32 objectId, Crypto_JobType *job);

/**
 * @brief            This function generates the internal seed state using the provided entropy source. Furthermore, this function can be used to update the seed state with new entropy
 * @details
 * @param[in]        cryptoKeyId Holds the identifier of the key for which a new seed shall be generated.
 * @param[in]        seedPtr Holds a pointer to the memory location which contains the data to feed the seed.
 * @param[in]        seedLength Contains the length of the seed in bytes.
 * @return           Std_ReturnType
 */
Std_ReturnType Crypto_RandomSeed(uint32 cryptoKeyId, const uint8 *seedPtr, uint32 seedLength);

#if (CRYPTO_VERSION_INFO_API == STD_ON)
/**
 * @brief            Returns the version information of this module.
 * @details
 *
 * @param[out]       versioninfo Pointer to where to store version information of this module
 *
 * @return           void
 */
void Crypto_GetVersionInfo(Std_VersionInfoType *versioninfo);

#endif   /* CRYPTO_VERSION_INFO_API == STD_ON*/



#ifdef __cplusplus
}
#endif

#endif /* CRYPTO_H */

/** @} */

