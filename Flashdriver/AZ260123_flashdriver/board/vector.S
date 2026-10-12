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
 * @file vector.S
 * @brief 
 * 
 */


    .section .isr_vector, "a"
    .align 2
    .thumb
    .long   STACK_end                                      /* Top of Stack */
    .long   Reset_Handler                                                /* Reset Handler */
    .long   NMI_Handler
    .long   HardFault_Handler
    .long   MemManage_Handler
    .long   BusFault_Handler
    .long   UsageFault_Handler
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   SVC_Handler
    .long   DebugMon_Handler
    .long   DefaultISR
    .long   PendSV_Handler
    .long   SysTick_Handler
    .long   DMA0_IRQHandler
    .long   DMA1_IRQHandler
    .long   DMA2_IRQHandler
    .long   DMA3_IRQHandler
    .long   DMA4_IRQHandler
    .long   DMA5_IRQHandler
    .long   DMA6_IRQHandler
    .long   DMA7_IRQHandler
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DMA_Error_IRQHandler
    .long   FPU_IRQHandler
    .long   EFM_IRQHandler
    .long   EFM_Error_IRQHandler
    .long   PCU_IRQHandler
    .long   EFM_Ecc_IRQHandler
    .long   WDG0_IRQHandler
    .long   RCU_IRQHandler
    .long   I2C0_Master_IRQHandler
    .long   I2C0_Slave_IRQHandler
    .long   SPI0_IRQHandler
    .long   SPI1_IRQHandler
    .long   SPI2_IRQHandler
    .long   I2C1_Master_IRQHandler
    .long   DefaultISR
    .long   UART0_IRQHandler
    .long   DefaultISR
    .long   UART1_IRQHandler
    .long   DefaultISR
    .long   UART2_IRQHandler
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   eADC0_IRQHandler
    .long   DefaultISR
    .long   ACMP0_IRQHandler
    .long   DefaultISR
    .long   DefaultISR
    .long   EMU0_SB_IRQHandler
    .long   EMU0_DB_IRQHandler
    .long   RTC_IRQHandler
    .long   RTC_Seconds_IRQHandler
    .long   pTMR0_Ch0_IRQHandler
    .long   pTMR0_Ch1_IRQHandler
    .long   pTMR0_Ch2_IRQHandler
    .long   pTMR0_Ch3_IRQHandler
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   CMU_IRQHandler
    .long   lpTMR0_IRQHandler
    .long   GPIOA_IRQHandler
    .long   GPIOB_IRQHandler
    .long   GPIOC_IRQHandler
    .long   GPIOD_IRQHandler
    .long   GPIOE_IRQHandler
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   CAN0_ORed_IRQHandler
    .long   CAN0_Error_IRQHandler
    .long   CAN0_Wake_Up_IRQHandler
    .long   CAN0_ORed_0_15_MB_IRQHandler
    .long   CAN0_ORed_16_31_MB_IRQHandler
    .long   CAN0_ORed_32_47_MB_IRQHandler
    .long   CAN0_ORed_48_63_MB_IRQHandler
    .long   CAN1_ORed_IRQHandler
    .long   CAN1_Error_IRQHandler
    .long   CAN1_Wake_Up_IRQHandler
    .long   CAN1_ORed_0_15_MB_IRQHandler
    .long   CAN1_ORed_16_31_MB_IRQHandler
    .long   CAN1_ORed_32_47_MB_IRQHandler
    .long   CAN1_ORed_48_63_MB_IRQHandler
    .long   CAN2_ORed_IRQHandler
    .long   CAN2_Error_IRQHandler
    .long   CAN2_Wake_Up_IRQHandler
    .long   CAN2_ORed_0_15_MB_IRQHandler
    .long   CAN2_ORed_16_31_MB_IRQHandler
    .long   DefaultISR
    .long   DefaultISR
    .long   eTMR0_Ch0_Ch1_IRQHandler
    .long   eTMR0_Ch2_Ch3_IRQHandler
    .long   eTMR0_Ch4_Ch5_IRQHandler
    .long   eTMR0_Ch6_Ch7_IRQHandler
    .long   eTMR0_Fault_IRQHandler
    .long   eTMR0_Ovf_IRQHandler
    .long   eTMR1_Ch0_Ch1_IRQHandler
    .long   eTMR1_Ch2_Ch3_IRQHandler
    .long   eTMR1_Ch4_Ch5_IRQHandler
    .long   eTMR1_Ch6_Ch7_IRQHandler
    .long   eTMR1_Fault_IRQHandler
    .long   eTMR1_Ovf_IRQHandler
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   MPWM0_Ch0_Ovf_IRQHandler
    .long   MPWM0_Ch1_Ovf_IRQHandler
    .long   MPWM0_Ch2_Ovf_IRQHandler
    .long   MPWM0_Ch3_Ovf_IRQHandler
    .long   MPWM0_Ch4_Ovf_IRQHandler
    .long   MPWM0_Ch5_Ovf_IRQHandler
    .long   MPWM0_Ch6_Ovf_IRQHandler
    .long   MPWM0_Ch7_Ovf_IRQHandler
    .long   MPWM0_Ch8_Ovf_IRQHandler
    .long   MPWM0_Ch9_Ovf_IRQHandler
    .long   MPWM0_Ch10_Ovf_IRQHandler
    .long   MPWM0_Ch11_Ovf_IRQHandler
    .long   MPWM0_Ch12_Ovf_IRQHandler
    .long   MPWM0_Ch13_Ovf_IRQHandler
    .long   MPWM0_Ch14_Ovf_IRQHandler
    .long   MPWM0_Ch15_Ovf_IRQHandler
    .long   MPWM0_Ch0_IRQHandler
    .long   MPWM0_Ch1_IRQHandler
    .long   MPWM0_Ch2_IRQHandler
    .long   MPWM0_Ch3_IRQHandler
    .long   MPWM0_Ch4_IRQHandler
    .long   MPWM0_Ch5_IRQHandler
    .long   MPWM0_Ch6_IRQHandler
    .long   MPWM0_Ch7_IRQHandler
    .long   MPWM0_Ch8_IRQHandler
    .long   MPWM0_Ch9_IRQHandler
    .long   MPWM0_Ch10_IRQHandler
    .long   MPWM0_Ch11_IRQHandler
    .long   MPWM0_Ch12_IRQHandler
    .long   MPWM0_Ch13_IRQHandler
    .long   MPWM0_Ch14_IRQHandler
    .long   MPWM0_Ch15_IRQHandler
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   DefaultISR
    .long   TRNG_IRQHandler
    .long   HCU_IRQHandler
