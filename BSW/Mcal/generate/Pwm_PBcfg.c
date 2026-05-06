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


#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Pwm_PBcfg.h"
#include "Pwm_Lld_Etmr_PBcfg.h"
#include "Pwm_Lld_Mpwm_PBcfg.h"

/*==================================================================================================
 *                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_VENDOR_ID_PBCFG_C                      (180)
#define PWM_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define PWM_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define PWM_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define PWM_SW_MAJOR_VERSION_PBCFG_C               (0)
#define PWM_SW_MINOR_VERSION_PBCFG_C               (9)
#define PWM_SW_PATCH_VERSION_PBCFG_C               (1)

/*==================================================================================================
 *                                        GLOBAL CONSTANTS                                        
==================================================================================================*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/**
 * @brief   PWM channels configuration array
 */
PWM_CONST static const Pwm_ChannelConfigType Pwm_ChannelConfigs[PWM_PBCFG_CHANNELS_COUNT] = 
{
/* PwmChannel_0 */
    {
        .ChannelId = 0U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_MPWM_INST_ID_MPWM_0_CH_0,
            .ChType = PWM_MLD_CHN_MPWM,
            .ChDutyCycle = 0U,
            .MpwmChCfg = &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch0
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_1 */
    {
        .ChannelId = 1U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_MPWM_INST_ID_MPWM_0_CH_1,
            .ChType = PWM_MLD_CHN_MPWM,
            .ChDutyCycle = 0U,
            .MpwmChCfg = &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch1
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_2 */
    {
        .ChannelId = 2U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_MPWM_INST_ID_MPWM_0_CH_2,
            .ChType = PWM_MLD_CHN_MPWM,
            .ChDutyCycle = 0U,
            .MpwmChCfg = &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch2
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_3 */
    {
        .ChannelId = 3U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_MPWM_INST_ID_MPWM_0_CH_3,
            .ChType = PWM_MLD_CHN_MPWM,
            .ChDutyCycle = 0U,
            .MpwmChCfg = &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch3
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_4 */
    {
        .ChannelId = 4U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_MPWM_INST_ID_MPWM_0_CH_4,
            .ChType = PWM_MLD_CHN_MPWM,
            .ChDutyCycle = 0U,
            .MpwmChCfg = &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch4
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_5 */
    {
        .ChannelId = 5U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_MPWM_INST_ID_MPWM_0_CH_5,
            .ChType = PWM_MLD_CHN_MPWM,
            .ChDutyCycle = 0U,
            .MpwmChCfg = &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch5
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_6 */
    {
        .ChannelId = 6U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_MPWM_INST_ID_MPWM_0_CH_8,
            .ChType = PWM_MLD_CHN_MPWM,
            .ChDutyCycle = 0U,
            .MpwmChCfg = &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch8
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_7 */
    {
        .ChannelId = 7U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_MPWM_INST_ID_MPWM_0_CH_10,
            .ChType = PWM_MLD_CHN_MPWM,
            .ChDutyCycle = 0U,
            .MpwmChCfg = &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch10
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_8 */
    {
        .ChannelId = 8U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_MPWM_INST_ID_MPWM_0_CH_11,
            .ChType = PWM_MLD_CHN_MPWM,
            .ChDutyCycle = 0U,
            .MpwmChCfg = &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch11
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_9 */
    {
        .ChannelId = 9U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_MPWM_INST_ID_MPWM_0_CH_12,
            .ChType = PWM_MLD_CHN_MPWM,
            .ChDutyCycle = 0U,
            .MpwmChCfg = &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch12
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_10 */
    {
        .ChannelId = 10U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_MPWM_INST_ID_MPWM_0_CH_14,
            .ChType = PWM_MLD_CHN_MPWM,
            .ChDutyCycle = 0U,
            .MpwmChCfg = &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch14
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_11 */
    {
        .ChannelId = 11U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_MPWM_INST_ID_MPWM_0_CH_15,
            .ChType = PWM_MLD_CHN_MPWM,
            .ChDutyCycle = 0U,
            .MpwmChCfg = &Pwm_Lld_Mpwm_ChCfg_Inst0_Ch15
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_12 */
    {
        .ChannelId = 12U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_0_CH_0,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst0_Ch0
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_13 */
    {
        .ChannelId = 13U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_0_CH_1,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst0_Ch1
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_14 */
    {
        .ChannelId = 14U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_0_CH_2,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst0_Ch2
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_15 */
    {
        .ChannelId = 15U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_0_CH_3,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst0_Ch3
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_16 */
    {
        .ChannelId = 16U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_0_CH_4,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst0_Ch4
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_17 */
    {
        .ChannelId = 17U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_0_CH_5,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst0_Ch5
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_18 */
    {
        .ChannelId = 18U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_0_CH_6,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst0_Ch6
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_19 */
    {
        .ChannelId = 19U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_0_CH_7,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst0_Ch7
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_20 */
    {
        .ChannelId = 20U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_1_CH_1,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst1_Ch1
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_21 */
    {
        .ChannelId = 21U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_1_CH_4,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst1_Ch4
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_22 */
    {
        .ChannelId = 22U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_1_CH_5,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst1_Ch5
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_23 */
    {
        .ChannelId = 23U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_1_CH_6,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst1_Ch6
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
/* PwmChannel_24 */
    {
        .ChannelId = 24U,
        .ChannelClass = PWM_VARIABLE_PERIOD,
        .MldChCfg = 
        {
            .ChInstId = PWM_LLD_ETMR_INST_ID_ETMR_1_CH_7,
            .ChType = PWM_MLD_CHN_ETMR,
            .ChDutyCycle = 0U,
            .EtmrChCfg = &Pwm_Lld_Etmr_ChCfg_Inst1_Ch7
        },
        .ChannelIdleState = PWM_LOW,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        .ChannelNotification = NULL_PTR
#endif
    },
};

/**
 * @brief   PWM instances configuration array
 */
PWM_CONST static const Pwm_Mld_InstCfgType Pwm_InstanceConfigs[PWM_PBCFG_INSTANCES_COUNT] =
{
/* PwmEtmr_0 */
    {
        .InstId = 0U,
        .InstType = PWM_MLD_INST_ETMR,
        .EtmrInstCfg = &Pwm_Lld_Etmr_InstCfg_Inst0
    },
/* PwmEtmr_1 */
    {
        .InstId = 1U,
        .InstType = PWM_MLD_INST_ETMR,
        .EtmrInstCfg = &Pwm_Lld_Etmr_InstCfg_Inst1
    },
/* PwmMpwm_0 */
    {
        .InstId = 0U,
        .InstType = PWM_MLD_INST_MPWM
    },
};

/**
 * @brief   PWM configuration
 */
PWM_CONST const Pwm_ConfigType Pwm_Config = 
{
    .ChannelCount = PWM_PBCFG_CHANNELS_COUNT,
    .PwmChannelsConfig = &Pwm_ChannelConfigs,
    .InstanceCount = PWM_PBCFG_INSTANCES_COUNT,   
    .PwmInstancesConfig = &Pwm_InstanceConfigs
};

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

