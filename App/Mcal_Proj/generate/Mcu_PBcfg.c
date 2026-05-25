/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Mcu_PBcfg.c
 * @brief 
 * 
 */



#include "Mcu.h"
#if (MCU_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
#include "Dem.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_VENDOR_ID_PBCFG_C                      (180)
#define MCU_AR_RELEASE_MAJOR_VERSION_PBCFG_C       (4)
#define MCU_AR_RELEASE_MINOR_VERSION_PBCFG_C       (4)
#define MCU_AR_RELEASE_REVISION_VERSION_PBCFG_C    (0)
#define MCU_SW_MAJOR_VERSION_PBCFG_C               (0)
#define MCU_SW_MINOR_VERSION_PBCFG_C               (9)
#define MCU_SW_PATCH_VERSION_PBCFG_C               (1)

/*================================================================================================== */


#if (MCU_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)
/* Check if Mcu_Cfg.c file and Dem.h file are of the same Autosar version */
#if ((MCU_AR_RELEASE_MAJOR_VERSION_PBCFG_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_AR_RELEASE_MINOR_VERSION_PBCFG_C != DEM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mcu_PBcfg.c and Dem.h are different"
#endif

#endif



#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

MCU_CONST const Mcu_SircConfigType Mcu_RootSircConfig[1] = {
    {
        .SircClockRefPointFrequency = 2000000U,
        .SircDeepSleepEnable = (boolean)STD_OFF,
        .SircStandbyEnable = (boolean)STD_OFF,
    },
};

MCU_CONST const Mcu_FircConfigType Mcu_RootFircConfig[1] = {
    {
        .FircClockRefPointFrequency = 48000000U,
        .FircDeepSleepEnable = (boolean)STD_OFF,
        .FircDelayEnable = (boolean)STD_OFF,
    },
};

MCU_CONST const Mcu_FxoscConfigType Mcu_RootFxoscConfig[1] = {
    {
        .ClockRefPointFrequency = 8000000U,
        .BypassMode = (boolean)STD_OFF,
        .GainSelection = 6U,
        .DeepSleepEnable = (boolean)STD_OFF,
        .DelaySelect = MCU_FXOSC_DELAY_16384_CYCLES,
    },
};

#if MCU_NO_PLL == STD_OFF
MCU_CONST const Mcu_PllConfigType Mcu_RootPllConfig[1] = {
    {
        .ClockRef = MCU_PLL_CLOCK_REFERENCE_FXOSC,
        .RefDiv = 0U,
        .FeedbackDiv = 19U,
    },
};
#endif /* #if MCU_NO_PLL == STD_OFF */


MCU_CONST const Mcu_ClockOutConfigType Mcu_RootClockOutConfig[1] = {
    {
        .Source = MCU_CLOCK_OUT_SOURCE_OFF,
        /* The register value should be subtract with 1 */
        .ClockOutDiv = 0U,
    },
};



MCU_CONST const Mcu_IpcConfigType Mcu_RootIpcConfig_0[37] = {
    {
        .PeripheralIndex = MCU_IPC_DMA_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_GPIO_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_PCTRLA_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_PCTRLB_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_PCTRLC_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_PCTRLD_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_PCTRLE_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_UART0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_UART1_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_UART2_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_PLL,
        .ClockDiv = 1U,
    },
    {
        .PeripheralIndex = MCU_IPC_I2C0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_I2C1_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_SPI0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_SPI1_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_SPI2_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_FlexCAN0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_FlexCAN1_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_FlexCAN2_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_eADC0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_PLL,
        .ClockDiv = 4U,
    },
    {
        .PeripheralIndex = MCU_IPC_ACMP0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_TMU_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_eTMR0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_PLL,
        .ClockDiv = 1U,
    },
    {
        .PeripheralIndex = MCU_IPC_eTMR1_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_PLL,
        .ClockDiv = 1U,
    },
    {
        .PeripheralIndex = MCU_IPC_MPWM0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_PLL,
        .ClockDiv = 1U,
    },
    {
        .PeripheralIndex = MCU_IPC_pTMR0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_lpTMR0_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_RTC_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_CRC_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_TRNG_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_HCU_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_WDG_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_EWDG_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_EMU_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_CMU_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_CFMU_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_CIM_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
    {
        .PeripheralIndex = MCU_IPC_SCU_INDEX,
        .ClockEnable = (boolean)STD_ON,
        .ClockSource = MCU_IPC_CLK_SRC_OFF,
        .ClockDiv = 0U,
    },
};

MCU_CONST const Mcu_PeripheralClockConfigType Mcu_RootPeripheralClockConfig[1] = {
    {
        .IpcCount = 37U,
        .IpcConfig = (Mcu_IpcConfigType *)&Mcu_RootIpcConfig_0[0],
    },
};



MCU_CONST const Mcu_ClockConfigType Mcu_RootClockConfig[1] = {
    [0] = {
        .SystemClockSource = MCU_SYSTEM_CLOCK_SOURCE_PLL,
        .CoreClockDiv = 0U,
        .FastBusClockDiv = 0U,
        .SlowBusClockDiv = 1U,
        .EfmPrescaleValue = 20U,
        .EfmWRSValue = 1U,

        .SircUnderUserCtrl = (boolean)STD_OFF,
        .SircConfig = &Mcu_RootSircConfig[0],

        .FircUnderUserCtrl = (boolean)STD_OFF,
        .FircEnable = (boolean)STD_ON,
        .FircConfig = &Mcu_RootFircConfig[0],

        .FxoscUnderUserCtrl = (boolean)STD_ON,
        .FxoscEnable = (boolean)STD_ON,
        .FxoscConfig = &Mcu_RootFxoscConfig[0],
#if (MCU_NO_PLL == STD_OFF)
        .PllUnderUserCtrl = (boolean)STD_ON,
        .PllEnable = (boolean)STD_ON,
        .PllConfig = (Mcu_PllConfigType *)&Mcu_RootPllConfig[0],
#endif
        .ClockOutEnable = (boolean)STD_OFF,
        .ClockOutConfig = &Mcu_RootClockOutConfig[0],

        .ClockMonitorConfig = NULL_PTR,
        .ClockMonitorConfigNums = 0,

        .PeripheralClockConfig = &Mcu_RootPeripheralClockConfig[0],
    },
};

MCU_CONST const Mcu_ResetConfigType Mcu_RootResetConfig={
    .HwResetPinOutputEnable = STD_OFF,
    .HwResetPinFilterEnable = STD_OFF,
    .HwResetPinFilterCount = 0U,
};

MCU_CONST const Mcu_PcuLvdConfigType Mcu_PcuLvdConfig = {
    .EnableBitList.BOREnable               = (boolean)STD_OFF,
    .EnableBitList.BORLowPowerModeEnable   = (boolean)STD_OFF,
    .EnableBitList.LVD5VEnable             = (boolean)STD_OFF,
    .EnableBitList.LVD5VFilterEnable       = (boolean)STD_OFF,
    .EnableBitList.LVD5VIntEnable          = (boolean)STD_ON,
    .EnableBitList.LVD5VLowPowerModeEnable = (boolean)STD_OFF,
    .EnableBitList.LVD5VReset              = (boolean)STD_OFF,
    .LVD5VFilterWidth                      = (uint8)0,
    .LVD5VNotificationPtr                  = NULL_PTR,
    .LVD5VTrim                             = MCU_PCU_LVD5V_TRIM_1850MV,
    .LVD5VHysteresis                       = MCU_PCU_LVD5V_HYS_PERCENT_0P0
};

MCU_CONST const Mcu_PcuConfigType Mcu_PcuConfig = {
    .LvdConfigPtr = &Mcu_PcuLvdConfig,
    .SetCoreVoltage = STD_OFF,
    .PMCHPRDYConfigure = MCU_PCU_PMCHPRDY_DELAY_80US,
    .EnergySavingConfigure = MCU_PCU_ESCFG_INDEX_0,
};

MCU_CONST const Mcu_PowerModeType PowerModeMap[1]={
    MCU_POWER_MODE_RUN,
};


MCU_CONST const Mcu_PowerConfigType McuPowerConfig = {
    .ModeMap = PowerModeMap
};

MCU_CONST const Mcu_ConfigType Mcu_Config = {
    .ClockConfig = Mcu_RootClockConfig,
    .ClockConfigNum = (1U),
    .RamSectionConfig = NULL_PTR,
    .ResetConfig = &Mcu_RootResetConfig,
    .RamSectionConfigNum = 0U,
    .ModeConfigNum = 1U,
    .PowerConfig = &McuPowerConfig,
    .PcuConfig = &Mcu_PcuConfig,
};


#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

