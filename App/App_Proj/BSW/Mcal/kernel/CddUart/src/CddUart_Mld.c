/**
*   @file    CddUart_Mld.c
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
 * PRQA S 3408 Rule-8.4:   A compatible declaration shall be visible when an object or function with external linkage is defined.
 */
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
#include "CddUart_Lld_Uart.h"
#else
#include "CddUart_Lld_LinFlexD.h"
#endif
#include "CddUart_Mld.h"
#if ((CDDUART_DEV_ERROR_DETECT == STD_ON) || (CDDUART_RUNTIME_ERROR_DETECT ==STD_ON))
#include "Det.h"
#endif
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
#include "OsIf.h"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
#define CDDUART_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CddUart_MemMap.h"
CDDUART_VAR static sint8 CddUart_Mld_HwMapping[CDDUART_NUMBER_OF_INSTANCES];
#define CDDUART_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CddUart_MemMap.h"
/*
* MR12 Dir-4.4 VIOLATION: A compatible declaration shall be visible when an object or function with external linkage is defined.
* CddUart_Mld_apChnConfig will be initialized before used and will not cause harm.
*/
#define CDDUART_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CddUart_MemMap.h"
CDDUART_VAR const CddUart_Mld_HwConfigType *CddUart_Mld_apChnConfig[CDDUART_CH_MAX_CONFIG];/* PRQA S 3408*/
#define CDDUART_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CddUart_MemMap.h"
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define CDDUART_START_SEC_CODE
#include "CddUart_MemMap.h"
/* implements CddUart_Mld_Init Activity*/
CDDUART_FUNC void CddUart_Mld_Init(uint8 Channel, uint32 UartClock, const CddUart_Mld_HwConfigType *Config)
{
    uint8 HwUnit = Config->UartHwChannel;
    for (uint8 Index = 0; Index < CDDUART_NUMBER_OF_INSTANCES; ++Index)
    {
        CddUart_Mld_HwMapping[Index] = -1;
    }
    /* Save the channel settings */
    CddUart_Mld_apChnConfig[Channel] = Config;
    /* Call the LLD Initialization function */
    if (LINFLEX_IP == CddUart_Mld_apChnConfig[Channel]->UartIpType)
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
        CddUart_Mld_HwMapping[HwUnit] = (sint8)Channel;
#if (!defined(CPU_YTM32B1MC0) && !defined(CPU_YTM32B1MD2))
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        (void)OsIf_Trusted_Call_Return3param(LinFlexD_Lld_Init, HwUnit, UartClock, Config->UserConfig->UserConfigOfUartHard);
#else
        (void)LinFlexD_Lld_Init(HwUnit, UartClock, Config->UserConfig->UserConfigOfUartHard);
#endif
#endif
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
        CddUart_Mld_HwMapping[HwUnit] = (sint8)Channel;
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        (void)OsIf_Trusted_Call_Return3param(UART_Lld_Init, HwUnit, UartClock, Config->UserConfig->UserConfigOfUartHard);
#else
        (void)UART_Lld_Init(HwUnit, UartClock, Config->UserConfig->UserConfigOfUartHard);
#endif
#endif
        /*GCOVR_EXCL_STOP*/
    }
}

/* implements CddUart_Mld_DeInit Activity*/
CDDUART_FUNC void CddUart_Mld_Deinit(uint8 Channel)
{
    uint8 HwUnit = CddUart_Mld_apChnConfig[Channel]->UartHwChannel;
    if (LINFLEX_IP == CddUart_Mld_apChnConfig[Channel]->UartIpType)
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
        /* Remove the current hw to logic mapping */
        CddUart_Mld_HwMapping[HwUnit] = -1;
#if (!defined(CPU_YTM32B1MC0) && !defined(CPU_YTM32B1MD2))
        (void)LinFlexD_Lld_Deinit(HwUnit);
#endif
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
        CddUart_Mld_HwMapping[HwUnit] = -1;
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        (void)OsIf_Trusted_Call_Return1param(UART_Lld_Deinit, HwUnit);
#else
        (void)UART_Lld_Deinit(HwUnit);
#endif
#endif
        /*GCOVR_EXCL_STOP*/
    }
    /* Remove refference to the current channel configuration */
    CddUart_Mld_apChnConfig[Channel] = NULL_PTR;
}

/* implements CddUart_Mld_SetBaudrate Activity*/
CDDUART_FUNC Std_ReturnType CddUart_Mld_SetBaudrate(uint8 Channel, uint32 BaudRateValue, uint32 ClockFrequency)
{
    Std_ReturnType TempStatus = E_NOT_OK;
    uint8 HwUnit = CddUart_Mld_apChnConfig[Channel]->UartHwChannel;
    if (LINFLEX_IP == CddUart_Mld_apChnConfig[Channel]->UartIpType)
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (!defined(CPU_YTM32B1MC0) && !defined(CPU_YTM32B1MD2))
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        if (CDDUART_STATUS_NO_ERROR == OsIf_Trusted_Call_Return3param(LinFlexD_Lld_SetBaudRate, HwUnit, ClockFrequency, BaudRateValue))
#else
        if (CDDUART_STATUS_NO_ERROR == LinFlexD_Lld_SetBaudRate(HwUnit, ClockFrequency, BaudRateValue))
#endif
        {
            TempStatus = E_OK;
        }
#endif
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        if (CDDUART_STATUS_NO_ERROR == OsIf_Trusted_Call_Return3param(UART_Lld_SetBaudRate, HwUnit, ClockFrequency, BaudRateValue))
#else
        if (CDDUART_STATUS_NO_ERROR == UART_Lld_SetBaudRate(HwUnit, ClockFrequency, BaudRateValue))
#endif
        {
            TempStatus = E_OK;
        }
#endif
        /*GCOVR_EXCL_STOP*/
    }
    return TempStatus;
}

/* implements CddUart_Mld_GetBaudrate Activity*/
CDDUART_FUNC void CddUart_Mld_GetBaudrate(uint8 Channel, uint32 *BaudrateValue)
{
    uint8 HwUnit = CddUart_Mld_apChnConfig[Channel]->UartHwChannel;
    if (LINFLEX_IP == CddUart_Mld_apChnConfig[Channel]->UartIpType)
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (!defined(CPU_YTM32B1MC0) && !defined(CPU_YTM32B1MD2))
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        (void)OsIf_Trusted_Call_Return2param(LinFlexD_Lld_GetBaudRate, HwUnit, BaudrateValue);
#else
        (void)LinFlexD_Lld_GetBaudRate(HwUnit, BaudrateValue);
#endif
#endif
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        (void)OsIf_Trusted_Call_Return2param(UART_Lld_GetBaudRate, HwUnit, BaudrateValue);
#else
        (void)UART_Lld_GetBaudRate(HwUnit, BaudrateValue);
#endif
#endif
        /*GCOVR_EXCL_STOP*/
    }
}

/* implements CddUart_Mld_AbortSendingData Activity*/
CDDUART_FUNC Std_ReturnType CddUart_Mld_AbortSendingData(uint8 Channel)
{
    Std_ReturnType TempStatus = (uint8)E_NOT_OK;
    uint8 HwUnit = CddUart_Mld_apChnConfig[Channel]->UartHwChannel;
    if (LINFLEX_IP == CddUart_Mld_apChnConfig[Channel]->UartIpType)
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (!defined(CPU_YTM32B1MC0) && !defined(CPU_YTM32B1MD2))
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        if (CDDUART_STATUS_NO_ERROR == OsIf_Trusted_Call_Return1param(LinFlexD_Lld_AbortSendingData, HwUnit))
#else
        if (CDDUART_STATUS_NO_ERROR == LinFlexD_Lld_AbortSendingData(HwUnit))
#endif
        {
            TempStatus = (uint8)E_OK;
        }
#endif
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        if (CDDUART_STATUS_NO_ERROR == OsIf_Trusted_Call_Return1param(UART_Lld_AbortSendingData, HwUnit))
#else
        if (CDDUART_STATUS_NO_ERROR == UART_Lld_AbortSendingData(HwUnit))
#endif
        {
            TempStatus = (uint8)E_OK;
        }
#endif
        /*GCOVR_EXCL_STOP*/
    }
    return TempStatus;
}

/* implements CddUart_Mld_AbortReceivingData Activity*/
CDDUART_FUNC Std_ReturnType CddUart_Mld_AbortReceivingData(uint8 Channel)
{
    Std_ReturnType TempStatus = (uint8)E_NOT_OK;
    uint8 HwUnit = CddUart_Mld_apChnConfig[Channel]->UartHwChannel;
    if (LINFLEX_IP == CddUart_Mld_apChnConfig[Channel]->UartIpType)
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (!defined(CPU_YTM32B1MC0) && !defined(CPU_YTM32B1MD2))
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        if (CDDUART_STATUS_NO_ERROR == OsIf_Trusted_Call_Return1param(LinFlexD_Lld_AbortReceivingData, HwUnit))
#else
        if (CDDUART_STATUS_NO_ERROR == LinFlexD_Lld_AbortReceivingData(HwUnit))
#endif
        {
            TempStatus = (uint8)E_OK;
        }
#endif
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        if (CDDUART_STATUS_NO_ERROR == OsIf_Trusted_Call_Return1param(UART_Lld_AbortReceivingData, HwUnit))
#else
        if (CDDUART_STATUS_NO_ERROR == UART_Lld_AbortReceivingData(HwUnit))
#endif
        {
            TempStatus = (uint8)E_OK;
        }
#endif
        /*GCOVR_EXCL_STOP*/
    }
    return TempStatus;
}

/* implements CddUart_Mld_SetTxBuffer Activity*/
CDDUART_FUNC void CddUart_Mld_SetTxBuffer(uint8 Channel, uint8 *Buffer, uint32 BufferSize)
{
    uint8 HwUnit = CddUart_Mld_apChnConfig[Channel]->UartHwChannel;
    if (LINFLEX_IP == CddUart_Mld_apChnConfig[Channel]->UartIpType)
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (!defined(CPU_YTM32B1MC0) && !defined(CPU_YTM32B1MD2))
        (void)LinFlexD_Lld_SetTxBuffer(HwUnit, Buffer, BufferSize);
#endif
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
        (void)UART_Lld_SetTxBuffer(HwUnit, Buffer, BufferSize);
#endif
        /*GCOVR_EXCL_STOP*/
    }
}

/* implements CddUart_Mld_SetCallBack Activity*/
CDDUART_FUNC void CddUart_Mld_SetCallBack(uint8 Channel, CddUart_General_CallbackType CallBackFunction)
{
    uint8 HwUnit = CddUart_Mld_apChnConfig[Channel]->UartHwChannel;
    if (LINFLEX_IP == CddUart_Mld_apChnConfig[Channel]->UartIpType)
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (!defined(CPU_YTM32B1MC0) && !defined(CPU_YTM32B1MD2))
        (void)LinFlexD_Lld_SetCallback(HwUnit, CallBackFunction);
#endif
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
        (void)UART_Lld_SetCallback(HwUnit, CallBackFunction);
#endif
        /*GCOVR_EXCL_STOP*/
    }
}

/* implements CddUart_Mld_SetRxBuffer Activity*/
CDDUART_FUNC void CddUart_Mld_SetRxBuffer(uint8 Channel, uint8 *Buffer, uint32 BufferSize)
{
    uint8 HwUnit = CddUart_Mld_apChnConfig[Channel]->UartHwChannel;
    if (LINFLEX_IP == CddUart_Mld_apChnConfig[Channel]->UartIpType)
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (!defined(CPU_YTM32B1MC0) && !defined(CPU_YTM32B1MD2))
        (void)LinFlexD_Lld_SetRxBuffer(HwUnit, Buffer, BufferSize);
#endif
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
        (void)UART_Lld_SetRxBuffer(HwUnit, Buffer, BufferSize);
#endif
        /*GCOVR_EXCL_STOP*/
    }
}

/* implements CddUart_Mld_SyncSend Activity*/
CDDUART_FUNC Std_ReturnType CddUart_Mld_SyncSend(uint8 Channel, uint8 *Buffer, uint32 BufferSize, uint32 Timeout)
{
    Std_ReturnType TempStatus = (uint8)E_NOT_OK;
    uint8 HwUnit = CddUart_Mld_apChnConfig[Channel]->UartHwChannel;
    /* LPUART is used */
    if (LINFLEX_IP == CddUart_Mld_apChnConfig[Channel]->UartIpType)
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (!defined(CPU_YTM32B1MC0) && !defined(CPU_YTM32B1MD2))
        CddUart_StatusType FlexdUartIpStatus;
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        FlexdUartIpStatus = (CddUart_StatusType)OsIf_Trusted_Call_Return4param(LinFlexD_Lld_SendDataBlocking, HwUnit, Buffer, BufferSize, Timeout);
#else
        FlexdUartIpStatus = LinFlexD_Lld_SendDataBlocking(HwUnit, Buffer, BufferSize, Timeout);
#endif
        if (CDDUART_STATUS_NO_ERROR == FlexdUartIpStatus)
        {
            TempStatus = (uint8)E_OK;
        }
        else if (CDDUART_STATUS_TIMEOUT == FlexdUartIpStatus)
        {
            TempStatus = (uint8)CDDUART_STATUS_TIMEOUT;
        }
        else
        {
            TempStatus = (uint8)E_NOT_OK;
        }
#endif
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
        CddUart_StatusType TempUartIpStatus;
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        TempUartIpStatus = (CddUart_StatusType)OsIf_Trusted_Call_Return4param(UART_Lld_SendDataBlocking, HwUnit, Buffer, BufferSize, Timeout);
#else
        TempUartIpStatus = UART_Lld_SendDataBlocking(HwUnit, Buffer, BufferSize, Timeout);
#endif
        if (CDDUART_STATUS_NO_ERROR == TempUartIpStatus)
        {
            TempStatus = (uint8)E_OK;
        }
        else if (CDDUART_STATUS_TIMEOUT == TempUartIpStatus)
        {
            TempStatus = (uint8)CDDUART_STATUS_TIMEOUT;
        }
        else
        {
            TempStatus = (uint8)E_NOT_OK;
        }
#endif
        /*GCOVR_EXCL_STOP*/
    }
    return TempStatus;
}

/* implements CddUart_Mld_SyncReceive Activity*/
CDDUART_FUNC Std_ReturnType CddUart_Mld_SyncReceive(uint8 Channel, uint8 *Buffer, uint32 BufferSize, uint32 Timeout)
{
    Std_ReturnType TempStatus = (uint8)E_NOT_OK;
    uint8 HwUnit = CddUart_Mld_apChnConfig[Channel]->UartHwChannel;
    if (LINFLEX_IP == CddUart_Mld_apChnConfig[Channel]->UartIpType)
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (!defined(CPU_YTM32B1MC0) && !defined(CPU_YTM32B1MD2))
        CddUart_StatusType FlexdUartIpStatus;
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        FlexdUartIpStatus = (CddUart_StatusType)OsIf_Trusted_Call_Return4param(LinFlexD_Lld_ReceiveDataBlocking, HwUnit, Buffer, BufferSize, Timeout);
#else
        FlexdUartIpStatus = LinFlexD_Lld_ReceiveDataBlocking(HwUnit, Buffer, BufferSize, Timeout);
#endif
        if (CDDUART_STATUS_NO_ERROR == FlexdUartIpStatus)
        {
            TempStatus = (uint8)E_OK;
        }
        else if (CDDUART_STATUS_TIMEOUT == FlexdUartIpStatus)
        {
            TempStatus = (uint8)CDDUART_STATUS_TIMEOUT;
        }
        else
        {
            TempStatus = (uint8)E_NOT_OK;
        }
#endif
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
        CddUart_StatusType TempUartIpStatus;
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        TempUartIpStatus = (CddUart_StatusType)OsIf_Trusted_Call_Return4param(UART_Lld_ReceiveDataBlocking, HwUnit, Buffer, BufferSize, Timeout);
#else
        TempUartIpStatus = UART_Lld_ReceiveDataBlocking(HwUnit, Buffer, BufferSize, Timeout);
#endif
        if (CDDUART_STATUS_NO_ERROR == TempUartIpStatus)
        {
            TempStatus = (uint8)E_OK;
        }
        else if (CDDUART_STATUS_TIMEOUT == TempUartIpStatus)
        {
            TempStatus = (uint8)CDDUART_STATUS_TIMEOUT;
        }
        else
        {
            TempStatus = (uint8)E_NOT_OK;
        }
#endif
        /*GCOVR_EXCL_STOP*/
    }
    return TempStatus;
}

/* implements CddUart_Mld_AsyncReceive Activity*/
CDDUART_FUNC Std_ReturnType CddUart_Mld_AsyncReceive(uint8 Channel, uint8 *Buffer, uint32 BufferSize)
{
    Std_ReturnType TempStatus = (uint8)E_NOT_OK;
    uint8 HwUnit = CddUart_Mld_apChnConfig[Channel]->UartHwChannel;
    if (LINFLEX_IP == CddUart_Mld_apChnConfig[Channel]->UartIpType)
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (!defined(CPU_YTM32B1MC0) && !defined(CPU_YTM32B1MD2))
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        if (CDDUART_STATUS_NO_ERROR == OsIf_Trusted_Call_Return3param(LinFlexD_Lld_ReceiveData, HwUnit, Buffer, BufferSize))
#else
        if (CDDUART_STATUS_NO_ERROR == LinFlexD_Lld_ReceiveData(HwUnit, Buffer, BufferSize))
#endif
        {
            TempStatus = (uint8)E_OK;
        }
#endif
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        if (CDDUART_STATUS_NO_ERROR == OsIf_Trusted_Call_Return3param(UART_Lld_ReceiveData, HwUnit, Buffer, BufferSize))
#else
        if (CDDUART_STATUS_NO_ERROR == UART_Lld_ReceiveData(HwUnit, Buffer, BufferSize))
#endif
        {
            TempStatus = (uint8)E_OK;
        }
#endif
        /*GCOVR_EXCL_STOP*/
    }
    return TempStatus;
}

/* implements CddUart_Mld_AsyncSend Activity*/
CDDUART_FUNC Std_ReturnType CddUart_Mld_AsyncSend(uint8 Channel, uint8 *Buffer, uint32 BufferSize)
{
    Std_ReturnType TempStatus = (uint8)E_NOT_OK;
    uint8 HwUnit = CddUart_Mld_apChnConfig[Channel]->UartHwChannel;
    if (LINFLEX_IP == CddUart_Mld_apChnConfig[Channel]->UartIpType)
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (!defined(CPU_YTM32B1MC0) && !defined(CPU_YTM32B1MD2))
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        if (CDDUART_STATUS_NO_ERROR == OsIf_Trusted_Call_Return3param(LinFlexD_Lld_SendData, HwUnit, Buffer, BufferSize))
#else
        if (CDDUART_STATUS_NO_ERROR == LinFlexD_Lld_SendData(HwUnit, Buffer, BufferSize))
#endif
        {
            TempStatus = (uint8)E_OK;
        }
#endif
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
#ifdef CDDUART_ENABLE_USER_MODE_SUPPORT
        if (CDDUART_STATUS_NO_ERROR == OsIf_Trusted_Call_Return3param(UART_Lld_SendData, HwUnit, Buffer, BufferSize))
#else
        if (CDDUART_STATUS_NO_ERROR == UART_Lld_SendData(HwUnit, Buffer, BufferSize))
#endif
        {
            TempStatus = (uint8)E_OK;
        }
#endif
        /*GCOVR_EXCL_STOP*/
    }
    return TempStatus;
}

CDDUART_FUNC void CddUart_Mld_SetTransmitStatus(uint8 Channel, CddUart_StatusType Status)
{
    uint8 HwUnit = CddUart_Mld_apChnConfig[Channel]->UartHwChannel;
    if (LINFLEX_IP == CddUart_Mld_apChnConfig[Channel]->UartIpType)
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (!defined(CPU_YTM32B1MC0) && !defined(CPU_YTM32B1MD2))
        LinFlexD_Lld_SetTransmitStatus(HwUnit, Status);
#endif
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
        UART_Lld_SetTransmitStatus(HwUnit, Status);
#endif
        /*GCOVR_EXCL_STOP*/
    }
}

/* implements CddUart_Mld_GetTransmitStatus Activity*/
CDDUART_FUNC CddUart_StatusType CddUart_Mld_GetTransmitStatus(uint8 Channel, uint32 *BytesRemaining)
{
    CddUart_StatusType TempStatus = CDDUART_STATUS_TIMEOUT;
    uint8 HwUnit = CddUart_Mld_apChnConfig[Channel]->UartHwChannel;
    if (LINFLEX_IP == CddUart_Mld_apChnConfig[Channel]->UartIpType)
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (!defined(CPU_YTM32B1MC0) && !defined(CPU_YTM32B1MD2))
        TempStatus = LinFlexD_Lld_GetTransmitStatus(HwUnit, BytesRemaining);
#endif
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
        TempStatus = UART_Lld_GetTransmitStatus(HwUnit, BytesRemaining);
#endif
        /*GCOVR_EXCL_STOP*/
    }
    return TempStatus;
}

CDDUART_FUNC void CddUart_Mld_SetReceiveStatus(uint8 Channel, CddUart_StatusType Status)
{
    uint8 HwUnit = CddUart_Mld_apChnConfig[Channel]->UartHwChannel;
    if (LINFLEX_IP == CddUart_Mld_apChnConfig[Channel]->UartIpType)
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (!defined(CPU_YTM32B1MC0) && !defined(CPU_YTM32B1MD2))
        LinFlexD_Lld_SetReceiveStatus(HwUnit, Status);
#endif
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
        UART_Lld_SetReceiveStatus(HwUnit, Status);
#endif
        /*GCOVR_EXCL_STOP*/
    }
}

/* implements CddUart_Mld_GetReceiveStatus Activity*/
CDDUART_FUNC CddUart_StatusType CddUart_Mld_GetReceiveStatus(uint8 Channel, uint32 *BytesRemaining)
{
    CddUart_StatusType TempStatus = CDDUART_STATUS_TIMEOUT;
    uint8 HwUnit = CddUart_Mld_apChnConfig[Channel]->UartHwChannel;
    if (LINFLEX_IP == CddUart_Mld_apChnConfig[Channel]->UartIpType)
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (!defined(CPU_YTM32B1MC0) && !defined(CPU_YTM32B1MD2))
        TempStatus = LinFlexD_Lld_GetReceiveStatus(HwUnit, BytesRemaining);
#endif
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Two MCUs, incompatible*/
#if (defined (CPU_YTM32B1MC0) || defined (CPU_YTM32B1MD2))
        TempStatus = UART_Lld_GetReceiveStatus(HwUnit, BytesRemaining);
#endif
        /*GCOVR_EXCL_STOP*/
    }
    return TempStatus;
}

#define CDDUART_STOP_SEC_CODE
#include "CddUart_MemMap.h"

#ifdef __cplusplus
}
#endif

