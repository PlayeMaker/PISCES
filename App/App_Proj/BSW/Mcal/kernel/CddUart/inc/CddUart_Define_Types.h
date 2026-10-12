/**
*   @file    CddUart_Define_Types.h
*   @version
*   @brief   Mcu Uart module datatype defines.
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

#ifndef CDDUART_DEFINE_TYPES_H
#define CDDUART_DEFINE_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

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
 * @brief Define the enum of the Events which can trigger UART callback
 *
 * @details This enum should include the Events for all platforms
 */
/* implements   Uart_EventType_enum */
typedef enum
{
    UART_EVENT_RX_FULL      = 0x00U,    /**< @brief Rx buffer is full */
    UART_EVENT_TX_EMPTY     = 0x01U,    /**< @brief Tx buffer is empty */
    UART_EVENT_END_TX       = 0x02U,    /**< @brief The current transfer is ending */
    UART_EVENT_END_RX       = 0x03U,    /**< @brief The current transfer is ending */
    UART_EVENT_ERROR        = 0x04U,    /**< @brief An error occurred during transfer */
    UART_EVENT_IDLE         = 0x05U,    /**< @brief The UART is in idle state */
} CddUart_General_EventType;
/**
 * @brief Uart callback notification signature.
 *
 *
 *
 */
/* implements     Uart_CallbackType_Type */
typedef void (*CddUart_General_CallbackType)(uint8 Channel, CddUart_General_EventType Event);
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif
#endif /* CDDUART_DEFINE_TYPES_H */

