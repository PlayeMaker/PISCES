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
 * @file mbedtls_config.c
 * @brief 
 * 
 */


#include "mbedtls_config_yuntu.h"

#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#include "memory_buffer_alloc.h"
static unsigned char mbedtls_mem_buf[CRYPTO_ENGINE_BUF_SIZE] = {0};
#endif

#if defined(MBEDTLS_PSA_CRYPTO_EXTERNAL_RNG)
#include <stdlib.h>

/* This function is called by the library when it needs random bytes.
 * It must fill the output buffer with random bytes and return 0 on success.
 * It must return a non-zero value on failure.
 @note TODO:
 */

#endif

void mbedtls_config_init()
{
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
    mbedtls_memory_buffer_alloc_init(mbedtls_mem_buf, CRYPTO_ENGINE_BUF_SIZE);
#endif
}




