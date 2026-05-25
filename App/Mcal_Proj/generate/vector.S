/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file vector.S
 * @brief 
 * 
 */


    .section .isr_vector, "a"
    .align 2
    .thumb
    .long   STACK_end       /* Top of Stack */
    .long   Reset_Handler   /* Reset Handler */
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   NMI_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   HardFault_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MemManage_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   BusFault_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   UsageFault_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   SVC_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DebugMon_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   PendSV_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   SysTick_Handler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA1_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA2_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA3_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA4_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA5_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA6_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA7_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DMA_Error_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   FPU_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   EFM_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   EFM_Error_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   PCU_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   EFM_Ecc_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   Wdg_Mld_Isr
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   RCU_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   I2C0_Master_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   I2C0_Slave_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   SPI0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   SPI1_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   SPI2_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   I2C1_Master_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   UART0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   UART1_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   UART2_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eADC0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   ACMP0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   EMU0_SB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   EMU0_DB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   RTC_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   RTC_Seconds_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   pTMR0_Ch0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   pTMR0_Ch1_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   pTMR0_Ch2_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   pTMR0_Ch3_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CMU_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   lpTMR0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   GPIOA_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   GPIOB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   GPIOC_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   GPIOD_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   GPIOE_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN0_ORed_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN0_Error_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN0_Wake_Up_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN0_ORed_0_15_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN0_ORed_16_31_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN0_ORed_32_47_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN0_ORed_48_63_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN1_ORed_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN1_Error_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN1_Wake_Up_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN1_ORed_0_15_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN1_ORed_16_31_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN1_ORed_32_47_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN1_ORed_48_63_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN2_ORed_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN2_Error_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN2_Wake_Up_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN2_ORed_0_15_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   CAN2_ORed_16_31_MB_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR0_Ch0_Ch1_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR0_Ch2_Ch3_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR0_Ch4_Ch5_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR0_Ch6_Ch7_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR0_Fault_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR0_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR1_Ch0_Ch1_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR1_Ch2_Ch3_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR1_Ch4_Ch5_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR1_Ch6_Ch7_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR1_Fault_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   eTMR1_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch0_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch1_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch2_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch3_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch4_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch5_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch6_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch7_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch8_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch9_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch10_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch11_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch12_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch13_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch14_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch15_Ovf_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch0_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch1_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch2_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch3_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch4_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch5_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch6_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch7_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch8_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch9_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch10_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch11_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch12_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch13_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch14_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   MPWM0_Ch15_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   DefaultISR
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   TRNG_IRQHandler
#endif
#ifdef USING_OS_AUTOSAROS
    .long   DefaultISR
#else
    .long   HCU_IRQHandler
#endif

