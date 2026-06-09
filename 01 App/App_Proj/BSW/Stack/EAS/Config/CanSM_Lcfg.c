/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanSM_Lcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanSM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanSM module configuration File
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


/*PRQA S 2100,2101 EOF*/
/*
Integer promotion related
*/

/*PRQA S 3227 EOF*/
/*
Read-only function input parameters may not be defined as const,it does not affect the function.
AUTOSAR API shall define standard input parameters according to specification requirements.
*/

/*PRQA S 3204,3206 EOF*/
/*
Read-only local variables may not be defined as const,this does not affect the function
*/
/*PRQA S 1531 EOF*/
/*
Variable are used in the core code.
*/


/*******************************************************************************
*   Includes
*******************************************************************************/

#include "CanSM.h"


#define CANSM_START_SEC_VAR_CLEARED_LOCAL_8
#include "CanSM_MemMap.h"
VAR(uint8, CANSM_VAR)  CanSM_TriggerInfo[CANSM_MAX_NETWORK_NUM];
#define CANSM_STOP_SEC_VAR_CLEARED_LOCAL_8
#include "CanSM_MemMap.h"


#define CANSM_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "CanSM_MemMap.h"
VAR(CanSM_NeworkInfoType, CANSM_VAR)  CanSM_NetworkInfo[CANSM_MAX_NETWORK_NUM];
#define CANSM_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "CanSM_MemMap.h"
#define CANSM_START_SEC_CONFIG_DATA
#include "CanSM_MemMap.h"
CONST(uint8, CANSM_CONST) CanSM_NumOfNetwork = CANSM_MAX_NETWORK_NUM;
#define CANSM_STOP_SEC_CONFIG_DATA
#include "CanSM_MemMap.h"


