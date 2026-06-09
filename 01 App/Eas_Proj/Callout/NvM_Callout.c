/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : NvM_Callout.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : NvM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : NvM module configuration File
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
/*PRQA S 857 EOF*/
/*
Number of macro definitions exceeds 1024 -program does not conform strictly to ISO:C90.
*/

/*PRQA S 3214 EOF*/
/*
The macro 'XXX_SEC_CODE' is not used and could be removed.
*/

/*PRQA S 5087 EOF*/
/*
Use of #include directive after code fragment.
*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Rte_NvM.h"
/*NvM_Callout.c Header File User Code start*/

/*NvM_Callout.c Header File User Code end*/
/*******************************************************************************
*   Callout declare
*******************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

  
  
#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"




