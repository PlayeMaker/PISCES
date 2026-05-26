/*
 *  Copyright 2020-2024 Yuntu Microelectronics co.,ltd
 *  All rights reserved.
 * 
 *  YUNTU Confidential. This software is owned or controlled by YUNTU and may only be
 *  used strictly in accordance with the applicable license terms. By expressly
 *  accepting such terms or by downloading, installing, activating and/or otherwise
 *  using the software, you are agreeing that you have read, and that you agree to
 *  comply with and are bound by, such license terms. If you do not agree to be
 *  bound by the applicable license terms, then you may not retain, install,
 *  activate or otherwise use the software. The production use license in
 *  Section 2.3 is expressly granted for this software.
 * 
 * @file mbedtls_config_yuntu.h
 * @brief 
 * 
 */




#ifndef MBEDTLS_CONFIG_YUNTU_H
#define MBEDTLS_CONFIG_YUNTU_H



#define MBEDTLS_PLATFORM_C 
#define MBEDTLS_PLATFORM_MEMORY
#define MBEDTLS_PLATFORM_NO_STD_FUNCTIONS
#define MBEDTLS_PLATFORM_EXIT_MACRO   (void)
// Memory configuration
#define MBEDTLS_MEMORY_BUFFER_ALLOC_C 
#define CRYPTO_ENGINE_BUF_SIZE   0x3800

// Normal 
#define MBEDTLS_BIGNUM_C


// Symmetric encryption configuration
#define MBEDTLS_AES_C
#define MBEDTLS_CIPHER_C
#define MBEDTLS_CIPHER_MODE_CBC

// Custom defines

//RSA
#define MBEDTLS_RSA_C
#define MBEDTLS_OID_C
#define MBEDTLS_PLATFORM_SNPRINTF_MACRO   printf
#define MBEDTLS_SHA256_C
#define MBEDTLS_CIPHER_MODE_CTR
#define MBEDTLS_PKCS1_V15
// #define MBEDTLS_ASN1_PARSE_C
// #define MBEDTLS_ASN1_WRITE_C
#define MBEDTLS_HMAC_DRBG_C
#define MBEDTLS_MD_C
// #define MBEDTLS_PEM_WRITE_C
// #define MBEDTLS_BASE64_C
#define MBEDTLS_GENPRIME
#define MBEDTLS_CTR_DRBG_C
// #define MBEDTLS_PEM_PARSE_C
#define MBEDTLS_PK_C
#define MBEDTLS_PK_PARSE_C
#define MBEDTLS_PK_WRITE_C

// PSA
// #define MBEDTLS_USE_PSA_CRYPTO 
// #define MBEDTLS_PSA_CRYPTO_CLIENT

// // Enable external RNG for PSA
#define MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG

// // PSA API Configuration
#define MBEDTLS_PSA_CRYPTO_C

// // PSA Key Type Support
// #define MBEDTLS_PSA_KEY_TYPE_AES_SUPPORT


extern void mbedtls_config_init();

#endif