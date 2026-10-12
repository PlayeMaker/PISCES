/**
*   @file    pSIP_Scu.h
*   @version
*
*   @brief   AUTOSAR Scu register map
*   @details Register map for SCU
*
*   @addtogroup SCU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Scu
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : V0.9.1
*
*   (c) Copyright 2020-2025 Jiangsu Yuntu Microelectronics CO,. LTD.
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef PSIP_SCU_H
#define PSIP_SCU_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              SCU REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup SCU_Peripheral_Access_Layer SCU Peripheral Access Layer
 * @{
 */


/** SCU - Size of Registers Arrays */

/* SCU Register Layout Typedef */
typedef struct
{
    uint32 CLKS;                               /**< Clock Selection Register, offset: 0x0000 */
    uint32 DIV;                                /**< System Clock Divider, offset: 0x0004 */
    uint32 STS;                                /**< Status Register, offset: 0x0008 */
    uint32 DIVSTS;                             /**< Clock Divider Status Register, offset: 0x000C */
    uint32 FIRC_CTRL;                          /**< FIRC Control Register, offset: 0x0010 */
    uint32 SIRC_CTRL;                          /**< SIRC Control Register, offset: 0x0014 */
    uint32 FXOSC_CTRL;                         /**< FXOSC Control Register, offset: 0x0018 */
    uint8 RESERVED7[ 4];                      /**< RESERVED7, offset: 0x001C */
    uint32 PLL_CTRL;                           /**< PLL Control Register, offset: 0x0020 */
    uint8 RESERVED9[12];                      /**< RESERVED9, offset: 0x0024 */
    uint32 RESERVED10;                         /**< RESERVED10, offset: 0x0030 */
    uint32 RESERVED11;                         /**< RESERVED11, offset: 0x0034 */
    uint32 RESERVED12;                         /**< RESERVED12, offset: 0x0038 */
    uint8 RESERVED13[44];                     /**< RESERVED13, offset: 0x003C */
    uint32 RESERVED14;                         /**< RESERVED14, offset: 0x0068 */

} SCU_Type, *SCU_MemMapPtr;

/** Number of instances of the SCU module. */
#define SCU_INSTANCE_COUNT                        (1u)

/* SCU base address */
#define SCU_BASE_ADDR32                                   (0x4007C000U)
#define SCU                                               ((volatile SCU_Type *)(SCU_BASE_ADDR32))

/** Array initializer of SCU peripheral base addresses */
#define SCU_BASE_ADDRS                                     { SCU_BASE_ADDR32 }
/** Array initializer of SCU peripheral base pointers */
#define SCU_BASE_PTRS                                      { SCU }

#define SCU_CLKS_OFFSET32                                  (0x0000U)                    /**< Offset for Clock Selection Register */
#define SCU_DIV_OFFSET32                                   (0x0004U)                    /**< Offset for System Clock Divider */
#define SCU_STS_OFFSET32                                   (0x0008U)                    /**< Offset for Status Register */
#define SCU_DIVSTS_OFFSET32                                (0x000CU)                    /**< Offset for Clock Divider Status Register */
#define SCU_FIRC_CTRL_OFFSET32                             (0x0010U)                    /**< Offset for FIRC Control Register */
#define SCU_SIRC_CTRL_OFFSET32                             (0x0014U)                    /**< Offset for SIRC Control Register */
#define SCU_FXOSC_CTRL_OFFSET32                            (0x0018U)                    /**< Offset for FXOSC Control Register */
#define SCU_PLL_CTRL_OFFSET32                              (0x0020U)                    /**< Offset for PLL Control Register */


/**
 * @addtogroup SCU Register Mask
 * @{
 */
/* SCU_CLKS Register */
#define SCU_CLKS_CLKSRCSEL_MASK                            (0x3U)
#define SCU_CLKS_CLKSRCSEL_SHIFT                           (0U)
#define SCU_CLKS_CLKSRCSEL(x)                              (((uint32)(((uint32)(x)) << SCU_CLKS_CLKSRCSEL_SHIFT)) & SCU_CLKS_CLKSRCSEL_MASK)
/* SCU_DIV Register */
#define SCU_DIV_CPDIVS_MASK                                (0xF0000U)
#define SCU_DIV_CPDIVS_SHIFT                               (16U)
#define SCU_DIV_CPDIVS(x)                                  (((uint32)(((uint32)(x)) << SCU_DIV_CPDIVS_SHIFT)) & SCU_DIV_CPDIVS_MASK)
#define SCU_DIV_FBDIVS_MASK                                (0xF00U)
#define SCU_DIV_FBDIVS_SHIFT                               (8U)
#define SCU_DIV_FBDIVS(x)                                  (((uint32)(((uint32)(x)) << SCU_DIV_FBDIVS_SHIFT)) & SCU_DIV_FBDIVS_MASK)
#define SCU_DIV_SBDIVS_MASK                                (0xFU)
#define SCU_DIV_SBDIVS_SHIFT                               (0U)
#define SCU_DIV_SBDIVS(x)                                  (((uint32)(((uint32)(x)) << SCU_DIV_SBDIVS_SHIFT)) & SCU_DIV_SBDIVS_MASK)
/* SCU_STS Register */
#define SCU_STS_PLL_LOCK_MASK                              (0x20U)
#define SCU_STS_PLL_LOCK_SHIFT                             (5U)
#define SCU_STS_PLL_LOCK(x)                                (((uint32)(((uint32)(x)) << SCU_STS_PLL_LOCK_SHIFT)) & SCU_STS_PLL_LOCK_MASK)
#define SCU_STS_FXOSC_VALID_MASK                           (0x8U)
#define SCU_STS_FXOSC_VALID_SHIFT                          (3U)
#define SCU_STS_FXOSC_VALID(x)                             (((uint32)(((uint32)(x)) << SCU_STS_FXOSC_VALID_SHIFT)) & SCU_STS_FXOSC_VALID_MASK)
#define SCU_STS_FIRC_VALID_MASK                            (0x4U)
#define SCU_STS_FIRC_VALID_SHIFT                           (2U)
#define SCU_STS_FIRC_VALID(x)                              (((uint32)(((uint32)(x)) << SCU_STS_FIRC_VALID_SHIFT)) & SCU_STS_FIRC_VALID_MASK)
#define SCU_STS_CLKST_MASK                                 (0x3U)
#define SCU_STS_CLKST_SHIFT                                (0U)
#define SCU_STS_CLKST(x)                                   (((uint32)(((uint32)(x)) << SCU_STS_CLKST_SHIFT)) & SCU_STS_CLKST_MASK)
/* SCU_DIVSTS Register */
#define SCU_DIVSTS_CPDIVST_MASK                            (0xF0000U)
#define SCU_DIVSTS_CPDIVST_SHIFT                           (16U)
#define SCU_DIVSTS_CPDIVST(x)                              (((uint32)(((uint32)(x)) << SCU_DIVSTS_CPDIVST_SHIFT)) & SCU_DIVSTS_CPDIVST_MASK)
#define SCU_DIVSTS_FBDIVST_MASK                            (0xF00U)
#define SCU_DIVSTS_FBDIVST_SHIFT                           (8U)
#define SCU_DIVSTS_FBDIVST(x)                              (((uint32)(((uint32)(x)) << SCU_DIVSTS_FBDIVST_SHIFT)) & SCU_DIVSTS_FBDIVST_MASK)
#define SCU_DIVSTS_SBDIVST_MASK                            (0xFU)
#define SCU_DIVSTS_SBDIVST_SHIFT                           (0U)
#define SCU_DIVSTS_SBDIVST(x)                              (((uint32)(((uint32)(x)) << SCU_DIVSTS_SBDIVST_SHIFT)) & SCU_DIVSTS_SBDIVST_MASK)
/* SCU_FIRC_CTRL Register */
#define SCU_FIRC_CTRL_FIRC_DLY_EN_MASK                     (0x8U)
#define SCU_FIRC_CTRL_FIRC_DLY_EN_SHIFT                    (3U)
#define SCU_FIRC_CTRL_FIRC_DLY_EN(x)                       (((uint32)(((uint32)(x)) << SCU_FIRC_CTRL_FIRC_DLY_EN_SHIFT)) & SCU_FIRC_CTRL_FIRC_DLY_EN_MASK)
#define SCU_FIRC_CTRL_FIRC_DS_EN_MASK                      (0x2U)
#define SCU_FIRC_CTRL_FIRC_DS_EN_SHIFT                     (1U)
#define SCU_FIRC_CTRL_FIRC_DS_EN(x)                        (((uint32)(((uint32)(x)) << SCU_FIRC_CTRL_FIRC_DS_EN_SHIFT)) & SCU_FIRC_CTRL_FIRC_DS_EN_MASK)
#define SCU_FIRC_CTRL_FIRC_EN_MASK                         (0x1U)
#define SCU_FIRC_CTRL_FIRC_EN_SHIFT                        (0U)
#define SCU_FIRC_CTRL_FIRC_EN(x)                           (((uint32)(((uint32)(x)) << SCU_FIRC_CTRL_FIRC_EN_SHIFT)) & SCU_FIRC_CTRL_FIRC_EN_MASK)
/* SCU_SIRC_CTRL Register */
#define SCU_SIRC_CTRL_SIRC_STB_EN_MASK                     (0x4U)
#define SCU_SIRC_CTRL_SIRC_STB_EN_SHIFT                    (2U)
#define SCU_SIRC_CTRL_SIRC_STB_EN(x)                       (((uint32)(((uint32)(x)) << SCU_SIRC_CTRL_SIRC_STB_EN_SHIFT)) & SCU_SIRC_CTRL_SIRC_STB_EN_MASK)
#define SCU_SIRC_CTRL_SIRC_DS_EN_MASK                      (0x2U)
#define SCU_SIRC_CTRL_SIRC_DS_EN_SHIFT                     (1U)
#define SCU_SIRC_CTRL_SIRC_DS_EN(x)                        (((uint32)(((uint32)(x)) << SCU_SIRC_CTRL_SIRC_DS_EN_SHIFT)) & SCU_SIRC_CTRL_SIRC_DS_EN_MASK)
/* SCU_FXOSC_CTRL Register */
#define SCU_FXOSC_CTRL_ALCDIS_MASK                         (0x4000U)
#define SCU_FXOSC_CTRL_ALCDIS_SHIFT                        (14U)
#define SCU_FXOSC_CTRL_ALCDIS(x)                           (((uint32)(((uint32)(x)) << SCU_FXOSC_CTRL_ALCDIS_SHIFT)) & SCU_FXOSC_CTRL_ALCDIS_MASK)
#define SCU_FXOSC_CTRL_DLY_SEL_MASK                        (0x3000U)
#define SCU_FXOSC_CTRL_DLY_SEL_SHIFT                       (12U)
#define SCU_FXOSC_CTRL_DLY_SEL(x)                          (((uint32)(((uint32)(x)) << SCU_FXOSC_CTRL_DLY_SEL_SHIFT)) & SCU_FXOSC_CTRL_DLY_SEL_MASK)
#define SCU_FXOSC_CTRL_GMSEL_MASK                          (0x700U)
#define SCU_FXOSC_CTRL_GMSEL_SHIFT                         (8U)
#define SCU_FXOSC_CTRL_GMSEL(x)                            (((uint32)(((uint32)(x)) << SCU_FXOSC_CTRL_GMSEL_SHIFT)) & SCU_FXOSC_CTRL_GMSEL_MASK)
#define SCU_FXOSC_CTRL_FXOSC_MODE_MASK                     (0x8U)
#define SCU_FXOSC_CTRL_FXOSC_MODE_SHIFT                    (3U)
#define SCU_FXOSC_CTRL_FXOSC_MODE(x)                       (((uint32)(((uint32)(x)) << SCU_FXOSC_CTRL_FXOSC_MODE_SHIFT)) & SCU_FXOSC_CTRL_FXOSC_MODE_MASK)
#define SCU_FXOSC_CTRL_FXOSC_DS_EN_MASK                    (0x2U)
#define SCU_FXOSC_CTRL_FXOSC_DS_EN_SHIFT                   (1U)
#define SCU_FXOSC_CTRL_FXOSC_DS_EN(x)                      (((uint32)(((uint32)(x)) << SCU_FXOSC_CTRL_FXOSC_DS_EN_SHIFT)) & SCU_FXOSC_CTRL_FXOSC_DS_EN_MASK)
#define SCU_FXOSC_CTRL_FXOSC_EN_MASK                       (0x1U)
#define SCU_FXOSC_CTRL_FXOSC_EN_SHIFT                      (0U)
#define SCU_FXOSC_CTRL_FXOSC_EN(x)                         (((uint32)(((uint32)(x)) << SCU_FXOSC_CTRL_FXOSC_EN_SHIFT)) & SCU_FXOSC_CTRL_FXOSC_EN_MASK)
/* SCU_PLL_CTRL Register */
#define SCU_PLL_CTRL_FBDIV_MASK                            (0x3F0000U)
#define SCU_PLL_CTRL_FBDIV_SHIFT                           (16U)
#define SCU_PLL_CTRL_FBDIV(x)                              (((uint32)(((uint32)(x)) << SCU_PLL_CTRL_FBDIV_SHIFT)) & SCU_PLL_CTRL_FBDIV_MASK)
#define SCU_PLL_CTRL_REFDIV_MASK                           (0xF00U)
#define SCU_PLL_CTRL_REFDIV_SHIFT                          (8U)
#define SCU_PLL_CTRL_REFDIV(x)                             (((uint32)(((uint32)(x)) << SCU_PLL_CTRL_REFDIV_SHIFT)) & SCU_PLL_CTRL_REFDIV_MASK)
#define SCU_PLL_CTRL_REFCLKSRCSEL_MASK                     (0x10U)
#define SCU_PLL_CTRL_REFCLKSRCSEL_SHIFT                    (4U)
#define SCU_PLL_CTRL_REFCLKSRCSEL(x)                       (((uint32)(((uint32)(x)) << SCU_PLL_CTRL_REFCLKSRCSEL_SHIFT)) & SCU_PLL_CTRL_REFCLKSRCSEL_MASK)
#define SCU_PLL_CTRL_PLL_DS_EN_MASK                        (0x2U)
#define SCU_PLL_CTRL_PLL_DS_EN_SHIFT                       (1U)
#define SCU_PLL_CTRL_PLL_DS_EN(x)                          (((uint32)(((uint32)(x)) << SCU_PLL_CTRL_PLL_DS_EN_SHIFT)) & SCU_PLL_CTRL_PLL_DS_EN_MASK)
#define SCU_PLL_CTRL_PLL_EN_MASK                           (0x1U)
#define SCU_PLL_CTRL_PLL_EN_SHIFT                          (0U)
#define SCU_PLL_CTRL_PLL_EN(x)                             (((uint32)(((uint32)(x)) << SCU_PLL_CTRL_PLL_EN_SHIFT)) & SCU_PLL_CTRL_PLL_EN_MASK)


/**
 * @}
 */ /* end of group SCU_Register_Masks */


/**
 * @}
 */ /* end of group SCU_Peripheral_Access_Layer */

#endif /* PSIP_SCU_H */
