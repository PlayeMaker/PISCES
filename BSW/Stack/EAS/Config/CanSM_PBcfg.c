/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanSM_PBcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanSM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanSM module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/

/*PRQA S 553 EOF*/
/*
Empty files.
*/


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanSM.h"

#define CANSM_START_SEC_CONFIG_DATA
#include "CanSM_MemMap.h"
static CONST(CanSM_NetworkCfgType, CANSM_CONST)  CanSM_NetworkCfg_0[1] =
{
    {
        CanIf_CanIf_BODY_LE1_CAN,ComM_ComM_BODY_LE1_CAN,(uint8)5,(uint16)10,(uint16)200,TRUE,(uint16)20,
    }/*CanSM_BODY_LE1_CAN*/
};
static CONST(CanSM_NetworkCfgType, CANSM_CONST)  CanSM_NetworkCfg_1[1] =
{
    {
        CanIf_CanIf_BODY_LE1_CAN,ComM_ComM_BODY_LE1_CAN,(uint8)5,(uint16)10,(uint16)200,TRUE,(uint16)20,
    }/*CanSM_BODY_LE1_CAN*/
};
CONST(CanSM_ConfigType, CANSM_CONST)  CanSM_CfgSet[2] =
{
    {1, 2, CanSM_NetworkCfg_0},/*Cfg_D*/
    {1, 2, CanSM_NetworkCfg_1}/*Cfg_P*/
};
#define CANSM_STOP_SEC_CONFIG_DATA
#include "CanSM_MemMap.h"

