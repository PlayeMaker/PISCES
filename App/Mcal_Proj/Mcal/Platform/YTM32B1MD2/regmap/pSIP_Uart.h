/**
*   @file    pSIP_Uart.h
*   @version
*
*   @brief   AUTOSAR Uart register map
*   @details Register map for UART
*
*   @addtogroup UART_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Uart
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

#ifndef PSIP_UART_H
#define PSIP_UART_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/

#include "Std_Types.h"

/*==================================================================================================
*                              UART REGISTER MAP
==================================================================================================*/

/**
 * @addtogroup UART_Peripheral_Access_Layer UART Peripheral Access Layer
 * @{
 */


/** UART - Size of Registers Arrays */

/* UART Register Layout Typedef */
typedef struct
{
    uint32 BAUD;                               /**< Baud Rate Configuration Register, offset: 0x0000 */
    uint32 CTRL0;                              /**< Control 0 Register, offset: 0x0004 */
    uint32 CTRL1;                              /**< Control 1 Register, offset: 0x0008 */
    uint32 INTF;                               /**< Interrupt Flag Register, offset: 0x000C */
    uint32 INTE;                               /**< Interrupt Enable Register, offset: 0x0010 */
    uint32 MATCH;                              /**< Match Configuration Register, offset: 0x0014 */
    uint32 DATA;                               /**< Data Buffer Register, offset: 0x0018 */
    uint32 TXFIFO;                             /**< TX FIFO Configuration Register, offset: 0x001C */
    uint32 RXFIFO;                             /**< RX FIFO Configuration Register, offset: 0x0020 */

} UART_Type, *UART_MemMapPtr;

/** Number of instances of the UART module. */
#define UART_INSTANCE_COUNT                        (3u)

/* UART0  base address */
#define UART0_BASE_ADDR32                                  (0x4001B000U)
#define UART0                                              (( UART_Type *)(UART0_BASE_ADDR32))
/* UART1  base address */
#define UART1_BASE_ADDR32                                  (0x4001C000U)
#define UART1                                              (( UART_Type *)(UART1_BASE_ADDR32))
/* UART2  base address */
#define UART2_BASE_ADDR32                                  (0x4001D000U)
#define UART2                                              (( UART_Type *)(UART2_BASE_ADDR32))

/** Array initializer of UART peripheral base addresses */
#define UART_BASE_ADDRS                                    { UART0_BASE_ADDR32,  UART1_BASE_ADDR32,  UART2_BASE_ADDR32 }
/** Array initializer of UART peripheral base pointers */
#define UART_BASE_PTRS                                     { UART0,  UART1,  UART2 }

#define UART_BAUD_OFFSET32                                 (0x0000U)                    /**< Offset for Baud Rate Configuration Register */
#define UART_CTRL0_OFFSET32                                (0x0004U)                    /**< Offset for Control 0 Register */
#define UART_CTRL1_OFFSET32                                (0x0008U)                    /**< Offset for Control 1 Register */
#define UART_INTF_OFFSET32                                 (0x000CU)                    /**< Offset for Interrupt Flag Register */
#define UART_INTE_OFFSET32                                 (0x0010U)                    /**< Offset for Interrupt Enable Register */
#define UART_MATCH_OFFSET32                                (0x0014U)                    /**< Offset for Match Configuration Register */
#define UART_DATA_OFFSET32                                 (0x0018U)                    /**< Offset for Data Buffer Register */
#define UART_TXFIFO_OFFSET32                               (0x001CU)                    /**< Offset for TX FIFO Configuration Register */
#define UART_RXFIFO_OFFSET32                               (0x0020U)                    /**< Offset for RX FIFO Configuration Register */


/**
 * @addtogroup UART Register Mask
 * @{
 */
/* UART_BAUD Register */
#define UART_BAUD_OSRVAL_MASK                               (0x1F0000U)
#define UART_BAUD_OSRVAL_SHIFT                              (16U)
#define UART_BAUD_OSRVAL(x)                                 (((uint32)(((uint32)(x)) << UART_BAUD_OSRVAL_SHIFT)) & UART_BAUD_OSRVAL_MASK)
#define UART_BAUD_DIV_MASK                                  (0x1FFFU)
#define UART_BAUD_DIV_SHIFT                                 (0U)
#define UART_BAUD_DIV(x)                                    (((uint32)(((uint32)(x)) << UART_BAUD_DIV_SHIFT)) & UART_BAUD_DIV_MASK)
/* UART_CTRL0 Register */
#define UART_CTRL0_TXDMAEN_MASK                             (0x20000000U)
#define UART_CTRL0_TXDMAEN_SHIFT                            (29U)
#define UART_CTRL0_TXDMAEN(x)                               (((uint32)(((uint32)(x)) << UART_CTRL0_TXDMAEN_SHIFT)) & UART_CTRL0_TXDMAEN_MASK)
#define UART_CTRL0_RXDMAEN_MASK                             (0x10000000U)
#define UART_CTRL0_RXDMAEN_SHIFT                            (28U)
#define UART_CTRL0_RXDMAEN(x)                               (((uint32)(((uint32)(x)) << UART_CTRL0_RXDMAEN_SHIFT)) & UART_CTRL0_RXDMAEN_MASK)
#define UART_CTRL0_IDLEDMAEN_MASK                           (0x8000000U)
#define UART_CTRL0_IDLEDMAEN_SHIFT                          (27U)
#define UART_CTRL0_IDLEDMAEN(x)                             (((uint32)(((uint32)(x)) << UART_CTRL0_IDLEDMAEN_SHIFT)) & UART_CTRL0_IDLEDMAEN_MASK)
#define UART_CTRL0_TXCTSRC_MASK                             (0x4000000U)
#define UART_CTRL0_TXCTSRC_SHIFT                            (26U)
#define UART_CTRL0_TXCTSRC(x)                               (((uint32)(((uint32)(x)) << UART_CTRL0_TXCTSRC_SHIFT)) & UART_CTRL0_TXCTSRC_MASK)
#define UART_CTRL0_TXCTSC_MASK                              (0x2000000U)
#define UART_CTRL0_TXCTSC_SHIFT                             (25U)
#define UART_CTRL0_TXCTSC(x)                                (((uint32)(((uint32)(x)) << UART_CTRL0_TXCTSC_SHIFT)) & UART_CTRL0_TXCTSC_MASK)
#define UART_CTRL0_TXRTXPOL_MASK                            (0x800000U)
#define UART_CTRL0_TXRTXPOL_SHIFT                           (23U)
#define UART_CTRL0_TXRTXPOL(x)                              (((uint32)(((uint32)(x)) << UART_CTRL0_TXRTXPOL_SHIFT)) & UART_CTRL0_TXRTXPOL_MASK)
#define UART_CTRL0_MATEN_MASK                               (0x200000U)
#define UART_CTRL0_MATEN_SHIFT                              (21U)
#define UART_CTRL0_MATEN(x)                                 (((uint32)(((uint32)(x)) << UART_CTRL0_MATEN_SHIFT)) & UART_CTRL0_MATEN_MASK)
#define UART_CTRL0_MATMOD_MASK                              (0x30000U)
#define UART_CTRL0_MATMOD_SHIFT                             (16U)
#define UART_CTRL0_MATMOD(x)                                (((uint32)(((uint32)(x)) << UART_CTRL0_MATMOD_SHIFT)) & UART_CTRL0_MATMOD_MASK)
#define UART_CTRL0_RTSWATER_MASK                            (0x1C00U)
#define UART_CTRL0_RTSWATER_SHIFT                           (10U)
#define UART_CTRL0_RTSWATER(x)                              (((uint32)(((uint32)(x)) << UART_CTRL0_RTSWATER_SHIFT)) & UART_CTRL0_RTSWATER_MASK)
#define UART_CTRL0_RXRTSE_MASK                              (0x10U)
#define UART_CTRL0_RXRTSE_SHIFT                             (4U)
#define UART_CTRL0_RXRTSE(x)                                (((uint32)(((uint32)(x)) << UART_CTRL0_RXRTSE_SHIFT)) & UART_CTRL0_RXRTSE_MASK)
#define UART_CTRL0_TXRTSE_MASK                              (0x8U)
#define UART_CTRL0_TXRTSE_SHIFT                             (3U)
#define UART_CTRL0_TXRTSE(x)                                (((uint32)(((uint32)(x)) << UART_CTRL0_TXRTSE_SHIFT)) & UART_CTRL0_TXRTSE_MASK)
#define UART_CTRL0_TXCTSE_MASK                              (0x4U)
#define UART_CTRL0_TXCTSE_SHIFT                             (2U)
#define UART_CTRL0_TXCTSE(x)                                (((uint32)(((uint32)(x)) << UART_CTRL0_TXCTSE_SHIFT)) & UART_CTRL0_TXCTSE_MASK)
#define UART_CTRL0_TXEN_MASK                                (0x2U)
#define UART_CTRL0_TXEN_SHIFT                               (1U)
#define UART_CTRL0_TXEN(x)                                  (((uint32)(((uint32)(x)) << UART_CTRL0_TXEN_SHIFT)) & UART_CTRL0_TXEN_MASK)
#define UART_CTRL0_RXEN_MASK                                (0x1U)
#define UART_CTRL0_RXEN_SHIFT                               (0U)
#define UART_CTRL0_RXEN(x)                                  (((uint32)(((uint32)(x)) << UART_CTRL0_RXEN_SHIFT)) & UART_CTRL0_RXEN_MASK)
/* UART_CTRL1 Register */
#define UART_CTRL1_FRAMESZ_MASK                             (0xC0000000U)
#define UART_CTRL1_FRAMESZ_SHIFT                            (30U)
#define UART_CTRL1_FRAMESZ(x)                               (((uint32)(((uint32)(x)) << UART_CTRL1_FRAMESZ_SHIFT)) & UART_CTRL1_FRAMESZ_MASK)
#define UART_CTRL1_STOPSZ_MASK                              (0x8000000U)
#define UART_CTRL1_STOPSZ_SHIFT                             (27U)
#define UART_CTRL1_STOPSZ(x)                                (((uint32)(((uint32)(x)) << UART_CTRL1_STOPSZ_SHIFT)) & UART_CTRL1_STOPSZ_MASK)
#define UART_CTRL1_TXINV_MASK                               (0x1000000U)
#define UART_CTRL1_TXINV_SHIFT                              (24U)
#define UART_CTRL1_TXINV(x)                                 (((uint32)(((uint32)(x)) << UART_CTRL1_TXINV_SHIFT)) & UART_CTRL1_TXINV_MASK)
#define UART_CTRL1_RXINV_MASK                               (0x800000U)
#define UART_CTRL1_RXINV_SHIFT                              (23U)
#define UART_CTRL1_RXINV(x)                                 (((uint32)(((uint32)(x)) << UART_CTRL1_RXINV_SHIFT)) & UART_CTRL1_RXINV_MASK)
#define UART_CTRL1_TXDIR_MASK                               (0x400000U)
#define UART_CTRL1_TXDIR_SHIFT                              (22U)
#define UART_CTRL1_TXDIR(x)                                 (((uint32)(((uint32)(x)) << UART_CTRL1_TXDIR_SHIFT)) & UART_CTRL1_TXDIR_MASK)
#define UART_CTRL1_SWAP_MASK                                (0x200000U)
#define UART_CTRL1_SWAP_SHIFT                               (21U)
#define UART_CTRL1_SWAP(x)                                  (((uint32)(((uint32)(x)) << UART_CTRL1_SWAP_SHIFT)) & UART_CTRL1_SWAP_MASK)
#define UART_CTRL1_LOOP_MASK                                (0x100000U)
#define UART_CTRL1_LOOP_SHIFT                               (20U)
#define UART_CTRL1_LOOP(x)                                  (((uint32)(((uint32)(x)) << UART_CTRL1_LOOP_SHIFT)) & UART_CTRL1_LOOP_MASK)
#define UART_CTRL1_IDLESZ_MASK                              (0x70000U)
#define UART_CTRL1_IDLESZ_SHIFT                             (16U)
#define UART_CTRL1_IDLESZ(x)                                (((uint32)(((uint32)(x)) << UART_CTRL1_IDLESZ_SHIFT)) & UART_CTRL1_IDLESZ_MASK)
#define UART_CTRL1_BOTHEDGE_MASK                            (0x8000U)
#define UART_CTRL1_BOTHEDGE_SHIFT                           (15U)
#define UART_CTRL1_BOTHEDGE(x)                              (((uint32)(((uint32)(x)) << UART_CTRL1_BOTHEDGE_SHIFT)) & UART_CTRL1_BOTHEDGE_MASK)
#define UART_CTRL1_LBKDEN_MASK                              (0x400U)
#define UART_CTRL1_LBKDEN_SHIFT                             (10U)
#define UART_CTRL1_LBKDEN(x)                                (((uint32)(((uint32)(x)) << UART_CTRL1_LBKDEN_SHIFT)) & UART_CTRL1_LBKDEN_MASK)
#define UART_CTRL1_LBKSZ_MASK                               (0x200U)
#define UART_CTRL1_LBKSZ_SHIFT                              (9U)
#define UART_CTRL1_LBKSZ(x)                                 (((uint32)(((uint32)(x)) << UART_CTRL1_LBKSZ_SHIFT)) & UART_CTRL1_LBKSZ_MASK)
#define UART_CTRL1_MSBF_MASK                                (0x100U)
#define UART_CTRL1_MSBF_SHIFT                               (8U)
#define UART_CTRL1_MSBF(x)                                  (((uint32)(((uint32)(x)) << UART_CTRL1_MSBF_SHIFT)) & UART_CTRL1_MSBF_MASK)
#define UART_CTRL1_SBK_MASK                                 (0x40U)
#define UART_CTRL1_SBK_SHIFT                                (6U)
#define UART_CTRL1_SBK(x)                                   (((uint32)(((uint32)(x)) << UART_CTRL1_SBK_SHIFT)) & UART_CTRL1_SBK_MASK)
#define UART_CTRL1_RBACK_MASK                               (0x8U)
#define UART_CTRL1_RBACK_SHIFT                              (3U)
#define UART_CTRL1_RBACK(x)                                 (((uint32)(((uint32)(x)) << UART_CTRL1_RBACK_SHIFT)) & UART_CTRL1_RBACK_MASK)
#define UART_CTRL1_ONEWIRE_MASK                             (0x4U)
#define UART_CTRL1_ONEWIRE_SHIFT                            (2U)
#define UART_CTRL1_ONEWIRE(x)                               (((uint32)(((uint32)(x)) << UART_CTRL1_ONEWIRE_SHIFT)) & UART_CTRL1_ONEWIRE_MASK)
#define UART_CTRL1_PAREN_MASK                               (0x2U)
#define UART_CTRL1_PAREN_SHIFT                              (1U)
#define UART_CTRL1_PAREN(x)                                 (((uint32)(((uint32)(x)) << UART_CTRL1_PAREN_SHIFT)) & UART_CTRL1_PAREN_MASK)
#define UART_CTRL1_PARSEL_MASK                              (0x1U)
#define UART_CTRL1_PARSEL_SHIFT                             (0U)
#define UART_CTRL1_PARSEL(x)                                (((uint32)(((uint32)(x)) << UART_CTRL1_PARSEL_SHIFT)) & UART_CTRL1_PARSEL_MASK)
/* UART_INTF Register */
#define UART_INTF_IDLEWAKE_MASK                             (0x20000U)
#define UART_INTF_IDLEWAKE_SHIFT                            (17U)
#define UART_INTF_IDLEWAKE(x)                               (((uint32)(((uint32)(x)) << UART_INTF_IDLEWAKE_SHIFT)) & UART_INTF_IDLEWAKE_MASK)
#define UART_INTF_RXBUSY_MASK                               (0x10000U)
#define UART_INTF_RXBUSY_SHIFT                              (16U)
#define UART_INTF_RXBUSY(x)                                 (((uint32)(((uint32)(x)) << UART_INTF_RXBUSY_SHIFT)) & UART_INTF_RXBUSY_MASK)
#define UART_INTF_RBCEIF_MASK                               (0x4000U)
#define UART_INTF_RBCEIF_SHIFT                              (14U)
#define UART_INTF_RBCEIF(x)                                 (((uint32)(((uint32)(x)) << UART_INTF_RBCEIF_SHIFT)) & UART_INTF_RBCEIF_MASK)
#define UART_INTF_RFEIF_MASK                                (0x2000U)
#define UART_INTF_RFEIF_SHIFT                               (13U)
#define UART_INTF_RFEIF(x)                                  (((uint32)(((uint32)(x)) << UART_INTF_RFEIF_SHIFT)) & UART_INTF_RFEIF_MASK)
#define UART_INTF_TFEIF_MASK                                (0x1000U)
#define UART_INTF_TFEIF_SHIFT                               (12U)
#define UART_INTF_TFEIF(x)                                  (((uint32)(((uint32)(x)) << UART_INTF_TFEIF_SHIFT)) & UART_INTF_TFEIF_MASK)
#define UART_INTF_LBKDIF_MASK                               (0x800U)
#define UART_INTF_LBKDIF_SHIFT                              (11U)
#define UART_INTF_LBKDIF(x)                                 (((uint32)(((uint32)(x)) << UART_INTF_LBKDIF_SHIFT)) & UART_INTF_LBKDIF_MASK)
#define UART_INTF_RXEDGEIF_MASK                             (0x400U)
#define UART_INTF_RXEDGEIF_SHIFT                            (10U)
#define UART_INTF_RXEDGEIF(x)                               (((uint32)(((uint32)(x)) << UART_INTF_RXEDGEIF_SHIFT)) & UART_INTF_RXEDGEIF_MASK)
#define UART_INTF_MATIF_MASK                                (0x200U)
#define UART_INTF_MATIF_SHIFT                               (9U)
#define UART_INTF_MATIF(x)                                  (((uint32)(((uint32)(x)) << UART_INTF_MATIF_SHIFT)) & UART_INTF_MATIF_MASK)
#define UART_INTF_NOZIF_MASK                                (0x80U)
#define UART_INTF_NOZIF_SHIFT                               (7U)
#define UART_INTF_NOZIF(x)                                  (((uint32)(((uint32)(x)) << UART_INTF_NOZIF_SHIFT)) & UART_INTF_NOZIF_MASK)
#define UART_INTF_OVRIF_MASK                                (0x40U)
#define UART_INTF_OVRIF_SHIFT                               (6U)
#define UART_INTF_OVRIF(x)                                  (((uint32)(((uint32)(x)) << UART_INTF_OVRIF_SHIFT)) & UART_INTF_OVRIF_MASK)
#define UART_INTF_FEIF_MASK                                 (0x20U)
#define UART_INTF_FEIF_SHIFT                                (5U)
#define UART_INTF_FEIF(x)                                   (((uint32)(((uint32)(x)) << UART_INTF_FEIF_SHIFT)) & UART_INTF_FEIF_MASK)
#define UART_INTF_IDLEIF_MASK                               (0x10U)
#define UART_INTF_IDLEIF_SHIFT                              (4U)
#define UART_INTF_IDLEIF(x)                                 (((uint32)(((uint32)(x)) << UART_INTF_IDLEIF_SHIFT)) & UART_INTF_IDLEIF_MASK)
#define UART_INTF_PARIF_MASK                                (0x8U)
#define UART_INTF_PARIF_SHIFT                               (3U)
#define UART_INTF_PARIF(x)                                  (((uint32)(((uint32)(x)) << UART_INTF_PARIF_SHIFT)) & UART_INTF_PARIF_MASK)
#define UART_INTF_TCIF_MASK                                 (0x4U)
#define UART_INTF_TCIF_SHIFT                                (2U)
#define UART_INTF_TCIF(x)                                   (((uint32)(((uint32)(x)) << UART_INTF_TCIF_SHIFT)) & UART_INTF_TCIF_MASK)
#define UART_INTF_TXIF_MASK                                 (0x2U)
#define UART_INTF_TXIF_SHIFT                                (1U)
#define UART_INTF_TXIF(x)                                   (((uint32)(((uint32)(x)) << UART_INTF_TXIF_SHIFT)) & UART_INTF_TXIF_MASK)
#define UART_INTF_RXIF_MASK                                 (0x1U)
#define UART_INTF_RXIF_SHIFT                                (0U)
#define UART_INTF_RXIF(x)                                   (((uint32)(((uint32)(x)) << UART_INTF_RXIF_SHIFT)) & UART_INTF_RXIF_MASK)
/* UART_INTE Register */
#define UART_INTE_RBCEIE_MASK                               (0x4000U)
#define UART_INTE_RBCEIE_SHIFT                              (14U)
#define UART_INTE_RBCEIE(x)                                 (((uint32)(((uint32)(x)) << UART_INTE_RBCEIE_SHIFT)) & UART_INTE_RBCEIE_MASK)
#define UART_INTE_RFEIE_MASK                                (0x2000U)
#define UART_INTE_RFEIE_SHIFT                               (13U)
#define UART_INTE_RFEIE(x)                                  (((uint32)(((uint32)(x)) << UART_INTE_RFEIE_SHIFT)) & UART_INTE_RFEIE_MASK)
#define UART_INTE_TFIFOEIE_MASK                             (0x1000U)
#define UART_INTE_TFIFOEIE_SHIFT                            (12U)
#define UART_INTE_TFIFOEIE(x)                               (((uint32)(((uint32)(x)) << UART_INTE_TFIFOEIE_SHIFT)) & UART_INTE_TFIFOEIE_MASK)
#define UART_INTE_LBKDIE_MASK                               (0x800U)
#define UART_INTE_LBKDIE_SHIFT                              (11U)
#define UART_INTE_LBKDIE(x)                                 (((uint32)(((uint32)(x)) << UART_INTE_LBKDIE_SHIFT)) & UART_INTE_LBKDIE_MASK)
#define UART_INTE_RXEDGEIE_MASK                             (0x400U)
#define UART_INTE_RXEDGEIE_SHIFT                            (10U)
#define UART_INTE_RXEDGEIE(x)                               (((uint32)(((uint32)(x)) << UART_INTE_RXEDGEIE_SHIFT)) & UART_INTE_RXEDGEIE_MASK)
#define UART_INTE_MATIE_MASK                                (0x200U)
#define UART_INTE_MATIE_SHIFT                               (9U)
#define UART_INTE_MATIE(x)                                  (((uint32)(((uint32)(x)) << UART_INTE_MATIE_SHIFT)) & UART_INTE_MATIE_MASK)
#define UART_INTE_NOZIE_MASK                                (0x80U)
#define UART_INTE_NOZIE_SHIFT                               (7U)
#define UART_INTE_NOZIE(x)                                  (((uint32)(((uint32)(x)) << UART_INTE_NOZIE_SHIFT)) & UART_INTE_NOZIE_MASK)
#define UART_INTE_OVRIE_MASK                                (0x40U)
#define UART_INTE_OVRIE_SHIFT                               (6U)
#define UART_INTE_OVRIE(x)                                  (((uint32)(((uint32)(x)) << UART_INTE_OVRIE_SHIFT)) & UART_INTE_OVRIE_MASK)
#define UART_INTE_FEIE_MASK                                 (0x20U)
#define UART_INTE_FEIE_SHIFT                                (5U)
#define UART_INTE_FEIE(x)                                   (((uint32)(((uint32)(x)) << UART_INTE_FEIE_SHIFT)) & UART_INTE_FEIE_MASK)
#define UART_INTE_IDLEIE_MASK                               (0x10U)
#define UART_INTE_IDLEIE_SHIFT                              (4U)
#define UART_INTE_IDLEIE(x)                                 (((uint32)(((uint32)(x)) << UART_INTE_IDLEIE_SHIFT)) & UART_INTE_IDLEIE_MASK)
#define UART_INTE_PARIE_MASK                                (0x8U)
#define UART_INTE_PARIE_SHIFT                               (3U)
#define UART_INTE_PARIE(x)                                  (((uint32)(((uint32)(x)) << UART_INTE_PARIE_SHIFT)) & UART_INTE_PARIE_MASK)
#define UART_INTE_TCIE_MASK                                 (0x4U)
#define UART_INTE_TCIE_SHIFT                                (2U)
#define UART_INTE_TCIE(x)                                   (((uint32)(((uint32)(x)) << UART_INTE_TCIE_SHIFT)) & UART_INTE_TCIE_MASK)
#define UART_INTE_TXIE_MASK                                 (0x2U)
#define UART_INTE_TXIE_SHIFT                                (1U)
#define UART_INTE_TXIE(x)                                   (((uint32)(((uint32)(x)) << UART_INTE_TXIE_SHIFT)) & UART_INTE_TXIE_MASK)
#define UART_INTE_RXIE_MASK                                 (0x1U)
#define UART_INTE_RXIE_SHIFT                                (0U)
#define UART_INTE_RXIE(x)                                   (((uint32)(((uint32)(x)) << UART_INTE_RXIE_SHIFT)) & UART_INTE_RXIE_MASK)
/* UART_MATCH Register */
#define UART_MATCH_DATAB_MASK                               (0x3FF0000U)
#define UART_MATCH_DATAB_SHIFT                              (16U)
#define UART_MATCH_DATAB(x)                                 (((uint32)(((uint32)(x)) << UART_MATCH_DATAB_SHIFT)) & UART_MATCH_DATAB_MASK)
#define UART_MATCH_DATAA_MASK                               (0x3FFU)
#define UART_MATCH_DATAA_SHIFT                              (0U)
#define UART_MATCH_DATAA(x)                                 (((uint32)(((uint32)(x)) << UART_MATCH_DATAA_SHIFT)) & UART_MATCH_DATAA_MASK)
/* UART_DATA Register */
#define UART_DATA_FERR_MASK                                 (0x100000U)
#define UART_DATA_FERR_SHIFT                                (20U)
#define UART_DATA_FERR(x)                                   (((uint32)(((uint32)(x)) << UART_DATA_FERR_SHIFT)) & UART_DATA_FERR_MASK)
#define UART_DATA_NOISE_MASK                                (0x80000U)
#define UART_DATA_NOISE_SHIFT                               (19U)
#define UART_DATA_NOISE(x)                                  (((uint32)(((uint32)(x)) << UART_DATA_NOISE_SHIFT)) & UART_DATA_NOISE_MASK)
#define UART_DATA_PARERR_MASK                               (0x40000U)
#define UART_DATA_PARERR_SHIFT                              (18U)
#define UART_DATA_PARERR(x)                                 (((uint32)(((uint32)(x)) << UART_DATA_PARERR_SHIFT)) & UART_DATA_PARERR_MASK)
#define UART_DATA_IDLE_MASK                                 (0x20000U)
#define UART_DATA_IDLE_SHIFT                                (17U)
#define UART_DATA_IDLE(x)                                   (((uint32)(((uint32)(x)) << UART_DATA_IDLE_SHIFT)) & UART_DATA_IDLE_MASK)
#define UART_DATA_RXEMPT_MASK                               (0x10000U)
#define UART_DATA_RXEMPT_SHIFT                              (16U)
#define UART_DATA_RXEMPT(x)                                 (((uint32)(((uint32)(x)) << UART_DATA_RXEMPT_SHIFT)) & UART_DATA_RXEMPT_MASK)
#define UART_DATA_LINBRK_MASK                               (0x8000U)
#define UART_DATA_LINBRK_SHIFT                              (15U)
#define UART_DATA_LINBRK(x)                                 (((uint32)(((uint32)(x)) << UART_DATA_LINBRK_SHIFT)) & UART_DATA_LINBRK_MASK)
#define UART_DATA_DATA_MASK                                 (0x3FFU)
#define UART_DATA_DATA_SHIFT                                (0U)
#define UART_DATA_DATA(x)                                   (((uint32)(((uint32)(x)) << UART_DATA_DATA_SHIFT)) & UART_DATA_DATA_MASK)
/* UART_TXFIFO Register */
#define UART_TXFIFO_EMPTY_MASK                              (0x80000000U)
#define UART_TXFIFO_EMPTY_SHIFT                             (31U)
#define UART_TXFIFO_EMPTY(x)                                (((uint32)(((uint32)(x)) << UART_TXFIFO_EMPTY_SHIFT)) & UART_TXFIFO_EMPTY_MASK)
#define UART_TXFIFO_ERROR_MASK                              (0x40000000U)
#define UART_TXFIFO_ERROR_SHIFT                             (30U)
#define UART_TXFIFO_ERROR(x)                                (((uint32)(((uint32)(x)) << UART_TXFIFO_ERROR_SHIFT)) & UART_TXFIFO_ERROR_MASK)
#define UART_TXFIFO_SIZE_MASK                               (0x7000000U)
#define UART_TXFIFO_SIZE_SHIFT                              (24U)
#define UART_TXFIFO_SIZE(x)                                 (((uint32)(((uint32)(x)) << UART_TXFIFO_SIZE_SHIFT)) & UART_TXFIFO_SIZE_MASK)
#define UART_TXFIFO_RESET_MASK                              (0x8000U)
#define UART_TXFIFO_RESET_SHIFT                             (15U)
#define UART_TXFIFO_RESET(x)                                (((uint32)(((uint32)(x)) << UART_TXFIFO_RESET_SHIFT)) & UART_TXFIFO_RESET_MASK)
#define UART_TXFIFO_EN_MASK                                 (0x4000U)
#define UART_TXFIFO_EN_SHIFT                                (14U)
#define UART_TXFIFO_EN(x)                                   (((uint32)(((uint32)(x)) << UART_TXFIFO_EN_SHIFT)) & UART_TXFIFO_EN_MASK)
#define UART_TXFIFO_COUNT_MASK                              (0x700U)
#define UART_TXFIFO_COUNT_SHIFT                             (8U)
#define UART_TXFIFO_COUNT(x)                                (((uint32)(((uint32)(x)) << UART_TXFIFO_COUNT_SHIFT)) & UART_TXFIFO_COUNT_MASK)
#define UART_TXFIFO_WATER_MASK                              (0x7U)
#define UART_TXFIFO_WATER_SHIFT                             (0U)
#define UART_TXFIFO_WATER(x)                                (((uint32)(((uint32)(x)) << UART_TXFIFO_WATER_SHIFT)) & UART_TXFIFO_WATER_MASK)
/* UART_RXFIFO Register */
#define UART_RXFIFO_EMPTY_MASK                              (0x80000000U)
#define UART_RXFIFO_EMPTY_SHIFT                             (31U)
#define UART_RXFIFO_EMPTY(x)                                (((uint32)(((uint32)(x)) << UART_RXFIFO_EMPTY_SHIFT)) & UART_RXFIFO_EMPTY_MASK)
#define UART_RXFIFO_ERROR_MASK                              (0x40000000U)
#define UART_RXFIFO_ERROR_SHIFT                             (30U)
#define UART_RXFIFO_ERROR(x)                                (((uint32)(((uint32)(x)) << UART_RXFIFO_ERROR_SHIFT)) & UART_RXFIFO_ERROR_MASK)
#define UART_RXFIFO_SIZE_MASK                               (0x7000000U)
#define UART_RXFIFO_SIZE_SHIFT                              (24U)
#define UART_RXFIFO_SIZE(x)                                 (((uint32)(((uint32)(x)) << UART_RXFIFO_SIZE_SHIFT)) & UART_RXFIFO_SIZE_MASK)
#define UART_RXFIFO_RESET_MASK                              (0x8000U)
#define UART_RXFIFO_RESET_SHIFT                             (15U)
#define UART_RXFIFO_RESET(x)                                (((uint32)(((uint32)(x)) << UART_RXFIFO_RESET_SHIFT)) & UART_RXFIFO_RESET_MASK)
#define UART_RXFIFO_EN_MASK                                 (0x4000U)
#define UART_RXFIFO_EN_SHIFT                                (14U)
#define UART_RXFIFO_EN(x)                                   (((uint32)(((uint32)(x)) << UART_RXFIFO_EN_SHIFT)) & UART_RXFIFO_EN_MASK)
#define UART_RXFIFO_COUNT_MASK                              (0x700U)
#define UART_RXFIFO_COUNT_SHIFT                             (8U)
#define UART_RXFIFO_COUNT(x)                                (((uint32)(((uint32)(x)) << UART_RXFIFO_COUNT_SHIFT)) & UART_RXFIFO_COUNT_MASK)
#define UART_RXFIFO_WATER_MASK                              (0x7U)
#define UART_RXFIFO_WATER_SHIFT                             (0U)
#define UART_RXFIFO_WATER(x)                                (((uint32)(((uint32)(x)) << UART_RXFIFO_WATER_SHIFT)) & UART_RXFIFO_WATER_MASK)


/**
 * @}
 */ /* end of group UART_Register_Masks */


/**
 * @}
 */ /* end of group UART_Peripheral_Access_Layer */

#endif /* PSIP_UART_H */
