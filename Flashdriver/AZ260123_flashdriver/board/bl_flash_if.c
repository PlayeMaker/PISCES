/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is the source file of the flash_if manager module.
 *
 *  \file       bl_flash_if.c
 *  \ingroup    flash_if_manager_module
 *  \author     haiping.wang <haiping.wang@hirain.com>
 *
 *  \version    5.7.0
 *  \date       25/06/2021
 *
 *  \par        Changelist
 *      Version  | Date       | Authors          | CR# | Descriptions
 *      -------- | ---------- | ---------------- | --- | ------------
 *      02.00.00 | 19/08/2013 | haiping.wang     | N/A | Boot020001
 *      05.01.00 | 27/03/2014 | mingqing.tang    | N/A | Boot050002
 *      05.02.00 | 27/03/2016 | beibei.xing      | N/A | Boot050015
 *      05.03.00 | 27/03/2017 | beibei.xing      | N/A | Boot050017
 *      05.04.00 | 27/03/2018 | beibei.xing      | N/A | Boot050018
 *
******************************************************************************/

#include "bl_flash_if.h"
#include "bl_flash_if_cfg.h"
#include "bl_flash.h"

/*****************************************************************************
 *  QAC Suppression
 *****************************************************************************/
/*PRQA S 306,506,602,781,1251,1257,1277,1532,2103,3112,3204,3227,3453 EOF*/
/*
 * MISRA-C:2004 11.3(306):Cast a pointer to an integral type.
 * To address a flash must cast an integral type to a pointer.
 *
 * 506:Dereferencing pointer value that is possibly NULL.
 * The parameter delay is not a null pointer.
 *
 * MISRA-C:2004 20.2(602):The identifier is reserved for use by the library.
 * The Bootloader do not use any library funtion and use the underscores to
 * indicate that the function is a interal function.
 *
 * MISRA-C:2004 5.6(781):The identifier is used as a structure/union member.
 * The member of the structure is used through the structure object.
 *
 * 1251:Suffixed integer constant causes implicit conversion of other
 * (integral) operand.
 *
 * 1257:Suffixed integer constant implicitly converted to smaller integer type
 * on assignment.
 *
 * 1277:A "U" suffix has not been appended to a hex constant.
 *
 * 1532:The function is only referenced in one translation unit.
 * all functions in this file are configurations in the Security Module.
 *
 * 2103:Integral promotion, unsigned short promoted to unsigned int.
 * This message will therefore only be generated when a short and an int are of
 * equal size.
 *
 * MISRA-C:2004 14.2(3112):This statement has no side-effect.
 * The DEBUG_ASSERT macro is used to debug bootloader when the BL_DEBUG is
 * enable. When the BL_DEBUG is disable, the DEBUG_ASSERT macro is null.
 *
 * 3204:The variable is only set once and so it could be declared with the
 * 'const' qualifier.
 *
 * 3227:The parameter is never modified and so it could be declared with const.
 *
 * MISRA-C:2004 19.7(3453):A function could probably be used instead of this
 * function-like macro.
 *
 */

/*****************************************************************************
 *  Verify The Configurations of Function Macro
 *****************************************************************************/
#if (FLASHIF_NUMBER_OF_BLOCK == 0)
#error "The number of the flash IF block is error."
#endif
/*****************************************************************************
 *  Internal Macro Definitions
 *****************************************************************************/
#define FLASHIF_DRIVER_MAGIC_ADDRESS        (FLASHIF_DRIVER_STARTADDRESS + 4)
#define FLASHIF_DRIVER_VERSION_ADDRESS      (FLASHIF_DRIVER_STARTADDRESS + 8)

/** \brief Set the status of flash IF context to NOINIT.*/
#define FLASHIF_STATUS_GOTO_NOINIT(ct)  ((ct)->status = FLASHIF_STATUS_NOINIT)
/** \brief Set the status of flash IF context to IDLE.*/
#define FLASHIF_STATUS_GOTO_IDLE(ct)    ((ct)->status = FLASHIF_STATUS_IDLE)
/** \brief Set the status of flash IF context to WRITING.*/
#define FLASHIF_STATUS_GOTO_WRITING(ct) ((ct)->status = FLASHIF_STATUS_WRITING)
/** \brief Set the status of flash IF context to ERASING.*/
#define FLASHIF_STATUS_GOTO_ERASING(ct) ((ct)->status = FLASHIF_STATUS_ERASING)

/** \brief Check whether the status of flash IF context is NOINIT.*/
#define FLASHIF_STATUS_IS_NOINIT(ct)    (FLASHIF_STATUS_NOINIT == (ct)->status)
/** \brief Check whether the status of flash IF context is IDLE.*/
#define FLASHIF_STATUS_IS_IDLE(ct)      (FLASHIF_STATUS_IDLE == (ct)->status)
/** \brief Check whether the status of flash IF context is WRITING.*/
#define FLASHIF_STATUS_IS_WRITING(ct)   (FLASHIF_STATUS_WRITING == \
                                            (ct)->status)
/** \brief Check whether the status of flash IF context is ERASING.*/
#define FLASHIF_STATUS_IS_ERASING(ct)   (FLASHIF_STATUS_ERASING == \
                                            (ct)->status)

/** \brief Check whether the id is a valid block list index of the flash IF.*/
#define FLASHIF_IS_VALID_BLOCK(id)      ((id) < FLASHIF_NUMBER_OF_BLOCK)

#define FLASHIF_INIT(pp)    FLASH_DRIVER_INIT(FLASHIF_DRIVER_STARTADDRESS,pp)
#define FLASHIF_DEINIT(pp)  FLASH_DRIVER_DEINIT(FLASHIF_DRIVER_STARTADDRESS,pp)
#define FLASHIF_ERASE(pp)   FLASH_DRIVER_ERASE(FLASHIF_DRIVER_STARTADDRESS,pp)
#define FLASHIF_WRITE(pp)   FLASH_DRIVER_WRITE(FLASHIF_DRIVER_STARTADDRESS,pp)

#define FLASHIF_STATE_INITED   0x1000
#define FLASHIF_STATE_UNINIT   0x0000

#define UDS_SERVICE_ID_31     (0x31u)

/*****************************************************************************
 *  Internal Variable Definitions
 *****************************************************************************/
static bl_u16_t gs_FlsIfInitSt = FLASHIF_STATE_UNINIT;

/*****************************************************************************
 *  Internal Type Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Internal Structure Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Internal Function Declarations
 *****************************************************************************/

/** \brief Erase a sector in the flash device.*/

static bl_Return_t _Flsif_EraseSector(bl_Address_t address,
                                            bl_Size_t size);
#if (FLASHIF_FUN_ERASE_BY_BLOCKID == BL_FUN_ON)
/** \brief Get the eraseable block id.*/
static bl_u16_t _Flsif_GetPhyBlockId(const bl_FlashIfBlockInfo_t *block,
                                        bl_Address_t address);
#endif

/*****************************************************************************
 * Internal Variable Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Global Variable Definitions
 *****************************************************************************/
bl_u32_t erasereturn=0;
bl_u32_t writereturn=0;
/*****************************************************************************
 *  Function Definitions
 *****************************************************************************/
/**************************************************************************//**
 *
 *  \details initialize the flash IF module. This interface will be check the
 *           magic value and the version between the flash if module and the
 *           flash driver head. If the magic or the version is not same, the
 *           initialization interface of the flash driver is not called.
 *
 *  \return If this module is initialized successfully returns BL_ERR_OK,
 *          otherwise returns BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK     - initialize successfully.
 *  \retval BL_ERR_NOT_OK - initialize unsuccessfully.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
bl_Return_t Flsif_Init(void)
{
    bl_FlashDrvParam_t param;

    FLASHIF_INIT(&param);

    return param.errCode;
}

/**************************************************************************//**
 *
 *  \details deinitialize the flash IF module.
 *
 *  \return If this module is deinitialized successfully returns BL_ERR_OK,
 *          otherwise returns BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK     - deinitialize successfully.
 *  \retval BL_ERR_NOT_OK - deinitialize unsuccessfully.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
bl_Return_t Flsif_DeInit(void)
{
    bl_FlashDrvParam_t param;

    FLASHIF_DEINIT(&param);

    if(BL_ERR_OK == param.errCode)
    {
        gs_FlsIfInitSt = FLASHIF_STATE_UNINIT;
    }
    return param.errCode;
}



/**************************************************************************//**
 *
 *  \details Begin to write the flash device.
 *
 *  \param[in] address  - the memory address of the data to be written in.
 *  \param[in] size     - the size of the data to be written.
 *  \param[in] buffer   - the pointer of the data to be written.
 *
 *  \return If the data are written successfully returns BL_ERR_OK, otherwise
 *          returns BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK     - the writing operation is done successfully.
 *  \retval BL_ERR_NOT_OK - the writing operation is done unsuccessfully.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
bl_Return_t Flsif_Write(bl_Address_t address,
                            bl_Size_t size,
                            const bl_Buffer_t *buffer)
{
    bl_Return_t ret = BL_ERR_NOT_OK;
    bl_FlashDrvParam_t param;


    param.address = address;
    param.size = size;
    param.buffer = buffer;


    FLASHIF_WRITE(&param);

    return ret;
}

/**************************************************************************//**
 *
 *  \details Begin to erase the flash device.
 *
 *  \param[in] address  - the memory address will be erased.
 *  \param[in] size     - the size will be erased.
 *
 *  \return If the memory is erased successfully returns BL_ERR_OK, otherwise
 *          returns BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK     - the erasing operation is done successfully.
 *  \retval BL_ERR_NOT_OK - the erasing operation is done unsuccessfully.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
bl_Return_t Flsif_Erase(bl_Address_t address, bl_Size_t size)
{
    bl_Return_t ret = BL_ERR_OK;

    _Flsif_EraseSector(address, size);

    return ret;
}



/**************************************************************************//**
 *
 *  \details Erase one sector of the flash device.
 *
 *  \param[in] block    - the pointer of the flash block.
 *  \param[in] address  - the address of the flash block.
 *  \param[in] size     - the size of the flash will be erased.
 *  \param[in] buffer   - useless parameter
 *
 *  \retval BL_ERR_OK       - the sector of the flash is erased successfully.
 *  \retval BL_ERR_NOT_OK   - the sector of the flash is erased unsuccessfully.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
static bl_Return_t _Flsif_EraseSector(bl_Address_t address,
                                            bl_Size_t size)
{
    bl_FlashDrvParam_t param;

    param.address = address;
    param.size = size;
    param.buffer = BL_NULL_PTR;

    FLASHIF_ERASE(&param);

    return param.errCode;
}

#if (FLASHIF_FUN_ERASE_BY_BLOCKID == BL_FUN_ON)
/**************************************************************************//**
 *
 *  \details Check wether the physical address of data is in a valid block and
 *           the size of data is a valid range in the block list.
 *
 *  \pre    the address in the current block.
 *
 *  \param[in] block    - the pointer of the current block that is erasing.
 *  \param[in] address  - the address in the current block.
 *
 *  \return the physical eraseable block id.
 *
 *  \since V5.1.0
 *
 *****************************************************************************/
static bl_u16_t _Flsif_GetPhyBlockId(const bl_FlashIfBlockInfo_t *block,
                                        bl_Address_t address)
{
    bl_u16_t offset;

    offset = (bl_u16_t)(address / block->sectorSize);

    return offset + block->phyBlockId;
}
#endif
