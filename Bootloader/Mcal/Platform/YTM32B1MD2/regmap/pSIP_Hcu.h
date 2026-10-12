/**
*   @file    pSIP_Hcu.h
*   @version
*
*   @brief   AUTOSAR Hcu register map
*   @details Register map for HCU
*
*   @addtogroup HCU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Hcu
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

#ifndef PSIP_HCU_H
#define PSIP_HCU_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              HCU REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup HCU_Peripheral_Access_Layer HCU Peripheral Access Layer
 * @{
 */


/** HCU - Size of Registers Arrays */
#define HCU_KEY_COUNT           (4)
#define HCU_CONTEXT_4_7_COUNT           (4)
#define HCU_CONTEXT_8_11_COUNT           (4)
#define HCU_CONTEXT_12_19_COUNT           (8)
#define HCU_CONTEXT_28_35_COUNT           (8)
#define HCU_PKEA_COUNT           (128)
#define HCU_PKEE_COUNT           (128)
#define HCU_PKEN_COUNT           (128)

/* HCU Register Layout Typedef */
typedef struct
{
    uint32 GO;                                 /**< Go Register, offset: 0x0000 */
    uint32 CR;                                 /**< Configuration Register, offset: 0x0004 */
    uint32 MSGINFO;                            /**< Message Information Register, offset: 0x0008 */
    uint32 MSGCUR;                             /**< Message Current number Register, offset: 0x000C */
    uint8 RESERVED4[ 8];                      /**< RESERVED4, offset: 0x0010 */
    uint32 INTE;                               /**< Interrupt Enable Register, offset: 0x0018 */
    uint32 SR;                                 /**< Status Register, offset: 0x001C */
    uint32 INMSG;                              /**< Input Message Register, offset: 0x0020 */
    uint32 OUTMSG;                             /**< Output Message Register, offset: 0x0024 */
    uint8 RESERVED9[ 8];                      /**< RESERVED9, offset: 0x0028 */
    uint32 KEY[ 4];                            /**< Key Register, offset: 0x0030 */
    uint8 RESERVED11[32];                     /**< RESERVED11, offset: 0x0040 */
    uint32 CONTEXT_4_7[ 4];                    /**< Context data 4~7 Register, offset: 0x0060 */
    uint32 CONTEXT_8_11[ 4];                   /**< Context data 8~11 Register, offset: 0x0070 */
    uint32 CONTEXT_12_19[ 8];                  /**< Context data 12~19 Register, offset: 0x0080 */
    uint8 RESERVED15[32];                     /**< RESERVED15, offset: 0x00A0 */
    uint32 CONTEXT_28_35[ 8];                  /**< Context data 28~35 Register, offset: 0x00C0 */
    uint8 RESERVED17[32];                     /**< RESERVED17, offset: 0x00E0 */
    uint32 PKEST;                              /**< PKE Start Register, offset: 0x0100 */
    uint32 PKECFG;                             /**< PKE Configuration Register, offset: 0x0104 */
    uint32 PKEIE;                              /**< PKE Interrupt Enable Register, offset: 0x0108 */
    uint32 PKESTAT;                            /**< PKE Status Register, offset: 0x010C */
    uint32 PKEA[128];                           /**< PKE Operand A Register, offset: 0x0110 */
    uint32 PKEE[128];                           /**< PKE Operand E Register, offset: 0x0310 */
    uint32 PKEN[128];                           /**< PKE Operand N Register, offset: 0x0510 */
    uint32 PKEAF;                              /**< PKE Operand A FIFO Register, offset: 0x0710 */
    uint32 PKEEF;                              /**< PKE Operand E FIFO Register, offset: 0x0714 */
    uint32 PKENF;                              /**< PKE Operand N FIFO Register, offset: 0x0718 */
    uint32 PKEFCNT;                            /**< PKE FIFO Count Register, offset: 0x071C */

} HCU_Type, *HCU_MemMapPtr;

/** Number of instances of the HCU module. */
#define HCU_INSTANCE_COUNT                        (1u)

/* HCU base address */
#define HCU_BASE_ADDR32                                   (0x40067000U)
#define HCU                                               ((volatile HCU_Type *)(HCU_BASE_ADDR32))

/** Array initializer of HCU peripheral base addresses */
#define HCU_BASE_ADDRS                                     { HCU_BASE_ADDR32 }
/** Array initializer of HCU peripheral base pointers */
#define HCU_BASE_PTRS                                      { HCU }

#define HCU_GO_OFFSET32                                    (0x0000U)                    /**< Offset for Go Register */
#define HCU_CR_OFFSET32                                    (0x0004U)                    /**< Offset for Configuration Register */
#define HCU_MSGINFO_OFFSET32                               (0x0008U)                    /**< Offset for Message Information Register */
#define HCU_MSGCUR_OFFSET32                                (0x000CU)                    /**< Offset for Message Current number Register */
#define HCU_INTE_OFFSET32                                  (0x0018U)                    /**< Offset for Interrupt Enable Register */
#define HCU_SR_OFFSET32                                    (0x001CU)                    /**< Offset for Status Register */
#define HCU_INMSG_OFFSET32                                 (0x0020U)                    /**< Offset for Input Message Register */
#define HCU_OUTMSG_OFFSET32                                (0x0024U)                    /**< Offset for Output Message Register */
#define HCU_KEY_OFFSET32(x)                                (0x0030U + ((x) * (4U)))     /**< Offset for Key Register */
#define HCU_CONTEXT_4_7_OFFSET32(x)                        (0x0060U + ((x) * (4U)))     /**< Offset for Context data 4~7 Register */
#define HCU_CONTEXT_8_11_OFFSET32(x)                       (0x0070U + ((x) * (4U)))     /**< Offset for Context data 8~11 Register */
#define HCU_CONTEXT_12_19_OFFSET32(x)                      (0x0080U + ((x) * (4U)))     /**< Offset for Context data 12~19 Register */
#define HCU_CONTEXT_28_35_OFFSET32(x)                      (0x00C0U + ((x) * (4U)))     /**< Offset for Context data 28~35 Register */
#define HCU_PKEST_OFFSET32                                 (0x0100U)                    /**< Offset for PKE Start Register */
#define HCU_PKECFG_OFFSET32                                (0x0104U)                    /**< Offset for PKE Configuration Register */
#define HCU_PKEIE_OFFSET32                                 (0x0108U)                    /**< Offset for PKE Interrupt Enable Register */
#define HCU_PKESTAT_OFFSET32                               (0x010CU)                    /**< Offset for PKE Status Register */
#define HCU_PKEA_OFFSET32(x)                               (0x0110U + ((x) * (4U)))     /**< Offset for PKE Operand A Register */
#define HCU_PKEE_OFFSET32(x)                               (0x0310U + ((x) * (4U)))     /**< Offset for PKE Operand E Register */
#define HCU_PKEN_OFFSET32(x)                               (0x0510U + ((x) * (4U)))     /**< Offset for PKE Operand N Register */
#define HCU_PKEAF_OFFSET32                                 (0x0710U)                    /**< Offset for PKE Operand A FIFO Register */
#define HCU_PKEEF_OFFSET32                                 (0x0714U)                    /**< Offset for PKE Operand E FIFO Register */
#define HCU_PKENF_OFFSET32                                 (0x0718U)                    /**< Offset for PKE Operand N FIFO Register */
#define HCU_PKEFCNT_OFFSET32                               (0x071CU)                    /**< Offset for PKE FIFO Count Register */


/**
 * @addtogroup HCU Register Mask
 * @{
 */
/* HCU_GO Register */
#define HCU_GO_GO_MASK                                     (0x1U)
#define HCU_GO_GO_SHIFT                                    (0U)
#define HCU_GO_GO(x)                                       (((uint32)(((uint32)(x)) << HCU_GO_GO_SHIFT)) & HCU_GO_GO_MASK)
/* HCU_CR Register */
#define HCU_CR_OUTDMAE_MASK                                (0x20000000U)
#define HCU_CR_OUTDMAE_SHIFT                               (29U)
#define HCU_CR_OUTDMAE(x)                                  (((uint32)(((uint32)(x)) << HCU_CR_OUTDMAE_SHIFT)) & HCU_CR_OUTDMAE_MASK)
#define HCU_CR_INDMAE_MASK                                 (0x10000000U)
#define HCU_CR_INDMAE_SHIFT                                (28U)
#define HCU_CR_INDMAE(x)                                   (((uint32)(((uint32)(x)) << HCU_CR_INDMAE_SHIFT)) & HCU_CR_INDMAE_MASK)
#define HCU_CR_SHAVE_MASK                                  (0x8000000U)
#define HCU_CR_SHAVE_SHIFT                                 (27U)
#define HCU_CR_SHAVE(x)                                    (((uint32)(((uint32)(x)) << HCU_CR_SHAVE_SHIFT)) & HCU_CR_SHAVE_MASK)
#define HCU_CR_CS_MASK                                     (0x800000U)
#define HCU_CR_CS_SHIFT                                    (23U)
#define HCU_CR_CS(x)                                       (((uint32)(((uint32)(x)) << HCU_CR_CS_SHIFT)) & HCU_CR_CS_MASK)
#define HCU_CR_MACLEN_MASK                                 (0x7F0000U)
#define HCU_CR_MACLEN_SHIFT                                (16U)
#define HCU_CR_MACLEN(x)                                   (((uint32)(((uint32)(x)) << HCU_CR_MACLEN_SHIFT)) & HCU_CR_MACLEN_MASK)
#define HCU_CR_ALGSEL_MASK                                 (0xF000U)
#define HCU_CR_ALGSEL_SHIFT                                (12U)
#define HCU_CR_ALGSEL(x)                                   (((uint32)(((uint32)(x)) << HCU_CR_ALGSEL_SHIFT)) & HCU_CR_ALGSEL_MASK)
#define HCU_CR_MSGB_MASK                                   (0x800U)
#define HCU_CR_MSGB_SHIFT                                  (11U)
#define HCU_CR_MSGB(x)                                     (((uint32)(((uint32)(x)) << HCU_CR_MSGB_SHIFT)) & HCU_CR_MSGB_MASK)
#define HCU_CR_MSGE_MASK                                   (0x400U)
#define HCU_CR_MSGE_SHIFT                                  (10U)
#define HCU_CR_MSGE(x)                                     (((uint32)(((uint32)(x)) << HCU_CR_MSGE_SHIFT)) & HCU_CR_MSGE_MASK)
#define HCU_CR_ENGSEL_MASK                                 (0xF0U)
#define HCU_CR_ENGSEL_SHIFT                                (4U)
#define HCU_CR_ENGSEL(x)                                   (((uint32)(((uint32)(x)) << HCU_CR_ENGSEL_SHIFT)) & HCU_CR_ENGSEL_MASK)
#define HCU_CR_DATSWP_MASK                                 (0xCU)
#define HCU_CR_DATSWP_SHIFT                                (2U)
#define HCU_CR_DATSWP(x)                                   (((uint32)(((uint32)(x)) << HCU_CR_DATSWP_SHIFT)) & HCU_CR_DATSWP_MASK)
#define HCU_CR_ENC_MASK                                    (0x2U)
#define HCU_CR_ENC_SHIFT                                   (1U)
#define HCU_CR_ENC(x)                                      (((uint32)(((uint32)(x)) << HCU_CR_ENC_SHIFT)) & HCU_CR_ENC_MASK)
/* HCU_MSGINFO Register */
#define HCU_MSGINFO_MSGTOT_MASK                            (0xFFFFFFFU)
#define HCU_MSGINFO_MSGTOT_SHIFT                           (0U)
#define HCU_MSGINFO_MSGTOT(x)                              (((uint32)(((uint32)(x)) << HCU_MSGINFO_MSGTOT_SHIFT)) & HCU_MSGINFO_MSGTOT_MASK)
/* HCU_MSGCUR Register */
#define HCU_MSGCUR_MSGLEN_MASK                             (0xFFFFU)
#define HCU_MSGCUR_MSGLEN_SHIFT                            (0U)
#define HCU_MSGCUR_MSGLEN(x)                               (((uint32)(((uint32)(x)) << HCU_MSGCUR_MSGLEN_SHIFT)) & HCU_MSGCUR_MSGLEN_MASK)
/* HCU_INTE Register */
#define HCU_INTE_INMSGWIE_MASK                             (0x80000000U)
#define HCU_INTE_INMSGWIE_SHIFT                            (31U)
#define HCU_INTE_INMSGWIE(x)                               (((uint32)(((uint32)(x)) << HCU_INTE_INMSGWIE_SHIFT)) & HCU_INTE_INMSGWIE_MASK)
#define HCU_INTE_OUTMSGRIE_MASK                            (0x40000000U)
#define HCU_INTE_OUTMSGRIE_SHIFT                           (30U)
#define HCU_INTE_OUTMSGRIE(x)                              (((uint32)(((uint32)(x)) << HCU_INTE_OUTMSGRIE_SHIFT)) & HCU_INTE_OUTMSGRIE_MASK)
#define HCU_INTE_KEYWIE_MASK                               (0x20000000U)
#define HCU_INTE_KEYWIE_SHIFT                              (29U)
#define HCU_INTE_KEYWIE(x)                                 (((uint32)(((uint32)(x)) << HCU_INTE_KEYWIE_SHIFT)) & HCU_INTE_KEYWIE_MASK)
#define HCU_INTE_AESIVWIE_MASK                             (0x10000000U)
#define HCU_INTE_AESIVWIE_SHIFT                            (28U)
#define HCU_INTE_AESIVWIE(x)                               (((uint32)(((uint32)(x)) << HCU_INTE_AESIVWIE_SHIFT)) & HCU_INTE_AESIVWIE_MASK)
#define HCU_INTE_AESMACRIE_MASK                            (0x8000000U)
#define HCU_INTE_AESMACRIE_SHIFT                           (27U)
#define HCU_INTE_AESMACRIE(x)                              (((uint32)(((uint32)(x)) << HCU_INTE_AESMACRIE_SHIFT)) & HCU_INTE_AESMACRIE_MASK)
#define HCU_INTE_AESMACWIE_MASK                            (0x4000000U)
#define HCU_INTE_AESMACWIE_SHIFT                           (26U)
#define HCU_INTE_AESMACWIE(x)                              (((uint32)(((uint32)(x)) << HCU_INTE_AESMACWIE_SHIFT)) & HCU_INTE_AESMACWIE_MASK)
#define HCU_INTE_AESIVRIE_MASK                             (0x800000U)
#define HCU_INTE_AESIVRIE_SHIFT                            (23U)
#define HCU_INTE_AESIVRIE(x)                               (((uint32)(((uint32)(x)) << HCU_INTE_AESIVRIE_SHIFT)) & HCU_INTE_AESIVRIE_MASK)
#define HCU_INTE_SHAICVWIE_MASK                            (0x400000U)
#define HCU_INTE_SHAICVWIE_SHIFT                           (22U)
#define HCU_INTE_SHAICVWIE(x)                              (((uint32)(((uint32)(x)) << HCU_INTE_SHAICVWIE_SHIFT)) & HCU_INTE_SHAICVWIE_MASK)
#define HCU_INTE_SHACTXWIE_MASK                            (0x200000U)
#define HCU_INTE_SHACTXWIE_SHIFT                           (21U)
#define HCU_INTE_SHACTXWIE(x)                              (((uint32)(((uint32)(x)) << HCU_INTE_SHACTXWIE_SHIFT)) & HCU_INTE_SHACTXWIE_MASK)
#define HCU_INTE_SHACTXRIE_MASK                            (0x100000U)
#define HCU_INTE_SHACTXRIE_SHIFT                           (20U)
#define HCU_INTE_SHACTXRIE(x)                              (((uint32)(((uint32)(x)) << HCU_INTE_SHACTXRIE_SHIFT)) & HCU_INTE_SHACTXRIE_MASK)
#define HCU_INTE_ODIE_MASK                                 (0x1U)
#define HCU_INTE_ODIE_SHIFT                                (0U)
#define HCU_INTE_ODIE(x)                                   (((uint32)(((uint32)(x)) << HCU_INTE_ODIE_SHIFT)) & HCU_INTE_ODIE_MASK)
/* HCU_SR Register */
#define HCU_SR_INMSGW_MASK                                 (0x80000000U)
#define HCU_SR_INMSGW_SHIFT                                (31U)
#define HCU_SR_INMSGW(x)                                   (((uint32)(((uint32)(x)) << HCU_SR_INMSGW_SHIFT)) & HCU_SR_INMSGW_MASK)
#define HCU_SR_OUTMSGR_MASK                                (0x40000000U)
#define HCU_SR_OUTMSGR_SHIFT                               (30U)
#define HCU_SR_OUTMSGR(x)                                  (((uint32)(((uint32)(x)) << HCU_SR_OUTMSGR_SHIFT)) & HCU_SR_OUTMSGR_MASK)
#define HCU_SR_KEYW_MASK                                   (0x20000000U)
#define HCU_SR_KEYW_SHIFT                                  (29U)
#define HCU_SR_KEYW(x)                                     (((uint32)(((uint32)(x)) << HCU_SR_KEYW_SHIFT)) & HCU_SR_KEYW_MASK)
#define HCU_SR_AESIVW_MASK                                 (0x10000000U)
#define HCU_SR_AESIVW_SHIFT                                (28U)
#define HCU_SR_AESIVW(x)                                   (((uint32)(((uint32)(x)) << HCU_SR_AESIVW_SHIFT)) & HCU_SR_AESIVW_MASK)
#define HCU_SR_AESMACR_MASK                                (0x8000000U)
#define HCU_SR_AESMACR_SHIFT                               (27U)
#define HCU_SR_AESMACR(x)                                  (((uint32)(((uint32)(x)) << HCU_SR_AESMACR_SHIFT)) & HCU_SR_AESMACR_MASK)
#define HCU_SR_AESMACW_MASK                                (0x4000000U)
#define HCU_SR_AESMACW_SHIFT                               (26U)
#define HCU_SR_AESMACW(x)                                  (((uint32)(((uint32)(x)) << HCU_SR_AESMACW_SHIFT)) & HCU_SR_AESMACW_MASK)
#define HCU_SR_AESIVR_MASK                                 (0x800000U)
#define HCU_SR_AESIVR_SHIFT                                (23U)
#define HCU_SR_AESIVR(x)                                   (((uint32)(((uint32)(x)) << HCU_SR_AESIVR_SHIFT)) & HCU_SR_AESIVR_MASK)
#define HCU_SR_SHAICVW_MASK                                (0x400000U)
#define HCU_SR_SHAICVW_SHIFT                               (22U)
#define HCU_SR_SHAICVW(x)                                  (((uint32)(((uint32)(x)) << HCU_SR_SHAICVW_SHIFT)) & HCU_SR_SHAICVW_MASK)
#define HCU_SR_SHACTXW_MASK                                (0x200000U)
#define HCU_SR_SHACTXW_SHIFT                               (21U)
#define HCU_SR_SHACTXW(x)                                  (((uint32)(((uint32)(x)) << HCU_SR_SHACTXW_SHIFT)) & HCU_SR_SHACTXW_MASK)
#define HCU_SR_SHACTXR_MASK                                (0x100000U)
#define HCU_SR_SHACTXR_SHIFT                               (20U)
#define HCU_SR_SHACTXR(x)                                  (((uint32)(((uint32)(x)) << HCU_SR_SHACTXR_SHIFT)) & HCU_SR_SHACTXR_MASK)
#define HCU_SR_SHAIVAL_MASK                                (0x4U)
#define HCU_SR_SHAIVAL_SHIFT                               (2U)
#define HCU_SR_SHAIVAL(x)                                  (((uint32)(((uint32)(x)) << HCU_SR_SHAIVAL_SHIFT)) & HCU_SR_SHAIVAL_MASK)
#define HCU_SR_AESVAL_MASK                                 (0x2U)
#define HCU_SR_AESVAL_SHIFT                                (1U)
#define HCU_SR_AESVAL(x)                                   (((uint32)(((uint32)(x)) << HCU_SR_AESVAL_SHIFT)) & HCU_SR_AESVAL_MASK)
#define HCU_SR_OD_MASK                                     (0x1U)
#define HCU_SR_OD_SHIFT                                    (0U)
#define HCU_SR_OD(x)                                       (((uint32)(((uint32)(x)) << HCU_SR_OD_SHIFT)) & HCU_SR_OD_MASK)
/* HCU_INMSG Register */
#define HCU_INMSG_INMSG_MASK                               (0xFFFFFFFFU)
#define HCU_INMSG_INMSG_SHIFT                              (0U)
#define HCU_INMSG_INMSG(x)                                 (((uint32)(((uint32)(x)) << HCU_INMSG_INMSG_SHIFT)) & HCU_INMSG_INMSG_MASK)
/* HCU_OUTMSG Register */
#define HCU_OUTMSG_OUTMSG_MASK                             (0xFFFFFFFFU)
#define HCU_OUTMSG_OUTMSG_SHIFT                            (0U)
#define HCU_OUTMSG_OUTMSG(x)                               (((uint32)(((uint32)(x)) << HCU_OUTMSG_OUTMSG_SHIFT)) & HCU_OUTMSG_OUTMSG_MASK)
/* HCU_KEY Register */
#define HCU_KEY_KEY_MASK                                   (0xFFFFFFFFU)
#define HCU_KEY_KEY_SHIFT                                  (0U)
#define HCU_KEY_KEY(x)                                     (((uint32)(((uint32)(x)) << HCU_KEY_KEY_SHIFT)) & HCU_KEY_KEY_MASK)
/* HCU_CONTEXT_4_7 Register */
#define HCU_CONTEXT_4_7_CONTEXT_MASK                       (0xFFFFFFFFU)
#define HCU_CONTEXT_4_7_CONTEXT_SHIFT                      (0U)
#define HCU_CONTEXT_4_7_CONTEXT(x)                         (((uint32)(((uint32)(x)) << HCU_CONTEXT_4_7_CONTEXT_SHIFT)) & HCU_CONTEXT_4_7_CONTEXT_MASK)
/* HCU_CONTEXT_8_11 Register */
#define HCU_CONTEXT_8_11_CONTEXT_MASK                      (0xFFFFFFFFU)
#define HCU_CONTEXT_8_11_CONTEXT_SHIFT                     (0U)
#define HCU_CONTEXT_8_11_CONTEXT(x)                        (((uint32)(((uint32)(x)) << HCU_CONTEXT_8_11_CONTEXT_SHIFT)) & HCU_CONTEXT_8_11_CONTEXT_MASK)
/* HCU_CONTEXT_12_19 Register */
#define HCU_CONTEXT_12_19_CONTEXT_MASK                     (0xFFFFFFFFU)
#define HCU_CONTEXT_12_19_CONTEXT_SHIFT                    (0U)
#define HCU_CONTEXT_12_19_CONTEXT(x)                       (((uint32)(((uint32)(x)) << HCU_CONTEXT_12_19_CONTEXT_SHIFT)) & HCU_CONTEXT_12_19_CONTEXT_MASK)
/* HCU_CONTEXT_28_35 Register */
#define HCU_CONTEXT_28_35_CONTEXT_MASK                     (0xFFFFFFFFU)
#define HCU_CONTEXT_28_35_CONTEXT_SHIFT                    (0U)
#define HCU_CONTEXT_28_35_CONTEXT(x)                       (((uint32)(((uint32)(x)) << HCU_CONTEXT_28_35_CONTEXT_SHIFT)) & HCU_CONTEXT_28_35_CONTEXT_MASK)
/* HCU_PKEST Register */
#define HCU_PKEST_ST_MASK                                  (0x1U)
#define HCU_PKEST_ST_SHIFT                                 (0U)
#define HCU_PKEST_ST(x)                                    (((uint32)(((uint32)(x)) << HCU_PKEST_ST_SHIFT)) & HCU_PKEST_ST_MASK)
/* HCU_PKECFG Register */
#define HCU_PKECFG_EOS_MASK                                (0x7F000000U)
#define HCU_PKECFG_EOS_SHIFT                               (24U)
#define HCU_PKECFG_EOS(x)                                  (((uint32)(((uint32)(x)) << HCU_PKECFG_EOS_SHIFT)) & HCU_PKECFG_EOS_MASK)
#define HCU_PKECFG_OOM_MASK                                (0x7F0000U)
#define HCU_PKECFG_OOM_SHIFT                               (16U)
#define HCU_PKECFG_OOM(x)                                  (((uint32)(((uint32)(x)) << HCU_PKECFG_OOM_SHIFT)) & HCU_PKECFG_OOM_MASK)
#define HCU_PKECFG_BE_MASK                                 (0x8000U)
#define HCU_PKECFG_BE_SHIFT                                (15U)
#define HCU_PKECFG_BE(x)                                   (((uint32)(((uint32)(x)) << HCU_PKECFG_BE_SHIFT)) & HCU_PKECFG_BE_MASK)
#define HCU_PKECFG_FIFOEN_MASK                             (0x4000U)
#define HCU_PKECFG_FIFOEN_SHIFT                            (14U)
#define HCU_PKECFG_FIFOEN(x)                               (((uint32)(((uint32)(x)) << HCU_PKECFG_FIFOEN_SHIFT)) & HCU_PKECFG_FIFOEN_MASK)
#define HCU_PKECFG_CMD_MASK                                (0xF00U)
#define HCU_PKECFG_CMD_SHIFT                               (8U)
#define HCU_PKECFG_CMD(x)                                  (((uint32)(((uint32)(x)) << HCU_PKECFG_CMD_SHIFT)) & HCU_PKECFG_CMD_MASK)
#define HCU_PKECFG_FC_MASK                                 (0x80U)
#define HCU_PKECFG_FC_SHIFT                                (7U)
#define HCU_PKECFG_FC(x)                                   (((uint32)(((uint32)(x)) << HCU_PKECFG_FC_SHIFT)) & HCU_PKECFG_FC_MASK)
#define HCU_PKECFG_DC_MASK                                 (0x40U)
#define HCU_PKECFG_DC_SHIFT                                (6U)
#define HCU_PKECFG_DC(x)                                   (((uint32)(((uint32)(x)) << HCU_PKECFG_DC_SHIFT)) & HCU_PKECFG_DC_MASK)
#define HCU_PKECFG_ECCSUB_MASK                             (0x20U)
#define HCU_PKECFG_ECCSUB_SHIFT                            (5U)
#define HCU_PKECFG_ECCSUB(x)                               (((uint32)(((uint32)(x)) << HCU_PKECFG_ECCSUB_SHIFT)) & HCU_PKECFG_ECCSUB_MASK)
#define HCU_PKECFG_R2DIS_MASK                              (0x10U)
#define HCU_PKECFG_R2DIS_SHIFT                             (4U)
#define HCU_PKECFG_R2DIS(x)                                (((uint32)(((uint32)(x)) << HCU_PKECFG_R2DIS_SHIFT)) & HCU_PKECFG_R2DIS_MASK)
#define HCU_PKECFG_EXPFEN_MASK                             (0x8U)
#define HCU_PKECFG_EXPFEN_SHIFT                            (3U)
#define HCU_PKECFG_EXPFEN(x)                               (((uint32)(((uint32)(x)) << HCU_PKECFG_EXPFEN_SHIFT)) & HCU_PKECFG_EXPFEN_MASK)
#define HCU_PKECFG_RST_MASK                                (0x1U)
#define HCU_PKECFG_RST_SHIFT                               (0U)
#define HCU_PKECFG_RST(x)                                  (((uint32)(((uint32)(x)) << HCU_PKECFG_RST_SHIFT)) & HCU_PKECFG_RST_MASK)
/* HCU_PKEIE Register */
#define HCU_PKEIE_IE_MASK                                  (0x1U)
#define HCU_PKEIE_IE_SHIFT                                 (0U)
#define HCU_PKEIE_IE(x)                                    (((uint32)(((uint32)(x)) << HCU_PKEIE_IE_SHIFT)) & HCU_PKEIE_IE_MASK)
/* HCU_PKESTAT Register */
#define HCU_PKESTAT_DONE_MASK                              (0x1U)
#define HCU_PKESTAT_DONE_SHIFT                             (0U)
#define HCU_PKESTAT_DONE(x)                                (((uint32)(((uint32)(x)) << HCU_PKESTAT_DONE_SHIFT)) & HCU_PKESTAT_DONE_MASK)
/* HCU_PKEA Register */
#define HCU_PKEA_A_MASK                                    (0xFFFFFFFFU)
#define HCU_PKEA_A_SHIFT                                   (0U)
#define HCU_PKEA_A(x)                                      (((uint32)(((uint32)(x)) << HCU_PKEA_A_SHIFT)) & HCU_PKEA_A_MASK)
/* HCU_PKEE Register */
#define HCU_PKEE_E_MASK                                    (0xFFFFFFFFU)
#define HCU_PKEE_E_SHIFT                                   (0U)
#define HCU_PKEE_E(x)                                      (((uint32)(((uint32)(x)) << HCU_PKEE_E_SHIFT)) & HCU_PKEE_E_MASK)
/* HCU_PKEN Register */
#define HCU_PKEN_N_MASK                                    (0xFFFFFFFFU)
#define HCU_PKEN_N_SHIFT                                   (0U)
#define HCU_PKEN_N(x)                                      (((uint32)(((uint32)(x)) << HCU_PKEN_N_SHIFT)) & HCU_PKEN_N_MASK)
/* HCU_PKEAF Register */
#define HCU_PKEAF_A_MASK                                   (0xFFFFFFFFU)
#define HCU_PKEAF_A_SHIFT                                  (0U)
#define HCU_PKEAF_A(x)                                     (((uint32)(((uint32)(x)) << HCU_PKEAF_A_SHIFT)) & HCU_PKEAF_A_MASK)
/* HCU_PKEEF Register */
#define HCU_PKEEF_E_MASK                                   (0xFFFFFFFFU)
#define HCU_PKEEF_E_SHIFT                                  (0U)
#define HCU_PKEEF_E(x)                                     (((uint32)(((uint32)(x)) << HCU_PKEEF_E_SHIFT)) & HCU_PKEEF_E_MASK)
/* HCU_PKENF Register */
#define HCU_PKENF_N_MASK                                   (0xFFFFFFFFU)
#define HCU_PKENF_N_SHIFT                                  (0U)
#define HCU_PKENF_N(x)                                     (((uint32)(((uint32)(x)) << HCU_PKENF_N_SHIFT)) & HCU_PKENF_N_MASK)
/* HCU_PKEFCNT Register */
#define HCU_PKEFCNT_CLR_MASK                               (0x80000000U)
#define HCU_PKEFCNT_CLR_SHIFT                              (31U)
#define HCU_PKEFCNT_CLR(x)                                 (((uint32)(((uint32)(x)) << HCU_PKEFCNT_CLR_SHIFT)) & HCU_PKEFCNT_CLR_MASK)
#define HCU_PKEFCNT_FCNT_MASK                              (0xFFU)
#define HCU_PKEFCNT_FCNT_SHIFT                             (0U)
#define HCU_PKEFCNT_FCNT(x)                                (((uint32)(((uint32)(x)) << HCU_PKEFCNT_FCNT_SHIFT)) & HCU_PKEFCNT_FCNT_MASK)


/**
 * @}
 */ /* end of group HCU_Register_Masks */


/**
 * @}
 */ /* end of group HCU_Peripheral_Access_Layer */

#endif /* PSIP_HCU_H */
