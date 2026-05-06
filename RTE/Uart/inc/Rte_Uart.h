#ifndef _RTE_UART_H_
#define _RTE_UART_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Drv_Uart.h"
/************************ Macro Definitions ************************/
#define RTE_UART_INIT                           Snf_Drv_Uart_Init
#define RTE_UART_SHELL_SEND(data, len)          Snf_Drv_Uart_Send(UART_CHANNEL_0, data, len)
#define RTE_UART_SHELL_START_RECEIVE(data, len) Snf_Drv_Uart_Start_Receive(UART_CHANNEL_0, data, len)
#define RTE_UART_SHELL_GET_SEND_STATE()         Snf_Drv_Uart_Get_Send_State(UART_CHANNEL_0)
#define RTE_UART_SHELL_GET_RECEIVE_STATE(bytes) Snf_Drv_Uart_Get_Receive_State(UART_CHANNEL_0, bytes)
/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_UART_H_ */