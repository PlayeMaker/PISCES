
#ifndef CDDUART_CFG_H
#define CDDUART_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "CddUart_Types.h"
#include "CddUart_Mld_PBcfg.h"
#include "CddUart_Lld_UartCfg.h"
#include "CddUart_PBcfg.h"
/*==================================================================================================
*                               FILE VERSION INFORMATION
==================================================================================================*/
#define CDDUART_VENDOR_ID_CFG                      (180)
#define CDDUART_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define CDDUART_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define CDDUART_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define CDDUART_SW_MAJOR_VERSION_CFG               (0)
#define CDDUART_SW_MINOR_VERSION_CFG               (9)
#define CDDUART_SW_PATCH_VERSION_CFG               (1)
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CddUart header file are of the same Autosar version */
#if (CDDUART_VENDOR_ID_CFG != CDDUART_VENDOR_ID_MLD_CFG)
#error "CddUart_Mld_PBcfg.h and CddUart_Cfg.h have different vendor ids"
#endif

/* Check if source file and CddUart header file are of the same Autosar version */
#if ((CDDUART_AR_RELEASE_MAJOR_VERSION_CFG != CDDUART_AR_RELEASE_MAJOR_VERSION_MLD_CFG) || \
     (CDDUART_AR_RELEASE_MINOR_VERSION_CFG != CDDUART_AR_RELEASE_MINOR_VERSION_MLD_CFG) || \
     (CDDUART_AR_RELEASE_REVISION_VERSION_CFG != CDDUART_AR_RELEASE_REVISION_VERSION_MLD_CFG) \
    )
#error "AutoSar Version Numbers of CddUart_Mld_PBcfg.h  and CddUart_Cfg.h are different"
#endif

/* Check if source file and CddUart header file are of the same Software version */
#if ((CDDUART_SW_MAJOR_VERSION_CFG != CDDUART_SW_MAJOR_VERSION_MLD_CFG) || \
     (CDDUART_SW_MINOR_VERSION_CFG != CDDUART_SW_MINOR_VERSION_MLD_CFG) || \
     (CDDUART_SW_PATCH_VERSION_CFG != CDDUART_SW_PATCH_VERSION_MLD_CFG) \
    )
#error "Software Version Numbers of CddUart_Mld_PBcfg.h  and CddUart_Cfg.h are different"
#endif
/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#define CddUartConf_UartChannel_UartChannel_0  0U
/*==================================================================================================
*                                       DEFINITIONS AND MACROS
==================================================================================================*/
#define UART_CORE_ID     ((uint32)0U)

/* @brief Enables / Disables multicore support */
#define CDDUART_MULTICORE_SUPPORT          (STD_OFF) 

/* @brief Enables / Disables PreCompile support when there is a single configuration */
#define CDDUART_PRECOMPILE_SUPPORT         (STD_OFF)

/* @brief Enables / Disables DET development errors detection and reporting */
#define CDDUART_DEV_ERROR_DETECT            (STD_ON) 
/* @brief Enables / Disables Runtime errors detection and reporting */
#define CDDUART_RUNTIME_ERROR_DETECT       (STD_OFF) 
/* @brief Number of loops before returning Timeout status */
#define CDDUART_TIMEOUT_VALUE_US           (1000U)

/* @brief Switches the Uart_GetVersionInfo() API ON or OFF. Support for version info API. */
#define CDDUART_VERSION_INFO_API            (STD_ON) 




#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
#error "Must define MCAL_ENABLE_USER_MODE_SUPPORT if CDDUART_ENABLE_USER_MODE_SUPPORT is defined"
#endif
#endif
/**
* @brief Support for SchM: sync/atomic operations, global interrupt disable/enable.
*/
#define CDDUART_SCHM_SUPPORT                (STD_ON) 
#define CDDUART_NUMBER_OF_INSTANCES             (UART_INSTANCE_COUNT)
/**
* @brief        All CoreIDs are supported by Uart driver.
*/

#define CDDUART_MAX_PARTITIONS             (1U)

/* @brief Number of Channels configured. */
#define CDDUART_CH_MAX_CONFIG              (1U)

#ifdef __cplusplus
}
#endif

#endif  /* CDDUART_CFG_H */

