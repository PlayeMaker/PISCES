/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Wdg_180_Inst0_Cfg_Defines.h
 * @brief 
 * 
 */


#ifndef WDG_180_Inst0_CFG_DEFINES_H
#define WDG_180_Inst0_CFG_DEFINES_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                         INCLUDE FILES                                         
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
 *                                       DEFINES AND MACROS                                       
==================================================================================================*/

/**
 * @brief   Compile switch to allow trigger Wdg manually or only by Gpt timer.
 * @details true: Wdg is allowed to triggered manually.
            false: Wdg is triggered only by Gpt timer.
 */
#define WDG_180_INST0_MANUAL_SERVICE    (STD_ON)

/**
 * @brief   WDG enable
 */
#define WDG_180_INST0_ENABLE              (STD_ON)



#ifdef __cplusplus
}
#endif

#endif /* WDG_180_Inst0_CFG_DEFINES_H */

