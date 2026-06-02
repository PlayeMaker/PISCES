/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dem_Cfg.c
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

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 5087,3614,3214,862,857 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "EcuM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in EcuM_MemMap.h
*/

/*PRQA S 3206 EOF*/
/*
input parameters of functions in generated files are not used
*/

/*PRQA S 776 EOF*/
/*
Names in core files may not follow relevant rules..
*/

/*PRQA S 3211,3218,3111,2213,3132 EOF*/
/*
Unified requirements of EAS: constant shall be converted.
Allow static variables that are only used once.
Variables defined in configuration files can be used in the core file instead of this file .
*/
/*PRQA S 1751,1504,1502,1531 EOF*/
/*
Names in core files may not follow relevant rules..
*/

/*PRQA S 1533,1559 EOF*/
/*
The function definition in Rte.
*/

/*PRQA S 380 EOF*/
/*
Number of macro definitions exceeds 4095 -program does not conform strictly to ISO:C99.
*/

/*PRQA S 674 EOF*/
/*
Initializer for pointer is of incompatible type.
*/

/*PRQA S 3408 EOF*/
/*
'XXX' has external Linkage and is being defined without any previous declaration.
*/


/*******************************************************************************
*   Include files
*******************************************************************************/
#include "Dem_Lcfg.h"
#include "Rte_Dem.h"
#include "NvM_Cfg.h"

/*******************************************************************************
*   Dem Container:DemGeneral
*******************************************************************************/
#define DEM_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "Dem_MemMap.h"

VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_0;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_1;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_2;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_3;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_4;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_5;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_6;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_7;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_8;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_9;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_10;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_11;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_12;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_13;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_14;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_15;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_16;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_17;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_18;
VAR(Dem_DTCDataEntryType, DEM_VAR) PrimaryDataEntry_0_19;

#define DEM_STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONFIG_DATA
#include "Dem_MemMap.h"


/*DemOperationCycle*/
CONST(Dem_OperationCycleInfoType, DEM_CONST) Dem_OperationCycleTable[DEM_NUM_OF_OPCYCLE] =
{
    {Dem_OpCycle_OperationCycle_DEM_IGNITION, (uint8)0xFF},
    {Dem_OpCycle_OperationCycle_DEM_WARMUP, (uint8)0xFF}
};

/*DemEnableCondition*/
CONST(Dem_EnableConditionType, DEM_CONST) Dem_EnConditionTable[DEM_NUM_OF_EN_CONDITION] =
{
    {(uint8)0, FALSE},
    {(uint8)1, FALSE},
    {(uint8)2, FALSE},
    {(uint8)3, FALSE},
    {(uint8)4, FALSE},
    {(uint8)5, FALSE},
    {(uint8)6, FALSE},
    {(uint8)7, FALSE},
    {(uint8)8, FALSE},
    {(uint8)9, FALSE},
    {(uint8)10, FALSE},
    {(uint8)11, FALSE}
};

/*DemEnableConditionGroup*/
STATIC CONST(uint8, DEM_CONST) Dem_EnableConditionRef_Array_0[2] = {(uint8)0, (uint8)1};
STATIC CONST(uint8, DEM_CONST) Dem_EnableConditionRef_Array_1[1] = {(uint8)2};
STATIC CONST(uint8, DEM_CONST) Dem_EnableConditionRef_Array_2[3] = {(uint8)0, (uint8)6, (uint8)4};
STATIC CONST(uint8, DEM_CONST) Dem_EnableConditionRef_Array_3[2] = {(uint8)7, (uint8)10};
STATIC CONST(uint8, DEM_CONST) Dem_EnableConditionRef_Array_4[2] = {(uint8)8, (uint8)10};
STATIC CONST(uint8, DEM_CONST) Dem_EnableConditionRef_Array_5[2] = {(uint8)9, (uint8)10};
STATIC CONST(uint8, DEM_CONST) Dem_EnableConditionRef_Array_6[1] = {(uint8)10};
STATIC CONST(uint8, DEM_CONST) Dem_EnableConditionRef_Array_7[2] = {(uint8)10, (uint8)11};
STATIC CONST(uint8, DEM_CONST) Dem_EnableConditionRef_Array_8[4] = {(uint8)0, (uint8)3, (uint8)4, (uint8)5};
CONST(Dem_EnableConditionGroupType, DEM_CONST) Dem_EnConditionGroupTable[DEM_NUM_OF_EN_GROUP] =
{
    {(uint8)2, Dem_EnableConditionRef_Array_0},
    {(uint8)1, Dem_EnableConditionRef_Array_1},
    {(uint8)3, Dem_EnableConditionRef_Array_2},
    {(uint8)2, Dem_EnableConditionRef_Array_3},
    {(uint8)2, Dem_EnableConditionRef_Array_4},
    {(uint8)2, Dem_EnableConditionRef_Array_5},
    {(uint8)1, Dem_EnableConditionRef_Array_6},
    {(uint8)2, Dem_EnableConditionRef_Array_7},
    {(uint8)4, Dem_EnableConditionRef_Array_8}
};

/*DemNvRamBlockId*/
CONST(Dem_NvRamBlockIdType, DEM_CONST) Dem_NvRamBlockIdTable[DEM_NUM_OF_BLOCKID] =
{
    {NvM_NVM_Dem_StorageMem}
};

/*DemEventMemorySet*/
CONST(Dem_EventMemorySetType,DEM_CONST) Dem_EventMemorySetTable[DEM_NUM_OF_EVENTMEMORYSET] =
{
    {
        (uint8)0,
        DEM_DTC_TRANSLATION_ISO14229_1,
        (uint8)0xFF,
        (uint8)0xFF,
        (uint8)0xFF,
        (uint8)0xFF,
        NULL_PTR,
        START
    }
};

/*DemPrimaryMemory*/
CONST(Dem_PrimaryMemoryType, DEM_CONST) Dem_PrimaryMemoryParameter[DEM_NUM_OF_PRIMARYMEM] =
{
    {
        (uint8)0x9,
        DEM_DISPLACEMENT_NONE,
        DEM_TRIGGER_ON_TEST_FAILED,
        (uint8)20,
        DEM_PROCESS_OCCCTR_TF,
        DEM_FF_RECNUM_CONFIGURED
    }
};


STATIC CONST(Dem_DTCDataInfoType, DEM_CONST) Dem_PrimaryDataEntry0[20] =
{
    {&PrimaryDataEntry_0_0, NvM_NVM_PrimaryDataEntry_0_0},
    {&PrimaryDataEntry_0_1, NvM_NVM_PrimaryDataEntry_0_1},
    {&PrimaryDataEntry_0_2, NvM_NVM_PrimaryDataEntry_0_2},
    {&PrimaryDataEntry_0_3, NvM_NVM_PrimaryDataEntry_0_3},
    {&PrimaryDataEntry_0_4, NvM_NVM_PrimaryDataEntry_0_4},
    {&PrimaryDataEntry_0_5, NvM_NVM_PrimaryDataEntry_0_5},
    {&PrimaryDataEntry_0_6, NvM_NVM_PrimaryDataEntry_0_6},
    {&PrimaryDataEntry_0_7, NvM_NVM_PrimaryDataEntry_0_7},
    {&PrimaryDataEntry_0_8, NvM_NVM_PrimaryDataEntry_0_8},
    {&PrimaryDataEntry_0_9, NvM_NVM_PrimaryDataEntry_0_9},
    {&PrimaryDataEntry_0_10, NvM_NVM_PrimaryDataEntry_0_10},
    {&PrimaryDataEntry_0_11, NvM_NVM_PrimaryDataEntry_0_11},
    {&PrimaryDataEntry_0_12, NvM_NVM_PrimaryDataEntry_0_12},
    {&PrimaryDataEntry_0_13, NvM_NVM_PrimaryDataEntry_0_13},
    {&PrimaryDataEntry_0_14, NvM_NVM_PrimaryDataEntry_0_14},
    {&PrimaryDataEntry_0_15, NvM_NVM_PrimaryDataEntry_0_15},
    {&PrimaryDataEntry_0_16, NvM_NVM_PrimaryDataEntry_0_16},
    {&PrimaryDataEntry_0_17, NvM_NVM_PrimaryDataEntry_0_17},
    {&PrimaryDataEntry_0_18, NvM_NVM_PrimaryDataEntry_0_18},
    {&PrimaryDataEntry_0_19, NvM_NVM_PrimaryDataEntry_0_19}
};

CONSTP2CONST(Dem_DTCDataInfoType, AUTOMATIC, DEM_CONST) Dem_PrimaryMemoryTable[DEM_NUM_OF_EVENTMEMORYSET] =
{
    Dem_PrimaryDataEntry0
};

/*DemClient*/
CONST(Dem_ClientType, DEM_CONST) Dem_ClientTable[DEM_NUM_OF_CLIENT]=
{
    {(uint8)0,DEM_CLIENT_USES_FULL_FUNCTIONALITY,TRUE,Dem_EventMemory_Set0,NULL_PTR}
};

#define DEM_STOP_SEC_CONFIG_DATA
#include "Dem_MemMap.h"


#define DEM_START_SEC_CONFIG_DATA
#include "Dem_MemMap.h"


/*DemDataElementClass*/
STATIC CONST(Dem_InternalDataElementClassType, DEM_CONST) Dem_IntDataElement_0 =
{
    (uint8)1, DEM_OCCCTR
};
CONST(Dem_ExternalCSDataElementClassType, DEM_CONST) Dem_CSDataElement_0 =
{
    (uint8)1, &Dem_Rte_DataElement1_Year_ReadDataElement, TRUE
};
CONST(Dem_ExternalCSDataElementClassType, DEM_CONST) Dem_CSDataElement_1 =
{
    (uint8)1, &Dem_Rte_DataElement2_Month_ReadDataElement, TRUE
};
CONST(Dem_ExternalCSDataElementClassType, DEM_CONST) Dem_CSDataElement_2 =
{
    (uint8)1, &Dem_Rte_DataElement3_Day_ReadDataElement, TRUE
};
CONST(Dem_ExternalCSDataElementClassType, DEM_CONST) Dem_CSDataElement_3 =
{
    (uint8)1, &Dem_Rte_DataElement4_Hour_ReadDataElement, TRUE
};
CONST(Dem_ExternalCSDataElementClassType, DEM_CONST) Dem_CSDataElement_4 =
{
    (uint8)1, &Dem_Rte_DataElement5_Minute_ReadDataElement, TRUE
};
CONST(Dem_ExternalCSDataElementClassType, DEM_CONST) Dem_CSDataElement_5 =
{
    (uint8)1, &Dem_Rte_DataElement6_Second_ReadDataElement, TRUE
};
CONST(Dem_ExternalCSDataElementClassType, DEM_CONST) Dem_CSDataElement_6 =
{
    (uint8)3, &Dem_Rte_DataElement7_Odometer_ReadDataElement, TRUE
};
CONST(Dem_ExternalCSDataElementClassType, DEM_CONST) Dem_CSDataElement_7 =
{
    (uint8)1, &Dem_Rte_DataElement8_LV_Battery_Voltage_ReadDataElement, TRUE
};
CONST(Dem_ExternalCSDataElementClassType, DEM_CONST) Dem_CSDataElement_8 =
{
    (uint8)2, &Dem_Rte_DataElement9_VehicleSpeed_ReadDataElement, TRUE
};
CONST(Dem_DataElementClassType, DEM_CONST) Dem_DataElementClassTable[DEM_NUM_OF_DATA] =
{
    {
        &Dem_IntDataElement_0,
        NULL_PTR
    },
    {
        NULL_PTR,
        &Dem_CSDataElement_0
    },
    {
        NULL_PTR,
        &Dem_CSDataElement_1
    },
    {
        NULL_PTR,
        &Dem_CSDataElement_2
    },
    {
        NULL_PTR,
        &Dem_CSDataElement_3
    },
    {
        NULL_PTR,
        &Dem_CSDataElement_4
    },
    {
        NULL_PTR,
        &Dem_CSDataElement_5
    },
    {
        NULL_PTR,
        &Dem_CSDataElement_6
    },
    {
        NULL_PTR,
        &Dem_CSDataElement_7
    },
    {
        NULL_PTR,
        &Dem_CSDataElement_8
    }
};

#define DEM_STOP_SEC_CONFIG_DATA
#include "Dem_MemMap.h"


#define DEM_START_SEC_CONFIG_DATA
#include "Dem_MemMap.h"

/*DemExtendedDataClass*/
STATIC CONST(uint8, DEM_CONST) Dem_ExtDataRecClassRef_Array_0[1] = {(uint8)0};

#define DEM_STOP_SEC_CONFIG_DATA
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONFIG_DATA
#include "Dem_MemMap.h"

CONST(Dem_ExtendedDataClassType, DEM_CONST) Dem_ExtDataClassTable[DEM_NUM_OF_EXTDATACLASS] =
{
    {(uint8)1, Dem_ExtDataRecClassRef_Array_0}
};

#define DEM_STOP_SEC_CONFIG_DATA
#include "Dem_MemMap.h"


#define DEM_START_SEC_CONFIG_DATA
#include "Dem_MemMap.h"

/*DemExtendedDataRecordClass*/
STATIC CONST(uint16, DEM_CONST) Dem_ExtDataElementClassRef_Array_0[10] = {(uint16)0, (uint16)1, (uint16)2, (uint16)3, (uint16)4, (uint16)5, (uint16)6, (uint16)7, (uint16)8, (uint16)9};

#define DEM_STOP_SEC_CONFIG_DATA
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONFIG_DATA
#include "Dem_MemMap.h"

CONST(Dem_ExtendedDataRecordClassType, DEM_CONST) Dem_ExtDataRecClassTable[DEM_NUM_OF_EXTDATAREC] =
{
    {
        (uint8)10,
        Dem_ExtDataElementClassRef_Array_0,
        (uint8)0x1,
        DEM_TRIGGER_ON_CONFIRMED,
        DEM_UPDATE_RECORD_NO
    }
};

#define DEM_STOP_SEC_CONFIG_DATA
#include "Dem_MemMap.h"


#define DEM_START_SEC_CONFIG_DATA
#include "Dem_MemMap.h"


/*******************************************************************************
*   Dem Container:DemConfigSet
*******************************************************************************/

#define DEM_STOP_SEC_CONFIG_DATA
#include "Dem_MemMap.h"


#define DEM_START_SEC_CONFIG_DATA
#include "Dem_MemMap.h"

/*DemDTCAttributes*/
STATIC CONST(uint8, DEM_CONST) Dem_ExtDataClassRef_0 = (uint8)0;
STATIC CONST(uint8, DEM_CONST) Dem_ExtDataClassRef_1 = (uint8)0;


#define DEM_STOP_SEC_CONFIG_DATA
#include "Dem_MemMap.h"

#define DEM_START_SEC_CONFIG_DATA
#include "Dem_MemMap.h"


CONST(Dem_DTCAttributesType, DEM_CONST) Dem_DTCAttributesTable[DEM_NUM_OF_DTCATB] =
{
    {
        (uint8)40,
        (uint8)1,
        (uint8)0,
        (Dem_PriorityType)1,
        DEM_EVENT_SIGNIFICANCE_FAULT,
        &Dem_ExtDataClassRef_0,
        NULL_PTR,
        (uint8)0,
        (uint8)0,
        (uint16)0x001F
    },
    {
        (uint8)40,
        (uint8)1,
        (uint8)1,
        (Dem_PriorityType)1,
        DEM_EVENT_SIGNIFICANCE_FAULT,
        &Dem_ExtDataClassRef_1,
        NULL_PTR,
        (uint8)0,
        (uint8)0,
        (uint16)0x001F
    }
};

#define DEM_STOP_SEC_CONFIG_DATA
#include "Dem_MemMap.h"


#define DEM_START_SEC_CONFIG_DATA
#include "Dem_MemMap.h"


/*DemDebounceTimeBaseClass*/
CONST(Dem_DebounceTimeBaseClassType, DEM_CONST) Dem_DebounceTimeBaseClassTable[DEM_NUM_OF_TIME_BASED] =
{
    {
        DEM_DEBOUNCE_FREEZE,
        (uint32)10,
        (uint32)250
    },
    {
        DEM_DEBOUNCE_FREEZE,
        (uint32)1000,
        (uint32)1000
    },
    {
        DEM_DEBOUNCE_FREEZE,
        (uint32)10,
        (uint32)1000
    },
    {
        DEM_DEBOUNCE_FREEZE,
        (uint32)2000,
        (uint32)1000
    },
    {
        DEM_DEBOUNCE_FREEZE,
        (uint32)2000,
        (uint32)40000
    },
    {
        DEM_DEBOUNCE_FREEZE,
        (uint32)2000,
        (uint32)10
    }
};

#define DEM_STOP_SEC_CONFIG_DATA
#include "Dem_MemMap.h"





