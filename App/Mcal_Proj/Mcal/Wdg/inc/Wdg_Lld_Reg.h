/**
 * @file    Wdg_Lld_Reg.h
 * @version V0.9.1
 *
 * @brief   YUNTU Wdg_Lld module interface
 * @details API implementation for Wdg_Lld driver
 *
 * @addtogroup WDG_LLD_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : WDG
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

#ifndef WDG_LLD_REG_H
#define WDG_LLD_REG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                      INCLUDE FILES
==================================================================================================*/
#include "pSIP_Wdg.h"

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
#else
#error "Wrong MCU part number or no MCU part number selected!"
#endif

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_LLD_REG_VENDOR_ID                      (180)
#define WDG_LLD_REG_MODULE_ID           (102)
#define WDG_LLD_REG_AR_RELEASE_MAJOR_VERSION       (4)
#define WDG_LLD_REG_AR_RELEASE_MINOR_VERSION       (4)
#define WDG_LLD_REG_AR_RELEASE_REVISION_VERSION    (0)
#define WDG_LLD_REG_SW_MAJOR_VERSION               (0)
#define WDG_LLD_REG_SW_MINOR_VERSION               (9)
#define WDG_LLD_REG_SW_PATCH_VERSION               (1)

#ifdef __cplusplus
}
#endif

#endif /* WDG_LLD_REG_H */

/** @} */

