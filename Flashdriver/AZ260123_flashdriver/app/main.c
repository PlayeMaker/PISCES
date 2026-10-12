/* USER CODE BEGIN Header */
/* you can remove the copyright */

/*
 *  Copyright 2020-2025 Yuntu Microelectronics Co., Ltd.
 *  All rights reserved.
 * 
 *  SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file main.c
 * @brief 
 * 
 */

/* USER CODE END Header */
#include "sdk_project_config.h"
//#include "fls_drv_bin.h"
#include "flash_driver.h"
#include "bl_flash_if.h"
#include "bl_flash.h"
#include "fls_drv_bin_data.h"



/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define FLASH_INST (0U)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
/* USER CODE END PV */

/* Private function declare --------------------------------------------------*/
/* USER CODE BEGIN PFDC */
/* USER CODE END PFDC */
static void Board_Init(void);

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */


/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
    bl_FlashDrvParam_t param;
    /* USER CODE BEGIN 1 */
    status_t status = STATUS_SUCCESS;
    uint32_t addr;
    uint8_t data[32] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};
    /* USER CODE END 1 */ 
    Board_Init();
    /* USER CODE BEGIN 2 */
    PRINTF("Build %s %s\n", __DATE__, __TIME__);
    PRINTF("Flash demo!\r\n");


    g_FlashHeader.Init(&param); //FLASHIF_INIT(&param);
    


    PRINTF("=> Checking erase/program PFlash0!\r\n");
    PRINTF("Due to cache pflash enable, it must disable cache first!\r\n");
    // CACHE_DRV_Disable(0);
    /* Erase 4K from 0x18000 to 0x18FFF */
	param.address = 0x18000;
	param.size = 4 * 1024;
    g_FlashHeader.Erase(&param); //FLASH_DRV_EraseSector(0x18000, 4 * 1024);


    param.size = 32;
    param.buffer = data;
    /* Write 4K from 0x18000 to 0x18FFF */
    g_FlashHeader.Write(&param);
    //CACHE_DRV_Disable(0);
    /* Erase 4K from 0x18000 to 0x18FFF */
    g_FlashHeader.Erase(&param); //FLASH_DRV_EraseSector(0x18000, 4 * 1024);





    CACHE_DRV_Enable(0);
    for (addr = 0x18000; addr < 0x18FFF; addr += 4)
    {
        if (*(uint32_t *)addr != addr)
        {
            PRINTF("Address %x program failed!\r\n", addr);
        }
    }

    PRINTF("=> Checking erase/program PFlash1!\r\n");
    PRINTF("Due to cache pflash enable, it must disable cache first!\r\n");
    CACHE_DRV_Disable(0);


    /* Write 6K from 0x40000 to 0x41800 */
    CACHE_DRV_Enable(0);
    for (addr = 0x40000; addr < 0x41800; addr += 4)
    {
        if (*(uint32_t *)addr != addr)
        {
            PRINTF("Address %x program failed!\r\n", addr);
        }
    }


    PRINTF("Flash check finished.\n");
    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1)
    {
        if (status != STATUS_SUCCESS)
        {
            break;
        }
        /* USER CODE END WHILE */
        /* USER CODE BEGIN 3 */
    }
    return status;
    /* USER CODE END 3 */
}

static void Board_Init(void)
{
    // CLOCK_SYS_Init(g_clockManConfigsArr,CLOCK_MANAGER_CONFIG_CNT,g_clockManCallbacksArr,CLOCK_MANAGER_CALLBACK_CNT);
    // if(STATUS_SUCCESS != CLOCK_SYS_UpdateConfiguration(CLOCK_MANAGER_ACTIVE_INDEX,CLOCK_MANAGER_POLICY_AGREEMENT))
    // {
    //     /* USER CODE BEGIN ERROR_HANDLER 1 */
    //     SystemSoftwareReset();
    //     /* USER CODE END ERROR_HANDLER 1 */
    // }
    // CACHE_DRV_Init(0,&cache_config0);
    // PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0,g_pin_mux_InitConfigArr0);
    // UTILITY_PRINT_Init();
}

/* USER CODE BEGIN 4 */
/* USER CODE END 4 */
