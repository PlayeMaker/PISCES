/**
 * @file    Crypto_Lld_Trng.c
 *
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4 MCAL
 *   Platform             : ARM
 *   Peripheral           : Crypto TRNG
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
                                              INCLUDE FILES
==================================================================================================*/
#include "Crypto_Lld_Reg.h"
#include "Crypto_Cfg.h"
#include "Crypto_Lld_Trng.h"

/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_LLD_TRNG_VENDOR_ID_C                             (180)
#define CRYPTO_LLD_TRNG_AR_RELEASE_MAJOR_VERSION_C              (4)
#define CRYPTO_LLD_TRNG_AR_RELEASE_MINOR_VERSION_C              (4)
#define CRYPTO_LLD_TRNG_AR_RELEASE_REVISION_VERSION_C           (0)
#define CRYPTO_LLD_TRNG_SW_MAJOR_VERSION_C                      (0)
#define CRYPTO_LLD_TRNG_SW_MINOR_VERSION_C                      (9)
#define CRYPTO_LLD_TRNG_SW_PATCH_VERSION_C                      (1)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CRYPTO_LLD_TRNG header file are of the same vendor */
#if (CRYPTO_LLD_TRNG_VENDOR_ID_C != CRYPTO_LLD_TRNG_VENDOR_ID)
#error "Crypto_Lld_Trng.c and Crypto_Lld_Trng.h have different vendor ids"
#endif

/* Check if source file and CRYPTO_LLD_TRNG header file are of the same Autosar version */
#if (( CRYPTO_LLD_TRNG_AR_RELEASE_MAJOR_VERSION_C != CRYPTO_LLD_TRNG_AR_RELEASE_MAJOR_VERSION) || \
      ( CRYPTO_LLD_TRNG_AR_RELEASE_MINOR_VERSION_C != CRYPTO_LLD_TRNG_AR_RELEASE_MINOR_VERSION) || \
      ( CRYPTO_LLD_TRNG_AR_RELEASE_REVISION_VERSION_C != CRYPTO_LLD_TRNG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Crypto_Lld_Trng.c and Crypto_Lld_Trng.h are different"
#endif

/* Check if source file and CRYPTO_LLD_TRNG header file are of the same Software version */
#if (( CRYPTO_LLD_TRNG_SW_MAJOR_VERSION_C != CRYPTO_LLD_TRNG_SW_MAJOR_VERSION) || \
      ( CRYPTO_LLD_TRNG_SW_MINOR_VERSION_C != CRYPTO_LLD_TRNG_SW_MINOR_VERSION) || \
      ( CRYPTO_LLD_TRNG_SW_PATCH_VERSION_C != CRYPTO_LLD_TRNG_SW_PATCH_VERSION))
#error "Software Version Numbers of Crypto_Lld_Trng.c and Crypto_Lld_Trng.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#define NUMINBYTE_OF_U32            (4U)
#define LENGTH_OF_U8                (8U)
#define LENGTH_OF_U16               (16U)
#define LENGTH_OF_U24               (24U)
#define LSBYTE_OF_U32               (0x000000FFU)

#define TRNG_DEF_RUNMAX             (0x22U)
#define TRNG_DEF_RETRYCNT           (0x0FU)
#define TRNG_DEF_SIZE               (0x200U)
#define TRNG_DEF_DELAY              (0x1A0U)
#define TRNG_DEF_FRQMIN             (0x00000010U)
#define TRNG_DEF_FRQMAX             (0x003FFFFFU)
#define TRNG_DEF_BITRANG            (0x2F0U)
#define TRNG_DEF_BITMAX             (0x300U)

#define TRNG_DEF_CTRL               (0x01220020U)
#define TRNG_DEF_SDCTL              (0x0c8009c4U)
#define TRNG_HW_FRQMAX              (0x00006400U)
#define TRNG_HW_FRQMIN              (0x00000640U)
#define TRNG_DEF_SCML               (0x010c0568U)
/**
 * @page misra_violations MISRA-C:2012 violations list
 *
 * PRQA S 2985 Rule-2.2: This operation is redundant. The value of the result is always that of the left-hand operand.
 * PRQA S 3415 Rule-13.5 Right hand operand of '&&' or '||' is an expression with persistent side effects.
*/
/*
*  MR12 Rule-2.2 VIOLATION: This file is used to configure registers,there will be some bits-operations like & or | or >>
*  according to bit-wide defined by registers, which are considered redundant operations.it is safe.
*/


/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/



/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                    GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*******************************************************************************
 * Variables
 ******************************************************************************/

#define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"
CRYPTO_VAR static Crypto_Lld_Trng_ConfigType Trng_Lld_CfgSetting;
#define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"
/*! @brief Table of base addresses for TRNG instances. */
CRYPTO_VAR static  volatile TRNG_Type *const  Trng_Lld_Base[TRNG_INSTANCE_COUNT] = TRNG_BASE_PTRS;

#define CRYPTO_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
/*FUNCTION**********************************************************************
 *
 * Function Name : Trng_Enable
 * Description   : This function enable the TRNG module.
 *
 *END**************************************************************************/
CRYPTO_FUNC static void Trng_Enable(volatile TRNG_Type *const Base)
{
    Base->CTRL |= TRNG_CTRL_TRNG_EN(1);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : TRNG_RegInit
 * Description   : This function restores the TRNG module to reset value.
 *
 *END**************************************************************************/
CRYPTO_FUNC static void Trng_RegInit(volatile TRNG_Type *const Base)
{

    Base->CTRL = TRNG_DEF_CTRL;
    Base->SDCTL = TRNG_DEF_SDCTL;
    Base->FRQMIN = TRNG_HW_FRQMIN;
    Base->FRQMAX = TRNG_HW_FRQMAX;
    Base->FRQCNT = 0x00000000U;
    Base->SCML = TRNG_DEF_SCML;
    Base->SCMC = 0x00000000U;
    Base->CTRL = 0x00000000U;

}


/*FUNCTION**********************************************************************
 *
 * Function Name : Trng_SetCtrlReg
 * Description   : This function set the CTRL register of TRNG module.
 *
 *END**************************************************************************/
CRYPTO_FUNC static void Trng_SetCtrlReg(volatile TRNG_Type *const Base)
{
    uint32 Temp = TRNG_CTRL_UNLOCK(1) |
                  TRNG_CTRL_RTY_CT(Trng_Lld_CfgSetting.RetryCnt) |
                  TRNG_CTRL_LRUN_MAX(Trng_Lld_CfgSetting.RunMax) |
                  TRNG_CTRL_FOR_SCLK(Trng_Lld_CfgSetting.ForceSystemClockEn) |
                  TRNG_CTRL_CLK_OUT(Trng_Lld_CfgSetting.ClkOutputEn) |
                  TRNG_CTRL_OSC_DIV(Trng_Lld_CfgSetting.OSCDiv) |
                  TRNG_CTRL_FRQ_CT_IE(Trng_Lld_CfgSetting.FrqCntInterruptEn) |
                  TRNG_CTRL_ENT_VAL_IE(Trng_Lld_CfgSetting.EntroptValidInterruptEn) |
                  TRNG_CTRL_HW_ERR_IE(Trng_Lld_CfgSetting.HwErrInterruptEn);

    Base->CTRL = Temp;
    /*Disable unlock, write to the control bits has bo effect.*/
    Base->CTRL &= ~TRNG_CTRL_UNLOCK(1);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Trng_SetSdctlReg
 * Description   : This function set the SDCTL register of TRNG module.
 *
 *END**************************************************************************/
CRYPTO_FUNC static void Trng_SetSdctlReg(volatile TRNG_Type *const Base)
{
    /*Enable unlock, the control bits are able to be modified.*/
    Base->CTRL |= TRNG_CTRL_UNLOCK(1);

    Base->SDCTL = TRNG_SDCTL_ENT_DLY(Trng_Lld_CfgSetting.EntropyDelay) | /*PRQA S 2985 */
                  TRNG_SDCTL_SAMP_SIZE(Trng_Lld_CfgSetting.SampleSize);/*PRQA S 2985 */

    /*Disable unlock, write to the control bits has bo effect.*/
    Base->CTRL &= ~TRNG_CTRL_UNLOCK(1);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Trng_SetFrqMinReg
 * Description   : This function set the FRQMIN register of TRNG module.
 *
 *END**************************************************************************/
CRYPTO_FUNC static void Trng_SetFrqMinReg(volatile TRNG_Type *const Base)
{
    /*Enable unlock, the control bits are able to be modified.*/
    Base->CTRL |= TRNG_CTRL_UNLOCK(1);
    Base->FRQMIN = TRNG_FRQMIN_FRQ_MIN(Trng_Lld_CfgSetting.FrqMin);/*PRQA S 2985 */

    /*Disable unlock, write to the control bits has bo effect.*/
    Base->CTRL &= ~TRNG_CTRL_UNLOCK(1);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Trng_SetFrqMaxReg
 * Description   : This function set the FRQMAX register of TRNG module.
 *
 *END**************************************************************************/
CRYPTO_FUNC static void Trng_SetFrqMaxReg(volatile TRNG_Type *const Base)
{
    /*Enable unlock, the control bits are able to be modified.*/
    Base->CTRL |= TRNG_CTRL_UNLOCK(1);
    Base->FRQMAX = TRNG_FRQMAX_FRQ_MAX(Trng_Lld_CfgSetting.FrqMax);/*PRQA S 2985 */

    /*Disable unlock, write to the control bits has bo effect.*/
    Base->CTRL &= ~TRNG_CTRL_UNLOCK(1);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Trng_SetScmlReg
 * Description   : This function set the SCML register of TRNG module.
 *
 *END**************************************************************************/
CRYPTO_FUNC static void Trng_SetScmlReg(volatile TRNG_Type *const Base)
{
    /* Enable unlock, the control bits are able to be modified. */
    Base->CTRL |= TRNG_CTRL_UNLOCK(1);
    Base->SCML = TRNG_SCML_MONO_MAX(Trng_Lld_CfgSetting.MonobitMax) | /*PRQA S 2985 */
                 TRNG_SCML_MONO_RNG(Trng_Lld_CfgSetting.MonobitRange);/*PRQA S 2985 */

    /*Disable unlock, write to the control bits has bo effect.*/
    Base->CTRL &= ~TRNG_CTRL_UNLOCK(1);
}



/*FUNCTION**********************************************************************
 *
 * Function Name : Trng_GetEntReg
 * Description   : This function get the ENT register value of TRNG module.
 *
 *END**************************************************************************/
CRYPTO_FUNC static uint32 Trng_GetEntReg(volatile const TRNG_Type *const Base, uint8 Index)
{
    return (Base->ENT[Index]);
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Trng_GetStatusFlag
 * Description   : This function returns the state of one of the Trng status flags
 * as requested by the user.
 *
 *END**************************************************************************/
CRYPTO_FUNC static boolean Trng_GetStatusFlag(const volatile TRNG_Type *const Base, Crypto_Lld_Trng_StatusFlagType StatusFlag)
{
    return (boolean)(((Base->STAT) >> (uint8)StatusFlag) & 1U);
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Crypto_Lld_Trng_GetEnt
 * Description   : This function read the entropy value.
 * Reading the highest offset(ENT(7)) will clear the entire entropy value
 * and start a new entropy generation.
 *
 *END**************************************************************************/
CRYPTO_FUNC  void Crypto_Lld_Trng_GetEnt(uint32 Instance, uint8 *EntValuePtr, uint32 Length)
{
    volatile const TRNG_Type *const Base = Trng_Lld_Base[Instance];
    uint8 Tempi = 0;
    uint8 Tempk = 0;
    uint32 Temp32data = 0;
    if (EntValuePtr != NULL_PTR)
    {
        for (Tempi = 0; Tempi < (Length / NUMINBYTE_OF_U32); ++Tempi)
        {
            Temp32data = Trng_GetEntReg(Base, Tempi);
            EntValuePtr[Tempk] = (uint8)((Temp32data >> LENGTH_OF_U24) & LSBYTE_OF_U32);/*PRQA S 2985 */
            ++Tempk;
            EntValuePtr[Tempk] = (uint8)((Temp32data >> LENGTH_OF_U16) & LSBYTE_OF_U32);
            ++Tempk;
            EntValuePtr[Tempk] = (uint8)((Temp32data >> LENGTH_OF_U8)  & LSBYTE_OF_U32);
            ++Tempk;
            EntValuePtr[Tempk] = (uint8)((Temp32data >> 0)  & LSBYTE_OF_U32);/*PRQA S 2985 */
            ++Tempk;
        }
        while (Tempi < (CRYPTO_LENGTH_OF_RANDOM / NUMINBYTE_OF_U32))
        {
            /*read the rest entropy value to clear the ENT register*/
            Temp32data = Trng_GetEntReg(Base, Tempi);
            ++Tempi;
        }
    }

}
/*FUNCTION**********************************************************************
 *
 * Function Name : Trng_Lld_GetDefaultConfig
 * Description   : Get default config of TRNG.
 *
 *END**************************************************************************/
CRYPTO_FUNC static void Trng_Lld_GetDefaultConfig(void)
{
    Trng_Lld_CfgSetting.RunMax = TRNG_DEF_RUNMAX;
    Trng_Lld_CfgSetting.RetryCnt = TRNG_DEF_RETRYCNT;
    Trng_Lld_CfgSetting.ForceSystemClockEn = FALSE;
    Trng_Lld_CfgSetting.ClkOutputEn = FALSE;
    Trng_Lld_CfgSetting.OSCDiv = TRNG_OSC_NO_DEVIDER;
    Trng_Lld_CfgSetting.FrqCntInterruptEn = FALSE;
    Trng_Lld_CfgSetting.EntroptValidInterruptEn = FALSE;
    Trng_Lld_CfgSetting.HwErrInterruptEn = FALSE;
    Trng_Lld_CfgSetting.SampleSize = TRNG_DEF_SIZE;
    Trng_Lld_CfgSetting.EntropyDelay = TRNG_DEF_DELAY;
    Trng_Lld_CfgSetting.FrqMin = TRNG_DEF_FRQMIN;
    Trng_Lld_CfgSetting.FrqMax = TRNG_DEF_FRQMAX;
    Trng_Lld_CfgSetting.MonobitRange = TRNG_DEF_BITRANG;
    Trng_Lld_CfgSetting.MonobitMax = TRNG_DEF_BITMAX;
    Trng_Lld_CfgSetting.EntValuePtr = NULL_PTR;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Crypto_Lld_Trng_Init
 * Description   : This function first resets the source triggers of all TRNG target modules
 * to their default values, then configures the TRNG with all the user defined in-out mappings.
 *
 *END**************************************************************************/
CRYPTO_FUNC  void Crypto_Lld_Trng_Init(uint32 Instance, uint32 EntropyDelay)
{

    volatile TRNG_Type *const Base = Trng_Lld_Base[Instance];
    uint32 Tempdate = 0x0000FFFF;
    if (Tempdate >= EntropyDelay)
    {
        /* Reset the TRNG registers to their default state, including disabling the TRNG */
        Trng_RegInit(Base);
        Trng_Lld_GetDefaultConfig();
        Trng_Lld_CfgSetting.EntropyDelay = EntropyDelay;
        Trng_SetCtrlReg(Base);
        Trng_SetFrqMaxReg(Base);
        Trng_SetFrqMinReg(Base);
        Trng_SetScmlReg(Base);
        Trng_SetSdctlReg(Base);
        Trng_Enable(Base);
    }
}




/*FUNCTION**********************************************************************
 *
 * Function Name : TRNG_DRV_IsIDLE
 * Description   : This function return the status of the entropy generation FSM.
 *
 *END**************************************************************************/
/*
*  MR12 Rule-13.5 VIOLATION: Even if there is side effects,but it is safe.
*
*/
CRYPTO_FUNC Crypto_Lld_Trng_OptStatusType Crypto_Lld_Trng_GetStatus(uint32 Instance)
{
    const volatile TRNG_Type *const Base = Trng_Lld_Base[Instance];
    Crypto_Lld_Trng_OptStatusType TempReturnValue = CRYPTO_TRNG_ERROR;
    if (TRUE == Trng_GetStatusFlag(Base, TRNG_BUSY))
    {
        TempReturnValue = CRYPTO_TRNG_BUSY;
    }
    else if ((TRUE == Trng_GetStatusFlag(Base, TRNG_ENTROPY_VALID)) && (TRUE == Trng_GetStatusFlag(Base, TRNG_FREQUENCY_COUNT_VALID))) /* PRQA S 3415 */
    {
        TempReturnValue = CRYPTO_TRNG_SUCCESS;
    }
    else
    {
        TempReturnValue = CRYPTO_TRNG_ERROR;
    }
    return TempReturnValue;
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif

