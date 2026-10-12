/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : BswM_PBcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : BswM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : BswM module configuration File
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


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "BswM_PBcfg.h"
#include "BswM_Lcfg.h"
#include "Rte_BswM.h"
#include "SchM_BswM.h"
#include "Rte_Main.h"


#include "Com.h"
#include "ComM.h"
#include "Dcm.h"
#include "CanSM.h"

/*******************************************************************************
*   Macro
*******************************************************************************/
/*RuleExpressionIndex*/
#define BSWM_RULE_BswM_RuleInitBlockII_Core0_PB0            (0)
#define BSWM_RULE_BswM_RuleWkupToReadNvM_Core0_PB0          (1)
#define BSWM_RULE_BswM_RuleReadNvMToRun_Core0_PB0           (2)
#define BSWM_RULE_BswM_RuleRunToPostRun_Core0_PB0           (3)
#define BSWM_RULE_BswM_RulePostRunToRun_Core0_PB0           (4)
#define BSWM_RULE_BswM_RulePostRunToPrep_Core0_PB0          (5)
#define BSWM_RULE_BswM_RuleRunToPrep_Core0_PB0              (6)
#define BSWM_RULE_BswM_RulePrepToRun_Core0_PB0              (7)
#define BSWM_RULE_BswM_RulePrepToWriteNvM_Core0_PB0         (8)
#define BSWM_RULE_BswM_RuleWriteNvMToRun_Core0_PB0          (9)
#define BSWM_RULE_BswM_RuleWriteNvMToSleep_Core0_PB0        (10)
#define BSWM_RULE_BswM_RuleWkupToSleep_Core0_PB0            (11)
#define BSWM_RULE_BswM_RuleBODY_LE1_CANTxOn_PB0             (12)
#define BSWM_RULE_BswM_RuleBODY_LE1_CANTxOff_PB0            (13)
#define BSWM_RULE_BswM_RuleBODY_LE1_CANRxOn_PB0             (14)
#define BSWM_RULE_BswM_RuleBODY_LE1_CANRxOff_PB0            (15)
#define BSWM_RULE_BswM_RuleInitBlockII_Core0_PB1            (0)
#define BSWM_RULE_BswM_RuleWkupToReadNvM_Core0_PB1          (1)
#define BSWM_RULE_BswM_RuleReadNvMToRun_Core0_PB1           (2)
#define BSWM_RULE_BswM_RuleRunToPostRun_Core0_PB1           (3)
#define BSWM_RULE_BswM_RulePostRunToRun_Core0_PB1           (4)
#define BSWM_RULE_BswM_RulePostRunToPrep_Core0_PB1          (5)
#define BSWM_RULE_BswM_RuleRunToPrep_Core0_PB1              (6)
#define BSWM_RULE_BswM_RulePrepToRun_Core0_PB1              (7)
#define BSWM_RULE_BswM_RulePrepToWriteNvM_Core0_PB1         (8)
#define BSWM_RULE_BswM_RuleWriteNvMToRun_Core0_PB1          (9)
#define BSWM_RULE_BswM_RuleWriteNvMToSleep_Core0_PB1        (10)
#define BSWM_RULE_BswM_RuleWkupToSleep_Core0_PB1            (11)
#define BSWM_RULE_BswM_RuleBODY_LE1_CANTxOn_PB1             (12)
#define BSWM_RULE_BswM_RuleBODY_LE1_CANTxOff_PB1            (13)
#define BSWM_RULE_BswM_RuleBODY_LE1_CANRxOn_PB1             (14)
#define BSWM_RULE_BswM_RuleBODY_LE1_CANRxOff_PB1            (15)
/*BswMActionListIndex*/
#define BSWM_ACTIONLIST_BswM_ALInitBlockII_Core0_PB0        ((BswMActionListIdType)0)
#define BSWM_ACTIONLIST_BswM_ALWkupToReadNvM_Core0_PB0      ((BswMActionListIdType)1)
#define BSWM_ACTIONLIST_BswM_ALReadNvMToRun_Core0_PB0       ((BswMActionListIdType)2)
#define BSWM_ACTIONLIST_BswM_ALRunToPostRun_Core0_PB0       ((BswMActionListIdType)3)
#define BSWM_ACTIONLIST_BswM_ALPostRunToRun_Core0_PB0       ((BswMActionListIdType)4)
#define BSWM_ACTIONLIST_BswM_ALPrepToRun_Core0_PB0          ((BswMActionListIdType)5)
#define BSWM_ACTIONLIST_BswM_ALPostRunToPrep_Core0_PB0      ((BswMActionListIdType)6)
#define BSWM_ACTIONLIST_BswM_ALRunToPrep_Core0_PB0          ((BswMActionListIdType)7)
#define BSWM_ACTIONLIST_BswM_ALPrepToWriteNvM_Core0_PB0     ((BswMActionListIdType)8)
#define BSWM_ACTIONLIST_BswM_ALWriteNvMToSleep_Core0_PB0    ((BswMActionListIdType)9)
#define BSWM_ACTIONLIST_BswM_ALWkupToSleep_Core0_PB0        ((BswMActionListIdType)10)
#define BSWM_ACTIONLIST_BswM_ALBODY_LE1_CANTxOff_PB0        ((BswMActionListIdType)11)
#define BSWM_ACTIONLIST_BswM_ALBODY_LE1_CANTxOn_PB0         ((BswMActionListIdType)12)
#define BSWM_ACTIONLIST_BswM_ALBODY_LE1_CANRxOff_PB0        ((BswMActionListIdType)13)
#define BSWM_ACTIONLIST_BswM_ALBODY_LE1_CANRxOn_PB0         ((BswMActionListIdType)14)
#define BSWM_ACTIONLIST_BswM_ALInitBlockII_Core0_PB1        ((BswMActionListIdType)0)
#define BSWM_ACTIONLIST_BswM_ALWkupToReadNvM_Core0_PB1      ((BswMActionListIdType)1)
#define BSWM_ACTIONLIST_BswM_ALReadNvMToRun_Core0_PB1       ((BswMActionListIdType)2)
#define BSWM_ACTIONLIST_BswM_ALRunToPostRun_Core0_PB1       ((BswMActionListIdType)3)
#define BSWM_ACTIONLIST_BswM_ALPostRunToRun_Core0_PB1       ((BswMActionListIdType)4)
#define BSWM_ACTIONLIST_BswM_ALPrepToRun_Core0_PB1          ((BswMActionListIdType)5)
#define BSWM_ACTIONLIST_BswM_ALPostRunToPrep_Core0_PB1      ((BswMActionListIdType)6)
#define BSWM_ACTIONLIST_BswM_ALRunToPrep_Core0_PB1          ((BswMActionListIdType)7)
#define BSWM_ACTIONLIST_BswM_ALPrepToWriteNvM_Core0_PB1     ((BswMActionListIdType)8)
#define BSWM_ACTIONLIST_BswM_ALWriteNvMToSleep_Core0_PB1    ((BswMActionListIdType)9)
#define BSWM_ACTIONLIST_BswM_ALWkupToSleep_Core0_PB1        ((BswMActionListIdType)10)
#define BSWM_ACTIONLIST_BswM_ALBODY_LE1_CANTxOff_PB1        ((BswMActionListIdType)11)
#define BSWM_ACTIONLIST_BswM_ALBODY_LE1_CANTxOn_PB1         ((BswMActionListIdType)12)
#define BSWM_ACTIONLIST_BswM_ALBODY_LE1_CANRxOff_PB1        ((BswMActionListIdType)13)
#define BSWM_ACTIONLIST_BswM_ALBODY_LE1_CANRxOn_PB1         ((BswMActionListIdType)14)
/*******************************************************************************
*   Global Vars
*******************************************************************************/

#define BSWM_START_SEC_CONFIG_DATA
#include "BswM_MemMap.h"

STATIC CONST(BswMRuleType, BSWM_CONST) BswMPortMappingRulesStart_PB0[BSWM_MAX_PORT_NUM] =
{
    (BswMRuleType)0,
    (BswMRuleType)10,
    (BswMRuleType)14,
    (BswMRuleType)18,
    (BswMRuleType)31,
    (BswMRuleType)32,
    (BswMRuleType)33,
    (BswMRuleType)45
};

STATIC CONST(BswMRuleType, BSWM_CONST) BswMPortMappingRulesNum_PB0[BSWM_MAX_PORT_NUM] =
{
    (BswMRuleType)10,
    (BswMRuleType)4,
    (BswMRuleType)4,
    (BswMRuleType)13,
    (BswMRuleType)1,
    (BswMRuleType)1,
    (BswMRuleType)12,
    (BswMRuleType)3
};

STATIC CONST(BswMRuleType, BSWM_CONST) BswMPortMappingRules_PB0[48] =
{
    (BswMRuleType)BSWM_RULE_BswM_RuleWkupToReadNvM_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleRunToPostRun_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RulePostRunToRun_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RulePostRunToPrep_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleRunToPrep_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RulePrepToRun_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RulePrepToWriteNvM_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleWriteNvMToRun_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleWriteNvMToSleep_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleWkupToSleep_Core0_PB0,

    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANTxOn_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANTxOff_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANRxOn_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANRxOff_PB0,

    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANTxOn_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANTxOff_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANRxOn_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANRxOff_PB0,

    (BswMRuleType)BSWM_RULE_BswM_RuleWkupToReadNvM_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleRunToPostRun_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RulePostRunToPrep_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleRunToPrep_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RulePrepToRun_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RulePrepToWriteNvM_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleWriteNvMToRun_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleWriteNvMToSleep_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleWkupToSleep_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANTxOn_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANTxOff_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANRxOn_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANRxOff_PB0,

    (BswMRuleType)BSWM_RULE_BswM_RuleReadNvMToRun_Core0_PB0,

    (BswMRuleType)BSWM_RULE_BswM_RuleWriteNvMToSleep_Core0_PB0,

    (BswMRuleType)BSWM_RULE_BswM_RuleInitBlockII_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleWkupToReadNvM_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleReadNvMToRun_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleRunToPostRun_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RulePostRunToRun_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RulePostRunToPrep_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleRunToPrep_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RulePrepToRun_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RulePrepToWriteNvM_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleWriteNvMToRun_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleWriteNvMToSleep_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleWkupToSleep_Core0_PB0,

    (BswMRuleType)BSWM_RULE_BswM_RuleRunToPostRun_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleRunToPrep_Core0_PB0,
    (BswMRuleType)BSWM_RULE_BswM_RuleWkupToSleep_Core0_PB0

};


STATIC CONST(BswMRuleType, BSWM_CONST) BswMPortMappingRulesStart_PB1[BSWM_MAX_PORT_NUM] =
{
    (BswMRuleType)0,
    (BswMRuleType)10,
    (BswMRuleType)14,
    (BswMRuleType)18,
    (BswMRuleType)31,
    (BswMRuleType)32,
    (BswMRuleType)33,
    (BswMRuleType)45
};

STATIC CONST(BswMRuleType, BSWM_CONST) BswMPortMappingRulesNum_PB1[BSWM_MAX_PORT_NUM] =
{
    (BswMRuleType)10,
    (BswMRuleType)4,
    (BswMRuleType)4,
    (BswMRuleType)13,
    (BswMRuleType)1,
    (BswMRuleType)1,
    (BswMRuleType)12,
    (BswMRuleType)3
};

STATIC CONST(BswMRuleType, BSWM_CONST) BswMPortMappingRules_PB1[48] =
{
    (BswMRuleType)BSWM_RULE_BswM_RuleWkupToReadNvM_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleRunToPostRun_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RulePostRunToRun_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RulePostRunToPrep_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleRunToPrep_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RulePrepToRun_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RulePrepToWriteNvM_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleWriteNvMToRun_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleWriteNvMToSleep_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleWkupToSleep_Core0_PB1,

    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANTxOn_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANTxOff_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANRxOn_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANRxOff_PB1,

    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANTxOn_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANTxOff_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANRxOn_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANRxOff_PB1,

    (BswMRuleType)BSWM_RULE_BswM_RuleWkupToReadNvM_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleRunToPostRun_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RulePostRunToPrep_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleRunToPrep_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RulePrepToRun_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RulePrepToWriteNvM_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleWriteNvMToRun_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleWriteNvMToSleep_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleWkupToSleep_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANTxOn_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANTxOff_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANRxOn_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleBODY_LE1_CANRxOff_PB1,

    (BswMRuleType)BSWM_RULE_BswM_RuleReadNvMToRun_Core0_PB1,

    (BswMRuleType)BSWM_RULE_BswM_RuleWriteNvMToSleep_Core0_PB1,

    (BswMRuleType)BSWM_RULE_BswM_RuleInitBlockII_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleWkupToReadNvM_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleReadNvMToRun_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleRunToPostRun_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RulePostRunToRun_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RulePostRunToPrep_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleRunToPrep_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RulePrepToRun_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RulePrepToWriteNvM_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleWriteNvMToRun_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleWriteNvMToSleep_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleWkupToSleep_Core0_PB1,

    (BswMRuleType)BSWM_RULE_BswM_RuleRunToPostRun_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleRunToPrep_Core0_PB1,
    (BswMRuleType)BSWM_RULE_BswM_RuleWkupToSleep_Core0_PB1

};


#define BSWM_STOP_SEC_CONFIG_DATA
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_INIT_GLOBAL_8
#include "BswM_MemMap.h"


#define BSWM_STOP_SEC_VAR_INIT_GLOBAL_8
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALInitBlockII_Core0TrueFunc0(void)
{
    BswM_InitBlockIICallout_Core0();

    BswM_SetTimer((uint8)0, (uint16)0);
    BswM_RequestMode(BswM_SysState_Core0, BSWM_GENERIC_MODE_WAKEUP);
    EcuM_SetState(ECUM_STATE_RUN);
    ComM_CommunicationAllowed(ComM_ComM_BODY_LE1_CAN, TRUE);
    BswM_StartBswTaskCallout_Core0();


    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALWkupToReadNvM_Core0TrueFunc0(void)
{
    BswM_StopTimer((uint8)0);
    BswM_RequestMode(BswM_SysState_Core0, BSWM_GENERIC_MODE_READ_NVM);
    BswM_NvMReadAllCallout_Core0();


    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALReadNvMToRun_Core0TrueFunc0(void)
{
    BswM_PostReadAllCallout_Core0();

    BswM_SetTimer((uint8)0, (uint16)10);
    BswM_RequestMode(BswM_SysState_Core0, BSWM_GENERIC_MODE_APP_RUN);
    EcuM_SetState(ECUM_STATE_APP_RUN);
    (void)Rte_Start();

    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALRunToPostRun_Core0TrueFunc0(void)
{
    BswM_RequestMode(BswM_SysState_Core0, BSWM_GENERIC_MODE_POST_RUN);
    EcuM_SetState(ECUM_STATE_APP_POST_RUN);

    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALPostRunToRun_Core0TrueFunc0(void)
{
    BswM_SetTimer((uint8)0, (uint16)10);
    EcuM_SetState(ECUM_STATE_APP_RUN);
    BswM_RequestMode(BswM_SysState_Core0, BSWM_GENERIC_MODE_APP_RUN);

    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALPrepToRun_Core0TrueFunc0(void)
{
    BswM_SetTimer((uint8)0, (uint16)10);
    EcuM_SetState(ECUM_STATE_APP_RUN);
    BswM_RequestMode(BswM_SysState_Core0, BSWM_GENERIC_MODE_APP_RUN);
    (void)Rte_Start();

    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALPostRunToPrep_Core0TrueFunc0(void)
{
    BswM_RequestMode(BswM_SysState_Core0, BSWM_GENERIC_MODE_PREP_SHUTDOWN);
    BswM_PreShutdownCallout_Core0();

    (void)Rte_Stop();

    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALRunToPrep_Core0TrueFunc0(void)
{
    BswM_RequestMode(BswM_SysState_Core0, BSWM_GENERIC_MODE_PREP_SHUTDOWN);
    BswM_PreShutdownCallout_Core0();

    (void)Rte_Stop();

    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALPrepToWriteNvM_Core0TrueFunc0(void)
{
    BswM_RequestMode(BswM_SysState_Core0, BSWM_GENERIC_MODE_WRITE_NVM);
    BswM_NvMWriteAllCallout_Core0();


    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALWriteNvMToSleep_Core0TrueFunc0(void)
{
    EcuM_SetState(ECUM_STATE_SLEEP);
    BswM_RequestMode(BswM_SysState_Core0, BSWM_GENERIC_MODE_SLEEP);
    BswM_ClearWakeupEventCallout_Core0();

    BswM_WriteNvMToSleepCallout_Core0();


    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALWkupToSleep_Core0TrueFunc0(void)
{
    EcuM_SetState(ECUM_STATE_SLEEP);
    BswM_RequestMode(BswM_SysState_Core0, BSWM_GENERIC_MODE_SLEEP);
    BswM_ClearWakeupEventCallout_Core0();

    BswM_WakeupToSleepCallout_Core0();


    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALBODY_LE1_CANTxOffTrueFunc0(void)
{
    Com_IpduGroupStop(Com_BODY_LE1_CANTx);


    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALBODY_LE1_CANTxOnTrueFunc0(void)
{
    Com_IpduGroupStart(Com_BODY_LE1_CANTx, FALSE);


    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALBODY_LE1_CANRxOffTrueFunc0(void)
{
    Com_IpduGroupStop(Com_BODY_LE1_CANRx);


    return E_OK;
}
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_ALBODY_LE1_CANRxOnTrueFunc0(void)
{
    Com_IpduGroupStart(Com_BODY_LE1_CANRx, FALSE);


    return E_OK;
}
STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleInitBlockII_Core0(void)
{
    volatile BswMRuleStateType ret;


    if(BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_INIT)
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleWkupToReadNvM_Core0(void)
{
    volatile BswMRuleStateType ret;


    if(((BswM_EcuMRequestMode == ECUM_STATE_APP_RUN)
       || (BswM_ComMMode[0] == COMM_FULL_COMMUNICATION))
           && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_WAKEUP)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleReadNvMToRun_Core0(void)
{
    volatile BswMRuleStateType ret;


    if(((BswM_NvMReadAllStatus == NVM_REQ_OK)
       || (BswM_NvMReadAllStatus == NVM_REQ_NOT_OK))
           && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_READ_NVM)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleRunToPostRun_Core0(void)
{
    volatile BswMRuleStateType ret;


    if((BswM_EcuMRequestMode == ECUM_STATE_APP_POST_RUN)
       && (BswM_ComMMode[0] == COMM_NO_COMMUNICATION)
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_APP_RUN)
       && (BswM_TimerMode[0] == BSWM_TIMER_EXPIRED)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RulePostRunToRun_Core0(void)
{
    volatile BswMRuleStateType ret;


    if((BswM_EcuMRequestMode == ECUM_STATE_APP_RUN)
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_POST_RUN)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RulePostRunToPrep_Core0(void)
{
    volatile BswMRuleStateType ret;


    if((BswM_EcuMRequestMode == ECUM_STATE_SHUTDOWN)
       && (BswM_ComMMode[0] == COMM_NO_COMMUNICATION)
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_POST_RUN)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleRunToPrep_Core0(void)
{
    volatile BswMRuleStateType ret;


    if((BswM_EcuMRequestMode == ECUM_STATE_SHUTDOWN)
       && (BswM_ComMMode[0] == COMM_NO_COMMUNICATION)
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_APP_RUN)
       && (BswM_TimerMode[0] == BSWM_TIMER_EXPIRED)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RulePrepToRun_Core0(void)
{
    volatile BswMRuleStateType ret;


    if(((BswM_EcuMRequestMode == ECUM_STATE_APP_RUN)
       || (BswM_ComMMode[0] == COMM_FULL_COMMUNICATION))
           && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_PREP_SHUTDOWN)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RulePrepToWriteNvM_Core0(void)
{
    volatile BswMRuleStateType ret;


    if((BswM_EcuMRequestMode == ECUM_STATE_SHUTDOWN)
       && (BswM_ComMMode[0] == COMM_NO_COMMUNICATION)
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_PREP_SHUTDOWN)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleWriteNvMToRun_Core0(void)
{
    volatile BswMRuleStateType ret;


    if(((BswM_EcuMRequestMode == ECUM_STATE_APP_RUN)
       || (BswM_ComMMode[0] == COMM_FULL_COMMUNICATION))
           && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_WRITE_NVM)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleWriteNvMToSleep_Core0(void)
{
    volatile BswMRuleStateType ret;


    if(((BswM_NvMWriteAllStatus == NVM_REQ_OK)
       || (BswM_NvMWriteAllStatus == NVM_REQ_NOT_OK))
           && (BswM_EcuMRequestMode == ECUM_STATE_SHUTDOWN)
       && (BswM_ComMMode[0] == COMM_NO_COMMUNICATION)
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_WRITE_NVM)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleWkupToSleep_Core0(void)
{
    volatile BswMRuleStateType ret;


    if((BswM_EcuMRequestMode == ECUM_STATE_SHUTDOWN)
       && (BswM_ComMMode[0] == COMM_NO_COMMUNICATION)
       && (BswM_GeneralPortMode[0] == BSWM_GENERIC_MODE_WAKEUP)
       && (BswM_TimerMode[0] == BSWM_TIMER_EXPIRED)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleBODY_LE1_CANTxOn(void)
{
    volatile BswMRuleStateType ret;


    if(((BswM_DcmComMMode[0] == DCM_ENABLE_RX_TX_NORM)
       || (BswM_DcmComMMode[0] == DCM_DISABLE_RX_ENABLE_TX_NORM)
       || (BswM_DcmComMMode[0] == DCM_ENABLE_RX_TX_NORM_NM)
       || (BswM_DcmComMMode[0] == DCM_DISABLE_RX_ENABLE_TX_NORM_NM))
           && (BswM_ComMMode[0] == COMM_FULL_COMMUNICATION)
       && (BswM_CanSMMode[0] == CANSM_BSWM_FULL_COMMUNICATION)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleBODY_LE1_CANTxOff(void)
{
    volatile BswMRuleStateType ret;


    if((!(BswM_CanSMMode[0] == CANSM_BSWM_FULL_COMMUNICATION))
           || (BswM_DcmComMMode[0] == DCM_DISABLE_RX_TX_NORMAL)
       || (BswM_DcmComMMode[0] == DCM_ENABLE_RX_DISABLE_TX_NORM)
       || (BswM_DcmComMMode[0] == DCM_DISABLE_RX_TX_NORM_NM)
       || (BswM_DcmComMMode[0] == DCM_ENABLE_RX_DISABLE_TX_NORM_NM)
           || (BswM_ComMMode[0] == COMM_NO_COMMUNICATION)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleBODY_LE1_CANRxOn(void)
{
    volatile BswMRuleStateType ret;


    if((!(BswM_CanSMMode[0] == CANSM_BSWM_NO_COMMUNICATION))
           && ((BswM_DcmComMMode[0] == DCM_ENABLE_RX_TX_NORM)
       || (BswM_DcmComMMode[0] == DCM_ENABLE_RX_DISABLE_TX_NORM)
       || (BswM_DcmComMMode[0] == DCM_ENABLE_RX_TX_NORM_NM)
       || (BswM_DcmComMMode[0] == DCM_ENABLE_RX_DISABLE_TX_NORM_NM))
           && (BswM_ComMMode[0] == COMM_FULL_COMMUNICATION)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_RuleBODY_LE1_CANRxOff(void)
{
    volatile BswMRuleStateType ret;


    if((BswM_DcmComMMode[0] == DCM_DISABLE_RX_TX_NORMAL)
       || (BswM_DcmComMMode[0] == DCM_DISABLE_RX_ENABLE_TX_NORM)
       || (BswM_DcmComMMode[0] == DCM_DISABLE_RX_TX_NORM_NM)
       || (BswM_DcmComMMode[0] == DCM_DISABLE_RX_ENABLE_TX_NORM_NM)
           || (BswM_ComMMode[0] == COMM_NO_COMMUNICATION)
       || (BswM_CanSMMode[0] == CANSM_BSWM_NO_COMMUNICATION)
      )
    {
        ret = BSWM_TRUE;
    }
    else
    {
        ret = BSWM_FALSE;
    }

    return ret;
}

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONFIG_DATA
#include "BswM_MemMap.h"

STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALInitBlockII_Core0TrueHead0 =
{
    BSWM_ACTION,
    BswM_ALInitBlockII_Core0TrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALWkupToReadNvM_Core0TrueHead0 =
{
    BSWM_ACTION,
    BswM_ALWkupToReadNvM_Core0TrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALReadNvMToRun_Core0TrueHead0 =
{
    BSWM_ACTION,
    BswM_ALReadNvMToRun_Core0TrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALRunToPostRun_Core0TrueHead0 =
{
    BSWM_ACTION,
    BswM_ALRunToPostRun_Core0TrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALPostRunToRun_Core0TrueHead0 =
{
    BSWM_ACTION,
    BswM_ALPostRunToRun_Core0TrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALPrepToRun_Core0TrueHead0 =
{
    BSWM_ACTION,
    BswM_ALPrepToRun_Core0TrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALPostRunToPrep_Core0TrueHead0 =
{
    BSWM_ACTION,
    BswM_ALPostRunToPrep_Core0TrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALRunToPrep_Core0TrueHead0 =
{
    BSWM_ACTION,
    BswM_ALRunToPrep_Core0TrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALPrepToWriteNvM_Core0TrueHead0 =
{
    BSWM_ACTION,
    BswM_ALPrepToWriteNvM_Core0TrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALWriteNvMToSleep_Core0TrueHead0 =
{
    BSWM_ACTION,
    BswM_ALWriteNvMToSleep_Core0TrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALWkupToSleep_Core0TrueHead0 =
{
    BSWM_ACTION,
    BswM_ALWkupToSleep_Core0TrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALBODY_LE1_CANTxOffTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALBODY_LE1_CANTxOffTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALBODY_LE1_CANTxOnTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALBODY_LE1_CANTxOnTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALBODY_LE1_CANRxOffTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALBODY_LE1_CANRxOffTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
STATIC CONST(BswM_ActionListItemType, BSWM_CONST) BswM_ALBODY_LE1_CANRxOnTrueHead0 =
{
    BSWM_ACTION,
    BswM_ALBODY_LE1_CANRxOnTrueFunc0,
    BSWM_ACTIONLIST_NULL,
    BSWM_RULE_NULL,
    NULL_PTR
};
CONST(BswMActionList, BSWM_CONST) BswMAvailableActionLists[BSWM_MAX_ACTIONLIST_NUM] =
{
    {
        BSWM_CONDITION,
        &BswM_ALInitBlockII_Core0TrueHead0,
        (PriorityIdType)0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALWkupToReadNvM_Core0TrueHead0,
        (PriorityIdType)0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALReadNvMToRun_Core0TrueHead0,
        (PriorityIdType)0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALRunToPostRun_Core0TrueHead0,
        (PriorityIdType)0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALPostRunToRun_Core0TrueHead0,
        (PriorityIdType)0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALPrepToRun_Core0TrueHead0,
        (PriorityIdType)0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALPostRunToPrep_Core0TrueHead0,
        (PriorityIdType)0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALRunToPrep_Core0TrueHead0,
        (PriorityIdType)0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALPrepToWriteNvM_Core0TrueHead0,
        (PriorityIdType)0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALWriteNvMToSleep_Core0TrueHead0,
        (PriorityIdType)0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALWkupToSleep_Core0TrueHead0,
        (PriorityIdType)0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALBODY_LE1_CANTxOffTrueHead0,
        (PriorityIdType)0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALBODY_LE1_CANTxOnTrueHead0,
        (PriorityIdType)0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALBODY_LE1_CANRxOffTrueHead0,
        (PriorityIdType)0
    },
    {
        BSWM_TRIGGER,
        &BswM_ALBODY_LE1_CANRxOnTrueHead0,
        (PriorityIdType)0
    }
};
STATIC CONST(BswM_RuleCfgType, BSWM_CONST) BswMAvailableRules_PB0[16] =
{
    /*BswM_RuleInitBlockII_Core0*/
    {
        BSWM_FALSE,
        &BswM_RuleInitBlockII_Core0,
        BSWM_ACTIONLIST_BswM_ALInitBlockII_Core0_PB0,
        BSWM_ACTIONLIST_NULL,
        BSWM_IMMEDIATE
    },
    /*BswM_RuleWkupToReadNvM_Core0*/
    {
        BSWM_FALSE,
        &BswM_RuleWkupToReadNvM_Core0,
        BSWM_ACTIONLIST_BswM_ALWkupToReadNvM_Core0_PB0,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleReadNvMToRun_Core0*/
    {
        BSWM_FALSE,
        &BswM_RuleReadNvMToRun_Core0,
        BSWM_ACTIONLIST_BswM_ALReadNvMToRun_Core0_PB0,
        BSWM_ACTIONLIST_NULL,
        BSWM_IMMEDIATE
    },
    /*BswM_RuleRunToPostRun_Core0*/
    {
        BSWM_FALSE,
        &BswM_RuleRunToPostRun_Core0,
        BSWM_ACTIONLIST_BswM_ALRunToPostRun_Core0_PB0,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RulePostRunToRun_Core0*/
    {
        BSWM_FALSE,
        &BswM_RulePostRunToRun_Core0,
        BSWM_ACTIONLIST_BswM_ALPostRunToRun_Core0_PB0,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RulePostRunToPrep_Core0*/
    {
        BSWM_FALSE,
        &BswM_RulePostRunToPrep_Core0,
        BSWM_ACTIONLIST_BswM_ALPostRunToPrep_Core0_PB0,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleRunToPrep_Core0*/
    {
        BSWM_FALSE,
        &BswM_RuleRunToPrep_Core0,
        BSWM_ACTIONLIST_BswM_ALRunToPrep_Core0_PB0,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RulePrepToRun_Core0*/
    {
        BSWM_FALSE,
        &BswM_RulePrepToRun_Core0,
        BSWM_ACTIONLIST_BswM_ALPrepToRun_Core0_PB0,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RulePrepToWriteNvM_Core0*/
    {
        BSWM_FALSE,
        &BswM_RulePrepToWriteNvM_Core0,
        BSWM_ACTIONLIST_BswM_ALPrepToWriteNvM_Core0_PB0,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleWriteNvMToRun_Core0*/
    {
        BSWM_FALSE,
        &BswM_RuleWriteNvMToRun_Core0,
        BSWM_ACTIONLIST_BswM_ALPrepToRun_Core0_PB0,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleWriteNvMToSleep_Core0*/
    {
        BSWM_FALSE,
        &BswM_RuleWriteNvMToSleep_Core0,
        BSWM_ACTIONLIST_BswM_ALWriteNvMToSleep_Core0_PB0,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleWkupToSleep_Core0*/
    {
        BSWM_FALSE,
        &BswM_RuleWkupToSleep_Core0,
        BSWM_ACTIONLIST_BswM_ALWkupToSleep_Core0_PB0,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleBODY_LE1_CANTxOn*/
    {
        BSWM_FALSE,
        &BswM_RuleBODY_LE1_CANTxOn,
        BSWM_ACTIONLIST_BswM_ALBODY_LE1_CANTxOn_PB0,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleBODY_LE1_CANTxOff*/
    {
        BSWM_FALSE,
        &BswM_RuleBODY_LE1_CANTxOff,
        BSWM_ACTIONLIST_BswM_ALBODY_LE1_CANTxOff_PB0,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleBODY_LE1_CANRxOn*/
    {
        BSWM_FALSE,
        &BswM_RuleBODY_LE1_CANRxOn,
        BSWM_ACTIONLIST_BswM_ALBODY_LE1_CANRxOn_PB0,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleBODY_LE1_CANRxOff*/
    {
        BSWM_FALSE,
        &BswM_RuleBODY_LE1_CANRxOff,
        BSWM_ACTIONLIST_BswM_ALBODY_LE1_CANRxOff_PB0,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    }
};
STATIC CONST(BswM_RuleCfgType, BSWM_CONST) BswMAvailableRules_PB1[16] =
{
    /*BswM_RuleInitBlockII_Core0*/
    {
        BSWM_FALSE,
        &BswM_RuleInitBlockII_Core0,
        BSWM_ACTIONLIST_BswM_ALInitBlockII_Core0_PB1,
        BSWM_ACTIONLIST_NULL,
        BSWM_IMMEDIATE
    },
    /*BswM_RuleWkupToReadNvM_Core0*/
    {
        BSWM_FALSE,
        &BswM_RuleWkupToReadNvM_Core0,
        BSWM_ACTIONLIST_BswM_ALWkupToReadNvM_Core0_PB1,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleReadNvMToRun_Core0*/
    {
        BSWM_FALSE,
        &BswM_RuleReadNvMToRun_Core0,
        BSWM_ACTIONLIST_BswM_ALReadNvMToRun_Core0_PB1,
        BSWM_ACTIONLIST_NULL,
        BSWM_IMMEDIATE
    },
    /*BswM_RuleRunToPostRun_Core0*/
    {
        BSWM_FALSE,
        &BswM_RuleRunToPostRun_Core0,
        BSWM_ACTIONLIST_BswM_ALRunToPostRun_Core0_PB1,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RulePostRunToRun_Core0*/
    {
        BSWM_FALSE,
        &BswM_RulePostRunToRun_Core0,
        BSWM_ACTIONLIST_BswM_ALPostRunToRun_Core0_PB1,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RulePostRunToPrep_Core0*/
    {
        BSWM_FALSE,
        &BswM_RulePostRunToPrep_Core0,
        BSWM_ACTIONLIST_BswM_ALPostRunToPrep_Core0_PB1,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleRunToPrep_Core0*/
    {
        BSWM_FALSE,
        &BswM_RuleRunToPrep_Core0,
        BSWM_ACTIONLIST_BswM_ALRunToPrep_Core0_PB1,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RulePrepToRun_Core0*/
    {
        BSWM_FALSE,
        &BswM_RulePrepToRun_Core0,
        BSWM_ACTIONLIST_BswM_ALPrepToRun_Core0_PB1,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RulePrepToWriteNvM_Core0*/
    {
        BSWM_FALSE,
        &BswM_RulePrepToWriteNvM_Core0,
        BSWM_ACTIONLIST_BswM_ALPrepToWriteNvM_Core0_PB1,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleWriteNvMToRun_Core0*/
    {
        BSWM_FALSE,
        &BswM_RuleWriteNvMToRun_Core0,
        BSWM_ACTIONLIST_BswM_ALPrepToRun_Core0_PB1,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleWriteNvMToSleep_Core0*/
    {
        BSWM_FALSE,
        &BswM_RuleWriteNvMToSleep_Core0,
        BSWM_ACTIONLIST_BswM_ALWriteNvMToSleep_Core0_PB1,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleWkupToSleep_Core0*/
    {
        BSWM_FALSE,
        &BswM_RuleWkupToSleep_Core0,
        BSWM_ACTIONLIST_BswM_ALWkupToSleep_Core0_PB1,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleBODY_LE1_CANTxOn*/
    {
        BSWM_FALSE,
        &BswM_RuleBODY_LE1_CANTxOn,
        BSWM_ACTIONLIST_BswM_ALBODY_LE1_CANTxOn_PB1,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleBODY_LE1_CANTxOff*/
    {
        BSWM_FALSE,
        &BswM_RuleBODY_LE1_CANTxOff,
        BSWM_ACTIONLIST_BswM_ALBODY_LE1_CANTxOff_PB1,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleBODY_LE1_CANRxOn*/
    {
        BSWM_FALSE,
        &BswM_RuleBODY_LE1_CANRxOn,
        BSWM_ACTIONLIST_BswM_ALBODY_LE1_CANRxOn_PB1,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    },
    /*BswM_RuleBODY_LE1_CANRxOff*/
    {
        BSWM_FALSE,
        &BswM_RuleBODY_LE1_CANRxOff,
        BSWM_ACTIONLIST_BswM_ALBODY_LE1_CANRxOff_PB1,
        BSWM_ACTIONLIST_NULL,
        BSWM_DEFERRED
    }
};
CONST(BswM_ConfigType, BSWM_CONST) BswM_PBConfigTable[2] =
{
    /*PBConfig 0*/
    {

        BswMPortMappingRulesStart_PB0, /*PortMappingRulesStart*/
        BswMPortMappingRulesNum_PB0, /*PortMappingRulesNum*/
        (BswMRuleType)48, /*PortMappingRuleNum*/
        BswMPortMappingRules_PB0, /*PortMappingRules*/
        (BswMRuleType)16, /*RuleNum*/
        BswMAvailableRules_PB0 /*AvailableRules*/
    },
    /*PBConfig 1*/
    {

        BswMPortMappingRulesStart_PB1, /*PortMappingRulesStart*/
        BswMPortMappingRulesNum_PB1, /*PortMappingRulesNum*/
        (BswMRuleType)48, /*PortMappingRuleNum*/
        BswMPortMappingRules_PB1, /*PortMappingRules*/
        (BswMRuleType)16, /*RuleNum*/
        BswMAvailableRules_PB1 /*AvailableRules*/
    }
};

#define BSWM_START_SEC_CONFIG_DATA
#include "BswM_MemMap.h"




