/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_BswM.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Rte module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Rte module configuration File
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
/*PRQA S 3432 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no
need to revise.
*/

/*PRQA S 776,777,778,779,791,792 EOF*/
/*
Names in this file may not follow relevant rules.
*/

/*PRQA S 3453,3429,1753 EOF*/
/*
A function-like macro is being defined. But this form is prescribed by autosar.
*/

/*PRQA S 5087 EOF*/
/*
Use of #include directive after code fragment.
*/


#ifndef RTE_BSWM_H
#define RTE_BSWM_H

#ifndef RTE_CORE
#ifdef RTE_APPLICATION_HEADER_FILE
#error Multiple application header files included.
#endif /* RTE_APPLICATION_HEADER_FILE */
#define RTE_APPLICATION_HEADER_FILE
#endif
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "BswM.h"
#include "Rte_BswM_Type.h"

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif  /*RTE_BSWM_H*/


