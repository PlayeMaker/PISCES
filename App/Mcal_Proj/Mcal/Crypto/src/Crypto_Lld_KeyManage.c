/**
 * @file    Crypto_keyManage.c
 * @version
 *
 * @brief   AUTOSAR Csm module interface
 * @details API implementation for CSM driver
 *
 * @addtogroup CSM_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4 MCAL
 *   Platform             : ARM
 *   Peripheral           : Csm
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
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Crypto_Lld_Hcu_Types.h"
#include "Crypto_Lld_Reg.h"
#include "Crypto_Lld_KeyManage.h"
#include "Crypto_Cfg.h"
#include "OsIf.h"
#include "Fls.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_LLD_KEYMANAGE_VENDOR_ID_C                         (180)
#define CRYPTO_LLD_KEYMANAGE_AR_RELEASE_MAJOR_VERSION_C          (4)
#define CRYPTO_LLD_KEYMANAGE_AR_RELEASE_MINOR_VERSION_C          (4)
#define CRYPTO_LLD_KEYMANAGE_AR_RELEASE_REVISION_VERSION_C       (0)
#define CRYPTO_LLD_KEYMANAGE_SW_MAJOR_VERSION_C                  (0)
#define CRYPTO_LLD_KEYMANAGE_SW_MINOR_VERSION_C                  (9)
#define CRYPTO_LLD_KEYMANAGE_SW_PATCH_VERSION_C                  (1)

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Crypto_Lld_KeyManage header file are of the same vendor */
#if (CRYPTO_LLD_KEYMANAGE_VENDOR_ID_C != CRYPTO_LLD_KEYMANAGE_VENDOR_ID)
#error "Crypto_Lld_KeyManage.c and Crypto_Lld_KeyManage.h have different vendor ids"
#endif

/* Check if source file and Crypto_Lld_KeyManage header file are of the same Autosar version */
#if (( CRYPTO_LLD_KEYMANAGE_AR_RELEASE_MAJOR_VERSION_C != CRYPTO_LLD_KEYMANAGE_AR_RELEASE_MAJOR_VERSION) || \
      ( CRYPTO_LLD_KEYMANAGE_AR_RELEASE_MINOR_VERSION_C != CRYPTO_LLD_KEYMANAGE_AR_RELEASE_MINOR_VERSION) || \
      ( CRYPTO_LLD_KEYMANAGE_AR_RELEASE_REVISION_VERSION_C != CRYPTO_LLD_KEYMANAGE_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Crypto_Lld_KeyManage.c and Crypto_Lld_KeyManage.h are different"
#endif

/* Check if source file and Crypto_Lld_KeyManage header file are of the same Software version */
#if (( CRYPTO_LLD_KEYMANAGE_SW_MAJOR_VERSION_C != CRYPTO_LLD_KEYMANAGE_SW_MAJOR_VERSION) || \
      ( CRYPTO_LLD_KEYMANAGE_SW_MINOR_VERSION_C != CRYPTO_LLD_KEYMANAGE_SW_MINOR_VERSION) || \
      ( CRYPTO_LLD_KEYMANAGE_SW_PATCH_VERSION_C != CRYPTO_LLD_KEYMANAGE_SW_PATCH_VERSION))
#error "Software Version Numbers of Crypto_Lld_KeyManage.c and Crypto_Lld_KeyManage.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#define LENGTH_OF_KEYSLOT        (32U)
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : Crypto_KeyManage_LoadAESKey
 * Description   : Load AES key for HCU
 *
 * Implements    : Crypto_KeyManage_LoadAESKey
 *END**************************************************************************/

CRYPTO_FUNC Std_ReturnType Crypto_KeyManage_LoadAESKey(uint32 Address)
{
    uint8 TempKey[16];
    Std_ReturnType TempStdRet = E_NOT_OK;
    /*Waiting for idle*/
    do
    {
        Fls_MainFunction();
    } while (Fls_GetStatus() != MEMIF_IDLE);
    /*Load key schm protect ??*/
    TempStdRet = Fls_Read(Address, TempKey, LENGTH_OF_KEYSLOT);
    if (E_OK == TempStdRet)
    {
        do
        {
            Fls_MainFunction();
        } while (Fls_GetStatus() != MEMIF_IDLE);

        if (Fls_GetJobResult() == MEMIF_JOB_OK)
        {
            TempStdRet = E_OK;
        }
        else
        {
            TempStdRet = E_NOT_OK;
        }
    }
    return TempStdRet;
}

#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

