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
 * @file uart_config.c
 * @brief 
 * 
 */



#include "uart_config.h"


/*uart_config0*/
uart_state_t uart_config0_State;
const uart_user_config_t uart_config0 = {
    .baudRate=115200U,
    .parityMode=UART_PARITY_DISABLED,
    .stopBitCount=UART_ONE_STOP_BIT,
    .bitCountPerChar=UART_8_BITS_PER_CHAR,
    .transferType=UART_USING_INTERRUPTS,
    .rxDMAChannel=0,
    .txDMAChannel=0,
    .idleErrorIntEnable=false,
};

