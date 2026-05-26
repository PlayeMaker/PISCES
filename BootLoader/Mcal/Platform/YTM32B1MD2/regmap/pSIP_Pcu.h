/**
*   @file    pSIP_Pcu.h
*   @version
*
*   @brief   AUTOSAR Pcu register map
*   @details Register map for PCU
*
*   @addtogroup PCU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Pcu
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

#ifndef PSIP_PCU_H
#define PSIP_PCU_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              PCU REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup PCU_Peripheral_Access_Layer PCU Peripheral Access Layer
 * @{
 */


/** PCU - Size of Registers Arrays */

/* PCU Register Layout Typedef */
typedef struct
{
    uint32 BORCR;                              /**< BOR Control Register, offset: 0x0000 */
    uint32 LVDCR;                              /**< Low Voltage Detection Control Register, offset: 0x0004 */
    uint32 CSR;                                /**< Control and Status Register, offset: 0x0008 */
    uint32 RESERVED3;                          /**< RESERVED3, offset: 0x000C */
    uint32 RESERVED4;                          /**< RESERVED4, offset: 0x0010 */

} PCU_Type, *PCU_MemMapPtr;

/** Number of instances of the PCU module. */
#define PCU_INSTANCE_COUNT                        (1u)

/* PCU base address */
#define PCU_BASE_ADDR32                                   (0x4007E000U)
#define PCU                                               ((volatile PCU_Type *)(PCU_BASE_ADDR32))

/** Array initializer of PCU peripheral base addresses */
#define PCU_BASE_ADDRS                                     { PCU_BASE_ADDR32 }
/** Array initializer of PCU peripheral base pointers */
#define PCU_BASE_PTRS                                      { PCU }

#define PCU_BORCR_OFFSET32                                 (0x0000U)                    /**< Offset for BOR Control Register */
#define PCU_LVDCR_OFFSET32                                 (0x0004U)                    /**< Offset for Low Voltage Detection Control Register */
#define PCU_CSR_OFFSET32                                   (0x0008U)                    /**< Offset for Control and Status Register */


/**
 * @addtogroup PCU Register Mask
 * @{
 */
/* PCU_BORCR Register */
#define PCU_BORCR_BORLPMD_MASK                             (0x2U)
#define PCU_BORCR_BORLPMD_SHIFT                            (1U)
#define PCU_BORCR_BORLPMD(x)                               (((uint32)(((uint32)(x)) << PCU_BORCR_BORLPMD_SHIFT)) & PCU_BORCR_BORLPMD_MASK)
#define PCU_BORCR_BOREN_MASK                               (0x1U)
#define PCU_BORCR_BOREN_SHIFT                              (0U)
#define PCU_BORCR_BOREN(x)                                 (((uint32)(((uint32)(x)) << PCU_BORCR_BOREN_SHIFT)) & PCU_BORCR_BOREN_MASK)
/* PCU_LVDCR Register */
#define PCU_LVDCR_LVD5VHYS_MASK                            (0x300000U)
#define PCU_LVDCR_LVD5VHYS_SHIFT                           (20U)
#define PCU_LVDCR_LVD5VHYS(x)                              (((uint32)(((uint32)(x)) << PCU_LVDCR_LVD5VHYS_SHIFT)) & PCU_LVDCR_LVD5VHYS_MASK)
#define PCU_LVDCR_LVD5VTRIM_MASK                           (0xF0000U)
#define PCU_LVDCR_LVD5VTRIM_SHIFT                          (16U)
#define PCU_LVDCR_LVD5VTRIM(x)                             (((uint32)(((uint32)(x)) << PCU_LVDCR_LVD5VTRIM_SHIFT)) & PCU_LVDCR_LVD5VTRIM_MASK)
#define PCU_LVDCR_LVD5VOUT_MASK                            (0x8000U)
#define PCU_LVDCR_LVD5VOUT_SHIFT                           (15U)
#define PCU_LVDCR_LVD5VOUT(x)                              (((uint32)(((uint32)(x)) << PCU_LVDCR_LVD5VOUT_SHIFT)) & PCU_LVDCR_LVD5VOUT_MASK)
#define PCU_LVDCR_LVD5VFLAG_MASK                           (0x4000U)
#define PCU_LVDCR_LVD5VFLAG_SHIFT                          (14U)
#define PCU_LVDCR_LVD5VFLAG(x)                             (((uint32)(((uint32)(x)) << PCU_LVDCR_LVD5VFLAG_SHIFT)) & PCU_LVDCR_LVD5VFLAG_MASK)
#define PCU_LVDCR_LVD5VIE_MASK                             (0x2000U)
#define PCU_LVDCR_LVD5VIE_SHIFT                            (13U)
#define PCU_LVDCR_LVD5VIE(x)                               (((uint32)(((uint32)(x)) << PCU_LVDCR_LVD5VIE_SHIFT)) & PCU_LVDCR_LVD5VIE_MASK)
#define PCU_LVDCR_LVD5VRE_MASK                             (0x1000U)
#define PCU_LVDCR_LVD5VRE_SHIFT                            (12U)
#define PCU_LVDCR_LVD5VRE(x)                               (((uint32)(((uint32)(x)) << PCU_LVDCR_LVD5VRE_SHIFT)) & PCU_LVDCR_LVD5VRE_MASK)
#define PCU_LVDCR_FLTCFG_MASK                              (0x18U)
#define PCU_LVDCR_FLTCFG_SHIFT                             (3U)
#define PCU_LVDCR_FLTCFG(x)                                (((uint32)(((uint32)(x)) << PCU_LVDCR_FLTCFG_SHIFT)) & PCU_LVDCR_FLTCFG_MASK)
#define PCU_LVDCR_LVD5VFLTEN_MASK                          (0x4U)
#define PCU_LVDCR_LVD5VFLTEN_SHIFT                         (2U)
#define PCU_LVDCR_LVD5VFLTEN(x)                            (((uint32)(((uint32)(x)) << PCU_LVDCR_LVD5VFLTEN_SHIFT)) & PCU_LVDCR_LVD5VFLTEN_MASK)
#define PCU_LVDCR_LVD5VLPMD_MASK                           (0x2U)
#define PCU_LVDCR_LVD5VLPMD_SHIFT                          (1U)
#define PCU_LVDCR_LVD5VLPMD(x)                             (((uint32)(((uint32)(x)) << PCU_LVDCR_LVD5VLPMD_SHIFT)) & PCU_LVDCR_LVD5VLPMD_MASK)
#define PCU_LVDCR_LVD5VEN_MASK                             (0x1U)
#define PCU_LVDCR_LVD5VEN_SHIFT                            (0U)
#define PCU_LVDCR_LVD5VEN(x)                               (((uint32)(((uint32)(x)) << PCU_LVDCR_LVD5VEN_SHIFT)) & PCU_LVDCR_LVD5VEN_MASK)
/* PCU_CSR Register */
#define PCU_CSR_SET1V_MASK                                 (0x400000U)
#define PCU_CSR_SET1V_SHIFT                                (22U)
#define PCU_CSR_SET1V(x)                                   (((uint32)(((uint32)(x)) << PCU_CSR_SET1V_SHIFT)) & PCU_CSR_SET1V_MASK)
#define PCU_CSR_PMCHPRDY_MASK                              (0x200000U)
#define PCU_CSR_PMCHPRDY_SHIFT                             (21U)
#define PCU_CSR_PMCHPRDY(x)                                (((uint32)(((uint32)(x)) << PCU_CSR_PMCHPRDY_SHIFT)) & PCU_CSR_PMCHPRDY_MASK)
#define PCU_CSR_ESCFG_MASK                                 (0xF0000U)
#define PCU_CSR_ESCFG_SHIFT                                (16U)
#define PCU_CSR_ESCFG(x)                                   (((uint32)(((uint32)(x)) << PCU_CSR_ESCFG_SHIFT)) & PCU_CSR_ESCFG_MASK)
#define PCU_CSR_PMCHPRDYDCFG_MASK                          (0x30U)
#define PCU_CSR_PMCHPRDYDCFG_SHIFT                         (4U)
#define PCU_CSR_PMCHPRDYDCFG(x)                            (((uint32)(((uint32)(x)) << PCU_CSR_PMCHPRDYDCFG_SHIFT)) & PCU_CSR_PMCHPRDYDCFG_MASK)
#define PCU_CSR_PMCLPEN_MASK                               (0x1U)
#define PCU_CSR_PMCLPEN_SHIFT                              (0U)
#define PCU_CSR_PMCLPEN(x)                                 (((uint32)(((uint32)(x)) << PCU_CSR_PMCLPEN_SHIFT)) & PCU_CSR_PMCLPEN_MASK)


/**
 * @}
 */ /* end of group PCU_Register_Masks */


/**
 * @}
 */ /* end of group PCU_Peripheral_Access_Layer */

#endif /* PSIP_PCU_H */
