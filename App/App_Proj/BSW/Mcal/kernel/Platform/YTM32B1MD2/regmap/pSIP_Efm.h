/**
*   @file    pSIP_Efm.h
*   @version
*
*   @brief   AUTOSAR Efm register map
*   @details Register map for EFM
*
*   @addtogroup EFM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Efm
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

#ifndef PSIP_EFM_H
#define PSIP_EFM_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              EFM REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup EFM_Peripheral_Access_Layer EFM Peripheral Access Layer
 * @{
 */


/** EFM - Size of Registers Arrays */
#define EFM_ADDR_PROT_COUNT           (3)

/* EFM Register Layout Typedef */
typedef struct
{
    uint32 CTRL;                               /**< Control Register, offset: 0x0000 */
    uint32 STS;                                /**< Status Register, offset: 0x0004 */
    uint32 CMD;                                /**< Command Register, offset: 0x0008 */
    uint32 CMD_PROT;                           /**< Command Protect Register, offset: 0x000C */
    uint32 TIMING1;                            /**< Timing 1 Control Register, offset: 0x0010 */
    uint32 TIMING2;                            /**< Timing 2 Control Register, offset: 0x0014 */
    uint8 RESERVED6[ 8];                      /**< RESERVED6, offset: 0x0018 */
    uint32 ERR_INJECT_CTRL;                    /**< Error Inject Control, offset: 0x0020 */
    uint32 ADDR_PROT[ 3];                      /**< Flash Partition Protect Register, offset: 0x0024 */
    uint32 ECCERR_ADDR;                        /**< ECC Error Address, offset: 0x0030 */
    uint32 ECCERR_CNT;                         /**< ECC Error Count, offset: 0x0034 */
    uint8 RESERVED11[200];                     /**< RESERVED11, offset: 0x0038 */
    uint32 RSA_KEY_CFG;                        /**< RSA_KEY Config, offset: 0x0100 */
    uint8 RESERVED13[252];                     /**< RESERVED13, offset: 0x0104 */
    uint32 CMD_UNLOCK;                         /**< EFM Command Unlock, offset: 0x0200 */
    uint32 CUS_KEY;                            /**< EFM Customer Key, offset: 0x0204 */
    uint8 RESERVED16[248];                     /**< RESERVED16, offset: 0x0208 */
    uint32 CTRL_OVRD;                          /**< Override Control Register, offset: 0x0300 */
    uint32 RESERVED18;                         /**< RESERVED18, offset: 0x0304 */
    uint32 RESERVED19;                         /**< RESERVED19, offset: 0x0308 */
    uint8 RESERVED20[116];                     /**< RESERVED20, offset: 0x030C */
    uint32 RESERVED21;                         /**< RESERVED21, offset: 0x0380 */
    uint32 RESERVED22;                         /**< RESERVED22, offset: 0x0384 */

} EFM_Type, *EFM_MemMapPtr;

/** Number of instances of the EFM module. */
#define EFM_INSTANCE_COUNT                        (1u)

/* EFM base address */
#define EFM_BASE_ADDR32                                   (0x40010000U)
#define EFM                                               ((volatile EFM_Type *)(EFM_BASE_ADDR32))

/** Array initializer of EFM peripheral base addresses */
#define EFM_BASE_ADDRS                                     { EFM_BASE_ADDR32 }
/** Array initializer of EFM peripheral base pointers */
#define EFM_BASE_PTRS                                      { EFM }

#define EFM_CTRL_OFFSET32                                  (0x0000U)                    /**< Offset for Control Register */
#define EFM_STS_OFFSET32                                   (0x0004U)                    /**< Offset for Status Register */
#define EFM_CMD_OFFSET32                                   (0x0008U)                    /**< Offset for Command Register */
#define EFM_CMD_PROT_OFFSET32                              (0x000CU)                    /**< Offset for Command Protect Register */
#define EFM_TIMING1_OFFSET32                               (0x0010U)                    /**< Offset for Timing 1 Control Register */
#define EFM_TIMING2_OFFSET32                               (0x0014U)                    /**< Offset for Timing 2 Control Register */
#define EFM_ERR_INJECT_CTRL_OFFSET32                       (0x0020U)                    /**< Offset for Error Inject Control */
#define EFM_ADDR_PROT_OFFSET32(x)                          (0x0024U + ((x) * (4U)))     /**< Offset for Flash Partition Protect Register */
#define EFM_ECCERR_ADDR_OFFSET32                           (0x0030U)                    /**< Offset for ECC Error Address */
#define EFM_ECCERR_CNT_OFFSET32                            (0x0034U)                    /**< Offset for ECC Error Count */
#define EFM_RSA_KEY_CFG_OFFSET32                           (0x0100U)                    /**< Offset for RSA_KEY Config */
#define EFM_CMD_UNLOCK_OFFSET32                            (0x0200U)                    /**< Offset for EFM Command Unlock */
#define EFM_CUS_KEY_OFFSET32                               (0x0204U)                    /**< Offset for EFM Customer Key */
#define EFM_CTRL_OVRD_OFFSET32                             (0x0300U)                    /**< Offset for Override Control Register */


/**
 * @addtogroup EFM Register Mask
 * @{
 */
/* EFM_CTRL Register */
#define EFM_CTRL_LPEN_MASK                                 (0x80000000U)
#define EFM_CTRL_LPEN_SHIFT                                (31U)
#define EFM_CTRL_LPEN(x)                                   (((uint32)(((uint32)(x)) << EFM_CTRL_LPEN_SHIFT)) & EFM_CTRL_LPEN_MASK)
#define EFM_CTRL_FWUP_EN_MASK                              (0x40000000U)
#define EFM_CTRL_FWUP_EN_SHIFT                             (30U)
#define EFM_CTRL_FWUP_EN(x)                                (((uint32)(((uint32)(x)) << EFM_CTRL_FWUP_EN_SHIFT)) & EFM_CTRL_FWUP_EN_MASK)
#define EFM_CTRL_PRESCALER_MASK                            (0x3F0000U)
#define EFM_CTRL_PRESCALER_SHIFT                           (16U)
#define EFM_CTRL_PRESCALER(x)                              (((uint32)(((uint32)(x)) << EFM_CTRL_PRESCALER_SHIFT)) & EFM_CTRL_PRESCALER_MASK)
#define EFM_CTRL_WE_MASK                                   (0x1000U)
#define EFM_CTRL_WE_SHIFT                                  (12U)
#define EFM_CTRL_WE(x)                                     (((uint32)(((uint32)(x)) << EFM_CTRL_WE_SHIFT)) & EFM_CTRL_WE_MASK)
#define EFM_CTRL_RWS_MASK                                  (0x300U)
#define EFM_CTRL_RWS_SHIFT                                 (8U)
#define EFM_CTRL_RWS(x)                                    (((uint32)(((uint32)(x)) << EFM_CTRL_RWS_SHIFT)) & EFM_CTRL_RWS_MASK)
#define EFM_CTRL_CMD_VERIFY_EN_MASK                        (0x10U)
#define EFM_CTRL_CMD_VERIFY_EN_SHIFT                       (4U)
#define EFM_CTRL_CMD_VERIFY_EN(x)                          (((uint32)(((uint32)(x)) << EFM_CTRL_CMD_VERIFY_EN_SHIFT)) & EFM_CTRL_CMD_VERIFY_EN_MASK)
#define EFM_CTRL_ACCERRIE_MASK                             (0x8U)
#define EFM_CTRL_ACCERRIE_SHIFT                            (3U)
#define EFM_CTRL_ACCERRIE(x)                               (((uint32)(((uint32)(x)) << EFM_CTRL_ACCERRIE_SHIFT)) & EFM_CTRL_ACCERRIE_MASK)
#define EFM_CTRL_UNRECOVERRIE_MASK                         (0x4U)
#define EFM_CTRL_UNRECOVERRIE_SHIFT                        (2U)
#define EFM_CTRL_UNRECOVERRIE(x)                           (((uint32)(((uint32)(x)) << EFM_CTRL_UNRECOVERRIE_SHIFT)) & EFM_CTRL_UNRECOVERRIE_MASK)
#define EFM_CTRL_RECOVERRIE_MASK                           (0x2U)
#define EFM_CTRL_RECOVERRIE_SHIFT                          (1U)
#define EFM_CTRL_RECOVERRIE(x)                             (((uint32)(((uint32)(x)) << EFM_CTRL_RECOVERRIE_SHIFT)) & EFM_CTRL_RECOVERRIE_MASK)
#define EFM_CTRL_DONEIE_MASK                               (0x1U)
#define EFM_CTRL_DONEIE_SHIFT                              (0U)
#define EFM_CTRL_DONEIE(x)                                 (((uint32)(((uint32)(x)) << EFM_CTRL_DONEIE_SHIFT)) & EFM_CTRL_DONEIE_MASK)
/* EFM_STS Register */
#define EFM_STS_CI_RDVIOLERR_MASK                          (0x4000000U)
#define EFM_STS_CI_RDVIOLERR_SHIFT                         (26U)
#define EFM_STS_CI_RDVIOLERR(x)                            (((uint32)(((uint32)(x)) << EFM_STS_CI_RDVIOLERR_SHIFT)) & EFM_STS_CI_RDVIOLERR_MASK)
#define EFM_STS_CI_WEERR_MASK                              (0x2000000U)
#define EFM_STS_CI_WEERR_SHIFT                             (25U)
#define EFM_STS_CI_WEERR(x)                                (((uint32)(((uint32)(x)) << EFM_STS_CI_WEERR_SHIFT)) & EFM_STS_CI_WEERR_MASK)
#define EFM_STS_CI_BUSYERR_MASK                            (0x1000000U)
#define EFM_STS_CI_BUSYERR_SHIFT                           (24U)
#define EFM_STS_CI_BUSYERR(x)                              (((uint32)(((uint32)(x)) << EFM_STS_CI_BUSYERR_SHIFT)) & EFM_STS_CI_BUSYERR_MASK)
#define EFM_STS_BOOT_INFO_MASK                             (0x8000U)
#define EFM_STS_BOOT_INFO_SHIFT                            (15U)
#define EFM_STS_BOOT_INFO(x)                               (((uint32)(((uint32)(x)) << EFM_STS_BOOT_INFO_SHIFT)) & EFM_STS_BOOT_INFO_MASK)
#define EFM_STS_IDLE_MASK                                  (0x80U)
#define EFM_STS_IDLE_SHIFT                                 (7U)
#define EFM_STS_IDLE(x)                                    (((uint32)(((uint32)(x)) << EFM_STS_IDLE_SHIFT)) & EFM_STS_IDLE_MASK)
#define EFM_STS_ARRAY_SELECTED_MASK                        (0x40U)
#define EFM_STS_ARRAY_SELECTED_SHIFT                       (6U)
#define EFM_STS_ARRAY_SELECTED(x)                          (((uint32)(((uint32)(x)) << EFM_STS_ARRAY_SELECTED_SHIFT)) & EFM_STS_ARRAY_SELECTED_MASK)
#define EFM_STS_CMD_FAIL_MASK                              (0x10U)
#define EFM_STS_CMD_FAIL_SHIFT                             (4U)
#define EFM_STS_CMD_FAIL(x)                                (((uint32)(((uint32)(x)) << EFM_STS_CMD_FAIL_SHIFT)) & EFM_STS_CMD_FAIL_MASK)
#define EFM_STS_ACCERR_MASK                                (0x8U)
#define EFM_STS_ACCERR_SHIFT                               (3U)
#define EFM_STS_ACCERR(x)                                  (((uint32)(((uint32)(x)) << EFM_STS_ACCERR_SHIFT)) & EFM_STS_ACCERR_MASK)
#define EFM_STS_UNRECOVERR_MASK                            (0x4U)
#define EFM_STS_UNRECOVERR_SHIFT                           (2U)
#define EFM_STS_UNRECOVERR(x)                              (((uint32)(((uint32)(x)) << EFM_STS_UNRECOVERR_SHIFT)) & EFM_STS_UNRECOVERR_MASK)
#define EFM_STS_RECOVERR_MASK                              (0x2U)
#define EFM_STS_RECOVERR_SHIFT                             (1U)
#define EFM_STS_RECOVERR(x)                                (((uint32)(((uint32)(x)) << EFM_STS_RECOVERR_SHIFT)) & EFM_STS_RECOVERR_MASK)
#define EFM_STS_DONE_MASK                                  (0x1U)
#define EFM_STS_DONE_SHIFT                                 (0U)
#define EFM_STS_DONE(x)                                    (((uint32)(((uint32)(x)) << EFM_STS_DONE_SHIFT)) & EFM_STS_DONE_MASK)
/* EFM_CMD Register */
#define EFM_CMD_CMD_MASK                                   (0xFFU)
#define EFM_CMD_CMD_SHIFT                                  (0U)
#define EFM_CMD_CMD(x)                                     (((uint32)(((uint32)(x)) << EFM_CMD_CMD_SHIFT)) & EFM_CMD_CMD_MASK)
/* EFM_CMD_PROT Register */
#define EFM_CMD_PROT_CMD_PROT_MASK                         (0xFFFFFFFFU)
#define EFM_CMD_PROT_CMD_PROT_SHIFT                        (0U)
#define EFM_CMD_PROT_CMD_PROT(x)                           (((uint32)(((uint32)(x)) << EFM_CMD_PROT_CMD_PROT_SHIFT)) & EFM_CMD_PROT_CMD_PROT_MASK)
/* EFM_TIMING1 Register */
#define EFM_TIMING1_TPROG_SEL_MASK                         (0x3U)
#define EFM_TIMING1_TPROG_SEL_SHIFT                        (0U)
#define EFM_TIMING1_TPROG_SEL(x)                           (((uint32)(((uint32)(x)) << EFM_TIMING1_TPROG_SEL_SHIFT)) & EFM_TIMING1_TPROG_SEL_MASK)
/* EFM_TIMING2 Register */
#define EFM_TIMING2_TERASE_BLK_SEL_MASK                    (0x30000U)
#define EFM_TIMING2_TERASE_BLK_SEL_SHIFT                   (16U)
#define EFM_TIMING2_TERASE_BLK_SEL(x)                      (((uint32)(((uint32)(x)) << EFM_TIMING2_TERASE_BLK_SEL_SHIFT)) & EFM_TIMING2_TERASE_BLK_SEL_MASK)
#define EFM_TIMING2_TERASE_SEC_SEL_MASK                    (0x3U)
#define EFM_TIMING2_TERASE_SEC_SEL_SHIFT                   (0U)
#define EFM_TIMING2_TERASE_SEC_SEL(x)                      (((uint32)(((uint32)(x)) << EFM_TIMING2_TERASE_SEC_SEL_SHIFT)) & EFM_TIMING2_TERASE_SEC_SEL_MASK)
/* EFM_ERR_INJECT_CTRL Register */
#define EFM_ERR_INJECT_CTRL_ECCERR_INJ_EN_MASK             (0xC0000000U)
#define EFM_ERR_INJECT_CTRL_ECCERR_INJ_EN_SHIFT            (30U)
#define EFM_ERR_INJECT_CTRL_ECCERR_INJ_EN(x)               (((uint32)(((uint32)(x)) << EFM_ERR_INJECT_CTRL_ECCERR_INJ_EN_SHIFT)) & EFM_ERR_INJECT_CTRL_ECCERR_INJ_EN_MASK)
/* EFM_ADDR_PROT Register */
#define EFM_ADDR_PROT_ADDR_PROT_MASK                       (0xFFFFFFFFU)
#define EFM_ADDR_PROT_ADDR_PROT_SHIFT                      (0U)
#define EFM_ADDR_PROT_ADDR_PROT(x)                         (((uint32)(((uint32)(x)) << EFM_ADDR_PROT_ADDR_PROT_SHIFT)) & EFM_ADDR_PROT_ADDR_PROT_MASK)
/* EFM_ECCERR_ADDR Register */
#define EFM_ECCERR_ADDR_ERR_FLASH_ADDR_MASK                (0xFFFFFFFFU)
#define EFM_ECCERR_ADDR_ERR_FLASH_ADDR_SHIFT               (0U)
#define EFM_ECCERR_ADDR_ERR_FLASH_ADDR(x)                  (((uint32)(((uint32)(x)) << EFM_ECCERR_ADDR_ERR_FLASH_ADDR_SHIFT)) & EFM_ECCERR_ADDR_ERR_FLASH_ADDR_MASK)
/* EFM_ECCERR_CNT Register */
#define EFM_ECCERR_CNT_ECCERR_INJ_ST_MASK                  (0x80000000U)
#define EFM_ECCERR_CNT_ECCERR_INJ_ST_SHIFT                 (31U)
#define EFM_ECCERR_CNT_ECCERR_INJ_ST(x)                    (((uint32)(((uint32)(x)) << EFM_ECCERR_CNT_ECCERR_INJ_ST_SHIFT)) & EFM_ECCERR_CNT_ECCERR_INJ_ST_MASK)
#define EFM_ECCERR_CNT_ECCERR_CNT_MASK                     (0xFFFFU)
#define EFM_ECCERR_CNT_ECCERR_CNT_SHIFT                    (0U)
#define EFM_ECCERR_CNT_ECCERR_CNT(x)                       (((uint32)(((uint32)(x)) << EFM_ECCERR_CNT_ECCERR_CNT_SHIFT)) & EFM_ECCERR_CNT_ECCERR_CNT_MASK)
/* EFM_RSA_KEY_CFG Register */
#define EFM_RSA_KEY_CFG_RSA_KEY_NUM_MASK                   (0x7FU)
#define EFM_RSA_KEY_CFG_RSA_KEY_NUM_SHIFT                  (0U)
#define EFM_RSA_KEY_CFG_RSA_KEY_NUM(x)                     (((uint32)(((uint32)(x)) << EFM_RSA_KEY_CFG_RSA_KEY_NUM_SHIFT)) & EFM_RSA_KEY_CFG_RSA_KEY_NUM_MASK)
/* EFM_CMD_UNLOCK Register */
#define EFM_CMD_UNLOCK_CMD_UNLOCK_KEY_MASK                 (0xFFFFFFFFU)
#define EFM_CMD_UNLOCK_CMD_UNLOCK_KEY_SHIFT                (0U)
#define EFM_CMD_UNLOCK_CMD_UNLOCK_KEY(x)                   (((uint32)(((uint32)(x)) << EFM_CMD_UNLOCK_CMD_UNLOCK_KEY_SHIFT)) & EFM_CMD_UNLOCK_CMD_UNLOCK_KEY_MASK)
/* EFM_CUS_KEY Register */
#define EFM_CUS_KEY_CUS_KEY_MATCH_MASK                     (0x80000000U)
#define EFM_CUS_KEY_CUS_KEY_MATCH_SHIFT                    (31U)
#define EFM_CUS_KEY_CUS_KEY_MATCH(x)                       (((uint32)(((uint32)(x)) << EFM_CUS_KEY_CUS_KEY_MATCH_SHIFT)) & EFM_CUS_KEY_CUS_KEY_MATCH_MASK)
#define EFM_CUS_KEY_CUS_KEY_MISMATCH_MASK                   (0x40000000U)
#define EFM_CUS_KEY_CUS_KEY_MISMATCH_SHIFT                  (30U)
#define EFM_CUS_KEY_CUS_KEY_MISMATCH(x)                     (((uint32)(((uint32)(x)) << EFM_CUS_KEY_CUS_KEY_MISMATCH_SHIFT)) & EFM_CUS_KEY_CUS_KEY_MISMATCH_MASK)
#define EFM_CUS_KEY_CUS_KEY_MASK                           (0xFFFFFFU)
#define EFM_CUS_KEY_CUS_KEY_SHIFT                          (0U)
#define EFM_CUS_KEY_CUS_KEY(x)                             (((uint32)(((uint32)(x)) << EFM_CUS_KEY_CUS_KEY_SHIFT)) & EFM_CUS_KEY_CUS_KEY_MASK)
/* EFM_CTRL_OVRD Register */
#define EFM_CTRL_OVRD_DFLASH_PREREAD_DIS_MASK                 (0x40U)
#define EFM_CTRL_OVRD_DFLASH_PREREAD_DIS_SHIFT                (6U)
#define EFM_CTRL_OVRD_DFLASH_PREREAD_DIS(x)                   (((uint32)(((uint32)(x)) << EFM_CTRL_OVRD_DFLASH_PREREAD_DIS_SHIFT)) & EFM_CTRL_OVRD_DFLASH_PREREAD_DIS_MASK)
#define EFM_CTRL_OVRD_PFLASH_PREREAD_DIS_MASK                 (0x20U)
#define EFM_CTRL_OVRD_PFLASH_PREREAD_DIS_SHIFT                (5U)
#define EFM_CTRL_OVRD_PFLASH_PREREAD_DIS(x)                   (((uint32)(((uint32)(x)) << EFM_CTRL_OVRD_PFLASH_PREREAD_DIS_SHIFT)) & EFM_CTRL_OVRD_PFLASH_PREREAD_DIS_MASK)
#define EFM_CTRL_OVRD_DBG_DISABLE_MASK                     (0x8U)
#define EFM_CTRL_OVRD_DBG_DISABLE_SHIFT                    (3U)
#define EFM_CTRL_OVRD_DBG_DISABLE(x)                       (((uint32)(((uint32)(x)) << EFM_CTRL_OVRD_DBG_DISABLE_SHIFT)) & EFM_CTRL_OVRD_DBG_DISABLE_MASK)
#define EFM_CTRL_OVRD_PFLASH_ECC_DIS_MASK                  (0x1U)
#define EFM_CTRL_OVRD_PFLASH_ECC_DIS_SHIFT                 (0U)
#define EFM_CTRL_OVRD_PFLASH_ECC_DIS(x)                    (((uint32)(((uint32)(x)) << EFM_CTRL_OVRD_PFLASH_ECC_DIS_SHIFT)) & EFM_CTRL_OVRD_PFLASH_ECC_DIS_MASK)


/**
 * @}
 */ /* end of group EFM_Register_Masks */


/**
 * @}
 */ /* end of group EFM_Peripheral_Access_Layer */

#endif /* PSIP_EFM_H */
