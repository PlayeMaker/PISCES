/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file undefined
 * @brief 
 * 
 */

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Crypto_Cfg.h"
#include "Crypto_Types.h"
#if(CRYPTO_ASYNJOB_METHOD_SUPPORT == CRYPTO_METHOD_DMA)
#include "CddDma_Cfg.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/
/*RAM key declaration*/
/* Pointer to Ram storing the Key Element value */

#define CRYPTO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crypto_MemMap.h"
/* Array storing the Crypto primitives in the __CryptoDriverObject_0__*/
CRYPTO_CONST static const Crypto_PrimitiveType Crypto_Primitives_CryptoDriverObject_0[1] =
{
    {
      (Crypto_PrimitiveServiceType)CRYPTO_RANDOMGENERATE,
      (uint8)CRYPTO_ALGOFAM_RNG,
      (uint8)CRYPTO_ALGOMODE_NOT_SET,
      (uint8)CRYPTO_ALGOFAM_NOT_SET
    },
};
/* Array storing the information about Crypto Driver Objects*/
CRYPTO_CONST const Crypto_ObjectType  Crypto_ObjectsList[CRYPTO_DRIVER_OBJECT_MAX] =
{
  {
    /* Jobs queue size */
    0U,
    /* Reference to the Crypto primitives list */
    Crypto_Primitives_CryptoDriverObject_0,
    /* Number of crypto primitives */
    1U
  },
};
/* Array storing keyelements*/
CRYPTO_CONST const Crypto_KeyElementType Crypto_KeyElementList[0] =
{
};
/* Array storing keys*/
CRYPTO_CONST const Crypto_KeyType Crypto_KeyList[CRYPTO_DRIVER_KEYID_MAX] =
{
};
/*configure Hcu */
CRYPTO_CONST const Crypto_ConfigType Crypto_PreCompileConfig =
{
  MODE_SWAPPING_NO,/*hcu_swapping*/
  HCU_USING_POLLING,/*hcu_carry*/
  /*!< Channel number for Inputdata DMA channel */
  Crypto_DMA_UNUSED,
  /*!< Channel number for Outputdata DMA channel */
  Crypto_DMA_UNUSED
};
#define CRYPTO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Crypto_MemMap.h"

