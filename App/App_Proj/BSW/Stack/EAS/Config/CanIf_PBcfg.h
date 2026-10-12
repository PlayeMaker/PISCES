/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanIf_PBcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanIf module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanIf module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/
#ifndef CANIF_PBCFG_H
#define CANIF_PBCFG_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanIf_Types.h"

/*******************************************************************************
*   ConfigSet
*******************************************************************************/
#define CANIF_START_SEC_CONFIG_DATA
#include "CanIf_MemMap.h"

extern P2CONST(CanIf_ConfigType, CANIF_VAR_NOINIT, CANIF_CONST) CanIf_ConfigSet;
extern CONST(CanIf_ConfigType, CANIF_CONST) CanIf_InitCfgSet[2];
#define CANIF_STOP_SEC_CONFIG_DATA
#include "CanIf_MemMap.h"
/*******************************************************************************
*   Access macro
*******************************************************************************/
#define CANIF_USED_TXPDU_NUM                                CanIf_ConfigSet->NumOfTxPdu
#define CANIF_USED_RXPDU_NUM                                CanIf_ConfigSet->NumOfRxPdu
#define CANIF_USED_HTH_NUM                                  CanIf_ConfigSet->NumOfHth
#define CANIF_USED_HRH_NUM                                  CanIf_ConfigSet->NumOfHrh

#define CANIF_TXPDU_CFG_INFO                                CanIf_ConfigSet->TxPduCfg
#define CANIF_RXPDU_CFG_INFO                                CanIf_ConfigSet->RxPduCfg
#define CANIF_HTH_CFG_INFO                                  CanIf_ConfigSet->HthCfg
#define CANIF_HRH_CFG_INFO                                  CanIf_ConfigSet->HrhCfg
#endif
