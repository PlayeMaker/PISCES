/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : NvM_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : NvM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : NvM module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/


#ifndef NVM_LCFG_H
#define NVM_LCFG_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "NvM_Types.h"
#include "MemIf.h"


/*******************************************************************************
*   Global Vars
*******************************************************************************/
#define NVM_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "NvM_MemMap.h"
extern VAR(NvM_RamBlock_Type, NVM_VAR_NOINIT)  NvM_AdmBlock[23];
extern VAR(NvM_QueBuf_Type, NVM_VAR_NOINIT) NvM_QueBuf[10];
#define NVM_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_LOCAL_8
#include "NvM_MemMap.h"


#define NVM_STOP_SEC_VAR_CLEARED_LOCAL_8
#include "NvM_MemMap.h"
/*******************************************************************************
*   Config parameters
*******************************************************************************/
#define NVM_START_SEC_CONFIG_DATA
#include "NvM_MemMap.h"
extern CONST(uint8, NVM_CONST) NvM_CompiledConfigId[2];
#define NVM_STOP_SEC_CONFIG_DATA
#include "NvM_MemMap.h"


#define NVM_START_SEC_CONFIG_DATA
#include "NvM_MemMap.h"
extern CONST(NvM_BlockConfigType, NVM_CONST) NvM_Config[23];
extern CONST(NvM_SingleCallBackFun, NVM_CONST) NvM_SingleCallBackFunPtr[23];
extern CONST(NvM_InitBlockCallBackFun, NVM_CONST) NvM_InitBlockCallBackFunPtr[23];
extern CONST(NvM_MultiCallBackFun, NVM_CONST) NvM_MultiCallBackFunPtr;
#define NVM_STOP_SEC_CONFIG_DATA
#include "NvM_MemMap.h"
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

/*******************************************************************************
*   Callout declare
*******************************************************************************/
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

/*******************************************************************************
*   Access
*******************************************************************************/

#endif /* #ifndef NVM_LCFG_H */

