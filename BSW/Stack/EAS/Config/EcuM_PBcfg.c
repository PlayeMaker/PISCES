/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EcuM_PBcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : EcuM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : EcuM module configuration File
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
/*PRQA S 5087,3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "EcuM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in EcuM_MemMap.h
*/

/*PRQA S 857 EOF*/
/*
Macro definitions exceed 1024.The number of macros is unlimited
*/

/*PRQA S 4640 EOF*/
/*
This waring is a false position. The 'errno.h' header file will not be used by the
EcuM module.
*/

/*PRQA S 3211,3132 EOF*/
/*
Particularity of configuration files.
*/

/*PRQA S 380 EOF*/
/*
Number of macro definitions exceeds 4095 -program does not conform strictly to ISO:C99.
*/



/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EcuM.h"
#include "Rte_EcuM.h"

/*******************************************************************************
*   Local Data Declaration
*******************************************************************************/
#define ECUM_START_SEC_CONFIG_DATA
#include "EcuM_MemMap.h"

STATIC CONST(uint8, ECUM_CONST) EcuM_ConsistencyHash[ECUM_CONFIG_HASH_LEN] =
{
    (uint8)0xD0,(uint8)0x51,(uint8)0x10,(uint8)0x9B
};

#define ECUM_STOP_SEC_CONFIG_DATA
#include "EcuM_MemMap.h"


#define ECUM_START_SEC_CONFIG_DATA
#include "EcuM_MemMap.h"

STATIC CONST(EcuM_FlexModuleConfigType, ECUM_CONST) EcuM_ModuleConfig_PB0 =
{
    &BswM_PBConfigTable[0],
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
};

STATIC CONST(EcuM_FlexModuleConfigType, ECUM_CONST) EcuM_ModuleConfig_PB1 =
{
    &BswM_PBConfigTable[1],
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
};

CONST(EcuM_ConfigType, ECUM_CONST) EcuM_PostBuildConfig[2] =
{
    {
        0,
        ECUM_CONFIG_HASH_LEN,
        EcuM_ConsistencyHash,
        &EcuM_ModuleConfig_PB0,
        ECUM_SHUTDOWN_TARGET_OFF,
        (EcuM_ShutdownModeType)0,
        FALSE
    },
    {
        0,
        ECUM_CONFIG_HASH_LEN,
        EcuM_ConsistencyHash,
        &EcuM_ModuleConfig_PB1,
        ECUM_SHUTDOWN_TARGET_OFF,
        (EcuM_ShutdownModeType)0,
        FALSE
    }
};

#define ECUM_STOP_SEC_CONFIG_DATA
#include "EcuM_MemMap.h"



