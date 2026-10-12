/**
*   @file    CddUart_Types.h
*   @version
*   @brief   AUTOSAR CddUart module datatype defines.
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
#ifndef CDDUART_TYPES_H
#define CDDUART_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"
#include "CddUart_Mld_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDDUART_TYPES_VENDOR_ID                    (180)
#define CDDUART_TYPES_AR_RELEASE_MAJOR_VERSION     (4)
#define CDDUART_TYPES_AR_RELEASE_MINOR_VERSION     (4)
#define CDDUART_TYPES_AR_RELEASE_REVISION_VERSION  (0)
#define CDDUART_TYPES_SW_MAJOR_VERSION             (0)
#define CDDUART_TYPES_SW_MINOR_VERSION             (9)
#define CDDUART_TYPES_SW_PATCH_VERSION             (1)
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/*Checks against Uart_Defines.h */

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief            Driver not initialized
* @details Errors reported by Det_ReportError() and Det_ReportRuntimeError().
*
*/
#define CDDUART_E_UNINIT               ((uint8)0x01U)

/**
* @brief Invalid channel given as parameter
* @details Errors reported by Det_ReportError() and Det_ReportRuntimeError().
*
*/
#define CDDUART_E_INVALID_CHANNEL      ((uint8)0x02U)

/**
* @brief Invalid channel given as parameter
* @details Errors reported by Det_ReportError() and Det_ReportRuntimeError().
*
*/
#define CDDUART_E_INVALID_POINTER      ((uint8)0x03U)

/**
* @brief Driver already initialized
* @details Errors reported by Det_ReportError() and Det_ReportRuntimeError().
*
*/
#define CDDUART_E_ALREADY_INITIALIZED  ((uint8)0x04U)

/**
* @brief Invalid coreid
*
*/
#define CDDUART_E_PARAM_CONFIG         ((uint8)0x05U)

/**
* @brief Channel is busy, therefore the service can not be executed
* @details Errors reported by Det_ReportError() and Det_ReportRuntimeError().
*
*/
#define CDDUART_E_CHANNEL_BUSY         ((uint8)0x06U)

/**
* @brief Parameter has a wrong value
* @details Errors reported by Det_ReportError() and Det_ReportRuntimeError().
*
*/
#define CDDUART_E_INVALID_PARAMETER    ((uint8)0x07U)

/**
* @brief Timeout occured
* @details Errors reported by Det_ReportError() and Det_ReportRuntimeError().
*
*/
#define CDDUART_E_TIMEOUT              ((uint8)0x08U)

/**
* @brief Invalid pointer for init function parameter
* @details Errors reported by Det_ReportError() and Det_ReportRuntimeError().
*
*/
#define CDDUART_E_INIT_FAILED          ((uint8)0x09U)

/**
* @brief De-Init function for specific HW channel finish unsuccessfully
* @details Errors reported by Det_ReportError() and Det_ReportRuntimeError().
*
*/
#define CDDUART_E_DEINIT_FAILED         ((uint8)0x10U)

/**
* @brief Parameter is out of range
* @details Errors reported by Det_ReportError() and Det_ReportRuntimeError().
*
*/
#define CDDUART_E_OUT_OF_RANGE         ((uint8)0x11U)

/**< @brief API service ID for UART_Init() function
* @details          Parameters used when raising an error or exception.
*
*/
#define CDDUART_INIT_ID                 ((uint8)0x00U)

/**
* @brief API service ID for UART_DeInit() function
* @details Parameters used when raising an error or exception.
*
*/
#define CDDUART_DEINIT_ID               ((uint8)0x01U)

/**
* @brief API service ID for UART_SetBaudrate() function
* @details Parameters used when raising an error or exception.
*
*/
#define CDDUART_SETBAUDRATE_ID          ((uint8)0x02U)

/**
* @brief API service ID for UART_GetBaudrate() function
* @details Parameters used when raising an error or exception.
*
*/
#define CDDUART_GETBAUDRATE_ID          ((uint8)0x03U)

/**
* @brief API service ID for UART_SyncSend() function
* @details Parameters used when raising an error or exception.
*
*/
#define CDDUART_SYNCSEND_ID             ((uint8)0x04U)

/**
* @brief API service ID for UART_AsyncReceive() function
* @details Parameters used when raising an error or exception.
*
*/
#define CDDUART_ASYNCSEND_ID            ((uint8)0x05U)

/**
* @brief API service ID for UART_SyncReceive() function
* @details Parameters used when raising an error or exception.
*
*/
#define CDDUART_SYNCRECEIVE_ID          ((uint8)0x06U)

/**
* @brief API service ID for UART_AsyncSend() function
* @details Parameters used when raising an error or exception.
*
*/
#define CDDUART_ASYNCRECEIVE_ID         ((uint8)0x07U)

/**
* @brief API service ID for UART_Abort() function
* @details Parameters used when raising an error or exception.
*
*/
#define CDDUART_ABORT_ID                ((uint8)0x08U)

/**
* @brief API service ID for UART_GetStatus() function
* @details Parameters used when raising an error or exception.
*
*/
#define CDDUART_GETSTATUS_ID            ((uint8)0x09U)

/**
* @brief API service ID for Uart_GetVersionInfo() function
* @details Parameters used when raising an error or exception.
*
*/
#define CDDUART_VERSIONINFO_ID          ((uint8)0x0AU)

/**
* @brief API service ID for UART_SetBuffer() function
* @details Parameters used when raising an error or exception.
*
*/
#define CDDUART_SETBUFFER_ID            ((uint8)0x0BU)

/**
* @brief API service ID for UART_SetCallBack() function
* @details Parameters used when raising an error or exception.
*
*/
#define CDDUART_SETCALLBACKFUN_ID       ((uint8)0x0CU)

/**
* @brief            Driver initialization status.
* @details          This enum contains the values for the driver initialization status.
*/
typedef enum
{
    CDDUART_DRV_UNINIT = 0U,    /**< @brief Driver not initialized */
    CDDUART_DRV_INIT,           /**< @brief Driver ready */
} CddUart_DrvStatusType;

/**
* @brief          The type operation of an Uart channel.
*/
/* implements     Uart_DataDirectionType_enum */
typedef enum
{
    CDDUART_SEND    = (uint8)0x00U,  /**< @brief The sending operation */
    CDDUART_RECEIVE = (uint8)0x01U   /**< @brief The receiving operation */
} CddUart_DataDirectionType;
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Uart channel configuration type structure.
* @details        This is the type of the external data structure containing
*                 the overall initialization data for one Uart Channel.
*                 A pointer to such a structure is provided to the Uart channel
*                 initialization routine for configuration of the Uart hardware
*                 channel.
*
*/
/* implements     Uart_ChannelConfigType_structure */
typedef struct
{
    uint8 UartChannelId;                               /**< @brief Uart channel configured  */
    uint32 ChannelCoreId;                              /**< @brief Core id on which the Uart channel has been assigned  */
    uint32 ChannelClockFrequency;                      /**< @brief The clock frequency configured on the given channel  */
    const CddUart_Mld_HwConfigType *UartChannelConfig; /**< @brief Pointer to a lower level channel configuration  */
} CddUart_ChannelConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDDUART_Types_H */

