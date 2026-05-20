/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file undefined
 * @brief 
 * 
 */

#include "Adc_Cfg.h"
#include "Adc_Types.h"
#if defined(ADC_DMA_SUPPORTED)||(ADC_HIGH_PRIORITY_SEQ_DMA_SUPPORTED == STD_ON)
#include "CddDma.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_PBCFG_C                      (180)
#define ADC_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define ADC_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define ADC_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define ADC_SW_MAJOR_VERSION_PBCFG_C               (0)
#define ADC_SW_MINOR_VERSION_PBCFG_C               (9)
#define ADC_SW_PATCH_VERSION_PBCFG_C               (1)

/*================================================================================================== */
/**
 * @brief          Config number of ADC Hw units.
 */
#define ADC_UNIT_NUMBER                         (1U)

/**
 * @brief          Max number of ADC Hw units.
 */
#define ADC_GROUP_NUMBER                        (1U)

/*****************************************************************************************************/
extern void ADC0_Group0CallBack(void); 

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

/*Group channels definetion*/
ADC_CONST static const Adc_ChannelType AdcGroup_0_Channel[10] = 
{
    ADC0_SE6_ADCH6|ADC_SAMP0,
    ADC0_SE7_ADCH7|ADC_SAMP0,
    ADC0_SE8_ADCH8|ADC_SAMP0,
    ADC0_SE9_ADCH9|ADC_SAMP0,
    ADC0_SE12_ADCH12|ADC_SAMP0,
    ADC0_SE13_ADCH13|ADC_SAMP0,
    ADC0_SE14_ADCH14|ADC_SAMP0,
    ADC0_SE15_ADCH15|ADC_SAMP0,
    ADC0_SE17_ADCH17|ADC_SAMP0,
    ADC0_SE22_ADCH22|ADC_SAMP0,
};

/**/

ADC_CONST static const Adc_GroupDefType AdcGroup_0_ChannelsInf = 
{
    .GroupChannels       = &AdcGroup_0_Channel[0],
    .GroupChannelsNum    = 10,
    .GroupInHwUnitId     = ADC_0,
};



#if (ADC_UNIT_NUMBER != 0)
#if (ADC_UNIT_NUMBER > ADC_MAX_HW_UNITS)
    #error "Config too many ADC Hw Unit !"
#else
ADC_CONST const Adc_HwUnitType Adc_HwUnitConfiguration[ADC_UNIT_NUMBER] = {
{ 
    .HwUnitId = ADC_0,
    .ClockSource = ADC_BUSCLK,
    .Prescale = 0,
    .StartupTime = 41,
    .InternalTempSensor = FALSE,
    .SwitchChannelCounter = 9,
    .HighPrioritySeqNum = HIGH_PRIORITY_SEQ_HAS_1_CHANNEL,
    .HighPrioritySeqIntcAndDmaCfg = ADC_INTC_ENABLED,
    .AdcResultsAveragedTimes = ADC_RESULTS_AVERAGED_NONE,
    .SampleTime = 18,
},
};
#endif /* ADC_UNIT_NUMBER > ADC_MAX_HW_UNITS */
#endif /* ADC_UNIT_NUMBER != 0 */

ADC_CONST const Adc_ChannelSampleType AdcGroup_0_ChannelSample = {
    .ChannelConvTime = 0,
    .ChannelRefVoltsrcHigh = 0,
    .ChannelRefVoltsrcLow = 0,
    .ChannelResolution = ADC_RESOLUTION_12BIT,
};

ADC_CONST const Adc_GroupSampleType AdcGroup_0_Configuration = 
{
    .GroupAccessMode = ADC_ACCESS_MODE_SINGLE,
    .GroupConversionMode = ADC_CONV_MODE_ONESHOT,
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    .GroupPriority = 0,
#endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */
    .GroupReplacement = ADC_GROUP_REPL_ABORT_RESTART,
    .GroupTriggSrc = ADC_TRIGG_SRC_SW,
    .StreamingBufferMode = ADC_STREAM_BUFFER_LINEAR,
    .StreamingNumSamples = 1,
    .GroupDefinition = &AdcGroup_0_ChannelsInf,
    .NotificationFunc = ADC0_Group0CallBack,
    .IntcAndDmaCfg = ADC_INTC_ENABLED,
};

ADC_CONST const Adc_GroupConfigType Adc_GourpsConfiguration[1] = 
{
    {
        .GroupId = AdcConf_AdcConfigSet_AdcGroup_0,
        .GroupSample = &AdcGroup_0_Configuration,
        .ChannelSample = &AdcGroup_0_ChannelSample,
    },
};
ADC_CONST const Adc_ConfigType Adc_Config =
{
    .GroupCfgNum    = ADC_GROUP_NUMBER,
    .HwUnitCfgNum   = ADC_UNIT_NUMBER,
    .HwUnitUserCfg = &Adc_HwUnitConfiguration[0],
    .GroupUserCfg  = &Adc_GourpsConfiguration[0],
};

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Adc_MemMap.h"

