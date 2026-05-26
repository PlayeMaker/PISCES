/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is the source file of the security manager module.
 *
 *  \file       bl_security.c
 *  \ingroup    security_manager_module
 *  \author     xin.shang <xin.shang@hirain.com>
 *              mingqing.tang <mingqing.tang@hirain.com>
 *
 *  \version    5.7.0
 *  \date       25/06/2021
 *
 *  \par        Changelist
 *      Version  | Date       | Authors          | CR# | Descriptions
 *      -------- | ---------- | ---------------- | --- | ------------
 *      01.00.00 | 25/03/2010 | hewei.zhang      | N/A | Boot010001
 *      01.01.00 | 19/05/2010 | hewei.zhang      | N/A | Boot010002
 *      02.00.00 | 18/05/2011 | mingqing.tang    | N/A | Boot020001
 *      02.01.00 | 15/06/2011 | mingqing.tang    | N/A | Boot020002
 *      02.05.00 | 22/06/2011 | mingqing.tang    | N/A | Boot020006
 *      05.00.00 | 19/06/2013 | xin.shang        | N/A | Boot050001
 *      05.01.00 | 27/03/2014 | mingqing.tang    | N/A | Boot050002
 *
 *****************************************************************************/
#include "bl_common.h"
#include "bl_security.h"
#include "bl_security_cfg.h"

/*****************************************************************************
 *  QAC Suppression
 *****************************************************************************/
/*PRQA S 1252,1532,2103,3112,3227 EOF*/
/*
 * 1252:suffixed integer constant implicitly converted to different integer.
 *
 * 1532:The function is only referenced in one translation unit.
 *
 * 2103:Integral promotion, unsigned short promoted to unsigned int.
 * This message will therefore only be generated when a short and an int are of
 * equal size.
 *
 * MISRA-C:2004 14.2(3112):This statement has no side-effect.
 * The DEBUG_ASSERT macro is used to debug bootloader when the BL_DEBUG is
 * enable. When the BL_DEBUG is disable, the DEBUG_ASSERT macro is null.
 *
 * 3227:The parameter is never modified and so it could be declared with const.
 *
 */

/*****************************************************************************
 *  Verify The Configurations of Macro
 *****************************************************************************/
#if ((SECM_ACCESS_SEED_SIZE == 0u) || (SECM_ACCESS_KEY_SIZE == 0u))
#error "the size of the seed and the key is failure."
#endif

/*****************************************************************************
 *  Internal Macro Definitions
 *****************************************************************************/
#define SECM_GET_HASH_OPERATIONS(id)            (&g_HashOperations[id])
/*****************************************************************************
 *  Internal Type Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Internal Structure Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Internal Function Declarations
 *****************************************************************************/

/*****************************************************************************
 *  Internal Variable Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Global Variable Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Function Definitions
 *****************************************************************************/
/**************************************************************************//**
 *
 *  \details Initialize the security manager module.
 *
 *  \since V1.0.0
 *
 *****************************************************************************/
void Secm_Init(void)
{

    BL_DEBUG_ASSERT_NO_RET(g_SecurityAccessOps.Init != BL_NULL_PTR);

    g_SecurityAccessOps.Init();
    SECM_SIGNATURE_INIT();
    return ;
}

/**************************************************************************//**
 *
 *  \details This function use the current seed to make a new seed.
 *
 *  \since  V1.0.0
 *
 *****************************************************************************/
void Secm_MakeNewSeed(void)
{
    BL_DEBUG_ASSERT_NO_RET(g_SecurityAccessOps.MakeNewSeed != BL_NULL_PTR);

    g_SecurityAccessOps.MakeNewSeed();

    return ;
}

/**************************************************************************//**
 *
 *  \details Get a seed of security access.
 *
 *  \param[out] seed - the pointer of a buffer used to save the seed.
 *
 *  \since  V1.0.0
 *
 *****************************************************************************/
void Secm_GetSeed(bl_Buffer_t *seed)
{
    BL_DEBUG_ASSERT_NO_RET(g_SecurityAccessOps.GetSeed != BL_NULL_PTR);
    BL_DEBUG_ASSERT_NO_RET(seed != BL_NULL_PTR);

    g_SecurityAccessOps.GetSeed(seed);

    return ;
}

/**************************************************************************//**
 *
 *  \details Verify the result of security access.
 *
 *  \param[in] size - the size of key.
 *  \param[in] key  - the value of key.
 *
 *  \return If the key is verified successfully return BL_ERR_OK, otherwise
 *          return BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK - the result is verified successfully.
 *  \retval BL_ERR_NOT_OK - the result is verified failed.
 *
 *  \since  V1.0.0
 *
 *****************************************************************************/
bl_Return_t Secm_VerifyKey(bl_Size_t size, const bl_Buffer_t *key)
{
    bl_Return_t ret = BL_ERR_NOT_OK;

    BL_DEBUG_ASSERT_CONFIG(g_SecurityAccessOps.VerifyKey != BL_NULL_PTR);
    BL_DEBUG_ASSERT_PARAM(key != BL_NULL_PTR);

    if (SECM_ACCESS_KEY_SIZE == size)
    {
        ret = g_SecurityAccessOps.VerifyKey(key);
    }

    return ret;
}


#if 1
/******************************************************************************************************************//**
 *
 *  \details Initialize the context of a HASH algorithm.
 *
 *  \param[in]     id       - the ID of the HASH algorithm.
 *  \param[in/out] hashCtx  - the context of the HASH algorithm.
 *
 *  \return None
 *
 *  \since  6.0.0
 *
 *********************************************************************************************************************/
void SecM_InitHashContext(bl_HashId_t id, bl_HashContext_t *hashCtx)
{
    BL_ASSERT(id < SECM_HASH_LIMIT, "");
    BL_ASSERT(hashCtx != BL_NULL_PTR, "");

    hashCtx->id = id;
    hashCtx->operations = SECM_GET_HASH_OPERATIONS(id);
    if (hashCtx->operations->AllocContext != BL_NULL_PTR)
    {
        hashCtx->context = hashCtx->operations->AllocContext();
        BL_ASSERT(hashCtx->context != BL_NULL_PTR, "");
    }
    else
    {
        hashCtx->context = BL_NULL_PTR;
    }
}

/******************************************************************************************************************//**
 *
 *  \details Free the context of a HASH algorithm.
 *
 *  \param[in/out] hashCtx  - the context of the HASH algorithm.
 *
 *  \return None
 *
 *  \since  6.0.0
 *
 *********************************************************************************************************************/
void SecM_FreeHashContext(bl_HashContext_t *hashCtx)
{
    BL_ASSERT(hashCtx != BL_NULL_PTR, "");
    BL_ASSERT(hashCtx->id < SECM_HASH_LIMIT, "");

    if (hashCtx->operations->FreeContext != BL_NULL_PTR)
    {
         hashCtx->operations->FreeContext(hashCtx->context);
    }

    hashCtx->id = SECM_HASH_LIMIT;
    hashCtx->context = BL_NULL_PTR;
    hashCtx->operations = BL_NULL_PTR;
}


/******************************************************************************************************************//**
 *
 *  \details Start a hash algorithm used to verify the data whether are valid.
 *
 *  \since  1.0.0
 *
 *********************************************************************************************************************/
void SecM_StartHash(bl_HashContext_t *hashCtx)
{
    BL_ASSERT(hashCtx != BL_NULL_PTR, "");
    BL_ASSERT(hashCtx->operations != BL_NULL_PTR, "");
    BL_ASSERT(hashCtx->operations->Start != BL_NULL_PTR, "");

    hashCtx->operations->Start(hashCtx->context);
}

/******************************************************************************************************************//**
 *
 *  \details The data are used to update the hash value.
 *
 *  \param[in]  hashCtx - the context of HASH algorithm.
 *  \param[in]  size    - the size of data.
 *  \param[in]  data    - the value of data.
 *
 *  \return If the hash value is calculated successfully return BL_ERR_OK,
 *          otherwise return BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK - the hash value is calculated successfully.
 *  \retval BL_ERR_NOT_OK - the hash value is not calculated successfully.
 *
 *  \since  1.0.0
 *
 *********************************************************************************************************************/
bl_Return_t SecM_UpdateHash(bl_HashContext_t *hashCtx, bl_Size_t size, const bl_Buffer_t *data)
{
    BL_ASSERT(hashCtx != BL_NULL_PTR, "");
    BL_ASSERT(hashCtx->operations != BL_NULL_PTR, "");
    BL_ASSERT(hashCtx->operations->Update != BL_NULL_PTR, "");
    BL_ASSERT(data != BL_NULL_PTR, "");
    BL_ASSERT(size != 0, "");

    return hashCtx->operations->Update(hashCtx->context, size, data);
}

/******************************************************************************************************************//**
 *
 *  \details Get the value of HASH.
 *
 *  \param[in]  hashCtx - the context of HASH algorithm.
 *  \param[in]  size    - the size of buffer.
 *  \param[out] buffer  - the buffer used for saving the HASH value.
 *
 *  \return If the HASH's value is right return BL_ERR_OK, otherwise return
 *          BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK - the HASH value is right.
 *  \retval BL_ERR_NOT_OK - the HASH value is NOT right.
 *
 *  \since  6.0.0
 *
 *********************************************************************************************************************/
bl_Return_t SecM_FinishHash(bl_HashContext_t *hashCtx, bl_Size_t size, bl_Buffer_t *buffer)
{
    BL_ASSERT(hashCtx != BL_NULL_PTR, "");
    BL_ASSERT(hashCtx->operations != BL_NULL_PTR, "");
    BL_ASSERT(hashCtx->operations->Finish != BL_NULL_PTR, "");
    BL_ASSERT(buffer != BL_NULL_PTR, "");
    BL_ASSERT(size != 0, "");

    return hashCtx->operations->Finish(hashCtx->context, size, buffer);
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
bl_Return_t SecM_VerifySignature(bl_HashId_t id, bl_Size_t hashSize,const bl_Buffer_t *hash,
							 	 bl_Size_t signSize, const bl_Buffer_t *signature)
{
	return SECM_SIGNATURE_VERIFY(id, hashSize, hash, signSize, signature);
}
#endif




