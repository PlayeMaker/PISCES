/*
* @file    Crypto_Lld_Reg.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : CRYPTO_Lld_Reg
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V0.9.1
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef CRYPTO_LLD_REG_H
#define CRYPTO_LLD_REG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "pSIP_Hcu.h"
#include "pSIP_Efm.h"
#include "pSIP_Trng.h"
#if defined(CPU_YTM32B1ME0)
#include "YTM32B1ME0_features.h"
#elif defined(CPU_YTM32B1MD1)
#include "YTM32B1MD1_features.h"
#elif defined(CPU_YTM32B1HA0)
#include "YTM32B1HA0_features.h"
#elif defined(CPU_YTM32B1MC0)
#include "YTM32B1MC0_features.h"
#elif defined(CPU_YTM32B1MD2)
#include "YTM32B1MD2_features.h"
#endif

/*==================================================================================================
                                      HHEADER FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_LLD_REG_VENDOR_ID                      (180)
#define CRYPTO_LLD_REG_AR_RELEASE_MAJOR_VERSION       (4)
#define CRYPTO_LLD_REG_AR_RELEASE_MINOR_VERSION       (4)
#define CRYPTO_LLD_REG_AR_RELEASE_REVISION_VERSION    (0)
#define CRYPTO_LLD_REG_SW_MAJOR_VERSION               (0)
#define CRYPTO_LLD_REG_SW_MINOR_VERSION               (9)
#define CRYPTO_LLD_REG_SW_PATCH_VERSION               (1)
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
#ifdef __cplusplus
}
#endif

#endif /* End of file CRYPTO_Lld_Reg.h */

