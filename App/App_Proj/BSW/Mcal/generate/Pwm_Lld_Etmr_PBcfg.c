/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Pwm_Lld_Etmr_PBcfg.c
 * @brief 
 * 
 */


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Pwm_Lld_Etmr_PBcfg.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_LLD_ETMR_VENDOR_ID_PBCFG_C                      (180)
#define PWM_LLD_ETMR_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define PWM_LLD_ETMR_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define PWM_LLD_ETMR_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define PWM_LLD_ETMR_SW_MAJOR_VERSION_PBCFG_C               (0)
#define PWM_LLD_ETMR_SW_MINOR_VERSION_PBCFG_C               (9)
#define PWM_LLD_ETMR_SW_PATCH_VERSION_PBCFG_C               (1)

/*==================================================================================================
 *                                         GLOBAL CONSTANTS                                         
==================================================================================================*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
                                                                                                        
/*================================================================================================*/
/* Instance configuration structure PwmEtmr_0 */
PWM_CONST const Pwm_Lld_Etmr_InstCfgType Pwm_Lld_Etmr_InstCfg_Inst0 = 
{
    .DebugModeEnable = TRUE,
    .OvfIrqEn = FALSE,
    .ModTrgEn = FALSE,
    .MidTrgEn = FALSE,
    .InitTrgEn = FALSE,
    .Period = 500U,
    .ClockPrescaler = 7U,
    .OutTrgWidth = 0,
    .OutTrgFreq = 0U,
    .PulseSrc = PWM_LLD_ETMR_OUTPULSESRC_CH0,
    .ClockSource = PWM_LLD_ETMR_CLKSRC_BUS,
    .ExClockSource = PWM_LLD_ETMR_EXCLKSRC_TCLK_IN0,
    .OutTrgSrc = PWM_LLD_ETMR_OUTTRGSRC_MATCH,
    .OvfCallback = NULL_PTR
};

/* Channel configuration PwmEtmrCh_0 */
PWM_CONST const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst0_Ch0 = 
{
    .Val0TrgEn = FALSE,
    .Val1TrgEn = FALSE,
    .ChannelId = 0U,
    .DutyCycle = 0U,
    .DeadTime = 0U,
    .AlignMode = PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_ETMR_POLARITY_NOT_INVERT,
    .IdleState = PWM_LLD_ETMR_OUTPUT_STATE_LOW,
    .ChMode = PWM_LLD_ETMR_MODE_INDEPENDENT
};
/* Channel configuration PwmEtmrCh_1 */
PWM_CONST const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst0_Ch1 = 
{
    .Val0TrgEn = FALSE,
    .Val1TrgEn = FALSE,
    .ChannelId = 1U,
    .DutyCycle = 0U,
    .DeadTime = 0U,
    .AlignMode = PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_ETMR_POLARITY_NOT_INVERT,
    .IdleState = PWM_LLD_ETMR_OUTPUT_STATE_LOW,
    .ChMode = PWM_LLD_ETMR_MODE_INDEPENDENT
};
/* Channel configuration PwmEtmrCh_2 */
PWM_CONST const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst0_Ch2 = 
{
    .Val0TrgEn = FALSE,
    .Val1TrgEn = FALSE,
    .ChannelId = 2U,
    .DutyCycle = 0U,
    .DeadTime = 0U,
    .AlignMode = PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_ETMR_POLARITY_NOT_INVERT,
    .IdleState = PWM_LLD_ETMR_OUTPUT_STATE_LOW,
    .ChMode = PWM_LLD_ETMR_MODE_INDEPENDENT
};
/* Channel configuration PwmEtmrCh_3 */
PWM_CONST const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst0_Ch3 = 
{
    .Val0TrgEn = FALSE,
    .Val1TrgEn = FALSE,
    .ChannelId = 3U,
    .DutyCycle = 0U,
    .DeadTime = 0U,
    .AlignMode = PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_ETMR_POLARITY_NOT_INVERT,
    .IdleState = PWM_LLD_ETMR_OUTPUT_STATE_LOW,
    .ChMode = PWM_LLD_ETMR_MODE_INDEPENDENT
};
/* Channel configuration PwmEtmrCh_4 */
PWM_CONST const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst0_Ch4 = 
{
    .Val0TrgEn = FALSE,
    .Val1TrgEn = FALSE,
    .ChannelId = 4U,
    .DutyCycle = 0U,
    .DeadTime = 0U,
    .AlignMode = PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_ETMR_POLARITY_NOT_INVERT,
    .IdleState = PWM_LLD_ETMR_OUTPUT_STATE_LOW,
    .ChMode = PWM_LLD_ETMR_MODE_INDEPENDENT
};
/* Channel configuration PwmEtmrCh_5 */
PWM_CONST const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst0_Ch5 = 
{
    .Val0TrgEn = FALSE,
    .Val1TrgEn = FALSE,
    .ChannelId = 5U,
    .DutyCycle = 0U,
    .DeadTime = 0U,
    .AlignMode = PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_ETMR_POLARITY_NOT_INVERT,
    .IdleState = PWM_LLD_ETMR_OUTPUT_STATE_LOW,
    .ChMode = PWM_LLD_ETMR_MODE_INDEPENDENT
};
/* Channel configuration PwmEtmrCh_6 */
PWM_CONST const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst0_Ch6 = 
{
    .Val0TrgEn = FALSE,
    .Val1TrgEn = FALSE,
    .ChannelId = 6U,
    .DutyCycle = 0U,
    .DeadTime = 0U,
    .AlignMode = PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_ETMR_POLARITY_NOT_INVERT,
    .IdleState = PWM_LLD_ETMR_OUTPUT_STATE_LOW,
    .ChMode = PWM_LLD_ETMR_MODE_INDEPENDENT
};
/* Channel configuration PwmEtmrCh_7 */
PWM_CONST const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst0_Ch7 = 
{
    .Val0TrgEn = FALSE,
    .Val1TrgEn = FALSE,
    .ChannelId = 7U,
    .DutyCycle = 0U,
    .DeadTime = 0U,
    .AlignMode = PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_ETMR_POLARITY_NOT_INVERT,
    .IdleState = PWM_LLD_ETMR_OUTPUT_STATE_LOW,
    .ChMode = PWM_LLD_ETMR_MODE_INDEPENDENT
};

PWM_CONST static const Pwm_Lld_Etmr_ChCfgType * const Pwm_Lld_Etmr_ChCfgArr_Inst0[8U] = 
{
    &Pwm_Lld_Etmr_ChCfg_Inst0_Ch0,
    &Pwm_Lld_Etmr_ChCfg_Inst0_Ch1,
    &Pwm_Lld_Etmr_ChCfg_Inst0_Ch2,
    &Pwm_Lld_Etmr_ChCfg_Inst0_Ch3,
    &Pwm_Lld_Etmr_ChCfg_Inst0_Ch4,
    &Pwm_Lld_Etmr_ChCfg_Inst0_Ch5,
    &Pwm_Lld_Etmr_ChCfg_Inst0_Ch6,
    &Pwm_Lld_Etmr_ChCfg_Inst0_Ch7,
};

/* User configuration structure PwmEtmr_0 */
PWM_CONST const Pwm_Lld_Etmr_CfgType Pwm_Lld_Etmr_Cfg_Inst0 = 
{
    .ChannelCount = 8U,
    .InstCfg = &Pwm_Lld_Etmr_InstCfg_Inst0,
    .ChCfgArr = Pwm_Lld_Etmr_ChCfgArr_Inst0
};

/*================================================================================================*/
/* Instance configuration structure PwmEtmr_1 */
PWM_CONST const Pwm_Lld_Etmr_InstCfgType Pwm_Lld_Etmr_InstCfg_Inst1 = 
{
    .DebugModeEnable = TRUE,
    .OvfIrqEn = FALSE,
    .ModTrgEn = FALSE,
    .MidTrgEn = FALSE,
    .InitTrgEn = FALSE,
    .Period = 500U,
    .ClockPrescaler = 7U,
    .OutTrgWidth = 0,
    .OutTrgFreq = 0U,
    .PulseSrc = PWM_LLD_ETMR_OUTPULSESRC_CH0,
    .ClockSource = PWM_LLD_ETMR_CLKSRC_BUS,
    .ExClockSource = PWM_LLD_ETMR_EXCLKSRC_TCLK_IN0,
    .OutTrgSrc = PWM_LLD_ETMR_OUTTRGSRC_MATCH,
    .OvfCallback = NULL_PTR
};

/* Channel configuration PwmEtmrCh_0 */
PWM_CONST const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst1_Ch1 = 
{
    .Val0TrgEn = FALSE,
    .Val1TrgEn = FALSE,
    .ChannelId = 1U,
    .DutyCycle = 0U,
    .DeadTime = 0U,
    .AlignMode = PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_ETMR_POLARITY_NOT_INVERT,
    .IdleState = PWM_LLD_ETMR_OUTPUT_STATE_LOW,
    .ChMode = PWM_LLD_ETMR_MODE_INDEPENDENT
};
/* Channel configuration PwmEtmrCh_1 */
PWM_CONST const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst1_Ch4 = 
{
    .Val0TrgEn = FALSE,
    .Val1TrgEn = FALSE,
    .ChannelId = 4U,
    .DutyCycle = 0U,
    .DeadTime = 0U,
    .AlignMode = PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_ETMR_POLARITY_NOT_INVERT,
    .IdleState = PWM_LLD_ETMR_OUTPUT_STATE_LOW,
    .ChMode = PWM_LLD_ETMR_MODE_INDEPENDENT
};
/* Channel configuration PwmEtmrCh_2 */
PWM_CONST const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst1_Ch5 = 
{
    .Val0TrgEn = FALSE,
    .Val1TrgEn = FALSE,
    .ChannelId = 5U,
    .DutyCycle = 0U,
    .DeadTime = 0U,
    .AlignMode = PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_ETMR_POLARITY_NOT_INVERT,
    .IdleState = PWM_LLD_ETMR_OUTPUT_STATE_LOW,
    .ChMode = PWM_LLD_ETMR_MODE_INDEPENDENT
};
/* Channel configuration PwmEtmrCh_3 */
PWM_CONST const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst1_Ch6 = 
{
    .Val0TrgEn = FALSE,
    .Val1TrgEn = FALSE,
    .ChannelId = 6U,
    .DutyCycle = 0U,
    .DeadTime = 0U,
    .AlignMode = PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_ETMR_POLARITY_NOT_INVERT,
    .IdleState = PWM_LLD_ETMR_OUTPUT_STATE_LOW,
    .ChMode = PWM_LLD_ETMR_MODE_INDEPENDENT
};
/* Channel configuration PwmEtmrCh_4 */
PWM_CONST const Pwm_Lld_Etmr_ChCfgType Pwm_Lld_Etmr_ChCfg_Inst1_Ch7 = 
{
    .Val0TrgEn = FALSE,
    .Val1TrgEn = FALSE,
    .ChannelId = 7U,
    .DutyCycle = 0U,
    .DeadTime = 0U,
    .AlignMode = PWM_LLD_ETMR_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_ETMR_POLARITY_NOT_INVERT,
    .IdleState = PWM_LLD_ETMR_OUTPUT_STATE_LOW,
    .ChMode = PWM_LLD_ETMR_MODE_INDEPENDENT
};

PWM_CONST static const Pwm_Lld_Etmr_ChCfgType * const Pwm_Lld_Etmr_ChCfgArr_Inst1[5U] = 
{
    &Pwm_Lld_Etmr_ChCfg_Inst1_Ch1,
    &Pwm_Lld_Etmr_ChCfg_Inst1_Ch4,
    &Pwm_Lld_Etmr_ChCfg_Inst1_Ch5,
    &Pwm_Lld_Etmr_ChCfg_Inst1_Ch6,
    &Pwm_Lld_Etmr_ChCfg_Inst1_Ch7,
};

/* User configuration structure PwmEtmr_1 */
PWM_CONST const Pwm_Lld_Etmr_CfgType Pwm_Lld_Etmr_Cfg_Inst1 = 
{
    .ChannelCount = 5U,
    .InstCfg = &Pwm_Lld_Etmr_InstCfg_Inst1,
    .ChCfgArr = Pwm_Lld_Etmr_ChCfgArr_Inst1
};

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

