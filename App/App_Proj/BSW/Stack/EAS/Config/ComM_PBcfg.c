/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : ComM_PBcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : ComM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : ComM module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/
#include "ComM_PBcfg.h"





#define COMM_START_SEC_CONFIG_DATA
#include "ComM_MemMap.h"

CONST(ComM_ConfigType, COMM_CONST) ComM_PBConfig[2] =
{
    {
        FALSE,
        {
            (uint8)0
        },
        {
            (uint8)0
        }
    },
    {
        FALSE,
        {
            (uint8)0
        },
        {
            (uint8)0
        }
    }
};

#define COMM_STOP_SEC_CONFIG_DATA
#include "ComM_MemMap.h"


