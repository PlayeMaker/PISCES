/**
 * @file    Wdg_Lld.c
 * @version V0.9.1
 *
 * @brief   YUNTU Wdg_Lld module interface
 * @details API implementation for Wdg_Lld driver
 *
 * @addtogroup WDG_LLD_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : WDG
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

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Wdg_Lld.h"
#include "Wdg_Lld_Reg.h"
#include "Std_Types.h"
#include "SchM_Wdg_180_Inst0.h"
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
#include "Devassert.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define WDG_LLD_VENDOR_ID_C                      (180)
#define WDG_LLD_AR_RELEASE_MAJOR_VERSION_C       (4)
#define WDG_LLD_AR_RELEASE_MINOR_VERSION_C       (4)
#define WDG_LLD_AR_RELEASE_REVISION_VERSION_C    (0)
#define WDG_LLD_SW_MAJOR_VERSION_C               (0)
#define WDG_LLD_SW_MINOR_VERSION_C               (9)
#define WDG_LLD_SW_PATCH_VERSION_C               (1)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Wdg_Lld.c and Wdg_Lld.h are of the same vendor */
#if (WDG_LLD_VENDOR_ID_C != WDG_LLD_VENDOR_ID)
#error "Wdg_Lld.c and Wdg_Lld.h have different vendor ids"
#endif

/* Check if Wdg_Lld.c and Wdg_Lld.h are of the same Autosar version */
#if ((WDG_LLD_AR_RELEASE_MAJOR_VERSION_C != WDG_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_LLD_AR_RELEASE_MINOR_VERSION_C != WDG_LLD_AR_RELEASE_MINOR_VERSION) || \
     (WDG_LLD_AR_RELEASE_REVISION_VERSION_C != WDG_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_Lld.c and Wdg_Lld.h are different"
#endif

/* Check if Wdg_Lld.c and Wdg_Lld.h are of the same software version */
#if ((WDG_LLD_SW_MAJOR_VERSION_C != WDG_LLD_SW_MAJOR_VERSION) || \
     (WDG_LLD_SW_MINOR_VERSION_C != WDG_LLD_SW_MINOR_VERSION) || \
     (WDG_LLD_SW_PATCH_VERSION_C != WDG_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Lld.c and Wdg_Lld.h are different"
#endif

#if (WDG_180_INST0_ENABLE == STD_ON)

/*==================================================================================================
 *                                         LOCAL CONSTANTS
==================================================================================================*/
#define WDG_180_INST0_START_SEC_CONST_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"

/** @brief Table of base addresses for WDG instances. */
WDG_180_INST0_CONST static volatile WDG_Type *const Wdg_Lld_Base[WDG_INSTANCE_COUNT] = WDG_BASE_PTRS;

#define WDG_180_INST0_STOP_SEC_CONST_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"     /* NOSONAR, memory map */

/*==================================================================================================
 *                                       LOCAL VARIABLES
==================================================================================================*/
#define WDG_180_INST0_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"           /* NOSONAR, memory map */

/** @brief Table to save WDG callback pointers. */
WDG_180_INST0_VAR static Wdg_Lld_CallbackType Wdg_Lld_Callback[WDG_INSTANCE_COUNT];

#define WDG_180_INST0_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Wdg_180_Inst0_MemMap.h"           /* NOSONAR, memory map */

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (WDG_180_INST0_RUN_ON_ROM == STD_ON)
#define WDG_180_INST0_START_SEC_CODE
#else
#define WDG_180_INST0_START_SEC_RAMCODE
#endif
#include "Wdg_180_Inst0_MemMap.h"           /* NOSONAR, memory map */

/**
 * @brief       Updates the WDG control register.
 * @details     This function writes the WDG control register.
 * @param[in]   Base WDG base pointer
 * @param[in]   Cr WDG control register value
 * @return      void
 */
WDG_180_INST0_FUNC static void WDG_UpdateCr(volatile WDG_Type *const Base, uint32 Cr)
{
    Base->CR = Cr;
}

/**
 * @brief       Updates the WDG timer overflow register.
 * @details     This function writes the WDG timer overflow register.
 * @param[in]   Base WDG base pointer
 * @param[in]   Tovr WDG timer overflow register value
 * @return      void
 */
WDG_180_INST0_FUNC static void WDG_UpdateTovr(volatile WDG_Type *const Base, uint32 Tovr)
{
    Base->TOVR = Tovr;
}

/**
 * @brief       Updates the WDG window register.
 * @details     This function writes the WDG window register.
 * @param[in]   Base WDG base pointer
 * @param[in]   Wvr WDG window register value
 * @return      void
 */
WDG_180_INST0_FUNC static void WDG_UpdateWvr(volatile WDG_Type *const Base, uint32 Wvr)
{
    Base->WVR = Wvr;
}

/**
 * @brief       Enables the WDG window mode.
 * @details     This function enables the WDG window mode.
 * @param[in]   Base WDG base pointer
 * @return      void
 */
WDG_180_INST0_FUNC static void WDG_EnableWindowMode(volatile WDG_Type *const Base)
{
    Base->CR |= WDG_CR_WIN_MASK;
}

/**
 * @brief       Verifies if the WDG is enabled.
 * @details     This function verifies the State of the WDG.
 * @param[in]   Base WDG base pointer
 * @return      uint8
 * @retval      TRUE if the WDG is enabled
 * @retval      FALSE if the WDG is disabled
 */
WDG_180_INST0_FUNC static uint8 WDG_IsEnabled(WDG_Type const volatile *Base)
{
    return (uint8)((Base->CR & WDG_CR_EN_MASK) >> WDG_CR_EN_SHIFT);
}

/**
 * @brief       Enables the WDG.
 * @details     This function enables the WDG.
 * @param[in]   Base WDG base pointer
 * @return      void
 */
WDG_180_INST0_FUNC static void WDG_Enable(volatile WDG_Type *const Base)
{
    Base->CR |= WDG_CR_EN_MASK;
}

/**
 * @brief       Disables the WDG.
 * @details     This function disables the WDG.
 * @param[in]   Base WDG base pointer
 * @return      void
 */
WDG_180_INST0_FUNC static void WDG_Disable(volatile WDG_Type *const Base)
{
    Base->CR &= ~WDG_CR_EN_MASK;
}

/**
 * @brief       Verifies if the WDG interrupt is enabled.
 * @details     This function verifies if the WDG interrupt is enabled.
 * @param[in]   Base WDG base pointer
 * @return      uint8
 * @retval      TRUE if the interrupt is enabled
 * @retval      FALSE if the interrupt is disabled
 */
WDG_180_INST0_FUNC static uint8 WDG_IsIntEnabled(WDG_Type const volatile *Base)
{
    return (uint8)((Base->CR & WDG_CR_IBR_MASK) >> WDG_CR_IBR_SHIFT);
}

/**
 * @brief       Verifies if the WDG is hard-locked.
 * @details     This function verifies if the WDG is hard-locked. If the WDG is hard-locked,
 *              reconfiguration of the registers is not allowed.
 * @param[in]   Base WDG base pointer
 * @return      uint8
 * @retval      TRUE if the WDG is hard-locked
 * @retval      FALSE if the WDG is not hard-locked
 */
WDG_180_INST0_FUNC static uint8 WDG_IsHardLocked(WDG_Type const volatile *Base)
{
    return (uint8)((Base->LR & WDG_LR_HL_MASK) >> WDG_LR_HL_SHIFT) ;
}

/**
 * @brief       Verifies if the WDG is soft-locked.
 * @details     This function verifies if the WDG is soft-locked. If the WDG is soft-locked,
 *              reconfiguration of the registers is not allowed.
 * @param[in]   Base WDG base pointer
 * @return      uint8
 * @retval      TRUE if the WDG is soft-locked
 * @retval      FALSE if the WDG is not soft-locked
 */
WDG_180_INST0_FUNC static uint8 WDG_IsSoftLocked(WDG_Type const volatile *Base)
{
    return (uint8)((Base->LR & WDG_LR_SL_MASK) >> WDG_LR_SL_SHIFT);
}

/**
 * @brief       Unlocks the WDG.
 * @details     This function unlocks the WDG. The WDG can be unlocked only if the module is
 *              locked.
 * @param[in]   Base WDG base pointer
 * @return      void
 */
WDG_180_INST0_FUNC static void WDG_Unlock(volatile WDG_Type *const Base)
{
    SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_07();
    Base->SVCR = FEATURE_WDG_UNLOCK_VALUE_1;
    /* Avoid these 2 steps are optimized by compiler. */
    (void)Base->SVCR;
    Base->SVCR = FEATURE_WDG_UNLOCK_VALUE_2;
    SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_07();
}

/**
 * @brief       Refreshes the WDG counter
 * @param[in]   Base WDG base pointer.
 * @return      void
 */
WDG_180_INST0_FUNC static void WDG_Trigger(volatile WDG_Type *const Base)
{
    /* Service WDG should be within an atomic sequence. */
    SchM_Enter_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_08();
    /* Write first value of the service key */
    Base->SVCR = FEATURE_WDG_TRIGGER_VALUE_1;
    /* Avoid these 2 steps are optimized by compiler. */
    (void)Base->SVCR;
    /* Write second value of the service key */
    Base->SVCR = FEATURE_WDG_TRIGGER_VALUE_2;
    SchM_Exit_Wdg_180_Inst0_WDG_EXCLUSIVE_AREA_08();
}

#if (WDG_180_INST0_DISABLE_ALLOWED == STD_ON)
/**
 * @brief       De-initialize the WDG.
 * @details     This function de-initialize the WDG.
 * @param[in]   Base WDG base pointer
 * @return      void
 */
WDG_180_INST0_FUNC static void WDG_Deinit(volatile WDG_Type *const Base)
{
    /* Reset control register, disable WDG */
    Base->CR = FEATURE_WDG_CR_RESET_VALUE & (~WDG_CR_EN_MASK);
    /* Reset timeout value register */
    Base->TOVR = FEATURE_WDG_TOVR_RESET_VALUE;
    /* Reset window value register */
    Base->WVR = FEATURE_WDG_WVR_RESET_VALUE;
    /* Clear the interrupt flag */
    Base->INTF = WDG_INTF_IF_MASK;
    /* Reset the lock register */
    Base->LR = FEATURE_WDG_LR_RESET_VALUE;
}
#endif

/**
 * @brief       Gets the Interrupt Flag.
 * @details     This function gets the Interrupt Flag (IF).
 * @param[in]   Base WDG Base pointer.
 * @return      uint8
 * @retval      TRUE if the interrupt flag is set
 * @retval      FALSE if the interrupt flag is not set
 */
WDG_180_INST0_FUNC static uint8 WDG_GetIntFlag(WDG_Type const volatile *Base)
{
    return (uint8)((Base->INTF & WDG_INTF_IF_MASK) >> WDG_INTF_IF_SHIFT);
}

/**
 * @brief       Clears the Interrupt Flag.
 * @details     This function clears the Interrupt Flag (IF).
 * @param[in]   Base WDG Base pointer.
 * @return      void
 */
WDG_180_INST0_FUNC static void WDG_ClearIntFlag(volatile WDG_Type *const Base)
{
    Base->INTF |= WDG_INTF_IF_MASK;
}

/**
 * @brief       Gets the WDG lock status.
 * @details     This function gets the WDG lock status.
 * @param[in]   Base WDG base pointer
 * @return      Wdg_Lld_LockType
 * @retval      WDG_LLD_UNLOCK if the WDG is unlocked
 * @retval      WDG_LLD_SOFTLOCK if the WDG is soft-locked
 * @retval      WDG_LLD_HARDLOCK if the WDG is hard-locked
 */
WDG_180_INST0_FUNC static Wdg_Lld_LockType WDG_Lld_GetLock(WDG_Type const volatile *Base)
{
    Wdg_Lld_LockType Lock;

    switch ((Base->LR & (WDG_LR_SL_MASK | WDG_LR_HL_MASK)) >> WDG_LR_SL_SHIFT)
    {
        case 0U:
            Lock = WDG_LLD_UNLOCK;
            break;
        case 1U:
            Lock = WDG_LLD_SOFTLOCK;
            break;
        /*GCOVR_EXCL_START*/
        /*When hard lock bit set, the CR, WIN, TO are read-only. once set, the bit can only be clear by reset.
          Therefore, soft lock are tested in integration testing, while hard lock are not. */
        case 2U:
            Lock = WDG_LLD_HARDLOCK;
            break;
        default:
            Lock = WDG_LLD_HARDLOCK;
            break;
        /*GCOVR_EXCL_STOP*/
    }

    return Lock;
}

/**
 * @brief       Locks the WDG.
 * @details     This function locks the WDG.
 * @param[in]   Base WDG base pointer
 * @param[in]   LockConfig Lock configuration
 * @return      void
 */
WDG_180_INST0_FUNC static void WDG_Lld_Lock(volatile WDG_Type *const Base, Wdg_Lld_LockType LockConfig)
{
    switch (LockConfig)
    {
        case WDG_LLD_SOFTLOCK:
            Base->LR |= WDG_LR_SL(1);
            break;
        /*GCOVR_EXCL_START*/
        /*When hard lock bit set, the CR, WIN, TO are read-only. once set, the bit can only be clear by reset.
          Therefore, soft lock are tested in integration testing, while hard lock are not.*/
        case WDG_LLD_HARDLOCK:
            Base->LR |= WDG_LR_HL(1);
            break;
        default:
            /* Do nothing. */
            break;
        /*GCOVR_EXCL_STOP*/
    }
}

/**
 * @brief       This function unlocks the WDG registers with timeout.
 * @param[in]   Base WDG base pointer
 * @return      Std_ReturnType
 * @retval      E_OK WDG registers unlocked
 * @retval      E_NOT_OK WDG registers not unlocked
 */
WDG_180_INST0_FUNC static Std_ReturnType Wdg_Lld_Unlock(volatile WDG_Type *const Base)
{
    uint32 Timeout = WDG_180_INST0_TIMEOUT_COUNT;
    Std_ReturnType Ret = E_OK;

    /* Hard lock, when this bit set, the CR, WIN, TO are read-only. once set, the bit can only be
     * clear by reset.
     */
    if (TRUE == WDG_IsHardLocked(Base))
    {
        /*GCOVR_EXCL_START*/
        /*When hard lock bit set, the CR, WIN, TO are read-only. once set, the bit can only be clear by reset.
           Therefore, soft lock are tested in integration testing, while hard lock are not.*/
        Ret = E_NOT_OK;
        /*GCOVR_EXCL_STOP*/
    }
    /* Soft lock, when this bit set, the CR, WIN, TO are read-only. this bit can be clear by
     * writing a valid sequence to SVR register.
     */
    else if (TRUE == WDG_IsSoftLocked(Base))
    {
        WDG_Unlock(Base);
        /* Wait until registers are unlocked or timeout. */
        while ((TRUE == WDG_IsSoftLocked(Base)) && (Timeout > 0U))
        {
            --Timeout;
        }
        /* Timeout. */
        if (Timeout == 0U)
        {
            /* Soft lock is enabled again to avoid unlock sequence successfully after timeout
             * expired.
             */
            WDG_Lld_Lock(Base, WDG_LLD_SOFTLOCK);
            Ret = E_NOT_OK;
        }
    }
    else
    {
        /* Do nothing. */
    }

    return Ret;
}

/**
 * @brief       This function checks the timeout value and window value.
 * @param[in]   TimeoutValue Timeout value
 * @param[in]   WindowValue Window value
 * @return      Std_ReturnType
 * @retval      E_OK Timeout value and window value are valid
 * @retval      E_NOT_OK Timeout value and window value are invalid
 */
WDG_180_INST0_FUNC static Std_ReturnType Wdg_Lld_CheckTimeout(uint32 TimeoutValue, uint32 WindowValue)
{
    Std_ReturnType Ret = E_OK;

#if (FEATURE_WDG_MINIMUM_TIMEOUT_VALUE > 0U)
    if (TimeoutValue < FEATURE_WDG_MINIMUM_TIMEOUT_VALUE)
    {
        Ret = E_NOT_OK;
    }
#endif
    if ((WindowValue != 0U) && (TimeoutValue <= WindowValue))
    {
        Ret = E_NOT_OK;
    }

    return Ret;
}

/**
 * @brief       This function configures the WDG hardware without checking.
 * @param[in]   Base WDG base pointer
 * @param[in]   WdgConfig WDG hardware configuration
 * @return      void
 */
WDG_180_INST0_FUNC static void Wdg_Lld_ConfigRegister(volatile WDG_Type *const Base, const Wdg_Lld_ConfigType *const WdgConfig)
{
    uint32 Cr;

    Cr = WDG_CR_RIA(WdgConfig->ResetInvalidApbEnable);
    Cr |= WDG_CR_WIN(WdgConfig->WindowMode);
    Cr |= WDG_CR_IBR(WdgConfig->InterruptBeforeReset);
    Cr |= WDG_CR_CLKSRC(WdgConfig->ClockSource);
    Cr |= WDG_CR_DSDIS(WdgConfig->DisableInDeepSleepMode);
    Cr |= WDG_CR_DBGDIS(WdgConfig->DisableInDebugMode);

    WDG_UpdateCr(Base, Cr);
    WDG_ClearIntFlag(Base);
    WDG_UpdateTovr(Base, WdgConfig->TimerOverflowValue);
    WDG_UpdateWvr(Base, WdgConfig->WindowValue);
}

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief       This function initializes the WDG hardware.
 * @param[in]   Instance WDG hardware instance
 * @param[in]   WdgConfig WDG hardware configuration
 * @return      Std_ReturnType
 * @retval      E_OK WDG hardware initialization success
 * @retval      E_NOT_OK WDG hardware initialization failed
 */
WDG_180_INST0_FUNC Std_ReturnType Wdg_Lld_Init(uint8 Instance, const Wdg_Lld_ConfigType *const WdgConfig)
{
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < WDG_INSTANCE_COUNT);
    DevAssert(WdgConfig != NULL_PTR);
#endif

    Std_ReturnType Ret;
    uint8 Enabled;
    volatile WDG_Type *const Base = Wdg_Lld_Base[Instance];

    Ret = Wdg_Lld_Unlock(Base);
    if (Ret == E_OK)
    {
        Enabled = WDG_IsEnabled(Base);
        if (TRUE == Enabled)
        {
            WDG_Disable(Base);
        }
        Ret = Wdg_Lld_CheckTimeout(WdgConfig->TimerOverflowValue, WdgConfig->WindowValue);
        if (Ret == E_OK)
        {
            /* Configure WDG register without enable. */
            Wdg_Lld_ConfigRegister(Base, WdgConfig);
            if (TRUE == WdgConfig->InterruptBeforeReset)
            {
                Wdg_Lld_Callback[Instance] = WdgConfig->WdgCallback;
            }
            else
            {
                Wdg_Lld_Callback[Instance] = NULL_PTR;
            }
            /* Enable WDG. */
            WDG_Enable(Base);
            /* Lock WDG */
            WDG_Lld_Lock(Base, WdgConfig->Lock);
        }
    }

    return Ret;
}

#if (WDG_180_INST0_DISABLE_ALLOWED == STD_ON)
/**
 * @brief       This function de-initializes the WDG driver
 * @param[in]   Instance WDG instance
 * @return      Std_ReturnType
 * @retval      E_OK WDG de-initialization success
 * @retval      E_NOT_OK WDG de-initialization failed
 */
WDG_180_INST0_FUNC Std_ReturnType Wdg_Lld_DeInit(uint8 Instance)
{
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < WDG_INSTANCE_COUNT);
#endif

    Std_ReturnType Ret;
    volatile WDG_Type *const Base = Wdg_Lld_Base[Instance];

    Ret = Wdg_Lld_Unlock(Base);
    if (Ret == E_OK)
    {
        WDG_Deinit(Base);
        WDG_Trigger(Base);
        Wdg_Lld_Callback[Instance] = NULL_PTR;
    }

    return Ret;
}
#endif /* WDG_180_INST0_DISABLE_ALLOWED */

/**
 * @brief       This function refreshes the WDG counter
 * @param[in]   Instance WDG instance
 * @return      void
 */
WDG_180_INST0_FUNC void Wdg_Lld_Service(uint8 Instance)
{
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < WDG_INSTANCE_COUNT);
#endif

    volatile WDG_Type *const Base = Wdg_Lld_Base[Instance];

    WDG_Trigger(Base);
}

/**
 * @brief       This function reconfigures the WDG hardware.
 * @param[in]   Instance WDG hardware instance
 * @param[in]   WdgConfig WDG hardware configuration
 * @return      Std_ReturnType
 * @retval      E_OK WDG hardware reconfiguration success
 * @retval      E_NOT_OK WDG hardware reconfiguration failed
 */
WDG_180_INST0_FUNC Std_ReturnType Wdg_Lld_Config(uint8 Instance, const Wdg_Lld_ConfigType *const WdgConfig)
{
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < WDG_INSTANCE_COUNT);
    DevAssert(WdgConfig != NULL_PTR);
#endif

    Std_ReturnType Ret;
    uint8 Enabled;
    volatile WDG_Type *const Base = Wdg_Lld_Base[Instance];

    Ret = Wdg_Lld_CheckTimeout(WdgConfig->TimerOverflowValue, WdgConfig->WindowValue);
    if (Ret == E_OK)
    {
        Ret = Wdg_Lld_Unlock(Base);
        if (Ret == E_OK)
        {
            Enabled = WDG_IsEnabled(Base);
            if (TRUE == Enabled)
            {
                WDG_Disable(Base);
            }
            /* Configure WDG register without enable. */
            Wdg_Lld_ConfigRegister(Base, WdgConfig);
            if (TRUE == WdgConfig->InterruptBeforeReset)
            {
                Wdg_Lld_Callback[Instance] = WdgConfig->WdgCallback;
            }
            else
            {
                Wdg_Lld_Callback[Instance] = NULL_PTR;
            }
            /* If WDG was enabled, enable it after configuration is done */
            if (TRUE == Enabled)
            {
                WDG_Enable(Base);
            }
            /* Lock WDG */
            WDG_Lld_Lock(Base, WdgConfig->Lock);
        }
    }

    return Ret;
}

/**
 * @brief       This function sets the WDG hardware timeout value.
 * @param[in]   Instance WDG hardware instance
 * @param[in]   TimeoutValue WDG hardware timeout value
 * @param[in]   WindowValue WDG hardware window value
 * @return      Std_ReturnType
 * @retval      E_OK set the WDG hardware timeout value success
 * @retval      E_NOT_OK set the WDG hardware timeout value failed
 */
WDG_180_INST0_FUNC Std_ReturnType Wdg_Lld_SetTimeout(uint8 Instance, uint32 TimeoutValue, uint32 WindowValue)
{
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < WDG_INSTANCE_COUNT);
#endif

    Std_ReturnType Ret;
    Wdg_Lld_LockType Lock;
    volatile WDG_Type *const Base = Wdg_Lld_Base[Instance];

    Lock = WDG_Lld_GetLock(Base);
    Ret = Wdg_Lld_CheckTimeout(TimeoutValue, WindowValue);
    if (Ret == E_OK)
    {
        /* Unlock WDG before update registers. */
        Ret = Wdg_Lld_Unlock(Base);
        if (Ret == E_OK)
        {
            /* Disable WDG. */
            WDG_Disable(Base);
            /* Update timer overflow value. */
            WDG_UpdateTovr(Base, TimeoutValue);
            if (WindowValue > 0U)
            {
                /* Update window value. */
                WDG_UpdateWvr(Base, WindowValue);
                /* Enable window mode. */
                WDG_EnableWindowMode(Base);
            }
            /* Enable WDG. */
            WDG_Enable(Base);
            /* Lock WDG */
            WDG_Lld_Lock(Base, Lock);
        }
    }

    return Ret;
}

/**
 * @brief       This function starts the WDG hardware.
 * @param[in]   Instance WDG hardware instance
 * @return      Std_ReturnType
 * @retval      E_OK WDG hardware start success
 * @retval      E_NOT_OK WDG hardware start failed
 */
WDG_180_INST0_FUNC Std_ReturnType Wdg_Lld_StartTimer(uint8 Instance)
{
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < WDG_INSTANCE_COUNT);
#endif

    Std_ReturnType Ret;
    Wdg_Lld_LockType Lock;
    volatile WDG_Type *const Base = Wdg_Lld_Base[Instance];

    Lock = WDG_Lld_GetLock(Base);
    Ret = Wdg_Lld_Unlock(Base);
    if (Ret == E_OK)
    {
        WDG_Enable(Base);
        WDG_Lld_Lock(Base, Lock);
    }

    return Ret;
}

/**
 * @brief       This function stops the WDG hardware.
 * @param[in]   Instance WDG hardware instance
 * @return      Std_ReturnType
 * @retval      E_OK WDG hardware stop success
 * @retval      E_NOT_OK WDG hardware stop failed
 */
WDG_180_INST0_FUNC Std_ReturnType Wdg_Lld_StopTimer(uint8 Instance)
{
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < WDG_INSTANCE_COUNT);
#endif

    Std_ReturnType Ret;
    Wdg_Lld_LockType Lock;
    volatile WDG_Type *const Base = Wdg_Lld_Base[Instance];

    Lock = WDG_Lld_GetLock(Base);
    Ret = Wdg_Lld_Unlock(Base);
    if (Ret == E_OK)
    {
        WDG_Disable(Base);
        WDG_Lld_Lock(Base, Lock);
    }

    return Ret;
}

/**
 * @brief       WDG instance interrupt handler.
 * @details     This function handles the different WDG instances interrupt.
 * @param[in]   Instance WDG hardware instance
 * @return      void
 */
WDG_180_INST0_FUNC void Wdg_Lld_IrqHandler(uint8 Instance)
{
#if (WDG_180_INST0_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < WDG_INSTANCE_COUNT);
#endif

    volatile WDG_Type *const Base = Wdg_Lld_Base[Instance];

    if (TRUE == WDG_GetIntFlag(Base))
    {
        /* Clear interrupt flag */
        WDG_ClearIntFlag(Base);
        if ((TRUE == WDG_IsIntEnabled(Base)) &&
                (Wdg_Lld_Callback[Instance] != NULL_PTR))
        {
            Wdg_Lld_Callback[Instance]();
        }
    }
}

#if (WDG_180_INST0_RUN_ON_ROM == STD_ON)
#define WDG_180_INST0_STOP_SEC_CODE
#else
#define WDG_180_INST0_STOP_SEC_RAMCODE
#endif
#include "Wdg_180_Inst0_MemMap.h"           /* NOSONAR, memory map */

#endif /* #if (WDG_180_INST0_ENABLE == STD_ON) */

#ifdef __cplusplus
}
#endif

/** @} */

