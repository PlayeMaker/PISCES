/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_Private_Var.h
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
#ifndef RTE_PRIVATE_VAR_H
#define RTE_PRIVATE_VAR_H


#include "Rte_Private_Type.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
extern FUNC(void, RTE_CODE) Rte_MemInit(
    P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, 
    uint32_least num
);
extern FUNC(void, RTE_CODE) Rte_MemCpy(
    P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, 
    P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, 
    uint32_least num
); 

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*******************************************************************************
*   ComCfgSet Define   *
*******************************************************************************/
extern P2CONST(uint8, AUTOMATIC, RTE_CONST) Rte_VarCfgPtr;


/*******************************************************************************
*   State
*******************************************************************************/
#define RTE_START_SEC_VAR_INIT_LOCAL_UNSPECIFIED_Com
#include "Rte_MemMap.h"
extern VAR(boolean, RTE_VAR) RTE_Day_Day_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvPumpCmd_DrvPumpCmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatBolsterValueBLCmd_DrvSeatBolsterValueBLCmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatBolsterValueBRCmd_DrvSeatBolsterValueBRCmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatCushionValue1Cmd_DrvSeatCushionValue1Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatCushionValue2Cmd_DrvSeatCushionValue2Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatCushionValue3Cmd_DrvSeatCushionValue3Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatCushionValue4Cmd_DrvSeatCushionValue4Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatCushionValue5Cmd_DrvSeatCushionValue5Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatCushionValue6Cmd_DrvSeatCushionValue6Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatLumbarBottomValue3Cmd_DrvSeatLumbarBottomValue3Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatLumbarMidValue2Cmd_DrvSeatLumbarMidValue2Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatLumbarTopValue1Cmd_DrvSeatLumbarTopValue1Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatUpperValueLCmd_DrvSeatUpperValueLCmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatUpperValueMCmd_DrvSeatUpperValueMCmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatUpperValueRCmd_DrvSeatUpperValueRCmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat10Cmd_DrvSeatmassgHeat10Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat11Cmd_DrvSeatmassgHeat11Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat12Cmd_DrvSeatmassgHeat12Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat1Cmd_DrvSeatmassgHeat1Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat2Cmd_DrvSeatmassgHeat2Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat3Cmd_DrvSeatmassgHeat3Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat4Cmd_DrvSeatmassgHeat4Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat5Cmd_DrvSeatmassgHeat5Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat6Cmd_DrvSeatmassgHeat6Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat7Cmd_DrvSeatmassgHeat7Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat8Cmd_DrvSeatmassgHeat8Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgHeat9Cmd_DrvSeatmassgHeat9Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve10Cmd_DrvSeatmassgValve10Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve11Cmd_DrvSeatmassgValve11Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve12Cmd_DrvSeatmassgValve12Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve1Cmd_DrvSeatmassgValve1Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve2Cmd_DrvSeatmassgValve2Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve3Cmd_DrvSeatmassgValve3Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve4Cmd_DrvSeatmassgValve4Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve5Cmd_DrvSeatmassgValve5Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve6Cmd_DrvSeatmassgValve6Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve7Cmd_DrvSeatmassgValve7Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve8Cmd_DrvSeatmassgValve8Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvSeatmassgValve9Cmd_DrvSeatmassgValve9Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvState_DrvState_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_DrvState_SrvSts_DrvState_SrvSts_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_Hr_Hr_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_MSec_MSec_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_Min_Min_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_Mth_Mth_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_OperatorState_OperatorState_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_OperatorState_SrvSts_OperatorState_SrvSts_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassPumpCmd_PassPumpCmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatBolsterValueBLCmd_PassSeatBolsterValueBLCmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatBolsterValueBRCmd_PassSeatBolsterValueBRCmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatCushionValue1Cmd_PassSeatCushionValue1Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatCushionValue2Cmd_PassSeatCushionValue2Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatCushionValue3Cmd_PassSeatCushionValue3Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatCushionValue4Cmd_PassSeatCushionValue4Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatCushionValue5Cmd_PassSeatCushionValue5Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatCushionValue6Cmd_PassSeatCushionValue6Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatLumbarBottomValue3Cmd_PassSeatLumbarBottomValue3Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatLumbarMidValue2Cmd_PassSeatLumbarMidValue2Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatLumbarTopValue1Cmd_PassSeatLumbarTopValue1Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatUpperValueLCmd_PassSeatUpperValueLCmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatUpperValueMCmd_PassSeatUpperValueMCmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatUpperValueRCmd_PassSeatUpperValueRCmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat10Cmd_PassSeatmassgHeat10Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat11Cmd_PassSeatmassgHeat11Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat12Cmd_PassSeatmassgHeat12Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat1Cmd_PassSeatmassgHeat1Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat2Cmd_PassSeatmassgHeat2Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat3Cmd_PassSeatmassgHeat3Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat4Cmd_PassSeatmassgHeat4Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat5Cmd_PassSeatmassgHeat5Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat6Cmd_PassSeatmassgHeat6Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat7Cmd_PassSeatmassgHeat7Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat8Cmd_PassSeatmassgHeat8Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgHeat9Cmd_PassSeatmassgHeat9Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve10Cmd_PassSeatmassgValve10Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve11Cmd_PassSeatmassgValve11Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve12Cmd_PassSeatmassgValve12Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve1Cmd_PassSeatmassgValve1Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve2Cmd_PassSeatmassgValve2Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve3Cmd_PassSeatmassgValve3Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve4Cmd_PassSeatmassgValve4Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve5Cmd_PassSeatmassgValve5Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve6Cmd_PassSeatmassgValve6Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve7Cmd_PassSeatmassgValve7Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve8Cmd_PassSeatmassgValve8Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_PassSeatmassgValve9Cmd_PassSeatmassgValve9Cmd_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_Sec_Sec_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_VehModeDef_VehModeDef_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_VehOdometer_VehOdometer_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_VehStateDetailed_VehStateDetailed_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_VehStateDetailed_SrvSts_VehStateDetailed_SrvSts_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_Yr_Yr_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_ZONE_13C_CRC_ZONE_13C_CRC_TIMEOUT_FLAG;
extern VAR(boolean, RTE_VAR) RTE_ZONE_13C_MsgCntr_ZONE_13C_MsgCntr_TIMEOUT_FLAG;
#define RTE_STOP_SEC_VAR_INIT_LOCAL_UNSPECIFIED_Com
#include "Rte_MemMap.h"


#endif
