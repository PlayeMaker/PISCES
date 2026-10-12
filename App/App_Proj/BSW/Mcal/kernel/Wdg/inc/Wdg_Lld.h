/**
 * @file    Wdg_Lld.h
 * @version V0.9.1
 *
 * @brief   YUNTU Wdg_Lld module interface
 * @details API implementation for Wdg_Lld driver
 *
 * @addtogroup WDG_LLD_MODULE
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

#ifndef WDG_LLD_H
#define WDG_LLD_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Wdg_Lld_Types.h"
#include "Wdg_180_Inst0_Cfg.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_LLD_VENDOR_ID                      (180)
#define WDG_LLD_MODULE_ID           (102)
#define WDG_LLD_AR_RELEASE_MAJOR_VERSION       (4)
#define WDG_LLD_AR_RELEASE_MINOR_VERSION       (4)
#define WDG_LLD_AR_RELEASE_REVISION_VERSION    (0)
#define WDG_LLD_SW_MAJOR_VERSION               (0)
#define WDG_LLD_SW_MINOR_VERSION               (9)
#define WDG_LLD_SW_PATCH_VERSION               (1)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Wdg_Lld.h and Wdg_Lld_Types.h are of the same vendor */
#if (WDG_LLD_VENDOR_ID != WDG_LLD_TYPES_VENDOR_ID)
#error "Wdg_Lld.h and Wdg_Lld_Types.h have different vendor ids"
#endif

/* Check if Wdg_Lld.h and Wdg_Lld_Types.h are of the same Autosar version */
#if ((WDG_LLD_AR_RELEASE_MAJOR_VERSION != WDG_LLD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_LLD_AR_RELEASE_MINOR_VERSION != WDG_LLD_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_LLD_AR_RELEASE_REVISION_VERSION != WDG_LLD_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_Lld.h and Wdg_Lld_Types.h are different"
#endif

/* Check if Wdg_Lld.h and Wdg_Lld_Types.h are of the same software version */
#if ((WDG_LLD_SW_MAJOR_VERSION != WDG_LLD_TYPES_SW_MAJOR_VERSION) || \
     (WDG_LLD_SW_MINOR_VERSION != WDG_LLD_TYPES_SW_MINOR_VERSION) || \
     (WDG_LLD_SW_PATCH_VERSION != WDG_LLD_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Lld.h and Wdg_Lld_Types.h are different"
#endif

/* Check if Wdg_Lld.h and Wdg_180_Inst0_Cfg.h are of the same vendor */
#if (WDG_LLD_VENDOR_ID != WDG_180_INST0_VENDOR_ID_CFG)
#error "Wdg_Lld.h and Wdg_180_Inst0_Cfg.h have different vendor ids"
#endif

/* Check if Wdg_Lld.h and Wdg_180_Inst0_Cfg.h are of the same Autosar version */
#if ((WDG_LLD_AR_RELEASE_MAJOR_VERSION != WDG_180_INST0_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (WDG_LLD_AR_RELEASE_MINOR_VERSION != WDG_180_INST0_AR_RELEASE_MINOR_VERSION_CFG) || \
     (WDG_LLD_AR_RELEASE_REVISION_VERSION != WDG_180_INST0_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Wdg_Lld.h and Wdg_180_Inst0_Cfg.h are different"
#endif

/* Check if Wdg_Lld.h and Wdg_180_Inst0_Cfg.h are of the same software version */
#if ((WDG_LLD_SW_MAJOR_VERSION != WDG_180_INST0_SW_MAJOR_VERSION_CFG) || \
     (WDG_LLD_SW_MINOR_VERSION != WDG_180_INST0_SW_MINOR_VERSION_CFG) || \
     (WDG_LLD_SW_PATCH_VERSION != WDG_180_INST0_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Wdg_Lld.h and Wdg_180_Inst0_Cfg.h are different"
#endif

#if (WDG_180_INST0_ENABLE == STD_ON)
/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
==================================================================================================*/
#if (WDG_180_INST0_RUN_ON_ROM == STD_ON)
#define WDG_180_INST0_START_SEC_CODE
#else
#define WDG_180_INST0_START_SEC_RAMCODE
#endif
#include "Wdg_180_Inst0_MemMap.h"           /* NOSONAR, memory map */

/**
 * @brief       This function initializes the WDG hardware.
 * @param[in]   Instance WDG hardware instance
 * @param[in]   WdgConfig WDG hardware configuration
 * @return      Std_ReturnType
 * @retval      E_OK WDG hardware initialization success
 * @retval      E_NOT_OK WDG hardware initialization failed
 */
WDG_180_INST0_FUNC Std_ReturnType Wdg_Lld_Init(uint8 Instance, const Wdg_Lld_ConfigType *const WdgConfig);

#if (WDG_180_INST0_DISABLE_ALLOWED == STD_ON)
/**
 * @brief       This function de-initializes the WDG driver
 * @param[in]   Instance WDG instance
 * @return      Std_ReturnType
 * @retval      E_OK WDG de-initialization success
 * @retval      E_NOT_OK WDG de-initialization failed
 */
WDG_180_INST0_FUNC Std_ReturnType Wdg_Lld_DeInit(uint8 Instance);
#endif /* (WDG_180_INST0_DISABLE_ALLOWED == STD_ON) */

/**
 * @brief       This function refreshes the WDG counter
 * @param[in]   Instance WDG instance
 * @return      void
 */
WDG_180_INST0_FUNC void Wdg_Lld_Service(uint8 Instance);

/**
 * @brief       This function reconfigures the WDG hardware.
 * @param[in]   Instance WDG hardware instance
 * @param[in]   WdgConfig WDG hardware configuration
 * @return      Std_ReturnType
 * @retval      E_OK WDG hardware reconfiguration success
 * @retval      E_NOT_OK WDG hardware reconfiguration failed
 */
WDG_180_INST0_FUNC Std_ReturnType Wdg_Lld_Config(uint8 Instance, const Wdg_Lld_ConfigType *const WdgConfig);

/**
 * @brief       This function sets the WDG hardware timeout value.
 * @param[in]   Instance WDG hardware instance
 * @param[in]   TimeoutValue WDG hardware timeout value
 * @param[in]   WindowValue WDG hardware window value
 * @return      Std_ReturnType
 * @retval      E_OK set the WDG hardware timeout value success
 * @retval      E_NOT_OK set the WDG hardware timeout value failed
 */
WDG_180_INST0_FUNC Std_ReturnType Wdg_Lld_SetTimeout(uint8 Instance, uint32 TimeoutValue, uint32 WindowValue);

/**
 * @brief       This function starts the WDG hardware.
 * @param[in]   Instance WDG hardware instance
 * @return      Std_ReturnType
 * @retval      E_OK WDG hardware start success
 * @retval      E_NOT_OK WDG hardware start failed
 */
WDG_180_INST0_FUNC Std_ReturnType Wdg_Lld_StartTimer(uint8 Instance);

/**
 * @brief       This function stops the WDG hardware.
 * @param[in]   Instance WDG hardware instance
 * @return      Std_ReturnType
 * @retval      E_OK WDG hardware stop success
 * @retval      E_NOT_OK WDG hardware stop failed
 */
WDG_180_INST0_FUNC Std_ReturnType Wdg_Lld_StopTimer(uint8 Instance);

/**
 * @brief       WDG instance interrupt handler.
 * @details     This function handles the different WDG instances interrupt.
 * @param[in]   Instance WDG hardware instance
 * @return      void
 */
WDG_180_INST0_FUNC void Wdg_Lld_IrqHandler(uint8 Instance);

#if (WDG_180_INST0_RUN_ON_ROM == STD_ON)
#define WDG_180_INST0_STOP_SEC_CODE
#else
#define WDG_180_INST0_STOP_SEC_RAMCODE
#endif
#include "Wdg_180_Inst0_MemMap.h"    /* NOSONAR, memory map */

#endif /* #if (WDG_180_INST0_ENABLE == STD_ON) */

#ifdef __cplusplus
}
#endif

#endif /* WDG_LLD_H */

/** @} */

