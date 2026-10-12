/**
*   @file    pSIP_Cmu.h
*   @version
*
*   @brief   AUTOSAR Cmu register map
*   @details Register map for CMU
*
*   @addtogroup CMU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Cmu
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

#ifndef PSIP_CMU_H
#define PSIP_CMU_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              CMU REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup CMU_Peripheral_Access_Layer CMU Peripheral Access Layer
 * @{
 */


/** CMU - Size of Registers Arrays */
#define CMU_CMP_COUNT           (8)
#define CMU_REFCNTTGT_COUNT           (8)
#define CMU_CLKVLDDLY_COUNT           (8)

/* CMU Register Layout Typedef */
typedef struct
{
    uint32 CTRL;                               /**< Clock Monitor Unit Control Register, offset: 0x0000 */
    uint32 STS;                                /**< Clock Monitor Unit Status Register, offset: 0x0004 */
    struct
    {
        uint32 HIGH;                               /**< Clock Monitor Unit High Comparison Value Register, offset: 0x0000 */
        uint32 LOW;                                /**< Clock Monitor Unit Low Comparison Value Register, offset: 0x0004 */

    } CMP[8];
    uint32 REFCNTTGT[ 8];                      /**< Reference Clock Counter Target Value Register, offset: 0x0048 */
    uint8 RESERVED4[ 4];                      /**< RESERVED4, offset: 0x0068 */
    uint32 RESERVED5[ 8];                      /**< RESERVED5, offset: 0x006C */
    uint32 CLKVLDDLY[ 8];                      /**< Monitored Clock Valid Delay Time Selection Register, offset: 0x008C */

} CMU_Type, *CMU_MemMapPtr;

/** Number of instances of the CMU module. */
#define CMU_INSTANCE_COUNT                        (1u)

/* CMU0  base address */
#define CMU0_BASE_ADDR32                                   (0x40076000U)
#define CMU0                                               ((volatile CMU_Type *)(CMU0_BASE_ADDR32))

/** Array initializer of CMU peripheral base addresses */
#define CMU_BASE_ADDRS                                     { CMU0_BASE_ADDR32 }
/** Array initializer of CMU peripheral base pointers */
#define CMU_BASE_PTRS                                      { CMU0 }

#define CMU_CTRL_OFFSET32                                  (0x0000U)                    /**< Offset for Clock Monitor Unit Control Register */
#define CMU_STS_OFFSET32                                   (0x0004U)                    /**< Offset for Clock Monitor Unit Status Register */
#define CMU_CMP_OFFSET32(x)                                (0x0008U + ((x) * (8U)))    /**< Offset for Clock Monitor Unit Comparison Value Structure */

#define CMU_CMP_HIGH_OFFSET32(x)                           (0x0008U + ((x) * (8U)))    /**< Offset for Clock Monitor Unit High Comparison Value Register */
#define CMU_CMP_LOW_OFFSET32(x)                            (0x000CU + ((x) * (8U)))    /**< Offset for Clock Monitor Unit Low Comparison Value Register */

#define CMU_REFCNTTGT_OFFSET32(x)                          (0x0048U + ((x) * (4U)))     /**< Offset for Reference Clock Counter Target Value Register */
#define CMU_CLKVLDDLY_OFFSET32(x)                          (0x008CU + ((x) * (4U)))     /**< Offset for Monitored Clock Valid Delay Time Selection Register */


/**
 * @addtogroup CMU Register Mask
 * @{
 */
/* CMU_CTRL Register */
#define CMU_CTRL_REFS_MASK                                 (0xFF0000U)
#define CMU_CTRL_REFS_SHIFT                                (16U)
#define CMU_CTRL_REFS(x)                                   (((uint32)(((uint32)(x)) << CMU_CTRL_REFS_SHIFT)) & CMU_CTRL_REFS_MASK)
#define CMU_CTRL_RE_MASK                                   (0xFF00U)
#define CMU_CTRL_RE_SHIFT                                  (8U)
#define CMU_CTRL_RE(x)                                     (((uint32)(((uint32)(x)) << CMU_CTRL_RE_SHIFT)) & CMU_CTRL_RE_MASK)
#define CMU_CTRL_EN_MASK                                   (0x0FU)
#define CMU_CTRL_EN_SHIFT                                  (0U)
#define CMU_CTRL_EN(x)                                     (((uint32)(((uint32)(x)) << CMU_CTRL_EN_SHIFT)) & CMU_CTRL_EN_MASK)
/* CMU_STS Register */
#define CMU_STS_LOSV_MASK                                  (0xFF000000U)
#define CMU_STS_LOSV_SHIFT                                 (24U)
#define CMU_STS_LOSV(x)                                    (((uint32)(((uint32)(x)) << CMU_STS_LOSV_SHIFT)) & CMU_STS_LOSV_MASK)
#define CMU_STS_LOSC_MASK                                  (0xFF0000U)
#define CMU_STS_LOSC_SHIFT                                 (16U)
#define CMU_STS_LOSC(x)                                    (((uint32)(((uint32)(x)) << CMU_STS_LOSC_SHIFT)) & CMU_STS_LOSC_MASK)
#define CMU_STS_LOSR_MASK                                  (0xFF00U)
#define CMU_STS_LOSR_SHIFT                                 (8U)
#define CMU_STS_LOSR(x)                                    (((uint32)(((uint32)(x)) << CMU_STS_LOSR_SHIFT)) & CMU_STS_LOSR_MASK)
#define CMU_STS_OUTRNG_MASK                                (0xFFU)
#define CMU_STS_OUTRNG_SHIFT                               (0U)
#define CMU_STS_OUTRNG(x)                                  (((uint32)(((uint32)(x)) << CMU_STS_OUTRNG_SHIFT)) & CMU_STS_OUTRNG_MASK)
/* CMU_CMP_HIGH Register */
#define CMU_CMP_HIGH_VAL_MASK                                  (0xFFFFU)
#define CMU_CMP_HIGH_VAL_SHIFT                                 (0U)
#define CMU_CMP_HIGH_VAL(x)                                    (((uint32)(((uint32)(x)) << CMU_CMP_HIGH_VAL_SHIFT)) & CMU_CMP_HIGH_VAL_MASK)
/* CMU_CMP_LOW Register */
#define CMU_CMP_LOW_VAL_MASK                                   (0xFFFFU)
#define CMU_CMP_LOW_VAL_SHIFT                                  (0U)
#define CMU_CMP_LOW_VAL(x)                                     (((uint32)(((uint32)(x)) << CMU_CMP_LOW_VAL_SHIFT)) & CMU_CMP_LOW_VAL_MASK)

/* CMU_REFCNTTGT Register */
#define CMU_REFCNTTGT_VAL_MASK                             (0xFFU)
#define CMU_REFCNTTGT_VAL_SHIFT                            (0U)
#define CMU_REFCNTTGT_VAL(x)                               (((uint32)(((uint32)(x)) << CMU_REFCNTTGT_VAL_SHIFT)) & CMU_REFCNTTGT_VAL_MASK)
/* CMU_CLKVLDDLY Register */
#define CMU_CLKVLDDLY_VAL_MASK                             (0xFU)
#define CMU_CLKVLDDLY_VAL_SHIFT                            (0U)
#define CMU_CLKVLDDLY_VAL(x)                               (((uint32)(((uint32)(x)) << CMU_CLKVLDDLY_VAL_SHIFT)) & CMU_CLKVLDDLY_VAL_MASK)


/**
 * @}
 */ /* end of group CMU_Register_Masks */


/**
 * @}
 */ /* end of group CMU_Peripheral_Access_Layer */

#endif /* PSIP_CMU_H */
