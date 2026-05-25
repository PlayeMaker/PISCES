/**
*   @file    CddUart_Lld_UartCfg.c
*   @version
*   @brief   Mcu Uart configure file.
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
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "CddUart_Uart_Types.h"
#include "CddUart_Lld_UartCfg.h"
#if (CDDUART_DMA_USED == STD_ON )
#include "CddDma.h"
#endif
/*==================================================================================================
*                               FILE VERSION INFORMATION
==================================================================================================*/
#define CDDUART_VENDOR_ID_UART_CFG_C                      (180)
#define CDDUART_AR_RELEASE_MAJOR_VERSION_UART_CFG_C       (4)
#define CDDUART_AR_RELEASE_MINOR_VERSION_UART_CFG_C       (4)
#define CDDUART_AR_RELEASE_REVISION_VERSION_UART_CFG_C    (0)
#define CDDUART_SW_MAJOR_VERSION_UART_CFG_C               (0)
#define CDDUART_SW_MINOR_VERSION_UART_CFG_C               (9)
#define CDDUART_SW_PATCH_VERSION_UART_CFG_C               (1)
/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define CDDUART_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CddUart_MemMap.h"

extern void Uart_Callbcak(uint8 Channel, CddUart_General_EventType Event);/*!< Callback Function declaration */
/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

CDDUART_CONST const Uart_UartUserConfigType CddUart_Ip_HwConfig_0 = 
{
    .BaudRate = 115200, /*!< baud rate */
    .MaxBaudRate = 10000000U, /*!< maximum baud rate supported by the UART */
    .ParityType = UART_PARITY_DISABLED, /*!< always 0/always 1/even/odd */
    .StopBitsCount = UART_ONE_STOP_BIT, /*!< number of stop bits, 1 stop bit (default) or 2 stop bits */
    .WordLength = UART_8_BITS_PER_CHAR, /*!< number of bits per transmitted/received word */
    .TxTransferType = UART_USING_DMA, /*!< Type of UART tx transfer (interrupt/dma based) */
    .RxTransferType = UART_USING_DMA, /*!< Type of UART rx transfer (interrupt/dma based) */
    .ComplexCallback = Uart_Callbcak, /*!< Callback to invoke for data transitions */
    .LogicChannel = 0, /*!< Logical channel number for the UART instance */
    .RxDMAChannel = CddDmaConf_CddDmaConfig_dmaLogicChannel_Type_1, /*!< Channel number for DMA rx channel.*/
    .TxDMAChannel = CddDmaConf_CddDmaConfig_dmaLogicChannel_Type_0, /*!< Channel number for DMA tx channel.If DMA mode is not used this field will be ignored. */
    .IdleErrorIntEnable = TRUE, /*!< Enable/Disable Idle line error interrupt */
    .LinIdleDetectSize = UART_LINE_IDLE_SIZE_8_CHAR, /*!< Idle line detection Bytes size */
};

#define CDDUART_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CddUart_MemMap.h"

#ifdef __cplusplus
}
#endif

