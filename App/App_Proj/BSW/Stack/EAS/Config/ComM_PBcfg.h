/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : ComM_PBcfg.h
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
#ifndef COMM_PBCFG_H
#define COMM_PBCFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComM_Cfg.h"


/*SWS_ComM_00162*/
typedef struct
{
    /*SWS_ComM_00911*//*ECUC_ComM_00878*/
    boolean ComMPncEnabled;
    /*ECUC_ComM_00876 User mapping to Pnc*/
    uint8 ComMUserMappingPncStart[COMM_NUM_OF_USER];
    uint8 ComMUserMappingPncNum[COMM_NUM_OF_USER];
} ComM_ConfigType;



#define COMM_START_SEC_CONFIG_DATA
#include "ComM_MemMap.h"

extern CONST(ComM_ConfigType, COMM_CONST) ComM_PBConfig[2];

#define COMM_STOP_SEC_CONFIG_DATA
#include "ComM_MemMap.h"




#endif/* COMM_PBCFG_H */




