/*
 * Copyright 2020-2024 Yuntu Microelectronics co.,ltd
 * All rights reserved.
 *
 * YUNTU Confidential. This software is owned or controlled by YUNTU and may
 * only be used strictly in accordance with the applicable license terms. By expressly
 * accepting such terms or by downloading, installing, activating and/or otherwise
 * using the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms. If you do not agree to be
 * bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software. The production use license in
 * Section 2.3 is expressly granted for this software.
 */
/*!
 * @file fls_drv_bin.h
 *
 */
#ifndef FLS_DRV_BIN_H
#define FLS_DRV_BIN_H

#include "stdint.h"
#include "status.h"

#define TEST_BY_ARRAY  /* Comment this line if download bin file to SRAM */

#ifdef TEST_BY_ARRAY
// #include "fls_drv_bin_data.h"
// #define FLS_DRV_BASE_ADDR ((uint32_t)bin_data)
//#define FLS_DRV_BASE_ADDR ((uint32_t)0x1FFFF000)
#else
//#define FLS_DRV_BASE_ADDR ((uint32_t)0x20004000)    /* Base address of the flash driver bin which download to SRAM */
#endif /* TEST_BY_ARRAY */

#define FLASH_DRIVER_VERSION_TYPE       (0x8001u)
#define FLASH_DRIVER_VERSION_INDEX      (0x0000u)
#define FLASH_DRIVER_VERSION_MAGIC      (0x58455031UL)
#define FLASH_DRIVER_VERSION_VERSION    (0x00010300UL)

#define FLASH_DRIVER_INIT_OFFSET        (0x0Cu)
#define FLASH_DRIVER_DEINIT_OFFSET      (0x10u)
#define FLASH_DRIVER_ERASE_OFFSET       (0x14u)
#define FLASH_DRIVER_WRITE_OFFSET       (0x18u)





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

/* FLASH driver API */
//#define FLASH_DRV_GetVersion()                 ((uint32_t)(((fls_drv_tbl_t*)(FLS_DRV_BASE_ADDR))->version))

/* Init to enble the CMD_VERIFY_EN, which determines whether to do verify read after erase or program operation during executing a command.
 * It would be okay, if not call the FLASH_DRV_Init() function. */
// #define FLASH_DRV_Init()                       ((FLASH_Init_t)((uint32_t)(((fls_drv_tbl_t*)(FLS_DRV_BASE_ADDR))->init) + FLS_DRV_BASE_ADDR))()

// /* Deinit do nothing, just return success. */
// #define FLASH_DRV_Deinit()                     ((FLASH_Deinit_t)((uint32_t)(((fls_drv_tbl_t*)(FLS_DRV_BASE_ADDR))->deinit) + FLS_DRV_BASE_ADDR))()

// #define FLASH_DRV_EraseSector(dest, size)      ((FLASH_EraseSector_t)((uint32_t)(((fls_drv_tbl_t*)(FLS_DRV_BASE_ADDR))->eraseSector) + FLS_DRV_BASE_ADDR))(dest, size)

// #define FLASH_DRV_Program(dest, size, pData)   ((FLASH_Program_t)((uint32_t)(((fls_drv_tbl_t*)(FLS_DRV_BASE_ADDR))->program) + FLS_DRV_BASE_ADDR))(dest, size, pData)

/* Not all chip suppoert bootswap */
//#define FLASH_DRV_BootSwap()                   ((FLASH_BootSwap_t)((uint32_t)(((fls_drv_tbl_t*)(FLS_DRV_BASE_ADDR))->bootSwap) + FLS_DRV_BASE_ADDR))()

#endif /* FLS_DRV_BIN_H */