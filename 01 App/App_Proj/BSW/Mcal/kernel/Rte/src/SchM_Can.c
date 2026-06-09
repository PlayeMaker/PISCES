/**
* @file    SchM_Can.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : SchM_Can
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
*   @file    SchM_Can.c
*
*   @addtogroup SCHM_CAN_MODULE
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
#include "SchM_Can.h"
/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_CAN_VENDOR_ID_C                      (180)
#define SCHM_CAN_AR_RELEASE_MAJOR_VERSION_C       (4)
#define SCHM_CAN_AR_RELEASE_MINOR_VERSION_C       (4)
#define SCHM_CAN_AR_RELEASE_REVISION_VERSION_C    (0)
#define SCHM_CAN_SW_MAJOR_VERSION_C               (0)
#define SCHM_CAN_SW_MINOR_VERSION_C               (9)
#define SCHM_CAN_SW_PATCH_VERSION_C               (1)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and SCHM_CAN header file are of the same vendor */
#if (SCHM_CAN_VENDOR_ID_C != SCHM_CAN_VENDOR_ID)
#error "SchM_Can.c and SchM_Can.h have different vendor ids"
#endif

/* Check if source file and SCHM_CAN header file are of the same Autosar version */
#if (( SCHM_CAN_AR_RELEASE_MAJOR_VERSION_C != SCHM_CAN_AR_RELEASE_MAJOR_VERSION) || \
      ( SCHM_CAN_AR_RELEASE_MINOR_VERSION_C != SCHM_CAN_AR_RELEASE_MINOR_VERSION) || \
      ( SCHM_CAN_AR_RELEASE_REVISION_VERSION_C != SCHM_CAN_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of SchM_Can.c and SchM_Can.h are different"
#endif

/* Check if source file and SCHM_CAN header file are of the same Software version */
#if (( SCHM_CAN_SW_MAJOR_VERSION_C != SCHM_CAN_SW_MAJOR_VERSION) || \
      ( SCHM_CAN_SW_MINOR_VERSION_C != SCHM_CAN_SW_MINOR_VERSION) || \
      ( SCHM_CAN_SW_PATCH_VERSION_C != SCHM_CAN_SW_PATCH_VERSION))
#error "Software Version Numbers of SchM_Can.c and SchM_Can.h are different"
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

#if(STD_ON == CAN_SCHM_SUPPORT)
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

#ifdef MCAL_SCHM_LITE

#define RTE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Rte_MemMap.h"

RTE_VAR static volatile uint8 SchM_Can_Msr;
RTE_VAR static volatile uint8 SchM_Can_ReentryGuard;

#define RTE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
#include "Rte_MemMap.h"

#else

#define RTE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Rte_MemMap.h"

RTE_VAR static volatile uint32 SchM_Can_Msr_00;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_00;
RTE_VAR static volatile uint32 SchM_Can_Msr_01;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_01;
RTE_VAR static volatile uint32 SchM_Can_Msr_02;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_02;
#if ((CAN_BUSOFF_PROCESS_HAS_INTERRUPT == STD_ON) || (CAN_SCHM_CONTINUOUSLY == STD_ON))
RTE_VAR static volatile uint32 SchM_Can_Msr_03;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_03;
#endif
#if ((CAN_DMA_USAGE == STD_ON) || (CAN_SCHM_CONTINUOUSLY == STD_ON))
RTE_VAR static volatile uint32 SchM_Can_Msr_04;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_04;
#endif
#if (((CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON) && (CAN_LEGACY_FIFO_USAGE == STD_ON)) || (CAN_SCHM_CONTINUOUSLY == STD_ON))
RTE_VAR static volatile uint32 SchM_Can_Msr_05;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_05;
#endif
RTE_VAR static volatile uint32 SchM_Can_Msr_06;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_06;
RTE_VAR static volatile uint32 SchM_Can_Msr_07;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_07;
RTE_VAR static volatile uint32 SchM_Can_Msr_08;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_08;
RTE_VAR static volatile uint32 SchM_Can_Msr_09;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_09;
RTE_VAR static volatile uint32 SchM_Can_Msr_10;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_10;
RTE_VAR static volatile uint32 SchM_Can_Msr_11;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_11;
RTE_VAR static volatile uint32 SchM_Can_Msr_12;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_12;
RTE_VAR static volatile uint32 SchM_Can_Msr_13;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_13;
RTE_VAR static volatile uint32 SchM_Can_Msr_14;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_14;
RTE_VAR static volatile uint32 SchM_Can_Msr_15;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_15;
RTE_VAR static volatile uint32 SchM_Can_Msr_16;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_16;
RTE_VAR static volatile uint32 SchM_Can_Msr_17;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_17;
RTE_VAR static volatile uint32 SchM_Can_Msr_18;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_18;
RTE_VAR static volatile uint32 SchM_Can_Msr_19;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_19;
#if ((CAN_LEGACY_FIFO_USAGE == STD_ON) || (CAN_SCHM_CONTINUOUSLY == STD_ON))
RTE_VAR static volatile uint32 SchM_Can_Msr_20;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_20;
#endif
RTE_VAR static volatile uint32 SchM_Can_Msr_21;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_21;
#if (((CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON) || (CAN_TX_PROCESS_HAS_INTERRUPT == STD_ON)) || (CAN_SCHM_CONTINUOUSLY == STD_ON))
RTE_VAR static volatile uint32 SchM_Can_Msr_22;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_22;
#endif
RTE_VAR static volatile uint32 SchM_Can_Msr_23;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_23;
RTE_VAR static volatile uint32 SchM_Can_Msr_24;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_24;
RTE_VAR static volatile uint32 SchM_Can_Msr_25;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_25;
RTE_VAR static volatile uint32 SchM_Can_Msr_26;
RTE_VAR static volatile uint32 SchM_Can_ReentryGuard_26;

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
RTE_FUNC uint32 SchM_Can_ReadMsr(void)
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

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA(void)
{
    if (0UL == SchM_Can_ReentryGuard)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA(void)
{
    SchM_Can_ReentryGuard--;
    if ((TRUE == ISR_ON(SchM_Can_Msr)) && (0UL == SchM_Can_ReentryGuard))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

#else

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_00(void)
{
    if (0UL == SchM_Can_ReentryGuard_00)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_00 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_00 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_00)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_00++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_00(void)
{
    SchM_Can_ReentryGuard_00--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_00)) && (0UL == SchM_Can_ReentryGuard_00))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_01(void)
{
    if (0UL == SchM_Can_ReentryGuard_01)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_01 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_01 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_01)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_01++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_01(void)
{
    SchM_Can_ReentryGuard_01--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_01)) && (0UL == SchM_Can_ReentryGuard_01))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_02(void)
{
    if (0UL == SchM_Can_ReentryGuard_02)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_02 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_02 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_02)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_02++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_02(void)
{
    SchM_Can_ReentryGuard_02--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_02)) && (0UL == SchM_Can_ReentryGuard_02))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
#if ((CAN_BUSOFF_PROCESS_HAS_INTERRUPT == STD_ON) || (CAN_SCHM_CONTINUOUSLY == STD_ON))
RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_03(void)
{
    if (0UL == SchM_Can_ReentryGuard_03)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_03 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_03 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_03)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_03++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_03(void)
{
    SchM_Can_ReentryGuard_03--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_03)) && (0UL == SchM_Can_ReentryGuard_03))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
#endif
#if ((CAN_DMA_USAGE == STD_ON) || (CAN_SCHM_CONTINUOUSLY == STD_ON))
RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_04(void)
{
    if (0UL == SchM_Can_ReentryGuard_04)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_04 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_04 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_04)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_04++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_04(void)
{
    SchM_Can_ReentryGuard_04--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_04)) && (0UL == SchM_Can_ReentryGuard_04))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
#endif

#if (((CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON) && (CAN_LEGACY_FIFO_USAGE == STD_ON)) || (CAN_SCHM_CONTINUOUSLY == STD_ON))
RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05(void)
{
    if (0UL == SchM_Can_ReentryGuard_05)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_05 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_05 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_05)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_05++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05(void)
{
    SchM_Can_ReentryGuard_05--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_05)) && (0UL == SchM_Can_ReentryGuard_05))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
#endif

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_06(void)
{
    if (0UL == SchM_Can_ReentryGuard_06)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_06 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_06 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_06)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_06++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_06(void)
{
    SchM_Can_ReentryGuard_06--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_06)) && (0UL == SchM_Can_ReentryGuard_06))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_07(void)
{
    if (0UL == SchM_Can_ReentryGuard_07)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_07 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_07 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_07)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_07++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_07(void)
{
    SchM_Can_ReentryGuard_07--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_07)) && (0UL == SchM_Can_ReentryGuard_07))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_08(void)
{
    if (0UL == SchM_Can_ReentryGuard_08)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_08 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_08 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_08)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_08++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_08(void)
{
    SchM_Can_ReentryGuard_08--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_08)) && (0UL == SchM_Can_ReentryGuard_08))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_09(void)
{
    if (0UL == SchM_Can_ReentryGuard_09)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_09 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_09 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_09)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_09++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_09(void)
{
    SchM_Can_ReentryGuard_09--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_09)) && (0UL == SchM_Can_ReentryGuard_09))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_10(void)
{
    if (0UL == SchM_Can_ReentryGuard_10)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_10 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_10 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_10)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_10++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_10(void)
{
    SchM_Can_ReentryGuard_10--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_10)) && (0UL == SchM_Can_ReentryGuard_10))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_11(void)
{
    if (0UL == SchM_Can_ReentryGuard_11)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_11 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_11 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_11)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_11++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_11(void)
{
    SchM_Can_ReentryGuard_11--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_11)) && (0UL == SchM_Can_ReentryGuard_11))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_12(void)
{
    if (0UL == SchM_Can_ReentryGuard_12)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_12 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_12 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_12)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_12++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_12(void)
{
    SchM_Can_ReentryGuard_12--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_12)) && (0UL == SchM_Can_ReentryGuard_12))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_13(void)
{
    if (0UL == SchM_Can_ReentryGuard_13)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_13 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_13 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_13)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_13++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_13(void)
{
    SchM_Can_ReentryGuard_13--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_13)) && (0UL == SchM_Can_ReentryGuard_13))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_14(void)
{
    if (0UL == SchM_Can_ReentryGuard_14)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_14 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_14 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_14)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_14++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_14(void)
{
    SchM_Can_ReentryGuard_14--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_14)) && (0UL == SchM_Can_ReentryGuard_14))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_15(void)
{
    if (0UL == SchM_Can_ReentryGuard_15)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_15 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_15 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_15)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_15++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_15(void)
{
    SchM_Can_ReentryGuard_15--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_15)) && (0UL == SchM_Can_ReentryGuard_15))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_16(void)
{
    if (0UL == SchM_Can_ReentryGuard_16)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_16 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_16 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_16)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_16++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_16(void)
{
    SchM_Can_ReentryGuard_16--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_16)) && (0UL == SchM_Can_ReentryGuard_16))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_17(void)
{
    if (0UL == SchM_Can_ReentryGuard_17)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_17 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_17 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_17)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_17++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_17(void)
{
    SchM_Can_ReentryGuard_17--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_17)) && (0UL == SchM_Can_ReentryGuard_17))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_18(void)
{
    if (0UL == SchM_Can_ReentryGuard_18)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_18 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_18 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_18)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_18++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_18(void)
{
    SchM_Can_ReentryGuard_18--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_18)) && (0UL == SchM_Can_ReentryGuard_18))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_19(void)
{
    if (0UL == SchM_Can_ReentryGuard_19)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_19 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_19 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_19)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_19++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_19(void)
{
    SchM_Can_ReentryGuard_19--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_19)) && (0UL == SchM_Can_ReentryGuard_19))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
#if ((CAN_LEGACY_FIFO_USAGE == STD_ON) || (CAN_SCHM_CONTINUOUSLY == STD_ON))
RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_20(void)
{
    if (0UL == SchM_Can_ReentryGuard_20)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_20 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_20 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_20)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_20++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_20(void)
{
    SchM_Can_ReentryGuard_20--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_20)) && (0UL == SchM_Can_ReentryGuard_20))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
#endif

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_21(void)
{
    if (0UL == SchM_Can_ReentryGuard_21)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_21 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_21 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_21)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_21++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_21(void)
{
    SchM_Can_ReentryGuard_21--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_21)) && (0UL == SchM_Can_ReentryGuard_21))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

#if (((CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON) || (CAN_TX_PROCESS_HAS_INTERRUPT == STD_ON)) || (CAN_SCHM_CONTINUOUSLY == STD_ON))
RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_22(void)
{
    if (0UL == SchM_Can_ReentryGuard_22)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_22 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_22 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_22)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_22++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_22(void)
{
    SchM_Can_ReentryGuard_22--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_22)) && (0UL == SchM_Can_ReentryGuard_22))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}
#endif

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_23(void)
{
    if (0UL == SchM_Can_ReentryGuard_23)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_23 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_23 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_23)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_23++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_23(void)
{
    SchM_Can_ReentryGuard_23--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_23)) && (0UL == SchM_Can_ReentryGuard_23))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_24(void)
{
    if (0UL == SchM_Can_ReentryGuard_24)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_24 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_24 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_24)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_24++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_24(void)
{
    SchM_Can_ReentryGuard_24--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_24)) && (0UL == SchM_Can_ReentryGuard_24))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_25(void)
{
    if (0UL == SchM_Can_ReentryGuard_25)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_25 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_25 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_25)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_25++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_25(void)
{
    SchM_Can_ReentryGuard_25--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_25)) && (0UL == SchM_Can_ReentryGuard_25))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

RTE_FUNC void SchM_Enter_Can_CAN_EXCLUSIVE_AREA_26(void)
{
    if (0UL == SchM_Can_ReentryGuard_26)
    {
#if (defined MCAL_ENABLE_USER_MODE_SUPPORT)
        SchM_Can_Msr_26 = OsIf_Trusted_Call_Return(SchM_Can_ReadMsr);
#else
        SchM_Can_Msr_26 = SchM_Can_ReadMsr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
        if (TRUE == ISR_ON(SchM_Can_Msr_26)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
        {
            OsIf_SuspendAllInterrupts();
        }
    }
    SchM_Can_ReentryGuard_26++;
}

RTE_FUNC void SchM_Exit_Can_CAN_EXCLUSIVE_AREA_26(void)
{
    SchM_Can_ReentryGuard_26--;
    if ((TRUE == ISR_ON(SchM_Can_Msr_26)) && (0UL == SchM_Can_ReentryGuard_26))       /*if interrupts were enabled*/
    {
        OsIf_ResumeAllInterrupts();
    }
}

#endif /* MCAL_SCHM_LITE*/

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#endif /* STD_ON == CAN_SCHM_SUPPORT */

#ifdef __cplusplus
}
#endif

/** @} */

/* End of file SchM_Can.c */

