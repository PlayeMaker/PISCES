/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is the source file of the timer module for xep100.
 *
 *  \file       bl_timer.c
 *  \ingroup    driver_module
 *  \author     sijia.hao <sijia.hao@hirain.com>
 *
 *  \version    1.2.0
 *  \date       05/08/2013
 *
 *  \par        Changelist
 *      Version  | Date       | Authors          | CR# | Descriptions
 *      -------- | ---------- | ---------------- | --- | -------------
 *      01.00.00 | 17/03/2010 | he.yang          | N/A | BootDrv010001
 *      01.01.00 | 21/02/2011 | ning.chen        | N/A | BootDrv010002
 *      01.02.00 | 05/08/2013 | sijia.hao        | N/A | BootDrv010003
 *
 *****************************************************************************/
#include "bl_system.h"
#include "bl_timer.h"

/*****************************************************************************
 *  QAC Suppression
 *****************************************************************************/
/*PRQA S 303,1251,1257,1532,2100,3442,3453 EOF*/
/*
 * MISRA-C:2004 11.3(303):Cast a pointer to an integral type.
 * To address a register must cast an integral type to a pointer.
 *
 * 1251:Suffixed integer constant causes implicit conversion of other
 * (integral) operand.
 *
 * 1257:Suffixed integer constant implicitly converted to smaller integer type
 * on assignment.
 *
 * 1532:The function is only referenced in one translation unit.
 * all functions in this file are configurations in the Security Module.
 *
 * 2100:Integral promotion : unsigned char promoted to signed int.
 *
 * 3442:Operator other than & or = applied to a volatile object.
 *
 * MISRA-C:2004 19.7(3453):A function could probably be used instead of this
 * function-like macro.
 *
 */

/*****************************************************************************
 *  Internal Macro Definitions
 *****************************************************************************/
#define SYST_CSR              (*(volatile bl_u32_t *)(0xE000E010u))
#define SYST_RVR              (*(volatile bl_u32_t *)(0xE000E014u))
#define SYST_CVR              (*(volatile bl_u32_t *)(0xE000E018u))

#define SYS_ENABLE_VALUE            (0x00000001u)
#define SYS_DISABLE_VALUE           (0xFFFFFFFEu)
#define SYS_CLEAR_VALUE             (0x00000000u)
#define SYS_RELOAD_VALUE            (0x00013880u)
#define SYS_COUNTFLAG_MASK          (0x00010000u)

#define SYST_CSR_RESET_VALUE   (0x00000001u)

bl_u32_t g_RandomSeed = 1;
/*****************************************************************************
 *  Function Definitions
 *****************************************************************************/
/**************************************************************************//**
 *
 *  \details Initialize timer module.
 *
 *  \return If the timer is initialized successfully returns BL_ERR_OK,
 *          otherwise returns BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK - the timer is initialized successfully.
 *  \retval BL_ERR_NOT_OK   - the timer is not initialized successfully.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
void Tim_Init(void)
{
    SYST_CVR = SYS_CLEAR_VALUE;
    SYST_RVR = SYS_RELOAD_VALUE;
    SYST_CSR |= SYS_ENABLE_VALUE;
}

/**************************************************************************//**
 *
 *  \details Check whether the timer is time out.
 *
 *  \return If the timer is time out returns BL_ERR_OK,
 *          otherwise returns BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK - the timer is time out.
 *  \retval BL_ERR_NOT_OK   - the timer is not time out.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
bl_Return_t Tim_IsTimeout(void)
{
    bl_Return_t ret = BL_ERR_NOT_OK;
    
    g_RandomSeed = SYST_CVR;

    if ((SYST_CSR & SYS_COUNTFLAG_MASK)== (SYS_COUNTFLAG_MASK))
    {
      	ret = BL_ERR_OK;
    }
    
    return ret;
}

/**************************************************************************//**
 *
 *  \details Deinitialize timer module.
 *
 *  \return If the timer is deinitialized successfully returns BL_ERR_OK,
 *          otherwise returns BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK - the timer is deinitialized successfully.
 *  \retval BL_ERR_NOT_OK   - the timer is not deinitialized successfully.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
void Tim_Deinit(void)
{
    SYST_CSR &= SYS_DISABLE_VALUE;
}



