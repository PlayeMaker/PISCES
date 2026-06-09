/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanSM_PBcfg.h
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
#ifndef CANSM_PBCFG_H
#define CANSM_PBCFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanSM_Types.h"

#define CANSM_START_SEC_CONFIG_DATA
#include "CanSM_MemMap.h"
extern CONST(CanSM_ConfigType, CANSM_CONST)  CanSM_CfgSet[2];

#define CANSM_STOP_SEC_CONFIG_DATA
#include "CanSM_MemMap.h"


/*******************************************************************************
*   Access
*******************************************************************************/
#define CANSM_USED_MAX_REQ_CNT          CanSM_ConfigSet->maxReqCnt
#define CANSM_USED_REQ_DURATION         CanSM_ConfigSet->reqDuration
#define CANSM_UESD_NETWORKCFG_INFO      CanSM_ConfigSet->netWorkCfg


#endif /* CANSM_PBCFG_H */


