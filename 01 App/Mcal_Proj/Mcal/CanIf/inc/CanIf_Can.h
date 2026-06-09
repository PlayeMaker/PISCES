/*
 *   @file    CanIf_Can.h
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
#ifndef CANIF_CAN_H
#define CANIF_CAN_H
#include "Std_Types.h"
#include "Can_GeneralTypes.h"
#ifdef  __cplusplus
extern "C"
{
#endif
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_CAN_VENDOR_ID                      (180)
#define CANIF_CAN_AR_RELEASE_MAJOR_VERSION       (4)
#define CANIF_CAN_AR_RELEASE_MINOR_VERSION       (4)
#define CANIF_CAN_AR_RELEASE_REVISION_VERSION    (0)
#define CANIF_CAN_SW_MAJOR_VERSION               (0)
#define CANIF_CAN_SW_MINOR_VERSION               (9)
#define CANIF_CAN_SW_PATCH_VERSION               (1)
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanIf_Types.h header file are of the same vendor */
#if (CANIF_CAN_VENDOR_ID != CANIF_TYPES_VENDOR_ID)
/* #error "CanIf_Can.h and CanIf_Types.h have different vendor ids" */
#endif
/* Check if current file and CanIf_Types.h header file are of the same Autosar version */
#if ((CANIF_CAN_AR_RELEASE_MAJOR_VERSION != CANIF_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CANIF_CAN_AR_RELEASE_MINOR_VERSION != CANIF_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CANIF_CAN_AR_RELEASE_REVISION_VERSION != CANIF_TYPES_AR_RELEASE_REVISION_VERSION))
  /* #error "AutoSar Version Numbers of CanIf_Can.h and CanIf_Types.h are different" */
#endif
/* Check if current file and CanIf_Types.h header file are of the same software version */
#if ((CANIF_CAN_SW_MAJOR_VERSION != CANIF_TYPES_SW_MAJOR_VERSION) || \
     (CANIF_CAN_SW_MINOR_VERSION != CANIF_TYPES_SW_MINOR_VERSION) || \
     (CANIF_CAN_SW_PATCH_VERSION != CANIF_TYPES_SW_PATCH_VERSION))
  /* #error "Software Version Numbers of CanIf_Can.h and CanIf_Types.h are different" */
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
/**
 * @brief           This service confirms a previously successfully processed transmission of a 
 					CAN TxPDU.
 * @details
 * @param[in]       PduIdType L-PDU handle of CAN L-PDU successfully transmitted.
                    This ID specifies the corresponding CAN L-PDU ID and implicitly the CAN 
                    Driver instance as well as the corresponding CAN controller device.
 * @return          void
 * @note            service_id:       0x13 \n
 *                  is_reentrant:     true \n
 *                  is_synchronous:   true \n
 *                  autosar_api:      true \n
 */
void CanIf_TxConfirmation(PduIdType CanTxPduId);

/**
 * @brief           This service indicates a successful reception of a received CAN Rx L-PDU to the 
 					CanIf after passing all filters and validation checks.
 * @details
 * @param[in]       Can_HwType Identifies the HRH and its corresponding CAN Controller
 * @param[in]       PduInfoType Pointer to the received L-PDU
 * @return          void
 * @note            service_id:       0x14 \n
 *                  is_reentrant:     true \n
 *                  is_synchronous:   true \n
 *                  autosar_api:      true \n
 */
void CanIf_RxIndication(const Can_HwType *Mailbox, const PduInfoType *PduInfoPtr);

/**
 * @brief           This service indicates a Controller BusOff event referring to the corresponding
 					CAN Controller with the abstract CanIf ControllerId.
 * @details
 * @param[in]       uint8 Abstract CanIf ControllerId which is assigned to a CAN controller, where a 
 					BusOff occured.
 * @return          void
 * @note            service_id:       0x16 \n
 *                  is_reentrant:     true \n
 *                  is_synchronous:   true \n
 *                  autosar_api:      true \n
 */
void CanIf_ControllerBusOff(uint8 ControllerId);

void CanIf_ControllerModeIndication(uint8 ControllerId,Can_ControllerStateType ControllerMode);
void CanIf_CurrentIcomConfiguration( uint8 ControllerId, IcomConfigIdType  ConfigurationId, IcomSwitch_ErrorType Error);


void CanIf_ControllerErrorStatePassive(uint8 ControllerId, uint16 RxErrorCounter, uint16 TxErrorCounter);

/**
 * @brief           Within this API, the upper layer module (called module) shall check whether 
 					the available data fits into the buffer size reported by 
 					PduInfoPtr->SduLength. If it fits, it shall copy its data into the buffer 
 					provided by PduInfoPtr->SduDataPtr and update the length of the actual copied 
 					data in PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing 
 					PduInfoPtr.
 * @details
 * @param[in]       PduIdType ID of the SDU that is requested to be transmitted.
 * @param[inout]    PduInfoType Contains a pointer to a buffer (SduDataPtr) to where the SDU data
 					shall be copied, and the available buffer size in SduLengh. On return, the 
 					service will indicate the length of the copied SDU data in SduLength.
 * @return          Std_ReturnType
 * @note            service_id:       0x41 \n
 *                  is_reentrant:     false \n
 *                  is_synchronous:   true \n
 *                  autosar_api:      true \n
 */
Std_ReturnType CanIf_TriggerTransmit(PduIdType TxPduId, PduInfoType *PduInfoPtr);

#ifdef __cplusplus
}
#endif

#endif /* CANIF_CAN_H */

/** @} */

