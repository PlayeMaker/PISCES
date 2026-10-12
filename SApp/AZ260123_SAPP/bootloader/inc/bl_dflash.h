/******************************************************************************
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is the header file of the flash module.
 *
 *  \file       bl_eep.h
 *  \ingroup    driver_module
 *  \author     haiping.wang <haiping.wang@hirain.com>
 *
 *  \version    1.3.0
 *  \date       05/06/2014
 *
 *  \par        Changelist
 *      Version  | Date       | Authors          | CR# | Descriptions
 *      -------- | ---------- | ---------------- | --- | -------------
 *      01.00.00 | 05/06/2014 | haping.wang      | N/A | BootDrv010001
 *      01.01.01 | 05/09/2014 | rui.guo          | N/A | BootEEPDrv010002
 *      01.02.00 | 05/11/2014 | rui.guo          | N/A | BootEEPDrv010003
 *****************************************************************************/
#ifndef _BL_DFLASH_H_
#define _BL_DFLASH_H_

#include "bl_typedefs.h"
#include "bl_flash_if.h"

/*****************************************************************************
 *  Macro Definitions
 *****************************************************************************/
#define    CLIB_FLASH_D_PAGE_LENGTH    (0x8)
/*****************************************************************************
 *  Structure Definitions
 *****************************************************************************/

/*****************************************************************************
 * External Function Prototype Declarations
 *****************************************************************************/
extern bl_Return_t Dflash_Write(bl_Address_t address, bl_Size_t size,const bl_Buffer_t *buffer);
extern bl_Return_t Dflash_Read(bl_Address_t address, bl_Size_t size, bl_Buffer_t *buffer);
extern bl_Return_t Dflash_Deinit(void);
extern bl_Return_t Dflash_Init(void);
extern bl_Return_t Dflash_Erase(bl_Address_t address, bl_Size_t size);
#endif

