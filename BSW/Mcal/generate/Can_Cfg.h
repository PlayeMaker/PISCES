/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file Can_Cfg.h
 * @brief 
 * 
 */


#ifndef CAN_CFG_H
#define CAN_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 */

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "Can_GeneralTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_VENDOR_ID_CFG                      (180)
#define CAN_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define CAN_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define CAN_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define CAN_SW_MAJOR_VERSION_CFG               (0)
#define CAN_SW_MINOR_VERSION_CFG               (9)
#define CAN_SW_PATCH_VERSION_CFG               (1)

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define CAN_LOGIC_CHANNEL_0             (0U) /**< LOGIC CAN controller 0 ID */
#define CAN_LOGIC_CHANNEL_1             (1U) /**< LOGIC CAN controller 1 ID */
#define CAN_LOGIC_CHANNEL_2             (2U) /**< LOGIC CAN controller 2 ID */
#define CAN_LOGIC_CHANNEL_3             (3U) /**< LOGIC CAN controller 3 ID */
#define CAN_LOGIC_CHANNEL_4             (4U) /**< LOGIC CAN controller 4 ID */
#define CAN_LOGIC_CHANNEL_5             (5U) /**< LOGIC CAN controller 5 ID */
#define CAN_LOGIC_CHANNEL_6             (6U) /**< LOGIC CAN controller 6 ID */
#define CAN_LOGIC_CHANNEL_7             (7U) /**< LOGIC CAN controller 7 ID */

#define FLEXCAN_0                       (0U) /**< Hardware CAN controller 0 ID */
#define FLEXCAN_1                       (1U) /**< Hardware CAN controller 1 ID */
#define FLEXCAN_2                       (2U) /**< Hardware CAN controller 2 ID */
#define FLEXCAN_3                       (3U) /**< Hardware CAN controller 3 ID */
#define FLEXCAN_4                       (4U) /**< Hardware CAN controller 4 ID */
#define FLEXCAN_5                       (5U) /**< Hardware CAN controller 5 ID */
#define FLEXCAN_6                       (6U) /**< Hardware CAN controller 6 ID */
#define FLEXCAN_7                       (7U) /**< Hardware CAN controller 7 ID */

#define LEGACY_FORMAT_A                 (0U)
#define LEGACY_FORMAT_B                 (1U)
#define LEGACY_FORMAT_C                 (2U)
#define LEGACY_FORMAT_D                 (3U)

/* 8  bytes per frame with 16 bytes payload, case type 0, every MB region can contain 32MBs */
#define CAN_FD_FRAME_SIZE_8            (0U)
/* 16 bytes per frame with 24 bytes payload, case type 1, every MB region can contain 21MBs */
#define CAN_FD_FRAME_SIZE_16            (1U)
/* 32 bytes per frame with 40 bytes payload, case type 2, every MB region can contain 12MBs */
#define CAN_FD_FRAME_SIZE_32            (2U)
/* 64 bytes per frame with 72 bytes payload, case type 3, every MB region can contain 7MBs */
#define CAN_FD_FRAME_SIZE_64            (3U)

#define CAN_MASK_INDIVIDUAL             (0U)
#define CAN_MASK_GLOBAL                 (1U)
#define CAN_MASK_MIXED                  (2U)
#define CAN_EVENT_PROCESS_INTERRUPT     (0U)
#define CAN_EVENT_PROCESS_POLLING       (1U)
#define CAN_EVENT_PROCESS_MIXED         (2U)

#define MAX_MB_QUALITY_PER_REGION_PLSIZETYPE_0    (32U)
#define MAX_MB_QUALITY_PER_REGION_PLSIZETYPE_1    (21U)
#define MAX_MB_QUALITY_PER_REGION_PLSIZETYPE_2    (12U)
#define MAX_MB_QUALITY_PER_REGION_PLSIZETYPE_3    (7U)

#define MB_NOT_USE                      (0xFFU)


/**
 * @brief        Switches the development error detection and notification on or off.
 * @details      * true: detection and notification is enabled.
 * false: detection and notification is disabled.
 *
 * @ref          ECUC_Can_00064
 * @scope        LOCAL
 */
#define CAN_DEV_ERROR_DETECT           (STD_ON)

/**
 * @brief        The support of the Can_SetBaudrate API is optional.
 * @details      If this parameter is set to true the Can_SetBaudrate API shall be supported.
    Otherwise the API is not supported.
 *
 * @ref          ECUC_Can_00482
 * @scope        ECU
 */
#define CAN_SET_BAUDRATE_API           (STD_OFF)
/**
* @brief        Switches the Can_GetVersionInfo() API ON or OFF.
*
* @ref          ECUC_Can_00106
* @scope        LOCAL
*/
#define CAN_VERSION_INFO_API           (STD_OFF)
/**
* @brief        Specifies the InstanceId of this module instance. If only one instance is
*    present it shall have the Id 0.
*
* @ref          ECUC_Can_00320
* @scope        LOCAL
*/
#define CAN_INDEX                      (0)
/**
* @brief        This parameter describes the period for cyclic call to Can_MainFunction_Mode.
* Unit is seconds.
*
* @ref          ECUC_Can_00376
* @scope
*/
#define CAN_MAIN_FUNCTION_MODE_PERIOD          (0.001)


/**
* @brief        Specifies the maximum time for blocking function until a timeout is detected.
* Unit is seconds.
*
* @ref          ECUC_Can_00113
* @scope        LOCAL
*/
#define CAN_TIMEOUT_DURATION                   (0.0001)

#define CAN_DMA_USAGE                         (STD_OFF)


#ifdef CAN_ENABLE_USER_MODE_SUPPORT
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
#error "Must define MCAL_ENABLE_USER_MODE_SUPPORT if CAN_ENABLE_USER_MODE_SUPPORT is defined"
#endif
#endif

/* CanGeneral_CanIcomGeneral */
#define CAN_PUBLIC_ICOM_SUPPORT        (STD_OFF)
/**
* @brief         Defines the level of Pretended Networking.
* @details       This parameter is reserved for future implementations
*                (Pretended Networking level 2).
*
* @ref          ECUC_Can_00445
* @scope        ECU
* @note range: s
*   CAN_ICOM_LEVEL_ONE
*   CAN_ICOM_LEVEL_TWO
*/
#define CAN_ICOM_LEVEL                 (CAN_ICOM_LEVEL_ONE)
/**
* @brief        Defines the variant, which is supported by this CanController
*
* @ref          ECUC_Can_00446
* @scope        ECU
* @note range: s
*   CAN_ICOM_VARIANT_HW
*   CAN_ICOM_VARIANT_NONE
*   CAN_ICOM_VARIANT_SW
*/
#define CAN_ICOM_VARIANT               (CAN_ICOM_VARIANT_NONE)

/**
 * @brief This parameter describes current chip support wakeup or not.
 */
#define CAN_WAKEUP_SUPPORT             (STD_OFF)

/**
 * @brief This parameter describes current configuration use ICOM or not.
 */
#define CAN_ICOM_USAGE         (STD_OFF)

/**
 * @brief Pre-compile Support.
 */
#define CAN_FIXED_PB_CONFIG            (STD_OFF)

/* CanGeneral_CanMainFunctionRWPeriods */
/**
* @brief         This parameter describes the period for cyclic call to Can_MainFunction_Read
*                or Can_MainFunction_Write depending on the referring item. Unit is seconds.
*                Different poll-cycles will be configurable if more than one
*                CanMainFunctionPeriod is configured. In this case multiple
*                Can_MainFunction_Read() or Can_MainFunction_Write() will be provided by
*                the CAN Driver module.
*
* @ref           ECUC_Can_00484
* @scope         LOCAL
*/
#define CAN_MAIN_FUNCTION_RW_PERIOD    (STD_OFF)

#define CAN_CHANNEL_USED_NUM           (3U)
#define CAN_CHANNEL_MAX_NUM            (3U)


/**
 * @brief The fellowing macro is for FLEXCAN_0.
 */
#define FLEXCAN_0_RX_PROCESS_HAS_INTERRUPT      (STD_ON)
#define FLEXCAN_0_RX_PROCESS_HAS_POLLING        (STD_OFF)
#define FLEXCAN_0_TX_PROCESS_HAS_INTERRUPT      (STD_ON)
#define FLEXCAN_0_TX_PROCESS_HAS_POLLING        (STD_OFF)
#define FLEXCAN_0_BUSOFF_PROCESS_HAS_INTERRUPT  (STD_ON)
#define FLEXCAN_0_BUSOFF_PROCESS_HAS_POLLING    (STD_OFF)
#define FLEXCAN_0_RAM_REGION_NUM                (2U)
#define FLEXCAN_0_WAKEUP_ENABLE                 (STD_OFF)

/**
 * @brief The fellowing macro is for all channel
 */
#define CAN_RX_PROCESS_HAS_INTERRUPT      (STD_ON)
#define CAN_RX_PROCESS_HAS_POLLING        (STD_OFF)
#define CAN_TX_PROCESS_HAS_INTERRUPT      (STD_ON)
#define CAN_TX_PROCESS_HAS_POLLING        (STD_OFF)
#define CAN_BUSOFF_PROCESS_HAS_INTERRUPT  (STD_ON)
#define CAN_BUSOFF_PROCESS_HAS_POLLING    (STD_OFF)

#define CAN_FD_USAGE                      (STD_OFF)
#define CAN_ENHANCE_FIFO_USAGE            (STD_ON)
#define CAN_LEGACY_FIFO_USAGE             (STD_OFF)

#define CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM (0U)

#define CAN_ENHANCE_FIFO_CHANNEL_NUM   (1U)

#define CAN_MAILBOX_REGION_NUM         (2U)

#define CAN_MAXIM_DATA_LENGTH          (64)

#define CAN_MEMECC_FEATURE             (STD_OFF)

#define CAN_SCHM_SUPPORT               (STD_ON)

#define CAN_FIFO_IDHIT_USAGE          (STD_OFF)

#define CAN_WAKEUP_FUNCTIONALITY_API              (STD_OFF)
#define CAN_API_DEINIT_ENABLE                     (STD_ON)
#define CAN_API_DISABLE_CONTROLLER_INTERRUPTS     (STD_ON)
#define CAN_API_ENABLE_CONTROLLER_INTERRUPTS      (STD_ON)
#define CAN_API_GET_CONTROLLER_ERROR_STATE        (STD_ON)
#define CAN_API_GET_CONTROLLER_MODE               (STD_ON)
#define CAN_API_GET_CONTROLLER_RX_ERROR_COUNTER   (STD_ON)
#define CAN_API_GET_CONTROLLER_TX_ERROR_COUNTER   (STD_ON)
#define CAN_API_MAINFUNCTION_WAKEUP               (STD_OFF)
#define CAN_API_ABORT_CONTROLLER_PENDING_MESSAGE  (STD_OFF)
/*==================================================================================================
 *                                       SYMBOLIC NAME
==================================================================================================*/
#define CanConf_CanController_CAN0                                        (0U)


#define CanConf_CanHardwareObject_CAN0_RX_EN_FIFO                             (0U)
#define CanConf_CanHardwareObject_CAN0_TX_FD                                  (1U)

/*==================================================================================================
 *                                      PRECMPILE CONFIG
==================================================================================================*/
/**
 * @brief Can MainFunction RW typedef.
 * @note trace: SWS_Can_00442, SWS_Can_00441
 */
typedef void (*Can_MainFunction_RW)(void);

#define CAN_LOGIC_CHANNEL_0_MAP               (FLEXCAN_0)
#define CAN_LOGIC_CHANNEL_0_USAGE             (STD_ON)
#define FLEXCAN_0_MAP                          (STD_ON)
#define CAN_0_FD_USAGE                        (STD_OFF)
#define CAN_0_ENHANCE_FIFO_USAGE              (STD_ON)
#define CAN_0_LEGACY_FIFO_USAGE               (STD_OFF)
#define CAN_0_NONE_FIFO_USAGE                 (STD_OFF)
#define CAN_0_DMA_USAGE                       (STD_OFF)
#define CAN_0_RX_PROCESS_MODE                 (CAN_EVENT_PROCESS_INTERRUPT)
#define CAN_0_TX_PROCESS_MODE                 (CAN_EVENT_PROCESS_INTERRUPT)
#define CAN_0_BUSOFF_PROCESS_MODE             (CAN_EVENT_PROCESS_INTERRUPT)
#define CAN_0_RAM_REGION_NUM                  (2U)
#define CAN_0_CAN_RAM_REGION_0_MB_NUM   (32U)
#define CAN_0_CAN_RAM_REGION_1_MB_NUM   (32U)


extern uint16 * Can_RxFifoLatestIdhit[1];



#ifdef __cplusplus
}
#endif

#endif /* CAN_CFG_H */

/** @} */

