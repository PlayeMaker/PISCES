/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : ComM.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : ComM.h
*   Author          : Hirain
********************************************************************************
*   Description     : ComM.h
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
#ifndef COMM_H
#define COMM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComM_Cfg.h"
#if(COMM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
#include "ComM_PBcfg.h"
#endif
#include "ComM_Version.h"

/*******************************************************************************
*   Macro
*******************************************************************************/
/*Development Error*/
#if(STD_ON == COMM_DEV_ERROR_DETECT)
/*SWS_ComM_00234*/
#define COMM_E_UNINIT                            ((uint8)0x01)
#define COMM_E_WRONG_PARAMETERS                  ((uint8)0x02)
#define COMM_E_PARAM_POINTER                     ((uint8)0x03)
#define COMM_E_INIT_FAILED                       ((uint8)0x04)

/* Non Autosar Standard */
#define COMM_E_CALLED_IN_WRONG_CORE              ((uint8)0xFF)

/* API ID*/
#define COMM_INIT_APIID                          ((uint8)0x01)
#define COMM_DEINIT_APIID                        ((uint8)0x02)
#define COMM_GETSTATUS_APIID                     ((uint8)0x03)
#define COMM_GETINHIBITIONSTATUS_APIID           ((uint8)0x04)
#define COMM_REQUESTCOMMODE_APIID                ((uint8)0x05)
#define COMM_GETMAXCOMMODE_APIID                 ((uint8)0x06)
#define COMM_GETREQUESTEDCOMMODE_APIID           ((uint8)0x07)
#define COMM_GETCURRENTCOMMODE_APIID             ((uint8)0x08)
#define COMM_GETCURRENTPNCCOMMODE_APIID          ((uint8)0x6a)
#define COMM_PREVENTWAKEUP_APIID                 ((uint8)0x09)
#define COMM_LIMITCHANNELTONOCOMMODE_APIID       ((uint8)0x0b)
#define COMM_LIMITECUTONOCOMMODE_APIID           ((uint8)0x0c)
#define COMM_READINHIBITCOUNTER_APIID            ((uint8)0x0d)
#define COMM_RESETINHIBITCOUNTER_APIID           ((uint8)0x0e)
#define COMM_SETECUGROUPCLASSIFICATION_APIID     ((uint8)0x0f)
#define COMM_GETVERSIONINFO_APIID                ((uint8)0x10)

#define COMM_NM_NETWORKSTARTINDICATION_APIID     ((uint8)0x15)
#define COMM_NM_NETWORKMODE_APIID                ((uint8)0x18)
#define COMM_NM_PREPAREBUSSLEEPMODE_APIID        ((uint8)0x19)
#define COMM_NM_BUSSLEEPMODE_APIID               ((uint8)0x1a)
#define COMM_NM_RESTARTINDICATION_APIID          ((uint8)0x1b)
#define COMM_NM_REPEATMSGLEFTINDICATION_APIID    ((uint8)0x66)
#define COMM_NM_PNCLEARNINGBITINDICATION_APIID   ((uint8)0x69)
#define COMM_NM_FORWARDSYNCPNCSHUTDOWN_APIID     ((uint8)0x6b)
#define COMM_NM_UPDATEEIRA_APIID                 ((uint8)0x6c)
#define COMM_NM_UPDATEERA_APIID                  ((uint8)0x6d)

#define COMM_DCM_ACTIVEDIAGNOSTIC_APIID          ((uint8)0x1f)
#define COMM_DCM_INACTIVEDIAGNOSTIC_APIID        ((uint8)0x20)

#define COMM_ECUM_WAKEUPINDICATION_APIID         ((uint8)0x2a)
#define COMM_ECUM_PNCWAKEUPINDICATION_APIID      ((uint8)0x37)

#define COMM_COMMUNICATIONALLOWED_APIID          ((uint8)0x35)

#define COMM_BUSSM_MODEINDICATION_APIID          ((uint8)0x33)
#define COMM_BUSSM_BUSSLEEPMODE_APIID            ((uint8)0x34)

#define COMM_MAINFUNCTION_APIID                  ((uint8)0x60)
#endif



/*******************************************************************************
* Type of data to be stored in NvM
*******************************************************************************/
typedef struct
{
    ComM_InhibitionStatusType ComMEcuGroupClassification;
#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
    boolean ComMNoWakeupStatus[COMM_NUM_OF_CHANNEL];
#endif
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
    /*SWS_ComM_00138*//*SWS_ComM_00140*/
    uint16 ComMInhibitCounter;/*0...65535*/
#endif
    uint32 ComMCrc;/*Reserved for NvM CRC validation*/
} ComM_StoredDataType;


/*******************************************************************************
* Global Vars Declaration
*******************************************************************************/
#define COMM_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "ComM_MemMap.h"

/*This varible is not static since it will be access by NvM*/
extern VAR(ComM_StoredDataType, COMM_VAR) ComM_StoredData;

#define COMM_STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "ComM_MemMap.h"

/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/
#define COMM_START_SEC_CODE
#include "ComM_MemMap.h"

/*SWS_ComM_00146*/
extern FUNC(void, COMM_CODE) ComM_Init
(
    P2CONST(ComM_ConfigType, AUTOMATIC, COMM_CONST) ConfigPtr
);

/*SWS_ComM_00147*/
extern FUNC(void, COMM_CODE) ComM_DeInit
(
    void
);

/*SWS_ComM_00242*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetStatus
(
    P2VAR(ComM_InitStatusType, AUTOMATIC, COMM_APPL_DATA) Status
);

/*SWS_ComM_00619*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetInhibitionStatus
(
    NetworkHandleType Channel,
    P2VAR(ComM_InhibitionStatusType, AUTOMATIC, COMM_APPL_DATA) Status
);

/*SWS_ComM_00110*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_RequestComMode
(
    ComM_UserHandleType User,
    ComM_ModeType ComMode
);

/*SWS_ComM_00085*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetMaxComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
);

/*SWS_ComM_00079*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetRequestedComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
);

/*SWS_ComM_00083*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurrentComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
);

/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
/*SWS_ComM_91002*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurrentPNCComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
);

/*SWS_ComM_01034*//*SWS_ComM_01037*//*SWS_ComM_01041*/
#if((STD_ON == COMM_PNC_GW_ENABLED) && (STD_ON == COMM_DYN_PNC_TO_CHL_MAP_SUPPORT))
/*SWS_ComM_91013*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetPncToChannelMapping
(
    P2VAR(boolean, AUTOMATIC, COMM_APPL_DATA) MappingTable,
    P2VAR(uint8, AUTOMATIC, COMM_APPL_DATA) ChannelCnt,
    P2VAR(uint8, AUTOMATIC, COMM_APPL_DATA) PncCnt
);

/*SWS_ComM_91015*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_UpdatePncToChannelMapping
(
    P2CONST(boolean, AUTOMATIC, COMM_APPL_DATA) MappingTable,
    uint8 ChannelCnt,
    uint8 PncCnt
);

/*SWS_ComM_91017*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_ResetPncToChannelMapping
(
    void
);
#endif

/*SWS_ComM_01044*//*SWS_ComM_01047*/
#if(STD_ON == COMM_DYN_PNC_TO_CHL_MAP_SUPPORT)
/*SWS_ComM_91019*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_PnLearningRequest
(
    void
);

/*SWS_ComM_91021*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_UpdatePncMembership
(
    boolean Control,
    P2CONST(uint8, AUTOMATIC, COMM_APPL_DATA) PncMembership
);
#endif
#endif/*#if(STD_ON == COMM_PNC_SUPPORT)*/



/*SWS_ComM_00799*/
#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
/*SWS_ComM_00156*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_PreventWakeUp
(
    NetworkHandleType Channel,
    boolean Status
);
#endif


/*SWS_ComM_00800*//*SWS_ComM_00801*//*SWS_ComM_00802*//*SWS_ComM_00803*/
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
/*SWS_ComM_00163*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_LimitChannelToNoComMode
(
    NetworkHandleType Channel,
    boolean Status
);

/*SWS_ComM_00124*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_LimitECUToNoComMode
(
    boolean Status
);

/*SWS_ComM_00224*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_ReadInhibitCounter
(
    P2VAR(uint16, AUTOMATIC, COMM_APPL_DATA) CounterValue
);

/*SWS_ComM_00108*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_ResetInhibitCounter
(
    void
);
#endif/*#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)*/


/*SWS_ComM_00552*/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_SetECUGroupClassification
(
    ComM_InhibitionStatusType Status
);

#if(STD_ON == COMM_VERSION_INFO_API)
/*SWS_ComM_00370*/
extern FUNC(void, COMM_CODE) ComM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, COMM_APPL_DATA) VersionInfo
);
#endif



/*SWS_ComM_00429*/
extern FUNC(void, COMM_CODE) ComM_MainFunction
(
    NetworkHandleType Channel
);

#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"


#endif/*COMM_H*/

