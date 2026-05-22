/*BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dem_Dcm.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : Dem_Dcm.h
*   Author          : Hirain
********************************************************************************
*   Description: for Dem APIs used by the Dcm exclusively.
*
********************************************************************************
*   Limitations:
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
*END_FILE_HDR*/

/*PRQA S 776 EOF*/
/*
Names in core files may not follow relevant rules..
*/


#ifndef DEM_DCM_H
#define DEM_DCM_H

/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dem_Types.h"
#include "Dem_Version.h"
#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))
#include "Dcm_Types.h"
#endif

/*******************************************************************************
* Global Function Prototype
*******************************************************************************/

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

/*SWS_Dem_00230*/
extern FUNC(Dem_DTCTranslationFormatType, DEM_CODE) Dem_GetTranslationType
(
    uint8 ClientId
);
/*SWS_Dem_00213*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCStatusAvailabilityMask
(
    uint8 ClientId,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatusMask,
    Dem_DTCOriginType DTCOrigin
);
/*SWS_Dem_00212*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetStatusOfDTC
(
    uint8 ClientId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCStatus
);
/*SWS_Dem_00232*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetSeverityOfDTC
(
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity,
    uint8 ClientId
);
/*SWS_Dem_00594*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetFunctionalUnitOfDTC
(
    uint8 ClientId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit
);
/*SWS_Dem_00208*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTCFilter
(
    uint8 ClientId,
    Dem_UdsStatusByteType DTCStatusMask,
    Dem_DTCFormatType DTCFormat,
    Dem_DTCOriginType DTCOrigin,
    boolean FilterWithSeverity,
    Dem_DTCSeverityType DTCSeverityMask,
    boolean FilterForFaultDetectionCounter/*no use*/
);
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTCFilterByExtendedDataRecordNumber
(
    uint8 ClientId,
    Dem_DTCFormatType DTCFormat,
    uint8 ExtendedDataRecordNumber
);

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTCFilterByReadinessGroup
(
    uint8 ClientId,
    Dem_DTCFormatType DTCFormat,
    Dem_EventOBDReadinessGroupType ReadinessGroupNumber
);
/*SWS_Dem_00214*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetNumberOfFilteredDTC
(
    uint8 ClientId,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) NumberOfFilteredDTC
);
/*SWS_Dem_00215*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetNextFilteredDTC
(
    uint8 ClientId,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatus
);
/*SWS_Dem_00227*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetNextFilteredDTCAndFDC
(
    uint8 ClientId,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) DTCFaultDetectionCounter
);
/*SWS_Dem_00281*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetNextFilteredDTCAndSeverity
(
    uint8 ClientId,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) DTCStatus,
    P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_APPL_DATA) DTCSeverity,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DTCFunctionalUnit
);
/*SWS_Dem_00209*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetFreezeFrameRecordFilter
(
    uint8 ClientId,
    Dem_DTCFormatType DTCFormat
);
/*SWS_Dem_00224*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetNextFilteredRecord
(
    uint8 ClientId,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) RecordNumber
);
/*SWS_Dem_00218*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCByOccurrenceTime
(
    uint8 ClientId,
    Dem_DTCRequestType DTCRequest,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC
);

/*SWS_Dem_00233*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DisableDTCRecordUpdate
(
    uint8 ClientId
);
/*SWS_Dem_00234*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EnableDTCRecordUpdate
(
    uint8 ClientId
);
/*SWS_Dem_00236*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetNextFreezeFrameData
(
    uint8 ClientId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
/*SWS_Dem_00238*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetSizeOfFreezeFrameSelection
(
    uint8 ClientId,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) SizeOfFreezeFrame
);
/*SWS_Dem_00239*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetNextExtendedDataRecord
(
    uint8 ClientId,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);
/*SWS_Dem_00240*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetSizeOfExtendedDataRecordSelection
(
    uint8 ClientId,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) SizeOfExtendedDataRecord
);

/*SWS_Dem_00241*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ClearDTC
(
    uint8 ClientId
);
/*SWS_Dem_00242*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DisableDTCSetting
(
    uint8 ClientId
);
/*SWS_Dem_00243*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_EnableDTCSetting
(
    uint8 ClientId
);




#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))

#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_SPARK)
/*SWS_Dem_00316*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue08
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata08BufferSize
);
#endif

#if(DEM_CFG_OBD_ENGINE_TYPE == DEM_IGNITION_COMPRESSION)
/*SWS_Dem_00317*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetInfoTypeValue0B
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0B,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) Iumprdata0BBufferSize
);
#endif

/*SWS_Dem_00318*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID01
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID01value
);

/*SWS_Dem_00325*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID1C
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID1Cvalue
);

/*SWS_Dem_00319*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID21
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID21value
);

/*SWS_Dem_00320*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID30
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID30value
);

/*SWS_Dem_00321*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID31
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID31value
);

/*SWS_Dem_00322*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID41
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID41value
);

/*SWS_Dem_00323*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4D
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Dvalue
);

/*SWS_Dem_00324*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4E
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID4Evalue
);

/*SWS_Dem_01187*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID91
(
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) PID91value
);

/*SWS_Dem_00327*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfOBDFreezeFrame
(
    uint8 PID,
    uint8 DataElementIndexOfPID,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) BufSize
);

/*SWS_Dem_00624*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTCOfOBDFreezeFrame
(
    uint8 FrameNumber,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTC,
    Dem_DTCFormatType DTCFormat
);

/*SWS_Dem_00766*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetAvailableOBDMIDs
(
    uint8 Obdmid,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) Obdmidvalue
);

/*SWS_Dem_00767*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetNumTIDsOfOBDMID
(
    uint8 Obdmid,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) numberOfTIDs
);

/*SWS_Dem_00768*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTRData
(
    uint8 Obdmid,
    uint8 TIDindex,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) TIDvalue,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) UaSID,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Testvalue,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Lowlimvalue,
    P2VAR(uint16, AUTOMATIC, DEM_APPL_DATA) Upplimvalue
);

#endif/*#if((DEM_CFG_OBD_SUPPORT == DEM_OBD_MASTER_ECU)||(DEM_CFG_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU))*/

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif /* DEM_DCM_H */


