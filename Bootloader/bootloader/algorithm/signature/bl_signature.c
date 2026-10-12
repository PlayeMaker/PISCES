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
    0x9A, 0x1F, 0x3B, 0x83, 0xDE, 0x5A, 0xEC, 0x8A, 0x0C, 0xCE, 0x1F, 0xAF, 0x7A, 0xFC, 0x93, 0x16,
	0x97, 0x55, 0x75, 0x2C, 0x5F, 0xA9, 0x4D, 0xCE, 0xC1, 0x82, 0x8E, 0xE9, 0x58, 0x34, 0xA1, 0x4E,
	0xB4, 0x76, 0x52, 0x0F, 0x07, 0x61, 0xED, 0x7E, 0x3A, 0x36, 0x4D, 0xE1, 0xB4, 0x7F, 0x88, 0xF1,
	0xEF, 0xE1, 0x2C, 0x99, 0x92, 0x54, 0x09, 0x56, 0x0F, 0x4A, 0xFB, 0x80, 0xA6, 0x30, 0x1B, 0xFF,
	0x4B, 0xEE, 0xF6, 0xF9, 0x21, 0xFF, 0x40, 0xA7, 0xDE, 0xE7, 0x1B, 0x57, 0x49, 0x32, 0xCD, 0x09,
	0xF4, 0x89, 0x3F, 0xFA, 0x1F, 0xE1, 0x92, 0x2A, 0x35, 0xC4, 0xE4, 0xA3, 0xB2, 0x34, 0x79, 0x31,
	0xA8, 0x4F, 0x18, 0x37, 0x7A, 0xF3, 0x26, 0xB7, 0xBC, 0x71, 0xA9, 0x2E, 0x54, 0xF8, 0x5D, 0x9D,
	0xB7, 0x10, 0xF8, 0xC7, 0x81, 0xD0, 0x67, 0x07, 0x08, 0xC1, 0xE3, 0xFF, 0xD5, 0x5D, 0x88, 0x16,
	0x4A, 0x2A, 0x34, 0x27, 0x19, 0x6E, 0x84, 0xB2, 0x45, 0x6B, 0xA2, 0x7C, 0xF8, 0x50, 0x3F, 0x7F,
	0xBE, 0x13, 0xC3, 0xC7, 0x1D, 0xF7, 0xA3, 0x81, 0x6D, 0x76, 0xA5, 0x11, 0x0D, 0x55, 0x5F, 0x4A,
	0xE0, 0x63, 0x25, 0x72, 0xB6, 0x78, 0x8B, 0xEE, 0xBB, 0x1B, 0xB8, 0x90, 0x9E, 0xCD, 0xA0, 0x61,
	0x57, 0x2D, 0x31, 0x14, 0xFE, 0x75, 0x5D, 0xDD, 0xEC, 0xDC, 0x42, 0xF0, 0x1C, 0x74, 0x11, 0xDA,
	0xC1, 0x99, 0x56, 0x87, 0x60, 0x8C, 0x0B, 0x50, 0x4C, 0x19, 0x16, 0x7A, 0x5A, 0x03, 0xAB, 0xD8,
	0xD3, 0xEC, 0xCF, 0xE7, 0x12, 0xDF, 0x9B, 0x8C, 0x83, 0x0E, 0x89, 0x35, 0x35, 0xA1, 0xD2, 0x79,
	0x6C, 0xDF, 0x11, 0xA6, 0xEC, 0x86, 0x49, 0x65, 0x7E, 0x41, 0x7B, 0x8C, 0xCD, 0x4C, 0x9B, 0x69,
	0x6D, 0xEC, 0xA9, 0xAC, 0x95, 0x8D, 0xCF, 0xD6, 0x43, 0x5C, 0x46, 0x79, 0x96, 0x07, 0x9B, 0x0B,
	0xEA, 0xF4, 0x08, 0x14, 0x5A, 0x7C, 0x60, 0x95, 0x98, 0xBC, 0x72, 0x40, 0x6A, 0x29, 0x8A, 0xE7,
	0x16, 0x6C, 0x8B, 0x00, 0xD7, 0x1D, 0xB5, 0xB9, 0x3A, 0x2A, 0x0C, 0x34, 0x91, 0x9D, 0x02, 0xFF,
	0x47, 0xD9, 0x1F, 0xD6, 0xFE, 0xDA, 0x00, 0xFD, 0x5F, 0x0E, 0x1B, 0xB3, 0xC6, 0xA7, 0x57, 0x92,
	0x47, 0xD4, 0x7E, 0x52, 0x42, 0x5E, 0xCA, 0xF2, 0x9D, 0xF9, 0x86, 0x7C, 0x6D, 0x46, 0x9D, 0x6A,
	0x3D, 0x62, 0x83, 0xF8, 0x83, 0xD4, 0xD9, 0x35, 0x2D, 0xF6, 0xCA, 0x66, 0x6E, 0xC1, 0x38, 0x80,
	0xC7, 0x5F, 0x00, 0x9A, 0x18, 0x8F, 0x69, 0x4E, 0xA1, 0x03, 0x50, 0x29, 0x0B, 0x4B, 0x34, 0xF5,
	0x05, 0xA0, 0x85, 0xB8, 0xAB, 0x90, 0xC2, 0x0C, 0x2C, 0x2E, 0xF9, 0x0E, 0xE2, 0x8C, 0xD9, 0x83,
	0xC0, 0xEC, 0x12, 0xC4, 0x1C, 0xA8, 0x42, 0x0A, 0x4B, 0x70, 0x4C, 0x8F, 0x42, 0x04, 0xDE, 0x01,
	/*E*/
	0x00, 0x01, 0x00, 0x01,
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
