/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_Com.h
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


#ifndef RTE_COM_H
#define RTE_COM_H

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
#include "Com.h"
#include "Rte_Com_Type.h"
#define Rte_Read_BattVolt_LBMR_BattVolt_LBMR                Rte_Read_Com_BattVolt_LBMR_BattVolt_LBMR
#define Rte_Read_Day_Day                                    Rte_Read_Com_Day_Day
#define Rte_Read_DrvHeat1_pct_DrvHeat1_pct                  Rte_Read_Com_DrvHeat1_pct_DrvHeat1_pct
#define Rte_Read_DrvHeat2_pct_DrvHeat2_pct                  Rte_Read_Com_DrvHeat2_pct_DrvHeat2_pct
#define Rte_Read_DrvHeat3_pct_DrvHeat3_pct                  Rte_Read_Com_DrvHeat3_pct_DrvHeat3_pct
#define Rte_Read_DrvHeat4_pct_DrvHeat4_pct                  Rte_Read_Com_DrvHeat4_pct_DrvHeat4_pct
#define Rte_Read_DrvHeat5_pct_DrvHeat5_pct                  Rte_Read_Com_DrvHeat5_pct_DrvHeat5_pct
#define Rte_Read_DrvHeat6_pct_DrvHeat6_pct                  Rte_Read_Com_DrvHeat6_pct_DrvHeat6_pct
#define Rte_Read_DrvKneadingMassgLvlCmd10_DrvKneadingMassgLvlCmd10    Rte_Read_Com_DrvKneadingMassgLvlCmd10_DrvKneadingMassgLvlCmd10
#define Rte_Read_DrvKneadingMassgLvlCmd5_DrvKneadingMassgLvlCmd5      Rte_Read_Com_DrvKneadingMassgLvlCmd5_DrvKneadingMassgLvlCmd5
#define Rte_Read_DrvKneadingMassgLvlCmd6_DrvKneadingMassgLvlCmd6      Rte_Read_Com_DrvKneadingMassgLvlCmd6_DrvKneadingMassgLvlCmd6
#define Rte_Read_DrvKneadingMassgLvlCmd7_DrvKneadingMassgLvlCmd7      Rte_Read_Com_DrvKneadingMassgLvlCmd7_DrvKneadingMassgLvlCmd7
#define Rte_Read_DrvKneadingMassgLvlCmd8_DrvKneadingMassgLvlCmd8      Rte_Read_Com_DrvKneadingMassgLvlCmd8_DrvKneadingMassgLvlCmd8
#define Rte_Read_DrvKneadingMassgLvlCmd9_DrvKneadingMassgLvlCmd9      Rte_Read_Com_DrvKneadingMassgLvlCmd9_DrvKneadingMassgLvlCmd9
#define Rte_Read_DrvKneadingMassgSkillsCmd10_DrvKneadingMassgSkillsCmd10        Rte_Read_Com_DrvKneadingMassgSkillsCmd10_DrvKneadingMassgSkillsCmd10
#define Rte_Read_DrvKneadingMassgSkillsCmd5_DrvKneadingMassgSkillsCmd5          Rte_Read_Com_DrvKneadingMassgSkillsCmd5_DrvKneadingMassgSkillsCmd5
#define Rte_Read_DrvKneadingMassgSkillsCmd6_DrvKneadingMassgSkillsCmd6          Rte_Read_Com_DrvKneadingMassgSkillsCmd6_DrvKneadingMassgSkillsCmd6
#define Rte_Read_DrvKneadingMassgSkillsCmd7_DrvKneadingMassgSkillsCmd7          Rte_Read_Com_DrvKneadingMassgSkillsCmd7_DrvKneadingMassgSkillsCmd7
#define Rte_Read_DrvKneadingMassgSkillsCmd8_DrvKneadingMassgSkillsCmd8          Rte_Read_Com_DrvKneadingMassgSkillsCmd8_DrvKneadingMassgSkillsCmd8
#define Rte_Read_DrvKneadingMassgSkillsCmd9_DrvKneadingMassgSkillsCmd9          Rte_Read_Com_DrvKneadingMassgSkillsCmd9_DrvKneadingMassgSkillsCmd9
#define Rte_Read_DrvKneadingMassgTimesCmd10_DrvKneadingMassgTimesCmd10          Rte_Read_Com_DrvKneadingMassgTimesCmd10_DrvKneadingMassgTimesCmd10
#define Rte_Read_DrvKneadingMassgTimesCmd5_DrvKneadingMassgTimesCmd5  Rte_Read_Com_DrvKneadingMassgTimesCmd5_DrvKneadingMassgTimesCmd5
#define Rte_Read_DrvKneadingMassgTimesCmd6_DrvKneadingMassgTimesCmd6  Rte_Read_Com_DrvKneadingMassgTimesCmd6_DrvKneadingMassgTimesCmd6
#define Rte_Read_DrvKneadingMassgTimesCmd7_DrvKneadingMassgTimesCmd7  Rte_Read_Com_DrvKneadingMassgTimesCmd7_DrvKneadingMassgTimesCmd7
#define Rte_Read_DrvKneadingMassgTimesCmd8_DrvKneadingMassgTimesCmd8  Rte_Read_Com_DrvKneadingMassgTimesCmd8_DrvKneadingMassgTimesCmd8
#define Rte_Read_DrvKneadingMassgTimesCmd9_DrvKneadingMassgTimesCmd9  Rte_Read_Com_DrvKneadingMassgTimesCmd9_DrvKneadingMassgTimesCmd9
#define Rte_Read_DrvPumpCmd_DrvPumpCmd                      Rte_Read_Com_DrvPumpCmd_DrvPumpCmd
#define Rte_Read_DrvSeatBolsterValueBLCmd_DrvSeatBolsterValueBLCmd    Rte_Read_Com_DrvSeatBolsterValueBLCmd_DrvSeatBolsterValueBLCmd
#define Rte_Read_DrvSeatBolsterValueBRCmd_DrvSeatBolsterValueBRCmd    Rte_Read_Com_DrvSeatBolsterValueBRCmd_DrvSeatBolsterValueBRCmd
#define Rte_Read_DrvSeatCushionValue1Cmd_DrvSeatCushionValue1Cmd      Rte_Read_Com_DrvSeatCushionValue1Cmd_DrvSeatCushionValue1Cmd
#define Rte_Read_DrvSeatCushionValue2Cmd_DrvSeatCushionValue2Cmd      Rte_Read_Com_DrvSeatCushionValue2Cmd_DrvSeatCushionValue2Cmd
#define Rte_Read_DrvSeatCushionValue3Cmd_DrvSeatCushionValue3Cmd      Rte_Read_Com_DrvSeatCushionValue3Cmd_DrvSeatCushionValue3Cmd
#define Rte_Read_DrvSeatCushionValue4Cmd_DrvSeatCushionValue4Cmd      Rte_Read_Com_DrvSeatCushionValue4Cmd_DrvSeatCushionValue4Cmd
#define Rte_Read_DrvSeatCushionValue5Cmd_DrvSeatCushionValue5Cmd      Rte_Read_Com_DrvSeatCushionValue5Cmd_DrvSeatCushionValue5Cmd
#define Rte_Read_DrvSeatCushionValue6Cmd_DrvSeatCushionValue6Cmd      Rte_Read_Com_DrvSeatCushionValue6Cmd_DrvSeatCushionValue6Cmd
#define Rte_Read_DrvSeatLumbarBottomValue3Cmd_DrvSeatLumbarBottomValue3Cmd      Rte_Read_Com_DrvSeatLumbarBottomValue3Cmd_DrvSeatLumbarBottomValue3Cmd
#define Rte_Read_DrvSeatLumbarMidValue2Cmd_DrvSeatLumbarMidValue2Cmd  Rte_Read_Com_DrvSeatLumbarMidValue2Cmd_DrvSeatLumbarMidValue2Cmd
#define Rte_Read_DrvSeatLumbarTopValue1Cmd_DrvSeatLumbarTopValue1Cmd  Rte_Read_Com_DrvSeatLumbarTopValue1Cmd_DrvSeatLumbarTopValue1Cmd
#define Rte_Read_DrvSeatUpperValueLCmd_DrvSeatUpperValueLCmd          Rte_Read_Com_DrvSeatUpperValueLCmd_DrvSeatUpperValueLCmd
#define Rte_Read_DrvSeatUpperValueMCmd_DrvSeatUpperValueMCmd          Rte_Read_Com_DrvSeatUpperValueMCmd_DrvSeatUpperValueMCmd
#define Rte_Read_DrvSeatUpperValueRCmd_DrvSeatUpperValueRCmd          Rte_Read_Com_DrvSeatUpperValueRCmd_DrvSeatUpperValueRCmd
#define Rte_Read_DrvSeatmassgHeat10Cmd_DrvSeatmassgHeat10Cmd          Rte_Read_Com_DrvSeatmassgHeat10Cmd_DrvSeatmassgHeat10Cmd
#define Rte_Read_DrvSeatmassgHeat11Cmd_DrvSeatmassgHeat11Cmd          Rte_Read_Com_DrvSeatmassgHeat11Cmd_DrvSeatmassgHeat11Cmd
#define Rte_Read_DrvSeatmassgHeat12Cmd_DrvSeatmassgHeat12Cmd          Rte_Read_Com_DrvSeatmassgHeat12Cmd_DrvSeatmassgHeat12Cmd
#define Rte_Read_DrvSeatmassgHeat1Cmd_DrvSeatmassgHeat1Cmd  Rte_Read_Com_DrvSeatmassgHeat1Cmd_DrvSeatmassgHeat1Cmd
#define Rte_Read_DrvSeatmassgHeat2Cmd_DrvSeatmassgHeat2Cmd  Rte_Read_Com_DrvSeatmassgHeat2Cmd_DrvSeatmassgHeat2Cmd
#define Rte_Read_DrvSeatmassgHeat3Cmd_DrvSeatmassgHeat3Cmd  Rte_Read_Com_DrvSeatmassgHeat3Cmd_DrvSeatmassgHeat3Cmd
#define Rte_Read_DrvSeatmassgHeat4Cmd_DrvSeatmassgHeat4Cmd  Rte_Read_Com_DrvSeatmassgHeat4Cmd_DrvSeatmassgHeat4Cmd
#define Rte_Read_DrvSeatmassgHeat5Cmd_DrvSeatmassgHeat5Cmd  Rte_Read_Com_DrvSeatmassgHeat5Cmd_DrvSeatmassgHeat5Cmd
#define Rte_Read_DrvSeatmassgHeat6Cmd_DrvSeatmassgHeat6Cmd  Rte_Read_Com_DrvSeatmassgHeat6Cmd_DrvSeatmassgHeat6Cmd
#define Rte_Read_DrvSeatmassgHeat7Cmd_DrvSeatmassgHeat7Cmd  Rte_Read_Com_DrvSeatmassgHeat7Cmd_DrvSeatmassgHeat7Cmd
#define Rte_Read_DrvSeatmassgHeat8Cmd_DrvSeatmassgHeat8Cmd  Rte_Read_Com_DrvSeatmassgHeat8Cmd_DrvSeatmassgHeat8Cmd
#define Rte_Read_DrvSeatmassgHeat9Cmd_DrvSeatmassgHeat9Cmd  Rte_Read_Com_DrvSeatmassgHeat9Cmd_DrvSeatmassgHeat9Cmd
#define Rte_Read_DrvSeatmassgValve10Cmd_DrvSeatmassgValve10Cmd        Rte_Read_Com_DrvSeatmassgValve10Cmd_DrvSeatmassgValve10Cmd
#define Rte_Read_DrvSeatmassgValve11Cmd_DrvSeatmassgValve11Cmd        Rte_Read_Com_DrvSeatmassgValve11Cmd_DrvSeatmassgValve11Cmd
#define Rte_Read_DrvSeatmassgValve12Cmd_DrvSeatmassgValve12Cmd        Rte_Read_Com_DrvSeatmassgValve12Cmd_DrvSeatmassgValve12Cmd
#define Rte_Read_DrvSeatmassgValve1Cmd_DrvSeatmassgValve1Cmd          Rte_Read_Com_DrvSeatmassgValve1Cmd_DrvSeatmassgValve1Cmd
#define Rte_Read_DrvSeatmassgValve2Cmd_DrvSeatmassgValve2Cmd          Rte_Read_Com_DrvSeatmassgValve2Cmd_DrvSeatmassgValve2Cmd
#define Rte_Read_DrvSeatmassgValve3Cmd_DrvSeatmassgValve3Cmd          Rte_Read_Com_DrvSeatmassgValve3Cmd_DrvSeatmassgValve3Cmd
#define Rte_Read_DrvSeatmassgValve4Cmd_DrvSeatmassgValve4Cmd          Rte_Read_Com_DrvSeatmassgValve4Cmd_DrvSeatmassgValve4Cmd
#define Rte_Read_DrvSeatmassgValve5Cmd_DrvSeatmassgValve5Cmd          Rte_Read_Com_DrvSeatmassgValve5Cmd_DrvSeatmassgValve5Cmd
#define Rte_Read_DrvSeatmassgValve6Cmd_DrvSeatmassgValve6Cmd          Rte_Read_Com_DrvSeatmassgValve6Cmd_DrvSeatmassgValve6Cmd
#define Rte_Read_DrvSeatmassgValve7Cmd_DrvSeatmassgValve7Cmd          Rte_Read_Com_DrvSeatmassgValve7Cmd_DrvSeatmassgValve7Cmd
#define Rte_Read_DrvSeatmassgValve8Cmd_DrvSeatmassgValve8Cmd          Rte_Read_Com_DrvSeatmassgValve8Cmd_DrvSeatmassgValve8Cmd
#define Rte_Read_DrvSeatmassgValve9Cmd_DrvSeatmassgValve9Cmd          Rte_Read_Com_DrvSeatmassgValve9Cmd_DrvSeatmassgValve9Cmd
#define Rte_Read_DrvState_DrvState                          Rte_Read_Com_DrvState_DrvState
#define Rte_Read_DrvState_SrvSts_DrvState_SrvSts            Rte_Read_Com_DrvState_SrvSts_DrvState_SrvSts
#define Rte_Read_Hr_Hr                                      Rte_Read_Com_Hr_Hr
#define Rte_Read_MSec_MSec                                  Rte_Read_Com_MSec_MSec
#define Rte_Read_Min_Min                                    Rte_Read_Com_Min_Min
#define Rte_Read_Mth_Mth                                    Rte_Read_Com_Mth_Mth
#define Rte_Read_OperatorState_OperatorState                Rte_Read_Com_OperatorState_OperatorState
#define Rte_Read_OperatorState_SrvSts_OperatorState_SrvSts  Rte_Read_Com_OperatorState_SrvSts_OperatorState_SrvSts
#define Rte_Read_PNC10_Sts_PNC10_Sts                        Rte_Read_Com_PNC10_Sts_PNC10_Sts
#define Rte_Read_PNC11_Sts_PNC11_Sts                        Rte_Read_Com_PNC11_Sts_PNC11_Sts
#define Rte_Read_PNC12_Sts_PNC12_Sts                        Rte_Read_Com_PNC12_Sts_PNC12_Sts
#define Rte_Read_PNC13_Sts_PNC13_Sts                        Rte_Read_Com_PNC13_Sts_PNC13_Sts
#define Rte_Read_PNC14_Sts_PNC14_Sts                        Rte_Read_Com_PNC14_Sts_PNC14_Sts
#define Rte_Read_PNC15_Sts_PNC15_Sts                        Rte_Read_Com_PNC15_Sts_PNC15_Sts
#define Rte_Read_PNC16_Sts_PNC16_Sts                        Rte_Read_Com_PNC16_Sts_PNC16_Sts
#define Rte_Read_PNC17_Sts_PNC17_Sts                        Rte_Read_Com_PNC17_Sts_PNC17_Sts
#define Rte_Read_PNC18_Sts_PNC18_Sts                        Rte_Read_Com_PNC18_Sts_PNC18_Sts
#define Rte_Read_PNC19_Sts_PNC19_Sts                        Rte_Read_Com_PNC19_Sts_PNC19_Sts
#define Rte_Read_PNC1_Sts_PNC1_Sts                          Rte_Read_Com_PNC1_Sts_PNC1_Sts
#define Rte_Read_PNC20_Sts_PNC20_Sts                        Rte_Read_Com_PNC20_Sts_PNC20_Sts
#define Rte_Read_PNC21_Sts_PNC21_Sts                        Rte_Read_Com_PNC21_Sts_PNC21_Sts
#define Rte_Read_PNC22_Sts_PNC22_Sts                        Rte_Read_Com_PNC22_Sts_PNC22_Sts
#define Rte_Read_PNC23_Sts_PNC23_Sts                        Rte_Read_Com_PNC23_Sts_PNC23_Sts
#define Rte_Read_PNC24_Sts_PNC24_Sts                        Rte_Read_Com_PNC24_Sts_PNC24_Sts
#define Rte_Read_PNC25_Sts_PNC25_Sts                        Rte_Read_Com_PNC25_Sts_PNC25_Sts
#define Rte_Read_PNC26_Sts_PNC26_Sts                        Rte_Read_Com_PNC26_Sts_PNC26_Sts
#define Rte_Read_PNC27_Sts_PNC27_Sts                        Rte_Read_Com_PNC27_Sts_PNC27_Sts
#define Rte_Read_PNC28_Sts_PNC28_Sts                        Rte_Read_Com_PNC28_Sts_PNC28_Sts
#define Rte_Read_PNC29_Sts_PNC29_Sts                        Rte_Read_Com_PNC29_Sts_PNC29_Sts
#define Rte_Read_PNC2_Sts_PNC2_Sts                          Rte_Read_Com_PNC2_Sts_PNC2_Sts
#define Rte_Read_PNC30_Sts_PNC30_Sts                        Rte_Read_Com_PNC30_Sts_PNC30_Sts
#define Rte_Read_PNC31_Sts_PNC31_Sts                        Rte_Read_Com_PNC31_Sts_PNC31_Sts
#define Rte_Read_PNC32_Sts_PNC32_Sts                        Rte_Read_Com_PNC32_Sts_PNC32_Sts
#define Rte_Read_PNC33_Sts_PNC33_Sts                        Rte_Read_Com_PNC33_Sts_PNC33_Sts
#define Rte_Read_PNC34_Sts_PNC34_Sts                        Rte_Read_Com_PNC34_Sts_PNC34_Sts
#define Rte_Read_PNC35_Sts_PNC35_Sts                        Rte_Read_Com_PNC35_Sts_PNC35_Sts
#define Rte_Read_PNC36_Sts_PNC36_Sts                        Rte_Read_Com_PNC36_Sts_PNC36_Sts
#define Rte_Read_PNC37_Sts_PNC37_Sts                        Rte_Read_Com_PNC37_Sts_PNC37_Sts
#define Rte_Read_PNC38_Sts_PNC38_Sts                        Rte_Read_Com_PNC38_Sts_PNC38_Sts
#define Rte_Read_PNC39_Sts_PNC39_Sts                        Rte_Read_Com_PNC39_Sts_PNC39_Sts
#define Rte_Read_PNC3_Sts_PNC3_Sts                          Rte_Read_Com_PNC3_Sts_PNC3_Sts
#define Rte_Read_PNC40_Sts_PNC40_Sts                        Rte_Read_Com_PNC40_Sts_PNC40_Sts
#define Rte_Read_PNC41_Sts_PNC41_Sts                        Rte_Read_Com_PNC41_Sts_PNC41_Sts
#define Rte_Read_PNC42_Sts_PNC42_Sts                        Rte_Read_Com_PNC42_Sts_PNC42_Sts
#define Rte_Read_PNC43_Sts_PNC43_Sts                        Rte_Read_Com_PNC43_Sts_PNC43_Sts
#define Rte_Read_PNC44_Sts_PNC44_Sts                        Rte_Read_Com_PNC44_Sts_PNC44_Sts
#define Rte_Read_PNC45_Sts_PNC45_Sts                        Rte_Read_Com_PNC45_Sts_PNC45_Sts
#define Rte_Read_PNC46_Sts_PNC46_Sts                        Rte_Read_Com_PNC46_Sts_PNC46_Sts
#define Rte_Read_PNC47_Sts_PNC47_Sts                        Rte_Read_Com_PNC47_Sts_PNC47_Sts
#define Rte_Read_PNC48_Sts_PNC48_Sts                        Rte_Read_Com_PNC48_Sts_PNC48_Sts
#define Rte_Read_PNC4_Sts_PNC4_Sts                          Rte_Read_Com_PNC4_Sts_PNC4_Sts
#define Rte_Read_PNC5_Sts_PNC5_Sts                          Rte_Read_Com_PNC5_Sts_PNC5_Sts
#define Rte_Read_PNC6_Sts_PNC6_Sts                          Rte_Read_Com_PNC6_Sts_PNC6_Sts
#define Rte_Read_PNC7_Sts_PNC7_Sts                          Rte_Read_Com_PNC7_Sts_PNC7_Sts
#define Rte_Read_PNC8_Sts_PNC8_Sts                          Rte_Read_Com_PNC8_Sts_PNC8_Sts
#define Rte_Read_PNC9_Sts_PNC9_Sts                          Rte_Read_Com_PNC9_Sts_PNC9_Sts
#define Rte_Read_PNC_DFT_PNC_DFT                            Rte_Read_Com_PNC_DFT_PNC_DFT
#define Rte_Read_PassHeat1_pct_PassHeat1_pct                Rte_Read_Com_PassHeat1_pct_PassHeat1_pct
#define Rte_Read_PassHeat2_pct_PassHeat2_pct                Rte_Read_Com_PassHeat2_pct_PassHeat2_pct
#define Rte_Read_PassHeat3_pct_PassHeat3_pct                Rte_Read_Com_PassHeat3_pct_PassHeat3_pct
#define Rte_Read_PassHeat4_pct_PassHeat4_pct                Rte_Read_Com_PassHeat4_pct_PassHeat4_pct
#define Rte_Read_PassHeat5_pct_PassHeat5_pct                Rte_Read_Com_PassHeat5_pct_PassHeat5_pct
#define Rte_Read_PassHeat6_pct_PassHeat6_pct                Rte_Read_Com_PassHeat6_pct_PassHeat6_pct
#define Rte_Read_PassKneadingMassgLvlCmd10_PassKneadingMassgLvlCmd10  Rte_Read_Com_PassKneadingMassgLvlCmd10_PassKneadingMassgLvlCmd10
#define Rte_Read_PassKneadingMassgLvlCmd5_PassKneadingMassgLvlCmd5    Rte_Read_Com_PassKneadingMassgLvlCmd5_PassKneadingMassgLvlCmd5
#define Rte_Read_PassKneadingMassgLvlCmd6_PassKneadingMassgLvlCmd6    Rte_Read_Com_PassKneadingMassgLvlCmd6_PassKneadingMassgLvlCmd6
#define Rte_Read_PassKneadingMassgLvlCmd7_PassKneadingMassgLvlCmd7    Rte_Read_Com_PassKneadingMassgLvlCmd7_PassKneadingMassgLvlCmd7
#define Rte_Read_PassKneadingMassgLvlCmd8_PassKneadingMassgLvlCmd8    Rte_Read_Com_PassKneadingMassgLvlCmd8_PassKneadingMassgLvlCmd8
#define Rte_Read_PassKneadingMassgLvlCmd9_PassKneadingMassgLvlCmd9    Rte_Read_Com_PassKneadingMassgLvlCmd9_PassKneadingMassgLvlCmd9
#define Rte_Read_PassKneadingMassgSkillsCmd10_PassKneadingMassgSkillsCmd10      Rte_Read_Com_PassKneadingMassgSkillsCmd10_PassKneadingMassgSkillsCmd10
#define Rte_Read_PassKneadingMassgSkillsCmd5_PassKneadingMassgSkillsCmd5        Rte_Read_Com_PassKneadingMassgSkillsCmd5_PassKneadingMassgSkillsCmd5
#define Rte_Read_PassKneadingMassgSkillsCmd6_PassKneadingMassgSkillsCmd6        Rte_Read_Com_PassKneadingMassgSkillsCmd6_PassKneadingMassgSkillsCmd6
#define Rte_Read_PassKneadingMassgSkillsCmd7_PassKneadingMassgSkillsCmd7        Rte_Read_Com_PassKneadingMassgSkillsCmd7_PassKneadingMassgSkillsCmd7
#define Rte_Read_PassKneadingMassgSkillsCmd8_PassKneadingMassgSkillsCmd8        Rte_Read_Com_PassKneadingMassgSkillsCmd8_PassKneadingMassgSkillsCmd8
#define Rte_Read_PassKneadingMassgSkillsCmd9_PassKneadingMassgSkillsCmd9        Rte_Read_Com_PassKneadingMassgSkillsCmd9_PassKneadingMassgSkillsCmd9
#define Rte_Read_PassKneadingMassgTimesCmd10_PassKneadingMassgTimesCmd10        Rte_Read_Com_PassKneadingMassgTimesCmd10_PassKneadingMassgTimesCmd10
#define Rte_Read_PassKneadingMassgTimesCmd5_PassKneadingMassgTimesCmd5          Rte_Read_Com_PassKneadingMassgTimesCmd5_PassKneadingMassgTimesCmd5
#define Rte_Read_PassKneadingMassgTimesCmd6_PassKneadingMassgTimesCmd6          Rte_Read_Com_PassKneadingMassgTimesCmd6_PassKneadingMassgTimesCmd6
#define Rte_Read_PassKneadingMassgTimesCmd7_PassKneadingMassgTimesCmd7          Rte_Read_Com_PassKneadingMassgTimesCmd7_PassKneadingMassgTimesCmd7
#define Rte_Read_PassKneadingMassgTimesCmd8_PassKneadingMassgTimesCmd8          Rte_Read_Com_PassKneadingMassgTimesCmd8_PassKneadingMassgTimesCmd8
#define Rte_Read_PassKneadingMassgTimesCmd9_PassKneadingMassgTimesCmd9          Rte_Read_Com_PassKneadingMassgTimesCmd9_PassKneadingMassgTimesCmd9
#define Rte_Read_PassPumpCmd_PassPumpCmd                    Rte_Read_Com_PassPumpCmd_PassPumpCmd
#define Rte_Read_PassSeatBolsterValueBLCmd_PassSeatBolsterValueBLCmd  Rte_Read_Com_PassSeatBolsterValueBLCmd_PassSeatBolsterValueBLCmd
#define Rte_Read_PassSeatBolsterValueBRCmd_PassSeatBolsterValueBRCmd  Rte_Read_Com_PassSeatBolsterValueBRCmd_PassSeatBolsterValueBRCmd
#define Rte_Read_PassSeatCushionValue1Cmd_PassSeatCushionValue1Cmd    Rte_Read_Com_PassSeatCushionValue1Cmd_PassSeatCushionValue1Cmd
#define Rte_Read_PassSeatCushionValue2Cmd_PassSeatCushionValue2Cmd    Rte_Read_Com_PassSeatCushionValue2Cmd_PassSeatCushionValue2Cmd
#define Rte_Read_PassSeatCushionValue3Cmd_PassSeatCushionValue3Cmd    Rte_Read_Com_PassSeatCushionValue3Cmd_PassSeatCushionValue3Cmd
#define Rte_Read_PassSeatCushionValue4Cmd_PassSeatCushionValue4Cmd    Rte_Read_Com_PassSeatCushionValue4Cmd_PassSeatCushionValue4Cmd
#define Rte_Read_PassSeatCushionValue5Cmd_PassSeatCushionValue5Cmd    Rte_Read_Com_PassSeatCushionValue5Cmd_PassSeatCushionValue5Cmd
#define Rte_Read_PassSeatCushionValue6Cmd_PassSeatCushionValue6Cmd    Rte_Read_Com_PassSeatCushionValue6Cmd_PassSeatCushionValue6Cmd
#define Rte_Read_PassSeatLumbarBottomValue3Cmd_PassSeatLumbarBottomValue3Cmd    Rte_Read_Com_PassSeatLumbarBottomValue3Cmd_PassSeatLumbarBottomValue3Cmd
#define Rte_Read_PassSeatLumbarMidValue2Cmd_PassSeatLumbarMidValue2Cmd          Rte_Read_Com_PassSeatLumbarMidValue2Cmd_PassSeatLumbarMidValue2Cmd
#define Rte_Read_PassSeatLumbarTopValue1Cmd_PassSeatLumbarTopValue1Cmd          Rte_Read_Com_PassSeatLumbarTopValue1Cmd_PassSeatLumbarTopValue1Cmd
#define Rte_Read_PassSeatUpperValueLCmd_PassSeatUpperValueLCmd        Rte_Read_Com_PassSeatUpperValueLCmd_PassSeatUpperValueLCmd
#define Rte_Read_PassSeatUpperValueMCmd_PassSeatUpperValueMCmd        Rte_Read_Com_PassSeatUpperValueMCmd_PassSeatUpperValueMCmd
#define Rte_Read_PassSeatUpperValueRCmd_PassSeatUpperValueRCmd        Rte_Read_Com_PassSeatUpperValueRCmd_PassSeatUpperValueRCmd
#define Rte_Read_PassSeatmassgHeat10Cmd_PassSeatmassgHeat10Cmd        Rte_Read_Com_PassSeatmassgHeat10Cmd_PassSeatmassgHeat10Cmd
#define Rte_Read_PassSeatmassgHeat11Cmd_PassSeatmassgHeat11Cmd        Rte_Read_Com_PassSeatmassgHeat11Cmd_PassSeatmassgHeat11Cmd
#define Rte_Read_PassSeatmassgHeat12Cmd_PassSeatmassgHeat12Cmd        Rte_Read_Com_PassSeatmassgHeat12Cmd_PassSeatmassgHeat12Cmd
#define Rte_Read_PassSeatmassgHeat1Cmd_PassSeatmassgHeat1Cmd          Rte_Read_Com_PassSeatmassgHeat1Cmd_PassSeatmassgHeat1Cmd
#define Rte_Read_PassSeatmassgHeat2Cmd_PassSeatmassgHeat2Cmd          Rte_Read_Com_PassSeatmassgHeat2Cmd_PassSeatmassgHeat2Cmd
#define Rte_Read_PassSeatmassgHeat3Cmd_PassSeatmassgHeat3Cmd          Rte_Read_Com_PassSeatmassgHeat3Cmd_PassSeatmassgHeat3Cmd
#define Rte_Read_PassSeatmassgHeat4Cmd_PassSeatmassgHeat4Cmd          Rte_Read_Com_PassSeatmassgHeat4Cmd_PassSeatmassgHeat4Cmd
#define Rte_Read_PassSeatmassgHeat5Cmd_PassSeatmassgHeat5Cmd          Rte_Read_Com_PassSeatmassgHeat5Cmd_PassSeatmassgHeat5Cmd
#define Rte_Read_PassSeatmassgHeat6Cmd_PassSeatmassgHeat6Cmd          Rte_Read_Com_PassSeatmassgHeat6Cmd_PassSeatmassgHeat6Cmd
#define Rte_Read_PassSeatmassgHeat7Cmd_PassSeatmassgHeat7Cmd          Rte_Read_Com_PassSeatmassgHeat7Cmd_PassSeatmassgHeat7Cmd
#define Rte_Read_PassSeatmassgHeat8Cmd_PassSeatmassgHeat8Cmd          Rte_Read_Com_PassSeatmassgHeat8Cmd_PassSeatmassgHeat8Cmd
#define Rte_Read_PassSeatmassgHeat9Cmd_PassSeatmassgHeat9Cmd          Rte_Read_Com_PassSeatmassgHeat9Cmd_PassSeatmassgHeat9Cmd
#define Rte_Read_PassSeatmassgValve10Cmd_PassSeatmassgValve10Cmd      Rte_Read_Com_PassSeatmassgValve10Cmd_PassSeatmassgValve10Cmd
#define Rte_Read_PassSeatmassgValve11Cmd_PassSeatmassgValve11Cmd      Rte_Read_Com_PassSeatmassgValve11Cmd_PassSeatmassgValve11Cmd
#define Rte_Read_PassSeatmassgValve12Cmd_PassSeatmassgValve12Cmd      Rte_Read_Com_PassSeatmassgValve12Cmd_PassSeatmassgValve12Cmd
#define Rte_Read_PassSeatmassgValve1Cmd_PassSeatmassgValve1Cmd        Rte_Read_Com_PassSeatmassgValve1Cmd_PassSeatmassgValve1Cmd
#define Rte_Read_PassSeatmassgValve2Cmd_PassSeatmassgValve2Cmd        Rte_Read_Com_PassSeatmassgValve2Cmd_PassSeatmassgValve2Cmd
#define Rte_Read_PassSeatmassgValve3Cmd_PassSeatmassgValve3Cmd        Rte_Read_Com_PassSeatmassgValve3Cmd_PassSeatmassgValve3Cmd
#define Rte_Read_PassSeatmassgValve4Cmd_PassSeatmassgValve4Cmd        Rte_Read_Com_PassSeatmassgValve4Cmd_PassSeatmassgValve4Cmd
#define Rte_Read_PassSeatmassgValve5Cmd_PassSeatmassgValve5Cmd        Rte_Read_Com_PassSeatmassgValve5Cmd_PassSeatmassgValve5Cmd
#define Rte_Read_PassSeatmassgValve6Cmd_PassSeatmassgValve6Cmd        Rte_Read_Com_PassSeatmassgValve6Cmd_PassSeatmassgValve6Cmd
#define Rte_Read_PassSeatmassgValve7Cmd_PassSeatmassgValve7Cmd        Rte_Read_Com_PassSeatmassgValve7Cmd_PassSeatmassgValve7Cmd
#define Rte_Read_PassSeatmassgValve8Cmd_PassSeatmassgValve8Cmd        Rte_Read_Com_PassSeatmassgValve8Cmd_PassSeatmassgValve8Cmd
#define Rte_Read_PassSeatmassgValve9Cmd_PassSeatmassgValve9Cmd        Rte_Read_Com_PassSeatmassgValve9Cmd_PassSeatmassgValve9Cmd
#define Rte_Read_Sec_Sec                                    Rte_Read_Com_Sec_Sec
#define Rte_Read_VC_Data_5E0_CRC_VC_Data_5E0_CRC            Rte_Read_Com_VC_Data_5E0_CRC_VC_Data_5E0_CRC
#define Rte_Read_VC_Data_5E0_MsgCntr_VC_Data_5E0_MsgCntr    Rte_Read_Com_VC_Data_5E0_MsgCntr_VC_Data_5E0_MsgCntr
#define Rte_Read_VC_Data_5E0_Payload_VC_Data_5E0_Payload    Rte_Read_Com_VC_Data_5E0_Payload_VC_Data_5E0_Payload
#define Rte_Read_VehModeDef_VehModeDef                      Rte_Read_Com_VehModeDef_VehModeDef
#define Rte_Read_VehOdometer_VehOdometer                    Rte_Read_Com_VehOdometer_VehOdometer
#define Rte_Read_VehSpdSts_Rdnt1_VehSpdSts_Rdnt1            Rte_Read_Com_VehSpdSts_Rdnt1_VehSpdSts_Rdnt1
#define Rte_Read_VehSpd_Rdnt1_VehSpd_Rdnt1                  Rte_Read_Com_VehSpd_Rdnt1_VehSpd_Rdnt1
#define Rte_Read_VehStateDetailed_VehStateDetailed          Rte_Read_Com_VehStateDetailed_VehStateDetailed
#define Rte_Read_VehStateDetailed_SrvSts_VehStateDetailed_SrvSts      Rte_Read_Com_VehStateDetailed_SrvSts_VehStateDetailed_SrvSts
#define Rte_Read_Yr_Yr                                      Rte_Read_Com_Yr_Yr
#define Rte_Read_ZONE_13C_CRC_ZONE_13C_CRC                  Rte_Read_Com_ZONE_13C_CRC_ZONE_13C_CRC
#define Rte_Read_ZONE_13C_MsgCntr_ZONE_13C_MsgCntr          Rte_Read_Com_ZONE_13C_MsgCntr_ZONE_13C_MsgCntr
#define Rte_Write_DrvHeat1Sts_DrvHeat1Sts                   Rte_Write_Com_DrvHeat1Sts_DrvHeat1Sts
#define Rte_Write_DrvHeat2Sts_DrvHeat2Sts                   Rte_Write_Com_DrvHeat2Sts_DrvHeat2Sts
#define Rte_Write_DrvHeat3Sts_DrvHeat3Sts                   Rte_Write_Com_DrvHeat3Sts_DrvHeat3Sts
#define Rte_Write_DrvHeat4Sts_DrvHeat4Sts                   Rte_Write_Com_DrvHeat4Sts_DrvHeat4Sts
#define Rte_Write_DrvHeat5ErrSts_DrvHeat5ErrSts             Rte_Write_Com_DrvHeat5ErrSts_DrvHeat5ErrSts
#define Rte_Write_DrvHeat5Sts_DrvHeat5Sts                   Rte_Write_Com_DrvHeat5Sts_DrvHeat5Sts
#define Rte_Write_DrvHeat6Sts_DrvHeat6Sts                   Rte_Write_Com_DrvHeat6Sts_DrvHeat6Sts
#define Rte_Write_DrvKneadingMassgSkillsSts10_DrvKneadingMassgSkillsSts10       Rte_Write_Com_DrvKneadingMassgSkillsSts10_DrvKneadingMassgSkillsSts10
#define Rte_Write_DrvKneadingMassgSkillsSts5_DrvKneadingMassgSkillsSts5         Rte_Write_Com_DrvKneadingMassgSkillsSts5_DrvKneadingMassgSkillsSts5
#define Rte_Write_DrvKneadingMassgSkillsSts6_DrvKneadingMassgSkillsSts6         Rte_Write_Com_DrvKneadingMassgSkillsSts6_DrvKneadingMassgSkillsSts6
#define Rte_Write_DrvKneadingMassgSkillsSts7_DrvKneadingMassgSkillsSts7         Rte_Write_Com_DrvKneadingMassgSkillsSts7_DrvKneadingMassgSkillsSts7
#define Rte_Write_DrvKneadingMassgSkillsSts8_DrvKneadingMassgSkillsSts8         Rte_Write_Com_DrvKneadingMassgSkillsSts8_DrvKneadingMassgSkillsSts8
#define Rte_Write_DrvKneadingMassgSkillsSts9_DrvKneadingMassgSkillsSts9         Rte_Write_Com_DrvKneadingMassgSkillsSts9_DrvKneadingMassgSkillsSts9
#define Rte_Write_DrvKneadingMassgTime10_DrvKneadingMassgTime10       Rte_Write_Com_DrvKneadingMassgTime10_DrvKneadingMassgTime10
#define Rte_Write_DrvKneadingMassgTime5_DrvKneadingMassgTime5         Rte_Write_Com_DrvKneadingMassgTime5_DrvKneadingMassgTime5
#define Rte_Write_DrvKneadingMassgTime6_DrvKneadingMassgTime6         Rte_Write_Com_DrvKneadingMassgTime6_DrvKneadingMassgTime6
#define Rte_Write_DrvKneadingMassgTime7_DrvKneadingMassgTime7         Rte_Write_Com_DrvKneadingMassgTime7_DrvKneadingMassgTime7
#define Rte_Write_DrvKneadingMassgTime8_DrvKneadingMassgTime8         Rte_Write_Com_DrvKneadingMassgTime8_DrvKneadingMassgTime8
#define Rte_Write_DrvKneadingMassgTime9_DrvKneadingMassgTime9         Rte_Write_Com_DrvKneadingMassgTime9_DrvKneadingMassgTime9
#define Rte_Write_DrvKneadingMassglvlSts10_DrvKneadingMassglvlSts10   Rte_Write_Com_DrvKneadingMassglvlSts10_DrvKneadingMassglvlSts10
#define Rte_Write_DrvKneadingMassglvlSts5_DrvKneadingMassglvlSts5     Rte_Write_Com_DrvKneadingMassglvlSts5_DrvKneadingMassglvlSts5
#define Rte_Write_DrvKneadingMassglvlSts6_DrvKneadingMassglvlSts6     Rte_Write_Com_DrvKneadingMassglvlSts6_DrvKneadingMassglvlSts6
#define Rte_Write_DrvKneadingMassglvlSts7_DrvKneadingMassglvlSts7     Rte_Write_Com_DrvKneadingMassglvlSts7_DrvKneadingMassglvlSts7
#define Rte_Write_DrvKneadingMassglvlSts8_DrvKneadingMassglvlSts8     Rte_Write_Com_DrvKneadingMassglvlSts8_DrvKneadingMassglvlSts8
#define Rte_Write_DrvKneadingMassglvlSts9_DrvKneadingMassglvlSts9     Rte_Write_Com_DrvKneadingMassglvlSts9_DrvKneadingMassglvlSts9
#define Rte_Write_DrvLumControlSts_DrvLumControlSts         Rte_Write_Com_DrvLumControlSts_DrvLumControlSts
#define Rte_Write_DrvLumSwitchSts_DrvLumSwitchSts           Rte_Write_Com_DrvLumSwitchSts_DrvLumSwitchSts
#define Rte_Write_DrvLumbarBottomWorkSts_DrvLumbarBottomWorkSts       Rte_Write_Com_DrvLumbarBottomWorkSts_DrvLumbarBottomWorkSts
#define Rte_Write_DrvLumbarMidWorkSts_DrvLumbarMidWorkSts   Rte_Write_Com_DrvLumbarMidWorkSts_DrvLumbarMidWorkSts
#define Rte_Write_DrvLumbarTopWorkSts_DrvLumbarTopWorkSts   Rte_Write_Com_DrvLumbarTopWorkSts_DrvLumbarTopWorkSts
#define Rte_Write_DrvMassSwitchSts_DrvMassSwitchSts         Rte_Write_Com_DrvMassSwitchSts_DrvMassSwitchSts
#define Rte_Write_DrvMassageHeatNTC1_DrvMassageHeatNTC1     Rte_Write_Com_DrvMassageHeatNTC1_DrvMassageHeatNTC1
#define Rte_Write_DrvMassageHeatNTC10_DrvMassageHeatNTC10   Rte_Write_Com_DrvMassageHeatNTC10_DrvMassageHeatNTC10
#define Rte_Write_DrvMassageHeatNTC11_DrvMassageHeatNTC11   Rte_Write_Com_DrvMassageHeatNTC11_DrvMassageHeatNTC11
#define Rte_Write_DrvMassageHeatNTC12_DrvMassageHeatNTC12   Rte_Write_Com_DrvMassageHeatNTC12_DrvMassageHeatNTC12
#define Rte_Write_DrvMassageHeatNTC2_DrvMassageHeatNTC2     Rte_Write_Com_DrvMassageHeatNTC2_DrvMassageHeatNTC2
#define Rte_Write_DrvMassageHeatNTC3_DrvMassageHeatNTC3     Rte_Write_Com_DrvMassageHeatNTC3_DrvMassageHeatNTC3
#define Rte_Write_DrvMassageHeatNTC4_DrvMassageHeatNTC4     Rte_Write_Com_DrvMassageHeatNTC4_DrvMassageHeatNTC4
#define Rte_Write_DrvMassageHeatNTC5_DrvMassageHeatNTC5     Rte_Write_Com_DrvMassageHeatNTC5_DrvMassageHeatNTC5
#define Rte_Write_DrvMassageHeatNTC6_DrvMassageHeatNTC6     Rte_Write_Com_DrvMassageHeatNTC6_DrvMassageHeatNTC6
#define Rte_Write_DrvMassageHeatNTC7_DrvMassageHeatNTC7     Rte_Write_Com_DrvMassageHeatNTC7_DrvMassageHeatNTC7
#define Rte_Write_DrvMassageHeatNTC8_DrvMassageHeatNTC8     Rte_Write_Com_DrvMassageHeatNTC8_DrvMassageHeatNTC8
#define Rte_Write_DrvMassageHeatNTC9_DrvMassageHeatNTC9     Rte_Write_Com_DrvMassageHeatNTC9_DrvMassageHeatNTC9
#define Rte_Write_DrvPumpSts_DrvPumpSts                     Rte_Write_Com_DrvPumpSts_DrvPumpSts
#define Rte_Write_DrvSeatBlosterValueSts_DrvSeatBlosterValueSts       Rte_Write_Com_DrvSeatBlosterValueSts_DrvSeatBlosterValueSts
#define Rte_Write_DrvSeatBolsterValueBLPos_DrvSeatBolsterValueBLPos   Rte_Write_Com_DrvSeatBolsterValueBLPos_DrvSeatBolsterValueBLPos
#define Rte_Write_DrvSeatBolsterValueBRPos_DrvSeatBolsterValueBRPos   Rte_Write_Com_DrvSeatBolsterValueBRPos_DrvSeatBolsterValueBRPos
#define Rte_Write_DrvSeatCushionValue1Pos_DrvSeatCushionValue1Pos     Rte_Write_Com_DrvSeatCushionValue1Pos_DrvSeatCushionValue1Pos
#define Rte_Write_DrvSeatCushionValue2Pos_DrvSeatCushionValue2Pos     Rte_Write_Com_DrvSeatCushionValue2Pos_DrvSeatCushionValue2Pos
#define Rte_Write_DrvSeatCushionValue3Pos_DrvSeatCushionValue3Pos     Rte_Write_Com_DrvSeatCushionValue3Pos_DrvSeatCushionValue3Pos
#define Rte_Write_DrvSeatCushionValue4Pos_DrvSeatCushionValue4Pos     Rte_Write_Com_DrvSeatCushionValue4Pos_DrvSeatCushionValue4Pos
#define Rte_Write_DrvSeatCushionValue5Pos_DrvSeatCushionValue5Pos     Rte_Write_Com_DrvSeatCushionValue5Pos_DrvSeatCushionValue5Pos
#define Rte_Write_DrvSeatCushionValue6Pos_DrvSeatCushionValue6Pos     Rte_Write_Com_DrvSeatCushionValue6Pos_DrvSeatCushionValue6Pos
#define Rte_Write_DrvSeatCushionValueSts_DrvSeatCushionValueSts       Rte_Write_Com_DrvSeatCushionValueSts_DrvSeatCushionValueSts
#define Rte_Write_DrvSeatLumbarBottomPos_DrvSeatLumbarBottomPos       Rte_Write_Com_DrvSeatLumbarBottomPos_DrvSeatLumbarBottomPos
#define Rte_Write_DrvSeatLumbarMidPos_DrvSeatLumbarMidPos   Rte_Write_Com_DrvSeatLumbarMidPos_DrvSeatLumbarMidPos
#define Rte_Write_DrvSeatLumbarTopPos_DrvSeatLumbarTopPos   Rte_Write_Com_DrvSeatLumbarTopPos_DrvSeatLumbarTopPos
#define Rte_Write_DrvSeatLumbarValueSts_DrvSeatLumbarValueSts         Rte_Write_Com_DrvSeatLumbarValueSts_DrvSeatLumbarValueSts
#define Rte_Write_DrvSeatMassFailr_DrvSeatMassFailr         Rte_Write_Com_DrvSeatMassFailr_DrvSeatMassFailr
#define Rte_Write_DrvSeatUpperValueLPos_DrvSeatUpperValueLPos         Rte_Write_Com_DrvSeatUpperValueLPos_DrvSeatUpperValueLPos
#define Rte_Write_DrvSeatUpperValueMPos_DrvSeatUpperValueMPos         Rte_Write_Com_DrvSeatUpperValueMPos_DrvSeatUpperValueMPos
#define Rte_Write_DrvSeatUpperValueRPos_DrvSeatUpperValueRPos         Rte_Write_Com_DrvSeatUpperValueRPos_DrvSeatUpperValueRPos
#define Rte_Write_DrvSeatUpperValueSts_DrvSeatUpperValueSts Rte_Write_Com_DrvSeatUpperValueSts_DrvSeatUpperValueSts
#define Rte_Write_DrvSeatmassgHeatCSts_DrvSeatmassgHeatCSts Rte_Write_Com_DrvSeatmassgHeatCSts_DrvSeatmassgHeatCSts
#define Rte_Write_DrvSeatmassgValveSts_DrvSeatmassgValveSts Rte_Write_Com_DrvSeatmassgValveSts_DrvSeatmassgValveSts
#define Rte_Write_DrvSystemFailr_DrvSystemFailr             Rte_Write_Com_DrvSystemFailr_DrvSystemFailr
#define Rte_Write_PassHeat1Sts_PassHeat1Sts                 Rte_Write_Com_PassHeat1Sts_PassHeat1Sts
#define Rte_Write_PassHeat2Sts_PassHeat2Sts                 Rte_Write_Com_PassHeat2Sts_PassHeat2Sts
#define Rte_Write_PassHeat3Sts_PassHeat3Sts                 Rte_Write_Com_PassHeat3Sts_PassHeat3Sts
#define Rte_Write_PassHeat4Sts_PassHeat4Sts                 Rte_Write_Com_PassHeat4Sts_PassHeat4Sts
#define Rte_Write_PassHeat5ErrSts_PassHeat5ErrSts           Rte_Write_Com_PassHeat5ErrSts_PassHeat5ErrSts
#define Rte_Write_PassHeat5Sts_PassHeat5Sts                 Rte_Write_Com_PassHeat5Sts_PassHeat5Sts
#define Rte_Write_PassHeat6Sts_PassHeat6Sts                 Rte_Write_Com_PassHeat6Sts_PassHeat6Sts
#define Rte_Write_PassKneadingMassgLvlSts10_PassKneadingMassgLvlSts10 Rte_Write_Com_PassKneadingMassgLvlSts10_PassKneadingMassgLvlSts10
#define Rte_Write_PassKneadingMassgLvlSts5_PassKneadingMassgLvlSts5   Rte_Write_Com_PassKneadingMassgLvlSts5_PassKneadingMassgLvlSts5
#define Rte_Write_PassKneadingMassgLvlSts6_PassKneadingMassgLvlSts6   Rte_Write_Com_PassKneadingMassgLvlSts6_PassKneadingMassgLvlSts6
#define Rte_Write_PassKneadingMassgLvlSts7_PassKneadingMassgLvlSts7   Rte_Write_Com_PassKneadingMassgLvlSts7_PassKneadingMassgLvlSts7
#define Rte_Write_PassKneadingMassgLvlSts8_PassKneadingMassgLvlSts8   Rte_Write_Com_PassKneadingMassgLvlSts8_PassKneadingMassgLvlSts8
#define Rte_Write_PassKneadingMassgLvlSts9_PassKneadingMassgLvlSts9   Rte_Write_Com_PassKneadingMassgLvlSts9_PassKneadingMassgLvlSts9
#define Rte_Write_PassKneadingMassgSkillsSts10_PassKneadingMassgSkillsSts10     Rte_Write_Com_PassKneadingMassgSkillsSts10_PassKneadingMassgSkillsSts10
#define Rte_Write_PassKneadingMassgSkillsSts5_PassKneadingMassgSkillsSts5       Rte_Write_Com_PassKneadingMassgSkillsSts5_PassKneadingMassgSkillsSts5
#define Rte_Write_PassKneadingMassgSkillsSts6_PassKneadingMassgSkillsSts6       Rte_Write_Com_PassKneadingMassgSkillsSts6_PassKneadingMassgSkillsSts6
#define Rte_Write_PassKneadingMassgSkillsSts7_PassKneadingMassgSkillsSts7       Rte_Write_Com_PassKneadingMassgSkillsSts7_PassKneadingMassgSkillsSts7
#define Rte_Write_PassKneadingMassgSkillsSts8_PassKneadingMassgSkillsSts8       Rte_Write_Com_PassKneadingMassgSkillsSts8_PassKneadingMassgSkillsSts8
#define Rte_Write_PassKneadingMassgSkillsSts9_PassKneadingMassgSkillsSts9       Rte_Write_Com_PassKneadingMassgSkillsSts9_PassKneadingMassgSkillsSts9
#define Rte_Write_PassKneadingMassgTime10_PassKneadingMassgTime10     Rte_Write_Com_PassKneadingMassgTime10_PassKneadingMassgTime10
#define Rte_Write_PassKneadingMassgTime5_PassKneadingMassgTime5       Rte_Write_Com_PassKneadingMassgTime5_PassKneadingMassgTime5
#define Rte_Write_PassKneadingMassgTime6_PassKneadingMassgTime6       Rte_Write_Com_PassKneadingMassgTime6_PassKneadingMassgTime6
#define Rte_Write_PassKneadingMassgTime7_PassKneadingMassgTime7       Rte_Write_Com_PassKneadingMassgTime7_PassKneadingMassgTime7
#define Rte_Write_PassKneadingMassgTime8_PassKneadingMassgTime8       Rte_Write_Com_PassKneadingMassgTime8_PassKneadingMassgTime8
#define Rte_Write_PassKneadingMassgTime9_PassKneadingMassgTime9       Rte_Write_Com_PassKneadingMassgTime9_PassKneadingMassgTime9
#define Rte_Write_PassLumControlSts_PassLumControlSts       Rte_Write_Com_PassLumControlSts_PassLumControlSts
#define Rte_Write_PassLumSwitchSts_PassLumSwitchSts         Rte_Write_Com_PassLumSwitchSts_PassLumSwitchSts
#define Rte_Write_PassLumbarBottomWorkSts_PassLumbarBottomWorkSts     Rte_Write_Com_PassLumbarBottomWorkSts_PassLumbarBottomWorkSts
#define Rte_Write_PassLumbarMidWorkSts_PassLumbarMidWorkSts Rte_Write_Com_PassLumbarMidWorkSts_PassLumbarMidWorkSts
#define Rte_Write_PassLumbarTopWorkSts_PassLumbarTopWorkSts Rte_Write_Com_PassLumbarTopWorkSts_PassLumbarTopWorkSts
#define Rte_Write_PassMassSwitchSts_PassMassSwitchSts       Rte_Write_Com_PassMassSwitchSts_PassMassSwitchSts
#define Rte_Write_PassMassageHeatNTC1_PassMassageHeatNTC1   Rte_Write_Com_PassMassageHeatNTC1_PassMassageHeatNTC1
#define Rte_Write_PassMassageHeatNTC10_PassMassageHeatNTC10 Rte_Write_Com_PassMassageHeatNTC10_PassMassageHeatNTC10
#define Rte_Write_PassMassageHeatNTC11_PassMassageHeatNTC11 Rte_Write_Com_PassMassageHeatNTC11_PassMassageHeatNTC11
#define Rte_Write_PassMassageHeatNTC12_PassMassageHeatNTC12 Rte_Write_Com_PassMassageHeatNTC12_PassMassageHeatNTC12
#define Rte_Write_PassMassageHeatNTC2_PassMassageHeatNTC2   Rte_Write_Com_PassMassageHeatNTC2_PassMassageHeatNTC2
#define Rte_Write_PassMassageHeatNTC3_PassMassageHeatNTC3   Rte_Write_Com_PassMassageHeatNTC3_PassMassageHeatNTC3
#define Rte_Write_PassMassageHeatNTC4_PassMassageHeatNTC4   Rte_Write_Com_PassMassageHeatNTC4_PassMassageHeatNTC4
#define Rte_Write_PassMassageHeatNTC5_PassMassageHeatNTC5   Rte_Write_Com_PassMassageHeatNTC5_PassMassageHeatNTC5
#define Rte_Write_PassMassageHeatNTC6_PassMassageHeatNTC6   Rte_Write_Com_PassMassageHeatNTC6_PassMassageHeatNTC6
#define Rte_Write_PassMassageHeatNTC7_PassMassageHeatNTC7   Rte_Write_Com_PassMassageHeatNTC7_PassMassageHeatNTC7
#define Rte_Write_PassMassageHeatNTC8_PassMassageHeatNTC8   Rte_Write_Com_PassMassageHeatNTC8_PassMassageHeatNTC8
#define Rte_Write_PassMassageHeatNTC9_PassMassageHeatNTC9   Rte_Write_Com_PassMassageHeatNTC9_PassMassageHeatNTC9
#define Rte_Write_PassPumpSts_PassPumpSts                   Rte_Write_Com_PassPumpSts_PassPumpSts
#define Rte_Write_PassSeatBlosterValueSts_PassSeatBlosterValueSts     Rte_Write_Com_PassSeatBlosterValueSts_PassSeatBlosterValueSts
#define Rte_Write_PassSeatBolsterValueBLPos_PassSeatBolsterValueBLPos Rte_Write_Com_PassSeatBolsterValueBLPos_PassSeatBolsterValueBLPos
#define Rte_Write_PassSeatBolsterValueBRPos_PassSeatBolsterValueBRPos Rte_Write_Com_PassSeatBolsterValueBRPos_PassSeatBolsterValueBRPos
#define Rte_Write_PassSeatCushionValue1Pos_PassSeatCushionValue1Pos   Rte_Write_Com_PassSeatCushionValue1Pos_PassSeatCushionValue1Pos
#define Rte_Write_PassSeatCushionValue2Pos_PassSeatCushionValue2Pos   Rte_Write_Com_PassSeatCushionValue2Pos_PassSeatCushionValue2Pos
#define Rte_Write_PassSeatCushionValue3Pos_PassSeatCushionValue3Pos   Rte_Write_Com_PassSeatCushionValue3Pos_PassSeatCushionValue3Pos
#define Rte_Write_PassSeatCushionValue4Pos_PassSeatCushionValue4Pos   Rte_Write_Com_PassSeatCushionValue4Pos_PassSeatCushionValue4Pos
#define Rte_Write_PassSeatCushionValue5Pos_PassSeatCushionValue5Pos   Rte_Write_Com_PassSeatCushionValue5Pos_PassSeatCushionValue5Pos
#define Rte_Write_PassSeatCushionValue6Pos_PassSeatCushionValue6Pos   Rte_Write_Com_PassSeatCushionValue6Pos_PassSeatCushionValue6Pos
#define Rte_Write_PassSeatCushionValueSts_PassSeatCushionValueSts     Rte_Write_Com_PassSeatCushionValueSts_PassSeatCushionValueSts
#define Rte_Write_PassSeatLumbarBottomPos_PassSeatLumbarBottomPos     Rte_Write_Com_PassSeatLumbarBottomPos_PassSeatLumbarBottomPos
#define Rte_Write_PassSeatLumbarMidPos_PassSeatLumbarMidPos Rte_Write_Com_PassSeatLumbarMidPos_PassSeatLumbarMidPos
#define Rte_Write_PassSeatLumbarTopPos_PassSeatLumbarTopPos Rte_Write_Com_PassSeatLumbarTopPos_PassSeatLumbarTopPos
#define Rte_Write_PassSeatLumbarValueSts_PassSeatLumbarValueSts       Rte_Write_Com_PassSeatLumbarValueSts_PassSeatLumbarValueSts
#define Rte_Write_PassSeatMassFailr_PassSeatMassFailr       Rte_Write_Com_PassSeatMassFailr_PassSeatMassFailr
#define Rte_Write_PassSeatUpperValueLPos_PassSeatUpperValueLPos       Rte_Write_Com_PassSeatUpperValueLPos_PassSeatUpperValueLPos
#define Rte_Write_PassSeatUpperValueMPos_PassSeatUpperValueMPos       Rte_Write_Com_PassSeatUpperValueMPos_PassSeatUpperValueMPos
#define Rte_Write_PassSeatUpperValueRPos_PassSeatUpperValueRPos       Rte_Write_Com_PassSeatUpperValueRPos_PassSeatUpperValueRPos
#define Rte_Write_PassSeatUpperValueSts_PassSeatUpperValueSts         Rte_Write_Com_PassSeatUpperValueSts_PassSeatUpperValueSts
#define Rte_Write_PassSeatmassgHeatCSts_PassSeatmassgHeatCSts         Rte_Write_Com_PassSeatmassgHeatCSts_PassSeatmassgHeatCSts
#define Rte_Write_PassSeatmassgValveSts_PassSeatmassgValveSts         Rte_Write_Com_PassSeatmassgValveSts_PassSeatmassgValveSts
#define Rte_Write_PassSystemFailr_PassSystemFailr           Rte_Write_Com_PassSystemFailr_PassSystemFailr

/*******************************************************************************
*   Com Cbk
*******************************************************************************/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd5
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd5
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd5
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd6
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd7
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd8
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd6
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd6
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd7
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd7
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd8
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd8
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd9
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd9
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd9
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd10
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd10
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd10
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat1_pct
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat2_pct
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat3_pct
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat4_pct
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat5_pct
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat6_pct
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve1Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve1Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve2Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve2Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve3Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve3Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve4Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve4Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve5Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve5Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve6Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve6Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve7Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve7Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve8Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve8Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve9Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve9Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve10Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve10Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve11Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve11Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve12Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve12Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat1Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat1Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat2Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat2Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat3Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat3Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat4Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat4Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat5Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat5Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat6Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat6Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat7Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat7Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat8Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat8Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat9Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat9Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat10Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat10Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat11Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat11Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat12Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat12Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarTopValue1Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarTopValue1Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarMidValue2Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarMidValue2Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarBottomValue3Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarBottomValue3Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBLCmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBLCmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBRCmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBRCmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue6Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue6Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue5Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue5Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue4Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue4Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvPumpCmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvPumpCmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueLCmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueLCmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueMCmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueMCmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue2Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue2Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueRCmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueRCmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue3Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue3Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue1Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue1Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Yr
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Yr
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Mth
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Mth
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Day
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Day
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Hr
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Hr
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Min
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Min
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Sec
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Sec
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_MSec
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_MSec
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts5
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts6
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts5
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts6
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts7
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts8
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts7
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts8
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime8
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime5
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime6
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime7
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvMassSwitchSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgHeatCSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarValueSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgValveSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatUpperValueSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValueSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBlosterValueSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarTopPos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarMidPos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarBottomPos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBLPos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBRPos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValue6Pos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue5Pos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue4Pos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue2Pos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue1Pos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueLPos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueMPos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueRPos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvPumpSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgSkillsSts9
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumControlSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumSwitchSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSystemFailr
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatMassFailr
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatCushionValue3Pos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarTopWorkSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarMidWorkSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarBottomWorkSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat1Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat2Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat3Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat4Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat6Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5ErrSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassglvlSts9
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgTime9
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgTime10
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgSkillsSts10
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassglvlSts10
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC1
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC2
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC3
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC4
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC5
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC6
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC7
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC8
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC9
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC10
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC11
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC12
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd5
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd5
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd5
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd6
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd7
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd8
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd6
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd6
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd7
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd7
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd8
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd8
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd9
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd9
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd10
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd10
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd9
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd10
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat1_pct
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat2_pct
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat3_pct
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat4_pct
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat5_pct
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat6_pct
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve1Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve1Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve2Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve2Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve3Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve3Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve4Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve4Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve5Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve5Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve6Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve6Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve7Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve7Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve8Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve8Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve9Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve9Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve10Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve10Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve11Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve11Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve12Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve12Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat1Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat1Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat2Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat2Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat3Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat3Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat4Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat4Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat5Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat5Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat6Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat6Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat7Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat7Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat8Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat8Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat9Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat9Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat10Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat10Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat11Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat11Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat12Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat12Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarTopValue1Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarTopValue1Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarMidValue2Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarMidValue2Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarBottomValue3Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarBottomValue3Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBLCmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBLCmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBRCmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBRCmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue6Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue6Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue5Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue5Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue4Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue4Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassPumpCmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassPumpCmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueLCmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueLCmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueMCmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueMCmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueRCmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueRCmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue2Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue2Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue3Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue3Cmd
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue1Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue1Cmd
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Yr
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Yr
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Mth
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Mth
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Day
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Day
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Hr
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Hr
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Min
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Min
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Sec
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Sec
(
    void
);
extern FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_MSec
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_MSec
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts5
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts5
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts6
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime5
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts6
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts7
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime6
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime7
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts8
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts7
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts8
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime8
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgValveSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgHeatCSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarValueSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatUpperValueSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValueSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBlosterValueSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassMassSwitchSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarTopPos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarMidPos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarBottomPos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBLPos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBRPos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValue6Pos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue5Pos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue4Pos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue2Pos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue1Pos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueLPos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueMPos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueRPos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassPumpSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgSkillsSts9
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumControlSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumSwitchSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSystemFailr
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatMassFailr
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatCushionValue3Pos
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarTopWorkSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarMidWorkSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarBottomWorkSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat1Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat2Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat3Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat4Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat6Sts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5ErrSts
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgLvlSts9
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgTime9
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgTime10
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgSkillsSts10
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgLvlSts10
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC1
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC2
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC3
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC4
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC5
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC6
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC7
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC8
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC9
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC10
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC11
(
    void
);

extern FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC12
(
    void
);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"


/*******************************************************************************
*   Extended
*******************************************************************************/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_BattVolt_LBMR_BattVolt_LBMR
(
    P2VAR(BattVolt_LBMR_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_Day_Day
(
    P2VAR(Day_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvHeat1_pct_DrvHeat1_pct
(
    P2VAR(DrvHeat1_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvHeat2_pct_DrvHeat2_pct
(
    P2VAR(DrvHeat2_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvHeat3_pct_DrvHeat3_pct
(
    P2VAR(DrvHeat3_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvHeat4_pct_DrvHeat4_pct
(
    P2VAR(DrvHeat4_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvHeat5_pct_DrvHeat5_pct
(
    P2VAR(DrvHeat5_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvHeat6_pct_DrvHeat6_pct
(
    P2VAR(DrvHeat6_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgLvlCmd10_DrvKneadingMassgLvlCmd10
(
    P2VAR(DrvKneadingMassgLvlCmd10_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgLvlCmd5_DrvKneadingMassgLvlCmd5
(
    P2VAR(DrvKneadingMassgLvlCmd5_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgLvlCmd6_DrvKneadingMassgLvlCmd6
(
    P2VAR(DrvKneadingMassgLvlCmd6_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgLvlCmd7_DrvKneadingMassgLvlCmd7
(
    P2VAR(DrvKneadingMassgLvlCmd7_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgLvlCmd8_DrvKneadingMassgLvlCmd8
(
    P2VAR(DrvKneadingMassgLvlCmd8_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgLvlCmd9_DrvKneadingMassgLvlCmd9
(
    P2VAR(DrvKneadingMassgLvlCmd9_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgSkillsCmd10_DrvKneadingMassgSkillsCmd10
(
    P2VAR(DrvKneadingMassgSkillsCmd10_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgSkillsCmd5_DrvKneadingMassgSkillsCmd5
(
    P2VAR(DrvKneadingMassgSkillsCmd5_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgSkillsCmd6_DrvKneadingMassgSkillsCmd6
(
    P2VAR(DrvKneadingMassgSkillsCmd6_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgSkillsCmd7_DrvKneadingMassgSkillsCmd7
(
    P2VAR(DrvKneadingMassgSkillsCmd7_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgSkillsCmd8_DrvKneadingMassgSkillsCmd8
(
    P2VAR(DrvKneadingMassgSkillsCmd8_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgSkillsCmd9_DrvKneadingMassgSkillsCmd9
(
    P2VAR(DrvKneadingMassgSkillsCmd9_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgTimesCmd10_DrvKneadingMassgTimesCmd10
(
    P2VAR(DrvKneadingMassgTimesCmd10_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgTimesCmd5_DrvKneadingMassgTimesCmd5
(
    P2VAR(DrvKneadingMassgTimesCmd5_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgTimesCmd6_DrvKneadingMassgTimesCmd6
(
    P2VAR(DrvKneadingMassgTimesCmd6_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgTimesCmd7_DrvKneadingMassgTimesCmd7
(
    P2VAR(DrvKneadingMassgTimesCmd7_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgTimesCmd8_DrvKneadingMassgTimesCmd8
(
    P2VAR(DrvKneadingMassgTimesCmd8_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvKneadingMassgTimesCmd9_DrvKneadingMassgTimesCmd9
(
    P2VAR(DrvKneadingMassgTimesCmd9_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvPumpCmd_DrvPumpCmd
(
    P2VAR(DrvPumpCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatBolsterValueBLCmd_DrvSeatBolsterValueBLCmd
(
    P2VAR(DrvSeatBolsterValueBLCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatBolsterValueBRCmd_DrvSeatBolsterValueBRCmd
(
    P2VAR(DrvSeatBolsterValueBRCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatCushionValue1Cmd_DrvSeatCushionValue1Cmd
(
    P2VAR(DrvSeatCushionValue1Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatCushionValue2Cmd_DrvSeatCushionValue2Cmd
(
    P2VAR(DrvSeatCushionValue2Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatCushionValue3Cmd_DrvSeatCushionValue3Cmd
(
    P2VAR(DrvSeatCushionValue3Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatCushionValue4Cmd_DrvSeatCushionValue4Cmd
(
    P2VAR(DrvSeatCushionValue4Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatCushionValue5Cmd_DrvSeatCushionValue5Cmd
(
    P2VAR(DrvSeatCushionValue5Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatCushionValue6Cmd_DrvSeatCushionValue6Cmd
(
    P2VAR(DrvSeatCushionValue6Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatLumbarBottomValue3Cmd_DrvSeatLumbarBottomValue3Cmd
(
    P2VAR(DrvSeatLumbarBottomValue3Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatLumbarMidValue2Cmd_DrvSeatLumbarMidValue2Cmd
(
    P2VAR(DrvSeatLumbarMidValue2Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatLumbarTopValue1Cmd_DrvSeatLumbarTopValue1Cmd
(
    P2VAR(DrvSeatLumbarTopValue1Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatUpperValueLCmd_DrvSeatUpperValueLCmd
(
    P2VAR(DrvSeatUpperValueLCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatUpperValueMCmd_DrvSeatUpperValueMCmd
(
    P2VAR(DrvSeatUpperValueMCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatUpperValueRCmd_DrvSeatUpperValueRCmd
(
    P2VAR(DrvSeatUpperValueRCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat10Cmd_DrvSeatmassgHeat10Cmd
(
    P2VAR(DrvSeatmassgHeat10Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat11Cmd_DrvSeatmassgHeat11Cmd
(
    P2VAR(DrvSeatmassgHeat11Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat12Cmd_DrvSeatmassgHeat12Cmd
(
    P2VAR(DrvSeatmassgHeat12Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat1Cmd_DrvSeatmassgHeat1Cmd
(
    P2VAR(DrvSeatmassgHeat1Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat2Cmd_DrvSeatmassgHeat2Cmd
(
    P2VAR(DrvSeatmassgHeat2Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat3Cmd_DrvSeatmassgHeat3Cmd
(
    P2VAR(DrvSeatmassgHeat3Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat4Cmd_DrvSeatmassgHeat4Cmd
(
    P2VAR(DrvSeatmassgHeat4Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat5Cmd_DrvSeatmassgHeat5Cmd
(
    P2VAR(DrvSeatmassgHeat5Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat6Cmd_DrvSeatmassgHeat6Cmd
(
    P2VAR(DrvSeatmassgHeat6Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat7Cmd_DrvSeatmassgHeat7Cmd
(
    P2VAR(DrvSeatmassgHeat7Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat8Cmd_DrvSeatmassgHeat8Cmd
(
    P2VAR(DrvSeatmassgHeat8Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgHeat9Cmd_DrvSeatmassgHeat9Cmd
(
    P2VAR(DrvSeatmassgHeat9Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve10Cmd_DrvSeatmassgValve10Cmd
(
    P2VAR(DrvSeatmassgValve10Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve11Cmd_DrvSeatmassgValve11Cmd
(
    P2VAR(DrvSeatmassgValve11Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve12Cmd_DrvSeatmassgValve12Cmd
(
    P2VAR(DrvSeatmassgValve12Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve1Cmd_DrvSeatmassgValve1Cmd
(
    P2VAR(DrvSeatmassgValve1Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve2Cmd_DrvSeatmassgValve2Cmd
(
    P2VAR(DrvSeatmassgValve2Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve3Cmd_DrvSeatmassgValve3Cmd
(
    P2VAR(DrvSeatmassgValve3Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve4Cmd_DrvSeatmassgValve4Cmd
(
    P2VAR(DrvSeatmassgValve4Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve5Cmd_DrvSeatmassgValve5Cmd
(
    P2VAR(DrvSeatmassgValve5Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve6Cmd_DrvSeatmassgValve6Cmd
(
    P2VAR(DrvSeatmassgValve6Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve7Cmd_DrvSeatmassgValve7Cmd
(
    P2VAR(DrvSeatmassgValve7Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve8Cmd_DrvSeatmassgValve8Cmd
(
    P2VAR(DrvSeatmassgValve8Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvSeatmassgValve9Cmd_DrvSeatmassgValve9Cmd
(
    P2VAR(DrvSeatmassgValve9Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvState_DrvState
(
    P2VAR(DrvState_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_DrvState_SrvSts_DrvState_SrvSts
(
    P2VAR(DrvState_SrvSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_Hr_Hr
(
    P2VAR(Hr_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_MSec_MSec
(
    P2VAR(MSec_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_Min_Min
(
    P2VAR(Min_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_Mth_Mth
(
    P2VAR(Mth_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_OperatorState_OperatorState
(
    P2VAR(OperatorState_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_OperatorState_SrvSts_OperatorState_SrvSts
(
    P2VAR(OperatorState_SrvSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC10_Sts_PNC10_Sts
(
    P2VAR(PNC10_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC11_Sts_PNC11_Sts
(
    P2VAR(PNC11_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC12_Sts_PNC12_Sts
(
    P2VAR(PNC12_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC13_Sts_PNC13_Sts
(
    P2VAR(PNC13_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC14_Sts_PNC14_Sts
(
    P2VAR(PNC14_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC15_Sts_PNC15_Sts
(
    P2VAR(PNC15_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC16_Sts_PNC16_Sts
(
    P2VAR(PNC16_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC17_Sts_PNC17_Sts
(
    P2VAR(PNC17_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC18_Sts_PNC18_Sts
(
    P2VAR(PNC18_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC19_Sts_PNC19_Sts
(
    P2VAR(PNC19_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC1_Sts_PNC1_Sts
(
    P2VAR(PNC1_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC20_Sts_PNC20_Sts
(
    P2VAR(PNC20_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC21_Sts_PNC21_Sts
(
    P2VAR(PNC21_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC22_Sts_PNC22_Sts
(
    P2VAR(PNC22_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC23_Sts_PNC23_Sts
(
    P2VAR(PNC23_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC24_Sts_PNC24_Sts
(
    P2VAR(PNC24_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC25_Sts_PNC25_Sts
(
    P2VAR(PNC25_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC26_Sts_PNC26_Sts
(
    P2VAR(PNC26_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC27_Sts_PNC27_Sts
(
    P2VAR(PNC27_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC28_Sts_PNC28_Sts
(
    P2VAR(PNC28_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC29_Sts_PNC29_Sts
(
    P2VAR(PNC29_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC2_Sts_PNC2_Sts
(
    P2VAR(PNC2_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC30_Sts_PNC30_Sts
(
    P2VAR(PNC30_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC31_Sts_PNC31_Sts
(
    P2VAR(PNC31_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC32_Sts_PNC32_Sts
(
    P2VAR(PNC32_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC33_Sts_PNC33_Sts
(
    P2VAR(PNC33_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC34_Sts_PNC34_Sts
(
    P2VAR(PNC34_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC35_Sts_PNC35_Sts
(
    P2VAR(PNC35_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC36_Sts_PNC36_Sts
(
    P2VAR(PNC36_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC37_Sts_PNC37_Sts
(
    P2VAR(PNC37_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC38_Sts_PNC38_Sts
(
    P2VAR(PNC38_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC39_Sts_PNC39_Sts
(
    P2VAR(PNC39_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC3_Sts_PNC3_Sts
(
    P2VAR(PNC3_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC40_Sts_PNC40_Sts
(
    P2VAR(PNC40_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC41_Sts_PNC41_Sts
(
    P2VAR(PNC41_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC42_Sts_PNC42_Sts
(
    P2VAR(PNC42_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC43_Sts_PNC43_Sts
(
    P2VAR(PNC43_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC44_Sts_PNC44_Sts
(
    P2VAR(PNC44_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC45_Sts_PNC45_Sts
(
    P2VAR(PNC45_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC46_Sts_PNC46_Sts
(
    P2VAR(PNC46_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC47_Sts_PNC47_Sts
(
    P2VAR(PNC47_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC48_Sts_PNC48_Sts
(
    P2VAR(PNC48_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC4_Sts_PNC4_Sts
(
    P2VAR(PNC4_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC5_Sts_PNC5_Sts
(
    P2VAR(PNC5_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC6_Sts_PNC6_Sts
(
    P2VAR(PNC6_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC7_Sts_PNC7_Sts
(
    P2VAR(PNC7_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC8_Sts_PNC8_Sts
(
    P2VAR(PNC8_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC9_Sts_PNC9_Sts
(
    P2VAR(PNC9_Sts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PNC_DFT_PNC_DFT
(
    P2VAR(PNC_DFT_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassHeat1_pct_PassHeat1_pct
(
    P2VAR(PassHeat1_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassHeat2_pct_PassHeat2_pct
(
    P2VAR(PassHeat2_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassHeat3_pct_PassHeat3_pct
(
    P2VAR(PassHeat3_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassHeat4_pct_PassHeat4_pct
(
    P2VAR(PassHeat4_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassHeat5_pct_PassHeat5_pct
(
    P2VAR(PassHeat5_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassHeat6_pct_PassHeat6_pct
(
    P2VAR(PassHeat6_pct_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgLvlCmd10_PassKneadingMassgLvlCmd10
(
    P2VAR(PassKneadingMassgLvlCmd10_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgLvlCmd5_PassKneadingMassgLvlCmd5
(
    P2VAR(PassKneadingMassgLvlCmd5_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgLvlCmd6_PassKneadingMassgLvlCmd6
(
    P2VAR(PassKneadingMassgLvlCmd6_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgLvlCmd7_PassKneadingMassgLvlCmd7
(
    P2VAR(PassKneadingMassgLvlCmd7_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgLvlCmd8_PassKneadingMassgLvlCmd8
(
    P2VAR(PassKneadingMassgLvlCmd8_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgLvlCmd9_PassKneadingMassgLvlCmd9
(
    P2VAR(PassKneadingMassgLvlCmd9_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgSkillsCmd10_PassKneadingMassgSkillsCmd10
(
    P2VAR(PassKneadingMassgSkillsCmd10_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgSkillsCmd5_PassKneadingMassgSkillsCmd5
(
    P2VAR(PassKneadingMassgSkillsCmd5_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgSkillsCmd6_PassKneadingMassgSkillsCmd6
(
    P2VAR(PassKneadingMassgSkillsCmd6_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgSkillsCmd7_PassKneadingMassgSkillsCmd7
(
    P2VAR(PassKneadingMassgSkillsCmd7_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgSkillsCmd8_PassKneadingMassgSkillsCmd8
(
    P2VAR(PassKneadingMassgSkillsCmd8_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgSkillsCmd9_PassKneadingMassgSkillsCmd9
(
    P2VAR(PassKneadingMassgSkillsCmd9_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgTimesCmd10_PassKneadingMassgTimesCmd10
(
    P2VAR(PassKneadingMassgTimesCmd10_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgTimesCmd5_PassKneadingMassgTimesCmd5
(
    P2VAR(PassKneadingMassgTimesCmd5_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgTimesCmd6_PassKneadingMassgTimesCmd6
(
    P2VAR(PassKneadingMassgTimesCmd6_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgTimesCmd7_PassKneadingMassgTimesCmd7
(
    P2VAR(PassKneadingMassgTimesCmd7_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgTimesCmd8_PassKneadingMassgTimesCmd8
(
    P2VAR(PassKneadingMassgTimesCmd8_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassKneadingMassgTimesCmd9_PassKneadingMassgTimesCmd9
(
    P2VAR(PassKneadingMassgTimesCmd9_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassPumpCmd_PassPumpCmd
(
    P2VAR(PassPumpCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatBolsterValueBLCmd_PassSeatBolsterValueBLCmd
(
    P2VAR(PassSeatBolsterValueBLCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatBolsterValueBRCmd_PassSeatBolsterValueBRCmd
(
    P2VAR(PassSeatBolsterValueBRCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatCushionValue1Cmd_PassSeatCushionValue1Cmd
(
    P2VAR(PassSeatCushionValue1Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatCushionValue2Cmd_PassSeatCushionValue2Cmd
(
    P2VAR(PassSeatCushionValue2Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatCushionValue3Cmd_PassSeatCushionValue3Cmd
(
    P2VAR(PassSeatCushionValue3Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatCushionValue4Cmd_PassSeatCushionValue4Cmd
(
    P2VAR(PassSeatCushionValue4Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatCushionValue5Cmd_PassSeatCushionValue5Cmd
(
    P2VAR(PassSeatCushionValue5Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatCushionValue6Cmd_PassSeatCushionValue6Cmd
(
    P2VAR(PassSeatCushionValue6Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatLumbarBottomValue3Cmd_PassSeatLumbarBottomValue3Cmd
(
    P2VAR(PassSeatLumbarBottomValue3Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatLumbarMidValue2Cmd_PassSeatLumbarMidValue2Cmd
(
    P2VAR(PassSeatLumbarMidValue2Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatLumbarTopValue1Cmd_PassSeatLumbarTopValue1Cmd
(
    P2VAR(PassSeatLumbarTopValue1Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatUpperValueLCmd_PassSeatUpperValueLCmd
(
    P2VAR(PassSeatUpperValueLCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatUpperValueMCmd_PassSeatUpperValueMCmd
(
    P2VAR(PassSeatUpperValueMCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatUpperValueRCmd_PassSeatUpperValueRCmd
(
    P2VAR(PassSeatUpperValueRCmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat10Cmd_PassSeatmassgHeat10Cmd
(
    P2VAR(PassSeatmassgHeat10Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat11Cmd_PassSeatmassgHeat11Cmd
(
    P2VAR(PassSeatmassgHeat11Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat12Cmd_PassSeatmassgHeat12Cmd
(
    P2VAR(PassSeatmassgHeat12Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat1Cmd_PassSeatmassgHeat1Cmd
(
    P2VAR(PassSeatmassgHeat1Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat2Cmd_PassSeatmassgHeat2Cmd
(
    P2VAR(PassSeatmassgHeat2Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat3Cmd_PassSeatmassgHeat3Cmd
(
    P2VAR(PassSeatmassgHeat3Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat4Cmd_PassSeatmassgHeat4Cmd
(
    P2VAR(PassSeatmassgHeat4Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat5Cmd_PassSeatmassgHeat5Cmd
(
    P2VAR(PassSeatmassgHeat5Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat6Cmd_PassSeatmassgHeat6Cmd
(
    P2VAR(PassSeatmassgHeat6Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat7Cmd_PassSeatmassgHeat7Cmd
(
    P2VAR(PassSeatmassgHeat7Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat8Cmd_PassSeatmassgHeat8Cmd
(
    P2VAR(PassSeatmassgHeat8Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgHeat9Cmd_PassSeatmassgHeat9Cmd
(
    P2VAR(PassSeatmassgHeat9Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve10Cmd_PassSeatmassgValve10Cmd
(
    P2VAR(PassSeatmassgValve10Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve11Cmd_PassSeatmassgValve11Cmd
(
    P2VAR(PassSeatmassgValve11Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve12Cmd_PassSeatmassgValve12Cmd
(
    P2VAR(PassSeatmassgValve12Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve1Cmd_PassSeatmassgValve1Cmd
(
    P2VAR(PassSeatmassgValve1Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve2Cmd_PassSeatmassgValve2Cmd
(
    P2VAR(PassSeatmassgValve2Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve3Cmd_PassSeatmassgValve3Cmd
(
    P2VAR(PassSeatmassgValve3Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve4Cmd_PassSeatmassgValve4Cmd
(
    P2VAR(PassSeatmassgValve4Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve5Cmd_PassSeatmassgValve5Cmd
(
    P2VAR(PassSeatmassgValve5Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve6Cmd_PassSeatmassgValve6Cmd
(
    P2VAR(PassSeatmassgValve6Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve7Cmd_PassSeatmassgValve7Cmd
(
    P2VAR(PassSeatmassgValve7Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve8Cmd_PassSeatmassgValve8Cmd
(
    P2VAR(PassSeatmassgValve8Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_PassSeatmassgValve9Cmd_PassSeatmassgValve9Cmd
(
    P2VAR(PassSeatmassgValve9Cmd_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_Sec_Sec
(
    P2VAR(Sec_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VC_Data_5E0_CRC_VC_Data_5E0_CRC
(
    P2VAR(VC_Data_5E0_CRC_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VC_Data_5E0_MsgCntr_VC_Data_5E0_MsgCntr
(
    P2VAR(VC_Data_5E0_MsgCntr_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VC_Data_5E0_Payload_VC_Data_5E0_Payload
(
    P2VAR(VC_Data_5E0_Payload_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VehModeDef_VehModeDef
(
    P2VAR(VehModeDef_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VehOdometer_VehOdometer
(
    P2VAR(VehOdometer_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VehSpdSts_Rdnt1_VehSpdSts_Rdnt1
(
    P2VAR(VehSpdSts_Rdnt1_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VehSpd_Rdnt1_VehSpd_Rdnt1
(
    P2VAR(VehSpd_Rdnt1_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VehStateDetailed_VehStateDetailed
(
    P2VAR(VehStateDetailed_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_VehStateDetailed_SrvSts_VehStateDetailed_SrvSts
(
    P2VAR(VehStateDetailed_SrvSts_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_Yr_Yr
(
    P2VAR(Yr_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_ZONE_13C_CRC_ZONE_13C_CRC
(
    P2VAR(ZONE_13C_CRC_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Com_ZONE_13C_MsgCntr_ZONE_13C_MsgCntr
(
    P2VAR(ZONE_13C_MsgCntr_IDT, AUTOMATIC, RTE_APPL_DATA) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvHeat1Sts_DrvHeat1Sts
(
    CONST(DrvHeat1Sts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvHeat2Sts_DrvHeat2Sts
(
    CONST(DrvHeat2Sts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvHeat3Sts_DrvHeat3Sts
(
    CONST(DrvHeat3Sts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvHeat4Sts_DrvHeat4Sts
(
    CONST(DrvHeat4Sts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvHeat5ErrSts_DrvHeat5ErrSts
(
    CONST(DrvHeat5ErrSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvHeat5Sts_DrvHeat5Sts
(
    CONST(DrvHeat5Sts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvHeat6Sts_DrvHeat6Sts
(
    CONST(DrvHeat6Sts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgSkillsSts10_DrvKneadingMassgSkillsSts10
(
    CONST(DrvKneadingMassgSkillsSts10_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgSkillsSts5_DrvKneadingMassgSkillsSts5
(
    CONST(DrvKneadingMassgSkillsSts5_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgSkillsSts6_DrvKneadingMassgSkillsSts6
(
    CONST(DrvKneadingMassgSkillsSts6_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgSkillsSts7_DrvKneadingMassgSkillsSts7
(
    CONST(DrvKneadingMassgSkillsSts7_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgSkillsSts8_DrvKneadingMassgSkillsSts8
(
    CONST(DrvKneadingMassgSkillsSts8_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgSkillsSts9_DrvKneadingMassgSkillsSts9
(
    CONST(DrvKneadingMassgSkillsSts9_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgTime10_DrvKneadingMassgTime10
(
    CONST(DrvKneadingMassgTime10_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgTime5_DrvKneadingMassgTime5
(
    CONST(DrvKneadingMassgTime5_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgTime6_DrvKneadingMassgTime6
(
    CONST(DrvKneadingMassgTime6_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgTime7_DrvKneadingMassgTime7
(
    CONST(DrvKneadingMassgTime7_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgTime8_DrvKneadingMassgTime8
(
    CONST(DrvKneadingMassgTime8_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassgTime9_DrvKneadingMassgTime9
(
    CONST(DrvKneadingMassgTime9_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassglvlSts10_DrvKneadingMassglvlSts10
(
    CONST(DrvKneadingMassglvlSts10_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassglvlSts5_DrvKneadingMassglvlSts5
(
    CONST(DrvKneadingMassglvlSts5_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassglvlSts6_DrvKneadingMassglvlSts6
(
    CONST(DrvKneadingMassglvlSts6_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassglvlSts7_DrvKneadingMassglvlSts7
(
    CONST(DrvKneadingMassglvlSts7_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassglvlSts8_DrvKneadingMassglvlSts8
(
    CONST(DrvKneadingMassglvlSts8_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvKneadingMassglvlSts9_DrvKneadingMassglvlSts9
(
    CONST(DrvKneadingMassglvlSts9_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvLumControlSts_DrvLumControlSts
(
    CONST(DrvLumControlSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvLumSwitchSts_DrvLumSwitchSts
(
    CONST(DrvLumSwitchSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvLumbarBottomWorkSts_DrvLumbarBottomWorkSts
(
    CONST(DrvLumbarBottomWorkSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvLumbarMidWorkSts_DrvLumbarMidWorkSts
(
    CONST(DrvLumbarMidWorkSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvLumbarTopWorkSts_DrvLumbarTopWorkSts
(
    CONST(DrvLumbarTopWorkSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassSwitchSts_DrvMassSwitchSts
(
    CONST(DrvMassSwitchSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC1_DrvMassageHeatNTC1
(
    CONST(DrvMassageHeatNTC1_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC10_DrvMassageHeatNTC10
(
    CONST(DrvMassageHeatNTC10_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC11_DrvMassageHeatNTC11
(
    CONST(DrvMassageHeatNTC11_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC12_DrvMassageHeatNTC12
(
    CONST(DrvMassageHeatNTC12_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC2_DrvMassageHeatNTC2
(
    CONST(DrvMassageHeatNTC2_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC3_DrvMassageHeatNTC3
(
    CONST(DrvMassageHeatNTC3_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC4_DrvMassageHeatNTC4
(
    CONST(DrvMassageHeatNTC4_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC5_DrvMassageHeatNTC5
(
    CONST(DrvMassageHeatNTC5_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC6_DrvMassageHeatNTC6
(
    CONST(DrvMassageHeatNTC6_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC7_DrvMassageHeatNTC7
(
    CONST(DrvMassageHeatNTC7_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC8_DrvMassageHeatNTC8
(
    CONST(DrvMassageHeatNTC8_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvMassageHeatNTC9_DrvMassageHeatNTC9
(
    CONST(DrvMassageHeatNTC9_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvPumpSts_DrvPumpSts
(
    CONST(DrvPumpSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatBlosterValueSts_DrvSeatBlosterValueSts
(
    CONST(DrvSeatBlosterValueSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatBolsterValueBLPos_DrvSeatBolsterValueBLPos
(
    CONST(DrvSeatBolsterValueBLPos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatBolsterValueBRPos_DrvSeatBolsterValueBRPos
(
    CONST(DrvSeatBolsterValueBRPos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatCushionValue1Pos_DrvSeatCushionValue1Pos
(
    CONST(DrvSeatCushionValue1Pos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatCushionValue2Pos_DrvSeatCushionValue2Pos
(
    CONST(DrvSeatCushionValue2Pos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatCushionValue3Pos_DrvSeatCushionValue3Pos
(
    CONST(DrvSeatCushionValue3Pos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatCushionValue4Pos_DrvSeatCushionValue4Pos
(
    CONST(DrvSeatCushionValue4Pos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatCushionValue5Pos_DrvSeatCushionValue5Pos
(
    CONST(DrvSeatCushionValue5Pos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatCushionValue6Pos_DrvSeatCushionValue6Pos
(
    CONST(DrvSeatCushionValue6Pos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatCushionValueSts_DrvSeatCushionValueSts
(
    CONST(DrvSeatCushionValueSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatLumbarBottomPos_DrvSeatLumbarBottomPos
(
    CONST(DrvSeatLumbarBottomPos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatLumbarMidPos_DrvSeatLumbarMidPos
(
    CONST(DrvSeatLumbarMidPos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatLumbarTopPos_DrvSeatLumbarTopPos
(
    CONST(DrvSeatLumbarTopPos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatLumbarValueSts_DrvSeatLumbarValueSts
(
    CONST(DrvSeatLumbarValueSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatMassFailr_DrvSeatMassFailr
(
    CONST(DrvSeatMassFailr_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatUpperValueLPos_DrvSeatUpperValueLPos
(
    CONST(DrvSeatUpperValueLPos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatUpperValueMPos_DrvSeatUpperValueMPos
(
    CONST(DrvSeatUpperValueMPos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatUpperValueRPos_DrvSeatUpperValueRPos
(
    CONST(DrvSeatUpperValueRPos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatUpperValueSts_DrvSeatUpperValueSts
(
    CONST(DrvSeatUpperValueSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatmassgHeatCSts_DrvSeatmassgHeatCSts
(
    CONST(DrvSeatmassgHeatCSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSeatmassgValveSts_DrvSeatmassgValveSts
(
    CONST(DrvSeatmassgValveSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_DrvSystemFailr_DrvSystemFailr
(
    CONST(DrvSystemFailr_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassHeat1Sts_PassHeat1Sts
(
    CONST(PassHeat1Sts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassHeat2Sts_PassHeat2Sts
(
    CONST(PassHeat2Sts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassHeat3Sts_PassHeat3Sts
(
    CONST(PassHeat3Sts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassHeat4Sts_PassHeat4Sts
(
    CONST(PassHeat4Sts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassHeat5ErrSts_PassHeat5ErrSts
(
    CONST(PassHeat5ErrSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassHeat5Sts_PassHeat5Sts
(
    CONST(PassHeat5Sts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassHeat6Sts_PassHeat6Sts
(
    CONST(PassHeat6Sts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgLvlSts10_PassKneadingMassgLvlSts10
(
    CONST(PassKneadingMassgLvlSts10_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgLvlSts5_PassKneadingMassgLvlSts5
(
    CONST(PassKneadingMassgLvlSts5_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgLvlSts6_PassKneadingMassgLvlSts6
(
    CONST(PassKneadingMassgLvlSts6_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgLvlSts7_PassKneadingMassgLvlSts7
(
    CONST(PassKneadingMassgLvlSts7_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgLvlSts8_PassKneadingMassgLvlSts8
(
    CONST(PassKneadingMassgLvlSts8_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgLvlSts9_PassKneadingMassgLvlSts9
(
    CONST(PassKneadingMassgLvlSts9_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgSkillsSts10_PassKneadingMassgSkillsSts10
(
    CONST(PassKneadingMassgSkillsSts10_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgSkillsSts5_PassKneadingMassgSkillsSts5
(
    CONST(PassKneadingMassgSkillsSts5_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgSkillsSts6_PassKneadingMassgSkillsSts6
(
    CONST(PassKneadingMassgSkillsSts6_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgSkillsSts7_PassKneadingMassgSkillsSts7
(
    CONST(PassKneadingMassgSkillsSts7_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgSkillsSts8_PassKneadingMassgSkillsSts8
(
    CONST(PassKneadingMassgSkillsSts8_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgSkillsSts9_PassKneadingMassgSkillsSts9
(
    CONST(PassKneadingMassgSkillsSts9_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgTime10_PassKneadingMassgTime10
(
    CONST(PassKneadingMassgTime10_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgTime5_PassKneadingMassgTime5
(
    CONST(PassKneadingMassgTime5_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgTime6_PassKneadingMassgTime6
(
    CONST(PassKneadingMassgTime6_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgTime7_PassKneadingMassgTime7
(
    CONST(PassKneadingMassgTime7_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgTime8_PassKneadingMassgTime8
(
    CONST(PassKneadingMassgTime8_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassKneadingMassgTime9_PassKneadingMassgTime9
(
    CONST(PassKneadingMassgTime9_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassLumControlSts_PassLumControlSts
(
    CONST(PassLumControlSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassLumSwitchSts_PassLumSwitchSts
(
    CONST(PassLumSwitchSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassLumbarBottomWorkSts_PassLumbarBottomWorkSts
(
    CONST(PassLumbarBottomWorkSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassLumbarMidWorkSts_PassLumbarMidWorkSts
(
    CONST(PassLumbarMidWorkSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassLumbarTopWorkSts_PassLumbarTopWorkSts
(
    CONST(PassLumbarTopWorkSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassSwitchSts_PassMassSwitchSts
(
    CONST(PassMassSwitchSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC1_PassMassageHeatNTC1
(
    CONST(PassMassageHeatNTC1_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC10_PassMassageHeatNTC10
(
    CONST(PassMassageHeatNTC10_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC11_PassMassageHeatNTC11
(
    CONST(PassMassageHeatNTC11_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC12_PassMassageHeatNTC12
(
    CONST(PassMassageHeatNTC12_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC2_PassMassageHeatNTC2
(
    CONST(PassMassageHeatNTC2_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC3_PassMassageHeatNTC3
(
    CONST(PassMassageHeatNTC3_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC4_PassMassageHeatNTC4
(
    CONST(PassMassageHeatNTC4_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC5_PassMassageHeatNTC5
(
    CONST(PassMassageHeatNTC5_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC6_PassMassageHeatNTC6
(
    CONST(PassMassageHeatNTC6_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC7_PassMassageHeatNTC7
(
    CONST(PassMassageHeatNTC7_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC8_PassMassageHeatNTC8
(
    CONST(PassMassageHeatNTC8_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassMassageHeatNTC9_PassMassageHeatNTC9
(
    CONST(PassMassageHeatNTC9_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassPumpSts_PassPumpSts
(
    CONST(PassPumpSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatBlosterValueSts_PassSeatBlosterValueSts
(
    CONST(PassSeatBlosterValueSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatBolsterValueBLPos_PassSeatBolsterValueBLPos
(
    CONST(PassSeatBolsterValueBLPos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatBolsterValueBRPos_PassSeatBolsterValueBRPos
(
    CONST(PassSeatBolsterValueBRPos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatCushionValue1Pos_PassSeatCushionValue1Pos
(
    CONST(PassSeatCushionValue1Pos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatCushionValue2Pos_PassSeatCushionValue2Pos
(
    CONST(PassSeatCushionValue2Pos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatCushionValue3Pos_PassSeatCushionValue3Pos
(
    CONST(PassSeatCushionValue3Pos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatCushionValue4Pos_PassSeatCushionValue4Pos
(
    CONST(PassSeatCushionValue4Pos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatCushionValue5Pos_PassSeatCushionValue5Pos
(
    CONST(PassSeatCushionValue5Pos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatCushionValue6Pos_PassSeatCushionValue6Pos
(
    CONST(PassSeatCushionValue6Pos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatCushionValueSts_PassSeatCushionValueSts
(
    CONST(PassSeatCushionValueSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatLumbarBottomPos_PassSeatLumbarBottomPos
(
    CONST(PassSeatLumbarBottomPos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatLumbarMidPos_PassSeatLumbarMidPos
(
    CONST(PassSeatLumbarMidPos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatLumbarTopPos_PassSeatLumbarTopPos
(
    CONST(PassSeatLumbarTopPos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatLumbarValueSts_PassSeatLumbarValueSts
(
    CONST(PassSeatLumbarValueSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatMassFailr_PassSeatMassFailr
(
    CONST(PassSeatMassFailr_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatUpperValueLPos_PassSeatUpperValueLPos
(
    CONST(PassSeatUpperValueLPos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatUpperValueMPos_PassSeatUpperValueMPos
(
    CONST(PassSeatUpperValueMPos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatUpperValueRPos_PassSeatUpperValueRPos
(
    CONST(PassSeatUpperValueRPos_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatUpperValueSts_PassSeatUpperValueSts
(
    CONST(PassSeatUpperValueSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatmassgHeatCSts_PassSeatmassgHeatCSts
(
    CONST(PassSeatmassgHeatCSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSeatmassgValveSts_PassSeatmassgValveSts
(
    CONST(PassSeatmassgValveSts_IDT, AUTOMATIC) data
);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Com_PassSystemFailr_PassSystemFailr
(
    CONST(PassSystemFailr_IDT, AUTOMATIC) data
);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif  /*RTE_COM_H*/


