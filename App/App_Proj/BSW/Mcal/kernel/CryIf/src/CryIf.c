/**
 * @file    CryIf.c
 * @version 
 *
 * @brief   AUTOSAR CryIf module interface
 * @details API implementation for CRYIF driver
 *
 * @addtogroup CRYIF_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4 MCAL
 *   Platform             : ARM
 *   Peripheral           : CryIf
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

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Dio_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers. 
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 *
 * @section Dio_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers. 
 *          The used compilers/linkers allow more than 31 characters significance for external identifiers.
 */



/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "CryIf.h"
#include "CryIf_Cfg.h"

#if (CRYIF_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif /* CRYIF_DEV_ERROR_DETECT == STD_ON */

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYIF_VENDOR_ID_C                      (0xB4)
#define CRYIF_AR_RELEASE_MAJOR_VERSION_C       (4)
#define CRYIF_AR_RELEASE_MINOR_VERSION_C       (4)
#define CRYIF_AR_RELEASE_REVISION_VERSION_C    (0)
#define CRYIF_SW_MAJOR_VERSION_C               (0)
#define CRYIF_SW_MINOR_VERSION_C               (9)
#define CRYIF_SW_PATCH_VERSION_C               (1)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CRYIF header file are of the same vendor */
#if (CRYIF_VENDOR_ID_C != CRYIF_VENDOR_ID)
#error "CryIf.c and CryIf.h have different vendor ids"
#endif

/* Check if source file and CRYIF header file are of the same Autosar version */
#if ((CRYIF_AR_RELEASE_MAJOR_VERSION_C != CRYIF_AR_RELEASE_MAJOR_VERSION) || \
     (CRYIF_AR_RELEASE_MINOR_VERSION_C != CRYIF_AR_RELEASE_MINOR_VERSION) || \
     (CRYIF_AR_RELEASE_REVISION_VERSION_C != CRYIF_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of CryIf.c and CryIf.h are different"
#endif

/* Check if source file and CRYIF header file are of the same Software version */
#if ((CRYIF_SW_MAJOR_VERSION_C != CRYIF_SW_MAJOR_VERSION) || \
     (CRYIF_SW_MINOR_VERSION_C != CRYIF_SW_MINOR_VERSION) || \
     (CRYIF_SW_PATCH_VERSION_C != CRYIF_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of CryIf.c and CryIf.h are different"
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief            Notifies the CRYIF about the completion of the request with the result of the cryptographic operation.
 * @details          
 * @param[in]        Crypto_JobType Points to the completed job's information structure. It contains a callbackID to identify which job is finished.
 * @param[in]        Std_ReturnType Contains the result of the cryptographic operation.
 * @return           void
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x0d \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
void CryIf_CallbackNotification (Crypto_JobType * job, Std_ReturnType result)
{
     (void)job;
     (void)result;
}

/**
 * @brief            This interface dispatches the job cancellation function to the configured crypto driver object.
 * @details          
 * @param[in]        uint32 Holds the identifier of the crypto channel.
 * @param[inout]     Crypto_JobType Pointer to the configuration of the job. Contains structures with user and primitive relevant information.
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x0e \n
 *                   is_reentrant:     true \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType CryIf_CancelJob (uint32 channelId, Crypto_JobType * job)
{
        (void)channelId;
        (void)job;
        return E_OK;
}

/**
 * @brief            This function shall dispatch the certificate parse function to the configured crypto driver object.
 * @details          
 * @param[in]        uint32 Holds the identifier of the key which shall be parsed.
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x0c \n
 *                   is_reentrant:     true \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType CryIf_CertificateParse (uint32 cryIfKeyId)
{
        (void)cryIfKeyId;
        return E_OK;
}

/**
 * @brief            Verifies the certificate stored in the key referenced by verifyCryIfKeyId with the certificate stored in the key referenced by cryIfKeyId.
 * @details          
 * @param[in]        uint32 Holds the identifier of the key which shall be used to validate the certificate.
 * @param[in]        uint32 Holds the identifier of the key containing the certificate to be verified.
 * @param[out]       Crypto_VerifyResultType Holds a pointer to the memory location which will contain the result of the certificate verification.
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x11 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType CryIf_CertificateVerify (uint32 cryIfKeyId, uint32 verifyCryIfKeyId, Crypto_VerifyResultType * verifyPtr)
{
        (void)cryIfKeyId;
        (void)verifyCryIfKeyId;
        (void)verifyPtr;
        return E_OK;
}

/**
 * @brief            Returns the version information of this module.
 * @details          
 * @param[in]        Std_VersionInfoType Pointer to where to store the version information of this module.
 * @return           void
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x01 \n
 *                   is_reentrant:     true \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
void CryIf_GetVersionInfo (Std_VersionInfoType * versioninfo)
{
        (void)versioninfo;
}

/**
 * @brief            Initializes the CRYIF module.
 * @details          
 * @param[in]        CryIf_ConfigType Pointer to a selected configuration structure
 * @return           void
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x00 \n
 *                   is_reentrant:     true \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
void CryIf_Init (const CryIf_ConfigType * configPtr)
{
        (void)configPtr;
}

/**
 * @brief            This function shall copy all key elements from the source key to a target key.
 * @details          
 * @param[in]        uint32 Holds the identifier of the key whose key element shall be the source element.
 * @param[in]        uint32 Holds the identifier of the key whose key element shall be the destination element.
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x10 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType CryIf_KeyCopy (uint32 cryIfKeyId, uint32 targetCryIfKeyId)
{
        (void)cryIfKeyId;
        (void)targetCryIfKeyId;
        return E_OK;
}

/**
 * @brief            This function shall dispatch the key derive function to the configured crypto driver object.
 * @details          
 * @param[in]        uint32 Holds the identifier of the key which is used for key derivation.
 * @param[in]        uint32 Holds the identifier of the key which is used to store the derived key.
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x09 \n
 *                   is_reentrant:     true \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType CryIf_KeyDerive (uint32 cryIfKeyId, uint32 targetCryIfKeyId)
{
        (void)cryIfKeyId;
        (void)targetCryIfKeyId;
        return E_OK;
}

/**
 * @brief            This function shall copy a key elements from one key to a target key.
 * @details          
 * @param[in]        uint32 Holds the identifier of the key whose key element shall be the source element.
 * @param[in]        uint32 Holds the identifier of the key element which shall be the source for the copy operation.
 * @param[in]        uint32 Holds the identifier of the key whose key element shall be the destination element.
 * @param[in]        uint32 Holds the identifier of the key element which shall be the destination for the copy operation.
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x0f \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType CryIf_KeyElementCopy (uint32 cryIfKeyId, uint32 keyElementId, uint32 targetCryIfKeyId, uint32 targetKeyElementId)
{
        (void)cryIfKeyId;
        (void)keyElementId;
        (void)targetCryIfKeyId;
        (void)targetKeyElementId;
        return E_OK;
}

/**
 * @brief            Copies a key element to another key element. The keyElementOffsets and keyElementCopyLength allows to copy just parts of the source key element into the destination key element.
 * @details          
 * @param[in]        uint32 Holds the identifier of the key whose key element shall be the source element.
 * @param[in]        uint32 Holds the identifier of the key element which shall be the source for the copy operation.
 * @param[in]        uint32 This is the offset of the source key element indicating the start index of the copy operation.
 * @param[in]        uint32 This is the offset of the target key element indicating the start index of the copy operation.
 * @param[in]        uint32 Specifies the number of bytes that shall be copied.
 * @param[in]        uint32 Holds the identifier of the key whose key element shall be the destination element.
 * @param[in]        uint32 Holds the identifier of the key element which shall be the destination for the copy operation.
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x12 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType CryIf_KeyElementCopyPartial (uint32 cryIfKeyId, uint32 keyElementId, uint32 keyElementSourceOffset, uint32 keyElementTargetOffset, uint32 keyElementCopyLength, uint32 targetCryIfKeyId, uint32 targetKeyElementId)
{
        (void)cryIfKeyId;
        (void)keyElementId;
        (void)keyElementSourceOffset;
        (void)keyElementTargetOffset;
        (void)keyElementCopyLength;
        (void)targetCryIfKeyId;
        (void)targetKeyElementId;
        return E_OK;
}
/**
 * @brief            This function shall dispatch the get key element function to the configured crypto driver object.
 * @details          
 * @param[in]        uint32 Holds the identifier of the key whose key element shall be returned.
 * @param[in]        uint32 Holds the identifier of the key element which shall be returned.
 * @param[out]       uint8 Holds the pointer of the buffer for the returned key element
 * @param[inout]     uint32 Holds a pointer to a memory location in which the length information is stored. On calling this function this parameter shall contain the size of the buffer provided by resultPtr. If the key element is configured to allow partial access, this parameter contains the amount of data which should be read from the key element. The size may not be equal to the size of the provided buffer anymore. When the request has finished, the amount of data that has been stored shall be stored.
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x06 \n
 *                   is_reentrant:     true \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType CryIf_KeyElementGet (uint32 cryIfKeyId, uint32 keyElementId, uint8 * resultPtr, uint32 * resultLengthPtr)
{
        (void)cryIfKeyId;
        (void)keyElementId;
        (void)resultPtr;
        (void)resultLengthPtr;
        return E_OK;
}

/**
 * @brief            This function shall dispatch the set key element function to the configured crypto driver object.
 * @details          
 * @param[in]        uint32 Holds the identifier of the key whose key element shall be set.
 * @param[in]        uint32 Holds the identifier of the key element which shall be set.
 * @param[in]        uint8 Holds the pointer to the key data which shall be set as key element.
 * @param[in]        uint32 Contains the length of the key element in bytes.
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x04 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType CryIf_KeyElementSet (uint32 cryIfKeyId, uint32 keyElementId, const uint8 * keyPtr, uint32 keyLength)
{
        (void)cryIfKeyId;
        (void)keyElementId;
        (void)keyPtr;
        (void)keyLength;
        return E_OK;
}
/**
 * @brief            This function shall dispatch the key exchange public value calculation function to the configured crypto driver object.
 * @details          
 * @param[in]        uint32 Holds the identifier of the key which shall be used for the key exchange protocol.
 * @param[out]       uint8 Contains the pointer to the data where the public value shall be stored.
 * @param[inout]     uint32 Holds a pointer to the memory location in which the public value length information is stored. On calling this function, this parameter shall contain the size of the buffer provided by publicValuePtr. When the request has finished, the actual length of the returned value shall be stored.
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x0a \n
 *                   is_reentrant:     true \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType CryIf_KeyExchangeCalcPubVal (uint32 cryIfKeyId, uint8 * publicValuePtr, uint32 * publicValueLengthPtr)
{
        (void)cryIfKeyId;
        (void)publicValuePtr;
        (void)publicValueLengthPtr;
        return E_OK; 
}
/**
 * @brief            This function shall dispatch the key exchange common shared secret calculation function to the configured crypto driver object.
 * @details          
 * @param[in]        uint32 Holds the identifier of the key which shall be used for the key exchange protocol.
 * @param[in]        uint8 Holds the pointer to the memory location which contains the partner's public value.
 * @param[in]        uint32 Contains the length of the partner's public value in bytes.
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x0b \n
 *                   is_reentrant:     true \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType CryIf_KeyExchangeCalcSecret (uint32 cryIfKeyId, const uint8 * partnerPublicValuePtr, uint32 partnerPublicValueLength)
{
        (void)cryIfKeyId;
        (void)partnerPublicValuePtr;
        (void)partnerPublicValueLength;
        return E_OK;
}

/**
 * @brief            This function shall dispatch the key generate function to the configured crypto driver object.
 * @details          
 * @param[in]        uint32 Holds the identifier of the key which is to be updated with the generated value.
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x08 \n
 *                   is_reentrant:     true \n
 *                   is_synchronous:   false \n
 *                   autosar_api:      true \n
 */
Std_ReturnType CryIf_KeyGenerate (uint32 cryIfKeyId)
{
        (void)cryIfKeyId;
        return E_OK;
}

/**
 * @brief            This function shall dispatch the set key valid function to the configured crypto driver object.
 * @details          
 * @param[in]        uint32 Holds the identifier of the key whose key elements shall be set to valid.
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x05 \n
 *                   is_reentrant:     false \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
Std_ReturnType CryIf_KeySetValid (uint32 cryIfKeyId)
{
        (void)cryIfKeyId;
        return E_OK;
}

/**
 * @brief            This interface dispatches the received jobs to the configured crypto driver object.
 * @details          
 * @param[in]        uint32 Holds the identifier of the crypto channel.
 * @param[inout]     Crypto_JobType Pointer to the configuration of the job. Contains structures with user and primitive relevant information.
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x03 \n
 *                   is_reentrant:     true \n
 *                   is_synchronous:   false \n
 *                   autosar_api:      true \n
 */
Std_ReturnType CryIf_ProcessJob (uint32 channelId, Crypto_JobType * job)
{
        (void)channelId;
        (void)job;
        return E_OK;
}

/**
 * @brief            This function shall dispatch the random seed function to the configured crypto driver object.
 * @details          
 * @param[in]        uint32 Holds the identifier of the key for which a new seed shall be generated.
 * @param[in]        uint8 Holds a pointer to the memory location which contains the data to feed the seed.
 * @param[in]        uint32 Contains the length of the seed in bytes.
 * @return           Std_ReturnType
 * @retval           <return_value> {return_value description}
 * @note             service_id:       0x07 \n
 *                   is_reentrant:     true \n
 *                   is_synchronous:   false \n
 *                   autosar_api:      true \n
 */
Std_ReturnType CryIf_RandomSeed (uint32 cryIfKeyId, const uint8 * seedPtr, uint32 seedLength)
{
        (void)cryIfKeyId;
        (void)seedPtr;
        (void)seedLength;
        return E_OK;
}

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

