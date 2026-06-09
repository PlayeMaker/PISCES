/**
 * @file    Adc_Types.h
 * @version
 *
 * @brief   AUTOSAR Adc module interface
 * @details API implementation for ADC driver
 *
 * @addtogroup ADC_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Adc
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
#ifndef ADC_TYPES_H
#define ADC_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                              INCLUDE FILES
==================================================================================================*/

#include "Std_Types.h"
#include "Adc_Cfg.h"

/*==================================================================================================
                                      HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_TYPES_VENDOR_ID                      (180)
#define ADC_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define ADC_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define ADC_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define ADC_TYPES_SW_MAJOR_VERSION               (0)
#define ADC_TYPES_SW_MINOR_VERSION               (9)
#define ADC_TYPES_SW_PATCH_VERSION               (1)

/*==================================================================================================
                                        FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ADC configuration header file are of the same vendor */
#if (ADC_TYPES_VENDOR_ID != ADC_VENDOR_ID_CFG)
#error "Adc_Types.h and Adc_Cfg.h have different vendor ids"
#endif

/* Check if source file and ADC configuration header file are of the same Autosar version */
#if ((ADC_TYPES_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ADC_TYPES_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ADC_TYPES_AR_RELEASE_REVISION_VERSION != ADC_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Adc_Types.h and Adc_Cfg.h are different"
#endif

/* Check if source file and ADC configuration header file are of the same software version */
#if ((ADC_TYPES_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION_CFG) || \
     (ADC_TYPES_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION_CFG) || \
     (ADC_TYPES_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Adc_Types.h and Adc_Cfg.h are different"
#endif

/*==================================================================================================
                                                DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                                EXTERNAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                                ENUMS
==================================================================================================*/

/**
 * @brief           Ranges slecet value
 * @details         Indicates which range select is used.
 * @note            trace: SWS_Adc_00524
 * @implements      Adc_ChannelRangeSelectType_enum
 */
typedef enum
{
    ADC_RANGE_UNDER_LOW     = 0U,    /*!< Range below low limit - low limit value included*/
    ADC_RANGE_BETWEEN       = 1U,    /*!< Range between low limit and high limit - high limit value included*/
    ADC_RANGE_OVER_HIGH     = 2U,    /*!< Range above high limit*/
    ADC_RANGE_ALWAYS        = 3U,    /*!< Complete range - independent from channel limit settings*/
    ADC_RANGE_NOT_UNDER_LOW = 4U,    /*!< Range above low limit*/
    ADC_RANGE_NOT_BETWEEN   = 5U,    /*!< Range above high limit or below low limit - low limit value included*/
    ADC_RANGE_NOT_OVER_HIGH = 6U,    /*!< Range below high limit - high limit value included   */
} Adc_ChannelRangeSelectType;

/**
 * @brief           Adc group access mode.
 * @details         Used for configuring the group conversion result fifo access mode.
 * @note            trace: SWS_Adc_00528
 * @implements      Adc_GroupAccessModeType_enum
 */
typedef enum
{
    ADC_ACCESS_MODE_SINGLE    = 0U,    /*! Single access mode */
    ADC_ACCESS_MODE_STREAMING = 1U,    /*! Streaming access mode */
} Adc_GroupAccessModeType;

/**
 * @brief           Adc group conversion mode.
 * @details         Used for configuring the group conversion mode.
 * @note            trace: SWS_Adc_00515
 * @implements      Adc_GroupConvModeType_enum
 */
typedef enum
{
    ADC_CONV_MODE_ONESHOT    = 0U,    /*!< One-shot conversion mode*/
    ADC_CONV_MODE_CONTINUOUS = 1U,    /*!< Continuous conversion mode*/
} Adc_GroupConvModeType;


/**
 * @brief           Adc group replacement
 * @details         Used for configuring the replacemet for group.
 * @note            trace: SWS_Adc_00523
 * @implements      Adc_GroupReplacementType_enum
 */
typedef enum
{
    ADC_GROUP_REPL_ABORT_RESTART  = 0U,  /*!< Abort and restart of group*/
    ADC_GROUP_REPL_SUSPEND_RESUME = 1U,  /*!< Suspend and resume of group*/
} Adc_GroupReplacementType;


/**
 * @brief           Adc hardware trigger edge.
 * @details         Used for configuring trigger edge when a group configured hardware trigger.
 * @note            trace: SWS_Adc_00520
 * @implements      Adc_GroupTriggSrcType_enum
 */
typedef enum
{
    ADC_HW_TRIG_RISING_EDGE  = 0U,   /*!< Rising edge  */
    ADC_HW_TRIG_FALLING_EDGE = 1U,   /*!< Falling edge */
    ADC_HW_TRIG_BOTH_EDGES   = 2U,   /*!< Both edges   */
} Adc_HwTriggerSignalType;

/**
 * @brief           Adc group status.
 * @details         Used for return the status of group.
 * @note            trace: SWS_Adc_00513
 * @implements      Adc_StatusType_enum
 */
typedef enum
{
    ADC_IDLE             = 0U,     /*!< Group is in IDLE state*/
    ADC_BUSY             = 1U,     /*!< Group is in BUSY state*/
    ADC_COMPLETED        = 2U,     /*!< Group is in COMPLETED state*/
    ADC_STREAM_COMPLETED = 3U,     /*!< Group is in STREAM_COMPLETED state*/
} Adc_StatusType;

/**
 * @brief           Adc group streaming buffer mode.
 * @details         Used for configuring the group streaming buffer mode.
 * @note            trace: SWS_Adc_00519
 * @implements      Adc_StreamBufferModeType_enum
 */
typedef enum
{
    ADC_STREAM_BUFFER_LINEAR   = 0U,   /*!< Linear streaming buffer mode*/
    ADC_STREAM_BUFFER_CIRCULAR = 1U,   /*!< Circular streaming buffer mode*/
} Adc_StreamBufferModeType;

/**
 * @brief           Adc group trigger source.
 * @details         Used for configuring the group trigger source.
 * @note            trace: SWS_Adc_00514
 * @implements      Adc_TriggerSourceType_enum
 */
typedef enum
{
    ADC_TRIGG_SRC_SW = 0U,  /*!< Software trigger*/
    ADC_TRIGG_SRC_HW = 1U,  /*!< Hardware trigger*/
} Adc_TriggerSourceType;

/**
* @brief          ADC group notification.
* @details        Indicates if notification is enabled for the group.
* @implements     Adc_NotificationCfgType_enum
*/
typedef enum
{
    ADC_NOTIFICATION_DISABLED = 0U, /*!< @brief Notification is disabled */
    ADC_NOTIFICATION_ENABLED  = 1U, /*!< @brief Notification is enabled */
} Adc_NotificationCfgType;

/**
* @brief          ADC interrupt and DMA configure.
* @details        Indicates if group conversion end interrput and DMA is enabled for the group.
*
*/
typedef enum
{
    ADC_INTCANDDMA_DISABLED = 0U, /*!< @brief interrput and DMA is disabled */
    ADC_INTC_ENABLED   = 1U, /*!< @brief only the interrput is enabled */
    ADC_DMA_ENABLED    = 2U, /*!< @brief only the DMA is enabled*/
} Adc_IntcAdnDmaCfgType;

/**
 * @brief           Type for ADC result of one channel.
 * @note            trace: SWS_Adc_00508
 */
typedef uint16 Adc_ValueGroupType;

/**
 * @brief            Numeric ID of an ADC channel.
 * @note            trace: SWS_Adc_00506
 */
#if (ADC_CHANNEL_SAMPLE_TIME_CFG == TRUE)
typedef uint16 Adc_ChannelType;
#else
typedef uint8 Adc_ChannelType;
#endif /* (ADC_CHANNEL_SAMPLE_TIME_CFG == TRUE) */
/**
 * @brief           Type for ADC channel configuring of one group.
 */
typedef struct
{
    const Adc_ChannelType   *GroupChannels;   /*!< @brief Pointer to the array of channels in the group. */
    Adc_ChannelType         GroupChannelsNum; /*!< @brief Number of channels in the group. */
    uint8                   GroupInHwUnitId;  /*!< @brief The hw unit id of the group. */
} Adc_GroupDefType;

/**
 * @brief           Type for ADC conversion time.
 * @note            trace: SWS_Adc_00510
 */
typedef uint16 Adc_ConversionTimeType;

/**
 * @brief           Numeric ID of an ADC group.
 * @note            trace: SWS_Adc_00507
 */
typedef uint16 Adc_GroupType;

/**
 * @brief Index for the queue of groups .
 */
typedef uint16 Adc_QueueIndexType;

/**
 * @brief           ADC Channel group priority.
 * @note            trace: SWS_Adc_00516
 */
typedef uint8 Adc_GroupPriorityType;

/**
 * @brief           Type for the reload value of the ADC embedded timer
 * @note            trace: SWS_Adc_00521
 */
typedef uint64 Adc_HwTriggerTimerType;

/**
 * @brief           ADC prescale value for the ADC clock.
 * @note            trace: SWS_Adc_00509
 */
typedef uint8 Adc_PrescaleType;

/**
 * @brief           Type for ADC resolution.
 * @details         Used for configuring the ADC resolution.
 * @note            trace: SWS_Adc_00512
 * @implements      Adc_ResolutionType_enum
 */
typedef enum
{
    ADC_RESOLUTION_12BIT   = 0U,    /*!< 12 bit resolution */
    ADC_RESOLUTION_10BIT   = 1U,    /*!< 10 bit resolution */
    ADC_RESOLUTION_8BIT    = 2U,    /*!< 8 bit resolution */
    ADC_RESOLUTION_6BIT    = 3U,    /*!< 6 bit resolution */
} Adc_ResolutionType;

/**
 * @brief   ADC Clock choose
 * @details Used for configuring the ADC function clock source.
 * @implements Adc_ClockSourceType_enum
 */
typedef enum
{
    ADC_BUSCLK = 0U,   /*!< Bus clock */
    ADC_FIRC   = 1U,   /*!< FIRC clock */
    ADC_EOSC   = 2U,   /*!< FXOSC clock */
    ADC_SIRC   = 3U,   /*!< SIRC clock */
} Adc_ClockSourceType;

#if (ADC_LOW_POWER_STATES_SUPPORT == STD_ON)
/**
* @brief      Power state type
* @details    Power state currently active or set as target power state.
* @implements     Adc_PowerStateType_enum
*/
typedef enum
{
    ADC_FULL_POWER = 0U,    /*!< Adc full power mode. */
    ADC_LOW_POWER,          /*!< Adc low power mode. */
    ADC_NODEFINE_POWER      /*!< Adc no define power mode. */
} Adc_PowerStateType;

/**
* @brief      Result of power state type
* @details    Result of the requests related to power state transitions.
* @implements     Adc_PowerStateRequestResultType_enum
*/
typedef enum
{
    ADC_SERVICE_ACCEPTED = 0U,  /*!< Power state change executed. */
    ADC_NOT_INIT,               /*!< Module not initialized. */
    ADC_SEQUENCE_ERROR,         /*!< Wrong API call sequence. */
    ADC_HW_FAILURE,             /*!< The HW module has a failure which prevents it to enter the required power state. */
    ADC_POWER_STATE_NOT_SUPP,   /*!< Module does not support the requested power state. */
    ADC_TRANS_NOT_POSSIBLE      /*!< Module cannot transition directly from the current power state to the requested power state. */
} Adc_PowerStateRequestResultType;
#endif /*(ADC_LOW_POWER_STATES_SUPPORT == STD_ON)*/

#if (ADC_HW_RESULTS_AVERAGE_SUPPORT == TRUE)
/**
 * @brief           Type for ADC results averaged.
 * @details         Used for configuring the number of times the conversion results are averaged.
 * @implements      Adc_ResultsAverageType_enum
 */
typedef enum
{
    ADC_RESULTS_AVERAGED_NONE = 0U,    /*!< No averaging */
    ADC_RESULTS_AVERAGED_2_TIMES,       /*!< Averaged 2 times */
    ADC_RESULTS_AVERAGED_4_TIMES,       /*!< Averaged 4 times */
    ADC_RESULTS_AVERAGED_8_TIMES,       /*!< Averaged 8 times */
    ADC_RESULTS_AVERAGED_16_TIMES,      /*!< Averaged 16 times */
    ADC_RESULTS_AVERAGED_32_TIMES,      /*!< Averaged 32 times */
} Adc_ResultsAverageType;

#endif /* (ADC_HW_RESULTS_AVERAGE_SUPPORT == TRUE) */
#if (ADC_HW_HIGH_PRIORITY_SEQUENCE == TRUE)
typedef enum
{
    HIGH_PRIORITY_SEQ_HAS_1_CHANNEL  = 0x01U, /*!< High priority sequence has 1 channel */
    HIGH_PRIORITY_SEQ_HAS_2_CHANNEL  = 0x02U, /*!< High priority sequence has 2 channels */
    HIGH_PRIORITY_SEQ_HAS_4_CHANNEL  = 0x04U, /*!< High priority sequence has 4 channels */
    HIGH_PRIORITY_SEQ_HAS_8_CHANNEL  = 0x08U, /*!< High priority sequence has 8 channels */
    HIGH_PRIORITY_SEQ_HAS_12_CHANNEL = 0x0CU, /*!< High priority sequence has 12 channels */
    HIGH_PRIORITY_SEQ_HAS_14_CHANNEL = 0x0EU, /*!< High priority sequence has 14 channels */
    HIGH_PRIORITY_SEQ_HAS_15_CHANNEL = 0x0FU, /*!< High priority sequence has 15 channels */
} Adc_HighPrioritySeqLengthCfgType;
#endif

#if (ADC_CHANNEL_SAMPLE_TIME_CFG == TRUE)
typedef enum
{
    ADC_SAMP0 = 0x00U,    /*!< Sample time 0 */
    ADC_SAMP1 = 0x80U,    /*!< Sample time 1 */
} Adc_ChannelSampleTimeCfgType;
#endif /* (ADC_CHANNEL_SAMPLE_TIME_CFG == TRUE) */

/**
* @brief            Type for ADC sampling time.
* @note            trace: SWS_Adc_00511
*/
typedef uint8 Adc_SamplingTimeType;

/**
* @brief           Number of samples of a streaming conversion buffer.
* @note            trace: SWS_Adc_00518
*/
typedef uint8 Adc_StreamNumSampleType;

/**
 * @brief           Notification function pointer definition
 * @note            trace: ECUC_Adc_00402
 */
typedef void(*Adc_NotificationType)(void);

/**
 * @brief       The channel configuration (parameters) depending on the hardware capability
 * @note        trace:ECUC_Adc_00268
 */
typedef struct
{
    /*ECUC_Adc_00011*/
    Adc_ConversionTimeType ChannelConvTime; /*!< Conversion time in ADC clock cycles */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    /*ECUC_Adc_00455*/
    uint64 ChannelHighLimit;  /*!< High limit value for limit check */
    /*ECUC_Adc_00453*/
    boolean ChannelLimitCheck; /*!< Enable/disable limit check */
    /*ECUC_Adc_00454*/
    uint64 ChannelLowLimit; /*!< Low limit value for limit check */
    /*ECUC_Adc_00456*/
    Adc_ChannelRangeSelectType ChannelRangeSelect; /*!< Select the range for limit check */
#endif
    /*ECUC_Adc_00089*/
    uint16 ChannelRefVoltsrcHigh; /*!< Reference voltage source high value */
    /*ECUC_Adc_00023*/
    uint16 ChannelRefVoltsrcLow; /*!< Reference voltage source low value */
    /*ECUC_Adc_00019*/
    Adc_ResolutionType ChannelResolution; /*!< Resolution of the channel */
    /*ECUC_Adc_00290*/
    Adc_SamplingTimeType ChannelSampTime; /*!< Sampling time in ADC clock cycles */
} Adc_ChannelSampleType;

/**
 * @brief       The Group configuration parameters.
 * @note        trace:ECUC_Adc_00028
 */
typedef struct
{
    /*ECUC_Adc_00317*/
    Adc_GroupAccessModeType GroupAccessMode;    /*!< Access mode of the group */
    /*ECUC_Adc_00397*/
    Adc_GroupConvModeType GroupConversionMode;  /*!< Conversion mode of the group */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /*ECUC_Adc_00287*/
    Adc_GroupPriorityType GroupPriority;        /*!< Priority of the group */
#endif/* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */
    /*ECUC_Adc_00435*/
    Adc_GroupReplacementType GroupReplacement;  /*!< Replacement mode of the group */
    /*ECUC_Adc_00399*/
    Adc_TriggerSourceType GroupTriggSrc;        /*!< Trigger source of the group */

#if (ADC_HW_TRIGGER_API == STD_ON)
#if (ADC_HW_HIGH_PRIORITY_SEQUENCE == FALSE)
    Adc_HwTriggerSourceType HwTrigSrc;          /*!< Hardware trigger source select*/
#endif /* ADC_HW_HIGH_PRIORITY_SEQUENCE == FALSE */
    /*ECUC_Adc_00400*/
    Adc_HwTriggerSignalType HwTrigSignal;       /*!< Hardware trigger edge */
    /*ECUC_Adc_00401*/
    Adc_HwTriggerTimerType HwTrigTimer;         /*!< Hardware trigger delay timer value */
#endif

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    /*ECUC_Adc_00402*/
    Adc_NotificationType  NotificationFunc;        /*!< Notification function pointer for the group*/
#endif

    /*ECUC_Adc_00316*/
    Adc_StreamBufferModeType StreamingBufferMode;  /*!< Buffer mode of the group */
    /*ECUC_Adc_00292*/
    Adc_StreamNumSampleType StreamingNumSamples;   /*!< Number of samples of the group */
    /*ECUC_Adc_00014*/
    const Adc_GroupDefType *GroupDefinition;      /*!< Pointer to the group definition */

    Adc_IntcAdnDmaCfgType IntcAndDmaCfg;         /*!< Interrupt and DMA configuration */
} Adc_GroupSampleType;

/**
 * @brief       The ADC HW specific parameters.
 * @note        trace:ECUC_Adc_00242
 */
typedef struct
{
    /*ECUC_Adc_00389*/
    uint8 HwUnitId;          /*!< ADC HW unit ID */
    /*ECUC_Adc_00087*/
    Adc_ClockSourceType ClockSource;  /*!< ADC clock source */
    /*ECUC_Adc_00088*/
    uint8 Prescale;         /*!< ADC prescale value */
    /*Adc startup time config*/
    uint8 StartupTime;    /*!< ADC startup time */
    /*Internal tempreture sensor enable*/
    boolean InternalTempSensor; /*!< Internal tempreture sensor enable */
#if (ADC_CHANNEL_SAMPLE_TIME_CFG == TRUE)
    uint32 SampleTime;      /*!< ADC sample time */
#endif
#ifdef ADC_DMA_SUPPORTED
    uint8 DmaChannel;                            /*!< DMA channel configuration for ADC */
#endif
#if (ADC_HW_HIGH_PRIORITY_SEQUENCE == TRUE)
    uint8 SwitchChannelCounter; /*The stabilization time for switch channels from low-priority seq to high-priority seq or vice versa*/
    Adc_HighPrioritySeqLengthCfgType HighPrioritySeqNum; /*!< Number of high priority sequence channels */
    Adc_IntcAdnDmaCfgType HighPrioritySeqIntcAndDmaCfg; /*!< Interrupt and DMA configuration for high priority sequence */
    uint8 HighPriorityDmaChannel; /*!< DMA channel configuration for high priority sequence */
#endif /* ADC_HW_HIGH_PRIORITY_SEQUENCE == TRUE */

#if (ADC_HW_RESULTS_AVERAGE_SUPPORT == TRUE)
    Adc_ResultsAverageType AdcResultsAveragedTimes; /*!< Number of times the conversion results are averaged */
#endif /* ADC_HW_RESULTS_AVERAGE_SUPPORT == TRUE */

} Adc_HwUnitType;

/**
 * @brief       The Group configuration parameters,include GroupID and channel configuration.
 * @note        trace:ECUC_Adc_00028
 */
typedef struct
{
    /*ECUC_Adc_00398*/
    Adc_GroupType                 GroupId;  /*!< Group ID */

    const Adc_ChannelSampleType   *ChannelSample;  /*!< Pointer to the channel configuration */

    const Adc_GroupSampleType     *GroupSample;    /*!< Pointer to the group configuration */
} Adc_GroupConfigType;

/**
 * @brief       The configuration parameters and sub containers of the AUTOSAR Adc module.
 * @note        trace:ECUC_Adc_00390
 */
typedef struct
{
    const uint8       HwUnitCfgNum;    /*!< The number of hw unit will be configured. */

    const uint8       GroupCfgNum;      /*!< The number of group will be configured*/

    const Adc_HwUnitType       *HwUnitUserCfg;  /*!< ADC HW module configuration*/

    const Adc_GroupConfigType  *GroupUserCfg;  /*!< ADC groups configuration*/
} Adc_ConfigType;

/**
* @brief          Structure for hardware unit status.
* @details        This structure contains the HW unit status information.
*
*/
typedef struct
{
    volatile Adc_QueueIndexType SwNormalQueueIndex; /*!< Queue index for all groups in the hw unit */

#if ((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)|| (ADC_ENABLE_QUEUING == STD_ON))
    volatile Adc_GroupType SwNormalQueue[ADC_QUEUE_MAX_DEPTH_MAX]; /*!< the queue for group ID,the Queue[0] is conversion group*/

    volatile Adc_GroupPriorityType SwNormalQueuePriority[ADC_QUEUE_MAX_DEPTH_MAX]; /*!< Queue index for all groups in the hw unit */
#else
    volatile Adc_GroupType SwNormalQueue[1]; /*!< the queue for group ID,the Queue[0] is conversion group*/
#endif/* ((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)|| (ADC_ENABLE_QUEUING == STD_ON)) */
#if (ADC_HW_TRIGGER_API == STD_ON)
    volatile Adc_GroupType HwOngoingHwGroup;       /*!< Ongoing hardware group ID */
#endif /* ADC_HW_TRIGGER_API == STD_ON */
} Adc_UnitStatusType;


/**
 * @brief          Structure for group status.
 * @details        This structure contains the group status information and result fifo ptr.
*/
typedef struct
{
    Adc_StatusType             GroupStatus;            /*!< Group status */
    Adc_ValueGroupType        *GroupValueBuf;          /*!< Pointer to the result buffer */
    boolean                    ResultBufInitSt;   /*!< Result buffer init status */
    boolean                    SampleFinished;    /*!< Sample finished status */
    Adc_StreamNumSampleType    GroupSampleCount;  /*!< Sample count of the group */
    Adc_ChannelType            GroupCompChnNum;   /*!< Channel count of conversion completed in the group */
    Adc_ChannelType            GroupLoadChnNum;   /*!< Channel count of loading to Adc hardware sequence */
#if (ADC_GRP_NOTIF_CAPABILITY==STD_ON)
    Adc_NotificationCfgType       NotificationEnFlag;   /*!< Notification status */
#endif
} Adc_GroupResultType;


#ifdef __cplusplus
}
#endif

#endif /* ADC_TYPES_H */

/** @} */
