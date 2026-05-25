/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dcm_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Dcm module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Dcm module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/

/*PRQA S 776,778,779 EOF*/
/*
Names in this file may not follow relevant rules.
*/

#ifndef DCM_LCFG_H
#define DCM_LCFG_H
/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dcm_Types.h"
/********************************************************************************
* Macro definition
********************************************************************************/

#define DCM_DEFAULT_MASK                                    (Dcm_SessionMaskType)0x00000001
#define DCM_PROGRAMMING_MASK                                (Dcm_SessionMaskType)0x00000002
#define DCM_EXTENDED_MASK                                   (Dcm_SessionMaskType)0x00000004

#define DCM_LOCKED_MASK                                     (Dcm_SecurityMaskType)0x00000001
#define DCM_L2_MASK                                         (Dcm_SecurityMaskType)0x00000002
#define DCM_ALL_MASK                                        0xFFFFFFFF
/*******************************************************************************
* Configuration
*******************************************************************************/
#define DCM_START_SEC_CONFIG_DATA
#include "Dcm_MemMap.h"
extern CONST(uint8, DCM_CONST) Dcm_RxPduToProtocolMap[DCM_CFG_RXPDU_NUM];
#define DCM_STOP_SEC_CONFIG_DATA
#include "Dcm_MemMap.h"

#define DCM_START_SEC_VAR_CLEARED_LOCAL_16
#include "Dcm_MemMap.h"
extern VAR(uint16, DCM_VAR) Dcm_DidIndexList[1];
#define DCM_STOP_SEC_VAR_CLEARED_LOCAL_16
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONFIG_DATA
#include "Dcm_MemMap.h"
extern CONST(Dcm_DsdServiceTableType, DCM_CONST) Dcm_DsdServiceTable[DCM_CFG_NUM_OF_STAB];
extern CONST(Dcm_DslProtocolRowType, DCM_CONST) Dcm_DslProtocolRow[DCM_CFG_NUM_OF_PROTOCOL];


extern CONST(Dcm_DspSessionType, DCM_CONST) Dcm_DspSession[DCM_CFG_NUM_OF_STAB];
extern CONST(Dcm_DspSecurityType, DCM_CONST) Dcm_DspSecurity[DCM_CFG_NUM_OF_STAB];
extern CONST(Dcm_DspDataType, DCM_CONST) Dcm_DspData[DCM_CFG_NUM_OF_STAB];
extern CONST(Dcm_DspDidType, DCM_CONST) Dcm_DspDid[DCM_CFG_NUM_OF_STAB];
extern CONST(Dcm_DspComControlType, DCM_CONST) Dcm_DspComControl[DCM_CFG_NUM_OF_STAB];
extern CONST(Dcm_DspRoutineType, DCM_CONST) Dcm_DspRoutine[DCM_CFG_NUM_OF_STAB];
extern CONST(Dcm_DspEcuResetType, DCM_CONST) Dcm_DspEcuReset[DCM_CFG_NUM_OF_STAB];
#define DCM_STOP_SEC_CONFIG_DATA
#include "Dcm_MemMap.h"

#endif


