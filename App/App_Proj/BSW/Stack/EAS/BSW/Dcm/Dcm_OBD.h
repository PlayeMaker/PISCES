/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dcm_OBD.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : Dcm_OBD.h
*   Author          : Hirain
********************************************************************************
*   Description: Dcm_OBD.h
*
********************************************************************************
*   Limitations: None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/

/*PRQA S 3614 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "Dcm_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in Dcm_MemMap.h
*/

#ifndef DCM_OBD_H
#define DCM_OBD_H

/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dcm_Types.h"

/*******************************************************************************
* Macros and Typedef
*******************************************************************************/


/*******************************************************************************
* Internal Global Function Prototype
*******************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
#if((DCM_OBD_01_ENABLED == STD_ON) || (DCM_OBD_02_ENABLED == STD_ON) \
    ||(DCM_OBD_08_ENABLED == STD_ON) || (DCM_OBD_09_ENABLED == STD_ON))
extern FUNC(void, DCM_CODE) DcmInternal_Init_AvailabilityParameters
(
    void
);
#endif

#if(DCM_OBD_01_ENABLED == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) DspInternal_01_RequestCurrentPowertrainDiagnosticData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_OBD_02_ENABLED == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) DspInternal_02_RequestPowertrainFreezeFrameData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if((DCM_OBD_03_ENABLED == STD_ON) || (DCM_OBD_07_ENABLED == STD_ON) || (DCM_OBD_0A_ENABLED == STD_ON))
extern FUNC(Std_ReturnType, DCM_CODE) DspInternal_03_07_0A_ObtainingDTC
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_OBD_04_ENABLED == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) DspInternal_04_ClearEmissionRelatedDiagnosticInformation
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_OBD_06_ENABLED == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) DspInternal_06_RequestOnBoardMonitoringTestResults
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_OBD_08_ENABLED == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) DspInternal_08_RequestControlOfOnBoardSystem
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#if(DCM_OBD_09_ENABLED == STD_ON)
extern FUNC(Std_ReturnType, DCM_CODE) DspInternal_09_RequestVehicleInformation
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);
#endif

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif/*DCM_OBD_H*/


