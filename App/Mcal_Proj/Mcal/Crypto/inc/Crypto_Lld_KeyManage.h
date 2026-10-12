/*
* @file    Crypto_Lld_KeyManage.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Crypto_Lld_KeyManage
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V0.9.1
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef CRYPTO_LLD_KEYMANAGE_H
#define CRYPTO_LLD_KEYMANAGE_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_LLD_KEYMANAGE_VENDOR_ID                         (180)
#define CRYPTO_LLD_KEYMANAGE_AR_RELEASE_MAJOR_VERSION          (4)
#define CRYPTO_LLD_KEYMANAGE_AR_RELEASE_MINOR_VERSION          (4)
#define CRYPTO_LLD_KEYMANAGE_AR_RELEASE_REVISION_VERSION       (0)
#define CRYPTO_LLD_KEYMANAGE_SW_MAJOR_VERSION                  (0)
#define CRYPTO_LLD_KEYMANAGE_SW_MINOR_VERSION                  (9)
#define CRYPTO_LLD_KEYMANAGE_SW_PATCH_VERSION                  (1)
/*==================================================================================================
                                                DEFINES AND MACROS
==================================================================================================*/
/*==================================================================================================
                                                EXTERNAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                ENUMS
==================================================================================================*/
/*==================================================================================================
                                                FUNCTION PROTOTYPES
==================================================================================================*/
extern Std_ReturnType Crypto_KeyManage_LoadAESKey(uint32 Address);
#ifdef __cplusplus
}
#endif

#endif /* End of file Crypto_Lld_KeyManage.h */
