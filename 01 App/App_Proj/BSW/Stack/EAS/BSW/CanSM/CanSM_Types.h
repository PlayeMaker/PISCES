/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanSM_Types.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : CANSM module type definitions head File
*   Author          : HeYang
********************************************************************************
*   Description     : The header file CanSM_Types.h contains the  common type
*                     definitions of the module CanSM
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
/*PRQA S 778,779 EOF*/
/*
Names in core files may not follow relevant rules.
*/

#ifndef CANSM_TYPES_H
#define CANSM_TYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanSM_Cfg.h"/*CANSM254*/
#include "CanSM_Version.h"
/*SWS_CanSM_00017 to get API and modeType */
#include "CanIf_Types.h"
/*SWS_CanSM_00191 to get ComM_BusSM_ModeIndication and ComM_ModeType*/
#if(STD_ON == CANSM_COMM_SUPPORT)
#include "ComM_BusSM.h"
#endif
#if(STD_ON == CANSM_DEM_SUPPORT)
#include "Dem.h"
#endif

/*******************************************************************************
*   Typedef
*******************************************************************************/

/*SWS_CanSM_00596*/
typedef enum
{
    CANSM_UNINITED = 0,
    CANSM_INITED = 1
} CanSM_StateType;

typedef enum
{
    CANSM_BSM_S_NOT_INITALIZED       = (uint8)0,
    CANSM_BSM_S_NOCOM                = (uint8)1,
    CANSM_BSM_S_SILENTCOM            = (uint8)2,
    /* follow substate may need process in every main function */
    CANSM_BSM_S_FULLCOM              = (uint8)3,
    CANSM_BSM_S_CHANGE_BAUDRATE      = (uint8)4,
    CANSM_BSM_S_PRE_FULLCOM          = (uint8)5,
    CANSM_BSM_S_PRE_NOCOM            = (uint8)6,
    CANSM_BSM_S_WUVALIDATION         = (uint8)7,
    CANSM_BSM_S_SILENTCOM_BOR        = (uint8)8
} CanSM_MainStateType;


typedef enum
{
    CANSM_NO_SUBSTATE = (uint8)0,
    CANSM_S_NO_BUS_OFF,
    /* follow substate may need process in every main function */
    CANSM_S_CHANGE_BR_SYNC,
    CANSM_S_TX_TIMEOUT_EXCEPTION,
    CANSM_S_BUS_OFF_CHECK,
    CANSM_S_TX_OFF,
    CANSM_S_CC_STOPPED,
    CANSM_S_CC_STOPPED_IND,
    CANSM_S_CC_SLEEP,
    CANSM_S_CC_SLEEP_IND,
    CANSM_S_CC_STARTED,
    CANSM_S_CC_START_IND,
    CANSM_S_TRCV_NORMAL,
    CANSM_S_TRCV_NORMAL_IND,
    CANSM_S_TRCV_STANDBY,
    CANSM_S_TRCV_STANDBY_IND,
    CANSM_S_RESTART_CC,
    CANSM_S_RESTART_CC_IND,
    CANSM_S_CC_STOPPED_WAIT,
    CANSM_S_CC_SLEEP_WAIT,
    CANSM_S_CC_STARTED_WAIT,
    CANSM_S_RESTART_CC_WAIT,
    CANSM_S_TRCV_NORMAL_WAIT,
    CANSM_S_TRCV_STANDBY_WAIT,
    CANSM_S_PN_CLEAR_WUF,
    CANSM_S_PN_CLEAR_WUF_WAIT,
    CANSM_S_PN_CLEAR_WUF_IND,
    CANSM_S_PN_CC_STOPPED,
    CANSM_S_CHECK_WFLAG_IN_NOT_CC_SLEEP,
    CANSM_S_CHECK_WFLAG_IN_CC_SLEEP,
    CANSM_S_CHECK_WFLAG_IN_CC_SLEEP_WAIT,
    CANSM_S_CHECK_WFLAG_IN_CC_SLEEP_IND,
    CANSM_S_CHECK_WUF_IN_NOT_CC_SLEEP_WAIT,
    CANSM_S_CHECK_WUF_IN_NOT_CC_SLEEP_IND,
    CANSM_S_CHECK_WUF_IN_CC_SLEEP_WAIT
} CanSM_subStateType;

/*SWS_CanSM_00598*/
typedef uint8 CanSM_BswMCurrentStateType;
#define CANSM_BSWM_NO_COMMUNICATION       (CanSM_BswMCurrentStateType)0
#define CANSM_BSWM_SILENT_COMMUNICATION   (CanSM_BswMCurrentStateType)1
#define CANSM_BSWM_FULL_COMMUNICATION     (CanSM_BswMCurrentStateType)2
#define CANSM_BSWM_BUS_OFF                (CanSM_BswMCurrentStateType)3
#define CANSM_BSWM_CHANGE_BAUDRATE        (CanSM_BswMCurrentStateType)4


#if(STD_OFF == CANSM_COMM_SUPPORT)
typedef uint8 ComM_ModeType;
/*CanSM state machine is in "No Communication" mode. Configured channel shall have no transmission or reception capability.*/
#define COMM_NO_COMMUNICATION                         ((ComM_ModeType)0)
/*CanSM state machine is in "Silent Communication" mode. Configured channel shall have only reception capability, no transmission capability.*/
#define COMM_SILENT_COMMUNICATION                     ((ComM_ModeType)1)
/*CanSM state machine is in "Full Communication" mode. Configured channel shall have both transmission and reception capability.*/
#define COMM_FULL_COMMUNICATION                       ((ComM_ModeType)2)
#endif

typedef struct
{
    ComM_ModeType                ComMMode;  /* only saved when report to ComM */
    CanSM_MainStateType          CanSMState;
    CanSM_subStateType           CanSMSubState;
    uint8                        retryNum;
    uint16                       durationTime;
    uint16                       borDurationTime;/* bor delay time */
    uint8                        borCnt;        /* num of try to bor */
    uint16                       borEnSureTime;
#if(STD_ON == CANSM_SET_BAUDRATE_API)
    uint16                       savedBDId;
#endif
    boolean                      StateChangeFlag;
} CanSM_NeworkInfoType;

typedef struct
{
#if(STD_OFF == CANSM_CTRLOPT_SUPPORT)
    uint8  CanIfCtrlId;
#endif
    NetworkHandleType ComMNetworfRef;
#if(STD_ON == CANSM_CANTRCV_SUPPORT)
    uint8  CanIfTrcvId;
#endif
    uint8  cntL1toL2;
    uint16 BorTimeL1;
    uint16 BorTimeL2;
    /*all configured networkhandle is false that CANSM_BOR_TX_CONFIRMATION_POLLING = STD_OFF*/
#if(STD_ON == CANSM_BOR_TX_CONFIRMATION_POLLING)
    boolean BorTxConfirmationPoll;
#endif
    uint16 BorTimeEnsure;
#if(STD_ON == CANSM_DEM_SUPPORT)
    Dem_EventIdType BusOffEventId;
    Dem_EventIdType ModeReqTimeOutId;
#endif
#if(STD_ON == CANSM_OSEKNM_SUPPORT)
    NetworkHandleType OsekNmHandle;
#endif
#if((STD_ON == CANSM_PNC_SUPPORT) && (STD_ON == CANSM_CANTRCV_SUPPORT))
    NetworkHandleType CanNmHandle;
#endif
#if(STD_ON == CANSM_MULTI_CORE_SUPPORT)
    uint8 CoreId;
#endif
} CanSM_NetworkCfgType;

/*SWS_CanSM_00597*/
typedef struct
{
    uint8   maxReqCnt;
    uint16  reqDuration;
    CONSTP2CONST(CanSM_NetworkCfgType, TYPEDEF, CANSM_CONST) netWorkCfg;
} CanSM_ConfigType;


#endif/*#ifndef CANSM_TYPES_H*/

