/*BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dem_NvM.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : Dem_NvM.h
*   Author          : Hirain
********************************************************************************
*   Description: for Dem APIs used by the NvM exclusively.
*
********************************************************************************
*   Limitations:
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
*END_FILE_HDR*/

/*PRQA S 776 EOF*/
/*
Names in core files may not follow relevant rules..
*/

#ifndef DEM_NVM_H
#define DEM_NVM_H

/*******************************************************************************
* Include files
*******************************************************************************/
#include "Std_Types.h"
#include "Dem_Types.h"
#include "Dem_Version.h"

/*******************************************************************************
* Global Function Prototype
*******************************************************************************/

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"


extern FUNC(Std_ReturnType, DEM_CODE) Dem_NvM_InitStorageMem
(
    void
);

#if(STD_ON == DEM_NVM_SUPPORT)
extern FUNC(Std_ReturnType, DEM_CODE) Dem_NvM_JobResultInd
(
    uint8 ServiceId,
    NvM_RequestResultType JobResult
);
#endif

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif /* DEM_NVM_H */



