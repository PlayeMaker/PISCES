/**
*   @file    CddUart_Lld_Uart_Irq.c
*   @version
*   @brief   AUTOSAR CddUart module interface
*   @details API implementation for CddUart driver
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
#include "CddUart_Lld_Uart.h"
#include "OsIf.h"
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#define CDDUART_START_SEC_CODE
#include "CddUart_MemMap.h"
/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef CDDUART_UART_0_USED
ISR(UART0_IRQHandler);
#endif
#ifdef CDDUART_UART_1_USED
ISR(UART1_IRQHandler);
#endif
#ifdef CDDUART_UART_2_USED
ISR(UART2_IRQHandler);
#endif
/*==================================================================================================
*                                    LOCAL FUNCTION
==================================================================================================*/

#ifdef CDDUART_UART_0_USED
/* Implementation of UART0 handler named in startup code. */
CDDUART_FUNC ISR(UART0_IRQHandler)
{
    UART_Lld_IRQHandler(0);
}
#endif

#ifdef CDDUART_UART_1_USED
/* Implementation of UART1 handler named in startup code. */
CDDUART_FUNC ISR(UART1_IRQHandler)
{
    UART_Lld_IRQHandler(1);
}
#endif

#ifdef CDDUART_UART_2_USED
/* Implementation of UART2 handler named in startup code. */
CDDUART_FUNC ISR(UART2_IRQHandler)
{
    UART_Lld_IRQHandler(2);
}
#endif
#define CDDUART_STOP_SEC_CODE
#include "CddUart_MemMap.h"

