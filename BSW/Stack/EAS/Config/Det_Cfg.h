/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Det_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Det module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Det module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/
#ifndef DET_CFG_H
#define DET_CFG_H
/*******************************************************************************
*   Include
*******************************************************************************/
#include "Det_Externals.h"

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 3458 EOF*/
/*
Meet the preparation requirements
*/
/*******************************************************************************
*   General
*******************************************************************************/
/*The configuration variant and version informations*/
#define DET_CONFIG_VARIANTS                                 STD_CONFIG_VARIANTS_PRECOMPILE
#define DET_VERSION_CHECK                                   STD_ON
#define DET_VERSION_INFO_API                                STD_OFF
#define DET_ERROR_LOOP                                      STD_OFF
#define DET_FORWARD_TO_DLT                                  STD_OFF
#define DET_DEBUG                                           STD_OFF


#define DET_SW_MAJOR_VERSION_CFG                            4
#define DET_SW_MINOR_VERSION_CFG                            0
#define DET_SW_PATCH_VERSION_CFG                            3
#define DET_AR_RELEASE_MAJOR_VERSION_CFG                    4
#define DET_AR_RELEASE_MINOR_VERSION_CFG                    7
#define DET_AR_RELEASE_REVISION_VERSION_CFG                 0

#endif /* DET_CFG_H */
