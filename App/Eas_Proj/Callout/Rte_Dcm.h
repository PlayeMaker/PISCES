/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_Dcm.h
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


#ifndef RTE_DCM_H
#define RTE_DCM_H

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
#include "Dcm.h"
#include "Rte_Dcm_Type.h"
#define Rte_Call_DCMServices_GetSecurityLevel(SecLevel)     Dcm_GetSecurityLevel(SecLevel)
#define Rte_Call_DCMServices_GetSesCtrlType(SesCtrlType)    Dcm_GetSesCtrlType(SesCtrlType)
#define Rte_Call_DCMServices_ResetToDefaultSession()        Dcm_ResetToDefaultSession()
#define Rte_Call_DCMServices_SetActiveDiagnostic(active)    Dcm_SetActiveDiagnostic(active)

/*******************************************************************************
*   Extended
*******************************************************************************/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
#define Dcm_Rte_CallbackDCMRequestServices_User_StartProtocol         Rte_Call_Dcm_CallbackDCMRequestServices_User_StartProtocol
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_CallbackDCMRequestServices_User_StartProtocol
(
    CONST(Dcm_ProtocolType, AUTOMATIC) ProtocolType,
    CONST(uint16, AUTOMATIC) TesterSourceAddress,
    CONST(uint16, AUTOMATIC) ConnectionId
);
#define Dcm_Rte_CallbackDCMRequestServices_User_StopProtocol          Rte_Call_Dcm_CallbackDCMRequestServices_User_StopProtocol
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_CallbackDCMRequestServices_User_StopProtocol
(
    CONST(Dcm_ProtocolType, AUTOMATIC) ProtocolType,
    CONST(uint16, AUTOMATIC) TesterSourceAddress,
    CONST(uint16, AUTOMATIC) ConnectionId
);
#define Dcm_Rte_DataServices_DspData_0xF010_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF010_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF010_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF010_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF110_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF110_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF110_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF110_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF111_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF111_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF111_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF111_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF118_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF118_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF118_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF118_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF119_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF119_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF119_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF119_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF150_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF150_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF150_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF150_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF15B_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF15B_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF15B_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF15B_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF186_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF186_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF186_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_DataElement_DspData_0xF186_0Type, AUTOMATIC, RTE_APPL_DATA) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF18A_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF18A_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF18A_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF18A_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF18B_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF18B_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF18B_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF18B_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF18C_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF18C_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF18C_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF18C_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF193_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF193_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF193_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF193_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF195_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF195_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF195_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF195_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xF19E_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xF19E_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF19E_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF19E_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xFD01_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xFD01_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xFD01_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xFD01_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_DataServices_DspData_0xFD02_0_ReadData      Rte_Call_Dcm_DataServices_DspData_0xFD02_0_ReadData
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xFD02_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xFD02_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_RoutineServices_0x0203_Start                Rte_Call_Dcm_RoutineServices_0x0203_Start
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_0x0203_Start
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_StartDataOut_DspRoutine0x0203_DspRoutine0x0203_StartOutSignalType, AUTOMATIC, RTE_APPL_DATA) DataOut_DspRoutine0x0203_StartOutSignal,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_RoutineServices_0xFD01_Start                Rte_Call_Dcm_RoutineServices_0xFD01_Start
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_0xFD01_Start
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_RoutineServices_0xFD04_Start                Rte_Call_Dcm_RoutineServices_0xFD04_Start
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_0xFD04_Start
(
    CONST(Dcm_StartDataIn_DspRoutine0xFD04_DspRoutine0xFD04_StartInSignalType, AUTOMATIC) DataIn_DspRoutine0xFD04_StartInSignal,
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_StartDataOut_DspRoutine0xFD04_DspRoutine0xFD04_StartOutSignalType, AUTOMATIC, RTE_APPL_DATA) DataOut_DspRoutine0xFD04_StartOutSignal,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_RoutineServices_0xFD05_Start                Rte_Call_Dcm_RoutineServices_0xFD05_Start
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_0xFD05_Start
(
    CONST(Dcm_StartDataIn_DspRoutine0xFD05_DspRoutine0xFD05_StartInSignalType, AUTOMATIC) DataIn_DspRoutine0xFD05_StartInSignal,
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_StartDataOut_DspRoutine0xFD05_DspRoutine0xFD05_StartOutSignalType, AUTOMATIC, RTE_APPL_DATA) DataOut_DspRoutine0xFD05_StartOutSignal,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_SecurityAccess_L2_GetSeed                   Rte_Call_Dcm_SecurityAccess_L2_GetSeed
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_L2_GetSeed
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_SeedArray_L2Type,AUTOMATIC) Seed,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_SecurityAccess_L2_CompareKey                Rte_Call_Dcm_SecurityAccess_L2_CompareKey
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_L2_CompareKey
(
    CONST(Dcm_KeyArray_L2Type, AUTOMATIC) Key,
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
);
#define Dcm_Rte_SecurityAccess_L2_GetSecurityAttemptCounter Rte_Call_Dcm_SecurityAccess_L2_GetSecurityAttemptCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_L2_GetSecurityAttemptCounter
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) AttemptCounter
);
#define Dcm_Rte_SecurityAccess_L2_SetSecurityAttemptCounter Rte_Call_Dcm_SecurityAccess_L2_SetSecurityAttemptCounter
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_L2_SetSecurityAttemptCounter
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    CONST(uint8, AUTOMATIC) AttemptCounter
);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif  /*RTE_DCM_H*/


