/**
 * @file    Can_LLD.h
 * @version V0.9.1
 *
 * @brief AUTOSAR Can driver interface
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
/*==================================================================================================
==================================================================================================*/

#ifndef CAN_LLD_H
#define CAN_LLD_H

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/
#include "Can_Types.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
 * @file Can_LLD.h
 */
#define CAN_LLD_VENDOR_ID                      (180)
#define CAN_LLD_AR_RELEASE_MAJOR_VERSION       (4)
#define CAN_LLD_AR_RELEASE_MINOR_VERSION       (4)
#define CAN_LLD_AR_RELEASE_REVISION_VERSION    (0)
#define CAN_LLD_SW_MAJOR_VERSION               (0)
#define CAN_LLD_SW_MINOR_VERSION               (9)
#define CAN_LLD_SW_PATCH_VERSION               (1)

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/**
 * @file     Can_Types.h
 */
/* Check if source file and CAN configuration header file are of the same vendor */
#if (CAN_TYPES_VENDOR_ID != CAN_LLD_VENDOR_ID)
#error "Can_Types.h and Can_Lld.h have different vendor ids"
#endif

/* Check if source file and CAN configuration header file are of the same Autosar version */
#if ((CAN_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_LLD_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_TYPES_AR_RELEASE_MINOR_VERSION != CAN_LLD_AR_RELEASE_MINOR_VERSION) || \
     (CAN_TYPES_AR_RELEASE_REVISION_VERSION != CAN_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Can_Types.h and Can_Lld.h are different"
#endif

/* Check if source file and CAN configuration header file are of the same software version */
#if ((CAN_TYPES_SW_MAJOR_VERSION != CAN_LLD_SW_MAJOR_VERSION) || \
     (CAN_TYPES_SW_MINOR_VERSION != CAN_LLD_SW_MINOR_VERSION) || \
     (CAN_TYPES_SW_MINOR_VERSION != CAN_LLD_SW_MINOR_VERSION))
#error "Software Version Numbers of Can_Types.h and Can_Lld.h are different"
#endif

/*==================================================================================================
                                         DRVER FUNCTIONS
==================================================================================================*/
#if (CAN_API_GET_CONTROLLER_RX_ERROR_COUNTER == STD_ON)
/**
 * @brief Returns the Rx error counter for a CAN controller.
 * @param[in] BaseAddr CAN controller's base address
 * @return uint8. The value of the current Rx error counter.
 */
uint8 Can_Lld_GetInstRxErrCounter(uint32 BaseAddr);
#endif

#if (CAN_API_GET_CONTROLLER_TX_ERROR_COUNTER == STD_ON)
/**
 * @brief Returns the Tx error counter for a CAN controller.
 * @param[in] BaseAddr CAN controller's base address
 * @return uint8. The value of the current Tx error counter.
 */
uint8 Can_Lld_GetInstTxErrCounter(uint32 BaseAddr);
#endif

#if (CAN_API_GET_CONTROLLER_ERROR_STATE == STD_ON)
/**
 * @brief Returns the error status of corresponding Can controller channel.
 * @param[in] BaseAddr CAN controller's base address
 * @return Can_ErrorStateType. Current error status of the CAN controller.
 */
Can_ErrorStateType Can_Lld_GetInstErrState(uint32 BaseAddr);
#endif

#if(CAN_SET_BAUDRATE_API == STD_ON)
/**
 * @brief This function Set the CAN baudrate.
 * @param[in] ChConfigPtr Pointer to CAN driver channel configuration structure.
 * @param[in] BdrConfig Pointer to CAN baudrate configuration set.
 * @return void
 */
void Can_Lld_SetBaudrate(const Can_ChannelConfigType *ChConfigPtr, const Can_BdrConfigType *BdrConfig);
#endif

#if ((CAN_API_MAINFUNCTION_WAKEUP == STD_ON) || (CAN_WAKEUP_SUPPORT == STD_ON))
/**
 * @brief This service get the Check Wakeup event occur or not.
 * @param[in] ChConfigPtr Pointer to CAN driver channel configuration structure.
 * @return boolean TRUE or FALSE.
 */
boolean Can_Lld_CheckWakeupOccur(const Can_ChannelConfigType *ChConfigPtr);
#endif

/**
 * @brief This function disable all interrupts of CAN controller.
 * @param[in] ChnLogicId Controller ID.
 * @return void
 */
void Can_Lld_DisableInterrupts(uint8 ChnLogicId);

/**
 * @brief This function enable all interrupts set by config.
 * @param[in] ChnLogicId Controller ID.
 * @return void
 */
void  Can_Lld_EnableInterrupts(uint8 ChnLogicId);

/**
 * @brief This function initializes the specified Can controller channel.
 * @param[in] ChnLogicId Controller ID, user configured.
 * @param[in] Bdr Pointer to CAN baudrate configuration set.
 * @return Std_ReturnType.
 * @retval         E_OK     Can controller channel initialization successful.
 * @retval         E_NOT_OK Can controller channel initialization failed.
 */
Std_ReturnType Can_Lld_ChnInit(uint8 ChnLogicId, const Can_BdrConfigType *Bdr);

/**
 * @brief This function Set the specified to Started mode from Stopped mode.
 * @param[in] ChnLogicId Controller ID.
 * @return Std_ReturnType.
 * @retval         E_OK     Successfully changed status.
 * @retval         E_NOT_OK Change status failed.
 */
Std_ReturnType Can_Lld_ModeStoppedToStarted(uint8 ChnLogicId);

/**
 * @brief This function Set the specified to Stopped mode from Started mode.
 * @param[in] ChnLogicId Controller ID.
 * @return Std_ReturnType.
 * @retval         E_OK     Successfully changed status.
 * @retval         E_NOT_OK Change status failed.
 */
Std_ReturnType Can_Lld_ModeStartedToStopped(uint8 ChnLogicId);

/**
 * @brief This function Set the specified to Stopped mode from Sleep mode.
 * @param[in] ChnLogicId Controller ID.
 * @param[in] CanCfgPtr Pointer to CAN driver configuration structure.
 * @return Std_ReturnType.
 * @retval         E_OK     Successfully changed status.
 * @retval         E_NOT_OK Change status failed.
 */
Std_ReturnType Can_Lld_ModeSleepToStopped(uint8 ChnLogicId);

/**
 * @brief This function Set the specified to Sleep mode from Stopped mode.
 * @param[in] ChnLogicId Controller ID.
 * @param[in] CanCfgPtr Pointer to CAN driver configuration structure.
 * @return Std_ReturnType.
 * @retval         E_OK     Successfully changed status.
 * @retval         E_NOT_OK Change status failed.
 */
Std_ReturnType Can_Lld_ModeStoppedToSleep(uint8 ChnLogicId);

#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)
/**
 * @brief This function polling specified Can Hrh receive event.
 * @param[in] Hrh Hrh ID.
 * @param[in] CanCfgPtr Pointer to CAN driver configuration structure.
 * @return void
 */
void Can_Lld_PeriodPollingRead(Can_HwHandleType Hrh);
#endif /*#if (CAN_RX_PROCESS_HAS_POLLING == STD_ON)*/

#if (CAN_TX_PROCESS_HAS_POLLING == STD_ON)
/**
 * @brief This function polling specified Can Hth writing successful event.
 * @param[in] Hth Hth ID.
 * @param[in] CanCfgPtr Pointer to CAN driver configuration structure.
 * @return void
 */
void Can_Lld_PeriodPollingWrite(Can_HwHandleType Hth);
#endif /*#if (CAN_TX_PROCESS_HAS_POLLING == STD_ON)*/

#if ((CAN_RX_PROCESS_HAS_POLLING == STD_ON) || (CAN_TX_PROCESS_HAS_POLLING == STD_ON))
/**
 * @brief This function quickly determines whether the corresponding flag bit is set.
 * @param[in] HohPolTable Hoh Polling Table.
 * @return boolean TRUE or FALSE.
 */
boolean Can_Lld_GetPollingState(const Can_HohPolTableType * HohPolTable);
#endif

#if (CAN_BUSOFF_PROCESS_HAS_POLLING == STD_ON)
/**
 * @brief This function polling specified Can controller channel busoff event.
 * @param[in] ChnLogicId Controller ID.
 * @param[in] CanCfgPtr Pointer to CAN driver configuration structure.
 * @return void
 */
void Can_Lld_BusoffPolling(uint8 ChnLogicId);

/**
 * @brief This function quickly determines whether the corresponding busoff flag bit is set.
 * @param[in] ChnLogicId Controller ID.
 * @param[in] CanCfgPtr Pointer to CAN driver configuration structure.
 * @return boolean TRUE or FALSE.
 */
boolean Can_Lld_GetBusOffFlags(uint8 ChnLogicId);
#endif /*#if (CAN_BUSOFF_PROCESS_HAS_POLLING == STD_ON)*/

/**
 * @brief This function obtain the message buffer status of specified Hth.
 * @param[in] Hth Handle of the HTH.
 * @param[in] MailBoxBufId Message buffer Id whitch is been obtain.
 * @param[in] CanCfgPtr Pointer to CAN driver configuration structure.
 * @return Std_ReturnType.
 * @retval E_OK: the message buffer is exist and ok.
 * @retval E_NOT_OK: the message buffer is not exist.
 * @retval CAN_BUSY: the message buffer is busy.
 */
Std_ReturnType Can_Lld_GetMbState(Can_HwHandleType Hth, uint8 *MailBoxId);

/**
 * @brief This function fill up the message buffer status of specified Hth.
 * @param[in] Hth Handle of the HTH.
 * @param[in] MailBoxBufId message buffer Id.
 * @param[in] PduInfo Pdu message.
 * @param[in] CanCfgPtr Pointer to CAN driver configuration structure.
 * @return void.
 */
void Can_Lld_WriteMailBox(Can_HwHandleType Hth, uint8 MailBoxId, const Can_PduType *PduInfo);

#if (CAN_ICOM_USAGE == STD_ON)
/**
 * @brief This function init Icom configuration.
 * @param[in] ChnLogicId Logical channel ID
 * @param[in] CfgId ICOM configuration ID
 * @param[in] CanCfgPtr Pointer to CAN driver configuration structure.
 * @return void
 */
void Can_Lld_SetControllerIcom(uint8 ChnLogicId, IcomConfigIdType CfgId, const Can_ConfigType *CanCfgPtr);
#endif

#if (CAN_API_ABORT_CONTROLLER_PENDING_MESSAGE == STD_ON)
/**
 * @brief This function aborts pending L-PDUs transmission.
 * @param[in] ChConfigPtr Can channel config ptr point to a channel's configuration.
 * @return void.
 */
void Can_Lld_AbortPendingMsg(const Can_ChannelConfigType *ChConfigPtr);
#endif

#if (CAN_BUSOFF_PROCESS_HAS_INTERRUPT == STD_ON)
/**
 * @brief This function is the handler of ORed interrupt
 *
 * @details             OR ed[Bus Off OR Bus Off Done OR Transmit Warning OR Receive Warning]
 * @param[in] ChnHwId CAN controller Hardware id.
 * @return void.
 */
void Can_Lld_IntHwObjPrcsORedBusoff(uint8 ChnHwId);
#endif

/**
 * @brief This function is the handler of Error interrupt
 *
 * @details             Interrupt indicating that errors were detected on the CAN bus
 *                      Interrupt indicating that errors were detected on the CAN bus for FD messages in the Fast Bit Rate region
 *                      Interrupt asserted due to correctable error detected in memory read access
 *                      Interrupt asserted due to non-correctable error detected in memory read access by host(CPU)
 *                      Interrupt asserted due to non-correctable error detected in memory read access by the FlexCAN
 * @param[in] ChnHwId CAN controller Hardware id.
 * @return void.
 */
void Can_Lld_IntHwObjPrcsErr(uint8 ChnHwId);

#if((CAN_RX_PROCESS_HAS_INTERRUPT == STD_ON) || (CAN_TX_PROCESS_HAS_INTERRUPT == STD_ON))
/**
 * @brief This function is the handler of ORed MB interrupt
 *
 * @details An interrupt indicating which mailbox has received data or completed transmitting data.
 * @param[in] ChnHwId CAN controller Hardware id.
 * @param[in] RegisterIdx Flag register's idx.
 * @return void.
 */
void Can_Lld_IntHwObjPrcsFrame(uint8 ChnHwId, uint8 RegisterIdx);
#endif

/**
 * @brief This function is used to install a Can_Config ptr to a Can_Lld layer.
 *
 * @param CanConfigPtr A pointer point to Can_Config.
 */
void Can_Lld_InstallConfigPtr(const Can_ConfigType* CanConfigPtr);

/**
 * @brief This function is used to uninstall a Can_Config ptr in a Can_Lld layer.
 *
 */
void Can_Lld_UnInstallConfigPtr(void);

#if (CAN_WAKEUP_SUPPORT == STD_ON)
/**
 * @brief This function is used to process wakeup enent.
 *
 * @param ChnHwId Hardware id of CAN channel.
 */
void Can_Lld_IntHwObjProcess_Wakeup(uint8 ChnHwId);
#endif

#ifdef __cplusplus
}
#endif

#endif /* CAN_LLD_H */

/** @} */

