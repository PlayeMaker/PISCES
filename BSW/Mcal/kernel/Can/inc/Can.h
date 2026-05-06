/*
 *   @file    Can.h
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

#ifndef CAN_H
#define CAN_H

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
 * @file     Can.h
 */
#define CAN_VENDOR_ID                      (180)
#define CAN_AR_RELEASE_MAJOR_VERSION       (4)
#define CAN_AR_RELEASE_MINOR_VERSION       (4)
#define CAN_AR_RELEASE_REVISION_VERSION    (0)
#define CAN_SW_MAJOR_VERSION               (0)
#define CAN_SW_MINOR_VERSION               (9)
#define CAN_SW_PATCH_VERSION               (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/**
 * @file     Can_Types.h
 */
/* Check if source file and CAN configuration header file are of the same vendor */
#if (CAN_VENDOR_ID != CAN_TYPES_VENDOR_ID)
#error "Can.h and Can_Types.h have different vendor ids"
#endif

/* Check if source file and CAN configuration header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION != CAN_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_AR_RELEASE_MINOR_VERSION != CAN_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CAN_AR_RELEASE_REVISION_VERSION != CAN_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Can.h and Can_Types.h are different"
#endif

/* Check if source file and CAN configuration header file are of the same software version */
#if ((CAN_SW_MAJOR_VERSION != CAN_TYPES_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION != CAN_TYPES_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION != CAN_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Can.h and Can_Types.h are different"
#endif

/*==================================================================================================
*                                       EXTERNAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
                                         GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief           This function initializes the CAN module.
 * @param[in]       Config Pointer to driver configuration.
 * @return          void
 */
void Can_Init(const Can_ConfigType *Config);

#if (CAN_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
 * @brief           This function checks if a wakeup has occurred for the given controller.
 * @param[in]       ChnLogicId Controller to be checked for a wakeup.
 * @return          Std_ReturnType
 * @retval          E_OK API call has been accepted.
 * @retval          E_NOT_OK API call has not been accepted.
 */
Std_ReturnType Can_CheckWakeup (uint8 ChnLogicId);
#endif

#if (CAN_API_DEINIT_ENABLE == STD_ON)
/**
 * @brief            This function de-initializes the module.
 * @return           void
 */
void Can_DeInit (void);
#endif

#if (CAN_API_DISABLE_CONTROLLER_INTERRUPTS == STD_ON)
/**
 * @brief            This function disables all interrupts for this CAN controller.
 * @param[in]        Controller CAN controller for which interrupts shall be disabled.
 * @return           void
 */
void Can_DisableControllerInterrupts(uint8 Controller);
#endif

#if (CAN_API_ENABLE_CONTROLLER_INTERRUPTS == STD_ON)
/**
 * @brief            This function enables all allowed interrupts.
 * @param[in]        Controller CAN controller for which interrupts shall be re-enabled
 * @return           void
 */
void Can_EnableControllerInterrupts(uint8 Controller);
#endif

#if (CAN_API_GET_CONTROLLER_ERROR_STATE == STD_ON)
/**
 * @brief           This service obtains the error state of the CAN controller.
 * @param[in]       ControllerId Abstracted CanIf ControllerId which is assigned to a CAN controller,
 *     which is requested for ErrorState.
 * @param[out]      ErrorStatePtr Pointer to a memory location, where the error state of
 *      the CAN controller will be stored.
 * @return          Std_ReturnType
 * @retval    E_OK    The error state was successfully read.
 * @retval    E_NOT_OK The error state was not successfully read.
 */
Std_ReturnType Can_GetControllerErrorState(uint8 ControllerId, Can_ErrorStateType * ErrorStatePtr);
#endif

#if (CAN_API_GET_CONTROLLER_MODE == STD_ON)
/**
 * @brief        This service reports about the current status of the requested CAN controller.
 * @param[in]     Controller CAN controller for which the status shall be requested.
 * @param[out]      ControllerModePtr Pointer to a memory location, where the current
 *               mode of the CAN controller will be stored.
 * @return          Std_ReturnType
 * @retval    E_OK    The mode was successfully read.
 * @retval    E_NOT_OK The mode was not successfully read.
 */
Std_ReturnType Can_GetControllerMode (uint8 Controller, Can_ControllerStateType * ControllerModePtr);
#endif

#if (CAN_API_GET_CONTROLLER_RX_ERROR_COUNTER == STD_ON)
/**
 * @brief   Returns the Rx error counter for a CAN controller. This value might not be available for all CAN controllers, in which case E_NOT_OK would be returned.
 * @param[in]  ControllerId CAN controller, whose current Rx error counter shall be acquired.
 * @param[out]  RxErrorCounterPtr Pointer to a memory location, where the current Rx error counter of the CAN controller will be stored.
 * @return   Std_ReturnType
 * @retval    E_OK    The Rx error counter was successfully read.
 * @retval    E_NOT_OK The Rx error counter was not successfully read.
 */
Std_ReturnType Can_GetControllerRxErrorCounter (uint8 ControllerId, uint8 * RxErrorCounterPtr);
#endif

#if (CAN_API_GET_CONTROLLER_TX_ERROR_COUNTER == STD_ON)
/**
 * @brief        Returns the Tx error counter for a CAN controller. This value might not be
 *     available for all CAN controllers, in which case E_NOT_OK would be returned.
 * @param[in]       ControllerId CAN controller, whose current Tx error counter shall be acquired.
 * @param[out]      TxErrorCounterPtr Pointer to a memory location, where the current Tx error counter of
 *     the CAN controller will be stored.
 * @return          Std_ReturnType
 * @retval    E_OK    The Tx error counter was successfully read.
 * @retval    E_NOT_OK The Tx error counter was not successfully read.
 */
Std_ReturnType Can_GetControllerTxErrorCounter (uint8 ControllerId, uint8 * TxErrorCounterPtr);
#endif

#if (CAN_BUSOFF_PROCESS_HAS_POLLING == STD_ON)
/**
 * @brief        This function performs the polling of bus-off events that are configured
 *     statically as 'to be polled'.
 * @return         void
 */
void Can_MainFunction_BusOff (void);
#endif

/**
 * @brief        The function Can_MainFunction_Mode shall implement the polling of CAN status
 *     register flags to detect transition of CAN Controller state.
 *     Trace : SWS_Can_00369
 * @details      The function Can_Mainfunction_Mode shall poll a flag of the CAN status
 *     register until the flag signals that the change takes effect and notify
 *     the upper layer with function CanIf_ControllerModeIndication about a
 *     successful state transition referring to the corresponding CAN controller
 *     with the abstract CanIf ControllerId.
 *     Trace : SWS_Can_00492
 * @return          void
 */
void Can_MainFunction_Mode (void);

#if (CAN_API_MAINFUNCTION_WAKEUP == STD_ON)
/**
 * @brief           This function performs the polling of wake-up events that are configured
 *     statically as 'to be polled'.
 * @return          void
 */
void Can_MainFunction_Wakeup (void);
#endif

#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM == 1U)
/**
 * @brief          This function performs the polling of RX indications when CAN_RX_PROCESSING
 *     is set to POLLING.
 * @return          void
 */
void Can_MainFunction_Read (void);
#elif(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 1U)
void Can_MainFunction_Read_Period_0(void);
void Can_MainFunction_Read_Period_1(void);
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 2U)
void Can_MainFunction_Read_Period_2(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 3U)
void Can_MainFunction_Read_Period_3(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 4U)
void Can_MainFunction_Read_Period_4(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 5U)
void Can_MainFunction_Read_Period_5(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 6U)
void Can_MainFunction_Read_Period_6(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 7U)
void Can_MainFunction_Read_Period_7(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 8U)
void Can_MainFunction_Read_Period_8(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 9U)
void Can_MainFunction_Read_Period_9(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 10U)
void Can_MainFunction_Read_Period_10(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 11U)
void Can_MainFunction_Read_Period_11(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 12U)
void Can_MainFunction_Read_Period_12(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 13U)
void Can_MainFunction_Read_Period_13(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 14U)
void Can_MainFunction_Read_Period_14(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 15U)
void Can_MainFunction_Read_Period_15(void);
#endif
#endif /* #if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM == 1U) */
#endif

#if (CAN_TX_PROCESS_HAS_POLLING == STD_ON)
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM == 1U)
/**
 * @brief           This function performs the polling of TX confirmation when CAN_TX_PROCESSING
 *     is set to POLLING.
 * @return          void
 */
void Can_MainFunction_Write (void);
#elif(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 1U)
void Can_MainFunction_Write_Period_0(void);
void Can_MainFunction_Write_Period_1(void);
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 2U)
void Can_MainFunction_Write_Period_2(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 3U)
void Can_MainFunction_Write_Period_3(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 4U)
void Can_MainFunction_Write_Period_4(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 5U)
void Can_MainFunction_Write_Period_5(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 6U)
void Can_MainFunction_Write_Period_6(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 7U)
void Can_MainFunction_Write_Period_7(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 8U)
void Can_MainFunction_Write_Period_8(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 9U)
void Can_MainFunction_Write_Period_9(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 10U)
void Can_MainFunction_Write_Period_10(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 11U)
void Can_MainFunction_Write_Period_11(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 12U)
void Can_MainFunction_Write_Period_12(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 13U)
void Can_MainFunction_Write_Period_13(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 14U)
void Can_MainFunction_Write_Period_14(void);
#endif
#if(CAN_MAIN_FUNCTION_RW_PERIOD_OPTION_NUM > 15U)
void Can_MainFunction_Write_Period_15(void);
#endif
#endif
#endif

#if (CAN_SET_BAUDRATE_API == STD_ON)
/**
 * @brief           This service shall set the baud rate configuration of the CAN controller.
      Depending on necessary baud rate modifications the controller might have
      to reset.
 * @param[in]       Controller CAN controller, whose baud rate shall be set
 * @param[in]       BaudrateConfigID references a baud rate configuration by ID
      (see CanControllerBaudrateConfigID)
 * @return          Std_ReturnType
 * @retval          E_OK baud rate configuration has been set
 * @retval          E_NOT_OK baud rate configuration has not been set
 */
Std_ReturnType Can_SetBaudrate(uint8 Controller, uint16 BaudrateConfigID);
#endif

/**
 * @brief           This function performs software triggered state transitions of the CAN
      controller State machine.
 * @param[in]       Controller CAN controller for which the status shall be changed
 * @param[in]       Transition Transition value to request new CAN controller state
 * @return          Std_ReturnType
 * @retval          E_OK The state transition was successfully performed.
 * @retval          E_NOT_OK The state transition was not successfully performed.
 */
Std_ReturnType Can_SetControllerMode(uint8 Controller, Can_ControllerStateType Transition);

#if (CAN_ICOM_USAGE == STD_ON)
/**
 * @brief          This service shall change the Icom Configuration of a CAN controller to the
      requested one.
 * @param[in]      Controller CAN controller for which the status shall be changed.
 * @param[in]      ConfigurationId Requested Configuration
 * @return         Std_ReturnType
 * @retval   E_OK    The Icom Configuration was successfully changed.
 * @retval   E_NOT_OK The Icom Configuration was not successfully changed.
 */
Std_ReturnType Can_SetIcomConfiguration (uint8 Controller, IcomConfigIdType ConfigurationId);
#endif

/**
 * @brief           This function is called by CanIf to pass a CAN message to CanLld_ for
 *     transmission.
 * @param[in]        Hth information which HW-transmit handle shall be used
 *     for transmit. Implicitly this is also the information about the controller
 *     to use because the Hth numbers are unique inside one hardware unit.
 * @param[in]        PduInfo Pointer to SDU user memory, Data Length and Identifier.
 * @return           Std_ReturnType
 * @retval           E_OK Write request has been accepted
 * @retval           E_NOT_OK Write request has not been accepted
 */
Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType *PduInfo);


#if (CAN_API_ABORT_CONTROLLER_PENDING_MESSAGE == STD_ON)
/**
 * @brief            This function aborts pending L-PDUs transmission.
 * @param[in]        Controller CAN controller channel Id.
 * @return           Std_ReturnType
 * @retval           E_OK Cancellation was executed successfully.
 * @retval           E_NOT_OK Cancellation was rejected.
 */
Std_ReturnType Can_AbortControllerPendingMsg(uint8 Controller);
#endif

/**
  * @brief       This service polling the hrhs whitch configured using this PeriodId
  * @param[in]   PeriodId CAN MainFunction read or write period Id
  * @return        void
  */
void Can_MainFunction_SpecificRead(uint8 PeriodId);

/**
  * @brief       This service polling the hths whitch configured using this PeriodId
  * @param[in]   PeriodId CAN MainFunction read or write period Id
  * @return        void
  */
void Can_MainFunction_SpecificWrite(uint8 PeriodId);

#if (((CAN_VERSION_INFO_API == STD_ON) && (CAN_DEV_ERROR_DETECT == STD_ON)))
/**
 * @brief            Returns the version information of this module.
 *
 * @param[in]        Std_VersionInfoType* versioninfo
 * @param[out]       versioninfo Pointer to where to store version information of this module
 *
 * @return           none
 */
#define Can_GetVersionInfo(versioninfo)                                       \
    {                                                                         \
        /* Check for DET: CAN_E_PARAM_POINTER */                              \
        if ((versioninfo) == NULL_PTR)                                        \
        {                                                                     \
            /* Report CAN_E_PARAM_POINTER DET if service called with          \
               NULL_PTR                                                       \
               Trace : SWS_Can_00177 */                                       \
            Det_ReportError(                                                  \
                (uint16)CAN_MODULE_ID,                                        \
                CAN_INSTANCE_ALL_ID,                                          \
                CAN_GET_VERSION_INFO_SID,                                     \
                CAN_E_PARAM_POINTER);                                         \
        }                                                                     \
        else                                                                  \
        {                                                                     \
            /* Vendor ID information */                                       \
            ((Std_VersionInfoType *)(versioninfo))->vendorID = CAN_VENDOR_ID; \
            /* Can module ID information */                                   \
            ((Std_VersionInfoType *)(versioninfo))->moduleID = CAN_MODULE_ID; \
            /* Can module Software major version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_major_version =        \
                (uint8)CAN_SW_MAJOR_VERSION;                                      \
            /* Can module Software minor version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =        \
                (uint8)CAN_SW_MINOR_VERSION;                                      \
            /* Can module Software patch version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =        \
                (uint8)CAN_SW_PATCH_VERSION;                                      \
        }                                                                     \
    }
#elif (((CAN_VERSION_INFO_API == STD_ON) && (CAN_DEV_ERROR_DETECT == STD_OFF)))
#define Can_GetVersionInfo(versioninfo)                                   \
    {                                                                     \
        /* Vendor ID information */                                       \
        ((Std_VersionInfoType *)(versioninfo))->vendorID = CAN_VENDOR_ID; \
        /* Can module ID information */                                   \
        ((Std_VersionInfoType *)(versioninfo))->moduleID = CAN_MODULE_ID; \
        /* Can module Software major version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_major_version =        \
            (uint8)CAN_SW_MAJOR_VERSION;                                      \
        /* Can module Software minor version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =        \
            (uint8)CAN_SW_MINOR_VERSION;                                      \
        /* Can module Software patch version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =        \
            (uint8)CAN_SW_PATCH_VERSION;                                      \
    }
#endif /* CAN_VERSION_INFO_API == STD_ON && CAN_DEV_ERROR_DETECT == STD_ON */

#ifdef __cplusplus
}
#endif

#endif /* CAN_H */

/** @} */

