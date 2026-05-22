/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : BswM_PBcfg.h
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
#ifndef BSWM_PBCFG_H
#define BSWM_PBCFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/

#include "BswM_Types.h"



/*******************************************************************************
*   PostBuild Config
*******************************************************************************/

#define BSWM_START_SEC_CONFIG_DATA
#include "BswM_MemMap.h"

extern CONST(BswMActionList, BSWM_CONST) BswMAvailableActionLists[BSWM_MAX_ACTIONLIST_NUM];

extern CONST(BswM_ConfigType, BSWM_CONST) BswM_PBConfigTable[2];

#define BSWM_STOP_SEC_CONFIG_DATA
#include "BswM_MemMap.h"


#endif /* BSWM_PBCFG_H */



