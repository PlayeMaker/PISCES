/**
 * @file    Pwm_Lld_Mpwm.C
 * @version V0.9.1
 *
 * @brief   YUNTU Pwm_Lld_Mpwm module interface
 * @details API implementation for Pwm_Lld_Mpwm driver
 *
 * @addtogroup PWM_LLD_MPWM_0_CH_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : MPWM
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V0.9.1
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
 *                                         INCLUDE FILES
=================================================================================================*/
#include "Pwm_Lld_Mpwm.h"
#include "OsIf.h"

/*==================================================================================================
 *                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_LLD_MPWM_IRQ_VENDOR_ID_C                      (180)
#define PWM_LLD_MPWM_IRQ_AR_RELEASE_MAJOR_VERSION_C       (4)
#define PWM_LLD_MPWM_IRQ_AR_RELEASE_MINOR_VERSION_C       (4)
#define PWM_LLD_MPWM_IRQ_AR_RELEASE_REVISION_VERSION_C    (0)
#define PWM_LLD_MPWM_IRQ_SW_MAJOR_VERSION_C               (0)
#define PWM_LLD_MPWM_IRQ_SW_MINOR_VERSION_C               (9)
#define PWM_LLD_MPWM_IRQ_SW_PATCH_VERSION_C               (1)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Pwm_Lld_Mpwm_Irq.c and Pwm_Lld_Mpwm.h are of the same vendor */
#if (PWM_LLD_MPWM_IRQ_VENDOR_ID_C != PWM_LLD_MPWM_VENDOR_ID)
#error "Pwm_Lld_Mpwm_Irq.c and Pwm_Lld_Mpwm.h have different vendor ids"
#endif

/* Check if Pwm_Lld_Mpwm_Irq.c and Pwm_Lld_Mpwm.h are of the same Autosar version */
#if ((PWM_LLD_MPWM_IRQ_AR_RELEASE_MAJOR_VERSION_C != PWM_LLD_MPWM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_LLD_MPWM_IRQ_AR_RELEASE_MINOR_VERSION_C != PWM_LLD_MPWM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_LLD_MPWM_IRQ_AR_RELEASE_REVISION_VERSION_C != PWM_LLD_MPWM_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pwm_Lld_Mpwm_Irq.c and Pwm_Lld_Mpwm.h are different"
#endif

/* Check if Pwm_Lld_Mpwm_Irq.c and Pwm_Lld_Mpwm.h are of the same Software version */
#if ((PWM_LLD_MPWM_IRQ_SW_MAJOR_VERSION_C != PWM_LLD_MPWM_SW_MAJOR_VERSION) || \
     (PWM_LLD_MPWM_IRQ_SW_MINOR_VERSION_C != PWM_LLD_MPWM_SW_MINOR_VERSION) || \
     (PWM_LLD_MPWM_IRQ_SW_PATCH_VERSION_C != PWM_LLD_MPWM_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm_Lld_Mpwm_Irq.c and Pwm_Lld_Mpwm.h are different"
#endif

/*==================================================================================================
 *                                   GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

#if defined(PWM_LLD_MPWM_0_CH_0_OVF_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch0_Ovf_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_0_CH_1_OVF_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch1_Ovf_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_0_CH_2_OVF_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch2_Ovf_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_0_CH_3_OVF_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch3_Ovf_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_0_CH_4_OVF_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch4_Ovf_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_0_CH_5_OVF_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch5_Ovf_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_0_CH_6_OVF_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch6_Ovf_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_0_CH_7_OVF_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch7_Ovf_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_0_CH_0_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch0_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_0_CH_1_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch1_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_0_CH_2_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch2_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_0_CH_3_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch3_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_0_CH_4_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch4_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_0_CH_5_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch5_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_0_CH_6_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch6_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_0_CH_7_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch7_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_0_CH_0_CH_7_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch0_Ch7_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_0_CH_8_CH_15_ISR_USED)
PWM_FUNC  ISR(MPWM0_Ch8_Ch15_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_1_CH_0_CH_7_ISR_USED)
PWM_FUNC  ISR(MPWM1_Ch0_Ch7_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_1_CH_8_CH_15_ISR_USED)
PWM_FUNC  ISR(MPWM1_Ch8_Ch15_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_2_CH_0_CH_7_ISR_USED)
PWM_FUNC  ISR(MPWM2_Ch0_Ch7_IRQHandler);
#endif

#if defined(PWM_LLD_MPWM_2_CH_8_CH_15_ISR_USED)
PWM_FUNC  ISR(MPWM2_Ch8_Ch15_IRQHandler);
#endif

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if defined(PWM_LLD_MPWM_0_CH_0_OVF_ISR_USED)
/**
 * @brief   MPWM0_Ch0 overflow interrupt handler.
 * @details This function handles the MPWM0_Ch0 overflow interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch0_Ovf_IRQHandler)
{
    Pwm_Lld_Mpwm_Ovf_IrqHandler(0U, 0U);
}
#endif

#if defined(PWM_LLD_MPWM_0_CH_1_OVF_ISR_USED)
/**
 * @brief   MPWM0_Ch1 overflow interrupt handler.
 * @details This function handles the MPWM0_Ch1 overflow interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch1_Ovf_IRQHandler)
{
    Pwm_Lld_Mpwm_Ovf_IrqHandler(0U, 1U);
}
#endif

#if defined(PWM_LLD_MPWM_0_CH_2_OVF_ISR_USED)
/**
 * @brief   MPWM0_Ch2 overflow interrupt handler.
 * @details This function handles the MPWM0_Ch2 overflow interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch2_Ovf_IRQHandler)
{
    Pwm_Lld_Mpwm_Ovf_IrqHandler(0U, 2U);
}
#endif

#if defined(PWM_LLD_MPWM_0_CH_3_OVF_ISR_USED)
/**
 * @brief   MPWM0_Ch3 overflow interrupt handler.
 * @details This function handles the MPWM0_Ch3 overflow interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch3_Ovf_IRQHandler)
{
    Pwm_Lld_Mpwm_Ovf_IrqHandler(0U, 3U);
}
#endif

#if defined(PWM_LLD_MPWM_0_CH_4_OVF_ISR_USED)
/**
 * @brief   MPWM0_Ch4 overflow interrupt handler.
 * @details This function handles the MPWM0_Ch4 overflow interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch4_Ovf_IRQHandler)
{
    Pwm_Lld_Mpwm_Ovf_IrqHandler(0U, 4U);
}
#endif

#if defined(PWM_LLD_MPWM_0_CH_5_OVF_ISR_USED)
/**
 * @brief   MPWM0_Ch5 overflow interrupt handler.
 * @details This function handles the MPWM0_Ch5 overflow interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch5_Ovf_IRQHandler)
{
    Pwm_Lld_Mpwm_Ovf_IrqHandler(0U, 5U);
}
#endif

#if defined(PWM_LLD_MPWM_0_CH_6_OVF_ISR_USED)
/**
 * @brief   MPWM0_Ch6 overflow interrupt handler.
 * @details This function handles the MPWM0_Ch6 overflow interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch6_Ovf_IRQHandler)
{
    Pwm_Lld_Mpwm_Ovf_IrqHandler(0U, 6U);
}
#endif

#if defined(PWM_LLD_MPWM_0_CH_7_OVF_ISR_USED)
/**
 * @brief   MPWM0_Ch7 overflow interrupt handler.
 * @details This function handles the MPWM0_Ch7 overflow interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch7_Ovf_IRQHandler)
{
    Pwm_Lld_Mpwm_Ovf_IrqHandler(0U, 7U);
}
#endif

#if defined(PWM_LLD_MPWM_0_CH_0_ISR_USED)
/**
 * @brief   MPWM0_Ch0 interrupt handler.
 * @details This function handles the MPWM0_Ch0 interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch0_IRQHandler)
{
    Pwm_Lld_Mpwm_IrqHandler(0U, 0U);
}
#endif

#if defined(PWM_LLD_MPWM_0_CH_1_ISR_USED)
/**
 * @brief   MPWM0_Ch1 interrupt handler.
 * @details This function handles the MPWM0_Ch1 interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch1_IRQHandler)
{
    Pwm_Lld_Mpwm_IrqHandler(0U, 1U);
}
#endif

#if defined(PWM_LLD_MPWM_0_CH_2_ISR_USED)
/**
 * @brief   MPWM0_Ch2 interrupt handler.
 * @details This function handles the MPWM0_Ch2 interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch2_IRQHandler)
{
    Pwm_Lld_Mpwm_IrqHandler(0U, 2U);
}
#endif

#if defined(PWM_LLD_MPWM_0_CH_3_ISR_USED)
/**
 * @brief   MPWM0_Ch3 interrupt handler.
 * @details This function handles the MPWM0_Ch3 interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch3_IRQHandler)
{
    Pwm_Lld_Mpwm_IrqHandler(0U, 3U);
}
#endif

#if defined(PWM_LLD_MPWM_0_CH_4_ISR_USED)
/**
 * @brief   MPWM0_Ch4 interrupt handler.
 * @details This function handles the MPWM0_Ch4 interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch4_IRQHandler)
{
    Pwm_Lld_Mpwm_IrqHandler(0U, 4U);
}
#endif

#if defined(PWM_LLD_MPWM_0_CH_5_ISR_USED)
/**
 * @brief   MPWM0_Ch5 interrupt handler.
 * @details This function handles the MPWM0_Ch5 interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch5_IRQHandler)
{
    Pwm_Lld_Mpwm_IrqHandler(0U, 5U);
}
#endif

#if defined(PWM_LLD_MPWM_0_CH_6_ISR_USED)
/**
 * @brief   MPWM0_Ch6 interrupt handler.
 * @details This function handles the MPWM0_Ch6 interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch6_IRQHandler)
{
    Pwm_Lld_Mpwm_IrqHandler(0U, 6U);
}
#endif

#if defined(PWM_LLD_MPWM_0_CH_7_ISR_USED)
/**
 * @brief   MPWM0_Ch7 interrupt handler.
 * @details This function handles the MPWM0_Ch7 interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch7_IRQHandler)
{
    Pwm_Lld_Mpwm_IrqHandler(0U, 7U);
}
#endif

#if defined(PWM_LLD_MPWM_0_CH_0_CH_7_ISR_USED)
/**
 * @brief   MPWM0 channel 0-7 interrupt handler.
 * @details This function handles the MPWM0 channel 0-7 interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch0_Ch7_IRQHandler)
{
    for (uint8 Ch = 0U; Ch <= 7U; ++Ch)
    {
        Pwm_Lld_Mpwm_Ovf_IrqHandler(0U, Ch);
        Pwm_Lld_Mpwm_IrqHandler(0U, Ch);
    }
}
#endif

#if defined(PWM_LLD_MPWM_0_CH_8_CH_15_ISR_USED)
/**
 * @brief   MPWM0 channel 8-15 interrupt handler.
 * @details This function handles the MPWM0 channel 8-15 interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM0_Ch8_Ch15_IRQHandler)
{
    for (uint8 Ch = 8U; Ch <= 15U; ++Ch)
    {
        Pwm_Lld_Mpwm_Ovf_IrqHandler(0U, Ch);
        Pwm_Lld_Mpwm_IrqHandler(0U, Ch);
    }
}
#endif

#if defined(PWM_LLD_MPWM_1_CH_0_CH_7_ISR_USED)
/**
 * @brief   MPWM1 channel 0-7 interrupt handler.
 * @details This function handles the MPWM1 channel 0-7 interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM1_Ch0_Ch7_IRQHandler)
{
    for (uint8 Ch = 0U; Ch <= 7U; ++Ch)
    {
        Pwm_Lld_Mpwm_Ovf_IrqHandler(1U, Ch);
        Pwm_Lld_Mpwm_IrqHandler(1U, Ch);
    }
}
#endif

#if defined(PWM_LLD_MPWM_1_CH_8_CH_15_ISR_USED)
/**
 * @brief   MPWM1 channel 8-15 interrupt handler.
 * @details This function handles the MPWM1 channel 8-15 interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM1_Ch8_Ch15_IRQHandler)
{
    for (uint8 Ch = 8U; Ch <= 15U; ++Ch)
    {
        Pwm_Lld_Mpwm_Ovf_IrqHandler(1U, Ch);
        Pwm_Lld_Mpwm_IrqHandler(1U, Ch);
    }
}
#endif

#if defined(PWM_LLD_MPWM_2_CH_0_CH_7_ISR_USED)
/**
 * @brief   MPWM2 channel 0-7 interrupt handler.
 * @details This function handles the MPWM2 channel 0-7 interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM2_Ch0_Ch7_IRQHandler)
{
    for (uint8 Ch = 0U; Ch <= 7U; ++Ch)
    {
        Pwm_Lld_Mpwm_Ovf_IrqHandler(2U, Ch);
        Pwm_Lld_Mpwm_IrqHandler(2U, Ch);
    }
}
#endif

#if defined(PWM_LLD_MPWM_2_CH_8_CH_15_ISR_USED)
/**
 * @brief   MPWM2 channel 8-15 interrupt handler.
 * @details This function handles the MPWM2 channel 8-15 interrupt.
 * @return  void
 */
PWM_FUNC  ISR(MPWM2_Ch8_Ch15_IRQHandler)
{
    for (uint8 Ch = 8U; Ch <= 15U; ++Ch)
    {
        Pwm_Lld_Mpwm_Ovf_IrqHandler(2U, Ch);
        Pwm_Lld_Mpwm_IrqHandler(2U, Ch);
    }
}
#endif

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

