/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanSM.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : CanSM module Header File
*   Author          : Hirain
********************************************************************************
*   Description     : CanSM module Header File
*
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

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 776 EOF*/
/*
Names in core files may not follow relevant rules..
*/

#ifndef CANSM_H
#define CANSM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanSM_Cbk.h"
#include "CanSM_Lcfg.h"
#if(CANSM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
#include "CanSM_PBcfg.h"
#endif


/*******************************************************************************
*   Macro
*******************************************************************************/
/*APIID*/
#define CANSM_INIT_SERVICE_ID                               ((uint8)0x00)
#define CANSM_GETVERSIONINFO_SERVICE_ID                     ((uint8)0x01)
#define CANSM_REQUESTCOMMODE_SERVICE_ID                     ((uint8)0x02)
#define CANSM_GETCURRENTCOMMODE_SERVICE_ID                  ((uint8)0x03)
#define CANSM_CONTROLLERBUSOFF_SERVICE_ID                   ((uint8)0x04)
#define CANSM_MAINFUNCTION_SERVICE_ID                       ((uint8)0x05)
#define CANSM_CONFPN_SERVICE_ID                             ((uint8)0x06)
#define CANSM_CTRLMODEIND_SERVICE_ID                        ((uint8)0x07)
#define CANSM_CLEARTRCVWUFFLAG_SERVICE_ID                   ((uint8)0x08)
#define CANSM_TRCVMODEIND_SERVICE_ID                        ((uint8)0x09)
#define CANSM_CHECKTRCVWUKFLAGIND_SERVICE_ID                ((uint8)0x0A)
#define CANSM_TXTIMEOUTEX_SERVICE_ID                        ((uint8)0x0B)
#define CANSM_SETBAUDRATE_SERVICE_ID                        ((uint8)0x0D)
#define CANSM_SETICOMCONIFGURATION_SERVICE_ID               ((uint8)0x0F)
#define CANSM_CURRENTICOMCONFIGURATION_SERVICE_ID           ((uint8)0x10)
#define CANSM_STARTWAKEUPSOURCE_SERVICE_ID                  ((uint8)0x11)
#define CANSM_STOPWAKEUPSOURCE_SERVICE_ID                   ((uint8)0x12)
#define CANSM_SETECUPASSIVE_SERVICE_ID                      ((uint8)0x13)
#define CANSM_DEINIT_SERVICE_ID                             ((uint8)0x14)

#define CANSM_WAITPROCESS_SERVICE_ID                        ((uint8)0x50)

/*Det Error Code CANSM069*/
#define CANSM_E_UNINIT                      ((uint8)0x01)
#define CANSM_E_PARAM_POINTER               ((uint8)0x02)
#define CANSM_E_INVALID_NETWORK_HANDLE      ((uint8)0x03)
#define CANSM_E_PARAM_CONTROLLER            ((uint8)0x04)
#define CANSM_E_PARAM_TRANSCEIVER           ((uint8)0x05)
#define CANSM_E_BUSOFF_RECOVERY_ACTIVE      ((uint8)0x06)
#define CANSM_E_WAIT_MODE_INDICATION        ((uint8)0x07)
#define CANSM_E_INVALID_COMM_REQUEST        ((uint8)0x08)
#define CANSM_E_MODE_REQUEST_TIMEOUT        ((uint8)0x0A)
#define CANSM_E_NOT_IN_NO_COM               ((uint8)0x0B)
#define CANSM_E_INVALID_NETWORK_STATE       ((uint8)0x50)



/*******************************************************************************
*   API Declare
*******************************************************************************/
#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.h"

/*SWS_CanSM_00008*/
extern FUNC(void, CANSM_CODE) CanSM_MainFunction
(
    void
);

#if(STD_ON ==  CANSM_VERSION_INFO_API)
extern FUNC(void, CANSM_CODE) CanSM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CANSM_APPL_DATA) VersionInfo
);
#endif

extern FUNC(void, CANSM_CODE) CanSM_Init
(
    P2CONST(CanSM_ConfigType, AUTOMATIC, CANSM_APPL_CONST) ConfigPtr
);

extern FUNC(void, CANSM_CODE) CanSM_DeInit
(
    void
);
#if(STD_ON == CANSM_SET_BAUDRATE_API)/*SWS_CanSM_00569 SWS_CanSM_00570*/
extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_SetBaudrate
(
    NetworkHandleType network,
    uint16 BaudRateConfigID
);
#endif

#if(STD_ON == CANSM_TXOFFLINEACTIVE_SUPPORT)/*SWS_CanSM_00645*/
extern FUNC(Std_ReturnType, CANSM_CODE) CanSM_SetEcuPassive
(
    boolean CanSM_Passive
);
#endif


#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.h"


#endif/*#ifndef CANSM_H*/

