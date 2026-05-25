/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Crypto_GeneralTypes.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : Crypto Stack General Header File
*   Author          : Hirain
********************************************************************************
*   Description     : Crypto Stack General Header File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/

/*PRQA S 0778,0779 EOF*/
#ifndef CRYPTO_GENERALTYPES_H
#define CRYPTO_GENERALTYPES_H


#include "Std_types.h"
#include "Rte_Csm_Type.h"

/*******************************************************************************
* MACRO
*******************************************************************************/
/*SWS_Crypto_91018*//*SWS_Csm_91044*/
#define CRYPTO_E_BUSY                      (Crypto_ResultType)0x02                /*The service request failed because the service is still busy.*/
#define CRYPTO_E_ENTROPY_EXHAUSTED         (Crypto_ResultType)0x04                /*The service request failed because the entropy of the random number generator is exhausted.*/
#define CRYPTO_E_KEY_READ_FAIL             (Crypto_ResultType)0x06                /*The service request failed becaus was denied e read access.*/
#define CRYPTO_E_KEY_WRITE_FAIL            (Crypto_ResultType)0x07                /*The service request failed because the writing access failed.*/
#define CRYPTO_E_KEY_NOT_AVAILABLE         (Crypto_ResultType)0x08                /*The service request failed because at least one required key element is not available.*/
#define CRYPTO_E_KEY_NOT_VALID             (Crypto_ResultType)0x09                /*The service request failed because the key is invalid.*/
#define CRYPTO_E_KEY_SIZE_MISMATCH         (Crypto_ResultType)0x0A                /*The service request failed because the key size does not match.*/
#define CRYPTO_E_JOB_CANCELED              (Crypto_ResultType)0x0C                /*The service request failed because the Job has been canceled.*/
#define CRYPTO_E_KEY_EMPTY                 (Crypto_ResultType)0x0D                /*The service request failed because of uninitialized source key.*/

/*******************************************************************************
* ENUMERATED
*******************************************************************************/
/*Crypto_AlgorithmFamilyType [SWS_Csm_01047]*/
typedef enum 
{
    CRYPTO_ALGOFAM_NOT_SET      = 0x00,       /*Algorithm family is not set*/
    CRYPTO_ALGOFAM_SHA1         = 0x01,       /*SHA1 hash*/
    CRYPTO_ALGOFAM_SHA2_224     = 0x02,       /*SHA2-224 hash*/
    CRYPTO_ALGOFAM_SHA2_256     = 0x03,       /*SHA2-256 hash*/
    CRYPTO_ALGOFAM_SHA2_384     = 0x04,       /*SHA2-384 hash*/
    CRYPTO_ALGOFAM_SHA2_512     = 0x05,       /*SHA2-512 hash*/
    CRYPTO_ALGOFAM_SHA2_512_224 = 0x06,       /*SHA2-512/224 hash*/
    CRYPTO_ALGOFAM_SHA2_512_256 = 0x07,       /*SHA2-512/256 hash*/
    CRYPTO_ALGOFAM_SHA3_224     = 0x08,       /*SHA3-224 hash*/
    CRYPTO_ALGOFAM_SHA3_256     = 0x09,       /*SHA3-256 hash*/
    CRYPTO_ALGOFAM_SHA3_384     = 0x0a,       /*SHA3-384 hash*/
    CRYPTO_ALGOFAM_SHA3_512     = 0x0b,       /*SHA3-512 hash*/
    CRYPTO_ALGOFAM_SHAKE128     = 0x0c,       /*SHAKE128 hash*/
    CRYPTO_ALGOFAM_SHAKE256     = 0x0d,       /*SHAKE256 hash*/
    CRYPTO_ALGOFAM_RIPEMD160    = 0x0e,       /*RIPEMD hash*/
    CRYPTO_ALGOFAM_BLAKE_1_256  = 0x0f,       /*BLAKE-1-256 hash*/
    CRYPTO_ALGOFAM_BLAKE_1_512  = 0x10,       /*BLAKE-1-512 hash*/
    CRYPTO_ALGOFAM_BLAKE_2s_256 = 0x11,       /*BLAKE-2s-256 hash*/
    CRYPTO_ALGOFAM_BLAKE_2s_512 = 0x12,       /*BLAKE-2s-512 hash*/
    CRYPTO_ALGOFAM_3DES         = 0x13,       /*3DES cipher*/
    CRYPTO_ALGOFAM_AES          = 0x14,       /*AES cipher*/
    CRYPTO_ALGOFAM_CHACHA       = 0x15,       /*ChaCha cipher*/
    CRYPTO_ALGOFAM_RSA          = 0x16,       /*RSA cipher*/
    CRYPTO_ALGOFAM_ED25519      = 0x17,       /*ED22518 elliptic curve*/
    CRYPTO_ALGOFAM_BRAINPOOL    = 0x18,       /*Brainpool elliptic curve*/
    CRYPTO_ALGOFAM_ECCNIST      = 0x19,       /*NIST ECC elliptic curves*/

    CRYPTO_ALGOFAM_RNG          = 0x1b,       /*Random Number Generator*/
    CRYPTO_ALGOFAM_SIPHASH      = 0x1c,       /*SipHash*/
    CRYPTO_ALGOFAM_ECIES        = 0x1d,       /*ECIES Cipher*/
    CRYPTO_ALGOFAM_ECCANSI      = 0x1e,       /*Elliptic curve according to ANSI X9.62*/
    CRYPTO_ALGOFAM_ECCSEC       = 0x1f,       /*Elliptic curve according to SECG*/
    CRYPTO_ALGOFAM_DRBG         = 0x20,       /*Random number generator according to NIST SP800-90A*/
    CRYPTO_ALGOFAM_FIPS186      = 0x21,       /*Random number generator according to FIPS 186*/
    CRYPTO_ALGOFAM_PADDING_PKCS7= 0x22,       /*Cipher padding according to PKCS.7*/
    CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS =0x23,/*Cipher padding mode. Fill/verify data with 0, but first bit after the data is 1. Eg. "DATA" & 0x80 & 0x00...*/
    CRYPTO_ALGOFAM_PBKDF2       = 0x24,       /*Password-Based Key Derivation Function 2*/
    CRYPTO_ALGOFAM_KDFX963      = 0x25,       /*ANSI X9.63 Public Key Cryptography*/
    CRYPTO_ALGOFAM_DH           = 0x26,       /*Diffie-Hellman*/
    CRYPTO_ALGOFAM_SM2          = 0x27,       /*SM2 elliptic curve algorithm*/
    CRYPTO_ALGOFAM_EEA3         = 0x28,       /*Stream cipher based on [x01]*/
    CRYPTO_ALGOFAM_SM3          = 0x29,       /*Chinese hash algorithm based on [x02]*/
    CRYPTO_ALGOFAM_EIA3         = 0x2A,       /*Authentication algorithm [x01]*/
    CRYPTO_ALGOFAM_HKDF         = 0x2B,       /* HMAC-based extract-and-expand key derivation function*/
    CRYPTO_ALGOFAM_ECDSA        = 0x2C,       /*Elliptic-curve Digital Signatures*/
    CRYPTO_ALGOFAM_POLY1305     = 0x2D,       /*Elliptic curve X25519 for ECDH*/    
    CRYPTO_ALGOFAM_X25519       = 0x2E,       /*Elliptic-curve Diffie Hellman*/
    CRYPTO_ALGOFAM_ECDH         = 0x2F,       /*Custom algorithm family*/


    CRYPTO_ALGOFAM_CUSTOM       = 0xff        /*Custom algorithm family*/

}Crypto_AlgorithmFamilyType;


/*Crypto_AlgorithmModeType  [SWS_Csm_01048]*/
typedef enum 
{
    CRYPTO_ALGOMODE_NOT_SET     =0x00,        /*Algorithm key is not set*/
    CRYPTO_ALGOMODE_ECB         =0x01,        /*Block mode: Electronic Code Book*/
    CRYPTO_ALGOMODE_CBC         =0x02,        /*Block mode: Cipher Block Chaining*/
    CRYPTO_ALGOMODE_CFB         =0x03,        /*Block mode: Cipher Feedback Mode*/
    CRYPTO_ALGOMODE_OFB         =0x04,        /*Block mode: Output Feedback Mode*/
    CRYPTO_ALGOMODE_CTR         =0x05,        /*Block mode: Counter Mode*/
    CRYPTO_ALGOMODE_GCM         =0x06,        /*Block mode: Galois/Counter Mode*/
    CRYPTO_ALGOMODE_XTS         =0x07,        /*XOR-encryption-based tweaked-code book mode with cipher text stealing*/
    CRYPTO_ALGOMODE_RSAES_OAEP  =0x08,        /*RSA Optimal Asymmetric Encryption Padding*/
    CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5 =0x09,   /*RSA encryption/decryption with PKCS#1 v1.5 padding*/
    CRYPTO_ALGOMODE_RSASSA_PSS  =0x0a,        /*RSA Probabilistic Signature Scheme*/
    CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5=0x0b,   /*RSA signature with PKCS#1 v1.5*/
    CRYPTO_ALGOMODE_8ROUNDS     =0x0c,        /*8 rounds (e.g. ChaCha8)*/
    CRYPTO_ALGOMODE_12ROUNDS    =0x0d,        /*12 rounds (e.g. ChaCha12)*/
    CRYPTO_ALGOMODE_20ROUNDS    =0x0e,        /*20 rounds (e.g. ChaCha20)*/
    CRYPTO_ALGOMODE_HMAC        =0x0f,        /*Hashed-based MAC*/
    CRYPTO_ALGOMODE_CMAC        =0x10,        /*Cipher-based MAC*/
    CRYPTO_ALGOMODE_GMAC        =0x11,        /*Galois MAC*/
    CRYPTO_ALGOMODE_CTRDRBG     =0x12,        /*Counter-based Deterministic Random Bit Generator*/
    CRYPTO_ALGOMODE_SIPHASH_2_4 =0x13,        /*Siphash-2-4*/
    CRYPTO_ALGOMODE_SIPHASH_4_8 =0x14,        /*Siphash-4-8*/
    CRYPTO_ALGOMODE_PXXXR1      =0x15,        /*ANSI R1 Curve*/
    CRYPTO_ALGOMODE_CUSTOM      =0xff         /*Custom algorithm mode*/
} Crypto_AlgorithmModeType;

/*Crypto_JobStateType [SWS_Csm_01028]*/
typedef enum 
{
    CRYPTO_JOBSTATE_IDLE    = 0x00,  /*Job is in the state "idle". This state is reached after Csm_Init() or when the "Finish" state is finished.*/
    CRYPTO_JOBSTATE_ACTIVE  = 0x01   /*Job is in the state "active". There was already some input or there are intermediate results. This state is \
                                     reached, when the "update" or "start" operation finishes.*/
}Crypto_JobStateType;                /*current job state.*/

/*Crypto_ServiceInfoType [SWS_Csm_01031]*/
typedef enum
{
    CRYPTO_HASH                   = 0x00,
    CRYPTO_MACGENERATE            = 0x01,
    CRYPTO_MACVERIFY              = 0x02,
    CRYPTO_ENCRYPT                = 0x03,
    CRYPTO_DECRYPT                = 0x04,
    CRYPTO_AEADENCRYPT            = 0x05,
    CRYPTO_AEADDECRYPT            = 0x06,
    CRYPTO_SIGNATUREGENERATE      = 0x07,
    CRYPTO_SIGNATUREVERIFY        = 0x08,
    CRYPTO_RANDOMGENERATE         = 0x0B,

    CRYPTO_RANDOMSEED             = 0x0C,
    CRYPTO_KEYGENERATE            = 0x0D,
    CRYPTO_KEYDERIVE              = 0x0E,
    CRYPTO_KEYEXCHANGECALCPUBVAL  = 0x0F,
    CRYPTO_KEYEXCHANGECALCSECRET  = 0x10,

    CRYPTO_KEYSETVALID            = 0x13,
    CRYPTO_KEYSETINVALID          = 0x14

} Crypto_ServiceInfoType;



/*Crypto_ProcessingType [SWS_Csm_01049]*/
/*description:Enumeration of the processing type*/
typedef enum
{
    CRYPTO_PROCESSING_ASYNC  = 0x01,               /*Asynchronous job processing*/
    CRYPTO_PROCESSING_SYNC   = 0x02              /*Synchronous job processing*/
}Crypto_ProcessingType;


/*SWS_Csm_91024*/
typedef enum
{
    CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT     = 0x01,
    CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT   = 0x02,
    CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT    = 0x04,
    CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT    = 0x10,
    CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT  = 0x20

}Crypto_InputOutputRedirectionConfigType;

typedef enum
{
    CRYPTO_KE_FORMAT_BIN_OCTET                  = 1,
    CRYPTO_KE_FORMAT_BIN_SHEKEYS                = 2,
    CRYPTO_KE_FORMAT_BIN_IDENT_PRIVATEKEY_PKCS8 = 3,
    CRYPTO_KE_FORMAT_BIN_IDENT_PUBLICKEY        = 4,
    CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY         = 5,
    CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY          = 6

}Crypto_KeyElementFormatType;

typedef enum
{
    CRYPTO_KE_MAC_KEY                          = 1,
    CRYPTO_KE_MAC_PROOF                        = 2,
    CRYPTO_KE_KEYGENERATE_SEED                = 16,

    CRYPTO_KE_SIGNATURE_KEY                    = 1,
    CRYPTO_KE_SIGNATURE_CURVETYPE              = 29,

    CRYPTO_KE_RANDOM_SEED_STATE                = 3,
    CRYPTO_KE_RAMDOM_ALGORITHM                 = 4,    

    CRYPTO_KE_CIPHER_KEY                       = 1,
    CRYPTO_KE_CIPHER_PROOF                     = 2,
    CRYPTO_KE_CIPHER_IV                        = 5,  
    CRYPTO_KE_CIPHER_2NDKEY                    = 7,

    CRYPTO_KE_KEYEXCHANGE_BASE                = 8,
    CRYPTO_KE_KEYEXCHANGE_PRIVKEY             = 9,
    CRYPTO_KE_KEYEXCHANGE_OWNPUBKEY           = 10,
    CRYPTO_KE_KEYEXCHANGE_SHAREDVALUE        = 1,
    CRYPTO_KE_KEYEXCHANGE_ALGORITHM           = 12,
    CRYPTO_KE_KEYEXCHANGE_CURVETYPE           = 29,

    CRYPTO_KE_KEYDERIVATION_PASSWORD          = 1,
    CRYPTO_KE_KEYDERIVATION_SALT               = 13,
    CRYPTO_KE_KEYDERIVATION_ITERATIONS        = 14,
    CRYPTO_KE_KEYDERIVATION_ALGORITHM         = 15,
    CRYPTO_KE_KEYDERIVATION_CURVETYPE          = 29,

    CRYPTO_KE_KEYGENERATE_KEY                 = 1,

    CRYPTO_KE_KEYGENERATE_ALGORITHM           = 17,
    CRYPTO_KE_KEYGENERATE_CURVETYPE            = 29
         
}Crypto_KeyElementAttributType;



/*******************************************************************************
* STRUCTURE TYPE
*******************************************************************************/

/*Crypto_AlgorithmInfoType [SWS_Csm_01008]*/
/*description:Structure which determines the exact algorithm. \
Note, not every algorithm needs to specify all fields. AUTOSAR shall only allow valid combinations.
*/
typedef struct
{
    Crypto_AlgorithmFamilyType family;           /*The family of the algorithm*/
    Crypto_AlgorithmFamilyType secondaryFamily;  /*The secondary family of the algorithm*/
    uint32                     keyLength;        /*The key length in bits to be used with that algorithm*/
    Crypto_AlgorithmModeType   mode;             /*The operation mode to be used with that algorithm*/

}Crypto_AlgorithmInfoType;

/*Crypto_PrimitiveInfoType [SWS_Csm_01011]*/
/*ECUC_Csm_00006*/
typedef struct
{
    const Crypto_ServiceInfoType service;      /*Contains the enum of the used service, e.g. Encrypt*/
    const Crypto_AlgorithmInfoType algorithm;  /*Contains the information of the used algorithm*/
}Crypto_PrimitiveInfoType;

/*Crypto_JobPrimitiveInputOutputType [SWS_Csm_01009]*/
/*description:Structure which contains input and output information depending on the job and the crypto primitive.*/
typedef struct
{
    const uint8*            inputPtr;         /*Pointer to the input data*/
    uint32               inputLength;         /*Contains the input length in bytes*/
    const uint8*   secondaryInputPtr;         /*Pointer to the secondary input data (for MacVerify, SignatureVerify)*/
    uint32      secondaryInputLength;         /*Contains the secondary input length in bytes*/
    const uint8*    tertiaryInputPtr;         /*Pointer to the tertiary input data (for MacVerify, SignatureVerify)*/
    uint32       tertiaryInputLength;         /*Contains the tertiary input length in bytes*/

    uint8*           outputPtr;         /*Pointer to the output data*/
    uint32*          outputLengthPtr;         /*Holds a pointer to a memory location containing the output length in bytes*/
    uint8*  secondaryOutputPtr;         /*Pointer to the secondary output data*/
    uint32* secondaryOutputLengthPtr;         /*Holds a pointer to a memory location containing the secondary output length in bytes*/

    Crypto_VerifyResultType*   verifyPtr;     /*Output pointer to a memory location holding a Crypto_VerifyResultType*/
    Crypto_OperationModeType    mode;         /*Indicator of the mode(s)/operation(s) to be performed*/
    uint32                cryIfKeyId;         /*Holds the CryIf key id for key operation services*/
    uint32          targetCryIfKeyId;         /*Holds the target CryIf key id for key operation services*/
    
}Crypto_JobPrimitiveInputOutputType;


/*Crypto_JobPrimitiveInfoType [SWS_Csm_01012]*/
/*description:Structure which contains further information, which depends on the job and the crypto primitive
*/
typedef struct 
{
    /*ECUC_Csm_00122*/
    const uint32                    callbackId;       /*Identifier of the callback function, to be called, if the configured service finished.*/
    /*ECUC_Csm_00122*/
    const Crypto_PrimitiveInfoType* primitiveInfo;    /*Pointer to a structure containing further configuration of the crypto primitives*/
    /*ECUC_Csm_00126*/
    uint32                          cryIfKeyId;       /*Identifier of the CryIf key*/
    /*ECUC_Csm_00276*/
    const Crypto_ProcessingType     processingType;   /*Determines the synchronous or asynchronous behavior*/
    
}Crypto_JobPrimitiveInfoType;



/*Crypto_JobRedirectionInfoType [SWS_Csm_91026]*/
/*dscription:Structure which holds the identifiers of the keys and key elements \
which shall be used as input and output for a job and a bit structure \
which indicates which buffers shall be redirected to those key elements.
*/
/*ECUC_Csm_00263*/
typedef struct 
{
    uint8  redirectionConfig;           /*Bit structure which indicates which buffer shall be redirected to a key element.\
                                        Values from Crypto_InputOutputRedirectionConfigType can be used and combined with unary OR operation.*/
    uint32 inputKeyId;                  /*Identifier of the key which shall be used as input*/
    uint32 inputKeyElementId;           /*Identifier of the key element which shall be used as input*/
    uint32 secondaryInputKeyId;         /*Identifier of the key which shall be used as secondary input*/
    uint32 secondaryInputKeyElementId;  /*Identifier of the key element which shall be used as secondary input*/
    uint32 tertiaryInputKeyId;          /*Identifier of the key which shall be used as tertiary input*/
    uint32 tertiaryInputKeyElementId;   /*Identifier of the key element which shall be used as tertiary input*/
    uint32 outputKeyId;                 /*Identifier of the key which shall be used as output*/
    uint32 outputKeyElementId;          /*Identifier of the key element which shall be used as output*/
    uint32 secondaryOutputKeyId;        /*Identifier of the key which shall be used as secondary output*/
    uint32 secondaryOutputKeyElementId; /*Identifier of the key element which shall be used as secondary output*/

}Crypto_JobRedirectionInfoType;

/*Crypto_JobStateType [SWS_Csm_01013]*/
/*description:Structure which contains further information, \
which depends on the job and the crypto primitive.*/
typedef struct
{
    /*ECUC_Csm_00119*/
    uint32 jobId;                                              /*Identifier for the job structure*/
    Crypto_JobStateType jobState;                                  /*Determines the current job state*/
    Crypto_JobPrimitiveInputOutputType jobPrimitiveInputOutput;    /*Structure containing input and output information depending on the job and the crypto primitive*/
    const Crypto_JobPrimitiveInfoType* jobPrimitiveInfo;           /*Pointer to a structure containing further information which depends on the job and the crypto primitive.*/
    Crypto_JobRedirectionInfoType* jobRedirectionInfoRef;     /*Pointer to a structure containing further information on the usage of keys as input and output for jobs.*/

    uint32 cryptoKeyId;   
    uint32 targetCryptoKeyId;  
    const uint32 jobPriority;

}Crypto_JobType;





#endif/*CRYPTO_GENERALTYPES_H*/
