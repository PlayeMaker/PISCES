/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is the source file of the watchdog module for xep100.
 *
 *  \file       bl_watchdog.c
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
#include "bl_common.h"
#include "bl_rte_funcfg.h"
#include "bl_system.h"
#include "bl_watchdog.h"
#include "Mcu.h"


/*****************************************************************************
 *  QAC Suppression
 *****************************************************************************/
/*PRQA S 303,306,310,342,1257,1258,1503,1532,3412,3453 EOF*/
/*
 * MISRA-C:2004 11.3(303):Cast a pointer to an integral type.
 * To address a register must cast an integral type to a pointer.
 *
 * MISRA-C:2004 11.3(306):Cast a pointer to an integral type.
 * To address a flash must cast an integral type to a pointer.
 *
 * MISRA-C:2004 11.4(310):Casting to different object pointer type.
 *
 * 342:K&R compilers do not support the ISO glue operator '##'.
 *
 * 1257:Suffixed integer constant implicitly converted to smaller integer type
 * on assignment.
 *
 * 1258:Suffixed integer constant explicitly cast to another type.
 *
 * MISRA-C:2004 14.1(1503):The function is defined but is not used within this
 * project.
 * these functions will be used When correlative macro is enable.
 *
 * 1532:The function is only referenced in one translation unit.
 * all functions in this file are configurations in the Security Module.
 *
 * MISRA-C:2004 19.4(3412):Macro defines an unrecognized code-fragment.
 *
 * MISRA-C:2004 19.7(3453):A function could probably be used instead of this
 * function-like macro.
 *
 */


/*****************************************************************************
 *  Internal Macro Definitions
 *****************************************************************************/
#define WDG_SVCR              (*(volatile bl_u32_t *)(0x4006A000u))
#define WDG_CR                (*(volatile bl_u32_t *)(0x4006A004u))
#define WDG_LR                (*(volatile bl_u32_t *)(0x4006A008u))
#define WDG_TOVR              (*(volatile bl_u32_t *)(0x4006A00Cu))
#define WDG_WVR               (*(volatile bl_u32_t *)(0x4006A010u))
#define WDG_CNTCVR            (*(volatile bl_u32_t *)(0x4006A014u))
#define WDG_INTF              (*(volatile bl_u32_t *)(0x4006A018u))

#define TIMEOUT_VALUE         (0x00008D80u)
#define WDG_ENABLE            (0x00000001u)
#define WDG_DISABLE           (0xFFFFFFFEu)
#define WDG_SOFT_LOCK         (0x00000001u)
#define WDG_TRIGGER_VALUE_1   (0x0000A518u)
#define WDG_TRIGGER_VALUE_2   (0x0000D826u)
#define WDG_UNLOCK_VALUE_1    (0x0000B631u)
#define WDG_UNLOCK_VALUE_2    (0x0000C278u)

#define WDG_CR_RESET_VALUE    (0x00000042u)
#define WDG_TOVR_RESET_VALUE  (0x00000300u)
/*****************************************************************************
 *  Function Definitions
 *****************************************************************************/
/**************************************************************************//**
 *
 *  \details Initialize watchdog module.
 *
 *  \return None.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
void Wdg_Init(void)
{
    WDG_TOVR = TIMEOUT_VALUE;
    WDG_CR |= WDG_ENABLE;
    WDG_LR |= WDG_SOFT_LOCK;
}

/**************************************************************************//**
 *
 *  \details Feed watchdog.
 *
 *  \return None.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
void Wdg_Feed(void)
{
    WDG_SVCR = WDG_TRIGGER_VALUE_1;
    WDG_SVCR = WDG_TRIGGER_VALUE_2;
}

/*****************************************************************************
 *  Function Definitions
 *****************************************************************************/

void Wdg_disable(void)
{
    WDG_SVCR = WDG_UNLOCK_VALUE_1;
    WDG_SVCR = WDG_UNLOCK_VALUE_2;
    WDG_CR &= WDG_DISABLE;
}

/**************************************************************************//**
 *
 *  \details Deinitialize watchdog module.
 *
 *  \return None.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
void Wdg_Deinit(void)
{
    WDG_SVCR = WDG_UNLOCK_VALUE_1;
    WDG_SVCR = WDG_UNLOCK_VALUE_2;
    WDG_CR &= WDG_CR_RESET_VALUE;
    WDG_TOVR = WDG_TOVR_RESET_VALUE;
}

/**************************************************************************//**
 *
 *  \details Reset watchdog module.
 *
 *  \return None.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
void Wdg_FastReset(void)
{   
    Mcu_Lld_SystemReset();
    for(;;)
    {
    }
}


