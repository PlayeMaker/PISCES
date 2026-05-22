/**
*   @file    ComStack_Types.h
*   @version
*
*   @brief   ComStack type define
*
*   @addtogroup GENERAL
*   @{
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
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

#ifndef COMSTACK_TYPES_H
#define COMSTACK_TYPES_H

/*=================================================================================================
*                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "Compiler.h"
#include "Platform_Types.h"
#include "ComStack_Types_Cfg.h"
/*******************************************************************************
*   Macro
*******************************************************************************/
/*Compatible with Mcal*/
#define COMTYPE_AR_RELEASE_MAJOR_VERSION     4
#define COMTYPE_AR_RELEASE_MINOR_VERSION     7
#define COMTYPE_AR_RELEASE_REVISION_VERSION  0


typedef uint8    NotifResultType;
/*General return codes for NotifResultType*/

/*Action has been successfully finished:
- message sent out (in case of confirmation),
- message received (in case of indication) */
#define NTFRSLT_OK                       ((NotifResultType)0x00)
/*Error notification:
- message not successfully sent out (in case of confirmation),
- message not successfully received (in case of indication) */
#define NTFRSLT_E_NOT_OK                 ((NotifResultType)0x01)
/*Error notification:
- timer N_Ar/N_As (according to ISO specification [ISONM]) has passed its
time-out value N_Asmax/N_Armax.This value can be issued to service user on
both the sender and receiver side. */
#define NTFRSLT_E_TIMEOUT_A              ((NotifResultType)0x02)
/*Error notification:
- timer N_Bs has passed its time-out value N_Bsmax (according to ISO
specification [ISONM]).This value can be issued to the service user on the
sender side only. */
#define NTFRSLT_E_TIMEOUT_BS             ((NotifResultType)0x03)
/*Error notification:
- timer N_Cr has passed its time-out value N_Crmax.
This value can be issued to the service user on the receiver side only. */
#define NTFRSLT_E_TIMEOUT_CR             ((NotifResultType)0x04)
/*Error notification:
- unexpected sequence number (PCI.SN) value received.
This value can be issued to the service user on the receiver side only. */
#define NTFRSLT_E_WRONG_SN               ((NotifResultType)0x05)
/*Error notification:
- invalid or unknown FlowStatus value has been received in a flow control
(FC) N_PDU.
This value can be issued to the service user on the sender side only. */
#define NTFRSLT_E_INVALID_FS             ((NotifResultType)0x06)
/*Error notification:
- unexpected protocol data unit received.
This value can be issued to the service user on both the sender and
receiver side. */
#define NTFRSLT_E_UNEXP_PDU              ((NotifResultType)0x07)
/*Error notification:
- flow control WAIT frame that exceeds the maximum counter N_WFTmax received.
This value can be issued to the service user on the receiver side. */
#define NTFRSLT_E_WFT_OVRN               ((NotifResultType)0x08)
/*Error notification:
Flow control (FC) N_PDU with FlowStatus = ABORT received. It indicates an abort
of a transmission. A possible reason for this is that the receiver is currently
busy and can not take the request at that point in time.*/
#define NTFRSLT_E_ABORT                  ((NotifResultType)0x09)
/*Error notification:
- flow control (FC) N_PDU with FlowStatus = OVFLW received.
  It indicates that the buffer on the receiver side of a segmented message
  transmission cannot store the number of bytes specified by the FirstFrame
  DataLength (FF_DL) parameter in the FirstFrame and therefore the transmission
  of the 19 of 23 AUTOSAR_SWS_ComStackTypes segmented message was aborted.
- no buffer within the TP available to transmit the segmented I-PDU.
This value can be issued to the service user on both the sender and receiver
side. */
#define NTFRSLT_E_NO_BUFFER              ((NotifResultType)0x0A)
/*Action has been successfully finished:
- Requested cancellation has been executed.*/
#define NTFRSLT_E_CANCELATION_OK         ((NotifResultType)0x0B)
/*Error notification:
- Due to an internal error the requested cancelation has not been executed.
This will happen e.g., if the to be canceled transmission has been executed
already.*/
#define NTFRSLT_E_CANCELATION_NOT_OK     ((NotifResultType)0x0C)
/*The parameter change request has been successfully executed */
#define NTFRSLT_PARAMETER_OK             ((NotifResultType)0x0D)
/*The request for the change of the parameter did not complete successfully*/
#define NTFRSLT_E_PARAMETER_NOT_OK       ((NotifResultType)0x0E)
/*The parameter change request not executed successfully due to an ongoing
reception*/
#define NTFRSLT_E_RX_ON                  ((NotifResultType)0x0F)
/*The parameter change request not executed successfully due to a wrong value*/
#define NTFRSLT_E_VALUE_NOT_OK           ((NotifResultType)0x10)

#define NTFRSLT_E_CAN_WRONG_CFDL         ((NotifResultType)0x11)
/* 0x12-0x1E Reserved values for  future usage. */

typedef uint8    BusTrcvErrorType;
/*General return codes for BusTrcvErrorType*/
#define BUSTRCV_OK         ((BusTrcvErrorType)0x00)
#define BUSTRCV_E_ERROR    ((BusTrcvErrorType)0x01)

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
typedef uint8        PduIdType;             /* uint8, uint16                 */
typedef uint16       PduLengthType;         /* uint8, uint16, uint32         */

typedef P2VAR(uint8, TYPEDEF, TYPEDEF) SduDataPtrType;
typedef struct
{
    SduDataPtrType SduDataPtr;
    P2VAR(uint8, TYPEDEF, TYPEDEF) MetaDataPtr;
    PduLengthType   SduLength;
} PduInfoType;

typedef enum
{
    TP_STMIN,
    TP_BS,
    TP_BC
} TPParameterType;

typedef enum
{
    BUFREQ_OK,
    BUFREQ_E_NOT_OK,
    BUFREQ_E_BUSY,
    BUFREQ_E_OVFL
} BufReq_ReturnType;

typedef enum
{
    TP_DATACONF,
    TP_DATARETRY,
    TP_CONFPENDING
} TpDataStateType;

typedef struct
{
    TpDataStateType     TpDataState;    /**< TP data state */
    PduLengthType       TxTpDataCnt;    /**< Tx TP data count */
} RetryInfoType;

typedef uint8       NetworkHandleType;
typedef uint8       IcomConfigIdType;

typedef enum
{
    ICOM_SWITCH_E_OK,
    ICOM_SWITCH_E_FAILED
} IcomSwitch_ErrorType;

#endif /* COMSTACK_TYPES_H */
/** @} */

