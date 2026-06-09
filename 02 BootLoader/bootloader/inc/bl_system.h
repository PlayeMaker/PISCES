/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is a head file of the system clock module.
 *
 *  \file       bl_system.h
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
#ifndef _BL_SYSTEM_H_
#define _BL_SYSTEM_H_
#include "bl_typedefs.h"
/*****************************************************************************
 *  QAC Suppression
 *****************************************************************************/
/*PRQA S 3205,3210,3447,3448 EOF*/
/*
 * 3205:The identifier is not used and could be removed.
 * The bl_Adapter_t is used by the specifically adapter such as UDS platform in
 * the bl_adpt_uds_platform.c
 *
 * 3210:The global identifier is declared but is not used.
 * The functions are used in the bl_security_cfg.c file.
 *
 * MISRA-C:2004 8.8(3447):The identifier has external linkage but this
 * declaration is not in a header file.
 * The function Declarations are in the header file.
 *
 * MISRA-C:2004 5.3(3448):Declaration of typedef is not in a header file.
 * The bl_SecurityDelay_t is declared in the header file.
 *
 */

/*****************************************************************************
 *  Macro Definitions
 *****************************************************************************/
#define SYS_OSC_CLOCK_FREQ      (8000)
#define SYS_MCU_CLOCK_FREQ      (80000)
#define SYS_BUS_CLOCK_FREQ      (40000) /*KHz*/
/*****************************************************************************
 *  External Function Prototype Declarations
 *****************************************************************************/
 /** \brief This function is used to remap interrupt vector table.*/
extern void Sys_RemapInterrupt(void);
/** \brief This function is used to go to application.*/
extern void Sys_GotoApplication(void);
/** \brief This function is used to turn on the flash protection.*/
extern void Sys_ProtectBootloader(void);
extern void Sys_InitClock(void);
extern void Sys_DeinitClock(void);
extern void Sys_Sleep(void);
extern void Sys_DirectGotoApplication(void);
extern void DIDdata_Init(void);
#endif

