/**
*   @file    CddUart_Mld_Types.h
*   @version
*   @brief   Mcu Uart Driver datatype defines.
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

#ifndef CDDUART_MLD_TYPES_H
#define CDDUART_MLD_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
 *                                            INCLUDE FILES
==================================================================================================*/
#include "CddUart_Define_Types.h"
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
#include "CddUart_Uart_Types.h"
#else
#include "CddUart_LinFlexD_Types.h"
#endif
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDDUART_MLD_TYPES_VENDOR_ID                    (180)
#define CDDUART_MLD_TYPES_AR_RELEASE_MAJOR_VERSION     (4)
#define CDDUART_MLD_TYPES_AR_RELEASE_MINOR_VERSION     (4)
#define CDDUART_MLD_TYPES_AR_RELEASE_REVISION_VERSION  (0)
#define CDDUART_MLD_TYPES_SW_MAJOR_VERSION             (0)
#define CDDUART_MLD_TYPES_SW_MINOR_VERSION             (9)
#define CDDUART_MLD_TYPES_SW_PATCH_VERSION             (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/**
* @internal
* @brief The hardware ip supported by the Uart driver
*/
typedef enum
{

    LINFLEX_IP   = 0,         /**< @brief Lin Flex Ip  */
    UART_IP      = 1          /**< @brief Uart Ip  */
} CddUart_Mld_HwChannelType;
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief The Ip configuration structure pointer
*/
typedef struct
{
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
    const Uart_UartUserConfigType *UserConfigOfUartHard;         /**< @brief uart Ip configuration structure  */
#else
    const LinFlexd_UartUserConfigType *UserConfigOfUartHard;     /**< @brief uart Ip configuration structure  */
#endif
} CddUart_Mld_IpConfigType;

/**
* @brief   Structure which brings together all the hardware
*          specific information regarding a channel
* @details This structure contains a pointer to the
*          Ip configuration structure, the type of hardware instance and
*          the number of it.
*/
typedef struct
{
    uint8 UartHwChannel;                         /**< @brief Uart Hardware Channel.*/
    CddUart_Mld_HwChannelType UartIpType;        /**< @brief Type of Hardware interface configured.*/
    const CddUart_Mld_IpConfigType *UserConfig;  /**< @brief Pointer to the Ip configuration structure.*/
} CddUart_Mld_HwConfigType;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif
#endif /*CDDUART_MLD_TYPES_H*/

