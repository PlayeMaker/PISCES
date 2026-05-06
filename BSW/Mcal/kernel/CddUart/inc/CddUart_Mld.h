/**
*   @file    CddUart_Mld.h
*   @version
*   @brief   AUTOSAR Uart module interface
*   @details API implementation for Uart driver
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
#ifndef CDDUART_MLD_H
#define CDDUART_MLD_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
 *                                            INCLUDE FILES
==================================================================================================*/
#include "CddUart_Cfg.h"

/*==================================================================================================
 *                                   FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief   Initialize an Uart channel.
*
* @details This function calls a LLD function initializes all hardware registers needed to
*          start the Uart functionality on the selected channel.
*
* @param[in] Channel   Uart channel to be initialized.
* @param[in] UartClock The clock frequency set for the Uart module.
* @param[in] Config    Configuration pointer containing hardware specific settings.
*
* @return    void.
*
*/
void CddUart_Mld_Init(uint8 Channel, uint32 UartClock, const CddUart_Mld_HwConfigType *Config);

/**
* @brief   De-initialize an Uart channel.
*
* @details This function calls a LLD function de-initializes an Uart Hw instance and resets the current
*          information regarding the current channel
*
* @param[in] Channel  Uart channel to be de-initialized.
*
* @return    void.
*
*/
void CddUart_Mld_Deinit(uint8 Channel);

/**
* @brief   Retrieves the baudrate value configured for the current channel.
*
* @details This function calls a LLD function returns the baudrate value configured for the given channel
*          via a pointer parameter provided by user.
*
* @param[in]  Channel       Uart channel where the baudrate shall be configured
* @param[out] BaudrateValue The pointer which will contain the baudrate value.
*
* @return     void
*
*/
void CddUart_Mld_GetBaudrate(uint8 Channel, uint32 *BaudrateValue);

/**
* @brief   Set the baudrate value for the current channel.
*
* @details This function calls a LLD function which sets a baudrate value for a given channel,
*
* @param[in] Channel        Uart channel where the baudrate shall be configured
* @param[in] BaudRateValue  The baudrate value to be configured.
* @param[in] ClockFrequency The clock frequency set for the Uart module.
*
* @return    Std_ReturnType
* @retval    E_OK           Baud rate successfully configured
* @retval    E_NOT_OK       Baud rate wasn't successfully configured
*
*/
Std_ReturnType CddUart_Mld_SetBaudrate(uint8 Channel, uint32 BaudRateValue, uint32 ClockFrequency);

/**
* @brief   Aborts an on-going reception.
*
* @details This function calls a LLD function which ends a reception earlier.
*
* @param[in] Channel        Uart channel where the reception shall be ended.
*
* @return    Std_ReturnType
* @retval    E_OK           The reception ended successfully
* @retval    E_NOT_OK       The reception didn't end successfully
*
*/
Std_ReturnType CddUart_Mld_AbortReceivingData(uint8 Channel);

/**
* @brief   Aborts an on-going transmission.
*
* @details This function calls a LLD function which ends a transfer earlier.
*
* @param[in] Channel Uart channel where the transmission shall be ended.
*
* @return    Std_ReturnType
* @retval    E_OK     The transfer ended successfully
* @retval    E_NOT_OK The transfer didn't end successfully
*
*/
Std_ReturnType CddUart_Mld_AbortSendingData(uint8 Channel);

/**
* @brief   Sets a tx buffer.
*
* @details This function calls a LLD function which sets a buffer for continuos transmission.
*
* @param[in] Channel    Uart channel where to set the buffer.
* @param[in] Buffer     Pointer to the buffer to be sent.
* @param[in] BufferSize The number of bytes to send.
*
* @return    void
*/
void CddUart_Mld_SetTxBuffer(uint8 Channel, uint8 *Buffer, uint32 BufferSize);

/**
* @brief   Sets uart callback.
* @details This function calls a LLD function which sets a callback function for continuos transmission.
*
* @param[in] Channel           Uart channel where to set the callback.
* @param[in] CallBackFunction  The callback function.
*
* @return  void
*/
void CddUart_Mld_SetCallBack(uint8 Channel, CddUart_General_CallbackType CallBackFunction);

/**
* @brief   Sets a rx buffer.
* @details This function calls a LLD function which sets a buffer for continuos reception.
*
* @param[in]  Channel    Uart channel where to set the buffer.
* @param[out] Buffer     Pointer to the buffer to be received.
* @param[in]  BufferSize The number of bytes to receive.
*
* @return    void
*/
void CddUart_Mld_SetRxBuffer(uint8 Channel, uint8 *Buffer, uint32 BufferSize);
/**
* @internal
* @brief  Sends a buffer synchronously.
* @details This function calls a LLD function which sends BufferSize bytes using polling method.
*
* @param[in] Channel    Uart channel used for transmission.
* @param[in] Buffer     Buffer to send.
* @param[in] BufferSize The number of bytes to send.
* @param[in] Timeout    The timeout value in us.
*
* @return    Std_ReturnType
* @retval    E_OK                   Tranmission ended successfully
* @retval    E_NOT_OK               Tranmission didn't end successfully
* @retval    CDDUART_STATUS_TIMEOUT Tranmission has timeout
*/
Std_ReturnType CddUart_Mld_SyncSend(uint8 Channel, uint8 *Buffer, uint32 BufferSize, uint32 Timeout);

/**
* @brief   Receives a buffer synchronously.
*
* @details This function calls a LLD function which receives BufferSize bytes using polling method.
*
* @param[in]  Channel    Uart channel used for reception.
* @param[out] Buffer     Pointer to the buffer to receive.
* @param[in]  BufferSize The number of bytes to receive.
* @param[in]  Timeout    The timeout value in us.
*
* @return    Std_ReturnType
* @retval    E_OK                Reception ended successfully
* @retval    E_NOT_OK            Reception didn't end successfully
* @retval    UART_STATUS_TIMEOUT Reception has timeout
*/
Std_ReturnType CddUart_Mld_SyncReceive(uint8 Channel, uint8 *Buffer, uint32 BufferSize, uint32 Timeout);

/**
* @brief   Receives a buffer asynchronously.
*
* @details This function calls a LLD function which receives BufferSize bytes using an asynchronous method.
*
* @param[in]  Channel    Uart channel used for reception.
* @param[out] Buffer     Pointer to the buffer to receive.
* @param[in]  BufferSize The number of bytes to receive.
*
* @return     Std_ReturnType
* @retval     E_OK     Reception started successfully
* @retval     E_NOT_OK Reception didn't start successfully
*/
Std_ReturnType CddUart_Mld_AsyncReceive(uint8 Channel, uint8 *Buffer, uint32 BufferSize);

/**
* @brief   Sends a buffer asynchronously.
*
* @details This function calls a LLD function which sends BufferSize bytes using an asynchronous method.
*
* @param[in] Channel    Uart channel used for transmission.
* @param[in] Buffer     Buffer to send.
* @param[in] BufferSize The number of bytes to send.
*
* @return    Std_ReturnType
* @retval    E_OK     Transmission started successfully
* @retval    E_NOT_OK Transmission didn't start successfully
*/
Std_ReturnType CddUart_Mld_AsyncSend(uint8 Channel, uint8 *Buffer, uint32 BufferSize);

/**
* @brief   Sets the status of the previous transfer.
*
* @param[in] Channel Uart channel.
* @param[in] Status  The status of the previous transfer.
*
* @return    void
*/
void CddUart_Mld_SetTransmitStatus(uint8 Channel, CddUart_StatusType Status);

/**
* @brief   Retrieves the status of the previous transfer.
*
* @details This function calls a LLD function which retrieves the status of the previous transfer
*          and the number of the remaining bytes to send.
*
* @param[in]  Channel        Uart channel.
* @param[out] BytesRemaining The pointer where to write the number of remaining bytes
*
* @return     CddUart_StatusType
* @retval     UART_NO_ERR0R:                 The previous transfer ended successfully
* @retval     UART_STATUS_OPERATION_ONGOING  The transfer is still on going
* @retval     UART_STATUS_ABORTED            The previous transfer was aborted
* @retval     UART_STATUS_TIMEOUT            The previous transfer was timeout

*/
CddUart_StatusType CddUart_Mld_GetTransmitStatus(uint8 Channel, uint32 *BytesRemaining);

/**
* @brief   Sets the status of the previous reception.
*
* @param[in] Channel Uart channel.
* @param[in] Status  The status of the previous reception.
*
* @return    void
*/
void CddUart_Mld_SetReceiveStatus(uint8 Channel, CddUart_StatusType Status);

/**
* @brief   Retrieves the status of the previous reception.
*
* @details This function calls a LLD function which retrieves the status of the previous reception
*          and the number of the remaining bytes to receive.
*
* @param[in]  Channel        Uart channel.
* @param[out] BytesRemaining The pointer where to write the number of remaining bytes
*
* @return     CddUart_StatusType
* @retval     UART_NO_ERR0R:                 The previous transfer ended successfully
* @retval     UART_STATUS_OPERATION_ONGOING  The reception is still on going
* @retval     UART_STATUS_ABORTED            The previous reception was aborted
* @retval     UART_STATUS_FRAMING_ERROR      Uart framing error
* @retval     UART_STATUS_RX_OVERRUN_ERROR   Uart overrun error
* @retval     UART_STATUS_PARITY_ERROR       Uart overrun error
* @retval     UART_STATUS_TIMEOUT            Uart operation has timeout

*/
CddUart_StatusType CddUart_Mld_GetReceiveStatus(uint8 Channel, uint32 *BytesRemaining);

#ifdef __cplusplus
}
#endif

#endif

