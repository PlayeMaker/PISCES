/**
*   @file    CddUart_Uart_Types.h
*   @version
*   @brief   Mcu  Uart IP Driver datatype defines.
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

#ifndef CDDUART_UART_TYPES_H
#define CDDUART_UART_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "CddUart_Define_Types.h"
#include "CddUart_Lld_Reg.h"
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define DEFAULT_OSR                    16U
#define BAUDRATE_FRACTION_WIDTH        LINFlexD_LINFBRR_FBR_WIDTH

/**
* @brief Uart Hw channel type
*/
#define UART_0                         0U
#define UART_1                         1U
#define UART_2                         2U

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/
/**
* @brief          Uart operation status type
*/
typedef enum
{
    CDDUART_STATUS_NO_ERROR            =  0x00, /**< @brief Uart operation is successful  */
    CDDUART_STATUS_OPERATION_ONGOING   =  0x01, /**< @brief Uart operation on going  */
    CDDUART_STATUS_ABORTED             =  0x02, /**< @brief Uart operation aborted  */
    CDDUART_STATUS_FRAMING_ERROR       =  0x03, /**< @brief Uart framing error  */
    CDDUART_STATUS_RX_OVERRUN_ERROR    =  0x04, /**< @brief Uart overrun error  */
    CDDUART_STATUS_PARITY_ERROR        =  0x05, /**< @brief Uart parity error  */
    CDDUART_STATUS_TIMEOUT             =  0x06, /**< @brief Uart operation has timeout  */
    CDDUART_STATUS_NOISE_ERROR         =  0x07, /**< @brief Uart noise error  */
    CDDUART_STATUS_DMA_ERROR           =  0x08, /**< @brief Uart Dma Error error  */
    CDDUART_STATUS_OTHER_ERROR         =  0x09, /**< @brief Uart others Error error  */
    CDDUART_STATUS_IDLE_ERROR          =  0x0A, /**< @brief Uart idle error  */
} CddUart_StatusType;
/*!
 * @brief UART status flags.
 *
 * This provides constants for the UART status flags for use in the UART functions.
 */
typedef enum
{
    UART_TX_DATA_REG_EMPTY             = UART_INTF_TXIF_MASK,       /*!< Tx data register empty flag, sets when Tx buffer is empty */
    UART_TX_COMPLETE                   = UART_INTF_TCIF_MASK,       /*!< Transmission complete flag, sets when transmission activity complete */
    UART_RX_DATA_REG_FULL              = UART_INTF_RXIF_MASK,       /*!< Rx data register full flag, sets when the receive data buffer is full */
    UART_IDLE_LINE_DETECT              = UART_INTF_IDLEIF_MASK,     /*!< Idle line detect flag, sets when idle line detected */
    UART_RX_OVERRUN                    = UART_INTF_OVRIF_MASK,      /*!< Rx Overrun sets if new data is received before data is read */
    UART_NOISE_DETECT                  = UART_INTF_NOZIF_MASK,      /*!< Rx takes 3 samples of each received bit. If these differ, the flag sets */
    UART_FRAME_ERR                     = UART_INTF_FEIF_MASK,       /*!< Frame error flag, sets if logic 0 was detected where stop bit expected */
    UART_PARITY_ERR                    = UART_INTF_PARIF_MASK,      /*!< If parity enabled, sets upon parity error detection */
    UART_LIN_BREAK_DETECT              = UART_INTF_LBKDIF_MASK,     /*!< LIN break detect interrupt flag, sets when LIN break char detected */
    UART_RX_ACTIVE_EDGE_DETECT         = UART_INTF_RXEDGEIF_MASK,   /*!< Rx pin active edge interrupt flag, sets when active edge detected */
#if FEATURE_UART_HAS_ADDRESS_MATCHING
    UART_MATCH_ADDR_ONE                = UART_INTF_MATIF_MASK,      /*!< Address one match flag */
#endif
#if FEATURE_UART_FIFO_SIZE > 0U
    UART_FIFO_TX_OF                    = UART_INTF_TFEIF_MASK,      /*!< Transmitter FIFO buffer overflow */
    UART_FIFO_RX_UF                    = UART_INTF_RFEIF_MASK,      /*!< Receiver FIFO buffer underflow */
#endif
} Uart_UartStatusType;

/*! @brief UART interrupt configuration structure, default settings are 0 (disabled) */
typedef enum
{
    UART_INT_LIN_BREAK_DETECT          = UART_INTE_LBKDIE_MASK,     /*!< LIN break detect. */
    UART_INT_RX_ACTIVE_EDGE            = UART_INTE_RXEDGEIE_MASK,   /*!< RX Active Edge. */
    UART_INT_TX_DATA_REG_EMPTY         = UART_INTE_TXIE_MASK,       /*!< Transmit data register empty. */
    UART_INT_TX_COMPLETE               = UART_INTE_TCIE_MASK,       /*!< Transmission complete. */
    UART_INT_RX_DATA_REG_FULL          = UART_INTE_RXIE_MASK,       /*!< Receiver data register full. */
    UART_INT_IDLE_LINE                 = UART_INTE_IDLEIE_MASK,     /*!< Idle line. */
    UART_INT_RX_OVERRUN                = UART_INTE_OVRIE_MASK,      /*!< Receiver Overrun. */
    UART_INT_NOISE_ERR                 = UART_INTE_NOZIE_MASK,      /*!< Noise Interrupt Enable bit. */
    UART_INT_FRAME_ERR                 = UART_INTE_FEIE_MASK,       /*!< Frame Error Interrupt Enable bit. */
    UART_INT_PARITY_ERR                = UART_INTE_PARIE_MASK,      /*!< Parity error check interrupt enable bit. */
#if FEATURE_UART_HAS_ADDRESS_MATCHING
    UART_INT_MATCH_ADDR_ONE            = UART_INTE_MATIE_MASK,      /*!< Match address one flag. */
#endif
} Uart_InterruptType;
/*! @brief UART number of bits in a character
 *
 * Implements : uart_bit_count_per_char_t_Class
 */
typedef enum
{
    UART_7_BITS_PER_CHAR               = 0x0U,  /*!< 7-bit data characters */
    UART_8_BITS_PER_CHAR               = 0x1U,  /*!< 8-bit data characters */
    UART_9_BITS_PER_CHAR               = 0x2U,  /*!< 9-bit data characters */
    UART_10_BITS_PER_CHAR              = 0x3U   /*!< 10-bit data characters */
} Uart_UartWordLengthType;
/*! @brief UART line idle detect size
 *
 * Implements : Uart_LineSizeType
 */
typedef enum
{
    UART_LINE_IDLE_SIZE_1_CHAR         = 0x0U,  /*!< idles after 1 char length */
    UART_LINE_IDLE_SIZE_2_CHAR         = 0x1U,  /*!< idles after 2 char length */
    UART_LINE_IDLE_SIZE_4_CHAR         = 0x2U,  /*!< idles after 4 char length */
    UART_LINE_IDLE_SIZE_8_CHAR         = 0x3U,  /*!< idles after 8 char length */
    UART_LINE_IDLE_SIZE_16_CHAR        = 0x4U,  /*!< idles after 16 char length */
    UART_LINE_IDLE_SIZE_32_CHAR        = 0x5U,  /*!< idles after 32 char length */
    UART_LINE_IDLE_SIZE_64_CHAR        = 0x6U,  /*!< idles after 64 char length */
    UART_LINE_IDLE_SIZE_128_CHAR       = 0x7U,  /*!< idles after 128 char length */
} Uart_LineSizeType;
/*! @brief UART number of stop bits
 *
 * Implements : uart_stop_bit_count_t_Class
 */
typedef enum
{
    UART_ONE_STOP_BIT                  = 0x0U,  /*!< one stop bit */
    UART_TWO_STOP_BIT                  = 0x1U   /*!< two stop bits */
} Uart_UartStopBitsType;
/*! @brief UART parity mode
 *
 * Implements : uart_parity_mode_t_Class
 */
typedef enum
{
    UART_PARITY_DISABLED               = 0x0U,  /*!< parity disabled */
    UART_PARITY_EVEN                   = 0x2U,  /*!< parity enabled, type even, bit setting: PE|PT = 10 */
    UART_PARITY_ODD                    = 0x3U   /*!< parity enabled, type odd,  bit setting: PE|PT = 11 */
} Uart_UartParityType;
/*! @brief Type of UART transfer (based on interrupts or DMA).
 *
 * Implements : uart_transfer_type_t_Class
 */
typedef enum
{
    UART_USING_DMA                     = 0U,    /*!< The driver will use DMA to perform UART transfer */
    UART_USING_INTERRUPTS              = 1U,    /*!< The driver will use interrupts to perform UART transfer */
} Uart_UartTransferType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*!
 * @brief Runtime state of the UART driver.
 *
 * Note that the caller provides memory for the driver state structures during
 * initialization because the driver does not statically allocate memory.
 *
 * Implements : uart_state_t_Class
 */
typedef struct
{
    uint8 *TxBuff;                                      /*!< The buffer of data being sent.*/
    uint8 *RxBuff;                                      /*!< The buffer of received data.*/
    uint32 TxSize;                                      /*!< The remaining number of bytes to be transmitted. */
    uint32 RxSize;                                      /*!< The remaining number of bytes to be received. */
    boolean IsTxBusy;                                   /*!< True if there is an active transmit.*/
    boolean IsRxBusy;                                   /*!< True if there is an active receive.*/
    CddUart_General_CallbackType RxCallback;            /*!< Callback to invoke for data receive */
    uint8 RxCallbackParam;                              /*!< Receive callback parameter. */
    CddUart_General_CallbackType TxCallback;            /*!< Callback to invoke for data send */
    uint8 TxCallbackParam;                              /*!< Transmit callback parameter.*/
    CddUart_General_CallbackType ErrorCallback;         /*!< Callback to invoke on error conditions */
    void *ErrorCallbackParam;                           /*!< Error callback parameter pointer */
    Uart_UartWordLengthType WordLength;                 /*!< Word length (8/16 bits) */
    uint8 RxComplete;                                   /*!< Synchronization object for blocking Rx timeout condition */
    uint8 TxComplete;                                   /*!< Synchronization object for blocking Tx timeout condition */
    Uart_UartTransferType TxTransferType;               /*!< Type of UART tx transfer (interrupt/dma based) */
    Uart_UartTransferType RxTransferType;               /*!< Type of UART rx transfer (interrupt/dma based) */
    uint8 RxDMAChannel;                                 /*!< DMA channel number for DMA-based rx. */
    uint8 TxDMAChannel;                                 /*!< DMA channel number for DMA-based tx. */
    CddUart_StatusType TransmitStatus;                  /*!< Status of last driver transmit operation */
    CddUart_StatusType ReceiveStatus;                   /*!< Status of last driver receive operation */
    boolean IdleErrorIntEnable;                         /*!< enable/disable idle interrupt. */
    Uart_LineSizeType LinIdleDetectSize;                /*!< Idle line detect size */
} Uart_UartStateType;

/*! @brief UART configuration structure
 *
 * Implements : uart_user_config_t_Class
 */
typedef struct
{
    uint32 BaudRate;                                    /*!< baud rate */
    uint32 MaxBaudRate;                                 /*!< maximum baud rate supported by the UART */
    Uart_UartParityType ParityType;                     /*!< always 0/always 1/even/odd */
    Uart_UartStopBitsType StopBitsCount;                /*!< number of stop bits, 1 stop bit (default) or 2 stop bits */
    Uart_UartWordLengthType WordLength;                 /*!< number of bits per transmitted/received word */
    Uart_UartTransferType TxTransferType;               /*!< Type of UART tx transfer (interrupt/dma based) */
    Uart_UartTransferType RxTransferType;               /*!< Type of UART rx transfer (interrupt/dma based) */
    CddUart_General_CallbackType ComplexCallback;       /*!< Callback to invoke for data transitions */
    uint8 LogicChannel;                             /*!< Logical channel number for the UART instance */
    uint8 RxDMAChannel;                                 /*!< Channel number for DMA rx channel.If DMA mode is not used this field will be ignored. */
    uint8 TxDMAChannel;                                 /*!< Channel number for DMA tx channel.If DMA mode is not used this field will be ignored. */
    boolean IdleErrorIntEnable;                         /*!< enable/disable idle interrupt. */
    Uart_LineSizeType LinIdleDetectSize;                /*!< Idle line detect size */
} Uart_UartUserConfigType;

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDDUART_LINFLEXDUART_TYPES_H */

