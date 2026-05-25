/**
 * @file    Pwm_Lld_Mpwm.C
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

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
 *                                         INCLUDE FILES
=================================================================================================*/
#include "Pwm_Lld_Mpwm.h"
#include "Pwm_Lld_Mpwm_Reg.h"
#include "SchM_Pwm.h"
#if (PWM_LLD_MPWM_DEV_ERROR_DETECT == STD_ON)
#include "Devassert.h"
#endif

/*==================================================================================================
 *                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_LLD_MPWM_VENDOR_ID_C                      (180)
#define PWM_LLD_MPWM_AR_RELEASE_MAJOR_VERSION_C       (4)
#define PWM_LLD_MPWM_AR_RELEASE_MINOR_VERSION_C       (4)
#define PWM_LLD_MPWM_AR_RELEASE_REVISION_VERSION_C    (0)
#define PWM_LLD_MPWM_SW_MAJOR_VERSION_C               (0)
#define PWM_LLD_MPWM_SW_MINOR_VERSION_C               (9)
#define PWM_LLD_MPWM_SW_PATCH_VERSION_C               (1)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Pwm_Lld_Mpwm.c and Pwm_Lld_Mpwm.h are of the same vendor */
#if (PWM_LLD_MPWM_VENDOR_ID_C != PWM_LLD_MPWM_VENDOR_ID)
#error "Pwm_Lld_Mpwm.c and Pwm_Lld_Mpwm.h have different vendor ids"
#endif

/* Check if Pwm_Lld_Mpwm.c and Pwm_Lld_Mpwm.h are of the same Autosar version */
#if ((PWM_LLD_MPWM_AR_RELEASE_MAJOR_VERSION_C != PWM_LLD_MPWM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_LLD_MPWM_AR_RELEASE_MINOR_VERSION_C != PWM_LLD_MPWM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_LLD_MPWM_AR_RELEASE_REVISION_VERSION_C != PWM_LLD_MPWM_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Pwm_Lld_Mpwm.c and Pwm_Lld_Mpwm.h are different"
#endif

/* Check if Pwm_Lld_Mpwm.c and Pwm_Lld_Mpwm.h are of the same Software version */
#if ((PWM_LLD_MPWM_SW_MAJOR_VERSION_C != PWM_LLD_MPWM_SW_MAJOR_VERSION) || \
     (PWM_LLD_MPWM_SW_MINOR_VERSION_C != PWM_LLD_MPWM_SW_MINOR_VERSION) || \
     (PWM_LLD_MPWM_SW_PATCH_VERSION_C != PWM_LLD_MPWM_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm_Lld_Mpwm.c and Pwm_Lld_Mpwm.h are different"
#endif

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/**
 * @brief Converts the duty cycle to ticks
 */
#define PWM_LLD_MPWM_DUTY_TO_TICK(duty, period) ((uint32)(((uint64)(duty) * (uint64)(period)) >> 15U))

/**
 * @brief Converts the ticks to duty cycle
 */
#define PWM_LLD_MPWM_TICK_TO_DUTY(tick, period) ((uint16)(((uint64)(tick) << 15U) / (uint64)(period)))

/*==================================================================================================
 *                                         LOCAL CONSTANTS
==================================================================================================*/
#define PWM_START_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

/** @brief Table of base addresses for MPWM instances. */
PWM_CONST static volatile MPWM_Type *const Mpwm_Lld_Base[MPWM_INSTANCE_COUNT] = MPWM_BASE_PTRS;

#define PWM_STOP_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

/*==================================================================================================
 *                                         LOCAL VARIABLES
==================================================================================================*/
#define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

/** @brief Table to save MPWM align mode. */
PWM_VAR static Pwm_Lld_Mpwm_AlignModeType Pwm_Lld_Mpwm_AlignMode[MPWM_INSTANCE_COUNT][MPWM_CH_COUNT];

/** @brief Table to save MPWM reload source. */
PWM_VAR static Pwm_Lld_Mpwm_RldSrcType Pwm_Lld_Mpwm_RldSrc[MPWM_INSTANCE_COUNT][MPWM_CH_COUNT];

/** @brief Table to save MPWM overflow interrupt callback pointers. */
PWM_VAR static Pwm_Lld_Mpwm_CallbackType Pwm_Lld_Mpwm_OvfCallback[MPWM_INSTANCE_COUNT][MPWM_CH_COUNT];

/** @brief Table to save MPWM channel interrupt callback pointers. */
PWM_VAR static Pwm_Lld_Mpwm_CallbackType Pwm_Lld_Mpwm_ChCallback[MPWM_INSTANCE_COUNT][MPWM_CH_COUNT];

#define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

/*==================================================================================================
 *                                         LOCAL FUNCTIONS
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/**
 * @brief       This function configures the overflow interrupt.
 * @param[in]   Base The base address of the MPWM instance.
 * @param[in]   Ch The channel number.
 * @param[in]   Enable TRUE to enable the interrupt, FALSE to disable the interrupt.
 * @return      void
 */
PWM_FUNC static inline void MPWM_OvfIntConfig(MPWM_Type volatile *Base, uint8 Ch, uint8 Enable)
{
    if (TRUE == Enable)
    {
        Base->INTE0 |= (MPWM_INTE0_CH0TOIE_MASK << Ch);
    }
    else
    {
        Base->INTE0 &= ~(MPWM_INTE0_CH0TOIE_MASK << Ch);
    }
}

/**
 * @brief       This function configures the channel interrupt.
 * @param[in]   Base The base address of the MPWM instance.
 * @param[in]   Ch The channel number.
 * @param[in]   Enable TRUE to enable the interrupt, FALSE to disable the interrupt.
 * @return      void
 */
PWM_FUNC static inline void MPWM_ChIntConfig(MPWM_Type volatile *Base, uint8 Ch, uint8 Enable)
{
    if (TRUE == Enable)
    {
        Base->INTE1 |= (MPWM_INTE1_CH0IE_MASK << Ch);
    }
    else
    {
        Base->INTE1 &= ~(MPWM_INTE1_CH0IE_MASK << Ch);
    }
}

/**
 * @brief       This function returns the overflow interrupt enable bit.
 * @param[in]   Base The base address of the MPWM instance.
 * @param[in]   Ch The channel number.
 * @return      uint8
 * @retval      TRUE if the interrupt is enabled
 * @retval      FALSE if the interrupt is disabled
 */
PWM_FUNC static inline uint8 MPWM_IsOvfIntEnabled(MPWM_Type const volatile *Base, uint8 Ch)
{
    return (uint8)((Base->INTE0 >> Ch) & MPWM_INTE0_CH0TOIE_MASK);
}

/**
 * @brief       This function returns the channel interrupt enable bit.
 * @param[in]   Base The base address of the MPWM instance.
 * @param[in]   Ch The channel number.
 * @return      uint8
 * @retval      TRUE if the interrupt is enabled
 * @retval      FALSE if the interrupt is disabled
 */
PWM_FUNC static inline uint8 MPWM_IsChIntEnabled(MPWM_Type const volatile *Base, uint8 Ch)
{
    return (uint8)((Base->INTE1 >> Ch) & MPWM_INTE1_CH0IE_MASK);
}

/**
 * @brief       This function returns the overflow interrupt flag.
 * @param[in]   Base The base address of the MPWM instance.
 * @param[in]   Ch The channel number.
 * @return      uint8
 * @retval      TRUE if the interrupt flag is set
 * @retval      FALSE if the interrupt flag is cleared
 */
PWM_FUNC static inline uint8 MPWM_GetOvfFlag(MPWM_Type const volatile *Base, uint8 Ch)
{
    return (uint8)((Base->STS0 >> Ch) & MPWM_STS0_CH0TOF_MASK);
}

/**
 * @brief       This function returns the channel interrupt flag.
 * @param[in]   Base The base address of the MPWM instance.
 * @param[in]   Ch The channel number.
 * @return      uint8
 * @retval      TRUE if the interrupt flag is set
 * @retval      FALSE if the interrupt flag is cleared
 */
PWM_FUNC static inline uint8 MPWM_GetChFlag(MPWM_Type const volatile *Base, uint8 Ch)
{
    return (uint8)((Base->STS1 >> Ch) & MPWM_STS1_CH0F_MASK);
}

/**
 * @brief       This function clears the overflow interrupt flag.
 * @param[in]   Base The base address of the MPWM instance.
 * @param[in]   Ch The channel number.
 * @return      void
 */
PWM_FUNC static inline void MPWM_ClearOvfFlag(volatile MPWM_Type *const Base, uint8 Ch)
{
    /* Clear overflow interrupt flag. */
    Base->STS0 = (uint32)MPWM_STS0_CH0TOF_MASK << Ch;
}

/**
 * @brief       This function clears the channel interrupt flag.
 * @param[in]   Base The base address of the MPWM instance.
 * @param[in]   Ch The channel number.
 * @return      void
 */
PWM_FUNC static inline void MPWM_ClearChFlag(volatile MPWM_Type *const Base, uint8 Ch)
{
    /* Clear channel interrupt flag. */
    Base->STS1 = (uint32)MPWM_STS1_CH0F_MASK << Ch;
}

/**
 * @brief       This function checks if the registers is loading.
 * @param[in]   Base The base address of the MPWM instance.
 * @param[in]   Ch The channel number.
 * @return      The registers loading status.
 * @retval      TRUE The registers is loading.
 * @retval      FALSE The registers is not loading.
 */
PWM_FUNC static inline uint8 MPWM_RegistersIsLoading(MPWM_Type const volatile *Base, uint8 Ch)
{
#ifdef MPWM_NO_LDOK_REG
    return (uint8)((Base->CH[Ch].CFG & MPWM_CH_CFG_LDOK_MASK) >> MPWM_CH_CFG_LDOK_SHIFT);
#else
    return (uint8)((Base->LDOK >> Ch) & MPWM_LDOK_CH0LDOK_MASK);
#endif
}

/**
 * @brief       This function clears the LDOK bit.
 * @param[in]   Base The base address of the MPWM instance.
 * @param[in]   Ch The channel number.
 * @return      void
 */
PWM_FUNC static void MPWM_ClearLdok(volatile MPWM_Type *const Base, uint8 Ch)
{
#ifdef MPWM_NO_CLDOK_REG
    Base->CH[Ch].CFG |= MPWM_CH_CFG_CLDOK_MASK;
#else
    Base->CLDOK |= (uint32)1U << Ch;
#endif
}

/**
 * @brief       This function sets the LDOK bit.
 * @param[in]   Base The base address of the MPWM instance.
 * @param[in]   Ch The channel number.
 * @return      void
 */
PWM_FUNC static void  MPWM_SetLdok(volatile MPWM_Type *const Base, uint8 Ch)
{
#ifdef MPWM_NO_LDOK_REG
    Base->CH[Ch].CFG |= MPWM_CH_CFG_LDOK_MASK;
#else
    Base->LDOK |= (uint32)1U << Ch;
#endif
}

/**
 * @brief       Set MPWM channel software trigger
 * @param[in]   Base The MPWM base address pointer
 * @param[in]   Ch   The MPWM channel
 * @return      void
 */
PWM_FUNC static inline void MPWM_SetChannelSwTrig(volatile MPWM_Type *const Base, uint8 Ch)
{
    Base->SWT = (uint32)0x1U << Ch;
}

/**
 * @brief       This function waits while the condition is met or timeout.
 * @param[in]   Base The base address of the MPWM instance.
 * @param[in]   Channel The channel number.
 * @return      void
 */
PWM_FUNC static void MPWM_WaitWhile(MPWM_Type const volatile *Base, uint8 Channel)
{
    uint32 Timeout = PWM_LLD_MPWM_TIMEOUT_COUNT;
    while (Timeout > 0U)
    {
        --Timeout;
        if (FALSE == MPWM_RegistersIsLoading(Base, Channel))
        {
            break;
        }
    }
}

/*==================================================================================================
 *                                         GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief       This function initializes the MPWM channel.
 * @param[in]   Instance The instance number.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Mpwm_InitChannel(uint8 Instance, const Pwm_Lld_Mpwm_ChCfgType *ChCfg)
{
#if (PWM_LLD_MPWM_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < MPWM_INSTANCE_COUNT);
    DevAssert(ChCfg != NULL_PTR);
#endif
    uint32 PeriodTick;
    uint32 DutyCycleTick;
    volatile MPWM_Type *const Base = Mpwm_Lld_Base[Instance];
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_06();
    /* Clear the LDOK bit. */
    MPWM_ClearLdok(Base, ChCfg->ChannelId);
    /* Configure the CH_CFG register. */
    /* Clear the CH_CFG before configuration. */
    Base->CH[ChCfg->ChannelId].CFG = 0U;
    /* Configure reloading sources. */
    Base->CH[ChCfg->ChannelId].CFG |= MPWM_CH_CFG_RLDSRC(ChCfg->ReloadSource);
    /* Configure debug mode. */
    Base->CH[ChCfg->ChannelId].CFG |= MPWM_CH_CFG_DBGDIS(ChCfg->DebugModeEn);
    /* Configure hardware trigger. */
    if (PWM_LLD_MPWM_RLD_SRC_HW == ChCfg->ReloadSource)
    {
        Base->CH[ChCfg->ChannelId].CFG |= MPWM_CH_CFG_HWTRIG(1U);
    }
    /* Configure CMP matching trigger output enable. */
    Base->CH[ChCfg->ChannelId].CFG |= MPWM_CH_CFG_CMPTOEN(ChCfg->CmpMatchTrigEn);
    /* Configure PERIOD matching trigger output enable. */
    Base->CH[ChCfg->ChannelId].CFG |= MPWM_CH_CFG_PERTOEN(ChCfg->PeriodMatchTrigEn);
    /* Configure clock prescaler. */
    Base->CH[ChCfg->ChannelId].CFG |= MPWM_CH_CFG_CLKPRS(ChCfg->ClockPrescaler);
    /* Configure channel mode to PWM mode. */
    if (PWM_LLD_MPWM_ALIGN_MODE_CENTER == ChCfg->AlignMode)
    {
        Base->CH[ChCfg->ChannelId].CFG |= PWM_LLD_MPWM_CH_MODE_PWM_CENTER_ALIGN;
    }
    else
    {
        Base->CH[ChCfg->ChannelId].CFG |= MPWM_CH_CFG_CHMODE(PWM_LLD_MPWM_CH_MODE_PWM);
    }
    /* Configure the POL register. */
    Base->POL &= ~((uint32)PWM_LLD_MPWM_POLARITY_INVERT << ChCfg->ChannelId);
    Base->POL |= (uint32)ChCfg->Polarity << ChCfg->ChannelId;
    /* Configure the INIT register with 0. */
    Base->INIT &= ~((uint32)MPWM_INIT_CH0INIT_MASK << ChCfg->ChannelId);
    /* Configure the CH_PERIOD register. */
    Base->CH[ChCfg->ChannelId].PERIOD = ChCfg->Period;
    PeriodTick = ChCfg->Period;
    /* Configure the default duty cycle. */
    DutyCycleTick = PWM_LLD_MPWM_DUTY_TO_TICK(ChCfg->DutyCycle, PeriodTick);
    switch (ChCfg->AlignMode)
    {
        case PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE:
            Base->CH[ChCfg->ChannelId].CMP = DutyCycleTick;
            break;
        case PWM_LLD_MPWM_ALIGN_MODE_RIGHT_EDGE:
            Base->CH[ChCfg->ChannelId].CMP = PeriodTick - DutyCycleTick;
            break;
        case PWM_LLD_MPWM_ALIGN_MODE_CENTER:
            Base->CH[ChCfg->ChannelId].CMP = (PeriodTick - DutyCycleTick) / 2;
            break;
        default:
            /* Do nothing. */
            break;
    }

    /* Install the overflow callback. */
    if (TRUE == ChCfg->OvfIrqEn)
    {
        Pwm_Lld_Mpwm_OvfCallback[Instance][ChCfg->ChannelId] = ChCfg->OvfCallback;
    }
    else
    {
        Pwm_Lld_Mpwm_OvfCallback[Instance][ChCfg->ChannelId] = NULL_PTR;
    }
    /* Install the channel callback. */
    if (TRUE == ChCfg->ChIrqEn)
    {
        Pwm_Lld_Mpwm_ChCallback[Instance][ChCfg->ChannelId] = ChCfg->ChCallback;
    }
    else
    {
        Pwm_Lld_Mpwm_ChCallback[Instance][ChCfg->ChannelId] = NULL_PTR;
    }
    /* Set the LDOK bit. */
    MPWM_SetLdok(Base, ChCfg->ChannelId);
    /* Enable channel. */
    Base->CTRL |= (uint32)MPWM_CTRL_CH0EN_MASK << ChCfg->ChannelId;
    /* Generate a software trigger if reloading source is software trigger. */
    if (PWM_LLD_MPWM_RLD_SRC_SW == ChCfg->ReloadSource)
    {
        MPWM_SetChannelSwTrig(Base, ChCfg->ChannelId);
    }
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_06();
    /* Wait until registers loading is ok or timeout, PERIOD and CMP is cleared. */
    MPWM_WaitWhile(Base, ChCfg->ChannelId);
    /* Save the PWM align mode */
    Pwm_Lld_Mpwm_AlignMode[Instance][ChCfg->ChannelId] = ChCfg->AlignMode;
    /* Save the PWM reload source */
    Pwm_Lld_Mpwm_RldSrc[Instance][ChCfg->ChannelId] = ChCfg->ReloadSource;
}

/**
 * @brief       This function de-initializes the MPWM channel.
 * @param[in]   Instance The instance number.
 * @param[in]   ChCfg The pointer to the configuration structure.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Mpwm_DeInitChannel(uint8 Instance, const Pwm_Lld_Mpwm_ChCfgType *ChCfg)
{
#if (PWM_LLD_MPWM_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < MPWM_INSTANCE_COUNT);
    DevAssert(ChCfg != NULL_PTR);
#endif
    volatile MPWM_Type *const Base = Mpwm_Lld_Base[Instance];
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_07();
    /* Clear the LDOK bit. */
    MPWM_ClearLdok(Base, ChCfg->ChannelId);
    /* Clear the CH_CFG register. */
    Base->CH[ChCfg->ChannelId].CFG = 0U;
    /* Clear the POL register. */
    Base->POL &= ~((uint32)PWM_LLD_MPWM_POLARITY_INVERT << ChCfg->ChannelId);
    /* Clear the INIT register. */
    Base->INIT &= ~((uint32)MPWM_INIT_CH0INIT_MASK << ChCfg->ChannelId);
    /* Clear the CH_PERIOD register. */
    Base->CH[ChCfg->ChannelId].PERIOD = 0U;
    /* Clear the CH_CMP register. */
    Base->CH[ChCfg->ChannelId].CMP = 0U;
    /* Clear the Ovf flag. */
    MPWM_ClearOvfFlag(Base, ChCfg->ChannelId);
    /* Clear the channel flag. */
    MPWM_ClearChFlag(Base, ChCfg->ChannelId);
    /* Clear the INTE0 register. */
    Base->INTE0 &= ~((uint32)MPWM_INTE0_CH0TOIE_MASK << ChCfg->ChannelId);
    /* Clear the INTE1 register. */
    Base->INTE1 &= ~((uint32)MPWM_INTE1_CH0IE_MASK << ChCfg->ChannelId);
    /* Set the LDOK bit. */
    MPWM_SetLdok(Base, ChCfg->ChannelId);
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_07();
    /* Wait until registers loading is ok or timeout, PERIOD and CMP is cleared. */
    MPWM_WaitWhile(Base, ChCfg->ChannelId);
    /* Use PWM mode. */
    Base->CH[ChCfg->ChannelId].CFG = MPWM_CH_CFG_CHMODE(PWM_LLD_MPWM_CH_MODE_PWM);
    /* Set the state of the PWM output signals to the idle state.  */
    Pwm_Lld_Mpwm_SetOutputToIdle(Instance, ChCfg->ChannelId, ChCfg->IdleState);
    /* Clear PWM align mode */
    Pwm_Lld_Mpwm_AlignMode[Instance][ChCfg->ChannelId] = PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE;
    Pwm_Lld_Mpwm_OvfCallback[Instance][ChCfg->ChannelId] = NULL_PTR;
    Pwm_Lld_Mpwm_ChCallback[Instance][ChCfg->ChannelId] = NULL_PTR;
}

/**
 * @brief       This function sets the duty cycle of the specified MPWM channel.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @param[in]   DutyCycle The duty cycle value. The value should be in the range of [0, 0x8000].
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Mpwm_SetDutyCycle(uint8 Instance, uint8 Channel, uint16 DutyCycle)
{
#if (PWM_LLD_MPWM_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < MPWM_INSTANCE_COUNT);
    DevAssert(Channel < MPWM_CH_COUNT);
#endif
    uint32 PeriodTick;
    uint32 DutyCycleTick;
    volatile MPWM_Type *const Base = Mpwm_Lld_Base[Instance];
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_08();
    /* Clear the LDOK bit. */
    MPWM_ClearLdok(Base, Channel);
    /* Get the newest period in the CH_PERIOD register */
    PeriodTick = Base->CH[Channel].PERIOD;
    /* Configure the duty cycle. */
    DutyCycleTick = PWM_LLD_MPWM_DUTY_TO_TICK(DutyCycle, PeriodTick);
    switch (Pwm_Lld_Mpwm_AlignMode[Instance][Channel])
    {
        case PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE:
            Base->CH[Channel].CMP = DutyCycleTick;
            break;
        case PWM_LLD_MPWM_ALIGN_MODE_RIGHT_EDGE:
            Base->CH[Channel].CMP = PeriodTick - DutyCycleTick;
            break;
        case PWM_LLD_MPWM_ALIGN_MODE_CENTER:
            Base->CH[Channel].CMP = (PeriodTick - DutyCycleTick) / 2;
            break;
        default:
            /* Do nothing. */
            break;
    }
    /* Set the LDOK bit. */
    MPWM_SetLdok(Base, Channel);
    /* Generate a software trigger if reloading source is software trigger. */
    if (PWM_LLD_MPWM_RLD_SRC_SW == Pwm_Lld_Mpwm_RldSrc[Instance][Channel])
    {
        MPWM_SetChannelSwTrig(Base, Channel);
    }
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_08();
}

/**
 * @brief       This function sets the period and duty cycle of the specified MPWM channel.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @param[in]   Period The period value.
 * @param[in]   DutyCycle The duty cycle value. The value should be in the range of [0, 0x8000].
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Mpwm_SetPeriodAndDuty
(
    uint8 Instance,
    uint8 Channel,
    uint32 Period,
    uint16 DutyCycle
)
{
#if (PWM_LLD_MPWM_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < MPWM_INSTANCE_COUNT);
    DevAssert(Channel < MPWM_CH_COUNT);
    DevAssert(Period > 0U);
#endif
    uint32 PeriodTick;
    uint32 DutyCycleTick;
    volatile MPWM_Type *const Base = Mpwm_Lld_Base[Instance];
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_09();
    /* Clear the LDOK bit. */
    MPWM_ClearLdok(Base, Channel);
    /* Configure the CH_PERIOD register. */
    Base->CH[Channel].PERIOD = Period;
    /* Get the newest period in the CH_PERIOD register */
    PeriodTick = Period;
    /* Configure the duty cycle. */
    DutyCycleTick = PWM_LLD_MPWM_DUTY_TO_TICK(DutyCycle, PeriodTick);
    switch (Pwm_Lld_Mpwm_AlignMode[Instance][Channel])
    {
        case PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE:
            Base->CH[Channel].CMP = DutyCycleTick;
            break;
        case PWM_LLD_MPWM_ALIGN_MODE_RIGHT_EDGE:
            Base->CH[Channel].CMP = PeriodTick - DutyCycleTick;
            break;
        case PWM_LLD_MPWM_ALIGN_MODE_CENTER:
            Base->CH[Channel].CMP = (PeriodTick - DutyCycleTick) / 2;
            break;
        default:
            /* Do nothing. */
            break;
    }
    /* Set the LDOK bit. */
    MPWM_SetLdok(Base, Channel);
    /* Generate a software trigger if reloading source is software trigger. */
    if (PWM_LLD_MPWM_RLD_SRC_SW == Pwm_Lld_Mpwm_RldSrc[Instance][Channel])
    {
        MPWM_SetChannelSwTrig(Base, Channel);
    }
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_09();
}

/**
 * @brief       This function sets the output to idle state.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @param[in]   IdleState The idle state.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Mpwm_SetOutputToIdle
(
    uint8 Instance,
    uint8 Channel,
    Pwm_Lld_Mpwm_OutputStateType IdleState
)
{
#if (PWM_LLD_MPWM_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < MPWM_INSTANCE_COUNT);
    DevAssert(Channel < MPWM_CH_COUNT);
#endif
    uint32 PeriodTick;
    uint32 DutyCycleTick;
    volatile MPWM_Type *const Base = Mpwm_Lld_Base[Instance];
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_10();
    /* Clear the LDOK bit. */
    MPWM_ClearLdok(Base, Channel);
    /* Get the newest period in the CH_PERIOD register */
    PeriodTick = Base->CH[Channel].PERIOD;
    /* Configure the duty cycle. */
    if (PWM_LLD_MPWM_OUTPUT_STATE_LOW == IdleState)
    {
        DutyCycleTick = 0U;
    }
    else
    {
        DutyCycleTick = PeriodTick;
    }
    switch (Pwm_Lld_Mpwm_AlignMode[Instance][Channel])
    {
        case PWM_LLD_MPWM_ALIGN_MODE_LEFT_EDGE:
            Base->CH[Channel].CMP = DutyCycleTick;
            break;
        case PWM_LLD_MPWM_ALIGN_MODE_RIGHT_EDGE:
            Base->CH[Channel].CMP = PeriodTick - DutyCycleTick;
            break;
        case PWM_LLD_MPWM_ALIGN_MODE_CENTER:
            Base->CH[Channel].CMP = (PeriodTick - DutyCycleTick) / 2;
            break;
        default:
            /* Do nothing. */
            break;
    }
    /* Set the LDOK bit. */
    MPWM_SetLdok(Base, Channel);
    /* Generate a software trigger if reloading source is software trigger. */
    if (PWM_LLD_MPWM_RLD_SRC_SW == Pwm_Lld_Mpwm_RldSrc[Instance][Channel])
    {
        MPWM_SetChannelSwTrig(Base, Channel);
    }
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_10();
    /* Wait until registers loading is ok or timeout, PERIOD and CMP is cleared. */
    MPWM_WaitWhile(Base, Channel);
}

/**
 * @brief       This function gets the output state of the specified MPWM channel.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @return      The output state.
 * @retval      PWM_LLD_MPWM_OUTPUT_STATE_LOW The output is low.
 * @retval      PWM_LLD_MPWM_OUTPUT_STATE_HIGH The output is high.
 */
PWM_FUNC Pwm_Lld_Mpwm_OutputStateType Pwm_Lld_Mpwm_GetOutputState(uint8 Instance, uint8 Channel)
{
#if (PWM_LLD_MPWM_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < MPWM_INSTANCE_COUNT);
    DevAssert(Channel < MPWM_CH_COUNT);
#endif
    Pwm_Lld_Mpwm_OutputStateType OutputState;
    MPWM_Type const volatile *Base = Mpwm_Lld_Base[Instance];
    /* Get the output state. */
    if (0U != (Base->IOSTS & ((uint32)MPWM_IOSTS_CH0IO_MASK << Channel)))
    {
        OutputState = PWM_LLD_MPWM_OUTPUT_STATE_HIGH;
    }
    else
    {
        OutputState = PWM_LLD_MPWM_OUTPUT_STATE_LOW;
    }
    return OutputState;
}

/**
 * @brief       This function configures the MPWM channel interrupt.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @param[in]   Enable TRUE to enable the interrupt, FALSE to disable the interrupt.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Mpwm_ChIntConfig(uint8 Instance, uint8 Channel, uint8 Enable)
{
#if (PWM_LLD_MPWM_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < MPWM_INSTANCE_COUNT);
    DevAssert(Channel < MPWM_CH_COUNT);
#endif
    volatile MPWM_Type *const Base = Mpwm_Lld_Base[Instance];
    /* Clear channel interrupt flag */
    MPWM_ClearChFlag(Base, Channel);

    /* Configure the channel interrupt. */
    MPWM_ChIntConfig(Base, Channel, Enable);
}

/**
 * @brief       This function configures the MPWM channel overflow interrupt.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @param[in]   Enable TRUE to enable the interrupt, FALSE to disable the interrupt.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Mpwm_OvfIntConfig(uint8 Instance, uint8 Channel, uint8 Enable)
{
#if (PWM_LLD_MPWM_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < MPWM_INSTANCE_COUNT);
    DevAssert(Channel < MPWM_CH_COUNT);
#endif
    volatile MPWM_Type *const Base = Mpwm_Lld_Base[Instance];

    /* Clear the channel overflow interrupt flag */
    MPWM_ClearOvfFlag(Base, Channel);

    /* Configure the channel overflow interrupt. */
    MPWM_OvfIntConfig(Base, Channel, Enable);
}

/**
 * @brief       MPWM overflow interrupt handler.
 * @details     This function handles the different MPWM channels overflow interrupt.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Mpwm_Ovf_IrqHandler(uint8 Instance, uint8 Channel)
{
#if (PWM_LLD_MPWM_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < MPWM_INSTANCE_COUNT);
    DevAssert(Channel < MPWM_CH_COUNT);
#endif
    volatile MPWM_Type *const Base = Mpwm_Lld_Base[Instance];
    /* GCOVR_EXCL_START */
    /* The (FALSE == MPWM_GetOvfFlag(Base, Channel)) branch cannot be reached normally. */
    if (TRUE == MPWM_GetOvfFlag(Base, Channel))
        /* GCOVR_EXCL_STOP */
    {
        /* Clear interrupt flag */
        MPWM_ClearOvfFlag(Base, Channel);
        /* GCOVR_EXCL_START */
        /* The (FALSE == MPWM_IsOvfIntEnabled(Base, Channel)) branch cannot be reached normally. */
        if ((TRUE == MPWM_IsOvfIntEnabled(Base, Channel)) &&
                (Pwm_Lld_Mpwm_OvfCallback[Instance][Channel] != NULL_PTR))
            /* GCOVR_EXCL_STOP */
        {
            Pwm_Lld_Mpwm_OvfCallback[Instance][Channel]();
        }
    }
}

/**
 * @brief       MPWM channel interrupt handler.
 * @details     This function handles the different MPWM channels interrupt.
 * @param[in]   Instance The instance number.
 * @param[in]   Channel The channel number.
 * @return      void
 */
PWM_FUNC void Pwm_Lld_Mpwm_IrqHandler(uint8 Instance, uint8 Channel)
{
#if (PWM_LLD_MPWM_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < MPWM_INSTANCE_COUNT);
    DevAssert(Channel < MPWM_CH_COUNT);
#endif
    volatile MPWM_Type *const Base = Mpwm_Lld_Base[Instance];
    /* GCOVR_EXCL_START */
    /* The (FALSE == MPWM_GetChFlag(Base, Channel)) branch cannot be reached normally. */
    if (TRUE == MPWM_GetChFlag(Base, Channel))
        /* GCOVR_EXCL_STOP */
    {
        /* Clear interrupt flag */
        MPWM_ClearChFlag(Base, Channel);
        /* GCOVR_EXCL_START */
        /* The (FALSE == MPWM_IsChIntEnabled(Base, Channel)) branch cannot be reached normally. */
        if ((TRUE == MPWM_IsChIntEnabled(Base, Channel)) &&
                (Pwm_Lld_Mpwm_ChCallback[Instance][Channel] != NULL_PTR))
            /* GCOVR_EXCL_STOP */
        {
            Pwm_Lld_Mpwm_ChCallback[Instance][Channel]();
        }
    }
}

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

