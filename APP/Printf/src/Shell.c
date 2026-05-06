/************************ Include Files ************************/
#include "Shell.h"
#include "Rte_Swc_Com.h"
#include "Rte_Swc_Com_Cfg.h"
#include "Rte_Fifo_Types.h"
#include "Rte_Uart.h"
#include "printf.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/
static uint8_t shell_fmt_buf[SHELL_UART_TX_LEN] = {0};
static uint8_t shell_rx_buf[SHELL_UART_RX_LEN]  = {0};
static uint8_t shell_tx_buf[SHELL_UART_TX_LEN]  = {0};
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Shell_Send_Polling(void);
static void _Snf_Shell_Recieve_Polling(void);
/************************ Private Function Implementations ************************/
/**
 * @brief  Shell send polling function
 * @param  None
 * @return None
 */
static void _Snf_Shell_Send_Polling(void)
{
    uint8_t len = 0;
    if (RTE_UART_STATE_TX_END == RTE_UART_SHELL_GET_SEND_STATE())
    {
        if (RTE_FIFO_STATUS_SUCCESS == Rte_Swc_Fifo_Com_Handle(RTE_SWC_SHELL_PRINT_FIFO_ID, shell_tx_buf, &len))
        {
            if (0 != len)
            {
                RTE_UART_SHELL_SEND(shell_tx_buf, len);
            }
        }
    }
}
/**
 * @brief  Shell receive polling function
 * @param  None
 * @return None
 */
static void _Snf_Shell_Recieve_Polling(void)
{
    uint32_t         bytes = 0;
    rte_uart_state_e state = RTE_UART_SHELL_GET_RECEIVE_STATE(&bytes);
    if (RTE_UART_STATE_RX_END == state || RTE_UART_STATE_RX_FULL == state)
    {
        RTE_UART_SHELL_START_RECEIVE(shell_rx_buf, SHELL_UART_RX_LEN);
    }
}
/************************ Public Function Implementations ************************/
/**
 * @brief  Shell task function
 * @param  None
 * @return None
 */
void Snf_Shell_Task_Init(void)
{
    RTE_UART_SHELL_START_RECEIVE(shell_rx_buf, SHELL_UART_RX_LEN);
}
/**
 * @brief  Shell task function
 * @param  None
 * @return None
 */
void Snf_Shell_Task(void)
{
    _Snf_Shell_Send_Polling();
    _Snf_Shell_Recieve_Polling();
}

/**
 * @brief  Shell print function
 * @param  fmt: Format string, similar to printf
 * @return None
 */
void Snf_Shell_Print(const char* fmt, ...)
{
    uint8_t len = 0;
    va_list argptr;
    va_start(argptr, fmt);
    len = vsnprintf_((char*)shell_fmt_buf, SHELL_UART_TX_LEN, fmt, argptr);
    va_end(argptr);
    Rte_Swc_Fifo_Com_Put(RTE_SWC_SHELL_PRINT_FIFO_ID, shell_fmt_buf, len);
}