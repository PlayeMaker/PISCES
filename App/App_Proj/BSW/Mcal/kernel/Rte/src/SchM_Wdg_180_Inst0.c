/**
 * @file    SchM_Wdg_180_Inst0.h
 * @version V0.9.1
 *
 * @brief   AUTOSAR SchM_Wdg_180_Inst0 module interface
 * @details API implementation for SchM_Wdg_180_Inst0 driver
 *
 * @addtogroup SCHM_WDG_180_INST0_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : WDG
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V0.9.1
 *
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                          INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "Platform_Cfg.h"
#include "OsIf.h"
#include "SchM_Wdg_180_Inst0.h"
/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_WDG_180_INST0_VENDOR_ID_C                    (180)
#define SCHM_WDG_180_INST0_AR_RELEASE_MAJOR_VERSION_C     (4)
#define SCHM_WDG_180_INST0_AR_RELEASE_MINOR_VERSION_C     (4)
#define SCHM_WDG_180_INST0_AR_RELEASE_REVISION_VERSION_C  (0)
#define SCHM_WDG_180_INST0_SW_MAJOR_VERSION_C             (0)
#define SCHM_WDG_180_INST0_SW_MINOR_VERSION_C             (9)
#define SCHM_WDG_180_INST0_SW_PATCH_VERSION_C             (1)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and SCHM_WDG_180_INST0 header file are of the same vendor */
#if (SCHM_WDG_180_INST0_VENDOR_ID_C != SCHM_WDG_180_INST0_VENDOR_ID)
#error "SchM_Wdg_180_Inst0.c and SchM_Wdg_180_Inst0.h have different vendor ids"
#endif

/* Check if source file and SCHM_WDG_180_INST0 header file are of the same Autosar version */
#if (( SCHM_WDG_180_INST0_AR_RELEASE_MAJOR_VERSION_C != SCHM_WDG_180_INST0_AR_RELEASE_MAJOR_VERSION) || \
      ( SCHM_WDG_180_INST0_AR_RELEASE_MINOR_VERSION_C != SCHM_WDG_180_INST0_AR_RELEASE_MINOR_VERSION) || \
      ( SCHM_WDG_180_INST0_AR_RELEASE_REVISION_VERSION_C != SCHM_WDG_180_INST0_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of SchM_Wdg_180_Inst0.c and SchM_Wdg_180_Inst0.h are different"
#endif

/* Check if source file and SCHM_WDG_180_INST0 header file are of the same Software version */
#if (( SCHM_WDG_180_INST0_SW_MAJOR_VERSION_C != SCHM_WDG_180_INST0_SW_MAJOR_VERSION) || \
      ( SCHM_WDG_180_INST0_SW_MINOR_VERSION_C != SCHM_WDG_180_INST0_SW_MINOR_VERSION) || \
      ( SCHM_WDG_180_INST0_SW_PATCH_VERSION_C != SCHM_WDG_180_INST0_SW_PATCH_VERSION))
#error "Software Version Numbers of SchM_Wdg_180_Inst0.c and SchM_Wdg_180_Inst0.h are different"
#endif
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

#if (STD_ON == WDG_SCHM_SUPPORT)
/*==================================================================================================
 *                                       LOCAL VARIABLES
==================================================================================================*/

#ifdef MCAL_SCHM_LITE

#define RTE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Rte_MemMap.h"

RTE_VAR static volatile uint8 SchM_Wdg_180_Inst0_Msr;
RTE_VAR static volatile uint8 SchM_Wdg_180_Inst0_ReentryGuard;

#define RTE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Rte_MemMap.h"

#else

#define RTE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Rte_MemMap.h"

RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_Msr_00[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_ReentryGuard_00[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_Msr_01[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_ReentryGuard_01[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_Msr_02[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_ReentryGuard_02[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_Msr_03[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_ReentryGuard_03[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_Msr_04[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_ReentryGuard_04[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_Msr_05[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_ReentryGuard_05[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_Msr_06[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_ReentryGuard_06[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_Msr_07[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_ReentryGuard_07[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_Msr_08[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_ReentryGuard_08[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_Msr_09[NUMBER_OF_CORES];
RTE_VAR static volatile uint32 SchM_Wdg_180_Inst0_ReentryGuard_09[NUMBER_OF_CORES];

#define RTE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Rte_MemMap.h"

#endif /* MCAL_SCHM_LITE */

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

/**
* @brief    This function returns the MSR register value (32 bits).
* @return   uint32 This function returns the MSR register value (32 bits).
*/
RTE_FUNC uint32 SchM_Wdg_180_Inst0_ReadMsr(void)
{
#if ((defined MCAL_ENABLE_USER_MODE_SUPPORT)&&(!defined MCAL_PLATFORM_ARM_M0PLUS))
    return __get_BASEPRI();
#else
    return __get_PRIMASK();
#endif
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

#ifdef MCAL_SCHM_LITE

RTE_FUNC void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA(void)
{
    if (0UL == SchM_Wdg_180_Inst0_ReentryGuard)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Wdg_180_Inst0_Msr = OsIf_Trusted_Call_Return(SchM_Wdg_180_Inst0_ReadMsr);
#else
        SchM_Wdg_180_Inst0_Msr = SchM_Wdg_180_Inst0_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Wdg_180_Inst0_ReentryGuard++;
}

RTE_FUNC void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA(void)
{
    SchM_Wdg_180_Inst0_ReentryGuard--;
    if ((TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr)) && (0UL == SchM_Wdg_180_Inst0_ReentryGuard))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

#else

RTE_FUNC void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_00(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Wdg_180_Inst0_ReentryGuard_00[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Wdg_180_Inst0_Msr_00[CoreId] = OsIf_Trusted_Call_Return(SchM_Wdg_180_Inst0_ReadMsr);
#else
        SchM_Wdg_180_Inst0_Msr_00[CoreId] = SchM_Wdg_180_Inst0_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_00[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Wdg_180_Inst0_ReentryGuard_00[CoreId];
}

RTE_FUNC void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_00(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Wdg_180_Inst0_ReentryGuard_00[CoreId];
    if ((TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_00[CoreId])) && (0UL == SchM_Wdg_180_Inst0_ReentryGuard_00[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_01(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Wdg_180_Inst0_ReentryGuard_01[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Wdg_180_Inst0_Msr_01[CoreId] = OsIf_Trusted_Call_Return(SchM_Wdg_180_Inst0_ReadMsr);
#else
        SchM_Wdg_180_Inst0_Msr_01[CoreId] = SchM_Wdg_180_Inst0_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_01[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Wdg_180_Inst0_ReentryGuard_01[CoreId];
}

RTE_FUNC void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_01(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Wdg_180_Inst0_ReentryGuard_01[CoreId];
    if ((TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_01[CoreId])) && (0UL == SchM_Wdg_180_Inst0_ReentryGuard_01[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_02(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Wdg_180_Inst0_ReentryGuard_02[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Wdg_180_Inst0_Msr_02[CoreId] = OsIf_Trusted_Call_Return(SchM_Wdg_180_Inst0_ReadMsr);
#else
        SchM_Wdg_180_Inst0_Msr_02[CoreId] = SchM_Wdg_180_Inst0_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_02[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Wdg_180_Inst0_ReentryGuard_02[CoreId];
}

RTE_FUNC void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_02(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Wdg_180_Inst0_ReentryGuard_02[CoreId];
    if ((TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_02[CoreId])) && (0UL == SchM_Wdg_180_Inst0_ReentryGuard_02[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_03(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Wdg_180_Inst0_ReentryGuard_03[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Wdg_180_Inst0_Msr_03[CoreId] = OsIf_Trusted_Call_Return(SchM_Wdg_180_Inst0_ReadMsr);
#else
        SchM_Wdg_180_Inst0_Msr_03[CoreId] = SchM_Wdg_180_Inst0_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_03[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Wdg_180_Inst0_ReentryGuard_03[CoreId];
}

RTE_FUNC void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_03(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Wdg_180_Inst0_ReentryGuard_03[CoreId];
    if ((TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_03[CoreId])) && (0UL == SchM_Wdg_180_Inst0_ReentryGuard_03[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_04(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Wdg_180_Inst0_ReentryGuard_04[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Wdg_180_Inst0_Msr_04[CoreId] = OsIf_Trusted_Call_Return(SchM_Wdg_180_Inst0_ReadMsr);
#else
        SchM_Wdg_180_Inst0_Msr_04[CoreId] = SchM_Wdg_180_Inst0_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_04[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Wdg_180_Inst0_ReentryGuard_04[CoreId];
}

RTE_FUNC void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_04(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Wdg_180_Inst0_ReentryGuard_04[CoreId];
    if ((TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_04[CoreId])) && (0UL == SchM_Wdg_180_Inst0_ReentryGuard_04[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_05(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Wdg_180_Inst0_ReentryGuard_05[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Wdg_180_Inst0_Msr_05[CoreId] = OsIf_Trusted_Call_Return(SchM_Wdg_180_Inst0_ReadMsr);
#else
        SchM_Wdg_180_Inst0_Msr_05[CoreId] = SchM_Wdg_180_Inst0_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_05[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Wdg_180_Inst0_ReentryGuard_05[CoreId];
}

RTE_FUNC void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_05(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Wdg_180_Inst0_ReentryGuard_05[CoreId];
    if ((TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_05[CoreId])) && (0UL == SchM_Wdg_180_Inst0_ReentryGuard_05[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_06(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Wdg_180_Inst0_ReentryGuard_06[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Wdg_180_Inst0_Msr_06[CoreId] = OsIf_Trusted_Call_Return(SchM_Wdg_180_Inst0_ReadMsr);
#else
        SchM_Wdg_180_Inst0_Msr_06[CoreId] = SchM_Wdg_180_Inst0_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_06[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Wdg_180_Inst0_ReentryGuard_06[CoreId];
}

RTE_FUNC void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_06(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Wdg_180_Inst0_ReentryGuard_06[CoreId];
    if ((TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_06[CoreId])) && (0UL == SchM_Wdg_180_Inst0_ReentryGuard_06[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_07(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Wdg_180_Inst0_ReentryGuard_07[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Wdg_180_Inst0_Msr_07[CoreId] = OsIf_Trusted_Call_Return(SchM_Wdg_180_Inst0_ReadMsr);
#else
        SchM_Wdg_180_Inst0_Msr_07[CoreId] = SchM_Wdg_180_Inst0_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_07[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Wdg_180_Inst0_ReentryGuard_07[CoreId];
}

RTE_FUNC void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_07(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Wdg_180_Inst0_ReentryGuard_07[CoreId];
    if ((TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_07[CoreId])) && (0UL == SchM_Wdg_180_Inst0_ReentryGuard_07[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_08(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Wdg_180_Inst0_ReentryGuard_08[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Wdg_180_Inst0_Msr_08[CoreId] = OsIf_Trusted_Call_Return(SchM_Wdg_180_Inst0_ReadMsr);
#else
        SchM_Wdg_180_Inst0_Msr_08[CoreId] = SchM_Wdg_180_Inst0_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_08[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Wdg_180_Inst0_ReentryGuard_08[CoreId];
}

RTE_FUNC void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_08(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Wdg_180_Inst0_ReentryGuard_08[CoreId];
    if ((TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_08[CoreId])) && (0UL == SchM_Wdg_180_Inst0_ReentryGuard_08[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_09(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    if (0UL == SchM_Wdg_180_Inst0_ReentryGuard_09[CoreId])
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Wdg_180_Inst0_Msr_09[CoreId] = OsIf_Trusted_Call_Return(SchM_Wdg_180_Inst0_ReadMsr);
#else
        SchM_Wdg_180_Inst0_Msr_09[CoreId] = SchM_Wdg_180_Inst0_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_09[CoreId])) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    ++SchM_Wdg_180_Inst0_ReentryGuard_09[CoreId];
}

RTE_FUNC void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_09(void)
{
    uint32 CoreId = OsIf_GetCoreID();
    --SchM_Wdg_180_Inst0_ReentryGuard_09[CoreId];
    if ((TRUE == ISR_ON(SchM_Wdg_180_Inst0_Msr_09[CoreId])) && (0UL == SchM_Wdg_180_Inst0_ReentryGuard_09[CoreId]))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

#endif /* MCAL_SCHM_LITE */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#endif /* #if (STD_ON == WDG_SCHM_SUPPORT) */

#ifdef __cplusplus
}
#endif

/** @} */

