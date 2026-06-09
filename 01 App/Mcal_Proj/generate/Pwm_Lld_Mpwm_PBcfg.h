/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Pwm_Lld_Mpwm_PBcfg.h
 * @brief 
 * 
 */


#ifndef PWM_LLD_MPWM_PBCFG_H
#define PWM_LLD_MPWM_PBCFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Pwm_Lld_Mpwm_Types.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_LLD_MPWM_VENDOR_ID_PBCFG                      (180)
#define PWM_LLD_MPWM_AR_RELEASE_MAJOR_VERSION_PBCFG       (4)
#define PWM_LLD_MPWM_AR_RELEASE_MINOR_VERSION_PBCFG       (4)
#define PWM_LLD_MPWM_AR_RELEASE_REVISION_VERSION_PBCFG    (0)
#define PWM_LLD_MPWM_SW_MAJOR_VERSION_PBCFG               (0)
#define PWM_LLD_MPWM_SW_MINOR_VERSION_PBCFG               (9)
#define PWM_LLD_MPWM_SW_PATCH_VERSION_PBCFG               (1)

/*==================================================================================================
 *                                       DEFINES AND MACROS                                       
==================================================================================================*/

/* eTMR instance index for instance configuration PwmMpwm_0 */
/* Channel configuration PwmMpwmCh_0 */
#define PWM_LLD_MPWM_INST_ID_MPWM_0_CH_0  (0U)
/* Channel configuration PwmMpwmCh_1 */
#define PWM_LLD_MPWM_INST_ID_MPWM_0_CH_1  (0U)
/* Channel configuration PwmMpwmCh_2 */
#define PWM_LLD_MPWM_INST_ID_MPWM_0_CH_2  (0U)
/* Channel configuration PwmMpwmCh_3 */
#define PWM_LLD_MPWM_INST_ID_MPWM_0_CH_3  (0U)
/* Channel configuration PwmMpwmCh_4 */
#define PWM_LLD_MPWM_INST_ID_MPWM_0_CH_4  (0U)
/* Channel configuration PwmMpwmCh_5 */
#define PWM_LLD_MPWM_INST_ID_MPWM_0_CH_5  (0U)
/* Channel configuration PwmMpwmCh_8 */
#define PWM_LLD_MPWM_INST_ID_MPWM_0_CH_8  (0U)
/* Channel configuration PwmMpwmCh_10 */
#define PWM_LLD_MPWM_INST_ID_MPWM_0_CH_10  (0U)
/* Channel configuration PwmMpwmCh_11 */
#define PWM_LLD_MPWM_INST_ID_MPWM_0_CH_11  (0U)
/* Channel configuration PwmMpwmCh_12 */
#define PWM_LLD_MPWM_INST_ID_MPWM_0_CH_12  (0U)
/* Channel configuration PwmMpwmCh_14 */
#define PWM_LLD_MPWM_INST_ID_MPWM_0_CH_14  (0U)
/* Channel configuration PwmMpwmCh_15 */
#define PWM_LLD_MPWM_INST_ID_MPWM_0_CH_15  (0U)

/*==================================================================================================
 *                                  GLOBAL CONSTANTS DECLARATIONS                                  
==================================================================================================*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/*================================================================================================*/
/* User configuration structure PwmMpwm_0 */
PWM_CONST extern const Pwm_Lld_Mpwm_CfgType Pwm_Lld_Mpwm_Cfg_Inst0;
/* Channel configuration PwmMpwmCh_0 */
PWM_CONST extern const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch0;
/* Channel configuration PwmMpwmCh_1 */
PWM_CONST extern const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch1;
/* Channel configuration PwmMpwmCh_2 */
PWM_CONST extern const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch2;
/* Channel configuration PwmMpwmCh_3 */
PWM_CONST extern const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch3;
/* Channel configuration PwmMpwmCh_4 */
PWM_CONST extern const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch4;
/* Channel configuration PwmMpwmCh_5 */
PWM_CONST extern const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch5;
/* Channel configuration PwmMpwmCh_8 */
PWM_CONST extern const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch8;
/* Channel configuration PwmMpwmCh_10 */
PWM_CONST extern const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch10;
/* Channel configuration PwmMpwmCh_11 */
PWM_CONST extern const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch11;
/* Channel configuration PwmMpwmCh_12 */
PWM_CONST extern const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch12;
/* Channel configuration PwmMpwmCh_14 */
PWM_CONST extern const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch14;
/* Channel configuration PwmMpwmCh_15 */
PWM_CONST extern const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch15;

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/*==================================================================================================
 *                                      FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef __cplusplus
}
#endif

#endif /* PWM_LLD_MPWM_PBCFG_H */

/** @} */

