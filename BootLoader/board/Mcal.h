/*
 * Copyright 2020-2025 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Mcal.h
 * @brief 
 * 
 */



#ifndef MCAL_H
#define MCAL_H




#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Compiler.h"
#include "Std_Types.h"

#include "Port.h"
#include "Port_PBcfg.h"
#include "Platform.h"
#include "Det.h"
#include "Can.h"
#include "Can_PBcfg.h"
#include "Mcu.h"
#include "Mcu_PBcfg.h"

#ifdef PORT_CONFIG_PB
PORT_CONFIG_PB
#endif
#ifdef CAN_CONFIG_PB
CAN_CONFIG_PB
#endif
#ifdef MCU_CONFIG_PB
MCU_CONFIG_PB
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCAL_VENDOR_ID                    180
#define MCAL_MODULE_ID                    0
#define MCAL_AR_RELEASE_MAJOR_VERSION     4
#define MCAL_AR_RELEASE_MINOR_VERSION     4
#define MCAL_AR_RELEASE_REVISION_VERSION  0
#define MCAL_SW_MAJOR_VERSION             0
#define MCAL_SW_MINOR_VERSION             9
#define MCAL_SW_PATCH_VERSION             1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Compiler.h header file are of the same Autosar version */
    #if ((MCAL_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION) || \
         (MCAL_AR_RELEASE_MINOR_VERSION != COMPILER_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcal.h and Compiler.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h header file are of the same Autosar version */
    #if ((MCAL_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MCAL_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcal.h and Std_Types.h are different"
    #endif
#endif



#define __ASM __asm


#ifdef __cplusplus
}
#endif



#endif

