/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : EcuM_Version.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : EcuM_Version.h
*   Author          : Hirain
********************************************************************************
*   Description     : EcuM_Version.h
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 791,792 EOF*/
/*
Names core in configuration files may not follow relevant rules.
*/

#ifndef ECUM_VERSION_H
#define ECUM_VERSION_H

#define ECUM_VENDOR_ID                   STD_HIRAIN_VENDOR_ID
#define ECUM_MODULE_ID                   ((uint16)10)
#define ECUM_INSTANCE_ID                 ((uint8)0)
#define ECUM_SW_MAJOR_VERSION            (4)
#define ECUM_SW_MINOR_VERSION            (0)
#define ECUM_SW_PATCH_VERSION            (6)
#define ECUM_SW_DEV_PHASE                (0)

#define ECUM_AR_RELEASE_MAJOR_VERSION    (4)

#define ECUM_AR_RELEASE_MINOR_VERSION_422    (2)
#define ECUM_AR_RELEASE_REVISION_VERSION_422 (2)

#define ECUM_AR_RELEASE_MINOR_VERSION_431    (3)
#define ECUM_AR_RELEASE_REVISION_VERSION_431 (1)

#define ECUM_AR_RELEASE_MINOR_VERSION_440    (4)
#define ECUM_AR_RELEASE_REVISION_VERSION_440 (0)

#define ECUM_AR_RELEASE_MINOR_VERSION_470    (7)
#define ECUM_AR_RELEASE_REVISION_VERSION_470 (0)

#endif/* ECUM_VERSION_H */

