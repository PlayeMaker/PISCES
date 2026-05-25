/**
* @file    SchM_CddUart.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : SchM_CddUart
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V0.9.1
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

/**
*   @file    SchM_CddUart.c
*
*   @addtogroup SCHM_CDDUART_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 3432 Rule-20.7: Expressions resulting from the expansion of macro parameters shall be enclosed in parentheses.
 * PRQA S 3335 Rule-1.1-C99: The program shall contain no violations of the standard C syntax and constraints, and shall
 *                           not exceed the implementation's translation limits Suppression Options.
 * PRQA S 3415 Rule-13.5: Right hand operand of '&&' or '||' is an expression with persistent side effects.
 * PRQA S 4434 Rule-10.3: The value of an expression shall not be assigned to an object with a narrower
 *                        essential type or of a different essential type category.
 *
 */

/* MR12 Rule-13.5 VIOLATION: Right hand operand of '&&' or '||' is an expression with persistent side effects.
 * The variables msr_CDDUART_EXCLUSIVE_AREA and reentry_guard_CDDUART_EXCLUSIVE_AREA are volatile but it's write
 * read operations are full tested and verified with no side effects in such usages in the whole file.
 * Thus, couldn't adhere to M3CM Rule-13.5
 */
/* PRQA S 3415 EOF */

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "OsIf.h"
#include "CddUart_Cfg.h"
#include "SchM_CddUart.h"
/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_CDDUART_VENDOR_ID_C                      (180)
#define SCHM_CDDUART_AR_RELEASE_MAJOR_VERSION_C       (4)
#define SCHM_CDDUART_AR_RELEASE_MINOR_VERSION_C       (4)
#define SCHM_CDDUART_AR_RELEASE_REVISION_VERSION_C    (0)
#define SCHM_CDDUART_SW_MAJOR_VERSION_C               (0)
#define SCHM_CDDUART_SW_MINOR_VERSION_C               (9)
#define SCHM_CDDUART_SW_PATCH_VERSION_C               (1)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and SCHM_CDDUART header file are of the same vendor */
#if (SCHM_CDDUART_VENDOR_ID_C != SCHM_CDDUART_VENDOR_ID)
#error "SchM_CddUart.c and SchM_CddUart.h have different vendor ids"
#endif

/* Check if source file and SCHM_CDDUART header file are of the same Autosar version */
#if (( SCHM_CDDUART_AR_RELEASE_MAJOR_VERSION_C != SCHM_CDDUART_AR_RELEASE_MAJOR_VERSION) || \
      ( SCHM_CDDUART_AR_RELEASE_MINOR_VERSION_C != SCHM_CDDUART_AR_RELEASE_MINOR_VERSION) || \
      ( SCHM_CDDUART_AR_RELEASE_REVISION_VERSION_C != SCHM_CDDUART_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of SchM_CddUart.c and SchM_CddUart.h are different"
#endif

/* Check if source file and SCHM_CDDUART header file are of the same Software version */
#if (( SCHM_CDDUART_SW_MAJOR_VERSION_C != SCHM_CDDUART_SW_MAJOR_VERSION) || \
      ( SCHM_CDDUART_SW_MINOR_VERSION_C != SCHM_CDDUART_SW_MINOR_VERSION) || \
      ( SCHM_CDDUART_SW_PATCH_VERSION_C != SCHM_CDDUART_SW_PATCH_VERSION))
#error "Software Version Numbers of SchM_CddUart.c and SchM_CddUart.h are different"
#endif

/* Check if source file and CDDUART Configure header file are of the same vendor */
#if (SCHM_CDDUART_VENDOR_ID_C != CDDUART_VENDOR_ID_CFG)
#error "SchM_CddUart.c and CddUart_Cfg.h have different vendor ids"
#endif

/* Check if source file and CDDUART Configure header file are of the same Autosar version */
#if (( SCHM_CDDUART_AR_RELEASE_MAJOR_VERSION_C != CDDUART_AR_RELEASE_MAJOR_VERSION_CFG) || \
      ( SCHM_CDDUART_AR_RELEASE_MINOR_VERSION_C != CDDUART_AR_RELEASE_MINOR_VERSION_CFG) || \
      ( SCHM_CDDUART_AR_RELEASE_REVISION_VERSION_C != CDDUART_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of SchM_CddUart.c and CddUart_Cfg.h are different"
#endif

/* Check if source file and CDDUART Configure header file are of the same Software version */
#if (( SCHM_CDDUART_SW_MAJOR_VERSION_C != CDDUART_SW_MAJOR_VERSION_CFG) || \
      ( SCHM_CDDUART_SW_MINOR_VERSION_C != CDDUART_SW_MINOR_VERSION_CFG) || \
      ( SCHM_CDDUART_SW_PATCH_VERSION_C != CDDUART_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of SchM_CddUart.c and CddUart_Cfg.h are different"
#endif

/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and SCHM_CDDUART header file are of the same vendor */
#if (SCHM_CDDUART_VENDOR_ID_C != SCHM_CDDUART_VENDOR_ID)
#error "SchM_CddUart.c and SchM_CddUart.h have different vendor ids"
#endif

/* Check if source file and SCHM_CDDUART header file are of the same Autosar version */
#if (( SCHM_CDDUART_AR_RELEASE_MAJOR_VERSION_C != SCHM_CDDUART_AR_RELEASE_MAJOR_VERSION) || \
      ( SCHM_CDDUART_AR_RELEASE_MINOR_VERSION_C != SCHM_CDDUART_AR_RELEASE_MINOR_VERSION) || \
      ( SCHM_CDDUART_AR_RELEASE_REVISION_VERSION_C != SCHM_CDDUART_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of SchM_CddUart.c and SchM_CddUart.h are different"
#endif

/* Check if source file and SCHM_CDDUART header file are of the same Software version */
#if (( SCHM_CDDUART_SW_MAJOR_VERSION_C != SCHM_CDDUART_SW_MAJOR_VERSION) || \
      ( SCHM_CDDUART_SW_MINOR_VERSION_C != SCHM_CDDUART_SW_MINOR_VERSION) || \
      ( SCHM_CDDUART_SW_PATCH_VERSION_C != SCHM_CDDUART_SW_PATCH_VERSION))
#error "Software Version Numbers of SchM_CddUart.c and SchM_CddUart.h are different"
#endif

/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
#ifdef MCAL_PLATFORM_ARM
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
#define ISR_STATE_MASK     ((uint32)0x000000C0UL)   /**< @brief DAIF bit I and F */
#elif  (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH)
#define ISR_STATE_MASK     ((uint32)0x00000080UL)   /**< @brief CPSR bit I */
#else
#if ((defined MCAL_ENABLE_USER_MODE_SUPPORT)&&(!defined MCAL_PLATFORM_ARM_M0PLUS))
#define ISR_STATE_MASK     ((uint32)0x000000FFUL)   /**< @brief BASEPRI[7:0] mask */
#else
#define ISR_STATE_MASK     ((uint32)0x00000001UL)   /**< @brief PRIMASK bit 0 */
#endif
#endif
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef MCAL_PLATFORM_ARM
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
#define ISR_ON(msr)            (((uint32)(msr) & (uint32)(ISR_STATE_MASK)) != (uint32)(ISR_STATE_MASK))
#elif  (MCAL_PLATFORM_ARM == MCAL_ARM_RARCH)
#define ISR_ON(msr)            (((uint32)(msr) & (uint32)(ISR_STATE_MASK)) != (uint32)(ISR_STATE_MASK))
#else
#define ISR_ON(msr)            (((uint32)(msr) & (uint32)(ISR_STATE_MASK)) == (uint32)0)
#endif
#endif

#if(STD_ON == CDDUART_SCHM_SUPPORT)
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

#ifdef MCAL_SCHM_LITE

#define RTE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Rte_MemMap.h"

RTE_VAR static volatile uint8 SchM_CddUart_Msr;
RTE_VAR static volatile uint8 SchM_CddUart_ReentryGuard;

#define RTE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Rte_MemMap.h"

#else

#define RTE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Rte_MemMap.h"

RTE_VAR static volatile uint32 SchM_CddUart_Msr_00;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_00;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_01;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_01;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_02;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_02;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_03;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_03;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_04;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_04;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_05;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_05;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_06;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_06;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_07;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_07;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_08;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_08;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_09;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_09;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_10;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_10;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_11;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_11;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_12;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_12;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_13;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_13;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_14;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_14;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_15;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_15;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_16;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_16;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_17;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_17;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_18;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_18;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_19;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_19;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_20;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_20;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_21;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_21;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_22;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_22;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_23;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_23;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_24;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_24;
RTE_VAR static volatile uint32 SchM_CddUart_Msr_25;
RTE_VAR static volatile uint32 SchM_CddUart_ReentryGuard_25;

#define RTE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Rte_MemMap.h"

#endif /* MCAL_SCHM_LITE */

/*==================================================================================================
                                                LOCAL FUNCTIONS
==================================================================================================*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

/**
* @brief   This function returns the MSR register value (32 bits).
* @details This function returns the MSR register value (32 bits).
*
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits).
*
* @pre  None
* @post None
*
*/
RTE_FUNC static uint32 SchM_CddUart_ReadMsr(void)
{
#if ((defined MCAL_ENABLE_USER_MODE_SUPPORT)&&(!defined MCAL_PLATFORM_ARM_M0PLUS))
    /** MR12 RULE-20.7 VIOLATION: Expressions resulting from the expansion of macro parameters shall be enclosed in parentheses.
    * In this specific case, the OsIf_Trusted_Call1param() is used to embedded call the LLD driver with
    * CPU mode changed to privileged mode for user mode support, such usage is full-verified and works
    * as expected. thus, couldn't adhere to M3CM Rule-20.7
    *
    * MR12 RULE-10.4 VIOLATION: No function declaration of the __get_BASEPRI(). Implicit declaration inserted: 'extern int %1s();'.
    * In this specific case, the __get_BASEPRI() is used to read the BASEPRI register value. The function is referred from the
    * CMSIS library with static_inline attribute. The CMSIS library is a standard library for ARM Cortex-M processors.
    *
    * MR12 Rule-10.3 VIOLATION: The value of an expression shall not be assigned to an object with a narrower
    * essential type or of a different essential type category.
    * Here the __get_BASEPRI() function returns a uint32 value when define, which is casted to a uint32 type.So, No risk of data loss
    *
    */
    return (uint32)OsIf_Trusted_Call_Return(__get_BASEPRI);  /* PRQA S 3335, 3432, 4434 */
#else
    return __get_PRIMASK();
#endif
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*==================================================================================================
                                                GLOBAL FUNCTIONS
==================================================================================================*/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

#ifdef MCAL_SCHM_LITE

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA(void)
{
    if (0UL == SchM_CddUart_ReentryGuard)
    {
        SchM_CddUart_Msr = (uint8)SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA(void)
{
    SchM_CddUart_ReentryGuard -= 1U;
    if (ISR_ON(SchM_CddUart_Msr) && (0UL == SchM_CddUart_ReentryGuard))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

#else

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_00(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_00)
    {
        SchM_CddUart_Msr_00 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_00)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_00 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_00(void)
{
    SchM_CddUart_ReentryGuard_00 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_00) && (0UL == SchM_CddUart_ReentryGuard_00))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_01(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_01)
    {
        SchM_CddUart_Msr_01 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_01)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_01 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_01(void)
{
    SchM_CddUart_ReentryGuard_01 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_01) && (0UL == SchM_CddUart_ReentryGuard_01))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_02(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_02)
    {
        SchM_CddUart_Msr_02 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_02)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_02 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_02(void)
{
    SchM_CddUart_ReentryGuard_02 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_02) && (0UL == SchM_CddUart_ReentryGuard_02))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_03(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_03)
    {
        SchM_CddUart_Msr_03 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_03)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_03 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_03(void)
{
    SchM_CddUart_ReentryGuard_03 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_03) && (0UL == SchM_CddUart_ReentryGuard_03))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_04(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_04)
    {
        SchM_CddUart_Msr_04 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_04)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_04 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_04(void)
{
    SchM_CddUart_ReentryGuard_04 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_04) && (0UL == SchM_CddUart_ReentryGuard_04))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_05(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_05)
    {
        SchM_CddUart_Msr_05 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_05)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_05 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_05(void)
{
    SchM_CddUart_ReentryGuard_05 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_05) && (0UL == SchM_CddUart_ReentryGuard_05))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_06(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_06)
    {
        SchM_CddUart_Msr_06 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_06)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_06 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_06(void)
{
    SchM_CddUart_ReentryGuard_06 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_06) && (0UL == SchM_CddUart_ReentryGuard_06))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_07(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_07)
    {
        SchM_CddUart_Msr_07 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_07)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_07 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_07(void)
{
    SchM_CddUart_ReentryGuard_07 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_07) && (0UL == SchM_CddUart_ReentryGuard_07))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_08(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_08)
    {
        SchM_CddUart_Msr_08 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_08)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_08 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_08(void)
{
    SchM_CddUart_ReentryGuard_08 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_08) && (0UL == SchM_CddUart_ReentryGuard_08))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_09(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_09)
    {
        SchM_CddUart_Msr_09 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_09)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_09 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_09(void)
{
    SchM_CddUart_ReentryGuard_09 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_09) && (0UL == SchM_CddUart_ReentryGuard_09))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_10(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_10)
    {
        SchM_CddUart_Msr_10 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_10)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_10 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_10(void)
{
    SchM_CddUart_ReentryGuard_10 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_10) && (0UL == SchM_CddUart_ReentryGuard_10))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_11(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_11)
    {
        SchM_CddUart_Msr_11 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_11)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_11 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_11(void)
{
    SchM_CddUart_ReentryGuard_11 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_11) && (0UL == SchM_CddUart_ReentryGuard_11))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_12(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_12)
    {
        SchM_CddUart_Msr_12 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_12)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_12 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_12(void)
{
    SchM_CddUart_ReentryGuard_12 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_12) && (0UL == SchM_CddUart_ReentryGuard_12))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_13(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_13)
    {
        SchM_CddUart_Msr_13 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_13)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_13 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_13(void)
{
    SchM_CddUart_ReentryGuard_13 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_13) && (0UL == SchM_CddUart_ReentryGuard_13))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_14(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_14)
    {
        SchM_CddUart_Msr_14 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_14)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_14 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_14(void)
{
    SchM_CddUart_ReentryGuard_14 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_14) && (0UL == SchM_CddUart_ReentryGuard_14))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_15(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_15)
    {
        SchM_CddUart_Msr_15 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_15)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_15 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_15(void)
{
    SchM_CddUart_ReentryGuard_15 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_15) && (0UL == SchM_CddUart_ReentryGuard_15))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_16(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_16)
    {
        SchM_CddUart_Msr_16 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_16)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_16 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_16(void)
{
    SchM_CddUart_ReentryGuard_16 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_16) && (0UL == SchM_CddUart_ReentryGuard_16))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_17(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_17)
    {
        SchM_CddUart_Msr_17 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_17)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_17 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_17(void)
{
    SchM_CddUart_ReentryGuard_17 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_17) && (0UL == SchM_CddUart_ReentryGuard_17))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_18(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_18)
    {
        SchM_CddUart_Msr_18 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_18)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_18 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_18(void)
{
    SchM_CddUart_ReentryGuard_18 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_18) && (0UL == SchM_CddUart_ReentryGuard_18))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_19(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_19)
    {
        SchM_CddUart_Msr_19 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_19)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_19 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_19(void)
{
    SchM_CddUart_ReentryGuard_19 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_19) && (0UL == SchM_CddUart_ReentryGuard_19))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_20(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_20)
    {
        SchM_CddUart_Msr_20 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_20)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_20 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_20(void)
{
    SchM_CddUart_ReentryGuard_20 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_20) && (0UL == SchM_CddUart_ReentryGuard_20))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_21(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_21)
    {
        SchM_CddUart_Msr_21 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_21)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_21 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_21(void)
{
    SchM_CddUart_ReentryGuard_21 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_21) && (0UL == SchM_CddUart_ReentryGuard_21))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_22(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_22)
    {
        SchM_CddUart_Msr_22 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_22)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_22 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_22(void)
{
    SchM_CddUart_ReentryGuard_22 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_22) && (0UL == SchM_CddUart_ReentryGuard_22))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_23(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_23)
    {
        SchM_CddUart_Msr_23 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_23)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_23 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_23(void)
{
    SchM_CddUart_ReentryGuard_23 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_23) && (0UL == SchM_CddUart_ReentryGuard_23))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_24(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_24)
    {
        SchM_CddUart_Msr_24 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_24)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_24 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_24(void)
{
    SchM_CddUart_ReentryGuard_24 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_24) && (0UL == SchM_CddUart_ReentryGuard_24))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_25(void)
{
    if (0UL == SchM_CddUart_ReentryGuard_25)
    {
        SchM_CddUart_Msr_25 = SchM_CddUart_ReadMsr();  /*read MSR (to store interrupts state)*/
        if (ISR_ON(SchM_CddUart_Msr_25)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_CddUart_ReentryGuard_25 += 1U;
}

RTE_FUNC void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_25(void)
{
    SchM_CddUart_ReentryGuard_25 -= 1U;
    if (ISR_ON(SchM_CddUart_Msr_25) && (0UL == SchM_CddUart_ReentryGuard_25))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

#endif /* MCAL_SCHM_LITE */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#endif /* STD_ON == CDDUART_SCHM_SUPPORT */

#ifdef __cplusplus
}
#endif

/** @} */

/* End of file SchM_CddUart.c */
