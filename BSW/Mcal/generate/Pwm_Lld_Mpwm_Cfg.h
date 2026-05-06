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


#ifndef PWM_LLD_MPWM_CFG_H
#define PWM_LLD_MPWM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                          INCLUDE FILES                                        
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
 *                                SOURCE FILE VERSION INFORMATION                                
==================================================================================================*/
#define PWM_LLD_MPWM_VENDOR_ID_CFG                      (180)
#define PWM_LLD_MPWM_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define PWM_LLD_MPWM_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define PWM_LLD_MPWM_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define PWM_LLD_MPWM_SW_MAJOR_VERSION_CFG               (0)
#define PWM_LLD_MPWM_SW_MINOR_VERSION_CFG               (9)
#define PWM_LLD_MPWM_SW_PATCH_VERSION_CFG               (1)

/*==================================================================================================
 *                                       DEFINES AND MACROS                                       
==================================================================================================*/
/**
 * @brief   Switch to enable the development error detection.
 */
#define PWM_LLD_MPWM_DEV_ERROR_DETECT   (STD_OFF)

/**
 * @brief   MPWM timeout count
 */
#define PWM_LLD_MPWM_TIMEOUT_COUNT      (65535U)


#ifdef __cplusplus
}
#endif

#endif /* PWM_LLD_MPWM_CFG_H */

