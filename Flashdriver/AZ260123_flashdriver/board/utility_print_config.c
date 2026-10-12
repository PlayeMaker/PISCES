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
 * @file utility_print_config.c
 * @brief 
 * 
 */



#include "utility_print_config.h"
#include "uart_config.h"

status_t UTILITY_PRINT_Init(void)
{
    status_t status=STATUS_SUCCESS;
    status=UART_DRV_Init(2, &uart_config0_State,&uart_config0);
    return status;
}

void printf_char(char ch)
{
    UART_DRV_SendDataPolling(2, (const uint8_t *) &ch, 1);
}


