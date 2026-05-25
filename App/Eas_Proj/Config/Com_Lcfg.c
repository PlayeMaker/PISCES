/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Com_Lcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Com module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Com module configuration File
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
/*PRQA S 791,792 EOF*/
/*
Relevant names of WDGM_AR_RELEASE_REVISION_VERSION may not follow relevant naming rules.
*/

/*PRQA S 5087,3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address segments in the files of each module.
*/

/*PRQA S 0857,0380 EOF*/
/*
Macro definitions exceed 1024. The number of macros is unlimited
*/

/*PRQA S 3111,2213,3132,3211,0914,3120,1533 EOF*/
/*
Particularity of configuration files.
*/

/*PRQA S 4153,4152 EOF*/
/*
Specific naming rules without modification
*/

/*PRQA S 2100,2101 EOF*/
/*
Integer promotion related
*/

/*PRQA S 3227 EOF*/
/*
Read-only function input parameters may not be defined as const,it does not affect the function.
AUTOSAR API shall define standard input parameters according to specification requirements.
*/

/*PRQA S 3204,3206 EOF*/
/*
Read-only local variables may not be defined as const,this does not affect the function
*/

/*PRQA S 2000 EOF*/
/*
When there is only one If,there can be no else.
*/

/*PRQA S 316,315 EOF*/
/*
Allows the void pointer type to be converted into other pointer types.
*/

/*PRQA S 777,778,779,789,776,787,785 EOF*/
/*
Names generated in configuration files may not follow relevant rules.
*/

/*PRQA S 0580,1272,0790,1290 EOF*/
/*
The float type is allowed.
*/

/*PRQA S 1502,1504,1751 EOF*/
/*
Use in Com code.
*/

/*PRQA S 1559 EOF*/
/*
The generated code is statically initialized.
*/
 
/*PRQA S 1550 EOF*/
/*
This variable is used in the code of multiple files, 
so it is defined in a general-purpose file.
*/

/*PRQA S 612 EOF*/
/*
Size of object 'Com' exceeds 32767 bytes -program does not conform strictly to ISO:C90.
*/
 
/*PRQA S 1281 EOF*/
/*
Integer Literal constant is of an unsigned type but does not include a "U" suffix.
*/

/*PRQA S 1502,1503,1531,1532,1751 EOF*/
/*
Used by other modules.
*/
/*PRQA S 0580,1272,0790,1290 EOF*/
/*
The float type is allowed.
*/



/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Com.h"
#include "Rte_Com.h"


/*******************************************************************************
*   Com Internal Vars
*******************************************************************************/
#define COM_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "Com_MemMap.h"
VAR(Com_RxPduType, COM_VAR) Com_RxPduTable[11];
VAR(Com_TxPduType, COM_VAR) Com_TxPduTable[6];
#define COM_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "Com_MemMap.h"

#define COM_START_SEC_VAR_CLEARED_LOCAL_8
#include "Com_MemMap.h"
VAR(Com_TxPduStateType, COM_VAR) Com_TxPduState[6];
VAR(uint8, COM_VAR) Com_SendSwitchTxModeFlag[6];
VAR(Com_RxPduStateType, COM_VAR) Com_RxPduState[11];
VAR(boolean, COM_VAR) Com_IpduGroupStartFlag[2];
VAR(boolean, COM_VAR) Com_IpduGroupDMEnableFlag[2];
#define COM_STOP_SEC_VAR_CLEARED_LOCAL_8
#include "Com_MemMap.h"

/*******************************************************************************
*   Tx Sig Buffer
*******************************************************************************/

#define COM_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "Com_MemMap.h"

VAR(uint8, COM_VAR_NOINIT) Com_TxPdu_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6[8];
VAR(uint8, COM_VAR_NOINIT) Com_TxPdu_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF[8];
VAR(uint8, COM_VAR_NOINIT) Com_TxPdu_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0[8];
VAR(uint8, COM_VAR_NOINIT) Com_TxPdu_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1[8];
VAR(uint8, COM_VAR_NOINIT) Com_TxPdu_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8[8];
VAR(uint8, COM_VAR_NOINIT) Com_TxPdu_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC[8];


VAR(uint8, COM_VAR_NOINIT) Com_TxPdu_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7[8];
VAR(uint8, COM_VAR_NOINIT) Com_TxPdu_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2[8];
VAR(uint8, COM_VAR_NOINIT) Com_TxPdu_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3[8];
VAR(uint8, COM_VAR_NOINIT) Com_TxPdu_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4[8];
VAR(uint8, COM_VAR_NOINIT) Com_TxPdu_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB[8];
VAR(uint8, COM_VAR_NOINIT) Com_TxPdu_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED[8];



#define COM_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "Com_MemMap.h"


#define COM_START_SEC_CONFIG_DATA
#include "Com_MemMap.h"




/*******************************************************************************
*   Tx signal and pdu
*******************************************************************************/


#define COM_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "Com_MemMap.h"


STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts5;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts6;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts5;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts6;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts7;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts8;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts7;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts8;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime8;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime5;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime6;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime7;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvMassSwitchSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgHeatCSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarValueSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgValveSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatUpperValueSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValueSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBlosterValueSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarTopPos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarMidPos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarBottomPos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBLPos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBRPos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValue6Pos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue5Pos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue4Pos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue2Pos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue1Pos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueLPos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueMPos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueRPos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvPumpSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgSkillsSts9;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumControlSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumSwitchSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSystemFailr;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatMassFailr;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatCushionValue3Pos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarTopWorkSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarMidWorkSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarBottomWorkSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat1Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat2Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat3Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat4Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat6Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5ErrSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassglvlSts9;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgTime9;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgTime10;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgSkillsSts10;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassglvlSts10;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC1;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC2;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC3;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC4;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC5;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC6;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC7;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC8;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC9;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC10;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC11;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC12;


STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts5;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts5;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts6;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime5;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts6;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts7;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime6;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime7;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts8;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts7;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts8;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime8;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgValveSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgHeatCSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarValueSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatUpperValueSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValueSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBlosterValueSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassMassSwitchSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarTopPos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarMidPos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarBottomPos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBLPos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBRPos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValue6Pos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue5Pos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue4Pos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue2Pos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue1Pos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueLPos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueMPos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueRPos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassPumpSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgSkillsSts9;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumControlSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumSwitchSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSystemFailr;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatMassFailr;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatCushionValue3Pos;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarTopWorkSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarMidWorkSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarBottomWorkSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat1Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat2Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat3Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat4Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat6Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5ErrSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgLvlSts9;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgTime9;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgTime10;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgSkillsSts10;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgLvlSts10;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC1;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC2;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC3;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC4;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC5;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC6;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC7;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC8;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC9;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC10;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC11;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC12;


#define COM_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "Com_MemMap.h"






/*******************************************************************************
*   Tx Init value, Invalid, Filter parameters 

*******************************************************************************/
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts5*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts5= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts6*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts6= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts5*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts5= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts6*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts6= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts7*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts7= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts8*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts8= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts7*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts7= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts8*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts8= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime8*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime8= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime5*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime5= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime6*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime6= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime7*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime7= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvMassSwitchSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvMassSwitchSts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgHeatCSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgHeatCSts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarValueSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarValueSts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgValveSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgValveSts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatUpperValueSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatUpperValueSts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValueSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValueSts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBlosterValueSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBlosterValueSts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarTopPos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarTopPos= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarMidPos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarMidPos= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarBottomPos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarBottomPos= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBLPos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBLPos= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBRPos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBRPos= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValue6Pos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValue6Pos= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue5Pos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue5Pos= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue4Pos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue4Pos= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue2Pos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue2Pos= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue1Pos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue1Pos= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueLPos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueLPos= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueMPos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueMPos= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueRPos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueRPos= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvPumpSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvPumpSts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgSkillsSts9*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgSkillsSts9= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumControlSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumControlSts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumSwitchSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumSwitchSts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSystemFailr*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSystemFailr= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatMassFailr*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatMassFailr= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatCushionValue3Pos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatCushionValue3Pos= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarTopWorkSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarTopWorkSts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarMidWorkSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarMidWorkSts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarBottomWorkSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarBottomWorkSts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat1Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat1Sts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat2Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat2Sts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat3Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat3Sts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat4Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat4Sts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5Sts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat6Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat6Sts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5ErrSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5ErrSts= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassglvlSts9*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassglvlSts9= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgTime9*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgTime9= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgTime10*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgTime10= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgSkillsSts10*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgSkillsSts10= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassglvlSts10*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassglvlSts10= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC1*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC1= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC2*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC2= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC3*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC3= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC4*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC4= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC5*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC5= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC6*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC6= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC7*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC7= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC8*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC8= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC9*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC9= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC10*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC10= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC11*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC11= (uint8)0;
/********* Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC12*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC12= (uint8)0;


CONST(Com_CfgTxSigTableType, COM_CONST) ComTxSigCfgTable0[66] =
{
    /*Pdu0, Signal 0*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts5,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts5,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)0,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts5,/* txAck function */
    },
    /*Pdu0, Signal 1*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts6,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts6,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)4,/* StartBit */
        (uint8)0xf,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts6,/* txAck function */
    },
    /*Pdu0, Signal 2*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts5,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts5,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)8,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0x3,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts5,/* txAck function */
    },
    /*Pdu0, Signal 3*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts6,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts6,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)10,/* StartBit */
        (uint8)0x3,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts6,/* txAck function */
    },
    /*Pdu0, Signal 4*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts7,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts7,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)12,/* StartBit */
        (uint8)0xf,/* MaskLsb */
        (uint8)0x3f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts7,/* txAck function */
    },
    /*Pdu0, Signal 5*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts8,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts8,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)14,/* StartBit */
        (uint8)0x3f,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts8,/* txAck function */
    },
    /*Pdu0, Signal 6*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts7,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts7,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)16,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts7,/* txAck function */
    },
    /*Pdu0, Signal 7*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts8,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts8,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)20,/* StartBit */
        (uint8)0xf,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts8,/* txAck function */
    },
    /*Pdu0, Signal 8*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime8,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime8,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)24,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime8,/* txAck function */
    },
    /*Pdu0, Signal 9*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime5,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime5,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)40,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime5,/* txAck function */
    },
    /*Pdu0, Signal 10*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime6,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime6,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)48,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime6,/* txAck function */
    },
    /*Pdu0, Signal 11*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime7,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime7,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)56,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime7,/* txAck function */
    },
    /*Pdu1, Signal 12*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvMassSwitchSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvMassSwitchSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)0,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0x3,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvMassSwitchSts,/* txAck function */
    },
    /*Pdu1, Signal 13*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgHeatCSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgHeatCSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)2,/* StartBit */
        (uint8)0x3,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgHeatCSts,/* txAck function */
    },
    /*Pdu1, Signal 14*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarValueSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarValueSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)4,/* StartBit */
        (uint8)0xf,/* MaskLsb */
        (uint8)0x3f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarValueSts,/* txAck function */
    },
    /*Pdu1, Signal 15*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgValveSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgValveSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)6,/* StartBit */
        (uint8)0x3f,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgValveSts,/* txAck function */
    },
    /*Pdu1, Signal 16*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatUpperValueSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatUpperValueSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)8,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0x3,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatUpperValueSts,/* txAck function */
    },
    /*Pdu1, Signal 17*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValueSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValueSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)10,/* StartBit */
        (uint8)0x3,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValueSts,/* txAck function */
    },
    /*Pdu1, Signal 18*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBlosterValueSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBlosterValueSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)12,/* StartBit */
        (uint8)0xf,/* MaskLsb */
        (uint8)0x3f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBlosterValueSts,/* txAck function */
    },
    /*Pdu1, Signal 19*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarTopPos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarTopPos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)16,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarTopPos,/* txAck function */
    },
    /*Pdu1, Signal 20*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarMidPos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarMidPos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)24,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarMidPos,/* txAck function */
    },
    /*Pdu1, Signal 21*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarBottomPos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarBottomPos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)32,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarBottomPos,/* txAck function */
    },
    /*Pdu1, Signal 22*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBLPos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBLPos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)40,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBLPos,/* txAck function */
    },
    /*Pdu1, Signal 23*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBRPos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBRPos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)48,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBRPos,/* txAck function */
    },
    /*Pdu1, Signal 24*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValue6Pos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValue6Pos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)56,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValue6Pos,/* txAck function */
    },
    /*Pdu2, Signal 25*/
    {
        (PduIdType)2,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue5Pos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue5Pos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)0,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue5Pos,/* txAck function */
    },
    /*Pdu2, Signal 26*/
    {
        (PduIdType)2,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue4Pos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue4Pos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)8,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue4Pos,/* txAck function */
    },
    /*Pdu2, Signal 27*/
    {
        (PduIdType)2,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue2Pos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue2Pos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)16,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue2Pos,/* txAck function */
    },
    /*Pdu2, Signal 28*/
    {
        (PduIdType)2,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue1Pos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue1Pos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)24,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue1Pos,/* txAck function */
    },
    /*Pdu2, Signal 29*/
    {
        (PduIdType)2,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueLPos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueLPos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)32,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueLPos,/* txAck function */
    },
    /*Pdu2, Signal 30*/
    {
        (PduIdType)2,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueMPos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueMPos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)40,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueMPos,/* txAck function */
    },
    /*Pdu2, Signal 31*/
    {
        (PduIdType)2,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueRPos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueRPos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)48,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueRPos,/* txAck function */
    },
    /*Pdu2, Signal 32*/
    {
        (PduIdType)2,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvPumpSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvPumpSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)56,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvPumpSts,/* txAck function */
    },
    /*Pdu3, Signal 33*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgSkillsSts9,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgSkillsSts9,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)8,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgSkillsSts9,/* txAck function */
    },
    /*Pdu3, Signal 34*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumControlSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumControlSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)3,/* BitSize */
        (uint16)16,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0x7,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumControlSts,/* txAck function */
    },
    /*Pdu3, Signal 35*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumSwitchSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumSwitchSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)3,/* BitSize */
        (uint16)19,/* StartBit */
        (uint8)0x7,/* MaskLsb */
        (uint8)0x3f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumSwitchSts,/* txAck function */
    },
    /*Pdu3, Signal 36*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSystemFailr,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSystemFailr,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)22,/* StartBit */
        (uint8)0x3f,/* MaskLsb */
        (uint8)0x7f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSystemFailr,/* txAck function */
    },
    /*Pdu3, Signal 37*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatMassFailr,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatMassFailr,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)23,/* StartBit */
        (uint8)0x7f,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatMassFailr,/* txAck function */
    },
    /*Pdu3, Signal 38*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatCushionValue3Pos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatCushionValue3Pos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)24,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatCushionValue3Pos,/* txAck function */
    },
    /*Pdu3, Signal 39*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarTopWorkSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarTopWorkSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)32,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0x3,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarTopWorkSts,/* txAck function */
    },
    /*Pdu3, Signal 40*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarMidWorkSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarMidWorkSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)34,/* StartBit */
        (uint8)0x3,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarMidWorkSts,/* txAck function */
    },
    /*Pdu3, Signal 41*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarBottomWorkSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarBottomWorkSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)36,/* StartBit */
        (uint8)0xf,/* MaskLsb */
        (uint8)0x3f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarBottomWorkSts,/* txAck function */
    },
    /*Pdu3, Signal 42*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat1Sts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat1Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)38,/* StartBit */
        (uint8)0x3f,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat1Sts,/* txAck function */
    },
    /*Pdu3, Signal 43*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat2Sts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat2Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)40,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0x3,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat2Sts,/* txAck function */
    },
    /*Pdu3, Signal 44*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat3Sts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat3Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)42,/* StartBit */
        (uint8)0x3,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat3Sts,/* txAck function */
    },
    /*Pdu3, Signal 45*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat4Sts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat4Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)44,/* StartBit */
        (uint8)0xf,/* MaskLsb */
        (uint8)0x3f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat4Sts,/* txAck function */
    },
    /*Pdu3, Signal 46*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5Sts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)46,/* StartBit */
        (uint8)0x3f,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5Sts,/* txAck function */
    },
    /*Pdu3, Signal 47*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat6Sts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat6Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)48,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0x3,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat6Sts,/* txAck function */
    },
    /*Pdu3, Signal 48*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5ErrSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5ErrSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)50,/* StartBit */
        (uint8)0x3,/* MaskLsb */
        (uint8)0x3f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5ErrSts,/* txAck function */
    },
    /*Pdu3, Signal 49*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassglvlSts9,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassglvlSts9,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)54,/* StartBit */
        (uint8)0x3f,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassglvlSts9,/* txAck function */
    },
    /*Pdu3, Signal 50*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgTime9,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgTime9,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)56,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgTime9,/* txAck function */
    },
    /*Pdu4, Signal 51*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgTime10,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgTime10,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)0,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgTime10,/* txAck function */
    },
    /*Pdu4, Signal 52*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgSkillsSts10,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgSkillsSts10,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)8,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgSkillsSts10,/* txAck function */
    },
    /*Pdu4, Signal 53*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassglvlSts10,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassglvlSts10,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)12,/* StartBit */
        (uint8)0xf,/* MaskLsb */
        (uint8)0x3f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassglvlSts10,/* txAck function */
    },
    /*Pdu4, Signal 54*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC1,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC1,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)16,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC1,/* txAck function */
    },
    /*Pdu4, Signal 55*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC2,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC2,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)24,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC2,/* txAck function */
    },
    /*Pdu4, Signal 56*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC3,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC3,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)32,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC3,/* txAck function */
    },
    /*Pdu4, Signal 57*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC4,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC4,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)40,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC4,/* txAck function */
    },
    /*Pdu4, Signal 58*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC5,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC5,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)48,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC5,/* txAck function */
    },
    /*Pdu4, Signal 59*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC6,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC6,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)56,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC6,/* txAck function */
    },
    /*Pdu5, Signal 60*/
    {
        (PduIdType)5,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC7,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC7,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)16,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC7,/* txAck function */
    },
    /*Pdu5, Signal 61*/
    {
        (PduIdType)5,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC8,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC8,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)24,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC8,/* txAck function */
    },
    /*Pdu5, Signal 62*/
    {
        (PduIdType)5,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC9,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC9,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)32,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC9,/* txAck function */
    },
    /*Pdu5, Signal 63*/
    {
        (PduIdType)5,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC10,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC10,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)40,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC10,/* txAck function */
    },
    /*Pdu5, Signal 64*/
    {
        (PduIdType)5,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC11,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC11,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)48,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC11,/* txAck function */
    },
    /*Pdu5, Signal 65*/
    {
        (PduIdType)5,/* txpduid */
        &Com_TxSigShareBuf_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC12,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC12,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)56,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC12,/* txAck function */
    },
};
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts5*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts5= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts5*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts5= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts6*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts6= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime5*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime5= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts6*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts6= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts7*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts7= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime6*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime6= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime7*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime7= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts8*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts8= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts7*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts7= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts8*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts8= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime8*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime8= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgValveSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgValveSts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgHeatCSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgHeatCSts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarValueSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarValueSts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatUpperValueSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatUpperValueSts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValueSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValueSts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBlosterValueSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBlosterValueSts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassMassSwitchSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassMassSwitchSts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarTopPos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarTopPos= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarMidPos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarMidPos= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarBottomPos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarBottomPos= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBLPos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBLPos= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBRPos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBRPos= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValue6Pos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValue6Pos= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue5Pos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue5Pos= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue4Pos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue4Pos= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue2Pos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue2Pos= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue1Pos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue1Pos= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueLPos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueLPos= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueMPos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueMPos= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueRPos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueRPos= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassPumpSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassPumpSts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgSkillsSts9*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgSkillsSts9= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumControlSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumControlSts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumSwitchSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumSwitchSts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSystemFailr*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSystemFailr= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatMassFailr*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatMassFailr= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatCushionValue3Pos*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatCushionValue3Pos= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarTopWorkSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarTopWorkSts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarMidWorkSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarMidWorkSts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarBottomWorkSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarBottomWorkSts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat1Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat1Sts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat2Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat2Sts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat3Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat3Sts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat4Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat4Sts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5Sts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat6Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat6Sts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5ErrSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5ErrSts= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgLvlSts9*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgLvlSts9= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgTime9*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgTime9= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgTime10*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgTime10= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgSkillsSts10*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgSkillsSts10= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgLvlSts10*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgLvlSts10= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC1*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC1= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC2*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC2= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC3*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC3= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC4*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC4= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC5*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC5= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC6*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC6= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC7*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC7= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC8*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC8= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC9*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC9= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC10*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC10= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC11*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC11= (uint8)0;
/********* Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC12*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC12= (uint8)0;


CONST(Com_CfgTxSigTableType, COM_CONST) ComTxSigCfgTable1[66] =
{
    /*Pdu0, Signal 0*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts5,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts5,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)0,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts5,/* txAck function */
    },
    /*Pdu0, Signal 1*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts5,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts5,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)4,/* StartBit */
        (uint8)0xf,/* MaskLsb */
        (uint8)0x3f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts5,/* txAck function */
    },
    /*Pdu0, Signal 2*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts6,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts6,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)6,/* StartBit */
        (uint8)0x3f,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts6,/* txAck function */
    },
    /*Pdu0, Signal 3*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime5,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime5,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)8,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime5,/* txAck function */
    },
    /*Pdu0, Signal 4*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts6,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts6,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)16,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts6,/* txAck function */
    },
    /*Pdu0, Signal 5*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts7,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts7,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)20,/* StartBit */
        (uint8)0xf,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts7,/* txAck function */
    },
    /*Pdu0, Signal 6*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime6,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime6,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)24,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime6,/* txAck function */
    },
    /*Pdu0, Signal 7*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime7,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime7,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)32,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime7,/* txAck function */
    },
    /*Pdu0, Signal 8*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts8,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts8,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)40,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts8,/* txAck function */
    },
    /*Pdu0, Signal 9*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts7,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts7,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)44,/* StartBit */
        (uint8)0xf,/* MaskLsb */
        (uint8)0x3f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts7,/* txAck function */
    },
    /*Pdu0, Signal 10*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts8,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts8,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)46,/* StartBit */
        (uint8)0x3f,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts8,/* txAck function */
    },
    /*Pdu0, Signal 11*/
    {
        (PduIdType)0,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime8,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime8,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)48,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime8,/* txAck function */
    },
    /*Pdu1, Signal 12*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgValveSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgValveSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)0,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0x3,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgValveSts,/* txAck function */
    },
    /*Pdu1, Signal 13*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgHeatCSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgHeatCSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)2,/* StartBit */
        (uint8)0x3,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgHeatCSts,/* txAck function */
    },
    /*Pdu1, Signal 14*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarValueSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarValueSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)4,/* StartBit */
        (uint8)0xf,/* MaskLsb */
        (uint8)0x3f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarValueSts,/* txAck function */
    },
    /*Pdu1, Signal 15*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatUpperValueSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatUpperValueSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)6,/* StartBit */
        (uint8)0x3f,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatUpperValueSts,/* txAck function */
    },
    /*Pdu1, Signal 16*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValueSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValueSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)10,/* StartBit */
        (uint8)0x3,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValueSts,/* txAck function */
    },
    /*Pdu1, Signal 17*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBlosterValueSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBlosterValueSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)12,/* StartBit */
        (uint8)0xf,/* MaskLsb */
        (uint8)0x3f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBlosterValueSts,/* txAck function */
    },
    /*Pdu1, Signal 18*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassMassSwitchSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassMassSwitchSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)14,/* StartBit */
        (uint8)0x3f,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassMassSwitchSts,/* txAck function */
    },
    /*Pdu1, Signal 19*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarTopPos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarTopPos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)16,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarTopPos,/* txAck function */
    },
    /*Pdu1, Signal 20*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarMidPos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarMidPos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)24,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarMidPos,/* txAck function */
    },
    /*Pdu1, Signal 21*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarBottomPos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarBottomPos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)32,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarBottomPos,/* txAck function */
    },
    /*Pdu1, Signal 22*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBLPos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBLPos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)40,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBLPos,/* txAck function */
    },
    /*Pdu1, Signal 23*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBRPos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBRPos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)48,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBRPos,/* txAck function */
    },
    /*Pdu1, Signal 24*/
    {
        (PduIdType)1,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValue6Pos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValue6Pos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)56,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValue6Pos,/* txAck function */
    },
    /*Pdu2, Signal 25*/
    {
        (PduIdType)2,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue5Pos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue5Pos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)0,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue5Pos,/* txAck function */
    },
    /*Pdu2, Signal 26*/
    {
        (PduIdType)2,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue4Pos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue4Pos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)8,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue4Pos,/* txAck function */
    },
    /*Pdu2, Signal 27*/
    {
        (PduIdType)2,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue2Pos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue2Pos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)16,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue2Pos,/* txAck function */
    },
    /*Pdu2, Signal 28*/
    {
        (PduIdType)2,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue1Pos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue1Pos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)24,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue1Pos,/* txAck function */
    },
    /*Pdu2, Signal 29*/
    {
        (PduIdType)2,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueLPos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueLPos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)32,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueLPos,/* txAck function */
    },
    /*Pdu2, Signal 30*/
    {
        (PduIdType)2,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueMPos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueMPos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)40,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueMPos,/* txAck function */
    },
    /*Pdu2, Signal 31*/
    {
        (PduIdType)2,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueRPos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueRPos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)48,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueRPos,/* txAck function */
    },
    /*Pdu2, Signal 32*/
    {
        (PduIdType)2,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassPumpSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassPumpSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)56,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassPumpSts,/* txAck function */
    },
    /*Pdu3, Signal 33*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgSkillsSts9,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgSkillsSts9,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)8,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgSkillsSts9,/* txAck function */
    },
    /*Pdu3, Signal 34*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumControlSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumControlSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)3,/* BitSize */
        (uint16)16,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0x7,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumControlSts,/* txAck function */
    },
    /*Pdu3, Signal 35*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumSwitchSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumSwitchSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)3,/* BitSize */
        (uint16)19,/* StartBit */
        (uint8)0x7,/* MaskLsb */
        (uint8)0x3f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumSwitchSts,/* txAck function */
    },
    /*Pdu3, Signal 36*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSystemFailr,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSystemFailr,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)22,/* StartBit */
        (uint8)0x3f,/* MaskLsb */
        (uint8)0x7f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSystemFailr,/* txAck function */
    },
    /*Pdu3, Signal 37*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatMassFailr,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatMassFailr,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)23,/* StartBit */
        (uint8)0x7f,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatMassFailr,/* txAck function */
    },
    /*Pdu3, Signal 38*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatCushionValue3Pos,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatCushionValue3Pos,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)24,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatCushionValue3Pos,/* txAck function */
    },
    /*Pdu3, Signal 39*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarTopWorkSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarTopWorkSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)32,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0x3,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarTopWorkSts,/* txAck function */
    },
    /*Pdu3, Signal 40*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarMidWorkSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarMidWorkSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)34,/* StartBit */
        (uint8)0x3,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarMidWorkSts,/* txAck function */
    },
    /*Pdu3, Signal 41*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarBottomWorkSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarBottomWorkSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)36,/* StartBit */
        (uint8)0xf,/* MaskLsb */
        (uint8)0x3f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarBottomWorkSts,/* txAck function */
    },
    /*Pdu3, Signal 42*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat1Sts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat1Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)38,/* StartBit */
        (uint8)0x3f,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat1Sts,/* txAck function */
    },
    /*Pdu3, Signal 43*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat2Sts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat2Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)40,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0x3,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat2Sts,/* txAck function */
    },
    /*Pdu3, Signal 44*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat3Sts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat3Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)42,/* StartBit */
        (uint8)0x3,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat3Sts,/* txAck function */
    },
    /*Pdu3, Signal 45*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat4Sts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat4Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)44,/* StartBit */
        (uint8)0xf,/* MaskLsb */
        (uint8)0x3f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat4Sts,/* txAck function */
    },
    /*Pdu3, Signal 46*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5Sts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)46,/* StartBit */
        (uint8)0x3f,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5Sts,/* txAck function */
    },
    /*Pdu3, Signal 47*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat6Sts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat6Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)48,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0x3,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat6Sts,/* txAck function */
    },
    /*Pdu3, Signal 48*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5ErrSts,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5ErrSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)50,/* StartBit */
        (uint8)0x3,/* MaskLsb */
        (uint8)0x3f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5ErrSts,/* txAck function */
    },
    /*Pdu3, Signal 49*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgLvlSts9,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgLvlSts9,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)54,/* StartBit */
        (uint8)0x3f,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgLvlSts9,/* txAck function */
    },
    /*Pdu3, Signal 50*/
    {
        (PduIdType)3,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgTime9,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgTime9,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)56,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgTime9,/* txAck function */
    },
    /*Pdu4, Signal 51*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgTime10,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgTime10,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)0,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgTime10,/* txAck function */
    },
    /*Pdu4, Signal 52*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgSkillsSts10,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgSkillsSts10,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)8,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xf,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgSkillsSts10,/* txAck function */
    },
    /*Pdu4, Signal 53*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgLvlSts10,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgLvlSts10,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)12,/* StartBit */
        (uint8)0xf,/* MaskLsb */
        (uint8)0x3f,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgLvlSts10,/* txAck function */
    },
    /*Pdu4, Signal 54*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC1,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC1,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)16,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC1,/* txAck function */
    },
    /*Pdu4, Signal 55*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC2,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC2,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)24,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC2,/* txAck function */
    },
    /*Pdu4, Signal 56*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC3,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC3,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)32,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC3,/* txAck function */
    },
    /*Pdu4, Signal 57*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC4,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC4,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)40,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC4,/* txAck function */
    },
    /*Pdu4, Signal 58*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC5,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC5,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)48,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC5,/* txAck function */
    },
    /*Pdu4, Signal 59*/
    {
        (PduIdType)4,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC6,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC6,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)56,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC6,/* txAck function */
    },
    /*Pdu5, Signal 60*/
    {
        (PduIdType)5,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC7,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC7,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)16,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC7,/* txAck function */
    },
    /*Pdu5, Signal 61*/
    {
        (PduIdType)5,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC8,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC8,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)24,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC8,/* txAck function */
    },
    /*Pdu5, Signal 62*/
    {
        (PduIdType)5,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC9,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC9,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)32,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC9,/* txAck function */
    },
    /*Pdu5, Signal 63*/
    {
        (PduIdType)5,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC10,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC10,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)40,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC10,/* txAck function */
    },
    /*Pdu5, Signal 64*/
    {
        (PduIdType)5,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC11,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC11,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)48,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC11,/* txAck function */
    },
    /*Pdu5, Signal 65*/
    {
        (PduIdType)5,/* txpduid */
        &Com_TxSigShareBuf_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC12,/* TxSigShareBufPtr */
        COM_PENDING,/* tr Property */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC12,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)56,/* StartBit */
        (uint8)0x0,/* MaskLsb */
        (uint8)0xff,/* MaskMsb */
        &Com_CbkTxAck_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC12,/* txAck function */
    },
};

/*******************************************************************************
*   Tx IPDU
*******************************************************************************/
/********* ComTxIPdu*********/
STATIC CONST(Com_CfgTxModeTableType, COM_CONST) ComTxModeTrue_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6 =
{
    COM_PERIODIC,
    (uint8)0,
    (uint16)0,
    (uint16)0,
    (uint16)5
};
/********* ComTxIPdu*********/
STATIC CONST(Com_CfgTxModeTableType, COM_CONST) ComTxModeTrue_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF =
{
    COM_PERIODIC,
    (uint8)0,
    (uint16)0,
    (uint16)0,
    (uint16)5
};
/********* ComTxIPdu*********/
STATIC CONST(Com_CfgTxModeTableType, COM_CONST) ComTxModeTrue_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0 =
{
    COM_PERIODIC,
    (uint8)0,
    (uint16)0,
    (uint16)0,
    (uint16)5
};
/********* ComTxIPdu*********/
STATIC CONST(Com_CfgTxModeTableType, COM_CONST) ComTxModeTrue_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1 =
{
    COM_PERIODIC,
    (uint8)0,
    (uint16)0,
    (uint16)0,
    (uint16)5
};
/********* ComTxIPdu*********/
STATIC CONST(Com_CfgTxModeTableType, COM_CONST) ComTxModeTrue_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8 =
{
    COM_PERIODIC,
    (uint8)0,
    (uint16)0,
    (uint16)0,
    (uint16)5
};
/********* ComTxIPdu*********/
STATIC CONST(Com_CfgTxModeTableType, COM_CONST) ComTxModeTrue_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC =
{
    COM_PERIODIC,
    (uint8)0,
    (uint16)0,
    (uint16)0,
    (uint16)5
};
/********* ComTxIPdu*********/
STATIC CONST(Com_CfgTxModeTableType, COM_CONST) ComTxModeTrue_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7 =
{
    COM_PERIODIC,
    (uint8)0,
    (uint16)0,
    (uint16)0,
    (uint16)5
};
/********* ComTxIPdu*********/
STATIC CONST(Com_CfgTxModeTableType, COM_CONST) ComTxModeTrue_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2 =
{
    COM_PERIODIC,
    (uint8)0,
    (uint16)0,
    (uint16)0,
    (uint16)5
};
/********* ComTxIPdu*********/
STATIC CONST(Com_CfgTxModeTableType, COM_CONST) ComTxModeTrue_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3 =
{
    COM_PERIODIC,
    (uint8)0,
    (uint16)0,
    (uint16)0,
    (uint16)5
};
/********* ComTxIPdu*********/
STATIC CONST(Com_CfgTxModeTableType, COM_CONST) ComTxModeTrue_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4 =
{
    COM_PERIODIC,
    (uint8)0,
    (uint16)0,
    (uint16)0,
    (uint16)5
};
/********* ComTxIPdu*********/
STATIC CONST(Com_CfgTxModeTableType, COM_CONST) ComTxModeTrue_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB =
{
    COM_PERIODIC,
    (uint8)0,
    (uint16)0,
    (uint16)0,
    (uint16)5
};
/********* ComTxIPdu*********/
STATIC CONST(Com_CfgTxModeTableType, COM_CONST) ComTxModeTrue_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED =
{
    COM_PERIODIC,
    (uint8)0,
    (uint16)0,
    (uint16)0,
    (uint16)5
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)0
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)0
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)0
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)0
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)0
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)0
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)0
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)0
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)0
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)0
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)0
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)0
};
 CONST(Com_CfgTxPduTableType, COM_CONST) ComTxPduCfgTable0[6] =
{
    {
        (uint16)0,/* mdt */
        (Com_SignalIdType)0,/* start sig index */
        (Com_SignalIdType)11,/* stop sig index */
        TRUE,/* group flag */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_IpduGroupPtr[0],/* pduGroupPtr */
        PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6,/* txpduId */
        Com_TxPdu_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6, /* data ptr*/
        (PduLengthType)8, /* data length*/
        &ComTxModeTrue_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6,
        NULL_PTR,
        FALSE,/* cancel support */
        (uint8)0x0/* unusedByte */
    },
    {
        (uint16)0,/* mdt */
        (Com_SignalIdType)12,/* start sig index */
        (Com_SignalIdType)24,/* stop sig index */
        TRUE,/* group flag */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_IpduGroupPtr[0],/* pduGroupPtr */
        PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF,/* txpduId */
        Com_TxPdu_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF, /* data ptr*/
        (PduLengthType)8, /* data length*/
        &ComTxModeTrue_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF,
        NULL_PTR,
        FALSE,/* cancel support */
        (uint8)0x0/* unusedByte */
    },
    {
        (uint16)0,/* mdt */
        (Com_SignalIdType)25,/* start sig index */
        (Com_SignalIdType)32,/* stop sig index */
        TRUE,/* group flag */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_IpduGroupPtr[0],/* pduGroupPtr */
        PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0,/* txpduId */
        Com_TxPdu_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0, /* data ptr*/
        (PduLengthType)8, /* data length*/
        &ComTxModeTrue_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0,
        NULL_PTR,
        FALSE,/* cancel support */
        (uint8)0x0/* unusedByte */
    },
    {
        (uint16)0,/* mdt */
        (Com_SignalIdType)33,/* start sig index */
        (Com_SignalIdType)50,/* stop sig index */
        TRUE,/* group flag */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_IpduGroupPtr[0],/* pduGroupPtr */
        PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1,/* txpduId */
        Com_TxPdu_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1, /* data ptr*/
        (PduLengthType)8, /* data length*/
        &ComTxModeTrue_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1,
        NULL_PTR,
        FALSE,/* cancel support */
        (uint8)0x0/* unusedByte */
    },
    {
        (uint16)0,/* mdt */
        (Com_SignalIdType)51,/* start sig index */
        (Com_SignalIdType)59,/* stop sig index */
        TRUE,/* group flag */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_IpduGroupPtr[0],/* pduGroupPtr */
        PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8,/* txpduId */
        Com_TxPdu_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8, /* data ptr*/
        (PduLengthType)8, /* data length*/
        &ComTxModeTrue_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8,
        NULL_PTR,
        FALSE,/* cancel support */
        (uint8)0x0/* unusedByte */
    },
    {
        (uint16)0,/* mdt */
        (Com_SignalIdType)60,/* start sig index */
        (Com_SignalIdType)65,/* stop sig index */
        TRUE,/* group flag */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_IpduGroupPtr[0],/* pduGroupPtr */
        PduR_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC,/* txpduId */
        Com_TxPdu_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC, /* data ptr*/
        (PduLengthType)8, /* data length*/
        &ComTxModeTrue_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC,
        NULL_PTR,
        FALSE,/* cancel support */
        (uint8)0x0/* unusedByte */
    },
};
 CONST(Com_CfgTxPduTableType, COM_CONST) ComTxPduCfgTable1[6] =
{
    {
        (uint16)0,/* mdt */
        (Com_SignalIdType)0,/* start sig index */
        (Com_SignalIdType)11,/* stop sig index */
        TRUE,/* group flag */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_IpduGroupPtr[0],/* pduGroupPtr */
        PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7,/* txpduId */
        Com_TxPdu_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7, /* data ptr*/
        (PduLengthType)8, /* data length*/
        &ComTxModeTrue_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7,
        NULL_PTR,
        FALSE,/* cancel support */
        (uint8)0x0/* unusedByte */
    },
    {
        (uint16)0,/* mdt */
        (Com_SignalIdType)12,/* start sig index */
        (Com_SignalIdType)24,/* stop sig index */
        TRUE,/* group flag */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_IpduGroupPtr[0],/* pduGroupPtr */
        PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2,/* txpduId */
        Com_TxPdu_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2, /* data ptr*/
        (PduLengthType)8, /* data length*/
        &ComTxModeTrue_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2,
        NULL_PTR,
        FALSE,/* cancel support */
        (uint8)0x0/* unusedByte */
    },
    {
        (uint16)0,/* mdt */
        (Com_SignalIdType)25,/* start sig index */
        (Com_SignalIdType)32,/* stop sig index */
        TRUE,/* group flag */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_IpduGroupPtr[0],/* pduGroupPtr */
        PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3,/* txpduId */
        Com_TxPdu_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3, /* data ptr*/
        (PduLengthType)8, /* data length*/
        &ComTxModeTrue_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3,
        NULL_PTR,
        FALSE,/* cancel support */
        (uint8)0x0/* unusedByte */
    },
    {
        (uint16)0,/* mdt */
        (Com_SignalIdType)33,/* start sig index */
        (Com_SignalIdType)50,/* stop sig index */
        TRUE,/* group flag */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_IpduGroupPtr[0],/* pduGroupPtr */
        PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4,/* txpduId */
        Com_TxPdu_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4, /* data ptr*/
        (PduLengthType)8, /* data length*/
        &ComTxModeTrue_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4,
        NULL_PTR,
        FALSE,/* cancel support */
        (uint8)0x0/* unusedByte */
    },
    {
        (uint16)0,/* mdt */
        (Com_SignalIdType)51,/* start sig index */
        (Com_SignalIdType)59,/* stop sig index */
        TRUE,/* group flag */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_IpduGroupPtr[0],/* pduGroupPtr */
        PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB,/* txpduId */
        Com_TxPdu_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB, /* data ptr*/
        (PduLengthType)8, /* data length*/
        &ComTxModeTrue_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB,
        NULL_PTR,
        FALSE,/* cancel support */
        (uint8)0x0/* unusedByte */
    },
    {
        (uint16)0,/* mdt */
        (Com_SignalIdType)60,/* start sig index */
        (Com_SignalIdType)65,/* stop sig index */
        TRUE,/* group flag */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_IpduGroupPtr[0],/* pduGroupPtr */
        PduR_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED,/* txpduId */
        Com_TxPdu_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED, /* data ptr*/
        (PduLengthType)8, /* data length*/
        &ComTxModeTrue_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED,
        NULL_PTR,
        FALSE,/* cancel support */
        (uint8)0x0/* unusedByte */
    },
};

#define COM_STOP_SEC_CONFIG_DATA
#include "Com_MemMap.h"



/*******************************************************************************
*   Rx IPDU & Signal Buffer
*******************************************************************************/

#define COM_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "Com_MemMap.h"

VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0[8];


STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1;
STATIC VAR(uint16, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd5;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd5;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd5;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd6;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd7;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd8;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd6;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd6;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd7;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd7;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd8;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd8;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd9;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd9;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd9;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd10;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd10;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd10;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat1_pct;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat2_pct;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat3_pct;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat4_pct;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat5_pct;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat6_pct;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve1Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve2Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve3Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve4Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve5Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve6Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve7Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve8Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve9Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve10Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve11Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve12Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat1Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat2Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat3Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat4Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat5Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat6Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat7Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat8Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat9Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat10Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat11Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat12Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarTopValue1Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarMidValue2Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarBottomValue3Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBLCmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBRCmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue6Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue5Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue4Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvPumpCmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueLCmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueMCmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue2Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueRCmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue3Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue1Cmd;
STATIC VAR(uint16, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR;
STATIC VAR(uint32, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Yr;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Mth;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Day;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Hr;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Min;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Sec;
STATIC VAR(uint16, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_MSec;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr;
STATIC VAR(uint64, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload;



VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC[8];
VAR(uint8, COM_VAR_NOINIT) Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0[8];


STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1;
STATIC VAR(uint16, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd5;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd5;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd5;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd6;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd7;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd8;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd6;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd6;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd7;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd7;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd8;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd8;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd9;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd9;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd10;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd10;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd9;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd10;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat1_pct;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat2_pct;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat3_pct;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat4_pct;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat5_pct;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat6_pct;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve1Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve2Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve3Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve4Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve5Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve6Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve7Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve8Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve9Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve10Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve11Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve12Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat1Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat2Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat3Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat4Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat5Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat6Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat7Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat8Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat9Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat10Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat11Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat12Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarTopValue1Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarMidValue2Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarBottomValue3Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBLCmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBRCmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue6Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue5Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue4Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassPumpCmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueLCmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueMCmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueRCmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue2Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue3Cmd;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue1Cmd;
STATIC VAR(uint16, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR;
STATIC VAR(uint32, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Yr;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Mth;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Day;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Hr;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Min;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Sec;
STATIC VAR(uint16, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_MSec;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC;
STATIC VAR(uint8, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr;
STATIC VAR(uint64, COM_VAR_NOINIT) Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload;




#define COM_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "Com_MemMap.h"



#define COM_START_SEC_CONFIG_DATA
#include "Com_MemMap.h"



/*******************************************************************************
*   for Rx Message and Signals
*******************************************************************************/




/*******************************************************************************
*   Rx Init value, Invalid, Filter parameters 

*******************************************************************************/
/********* Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1*********/
STATIC CONST(uint16, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1= (uint16)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd5*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd5= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd5*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd5= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd5*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd5= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd6*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd6= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd7*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd7= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd8*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd8= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd6*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd6= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd6*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd6= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd7*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd7= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd7*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd7= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd8*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd8= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd8*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd8= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd9*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd9= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd9*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd9= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd9*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd9= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd10*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd10= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd10*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd10= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd10*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd10= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat1_pct*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat1_pct= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat2_pct*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat2_pct= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat3_pct*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat3_pct= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat4_pct*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat4_pct= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat5_pct*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat5_pct= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat6_pct*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat6_pct= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve1Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve1Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve2Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve2Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve3Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve3Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve4Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve4Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve5Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve5Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve6Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve6Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve7Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve7Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve8Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve8Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve9Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve9Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve10Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve10Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve11Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve11Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve12Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve12Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat1Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat1Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat2Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat2Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat3Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat3Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat4Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat4Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat5Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat5Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat6Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat6Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat7Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat7Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat8Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat8Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat9Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat9Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat10Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat10Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat11Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat11Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat12Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat12Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarTopValue1Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarTopValue1Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarMidValue2Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarMidValue2Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarBottomValue3Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarBottomValue3Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBLCmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBLCmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBRCmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBRCmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue6Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue6Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue5Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue5Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue4Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue4Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvPumpCmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvPumpCmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueLCmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueLCmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueMCmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueMCmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue2Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue2Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueRCmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueRCmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue3Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue3Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue1Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue1Cmd= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR*********/
STATIC CONST(uint16, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR= (uint16)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer*********/
STATIC CONST(uint32, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer= (uint32)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Yr*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Yr= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Mth*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Mth= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Day*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Day= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Hr*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Hr= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Min*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Min= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Sec*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Sec= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_MSec*********/
STATIC CONST(uint16, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_MSec= (uint16)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr= (uint8)0;
/********* Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload*********/
STATIC CONST(uint64, COM_CONST) Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload= (uint64)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1*********/
STATIC CONST(uint16, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1= (uint16)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd5*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd5= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd5*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd5= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd5*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd5= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd6*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd6= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd7*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd7= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd8*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd8= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd6*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd6= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd6*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd6= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd7*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd7= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd7*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd7= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd8*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd8= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd8*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd8= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd9*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd9= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd9*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd9= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd10*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd10= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd10*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd10= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd9*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd9= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd10*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd10= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat1_pct*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat1_pct= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat2_pct*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat2_pct= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat3_pct*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat3_pct= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat4_pct*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat4_pct= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat5_pct*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat5_pct= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat6_pct*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat6_pct= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve1Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve1Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve2Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve2Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve3Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve3Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve4Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve4Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve5Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve5Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve6Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve6Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve7Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve7Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve8Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve8Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve9Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve9Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve10Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve10Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve11Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve11Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve12Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve12Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat1Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat1Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat2Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat2Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat3Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat3Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat4Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat4Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat5Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat5Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat6Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat6Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat7Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat7Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat8Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat8Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat9Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat9Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat10Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat10Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat11Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat11Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat12Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat12Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarTopValue1Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarTopValue1Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarMidValue2Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarMidValue2Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarBottomValue3Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarBottomValue3Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBLCmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBLCmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBRCmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBRCmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue6Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue6Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue5Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue5Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue4Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue4Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassPumpCmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassPumpCmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueLCmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueLCmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueMCmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueMCmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueRCmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueRCmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue2Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue2Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue3Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue3Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue1Cmd*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue1Cmd= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR*********/
STATIC CONST(uint16, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR= (uint16)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer*********/
STATIC CONST(uint32, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer= (uint32)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Yr*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Yr= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Mth*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Mth= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Day*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Day= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Hr*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Hr= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Min*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Min= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Sec*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Sec= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_MSec*********/
STATIC CONST(uint16, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_MSec= (uint16)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr*********/
STATIC CONST(uint8, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr= (uint8)0;
/********* Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload*********/
STATIC CONST(uint64, COM_CONST) Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload= (uint64)0;
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};
STATIC CONST(Com_IpduGroupIdType, COM_CONST) Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_IpduGroupPtr[1] = 
{
    (Com_IpduGroupIdType)1
};


/*******************************************************************************
*   Rx Com Timeout Substitution Value 

*******************************************************************************/


CONST(Com_CfgRxPduTableType, COM_CONST) ComRxPduCfgTable0[11] =
{
    {
        (Com_SignalIdType)0,/* start sig index */
        (Com_SignalIdType)1,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_IpduGroupPtr[0],/* pduGroupPtr */
        FALSE,/* timeout enable */
        (uint16)0,/* first timeout */
        (uint16)0,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)2,/* start sig index */
        (Com_SignalIdType)10,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_IpduGroupPtr[0],/* pduGroupPtr */
        TRUE,/* timeout enable */
        (uint16)50,/* first timeout */
        (uint16)50,/* timeout */
        &Com_CbkRxPduTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)11,/* start sig index */
        (Com_SignalIdType)28,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_IpduGroupPtr[0],/* pduGroupPtr */
        FALSE,/* timeout enable */
        (uint16)0,/* first timeout */
        (uint16)0,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)29,/* start sig index */
        (Com_SignalIdType)34,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_IpduGroupPtr[0],/* pduGroupPtr */
        FALSE,/* timeout enable */
        (uint16)0,/* first timeout */
        (uint16)0,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)35,/* start sig index */
        (Com_SignalIdType)66,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_IpduGroupPtr[0],/* pduGroupPtr */
        TRUE,/* timeout enable */
        (uint16)50,/* first timeout */
        (uint16)50,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)67,/* start sig index */
        (Com_SignalIdType)73,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_IpduGroupPtr[0],/* pduGroupPtr */
        TRUE,/* timeout enable */
        (uint16)50,/* first timeout */
        (uint16)50,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)74,/* start sig index */
        (Com_SignalIdType)74,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF_IpduGroupPtr[0],/* pduGroupPtr */
        FALSE,/* timeout enable */
        (uint16)0,/* first timeout */
        (uint16)0,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)75,/* start sig index */
        (Com_SignalIdType)75,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_IpduGroupPtr[0],/* pduGroupPtr */
        TRUE,/* timeout enable */
        (uint16)50,/* first timeout */
        (uint16)50,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)76,/* start sig index */
        (Com_SignalIdType)82,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_IpduGroupPtr[0],/* pduGroupPtr */
        TRUE,/* timeout enable */
        (uint16)50,/* first timeout */
        (uint16)50,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)83,/* start sig index */
        (Com_SignalIdType)131,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_IpduGroupPtr[0],/* pduGroupPtr */
        FALSE,/* timeout enable */
        (uint16)0,/* first timeout */
        (uint16)0,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)132,/* start sig index */
        (Com_SignalIdType)134,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_IpduGroupPtr[0],/* pduGroupPtr */
        FALSE,/* timeout enable */
        (uint16)0,/* first timeout */
        (uint16)0,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
};
CONST(Com_CfgRxPduTableType, COM_CONST) ComRxPduCfgTable1[11] =
{
    {
        (Com_SignalIdType)0,/* start sig index */
        (Com_SignalIdType)1,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_IpduGroupPtr[0],/* pduGroupPtr */
        FALSE,/* timeout enable */
        (uint16)0,/* first timeout */
        (uint16)0,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)2,/* start sig index */
        (Com_SignalIdType)10,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_IpduGroupPtr[0],/* pduGroupPtr */
        TRUE,/* timeout enable */
        (uint16)50,/* first timeout */
        (uint16)50,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)11,/* start sig index */
        (Com_SignalIdType)28,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_IpduGroupPtr[0],/* pduGroupPtr */
        FALSE,/* timeout enable */
        (uint16)0,/* first timeout */
        (uint16)0,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)29,/* start sig index */
        (Com_SignalIdType)34,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_IpduGroupPtr[0],/* pduGroupPtr */
        FALSE,/* timeout enable */
        (uint16)0,/* first timeout */
        (uint16)0,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)35,/* start sig index */
        (Com_SignalIdType)66,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_IpduGroupPtr[0],/* pduGroupPtr */
        TRUE,/* timeout enable */
        (uint16)50,/* first timeout */
        (uint16)50,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)67,/* start sig index */
        (Com_SignalIdType)73,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_IpduGroupPtr[0],/* pduGroupPtr */
        TRUE,/* timeout enable */
        (uint16)50,/* first timeout */
        (uint16)50,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)74,/* start sig index */
        (Com_SignalIdType)74,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF_IpduGroupPtr[0],/* pduGroupPtr */
        FALSE,/* timeout enable */
        (uint16)0,/* first timeout */
        (uint16)0,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)75,/* start sig index */
        (Com_SignalIdType)75,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_IpduGroupPtr[0],/* pduGroupPtr */
        TRUE,/* timeout enable */
        (uint16)50,/* first timeout */
        (uint16)50,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)76,/* start sig index */
        (Com_SignalIdType)82,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_IpduGroupPtr[0],/* pduGroupPtr */
        TRUE,/* timeout enable */
        (uint16)50,/* first timeout */
        (uint16)50,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)83,/* start sig index */
        (Com_SignalIdType)131,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_IpduGroupPtr[0],/* pduGroupPtr */
        FALSE,/* timeout enable */
        (uint16)0,/* first timeout */
        (uint16)0,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
    {
        (Com_SignalIdType)132,/* start sig index */
        (Com_SignalIdType)134,/* stop sig index */
        TRUE,/* group index */
        (Com_IpduGroupIdType)1,
        &Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_IpduGroupPtr[0],/* pduGroupPtr */
        FALSE,/* timeout enable */
        (uint16)0,/* first timeout */
        (uint16)0,/* timeout */
        NULL_PTR, /* RxPduCbkRxTOutFun */
        Com_RxPduSignal_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0, /* data ptr*/
        (PduLengthType)8 /* data length*/
    },
};
CONST(Com_CfgRxSigTableType, COM_CONST) ComRxSigCfgTable0[135] =
{
    /*Pdu0, Signal 0*/
    {
        (PduIdType)0,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)29,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu0, Signal 1*/
    {
        (PduIdType)0,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1,/* RxSigShareBufPtr */
        COM_SIG_U16,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)13,/* BitSize */
        (uint16)32,/* StartBit */
        (uint64)0x1fff,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu1, Signal 2*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)0,/* StartBit */
        (uint64)0xff,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC,/* rx timeout function */
    },
    /*Pdu1, Signal 3*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)8,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr,/* rx timeout function */
    },
    /*Pdu1, Signal 4*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)12,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts,/* rx timeout function */
    },
    /*Pdu1, Signal 5*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)13,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts,/* rx timeout function */
    },
    /*Pdu1, Signal 6*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)14,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts,/* rx timeout function */
    },
    /*Pdu1, Signal 7*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)3,/* BitSize */
        (uint16)16,/* StartBit */
        (uint64)0x7,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState,/* rx timeout function */
    },
    /*Pdu1, Signal 8*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)3,/* BitSize */
        (uint16)19,/* StartBit */
        (uint64)0x7,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState,/* rx timeout function */
    },
    /*Pdu1, Signal 9*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)24,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed,/* rx timeout function */
    },
    /*Pdu1, Signal 10*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)28,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef,/* rx timeout function */
    },
    /*Pdu2, Signal 11*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd5,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd5,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)0,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd5,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 12*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd5,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd5,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)4,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd5,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 13*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd5,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd5,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)8,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd5,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 14*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd6,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd6,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)10,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd6,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 15*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd7,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd7,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)12,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd7,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 16*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd8,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd8,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)14,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd8,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 17*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd6,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd6,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)16,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd6,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 18*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd6,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd6,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)20,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd6,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 19*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd7,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd7,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)24,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd7,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 20*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd7,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd7,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)28,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd7,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 21*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd8,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd8,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)32,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd8,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 22*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd8,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd8,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)36,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd8,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 23*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd9,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd9,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)40,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd9,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 24*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd9,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd9,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)44,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd9,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 25*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd9,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd9,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)48,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd9,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 26*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd10,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd10,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)50,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd10,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 27*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd10,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd10,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)52,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd10,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 28*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd10,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd10,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)56,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd10,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu3, Signal 29*/
    {
        (PduIdType)3,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat1_pct,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat1_pct,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)7,/* BitSize */
        (uint16)16,/* StartBit */
        (uint64)0x7f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat1_pct,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu3, Signal 30*/
    {
        (PduIdType)3,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat2_pct,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat2_pct,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)7,/* BitSize */
        (uint16)24,/* StartBit */
        (uint64)0x7f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat2_pct,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu3, Signal 31*/
    {
        (PduIdType)3,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat3_pct,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat3_pct,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)7,/* BitSize */
        (uint16)32,/* StartBit */
        (uint64)0x7f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat3_pct,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu3, Signal 32*/
    {
        (PduIdType)3,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat4_pct,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat4_pct,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)7,/* BitSize */
        (uint16)40,/* StartBit */
        (uint64)0x7f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat4_pct,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu3, Signal 33*/
    {
        (PduIdType)3,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat5_pct,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat5_pct,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)7,/* BitSize */
        (uint16)48,/* StartBit */
        (uint64)0x7f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat5_pct,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu3, Signal 34*/
    {
        (PduIdType)3,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat6_pct,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat6_pct,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)7,/* BitSize */
        (uint16)56,/* StartBit */
        (uint64)0x7f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat6_pct,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu4, Signal 35*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve1Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve1Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)0,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve1Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve1Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 36*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve2Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve2Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)2,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve2Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve2Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 37*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve3Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve3Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)4,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve3Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve3Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 38*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve4Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve4Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)6,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve4Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve4Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 39*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve5Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve5Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)8,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve5Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve5Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 40*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve6Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve6Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)10,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve6Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve6Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 41*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve7Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve7Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)12,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve7Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve7Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 42*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve8Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve8Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)14,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve8Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve8Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 43*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve9Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve9Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)16,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve9Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve9Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 44*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve10Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve10Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)18,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve10Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve10Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 45*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve11Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve11Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)20,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve11Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve11Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 46*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve12Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve12Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)22,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve12Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve12Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 47*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat1Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat1Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)24,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat1Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat1Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 48*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat2Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat2Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)26,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat2Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat2Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 49*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat3Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat3Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)28,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat3Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat3Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 50*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat4Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat4Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)30,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat4Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat4Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 51*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat5Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat5Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)32,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat5Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat5Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 52*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat6Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat6Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)34,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat6Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat6Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 53*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat7Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat7Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)36,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat7Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat7Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 54*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat8Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat8Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)38,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat8Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat8Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 55*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat9Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat9Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)40,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat9Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat9Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 56*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat10Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat10Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)42,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat10Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat10Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 57*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat11Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat11Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)44,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat11Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat11Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 58*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat12Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat12Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)46,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat12Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat12Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 59*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarTopValue1Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarTopValue1Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)48,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarTopValue1Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarTopValue1Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 60*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarMidValue2Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarMidValue2Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)50,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarMidValue2Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarMidValue2Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 61*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarBottomValue3Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarBottomValue3Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)52,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarBottomValue3Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarBottomValue3Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 62*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBLCmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBLCmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)54,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBLCmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBLCmd,/* rx timeout function */
    },
    /*Pdu4, Signal 63*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBRCmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBRCmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)56,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBRCmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBRCmd,/* rx timeout function */
    },
    /*Pdu4, Signal 64*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue6Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue6Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)58,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue6Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue6Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 65*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue5Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue5Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)60,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue5Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue5Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 66*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue4Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue4Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)62,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue4Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue4Cmd,/* rx timeout function */
    },
    /*Pdu5, Signal 67*/
    {
        (PduIdType)5,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvPumpCmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvPumpCmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)7,/* BitSize */
        (uint16)17,/* StartBit */
        (uint64)0x7f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvPumpCmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvPumpCmd,/* rx timeout function */
    },
    /*Pdu5, Signal 68*/
    {
        (PduIdType)5,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueLCmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueLCmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)24,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueLCmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueLCmd,/* rx timeout function */
    },
    /*Pdu5, Signal 69*/
    {
        (PduIdType)5,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueMCmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueMCmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)26,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueMCmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueMCmd,/* rx timeout function */
    },
    /*Pdu5, Signal 70*/
    {
        (PduIdType)5,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue2Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue2Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)28,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue2Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue2Cmd,/* rx timeout function */
    },
    /*Pdu5, Signal 71*/
    {
        (PduIdType)5,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueRCmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueRCmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)30,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueRCmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueRCmd,/* rx timeout function */
    },
    /*Pdu5, Signal 72*/
    {
        (PduIdType)5,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue3Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue3Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)36,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue3Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue3Cmd,/* rx timeout function */
    },
    /*Pdu5, Signal 73*/
    {
        (PduIdType)5,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue1Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue1Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)38,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue1Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue1Cmd,/* rx timeout function */
    },
    /*Pdu6, Signal 74*/
    {
        (PduIdType)6,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR,/* RxSigShareBufPtr */
        COM_SIG_U16,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)16,/* BitSize */
        (uint16)24,/* StartBit */
        (uint64)0xffff,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu7, Signal 75*/
    {
        (PduIdType)7,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer,/* RxSigShareBufPtr */
        COM_SIG_U32,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)24,/* BitSize */
        (uint16)16,/* StartBit */
        (uint64)0xffffff,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer,/* rx timeout function */
    },
    /*Pdu8, Signal 76*/
    {
        (PduIdType)8,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Yr,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Yr,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)0,/* StartBit */
        (uint64)0xff,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Yr,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Yr,/* rx timeout function */
    },
    /*Pdu8, Signal 77*/
    {
        (PduIdType)8,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Mth,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Mth,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)8,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Mth,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Mth,/* rx timeout function */
    },
    /*Pdu8, Signal 78*/
    {
        (PduIdType)8,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Day,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Day,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)5,/* BitSize */
        (uint16)16,/* StartBit */
        (uint64)0x1f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Day,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Day,/* rx timeout function */
    },
    /*Pdu8, Signal 79*/
    {
        (PduIdType)8,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Hr,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Hr,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)5,/* BitSize */
        (uint16)24,/* StartBit */
        (uint64)0x1f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Hr,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Hr,/* rx timeout function */
    },
    /*Pdu8, Signal 80*/
    {
        (PduIdType)8,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Min,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Min,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)6,/* BitSize */
        (uint16)32,/* StartBit */
        (uint64)0x3f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Min,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Min,/* rx timeout function */
    },
    /*Pdu8, Signal 81*/
    {
        (PduIdType)8,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Sec,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Sec,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)6,/* BitSize */
        (uint16)40,/* StartBit */
        (uint64)0x3f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Sec,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Sec,/* rx timeout function */
    },
    /*Pdu8, Signal 82*/
    {
        (PduIdType)8,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_MSec,/* RxSigShareBufPtr */
        COM_SIG_U16,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_MSec,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)10,/* BitSize */
        (uint16)56,/* StartBit */
        (uint64)0x3ff,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_MSec,/* rxAck function */
        &Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_MSec,/* rx timeout function */
    },
    /*Pdu9, Signal 83*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)15,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 84*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)16,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 85*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)17,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 86*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)18,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 87*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)19,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 88*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)20,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 89*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)21,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 90*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)22,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 91*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)23,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 92*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)24,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 93*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)25,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 94*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)26,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 95*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)27,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 96*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)28,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 97*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)29,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 98*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)30,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 99*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)31,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 100*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)32,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 101*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)33,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 102*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)34,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 103*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)35,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 104*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)36,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 105*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)37,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 106*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)38,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 107*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)39,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 108*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)40,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 109*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)41,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 110*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)42,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 111*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)43,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 112*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)44,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 113*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)45,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 114*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)46,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 115*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)47,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 116*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)48,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 117*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)49,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 118*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)50,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 119*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)51,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 120*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)52,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 121*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)53,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 122*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)54,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 123*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)55,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 124*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)56,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 125*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)57,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 126*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)58,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 127*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)59,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 128*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)60,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 129*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)61,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 130*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)62,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 131*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)63,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu10, Signal 132*/
    {
        (PduIdType)10,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)0,/* StartBit */
        (uint64)0xff,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu10, Signal 133*/
    {
        (PduIdType)10,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)8,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu10, Signal 134*/
    {
        (PduIdType)10,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload,/* RxSigShareBufPtr */
        COM_SIG_U64,/* signal type */
        &Com_InitVal_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)48,/* BitSize */
        (uint16)56,/* StartBit */
        (uint64)0xffffffffffff,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
};
CONST(Com_CfgRxSigTableType, COM_CONST) ComRxSigCfgTable1[135] =
{
    /*Pdu0, Signal 0*/
    {
        (PduIdType)0,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)29,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu0, Signal 1*/
    {
        (PduIdType)0,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1,/* RxSigShareBufPtr */
        COM_SIG_U16,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)13,/* BitSize */
        (uint16)32,/* StartBit */
        (uint64)0x1fff,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu1, Signal 2*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)0,/* StartBit */
        (uint64)0xff,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC,/* rx timeout function */
    },
    /*Pdu1, Signal 3*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)8,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr,/* rx timeout function */
    },
    /*Pdu1, Signal 4*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)12,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts,/* rx timeout function */
    },
    /*Pdu1, Signal 5*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)13,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts,/* rx timeout function */
    },
    /*Pdu1, Signal 6*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)14,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts,/* rx timeout function */
    },
    /*Pdu1, Signal 7*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)3,/* BitSize */
        (uint16)16,/* StartBit */
        (uint64)0x7,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState,/* rx timeout function */
    },
    /*Pdu1, Signal 8*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)3,/* BitSize */
        (uint16)19,/* StartBit */
        (uint64)0x7,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState,/* rx timeout function */
    },
    /*Pdu1, Signal 9*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)24,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed,/* rx timeout function */
    },
    /*Pdu1, Signal 10*/
    {
        (PduIdType)1,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)28,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef,/* rx timeout function */
    },
    /*Pdu2, Signal 11*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd5,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd5,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)0,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd5,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 12*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd5,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd5,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)4,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd5,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 13*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd5,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd5,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)8,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd5,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 14*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd6,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd6,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)10,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd6,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 15*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd7,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd7,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)12,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd7,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 16*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd8,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd8,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)14,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd8,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 17*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd6,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd6,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)16,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd6,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 18*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd6,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd6,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)20,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd6,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 19*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd7,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd7,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)24,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd7,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 20*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd7,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd7,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)28,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd7,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 21*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd8,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd8,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)32,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd8,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 22*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd8,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd8,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)36,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd8,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 23*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd9,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd9,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)40,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd9,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 24*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd9,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd9,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)44,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd9,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 25*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd10,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd10,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)48,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd10,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 26*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd10,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd10,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)52,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd10,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 27*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd9,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd9,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)56,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd9,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu2, Signal 28*/
    {
        (PduIdType)2,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd10,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd10,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)58,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd10,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu3, Signal 29*/
    {
        (PduIdType)3,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat1_pct,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat1_pct,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)7,/* BitSize */
        (uint16)16,/* StartBit */
        (uint64)0x7f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat1_pct,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu3, Signal 30*/
    {
        (PduIdType)3,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat2_pct,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat2_pct,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)7,/* BitSize */
        (uint16)24,/* StartBit */
        (uint64)0x7f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat2_pct,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu3, Signal 31*/
    {
        (PduIdType)3,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat3_pct,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat3_pct,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)7,/* BitSize */
        (uint16)32,/* StartBit */
        (uint64)0x7f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat3_pct,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu3, Signal 32*/
    {
        (PduIdType)3,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat4_pct,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat4_pct,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)7,/* BitSize */
        (uint16)40,/* StartBit */
        (uint64)0x7f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat4_pct,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu3, Signal 33*/
    {
        (PduIdType)3,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat5_pct,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat5_pct,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)7,/* BitSize */
        (uint16)48,/* StartBit */
        (uint64)0x7f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat5_pct,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu3, Signal 34*/
    {
        (PduIdType)3,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat6_pct,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat6_pct,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)7,/* BitSize */
        (uint16)56,/* StartBit */
        (uint64)0x7f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat6_pct,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu4, Signal 35*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve1Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve1Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)0,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve1Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve1Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 36*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve2Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve2Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)2,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve2Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve2Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 37*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve3Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve3Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)4,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve3Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve3Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 38*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve4Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve4Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)6,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve4Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve4Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 39*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve5Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve5Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)8,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve5Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve5Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 40*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve6Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve6Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)10,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve6Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve6Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 41*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve7Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve7Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)12,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve7Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve7Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 42*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve8Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve8Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)14,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve8Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve8Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 43*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve9Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve9Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)16,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve9Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve9Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 44*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve10Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve10Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)18,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve10Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve10Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 45*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve11Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve11Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)20,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve11Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve11Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 46*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve12Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve12Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)22,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve12Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve12Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 47*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat1Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat1Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)24,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat1Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat1Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 48*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat2Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat2Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)26,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat2Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat2Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 49*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat3Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat3Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)28,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat3Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat3Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 50*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat4Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat4Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)30,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat4Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat4Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 51*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat5Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat5Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)32,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat5Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat5Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 52*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat6Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat6Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)34,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat6Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat6Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 53*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat7Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat7Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)36,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat7Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat7Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 54*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat8Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat8Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)38,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat8Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat8Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 55*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat9Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat9Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)40,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat9Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat9Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 56*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat10Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat10Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)42,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat10Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat10Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 57*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat11Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat11Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)44,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat11Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat11Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 58*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat12Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat12Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)46,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat12Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat12Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 59*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarTopValue1Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarTopValue1Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)48,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarTopValue1Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarTopValue1Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 60*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarMidValue2Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarMidValue2Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)50,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarMidValue2Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarMidValue2Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 61*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarBottomValue3Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarBottomValue3Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)52,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarBottomValue3Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarBottomValue3Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 62*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBLCmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBLCmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)54,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBLCmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBLCmd,/* rx timeout function */
    },
    /*Pdu4, Signal 63*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBRCmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBRCmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)56,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBRCmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBRCmd,/* rx timeout function */
    },
    /*Pdu4, Signal 64*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue6Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue6Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)58,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue6Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue6Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 65*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue5Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue5Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)60,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue5Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue5Cmd,/* rx timeout function */
    },
    /*Pdu4, Signal 66*/
    {
        (PduIdType)4,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue4Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue4Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)62,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue4Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue4Cmd,/* rx timeout function */
    },
    /*Pdu5, Signal 67*/
    {
        (PduIdType)5,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassPumpCmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassPumpCmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)7,/* BitSize */
        (uint16)17,/* StartBit */
        (uint64)0x7f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassPumpCmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassPumpCmd,/* rx timeout function */
    },
    /*Pdu5, Signal 68*/
    {
        (PduIdType)5,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueLCmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueLCmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)24,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueLCmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueLCmd,/* rx timeout function */
    },
    /*Pdu5, Signal 69*/
    {
        (PduIdType)5,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueMCmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueMCmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)26,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueMCmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueMCmd,/* rx timeout function */
    },
    /*Pdu5, Signal 70*/
    {
        (PduIdType)5,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueRCmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueRCmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)28,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueRCmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueRCmd,/* rx timeout function */
    },
    /*Pdu5, Signal 71*/
    {
        (PduIdType)5,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue2Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue2Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)30,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue2Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue2Cmd,/* rx timeout function */
    },
    /*Pdu5, Signal 72*/
    {
        (PduIdType)5,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue3Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue3Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)36,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue3Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue3Cmd,/* rx timeout function */
    },
    /*Pdu5, Signal 73*/
    {
        (PduIdType)5,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue1Cmd,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue1Cmd,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)2,/* BitSize */
        (uint16)38,/* StartBit */
        (uint64)0x3,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue1Cmd,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue1Cmd,/* rx timeout function */
    },
    /*Pdu6, Signal 74*/
    {
        (PduIdType)6,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR,/* RxSigShareBufPtr */
        COM_SIG_U16,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)16,/* BitSize */
        (uint16)24,/* StartBit */
        (uint64)0xffff,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu7, Signal 75*/
    {
        (PduIdType)7,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer,/* RxSigShareBufPtr */
        COM_SIG_U32,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)24,/* BitSize */
        (uint16)16,/* StartBit */
        (uint64)0xffffff,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer,/* rx timeout function */
    },
    /*Pdu8, Signal 76*/
    {
        (PduIdType)8,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Yr,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Yr,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)0,/* StartBit */
        (uint64)0xff,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Yr,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Yr,/* rx timeout function */
    },
    /*Pdu8, Signal 77*/
    {
        (PduIdType)8,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Mth,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Mth,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)8,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Mth,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Mth,/* rx timeout function */
    },
    /*Pdu8, Signal 78*/
    {
        (PduIdType)8,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Day,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Day,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)5,/* BitSize */
        (uint16)16,/* StartBit */
        (uint64)0x1f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Day,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Day,/* rx timeout function */
    },
    /*Pdu8, Signal 79*/
    {
        (PduIdType)8,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Hr,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Hr,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)5,/* BitSize */
        (uint16)24,/* StartBit */
        (uint64)0x1f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Hr,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Hr,/* rx timeout function */
    },
    /*Pdu8, Signal 80*/
    {
        (PduIdType)8,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Min,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Min,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)6,/* BitSize */
        (uint16)32,/* StartBit */
        (uint64)0x3f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Min,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Min,/* rx timeout function */
    },
    /*Pdu8, Signal 81*/
    {
        (PduIdType)8,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Sec,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Sec,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)6,/* BitSize */
        (uint16)40,/* StartBit */
        (uint64)0x3f,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Sec,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Sec,/* rx timeout function */
    },
    /*Pdu8, Signal 82*/
    {
        (PduIdType)8,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_MSec,/* RxSigShareBufPtr */
        COM_SIG_U16,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_MSec,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)10,/* BitSize */
        (uint16)56,/* StartBit */
        (uint64)0x3ff,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_MSec,/* rxAck function */
        &Com_CbkRxTOut_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_MSec,/* rx timeout function */
    },
    /*Pdu9, Signal 83*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)15,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 84*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)16,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 85*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)17,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 86*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)18,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 87*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)19,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 88*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)20,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 89*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)21,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 90*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)22,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 91*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)23,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 92*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)24,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 93*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)25,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 94*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)26,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 95*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)27,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 96*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)28,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 97*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)29,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 98*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)30,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 99*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)31,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 100*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)32,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 101*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)33,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 102*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)34,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 103*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)35,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 104*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)36,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 105*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)37,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 106*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)38,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 107*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)39,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 108*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)40,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 109*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)41,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 110*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)42,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 111*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)43,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 112*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)44,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 113*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)45,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 114*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)46,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 115*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)47,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 116*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)48,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 117*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)49,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 118*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)50,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 119*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)51,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 120*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)52,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 121*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)53,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 122*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)54,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 123*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)55,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 124*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)56,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 125*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)57,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 126*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)58,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 127*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)59,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 128*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)60,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 129*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)61,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 130*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)62,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu9, Signal 131*/
    {
        (PduIdType)9,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)1,/* BitSize */
        (uint16)63,/* StartBit */
        (uint64)0x1,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu10, Signal 132*/
    {
        (PduIdType)10,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)8,/* BitSize */
        (uint16)0,/* StartBit */
        (uint64)0xff,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu10, Signal 133*/
    {
        (PduIdType)10,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr,/* RxSigShareBufPtr */
        COM_SIG_U8,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)4,/* BitSize */
        (uint16)8,/* StartBit */
        (uint64)0xf,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
    /*Pdu10, Signal 134*/
    {
        (PduIdType)10,/* rxpduid */
        &Com_RxSigShareBuf_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload,/* RxSigShareBufPtr */
        COM_SIG_U64,/* signal type */
        &Com_InitVal_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload,/* signal init value */
        (PduLengthType)0,/* start byte of signal, for dyn only*/
        (PduLengthType)0,/* signal length in  byte, only for u8n dyn */
        COM_BIG_ENDIAN,/* Endianness */
        (uint16)48,/* BitSize */
        (uint16)56,/* StartBit */
        (uint64)0xffffffffffff,/* Mask */
        COM_RX_TIMEOUT_NONE, /* timeout action */
        &Com_CbkRxAck_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload,/* rxAck function */
        NULL_PTR,/* rx timeout function */
    },
};


/*******************************************************************************
*   IPDUGroup
*******************************************************************************/
STATIC CONST(PduIdType, COM_CONST) Com_Tx_Cfg_D_BODY_LE1_CANTx[6] =
{
    (PduIdType)0, (PduIdType)1, (PduIdType)2, (PduIdType)3, (PduIdType)4, (PduIdType)5
};

STATIC CONST(PduIdType, COM_CONST) Com_Rx_Cfg_D_BODY_LE1_CANRx[11] =
{
    (PduIdType)0, (PduIdType)1, (PduIdType)2, (PduIdType)3, (PduIdType)4, (PduIdType)5, (PduIdType)6, (PduIdType)7, (PduIdType)8, (PduIdType)9, (PduIdType)10
};

CONST(Com_CfgPduGroupTableType, COM_CONST) ComPduGroupCfgTable0[2] =
{
    {
        Com_Tx_Cfg_D_BODY_LE1_CANTx,
        (PduIdType)6,
        NULL_PTR,
        (PduIdType)0
    },
    {
        NULL_PTR,
        (PduIdType)0,
        Com_Rx_Cfg_D_BODY_LE1_CANRx,
        (PduIdType)11
    }
};
STATIC CONST(PduIdType, COM_CONST) Com_Tx_Cfg_P_BODY_LE1_CANTx[6] =
{
    (PduIdType)0, (PduIdType)1, (PduIdType)2, (PduIdType)3, (PduIdType)4, (PduIdType)5
};

STATIC CONST(PduIdType, COM_CONST) Com_Rx_Cfg_P_BODY_LE1_CANRx[11] =
{
    (PduIdType)0, (PduIdType)1, (PduIdType)2, (PduIdType)3, (PduIdType)4, (PduIdType)5, (PduIdType)6, (PduIdType)7, (PduIdType)8, (PduIdType)9, (PduIdType)10
};

CONST(Com_CfgPduGroupTableType, COM_CONST) ComPduGroupCfgTable1[2] =
{
    {
        Com_Tx_Cfg_P_BODY_LE1_CANTx,
        (PduIdType)6,
        NULL_PTR,
        (PduIdType)0
    },
    {
        NULL_PTR,
        (PduIdType)0,
        Com_Rx_Cfg_P_BODY_LE1_CANRx,
        (PduIdType)11
    }
};



/*******************************************************************************
*   rx signal group 
*******************************************************************************/


/*******************************************************************************
*   tx signal group 
*******************************************************************************/


/*******************************************************************************
*   signal gateway
*******************************************************************************/


/*******************************************************************************
*   main function
*******************************************************************************/

#define COM_STOP_SEC_CONFIG_DATA
#include "Com_MemMap.h"


