/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Port_PBcfg.c
 * @brief 
 * 
 */



#include "Port.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PORT_VENDOR_ID_PBCFG_C                      (180)
#define PORT_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define PORT_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define PORT_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define PORT_SW_MAJOR_VERSION_PBCFG_C               (0)
#define PORTU_SW_MINOR_VERSION_PBCFG_C              (9)
#define PORTU_SW_PATCH_VERSION_PBCFG_C              (1)

/*================================================================================================== */

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

PORT_CONST static const Port_PinConfigType Port_A_PinsConfig[] = {
    /* PCR-0, Feature-MPWM0_CH1 */
    
    {
        .HwPinId = 0,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-1, Feature-eTMR1_CH1 */
    
    {
        .HwPinId = 1,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-2, Feature-MPWM0_CH8 */
    
    {
        .HwPinId = 2,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-3, Feature-ADC0_SE17 */
    
    {
        .HwPinId = 3,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ANA,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-6, Feature-GPIO */
    
    {
        .HwPinId = 6,
        .Direction = PORT_PIN_OUT,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_GPIO,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-7, Feature-GPIO */
    
    {
        .HwPinId = 7,
        .Direction = PORT_PIN_OUT,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_GPIO,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-10, Feature-eTMR1_CH4 */
    
    {
        .HwPinId = 10,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-11, Feature-eTMR1_CH5 */
    
    {
        .HwPinId = 11,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-12, Feature-eTMR1_CH6 */
    
    {
        .HwPinId = 12,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-13, Feature-eTMR1_CH7 */
    
    {
        .HwPinId = 13,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
};


PORT_CONST static const Port_PinConfigType Port_B_PinsConfig[] = {
    /* PCR-32, Feature-CAN0_RX */
    
    {
        .HwPinId = 0,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT5,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-33, Feature-CAN0_TX */
    
    {
        .HwPinId = 1,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT5,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-34, Feature-ADC0_SE6 */
    
    {
        .HwPinId = 2,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ANA,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-35, Feature-ADC0_SE7 */
    
    {
        .HwPinId = 3,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ANA,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-36, Feature-eTMR0_CH4 */
    
    {
        .HwPinId = 4,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-37, Feature-eTMR0_CH5 */
    
    {
        .HwPinId = 5,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-38, Feature-GPIO */
    
    {
        .HwPinId = 6,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_UNCHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_GPIO,
        .IsModeChangeable = PORT_PIN_MODE_NOT_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-39, Feature-GPIO */
    
    {
        .HwPinId = 7,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_UNCHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_GPIO,
        .IsModeChangeable = PORT_PIN_MODE_NOT_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-44, Feature-GPIO */
    
    {
        .HwPinId = 12,
        .Direction = PORT_PIN_OUT,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_GPIO,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    /* PCR-45, Feature-GPIO */
    
    {
        .HwPinId = 13,
        .Direction = PORT_PIN_OUT,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_GPIO,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
};

PORT_CONST static const Port_PinConfigType Port_C_PinsConfig[] = {
    
    /* PCR-64, Feature-ADC0_SE8 */
    {
        .HwPinId = 0,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ANA,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-65, Feature-ADC0_SE9 */
    {
        .HwPinId = 1,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ANA,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-66, Feature-eTMR0_CH2 */
    {
        .HwPinId = 2,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-67, Feature-eTMR0_CH3 */
    {
        .HwPinId = 3,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-69, Feature-GPIO */
    {
        .HwPinId = 5,
        .Direction = PORT_PIN_OUT,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_GPIO,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-70, Feature-MPWM0_CH10 */
    {
        .HwPinId = 6,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT4,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-71, Feature-MPWM0_CH11 */
    {
        .HwPinId = 7,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT4,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-72, Feature-GPIO */
    {
        .HwPinId = 8,
        .Direction = PORT_PIN_OUT,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_GPIO,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-73, Feature-GPIO */
    {
        .HwPinId = 9,
        .Direction = PORT_PIN_OUT,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_GPIO,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-78, Feature-ADC0_SE12 */
    {
        .HwPinId = 14,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ANA,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-79, Feature-ADC0_SE13 */
    {
        .HwPinId = 15,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ANA,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-80, Feature-ADC0_SE14 */
    {
        .HwPinId = 16,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ANA,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-81, Feature-ADC0_SE15 */
    {
        .HwPinId = 17,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ANA,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
};


PORT_CONST static const Port_PinConfigType Port_D_PinsConfig[] = {
    
    /* PCR-96, Feature-MPWM0_CH0 */
    {
        .HwPinId = 0,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT4,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-98, Feature-MPWM0_CH12 */
    {
        .HwPinId = 2,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-99, Feature-GPIO */
    {
        .HwPinId = 3,
        .Direction = PORT_PIN_OUT,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_GPIO,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-100, Feature-ADC0_SE22 */
    {
        .HwPinId = 4,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ANA,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-101, Feature-GPIO */
    {
        .HwPinId = 5,
        .Direction = PORT_PIN_OUT,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_GPIO,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-102, Feature-UART2_RX */
    {
        .HwPinId = 6,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-103, Feature-UART2_TX */
    {
        .HwPinId = 7,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-111, Feature-eTMR0_CH0 */
    {
        .HwPinId = 15,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-112, Feature-eTMR0_CH1 */
    {
        .HwPinId = 16,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
};


PORT_CONST static const Port_PinConfigType Port_E_PinsConfig[] = {
    
    /* PCR-128, Feature-GPIO */
    {
        .HwPinId = 0,
        .Direction = PORT_PIN_OUT,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_GPIO,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-129, Feature-GPIO */
    {
        .HwPinId = 1,
        .Direction = PORT_PIN_OUT,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_GPIO,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-130, Feature-MPWM0_CH14 */
    {
        .HwPinId = 2,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT4,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-131, Feature-GPIO */
    {
        .HwPinId = 3,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_UNCHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_GPIO,
        .IsModeChangeable = PORT_PIN_MODE_NOT_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-132, Feature-MPWM0_CH2 */
    {
        .HwPinId = 4,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT4,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-133, Feature-MPWM0_CH3 */
    {
        .HwPinId = 5,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT4,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-134, Feature-MPWM0_CH15 */
    {
        .HwPinId = 6,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT4,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-135, Feature-GPIO */
    {
        .HwPinId = 7,
        .Direction = PORT_PIN_OUT,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_GPIO,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-136, Feature-eTMR0_CH6 */
    {
        .HwPinId = 8,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-137, Feature-eTMR0_CH7 */
    {
        .HwPinId = 9,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT2,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-138, Feature-MPWM0_CH4 */
    {
        .HwPinId = 10,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT4,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
    
    /* PCR-139, Feature-MPWM0_CH5 */
    {
        .HwPinId = 11,
        .Direction = PORT_PIN_IN,
        .IsDirectionChangeable= PORT_PIN_DIRECTION_CHANGEABLE,
        .InitLevel = PORT_PIN_LEVEL_LOW,
        .InitMode=  PORT_PIN_MODE_ALT4,
        .IsModeChangeable = PORT_PIN_MODE_CHANGEABLE,
        .PullConfig = PORT_PIN_NO_PULL,
        .DriveStrength = PORT_PIN_LOW_DRIVE_STRENGTH,
        .PassiveFilter = (boolean)0,
        .DigitalFilter = (boolean)0,
        .DigitalFilterWidth = 0,
        .OutputCompare = (boolean)0,
        .InvertEnable = (boolean)0,
    },
};




PORT_CONST const Port_GroupConfigType PortGroup_Config[PORT_TOTAL_NUMBER] ={
     /* PORT_A Config */
    {
        .HwPortId = 0,
        .NumberOfPortPins = 10,
        .PortPinConfigPtr = &Port_A_PinsConfig[0],
    },
    /* PORT_B Config */
    {
        .HwPortId = 1,
        .NumberOfPortPins = 10,
        .PortPinConfigPtr = &Port_B_PinsConfig[0],
    },
    /* PORT_C Config */
    {
        .HwPortId = 2,
        .NumberOfPortPins = 13,
        .PortPinConfigPtr = &Port_C_PinsConfig[0],
    },
    /* PORT_D Config */
    {
        .HwPortId = 3,
        .NumberOfPortPins = 9,
        .PortPinConfigPtr = &Port_D_PinsConfig[0],
    },
    /* PORT_E Config */
    {
        .HwPortId = 4,
        .NumberOfPortPins = 12,
        .PortPinConfigPtr = &Port_E_PinsConfig[0],
    },
};

PORT_CONST const Port_ConfigType Port_Config = {
.NumberOfGroup = PORT_TOTAL_NUMBER,
    .PortGroupConfigPtr = &PortGroup_Config[0],
};


#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"

