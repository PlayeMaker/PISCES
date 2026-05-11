#ifndef _DRV_UART_H_
#define _DRV_UART_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
#include "CddUart_Cfg.h"
/************************ Macro Definitions ************************/
#define DRV_UART_MAX_CHANNEL CDDUART_CH_MAX_CONFIG
#define DRV_UART_CHANNEL_0   CddUartConf_UartChannel_UartChannel_0
/************************ Type Definitions ************************/

/************************ External Variables ************************/
typedef enum
{
    DRV_UART_STATE_IDLE    = 0x00,  // Idle
    DRV_UART_STATE_TX_BUSY = 0x01,  // Transmit busy
    DRV_UART_STATE_TX_END  = 0x02,  // Transmit end
    DRV_UART_STATE_RX_FULL = 0x03,  // Receive full
    DRV_UART_STATE_RX_END  = 0x04,  // Receive end
    DRV_UART_STATE_ERROR   = 0x05,  // Error
} drv_uart_state_e;

typedef struct
{
    uint32_t         remaining_len;
    drv_uart_state_e state;
} drv_uart_rx_state;

/************************ Function Declarations ************************/
void             Snf_Drv_Uart_Init(void);
void             Snf_Drv_Uart_Send(uint8_t channel, uint8_t* data, uint16_t len);
void             Snf_Drv_Uart_Start_Receive(uint8_t channel, uint8_t* data, uint16_t len);
drv_uart_state_e Snf_Drv_Uart_Get_Send_State(uint8_t channel);
drv_uart_state_e Snf_Drv_Uart_Get_Receive_State(uint8_t channel, uint32_t* bytes);

#ifdef __cplusplus
}
#endif

#endif /* _DRV_UART_H_ */
