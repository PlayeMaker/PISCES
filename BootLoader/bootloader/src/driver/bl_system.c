/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is the source file of the system clock module.
 *
 *  \file       bl_system.c
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
#include <bl_can.h>
#include "Mcal.h"
#include "bl_dflash.h"
#include "bl_adpt_uds_platform_cfg.h"
#include "bl_data.h"
#include "bl_timer.h"
#include "bl_watchdog.h"
#include "sdk_project_config.h"
#include "cache_driver.h"
#include "cache_config.h"
#include "interrupt_manager.h"
/*****************************************************************************
 *  QAC Suppression
 *****************************************************************************/
/*PRQA S 277,303,305,1251,1257,1503,1532,2100,3112,3442,3453,4130 EOF*/
/*
 * 277:An integer constant expression with negative value is being converted
 * to an unsigned type.
 *
 * MISRA-C:2004 11.3(303):Cast a pointer to an integral type.
 * To address a register must cast an integral type to a pointer.
 *
 * MISRA-C:2004 11.3(305):Cast a pointer to an integral type.
 *
 * 1251:Suffixed integer constant causes implicit conversion of other
 * (integral) operand.
 *
 * 1257:Suffixed integer constant implicitly converted to smaller integer type
 * on assignment.
 *
 * MISRA-C:2004 14.1(1503):The function is defined but is not used within this
 * project.
 * these functions will be used When correlative macro is enable.
 *
 * 1532:The function is only referenced in one translation unit.
 * all functions in this file are configurations in the Security Module.
 *
 * 2100:Integral promotion : unsigned char promoted to signed int.
 *
 * MISRA-C:2004 14.2(3112):This statement has no side-effect.
 * The DEBUG_ASSERT macro is used to debug bootloader when the BL_DEBUG is
 * enable. When the BL_DEBUG is disable, the DEBUG_ASSERT macro is null.
 *
 * 3442:Operator other than & or = applied to a volatile object.
 *
 * MISRA-C:2004 19.7(3453):A function could probably be used instead of this
 * function-like macro.
 *
 * MISRA-C:2004 12.7(4130):Bitwise operations on signed data will give
 * implementation defined results.
 *
 */

/*****************************************************************************
 *  Internal Macro Definitions
 *****************************************************************************/
#define SYS_ENTRY_POINT     (0x00018004ul)  /**< application entry point.*/


#define WakeUpFlag               (*(volatile uint64_t*)(0x20407E00ul))



/*****************************************************************************
 *  Internal Type Definitions
 *****************************************************************************/
/** a function pointer is used to go to application*/
typedef void (* theApp)(void);
static void Sys_checkresetreseon(void);
static void dflashdiddatainit(void);
/*****************************************************************************
 *  Function Definitions
 *****************************************************************************/
/**************************************************************************//**
 *
 *  \details Initialize system clock.
 *
 *  \return None.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
/*****************************************************************************
 *  Function Definitions
 *****************************************************************************/
void Sys_InitClock(void)
{
    Mcu_Init(&Mcu_Config);
    Mcu_InitClock(0);
    #if (MCU_NO_PLL == STD_OFF)
    while (MCU_PLL_LOCKED != Mcu_GetPllStatus()) {
        /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
    #endif
    Platform_Init(NULL_PTR);
    CACHE_DRV_Init(0,&cache_config0);

    INT_SYS_DisableIRQGlobal();
}

/**************************************************************************//**
 *
 *  \details Deinitialize system clock.
 *
 *  \return None.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
void Sys_DeinitClock(void)
{
    Can_Deinit();
    Tim_Deinit();
    Wdg_Deinit();
}

/**************************************************************************//**
 *
 *  \details Set system clock to sleep mode.
 *
 *  \return None.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
void Sys_Sleep(void)
{

}

/**************************************************************************//**
 *
 *  \details Remap the interrupt vector table.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
void Sys_RemapInterrupt(void)
{

}

/**************************************************************************//**
 *
 *  \details Set up the application entry point, and go to the application.
 *
 *  \since  V1.0.0
 *
 *****************************************************************************/
void Sys_GotoApplication(void)
{
    /*when a new application is downloaded by the bootloader, the enter address
      of this application maybe is different from the old one.*/
    /*PRQA S 3204 1*/
    theApp AppEntry = (theApp)(*(volatile  bl_u32_t *)SYS_ENTRY_POINT);
    AppEntry();
}

/**************************************************************************//**
 *
 *  \details .
 *
 *  \since  V2.0.0
 *
 *****************************************************************************/
void Sys_ProtectBootloader(void)
{

}


/**************************************************************************//**
 *  \details Initialize the value of DID_F111/F150/F18E/F010.
 *  \return None.
 *****************************************************************************/
/*Map the data of DID_F111/F150/F18E to correct address*/
const bl_u8_t DIDF110_HardWareNumber[11] __attribute__((section(".ARM.__at_""0xFFD0"))) = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

const bl_u8_t DIDF111_VehManuHardWareBaseline[2] __attribute__((section(".ARM.__at_""0xFFD0"))) = {0xFF, 0xFF};

const bl_u8_t DIDF150_BT_SofteWareVersion[4] __attribute__((section(".ARM.__at_""0xFFD0"))) = {0xFF, 0xFF, 0xFF, 0xFF};

const bl_u8_t DIDF18E_VehManuKitAssemblyPartVer[11] __attribute__((section(".ARM.__at_""0xFFD0"))) = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

void DIDdata_Init(void)
{
    bl_u8_t  flag[1] = {0x00};
    bl_u8_t  flaginit[1] = {0xAB};
    bl_u8_t  didf010init[4] = {0x00,0x00,0xFF,0xFF};
    bl_u8_t  dataFlag[12] = {0x00};
    
    /*Call DID_F111/F150/F18E ensure configuration success*/
    bl_u8_t  dest[3];

    dest[0] = DIDF111_VehManuHardWareBaseline[0];
    dest[1] = DIDF150_BT_SofteWareVersion[0];
    dest[2] = DIDF18E_VehManuKitAssemblyPartVer[0];
    
    /*Init the value of DID_F010*/
    Dm_ReadData(ADPT_FirstExecuted_FLAGID,(bl_Size_t)ADPT_FirstExecuted_SIZE, &flag[0]);
    if(flag[0] != 0xAB)
    {
        Dm_WriteData(ADPT_FirstExecuted_FLAGID,(bl_Size_t)ADPT_FirstExecuted_SIZE, &flaginit[0]);
        
        Dm_WriteData(ADPT_F150_FLAGID, (bl_Size_t)ADPT_F150_SIZE, &DIDF150_BT_SofteWareVersion[0]);
        dataFlag[ADPT_F150_FLAGID] = 1;
        Dm_WriteData(ADPT_F010_FLAGID, (bl_Size_t)ADPT_F010_SIZE, &didf010init[0]);
        dataFlag[ADPT_F010_FLAGID] = 1;
        Dm_WriteData(ADPT_F110_FLAGID, (bl_Size_t)ADPT_F110_SIZE, &DIDF110_HardWareNumber[0]);
        dataFlag[ADPT_F110_FLAGID] = 1;
        Dm_WriteData(ADPT_F111_FLAGID, (bl_Size_t)ADPT_F111_SIZE, &DIDF111_VehManuHardWareBaseline[0]);
        dataFlag[ADPT_F111_FLAGID] = 1;

        Dflash_Write(0x0200F880,0x20,&dataFlag[0]);
        
    }
}
