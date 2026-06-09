/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : PduR_Cfg.h
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

/*PRQA S 0791,0792 EOF*/
/*
Configure the relevant name of the file, not follow the relevant naming rules
*/

#ifndef PDUR_CFG_H
#define PDUR_CFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComStack_Types.h"


/*******************************************************************************
*   Common Macro
*******************************************************************************/
/*The configuration variant and version informations*/
#define PDUR_CONFIG_VARIANTS                                STD_CONFIG_VARIANTS_POSTBUILD

/*******************************************************************************
*   Non Autosar Standard
*******************************************************************************/
#define PDUR_VERSION_CHECK                                  STD_ON

/*******************************************************************************
*   PduRGeneral
*******************************************************************************/
/*ECUC_PduR_00302*/
#define PDUR_DEV_ERROR_DETECT                               STD_OFF
/*ECUC_PduR_00316*/
#define PDUR_VERSION_INFO_API                               STD_OFF
/*ECUC_PduR_00317*/
#define PDUR_ZERO_COST_OPERATION                            STD_OFF
/*ECUC_PduR_00347*/
#define PDUR_METADATA_SUPPORT                               STD_OFF
#define PDUR_TP_SUPPORT                                     STD_ON
#define PDUR_IF_SUPPORT                                     STD_ON
#define PDUR_GW_IF_SUPPORT                                  STD_OFF
#define PDUR_GW_TP_SUPPORT                                  STD_OFF
#define PDUR_PATHGROUP_SUPPORT                              STD_OFF
#define PDUR_PDU_BUFFER_SUPPORT                             STD_OFF
/* generate tool's version*/
#define PDUR_SW_MAJOR_VERSION_CFG                           4
#define PDUR_SW_MINOR_VERSION_CFG                           0
#define PDUR_SW_PATCH_VERSION_CFG                           3
#define PDUR_AR_RELEASE_MAJOR_VERSION_CFG                   4
#define PDUR_AR_RELEASE_MINOR_VERSION_CFG                   7
#define PDUR_AR_RELEASE_REVISION_VERSION_CFG                0

#endif


