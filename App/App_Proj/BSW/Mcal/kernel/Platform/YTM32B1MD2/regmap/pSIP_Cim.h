/**
*   @file    pSIP_Cim.h
*   @version
*
*   @brief   AUTOSAR Cim register map
*   @details Register map for CIM
*
*   @addtogroup CIM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Cim
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

#ifndef PSIP_CIM_H
#define PSIP_CIM_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              CIM REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup CIM_Peripheral_Access_Layer CIM Peripheral Access Layer
 * @{
 */


/** CIM - Size of Registers Arrays */

/* CIM Register Layout Typedef */
typedef struct
{
    uint32 DIEINFO;                            /**< Die Information Register, offset: 0x0000 */
    uint8 RESERVED1[ 4];                      /**< RESERVED1, offset: 0x0004 */
    uint32 CHIPINFO;                           /**< Chip Information Register, offset: 0x0008 */
    uint8 RESERVED3[36];                      /**< RESERVED3, offset: 0x000C */
    uint32 CTRL;                               /**< CIM Control Register, offset: 0x0030 */
    uint8 RESERVED5[12];                      /**< RESERVED5, offset: 0x0034 */
    uint32 FPUIE;                              /**< FPU Interrupt Enable Register, offset: 0x0040 */
    uint32 SWTRIG;                             /**< Software Trigger Register, offset: 0x0044 */
    uint32 ETMROPT0;                           /**< eTMR Option Register 0, offset: 0x0048 */
    uint32 ETMROPT1;                           /**< eTMR Option Register 1, offset: 0x004C */

} CIM_Type, *CIM_MemMapPtr;

/** Number of instances of the CIM module. */
#define CIM_INSTANCE_COUNT                        (1u)

/* CIM base address */
#define CIM_BASE_ADDR32                                   (0x4007B000U)
#define CIM                                               ((volatile CIM_Type *)(CIM_BASE_ADDR32))

/** Array initializer of CIM peripheral base addresses */
#define CIM_BASE_ADDRS                                     { CIM_BASE_ADDR32 }
/** Array initializer of CIM peripheral base pointers */
#define CIM_BASE_PTRS                                      { CIM }

#define CIM_DIEINFO_OFFSET32                               (0x0000U)                    /**< Offset for Die Information Register */
#define CIM_CHIPINFO_OFFSET32                              (0x0008U)                    /**< Offset for Chip Information Register */
#define CIM_CTRL_OFFSET32                                  (0x0030U)                    /**< Offset for CIM Control Register */
#define CIM_FPUIE_OFFSET32                                 (0x0040U)                    /**< Offset for FPU Interrupt Enable Register */
#define CIM_SWTRIG_OFFSET32                                (0x0044U)                    /**< Offset for Software Trigger Register */
#define CIM_ETMROPT0_OFFSET32                              (0x0048U)                    /**< Offset for eTMR Option Register 0 */
#define CIM_ETMROPT1_OFFSET32                              (0x004CU)                    /**< Offset for eTMR Option Register 1 */


/**
 * @addtogroup CIM Register Mask
 * @{
 */
/* CIM_DIEINFO Register */
#define CIM_DIEINFO_FAMID_MASK                             (0xF0000000U)
#define CIM_DIEINFO_FAMID_SHIFT                            (28U)
#define CIM_DIEINFO_FAMID(x)                               (((uint32)(((uint32)(x)) << CIM_DIEINFO_FAMID_SHIFT)) & CIM_DIEINFO_FAMID_MASK)
#define CIM_DIEINFO_GENID_MASK                             (0xF000000U)
#define CIM_DIEINFO_GENID_SHIFT                            (24U)
#define CIM_DIEINFO_GENID(x)                               (((uint32)(((uint32)(x)) << CIM_DIEINFO_GENID_SHIFT)) & CIM_DIEINFO_GENID_MASK)
#define CIM_DIEINFO_SUBFAMIDH_MASK                         (0xF00000U)
#define CIM_DIEINFO_SUBFAMIDH_SHIFT                        (20U)
#define CIM_DIEINFO_SUBFAMIDH(x)                           (((uint32)(((uint32)(x)) << CIM_DIEINFO_SUBFAMIDH_SHIFT)) & CIM_DIEINFO_SUBFAMIDH_MASK)
#define CIM_DIEINFO_SUBFAMIDL_MASK                         (0xF0000U)
#define CIM_DIEINFO_SUBFAMIDL_SHIFT                        (16U)
#define CIM_DIEINFO_SUBFAMIDL(x)                           (((uint32)(((uint32)(x)) << CIM_DIEINFO_SUBFAMIDL_SHIFT)) & CIM_DIEINFO_SUBFAMIDL_MASK)
#define CIM_DIEINFO_MAJVER_MASK                            (0xF0U)
#define CIM_DIEINFO_MAJVER_SHIFT                           (4U)
#define CIM_DIEINFO_MAJVER(x)                              (((uint32)(((uint32)(x)) << CIM_DIEINFO_MAJVER_SHIFT)) & CIM_DIEINFO_MAJVER_MASK)
#define CIM_DIEINFO_MINVER_MASK                            (0xFU)
#define CIM_DIEINFO_MINVER_SHIFT                           (0U)
#define CIM_DIEINFO_MINVER(x)                              (((uint32)(((uint32)(x)) << CIM_DIEINFO_MINVER_SHIFT)) & CIM_DIEINFO_MINVER_MASK)
/* CIM_CHIPINFO Register */
#define CIM_CHIPINFO_FLEXCAN2_EN_MASK                      (0x20000000U)
#define CIM_CHIPINFO_FLEXCAN2_EN_SHIFT                     (29U)
#define CIM_CHIPINFO_FLEXCAN2_EN(x)                        (((uint32)(((uint32)(x)) << CIM_CHIPINFO_FLEXCAN2_EN_SHIFT)) & CIM_CHIPINFO_FLEXCAN2_EN_MASK)
#define CIM_CHIPINFO_FLEXCAN1_EN_MASK                      (0x10000000U)
#define CIM_CHIPINFO_FLEXCAN1_EN_SHIFT                     (28U)
#define CIM_CHIPINFO_FLEXCAN1_EN(x)                        (((uint32)(((uint32)(x)) << CIM_CHIPINFO_FLEXCAN1_EN_SHIFT)) & CIM_CHIPINFO_FLEXCAN1_EN_MASK)
#define CIM_CHIPINFO_FLEXCAN0_EN_MASK                      (0x8000000U)
#define CIM_CHIPINFO_FLEXCAN0_EN_SHIFT                     (27U)
#define CIM_CHIPINFO_FLEXCAN0_EN(x)                        (((uint32)(((uint32)(x)) << CIM_CHIPINFO_FLEXCAN0_EN_SHIFT)) & CIM_CHIPINFO_FLEXCAN0_EN_MASK)
#define CIM_CHIPINFO_FLEXCAN2_FD_EN_MASK                   (0x4000000U)
#define CIM_CHIPINFO_FLEXCAN2_FD_EN_SHIFT                  (26U)
#define CIM_CHIPINFO_FLEXCAN2_FD_EN(x)                     (((uint32)(((uint32)(x)) << CIM_CHIPINFO_FLEXCAN2_FD_EN_SHIFT)) & CIM_CHIPINFO_FLEXCAN2_FD_EN_MASK)
#define CIM_CHIPINFO_FLEXCAN1_FD_EN_MASK                   (0x2000000U)
#define CIM_CHIPINFO_FLEXCAN1_FD_EN_SHIFT                  (25U)
#define CIM_CHIPINFO_FLEXCAN1_FD_EN(x)                     (((uint32)(((uint32)(x)) << CIM_CHIPINFO_FLEXCAN1_FD_EN_SHIFT)) & CIM_CHIPINFO_FLEXCAN1_FD_EN_MASK)
#define CIM_CHIPINFO_FLEXCAN0_FD_EN_MASK                   (0x1000000U)
#define CIM_CHIPINFO_FLEXCAN0_FD_EN_SHIFT                  (24U)
#define CIM_CHIPINFO_FLEXCAN0_FD_EN(x)                     (((uint32)(((uint32)(x)) << CIM_CHIPINFO_FLEXCAN0_FD_EN_SHIFT)) & CIM_CHIPINFO_FLEXCAN0_FD_EN_MASK)
#define CIM_CHIPINFO_PKGS_MASK                             (0xF00000U)
#define CIM_CHIPINFO_PKGS_SHIFT                            (20U)
#define CIM_CHIPINFO_PKGS(x)                               (((uint32)(((uint32)(x)) << CIM_CHIPINFO_PKGS_SHIFT)) & CIM_CHIPINFO_PKGS_MASK)
#define CIM_CHIPINFO_SRAMS_MASK                            (0xF0000U)
#define CIM_CHIPINFO_SRAMS_SHIFT                           (16U)
#define CIM_CHIPINFO_SRAMS(x)                              (((uint32)(((uint32)(x)) << CIM_CHIPINFO_SRAMS_SHIFT)) & CIM_CHIPINFO_SRAMS_MASK)
#define CIM_CHIPINFO_DFLASHS_MASK                          (0xF000U)
#define CIM_CHIPINFO_DFLASHS_SHIFT                         (12U)
#define CIM_CHIPINFO_DFLASHS(x)                            (((uint32)(((uint32)(x)) << CIM_CHIPINFO_DFLASHS_SHIFT)) & CIM_CHIPINFO_DFLASHS_MASK)
#define CIM_CHIPINFO_PFLASHS_MASK                          (0xF00U)
#define CIM_CHIPINFO_PFLASHS_SHIFT                         (8U)
#define CIM_CHIPINFO_PFLASHS(x)                            (((uint32)(((uint32)(x)) << CIM_CHIPINFO_PFLASHS_SHIFT)) & CIM_CHIPINFO_PFLASHS_MASK)
/* CIM_CTRL Register */
#define CIM_CTRL_ACMP0_TRIG_SEL_MASK                       (0x300U)
#define CIM_CTRL_ACMP0_TRIG_SEL_SHIFT                      (8U)
#define CIM_CTRL_ACMP0_TRIG_SEL(x)                         (((uint32)(((uint32)(x)) << CIM_CTRL_ACMP0_TRIG_SEL_SHIFT)) & CIM_CTRL_ACMP0_TRIG_SEL_MASK)
#define CIM_CTRL_LOCKUPEN_MASK                             (0x4U)
#define CIM_CTRL_LOCKUPEN_SHIFT                            (2U)
#define CIM_CTRL_LOCKUPEN(x)                               (((uint32)(((uint32)(x)) << CIM_CTRL_LOCKUPEN_SHIFT)) & CIM_CTRL_LOCKUPEN_MASK)
#define CIM_CTRL_NMIEN_MASK                                (0x2U)
#define CIM_CTRL_NMIEN_SHIFT                               (1U)
#define CIM_CTRL_NMIEN(x)                                  (((uint32)(((uint32)(x)) << CIM_CTRL_NMIEN_SHIFT)) & CIM_CTRL_NMIEN_MASK)
#define CIM_CTRL_WICENREQ_MASK                             (0x1U)
#define CIM_CTRL_WICENREQ_SHIFT                            (0U)
#define CIM_CTRL_WICENREQ(x)                               (((uint32)(((uint32)(x)) << CIM_CTRL_WICENREQ_SHIFT)) & CIM_CTRL_WICENREQ_MASK)
/* CIM_FPUIE Register */
#define CIM_FPUIE_FPIXCIE_MASK                             (0x20U)
#define CIM_FPUIE_FPIXCIE_SHIFT                            (5U)
#define CIM_FPUIE_FPIXCIE(x)                               (((uint32)(((uint32)(x)) << CIM_FPUIE_FPIXCIE_SHIFT)) & CIM_FPUIE_FPIXCIE_MASK)
#define CIM_FPUIE_FPIDCIE_MASK                             (0x10U)
#define CIM_FPUIE_FPIDCIE_SHIFT                            (4U)
#define CIM_FPUIE_FPIDCIE(x)                               (((uint32)(((uint32)(x)) << CIM_FPUIE_FPIDCIE_SHIFT)) & CIM_FPUIE_FPIDCIE_MASK)
#define CIM_FPUIE_FPOFCIE_MASK                             (0x8U)
#define CIM_FPUIE_FPOFCIE_SHIFT                            (3U)
#define CIM_FPUIE_FPOFCIE(x)                               (((uint32)(((uint32)(x)) << CIM_FPUIE_FPOFCIE_SHIFT)) & CIM_FPUIE_FPOFCIE_MASK)
#define CIM_FPUIE_FPUFCIE_MASK                             (0x4U)
#define CIM_FPUIE_FPUFCIE_SHIFT                            (2U)
#define CIM_FPUIE_FPUFCIE(x)                               (((uint32)(((uint32)(x)) << CIM_FPUIE_FPUFCIE_SHIFT)) & CIM_FPUIE_FPUFCIE_MASK)
#define CIM_FPUIE_FPDZCIE_MASK                             (0x2U)
#define CIM_FPUIE_FPDZCIE_SHIFT                            (1U)
#define CIM_FPUIE_FPDZCIE(x)                               (((uint32)(((uint32)(x)) << CIM_FPUIE_FPDZCIE_SHIFT)) & CIM_FPUIE_FPDZCIE_MASK)
#define CIM_FPUIE_FPIOCIE_MASK                             (0x1U)
#define CIM_FPUIE_FPIOCIE_SHIFT                            (0U)
#define CIM_FPUIE_FPIOCIE(x)                               (((uint32)(((uint32)(x)) << CIM_FPUIE_FPIOCIE_SHIFT)) & CIM_FPUIE_FPIOCIE_MASK)
/* CIM_SWTRIG Register */
#define CIM_SWTRIG_SWTCNT_MASK                             (0xFEU)
#define CIM_SWTRIG_SWTCNT_SHIFT                            (1U)
#define CIM_SWTRIG_SWTCNT(x)                               (((uint32)(((uint32)(x)) << CIM_SWTRIG_SWTCNT_SHIFT)) & CIM_SWTRIG_SWTCNT_MASK)
#define CIM_SWTRIG_SWT_MASK                                (0x1U)
#define CIM_SWTRIG_SWT_SHIFT                               (0U)
#define CIM_SWTRIG_SWT(x)                                  (((uint32)(((uint32)(x)) << CIM_SWTRIG_SWT_SHIFT)) & CIM_SWTRIG_SWT_MASK)
/* CIM_ETMROPT0 Register */
#define CIM_ETMROPT0_ETMR1_FAULT_SEL_MASK                  (0x700000U)
#define CIM_ETMROPT0_ETMR1_FAULT_SEL_SHIFT                 (20U)
#define CIM_ETMROPT0_ETMR1_FAULT_SEL(x)                    (((uint32)(((uint32)(x)) << CIM_ETMROPT0_ETMR1_FAULT_SEL_SHIFT)) & CIM_ETMROPT0_ETMR1_FAULT_SEL_MASK)
#define CIM_ETMROPT0_ETMR0_FAULT_SEL_MASK                  (0x70000U)
#define CIM_ETMROPT0_ETMR0_FAULT_SEL_SHIFT                 (16U)
#define CIM_ETMROPT0_ETMR0_FAULT_SEL(x)                    (((uint32)(((uint32)(x)) << CIM_ETMROPT0_ETMR0_FAULT_SEL_SHIFT)) & CIM_ETMROPT0_ETMR0_FAULT_SEL_MASK)
#define CIM_ETMROPT0_ETMR1_EXTCLK_SEL_MASK                  (0xCU)
#define CIM_ETMROPT0_ETMR1_EXTCLK_SEL_SHIFT                 (2U)
#define CIM_ETMROPT0_ETMR1_EXTCLK_SEL(x)                    (((uint32)(((uint32)(x)) << CIM_ETMROPT0_ETMR1_EXTCLK_SEL_SHIFT)) & CIM_ETMROPT0_ETMR1_EXTCLK_SEL_MASK)
#define CIM_ETMROPT0_ETMR0_EXTCLK_SEL_MASK                  (0x3U)
#define CIM_ETMROPT0_ETMR0_EXTCLK_SEL_SHIFT                 (0U)
#define CIM_ETMROPT0_ETMR0_EXTCLK_SEL(x)                    (((uint32)(((uint32)(x)) << CIM_ETMROPT0_ETMR0_EXTCLK_SEL_SHIFT)) & CIM_ETMROPT0_ETMR0_EXTCLK_SEL_MASK)
/* CIM_ETMROPT1 Register */
#define CIM_ETMROPT1_ETMR0_CH7OUTSEL_MASK                  (0x800000U)
#define CIM_ETMROPT1_ETMR0_CH7OUTSEL_SHIFT                 (23U)
#define CIM_ETMROPT1_ETMR0_CH7OUTSEL(x)                    (((uint32)(((uint32)(x)) << CIM_ETMROPT1_ETMR0_CH7OUTSEL_SHIFT)) & CIM_ETMROPT1_ETMR0_CH7OUTSEL_MASK)
#define CIM_ETMROPT1_ETMR0_CH6OUTSEL_MASK                  (0x400000U)
#define CIM_ETMROPT1_ETMR0_CH6OUTSEL_SHIFT                 (22U)
#define CIM_ETMROPT1_ETMR0_CH6OUTSEL(x)                    (((uint32)(((uint32)(x)) << CIM_ETMROPT1_ETMR0_CH6OUTSEL_SHIFT)) & CIM_ETMROPT1_ETMR0_CH6OUTSEL_MASK)
#define CIM_ETMROPT1_ETMR0_CH5OUTSEL_MASK                  (0x200000U)
#define CIM_ETMROPT1_ETMR0_CH5OUTSEL_SHIFT                 (21U)
#define CIM_ETMROPT1_ETMR0_CH5OUTSEL(x)                    (((uint32)(((uint32)(x)) << CIM_ETMROPT1_ETMR0_CH5OUTSEL_SHIFT)) & CIM_ETMROPT1_ETMR0_CH5OUTSEL_MASK)
#define CIM_ETMROPT1_ETMR0_CH4OUTSEL_MASK                  (0x100000U)
#define CIM_ETMROPT1_ETMR0_CH4OUTSEL_SHIFT                 (20U)
#define CIM_ETMROPT1_ETMR0_CH4OUTSEL(x)                    (((uint32)(((uint32)(x)) << CIM_ETMROPT1_ETMR0_CH4OUTSEL_SHIFT)) & CIM_ETMROPT1_ETMR0_CH4OUTSEL_MASK)
#define CIM_ETMROPT1_ETMR0_CH3OUTSEL_MASK                  (0x80000U)
#define CIM_ETMROPT1_ETMR0_CH3OUTSEL_SHIFT                 (19U)
#define CIM_ETMROPT1_ETMR0_CH3OUTSEL(x)                    (((uint32)(((uint32)(x)) << CIM_ETMROPT1_ETMR0_CH3OUTSEL_SHIFT)) & CIM_ETMROPT1_ETMR0_CH3OUTSEL_MASK)
#define CIM_ETMROPT1_ETMR0_CH2OUTSEL_MASK                  (0x40000U)
#define CIM_ETMROPT1_ETMR0_CH2OUTSEL_SHIFT                 (18U)
#define CIM_ETMROPT1_ETMR0_CH2OUTSEL(x)                    (((uint32)(((uint32)(x)) << CIM_ETMROPT1_ETMR0_CH2OUTSEL_SHIFT)) & CIM_ETMROPT1_ETMR0_CH2OUTSEL_MASK)
#define CIM_ETMROPT1_ETMR0_CH1OUTSEL_MASK                  (0x20000U)
#define CIM_ETMROPT1_ETMR0_CH1OUTSEL_SHIFT                 (17U)
#define CIM_ETMROPT1_ETMR0_CH1OUTSEL(x)                    (((uint32)(((uint32)(x)) << CIM_ETMROPT1_ETMR0_CH1OUTSEL_SHIFT)) & CIM_ETMROPT1_ETMR0_CH1OUTSEL_MASK)
#define CIM_ETMROPT1_ETMR0_CH0OUTSEL_MASK                  (0x10000U)
#define CIM_ETMROPT1_ETMR0_CH0OUTSEL_SHIFT                 (16U)
#define CIM_ETMROPT1_ETMR0_CH0OUTSEL(x)                    (((uint32)(((uint32)(x)) << CIM_ETMROPT1_ETMR0_CH0OUTSEL_SHIFT)) & CIM_ETMROPT1_ETMR0_CH0OUTSEL_MASK)
#define CIM_ETMROPT1_MPWM0CH0SEL_MASK                      (0x1000U)
#define CIM_ETMROPT1_MPWM0CH0SEL_SHIFT                     (12U)
#define CIM_ETMROPT1_MPWM0CH0SEL(x)                        (((uint32)(((uint32)(x)) << CIM_ETMROPT1_MPWM0CH0SEL_SHIFT)) & CIM_ETMROPT1_MPWM0CH0SEL_MASK)
#define CIM_ETMROPT1_MPWM0CH6SEL_MASK                      (0x400U)
#define CIM_ETMROPT1_MPWM0CH6SEL_SHIFT                     (10U)
#define CIM_ETMROPT1_MPWM0CH6SEL(x)                        (((uint32)(((uint32)(x)) << CIM_ETMROPT1_MPWM0CH6SEL_SHIFT)) & CIM_ETMROPT1_MPWM0CH6SEL_MASK)
#define CIM_ETMROPT1_ETMR1CH0SEL_MASK                      (0x100U)
#define CIM_ETMROPT1_ETMR1CH0SEL_SHIFT                     (8U)
#define CIM_ETMROPT1_ETMR1CH0SEL(x)                        (((uint32)(((uint32)(x)) << CIM_ETMROPT1_ETMR1CH0SEL_SHIFT)) & CIM_ETMROPT1_ETMR1CH0SEL_MASK)
#define CIM_ETMROPT1_ETMR1SS1C_MASK                        (0x2U)
#define CIM_ETMROPT1_ETMR1SS1C_SHIFT                       (1U)
#define CIM_ETMROPT1_ETMR1SS1C(x)                          (((uint32)(((uint32)(x)) << CIM_ETMROPT1_ETMR1SS1C_SHIFT)) & CIM_ETMROPT1_ETMR1SS1C_MASK)
#define CIM_ETMROPT1_ETMR0SS1C_MASK                        (0x1U)
#define CIM_ETMROPT1_ETMR0SS1C_SHIFT                       (0U)
#define CIM_ETMROPT1_ETMR0SS1C(x)                          (((uint32)(((uint32)(x)) << CIM_ETMROPT1_ETMR0SS1C_SHIFT)) & CIM_ETMROPT1_ETMR0SS1C_MASK)


/**
 * @}
 */ /* end of group CIM_Register_Masks */


/**
 * @}
 */ /* end of group CIM_Peripheral_Access_Layer */

#endif /* PSIP_CIM_H */
