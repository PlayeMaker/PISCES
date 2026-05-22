/**
* @file    SchM_Fee.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : SchM_Fee
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
*   @file    SchM_Fee.c
*
*   @addtogroup SCHM_FEE_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "OsIf.h"
#include "SchM_Fee.h"
/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_FEE_VENDOR_ID_C                      (180)
#define SCHM_FEE_AR_RELEASE_MAJOR_VERSION_C       (4)
#define SCHM_FEE_AR_RELEASE_MINOR_VERSION_C       (4)
#define SCHM_FEE_AR_RELEASE_REVISION_VERSION_C    (0)
#define SCHM_FEE_SW_MAJOR_VERSION_C               (0)
#define SCHM_FEE_SW_MINOR_VERSION_C               (9)
#define SCHM_FEE_SW_PATCH_VERSION_C               (1)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and SCHM_FEE header file are of the same vendor */
#if (SCHM_FEE_VENDOR_ID_C != SCHM_FEE_VENDOR_ID)
#error "SchM_Fee.c and SchM_Fee.h have different vendor ids"
#endif

/* Check if source file and SCHM_FEE header file are of the same Autosar version */
#if (( SCHM_FEE_AR_RELEASE_MAJOR_VERSION_C != SCHM_FEE_AR_RELEASE_MAJOR_VERSION) || \
      ( SCHM_FEE_AR_RELEASE_MINOR_VERSION_C != SCHM_FEE_AR_RELEASE_MINOR_VERSION) || \
      ( SCHM_FEE_AR_RELEASE_REVISION_VERSION_C != SCHM_FEE_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of SchM_Fee.c and SchM_Fee.h are different"
#endif

/* Check if source file and SCHM_FEE header file are of the same Software version */
#if (( SCHM_FEE_SW_MAJOR_VERSION_C != SCHM_FEE_SW_MAJOR_VERSION) || \
      ( SCHM_FEE_SW_MINOR_VERSION_C != SCHM_FEE_SW_MINOR_VERSION) || \
      ( SCHM_FEE_SW_PATCH_VERSION_C != SCHM_FEE_SW_PATCH_VERSION))
#error "Software Version Numbers of SchM_Fee.c and SchM_Fee.h are different"
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

#if(STD_ON == FEE_SCHM_SUPPORT)
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

#ifdef MCAL_SCHM_LITE

#define RTE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Rte_MemMap.h"

RTE_VAR static volatile uint8 SchM_Fee_Msr;
RTE_VAR static volatile uint8 SchM_Fee_ReentryGuard;

#define RTE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Rte_MemMap.h"

#else

#define RTE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Rte_MemMap.h"

RTE_VAR static volatile uint32 SchM_Fee_Msr_00;
RTE_VAR static volatile uint32 SchM_Fee_ReentryGuard_00;

RTE_VAR static volatile uint32 SchM_Fee_Msr_01;
RTE_VAR static volatile uint32 SchM_Fee_ReentryGuard_01;

RTE_VAR static volatile uint32 SchM_Fee_Msr_02;
RTE_VAR static volatile uint32 SchM_Fee_ReentryGuard_02;

RTE_VAR static volatile uint32 SchM_Fee_Msr_03;
RTE_VAR static volatile uint32 SchM_Fee_ReentryGuard_03;

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
RTE_FUNC uint32 SchM_Fee_ReadMsr(void)
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
                                                GLOBAL FUNCTIONS
==================================================================================================*/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

#ifdef MCAL_SCHM_LITE

RTE_FUNC void SchM_Enter_Fee_FEE_EXCLUSIVE_AREA(void)
{
    if (0UL == SchM_Fee_ReentryGuard)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Fee_Msr = OsIf_Trusted_Call_Return(SchM_Fee_ReadMsr);
#else
        SchM_Fee_Msr = SchM_Fee_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Fee_Msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Fee_ReentryGuard++;
}

RTE_FUNC void SchM_Exit_Fee_FEE_EXCLUSIVE_AREA(void)
{
    SchM_Fee_ReentryGuard--;
    if ((TRUE == ISR_ON(SchM_Fee_Msr)) && (0UL == SchM_Fee_ReentryGuard))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

#else

RTE_FUNC void SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_00(void)
{
    if (0UL == SchM_Fee_ReentryGuard_00)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Fee_Msr_00 = OsIf_Trusted_Call_Return(SchM_Fee_ReadMsr);
#else
        SchM_Fee_Msr_00 = SchM_Fee_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Fee_Msr_00)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Fee_ReentryGuard_00++;
}

RTE_FUNC void SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_00(void)
{
    SchM_Fee_ReentryGuard_00--;
    if ((TRUE == ISR_ON(SchM_Fee_Msr_00)) && (0UL == SchM_Fee_ReentryGuard_00))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_01(void)
{
    if (0UL == SchM_Fee_ReentryGuard_01)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Fee_Msr_01 = OsIf_Trusted_Call_Return(SchM_Fee_ReadMsr);
#else
        SchM_Fee_Msr_01 = SchM_Fee_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Fee_Msr_01)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Fee_ReentryGuard_01++;
}

RTE_FUNC void SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_01(void)
{
    SchM_Fee_ReentryGuard_01--;
    if ((TRUE == ISR_ON(SchM_Fee_Msr_01)) && (0UL == SchM_Fee_ReentryGuard_01))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_02(void)
{
    if (0UL == SchM_Fee_ReentryGuard_02)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Fee_Msr_02 = OsIf_Trusted_Call_Return(SchM_Fee_ReadMsr);
#else
        SchM_Fee_Msr_02 = SchM_Fee_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Fee_Msr_02)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Fee_ReentryGuard_02++;
}

RTE_FUNC void SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_02(void)
{
    SchM_Fee_ReentryGuard_02--;
    if ((TRUE == ISR_ON(SchM_Fee_Msr_02)) && (0UL == SchM_Fee_ReentryGuard_02))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_03(void)
{
    if (0UL == SchM_Fee_ReentryGuard_03)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Fee_Msr_03 = OsIf_Trusted_Call_Return(SchM_Fee_ReadMsr);
#else
        SchM_Fee_Msr_03 = SchM_Fee_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Fee_Msr_03)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Fee_ReentryGuard_03++;
}

RTE_FUNC void SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_03(void)
{
    SchM_Fee_ReentryGuard_03--;
    if ((TRUE == ISR_ON(SchM_Fee_Msr_03)) && (0UL == SchM_Fee_ReentryGuard_03))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

#endif /* MCAL_SCHM_LITE */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#endif /* STD_ON == FEE_SCHM_SUPPORT */

#ifdef __cplusplus
}
#endif

/** @} */

/* End of file SchM_Fee.c */

