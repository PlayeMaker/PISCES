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
 *   Peripheral           : WDG, EWDG
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

#ifndef SCHM_WDG_180_INST0_H
#define SCHM_WDG_180_INST0_H

#ifdef __cplusplus
extern "C" {
#endif

/* PRQA S 0777,0779 EOF */
/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Wdg_180_Inst0_Cfg.h"
/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_WDG_180_INST0_VENDOR_ID                      (180U)
#define SCHM_WDG_180_INST0_AR_RELEASE_MAJOR_VERSION       (4U)
#define SCHM_WDG_180_INST0_AR_RELEASE_MINOR_VERSION       (4U)
#define SCHM_WDG_180_INST0_AR_RELEASE_REVISION_VERSION    (0U)
#define SCHM_WDG_180_INST0_SW_MAJOR_VERSION               (0)
#define SCHM_WDG_180_INST0_SW_MINOR_VERSION               (9)
#define SCHM_WDG_180_INST0_SW_PATCH_VERSION               (1)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and WDG_180_INST0_CFG header file are of the same vendor */
#if (SCHM_WDG_180_INST0_VENDOR_ID != WDG_180_INST0_VENDOR_ID_CFG)
#error "SchM_Wdg_180_Inst0.h and Wdg_180_Inst0_Cfg.h have different vendor ids"
#endif

/* Check if header file and WDG_180_INST0_CFG header file are of the same Autosar version */
#if (( SCHM_WDG_180_INST0_AR_RELEASE_MAJOR_VERSION != WDG_180_INST0_AR_RELEASE_MAJOR_VERSION_CFG) || \
      ( SCHM_WDG_180_INST0_AR_RELEASE_MINOR_VERSION != WDG_180_INST0_AR_RELEASE_MINOR_VERSION_CFG) || \
      ( SCHM_WDG_180_INST0_AR_RELEASE_REVISION_VERSION != WDG_180_INST0_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of SchM_Wdg_180_Inst0.h and Wdg_180_Inst0_Cfg.h are different"
#endif

/* Check if header file and WDG_180_INST0_CFG header file are of the same Software version */
#if (( SCHM_WDG_180_INST0_SW_MAJOR_VERSION != WDG_180_INST0_SW_MAJOR_VERSION_CFG) || \
      ( SCHM_WDG_180_INST0_SW_MINOR_VERSION != WDG_180_INST0_SW_MINOR_VERSION_CFG) || \
      ( SCHM_WDG_180_INST0_SW_PATCH_VERSION != WDG_180_INST0_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of SchM_Wdg_180_Inst0.h and Wdg_180_Inst0_Cfg.h are different"
#endif
/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
#ifndef NUMBER_OF_CORES
#define NUMBER_OF_CORES (1U)
#endif

/*==================================================================================================
 *                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

#if (STD_ON == WDG_180_INST0_SCHM_SUPPORT)

#ifdef MCAL_SCHM_LITE

extern void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA(void);
extern void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA(void);

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_00() SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_00() SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_01() SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_01() SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_02() SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_02() SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_03() SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_03() SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_04() SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_04() SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_05() SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_05() SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_06() SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_06() SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_07() SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_07() SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_08() SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_08() SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_09() SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_09() SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA()

#else

RTE_FUNC extern void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_00(void);
RTE_FUNC extern void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_00(void);

RTE_FUNC extern void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_01(void);
RTE_FUNC extern void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_01(void);

RTE_FUNC extern void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_02(void);
RTE_FUNC extern void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_02(void);

RTE_FUNC extern void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_03(void);
RTE_FUNC extern void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_03(void);

RTE_FUNC extern void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_04(void);
RTE_FUNC extern void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_04(void);

RTE_FUNC extern void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_05(void);
RTE_FUNC extern void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_05(void);

RTE_FUNC extern void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_06(void);
RTE_FUNC extern void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_06(void);

RTE_FUNC extern void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_07(void);
RTE_FUNC extern void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_07(void);

RTE_FUNC extern void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_08(void);
RTE_FUNC extern void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_08(void);

RTE_FUNC extern void SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_09(void);
RTE_FUNC extern void SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_09(void);

#endif /* MCAL_SCHM_LITE */

#else

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_00()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_00()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_01()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_01()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_02()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_02()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_03()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_03()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_04()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_04()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_05()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_05()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_06()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_06()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_07()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_07()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_08()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_08()

#define SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_09()
#define SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_09()

#endif /* (STD_ON == WDG_180_INST0_SCHM_SUPPORT) */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* SCHM_WDG_180_INST0_H */

/** @} */

