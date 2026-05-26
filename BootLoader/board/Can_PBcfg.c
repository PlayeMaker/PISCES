/*
 * Copyright 2020-2025 Yuntu Microelectronics Co., Ltd.
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

CAN_CONST const Can_FilterOfStdFifoType StdRxFifoFltConfig_0_MCMD[4] =
{
    {
        .FilterCodeStd1 = 0x7FFU,
        .FilterCodeStd2 = 0x623U,
        .EnhanceRxFifoFilterFormat = CAN_FILTER_FORMAT_ACC_MASK_MODE
    },
    {
        .FilterCodeStd1 = 0x7FFU,
        .FilterCodeStd2 = 0x601U,
        .EnhanceRxFifoFilterFormat = CAN_FILTER_FORMAT_ACC_MASK_MODE
    },
    {
        .FilterCodeStd1 = 0x7FFU,
        .FilterCodeStd2 = 0x120U,
        .EnhanceRxFifoFilterFormat = CAN_FILTER_FORMAT_ACC_MASK_MODE
    },
    {
        .FilterCodeStd1 = 0x7FFU,
        .FilterCodeStd2 = 0x110U,
        .EnhanceRxFifoFilterFormat = CAN_FILTER_FORMAT_ACC_MASK_MODE
    },
};

CAN_CONST const Can_FilterOfStdFifoType StdRxFifoFltConfig_0_MCMP[4] =
{
    {
        .FilterCodeStd1 = 0x7FFU,
        .FilterCodeStd2 = 0x624U,
        .EnhanceRxFifoFilterFormat = CAN_FILTER_FORMAT_ACC_MASK_MODE
    },
    {
        .FilterCodeStd1 = 0x7FFU,
        .FilterCodeStd2 = 0x601U,
        .EnhanceRxFifoFilterFormat = CAN_FILTER_FORMAT_ACC_MASK_MODE
    },
    {
        .FilterCodeStd1 = 0x7FFU,
        .FilterCodeStd2 = 0x140U,
        .EnhanceRxFifoFilterFormat = CAN_FILTER_FORMAT_ACC_MASK_MODE
    },
    {
        .FilterCodeStd1 = 0x7FFU,
        .FilterCodeStd2 = 0x130U,
        .EnhanceRxFifoFilterFormat = CAN_FILTER_FORMAT_ACC_MASK_MODE
    },
};

CAN_CONST const Can_EnhanceRxFifoConfigType Can_EnhanceRxFifoConfig_0[2] =
{
    {
        .EnhanceRxFifoWatermarkNum = 1U,
        .ExtRxFifoFilterNum = 0U,
        .StdRxFifoFilterNum = 4U,
        .ExtRxFifoFltConfigPtr = NULL_PTR,
        .StdRxFifoFltConfigPtr = StdRxFifoFltConfig_0_MCMD,
    },
    {
        .EnhanceRxFifoWatermarkNum = 1U,
        .ExtRxFifoFilterNum = 0U,
        .StdRxFifoFilterNum = 4U,
        .ExtRxFifoFltConfigPtr = NULL_PTR,
        .StdRxFifoFltConfigPtr = StdRxFifoFltConfig_0_MCMP,
    },
};
#endif/*#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)*/
#if (CAN_LEGACY_FIFO_USAGE == STD_ON)

#endif/*#if (CAN_LEGACY_FIFO_USAGE == STD_ON)*/

#if (CAN_FD_USAGE == STD_ON)
CAN_CONST const CAN_FdBdrConfigType Can_FdBdrConfig_0[1] =
{
    {
        .CanFdBaudrate      = 2000U,
        .CanFdTxBdrSwitch   = TRUE,
        .CanFdPreDiv        = 2U,
        .CanFdPropSeg       = 8U,
        .CanFdSeg1          = 7U,
        .CanFdSeg2          = 4U,
        .CanFdSyncJumpWidth = 4U,
        .CanFdTdcOffset     = 16U
    },
};
#endif



CAN_CONST const Can_BdrConfigType CanControllerBaudrateConfig_0[1] = 
{
    {
        .CanBaudrateConfigID = 0U,
        .CanBaudrate         = 500U,
        .CanPreDiv           = 2U,
        .CanPropSeg          = 47U,
        .CanSeg1             = 16U,
        .CanSeg2             = 16U,
        .CanSyncJumpWidth    = 16U,
#if (CAN_FD_USAGE == STD_ON)
        .CanFdBdrConfig = (const CAN_FdBdrConfigType *)&Can_FdBdrConfig_0[0],
#endif
    },
};

CAN_CONST const Can_MbRegionConfigType MbRegionConfig_0[2] =
{
    {
        .MbPlSizeType     = CAN_PLSIZE_64_BYTES,
        .MbMsgBufferNum   = 7U,
        .PayloadSize      = 64U,
        .PayloadRamLength = 72U
    },
    {
        .MbPlSizeType     = CAN_PLSIZE_64_BYTES,
        .MbMsgBufferNum   = 7U,
        .PayloadSize      = 64U,
        .PayloadRamLength = 72U
    },
};


CAN_CONST const Can_PayloadConfigType    Can_PayloadConfig_0_MCMD =
{
    .MbRegionNum     = (Can_HwObjRegionType)2U,
    .MbRegionConfig  = MbRegionConfig_0,
    .ChPayloadMaxNum = 14U,
    .RxFifoType      = CAN_RX_FIFO_ENHANCE,
#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)
    .EnhanceRxFifoConfigPtr = &Can_EnhanceRxFifoConfig_0[0], /*!< Point the rx fifo config */
#endif
#if (CAN_LEGACY_FIFO_USAGE == STD_ON)
    .LegacyRxFifoConfigPtr  = NULL_PTR,
#endif
};

CAN_CONST const Can_PayloadConfigType    Can_PayloadConfig_0_MCMP =
{
    .MbRegionNum     = (Can_HwObjRegionType)2U,
    .MbRegionConfig  = MbRegionConfig_0,
    .ChPayloadMaxNum = 14U,
    .RxFifoType      = CAN_RX_FIFO_ENHANCE,
#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)
    .EnhanceRxFifoConfigPtr = &Can_EnhanceRxFifoConfig_0[1], /*!< Point the rx fifo config */
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
        .UsePolling        = TRUE,
        .PollingPeriodId   = 0U,
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
        .UsePolling        = TRUE,
        .PollingPeriodId   = 0U,
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

#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
CAN_CONST const Can_HohPolTableType Can_HrhPolTable_0[1] =
{
    {
        .CanHohId          = 0U,
        .CanDiagAddr0      = (volatile uint32 *)(0x40030000U + 0x0C14),
        .CanDiagMask0      = 0xF0000000,
        .CanDiagAddr1      = (volatile uint32 *)(NULL_PTR),
        .CanDiagMask1      = 0x00000000,
    },
};

CAN_CONST const Can_HohPolPeriodType CanHrhPolPeriodTable[1] =
{
    /* Polling Name: CanMainFunctionRWPeriods_0 */
    {
        .CanPeriodId       = 0U,
        .CanHohNum         = 1U,
        .CanPolTablePtr    = Can_HrhPolTable_0,
    },
};
#endif

#if (CAN_TX_PROCESS_HAS_POLLING == STD_ON)
CAN_CONST const Can_HohPolTableType Can_HthPolTable_0[1] =
{
    {
        .CanHohId          = 1U,
        .CanDiagAddr0      = (volatile uint32 *)(0x40030000U + 0x30U),
        .CanDiagMask0      = 0x1U,
        .CanDiagAddr1      = (volatile uint32 *)(NULL_PTR),
        .CanDiagMask1      = 0x00000000,
    },
};

CAN_CONST const Can_HohPolPeriodType CanHthPolPeriodTable[1] =
{
    /* Polling Name: CanMainFunctionRWPeriods_0 */
    {
        .CanPeriodId       = 0U,
        .CanHohNum         = 1U,
        .CanPolTablePtr    = Can_HthPolTable_0,
    },
};
#endif


/**
 * @brief This map is used to translate the 'CAN hardware ID' to 'a logical ID'.
 */
CAN_CONST const uint8 Can_HwIdTable[8] = { 0U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,  };

/**
 * @brief This map is used to convert a mailbox flag ID to the HOH ID and region for CAN0.
 */
CAN_CONST const Can_MbFlagMatrixType Can_HwFlagMatrixConfig_0[14] =
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
        .CanHwObjId    = 0,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 8 */
    {
        .CanHwObjId    = 1,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 9 */
    {
        .CanHwObjId    = 2,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 10 */
    {
        .CanHwObjId    = 3,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 11 */
    {
        .CanHwObjId    = 4,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 12 */
    {
        .CanHwObjId    = 5,
        .CanHwRegionId = CAN_RAM_REGION_1,
        .CanHohId      = MB_NOT_USE,
    },
    /* Flag id: 13 */
    {
        .CanHwObjId    = 6,
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


CAN_CONST const Can_ChannelConfigType Can_ChannelConfig_MCMD[1] =
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
        .CanAutoBusoffRecovery   = TRUE,
        .CanRxProcessing         = CAN_PROCESS_POLLING,
        .CanTxProcessing         = CAN_PROCESS_POLLING,
        .CanBusoffProcessing     = CAN_PROCESS_POLLING,
#if (CAN_WAKEUP_SUPPORT == STD_ON)
        .CanWakeupProcessing     = CAN_PROCESS_INTERRUPT,
        .CanWakeupSupport        = FALSE,
        .EcuMWakeupSource        = (EcuM_WakeupSourceType)0,
#endif
#if (CAN_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .CanWakeupFunctionalityAPI = FALSE,
#endif
#if (CAN_FD_USAGE == STD_ON)
        .FdUsage                 = TRUE,
        .IsoModeUsage            = TRUE,
#endif
        .CanTimeQuantaSource     = CAN_CLOCK_SOURCE_PE,
        .ChBaudrateNum           = 1U,
        .DefaultBdrConfig        = &CanControllerBaudrateConfig_0[0],
        .BdrConfigPtr            = CanControllerBaudrateConfig_0,
        .PayloadConfigPtr        = &Can_PayloadConfig_0_MCMD,
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

CAN_CONST const Can_ChannelConfigType Can_ChannelConfig_MCMP[1] =
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
        .CanAutoBusoffRecovery   = TRUE,
        .CanRxProcessing         = CAN_PROCESS_POLLING,
        .CanTxProcessing         = CAN_PROCESS_POLLING,
        .CanBusoffProcessing     = CAN_PROCESS_POLLING,
#if (CAN_WAKEUP_SUPPORT == STD_ON)
        .CanWakeupProcessing     = CAN_PROCESS_INTERRUPT,
        .CanWakeupSupport        = FALSE,
        .EcuMWakeupSource        = (EcuM_WakeupSourceType)0,
#endif
#if (CAN_WAKEUP_FUNCTIONALITY_API == STD_ON)
        .CanWakeupFunctionalityAPI = FALSE,
#endif
#if (CAN_FD_USAGE == STD_ON)
        .FdUsage                 = TRUE,
        .IsoModeUsage            = TRUE,
#endif
        .CanTimeQuantaSource     = CAN_CLOCK_SOURCE_PE,
        .ChBaudrateNum           = 1U,
        .DefaultBdrConfig        = &CanControllerBaudrateConfig_0[0],
        .BdrConfigPtr            = CanControllerBaudrateConfig_0,
        .PayloadConfigPtr        = &Can_PayloadConfig_0_MCMP,
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
CAN_CONST const Can_ConfigType Can_Config[2] =
{
    {
        .CanChannelNum        = 1U,
        .CanHohNum            = 2U,
        .CanChCfgPtr          = Can_ChannelConfig_MCMD,
        .CanHohCfgPtr         = Can_HohConfig,
        .CanHwIdTable         = Can_HwIdTable,
    #if ((CAN_RX_PROCESS_HAS_POLLING == STD_ON) && (CAN_TX_PROCESS_HAS_POLLING == STD_ON))
        .CanPolPeriodNum      = 1,
    #endif
    #if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
        .CanHrhPolPeriodPtr   = CanHrhPolPeriodTable,
    #endif
    #if (CAN_TX_PROCESS_HAS_POLLING == STD_ON)
        .CanHthPolPeriodPtr   = CanHthPolPeriodTable,
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
    },
    {
        .CanChannelNum        = 1U,
        .CanHohNum            = 2U,
        .CanChCfgPtr          = Can_ChannelConfig_MCMP,
        .CanHohCfgPtr         = Can_HohConfig,
        .CanHwIdTable         = Can_HwIdTable,
    #if ((CAN_RX_PROCESS_HAS_POLLING == STD_ON) && (CAN_TX_PROCESS_HAS_POLLING == STD_ON))
        .CanPolPeriodNum      = 1,
    #endif
    #if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
        .CanHrhPolPeriodPtr   = CanHrhPolPeriodTable,
    #endif
    #if (CAN_TX_PROCESS_HAS_POLLING == STD_ON)
        .CanHthPolPeriodPtr   = CanHthPolPeriodTable,
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
    }
};

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

