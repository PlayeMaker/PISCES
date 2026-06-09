/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : PduR_Cfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : PduR module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : PduR module configuration File
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
/*PRQA S 862,3214,3614,778,779 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address 
segments in the files of each module,#include "PduR_MemMap.h" is required.Defined 
XXX_START_SEC_ will undefine in PduR_MemMap.h
*/

/*PRQA S 3132,3211,3111,2213 EOF*/
/*
Particularity of configuration files
*/

/*PRQA S 857,380 EOF*/
/*
Macro definitions exceed 1024.The number of macros is unlimited.
*/
/*PRQA S 1559 EOF*/
/*
Functions are defined in other module.
*/
/*PRQA S 1533,1531 EOF*/
/*
Variable are used in core code.
*/
/*PRQA S 2905 EOF*/
/*
Variable are used in core code.
*/
/*PRQA S 0791,0792 EOF*/
/*
Relevant names of macros may not follow relevant naming rules, 
for example:PDUR_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED, PDUR_STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
*/
/*PRQA S 3432 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no need to revise.
*/
/*PRQA S 1502 EOF*/
/*
Relevant Object may be used in the case where there are crosscore transmiting paths.
*/

/*PRQA S 674 EOF*/
/*
Initializer for pointer is of incompatible type.
*/

/*PRQA S 5087 EOF*/
/*
Use of #include directive after code fragment.
*/



/*******************************************************************************
*   Includes
*******************************************************************************/
#include "PduR_PBcfg.h"



