/**
 * @file    Can_Types.h
 * @version V0.9.1
 *
 * @brief   AUTOSAR Can module interface
 * @details API implementation for CAN driver
 *
 * @addtogroup CAN_MODULE
 * @{
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

#ifndef CAN_TYPES_H
#define CAN_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/
#include "Can_GeneralTypes.h"
#include "Can_Cfg.h"

#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* CAN_DEV_ERROR_DETECT == STD_ON */

#if (CAN_DMA_USAGE == STD_ON)
#include "CddDma.h"
#include "CddDma_Cfg.h"
#include "pSIP_Dma.h"
#endif

#if (CAN_WAKEUP_SUPPORT == STD_ON)
#include "EcuM.h"
#endif

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
 * @file     Can_Types.h
 */
#define CAN_TYPES_VENDOR_ID                      (180)
#define CAN_TYPES_AR_RELEASE_MAJOR_VERSION       (4)
#define CAN_TYPES_AR_RELEASE_MINOR_VERSION       (4)
#define CAN_TYPES_AR_RELEASE_REVISION_VERSION    (0)
#define CAN_TYPES_SW_MAJOR_VERSION               (0)
#define CAN_TYPES_SW_MINOR_VERSION               (9)
#define CAN_TYPES_SW_PATCH_VERSION               (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CAN configuration header file are of the same vendor */
#if (CAN_TYPES_VENDOR_ID != CAN_VENDOR_ID_CFG)
#error "Can_Types.h and Can_Cfg.h have different vendor ids"
#endif

/* Check if source file and CAN configuration header file are of the same Autosar version */
#if ((CAN_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (CAN_TYPES_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION_CFG) || \
     (CAN_TYPES_AR_RELEASE_REVISION_VERSION != CAN_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Can_Types.h and Can_Cfg.h are different"
#endif

/* Check if source file and CAN configuration header file are of the same software version */
#if ((CAN_TYPES_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION_CFG) || \
     (CAN_TYPES_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION_CFG) || \
     (CAN_TYPES_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Can_Types.h and Can_Cfg.h are different"
#endif

/*==================================================================================================
*                                           DEV DEFINES
==================================================================================================*/
/** @brief CAN MODULE INSTANCE ID */
#define CAN_INSTANCE_ID                           ((uint8)0U)
#define CAN_HTH_ERROR_ID                          ((uint8)254U)
#define CAN_INSTANCE_ALL_ID                       ((uint8)255U)

/** @brief CAN MODULE ID */
#define CAN_MODULE_ID                             ((uint8)80U)

#if (CAN_DEV_ERROR_DETECT == STD_ON)
/**
 * @defgroup Can_DEV_ERROR
 * @brief CAN development errors
 */
/** @{ */

/** @brief CAN API service is called using an invalid pointer
            (e.g. the pointer should not be NULL).  */
#define CAN_E_PARAM_POINTER                       ((uint8)0x01)
#define CAN_E_PARAM_HANDLE                        ((uint8)0x02)
#define CAN_E_PARAM_DATA_LENGTH                   ((uint8)0x03)
#define CAN_E_PARAM_CONTROLLER                    ((uint8)0x04)
#define CAN_E_UNINIT                              ((uint8)0x05)
#define CAN_E_TRANSITION                          ((uint8)0x06)
#define CAN_E_PARAM_BAUDRATE                      ((uint8)0x07)
#define CAN_E_ICOM_CONFIG_INVALID                 ((uint8)0x08)
#define CAN_E_INIT_FAILED                         ((uint8)0x09)
#define CAN_E_TESTING                             ((uint8)0x0A)
#define CAN_E_DATALOST                            ((uint8)0x0F)
/** @} */
#endif /* (CAN_DEV_ERROR_DETECT == STD_ON) */

/**
 * @defgroup Can_SID
 * @brief Service ID number for all CAN driver services
 */
/** @{ */
/** @brief API Service ID for Can_CheckWakeup */
#define CAN_SID_CHECK_WAKEUP                      (0x0bU)
/** @brief API Service ID for Can_DeInit */
#define CAN_SID_DE_INIT                           (0x10U)
/** @brief API Service ID for Can_DisableControllerInterrupts */
#define CAN_SID_DISABLE_CONTROLLER_INTERRUPTS     (0x04U)
/** @brief API Service ID for Can_EnableControllerInterrupts */
#define CAN_SID_ENABLE_CONTROLLER_INTERRUPTS      (0x05U)
/** @brief API Service ID for Can_GetControllerErrorState */
#define CAN_SID_GET_CONTROLLER_ERROR_STATE        (0x11U)
/** @brief API Service ID for Can_GetControllerMode */
#define CAN_SID_GET_CONTROLLER_MODE               (0x12U)
/** @brief API Service ID for Can_GetControllerRxErrorCounter */
#define CAN_SID_GET_CONTROLLER_RX_ERROR_COUNTER   (0x30U)
/** @brief API Service ID for Can_GetControllerTxErrorCounter */
#define CAN_SID_GET_CONTROLLER_TX_ERROR_COUNTER   (0x31U)
/** @brief API Service ID for Can_GetVersionInfo */
#define CAN_SID_GET_VERSION_INFO                  (0x07U)
/** @brief API Service ID for Can_Init */
#define CAN_SID_INIT                              (0x00U)
/** @brief API Service ID for Can_MainFunction_BusOff */
#define CAN_SID_MAIN_FUNCTION_BUS_OFF             (0x09U)
/** @brief API Service ID for Can_MainFunction_Mode */
#define CAN_SID_MAIN_FUNCTION_MODE                (0x0cU)
/** @brief API Service ID for Can_MainFunction_Read */
#define CAN_SID_MAIN_FUNCTION_READ                (0x08U)
/** @brief API Service ID for Can_MainFunction_Wakeup */
#define CAN_SID_MAIN_FUNCTION_WAKEUP              (0x0aU)
/** @brief API Service ID for Can_MainFunction_Write */
#define CAN_SID_MAIN_FUNCTION_WRITE               (0x01U)
/** @brief API Service ID for Can_SetBaudrate */
#define CAN_SID_SET_BAUDRATE                      (0x0fU)
/** @brief API Service ID for Can_SetControllerMode */
#define CAN_SID_SET_CONTROLLER_MODE               (0x03U)
/** @brief API Service ID for Can_SetIcomConfiguration */
#define CAN_SID_SET_ICOM_CONFIGURATION            (0x21U)
/** @brief API Service ID for Can_TTAckTimeMark */
#define CAN_SID_TT_ACK_TIME_MARK                  (0x4aU)
/** @brief API Service ID for Can_TTCancelTimeMark */
#define CAN_SID_TT_CAN_SIDCEL_TIME_MARK           (0x49U)
/** @brief API Service ID for Can_TTDisableTimeMarkIRQ */
#define CAN_SID_TT_DISABLE_TIME_MARK_IR_Q         (0x4cU)
/** @brief API Service ID for Can_TTEnableTimeMarkIRQ */
#define CAN_SID_TT_ENABLE_TIME_MARK_IR_Q          (0x4bU)
/** @brief API Service ID for Can_TTGetControllerTime */
#define CAN_SID_TT_GET_CONTROLLER_TIME            (0x33U)
/** @brief API Service ID for Can_TTGetErrorLevel */
#define CAN_SID_TT_GET_ERROR_LEVEL                (0x36U)
/** @brief API Service ID for Can_TTGetMasterState */
#define CAN_SID_TT_GET_MASTER_STATE               (0x34U)
/** @brief API Service ID for Can_TTGetNTUActual */
#define CAN_SID_TT_GET_NT_UACTUAL                 (0x35U)
/** @brief API Service ID for Can_TTGetSyncQuality */
#define CAN_SID_TT_GET_SYNC_QUALITY               (0x47U)
/** @brief API Service ID for Can_TTGetTimeMarkIRQStatus */
#define CAN_SID_TT_GET_TIME_MARK_IR_QSTATUS       (0x4dU)
/** @brief API Service ID for Can_TTGlobalTimePreset */
#define CAN_SID_TT_GLOBAL_TIME_PRESET             (0x3aU)
/** @brief API Service ID for Can_TTMainFunction_IRQ */
#define CAN_SID_TT_MAIN_FUNCTION_IR_Q             (0x50U)
/** @brief API Service ID for Can_TTReceive */
#define CAN_SID_TT_RECEIVE                        (NoneU)
/** @brief API Service ID for Can_TTSetEndOfGap */
#define CAN_SID_TT_SET_END_OF_GAP                 (0x38U)
/** @brief API Service ID for Can_TTSetExtClockSyncCommand */
#define CAN_SID_TT_SET_EXT_CLOCK_SYNC_COMMAND     (0x3bU)
/** @brief API Service ID for Can_TTSetNTUAdjust */
#define CAN_SID_TT_SET_NT_UADJUST                 (0x3cU)
/** @brief API Service ID for Can_TTSetNextIsGap */
#define CAN_SID_TT_SET_NEXT_IS_GAP                (0x37U)
/** @brief API Service ID for Can_TTSetTimeCommand */
#define CAN_SID_TT_SET_TIME_COMMAND               (0x39U)
/** @brief API Service ID for Can_TTSetTimeMark */
#define CAN_SID_TT_SET_TIME_MARK                  (0x48U)
/** @brief API Service ID for Can_Write */
#define CAN_SID_WRITE                             (0x06U)
/** @brief API Service ID for EcuM_CheckWakeup */
#define ECU_M_CHECK_WAKEUP                        (0x42U)

/** @brief Additional API Service ID for Can_AbortControllerPendingMsg */
#define CAN_SID_ABORT_CONTROLLER_PENDING_MESSAGE  (0x5aU)
/** @} */

/* Report Runtime Error SID ,wait to check */
#define CAN_SID_DATALOST                          (0x4fU)

#if (CAN_DMA_USAGE == STD_ON)
#define CAN_DMA_DONE_ADDR    (volatile uint32 *)(DMA0_BASE_ADDR32 + DMA_DONE_OFFSET32)
#endif

/*==================================================================================================
*                                           LOCAL MACROS
==================================================================================================*/
#define CAN_ID_TYPE_FD_FRAME_MASK       (0x40000000U)
#define CAN_ID_TYPE_EXTENDED_FRAME_MASK (0x80000000U)
/*==================================================================================================
                                    START PRECOMPILE MACRO
                                  YTM32B1ME0x MCAL CAN MODULE
==================================================================================================*/
/**
 * @brief Check the Can Controller Id starts with 0 and continue without any gaps
 */
/* [Validation - START]Can Controller Id starts with 0 and continue without any gaps */

#define DEVELOPPING                               (STD_OFF)
#define PARA_CALIBRATE                            (STD_OFF)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
enum
{
    CAN_UNINIT,
    CAN_READY,
};

/** @brief FlexCAN message buffer CODE for Rx buffers*/
enum
{
    CAN_CSCODE_RX_INACTIVE = 0x0,                 /*!< MB is not active.*/
    CAN_CSCODE_RX_BUSY     = 0x1,                 /*!< FlexCAN is updating the contents of the MB.
                                                       The CPU must not access the MB. */
    CAN_CSCODE_RX_FULL     = 0x2,                 /*!< MB is full.*/
    CAN_CSCODE_RX_EMPTY    = 0x4,                 /*!< MB is active and empty.*/
    CAN_CSCODE_RX_OVERRUN  = 0x6,                 /*!< MB is overwritten into a full buffer.*/
    CAN_CSCODE_RX_RANSWER  = 0xA,                 /*!< A frame was configured to recognize a Remote Request Frame
                                                       and transmit a Response Frame in return.*/
    CAN_CSCODE_RX_NOT_USED = 0xF                  /*!< Not used*/
};

/** @brief FlexCAN message buffer CODE FOR Tx buffers*/
enum
{
    CAN_CSCODE_TX_INACTIVE = 0x08,                /*!< MB is not active.*/
    CAN_CSCODE_TX_ABORT    = 0x09,                /*!< MB is aborted.*/
    CAN_CSCODE_TX_DATA     = 0x0C,                /*!< MB is a TX Data Frame(MB RTR must be 0).*/
    CAN_CSCODE_TX_REMOTE   = 0x1C,                /*!< MB is a TX Remote Request Frame (MB RTR must be 1).*/
    CAN_CSCODE_TX_TANSWER  = 0x0E,                /*!< MB is a TX Response Request Frame from.
                                                       an incoming Remote Request Frame. */
    CAN_CSCODE_TX_NOT_USED = 0xF                  /*!< Not used*/
};

typedef enum
{
    CAN_HW_OBJ_IDLE,
    CAN_HW_OBJ_BUSY,
} Can_HwObjStateType;


typedef enum
{
    CAN_MASK_TYPE_INDIVIDUAL = 0,
    CAN_MASK_TYPE_GLOBAL     = 1,
} Can_MaskType;

typedef enum
{
    STANDARD = 0,
    EXTENDED = 1,
    MIXED    = 2,
} Can_MsgIdType;

typedef enum
{
    CAN_RECEIVE  = 0,
    CAN_TRANSMIT = 1,
} Can_ObjectType;

typedef enum
{
    CAN_PROCESS_INTERRUPT = 0,
    CAN_PROCESS_POLLING   = 1,
    CAN_PROCESS_MIXED     = 2,
} Can_ProcessType;

typedef enum
{
    CAN_INTERRUPT = 0,
    CAN_POLLING   = 1,
} Can_FrameProcessType;

/**
 * @brief CAN clock source define
 */
typedef enum
{
    CAN_CLOCK_SOURCE_OSC = 0U,
    CAN_CLOCK_SOURCE_PE  = 1U,
} Can_ControllerClockRefType;

/**
 * @brief FlexCAN payload sizes
 */
typedef enum
{
    CAN_PLSIZE_8_BYTES  = 0U,
    CAN_PLSIZE_16_BYTES = 1U,
    CAN_PLSIZE_32_BYTES = 2U,
    CAN_PLSIZE_64_BYTES = 3U,
} Can_PayloadSizeType;

typedef enum
{
    CAN_RAM_REGION_0    = 0U,
    CAN_RAM_REGION_1    = 1U,
    CAN_RAM_REGION_2    = 2U,
    CAN_RAM_REGION_3    = 3U,
    CAN_RX_FIFO_LEGACY  = 250U,
    CAN_RX_FIFO_ENHANCE = 251U,
    CAN_RX_FIFO_NONE    = 255U
} Can_HwObjRegionType;

/**
 * @brief ID Acceptance Mode: Identifies the format of the Rx FIFO ID Filter Table elements
 */
typedef enum
{
    CAN_ENHANCE_RX_FIFO_FILTER_SCHEME_MASK_FILTER,
    CAN_ENHANCE_RX_FIFO_FILTER_SCHEME_RANGE_FILTER,
    CAN_ENHANCE_RX_FIFO_FILTER_SCHEME_TWO_FILTER,
} Can_EnhanceRxFifoFilterSchemeType;

typedef enum
{
    /**< One full ID (standard and extended) per ID Filter Table element.*/
    CAN_LEGACY_RX_FIFO_FILTER_FORMAT_A = 0U,
    /**< Two full standard IDs or two partial 14-bit (standard and extended) IDs per ID Filter Table
         element. */
    CAN_LEGACY_RX_FIFO_FILTER_FORMAT_B = 1U,
    /**< Four partial 8-bit Standard IDs per ID Filter Table element.*/
    CAN_LEGACY_RX_FIFO_FILTER_FORMAT_C = 2U,
    /**< All frames rejected.*/
    CAN_LEGACY_RX_FIFO_FILTER_FORMAT_D = 3U
} Can_LegacyRxFifoIdmFltType;

typedef enum
{
    CAN_FILTER_FORMAT_ACC_MASK_MODE = 0U,
    CAN_FILTER_FORMAT_ACC_RANG_MODE = 1U,
    CAN_FILTER_FORMAT_ACC_ACC_MODE  = 2U
} Can_EnhanceRxFifoFltType;

/*! @brief FlexCAN Rx FIFO filters number
 * Implements : flexcan_rx_fifo_id_filter_num_t_Class
 */
typedef enum
{
    /**<   8 Rx FIFO Filters. @internal gui name="8 Rx FIFO Filters" */
    CAN_RX_FIFO_ID_FILTERS_NUM_8 = 0x0,
    /**<  16 Rx FIFO Filters. @internal gui name="16 Rx FIFO Filters" */
    CAN_RX_FIFO_ID_FILTERS_NUM_16 = 0x1,
    /**<  24 Rx FIFO Filters. @internal gui name="24 Rx FIFO Filters" */
    CAN_RX_FIFO_ID_FILTERS_NUM_24 = 0x2,
    /**<  32 Rx FIFO Filters. @internal gui name="32 Rx FIFO Filters" */
    CAN_RX_FIFO_ID_FILTERS_NUM_32 = 0x3,
    /**<  40 Rx FIFO Filters. @internal gui name="40 Rx FIFO Filters" */
    CAN_RX_FIFO_ID_FILTERS_NUM_40 = 0x4,
    /**<  48 Rx FIFO Filters. @internal gui name="48 Rx FIFO Filters" */
    CAN_RX_FIFO_ID_FILTERS_NUM_48 = 0x5,
    /**<  56 Rx FIFO Filters. @internal gui name="56 Rx FIFO Filters" */
    CAN_RX_FIFO_ID_FILTERS_NUM_56 = 0x6,
    /**<  64 Rx FIFO Filters. @internal gui name="64 Rx FIFO Filters" */
    CAN_RX_FIFO_ID_FILTERS_NUM_64 = 0x7,
    /**<  72 Rx FIFO Filters. @internal gui name="72 Rx FIFO Filters" */
    CAN_RX_FIFO_ID_FILTERS_NUM_72 = 0x8,
    /**<  80 Rx FIFO Filters. @internal gui name="80 Rx FIFO Filters" */
    CAN_RX_FIFO_ID_FILTERS_NUM_80 = 0x9,
    /**<  88 Rx FIFO Filters. @internal gui name="88 Rx FIFO Filters" */
    CAN_RX_FIFO_ID_FILTERS_NUM_88 = 0xA,
    /**<  96 Rx FIFO Filters. @internal gui name="96 Rx FIFO Filters" */
    CAN_RX_FIFO_ID_FILTERS_NUM_96 = 0xB,
    /**< 104 Rx FIFO Filters. @internal gui name="104 Rx FIFO Filters" */
    CAN_RX_FIFO_ID_FILTERS_NUM_104 = 0xC,
    /**< 112 Rx FIFO Filters. @internal gui name="112 Rx FIFO Filters" */
    CAN_RX_FIFO_ID_FILTERS_NUM_112 = 0xD,
    /**< 120 Rx FIFO Filters. @internal gui name="120 Rx FIFO Filters" */
    CAN_RX_FIFO_ID_FILTERS_NUM_120 = 0xE,
    /**< 128 Rx FIFO Filters. @internal gui name="128 Rx FIFO Filters" */
    CAN_RX_FIFO_ID_FILTERS_NUM_128 = 0xF
} Can_RxFifoIdFilterNumType;

#if (CAN_ICOM_USAGE == STD_ON)
/**
 * @brief FlexCAN payload sizes
 */
typedef enum
{
    CAN_ICOM_FCS_FILTER_ONLY                        = 0U,
    CAN_ICOM_FCS_FILTER_AND_PAYLOAD                 = 1U,
    CAN_ICOM_FCS_FILTER_SPECIFY_NUMBERS             = 2U,
    CAN_ICOM_FCS_FILTER_AND_PAYLOAD_SPECIFY_NUMBERS = 3U,
} Can_IcomFCSType;

typedef enum
{
    CAN_ICOM_IDFS_ID_EXACT            = 0U,
    CAN_ICOM_IDFS_ID_EQUAL_OR_GREATER = 1U,
    CAN_ICOM_IDFS_ID_EQUAL_OR_SMALLER = 2U,
    CAN_ICOM_IDFS_ID_RANGE            = 3U,
} Can_IcomIDFSType;

typedef enum
{
    CAN_ICOM_PLFS_PAYLOAD_EXACT            = 0U,
    CAN_ICOM_PLFS_PAYLOAD_EQUAL_OR_GREATER = 1U,
    CAN_ICOM_PLFS_PAYLOAD_EQUAL_OR_SMALLER = 2U,
    CAN_ICOM_PLFS_PAYLOAD_RANGE            = 3U,
} Can_IcomPLFSType;

typedef enum
{
    CAN_ICOM_REJECT_REMOTE_FRAME = 0U,
    CAN_ICOM_ACCEPT_REMOTE_FRAME = 1U,
} Can_IcomFltRTRType;
#endif

typedef enum
{
    CAN_HANDLE_BASIC = 0U,
    CAN_HANDLE_FULL  = 1U,
} Can_HandleType;

typedef enum
{
    CAN_OSCILLATOR_CLOCK = 0U,
    CAN_PERIPHERAL_CLOCK = 1U,
} Can_PeClockSrcType;

typedef enum
{
    CAN_ERROR_STFERR      = 0U,
    CAN_ERROR_FRMERR      = 1U,
    CAN_ERROR_CRCERR      = 2U,
    CAN_ERROR_ACKERR      = 3U,
    CAN_ERROR_BIT0ERR     = 4U,
    CAN_ERROR_BIT1ERR     = 5U,
    CAN_ERROR_OVERRUN     = 8U,
    CAN_ERROR_DMA_RECEIVE = 9U,
} Can_ErrorType;

typedef enum
{
    CAN_ERROR_STFERR_FAST  = 0U,
    CAN_ERROR_FRMERR_FAST  = 1U,
    CAN_ERROR_CRCERR_FAST  = 2U,
    CAN_ERROR_BIT0ERR_FAST = 4U,
    CAN_ERROR_BIT1ERR_FAST = 5U
} Can_ErrorFastType;

typedef enum
{
    CAN_RX_ERROR_COUNTER_OVER_96  = 0U,
    CAN_TX_ERROR_COUNTER_OVER_96  = 1U,
    CAN_BUSOFF_DONE               = 2U,
    CAN_ENHANCE_RX_FIFO_UNDERFLOW = 3U,
} Can_WarningType;

typedef enum
{
    CAN_ERROR_NCE_HOST        = 0U,
    CAN_ERROR_NCE_FLEXCAN     = 1U,
    CAN_ERROR_NCE_HOST_OVF    = 2U,
    CAN_ERROR_NCE_FLEXCAN_OVF = 3U,
} Can_NceType;

typedef enum
{
    CAN_ERROR_CE     = 0U,
    CAN_ERROR_CE_OVF = 1U,
} Can_CeType;

/*==================================================================================================
*                                      CALLBACK TYPE
==================================================================================================*/
#if ((CAN_LEGACY_FIFO_USAGE == STD_ON) || (CAN_ENHANCE_FIFO_USAGE == STD_ON))
#if (CAN_FIFO_IDHIT_USAGE == STD_ON)
typedef void (*Can_CallbackPtrOfIdhitType)(uint8 ChnLogicId, uint16 *TmpPtr);
#endif
typedef void (*Can_CallbackPtrOfFifoFullType)(void);
typedef void (*Can_CallbackPtrOfFifoOvfType)(void);
#endif
typedef void (*Can_CallbackPtrOfErrType)(Can_ErrorType CanErrEnum);
typedef void (*Can_CallbackPtrOfErrFastType)(Can_ErrorFastType CanErrFastEnum);
typedef void (*Can_CallbackPtrOfErrNceType)(Can_NceType CanNceEnum);
typedef void (*Can_CallbackPtrOfErrCeType)(Can_CeType CanCeEnum);
typedef void (*Can_CallbackPtrOfOverrunType)(Can_HwHandleType Hrh);
typedef void (*Can_CallbackPtrOfBusoffType)(void);
typedef void (*Can_CallbackPtrOfWarningType)(Can_WarningType CanWarningEnum);
#if (CAN_WAKEUP_SUPPORT == STD_ON)
typedef void (*Can_CallbackPtrOfWakeupType)(void);
#endif
#if (CAN_ICOM_USAGE == STD_ON)
typedef void (*Can_CallbackPtrOfIcomType)(const Can_HwType *Mailbox, const PduInfoType *PduInfoPtr, boolean isSoftwareIcom);
#endif
typedef boolean (*Can_CallbackPtrOfReceiveType)(uint8 Hrh, Can_IdType CanId, uint8 CanDataLegth, const uint8* CanSduPtr);
typedef void (*Can_CallbackPtrOfTransmitType)(PduIdType TxPduId);

/*==================================================================================================
*                                      GLOBAL TYPEDEFS
==================================================================================================*/
typedef struct
{
    uint32 FilterCode;                            /*!< The Can receive filter of extended or standard frame for Can message buffer */
    uint32 MaskCode;                              /*!< The Can receive filter mask of extended or standard frame for Can message buffer */
} Can_FilterOfMbType;

#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)
typedef struct
{
    uint32 FilterCodeExt1;                                    /*!< The Can receive filter of extended frame for enhance rx FIFO */
    uint32 FilterCodeExt2;                                    /*!< The Can receive filter mask of extended frame for enhance rx FIFO */
    Can_EnhanceRxFifoFltType EnhanceRxFifoFilterFormat;       /*!< filter format of enhance rx fifo */
} Can_FilterOfExtFifoType;

typedef struct
{
    uint16 FilterCodeStd1;                                    /*!< The Can receive filter of standard frame for enhance rx FIFO */
    uint16 FilterCodeStd2;                                    /*!< The Can receive filter mask of standard frame for enhance rx FIFO */
    Can_EnhanceRxFifoFltType EnhanceRxFifoFilterFormat;       /*!< filter format of enhance rx fifo */
} Can_FilterOfStdFifoType;

typedef struct
{
    uint8 EnhanceRxFifoWatermarkNum;                          /*!< The watermark of enhance rx fifo enabled when enhance rx fifo usage*/
    uint8 ExtRxFifoFilterNum;                                 /*!< The Count of the extended filter quantity of enhance rx fifo */
    uint8 StdRxFifoFilterNum;                                 /*!< The Count of the standard filter quantity of enhance rx fifo */
    const Can_FilterOfExtFifoType *ExtRxFifoFltConfigPtr;     /*!< Point the extended filters and masks for enhance rx fifo */
    const Can_FilterOfStdFifoType *StdRxFifoFltConfigPtr;     /*!< Point the standard filters and masks for enhance rx fifo */
} Can_EnhanceRxFifoConfigType;
#endif/*#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)*/

#if (CAN_LEGACY_FIFO_USAGE == STD_ON)
typedef struct
{
    Can_MsgIdType MsgIdType;                                  /*!< The receive frame is standard, extended or mixed */
    uint32 FilterCode;                                        /*!< The Can receive filter of extended or standard frame for legacy rx FIFO */
    uint32 MaskCode;                                          /*!< The Can receive filter mask of extended or standard frame for legacy rx FIFO */
} Can_IdvMaskFilterConfigType;

typedef struct
{
    Can_MsgIdType MsgIdType;                                  /*!< The receive frame is standard, extended or mixed*/
    uint32 GlobalMaskCode;                                    /*!< The Can receive filter mask of extended or standard frame for legacy rx FIFO */
    const uint32 *FilterCodePtr;                              /*!< The Can receive filter of extended or standard frame for legacy rx FIFO */
} Can_GlbMaskFilterConfigType;

typedef struct
{
    Can_LegacyRxFifoIdmFltType LegacyRxFifoFilterFormat;            /*!< filter format of legacy rx fifo */
    uint16 LegacyRxFifoFilterTotalNum;                              /*!< The Count of the total filter quantity of legacy rx fifo */
    uint8 LegacyRxFifoOccupyMailboxNum;                             /*!< Indicate how many message buffers have been Occupied by legacy rx fifo when legacy usage*/
    uint16 FilterNumWithIndividualMask;                             /*!< Indicate the count of the filter quantity of rx fifo with individual mask */
    uint16 FilterNumWithGlobalMask;                                 /*!< Indicate the count of the filter quantity of rx fifo with global mask */
    const Can_IdvMaskFilterConfigType *IndividualMaskFltConfigPtr;  /*!< Point the filters which with individual masks for legacy rx fifo */
    const Can_GlbMaskFilterConfigType *GlobalMaskFltConfigPtr;      /*!< Point the filters which with Global masks for legacy rx fifo */
} Can_LegacyRxFifoConfigType;
#endif/*#if (CAN_LEGACY_FIFO_USAGE == STD_ON)*/

typedef struct
{
    Can_PayloadSizeType MbPlSizeType;                               /*!< The payload size mode of message buffer */
    uint8 MbMsgBufferNum;                                           /*!< Indicate how many message buffers in this ram region*/
    PduLengthType PayloadSize;                                      /*!< Indicate how many bytes there are per message buffer in this ram region*/
    uint8 PayloadRamLength;                                         /*!< Indicate how many bytes have been occupied by every message buffer in this ram region*/
} Can_MbRegionConfigType;

typedef struct
{
    Can_HwObjRegionType MbRegionNum;                                /*!< Indicate how many ram regions there are in this can channel */
    uint8 ChPayloadMaxNum;                                          /*!< Indicate how many message buffers there are in this can channel*/
    Can_HwObjRegionType RxFifoType;                                 /*!< The rx FIFO mode enum */
    const Can_MbRegionConfigType *MbRegionConfig;                   /*!< Point the ram region config */
#if (CAN_ENHANCE_FIFO_USAGE == STD_ON)
    const Can_EnhanceRxFifoConfigType *EnhanceRxFifoConfigPtr;      /*!< Point the rx fifo config */
#endif
#if (CAN_LEGACY_FIFO_USAGE == STD_ON)
    const Can_LegacyRxFifoConfigType *LegacyRxFifoConfigPtr;        /*!< Point the rx fifo config */
#endif
} Can_PayloadConfigType;

#if (CAN_FD_USAGE == STD_ON)
typedef struct
{
    uint16 CanFdBaudrate;       /*!< CanFD baudrate in this baudrate group */
    boolean CanFdTxBdrSwitch;   /*!< CanFD Tx baudrate switch in this baudrate group*/
    uint8 CanFdPreDiv;          /*!< CanFD preDivision in this baudrate group */
    uint8 CanFdPropSeg;         /*!< CanFD baudrate propsegment length in this baudrate group */
    uint8 CanFdSeg1;            /*!< CanFD baudrate segment1 length in this baudrate group */
    uint8 CanFdSeg2;            /*!< CanFD baudrate segment2 length in this baudrate group */
    uint8 CanFdSyncJumpWidth;   /*!< CanFD baudrate sync jump width in this baudrate group */
    uint8 CanFdTdcOffset;       /*!< CanFD baudrate time delay compensation in this baudrate group, suggest to equal to (propsegment + segment1) */
} CAN_FdBdrConfigType;
#endif

/**
 * @brief CAN bandrate config type
 */
typedef struct
{
    uint16 CanBaudrateConfigID; /*!< Can baudrate phase ID of this baudrate group */
    uint16 CanBaudrate;         /*!< Can baudrate in this baudrate group */
    uint8 CanPreDiv;            /*!< Can preDivision in this baudrate group */
    uint8 CanPropSeg;           /*!< Can baudrate propsegment length in this baudrate group */
    uint8 CanSeg1;              /*!< Can baudrate segment1 length in this baudrate group */
    uint8 CanSeg2;              /*!< Can baudrate segment2 length in this baudrate group */
    uint8 CanSyncJumpWidth;     /*!< Can baudrate sync jump width in this baudrate group */
#if (CAN_FD_USAGE == STD_ON)
    const CAN_FdBdrConfigType *CanFdBdrConfig;  /*!< Point the CanFD baudrate config */
#endif
} Can_BdrConfigType;


/**
 * @brief This struct is used to covert a hardware flag id to logic hoh id and mailbox id and region id.
 */
typedef struct
{
    uint8 CanHwObjId;                   /*!< Logic id in a region */
    Can_HwObjRegionType CanHwRegionId;  /*!< Logic region id */
    Can_HwHandleType CanHohId;          /*!< The handle ID corresponding to this message buffer hardware object ID*/
} Can_MbFlagMatrixType;

#if ((CAN_RX_PROCESS_HAS_POLLING == STD_ON) || (CAN_TX_PROCESS_HAS_POLLING == STD_ON))
typedef struct
{
    Can_HwHandleType CanHohId;          /*!< The hoh ID */
    volatile uint32 *CanDiagAddr0;      /*!< Flag bit quick address query 0 */
    uint32 CanDiagMask0;                /*!< Flag bit quick mask query 0 */
    volatile uint32 *CanDiagAddr1;      /*!< Flag bit quick address query 1 */
    uint32 CanDiagMask1;                /*!< Flag bit quick mask query 1 */
} Can_HohPolTableType;

typedef struct
{
    uint8 CanPeriodId;                         /*!< The polling period ID */
    Can_HwHandleType CanHohNum;                /*!< Indicates the number of handles that need to be queried corresponding to this cycle ID */
    const Can_HohPolTableType *CanPolTablePtr; /*!< Point to the direct query table corresponding to this handle */
} Can_HohPolPeriodType;
#endif


#if (CAN_ICOM_USAGE == STD_ON)
typedef struct
{
    uint8 IcomObjectId;              /*!< The Icom object ID */
} Can_IcomConfigType;
#endif

typedef struct
{
    Can_HwHandleType CanObjId;                /*!< HOH ID */
    uint8 CanHwObjNum;                  /*!< The count of message buffer quantity have occupied by the HOH */
    uint8 CanChannelId;                /*!< The Can channel of this HOH handled */
    Can_HwObjRegionType CanHwObjRegionId;      /*!< The hardware object Region occupied by the HOH in corresponding Can channel*/
    Can_ObjectType ObjectType;              /*!< HRH or HTR */
#if (DEVELOPPING == STD_ON)
    Can_HandleType BasicFullType;           /*!< BASIC or FULL */
    boolean TrigTransEnable;              /*!< Whether to use trigger transmitting of this HTH handled */
#endif
#if ((CAN_RX_PROCESS_HAS_POLLING == STD_ON) || (CAN_TX_PROCESS_HAS_POLLING == STD_ON))
    boolean UsePolling;                  /*!< Whether to use polling of this HOH handled */
    uint8 PollingPeriodId;              /*!< The polling period ID of this HOH handled */
#endif
#if (CAN_FD_USAGE == STD_ON)
    uint8 CanFdPaddingValue;            /*!< The Can FD padding value of this HOH handled */
#endif
    Can_MsgIdType MsgIdType;                /*!< The receive frame is standard, extended, or mixed*/
    const Can_FilterOfMbType *FilterConfig;   /*!< Point the filter mask config of this HRH without rx FIFO*/
    uint8 CanHwObjStartId;              /*!< The message buffer start ID of this HOH handled */
    uint8 CanHwFlagStartId;              /*!< The message buffer Interrupt Flag start ID of this HOH handled */
} Can_HohConfigType;

typedef struct
{
#if ((CAN_LEGACY_FIFO_USAGE == STD_ON) || (CAN_ENHANCE_FIFO_USAGE == STD_ON))
    Can_CallbackPtrOfFifoFullType ReceiveFifoFullCallback;       /*!< The callback function of Can receive full */
    Can_CallbackPtrOfFifoOvfType ReceiveFifoOverflowCallback;    /*!< The callback function of Can receive overflow */
#endif
    Can_CallbackPtrOfOverrunType OverrunCallback;                /*!< The callback function of Can overrun */
    Can_CallbackPtrOfWarningType WarningCallback;                /*!< The callback function of Can warning */
    Can_CallbackPtrOfBusoffType BusoffCallback;                  /*!< The callback function of Can busoff */
    Can_CallbackPtrOfErrType ErrorCallback;                      /*!< The callback function of Can error */
    Can_CallbackPtrOfErrFastType ErrFastCallback;                /*!< The callback function of Can error fast */
    Can_CallbackPtrOfErrNceType ErrNceCallback;                  /*!< The callback function of Can ECC Non-Correctable Errors*/
    Can_CallbackPtrOfErrCeType ErrCeCallback;                    /*!< The callback function of Can ECC Correctable Errors*/
#if (CAN_WAKEUP_SUPPORT == STD_ON)
    Can_CallbackPtrOfWakeupType WakeupCallback;                  /*!< The callback function of Can wakeup */
#endif
#if (CAN_ICOM_USAGE == STD_ON)
    Can_CallbackPtrOfIcomType IcomCallback;                      /*!< The callback function of Can Icom */
#endif
} Can_CallbackEntranceType;

typedef struct
{
    uint8 CanChannelId;                              /*!< The Can channel ID */
    uint8 CanHwChId;                                 /*!< The Can hardware channel ID */
    boolean CanChActivation;                         /*!< Whether Can channel activate */
    uint32 ChBaseAddr;                               /*!< The Can hardware channel base address */
    boolean CanTrippleSamp;                          /*!< Whether Can Tripple Sampling usage */
    boolean CanAutoBusoffRecovery;                   /*!< Whether Can Auto Busoff Recovery usage */
    boolean CanLoopBackEnable;                       /*!< Whether Can Loop Back mode be enabled */
    Can_ProcessType CanTxProcessing;                 /*!< Interrupt, Polling or Mixed Mode of Can transmit processing mode*/
    Can_ProcessType CanRxProcessing;                 /*!< Interrupt, Polling or Mixed Mode of Can recive processing mode*/
    Can_ProcessType CanBusoffProcessing;             /*!< Interrupt, Polling or Mixed Mode of Can busoff processing mode*/
#if (CAN_WAKEUP_SUPPORT == STD_ON)
    Can_ProcessType CanWakeupProcessing;             /*!< Interrupt, Polling or Mixed Mode of Can wakeup processing mode*/
    boolean CanWakeupSupport;                        /*!< Whether Can Wakeup support usage */
    EcuM_WakeupSourceType EcuMWakeupSource;          /*!< The EcuM wakeup source of this Can channel */
#endif
#if (CAN_WAKEUP_FUNCTIONALITY_API == STD_ON)
    boolean CanWakeupFunctionalityAPI;               /*!< Whether Can Wakeup Functionality API support usage */
#endif
#if (CAN_FD_USAGE == STD_ON)
    boolean FdUsage;                                 /*!< Whether Can FD usage */
    boolean IsoModeUsage;                            /*!< Whether Can FD ISO MODE usage */
#endif
#if (CAN_DMA_USAGE == STD_ON)
    boolean CanDmaUsage;                             /*!< Whether to use DMA of this Can channel */
    CddDma_ChannelType CanDmaChannel;                /*!< The Can DMA channel of this Can channel */
#endif
    Can_ControllerClockRefType CanTimeQuantaSource;  /*!< The Can baudrate time quanta clock source */
    uint16 ChBaudrateNum;                            /*!< The Count of the baudrate group quantity of this Can channel */
    const Can_BdrConfigType *DefaultBdrConfig;       /*!< Point the default baudrate config */
    const Can_BdrConfigType *BdrConfigPtr;           /*!< Point the baudrate config */
    const Can_PayloadConfigType *PayloadConfigPtr;   /*!< Point the payload config */
    const Can_CallbackEntranceType *CanCallbackPtr;  /*!< The Can callback entrance */
    Can_HwHandleType   CanFifoHrhId;
    const Can_MbFlagMatrixType *CanHwFlagMatrixPtr;  /*!< Point the Can Message buffer to hoh Correspondence Table */
    uint32 RamMbNum;                                 /*!< The Count of the message buffer quantity of this Can channel for init ram*/
    boolean RamIrmqEn;                               /*!< Whether to use Individual Rx Masking and Queue Enable of this Can channel for init ram*/
#if (CAN_MEMECC_FEATURE == STD_ON)
    boolean RamHrTimeStmpEn;                         /*!< Whether to use HR time stamp of this Can channel for init ram*/
    boolean RamEnhMbMemEn;                           /*!< Whether to use Enhanced Message Buffers of this Can channel for init ram*/
    boolean RamEnhFifoEn;                            /*!< Whether to use Enhanced Rx FIFO of this Can channel for init ram*/
#endif
} Can_ChannelConfigType;

typedef struct
{
    uint8 CanChannelNum;                               /*!< The Count of the Can channel quantity of whole Can module */
    const Can_ChannelConfigType *CanChCfgPtr;          /*!< Point the Can channel config */
    Can_HwHandleType CanHohNum;                        /*!< The Count of the HOH quantity of whole Can module */
    const Can_HohConfigType *CanHohCfgPtr;             /*!< Point the Can HOH config */
    const uint8 *CanHwIdTable;                         /*!< Point the Can hardware object ID */
#if ((CAN_RX_PROCESS_HAS_POLLING == STD_ON) && (CAN_TX_PROCESS_HAS_POLLING == STD_ON))
    uint8 CanPolPeriodNum;                             /*!< The Count of the polling period quantity of whole Can module */
#endif
#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
    const Can_HohPolPeriodType *CanHrhPolPeriodPtr;    /*!< Point the Can Hrh polling table */
#endif
#if (CAN_TX_PROCESS_HAS_POLLING == STD_ON)
    const Can_HohPolPeriodType *CanHthPolPeriodPtr;    /*!< Point the Can hth polling table */
#endif
    Can_CallbackPtrOfReceiveType CanReceiveCallback;   /*!< Point the Can receive callback */
    Can_CallbackPtrOfTransmitType CanTransmitCallback; /*!< Point the Can transmit callback */
#if ((CAN_ENHANCE_FIFO_USAGE == STD_ON) || (CAN_LEGACY_FIFO_USAGE == STD_ON))
#if (CAN_FIFO_IDHIT_USAGE == STD_ON)
    Can_CallbackPtrOfIdhitType CanIdhitCallback;       /*!< Point the Can ID hit callback */
#endif
#endif
#if (CAN_ICOM_USAGE == STD_ON)
    uint8 CanIcomNum;                                  /*!< The Count of the Icom channel quantity of whole Can module */
    const Can_IcomConfigType   *CanIcomCfgPtr;         /*!< Point the Icom config */
#endif
} Can_ConfigType;

#ifdef __cplusplus
}
#endif

#endif /* CAN_TYPES_H */
/** @} */
