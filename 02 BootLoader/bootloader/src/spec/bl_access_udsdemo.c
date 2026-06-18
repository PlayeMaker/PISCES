/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is a source file to make seed and verify a key.
 *
 *  \file       bl_access_udsdemo.c
 *  \ingroup    security_manager_module
 *  \author     xin.shang <xin.shang@hirain.com>
 *
 *  \version    5.7.0
 *  \date       25/06/2021
 *
 *  \par        Changelist
 *      Version  | Date       | Authors          | CR# | Descriptions
 *      -------- | ---------- | ---------------- | --- | ------------
 *      01.00.00 | 25/03/2010 | hewei.zhang      | N/A | Boot010001
 *      01.01.00 | 19/05/2010 | hewei.zhang      | N/A | Boot010002
 *      05.00.00 | 19/06/2013 | xin.shang        | N/A | Boot050001
 *      05.01.00 | 27/03/2014 | mingqing.tang    | N/A | Boot050002
 *
 *****************************************************************************/
#include "bl_common.h"
#include "bl_security_funcfg.h"
#include "bl_access_udsdemo.h"
#include "bl_typedefs.h"
#include "bl_timer.h"
#include "bl_can.h"
#include "bl_booting.h"
#include <stdlib.h>
/*****************************************************************************
 *  QAC Suppression
 *****************************************************************************/
/*PRQA S 602,1532,3212,3227,3453 EOF*/
/*
 * MISRA-C:2004 20.2(602):The identifier is reserved for use by the library.
 * The Bootloader do not use any library funtion and use the underscores to
 * indicate that the function is a interal function.
 *
 * 1532:The function is only referenced in one translation unit.
 * all functions in this file are configurations in the Security Module.
 *
 * 3212:This explicit cast is redundant and could be removed.
 * ACC_UDSDEMO_KEY_FROM_BUF and ACC_UDSDEMO_SEED_TO_BUF are not explicit cast.
 *
 * 3227:The parameter is never modified and so it could be declared with const.
 * Acc_UdsDemoGetSeed, the seed will be modify.
 * Acc_UdsDemoVerifyKey, the key is declared with const.
 *
 * MISRA-C:2004 19.7(3453):A function could probably be used instead of this
 * function-like macro.
 * ACC_UDSDEMO_KEY_FROM_BUF macro do not have side-effect.
 * ACC_UDSDEMO_SEED_TO_BUF macro do not have side-effect.
 *
 */

/*****************************************************************************
 *  Verify The Configurations of Macro
 *****************************************************************************/
#if ((SECM_ACCESS_KEY_SIZE != 4u) && (SECM_ACCESS_KEY_SIZE != 2u))
#error "The size of a key is only four or two, other values are invalid."
#endif

#if ((SECM_ACCESS_SEED_SIZE != 4u) && (SECM_ACCESS_SEED_SIZE != 2u))
#error "The size of a seed is only four or two, other values are invalid."
#endif
/*****************************************************************************
 *  Internal Macro Definitions
 *****************************************************************************/
#if (SECM_ACCESS_KEY_SIZE == 4u)
#define ACC_UDSDEMO_KEY_MASK                (0xA5CEFDB6UL)
#define ACC_UDSDEMO_KEY_FROM_BUF(buf)       BL_BE32_TO_MCU(buf)
#elif (SECM_ACCESS_KEY_SIZE == 2u)
#define ACC_UDSDEMO_KEY_MASK                (0xDFB6u)
#define ACC_UDSDEMO_KEY_FROM_BUF(buf)       BL_BE16_TO_MCU(buf)
#endif

#if (SECM_ACCESS_SEED_SIZE == 4u)
/** \brief It is used to calculate the random seed*/
#define ACC_UDSDEMO_RANDOM_SEED             (16807UL)
#define ACC_UDSDEMO_SEED_INITVALUE          (0x1A2B3C4DUL)
#define ACC_UDSDEMO_SEED_TO_BUF(seed,buf)   BL_MCU_TO_BE32(buf,seed)
#elif (SECM_ACCESS_SEED_SIZE == 2u)
/** \brief It is used to calculate the random seed*/
#define ACC_UDSDEMO_RANDOM_SEED             (16807u)
#define ACC_UDSDEMO_SEED_INITVALUE          (0x1235u)
#define ACC_UDSDEMO_SEED_TO_BUF(seed,buf)   BL_MCU_TO_BE16(buf,seed)
#endif

/*****************************************************************************
 *  Internal Type Definitions
 *****************************************************************************/
#if (SECM_ACCESS_SEED_SIZE == 4u)
typedef bl_u32_t bl_UdsDemoSeed_t;
#elif (SECM_ACCESS_SEED_SIZE == 2u)
typedef bl_u16_t bl_UdsDemoSeed_t;
#endif

#if (SECM_ACCESS_KEY_SIZE == 4u)
typedef bl_u32_t bl_UdsDemoKey_t;
#elif (SECM_ACCESS_KEY_SIZE == 2u)
typedef bl_u16_t bl_UdsDemoKey_t;
#endif

/*****************************************************************************
 *  Internal Structure Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Internal Function Declarations
 *****************************************************************************/
/** \brief Calculate the key from the gs_UdsDemoSeed.*/
static bl_UdsDemoKey_t _Acc_UdsDemoCalculateKey(void);

/*****************************************************************************
 *  Internal Variable Definitions
 *****************************************************************************/
static bl_UdsDemoSeed_t gs_UdsDemoSeed;

/*****************************************************************************
 *  Global Variable Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Function Definitions
 *****************************************************************************/
/**************************************************************************//**
 *
 *  \details Initialize the DEMO security access used for UDS.
 *
 *  \since  V1.0.0
 *
 *****************************************************************************/
void Acc_UdsDemoInit(void)
{
    gs_UdsDemoSeed = ACC_UDSDEMO_SEED_INITVALUE;

    return ;
}

/**************************************************************************//**
 *
 *  \details Make a new seed.
 *
 *  \since  V5.0.0
 *
 *****************************************************************************/
#define LCG_A       1103515245UL
#define LCG_C       12345UL

void Acc_UdsDemoMakeNewSeed(void)
{
    bl_u32_t Entropy = ((*(volatile bl_u32_t*)(0x40066000UL)) + g_RandomSeed)*rand();
    gs_UdsDemoSeed = (gs_UdsDemoSeed * LCG_A + LCG_C) ^ Entropy;

    if((gs_UdsDemoSeed == 0) || (gs_UdsDemoSeed == 0xFFFFFFFFUL))
    {
        gs_UdsDemoSeed = ACC_UDSDEMO_SEED_INITVALUE;
    }

    return ;
}

/**************************************************************************//**
 *
 *  \details Get current seed value.
 *
 *  \param[out]  seed - the value of current seed.
 *
 *  \since  V1.0.0
 *
 *****************************************************************************/
void Acc_UdsDemoGetSeed(bl_Buffer_t *seed)
{
    ACC_UDSDEMO_SEED_TO_BUF(gs_UdsDemoSeed,seed);

    return ;
}

/**************************************************************************//**
 *
 *  \details Verify the value of transmitted key whether is right.
 *
 *  \param[in]  key - the value of transmitted key.
 *
 *  \return If the transmitted key value is right return BL_ERR_OK, otherwise
 *          return BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK - the transmitted key value is right.
 *  \retval BL_ERR_NOT_OK - the transmitted key value is NOT right.
 *
 *  \since  V1.0.0
 *
 *****************************************************************************/
bl_Return_t Acc_UdsDemoVerifyKey(const bl_Buffer_t *key)
{
    bl_Return_t ret = BL_ERR_NOT_OK;
    bl_UdsDemoKey_t calKey;
    bl_UdsDemoKey_t tranKey;

    calKey = _Acc_UdsDemoCalculateKey();
    tranKey = ACC_UDSDEMO_KEY_FROM_BUF(key);

    if (calKey == tranKey)
    {
        ret = BL_ERR_OK;
    }


    return ret;
}
/**************************************************************************//**
 *
 *  \details An algorithm is used to calculate the crc8.
 *
 *  \return the crc8 value
 *
 *  \since V1.0.0
 *
 *****************************************************************************/
static bl_u8_t crc8(bl_u8_t *data, bl_u8_t length) /*function of calculate the Key*/
{
    bl_u8_t t_crc;
    bl_u8_t f, b;
    t_crc = 0xFF;
    for (f = 0; f < length; f++)
    {
        t_crc ^= data[f];
        for (b = 0; b < 8; b++)
        {
            if ((t_crc & 0x80) != 0)
            {
                t_crc <<= 1;
                t_crc ^= 0x1D;
            }
            else
            {
                t_crc <<= 1;
            }
        }
    }
    return ~t_crc;
}

/**************************************************************************//**
 *
 *  \details An algorithm is used to calculate the key by a seed.
 *
 *  \return the key value
 *
 *  \since V1.0.0
 *
 *****************************************************************************/
static bl_Return_t  ASAP1A_CCP_ComputeKeyFromSeed(bl_u8_t *seed, bl_u16_t sizeSeed,
                                   bl_u8_t * key, bl_u16_t maxSizeKey, bl_u16_t *sizeKey)
{
    bl_u16_t seedlength = 6;
    bl_u8_t buf_byte[6];
    bl_u8_t crc_byte[7];

    seed[4] = 0x45;
    seed[5] = 0x2A;

#if 1 /* original version*/
    buf_byte[0] = seed[0];
    buf_byte[1] = seed[1];
    buf_byte[2] = seed[2];
    buf_byte[3] = seed[3];
    buf_byte[4] = seed[4];
    buf_byte[5] = seed[5];
#endif

    crc_byte[0] = crc8(buf_byte,seedlength);

    buf_byte[0] = crc_byte[0];
    crc_byte[1] = crc8(buf_byte,seedlength);

    buf_byte[0] = seed[0];
    buf_byte[1] = crc_byte[1];
    crc_byte[2] = crc8(buf_byte, seedlength);

    buf_byte[1] = seed[1];
    buf_byte[2] = crc_byte[2];
    crc_byte[3] = crc8(buf_byte, seedlength);

    buf_byte[2] = seed[2];
    buf_byte[3] = crc_byte[3];
    crc_byte[4] = crc8(buf_byte, seedlength);

    buf_byte[3] = seed[3];
    buf_byte[4] = crc_byte[4];
    crc_byte[5] = crc8(buf_byte, seedlength);

    buf_byte[4] = seed[4];
    buf_byte[5] = crc_byte[5];
    crc_byte[6] = crc8(buf_byte, seedlength);

    if (crc_byte[3] == 0 && crc_byte[4] == 0 && crc_byte[5] == 0 && crc_byte[6] == 0)
    {
        key[0] = crc_byte[1];
        key[1] = crc_byte[2];
        key[2] = crc_byte[3];
        key[3] = crc_byte[4];
    }
    else
    {
        key[0] = crc_byte[3];
        key[1] = crc_byte[4];
        key[2] = crc_byte[5];
        key[3] = crc_byte[6];
    }

    *sizeKey = 4;

    /* If the return value is false the flash tool stops*/
    return BL_ERR_OK;
}
/**************************************************************************//**
 *
 *  \details An algorithm is used to calculate the key by a seed.
 *
 *  \return the key value
 *
 *  \since V1.0.0
 *
 *****************************************************************************/
static bl_UdsDemoKey_t _Acc_UdsDemoCalculateKey(void)
{
    bl_UdsDemoKey_t key,temp_key;
    bl_u16_t sizekey = 0x4;
    bl_u8_t seed[4];

    Bl_McuToBe32(seed,gs_UdsDemoSeed);
    ASAP1A_CCP_ComputeKeyFromSeed(seed,4,(bl_u8_t*)&key,4,&sizekey);
    temp_key = Bl_Be32ToMcu((bl_u8_t*)&key);

    return temp_key;
}


