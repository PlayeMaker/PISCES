/************************ Include Files ************************/
#include "Drv_Uart.h"
#include <stdint.h>
#include "Mcal.h"
#include "Platform_Types.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/
static drv_uart_rx_state uart_rx_state[UART_MAX_CHANNEL] = {0};
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
 * @brief  UART initialization function
 * @param  None
 * @return None
 */
void Snf_Drv_Uart_Init(void)
{
    CddUart_Init(&CddUart_Config);
}

/**
 * @brief  UART send function
 * @param  channel UART channel number
 * @param  data    Pointer to the data to be sent
 * @param  len     Length of the data to be sent
 * @return None
 */
void Snf_Drv_Uart_Send(uint8_t channel, uint8_t* data, uint16_t len)
{
    if (channel >= UART_MAX_CHANNEL || NULL_PTR == data || 0 == len)
    {
        return;
    }
    CddUart_AsyncSend(channel, data, (uint32)len);
}

/**
 * @brief  UART receive function
 * @param  channel UART channel number
 * @param  data    Pointer to the data to be received
 * @param  len     Length of the data to be received
 * @return None
 */
void Snf_Drv_Uart_Start_Receive(uint8_t channel, uint8_t* data, uint16_t len)
{
    if (channel >= UART_MAX_CHANNEL || NULL_PTR == data || 0 == len)
    {
        return;
    }

    uart_rx_state[channel].remaining_len = (uint32_t)len;
    uart_rx_state[channel].state         = RTE_UART_STATE_IDLE;
    CddUart_AsyncReceive(channel, data, (uint32)len);
}

/**
 * @brief  UART Send state function
 * @param  channel UART channel number
 * @return None
 */
rte_uart_state_e Snf_Drv_Uart_Get_Send_State(uint8_t channel)
{
    uint32             bytes = 0;
    rte_uart_state_e   state = RTE_UART_STATE_ERROR;
    CddUart_StatusType TransmitStatus;

    if (channel >= UART_MAX_CHANNEL)
    {
        return RTE_UART_STATE_ERROR;
    }

    TransmitStatus = CddUart_GetStatus(channel, &bytes, CDDUART_SEND);

    if (CDDUART_STATUS_NO_ERROR == TransmitStatus && 0 == bytes)
    {
        state = RTE_UART_STATE_TX_END;
    }

    return state;
}

/**
 * @brief  UART Receive state function
 * @param  channel UART channel number
 * @return None
 */
rte_uart_state_e Snf_Drv_Uart_Get_Receive_State(uint8_t channel, uint32_t* bytes)
{
    rte_uart_state_e state = RTE_UART_STATE_ERROR;

    if (channel >= UART_MAX_CHANNEL)
    {
        return state;
    }

    if (RTE_UART_STATE_RX_FULL == uart_rx_state[channel].state || RTE_UART_STATE_RX_END == uart_rx_state[channel].state)
    {
        *bytes = uart_rx_state[channel].remaining_len;
        state  = uart_rx_state[channel].state;
    }

    return state;
}

/**
 * @brief  UART callback function
 * @param  Channel UART channel number
 * @param  Event   UART event type
 * @return None
 */
void Uart_Callbcak(uint8 Channel, CddUart_General_EventType Event)
{
    (void)Channel;
    switch (Event)
    {
        case UART_EVENT_RX_FULL:
            uart_rx_state[Channel].state = RTE_UART_STATE_RX_FULL;
            break;
        case UART_EVENT_END_RX:
        case UART_EVENT_IDLE:
            uart_rx_state[Channel].state = RTE_UART_STATE_RX_END;
            CddUart_GetStatus(Channel, (uint32*)&uart_rx_state[Channel].remaining_len, CDDUART_RECEIVE);
            break;
        default:
            break;
    };
}
