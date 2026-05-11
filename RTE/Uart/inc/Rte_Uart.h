#ifndef _RTE_UART_H_
#define _RTE_UART_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Drv_Uart.h"
/************************ Macro Definitions ************************/
#define RTE_UART_INIT                            Snf_Drv_Uart_Init
#define RTE_UART_PRINTF_SEND(data, len)          Snf_Drv_Uart_Send(DRV_UART_CHANNEL_0, data, len)
#define RTE_UART_PRINTF_START_RECEIVE(data, len) Snf_Drv_Uart_Start_Receive(DRV_UART_CHANNEL_0, data, len)
#define RTE_UART_PRINTF_GET_SEND_STATE()         (rte_uart_state_e) Snf_Drv_Uart_Get_Send_State(DRV_UART_CHANNEL_0)
#define RTE_UART_PRINTF_GET_RECEIVE_STATE(bytes) (rte_uart_state_e) Snf_Drv_Uart_Get_Receive_State(DRV_UART_CHANNEL_0, bytes)
/************************ Type Definitions ************************/
typedef enum
{
    RTE_UART_STATE_IDLE    = DRV_UART_STATE_IDLE,     // Idle
    RTE_UART_STATE_TX_BUSY = DRV_UART_STATE_TX_BUSY,  // Transmit busy
    RTE_UART_STATE_TX_END  = DRV_UART_STATE_TX_END,   // Transmit end
    RTE_UART_STATE_RX_FULL = DRV_UART_STATE_RX_FULL,  // Receive full
    RTE_UART_STATE_RX_END  = DRV_UART_STATE_RX_END,   // Receive end
    RTE_UART_STATE_ERROR   = DRV_UART_STATE_ERROR,    // Error
} rte_uart_state_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_UART_H_ */