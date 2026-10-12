/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : BswM.h
*   Author          : Hirain
********************************************************************************
*   Description     : BswM.h
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
#ifndef BSWM_H
#define BSWM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "BswM_Version.h"
#include "BswM_Lcfg.h"
#if(BSWM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
#include "BswM_PBcfg.h"
#endif
#include "BswM_Cfg.h"


/*******************************************************************************
*   Macro
*******************************************************************************/
/* Development Error */
/*SWS_BswM_00230*/
#define BSWM_E_UNINIT                        ((uint8)0x01)
#define BSWM_E_NULL_POINTER                  ((uint8)0x02)
#define BSWM_E_PARAM_INVALID                 ((uint8)0x03)
#define BSWM_E_REQ_USER_OUT_OF_RANGE         ((uint8)0x04)
#define BSWM_E_REQ_MODE_OUT_OF_RANGE         ((uint8)0x05)
#define BSWM_E_PARAM_CONFIG                  ((uint8)0x06)
#define BSWM_E_PARAM_POINTER                 ((uint8)0x07)
#define BSWM_E_INIT_FAILED                   ((uint8)0x08)
#define BSWM_E_ACTION_FAILED                 ((uint8)0xFF)

/* Non Autosar Standard */

/* API ID*/
#define BSWM_INIT_APIID                                 ((uint8)0x00)
#define BSWM_GETVERSIONINFO_APIID                       ((uint8)0x01)
#define BSWM_REQUESTMODE_APIID                          ((uint8)0x02)
#define BSWM_MAINFUNCTION_APIID                         ((uint8)0x03)
#define BSWM_DEINIT_APIID                               ((uint8)0x04)
#define BSWM_CANSM_CURRENTSTATE_APIID                   ((uint8)0x05)
#define BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_APIID   ((uint8)0x06)
#define BSWM_LINSM_CURRENTSTATE_APIID                   ((uint8)0x09)
#define BSWM_LINSM_CURRENTSCHEDULE_APIID                ((uint8)0x0a)
#define BSWM_LINTP_REQUESTMODE_APIID                    ((uint8)0x0b)
#define BSWM_FRSM_CURRENTSTATE_APIID                    ((uint8)0x0c)
#define BSWM_ETHSM_CURRENTSTATE_APIID                   ((uint8)0x0d)
#define BSWM_COMM_CURRENTMODE_APIID                     ((uint8)0x0e)
#define BSWM_ECUM_CURRENTSTATE_APIID                    ((uint8)0x28)
#define BSWM_ECUM_CURRENTWAKEUP_APIID                   ((uint8)0x10)
#define BSWM_WDGM_REQUESTPARTITIONRESET_APIID           ((uint8)0x11)
#define BSWM_TRIGGERSTARTUPPHASE2_APIID                 ((uint8)0x12)
#define BSWM_DCM_APPLICATIONUPDATED_APIID               ((uint8)0x14)
#define BSWM_COMM_CURRENTPNCMODE_APIID                  ((uint8)0x15)
#define BSWM_NVM_CURRENTBLOCKMODE_APIID                 ((uint8)0x16)
#define BSWM_NVM_CURRENTJOBMODE_APIID                   ((uint8)0x17)
#define BSWM_J1938NM_STATECHANGENOTIFICATION_APIID      ((uint8)0x18)
#define BSWM_J1938DCMBROADCASTSTATUS_APIID              ((uint8)0x1b)
#define BSWM_BSWMPARTITIONRESTARTED_APIID               ((uint8)0x1e)
#define BSWM_SD_CLIENTSERVICECURRENTSTATE_APIID         ((uint8)0x1f)
#define BSWM_SD_EVENTHANDLERCURRENTSTATE_APIID          ((uint8)0x20)
#define BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_APIID    ((uint8)0x21)
#define BSWM_COMM_INITIATERESET_APIID                   ((uint8)0x22)
#define BSWM_NM_CARWAKEUPINDICATION_APIID               ((uint8)0x24)
#define BSWM_ETHIF_PORTGROUPLINKSTATECHG_APIID          ((uint8)0x26)
#define BSWM_NM_STATECHANGENOTIFICATION_APIID           ((uint8)0x27)
#define BSWM_ECUM_REQUESTEDSTATE_APIID                  ((uint8)0x29)
#define BSWM_SOAD_SOCONMODECHG_APIID                    ((uint8)0x2a)


/*******************************************************************************
*   API Declaration
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"

extern FUNC(void, BSWM_CODE) BswM_Init
(
    P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_CONST) ConfigPtr
);


extern FUNC(void, BSWM_CODE) BswM_Deinit
(
    void
);

#if(STD_ON == BSWM_VERSION_INFO_API)
extern FUNC(void, BSWM_CODE) BswM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, BSWM_APPL_DATA) VersionInfo
);
#endif

#if(STD_ON == BSWM_GENERIC_REQUEST_ENABLED)
extern FUNC(void, BSWM_CODE) BswM_RequestMode
(
    BswM_UserType requesting_user,
    BswM_ModeType requested_mode
);
#endif

#if(STD_ON == BSWM_MULTIPATITION_ENABLED)
extern FUNC(void, BSWM_CODE) BswM_BswMPartitionRestarted
(
    void
);

#endif

extern FUNC(void, BSWM_CODE) BswM_MainFunction
(
    void
);

extern FUNC(void, BSWM_CODE) BswM_SetRulesAsDeffer
(
    uint8 CoreId,
    BswMPortType Port
);

#if(STD_ON == BSWM_TIMER_ENABLED)
extern FUNC(void, BSWM_CODE) BswM_SetTimer
(
    uint8 TimerID,
    uint16 TimerValue
);
extern FUNC(void, BSWM_CODE) BswM_StopTimer
(
    uint8 TimerID
);
#endif

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"


#endif/* BSWM_H */

