#ifndef _DRV_UART_H_
#define _DRV_UART_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
#include "CddUart_Cfg.h"
#include "Rte_Uart_Types.h"
/************************ Macro Definitions ************************/
#define UART_MAX_CHANNEL CDDUART_CH_MAX_CONFIG
#define UART_CHANNEL_0   CddUartConf_UartChannel_UartChannel_0
/************************ Type Definitions ************************/

/************************ External Variables ************************/
typedef struct
{
    uint32_t         remaining_len;
    rte_uart_state_e state;
} drv_uart_rx_state;
/************************ Function Declarations ************************/
void             Snf_Drv_Uart_Init(void);
void             Snf_Drv_Uart_Send(uint8_t channel, uint8_t* data, uint16_t len);
void             Snf_Drv_Uart_Start_Receive(uint8_t channel, uint8_t* data, uint16_t len);
rte_uart_state_e Snf_Drv_Uart_Get_Send_State(uint8_t channel);
rte_uart_state_e Snf_Drv_Uart_Get_Receive_State(uint8_t channel, uint32_t* bytes);

#ifdef __cplusplus
}
#endif

#endif /* _DRV_UART_H_ */
