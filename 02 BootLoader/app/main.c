/* USER CODE BEGIN Header */
/* you can remove the copyright */
/*
 * Copyright 2020-2025 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 * 
 *  YUNTU Confidential. This software is owned or controlled by YUNTU and may only be
 *  used strictly in accordance with the applicable license terms. By expressly
 *  accepting such terms or by downloading, installing, activating and/or otherwise
 *  using the software, you are agreeing that you have read, and that you agree to
 *  comply with and are bound by, such license terms. If you do not agree to be
 *  bound by the applicable license terms, then you may not retain, install,
 *  activate or otherwise use the software. The production use license in
 *  Section 2.3 is expressly granted for this software.
 * 
 * @file main.c
 * @brief
 *
 */

/* USER CODE END Header */
#include "Mcal.h"
/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <osif.h>
#include <string.h>

#include "bl_can_if.h"
#include "bl_rte.h"
#include "bl_logical_block.h"
#include "bl_memory.h"
#include "bl_system.h"
#include "bl_booting.h"
#include "bl_app.h"
#include "bl_process_driver.h"
#include "bl_security.h"
#include "bl_rte_cfg.h"
#include "bl_adpt_uds_platform.h"
//#include "bl_dflash.h"
#include "bl_flash_if.h"
#include "bl_data_cfg.h"
#include "bl_timer.h"
#include "bl_watchdog.h"
#include "Can_Cfg.h"
#include "status.h"
#include "flash_driver.h"



/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
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

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */


/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
    bl_BootingFlag_t flag;

    Rte_PreInit();

    DIDdata_Init();

    /*Initialize system*/
    flag = Bootm_CheckBootingRequirement();
    if (BOOTING_FLAG_APPLICATION_VALID == flag)
    {
        Bootm_GotoApplication();
        /*never return unless StayInBoot enable and receive a valid SIB frame*/
    }

    Rte_PostInit();
    
    Rte_ProcessReset(flag);

    PROC_SCHEDULE();

    return 0;
}

