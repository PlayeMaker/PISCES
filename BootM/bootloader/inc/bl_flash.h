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


/*****************************************************************************
 *  Macro Definitions
 *****************************************************************************/
#define  FBL_VALID_FLAG_ADDRESS      (0x0200FC10ul)
//#define  FBL_INVALID_FLAG_ADDRESS    (0x0200FE10ul)

#define  APP_VALID_FLAG_ADDRESS      (0x0200F600ul)
//#define  APP_INVALID_FLAG_ADDRESS    (0x0200F610ul)

#define  FLAG_SIZE                   (0x04ul)

#define  FBL_RUN_ADDRESS             (0x00004004ul)
#define  APP_RUN_ADDRESS             (0x00018004ul)
/*****************************************************************************
 * Type Declarations
 *****************************************************************************/

/*****************************************************************************
 *  Structure Definitions
 *****************************************************************************/

/*****************************************************************************
 * External Function Prototype Declarations
 *****************************************************************************/

extern void  Jump_to_Run(void);



#endif
