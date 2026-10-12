/**
 * @file    Crypto.c
 *
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

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @page misra_violations MISRA-C:2012 violations list
 *
 * PRQA S 3673 Rule-8.13: The object addressed by the pointer parameter '%1s' is not modified and so the pointer could be of type 'pointer to const'.
 * PRQA S 4322 Rule-10.5 An expression of 'essentially enum' type (%1s) is being cast to a different enum type, '%2s'.
 * PRQA S 2812 Rule-10.4 Apparent: Dereference of NULL pointer.
*/
/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Crypto.h"
#include "Crypto_Mld.h"
#include "Crypto_Cfg.h"
#include "CryIf.h"
#ifdef CRYPTO_ENABLE_USER_MODE_SUPPORT
#include "OsIf.h"
#endif
#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* CRYPTO_DEV_ERROR_DETECT == STD_ON */
/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_VENDOR_ID_C                          (180)
#define CRYPTO_AR_RELEASE_MAJOR_VERSION_C              (4)
#define CRYPTO_AR_RELEASE_MINOR_VERSION_C              (4)
#define CRYPTO_AR_RELEASE_REVISION_VERSION_C           (0)
#define CRYPTO_SW_MAJOR_VERSION_C                      (0)
#define CRYPTO_SW_MINOR_VERSION_C                      (9)
#define CRYPTO_SW_PATCH_VERSION_C                      (1)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CRYPTO header file are of the same vendor */
#if (CRYPTO_VENDOR_ID_C != CRYPTO_VENDOR_ID)
#error "Crypto.c and Crypto.h have different vendor ids"
#endif

/* Check if source file and CRYPTO header file are of the same Autosar version */
#if (( CRYPTO_AR_RELEASE_MAJOR_VERSION_C != CRYPTO_AR_RELEASE_MAJOR_VERSION) || \
      ( CRYPTO_AR_RELEASE_MINOR_VERSION_C != CRYPTO_AR_RELEASE_MINOR_VERSION) || \
      ( CRYPTO_AR_RELEASE_REVISION_VERSION_C != CRYPTO_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Crypto.c and Crypto.h are different"
#endif

/* Check if source file and CRYPTO header file are of the same Software version */
#if (( CRYPTO_SW_MAJOR_VERSION_C != CRYPTO_SW_MAJOR_VERSION) || \
      ( CRYPTO_SW_MINOR_VERSION_C != CRYPTO_SW_MINOR_VERSION) || \
      ( CRYPTO_SW_PATCH_VERSION_C != CRYPTO_SW_PATCH_VERSION))
#error "Software Version Numbers of Crypto.c and Crypto.h are different"
#endif

/* Check if source file and Crypto_Mld.h file are of the same vendor */
#if (CRYPTO_VENDOR_ID_C != CRYPTO_MLD_VENDOR_ID)
#error "Crypto.c and Crypto_Mld.h have different vendor ids"
#endif

/* Check if source file and Crypto_Mld.h file are of the same AUTOSAR version */
#if ((CRYPTO_AR_RELEASE_MAJOR_VERSION_C != CRYPTO_MLD_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_AR_RELEASE_MINOR_VERSION_C != CRYPTO_MLD_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_AR_RELEASE_REVISION_VERSION_C != CRYPTO_MLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Crypto.c and Crypto_Mld.h are different"
#endif

/* Check if source file and Crypto_Mld.h file are of the same software version */
#if ((CRYPTO_SW_MAJOR_VERSION_C != CRYPTO_MLD_SW_MAJOR_VERSION) || \
     (CRYPTO_SW_MINOR_VERSION_C != CRYPTO_MLD_SW_MINOR_VERSION) || \
     (CRYPTO_SW_PATCH_VERSION_C != CRYPTO_MLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Crypto.c and Crypto_Mld.h are different"
#endif
/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/
#define LENGTH_OF_SHA384               (48U)
#define LENGTH_OF_SHA256               (32U)
#define MINLENGTH_OF_RANDOM            (4U)
#define MAXBITS_OF_KEY                 (256U)
#define MINBYTES_OF_INPUT              (16U)
#define CRYPTO_MAXSIZE_WRITEONCE           (0x7C00U)
/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#define CRYPTO_HW_RESOURCE_NUM   (2U)
/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/
/* Pre-compile configuration structure for Crypto */
extern const Crypto_ConfigType Crypto_PreCompileConfig;
/* Array storing keys*/
extern const Crypto_KeyType Crypto_KeyList[CRYPTO_DRIVER_KEYID_MAX];

/* Array storing keyelements*/
extern const Crypto_KeyElementType Crypto_KeyElementList[CRYPTO_DRIVER_KEYELEMENT_MAX];

/* Array storing the information about Crypto Driver Objects*/
extern  const Crypto_ObjectType  Crypto_ObjectsList[CRYPTO_DRIVER_OBJECT_MAX];
/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/
#define CRYPTO_START_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"
CRYPTO_VAR static Crypto_DriverStateType Crypto_DriverState = CRYPTO_DRIVER_UNINIT;
/* Array storing the information about Crypto Driver Objects*/
CRYPTO_VAR static Crypto_InstanceType volatile Crypto_Instance[CRYPTO_HW_RESOURCE_NUM] =
{
    {
        /*Crypto instance id */
        0,
        /* Crypto Current Job  */
        NULL_PTR,
    },
    {
        /*Crypto instance id */
        1,
        /* Crypto Current Job  */
        NULL_PTR,
    },
};
#define CRYPTO_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"
/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
/*
*  MR12 Rule-8.3 VIOLATION: In this module,Hardware do not support Canceling job. "* job" the parameter of function is not be used,it will violate this rule.
*but,it is safe
*/
/**
 * @brief            This function cancels the job identified by the parameter job.
 * @param[in]        objectId  The Crypto Driver Object ID.
 * @param[in]        job  Pointer to the job to be cancelled.
 * @return           Std_ReturnType
 * @retval           E_OK               The job has been successfully cancelled.
 * @retval           E_NOT_OK          The job could not be cancelled.
 */
CRYPTO_FUNC Std_ReturnType Crypto_CancelJob(uint32 objectId,  Crypto_JobInfoType *job)   /* PRQA S 3673 */
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
#if (STD_ON == CRYPTO_DEV_ERROR_DETECT)
    if (objectId >= CRYPTO_DRIVER_OBJECT_MAX)
    {
        /* If the objectId out of range and if development error detection for the Crypto Driver is enabled,
           the function Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK. */
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_CANCEL_JOB, CRYPTO_E_PARAM_HANDLE);
        RetVal         = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == job)
    {
        /* If the parameter job is a null pointer and if development error detection for the Crypto Driver is enabled,
           the function Crypto_ProcessJob shall report CRYPTO_E_PARAM_POINTER to the DET and return E_NOT_OK. */
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_CANCEL_JOB, CRYPTO_E_PARAM_POINTER);
        RetVal         = (Std_ReturnType)E_NOT_OK;
    }
    else if (CRYPTO_DRIVER_UNINIT == Crypto_DriverState)
    {
        /* return E_NOT_OK if the module is not yet initialized*/
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_CANCEL_JOB, CRYPTO_E_UNINIT);
        RetVal         = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif /* (STD_ON == CRYPTO_DEV_ERROR_DETECT) */
    {
        /*Crypto driver don't support queue now, so if the job is ongoning, it can't be cancelled.*/
        RetVal         = (Std_ReturnType)E_OK;
        for (uint8 LoopCnt = 0; LoopCnt < CRYPTO_HW_RESOURCE_NUM; ++LoopCnt)
        {
            if ((Crypto_Instance[LoopCnt].CryptoCurrentJob != NULL_PTR) && \
                    (job->jobId == Crypto_Instance[LoopCnt].CryptoCurrentJob->jobId))
            {
                /*more*/
                RetVal = CRYPTO_E_JOB_CANCELED;
            }
        }
    }
    return RetVal;
}
CRYPTO_FUNC Std_ReturnType Crypto_CertificateParse(uint32 cryptoKeyId)
{
    /*Avoid compiler warnings*/
    (void)cryptoKeyId;
#if (STD_ON == CRYPTO_DEV_ERROR_DETECT)
    (void) Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_CERTIFICATE_PARSE, CRYPTO_E_NOT_SUPPORTED);
#endif /* (STD_ON == CRYPTO_DEV_ERROR_DETECT) */
    return E_NOT_OK;
}
/*
*  MR12 Rule-8.3 VIOLATION: The API do not support. verifyPtr is pointer,it will violate this rule.
*but,it is safe
*/
CRYPTO_FUNC Std_ReturnType Crypto_CertificateVerify(uint32 cryptoKeyId, uint32 verifyCryptoKeyId, Crypto_VerifyResultType *verifyPtr)  /* PRQA S 3673 */
{
    /*Avoid compiler warnings*/
    (void)cryptoKeyId;
    (void)verifyCryptoKeyId;
    (void)verifyPtr;
#if (STD_ON == CRYPTO_DEV_ERROR_DETECT)
    (void) Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_CERTIFICATE_VERIFY, CRYPTO_E_NOT_SUPPORTED);
#endif /* (STD_ON == CRYPTO_DEV_ERROR_DETECT) */
    return E_NOT_OK;
}

#if (STD_ON == CRYPTO_VERSION_INFO_API)
/**
 * @brief            Returns the version information of the Crypto Driver.
 * @param[out]       versioninfo  Pointer to the structure to hold version information.
 * @return           None
 */
CRYPTO_FUNC void Crypto_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (STD_ON == CRYPTO_DEV_ERROR_DETECT)
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_GET_VERSION_INFO, CRYPTO_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == CRYPTO_DEV_ERROR_DETECT */
    {
        versioninfo->moduleID           = (uint16)CRYPTO_MODULE_ID;
        versioninfo->vendorID           = (uint16)CRYPTO_VENDOR_ID;
        versioninfo->sw_major_version   = (uint8)CRYPTO_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version   = (uint8)CRYPTO_SW_MINOR_VERSION;
        versioninfo->sw_patch_version   = (uint8)CRYPTO_SW_PATCH_VERSION;
    }
}
#endif /* (STD_ON == CRYPTO_VERSION_INFO_API) */

CRYPTO_FUNC void Crypto_Init(const Crypto_ConfigType *configPtr)
{
    (void)configPtr;
    const Crypto_ConfigType *CryptoConfig = &Crypto_PreCompileConfig;
    if (CRYPTO_DRIVER_UNINIT == Crypto_DriverState)
    {
#ifdef CRYPTO_ENABLE_USER_MODE_SUPPORT
        OsIf_Trusted_Call1param(Crypto_Mld_Init, CryptoConfig->Swap);
#else
        Crypto_Mld_Init(CryptoConfig->Swap);/*Swap byte*/
#endif
        Crypto_DriverState = CRYPTO_DRIVER_INITIALIZED;
    }
}
CRYPTO_FUNC Std_ReturnType Crypto_KeyCopy(uint32 cryptoKeyId, uint32 targetCryptoKeyId)
{
    /*Avoid compiler warnings*/
    (void)cryptoKeyId;
    (void)targetCryptoKeyId;
#if (STD_ON == CRYPTO_DEV_ERROR_DETECT)
    (void) Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_KEY_COPY, CRYPTO_E_NOT_SUPPORTED);
#endif /* (STD_ON == CRYPTO_DEV_ERROR_DETECT) */
    return E_NOT_OK;
}
CRYPTO_FUNC Std_ReturnType Crypto_KeyDerive(uint32 cryptoKeyId, uint32 targetCryptoKeyId)
{
    /*Avoid compiler warnings*/
    (void)cryptoKeyId;
    (void)targetCryptoKeyId;
#if (STD_ON == CRYPTO_DEV_ERROR_DETECT)
    (void) Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_KEY_DERIVE, CRYPTO_E_NOT_SUPPORTED);
#endif /* (STD_ON == CRYPTO_DEV_ERROR_DETECT) */
    return E_NOT_OK;
}

/**
 */
CRYPTO_FUNC Std_ReturnType Crypto_KeyElementCopy(uint32 cryptoKeyId, uint32 keyElementId, uint32 targetCryptoKeyId, uint32 targetKeyElementId)
{
    /*Avoid compiler warnings*/
    (void)cryptoKeyId;
    (void)keyElementId;
    (void)targetCryptoKeyId;
    (void)targetKeyElementId;
#if (STD_ON == CRYPTO_DEV_ERROR_DETECT)
    (void) Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_KEY_ELEMENT_COPY, CRYPTO_E_NOT_SUPPORTED);
#endif /* (STD_ON == CRYPTO_DEV_ERROR_DETECT) */
    return E_NOT_OK;
}
CRYPTO_FUNC Std_ReturnType Crypto_KeyElementCopyPartial(uint32 cryptoKeyId, uint32 keyElementId, uint32 keyElementSourceOffset, uint32 keyElementTargetOffset, uint32 keyElementCopyLength, uint32 targetCryptoKeyId, uint32 targetKeyElementId)
{
    /*Avoid compiler warnings*/
    (void)cryptoKeyId;
    (void)keyElementId;
    (void)keyElementSourceOffset;
    (void)keyElementTargetOffset;
    (void)keyElementCopyLength;
    (void)targetCryptoKeyId;
    (void)targetKeyElementId;
#if (STD_ON == CRYPTO_DEV_ERROR_DETECT)
    (void) Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_KEY_ELEMENT_COPY_PARTIAL, CRYPTO_E_NOT_SUPPORTED);
#endif /* (STD_ON == CRYPTO_DEV_ERROR_DETECT) */
    return E_NOT_OK;
}
/*
*  MR12 Rule-8.3 VIOLATION: The API do not support. "resultPtr" and "resultLengthPtr" is pointer,it will violate this rule.
*  but,it is safe
*/
CRYPTO_FUNC Std_ReturnType Crypto_KeyElementGet(uint32 cryptoKeyId, uint32 keyElementId, uint8 *resultPtr, uint32 *resultLengthPtr)   /* PRQA S 3673 */
{
    /*Avoid compiler warnings*/
    (void)cryptoKeyId;
    (void)keyElementId;
    (void)resultPtr;
    (void)resultLengthPtr;
#if (STD_ON == CRYPTO_DEV_ERROR_DETECT)
    (void) Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_KEY_ELEMENT_GET, CRYPTO_E_NOT_SUPPORTED);
#endif /* (STD_ON == CRYPTO_DEV_ERROR_DETECT) */
    return E_NOT_OK;
}
/*
*  MR12 Rule-8.3 VIOLATION: The API do not support. "keyElementIdsPtr" and "keyElementIdsLengthPtr" is pointer,it will violate this rule.
*  but,it is safe
*/
CRYPTO_FUNC Std_ReturnType Crypto_KeyElementIdsGet(uint32 cryptoKeyId, uint32 *keyElementIdsPtr, uint32 *keyElementIdsLengthPtr)   /* PRQA S 3673 */
{
    /*Avoid compiler warnings*/
    (void)cryptoKeyId;
    (void)keyElementIdsPtr;
    (void)keyElementIdsLengthPtr;
#if (STD_ON == CRYPTO_DEV_ERROR_DETECT)
    (void) Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_KEY_ELEMENT_IDS_GET, CRYPTO_E_NOT_SUPPORTED);
#endif /* (STD_ON == CRYPTO_DEV_ERROR_DETECT) */
    return E_NOT_OK;
}
/* */
CRYPTO_FUNC Std_ReturnType Crypto_KeyElementSet(uint32 cryptoKeyId, uint32 keyElementId, const uint8 *keyPtr, uint32 keyLength)
{
    /*Avoid compiler warnings*/
    (void)cryptoKeyId;
    (void)keyElementId;
    (void)keyPtr;
    (void)keyLength;
#if (STD_ON == CRYPTO_DEV_ERROR_DETECT)
    (void) Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_KEY_ELEMENT_SET, CRYPTO_E_NOT_SUPPORTED);
#endif /* (STD_ON == CRYPTO_DEV_ERROR_DETECT) */
    return E_NOT_OK;
}

/*
*  MR12 Rule-8.3 VIOLATION: The API do not support."publicValueLengthPtr" and "publicValuePtr" is pointer,it will violate this rule.
*but,it is safe
*/
CRYPTO_FUNC Std_ReturnType Crypto_KeyExchangeCalcPubVal(uint32 cryptoKeyId, uint8 *publicValuePtr, uint32 *publicValueLengthPtr)   /* PRQA S 3673 */
{
    /*Avoid compiler warnings*/
    (void)cryptoKeyId;
    (void)publicValuePtr;
    (void)publicValueLengthPtr;
#if (STD_ON == CRYPTO_DEV_ERROR_DETECT)
    (void) Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID,
                           (uint8)CRYPTO_SID_KEY_EXCHANGE_CALC_PUB_VAL, CRYPTO_E_NOT_SUPPORTED);/* PRQA S 3673 */
#endif /* (STD_ON == CRYPTO_DEV_ERROR_DETECT) */
    return E_NOT_OK;
}
/*
*/
CRYPTO_FUNC Std_ReturnType Crypto_KeyExchangeCalcSecret(uint32 cryptoKeyId, const uint8 *partnerPublicValuePtr, uint32 partnerPublicValueLength)
{
    /*Avoid compiler warnings*/
    (void)cryptoKeyId;
    (void)partnerPublicValuePtr;
    (void)partnerPublicValueLength;
#if (STD_ON == CRYPTO_DEV_ERROR_DETECT)
    (void) Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_KEY_EXCHANGE_CALC_SECRET, CRYPTO_E_NOT_SUPPORTED);
#endif /* (STD_ON == CRYPTO_DEV_ERROR_DETECT) */
    return E_NOT_OK;
}

/*
*/
CRYPTO_FUNC Std_ReturnType Crypto_KeyGenerate(uint32 cryptoKeyId)
{
    /*Avoid compiler warnings*/
    (void)cryptoKeyId;
#if (STD_ON == CRYPTO_DEV_ERROR_DETECT)
    (void) Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_KEY_GENERATE, CRYPTO_E_NOT_SUPPORTED);
#endif /* (STD_ON == CRYPTO_DEV_ERROR_DETECT) */
    return E_NOT_OK;
}

/*
*/
CRYPTO_FUNC Std_ReturnType Crypto_KeySetValid(uint32 cryptoKeyId)
{
    Std_ReturnType             RetVal         = (Std_ReturnType)E_NOT_OK;
    /*Avoid compiler warnings*/
    (void)cryptoKeyId;
#if (STD_ON == CRYPTO_DEV_ERROR_DETECT)
    (void) Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_KEY_SET_VALID, CRYPTO_E_NOT_SUPPORTED);
#endif /* (STD_ON == CRYPTO_DEV_ERROR_DETECT) */
    return RetVal;
}
/*
*/
CRYPTO_FUNC Std_ReturnType Crypto_KeySetInValid(uint32 cryptoKeyId)
{
    Std_ReturnType            RetVal         = (Std_ReturnType)E_NOT_OK;
    /*Avoid compiler warnings*/
    (void)cryptoKeyId;
#if (STD_ON == CRYPTO_DEV_ERROR_DETECT)
    (void) Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_KEY_SET_INVALID, CRYPTO_E_NOT_SUPPORTED);
#endif /* (STD_ON == CRYPTO_DEV_ERROR_DETECT) */
    return RetVal;
}
/**
  * @brief            This function checks the key if valid.
  * @param[in]        Job  pointer to the job.
  * @return           Std_ReturnType
  * @retval           E_OK               The key is valid.
  * @retval           E_NOT_OK           The key is invalid.
*/
CRYPTO_FUNC static Std_ReturnType Crypto_CheckKeyvalid(const Crypto_JobType *Job)
{
    uint32 KeyIdIndex;
    uint32 KeylistElementId;
    Std_ReturnType             RetVal         = (Std_ReturnType)E_OK;
    KeyIdIndex = (Job->cryptoKeyId);
    if (KeyIdIndex >= CRYPTO_DRIVER_KEYID_MAX)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        KeylistElementId = Crypto_KeyList[KeyIdIndex].AdressKeyIndex[0];
        if (MAXBITS_OF_KEY < Crypto_KeyElementList[KeylistElementId].KenLengthInbits)
        {
            /*key length out of rang 256 bits */
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else if ((FALSE == Crypto_KeyElementList[KeylistElementId].UseSecNVRKey) &&
                 (TRUE == Crypto_KeyElementList[KeylistElementId].CryptoKeyElementPersist) &&
                 ((0U == Crypto_KeyElementList[KeylistElementId].KenLengthInbits)
                  || (NULL_PTR == Crypto_KeyElementList[KeylistElementId].KeyRamAdress)))
        {
            /*keytype is  of software. and input point is null*/
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else if (CRYPTO_ALGOFAM_AES == Job->jobPrimitiveInfo->primitiveInfo->algorithm.family)
        {
            /*The AES engine supports 128-bit, 192-bit and 256-bit key size*/
            if ((HCU_AES_KeyLength_128bits != Crypto_KeyElementList[KeylistElementId].KenLengthInbits) &&
                    (HCU_AES_KeyLength_192bits != Crypto_KeyElementList[KeylistElementId].KenLengthInbits) &&
                    (HCU_AES_KeyLength_256bits != Crypto_KeyElementList[KeylistElementId].KenLengthInbits))
            {
                RetVal = E_NOT_OK;
            }
        }
        else
        {
            /*do nothing*/
        }
    }
    return RetVal;
}

/**
 * @brief            This function checks the input parameter if valid.
 * @param[in]        Job  Pointer to the job.
 * @return           Std_ReturnType
 */
CRYPTO_FUNC static Std_ReturnType Crypto_CheckParaInJobProcess(const Crypto_JobType *Job)
{
    Std_ReturnType             RetVal         = (Std_ReturnType)E_OK;
    if (CRYPTO_RANDOMGENERATE == Job->jobPrimitiveInfo->primitiveInfo->service)
    {
        if (NULL_PTR == Job->jobPrimitiveInputOutput.outputPtr)
        {
            /*output pointer is null*/
            RetVal = E_NOT_OK;
        }
        else if ((*(Job->jobPrimitiveInputOutput.outputLengthPtr) > CRYPTO_LENGTH_OF_RANDOM) ||
                 ((*(Job->jobPrimitiveInputOutput.outputLengthPtr) % MINLENGTH_OF_RANDOM) != 0U))
        {
            /*Random 256bits(32 bytes). */
            RetVal = E_NOT_OK;
        }
        else
        {
            /*Do nothing*/
        }
    }
    else if ((E_NOT_OK == Crypto_CheckKeyvalid(Job)) &&
             (CRYPTO_HASH != Job->jobPrimitiveInfo->primitiveInfo->service))
    {
        /*check Key if valid*/
        RetVal = E_NOT_OK;
    }
    else
    {
        if ((CRYPTO_MACVERIFY != Job->jobPrimitiveInfo->primitiveInfo->service) &&
                ((NULL_PTR == Job->jobPrimitiveInputOutput.inputPtr) ||
                 (NULL_PTR == Job->jobPrimitiveInputOutput.outputPtr)))
        {
            /*input or output pointer is null.*/
            RetVal = E_NOT_OK;
        }
        else if ((CRYPTO_ALGOFAM_SHA2_256 == Job->jobPrimitiveInfo->primitiveInfo->algorithm.family) &&
                 ((((Job->jobPrimitiveInputOutput.mode != CRYPTO_OPERATIONMODE_FINISH) &&
                    (Job->jobPrimitiveInputOutput.mode != CRYPTO_OPERATIONMODE_SINGLECALL)) &&
                   ((Job->jobPrimitiveInputOutput.inputLength % HCU_SHA_256_BLOCK_SIZE) != 0U)) ||
                  (*(Job->jobPrimitiveInputOutput.outputLengthPtr) > LENGTH_OF_SHA256) ||
                  ((*(Job->jobPrimitiveInputOutput.outputLengthPtr) % MINBYTES_OF_INPUT) != 0U)))
        {
            /*Block size should be divided into times of 64 bytes in SHA-256 .*/
            RetVal = E_NOT_OK;
        }
        else if ((CRYPTO_ALGOFAM_SHA2_384 == Job->jobPrimitiveInfo->primitiveInfo->algorithm.family) &&
                 ((((Job->jobPrimitiveInputOutput.mode != CRYPTO_OPERATIONMODE_FINISH) &&
                    (Job->jobPrimitiveInputOutput.mode != CRYPTO_OPERATIONMODE_SINGLECALL)) &&
                   ((Job->jobPrimitiveInputOutput.inputLength % HCU_SHA_384_BLOCK_SIZE) != 0U)) ||
                  (*(Job->jobPrimitiveInputOutput.outputLengthPtr) > LENGTH_OF_SHA384) ||
                  ((*(Job->jobPrimitiveInputOutput.outputLengthPtr) % MINBYTES_OF_INPUT) != 0U)))
        {
            /*Block size should be divided into times of 128 bytes in SHA-384.*/
            RetVal = E_NOT_OK;
        }
        else if (((CRYPTO_ALGOFAM_SHA2_256 != Job->jobPrimitiveInfo->primitiveInfo->algorithm.family) && \
                  (CRYPTO_ALGOFAM_SHA2_384 != Job->jobPrimitiveInfo->primitiveInfo->algorithm.family)) && \
                 ((Job->jobPrimitiveInputOutput.inputLength % HCU_BUFF_LEN_CHECK_MASK) != 0U))
        {
            /*HCU Module of mcu,Input FIFO Data, write should be in 128 bits(16bytes).*/
            RetVal = E_NOT_OK;
        }
        else if ((CRYPTO_ALGOMODE_CBC == Job->jobPrimitiveInfo->primitiveInfo->algorithm.mode) ||
                 (CRYPTO_ALGOMODE_CTR == Job->jobPrimitiveInfo->primitiveInfo->algorithm.mode) ||
                 (CRYPTO_MACVERIFY == Job->jobPrimitiveInfo->primitiveInfo->service))
        {
            /*In this condition,Need to check sencondinput*/
            if ((NULL_PTR == Job->jobPrimitiveInputOutput.secondaryInputPtr) ||
                    (Job->jobPrimitiveInputOutput.secondaryInputLength != MINBYTES_OF_INPUT))
            {
                /*Second output pointer is null or Size is out rang.*/
                RetVal = E_NOT_OK;
            }
        }
        else if (((CRYPTO_ENCRYPT == Job->jobPrimitiveInfo->primitiveInfo->service) ||
                  (CRYPTO_DECRYPT == Job->jobPrimitiveInfo->primitiveInfo->service)) &&
                 (Job->jobPrimitiveInputOutput.inputLength != (*(Job->jobPrimitiveInputOutput.outputLengthPtr))))
        {
            /*Sevice ENCRYPT and DECRYPT Require Input eque output*/
            RetVal = E_NOT_OK;
        }
        else if (((CRYPTO_OPERATIONMODE_START == Job->jobPrimitiveInputOutput.mode) || \
                  (CRYPTO_OPERATIONMODE_UPDATE == Job->jobPrimitiveInputOutput.mode) || \
                  (CRYPTO_OPERATIONMODE_FINISH == Job->jobPrimitiveInputOutput.mode)) && \
                 (Job->jobPrimitiveInputOutput.inputLength > CRYPTO_MAXSIZE_WRITEONCE))
        {
            /*In stream mode, the max length of input data can't more than CRYPTO_MAXSIZE_WRITEONCE*/
            RetVal = E_NOT_OK;
        }
        else if ((CRYPTO_OPERATIONMODE_STREAMSTART == Job->jobPrimitiveInputOutput.mode) && \
                 (Job->jobPrimitiveInputOutput.inputLength > ((uint32)2U * CRYPTO_MAXSIZE_WRITEONCE)))
        {
            /*In stream mode, the max length of input data can't more than 2*CRYPTO_MAXSIZE_WRITEONCE*/
            RetVal = E_NOT_OK;
        }
        else
        {
            /*Do nothing*/
        }
    }
    return RetVal;
}

/**
 * @brief            This function checks the service if supported.
 * @param[in]        ObjectId    Holds the index of the Crypto Driver Object
 * @param[in]        Job         Pointer to the configuration of the job. Contains structures with job and
 * @return           Std_ReturnType
 * @retval           E_OK               The service is supported.
 * @retval           E_NOT_OK           The service is not supported.
 */
CRYPTO_FUNC static Std_ReturnType Crypto_CheckServiceIfSupported(uint32 ObjectId, const Crypto_JobType *Job)
{
    Std_ReturnType             RetVal         = (Std_ReturnType)E_NOT_OK;
    uint8 Tempi = 0;
    for (; Tempi < Crypto_ObjectsList[ObjectId].PrimitivesNum; ++Tempi)
    {
        if (((uint8)(Job->jobPrimitiveInfo->primitiveInfo->service) ==
                (uint8)(Crypto_ObjectsList[ObjectId].CryptoPrimitives[Tempi].Service))
                && ((uint8)(Job->jobPrimitiveInfo->primitiveInfo->algorithm.family) ==
                    (Crypto_ObjectsList[ObjectId].CryptoPrimitives[Tempi].AlgoFamily))
                && ((uint8)(Job->jobPrimitiveInfo->primitiveInfo->algorithm.mode) ==
                    (Crypto_ObjectsList[ObjectId].CryptoPrimitives[Tempi].AlgoMode))
                && ((uint8)(Job->jobPrimitiveInfo->primitiveInfo->algorithm.secondaryFamily) ==
                    (Crypto_ObjectsList[ObjectId].CryptoPrimitives[Tempi].SecondaryAlgoFamily))
           )
        {
            RetVal         = (Std_ReturnType)E_OK;
            break;
        }
    }
    return RetVal;
}


#if (STD_ON == CRYPTO_DEV_ERROR_DETECT)
/**
* @brief            This function checks that the parameters and configuration are valid for Crypto_ProcessJob().
* @param[in]        ObjectId    Holds the index of the Crypto Driver Object
* @param[in]        Job         Pointer to the configuration of the job. Contains structures with job and
*                               primitive relevant information but also pointer to result buffers.
* @return           Std_ReturnType
* @retval           E_OK                        Service request is valid
* @retval           E_NOT_OK                    Service request is not valid
*/
CRYPTO_FUNC static Std_ReturnType Crypto_CheckJob_ParameteError(uint32 ObjectId, const Crypto_JobType *Job)
{
    Std_ReturnType             RetVal         = (Std_ReturnType)E_OK;
    /* Check whether the driver is initialized */
    if (CRYPTO_DRIVER_UNINIT == Crypto_DriverState)
    {

        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_PROCESS_JOB, CRYPTO_E_UNINIT);
        RetVal         = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == Job)
    {
        /* If the parameter job is a null pointer and if development error detection for the Crypto Driver is enabled,
           the function Crypto_ProcessJob shall report CRYPTO_E_PARAM_POINTER to the DET and return E_NOT_OK. */
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_PROCESS_JOB, CRYPTO_E_PARAM_POINTER);
        RetVal         = (Std_ReturnType)E_NOT_OK;
    }
    else if (ObjectId >= CRYPTO_DRIVER_OBJECT_MAX)
    {
        /* If the ObjectId out of range and if development error detection for the Crypto Driver is enabled,
           the function Crypto_ProcessJob shall report CRYPTO_E_PARAM_HANDLE to the DET and return E_NOT_OK. */
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_PROCESS_JOB, CRYPTO_E_PARAM_HANDLE);
        RetVal         = (Std_ReturnType)E_NOT_OK;
    }
    /* check service is not supported */
    else if ((Std_ReturnType)E_NOT_OK == Crypto_CheckServiceIfSupported(ObjectId, Job))
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_PROCESS_JOB, CRYPTO_E_NOT_SUPPORTED);
        RetVal         = (Std_ReturnType)E_NOT_OK;
    }
    /* Check whether the u32CryptoKeyId is valid */
    else if ((Std_ReturnType)E_NOT_OK == Crypto_CheckParaInJobProcess(Job))
    {
        (void)Det_ReportError((uint16)CRYPTO_MODULE_ID, (uint8)CRYPTO_INSTANCE_ID, (uint8)CRYPTO_SID_PROCESS_JOB, CRYPTO_E_INVALID_PARAM);
        RetVal         = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /*do nothing*/
    }
    return RetVal;
}
#endif /* (STD_ON == CRYPTO_DEV_ERROR_DETECT) */
/*
*  MR12 Rule-10.5 VIOLATION: In this API function,There are different enum Type conversion.it is safe.
*/
/**
 * @brief            This function prepares the parameters for processing a job.
 * @param[in]        Job         Pointer to the configuration of the job. Contains structures with job and
 *                               primitive relevant information but also pointer to result buffers.
 * @param[in]        ResetFlag  If it is greater than zero, all parameters are initialized for a new job.
 *                               If it is zero, only the input and output pointers and lengths are updated
 *                               for a continued job.
 * @return           Std_ReturnType
 * @retval           E_OK               The parameters have been prepared successfully.
 * @retval           E_NOT_OK          The parameters could not be prepared successfully.
 */
CRYPTO_FUNC static Std_ReturnType Crypto_PrepareParemeter(const Crypto_JobType *Job, uint8 ResetFlag)
{
    Std_ReturnType             RetVal         = (Std_ReturnType)E_OK;
    if (ResetFlag > 0U)
    {
        /*Inputdata Reset*/
        Crypto_RunningData.HcuTotalLength = Job->jobPrimitiveInputOutput.inputLength;
        Crypto_RunningData.HcuInputPtr = Job->jobPrimitiveInputOutput.inputPtr;
        Crypto_RunningData.HcuInputLength = Job->jobPrimitiveInputOutput.inputLength;
        Crypto_RunningData.HcuInputIndex = 0;
        Crypto_RunningData.HcuInputControlIndex = 0;
        Crypto_RunningData.HcuSecondInputPtr = NULL_PTR;
        Crypto_RunningData.HcuSecondInputLength = 0;
        Crypto_RunningData.HcuCmacVerifyResultPtr = NULL_PTR;
        /*outputdata Reset*/
        Crypto_RunningData.HcuOutPutPtr = Job->jobPrimitiveInputOutput.outputPtr;
        if (NULL_PTR != Job->jobPrimitiveInputOutput.outputLengthPtr)
        {
            Crypto_RunningData.HcuOutPutPtrLength = *(Job->jobPrimitiveInputOutput.outputLengthPtr);
        }
        else
        {
            /*do nothing*/
        }
        /*Key Reset*/
        Crypto_RunningData.HcuRunKey = &Crypto_KeyElementList[Crypto_KeyList[Job->cryptoKeyId].AdressKeyIndex[0]];
        /*Control Reset*/
        Crypto_RunningData.HcuRunStatus = HCU_IDLE;
        Crypto_RunningData.HcuProcessing = Job->jobPrimitiveInfo->processingType;
        /*algorithm Reset*/
        if ((CRYPTO_HASH == Job->jobPrimitiveInfo->primitiveInfo->service) &&
                (CRYPTO_ALGOFAM_SHA2_256 == Job->jobPrimitiveInfo->primitiveInfo->algorithm.family))
        {
            /* Hash 256 */
            Crypto_RunningData.HcuEngine = ENG_SHA;
            Crypto_RunningData.AlgorithmAESMode = (Crypto_Lld_Hcu_AesModeType)HCU_SHA_256;/* PRQA S 4322  */
            Crypto_RunningData.HcuModeSel = MODE_ENC;
            /*Key Reset*/
            Crypto_RunningData.HcuRunKey = NULL_PTR;
        }
        else if ((CRYPTO_HASH == Job->jobPrimitiveInfo->primitiveInfo->service) &&
                 (CRYPTO_ALGOFAM_SHA2_384 == Job->jobPrimitiveInfo->primitiveInfo->algorithm.family))
        {
            /*Hash 384*/
            Crypto_RunningData.HcuEngine = ENG_SHA;
            Crypto_RunningData.AlgorithmAESMode = (Crypto_Lld_Hcu_AesModeType)HCU_SHA_384;/* PRQA S 4322  */
            Crypto_RunningData.HcuModeSel = MODE_ENC;
            /*Key Reset*/
            Crypto_RunningData.HcuRunKey = NULL_PTR;
        }
        else if (CRYPTO_MACGENERATE == Job->jobPrimitiveInfo->primitiveInfo->service)
        {
            /*AES+CMAC+ENC */
            Crypto_RunningData.HcuEngine = ENG_AES;
            Crypto_RunningData.HcuModeSel = MODE_ENC;
            Crypto_RunningData.AlgorithmAESMode = ALG_AES_CMAC;
        }
        else if (CRYPTO_MACVERIFY == Job->jobPrimitiveInfo->primitiveInfo->service)
        {
            /*AES+CMAC+DNC*/
            Crypto_RunningData.HcuEngine = ENG_AES;
            Crypto_RunningData.HcuModeSel = MODE_DEC;
            Crypto_RunningData.AlgorithmAESMode = ALG_AES_CMAC;
            /*Inputdata Reset*/
            Crypto_RunningData.HcuSecondInputPtr = Job->jobPrimitiveInputOutput.secondaryInputPtr;
            Crypto_RunningData.HcuSecondInputLength = Job->jobPrimitiveInputOutput.secondaryInputLength;
            Crypto_RunningData.HcuCmacVerifyResultPtr = Job->jobPrimitiveInputOutput.verifyPtr;
        }
        else if (CRYPTO_ENCRYPT == Job->jobPrimitiveInfo->primitiveInfo->service)
        {
            Crypto_RunningData.HcuEngine = ENG_AES;
            Crypto_RunningData.HcuModeSel = MODE_ENC;
            if (CRYPTO_ALGOMODE_ECB == Job->jobPrimitiveInfo->primitiveInfo->algorithm.mode)
            {
                Crypto_RunningData.AlgorithmAESMode = ALG_AES_ECB;
            }
            else if (CRYPTO_ALGOMODE_CBC == Job->jobPrimitiveInfo->primitiveInfo->algorithm.mode)
            {
                Crypto_RunningData.AlgorithmAESMode = ALG_AES_CBC;
                /*Inputdata Reset Need iv*/
                Crypto_RunningData.HcuSecondInputPtr = Job->jobPrimitiveInputOutput.secondaryInputPtr;
                Crypto_RunningData.HcuSecondInputLength = Job->jobPrimitiveInputOutput.secondaryInputLength;
            }
            else if (CRYPTO_ALGOMODE_CTR == Job->jobPrimitiveInfo->primitiveInfo->algorithm.mode)
            {
                Crypto_RunningData.AlgorithmAESMode = ALG_AES_CTR;
                /*Inputdata Reset Need CV*/
                Crypto_RunningData.HcuSecondInputPtr = Job->jobPrimitiveInputOutput.secondaryInputPtr;
                Crypto_RunningData.HcuSecondInputLength = Job->jobPrimitiveInputOutput.secondaryInputLength;
            }
            else
            {
                /*do nothing*/
            }
        }
        else if (CRYPTO_DECRYPT == Job->jobPrimitiveInfo->primitiveInfo->service)
        {
            Crypto_RunningData.HcuEngine = ENG_AES;
            Crypto_RunningData.HcuModeSel = MODE_DEC;
            if (CRYPTO_ALGOMODE_ECB == Job->jobPrimitiveInfo->primitiveInfo->algorithm.mode)
            {
                Crypto_RunningData.AlgorithmAESMode = ALG_AES_ECB;
            }
            else if (CRYPTO_ALGOMODE_CBC == Job->jobPrimitiveInfo->primitiveInfo->algorithm.mode)
            {
                Crypto_RunningData.AlgorithmAESMode = ALG_AES_CBC;
                /*Inputdata Reset Need iv*/
                Crypto_RunningData.HcuSecondInputPtr = Job->jobPrimitiveInputOutput.secondaryInputPtr;
                Crypto_RunningData.HcuSecondInputLength = Job->jobPrimitiveInputOutput.secondaryInputLength;
            }
            else if (CRYPTO_ALGOMODE_CTR == Job->jobPrimitiveInfo->primitiveInfo->algorithm.mode)
            {
                Crypto_RunningData.AlgorithmAESMode = ALG_AES_CTR;
                /*Inputdata Reset Need CV*/
                Crypto_RunningData.HcuSecondInputPtr = Job->jobPrimitiveInputOutput.secondaryInputPtr;
                Crypto_RunningData.HcuSecondInputLength = Job->jobPrimitiveInputOutput.secondaryInputLength;
            }
            else
            {
                /*do nothing*/
            }
        }
        else
        {
            /*do nothing*/
        }
    }
    else
    {
        /*Input Total Length update*/
        Crypto_RunningData.HcuTotalLength += Job->jobPrimitiveInputOutput.inputLength;
        /*Inputdata Update*/
        Crypto_RunningData.HcuInputPtr = Job->jobPrimitiveInputOutput.inputPtr;
        Crypto_RunningData.HcuInputLength = Job->jobPrimitiveInputOutput.inputLength;
        /*Outputdata Update*/
        Crypto_RunningData.HcuOutPutPtr = Job->jobPrimitiveInputOutput.outputPtr;
        if (NULL_PTR != Job->jobPrimitiveInputOutput.outputLengthPtr)
        {
            Crypto_RunningData.HcuOutPutPtrLength = *(Job->jobPrimitiveInputOutput.outputLengthPtr);
        }
        else
        {
            /*do nothing*/
        }
        Crypto_RunningData.HcuInputIndex = 0;
        Crypto_RunningData.HcuInputControlIndex = 0;
        /*The hcu state need changed to UPDATEFINIT when job is CRYPTO_OPERATIONMODE_FINISH*/
        if (CRYPTO_OPERATIONMODE_FINISH == Job->jobPrimitiveInputOutput.mode)
        {
            Crypto_RunningData.HcuRunStatus = HCU_UPDATEFINISH;
        }
    }
    return RetVal;
}
/**
 * @brief            This function processes the current job.
 *
 * @param[in]        None
 * @return           Std_ReturnType
 * @retval           E_OK               The job has been processed successfully.
 * @retval           E_NOT_OK          The job could not be processed successfully.
 */

CRYPTO_FUNC static  Std_ReturnType Crypto_ProcessJobHcu(void)
{
    Std_ReturnType             RetVal         = (Std_ReturnType)E_NOT_OK;
    uint8 JobOperation = 0xFF;
    if (NULL_PTR != Crypto_Instance[0].CryptoCurrentJob)
    {
        JobOperation = (uint8)Crypto_Instance[0].CryptoCurrentJob->jobPrimitiveInputOutput.mode;
    }
    /*Job process*/
    switch (JobOperation)
    {
        case (uint8)CRYPTO_OPERATIONMODE_START:
            RetVal = Crypto_Mld_HcuStart(CRYPTO_OPT_MULTI_MODE);
            if ((uint8)CRYPTO_PROCESSING_SYNC == (uint8)Crypto_Instance[0].CryptoCurrentJob->jobPrimitiveInfo->processingType)
            {
                Crypto_Instance[0].CryptoCurrentJob->jobState = CRYPTO_JOBSTATE_IDLE;
                if (E_OK != RetVal)
                {
                    RetVal = (Std_ReturnType)E_NOT_OK;
                    Crypto_Instance[0].CryptoCurrentJob = NULL_PTR;
                }
            }
            else
            {
                if (1U != RetVal)
                {
                    /*0xFE mean function not run,erro*/
                    Crypto_Instance[0].CryptoCurrentJob->jobState = CRYPTO_JOBSTATE_IDLE;
                    if (RetVal > 0U)
                    {
                        RetVal = (Std_ReturnType)E_NOT_OK;
                        CryIf_CallbackNotification(Crypto_Instance[0].CryptoCurrentJob, RetVal);
                        Crypto_Instance[0].CryptoCurrentJob = NULL_PTR;
                    }
                    else
                    {
                        RetVal = (Std_ReturnType)E_OK;
                        CryIf_CallbackNotification(Crypto_Instance[0].CryptoCurrentJob, RetVal);
                    }
                }
            }
            break;
        case (uint8)CRYPTO_OPERATIONMODE_UPDATE:
            RetVal =  Crypto_Mld_HcuUpdate(CRYPTO_OPT_MULTI_MODE);
            if ((uint8)CRYPTO_PROCESSING_SYNC == (uint8)Crypto_Instance[0].CryptoCurrentJob->jobPrimitiveInfo->processingType)
            {
                Crypto_Instance[0].CryptoCurrentJob->jobState = CRYPTO_JOBSTATE_IDLE;
                if (E_OK != RetVal)
                {
                    RetVal = (Std_ReturnType)E_NOT_OK;
                    Crypto_Instance[0].CryptoCurrentJob = NULL_PTR;
                }
            }
            else
            {
                if (1U != RetVal)
                {
                    /*0xFE mean function not run,erro*/
                    Crypto_Instance[0].CryptoCurrentJob->jobState = CRYPTO_JOBSTATE_IDLE;
                    if (RetVal > 0U)
                    {
                        RetVal = (Std_ReturnType)E_NOT_OK;
                        CryIf_CallbackNotification(Crypto_Instance[0].CryptoCurrentJob, RetVal);
                        Crypto_Instance[0].CryptoCurrentJob = NULL_PTR;
                    }
                    else
                    {
                        RetVal = (Std_ReturnType)E_OK;
                        CryIf_CallbackNotification(Crypto_Instance[0].CryptoCurrentJob, RetVal);
                    }
                }
            }
            break;
        case (uint8)CRYPTO_OPERATIONMODE_STREAMSTART:
            (void)Crypto_Mld_HcuStart(CRYPTO_OPT_STREAM_MODE);
            RetVal =  Crypto_Mld_HcuUpdate(CRYPTO_OPT_STREAM_MODE);
            if ((uint8)CRYPTO_PROCESSING_SYNC == (uint8)Crypto_Instance[0].CryptoCurrentJob->jobPrimitiveInfo->processingType)
            {
                Crypto_Instance[0].CryptoCurrentJob->jobState = CRYPTO_JOBSTATE_IDLE;
                if (E_OK != RetVal)
                {
                    RetVal = (Std_ReturnType)E_NOT_OK;
                    Crypto_Instance[0].CryptoCurrentJob = NULL_PTR;
                }
            }
            else
            {
                if ((1U != RetVal) && (0xFEU != RetVal))
                {
                    /*0xFE mean Function that Called not runing.waiting*/
                    Crypto_Instance[0].CryptoCurrentJob->jobState = CRYPTO_JOBSTATE_IDLE;
                    if (RetVal > 0U)
                    {
                        RetVal = (Std_ReturnType)E_NOT_OK;
                        CryIf_CallbackNotification(Crypto_Instance[0].CryptoCurrentJob, RetVal);
                        Crypto_Instance[0].CryptoCurrentJob = NULL_PTR;
                    }
                    else
                    {
                        RetVal = (Std_ReturnType)E_OK;
                        CryIf_CallbackNotification(Crypto_Instance[0].CryptoCurrentJob, RetVal);
                    }
                }
            }
            break;
        case (uint8)CRYPTO_OPERATIONMODE_FINISH:
            RetVal =  Crypto_Mld_HcuFinish(CRYPTO_OPT_MULTI_MODE);
            if ((uint8)CRYPTO_PROCESSING_SYNC == (uint8)Crypto_Instance[0].CryptoCurrentJob->jobPrimitiveInfo->processingType)
            {
                Crypto_Instance[0].CryptoCurrentJob->jobState = CRYPTO_JOBSTATE_IDLE;
                Crypto_Instance[0].CryptoCurrentJob = NULL_PTR;
                if (E_OK != RetVal)
                {
                    RetVal = (Std_ReturnType)E_NOT_OK;
                }
            }
            else
            {
                if (1U != RetVal)
                {
                    /*0xFE mean function not run,erro*/
                    Crypto_Instance[0].CryptoCurrentJob->jobState = CRYPTO_JOBSTATE_IDLE;
                    if (RetVal > 0U)
                    {
                        RetVal = (Std_ReturnType)E_NOT_OK;
                    }
                    else
                    {
                        RetVal = (Std_ReturnType)E_OK;
                    }
                    CryIf_CallbackNotification(Crypto_Instance[0].CryptoCurrentJob, RetVal);
                    Crypto_Instance[0].CryptoCurrentJob = NULL_PTR;
                }
            }
            break;
        case (uint8)CRYPTO_OPERATIONMODE_SINGLECALL:
            if ((uint8)CRYPTO_PROCESSING_SYNC == (uint8)Crypto_Instance[0].CryptoCurrentJob->jobPrimitiveInfo->processingType)
            {
                RetVal =  Crypto_Mld_HcuSyncSingleCall(CRYPTO_OPT_SINGLE_MODE);
                Crypto_Instance[0].CryptoCurrentJob->jobState = CRYPTO_JOBSTATE_IDLE;
                Crypto_Instance[0].CryptoCurrentJob = NULL_PTR;
                if (E_OK != RetVal)
                {
                    RetVal = (Std_ReturnType)E_NOT_OK;
                }
            }
            else
            {

                RetVal =  Crypto_Mld_HcuAsyncSingleCall(CRYPTO_OPT_SINGLE_MODE);
                if ((1U != RetVal) && (0xFEU != RetVal))
                {
                    /*0xFE mean Function that Called not runing.waiting*/
                    Crypto_Instance[0].CryptoCurrentJob->jobState = CRYPTO_JOBSTATE_IDLE;
                    if (RetVal > 0U)
                    {
                        RetVal = (Std_ReturnType)E_NOT_OK;
                    }
                    else
                    {
                        RetVal = (Std_ReturnType)E_OK;
                    }
                    CryIf_CallbackNotification(Crypto_Instance[0].CryptoCurrentJob, RetVal);
                    Crypto_Instance[0].CryptoCurrentJob = NULL_PTR;
                }
            }
            break;
        default:
            RetVal = (Std_ReturnType)E_NOT_OK;
            break;
    }
    return RetVal;
}

/**
* @brief            This function deals with the current job.
*
* @param[in]        ObjectId    Holds the index of the Crypto Driver Object
* @return           Std_ReturnType
* @retval           E_OK               The job has been dealt with successfully.
* @retval           E_NOT_OK          The job could not be dealt with successfully.
*/
CRYPTO_FUNC static  Std_ReturnType Crypto_JobDeal(uint32 ObjectId)
{
    uint8 JobRequestService;
    Std_ReturnType             RetVal         = (Std_ReturnType)E_NOT_OK;
    JobRequestService = (uint8)(Crypto_Instance[ObjectId].CryptoCurrentJob->jobPrimitiveInfo->primitiveInfo->service);
    switch (JobRequestService)
    {
        case (uint8)CRYPTO_HASH:
        case (uint8)CRYPTO_MACGENERATE:
        case (uint8)CRYPTO_MACVERIFY:
        case (uint8)CRYPTO_ENCRYPT:
        case (uint8)CRYPTO_DECRYPT:
#if defined (CRYPTO_ENABLE_USER_MODE_SUPPORT)
            RetVal = (Std_ReturnType)OsIf_Trusted_Call_Return(Crypto_ProcessJobHcu);
#else
            RetVal = Crypto_ProcessJobHcu();
#endif
            break;
        case (uint8)CRYPTO_RANDOMGENERATE:
        {
#if defined(CRYPTO_ENABLE_USER_MODE_SUPPORT)
            RetVal = (Std_ReturnType)OsIf_Trusted_Call_Return2param(Crypto_Mld_ProcessJobRandom, *(Crypto_Instance[ObjectId].CryptoCurrentJob->jobPrimitiveInputOutput.outputLengthPtr), Crypto_Instance[ObjectId].CryptoCurrentJob->jobPrimitiveInputOutput.outputPtr);
#else
            RetVal = Crypto_Mld_ProcessJobRandom(*(Crypto_Instance[ObjectId].CryptoCurrentJob->jobPrimitiveInputOutput.outputLengthPtr),
                                                 Crypto_Instance[ObjectId].CryptoCurrentJob->jobPrimitiveInputOutput.outputPtr);
#endif
            CryIf_CallbackNotification(Crypto_Instance[ObjectId].CryptoCurrentJob, RetVal);
            Crypto_Instance[ObjectId].CryptoCurrentJob->jobState = CRYPTO_JOBSTATE_IDLE;
            Crypto_Instance[ObjectId].CryptoCurrentJob = NULL_PTR;//Operation is clear

        }
        break;
        default:
            RetVal = (Std_ReturnType)E_NOT_OK;
            break;
    }
    return RetVal;
}
/**
 * @brief            This function prepares the parameters for the HCU.
 * @param[in]        Job         Pointer to the Crypto job structure.
 * @return           Std_ReturnType
 * @retval           E_OK               The parameters have been prepared successfully.
 * @retval           E_NOT_OK          The parameters could not be prepared successfully.
 */
CRYPTO_FUNC static  Std_ReturnType Crypto_AlgorithmPrepareParamete(Crypto_JobType *Job)
{
    uint8 JobOperation;
    Std_ReturnType             RetVal         = (Std_ReturnType)E_OK;
    JobOperation = (uint8)(Job->jobPrimitiveInputOutput.mode);
    if ((HCU_IDLE == Crypto_RunningData.HcuRunStatus) &&
            (CRYPTO_JOBSTATE_IDLE == Job->jobState) &&
            (((uint8)CRYPTO_OPERATIONMODE_START == JobOperation) ||
             ((uint8)CRYPTO_OPERATIONMODE_STREAMSTART == JobOperation) ||
             ((uint8)CRYPTO_OPERATIONMODE_SINGLECALL == JobOperation)))
    {
        /* Reset job */
        Crypto_Instance[0].CryptoCurrentJob = Job;
        (void)Crypto_PrepareParemeter(Crypto_Instance[0].CryptoCurrentJob, 1);
        Crypto_Instance[0].CryptoCurrentJob->jobState = CRYPTO_JOBSTATE_ACTIVE;
    }
    else if ((HCU_STARTING < Crypto_RunningData.HcuRunStatus) &&
             (CRYPTO_JOBSTATE_IDLE == Job->jobState) &&
             (((uint8)CRYPTO_OPERATIONMODE_START == JobOperation) ||
              ((uint8)CRYPTO_OPERATIONMODE_STREAMSTART == JobOperation) ||
              ((uint8)CRYPTO_OPERATIONMODE_SINGLECALL == JobOperation)))
    {
        /*Reset job*/
        Crypto_Instance[0].CryptoCurrentJob = Job;
        (void)Crypto_PrepareParemeter(Crypto_Instance[0].CryptoCurrentJob, 1);
        Crypto_Instance[0].CryptoCurrentJob->jobState = CRYPTO_JOBSTATE_ACTIVE;
    }
    else if (((HCU_STARTED == Crypto_RunningData.HcuRunStatus) || \
              (HCU_UPDATEIDLE == Crypto_RunningData.HcuRunStatus) || \
              (HCU_UPDATEFINISH == Crypto_RunningData.HcuRunStatus)) &&
             (((uint8)CRYPTO_OPERATIONMODE_UPDATE == JobOperation) || ((uint8)CRYPTO_OPERATIONMODE_FINISH == JobOperation)))
    {
        /*Update input*/
        Crypto_Instance[0].CryptoCurrentJob = Job;
        (void)Crypto_PrepareParemeter(Crypto_Instance[0].CryptoCurrentJob, 0);
        Crypto_Instance[0].CryptoCurrentJob->jobState = CRYPTO_JOBSTATE_ACTIVE;
    }
    else
    {
        RetVal         = (Std_ReturnType)E_NOT_OK;
    }
    return RetVal;
}

/**
 * @brief            This function prepares the parameters for the random job.
 * @param[in]        Job         Pointer to the Crypto job structure.
 * @return           Std_ReturnType
 * @retval           E_OK               The parameters have been prepared successfully.
 * @retval           E_NOT_OK          The parameters could not be prepared successfully.
 */
CRYPTO_FUNC static  Std_ReturnType Crypto_RandomPrepareParamete(Crypto_JobType *Job)
{
    uint8 JobOperation;
    Std_ReturnType             RetVal         = (Std_ReturnType)E_OK;
    JobOperation = (uint8)(Job->jobPrimitiveInputOutput.mode);
    if ((uint8)CRYPTO_OPERATIONMODE_SINGLECALL == JobOperation)
    {
        /*Only single call */
        Crypto_Instance[1].CryptoCurrentJob = Job;
        Crypto_Instance[1].CryptoCurrentJob->jobState = CRYPTO_JOBSTATE_ACTIVE;
    }
    else
    {
        RetVal         = (Std_ReturnType)E_NOT_OK;
    }
    return RetVal;
}
/**
* @brief            This function manages the current job.
*
* @param[in]        ObjectId    Holds the index of the Crypto Driver Object
* @param[in]        Job         Pointer to the configuration of the job. Contains structures with
*                               job and primitive relevant information but also pointer to result buffers.
* @return           Std_ReturnType
* @retval           E_OK               The job has been managed successfully.
* @retval           E_NOT_OK          The job could not be managed successfully.
* @retval           CRYPTO_E_BUSY     The job could not be managed because another job is in progress.
*/
CRYPTO_FUNC static  Std_ReturnType Crypto_JobManage(uint32 ObjectId, Crypto_JobType *Job)
{
    uint8 JobRequestService;
    uint8 JobOperation;
    Std_ReturnType             RetVal         = (Std_ReturnType)E_NOT_OK;
    JobRequestService = (uint8)(Job->jobPrimitiveInfo->primitiveInfo->service);
    JobOperation = (uint8)(Job->jobPrimitiveInputOutput.mode);
    /* If object job is null and job mode is start, then add new job,Reset paramete */
    if (NULL_PTR == Crypto_Instance[ObjectId].CryptoCurrentJob)
    {
        if (((uint8)CRYPTO_OPERATIONMODE_START == JobOperation) ||
                ((uint8)CRYPTO_OPERATIONMODE_STREAMSTART == JobOperation) ||
                ((uint8)CRYPTO_OPERATIONMODE_SINGLECALL == JobOperation))
        {
            /*CurrentJob is null and new job mode is start,then added*/
            Crypto_Instance[ObjectId].CryptoCurrentJob = Job;
            RetVal = (Std_ReturnType)E_OK;
        }
    }
    if (NULL_PTR != Crypto_Instance[ObjectId].CryptoCurrentJob)
    {
        if ((Job->jobId == Crypto_Instance[ObjectId].CryptoCurrentJob->jobId)
                && (CRYPTO_JOBSTATE_IDLE == Crypto_Instance[ObjectId].CryptoCurrentJob->jobState))
        {
            /*CurrentJob is not null and new job is same as current job*/
            if (((uint8)CRYPTO_HASH == JobRequestService) ||
                    ((uint8)CRYPTO_MACGENERATE == JobRequestService) ||
                    ((uint8)CRYPTO_MACVERIFY == JobRequestService) ||
                    ((uint8)CRYPTO_ENCRYPT == JobRequestService) ||
                    ((uint8)CRYPTO_DECRYPT == JobRequestService))
            {
                /*if service is CRYPTO_HASH ect*/
                (void)Crypto_AlgorithmPrepareParamete(Crypto_Instance[ObjectId].CryptoCurrentJob);
                RetVal = (Std_ReturnType)E_OK;
            }
            else if ((uint8)CRYPTO_RANDOMGENERATE == JobRequestService)
            {
                (void)Crypto_RandomPrepareParamete(Crypto_Instance[ObjectId].CryptoCurrentJob);
                RetVal = (Std_ReturnType)E_OK;
            }
            else
            {
                /*do nothing*/
            }
        }
        else
        {
            /*CurrentJob is not null and new job is not same as current job*/
            RetVal = CRYPTO_E_BUSY;
        }
    }
    return RetVal;
}
/*
*  MR12 Rule-10.4 VIOLATION: In this API function,If the parameter job is NULL, the value of Retval will be E_ NOT_ OK,
* the instruction ((uint8)CRYPTO_PROCESSING_SYNC == (uint8)job->jobPrimitiveInfo->processingType) will not be executed.
* so,it is safe.
*/
/**
* @brief            This function processes a crypto job.
*
* @param[in]        ObjectId    Holds the index of the Crypto Driver Object
* @param[in]        Job         Pointer to the configuration of the job. Contains structures with job and
*                               primitive relevant information but also pointer to result buffers.
* @return           Std_ReturnType
* @retval           E_OK               The job has been processed successfully.
* @retval           E_NOT_OK          The job could not be processed successfully.
*/
CRYPTO_FUNC Std_ReturnType Crypto_ProcessJob(uint32 objectId, Crypto_JobType *job)
{
    Std_ReturnType             RetVal         = (Std_ReturnType)E_OK;
    uint8  JobRequestService;
    uint32 TempInstanceId = 0;
    if (NULL_PTR != job)
    {
        JobRequestService = (uint8)(job->jobPrimitiveInfo->primitiveInfo->service);
        if ((uint8)CRYPTO_RANDOMGENERATE != JobRequestService)
        {
            TempInstanceId = 0;
        }
        else
        {
            TempInstanceId = 1;
        }
    }
#if (CRYPTO_DEV_ERROR_DETECT == STD_ON)
    RetVal = Crypto_CheckJob_ParameteError(objectId, job); /*!< step1: check paramete*/
#endif /* (CRYPTO_DEV_ERROR_DETECT == STD_ON) */
    if ((Std_ReturnType)E_OK == RetVal)
    {
        RetVal = Crypto_JobManage(TempInstanceId, job); /*!< step2: Job manage*/
    }
    if (((Std_ReturnType)E_OK == RetVal)
            && ((uint8)CRYPTO_PROCESSING_SYNC == (uint8)job->jobPrimitiveInfo->processingType)) /*PRQA S 2812  */
    {
        /*Job's mode is sync,do it immediately.or call mainfunction*/
        RetVal = Crypto_JobDeal(TempInstanceId);/*!< step3: Job Deal*/
    }
    return RetVal;
}
/**/
CRYPTO_FUNC Std_ReturnType Crypto_RandomSeed(uint32 cryptoKeyId, const uint8 *seedPtr, uint32 seedLength)
{
    /*Avoid compiler warnings*/
    (void)cryptoKeyId;
    (void)seedPtr;
    (void)seedLength;
    return E_NOT_OK;
}
/**
 * @brief            This function is called periodically to process the jobs.
 * @param[in]        None
 * @return           None
 */
CRYPTO_FUNC void Crypto_MainFunction(void)
{
    /*Check Crypto_ObjectsList,if job in that is active,then processe */
    uint8 Tempi = 0;
    for (; Tempi < CRYPTO_DRIVER_InstanceMax; ++Tempi)
    {
        if (Crypto_Instance[Tempi].CryptoCurrentJob != NULL_PTR)
        {
            if (Crypto_Instance[Tempi].CryptoCurrentJob->jobState == CRYPTO_JOBSTATE_ACTIVE)
            {
                (void)Crypto_JobDeal(Tempi);
            }
        }
    }
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

