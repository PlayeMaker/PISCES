/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dcm_Code.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Dcm module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Dcm module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/

/*PRQA S 776 EOF*/
/*
Names in this file may not follow relevant rules.
*/

/*PRQA S 3614 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "Dcm_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in Dcm_MemMap.h
*/

/*PRQA S 3432 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no
need to revise.
*/
#ifndef DCM_CODE_H
#define DCM_CODE_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Dcm_Types.h"


#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"


extern FUNC(Std_ReturnType, DCM_CODE) Dcm_SecurityAccess_L2_GetSeed
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_SecurityAccess_L2_CompareKey
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
);


extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xF010_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xF110_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xF111_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xF118_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xF119_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xF150_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xF15B_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xF186_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xF18A_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xF18B_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xF18C_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xF193_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xF195_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xF19E_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xFD00_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xFD01_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xFD02_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, DCM_CODE) Dcm_DataServices_0xFD03_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, RTE_CODE) Dcm_RoutineServices_0x0203_Start
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataIn,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataOut,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,/*In&Out parameter*/
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, RTE_CODE) Dcm_RoutineServices_0xFD01_Start
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataIn,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataOut,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,/*In&Out parameter*/
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, RTE_CODE) Dcm_RoutineServices_0xFD04_Start
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataIn,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataOut,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,/*In&Out parameter*/
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);

extern FUNC(Std_ReturnType, RTE_CODE) Dcm_RoutineServices_0xFD05_Start
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataIn,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataOut,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,/*In&Out parameter*/
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
);


#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"


#endif


