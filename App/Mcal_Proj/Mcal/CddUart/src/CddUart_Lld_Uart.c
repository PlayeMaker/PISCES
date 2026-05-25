/*
*   @file    CddUart_Lld_Uart.c
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
#include "Mcal.h"
#include "CddUart_Lld_Uart.h"
#include "SchM_CddUart.h"
#if (STD_ON == CDDUART_DMA_USED)
#include "CddDma.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDDUART_VENDOR_ID_LLD_UART_C                           (180)
#define CDDUART_AR_RELEASE_MAJOR_VERSION_LLD_UART_C            (4)
#define CDDUART_AR_RELEASE_MINOR_VERSION_LLD_UART_C            (4)
#define CDDUART_AR_RELEASE_REVISION_VERSION_LLD_UART_C         (0)
#define CDDUART_SW_MAJOR_VERSION_LLD_UART_C                    (0)
#define CDDUART_SW_MINOR_VERSION_LLD_UART_C                    (9)
#define CDDUART_SW_PATCH_VERSION_LLD_UART_C                    (1)
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CddUart header file are of the same Autosar version */
#if (CDDUART_VENDOR_ID_LLD_UART_C != CDDUART_VENDOR_ID_UART_CFG)
#error "CddUart_Lld_Uart.c and CddUart_Lld_UartCfg.h have different vendor ids"
#endif

/* Check if source file and CddUart header file are of the same Autosar version */
#if ((CDDUART_AR_RELEASE_MAJOR_VERSION_LLD_UART_C != CDDUART_AR_RELEASE_MAJOR_VERSION_UART_CFG) || \
     (CDDUART_AR_RELEASE_MINOR_VERSION_LLD_UART_C != CDDUART_AR_RELEASE_MINOR_VERSION_UART_CFG) || \
     (CDDUART_AR_RELEASE_REVISION_VERSION_LLD_UART_C != CDDUART_AR_RELEASE_REVISION_VERSION_UART_CFG) \
    )
#error "AutoSar Version Numbers of CddUart_Lld_Uart.c  and CddUart_Lld_UartCfg.h are different"
#endif

/* Check if source file and CddUart header file are of the same Software version */
#if ((CDDUART_SW_MAJOR_VERSION_LLD_UART_C != CDDUART_SW_MAJOR_VERSION_UART_CFG) || \
     (CDDUART_SW_MINOR_VERSION_LLD_UART_C != CDDUART_SW_MINOR_VERSION_UART_CFG) || \
     (CDDUART_SW_PATCH_VERSION_LLD_UART_C != CDDUART_SW_PATCH_VERSION_UART_CFG) \
    )
#error "Software Version Numbers of CddUart_Lld_Uart.c  and CddUart_Lld_UartCfg.h are different"
#endif
/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#define CDDUART_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CddUart_MemMap.h"
/* Array of pointers to UART driver runtime state structures */
CDDUART_VAR static Uart_UartStateType Uart_UartStatePtr[CDDUART_UART_INSTANCE_COUNT];
CDDUART_VAR static uint32 Uart_ClockFrequency[CDDUART_UART_INSTANCE_COUNT];
#define CDDUART_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CddUart_MemMap.h"

#define CDDUART_START_SEC_CONST_UNSPECIFIED
#include "CddUart_MemMap.h"
/*! @brief Table of Base addresses for LINFlexD instances. */
CDDUART_CONST static UART_Type *const Uart_UartBase[CDDUART_UART_INSTANCE_COUNT] = UART_BASE_PTRS;
#define CDDUART_STOP_SEC_CONST_UNSPECIFIED
#include "CddUart_MemMap.h"

/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/
#if (CDDUART_DMA_USED == STD_ON)
extern const CddDma_TransferConfigType *DmaChannelTransferConfigArray[CDDDMA_CHANNEL_CONFIG_COUNT];
#endif

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void UART_Lld_ClearErrorFlags(UART_Type *Base);
static CddUart_StatusType UART_Lld_StartSendDataUsingInt(uint32 Instance, uint8 *TxBuff, uint32 TxSize);
static void UART_Lld_CompleteSendDataUsingInt(uint32 Instance);
static CddUart_StatusType UART_Lld_StartReceiveDataUsingInt(uint32 Instance, uint8 *RxBuff, uint32 RxSize);
static void UART_Lld_CompleteReceiveDataUsingInt(uint32 Instance);
#if (STD_ON == CDDUART_DMA_USED)
static void UART_Lld_DmaTxInit(uint32 Instance);
static void UART_Lld_DmaRxInit(uint32 Instance);
static void UART_Lld_StopTxDma(uint32 Instance);
static void UART_Lld_StopRxDma(uint32 Instance);
static CddUart_StatusType UART_Lld_StartSendDataUsingDma(uint32 Instance, uint8 *TxBuff, uint32 TxSize);
static void UART_Lld_TxDmaComplete(uint32 Instance);
static CddUart_StatusType UART_Lld_StartReceiveDataUsingDma(uint32 Instance, uint8 *RxBuff, uint32 RxSize);
static void UART_Lld_RxDmaComplete(uint32 Instance);
static void UART_Lld_DmaTxError(uint32 Instance);
static void UART_Lld_DmaRxError(uint32 Instance);
#endif
static void UART_Lld_PutData(uint32 Instance);
static void UART_Lld_GetData(uint32 Instance);
void UART_Lld_RxIrqHandler(uint8 Instance);
void UART_Lld_IdleLineIrqHandler(uint8 Instance);
void UART_Lld_TxEmptyIrqHandler(uint8 Instance);
void UART_Lld_TxCompleteIrqHandler(uint8 Instance);
void UART_Lld_ErrIrqHandler(uint8 Instance);
static void UART_Lld_SetErrorInterrupts(uint32 Instance, boolean Enable);

/*==================================================================================================
*                                    LOCAL FUNCTION
==================================================================================================*/
#define CDDUART_START_SEC_CODE
#include "CddUart_MemMap.h"

/*!
 * @brief  Reset tx fifo
 *
 * This function resets tx fifo
 *
 * @param[in] Base UART base pointer
 */
CDDUART_FUNC static inline void UART_ResetTxFifo(UART_Type *Base)
{
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_10();
    Base->TXFIFO = UART_TXFIFO_RESET_MASK;
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_10();
}

/*!
 * @brief  Set tx fifo watermark
 *
 * This function sets tx fifo watermark
 *
 * @param[in] Base UART base pointer
 * @param[in] WatermarkValue Watermark value
 */
CDDUART_FUNC static inline void UART_SetTxFifoWatermark(UART_Type *Base, uint32 WatermarkValue)
{
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_11();
    Base->TXFIFO &= ~UART_TXFIFO_WATER_MASK;
    Base->TXFIFO |= UART_TXFIFO_WATER(WatermarkValue);
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_11();
}

/*!
 * @brief  Enable tx fifo
 *
 * This function Enable tx fifo
 *
 * @param[in] Base UART base pointer
 * @param[in] Enable Enable or Disable tx fifo
 */
CDDUART_FUNC static inline void UART_EnableTxFifo(UART_Type *Base, boolean Enable)
{
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_12();
    if (Enable)
    {
        Base->TXFIFO |= UART_TXFIFO_EN(1);
    }
    else
    {
        Base->TXFIFO &= ~UART_TXFIFO_EN_MASK;
    }
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_12();
}

#if (STD_ON == CDDUART_DMA_USED)
/*!
 * @brief Configures DMA requests.
 *
 * This function configures DMA requests for UART Transmitter.
 *
 *
 * @param[in] Base UART base pointer
 * @param[in] Enable Transmit DMA request configuration (enable:1 /disable: 0)
 */
CDDUART_FUNC static inline void UART_SetTxDmaCmd(UART_Type *Base, boolean Enable)
{
    uint32 TempReg;
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_13();
    TempReg = Base->CTRL0;
    TempReg &= ~UART_CTRL0_TXDMAEN_MASK;
    TempReg |= UART_CTRL0_TXDMAEN(Enable);
    Base->CTRL0 = TempReg;
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_13();
}

/*!
 * @brief Configures DMA requests.
 *
 * This function configures DMA requests for UART Receiver.
 *
 *
 * @param[in] Base UART base pointer
 * @param[in] Enable Receive DMA request configuration (enable: 1/disable: 0)
 */
CDDUART_FUNC static inline void UART_SetRxDmaCmd(UART_Type *Base, boolean Enable)
{
    uint32 TempReg;
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_14();
    TempReg = Base->CTRL0;
    TempReg &= ~UART_CTRL0_RXDMAEN_MASK;
    TempReg |= UART_CTRL0_RXDMAEN(Enable);
    Base->CTRL0 = TempReg;
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_14();
}
#endif

/*!
 * @brief  Reset rx fifo
 *
 * This function resets rx fifo
 *
 * @param[in] Base UART base pointer
 */
CDDUART_FUNC static inline void UART_ResetRxFifo(UART_Type *Base)
{
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_15();
    Base->RXFIFO = UART_RXFIFO_RESET_MASK;
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_15();
}

/*!
 * @brief  Set rx fifo watermark
 *
 * This function sets rx fifo watermark
 *
 * @param[in] Base UART base pointer
 * @param[in] WatermarkValue Watermark value
 */
CDDUART_FUNC static inline void UART_SetRxFifoWatermark(UART_Type *Base, uint32 WatermarkValue)
{
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_16();
    Base->RXFIFO &= ~UART_RXFIFO_WATER_MASK;
    Base->RXFIFO |= UART_RXFIFO_WATER(WatermarkValue);
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_16();
}

/*!
 * @brief  Enable rx fifo
 *
 * This function Enable rx fifo
 *
 * @param[in] Base UART base pointer
 * @param[in] Enable Enable or Disable rx fifo
 */
CDDUART_FUNC static inline void UART_EnableRxFifo(UART_Type *Base, boolean Enable)
{
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_17();
    if (Enable)
    {
        Base->RXFIFO |= UART_RXFIFO_EN(1);
    }
    else
    {
        Base->RXFIFO &= ~UART_RXFIFO_EN_MASK;
    }
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_17();
}

/*!
* @brief  Clears the error flags treated by the driver
*
* This function clears the error flags treated by the driver.
*
* @param[in] Base UART Base pointer
*/
CDDUART_FUNC static inline void UART_Lld_ClearErrorFlags(UART_Type *Base)
{
    uint32 Mask = UART_INTF_OVRIF_MASK | \
                  UART_INTF_NOZIF_MASK | \
                  UART_INTF_FEIF_MASK  | \
                  UART_INTF_PARIF_MASK;
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_00();
    Base->INTF = Mask;
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_00();
}

/*!
* @brief  This function clears the idle flag.
* @param[in] Base UART Base pointer
*/
CDDUART_FUNC static inline void UART_Lld_ClearIdleFlag(UART_Type *Base)
{
    Base->INTF = UART_INTF_IDLEIF_MASK;
}

/*!
 * @brief Initializes the UART controller to known state, using
 *        register reset values defined in the reference manual.
 *
 * @param[in] Base UART Base pointer
 * @return    void
 ***************************************************************************/
CDDUART_FUNC static inline void UART_Init(UART_Type *Base)
{
    /* Set the default oversampling ratio (16) and baud-rate divider (4) */
    Base->BAUD = ((FEATURE_UART_DEFAULT_OSR << UART_BAUD_OSRVAL_SHIFT) | \
                  (FEATURE_UART_DEFAULT_DIV << UART_BAUD_DIV_SHIFT));
    /* Clear the error/interrupt flags */
    Base->INTF = FEATURE_UART_INTF_REG_FLAGS_MASK;
    /* Reset all features/interrupts by default */
    Base->CTRL0 = 0x00000000;
    /* Reset match addresses */
    Base->MATCH = 0x00000000;
#if FEATURE_UART_FIFO_SIZE > 0U
    /* Reset FIFO and watermark feature */
    Base->TXFIFO = FEATURE_UART_FIFO_RESET_MASK;
    Base->RXFIFO = FEATURE_UART_FIFO_RESET_MASK;
#endif
}



/*!
 * @brief Gets the UART transmitter Enable status.
 *
 * This function gets the UART transmitter Enable status.
 *
 *
 * @param[in] Base UART Base pointer.
 * @return boolean The UART transmitter Enable status.
 */
CDDUART_FUNC static inline boolean Uart_GetTransmitterEnStatus(UART_Type *Base)
{
    return (boolean)((Base->CTRL0 & UART_CTRL0_TXEN_MASK) >> UART_CTRL0_TXEN_SHIFT);
}

/*!
 * @brief Enable/Disable the UART transmitter.
 *
 * This function enables or disables the UART transmitter, Based on the
 * Parameter received.
 *
 *
 * @param[in] Base UART Base pointer.
 * @param[in] Enable Enable(true) or disable(false) transmitter.
 */
CDDUART_FUNC static void UART_SetTransmitterCmd(UART_Type *Base, boolean Enable)
{
    uint32 RegValTemp = 0;
    uint32 TimerOutCnt = 1000;
    boolean NotCompleteFlag = TRUE;
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_01();
    if (TRUE == Enable)
    {
        RegValTemp = (Base->CTRL0 & ~UART_CTRL0_TXEN_MASK) | (1UL << UART_CTRL0_TXEN_SHIFT);
    }
    else
    {
        RegValTemp = (Base->CTRL0 & ~UART_CTRL0_TXEN_MASK) | (0UL << UART_CTRL0_TXEN_SHIFT);
    }
    Base->CTRL0 = RegValTemp;
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_01();
    /* Wait for the register write operation to complete */
    do
    {
        NotCompleteFlag = (boolean)(Uart_GetTransmitterEnStatus(Base) != Enable);
        --TimerOutCnt;
        if (0U == TimerOutCnt)
        {
            break;
        }
    } while (TRUE == NotCompleteFlag);
}

/*!
 * @brief Gets the UART Rx Enable status.
 *
 * This function gets the UART Rx Enable status.
 *
 *
 * @param[in] Base UART Base pointer.
 * @return boolean The UART Rx Enable status.
 */
CDDUART_FUNC static inline boolean Uart_GetReceiverEnStatus(UART_Type *Base)
{
    return (boolean)((Base->CTRL0 & UART_CTRL0_RXEN_MASK) >> UART_CTRL0_RXEN_SHIFT);
}

/*!
 * @brief Enable/Disable the UART receiver.
 *
 * This function enables or disables the UART receiver, Based on the
 * Parameter received.
 *
 *
 * @param[in] Base UART Base pointer
 * @param[in] Enable Enable(true) or disable(false) receiver.
 */
CDDUART_FUNC static void UART_SetReceiverCmd(UART_Type *Base, boolean Enable)
{
    uint32 RegValTemp = 0;
    uint32 TimerOutCnt = 1000;
    boolean NotCompleteFlag = TRUE;
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_02();
    if (TRUE == Enable)
    {
        RegValTemp = (Base->CTRL0 & ~UART_CTRL0_RXEN_MASK) | (1UL << UART_CTRL0_RXEN_SHIFT);
    }
    else
    {
        RegValTemp = (Base->CTRL0 & ~UART_CTRL0_RXEN_MASK) | (0UL << UART_CTRL0_RXEN_SHIFT);
    }
    Base->CTRL0 = RegValTemp;
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_02();
    /* Wait for the register write operation to complete */
    do
    {
        NotCompleteFlag = (boolean)(Uart_GetReceiverEnStatus(Base) != Enable);
        --TimerOutCnt;
        if (0U == TimerOutCnt)
        {
            break;
        }
    } while (TRUE == NotCompleteFlag);
}

/*!
 * @brief Sets the UART baud rate modulo divisor.
 *
 * This function sets the UART baud rate modulo divisor.
 *
 *
 * @param[in] Base UART Base pointer.
 * @param[in] BaudRateDivisor The baud rate modulo division "SBR"
 */
CDDUART_FUNC static inline void UART_SetBaudRateDivisor(UART_Type *Base, uint32 BaudRateDivisor)
{
    uint32 BaudRegValTemp;
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_03();
    BaudRegValTemp = Base->BAUD;
    BaudRegValTemp &= ~ UART_BAUD_DIV_MASK;
    /* Removed the shift operation as the SBR field position is zero; shifting with 0 violates MISRA */
    BaudRegValTemp |= BaudRateDivisor & UART_BAUD_DIV_MASK;
    Base->BAUD = BaudRegValTemp;
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_03();
}

/*!
 * @brief Gets the UART baud rate modulo divisor.
 *
 * This function gets the UART baud rate modulo divisor.
 *
 *
 * @param[in] Base UART Base pointer.
 * @return uint16  The baud rate modulo division "SBR"
 */
CDDUART_FUNC static inline uint16 UART_GetBaudRateDivisor(const UART_Type *Base)
{
    return ((uint16)((Base->BAUD & UART_BAUD_DIV_MASK) >> UART_BAUD_DIV_SHIFT));
}

/*!
 * @brief Sets the UART baud rate oversampling ratio
 *
 * This function sets the UART baud rate oversampling ratio.
 * (Note: Feature available on select UART instances used together with baud rate programming)
 * The oversampling ratio should be set between 4x (00011) and 32x (11111). Writing
 * an invalid oversampling ratio results in an error and is set to a default
 * 16x (01111) oversampling ratio.
 * Disable the transmitter/receiver before calling this function.
 *
 *
 * @param[in] Base UART Base pointer.
 * @param[in] OverSamplingRatio The oversampling ratio "OSR"
 */
CDDUART_FUNC static inline void UART_SetOversamplingRatio(UART_Type *Base, uint32 OverSamplingRatio)
{
    uint32 BaudRegValTemp;
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_04();
    BaudRegValTemp = Base->BAUD;
    BaudRegValTemp &= ~ UART_BAUD_OSRVAL_MASK;
    BaudRegValTemp |= UART_BAUD_OSRVAL(OverSamplingRatio);
    Base->BAUD = BaudRegValTemp;
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_04();
}

/*!
 * @brief Gets the UART baud rate oversampling ratio
 *
 * This function gets the UART baud rate oversampling ratio.
 * (Note: Feature available on select UART instances used together with baud rate programming)
 *
 *
 * @param[in] Base UART Base pointer.
 * @return uint8   The oversampling ratio "OSR"
 */
CDDUART_FUNC static inline uint8 UART_GetOversamplingRatio(const UART_Type *Base)
{
    return ((uint8)((Base->BAUD & UART_BAUD_OSRVAL_MASK) >> UART_BAUD_OSRVAL_SHIFT));
}

/*!
 * @brief Configures the UART baud rate both edge sampling
 *
 * This function configures the UART baud rate both edge sampling.
 * (Note: Feature available on select UART instances used with baud rate programming)
 * When enabled, the received data is sampled on both edges of the baud rate clock.
 * This must be set when the oversampling ratio is between 4x and 7x.
 * This function should only be called when the receiver is disabled.
 *
 *
 * @param[in] Base UART Base pointer.
 *@return void
 */
CDDUART_FUNC static inline void UART_EnableBothEdgeSamplingCmd(UART_Type *Base)
{
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_05();
    Base->CTRL1 |= UART_CTRL1_BOTHEDGE_MASK;
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_05();
}

/*!
 * @brief Configures the number of bits per char in UART controller.
 * In some UART instances, the user should disable the transmitter/receiver
 * before calling this function.
 * Generally, this may be applied to all UARTs to ensure safe operation.
 *
 * @param[in] Base            UART Base pointer.
 * @param[in] BitCountPerChar Number of bits per char (8, 9, 10)
 * @param[in] Parity          Parity enable/disable
 * @return void
 */
CDDUART_FUNC static inline void UART_SetBitCountPerChar(UART_Type *Base, Uart_UartWordLengthType BitCountPerChar, boolean Parity)
{
    uint32 TmpBitCountPerChar = (uint32)BitCountPerChar;
    if (TRUE == Parity)
    {
        TmpBitCountPerChar += 1U;
    }
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_06();
    Base->CTRL1 &= ~UART_CTRL1_FRAMESZ_MASK;
    Base->CTRL1 |= UART_CTRL1_FRAMESZ(TmpBitCountPerChar);
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_06();
}

/*!
 * @brief Configures parity mode in the UART controller.
 * In some UART instances, the user should disable the transmitter/receiver
 * before calling this function.
 * Generally, this may be applied to all UARTs to ensure safe operation.
 *
 * @param[in] Base          UART Base pointer.
 * @param[in] ParityModeType Parity mode (none, even, odd, always 0, always 1)
 * @return void
 */
CDDUART_FUNC static inline void UART_SetParityMode(UART_Type *Base, Uart_UartParityType ParityModeType)
{
    Base->CTRL1 = (Base->CTRL1 & ~UART_CTRL1_PAREN_MASK) | (((uint32)ParityModeType >> 1U) << UART_CTRL1_PAREN_SHIFT);
    Base->CTRL1 = (Base->CTRL1 & ~UART_CTRL1_PARSEL_MASK) | (((uint32)ParityModeType & 1U) << UART_CTRL1_PARSEL_SHIFT);
}

/*!
 * @brief Sends the UART 8-bit character.
 *
 * This functions sends an 8-bit character.
 *
 *
 * @param[in] Base UART Instance
 * @param[in] Data Data to send (8-bit)
 * @return void
 */
CDDUART_FUNC static inline void UART_Putchar(UART_Type *Base, uint16 Data)
{
    Base->DATA = Data;
}

/*!
 * @brief Sends the UART 9-bit character.
 *
 * This functions sends a 9-bit character.
 * @param[in] Base UART Base pointer
 * @param[in] Data Data to send (9-bit)
 * @return void
 */
CDDUART_FUNC static inline void UART_Putchar9(UART_Type *Base, uint16 Data)
{
    Base->DATA = Data;
}

/*!
 * @brief Sends the UART 10-bit character.
 *
 * @param[in] Base UART Base pointer
 * @param[in] Data Data to send (10-bit)
 * @return void
 */
CDDUART_FUNC static inline void UART_Putchar10(UART_Type *Base, uint16 Data)
{
    Base->DATA = Data;
}

/*!
 * @brief Gets the UART 8-bit character.
 *
 * This functions receives an 8-bit character.
 *
 *
 * @param[in] Base UART Base pointer
 * @param[out] ReadData Data read from receive (8-bit)
 * @return void
 */
CDDUART_FUNC static inline void UART_Getchar(const UART_Type *Base, uint8 *ReadData)
{
    *ReadData = (uint8)Base->DATA;
}

/*!
 * @brief Gets the UART 9-bit character.
 *
 * This functions receives a 9-bit character.
 *
 * @param[in] Base UART Base pointer
 * @param[out] ReadData Data read from receive (9-bit)
 * @return void
 */
CDDUART_FUNC static inline void UART_Getchar9(const UART_Type *Base, uint16 *ReadData)
{
    /* get data from the uart data register */
    *ReadData = (uint16)Base->DATA;
}

/*!
 * @brief Gets the UART 10-bit character
 *
 * @param[in] Base UART Base pointer
 * @param[out] ReadData Data read from receive (10-bit)
 * @return void
 */
CDDUART_FUNC static inline void UART_Getchar10(const UART_Type *Base, uint16 *ReadData)
{
    /* get data */
    *ReadData = (uint16)Base->DATA;
}

/*!
 * @brief Configures the number of stop bits in the UART controller.
 *
 * This function configures the number of stop bits in the UART controller.
 * In some UART instances, the user should disable the transmitter/receiver
 * before calling this function.
 * Generally, this may be applied to all UARTs to ensure safe operation.
 *
 * @param[in] Base UART Base pointer.
 * @param[in] StopBitCount Number of stop bits (1 or 2 - see Uart_UartStopBitsType struct)
 * @return void
 */
CDDUART_FUNC static inline void UART_SetStopBitCount(UART_Type *Base, Uart_UartStopBitsType StopBitCount)
{
    Base->CTRL1 = (Base->CTRL1 & ~UART_CTRL1_STOPSZ_MASK) | ((uint32)StopBitCount << UART_CTRL1_STOPSZ_SHIFT);
}

/*!
 * @brief Set line idle detect size
 *
 * @param[in] Base UART Base pointer
 * @param[in] LineIdleSize Line idle size [0-7]
 * @return void
 */
CDDUART_FUNC static inline void UART_SetLineIdleSize(UART_Type *Base, uint8 LineIdleSize)
{
    Base->CTRL1 = (Base->CTRL1 & ~UART_CTRL1_IDLESZ_MASK) | ((uint32)LineIdleSize << UART_CTRL1_IDLESZ_SHIFT);
}

/*!
 * @brief Configures the UART module interrupts to Enable/disable
 * various interrupt sources.
 *
 * @param[in] Base UART Base pointer
 * @param[in] IntSrc Interrupt source (see Uart_InterruptType struct)
 * @param[in] Enable Enable or disable the interrupt source
 * @return void
 */
CDDUART_FUNC static inline void UART_SetIntMode(UART_Type *Base, Uart_InterruptType IntSrc, boolean Enable)
{
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_07();
    if (TRUE == Enable)
    {
        Base->INTE |= (uint32)IntSrc;
    }
    else
    {
        Base->INTE &= ~(uint32)IntSrc;
    }
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_07();
}

/*!
 * @brief Returns whether UART module interrupt is enabled/disabled.
 *
 * @param[in] Base UART Base pointer
 * @param[in] IntSrc Interrupt source (see Uart_InterruptType struct)
 * @return boolean Interrupt status (enabled/disabled)
 */
CDDUART_FUNC static inline  boolean UART_GetIntMode(const UART_Type *Base, Uart_InterruptType IntSrc)
{
    boolean ReTempValue = FALSE;
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_08();
    if ((Base->INTE & (uint32)IntSrc) != 0U)
    {
        ReTempValue = TRUE;
    }
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_08();
    return ReTempValue;
}

/*!
 * @brief UART get status flag by passing flag enum.
 *
 * @param[in] Base UART Base pointer
 * @param[in] StatusFlag Status flag (see Uart_UartStatusType struct)
 * @return boolean Status flag (set/clear)
 */
CDDUART_FUNC static inline boolean UART_GetStatusFlag(const UART_Type *Base, Uart_UartStatusType StatusFlag)
{
    boolean ReTempValue = FALSE;
    SchM_Enter_CddUart_CDDUART_EXCLUSIVE_AREA_09();
    if ((Base->INTF & (uint32)StatusFlag) != 0U)
    {
        ReTempValue = TRUE;
    }
    SchM_Exit_CddUart_CDDUART_EXCLUSIVE_AREA_09();
    return ReTempValue;
}

/*!
 * @brief Enable or disable the UART error interrupts.
 *
 * This function enables or disables the UART error interrupts.
 *
 * @param[in] Base UART Base pointer
 * @param[in] Enable Enable or disable the error interrupts
 * @return void
 */
CDDUART_FUNC static void UART_SetErrorInterrupts(UART_Type *Base, boolean Enable)
{
    /* Configure the error interrupts */
    UART_SetIntMode(Base, UART_INT_RX_OVERRUN, Enable);
    UART_SetIntMode(Base, UART_INT_PARITY_ERR, Enable);
    UART_SetIntMode(Base, UART_INT_NOISE_ERR, Enable);
    UART_SetIntMode(Base, UART_INT_FRAME_ERR, Enable);
}

/**
 * @brief Starts sending data using interrupts.
 *
 * This function is used to start sending data using interrupts on the specified UART instance.
 *
 * @param[in] Instance The UART instance to use.
 * @param[in] TxBuff Pointer to the transmit buffer containing the data to be sent.
 * @param[in] TxSize The size of the transmit buffer in bytes.
 *
 * @return CddUart_StatusType The status of the UART transmission operation.
 */
CDDUART_FUNC static CddUart_StatusType UART_Lld_StartSendDataUsingInt(uint32 Instance, uint8 *TxBuff, uint32 TxSize)
{
    UART_Type *Base = Uart_UartBase[Instance];
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    CddUart_StatusType RetVal = CDDUART_STATUS_NO_ERROR;
    /* Check it's not busy transmitting data from a previous function call */
    if (TRUE == UartStatePtr->IsTxBusy)
    {
        RetVal = CDDUART_STATUS_OPERATION_ONGOING;
    }
    else
    {
        /* initialize the module driver state structure */
        UartStatePtr->TxBuff = TxBuff;
        UartStatePtr->TxSize = TxSize;
        UartStatePtr->IsTxBusy = TRUE;
        UartStatePtr->TransmitStatus = CDDUART_STATUS_OPERATION_ONGOING;
        UART_ResetTxFifo(Base);
        UART_SetTxFifoWatermark(Base, 0U);
        UART_EnableTxFifo(Base, TRUE);
        /* Enable error interrupts */
        UART_Lld_SetErrorInterrupts(Instance, TRUE);
        /* Enable tx empty interrupt */
        UART_SetIntMode(Base, UART_INT_TX_DATA_REG_EMPTY, TRUE);
        /* Enable the UART transmitter */
        UART_SetTransmitterCmd(Base, TRUE);
    }
    return RetVal;
}

#if (STD_ON == CDDUART_DMA_USED)
/**
 * @brief Starts sending data using DMA.
 *
 * This function is used to start sending data using DMA on the specified UART instance.
 *
 * @param[in] Instance The UART instance to use.
 * @param[in] TxBuff Pointer to the transmit buffer containing the data to be sent.
 * @param[in] TxSize The size of the transmit buffer in bytes.
 *
 * @return CddUart_StatusType The status of the UART transmission operation.
 */
CDDUART_FUNC static CddUart_StatusType UART_Lld_StartSendDataUsingDma(uint32 Instance, uint8 *TxBuff, uint32 TxSize)
{
    UART_Type *Base = Uart_UartBase[Instance];
    Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    CddUart_StatusType RetVal = CDDUART_STATUS_NO_ERROR;
    CddDma_TransferConfigType UartTxDmaConfig;
    /* Check it's not busy transmitting data from a previous function call */
    if (UartStatePtr->IsTxBusy)
    {
        RetVal = CDDUART_STATUS_OPERATION_ONGOING;
    }
    else
    {
        /* Update state structure */
        UartStatePtr->TxBuff = TxBuff;
        UartStatePtr->TxSize = TxSize;
        UartStatePtr->IsTxBusy = TRUE;
        UartStatePtr->TransmitStatus = CDDUART_STATUS_OPERATION_ONGOING;
        UartTxDmaConfig = *DmaChannelTransferConfigArray[UartStatePtr->TxDMAChannel];
        UartTxDmaConfig.SrcTransferSize = DMA_TRANSFER_SIZE_1_BYTE;
        UartTxDmaConfig.DestTransferSize = DMA_TRANSFER_SIZE_1_BYTE;
        UartTxDmaConfig.SrcOffset = (sint16) 1 << (uint16)DMA_TRANSFER_SIZE_1_BYTE;
        UartTxDmaConfig.DestOffset = 0;
        UartTxDmaConfig.TransferLoopByteCount = (uint32) 1 << (uint32)DMA_TRANSFER_SIZE_1_BYTE;
        UartTxDmaConfig.TriggerCount = TxSize;
        UART_ResetTxFifo(Base);
        UART_SetTxFifoWatermark(Base, 2U);
        UART_EnableTxFifo(Base, TRUE);
        /* Configure the transfer control descriptor for the previously allocated channel */
        (void)CddDma_SetLogicChannelTransfer(UartStatePtr->TxDMAChannel, (uint32)UartStatePtr->TxBuff, \
                                             (uint32)(&(Base->DATA)), &UartTxDmaConfig);
        /* Start the DMA channel */
        CddDma_StartChannel(UartStatePtr->TxDMAChannel);
        /* Enable error interrupts */
        UART_Lld_SetErrorInterrupts(Instance, TRUE);
        /* Enable the UART transmitter */
        UART_SetTransmitterCmd(Base, TRUE);
        /* Enable tx DMA requests for the current Instance */
        UART_SetTxDmaCmd(Base, TRUE);
    }
    return RetVal;
}
#endif

/**
 * @brief Complete the process of sending data using interrupts.
 *
 * This function is called when the UART module has finished sending data using interrupts.
 *
 * @param[in] Instance The UART instance to use.
 * @return void
 */
CDDUART_FUNC static void UART_Lld_CompleteSendDataUsingInt(uint32 Instance)
{
    UART_Type *Base = Uart_UartBase[Instance];
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    UART_ResetTxFifo(Base);
    UART_EnableTxFifo(Base, FALSE);
    /* If the transfer is aborted or timed out, disable tx empty interrupt */
    UART_SetIntMode(Base, UART_INT_TX_DATA_REG_EMPTY, FALSE);
    /* Disable transmission complete interrupt */
    UART_SetIntMode(Base, UART_INT_TX_COMPLETE, FALSE);
    /* Disable transmitter */
    UART_SetTransmitterCmd(Base, FALSE);
    
    /* Update the internal busy flag */
    UartStatePtr->IsTxBusy = FALSE;
    if (UartStatePtr->TransmitStatus == CDDUART_STATUS_OPERATION_ONGOING)
    {
        /* If the transfer is completed, update the transmit status */
        UartStatePtr->TransmitStatus = CDDUART_STATUS_NO_ERROR;
    }
}

#if (STD_ON == CDDUART_DMA_USED)
/**
 * @brief Initialize the DMA channel for UART transmission.
 *
 * This function initializes the DMA channel for UART transmission.
 *
 * @param[in] Instance The UART instance to use.
 * @return void
 */
CDDUART_FUNC static void UART_Lld_DmaTxInit(uint32 Instance)
{
    const Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    CddDma_InstallCallback(UartStatePtr->TxDMAChannel, UART_Lld_TxDmaComplete, Instance);
    CddDma_InstallErrorCallback(UartStatePtr->TxDMAChannel, UART_Lld_DmaTxError, Instance);
}

/*!
 * @brief Finish up a transmit by completing the process of sending
 * data and disabling the DMA requests. This is a callback for DMA trigger loop
 * completion, so it must match the DMA callback signature.
 * This is not a public API as it is called from other driver functions.
 *
 * @param[in] Parameter The UART instance here to use.
 * @return void
 */
CDDUART_FUNC static void UART_Lld_TxDmaComplete(uint32 Instance)
{
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    UART_Type *Base = Uart_UartBase[Instance];
    CddDma_TransferConfigType UartTxDmaConfig;
    CddDma_StopChannel(UartStatePtr->TxDMAChannel);
    UartStatePtr->TxSize = 0U;
    /* Invoke callback if there is one */
    if (UartStatePtr->TxCallback != NULL_PTR)
    {
        /* Allow the user to provide a new buffer, for continuous transmission */
        UartStatePtr->TxCallback(UartStatePtr->TxCallbackParam, UART_EVENT_TX_EMPTY);
    }
    /* If the callback has updated the tx buffer, update the DMA descriptor to continue the transfer;
     * otherwise, stop the current transfer.
     */
    if (UartStatePtr->TxSize > 0U)
    {
        UartStatePtr->IsTxBusy = TRUE;
        UartStatePtr->TransmitStatus = CDDUART_STATUS_OPERATION_ONGOING;
        UartTxDmaConfig = *DmaChannelTransferConfigArray[UartStatePtr->TxDMAChannel];
        UartTxDmaConfig.SrcTransferSize = DMA_TRANSFER_SIZE_1_BYTE;
        UartTxDmaConfig.DestTransferSize = DMA_TRANSFER_SIZE_1_BYTE;
        UartTxDmaConfig.SrcOffset = (sint16) 1 << (uint16)DMA_TRANSFER_SIZE_1_BYTE;
        UartTxDmaConfig.DestOffset = 0;
        UartTxDmaConfig.TransferLoopByteCount = (uint32) 1 << (uint32)DMA_TRANSFER_SIZE_1_BYTE;
        UartTxDmaConfig.TriggerCount = UartStatePtr->TxSize;
        /* Set the source address and the number of transfer loops (bytes to be transferred) */
        /* Configure the transfer control descriptor for the previously allocated channel */
        (void)CddDma_SetLogicChannelTransfer(UartStatePtr->TxDMAChannel, (uint32)UartStatePtr->TxBuff, \
                                             (uint32)(&(Base->DATA)), &UartTxDmaConfig);
        /* Re-start the channel */
        (void)CddDma_StartChannel(UartStatePtr->TxDMAChannel);
    }
    else
    {
        UartStatePtr->IsTxBusy = FALSE;
        UartStatePtr->TransmitStatus = CDDUART_STATUS_NO_ERROR;
        /* Enable transmission complete interrupt */
        UART_SetIntMode(Base, UART_INT_TX_COMPLETE, TRUE);
        if (UartStatePtr->TxCallback != NULL_PTR)
        {
            /* Allow the user to provide a new buffer, for continuous transmission */
            UartStatePtr->TxCallback(UartStatePtr->TxCallbackParam, UART_EVENT_END_TX);
        }
    }
}

/*!
 * @brief Finish up a receive by completing the process of receiving data
 * and disabling the DMA requests. This is a callback for DMA trigger loop
 * completion, so it must match the DMA callback signature.
 * This is not a public API as it is called from other driver functions.
 *
 * @param[in] Parameter The UART instance here to use.
 * @return void
 */
CDDUART_FUNC static void UART_Lld_RxDmaComplete(uint32 Instance)
{
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    UART_Type *Base = Uart_UartBase[Instance];
    CddDma_TransferConfigType UartRxDmaConfig;
    CddDma_StopChannel(UartStatePtr->RxDMAChannel);
    UartStatePtr->RxSize = 0U;
    /* Invoke callback if there is one */
    if (UartStatePtr->RxCallback != NULL_PTR)
    {
        /* Allow the user to provide a new buffer inside the callback, to continue the reception */
        UartStatePtr->RxCallback(UartStatePtr->RxCallbackParam, UART_EVENT_RX_FULL);
    }
    /* If the callback has updated the rx buffer, update the DMA descriptor to continue the transfer;
     * otherwise, stop the current transfer.
     */
    if (UartStatePtr->RxSize > 0U)
    {
        /* Set the source address and the number of transfer loops (bytes to be transfered) */
        UartStatePtr->IsRxBusy = TRUE;
        UartStatePtr->ReceiveStatus = CDDUART_STATUS_OPERATION_ONGOING;
        UartRxDmaConfig = *DmaChannelTransferConfigArray[UartStatePtr->RxDMAChannel];
        UartRxDmaConfig.SrcTransferSize = DMA_TRANSFER_SIZE_1_BYTE;
        UartRxDmaConfig.DestTransferSize = DMA_TRANSFER_SIZE_1_BYTE;
        UartRxDmaConfig.SrcOffset = 0;
        UartRxDmaConfig.DestOffset = (sint16) 1 << (uint16)DMA_TRANSFER_SIZE_1_BYTE;
        UartRxDmaConfig.TransferLoopByteCount = (uint32) 1 << (uint32)DMA_TRANSFER_SIZE_1_BYTE;
        UartRxDmaConfig.TriggerCount = UartStatePtr->RxSize;
        /* Set the source address and the number of transfer loops (bytes to be transferred) */
        /* Configure the transfer control descriptor for the previously allocated channel */
        (void)CddDma_SetLogicChannelTransfer(UartStatePtr->RxDMAChannel, (uint32)(&(Base->DATA)), \
                                             (uint32)UartStatePtr->RxBuff, &UartRxDmaConfig);
        /* Re-start the channel */
        (void)CddDma_StartChannel(UartStatePtr->RxDMAChannel);
    }
    else
    {
        UartStatePtr->IsRxBusy = FALSE;
        UartStatePtr->ReceiveStatus = CDDUART_STATUS_NO_ERROR;
        /* Stop the reception */
        UART_Lld_StopRxDma(Instance);
        /* Invoke the callback to notify the end of the transfer */
        if (UartStatePtr->RxCallback != NULL_PTR)
        {
            UartStatePtr->RxCallback(UartStatePtr->RxCallbackParam, UART_EVENT_END_RX);
        }
        /* Clear the flags */
        UART_Lld_ClearErrorFlags(Base);
    }
}

/*!
 * @brief This function is called when an error occurs during a DMA transfer.
 *
 * @param[in] Parameter The UART instance here to use.
 * @return void
 */
CDDUART_FUNC static void UART_Lld_DmaTxError(uint32 Instance)
{
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    /* Update the status */
    UartStatePtr->TransmitStatus = CDDUART_STATUS_DMA_ERROR;
    /* Stop the transfer */
    UART_Lld_StopTxDma(Instance);
    /* Notify the application that an error occurred */
    if (UartStatePtr->TxCallback != NULL_PTR)
    {
        UartStatePtr->TxCallback(UartStatePtr->TxCallbackParam, UART_EVENT_ERROR);
    }
}

/*!
 * @brief This function is called when an error occurs during a DMA receiver.
 *
 * @param[in] Parameter The UART instance here to use.
 * @return void
 */
CDDUART_FUNC static void UART_Lld_DmaRxError(uint32 Instance)
{
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    UART_Type *Base = Uart_UartBase[Instance];
    /* Update the status */
    UartStatePtr->ReceiveStatus = CDDUART_STATUS_DMA_ERROR;
    /* Stop the transfer */
    UART_Lld_StopRxDma(Instance);
    /* Notify the application that an error occurred */
    if (UartStatePtr->RxCallback != NULL_PTR)
    {
        UartStatePtr->RxCallback(UartStatePtr->RxCallbackParam, UART_EVENT_ERROR);
    }
    /* Clear the flags */
    UART_Lld_ClearErrorFlags(Base);
}
#endif

/*!
 * @brief Initiate (start) a receive by beginning the process of
 * receiving data and enabling the interrupt.
 * This is not a public API as it is called from other driver functions.
 *
 * @param[in] Instance The UART instance to use.
 * @param[in] RxBuff Pointer to the receive buffer where the received data is stored.
 * @param[in] RxSize The size of the receive buffer in bytes.
 * @return CddUart_StatusType The status of the UART receive operation.
 */
CDDUART_FUNC static CddUart_StatusType UART_Lld_StartReceiveDataUsingInt(uint32 Instance, uint8 *RxBuff, uint32 RxSize)
{
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    UART_Type *Base = Uart_UartBase[Instance];
    CddUart_StatusType RetVal = CDDUART_STATUS_NO_ERROR;
    uint8 TmpByte;
    /* Check it's not busy receiving data from a previous function call */
    if (TRUE == UartStatePtr->IsRxBusy)
    {
        RetVal = CDDUART_STATUS_OPERATION_ONGOING;
    }
    else
    {
        /* Initialize the module driver state struct to indicate transfer in progress
         * and with the buffer and byte count data. */
        UartStatePtr->IsRxBusy = TRUE;
        UartStatePtr->RxBuff = RxBuff;
        UartStatePtr->RxSize = RxSize;
        UartStatePtr->ReceiveStatus = CDDUART_STATUS_OPERATION_ONGOING;
        /*GCOVR_EXCL_START*/
        if (TRUE == UART_GetStatusFlag(Base, UART_RX_DATA_REG_FULL))
        {
            /* Read dummy to clear RDRF flag */
            UART_Getchar(Base, &TmpByte);
        }
        /*GCOVR_EXCL_STOP*/
        UART_ResetRxFifo(Base);
        UART_SetRxFifoWatermark(Base, 0U);
        UART_EnableRxFifo(Base, TRUE);
        /* Enable error interrupts */
        UART_Lld_SetErrorInterrupts(Instance, TRUE);
        /* Enable receive data full interrupt */
        UART_SetIntMode(Base, UART_INT_RX_DATA_REG_FULL, TRUE);
        /* Enable the receiver */
        UART_SetReceiverCmd(Base, TRUE);
    }
    return RetVal;
}

#if (STD_ON == CDDUART_DMA_USED)

/*!
 * @brief Initiate (start) a receive by beginning the process of
 * receiving data using DMA transfers.
 * This is not a public API as it is called from other driver functions.
 *
 * @param[in] Instance The UART instance to use.
 * @param[in] RxBuff Pointer to the receive buffer where the received data is stored.
 * @param[in] RxSize The size of the receive buffer in bytes.
 * @return CddUart_StatusType The status of the UART receive operation.
 */
CDDUART_FUNC static CddUart_StatusType UART_Lld_StartReceiveDataUsingDma(uint32 Instance, uint8 *RxBuff, uint32 RxSize)
{
    UART_Type *Base = Uart_UartBase[Instance];
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    CddUart_StatusType RetVal = CDDUART_STATUS_NO_ERROR;
    CddDma_TransferConfigType UartRxDmaConfig;
    uint8 TmpByte;
    /* Check it's not busy transmitting data from a previous function call */
    if (UartStatePtr->IsRxBusy)
    {
        RetVal = CDDUART_STATUS_OPERATION_ONGOING;
    }
    else
    {
        /* Update state structure */
        UartStatePtr->RxBuff = RxBuff;
        UartStatePtr->RxSize = RxSize;
        UartStatePtr->IsRxBusy = TRUE;
        UartStatePtr->ReceiveStatus = CDDUART_STATUS_OPERATION_ONGOING;
        UartRxDmaConfig = *DmaChannelTransferConfigArray[UartStatePtr->RxDMAChannel];
        UartRxDmaConfig.SrcTransferSize = DMA_TRANSFER_SIZE_1_BYTE;
        UartRxDmaConfig.DestTransferSize = DMA_TRANSFER_SIZE_1_BYTE;
        UartRxDmaConfig.SrcOffset = 0;
        UartRxDmaConfig.DestOffset = (sint16) 1 << (uint16)DMA_TRANSFER_SIZE_1_BYTE;
        UartRxDmaConfig.TransferLoopByteCount = (uint32) 1 << (uint32)DMA_TRANSFER_SIZE_1_BYTE;
        UartRxDmaConfig.TriggerCount = RxSize;
        /* Read dummy to clear RDRF flag */
        /*GCOVR_EXCL_START*/
        if (TRUE == UART_GetStatusFlag(Base, UART_RX_DATA_REG_FULL))
        {
            UART_Getchar(Base, &TmpByte);
        }
        /*GCOVR_EXCL_STOP*/
        UART_ResetRxFifo(Base);
        UART_SetRxFifoWatermark(Base, 0U);
        UART_EnableRxFifo(Base, TRUE);
        /* Configure the transfer control descriptor for the previously allocated channel */
        (void)CddDma_SetLogicChannelTransfer(UartStatePtr->RxDMAChannel, (uint32)(&(Base->DATA)), \
                                             (uint32)UartStatePtr->RxBuff, &UartRxDmaConfig);
        /* Start the DMA channel */
        (void)CddDma_StartChannel(UartStatePtr->RxDMAChannel);
        /* Enable error interrupts */
        UART_Lld_SetErrorInterrupts(Instance, TRUE);
        /* Enable rx DMA requests for the current Instance */
        UART_SetRxDmaCmd(Base, TRUE);
        /* Enable the receiver */
        UART_SetReceiverCmd(Base, TRUE);
    }
    return RetVal;
}
#endif

/*!
 * @brief Finish up a receive by completing the process of receiving data
 * and disabling the interrupt.
 * This is not a public API as it is called from other driver functions.
 *
 * @param[in] Instance The UART instance to use.
 * @return void
 */
CDDUART_FUNC static void UART_Lld_CompleteReceiveDataUsingInt(uint32 Instance)
{
    uint8 TmpByte;
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    UART_Type *Base = Uart_UartBase[Instance];
    /* Disable receiver */
    UART_SetReceiverCmd(Base, FALSE);
    /* Disable error interrupts */
    UART_Lld_SetErrorInterrupts(Instance, FALSE);
    UART_ResetRxFifo(Base);
    UART_EnableRxFifo(Base, FALSE);
    /*GCOVR_EXCL_START*/
    if (TRUE == UART_GetStatusFlag(Base, UART_RX_DATA_REG_FULL))
    {
        /* Read dummy to clear RDRF flag */
        UART_Getchar(Base, &TmpByte);
    }
    /*GCOVR_EXCL_START*/
    /* Disable receive data full and rx overrun interrupt. */
    UART_SetIntMode(Base, UART_INT_RX_DATA_REG_FULL, FALSE);
    if (TRUE == UartStatePtr->IdleErrorIntEnable)
    {
        UART_Lld_ClearIdleFlag(Base);
    }
    /* Update the information of the module driver state */
    UartStatePtr->IsRxBusy = FALSE;
    if (UartStatePtr->ReceiveStatus == CDDUART_STATUS_OPERATION_ONGOING)
    {
        UartStatePtr->ReceiveStatus = CDDUART_STATUS_NO_ERROR;
    }
}

#if (STD_ON == CDDUART_DMA_USED)

CDDUART_FUNC static void UART_Lld_DmaRxInit(uint32 Instance)
{
    const Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    CddDma_InstallCallback(UartStatePtr->RxDMAChannel, UART_Lld_RxDmaComplete, Instance);
    CddDma_InstallErrorCallback(UartStatePtr->RxDMAChannel, UART_Lld_DmaRxError, Instance);
}
#endif

/*!
 * @brief Write data to the buffer register, according to configured
 * word length.
 * This is not a public API as it is called from other driver functions.
 *
 * @param[in] Instance The UART instance to use.
 * @return void
 */
CDDUART_FUNC static void UART_Lld_PutData(uint32 Instance)
{
    volatile uint8 PutCnt;
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    UART_Type *Base = Uart_UartBase[Instance];
    uint8 TempData8;
    uint16 TempData16;
    if (UartStatePtr->WordLength <= UART_8_BITS_PER_CHAR)
    {
        PutCnt = 0U;
        while (UartStatePtr->TxSize > 0U)
        {
            TempData8 = *UartStatePtr->TxBuff;
            /* Update the state structure */
            ++UartStatePtr->TxBuff;
            UartStatePtr->TxSize -= 1U;
            PutCnt++;
            /* Transmit the data */
            UART_Putchar(Base, TempData8);
            if (PutCnt == 4U)
            {
                break;
            }
        }
        
        
    }
    else if (UartStatePtr->WordLength == UART_9_BITS_PER_CHAR)
    {
        /*GCOVR_EXCL_START*/
        /*Multiple configurations required*/
        PutCnt = 0U;
        while (UartStatePtr->TxSize > 0U)
        {
            TempData16 = *(UartStatePtr->TxBuff);
            TempData16 = (uint16)(TempData16 << 8U);
            ++UartStatePtr->TxBuff;
            UartStatePtr->TxSize -= 1U;
            if (UartStatePtr->TxSize > 0U)
            {
                TempData16 |= *(UartStatePtr->TxBuff);
                ++UartStatePtr->TxBuff;
                UartStatePtr->TxSize -= 1U;
            }
            PutCnt++;
            /* Transmit the data */
            UART_Putchar9(Base, TempData16);
            if (PutCnt == 4U)
            {
                break;
            }
            
        }
        /*GCOVR_EXCL_STOP*/
        
    }
    else
    {
        /*GCOVR_EXCL_START*/
        PutCnt = 0U;
        while (UartStatePtr->TxSize > 0U)
        {
            /*Multiple configurations required*/
            /* Create a 16-bits integer from two bytes */
            TempData16 = *(UartStatePtr->TxBuff);
            TempData16 = (uint16)(TempData16 << 8U);
            ++UartStatePtr->TxBuff;
            UartStatePtr->TxSize -= 1U;
            if (UartStatePtr->TxSize > 0U)
            {
                TempData16 |= *(UartStatePtr->TxBuff);
                ++UartStatePtr->TxBuff;
                UartStatePtr->TxSize -= 1U;
            }
            PutCnt++;
            /* Transmit the data */
            UART_Putchar10(Base, TempData16);
            if (PutCnt == 4U)
            {
                break;
            }
        }
        
        
        
        /*GCOVR_EXCL_STOP*/
    }
}

/*!
 * @brief Read data from the buffer register, according to configured
 * word length.
 * This is not a public API as it is called from other driver functions.
 *
 * @param[in] Instance The UART instance to use.
 * @return void
 */
CDDUART_FUNC static void UART_Lld_GetData(uint32 Instance)
{
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    const UART_Type *Base = Uart_UartBase[Instance];
    uint16 TempData16 = 0;
    if (UartStatePtr->WordLength <= UART_8_BITS_PER_CHAR)
    {
        /* Receive the data */
        UART_Getchar(Base, (UartStatePtr->RxBuff));
        ++UartStatePtr->RxBuff;
        UartStatePtr->RxSize -= 1U;
    }
    else if (UartStatePtr->WordLength == UART_9_BITS_PER_CHAR)
    {
        /*GCOVR_EXCL_START*/
        /*Multiple configurations required*/
        /* Receive the data */
        UART_Getchar9(Base, &TempData16);
        *(UartStatePtr->RxBuff) = (uint8)(TempData16 >> 8U);
        ++UartStatePtr->RxBuff;
        UartStatePtr->RxSize -= 1U;
        if (UartStatePtr->RxSize > 0U)
        {
            *(UartStatePtr->RxBuff) = (uint8)(TempData16 & 0x00FFU);
            ++UartStatePtr->RxBuff;
            UartStatePtr->RxSize -= 1U;
        }
        /*GCOVR_EXCL_STOP*/
    }
    else
    {
        /*GCOVR_EXCL_START*/
        /*Multiple configurations required*/
        /* Receive the data */
        UART_Getchar10(Base, &TempData16);
        *(UartStatePtr->RxBuff) = (uint8)(TempData16 >> 8U);
        ++UartStatePtr->RxBuff;
        UartStatePtr->RxSize -= 1U;
        if (UartStatePtr->RxSize > 0U)
        {
            *(UartStatePtr->RxBuff) = (uint8)(TempData16 & 0x00FFU);
            ++UartStatePtr->RxBuff;
            UartStatePtr->RxSize -= 1U;
        }
        /*GCOVR_EXCL_STOP*/
    }
}

#if (STD_ON == CDDUART_DMA_USED)
/*!
 * @brief Finish up a DMA transmission by disabling the DMA requests,
 * transmission complete interrupt and tx logic. This function also resets the
 * internal driver state (busy flag/tx semaphore).
 * This is not a public API as it is called from other driver functions.
 *
 * @param[in] Instance The UART instance to use.
 * @return void
 */
CDDUART_FUNC static void UART_Lld_StopTxDma(uint32 Instance)
{
    UART_Type *Base = Uart_UartBase[Instance];
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    /* Disable tx DMA requests for the current Instance */
    UART_SetTxDmaCmd(Base, FALSE);
    /* Stop the dma channel */
    (void)CddDma_StopChannel(UartStatePtr->TxDMAChannel);
    /* Disable transmission complete interrupt */
    UART_SetIntMode(Base, UART_INT_TX_COMPLETE, FALSE);
    /* Disable transmitter */
    UART_SetTransmitterCmd(Base, FALSE);
    if (UartStatePtr->TransmitStatus == CDDUART_STATUS_OPERATION_ONGOING)
    {
        /* If the transfer is completed, update the transmit status */
        UartStatePtr->TransmitStatus = CDDUART_STATUS_NO_ERROR;
    }
    /* Update the internal busy flag */
    UartStatePtr->IsTxBusy = FALSE;
}

/*!
 * @brief Finish up a DMA reception by disabling the DMA requests,
 * error interrupts and rx logic. This function also resets the internal driver
 * state (busy flag/rx semaphore).
 * This is not a public API as it is called from other driver functions.
 *
 * @param[in] Instance The UART instance to use.
 * @return void
 */
CDDUART_FUNC static void UART_Lld_StopRxDma(uint32 Instance)
{
    UART_Type *Base = Uart_UartBase[Instance];
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    /* Disable receiver */
    UART_SetReceiverCmd(Base, FALSE);
    /* Disable error interrupts */
    UART_Lld_SetErrorInterrupts(Instance, FALSE);
    /* Disable rx DMA requests for the current Instance */
    UART_SetRxDmaCmd(Base, FALSE);
    /* Reset rx fifo to clear RDRF flag */
    UART_ResetRxFifo(Base);
    /* Stop the DMA channel */
    (void)CddDma_StopChannel(UartStatePtr->RxDMAChannel);
    /* Update the internal driver status */
    if (UartStatePtr->ReceiveStatus == CDDUART_STATUS_OPERATION_ONGOING)
    {
        UartStatePtr->ReceiveStatus = CDDUART_STATUS_NO_ERROR;
    }
    /* Update the information of the module driver state */
    UartStatePtr->IsRxBusy = FALSE;
}
#endif

/*!
 * @brief Enable or disable the UART error interrupts.
 * This is not a public API as it is called from other driver functions.
 *
 * @param[in] Instance The UART instance to use.
 * @param[in] Enable TRUE to enable the error interrupts, FALSE to disable.
 * @return void
 */
CDDUART_FUNC static void UART_Lld_SetErrorInterrupts(uint32 Instance, boolean Enable)
{
    UART_Type *Base = Uart_UartBase[Instance];
    const Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    boolean IdleIntEnable;
    if ((TRUE == UartStatePtr->IdleErrorIntEnable) && (TRUE == Enable))
    {
        IdleIntEnable = TRUE;
    }
    else
    {
        IdleIntEnable = FALSE;
    }
    /* Disable/Enable error interrupts */
    UART_SetErrorInterrupts(Base, Enable);
    UART_SetIntMode(Base, UART_INT_IDLE_LINE, IdleIntEnable);
}

/*==================================================================================================
                                                GLOBAL FUNCTIONS
==================================================================================================*/
CDDUART_FUNC CddUart_StatusType UART_Lld_Init(uint32 Instance, uint32 UartClock, const Uart_UartUserConfigType *UartUserConfig)
{
    CddUart_StatusType UartStatus = CDDUART_STATUS_NO_ERROR;
    UART_Type *Base;
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    uint32 Idx = 0;
    if (Instance > CDDUART_UART_INSTANCE_COUNT)
    {
        UartStatus = CDDUART_STATUS_OTHER_ERROR;
    }
    else if (NULL_PTR == UartUserConfig)
    {
        UartStatus = CDDUART_STATUS_OTHER_ERROR;
    }
    else if ((UartUserConfig->WordLength == UART_10_BITS_PER_CHAR) &&
             (UartUserConfig->ParityType == UART_PARITY_DISABLED))
    {
        UartStatus = CDDUART_STATUS_OTHER_ERROR;
    }
    else
    {
        /* Clear the state struct for this instance. */
        uint8 *ClearStructPtr = (uint8 *)UartStatePtr;
        Idx = 0;
        for (; Idx < sizeof(Uart_UartStateType); ++Idx)
        {
            ClearStructPtr[Idx] = 0;
        }
        /* Save runtime structure pointer.*/
        Uart_UartStatePtr[Instance] = (*UartStatePtr);
        /* Save whether to Enable idle interrupt. */
        UartStatePtr->IdleErrorIntEnable = UartUserConfig->IdleErrorIntEnable;
        UartStatePtr->LinIdleDetectSize = UartUserConfig->LinIdleDetectSize;
        /* Save the transfer information for runtime retrieval */
        UartStatePtr->WordLength = UartUserConfig->WordLength;
#if (STD_ON == CDDUART_DMA_USED)
        UartStatePtr->RxDMAChannel = UartUserConfig->RxDMAChannel;
        UartStatePtr->TxDMAChannel = UartUserConfig->TxDMAChannel;
#endif
        /* initialize the UART Instance */
        Base = Uart_UartBase[Instance];
        UART_Init(Base);
        /* initialize the parameters of the UART config structure with desired data */
        (void)UART_Lld_SetBaudRate(Instance, UartClock, UartUserConfig->BaudRate);
        if (UartUserConfig->ParityType != UART_PARITY_DISABLED)
        {
            UART_SetBitCountPerChar(Base, UartUserConfig->WordLength, TRUE);
        }
        else
        {
            UART_SetBitCountPerChar(Base, UartUserConfig->WordLength, FALSE);
        }
        UART_SetParityMode(Base, UartUserConfig->ParityType);
        UART_SetStopBitCount(Base, UartUserConfig->StopBitsCount);
        UART_SetLineIdleSize(Base, (uint8)UartUserConfig->LinIdleDetectSize);
        UART_SetIntMode(Base, UART_INT_IDLE_LINE, FALSE);
        /* initialize last driver operation status */
        Uart_UartStatePtr[Instance].TransmitStatus = CDDUART_STATUS_NO_ERROR;
        Uart_UartStatePtr[Instance].ReceiveStatus = CDDUART_STATUS_NO_ERROR;
        /* Save the transfer type and DMA channels in driver state */
        Uart_UartStatePtr[Instance].TxTransferType = UartUserConfig->TxTransferType;
        Uart_UartStatePtr[Instance].RxTransferType = UartUserConfig->RxTransferType;
#if (STD_ON == CDDUART_DMA_USED)
        if (UartUserConfig->TxTransferType == UART_USING_DMA)
        {
            UART_Lld_DmaTxInit(Instance);
        }
        if (UartUserConfig->RxTransferType == UART_USING_DMA)
        {
            UART_Lld_DmaRxInit(Instance);
        }
#endif
        /* Initialize callback functions and parameters */
        Uart_UartStatePtr[Instance].RxCallback = UartUserConfig->ComplexCallback;
        Uart_UartStatePtr[Instance].TxCallback = UartUserConfig->ComplexCallback;
        Uart_UartStatePtr[Instance].ErrorCallback = UartUserConfig->ComplexCallback;
        Uart_UartStatePtr[Instance].RxCallbackParam = UartUserConfig->LogicChannel;
        Uart_UartStatePtr[Instance].TxCallbackParam = UartUserConfig->LogicChannel;
        Uart_UartStatePtr[Instance].ErrorCallbackParam = NULL_PTR;
    }
    return UartStatus;
}

CDDUART_FUNC CddUart_StatusType UART_Lld_Deinit(uint32 Instance)
{
    CddUart_StatusType UartStatus = CDDUART_STATUS_NO_ERROR;
    uint32 Idx = 0;
    volatile Uart_UartStateType *UartStatePtr;
    if (Instance > CDDUART_UART_INSTANCE_COUNT)
    {
        UartStatus = CDDUART_STATUS_OTHER_ERROR;
    }
    else
    {
        UartStatePtr = &Uart_UartStatePtr[Instance];
        /* Clear the state struct for this Instance. */
        uint8 *ClearStructPtr = (uint8 *)UartStatePtr;
        for (; Idx < sizeof(Uart_UartStateType); ++Idx)
        {
            ClearStructPtr[Idx] = 0;
        }
        Uart_UartStatePtr[Instance] = (*UartStatePtr);
    }
    return UartStatus;
}
/* implements UART_Lld_SetCallback Activity*/
CDDUART_FUNC CddUart_StatusType UART_Lld_SetCallback(uint32 Instance, CddUart_General_CallbackType CallBackFunction)
{
    CddUart_StatusType UartStatus = CDDUART_STATUS_NO_ERROR;
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    if ((Instance > CDDUART_UART_INSTANCE_COUNT)
            || (NULL_PTR == CallBackFunction))
    {
        UartStatus = CDDUART_STATUS_OTHER_ERROR;
    }
    else
    {
        UartStatePtr->TxCallback = CallBackFunction;
        UartStatePtr->RxCallback = CallBackFunction;
        UartStatePtr->ErrorCallback = CallBackFunction;
    }
    return UartStatus;
}

CDDUART_FUNC CddUart_StatusType UART_Lld_SendDataBlocking(uint32 Instance, uint8 *TxBuff, uint32 TxSize, uint32 Timeout)
{
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    CddUart_StatusType RetVal = CDDUART_STATUS_NO_ERROR;
    uint32 CddUartTemp16 = 0;
    CddUartTemp16 = Timeout;
    if ((Instance > CDDUART_UART_INSTANCE_COUNT)
            || (NULL_PTR == TxBuff)
            || (0U == TxSize))
    {
        RetVal = CDDUART_STATUS_OTHER_ERROR;
    }
    else
    {
        if (UartStatePtr->TxTransferType == UART_USING_INTERRUPTS)
        {
            /* Start the transmission process using interrupts */
            RetVal = UART_Lld_StartSendDataUsingInt(Instance, TxBuff, TxSize);
        }
#if (STD_ON == CDDUART_DMA_USED)
        else
        {
            /* Start the transmission process using DMA */
            RetVal = UART_Lld_StartSendDataUsingDma(Instance, TxBuff, TxSize);
        }
#endif
        while ((TRUE == UartStatePtr->IsTxBusy) && (CDDUART_STATUS_NO_ERROR == RetVal))
        {
            /* Wait until to transmit is complete. */
            if (0U == CddUartTemp16)
            {
                /*GCOVR_EXCL_START*/
                /*Hardware errors need to be injected*/
                RetVal = CDDUART_STATUS_TIMEOUT;
                break;
                /*GCOVR_EXCL_STOP*/
            }
            --CddUartTemp16;
        }
        /* Finish the transmission if timeout expired */
        if (RetVal == CDDUART_STATUS_TIMEOUT)
        {
            /*GCOVR_EXCL_START*/
            /*Hardware errors need to be injected*/
            UartStatePtr->TransmitStatus = CDDUART_STATUS_TIMEOUT;
            if (UartStatePtr->TxTransferType == UART_USING_INTERRUPTS)
            {
                UART_Lld_CompleteSendDataUsingInt(Instance);
            }
#if (STD_ON == CDDUART_DMA_USED)
            else
            {
                UART_Lld_StopTxDma(Instance);
            }
#endif
            /*GCOVR_EXCL_STOP*/
        }
        else
        {
            if (UartStatePtr->TransmitStatus != CDDUART_STATUS_NO_ERROR)
            {
                UartStatePtr->TransmitStatus = CDDUART_STATUS_OTHER_ERROR;
            }
        }
    }
    return RetVal;
}

CDDUART_FUNC CddUart_StatusType UART_Lld_SendData(uint32 Instance, uint8 *TxBuff,
        uint32 TxSize)
{
    CddUart_StatusType RetVal = CDDUART_STATUS_NO_ERROR;
    const Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    if ((Instance > CDDUART_UART_INSTANCE_COUNT)
            || (NULL_PTR == TxBuff)
            || (0U == TxSize))
    {
        RetVal = CDDUART_STATUS_OTHER_ERROR;
    }
    else
    {
        if (UartStatePtr->TxTransferType == UART_USING_INTERRUPTS)
        {
            /* Start the transmission process using interrupts */
            RetVal = UART_Lld_StartSendDataUsingInt(Instance, TxBuff, TxSize);
        }
#if (STD_ON == CDDUART_DMA_USED)
        else
        {
            /* Start the transmission process using DMA */
            RetVal = UART_Lld_StartSendDataUsingDma(Instance, TxBuff, TxSize);
        }
#endif
    }
    return RetVal;
}

CDDUART_FUNC void  UART_Lld_SetTransmitStatus(uint32 Instance, CddUart_StatusType Status)
{
    Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    UartStatePtr->TransmitStatus = Status;
}

CDDUART_FUNC CddUart_StatusType UART_Lld_GetTransmitStatus(uint32 Instance, uint32 *BytesRemaining)
{
    const Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    CddUart_StatusType RetVal = CDDUART_STATUS_NO_ERROR;
    if (Instance > CDDUART_UART_INSTANCE_COUNT)
    {
        RetVal = CDDUART_STATUS_OTHER_ERROR;
    }
    else
    {
        if (BytesRemaining != NULL_PTR)
        {
            if (TRUE == UartStatePtr->IsTxBusy)
            {
                /* Fill in the bytes not transferred yet. */
                if (UartStatePtr->TxTransferType == UART_USING_INTERRUPTS)
                {
                    /* In interrupt-Based communication, the remaining bytes are retrieved
                     * from the state structure
                     */
                    *BytesRemaining = UartStatePtr->TxSize;
                }
#if (STD_ON == CDDUART_DMA_USED)
                else
                {
                    /* In DMA-Based communication, the remaining bytes are retrieved
                     * from the current DMA trigger loop count
                     */
                    *BytesRemaining = CddDma_GetChannelRemainingTriggerCount(UartStatePtr->TxDMAChannel);
                }
#endif
            }
            else
            {
                *BytesRemaining = 0;
            }
        }
        RetVal = UartStatePtr->TransmitStatus;
    }
    return RetVal;
}

CDDUART_FUNC CddUart_StatusType UART_Lld_AbortSendingData(uint32 Instance)
{
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    CddUart_StatusType RetVal = CDDUART_STATUS_NO_ERROR;
    if (Instance > CDDUART_UART_INSTANCE_COUNT)
    {
        RetVal = CDDUART_STATUS_OTHER_ERROR;
    }
    else if (TRUE == UartStatePtr->IsTxBusy)
    {
        /* Update the tx status */
        UartStatePtr->TransmitStatus = CDDUART_STATUS_ABORTED;
        /* Stop the running transfer. */
        if (UartStatePtr->TxTransferType == UART_USING_INTERRUPTS)
        {
            UART_Lld_CompleteSendDataUsingInt(Instance);
        }
#if (STD_ON == CDDUART_DMA_USED)
        else
        {
            UART_Lld_StopTxDma(Instance);
        }
#endif
    }
    else
    {
        /*do nothing*/
    }
    return RetVal;
}

CDDUART_FUNC CddUart_StatusType UART_Lld_ReceiveDataBlocking(uint32 Instance, uint8 *RxBuff, uint32 RxSize, uint32 Timeout)
{
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    CddUart_StatusType RetVal = CDDUART_STATUS_NO_ERROR;
    uint32 CddUartTemp16 = 0;
    CddUartTemp16 = Timeout;
    if ((Instance > CDDUART_UART_INSTANCE_COUNT)
            || (NULL_PTR == RxBuff)
            || (0U == RxSize))
    {
        RetVal = CDDUART_STATUS_OTHER_ERROR;
    }
    else
    {
        if (UartStatePtr->RxTransferType == UART_USING_INTERRUPTS)
        {
            /* Start the reception process using interrupts */
            RetVal = UART_Lld_StartReceiveDataUsingInt(Instance, RxBuff, RxSize);
        }
#if(STD_ON == CDDUART_DMA_USED)
        else
        {
            /* Start the reception process using DMA */
            RetVal = UART_Lld_StartReceiveDataUsingDma(Instance, RxBuff, RxSize);
        }
#endif
        while ((TRUE == UartStatePtr->IsRxBusy) && (CDDUART_STATUS_NO_ERROR == RetVal))
        {
            /* Wait until to transmit is complete. */
            if (0U == CddUartTemp16)
            {
                RetVal = CDDUART_STATUS_TIMEOUT;
                break;
            }
            --CddUartTemp16;
        }
        /* Finish the reception if Timeout expired */
        if (RetVal == CDDUART_STATUS_TIMEOUT)
        {
            UartStatePtr->ReceiveStatus = CDDUART_STATUS_TIMEOUT;
            if (UartStatePtr->RxTransferType == UART_USING_INTERRUPTS)
            {
                UART_Lld_CompleteReceiveDataUsingInt(Instance);
            }
#if(STD_ON == CDDUART_DMA_USED)
            else
            {
                UART_Lld_StopRxDma(Instance);
            }
#endif
        }
        else
        {
            if (UartStatePtr->ReceiveStatus != CDDUART_STATUS_NO_ERROR)
            {
                UartStatePtr->ReceiveStatus = CDDUART_STATUS_OTHER_ERROR;
            }
        }
    }
    return RetVal;
}

CDDUART_FUNC CddUart_StatusType UART_Lld_ReceiveData(uint32 Instance, uint8 *RxBuff, uint32 RxSize)
{
    CddUart_StatusType RetVal = CDDUART_STATUS_NO_ERROR;
    const Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    if ((Instance > CDDUART_UART_INSTANCE_COUNT)
            || (NULL_PTR == RxBuff)
            || (0U == RxSize))
    {
        RetVal = CDDUART_STATUS_OTHER_ERROR;
    }
    else
    {
        if (UartStatePtr->RxTransferType == UART_USING_INTERRUPTS)
        {
            /* Start the transmission process using interrupts */
            RetVal = UART_Lld_StartReceiveDataUsingInt(Instance, RxBuff, RxSize);
        }
#if(STD_ON == CDDUART_DMA_USED)
        else
        {
            /* Start the transmission process using interrupts */
            RetVal = UART_Lld_StartReceiveDataUsingDma(Instance, RxBuff, RxSize);
        }
#endif
    }
    return RetVal;
}

CDDUART_FUNC void UART_Lld_SetReceiveStatus(uint32 Instance, CddUart_StatusType Status)
{
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    UartStatePtr->ReceiveStatus = Status;
}

CDDUART_FUNC CddUart_StatusType UART_Lld_GetReceiveStatus(uint32 Instance, uint32 *BytesRemaining)
{
    const Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    CddUart_StatusType RetVal = CDDUART_STATUS_NO_ERROR;
    if (Instance > CDDUART_UART_INSTANCE_COUNT)
    {
        RetVal = CDDUART_STATUS_OTHER_ERROR;
    }
    else
    {
        if (BytesRemaining != NULL_PTR)
        {
            if (TRUE == UartStatePtr->IsRxBusy)
            {
                /* Fill in the number of bytes yet to be received and update the return value if needed */
                if (UartStatePtr->RxTransferType == UART_USING_INTERRUPTS)
                {
                    /* In interrupt-Based communication, the remaining bytes are retrieved
                     * from the state structure
                     */
                    *BytesRemaining = UartStatePtr->RxSize;
                }
#if(STD_ON == CDDUART_DMA_USED)
                else
                {
                    /* In DMA-Based communication, the remaining bytes are retrieved
                     * from the current DMA trigger loop count*/
                    *BytesRemaining = CddDma_GetChannelRemainingTriggerCount(UartStatePtr->RxDMAChannel);
                }
#endif
            }
            else
            {
                *BytesRemaining = 0;
            }
        }
        RetVal = UartStatePtr->ReceiveStatus;
    }
    return RetVal;
}

CDDUART_FUNC CddUart_StatusType UART_Lld_AbortReceivingData(uint32 Instance)
{
    CddUart_StatusType RetVal = CDDUART_STATUS_NO_ERROR;
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    if (Instance > CDDUART_UART_INSTANCE_COUNT)
    {
        RetVal = CDDUART_STATUS_OTHER_ERROR;
    }
    else if (TRUE == UartStatePtr->IsRxBusy)
    {
        /* Check if a transfer is running. */
        /* Update the rx status */
        UartStatePtr->ReceiveStatus = CDDUART_STATUS_ABORTED;
        /* Stop the running transfer. */
        if (UartStatePtr->RxTransferType == UART_USING_INTERRUPTS)
        {
            UART_Lld_CompleteReceiveDataUsingInt(Instance);
        }
#if(STD_ON == CDDUART_DMA_USED)
        else
        {
            UART_Lld_StopRxDma(Instance);
        }
#endif
    }
    else
    {
        /*do nothing*/
    }
    return RetVal;
}

CDDUART_FUNC CddUart_StatusType UART_Lld_SetBaudRate(uint32 Instance, uint32 UartClock, uint32 DesiredBaudRate)
{
    uint16 Sbr = 0U;
    uint16 SbrTemp = 0U;
    uint16 Tempi = 0U;
    uint32 Osr = 0U;
    uint32 TempDiff = 0U;
    uint32 CalculatedBaud = 0U;
    uint32 BaudDiff = 0U;
    uint32 MaxOsr = 0U;
    uint32 UartSourceClock = UartClock;
    UART_Type *Base;
    CddUart_StatusType UartStatus = CDDUART_STATUS_NO_ERROR;
    if (Instance > CDDUART_UART_INSTANCE_COUNT)
    {
        UartStatus = CDDUART_STATUS_OTHER_ERROR;
    }
    else if ((TRUE == Uart_UartStatePtr[Instance].IsTxBusy)
             || (TRUE == Uart_UartStatePtr[Instance].IsRxBusy))
    {
        UartStatus = CDDUART_STATUS_OPERATION_ONGOING;
    }
    else
    {
        Base = Uart_UartBase[Instance];
        Uart_ClockFrequency[Instance] = UartClock;
        /* This uart instantiation uses a slightly different baud rate calculation
         * The idea is to use the best OSR (over-sampling rate) possible
         * Note, Osr is typically hard-set to 16 in other uart instantiations
         * First calculate the baud rate using the minimum OSR possible (4) */
        Osr = 4;
        Sbr = (uint16)(UartSourceClock / (DesiredBaudRate * Osr));
        CalculatedBaud = (UartSourceClock / (Osr * Sbr));
        if (CalculatedBaud > DesiredBaudRate)
        {
            BaudDiff = CalculatedBaud - DesiredBaudRate;
        }
        else
        {
            BaudDiff = DesiredBaudRate - CalculatedBaud;
        }
        /* find maximum Osr */
        MaxOsr = UartSourceClock / DesiredBaudRate;
        if (MaxOsr > 32U)
        {
            MaxOsr = 32U;
        }
        /* loop to find the best Osr value possible, one that generates minimum BaudDiff
         * iterate through the rest of the supported values of Osr */
        if (MaxOsr >= 5U)
        {
            Tempi = 5U;
            for (; Tempi <= MaxOsr; ++Tempi)
            {
                /* calculate the temporary Sbr value   */
                SbrTemp = (uint16)(UartSourceClock / (DesiredBaudRate * Tempi));
                /* calculate the baud rate Based on the temporary Osr and Sbr values */
                CalculatedBaud = (UartSourceClock / (Tempi * SbrTemp));
                if (CalculatedBaud > DesiredBaudRate)
                {
                    TempDiff = CalculatedBaud - DesiredBaudRate;
                }
                else
                {
                    TempDiff = DesiredBaudRate - CalculatedBaud;
                }
                if (TempDiff <= BaudDiff)
                {
                    BaudDiff = TempDiff;
                    Osr = Tempi;  /* update and store the best Osr value calculated */
                    Sbr = SbrTemp;  /* update store the best Sbr value calculated */
                }
            }
        }
        /* Check if Osr is between 4x and 7x oversampling.
         * If so, then "BOTHEDGE" sampling must be turned on */
        if (Osr < 8U)
        {
            UART_EnableBothEdgeSamplingCmd(Base);
        }
        /* program the Osr value (bit value is one less than actual value) */
        UART_SetOversamplingRatio(Base, (Osr - 1U));
        /* write the Sbr value to the BAUD registers */
        UART_SetBaudRateDivisor(Base, Sbr);
    }
    return UartStatus;
}

CDDUART_FUNC CddUart_StatusType UART_Lld_GetBaudRate(uint32 Instance, uint32 *ConfiguredBaudRate)
{
    uint8 Osr;
    uint16 Sbr;
    uint32 UartSourceClock;
    CddUart_StatusType UartStatus = CDDUART_STATUS_NO_ERROR;
    UART_Type const *Base;
    if ((Instance > CDDUART_UART_INSTANCE_COUNT)
            || (NULL_PTR == ConfiguredBaudRate))
    {
        UartStatus = CDDUART_STATUS_OTHER_ERROR;
    }
    else
    {
        Base = Uart_UartBase[Instance];
        UartSourceClock = Uart_ClockFrequency[Instance];
        Osr = UART_GetOversamplingRatio(Base);
        Sbr = UART_GetBaudRateDivisor(Base);
        /* Compute the baud rate Based on protocol clock value */
        *ConfiguredBaudRate = (UartSourceClock / ((Osr + 1UL) * Sbr));
    }
    return UartStatus;
}

CDDUART_FUNC CddUart_StatusType UART_Lld_SetTxBuffer(uint32 Instance, uint8 *TxBuff, uint32 TxSize)
{
    CddUart_StatusType UartStatus = CDDUART_STATUS_NO_ERROR;
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    if ((Instance > CDDUART_UART_INSTANCE_COUNT)
            || (NULL_PTR == TxBuff)
            || (0U == TxSize))
    {
        UartStatus = CDDUART_STATUS_OTHER_ERROR;
    }
    else
    {
        UartStatePtr->TxBuff = TxBuff;
        UartStatePtr->TxSize = TxSize;
    }
    return UartStatus;
}

CDDUART_FUNC CddUart_StatusType UART_Lld_SetRxBuffer(uint32 Instance, uint8 *RxBuff, uint32 RxSize)
{
    CddUart_StatusType UartStatus = CDDUART_STATUS_NO_ERROR;
    volatile Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    if ((Instance > CDDUART_UART_INSTANCE_COUNT)
            || (NULL_PTR == RxBuff)
            || (0U == RxSize))
    {
        UartStatus = CDDUART_STATUS_OTHER_ERROR;
    }
    else
    {
        UartStatePtr->RxBuff = RxBuff;
        UartStatePtr->RxSize = RxSize;
    }
    return UartStatus;
}

CDDUART_FUNC void UART_Lld_IRQHandler(uint8 Instance)
{
    const UART_Type *Base = Uart_UartBase[Instance];
    UART_Lld_ErrIrqHandler(Instance);
    /* Handle receive data full interrupt */
    if ((TRUE == UART_GetIntMode(Base, UART_INT_RX_DATA_REG_FULL)) &&
            (TRUE == UART_GetStatusFlag(Base, UART_RX_DATA_REG_FULL)))
    {
        UART_Lld_RxIrqHandler(Instance);
    }
    /* Handle transmitter data register empty interrupt */
    if ((TRUE == UART_GetIntMode(Base, UART_INT_TX_DATA_REG_EMPTY)) &&
            (TRUE == UART_GetStatusFlag(Base, UART_TX_DATA_REG_EMPTY)))
    {
        UART_Lld_TxEmptyIrqHandler(Instance);
    }
    /* Handle transmission complete interrupt */
    if ((TRUE == UART_GetIntMode(Base, UART_INT_TX_COMPLETE)) &&
            (TRUE == UART_GetStatusFlag(Base, UART_TX_COMPLETE)))
    {
        UART_Lld_TxCompleteIrqHandler(Instance);
    }
    /* Handle idle line interrupt */
    if ((TRUE == UART_GetIntMode(Base, UART_INT_IDLE_LINE)) &&
            (TRUE == UART_GetStatusFlag(Base, UART_IDLE_LINE_DETECT)))
    {
        UART_Lld_IdleLineIrqHandler(Instance);
    }
}

CDDUART_FUNC void UART_Lld_RxIrqHandler(uint8 Instance)
{
    const Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    /* Exit if there is no reception in progress */
    if (TRUE == UartStatePtr->IsRxBusy)
    {
        /* Get data and put in receive buffer  */
        UART_Lld_GetData(Instance);
        /* Check if this was the last byte in the current buffer */
        if (0U == UartStatePtr->RxSize)
        {
            /* Invoke the callback when the buffer is finished;
             * Application can provide another buffer inside the callback by calling LINFlexD_UART_Lld_SetRxBuffer */
            if (UartStatePtr->RxCallback != NULL_PTR)
            {
                UartStatePtr->RxCallback(UartStatePtr->RxCallbackParam, UART_EVENT_RX_FULL);
            }
        }
        /* Finish reception if this was the last byte received */
        if (0U == UartStatePtr->RxSize)
        {
            /* Complete transfer (disable rx logic) */
            UART_Lld_CompleteReceiveDataUsingInt(Instance);
            /* Invoke callback if there is one */
            if (UartStatePtr->RxCallback != NULL_PTR)
            {
                UartStatePtr->RxCallback(UartStatePtr->RxCallbackParam, UART_EVENT_END_RX);
            }
        }
        /* Clear the flag */
    }
}

CDDUART_FUNC void UART_Lld_IdleLineIrqHandler(uint8 Instance)
{
    Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    if (UartStatePtr->RxSize > 0U)
    {
        /* Stop the running transfer. */
        if (UartStatePtr->TxTransferType == UART_USING_INTERRUPTS)
        {
            UART_Lld_CompleteReceiveDataUsingInt(Instance);
        }
#if (STD_ON == CDDUART_DMA_USED)
        else
        {
            UART_Lld_RxDmaComplete(Instance);
        }
#endif
        /* Update the tx status */
        UartStatePtr->ReceiveStatus = CDDUART_STATUS_TIMEOUT;
    }
    /* Ensure no new receive is required from the Idle callback*/
    UartStatePtr->IsRxBusy = TRUE;
    if (UartStatePtr->RxCallback != NULL_PTR)
    {
        UartStatePtr->RxCallback(UartStatePtr->RxCallbackParam, UART_EVENT_IDLE);
    }
    UartStatePtr->IsRxBusy = FALSE;
    UartStatePtr->RxSize = 0U;
}

CDDUART_FUNC  void UART_Lld_TxEmptyIrqHandler(uint8 Instance)
{
    const Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    UART_Type *Base = Uart_UartBase[Instance];
    /* Exit if there is no transmission in progress */
    if (TRUE == UartStatePtr->IsTxBusy)
    {
        /* Check if there are any more bytes to send */
        if (UartStatePtr->TxSize > 0U)
        {
            /* Transmit the data */
            UART_Lld_PutData(Instance);
        }
        else
        {
            /* Invoke the callback when the buffer is finished;
             * Application can provide another buffer inside the callback by calling LINFlexD_UART_Lld_SetTxBuffer
             */
            if (UartStatePtr->TxCallback != NULL_PTR)
            {
                UartStatePtr->TxCallback(UartStatePtr->TxCallbackParam, UART_EVENT_TX_EMPTY);
            }
            /* If there is no more data to send, complete the transmission */
            if (0U == UartStatePtr->TxSize)
            {
                UART_SetIntMode(Base, UART_INT_TX_DATA_REG_EMPTY, FALSE);
                UART_SetIntMode(Base, UART_INT_TX_COMPLETE, TRUE);
                /* Call the callback to notify application that the transfer is complete */
                if (UartStatePtr->TxCallback != NULL_PTR)
                {
                    UartStatePtr->TxCallback(UartStatePtr->TxCallbackParam, UART_EVENT_END_TX);
                }
                /* Clear the flag */
            }
        }
    }
}

CDDUART_FUNC  void UART_Lld_TxCompleteIrqHandler(uint8 Instance)
{
    const Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    if (0U == UartStatePtr->TxSize)
    {
        if (UartStatePtr->TxTransferType == UART_USING_INTERRUPTS)
        {
            /* Complete the interrupt Based transfer */
            UART_Lld_CompleteSendDataUsingInt(Instance);
        }
#if (STD_ON == CDDUART_DMA_USED)
        else
        {
            /* Complete the DMA Based transfer */
            UART_Lld_StopTxDma(Instance);
        }
#endif
        /* Invoke callback if there is one */
        if (UartStatePtr->TxCallback != NULL_PTR)
        {
            UartStatePtr->TxCallback(UartStatePtr->TxCallbackParam, UART_EVENT_END_TX);
        }
    }
}

CDDUART_FUNC  void UART_Lld_ErrIrqHandler(uint8 Instance)
{
    Uart_UartStateType *UartStatePtr = &Uart_UartStatePtr[Instance];
    UART_Type *Base = Uart_UartBase[Instance];
    /* Handle receive overrun interrupt */
    /*GCOVR_EXCL_START*/
    if ((TRUE == UART_GetStatusFlag(Base, UART_RX_OVERRUN)) &&
            (TRUE == UART_GetIntMode(Base, UART_INT_RX_OVERRUN)))
    {
        /* Update the internal status */
        UartStatePtr->ReceiveStatus = CDDUART_STATUS_RX_OVERRUN_ERROR;
        if (UartStatePtr->RxTransferType == UART_USING_INTERRUPTS)
        {
            /* Complete the transfer (disable rx logic) */
            UART_Lld_CompleteReceiveDataUsingInt(Instance);
        }
#if (STD_ON == CDDUART_DMA_USED)
        else
        {
            /* Complete the transfer (stop DMA channel) */
            UART_Lld_StopRxDma(Instance);
        }
#endif
        /* Invoke callback if there is one */
        if (UartStatePtr->RxCallback != NULL_PTR)
        {
            UartStatePtr->RxCallback(UartStatePtr->RxCallbackParam, UART_EVENT_ERROR);
        }
    }
    /* Handle framing error interrupt */
    if ((TRUE == UART_GetStatusFlag(Base, UART_FRAME_ERR)) &&
            (TRUE == UART_GetIntMode(Base, UART_INT_FRAME_ERR)))
    {
        /* Update the internal status */
        UartStatePtr->ReceiveStatus = CDDUART_STATUS_FRAMING_ERROR;
        if (UartStatePtr->RxTransferType == UART_USING_INTERRUPTS)
        {
            /* Complete the transfer (disable rx logic) */
            UART_Lld_CompleteReceiveDataUsingInt(Instance);
        }
#if (STD_ON == CDDUART_DMA_USED)
        else
        {
            /* Complete the transfer (stop DMA channel) */
            UART_Lld_StopRxDma(Instance);
        }
#endif
        /* Invoke callback if there is one */
        if (UartStatePtr->RxCallback != NULL_PTR)
        {
            UartStatePtr->RxCallback(UartStatePtr->RxCallbackParam, UART_EVENT_ERROR);
        }
    }
    /* Handle parity error interrupt */
    if ((TRUE == UART_GetStatusFlag(Base, UART_PARITY_ERR)) &&
            (TRUE == UART_GetIntMode(Base, UART_INT_PARITY_ERR)))
    {
        /* Update the internal status */
        UartStatePtr->ReceiveStatus = CDDUART_STATUS_PARITY_ERROR;
        if (UartStatePtr->RxTransferType == UART_USING_INTERRUPTS)
        {
            /* Complete the transfer (disable rx logic) */
            UART_Lld_CompleteReceiveDataUsingInt(Instance);
        }
#if (STD_ON == CDDUART_DMA_USED)
        else
        {
            /* Complete the transfer (stop DMA channel) */
            UART_Lld_StopRxDma(Instance);
        }
#endif
        /* Invoke callback if there is one */
        if (UartStatePtr->RxCallback != NULL_PTR)
        {
            UartStatePtr->RxCallback(UartStatePtr->RxCallbackParam, UART_EVENT_ERROR);
        }
    }
    /* Handle noise error interrupt */
    if ((TRUE == UART_GetStatusFlag(Base, UART_NOISE_DETECT)) &&
            (TRUE == UART_GetIntMode(Base, UART_INT_NOISE_ERR)))
    {
        /* Update the internal status */
        UartStatePtr->ReceiveStatus = CDDUART_STATUS_NOISE_ERROR;
        if (UartStatePtr->RxTransferType == UART_USING_INTERRUPTS)
        {
            /* Complete transfer (disable rx logic) */
            UART_Lld_CompleteReceiveDataUsingInt(Instance);
        }
#if (STD_ON == CDDUART_DMA_USED)
        else
        {
            /* Complete the transfer (stop DMA channel) */
            UART_Lld_StopRxDma(Instance);
        }
#endif
        /* Invoke callback if there is one */
        if (UartStatePtr->RxCallback != NULL_PTR)
        {
            UartStatePtr->RxCallback(UartStatePtr->RxCallbackParam, UART_EVENT_ERROR);
        }
        /*GCOVR_EXCL_STOP*/
    }
    /* Clear the flags */
    UART_Lld_ClearErrorFlags(Base);
}



#ifdef __cplusplus
}
#endif
#define CDDUART_STOP_SEC_CODE
#include "CddUart_MemMap.h"

