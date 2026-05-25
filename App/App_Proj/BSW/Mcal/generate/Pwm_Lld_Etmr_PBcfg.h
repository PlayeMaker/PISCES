/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Pwm_Lld_Etmr_PBcfg.h
 * @brief 
 * 
 */


#ifndef PWM_LLD_ETMR_PBCFG_H
#define PWM_LLD_ETMR_PBCFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Pwm_Lld_Etmr_Types.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_LLD_ETMR_VENDOR_ID_PBCFG                      (180)
#define PWM_LLD_ETMR_AR_RELEASE_MAJOR_VERSION_PBCFG       (4)
#define PWM_LLD_ETMR_AR_RELEASE_MINOR_VERSION_PBCFG       (4)
#define PWM_LLD_ETMR_AR_RELEASE_REVISION_VERSION_PBCFG    (0)
#define PWM_LLD_ETMR_SW_MAJOR_VERSION_PBCFG               (0)
#define PWM_LLD_ETMR_SW_MINOR_VERSION_PBCFG               (9)
#define PWM_LLD_ETMR_SW_PATCH_VERSION_PBCFG               (1)

/*==================================================================================================
 *                                       DEFINES AND MACROS                                       
==================================================================================================*/

/* eTMR instance index for instance configuration PwmEtmr_0 */
/* Channel configuration PwmEtmrCh_0 */
#define PWM_LLD_ETMR_INST_ID_ETMR_0_CH_0  (0U)
/* Channel configuration PwmEtmrCh_1 */
#define PWM_LLD_ETMR_INST_ID_ETMR_0_CH_1  (0U)
/* Channel configuration PwmEtmrCh_2 */
#define PWM_LLD_ETMR_INST_ID_ETMR_0_CH_2  (0U)
/* Channel configuration PwmEtmrCh_3 */
#define PWM_LLD_ETMR_INST_ID_ETMR_0_CH_3  (0U)
/* Channel configuration PwmEtmrCh_4 */
#define PWM_LLD_ETMR_INST_ID_ETMR_0_CH_4  (0U)
/* Channel configuration PwmEtmrCh_5 */
#define PWM_LLD_ETMR_INST_ID_ETMR_0_CH_5  (0U)
/* Channel configuration PwmEtmrCh_6 */
#define PWM_LLD_ETMR_INST_ID_ETMR_0_CH_6  (0U)
/* Channel configuration PwmEtmrCh_7 */
#define PWM_LLD_ETMR_INST_ID_ETMR_0_CH_7  (0U)

/* eTMR instance index for instance configuration PwmEtmr_1 */
/* Channel configuration PwmEtmrCh_0 */
#define PWM_LLD_ETMR_INST_ID_ETMR_1_CH_1  (1U)
/* Channel configuration PwmEtmrCh_1 */
#define PWM_LLD_ETMR_INST_ID_ETMR_1_CH_4  (1U)
/* Channel configuration PwmEtmrCh_2 */
#define PWM_LLD_ETMR_INST_ID_ETMR_1_CH_5  (1U)
/* Channel configuration PwmEtmrCh_3 */
#define PWM_LLD_ETMR_INST_ID_ETMR_1_CH_6  (1U)
/* Channel configuration PwmEtmrCh_4 */
#define PWM_LLD_ETMR_INST_ID_ETMR_1_CH_7  (1U)

/*==================================================================================================
 *                                  GLOBAL CONSTANTS DECLARATIONS                                  
==================================================================================================*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/*================================================================================================*/
/* User configuration structure PwmEtmr_0 */
PWM_CONST extern const Pwm_Lld_Etmr_CfgType Pwm_Lld_Etmr_Cfg_Inst0;
/* Instance configuration structure PwmEtmr_0 */
PWM_CONST extern const Pwm_Lld_Etmr_InstCfgType Pwm_Lld_Etmr_InstCfg_Inst0;
/* Channel configuration PwmEtmrCh_0 */
PWM_CONST extern const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst0_Ch0;
/* Channel configuration PwmEtmrCh_1 */
PWM_CONST extern const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst0_Ch1;
/* Channel configuration PwmEtmrCh_2 */
PWM_CONST extern const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst0_Ch2;
/* Channel configuration PwmEtmrCh_3 */
PWM_CONST extern const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst0_Ch3;
/* Channel configuration PwmEtmrCh_4 */
PWM_CONST extern const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst0_Ch4;
/* Channel configuration PwmEtmrCh_5 */
PWM_CONST extern const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst0_Ch5;
/* Channel configuration PwmEtmrCh_6 */
PWM_CONST extern const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst0_Ch6;
/* Channel configuration PwmEtmrCh_7 */
PWM_CONST extern const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst0_Ch7;

/*================================================================================================*/
/* User configuration structure PwmEtmr_1 */
PWM_CONST extern const Pwm_Lld_Etmr_CfgType Pwm_Lld_Etmr_Cfg_Inst1;
/* Instance configuration structure PwmEtmr_1 */
PWM_CONST extern const Pwm_Lld_Etmr_InstCfgType Pwm_Lld_Etmr_InstCfg_Inst1;
/* Channel configuration PwmEtmrCh_0 */
PWM_CONST extern const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst1_Ch1;
/* Channel configuration PwmEtmrCh_1 */
PWM_CONST extern const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst1_Ch4;
/* Channel configuration PwmEtmrCh_2 */
PWM_CONST extern const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst1_Ch5;
/* Channel configuration PwmEtmrCh_3 */
PWM_CONST extern const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst1_Ch6;
/* Channel configuration PwmEtmrCh_4 */
PWM_CONST extern const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst1_Ch7;

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/*==================================================================================================
 *                                      FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef __cplusplus
}
#endif

#endif /* PWM_LLD_ETMR_PBCFG_H */

/** @} */

