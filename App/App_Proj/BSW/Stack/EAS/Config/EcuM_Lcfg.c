/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EcuM_Lcfg.c
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
/*PRQA S 5087,3614,3214,862,3211 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "EcuM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in EcuM_MemMap.h.
Variables defined in configuration files can be used in the core file instead of this file.
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

/*PRQA S 380 EOF*/
/*
Number of macro definitions exceeds 4095 -program does not conform strictly to ISO:C99.
*/



/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EcuM.h"

/*******************************************************************************
*   Local Data Declaration
*******************************************************************************/
#define ECUM_START_SEC_CONFIG_DATA
#include "EcuM_MemMap.h"

CONST(uint8, ECUM_CONST) EcuM_ConfigConsistencyHash[ECUM_CONFIG_HASH_LEN] =
{
    (uint8)0xD0,(uint8)0x51,(uint8)0x10,(uint8)0x9B
};

#define ECUM_STOP_SEC_CONFIG_DATA
#include "EcuM_MemMap.h"



