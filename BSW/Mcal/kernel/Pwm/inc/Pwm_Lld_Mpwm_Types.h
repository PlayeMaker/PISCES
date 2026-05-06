/**
 * @file    Pwm_Lld_Mpwm_Types.h
 * @version V0.9.1
 *
 * @brief   YUNTU Pwm_Lld_Mpwm module interface
 * @details API implementation for Pwm_Lld_Mpwm driver
 *
 * @addtogroup PWM_LLD_MPWM_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : MPWM
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V0.9.1
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/

#ifndef PWM_LLD_MPWM_TYPES_H
#define PWM_LLD_MPWM_TYPES_H

#include "Platform_Types.h"
#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_LLD_MPWM_TYPES_VENDOR_ID                      (180)
#define PWM_LLD_MPWM_TYPES_MODULE_ID            (121)
#define PWM_LLD_MPWM_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define PWM_LLD_MPWM_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define PWM_LLD_MPWM_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define PWM_LLD_MPWM_TYPES_SW_MAJOR_VERSION               (0)
#define PWM_LLD_MPWM_TYPES_SW_MINOR_VERSION               (9)
#define PWM_LLD_MPWM_TYPES_SW_PATCH_VERSION               (1)

/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/
/**
 * @brief MPWM PWM aligned mode.
 */
typedef enum
{
    PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE   = 0x00U,    /**< Left edge aligned. */
    PWM_LLD_MPWM_ALIGN_MODE_RIGHT_EDGE  = 0x01U,    /**< Right edge aligned. */
    PWM_LLD_MPWM_ALIGN_MODE_CENTER      = 0x02U     /**< Center aligned. only YTM32B1MD24 support, 2025.8 */
} Pwm_Lld_Mpwm_AlignModeType;

/**
 * @brief MPWM PWM output state.
 */
typedef enum
{
    PWM_LLD_MPWM_OUTPUT_STATE_LOW   = 0x00U,    /**< The PWM channel is in low state. */
    PWM_LLD_MPWM_OUTPUT_STATE_HIGH  = 0x01U     /**< The PWM channel is in high state. */
} Pwm_Lld_Mpwm_OutputStateType;

/**
 * @brief MPWM PWM polarity.
 */
typedef enum
{
    PWM_LLD_MPWM_POLARITY_NOT_INVERT    = 0x00U,    /**< Not invert the channel output. */
    PWM_LLD_MPWM_POLARITY_INVERT        = 0x01U     /**< Invert the channel output. */
} Pwm_Lld_Mpwm_PolarityType;

/**
 * @brief MPWM channel initial value.
 */
typedef enum
{
    PWM_LLD_MPWM_INIT_0 = 0x00U,    /**< Channel initial value is 0. */
    PWM_LLD_MPWM_INIT_1 = 0x01U     /**< Channel initial value is 1. */
} Pwm_Lld_Mpwm_InitType;

/**
 * @brief MPWM reloading sources.
 */
typedef enum
{
    PWM_LLD_MPWM_RLD_SRC_PERIOD     = 0x00U,    /**< PERIOD matching point reload. */
    PWM_LLD_MPWM_RLD_SRC_HW         = 0x01U,    /**< Hardware trigger point reload. */
    PWM_LLD_MPWM_RLD_SRC_SW         = 0x02U,    /**< Software trigger point reload. */
    PWM_LLD_MPWM_RLD_SRC_DISABLE    = 0x03U     /**< Double buffer mechanism is disabled. */
} Pwm_Lld_Mpwm_RldSrcType;

/**
 * @brief MPWM clock prescaler.
 */
typedef enum
{
    PWM_LLD_MPWM_CLK_DIV_1      = 0x00U,    /**< Clock prescaler is 1. */
    PWM_LLD_MPWM_CLK_DIV_2      = 0x01U,    /**< Clock prescaler is 2. */
    PWM_LLD_MPWM_CLK_DIV_4      = 0x02U,    /**< Clock prescaler is 4. */
    PWM_LLD_MPWM_CLK_DIV_8      = 0x03U,    /**< Clock prescaler is 8. */
    PWM_LLD_MPWM_CLK_DIV_16     = 0x04U,    /**< Clock prescaler is 16. */
    PWM_LLD_MPWM_CLK_DIV_32     = 0x05U,    /**< Clock prescaler is 32. */
    PWM_LLD_MPWM_CLK_DIV_64     = 0x06U,    /**< Clock prescaler is 64. */
    PWM_LLD_MPWM_CLK_DIV_128    = 0x07U     /**< Clock prescaler is 128. */
} Pwm_Lld_Mpwm_ClkPrsType;

/**
 * @brief MPWM channel mode.
 */
typedef enum
{
    PWM_LLD_MPWM_CH_MODE_COMMON_TIMER   = 0x00U,    /**< Common timer mode. */
    PWM_LLD_MPWM_CH_MODE_PWM            = 0x01U,    /**< PWM mode. */
    PWM_LLD_MPWM_CH_MODE_OUTPUT_COMPARE = 0x02U,    /**< Output compare mode. */
    PWM_LLD_MPWM_CH_MODE_INPUT_CAPTURE  = 0x03U,    /**< Input capture mode. */
    PWM_LLD_MPWM_CH_MODE_PULSE_COUNTER  = 0x04U,     /**< Pulse counter mode. */
    PWM_LLD_MPWM_CH_MODE_PWM_CENTER_ALIGN = 0x05U    /**< PWM center aligned mode. */
} Pwm_Lld_Mpwm_ChModeType;

/*==================================================================================================
 *                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief MPWM PWM callback type.
 */
typedef void (*Pwm_Lld_Mpwm_CallbackType)(void);

/**
 * @brief MPWM PWM Mode channel configuration
 */
typedef struct
{
    boolean DebugModeEn;                    /**< Debug mode enable */
    boolean CmpMatchTrigEn;                 /**< CMP Matching Trigger Output Enable. */
    boolean PeriodMatchTrigEn;              /**< PERIOD Matching Trigger Output Enable. */
    boolean OvfIrqEn;                       /**< Overflow interrupt enable */
    boolean ChIrqEn;                        /**< Channel interrupt enable */
    uint8 ChannelId;                        /**< Channel ID */
    uint16 Period;                          /**< Period */
    uint16 DutyCycle;                       /**< Duty cycle */
    Pwm_Lld_Mpwm_ClkPrsType ClockPrescaler; /**< Clock prescaler */
    Pwm_Lld_Mpwm_RldSrcType ReloadSource;   /**< Reloading source */
    Pwm_Lld_Mpwm_AlignModeType AlignMode;   /**< PWM aligned mode */
    Pwm_Lld_Mpwm_PolarityType Polarity;     /**< PWM channel polarity */
    Pwm_Lld_Mpwm_OutputStateType IdleState; /**< PWM channel idle state */
    Pwm_Lld_Mpwm_CallbackType OvfCallback;  /**< Overflow interrupt callback */
    Pwm_Lld_Mpwm_CallbackType ChCallback;   /**< Channel interrupt callback */
} Pwm_Lld_Mpwm_ChCfgType;

/**
 * @brief MPWM PWM Mode configuration
 */
typedef struct
{
    uint8 ChannelCount;                             /**< Number of PWM channels */
    const Pwm_Lld_Mpwm_ChCfgType *const *ChCfgArr;  /**< Pointer to channel configuration array */
} Pwm_Lld_Mpwm_CfgType;

#ifdef __cplusplus
}
#endif

#endif /* PWM_LLD_MPWM_TYPES_H */

/** @} */

