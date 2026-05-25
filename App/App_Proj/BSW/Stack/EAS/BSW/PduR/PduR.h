/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : PduR.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : PduR.h
*   Author          : Hirain
********************************************************************************
*   Description     : PduR.h
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/
#ifndef PDUR_H
#define PDUR_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "PduR_Cbk.h"
#include "PduR_Version.h"


#if(STD_OFF == PDUR_ZERO_COST_OPERATION)
/*******************************************************************************
*   Macro
*******************************************************************************/
/* Development Error */

/*SWS_PduR_00100 SWS_PDUR_00816*/
#define PDUR_E_INIT_FAILED                       (0x00)
#define PDUR_E_UNINIT                            (0x01)
#define PDUR_E_PDU_ID_INVALID                    (0x02)
#define PDUR_E_TP_TX_REQ_REJECTED                (0x03)
#define PDUR_E_PARAM_INVALID                     (0x04)
#define PDUR_E_DUPLICATE_IPDU_ID                 (0x06)
#define PDUR_E_IPDU_TOO_LONG                     (0x07)
#define PDUR_E_ROUTING_PATH_GROUP_ID_INVALID     (0x08)
#define PDUR_E_PARAM_POINTER                     (0x09)
#define PDUR_E_PDU_INSTANCES_LOST                (0x0a)


/* Non Autosar Standard */
#define PDUR_E_DEST_TXBUF_ID_INVALID             (0x0c)
#define PDUR_E_DEST_NUM_TOO_MUCH                 (0x0d)
#define PDUR_E_DEST_TRIGGER_INVALID              (0x0e)

/* API ID*/
#define PDUR_INIT_APIID                          (0xf0)
#define PDUR_GETVERSIONINFO_APIID                (0xf1)
#define PDUR_GETCONFIGURATIONID_APIID            (0xf2)
#define PDUR_ENABLE_ROUTING_APIID                (0xf3)
#define PDUR_DISABLE_ROUTING_APIID               (0xf4)

#define PDUR_MODULE_IF_TXCONFIRMATION_APIID      (0x40)
#define PDUR_MODULE_IF_TRIGGERTRANSMIT_APIID     (0x41)
#define PDUR_MODULE_IF_RXINDICATION_APIID        (0x42)

#define PDUR_MODULE_TP_COPYTXDATA_APIID          (0x43)
#define PDUR_MODULE_TP_COPYRXDATA_APIID          (0x44)
#define PDUR_MODULE_TP_RXINDICATION_APIID        (0x45)
#define PDUR_MODULE_TP_STARTOFRECEPTION_APIID    (0x46)
#define PDUR_MODULE_TP_TXCONFIRMATION_APIID      (0x48)

#define PDUR_MODULE_UP_TRANSMIT_APIID            (0x49)
#define PDUR_MODULE_UP_CANCEL_TRANSMIT_APIID     (0x4a)
#define PDUR_MODULE_UP_CANCEL_RECEIVE_APIID      (0x4c)
#define PDUR_PDUR_GETRXPDUSTATE_APIID            (0x4F)
#define PDUR_GETPATHSTATE_APIID                  (0xFF)

#define PDUR_TEST_ENABLE                           STD_OFF
/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/
#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

extern FUNC(void, PDUR_CODE) PduR_Init
(
    P2CONST(PduR_PBConfigType, AUTOMATIC, PDUR_CONST) ConfigPtr
);

extern FUNC(void, PDUR_CODE) PduR_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, PDUR_APPL_DATA) versionInfo
);

extern FUNC(PduR_PBConfigIdType, PDUR_CODE) PduR_GetConfigurationId
(
    void
);

extern FUNC(void, PDUR_CODE) PduR_EnableRouting
(
    PduR_RoutingPathGroupIdType id
);

extern FUNC(void, PDUR_CODE) PduR_DisableRouting
(
    PduR_RoutingPathGroupIdType id,
    boolean initialize
);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_UpCallTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_CONST) PduInfoPtr
);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_UpCallCancelTransmit
(
    PduIdType TxPduId
);

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_UpCallCancelReceive
(
    PduIdType RxPduId
);

#if(STD_ON == PDUR_PDU_BUFFER_SUPPORT)
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_GetPathState
(
    PduIdType id,
    uint8* PathStatus
);
#endif

extern FUNC(Std_ReturnType, PDUR_CODE) PduR_GetRxPduState
(
    PduIdType id
);

#if(STD_ON == PDUR_MULTICORE_SUPPORT)
extern FUNC(void, PDUR_CODE) PduR_CrossCoreTxMainfunction
(
    void
);
#ifdef PDUR_SRC_MAINFUNCTION_ENABLE
extern FUNC(void, PDUR_CODE) PduR_CrossCoreSrcMainfunction
(
    void
);
#endif
#endif

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"

#else
#define PduR_Init(ConfigPtr)
#endif

#endif /*PDUR_H */

