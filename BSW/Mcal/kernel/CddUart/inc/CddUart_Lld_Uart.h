/**
*   @file    CddUart_Lld_Uart.h
*   @version
*   @brief   AUTOSAR CddUart module interface
*   @details API implementation for UART driver
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
#ifndef CDDUART_LLD_UART_H
#define CDDUART_LLD_UART_H

/*==================================================================================================
 *                                            INCLUDE FILES
==================================================================================================*/
#include "CddUart_Cfg.h"
#include "CddUart_Lld_UartCfg.h"

/*==================================================================================================
 *                                   FUNCTION PROTOTYPES
==================================================================================================*/
/*!
 * @brief   Sets the baud rate for UART communication.
 *
 * @details This function computes the fractional and integer parts of the baud rate divisor
 *          to obtain the desired baud rate using the current protocol clock.
 *
 * @param[in] Instance        UART Instance number
 * @param[in] UartClock       Clock frequency
 * @param[in] DesiredBaudRate Desired baud rate
 *
 * @return CddUart_StatusType
 * @retval CDDUART_STATUS_NO_ERROR If the baud rate is set successfully
 * @retval OTHER_ERROR_CODE        If the baud rate cannot be set
 */
CddUart_StatusType UART_Lld_SetBaudRate(uint32 Instance, uint32 UartClock, uint32 DesiredBaudRate);

/*!
 * @brief   Gets the baud rate for UART communication.
 *
 * @details This function returns the current UART baud rate, according to register values
 *          and the protocol clock frequency.
 *
 * @param[in]  Instance           UART Instance number
 * @param[out] ConfiguredBaudRate Current baud rate
 *
 * @return CddUart_StatusType
 * @retval CDDUART_STATUS_NO_ERROR  If the baud rate is obtained successfully
 * @retval An error code            If the baud rate is not obtained
 */
CddUart_StatusType UART_Lld_GetBaudRate(uint32 Instance, uint32 *ConfiguredBaudRate);

/*!
 * @brief   Initializes a UART Instance for UART operation.
 *
 * @details The caller provides memory for the driver state structures during initialization.
 *          The user must enable the UART clock source in the application to initialize the module.
 *
 * @param[in] Instance       UART Instance number
 * @param[in] UartClock      Clock frequency of the UART module
 * @param[in] UartUserConfig Pointer to the user configuration structure
 *
 * @return CddUart_StatusType
 * @retval CDDUART_STATUS_NO_ERROR If the initialization is successful
 * @retval OTHER_ERROR_CODE        If the initialization is fails
 */
CddUart_StatusType UART_Lld_Init(uint32 Instance, uint32 UartClock, const Uart_UartUserConfigType *UartUserConfig);

/*!
 * @brief Shuts down the UART functionality of the UART module by disabling interrupts and transmitter/receiver.
 *
 * @param[in] Instance  UART Instance number
 *
 * @return CddUart_StatusType
 * @retval CDDUART_STATUS_NO_ERROR If the de-initialization is successful
 * @retval OTHER_ERROR_CODE        If the de-initialization is fails
 */
CddUart_StatusType UART_Lld_Deinit(uint32 Instance);

/*!
 * @brief   Sends data using UART module in UART mode with blocking method.
 *
 * @details Blocking means that the function does not return until the transmission is complete.
 *
 * @param[in] Instance UART Instance number
 * @param[in] TxBuff   Source buffer containing 8-bit data chars to send
 * @param[in] TxSize   The number of bytes to send
 * @param[in] Timeout  Timeout value in milliseconds
 *
 * @return CddUart_StatusType
 * @retval CDDUART_STATUS_NO_ERROR If the transmission is successful
 * @retval OTHER_ERROR_CODE        If the transmission is fails
 */
CddUart_StatusType UART_Lld_SendDataBlocking(uint32 Instance, uint8 *TxBuff, uint32 TxSize, uint32 Timeout);

/*!
 * @brief   Sends data using UART module in UART mode with non-blocking method.
 *
 * @details This enables an a-sync method for transmitting data. When used with
 *          a non-blocking receive, the UART driver can perform a full duplex operation.
 *          Non-blocking  means that the function returns immediately.
 *          The application has to get the transmit status to know when the transmission is complete.
 *
 * @param[in] Instance UART Instance number
 * @param[in] TxBuff   Source buffer containing 8-bit data chars to send
 * @param[in] TxSize   The number of bytes to send
 *
 * @return CddUart_StatusType
 * @retval CDDUART_STATUS_NO_ERROR  If the data is sent successfully
 * @retval An error code            If the data is sent fails
 */
CddUart_StatusType UART_Lld_SendData(uint32 Instance, uint8 *TxBuff, uint32 TxSize);

/*!
 * @brief Sets the status of the transmit operation.
 *
 * @param[in] Instance UART Instance number
 * @param[in] Status   The status of the transmit operation
 *
 * @return void
 */
void  UART_Lld_SetTransmitStatus(uint32 Instance, CddUart_StatusType Status);

/*!
 * @brief Returns the current status of the transmit operation.
 *
 * @note  In DMA mode, this parameter may not be accurate, in case the transfer completes right after calling this function;
 *        In this case, the parameter is zero, due to automatic reloading of the trigger loop count
 *        in the DMA transfer descriptor.
 *
 * @param[in]  Instance       UART Instance number
 * @param[out] BytesRemaining Pointer to value that is filled with the number of bytes
 *                            that still need to be transmitted in the active transfer.
 *
 * @return CddUart_StatusType
 * @retval CDDUART_STATUS_NO_ERROR  If the transmit operation has completed successfully
 * @retval OTHER_STATUS             If the transmit operation in other status
 */
CddUart_StatusType UART_Lld_GetTransmitStatus(uint32 Instance, uint32 *BytesRemaining);

/*!
 * @brief Terminates a non-blocking transmission early.
 *
 * @param[in] Instance UART Instance number
 *
 * @return CddUart_StatusType
 * @retval CDDUART_STATUS_NO_ERROR    If the abort operation is successful
 * @retval CDDUART_STATUS_OTHER_ERROR If the abort operation fails
 */
CddUart_StatusType UART_Lld_AbortSendingData(uint32 Instance);

/*!
 * @brief   Retrieves data from the UART module in UART mode with blocking method.
 *
 * @details Blocking means that the function does not return until the receive is complete.
 *
 * @param[in]  Instance UART Instance number
 * @param[out] RxBuff   Pointer to the buffer where the received data will be stored
 * @param[in]  RxSize   The number of bytes to receive
 * @param[in]  Timeout  Timeout value in milliseconds
 *
 * @return CddUart_StatusType
 * @retval CDDUART_STATUS_NO_ERROR If the data is received successfully
 * @retval An error code           If the data is received fails or timeout occurs during receiving
 */
CddUart_StatusType UART_Lld_ReceiveDataBlocking(uint32 Instance, uint8 *RxBuff, uint32 RxSize, uint32 Timeout);

/*!
 * @brief   Retrieves data from the UART module in UART mode with non-blocking method.
 *
 * @details This enables an a-sync method for receiving data. When used with a non-blocking transmission,
 *          the UART driver can perform a full duplex operation. on-blocking means that the function returns immediately.
 *          The application has to get the receive status to know when the receive is complete.
 *
 * @param[in]  Instance UART Instance number
 * @param[out] RxBuff   Pointer to the buffer where the received data will be stored
 * @param[in]  RxSize   The number of bytes to receive
 *
 * @return CddUart_StatusType
 * @retval CDDUART_STATUS_NO_ERROR If the data is received successfully
 * @retval An error code           If the data is received fails
 */
CddUart_StatusType UART_Lld_ReceiveData(uint32 Instance, uint8 *RxBuff, uint32 RxSize);

/*!
 * @brief   Sets the receive status of the UART module.
 *
 * @param[in] Instance UART Instance number
 * @param[in] Status   The status of the receive operation
 *
 * @return void
 */
void UART_Lld_SetReceiveStatus(uint32 Instance, CddUart_StatusType Status);

/*!
 * @brief Returns whether the previous receive is complete.
 *
 * @note  In DMA mode, this parameter may not be accurate, in case the transfer completes right after calling this function; in this case,
 *        the parameter is zero, due to automatic reloading of the trigger loop count in the DMA transfer descriptor.
 *
 * @param[in]  Instance       UART Instance number
 * @param[out] BytesRemaining pointer to value that is filled with the number of bytes that still need to be received in the active transfer.
 *
 * @return CddUart_StatusType
 * @retval CDDUART_STATUS_NO_ERROR If the receive operation has completed successfully
 * @retval OTHER_STATUS            If the receive operation is in progress
 */
CddUart_StatusType UART_Lld_GetReceiveStatus(uint32 Instance, uint32 *BytesRemaining);

/*!
 * @brief Terminates a non-blocking receive early.
 *
 * @param[in] Instance UART Instance number
 *
 * @return CddUart_StatusType
 * @retval CDDUART_STATUS_NO_ERROR    If the abort operation is successful
 * @retval CDDUART_STATUS_OTHER_ERROR If the abort operation fails
 */
CddUart_StatusType UART_Lld_AbortReceivingData(uint32 Instance);

/*!
 * @brief   Sets the internal driver reference to the tx buffer.
 *
 * @details This function can be called from the tx callback to provide the driver
 *          with a new buffer, for continuous transmission.
 *
 * @param[in] Instance UART Instance number
 * @param[in] TxBuff   Pointer to the buffer containing 8-bit data chars to send
 * @param[in] TxSize   The number of bytes to send
 *
 * @return CddUart_StatusType
 * @retval CDDUART_STATUS_NO_ERROR  If the tx buffer is set successfully
 * @retval An error code            If the tx buffer is set fails
 */
CddUart_StatusType UART_Lld_SetTxBuffer(uint32 Instance, uint8 *TxBuff, uint32 TxSize);

/*!
 * @brief Sets the internal driver reference to the Call back.
 *
 * @param[in] Instance         UART Instance number
 * @param[in] CallBackFunction Callback function to be set.
 *
 * @return CddUart_StatusType
 * @retval CDDUART_STATUS_NO_ERROR  If the callback is set successfully
 * @retval An error code            If the callback is set fails
 */
CddUart_StatusType UART_Lld_SetCallback(uint32 Instance, CddUart_General_CallbackType CallBackFunction);

/*!
 * @brief   Sets the internal driver reference to the rx buffer.
 *
 * @details This function can be called from the rx callback to provide the driver
 *          with a new buffer, for continuous reception.
 *
 * @param[in]  Instance UART Instance number
 * @param[out] RxBuff   Pointer to the buffer where the received data will be stored
 * @param[in]  RxSize   The number of bytes to receive
 *
 * @return CddUart_StatusType
 * @retval CDDUART_STATUS_NO_ERROR  If the rx buffer is set successfully
 * @retval An error code            If the rx buffer is set fails
 */
CddUart_StatusType UART_Lld_SetRxBuffer(uint32 Instance, uint8 *RxBuff, uint32 RxSize);

/*!
 * @brief   Interrupt handler for UART.
 *
 * @details This handler uses the buffers stored in the state structure to transfer data.
 *          This is not a public API as it is called by IRQ whenever an interrupt occurs.
 *
 * @param[in] Instance  UART Instance number
 *
 * @return void
 */
void UART_Lld_IRQHandler(uint8 Instance);

#endif  /* CDDUART_LLD_UART_H */

