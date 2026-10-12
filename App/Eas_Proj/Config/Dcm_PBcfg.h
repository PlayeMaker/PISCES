/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dcm_PBcfg.h
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

#ifndef DCM_PBCFG_H
#define DCM_PBCFG_H
/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dcm_Types.h"
/*******************************************************************************
* Configuration
*******************************************************************************/
#define DCM_START_SEC_CONFIG_DATA
#include "Dcm_MemMap.h"



extern CONST(Dcm_ConfigType, DCM_CONST) Dcm_PB_Config[2U];


#define DCM_STOP_SEC_CONFIG_DATA
#include "Dcm_MemMap.h"

#endif


