/*
 * Copyright (c) 2021-2025 Yuntu Microelectronics Co., Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#include "device_registers.h"
#include "system_YTM32B1MD2.h"
#include "stdbool.h"

/* ----------------------------------------------------------------------------
   -- Core clock
   ---------------------------------------------------------------------------- */

uint32_t SystemCoreClock = DEFAULT_SYSTEM_CLOCK;


/*FUNCTION**********************************************************************
 *
 * Function Name : SystemInit
 * Description   : This function disables the watchdog, enables FPU
 * and the power mode protection if the corresponding feature macro
 * is enabled. SystemInit is called from startup_device file.
 *
 * Implements    : SystemInit_Activity
 *END**************************************************************************/
void SystemInit(void)
{
/**************************************************************************/
                      /* FPU ENABLE*/
/**************************************************************************/
#ifdef ENABLE_FPU
  /* Enable CP10 and CP11 coprocessors */
  SCB->CPACR |= (3UL << 20 | 3UL << 22);
#endif /* ENABLE_FPU */
/**************************************************************************/
/* EFM CONTROL */
/**************************************************************************/
    EFM->CTRL |= EFM_CTRL_LPEN_MASK;
/**************************************************************************/
/* RCU CONTROL */
/**************************************************************************/
    CIM->CTRL |= CIM_CTRL_LOCKUPEN_MASK;
/**************************************************************************/
/* WDOG DISABLE*/
/**************************************************************************/
#if (DISABLE_WDOG)
    WDG0->SVCR = 0xB631;
    WDG0->SVCR = 0xC278;
    WDG0->CR &= ~WDG_CR_EN_MASK;
#endif /* (DISABLE_WDOG) */
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SystemCoreClockUpdate
 * Description   : This function must be called whenever the core clock is changed
 * during program execution. It evaluates the clock register settings and calculates
 * the current core clock.
 *
 * Implements    : SystemCoreClockUpdate_Activity
 *END**************************************************************************/
void SystemCoreClockUpdate(void)
{
    uint32_t refClkFreq;
    uint32_t feedbackDiv;
    uint32_t referenceDiv;
    switch ((SCU->STS & SCU_STS_CLKST_MASK) >> SCU_STS_CLKST_SHIFT)
    {
        case 0x0:
            /* FIRC */
            SystemCoreClock = FEATURE_SCU_FIRC_FREQ;
            break;
#if defined(FEATURE_SCU_SUPPORT_PLL) && (FEATURE_SCU_SUPPORT_PLL)
        case 0x1:
            /* PLL */
            if (SCU_PLL_CTRL_REFCLKSRCSEL_MASK == (SCU->PLL_CTRL & SCU_PLL_CTRL_REFCLKSRCSEL_MASK))
            {
                /* Select FIRC as PLL reference clock */
                refClkFreq = FEATURE_SCU_FIRC_FREQ;
            }
            else
            {
                /* Select FXOSC as PLL reference clock */
                refClkFreq = FEATURE_SCU_FXOSC_FREQ;
            }
            /* Fout = (Fref * Ndiv) / ( 2 * Npre) */
            feedbackDiv = ((SCU->PLL_CTRL & SCU_PLL_CTRL_FBDIV_MASK) >> SCU_PLL_CTRL_FBDIV_SHIFT) + 1;
            referenceDiv = ((SCU->PLL_CTRL & SCU_PLL_CTRL_REFDIV_MASK) >> SCU_PLL_CTRL_REFDIV_SHIFT) + 1;
            SystemCoreClock = ((refClkFreq * feedbackDiv) / referenceDiv) >> 1;
            break;
#endif /* FEATURE_SCU_SUPPORT_PLL */
        case 0x2:
            /* FXOSC */
            SystemCoreClock = FEATURE_SCU_FXOSC_FREQ;
            break;
        case 0x3:
            /* SIRC */
            SystemCoreClock = FEATURE_SCU_SIRC_FREQ;
            break;
        default:
            break;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : SystemSoftwareReset
 * Description   : This function is used to initiate a system reset
 *
 * Implements    : SystemSoftwareReset_Activity
 *END**************************************************************************/
void SystemSoftwareReset(void)
{
    NVIC_SystemReset();
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
