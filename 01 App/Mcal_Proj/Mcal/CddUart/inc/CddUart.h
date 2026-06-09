/**
*   @file    CddUart.h
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
#ifndef CDDUART_H
#define CDDUART_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CddUart_Cfg.h"
/* Api to retrieve the core id */
#if (STD_ON == CDDUART_MULTICORE_SUPPORT)
#define CddUart_GetCoreID() (OsIf_GetCoreID())
#else
#define CddUart_GetCoreID() ((uint32)0x0U)
#endif /* (STD_ON == CDDUART_MULTICORE_SUPPORT) */
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDDUART_MODULE_ID                      255
#define CDDUART_VENDOR_ID                      (180)
#define CDDUART_AR_RELEASE_MAJOR_VERSION       (4)
#define CDDUART_AR_RELEASE_MINOR_VERSION       (4)
#define CDDUART_AR_RELEASE_REVISION_VERSION    (0)
#define CDDUART_SW_MAJOR_VERSION               (0)
#define CDDUART_SW_MINOR_VERSION               (9)
#define CDDUART_SW_PATCH_VERSION               (1)

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CddUart header file are of the same Autosar version */
#if (CDDUART_VENDOR_ID_CFG != CDDUART_VENDOR_ID)
#error "CddUart.h and CddUart_Cfg.h have different vendor ids"
#endif

/* Check if source file and CddUart header file are of the same Autosar version */
#if ((CDDUART_AR_RELEASE_MAJOR_VERSION_CFG != CDDUART_AR_RELEASE_MAJOR_VERSION) || \
     (CDDUART_AR_RELEASE_MINOR_VERSION_CFG != CDDUART_AR_RELEASE_MINOR_VERSION) || \
     (CDDUART_AR_RELEASE_REVISION_VERSION_CFG != CDDUART_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of CddUart.h  and CddUart_Cfg.h are different"
#endif

/* Check if source file and CddUart header file are of the same Software version */
#if ((CDDUART_SW_MAJOR_VERSION_CFG != CDDUART_SW_MAJOR_VERSION) || \
     (CDDUART_SW_MINOR_VERSION_CFG != CDDUART_SW_MINOR_VERSION) || \
     (CDDUART_SW_PATCH_VERSION_CFG != CDDUART_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of CddUart.h  and CddUart_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Uart driver configuration type structure.
* @details        This is the type of the pointer to the external data
*                 Uart Channels.
*                 A pointer of such a structure is provided to the Uart driver
*                 initialization routine for configuration of the Uart hardware
*                 channel.
*/
/* implements     Uart_ConfigType_structure */
typedef struct
{
    uint32 PartitionCoreId;                                 /**< @brief Partition configured of the core  */
    /**
     * @brief     Hardware channel.
     * @details   Constant pointer of the constant external data
     *            structure containing the overall initialization data
     *            for all the configured Uart Channels.
     */
    const CddUart_ChannelConfigType *Configs[CDDUART_CH_MAX_CONFIG];
} CddUart_ConfigType;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


/**
* @brief   Initializes the UART module.
* @details This function performs software initialization of UART
*          driver. It shall configure the Uart hardware peripheral for each channel.
*
* @param[in] Config Pointer to UART driver configuration set.
*
* @return  void
*
*/
void CddUart_Init(const CddUart_ConfigType *Config);

/**
* @brief   De-initializes the UART module.
*
* @details This function performs software de-initialization of UART driver.
*
* @return  void
*
**/
void CddUart_Deinit(void);

/**
* @brief   Configures the baud rate for the serial communication.
*
* @details This function performs the setting of the communication baudrate provided in the parameter.
*
* @param[in] Channel  Uart channel to be addressed.
* @param[in] Baudrate Baudrate value to be set.
*
* @return Std_ReturnType.
* @retval E_NOT_OK  If the Uart Channel is not valid or Uart driver is not initialized or
*                   a transfer is on-going or wrong core is addressed.
* @retval E_OK      If the baudrate has been set successfully.
*
**/
Std_ReturnType CddUart_SetBaudrate(uint8 Channel, uint32 Baudrate);

/**
* @brief   Retrieves the baud rate which is currently set for the serial communication.
*
* @details This function returns via the second parameter the current serial baudrate.
*
* @param[in]  Channel  Uart channel to be addressed.
* @param[out] Baudrate Pointer to a memory location where the baudrate value is returned.
*
* @return Std_ReturnType.
* @retval E_NOT_OK If the Uart Channel is not valid or Uart driver is not initialized or
*                  a transfer is on-going or wrong core is addressed or a NULL_PTR pointer has been provided
* @retval E_OK     If the baudrate has been returned successfully.
*
**/
Std_ReturnType CddUart_GetBaudrate(uint8 Channel, uint32 *Baudrate);
/**
* @brief   Configures a Callback function for continuous transfers.
*
* @details This function can be called inside a notification callback.
*
* @param[in] Channel          Uart channel to be addressed.
* @param[in] CallBackFunction This parameter is the Callback function.
*
* @return void.
*
**/
void CddUart_SetCallBack(uint8 Channel, CddUart_General_CallbackType CallBackFunction);

/**
* @brief   Configures a new buffer for continuous transfers.
*
* @details This function can be called inside a notification callback and
*          offers the possibility to change the buffer in order to assure a
*          continuous asynchronous transfer.
*
* @param[in]     Channel    Uart channel to be addressed.
* @param[in out] Buffer     The new buffer provided.
* @param[in]     BufferSize The size of the new buffer.
* @param[in]     Direction  This parameter indicates for which type of transmission is the buffer set. Its values are UART_SEND for
*                           setting a buffer when the previous buffer is empty and there are more bytes to send and UART_RECEIVE to set
*                           a new buffer when the previous buffer is full with received buffer and there is more data to be received.
*
* @return void.
*
**/
void CddUart_SetBuffer(uint8 Channel,  uint8 *Buffer, uint32 BufferSize, CddUart_DataDirectionType Direction);

/**
* @brief   Starts a synchronous transfer of bytes.
*
* @details This function starts sending a number of bytes in a synchronous manner.
*
* @param[in] Channel    Uart channel to be addressed.
* @param[in] Buffer     The buffer which contains the bytes to be sent.
* @param[in] BufferSize The Buffer size.
* @param[in] Timeout    The timeout in us.

* @return Std_ReturnType.
* @retval E_NOT_OK If the Uart Channel is not valid or
*                  Uart driver is not initialized or
*                  Buffer is a NULL_PTR or
*                  BufferSize is 0, meaning no space has been allocated for the buffer or
*                  a wrong core has been accessed or
*                  a transfer is already on going on the requested channel or
*                  timeout occurred.
* @retval E_OK     Successful transfer.
*
**/
Std_ReturnType CddUart_SyncSend(uint8 Channel, uint8 *Buffer, uint32 BufferSize, uint32 Timeout);

/**
* @brief   Starts a synchronous reception of bytes.
*
* @details This function starts receiving a number of bytes in a synchronous manner.
*
* @param[in] Channel    Uart channel to be addressed.
* @param[in] Buffer     The buffer where the bytes will be located.
* @param[in] BufferSize The Buffer size.
* @param[in] Timeout    The timeout in us.
*
* @return Std_ReturnType.
* @retval E_NOT_OK If the Uart Channel is not valid or
*                  Uart driver is not initialized or
*                  Buffer is a NULL_PTR or
*                  BufferSize is 0, meaning no space has been allocated for the buffer or
*                  a wrong core has been accessed or
*                  a reception is already on going on the requested channel or
*                  timeout occurred.
*
* @retval E_OK     Successful reception.
*
**/
Std_ReturnType CddUart_SyncReceive(uint8 Channel, uint8 *Buffer, uint32 BufferSize, uint32 Timeout);

/**
* @brief   Aborts an on-going transfer.

* @details This function aborts either a reception or a transmission depending on the last parameter.
*
* @param[in] Channel          Uart channel to be addressed.
* @param[in] TransmissionType Type of the transfer to be aborted. It can be either UART_SEND or UART_RECEIVE.
*
* @return Std_ReturnType.
* @retval E_NOT_OK If the Uart Channel is not valid or
*                  Uart driver is not initialized or
*                  a wrong core has been accessed
*
* @retval E_OK     Successful transfer aborted or in case no transfer was on going.
*
**/
Std_ReturnType CddUart_Abort(uint8 Channel, CddUart_DataDirectionType TransmissionType);

/**
* @brief   Starts an asynchronous transfer(send) of bytes.
*
* @details This function starts sending a number of bytes in an asynchronous manner. The transfer can be performed using
*          either DMA or interrupts depending on the transfer type configured on the addressed channel.
*
* @param[in] Channel    Uart channel to be addressed.
* @param[in] Buffer     The buffer where the data to be sent is located.
* @param[in] BufferSize The Buffer size.
*
* @return Std_ReturnType.
* @retval E_NOT_OK If the Uart Channel is not valid or
*                  Uart driver is not initialized or
*                  Buffer is a NULL_PTR or
*                  BufferSize is 0, meaning no space has been allocated for the buffer or
*                  a wrong core has been accessed or
*                  a transfer(send) is already on going on the requested channel.
*
* @retval E_OK     The transfer(send) started successfully.
*
**/
Std_ReturnType CddUart_AsyncSend(uint8 Channel, uint8 *Buffer, uint32 BufferSize);

/**
* @brief   Starts an asynchronous transfer(receive) of bytes.
* @details This function starts receiving a number of bytes in an asynchronous manner. The transfer can be performed using
*          either DMA or interrupts depending on the transfer type configured on the addressed channel.
*
* @param[in] Channel    Uart channel to be addressed.
* @param[in] Buffer     The buffer where the data to be received will located.
* @param[in] BufferSize The Buffer size.
*
* @return Std_ReturnType.
* @retval E_NOT_OK If the Uart Channel is not valid or
*                  Uart driver is not initialized or
*                  Buffer is a NULL_PTR or
*                  BufferSize is 0, meaning no space has been allocated for the buffer or
*                  a wrong core has been accessed or
*                  a transfer(receive) is already on going on the requested channel.
*
* @retval E_OK     The transfer(receive) started successfully.
*
**/
Std_ReturnType CddUart_AsyncReceive(uint8 Channel,  uint8 *Buffer, uint32 BufferSize);

/**
* @brief   Returns the status of the previous transfer.
* @details This function returns the status of the previous transfer.
*          If there is a transfer in progress, this function will also get the number of remaining bytes at the time the function was called.
* @param[in]  Channel          Uart channel to be addressed.
* @param[out] BytesTransferred A pointer where the number of remaining bytes will be written.
* @param[in]  TransferType     The type of transfer in discussion (UART_SEND or UART_RECEIVE).
*
* @return  CddUart_StatusType.
* @retval  UART_STATUS_NO_ERROR          Operation has ended successfully.
* @retval  UART_STATUS_FRAMING_ERROR     Operation has had a framing error. This status is returned only if the TransferType parameter is RECEIVE.
* @retval  UART_STATUS_RX_OVERRUN_ERROR  Operation has had an overrun error. This status is returned only if the TransferType parameter is RECEIVE.
* @retval  UART_STATUS_PARITY_ERROR      Operation has had a parity error. This status is returned only if the TransferType parameter is RECEIVE.
* @retval  UART_STATUS_OPERATION_ONGOING Operation has not finished at the moment of function call.
* @retval  UART_STATUS_ABORTED           Operation has been aborted.
* @retval  UART_STATUS_TIMEOUT           Operation has had timeout in synchronous transfer functions with timeout value pass in Timeout parameter or
*                                        functions that use the loop function whose execution time exceeds the timeout value configured through the UI
*
**/
CddUart_StatusType CddUart_GetStatus(uint8 Channel, uint32 *BytesTransferred, CddUart_DataDirectionType TransferType);

#if (CDDUART_VERSION_INFO_API == STD_ON)
/**
* @brief   Returns the version information of this module.
*
* @details The version information includes:
*
* @param[in,out] VersionInfo Pointer for storing the version information of this module.
*
**/
void CddUart_GetVersionInfo(Std_VersionInfoType *VersionInfo);
#endif /* (CDDUART_VERSION_INFO_API == STD_ON) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* UART_H */

