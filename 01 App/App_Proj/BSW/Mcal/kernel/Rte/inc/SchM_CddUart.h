/*
* @file    SchM_CddUart.h
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
#ifndef SCHM_CDDUART_H
#define SCHM_CDDUART_H

/**
*   @file    SchM_CddUart.h
*
*   @addtogroup SCHM_CDDUART_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 0777 Rule 5.1: External identifiers shall be distinct
 * PRQA S 0779 Rule 5.2: Identifiers declared in the same scope and name space shall be distinct
 * PRQA S 0787 Rule 5.5: Identifiers shall be distinct from macro names. it's required when "MCAL_SCHM_LITE" is defined
 */
/* MR12 RULE 5.1 VIOLATION: The naming of the functions SchM_Enter and SchM_Exit follows the AUTOSAR_SWS_RTE documentation
 * standards but does not comply with M3CM Rule-5.1 (0777).
 */
/* MR12 RULE 5.2 VIOLATION: The naming of the functions SchM_Enter and SchM_Exit follows the AUTOSAR_SWS_RTE documentation
 * standards but does not comply with M3CM Rule-5.2 (0779).
 */
/* MR12 RULE 5.5 VIOLATION: The naming of the functions SchM_Enter and SchM_Exit implemented
 * with the macro define to reuse the code and reduce size, it's full tested and verified with no risks.
 * standards but does not comply with M3CM Rule-5.5 (0787).
 */
/* PRQA S 0777,0779,0787 EOF */
/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "CddUart_Cfg.h"
/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define SCHM_CDDUART_VENDOR_ID                      (180)
#define SCHM_CDDUART_AR_RELEASE_MAJOR_VERSION       (4)
#define SCHM_CDDUART_AR_RELEASE_MINOR_VERSION       (4)
#define SCHM_CDDUART_AR_RELEASE_REVISION_VERSION    (0)
#define SCHM_CDDUART_SW_MAJOR_VERSION               (0)
#define SCHM_CDDUART_SW_MINOR_VERSION               (9)
#define SCHM_CDDUART_SW_PATCH_VERSION               (1)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CDDUART Configure header file are of the same vendor */
#if (SCHM_CDDUART_VENDOR_ID != CDDUART_VENDOR_ID_CFG)
#error "SchM_CddUart.h and CddUart_Cfg.h have different vendor ids"
#endif

/* Check if source file and CDDUART Configure header file are of the same Autosar version */
#if (( SCHM_CDDUART_AR_RELEASE_MAJOR_VERSION != CDDUART_AR_RELEASE_MAJOR_VERSION_CFG) || \
     ( SCHM_CDDUART_AR_RELEASE_MINOR_VERSION != CDDUART_AR_RELEASE_MINOR_VERSION_CFG) || \
     ( SCHM_CDDUART_AR_RELEASE_REVISION_VERSION != CDDUART_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of SchM_CddUart.h and CddUart_Cfg.h are different"
#endif

/* Check if source file and CDDUART Configure header file are of the same Software version */
#if (( SCHM_CDDUART_SW_MAJOR_VERSION != CDDUART_SW_MAJOR_VERSION_CFG) || \
     ( SCHM_CDDUART_SW_MINOR_VERSION != CDDUART_SW_MINOR_VERSION_CFG) || \
     ( SCHM_CDDUART_SW_PATCH_VERSION != CDDUART_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of SchM_CddUart.h and CddUart_Cfg.h are different"
#endif

/*==================================================================================================
                                                DEFINES AND MACROS
==================================================================================================*/

/* Number of cores id */
#ifndef NUMBER_OF_CORES
#define NUMBER_OF_CORES         (uint8)(1U)
#endif /* NUMBER_OF_CORES */

/*==================================================================================================
                                                EXTERNAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                ENUMS
==================================================================================================*/
/*==================================================================================================
                                                FUNCTION PROTOTYPES
==================================================================================================*/

#if(STD_ON == CDDUART_SCHM_SUPPORT)

#ifdef MCAL_SCHM_LITE

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA(void);

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_00() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_00() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_01() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_01() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_02() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_02() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_03() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_03() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_04() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_04() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_05() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_05() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_06() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_06() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_07() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_07() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_08() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_08() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_09() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_09() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_10() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_10() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_11() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_11() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_12() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_12() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_13() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_13() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_14() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_14() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_15() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_15() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_16() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_16() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_17() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_17() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_18() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_18() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_19() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_19() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_20() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_20() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_21() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_21() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_22() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_22() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_23() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_23() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_24() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_24() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_25() SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_25() SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA()

#else

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_00(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_00(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_01(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_01(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_02(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_02(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_03(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_03(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_04(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_04(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_05(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_05(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_06(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_06(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_07(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_07(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_08(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_08(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_09(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_09(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_10(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_10(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_11(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_11(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_12(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_12(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_13(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_13(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_14(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_14(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_15(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_15(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_16(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_16(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_17(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_17(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_18(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_18(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_19(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_19(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_20(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_20(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_21(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_21(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_22(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_22(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_23(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_23(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_24(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_24(void);

extern void SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_25(void);
extern void SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_25(void);

#endif /* MCAL_SCHM_LITE */

#else

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_00()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_00()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_01()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_01()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_02()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_02()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_03()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_03()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_04()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_04()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_05()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_05()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_06()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_06()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_07()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_07()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_08()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_08()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_09()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_09()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_10()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_10()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_11()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_11()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_12()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_12()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_13()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_13()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_14()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_14()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_15()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_15()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_16()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_16()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_17()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_17()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_18()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_18()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_19()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_19()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_20()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_20()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_21()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_21()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_22()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_22()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_23()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_23()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_24()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_24()

#define SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_25()
#define SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_25()

#endif /* (STD_ON == CDDUART_SCHM_SUPPORT) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* End of file SchM_CddUart.h */
