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
 * @file pin_mux.c
 * @brief 
 * 
 */



#include "pin_mux.h"

/*! @brief User configuration cfg InitConfigArr0 array */
const pin_settings_config_t g_pin_mux_InitConfigArr0[NUM_OF_CONFIGURED_PINS0] = {
    /* PTE_12-19-UART2_TX- */
    {
        .base = PCTRLE,
        .pinPortIdx = 12U,
        .pullConfig = PCTRL_INTERNAL_PULL_NOT_ENABLED,
        .passiveFilter = false,
        .driveSelect = PCTRL_LOW_DRIVE_STRENGTH,
        .mux = PCTRL_MUX_ALT3,
        .intConfig = PCTRL_DMA_INT_DISABLED,
        .clearIntFlag = false,
        .digitalFilter = false,
        .gpioBase = GPIOE,
        .direction = GPIO_INPUT_DIRECTION,
        .initValue = 0,
    },
    /* PTD_17-20-UART2_RX- */
    {
        .base = PCTRLD,
        .pinPortIdx = 17U,
        .pullConfig = PCTRL_INTERNAL_PULL_NOT_ENABLED,
        .passiveFilter = false,
        .driveSelect = PCTRL_LOW_DRIVE_STRENGTH,
        .mux = PCTRL_MUX_ALT3,
        .intConfig = PCTRL_DMA_INT_DISABLED,
        .clearIntFlag = false,
        .digitalFilter = false,
        .gpioBase = GPIOD,
        .direction = GPIO_INPUT_DIRECTION,
        .initValue = 0,
    },
};



/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/

