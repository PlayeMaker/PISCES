/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dcm_Callout.c
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

/*PRQA S 778,779,777,1532,1503,3120,3673,2814,1860,2016 EOF*/
/*
Names in this file may not follow relevant rules.
*/

/*PRQA S 857 EOF*/

/*PRQA S 3204 EOF*/
/*
Though the variable '%s' is only set once but it could not be declared with the 'const' qualifier.
*/

/*PRQA S 3206 EOF*/
/*
The parameter '%s' will be used by user.
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

/*PRQA S 380 EOF*/
/*
Number of macro definitions exceeds 4095 -program does not conform strictly to ISO:C99.
*/

/*PRQA S 5087 EOF*/
/*
Use of #include directive after code fragment.
*/

/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dcm_Callout.h"
#include "Dflash.h"
#include "Version.h"
/*Dcm_Callout.c Header File User Code start*/

/*Dcm_Callout.c Header File User Code end*/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
#include "BSW_APP.h"

extern ECU_MODE CURRENT_ECU;
#define REP_FLAG_DATA              (0x0200FC00u)
/*SWS_Dcm_00543*/
FUNC(Std_ReturnType, DCM_CALLOUT_CODE) Dcm_SetProgConditions
(
	Dcm_OpStatusType OpStatus,
	P2CONST(Dcm_ProgConditionsType, AUTOMATIC, DCM_APPL_DATA) ProgConditions
)
{
	uint8 dataMCMD[4] = {0xA5,0xA5,0xA5,0xA5};
    uint8 dataMCMP[4] = {0xB5,0xB5,0xB5,0xB5};
    Std_ReturnType ret = E_OK;
    /* Dcm_SetProgConditions User Code start*/

    if(CURRENT_ECU == MCM_D)
    {
        Dflash_Write(REP_FLAG_DATA,0x4,&dataMCMD[0]);
    }
    else
    {
        Dflash_Write(REP_FLAG_DATA,0x4,&dataMCMP[0]);
    }
    
    /* Dcm_SetProgConditions User Code end*/
    return ret;
}

/*SWS_Dcm_00544*/
FUNC(Dcm_EcuStartModeType, DCM_CALLOUT_CODE) Dcm_GetProgConditions
(
    P2VAR(Dcm_ProgConditionsType, AUTOMATIC, DCM_APPL_DATA) ProgConditions
)
{
    Dcm_EcuStartModeType Result = DCM_COLD_START;
    /*Dcm_GetProgConditions User Code start*/

    /*Dcm_GetProgConditions User Code end*/
    return Result;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_CallbackDCMRequestServices_User_StartProtocol
(
    CONST(Dcm_ProtocolType, AUTOMATIC) ProtocolType,
    CONST(uint16, AUTOMATIC) TesterSourceAddress,
    CONST(uint16, AUTOMATIC) ConnectionId
)
{
    Std_ReturnType ret = RTE_E_OK;
    /*Rte_Call_Dcm_CallbackDCMRequestServices_User_StartProtocol User Code start*/

    /*Rte_Call_Dcm_CallbackDCMRequestServices_User_StartProtocol User Code end*/
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_CallbackDCMRequestServices_User_StopProtocol
(
    CONST(Dcm_ProtocolType, AUTOMATIC) ProtocolType,
    CONST(uint16, AUTOMATIC) TesterSourceAddress,
    CONST(uint16, AUTOMATIC) ConnectionId
)
{
    Std_ReturnType ret = RTE_E_OK;
    /*Rte_Call_Dcm_CallbackDCMRequestServices_User_StopProtocol User Code start*/

    /*Rte_Call_Dcm_CallbackDCMRequestServices_User_StopProtocol User Code end*/
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF010_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF010_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xF010_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)4;
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = i + 1;
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xF010_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF110_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF110_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xF110_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)11;
    char* hardware_version = Snf_Hardware_Version_Get();
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = hardware_version[i];
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xF110_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF111_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF111_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xF111_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)2;
    char* hardware_baseline = Snf_Hardware_Baseline_Get();
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = hardware_baseline[i];
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xF111_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF118_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF118_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xF118_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)11;
    char* software_version = Snf_Software_Version_Get();
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = software_version[i];
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xF118_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF119_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF119_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xF119_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)2;
    char* software_baseline = Snf_Software_Baseline_Get();
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = software_baseline[i];
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xF119_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF150_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF150_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xF150_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)3;
    char* bootloader_number = Snf_Bootloader_Number_Get();
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = bootloader_number[i];
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xF150_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF15B_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF15B_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xF15B_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)12;
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = i + 1;
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xF15B_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF186_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_DataElement_DspData_0xF186_0Type, AUTOMATIC, RTE_APPL_DATA) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xF186_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)1;
    uint8 ses_ctrl_type = 0;
    Rte_Call_DCMServices_GetSesCtrlType(&ses_ctrl_type);
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = ses_ctrl_type;
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xF186_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF18A_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF18A_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xF18A_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)8;
    char* supplier_number = Snf_Supplier_Number_Get();
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = supplier_number[i];
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xF18A_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF18B_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF18B_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xF18B_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)3;
    char* manufacturing_date = Snf_Manufacturing_Date_Get();
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = manufacturing_date[i];
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xF18B_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF18C_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF18C_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xF18C_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)16;
    char* serial_number = Snf_Serial_Number_Get();
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = serial_number[i];
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xF18C_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF193_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF193_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xF193_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)3;
    char* supplier_hardware_number = Snf_Supplier_Hardware_Number_Get();
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = supplier_hardware_number[i];
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xF193_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF195_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF195_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xF195_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)3;
    char* supplier_software_number = Snf_Supplier_Software_Number_Get();
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = supplier_software_number[i];
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xF195_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xF19E_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xF19E_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xF19E_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)3;
    char* diag_database_version = Snf_Diag_Database_Version_Get();
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = diag_database_version[i];
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xF19E_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xFD00_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xFD00_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xFD00_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)3;
    char* bootloader_inside_version = Snf_Bootloader_Inside_Version_Get();
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = bootloader_inside_version[i];
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xFD00_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xFD01_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xFD01_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xFD01_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)3;
    char* software_inside_version = Snf_Software_Inside_Version_Get();
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = software_inside_version[i];
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xFD01_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xFD02_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xFD02_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xFD02_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)3;
    char* hardware_inside_version = Snf_Hardware_Inside_Version_Get();
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = hardware_inside_version[i];
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xFD02_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xFD03_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xFD03_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xFD03_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)2;
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = i + 1;
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xFD03_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DspData_0xFD05_0_ReadData
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_DataElement_DspData_0xFD05_0Type,AUTOMATIC) Data,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_DataServices_DspData_0xFD05_0_ReadData User Code start*/

    uint8 i;
    uint8 length = (uint8)6;
    for(i = (uint8)0; i < length; i++)
    {
        Data[i] = i + 1;
    }
    return E_OK;
    /*Rte_Call_Dcm_DataServices_DspData_0xFD05_0_ReadData User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_0x0203_Start
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_StartDataOut_DspRoutine0x0203_DspRoutine0x0203_StartOutSignalType, AUTOMATIC, RTE_APPL_DATA) DataOut_DspRoutine0x0203_StartOutSignal,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /* Rte_Call_Dcm_RoutineServices_0x0203_Start User Code start*/
    if(1)
    {
        *DataOut_DspRoutine0x0203_StartOutSignal = 0;
    }
    else
    {
        *DataOut_DspRoutine0x0203_StartOutSignal = 1;        
    }

    Std_ReturnType Result = E_OK;

    return Result;
    /* Rte_Call_Dcm_RoutineServices_0x0203_Start User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_0xFD04_Start
(
    CONST(Dcm_StartFlexibleInArrayData_DspRoutine0xFD04_DspRoutine0xFD04_StartInSignalType, AUTOMATIC) DataIn_DspRoutine0xFD04_StartInSignal,
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_StartFlexibleOutArrayData_DspRoutine0xFD04_DspRoutine0xFD04_StartOutSignalType,AUTOMATIC) DataOut_DspRoutine0xFD04_StartOutSignal,
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_RoutineServices_0xFD04_Start User Code start*/

    Std_ReturnType Result = E_OK;

    return Result;
    /*Rte_Call_Dcm_RoutineServices_0xFD04_Start User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_0xFD04_Stop
(
    CONST(Dcm_StopFlexibleInArrayData_DspRoutine0xFD04_DspRoutine0xFD04_StopInSignalType, AUTOMATIC) DataIn_DspRoutine0xFD04_StopInSignal,
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_StopFlexibleOutArrayData_DspRoutine0xFD04_DspRoutine0xFD04_StopOutSignalType,AUTOMATIC) DataOut_DspRoutine0xFD04_StopOutSignal,
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_RoutineServices_0xFD04_Stop User Code start*/

    Std_ReturnType Result = E_OK;

    return Result;
    /*Rte_Call_Dcm_RoutineServices_0xFD04_Stop User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_0xFD05_Start
(
    CONST(Dcm_StartFlexibleInArrayData_DspRoutine0xFD05_DspRoutine0xFD05_StartInSignalType, AUTOMATIC) DataIn_DspRoutine0xFD05_StartInSignal,
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_StartFlexibleOutArrayData_DspRoutine0xFD05_DspRoutine0xFD05_StartOutSignalType,AUTOMATIC) DataOut_DspRoutine0xFD05_StartOutSignal,
    P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) currentDataLength,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_RoutineServices_0xFD05_Start User Code start*/

    Std_ReturnType Result = E_OK;

    return Result;
    /*Rte_Call_Dcm_RoutineServices_0xFD05_Start User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_RoutineServices_0xFD10_Start
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_RoutineServices_0xFD10_Start User Code start*/

    Std_ReturnType Result = E_OK;

    return Result;
    /*Rte_Call_Dcm_RoutineServices_0xFD10_Start User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_L2_GetSeed
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    VAR(Dcm_SeedArray_L2Type,AUTOMATIC) Seed,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_SecurityAccess_L2_GetSeed User Code start*/

    uint8 i;
    uint8 length = (uint8)4;
    /*add your code here:The value of the seed is derived from the application layer*/
    for(i = (uint8)0; i < length; i++)
    {
        Seed[i] = (uint8)0x0C;
    }
    return E_OK;
    /*Rte_Call_Dcm_SecurityAccess_L2_GetSeed User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_L2_CompareKey
(
    CONST(Dcm_KeyArray_L2Type, AUTOMATIC) Key,
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_APPL_DATA) ErrorCode
)
{
    /*Rte_Call_Dcm_SecurityAccess_L2_CompareKey User Code start*/

    Std_ReturnType Result = DCM_E_COMPARE_KEY_FAILED;/*Compare Key is Falied*/
    uint8 i;
    uint8 length = (uint8)4;

    *ErrorCode = DCM_E_INVALIDKEY;

    /*add your code here:The value of the seed is derived from the application layer*/
    for(i = (uint8)0; i < length; i++)
    {
        if(Key[i] != (uint8)0)
        {
            Result = E_OK;
            *ErrorCode = DCM_POS_RESP;
            break;
        }
    }
    return Result;
    /*Rte_Call_Dcm_SecurityAccess_L2_CompareKey User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_L2_GetSecurityAttemptCounter
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) AttemptCounter
)
{
    /*Rte_Call_Dcm_SecurityAccess_L2_GetSecurityAttemptCounter User Code start*/

    Std_ReturnType Result = E_OK;
    
    if(AttemptCounter != NULL_PTR)
    {
        *AttemptCounter = (uint8)3;
    }
    
    return Result;
    /*Rte_Call_Dcm_SecurityAccess_L2_GetSecurityAttemptCounter User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_SecurityAccess_L2_SetSecurityAttemptCounter
(
    CONST(Dcm_OpStatusType, AUTOMATIC) OpStatus,
    CONST(uint8, AUTOMATIC) AttemptCounter
)
{
    /*Rte_Call_Dcm_SecurityAccess_L2_SetSecurityAttemptCounter User Code start*/

    Std_ReturnType Result = E_OK;
    
    return Result;
    /*Rte_Call_Dcm_SecurityAccess_L2_SetSecurityAttemptCounter User Code end*/
}


#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"


