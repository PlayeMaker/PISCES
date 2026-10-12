/*
 * Copyright 2020-2025 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file vector_table_copy.c
 * @brief 
 * 
 */

#include "Platform_Types.h"
#include "OsIf.h"
#include "YTM32B1MD2_features.h"

static volatile uint32 * const s_vectors[NUMBER_OF_CORES] = FEATURE_INTERRUPT_INT_VECTORS;
extern uint32 IVT_RAM_start[1U];
extern uint32 IVT_start[1U];
extern uint32 IVT_end[1U];

void VectorTableCopy(void)
{
    uint8 coreId = (uint8)OsIf_GetCoreID();
    uint32* ramStart = (uint32*)IVT_RAM_start;
    const uint32* romStart = (const uint32*)IVT_start;
    uint32 size=((uint32)IVT_end-(uint32)IVT_start)/sizeof(uint32);
    (void)s_vectors;

    for (uint32 n = 0; n < size; n++)
    {
        ramStart[n] = romStart[n];
    }
    *s_vectors[coreId] = (uint32)IVT_RAM_start;
}

void DefaultISR(void)
{
   while(1){};
}

#ifndef USING_OS_AUTOSAROS
__attribute__ ((weak)) void NMI_Handler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void HardFault_Handler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MemManage_Handler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void BusFault_Handler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void UsageFault_Handler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void SVC_Handler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void DebugMon_Handler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void PendSV_Handler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void SysTick_Handler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void DMA0_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void DMA1_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void DMA2_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void DMA3_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void DMA4_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void DMA5_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void DMA6_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void DMA7_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void DMA_Error_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void FPU_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void EFM_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void EFM_Error_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void PCU_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void EFM_Ecc_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void Wdg_Mld_Isr(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void RCU_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void I2C0_Master_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void I2C0_Slave_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void SPI0_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void SPI1_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void SPI2_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void I2C1_Master_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void UART0_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void UART1_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void UART2_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void eADC0_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void ACMP0_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void EMU0_SB_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void EMU0_DB_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void RTC_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void RTC_Seconds_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void pTMR0_Ch0_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void pTMR0_Ch1_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void pTMR0_Ch2_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void pTMR0_Ch3_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CMU_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void lpTMR0_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void GPIOA_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void GPIOB_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void GPIOC_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void GPIOD_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void GPIOE_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN0_ORed_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN0_Error_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN0_Wake_Up_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN0_ORed_0_15_MB_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN0_ORed_16_31_MB_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN0_ORed_32_47_MB_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN0_ORed_48_63_MB_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN1_ORed_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN1_Error_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN1_Wake_Up_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN1_ORed_0_15_MB_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN1_ORed_16_31_MB_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN1_ORed_32_47_MB_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN1_ORed_48_63_MB_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN2_ORed_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN2_Error_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN2_Wake_Up_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN2_ORed_0_15_MB_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void CAN2_ORed_16_31_MB_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void eTMR0_Ch0_Ch1_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void eTMR0_Ch2_Ch3_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void eTMR0_Ch4_Ch5_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void eTMR0_Ch6_Ch7_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void eTMR0_Fault_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void eTMR0_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void eTMR1_Ch0_Ch1_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void eTMR1_Ch2_Ch3_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void eTMR1_Ch4_Ch5_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void eTMR1_Ch6_Ch7_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void eTMR1_Fault_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void eTMR1_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch0_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch1_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch2_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch3_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch4_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch5_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch6_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch7_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch8_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch9_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch10_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch11_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch12_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch13_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch14_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch15_Ovf_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch0_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch1_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch2_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch3_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch4_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch5_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch6_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch7_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch8_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch9_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch10_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch11_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch12_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch13_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch14_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void MPWM0_Ch15_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void TRNG_IRQHandler(void) 
{
    DefaultISR();
}
__attribute__ ((weak)) void HCU_IRQHandler(void) 
{
    DefaultISR();
}
#endif
