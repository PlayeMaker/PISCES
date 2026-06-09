/*
 * Copyright 2020-2025 Yuntu Microelectronics Co., Ltd.
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
    /* PCR-0, Feature-GPIO */
    
    {
        .HwPinId = 0,
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
    /* PCR-1, Feature-GPIO */
    
    {
        .HwPinId = 1,
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
    /* PCR-2, Feature-GPIO */
    
    {
        .HwPinId = 2,
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
    /* PCR-3, Feature-GPIO */
    
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
    /* PCR-6, Feature-GPIO */
    
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
    /* PCR-7, Feature-GPIO */
    
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
    /* PCR-10, Feature-GPIO */
    
    {
        .HwPinId = 10,
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
    /* PCR-11, Feature-GPIO */
    
    {
        .HwPinId = 11,
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
    /* PCR-12, Feature-GPIO */
    
    {
        .HwPinId = 12,
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
    /* PCR-13, Feature-GPIO */
    
    {
        .HwPinId = 13,
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
        .Direction = PORT_PIN_OUT,
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
    /* PCR-34, Feature-GPIO */
    
    {
        .HwPinId = 2,
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
    /* PCR-35, Feature-GPIO */
    
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
    /* PCR-36, Feature-GPIO */
    
    {
        .HwPinId = 4,
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
    /* PCR-37, Feature-GPIO */
    
    {
        .HwPinId = 5,
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
    /* PCR-45, Feature-GPIO */
    
    {
        .HwPinId = 13,
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
};

PORT_CONST static const Port_PinConfigType Port_C_PinsConfig[] = {
    
    /* PCR-64, Feature-GPIO */
    {
        .HwPinId = 0,
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
    
    /* PCR-65, Feature-GPIO */
    {
        .HwPinId = 1,
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
    
    /* PCR-66, Feature-GPIO */
    {
        .HwPinId = 2,
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
    
    /* PCR-67, Feature-GPIO */
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
    
    /* PCR-69, Feature-GPIO */
    {
        .HwPinId = 5,
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
    
    /* PCR-70, Feature-GPIO */
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
    
    /* PCR-71, Feature-GPIO */
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
    
    /* PCR-72, Feature-GPIO */
    {
        .HwPinId = 8,
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
    
    /* PCR-78, Feature-GPIO */
    {
        .HwPinId = 14,
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
    
    /* PCR-79, Feature-GPIO */
    {
        .HwPinId = 15,
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
    
    /* PCR-80, Feature-GPIO */
    {
        .HwPinId = 16,
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
    
    /* PCR-81, Feature-GPIO */
    {
        .HwPinId = 17,
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
};


PORT_CONST static const Port_PinConfigType Port_D_PinsConfig[] = {
    
    /* PCR-96, Feature-GPIO */
    {
        .HwPinId = 0,
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
    
    /* PCR-98, Feature-GPIO */
    {
        .HwPinId = 2,
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
    
    /* PCR-99, Feature-GPIO */
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
    
    /* PCR-100, Feature-GPIO */
    {
        .HwPinId = 4,
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
    
    /* PCR-101, Feature-GPIO */
    {
        .HwPinId = 5,
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
    
    /* PCR-102, Feature-GPIO */
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
    
    /* PCR-103, Feature-GPIO */
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
    
    /* PCR-111, Feature-GPIO */
    {
        .HwPinId = 15,
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
    
    /* PCR-112, Feature-GPIO */
    {
        .HwPinId = 16,
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
};


PORT_CONST static const Port_PinConfigType Port_E_PinsConfig[] = {
    
    /* PCR-128, Feature-GPIO */
    {
        .HwPinId = 0,
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
    
    /* PCR-129, Feature-GPIO */
    {
        .HwPinId = 1,
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
    
    /* PCR-130, Feature-GPIO */
    {
        .HwPinId = 2,
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
    
    /* PCR-132, Feature-GPIO */
    {
        .HwPinId = 4,
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
    
    /* PCR-133, Feature-GPIO */
    {
        .HwPinId = 5,
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
    
    /* PCR-134, Feature-GPIO */
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
    
    /* PCR-135, Feature-GPIO */
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
    
    /* PCR-136, Feature-GPIO */
    {
        .HwPinId = 8,
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
    
    /* PCR-137, Feature-GPIO */
    {
        .HwPinId = 9,
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
    
    /* PCR-138, Feature-GPIO */
    {
        .HwPinId = 10,
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
    
    /* PCR-139, Feature-GPIO */
    {
        .HwPinId = 11,
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

