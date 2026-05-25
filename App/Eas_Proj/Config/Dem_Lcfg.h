/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dem_Lcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Dem module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Dem module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/
#ifndef DEM_LCFG_H
#define DEM_LCFG_H

/*******************************************************************************
*   Include files
*******************************************************************************/
#include "Dem_Types.h"

/*******************************************************************************
*   Dem Container:DemGeneral
*******************************************************************************/
#define DEM_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "Dem_MemMap.h"

extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_0;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_1;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_2;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_3;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_4;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_5;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_6;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_7;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_8;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_9;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_10;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_11;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_12;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_13;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_14;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_15;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_16;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_17;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_18;
extern VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_19;

#define DEM_STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONFIG_DATA
#include "Dem_MemMap.h"

/*DemClient*/
extern CONST(Dem_ClientType,DEM_CONST) Dem_ClientTable[DEM_NUM_OF_CLIENT];

/*DemOperationCycle*/
extern CONST(Dem_OperationCycleInfoType,DEM_CONST) Dem_OperationCycleTable[DEM_NUM_OF_OPCYCLE];
/*DemEventMemorySet*/
extern CONST(Dem_EventMemorySetType,DEM_CONST) Dem_EventMemorySetTable[DEM_NUM_OF_EVENTMEMORYSET];

/*DemEnableCondition*/
extern CONST(Dem_EnableConditionType,DEM_CONST) Dem_EnConditionTable[DEM_NUM_OF_EN_CONDITION];

/*DemEnableConditionGroup*/
extern CONST(Dem_EnableConditionGroupType,DEM_CONST) Dem_EnConditionGroupTable[DEM_NUM_OF_EN_GROUP];

/*DemNvRamBlockId*/
extern CONST(Dem_NvRamBlockIdType,DEM_CONST) Dem_NvRamBlockIdTable[DEM_NUM_OF_BLOCKID];
/*DemPrimaryMemory*/
extern CONST(Dem_PrimaryMemoryType, DEM_CONST) Dem_PrimaryMemoryParameter[DEM_NUM_OF_PRIMARYMEM];

extern CONSTP2CONST(Dem_DTCDataInfoType, AUTOMATIC, DEM_CONST) Dem_PrimaryMemoryTable[DEM_NUM_OF_EVENTMEMORYSET];

#define DEM_STOP_SEC_CONFIG_DATA
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONFIG_DATA
#include "Dem_MemMap.h"


/*DemDataElementClass*/
extern CONST(Dem_DataElementClassType,DEM_CONST) Dem_DataElementClassTable[DEM_NUM_OF_DATA];

/*DemExtendedDataClass*/
extern CONST(Dem_ExtendedDataClassType,DEM_CONST) Dem_ExtDataClassTable[DEM_NUM_OF_EXTDATACLASS];

/*DemExtendedDataRecordClass*/
extern CONST(Dem_ExtendedDataRecordClassType,DEM_CONST) Dem_ExtDataRecClassTable[DEM_NUM_OF_EXTDATAREC];

/*******************************************************************************
*   Dem Container:DemConfigSet
*******************************************************************************/

/*DemDTCAttributes*/
extern CONST(Dem_DTCAttributesType,DEM_CONST) Dem_DTCAttributesTable[DEM_NUM_OF_DTCATB];

/*DemDebounceTimeBaseClass*/
extern CONST(Dem_DebounceTimeBaseClassType,DEM_CONST) Dem_DebounceTimeBaseClassTable[DEM_NUM_OF_TIME_BASED];
#define DEM_STOP_SEC_CONFIG_DATA
#include "Dem_MemMap.h"


#endif




