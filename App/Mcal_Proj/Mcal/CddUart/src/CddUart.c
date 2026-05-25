/**
*   @file    CddUart.c
*   @version
*   @brief   AUTOSAR CddUart module interface
*   @details API implementation for CddUart driver
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
extern "C"
{
#endif
/**
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 2877 Dir-4.1:   This loop will never be executed more than once.
 */
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "CddUart_Mld.h"
#include "CddUart.h"
#include "OsIf.h"
#include "SchM_CddUart.h"
#if ((CDDUART_DEV_ERROR_DETECT == STD_ON) || (CDDUART_RUNTIME_ERROR_DETECT ==STD_ON))
#include "Det.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define CDDUART_VENDOR_ID_C                      (180)
#define CDDUART_AR_RELEASE_MAJOR_VERSION_C       (4)
#define CDDUART_AR_RELEASE_MINOR_VERSION_C       (4)
#define CDDUART_AR_RELEASE_REVISION_VERSION_C    (0)
#define CDDUART_SW_MAJOR_VERSION_C               (0)
#define CDDUART_SW_MINOR_VERSION_C               (9)
#define CDDUART_SW_PATCH_VERSION_C               (1)

/*=================================================================================================*/

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CddUart header file are of the same Autosar version */
#if (CDDUART_VENDOR_ID_C != CDDUART_VENDOR_ID)
#error "CddUart.c and CddUart.h have different vendor ids"
#endif

/* Check if source file and CddUart header file are of the same Autosar version */
#if ((CDDUART_AR_RELEASE_MAJOR_VERSION_C != CDDUART_AR_RELEASE_MAJOR_VERSION) || \
     (CDDUART_AR_RELEASE_MINOR_VERSION_C != CDDUART_AR_RELEASE_MINOR_VERSION) || \
     (CDDUART_AR_RELEASE_REVISION_VERSION_C != CDDUART_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of CddUart.c and CddUart.h are different"
#endif

/* Check if source file and CddUart header file are of the same Software version */
#if ((CDDUART_SW_MAJOR_VERSION_C != CDDUART_SW_MAJOR_VERSION) || \
     (CDDUART_SW_MINOR_VERSION_C != CDDUART_SW_MINOR_VERSION) || \
     (CDDUART_SW_PATCH_VERSION_C != CDDUART_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of CddUart.c and CddUart.h are different"
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#define CDDUART_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CddUart_MemMap.h"
/**
* @brief          UART driver status variable.
* @details        UART driver initialization status variable.
*/
CDDUART_VAR static CddUart_DrvStatusType CddUart_au8DriverStatus[CDDUART_MAX_PARTITIONS];
/**
* @brief          CddUart clock frequencies.
* @details        This variable retains the values of clock frequencies set at driver initialization for each channel.
*/
CDDUART_VAR static uint32 CddUart_au32ClockFrequency[CDDUART_MAX_PARTITIONS][CDDUART_CH_MAX_CONFIG];
#define CDDUART_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CddUart_MemMap.h"
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
#if (CDDUART_PRECOMPILE_SUPPORT == STD_ON)
extern const CddUart_ConfigType CddUart_PreCompileConfig;
#endif

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/**
* @brief          Global configuration pointer.
* @details        Pointer to the configuration structure.
*/
#define CDDUART_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CddUart_MemMap.h"
CDDUART_VAR static const CddUart_ConfigType *CddUart_apConfig[CDDUART_MAX_PARTITIONS];
#define CDDUART_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CddUart_MemMap.h"

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

static Std_ReturnType CddUart_StartSyncReceive(uint8 CoreId, uint8 Channel, uint8 *Buffer, uint32 BufferSize, uint32 Timeout);
static Std_ReturnType CddUart_StartSyncSend(uint8 CoreId, uint8 Channel, uint8 *Buffer, uint32 BufferSize, uint32 Timeout);
static Std_ReturnType CddUart_StartAsyncReceive(uint8 CoreId, uint8 Channel, uint8 *Buffer, uint32 BufferSize);
static Std_ReturnType CddUart_StartAsyncSend(uint8 CoreId, uint8 Channel, uint8 *Buffer, uint32 BufferSize);
static void CddUart_StartSetBuffer(uint8 CoreId, uint8 Channel, uint8 *Buffer, uint32 BufferSize, CddUart_DataDirectionType Direction);
#define CDDUART_START_SEC_CODE
#include "CddUart_MemMap.h"
/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @internal
* @brief  Start Receive data with polling method.
* @details This function will start receive data when CddUart_Ipw_GetReceiveStatus do not in ONGOING status.
* @param[in] CoreId       Core ID
* @param[in] Channel      CddUart channel used for transmission.
* @param[in] Buffer        Buffer to receive.
* @param[in] BufferSize  The number of bytes to receive.
*
*
* @return   E_OK:               Reception ended successfully
*           E_NOT_OK:           Reception didn't end successfully
*           UART_STATUS_TIMEOUT:     Reception has timeout
* This is not a public API as it is called from other driver functions.
*/
CDDUART_FUNC static Std_ReturnType CddUart_StartSyncReceive(uint8 CoreId, uint8 Channel, uint8 *Buffer, uint32 BufferSize, uint32 Timeout)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    CddUart_StatusType ReceiveStatus;
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
    if (CoreId != CddUart_apConfig[CoreId]->PartitionCoreId)
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        /* Invalid CoreId */
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              (uint8)CDDUART_SYNCRECEIVE_ID,
                              (uint8)CDDUART_E_PARAM_CONFIG);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if (NULL_PTR == CddUart_apConfig[CoreId]->Configs[Channel])
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  (uint8)CDDUART_SYNCRECEIVE_ID,
                                  (uint8)CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT     == STD_ON) */
        }
        else
        {
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
            SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_22();
            ReceiveStatus = CddUart_Mld_GetReceiveStatus(Channel, NULL_PTR);
            if (CDDUART_STATUS_OPERATION_ONGOING == ReceiveStatus)
            {
                /*GCOVR_EXCL_START*/
                SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_22();
                /*GCOVR_EXCL_STOP*/
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                      (uint8)0,
                                      CDDUART_SYNCRECEIVE_ID,
                                      CDDUART_E_CHANNEL_BUSY);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
                CddUart_Mld_SetReceiveStatus(Channel, CDDUART_STATUS_OPERATION_ONGOING);
                SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_22();
                TempReturn = CddUart_Mld_SyncReceive(Channel, Buffer, BufferSize, Timeout);
                (void)CoreId;
                if (E_OK != TempReturn)
                {
#if (CDDUART_RUNTIME_ERROR_DETECT == STD_ON)
                    /* Timeout occur */
                    (void)Det_ReportRuntimeError((uint16)CDDUART_MODULE_ID,
                                                 (uint8)0,
                                                 CDDUART_SYNCRECEIVE_ID,
                                                 CDDUART_E_TIMEOUT);
#endif /* (CDDUART_RUNTIME_ERROR_DETECT == STD_ON) */
                    TempReturn = E_NOT_OK;
                }
            }
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
        }
    }
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
    return TempReturn;
}

/**
* @internal
* @brief  Start Transfer data with polling method.
* @details This function will start transfer data when CddUart_Ipw_GetReceiveStatus do not in ONGOING status.
* @param[in] CoreId       Core ID
* @param[in] Channel      CddUart channel used for transmission.
* @param[in] Buffer        Buffer to send.
* @param[in] BufferSize  The number of bytes to send.
*
*
* @return   E_OK:               Reception ended successfully
*           E_NOT_OK:           Reception didn't end successfully
*           UART_STATUS_TIMEOUT:     Reception has timeout
* This is not a public API as it is called from other driver functions.
*/
CDDUART_FUNC static Std_ReturnType CddUart_StartSyncSend(uint8 CoreId, uint8 Channel, uint8 *Buffer, uint32 BufferSize, uint32 Timeout)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    CddUart_StatusType TransmitStatus;
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
    if (CoreId != CddUart_apConfig[CoreId]->PartitionCoreId)
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        /* Invalid CoreId */
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              (uint8)CDDUART_SYNCSEND_ID,
                              (uint8)CDDUART_E_PARAM_CONFIG);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if (NULL_PTR == CddUart_apConfig[CoreId]->Configs[Channel])
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  (uint8)CDDUART_SYNCSEND_ID,
                                  (uint8)CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT     == STD_ON) */
        }
        else
        {
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
            SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_21();
            TransmitStatus = CddUart_Mld_GetTransmitStatus(Channel, NULL_PTR);
            if (CDDUART_STATUS_OPERATION_ONGOING == TransmitStatus)
            {
                /*GCOVR_EXCL_START*/
                SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_21();
                /*GCOVR_EXCL_STOP*/
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                      (uint8)0,
                                      CDDUART_SYNCSEND_ID,
                                      CDDUART_E_CHANNEL_BUSY);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
                CddUart_Mld_SetTransmitStatus(Channel, CDDUART_STATUS_OPERATION_ONGOING);
                SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_21();
                TempReturn = CddUart_Mld_SyncSend(Channel, Buffer, BufferSize, Timeout);
                (void)CoreId;
                if (E_OK != TempReturn)
                {
#if (CDDUART_RUNTIME_ERROR_DETECT == STD_ON)
                    /* Timeout occur */
                    (void)Det_ReportRuntimeError((uint16)CDDUART_MODULE_ID,
                                                 (uint8)0,
                                                 CDDUART_SYNCSEND_ID,
                                                 CDDUART_E_TIMEOUT);
#endif /* (CDDUART_RUNTIME_ERROR_DETECT == STD_ON) */
                    TempReturn = E_NOT_OK;
                }
            }
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
        }
    }
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
    return TempReturn;
}

/**
* @internal
* @brief  Start Receive data with asynchronously method.
* @details This function will start receive data when CddUart_Ipw_GetReceiveStatus do not in ONGOING status.
* @param[in] CoreId       Core ID
* @param[in] Channel      CddUart channel used for transmission.
* @param[in] Buffer        Buffer to receive.
* @param[in] BufferSize  The number of bytes to receive.
*
*
* @return   E_OK:               Reception ended successfully
*           E_NOT_OK:           Reception didn't end successfully
*           UART_STATUS_TIMEOUT:     Reception has timeout
* This is not a public API as it is called from other driver functions.
*/
CDDUART_FUNC static Std_ReturnType CddUart_StartAsyncReceive(uint8 CoreId, uint8 Channel, uint8 *Buffer, uint32 BufferSize)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    CddUart_StatusType ReceiveStatus;
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
    if (CoreId != CddUart_apConfig[CoreId]->PartitionCoreId)
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        /* Invalid CoreId */
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              (uint8)CDDUART_ASYNCRECEIVE_ID,
                              (uint8)CDDUART_E_PARAM_CONFIG);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if (NULL_PTR == CddUart_apConfig[CoreId]->Configs[Channel])
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  (uint8)CDDUART_ASYNCRECEIVE_ID,
                                  (uint8)CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT     == STD_ON) */
        }
        else
        {
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
            SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_23();
            ReceiveStatus = CddUart_Mld_GetReceiveStatus(Channel, NULL_PTR);
            if (CDDUART_STATUS_OPERATION_ONGOING == ReceiveStatus)
            {
                /*GCOVR_EXCL_START*/
                SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_23();
                /*GCOVR_EXCL_STOP*/
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                      (uint8)0,
                                      CDDUART_ASYNCRECEIVE_ID,
                                      CDDUART_E_CHANNEL_BUSY);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
                CddUart_Mld_SetReceiveStatus(Channel, CDDUART_STATUS_OPERATION_ONGOING);
                SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_23();
                TempReturn = CddUart_Mld_AsyncReceive(Channel, Buffer, BufferSize);
                (void)CoreId;
            }
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
        }
    }
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
    return TempReturn;
}

/**
* @internal
* @brief  Start Transfer data with asynchronously method.
* @details This function will start transfer data when CddUart_Ipw_GetReceiveStatus do not in ONGOING status.
* @param[in] CoreId       Core ID
* @param[in] Channel      CddUart channel used for transmission.
* @param[in] Buffer        Buffer to send.
* @param[in] BufferSize  The number of bytes to send.
*
*
* @return   E_OK:               Reception ended successfully
*           E_NOT_OK:           Reception didn't end successfully
*           UART_STATUS_TIMEOUT:     Reception has timeout
* This is not a public API as it is called from other driver functions.
*/
CDDUART_FUNC static Std_ReturnType CddUart_StartAsyncSend(uint8 CoreId, uint8 Channel, uint8 *Buffer, uint32 BufferSize)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    CddUart_StatusType TransmitStatus;
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
    if (CoreId != CddUart_apConfig[CoreId]->PartitionCoreId)
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        /* Invalid CoreId */
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              (uint8)CDDUART_ASYNCSEND_ID,
                              (uint8)CDDUART_E_PARAM_CONFIG);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if (NULL_PTR == CddUart_apConfig[CoreId]->Configs[Channel])
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  (uint8)CDDUART_ASYNCSEND_ID,
                                  (uint8)CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT     == STD_ON) */
        }
        else
        {
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
            SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_24();
            TransmitStatus = CddUart_Mld_GetTransmitStatus(Channel, NULL_PTR);
            if (CDDUART_STATUS_OPERATION_ONGOING == TransmitStatus)
            {
                /*GCOVR_EXCL_START*/
                SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_24();
                /*GCOVR_EXCL_STOP*/
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                      (uint8)0,
                                      CDDUART_ASYNCSEND_ID,
                                      CDDUART_E_CHANNEL_BUSY);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
                CddUart_Mld_SetTransmitStatus(Channel, CDDUART_STATUS_OPERATION_ONGOING);
                SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_24();
                TempReturn = CddUart_Mld_AsyncSend(Channel,
                                                   Buffer,
                                                   BufferSize);
                (void)CoreId;
            }
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
        }
    }
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
    return TempReturn;
}

/**
* @internal
* @brief  Sets a tx or rx buffer.
* @details This function will start set up a buffer to receive or transmit.
* @param[in] CoreId       Core ID
* @param[in] Channel      CddUart channel used for transmission.
* @param[in] Buffer        Buffer to send.
* @param[in] BufferSize  The number of bytes to send.
* @param[in] Direction           Transmission type.
*
* @return   E_OK:               Reception ended successfully
*           E_NOT_OK:           Reception didn't end successfully
* This is not a public API as it is called from other driver functions.
*/
CDDUART_FUNC static void CddUart_StartSetBuffer(uint8 CoreId, uint8 Channel, uint8 *Buffer, uint32 BufferSize, CddUart_DataDirectionType Direction)
{
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
    if (CoreId != CddUart_apConfig[CoreId]->PartitionCoreId)
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        /* Invalid CoreId */
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              (uint8)CDDUART_SETBUFFER_ID,
                              (uint8)CDDUART_E_PARAM_CONFIG);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if (NULL_PTR == CddUart_apConfig[CoreId]->Configs[Channel])
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  (uint8)CDDUART_SETBUFFER_ID,
                                  (uint8)CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT     == STD_ON) */
        }
        else
        {
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
            if (CDDUART_SEND == Direction)
            {
                CddUart_Mld_SetTxBuffer(Channel, Buffer, BufferSize);
            }
            else
            {
                CddUart_Mld_SetRxBuffer(Channel, Buffer, BufferSize);
            }
            (void)CoreId;
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
        }
    }
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
}
/**
* @internal
* @brief  Sets a tx or rx CallBack.
* @details This function will start set up a callback function to receive or transmit.
* @param[in] CoreId              Core ID
* @param[in] Channel             CddUart channel used for transmission.
* @param[in] Direction           Transmission type.
* @param[in] CallBackFunction    CallBack Function.
*
* @return   E_OK:               Reception ended successfully
*           E_NOT_OK:           Reception didn't end successfully
* This is not a public API as it is called from other driver functions.
*/
CDDUART_FUNC static void CddUart_StartSetCallBackFun(uint8 CoreId, uint8 Channel, CddUart_General_CallbackType CallBackFunction)
{
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
    if (CoreId != CddUart_apConfig[CoreId]->PartitionCoreId)
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        /* Invalid CoreId */
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              (uint8)CDDUART_SETCALLBACKFUN_ID,
                              (uint8)CDDUART_E_PARAM_CONFIG);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if (NULL_PTR == CddUart_apConfig[CoreId]->Configs[Channel])
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  (uint8)CDDUART_SETCALLBACKFUN_ID,
                                  (uint8)CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT     == STD_ON) */
        }
        else
        {
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
            CddUart_Mld_SetCallBack(Channel, CallBackFunction);
            (void)CoreId;
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
        }
    }
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
}

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
CDDUART_FUNC void CddUart_Init(const CddUart_ConfigType *Config)
{
    uint8 U8ChLoop;
    uint8 CoreId;
    uint8 Channel;
    /* Get core ID of current processor */
    CoreId = (uint8) CddUart_GetCoreID();
    /* Check whether the CddUart driver is in CDDUART_DRV_UNINIT state */
    if (CDDUART_DRV_UNINIT != CddUart_au8DriverStatus[CoreId])
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        /* CddUart driver has been already initialized */
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              CDDUART_INIT_ID,
                              CDDUART_E_ALREADY_INITIALIZED);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
#if (CDDUART_PRECOMPILE_SUPPORT == STD_OFF)
        /* Check Config for not being a null pointer */
        if (NULL_PTR == Config)
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            /* Invalid pointer */
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID, \
                                  (uint8)0, \
                                  CDDUART_INIT_ID, \
                                  CDDUART_E_INIT_FAILED \
                                 );
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
        }
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
        else if (CoreId != Config->PartitionCoreId)
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            /* Invalid CoreId */
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  (uint8)CDDUART_INIT_ID,
                                  (uint8)CDDUART_E_PARAM_CONFIG);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
        }
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
        else
        {
            CddUart_apConfig[CoreId] = Config;
#else /* CDDUART_PRECOMPILE_SUPPORT == STD_ON */
        if (NULL_PTR != Config)
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            /* Invalid pointer */
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  (uint8)CDDUART_INIT_ID,
                                  (uint8)CDDUART_E_INIT_FAILED);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
        }
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
        else if ((NULL_PTR == CddUart_PBCfgVariant[CoreId]) ||
                 (CoreId != CddUart_PBCfgVariant[CoreId]->PartitionCoreId))
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            /* Invalid CoreId */
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  (uint8)CDDUART_INIT_ID,
                                  (uint8)CDDUART_E_PARAM_CONFIG);
#endif /* CDDUART_DEV_ERROR_DETECT == STD_ON */
        }
#endif /* CDDUART_MULTICORE_SUPPORT == STD_ON */
        else
        {
            CddUart_apConfig[CoreId] = &CddUart_PreCompileConfig;
            (void)Config;
#endif /* CDDUART_PRECOMPILE_SUPPORT == STD_ON */
            /*
             * MR12 Dir-4.4 VIOLATION: This loop will never be executed more than once.
             * CDDUART_CH_MAX_CONFIG is a configuration parameter, which may be once or multiple times.
             * So, this approach can be adopted
            */
            U8ChLoop = 0U;
            for (; U8ChLoop < CDDUART_CH_MAX_CONFIG; ++U8ChLoop)/* PRQA S 2877*/
            {
                if (CddUart_apConfig[CoreId]->Configs[U8ChLoop] != NULL_PTR)
                {
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
                    if (CoreId == CddUart_apConfig[CoreId]->Configs[U8ChLoop]->ChannelCoreId)
                    {
#endif /* CDDUART_MULTICORE_SUPPORT == STD_ON */
                        Channel = CddUart_apConfig[CoreId]->Configs[U8ChLoop]->UartChannelId;
                        CddUart_au32ClockFrequency[CoreId][Channel] = CddUart_apConfig[CoreId]->Configs[U8ChLoop]->ChannelClockFrequency;
                        CddUart_Mld_Init(Channel, CddUart_au32ClockFrequency[CoreId][Channel], CddUart_apConfig[CoreId]->Configs[U8ChLoop]->UartChannelConfig);
                        /* Update UART driver status to CDDUART_DRV_INIT */
                        CddUart_au8DriverStatus[CoreId] = CDDUART_DRV_INIT;
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
                    }
#endif /* CDDUART_MULTICORE_SUPPORT == STD_ON */
                }
            }
        }
    }
}
/*===============================================================================================*/
CDDUART_FUNC void CddUart_Deinit(void)
{
    uint8 U8ChLoop = 0U;
    uint8 CoreId = 0U;
    uint8 Channel;
    CddUart_StatusType ReceiveStatus;
    CddUart_StatusType TransmitStatus;
    boolean IsAllChannelsIdle = TRUE;
    /* Get core ID of current processor */
    CoreId = (uint8) CddUart_GetCoreID();
    /* Check whether the UART driver is in CDDUART_DRV_UNINIT state */
    if (CDDUART_DRV_INIT != CddUart_au8DriverStatus[CoreId])
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        /* CddUart driver has been already initialized */
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              CDDUART_DEINIT_ID,
                              CDDUART_E_UNINIT);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        /*
        * MR12 Dir-4.4 VIOLATION: This loop will never be executed more than once.
        * CDDUART_CH_MAX_CONFIG is a configuration parameter, which may be once or multiple times.
        * So, this approach can be adopted
        */
        U8ChLoop = 0U;
        for (; U8ChLoop < CDDUART_CH_MAX_CONFIG; ++U8ChLoop)/* PRQA S 2877*/
        {
            if (CddUart_apConfig[CoreId]->Configs[U8ChLoop] != NULL_PTR)
            {
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
                if (CoreId == CddUart_apConfig[CoreId]->Configs[U8ChLoop]->ChannelCoreId)
                {
#endif /* CDDUART_MULTICORE_SUPPORT == STD_ON */
                    Channel = CddUart_apConfig[CoreId]->Configs[U8ChLoop]->UartChannelId;
                    ReceiveStatus = CddUart_Mld_GetReceiveStatus(Channel, NULL_PTR);
                    TransmitStatus = CddUart_Mld_GetTransmitStatus(Channel, NULL_PTR);
                    /* Check whether channel is busy sending or receiving */
                    if ((CDDUART_STATUS_OPERATION_ONGOING == ReceiveStatus) ||
                            (CDDUART_STATUS_OPERATION_ONGOING == TransmitStatus))
                    {
                        IsAllChannelsIdle = FALSE;
                        break;
                    }
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
                }
#endif /* CDDUART_MULTICORE_SUPPORT == STD_ON */
            }
        }
        if (TRUE == IsAllChannelsIdle)
        {
            /*
             * MR12 Dir-4.4 VIOLATION: This loop will never be executed more than once.
             * CDDUART_CH_MAX_CONFIG is a configuration parameter, which may be once or multiple times.
             * So, this approach can be adopted
            */
            /* In case all of setting channel are free */
            U8ChLoop = 0U;
            for (; U8ChLoop < CDDUART_CH_MAX_CONFIG; ++U8ChLoop)/* PRQA S 2877*/
            {
                if (CddUart_apConfig[CoreId]->Configs[U8ChLoop] != NULL_PTR)
                {
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
                    if (CoreId == CddUart_apConfig[CoreId]->Configs[U8ChLoop]->ChannelCoreId)
                    {
#endif /* CDDUART_MULTICORE_SUPPORT == STD_ON */
                        Channel = CddUart_apConfig[CoreId]->Configs[U8ChLoop]->UartChannelId;
                        /* Deinit channel */
                        CddUart_Mld_Deinit(Channel);
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
                    }
#endif /* CDDUART_MULTICORE_SUPPORT == STD_ON */
                }
            }
            CddUart_au8DriverStatus[CoreId] = CDDUART_DRV_UNINIT;
            CddUart_apConfig[CoreId] = NULL_PTR;
        }
        else
        {
            /* In case one or more channels are busy */
#if (CDDUART_RUNTIME_ERROR_DETECT == STD_ON)
            /* Timeout occur */
            (void)Det_ReportRuntimeError((uint16)CDDUART_MODULE_ID,
                                         (uint8)0,
                                         CDDUART_DEINIT_ID,
                                         CDDUART_E_DEINIT_FAILED);
#endif /* (CDDUART_RUNTIME_ERROR_DETECT == STD_ON) */
        }
    }
}
/* implements     CddUart_SetBaudrate_Activity*/
CDDUART_FUNC Std_ReturnType CddUart_SetBaudrate(uint8 Channel, uint32 Baudrate)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    uint8 CoreId;
    CddUart_StatusType ReceiveStatus;
    CddUart_StatusType TransmitStatus;
    CoreId = (uint8) CddUart_GetCoreID();
    if (CDDUART_DRV_UNINIT == CddUart_au8DriverStatus[CoreId])
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              CDDUART_SETBAUDRATE_ID,
                              CDDUART_E_UNINIT);
#endif /* (CDDUART_DEV_ERROR_DETECT     == STD_ON) */
    }
    else if (Channel >= CDDUART_CH_MAX_CONFIG)
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              CDDUART_SETBAUDRATE_ID,
                              CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT     == STD_ON) */
    }
    else if (Baudrate > CddUart_apConfig[0]->Configs[Channel]->UartChannelConfig->UserConfig->UserConfigOfUartHard->MaxBaudRate)
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              CDDUART_SETBAUDRATE_ID,
                              CDDUART_E_OUT_OF_RANGE);
#endif /* (CDDUART_DEV_ERROR_DETECT     == STD_ON) */
    }
    else
    {
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
        if (CoreId != CddUart_apConfig[CoreId]->PartitionCoreId)
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            /* Invalid CoreId */
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  (uint8)CDDUART_SETBAUDRATE_ID,
                                  (uint8)CDDUART_E_PARAM_CONFIG);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            if (NULL_PTR == CddUart_apConfig[CoreId]->Configs[Channel])
            {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                      (uint8)0,
                                      (uint8)CDDUART_SETBAUDRATE_ID,
                                      (uint8)CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT     == STD_ON) */
            }
            else
            {
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
                ReceiveStatus = CddUart_Mld_GetReceiveStatus(Channel, NULL_PTR);
                TransmitStatus = CddUart_Mld_GetTransmitStatus(Channel, NULL_PTR);
                /* Check whether channel is busy sending or receiving */
                if ((CDDUART_STATUS_OPERATION_ONGOING == ReceiveStatus) ||
                        (CDDUART_STATUS_OPERATION_ONGOING == TransmitStatus))
                {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                    (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                          (uint8)0,
                                          CDDUART_SETBAUDRATE_ID,
                                          CDDUART_E_CHANNEL_BUSY);
#endif /* (CDDUART_DEV_ERROR_DETECT     == STD_ON) */
                }
                else
                {
                    TempReturn = CddUart_Mld_SetBaudrate(Channel, Baudrate, CddUart_au32ClockFrequency[CoreId][Channel]);
                }
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
            }
        }
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
    }
    return TempReturn;
}
/* implements     CddUart_GetBaudrate_Activity*/
CDDUART_FUNC Std_ReturnType CddUart_GetBaudrate(uint8 Channel, uint32 * Baudrate)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    uint8 CoreId;
    /* Get core ID of current processor */
    CoreId = (uint8) CddUart_GetCoreID();
    if (CDDUART_DRV_UNINIT == CddUart_au8DriverStatus[CoreId])
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              CDDUART_GETBAUDRATE_ID,
                              CDDUART_E_UNINIT);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if (Channel >= CDDUART_CH_MAX_CONFIG)
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  CDDUART_GETBAUDRATE_ID,
                                  CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            if (NULL_PTR == Baudrate)
            {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                      (uint8)0,
                                      CDDUART_GETBAUDRATE_ID,
                                      CDDUART_E_INVALID_POINTER);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
                if (CoreId != CddUart_apConfig[CoreId]->PartitionCoreId)
                {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                    /* Invalid CoreId */
                    (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                          (uint8)0,
                                          (uint8)CDDUART_GETBAUDRATE_ID,
                                          (uint8)CDDUART_E_PARAM_CONFIG);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
                }
                else
                {
                    if (NULL_PTR == CddUart_apConfig[CoreId]->Configs[Channel])
                    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                              (uint8)0,
                                              (uint8)CDDUART_GETBAUDRATE_ID,
                                              (uint8)CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT     == STD_ON) */
                    }
                    else
                    {
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
                        CddUart_Mld_GetBaudrate(Channel, Baudrate);
                        TempReturn = E_OK;
                        (void)CoreId;
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
                    }
                }
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
            }
        }
    }
    return TempReturn;
}
/* implements     CddUart_Abort_Activity*/
CDDUART_FUNC Std_ReturnType CddUart_Abort(uint8 Channel, CddUart_DataDirectionType TransmissionType)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    uint8 CoreId;
    /* Get core ID of current processor */
    CoreId = (uint8) CddUart_GetCoreID();
    if (CDDUART_DRV_UNINIT == CddUart_au8DriverStatus[CoreId])
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              CDDUART_ABORT_ID,
                              CDDUART_E_UNINIT);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if (Channel >= CDDUART_CH_MAX_CONFIG)
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  CDDUART_ABORT_ID,
                                  CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
            if (CoreId != CddUart_apConfig[CoreId]->PartitionCoreId)
            {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                /* Invalid CoreId */
                (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                      (uint8)0,
                                      (uint8)CDDUART_ABORT_ID,
                                      (uint8)CDDUART_E_PARAM_CONFIG);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
                if (NULL_PTR == CddUart_apConfig[CoreId]->Configs[Channel])
                {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                    (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                          (uint8)0,
                                          (uint8)CDDUART_ABORT_ID,
                                          (uint8)CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT     == STD_ON) */
                }
                else
                {
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
                    if (CDDUART_SEND == TransmissionType)
                    {
                        TempReturn = CddUart_Mld_AbortSendingData(Channel);
                    }
                    else
                    {
                        TempReturn = CddUart_Mld_AbortReceivingData(Channel);
                    }
                    (void)CoreId;
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
                }
            }
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
        }
    }
    return TempReturn;
}
/* implements     CddUart_SetBuffer_Activity*/
CDDUART_FUNC void CddUart_SetBuffer(uint8 Channel,  uint8 * Buffer, uint32 BufferSize, CddUart_DataDirectionType Direction)
{
    uint8 CoreId;
    /* Get core ID of current processor */
    CoreId = (uint8) CddUart_GetCoreID();
    if (CDDUART_DRV_UNINIT == CddUart_au8DriverStatus[CoreId])
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              CDDUART_SETBUFFER_ID,
                              CDDUART_E_UNINIT);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if (Channel >= CDDUART_CH_MAX_CONFIG)
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  CDDUART_SETBUFFER_ID,
                                  CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            if (NULL_PTR == Buffer)
            {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                      (uint8)0,
                                      CDDUART_SETBUFFER_ID,
                                      CDDUART_E_INVALID_POINTER);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
                if (0U == BufferSize)
                {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                    (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                          (uint8)0,
                                          CDDUART_SETBUFFER_ID,
                                          CDDUART_E_INVALID_PARAMETER);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
                }
                else
                {
                    CddUart_StartSetBuffer(CoreId, Channel, Buffer, BufferSize, Direction);
                }
            }
        }
    }
}
/* implements     CddUart_SetCallBackFunction_Activity*/
CDDUART_FUNC void CddUart_SetCallBack(uint8 Channel, CddUart_General_CallbackType CallBackFunction)
{
    uint8 CoreId;
    /* Get core ID of current processor */
    CoreId = (uint8) CddUart_GetCoreID();
    if (CDDUART_DRV_UNINIT == CddUart_au8DriverStatus[CoreId])
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              CDDUART_SETCALLBACKFUN_ID,
                              CDDUART_E_UNINIT);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if (Channel >= CDDUART_CH_MAX_CONFIG)
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  CDDUART_SETCALLBACKFUN_ID,
                                  CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            if (NULL_PTR == CallBackFunction)
            {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                      (uint8)0,
                                      CDDUART_SETCALLBACKFUN_ID,
                                      CDDUART_E_INVALID_POINTER);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
                CddUart_StartSetCallBackFun(CoreId, Channel, CallBackFunction);
            }
        }
    }
}
/* implements     CddUart_SyncSend_Activity*/
CDDUART_FUNC Std_ReturnType CddUart_SyncSend(uint8 Channel, uint8 * Buffer, uint32 BufferSize, uint32 Timeout)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    uint8 CoreId;
    /* Get core ID of current processor */
    CoreId = (uint8) CddUart_GetCoreID();
    if (CDDUART_DRV_UNINIT == CddUart_au8DriverStatus[CoreId])
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              CDDUART_SYNCSEND_ID,
                              CDDUART_E_UNINIT);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if (Channel >= CDDUART_CH_MAX_CONFIG)
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  CDDUART_SYNCSEND_ID,
                                  CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            if (NULL_PTR == Buffer)
            {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                      (uint8)0,
                                      CDDUART_SYNCSEND_ID,
                                      CDDUART_E_INVALID_POINTER);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
                if (0U == BufferSize)
                {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                    (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                          (uint8)0,
                                          CDDUART_SYNCSEND_ID,
                                          CDDUART_E_INVALID_PARAMETER);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
                }
                else
                {
                    TempReturn = CddUart_StartSyncSend(CoreId, Channel, Buffer, BufferSize, Timeout);
                }
            }
        }
    }
    return TempReturn;
}
/* implements     CddUart_SyncReceive_Activity*/
CDDUART_FUNC Std_ReturnType CddUart_SyncReceive(uint8 Channel, uint8 * Buffer, uint32 BufferSize, uint32 Timeout)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    uint8 CoreId;
    /* Get core ID of current processor */
    CoreId = (uint8) CddUart_GetCoreID();
    if (CDDUART_DRV_UNINIT == CddUart_au8DriverStatus[CoreId])
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              CDDUART_SYNCRECEIVE_ID,
                              CDDUART_E_UNINIT);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if (Channel >= CDDUART_CH_MAX_CONFIG)
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  CDDUART_SYNCRECEIVE_ID,
                                  CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            if (NULL_PTR == Buffer)
            {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                      (uint8)0,
                                      CDDUART_SYNCRECEIVE_ID,
                                      CDDUART_E_INVALID_POINTER);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
                if (0U == BufferSize)
                {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                    (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                          (uint8)0,
                                          CDDUART_SYNCRECEIVE_ID,
                                          CDDUART_E_INVALID_PARAMETER);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
                }
                else
                {
                    TempReturn = CddUart_StartSyncReceive(CoreId, Channel, Buffer, BufferSize, Timeout);
                }
            }
        }
    }
    return TempReturn;
}
/* implements     CddUart_AsyncReceive_Activity*/
CDDUART_FUNC Std_ReturnType CddUart_AsyncReceive(uint8 Channel, uint8 * Buffer, uint32 BufferSize)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    uint8 CoreId;
    /* Get core ID of current processor */
    CoreId = (uint8) CddUart_GetCoreID();
    if (CDDUART_DRV_UNINIT == CddUart_au8DriverStatus[CoreId])
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              CDDUART_ASYNCRECEIVE_ID,
                              CDDUART_E_UNINIT);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if (Channel >= CDDUART_CH_MAX_CONFIG)
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  CDDUART_ASYNCRECEIVE_ID,
                                  CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            if (NULL_PTR == Buffer)
            {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                      (uint8)0,
                                      CDDUART_ASYNCRECEIVE_ID,
                                      CDDUART_E_INVALID_POINTER);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
                if (0U == BufferSize)
                {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                    (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                          (uint8)0,
                                          CDDUART_ASYNCRECEIVE_ID,
                                          CDDUART_E_INVALID_PARAMETER);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
                }
                else
                {
                    TempReturn = CddUart_StartAsyncReceive(CoreId, Channel, Buffer, BufferSize);
                }
            }
        }
    }
    return TempReturn;
}
/* implements     CddUart_AsyncSend_Activity*/
CDDUART_FUNC Std_ReturnType CddUart_AsyncSend(uint8 Channel, uint8 * Buffer, uint32 BufferSize)
{
    Std_ReturnType TempReturn = E_NOT_OK;
    uint8 CoreId;
    /* Get core ID of current processor */
    CoreId = (uint8) CddUart_GetCoreID();
    if (CDDUART_DRV_UNINIT == CddUart_au8DriverStatus[CoreId])
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              CDDUART_ASYNCSEND_ID,
                              CDDUART_E_UNINIT);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if (Channel >= CDDUART_CH_MAX_CONFIG)
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  CDDUART_ASYNCSEND_ID,
                                  CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            if (NULL_PTR == Buffer)
            {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                      (uint8)0,
                                      CDDUART_ASYNCSEND_ID,
                                      CDDUART_E_INVALID_POINTER);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
                if (0U == BufferSize)
                {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                    (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                          (uint8)0,
                                          CDDUART_ASYNCSEND_ID,
                                          CDDUART_E_INVALID_PARAMETER);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
                }
                else
                {
                    TempReturn = CddUart_StartAsyncSend(CoreId, Channel, Buffer, BufferSize);
                }
            }
        }
    }
    return TempReturn;
}
/* implements     CddUart_GetStatus_Activity*/
CDDUART_FUNC CddUart_StatusType CddUart_GetStatus(uint8 Channel, uint32 * BytesTransferred, CddUart_DataDirectionType TransferType)
{
    CddUart_StatusType TempReturn;
    uint8 CoreId;
    TempReturn = CDDUART_STATUS_RX_OVERRUN_ERROR;
    /* Get core ID of current processor */
    CoreId = (uint8) CddUart_GetCoreID();
    if (CDDUART_DRV_UNINIT == CddUart_au8DriverStatus[CoreId])
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                              (uint8)0,
                              CDDUART_GETSTATUS_ID,
                              CDDUART_E_UNINIT);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        if (Channel >= CDDUART_CH_MAX_CONFIG)
        {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                  (uint8)0,
                                  CDDUART_GETSTATUS_ID,
                                  CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
        }
        else
        {
            if (NULL_PTR == BytesTransferred)
            {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                      (uint8)0,
                                      CDDUART_GETSTATUS_ID,
                                      CDDUART_E_INVALID_POINTER);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
            }
            else
            {
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
                if (CoreId != CddUart_apConfig[CoreId]->PartitionCoreId)
                {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                    /* Invalid CoreId */
                    (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                          (uint8)0,
                                          (uint8)CDDUART_GETSTATUS_ID,
                                          (uint8)CDDUART_E_PARAM_CONFIG);
#endif /* (CDDUART_DEV_ERROR_DETECT == STD_ON) */
                }
                else
                {
                    if (NULL_PTR == CddUart_apConfig[CoreId]->Configs[Channel])
                    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
                        (void)Det_ReportError((uint16)CDDUART_MODULE_ID,
                                              (uint8)0,
                                              (uint8)CDDUART_GETSTATUS_ID,
                                              (uint8)CDDUART_E_INVALID_CHANNEL);
#endif /* (CDDUART_DEV_ERROR_DETECT     == STD_ON) */
                    }
                    else
                    {
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
                        if (CDDUART_SEND == TransferType)
                        {
                            TempReturn = CddUart_Mld_GetTransmitStatus(Channel, BytesTransferred);
                        }
                        else
                        {
                            TempReturn = CddUart_Mld_GetReceiveStatus(Channel, BytesTransferred);
                        }
                        (void)CoreId;
#if (CDDUART_MULTICORE_SUPPORT == STD_ON)
                    }
                }
#endif /* (CDDUART_MULTICORE_SUPPORT == STD_ON) */
            }
        }
    }
    return TempReturn;
}
#if (CDDUART_VERSION_INFO_API == STD_ON)
/* implements     CddUart_GetVersionInfo_Activity*/
CDDUART_FUNC void CddUart_GetVersionInfo(Std_VersionInfoType * VersionInfo)
{
    if (NULL_PTR == VersionInfo)
    {
#if (CDDUART_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)CDDUART_MODULE_ID, \
                              (uint8)0, \
                              CDDUART_VERSIONINFO_ID, \
                              CDDUART_E_INVALID_POINTER \
                             );
#endif /* CDDUART_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        VersionInfo->vendorID = (uint16) CDDUART_VENDOR_ID;
        VersionInfo->moduleID = (uint8) CDDUART_MODULE_ID;
        VersionInfo->sw_major_version = (uint8) CDDUART_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8) CDDUART_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8) CDDUART_SW_PATCH_VERSION;
    }
}
#endif /* (CDDUART_VERSION_INFO_API == STD_ON) */
#define CDDUART_STOP_SEC_CODE
#include "CddUart_MemMap.h"
#ifdef __cplusplus
}
#endif

