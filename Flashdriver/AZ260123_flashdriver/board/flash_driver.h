/*
 * Copyright 2020-2022 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*!
 * @file flash_driver.h
 *
 */

#ifndef FLASH_DRIVER_H
#define FLASH_DRIVER_H

#include <stdbool.h>
#include <stddef.h>
#include "status.h"
#include "device_registers.h"

#include "stdint.h"

#define TEST_BY_ARRAY  /* Comment this line if download bin file to SRAM */

// #ifdef TEST_BY_ARRAY
// #include "fls_drv_bin_data.h"
// #define FLS_DRV_BASE_ADDR ((uint32_t)bin_data)
// //#define FLS_DRV_BASE_ADDR ((uint32_t)0x1FFFF000)
// #else
// #define FLS_DRV_BASE_ADDR ((uint32_t)0x20004000)    /* Base address of the flash driver bin which download to SRAM */
// #endif /* TEST_BY_ARRAY */

// #define FLASH_DRIVER_VERSION_TYPE       (0x8001u)
// #define FLASH_DRIVER_VERSION_INDEX      (0x0000u)
// #define FLASH_DRIVER_VERSION_MAGIC      (0x58455031UL)
// #define FLASH_DRIVER_VERSION_VERSION    (0x00010300UL)

// #define FLASH_DRIVER_INIT_OFFSET        (0x0Cu)
// #define FLASH_DRIVER_DEINIT_OFFSET      (0x10u)
// #define FLASH_DRIVER_ERASE_OFFSET       (0x14u)
// #define FLASH_DRIVER_WRITE_OFFSET       (0x18u)



// /*!
//  * @brief Flash driver init function.
//  */
// typedef status_t (*FLASH_Init_t)(void);

// /*!
//  * @brief Flash driver deinit function.
//  */
// typedef status_t (*FLASH_Deinit_t)(void);

// /*!
//  * @brief Flash erase sector synchronously.
//  */
// typedef status_t (*FLASH_EraseSector_t)(uint32_t dest, uint32_t size);

// /*!
//  * @brief Flash program synchronously.
//  */
// typedef status_t (*FLASH_Program_t)(uint32_t dest, uint32_t size, const void * pData);

// /*!
//  * @brief Flash driver boot swap function.
//  */
// typedef status_t (*FLASH_BootSwap_t)(void);

// typedef struct{
//     //uint32_t version;
//     uint16_t type;          /**< The type of the flash driver.*/
//     uint16_t index;         /**< The index of the flash driver.*/
//     uint32_t magic;         /**< The magic value of the flash driver*/
//     uint32_t version;       /**< The current of the flash driver.*/
//     FLASH_Init_t init;
//     FLASH_Deinit_t deinit;
//     FLASH_EraseSector_t eraseSector;
//     FLASH_Program_t program;
//     //FLASH_BootSwap_t bootSwap;   /* Optional by chip */
// }fls_drv_tbl_t;



// extern status_t FLASH_DRV_Init(void);
// extern status_t FLASH_DRV_Deinit(void);
// extern status_t FLASH_DRV_EraseSector(uint32_t dest, uint32_t size);
// extern status_t FLASH_DRV_Program(uint32_t dest, uint32_t size, const void * pData);



/*!
 * @defgroup flash_driver Flash Memory (Flash)
 * @ingroup flash
 * @details This section describes the programming interface of the Flash Peripheral Driver.
 * @{
 */


/*!
 * @addtogroup flash_driver
 * @{
 */


/*******************************************************************************
* CallBack function period
*******************************************************************************/
#ifndef FLASH_CALLBACK_CS
/*! @brief  Callback period count for FlashCheckSum
 *
 * This value is only relevant for FlashCheckSum operation, where a high rate of
 * calling back can impair performance. The rest of the flash operations invoke
 * the callback as often as possible while waiting for the flash controller
 * to finish the requested operation.
 */
#define FLASH_CALLBACK_CS 0x0AU
#endif

/*******************************************************************************
* Null Callback function definition
*******************************************************************************/
/*!
 * @name Null Callback function definition
 * @{
 */
/*! @brief  Null callback */
#define NULL_CALLBACK      ((flash_callback_t)0xFFFFFFFFU)

/*@}*/

/*******************************************************************************
* Callback function prototype
*******************************************************************************/
/*! @brief Call back function pointer data type
 *
 *   If using callback in the application, any code reachable from this function
 *   must not be placed in a Flash block targeted for a program/erase operation.
 *   Functions can be placed in RAM section by using the
 *   START/END_FUNCTION_DEFINITION/DECLARATION_RAMSECTION macros.
 */
typedef void (*flash_callback_t)(void);

/*******************************************************************************
* Function Prototypes for Flash SSD
*******************************************************************************/
/*!
 * @name Flash driver APIs
 * @{
 */

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initialize the flash driver.
 *
 * This function initializes the flash driver. It should be called before any
 * other flash driver APIs are called.
 *
 * @return operation status
 *        - STATUS_SUCCESS:         Operation was successful.
 *        - STATUS_ERROR:           Operation failure was occurred.
 */
status_t FLASH_DRV_Init(void);


/*!
 * @brief De-initialize the flash driver.
 *
 * This function de-initializes the flash driver. It should be called after all
 * other flash driver APIs are called.
 * This function should be called before the system is reset.
 *
 * @return operation status
 *        - STATUS_SUCCESS:         Operation was successful.
 *        - STATUS_ERROR:           Operation failure was occurred.
 */
status_t FLASH_DRV_Deinit(void);

/*!
 * @brief Flash Block Erase
 *
 * This API is used to erase a block of flash memory.
 * This API is will erase flash block regardless of the protection status.
 *
 * @param[in] dest Start address for the target flash block.
                   This address should be aligned to flash block margin.
 * @return operation status
 *        - STATUS_SUCCESS:         Operation was successful.
 *        - STATUS_ERROR:           Operation failure was occurred.
 *        - STATUS_BUSY:            Operation was busy.
 */
status_t FLASH_DRV_EraseBlock(uint32_t dest);

/*!
 * @brief Flash erase sector.
 *
 * This API erases one or more sectors in main flash or data flash memory.
 * This API always returns STATUS_SUCCESS if size provided by the user is
 * zero regardless of the input validation.
 *
 * @param[in] dest Address in the first sector to be erased.
 *            User need to make sure the dest address in of main flash or data flash block.
 *            This address should be aligned to sector size:
 *            FEATURE_EFM_MAIN_ARRAY_SECTOR_SIZE or FEATURE_EFM_DATA_ARRAY_SECTOR_SIZE.
 *
 * @param[in] size Size to be erased in bytes. It is used to determine number of sectors to be erased.
 *            This size should be aligned to bytes:
 *            FEATURE_EFM_MAIN_ARRAY_SECTOR_SIZE or FEATURE_EFM_DATA_ARRAY_SECTOR_SIZE.
 *
 * @return operation status
 *        - STATUS_SUCCESS:         Operation was successful.
 *        - STATUS_ERROR:           Operation failure was occurred.
 *        - STATUS_BUSY:            Operation was busy.
 */
status_t FLASH_DRV_EraseSector(uint32_t dest, uint32_t size);

/*!
 * @brief Flash program
 *
 * This API is used to program 4 consecutive bytes (for program long
 * word command) and 8 consecutive bytes (for program phrase command) on
 * P-Flash or D-Flash block. This API always returns EFM_OK if size
 * provided by user is zero regardless of the input validation
 *
 * @param[in] dest Start address for the intended program operation.
 *                 This address should be aligned to bytes:
 *                 FEATURE_EFM_WRITE_UNIT_SIZE
 *                  
 * @param[in] size Size in byte to be programmed.
 *                 This size should be aligned to bytes:
 *.                FEATURE_EFM_WRITE_UNIT_SIZE
 *
 * @param[in] pData Pointer of source address from which data has to
 *                  be taken for program operation. pData should be **aligned to
 *                  32-bit boundary**.
 * @return operation status
 *        - STATUS_SUCCESS:         Operation was successful.
 *        - STATUS_ERROR:           Operation failure was occurred.
 *        - STATUS_BUSY:            Operation was busy.
 */
status_t FLASH_DRV_Program(uint32_t dest, uint32_t size, const void *pData);

/*!
 * @brief Calculates check sum.
 *
 * This API performs 32 bit sum of each byte data over a specified Flash
 * memory range without carry which provides rapid method for checking data integrity.
 * The callback time period of this API is determined via FLASH_CALLBACK_CS macro in
 * flash_driver.h which is used as a counter value for the CallBack() function calling in
 * this API. This value can be changed as per the user requirement. User can change this value
 * to obtain the maximum permissible callback time period.
 * This API always returns STATUS_SUCCESS if size provided by user is zero regardless of the input
 * validation.
 *
 * @param[in] dest Start address of the Flash range to be summed.
 * @param[in] size Size in byte of the Flash range to be summed.
 * @param[in] pSum To return the sum value.
 * @return operation status
 *        - STATUS_SUCCESS:         Operation was successful.
 *        - STATUS_ERROR:           Operation failure was occurred.
 */
status_t FLASH_DRV_CheckSum(uint32_t dest, uint32_t size, uint32_t *pSum);

/*!
 * @brief Enable the command complete interrupt.
 *
 * This function will enable the command complete interrupt is generated when
 * an EFM command completes.
 *
 * @return operation status
 *        - STATUS_SUCCESS:         Operation was successful.
 */
status_t FLASH_DRV_EnableCmdCompleteInterrupt(void);

/*!
 * @brief Disable the command complete interrupt.
 *
 */
void FLASH_DRV_DisableCmdCompleteInterrupt(void);

/*!
 * @brief Check the command complete flag has completed or not.
 *
 * @return the command complete flag
 *        - true: The EFM command has completed.
 *        - false: The EFM command is in progress.
 *
 * Implements    : FLASH_DRV_GetCmdCompleteFlag_Activity
 */
static inline bool FLASH_DRV_GetCmdCompleteFlag(void)
{
    return (((EFM->STS & EFM_STS_IDLE_MASK) >> EFM_STS_IDLE_SHIFT) != 0U);
}

/*!
 * @brief Check the read collision error flag is detected or not.
 *
 * @return the read collision error flag
 *        - true: Collision error detected.
 *        - false: No collision error detected.
 *
 * Implements    : FLASH_DRV_GetReadCollisionFlag_Activity
 */
static inline bool FLASH_DRV_GetReadCollisionFlag(void)
{
    return (((EFM->STS & EFM_STS_ACCERR_MASK) >> EFM_STS_ACCERR_SHIFT) != 0U);
}

/*!
 * @brief Clear the read collision error flag.
 *
 * Implements    : FLASH_DRV_ClearReadCollisionFlag_Activity
 */
static inline void FLASH_DRV_ClearReadCollisionFlag(void)
{
    EFM->STS = EFM_STS_ACCERR_MASK;
}

/*!
 * @brief Check the double bit fault flag is detected during a valid
 * flash read access from the platform flash controller
 *
 * @return the platform flash error status
 * @retval true: Double bit fault detected.
 * @retval false: No double bit fault detected.
 *
 * Implements    : FLASH_DRV_GetDoubleBitFaultFlag_Activity
 */
static inline bool FLASH_DRV_GetDoubleBitFaultFlag(void)
{
    return (((EFM->STS & EFM_STS_UNRECOVERR_MASK) >> EFM_STS_UNRECOVERR_SHIFT) != 0U);
}

/*!
 * @brief Clear the platform Flash double bit fault detect flag.
 *
 * Implements    : FLASH_DRV_ClearDoubleBitFaultFlag_Activity
 */
static inline void FLASH_DRV_ClearDoubleBitFaultFlag(void)
{
    EFM->STS = EFM_STS_UNRECOVERR_MASK;
}

/*!
 * @brief Enable the read collision error interrupt.
 *
 * This function will enable the read collision error interrupt generation when an
 * EFM read collision error occurs.
 *
 * @return operation status
 *        - STATUS_SUCCESS:         Operation was successful.
 */
status_t FLASH_DRV_EnableReadCollisionInterrupt(void);

/*!
 * @brief Disable the read collision error interrupt.
 *
 */
void FLASH_DRV_DisableReadCollisionInterrupt(void);

/*!
 * @brief Enable the double bit fault detect interrupt.
 *
 * This function will enable the double bit fault detect interrupt generation when
 * an uncorrectable ECC fault is detected during a valid flash read access from
 * the platform flash controller.
 *
 * @return operation status
 *        - STATUS_SUCCESS:         Operation was successful.
 */
status_t FLASH_DRV_EnableDoubleBitFaultInterrupt(void);

/*!
 * @brief Disable the double bit fault detect interrupt.
 *
 */
void FLASH_DRV_DisableDoubleBitFaultInterrupt(void);


/*!
 * @brief Flash NVR Sector Erase
 *
 * This API is used to erase an NVR sector of flash memory.
 * THis API won't support multi-sector erase for safety consideration.
 *
 * \note User have to unlock the flash NVR sector before programming.
 *
 * @param[in] dest Start address for the target flash NVR sector.
                   This address should be aligned to flash block margin.
 * @return operation status
 *        - STATUS_SUCCESS:         Operation was successful.
 *        - STATUS_ERROR:           Operation failure was occurred.
 *        - STATUS_BUSY:            Operation was busy.
 */
status_t FLASH_DRV_EraseNVR(uint32_t dest);

/*!
 * @brief Flash NVR Program
 *
 * This API is used to program flash NVR sectors.
 * User can get flash NVR partition information from chip reference manual.
 * This API can be used to program AES key, customer NVR region, etc.
 * \note User have to unlock the flash NVR sector before programming.
 * \note THis API won't support multi-sector program for safety consideration.
 *
 * @param[in] dest Start address for the target flash NVR sector.
                   This address should be aligned to flash block margin.
 * @param[in] size Size in byte to be programmed.
 *                 This size should be aligned to bytes following below table.
 * @param[in] pData Pointer of source address from which data has to
 *                  be taken for program operation. **pData should be aligned to
 *                  32-bit boundary**.
 * @return operation status
 *        - STATUS_SUCCESS:         Operation was successful.
 *        - STATUS_ERROR:           Operation failure was occurred.
 *        - STATUS_BUSY:            Operation was busy.
 */
status_t FLASH_DRV_ProgramNVR(uint32_t dest, uint32_t size, const void *pData);

/*!
 * @brief Flash NVR Read
 *
 * This API is used to read data from flash NVR region.
 * This API won't support AES key read for safety consideration.
 *
 * \note User have to unlock the flash NVR sector before programming.
 *
 * @param[in] address Start address for the target flash NVR sector.
 *                 This address should be aligned to flash block margin.
 * @param[in] size Total read data length in byte.
 *                 This read length should be aligned to flash program margin.
 * @param[out] dest Read data destination address.
 *                 This address should be aligned to 32-bit boundary.
 * @return operation status
 *        - STATUS_SUCCESS:         Operation was successful.
 *        - STATUS_ERROR:           Operation failure was occurred.
 *        - STATUS_BUSY:            Operation was busy.
 */
status_t FLASH_DRV_ReadNVR(uint32_t address, uint32_t size, void *dest);

#ifdef FEATURE_EFM_BOOT_SWAP_CMD_CODE

/*!
 * @brief Flash boot swap
 *
 * This API is used swap the boot flash block with the current flash block.
 *
 * @return operation status
 *        - STATUS_SUCCESS:         Operation was successful.
 *        - STATUS_ERROR:           Operation failure was occurred.
 *        - STATUS_BUSY:            Operation was busy.
 */
status_t FLASH_DRV_BootSwap(void);

#endif

#ifdef FEATURE_EFM_LOAD_AES_KEY_CMD_CODE
/*!
 * @brief Flash load AES key
 *
 * This API is used for load AES key for HCU.
 *
 * @param[in] address Start address for the target flash NVR sector.
 *                 This address should be aligned to flash block margin.
 * 
 * @return operation status
 *        - STATUS_SUCCESS:         Operation was successful.
 *        - STATUS_ERROR:           Operation failure was occurred.
 *        - STATUS_BUSY:            Operation was busy.
 */
status_t FLASH_DRV_LoadAESKey(uint32_t address);
#endif /* FEATURE_EFM_LOAD_AES_KEY_CMD_CODE */

#if defined(__cplusplus)
}
#endif

/*@}*/ /* End of Flash driver APIs*/
/*! @}*/ /* End of addtogroup flash_driver */

#endif /* FLASH_DRIVER_H */
