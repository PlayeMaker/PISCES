/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Can_PBcfg.c
 * @brief 
 * 
 */


#ifdef __cplusplus
extern "C"{
#endif

/**
 * @page misra_violations MISRA-C:2012 violations
 */

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Can.h"
#include "Can_Drv.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_VENDOR_ID_PBCFG_C                      (180)
#define CAN_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define CAN_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define CAN_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define CAN_SW_MAJOR_VERSION_PBCFG_C               (0)
#define CAN_SW_MINOR_VERSION_PBCFG_C               (9)
#define CAN_SW_PATCH_VERSION_PBCFG_C               (1)

/*==================================================================================================
*                                         CALLBACKS
==================================================================================================*/



#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
CAN_FUNC __attribute__((weak)) boolean CanReceiveCallOut(uint8 Hrh, Can_IdType CanId, uint8 CanDataLegth, const uint8* CanSduPtr ){(void)Hrh; (void)CanId; (void)CanDataLegth; (void)CanSduPtr; return TRUE;}
CAN_FUNC __attribute__((weak)) void CanTransmitCallOut(PduIdType TxPduId){(void)TxPduId;}



#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"
/*==================================================================================================
*                                         CONSTANTS
==================================================================================================*/
#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"
#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)
CAN_CONST const Can_FilterOfExtFifoType ExtRxFifoFltConfig_0[1] =
{
    {
        .FilterCodeExt1 = 0x1FFFFFFFU,
        .FilterCodeExt2 = 0x0U,
        .EnhanceRxFifoFilterFormat = CAN_FILTER_FORMAT_ACC_RANG_MODE
    },
};

CAN_CONST const Can_FilterOfStdFifoType StdRxFifoFltConfig_0[2] =
{
    {
        .FilterCodeStd1 = 0x7FFU,
        .FilterCodeStd2 = 0x0U,
        .EnhanceRxFifoFilterFormat = CAN_FILTER_FORMAT_ACC_MASK_MODE
    },
    {
        .FilterCodeStd1 = 0x0U,
        .FilterCodeStd2 = 0x7FFU,
        .EnhanceRxFifoFilterFormat = CAN_FILTER_FORMAT_ACC_RANG_MODE
    },
};

CAN_CONST const Can_EnhanceRxFifoConfigType Can_EnhanceRxFifoConfig_0 =
{
    .EnhanceRxFifoWatermarkNum = 1U,
    .ExtRxFifoFilterNum = 1U,
    .StdRxFifoFilterNum = 2U,
    .ExtRxFifoFltConfigPtr = ExtRxFifoFltConfig_0,
    .StdRxFifoFltConfigPtr = StdRxFifoFltConfig_0,
};
#endif/*#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)*/
#if (CAN_LEGACY_FIFO_USAGE == STD_ON)

#endif/*#if (CAN_LEGACY_FIFO_USAGE == STD_ON)*/

#if (CAN_FD_USAGE == STD_ON)
#endif



CAN_CONST const Can_BdrConfigType CanControllerBaudrateConfig_0[1] = 
{
    {
        .CanBaudrateConfigID = 0U,
        .CanBaudrate         = 500U,
        .CanPreDiv           = 1U,
        .CanPropSeg          = 7U,
        .CanSeg1             = 5U,
        .CanSeg2             = 3U,
        .CanSyncJumpWidth    = 1U,
#if (CAN_FD_USAGE == STD_ON)
        .CanFdBdrConfig = NULL_PTR,
#endif
    },
};

CAN_CONST const Can_MbRegionConfigType MbRegionConfig_0[2] =
{
    {
        .MbPlSizeType     = CAN_PLSIZE_8_BYTES,
        .MbMsgBufferNum   = 32U,
        .PayloadSize      = 8U,
        .PayloadRamLength = 16U
    },
    {
        .MbPlSizeType     = CAN_PLSIZE_8_BYTES,
        .MbMsgBufferNum   = 32U,
        .PayloadSize      = 8U,
        .PayloadRamLength = 16U
    },
};


CAN_CONST const Can_PayloadConfigType    Can_PayloadConfig_0 =
{
    .MbRegionNum     = (Can_HwObjRegionType)2U,
    .MbRegionConfig  = MbRegionConfig_0,
    .ChPayloadMaxNum = 64U,
    .RxFifoType      = CAN_RX_FIFO_ENHANCE,
#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)
    .EnhanceRxFifoConfigPtr = &Can_EnhanceRxFifoConfig_0, /*!< Point the rx fifo config */
#endif
#if (CAN_LEGACY_FIFO_USAGE == STD_ON)
    .LegacyRxFifoConfigPtr  = NULL_PTR,
#endif
};




CAN_CONST const Can_HohConfigType Can_HohConfig[2] =
{
    {
        .CanObjId          = 0U,
        .CanChannelId      = 0U,
        .CanHwObjRegionId  = CAN_RX_FIFO_ENHANCE,
        .CanHwObjNum       = 20U,
        .ObjectType        = CAN_RECEIVE,
#if ((CAN_RX_PROCESS_HAS_POLLING == STD_ON) || (CAN_TX_PROCESS_HAS_POLLING == STD_ON))
        .UsePolling        = FALSE,
        .PollingPeriodId   = 255U,
#endif
#if (DEVELOPPING == STD_ON)
        .BasicFullType     = CAN_HANDLE_BASIC,
#endif
        .CanHwFlagStartId  = 255,
        .CanHwObjStartId = 255
    },
    {
        .CanObjId          = 1U,
        .CanChannelId      = 0U,
        .CanHwObjRegionId  = CAN_RAM_REGION_0,
        .CanHwObjNum       = 1U,
        .ObjectType        = CAN_TRANSMIT,
#if ((CAN_RX_PROCESS_HAS_POLLING == STD_ON) || (CAN_TX_PROCESS_HAS_POLLING == STD_ON))
        .UsePolling        = FALSE,
        .PollingPeriodId   = 255U,
#endif
#if (CAN_FD_USAGE == STD_ON)
        .CanFdPaddingValue = 0xccU,
#endif
#if (DEVELOPPING == STD_ON)
        .TrigTransEnable   = FALSE,
#endif
#if (DEVELOPPING == STD_ON)
        .BasicFullType     = CAN_HANDLE_BASIC,
#endif
        .CanHwFlagStartId  = 0,
        .CanHwObjStartId = 0
    },
};



/**
 * @brief This map is used to translate the 'CAN hardware ID' to 'a logical ID'.
 */
CAN_CONST const uint8 Can_HwIdTable[8] = { 0U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,  };

/**
 * @brief This map is used to convert a mailbox flag ID to the HOH ID and region for CAN0.
 */
CAN_CONST const Can_MbFlagMatrixType Can_HwFlagMatrixConfig_0[64] =
{
    /* Flag id: 0 */
    {
        .CanHwObjId    = 0,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = 1,
    },
    /* Flag id: 1 */
    {
        .CanHwObjId    = 1,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 2 */
    {
        .CanHwObjId    = 2,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 3 */
    {
        .CanHwObjId    = 3,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 4 */
    {
        .CanHwObjId    = 4,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 5 */
    {
        .CanHwObjId    = 5,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 6 */
    {
        .CanHwObjId    = 6,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 7 */
    {
        .CanHwObjId    = 7,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 8 */
    {
        .CanHwObjId    = 8,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 9 */
    {
        .CanHwObjId    = 9,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 10 */
    {
        .CanHwObjId    = 10,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 11 */
    {
        .CanHwObjId    = 11,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 12 */
    {
        .CanHwObjId    = 12,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 13 */
    {
        .CanHwObjId    = 13,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 14 */
    {
        .CanHwObjId    = 14,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 15 */
    {
        .CanHwObjId    = 15,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 16 */
    {
        .CanHwObjId    = 16,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 17 */
    {
        .CanHwObjId    = 17,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 18 */
    {
        .CanHwObjId    = 18,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 19 */
    {
        .CanHwObjId    = 19,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 20 */
    {
        .CanHwObjId    = 20,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 21 */
    {
        .CanHwObjId    = 21,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 22 */
    {
        .CanHwObjId    = 22,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 23 */
    {
        .CanHwObjId    = 23,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 24 */
    {
        .CanHwObjId    = 24,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 25 */
    {
        .CanHwObjId    = 25,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 26 */
    {
        .CanHwObjId    = 26,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 27 */
    {
        .CanHwObjId    = 27,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 28 */
    {
        .CanHwObjId    = 28,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 29 */
    {
        .CanHwObjId    = 29,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 30 */
    {
        .CanHwObjId    = 30,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 31 */
    {
        .CanHwObjId    = 31,
        .CanHwRegionId = CAN_RAM_REGION_0,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 32 */
    {
        .CanHwObjId    = 0,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 33 */
    {
        .CanHwObjId    = 1,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 34 */
    {
        .CanHwObjId    = 2,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 35 */
    {
        .CanHwObjId    = 3,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 36 */
    {
        .CanHwObjId    = 4,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 37 */
    {
        .CanHwObjId    = 5,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 38 */
    {
        .CanHwObjId    = 6,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 39 */
    {
        .CanHwObjId    = 7,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 40 */
    {
        .CanHwObjId    = 8,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 41 */
    {
        .CanHwObjId    = 9,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 42 */
    {
        .CanHwObjId    = 10,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 43 */
    {
        .CanHwObjId    = 11,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 44 */
    {
        .CanHwObjId    = 12,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 45 */
    {
        .CanHwObjId    = 13,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 46 */
    {
        .CanHwObjId    = 14,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 47 */
    {
        .CanHwObjId    = 15,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 48 */
    {
        .CanHwObjId    = 16,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 49 */
    {
        .CanHwObjId    = 17,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 50 */
    {
        .CanHwObjId    = 18,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 51 */
    {
        .CanHwObjId    = 19,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 52 */
    {
        .CanHwObjId    = 20,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 53 */
    {
        .CanHwObjId    = 21,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 54 */
    {
        .CanHwObjId    = 22,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 55 */
    {
        .CanHwObjId    = 23,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 56 */
    {
        .CanHwObjId    = 24,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 57 */
    {
        .CanHwObjId    = 25,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 58 */
    {
        .CanHwObjId    = 26,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 59 */
    {
        .CanHwObjId    = 27,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 60 */
    {
        .CanHwObjId    = 28,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 61 */
    {
        .CanHwObjId    = 29,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 62 */
    {
        .CanHwObjId    = 30,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 63 */
    {
        .CanHwObjId    = 31,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
};


/**
 * @brief This is callback enable list for CAN0
 */
CAN_CONST const Can_CallbackEntranceType Can_CallbackEntrance_0 =
{
#if ((CAN_LEGACY_FIFO_USAGE == STD_ON) || (CAN_ENHANCE_FIFO_USAGE == STD_ON))
    .ReceiveFifoFullCallback      = NULL_PTR,
    .ReceiveFifoOverflowCallback  = NULL_PTR,
#endif
    .OverrunCallback              = NULL_PTR,
    .WarningCallback              = NULL_PTR,
    .BusoffCallback               = NULL_PTR,
    .ErrorCallback                = NULL_PTR,
    .ErrFastCallback              = NULL_PTR,
    .ErrNceCallback               = NULL_PTR,
    .ErrCeCallback                = NULL_PTR,
#if (CAN_WAKEUP_SUPPORT == STD_ON)
    .WakeupCallback               = NULL_PTR,
#endif
#if (CAN_ICOM_USAGE == STD_ON)
    .IcomCallback                 = NULL_PTR,
#endif
};


CAN_CONST const Can_ChannelConfigType Can_ChannelConfig[1] =
{
    {
        .CanChannelId            = 0U,
        .CanHwChId               = FLEXCAN_0,
        .CanChActivation         = TRUE,
        .ChBaseAddr              = 0x40030000U,
        .CanTrippleSamp          = FALSE,
        /* Do not need to take care of 'CanAutoBusoffRecovery' param, The driver ensures that
           when a Busoff occurs, the Can controller will always enter the STOPPED state and
           has complied with MCAL requirements */
        .CanAutoBusoffRecovery   = FALSE,
        .CanRxProcessing         = CAN_PROCESS_INTERRUPT,
        .CanTxProcessing         = CAN_PROCESS_INTERRUPT,
        .CanBusoffProcessing     = CAN_PROCESS_INTERRUPT,
#if (CAN_WAKEUP_SUPPORT == STD_ON)
        .CanWakeupProcessing     = CAN_PROCESS_INTERRUPT,
        .CanWakeupSupport        = FALSE,
        .EcuMWakeupSource        = (EcuM_WakeupSourceType)0,
#endif
#if (CAN_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .CanWakeupFunctionalityAPI = FALSE,
#endif
#if (CAN_FD_USAGE == STD_ON)
        .FdUsage                 = FALSE,
        .IsoModeUsage            = TRUE,
#endif
        .CanTimeQuantaSource     = CAN_CLOCK_SOURCE_OSC,
        .ChBaudrateNum           = 1U,
        .DefaultBdrConfig        = &CanControllerBaudrateConfig_0[0],
        .BdrConfigPtr            = CanControllerBaudrateConfig_0,
        .PayloadConfigPtr        = &Can_PayloadConfig_0,
        .CanCallbackPtr          = &Can_CallbackEntrance_0,
        .CanFifoHrhId            = 0U,
        .CanHwFlagMatrixPtr      = Can_HwFlagMatrixConfig_0,
        .RamMbNum                = 64U,
        .RamIrmqEn               = TRUE,
#if (CAN_MEMECC_FEATURE == STD_ON)
        .RamEnhFifoEn            = TRUE,
        .RamHrTimeStmpEn         = FALSE,
        .RamEnhMbMemEn           = FALSE,
#endif
    },
};

/**
 * @brief CAN config
 */
CAN_CONST const Can_ConfigType Can_Config =
{
    .CanChannelNum        = 1U,
    .CanHohNum            = 2U,
    .CanChCfgPtr          = Can_ChannelConfig,
    .CanHohCfgPtr         = Can_HohConfig,
    .CanHwIdTable         = Can_HwIdTable,
#if ((CAN_RX_PROCESS_HAS_POLLING == STD_ON) && (CAN_TX_PROCESS_HAS_POLLING == STD_ON))
    .CanPolPeriodNum      = 0,
#endif
#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
    .CanHrhPolPeriodPtr   = NULL_PTR,
#endif
#if (CAN_TX_PROCESS_HAS_POLLING == STD_ON)
    .CanHthPolPeriodPtr   = NULL_PTR,
#endif
    .CanReceiveCallback   = CanReceiveCallOut,
    .CanTransmitCallback  = CanTransmitCallOut,
#if ((CAN_ENHANCE_FIFO_USAGE == STD_ON) || (CAN_LEGACY_FIFO_USAGE == STD_ON))
#if (CAN_FIFO_IDHIT_USAGE == STD_ON)
    .CanIdhitCallback     = NULL_PTR,
#endif
#endif
#if (CAN_ICOM_USAGE == STD_ON)
    .CanIcomNum           = 0U,
    .CanIcomCfgPtr        = NULL_PTR,
#endif
};

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

