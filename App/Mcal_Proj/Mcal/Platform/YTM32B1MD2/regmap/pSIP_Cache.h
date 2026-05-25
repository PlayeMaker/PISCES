/**
*   @file    pSIP_Cache.h
*   @version
*
*   @brief   AUTOSAR Cache register map
*   @details Register map for CACHE
*
*   @addtogroup CACHE_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Cache
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

#ifndef PSIP_CACHE_H
#define PSIP_CACHE_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              CACHE REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup CACHE_Peripheral_Access_Layer CACHE Peripheral Access Layer
 * @{
 */


/** CACHE - Size of Registers Arrays */

/* CACHE Register Layout Typedef */
typedef struct
{
    uint32 CACR;                               /**< Cache Control Register, offset: 0x0000 */
    uint32 CALCR;                              /**< Cache Line Control Register, offset: 0x0004 */
    uint32 CASAR;                              /**< Cache Search Address Register, offset: 0x0008 */
    uint32 RESERVED3;                          /**< RESERVED3, offset: 0x000C */
    uint8 RESERVED4[16];                      /**< RESERVED4, offset: 0x0010 */
    uint32 CAMR;                               /**< Cache Mode Register, offset: 0x0020 */
    uint8 RESERVED6[28];                      /**< RESERVED6, offset: 0x0024 */
    uint32 CAPCR;                              /**< Cache Parity Control Register, offset: 0x0040 */
    uint32 CAPFISR;                            /**< Cache Parity Fault Interrupt Status Register, offset: 0x0044 */
    uint32 CAPFADDR;                           /**< Cache Parity Fault Address Register, offset: 0x0048 */
    uint32 CAPFATT;                            /**< Cache Parity Fault Attribute Register, offset: 0x004C */
    uint32 RESERVED11;                         /**< RESERVED11, offset: 0x0050 */
    uint32 CAPFDAT;                            /**< Cache Parity Fault DATA Register, offset: 0x0054 */

} CACHE_Type, *CACHE_MemMapPtr;

/** Number of instances of the CACHE module. */
#define CACHE_INSTANCE_COUNT                        (1u)

/* CACHE base address */
#define CACHE_BASE_ADDR32                                 (0xE0080000U)
#define CACHE                                             ((volatile CACHE_Type *)(CACHE_BASE_ADDR32))

/** Array initializer of CACHE peripheral base addresses */
#define CACHE_BASE_ADDRS                                   { CACHE_BASE_ADDR32 }
/** Array initializer of CACHE peripheral base pointers */
#define CACHE_BASE_PTRS                                    { CACHE }

#define CACHE_CACR_OFFSET32                                (0x0000U)                    /**< Offset for Cache Control Register */
#define CACHE_CALCR_OFFSET32                               (0x0004U)                    /**< Offset for Cache Line Control Register */
#define CACHE_CASAR_OFFSET32                               (0x0008U)                    /**< Offset for Cache Search Address Register */
#define CACHE_CAMR_OFFSET32                                (0x0020U)                    /**< Offset for Cache Mode Register */
#define CACHE_CAPCR_OFFSET32                               (0x0040U)                    /**< Offset for Cache Parity Control Register */
#define CACHE_CAPFISR_OFFSET32                             (0x0044U)                    /**< Offset for Cache Parity Fault Interrupt Status Register */
#define CACHE_CAPFADDR_OFFSET32                            (0x0048U)                    /**< Offset for Cache Parity Fault Address Register */
#define CACHE_CAPFATT_OFFSET32                             (0x004CU)                    /**< Offset for Cache Parity Fault Attribute Register */
#define CACHE_CAPFDAT_OFFSET32                             (0x0054U)                    /**< Offset for Cache Parity Fault DATA Register */


/**
 * @addtogroup CACHE Register Mask
 * @{
 */
/* CACHE_CACR Register */
#define CACHE_CACR_CMDREQ_MASK                               (0x80000000U)
#define CACHE_CACR_CMDREQ_SHIFT                              (31U)
#define CACHE_CACR_CMDREQ(x)                                 (((uint32)(((uint32)(x)) << CACHE_CACR_CMDREQ_SHIFT)) & CACHE_CACR_CMDREQ_MASK)
#define CACHE_CACR_IW1_MASK                                  (0x4000000U)
#define CACHE_CACR_IW1_SHIFT                                 (26U)
#define CACHE_CACR_IW1(x)                                    (((uint32)(((uint32)(x)) << CACHE_CACR_IW1_SHIFT)) & CACHE_CACR_IW1_MASK)
#define CACHE_CACR_IW0_MASK                                  (0x1000000U)
#define CACHE_CACR_IW0_SHIFT                                 (24U)
#define CACHE_CACR_IW0(x)                                    (((uint32)(((uint32)(x)) << CACHE_CACR_IW0_SHIFT)) & CACHE_CACR_IW0_MASK)
#define CACHE_CACR_EN_MASK                                   (0x1U)
#define CACHE_CACR_EN_SHIFT                                  (0U)
#define CACHE_CACR_EN(x)                                     (((uint32)(((uint32)(x)) << CACHE_CACR_EN_SHIFT)) & CACHE_CACR_EN_MASK)
/* CACHE_CALCR Register */
#define CACHE_CALCR_LADDRS_MASK                              (0x4000000U)
#define CACHE_CALCR_LADDRS_SHIFT                             (26U)
#define CACHE_CALCR_LADDRS(x)                                (((uint32)(((uint32)(x)) << CACHE_CALCR_LADDRS_SHIFT)) & CACHE_CALCR_LADDRS_MASK)
#define CACHE_CALCR_LCMD_MASK                                (0x3000000U)
#define CACHE_CALCR_LCMD_SHIFT                               (24U)
#define CACHE_CALCR_LCMD(x)                                  (((uint32)(((uint32)(x)) << CACHE_CALCR_LCMD_SHIFT)) & CACHE_CALCR_LCMD_MASK)
#define CACHE_CALCR_LCMDW_MASK                               (0x400000U)
#define CACHE_CALCR_LCMDW_SHIFT                              (22U)
#define CACHE_CALCR_LCMDW(x)                                 (((uint32)(((uint32)(x)) << CACHE_CALCR_LCMDW_SHIFT)) & CACHE_CALCR_LCMDW_MASK)
#define CACHE_CALCR_LCMDREQV_MASK                            (0x100000U)
#define CACHE_CALCR_LCMDREQV_SHIFT                           (20U)
#define CACHE_CALCR_LCMDREQV(x)                              (((uint32)(((uint32)(x)) << CACHE_CALCR_LCMDREQV_SHIFT)) & CACHE_CALCR_LCMDREQV_MASK)
#define CACHE_CALCR_WS_MASK                                  (0x4000U)
#define CACHE_CALCR_WS_SHIFT                                 (14U)
#define CACHE_CALCR_WS(x)                                    (((uint32)(((uint32)(x)) << CACHE_CALCR_WS_SHIFT)) & CACHE_CALCR_WS_MASK)
#define CACHE_CALCR_CAADDR_MASK                              (0x3FF0U)
#define CACHE_CALCR_CAADDR_SHIFT                             (4U)
#define CACHE_CALCR_CAADDR(x)                                (((uint32)(((uint32)(x)) << CACHE_CALCR_CAADDR_SHIFT)) & CACHE_CALCR_CAADDR_MASK)
#define CACHE_CALCR_LCMDREQ_MASK                             (0x1U)
#define CACHE_CALCR_LCMDREQ_SHIFT                            (0U)
#define CACHE_CALCR_LCMDREQ(x)                               (((uint32)(((uint32)(x)) << CACHE_CALCR_LCMDREQ_SHIFT)) & CACHE_CALCR_LCMDREQ_MASK)
/* CACHE_CASAR Register */
#define CACHE_CASAR_PHYADDR_MASK                             (0xFFFFFFF0U)
#define CACHE_CASAR_PHYADDR_SHIFT                            (4U)
#define CACHE_CASAR_PHYADDR(x)                               (((uint32)(((uint32)(x)) << CACHE_CASAR_PHYADDR_SHIFT)) & CACHE_CASAR_PHYADDR_MASK)
#define CACHE_CASAR_LCMDREQ_MASK                             (0x1U)
#define CACHE_CASAR_LCMDREQ_SHIFT                            (0U)
#define CACHE_CASAR_LCMDREQ(x)                               (((uint32)(((uint32)(x)) << CACHE_CASAR_LCMDREQ_SHIFT)) & CACHE_CASAR_LCMDREQ_MASK)
/* CACHE_CAMR Register */
#define CACHE_CAMR_PFLASHCM_MASK                             (0x80000000U)
#define CACHE_CAMR_PFLASHCM_SHIFT                            (31U)
#define CACHE_CAMR_PFLASHCM(x)                               (((uint32)(((uint32)(x)) << CACHE_CAMR_PFLASHCM_SHIFT)) & CACHE_CAMR_PFLASHCM_MASK)
#define CACHE_CAMR_OCRAMCM_MASK                              (0x8000000U)
#define CACHE_CAMR_OCRAMCM_SHIFT                             (27U)
#define CACHE_CAMR_OCRAMCM(x)                                (((uint32)(((uint32)(x)) << CACHE_CAMR_OCRAMCM_SHIFT)) & CACHE_CAMR_OCRAMCM_MASK)
/* CACHE_CAPCR Register */
#define CACHE_CAPCR_CAPREN_MASK                              (0x4U)
#define CACHE_CAPCR_CAPREN_SHIFT                             (2U)
#define CACHE_CAPCR_CAPREN(x)                                (((uint32)(((uint32)(x)) << CACHE_CAPCR_CAPREN_SHIFT)) & CACHE_CAPCR_CAPREN_MASK)
#define CACHE_CAPCR_CAPFEN_MASK                              (0x2U)
#define CACHE_CAPCR_CAPFEN_SHIFT                             (1U)
#define CACHE_CAPCR_CAPFEN(x)                                (((uint32)(((uint32)(x)) << CACHE_CAPCR_CAPFEN_SHIFT)) & CACHE_CAPCR_CAPFEN_MASK)
#define CACHE_CAPCR_CAPFBDIS_MASK                            (0x1U)
#define CACHE_CAPCR_CAPFBDIS_SHIFT                           (0U)
#define CACHE_CAPCR_CAPFBDIS(x)                              (((uint32)(((uint32)(x)) << CACHE_CAPCR_CAPFBDIS_SHIFT)) & CACHE_CAPCR_CAPFBDIS_MASK)
/* CACHE_CAPFISR Register */
#define CACHE_CAPFISR_CATPERR_MASK                           (0x2U)
#define CACHE_CAPFISR_CATPERR_SHIFT                          (1U)
#define CACHE_CAPFISR_CATPERR(x)                             (((uint32)(((uint32)(x)) << CACHE_CAPFISR_CATPERR_SHIFT)) & CACHE_CAPFISR_CATPERR_MASK)
#define CACHE_CAPFISR_CADPERR_MASK                           (0x1U)
#define CACHE_CAPFISR_CADPERR_SHIFT                          (0U)
#define CACHE_CAPFISR_CADPERR(x)                             (((uint32)(((uint32)(x)) << CACHE_CAPFISR_CADPERR_SHIFT)) & CACHE_CAPFISR_CADPERR_MASK)
/* CACHE_CAPFADDR Register */
#define CACHE_CAPFADDR_CAPFADDR_MASK                         (0xFFFFFFFFU)
#define CACHE_CAPFADDR_CAPFADDR_SHIFT                        (0U)
#define CACHE_CAPFADDR_CAPFADDR(x)                           (((uint32)(((uint32)(x)) << CACHE_CAPFADDR_CAPFADDR_SHIFT)) & CACHE_CAPFADDR_CAPFADDR_MASK)
/* CACHE_CAPFATT Register */
#define CACHE_CAPFATT_CAPFSIZE_MASK                          (0x70U)
#define CACHE_CAPFATT_CAPFSIZE_SHIFT                         (4U)
#define CACHE_CAPFATT_CAPFSIZE(x)                            (((uint32)(((uint32)(x)) << CACHE_CAPFATT_CAPFSIZE_SHIFT)) & CACHE_CAPFATT_CAPFSIZE_MASK)
#define CACHE_CAPFATT_CAPFPROT_MASK                          (0xFU)
#define CACHE_CAPFATT_CAPFPROT_SHIFT                         (0U)
#define CACHE_CAPFATT_CAPFPROT(x)                            (((uint32)(((uint32)(x)) << CACHE_CAPFATT_CAPFPROT_SHIFT)) & CACHE_CAPFATT_CAPFPROT_MASK)
/* CACHE_CAPFDAT Register */
#define CACHE_CAPFDAT_CAPFDAT_MASK                           (0xFFFFFFFFU)
#define CACHE_CAPFDAT_CAPFDAT_SHIFT                          (0U)
#define CACHE_CAPFDAT_CAPFDAT(x)                             (((uint32)(((uint32)(x)) << CACHE_CAPFDAT_CAPFDAT_SHIFT)) & CACHE_CAPFDAT_CAPFDAT_MASK)


/**
 * @}
 */ /* end of group CACHE_Register_Masks */


/**
 * @}
 */ /* end of group CACHE_Peripheral_Access_Layer */

#endif /* PSIP_CACHE_H */
