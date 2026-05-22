/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : BswM_Cfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : BswM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : BswM module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/
/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 791,792 EOF*/
/*
Relevant names of WDGM_AR_RELEASE_REVISION_VERSION may not follow relevant naming rules.
*/

/*PRQA S 5087,3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address segments in the files of each module.
*/

/*PRQA S 0857,0380 EOF*/
/*
Macro definitions exceed 1024. The number of macros is unlimited
*/

/*PRQA S 3111,2213,3132,3211,0914,3120 EOF*/
/*
Particularity of configuration files.
*/

/*PRQA S 4153,4152 EOF*/
/*
Specific naming rules without modification
*/

/*PRQA S 2100,2101 EOF*/
/*
Integer promotion related
*/

/*PRQA S 3200 EOF*/
/*
'XXX' returns a value which is not being used.
*/

/*PRQA S 3430 EOF*/
/*
Macro argument expression may require parenttheses.
*/
/*****************************************************************************
 *  BswM QAC Suppression
 *****************************************************************************/
/*PRQA S 3450 EOF*/
/*
The internal linkage functions don't need previous declaration..
*/
/*PRQA S 1531,1533 EOF*/
/*
Configuration code must be defined in the config file.
*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "BswM_Lcfg.h"
#include "Rte_BswM.h"
#include "SchM_BswM.h"
#include "Rte_Main.h"


#include "Com.h"
#include "ComM.h"
#include "Dcm.h"
#include "CanSM.h"

/*******************************************************************************
*   Global Vars
*******************************************************************************/

#define BSWM_START_SEC_CONFIG_DATA
#include "BswM_MemMap.h"


CONST(NetworkHandleType, BSWM_CONST) BswM_CanSMModeRef[BSWM_CANSM_PORT_NUM] =
{
    CanSM_ComM_BODY_LE1_CAN
};

CONST(NetworkHandleType, BSWM_CONST) BswM_ComMModeRef[BSWM_COMM_PORT_NUM] =
{
    ComM_ComM_BODY_LE1_CAN
};

CONST(NetworkHandleType, BSWM_CONST) BswM_DcmComMModeRef[BSWM_DCM_PORT_NUM] =
{
    ComM_ComM_BODY_LE1_CAN
};




#define BSWM_STOP_SEC_CONFIG_DATA
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_INIT_GLOBAL_8
#include "BswM_MemMap.h"

/*ECUC_BswM_01043*/
VAR(EcuM_StateType, BSWM_VAR) BswM_EcuMRequestMode = ECUM_STATE_SHUTDOWN;

/*ECUC_BswM_00857*/
VAR(CanSM_BswMCurrentStateType, BSWM_VAR) BswM_CanSMMode[BSWM_CANSM_PORT_NUM] =
{
    CANSM_BSWM_NO_COMMUNICATION
};
/*ECUC_BswM_00880*/
VAR(ComM_ModeType, BSWM_VAR) BswM_ComMMode[BSWM_COMM_PORT_NUM] =
{
    COMM_NO_COMMUNICATION
};
/*ECUC_BswM_00956*/
VAR(NvM_RequestResultType, BSWM_VAR) BswM_NvMReadAllStatus = NVM_REQ_PENDING;
/*ECUC_BswM_00956*/
VAR(NvM_RequestResultType, BSWM_VAR) BswM_NvMWriteAllStatus = NVM_REQ_PENDING;

VAR(BswM_TimerState, BSWM_VAR) BswM_TimerMode[BSWM_MAX_TIMER_NUM] =
{
    BSWM_TIMER_STOPPED
};


/*ECUC_BswM_00863*/
VAR(Dcm_CommunicationModeType, BSWM_VAR) BswM_DcmComMMode[BSWM_DCM_PORT_NUM] =
{
    DCM_ENABLE_RX_TX_NORM_NM
};


#define BSWM_STOP_SEC_VAR_INIT_GLOBAL_8
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_INIT_GLOBAL_16
#include "BswM_MemMap.h"

VAR(BswM_ModeType, BSWM_VAR) BswM_GeneralPortMode[BSWM_GENERAL_PORT_NUM] =
{
    BSWM_GENERIC_MODE_INIT
};


#define BSWM_STOP_SEC_VAR_INIT_GLOBAL_16
#include "BswM_MemMap.h"




