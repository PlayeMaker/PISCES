/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Pwm_Lld_Mpwm_PBcfg.c
 * @brief 
 * 
 */


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Pwm_Lld_Mpwm_PBcfg.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_LLD_MPWM_VENDOR_ID_PBCFG_C                      (180)
#define PWM_LLD_MPWM_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define PWM_LLD_MPWM_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define PWM_LLD_MPWM_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define PWM_LLD_MPWM_SW_MAJOR_VERSION_PBCFG_C               (0)
#define PWM_LLD_MPWM_SW_MINOR_VERSION_PBCFG_C               (9)
#define PWM_LLD_MPWM_SW_PATCH_VERSION_PBCFG_C               (1)

/*==================================================================================================
 *                                         GLOBAL CONSTANTS                                         
==================================================================================================*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
                                                                                                
/*================================================================================================*/
/* Channel configuration PwmMpwmCh_0 */
PWM_CONST const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch0 = 
{
    .DebugModeEn = STD_ON,
    .CmpMatchTrigEn = STD_OFF,
    .PeriodMatchTrigEn = STD_OFF,
    .OvfIrqEn = STD_OFF,
    .ChIrqEn = STD_OFF,
    .ChannelId = 0U,
    .Period = 500U,
    .DutyCycle = 0U,
    .ClockPrescaler = PWM_LLD_MPWM_CLK_DIV_8,
    .ReloadSource = PWM_LLD_MPWM_RLD_SRC_PERIOD,
    .AlignMode = PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_MPWM_POLARITY_INVERT,
    .IdleState = PWM_LLD_MPWM_OUTPUT_STATE_LOW,
    .OvfCallback = NULL_PTR,
    .ChCallback = NULL_PTR
};
/* Channel configuration PwmMpwmCh_1 */
PWM_CONST const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch1 = 
{
    .DebugModeEn = STD_ON,
    .CmpMatchTrigEn = STD_OFF,
    .PeriodMatchTrigEn = STD_OFF,
    .OvfIrqEn = STD_OFF,
    .ChIrqEn = STD_OFF,
    .ChannelId = 1U,
    .Period = 500U,
    .DutyCycle = 0U,
    .ClockPrescaler = PWM_LLD_MPWM_CLK_DIV_8,
    .ReloadSource = PWM_LLD_MPWM_RLD_SRC_PERIOD,
    .AlignMode = PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_MPWM_POLARITY_INVERT,
    .IdleState = PWM_LLD_MPWM_OUTPUT_STATE_LOW,
    .OvfCallback = NULL_PTR,
    .ChCallback = NULL_PTR
};
/* Channel configuration PwmMpwmCh_2 */
PWM_CONST const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch2 = 
{
    .DebugModeEn = STD_ON,
    .CmpMatchTrigEn = STD_OFF,
    .PeriodMatchTrigEn = STD_OFF,
    .OvfIrqEn = STD_OFF,
    .ChIrqEn = STD_OFF,
    .ChannelId = 2U,
    .Period = 500U,
    .DutyCycle = 0U,
    .ClockPrescaler = PWM_LLD_MPWM_CLK_DIV_8,
    .ReloadSource = PWM_LLD_MPWM_RLD_SRC_PERIOD,
    .AlignMode = PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_MPWM_POLARITY_INVERT,
    .IdleState = PWM_LLD_MPWM_OUTPUT_STATE_LOW,
    .OvfCallback = NULL_PTR,
    .ChCallback = NULL_PTR
};
/* Channel configuration PwmMpwmCh_3 */
PWM_CONST const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch3 = 
{
    .DebugModeEn = STD_ON,
    .CmpMatchTrigEn = STD_OFF,
    .PeriodMatchTrigEn = STD_OFF,
    .OvfIrqEn = STD_OFF,
    .ChIrqEn = STD_OFF,
    .ChannelId = 3U,
    .Period = 500U,
    .DutyCycle = 0U,
    .ClockPrescaler = PWM_LLD_MPWM_CLK_DIV_8,
    .ReloadSource = PWM_LLD_MPWM_RLD_SRC_PERIOD,
    .AlignMode = PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_MPWM_POLARITY_INVERT,
    .IdleState = PWM_LLD_MPWM_OUTPUT_STATE_LOW,
    .OvfCallback = NULL_PTR,
    .ChCallback = NULL_PTR
};
/* Channel configuration PwmMpwmCh_4 */
PWM_CONST const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch4 = 
{
    .DebugModeEn = STD_ON,
    .CmpMatchTrigEn = STD_OFF,
    .PeriodMatchTrigEn = STD_OFF,
    .OvfIrqEn = STD_OFF,
    .ChIrqEn = STD_OFF,
    .ChannelId = 4U,
    .Period = 500U,
    .DutyCycle = 0U,
    .ClockPrescaler = PWM_LLD_MPWM_CLK_DIV_8,
    .ReloadSource = PWM_LLD_MPWM_RLD_SRC_PERIOD,
    .AlignMode = PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_MPWM_POLARITY_INVERT,
    .IdleState = PWM_LLD_MPWM_OUTPUT_STATE_LOW,
    .OvfCallback = NULL_PTR,
    .ChCallback = NULL_PTR
};
/* Channel configuration PwmMpwmCh_5 */
PWM_CONST const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch5 = 
{
    .DebugModeEn = STD_ON,
    .CmpMatchTrigEn = STD_OFF,
    .PeriodMatchTrigEn = STD_OFF,
    .OvfIrqEn = STD_OFF,
    .ChIrqEn = STD_OFF,
    .ChannelId = 5U,
    .Period = 500U,
    .DutyCycle = 0U,
    .ClockPrescaler = PWM_LLD_MPWM_CLK_DIV_8,
    .ReloadSource = PWM_LLD_MPWM_RLD_SRC_PERIOD,
    .AlignMode = PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_MPWM_POLARITY_INVERT,
    .IdleState = PWM_LLD_MPWM_OUTPUT_STATE_LOW,
    .OvfCallback = NULL_PTR,
    .ChCallback = NULL_PTR
};
/* Channel configuration PwmMpwmCh_8 */
PWM_CONST const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch8 = 
{
    .DebugModeEn = STD_ON,
    .CmpMatchTrigEn = STD_OFF,
    .PeriodMatchTrigEn = STD_OFF,
    .OvfIrqEn = STD_OFF,
    .ChIrqEn = STD_OFF,
    .ChannelId = 8U,
    .Period = 500U,
    .DutyCycle = 0U,
    .ClockPrescaler = PWM_LLD_MPWM_CLK_DIV_8,
    .ReloadSource = PWM_LLD_MPWM_RLD_SRC_PERIOD,
    .AlignMode = PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_MPWM_POLARITY_INVERT,
    .IdleState = PWM_LLD_MPWM_OUTPUT_STATE_LOW,
    .OvfCallback = NULL_PTR,
    .ChCallback = NULL_PTR
};
/* Channel configuration PwmMpwmCh_10 */
PWM_CONST const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch10 = 
{
    .DebugModeEn = STD_ON,
    .CmpMatchTrigEn = STD_OFF,
    .PeriodMatchTrigEn = STD_OFF,
    .OvfIrqEn = STD_OFF,
    .ChIrqEn = STD_OFF,
    .ChannelId = 10U,
    .Period = 500U,
    .DutyCycle = 0U,
    .ClockPrescaler = PWM_LLD_MPWM_CLK_DIV_8,
    .ReloadSource = PWM_LLD_MPWM_RLD_SRC_PERIOD,
    .AlignMode = PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_MPWM_POLARITY_INVERT,
    .IdleState = PWM_LLD_MPWM_OUTPUT_STATE_LOW,
    .OvfCallback = NULL_PTR,
    .ChCallback = NULL_PTR
};
/* Channel configuration PwmMpwmCh_11 */
PWM_CONST const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch11 = 
{
    .DebugModeEn = STD_ON,
    .CmpMatchTrigEn = STD_OFF,
    .PeriodMatchTrigEn = STD_OFF,
    .OvfIrqEn = STD_OFF,
    .ChIrqEn = STD_OFF,
    .ChannelId = 11U,
    .Period = 500U,
    .DutyCycle = 0U,
    .ClockPrescaler = PWM_LLD_MPWM_CLK_DIV_8,
    .ReloadSource = PWM_LLD_MPWM_RLD_SRC_PERIOD,
    .AlignMode = PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_MPWM_POLARITY_INVERT,
    .IdleState = PWM_LLD_MPWM_OUTPUT_STATE_LOW,
    .OvfCallback = NULL_PTR,
    .ChCallback = NULL_PTR
};
/* Channel configuration PwmMpwmCh_12 */
PWM_CONST const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch12 = 
{
    .DebugModeEn = STD_ON,
    .CmpMatchTrigEn = STD_OFF,
    .PeriodMatchTrigEn = STD_OFF,
    .OvfIrqEn = STD_OFF,
    .ChIrqEn = STD_OFF,
    .ChannelId = 12U,
    .Period = 500U,
    .DutyCycle = 0U,
    .ClockPrescaler = PWM_LLD_MPWM_CLK_DIV_8,
    .ReloadSource = PWM_LLD_MPWM_RLD_SRC_PERIOD,
    .AlignMode = PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_MPWM_POLARITY_INVERT,
    .IdleState = PWM_LLD_MPWM_OUTPUT_STATE_LOW,
    .OvfCallback = NULL_PTR,
    .ChCallback = NULL_PTR
};
/* Channel configuration PwmMpwmCh_14 */
PWM_CONST const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch14 = 
{
    .DebugModeEn = STD_ON,
    .CmpMatchTrigEn = STD_OFF,
    .PeriodMatchTrigEn = STD_OFF,
    .OvfIrqEn = STD_OFF,
    .ChIrqEn = STD_OFF,
    .ChannelId = 14U,
    .Period = 500U,
    .DutyCycle = 0U,
    .ClockPrescaler = PWM_LLD_MPWM_CLK_DIV_8,
    .ReloadSource = PWM_LLD_MPWM_RLD_SRC_PERIOD,
    .AlignMode = PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_MPWM_POLARITY_INVERT,
    .IdleState = PWM_LLD_MPWM_OUTPUT_STATE_LOW,
    .OvfCallback = NULL_PTR,
    .ChCallback = NULL_PTR
};
/* Channel configuration PwmMpwmCh_15 */
PWM_CONST const Pwm_Lld_Mpwm_ChCfgType Pwm_Lld_Mpwm_ChCfg_Inst0_Ch15 = 
{
    .DebugModeEn = STD_ON,
    .CmpMatchTrigEn = STD_OFF,
    .PeriodMatchTrigEn = STD_OFF,
    .OvfIrqEn = STD_OFF,
    .ChIrqEn = STD_OFF,
    .ChannelId = 15U,
    .Period = 500U,
    .DutyCycle = 0U,
    .ClockPrescaler = PWM_LLD_MPWM_CLK_DIV_8,
    .ReloadSource = PWM_LLD_MPWM_RLD_SRC_PERIOD,
    .AlignMode = PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE,
    .Polarity = PWM_LLD_MPWM_POLARITY_INVERT,
    .IdleState = PWM_LLD_MPWM_OUTPUT_STATE_LOW,
    .OvfCallback = NULL_PTR,
    .ChCallback = NULL_PTR
};

PWM_CONST static const Pwm_Lld_Mpwm_ChCfgType * const Pwm_Lld_Mpwm_ChCfgArr_Inst0[12U] = 
{
    &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch0,
    &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch1,
    &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch2,
    &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch3,
    &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch4,
    &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch5,
    &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch8,
    &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch10,
    &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch11,
    &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch12,
    &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch14,
    &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch15,
};

/* User configuration structure PwmMpwm_0 */
PWM_CONST const Pwm_Lld_Mpwm_CfgType Pwm_Lld_Mpwm_Cfg_Inst0 = 
{
    .ChannelCount = 12U,
    .ChCfgArr = Pwm_Lld_Mpwm_ChCfgArr_Inst0
};

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

