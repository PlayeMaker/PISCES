/**
* @file    Adc_Lld_Eadc.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Eadc
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V0.9.1
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif
/*
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 0306 Rule 11.4: A conversion should not be performed between a pointer to object and an
 *                    integer type.
 *
 * PRQA S 0326 Rule 11.6: A cast shall not be performed between pointer to void and an arithmetic
 *                        type.
 *
 * PRQA S 3673 Rule 8.13: A pointer should point to a const-qualified type whenever possible.
 *
 * PRQA S 2985 Rule 2.2: There shall be no dead code.
 *
 * PRQA S 2986 Rule 2.2: There shall be no dead code.
 *
 * PRQA S 1505 Rule 8.7: Functions and objects should not be defined with external linkage
 *                       if they are referenced in only one translation unit
 * PRQA S 0488 Rule 18.4: The +, -, += and -= operators sho uld not be applied to an
 *                         expression of pointer type
 */
/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/
#include "Adc_Lld_Eadc.h"
#include "SchM_Adc.h"
#include "Adc_Lld_Reg.h"
#if defined(ADC_DMA_SUPPORTED)||(ADC_HIGH_PRIORITY_SEQ_DMA_SUPPORTED == STD_ON)
#include "CddDma.h"
#endif


/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_LLD_VENDOR_ID_C                      (180)
#define ADC_LLD_AR_RELEASE_MAJOR_VERSION_C       (4)
#define ADC_LLD_AR_RELEASE_MINOR_VERSION_C       (4)
#define ADC_LLD_AR_RELEASE_REVISION_VERSION_C    (0)
#define ADC_LLD_SW_MAJOR_VERSION_C               (0)
#define ADC_LLD_SW_MINOR_VERSION_C               (9)
#define ADC_LLD_SW_PATCH_VERSION_C               (1)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ADC_LLD header file are of the same vendor */
#if (ADC_LLD_VENDOR_ID_C != ADC_LLD_VENDOR_ID)
#error "Adc_Lld.c and Adc_Lld_Eadc.h have different vendor ids"
#endif

/* Check if source file and ADC_LLD header file are of the same Autosar version */
#if (( ADC_LLD_AR_RELEASE_MAJOR_VERSION_C != ADC_LLD_AR_RELEASE_MAJOR_VERSION) || \
      ( ADC_LLD_AR_RELEASE_MINOR_VERSION_C != ADC_LLD_AR_RELEASE_MINOR_VERSION) || \
      ( ADC_LLD_AR_RELEASE_REVISION_VERSION_C != ADC_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Adc_Lld_Eadc.c and Adc_Lld_Eadc.h are different"
#endif

/* Check if source file and ADC_LLD header file are of the same Software version */
#if (( ADC_LLD_SW_MAJOR_VERSION_C != ADC_LLD_SW_MAJOR_VERSION) || \
      ( ADC_LLD_SW_MINOR_VERSION_C != ADC_LLD_SW_MINOR_VERSION) || \
      ( ADC_LLD_SW_PATCH_VERSION_C != ADC_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Adc_Lld_Eadc.c and Adc_Lld_Eadc.h are different"
#endif

/* Check if source file and ADC_LLD_REG header file are of the same vendor */
#if (ADC_LLD_VENDOR_ID_C != ADC_LLD_REG_VENDOR_ID)
#error "Adc_Lld_Eadc.c and Adc_Lld_Reg.h have different vendor ids"
#endif

/* Check if source file and ADC_LLD_REG header file are of the same Autosar version */
#if (( ADC_LLD_AR_RELEASE_MAJOR_VERSION_C != ADC_LLD_REG_AR_RELEASE_MAJOR_VERSION) || \
      ( ADC_LLD_AR_RELEASE_MINOR_VERSION_C != ADC_LLD_REG_AR_RELEASE_MINOR_VERSION) || \
      ( ADC_LLD_AR_RELEASE_REVISION_VERSION_C != ADC_LLD_REG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Adc_Lld_Eadc.c and Adc_Lld_Reg.h are different"
#endif

/* Check if source file and ADC_LLD_REG header file are of the same Software version */
#if (( ADC_LLD_SW_MAJOR_VERSION_C != ADC_LLD_REG_SW_MAJOR_VERSION) || \
      ( ADC_LLD_SW_MINOR_VERSION_C != ADC_LLD_REG_SW_MINOR_VERSION) || \
      ( ADC_LLD_SW_PATCH_VERSION_C != ADC_LLD_REG_SW_PATCH_VERSION))
#error "Software Version Numbers of Adc_Lld_Eadc.c and Adc_Lld_Reg.h are different"
#endif


/*==================================================================================================
                                                GLOBAL VARIABLES
==================================================================================================*/
/* Declare the pointer to the ADC configuration structure */
extern const Adc_ConfigType *Adc_ConfigPtr;

/*ADC hw status data*/
extern Adc_UnitStatusType Adc_HwStatus[ADC_MAX_HW_UNITS];

/*ADC conversion result buffer*/
#if(ADC_FIXED_PB_CONFIG == STD_ON)
extern Adc_GroupResultType     Adc_GroupResult[ADC_GROUP_NUMBER];
#else
extern Adc_GroupResultType     Adc_GroupResult[ADC_MAX_GROUPS];
#endif

#define ADC_START_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"
ADC_CONST static volatile eADC_Type *const Adc_RegBase[eADC_INSTANCE_COUNT] = eADC_BASE_PTRS;
#define ADC_STOP_SEC_CONST_UNSPECIFIED
#include "Adc_MemMap.h"
/*==================================================================================================
                                                LOCAL VARIABLES
==================================================================================================*/
#if defined(ADC_DMA_SUPPORTED)||(ADC_HIGH_PRIORITY_SEQ_DMA_SUPPORTED == STD_ON)
#define ADC_START_SEC_VAR_CLEARED_32
#include "Adc_MemMap.h"
ADC_VAR static CddDma_TransferConfigType Adc_DmaTransferConfig[ADC_MAX_HW_UNITS];
#define ADC_STOP_SEC_VAR_CLEARED_32
#include "Adc_MemMap.h"
#endif
/*==================================================================================================
                                                LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                LOCAL MACROS
==================================================================================================*/
#define ADC_MAX_CHANNEL_IN_GROUP    16U

#define ADC_TWO_BYTE                2U

#define ADC_MAX_UINT16              0xFFFFU

/*Reset value for adc registers*/
#define ADC_RESET_ZERO_VALUE        0x00000000U
#define ADC_RESET_ONE_VALUE         0xFFFFFFFFU
#if defined (CPU_YTM32B1MD2)
#define ADC_CFG0_DEFAULT_VALUE      0x0F000F00U
#else
#endif
#define ADC_CFG1_DEFAULT_VALUE      0x000800C0U
#define ADC_SMP_DEFAULT_VALUE       0x00000202U
#define ADC_WDTH_DEFAULT_VALUE      0x0FFF0000U
#define ADC_CHNSEL_DEFAULT_VALUE    (uint8)0x00U

/*==================================================================================================
                                                LOCAL FUNCTIONS
==================================================================================================*/
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"

/**
 * @brief   Set ADC CFG1 register
 * @details This function sets the ADC CFG1 register with the provided configuration.The CFG1 register
 *          contains the sample average, switch channel counter, and startup time settings.
 * @param[out]   PtrAdcBase ADC base address pointer
 * @param[in]    SwitchChannelCounter ADC switch channel counter
 * @return       void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetCFG1(volatile eADC_Type *PtrAdcBase, const Adc_HwUnitType *AdcHwUnitPtr)
{
    uint32 Temp = 0;
    Temp  = eADC_CFG1_SMPAVGE(AdcHwUnitPtr->AdcResultsAveragedTimes) | \
            eADC_CFG1_SWITCHCNT(AdcHwUnitPtr->SwitchChannelCounter) | \
            eADC_CFG1_STCNT(AdcHwUnitPtr->StartupTime);
    PtrAdcBase->CFG1 = Temp;
}

/**
 * @brief   Set ADC sample time register
 * @details This function sets the ADC sample time register with the provided sample time.
 * @param[out]   PtrAdcBase ADC base address pointer
 * @param[in]    SampleTime ADC sample time
 * @return       void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetSampleTime(volatile eADC_Type *PtrAdcBase, uint32 SampleTime)
{
    PtrAdcBase->SMP = SampleTime;
}

/*!
 * @brief Sets the sequence channel ID by sequence index
 * @param[in] PtrAdcBase adc base pointer
 * @param[in] ChselIdx Sequence index
 * @param[in] ChannelId channel id
 * @return void
 */
ADC_FUNC LOCAL_INLINE void ADC_Lld_SetSequeceChannel(volatile eADC_Type *PtrAdcBase,
        uint8 ChselIdx,
        uint16 ChannelId)
{
    if (ChselIdx < ADC_MAX_CHANNEL_IN_GROUP)
    {
        PtrAdcBase->CHSEL[ChselIdx] = (uint8)ChannelId;
    }
}



/**
 * @brief   Set ADC stop conversion
 * @param[out]   PtrAdcBase ADC base address pointer
 * @return       void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetStopConversion(volatile eADC_Type *PtrAdcBase)
{
    PtrAdcBase->CTRL |= eADC_CTRL_ADSTOP_MASK;
}

/**
 * @brief   Get ADC stop status
 * @param[out]   PtrAdcBase ADC base address pointer
 * @return       Boolean
*/
ADC_FUNC LOCAL_INLINE boolean Adc_Lld_GetStopStatus(volatile eADC_Type const   *PtrAdcBase)
{
    return (boolean)((PtrAdcBase->CTRL & eADC_CTRL_ADSTOP_MASK) >> eADC_CTRL_ADSTOP_SHIFT);
}

/**
 * @brief   Set ADC start conversion
 * @param[out]   PtrAdcBase ADC base address pointer
 * @return       void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetStartConversion(volatile eADC_Type *PtrAdcBase)
{
    PtrAdcBase->CTRL |= eADC_CTRL_ADSTART_MASK;
}

/**
 * @brief   Get ADC start status
 * @param[out]   PtrAdcBase ADC base address pointer
 * @return       Boolean
*/
ADC_FUNC LOCAL_INLINE boolean Adc_Lld_GetStartConversion(volatile eADC_Type const   *PtrAdcBase)
{
    return (boolean)((PtrAdcBase->CTRL & eADC_CTRL_ADSTART_MASK) >> eADC_CTRL_ADSTART_SHIFT);
}

/**
 * @brief  Set the ADDIS to disable ADC unit
 * @param[out]  PtrAdcBase ADC base address pointer
 * @return  void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetADDIS(volatile eADC_Type *PtrAdcBase)
{
    PtrAdcBase->CTRL |= eADC_CTRL_ADDIS_MASK;
}

/**
 * @brief  Get ADCx Disable or not.
 * @param[in]  PtrAdcBase ADC base address pointer
 * @return  boolean
*/
ADC_FUNC LOCAL_INLINE boolean Adc_Lld_GetADDISStatus(volatile eADC_Type const *PtrAdcBase)
{
    return (boolean)((PtrAdcBase->CTRL & eADC_CTRL_ADDIS_MASK) >> eADC_CTRL_ADDIS_SHIFT);
}

/**
 * @brief  Set TSEN to enable tempreture sensor
 * @param[out]  PtrAdcBase ADC base address pointer
 * @param[in]   EnableTSEN enable or disable tempreture sensor
 * @return  void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetTSEN(volatile eADC_Type *PtrAdcBase, boolean EnableTSEN)
{
    uint32 Temp = PtrAdcBase->CTRL;
    if (TRUE == EnableTSEN)
    {
        Temp |= eADC_CTRL_TSEN_MASK;
    }
    else
    {
        Temp &= ~eADC_CTRL_TSEN_MASK;
    }
    PtrAdcBase->CTRL = Temp;
}

/**
 * @brief  Set ADEN to enable ADC unit
 * @param[out]  PtrAdcBase ADC base address pointer
 * @return  void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_SetADEN(volatile eADC_Type *PtrAdcBase)
{
    PtrAdcBase->CTRL |= eADC_CTRL_ADEN_MASK;
}
/**
 * @brief  Get ADCx Enable or not.
 * @param[in]  PtrAdcBase ADC base address pointer
 * @return  boolean
*/
ADC_FUNC LOCAL_INLINE boolean Adc_Lld_GetADEN(volatile eADC_Type const *PtrAdcBase)
{
    return (boolean)((PtrAdcBase->CTRL & eADC_CTRL_ADEN_MASK) >> eADC_CTRL_ADEN_SHIFT);
}
/**
 * @brief  Get ADCx End of Sequence Interrupt Flag
 * @param[in]  PtrAdcBase ADC base address pointer
 * @return  boolean
*/
ADC_FUNC LOCAL_INLINE boolean Adc_Lld_GetEOSEQIntFlag(volatile eADC_Type const *PtrAdcBase)
{
    uint32 Temp = PtrAdcBase->STS;
    boolean Ret = FALSE;
    Temp = (Temp & eADC_STS_LEOSEQ_MASK) >> eADC_STS_LEOSEQ_SHIFT;
    if (Temp != 0u)
    {
        Ret = TRUE;
    }
    return Ret;
}

/**
 * @brief  Clear ADCx End of Sequence Interrupt Flag
 * @param[in]  PtrAdcBase ADC base address pointer
 * @return  void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_ClearEOSEQIntFlag(volatile eADC_Type *PtrAdcBase)
{
    PtrAdcBase->STS = eADC_STS_LEOSEQ_MASK;
}

/**
 * @brief Reset all registers to power on default value
 * @param[out] PtrAdcBase adc base pointer
 * @return void
*/
ADC_FUNC LOCAL_INLINE void Adc_Lld_ResetRegister(volatile eADC_Type *PtrAdcBase)
{
    PtrAdcBase->CTRL = ADC_RESET_ZERO_VALUE;
    PtrAdcBase->STS = ADC_RESET_ONE_VALUE;
    PtrAdcBase->OVRSTS = ADC_RESET_ONE_VALUE;
    PtrAdcBase->INTE = ADC_RESET_ZERO_VALUE;
    PtrAdcBase->CFG0 = ADC_CFG0_DEFAULT_VALUE;
    PtrAdcBase->CFG1 = ADC_CFG1_DEFAULT_VALUE;
    PtrAdcBase->SMP  = ADC_SMP_DEFAULT_VALUE;
    PtrAdcBase->WDCTRL = ADC_RESET_ZERO_VALUE;
    for (uint8 LoopCnt = 0; LoopCnt < eADC_WDTH_COUNT; ++LoopCnt)
    {
        PtrAdcBase->WDTH[LoopCnt] = ADC_WDTH_DEFAULT_VALUE;
    }
    for (uint8 LoopCnt = 0; LoopCnt < ADC_MAX_CHANNEL_IN_GROUP; ++LoopCnt)
    {
        PtrAdcBase->CHSEL[LoopCnt] = ADC_CHNSEL_DEFAULT_VALUE;
        PtrAdcBase->DATA[LoopCnt] = ADC_RESET_ZERO_VALUE;
    }
}
ADC_FUNC LOCAL_INLINE uint32 Adc_Lld_HighPriSeqCfg(Adc_HighPrioritySeqLengthCfgType HighPriSeqNum)
{
    uint32 Temp = 0U;
    switch (HighPriSeqNum)
    {
        case HIGH_PRIORITY_SEQ_HAS_1_CHANNEL:
            Temp = eADC_CFG0_SEQCFG(0) | eADC_CFG0_HSEQSEL(1);
            break;
        case HIGH_PRIORITY_SEQ_HAS_2_CHANNEL:
            Temp = eADC_CFG0_SEQCFG(1) | eADC_CFG0_HSEQSEL(0);
            break;
        case HIGH_PRIORITY_SEQ_HAS_4_CHANNEL:
            Temp = eADC_CFG0_SEQCFG(2) | eADC_CFG0_HSEQSEL(0);
            break;
        case HIGH_PRIORITY_SEQ_HAS_8_CHANNEL:
            Temp = eADC_CFG0_SEQCFG(3) | eADC_CFG0_HSEQSEL(0);
            break;
        case HIGH_PRIORITY_SEQ_HAS_12_CHANNEL:
            Temp = eADC_CFG0_SEQCFG(2) | eADC_CFG0_HSEQSEL(1);
            break;
        case HIGH_PRIORITY_SEQ_HAS_14_CHANNEL:
            Temp = eADC_CFG0_SEQCFG(1) | eADC_CFG0_HSEQSEL(1);
            break;
        case HIGH_PRIORITY_SEQ_HAS_15_CHANNEL:
            Temp = eADC_CFG0_SEQCFG(0) | eADC_CFG0_HSEQSEL(0);
            break;
        default:
            /* Do nothing */
            break;
    }
    return Temp;
}

ADC_FUNC LOCAL_INLINE void Adc_Lld_SetCFG0(volatile eADC_Type *PtrAdcBase, const Adc_HwUnitType *HwUnitCfg)
{
    uint32 Temp = 0U;
    /*Set high priority sequence length and seq select*/
    Temp |= Adc_Lld_HighPriSeqCfg(HwUnitCfg->HighPrioritySeqNum);
    Temp |= eADC_CFG0_HSEQLEN((uint8)(HwUnitCfg->HighPrioritySeqNum) - 1U);
    /*Set ADC conversion result alignment*/
    Temp |= eADC_CFG0_ALIGN(ADC_RESULT_ALIGNMENT);
    /*Set conversion mode*/
    Temp |= eADC_CFG0_MODE(0U);
    /*Set ADC prescaler*/
    Temp |= eADC_CFG0_PRS(HwUnitCfg->Prescale);
    /*set default low priority seq length*/
    Temp |= eADC_CFG0_LSEQLEN(((ADC_MAX_CHANNEL_IN_GROUP - HwUnitCfg->HighPrioritySeqNum) - 1U));
    /*Set low priority sequence trigger source to SW*/
    Temp |= eADC_CFG0_SFTTEN(1);
    PtrAdcBase->CFG0 = Temp;
}

#if defined(ADC_DMA_SUPPORTED)||(ADC_HIGH_PRIORITY_SEQ_DMA_SUPPORTED==STD_ON)
/*
 * @brief   Get the ADC hardware index in adc hardware unit condfiguration array.
 * @param[in]   AdcHwUnit ADC hardware unit
 * @return  uint8 ADC hardware index in hardware unit condfiguration array
*/
ADC_FUNC static uint8 Adc_Lld_HwIndexCaculate(uint8 AdcHwUnit)
{
    uint8 LoopCnt;
#if defined(CPU_YTM32B1HA0)||defined(CPU_YTM32B1ME0)
    for (LoopCnt = 0; LoopCnt < Adc_ConfigPtr->HwUnitCfgNum; ++LoopCnt)
    {
        if (Adc_ConfigPtr->HwUnitUserCfg[LoopCnt].HwUnitId == AdcHwUnit)
        {
            break;
        }
    }
#else
    LoopCnt = AdcHwUnit;
#endif
    return LoopCnt;
}

/**
 * @brief   Set Dma TCD for ADCx
 * @param[in]   AdcHwIndex ADC hardware index
 * @param[in]   VirtualChannel DMA virtual channel
 * @param[in]   DestAddr destination address
 * @param[in]   TransferCount transfer count in bytes
 * @return  void
*/
ADC_FUNC static void Adc_Lld_DmaTcdInit(uint8 AdcHwIndex, CddDma_ChannelType VirtualChannel, uint32 DestAddr, uint32 TransferCount, uint8 DataBufferBase)
{
    /*LOAD trancsfer configuration to TDC*/
    Adc_DmaTransferConfig[AdcHwIndex].SrcAddr = (uint32)(&(Adc_RegBase[AdcHwIndex]->DATA[DataBufferBase]));
    Adc_DmaTransferConfig[AdcHwIndex].DestAddr = DestAddr;
    Adc_DmaTransferConfig[AdcHwIndex].SrcTransferSize = DMA_TRANSFER_SIZE_2_BYTE;
    Adc_DmaTransferConfig[AdcHwIndex].DestTransferSize = DMA_TRANSFER_SIZE_2_BYTE;
    Adc_DmaTransferConfig[AdcHwIndex].SrcOffset = (sint16)((uint32)1U << ((uint8)DMA_TRANSFER_SIZE_4_BYTE));
    Adc_DmaTransferConfig[AdcHwIndex].DestOffset = (sint16)((uint32)1U << ((uint8)DMA_TRANSFER_SIZE_2_BYTE));
    Adc_DmaTransferConfig[AdcHwIndex].TransferLoopByteCount = TransferCount;
    Adc_DmaTransferConfig[AdcHwIndex].TriggerCount = 1u;
    (void)CddDma_SetLogicChannelTransfer(VirtualChannel, (uint32)(&(Adc_RegBase[AdcHwIndex]->DATA[DataBufferBase])), DestAddr, &Adc_DmaTransferConfig[AdcHwIndex]);
    /*Install the call back function for DMA transfer compeleted irq*/
    /* MR12 RULE 11.6 VIOLATION:In this specific case, needs to convert the Parameter to instance, thus, couldn't adhere
     *                           to M3CM Rule-11.6
     */
#if (ADC_HIGH_PRIORITY_SEQ_DMA_SUPPORTED==STD_ON)
    if (DataBufferBase == 0U)
    {
        CddDma_InstallCallback(VirtualChannel, Adc_Lld_HoSeqDmaNotification, (uint32)AdcHwIndex); /*PRQA S 0326*/
    }
#endif /*ADC_HIGH_PRIORITY_SEQ_DMA_SUPPORTED*/
#if defined (ADC_DMA_SUPPORTED)
    if (DataBufferBase != 0U)
    {
        CddDma_InstallCallback(VirtualChannel, Adc_Lld_DmaTransEndNotification, (uint32)AdcHwIndex); /*PRQA S 0326*/
    }
#endif /*ADC_DMA_SUPPORTED*/
    /*Start the DMA channel*/
    CddDma_StartChannel(VirtualChannel);
}

/**
 * @brief   Update the Dma TCD for ADCx
 * @param[in]   AdcHwIndex ADC hardware index
 * @param[in]   GroupIndex ADC group index
 * @return  void
*/
ADC_FUNC static void Adc_Lld_UpdataDmaTcdForGroup(uint8 AdcHwUnit, uint16 GroupIndex)
{
    uint32 DestAddr = 0;
    uint32 TransferCount = 0;
    uint8 DmaVirChannel = 0;
    uint8 BufferBase;
    uint8 ChannelNum = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum;
    TransferCount = ADC_TWO_BYTE * ((uint32)Adc_GroupResult[GroupIndex].GroupLoadChnNum);
    /* MR12 Rule 11.4 VIOLATION: In this specific case, the Adc result buffer address need use to configure
        *                           the DMA dest Parameter, couldn't adhere to M3CM Rule-11.4
        */
    /*PRQA S 0306 ++*/
    /*Modify the Dest address for a bug, when adc configured to hw trigger with DMA, if the result is not
    read before a new trigger signal generated, the dest address must minus 2*channel number.*/
    uint8 TempSampleCnt;
    if (Adc_GroupResult[GroupIndex].GroupSampleCount >= Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples)
    {
        TempSampleCnt = Adc_GroupResult[GroupIndex].GroupSampleCount - 1U;
    }
    else
    {
        TempSampleCnt = Adc_GroupResult[GroupIndex].GroupSampleCount;
    }
    /*NOSONAR - The Dma init function need a address for parameter ,not a pointer*/
    DestAddr = (uint32) & (Adc_GroupResult[GroupIndex].GroupValueBuf[(TempSampleCnt * ChannelNum) + Adc_GroupResult[GroupIndex].GroupCompChnNum]);/*NOSONAR */
    /*PRQA S 0306 --*/
    if (Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupTriggSrc == ADC_TRIGG_SRC_HW)
    {
        DmaVirChannel = Adc_ConfigPtr->HwUnitUserCfg[Adc_Lld_HwIndexCaculate(AdcHwUnit)].HighPriorityDmaChannel;
        BufferBase = 0U;
    }
    else
    {
#if defined(ADC_DMA_SUPPORTED)
        DmaVirChannel = Adc_ConfigPtr->HwUnitUserCfg[Adc_Lld_HwIndexCaculate(AdcHwUnit)].DmaChannel;
#endif /*ADC_DMA_SUPPORTED*/
        BufferBase = Adc_ConfigPtr->HwUnitUserCfg[Adc_Lld_HwIndexCaculate(AdcHwUnit)].HighPrioritySeqNum;
    }
    Adc_Lld_DmaTcdInit(AdcHwUnit, DmaVirChannel, DestAddr, TransferCount, BufferBase);
}
#endif/*ADC_DMA_SUPPORTED*/

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
 * @brief check the adc result is in the range
 * @param[out] GroupIndex adc group index
 * @param[in] TempResult the adc result
 * @return boolean TRUE:in the range;FALSE:out of the range
*/
ADC_FUNC static boolean Adc_Lld_LimitCheck(uint16 GroupIndex, uint16 TempResult)
{
    boolean LimitCheckResultFlag = FALSE;
    switch (Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelRangeSelect)
    {
        case ADC_RANGE_UNDER_LOW:
        {
            if (TempResult <= Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelLowLimit)
            {
                LimitCheckResultFlag = TRUE;
            }
        }
        break;
        case ADC_RANGE_BETWEEN:
        {
            if ((TempResult > Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelLowLimit) && \
                    (TempResult <= Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelHighLimit))
            {
                LimitCheckResultFlag = TRUE;
            }
        }
        break;
        case ADC_RANGE_OVER_HIGH:
        {
            if (TempResult > Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelHighLimit)
            {
                LimitCheckResultFlag = TRUE;
            }
        }
        break;
        case ADC_RANGE_NOT_UNDER_LOW:
        {
            if (TempResult > Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelLowLimit)
            {
                LimitCheckResultFlag = TRUE;
            }
        }
        break;
        case ADC_RANGE_NOT_BETWEEN:
        {
            if ((TempResult <= Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelLowLimit) || \
                    (TempResult > Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelHighLimit))
            {
                LimitCheckResultFlag = TRUE;
            }
        }
        break;
        case ADC_RANGE_NOT_OVER_HIGH:
        {
            if (TempResult <= Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelHighLimit)
            {
                LimitCheckResultFlag = TRUE;
            }
        }
        break;
        default:
        {
            LimitCheckResultFlag = TRUE;
        }
        break;
    }
    return LimitCheckResultFlag;
}
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */

#if (ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
/**
 * @brief This function is used to get the auto off state of the ADC hardware unit.
 * @param AdcHwUnit ADC hardware unit number.
 * @return boolean TRUE if the ADC hardware unit is in auto off state, FALSE otherwise.
 */
ADC_FUNC LOCAL_INLINE boolean Adc_Lld_GetAutoOff(uint8 AdcHwUnit)
{
    boolean AutoOff = FALSE;
    if ((Adc_RegBase[AdcHwUnit]->CFG0 & eADC_CFG0_AUTOOFF_MASK) != 0U)
    {
        AutoOff = TRUE;
    }
    return AutoOff;
}

/**
 * @brief Configures the auto off state of the ADC hardware unit.
 * @param AdcHwUnit ADC hardware unit number.
 * @param AutoOff TRUE if the ADC hardware unit is in auto off state, FALSE otherwise.
 * @return void
 */
ADC_FUNC static void Adc_Lld_AutoOffCfg(uint8 AdcHwUnit, boolean AutoOff)
{
    uint32 Temp = Adc_RegBase[AdcHwUnit]->CFG0;
    if (TRUE == AutoOff)
    {
        Temp |= eADC_CFG0_AUTOOFF_MASK;
    }
    else
    {
        Temp &= ~eADC_CFG0_AUTOOFF_MASK;
    }
    Adc_RegBase[AdcHwUnit]->CFG0 = Temp;
}
#endif /* ADC_LOW_POWER_STATES_SUPPORT == STD_ON */

/**
 * @brief  Disable ADC unit
 * @param[in]  AdcHwUnit Adc hardware index
 * @param[in]  TimeoutLimit timeout value
 * @return  void
 */
ADC_FUNC static void Adc_Lld_Disable(uint8 AdcHwUnit, uint32 TimeoutLimit)
{
    uint32 TimeOutCount = TimeoutLimit;
    Adc_Lld_SetADDIS(Adc_RegBase[AdcHwUnit]);
    while ((TRUE == Adc_Lld_GetADDISStatus(Adc_RegBase[AdcHwUnit])) && (TimeOutCount > 0u))
    {
        --TimeOutCount;
    }
}

/**
 * @brief  Enable ADC unit
 * @param[in] AdcHwIndex Adc hardware index
 * @param[in] TimeoutLimit timeout value
 * @return  void
*/
ADC_FUNC  static void Adc_Lld_Enable(uint8 AdcHwIndex, uint32 TimeoutLimit)
{
    uint32 TimeOutCount = TimeoutLimit;
    Adc_Lld_SetADEN(Adc_RegBase[AdcHwIndex]);
    while ((FALSE == Adc_Lld_GetADEN(Adc_RegBase[AdcHwIndex])) && (TimeOutCount > 0u))
    {
        --TimeOutCount;
    }
}

/**
 * @brief Reload data to Adc hardware and start conversion
 *
 * @param AdcHwIndex Adc hardware index
 * @return void
 */
ADC_FUNC static void Adc_Lld_RestartAdcHardWare(uint8 AdcHwIndex)
{
    uint16 Group = ADC_MAX_UINT16;
    uint16 GroupIndex = 0;
    Group = Adc_HwStatus[AdcHwIndex].SwNormalQueue[0];
    GroupIndex = Adc_Lld_GroupIndexCheck(Group);
    Adc_Lld_LoadGroupToHwUnit(AdcHwIndex, GroupIndex);
    Adc_Lld_StartConversion(AdcHwIndex);
}



/*==================================================================================================
                                                GLOBAL FUNCTIONS
==================================================================================================*/
/*************************************************************************************
*This function used to get the running group index.
**************************************************************************************/
ADC_FUNC uint16 Adc_Lld_GetRunningGroupIndex(uint8 AdcHwIndex)
{
    uint16 TempOnGoGroupIndex = ADC_MAX_UINT16;
    if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex >= 1u)
    {
        TempOnGoGroupIndex = Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].SwNormalQueue[0]);
    }
    return TempOnGoGroupIndex;
}

#if (ADC_HW_TRIGGER_API==STD_ON)
ADC_FUNC uint16 Adc_Lld_GetHoGroupIndex(uint8 AdcHwIndex)
{
    uint16 TempOnGoGroupIndex = ADC_MAX_UINT16;
    if (Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup != ADC_MAX_UINT16)
    {
        TempOnGoGroupIndex = Adc_Lld_GroupIndexCheck(Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup);
    }
    return TempOnGoGroupIndex;
}
#endif /* ADC_HW_TRIGGER_API==STD_ON */
/************************************************************************
 *                       Adc_Lld_InitTempSensor
************************************************************************/
ADC_FUNC void Adc_Lld_InitTempSensor(boolean TempSensorEnable)
{
    Adc_Lld_SetTSEN(Adc_RegBase[ADC_0], TempSensorEnable);
}

/************************************************************************
 *                       Adc_Lld_HwUnitEnable
************************************************************************/
ADC_FUNC void Adc_Lld_HwUnitEnable(uint8 AdcHwUnit)
{
    Adc_Lld_Enable(AdcHwUnit, ADC_TIMEOUT_VALUE);
}

/************************************************************************
 *                       Adc_Lld_HwClockInit
*************************************************************************/
ADC_FUNC void Adc_Lld_HwClockInit(const Adc_HwUnitType *HwUnitCfgPtr)
{
    volatile eADC_Type *PtrAdcBase = Adc_RegBase[HwUnitCfgPtr->HwUnitId];
    /* set ADC function clock prescaler*/
    Adc_Lld_SetCFG1(PtrAdcBase, HwUnitCfgPtr);
    /* set ADC sample time*/
    Adc_Lld_SetSampleTime(PtrAdcBase, HwUnitCfgPtr->SampleTime);
    /* set ADC CFG0*/
    Adc_Lld_SetCFG0(PtrAdcBase, HwUnitCfgPtr);
}

/************************************************************************
 *                       Adc_Lld_StopConversion
*************************************************************************/
ADC_FUNC void Adc_Lld_StopConversion(uint8 AdcHwUnit)
{
    uint32 TimeoutLimit = 0;
    TimeoutLimit = ADC_TIMEOUT_VALUE;
    if (Adc_RegBase[AdcHwUnit]->CTRL & eADC_CTRL_ADSTART_MASK)
    {
        Adc_Lld_SetStopConversion(Adc_RegBase[AdcHwUnit]);
        while ((TRUE == Adc_Lld_GetStopStatus(Adc_RegBase[AdcHwUnit])) && (TimeoutLimit > 0u))
        {
            --TimeoutLimit;
        }
    }
}

/************************************************************************
 *                       Adc_Lld_StartConversion
*************************************************************************/
ADC_FUNC void Adc_Lld_StartConversion(uint8 AdcHwUnit)
{
    if (FALSE == Adc_Lld_GetStartConversion(Adc_RegBase[AdcHwUnit]))
    {
#ifdef ADC_DMA_SUPPORTED
        /*Set Dma config if need*/
        uint16 GroupIndex = Adc_Lld_GetRunningGroupIndex(AdcHwUnit);
        if (ADC_DMA_ENABLED == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->IntcAndDmaCfg)
        {
            Adc_Lld_UpdataDmaTcdForGroup(AdcHwUnit, GroupIndex);
        }
#endif/*ADC_DMA_SUPPORTED*/
        Adc_Lld_SetStartConversion(Adc_RegBase[AdcHwUnit]);
    }
    else
    {
        /*do nothing*/
    }
}

/************************************************************************
 *                       Adc_Lld_DisableIntcandHwTrigger
*************************************************************************/
ADC_FUNC void Adc_Lld_DisableIntcandHwTrigger(uint8 AdcHwUnit)
{
    /* disable high priority sequence end interrupt*/
    Adc_RegBase[AdcHwUnit]->INTE &= ~eADC_INTE_HEOSEQIE_MASK;
#if (ADC_HIGH_PRIORITY_SEQ_DMA_SUPPORTED == STD_ON)
    /* disable high priority sequence DMA*/
    Adc_RegBase[AdcHwUnit]->CFG0 &= ~eADC_CFG0_HDMAEN_MASK;
#endif /* ADC_HIGH_PRIORITY_SEQ_DMA_SUPPORTED == STD_ON */
}

/************************************************************************
 *                       Adc_Lld_DeinitHwUnit
*************************************************************************/
ADC_FUNC void Adc_Lld_DeinitHwUnit(uint8 AdcHwUnit)
{
    Adc_Lld_StopConversion(AdcHwUnit);
    Adc_Lld_Disable(AdcHwUnit, ADC_TIMEOUT_VALUE);
    Adc_Lld_ResetRegister(Adc_RegBase[AdcHwUnit]);
}

/************************************************************************
 *                       Adc_Lld_ReadSeqConvEndIntFlag
*************************************************************************/
ADC_FUNC boolean Adc_Lld_ReadSeqConvEndIntFlag(uint8 AdcHwUnit)
{
    boolean Temp = FALSE;
    Temp = Adc_Lld_GetEOSEQIntFlag(Adc_RegBase[AdcHwUnit]);
    return Temp;
}

ADC_FUNC boolean Adc_Lld_ReadHoSeqConvEndIntFlag(uint8 AdcHwUnit)
{
    boolean Temp = FALSE;
    /* Read the high priority sequence end interrupt flag */
    if (((Adc_RegBase[AdcHwUnit]->STS & eADC_STS_HEOSEQ_MASK) >> eADC_STS_HEOSEQ_SHIFT) != 0u)
    {
        Temp = TRUE;
    }
    return Temp;
}

/************************************************************************
 *                       Adc_Lld_ClearSeqConvEndIntFlag
*************************************************************************/
ADC_FUNC void Adc_Lld_ClearSeqConvEndIntFlag(uint8 AdcHwUnit)
{
    Adc_Lld_ClearEOSEQIntFlag(Adc_RegBase[AdcHwUnit]);
}

ADC_FUNC void Adc_Lld_ClearHoSeqConvEndIntFlag(uint8 AdcHwUnit)
{
    /* Clear the high priority sequence end interrupt flag */
    Adc_RegBase[AdcHwUnit]->STS = eADC_STS_HEOSEQ_MASK;
}

/************************************************************************
 *                       Adc_Lld_ReadConversionResults
*************************************************************************/
#if (ADC_ENABLE_LIMIT_CHECK==STD_ON)
ADC_FUNC boolean Adc_Lld_ReadConversionResults(uint8 AdcHwUnit, uint16 GroupIndex, Adc_ValueGroupType *ResultBufPtr,
        uint16 ChannelCount, uint8 BaseBufferIndex)
{
    uint16 Temp = 0;
    boolean LimitCheckResultFlag = TRUE;
    for (uint8 InterLoopCount = 0; InterLoopCount < ChannelCount; ++InterLoopCount)
    {
        Temp = Adc_RegBase[AdcHwUnit]->DATA[InterLoopCount + BaseBufferIndex];
        if ((TRUE == Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelLimitCheck) && \
                (ADC_RANGE_ALWAYS != Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelRangeSelect) && \
                (FALSE == Adc_Lld_LimitCheck(GroupIndex, Temp)))
        {
            LimitCheckResultFlag = FALSE;
        }
    }
    return LimitCheckResultFlag;
}
#else
ADC_FUNC void Adc_Lld_ReadConversionResults(uint8 AdcHwUnit, Adc_ValueGroupType *ResultBufPtr,
        uint16 ChannelCount, uint8 BaseBufferIndex)
{
    for (uint8 InterLoopCount = 0; InterLoopCount < ChannelCount; ++InterLoopCount)
    {
        ResultBufPtr[InterLoopCount] = Adc_RegBase[AdcHwUnit]->DATA[InterLoopCount + BaseBufferIndex];
    }
}
#endif /* ADC_ENABLE_LIMIT_CHECK==STD_ON */


/************************************************************************
 *                       Adc_Lld_LoadGroupToHwUnit
*************************************************************************/
ADC_FUNC void Adc_Lld_LoadGroupToHwUnit(uint8 AdcHwUnit, uint16 GroupIndex)
{
    volatile eADC_Type *const PtrAdcBase = Adc_RegBase[AdcHwUnit];
    uint8 GroupChannelNum = 0u;
    uint32 TempReg = 0u;
    uint8 LowPrioritySeqNumBase = Adc_ConfigPtr->HwUnitUserCfg[AdcHwUnit].HighPrioritySeqNum;
    if (Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupTriggSrc == ADC_TRIGG_SRC_HW)
    {
        GroupChannelNum = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum;
        Adc_GroupResult[GroupIndex].GroupLoadChnNum = GroupChannelNum;
        /*Set high priority sequence*/
        for (uint8 InterLoopCount = 0; InterLoopCount < GroupChannelNum; ++InterLoopCount)
        {
            ADC_Lld_SetSequeceChannel(PtrAdcBase, InterLoopCount, \
                                      Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannels[Adc_GroupResult[GroupIndex].GroupCompChnNum + InterLoopCount]);
        }
#if (ADC_HIGH_PRIORITY_SEQ_DMA_SUPPORTED == STD_ON)
        /*Set Dma config if need*/
        if (ADC_DMA_ENABLED == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->IntcAndDmaCfg)
        {
            Adc_Lld_UpdataDmaTcdForGroup(AdcHwUnit, GroupIndex);
        }
#endif/*(ADC_HIGH_PRIORITY_SEQ_DMA_SUPPORTED == STD_ON)*/
        /* Clear all interrupt flag */
        PtrAdcBase->STS = eADC_STS_HEOSEQ_MASK;
        if (Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->IntcAndDmaCfg == ADC_DMA_ENABLED)
        {
            /*Set Dma configuration and high priority seq length*/
            PtrAdcBase->CFG0 |= eADC_CFG0_HDMAEN(TRUE) |
                                eADC_CFG0_HSEQLEN(GroupChannelNum - 1u);
            PtrAdcBase->INTE &= ~eADC_INTE_HEOSEQIE_MASK;
        }
        else
        {
            PtrAdcBase->CFG0 &= ~(eADC_CFG0_HDMAEN_MASK | eADC_CFG0_HSEQLEN_MASK);
            PtrAdcBase->CFG0 |= eADC_CFG0_HSEQLEN(GroupChannelNum - 1u) |
                                eADC_CFG0_HDMAEN(FALSE);
            /*enable high priority sequence end interrupt*/
            PtrAdcBase->INTE |= eADC_INTE_HEOSEQIE(1U);
        }
    }
    else
    {
        /*Stop ADC unit*/
        Adc_Lld_StopConversion(AdcHwUnit);
        /*get group channels number*/
        if (Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum > \
                (ADC_MAX_CHANNEL_IN_GROUP - LowPrioritySeqNumBase))
        {
            if ((0u == Adc_GroupResult[GroupIndex].GroupCompChnNum) || \
                    ((Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum - \
                      Adc_GroupResult[GroupIndex].GroupCompChnNum) > \
                     (ADC_MAX_CHANNEL_IN_GROUP - LowPrioritySeqNumBase)))
            {
                GroupChannelNum = (ADC_MAX_CHANNEL_IN_GROUP - LowPrioritySeqNumBase);
            }
            else
            {
                GroupChannelNum = (uint8)(Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum - \
                                          Adc_GroupResult[GroupIndex].GroupCompChnNum);
            }
        }
        else
        {
            GroupChannelNum = (uint8)Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum;
        }
        Adc_GroupResult[GroupIndex].GroupLoadChnNum = GroupChannelNum;
        /*Set conversion sequence*/
        for (uint8 InterLoopCount = 0; InterLoopCount < GroupChannelNum; ++InterLoopCount)
        {
            ADC_Lld_SetSequeceChannel(PtrAdcBase, InterLoopCount + LowPrioritySeqNumBase, \
                                      Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannels[Adc_GroupResult[GroupIndex].GroupCompChnNum + InterLoopCount]);
        }
        /**/
        TempReg = PtrAdcBase->CFG0;
        TempReg &= ~(eADC_CFG0_LDMAEN_MASK | eADC_CFG0_LSEQLEN_MASK);
        TempReg |= eADC_CFG0_LSEQLEN((GroupChannelNum - 1u));
        if (ADC_DMA_ENABLED == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->IntcAndDmaCfg)
        {
            /*Set Dma configuration and low priority seq length*/
            TempReg |= eADC_CFG0_LDMAEN(TRUE);
        }
        PtrAdcBase->CFG0 = TempReg;
        /* Clear all interrupt flag */
        PtrAdcBase->STS = eADC_STS_LEOSEQ_MASK;
        /* set ADC intc enable */
        /* SWS_Adc_00156 */
        if ((ADC_INTC_ENABLED == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->IntcAndDmaCfg) && ((PtrAdcBase->INTE & eADC_INTE_LEOSEQIE_MASK) == 0U))
        {
            PtrAdcBase->INTE |= eADC_INTE_LEOSEQIE(1U);
        }
        else if ((ADC_INTCANDDMA_DISABLED == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->IntcAndDmaCfg) && ((PtrAdcBase->INTE & eADC_INTE_LEOSEQIE_MASK) != 0U))
        {
            PtrAdcBase->INTE &= ~eADC_INTE_LEOSEQIE_MASK;
        }
        else
        {
            /*Nothing to do*/
        }
    }
    /*ADC Enable*/
    /*ADC Start*/
}

/************************************************************************************
* Check the Group index is in Groups array or not.
*************************************************************************************/
ADC_FUNC uint16 Adc_Lld_GroupIndexCheck(Adc_GroupType Group)
{
    uint16 TempIndex = 0u;
    uint8 InterLoopCount;
    for (InterLoopCount = 0u; InterLoopCount < Adc_ConfigPtr->GroupCfgNum; ++InterLoopCount)
    {
        if (Group == Adc_ConfigPtr->GroupUserCfg[InterLoopCount].GroupId)
        {
            TempIndex = InterLoopCount;
            break;
        }
    }
    /*Group ID is invalid,return Adc_ConfigPtr->GroupCfgNum*/
    if (InterLoopCount >= Adc_ConfigPtr->GroupCfgNum)
    {
        TempIndex = Adc_ConfigPtr->GroupCfgNum;
    }
    return TempIndex;
}


/************************************************************************************
* Update the group status in IRQ.
*************************************************************************************/
ADC_FUNC void Adc_Lld_GroupStatusUpdata(uint16 GroupIndex)
{
    /*update group status*/
    switch (Adc_GroupResult[GroupIndex].GroupStatus)
    {
        case ADC_IDLE:
            Adc_GroupResult[GroupIndex].GroupSampleCount = 0u;
            break;
        case ADC_BUSY:
        case ADC_COMPLETED:
        {
            if (Adc_GroupResult[GroupIndex].GroupSampleCount >= Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples)
            {
                Adc_GroupResult[GroupIndex].GroupStatus = ADC_STREAM_COMPLETED;
                Adc_GroupResult[GroupIndex].GroupSampleCount = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples;
            }
            else
            {
                Adc_GroupResult[GroupIndex].GroupStatus = ADC_COMPLETED;
            }
        }
        break;
        case ADC_STREAM_COMPLETED:
        {
            Adc_GroupResult[GroupIndex].GroupSampleCount = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples;
        }
        break;
        default:
            /*Nothing to do*/
            break;
    }
}

/************************************************************************
 *                       Adc_Lld_QueueDataUpdata
 ***********************************************************************/
ADC_FUNC Std_ReturnType Adc_Lld_QueueDataUpdata(uint8 AdcHwIndex, uint16 GroupIndex)
{
    Std_ReturnType TempRet = E_NOT_OK;
    /*The group state is stream completed, the ADC hw need to load another group in queue to
      conversion or stop if no group in queue*/
    if (Adc_GroupResult[GroupIndex].GroupStatus == ADC_STREAM_COMPLETED)
    {
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_05();
#if ((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)||(ADC_ENABLE_QUEUING == STD_ON))
        if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex > 1u)
        {
            Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex -= 1u;
            for (uint8 InterLoopCount = 0; InterLoopCount < Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex; ++InterLoopCount)
            {
                /*NOSONAR - This is a pointer copy operation, which is safe to do*/
                Adc_HwStatus[AdcHwIndex].SwNormalQueue[InterLoopCount] = Adc_HwStatus[AdcHwIndex].SwNormalQueue[InterLoopCount + 1u]; /*NOSONAR*/
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
                Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[InterLoopCount] = Adc_HwStatus[AdcHwIndex].SwNormalQueuePriority[InterLoopCount + 1];/*NOSONAR*/
#endif /*(ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)*/
            }
            Adc_HwStatus[AdcHwIndex].SwNormalQueue[Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex] = ADC_MAX_UINT16;
        }
        else
#endif /*((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)||(ADC_ENABLE_QUEUING == STD_ON))*/
        {
            Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex = 0u;
        }
        TempRet = E_OK;
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05();
    }
    return TempRet;
}

#if (ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
/************************************************************************
 *                       Adc_Lld_SetPowerState
 ***********************************************************************/
ADC_FUNC Std_ReturnType Adc_Lld_SetPowerState(Adc_PowerStateType PowerState)
{
    Std_ReturnType ReturnValue = (Std_ReturnType)E_OK;
    for (uint8 AdcHwUnitId = 0U; AdcHwUnitId < ADC_MAX_HW_UNITS; ++AdcHwUnitId)
    {
        if (ADC_FULL_POWER == PowerState)
        {
            Adc_Lld_AutoOffCfg(AdcHwUnitId, FALSE);
        }
        else if (ADC_LOW_POWER == PowerState)
        {
            Adc_Lld_AutoOffCfg(AdcHwUnitId, TRUE);
        }
        else
        {
            ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }
    return ReturnValue;
}
#endif /* (ADC_LOW_POWER_STATES_SUPPORT == STD_ON) */


/************************************************************************
 *                       Adc_Lld_Adc0DmaTransEndNotification
 ***********************************************************************/
ADC_FUNC void Adc_Lld_IrqProcess(uint8 AdcHwIndex)
{
    /*judge interrput flag*/
    uint16 GroupIndex = 0;
    Adc_ChannelType GroupChannelNum = 0;
    uint8 TempSampleCnt = 0;
    /*Check interrupt flag*/
#if (ADC_HIGH_PRIORITY_SEQ_DMA_SUPPORTED==STD_OFF)
    if (TRUE == Adc_Lld_ReadHoSeqConvEndIntFlag(AdcHwIndex))
    {
        /* Clear the interrupt flag */
        Adc_Lld_ClearHoSeqConvEndIntFlag(AdcHwIndex);
#if (ADC_HW_TRIGGER_API==STD_ON)
        /*The high priority sequence conversion has ended*/
        if (Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup != ADC_MAX_UINT16)
        {
            /*If there is a High priority Group currently performing the conversion and the HEOSEQ flag is set,
             then handle the conversion completion interrupt*/
            /*read which group is busy in high priority seq*/
            GroupIndex = Adc_Lld_GetHoGroupIndex(AdcHwIndex);
            /*Handles the number of times the hardware group collection is completed, because the
            hardware triggers the group in the ADC_STREAM_COMPLETED state to allow the collection to continue*/
            if ((Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupTriggSrc == ADC_TRIGG_SRC_HW) && \
                    (Adc_GroupResult[GroupIndex].GroupSampleCount >= Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples) && \
                    (ADC_STREAM_COMPLETED == Adc_GroupResult[GroupIndex].GroupStatus))
            {
                Adc_GroupResult[GroupIndex].GroupSampleCount = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples - 1u;
            }
            GroupChannelNum = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum;
            TempSampleCnt = (Adc_GroupResult[GroupIndex].GroupSampleCount * GroupChannelNum) + Adc_GroupResult[GroupIndex].GroupCompChnNum;
            /*Read Adc data to result buffer and align*/
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
            /* SWS_Adc_00446 ,SWS_Adc_00447, SWS_Adc_00448*/
            boolean LimitCheckResultFlag = TRUE;
            /*buffer filled with data from FIFO register*/
            LimitCheckResultFlag = Adc_Lld_ReadConversionResults(AdcHwIndex, GroupIndex, \
                                   & (Adc_GroupResult[GroupIndex].GroupValueBuf[TempSampleCnt]), \
                                   Adc_GroupResult[GroupIndex].GroupLoadChnNum, \
                                   0U);
            if (FALSE == LimitCheckResultFlag)
            {
                if ((Adc_GroupResult[GroupIndex].GroupCompChnNum + Adc_GroupResult[GroupIndex].GroupLoadChnNum) >= \
                        Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum)
                {
                    Adc_GroupResult[GroupIndex].GroupLoadChnNum = 0;
                }
            }
            else
#else
            /*buffer filled with data from FIFO register*/
            /* MR12 RULE 18.4 VIOLATION: The integer Value 1 is being added or subtracted from a pointer.
                        * Pointer operation is more concise for data processing, thus, couldn't adhere to M3CM Rule-8.13
                        */
            /*PRQA S 0488 ++*/
            Adc_Lld_ReadConversionResults(AdcHwIndex, (Adc_GroupResult[GroupIndex].GroupValueBuf + TempSampleCnt), \
                                          Adc_GroupResult[GroupIndex].GroupLoadChnNum, \
                                          Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelResolution);
            /*PRQA S 0488 --*/
#endif /* #if (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
            {
                /* SWS_Adc_00325 */
                Adc_GroupResult[GroupIndex].GroupCompChnNum += Adc_GroupResult[GroupIndex].GroupLoadChnNum;
                if (Adc_GroupResult[GroupIndex].GroupCompChnNum >= Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum)
                {
                    Adc_GroupResult[GroupIndex].GroupSampleCount += 1u;
                    Adc_GroupResult[GroupIndex].GroupCompChnNum = 0u;
                    Adc_Lld_GroupStatusUpdata(GroupIndex);
                }
            }
            Adc_GroupResult[GroupIndex].GroupLoadChnNum = 0;
#if ADC_GRP_NOTIF_CAPABILITY==STD_ON
            /* call notification api for user if enable*/
            if ((ADC_NOTIFICATION_ENABLED == Adc_GroupResult[GroupIndex].NotificationEnFlag) && \
                    (ADC_BUSY != Adc_GroupResult[GroupIndex].GroupStatus) && \
                    (0u == Adc_GroupResult[GroupIndex].GroupCompChnNum))
            {
                Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->NotificationFunc();
            }
#endif
            /*keep the group*/
            Adc_GroupResult[GroupIndex].GroupLoadChnNum = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum;
        }
#endif
    }
#endif /* (ADC_HIGH_PRIORITY_SEQ_DMA_SUPPORTED == STD_OFF) */
#ifndef ADC_DMA_SUPPORTED
    if (TRUE == Adc_Lld_ReadSeqConvEndIntFlag(AdcHwIndex))
    {
        /* Clear the interrupt flag */
        Adc_Lld_ClearSeqConvEndIntFlag(AdcHwIndex);
        GroupIndex = Adc_Lld_GetRunningGroupIndex(AdcHwIndex);
        /*The low priority sequence conversion has ended*/
        if ((Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex > 0u) && \
                (Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->IntcAndDmaCfg == ADC_INTC_ENABLED))
        {
            /*If there is a Low priority Group currently performing the conversion and the LEOSEQ flag is set,
             then handle the conversion completion interrupt*/
            /*read which group is busy in queue*/
            GroupChannelNum = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum;
            TempSampleCnt = (Adc_GroupResult[GroupIndex].GroupSampleCount * GroupChannelNum) + Adc_GroupResult[GroupIndex].GroupCompChnNum;
            /*Read Adc data to result buffer and align*/
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
            /* SWS_Adc_00446 ,SWS_Adc_00447, SWS_Adc_00448*/
            boolean LimitCheckResultFlag = TRUE;
            /*buffer filled with data from FIFO register*/
            LimitCheckResultFlag = Adc_Lld_ReadConversionResults(AdcHwIndex, GroupIndex, \
                                   & (Adc_GroupResult[GroupIndex].GroupValueBuf[TempSampleCnt]), \
                                   Adc_GroupResult[GroupIndex].GroupLoadChnNum, \
                                   Adc_ConfigPtr->HwUnitUserCfg[AdcHwIndex].HighPrioritySeqNum);
            if (FALSE == LimitCheckResultFlag)
            {
                if ((Adc_GroupResult[GroupIndex].GroupCompChnNum + Adc_GroupResult[GroupIndex].GroupLoadChnNum) >= \
                        Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum)
                {
                    Adc_GroupResult[GroupIndex].GroupLoadChnNum = 0;
                }
            }
            else
#else
            /*buffer filled with data from FIFO register*/
            /* MR12 RULE 18.4 VIOLATION: The integer Value 1 is being added or subtracted from a pointer.
                        * Pointer operation is more concise for data processing, thus, couldn't adhere to M3CM Rule-8.13
                        */
            /*PRQA S 0488 ++*/
            Adc_Lld_ReadConversionResults(AdcHwIndex, (Adc_GroupResult[GroupIndex].GroupValueBuf + TempSampleCnt), \
                                          Adc_GroupResult[GroupIndex].GroupLoadChnNum, \
                                          Adc_ConfigPtr->HwUnitUserCfg[AdcHwIndex].HighPrioritySeqNum);
            /*PRQA S 0488 --*/
#endif /* #if (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
            {
                /* SWS_Adc_00325 */
                Adc_GroupResult[GroupIndex].GroupCompChnNum += Adc_GroupResult[GroupIndex].GroupLoadChnNum;
                if (Adc_GroupResult[GroupIndex].GroupCompChnNum >= Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum)
                {
                    Adc_GroupResult[GroupIndex].GroupSampleCount += 1u;
                    Adc_GroupResult[GroupIndex].GroupCompChnNum = 0u;
                    Adc_Lld_GroupStatusUpdata(GroupIndex);
                }
            }
            Adc_GroupResult[GroupIndex].GroupLoadChnNum = 0;
            /*updata queue data*/
            (void)Adc_Lld_QueueDataUpdata(AdcHwIndex, GroupIndex);
#if ADC_GRP_NOTIF_CAPABILITY==STD_ON
            /* call notification api for user if enable*/
            if ((ADC_NOTIFICATION_ENABLED == Adc_GroupResult[GroupIndex].NotificationEnFlag) && \
                    (ADC_BUSY != Adc_GroupResult[GroupIndex].GroupStatus) && \
                    (0u == Adc_GroupResult[GroupIndex].GroupCompChnNum))
            {
                Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->NotificationFunc();
            }
#endif
            if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex > 0u)
            {
                /*load the remaining channels or next group to ADC HW and start conversion*/
                Adc_Lld_RestartAdcHardWare(AdcHwIndex);
            }
            else
            {
                /*No group to be convert, stop adc hw*/
                Adc_Lld_StopConversion(AdcHwIndex);
            }
        }
    }
    else
#endif /* #ifndef ADC_DMA_SUPPORTED*/
    {
        /*do nothing*/
        (void)GroupIndex;
        (void)GroupChannelNum;
        (void)TempSampleCnt;
    }
}


#if (ADC_HIGH_PRIORITY_SEQ_DMA_SUPPORTED==STD_ON)&&(ADC_HW_TRIGGER_API==STD_ON)
/**************************************************************************************************
* Adc_Lld_HoSeqDmaNotification
**************************************************************************************************/
ADC_FUNC void Adc_Lld_HoSeqDmaNotification(uint32 Parameter)
{
    uint8 AdcHwIndex = (uint8)Parameter;
    uint16 GroupIndex = 0u;
    Adc_ChannelType GroupChannelNum = 0U;
    uint8 InterLoopCount = 0;
    uint8 DmaVirChannel;
    /*The high priority sequence conversion has ended*/
    if (Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup != ADC_MAX_UINT16)
    {
        /*If there is a High priority Group currently performing the conversion and the HEOSEQ flag is set,
             then handle the conversion completion interrupt*/
        /*read which group is busy in high priority seq*/
        GroupIndex = Adc_Lld_GetHoGroupIndex(AdcHwIndex);
        DmaVirChannel = Adc_ConfigPtr->HwUnitUserCfg[Adc_Lld_HwIndexCaculate(AdcHwIndex)].HighPrioritySeqIntcAndDmaCfg;
        CddDma_StopChannel(DmaVirChannel);
        Adc_Lld_ClearHoSeqConvEndIntFlag(AdcHwIndex);
        /*Handles the number of times the hardware group collection is completed, because the
            hardware triggers the group in the ADC_STREAM_COMPLETED state to allow the collection to continue*/
        if ((Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupTriggSrc == ADC_TRIGG_SRC_HW) && \
                (Adc_GroupResult[GroupIndex].GroupSampleCount >= Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples) && \
                (ADC_STREAM_COMPLETED == Adc_GroupResult[GroupIndex].GroupStatus))
        {
            Adc_GroupResult[GroupIndex].GroupSampleCount = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->StreamingNumSamples - 1u;
        }
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        boolean LimitCheckResultFlag = TRUE;
        /* SWS_Adc_00446 ,SWS_Adc_00447, SWS_Adc_00448*/
        if ((TRUE == Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelLimitCheck) && \
                (ADC_RANGE_ALWAYS != Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelRangeSelect))
        {
            for (InterLoopCount = 0u; InterLoopCount < GroupChannelNum; ++InterLoopCount)
            {
                LimitCheckResultFlag = Adc_Lld_LimitCheck(GroupIndex, \
                                       Adc_GroupResult[GroupIndex].GroupValueBuf[Adc_GroupResult[GroupIndex].GroupCompChnNum + InterLoopCount]);
                if (FALSE == LimitCheckResultFlag)
                {
                    break;
                }
            }
        }
        if (TRUE == LimitCheckResultFlag)
#endif /* #if (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
        {
            /*Add sample times for the Group*/
            Adc_GroupResult[GroupIndex].GroupCompChnNum += Adc_GroupResult[GroupIndex].GroupLoadChnNum;
            if (Adc_GroupResult[GroupIndex].GroupCompChnNum >= Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum)
            {
                Adc_GroupResult[GroupIndex].GroupSampleCount += 1u;
                Adc_GroupResult[GroupIndex].GroupCompChnNum = 0u;
                /* SWS_Adc_00325 */
                Adc_Lld_GroupStatusUpdata(GroupIndex);
            }
            (void)GroupChannelNum;
            (void)InterLoopCount;
        }
        Adc_GroupResult[GroupIndex].GroupLoadChnNum = 0;
#if ADC_GRP_NOTIF_CAPABILITY==STD_ON
        /* call notification api for user if enable*/
        if ((ADC_NOTIFICATION_ENABLED == Adc_GroupResult[GroupIndex].NotificationEnFlag) && \
                (ADC_BUSY != Adc_GroupResult[GroupIndex].GroupStatus) && \
                (0u == Adc_GroupResult[GroupIndex].GroupCompChnNum))
        {
            Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->NotificationFunc();
        }
#endif
        if (Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup != ADC_MAX_UINT16)
        {
            /*Only when continuous hardware triggers the acquisition, the DMA TCD needs to be adjusted.*/
            if (Adc_HwStatus[AdcHwIndex].HwOngoingHwGroup == Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupId)
            {
                /*keep the group and config the DMA*/
                Adc_GroupResult[GroupIndex].GroupLoadChnNum = Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum;
                Adc_Lld_UpdataDmaTcdForGroup(AdcHwIndex, GroupIndex);
            }
        }
    }
}
#endif

#if defined(ADC_DMA_SUPPORTED)
/************************************************************************
 *                       Adc_Lld_DmaTransEndNotification
 ***********************************************************************/
ADC_FUNC void Adc_Lld_DmaTransEndNotification(uint32 Parameter)
{
    /* MR12 RULE 11.4 VIOLATION:In this specific case, needs to convert the Parameter to instance, thus, couldn't adhere
     *                           to M3CM Rule-11.6
     */
    uint8 AdcHwIndex = (uint8)Parameter;
    uint16 GroupIndex = 0u;
    Adc_ChannelType GroupChannelNum = 0U;
    uint8 InterLoopCount = 0;
    uint8 DmaVirChannel;
    DmaVirChannel = Adc_ConfigPtr->HwUnitUserCfg[Adc_Lld_HwIndexCaculate(AdcHwIndex)].DmaChannel;
    CddDma_StopChannel(DmaVirChannel);
    Adc_Lld_ClearSeqConvEndIntFlag(AdcHwIndex);
    /*read which group is busy in queue*/
    GroupIndex =  Adc_Lld_GetRunningGroupIndex(AdcHwIndex);
    GroupChannelNum = Adc_GroupResult[GroupIndex].GroupLoadChnNum;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    boolean LimitCheckResultFlag = TRUE;
    /* SWS_Adc_00446 ,SWS_Adc_00447, SWS_Adc_00448*/
    if ((TRUE == Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelLimitCheck) && \
            (ADC_RANGE_ALWAYS != Adc_ConfigPtr->GroupUserCfg[GroupIndex].ChannelSample->ChannelRangeSelect))
    {
        for (InterLoopCount = 0u; InterLoopCount < GroupChannelNum; ++InterLoopCount)
        {
            LimitCheckResultFlag = Adc_Lld_LimitCheck(GroupIndex, \
                                   Adc_GroupResult[GroupIndex].GroupValueBuf[Adc_GroupResult[GroupIndex].GroupCompChnNum + InterLoopCount]);
            if (FALSE == LimitCheckResultFlag)
            {
                break;
            }
        }
    }
    if (TRUE == LimitCheckResultFlag)
#endif /* #if (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    {
        /*Add sample times for the Group*/
        Adc_GroupResult[GroupIndex].GroupCompChnNum += Adc_GroupResult[GroupIndex].GroupLoadChnNum;
        if (Adc_GroupResult[GroupIndex].GroupCompChnNum >= Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->GroupDefinition->GroupChannelsNum)
        {
            Adc_GroupResult[GroupIndex].GroupSampleCount += 1u;
            Adc_GroupResult[GroupIndex].GroupCompChnNum = 0u;
            /* SWS_Adc_00325 */
            Adc_Lld_GroupStatusUpdata(GroupIndex);
        }
        (void)GroupChannelNum;
        (void)InterLoopCount;
    }
    Adc_GroupResult[GroupIndex].GroupLoadChnNum = 0;
    /*updata queue data*/
    (void)Adc_Lld_QueueDataUpdata(AdcHwIndex, GroupIndex);
#if ADC_GRP_NOTIF_CAPABILITY==STD_ON
    /* call notification api for user if enable*/
    if ((ADC_NOTIFICATION_ENABLED == Adc_GroupResult[GroupIndex].NotificationEnFlag) && \
            (ADC_BUSY != Adc_GroupResult[GroupIndex].GroupStatus) && \
            (0u == Adc_GroupResult[GroupIndex].GroupCompChnNum))
    {
        Adc_ConfigPtr->GroupUserCfg[GroupIndex].GroupSample->NotificationFunc();
    }
#endif
    /*reload group configuration and restart convert,when the queue is not empty*/
    if (Adc_HwStatus[AdcHwIndex].SwNormalQueueIndex > 0u)
    {
        /*load the remaining channels or next group to ADC HW and start conversion*/
        Adc_Lld_RestartAdcHardWare(AdcHwIndex);
    }
    else
    {
        /*No group to be convert, stop adc hw*/
        Adc_Lld_StopConversion(AdcHwIndex);
    }
}
#endif/*ADC_DMA_SUPPORTED*/

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file Adc_Lld.c */

