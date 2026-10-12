/*
 *  Copyright 2020-2024 Yuntu Microelectronics co.,ltd
 *  All rights reserved.
 * 
 *  YUNTU Confidential. This software is owned or controlled by YUNTU and may only be
 *  used strictly in accordance with the applicable license terms. By expressly
 *  accepting such terms or by downloading, installing, activating and/or otherwise
 *  using the software, you are agreeing that you have read, and that you agree to
 *  comply with and are bound by, such license terms. If you do not agree to be
 *  bound by the applicable license terms, then you may not retain, install,
 *  activate or otherwise use the software. The production use license in
 *  Section 2.3 is expressly granted for this software.
 * 
 * @file clock_config.c
 * @brief 
 * 
 */

#include "stddef.h"
#include "clock_config.h"

/*! @brief peripheral clock PeripheralClockConfig */

peripheral_clock_config_t clock_config0PeripheralClockConfig[1] = {
    {
        .clkName = UART2_CLK,
        .clkGate = true,
        .divider = DIV_BY_1,
        .clkSrc = CLK_SRC_FIRC,
    },
};

const scu_config_t clock_config0ScuConfig = {
    .fircEnable = true,
    .fircDeepSleepEnable = false,
    .sircDeepSleepEnable = false,
    .sircStandbyEnable = false,
    .sircPowerDownEnable = false,
    .sysClkSrc = SCU_SYSTEM_CLOCK_SRC_FIRC,
    .fxoscConfig =
        {
            .enable = false,
            .bypassMode = false,
            .gainSelection = 5,
            .frequency = 24000000U,
        },
    .pllConfig =
        {
            .enable = false,
            .pllRefClock = SCU_PLL_REF_FXOSC_CLK,
            .pllFeedBackDiv = 20,
            .pllRefClkDiv = 3,
        },
    .sysDiv = SCU_SYS_CLK_DIV_BY_1,
    .fastBusDiv = SCU_SYS_CLK_DIV_BY_1,
    .slowBusDiv = SCU_SYS_CLK_DIV_BY_2,
    .flashDiv = SCU_SYS_CLK_DIV_BY_2,
    .clockOutConfig =
        {
            .enable = false,
            .source = SCU_CLKOUT_SEL_PLL_CLK,
            .divider = 1
        },
};

const cmu_config_t clock_config0CmuConfig = {
    .slowBusMonitor={
        .enable = false,                 
        .resetEnable = true,           
        .refClock = CMU_REF_SIRC_CLOCK,              
        .compareHigh = (50 * 128 / 2),        
        .compareLow = (30 * 128 / 2),       
    },
    .fircClockMonitor={
        .enable = false,                 
        .resetEnable = true,           
        .refClock = CMU_REF_SIRC_CLOCK,              
        .compareHigh = (60 * 128 / 2),        
        .compareLow = (36 * 128 / 2),         
    },
    .pllClockMonitor={
        .enable = false,                 
        .resetEnable = true,           
        .refClock = CMU_REF_SIRC_CLOCK,              
        .compareHigh = (100 * 128 / 2),        
        .compareLow = (60 * 128 / 2),         
    },
    .fxoscClockMonitor={
        .enable = false,                 
        .resetEnable = true,           
        .refClock = CMU_REF_SIRC_CLOCK,              
        .compareHigh = (30 * 128 / 2),        
        .compareLow = (18 * 128 / 2),         
    },
};

/*! @brief User Configuration structure clock_config0ClockManager */
clock_manager_user_config_t clock_config0ClockManager = {
    .scuConfigPtr = &clock_config0ScuConfig,
    .cmuConfigPtr = &clock_config0CmuConfig,
    .ipcConfig =
        {
            .peripheralClocks = clock_config0PeripheralClockConfig,
            .count = 1,
        },
};

/*! @brief Array of pointers to User configuration structures */
clock_manager_user_config_t const *g_clockManConfigsArr[] = {
    &clock_config0ClockManager,
};

/*! @brief Array of pointers to User defined Callbacks configuration structures */
/* The tool do not support generate Callbacks configuration. It's always empty. */
clock_manager_callback_user_config_t *g_clockManCallbacksArr[] = {(void *)0};
