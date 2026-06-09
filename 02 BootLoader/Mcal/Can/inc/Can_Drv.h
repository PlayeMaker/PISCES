/*
 *   @file    Can_Drv.h
 *   @version V0.9.1
 *
 *   @brief   AUTOSAR Can module interface
 *   @details API implementation for CAN driver
 *
 *   @addtogroup CAN_MODULE
 *   @{
 */

/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Can
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : V0.9.1
*
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef CAN_DRV_H
#define CAN_DRV_H

#ifdef __cplusplus
extern "C"{
#endif

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/
#include "Can_Types.h"

#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */

#if (CAN_DMA_USAGE == STD_ON)
#include "CddDma.h"
#include "CddDma_Cfg.h"
#include "pSIP_Dma.h"
#endif

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
 * @file     Can_Drv.h
 */
#define CAN_DRV_VENDOR_ID                      (180)
#define CAN_DRV_AR_RELEASE_MAJOR_VERSION       (4)
#define CAN_DRV_AR_RELEASE_MINOR_VERSION       (4)
#define CAN_DRV_AR_RELEASE_REVISION_VERSION    (0)
#define CAN_DRV_SW_MAJOR_VERSION               (0)
#define CAN_DRV_SW_MINOR_VERSION               (9)
#define CAN_DRV_SW_PATCH_VERSION               (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/**
 * @file     Can_Types.h
 */
/* Check if source file and CAN configuration header file are of the same vendor */
#if (CAN_DRV_VENDOR_ID != CAN_TYPES_VENDOR_ID)
#error "Can_Drv.h and Can_Types.h have different vendor ids"
#endif

/* Check if source file and CAN configuration header file are of the same Autosar version */
#if ((CAN_DRV_AR_RELEASE_MAJOR_VERSION != CAN_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_DRV_AR_RELEASE_MINOR_VERSION != CAN_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CAN_DRV_AR_RELEASE_REVISION_VERSION != CAN_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Can_Drv.h and Can_Types.h are different"
#endif

/* Check if source file and CAN configuration header file are of the same software version */
#if ((CAN_DRV_SW_MAJOR_VERSION != CAN_TYPES_SW_MAJOR_VERSION) || \
     (CAN_DRV_SW_MINOR_VERSION != CAN_TYPES_SW_MINOR_VERSION) || \
     (CAN_DRV_SW_PATCH_VERSION != CAN_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Can_Drv.h and Can_Types.h are different"
#endif

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define CAN32_READ(address) (*(volatile uint32 *)(address))
#define CAN8_READ(address) (*(volatile uint8 *)(address))
#define CAN16_READ(address) (*(volatile uint16 *)(address))
#define CAN32_WRITE(address, value) ((*(volatile uint32 *)(address)) = (value))
#define CAN8_WRITE(address, value) ((*(volatile uint8 *)(address)) = (value))
#define CAN32_AEARWRITE(address, mask, value) (CAN32_WRITE((address), \
                ((CAN32_READ(address) & ((uint32) ~(mask))) | (value))))

#define CAN32_SET_BITS(address, mask) ((*(volatile uint32 *)(address)) |= (mask))
#define CAN32_CLEAR_BITS(address, mask) ((*(volatile uint32 *)(address)) &= (~(mask)))
#define CAN32_INDEX_SET_BIT(address, bitindex) \
        ((*(volatile uint32 *)(address)) |= ((uint32)1U << (bitindex)))
#define CAN32_INDEX_CLEAR_BIT(address, bitindex) \
        ((*(volatile uint32 *)(address)) &= (~((uint32)1U << (bitindex))))

#define CAN32_GET_BITS(address, mask)    ((*(volatile uint32 *)(address)) & (mask))
#define CAN32_INDEX_GET_BITS(address, mask, bitindex) \
        (((*(volatile uint32 *)(address)) & (mask)) >> (bitindex))
#define CAN32_INDEX_GET_BIT(address, bitindex) \
        (((*(volatile uint32 *)(address)) >> (bitindex)) & ((uint32)1U))

#define CAN_UNUSED_PARAM(parma) ((void)parma)

#define CAN_TIMEOUT_COUNT ((uint32)10000U)
#define CAN_RAM_REGION_SIZE ((uint32)0x00000200U)

#define CAN_HWOBJ_MAX                                   (32U)

#define CAN_BASE_ADDR_MASK                              (0xFFFFF000U)

#define CAN_FORMAT_A_ID_0_STD_SHIFT                     (19)
#define CAN_FORMAT_A_ID_0_EXT_SHIFT                     (1)
#define CAN_FORMAT_B_ID_0_STD_SHIFT                     (19)
#define CAN_FORMAT_B_ID_0_EXT_SHIFT                     (1)
#define CAN_FORMAT_B_ID_1_STD_SHIFT                     (3)
#define CAN_FORMAT_B_ID_1_EXT_SHIFT                     (-15)
#define CAN_FORMAT_C_ID_0_EXT_SHIFT                     (3)
#define CAN_FORMAT_C_ID_1_EXT_SHIFT                     (-5)
#define CAN_FORMAT_C_ID_2_EXT_SHIFT                     (-13)
#define CAN_FORMAT_C_ID_3_EXT_SHIFT                     (-21)

#define CAN_CONST_FORMATC_FILTER_B0                     (0U)
#define CAN_CONST_FORMATC_FILTER_B1                     (1U)
#define CAN_CONST_FORMATC_FILTER_B2                     (2U)
#define CAN_CONST_FORMATC_FILTER_B3                     (3U)
#define CAN_CONST_FORMATC_FILTER_BLOCK_NUM              (4U)

#define CAN_CONST_FORMATB_FILTER_B0                     (0U)
#define CAN_CONST_FORMATB_FILTER_B1                     (1U)
#define CAN_CONST_FORMATB_FILTER_BLOCK_NUM              (2U)

#define CAN_CONST_FORMATB_ID_TYPE_FD_FRAME_MASK         (0x4000U)
#define CAN_CONST_FORMATB_ID_TYPE_EXTENDED_FRAME_MASK   (0x8000U)

#define CAN_CONST_IRQ_ENTRANCE_0                        (0U)
#define CAN_CONST_IRQ_ENTRANCE_1                        (1U)
#define CAN_CONST_IRQ_ENTRANCE_2                        (2U)
#define CAN_CONST_IRQ_ENTRANCE_3                        (3U)
#define CAN_CONST_IRQ_ENTRANCE_4                        (4U)
#define CAN_CONST_IRQ_ENTRANCE_5                        (5U)
#define CAN_CONST_IRQ_ENTRANCE_6                        (6U)
#define CAN_CONST_IRQ_ENTRANCE_7                        (7U)

#define CAN_CONST_MASK_FLAG_OFFSET                      (0x08U)

#define CAN_CONST_BYTENUM_PER_WORD                      (4U)
#define CAN_CONST_BYTE0_MASK                            (0x000000FFU)
#define CAN_CONST_BYTE1_MASK                            (0x0000FF00U)
#define CAN_CONST_BYTE2_MASK                            (0x00FF0000U)
#define CAN_CONST_BYTE3_MASK                            (0xFF000000U)
#define CAN_CEIL_WORD(x)                                (((x) + CAN_CONST_BYTENUM_PER_WORD - 1U) / CAN_CONST_BYTENUM_PER_WORD)
#define CAN_SWAP_BYTES32(x)                             (((uint32)((x) & CAN_CONST_BYTE3_MASK) >> 24) | \
                                                         ((uint32)((x) & CAN_CONST_BYTE2_MASK) >> 8)  | \
                                                         ((uint32)((x) & CAN_CONST_BYTE1_MASK) << 8)  | \
                                                         ((uint32)((x) & CAN_CONST_BYTE0_MASK) << 24))
#define CAN_CONST_OFFSET8                               (8U)
#define CAN_CONST_OFFSET24                              (24U)
#define CAN_CONST_LEGACY_FIFO_DEPTH                     (6U)
#define CAN_CONST_ENHANCE_FIFO_DEPTH                    (32U)
#define CAN_CONST_MAILBOXNUM_PER_RAMREGION              (32U)
#define CAN_CONST_RAMBYTES_PER_RAMREGION                (512U)
#define CAN_CONST_MAILBOXNUM_PER_IRG_ENTRANCE           (16U)
#define CAN_CONST_WHOLE_OF_BYTE_ALL_TRUE                (0xFFU)
#define CAN_CONST_WHOLE_OF_DBYTE_ALL_TRUE               (0xFFFFU)
#define CAN_CONST_WHOLE_OF_WORD_ALL_TRUE                (0xFFFFFFFFU)
#define CAN_CONST_LOWER_HALF_OF_WORD_ALL_TRUE           (0x0000FFFFU)
#define CAN_CONST_UPPER_HALF_OF_WORD_ALL_TRUE           (0xFFFF0000U)
#define CAN_CONST_BYTE0_OF_WORD_ALL_TRUE                (0x000000FFU)
#define CAN_CONST_BYTE1_OF_WORD_ALL_TRUE                (0x0000FF00U)
#define CAN_CONST_BYTE2_OF_WORD_ALL_TRUE                (0x00FF0000U)
#define CAN_CONST_BYTE3_OF_WORD_ALL_TRUE                (0xFF000000U)
#define CAN_CONST_BYTE0_OF_WORD                         (0U)
#define CAN_CONST_BYTE1_OF_WORD                         (1U)
#define CAN_CONST_BYTE2_OF_WORD                         (2U)
#define CAN_CONST_BYTE3_OF_WORD                         (3U)
#define CAN_CONST_OFFADDR_OF_MAILBOX                    (0x00000080U)
#define CAN_CONST_OFFADDR_OF_RXIMR                      (0x00000880U)
#define CAN_CONST_OFFADDR_OF_RXTIMESTAMP0               (0x00000C20U)
#define CAN_CONST_OFFADDR_OF_RXTIMESTAMP1               (0x00000C24U)
#define CAN_CONST_OFFADDR_OF_HRTIMESTAMP                (0x00000C30U)
#define CAN_CONST_OFFADDR_OF_RXFIR                      (0x00000A80U)
#define CAN_CONST_OFFADDR_OF_MASK                       (0x00000AA0U)
#define CAN_CONST_OFFADDR_OF_FDSMB                      (0x00000F28U)
#define CAN_CONST_OFFADDR_OF_SMB                        (0x00000AB0U)
#define CAN_CONST_OFFADDR_OF_TIMESTAMP                  (0x00001000U)
#define CAN_CONST_OFFADDR_OF_ENHFIFO                    (0x00002000U)
#define CAN_CONST_OFFADDR_OF_ENHFIFO_FILTER             (0x00003000U)
#define CAN_BUSOFF_FLAGS_MASK                           (0x00080302U)
#define CAN_RAM_START_OFFSET32                          (0x0080U)
#define CAN_RAMN_OFFSET32(x)                            (0x0080U + ((x) * (4U)))             /**< Offset for Embeded RAM Start */
#define CAN_RXFIFOIDF_OFFSET32(x)                       (0x00E0U + ((x) * (4U)))     /**< Offset for Rx FIFO ID filter table */
#define CAN_RXIMR_OFFSET32(x)                           (0x0880U + ((x) * (4U)))     /**< Offset for RX Individual Mask Register */
#define CAN_RXFIR_FIFO_OFFSET32(x)                      (0x0A80U + ((x) * (4U)))     /**< Offset for RXFIR FIFO Information Register */
#define CAN_MB_HERADER_1_PRIO_MASK                      (0xE0000000U)
#define CAN_MB_HERADER_1_PRIO_SHIFT                     (29U)
#define CAN_MB_HERADER_1_PRIO(x)                        (((uint32)(((uint32)(x)) << CAN_MB_HERADER_1_PRIO_SHIFT)) & CAN_MB_HERADER_1_PRIO_MASK)
#define CAN_MB_HERADER_1_ID_STD_MASK                    (0x1FFC0000U)
#define CAN_MB_HERADER_1_ID_STD_SHIFT                   (18U)
#define CAN_MB_HERADER_1_ID_STD(x)                      (((uint32)(((uint32)(x)) << CAN_MB_HERADER_1_ID_STD_SHIFT)) & CAN_MB_HERADER_1_ID_STD_MASK)
#define CAN_MB_HERADER_1_ID_EXT_MASK                    (0x1FFFFFFFU)
#define CAN_MB_HERADER_1_ID_EXT_SHIFT                   (0U)
#define CAN_MB_HERADER_1_ID_EXT(x)                      (((uint32)(((uint32)(x)) << CAN_MB_HERADER_1_ID_EXT_SHIFT)) & CAN_MB_HERADER_1_ID_EXT_MASK)

#define CAN_ENHANCE_RXFIFO_IDHIT_MASK                   (0x0000007FU)
#define CAN_ENHANCE_RXFIFO_IDHIT_SHIFT                  (0U)
#define CAN_ENHANCE_RXFIFO_IDHIT(x)                     (((uint32)(((uint32)(x)) << CAN_ENHANCE_RXFIFO_IDHIT_SHIFT)) & CAN_ENHANCE_RXFIFO_IDHIT_MASK)
#define CAN_ENHANCE_FIFO_FLAGS_MASK                     (0xF0000000U)
#define CAN_ENHANCE_RX_FIFO_RAM_OFFSET32                (0x2000U)                    /**< Offset for Enhanced Rx FIFO RAM */
#define CAN_ENHANCE_MB_MEMORY_OFFSET32                  (0x1000U)                    /**< Offset for Enhanced MB RAM */

#define CAN_LEGACY_RXFIFO_IDHIT_MASK                    (0xFF800000U)
#define CAN_LEGACY_RXFIFO_IDHIT_SHIFT                   (23U)
#define CAN_LEGACY_RXFIFO_IDHIT(x)                      (((uint32)(((uint32)(x)) << CAN_LEGACY_RXFIFO_IDHIT_SHIFT)) & CAN_LEGACY_RXFIFO_IDHIT_MASK)
#define CAN_LEGACY_FIFO_FLAGS_MASK                      (0x000000E0U)
/* CAN Mail box header */
#define CAN_MB_HERADER_0_EDL_MASK                       (0x80000000U)
#define CAN_MB_HERADER_0_EDL_SHIFT                      (31U)
#define CAN_MB_HERADER_0_EDL(x)                         (((uint32)(((uint32)(x)) << CAN_MB_HERADER_0_EDL_SHIFT)) & CAN_MB_HERADER_0_EDL_MASK)
#define CAN_MB_HERADER_0_BRS_MASK                       (0x40000000U)
#define CAN_MB_HERADER_0_BRS_SHIFT                      (30U)
#define CAN_MB_HERADER_0_BRS(x)                         (((uint32)(((uint32)(x)) << CAN_MB_HERADER_0_BRS_SHIFT)) & CAN_MB_HERADER_0_BRS_MASK)
#define CAN_MB_HERADER_0_ESI_MASK                       (0x20000000U)
#define CAN_MB_HERADER_0_ESI_SHIFT                      (29U)
#define CAN_MB_HERADER_0_ESI(x)                         (((uint32)(((uint32)(x)) << CAN_MB_HERADER_0_ESI_SHIFT)) & CAN_MB_HERADER_0_ESI_MASK)
#define CAN_MB_HERADER_0_CODE_MASK                      (0x0F000000U)
#define CAN_MB_HERADER_0_CODE_SHIFT                     (24U)
#define CAN_MB_HERADER_0_CODE(x)                        (((uint32)(((uint32)(x)) << CAN_MB_HERADER_0_CODE_SHIFT)) & CAN_MB_HERADER_0_CODE_MASK)
#define CAN_MB_HERADER_0_SRR_MASK                       (0x00400000U)
#define CAN_MB_HERADER_0_SRR_SHIFT                      (22U)
#define CAN_MB_HERADER_0_SRR(x)                         (((uint32)(((uint32)(x)) << CAN_MB_HERADER_0_SRR_SHIFT)) & CAN_MB_HERADER_0_SRR_MASK)
#define CAN_MB_HERADER_0_IDE_MASK                       (0x00200000U)
#define CAN_MB_HERADER_0_IDE_SHIFT                      (21U)
#define CAN_MB_HERADER_0_IDE(x)                         (((uint32)(((uint32)(x)) << CAN_MB_HERADER_0_IDE_SHIFT)) & CAN_MB_HERADER_0_IDE_MASK)
#define CAN_MB_HERADER_0_RTR_MASK                       (0x00100000U)
#define CAN_MB_HERADER_0_RTR_SHIFT                      (20U)
#define CAN_MB_HERADER_0_RTR(x)                         (((uint32)(((uint32)(x)) << CAN_MB_HERADER_0_RTR_SHIFT)) & CAN_MB_HERADER_0_RTR_MASK)
#define CAN_MB_HERADER_0_DLC_MASK                       (0x000F0000U)
#define CAN_MB_HERADER_0_DLC_SHIFT                      (16U)
#define CAN_MB_HERADER_0_DLC(x)                         (((uint32)(((uint32)(x)) << CAN_MB_HERADER_0_DLC_SHIFT)) & CAN_MB_HERADER_0_DLC_MASK)
#define CAN_MB_HERADER_0_TIMESTAMP_MASK                 (0x0000FFFFU)
#define CAN_MB_HERADER_0_TIMESTAMP_SHIFT                (0U)
#define CAN_MB_HERADER_0_TIMESTAMP(x)                   (((uint32)(((uint32)(x)) << CAN_MB_HERADER_0_TIMESTAMP_SHIFT)) & CAN_MB_HERADER_0_TIMESTAMP_MASK)

#define CAN_ERFFELN_FSCH_MASK                           (0xC0000000U)
#define CAN_ERFFELN_FSCH_SHIFT                          (30U)
#define CAN_ERFFELN_FSCH(x)                             (((uint32)(((uint32)(x)) << CAN_ERFFELN_FSCH_SHIFT)) & CAN_ERFFELN_FSCH_MASK)
#define CAN_ERFFELN_STDID_RTR_FILTER_MASK               (0x08000000U)
#define CAN_ERFFELN_STDID_RTR_FILTER_SHIFT              (27U)
#define CAN_ERFFELN_STDID_RTR_FILTER(x)                 (((uint32)(((uint32)(x)) << CAN_ERFFELN_STDID_RTR_FILTER_SHIFT)) & CAN_ERFFELN_STDID_RTR_FILTER_MASK)
#define CAN_ERFFELN_STDID_ID_FILTER_MASK                (0x07FF0000U)
#define CAN_ERFFELN_STDID_ID_FILTER_SHIFT               (16U)
#define CAN_ERFFELN_STDID_ID_FILTER(x)                  (((uint32)(((uint32)(x)) << CAN_ERFFELN_STDID_ID_FILTER_SHIFT)) & CAN_ERFFELN_STDID_ID_FILTER_MASK)
#define CAN_ERFFELN_STDID_RTR_MASK_MASK                 (0x00000800U)
#define CAN_ERFFELN_STDID_RTR_MASK_SHIFT                (11U)
#define CAN_ERFFELN_STDID_RTR_MASK(x)                   (((uint32)(((uint32)(x)) << CAN_ERFFELN_STDID_RTR_MASK_SHIFT)) & CAN_ERFFELN_STDID_RTR_MASK_MASK)
#define CAN_ERFFELN_STDID_ID_MASK_MASK                  (0x000007FFU)
#define CAN_ERFFELN_STDID_ID_MASK_SHIFT                 (0U)
#define CAN_ERFFELN_STDID_ID_MASK(x)                    (((uint32)(((uint32)(x)) << CAN_ERFFELN_STDID_ID_MASK_SHIFT)) & CAN_ERFFELN_STDID_ID_MASK_MASK)

#define CAN_ERFFELN_EXDID_RTR_FILTER_MASK               (0x20000000U)
#define CAN_ERFFELN_EXDID_RTR_FILTER_SHIFT              (29U)
#define CAN_ERFFELN_EXDID_RTR_FILTER(x)                 (((uint32)(((uint32)(x)) << CAN_ERFFELN_EXDID_RTR_FILTER_SHIFT)) & CAN_ERFFELN_EXDID_RTR_FILTER_MASK)
#define CAN_ERFFELN_EXDID_ID_FILTER_MASK                (0x1FFFFFFFU)
#define CAN_ERFFELN_EXDID_ID_FILTER_SHIFT               (0U)
#define CAN_ERFFELN_EXDID_ID_FILTER(x)                  (((uint32)(((uint32)(x)) << CAN_ERFFELN_EXDID_ID_FILTER_SHIFT)) & CAN_ERFFELN_EXDID_ID_FILTER_MASK)
#define CAN_ERFFELN_EXDID_RTR_MASK_MASK                 (0x20000000U)
#define CAN_ERFFELN_EXDID_RTR_MASK_SHIFT                (29U)
#define CAN_ERFFELN_EXDID_RTR_MASK(x)                   (((uint32)(((uint32)(x)) << CAN_ERFFELN_EXDID_RTR_MASK_SHIFT)) & CAN_ERFFELN_EXDID_RTR_MASK_MASK)
#define CAN_ERFFELN_EXDID_ID_MASK_MASK                  (0x1FFFFFFFU)
#define CAN_ERFFELN_EXDID_ID_MASK_SHIFT                 (0U)
#define CAN_ERFFELN_EXDID_ID_MASK(x)                    (((uint32)(((uint32)(x)) << CAN_ERFFELN_EXDID_ID_MASK_SHIFT)) & CAN_ERFFELN_EXDID_ID_MASK_MASK)

#define CAN_CONST_ECCERROR_OF_CEIF                      (0x00010000U)
#define CAN_CONST_ECCERROR_OF_HANCEIF                   (0x00080000U)
#define CAN_CONST_RAM_WORDNUM_OF_RXFIR                  (6U)
#define CAN_CONST_RAM_WORDNUM_OF_MASK                   (4U)
#define CAN_CONST_RAM_WORDNUM_OF_FDSMB                  (54U)
#define CAN_CONST_RAM_WORDNUM_OF_SMB                    (12U)
#define CAN_CONST_RAM_WORDNUM_OF_TIMESTAMP              (512U)
/* 20U * 32U(max Enhanced fifo nums) */
#define CAN_CONST_RAM_WORDNUM_OF_ENHFIFO                (20U * 32U)
#define CAN_CONST_RAM_WORDNUM_OF_ENHFIFO_FILTER         (128U)

#define CAN_CONST_ENH_FILTER_NUMCODE_ADAPTER            (1U)
#define CAN_CONST_ENH_FILTER_STDFLTNUM_PER_ELEMENT      (2U)
#define CAN_CONST_BUSOFF_REGISTER_ENUM                  (2U)
#define CAN_CONST_FRAME_8_BYTE_FORMAT                   (8U)
#define CAN_CONST_FRAME_64_BYTE_FORMAT                  (64U)
#define CAN_CONST_BITS_NUM_PER_BYTE                     (8U)
#define CAN_CONST_BITS_NUM_PER_CHECKSUM                 (5U)
#define CAN_CONST_ECC_DIAG_CODE_9C                      (0x9CU)
#define CAN_CONST_ECC_DIAG_CODE_96                      (0x96U)
#define CAN_CONST_ECC_DIAG_CODE_93                      (0x93U)
#define CAN_CONST_ECC_DIAG_CODE_99                      (0x99U)
#define CAN_CONST_ECC_DIAG_CODE_9A                      (0x9AU)
#define CAN_CONST_ECC_DIAG_CODE_87                      (0x87U)
#define CAN_CONST_ECC_DIAG_CODE_95                      (0x95U)
#define CAN_CONST_ECC_DIAG_CODE_8E                      (0x8EU)
#define CAN_CONST_ECC_DIAG_CODE_81                      (0x81U)
#define CAN_CONST_ECC_DIAG_CODE_82                      (0x82U)
#define CAN_CONST_ECC_DIAG_CODE_84                      (0x84U)
#define CAN_CONST_ECC_DIAG_CODE_88                      (0x88U)
#define CAN_CONST_ECC_DIAG_CODE_90                      (0x90U)
#define CAN_CONST_BIT0_TRUE_OF_A_BYTE                   (0x01U)
#define CAN_CONST_BIT1_TRUE_OF_A_BYTE                   (0x02U)
#define CAN_CONST_BIT2_TRUE_OF_A_BYTE                   (0x04U)
#define CAN_CONST_BIT3_TRUE_OF_A_BYTE                   (0x08U)
#define CAN_CONST_BIT4_TRUE_OF_A_BYTE                   (0x10U)
#define CAN_CONST_BIT5_TRUE_OF_A_BYTE                   (0x20U)
#define CAN_CONST_BIT6_TRUE_OF_A_BYTE                   (0x40U)
#define CAN_CONST_BIT7_TRUE_OF_A_BYTE                   (0x80U)

#define CAN_CONST_ENH_FILTER_NUMCODE_ADAPTER            (1U)
#define CAN_CONST_ENH_FILTER_STDFLTNUM_PER_ELEMENT      (2U)
#define CAN_CONST_BUSOFF_REGISTER_ENUM                  (2U)
#define CAN_CONST_FRAME_8_BYTE_FORMAT                   (8U)
#define CAN_CONST_FRAME_64_BYTE_FORMAT                  (64U)
#define CAN_CONST_PARA_NUM_1                            (1U)

#define CAN_CONST_TIMEOUT_ACC_10                        (10U)
#define CAN_CONST_TIMEOUT_ACC_50                        (50U)
#define CAN_CONST_TIMEOUT_ACC_60000                     (60000U)


#define CAN_LOGIC_CHANNEL_0                             (0U) /**< LOGIC CAN controller 0 ID */
#define CAN_LOGIC_CHANNEL_1                             (1U) /**< LOGIC CAN controller 1 ID */
#define CAN_LOGIC_CHANNEL_2                             (2U) /**< LOGIC CAN controller 2 ID */
#define CAN_LOGIC_CHANNEL_3                             (3U) /**< LOGIC CAN controller 3 ID */
#define CAN_LOGIC_CHANNEL_4                             (4U) /**< LOGIC CAN controller 4 ID */
#define CAN_LOGIC_CHANNEL_5                             (5U) /**< LOGIC CAN controller 5 ID */
#define CAN_LOGIC_CHANNEL_6                             (6U) /**< LOGIC CAN controller 6 ID */
#define CAN_LOGIC_CHANNEL_7                             (7U) /**< LOGIC CAN controller 7 ID */

#define FLEXCAN_0                                       (0U) /**< Hardware CAN controller 0 ID */
#define FLEXCAN_1                                       (1U) /**< Hardware CAN controller 1 ID */
#define FLEXCAN_2                                       (2U) /**< Hardware CAN controller 2 ID */
#define FLEXCAN_3                                       (3U) /**< Hardware CAN controller 3 ID */
#define FLEXCAN_4                                       (4U) /**< Hardware CAN controller 4 ID */
#define FLEXCAN_5                                       (5U) /**< Hardware CAN controller 5 ID */
#define FLEXCAN_6                                       (6U) /**< Hardware CAN controller 6 ID */
#define FLEXCAN_7                                       (7U) /**< Hardware CAN controller 7 ID */

#define LEGACY_FORMAT_A                                 (0U)
#define LEGACY_FORMAT_B                                 (1U)
#define LEGACY_FORMAT_C                                 (2U)
#define LEGACY_FORMAT_D                                 (3U)

/* 8  bytes per frame with 16 bytes payload, case type 0, every MB region can contain 32MBs*/
#define CAN_FD_FRAME_SIZE_8                             (0U)
/* 16 bytes per frame with 24 bytes payload, case type 1, every MB region can contain 21MBs*/
#define CAN_FD_FRAME_SIZE_16                            (1U)
/* 32 bytes per frame with 40 bytes payload, case type 2, every MB region can contain 12MBs*/
#define CAN_FD_FRAME_SIZE_32                            (2U)
/* 64 bytes per frame with 72 bytes payload, case type 3, every MB region can contain 7MBs*/
#define CAN_FD_FRAME_SIZE_64                            (3U)

#define CAN_MASK_INDIVIDUAL                             (0U)
#define CAN_MASK_GLOBAL                                 (1U)
#define CAN_MASK_MIXED                                  (2U)
#define CAN_EVENT_PROCESS_INTERRUPT                     (0U)
#define CAN_EVENT_PROCESS_POLLING                       (1U)
#define CAN_EVENT_PROCESS_MIXED                         (2U)

#define MAX_MB_QUALITY_PER_REGION_PLSIZETYPE_0          (32U)
#define MAX_MB_QUALITY_PER_REGION_PLSIZETYPE_1          (21U)
#define MAX_MB_QUALITY_PER_REGION_PLSIZETYPE_2          (12U)
#define MAX_MB_QUALITY_PER_REGION_PLSIZETYPE_3          (7U)

#define CAN_MB_RAM_DATA_OFFSET                          (2U)
/* 64Bytes + 4Bytes HEAD + 4Bytes ID + 4Byte IDHIT INFO for Enhanced FIFO */
#define CAN_MB_RAM_MAX_WORD_SIZE                        (19U)
#define CAN_LEGACY_FIFO_RAM_DATA_SIZE                   (8U)
#define CAN_ENHANCED_FIFO_RAM_DATA_SIZE                 (68U)

/*================================================================================================== 
                                          CODE MACRO                                           
==================================================================================================*/
/**
 * This macro is used to control generate IDHIT code or not.
 */
#define CAN_CODE_IDHIT ((CAN_FIFO_IDHIT_USAGE == STD_ON) && \
                        ((CAN_LEGACY_FIFO_USAGE == STD_ON) || (CAN_ENHANCE_FIFO_USAGE == STD_ON)))

/*==================================================================================================
                            CALLBACK SERVERS NOT FOR CUSTOMER USE
==================================================================================================*/
/**
  * @brief This service obtains the configuration of the Can module.
  * @return costumer config pointer
  */
const Can_ConfigType *Can_Bak_GetCfgPtr(void);

/**
  * @brief This service report error when Can data lost.
  * @param[in] ChnLogicId CAN controller channel Id
  * @return       void
  */
void Can_Bak_CallDatalost(uint8 ChnLogicId);

/**
  * @brief This service return Can module current state
  * @param[in] void
  * @return       CAN_UINIT or CAN_READY
  */
uint8 Can_Bak_GetDriveState(void);

/**
  * @brief This service is used to update the software state machine when a hardware
  *        event causes the Can module to be forced to stop
  * @param[in] ChnLogicId CAN controller channel Id
  * @return       E_OK or E_NOT_OK
  */
Std_ReturnType Can_Bak_SetCanStatusToStopped(uint8 ChnLogicId);

/**
  * @brief This service is used to obtain the controller ID through the received handle.
  * @param[in] Hrh Can received handle
  * @return Can controller Id
  */
uint8 Can_Bak_GetCanInstIdByHrh(Can_HwHandleType Hrh);

/**
  * @brief This service obtains the interrupt state of the corresponding Can channel
  * @param[in] ChnLogicId CAN controller channel Id
  * @return Boolean
  */
boolean Can_Bak_GetInterruptState(uint8 ChnLogicId);

#ifdef __cplusplus
}
#endif

#endif /* CAN_DRV_H */

/** @} */

