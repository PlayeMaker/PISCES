/**
 *   @file    Can_If.c
 *   @version
 *
 *   @brief   AUTOSAR Can interface
 *   @details This file is the Autosar Can interface
 *
 *   @addtogroup CAN_IF
 *   @{
 */
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : 
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

/*==================================================================================================
*                                          INCLUDE FILES
==================================================================================================*/
#include "CanIf.h"
#include "CanIf_Can.h"
#include "Can.h"
#define CANIF_UNUSED_PARAM(parma) ((void)parma)

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief           This service indicates a successful reception of a received CAN Rx L-PDU to 
 					the CanIf after passing all filters and validation checks.
 * @details
 * @param[in]       Can_HwType Identifies the HRH and its corresponding CAN Controller
 * @param[in]       PduInfoType Pointer to the received L-PDU
 * @return          void
 * @note            service_id:       0x14 \n
 *                  is_reentrant:     true \n
 *                  is_synchronous:   true \n
 *                  autosar_api:      true \n
 */
void CanIf_RxIndication(const Can_HwType *Mailbox, const PduInfoType *PduInfoPtr)
{
    CANIF_UNUSED_PARAM(Mailbox);
    CANIF_UNUSED_PARAM(PduInfoPtr);
    uint8 rxLen = 0;
    g_RxCanId = Mailbox->CanId;
    g_RxCanDlc = PduInfoPtr->SduLength;
    while (rxLen < g_RxCanDlc)
    {
      g_RxCanData[rxLen] = PduInfoPtr->SduDataPtr[rxLen];
      rxLen++;
    }
}

/**
 * @brief           This service confirms a previously successfully processed transmission of 
 					a CAN TxPDU.
 * @details
 * @param[in]       PduIdType L-PDU handle of CAN L-PDU successfully transmitted.
                    This ID specifies the corresponding CAN L-PDU ID and implicitly the CAN Driver 
                    instance as well as the corresponding CAN controller device.
 * @return          void
 * @note            service_id:       0x13 \n
 *                  is_reentrant:     true \n
 *                  is_synchronous:   true \n
 *                  autosar_api:      true \n
 */
void CanIf_TxConfirmation(PduIdType CanTxPduId)
{
    g_TxCanStatus = E_OK;
    CANIF_UNUSED_PARAM(CanTxPduId);
}

/**
 * @brief            
 * @details
 * @param[in]      
                    
 * @return           void
 * @note             service_id:       0x13 \n
 *                   is_reentrant:     true \n
 *                   is_synchronous:   true \n
 *                   autosar_api:      true \n
 */
 
void CanIf_CurrentIcomConfiguration \
		(uint8 ControllerId,IcomConfigIdType ConfigurationId,IcomSwitch_ErrorType Error)
{
	CANIF_UNUSED_PARAM(ControllerId);
	CANIF_UNUSED_PARAM(ConfigurationId);
	CANIF_UNUSED_PARAM(Error);
}

void CanIf_ControllerModeIndication(uint8 ControllerId,Can_ControllerStateType ControllerMode)
{
    CANIF_UNUSED_PARAM(ControllerId);
	CANIF_UNUSED_PARAM(ControllerMode);
}

void CanIf_ControllerBusOff(uint8 ControllerId)
{
    CANIF_UNUSED_PARAM(ControllerId);
}

/** @} */

