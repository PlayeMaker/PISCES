/**
 * @file    Crypto_Types.h
 * @version
 *
 * @brief   AUTOSAR Crypto module interface
 * @details API implementation for CRYPTO driver
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
#ifndef CRYPTO_TYPES_H
#define CRYPTO_TYPES_H
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "Crypto_Cfg.h"
#include "Crypto_Lld_Hcu_Types.h"
#include "Csm_Types.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_VENDOR_ID_TYPES                      (180)
#define CRYPTO_AR_RELEASE_MAJOR_VERSION_TYPES       (4)
#define CRYPTO_AR_RELEASE_MINOR_VERSION_TYPES       (4)
#define CRYPTO_AR_RELEASE_REVISION_VERSION_TYPES    (0)
#define CRYPTO_SW_MAJOR_VERSION_TYPES               (0)
#define CRYPTO_SW_MINOR_VERSION_TYPES               (9)
#define CRYPTO_SW_PATCH_VERSION_TYPES               (1)
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/*Check if source file and Crypto Cfg defined header file are of the same vendor */
#if (CRYPTO_VENDOR_ID_TYPES != CRYPTO_VENDOR_ID_CFG)
#error "Crypto_Types.h and Crypto_Cfg.h have different vendor ids"
#endif

/*Check if source file and Crypto Cfg defined header file are of the same AUTOSAR version*/
#if ((CRYPTO_AR_RELEASE_MAJOR_VERSION_TYPES != CRYPTO_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (CRYPTO_AR_RELEASE_MINOR_VERSION_TYPES != CRYPTO_AR_RELEASE_MINOR_VERSION_CFG) || \
     (CRYPTO_AR_RELEASE_REVISION_VERSION_TYPES != CRYPTO_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "Crypto_Types.h and Crypto_Cfg.h have different AUTOSAR version numbers"
#endif

/*Check if source file and  Crypto Cfg defined header file are of the same software version*/
#if ((CRYPTO_SW_MAJOR_VERSION_TYPES != CRYPTO_SW_MAJOR_VERSION_CFG) || \
     (CRYPTO_SW_MINOR_VERSION_TYPES != CRYPTO_SW_MINOR_VERSION_CFG) || \
     (CRYPTO_SW_PATCH_VERSION_TYPES != CRYPTO_SW_PATCH_VERSION_CFG) \
    )
#error "Crypto_Types.h and Crypto_Cfg.h have different software version numbers"
#endif

/* Check if source file and Crypto Lld Hcu types defined header file are of the same vendor */
#if (CRYPTO_VENDOR_ID_TYPES != CRYPTO_LLD_HCU_TYPES_VENDOR_ID)
#error "Crypto_Types.h and Crypto_Lld_Hcu_Types.h have different vendor ids"
#endif

/* Check if source file and Crypto Lld Hcu types defined header file are of the same AUTOSAR version */
#if ((CRYPTO_AR_RELEASE_MAJOR_VERSION_TYPES != CRYPTO_LLD_HCU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_AR_RELEASE_MINOR_VERSION_TYPES != CRYPTO_LLD_HCU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_AR_RELEASE_REVISION_VERSION_TYPES != CRYPTO_LLD_HCU_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Crypto_Types.h and Crypto_Lld_Hcu_Types.h are different"
#endif

/* Check if source file and Crypto Lld Hcu types defined header file are of the same software version */
#if ((CRYPTO_SW_MAJOR_VERSION_TYPES != CRYPTO_LLD_HCU_TYPES_SW_MAJOR_VERSION) || \
     (CRYPTO_SW_MINOR_VERSION_TYPES != CRYPTO_LLD_HCU_TYPES_SW_MINOR_VERSION) || \
     (CRYPTO_SW_PATCH_VERSION_TYPES != CRYPTO_LLD_HCU_TYPES_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Crypto_Types.h and Crypto_Lld_Hcu_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
 * @brief        Define the writing access rights of the key element
 * @details      CRYPTO_WA_DENIED = key element can not be written from outside the Crypto Driver
                CRYPTO_WA INTERNAL_COPY = key element can be filled with another key element in the same crypto driver.
                CRYPTO_WA_ALLOWED = key element can be rwritten as plaintext
                CRYPTO_WA_ENCRYPTED = key element can be written encrypted. E.g. SHE load key.
 * @ref          ECUC_Crypto_00027
 */
typedef enum
{
    CRYPTO_WA_DENIED        = 0x01U,
    CRYPTO_WA_INTERNAL_COPY = 0x02U,
    CRYPTO_WA_ALLOWED       = 0x03U,
    CRYPTO_WA_ENCRYPTED     = 0x04U
} CRYPTO_KEY_ELEMENT_WRITE_ACCESS;
/**
 * @brief        Define the reading access rights of the key element.
 * @details      CRYPTO_RA_DENIED = key element cannot be read from outside the Crypto Driver
                CRYPTO_RA INTERNAL_COPY = key element can be copied to another key element in the same crypto driver.
                CRYPTO_RA_ALLOWED = key element can be read as plaintext
                CRYPTO_RA_ENCRYPTED = key element can be read encrypted. E.g. SHE Ram-Key export.
 * @ref          ECUC_Crypto_00024
 */
typedef enum
{
    CRYPTO_RA_DENIED        = 0x01U,
    CRYPTO_RA_INTERNAL_COPY = 0x02U,
    CRYPTO_RA_ALLOWED       = 0x03U,
    CRYPTO_RA_ENCRYPTED     = 0x04U
} CRYPTO_KEY_ELEMENT_READ_ACCESS;
/**
 * @brief        Defines the format for the key element. This is the format used to provide or extract the key data from the driver.
 * @details
 * @ref          ECUC_Crypto_00041
 */

typedef enum
{
    CRYPTO_KE_FORMAT_BIN_OCTET                       = 0x01U,
    CRYPTO_KE_FORMAT_BIN_SHEKEYS                     = 0x02U,
    CRYPTO_KE_FORMAT_BIN_IDENT_PRIVATEKEY_PKCS8      = 0x03U,
    CRYPTO_KE_FORMAT_BIN_IDENT_PUBLICKEY             = 0x04U,
    CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY              = 0x05U,
    CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY               = 0x06U,
    CRYPTO_KE_FORMAT_BIN_CERT_X509_V3                = 0x07U,
    CRYPTO_KE_FORMAT_BIN_CERT_CVC                    = 0x08U
} CRYPTO_KEY_ELEMENT_FORMAT;

/**
* @brief Enum containing the possible states of the Crypto driver
*/
typedef enum
{
    CRYPTO_DRIVER_UNINIT      = 0x00U,
    CRYPTO_DRIVER_INITIALIZED = 0x01U
} Crypto_DriverStateType;
/* Structure storing information about Key */
typedef struct
{
    /* Members storing Autosar required information */
    const   uint32                           CryptoKeyElementId;              /**< KeyElement ID*/
    const   boolean                          CryptoKeyElementAllowPartialAccess;/**< Flag  indicate if the key element is persistent or not*/
    /**< Define the format for the key element. This is the format used to provide or extract the key data from the driver.*/
    const   CRYPTO_KEY_ELEMENT_FORMAT        CryptoKeyFormat;
    const   boolean                          CryptoKeyElementPersist;           /**< Flag  indicate if the key element is persistent or not*/
    const   CRYPTO_KEY_ELEMENT_READ_ACCESS   CryptoKeyElementReadAccess;        /**< Define the reading access rights of the key element.*/
    const   uint32                           CryptoKeyElementMaxSize;         /**< Maximum size of the key element in bytes*/
    const   CRYPTO_KEY_ELEMENT_WRITE_ACCESS  CryptoKeyElementWriteAccess;       /**< Define the writing access rights of the key element.*/
    const   boolean                          UseSecNVRKey;              /**< Flag  indicate where the key stored in, NVR or RAM*/
    const   uint32                           NVRKeySlot;              /**< NVR Slot that stored the key if needed*/
    const   uint32                           KenLengthInbits;            /**< Key length in bits*/
    const   uint32                          *KeyRamAdress;            /**< Ram Adress that stored the key if needed*/
} Crypto_KeyElementType;
/**
* @brief Enum containing the possible primitives supported by the Crypto driver
*/
typedef enum
{
    PRIMITIVE_HASH                  = 0x00U,  /** Hash Service */
    PRIMITIVE_MACGENERATE           = 0x01U,  /* MacGenerate Service */
    PRIMITIVE_MACVERIFY             = 0x02U,  /* MacVerify Service */
    PRIMITIVE_ENCRYPT               = 0x03U,  /* Encrypt Service */
    PRIMITIVE_DECRYPT               = 0x04U,  /* Decrypt Service */
    PRIMITIVE_RANDOMGENERATE        = 0x0BU,  /* RandomGenerate Service */
} Crypto_PrimitiveServiceType;

typedef enum
{
    CRYPTO_OPT_SINGLE_MODE = 0x00U,     /**< Single mode operation */
    CRYPTO_OPT_MULTI_MODE  = 0x01U,     /**< Multi mode operation */
    CRYPTO_OPT_STREAM_MODE = 0x02U      /**< Stream mode operation */
} Crypto_OperationType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct
{
    const Crypto_PrimitiveServiceType Service;              /**< Service ID */
    const uint8                       AlgoFamily;         /**< Algorithm Family */
    const uint8                       AlgoMode;           /**< Algorithm Mode */
    const uint8                       SecondaryAlgoFamily;/**< Secondary Algorithm Family */
} Crypto_PrimitiveType;

/* Structure storing information about the Key.Be reference by uplayer  */
typedef struct
{

    uint32                  NumOfKey;       /**< Number of key elements*/
    const uint32           *AdressKeyIndex;/**< Reference to the list of key elements*/
} Crypto_KeyType;

/* Structure storing information about a Crypto Driver Object */
typedef struct
{
    const uint32                          CryptoQueueSize;  /**< Crypto Queue Size */
    const Crypto_PrimitiveType *const     CryptoPrimitives;   /**< Reference to the list of primitives supported by the Crypto Driver */
    const uint32                          PrimitivesNum;    /**< Number of primitives supported by the Crypto Driver */
} Crypto_ObjectType;
/* Structure storing information about a Crypto Driver Object */
typedef struct
{
    const uint32                          CryptoInstanceId;  /**< Crypto instance id */
    Crypto_JobType                       *CryptoCurrentJob;    /**< Crypto Current Job  */
} Crypto_InstanceType;


/* Structure storing information about the Key.Be reference by uplayer  */
typedef struct
{
    Crypto_Lld_Hcu_EngineType          HcuEngine;      /*!< HCU engine selection */
    Crypto_Lld_Hcu_AesModeType        AlgorithmAESMode; /*!< HCU algorithm selection */
    Crypto_Lld_Hcu_ShaType            AlgorithmSHAMode;     /*!< HCU Hash Mode selection */
    Crypto_Lld_Hcu_EngineModeType            HcuModeSel;     /*!< HCU mode selection */
    Crypto_ProcessingType     HcuProcessing;   /*!< HCU processing type */
    Crypto_Lld_Hcu_RunStatusType           HcuRunStatus;   /*!< HCU run status */
    const Crypto_KeyElementType    *HcuRunKey;    /*!< HCU run key */
    const uint8                    *HcuInputPtr;    /*!< HCU input data pointer */
    uint32                    HcuInputLength;  /*!< HCU input data length */
    uint32                    HcuInputIndex;       /*!< HCU input data index */
    uint32                    HcuInputControlIndex;    /*!< HCU load input data contorl index */
    const uint8                     *HcuSecondInputPtr;   /*!< HCU second input data pointer */
    uint32                    HcuSecondInputLength;    /*!< HCU second input data length */
    uint8                    *HcuOutPutPtr;    /*!< HCU output data pointer */
    uint32                    HcuOutPutPtrLength;  /*!< HCU output data length */
    Crypto_VerifyResultType  *HcuCmacVerifyResultPtr; /*!< HCU CMAC verify result pointer */
    uint32                    HcuTotalLength;  /*!< HCU Totol data length */
#if defined(CPU_YTM32B1MC0)
    uint8                   IvFillData[16];          /*!< HCU of MC0 IV fill data */
    uint8                   TempMacValue[16];          /*!< HCU of MC0 TempMacValue */
#elif defined (CPU_YTM32B1MD2)
    uint8                   IvFillData[32];          /*!< HCU of MC0 IV fill data */
    uint8                   TempMacValue[32];          /*!< HCU of MC0 TempMacValue */
#else
#endif
} Crypto_RunningDataType;

/**
*  @brief  Structure for Crypto configuration
*/
typedef struct
{
    Crypto_Lld_Hcu_SwappingType Swap;           /*!< Specifies the type of swapping */
    Crypto_Lld_Hcu_CarryType CarryType;    /*!< Specifies the type of data carried type */
    uint8 IngressDMAChannel;     /*!< Channel number for DMA ingress channel */
    uint8 EgressDMAChannel;      /*!< Channel number for DMA egress channel */

} Crypto_ConfigType;
/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#endif /* CRYPTO_TYPES_H */

