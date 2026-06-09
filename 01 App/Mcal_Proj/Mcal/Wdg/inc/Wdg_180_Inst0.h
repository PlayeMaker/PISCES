/**
 * @file    Wdg_180_Inst0.h
 * @version V0.9.1
 *
 * @brief   YUNTU Wdg_180_Inst0 module interface
 * @details API implementation for Wdg_180_Inst0 driver
 *
 * @addtogroup WDG_180_INST0_MODULE
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
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/

#ifndef WDG_180_INST0_H
#define WDG_180_INST0_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                          INCLUDE FILES
==================================================================================================*/
#include "Wdg_180_Inst0_Cfg.h"
#include "Std_Types.h"
#include "WdgIf_Types.h"
#include "Wdg_180_Inst0_Types.h"

#ifdef WDG_180_INST0_ENABLE
#if (WDG_180_INST0_ENABLE == STD_ON)

/*==================================================================================================
 *                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_180_INST0_VENDOR_ID                      (180)
#define WDG_180_INST0_MODULE_ID             (102)
#define WDG_180_INST0_AR_RELEASE_MAJOR_VERSION       (4)
#define WDG_180_INST0_AR_RELEASE_MINOR_VERSION       (4)
#define WDG_180_INST0_AR_RELEASE_REVISION_VERSION    (0)
#define WDG_180_INST0_SW_MAJOR_VERSION               (0)
#define WDG_180_INST0_SW_MINOR_VERSION               (9)
#define WDG_180_INST0_SW_PATCH_VERSION               (1)

/*==================================================================================================
 *                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Wdg_180_Inst0.h and Wdg_180_Inst0_Cfg.h are of the same vendor */
#if (WDG_180_INST0_VENDOR_ID != WDG_180_INST0_VENDOR_ID_CFG)
#error "Wdg_180_Inst0.h and Wdg_180_Inst0_Cfg.h have different vendor ids"
#endif

/* Check if Wdg_180_Inst0.h and Wdg_180_Inst0_Cfg.h are of the same Autosar version */
#if ((WDG_180_INST0_AR_RELEASE_MAJOR_VERSION != WDG_180_INST0_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (WDG_180_INST0_AR_RELEASE_MINOR_VERSION != WDG_180_INST0_AR_RELEASE_MINOR_VERSION_CFG) || \
     (WDG_180_INST0_AR_RELEASE_REVISION_VERSION != WDG_180_INST0_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Wdg_180_Inst0.h and Wdg_180_Inst0_Cfg.h are different"
#endif

/* Check if Wdg_180_Inst0.h and Wdg_180_Inst0_Cfg.h are of the same software version */
#if ((WDG_180_INST0_SW_MAJOR_VERSION != WDG_180_INST0_SW_MAJOR_VERSION_CFG) || \
     (WDG_180_INST0_SW_MINOR_VERSION != WDG_180_INST0_SW_MINOR_VERSION_CFG) || \
     (WDG_180_INST0_SW_PATCH_VERSION != WDG_180_INST0_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Wdg_180_Inst0.h and Wdg_180_Inst0_Cfg.h are different"
#endif

/* Check if Wdg_180_Inst0.h and Wdg_180_Inst0_Types.h are of the same vendor */
#if (WDG_180_INST0_VENDOR_ID != WDG_180_INST0_TYPES_VENDOR_ID)
#error "Wdg_180_Inst0.h and Wdg_180_Inst0_Types.h have different vendor ids"
#endif

/* Check if Wdg_180_Inst0.h and Wdg_180_Inst0_Types.h are of the same Autosar version */
#if ((WDG_180_INST0_AR_RELEASE_MAJOR_VERSION != WDG_180_INST0_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_180_INST0_AR_RELEASE_MINOR_VERSION != WDG_180_INST0_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_180_INST0_AR_RELEASE_REVISION_VERSION != WDG_180_INST0_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_180_Inst0.h and Wdg_180_Inst0_Types.h are different"
#endif

/* Check if Wdg_180_Inst0.h and Wdg_180_Inst0_Types.h are of the same software version */
#if ((WDG_180_INST0_SW_MAJOR_VERSION != WDG_180_INST0_TYPES_SW_MAJOR_VERSION) || \
     (WDG_180_INST0_SW_MINOR_VERSION != WDG_180_INST0_TYPES_SW_MINOR_VERSION) || \
     (WDG_180_INST0_SW_PATCH_VERSION != WDG_180_INST0_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_180_Inst0.h and Wdg_180_Inst0_Types.h are different"
#endif

/*==================================================================================================
 *                                      FUNCTION PROTOTYPES
==================================================================================================*/
#if (WDG_180_INST0_RUN_ON_ROM == STD_ON)
#define WDG_180_INST0_START_SEC_CODE
#else
#define WDG_180_INST0_START_SEC_RAMCODE
#endif
#include "Wdg_180_Inst0_MemMap.h"           /* NOSONAR, memory map */

/**
 * @brief       Initializes the WDG module.
 * @param[in]   ConfigPtr Pointer to configuration set
 * @return      void
 */
WDG_180_INST0_FUNC void Wdg_180_Inst0_Init(const Wdg_180_Inst0_ConfigType *ConfigPtr);

/**
 * @brief       Switches the watchdog into the mode Mode.
 * @param[in]   Mode WDGIF_OFF_MODE, WDGIF_SLOW_MODE, WDGIF_FAST_MODE
 * @return      Std_ReturnType
 * @retval      E_OK Mode switch was successful.
 * @retval      E_NOT_OK Mode switch was not successful.
 */
WDG_180_INST0_FUNC Std_ReturnType Wdg_180_Inst0_SetMode(WdgIf_ModeType Mode);

#if (WDG_180_INST0_MANUAL_SERVICE == STD_OFF)
/**
 * @brief       Sets the timeout value for the trigger counter.
 * @param[in]   Timeout Timeout value (milliseconds) for setting the trigger counter.
 * @return      void
 */
WDG_180_INST0_FUNC void Wdg_180_Inst0_SetTriggerCondition(uint16 Timeout);
#endif

#if (WDG_180_INST0_MANUAL_SERVICE == STD_ON)
/**
 * @brief       Refreshes the watchdog timer Manually.
 * @return      void
 */
WDG_180_INST0_FUNC void Wdg_180_Inst0_Service(void);
#endif

#if (WDG_180_INST0_VERSION_INFO_API == STD_ON)
/**
 * @brief       Returns the version information of the module.
 * @param[out]  VersionInfo Pointer to where to store the version information of this module.
 * @return      void
 */
WDG_180_INST0_FUNC void Wdg_180_Inst0_GetVersionInfo(Std_VersionInfoType *VersionInfo);
#endif

#if (WDG_180_INST0_RUN_ON_ROM == STD_ON)
#define WDG_180_INST0_STOP_SEC_CODE
#else
#define WDG_180_INST0_STOP_SEC_RAMCODE
#endif
#include "Wdg_180_Inst0_MemMap.h"           /* NOSONAR, memory map */

#endif /* #if (WDG_180_INST0_ENABLE == STD_ON) */
#endif /* #ifdef WDG_180_INST0_ENABLE */

#ifdef __cplusplus
}
#endif

#endif /* WDG_180_INST0_H */

/** @} */

