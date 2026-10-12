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
 * @file RamInit0.S
 * @brief 
 * 
 */

.syntax unified
.globl RamInit0
RamInit0:
_GET_POR:
    LDR     R1, =0x4007F000
    LDR     R4, [R1]
    LDR     R3, =0x1
/* R4 store POR result */
    ANDS    R4, R3
_IVT_RAM_start:
/* 8bytes align */
    LDR     R1, =IVT_RAM_memory_start
    LDR     R2, =IVT_RAM_memory_end
    
    SUBS    R2, R2, R1
    SUBS    R2, #1
    BLE     _IVT_RAM_end

    LDR     R0, =0x5A5A5A5A
    LDR     R3, =0x5A5A5A5A
 _IVT_RAM_loop:
    STM     R1!, {R0,R3}
    SUBS    R2, #8
    BGE      _IVT_RAM_loop
 _IVT_RAM_end:
_STACK_start:
/* 8bytes align */
    LDR     R1, =STACK_memory_start
    LDR     R2, =STACK_memory_end
    
    SUBS    R2, R2, R1
    SUBS    R2, #1
    BLE     _STACK_end

    LDR     R0, =0x5A5A5A5A
    LDR     R3, =0x5A5A5A5A
 _STACK_loop:
    STM     R1!, {R0,R3}
    SUBS    R2, #8
    BGE      _STACK_loop
 _STACK_end:
_RAM_start:
/* 8bytes align */
    LDR     R1, =RAM_memory_start
    LDR     R2, =RAM_memory_end
    
    SUBS    R2, R2, R1
    SUBS    R2, #1
    BLE     _RAM_end

    LDR     R0, =0x5A5A5A5A
    LDR     R3, =0x5A5A5A5A
 _RAM_loop:
    STM     R1!, {R0,R3}
    SUBS    R2, #8
    BGE      _RAM_loop
 _RAM_end:
   BX LR

