/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file CddDma_Cfg.h
 * @brief 
 * 
 */


#ifndef CDDDMA_CFG_H
#define CDDDMA_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "CddDma_PBcfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDDDMA_VENDOR_ID_CFG                      (180)
#define CDDDMA_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define CDDDMA_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define CDDDMA_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define CDDDMA_SW_MAJOR_VERSION_CFG               (0)
#define CDDDMA_SW_MINOR_VERSION_CFG               (9)
#define CDDDMA_SW_PATCH_VERSION_CFG               (1)

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*!
 * @brief Structure for the DMA hardware request
 *
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request into DMAMUX to trigger the DMA transfer accordingly. The index
 * of the hardware request varies according  to the to SoC.
 */
typedef enum {
    DMA_REQ_DISABLED         =   0U,     /*!< Disabled         dma request    0u */
    DMA_REQ_UART0_RX         =   2U,     /*!< UART0_RX         dma request    2u */
    DMA_REQ_UART0_TX         =   3U,     /*!< UART0_TX         dma request    3u */
    DMA_REQ_UART1_RX         =   4U,     /*!< UART1_RX         dma request    4u */
    DMA_REQ_UART1_TX         =   5U,     /*!< UART1_TX         dma request    5u */
    DMA_REQ_UART2_RX         =   6U,     /*!< UART2_RX         dma request    6u */
    DMA_REQ_UART2_TX         =   7U,     /*!< UART2_TX         dma request    7u */
    DMA_REQ_I2C1_RX          =   8U,     /*!< I2C1_RX          dma request    8u */
    DMA_REQ_I2C1_TX          =   9U,     /*!< I2C1_TX          dma request    9u */
    DMA_REQ_MPWM0_CH8        =  10U,     /*!< MPWM0_CH8        dma request   10u */
    DMA_REQ_MPWM0_CH9        =  11U,     /*!< MPWM0_CH9        dma request   11u */
    DMA_REQ_MPWM0_CH10       =  12U,     /*!< MPWM0_CH10       dma request   12u */
    DMA_REQ_MPWM0_CH11       =  13U,     /*!< MPWM0_CH11       dma request   13u */
    DMA_REQ_SPI0_RX          =  14U,     /*!< SPI0_RX          dma request   14u */
    DMA_REQ_SPI0_TX          =  15U,     /*!< SPI0_TX          dma request   15u */
    DMA_REQ_SPI1_RX          =  16U,     /*!< SPI1_RX          dma request   16u */
    DMA_REQ_SPI1_TX          =  17U,     /*!< SPI1_TX          dma request   17u */
    DMA_REQ_SPI2_RX          =  18U,     /*!< SPI2_RX          dma request   18u */
    DMA_REQ_SPI2_TX          =  19U,     /*!< SPI2_TX          dma request   19u */
    DMA_REQ_eTMR1_CH0        =  20U,     /*!< eTMR1_CH0        dma request   20u */
    DMA_REQ_eTMR1_CH1        =  21U,     /*!< eTMR1_CH1        dma request   21u */
    DMA_REQ_eTMR1_CH2        =  22U,     /*!< eTMR1_CH2        dma request   22u */
    DMA_REQ_eTMR1_CH3        =  23U,     /*!< eTMR1_CH3        dma request   23u */
    DMA_REQ_eTMR1_CH4        =  24U,     /*!< eTMR1_CH4        dma request   24u */
    DMA_REQ_eTMR1_CH5        =  25U,     /*!< eTMR1_CH5        dma request   25u */
    DMA_REQ_eTMR1_CH6        =  26U,     /*!< eTMR1_CH6        dma request   26u */
    DMA_REQ_eTMR1_CH7        =  27U,     /*!< eTMR1_CH7        dma request   27u */
    DMA_REQ_MPWM0_CH0        =  28U,     /*!< MPWM0_CH0        dma request   28u */
    DMA_REQ_MPWM0_CH1        =  29U,     /*!< MPWM0_CH1        dma request   29u */
    DMA_REQ_MPWM0_CH2        =  30U,     /*!< MPWM0_CH2        dma request   30u */
    DMA_REQ_MPWM0_CH3        =  31U,     /*!< MPWM0_CH3        dma request   31u */
    DMA_REQ_MPWM0_CH4        =  32U,     /*!< MPWM0_CH4        dma request   32u */
    DMA_REQ_MPWM0_CH5        =  33U,     /*!< MPWM0_CH5        dma request   33u */
    DMA_REQ_MPWM0_CH6        =  34U,     /*!< MPWM0_CH6        dma request   34u */
    DMA_REQ_MPWM0_CH7        =  35U,     /*!< MPWM0_CH7        dma request   35u */
    DMA_REQ_eTMR0            =  36U,     /*!< eTMR0            dma request   36u */
    DMA_REQ_MPWM0_CH12       =  38U,     /*!< MPWM0_CH12       dma request   38u */
    DMA_REQ_MPWM0_CH13       =  39U,     /*!< MPWM0_CH13       dma request   39u */
    DMA_REQ_HCU_INGRESS      =  40U,     /*!< HCU_INGRESS      dma request   40u */
    DMA_REQ_HCU_EGRESS       =  41U,     /*!< HCU_EGRESS       dma request   41u */
    DMA_REQ_ADC0_HDMA        =  42U,     /*!< ADC0_HDMA        dma request   42u */
    DMA_REQ_ADC0_SDMA        =  43U,     /*!< ADC0_SDMA        dma request   43u */
    DMA_REQ_I2C0_RX          =  44U,     /*!< I2C0_RX          dma request   44u */
    DMA_REQ_I2C0_TX          =  45U,     /*!< I2C0_TX          dma request   45u */
    DMA_REQ_MPWM0_CH14       =  46U,     /*!< MPWM0_CH14       dma request   46u */
    DMA_REQ_MPWM0_CH15       =  47U,     /*!< MPWM0_CH15       dma request   47u */
    DMA_REQ_ACMP0            =  48U,     /*!< ACMP0            dma request   48u */
    DMA_REQ_GPIOA            =  49U,     /*!< GPIOA            dma request   49u */
    DMA_REQ_GPIOB            =  50U,     /*!< GPIOB            dma request   50u */
    DMA_REQ_GPIOC            =  51U,     /*!< GPIOC            dma request   51u */
    DMA_REQ_GPIOD            =  52U,     /*!< GPIOD            dma request   52u */
    DMA_REQ_GPIOE            =  53U,     /*!< GPIOE            dma request   53u */
    DMA_REQ_FLEXCAN0         =  54U,     /*!< FLEXCAN0         dma request   54u */
    DMA_REQ_FLEXCAN1         =  55U,     /*!< FLEXCAN1         dma request   55u */
    DMA_REQ_FLEXCAN2         =  56U,     /*!< FLEXCAN2         dma request   56u */
    DMA_REQ_lpTMR0           =  59U,     /*!< lpTMR0           dma request   59u */
    DMA_REQ_ALWAYS_ON_0      =  62U,     /*!< ALWAYS_ON_0      dma request   62u */
    DMA_REQ_ALWAYS_ON_1      =  63U,     /*!< ALWAYS_ON_1      dma request   63u */
} CddDma_RequestSourceType;
/*==================================================================================================
*                                       DEFINITIONS AND MACROS
==================================================================================================*/
/**
 * @brief   Maximum number of DMA channels.
 */
#define CDDDMA_MAX_CHANNEL_NUM                     (8U)

/* @brief Total enabled number of DMA channels. */
#define CDDDMA_CHANNEL_CONFIG_COUNT                (2U)

/* Logic Channel 0 */
#define DMA_LOGIC_CH_0             (0U)
/* Logic Channel 1 */
#define DMA_LOGIC_CH_1             (1U)

/**
* @brief Define precompile support.
* @details Define precompile support if VARIANT-PRE-COMPILE or VARIANT-LINK-TIME is selected and number of variant <=1.
*/
#define CDDDMA_PRECOMPILE_SUPPORT                  (STD_OFF)

#define CDDDMA_DEV_ERROR_DETECT                    (STD_ON)

#define CDDDMA_VERSION_INFO_API                    (STD_OFF)

/**
* @brief Support for SchM: sync/atomic operations, global interrupt disable/enable.
*        If this parameter has been configured to 'STD_ON', the MCAL driver code supports sync/atomic operations for key resource protection.
*        If it is enabled, all the SchM codes in MCAL CddDma driver codes will work and support sync/atomic operation with CPU global interrupt enable/disable for key resource protection. 
*        Disable it can reduce code size, but may cause potential risks when access to some critical resource!
*/
#define CDDDMA_SCHM_SUPPORT                         (STD_ON) 


#ifdef CDDDMA_ENABLE_USER_MODE_SUPPORT
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
#error "Must define MCAL_ENABLE_USER_MODE_SUPPORT if CDDDMA_ENABLE_USER_MODE_SUPPORT is defined"
#endif
#endif

#endif

