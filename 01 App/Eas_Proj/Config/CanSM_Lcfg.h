/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanSM_Lcfg.h
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
/*PRQA S 776 EOF*/
/*
Names in core files may not follow relevant rules..
*/

#ifndef CANSM_LCFG_H
#define CANSM_LCFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/

#include "CanSM_Types.h"
#define CANSM_START_SEC_VAR_CLEARED_LOCAL_8
#include "CanSM_MemMap.h"
extern VAR(uint8, CANSM_VAR)  CanSM_TriggerInfo[CANSM_MAX_NETWORK_NUM];
#define CANSM_STOP_SEC_VAR_CLEARED_LOCAL_8
#include "CanSM_MemMap.h"

#define CANSM_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "CanSM_MemMap.h"
extern VAR(CanSM_NeworkInfoType, CANSM_VAR)  CanSM_NetworkInfo[CANSM_MAX_NETWORK_NUM];
#define CANSM_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "CanSM_MemMap.h"
#define CANSM_START_SEC_CONFIG_DATA
#include "CanSM_MemMap.h"
extern CONST(uint8, CANSM_CONST) CanSM_NumOfNetwork;
#define CANSM_STOP_SEC_CONFIG_DATA
#include "CanSM_MemMap.h"

/*******************************************************************************
*   Access 
*******************************************************************************/
#define CANSM_USED_NETWORK_NUM          CanSM_NumOfNetwork

#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.h"
extern FUNC(void, CANSM_CODE) CanSM_EnterBorL1_Indication
(
    NetworkHandleType Channel
);

extern FUNC(void, CANSM_CODE) CanSM_EnterBorL2_Indication
(
    NetworkHandleType Channel
);

extern FUNC(void, CANSM_CODE) CanSM_BORSuccess_Indication
(
    NetworkHandleType Channel
);

extern FUNC(void, CANSM_CODE) CanSM_BusOff_Indication
(
    uint8 ControllerId
);

#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.h"
#endif /* CANSM_LCFG_H */


