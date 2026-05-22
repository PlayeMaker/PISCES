/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanTp_Cfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanTp module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanTp module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanTp_PBcfg.h"
#include "CanIf.h"
#include "PduR.h"

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 862,3214,3614 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address 
segments in the files of each module,#include "CanTp_MemMap.h" is required.Defined 
XXX_START_SEC_ will undefine in CanTp_MemMap.h
*/

/*PRQA S 3132,3211,3111,2213 EOF*/
/*
Particularity of configuration files
*/
/*PRQA S 857 EOF*/
/*
Macro definitions exceed 1024.The number of macros is unlimited.
*/

/*PRQA S 380 EOF*/
/*
Number of macro definitions exceeds 4095 -program does not conform strictly to ISO:C99.
*/

/*PRQA S 857 EOF*/
/*
Number of macro definitions exceeds 1024 -program does not conform strictly to ISO:C90.
*/

/*PRQA S 5087 EOF*/
/*
Use of #include directive after code fragment.
*/

#define CANTP_STOP_SEC_CONFIG_DATA
#include "CanTp_MemMap.h"




