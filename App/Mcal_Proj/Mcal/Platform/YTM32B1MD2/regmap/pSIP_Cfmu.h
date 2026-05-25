/**
*   @file    pSIP_Cfmu.h
*   @version
*
*   @brief   AUTOSAR Cfmu register map
*   @details Register map for CFMU
*
*   @addtogroup CFMU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Cfmu
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

#ifndef PSIP_CFMU_H
#define PSIP_CFMU_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              CFMU REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup CFMU_Peripheral_Access_Layer CFMU Peripheral Access Layer
 * @{
 */


/** CFMU - Size of Registers Arrays */

/* CFMU Register Layout Typedef */
typedef struct
{
    uint32 CTRL;                               /**< Control Register, offset: 0x0000 */
    uint32 CLK_CNT;                            /**< Clock Count Register, offset: 0x0004 */
    uint32 REFCLK_CNT;                         /**< Reference Clock Count Register, offset: 0x0008 */
    uint32 CLK_TGTCNT;                         /**< Target Count of to-be-measured Clock Register, offset: 0x000C */
    uint32 REFCLK_TGTCNT;                      /**< Reference Clock Target Count Register, offset: 0x0010 */
    uint32 STS;                                /**< Status Register, offset: 0x0014 */
    uint32 REFCLK_CNT_SAVED;                   /**< Reference Clock Count Saved Register, offset: 0x0018 */

} CFMU_Type, *CFMU_MemMapPtr;

/** Number of instances of the CFMU module. */
#define CFMU_INSTANCE_COUNT                        (1u)

/* CFMU0  base address */
#define CFMU0_BASE_ADDR32                                  (0x40077000U)
#define CFMU0                                              ((volatile CFMU_Type *)(CFMU0_BASE_ADDR32))

/** Array initializer of CFMU peripheral base addresses */
#define CFMU_BASE_ADDRS                                    { CFMU0_BASE_ADDR32 }
/** Array initializer of CFMU peripheral base pointers */
#define CFMU_BASE_PTRS                                     { CFMU0 }

#define CFMU_CTRL_OFFSET32                                 (0x0000U)                    /**< Offset for Control Register */
#define CFMU_CLK_CNT_OFFSET32                              (0x0004U)                    /**< Offset for Clock Count Register */
#define CFMU_REFCLK_CNT_OFFSET32                           (0x0008U)                    /**< Offset for Reference Clock Count Register */
#define CFMU_CLK_TGTCNT_OFFSET32                           (0x000CU)                    /**< Offset for Target Count of to-be-measured Clock Register */
#define CFMU_REFCLK_TGTCNT_OFFSET32                        (0x0010U)                    /**< Offset for Reference Clock Target Count Register */
#define CFMU_STS_OFFSET32                                  (0x0014U)                    /**< Offset for Status Register */
#define CFMU_REFCLK_CNT_SAVED_OFFSET32                     (0x0018U)                    /**< Offset for Reference Clock Count Saved Register */


/**
 * @addtogroup CFMU Register Mask
 * @{
 */
/* CFMU_CTRL Register */
#define CFMU_CTRL_CLK_OUTEN_MASK                            (0x8000U)
#define CFMU_CTRL_CLK_OUTEN_SHIFT                           (15U)
#define CFMU_CTRL_CLK_OUTEN(x)                              (((uint32)(((uint32)(x)) << CFMU_CTRL_CLK_OUTEN_SHIFT)) & CFMU_CTRL_CLK_OUTEN_MASK)
#define CFMU_CTRL_CLK_SEL_MASK                              (0x7F00U)
#define CFMU_CTRL_CLK_SEL_SHIFT                             (8U)
#define CFMU_CTRL_CLK_SEL(x)                                (((uint32)(((uint32)(x)) << CFMU_CTRL_CLK_SEL_SHIFT)) & CFMU_CTRL_CLK_SEL_MASK)
#define CFMU_CTRL_CLK_DIV_MASK                              (0xFFU)
#define CFMU_CTRL_CLK_DIV_SHIFT                             (0U)
#define CFMU_CTRL_CLK_DIV(x)                                (((uint32)(((uint32)(x)) << CFMU_CTRL_CLK_DIV_SHIFT)) & CFMU_CTRL_CLK_DIV_MASK)
/* CFMU_CLK_CNT Register */
#define CFMU_CLK_CNT_CNT_MASK                               (0xFFFFU)
#define CFMU_CLK_CNT_CNT_SHIFT                              (0U)
#define CFMU_CLK_CNT_CNT(x)                                 (((uint32)(((uint32)(x)) << CFMU_CLK_CNT_CNT_SHIFT)) & CFMU_CLK_CNT_CNT_MASK)
/* CFMU_REFCLK_CNT Register */
#define CFMU_REFCLK_CNT_CNT_MASK                            (0xFFFFU)
#define CFMU_REFCLK_CNT_CNT_SHIFT                           (0U)
#define CFMU_REFCLK_CNT_CNT(x)                              (((uint32)(((uint32)(x)) << CFMU_REFCLK_CNT_CNT_SHIFT)) & CFMU_REFCLK_CNT_CNT_MASK)
/* CFMU_CLK_TGTCNT Register */
#define CFMU_CLK_TGTCNT_CNT_MASK                            (0xFFFFU)
#define CFMU_CLK_TGTCNT_CNT_SHIFT                           (0U)
#define CFMU_CLK_TGTCNT_CNT(x)                              (((uint32)(((uint32)(x)) << CFMU_CLK_TGTCNT_CNT_SHIFT)) & CFMU_CLK_TGTCNT_CNT_MASK)
/* CFMU_REFCLK_TGTCNT Register */
#define CFMU_REFCLK_TGTCNT_CNT_MASK                         (0xFFFFU)
#define CFMU_REFCLK_TGTCNT_CNT_SHIFT                        (0U)
#define CFMU_REFCLK_TGTCNT_CNT(x)                           (((uint32)(((uint32)(x)) << CFMU_REFCLK_TGTCNT_CNT_SHIFT)) & CFMU_REFCLK_TGTCNT_CNT_MASK)
/* CFMU_STS Register */
#define CFMU_STS_CLK_CNT_START_MASK                         (0x4U)
#define CFMU_STS_CLK_CNT_START_SHIFT                        (2U)
#define CFMU_STS_CLK_CNT_START(x)                           (((uint32)(((uint32)(x)) << CFMU_STS_CLK_CNT_START_SHIFT)) & CFMU_STS_CLK_CNT_START_MASK)
#define CFMU_STS_CLK_CNT_STOP_MASK                          (0x2U)
#define CFMU_STS_CLK_CNT_STOP_SHIFT                         (1U)
#define CFMU_STS_CLK_CNT_STOP(x)                            (((uint32)(((uint32)(x)) << CFMU_STS_CLK_CNT_STOP_SHIFT)) & CFMU_STS_CLK_CNT_STOP_MASK)
#define CFMU_STS_REFCLK_CNT_STOP_MASK                       (0x1U)
#define CFMU_STS_REFCLK_CNT_STOP_SHIFT                      (0U)
#define CFMU_STS_REFCLK_CNT_STOP(x)                         (((uint32)(((uint32)(x)) << CFMU_STS_REFCLK_CNT_STOP_SHIFT)) & CFMU_STS_REFCLK_CNT_STOP_MASK)
/* CFMU_REFCLK_CNT_SAVED Register */
#define CFMU_REFCLK_CNT_SAVED_CNT_MASK                       (0xFFFFU)
#define CFMU_REFCLK_CNT_SAVED_CNT_SHIFT                      (0U)
#define CFMU_REFCLK_CNT_SAVED_CNT(x)                         (((uint32)(((uint32)(x)) << CFMU_REFCLK_CNT_SAVED_CNT_SHIFT)) & CFMU_REFCLK_CNT_SAVED_CNT_MASK)


/**
 * @}
 */ /* end of group CFMU_Register_Masks */


/**
 * @}
 */ /* end of group CFMU_Peripheral_Access_Layer */

#endif /* PSIP_CFMU_H */
