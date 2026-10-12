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
//#include "Mcal.h"
#include "Mcu.h"
/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* Including necessary configuration files. */
#include "bl_rte.h"
#include "bl_booting.h"
#include "bl_process_driver.h"
#include "bl_app.h"




/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{

    Rte_PreInit();

    Rte_PostInit();
    
    App_LoadBootloader();

    PROC_SCHEDULE();

    return 0;
}

