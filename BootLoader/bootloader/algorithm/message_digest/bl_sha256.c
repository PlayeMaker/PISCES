/******************************************************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any information contained in this doc should not
 *              be reproduced, or used, or disclosed without the written authorization from HiRain Technologies.
 *
 *  \brief      This is a source file of the SHA256 algorithm.
 *
 *  \file       bl_sha256.c
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
#include "bl_common.h"
#include "bl_sha256.h"
#include "sha256.h"

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

/**********************************************************************************************************************
 *  Internal Type Definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Internal Structure Definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Internal Function Declarations
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Internal Variable Definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Global Variable Definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Function Definitions
 *********************************************************************************************************************/
/******************************************************************************************************************//**
 *
 *  \details Initialize the SHA256 algorithm.
 *
 *  \since  6.0.0
 *
 *********************************************************************************************************************/
void SHA256_Init(void)
{

}
mbedtls_sha256_context tempcontext;
/******************************************************************************************************************//**
 *
 *  \details Allocates the context of the SHA256 algorithm.
 *
 *  \return return the pointer of the context.
 *
 *  \since  6.0.0
 *
 *********************************************************************************************************************/
void* SHA256_AllocContext(void)
{
    mbedtls_sha256_context *context = &tempcontext;

    // context = MemP_Alloc(MEMP_TYPE_SHA256_CONTEXT);
    BL_ASSERT(context != BL_NULL_PTR, "");
    mbedtls_sha256_init(context);

    return context;
}

/******************************************************************************************************************//**
 *
 *  \details Frees the context of the SHA256 algorithm.
 *
 *  \param[in]  context - the context of the SHA256 algorithm.
 *
 *  \return None
 *
 *  \since  6.0.0
 *
 *********************************************************************************************************************/
void SHA256_FreeContext(void *context)
{
    BL_ASSERT(context != BL_NULL_PTR, "");

    mbedtls_sha256_free(context);
    // MemP_Free(MEMP_TYPE_SHA256_CONTEXT, context);
}
/******************************************************************************************************************//**
 *
 *  \details Start the SHA256 algorithm.
 *
 *  \param[in]  context - the context of the SHA256 algorithm.
 *
 *  \return None
 *
 *  \since  6.0.0
 *
 *********************************************************************************************************************/
void SHA256_Start(void *context)
{
    BL_ASSERT(context != BL_NULL_PTR, "");

    (void)mbedtls_sha256_starts_ret(context, 0);
}

/******************************************************************************************************************//**
 *
 *  \details Update the SHA256 value.
 *
 *  \param[in]  context - the context of the SHA256 algorithm.
 *  \param[in]  size    - the size of data.
 *  \param[in]  data    - the value of data.
 *
 *  \return If the SHA256 value is calculated successfully return BL_ERR_OK,
 *          otherwise return BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK - the SHA256 value is calculated successfully.
 *  \retval BL_ERR_NOT_OK - the SHA256 value is not calculated successfully.
 *
 *  \since  6.0.0
 *
 *********************************************************************************************************************/
bl_Return_t SHA256_Update(void *context, bl_Size_t size, const bl_Buffer_t *data)
{
    bl_Return_t ret = BL_ERR_NOT_OK;

    BL_ASSERT(context != BL_NULL_PTR, "");

    if (mbedtls_sha256_update_ret(context, data, size) == 0)
    {
        ret = BL_ERR_OK;
    }

    return ret;
}

/******************************************************************************************************************//**
 *
 *  \details Finish the SHA256 algorithm and return its result.
 *
 *  \param[in]  context - the context of the SHA256 algorithm.
 *  \param[in]  size - the size of buffer.
 *  \param[in]  buffer - the SHA256's result.
 *
 *  \return If the SHA256's result is right return BL_ERR_OK, otherwise return
 *          BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK - the SHA256's result is right.
 *  \retval BL_ERR_NOT_OK - the SHA256's result is NOT right.
 *
 *  \since  6.0.0
 *
 *********************************************************************************************************************/
bl_Return_t SHA256_Finish(void *context, bl_Size_t size, bl_Buffer_t *buffer)
{
    bl_Return_t ret = BL_ERR_NOT_OK;

    BL_ASSERT((context != BL_NULL_PTR) && (buffer != BL_NULL_PTR), "");

    if ((size == SECM_SHA256_HASH_LENGTH) && (mbedtls_sha256_finish_ret(context, buffer) == 0))
    {
        ret = BL_ERR_OK;
    }

    return ret;
}
