#ifndef _RTE_UART_TYPES_H_
#define _RTE_UART_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
typedef enum
{
    RTE_UART_STATE_IDLE    = 0x00,  // Idle
    RTE_UART_STATE_TX_BUSY = 0x01,  // Transmit busy
    RTE_UART_STATE_TX_END  = 0x02,  // Transmit end
    RTE_UART_STATE_RX_FULL = 0x03,  // Receive full
    RTE_UART_STATE_RX_END  = 0x04,  // Receive end
    RTE_UART_STATE_ERROR   = 0x05,  // Error
} rte_uart_state_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_UART_TYPES_H_ */