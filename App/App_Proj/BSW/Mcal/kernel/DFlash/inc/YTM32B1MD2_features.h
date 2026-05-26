/*
 * Copyright (c) 2024-2025 Yuntu Microelectronics Co., Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*!
 * @file YTM32B1MD2_features.h
 * @brief Chip specific module features
 */

#ifndef YTM32B1MD2_FEATURES_H
#define YTM32B1MD2_FEATURES_H

/* ERRATA sections*/

/* @brief Number of cores. */
#ifndef NUMBER_OF_CORES
#define NUMBER_OF_CORES                     (1u)
#endif /* NUMBER_OF_CORES */

/* SOC module features */

/* @brief PORT availability on the SoC. */
#define FEATURE_SOC_PORT_COUNT              (5)

#define FEATURE_SOC_IPC_COUNT               (1)
/* @brief Power down mode availability on the SoC. */
#define FEATURE_SOC_SUPPORT_POWERDOWN_MODE  (0)
#define FEATURE_SOC_SUPPORT_DEEPPOWERDOWN_MODE  (0)
#define FEATURE_SCU_SUPPORT_PLL             (1)
#define FEATURE_SOC_HAS_SEPARATE_CMU_AND_CLKOUT (1)

/* @brief Cache availability on the SoC. */
#define FEATURE_SOC_SUPPORT_CACHE           (1)

/* @brief Slow IRC clock frequency(2MHz). */
#define FEATURE_SCU_SIRC_FREQ               (2000000U)
/* @brief Fast IRC trimmed clock frequency(48MHz). */
#define FEATURE_SCU_FIRC_FREQ               (48000000U)
/* @brief FXOSC clock frequency(24MHz). */
#define FEATURE_SCU_FXOSC_FREQ              (24000000U)
/* @brief SCU FXOSC support GAIN configuration. */
#define FEATURE_SCU_FXOSC_SUPPORT_GAIN_SEL  (1)
/* @brief SCU support PLL clock. */
#define FEATURE_SCU_SUPPORT_PLL             (1)
/* @brief SCU support CMU reference clock selection. */
#define FEATURE_SCU_SUPPORT_CMU_REFCLK_SEL  (1)
/* @brief SCU support SXOSC 32.768K clock. */
#define FEATURE_SCU_SUPPORT_SXOSC           (0)
#if FEATURE_SCU_SUPPORT_SXOSC
/* @brief SXOSC clock frequency(32.768K). */
#define FEATURE_SCU_SXOSC_FREQ              (32768U)
#endif /* FEATURE_SCU_SUPPORT_SXOSC */
#define FEATURE_SCU_SUPPORT_LPO             (1)
#if FEATURE_SCU_SUPPORT_LPO
#define FEATURE_SCU_LPO_FREQ                (32000U)
#endif
/* @brief Clock switch PLL lock timeout loop count. */
#define FEATURE_CLOCK_TIMEOUT_LOOP_CHECK_CNT      (0xF0)
#define FEATURE_CLOCK_TIMEOUT_LOOP_CNT            (FEATURE_CLOCK_TIMEOUT_LOOP_CHECK_CNT * 64u)

/* FLASH module features */

/* @brief Flash operation clock source, used for PRESCALER */
#define FEATURE_EFM_OPERATION_CLOCK_SOURCE   (SLOW_BUS_CLK)
/* @brief Flash timing max value */
#define FEATURE_EFM_TIMING_MAX               (0x1U)
#define FEATURE_EFM_TIMING1_MAX              (0x3U)
#define FEATURE_EFM_TIMING2_MAX              (0x00030003U)
/* @brief Flash block count. */
#define FEATURE_EFM_BLOCK_COUNT              (3u)
/* @brief Flash program flash start address. */
#define FEATURE_EFM_MAIN_ARRAY_START_ADDRESS (0x0U)
/* @brief Flash program flash end address. */
#define FEATURE_EFM_MAIN_ARRAY_END_ADDRESS   (0x7FFFFU)
/* @brief Flash sector size. */
#define FEATURE_EFM_MAIN_ARRAY_SECTOR_SIZE   (0x200u)
/* @brief Flash has data flash. */
#define FEATURE_EFM_HAS_DATA_FLASH           (1)
#if FEATURE_EFM_HAS_DATA_FLASH
/* @brief Flash data flash start address. */
#define FEATURE_EFM_DATA_ARRAY_START_ADDRESS (0x02000000U)
/* @brief Flash data flash end address. */
#define FEATURE_EFM_DATA_ARRAY_END_ADDRESS   (0x0200FFFFU)
/* @brief Flash data flash sector size. */
#define FEATURE_EFM_DATA_ARRAY_SECTOR_SIZE   (0x200u)
#endif /* FEATURE_EFM_HAS_DATA_FLASH */
#define FEATURE_EFM_HAS_NVR_FLASH (1)
#if FEATURE_EFM_HAS_NVR_FLASH
/* @brief Flash NVR start address. */
#define FEATURE_EFM_NVR_ARRAY_START_ADDRESS (0x10000000U)
/* @brief Flash NVR end address. */
#define FEATURE_EFM_NVR_ARRAY_END_ADDRESS   (0x12001DFFU)
/* @brief Flash NVR sector size. */
#define FEATURE_EFM_NVR_ARRAY_SECTOR_SIZE   (0x200u)
#endif /* FEATURE_EFM_HAS_NVR_FLASH */

/* @brief Flash sector minimum size. */
#define FEATURE_EFM_FLASH_MIN_SECTOR_SIZE    (0x200u)

/* @brief Flash write unit size. */
#define FEATURE_EFM_WRITE_UNIT_SIZE                 (4u)
/* @brief Flash write unit size in words. */
#define FEATURE_EFM_WRITE_UNIT_WORD_SIZE            (FEATURE_EFM_WRITE_UNIT_SIZE >> 2)
/* @brief Flash Program unit command. */
#define FEATURE_EFM_PROGRAM_CMD_CODE                (0x03u)
/* @brief Flash Erase Sector command. */
#define FEATURE_EFM_ERASE_SECTOR_CMD_CODE           (0x10u)
/* @brief Erase Sector Retry Flash command (Soft). */
#define FEATURE_EFM_ERASE_SECTOR_RETRY_CMD_CODE     (0xFEu)
/* @brief Erase Flash Block command. */
#define FEATURE_EFM_ERASE_BLOCK_CMD_CODE            (0x11u)
/* @brief Flash Load AES KEY command. */
#define FEATURE_EFM_LOAD_AES_KEY_CMD_CODE           (0x30u)
/* @brief Flash Boot Swap command. */
#define FEATURE_EFM_BOOT_SWAP_CMD_CODE              (0x31u)
/* @brief Flash Load RSA KEY command. */
#define FEATURE_EFM_LOAD_RSA_KEY_CMD_CODE           (0x2Fu)
/* @brief Flash Boot Swap tag address. */
#define FEATURE_EFM_BOOT_SWAP_TAG_ADDR              (0x11000800u)
/* @brief Flash Status Error Code Mask. */
#define FEATURE_EFM_CMD_ERROR_MASK                                                                   \
    (EFM_STS_CMD_FAIL_MASK | EFM_STS_ACCERR_MASK | EFM_STS_UNRECOVERR_MASK | EFM_STS_RECOVERR_MASK | \
     EFM_STS_CI_BUSYERR_MASK | EFM_STS_CI_WEERR_MASK)
/* @brief Flash Unlock command register. */
#define EFM_UNLOCK_CMD_REGISTER(base)       \
    do                                      \
    {                                       \
        (base)->CMD_UNLOCK = 0xfd9573f5U;   \
    }                                       \
    while (0)
/* @brief Flash enable flash write commands. */
#define EFM_ENABLE_WE_COMMAND(base)         \
    do                                      \
    {                                       \
        (base)->CTRL |= EFM_CTRL_WE_MASK;   \
        __asm("ISB");                       \
        __asm("DSB");                       \
    }                                       \
    while (0)
/* @brief Flash disable flash write commands. */
#define EFM_DISABLE_WE_COMMAND(base)        \
    do                                      \
    {                                       \
        __asm("ISB");                       \
        __asm("DSB");                       \
        (base)->CTRL &= ~EFM_CTRL_WE_MASK;  \
    }                                       \
    while (0)

/* RCU module features */
/* @brief Reset pin output feature */
#define FEATURE_RCU_HAS_PIN_OUTPUT                  (1U)

/* WDG module features */

/*!
 * @brief WDG clock source.
 * Implements : wdg_clock_source_t_Class
 */
typedef enum
{
    WDG_LPO_CLOCK = 0x00U, /*!< LPO clock */
    WDG_SIRC_CLOCK = 0x01U, /*!< SIRC clock */
    WDG_IPC_CLOCK = 0x02U, /*!< IPC clock */
    WDG_BUS_CLOCK = 0x03U, /*!< Bus clock */
} wdg_clock_source_t;
/* @brief The 32-bit value used for unlocking the WDG. */
#define FEATURE_WDG_UNLOCK_VALUE_1                      (0xB631)
#define FEATURE_WDG_UNLOCK_VALUE_2                      (0xC278)
/* @brief The 32-bit value used for resetting the WDG counter. */
#define FEATURE_WDG_TRIGGER_VALUE_1                     (0xA518)
#define FEATURE_WDG_TRIGGER_VALUE_2                     (0xD826)
/* @brief The reset value of the timeout register. */
#define FEATURE_WDG_TOVR_RESET_VALUE                    (0xC00U)
/* @brief The value minimum of the timeout register. */
#define FEATURE_WDG_MINIMUM_TIMEOUT_VALUE               (0x100U)
/* @brief The reset value of the window register. */
#define FEATURE_WDG_WVR_RESET_VALUE                     (0x0U)
/* @brief Default reset value of the LR register. */
#define FEATURE_WDG_LR_RESET_VALUE                      (0x1UL)
/* @brief The value used to set WDG source clock from LPO. */
#define FEATURE_WDG_CLK_FROM_LPO                        (0x1UL)

/* @brief Default reset value of the CR register. */
#define FEATURE_WDG_CR_RESET_VALUE                      (0x2520U)

/* EWDG module features */
/* @brief First byte of the EWM Service key        */
#define FEATURE_EWDG_KEY_FIRST_BYTE                      (0xA8U)
/* @brief Second byte of the EWM Service key       */
#define FEATURE_EWDG_KEY_SECOND_BYTE                     (0x6CU)
/* @brief EWDG maximum compare high value. */
#define FEATURE_EWDG_CMPH_MAX_VALUE                      (0xFFFEU)
/* @brief EWDG minimum compare low value. */
#define FEATURE_EWDG_CMPL_MIN_VALUE                      (0x00U)
/* @brief EWDG support LPO clock */
#define FEATURE_EWDG_SUPPORT_LPO_CLOCK                   (1U)


/* Interrupt module features */

/* @brief Lowest interrupt request number. */
#define FEATURE_INTERRUPT_IRQ_MIN                       (NMI_IRQn)
/* @brief Highest interrupt request number. */
#define FEATURE_INTERRUPT_IRQ_MAX                       (HCU_IRQn)
/**< Number of priority bits implemented in the NVIC */
#define FEATURE_NVIC_PRIO_BITS                          (3U)
/* @brief Has software interrupt. */
#define FEATURE_INTERRUPT_HAS_SOFTWARE_IRQ              (0u)
/* @brief Has pending interrupt state. */
#define FEATURE_INTERRUPT_HAS_PENDING_STATE             (1u)
/* @brief Has active interrupt state. */
#define FEATURE_INTERRUPT_HAS_ACTIVE_STATE              (0u)
/* @brief Multicore support for interrupts */
#define FEATURE_INTERRUPT_MULTICORE_SUPPORT             (0u)
/* @brief Registers in which the start of interrupt vector table needs to be configured */
#define FEATURE_INTERRUPT_INT_VECTORS                   {&SCB->VTOR}

/* eTMR module features */

/* @brief Number of PWM channels */
#define FEATURE_eTMR_CHANNEL_COUNTS                     {8U, 8U}
#define FEATURE_eTMR_CHANNEL_INTERRUPT_COUNTS           (8U)
#define FEATURE_eTMR_CHANNEL_MAX_COUNT                  (8U)
#define FEATURE_eTMR0_CHANNEL_MAX_COUNT                 (8U)
#define FEATURE_eTMR1_CHANNEL_MAX_COUNT                 (8U)
/* @brief Number of fault channels */
#define FEATURE_eTMR_FAULT_CHANNELS                     (4U)
/* @brief Output channel offset */
#define FEATURE_eTMR_OUTPUT_CHANNEL_OFFSET              (16U)
/* @brief Max counter value */
#define FEATURE_eTMR_CNT_MAX_VALUE_U32                  (0xFFFFFFFFU)
/* @brief Input capture for single shot */
#define FEATURE_eTMR_INPUT_CAPTURE_SINGLE_SHOT          (2U)
/* @brief Number of interrupt vector for channels of the eTMR module. */
#define FEATURE_eTMR_HAS_NUM_IRQS_CHANS                 (4U)
/* @brief Deadtime prescaler */
#define FEATURE_eTMR_HAS_DEAD_TIME_PRESCALER            (0U)
/* @brief Double switch */
#define FEATURE_eTMR_HAS_DOUBLE_SWITCH                  (1U)
/* @brief Combination capture mode */
#define FEATURE_eTMR_HAS_COMBINATION_CAPTURE            (0U)
/* @brief Hardware capture method */
#define FEATURE_eTMR_HAS_HARDWARE_CAPTURE               (1U)
/* @brief Capture hold */
#define FEATURE_eTMR_HAS_CAPTURE_HOLD                   (0U)
/* @brief Output trigger width */
#define FEATURE_eTMR_HAS_OUTPUT_TRIGGER_WIDTH           (1U)
/* @brief MID feature */
#define FEATURE_eTMR_HAS_MID                            (1U)
/* @brief Support to configure counter initial value source */
#define FEATURE_eTMR_HAS_CNT_INIT_SRC                   (1U)
/* @brief Counter initial value configurable */
#define FEATURE_eTMR_HAS_INIT_REG                       (1U)
/* @brief CHINIT bit is in Channel CTRL register */
#define FEATURE_eTMR_HAS_CHINIT_BIT                     (1U)
/* @brief Support quad decoder mod register */
#define FEATURE_eTMR_HAS_QUAD_DECODER_MOD               (1U)
/* @brief Support configure dead time alone */
#define FEATURE_eTMR_DEADTIME_CONFIG_EACH_CHANNEL       (1U)
/* @brief Counter count from INIT+1 */
#define FEATURE_eTMR_COUNT_FROM_INIT_PLUS_ONE           (1U)
/* @brief Support 100% duty cycle */
#define FEATURE_eTMR_SUPPORT_100_DUTY_CYCLE             (1U)
/* @brief eTMR support ipc clock source */
#define FEATURE_eTMR_HAS_IPC_CLOCK_SOURCE               (1U)
/* @brief eTMR configure ipc clock source*/
#define eTMR_DRV_ConfigIpcClock(n)                      (CIM->ETMROPT0 |= 0x3 << (n * 2))
/* @brief eTMR internal clock source */
#define eTMR_INTERNAL_CLOCK                             (FAST_BUS_CLK)
/* @brief eTMR external ipc clock source */
#define eTMR_IPC_CLK                                    {eTMR0_CLK, eTMR1_CLK}
/* @brief eTMR external clock source frequency */
#define FEATURE_eTMR_EXTERNAL_CLOCK_FREQ                (1000000U)
/* @brief eTMR Dither MOD configuration */
#define FEATURE_eTMR_HAS_DITHERING                      (1U)
/* @brief eTMR support center align calculation by hardware */
#define FEATURE_eTMR_HAS_HW_CENTER_ALIGN_CALCULATION    (1U)
/* @brief eTMR support channel val0, val1 match interrupt in PWM mode */
#define FEATURE_eTMR_HAS_CHANNEL_VALUE_MATCH_INTERRUPT_IN_PWM_MODE  (1U)

/* MPWM module features */

/* @brief MPWM internal clock source */
#define MPWM_CLK                                        {FAST_BUS_CLK}
/* @brief MPWM clock array */
#define MPWM_IPC_CLK                                    {MPWM0_CLK}
/* @brief MPWM support functional clock */
#define FEATURE_MPWM_HAS_IPC_CLOCK_SOURCE               (1U)
/* @brief MPWM support combination capture */
#define FEATURE_MPWM_HAS_COMBINATION_CAPTURE            (1U)
/* @brief MPWM support ldok/cldok simultaneously */
#define FEATURE_MPWM_HAS_SIMULTANEOUS_UPDATE            (1U)

/* I2C module features */

/* @brief DMA requests for I2C module. */
#define I2C_DMA_REQ                                     {{(uint8_t)DMA_REQ_I2C0_TX, (uint8_t)DMA_REQ_I2C0_RX}, \
                                                            {(uint8_t)DMA_REQ_I2C1_TX, (uint8_t)DMA_REQ_I2C1_RX}}
/* @brief IPC clocks for I2C module. */
#define I2C_CLOCK_NAMES                                  {I2C0_CLK, I2C1_CLK}
/* @brief IPC index for I2C module */
#define I2C_IPC_INDEX                                   {IPC_I2C0_INDEX, IPC_I2C1_INDEX}
/* @brief Slave mode support I2C module. */
#define I2C_SLAVE_SUPPORT                               {TRUE, FALSE}
/* @brief I2C module support TXCFG. */
#define I2C_SUPPORT_TXCFG                               (1)
/* @brief Disable high-speed and ultra-fast operating modes */
#define I2C_HAS_FAST_PLUS_MODE                          (1U)
#define I2C_HAS_HIGH_SPEED_MODE                         (1U)
#define I2C_HAS_ULTRA_FAST_MODE                         (1U)

/* CRC module features */

/* @brief CRC module */
#define FEATURE_CRC_DRIVER_SOFT_POLYNOMIAL
/* @brief Default CRC bit width */
#define FEATURE_CRC_DEFAULT_WIDTH                       CRC_BITS_16
/* @brief CRC support CRC 4 mode*/
#define FEATURE_CRC_SUPPORT_CRC4                        (1)
/* @brief CRC support CRC 8 mode*/
#define FEATURE_CRC_SUPPORT_CRC8                        (1)
/* @brief Default CRC read transpose */
#define FEATURE_CRC_DEFAULT_READ_TRANSPOSE              CRC_TRANSPOSE_NONE
/* @brief Default CRC write transpose */
#define FEATURE_CRC_DEFAULT_WRITE_TRANSPOSE             CRC_TRANSPOSE_NONE
/* @brief Default polynomial 0x1021U */
#define FEATURE_CRC_DEFAULT_POLYNOMIAL                  (0x1021U)
/* @brief Default seed value is 0xFFFFU */
#define FEATURE_CRC_DEFAULT_SEED                        (0xFFFFU)

/* PCTRL module features */
/* @brief Has control lock. */
#define FEATURE_PCTRL_HAS_PIN_CONTROL_LOCK              (1)
/* @brief Has open drain control. */
#define FEATURE_PINS_HAS_OPEN_DRAIN                     (0)
/* @brief Has digital filter. */
#define FEATURE_PINS_HAS_DIGITAL_FILTER                 (0)
/* @brief Has digital filter clock selection. */
#define FEATURE_PINS_HAS_FILTER_CLOCK_SEL               (0)
/* @brief Has digital filter. */
#define FEATURE_PCTRL_HAS_DIGITAL_FILTER                (1)
/* @brief Has trigger output to trigger other peripherals. */
#define FEATURE_PINS_HAS_TRIGGER_OUT                    (0)
/* @brief Has setting flag only. */
#define FEATURE_PINS_HAS_FLAG_SET_ONLY                  (0)
/* @brief Has pull resistor selection available. */
#define FEATURE_PINS_HAS_PULL_SELECTION                 (1)
/* @brief Has slew rate control. */
#define FEATURE_PINS_HAS_SLEW_RATE                      (0)
/* @brief Has filter clock selection control. */
#define FEATURE_PINS_HAS_FILTER_CLOCK_SELECTION         (0)
/* @brief Has passive filter. */
#define FEATURE_PINS_HAS_PASSIVE_FILTER                 (1)
/* @brief Has drive strength. */
#define FEATURE_PINS_HAS_DRIVE_STRENGTH                 (1)
/* @brief Has drive strength control bits*/
#define FEATURE_PINS_HAS_DRIVE_STRENGTH_CONTROL         (1)
/* @brief Has port input disable control bits*/
#define FEATURE_PINS_HAS_INPUT_DISABLE                  (1)


/* ACMP module features */

/* @brief Comparator has internal DAC module */
#define FEATURE_ACMP_HAS_DAC                            (1U)
/* @brief Comparator has power mode control */
#define FEATURE_ACMP_HAS_POWER_MODE                     (1U)
/* @brief Comparator has pin output enable */
#define FEATURE_ACMP_HAS_PINOUT_ENABLE                  (1U)
/* @brief Comparator has mode config */
#define FEATURE_ACMP_HAS_EN_REG                         (1U)
/* @brief Continuous mode is in the CTRL register */
#define FEATURE_ACMP_HAS_CONTINUOUS_MODE_IN_CTRL_REG    (1U)
/* @brief ACMP Function Clock Selection */
#define FEATURE_ACMP_HAS_CLK_SRC_SEL                    (0U)
/* @brief ACMP has filter bypass control */
#define FEATURE_ACMP_HAS_FILTER_BYPASS                  (1U)
/* @brief ACMP filter clock source is in the CTRL register */
#define FEATURE_ACMP_HAS_FILTER_CLK_SRC_IN_CTRL_REG     (1U)
/* @brief ACMP positive/negative input source selected in MUX register */
#define FEATURE_ACMP_HAS_INPUT_SRC_SEL_IN_MUX_REG       (1U)
/* @brief ACMP DAC reference voltage selection */
#define FEATURE_ACMP_HAS_DAC_VOLTAGE_REF_SRC            (0U)
/* @brief ACMP DAC output enable */
#define FEATURE_ACMP_HAS_DAC_OUTPUT                     (1U)
/* @brief ACMP Auto disable hard block */
#define FEATURE_ACMP_HAS_AUTODIS                        (0U)
/* @brief ACMP comparator offset control */
#define FEATURE_ACMP_HAS_OFFSET_CONTROL                 (0U)
/* @brief ACMP support sxosc clock */
#define FEATURE_ACMP_SUPPORT_SXOSC_CLK                  (0U)
/* @brief ACMP has EXP register */
#define FEATURE_ACMP_HAS_EXP_REG                        (1U)
/* @brief ACMP has trigger mode gate */
#define FEATURE_ACMP_HAS_TRIG_MODE_GATE                 (1U)
/* @brief ACMP supports high/low level detection */
#define FEATURE_ACMP_SUPPORT_LEVEL_DETECTION            (1U)

#define FEATURE_ACMP_CTRL_RESET_VALUE                   (0x00000000)
#define FEATURE_ACMP_STS_CLEAR_MASK                     (0x00FF0000)
#define FEATURE_ACMP_STS_CH_OUT_MASK                    (0xFF000000)
#define FEATURE_ACMP_STS_CH_OUT_SHIFT                   (24)
#define FEATURE_ACMP_STS_CH_FLAG_MASK                   (0x00FF0000)
#define FEATURE_ACMP_STS_CH_FLAG_SHIFT                  (16)
#define FEATURE_ACMP_DEFAULT_CONT_PERIOD                (0x30)
#define FEATURE_ACMP_DEFAULT_CONT_POS                   (0x18)

#if FEATURE_ACMP_HAS_DAC
/* @brief Comparator fix DAC input to mux side */
#define FEATURE_ACMP_DAC_FIX_SELECTION                  (0U)
#define ACMP_DAC_RESOLUTION                             (255U)
#endif /* FEATURE_ACMP_HAS_DAC */

/* IPC module features */
/* @brief IPC support FAST BUS clock */
#define FEATURE_IPC_SUPPORT_FAST_BUS_CLK                (1)

/*! @brief Clock names. */
typedef enum
{
    /* IPC clocks */
    DMA_CLK                  =  0U, /*!< DMA        clock source */
    GPIO_CLK                 =  1U, /*!< GPIO       clock source */
    PCTRLA_CLK               =  2U, /*!< PCTRLA     clock source */
    PCTRLB_CLK               =  3U, /*!< PCTRLB     clock source */
    PCTRLC_CLK               =  4U, /*!< PCTRLC     clock source */
    PCTRLD_CLK               =  5U, /*!< PCTRLD     clock source */
    PCTRLE_CLK               =  6U, /*!< PCTRLE     clock source */
    UART0_CLK                =  7U, /*!< UART0      clock source */
    UART1_CLK                =  8U, /*!< UART1      clock source */
    UART2_CLK                =  9U, /*!< UART2      clock source */
    I2C0_CLK                 = 10U, /*!< I2C0       clock source */
    I2C1_CLK                 = 11U, /*!< I2C1       clock source */
    SPI0_CLK                 = 12U, /*!< SPI0       clock source */
    SPI1_CLK                 = 13U, /*!< SPI1       clock source */
    SPI2_CLK                 = 14U, /*!< SPI2       clock source */
    FlexCAN0_CLK             = 15U, /*!< FlexCAN0   clock source */
    FlexCAN1_CLK             = 16U, /*!< FlexCAN1   clock source */
    FlexCAN2_CLK             = 17U, /*!< FlexCAN2   clock source */
    eADC0_CLK                = 18U, /*!< eADC0      clock source */
    ACMP0_CLK                = 19U, /*!< ACMP0      clock source */
    TMU_CLK                  = 20U, /*!< TMU        clock source */
    eTMR0_CLK                = 21U, /*!< eTMR0      clock source */
    eTMR1_CLK                = 22U, /*!< eTMR1      clock source */
    MPWM0_CLK                = 23U, /*!< MPWM0      clock source */
    pTMR0_CLK                = 24U, /*!< pTMR0      clock source */
    lpTMR0_CLK               = 25U, /*!< lpTMR0     clock source */
    RTC_CLK                  = 26U, /*!< RTC        clock source */
    CRC_CLK                  = 27U, /*!< CRC        clock source */
    TRNG_CLK                 = 28U, /*!< TRNG       clock source */
    HCU_CLK                  = 29U, /*!< HCU        clock source */
    WDG0_CLK                 = 30U, /*!< WDG0       clock source */
    EWDG0_CLK                = 31U, /*!< EWDG0      clock source */
    EMU0_CLK                 = 32U, /*!< EMU0       clock source */
    CMU_CLK                  = 33U, /*!< CMU        clock source */
    CFMU_CLK                 = 34U, /*!< CFMU       clock source */
    CIM_CLK                  = 35U, /*!< CIM        clock source */
    SCU_CLK                  = 36U, /*!< SCU        clock source */

    IPC_PERI_END_OF_CLOCK    = 37U, /*!< IPC_PERI_END_OF_CLOCK */
    IPC_SIRC_CLK             = 38U, /*!< IPC_SIRC   clock source */
    IPC_FIRC_CLK             = 39U, /*!< IPC_FIRC   clock source */
    IPC_FXOSC_CLK            = 40U, /*!< IPC_FXOSC  clock source */
    IPC_SXOSC_CLK            = 41U, /*!< IPC_SXOSC  clock source */
    IPC_PLL_CLK              = 42U, /*!< IPC_PLL    clock source */
    IPC_LPO_CLK              = 43U, /*!< IPC_LPO    clock source */

    IPC_END_OF_CLOCK         = 44U, /*!< IPC_END_OF_CLOCK */
    CORE_CLK                 = 45U, /*!< CORE       clock source */
    FAST_BUS_CLK             = 46U, /*!< FAST_BUS   clock source */
    SLOW_BUS_CLK             = 47U, /*!< SLOW_BUS   clock source */

    CLOCK_NAME_COUNT         = 48U, /*!< CLOCK_NAME_COUNT */
} clock_names_t;

/*! @brief SCU(CFMU) clock output selection */
typedef enum
{
    SCU_CLKOUT_SEL_DISABLE      = 0U,     /*!< SCU CLKOUT Disable               */
    SCU_CLKOUT_SEL_FIRC_CLK     = 1U,     /*!< SCU CLKOUT Select FIRC CLK       */
    SCU_CLKOUT_SEL_SIRC_CLK     = 2U,     /*!< SCU CLKOUT Select SIRC CLK       */
    SCU_CLKOUT_SEL_FXOSC_CLK    = 3U,     /*!< SCU CLKOUT Select FXOSC CLK      */
    SCU_CLKOUT_SEL_PLL_CLK      = 4U,     /*!< SCU CLKOUT Select PLL CLK        */
    SCU_CLKOUT_SEL_LPO_CLK      = 5U,     /*!< SCU CLKOUT Select LPO CLK        */
    SCU_CLKOUT_SEL_TRNG_CLK     = 6U,     /*!< SCU CLKOUT Select TRNG OSC CLK   */
    SCU_CLKOUT_SEL_CORE_CLK     = 7U,     /*!< SCU CLKOUT Select CORE CLK       */
} scu_clkout_src_t;

/*! @brief IPC clock name mappings
 *  Mappings between clock names and peripheral clock control indexes.
 *  If there is no peripheral clock control index for a clock name,
 *  then the corresponding value is IPC_INVALID_INDEX.
 */
#define IPC_GPIO_INDEX         ( 17U)
#define IPC_PCTRLA_INDEX       ( 18U)
#define IPC_PCTRLB_INDEX       ( 19U)
#define IPC_PCTRLC_INDEX       ( 20U)
#define IPC_PCTRLD_INDEX       ( 21U)
#define IPC_PCTRLE_INDEX       ( 22U)
#define IPC_UART0_INDEX        ( 27U)
#define IPC_UART1_INDEX        ( 28U)
#define IPC_UART2_INDEX        ( 29U)
#define IPC_I2C0_INDEX         ( 35U)
#define IPC_I2C1_INDEX         ( 36U)
#define IPC_SPI0_INDEX         ( 42U)
#define IPC_SPI1_INDEX         ( 43U)
#define IPC_SPI2_INDEX         ( 44U)
#define IPC_FlexCAN0_INDEX     ( 48U)
#define IPC_FlexCAN1_INDEX     ( 52U)
#define IPC_FlexCAN2_INDEX     ( 56U)
#define IPC_eADC0_INDEX        ( 64U)
#define IPC_ACMP0_INDEX        ( 67U)
#define IPC_TMU_INDEX          ( 72U)
#define IPC_eTMR0_INDEX        ( 73U)
#define IPC_eTMR1_INDEX        ( 74U)
#define IPC_MPWM0_INDEX        ( 79U)
#define IPC_pTMR0_INDEX        ( 90U)
#define IPC_lpTMR0_INDEX       ( 93U)
#define IPC_RTC_INDEX          ( 96U)
#define IPC_CRC_INDEX          (101U)
#define IPC_TRNG_INDEX         (102U)
#define IPC_HCU_INDEX          (103U)
#define IPC_WDG0_INDEX         (106U)
#define IPC_EWDG0_INDEX        (107U)
#define IPC_EMU0_INDEX         (114U)
#define IPC_CMU_INDEX          (118U)
#define IPC_CFMU_INDEX         (119U)
#define IPC_CIM_INDEX          (123U)
#define IPC_SCU_INDEX          (124U)
#define IPC_IPC_PERI_END_OF_CLOCK_INDEX   (125U)
#define IPC_IPC_SIRC_INDEX     (126U)
#define IPC_IPC_FIRC_INDEX     (127U)
#define IPC_IPC_FXOSC_INDEX    (128U)
#define IPC_IPC_SXOSC_INDEX    (129U)
#define IPC_IPC_PLL_INDEX      (130U)
#define IPC_IPC_LPO_INDEX      (131U)
#define IPC_IPC_END_OF_CLOCK_INDEX   (132U)
#define IPC_CORE_INDEX         (133U)
#define IPC_FAST_BUS_INDEX     (134U)
#define IPC_SLOW_BUS_INDEX     (135U)
#define IPC_CLOCK_NAME_COUNT_INDEX   (136U)

#define  IPC_CLOCK_NAME_MAPPINGS \
{                                \
    IPC_GPIO_INDEX,           /*!< GPIO       clock source   17u */ \
    IPC_PCTRLA_INDEX,         /*!< PCTRLA     clock source   18u */ \
    IPC_PCTRLB_INDEX,         /*!< PCTRLB     clock source   19u */ \
    IPC_PCTRLC_INDEX,         /*!< PCTRLC     clock source   20u */ \
    IPC_PCTRLD_INDEX,         /*!< PCTRLD     clock source   21u */ \
    IPC_PCTRLE_INDEX,         /*!< PCTRLE     clock source   22u */ \
    IPC_UART0_INDEX,          /*!< UART0      clock source   27u */ \
    IPC_UART1_INDEX,          /*!< UART1      clock source   28u */ \
    IPC_UART2_INDEX,          /*!< UART2      clock source   29u */ \
    IPC_I2C0_INDEX,           /*!< I2C0       clock source   35u */ \
    IPC_I2C1_INDEX,           /*!< I2C1       clock source   36u */ \
    IPC_SPI0_INDEX,           /*!< SPI0       clock source   42u */ \
    IPC_SPI1_INDEX,           /*!< SPI1       clock source   43u */ \
    IPC_SPI2_INDEX,           /*!< SPI2       clock source   44u */ \
    IPC_FlexCAN0_INDEX,       /*!< FlexCAN0   clock source   48u */ \
    IPC_FlexCAN1_INDEX,       /*!< FlexCAN1   clock source   52u */ \
    IPC_FlexCAN2_INDEX,       /*!< FlexCAN2   clock source   56u */ \
    IPC_eADC0_INDEX,          /*!< eADC0      clock source   64u */ \
    IPC_ACMP0_INDEX,          /*!< ACMP0      clock source   67u */ \
    IPC_TMU_INDEX,            /*!< TMU        clock source   72u */ \
    IPC_eTMR0_INDEX,          /*!< eTMR0      clock source   73u */ \
    IPC_eTMR1_INDEX,          /*!< eTMR1      clock source   74u */ \
    IPC_MPWM0_INDEX,          /*!< MPWM0      clock source   79u */ \
    IPC_pTMR0_INDEX,          /*!< pTMR0      clock source   90u */ \
    IPC_lpTMR0_INDEX,         /*!< lpTMR0     clock source   93u */ \
    IPC_RTC_INDEX,            /*!< RTC        clock source   96u */ \
    IPC_CRC_INDEX,            /*!< CRC        clock source  101u */ \
    IPC_TRNG_INDEX,           /*!< TRNG       clock source  102u */ \
    IPC_HCU_INDEX,            /*!< HCU        clock source  103u */ \
    IPC_WDG0_INDEX,           /*!< WDG0       clock source  106u */ \
    IPC_EWDG0_INDEX,          /*!< EWDG0      clock source  107u */ \
    IPC_EMU0_INDEX,           /*!< EMU0       clock source  114u */ \
    IPC_CMU_INDEX,            /*!< CMU        clock source  118u */ \
    IPC_CFMU_INDEX,           /*!< CFMU       clock source  119u */ \
    IPC_CIM_INDEX,            /*!< CIM        clock source  123u */ \
    IPC_SCU_INDEX,            /*!< SCU        clock source  124u */ \
    IPC_IPC_PERI_END_OF_CLOCK_INDEX,     /*!< IPC_PERI_END_OF_CLOCK clock source  125u */ \
    IPC_IPC_SIRC_INDEX,       /*!< IPC_SIRC   clock source  126u */ \
    IPC_IPC_FIRC_INDEX,       /*!< IPC_FIRC   clock source  127u */ \
    IPC_IPC_FXOSC_INDEX,      /*!< IPC_FXOSC  clock source  128u */ \
    IPC_IPC_SXOSC_INDEX,      /*!< IPC_SXOSC  clock source  129u */ \
    IPC_IPC_PLL_INDEX,        /*!< IPC_PLL    clock source  130u */ \
    IPC_IPC_LPO_INDEX,        /*!< IPC_LPO    clock source  131u */ \
    IPC_IPC_END_OF_CLOCK_INDEX,     /*!< IPC_END_OF_CLOCK clock source  132u */ \
    IPC_CORE_INDEX,           /*!< CORE       clock source  133u */ \
    IPC_FAST_BUS_INDEX,       /*!< FAST_BUS   clock source  134u */ \
    IPC_SLOW_BUS_INDEX,       /*!< SLOW_BUS   clock source  135u */ \
}
/*! @brief IPC clock source select
 *  Implements peripheral_clock_source_t_Class
 */
typedef enum
{
    CLK_SRC_DISABLED        = 0x00U,            /*!< Disabled clock */
    CLK_SRC_FIRC            = 0x01U,            /*!< Fast IRC Clock */
    CLK_SRC_SIRC            = 0x02U,            /*!< Slow IRC Clock */
    CLK_SRC_FXOSC           = 0x03U,            /*!< External Fast OSC Clock */
    CLK_SRC_LPO             = 0x04U,            /*!< Internal LPO Clock */
    CLK_SRC_PLL             = 0x05U,            /*!< PLL Clock */
    CLK_SRC_FAST_BUS        = 0x07U,            /*!< Internal Fast Bus Clock */
} peripheral_clock_source_t;

/* SPI module features */
/* @brief Initial value for state structure */
#define FEATURE_SPI_STATE_STRUCTURES_NULL {NULL, NULL, NULL}
/* @brief Has transmitter/receiver DMA enable bits. */
#define FEATURE_SPI_HAS_DMA_ENABLE (1)
/* @brief Clock indexes for SPI clock */
#define FEATURE_SPI_CLOCKS_NAMES {SPI0_CLK, SPI1_CLK, SPI2_CLK}

/* eADC module features */

/*! @brief eADC WDG Channel count */
#define FEATURE_EADC_WDG_CHANNEL_COUNT                     (2U)

#define EADC_CLOCKS                                        {eADC0_CLK}

/*! @brief EADC default clock divider from RM */
#define EADC_DEFAULT_CLOCK_DIVIDER                         (0x00U)
/*! @brief EADC default Sample Time from RM */
#define EADC_DEFAULT_SAMPLE_TIME                           (0x02U)
/*! @brief EADC default Start Time from RM */
#define EADC_DEFAULT_START_TIME                            (0xC0U)
/* @brief Max of eadc clock frequency */
#define EADC_CLOCK_FREQ_MAX_RUNTIME                        (32000000u)
/* @brief Min of eadc clock frequency */
#define EADC_CLOCK_FREQ_MIN_RUNTIME                        (2000000u)
/* @brief Max of eADC convert channels */
#define FEATURE_eADC_MAX_NUM_EXT_CHANS                     (36U)

/* CAN module features */

/* @brief Frames available in Rx FIFO flag shift */
#define FEATURE_CAN_RXFIFO_FRAME_AVAILABLE  (5U)
/* @brief Rx FIFO warning flag shift */
#define FEATURE_CAN_RXFIFO_WARNING          (6U)
/* @brief Rx FIFO overflow flag shift */
#define FEATURE_CAN_RXFIFO_OVERFLOW         (7U)
/* @brief The list contains definitions of the FD feature support on all instances */
#define FEATURE_CAN_INSTANCES_HAS_FD        {true, true, true}

/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN0 */
#define FEATURE_CAN0_MAX_MB_NUM             (64U)
/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN1 */
#define FEATURE_CAN1_MAX_MB_NUM             (64U)
/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN2 */
#define FEATURE_CAN2_MAX_MB_NUM             (32U)
/* @brief Maximum number of Message Buffers supported for payload size 8 for CAN3 */

/* @brief Has PE clock source select (bit field CAN_CTRL1[CLKSRC]). */
#define FEATURE_CAN_HAS_PE_CLKSRC_SELECT    (1)
/* @brief Has DMA enable (bit field MCR[DMA]). */
#define FEATURE_CAN_HAS_DMA_ENABLE          (1)

/* @brief Maximum number of Message Buffers supported for payload size 8 for any of the CAN instances */
#define FEATURE_CAN_MAX_MB_NUM              (64U)
/* @brief Maximum number of Message Buffers supported for payload size 8 for any of the CAN instances */
#define FEATURE_CAN_MAX_MB_NUM_ARRAY        { FEATURE_CAN0_MAX_MB_NUM, \
                                              FEATURE_CAN1_MAX_MB_NUM, \
                                              FEATURE_CAN2_MAX_MB_NUM }
/* @brief Has Pretending Networking mode */
#define FEATURE_CAN_HAS_PRETENDED_NETWORKING    (0)
/* @brief Has Stuff Bit Count Enable Bit */
#define FEATURE_CAN_HAS_STFCNTEN_ENABLE         (0)
/* @brief Has ISO CAN FD Enable Bit */
#define FEATURE_CAN_HAS_ISOCANFDEN_ENABLE       (1)
/* @brief Has Message Buffer Data Size Region 1 */
#define FEATURE_CAN_HAS_MBDSR1                  (1)
/* @brief Has Message Buffer Data Size Region 2 */
#define FEATURE_CAN_HAS_MBDSR2                  (0)
/* @brief DMA hardware requests for all FlexCAN instances */
#define FEATURE_CAN_DMA_REQUESTS              { DMA_REQ_FLEXCAN0, \
                                                DMA_REQ_FLEXCAN1, \
                                                DMA_REQ_FLEXCAN2}

/* @brief Maximum number of Message Buffers IRQs */
#define FEATURE_CAN_MB_IRQS_MAX_COUNT       (4U)
/* @brief Message Buffers IRQs */
#define FEATURE_CAN_MB_IRQS                 { CAN_ORed_0_15_MB_IRQS, CAN_ORed_16_31_MB_IRQS, CAN_ORed_32_47_MB_IRQS, CAN_ORed_48_63_MB_IRQS }
/* @brief Has Wake Up Irq channels (CAN_Wake_Up_IRQS_CH_COUNT > 0u) */
#define FEATURE_CAN_HAS_WAKE_UP_IRQ         (1)
/* @brief Has Self Wake Up mode */
#define FEATURE_CAN_HAS_SELF_WAKE_UP        (1)
/* @brief Has Flexible Data Rate */
#define FEATURE_CAN_HAS_FD                  (1)
/* @brief Has RAM ECC */
#define FEATURE_CAN_HAS_RAM_ECC             (0)
/* @brief Clock name for the PE oscillator clock source */
#define FEATURE_CAN_PE_OSC_CLK_NAME         IPC_FXOSC_CLK
/* @bried FlexCAN has Detection And Correction of Memory Errors */
#define FEATURE_CAN_HAS_MEM_ERR_DET         (1)

#define FEATURE_CAN_RAM_COUNT               (256)
#define FEATURE_CAN_RXIMR_COUNT             (64)
/* @brief Has enhanced rx fifo feature for CAN0 */
#define FEATURE_CAN0_HAS_ENHANCE_RX_FIFO (1)
/* @brief Has enhanced rx fifo feature for CAN1 */
#define FEATURE_CAN1_HAS_ENHANCE_RX_FIFO (0)
/* @brief Has enhanced rx fifo feature for CAN2 */
#define FEATURE_CAN2_HAS_ENHANCE_RX_FIFO (0)

/* @brief Has enhanced rx fifo feature for all CAN */
#define FEATURE_CAN_HAS_ENHANCE_RX_FIFO  (1)

/* @brief The list contains definitions of the rx-fifo feature support on all instances */
#define FEATURE_CAN_INSTANCES_HAS_ENHANCE_RX_FIFO        { FEATURE_CAN0_HAS_ENHANCE_RX_FIFO, \
                                                           FEATURE_CAN1_HAS_ENHANCE_RX_FIFO, \
                                                           FEATURE_CAN2_HAS_ENHANCE_RX_FIFO }
#define FEATURE_CAN_ENHANCE_RX_FIFO_COUNT (20U)

/* @brief Enhance fifo message buffer count */
#define FEATURE_CAN_ERFFELn_COUNT (128U)

/* @brief High-resolution time stamp feature for CAN0 */
#define FEATURE_CAN0_HAS_HR_TIMESTAMP (0)
/* @brief High-resolution time stamp feature for CAN1 */
#define FEATURE_CAN1_HAS_HR_TIMESTAMP (0)
/* @brief High-resolution time stamp feature for CAN2 */
#define FEATURE_CAN2_HAS_HR_TIMESTAMP (0)
/* @brief High-resolution time stamp feature for all CAN */
#define FEATURE_CAN_HAS_HR_TIMESTAMP (0)
/* @brief The list contains definitions of the High-resolution time stamp feature support on all instances */
#define FEATURE_CAN_INSTANCES_HAS_HR_TIMESTAMP           { FEATURE_CAN0_HAS_HR_TIMESTAMP, \
                                                           FEATURE_CAN1_HAS_HR_TIMESTAMP, \
                                                           FEATURE_CAN2_HAS_HR_TIMESTAMP}

/* pTMR module features */

/* @brief Clock names for pTMR */
#define pTMR_CLOCK_NAMES                                {FAST_BUS_CLK}
/* @brief IPC Clock names for pTMR */
#define pTMR_IPC_CLOCK_NAMES                            {pTMR0_CLK}
/* @brief pTMR support function clock */
#define FEATURE_pTMR_HAS_IPC_CLOCK_SOURCE               (1U)

/* @brief pTMR instance list */
typedef enum
{
    pTMR0_INST = 0,
} ptmr_instance_t;

/* @brief pTMR channels list for each instance */
typedef enum
{
    pTMR0_CH0 = 0U,
    pTMR0_CH1 = 1U,
    pTMR0_CH2 = 2U,
    pTMR0_CH3 = 3U,
} ptmr_channel_t;

/* TMR module features */
#define TMR_CLOCK_NAMES {SLOW_BUS_CLK}

/* lpTMR module features */

/* @brief lpTMR pulse counter input options */
#define FEATURE_LPTMR_HAS_INPUT_ALT1_SELECTION  (1U)
/* @brief Clock names for lpTMR. */
#define lpTMR_CLOCK_NAMES {lpTMR0_CLK }
/* @brief alt1 input for lpTMR. */
#define FEATURE_lpTMR_HAS_INPUT_ALT1_SELECTION  (1U)
/* @brief lpTMR ip clock selection */
#define FEATURE_lpTMR_HAS_CLOCK_SELECTION       (1U)
/* @brief lpTMR clock source support ipc */
#define FEATURE_lpTMR_CLKSRC_SUPPORT_IPC        (0U)
/* @brief lpTMR clock source support firc */
#define FEATURE_lpTMR_CLKSRC_SUPPORT_FIRC       (1U)
/* @brief lpTMR clock source support sxosc */
#define FEATURE_lpTMR_CLKSRC_SUPPORT_FXOSC      (1U)
/* @brief lpTMR clock source support lpo */
#define FEATURE_lpTMR_CLKSRC_SUPPORT_LPO        (1U)
/* @brief lpTMR clock source support sirc */
#define FEATURE_lpTMR_CLKSRC_SUPPORT_SIRC       (1U)

/* RTC module features */

/*!
 * @brief RTC clock select
 * Implements : rtc_clk_source_t_Class
 */
typedef enum
{
    RTC_CLK_SRC_BUS = 0x00U, /*!< RTC Prescaler increments using bus clock */
    RTC_CLK_SRC_RTC_PIN = 0x01U,   /*!< RTC Prescaler increments from RTC pin */
    RTC_CLK_SRC_SIRC = 0x02U,   /*!< RTC Prescaler increments from SIRC clock */
    RTC_CLK_SRC_IPC = 0x03U,   /*!< RTC Prescaler increments from IPC function clock */
} rtc_clk_source_t;
/* @brief RTC has separate second irq */
#define FEATURE_RTC_HAS_SEPARATE_SECOND_IRQ     (1U)
/* @brief RTC has 32.768 OSC clock support */
#define FEATURE_RTC_HAS_OSC                     (1U)

/* UART module features */

/* @brief One wire mode is supported. */
#define FEATURE_UART_HAS_ONE_WIRE_MODE_SUPPORT (1)
/* @brief Hardware flow control (RTS, CTS) is supported. */
#define FEATURE_UART_HAS_MODEM_SUPPORT (1)
/* @brief Baud rate oversampling is available. */
#define FEATURE_UART_HAS_BAUD_RATE_OVER_SAMPLING_SUPPORT (1)
/* @brief Baud rate oversampling is available. */
#define FEATURE_UART_HAS_BOTH_EDGE_SAMPLING_SUPPORT (1)
/* @brief Capacity (number of entries) of the transmit/receive FIFO (or zero if no FIFO is available). */
#define FEATURE_UART_FIFO_SIZE (4U)
/* @brief Supports two match addresses to filter incoming frames. */
#define FEATURE_UART_HAS_ADDRESS_MATCHING (1)
/* @brief Has transmitter/receiver DMA enable bits. */
#define FEATURE_UART_HAS_DMA_ENABLE (1)
/* @brief Flag clearance mask for STAT register. */
#define FEATURE_UART_INTF_REG_FLAGS_MASK (0x0000CEFF)
/* @brief Flag clearance mask for FIFO register. */
#define FEATURE_UART_FIFO_REG_FLAGS_MASK (0x00030000U)
/* @brief Reset mask for FIFO register. */
#define FEATURE_UART_FIFO_RESET_MASK (0x00008000U)
/* @brief Default oversampling ratio. */
#define FEATURE_UART_DEFAULT_OSR (0x0FUL)
/* @brief Default baud rate divisor. */
#define FEATURE_UART_DEFAULT_DIV (0x04UL)
/* @brief Clock names for UART. */
#define UART_CLOCK_NAMES                \
    {                                   \
        UART0_CLK, UART1_CLK, UART2_CLK \
    }
/* @brief IPC index for UART module */
#define UART_IPC_INDEX                                      \
    {                                                       \
        IPC_UART0_INDEX, IPC_UART1_INDEX, IPC_UART2_INDEX   \
    }

/* HCU module features */
#define FEATURE_HCU_AES_ENGINE                           (1U)
#define FEATURE_HCU_SM4_ENGINE                           (0U)
#define FEATURE_HCU_SHA_ENGINE                           (1U)
#define FEATURE_HCU_ONE_LOOP_DATA_SIZE                   (16U)
#define FEATURE_HCU_ONE_LOOP_INPUT_WATERMARK             (4U)
#define FEATURE_HCU_HAS_FIXED_DMA                        (1U)
#define FEATURE_HCU_HAS_SHA_AUTHORIZE                    (1U)
#define FEATURE_HCU_AES_CTR_ENGINE                       (0U)
#define FEATURE_HCU_AES_CCM_ENGINE                       (0U)
#define FEATURE_HCU_HMAC_ENGINE                          (0U)
#define FEATURE_HCU_PKE_ENGINE                           (1U)
#define FEATURE_HCU_ECC_ENGINE                           (1U)
#define FEATURE_HCU_RSA_ENGINE                           (1U)

/* @brief ECC Max words length support */
#define FEATURE_HCU_ECC_MAX_WORD_LENGTH                  (32U)

/* @brief RSA Max words length support */
#define FEATURE_HCU_RSA_MAX_WORD_LENGTH                  (128U)
/* @brief HCU has hardware key load */
#define FEATURE_RSA_HAS_HARDWARE_KEY_LOAD                (1U)

/* @brief Reduce HCU area */
#define FEATURE_HCU_HAS_AREA_REDUCTION                   (1U)
/* @brief HCU key size fixed */
#define FEATURE_HCU_KEY_SIZE_UNFIXED                     (0U)

#define FEATURE_HCU_FIFO_SIZE_IN_WORDS                   (8U)

/* @brief MAC length in bit */
#define FEATURE_HCU_MAC_LEN_IN_BIT                       (1U)

/* @brief EFM AES area base address */
#define FEATURE_EFM_AES_KEY_BASE_ADDR                    (0x11001A00U)
/* @brief EFM AES key size (bytes)*/
#define FEATURE_EFM_AES_KEY_SIZE                         (16U)
#define FEATURE_EFM_AES_KEY_COUNT_MAX                    (64U)
#define FEATURE_HCU_GET_KEY_ADDR(key_id)                 (FEATURE_EFM_AES_KEY_BASE_ADDR + ((key_id) * FEATURE_EFM_AES_KEY_SIZE))
/* @brief EFM AES area base address */
#define FEATURE_EFM_RSA_KEY_BASE_ADDR                    (0x11001200U)
/* @brief EFM RSA key size (bytes)*/
#define FEATURE_EFM_RSA_KEY_SIZE                         (512U)
#define FEATURE_RSA_GET_KEY_ADDR(key_id)                 (FEATURE_EFM_RSA_KEY_BASE_ADDR + ((key_id) * FEATURE_EFM_RSA_KEY_SIZE))

/* @brief EFM RSA key size (bytes)*/
#define FEATURE_EFM_RSA_KEY_COUNT_MAX                    (4U)

/* TRNG module features */

/* @brief Entropy Value count optimize */
#define FEATURE_TRNG_ENTROPY_COUNT_OPTIMIZE         (1U)

/* OSIF module features */

#define FEATURE_OSIF_USE_SYSTICK                         (1)
#define FEATURE_OSIF_FREERTOS_ISR_CONTEXT_METHOD         (1) /* Cortex M device */


/* PTU module features */

/* @brief PTU has instance back to back mode between PTU0 CH0 and PTU1 CH0 pre-triggers */
#define FEATURE_PTU_HAS_INSTANCE_BACKTOBACK     (1)

/* @brief PTU has inter-channel back to back mode between PTUx CH0 and PTUx CH1 pre-triggers */
#define FEATURE_PTU_HAS_INTERCHANNEL_BACKTOBACK (1)

/*! @brief EMU Global Enable KEY */
#define FEATURE_EMU_GLOBAL_ENABLE_KEY           (1U)


#if defined(USER_DEVICE_FEATURES_OVERRIDE)
#include "user_device_features_override.h"
#endif


#endif /* YTM32B1MD0_FEATURES_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/
