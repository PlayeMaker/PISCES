/**
 *   @file    Can_Lld.c
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

#ifdef __cplusplus
extern "C" {
#endif
/* PRQA S 0306,0307,0313,0316,4700 EOF */
/**
 *  @page misra_violations MISRA-C:2012 violations
 *  PRQA S 0306 Rule-11.4: A conversion should not be performed between a pointer to object and
 *  an integer type
 *
 *  PRQA S 0307 Rule-1.3: Cast between a pointer to object and a pointer to function.
 *  PRQA S 0307 Rule-11.1: Conversions shall not be performed between a pointer to a function
 *      and any other type
 *
 *  PRQA S 0316 Rule-11.5: Cast from a pointer to void to a pointer to object type.
 *
 *  PRQA S 0313 Rule-11.1: Casting to different function pointer type.
 *
 *  PRQA S 4700 CMA information
 *  integer type
 */
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "pSIP_Can.h"
#include "Can_Drv.h"
#include "SchM_Can.h"
#include "Can_Lld.h"
#include "CanIf_Can.h"

#if (CAN_WAKEUP_SUPPORT == STD_ON)
#include "EcuM.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_LLD_VENDOR_ID_C                      (180)
#define CAN_LLD_AR_RELEASE_MAJOR_VERSION_C       (4)
#define CAN_LLD_AR_RELEASE_MINOR_VERSION_C       (4)
#define CAN_LLD_AR_RELEASE_REVISION_VERSION_C    (0)
#define CAN_LLD_SW_MAJOR_VERSION_C               (0)
#define CAN_LLD_SW_MINOR_VERSION_C               (9)
#define CAN_LLD_SW_PATCH_VERSION_C               (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CAN header file are of the same vendor */
#if (CAN_LLD_VENDOR_ID_C != CAN_LLD_VENDOR_ID)
#error "Can_Lld.c and Can_Lld.hhave different vendor ids"
#endif
/* Check if source file and CAN header file are of the same Autosar version */
#if ((CAN_LLD_AR_RELEASE_MAJOR_VERSION_C != CAN_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_LLD_AR_RELEASE_MINOR_VERSION_C != CAN_LLD_AR_RELEASE_MINOR_VERSION) || \
     (CAN_LLD_AR_RELEASE_REVISION_VERSION_C != CAN_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Can_Lld.c and Can_Lld.h are different"
#endif
/* Check if source file and CAN header file are of the same Software version */
#if ((CAN_LLD_SW_MAJOR_VERSION_C != CAN_LLD_SW_MAJOR_VERSION) || \
     (CAN_LLD_SW_MINOR_VERSION_C != CAN_LLD_SW_MINOR_VERSION) || \
     (CAN_LLD_SW_PATCH_VERSION_C != CAN_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Can_Lld.c and Can_Lld.h are different"
#endif
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define CAN_CONST_TABLE                   (STD_ON)
#if (CAN_CONST_TABLE == STD_ON)
#define CAN_START_SEC_CONST_8
#include "Can_MemMap.h"
CAN_CONST static const uint8 Can_Table_IrqFlagIdToOffsetAddr[4] = {0x30U, 0x2CU, 0x74U, 0x70U};

CAN_CONST static const uint8 Can_Table_FrameDataAddr[64] =
{
    11U, 10U,  9U,  8U, 15U, 14U, 13U, 12U, 19U, 18U, 17U, 16U, 23U, 22U, 21U, 20U,
    27U, 26U, 25U, 24U, 31U, 30U, 29U, 28U, 35U, 34U, 33U, 32U, 39U, 38U, 37U, 36U,
    43U, 42U, 41U, 40U, 47U, 46U, 45U, 44U, 51U, 50U, 49U, 48U, 55U, 54U, 53U, 52U,
    59U, 58U, 57U, 56U, 63U, 62U, 61U, 60U, 67U, 66U, 65U, 64U, 71U, 70U, 69U, 68U
};

CAN_CONST static const uint8 Can_Table_DlcToDatalength[16] =
{
    0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 12U, 16U, 20U, 24U, 32U, 48U, 64U
};

/**
 * @brief This table covert a data length to a dlc code.
 *
 */
CAN_CONST static const uint8 Can_Table_DatalengthToDlc[65] =
{
    0U,  1U,  2U,  3U,  4U,  5U,  6U,  7U, 8U,
    9U,  9U,  9U,  9U, 10U, 10U, 10U, 10U,
    11U, 11U, 11U, 11U, 12U, 12U, 12U, 12U,
    13U, 13U, 13U, 13U, 13U, 13U, 13U, 13U,
    14U, 14U, 14U, 14U, 14U, 14U, 14U, 14U,
    14U, 14U, 14U, 14U, 14U, 14U, 14U, 14U,
    15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U,
    15U, 15U, 15U, 15U, 15U, 15U, 15U, 15U
};

#if (CAN_CODE_IDHIT == STD_ON)
CAN_CONST static const uint8 Can_Table_DlcToIdhitOff[16] =
{
    2U, 3U, 3U, 3U, 3U, 4U, 4U, 4U, 4U, 5U, 6U, 7U, 8U, 10U, 14U, 18U
};
#endif
#define CAN_STOP_SEC_CONST_8
#include "Can_MemMap.h"
#endif
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define CAN_START_SEC_VAR_CLEARED_32
#include "Can_MemMap.h"
CAN_VAR static const Can_ConfigType *Can_ConfigPtr;
#define CAN_STOP_SEC_VAR_CLEARED_32
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_CLEARED_BOOLEAN
#include "Can_MemMap.h"
#if (CAN_FD_USAGE == STD_ON)
CAN_VAR static boolean Can_LocFdBdrSwitch[CAN_CHANNEL_USED_NUM];
#endif
#define CAN_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Can_MemMap.h"

#if (CAN_CODE_IDHIT == STD_ON)
extern void Can_PBcfg_RxFifoIdhit(uint8 ChnLogicId, uint16 *TmpPtr);
#define CAN_START_SEC_VAR_INIT_16
#include "Can_MemMap.h"
CAN_VAR static uint16 Can_LocFifoIdhit[CAN_CHANNEL_USED_NUM] =
{
#if (CAN_CHANNEL_USED_NUM > 0)
    0xffffU,
#endif
#if (CAN_CHANNEL_USED_NUM > 1)
    0xffffU,
#endif
#if (CAN_CHANNEL_USED_NUM > 2)
    0xffffU,
#endif
#if (CAN_CHANNEL_USED_NUM > 3)
    0xffffU,
#endif
#if (CAN_CHANNEL_USED_NUM > 4)
    0xffffU,
#endif
#if (CAN_CHANNEL_USED_NUM > 5)
    0xffffU,
#endif
#if (CAN_CHANNEL_USED_NUM > 6)
    0xffffU,
#endif
#if (CAN_CHANNEL_USED_NUM > 7)
    0xffffU,
#endif
};
#define CAN_STOP_SEC_VAR_INIT_16
#include "Can_MemMap.h"
#define CAN_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"
CAN_VAR static uint16 *Can_LocFifoIdhitPtr[CAN_CHANNEL_USED_NUM];
#define CAN_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Can_MemMap.h"
#endif /* #if (CAN_CODE_IDHIT == STD_ON) */


#if ((CAN_FIXED_PB_CONFIG == STD_ON) && (CAN_FIXED_PC_LESS_MEMORY == STD_ON))

#define CAN_START_SEC_VAR_CLEARED_32
#include "Can_MemMap.h"
#if (CAN_LOGIC_CHANNEL_0_USAGE == STD_ON)
CAN_VAR static uint32 Can_0_MailBoxRegion_IdleState[CAN_0_RAM_REGION_NUM];
CAN_VAR static uint32 Can_0_MailBoxRegion_IntState[CAN_0_RAM_REGION_NUM];
#endif
#if (CAN_LOGIC_CHANNEL_1_USAGE == STD_ON)
CAN_VAR static uint32 Can_1_MailBoxRegion_IdleState[CAN_1_RAM_REGION_NUM];
CAN_VAR static uint32 Can_1_MailBoxRegion_IntState[CAN_1_RAM_REGION_NUM];
#endif
#if (CAN_LOGIC_CHANNEL_2_USAGE == STD_ON)
CAN_VAR static uint32 Can_2_MailBoxRegion_IdleState[CAN_2_RAM_REGION_NUM];
CAN_VAR static uint32 Can_2_MailBoxRegion_IntState[CAN_2_RAM_REGION_NUM];
#endif
#if (CAN_LOGIC_CHANNEL_3_USAGE == STD_ON)
CAN_VAR static uint32 Can_3_MailBoxRegion_IdleState[CAN_3_RAM_REGION_NUM];
CAN_VAR static uint32 Can_3_MailBoxRegion_IntState[CAN_3_RAM_REGION_NUM];
#endif
#if (CAN_LOGIC_CHANNEL_4_USAGE == STD_ON)
CAN_VAR static uint32 Can_4_MailBoxRegion_IdleState[CAN_4_RAM_REGION_NUM];
CAN_VAR static uint32 Can_4_MailBoxRegion_IntState[CAN_4_RAM_REGION_NUM];
#endif
#if (CAN_LOGIC_CHANNEL_5_USAGE == STD_ON)
CAN_VAR static uint32 Can_5_MailBoxRegion_IdleState[CAN_5_RAM_REGION_NUM];
CAN_VAR static uint32 Can_5_MailBoxRegion_IntState[CAN_5_RAM_REGION_NUM];
#endif
#if (CAN_LOGIC_CHANNEL_6_USAGE == STD_ON)
CAN_VAR static uint32 Can_6_MailBoxRegion_IdleState[CAN_6_RAM_REGION_NUM];
CAN_VAR static uint32 Can_6_MailBoxRegion_IntState[CAN_6_RAM_REGION_NUM];
#endif
#if (CAN_LOGIC_CHANNEL_7_USAGE == STD_ON)
CAN_VAR static uint32 Can_7_MailBoxRegion_IdleState[CAN_7_RAM_REGION_NUM];
CAN_VAR static uint32 Can_7_MailBoxRegion_IntState[CAN_7_RAM_REGION_NUM];
#endif

#if (CAN_DMA_USAGE == STD_ON)
#if ((CAN_LOGIC_CHANNEL_0_USAGE == STD_ON) && (CAN_0_DMA_USAGE == STD_ON))
#if (CAN_0_ENHANCE_FIFO_USAGE == STD_ON)
CAN_VAR static uint32 Can_0_DmaBuffer[20];
#else
CAN_VAR static uint32 Can_0_DmaBuffer[4];
#endif
#endif
#if ((CAN_LOGIC_CHANNEL_1_USAGE == STD_ON) && (CAN_1_DMA_USAGE == STD_ON))
#if (CAN_1_ENHANCE_FIFO_USAGE == STD_ON)
CAN_VAR static uint32 Can_1_DmaBuffer[20];
#else
CAN_VAR static uint32 Can_1_DmaBuffer[4];
#endif
#endif
#if ((CAN_LOGIC_CHANNEL_2_USAGE == STD_ON) && (CAN_2_DMA_USAGE == STD_ON))
#if (CAN_2_ENHANCE_FIFO_USAGE == STD_ON)
CAN_VAR static uint32 Can_2_DmaBuffer[20];
#else
CAN_VAR static uint32 Can_2_DmaBuffer[4];
#endif
#endif
#if ((CAN_LOGIC_CHANNEL_3_USAGE == STD_ON) && (CAN_3_DMA_USAGE == STD_ON))
#if (CAN_3_ENHANCE_FIFO_USAGE == STD_ON)
CAN_VAR static uint32 Can_3_DmaBuffer[20];
#else
CAN_VAR static uint32 Can_3_DmaBuffer[4];
#endif
#endif
#if ((CAN_LOGIC_CHANNEL_4_USAGE == STD_ON) && (CAN_4_DMA_USAGE == STD_ON))
#if (CAN_4_ENHANCE_FIFO_USAGE == STD_ON)
CAN_VAR static uint32 Can_4_DmaBuffer[20];
#else
CAN_VAR static uint32 Can_4_DmaBuffer[4];
#endif
#endif
#if ((CAN_LOGIC_CHANNEL_5_USAGE == STD_ON) && (CAN_5_DMA_USAGE == STD_ON))
#if (CAN_5_ENHANCE_FIFO_USAGE == STD_ON)
CAN_VAR static uint32 Can_5_DmaBuffer[20];
#else
CAN_VAR static uint32 Can_5_DmaBuffer[4];
#endif
#endif
#if ((CAN_LOGIC_CHANNEL_6_USAGE == STD_ON) && (CAN_6_DMA_USAGE == STD_ON))
#if (CAN_6_ENHANCE_FIFO_USAGE == STD_ON)
CAN_VAR static uint32 Can_6_DmaBuffer[20];
#else
CAN_VAR static uint32 Can_6_DmaBuffer[4];
#endif
#endif
#if ((CAN_LOGIC_CHANNEL_7_USAGE == STD_ON) && (CAN_7_DMA_USAGE == STD_ON))
#if (CAN_7_ENHANCE_FIFO_USAGE == STD_ON)
CAN_VAR static uint32 Can_7_DmaBuffer[20];
#else
CAN_VAR static uint32 Can_7_DmaBuffer[4];
#endif
#endif
#endif /*#if (CAN_DMA_USAGE == STD_ON)*/
#define CAN_STOP_SEC_VAR_CLEARED_32
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_CLEARED_8
#include "Can_MemMap.h"
#if (CAN_LOGIC_CHANNEL_0_USAGE == STD_ON)
#if (CAN_0_RAM_REGION_NUM > 0U)
CAN_VAR static PduIdType Can_0_MailBoxRegion_0_PduId[CAN_0_CAN_RAM_REGION_0_MB_NUM];
#endif
#if (CAN_0_RAM_REGION_NUM > 1U)
CAN_VAR static PduIdType Can_0_MailBoxRegion_1_PduId[CAN_0_CAN_RAM_REGION_1_MB_NUM];
#endif
#if (CAN_0_RAM_REGION_NUM > 2U)
CAN_VAR static PduIdType Can_0_MailBoxRegion_2_PduId[CAN_0_CAN_RAM_REGION_2_MB_NUM];
#endif
#if (CAN_0_RAM_REGION_NUM > 3U)
CAN_VAR static PduIdType Can_0_MailBoxRegion_3_PduId[CAN_0_CAN_RAM_REGION_3_MB_NUM];
#endif
#endif
#if (CAN_LOGIC_CHANNEL_1_USAGE == STD_ON)
#if (CAN_1_RAM_REGION_NUM > 0U)
CAN_VAR static PduIdType Can_1_MailBoxRegion_0_PduId[CAN_1_CAN_RAM_REGION_0_MB_NUM];
#endif
#if (CAN_1_RAM_REGION_NUM > 1U)
CAN_VAR static PduIdType Can_1_MailBoxRegion_1_PduId[CAN_1_CAN_RAM_REGION_1_MB_NUM];
#endif
#if (CAN_1_RAM_REGION_NUM > 2U)
CAN_VAR static PduIdType Can_1_MailBoxRegion_2_PduId[CAN_1_CAN_RAM_REGION_2_MB_NUM];
#endif
#if (CAN_1_RAM_REGION_NUM > 3U)
CAN_VAR static PduIdType Can_1_MailBoxRegion_3_PduId[CAN_1_CAN_RAM_REGION_3_MB_NUM];
#endif
#endif
#if (CAN_LOGIC_CHANNEL_2_USAGE == STD_ON)
#if (CAN_2_RAM_REGION_NUM > 0U)
CAN_VAR static PduIdType Can_2_MailBoxRegion_0_PduId[CAN_2_CAN_RAM_REGION_0_MB_NUM];
#endif
#if (CAN_2_RAM_REGION_NUM > 1U)
CAN_VAR static PduIdType Can_2_MailBoxRegion_1_PduId[CAN_2_CAN_RAM_REGION_1_MB_NUM];
#endif
#if (CAN_2_RAM_REGION_NUM > 2U)
CAN_VAR static PduIdType Can_2_MailBoxRegion_2_PduId[CAN_2_CAN_RAM_REGION_2_MB_NUM];
#endif
#if (CAN_2_RAM_REGION_NUM > 3U)
CAN_VAR static PduIdType Can_2_MailBoxRegion_3_PduId[CAN_2_CAN_RAM_REGION_3_MB_NUM];
#endif
#endif
#if (CAN_LOGIC_CHANNEL_3_USAGE == STD_ON)
#if (CAN_3_RAM_REGION_NUM > 0U)
CAN_VAR static PduIdType Can_3_MailBoxRegion_0_PduId[CAN_3_CAN_RAM_REGION_0_MB_NUM];
#endif
#if (CAN_3_RAM_REGION_NUM > 1U)
CAN_VAR static PduIdType Can_3_MailBoxRegion_1_PduId[CAN_3_CAN_RAM_REGION_1_MB_NUM];
#endif
#if (CAN_3_RAM_REGION_NUM > 2U)
CAN_VAR static PduIdType Can_3_MailBoxRegion_2_PduId[CAN_3_CAN_RAM_REGION_2_MB_NUM];
#endif
#if (CAN_3_RAM_REGION_NUM > 3U)
CAN_VAR static PduIdType Can_3_MailBoxRegion_3_PduId[CAN_3_CAN_RAM_REGION_3_MB_NUM];
#endif
#endif
#if (CAN_LOGIC_CHANNEL_4_USAGE == STD_ON)
#if (CAN_4_RAM_REGION_NUM > 0U)
CAN_VAR static PduIdType Can_4_MailBoxRegion_0_PduId[CAN_4_CAN_RAM_REGION_0_MB_NUM];
#endif
#if (CAN_4_RAM_REGION_NUM > 1U)
CAN_VAR static PduIdType Can_4_MailBoxRegion_1_PduId[CAN_4_CAN_RAM_REGION_1_MB_NUM];
#endif
#if (CAN_4_RAM_REGION_NUM > 2U)
CAN_VAR static PduIdType Can_4_MailBoxRegion_2_PduId[CAN_4_CAN_RAM_REGION_2_MB_NUM];
#endif
#if (CAN_4_RAM_REGION_NUM > 3U)
CAN_VAR static PduIdType Can_4_MailBoxRegion_3_PduId[CAN_4_CAN_RAM_REGION_3_MB_NUM];
#endif
#endif
#if (CAN_LOGIC_CHANNEL_5_USAGE == STD_ON)
#if (CAN_5_RAM_REGION_NUM > 0U)
CAN_VAR static PduIdType Can_5_MailBoxRegion_0_PduId[CAN_5_CAN_RAM_REGION_0_MB_NUM];
#endif
#if (CAN_5_RAM_REGION_NUM > 1U)
CAN_VAR static PduIdType Can_5_MailBoxRegion_1_PduId[CAN_5_CAN_RAM_REGION_1_MB_NUM];
#endif
#if (CAN_5_RAM_REGION_NUM > 2U)
CAN_VAR static PduIdType Can_5_MailBoxRegion_2_PduId[CAN_5_CAN_RAM_REGION_2_MB_NUM];
#endif
#if (CAN_5_RAM_REGION_NUM > 3U)
CAN_VAR static PduIdType Can_5_MailBoxRegion_3_PduId[CAN_5_CAN_RAM_REGION_3_MB_NUM];
#endif
#endif
#if (CAN_LOGIC_CHANNEL_6_USAGE == STD_ON)
#if (CAN_6_RAM_REGION_NUM > 0U)
CAN_VAR static PduIdType Can_6_MailBoxRegion_0_PduId[CAN_6_CAN_RAM_REGION_0_MB_NUM];
#endif
#if (CAN_6_RAM_REGION_NUM > 1U)
CAN_VAR static PduIdType Can_6_MailBoxRegion_1_PduId[CAN_6_CAN_RAM_REGION_1_MB_NUM];
#endif
#if (CAN_6_RAM_REGION_NUM > 2U)
CAN_VAR static PduIdType Can_6_MailBoxRegion_2_PduId[CAN_6_CAN_RAM_REGION_2_MB_NUM];
#endif
#if (CAN_6_RAM_REGION_NUM > 3U)
CAN_VAR static PduIdType Can_6_MailBoxRegion_3_PduId[CAN_6_CAN_RAM_REGION_3_MB_NUM];
#endif
#endif
#if (CAN_LOGIC_CHANNEL_7_USAGE == STD_ON)
#if (CAN_7_RAM_REGION_NUM > 0U)
CAN_VAR static PduIdType Can_7_MailBoxRegion_0_PduId[CAN_7_CAN_RAM_REGION_0_MB_NUM];
#endif
#if (CAN_7_RAM_REGION_NUM > 1U)
CAN_VAR static PduIdType Can_7_MailBoxRegion_1_PduId[CAN_7_CAN_RAM_REGION_1_MB_NUM];
#endif
#if (CAN_7_RAM_REGION_NUM > 2U)
CAN_VAR static PduIdType Can_7_MailBoxRegion_2_PduId[CAN_7_CAN_RAM_REGION_2_MB_NUM];
#endif
#if (CAN_7_RAM_REGION_NUM > 3U)
CAN_VAR static PduIdType Can_7_MailBoxRegion_3_PduId[CAN_7_CAN_RAM_REGION_3_MB_NUM];
#endif
#endif
#define CAN_STOP_SEC_VAR_CLEARED_8
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_INIT_UNSPECIFIED
#include "Can_MemMap.h"
#if (CAN_LOGIC_CHANNEL_0_USAGE == STD_ON)
CAN_VAR static PduIdType *Can_0_MailBox_PduId[CAN_0_RAM_REGION_NUM] =
{
#if (CAN_0_RAM_REGION_NUM > 0U)
    Can_0_MailBoxRegion_0_PduId,
#endif
#if (CAN_0_RAM_REGION_NUM > 1U)
    Can_0_MailBoxRegion_1_PduId,
#endif
#if (CAN_0_RAM_REGION_NUM > 2U)
    Can_0_MailBoxRegion_2_PduId,
#endif
#if (CAN_0_RAM_REGION_NUM > 3U)
    Can_0_MailBoxRegion_3_PduId,
#endif
};
#endif
#if (CAN_LOGIC_CHANNEL_1_USAGE == STD_ON)
CAN_VAR static PduIdType *Can_1_MailBox_PduId[CAN_1_RAM_REGION_NUM] =
{
#if (CAN_1_RAM_REGION_NUM > 0U)
    Can_1_MailBoxRegion_0_PduId,
#endif
#if (CAN_1_RAM_REGION_NUM > 1U)
    Can_1_MailBoxRegion_1_PduId,
#endif
#if (CAN_1_RAM_REGION_NUM > 2U)
    Can_1_MailBoxRegion_2_PduId,
#endif
#if (CAN_1_RAM_REGION_NUM > 3U)
    Can_1_MailBoxRegion_3_PduId,
#endif
};
#endif
#if (CAN_LOGIC_CHANNEL_2_USAGE == STD_ON)
CAN_VAR static PduIdType *Can_2_MailBox_PduId[CAN_2_RAM_REGION_NUM] =
{
#if (CAN_2_RAM_REGION_NUM > 0U)
    Can_2_MailBoxRegion_0_PduId,
#endif
#if (CAN_2_RAM_REGION_NUM > 1U)
    Can_2_MailBoxRegion_1_PduId,
#endif
#if (CAN_2_RAM_REGION_NUM > 2U)
    Can_2_MailBoxRegion_2_PduId,
#endif
#if (CAN_2_RAM_REGION_NUM > 3U)
    Can_2_MailBoxRegion_3_PduId,
#endif
};
#endif
#if (CAN_LOGIC_CHANNEL_3_USAGE == STD_ON)
CAN_VAR static PduIdType *Can_3_MailBox_PduId[CAN_3_RAM_REGION_NUM] =
{
#if (CAN_3_RAM_REGION_NUM > 0U)
    Can_3_MailBoxRegion_0_PduId,
#endif
#if (CAN_3_RAM_REGION_NUM > 1U)
    Can_3_MailBoxRegion_1_PduId,
#endif
#if (CAN_3_RAM_REGION_NUM > 2U)
    Can_3_MailBoxRegion_2_PduId,
#endif
#if (CAN_3_RAM_REGION_NUM > 3U)
    Can_3_MailBoxRegion_3_PduId,
#endif
};
#endif
#if (CAN_LOGIC_CHANNEL_4_USAGE == STD_ON)
CAN_VAR static PduIdType *Can_4_MailBox_PduId[CAN_4_RAM_REGION_NUM] =
{
#if (CAN_4_RAM_REGION_NUM > 0U)
    Can_4_MailBoxRegion_0_PduId,
#endif
#if (CAN_4_RAM_REGION_NUM > 1U)
    Can_4_MailBoxRegion_1_PduId,
#endif
#if (CAN_4_RAM_REGION_NUM > 2U)
    Can_4_MailBoxRegion_2_PduId,
#endif
#if (CAN_4_RAM_REGION_NUM > 3U)
    Can_4_MailBoxRegion_3_PduId,
#endif
};
#endif
#if (CAN_LOGIC_CHANNEL_5_USAGE == STD_ON)
CAN_VAR static PduIdType *Can_5_MailBox_PduId[CAN_5_RAM_REGION_NUM] =
{
#if (CAN_5_RAM_REGION_NUM > 0U)
    Can_5_MailBoxRegion_0_PduId,
#endif
#if (CAN_5_RAM_REGION_NUM > 1U)
    Can_5_MailBoxRegion_1_PduId,
#endif
#if (CAN_5_RAM_REGION_NUM > 2U)
    Can_5_MailBoxRegion_2_PduId,
#endif
#if (CAN_5_RAM_REGION_NUM > 3U)
    Can_5_MailBoxRegion_3_PduId,
#endif
};
#endif
#if (CAN_LOGIC_CHANNEL_6_USAGE == STD_ON)
CAN_VAR static PduIdType *Can_6_MailBox_PduId[CAN_6_RAM_REGION_NUM] =
{
#if (CAN_6_RAM_REGION_NUM > 0U)
    Can_6_MailBoxRegion_0_PduId,
#endif
#if (CAN_6_RAM_REGION_NUM > 1U)
    Can_6_MailBoxRegion_1_PduId,
#endif
#if (CAN_6_RAM_REGION_NUM > 2U)
    Can_6_MailBoxRegion_2_PduId,
#endif
#if (CAN_6_RAM_REGION_NUM > 3U)
    Can_6_MailBoxRegion_3_PduId,
#endif
};
#endif

#if (CAN_LOGIC_CHANNEL_7_USAGE == STD_ON)
CAN_VAR static PduIdType *Can_7_MailBox_PduId[CAN_7_RAM_REGION_NUM] =
{
#if (CAN_7_RAM_REGION_NUM > 0U)
    Can_7_MailBoxRegion_0_PduId,
#endif
#if (CAN_7_RAM_REGION_NUM > 1U)
    Can_7_MailBoxRegion_1_PduId,
#endif
#if (CAN_7_RAM_REGION_NUM > 2U)
    Can_7_MailBoxRegion_2_PduId,
#endif
#if (CAN_7_RAM_REGION_NUM > 3U)
    Can_7_MailBoxRegion_3_PduId,
#endif
};
#endif

CAN_VAR static uint32 *Can_ChHwObjIdle[CAN_CHANNEL_USED_NUM] =
{
#if (CAN_LOGIC_CHANNEL_0_USAGE == STD_ON)
    Can_0_MailBoxRegion_IdleState,
#endif
#if (CAN_LOGIC_CHANNEL_1_USAGE == STD_ON)
    Can_1_MailBoxRegion_IdleState,
#endif
#if (CAN_LOGIC_CHANNEL_2_USAGE == STD_ON)
    Can_2_MailBoxRegion_IdleState,
#endif
#if (CAN_LOGIC_CHANNEL_3_USAGE == STD_ON)
    Can_3_MailBoxRegion_IdleState,
#endif
#if (CAN_LOGIC_CHANNEL_4_USAGE == STD_ON)
    Can_4_MailBoxRegion_IdleState,
#endif
#if (CAN_LOGIC_CHANNEL_5_USAGE == STD_ON)
    Can_5_MailBoxRegion_IdleState,
#endif
#if (CAN_LOGIC_CHANNEL_6_USAGE == STD_ON)
    Can_6_MailBoxRegion_IdleState,
#endif
#if (CAN_LOGIC_CHANNEL_7_USAGE == STD_ON)
    Can_7_MailBoxRegion_IdleState,
#endif
};

CAN_VAR static uint32 *Can_ChHwObjInt[CAN_CHANNEL_USED_NUM] =
{
#if (CAN_LOGIC_CHANNEL_0_USAGE == STD_ON)
    Can_0_MailBoxRegion_IntState,
#endif
#if (CAN_LOGIC_CHANNEL_1_USAGE == STD_ON)
    Can_1_MailBoxRegion_IntState,
#endif
#if (CAN_LOGIC_CHANNEL_2_USAGE == STD_ON)
    Can_2_MailBoxRegion_IntState,
#endif
#if (CAN_LOGIC_CHANNEL_3_USAGE == STD_ON)
    Can_3_MailBoxRegion_IntState,
#endif
#if (CAN_LOGIC_CHANNEL_4_USAGE == STD_ON)
    Can_4_MailBoxRegion_IntState,
#endif
#if (CAN_LOGIC_CHANNEL_5_USAGE == STD_ON)
    Can_5_MailBoxRegion_IntState,
#endif
#if (CAN_LOGIC_CHANNEL_6_USAGE == STD_ON)
    Can_6_MailBoxRegion_IntState,
#endif
#if (CAN_LOGIC_CHANNEL_7_USAGE == STD_ON)
    Can_7_MailBoxRegion_IntState,
#endif
};

CAN_VAR static PduIdType **Can_ChHwObjPduId[CAN_CHANNEL_USED_NUM] =
{
#if (CAN_LOGIC_CHANNEL_0_USAGE == STD_ON)
    Can_0_MailBox_PduId,
#endif
#if (CAN_LOGIC_CHANNEL_1_USAGE == STD_ON)
    Can_1_MailBox_PduId,
#endif
#if (CAN_LOGIC_CHANNEL_2_USAGE == STD_ON)
    Can_2_MailBox_PduId,
#endif
#if (CAN_LOGIC_CHANNEL_3_USAGE == STD_ON)
    Can_3_MailBox_PduId,
#endif
#if (CAN_LOGIC_CHANNEL_4_USAGE == STD_ON)
    Can_4_MailBox_PduId,
#endif
#if (CAN_LOGIC_CHANNEL_5_USAGE == STD_ON)
    Can_5_MailBox_PduId,
#endif
#if (CAN_LOGIC_CHANNEL_6_USAGE == STD_ON)
    Can_6_MailBox_PduId,
#endif
#if (CAN_LOGIC_CHANNEL_7_USAGE == STD_ON)
    Can_7_MailBox_PduId,
#endif
};

#if (CAN_DMA_USAGE == STD_ON)
CAN_VAR static uint32 *Can_DmaBuffer[CAN_CHANNEL_USED_NUM] =
{
#if (CAN_LOGIC_CHANNEL_0_USAGE == STD_ON)
#if (CAN_0_DMA_USAGE == STD_ON)
    Can_0_DmaBuffer,
#else
    NULL_PTR,
#endif
#endif
#if (CAN_LOGIC_CHANNEL_1_USAGE == STD_ON)
#if (CAN_1_DMA_USAGE == STD_ON)
    Can_1_DmaBuffer,
#else
    NULL_PTR,
#endif
#endif
#if (CAN_LOGIC_CHANNEL_2_USAGE == STD_ON)
#if (CAN_2_DMA_USAGE == STD_ON)
    Can_2_DmaBuffer,
#else
    NULL_PTR,
#endif
#endif
#if (CAN_LOGIC_CHANNEL_3_USAGE == STD_ON)
#if (CAN_3_DMA_USAGE == STD_ON)
    Can_3_DmaBuffer,
#else
    NULL_PTR,
#endif
#endif
#if (CAN_LOGIC_CHANNEL_4_USAGE == STD_ON)
#if (CAN_4_DMA_USAGE == STD_ON)
    Can_4_DmaBuffer,
#else
    NULL_PTR,
#endif
#endif
#if (CAN_LOGIC_CHANNEL_5_USAGE == STD_ON)
#if (CAN_5_DMA_USAGE == STD_ON)
    Can_5_DmaBuffer,
#else
    NULL_PTR,
#endif
#endif
#if (CAN_LOGIC_CHANNEL_6_USAGE == STD_ON)
#if (CAN_6_DMA_USAGE == STD_ON)
    Can_6_DmaBuffer,
#else
    NULL_PTR,
#endif
#endif
#if (CAN_LOGIC_CHANNEL_7_USAGE == STD_ON)
#if (CAN_7_DMA_USAGE == STD_ON)
    Can_7_DmaBuffer,
#else
    NULL_PTR,
#endif
#endif
};
#endif
#define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Can_MemMap.h"

#else  /*#if((CAN_FIXED_PB_CONFIG == STD_ON) && (CAN_FIXED_PC_LESS_MEMORY == STD_ON))*/
#define CAN_START_SEC_VAR_CLEARED_32
#include "Can_MemMap.h"
CAN_VAR static uint32 Can_ChHwObjIdle[CAN_CHANNEL_USED_NUM][CAN_MAILBOX_REGION_NUM];
CAN_VAR static uint32 Can_ChHwObjInt[CAN_CHANNEL_USED_NUM][CAN_MAILBOX_REGION_NUM];
#define CAN_STOP_SEC_VAR_CLEARED_32
#include "Can_MemMap.h"

#define CAN_START_SEC_VAR_CLEARED_8
#include "Can_MemMap.h"
CAN_VAR static PduIdType Can_ChHwObjPduId[CAN_CHANNEL_USED_NUM][CAN_MAILBOX_REGION_NUM][CAN_HWOBJ_MAX];
#define CAN_STOP_SEC_VAR_CLEARED_8
#include "Can_MemMap.h"

#if (CAN_DMA_USAGE == STD_ON)
#define CAN_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Can_MemMap.h"
CAN_VAR static uint32 Can_DmaBuffer[CAN_CHANNEL_USED_NUM][20];
#define CAN_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
#include "Can_MemMap.h"

#endif
#endif /*#if((CAN_FIXED_PB_CONFIG == STD_ON) && (CAN_FIXED_PC_LESS_MEMORY == STD_ON))*/

/*==================================================================================================
*                                      EXTERN VARIABLES
==================================================================================================*/
#if (CAN_DMA_USAGE == STD_ON)
extern const CddDma_TransferConfigType *DmaChannelTransferConfigArray[CDDDMA_CHANNEL_CONFIG_COUNT];
#endif

/*==================================================================================================
*                               LOCAL INLINE FUNCTION PROTOTYPES
==================================================================================================*/
LOCAL_INLINE void Can_Lld_EnableRamAccess(uint32 BaseAddr, boolean Value);
LOCAL_INLINE void Can_Lld_InitVariable(const Can_ChannelConfigType *ChConfigPtr);
LOCAL_INLINE void Can_Lld_UpdateIdleState(uint8 ChnLogicId, uint8 RegionId, uint8 HwObjId);
LOCAL_INLINE uint32 *Can_Lld_GetMailboxAddr(const Can_ChannelConfigType *ConfigPtr, uint32 RegionId, uint32 MailBoxId);
LOCAL_INLINE void Can_Lld_InitCanModule(const Can_ChannelConfigType *ConfigPtr);
LOCAL_INLINE void Can_Lld_InitChnConfig(const Can_ChannelConfigType *ChConfigPtr);
LOCAL_INLINE Std_ReturnType Can_Lld_StopChn(const Can_ChannelConfigType *ChConfigPtr);
#if (CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON)
LOCAL_INLINE void Can_Lld_IrqProcessMailBox(uint8 IrqId, uint8 HwObjId, const Can_ChannelConfigType *ChConfigPtr);
#endif
LOCAL_INLINE uint32 Can_Lld_GetCanFrameId(const uint32 *MailBoxAddr, Can_HwObjRegionType RxFifoType);
LOCAL_INLINE void Can_Lld_ClrMailBoxIntFlag(uint32 BaseAddr, uint8 RegisterIdx, uint8 FlagIdx);
LOCAL_INLINE void Can_Lld_InitRam(const Can_ChannelConfigType *ChConfigPtr);
LOCAL_INLINE void Can_Lld_InitOneMailbox(Can_HwHandleType Hoh, uint32 MailBoxAddr, uint32 MaskAddr);
LOCAL_INLINE void Can_Lld_InitAllMsgBuf(const Can_ChannelConfigType *ChConfigPtr);
LOCAL_INLINE Std_ReturnType Can_Lld_SetClockReference(uint32 BaseAddr, Can_ControllerClockRefType ClkSrc);
LOCAL_INLINE void Can_Lld_DisableDma(const Can_ChannelConfigType *ChConfigPtr);
LOCAL_INLINE void Can_Lld_ProcessError(const Can_ChannelConfigType *ChConfigPtr);
LOCAL_INLINE const Can_ChannelConfigType *Can_Lld_GetChConfigPtr(uint8 ChHwId);
#if (CAN_FD_USAGE == STD_ON)
LOCAL_INLINE void Can_Lld_EnableErrInt(uint32 BaseAddr, boolean IsCanFD);
#else
LOCAL_INLINE void Can_Lld_EnableErrInt(uint32 BaseAddr);
#endif

#if ((CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON) || (CAN_TX_PROCESS_HAS_INTERRUPT == STD_ON))
LOCAL_INLINE void Can_Lld_EnableRxTxInterrupt(const Can_ChannelConfigType *ChConfigPtr);
#endif

/* The fellowing code is only for Enhanced fifo */
#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)
LOCAL_INLINE void Can_Lld_InitEnhRxFifo(const Can_ChannelConfigType *ChConfigPtr);
#if (CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON)
LOCAL_INLINE void Can_Lld_PrcsEnhRxFifo(const Can_ChannelConfigType *ChConfigPtr);
#endif
LOCAL_INLINE boolean Can_Lld_CheckFlagEnhFifo(const uint32 BaseAddr);
#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
LOCAL_INLINE void Can_Lld_PollingEnhFifoHrh(const Can_ChannelConfigType *ChConfigPtr);
#endif
#endif /* (CAN_ENHANCE_FIFO_USAGE == STD_ON) */

/* The fellowing code is only for Legacy fifo */
#if (CAN_LEGACY_FIFO_USAGE == STD_ON)
LOCAL_INLINE void Can_Lld_InitLgcFmtA_RxFifo(const Can_ChannelConfigType *ChConfigPtr);
LOCAL_INLINE void Can_Lld_InitLgcFmtB_RxFifo(const Can_ChannelConfigType *ChConfigPtr);
LOCAL_INLINE void Can_Lld_InitLgcFmtC_RxFifo(const Can_ChannelConfigType *ChConfigPtr);
LOCAL_INLINE void Can_Lld_InitLegacyRxFifo(const Can_ChannelConfigType *ChConfigPtr);
#if (CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON)
LOCAL_INLINE void Can_Lld_PrcsLgcRxFifo(const Can_ChannelConfigType *ChConfigPtr);
#endif
LOCAL_INLINE boolean Can_Lld_CheckLgcRxFifoFlag(uint32 BaseAddr);
#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
LOCAL_INLINE void Can_Lld_PollingLgcFifoHrh(const Can_ChannelConfigType *ChConfigPtr);
#endif
#endif /* (CAN_LEGACY_FIFO_USAGE == STD_ON) */

#if (CAN_BUSOFF_PROCESS_HAS_INTERRUPT == STD_ON)
LOCAL_INLINE void Can_Lld_EnableBusoffInt(uint32 BaseAddr);
#endif

#if (CAN_MEMECC_FEATURE == STD_ON)
LOCAL_INLINE void Can_Lld_ProcessEcc(const Can_ChannelConfigType *ChConfigPtr);
#endif

#if (CAN_FD_USAGE == STD_ON)
LOCAL_INLINE void Can_Lld_ProcessErrorFast(const Can_ChannelConfigType *ChConfigPtr);
#endif

#if (CAN_DMA_USAGE == STD_ON)
LOCAL_INLINE void Can_Lld_DmaReceiveData(uint32 ChannelId);
LOCAL_INLINE void Can_Lld_DmaReceiveError(uint32 ChannelId);
#endif
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void Can_Lld_EmptyMailbox(uint32 *Addr, Can_ObjectType RxTxType);
static Std_ReturnType Can_Lld_SetChnToFreezeMode(uint32 BaseAddr);
static Std_ReturnType Can_Lld_SetChnToNormalMode(uint32 BaseAddr);
static Std_ReturnType Can_Lld_ResetChn(uint32 BaseAddr);
static Std_ReturnType Can_Lld_DisableChn(uint32 BaseAddr);
static void Can_Lld_ClearAllFlags(const Can_ChannelConfigType *ChConfigPtr);
static void Can_Lld_LocSetBaudrate(const Can_ChannelConfigType *ChConfigPtr, const Can_BdrConfigType *BdrConfig);
static void Can_Lld_LocDisableInterrupts(const Can_ChannelConfigType *ChConfigPtr);
static boolean Can_Lld_CheckReset(uint32 BaseAddr);
static void Can_Lld_BusoffHandle(const Can_ChannelConfigType *ChConfigPtr);
static void Can_Lld_CopyMsg(const uint32 *SrcAddr, uint32 *DestAddr, uint8 CopyLen);
static void Can_Lld_HandleMsg(uint32 *MsgArray, Can_HwHandleType Hrh, const Can_ChannelConfigType *ChConfigPtr);

#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)
static void Can_Lld_CheckEnhRxFifoRx(const Can_ChannelConfigType *ChConfigPtr);
static void Can_Lld_CheckEnhRxFifoFull(const Can_ChannelConfigType *ChConfigPtr);
static void Can_Lld_CheckEnhRxFifoOvf(const Can_ChannelConfigType *ChConfigPtr);
static void Can_Lld_CheckEnhRxFifoUdf(const Can_ChannelConfigType *ChConfigPtr);
#endif /* (CAN_ENHANCE_FIFO_USAGE == STD_ON) */

#if (CAN_LEGACY_FIFO_USAGE == STD_ON)
static uint32 Can_Lld_ShiftFilter(uint32 Data, sint8 ShiftBits);
static void Can_Lld_CheckLgcRxFifoRx(const Can_ChannelConfigType *ChConfigPtr);
static void Can_Lld_CheckLgcRxFifoFull(const Can_ChannelConfigType *ChConfigPtr);
static void Can_Lld_CheckLgcRxFifoOvf(const Can_ChannelConfigType *ChConfigPtr);
#endif /* (CAN_LEGACY_FIFO_USAGE == STD_ON) */

#if((CAN_TX_PROCESS_HAS_POLLING == STD_ON) || (CAN_RX_PROCESS_HAS_POLLING == STD_ON))
static uint32 Can_Lld_GetIntFlag(uint32 BaseAddr, uint8 RegisterIdx);
#endif

#if (CAN_MEMECC_FEATURE == STD_ON)
static void Can_Lld_DisableMemEcc(uint32 BaseAddr);
static void Can_Lld_EnableMemEcc(uint32 BaseAddr);
#endif

#if (CAN_DMA_USAGE == STD_ON)
static Can_ReturnType Can_Lld_DmaConfig(const Can_ChannelConfigType *ChConfigPtr, Can_HwObjRegionType Can_FifoType);
#endif

#if (CAN_API_ABORT_CONTROLLER_PENDING_MESSAGE == STD_OFF)
static void Can_Lld_AbortPendingMsg(const Can_ChannelConfigType *ChConfigPtr);
#endif

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define CAN_START_SEC_CODE
#include "Can_MemMap.h"
#define CAN_DRIVER_CODE (STD_ON)
#if (CAN_DRIVER_CODE == STD_ON)
CAN_FUNC void Can_Lld_InstallConfigPtr(const Can_ConfigType *CanConfigPtr)
{
    Can_ConfigPtr = CanConfigPtr;
}

CAN_FUNC void Can_Lld_UnInstallConfigPtr(void)
{
    Can_ConfigPtr = NULL_PTR;
}

#if (CAN_API_GET_CONTROLLER_RX_ERROR_COUNTER == STD_ON)
CAN_FUNC uint8 Can_Lld_GetInstRxErrCounter(uint32 BaseAddr)
{
    uint8 RetVal;
    RetVal = (uint8)CAN32_INDEX_GET_BITS(BaseAddr + CAN_ECR_OFFSET32, CAN_ECR_RXERRCNT_MASK, CAN_ECR_RXERRCNT_SHIFT);
    return RetVal;
}
#endif

#if (CAN_API_GET_CONTROLLER_TX_ERROR_COUNTER == STD_ON)
CAN_FUNC uint8 Can_Lld_GetInstTxErrCounter(uint32 BaseAddr)
{
    uint8 RetVal;
    RetVal = (uint8)CAN32_INDEX_GET_BITS(BaseAddr + CAN_ECR_OFFSET32, CAN_ECR_TXERRCNT_MASK, CAN_ECR_TXERRCNT_SHIFT);
    return RetVal;
}
#endif

#if (CAN_API_GET_CONTROLLER_ERROR_STATE == STD_ON)
CAN_FUNC Can_ErrorStateType Can_Lld_GetInstErrState(uint32 BaseAddr)
{
    Can_ErrorStateType RetVal;
    uint32 Tmp32;
    Tmp32 = CAN32_INDEX_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_FLTCONF_MASK, CAN_ESR1_FLTCONF_SHIFT);
    if (Tmp32 > CAN_CONST_BUSOFF_REGISTER_ENUM)
    {
        RetVal = CAN_ERRORSTATE_BUSOFF;
    }
    else
    {
        RetVal = (Can_ErrorStateType)Tmp32;
    }
    return RetVal;
}
#endif

#if(CAN_SET_BAUDRATE_API == STD_ON)
CAN_FUNC void Can_Lld_SetBaudrate(const Can_ChannelConfigType *ChConfigPtr, const Can_BdrConfigType *BdrConfig)
{
    (void)Can_Lld_SetChnToFreezeMode(ChConfigPtr->ChBaseAddr);
    (void)Can_Lld_LocSetBaudrate(ChConfigPtr, BdrConfig);
    if ((Std_ReturnType)E_NOT_OK == Can_Lld_DisableChn(ChConfigPtr->ChBaseAddr))
    {
        (void)Can_Lld_DisableChn(ChConfigPtr->ChBaseAddr);
    }
}
#endif

#if (CAN_WAKEUP_SUPPORT == STD_ON)
CAN_FUNC boolean Can_Lld_CheckWakeupOccur(const Can_ChannelConfigType *ChConfigPtr)
{
    /* The function Can_MainFunction_Wakeup shall perform the polling of wake-up events
       that are configured statically as 'to be polled'
       Trace : SWS_Can_00112 */
    /* PRQA S 3110 ++ */
    /* The macro is defined as 0 for a uniformed code style */
    return (boolean)CAN32_GET_BITS(ChConfigPtr->ChBaseAddr, CAN_ESR1_WAKINT_MASK) >> CAN_ESR1_WAKINT_SHIFT;
    /* PRQA S 3110 --*/
}
#endif

CAN_FUNC void Can_Lld_DisableInterrupts(uint8 ChnLogicId)
{
    Can_Lld_LocDisableInterrupts(&Can_ConfigPtr->CanChCfgPtr[ChnLogicId]);
}

CAN_FUNC void  Can_Lld_EnableInterrupts(uint8 ChnLogicId)
{
    const Can_ChannelConfigType *ChConfigPtr = &Can_ConfigPtr->CanChCfgPtr[ChnLogicId];
#if((CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON) && \
    ((CAN_ENHANCE_FIFO_USAGE == STD_ON) || (CAN_LEGACY_FIFO_USAGE == STD_ON)))
    uint32 BaseAddr = (uint32)ChConfigPtr->ChBaseAddr;
#endif
    Can_Lld_LocDisableInterrupts(ChConfigPtr);
#if (CAN_FD_USAGE == STD_ON)
    Can_Lld_EnableErrInt(ChConfigPtr->ChBaseAddr, ChConfigPtr->FdUsage);
#else
    Can_Lld_EnableErrInt(ChConfigPtr->ChBaseAddr);
#endif
#if (CAN_BUSOFF_PROCESS_HAS_INTERRUPT == STD_ON)
    if (CAN_PROCESS_INTERRUPT == ChConfigPtr->CanBusoffProcessing)
    {
        Can_Lld_EnableBusoffInt(ChConfigPtr->ChBaseAddr);
    }
#endif /* (CAN_BUSOFF_PROCESS_HAS_INTERRUPT == STD_ON) */
#if (CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON)
#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)
    if (CAN_RX_FIFO_ENHANCE == ChConfigPtr->PayloadConfigPtr->RxFifoType)
    {
#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
        if (FALSE == Can_ConfigPtr->CanHohCfgPtr[ChConfigPtr->CanFifoHrhId].UsePolling)
#endif
        {
#if (CAN_DMA_USAGE == STD_ON)
            if (TRUE == ChConfigPtr->CanDmaUsage)
            {
                /* Enable enhance fifo interrupts */
                CAN32_WRITE(BaseAddr + CAN_ERFIER_OFFSET32,
                            CAN_ERFIER_ERFUFWIE(1) | CAN_ERFIER_ERFOVFIE(1));
            }
            else
#endif
            {
                /* Enable enhance fifo interrupts */
                CAN32_WRITE(BaseAddr + CAN_ERFIER_OFFSET32, CAN_ERFIER_ERFUFWIE(1) | \
                            CAN_ERFIER_ERFOVFIE(1) | CAN_ERFIER_ERFWMIIE(1) | CAN_ERFIER_ERFDAIE(1));
            }
        }
    }
#endif
#if (CAN_LEGACY_FIFO_USAGE == STD_ON)
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_05();
    if (CAN_RX_FIFO_LEGACY == ChConfigPtr->PayloadConfigPtr->RxFifoType)
    {
#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
        if (FALSE == Can_ConfigPtr->CanHohCfgPtr[ChConfigPtr->CanFifoHrhId].UsePolling)
#endif
        {
#if (CAN_DMA_USAGE == STD_ON)
            if (TRUE == ChConfigPtr->CanDmaUsage)
            {
                CAN32_AEARWRITE(BaseAddr + CAN_IMASK1_OFFSET32,
                                CAN_IFLAG1_BUF6I_MASK | CAN_IFLAG1_BUF7I_MASK,
                                CAN_IFLAG1_BUF6I(1) | CAN_IFLAG1_BUF7I(1));
            }
            else
#endif
            {
                /* Enable legacy fifo interrupts */
                CAN32_AEARWRITE(BaseAddr + CAN_IMASK1_OFFSET32,
                                CAN_IFLAG1_BUF5I_MASK | CAN_IFLAG1_BUF6I_MASK | CAN_IFLAG1_BUF7I_MASK,
                                CAN_IFLAG1_BUF5I(1) | CAN_IFLAG1_BUF6I(1) | CAN_IFLAG1_BUF7I(1));
            }
        }
    }
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_05();
#endif
#endif
    /* Enable mail box interrupts, update check, can not support Legacy Fifo */
#if ((CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON) || (CAN_TX_PROCESS_HAS_INTERRUPT == STD_ON))
    if ((CAN_PROCESS_POLLING != ChConfigPtr->CanRxProcessing) || \
            (CAN_PROCESS_POLLING != ChConfigPtr->CanTxProcessing))
    {
        Can_Lld_EnableRxTxInterrupt(ChConfigPtr);
    }
#endif
    /* Enable mail box interrupts */
}

CAN_FUNC Std_ReturnType Can_Lld_ChnInit(uint8 ChnLogicId, const Can_BdrConfigType *Bdr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint32 BaseAddr = Can_ConfigPtr->CanChCfgPtr[ChnLogicId].ChBaseAddr;
    const Can_ChannelConfigType *ChConfigPtr = &Can_ConfigPtr->CanChCfgPtr[ChnLogicId];
    /* check when SLEEP MODE is LOM MODE, need to init the Can_ChHwObjIdle? */
    Can_Lld_InitVariable(ChConfigPtr);
#if (CAN_MEMECC_FEATURE == STD_ON)
    Can_Lld_DisableMemEcc(BaseAddr);
#endif
    /* ???Pre-chech for CAN clock, The selected clock is fed to the prescaler to generate the
       serial clock (Sclock) */
    /* Set CAN clock reference and enable CAN module to normal mode */
    RetVal = Can_Lld_SetClockReference(BaseAddr, Can_ConfigPtr->CanChCfgPtr[ChnLogicId].CanTimeQuantaSource);
    if ((Std_ReturnType)E_OK == RetVal)
    {
        /* Set module to freeze mode */
        RetVal = Can_Lld_SetChnToFreezeMode(BaseAddr);
    }
    /* check if Can_Lld_ResetChn lead to ECC error */
    if ((Std_ReturnType)E_OK == RetVal)
    {
        RetVal = Can_Lld_ResetChn(BaseAddr);
#if (CAN_MEMECC_FEATURE == STD_ON)
        Can_Lld_DisableMemEcc(BaseAddr);
#endif
    }
    if ((Std_ReturnType)E_OK == RetVal)
    {
        /* Init CAN module */
        Can_Lld_InitCanModule(ChConfigPtr);
        /* Init RAM */
        Can_Lld_InitRam(ChConfigPtr);
#if (CAN_MEMECC_FEATURE == STD_ON)
        Can_Lld_EnableMemEcc(BaseAddr);
#endif
        /* Init CAN config */
        Can_Lld_InitChnConfig(ChConfigPtr);
        /* Set the bandrate of CAN and CANFD */
        Can_Lld_LocSetBaudrate(ChConfigPtr, Bdr);
        /* Config Message buffer */
        Can_Lld_InitAllMsgBuf(ChConfigPtr);
        Can_Lld_ClearAllFlags(ChConfigPtr);
        /* Set the can controller to stop mode : Disable CAN module */
        RetVal = Can_Lld_DisableChn(BaseAddr);
    }
    return RetVal;
}

CAN_FUNC Std_ReturnType Can_Lld_ModeStoppedToStarted(uint8 ChnLogicId)
{
    /* update all mode swift check */
    Std_ReturnType RetVal;
    RetVal =  Can_Lld_SetChnToNormalMode(Can_ConfigPtr->CanChCfgPtr[ChnLogicId].ChBaseAddr);
    return RetVal;
}

CAN_FUNC Std_ReturnType Can_Lld_ModeStartedToStopped(uint8 ChnLogicId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    RetVal = Can_Lld_StopChn(&Can_ConfigPtr->CanChCfgPtr[ChnLogicId]);
    return RetVal;
}

CAN_FUNC Std_ReturnType Can_Lld_ModeSleepToStopped(uint8 ChnLogicId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    const Can_ChannelConfigType *ChConfigPtr = &Can_ConfigPtr->CanChCfgPtr[ChnLogicId];
    /* PRQA S 2985 ++
     * The macro CAN_MCR_OFFSET32 is 0 and is used by a uniform code style
     */
    /* Disable Self awake */
    CAN32_CLEAR_BITS(ChConfigPtr->ChBaseAddr + CAN_MCR_OFFSET32, CAN_MCR_SLFWAK_MASK | CAN_MCR_WAKMSK_MASK);
    /* PRQA S 2985 -- */
    /* Clear Wakeup flag */
    CAN32_SET_BITS(ChConfigPtr->ChBaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_WAKINT_MASK);
    RetVal = (Std_ReturnType)E_OK;
    return RetVal;
}

CAN_FUNC Std_ReturnType Can_Lld_ModeStoppedToSleep(uint8 ChnLogicId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    const Can_ChannelConfigType *ChConfigPtr = &Can_ConfigPtr->CanChCfgPtr[ChnLogicId];
    /* Enbale Self awake */
    /* PRQA S 2985 ++
     * The macro CAN_MCR_OFFSET32 is 0 and is used by a uniform code style
     */
    CAN32_SET_BITS(ChConfigPtr->ChBaseAddr + CAN_MCR_OFFSET32, CAN_MCR_SLFWAK_MASK | CAN_MCR_WAKMSK_MASK);
    /* PRQA S 2985 -- */
    RetVal = (Std_ReturnType)E_OK;
    return RetVal;
}

#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
CAN_FUNC void Can_Lld_PeriodPollingRead(Can_HwHandleType Hrh)
{
    uint8 ChnLogicId;
    uint8 HwObjFlagId;
    uint8 HwObjMailBoxId;
    uint8 HwObjNum;
    uint8 Index;
    uint8 RegisterIdx;
    uint8 FlagIdx;
    uint32 FlagValue;
    Can_HwObjRegionType RegionId = Can_ConfigPtr->CanHohCfgPtr[Hrh].CanHwObjRegionId;
    ChnLogicId = Can_ConfigPtr->CanHohCfgPtr[Hrh].CanChannelId;
    HwObjNum = Can_ConfigPtr->CanHohCfgPtr[Hrh].CanHwObjNum;
#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)
    if (CAN_RX_FIFO_ENHANCE == RegionId)
    {
        Can_Lld_PollingEnhFifoHrh(&Can_ConfigPtr->CanChCfgPtr[ChnLogicId]);
    }
    else
#endif
#if (CAN_LEGACY_FIFO_USAGE == STD_ON)
        if (CAN_RX_FIFO_LEGACY == RegionId)
        {
            Can_Lld_PollingLgcFifoHrh(&Can_ConfigPtr->CanChCfgPtr[ChnLogicId]);
        }
        else
#endif
        {
            HwObjMailBoxId = Can_ConfigPtr->CanHohCfgPtr[Hrh].CanHwObjStartId;
            HwObjFlagId = Can_ConfigPtr->CanHohCfgPtr[Hrh].CanHwFlagStartId;
            for (Index = 0U; Index < HwObjNum; ++Index)
            {
                /* Which flag register */
                RegisterIdx = HwObjFlagId / CAN_CONST_MAILBOXNUM_PER_RAMREGION;
                /* Which bit in a flag register */
                FlagIdx = HwObjFlagId % CAN_CONST_MAILBOXNUM_PER_RAMREGION;
                FlagValue = Can_Lld_GetIntFlag(Can_ConfigPtr->CanChCfgPtr[ChnLogicId].ChBaseAddr, RegisterIdx);
                if (0U != ((FlagValue >> FlagIdx) & (uint32)1U))
                {
                    /* Clear mailbox flag */
                    const uint32 *MbAddr = Can_Lld_GetMailboxAddr(&Can_ConfigPtr->CanChCfgPtr[ChnLogicId], (uint32)RegionId, (uint32)HwObjMailBoxId);
                    const uint8 MbPayloadSize = Can_ConfigPtr->CanChCfgPtr[ChnLogicId].PayloadConfigPtr->MbRegionConfig[RegionId].PayloadSize;
                    uint32 RamArray[CAN_MB_RAM_MAX_WORD_SIZE];
                    Can_Lld_CopyMsg(MbAddr, RamArray, MbPayloadSize);
                    //Can_Lld_ClrMailBoxIntFlag(Can_ConfigPtr->CanChCfgPtr[ChnLogicId].ChBaseAddr, RegisterIdx, FlagIdx);
                    Can_Lld_HandleMsg(RamArray, Hrh, &Can_ConfigPtr->CanChCfgPtr[ChnLogicId]);
                }
                ++HwObjFlagId;
                ++HwObjMailBoxId;
            }
        }
}
#endif /*#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)*/

#if (CAN_TX_PROCESS_HAS_POLLING == STD_ON)
void Can_Lld_PeriodPollingWrite(Can_HwHandleType Hth)
{
    uint8 ChLogicId;
    uint8 HwObjFlagId;
    uint8 HwObjMailBoxId;
    uint8 Index;
    uint8 HwObjNum;
    uint8 RegisterIdx;
    uint8 FlagIdx;
    uint32 FlagValue;
    Can_HwObjRegionType RegionId = Can_ConfigPtr->CanHohCfgPtr[Hth].CanHwObjRegionId;
    Can_CallbackPtrOfTransmitType Callback;
    ChLogicId = Can_ConfigPtr->CanHohCfgPtr[Hth].CanChannelId;
    HwObjNum = Can_ConfigPtr->CanHohCfgPtr[Hth].CanHwObjNum;
    HwObjMailBoxId = Can_ConfigPtr->CanHohCfgPtr[Hth].CanHwObjStartId;
    HwObjFlagId = Can_ConfigPtr->CanHohCfgPtr[Hth].CanHwFlagStartId;
    for (Index = 0U; Index < HwObjNum; ++Index)
    {
        /* Which flag register */
        RegisterIdx = HwObjFlagId / CAN_CONST_MAILBOXNUM_PER_RAMREGION;
        /* Which bit in a flag register */
        FlagIdx = HwObjFlagId % CAN_CONST_MAILBOXNUM_PER_RAMREGION;
        FlagValue = Can_Lld_GetIntFlag(Can_ConfigPtr->CanChCfgPtr[ChLogicId].ChBaseAddr, RegisterIdx);
        if (0U != ((FlagValue >> FlagIdx) & (uint32)1U))
        {
            Can_Lld_ClrMailBoxIntFlag(Can_ConfigPtr->CanChCfgPtr[ChLogicId].ChBaseAddr, RegisterIdx, FlagIdx);

            Callback = Can_ConfigPtr->CanTransmitCallback;
            if (NULL_PTR != Callback)
            {
                Callback(Can_ChHwObjPduId[ChLogicId][RegionId][HwObjMailBoxId]);
            }
            Can_Lld_UpdateIdleState(ChLogicId, (uint8)RegionId, HwObjMailBoxId);
            /*Callback to CanIf layer to confirmation tx*/
            CanIf_TxConfirmation(Can_ChHwObjPduId[ChLogicId][RegionId][HwObjMailBoxId]);
        }
        ++HwObjFlagId;
        ++HwObjMailBoxId;
    }
}
#endif /*#if (CAN_TX_PROCESS_HAS_POLLING == STD_ON)*/

#if((CAN_TX_PROCESS_HAS_POLLING == STD_ON) || (CAN_RX_PROCESS_HAS_POLLING == STD_ON))
boolean Can_Lld_GetPollingState(const Can_HohPolTableType *HohPolTable)
{
    boolean RetVal = FALSE;
    if (0U != (*(HohPolTable->CanDiagAddr0) & HohPolTable->CanDiagMask0))
    {
        RetVal = TRUE;
    }
    if (NULL_PTR != HohPolTable->CanDiagAddr1)
    {
        if (0U != (*(HohPolTable->CanDiagAddr1) & HohPolTable->CanDiagMask1))
        {
            RetVal = TRUE;
        }
    }
    return RetVal;
}
#endif

#if (CAN_BUSOFF_PROCESS_HAS_POLLING == STD_ON)
CAN_FUNC void Can_Lld_BusoffPolling(uint8 ChnLogicId)
{
    Can_Lld_BusoffHandle(&Can_ConfigPtr->CanChCfgPtr[ChnLogicId]);
}

CAN_FUNC boolean Can_Lld_GetBusOffFlags(uint8 ChnLogicId)
{
    boolean RetVal = FALSE;
    uint32 BaseAddr = (uint32)Can_ConfigPtr->CanChCfgPtr[ChnLogicId].ChBaseAddr;
    if (0U != (CAN32_READ(BaseAddr + CAN_ESR1_OFFSET32) & CAN_BUSOFF_FLAGS_MASK))
    {
        RetVal = TRUE;
    }
    return RetVal;
}
#endif /*#if (CAN_BUSOFF_PROCESS_HAS_POLLING == STD_ON)*/

CAN_FUNC Std_ReturnType Can_Lld_GetMbState(Can_HwHandleType Hth, uint8 *MailBoxId)
{
    Can_ReturnType RetVal = CAN_BUSY;
    uint8 ChnLogicId;
    uint8 Tmp8;
    uint8 Index;
    uint8 HwObjStartId = 0U;
    ChnLogicId = Can_ConfigPtr->CanHohCfgPtr[Hth].CanChannelId;
    Can_HwObjRegionType HwObjRegionId = Can_ConfigPtr->CanHohCfgPtr[Hth].CanHwObjRegionId;
    HwObjStartId = Can_ConfigPtr->CanHohCfgPtr[Hth].CanHwObjStartId;
    /* atomic operation , for Reentrancy */
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_00();
    *MailBoxId = 0;
    for (Index = 0; Index < Can_ConfigPtr->CanHohCfgPtr[Hth].CanHwObjNum; ++Index)
    {
        Tmp8 = HwObjStartId + Index;
        if ((Can_ChHwObjIdle[ChnLogicId][HwObjRegionId] & ((uint32)1U << Tmp8)) != 0x0U)
        {
            Can_ChHwObjIdle[ChnLogicId][HwObjRegionId] &= (~((uint32)1U << Tmp8));
            *MailBoxId = Tmp8;
            RetVal = CAN_OK;
            break;
        }
    }
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_00();
    return (Std_ReturnType)RetVal;
}

CAN_FUNC void Can_Lld_WriteMailBox(Can_HwHandleType Hth, uint8 MailBoxId, const Can_PduType *PduInfo)
{
    uint8 InstId = Can_ConfigPtr->CanHohCfgPtr[Hth].CanChannelId;
    uint32 MailBoxAddr = (uint32)(Can_ConfigPtr->CanChCfgPtr[InstId].ChBaseAddr) + (uint32)(CAN_RAMN_OFFSET32(0U));
    uint16 MailBoxDatalength;
    uint16 RamLength;
    uint16 RegionId = (uint16)(Can_ConfigPtr->CanHohCfgPtr[Hth].CanHwObjRegionId);
    uint8 Index;
    uint8 DlcCode;
    uint8 AvlDataLength = PduInfo->length;
    const uint8 *PduDataPtr = PduInfo->sdu;
    boolean IsFdFrame = FALSE;
    boolean IsBrsEnable = FALSE;
    boolean IsExtendedFrame = FALSE;
    uint32 Tmp32;
#if (CAN_FD_USAGE == STD_ON)
    uint8 DlcDataLength;
    if ((TRUE == Can_ConfigPtr->CanChCfgPtr[InstId].FdUsage) && (((PduInfo->id) & CAN_ID_TYPE_FD_FRAME_MASK) != 0U))
    {
        /* Classical frame or CANFD frame */
        IsFdFrame = TRUE;
        IsBrsEnable = Can_LocFdBdrSwitch[InstId];
    }
#endif
    /* Extended frame or standard frame */
    if ((PduInfo->id & CAN_ID_TYPE_EXTENDED_FRAME_MASK) != 0U)
    {
        IsExtendedFrame = TRUE;
    }
    /* Get hardware object infomation */
    /* Get message buffer start address and mailbox size */
    MailBoxDatalength = Can_ConfigPtr->CanChCfgPtr[InstId].PayloadConfigPtr->MbRegionConfig[RegionId].PayloadSize;
    RamLength = Can_ConfigPtr->CanChCfgPtr[InstId].PayloadConfigPtr->MbRegionConfig[RegionId].PayloadRamLength;
    MailBoxAddr += (CAN_RAM_REGION_SIZE * (uint32)RegionId) + ((uint32)RamLength * (uint32)MailBoxId);
    /* Get pud information */
    if (AvlDataLength > (uint8)MailBoxDatalength)
    {
        AvlDataLength = (uint8)MailBoxDatalength;
    }
    for (Index = 0; Index < AvlDataLength; ++Index)
    {
        CAN8_WRITE(MailBoxAddr + Can_Table_FrameDataAddr[Index], PduDataPtr[Index]);
    }
    DlcCode = Can_Table_DatalengthToDlc[AvlDataLength];
#if (CAN_FD_USAGE == STD_ON)
    if ((TRUE == Can_ConfigPtr->CanChCfgPtr[InstId].FdUsage) && (CAN_CONST_FRAME_8_BYTE_FORMAT < AvlDataLength))
    {
        DlcDataLength = Can_Table_DlcToDatalength[DlcCode];
        for (; Index < DlcDataLength; ++Index)
        {
            CAN8_WRITE(MailBoxAddr + Can_Table_FrameDataAddr[Index], Can_ConfigPtr->CanHohCfgPtr[Hth].CanFdPaddingValue);
        }
    }
#endif
    /* Write ID to mail box header-1 */
    Tmp32 = CAN_MB_HERADER_1_ID_STD(PduInfo->id);
    if (TRUE == IsExtendedFrame)
    {
        Tmp32 = PduInfo->id;
    }
    CAN32_WRITE(MailBoxAddr + CAN_CONST_BYTENUM_PER_WORD, Tmp32);
    /* Remember current upper layer tx sw pdu handle */
    Can_ChHwObjPduId[InstId][RegionId][MailBoxId] = PduInfo->swPduHandle;
    /* Write control code to mail box header-0 to send message */
    Tmp32 = CAN_MB_HERADER_0_DLC(DlcCode) + CAN_MB_HERADER_0_CODE(CAN_CSCODE_TX_DATA);
    if (TRUE == IsFdFrame)
    {
        Tmp32 |= CAN_MB_HERADER_0_EDL_MASK;
    }
    if (TRUE == IsExtendedFrame)
    {
        Tmp32 |= CAN_MB_HERADER_0_IDE_MASK;
    }
    if (TRUE == IsBrsEnable)
    {
        Tmp32 |= CAN_MB_HERADER_0_BRS_MASK;
    }
    CAN32_WRITE(MailBoxAddr, Tmp32);
}

#endif
/*==================================================================================================
 *                                     LOCAL INLINE FUNCTION
==================================================================================================*/
CAN_FUNC LOCAL_INLINE uint32 Can_GetRegisterBit(uint32 Addr, uint32 BitIndex)
{
    return CAN32_INDEX_GET_BIT(Addr, BitIndex);
}

#define CAN_NECESSARY_CODE (STD_ON)
#if (CAN_NECESSARY_CODE == STD_ON)
CAN_FUNC LOCAL_INLINE void Can_Lld_EnableRamAccess(uint32 BaseAddr, boolean Value)
{
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_25();
    CAN32_AEARWRITE(BaseAddr + CAN_CTRL2_OFFSET32, CAN_CTRL2_WRMFRZ_MASK, CAN_CTRL2_WRMFRZ(Value));
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_25();
}

CAN_FUNC LOCAL_INLINE void Can_Lld_InitVariable(const Can_ChannelConfigType *ChConfigPtr)
{
    uint8 ChnLogicId = ChConfigPtr->CanChannelId;
    boolean IsPoll;
#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
    Can_ProcessType RxProcess = ChConfigPtr->CanRxProcessing;
#endif
#if (CAN_TX_PROCESS_HAS_POLLING == STD_ON)
    Can_ProcessType TxProcess = ChConfigPtr->CanTxProcessing;
#endif
    Can_HwHandleType Hoh;
    Can_HwObjRegionType RegionFlagId;
    uint16 Tmp16;
    uint8 MailboxStartId = 0U;
    uint8 MailBoxFlagId;
    uint16 MailBoxNum = ChConfigPtr->PayloadConfigPtr->ChPayloadMaxNum;
#if (((CAN_LEGACY_FIFO_USAGE == STD_ON) || (CAN_ENHANCE_FIFO_USAGE == STD_ON))&& (CAN_FIFO_IDHIT_USAGE == STD_ON))
    Can_LocFifoIdhitPtr[ChnLogicId] = &Can_LocFifoIdhit[ChnLogicId];
    Can_PBcfg_RxFifoIdhit(ChnLogicId, Can_LocFifoIdhitPtr[ChnLogicId]);
#endif
    for (uint8 Index = 0U; Index < (uint8)ChConfigPtr->PayloadConfigPtr->MbRegionNum; ++Index)
    {
        Can_ChHwObjIdle[ChnLogicId][Index] = CAN_CONST_WHOLE_OF_WORD_ALL_TRUE;
        Can_ChHwObjInt[ChnLogicId][Index]  = 0x00000000U;
    }
#if (CAN_LEGACY_FIFO_USAGE == STD_ON)
    if (CAN_RX_FIFO_LEGACY == ChConfigPtr->PayloadConfigPtr->RxFifoType)
    {
        MailboxStartId = ChConfigPtr->PayloadConfigPtr-> \
                         LegacyRxFifoConfigPtr->LegacyRxFifoOccupyMailboxNum;
    }
#endif
    for (uint8 HwObjFlagId = MailboxStartId; HwObjFlagId < MailBoxNum; ++HwObjFlagId)
    {
        MailBoxFlagId = HwObjFlagId % CAN_CONST_MAILBOXNUM_PER_RAMREGION;
        Tmp16 = (uint16)HwObjFlagId / (uint16)CAN_CONST_MAILBOXNUM_PER_RAMREGION;
        RegionFlagId = (Can_HwObjRegionType)Tmp16;
        Hoh  = ChConfigPtr->CanHwFlagMatrixPtr[HwObjFlagId].CanHohId;
        if (MB_NOT_USE != Hoh)
        {
#if ((CAN_RX_PROCESS_HAS_POLLING == STD_ON) || (CAN_TX_PROCESS_HAS_POLLING == STD_ON))
            IsPoll = Can_ConfigPtr->CanHohCfgPtr[Hoh].UsePolling;
#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
            if (CAN_RECEIVE == Can_ConfigPtr->CanHohCfgPtr[Hoh].ObjectType)
            {
                if (CAN_PROCESS_INTERRUPT == RxProcess)
                {
                    IsPoll = FALSE;
                }
                else if (CAN_PROCESS_POLLING == RxProcess)
                {
                    IsPoll = TRUE;
                }
                else
                {
                    /* here nothing to do */
                }
            }
#endif
#if (CAN_TX_PROCESS_HAS_POLLING == STD_ON)
            if (CAN_TRANSMIT == Can_ConfigPtr->CanHohCfgPtr[Hoh].ObjectType)
            {
                if (CAN_PROCESS_INTERRUPT == TxProcess)
                {
                    IsPoll = FALSE;
                }
                else if (CAN_PROCESS_POLLING == TxProcess)
                {
                    IsPoll = TRUE;
                }
                else
                {
                    /* here nothing to do */
                }
            }
#endif
#else
            IsPoll = FALSE;
#endif
            if (FALSE == IsPoll)
            {
                Can_ChHwObjInt[ChnLogicId][RegionFlagId] |= ((uint32)1U << MailBoxFlagId);
            }
        }
    }
}

CAN_FUNC LOCAL_INLINE void Can_Lld_UpdateIdleState(uint8 ChnLogicId, uint8 RegionId, uint8 HwObjId)
{
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_09();
    Can_ChHwObjIdle[ChnLogicId][RegionId] |= ((uint32)1U << HwObjId); /*NOSONAR, HwObjId has been restricted before passing parameters*/
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_09();
}

CAN_FUNC LOCAL_INLINE uint32 *Can_Lld_GetMailboxAddr(const Can_ChannelConfigType *ConfigPtr, uint32 RegionId, uint32 MailBoxId)
{
    uint32 Addr;
    uint32 BaseAddr = ConfigPtr->ChBaseAddr;
    uint8 RamLength = ConfigPtr->PayloadConfigPtr->MbRegionConfig[RegionId].PayloadRamLength;
    Addr = BaseAddr + CAN_RAM_START_OFFSET32 + (RegionId * CAN_RAM_REGION_SIZE) + ((uint32)RamLength * MailBoxId);
    return (uint32 *)Addr;
}

CAN_FUNC LOCAL_INLINE void Can_Lld_LocDisableInterrupts(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = (uint32)ChConfigPtr->ChBaseAddr;
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_16();
    /* Diable Tx/Rx interrupt */
    CAN32_CLEAR_BITS(BaseAddr, CAN_MCR_WAKMSK_MASK);
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_16();
#if (0U < CAN_MAILBOX_REGION_NUM)
    if ((uint8)ChConfigPtr->PayloadConfigPtr->MbRegionNum > 0U)
    {
        CAN32_WRITE(BaseAddr + CAN_IMASK1_OFFSET32, 0U);
    }
#endif
#if (1U < CAN_MAILBOX_REGION_NUM)
    if ((uint8)ChConfigPtr->PayloadConfigPtr->MbRegionNum > 1U)
    {
        CAN32_WRITE(BaseAddr + CAN_IMASK2_OFFSET32, 0U);
    }
#endif
#if (2U < CAN_MAILBOX_REGION_NUM)
    if ((uint8)ChConfigPtr->PayloadConfigPtr->MbRegionNum > 2U)
    {
        CAN32_WRITE(BaseAddr + CAN_IMASK3_OFFSET32, 0U);
    }
#endif
#if (3U < CAN_MAILBOX_REGION_NUM)
    if ((uint8)ChConfigPtr->PayloadConfigPtr->MbRegionNum > 3U)
    {
        CAN32_WRITE(BaseAddr + CAN_IMASK4_OFFSET32, 0U);
    }
#endif
    /* Disable busoff interrupt, error Interrupt */
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_01();
    CAN32_AEARWRITE(BaseAddr + CAN_CTRL1_OFFSET32,
                    CAN_CTRL1_BOFFMSK_MASK |
                    CAN_CTRL1_ERRMSK_MASK |
                    CAN_CTRL1_TWRNMSK_MASK |
                    CAN_CTRL1_RWRNMSK_MASK,
                    CAN_CTRL1_BOFFMSK(0) |
                    CAN_CTRL1_ERRMSK(0) |
                    CAN_CTRL1_TWRNMSK(0) |
                    CAN_CTRL1_RWRNMSK(0));
    CAN32_AEARWRITE(BaseAddr + CAN_CTRL2_OFFSET32,
                    CAN_CTRL2_ERRMSK_FAST_MASK |
                    CAN_CTRL2_BOFFDONEMSK_MASK,
                    CAN_CTRL2_ERRMSK_FAST(0) |
                    CAN_CTRL2_BOFFDONEMSK(0));
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_01();
#if (CAN_ENHANCE_FIFO_CHANNEL_NUM > 0)
    if (CAN_ENHANCE_FIFO_CHANNEL_NUM > ChConfigPtr->CanHwChId)
    {
        CAN32_WRITE(BaseAddr + CAN_ERFIER_OFFSET32, 0x00000000U);
    }
#endif
}

#if (STD_ON == CAN_FD_USAGE)
CAN_FUNC LOCAL_INLINE void Can_Lld_EnableErrInt(uint32 BaseAddr, boolean IsCanFD)
{
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_02();
    CAN32_AEARWRITE(BaseAddr +  CAN_CTRL1_OFFSET32,
                    CAN_CTRL1_ERRMSK_MASK,
                    CAN_CTRL1_ERRMSK(1));
    if (TRUE == IsCanFD)
    {
        CAN32_AEARWRITE(BaseAddr + CAN_CTRL2_OFFSET32,
                        CAN_CTRL2_ERRMSK_FAST_MASK,
                        CAN_CTRL2_ERRMSK_FAST(1));
    }
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_02();
}
#else
CAN_FUNC LOCAL_INLINE void Can_Lld_EnableErrInt(uint32 BaseAddr)
{
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_02();
    CAN32_AEARWRITE(BaseAddr +  CAN_CTRL1_OFFSET32,
                    CAN_CTRL1_ERRMSK_MASK,
                    CAN_CTRL1_ERRMSK(1));
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_02();
}
#endif

CAN_FUNC LOCAL_INLINE void Can_Lld_DisableDma(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = ChConfigPtr->ChBaseAddr;
#if (CAN_ENHANCE_FIFO_CHANNEL_NUM > 0)
    if (CAN_ENHANCE_FIFO_CHANNEL_NUM > ChConfigPtr->CanHwChId)
    {
        /* Reset Rx FIFO engine, clear enhanced Rx FIFO content */
        CAN32_WRITE(BaseAddr + CAN_ERFSR_OFFSET32, CAN_ENHANCE_FIFO_FLAGS_MASK + CAN_ERFSR_ERFCLR_MASK);
    }
#endif
    CAN32_WRITE(BaseAddr + CAN_IFLAG1_OFFSET32, CAN_CONST_BYTE0_OF_WORD_ALL_TRUE);
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_21();
    CAN32_CLEAR_BITS(BaseAddr, CAN_MCR_DMA_MASK); /* Disable DMA */
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_21();
}

CAN_FUNC LOCAL_INLINE void Can_Lld_InitOneMailbox(Can_HwHandleType Hoh, uint32 MailBoxAddr, uint32 MaskAddr)
{
    const Can_HohConfigType *HohPtr = &Can_ConfigPtr->CanHohCfgPtr[Hoh];
    if (CAN_RECEIVE == HohPtr->ObjectType)
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_08();
        /* reject remote frame */
        CAN32_CLEAR_BITS(MailBoxAddr, CAN_MB_HERADER_0_RTR_MASK);
        /* Write Filter code to the ID field of Mailbox */
        if (STANDARD == HohPtr->MsgIdType) /* STANDARD */
        {
            CAN32_CLEAR_BITS(MailBoxAddr, CAN_MB_HERADER_0_IDE_MASK);
            CAN32_WRITE(MailBoxAddr + CAN_CONST_BYTENUM_PER_WORD, (HohPtr->FilterConfig[0].FilterCode) << \
                        CAN_MB_HERADER_1_ID_STD_SHIFT);
            CAN32_WRITE(MaskAddr, (HohPtr->FilterConfig[0].MaskCode \
                                   << CAN_MB_HERADER_1_ID_STD_SHIFT) | 0x80000000U | 0x40000000U);
        }
        else if (EXTENDED == HohPtr->MsgIdType) /* EXTENDED */
        {
            CAN32_SET_BITS(MailBoxAddr, CAN_MB_HERADER_0_IDE_MASK);
            CAN32_WRITE(MailBoxAddr + CAN_CONST_BYTENUM_PER_WORD, HohPtr->FilterConfig[0].FilterCode);
            CAN32_WRITE(MaskAddr, HohPtr->FilterConfig[0].MaskCode | 0x80000000U | 0x40000000U);
        }
        else /* MIXED */
        {
            CAN32_WRITE(MailBoxAddr + CAN_CONST_BYTENUM_PER_WORD, HohPtr->FilterConfig[0].FilterCode);
            CAN32_WRITE(MaskAddr, HohPtr->FilterConfig[0].MaskCode | 0x80000000U);
        }
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_08();
        /* Write C/S code to inactive state */
        Can_Lld_EmptyMailbox((uint32 *)MailBoxAddr, CAN_RECEIVE);
    }
    /* Transimite hardware obj */
    else
    {
        Can_Lld_EmptyMailbox((uint32 *)MailBoxAddr, CAN_TRANSMIT);
    }
}

CAN_FUNC LOCAL_INLINE void Can_Lld_InitAllMsgBuf(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = ChConfigPtr->ChBaseAddr;
    Can_HwObjRegionType RegionNum = ChConfigPtr->PayloadConfigPtr->MbRegionNum;
    uint8 MailBoxNum;
    uint8 FlagHwObjId;
    Can_HwHandleType  Hoh;
    uint32 MailBoxAddr;
    uint32 RegionAddr;
    uint32 MaskAddr;
    uint32 Tmp32;
    uint32 RamLength;
    /* Caculate individual mask and mailbox 0 address */
    uint32 IdvMaskBaseAddr = BaseAddr + (uint32)(CAN_RXIMR_OFFSET32(0U));
    uint8 MailBoxStartId = 0U;
    uint32 IdvMaskCount = 0U;
#if (CAN_LEGACY_FIFO_USAGE == STD_ON)
    if (CAN_RX_FIFO_LEGACY == ChConfigPtr->PayloadConfigPtr->RxFifoType)
    {
        MailBoxStartId = ChConfigPtr->PayloadConfigPtr-> \
                         LegacyRxFifoConfigPtr->LegacyRxFifoOccupyMailboxNum;
        IdvMaskCount = MailBoxStartId;
    }
#endif/* #if (CAN_LEGACY_FIFO_USAGE == STD_ON) */
    for (uint8 RegionId = 0U; RegionId < (uint8)RegionNum; ++RegionId)
    {
        RamLength = ChConfigPtr->PayloadConfigPtr->
                    MbRegionConfig[RegionId].PayloadRamLength;
        MailBoxNum = ChConfigPtr->PayloadConfigPtr-> \
                     MbRegionConfig[RegionId].MbMsgBufferNum;
        Tmp32 = CAN_RAM_REGION_SIZE * (uint32)RegionId;
        RegionAddr = BaseAddr + (uint32)CAN_RAMN_OFFSET32(0U) + Tmp32;
        if (0U != RegionId)
        {
            MailBoxStartId = 0U;
        }
        for (uint8 Index = MailBoxStartId; Index < MailBoxNum; ++Index)
        {
            FlagHwObjId = Index;
            for (uint8 Index2 = 0U; Index2 < RegionId; ++Index2)
            {
                FlagHwObjId += ChConfigPtr->PayloadConfigPtr-> \
                               MbRegionConfig[Index2].MbMsgBufferNum;
            }
            Hoh = ChConfigPtr->CanHwFlagMatrixPtr[FlagHwObjId].CanHohId;
            Tmp32 = RamLength * (uint32)Index;
            MailBoxAddr = RegionAddr + Tmp32;
            if (MB_NOT_USE != Hoh)
            {
                MaskAddr = IdvMaskBaseAddr + ((uint32)CAN_CONST_BYTENUM_PER_WORD * IdvMaskCount);
                /* Recive and Transmit hardware obj */
                Can_Lld_InitOneMailbox(Hoh, MailBoxAddr, MaskAddr);
            }
            else
            {
                Can_Lld_EmptyMailbox((uint32 *)MailBoxAddr, CAN_TRANSMIT);
            }
            ++IdvMaskCount;
        }
    }
}

#if (CAN_API_ABORT_CONTROLLER_PENDING_MESSAGE == STD_ON)
CAN_FUNC void Can_Lld_AbortPendingMsg(const Can_ChannelConfigType *ChConfigPtr)
#else
CAN_FUNC LOCAL_INLINE void Can_Lld_AbortPendingMsg(const Can_ChannelConfigType *ChConfigPtr)
#endif
{
    uint32 BaseAddr = (uint32)ChConfigPtr->ChBaseAddr; /* NOLINT */
    uint32 FlagRegAddress;
    uint32 MaskRegAddress;
    uint32 MailBoxAddr;
    uint32 Tmp32;
    uint32 MailBoxOffsetAddr = BaseAddr + CAN_RAMN_OFFSET32(0U);
    uint16 MailBoxNum = ChConfigPtr->PayloadConfigPtr->ChPayloadMaxNum;
    uint8 MailBoxId = 0U;
    Can_HwObjRegionType RegionId = (Can_HwObjRegionType)0U;
    uint8 RamLength;
    uint8 MailBoxFlagId;
    /* Store the Idx of current MailBox flag in `Can_Table_IrqFlagIdToOffsetAddr` */
    uint8 IFlagIdx;
    Can_HwHandleType Hoh;
    uint32 TimeOutCntTemp = 0;
    boolean AbortFlag = FALSE;
    for (uint8 HwObjFlagId = 0U; HwObjFlagId < MailBoxNum; ++HwObjFlagId)
    {
        RegionId = ChConfigPtr->CanHwFlagMatrixPtr[HwObjFlagId].CanHwRegionId;
        MailBoxId = ChConfigPtr->CanHwFlagMatrixPtr[HwObjFlagId].CanHwObjId;
        Hoh  = ChConfigPtr->CanHwFlagMatrixPtr[HwObjFlagId].CanHohId;
        if ((MB_NOT_USE != Hoh) && (CAN_TRANSMIT == Can_ConfigPtr->CanHohCfgPtr[Hoh].ObjectType))
        {
            RamLength = ChConfigPtr->PayloadConfigPtr->MbRegionConfig[RegionId].PayloadRamLength;
            Tmp32 = (uint32)RegionId * (uint32)CAN_CONST_RAMBYTES_PER_RAMREGION;
            MailBoxAddr = (uint32)RamLength * (uint32)MailBoxId;
            MailBoxAddr += MailBoxOffsetAddr + Tmp32;
            MailBoxFlagId = HwObjFlagId % CAN_CONST_MAILBOXNUM_PER_RAMREGION;
            IFlagIdx = HwObjFlagId / CAN_CONST_MAILBOXNUM_PER_RAMREGION;
            FlagRegAddress = BaseAddr + Can_Table_IrqFlagIdToOffsetAddr[IFlagIdx];
            /* The offset between IFLAG and IMASK is 0x08 */
            MaskRegAddress = FlagRegAddress - CAN_CONST_MASK_FLAG_OFFSET;
            /* check if the msg has been transmitted */
            uint32 TempCode = (CAN32_READ(MailBoxAddr) & CAN_MB_HERADER_0_CODE_MASK) >> \
                              CAN_MB_HERADER_0_CODE_SHIFT;
            /* abort the msg which is not inactive */
            if ((uint32)CAN_CSCODE_TX_INACTIVE != TempCode)
            {
                /* store and clear the mask value of the MailBox to avoid interrupt pendding */
                uint32 TempMask = CAN32_READ(MaskRegAddress);
                CAN32_WRITE(MaskRegAddress, 0x00);
                /* clear transmit hardware interrupt flag */
                CAN32_WRITE(FlagRegAddress, (uint32)1U << MailBoxId);
                /* write abort code to mailbox code area */
                SchM_Enter_Can_CAN_EXCLUSIVE_AREA_12();
                CAN32_AEARWRITE(MailBoxAddr, CAN_MB_HERADER_0_CODE_MASK, \
                                (uint32)CAN_CSCODE_TX_ABORT << CAN_MB_HERADER_0_CODE_SHIFT);
                SchM_Exit_Can_CAN_EXCLUSIVE_AREA_12();
                while ((FALSE == AbortFlag) && (TimeOutCntTemp < CAN_TIMEOUT_COUNT))
                {
                    if (0U != Can_GetRegisterBit(FlagRegAddress, MailBoxFlagId))
                    {
                        CAN32_WRITE(FlagRegAddress, (uint32)1U << MailBoxId);
                        AbortFlag = TRUE;
                    }
                    /**
                     * NOTE:
                     * Here, there is no distinction made between whether the message was sent or
                     * aborted. If it is necessary to identify whether a message was sent or aborted,
                     * it is necessary to wait for the corresponding IFLAG flag and then determine
                     * the Code area of the MailBox:
                     * - 1001: Message was aborted.
                     * - 1000: Message was transmitted.
                     */
                    ++TimeOutCntTemp;
                }
                /* restore the mask value */
                CAN32_WRITE(MaskRegAddress, TempMask);
            }
            /* The MailBox Code is Inactive means the msg has already been transmitted */
        }
    }
}

CAN_FUNC LOCAL_INLINE void  Can_Lld_InitCanModule(const Can_ChannelConfigType *ConfigPtr)
{
    uint32 BaseAddr = (uint32)ConfigPtr->ChBaseAddr;
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_23();
    /* Default disable abort machanism */
    CAN32_SET_BITS(BaseAddr, CAN_MCR_AEN_MASK);
    // TODO CanTst need enable LPB
    /* Defalut disalbe self reception */
    CAN32_SET_BITS(BaseAddr, CAN_MCR_SRXDIS_MASK);
    /* Defalut disalbe loop back */
    CAN32_CLEAR_BITS(BaseAddr + CAN_CTRL1_OFFSET32, CAN_CTRL1_LPB_MASK);
    /* Defalut local priority arbitration */
    CAN32_CLEAR_BITS(BaseAddr, CAN_MCR_LPRIOEN_MASK);
    CAN32_SET_BITS(BaseAddr, CAN_MCR_WRNEN_MASK);
    /* Default set: auto response when rx remote frame request. */
    CAN32_SET_BITS(BaseAddr + CAN_CTRL2_OFFSET32, CAN_CTRL2_RRS_MASK);
    /*  Enables the comparison of both the IDE and RTR bits of an Rx mailbox filter */
    CAN32_SET_BITS(BaseAddr + CAN_CTRL2_OFFSET32, CAN_CTRL2_EACEN_MASK);
    /* Enable enhance bit time define, CTRL2[BTE] */
    CAN32_SET_BITS(BaseAddr + CAN_CTRL2_OFFSET32, CAN_CTRL2_BTE_MASK);
    if (TRUE == ConfigPtr->CanTrippleSamp)
    {
        CAN32_SET_BITS(BaseAddr + CAN_CTRL1_OFFSET32, CAN_CTRL1_SMP_MASK);
    }
    else
    {
        CAN32_CLEAR_BITS(BaseAddr + CAN_CTRL1_OFFSET32, CAN_CTRL1_SMP_MASK);
    }
    if (TRUE == ConfigPtr->CanAutoBusoffRecovery)
    {
        CAN32_CLEAR_BITS(BaseAddr + CAN_CTRL1_OFFSET32, CAN_CTRL1_BOFFREC_MASK);
    }
    else
    {
        CAN32_SET_BITS(BaseAddr + CAN_CTRL1_OFFSET32, CAN_CTRL1_BOFFREC_MASK);
    }
    /* Enable / Disable CANFD mode */
#if (CAN_FD_USAGE == STD_ON)
    if (TRUE == ConfigPtr->FdUsage)
    {
        /* Enable CANFD mode */
        CAN32_SET_BITS(BaseAddr, CAN_MCR_FDEN_MASK);
    }
    else
#endif
    {
        /* Disable CANFD mode */
        CAN32_CLEAR_BITS(BaseAddr, CAN_MCR_FDEN_MASK);
    }
    /* Set Rx message filter mask use global mask or individual mask. check */
    CAN32_SET_BITS(BaseAddr, CAN_MCR_IRMQ_MASK);
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_23();
}

CAN_FUNC LOCAL_INLINE void Can_Lld_InitRam(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = (uint32)ChConfigPtr->ChBaseAddr;
    uint32 ChnRamAddr32;
    uint32 Addr32Index;
    uint32 MailBoxMaxNum = ChConfigPtr->RamMbNum;
    /* Set CAN_CTRL2.WRMFRZ to enable write Access to all memory positions that require init */
    Can_Lld_EnableRamAccess(ChConfigPtr->ChBaseAddr, TRUE);
    /* Clear the FlexCAN message buffer */
    ChnRamAddr32 = BaseAddr + (uint32)CAN_CONST_OFFADDR_OF_MAILBOX;
    for (Addr32Index = 0U; Addr32Index < (MailBoxMaxNum * CAN_CONST_BYTENUM_PER_WORD); ++Addr32Index)
    {
        /* 0x0080 ~ 0x---- */
        CAN32_WRITE(ChnRamAddr32, 0x0U);
        ChnRamAddr32 += (uint32)CAN_CONST_BYTENUM_PER_WORD;
    }
    if (TRUE == ChConfigPtr->RamIrmqEn)
    {
        /* Clear RXIMR */
        ChnRamAddr32 = BaseAddr + (uint32)CAN_CONST_OFFADDR_OF_RXIMR;
        for (Addr32Index = 0U; Addr32Index < MailBoxMaxNum; ++Addr32Index)
        {
            /* 0x0880 ~ 0x---- */
            CAN32_WRITE(ChnRamAddr32, 0x0U);
            ChnRamAddr32 += (uint32)CAN_CONST_BYTENUM_PER_WORD;
        }
    }
#if (CAN_MEMECC_FEATURE == STD_ON)
    if (TRUE == ChConfigPtr->RamHrTimeStmpEn)
    {
        /* Clear time stamp region */
        CAN32_WRITE(BaseAddr + (uint32)CAN_CONST_OFFADDR_OF_RXTIMESTAMP0, 0x0U);
        CAN32_WRITE(BaseAddr + (uint32)CAN_CONST_OFFADDR_OF_RXTIMESTAMP1, 0x0U);
        ChnRamAddr32 = BaseAddr + (uint32)CAN_CONST_OFFADDR_OF_HRTIMESTAMP;
        for (Addr32Index = 0U; Addr32Index < MailBoxMaxNum; ++Addr32Index)
        {
            /* 0x0C30 ~ 0x---- */
            CAN32_WRITE(ChnRamAddr32, 0x0U);
            ChnRamAddr32 += (uint32)CAN_CONST_BYTENUM_PER_WORD;
        }
    }
    ChnRamAddr32 = BaseAddr + (uint32)CAN_CONST_OFFADDR_OF_RXFIR;
    for (Addr32Index = 0U; Addr32Index < CAN_CONST_RAM_WORDNUM_OF_RXFIR; ++Addr32Index)
    {
        /* 0x0A80 ~ 0x0A94 */
        CAN32_WRITE(ChnRamAddr32, 0x0U);
        ChnRamAddr32 += (uint32)CAN_CONST_BYTENUM_PER_WORD;
    }
    /* Clear Masks */
    ChnRamAddr32 = BaseAddr + (uint32)CAN_CONST_OFFADDR_OF_MASK;
    for (Addr32Index = 0U; Addr32Index < CAN_CONST_RAM_WORDNUM_OF_MASK; ++Addr32Index)
    {
        /* 0x0AA0 ~ 0x0AAC */
        CAN32_WRITE(ChnRamAddr32, 0x0U);
        ChnRamAddr32 += (uint32)CAN_CONST_BYTENUM_PER_WORD;
    }
#if (CAN_FD_USAGE == STD_ON)
    /* Clear SMB of CANFD */
    if (TRUE == ChConfigPtr->FdUsage)
    {
        ChnRamAddr32 = BaseAddr + (uint32)CAN_CONST_OFFADDR_OF_FDSMB;
        for (Addr32Index = 0U; Addr32Index < CAN_CONST_RAM_WORDNUM_OF_FDSMB; ++Addr32Index)
        {
            CAN32_WRITE(ChnRamAddr32, 0x0U);
            ChnRamAddr32 += (uint32)CAN_CONST_BYTENUM_PER_WORD;
        }
    }
    else
#endif
    {
        /* Clear SMB of Classical CAN */
        ChnRamAddr32 = BaseAddr + (uint32)CAN_CONST_OFFADDR_OF_SMB;
        for (Addr32Index = 0U; Addr32Index < CAN_CONST_RAM_WORDNUM_OF_SMB; ++Addr32Index)
        {
            CAN32_WRITE(ChnRamAddr32, 0x0U);
            ChnRamAddr32 += (uint32)CAN_CONST_BYTENUM_PER_WORD;
        }
    }
    if (TRUE == ChConfigPtr->RamEnhMbMemEn)
    {
        /* 0x1000U ~ 0x17FFU: Clear enhanced MB memory */
        ChnRamAddr32 = BaseAddr + (uint32)CAN_CONST_OFFADDR_OF_TIMESTAMP;
        for (Addr32Index = 0U; Addr32Index < CAN_CONST_RAM_WORDNUM_OF_TIMESTAMP; ++Addr32Index)
        {
            CAN32_WRITE(ChnRamAddr32, 0x0U);
            ChnRamAddr32 += (uint32)CAN_CONST_BYTENUM_PER_WORD;
        }
    }
    if (TRUE == ChConfigPtr->RamEnhFifoEn)
    {
        /* Clear enhance fifo: 0x2000U~0x2000U + (80U * 32U) - 4U */
        ChnRamAddr32 = BaseAddr + (uint32)CAN_CONST_OFFADDR_OF_ENHFIFO;
        for (Addr32Index = 0U; Addr32Index < CAN_CONST_RAM_WORDNUM_OF_ENHFIFO; ++Addr32Index)
        {
            CAN32_WRITE(ChnRamAddr32, 0x0U);
            ChnRamAddr32 += (uint32)CAN_CONST_BYTENUM_PER_WORD;
        }
        /* Clear filter elements of enhance fifo */
        ChnRamAddr32 = BaseAddr + (uint32)CAN_CONST_OFFADDR_OF_ENHFIFO_FILTER;
        for (Addr32Index = 0U; Addr32Index < CAN_CONST_RAM_WORDNUM_OF_ENHFIFO_FILTER; ++Addr32Index)
        {
            CAN32_WRITE(ChnRamAddr32, 0x0U);
            ChnRamAddr32 += (uint32)CAN_CONST_BYTENUM_PER_WORD;
        }
    }
#endif
    CAN32_WRITE(BaseAddr + CAN_RXMGMASK_OFFSET32, 0x0U);
    CAN32_WRITE(BaseAddr + CAN_RX14MASK_OFFSET32, 0x0U);
    CAN32_WRITE(BaseAddr + CAN_RX15MASK_OFFSET32, 0x0U);
    CAN32_WRITE(BaseAddr + CAN_RXFGMASK_OFFSET32, 0x0U);
    /* Clear CAN_CTRL2.WRMFRZ  to restrict write Access to memory */
    Can_Lld_EnableRamAccess(ChConfigPtr->ChBaseAddr, FALSE);
}

CAN_FUNC LOCAL_INLINE void Can_Lld_InitChnConfig(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = ChConfigPtr->ChBaseAddr;
    uint32 Tmp32;
#if ((CAN_ENHANCE_FIFO_USAGE == STD_ON) || (CAN_LEGACY_FIFO_USAGE == STD_ON))
    Can_HwObjRegionType RxFifoType = ChConfigPtr->PayloadConfigPtr->RxFifoType;
#endif
    /* Set RXMGMASK located in RAM */
    CAN32_WRITE(BaseAddr + CAN_RXMGMASK_OFFSET32, 0xFFFFFFFFU);
    /* Set RX14MASK located in RAM */
    CAN32_WRITE(BaseAddr + CAN_RX14MASK_OFFSET32, 0xFFFFFFFFU);
    /* Set RX15MASK located in RAM */
    CAN32_WRITE(BaseAddr + CAN_RX15MASK_OFFSET32, 0xFFFFFFFFU);
    /* Set RXFGMASK located in RAM */
    CAN32_WRITE(BaseAddr + CAN_RXFGMASK_OFFSET32, 0xFFFFFFFFU);
    Can_Lld_DisableDma(ChConfigPtr);
    /* Enable/Disable Rx Fifo , and config the Fifo */
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_07();
    /**
    * The channel may have an RX legacy FIFO, enhanced FIFO, or no FIFO. The different types operate as follows:
    *  * Legacy FIFO: Disable enhanced FIFO usage (if the channel supports it).
    *  * Enhanced FIFO: Disable legacy FIFO usage.
    *  * No FIFO: Disable both FIFO usages (if the channel supports them).
    */
#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)
    if (CAN_RX_FIFO_ENHANCE == RxFifoType)
    {
        /* Disable Rx Fifo */
        CAN32_CLEAR_BITS(BaseAddr, CAN_MCR_RFEN_MASK);
    }
    else
#endif
#if (CAN_LEGACY_FIFO_USAGE == STD_ON)
        if (CAN_RX_FIFO_LEGACY == RxFifoType)
        {
#if (CAN_ENHANCE_FIFO_CHANNEL_NUM > 0)
            /* Disable enhance rx fifo */
            if (CAN_ENHANCE_FIFO_CHANNEL_NUM > ChConfigPtr->CanHwChId)
            {
                CAN32_CLEAR_BITS(BaseAddr + CAN_ERFCR_OFFSET32, CAN_ERFCR_ERFEN_MASK);
            }
#endif
        }
        else
#endif/*#if (CAN_LEGACY_FIFO_USAGE == STD_ON) */
        {
#if (CAN_ENHANCE_FIFO_CHANNEL_NUM > 0)
            /* Disable enhance rx fifo */
            if (CAN_ENHANCE_FIFO_CHANNEL_NUM > ChConfigPtr->CanHwChId)
            {
                CAN32_CLEAR_BITS(BaseAddr + CAN_ERFCR_OFFSET32, CAN_ERFCR_ERFEN_MASK);
            }
#endif
            /* Disable Rx Fifo */
            CAN32_CLEAR_BITS(BaseAddr, CAN_MCR_RFEN_MASK);
        }
    /* Set Max message buffer count */
    Tmp32 = ChConfigPtr->PayloadConfigPtr->ChPayloadMaxNum - (uint32)1U;
    CAN32_AEARWRITE(BaseAddr, CAN_MCR_MAXMB_MASK, Tmp32);
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_07();
#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)
    if (CAN_RX_FIFO_ENHANCE == RxFifoType)
    {
        /* Init enhance rx fifo */
        Can_Lld_InitEnhRxFifo(ChConfigPtr);
    }
#endif
#if (CAN_LEGACY_FIFO_USAGE == STD_ON)
    if (CAN_RX_FIFO_LEGACY == RxFifoType)
    {
        /* Config the fifo */
        Can_Lld_InitLegacyRxFifo(ChConfigPtr);
    }
#endif
    /* Reset the free running timer */
    CAN32_WRITE(BaseAddr + CAN_TIMER_OFFSET32, 0x00000000U);
#if (CAN_FD_USAGE == STD_ON)
    if (TRUE == ChConfigPtr->FdUsage)
    {
        /* Clear Error flags of CANFD */
        CAN32_WRITE(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_ERRINT_FAST_MASK);
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_13();
        /* Set CANFD prtocol mode: ISO or None ISO */
        if (TRUE == ChConfigPtr->IsoModeUsage)
        {
            CAN32_SET_BITS(BaseAddr + CAN_CTRL2_OFFSET32, CAN_CTRL2_ISOCANFDEN_MASK);
        }
        else
        {
            CAN32_CLEAR_BITS(BaseAddr + CAN_CTRL2_OFFSET32, CAN_CTRL2_ISOCANFDEN_MASK);
        }
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_13();
        /* Default set TDC disable */
#if (0U < CAN_MAILBOX_REGION_NUM)
        if ((uint8)ChConfigPtr->PayloadConfigPtr->MbRegionNum > 0U)
        {
            Tmp32  = CAN_FDCTRL_MBDSR0((uint32)ChConfigPtr-> \
                                       PayloadConfigPtr->MbRegionConfig[0].MbPlSizeType);
        }
#endif
#if (1U < CAN_MAILBOX_REGION_NUM)
        if ((uint8)ChConfigPtr->PayloadConfigPtr->MbRegionNum > 1U)
        {
            Tmp32 += CAN_FDCTRL_MBDSR1((uint32)(ChConfigPtr-> \
                                                PayloadConfigPtr->MbRegionConfig[1].MbPlSizeType));
        }
#endif
#if (2U < CAN_MAILBOX_REGION_NUM)
        if ((uint8)ChConfigPtr->PayloadConfigPtr->MbRegionNum > 2U)
        {
            Tmp32 += CAN_FDCTRL_MBDSR2((uint32)(ChConfigPtr-> \
                                                PayloadConfigPtr->MbRegionConfig[2].MbPlSizeType));
        }
#endif
#if (3U < CAN_MAILBOX_REGION_NUM)
        if ((uint8)ChConfigPtr->PayloadConfigPtr->MbRegionNum > 3U)
        {
            Tmp32 += CAN_FDCTRL_MBDSR3((uint32)(ChConfigPtr-> \
                                                PayloadConfigPtr->MbRegionConfig[3].MbPlSizeType));
        }
#endif
    }
    CAN32_WRITE(BaseAddr + CAN_FDCTRL_OFFSET32, Tmp32);
#else
    CAN32_WRITE(BaseAddr + CAN_FDCTRL_OFFSET32, 0x00000000U);
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_13();
    CAN32_CLEAR_BITS(BaseAddr + CAN_CTRL2_OFFSET32, CAN_CTRL2_ISOCANFDEN_MASK);
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_13();
#endif
}

CAN_FUNC LOCAL_INLINE void Can_Lld_ClearAllFlags(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = (uint32)ChConfigPtr->ChBaseAddr;
    /* Clear flags */
#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)
    uint8 EnhFifoFrameCnt = 0U;
    if (CAN_ENHANCE_FIFO_CHANNEL_NUM > ChConfigPtr->CanHwChId)
    {
        /* Clear enhance fifo interrupt flag */
        CAN32_WRITE(BaseAddr + CAN_ERFSR_OFFSET32, 0xE0000000U);
        while ((TRUE == Can_Lld_CheckFlagEnhFifo(ChConfigPtr->ChBaseAddr)) && (EnhFifoFrameCnt < CAN_CONST_ENHANCE_FIFO_DEPTH))
        {
            CAN32_WRITE(BaseAddr + CAN_ERFSR_OFFSET32, CAN_ERFSR_ERFDA_MASK);
            ++EnhFifoFrameCnt;
        }
    }
#endif
    /* Clear Message buffer interrupt flag */
#if (0U < CAN_MAILBOX_REGION_NUM)
    if ((uint8)ChConfigPtr->PayloadConfigPtr->MbRegionNum > 0U)
    {
        CAN32_WRITE(BaseAddr + CAN_IFLAG1_OFFSET32, 0xFFFFFFFFU);
    }
#endif
#if (1U < CAN_MAILBOX_REGION_NUM)
    if ((uint8)ChConfigPtr->PayloadConfigPtr->MbRegionNum > 1U)
    {
        CAN32_WRITE(BaseAddr + CAN_IFLAG2_OFFSET32, 0xFFFFFFFFU);
    }
#endif
#if (2U < CAN_MAILBOX_REGION_NUM)
    if ((uint8)ChConfigPtr->PayloadConfigPtr->MbRegionNum > 2U)
    {
        CAN32_WRITE(BaseAddr + CAN_IFLAG3_OFFSET32, 0xFFFFFFFFU);
    }
#endif
#if (3U < CAN_MAILBOX_REGION_NUM)
    if ((uint8)ChConfigPtr->PayloadConfigPtr->MbRegionNum > 3U)
    {
        CAN32_WRITE(BaseAddr + CAN_IFLAG4_OFFSET32, 0xFFFFFFFFU);
    }
#endif
    /* Clear Error flags of classical CAN */
    CAN32_WRITE(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_WAKINT_MASK | CAN_ESR1_ERRINT_MASK | \
                CAN_ESR1_BOFFINT_MASK | CAN_ESR1_BOFFDONEINT_MASK | CAN_ESR1_ERROVR_MASK);
}

CAN_FUNC LOCAL_INLINE void Can_Lld_LocSetBaudrate(const Can_ChannelConfigType *ChConfigPtr, const Can_BdrConfigType *BdrConfig)
{
    uint32 BaseAddr = (uint32)ChConfigPtr->ChBaseAddr;
    uint32 Tmp32Div;
#if (CAN_FD_USAGE == STD_ON)
    uint32 Tmp32Etdc;
#endif
    boolean FdrateFlag = FALSE;
    /* Set PTS, PBS1, PBS2, SJW */
    CAN32_WRITE(BaseAddr + CAN_ENCBT_OFFSET32,
                (((uint32)BdrConfig->CanPropSeg + (uint32)BdrConfig->CanSeg1 - (uint32)1U)) | \
                (((uint32)BdrConfig->CanSeg2 - (uint32)1U) << CAN_ENCBT_NTSEG2_SHIFT) | \
                (((uint32)BdrConfig->CanSyncJumpWidth - (uint32)1U) << CAN_ENCBT_NRJW_SHIFT));
    /* Get classical CAN pre-divider */
    Tmp32Div = (uint32)BdrConfig->CanPreDiv - (uint32)1U;
#if (CAN_FD_USAGE == STD_ON)
    /* Set FD CAN baudrate */
    Can_LocFdBdrSwitch[ChConfigPtr->CanChannelId] = FALSE;
    if (TRUE == ChConfigPtr->FdUsage)
    {
        Can_LocFdBdrSwitch[ChConfigPtr->CanChannelId] = BdrConfig->CanFdBdrConfig->CanFdTxBdrSwitch;
        /* Get CANFD switch pre-divider */
        Tmp32Div += (((uint32)BdrConfig->CanFdBdrConfig->CanFdPreDiv - (uint32)1U) << CAN_EPRS_EDPRESDIV_SHIFT);
        /* Set PTS, PBS1, PBS2, SJW */
        CAN32_WRITE(BaseAddr + CAN_EDCBT_OFFSET32,
                    (((uint32)BdrConfig->CanFdBdrConfig->CanFdPropSeg + (uint32)BdrConfig->CanFdBdrConfig->CanFdSeg1 - (uint32)1U)) |
                    (((uint32)BdrConfig->CanFdBdrConfig->CanFdSeg2 - (uint32)1U) << CAN_EDCBT_DTSEG2_SHIFT) |
                    (((uint32)BdrConfig->CanFdBdrConfig->CanFdSyncJumpWidth - (uint32)1U) << CAN_EDCBT_DRJW_SHIFT));
        /* Set tdcoff */
        CAN32_WRITE(BaseAddr + CAN_ETDC_OFFSET32, 0x00000000U);
        if ((FALSE != BdrConfig->CanFdBdrConfig->CanFdTxBdrSwitch))
        {
            FdrateFlag = TRUE;
            Tmp32Etdc = CAN_ETDC_ETDCEN_MASK;
            if (0U != BdrConfig->CanFdBdrConfig->CanFdTdcOffset)
            {
                Tmp32Etdc += CAN_ETDC_ETDCOFF(BdrConfig->CanFdBdrConfig->CanFdTdcOffset);
            }
            CAN32_WRITE(BaseAddr + CAN_ETDC_OFFSET32, Tmp32Etdc);
        }
    }
#endif /* (CAN_FD_USAGE == STD_ON) */
    /* Set pre-divider */
    CAN32_WRITE(BaseAddr + CAN_EPRS_OFFSET32, Tmp32Div);
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_18();
    /* Set brs*/
    if (TRUE == FdrateFlag)
    {
        CAN32_SET_BITS(BaseAddr + CAN_FDCTRL_OFFSET32, CAN_FDCTRL_FDRATE_MASK);
    }
    else
    {
        CAN32_CLEAR_BITS(BaseAddr + CAN_FDCTRL_OFFSET32, CAN_FDCTRL_FDRATE_MASK);
    }
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_18();
}

CAN_FUNC LOCAL_INLINE Std_ReturnType Can_Lld_SetChnToNormalMode(uint32 BaseAddr)
{
    Std_ReturnType RetVal = E_NOT_OK;
    uint32 TimeOutCntTemp = 0;
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_06();
    /* Enable CAN module and set to normal mode */
    CAN32_CLEAR_BITS(BaseAddr, CAN_MCR_MDIS_MASK);
    CAN32_CLEAR_BITS(BaseAddr, CAN_MCR_HALT_MASK);
    CAN32_CLEAR_BITS(BaseAddr, CAN_MCR_FRZ_MASK);
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_06();
    while ((0U != CAN32_GET_BITS(BaseAddr + CAN_MCR_OFFSET32, CAN_MCR_NOTRDY_MASK)) && \
            (TimeOutCntTemp < CAN_TIMEOUT_COUNT))
    {
        ++TimeOutCntTemp;
    }
    /* If time out, return E_NOT_OK */
    if (TimeOutCntTemp < CAN_TIMEOUT_COUNT)
    {
        RetVal = (Std_ReturnType)E_OK;
    }
    return RetVal;
}

CAN_FUNC LOCAL_INLINE Std_ReturnType Can_Lld_StopChn(const Can_ChannelConfigType *ChConfigPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    /* After bus-off detection, the Can module shall cancel still pending messages
           Trace : SWS_Can_00273 */
    Can_Lld_AbortPendingMsg(ChConfigPtr);
    RetVal = Can_Lld_SetChnToFreezeMode(ChConfigPtr->ChBaseAddr);
    Can_Lld_ClearAllFlags(ChConfigPtr);
    if ((Std_ReturnType)E_OK == RetVal)
    {
        /* Disabling of CAN interrupts shall not be executed, when CAN interrupts have been \
           disabled by function Can_DisableControllerInterrupts
           Trace : SWS_Can_00426 */
        if (TRUE == Can_Bak_GetInterruptState(ChConfigPtr->CanChannelId))
        {
            Can_Lld_LocDisableInterrupts(ChConfigPtr);
        }
        /* The function Can_SetControllerMode shall perform software triggered state
           transitions of the CAN controller State machine.
           Trace : SWS_Can_00017 */
        (void)Can_Bak_SetCanStatusToStopped(ChConfigPtr->CanChannelId);
    }
    return RetVal;
}

CAN_FUNC LOCAL_INLINE uint32 Can_Lld_GetCanFrameId(const uint32 *MailBoxAddr, Can_HwObjRegionType RxFifoType)
{
    uint32 CanId;
    if (0U != (MailBoxAddr[0] & CAN_MB_HERADER_0_IDE_MASK))
    {
        /* Get rx message ID: extended frame */
        CanId = MailBoxAddr[1] & CAN_MB_HERADER_1_ID_EXT_MASK;
        CanId |= CAN_ID_TYPE_EXTENDED_FRAME_MASK;
    }
    else
    {
        /* Get rx message ID: standard frame */
        CanId = (MailBoxAddr[1] & CAN_MB_HERADER_1_ID_STD_MASK) >> CAN_MB_HERADER_1_ID_STD_SHIFT;
    }
#if (CAN_FD_USAGE == STD_ON)
    if ((CAN_RX_FIFO_LEGACY != RxFifoType) && (0U != (MailBoxAddr[0] & CAN_MB_HERADER_0_EDL_MASK)))
    {
        CanId |= CAN_ID_TYPE_FD_FRAME_MASK;
    }
#endif
    return CanId;
}

CAN_FUNC LOCAL_INLINE uint8 Can_Lld_GetPayloadRamSize(const Can_ChannelConfigType *ChConfigPtr, Can_HwObjRegionType RegionId)
{
    uint8 Res = 0U;
    switch (RegionId)
    {
#if (CAN_LEGACY_FIFO_USAGE == STD_ON)
        case CAN_RX_FIFO_LEGACY:
            Res = 8U;
            break;
#endif /* (CAN_LEGACY_FIFO_USAGE == STD_ON) */
#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)
        case CAN_RX_FIFO_ENHANCE:
            Res = 64U;
            break;
#endif /* (CAN_ENHANCE_FIFO_USAGE == STD_ON) */
        default:
            Res = (uint8)ChConfigPtr->PayloadConfigPtr->MbRegionConfig[RegionId].PayloadSize;
            break;
    }
    return Res;
}

CAN_FUNC LOCAL_INLINE void Can_Lld_CopyMsg(const uint32 *SrcAddr, uint32 *DestAddr, uint8 CopyLen)
{
    uint8 PayloadCopyCnt = (CopyLen / 4U) + 2U;
    /* Lock MB */
    DestAddr[0] = SrcAddr[0];
    DestAddr[1] = SrcAddr[1];
    for (uint8 Index = 2U; Index < PayloadCopyCnt; ++Index)
    {
        DestAddr[Index] = SrcAddr[Index];
    }
    /* Unlock MB, Read Timer register to unlock the MB */
    CAN32_READ(((uint32)SrcAddr & CAN_BASE_ADDR_MASK) + CAN_TIMER_OFFSET32);
}

CAN_FUNC LOCAL_INLINE void Can_Lld_HandleMsg(uint32 *MsgArray, Can_HwHandleType Hrh, const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 DlcCode = (MsgArray[0] & CAN_MB_HERADER_0_DLC_MASK) >> CAN_MB_HERADER_0_DLC_SHIFT;
    PduInfoType PduInfo;
    PduInfo.SduLength = (PduLengthType)Can_Table_DlcToDatalength[(uint8)DlcCode];
    Can_HwObjRegionType RegionId = Can_ConfigPtr->CanHohCfgPtr[Hrh].CanHwObjRegionId;
    Can_HwType MailBoxInfo;
    MailBoxInfo.Hoh = Hrh;
    MailBoxInfo.ControllerId = ChConfigPtr->CanChannelId;
    MailBoxInfo.CanId = Can_Lld_GetCanFrameId(MsgArray, RegionId);
    /**
     * byte0 is MB status code, byte1 is id, regardless of the DLC that is transmitted, copy a
     * polygon Size data at a time
     */
    uint8 PayloadRamSize = Can_Lld_GetPayloadRamSize(ChConfigPtr, RegionId);
    /** Actrual DLC may greater than payloadSize */
    if (PayloadRamSize < PduInfo.SduLength)
    {
        PduInfo.SduLength = PayloadRamSize;
    }
    PduInfo.SduDataPtr = (uint8 *)&MsgArray[CAN_MB_RAM_DATA_OFFSET];
    /* Convert all word to big endian */
    for (uint8 WordIndex = 0U; WordIndex < CAN_CEIL_WORD(PduInfo.SduLength); WordIndex++)
    {
        uint32 Value = MsgArray[WordIndex + 2U]; /* NOSONAR The uninited area of array will not reach */
        MsgArray[WordIndex + 2U] = CAN_SWAP_BYTES32(Value);
    }
#if (CAN_CODE_IDHIT == STD_ON)
    uint8 ChnLogicId = ChConfigPtr->CanChannelId;
    uint16 Idhit = CAN_CONST_WHOLE_OF_DBYTE_ALL_TRUE;
    switch (RegionId)
    {
#if (CAN_ENHANCE_FIFO_USAGE == STD_ON) /* Handle Enhanced fifo receive */
        case CAN_RX_FIFO_ENHANCE:
        {
            /** Because the Fifo does not require timely unlocking the MB, real pointers can be used. */
            Idhit = (uint16)MsgArray[Can_Table_DlcToIdhitOff[DlcCode]] & CAN_ENHANCE_RXFIFO_IDHIT_MASK;
            break;
        }
#endif /* (CAN_ENHANCE_FIFO_USAGE == STD_ON) */
#if (CAN_LEGACY_FIFO_USAGE == STD_ON) /* Handle legacy fifo receive */
        case CAN_RX_FIFO_LEGACY:
        {
            /** Because the Fifo does not require timely unlocking the MB, real pointers can be used. */
            Idhit = (uint16)((MsgArray[0] & CAN_LEGACY_RXFIFO_IDHIT_MASK) >> CAN_LEGACY_RXFIFO_IDHIT_SHIFT);
            break;
        }
#endif /* (CAN_LEGACY_FIFO_USAGE == STD_ON) */
        default:
        {
            if ((uint32)CAN_CSCODE_RX_OVERRUN == ((MsgArray[0] & CAN_MB_HERADER_0_CODE_MASK) >> CAN_MB_HERADER_0_CODE_SHIFT))
            {
                /* CAN_CSCODE_RX_OVERRUN */
                /* Can module shall raise the runtime error CAN_E_DATALOST in case of "overwrite" or
                "overrun" event detection.
                Trace SWS_Can_00395 */
                Can_Bak_CallDatalost(ChConfigPtr->CanChannelId);
                if (NULL_PTR != ChConfigPtr->CanCallbackPtr->OverrunCallback)
                {
                    ChConfigPtr->CanCallbackPtr->OverrunCallback(Hrh);
                }
            }
            break;
        }
    }
    if (NULL_PTR != Can_LocFifoIdhitPtr[ChnLogicId])
    {
        *Can_LocFifoIdhitPtr[ChnLogicId] = Idhit;
    }
#else
    switch (RegionId)
    {
#if (CAN_ENHANCE_FIFO_USAGE == STD_ON) /* Handle Enhanced fifo receive */
        case CAN_RX_FIFO_ENHANCE:
        {
            break;
        }
#endif /* (CAN_ENHANCE_FIFO_USAGE == STD_ON) */
#if (CAN_LEGACY_FIFO_USAGE == STD_ON) /* Handle legacy fifo receive */
        case CAN_RX_FIFO_LEGACY:
        {
            break;
        }
#endif /* (CAN_LEGACY_FIFO_USAGE == STD_ON) */
        default:
        {
            if ((uint32)CAN_CSCODE_RX_OVERRUN == ((MsgArray[0] & CAN_MB_HERADER_0_CODE_MASK) >> CAN_MB_HERADER_0_CODE_SHIFT))
            {
                /* CAN_CSCODE_RX_OVERRUN */
                /* Can module shall raise the runtime error CAN_E_DATALOST in case of "overwrite" or
                "overrun" event detection.
                Trace SWS_Can_00395 */
                Can_Bak_CallDatalost(ChConfigPtr->CanChannelId);
                if (NULL_PTR != ChConfigPtr->CanCallbackPtr->OverrunCallback)
                {
                    ChConfigPtr->CanCallbackPtr->OverrunCallback(Hrh);
                }
            }
            break;
        }
    }
#endif /* (CAN_CODE_IDHIT == STD_ON) */
    Can_CallbackPtrOfReceiveType Callback = Can_ConfigPtr->CanReceiveCallback;
    if (NULL_PTR == Callback)
    {
        CanIf_RxIndication(&MailBoxInfo, &PduInfo);
    }
    else
    {
        if (TRUE == Callback(MailBoxInfo.Hoh, MailBoxInfo.CanId, (uint8)(PduInfo.SduLength), PduInfo.SduDataPtr))
        {
            CanIf_RxIndication(&MailBoxInfo, &PduInfo);
        }
    }
#if (CAN_CODE_IDHIT == STD_ON)
    if (NULL_PTR != Can_LocFifoIdhitPtr[ChnLogicId])
    {
        *Can_LocFifoIdhitPtr[ChnLogicId] = CAN_CONST_WHOLE_OF_DBYTE_ALL_TRUE;
    }
#endif
}

CAN_FUNC LOCAL_INLINE void Can_Lld_ClrMailBoxIntFlag(uint32 BaseAddr, uint8 RegisterIdx, uint8 FlagIdx)
{
    uint32 FlagRegAddress;
    FlagRegAddress = BaseAddr + Can_Table_IrqFlagIdToOffsetAddr[RegisterIdx]; /* NOSONAR: RegionFlagId is always smaller than 4 */
    /* Set 1 to clear interrupt flag */
    if(FlagIdx <33)
    {
        CAN32_WRITE(FlagRegAddress, (uint32)1U << FlagIdx);
    }

}

CAN_FUNC LOCAL_INLINE Std_ReturnType Can_Lld_ResetChn(uint32 BaseAddr)
{
    uint32 TimeOutCntTemp = 0U;
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_10();
    /* Enable can module */
    CAN32_CLEAR_BITS(BaseAddr, CAN_MCR_MDIS_MASK);
    /* Disable Freeze mode */
    CAN32_CLEAR_BITS(BaseAddr, CAN_MCR_FRZ_MASK);
    CAN32_CLEAR_BITS(BaseAddr, CAN_MCR_HALT_MASK);
    /* Reset the FlexCan by software reset */
    CAN32_SET_BITS(BaseAddr, CAN_MCR_SOFTRST_MASK);
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_10();
    /* Wait for reset cycle to complete */
    while ((FALSE == Can_Lld_CheckReset(BaseAddr)) && (TimeOutCntTemp < CAN_TIMEOUT_COUNT))
    {
        ++TimeOutCntTemp;
    }
    /* Timeout check, if timeout, return go to freeze mode failed */
    if (TimeOutCntTemp >= CAN_TIMEOUT_COUNT)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        RetVal = (Std_ReturnType)E_OK;
    }
    /* Disable can module */
    return RetVal;
}


CAN_FUNC LOCAL_INLINE Std_ReturnType Can_Lld_SetClockReference(uint32 BaseAddr, Can_ControllerClockRefType ClkSrc)
{
    uint32 TimeOutCntTemp = 0U;
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    /* Set Controller to Disable Module */
    RetVal = Can_Lld_DisableChn(BaseAddr);
    if ((Std_ReturnType)E_OK == RetVal)
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_24();
        /* Set CAN engine clock source */
        if (ClkSrc == CAN_CLOCK_SOURCE_OSC)
        {
            CAN32_CLEAR_BITS(BaseAddr + CAN_CTRL1_OFFSET32, CAN_CTRL1_CLKSRC_MASK);
        }
        else
        {
            CAN32_SET_BITS(BaseAddr + CAN_CTRL1_OFFSET32, CAN_CTRL1_CLKSRC_MASK);
        }
        /* Enable Module */
        CAN32_CLEAR_BITS(BaseAddr, CAN_MCR_MDIS_MASK);
        CAN32_CLEAR_BITS(BaseAddr, CAN_MCR_FRZ_MASK);
        CAN32_CLEAR_BITS(BaseAddr, CAN_MCR_HALT_MASK);
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_24();
        while (((uint32)CAN_MCR_NOTRDY_MASK == CAN32_GET_BITS(BaseAddr + \
                CAN_MCR_OFFSET32, CAN_MCR_NOTRDY_MASK)) && (TimeOutCntTemp < CAN_TIMEOUT_COUNT))
        {
            ++TimeOutCntTemp;
        }
        /* If time out, return E_NOT_OK */
        if (TimeOutCntTemp >= CAN_TIMEOUT_COUNT)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    return RetVal;
}

CAN_FUNC LOCAL_INLINE Std_ReturnType Can_Lld_DisableChn(uint32 BaseAddr)
{
    uint32 TimeOutCntTemp = 0;
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    if (0U == CAN32_GET_BITS(BaseAddr, CAN_MCR_MDIS_MASK))
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_17();
        /* If Module Enabled , Disable Module */
        CAN32_SET_BITS(BaseAddr, CAN_MCR_MDIS_MASK);
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_17();
        /* Wait for low power mode acknowledgement */
        while ((0U == CAN32_GET_BITS(BaseAddr + CAN_MCR_OFFSET32, CAN_MCR_LPMACK_MASK)) && \
                (TimeOutCntTemp < CAN_TIMEOUT_COUNT))
        {
            ++TimeOutCntTemp;
        }
        /* If time out, return E_NOT_OK */
        if (TimeOutCntTemp >= CAN_TIMEOUT_COUNT)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    return RetVal;
}

CAN_FUNC LOCAL_INLINE void Can_Lld_ProcessError(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = (uint32)ChConfigPtr->ChBaseAddr;
    if (0U != CAN32_GET_BITS(BaseAddr + CAN_CTRL1_OFFSET32, CAN_CTRL1_ERRMSK_MASK))
    {
        if (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_ERROVR_MASK))
        {
            if (NULL_PTR != ChConfigPtr->CanCallbackPtr->ErrorCallback)
            {
                ChConfigPtr->CanCallbackPtr->ErrorCallback(CAN_ERROR_OVERRUN);
            }
            CAN32_WRITE(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_ERROVR_MASK);
        }
        if ((0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_ERRINT_MASK)) && \
                (NULL_PTR != ChConfigPtr->CanCallbackPtr->ErrorCallback))
        {
            /* GCOVR_EXCL_START: The fellowing could not be coverd by integration test */
            if (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_BIT1ERR_MASK))
            {
                ChConfigPtr->CanCallbackPtr->ErrorCallback(CAN_ERROR_BIT1ERR);
            }
            if (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_BIT0ERR_MASK))
            {
                ChConfigPtr->CanCallbackPtr->ErrorCallback(CAN_ERROR_BIT0ERR);
            }
            if (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_ACKERR_MASK))
            {
                ChConfigPtr->CanCallbackPtr->ErrorCallback(CAN_ERROR_ACKERR);
            }
            if (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_CRCERR_MASK))
            {
                ChConfigPtr->CanCallbackPtr->ErrorCallback(CAN_ERROR_CRCERR);
            }
            if (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_FRMERR_MASK))
            {
                ChConfigPtr->CanCallbackPtr->ErrorCallback(CAN_ERROR_FRMERR);
            }
            if (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_STFERR_MASK))
            {
                ChConfigPtr->CanCallbackPtr->ErrorCallback(CAN_ERROR_STFERR);
            }
            /* GCOVR_EXCL_STOP */
        }
        if (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_ERRINT_MASK))
        {
            CAN32_WRITE(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_ERRINT_MASK);
        }
    }
}

LOCAL_INLINE const Can_ChannelConfigType *Can_Lld_GetChConfigPtr(uint8 ChHwId)
{
    return &Can_ConfigPtr->CanChCfgPtr[Can_ConfigPtr->CanHwIdTable[ChHwId]];
}
#endif

#define CAN_CONDITIONALCOMPILATION_CODE (STD_ON)
#if (CAN_CONDITIONALCOMPILATION_CODE == STD_ON)
#if (CAN_BUSOFF_PROCESS_HAS_INTERRUPT == STD_ON)
CAN_FUNC LOCAL_INLINE void Can_Lld_EnableBusoffInt(uint32 BaseAddr)
{
    /* Enable busoff Interrupt */
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_03();
    CAN32_AEARWRITE(BaseAddr + CAN_CTRL1_OFFSET32,
                    CAN_CTRL1_BOFFMSK_MASK |
                    CAN_CTRL1_TWRNMSK_MASK |
                    CAN_CTRL1_RWRNMSK_MASK,
                    CAN_CTRL1_BOFFMSK(1) |
                    CAN_CTRL1_TWRNMSK(1) |
                    CAN_CTRL1_RWRNMSK(1));
    CAN32_AEARWRITE(BaseAddr + CAN_CTRL2_OFFSET32,
                    CAN_CTRL2_BOFFDONEMSK_MASK,
                    CAN_CTRL2_BOFFDONEMSK(1));
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_03();
}
#endif

#if ((CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON) || (CAN_TX_PROCESS_HAS_INTERRUPT == STD_ON))
CAN_FUNC LOCAL_INLINE void Can_Lld_EnableRxTxInterrupt(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = ChConfigPtr->ChBaseAddr;
    uint8 RegionNum = (uint8)ChConfigPtr->PayloadConfigPtr->MbRegionNum;
    uint8 ChnLogicId = ChConfigPtr->CanChannelId;
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_22();
#if (0U < CAN_MAILBOX_REGION_NUM)
    if (RegionNum > 0U)
    {
        CAN32_SET_BITS(BaseAddr + CAN_IMASK1_OFFSET32, Can_ChHwObjInt[ChnLogicId][0]);
    }
#endif
#if (1U < CAN_MAILBOX_REGION_NUM)
    if (RegionNum > 1U)
    {
        CAN32_SET_BITS(BaseAddr + CAN_IMASK2_OFFSET32, Can_ChHwObjInt[ChnLogicId][1]);
    }
#endif
#if (2U < CAN_MAILBOX_REGION_NUM)
    if (RegionNum > 2U)
    {
        CAN32_SET_BITS(BaseAddr + CAN_IMASK3_OFFSET32, Can_ChHwObjInt[ChnLogicId][2]);
    }
#endif
#if (3U < CAN_MAILBOX_REGION_NUM)
    if (RegionNum > 3U)
    {
        CAN32_SET_BITS(BaseAddr + CAN_IMASK4_OFFSET32, Can_ChHwObjInt[ChnLogicId][3]);
    }
#endif
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_22();
}
#endif

#if (CAN_LEGACY_FIFO_USAGE == STD_ON)
CAN_FUNC LOCAL_INLINE void Can_Lld_InitLgcFmtA_RxFifo(const Can_ChannelConfigType *ChConfigPtr)
{
    uint16 FltIndex;
    uint32 MixedMask0;
    uint32 MaskCode;
    uint32 IdCode0;
    sint8  ShiftCode0;
    uint32 BaseAddr = ChConfigPtr->ChBaseAddr;
    uint16 IndividualFltNum = ChConfigPtr->PayloadConfigPtr->LegacyRxFifoConfigPtr->FilterNumWithIndividualMask;
    uint16 GlobalFltNum = ChConfigPtr->PayloadConfigPtr->LegacyRxFifoConfigPtr->FilterNumWithGlobalMask;
    const Can_IdvMaskFilterConfigType *IdvFltPtr = ChConfigPtr->PayloadConfigPtr->LegacyRxFifoConfigPtr->IndividualMaskFltConfigPtr;
    const Can_GlbMaskFilterConfigType *GlbFltPtr = ChConfigPtr->PayloadConfigPtr->LegacyRxFifoConfigPtr->GlobalMaskFltConfigPtr;
    for (FltIndex = 0; FltIndex < IndividualFltNum; ++FltIndex)
    {
        if (MIXED == IdvFltPtr[FltIndex].MsgIdType)
        {
            IdCode0 = CAN_ID_TYPE_FD_FRAME_MASK;
            ShiftCode0 = CAN_FORMAT_A_ID_0_EXT_SHIFT;
            MixedMask0 = CAN_ID_TYPE_EXTENDED_FRAME_MASK;
        }
        else if (STANDARD == IdvFltPtr[FltIndex].MsgIdType)
        {
            IdCode0 = 0x00000000U;
            ShiftCode0 = CAN_FORMAT_A_ID_0_STD_SHIFT;
            MixedMask0 = CAN_ID_TYPE_EXTENDED_FRAME_MASK | CAN_ID_TYPE_FD_FRAME_MASK;
        }
        else
        {
            IdCode0 = CAN_ID_TYPE_FD_FRAME_MASK;
            ShiftCode0 = CAN_FORMAT_A_ID_0_EXT_SHIFT;
            MixedMask0 = CAN_ID_TYPE_EXTENDED_FRAME_MASK | CAN_ID_TYPE_FD_FRAME_MASK;
        }
        CAN32_WRITE(BaseAddr + CAN_RXFIFOIDF_OFFSET32((uint32)FltIndex), \
                    Can_Lld_ShiftFilter((IdvFltPtr[FltIndex].FilterCode), ShiftCode0) | IdCode0);
        CAN32_WRITE(BaseAddr + CAN_RXIMR_OFFSET32((uint32)FltIndex), \
                    Can_Lld_ShiftFilter((IdvFltPtr[FltIndex].MaskCode), ShiftCode0) | MixedMask0);
    }
    if (NULL_PTR != GlbFltPtr)
    {
        if (MIXED == GlbFltPtr[0].MsgIdType)
        {
            IdCode0 = CAN_ID_TYPE_FD_FRAME_MASK;
            ShiftCode0 = CAN_FORMAT_A_ID_0_EXT_SHIFT;
            MixedMask0 = CAN_ID_TYPE_EXTENDED_FRAME_MASK;
        }
        else if (STANDARD == GlbFltPtr[0].MsgIdType)
        {
            IdCode0 = 0x00000000U;
            ShiftCode0 = CAN_FORMAT_A_ID_0_STD_SHIFT;
            MixedMask0 = CAN_ID_TYPE_EXTENDED_FRAME_MASK | CAN_ID_TYPE_FD_FRAME_MASK;
        }
        else
        {
            IdCode0 = CAN_ID_TYPE_FD_FRAME_MASK;
            ShiftCode0 = CAN_FORMAT_A_ID_0_EXT_SHIFT;
            MixedMask0 = CAN_ID_TYPE_EXTENDED_FRAME_MASK | CAN_ID_TYPE_FD_FRAME_MASK;
        }
        MaskCode = Can_Lld_ShiftFilter((GlbFltPtr[0].GlobalMaskCode), ShiftCode0) | MixedMask0;
        CAN32_WRITE(BaseAddr + CAN_RXFGMASK_OFFSET32, MaskCode);
        for (FltIndex = 0; FltIndex < GlobalFltNum; ++FltIndex)
        {
            CAN32_WRITE(BaseAddr + CAN_RXFIFOIDF_OFFSET32((uint32)FltIndex + (uint32)IndividualFltNum), \
                        Can_Lld_ShiftFilter((GlbFltPtr[0].FilterCodePtr[FltIndex]), ShiftCode0) | IdCode0);
        }
    }
}

CAN_FUNC LOCAL_INLINE void Can_Lld_InitLgcFmtB_RxFifo(const Can_ChannelConfigType *ChConfigPtr)
{
    uint16 FltIndex;
    uint32 MixedMask0;
    uint32 MixedMask1;
    uint32 FilterCode;
    uint32 MaskCode;
    uint32 IdCode0;
    uint32 IdCode1;
    sint8  ShiftCode0;
    sint8  ShiftCode1;
    uint32 BaseAddr = (uint32)ChConfigPtr->ChBaseAddr;
    uint16 IndividualFltNum = ChConfigPtr->PayloadConfigPtr->LegacyRxFifoConfigPtr->FilterNumWithIndividualMask;
    uint16 GlobalFltNum = ChConfigPtr->PayloadConfigPtr->LegacyRxFifoConfigPtr->FilterNumWithGlobalMask;
    const Can_IdvMaskFilterConfigType *IdvFltPtr = ChConfigPtr->PayloadConfigPtr->LegacyRxFifoConfigPtr->IndividualMaskFltConfigPtr;
    const Can_GlbMaskFilterConfigType *GlbFltPtr = ChConfigPtr->PayloadConfigPtr->LegacyRxFifoConfigPtr->GlobalMaskFltConfigPtr;
    for (FltIndex = 0U; FltIndex < IndividualFltNum; FltIndex = FltIndex + CAN_CONST_FORMATB_FILTER_BLOCK_NUM)
    {
        if (MIXED == IdvFltPtr[FltIndex].MsgIdType)
        {
            IdCode0 = 0x00000000U;
            ShiftCode0 = CAN_FORMAT_B_ID_0_EXT_SHIFT;
            MixedMask0 = CAN_ID_TYPE_EXTENDED_FRAME_MASK;
        }
        else if (STANDARD == IdvFltPtr[FltIndex].MsgIdType)
        {
            IdCode0 = 0x00000000U;
            ShiftCode0 = CAN_FORMAT_B_ID_0_STD_SHIFT;
            MixedMask0 = CAN_ID_TYPE_EXTENDED_FRAME_MASK | CAN_ID_TYPE_FD_FRAME_MASK;
        }
        else
        {
            IdCode0 = CAN_ID_TYPE_FD_FRAME_MASK;
            ShiftCode0 = CAN_FORMAT_B_ID_0_EXT_SHIFT;
            MixedMask0 = CAN_ID_TYPE_EXTENDED_FRAME_MASK | CAN_ID_TYPE_FD_FRAME_MASK;
        }
        if (MIXED == IdvFltPtr[FltIndex + CAN_CONST_FORMATB_FILTER_B1].MsgIdType)
        {
            IdCode1 = 0x0000U;
            ShiftCode1 = CAN_FORMAT_B_ID_1_EXT_SHIFT;
            MixedMask1 = CAN_CONST_FORMATB_ID_TYPE_EXTENDED_FRAME_MASK;
        }
        else if (STANDARD == IdvFltPtr[FltIndex + CAN_CONST_FORMATB_FILTER_B1].MsgIdType)
        {
            IdCode1 = 0x0000U;
            ShiftCode1 = CAN_FORMAT_B_ID_1_STD_SHIFT;
            MixedMask1 = CAN_CONST_FORMATB_ID_TYPE_EXTENDED_FRAME_MASK | CAN_CONST_FORMATB_ID_TYPE_FD_FRAME_MASK;
        }
        else
        {
            IdCode1 = CAN_CONST_FORMATB_ID_TYPE_FD_FRAME_MASK;
            ShiftCode1 = CAN_FORMAT_B_ID_1_EXT_SHIFT;
            MixedMask1 = CAN_CONST_FORMATB_ID_TYPE_EXTENDED_FRAME_MASK | CAN_CONST_FORMATB_ID_TYPE_FD_FRAME_MASK;
        }
        FilterCode = ((Can_Lld_ShiftFilter(IdvFltPtr[FltIndex].FilterCode, ShiftCode0) & CAN_CONST_UPPER_HALF_OF_WORD_ALL_TRUE) | IdCode0) | \
                     ((Can_Lld_ShiftFilter(IdvFltPtr[FltIndex + CAN_CONST_FORMATB_FILTER_B1].FilterCode, ShiftCode1) & \
                       CAN_CONST_LOWER_HALF_OF_WORD_ALL_TRUE) | IdCode1);
        MaskCode = ((Can_Lld_ShiftFilter(IdvFltPtr[FltIndex].MaskCode, ShiftCode0) & CAN_CONST_UPPER_HALF_OF_WORD_ALL_TRUE) | MixedMask0) | \
                   ((Can_Lld_ShiftFilter(IdvFltPtr[FltIndex + CAN_CONST_FORMATB_FILTER_B1].MaskCode, ShiftCode1) & \
                     CAN_CONST_LOWER_HALF_OF_WORD_ALL_TRUE) | MixedMask1);
        CAN32_WRITE(BaseAddr + CAN_RXFIFOIDF_OFFSET32((uint32)FltIndex / (uint32)CAN_CONST_FORMATB_FILTER_BLOCK_NUM), (uint32)FilterCode);
        CAN32_WRITE(BaseAddr + CAN_RXIMR_OFFSET32((uint32)FltIndex / (uint32)CAN_CONST_FORMATB_FILTER_BLOCK_NUM), (uint32)MaskCode);
    }
    if (NULL_PTR != GlbFltPtr)
    {
        if (MIXED == GlbFltPtr[CAN_CONST_FORMATB_FILTER_B0].MsgIdType)
        {
            IdCode0 = 0x00000000U;
            ShiftCode0 = CAN_FORMAT_B_ID_0_EXT_SHIFT;
            MixedMask0 = CAN_ID_TYPE_EXTENDED_FRAME_MASK;
        }
        else if (STANDARD == GlbFltPtr[CAN_CONST_FORMATB_FILTER_B0].MsgIdType)
        {
            IdCode0 = 0x00000000U;
            ShiftCode0 = CAN_FORMAT_B_ID_0_STD_SHIFT;
            MixedMask0 = CAN_ID_TYPE_EXTENDED_FRAME_MASK | CAN_ID_TYPE_FD_FRAME_MASK;
        }
        else
        {
            IdCode0 = CAN_ID_TYPE_FD_FRAME_MASK;
            ShiftCode0 = CAN_FORMAT_B_ID_0_EXT_SHIFT;
            MixedMask0 = CAN_ID_TYPE_EXTENDED_FRAME_MASK | CAN_ID_TYPE_FD_FRAME_MASK;
        }
        if (MIXED == GlbFltPtr[CAN_CONST_FORMATB_FILTER_B1].MsgIdType)
        {
            IdCode1 = 0x0000U;
            ShiftCode1 = CAN_FORMAT_B_ID_1_EXT_SHIFT;
            MixedMask1 = CAN_CONST_FORMATB_ID_TYPE_EXTENDED_FRAME_MASK;
        }
        else if (STANDARD == GlbFltPtr[CAN_CONST_FORMATB_FILTER_B1].MsgIdType)
        {
            IdCode1 = 0x0000U;
            ShiftCode1 = CAN_FORMAT_B_ID_1_STD_SHIFT;
            MixedMask1 = CAN_CONST_FORMATB_ID_TYPE_EXTENDED_FRAME_MASK | CAN_CONST_FORMATB_ID_TYPE_FD_FRAME_MASK;
        }
        else
        {
            IdCode1 = CAN_CONST_FORMATB_ID_TYPE_FD_FRAME_MASK;
            ShiftCode1 = CAN_FORMAT_B_ID_1_EXT_SHIFT;
            MixedMask1 = CAN_CONST_FORMATB_ID_TYPE_EXTENDED_FRAME_MASK | CAN_CONST_FORMATB_ID_TYPE_FD_FRAME_MASK;
        }
        MaskCode = (Can_Lld_ShiftFilter((GlbFltPtr[0].GlobalMaskCode), ShiftCode0) | MixedMask0) | \
                   (Can_Lld_ShiftFilter((GlbFltPtr[1].GlobalMaskCode), ShiftCode1) | MixedMask1);
        CAN32_WRITE(BaseAddr + CAN_RXFGMASK_OFFSET32, MaskCode);
        for (FltIndex = 0U; FltIndex < (GlobalFltNum / CAN_CONST_FORMATB_FILTER_BLOCK_NUM); ++FltIndex)
        {
            FilterCode = ((Can_Lld_ShiftFilter((GlbFltPtr[0].FilterCodePtr[FltIndex]), \
                                               ShiftCode0) | IdCode0) & CAN_CONST_UPPER_HALF_OF_WORD_ALL_TRUE) | \
                         ((Can_Lld_ShiftFilter((GlbFltPtr[1].FilterCodePtr[FltIndex]), \
                                               ShiftCode1) | IdCode1) & CAN_CONST_LOWER_HALF_OF_WORD_ALL_TRUE);
            CAN32_WRITE(BaseAddr + CAN_RXFIFOIDF_OFFSET32(((uint32)IndividualFltNum / (uint32)2U) + (uint32)FltIndex), \
                        (uint32)FilterCode);
        }
    }
}

CAN_FUNC LOCAL_INLINE void Can_Lld_InitLgcFmtC_RxFifo(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = (uint32)ChConfigPtr->ChBaseAddr;
    uint16 FltIndex;
    uint32 FilterCode;
    uint32 MaskCode;
    sint8  ShiftCode0;
    sint8 ShiftCode1;
    sint8 ShiftCode2;
    sint8 ShiftCode3;
    uint16 IndividualFltNum = ChConfigPtr->PayloadConfigPtr->LegacyRxFifoConfigPtr->FilterNumWithIndividualMask;
    uint16 GlobalFltNum = ChConfigPtr->PayloadConfigPtr->LegacyRxFifoConfigPtr->FilterNumWithGlobalMask;
    const Can_IdvMaskFilterConfigType *IdvFltPtr = ChConfigPtr->PayloadConfigPtr->LegacyRxFifoConfigPtr->IndividualMaskFltConfigPtr;
    const Can_GlbMaskFilterConfigType *GlbFltPtr = ChConfigPtr->PayloadConfigPtr->LegacyRxFifoConfigPtr->GlobalMaskFltConfigPtr;
    ShiftCode0 = CAN_FORMAT_C_ID_0_EXT_SHIFT;
    ShiftCode1 = CAN_FORMAT_C_ID_1_EXT_SHIFT;
    ShiftCode2 = CAN_FORMAT_C_ID_2_EXT_SHIFT;
    ShiftCode3 = CAN_FORMAT_C_ID_3_EXT_SHIFT;
    for (FltIndex = 0; FltIndex < IndividualFltNum; FltIndex = FltIndex + CAN_CONST_BYTENUM_PER_WORD)
    {
        FilterCode = \
                     (Can_Lld_ShiftFilter((IdvFltPtr[FltIndex].FilterCode), ShiftCode0) & CAN_CONST_BYTE3_OF_WORD_ALL_TRUE) | \
                     (Can_Lld_ShiftFilter((IdvFltPtr[FltIndex + CAN_CONST_FORMATC_FILTER_B1].FilterCode), ShiftCode1) & CAN_CONST_BYTE2_OF_WORD_ALL_TRUE) | \
                     (Can_Lld_ShiftFilter((IdvFltPtr[FltIndex + CAN_CONST_FORMATC_FILTER_B2].FilterCode), ShiftCode2) & CAN_CONST_BYTE1_OF_WORD_ALL_TRUE) | \
                     (Can_Lld_ShiftFilter((IdvFltPtr[FltIndex + CAN_CONST_FORMATC_FILTER_B3].FilterCode), ShiftCode3) & CAN_CONST_BYTE0_OF_WORD_ALL_TRUE);
        MaskCode = \
                   (Can_Lld_ShiftFilter((IdvFltPtr[FltIndex].MaskCode), ShiftCode0) & CAN_CONST_BYTE3_OF_WORD_ALL_TRUE) | \
                   (Can_Lld_ShiftFilter((IdvFltPtr[FltIndex + CAN_CONST_FORMATC_FILTER_B1].MaskCode), ShiftCode1) & CAN_CONST_BYTE2_OF_WORD_ALL_TRUE) | \
                   (Can_Lld_ShiftFilter((IdvFltPtr[FltIndex + CAN_CONST_FORMATC_FILTER_B2].MaskCode), ShiftCode2) & CAN_CONST_BYTE1_OF_WORD_ALL_TRUE) | \
                   (Can_Lld_ShiftFilter((IdvFltPtr[FltIndex + CAN_CONST_FORMATC_FILTER_B3].MaskCode), ShiftCode3) & CAN_CONST_BYTE0_OF_WORD_ALL_TRUE);
        CAN32_WRITE(BaseAddr + CAN_RXFIFOIDF_OFFSET32((uint32)FltIndex / (uint32)CAN_CONST_BYTENUM_PER_WORD), (uint32)FilterCode);
        CAN32_WRITE(BaseAddr + CAN_RXIMR_OFFSET32((uint32)FltIndex / (uint32)CAN_CONST_BYTENUM_PER_WORD), (uint32)MaskCode);
    }
    if (NULL_PTR != GlbFltPtr)
    {
        MaskCode = \
                   (Can_Lld_ShiftFilter((GlbFltPtr[CAN_CONST_FORMATC_FILTER_B0].GlobalMaskCode), ShiftCode0) & CAN_CONST_BYTE3_OF_WORD_ALL_TRUE) | \
                   (Can_Lld_ShiftFilter((GlbFltPtr[CAN_CONST_FORMATC_FILTER_B1].GlobalMaskCode), ShiftCode1) & CAN_CONST_BYTE2_OF_WORD_ALL_TRUE) | \
                   (Can_Lld_ShiftFilter((GlbFltPtr[CAN_CONST_FORMATC_FILTER_B2].GlobalMaskCode), ShiftCode2) & CAN_CONST_BYTE1_OF_WORD_ALL_TRUE) | \
                   (Can_Lld_ShiftFilter((GlbFltPtr[CAN_CONST_FORMATC_FILTER_B3].GlobalMaskCode), ShiftCode3) & CAN_CONST_BYTE0_OF_WORD_ALL_TRUE);
        CAN32_WRITE(BaseAddr + CAN_RXFGMASK_OFFSET32, MaskCode);
        for (FltIndex = 0U; FltIndex < (GlobalFltNum / CAN_CONST_BYTENUM_PER_WORD); ++FltIndex)
        {
            FilterCode = (Can_Lld_ShiftFilter((GlbFltPtr[CAN_CONST_FORMATC_FILTER_B0].FilterCodePtr[FltIndex]), \
                                              ShiftCode0) & CAN_CONST_BYTE3_OF_WORD_ALL_TRUE) | \
                         (Can_Lld_ShiftFilter((GlbFltPtr[CAN_CONST_FORMATC_FILTER_B1].FilterCodePtr[FltIndex]), \
                                              ShiftCode1) & CAN_CONST_BYTE2_OF_WORD_ALL_TRUE) | \
                         (Can_Lld_ShiftFilter((GlbFltPtr[CAN_CONST_FORMATC_FILTER_B2].FilterCodePtr[FltIndex]), \
                                              ShiftCode2) & CAN_CONST_BYTE1_OF_WORD_ALL_TRUE) | \
                         (Can_Lld_ShiftFilter((GlbFltPtr[CAN_CONST_FORMATC_FILTER_B3].FilterCodePtr[FltIndex]), \
                                              ShiftCode3) & CAN_CONST_BYTE0_OF_WORD_ALL_TRUE);
            CAN32_WRITE(BaseAddr + \
                        CAN_RXFIFOIDF_OFFSET32(((uint32)IndividualFltNum / (uint32)CAN_CONST_BYTENUM_PER_WORD) + (uint32)FltIndex), (uint32)FilterCode);
        }
    }
}

CAN_FUNC LOCAL_INLINE void Can_Lld_InitLegacyRxFifo(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = (uint32)ChConfigPtr->ChBaseAddr;
    Can_LegacyRxFifoIdmFltType Format = ChConfigPtr->PayloadConfigPtr->LegacyRxFifoConfigPtr->LegacyRxFifoFilterFormat;
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_20();
    CAN32_SET_BITS(BaseAddr, CAN_MCR_RFEN_MASK); /* Enable Rx fifo */
    CAN32_AEARWRITE(BaseAddr, CAN_MCR_IDAM_MASK, (uint32)(Format) << CAN_MCR_IDAM_SHIFT);
    /* Set ID acceptance filter number */
    CAN32_AEARWRITE(BaseAddr + CAN_CTRL2_OFFSET32, CAN_CTRL2_RFFN_MASK, \
                    (((uint32)(ChConfigPtr->PayloadConfigPtr->LegacyRxFifoConfigPtr->LegacyRxFifoOccupyMailboxNum) - \
                      (uint32)8U) / (uint32)2U) << CAN_CTRL2_RFFN_SHIFT);
#if (CAN_DMA_USAGE == STD_ON)
    if (TRUE == ChConfigPtr->CanDmaUsage)
    {
        /* Enable DMA in FLEX_CAN module */
        CAN32_SET_BITS(BaseAddr, CAN_MCR_DMA_MASK);
    }
#endif
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_20();
#if (CAN_DMA_USAGE == STD_ON)
    if ((TRUE == ChConfigPtr->CanDmaUsage))
    {
        /* Config Dma relative setting */
        (void)Can_Lld_DmaConfig(ChConfigPtr, CAN_RX_FIFO_LEGACY);
    }
#endif
    if (CAN_LEGACY_RX_FIFO_FILTER_FORMAT_A == Format)
    {
        Can_Lld_InitLgcFmtA_RxFifo(ChConfigPtr);
    }
    else if (CAN_LEGACY_RX_FIFO_FILTER_FORMAT_B == Format)
    {
        Can_Lld_InitLgcFmtB_RxFifo(ChConfigPtr);
    }
    else
    {
        Can_Lld_InitLgcFmtC_RxFifo(ChConfigPtr);
    }
}

CAN_FUNC LOCAL_INLINE boolean Can_Lld_CheckLgcRxFifoFlag(uint32 BaseAddr)
{
    boolean RetVal = FALSE;
    if (0U != CAN32_GET_BITS(BaseAddr + CAN_IFLAG1_OFFSET32, CAN_IFLAG1_BUF5I_MASK))
    {
        RetVal = TRUE;
    }
    return RetVal;
}

#if (CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON)
CAN_FUNC LOCAL_INLINE void Can_Lld_PrcsLgcRxFifo(const Can_ChannelConfigType *ChConfigPtr)
{
    Can_Lld_CheckLgcRxFifoOvf(ChConfigPtr);
    Can_Lld_CheckLgcRxFifoFull(ChConfigPtr);
    Can_Lld_CheckLgcRxFifoRx(ChConfigPtr);
}
#endif

#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
CAN_FUNC LOCAL_INLINE void Can_Lld_PollingLgcFifoHrh(const Can_ChannelConfigType *ChConfigPtr)
{
#if (CAN_DMA_USAGE == STD_ON)
    Can_HwHandleType Hrh = ChConfigPtr->CanFifoHrhId;
    CddDma_ChannelStatusReturnType Can_DmaChnStatus;
    Can_CallbackPtrOfErrType ErrorCallback = ChConfigPtr->CanCallbackPtr->ErrorCallback;
    boolean Can_FlagDmaStart = FALSE;
#endif
    Can_Lld_CheckLgcRxFifoOvf(ChConfigPtr);
    Can_Lld_CheckLgcRxFifoFull(ChConfigPtr);
#if (CAN_DMA_USAGE == STD_ON)
    if (TRUE == ChConfigPtr->CanDmaUsage)
    {
        CddDma_GetChannelStatus(ChConfigPtr->CanDmaChannel, &Can_DmaChnStatus);
        if (TRUE == Can_DmaChnStatus.Done)
        {
            CddDma_StopChannel(ChConfigPtr->CanDmaChannel);
            CddDma_ClearChannelDoneStatus(ChConfigPtr->CanDmaChannel);
            Can_Lld_HandleMsg(&Can_DmaBuffer[ChConfigPtr->CanChannelId][0], Hrh, ChConfigPtr);
            Can_FlagDmaStart = TRUE;
        }
        if (0U != Can_DmaChnStatus.Errors)
        {
            CddDma_StopChannel(ChConfigPtr->CanDmaChannel);
            if (NULL_PTR != ErrorCallback)
            {
                ErrorCallback(CAN_ERROR_DMA_RECEIVE);
            }
            Can_FlagDmaStart = TRUE;
        }
        if (TRUE == Can_FlagDmaStart)
        {
            CddDma_StartChannel(ChConfigPtr->CanDmaChannel);
        }
    }
    else
#endif
    {
        Can_Lld_CheckLgcRxFifoRx(ChConfigPtr);
    }
}
#endif /* (CAN_RX_PROCESS_HAS_POLLING == STD_ON) */
#endif /* (CAN_LEGACY_FIFO_USAGE == STD_ON) */

#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)
CAN_FUNC LOCAL_INLINE boolean Can_Lld_CheckFlagEnhFifo(const uint32 BaseAddr)
{
    boolean RetVal = FALSE;
    if (0U == CAN32_GET_BITS(BaseAddr + CAN_ERFSR_OFFSET32, CAN_ERFSR_ERFE_MASK))
    {
        RetVal = TRUE;
    }
    return RetVal;
}

CAN_FUNC LOCAL_INLINE void Can_Lld_InitEnhRxFifo(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = (uint32)ChConfigPtr->ChBaseAddr;
    const Can_EnhanceRxFifoConfigType *FifoCfgPtr;
    FifoCfgPtr = ChConfigPtr->PayloadConfigPtr->EnhanceRxFifoConfigPtr;
    uint32 FilterAddr = BaseAddr + CAN_ERFFELn_OFFSET32(0U);
    uint32 IdFilterNumCode;
    uint32 ExtIdFilterNum;
    uint32 StdIdFilterNum;
    uint32 StdIdFilterElementNum;
    uint32 DmaLw;
    uint32 Tmp32;
    uint32 WatermarkCode = FifoCfgPtr->EnhanceRxFifoWatermarkNum - (uint32)1U;
    uint8 FltIndex = 0U;
    Can_EnhanceRxFifoFltType FormatType;
#if (CAN_DMA_USAGE == STD_ON)
    /* Set DMA last word */
    if (TRUE == ChConfigPtr->CanDmaUsage)
    {
        DmaLw = CAN_ERFCR_DMALW_MASK & ((uint32)0x13U << CAN_ERFCR_DMALW_SHIFT);
    }
    else
#endif
    {
        DmaLw = 0U;
    }
    /* Get extended id filter number and standard id id filter number from config */
    ExtIdFilterNum = FifoCfgPtr->ExtRxFifoFilterNum;
    StdIdFilterNum = FifoCfgPtr->StdRxFifoFilterNum;
    /* Caculate standard id filter element number */
    StdIdFilterElementNum = (StdIdFilterNum + CAN_CONST_ENH_FILTER_NUMCODE_ADAPTER) / CAN_CONST_ENH_FILTER_STDFLTNUM_PER_ELEMENT;
    /* Caculate total id filter number code */
    IdFilterNumCode = (StdIdFilterElementNum + ExtIdFilterNum) - CAN_CONST_ENH_FILTER_NUMCODE_ADAPTER;
    Tmp32 = CAN_ERFCR_ERFEN_MASK | DmaLw | CAN_ERFCR_NFE(IdFilterNumCode) | CAN_ERFCR_NEXIF(ExtIdFilterNum) | WatermarkCode;
    /* Reset Rx FIFO engine, clear enhanced Rx FIFO content */
    CAN32_WRITE(BaseAddr + CAN_ERFSR_OFFSET32, CAN_ENHANCE_FIFO_FLAGS_MASK + CAN_ERFSR_ERFCLR_MASK);
    /* Set filter counter and watermark */
    CAN32_WRITE(BaseAddr + CAN_ERFCR_OFFSET32, Tmp32);
#if (CAN_DMA_USAGE == STD_ON)
    if (TRUE == ChConfigPtr->CanDmaUsage)
    {
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_04();
        CAN32_SET_BITS(BaseAddr, CAN_MCR_DMA_MASK); /* Enable DMA */
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_04();
    }
// TODO Check here
    /** if ((TRUE == ChConfigPtr->CanDmaUsage) && (CAN_INITINST != InitType)) */
    if ((TRUE == ChConfigPtr->CanDmaUsage))
    {
        (void)Can_Lld_DmaConfig(ChConfigPtr, CAN_RX_FIFO_ENHANCE);
    }
#endif
    /* Set extended ID filter */
    for (FltIndex = 0; FltIndex < ExtIdFilterNum; ++FltIndex)
    {
        FormatType = FifoCfgPtr->ExtRxFifoFltConfigPtr[FltIndex].EnhanceRxFifoFilterFormat;
        Tmp32 = FifoCfgPtr->ExtRxFifoFltConfigPtr[FltIndex].FilterCodeExt1;
        /* PRQA S 2985 ++
         * The variable FormatType is not always zero, so the fellowing code maybe redundant.
         */
        /* write FSCH flag in first filter */
        Tmp32 |= CAN_ERFFELN_FSCH(FormatType);
        /* PRQA S 2985 -- */
        CAN32_WRITE(FilterAddr, Tmp32);
        FilterAddr += CAN_CONST_BYTENUM_PER_WORD;
        /* write second filter directly */
        Tmp32 = FifoCfgPtr->ExtRxFifoFltConfigPtr[FltIndex].FilterCodeExt2;
        if (FormatType == CAN_FILTER_FORMAT_ACC_MASK_MODE)
        {
            Tmp32 |= CAN_ERFFELN_EXDID_RTR_FILTER_MASK;
        }
        CAN32_WRITE(FilterAddr, Tmp32);
        FilterAddr += CAN_CONST_BYTENUM_PER_WORD;
    }
    /* Set standard ID filter */
    for (FltIndex = 0; FltIndex < StdIdFilterNum; ++FltIndex)
    {
        FormatType = FifoCfgPtr->StdRxFifoFltConfigPtr[FltIndex].EnhanceRxFifoFilterFormat;
        Tmp32 = FifoCfgPtr->StdRxFifoFltConfigPtr[FltIndex].FilterCodeStd1 | \
                CAN_ERFFELN_STDID_ID_FILTER(FifoCfgPtr->StdRxFifoFltConfigPtr[FltIndex].FilterCodeStd2);
        if (CAN_FILTER_FORMAT_ACC_ACC_MODE == FormatType)
        {
            Tmp32 |= CAN_ERFFELN_FSCH(2);
        }
        else if (CAN_FILTER_FORMAT_ACC_RANG_MODE == FormatType)
        {
            Tmp32 |= (CAN_ERFFELN_FSCH(1) | CAN_ERFFELN_STDID_RTR_MASK_MASK);
        }
        else
        {
            Tmp32 |= CAN_ERFFELN_STDID_RTR_MASK_MASK;
        }
        CAN32_WRITE(FilterAddr, Tmp32);
        FilterAddr += CAN_CONST_BYTENUM_PER_WORD;
    }
}

#if (CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON)
CAN_FUNC LOCAL_INLINE void Can_Lld_PrcsEnhRxFifo(const Can_ChannelConfigType *ChConfigPtr)
{
    Can_Lld_CheckEnhRxFifoUdf(ChConfigPtr);
    Can_Lld_CheckEnhRxFifoOvf(ChConfigPtr);
    Can_Lld_CheckEnhRxFifoFull(ChConfigPtr);
    Can_Lld_CheckEnhRxFifoRx(ChConfigPtr);
}
#endif

#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
CAN_FUNC LOCAL_INLINE void Can_Lld_PollingEnhFifoHrh(const Can_ChannelConfigType *ChConfigPtr)
{
#if (CAN_DMA_USAGE == STD_ON)
    CddDma_ChannelStatusReturnType Can_DmaChnStatus;
    Can_CallbackPtrOfErrType ErrorCallback = ChConfigPtr->CanCallbackPtr->ErrorCallback;
    boolean Can_FlagDmaStart = FALSE;
    Can_HwHandleType Hrh = ChConfigPtr->CanFifoHrhId;
#endif
    Can_Lld_CheckEnhRxFifoUdf(ChConfigPtr);
    Can_Lld_CheckEnhRxFifoOvf(ChConfigPtr);
#if (CAN_DMA_USAGE == STD_ON)
    if (TRUE == ChConfigPtr->CanDmaUsage)
    {
        CddDma_GetChannelStatus(ChConfigPtr->CanDmaChannel, &Can_DmaChnStatus);
        if (TRUE == Can_DmaChnStatus.Done)
        {
            CddDma_StopChannel(ChConfigPtr->CanDmaChannel);
            CddDma_ClearChannelDoneStatus(ChConfigPtr->CanDmaChannel);
            Can_Lld_HandleMsg(&Can_DmaBuffer[ChConfigPtr->CanChannelId][0], Hrh, ChConfigPtr);
            Can_FlagDmaStart = TRUE;
        }
        if (0U != Can_DmaChnStatus.Errors)
        {
            CddDma_StopChannel(ChConfigPtr->CanDmaChannel);
            if (NULL_PTR != ErrorCallback)
            {
                ErrorCallback(CAN_ERROR_DMA_RECEIVE);
            }
            Can_FlagDmaStart = TRUE;
        }
        if (TRUE == Can_FlagDmaStart)
        {
            CddDma_StartChannel(ChConfigPtr->CanDmaChannel);
        }
    }
    else
#endif
    {
        Can_Lld_CheckEnhRxFifoFull(ChConfigPtr);
        Can_Lld_CheckEnhRxFifoRx(ChConfigPtr);
    }
}
#endif/*#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)*/
#endif

#if (CAN_MEMECC_FEATURE == STD_ON)
CAN_FUNC LOCAL_INLINE void Can_Lld_ProcessEcc(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = (uint32)ChConfigPtr->ChBaseAddr;
    /* Host Access With Non-Correctable Errors Interrupt */
    if (0U != CAN32_GET_BITS(BaseAddr + CAN_MECR_OFFSET32, CAN_MECR_HANCEI_MSK_MASK))
    {
        /*No interrupt is associated with this flag, this IF may implement by mainfunction check*/
        if (0U != CAN32_GET_BITS(BaseAddr + CAN_ERRSR_OFFSET32, CAN_ERRSR_HANCEIOF_MASK))
        {
            if (NULL_PTR != ChConfigPtr->CanCallbackPtr->ErrNceCallback)
            {
                ChConfigPtr->CanCallbackPtr->ErrNceCallback(CAN_ERROR_NCE_HOST_OVF);
            }
            CAN32_WRITE(BaseAddr + CAN_ERRSR_OFFSET32, CAN_ERRSR_HANCEIOF_MASK);
        }
        if (0U != CAN32_GET_BITS(BaseAddr + CAN_ERRSR_OFFSET32, CAN_ERRSR_HANCEIF_MASK))
        {
            Can_Lld_AbortPendingMsg(ChConfigPtr);
            (void)Can_Lld_SetChnToFreezeMode(ChConfigPtr->ChBaseAddr);
            /* check, corrupted frames aborted aotu or by CPU(software)*/
            (void)Can_Lld_SetChnToNormalMode(ChConfigPtr->ChBaseAddr);
            if (NULL_PTR != ChConfigPtr->CanCallbackPtr->ErrNceCallback)
            {
                ChConfigPtr->CanCallbackPtr->ErrNceCallback(CAN_ERROR_NCE_HOST);
            }
            CAN32_WRITE(BaseAddr + CAN_ERRSR_OFFSET32, CAN_ERRSR_HANCEIF_MASK);
        }
    }
    /* FlexCAN Access With Non-Correctable Errors Interrupt Mask */
    if (0U != CAN32_GET_BITS(BaseAddr + CAN_MECR_OFFSET32, CAN_MECR_FANCEI_MSK_MASK))
    {
        /*No interrupt is associated with this flag, this IF may implement by mainfunction check*/
        if (0U != CAN32_GET_BITS(BaseAddr + CAN_ERRSR_OFFSET32, CAN_ERRSR_FANCEIOF_MASK))
        {
            if (NULL_PTR != ChConfigPtr->CanCallbackPtr->ErrNceCallback)
            {
                ChConfigPtr->CanCallbackPtr->ErrNceCallback(CAN_ERROR_NCE_FLEXCAN_OVF);
            }
            CAN32_WRITE(BaseAddr + CAN_ERRSR_OFFSET32, CAN_ERRSR_FANCEIOF_MASK);
        }
        if (0U != CAN32_GET_BITS(BaseAddr + CAN_ERRSR_OFFSET32, CAN_ERRSR_FANCEIF_MASK))
        {
            Can_Lld_AbortPendingMsg(ChConfigPtr);
            (void)Can_Lld_SetChnToFreezeMode(ChConfigPtr->ChBaseAddr);
            /* check, corrupted frames aborted aotu or by CPU(software)*/
            (void)Can_Lld_SetChnToNormalMode(ChConfigPtr->ChBaseAddr);
            if (NULL_PTR != ChConfigPtr->CanCallbackPtr->ErrNceCallback)
            {
                ChConfigPtr->CanCallbackPtr->ErrNceCallback(CAN_ERROR_NCE_FLEXCAN);
            }
            CAN32_WRITE(BaseAddr + CAN_ERRSR_OFFSET32, CAN_ERRSR_FANCEIF_MASK);
        }
    }
    /* FlexCAN Access With Correctable Errors Interrupt Mask */
    if (0U != CAN32_GET_BITS(BaseAddr + CAN_MECR_OFFSET32, CAN_MECR_CEI_MSK_MASK))
    {
        /*No interrupt is associated with this flag, this IF may implement by mainfunction check*/
        if (0U != CAN32_GET_BITS(BaseAddr + CAN_ERRSR_OFFSET32, CAN_ERRSR_CEIOF_MASK))
        {
            if (NULL_PTR != ChConfigPtr->CanCallbackPtr->ErrCeCallback)
            {
                ChConfigPtr->CanCallbackPtr->ErrCeCallback(CAN_ERROR_CE_OVF);
            }
            CAN32_WRITE(BaseAddr + CAN_ERRSR_OFFSET32, CAN_ERRSR_CEIOF_MASK);
        }
        if (0U != CAN32_GET_BITS(BaseAddr + CAN_ERRSR_OFFSET32, CAN_ERRSR_CEIF_MASK))
        {
            if (NULL_PTR != ChConfigPtr->CanCallbackPtr->ErrCeCallback)
            {
                ChConfigPtr->CanCallbackPtr->ErrCeCallback(CAN_ERROR_CE);
            }
            CAN32_WRITE(BaseAddr + CAN_ERRSR_OFFSET32, CAN_ERRSR_CEIF_MASK);
        }
    }
#if 0
    if (0U != CAN32_GET_BITS(BaseAddr + CAN_MECR_OFFSET32, CAN_MECR_HAERRIE_MASK))
    {
    }
    if (0U != CAN32_GET_BITS(BaseAddr + CAN_MECR_OFFSET32, CAN_MECR_FAERRIE_MASK))
    {
    }
#endif
}
#endif

#if (CAN_FD_USAGE == STD_ON)
CAN_FUNC LOCAL_INLINE void Can_Lld_ProcessErrorFast(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = (uint32)ChConfigPtr->ChBaseAddr;
    if ((0U != CAN32_GET_BITS(BaseAddr + CAN_CTRL2_OFFSET32, CAN_CTRL2_ERRMSK_FAST_MASK)) && \
            (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_ERRINT_FAST_MASK)) && \
            (NULL_PTR != ChConfigPtr->CanCallbackPtr->ErrFastCallback))
    {
        /* GCOVR_EXCL_START: The fellowing error could not be coverd by integration test */
        if (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_BIT1ERR_FAST_MASK))
        {
            ChConfigPtr->CanCallbackPtr->ErrFastCallback(CAN_ERROR_BIT1ERR_FAST);
        }
        if (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_BIT0ERR_FAST_MASK))
        {
            ChConfigPtr->CanCallbackPtr->ErrFastCallback(CAN_ERROR_BIT0ERR_FAST);
        }
        if (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_CRCERR_FAST_MASK))
        {
            ChConfigPtr->CanCallbackPtr->ErrFastCallback(CAN_ERROR_CRCERR_FAST);
        }
        if (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_FRMERR_FAST_MASK))
        {
            ChConfigPtr->CanCallbackPtr->ErrFastCallback(CAN_ERROR_FRMERR_FAST);
        }
        if (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_STFERR_FAST_MASK))
        {
            ChConfigPtr->CanCallbackPtr->ErrFastCallback(CAN_ERROR_STFERR_FAST);
        }
        /* GCOVR_EXCL_STOP */
    }
    if ((0U != CAN32_GET_BITS(BaseAddr + CAN_CTRL2_OFFSET32, CAN_CTRL2_ERRMSK_FAST_MASK)) && \
            (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_ERRINT_FAST_MASK)))
    {
        CAN32_WRITE(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_ERRINT_FAST_MASK);
    }
}
#endif

#if (CAN_MEMECC_FEATURE == STD_ON)
CAN_FUNC static void Can_Lld_DisableMemEcc(uint32 BaseAddr)
{
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_26();
    CAN32_SET_BITS(BaseAddr + CAN_CTRL2_OFFSET32, CAN_CTRL2_ECRWRE_MASK);
    CAN32_CLEAR_BITS(BaseAddr + CAN_MECR_OFFSET32, CAN_MECR_ECRWRDIS_MASK);
    CAN32_CLEAR_BITS(BaseAddr + CAN_MECR_OFFSET32, CAN_MECR_HANCEI_MSK_MASK);
    CAN32_CLEAR_BITS(BaseAddr + CAN_MECR_OFFSET32, CAN_MECR_FANCEI_MSK_MASK);
    CAN32_CLEAR_BITS(BaseAddr + CAN_MECR_OFFSET32, CAN_MECR_NCEFAFRZ_MASK);
    CAN32_SET_BITS(BaseAddr + CAN_MECR_OFFSET32, CAN_MECR_ECRWRDIS_MASK);
    CAN32_CLEAR_BITS(BaseAddr + CAN_CTRL2_OFFSET32, CAN_CTRL2_ECRWRE_MASK);
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_26();
}

CAN_FUNC static void Can_Lld_EnableMemEcc(uint32 BaseAddr)
{
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_26(); /* update AREA26 redefine */
    CAN32_SET_BITS(BaseAddr + CAN_CTRL2_OFFSET32, CAN_CTRL2_ECRWRE_MASK);
    CAN32_CLEAR_BITS(BaseAddr + CAN_MECR_OFFSET32, CAN_MECR_ECRWRDIS_MASK);
    CAN32_WRITE(BaseAddr + CAN_MECR_OFFSET32, 0x000DE080U);
    CAN32_SET_BITS(BaseAddr + CAN_MECR_OFFSET32, CAN_MECR_ECRWRDIS_MASK);
    CAN32_CLEAR_BITS(BaseAddr + CAN_CTRL2_OFFSET32, CAN_CTRL2_ECRWRE_MASK);
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_26();
}
#endif

#if (CAN_DMA_USAGE == STD_ON)
CAN_FUNC LOCAL_INLINE void Can_Lld_DmaReceiveData(uint32 ChannelId)
{
    const Can_ConfigType *CanCfgPtr = Can_Bak_GetCfgPtr();
    uint8 ChnId = (uint8)(ChannelId & CAN_CONST_BYTE0_OF_WORD_ALL_TRUE);
    CddDma_ChannelType dmaChannel = CanCfgPtr->CanChCfgPtr[ChnId].CanDmaChannel;
    Can_HwHandleType Hrh;
    CddDma_StopChannel(dmaChannel);
    Hrh = CanCfgPtr->CanChCfgPtr[ChnId].CanFifoHrhId;
    Can_Lld_HandleMsg(&Can_DmaBuffer[ChnId][0], Hrh, &CanCfgPtr->CanChCfgPtr[ChnId]);
    CddDma_StartChannel(dmaChannel);
}

CAN_FUNC LOCAL_INLINE void Can_Lld_DmaReceiveError(uint32 ChannelId)
{
    const Can_ConfigType *CanCfgPtr = Can_Bak_GetCfgPtr();
    uint8 ChnId = (uint8)(ChannelId & CAN_CONST_BYTE0_OF_WORD_ALL_TRUE);
    Can_CallbackPtrOfErrType Callback = CanCfgPtr->CanChCfgPtr[ChnId].CanCallbackPtr->ErrorCallback;
    if (NULL_PTR != Callback)
    {
        Callback(CAN_ERROR_DMA_RECEIVE);
    }
}
#endif
#endif /* #if (CAN_CONDITIONALCOMPILATION_CODE == STD_ON) */

/*==================================================================================================
 *                                        LOCAL FUNCTION
==================================================================================================*/
#define CAN_NECESSARY_CODE (STD_ON)
#if (CAN_NECESSARY_CODE == STD_ON)
CAN_FUNC static void Can_Lld_EmptyMailbox(uint32 *Addr, Can_ObjectType RxTxType)
{
    uint32 Tmp32;
    uint32 TmpReg;
    if (CAN_RECEIVE == RxTxType)
    {
        Tmp32 = CAN_MB_HERADER_0_CODE(CAN_CSCODE_RX_EMPTY);
    }
    else
    {
        Tmp32 = CAN_MB_HERADER_0_CODE(CAN_CSCODE_TX_INACTIVE);
    }
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_19();
    TmpReg = *Addr;
    TmpReg &= (~CAN_MB_HERADER_0_CODE_MASK);
    *Addr = TmpReg | Tmp32;
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_19();
}

CAN_FUNC static Std_ReturnType Can_Lld_SetChnToFreezeMode(uint32 BaseAddr)
{
    uint32 TimeOutCntTemp = 0;
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_15();
    /* Set to freeze mode */
    CAN32_SET_BITS(BaseAddr, CAN_MCR_FRZ_MASK);
    CAN32_SET_BITS(BaseAddr, CAN_MCR_HALT_MASK);
    /* Enable can module */
    if ((uint32)CAN_MCR_MDIS_MASK == CAN32_GET_BITS(BaseAddr, CAN_MCR_MDIS_MASK))
    {
        CAN32_CLEAR_BITS(BaseAddr, CAN_MCR_MDIS_MASK);
    }
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_15();
    /* Wait for freeze mode acknowledge is set(FRZACK == 1) or timeout */
    while (((uint32)CAN_MCR_FRZACK_MASK != CAN32_GET_BITS(BaseAddr + \
            CAN_MCR_OFFSET32, CAN_MCR_FRZACK_MASK)) && (TimeOutCntTemp < CAN_TIMEOUT_COUNT))
    {
        ++TimeOutCntTemp;
    }
    /* GCOVR_EXCL_START: Timeout check, if timeout, use soft reset */
    if (TimeOutCntTemp >= CAN_TIMEOUT_COUNT)
    {
        TimeOutCntTemp = 0;
        SchM_Enter_Can_CAN_EXCLUSIVE_AREA_11();
        /* Reset the FlexCan by software reset */
        CAN32_SET_BITS(BaseAddr, CAN_MCR_SOFTRST_MASK);
        SchM_Exit_Can_CAN_EXCLUSIVE_AREA_11();
        /* Wait for reset cycle to complete */
        while ((FALSE == Can_Lld_CheckReset(BaseAddr)) && (TimeOutCntTemp < CAN_TIMEOUT_COUNT))
        {
            ++TimeOutCntTemp;
        }
        /* Timeout check, if timeout, return go to freeze mode failed */
        if (TimeOutCntTemp >= CAN_TIMEOUT_COUNT)
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            RetVal = (Std_ReturnType)E_OK;
        }
    }
    /* GCOVR_EXCL_STOP */
    else
    {
        RetVal = (Std_ReturnType)E_OK;
    }
    return RetVal;
}

CAN_FUNC static boolean Can_Lld_CheckReset(uint32 BaseAddr)
{
    boolean RetVal;
    if (0U == CAN32_GET_BITS(BaseAddr, CAN_MCR_SOFTRST_MASK))
    {
        RetVal = TRUE;
    }
    else
    {
        RetVal = FALSE;
    }
    return RetVal;
}

CAN_FUNC static void Can_Lld_BusoffHandle(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = (uint32)ChConfigPtr->ChBaseAddr;
    if (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_TWRNINT_MASK))
    {
        if (NULL_PTR != ChConfigPtr->CanCallbackPtr->WarningCallback)
        {
            ChConfigPtr->CanCallbackPtr-> \
            WarningCallback(CAN_TX_ERROR_COUNTER_OVER_96);
        }
        CAN32_WRITE(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_TWRNINT_MASK);
    }
    if (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_RWRNINT_MASK))
    {
        if (NULL_PTR != ChConfigPtr->CanCallbackPtr->WarningCallback)
        {
            ChConfigPtr->CanCallbackPtr-> \
            WarningCallback(CAN_RX_ERROR_COUNTER_OVER_96);
        }
        CAN32_WRITE(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_RWRNINT_MASK);
    }
    if (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_BOFFDONEINT_MASK))
    {
        if (NULL_PTR != ChConfigPtr->CanCallbackPtr->WarningCallback)
        {
            ChConfigPtr->CanCallbackPtr->WarningCallback(CAN_BUSOFF_DONE);
        }
        CAN32_WRITE(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_BOFFDONEINT_MASK);
    }
    /*update Can_Lld_AbortPendingMsg can be called when CAN_READY */
    if (0U != CAN32_GET_BITS(BaseAddr + CAN_ESR1_OFFSET32, CAN_ESR1_BOFFINT_MASK))
    {
        /* After bus-off detection, the CAN controller shall transition to the state STOPPED
           and the Can module shall ensure that the CAN controller doesn't participate on
           the network anymore. STARTED -> STOPPED Trace : SWS_Can_00020.
           Trace : SWS_Can_00272 */
        (void)Can_Lld_StopChn(ChConfigPtr);
        /* triggered by hardware if the CAN controller reaches bus-off state, The CanIf module
           is notified with the function CanIf _ControllerBusOff after STOPPED state is reached
           referring to the corresponding CAN controller with the abstract CanIf ControllerId
           Trace : SWS_Can_00020 */
        CanIf_ControllerBusOff(ChConfigPtr->CanChannelId);
        /* Callback to CanIf layer to indication rx */
        if (NULL_PTR != ChConfigPtr->CanCallbackPtr->BusoffCallback)
        {
            ChConfigPtr->CanCallbackPtr->BusoffCallback();
        }
        CAN32_WRITE(BaseAddr + CAN_ESR1_OFFSET32, (uint32)1U << CAN_ESR1_BOFFINT_SHIFT);
    }
}

#endif

#define CAN_CONDITIONALCOMPILATION_CODE (STD_ON)
#if (CAN_CONDITIONALCOMPILATION_CODE == STD_ON)
#if((CAN_TX_PROCESS_HAS_POLLING == STD_ON) || (CAN_RX_PROCESS_HAS_POLLING == STD_ON))
CAN_FUNC static uint32 Can_Lld_GetIntFlag(uint32 BaseAddr, uint8 RegisterIdx)
{
    uint32 RetVal;
#if (0U < CAN_MAILBOX_REGION_NUM)
    if (0U == RegisterIdx)
    {
        RetVal = CAN32_READ(BaseAddr + CAN_IFLAG1_OFFSET32);
    }
#endif
    /* GCOVR_EXCL_START: The fellowing code is equal to up code */
#if (1U < CAN_MAILBOX_REGION_NUM)
    else if (1U == RegisterIdx)
    {
        RetVal = CAN32_READ(BaseAddr + CAN_IFLAG2_OFFSET32);
    }
#endif
#if (2U < CAN_MAILBOX_REGION_NUM)
    else if (2U == RegisterIdx)
    {
        RetVal = CAN32_READ(BaseAddr + CAN_IFLAG3_OFFSET32);
    }
#endif
#if (3U < CAN_MAILBOX_REGION_NUM)
    else if (3U == RegisterIdx)
    {
        RetVal = CAN32_READ(BaseAddr + CAN_IFLAG4_OFFSET32);
    }
#endif
    else
    {
        RetVal = CAN32_READ(BaseAddr + CAN_IFLAG1_OFFSET32);
    }
    /* GCOVR_EXCL_STOP */
    return RetVal;
}
#endif

#if (CAN_LEGACY_FIFO_USAGE == STD_ON)
CAN_FUNC static uint32 Can_Lld_ShiftFilter(uint32 Data, sint8 ShiftBits)
{
    uint32 RetVal;
    if (ShiftBits > 0)
    {
        RetVal = (Data << (uint8)ShiftBits);
    }
    else
    {
        RetVal = (Data >> (uint8)(-ShiftBits));
    }
    return RetVal;
}

CAN_FUNC static void Can_Lld_CheckLgcRxFifoRx(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = (uint32)ChConfigPtr->ChBaseAddr;
    uint32 TimeOutCntTemp = 0;
    Can_HwHandleType Hrh = ChConfigPtr->CanFifoHrhId;
    while ((TRUE == Can_Lld_CheckLgcRxFifoFlag(ChConfigPtr->ChBaseAddr)) && (TimeOutCntTemp < CAN_CONST_LEGACY_FIFO_DEPTH))
    {
        /* Read rx fifo Data  */
        uint32 RamArray[CAN_MB_RAM_MAX_WORD_SIZE];
        Can_Lld_CopyMsg((uint32 *)(BaseAddr + CAN_RAM_START_OFFSET32), RamArray, CAN_LEGACY_FIFO_RAM_DATA_SIZE);
        /* Clear flag */
        CAN32_WRITE(BaseAddr + CAN_IFLAG1_OFFSET32, CAN_IFLAG1_BUF5I_MASK);
        Can_Lld_HandleMsg(RamArray, Hrh, ChConfigPtr);
        ++TimeOutCntTemp;
    }
}

CAN_FUNC static void Can_Lld_CheckLgcRxFifoFull(const Can_ChannelConfigType *ChConfigPtr)
{
    /* when the number of unread messages in the Rx FIFO is increased to 5 from 4 due to the
    reception of a new message, meaning that the Rx FIFO is almost full */
    uint32 BaseAddr = ChConfigPtr->ChBaseAddr;
    uint32 IntFlag = CAN32_READ(BaseAddr + CAN_IFLAG1_OFFSET32);
    Can_CallbackPtrOfFifoFullType FullCallback = ChConfigPtr->CanCallbackPtr->ReceiveFifoFullCallback;
    if (0U != (IntFlag & CAN_IFLAG1_BUF6I_MASK))
    {
        if (NULL_PTR != FullCallback)
        {
            FullCallback();
        }
        /* Clear overflow flag */
        CAN32_WRITE(BaseAddr + CAN_IFLAG1_OFFSET32, CAN_IFLAG1_BUF6I_MASK);
    }
}

CAN_FUNC static void Can_Lld_CheckLgcRxFifoOvf(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = ChConfigPtr->ChBaseAddr;
    uint32 IntFlag = CAN32_READ(BaseAddr + CAN_IFLAG1_OFFSET32);
    Can_CallbackPtrOfFifoOvfType OverflowCallback = ChConfigPtr->CanCallbackPtr->ReceiveFifoOverflowCallback;
    if (0U != (IntFlag & CAN_IFLAG1_BUF7I_MASK))
    {
        Can_Bak_CallDatalost(ChConfigPtr->CanChannelId);
        if (NULL_PTR != OverflowCallback)
        {
            OverflowCallback();
        }
        /* Clear overflow flag */
        CAN32_WRITE(BaseAddr + CAN_IFLAG1_OFFSET32, CAN_IFLAG1_BUF7I_MASK);
    }
}
#endif /* (CAN_LEGACY_FIFO_USAGE == STD_ON) */

#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)
CAN_FUNC static void Can_Lld_CheckEnhRxFifoRx(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = ChConfigPtr->ChBaseAddr;
    uint32 EnhFifoFrameCnt = 0;
    Can_HwHandleType Hrh = ChConfigPtr->CanFifoHrhId;
    while ((TRUE == Can_Lld_CheckFlagEnhFifo(ChConfigPtr->ChBaseAddr)) && (EnhFifoFrameCnt < CAN_CONST_ENHANCE_FIFO_DEPTH))
    {
        /* Read rx fifo Data  */
        uint32 RamArray[CAN_MB_RAM_MAX_WORD_SIZE];
        Can_Lld_CopyMsg((uint32 *)(BaseAddr + CAN_ENHANCE_RX_FIFO_RAM_OFFSET32), RamArray, CAN_ENHANCED_FIFO_RAM_DATA_SIZE);
        /* Clear flag */
        CAN32_WRITE(BaseAddr + CAN_ERFSR_OFFSET32, CAN_ERFSR_ERFDA_MASK);
        Can_Lld_HandleMsg(RamArray, Hrh, ChConfigPtr);
        ++EnhFifoFrameCnt;
    }
}

CAN_FUNC static void Can_Lld_CheckEnhRxFifoFull(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = ChConfigPtr->ChBaseAddr;
    Can_CallbackPtrOfFifoFullType FullCallback = ChConfigPtr->CanCallbackPtr->ReceiveFifoFullCallback;
    if (0U != CAN32_GET_BITS(BaseAddr + CAN_ERFSR_OFFSET32, CAN_ERFSR_ERFWMI_MASK))
    {
        if (NULL_PTR != FullCallback)
        {
            FullCallback();
        }
        CAN32_WRITE(BaseAddr + CAN_ERFSR_OFFSET32, CAN_ERFSR_ERFWMI_MASK);
    }
}

CAN_FUNC static void Can_Lld_CheckEnhRxFifoOvf(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = ChConfigPtr->ChBaseAddr;
    Can_CallbackPtrOfFifoOvfType OverflowCallback = ChConfigPtr->CanCallbackPtr->ReceiveFifoOverflowCallback;
    /* when an incoming message was lost because the Rx FIFO is full */
    if (0U != CAN32_GET_BITS(BaseAddr + CAN_ERFSR_OFFSET32, CAN_ERFSR_ERFOVF_MASK))
    {
        Can_Bak_CallDatalost(ChConfigPtr->CanChannelId);
        /* call back */
        if (NULL_PTR != OverflowCallback)
        {
            OverflowCallback();
        }
        /* Clear overflow flag */
        CAN32_WRITE(BaseAddr + CAN_ERFSR_OFFSET32, CAN_ERFSR_ERFOVF_MASK);
    }
}

CAN_FUNC static void Can_Lld_CheckEnhRxFifoUdf(const Can_ChannelConfigType *ChConfigPtr)
{
    uint32 BaseAddr = ChConfigPtr->ChBaseAddr;
    Can_CallbackPtrOfWarningType WarnCallback = ChConfigPtr->CanCallbackPtr->WarningCallback;
    /* Rx fifo underflow process */
    if (0U != CAN32_GET_BITS(BaseAddr + CAN_ERFSR_OFFSET32, CAN_ERFSR_ERFUFW_MASK))
    {
        if (NULL_PTR != WarnCallback)
        {
            WarnCallback(CAN_ENHANCE_RX_FIFO_UNDERFLOW);
        }
        CAN32_WRITE(BaseAddr + CAN_ERFSR_OFFSET32, CAN_ERFSR_ERFUFW_MASK);
    }
}
#endif

#if (CAN_DMA_USAGE == STD_ON)
CAN_FUNC static Can_ReturnType Can_Lld_DmaConfig(const Can_ChannelConfigType *ChConfigPtr, Can_HwObjRegionType Can_FifoType)
{
    uint32 BaseAddr = ChConfigPtr->ChBaseAddr;
    Can_ReturnType RetVal = CAN_NOT_OK;
    uint32 Can_DmaSrcAddr, Can_DmaDestAddr, Tmp32;
    sint32 tmps32;
    CddDma_ChannelType dmaChannel = ChConfigPtr->CanDmaChannel;
    CddDma_TransferConfigType Can_DmaReceiveConfig = *DmaChannelTransferConfigArray[dmaChannel];
#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
    Can_DmaReceiveConfig.ChannelPollingMode = Can_ConfigPtr->CanHohCfgPtr[ChConfigPtr->CanFifoHrhId].UsePolling;
#else
    Can_DmaReceiveConfig.ChannelPollingMode = FALSE;
    RetVal = CAN_OK;
#endif
    Can_DmaReceiveConfig.SrcTransferSize = DMA_TRANSFER_SIZE_4_BYTE;
    Can_DmaReceiveConfig.DestTransferSize = DMA_TRANSFER_SIZE_4_BYTE;
    Can_DmaReceiveConfig.SrcOffset = 0x4;
    Can_DmaReceiveConfig.DestOffset = 0x4;
    Can_DmaReceiveConfig.TriggerCount = 0x01U;
    Can_DmaReceiveConfig.DisableReqOnCompletion = TRUE;
    Can_DmaSrcAddr = BaseAddr + CAN_RAM_START_OFFSET32;
    Can_DmaDestAddr = (uint32)(&Can_DmaBuffer[ChConfigPtr->CanChannelId][0]);
    Tmp32  = 16U;
    tmps32 = 16;
#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)
    if (CAN_RX_FIFO_ENHANCE == Can_FifoType)
    {
        Can_DmaSrcAddr = BaseAddr + CAN_ENHANCE_RX_FIFO_RAM_OFFSET32;
        Tmp32  = 80U;
        tmps32 = 80;
    }
#endif
    Can_DmaReceiveConfig.TransferLoopByteCount = Tmp32;
    Can_DmaReceiveConfig.SrcLastAddrAdjust = -tmps32;
    Can_DmaReceiveConfig.DestLastAddrAdjust = -tmps32;
    (void)CddDma_SetLogicChannelTransfer(dmaChannel, Can_DmaSrcAddr, Can_DmaDestAddr, &Can_DmaReceiveConfig);
    /**
     * @page misra_violations MISRA-C:2012 violations
     * PRQA S 0313 Rule-11.1: Casting to different function pointer type.
     * integer type
     */
    CddDma_InstallCallback(dmaChannel, (CddDma_CallbackType)Can_Lld_DmaReceiveData, ChConfigPtr->CanChannelId);
    /**
     * @page misra_violations MISRA-C:2012 violations
     * PRQA S 0313 Rule-11.1: Casting to different function pointer type.
     * integer type
     */
    CddDma_InstallErrorCallback(dmaChannel, (CddDma_CallbackType)Can_Lld_DmaReceiveError, ChConfigPtr->CanChannelId);
    CddDma_StartChannel(dmaChannel);
    return RetVal;
}
#endif
#endif /* #if (CAN_CONDITIONALCOMPILATION_CODE == STD_ON) */
/*==================================================================================================
*                                          IRQ IMPLEMENT
==================================================================================================*/
#define CAN_IRQPROCESS_CODE (STD_ON)
#if (CAN_IRQPROCESS_CODE == STD_ON)
#if (CAN_BUSOFF_PROCESS_HAS_INTERRUPT == STD_ON)
CAN_FUNC void Can_Lld_IntHwObjPrcsORedBusoff(uint8 ChnHwId)
{
    const Can_ChannelConfigType *ChConfigPtr = Can_Lld_GetChConfigPtr(ChnHwId);
    Can_Lld_BusoffHandle(ChConfigPtr);
}
#endif /*#if (CAN_BUSOFF_PROCESS_HAS_INTERRUPT == STD_ON)*/

CAN_FUNC void Can_Lld_IntHwObjPrcsErr(uint8 ChnHwId)
{
    const Can_ChannelConfigType *ChConfigPtr = Can_Lld_GetChConfigPtr(ChnHwId);
#if (CAN_MEMECC_FEATURE == STD_ON)
    Can_Lld_ProcessEcc(ChConfigPtr);
#endif
    /* Errors Interrupt Mask */
    Can_Lld_ProcessError(ChConfigPtr);
#if (CAN_FD_USAGE == STD_ON)
    if (TRUE == ChConfigPtr->FdUsage)
    {
        /* FAST(CANFD) Errors Interrupt Mask */
        Can_Lld_ProcessErrorFast(ChConfigPtr);
    }
#endif/*if(CAN_FD_USAGE == STD_ON)*/
    /* If the CAN hardware can be configured to lock the RX hardware object after reception, it
       could happen that the newly arrived message cannot be stored to the hardware buffer. In
       this case, the CAN controller detects an "overrun" event, if supported by hardware
       Trace : SWS_Can_00012 */
}

#if((CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON) || (CAN_TX_PROCESS_HAS_INTERRUPT == STD_ON))
CAN_FUNC LOCAL_INLINE void Can_Lld_IrqProcessMailBox(uint8 IrqId, uint8 HwObjId, const Can_ChannelConfigType *ChConfigPtr)
{
    Can_HwHandleType Hoh;
    Can_HwObjRegionType RegionId = (Can_HwObjRegionType)0U;
    uint8 MailBoxId = 0U;
    uint8 HwObjFlagId = (IrqId * CAN_CONST_MAILBOXNUM_PER_IRG_ENTRANCE) + HwObjId;
    uint8 CanChannelId = ChConfigPtr->CanChannelId;
    RegionId = ChConfigPtr->CanHwFlagMatrixPtr[HwObjFlagId].CanHwRegionId;
    MailBoxId = ChConfigPtr->CanHwFlagMatrixPtr[HwObjFlagId].CanHwObjId;
    Hoh  = ChConfigPtr->CanHwFlagMatrixPtr[HwObjFlagId].CanHohId;
    Can_CallbackPtrOfTransmitType Callback;
    /* Which flag register */
    uint8 RegisterIdx = HwObjFlagId / (uint8)CAN_CONST_MAILBOXNUM_PER_RAMREGION;
    /* Which bit in a flag register */
    uint8 FlagIdx = HwObjFlagId % (uint8)CAN_CONST_MAILBOXNUM_PER_RAMREGION;
    if (Hoh != MB_NOT_USE)
    {
        if (CAN_RECEIVE == Can_ConfigPtr->CanHohCfgPtr[Hoh].ObjectType)
        {
            /* Received one msg */
            const uint32 *MailBoxAddr = Can_Lld_GetMailboxAddr(ChConfigPtr, (uint32)RegionId, (uint32)MailBoxId);
            uint32 RamArray[CAN_MB_RAM_MAX_WORD_SIZE];
            const uint8 MbPayloadSize = ChConfigPtr->PayloadConfigPtr->MbRegionConfig[RegionId].PayloadSize;
            Can_Lld_CopyMsg(MailBoxAddr, RamArray, MbPayloadSize);
            /* Clear flag */
            Can_Lld_ClrMailBoxIntFlag(ChConfigPtr->ChBaseAddr, RegisterIdx, FlagIdx);
            Can_Lld_HandleMsg(RamArray, Hoh, ChConfigPtr);
        }
        else
        {
            /* Comlate tx */
            Can_Lld_ClrMailBoxIntFlag(ChConfigPtr->ChBaseAddr, RegisterIdx, FlagIdx);
            /* Callback to CanIf layer to confirmation tx */
            CanIf_TxConfirmation(Can_ChHwObjPduId[CanChannelId][RegionId][MailBoxId]);
            Callback = Can_ConfigPtr->CanTransmitCallback;
            if (NULL_PTR != Callback)
            {
                Callback(Can_ChHwObjPduId[CanChannelId][RegionId][MailBoxId]);
            }
            /* Unlock mailbox */
            Can_Lld_UpdateIdleState(CanChannelId, (uint8)RegionId, MailBoxId);
        }
    }
}

CAN_FUNC void Can_Lld_IntHwObjPrcsFrame(uint8 ChnHwId, uint8 RegisterIdx)
{
    const Can_ChannelConfigType *ChConfigPtr = Can_Lld_GetChConfigPtr(ChnHwId);
    uint32 BaseAddr = (uint32)ChConfigPtr->ChBaseAddr;
    uint16 IntFlagValueU16 = 0U;
    uint16 IntMaskValueU16 = 0U;
    uint8 MailboxStartId = 0U;
#if (CAN_ENHANCE_FIFO_USAGE == STD_ON && CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON)
    if ((0U == RegisterIdx) && (CAN_RX_FIFO_ENHANCE == ChConfigPtr->PayloadConfigPtr->RxFifoType))
    {
#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
        if (FALSE == Can_ConfigPtr->CanHohCfgPtr[ChConfigPtr->CanFifoHrhId].UsePolling)
#endif
        {
            if (0U != (CAN32_READ(BaseAddr + CAN_ERFSR_OFFSET32) & CAN_ENHANCE_FIFO_FLAGS_MASK))
            {
                Can_Lld_PrcsEnhRxFifo(ChConfigPtr);
            }
        }
    }
#endif/*#if (CAN_ENHANCE_FIFO_USAGE == STD_ON && CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON) */

#if (CAN_LEGACY_FIFO_USAGE == STD_ON)
    if (CAN_RX_FIFO_LEGACY  == ChConfigPtr->PayloadConfigPtr->RxFifoType)
    {
#if (CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON)
        if (0U == RegisterIdx)
        {
#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
            if (FALSE == Can_ConfigPtr->CanHohCfgPtr[ChConfigPtr->CanFifoHrhId].UsePolling)
#endif
            {
                if (0U != (CAN32_READ(BaseAddr + CAN_IFLAG1_OFFSET32) & CAN_LEGACY_FIFO_FLAGS_MASK))
                {
                    Can_Lld_PrcsLgcRxFifo(ChConfigPtr);
                }
            }
        }
#endif
        uint8 Tmp8 = ChConfigPtr->PayloadConfigPtr->LegacyRxFifoConfigPtr->LegacyRxFifoOccupyMailboxNum;
        if (0U == RegisterIdx)
        {
            MailboxStartId = Tmp8;
        }
        else if (1U == RegisterIdx)
        {
            if (CAN_CONST_MAILBOXNUM_PER_IRG_ENTRANCE < Tmp8)
            {
                MailboxStartId = Tmp8 - CAN_CONST_MAILBOXNUM_PER_IRG_ENTRANCE;
            }
            else
            {
                MailboxStartId = 0U;
            }
        }
        else
        {
            /*here do nothing*/
        }
    }
#endif/*#if (CAN_LEGACY_FIFO_USAGE == STD_ON)*/

    switch (RegisterIdx)
    {
#if (0U < CAN_MAILBOX_REGION_NUM)
        case CAN_CONST_IRQ_ENTRANCE_0:
        {
            IntFlagValueU16 = CAN16_READ(BaseAddr + CAN_IFLAG1_OFFSET32);
            IntMaskValueU16 = CAN16_READ(BaseAddr + CAN_IMASK1_OFFSET32);
            break;
        }
        case CAN_CONST_IRQ_ENTRANCE_1:
        {
            IntFlagValueU16 = CAN16_READ(BaseAddr + CAN_IFLAG1_OFFSET32 + 2U);
            IntMaskValueU16 = CAN16_READ(BaseAddr + CAN_IMASK1_OFFSET32 + 2U);
            break;
        }
#endif
#if (1U < CAN_MAILBOX_REGION_NUM) /* GCOVR_EXCL_START the fellowing code is equal to uplayer */
        case CAN_CONST_IRQ_ENTRANCE_2:
        {
            IntFlagValueU16 = CAN16_READ(BaseAddr + CAN_IFLAG2_OFFSET32);
            IntMaskValueU16 = CAN16_READ(BaseAddr + CAN_IMASK2_OFFSET32);
            break;
        }
        case CAN_CONST_IRQ_ENTRANCE_3:
        {
            IntFlagValueU16 = CAN16_READ(BaseAddr + CAN_IFLAG2_OFFSET32 + 2U);
            IntMaskValueU16 = CAN16_READ(BaseAddr + CAN_IMASK2_OFFSET32 + 2U);
            break;
        }
#endif
#if (2U < CAN_MAILBOX_REGION_NUM)
        case CAN_CONST_IRQ_ENTRANCE_4:
        {
            IntFlagValueU16 = CAN16_READ(BaseAddr + CAN_IFLAG3_OFFSET32);
            IntMaskValueU16 = CAN16_READ(BaseAddr + CAN_IMASK3_OFFSET32);
            break;
        }
        case CAN_CONST_IRQ_ENTRANCE_5:
        {
            IntFlagValueU16 = CAN16_READ(BaseAddr + CAN_IFLAG3_OFFSET32 + 2U);
            IntMaskValueU16 = CAN16_READ(BaseAddr + CAN_IMASK3_OFFSET32 + 2U);
            break;
        }
#endif
#if (3U < CAN_MAILBOX_REGION_NUM)
        case CAN_CONST_IRQ_ENTRANCE_6:
        {
            IntFlagValueU16 = CAN16_READ(BaseAddr + CAN_IFLAG4_OFFSET32);
            IntMaskValueU16 = CAN16_READ(BaseAddr + CAN_IMASK4_OFFSET32);
            break;
        }
        case CAN_CONST_IRQ_ENTRANCE_7:
        {
            IntFlagValueU16 = CAN16_READ(BaseAddr + CAN_IFLAG4_OFFSET32 + 2U);
            IntMaskValueU16 = CAN16_READ(BaseAddr + CAN_IMASK4_OFFSET32 + 2U);
            break;
        }
#endif
        default:
        {
            /* here do nothing */
            break;
        }
            /* GCOVR_EXCL_STOP */
    }
    if (0U != (IntFlagValueU16 & IntMaskValueU16))
    {
        for (uint8 Index = MailboxStartId; Index < CAN_CONST_MAILBOXNUM_PER_IRG_ENTRANCE; ++Index)
        {
            if ((((IntFlagValueU16 >> Index) & 0x01U) != 0U) && (((IntMaskValueU16 >> Index) & 0x01U) != 0U))
            {
                (void)Can_Lld_IrqProcessMailBox(RegisterIdx, Index, ChConfigPtr);
            }
        }
    }
}
#endif/*#if((CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON) || (CAN_TX_PROCESS_HAS_INTERRUPT == STD_ON))*/
#endif

#if (CAN_WAKEUP_SUPPORT == STD_ON)
CAN_FUNC void Can_Lld_IntHwObjProcess_Wakeup(uint8 ChnHwId)
{
    const Can_ChannelConfigType *ChConfigPtr = Can_Lld_GetChConfigPtr(ChnHwId);
    /**
     * [SWS_Can_00271]
     * On hardware wakeup (triggered by a wake-up event from CAN bus), the Can module shall call
     * the function EcuM_CheckWakeup either in interrupt context or in the context of Can_MainFunction_Wakeup.
     */
    EcuM_CheckWakeup(ChConfigPtr->EcuMWakeupSource);
    /**
     * [SWS_Can_00270]
     * On hardware wakeup (triggered by a wake-up event from CAN bus), the CAN controller shall
     * transition into the state STOPPED.
     */
    (void)Can_SetControllerMode(ChConfigPtr->CanChannelId, CAN_CS_STOPPED);
    /* Clear flag */
    /* Can_SetControllerMode will call clear flag function */
}
#endif

#define CAN_STOP_SEC_CODE
#include "Can_MemMap.h"

/* The features list that do not accord with Autosar */
/* 1. CAN_CS_SLEEP is not fully supported in hardware. */
/* 2. Do not support Icom */

#ifdef __cplusplus
}
#endif

/** @} */

