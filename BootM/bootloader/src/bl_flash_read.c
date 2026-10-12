/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is the source file of the flash module.
 *
 *  \file       bl_flash_read.c
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
#include "bl_flash.h"

/*****************************************************************************
 *  QAC Suppression
 *****************************************************************************/
/*PRQA S 306,506,781,1015,1532,3112,3227,3408 EOF*/
/*
 * MISRA-C:2004 11.3(306):Cast a pointer to an integral type.
 * To address a flash must cast an integral type to a pointer.
 *
 * 506:Dereferencing pointer value that is possibly NULL.
 * The parameter delay is not a null pointer.
 *
 * MISRA-C:2004 5.6(781):The identifier is used as a structure/union member.
 * The member of the structure is used through the structure object.
 *
 * 1015:Far is not a legal keyword in ISO C
 * This is a valid keyword in the CodeWarrior.
 *
 * 1532:The function is only referenced in one translation unit.
 * all functions in this file are configurations in the Security Module.
 *
 * MISRA-C:2004 14.2(3112):This statement has no side-effect.
 * The DEBUG_ASSERT macro is used to debug bootloader when the BL_DEBUG is
 * enable. When the BL_DEBUG is disable, the DEBUG_ASSERT macro is null.
 *
 * 3227:The parameter is never modified and so it could be declared with const.
 *
 * MISRA-C:2004 8.8(3408):The identifier has external linkage but is being
 * defined without any previous declaration.
 * The Flash_Read has a previous declaraton in the bl_flash.h file.
 *
 */

typedef void (* theApp)(void);
/*****************************************************************************
 *  Function Definitions
 *****************************************************************************/
static bl_Return_t _Dm_IsDefaultData(bl_Address_t src);

static bl_Return_t Flash_Read(bl_Address_t src, bl_Size_t size,  bl_Buffer_t *buffer);
/**************************************************************************//**
 *
 *  \details Read the data from the internal Flash device.
 *
 *  \return None.
 *
 *  \since V1.0.0
 *
 *****************************************************************************/
static bl_Return_t Flash_Read(bl_Address_t src, bl_Size_t size,  bl_Buffer_t *buffer)
{
    bl_Size_t i;

    for (i = 0; i < size; i++)
    {
        buffer[i] = *(bl_Buffer_t *)(src + i); /*lint !e511*/
    }

    return BL_ERR_OK;
}

/**************************************************************************//**
 *
 *  \details Check the parameters.
 *
 *  \return If the the data is checked successfully return BL_ERR_OK, otherwise
 *          return BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK               - the data is checked successfully.
 *  \retval BL_ERR_NOT_OK           - the data is not checked successfully.
 *
 *  \since  V4.0.0
 *
 *****************************************************************************/
static bl_Return_t _Dm_IsDefaultData(bl_Address_t src)
{
    bl_Return_t ret = BL_ERR_NOT_OK;
    bl_Size_t i;
    bl_Buffer_t buffer[FLAG_SIZE];
    bl_Buffer_t valig_int_value[FLAG_SIZE] = {0x55, 0x55, 0x55, 0x55};

    ret = Flash_Read(src, FLAG_SIZE, buffer);
    if(BL_ERR_OK == ret)
    {
        for(i = 0; i < FLAG_SIZE; i++)
        {
            if(valig_int_value[i] != buffer[i])
            {
                ret = BL_ERR_NOT_OK;
                break;
            }
        }
    }

    return ret;
}


void  Jump_to_Run(void)
{
    theApp AppEntry;

	if(_Dm_IsDefaultData((bl_Address_t)FBL_VALID_FLAG_ADDRESS) == BL_ERR_OK)
	{
	    AppEntry = (theApp)(*(volatile  bl_u32_t *)FBL_RUN_ADDRESS);
	    AppEntry();
	}
	else if(_Dm_IsDefaultData((bl_Address_t)APP_VALID_FLAG_ADDRESS) == BL_ERR_OK)
	{
	    AppEntry = (theApp)(*(volatile  bl_u32_t *)APP_RUN_ADDRESS);
	    AppEntry();
	}
	else
	{

	}

}
