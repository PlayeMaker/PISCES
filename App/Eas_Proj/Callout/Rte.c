/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte.c
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
/*PRQA S 5087,3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "Rte_MemMap.h" is required. Defined
XXX_START_SEC_ will undefine in Rte_MemMap.h
*/

/*PRQA S 3206,1278 EOF*/
/*
Particularity of Callout files
*/

/*PRQA S 3432,3410,3409 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no
need to revise.
*/

/*PRQA S 315 EOF*/
/*
Implicit conversion from a pointer to object type to a pointer to void.
*/

/*PRQA S 380 EOF*/
/*
Number of macro definitions exceeds 4095 -program does not conform strictly to ISO:C99.
*/

/*PRQA S 857 EOF*/
/*
Number of macro definitions exceeds 1024 -program does not conform strictly to ISO:C90.
*/

/*PRQA S 1340 EOF*/
/*
Storing the address of the parameter 'data' in a constant pointer.
*/

/*PRQA S 1863 EOF*/

/*PRQA S 1514,1751,2984 EOF*/
/*
The parameters provided to the user shall be modified and used by 
the user through adding code.
*/

/*PRQA S 1505,1503,1532 EOF*/
/*
Api used by other modules.
*/

/*PRQA S 3673,4603,2986 EOF*/
/*
Parameters in AUTOSAR standard APIs,they may not follow this rule.
*/

/*PRQA S 0580,1272,0790,1290 EOF*/
/*
The float type is allowed.
*/

/*PRQA S 2220,1302,3209,3200,3335 EOF*/
/*
Interrupts Api problem.
*/

/*PRQA S 2814,2824 EOF*/
/*
Ensure that the input pointer is not a null pointer.
*/

/*PRQA S 2201 EOF*/
/*
The issue with the indentation method will be uniformly modified.
*/

/*******************************************************************************
*   Includes.
********************************************************************************/
#include "Rte_Private.h"
#include "Rte_Private_Var.h"


/*Rte.c Header File User Code start*/

/*Rte.c Header File User Code end*/

/*******************************************************************************
*   ComCfgSet Define   *
*******************************************************************************/
#define RTE_START_SEC_CONST_UNSPECIFIED
#include "Rte_MemMap.h"
P2CONST(uint8, AUTOMATIC, RTE_CONST) Rte_VarCfgPtr;

CONST(uint8, RTE_CONST) Rte_Config_0 =
{
    0U
};

CONST(uint8, RTE_CONST) Rte_Config_1 =
{
    1U
};

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "Rte_MemMap.h"

/*******************************************************************************
*   State
*******************************************************************************/
#define RTE_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED_Com
#include "Rte_MemMap.h"
VAR(boolean, RTE_VAR) RTE_Day_Day_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvPumpCmd_DrvPumpCmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatBolsterValueBLCmd_DrvSeatBolsterValueBLCmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatBolsterValueBRCmd_DrvSeatBolsterValueBRCmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatCushionValue1Cmd_DrvSeatCushionValue1Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatCushionValue2Cmd_DrvSeatCushionValue2Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatCushionValue3Cmd_DrvSeatCushionValue3Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatCushionValue4Cmd_DrvSeatCushionValue4Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatCushionValue5Cmd_DrvSeatCushionValue5Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatCushionValue6Cmd_DrvSeatCushionValue6Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatLumbarBottomValue3Cmd_DrvSeatLumbarBottomValue3Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatLumbarMidValue2Cmd_DrvSeatLumbarMidValue2Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatLumbarTopValue1Cmd_DrvSeatLumbarTopValue1Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatUpperValueLCmd_DrvSeatUpperValueLCmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatUpperValueMCmd_DrvSeatUpperValueMCmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatUpperValueRCmd_DrvSeatUpperValueRCmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat10Cmd_DrvSeatmassgHeat10Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat11Cmd_DrvSeatmassgHeat11Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat12Cmd_DrvSeatmassgHeat12Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat1Cmd_DrvSeatmassgHeat1Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat2Cmd_DrvSeatmassgHeat2Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat3Cmd_DrvSeatmassgHeat3Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat4Cmd_DrvSeatmassgHeat4Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat5Cmd_DrvSeatmassgHeat5Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat6Cmd_DrvSeatmassgHeat6Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat7Cmd_DrvSeatmassgHeat7Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat8Cmd_DrvSeatmassgHeat8Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat9Cmd_DrvSeatmassgHeat9Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve10Cmd_DrvSeatmassgValve10Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve11Cmd_DrvSeatmassgValve11Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve12Cmd_DrvSeatmassgValve12Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve1Cmd_DrvSeatmassgValve1Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve2Cmd_DrvSeatmassgValve2Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve3Cmd_DrvSeatmassgValve3Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve4Cmd_DrvSeatmassgValve4Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve5Cmd_DrvSeatmassgValve5Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve6Cmd_DrvSeatmassgValve6Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve7Cmd_DrvSeatmassgValve7Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve8Cmd_DrvSeatmassgValve8Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve9Cmd_DrvSeatmassgValve9Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvState_DrvState_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_DrvState_SrvSts_DrvState_SrvSts_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_Hr_Hr_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_MSec_MSec_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_Min_Min_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_Mth_Mth_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_OperatorState_OperatorState_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_OperatorState_SrvSts_OperatorState_SrvSts_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassPumpCmd_PassPumpCmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatBolsterValueBLCmd_PassSeatBolsterValueBLCmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatBolsterValueBRCmd_PassSeatBolsterValueBRCmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatCushionValue1Cmd_PassSeatCushionValue1Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatCushionValue2Cmd_PassSeatCushionValue2Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatCushionValue3Cmd_PassSeatCushionValue3Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatCushionValue4Cmd_PassSeatCushionValue4Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatCushionValue5Cmd_PassSeatCushionValue5Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatCushionValue6Cmd_PassSeatCushionValue6Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatLumbarBottomValue3Cmd_PassSeatLumbarBottomValue3Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatLumbarMidValue2Cmd_PassSeatLumbarMidValue2Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatLumbarTopValue1Cmd_PassSeatLumbarTopValue1Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatUpperValueLCmd_PassSeatUpperValueLCmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatUpperValueMCmd_PassSeatUpperValueMCmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatUpperValueRCmd_PassSeatUpperValueRCmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat10Cmd_PassSeatmassgHeat10Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat11Cmd_PassSeatmassgHeat11Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat12Cmd_PassSeatmassgHeat12Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat1Cmd_PassSeatmassgHeat1Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat2Cmd_PassSeatmassgHeat2Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat3Cmd_PassSeatmassgHeat3Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat4Cmd_PassSeatmassgHeat4Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat5Cmd_PassSeatmassgHeat5Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat6Cmd_PassSeatmassgHeat6Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat7Cmd_PassSeatmassgHeat7Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat8Cmd_PassSeatmassgHeat8Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat9Cmd_PassSeatmassgHeat9Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve10Cmd_PassSeatmassgValve10Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve11Cmd_PassSeatmassgValve11Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve12Cmd_PassSeatmassgValve12Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve1Cmd_PassSeatmassgValve1Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve2Cmd_PassSeatmassgValve2Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve3Cmd_PassSeatmassgValve3Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve4Cmd_PassSeatmassgValve4Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve5Cmd_PassSeatmassgValve5Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve6Cmd_PassSeatmassgValve6Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve7Cmd_PassSeatmassgValve7Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve8Cmd_PassSeatmassgValve8Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve9Cmd_PassSeatmassgValve9Cmd_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_Sec_Sec_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_VehModeDef_VehModeDef_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_VehOdometer_VehOdometer_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_VehStateDetailed_VehStateDetailed_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_VehStateDetailed_SrvSts_VehStateDetailed_SrvSts_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_Yr_Yr_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_ZONE_13C_CRC_ZONE_13C_CRC_TIMEOUT_FLAG = RTE_FALSE;
VAR(boolean, RTE_VAR) RTE_ZONE_13C_MsgCntr_ZONE_13C_MsgCntr_TIMEOUT_FLAG = RTE_FALSE;
#define RTE_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED_Com
#include "Rte_MemMap.h"


/*******************************************************************************
*   Rte Api
*******************************************************************************/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"


FUNC(void, RTE_CODE) Rte_MemCpy(
    P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, 
    P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, 
    uint32_least num
) 
{
    /*PRQA S 316 ++*/
    P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA)) source;
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dst = (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA)) destination;
    /*PRQA S 316 --*/
    uint32_least i;
    SuspendAllInterrupts();
    for (i = (uint32_least)0; i < num; i++)
    {
        dst[i] = src[i];
    }
    ResumeAllInterrupts();
}

FUNC(void, RTE_CODE) Rte_MemInit(
    P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, 
    uint32_least num
)
{
    /*PRQA S 316 ++*/
    P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) dst = (P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA)) ptr;
    /*PRQA S 316 --*/
    uint32_least i;
    SuspendAllInterrupts();
    for (i = (uint32_least)0; i < num; i++)
    {
        dst[i] = (uint8)0;
    }
    ResumeAllInterrupts();
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void)
{

    /*Rte_Start_Before User Code start*/

    /*Rte_Start_Before User Code end*/

    /*Rte_Start_After User Code start*/

    /*Rte_Start_After User Code end*/

    return RTE_E_OK;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void)
{
    /*Rte_Stop User Code start*/

    /*Rte_Stop User Code end*/
    return RTE_E_OK;
}


#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*   Implicit Handle
*******************************************************************************/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*******************************************************************************
*   Rte Api for Sender Receiver port of Com
*******************************************************************************/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_BattVolt_LBMR_BattVolt_LBMR
(
    P2VAR(BattVolt_LBMR_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_Day_Day
(
    P2VAR(Day_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Day, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Day, data);


    }

    if(RTE_TRUE == RTE_Day_Day_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvHeat1_pct_DrvHeat1_pct
(
    P2VAR(DrvHeat1_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat1_pct, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvHeat2_pct_DrvHeat2_pct
(
    P2VAR(DrvHeat2_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat2_pct, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvHeat3_pct_DrvHeat3_pct
(
    P2VAR(DrvHeat3_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat3_pct, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvHeat4_pct_DrvHeat4_pct
(
    P2VAR(DrvHeat4_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat4_pct, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvHeat5_pct_DrvHeat5_pct
(
    P2VAR(DrvHeat5_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat5_pct, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvHeat6_pct_DrvHeat6_pct
(
    P2VAR(DrvHeat6_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat6_pct, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgLvlCmd10_DrvKneadingMassgLvlCmd10
(
    P2VAR(DrvKneadingMassgLvlCmd10_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd10, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgLvlCmd5_DrvKneadingMassgLvlCmd5
(
    P2VAR(DrvKneadingMassgLvlCmd5_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd5, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgLvlCmd6_DrvKneadingMassgLvlCmd6
(
    P2VAR(DrvKneadingMassgLvlCmd6_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd6, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgLvlCmd7_DrvKneadingMassgLvlCmd7
(
    P2VAR(DrvKneadingMassgLvlCmd7_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd7, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgLvlCmd8_DrvKneadingMassgLvlCmd8
(
    P2VAR(DrvKneadingMassgLvlCmd8_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd8, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgLvlCmd9_DrvKneadingMassgLvlCmd9
(
    P2VAR(DrvKneadingMassgLvlCmd9_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd9, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgSkillsCmd10_DrvKneadingMassgSkillsCmd10
(
    P2VAR(DrvKneadingMassgSkillsCmd10_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd10, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgSkillsCmd5_DrvKneadingMassgSkillsCmd5
(
    P2VAR(DrvKneadingMassgSkillsCmd5_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd5, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgSkillsCmd6_DrvKneadingMassgSkillsCmd6
(
    P2VAR(DrvKneadingMassgSkillsCmd6_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd6, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgSkillsCmd7_DrvKneadingMassgSkillsCmd7
(
    P2VAR(DrvKneadingMassgSkillsCmd7_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd7, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgSkillsCmd8_DrvKneadingMassgSkillsCmd8
(
    P2VAR(DrvKneadingMassgSkillsCmd8_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd8, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgSkillsCmd9_DrvKneadingMassgSkillsCmd9
(
    P2VAR(DrvKneadingMassgSkillsCmd9_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd9, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgTimesCmd10_DrvKneadingMassgTimesCmd10
(
    P2VAR(DrvKneadingMassgTimesCmd10_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd10, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgTimesCmd5_DrvKneadingMassgTimesCmd5
(
    P2VAR(DrvKneadingMassgTimesCmd5_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd5, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgTimesCmd6_DrvKneadingMassgTimesCmd6
(
    P2VAR(DrvKneadingMassgTimesCmd6_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd6, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgTimesCmd7_DrvKneadingMassgTimesCmd7
(
    P2VAR(DrvKneadingMassgTimesCmd7_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd7, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgTimesCmd8_DrvKneadingMassgTimesCmd8
(
    P2VAR(DrvKneadingMassgTimesCmd8_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd8, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgTimesCmd9_DrvKneadingMassgTimesCmd9
(
    P2VAR(DrvKneadingMassgTimesCmd9_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd9, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvPumpCmd_DrvPumpCmd
(
    P2VAR(DrvPumpCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvPumpCmd, data);


    }

    if(RTE_TRUE == RTE_DrvPumpCmd_DrvPumpCmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatBolsterValueBLCmd_DrvSeatBolsterValueBLCmd
(
    P2VAR(DrvSeatBolsterValueBLCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBLCmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatBolsterValueBLCmd_DrvSeatBolsterValueBLCmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatBolsterValueBRCmd_DrvSeatBolsterValueBRCmd
(
    P2VAR(DrvSeatBolsterValueBRCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBRCmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatBolsterValueBRCmd_DrvSeatBolsterValueBRCmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatCushionValue1Cmd_DrvSeatCushionValue1Cmd
(
    P2VAR(DrvSeatCushionValue1Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue1Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatCushionValue1Cmd_DrvSeatCushionValue1Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatCushionValue2Cmd_DrvSeatCushionValue2Cmd
(
    P2VAR(DrvSeatCushionValue2Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue2Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatCushionValue2Cmd_DrvSeatCushionValue2Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatCushionValue3Cmd_DrvSeatCushionValue3Cmd
(
    P2VAR(DrvSeatCushionValue3Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue3Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatCushionValue3Cmd_DrvSeatCushionValue3Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatCushionValue4Cmd_DrvSeatCushionValue4Cmd
(
    P2VAR(DrvSeatCushionValue4Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue4Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatCushionValue4Cmd_DrvSeatCushionValue4Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatCushionValue5Cmd_DrvSeatCushionValue5Cmd
(
    P2VAR(DrvSeatCushionValue5Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue5Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatCushionValue5Cmd_DrvSeatCushionValue5Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatCushionValue6Cmd_DrvSeatCushionValue6Cmd
(
    P2VAR(DrvSeatCushionValue6Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue6Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatCushionValue6Cmd_DrvSeatCushionValue6Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatLumbarBottomValue3Cmd_DrvSeatLumbarBottomValue3Cmd
(
    P2VAR(DrvSeatLumbarBottomValue3Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarBottomValue3Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatLumbarBottomValue3Cmd_DrvSeatLumbarBottomValue3Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatLumbarMidValue2Cmd_DrvSeatLumbarMidValue2Cmd
(
    P2VAR(DrvSeatLumbarMidValue2Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarMidValue2Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatLumbarMidValue2Cmd_DrvSeatLumbarMidValue2Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatLumbarTopValue1Cmd_DrvSeatLumbarTopValue1Cmd
(
    P2VAR(DrvSeatLumbarTopValue1Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarTopValue1Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatLumbarTopValue1Cmd_DrvSeatLumbarTopValue1Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatUpperValueLCmd_DrvSeatUpperValueLCmd
(
    P2VAR(DrvSeatUpperValueLCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueLCmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatUpperValueLCmd_DrvSeatUpperValueLCmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatUpperValueMCmd_DrvSeatUpperValueMCmd
(
    P2VAR(DrvSeatUpperValueMCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueMCmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatUpperValueMCmd_DrvSeatUpperValueMCmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatUpperValueRCmd_DrvSeatUpperValueRCmd
(
    P2VAR(DrvSeatUpperValueRCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueRCmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatUpperValueRCmd_DrvSeatUpperValueRCmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat10Cmd_DrvSeatmassgHeat10Cmd
(
    P2VAR(DrvSeatmassgHeat10Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat10Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgHeat10Cmd_DrvSeatmassgHeat10Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat11Cmd_DrvSeatmassgHeat11Cmd
(
    P2VAR(DrvSeatmassgHeat11Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat11Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgHeat11Cmd_DrvSeatmassgHeat11Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat12Cmd_DrvSeatmassgHeat12Cmd
(
    P2VAR(DrvSeatmassgHeat12Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat12Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgHeat12Cmd_DrvSeatmassgHeat12Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat1Cmd_DrvSeatmassgHeat1Cmd
(
    P2VAR(DrvSeatmassgHeat1Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat1Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgHeat1Cmd_DrvSeatmassgHeat1Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat2Cmd_DrvSeatmassgHeat2Cmd
(
    P2VAR(DrvSeatmassgHeat2Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat2Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgHeat2Cmd_DrvSeatmassgHeat2Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat3Cmd_DrvSeatmassgHeat3Cmd
(
    P2VAR(DrvSeatmassgHeat3Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat3Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgHeat3Cmd_DrvSeatmassgHeat3Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat4Cmd_DrvSeatmassgHeat4Cmd
(
    P2VAR(DrvSeatmassgHeat4Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat4Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgHeat4Cmd_DrvSeatmassgHeat4Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat5Cmd_DrvSeatmassgHeat5Cmd
(
    P2VAR(DrvSeatmassgHeat5Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat5Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgHeat5Cmd_DrvSeatmassgHeat5Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat6Cmd_DrvSeatmassgHeat6Cmd
(
    P2VAR(DrvSeatmassgHeat6Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat6Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgHeat6Cmd_DrvSeatmassgHeat6Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat7Cmd_DrvSeatmassgHeat7Cmd
(
    P2VAR(DrvSeatmassgHeat7Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat7Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgHeat7Cmd_DrvSeatmassgHeat7Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat8Cmd_DrvSeatmassgHeat8Cmd
(
    P2VAR(DrvSeatmassgHeat8Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat8Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgHeat8Cmd_DrvSeatmassgHeat8Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat9Cmd_DrvSeatmassgHeat9Cmd
(
    P2VAR(DrvSeatmassgHeat9Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat9Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgHeat9Cmd_DrvSeatmassgHeat9Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve10Cmd_DrvSeatmassgValve10Cmd
(
    P2VAR(DrvSeatmassgValve10Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve10Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgValve10Cmd_DrvSeatmassgValve10Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve11Cmd_DrvSeatmassgValve11Cmd
(
    P2VAR(DrvSeatmassgValve11Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve11Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgValve11Cmd_DrvSeatmassgValve11Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve12Cmd_DrvSeatmassgValve12Cmd
(
    P2VAR(DrvSeatmassgValve12Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve12Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgValve12Cmd_DrvSeatmassgValve12Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve1Cmd_DrvSeatmassgValve1Cmd
(
    P2VAR(DrvSeatmassgValve1Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve1Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgValve1Cmd_DrvSeatmassgValve1Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve2Cmd_DrvSeatmassgValve2Cmd
(
    P2VAR(DrvSeatmassgValve2Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve2Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgValve2Cmd_DrvSeatmassgValve2Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve3Cmd_DrvSeatmassgValve3Cmd
(
    P2VAR(DrvSeatmassgValve3Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve3Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgValve3Cmd_DrvSeatmassgValve3Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve4Cmd_DrvSeatmassgValve4Cmd
(
    P2VAR(DrvSeatmassgValve4Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve4Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgValve4Cmd_DrvSeatmassgValve4Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve5Cmd_DrvSeatmassgValve5Cmd
(
    P2VAR(DrvSeatmassgValve5Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve5Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgValve5Cmd_DrvSeatmassgValve5Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve6Cmd_DrvSeatmassgValve6Cmd
(
    P2VAR(DrvSeatmassgValve6Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve6Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgValve6Cmd_DrvSeatmassgValve6Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve7Cmd_DrvSeatmassgValve7Cmd
(
    P2VAR(DrvSeatmassgValve7Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve7Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgValve7Cmd_DrvSeatmassgValve7Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve8Cmd_DrvSeatmassgValve8Cmd
(
    P2VAR(DrvSeatmassgValve8Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve8Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgValve8Cmd_DrvSeatmassgValve8Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve9Cmd_DrvSeatmassgValve9Cmd
(
    P2VAR(DrvSeatmassgValve9Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve9Cmd, data);


    }

    if(RTE_TRUE == RTE_DrvSeatmassgValve9Cmd_DrvSeatmassgValve9Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvState_DrvState
(
    P2VAR(DrvState_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState, data);


    }

    if(RTE_TRUE == RTE_DrvState_DrvState_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvState_SrvSts_DrvState_SrvSts
(
    P2VAR(DrvState_SrvSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts, data);


    }

    if(RTE_TRUE == RTE_DrvState_SrvSts_DrvState_SrvSts_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_Hr_Hr
(
    P2VAR(Hr_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Hr, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Hr, data);


    }

    if(RTE_TRUE == RTE_Hr_Hr_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_MSec_MSec
(
    P2VAR(MSec_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_MSec, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_MSec, data);


    }

    if(RTE_TRUE == RTE_MSec_MSec_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_Min_Min
(
    P2VAR(Min_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Min, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Min, data);


    }

    if(RTE_TRUE == RTE_Min_Min_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_Mth_Mth
(
    P2VAR(Mth_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Mth, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Mth, data);


    }

    if(RTE_TRUE == RTE_Mth_Mth_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_OperatorState_OperatorState
(
    P2VAR(OperatorState_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState, data);


    }

    if(RTE_TRUE == RTE_OperatorState_OperatorState_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_OperatorState_SrvSts_OperatorState_SrvSts
(
    P2VAR(OperatorState_SrvSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts, data);


    }

    if(RTE_TRUE == RTE_OperatorState_SrvSts_OperatorState_SrvSts_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC10_Sts_PNC10_Sts
(
    P2VAR(PNC10_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC11_Sts_PNC11_Sts
(
    P2VAR(PNC11_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC12_Sts_PNC12_Sts
(
    P2VAR(PNC12_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC13_Sts_PNC13_Sts
(
    P2VAR(PNC13_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC14_Sts_PNC14_Sts
(
    P2VAR(PNC14_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC15_Sts_PNC15_Sts
(
    P2VAR(PNC15_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC16_Sts_PNC16_Sts
(
    P2VAR(PNC16_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC17_Sts_PNC17_Sts
(
    P2VAR(PNC17_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC18_Sts_PNC18_Sts
(
    P2VAR(PNC18_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC19_Sts_PNC19_Sts
(
    P2VAR(PNC19_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC1_Sts_PNC1_Sts
(
    P2VAR(PNC1_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC20_Sts_PNC20_Sts
(
    P2VAR(PNC20_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC21_Sts_PNC21_Sts
(
    P2VAR(PNC21_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC22_Sts_PNC22_Sts
(
    P2VAR(PNC22_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC23_Sts_PNC23_Sts
(
    P2VAR(PNC23_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC24_Sts_PNC24_Sts
(
    P2VAR(PNC24_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC25_Sts_PNC25_Sts
(
    P2VAR(PNC25_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC26_Sts_PNC26_Sts
(
    P2VAR(PNC26_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC27_Sts_PNC27_Sts
(
    P2VAR(PNC27_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC28_Sts_PNC28_Sts
(
    P2VAR(PNC28_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC29_Sts_PNC29_Sts
(
    P2VAR(PNC29_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC2_Sts_PNC2_Sts
(
    P2VAR(PNC2_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC30_Sts_PNC30_Sts
(
    P2VAR(PNC30_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC31_Sts_PNC31_Sts
(
    P2VAR(PNC31_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC32_Sts_PNC32_Sts
(
    P2VAR(PNC32_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC33_Sts_PNC33_Sts
(
    P2VAR(PNC33_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC34_Sts_PNC34_Sts
(
    P2VAR(PNC34_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC35_Sts_PNC35_Sts
(
    P2VAR(PNC35_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC36_Sts_PNC36_Sts
(
    P2VAR(PNC36_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC37_Sts_PNC37_Sts
(
    P2VAR(PNC37_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC38_Sts_PNC38_Sts
(
    P2VAR(PNC38_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC39_Sts_PNC39_Sts
(
    P2VAR(PNC39_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC3_Sts_PNC3_Sts
(
    P2VAR(PNC3_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC40_Sts_PNC40_Sts
(
    P2VAR(PNC40_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC41_Sts_PNC41_Sts
(
    P2VAR(PNC41_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC42_Sts_PNC42_Sts
(
    P2VAR(PNC42_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC43_Sts_PNC43_Sts
(
    P2VAR(PNC43_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC44_Sts_PNC44_Sts
(
    P2VAR(PNC44_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC45_Sts_PNC45_Sts
(
    P2VAR(PNC45_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC46_Sts_PNC46_Sts
(
    P2VAR(PNC46_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC47_Sts_PNC47_Sts
(
    P2VAR(PNC47_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC48_Sts_PNC48_Sts
(
    P2VAR(PNC48_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC4_Sts_PNC4_Sts
(
    P2VAR(PNC4_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC5_Sts_PNC5_Sts
(
    P2VAR(PNC5_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC6_Sts_PNC6_Sts
(
    P2VAR(PNC6_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC7_Sts_PNC7_Sts
(
    P2VAR(PNC7_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC8_Sts_PNC8_Sts
(
    P2VAR(PNC8_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC9_Sts_PNC9_Sts
(
    P2VAR(PNC9_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC_DFT_PNC_DFT
(
    P2VAR(PNC_DFT_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassHeat1_pct_PassHeat1_pct
(
    P2VAR(PassHeat1_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat1_pct, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassHeat2_pct_PassHeat2_pct
(
    P2VAR(PassHeat2_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat2_pct, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassHeat3_pct_PassHeat3_pct
(
    P2VAR(PassHeat3_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat3_pct, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassHeat4_pct_PassHeat4_pct
(
    P2VAR(PassHeat4_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat4_pct, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassHeat5_pct_PassHeat5_pct
(
    P2VAR(PassHeat5_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat5_pct, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassHeat6_pct_PassHeat6_pct
(
    P2VAR(PassHeat6_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat6_pct, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgLvlCmd10_PassKneadingMassgLvlCmd10
(
    P2VAR(PassKneadingMassgLvlCmd10_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd10, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgLvlCmd5_PassKneadingMassgLvlCmd5
(
    P2VAR(PassKneadingMassgLvlCmd5_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd5, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgLvlCmd6_PassKneadingMassgLvlCmd6
(
    P2VAR(PassKneadingMassgLvlCmd6_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd6, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgLvlCmd7_PassKneadingMassgLvlCmd7
(
    P2VAR(PassKneadingMassgLvlCmd7_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd7, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgLvlCmd8_PassKneadingMassgLvlCmd8
(
    P2VAR(PassKneadingMassgLvlCmd8_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd8, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgLvlCmd9_PassKneadingMassgLvlCmd9
(
    P2VAR(PassKneadingMassgLvlCmd9_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd9, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgSkillsCmd10_PassKneadingMassgSkillsCmd10
(
    P2VAR(PassKneadingMassgSkillsCmd10_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd10, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgSkillsCmd5_PassKneadingMassgSkillsCmd5
(
    P2VAR(PassKneadingMassgSkillsCmd5_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd5, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgSkillsCmd6_PassKneadingMassgSkillsCmd6
(
    P2VAR(PassKneadingMassgSkillsCmd6_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd6, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgSkillsCmd7_PassKneadingMassgSkillsCmd7
(
    P2VAR(PassKneadingMassgSkillsCmd7_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd7, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgSkillsCmd8_PassKneadingMassgSkillsCmd8
(
    P2VAR(PassKneadingMassgSkillsCmd8_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd8, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgSkillsCmd9_PassKneadingMassgSkillsCmd9
(
    P2VAR(PassKneadingMassgSkillsCmd9_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd9, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgTimesCmd10_PassKneadingMassgTimesCmd10
(
    P2VAR(PassKneadingMassgTimesCmd10_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd10, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgTimesCmd5_PassKneadingMassgTimesCmd5
(
    P2VAR(PassKneadingMassgTimesCmd5_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd5, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgTimesCmd6_PassKneadingMassgTimesCmd6
(
    P2VAR(PassKneadingMassgTimesCmd6_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd6, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgTimesCmd7_PassKneadingMassgTimesCmd7
(
    P2VAR(PassKneadingMassgTimesCmd7_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd7, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgTimesCmd8_PassKneadingMassgTimesCmd8
(
    P2VAR(PassKneadingMassgTimesCmd8_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd8, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgTimesCmd9_PassKneadingMassgTimesCmd9
(
    P2VAR(PassKneadingMassgTimesCmd9_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd9, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassPumpCmd_PassPumpCmd
(
    P2VAR(PassPumpCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassPumpCmd, data);


    }

    if(RTE_TRUE == RTE_PassPumpCmd_PassPumpCmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatBolsterValueBLCmd_PassSeatBolsterValueBLCmd
(
    P2VAR(PassSeatBolsterValueBLCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBLCmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatBolsterValueBLCmd_PassSeatBolsterValueBLCmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatBolsterValueBRCmd_PassSeatBolsterValueBRCmd
(
    P2VAR(PassSeatBolsterValueBRCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBRCmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatBolsterValueBRCmd_PassSeatBolsterValueBRCmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatCushionValue1Cmd_PassSeatCushionValue1Cmd
(
    P2VAR(PassSeatCushionValue1Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue1Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatCushionValue1Cmd_PassSeatCushionValue1Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatCushionValue2Cmd_PassSeatCushionValue2Cmd
(
    P2VAR(PassSeatCushionValue2Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue2Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatCushionValue2Cmd_PassSeatCushionValue2Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatCushionValue3Cmd_PassSeatCushionValue3Cmd
(
    P2VAR(PassSeatCushionValue3Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue3Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatCushionValue3Cmd_PassSeatCushionValue3Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatCushionValue4Cmd_PassSeatCushionValue4Cmd
(
    P2VAR(PassSeatCushionValue4Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue4Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatCushionValue4Cmd_PassSeatCushionValue4Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatCushionValue5Cmd_PassSeatCushionValue5Cmd
(
    P2VAR(PassSeatCushionValue5Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue5Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatCushionValue5Cmd_PassSeatCushionValue5Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatCushionValue6Cmd_PassSeatCushionValue6Cmd
(
    P2VAR(PassSeatCushionValue6Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue6Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatCushionValue6Cmd_PassSeatCushionValue6Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatLumbarBottomValue3Cmd_PassSeatLumbarBottomValue3Cmd
(
    P2VAR(PassSeatLumbarBottomValue3Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarBottomValue3Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatLumbarBottomValue3Cmd_PassSeatLumbarBottomValue3Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatLumbarMidValue2Cmd_PassSeatLumbarMidValue2Cmd
(
    P2VAR(PassSeatLumbarMidValue2Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarMidValue2Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatLumbarMidValue2Cmd_PassSeatLumbarMidValue2Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatLumbarTopValue1Cmd_PassSeatLumbarTopValue1Cmd
(
    P2VAR(PassSeatLumbarTopValue1Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarTopValue1Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatLumbarTopValue1Cmd_PassSeatLumbarTopValue1Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatUpperValueLCmd_PassSeatUpperValueLCmd
(
    P2VAR(PassSeatUpperValueLCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueLCmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatUpperValueLCmd_PassSeatUpperValueLCmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatUpperValueMCmd_PassSeatUpperValueMCmd
(
    P2VAR(PassSeatUpperValueMCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueMCmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatUpperValueMCmd_PassSeatUpperValueMCmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatUpperValueRCmd_PassSeatUpperValueRCmd
(
    P2VAR(PassSeatUpperValueRCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueRCmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatUpperValueRCmd_PassSeatUpperValueRCmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat10Cmd_PassSeatmassgHeat10Cmd
(
    P2VAR(PassSeatmassgHeat10Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat10Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgHeat10Cmd_PassSeatmassgHeat10Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat11Cmd_PassSeatmassgHeat11Cmd
(
    P2VAR(PassSeatmassgHeat11Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat11Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgHeat11Cmd_PassSeatmassgHeat11Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat12Cmd_PassSeatmassgHeat12Cmd
(
    P2VAR(PassSeatmassgHeat12Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat12Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgHeat12Cmd_PassSeatmassgHeat12Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat1Cmd_PassSeatmassgHeat1Cmd
(
    P2VAR(PassSeatmassgHeat1Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat1Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgHeat1Cmd_PassSeatmassgHeat1Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat2Cmd_PassSeatmassgHeat2Cmd
(
    P2VAR(PassSeatmassgHeat2Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat2Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgHeat2Cmd_PassSeatmassgHeat2Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat3Cmd_PassSeatmassgHeat3Cmd
(
    P2VAR(PassSeatmassgHeat3Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat3Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgHeat3Cmd_PassSeatmassgHeat3Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat4Cmd_PassSeatmassgHeat4Cmd
(
    P2VAR(PassSeatmassgHeat4Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat4Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgHeat4Cmd_PassSeatmassgHeat4Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat5Cmd_PassSeatmassgHeat5Cmd
(
    P2VAR(PassSeatmassgHeat5Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat5Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgHeat5Cmd_PassSeatmassgHeat5Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat6Cmd_PassSeatmassgHeat6Cmd
(
    P2VAR(PassSeatmassgHeat6Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat6Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgHeat6Cmd_PassSeatmassgHeat6Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat7Cmd_PassSeatmassgHeat7Cmd
(
    P2VAR(PassSeatmassgHeat7Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat7Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgHeat7Cmd_PassSeatmassgHeat7Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat8Cmd_PassSeatmassgHeat8Cmd
(
    P2VAR(PassSeatmassgHeat8Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat8Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgHeat8Cmd_PassSeatmassgHeat8Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat9Cmd_PassSeatmassgHeat9Cmd
(
    P2VAR(PassSeatmassgHeat9Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat9Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgHeat9Cmd_PassSeatmassgHeat9Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve10Cmd_PassSeatmassgValve10Cmd
(
    P2VAR(PassSeatmassgValve10Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve10Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgValve10Cmd_PassSeatmassgValve10Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve11Cmd_PassSeatmassgValve11Cmd
(
    P2VAR(PassSeatmassgValve11Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve11Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgValve11Cmd_PassSeatmassgValve11Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve12Cmd_PassSeatmassgValve12Cmd
(
    P2VAR(PassSeatmassgValve12Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve12Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgValve12Cmd_PassSeatmassgValve12Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve1Cmd_PassSeatmassgValve1Cmd
(
    P2VAR(PassSeatmassgValve1Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve1Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgValve1Cmd_PassSeatmassgValve1Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve2Cmd_PassSeatmassgValve2Cmd
(
    P2VAR(PassSeatmassgValve2Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve2Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgValve2Cmd_PassSeatmassgValve2Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve3Cmd_PassSeatmassgValve3Cmd
(
    P2VAR(PassSeatmassgValve3Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve3Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgValve3Cmd_PassSeatmassgValve3Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve4Cmd_PassSeatmassgValve4Cmd
(
    P2VAR(PassSeatmassgValve4Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve4Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgValve4Cmd_PassSeatmassgValve4Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve5Cmd_PassSeatmassgValve5Cmd
(
    P2VAR(PassSeatmassgValve5Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve5Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgValve5Cmd_PassSeatmassgValve5Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve6Cmd_PassSeatmassgValve6Cmd
(
    P2VAR(PassSeatmassgValve6Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve6Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgValve6Cmd_PassSeatmassgValve6Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve7Cmd_PassSeatmassgValve7Cmd
(
    P2VAR(PassSeatmassgValve7Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve7Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgValve7Cmd_PassSeatmassgValve7Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve8Cmd_PassSeatmassgValve8Cmd
(
    P2VAR(PassSeatmassgValve8Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve8Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgValve8Cmd_PassSeatmassgValve8Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve9Cmd_PassSeatmassgValve9Cmd
(
    P2VAR(PassSeatmassgValve9Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve9Cmd, data);


    }

    if(RTE_TRUE == RTE_PassSeatmassgValve9Cmd_PassSeatmassgValve9Cmd_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_Sec_Sec
(
    P2VAR(Sec_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Sec, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Sec, data);


    }

    if(RTE_TRUE == RTE_Sec_Sec_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VC_Data_5E0_CRC_VC_Data_5E0_CRC
(
    P2VAR(VC_Data_5E0_CRC_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VC_Data_5E0_MsgCntr_VC_Data_5E0_MsgCntr
(
    P2VAR(VC_Data_5E0_MsgCntr_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VC_Data_5E0_Payload_VC_Data_5E0_Payload
(
    P2VAR(VC_Data_5E0_Payload_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VehModeDef_VehModeDef
(
    P2VAR(VehModeDef_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef, data);


    }

    if(RTE_TRUE == RTE_VehModeDef_VehModeDef_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VehOdometer_VehOdometer
(
    P2VAR(VehOdometer_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer, data);


    }

    if(RTE_TRUE == RTE_VehOdometer_VehOdometer_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VehSpdSts_Rdnt1_VehSpdSts_Rdnt1
(
    P2VAR(VehSpdSts_Rdnt1_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VehSpd_Rdnt1_VehSpd_Rdnt1
(
    P2VAR(VehSpd_Rdnt1_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1, data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VehStateDetailed_VehStateDetailed
(
    P2VAR(VehStateDetailed_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed, data);


    }

    if(RTE_TRUE == RTE_VehStateDetailed_VehStateDetailed_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VehStateDetailed_SrvSts_VehStateDetailed_SrvSts
(
    P2VAR(VehStateDetailed_SrvSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts, data);


    }

    if(RTE_TRUE == RTE_VehStateDetailed_SrvSts_VehStateDetailed_SrvSts_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_Yr_Yr
(
    P2VAR(Yr_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Yr, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Yr, data);


    }

    if(RTE_TRUE == RTE_Yr_Yr_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_ZONE_13C_CRC_ZONE_13C_CRC
(
    P2VAR(ZONE_13C_CRC_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC, data);


    }

    if(RTE_TRUE == RTE_ZONE_13C_CRC_ZONE_13C_CRC_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_ZONE_13C_MsgCntr_ZONE_13C_MsgCntr
(
    P2VAR(ZONE_13C_MsgCntr_IDT, AUTOMATIC, RTE_APPL_DATA) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr, data);


    }

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_ReceiveSignal(Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr, data);


    }

    if(RTE_TRUE == RTE_ZONE_13C_MsgCntr_ZONE_13C_MsgCntr_TIMEOUT_FLAG)
    {
        ret |= (Std_ReturnType)RTE_E_MAX_AGE_EXCEEDED;
    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvHeat1Sts_DrvHeat1Sts
(
    CONST(DrvHeat1Sts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat1Sts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvHeat2Sts_DrvHeat2Sts
(
    CONST(DrvHeat2Sts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat2Sts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvHeat3Sts_DrvHeat3Sts
(
    CONST(DrvHeat3Sts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat3Sts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvHeat4Sts_DrvHeat4Sts
(
    CONST(DrvHeat4Sts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat4Sts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvHeat5ErrSts_DrvHeat5ErrSts
(
    CONST(DrvHeat5ErrSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5ErrSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvHeat5Sts_DrvHeat5Sts
(
    CONST(DrvHeat5Sts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5Sts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvHeat6Sts_DrvHeat6Sts
(
    CONST(DrvHeat6Sts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat6Sts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgSkillsSts10_DrvKneadingMassgSkillsSts10
(
    CONST(DrvKneadingMassgSkillsSts10_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgSkillsSts10, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgSkillsSts5_DrvKneadingMassgSkillsSts5
(
    CONST(DrvKneadingMassgSkillsSts5_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts5, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgSkillsSts6_DrvKneadingMassgSkillsSts6
(
    CONST(DrvKneadingMassgSkillsSts6_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts6, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgSkillsSts7_DrvKneadingMassgSkillsSts7
(
    CONST(DrvKneadingMassgSkillsSts7_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts7, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgSkillsSts8_DrvKneadingMassgSkillsSts8
(
    CONST(DrvKneadingMassgSkillsSts8_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts8, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgSkillsSts9_DrvKneadingMassgSkillsSts9
(
    CONST(DrvKneadingMassgSkillsSts9_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgSkillsSts9, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgTime10_DrvKneadingMassgTime10
(
    CONST(DrvKneadingMassgTime10_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgTime10, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgTime5_DrvKneadingMassgTime5
(
    CONST(DrvKneadingMassgTime5_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime5, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgTime6_DrvKneadingMassgTime6
(
    CONST(DrvKneadingMassgTime6_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime6, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgTime7_DrvKneadingMassgTime7
(
    CONST(DrvKneadingMassgTime7_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime7, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgTime8_DrvKneadingMassgTime8
(
    CONST(DrvKneadingMassgTime8_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime8, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgTime9_DrvKneadingMassgTime9
(
    CONST(DrvKneadingMassgTime9_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgTime9, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassglvlSts10_DrvKneadingMassglvlSts10
(
    CONST(DrvKneadingMassglvlSts10_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassglvlSts10, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassglvlSts5_DrvKneadingMassglvlSts5
(
    CONST(DrvKneadingMassglvlSts5_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts5, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassglvlSts6_DrvKneadingMassglvlSts6
(
    CONST(DrvKneadingMassglvlSts6_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts6, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassglvlSts7_DrvKneadingMassglvlSts7
(
    CONST(DrvKneadingMassglvlSts7_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts7, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassglvlSts8_DrvKneadingMassglvlSts8
(
    CONST(DrvKneadingMassglvlSts8_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts8, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassglvlSts9_DrvKneadingMassglvlSts9
(
    CONST(DrvKneadingMassglvlSts9_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassglvlSts9, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvLumControlSts_DrvLumControlSts
(
    CONST(DrvLumControlSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumControlSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvLumSwitchSts_DrvLumSwitchSts
(
    CONST(DrvLumSwitchSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumSwitchSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvLumbarBottomWorkSts_DrvLumbarBottomWorkSts
(
    CONST(DrvLumbarBottomWorkSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarBottomWorkSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvLumbarMidWorkSts_DrvLumbarMidWorkSts
(
    CONST(DrvLumbarMidWorkSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarMidWorkSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvLumbarTopWorkSts_DrvLumbarTopWorkSts
(
    CONST(DrvLumbarTopWorkSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarTopWorkSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassSwitchSts_DrvMassSwitchSts
(
    CONST(DrvMassSwitchSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvMassSwitchSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC1_DrvMassageHeatNTC1
(
    CONST(DrvMassageHeatNTC1_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC1, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC10_DrvMassageHeatNTC10
(
    CONST(DrvMassageHeatNTC10_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC10, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC11_DrvMassageHeatNTC11
(
    CONST(DrvMassageHeatNTC11_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC11, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC12_DrvMassageHeatNTC12
(
    CONST(DrvMassageHeatNTC12_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC12, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC2_DrvMassageHeatNTC2
(
    CONST(DrvMassageHeatNTC2_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC2, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC3_DrvMassageHeatNTC3
(
    CONST(DrvMassageHeatNTC3_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC3, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC4_DrvMassageHeatNTC4
(
    CONST(DrvMassageHeatNTC4_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC4, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC5_DrvMassageHeatNTC5
(
    CONST(DrvMassageHeatNTC5_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC5, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC6_DrvMassageHeatNTC6
(
    CONST(DrvMassageHeatNTC6_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC6, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC7_DrvMassageHeatNTC7
(
    CONST(DrvMassageHeatNTC7_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC7, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC8_DrvMassageHeatNTC8
(
    CONST(DrvMassageHeatNTC8_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC8, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC9_DrvMassageHeatNTC9
(
    CONST(DrvMassageHeatNTC9_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC9, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvPumpSts_DrvPumpSts
(
    CONST(DrvPumpSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvPumpSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatBlosterValueSts_DrvSeatBlosterValueSts
(
    CONST(DrvSeatBlosterValueSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBlosterValueSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatBolsterValueBLPos_DrvSeatBolsterValueBLPos
(
    CONST(DrvSeatBolsterValueBLPos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBLPos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatBolsterValueBRPos_DrvSeatBolsterValueBRPos
(
    CONST(DrvSeatBolsterValueBRPos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBRPos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatCushionValue1Pos_DrvSeatCushionValue1Pos
(
    CONST(DrvSeatCushionValue1Pos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue1Pos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatCushionValue2Pos_DrvSeatCushionValue2Pos
(
    CONST(DrvSeatCushionValue2Pos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue2Pos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatCushionValue3Pos_DrvSeatCushionValue3Pos
(
    CONST(DrvSeatCushionValue3Pos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatCushionValue3Pos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatCushionValue4Pos_DrvSeatCushionValue4Pos
(
    CONST(DrvSeatCushionValue4Pos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue4Pos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatCushionValue5Pos_DrvSeatCushionValue5Pos
(
    CONST(DrvSeatCushionValue5Pos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue5Pos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatCushionValue6Pos_DrvSeatCushionValue6Pos
(
    CONST(DrvSeatCushionValue6Pos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValue6Pos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatCushionValueSts_DrvSeatCushionValueSts
(
    CONST(DrvSeatCushionValueSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValueSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatLumbarBottomPos_DrvSeatLumbarBottomPos
(
    CONST(DrvSeatLumbarBottomPos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarBottomPos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatLumbarMidPos_DrvSeatLumbarMidPos
(
    CONST(DrvSeatLumbarMidPos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarMidPos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatLumbarTopPos_DrvSeatLumbarTopPos
(
    CONST(DrvSeatLumbarTopPos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarTopPos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatLumbarValueSts_DrvSeatLumbarValueSts
(
    CONST(DrvSeatLumbarValueSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarValueSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatMassFailr_DrvSeatMassFailr
(
    CONST(DrvSeatMassFailr_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatMassFailr, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatUpperValueLPos_DrvSeatUpperValueLPos
(
    CONST(DrvSeatUpperValueLPos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueLPos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatUpperValueMPos_DrvSeatUpperValueMPos
(
    CONST(DrvSeatUpperValueMPos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueMPos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatUpperValueRPos_DrvSeatUpperValueRPos
(
    CONST(DrvSeatUpperValueRPos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueRPos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatUpperValueSts_DrvSeatUpperValueSts
(
    CONST(DrvSeatUpperValueSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatUpperValueSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatmassgHeatCSts_DrvSeatmassgHeatCSts
(
    CONST(DrvSeatmassgHeatCSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgHeatCSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatmassgValveSts_DrvSeatmassgValveSts
(
    CONST(DrvSeatmassgValveSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgValveSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSystemFailr_DrvSystemFailr
(
    CONST(DrvSystemFailr_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_0)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSystemFailr, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassHeat1Sts_PassHeat1Sts
(
    CONST(PassHeat1Sts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat1Sts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassHeat2Sts_PassHeat2Sts
(
    CONST(PassHeat2Sts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat2Sts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassHeat3Sts_PassHeat3Sts
(
    CONST(PassHeat3Sts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat3Sts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassHeat4Sts_PassHeat4Sts
(
    CONST(PassHeat4Sts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat4Sts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassHeat5ErrSts_PassHeat5ErrSts
(
    CONST(PassHeat5ErrSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5ErrSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassHeat5Sts_PassHeat5Sts
(
    CONST(PassHeat5Sts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5Sts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassHeat6Sts_PassHeat6Sts
(
    CONST(PassHeat6Sts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat6Sts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgLvlSts10_PassKneadingMassgLvlSts10
(
    CONST(PassKneadingMassgLvlSts10_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgLvlSts10, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgLvlSts5_PassKneadingMassgLvlSts5
(
    CONST(PassKneadingMassgLvlSts5_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts5, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgLvlSts6_PassKneadingMassgLvlSts6
(
    CONST(PassKneadingMassgLvlSts6_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts6, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgLvlSts7_PassKneadingMassgLvlSts7
(
    CONST(PassKneadingMassgLvlSts7_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts7, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgLvlSts8_PassKneadingMassgLvlSts8
(
    CONST(PassKneadingMassgLvlSts8_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts8, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgLvlSts9_PassKneadingMassgLvlSts9
(
    CONST(PassKneadingMassgLvlSts9_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgLvlSts9, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgSkillsSts10_PassKneadingMassgSkillsSts10
(
    CONST(PassKneadingMassgSkillsSts10_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgSkillsSts10, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgSkillsSts5_PassKneadingMassgSkillsSts5
(
    CONST(PassKneadingMassgSkillsSts5_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts5, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgSkillsSts6_PassKneadingMassgSkillsSts6
(
    CONST(PassKneadingMassgSkillsSts6_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts6, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgSkillsSts7_PassKneadingMassgSkillsSts7
(
    CONST(PassKneadingMassgSkillsSts7_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts7, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgSkillsSts8_PassKneadingMassgSkillsSts8
(
    CONST(PassKneadingMassgSkillsSts8_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts8, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgSkillsSts9_PassKneadingMassgSkillsSts9
(
    CONST(PassKneadingMassgSkillsSts9_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgSkillsSts9, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgTime10_PassKneadingMassgTime10
(
    CONST(PassKneadingMassgTime10_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgTime10, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgTime5_PassKneadingMassgTime5
(
    CONST(PassKneadingMassgTime5_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime5, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgTime6_PassKneadingMassgTime6
(
    CONST(PassKneadingMassgTime6_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime6, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgTime7_PassKneadingMassgTime7
(
    CONST(PassKneadingMassgTime7_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime7, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgTime8_PassKneadingMassgTime8
(
    CONST(PassKneadingMassgTime8_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime8, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgTime9_PassKneadingMassgTime9
(
    CONST(PassKneadingMassgTime9_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgTime9, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassLumControlSts_PassLumControlSts
(
    CONST(PassLumControlSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumControlSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassLumSwitchSts_PassLumSwitchSts
(
    CONST(PassLumSwitchSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumSwitchSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassLumbarBottomWorkSts_PassLumbarBottomWorkSts
(
    CONST(PassLumbarBottomWorkSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarBottomWorkSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassLumbarMidWorkSts_PassLumbarMidWorkSts
(
    CONST(PassLumbarMidWorkSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarMidWorkSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassLumbarTopWorkSts_PassLumbarTopWorkSts
(
    CONST(PassLumbarTopWorkSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarTopWorkSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassSwitchSts_PassMassSwitchSts
(
    CONST(PassMassSwitchSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassMassSwitchSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC1_PassMassageHeatNTC1
(
    CONST(PassMassageHeatNTC1_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC1, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC10_PassMassageHeatNTC10
(
    CONST(PassMassageHeatNTC10_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC10, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC11_PassMassageHeatNTC11
(
    CONST(PassMassageHeatNTC11_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC11, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC12_PassMassageHeatNTC12
(
    CONST(PassMassageHeatNTC12_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC12, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC2_PassMassageHeatNTC2
(
    CONST(PassMassageHeatNTC2_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC2, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC3_PassMassageHeatNTC3
(
    CONST(PassMassageHeatNTC3_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC3, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC4_PassMassageHeatNTC4
(
    CONST(PassMassageHeatNTC4_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC4, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC5_PassMassageHeatNTC5
(
    CONST(PassMassageHeatNTC5_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC5, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC6_PassMassageHeatNTC6
(
    CONST(PassMassageHeatNTC6_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC6, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC7_PassMassageHeatNTC7
(
    CONST(PassMassageHeatNTC7_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC7, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC8_PassMassageHeatNTC8
(
    CONST(PassMassageHeatNTC8_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC8, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC9_PassMassageHeatNTC9
(
    CONST(PassMassageHeatNTC9_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC9, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassPumpSts_PassPumpSts
(
    CONST(PassPumpSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassPumpSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatBlosterValueSts_PassSeatBlosterValueSts
(
    CONST(PassSeatBlosterValueSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBlosterValueSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatBolsterValueBLPos_PassSeatBolsterValueBLPos
(
    CONST(PassSeatBolsterValueBLPos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBLPos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatBolsterValueBRPos_PassSeatBolsterValueBRPos
(
    CONST(PassSeatBolsterValueBRPos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBRPos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatCushionValue1Pos_PassSeatCushionValue1Pos
(
    CONST(PassSeatCushionValue1Pos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue1Pos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatCushionValue2Pos_PassSeatCushionValue2Pos
(
    CONST(PassSeatCushionValue2Pos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue2Pos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatCushionValue3Pos_PassSeatCushionValue3Pos
(
    CONST(PassSeatCushionValue3Pos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatCushionValue3Pos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatCushionValue4Pos_PassSeatCushionValue4Pos
(
    CONST(PassSeatCushionValue4Pos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue4Pos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatCushionValue5Pos_PassSeatCushionValue5Pos
(
    CONST(PassSeatCushionValue5Pos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue5Pos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatCushionValue6Pos_PassSeatCushionValue6Pos
(
    CONST(PassSeatCushionValue6Pos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValue6Pos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatCushionValueSts_PassSeatCushionValueSts
(
    CONST(PassSeatCushionValueSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValueSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatLumbarBottomPos_PassSeatLumbarBottomPos
(
    CONST(PassSeatLumbarBottomPos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarBottomPos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatLumbarMidPos_PassSeatLumbarMidPos
(
    CONST(PassSeatLumbarMidPos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarMidPos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatLumbarTopPos_PassSeatLumbarTopPos
(
    CONST(PassSeatLumbarTopPos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarTopPos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatLumbarValueSts_PassSeatLumbarValueSts
(
    CONST(PassSeatLumbarValueSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarValueSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatMassFailr_PassSeatMassFailr
(
    CONST(PassSeatMassFailr_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatMassFailr, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatUpperValueLPos_PassSeatUpperValueLPos
(
    CONST(PassSeatUpperValueLPos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueLPos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatUpperValueMPos_PassSeatUpperValueMPos
(
    CONST(PassSeatUpperValueMPos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueMPos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatUpperValueRPos_PassSeatUpperValueRPos
(
    CONST(PassSeatUpperValueRPos_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueRPos, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatUpperValueSts_PassSeatUpperValueSts
(
    CONST(PassSeatUpperValueSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatUpperValueSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatmassgHeatCSts_PassSeatmassgHeatCSts
(
    CONST(PassSeatmassgHeatCSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgHeatCSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatmassgValveSts_PassSeatmassgValveSts
(
    CONST(PassSeatmassgValveSts_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgValveSts, &data);


    }

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSystemFailr_PassSystemFailr
(
    CONST(PassSystemFailr_IDT, AUTOMATIC) data
)
{
    Std_ReturnType ret = RTE_E_OK;

    if(*Rte_VarCfgPtr == Rte_Config_1)
    {
        ret = (Std_ReturnType)Com_SendSignal(Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSystemFailr, &data);


    }

    return ret;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"


/*******************************************************************************
*   Rte Api for Mode Switch port of ComM
*******************************************************************************/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_ComM_UM_User0_ComMMode
(
    CONST(Rte_ModeType_ComMMode, AUTOMATIC) nextMode
)
{
    Std_ReturnType ret = RTE_E_OK;
    /*Rte_Switch_ComM_UM_User0_ComMMode User Code start*/

    /*Rte_Switch_ComM_UM_User0_ComMMode User Code end*/

    return ret;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"


/*******************************************************************************
*   Rte Api for Mode Switch port of EcuM
*******************************************************************************/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_EcuM_currentMode_currentMode
(
    CONST(Rte_ModeType_EcuM_Mode, AUTOMATIC) nextMode
)
{
    Std_ReturnType ret = RTE_E_OK;
    /*Rte_Switch_EcuM_currentMode_currentMode User Code start*/

    /*Rte_Switch_EcuM_currentMode_currentMode User Code end*/

    return ret;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"




