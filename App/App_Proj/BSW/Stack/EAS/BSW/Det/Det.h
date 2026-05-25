/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Det.h
********************************************************************************
*   Project/Product : AUTOSAR 4.2.2 AUTOSAR 4.7.0
*   Title           : Default Error Tracer Header File
*   Author          : Hirain
********************************************************************************
*   Description     : Includes all user relevant information for the tracing of
*                     development errors.   .
*
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

#ifndef DET_H
#define DET_H/*SWS_Det_00004 SWS_Det_00037 SWS_Det_00029 SWS_Det_00031*/
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Std_Types.h"
#include "Det_Cfg.h"
#include "Det_Version.h"
/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 792,791 EOF*/
/*
Name of macros may not follow relevant naming rules.
*/

/*PRQA S 3429,3453,3412 EOF*/
/*
The unified requirement of EAS is that the error reporting functions of Det and 
Dem moduls are accessed by macro functions.This part has been verified and has 
no problem
*/

/*PRQA S 3432 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no 
need to revise.
*/

/*PRQA S 776 EOF*/
/*
Names  in Core files may not follow relevant rules.
*/

/*******************************************************************************
*   Macro SWS_Det_00036
*******************************************************************************/
#define DET_E_PARAM_POINTER             ((uint8)1)

#define DET_E_CANNOT_REPORT             ((uint8)1)
#define DET_E_WRONG_MODULE              ((uint8)2)
#define DET_E_WRONG_INSTANCE            ((uint8)3)
#define DET_E_WRONG_API                 ((uint8)4)
#define DET_E_WRONG_ERROR               ((uint8)5)

#define DET_E_UNAVAILABLE               ((uint8)1)

/* API ID*/
#define DET_INIT_APIID                  ((uint8)0)
#define DET_REPORTERROR_APIID           ((uint8)1)
#define DET_START_APIID                 ((uint8)2)
#define DET_GETVERSION_APIID            ((uint8)3)
#define DET_REPORTRUNTIMEERROR_APIID    ((uint8)4)
#define DET_REPORTTRANSIENTERROR_APIID  ((uint8)5)


/*SWS_Det_00210*/
typedef struct
{
    uint8   unused;
} Det_ConfigType;

/*******************************************************************************
*   Global Function Declaration
*******************************************************************************/
#define DET_START_SEC_CODE
#include "Det_MemMap.h"

extern FUNC(void, DET_CODE) Det_Init
(
    P2CONST(Det_ConfigType, AUTOMATIC, DET_CONST) ConfigPtr
);
extern FUNC(Std_ReturnType, DET_CODE) Det_ReportError
(
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 ErrorId
);

extern FUNC(Std_ReturnType, DET_CODE) Det_ReportRuntimeError
(
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 ErrorId
);

extern FUNC(Std_ReturnType, DET_CODE) Det_ReportTransientError
(
    uint16 ModuleId,
    uint8 InstanceId,
    uint8 ApiId,
    uint8 FaultId
);

Std_ReturnType Det_ReportTransientFault(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 FaultId);

extern FUNC(void, DET_CODE) Det_Start(void);

#if(STD_ON == DET_VERSION_INFO_API)/*SWS_Det_00028*/
extern FUNC(void, DET_CODE) Det_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DET_APPL_DATA) VersionInfo
);
#endif

#define DET_STOP_SEC_CODE
#include "Det_MemMap.h"

#define DET_ERROR_DETECT(cond, moduleId, instanceId, apiCode, errCode) \
    if (!(cond)) \
    { \
        (void)Det_ReportError((moduleId),(instanceId),(apiCode),(errCode));\
        return ;\
    }

#define DET_ERROR_DETECT_RET(cond, moduleId, instanceId, apiCode, errCode, ret) \
    if (!(cond)) \
    { \
        (void)Det_ReportError((moduleId),(instanceId),(apiCode),(errCode));\
        return (ret);\
    }

#define DET_REPORT_ERROR(moduleId, instanceId, apiCode, errCode)  \
    (void)Det_ReportError((moduleId),(instanceId),(apiCode),(errCode))

#define DET_REPORT_RUNTIME_ERROR(moduleId, instanceId, apiCode, errCode)  \
    (void)Det_ReportRuntimeError((moduleId),(instanceId),(apiCode),(errCode))

#define DET_REPORT_TRANSIENT_ERROR(moduleId, instanceId, apiCode, errCode)  \
    (void)Det_ReportTransientError((moduleId),(instanceId),(apiCode),(errCode))

#endif/* DET_H */
