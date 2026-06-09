/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanTp.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : CanTp.h
*   Author          : Hirain
********************************************************************************
*   Description     : Main header file of the AUTOSAR CAN Transport Protocol,
*                     according to AUTOSAR_SWS_CANTransportLayer.pdf(Release4.2)
*                     The header file contains the declaration of the Can module
*                     API;contains 'extern' declarations of constants,global data,
*                     type definitions and services that are specified in the
*                     CanTp module SWS.
*
********************************************************************************
*   Limitations     :
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/

/*PRQA S 776 EOF*/
/*
Names  in Core files may not follow relevant rules.
*/

#ifndef CANTP_H
#define CANTP_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanTp_PBcfg.h"
#include "CanTp_Version.h"


/**************************************************************************************************
* Global defines
**************************************************************************************************/

/* Development Error */
#if(STD_ON == CANTP_DEV_ERROR_DETECT)
/*SWS_CanTp_00293*/
#define CANTP_E_INIT_FAILED                      (0x04)
#define CANTP_E_UNINIT                           (0x20)
#define CANTP_E_INVALID_TX_ID                    (0x30)
#define CANTP_E_INVALID_RX_ID                    (0x40)
#define CANTP_E_PADDING                          (0x70)
#define CANTP_E_PARAM_CONFIG                     (0x01)
#define CANTP_E_PARAM_ID                         (0x02)
#define CANTP_E_PARAM_POINTER                    (0x03)
#define CANTP_E_INVALID_TATYPE                   (0x90)
#define CANTP_E_OPER_NOT_SUPPORTED               (0xA0)
#define CANTP_E_COM                              (0xB0)
#define CANTP_E_RX_COM                           (0xC0)
#define CANTP_E_TX_COM                           (0xD0)

#define CANTP_E_INVALID_TX_BUFFER                (0x50)
#define CANTP_E_INVALID_RX_BUFFER                (0x60)
#define CANTP_E_INVALID_TX_LENGTH                (0x80)
#define CANTP_E_INVALID_RX_LENGTH                (0xE0)

#define CANTP_E_INVALID_CHANNEL                  (0xFE)
#define CANTP_E_INVALID_ADDRESS                  (0xFD)
#define CANTP_E_INVALID_RXFC_ID                  (0xFC)
#define CANTP_E_INVALID_NPCI_OFFSET              (0xFB)

/* --- API Service IDs ---- */
#define CANTP_SID_INIT                           (0x01)
#define CANTP_SID_SHUTDOWN                       (0x02)
#define CANTP_SID_TRANSMIT                       (0x49)
#define CANTP_SID_RXINDICATION                   (0x42)
#define CANTP_SID_TXCONFIRMATION                 (0x40)
#define CANTP_SID_MAINFUNCTION                   (0x06)
#define CANTP_SID_GETVERSIONINFO                 (0x07)
#define CANTP_SID_CANCELTRANSMIT                 (0x4A)
#define CANTP_SID_CANCELRECEIVE                  (0x4C)
#define CANTP_SID_CHANGEPARAMETER                (0x4B)
#define CANTP_SID_READPARAMETER                  (0x0B)
#define CANTP_SID_MAINFUNCTIONRX                 (0x20)
#define CANTP_SID_MAINFUNCTIONTX                 (0x21)

#endif

/**************************************************************************************************
* Gloable Data definitions
**************************************************************************************************/

/**************************************************************************************************
* Prototypes of export functions
**************************************************************************************************/
#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"

extern FUNC(void, CANTP_CODE) CanTp_Init
(
    CONSTP2CONST (CanTp_ConfigType, CANTP_APPL_CONST, AUTOMATIC) CfgPtr
);

extern FUNC(void, CANTP_CODE) CanTp_Shutdown
(
    void
);

extern FUNC(void, CANTP_CODE) CanTp_MainFunction
(
    void
);

extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_Transmit
(
    PduIdType CanTpTxSduId,
    P2CONST (PduInfoType, AUTOMATIC, CANTP_APPL_DATA) CanTpTxInfoPtr
);

#if(CANTP_TC == STD_ON)
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_CancelTransmit
(
    PduIdType CanTpTxSduId
);
#endif

#if(CANTP_RC == STD_ON)
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_CancelReceive
(
    PduIdType CanTpRxSduId
);
#endif

#if(STD_ON == CANTP_CHANGE_PARAMETER_API)
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_ChangeParameter
(
    PduIdType id,
    TPParameterType parameter,
    uint16 value
);
#endif

#if(STD_ON == CANTP_READ_PARAMETER_API)
extern FUNC(Std_ReturnType, CANTP_CODE) CanTp_ReadParameter
(
    PduIdType id,
    TPParameterType parameter,
    P2VAR (uint16, AUTOMATIC, CANTP_APPL_DATA) value
);
#endif


#if(CANTP_VERSION_INFO_API == STD_ON)
extern FUNC(void, CANTP_CODE) CanTp_GetVersionInfo
(
    P2VAR (Std_VersionInfoType, AUTOMATIC, CANTP_APPL_DATA) versioninfo
);
#endif

#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"

#endif/* CANTP_H */

