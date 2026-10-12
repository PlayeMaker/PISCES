/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is the header file of the flash module.
 *
 *  \file       bl_flash.h
 *  \ingroup    driver_module
 *  \author     sijia.hao <sijia.hao@hirain.com>
 *
 *  \version    1.3.0
 *  \date       05/08/2013
 *
 *  \par        Changelist
 *      Version  | Date       | Authors          | CR# | Descriptions
 *      -------- | ---------- | ---------------- | --- | -------------
 *      01.00.00 | 17/03/2010 | he.yang          | N/A | BootDrv010001
 *      01.01.00 | 21/02/2011 | ning.chen        | N/A | BootDrv010002
 *      01.02.00 | 05/08/2013 | sijia.hao        | N/A | BootDrv010003
 *      01.03.00 | 20/03/2014 | sijia.hao        | N/A | BootDrv010004
 *
 *****************************************************************************/
#ifndef _BL_FLASH_H_
#define _BL_FLASH_H_
#include "bl_typedefs.h"
#include "bl_system.h"
#include "bl_flash_if.h"
/*****************************************************************************
 *  QAC Suppression
 *****************************************************************************/
/*PRQA S 3210,3447,3453 EOF*/
/*
 * 3210:The global identifier is declared but is not used.
 * The functions are used in the bl_security_cfg.c file.
 *
 * MISRA-C:2004 8.8(3447):The identifier has external linkage but this
 * declaration is not in a header file.
 * The function Declarations are in the header file.
 *
 * MISRA-C:2004 19.7(3453):A function could probably be used instead of this
 * function-like macro.
 *
 */

/*****************************************************************************
 *  Macro Definitions
 *****************************************************************************/
#define FLASH_DRIVER_VERSION_TYPE       (0x8001u)
#define FLASH_DRIVER_VERSION_INDEX      (0x0000u)
#define FLASH_DRIVER_VERSION_MAGIC      (0x58455031UL)
#define FLASH_DRIVER_VERSION_VERSION    (0x00010300UL)

#define FLASH_DRIVER_INIT_OFFSET        (0x0Cu)
#define FLASH_DRIVER_DEINIT_OFFSET      (0x10u)
#define FLASH_DRIVER_ERASE_OFFSET       (0x14u)
#define FLASH_DRIVER_WRITE_OFFSET       (0x18u)

#define FLASH_DRIVER_INIT(sa, pp)       (*(bl_FlashDrvFun_t*)((sa)\
                                            + FLASH_DRIVER_INIT_OFFSET))(pp)
#define FLASH_DRIVER_DEINIT(sa, pp)     (*(bl_FlashDrvFun_t*)((sa)\
                                            + FLASH_DRIVER_DEINIT_OFFSET))(pp)
#define FLASH_DRIVER_ERASE(sa, pp)      (*(bl_FlashDrvFun_t*)((sa)\
                                            + FLASH_DRIVER_ERASE_OFFSET))(pp)
#define FLASH_DRIVER_WRITE(sa, pp)      (*(bl_FlashDrvFun_t*)((sa)\
                                            + FLASH_DRIVER_WRITE_OFFSET))(pp)
/*****************************************************************************
 * Type Declarations
 *****************************************************************************/

extern const bl_FlashDrvHeader_t g_FlashHeader;

/*****************************************************************************
 *  Structure Definitions
 *****************************************************************************/

/*****************************************************************************
 * External Function Prototype Declarations
 *****************************************************************************/
extern void Flash_Init(bl_FlashDrvParam_t *par);
extern void Flash_Deinit(bl_FlashDrvParam_t *par);
extern void Flash_Write(bl_FlashDrvParam_t *par);
extern void Flash_Erase(bl_FlashDrvParam_t *par);
extern void Flash_Read(bl_FlashDrvParam_t *par);

extern bl_Return_t Flash_CheckWriteStatus(void);
extern bl_Return_t Flash_CheckEraseStatus(void);
extern bl_Return_t PFlash_CheckWriteStatus(void);/*add by yanhui.guo*/
extern bl_Return_t PFlash_CheckEraseStatus(void);

extern bl_u32_t erasereturn;
extern bl_u32_t writereturn;

#endif
