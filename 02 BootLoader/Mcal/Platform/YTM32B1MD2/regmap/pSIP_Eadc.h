/**
*   @file    pSIP_Eadc.h
*   @version
*
*   @brief   AUTOSAR Eadc register map
*   @details Register map for EADC
*
*   @addtogroup EADC_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Eadc
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

#ifndef PSIP_EADC_H
#define PSIP_EADC_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              EADC REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup eADC_Peripheral_Access_Layer eADC Peripheral Access Layer
 * @{
 */


/** eADC - Size of Registers Arrays */
#define eADC_CHSEL_COUNT           (16)
#define eADC_WDTH_COUNT           (2)
#define eADC_DATA_COUNT           (16)

/* eADC Register Layout Typedef */
typedef struct
{
    uint32 STS;                                /**< Status register, offset: 0x0000 */
    uint32 RESERVED1;                          /**< RESERVED1, offset: 0x0004 */
    uint32 OVRSTS;                             /**< Buffer Override status register, offset: 0x0008 */
    uint32 INTE;                               /**< Interrupt Enable Register, offset: 0x000C */
    uint32 CTRL;                               /**< Control Register, offset: 0x0010 */
    uint32 CFG0;                               /**< Configuration 0 Register, offset: 0x0014 */
    uint32 CFG1;                               /**< Configuration 0 Register, offset: 0x0018 */
    uint32 SMP;                                /**< Sampling Register, offset: 0x001C */
    uint8 RESERVED8[16];                      /**< RESERVED8, offset: 0x0020 */
    uint8 CHSEL[16];                          /**< Channel Configure Register, offset: 0x0030 */
    uint8 RESERVED10[16];                     /**< RESERVED10, offset: 0x0040 */
    uint32 RESERVED11;                         /**< RESERVED11, offset: 0x0050 */
    uint32 TSC;                                /**< Temperature Sensor Coefficient, offset: 0x0054 */
    uint8 RESERVED13[40];                     /**< RESERVED13, offset: 0x0058 */
    uint32 WDCTRL;                             /**< Watchdog Control Register, offset: 0x0080 */
    uint8 RESERVED15[12];                     /**< RESERVED15, offset: 0x0084 */
    uint32 WDTH[ 2];                           /**< Watchdog Threshold Register, offset: 0x0090 */
    uint8 RESERVED17[56];                     /**< RESERVED17, offset: 0x0098 */
    uint32 DATA[16];                           /**< Data Buffer Array, offset: 0x00D0 */

} eADC_Type, *eADC_MemMapPtr;

/** Number of instances of the eADC module. */
#define eADC_INSTANCE_COUNT                        (1u)

/* eADC0  base address */
#define eADC0_BASE_ADDR32                                  (0x40040000U)
#define eADC0                                              ((volatile eADC_Type *)(eADC0_BASE_ADDR32))

/** Array initializer of eADC peripheral base addresses */
#define eADC_BASE_ADDRS                                    { eADC0_BASE_ADDR32 }
/** Array initializer of eADC peripheral base pointers */
#define eADC_BASE_PTRS                                     { eADC0 }

#define eADC_STS_OFFSET32                                  (0x0000U)                    /**< Offset for Status register */
#define eADC_OVRSTS_OFFSET32                               (0x0008U)                    /**< Offset for Buffer Override status register */
#define eADC_INTE_OFFSET32                                 (0x000CU)                    /**< Offset for Interrupt Enable Register */
#define eADC_CTRL_OFFSET32                                 (0x0010U)                    /**< Offset for Control Register */
#define eADC_CFG0_OFFSET32                                 (0x0014U)                    /**< Offset for Configuration 0 Register */
#define eADC_CFG1_OFFSET32                                 (0x0018U)                    /**< Offset for Configuration 0 Register */
#define eADC_SMP_OFFSET32                                  (0x001CU)                    /**< Offset for Sampling Register */
#define eADC_CHSEL_OFFSET8(x)                             (0x0030U + ((x) * (1U)))     /**< Offset for Channel Configure Register */
#define eADC_TSC_OFFSET32                                  (0x0054U)                    /**< Offset for Temperature Sensor Coefficient */
#define eADC_WDCTRL_OFFSET32                               (0x0080U)                    /**< Offset for Watchdog Control Register */
#define eADC_WDTH_OFFSET32(x)                              (0x0090U + ((x) * (4U)))     /**< Offset for Watchdog Threshold Register */
#define eADC_DATA_OFFSET32(x)                              (0x00D0U + ((x) * (4U)))     /**< Offset for Data Buffer Array */


/**
 * @addtogroup eADC Register Mask
 * @{
 */
/* eADC_STS Register */
#define eADC_STS_WD1_MASK                                   (0x20000U)
#define eADC_STS_WD1_SHIFT                                  (17U)
#define eADC_STS_WD1(x)                                     (((uint32)(((uint32)(x)) << eADC_STS_WD1_SHIFT)) & eADC_STS_WD1_MASK)
#define eADC_STS_WD0_MASK                                   (0x10000U)
#define eADC_STS_WD0_SHIFT                                  (16U)
#define eADC_STS_WD0(x)                                     (((uint32)(((uint32)(x)) << eADC_STS_WD0_SHIFT)) & eADC_STS_WD0_MASK)
#define eADC_STS_LOWERR_MASK                                (0x40U)
#define eADC_STS_LOWERR_SHIFT                               (6U)
#define eADC_STS_LOWERR(x)                                  (((uint32)(((uint32)(x)) << eADC_STS_LOWERR_SHIFT)) & eADC_STS_LOWERR_MASK)
#define eADC_STS_LEOSEQ_MASK                                (0x20U)
#define eADC_STS_LEOSEQ_SHIFT                               (5U)
#define eADC_STS_LEOSEQ(x)                                  (((uint32)(((uint32)(x)) << eADC_STS_LEOSEQ_SHIFT)) & eADC_STS_LEOSEQ_MASK)
#define eADC_STS_HEOSEQ_MASK                                (0x10U)
#define eADC_STS_HEOSEQ_SHIFT                               (4U)
#define eADC_STS_HEOSEQ(x)                                  (((uint32)(((uint32)(x)) << eADC_STS_HEOSEQ_SHIFT)) & eADC_STS_HEOSEQ_MASK)
#define eADC_STS_NORERR_MASK                                (0x8U)
#define eADC_STS_NORERR_SHIFT                               (3U)
#define eADC_STS_NORERR(x)                                  (((uint32)(((uint32)(x)) << eADC_STS_NORERR_SHIFT)) & eADC_STS_NORERR_MASK)
#define eADC_STS_EOC_MASK                                   (0x4U)
#define eADC_STS_EOC_SHIFT                                  (2U)
#define eADC_STS_EOC(x)                                     (((uint32)(((uint32)(x)) << eADC_STS_EOC_SHIFT)) & eADC_STS_EOC_MASK)
#define eADC_STS_EOSMP_MASK                                 (0x2U)
#define eADC_STS_EOSMP_SHIFT                                (1U)
#define eADC_STS_EOSMP(x)                                   (((uint32)(((uint32)(x)) << eADC_STS_EOSMP_SHIFT)) & eADC_STS_EOSMP_MASK)
#define eADC_STS_ADRDY_MASK                                 (0x1U)
#define eADC_STS_ADRDY_SHIFT                                (0U)
#define eADC_STS_ADRDY(x)                                   (((uint32)(((uint32)(x)) << eADC_STS_ADRDY_SHIFT)) & eADC_STS_ADRDY_MASK)
/* eADC_OVRSTS Register */
#define eADC_OVRSTS_OVR15_MASK                              (0x8000U)
#define eADC_OVRSTS_OVR15_SHIFT                             (15U)
#define eADC_OVRSTS_OVR15(x)                                (((uint32)(((uint32)(x)) << eADC_OVRSTS_OVR15_SHIFT)) & eADC_OVRSTS_OVR15_MASK)
#define eADC_OVRSTS_OVR14_MASK                              (0x4000U)
#define eADC_OVRSTS_OVR14_SHIFT                             (14U)
#define eADC_OVRSTS_OVR14(x)                                (((uint32)(((uint32)(x)) << eADC_OVRSTS_OVR14_SHIFT)) & eADC_OVRSTS_OVR14_MASK)
#define eADC_OVRSTS_OVR13_MASK                              (0x2000U)
#define eADC_OVRSTS_OVR13_SHIFT                             (13U)
#define eADC_OVRSTS_OVR13(x)                                (((uint32)(((uint32)(x)) << eADC_OVRSTS_OVR13_SHIFT)) & eADC_OVRSTS_OVR13_MASK)
#define eADC_OVRSTS_OVR12_MASK                              (0x1000U)
#define eADC_OVRSTS_OVR12_SHIFT                             (12U)
#define eADC_OVRSTS_OVR12(x)                                (((uint32)(((uint32)(x)) << eADC_OVRSTS_OVR12_SHIFT)) & eADC_OVRSTS_OVR12_MASK)
#define eADC_OVRSTS_OVR11_MASK                              (0x800U)
#define eADC_OVRSTS_OVR11_SHIFT                             (11U)
#define eADC_OVRSTS_OVR11(x)                                (((uint32)(((uint32)(x)) << eADC_OVRSTS_OVR11_SHIFT)) & eADC_OVRSTS_OVR11_MASK)
#define eADC_OVRSTS_OVR10_MASK                              (0x400U)
#define eADC_OVRSTS_OVR10_SHIFT                             (10U)
#define eADC_OVRSTS_OVR10(x)                                (((uint32)(((uint32)(x)) << eADC_OVRSTS_OVR10_SHIFT)) & eADC_OVRSTS_OVR10_MASK)
#define eADC_OVRSTS_OVR9_MASK                               (0x200U)
#define eADC_OVRSTS_OVR9_SHIFT                              (9U)
#define eADC_OVRSTS_OVR9(x)                                 (((uint32)(((uint32)(x)) << eADC_OVRSTS_OVR9_SHIFT)) & eADC_OVRSTS_OVR9_MASK)
#define eADC_OVRSTS_OVR8_MASK                               (0x100U)
#define eADC_OVRSTS_OVR8_SHIFT                              (8U)
#define eADC_OVRSTS_OVR8(x)                                 (((uint32)(((uint32)(x)) << eADC_OVRSTS_OVR8_SHIFT)) & eADC_OVRSTS_OVR8_MASK)
#define eADC_OVRSTS_OVR7_MASK                               (0x80U)
#define eADC_OVRSTS_OVR7_SHIFT                              (7U)
#define eADC_OVRSTS_OVR7(x)                                 (((uint32)(((uint32)(x)) << eADC_OVRSTS_OVR7_SHIFT)) & eADC_OVRSTS_OVR7_MASK)
#define eADC_OVRSTS_OVR6_MASK                               (0x40U)
#define eADC_OVRSTS_OVR6_SHIFT                              (6U)
#define eADC_OVRSTS_OVR6(x)                                 (((uint32)(((uint32)(x)) << eADC_OVRSTS_OVR6_SHIFT)) & eADC_OVRSTS_OVR6_MASK)
#define eADC_OVRSTS_OVR5_MASK                               (0x20U)
#define eADC_OVRSTS_OVR5_SHIFT                              (5U)
#define eADC_OVRSTS_OVR5(x)                                 (((uint32)(((uint32)(x)) << eADC_OVRSTS_OVR5_SHIFT)) & eADC_OVRSTS_OVR5_MASK)
#define eADC_OVRSTS_OVR4_MASK                               (0x10U)
#define eADC_OVRSTS_OVR4_SHIFT                              (4U)
#define eADC_OVRSTS_OVR4(x)                                 (((uint32)(((uint32)(x)) << eADC_OVRSTS_OVR4_SHIFT)) & eADC_OVRSTS_OVR4_MASK)
#define eADC_OVRSTS_OVR3_MASK                               (0x8U)
#define eADC_OVRSTS_OVR3_SHIFT                              (3U)
#define eADC_OVRSTS_OVR3(x)                                 (((uint32)(((uint32)(x)) << eADC_OVRSTS_OVR3_SHIFT)) & eADC_OVRSTS_OVR3_MASK)
#define eADC_OVRSTS_OVR2_MASK                               (0x4U)
#define eADC_OVRSTS_OVR2_SHIFT                              (2U)
#define eADC_OVRSTS_OVR2(x)                                 (((uint32)(((uint32)(x)) << eADC_OVRSTS_OVR2_SHIFT)) & eADC_OVRSTS_OVR2_MASK)
#define eADC_OVRSTS_OVR1_MASK                               (0x2U)
#define eADC_OVRSTS_OVR1_SHIFT                              (1U)
#define eADC_OVRSTS_OVR1(x)                                 (((uint32)(((uint32)(x)) << eADC_OVRSTS_OVR1_SHIFT)) & eADC_OVRSTS_OVR1_MASK)
#define eADC_OVRSTS_OVR0_MASK                               (0x1U)
#define eADC_OVRSTS_OVR0_SHIFT                              (0U)
#define eADC_OVRSTS_OVR0(x)                                 (((uint32)(((uint32)(x)) << eADC_OVRSTS_OVR0_SHIFT)) & eADC_OVRSTS_OVR0_MASK)
/* eADC_INTE Register */
#define eADC_INTE_WDIE_MASK                                 (0x10000U)
#define eADC_INTE_WDIE_SHIFT                                (16U)
#define eADC_INTE_WDIE(x)                                   (((uint32)(((uint32)(x)) << eADC_INTE_WDIE_SHIFT)) & eADC_INTE_WDIE_MASK)
#define eADC_INTE_LOWERRIE_MASK                             (0x80U)
#define eADC_INTE_LOWERRIE_SHIFT                            (7U)
#define eADC_INTE_LOWERRIE(x)                               (((uint32)(((uint32)(x)) << eADC_INTE_LOWERRIE_SHIFT)) & eADC_INTE_LOWERRIE_MASK)
#define eADC_INTE_OVRIE_MASK                                (0x40U)
#define eADC_INTE_OVRIE_SHIFT                               (6U)
#define eADC_INTE_OVRIE(x)                                  (((uint32)(((uint32)(x)) << eADC_INTE_OVRIE_SHIFT)) & eADC_INTE_OVRIE_MASK)
#define eADC_INTE_LEOSEQIE_MASK                             (0x20U)
#define eADC_INTE_LEOSEQIE_SHIFT                            (5U)
#define eADC_INTE_LEOSEQIE(x)                               (((uint32)(((uint32)(x)) << eADC_INTE_LEOSEQIE_SHIFT)) & eADC_INTE_LEOSEQIE_MASK)
#define eADC_INTE_HEOSEQIE_MASK                             (0x10U)
#define eADC_INTE_HEOSEQIE_SHIFT                            (4U)
#define eADC_INTE_HEOSEQIE(x)                               (((uint32)(((uint32)(x)) << eADC_INTE_HEOSEQIE_SHIFT)) & eADC_INTE_HEOSEQIE_MASK)
#define eADC_INTE_NORERRIE_MASK                             (0x8U)
#define eADC_INTE_NORERRIE_SHIFT                            (3U)
#define eADC_INTE_NORERRIE(x)                               (((uint32)(((uint32)(x)) << eADC_INTE_NORERRIE_SHIFT)) & eADC_INTE_NORERRIE_MASK)
#define eADC_INTE_EOCIE_MASK                                (0x4U)
#define eADC_INTE_EOCIE_SHIFT                               (2U)
#define eADC_INTE_EOCIE(x)                                  (((uint32)(((uint32)(x)) << eADC_INTE_EOCIE_SHIFT)) & eADC_INTE_EOCIE_MASK)
#define eADC_INTE_EOSMPIE_MASK                              (0x2U)
#define eADC_INTE_EOSMPIE_SHIFT                             (1U)
#define eADC_INTE_EOSMPIE(x)                                (((uint32)(((uint32)(x)) << eADC_INTE_EOSMPIE_SHIFT)) & eADC_INTE_EOSMPIE_MASK)
#define eADC_INTE_ADRDYIE_MASK                              (0x1U)
#define eADC_INTE_ADRDYIE_SHIFT                             (0U)
#define eADC_INTE_ADRDYIE(x)                                (((uint32)(((uint32)(x)) << eADC_INTE_ADRDYIE_SHIFT)) & eADC_INTE_ADRDYIE_MASK)
/* eADC_CTRL Register */
#define eADC_CTRL_TSEN_MASK                                 (0x10U)
#define eADC_CTRL_TSEN_SHIFT                                (4U)
#define eADC_CTRL_TSEN(x)                                   (((uint32)(((uint32)(x)) << eADC_CTRL_TSEN_SHIFT)) & eADC_CTRL_TSEN_MASK)
#define eADC_CTRL_ADSTOP_MASK                               (0x8U)
#define eADC_CTRL_ADSTOP_SHIFT                              (3U)
#define eADC_CTRL_ADSTOP(x)                                 (((uint32)(((uint32)(x)) << eADC_CTRL_ADSTOP_SHIFT)) & eADC_CTRL_ADSTOP_MASK)
#define eADC_CTRL_ADSTART_MASK                              (0x4U)
#define eADC_CTRL_ADSTART_SHIFT                             (2U)
#define eADC_CTRL_ADSTART(x)                                (((uint32)(((uint32)(x)) << eADC_CTRL_ADSTART_SHIFT)) & eADC_CTRL_ADSTART_MASK)
#define eADC_CTRL_ADDIS_MASK                                (0x2U)
#define eADC_CTRL_ADDIS_SHIFT                               (1U)
#define eADC_CTRL_ADDIS(x)                                  (((uint32)(((uint32)(x)) << eADC_CTRL_ADDIS_SHIFT)) & eADC_CTRL_ADDIS_MASK)
#define eADC_CTRL_ADEN_MASK                                 (0x1U)
#define eADC_CTRL_ADEN_SHIFT                                (0U)
#define eADC_CTRL_ADEN(x)                                   (((uint32)(((uint32)(x)) << eADC_CTRL_ADEN_SHIFT)) & eADC_CTRL_ADEN_MASK)
/* eADC_CFG0 Register */
#define eADC_CFG0_SEQCFG_MASK                               (0xC0000000U)
#define eADC_CFG0_SEQCFG_SHIFT                              (30U)
#define eADC_CFG0_SEQCFG(x)                                 (((uint32)(((uint32)(x)) << eADC_CFG0_SEQCFG_SHIFT)) & eADC_CFG0_SEQCFG_MASK)
#define eADC_CFG0_HSEQSEL_MASK                              (0x20000000U)
#define eADC_CFG0_HSEQSEL_SHIFT                             (29U)
#define eADC_CFG0_HSEQSEL(x)                                (((uint32)(((uint32)(x)) << eADC_CFG0_HSEQSEL_SHIFT)) & eADC_CFG0_HSEQSEL_MASK)
#define eADC_CFG0_HSEQLEN_MASK                              (0xF000000U)
#define eADC_CFG0_HSEQLEN_SHIFT                             (24U)
#define eADC_CFG0_HSEQLEN(x)                                (((uint32)(((uint32)(x)) << eADC_CFG0_HSEQLEN_SHIFT)) & eADC_CFG0_HSEQLEN_MASK)
#define eADC_CFG0_LPEN_MASK                                 (0x200000U)
#define eADC_CFG0_LPEN_SHIFT                                (21U)
#define eADC_CFG0_LPEN(x)                                   (((uint32)(((uint32)(x)) << eADC_CFG0_LPEN_SHIFT)) & eADC_CFG0_LPEN_MASK)
#define eADC_CFG0_AUTOOFF_MASK                              (0x100000U)
#define eADC_CFG0_AUTOOFF_SHIFT                             (20U)
#define eADC_CFG0_AUTOOFF(x)                                (((uint32)(((uint32)(x)) << eADC_CFG0_AUTOOFF_SHIFT)) & eADC_CFG0_AUTOOFF_MASK)
#define eADC_CFG0_ALIGN_MASK                                (0x80000U)
#define eADC_CFG0_ALIGN_SHIFT                               (19U)
#define eADC_CFG0_ALIGN(x)                                  (((uint32)(((uint32)(x)) << eADC_CFG0_ALIGN_SHIFT)) & eADC_CFG0_ALIGN_MASK)
#define eADC_CFG0_MODE_MASK                                 (0x70000U)
#define eADC_CFG0_MODE_SHIFT                                (16U)
#define eADC_CFG0_MODE(x)                                   (((uint32)(((uint32)(x)) << eADC_CFG0_MODE_SHIFT)) & eADC_CFG0_MODE_MASK)
#define eADC_CFG0_RES_MASK                                  (0xC000U)
#define eADC_CFG0_RES_SHIFT                                 (14U)
#define eADC_CFG0_RES(x)                                    (((uint32)(((uint32)(x)) << eADC_CFG0_RES_SHIFT)) & eADC_CFG0_RES_MASK)
#define eADC_CFG0_SFTTEN_MASK                               (0x2000U)
#define eADC_CFG0_SFTTEN_SHIFT                              (13U)
#define eADC_CFG0_SFTTEN(x)                                 (((uint32)(((uint32)(x)) << eADC_CFG0_SFTTEN_SHIFT)) & eADC_CFG0_SFTTEN_MASK)
#define eADC_CFG0_LSEQLEN_MASK                              (0xF00U)
#define eADC_CFG0_LSEQLEN_SHIFT                             (8U)
#define eADC_CFG0_LSEQLEN(x)                                (((uint32)(((uint32)(x)) << eADC_CFG0_LSEQLEN_SHIFT)) & eADC_CFG0_LSEQLEN_MASK)
#define eADC_CFG0_PRS_MASK                                  (0x78U)
#define eADC_CFG0_PRS_SHIFT                                 (3U)
#define eADC_CFG0_PRS(x)                                    (((uint32)(((uint32)(x)) << eADC_CFG0_PRS_SHIFT)) & eADC_CFG0_PRS_MASK)
#define eADC_CFG0_DMAREQCFG_MASK                            (0x4U)
#define eADC_CFG0_DMAREQCFG_SHIFT                           (2U)
#define eADC_CFG0_DMAREQCFG(x)                              (((uint32)(((uint32)(x)) << eADC_CFG0_DMAREQCFG_SHIFT)) & eADC_CFG0_DMAREQCFG_MASK)
#define eADC_CFG0_LDMAEN_MASK                               (0x2U)
#define eADC_CFG0_LDMAEN_SHIFT                              (1U)
#define eADC_CFG0_LDMAEN(x)                                 (((uint32)(((uint32)(x)) << eADC_CFG0_LDMAEN_SHIFT)) & eADC_CFG0_LDMAEN_MASK)
#define eADC_CFG0_HDMAEN_MASK                               (0x1U)
#define eADC_CFG0_HDMAEN_SHIFT                              (0U)
#define eADC_CFG0_HDMAEN(x)                                 (((uint32)(((uint32)(x)) << eADC_CFG0_HDMAEN_SHIFT)) & eADC_CFG0_HDMAEN_MASK)
/* eADC_CFG1 Register */
#define eADC_CFG1_SMPAVGE_MASK                              (0xE0000000U)
#define eADC_CFG1_SMPAVGE_SHIFT                             (29U)
#define eADC_CFG1_SMPAVGE(x)                                (((uint32)(((uint32)(x)) << eADC_CFG1_SMPAVGE_SHIFT)) & eADC_CFG1_SMPAVGE_MASK)
#define eADC_CFG1_SWITCHCNT_MASK                            (0xF0000U)
#define eADC_CFG1_SWITCHCNT_SHIFT                           (16U)
#define eADC_CFG1_SWITCHCNT(x)                              (((uint32)(((uint32)(x)) << eADC_CFG1_SWITCHCNT_SHIFT)) & eADC_CFG1_SWITCHCNT_MASK)
#define eADC_CFG1_STCNT_MASK                                (0xFFU)
#define eADC_CFG1_STCNT_SHIFT                               (0U)
#define eADC_CFG1_STCNT(x)                                  (((uint32)(((uint32)(x)) << eADC_CFG1_STCNT_SHIFT)) & eADC_CFG1_STCNT_MASK)
/* eADC_SMP Register */
#define eADC_SMP_SMP1_MASK                                  (0xFF00U)
#define eADC_SMP_SMP1_SHIFT                                 (8U)
#define eADC_SMP_SMP1(x)                                    (((uint32)(((uint32)(x)) << eADC_SMP_SMP1_SHIFT)) & eADC_SMP_SMP1_MASK)
#define eADC_SMP_SMP0_MASK                                  (0xFFU)
#define eADC_SMP_SMP0_SHIFT                                 (0U)
#define eADC_SMP_SMP0(x)                                    (((uint32)(((uint32)(x)) << eADC_SMP_SMP0_SHIFT)) & eADC_SMP_SMP0_MASK)
/* eADC_CHSEL Register */
#define eADC_CHSEL_SMPSEL_MASK                              (0x80U)
#define eADC_CHSEL_SMPSEL_SHIFT                             (7U)
#define eADC_CHSEL_SMPSEL(x)                                (((uint32)(((uint32)(x)) << eADC_CHSEL_SMPSEL_SHIFT)) & eADC_CHSEL_SMPSEL_MASK)
#define eADC_CHSEL_OVRMOD_MASK                              (0x40U)
#define eADC_CHSEL_OVRMOD_SHIFT                             (6U)
#define eADC_CHSEL_OVRMOD(x)                                (((uint32)(((uint32)(x)) << eADC_CHSEL_OVRMOD_SHIFT)) & eADC_CHSEL_OVRMOD_MASK)
#define eADC_CHSEL_CHSEL_MASK                               (0x3FU)
#define eADC_CHSEL_CHSEL_SHIFT                              (0U)
#define eADC_CHSEL_CHSEL(x)                                 (((uint32)(((uint32)(x)) << eADC_CHSEL_CHSEL_SHIFT)) & eADC_CHSEL_CHSEL_MASK)
/* eADC_TSC Register */
#define eADC_TSC_COEFF_MASK                                 (0xFFFU)
#define eADC_TSC_COEFF_SHIFT                                (0U)
#define eADC_TSC_COEFF(x)                                   (((uint32)(((uint32)(x)) << eADC_TSC_COEFF_SHIFT)) & eADC_TSC_COEFF_MASK)
/* eADC_WDCTRL Register */
#define eADC_WDCTRL_WD1EN_MASK                              (0x8000U)
#define eADC_WDCTRL_WD1EN_SHIFT                             (15U)
#define eADC_WDCTRL_WD1EN(x)                                (((uint32)(((uint32)(x)) << eADC_WDCTRL_WD1EN_SHIFT)) & eADC_WDCTRL_WD1EN_MASK)
#define eADC_WDCTRL_WD1CHSEL_MASK                           (0x3F00U)
#define eADC_WDCTRL_WD1CHSEL_SHIFT                          (8U)
#define eADC_WDCTRL_WD1CHSEL(x)                             (((uint32)(((uint32)(x)) << eADC_WDCTRL_WD1CHSEL_SHIFT)) & eADC_WDCTRL_WD1CHSEL_MASK)
#define eADC_WDCTRL_WD0EN_MASK                              (0x80U)
#define eADC_WDCTRL_WD0EN_SHIFT                             (7U)
#define eADC_WDCTRL_WD0EN(x)                                (((uint32)(((uint32)(x)) << eADC_WDCTRL_WD0EN_SHIFT)) & eADC_WDCTRL_WD0EN_MASK)
#define eADC_WDCTRL_WD0SGL_MASK                             (0x40U)
#define eADC_WDCTRL_WD0SGL_SHIFT                            (6U)
#define eADC_WDCTRL_WD0SGL(x)                               (((uint32)(((uint32)(x)) << eADC_WDCTRL_WD0SGL_SHIFT)) & eADC_WDCTRL_WD0SGL_MASK)
#define eADC_WDCTRL_WD0CHSEL_MASK                           (0x3FU)
#define eADC_WDCTRL_WD0CHSEL_SHIFT                          (0U)
#define eADC_WDCTRL_WD0CHSEL(x)                             (((uint32)(((uint32)(x)) << eADC_WDCTRL_WD0CHSEL_SHIFT)) & eADC_WDCTRL_WD0CHSEL_MASK)
/* eADC_WDTH Register */
#define eADC_WDTH_THMD_MASK                                 (0x80000000U)
#define eADC_WDTH_THMD_SHIFT                                (31U)
#define eADC_WDTH_THMD(x)                                   (((uint32)(((uint32)(x)) << eADC_WDTH_THMD_SHIFT)) & eADC_WDTH_THMD_MASK)
#define eADC_WDTH_HIGH_MASK                                 (0xFFF0000U)
#define eADC_WDTH_HIGH_SHIFT                                (16U)
#define eADC_WDTH_HIGH(x)                                   (((uint32)(((uint32)(x)) << eADC_WDTH_HIGH_SHIFT)) & eADC_WDTH_HIGH_MASK)
#define eADC_WDTH_LOW_MASK                                  (0xFFFU)
#define eADC_WDTH_LOW_SHIFT                                 (0U)
#define eADC_WDTH_LOW(x)                                    (((uint32)(((uint32)(x)) << eADC_WDTH_LOW_SHIFT)) & eADC_WDTH_LOW_MASK)
/* eADC_DATA Register */
#define eADC_DATA_DB_MASK                                   (0xFFFFU)
#define eADC_DATA_DB_SHIFT                                  (0U)
#define eADC_DATA_DB(x)                                     (((uint32)(((uint32)(x)) << eADC_DATA_DB_SHIFT)) & eADC_DATA_DB_MASK)


/**
 * @}
 */ /* end of group eADC_Register_Masks */


/**
 * @}
 */ /* end of group eADC_Peripheral_Access_Layer */

#endif /* PSIP_EADC_H */
