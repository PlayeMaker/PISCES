/******************************************************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any information contained in this doc should not
 *              be reproduced, or used, or disclosed without the written authorization from HiRain Technologies.
 *
 *  \brief      This is a source file of the signature algorithm.
 *
 *  \file       bl_signature.c
 *
 *  \author     Tang, Mingqing <mingqing.tang@hirain.com>
 *
 *  \version    6.1.0
 *  \date       16/01/2019
 *
 *  \par        Changelist
 *              Version  | Date       | Authors          | Descriptions
 *              -------- | ---------- | ---------------- | -----------------------
 *              6.0.0    | 07/09/2018 | Tang, Mingqing   | The first version using the new architecture.
 *              6.0.1    | 02/11/2018 | Tang, Mingqing   | Porting SHA-256 algorithm for checking integrity of data.
 *              6.1.0    | 16/01/2019 | Tang, Mingqing   | Implement digital signature and LZSS algorithm.
 *
 *********************************************************************************************************************/
#include "bl_signature.h"
#include "bl_signature_cfg.h"
#include "bl_security.h"
#include "bl_memory.h"
#include "bl_common.h"
#include "rsa.h"
#include "bl_data.h"
#include "mbedtls_config.h"

/**********************************************************************************************************************
 *  QAC Suppression
 *********************************************************************************************************************/
/*PRQA S EOF*/

/**********************************************************************************************************************
 *  Verify The Configurations of Macro
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Internal Macro Definitions
 *********************************************************************************************************************/
#define SIGN_PUBLICKEY_TYPE_NONE        (0)
#define SIGN_PUBLICKEY_TYPE_DEV         (1)
#define SIGN_PUBLICKEY_TYPE_PRODUCT     (2)

/**********************************************************************************************************************
 *  Internal Type Definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Internal Structure Definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Internal Function Declarations
 *********************************************************************************************************************/
// static bl_Return_t Sign__CheckPublicKeyHash(const bl_Buffer_t *key);

static bl_Return_t Sign__UpdatePublicKey(const bl_Buffer_t *key);
/**********************************************************************************************************************
 *  Internal Variable Definitions
 *********************************************************************************************************************/
static mbedtls_rsa_context gs_signature;

static bl_u8_t gs_PublicKeyType;

static const bl_Buffer_t gs_DevPublicKey[SIGN_PKEY_LENGTH] =
{
    /*N*/
    0x9a, 0x1f, 0x3b, 0x83, 0xde, 0x5a, 0xec, 0x8a, 0x0c, 0xce, 0x1f, 0xaf, 0x7a, 0xfc, 0x93, 0x16,
    0x97, 0x55, 0x75, 0x2c, 0x5f, 0xa9, 0x4d, 0xce, 0xc1, 0x82, 0x8e, 0xe9, 0x58, 0x34, 0xa1, 0x4e,
    0xb4, 0x76, 0x52, 0x0f, 0x07, 0x61, 0xed, 0x7e, 0x3a, 0x36, 0x4d, 0xe1, 0xb4, 0x7f, 0x88, 0xf1,
    0xef, 0xe1, 0x2c, 0x99, 0x92, 0x54, 0x09, 0x56, 0x0f, 0x4a, 0xfb, 0x80, 0xa6, 0x30, 0x1b, 0xff,
    0x4b, 0xee, 0xf6, 0xf9, 0x21, 0xff, 0x40, 0xa7, 0xde, 0xe7, 0x1b, 0x57, 0x49, 0x32, 0xcd, 0x09,
    0xf4, 0x89, 0x3f, 0xfa, 0x1f, 0xe1, 0x92, 0xa3, 0x5c, 0x4e, 0x4a, 0x3b, 0x23, 0x47, 0x93, 0x1a,
    0x84, 0xf1, 0x83, 0x77, 0xaf, 0x32, 0x6b, 0x7b, 0xc7, 0x1a, 0x92, 0xe5, 0x4f, 0x85, 0xd9, 0xdb,
    0x71, 0x0f, 0x8c, 0x78, 0x1d, 0x06, 0x70, 0x70, 0x8c, 0x1e, 0x3f, 0xfd, 0x55, 0xd8, 0x81, 0x64,
    0xa2, 0xa3, 0x42, 0x71, 0x96, 0xe8, 0x4b, 0x24, 0x56, 0xba, 0x27, 0xcf, 0x85, 0x03, 0xf7, 0xfb,
    0xe1, 0x3c, 0x3c, 0x71, 0xdf, 0x7a, 0x38, 0x16, 0xd7, 0x6a, 0x51, 0x10, 0xd5, 0x55, 0xf4, 0xae,
    0x06, 0x32, 0x57, 0x2b, 0x67, 0x88, 0xbe, 0xbb, 0xb1, 0xbb, 0x89, 0x09, 0xec, 0xda, 0x06, 0x15,
    0x72, 0xd3, 0x11, 0x4f, 0xe7, 0x55, 0xdd, 0xde, 0xcd, 0xc4, 0x2f, 0x01, 0xc7, 0x41, 0x1d, 0xac,
    0x19, 0x95, 0x68, 0x76, 0x08, 0xc0, 0xb5, 0x04, 0xc1, 0x91, 0x67, 0xa5, 0xa0, 0x3a, 0xbd, 0x8d,
    0x3e, 0xcc, 0xfe, 0x71, 0x2d, 0xf9, 0xb8, 0xc8, 0x30, 0xe8, 0x93, 0x53, 0x5a, 0x1d, 0x27, 0x96,
    0xcd, 0xf1, 0x1a, 0x6e, 0xc8, 0x64, 0x96, 0x57, 0xe4, 0x17, 0xb8, 0xcc, 0xd4, 0xc9, 0xb6, 0x96,
    0xde, 0xca, 0x9a, 0xc9, 0x58, 0xdc, 0xfd, 0x64, 0x35, 0xc4, 0x67, 0x99, 0x60, 0x79, 0xb0, 0xbe,
    0xaf, 0x40, 0x81, 0x45, 0xa7, 0xc6, 0x09, 0x59, 0x8b, 0xc7, 0x24, 0x06, 0xa2, 0x98, 0xae, 0x71,
    0x66, 0xc8, 0xb0, 0x0d, 0x71, 0xdb, 0x5b, 0x93, 0xa2, 0xa0, 0xc3, 0x49, 0x19, 0xd0, 0x2f, 0xf4,
    0x7d, 0x91, 0xfd, 0x6f, 0xed, 0xa0, 0x0f, 0xd5, 0xf0, 0xe1, 0xbb, 0x3c, 0x6a, 0x75, 0x79, 0x24,
    0x7d, 0x47, 0xe5, 0x24, 0x25, 0xec, 0xaf, 0x29, 0xdf, 0x98, 0x67, 0xc6, 0xd4, 0x69, 0xd6, 0xa3,
    0xd6, 0x28, 0x3f, 0x88, 0x3d, 0x4d, 0x93, 0x52, 0xdf, 0x6c, 0xa6, 0x66, 0xec, 0x13, 0x88, 0x0c,
    0x75, 0xf0, 0x09, 0xa1, 0x88, 0xf6, 0x94, 0xea, 0x10, 0x35, 0x02, 0x90, 0xb4, 0xb3, 0x4f, 0x50,
    0x5a, 0x08, 0x5b, 0x8a, 0xb9, 0x0c, 0x20, 0xc2, 0xc2, 0xef, 0x90, 0xee, 0x28, 0xcd, 0x98, 0x3c,
    0x0e, 0xc1, 0x2c, 0x41, 0xca, 0x84, 0x20, 0xa4, 0xb7, 0x04, 0xc8, 0xf4, 0x20, 0x4d, 0xe0, 0x01,
    /*E*/
    0x00, 0x01, 0x00, 0x01,/*最后4字节表示什么意思zsd*/
};

/**********************************************************************************************************************
 *  Global Variable Definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Function Definitions
 *********************************************************************************************************************/

/******************************************************************************************************************//**
 *
 *  \details Initialize the signature algorithm.
 *
 *  \since  6.0.0
 *
 *********************************************************************************************************************/
void Sign_Init(void)
{

    mbedtls_config_init();
    mbedtls_rsa_init(&gs_signature, MBEDTLS_RSA_PKCS_V21, MBEDTLS_MD_SHA256);

    /*the dev key is always valid.*/
    (void)Sign__UpdatePublicKey(gs_DevPublicKey);
    gs_PublicKeyType = SIGN_PUBLICKEY_TYPE_DEV;

}

/******************************************************************************************************************//**
 *
 *  \details Verify the signature.
 *
 *  \param[in]  id          - the id of HASH algorithm.
 *  \param[in]  hashSize    - the size of HASH.
 *  \param[in]  hash        - the hash
 *  \param[in]  signSize    - the size of signature
 *  \param[in]  signature   - the signature
 *
 *  \return If the signature is right return BL_ERR_OK otherwise returns BL_ERR_NOT_OK.
 *
 *  \since  6.0.0
 *
 *********************************************************************************************************************/
bl_Return_t Sign_VerifySignature(bl_HashId_t id, bl_Size_t hashSize, const bl_Buffer_t *hash,
                                    bl_Size_t signSize, const bl_Buffer_t *signature)
{
    bl_Return_t ret;
    bl_u32_t size = mbedtls_rsa_get_len(&gs_signature);
    int result;

    if ((id != SECM_HASH_SHA256) || (size != signSize) || (SIGN_PUBLICKEY_TYPE_NONE == gs_PublicKeyType))
    {
       ret = BL_ERR_NOT_OK;
    }
    else
    {
        result = mbedtls_rsa_rsassa_pss_verify(&gs_signature, BL_NULL_PTR, BL_NULL_PTR,
                                                MBEDTLS_RSA_PUBLIC, MBEDTLS_MD_SHA256,
                                                hashSize, 
                                                (const unsigned char *)hash, 
                                                (const unsigned char *)signature );

        if (result != 0)
        {
            ret = BL_ERR_NOT_OK;
        }
        else
        {
            ret = BL_ERR_OK;
        }
    }

    return ret;
}

/******************************************************************************************************************//**
 *
 *  \details Update the public key.
 *
 *  \param[in]  key - the public key
 *
 *  \return if the key is a valid public key returns BL_ERR_OK, otherwise returns BL_ERR_NOT_OK.
 *
 *  \since  6.0.0
 *
 *********************************************************************************************************************/
static bl_Return_t Sign__UpdatePublicKey(const bl_Buffer_t *key)
{
    bl_Return_t ret = BL_ERR_OK;

    mbedtls_rsa_import_raw(&gs_signature, key, SIGN_PKEY_N_LENGTH,
                            BL_NULL_PTR, 0,
                            BL_NULL_PTR, 0,
                            BL_NULL_PTR, 0,
                            &key[SIGN_PKEY_N_LENGTH], SIGN_PKEY_E_LENGTH);

    if (mbedtls_rsa_check_pubkey(&gs_signature) != 0)
    {
        mbedtls_rsa_free(&gs_signature);
        ret = BL_ERR_NOT_OK;
    }

    return ret;
}
