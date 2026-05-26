/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dcm_Code.c
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

/*PRQA S 857,2784 EOF*/


/*PRQA S 1532 EOF*/
/*
Function declared externally are called by the user.
*/

/*PRQA S 2814,2824 EOF*/
/*
The pointer has already been checked for null in other files.
*/
/*PRQA S 431 EOF*/
/*
Function argument points to a more heavily qualified type.
*/

/*PRQA S 2000 EOF*/
/*
When there is only one If,there can be no else.
*/

/*PRQA S 2100 EOF*/
/*
Logical judgment needs to be done.
*/

/*PRQA S 3120 EOF*/
/*
An integer constant has been used.
*/

/*PRQA S 3204 EOF*/
/*
Though the variable '%s' is only set once but it could not be declared with the 'const' qualifier.
*/

/*PRQA S 3206,3673 EOF*/
/*
The parameter '%s' will be used in other configurations.
*/

/*PRQA S 3227 EOF*/
/*
The parameter '%s' will be modified in the call function.
*/

/*PRQA S 3614,3214,862 EOF*/
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

/*PRQA S 4599 EOF*/
/*
Operands of binary operator have the same type but distinct type names.
*/

/*PRQA S 5087 EOF*/
/*
Use of #include directive after code fragment.
*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Dcm_Code.h"
#include "Rte_Dcm.h"
#include "Bsw_Common.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

FUNC(Std_ReturnType, DCM_CODE) Dcm_SecurityAccess_L2_GetSeed
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType ret = E_OK;
    uint8 *Seed = &(pMsgContext->resData[2]);

    ret = Dcm_Rte_SecurityAccess_L2_GetSeed(OpStatus, Seed, pErrorCode);


    return ret;
}

FUNC(Std_ReturnType, DCM_CODE) Dcm_SecurityAccess_L2_CompareKey
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType ret = E_OK;
    uint8 *Key = &(pMsgContext->reqData[2]);

    ret = Dcm_Rte_SecurityAccess_L2_CompareKey(Key, OpStatus, pErrorCode);

    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Dcm_DataServices_0xF010_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
    Std_ReturnType ret = E_OK;


    ret = Dcm_Rte_DataServices_DspData_0xF010_0_ReadData(OpStatus, Data, ErrorCode);

    return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Dcm_DataServices_0xF110_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
    Std_ReturnType ret = E_OK;


    ret = Dcm_Rte_DataServices_DspData_0xF110_0_ReadData(OpStatus, Data, ErrorCode);

    return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Dcm_DataServices_0xF111_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
    Std_ReturnType ret = E_OK;


    ret = Dcm_Rte_DataServices_DspData_0xF111_0_ReadData(OpStatus, Data, ErrorCode);

    return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Dcm_DataServices_0xF118_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
    Std_ReturnType ret = E_OK;


    ret = Dcm_Rte_DataServices_DspData_0xF118_0_ReadData(OpStatus, Data, ErrorCode);

    return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Dcm_DataServices_0xF119_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
    Std_ReturnType ret = E_OK;


    ret = Dcm_Rte_DataServices_DspData_0xF119_0_ReadData(OpStatus, Data, ErrorCode);

    return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Dcm_DataServices_0xF150_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
    Std_ReturnType ret = E_OK;


    ret = Dcm_Rte_DataServices_DspData_0xF150_0_ReadData(OpStatus, Data, ErrorCode);

    return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Dcm_DataServices_0xF15B_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
    Std_ReturnType ret = E_OK;


    ret = Dcm_Rte_DataServices_DspData_0xF15B_0_ReadData(OpStatus, Data, ErrorCode);

    return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Dcm_DataServices_0xF186_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
    Std_ReturnType ret = E_OK;


    ret = Dcm_Rte_DataServices_DspData_0xF186_0_ReadData(OpStatus, Data, ErrorCode);

    return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Dcm_DataServices_0xF18A_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
    Std_ReturnType ret = E_OK;


    ret = Dcm_Rte_DataServices_DspData_0xF18A_0_ReadData(OpStatus, Data, ErrorCode);

    return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Dcm_DataServices_0xF18B_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
    Std_ReturnType ret = E_OK;


    ret = Dcm_Rte_DataServices_DspData_0xF18B_0_ReadData(OpStatus, Data, ErrorCode);

    return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Dcm_DataServices_0xF18C_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
    Std_ReturnType ret = E_OK;


    ret = Dcm_Rte_DataServices_DspData_0xF18C_0_ReadData(OpStatus, Data, ErrorCode);

    return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Dcm_DataServices_0xF193_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
    Std_ReturnType ret = E_OK;


    ret = Dcm_Rte_DataServices_DspData_0xF193_0_ReadData(OpStatus, Data, ErrorCode);

    return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Dcm_DataServices_0xF195_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
    Std_ReturnType ret = E_OK;


    ret = Dcm_Rte_DataServices_DspData_0xF195_0_ReadData(OpStatus, Data, ErrorCode);

    return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Dcm_DataServices_0xF19E_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
    Std_ReturnType ret = E_OK;


    ret = Dcm_Rte_DataServices_DspData_0xF19E_0_ReadData(OpStatus, Data, ErrorCode);

    return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Dcm_DataServices_0xFD01_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
    Std_ReturnType ret = E_OK;


    ret = Dcm_Rte_DataServices_DspData_0xFD01_0_ReadData(OpStatus, Data, ErrorCode);

    return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Dcm_DataServices_0xFD02_0_ReadData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
    Std_ReturnType ret = E_OK;


    ret = Dcm_Rte_DataServices_DspData_0xFD02_0_ReadData(OpStatus, Data, ErrorCode);

    return ret;
}


FUNC(Std_ReturnType, RTE_CODE) Dcm_RoutineServices_0x0203_Start
(
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataIn,
    Dcm_OpStatusType OpStatus,
    P2VAR(uint8, AUTOMATIC, DCM_VAR) DataOut,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode
)
{
    Std_ReturnType ret = E_OK;
    uint16 DataPos;
    /*DataIn signals*/

    /*DataOut signals*/
    Dcm_StartDataOut_DspRoutine0x0203_DspRoutine0x0203_StartOutSignalType DataOut_DspRoutine0x0203_Start_DspRoutine0x0203_StartOutSignal;



    ret = Dcm_Rte_RoutineServices_0x0203_Start(
        OpStatus,
        &DataOut_DspRoutine0x0203_Start_DspRoutine0x0203_StartOutSignal,/*Pointer*/
        ErrorCode
    );

    if(ret == E_OK)
    {
        DataPos = (uint16)0;

        DataOut[DataPos] = DataOut_DspRoutine0x0203_Start_DspRoutine0x0203_StartOutSignal;
        
    }

    return ret;
}




#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"



