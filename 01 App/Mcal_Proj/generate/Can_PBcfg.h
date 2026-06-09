/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Can_PBcfg.h
 * @brief 
 * 
 */


#ifndef CAN_PB_CFG_H
#define CAN_PB_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_VENDOR_ID_PBCFG                      (180)
#define CAN_AR_RELEASE_MAJOR_VERSION_PBCFG       (4)
#define CAN_AR_RELEASE_MINOR_VERSION_PBCFG       (4)
#define CAN_AR_RELEASE_REVISION_VERSION_PBCFG    (0)
#define CAN_SW_MAJOR_VERSION_PBCFG               (0)
#define CAN_SW_MINOR_VERSION_PBCFG               (9)
#define CAN_SW_PATCH_VERSION_PBCFG               (1)

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
#define CAN_CONFIG_PB \
    extern const Can_ConfigType Can_Config;

#ifdef __cplusplus
}
#endif

#endif /* CAN_PB_CFG_H */

/** @} */

