/************************ Include Files ************************/
#include "Printf_Handle.h"
#include "Rte_Swc_Com.h"
#include "Rte_Swc_Com_Cfg.h"
#include "Rte_Fifo_Types.h"
#include "Rte_Uart.h"
#include "printf.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/
static uint8_t printf_tx_buf[PRINTF_UART_TX_LEN] = {0};
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Printf_Send_Polling(void);
/************************ Private Function Implementations ************************/
/**
 * @brief  Printf send polling function
 * @param  None
 * @return None
 */
static void _Snf_Printf_Send_Polling(void)
{
    uint8_t len = 0;
    if (RTE_UART_STATE_TX_END == RTE_UART_PRINTF_GET_SEND_STATE())
    {
        if (RTE_FIFO_STATUS_SUCCESS == Rte_Swc_Fifo_Com_Handle(RTE_SWC_PRINTF_FIFO_ID, printf_tx_buf, &len))
        {
            if (0 != len)
            {
                RTE_UART_PRINTF_SEND(printf_tx_buf, len);
            }
        }
    }
}
/************************ Public Function Implementations ************************/
/**
 * @brief  Printf task function
 * @param  None
 * @return None
 */
void Snf_Printf_Task(void)
{
    _Snf_Printf_Send_Polling();
}

/**
 * @brief  Printf print function
 * @param  fmt: Format string, similar to printf
 * @return None
 */
void Snf_Printf(const char* fmt, ...)
{
    uint8_t len                                = 0;
    uint8_t printf_fmt_buf[PRINTF_UART_TX_LEN] = {0};
    va_list argptr;
    va_start(argptr, fmt);
    len = vsnprintf_((char*)printf_fmt_buf, PRINTF_UART_TX_LEN, fmt, argptr);
    va_end(argptr);
    Rte_Swc_Fifo_Com_Put(RTE_SWC_PRINTF_FIFO_ID, printf_fmt_buf, len);
}