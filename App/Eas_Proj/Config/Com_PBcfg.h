/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Com_PBcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Com module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Com module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/
#ifndef COM_PBCFG_H
#define COM_PBCFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Com_Types.h"

#include "Com_Lcfg.h"


/*******************************************************************************
*   ConfigSet
*******************************************************************************/

#define COM_START_SEC_CONFIG_DATA
#include "Com_MemMap.h"

extern CONST(Com_ConfigType, CANIF_CONST) Com_InitCfgSet[2];

#define COM_STOP_SEC_CONFIG_DATA
#include "Com_MemMap.h"


 /*******************************************************************************
*   Access macro
*******************************************************************************/
#define COM_CFG_RXPDU_INFO                 Com_PBConfig->RxPduCfg
#define COM_CFG_RXSIG_INFO                 Com_PBConfig->RxSigCfg
#define COM_CFG_TXSIG_GROUP_INFO           Com_PBConfig->TxSignalGroupCfg
#define COM_CFG_RXSIG_GROUP_INFO           Com_PBConfig->RxSignalGroupCfg

#define COM_CFG_TXPDU_INFO                 Com_PBConfig->TxPduCfg
#define COM_CFG_TXSIG_INFO                 Com_PBConfig->TxSigCfg

#define COM_CFG_PDU_GROUP_INFO             Com_PBConfig->PduGroupCfg
#define COM_CFG_GWSIG_INFO                 Com_PBConfig->GWSigCfg

#define COM_RXPDU_NUM                      Com_PBConfig->RxPduNum
#define COM_RXSIG_NUM                      Com_PBConfig->RxSigNum
#define COM_TXPDU_NUM                      Com_PBConfig->TxPduNum
#define COM_TXSIG_NUM                      Com_PBConfig->TxSigNum
#define COM_TXSIG_GROUP_NUM                Com_PBConfig->TxSigGrpNum
#define COM_RXSIG_GROUP_NUM                Com_PBConfig->RxSigGrpNum
#define COM_PDU_GROUP_NUM                  Com_PBConfig->PduGroupNum
#define COM_GWSIG_NUM                      Com_PBConfig->GWSigNum
#define COM_PBCONFIGID                     Com_PBConfig->PBConfigId
#endif


