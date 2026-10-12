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
 * @file startup.S
 * @brief 
 * 
 */

    .syntax unified
    .arch armv8-m.main

    .thumb
/* Reset Handler */
    .thumb_func
    .align 2
    .globl   Reset_Handler
    .type    Reset_Handler, %function
_start:
Reset_Handler:
    cpsid   i               /* Mask interrupts */

    /* Init the rest of the registers */
    ldr     r1,=0
    ldr     r2,=0
    ldr     r3,=0
    ldr     r4,=0
    ldr     r5,=0
    ldr     r6,=0
    ldr     r7,=0
    mov     r8,r7
    mov     r9,r7
    mov     r10,r7
    mov     r11,r7
    mov     r12,r7

 
    /* RamInit 0 Stage, focus on ecc init, asm code*/
    bl     RamInit0

    /* Initialize the stack pointer */
    ldr     r0,=STACK_end
    mov     r13,r0

    /* RamInit 1 Stage, focus on copy data,clear bss, c code*/
    ldr     r0,=RamInit1
    blx     r0

    /* Copy Vector Table for interrupt, c code */
#ifndef __NO_VECTOR_TABLE_COPY
    /* Call the to copy vector table from flash to ram */
    ldr     r0,=VectorTableCopy
    blx     r0
#endif
    /* SystemInit, user can init PLL to speed up left startup code, c code*/
#ifndef __NO_SYSTEM_INIT
    /* Call the system init routine */
    ldr     r0,=SystemInit
    blx     r0
#endif
    /* RamInit 2 Stage, focus on others ram init, c code */
    ldr     r0,=RamInit2
    blx     r0

    /* Unmask interrupts */
    cpsie   i               

    /* Call the main routine */
    bl      main
JumpToSelf:
    b       JumpToSelf