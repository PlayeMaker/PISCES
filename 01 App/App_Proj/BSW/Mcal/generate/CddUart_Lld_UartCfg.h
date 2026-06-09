/**
*   @file    CddUart_Lld_UartCfg.h
*   @version 
*   @brief   AUTOSAR CddUart module interface
*   @details API implementation for CddUart driver cfg.
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : uart
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


#ifndef CDDUART_LLD_UartCFG_H
#define CDDUART_LLD_UartCFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CddUart_Uart_Types.h"
/*==================================================================================================
*                               FILE VERSION INFORMATION
==================================================================================================*/
#define CDDUART_VENDOR_ID_UART_CFG                      (180)
#define CDDUART_AR_RELEASE_MAJOR_VERSION_UART_CFG       (4)
#define CDDUART_AR_RELEASE_MINOR_VERSION_UART_CFG       (4)
#define CDDUART_AR_RELEASE_REVISION_VERSION_UART_CFG    (0)
#define CDDUART_SW_MAJOR_VERSION_UART_CFG               (0)
#define CDDUART_SW_MINOR_VERSION_UART_CFG               (9)
#define CDDUART_SW_PATCH_VERSION_UART_CFG               (1)
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#if (defined(CPU_YTM32B1MC0) || defined(CPU_YTM32B1MD2))
#define CDDUART_UART_INSTANCE_COUNT             (3U)
#endif
/* @brief Uart has feature DMA enable. */
#define CDDUART_DMA_USED                        (STD_ON)
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
extern const Uart_UartUserConfigType CddUart_Ip_HwConfig_0;

#ifdef __cplusplus
}
#endif

#endif 

