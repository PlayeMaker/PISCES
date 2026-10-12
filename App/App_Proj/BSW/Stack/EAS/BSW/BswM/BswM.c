/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM.c
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : BswM.c
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of BswM provided functionality
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials        CR#          Descriptions
*   ---------   ----------    ------------   ----------   ---------------
*   04.00.00    15/02/2023    wenbo.cui       N/A          Original
*   04.01.00    16/08/2024    Feixiang.Dong   N/A          Multicore
********************************************************************************
* END_FILE_HDR*/


/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 5087,3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "EcuM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in EcuM_MemMap.h
*/

/*PRQA S 3453,3429 EOF*/
/*
1.The unified requirement of EAS is that the error reporting functions of Det
and Dem moduls are accessed by macro functions.This part has been verified and
has no problem.
2.Macro functions are allowed to use to access parameters and do some simple operations.
*/

/*PRQA S 3432,3410,3409 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no
need to revise.
*/

/*PRQA S 3673,4603 EOF*/
/*
Parameters in AUTOSAR standard APIs,they may not follow this rule.
*/

/*PRQA S 3212 EOF*/
/*
Unified requirements of EAS: constant shall be converted.
*/

/*PRQA S 3119 EOF*/
/*
No unified input parameter processing is used
*/

/*PRQA S 3197 EOF*/
/*
Redundant initialization will not cause functional problems,there is no need to
revise.And it is the requirement of programming specification to initialize
local variables.
*/

/*PRQA S 3138,3141 EOF*/
/*
The code of critical segments can be configured as void when QAC testing.
Note:When called by Det,Dem or BswM, the critical segments must be enabled when
QAC testing.Reasons are needed for special circumstances not enabled.
*/

/*PRQA S 3416 EOF*/
/*
In a If statement,calling a function to directly determine the return value is 
allowed if there is only one judge branch.
*/

/*PRQA S 0857,0380 EOF*/
/*
Macro definitions exceed 1024. The number of macros is unlimited
*/

/*PRQA S 792,791 EOF*/
/*
Name of macros may not follow relevant naming rules.
*/

/*PRQA S 1503 EOF*/
/*
Api used by other modules.
*/

/*PRQA S 1532 EOF*/
/*
Function declared externally are called by the user.
*/
/*****************************************************************************
 *  BswM QAC Suppression
 *****************************************************************************/

/*PRQA S 3227,3204 EOF*/
/*
Read-only function input parameters may not be defined as const,it does not affect the function.
AUTOSAR API shall define standard input parameters according to specification requirements
*/

/*PRQA S 2100,2101 EOF*/
/*
Integer promotion related
*/
/*PRQA S 2000 EOF*/
/*
When there is only one If,there can be no else.
*/
/*PRQA S 0776 EOF*/
/*
The first 6 characters shall be different.But AUTOSAR requires prefixes must be the same,so this is ignored.
*/

/*PRQA S 3206 EOF*/
/*
The function parameters will be used under certain conditions.
*/

/*PRQA S 2201 EOF*/
/*
When BSWM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD, This warning will not exis.
*/

/*PRQA S 2842,2844 EOF*/
/*
Value of index will not exceed the effective range.
*/

/*PRQA S 2877,2984 EOF*/
/*
If the port of one module is configured only one, the warning will be reported.
*/
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "BswM.h"
#include "ComStack_Types.h"
#include "SchM_BswM.h"


#if(STD_ON == BSWM_COMM_ENABLED)
#include "BswM_ComM.h"
#include "ComM.h"
#endif

#if(STD_ON == BSWM_NVM_ENABLED)
#include "BswM_NvM.h"
#include "NvM.h"
#endif

#if(STD_ON == BSWM_CANSM_ENABLED)
#include "BswM_CanSM.h"
#include "CanSM.h"
#endif

#if(STD_ON == BSWM_LINSM_ENABLED)
#include "BswM_LinSM.h"
#include "LinSM.h"
#endif

#if(STD_ON == BSWM_FRSM_ENABLED)
#include "BswM_FrSM.h"
#include "FrSM.h"
#endif

#if(STD_ON == BSWM_ETHSM_ENABLED)
#include "BswM_EthSM.h"
#include "EthSM.h"
#endif

#if(STD_ON == BSWM_ECUM_ENABLED)
#include "BswM_EcuM.h"
#include "EcuM.h"
#endif

#if(STD_ON == BSWM_LINTP_ENABLED)
#include "BswM_LinTp.h"
#include "LinTp.h"
#endif

#if(STD_ON == BSWM_DEV_ERROR_DETECT)
#include "Det.h"
#endif

#if(STD_ON == BSWM_DCM_ENABLED)
#include "BswM_Dcm.h"
#include "Dcm.h"
#endif

#if(STD_ON == BSWM_SD_ENABLED)
#include "BswM_Sd.h"
#include "Sd.h"
#endif

#if(STD_ON == BSWM_NM_ENABLED)
#include "BswM_Nm.h"
#include "Nm.h"
#endif

#if(STD_ON == BSWM_ETHIF_ENABLED)
#include "BswM_EthIf.h"
#include "EthIf.h"
#endif

#if(STD_ON == BSWM_SOAD_ENABLED)
#include "BswM_SoAd.h"
#include "SoAd.h"
#endif

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
#include "Bmc.h"
#endif

/*******************************************************************************
*   Version Check
*******************************************************************************/
#if(STD_ON == BSWM_VERSION_CHECK)
/* check Version with cfg file */
#if((BSWM_AR_RELEASE_MAJOR_VERSION != BSWM_AR_RELEASE_MAJOR_VERSION_CFG) || \
   (BSWM_AR_RELEASE_MINOR_VERSION != BSWM_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of BswM and its cfg file are incompatible"
#endif

#if((BSWM_SW_MAJOR_VERSION != BSWM_SW_MAJOR_VERSION_CFG) || \
   (BSWM_SW_MINOR_VERSION != BSWM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of BswM and its cfg file are incompatible"
#endif
#endif/*#if(STD_ON == BSWM_VERSION_CHECK)*/



/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == BSWM_DEV_ERROR_DETECT)
#define BSWM_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(BSWM_MODULE_ID, BSWM_INSTANCE_ID, (ApiId), (errcode))
#else
#define BSWM_DET_REPORT_ERROR(ApiId, errcode)
#endif


#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
#define BswM_CrossCorePortCheck(Core)    (BswM_CoreInfoTable[Core].CrossCorePortCheckFunc())
#define BSWM_CORE_RULE_START(Core)       (BswM_CoreInfoTable[Core].CoreRuleStart)
#define BSWM_CORE_RULE_END(Core)         (BswM_CoreInfoTable[Core].CoreRuleEnd)
#else
#define BSWM_CORE_RULE_START(Core)       (BswMRuleType)0
#if(BSWM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#define BSWM_CORE_RULE_END(Core)         (BSWM_MAX_RULE_NUM - (BswMRuleType)1)
#else
#define BSWM_CORE_RULE_END(Core)         ((BswM_ConfigSet->RuleNum) - (BswMRuleType)1)
#endif
#endif

#if((STD_ON == BSWM_TIMER_ENABLED) && (STD_ON == BSWM_MULTI_CORE_SUPPORT))
#define BSWM_TIMER_MAP_CORE(Timer)       (BswM_TimerMappingCore[Timer])
#endif

/*PRQA S 3435,3456 ++*/
/*This macro parameter occurs more than once in the replacement list. There is no need to modify the specific method */
#define BSWM_MATCH_INPUT(src,mask)         (((uint32)(src) & (uint32)(mask)) == (uint32)src)
/*PRQA S 3435,3456 --*/
#define BSWM_RULE_IS_DEFERRED(RuleId)      (TRUE == BswM_RuleDeferredFlag[RuleId])
#define BSWM_RULE_SET_DEFERRED(RuleId)     (BswM_RuleDeferredFlag[RuleId] = TRUE)
#define BSWM_RULE_SET_UNDEFERRED(RuleId)   (BswM_RuleDeferredFlag[RuleId] = FALSE)

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
#define BSWM_IS_LOCKED(CoreID)      (TRUE == BswM_ArbitrateLock[CoreID])
#define BSWM_LOCK(CoreID)           (BswM_ArbitrateLock[CoreID] = TRUE)
#define BSWM_UNLOCK(CoreID)         (BswM_ArbitrateLock[CoreID] = FALSE)
#else
#define BSWM_IS_LOCKED(CoreID)      (TRUE == BswM_ArbitrateLock)
#define BSWM_LOCK(CoreID)           (BswM_ArbitrateLock = TRUE)
#define BSWM_UNLOCK(CoreID)         (BswM_ArbitrateLock = FALSE)
#endif

/*******************************************************************************
*   Local Data Define
*******************************************************************************/
#define BSWM_START_SEC_VAR_INIT_GLOBAL_8
#include "BswM_MemMap.h"

STATIC VAR(Std_InitStateType, BSWM_VAR) BswM_InitStatus = STD_UNINITIALIZED;
#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
STATIC volatile VAR(boolean, BSWM_VAR) BswMCoreWaitFlag = FALSE;
#endif

#define BSWM_STOP_SEC_VAR_INIT_GLOBAL_8
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_LOCAL_8
#include "BswM_MemMap.h"

STATIC VAR(BswMRuleStateType, BSWM_VAR) BswMRuleState[BSWM_MAX_RULE_NUM];

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
STATIC VAR(boolean, BSWM_VAR) BswM_ArbitrateLock[BSWM_USED_CORE_NUMBER];
#else
STATIC VAR(boolean, BSWM_VAR) BswM_ArbitrateLock;
#endif

STATIC VAR(boolean, BSWM_VAR) BswM_RuleDeferredFlag[BSWM_MAX_RULE_NUM];

#define BSWM_STOP_SEC_VAR_CLEARED_LOCAL_8
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_LOCAL_16
#include "BswM_MemMap.h"
STATIC VAR(uint16, BSWM_VAR) BswMRuleDeferredCnt[BSWM_USED_CORE_NUMBER];
#define BSWM_STOP_SEC_VAR_CLEARED_LOCAL_16

#include "BswM_MemMap.h"
#define BSWM_START_SEC_VAR_CLEARED_LOCAL_32
#include "BswM_MemMap.h"
#if(STD_ON == BSWM_TIMER_ENABLED)
STATIC VAR(uint32, BSWM_VAR) BswM_Timer[BSWM_MAX_TIMER_NUM];
#endif
#define BSWM_STOP_SEC_VAR_CLEARED_LOCAL_32
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "BswM_MemMap.h"
STATIC VAR(BswM_PriorityALType, BSWM_VAR) BswM_PriorityActionList[BSWM_USED_CORE_NUMBER][BSWM_MAX_PRIORITY_NUM];
#define BSWM_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "BswM_MemMap.h"
#if(BSWM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
STATIC P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_VAR_NOINIT) BswM_ConfigSet;
#endif
#define BSWM_STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "BswM_MemMap.h"

/*******************************************************************************
*   Private Functions
*******************************************************************************/
#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"
STATIC FUNC(void, BSWM_CODE) BswM_ImmediateRunRule
(
    BswMRuleType RuleIndex
);

STATIC FUNC(void, BSWM_CODE) BswM_DeferredRunRule
(
    BswMRuleType RuleIndex
);

STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_RunActionList
(
    BswMActionListIdType ActionListId
);

STATIC FUNC(void, BSWM_CODE) BswM_DeferRule
(
    uint8 CoreId,
    BswMRuleType RuleIndex
);

STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_ArbitrateRule
(
    uint8 CoreId,
    BswMRuleType RuleId
);

STATIC FUNC(void, BSWM_CODE) BswM_RecordActionList
(
    BswMActionListIdType ActionListId
);

STATIC FUNC(void, BSWM_CODE) BswM_ArbitratePortMappingRules
(
    BswMPortType Port
);

#if(STD_ON == BSWM_TIMER_ENABLED)
STATIC FUNC(void, BSWM_CODE) BswM_TimerMainFunction
(
    uint8 CoreId
);
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_RunActionList
*
* Description:   Immediate run an ActionList
*
* Inputs:        ActionListId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, BSWM_CODE) BswM_RunActionList
(
    BswMActionListIdType ActionListId
)
{
    Std_ReturnType ret = E_OK;
    P2CONST(BswM_ActionListItemType, AUTOMATIC, BSWM_CONST) ActionItem;

    if((BswMActionListIdType)BSWM_ACTIONLIST_NULL == ActionListId)
    {
        ret = E_OK;
    }
    else
    {
        ActionItem = BswMAvailableActionLists[ActionListId].ActionListHead;

        while(NULL_PTR != ActionItem)
        {
            switch(ActionItem->ActionType)
            {
            case BSWM_ACTION:
                if(NULL_PTR != ActionItem->ActionFunc)
                {
                    ret = ActionItem->ActionFunc();/*PRQA S 1521*/
                }
                break;

            case BSWM_ACTIONLIST:
                /*PRQA S 3670 ++*/
                /* MISRA RULE 16.2 violated:
                The indirect recurisive call is necessary to process the cascaded action lists,
                and this recurisive call will return eventually.*/
                ret = BswM_RunActionList(ActionItem->ActionListId);/*PRQA S 1521*/
                /*PRQA S 3670 --*/
                break;

            case BSWM_RULE:
                /*SWS_BswM_00062*/
                /*locked now, run later*/
                if(BSWM_RULE_NULL != ActionItem->RuleId)
                {
                    BswM_ImmediateRunRule(ActionItem->RuleId);
                }
                ret = E_OK;
                break;

            default:
                ret = E_NOT_OK;
                break;
            }

            if(E_NOT_OK == ret)
            {
                /*SWS_BswM_00239*/
#if(STD_ON == BSWM_ERRORID_ENABLED)
                BSWM_DET_REPORT_ERROR(ActionItem->ErrorId, BSWM_E_ACTION_FAILED);
#endif
#if(STD_ON == BSWM_ABORTONFAIL_ENABLED)
                if(ActionItem->AbortOnFail)
                {
                    break;
                }
#endif
            }

            ActionItem = (const BswM_ActionListItemType*)(ActionItem->next);

        }
    }

    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_ImmediateRunRule
*
* Description:   Immediate run a rule
*
* Inputs:        RuleIndex
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, BSWM_CODE) BswM_ImmediateRunRule
(
    BswMRuleType RuleIndex
)
{
    BswMRuleStateType RuleNewState;
    BswMRuleStateType RuleOldState = BswMRuleState[RuleIndex];
    RuleNewState = BswMAvailableRules[RuleIndex].RuleFunc();

    /*SWS_BswM_00016*//* SWS_BswM_00066 */
    if(BSWM_TRUE == RuleNewState)
    {
        BswMRuleState[RuleIndex] = BSWM_TRUE;

        if((BswMActionListIdType)BSWM_ACTIONLIST_NULL == BswMAvailableRules[RuleIndex].RuleTrueActionList)
        {
            /*NULL ACTIONLIST do not need to process*/
        }
        else if(BswMAvailableActionLists[BswMAvailableRules[RuleIndex].RuleTrueActionList].Excution == BSWM_CONDITION)
        {
            /* Run True Action List *//* SWS_BswM_00115 */
            (void)BswM_RunActionList(BswMAvailableRules[RuleIndex].RuleTrueActionList);
        }
        else  /* True Action List is TRIGGER */
        {
            /* SWS_BswM_00011 */
            if(BSWM_TRUE != RuleOldState)
            {
                (void)BswM_RunActionList(BswMAvailableRules[RuleIndex].RuleTrueActionList);
            }
        }
    }
    else if(BSWM_FALSE == RuleNewState)
    {
        BswMRuleState[RuleIndex] = BSWM_FALSE;

        if((BswMActionListIdType)BSWM_ACTIONLIST_NULL == BswMAvailableRules[RuleIndex].RuleFalseActionList)
        {
            /*NULL ACTIONLIST do not need to process*/
        }
        else if(BswMAvailableActionLists[BswMAvailableRules[RuleIndex].RuleFalseActionList].Excution == BSWM_CONDITION)
        {
            /* Run False Action List *//* SWS_BswM_00116 */
            (void)BswM_RunActionList(BswMAvailableRules[RuleIndex].RuleFalseActionList);
        }
        else  /* False Action List is TRIGGER */
        {
            /* SWS_BswM_00023 */
            if(BSWM_FALSE != RuleOldState)
            {
                (void)BswM_RunActionList(BswMAvailableRules[RuleIndex].RuleFalseActionList);
            }
        }
    }
    else
    {
        /* SWS_BswM_00064 */
        BswMRuleState[RuleIndex] = BSWM_UNDEFINED;
        /*BSWM_UNDEFINED do not need to process*/
    }

    return;
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_RecordActionList
*
* Description:   Record the order of action execution
*
* Inputs:        RuleIndex
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, BSWM_CODE) BswM_RecordActionList
(
    BswMActionListIdType ActionListId
)
{
    PriorityIdType PriorityId;
    DeferALCountType ALCount;
#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
    uint8 CurCoreID = BSWM_GET_CORE_ID();
#else
    uint8 CurCoreID = (uint8)0;
#endif

    /*Obtain Execution Priority*/
    PriorityId = BswMAvailableActionLists[ActionListId].PriorityId;
    /*In cases where BswMActionListPriority are the same, the order of execution is arbitrary*/
    ALCount = BswM_PriorityActionList[CurCoreID][PriorityId].DeferALCount;
    BswM_PriorityActionList[CurCoreID][PriorityId].DeferActionList[ALCount] = ActionListId;
    /*PRQA S 3383 ++*/
    /*A wraparound guard cannot be identified for the given unsigned arithmetic expression.*/
    BswM_PriorityActionList[CurCoreID][PriorityId].DeferALCount++;
    /*PRQA S 3383 --*/
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_DeferredRunRule
*
* Description:   Defer run a rule
*
* Inputs:        RuleIndex
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, BSWM_CODE) BswM_DeferredRunRule
(
    BswMRuleType RuleIndex
)
{
    BswMRuleStateType RuleNewState;
    BswMRuleStateType RuleOldState = BswMRuleState[RuleIndex];
    RuleNewState = BswMAvailableRules[RuleIndex].RuleFunc();

    /*SWS_BswM_00016*//* SWS_BswM_00066 */
    if(BSWM_TRUE == RuleNewState)
    {
        BswMRuleState[RuleIndex] = BSWM_TRUE;

        if((BswMActionListIdType)BSWM_ACTIONLIST_NULL == BswMAvailableRules[RuleIndex].RuleTrueActionList)
        {
            /*NULL ACTIONLIST do not need to process*/
        }
        else if(BswMAvailableActionLists[BswMAvailableRules[RuleIndex].RuleTrueActionList].Excution == BSWM_CONDITION)
        {
            (void)BswM_RecordActionList(BswMAvailableRules[RuleIndex].RuleTrueActionList);
        }
        else  /* True Action List is TRIGGER */
        {
            /* SWS_BswM_00011 */
            if(BSWM_TRUE != RuleOldState)
            {
                (void)BswM_RecordActionList(BswMAvailableRules[RuleIndex].RuleTrueActionList);
            }
        }
    }
    else if(BSWM_FALSE == RuleNewState)
    {
        BswMRuleState[RuleIndex] = BSWM_FALSE;

        if((BswMActionListIdType)BSWM_ACTIONLIST_NULL == BswMAvailableRules[RuleIndex].RuleFalseActionList)
        {
            /*NULL ACTIONLIST do not need to process*/
        }
        else if(BswMAvailableActionLists[BswMAvailableRules[RuleIndex].RuleFalseActionList].Excution == BSWM_CONDITION)
        {
            (void)BswM_RecordActionList(BswMAvailableRules[RuleIndex].RuleFalseActionList);
        }
        else  /* False Action List is TRIGGER */
        {
            /* SWS_BswM_00023 */
            if(BSWM_FALSE != RuleOldState)
            {
                (void)BswM_RecordActionList(BswMAvailableRules[RuleIndex].RuleFalseActionList);
            }
        }
    }
    else
    {
        /* SWS_BswM_00064 */
        BswMRuleState[RuleIndex] = BSWM_UNDEFINED;
        /*BSWM_UNDEFINED do not need to process*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_DeferRule
*
* Description:   Label a rule as deferred
*
* Inputs:        RuleIndex
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, BSWM_CODE) BswM_DeferRule
(
    uint8 CoreId,
    BswMRuleType RuleIndex
)
{
    SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_2();

    if(!BSWM_RULE_IS_DEFERRED(RuleIndex))
    {
        BSWM_RULE_SET_DEFERRED(RuleIndex);
        /*PRQA S 3383 ++*/
        /*A wraparound guard cannot be identified for the given unsigned arithmetic expression.*/
        BswMRuleDeferredCnt[CoreId]++;
        /*PRQA S 3383 --*/
    }

    SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_2();
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_ArbitrateRule
*
* Description:   This function arbitrate the required rules either immediately or deferred to
*                main function
*
* Inputs:        CoreId: Core identifier
*                RuleId: Id of the rule to be arbitrated
*
* Outputs:       BSWM_TRUE when complete
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(BswMRuleStateType, BSWM_CODE) BswM_ArbitrateRule
(
    uint8 CoreId,
    BswMRuleType RuleId
)
{
    if(BswMAvailableRules[RuleId].RequestProcessing == BSWM_IMMEDIATE)
    {
        /*SWS_BswM_00069 not a TAS instruction, tbd*/
        if(BSWM_IS_LOCKED(CoreId))
        {
            BswM_DeferRule(CoreId, RuleId);
        }
        else
        {
            BSWM_LOCK(CoreId);
            BswM_ImmediateRunRule(RuleId);
            BSWM_UNLOCK(CoreId);
        }
    }
    else
    {
        BswM_DeferRule(CoreId, RuleId);
    }

    return BSWM_TRUE;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_ArbitratePortMappingRules
*
* Description:   This function arbitrate rules mapping by given port
*
* Inputs:        Port  Id of the Port to be arbitrated
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, BSWM_CODE) BswM_ArbitratePortMappingRules
(
    BswMPortType Port
)
{
    BswMRuleType RuleIndex;
    BswMRuleType StartRuleId;
    BswMRuleType EndRuleId;
#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
    uint8 CurCoreID = BSWM_GET_CORE_ID();
#else
    uint8 CurCoreID = (uint8)0;
#endif

    StartRuleId = BswMPortMappingRulesStart[Port];
    EndRuleId = StartRuleId + BswMPortMappingRulesNum[Port];

    for(RuleIndex = StartRuleId; RuleIndex < EndRuleId; RuleIndex++)
    {
        (void)BswM_ArbitrateRule(CurCoreID, BswMPortMappingRules[RuleIndex]);
    }
}


#if(STD_ON == BSWM_TIMER_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_TimerMainFunction
*
* Description:   This function is called in BswM main function to process timer.
*
* Inputs:        CoreId: identifier of core
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, BSWM_CODE) BswM_TimerMainFunction
(
    uint8 CoreId
)
{
    uint8 TimerId;
    BswMPortType Port;

    for(TimerId = (uint8)0; TimerId < BSWM_MAX_TIMER_NUM; TimerId++)
    {
#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
        if(BSWM_TIMER_MAP_CORE(TimerId) == CoreId)
#endif
        {
            SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_0();
            if(BswM_Timer[TimerId] > (uint16)0)
            {
                BswM_Timer[TimerId]--;

                if(BswM_Timer[TimerId] == (uint16)0)
                {
                    /*SWS_BswM_00264*/
                    BswM_TimerMode[TimerId] = BSWM_TIMER_EXPIRED;
                    Port = BSWM_MAP_TIMER_TO_PORT(TimerId);
                    BswM_SetRulesAsDeffer(CoreId, Port);
                }
            }
            SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_0();
        }
    }
}
#endif


/*******************************************************************************
*   Public Functions
*******************************************************************************/
/*SWS_BswM_00003*/
#if(STD_ON == BSWM_VERSION_INFO_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_GetVersionInfo  
*
* Description:   This service returns the version information of the called
*                BSW Mode Manager module
*
* Inputs:        None
*
* Outputs:       VersionInfo  Pointer to where to store the version information
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, BSWM_APPL_DATA) VersionInfo
)
{
    if(NULL_PTR == VersionInfo)
    {
        BSWM_DET_REPORT_ERROR(BSWM_GETVERSIONINFO_APIID, BSWM_E_PARAM_POINTER);
    }
    else
    {
        VersionInfo->vendorID = BSWM_VENDOR_ID;
        VersionInfo->moduleID = BSWM_MODULE_ID;

        VersionInfo->sw_major_version = (uint8)BSWM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)BSWM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)BSWM_SW_PATCH_VERSION;
    }
}
#endif

#if(STD_ON == BSWM_GENERIC_REQUEST_ENABLED)
/*SWS_BswM_00046*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_RequestMode  
*
* Description:   Generic function call to request modes. This function shall only 
*                be used by other BSW module that does not have a specific mode 
*                reuqest interface
*
* Inputs:        requesting_user  The user that requests the mode
*                requested_mode   The requested mode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_RequestMode
(
    BswM_UserType requesting_user,
    BswM_ModeType requested_mode
)
{
    BswMPortType Port;

    /*SWS_BswM_00077*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_REQUESTMODE_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00089*/
    /*Modes are user-defined, so no range check can be peformed*/
    /*SWS_BswM_00090*/
#if(BSWM_GENERAL_PORT_NUM > 0)
    else if(requesting_user >= (BswM_UserType)BSWM_GENERAL_PORT_NUM)
    {
        BSWM_DET_REPORT_ERROR(BSWM_REQUESTMODE_APIID, BSWM_E_REQ_USER_OUT_OF_RANGE);
    }
    else
    {
#if(STD_OFF == BSWM_MULTI_CORE_SUPPORT)
        BswM_GeneralPortMode[requesting_user] = requested_mode;
#else
        BSWM_ATOMIC_WRITE_16(&(BswM_GeneralPortMode[requesting_user]), requested_mode);

        if(BswM_GeneralPortModeMultiCore[requesting_user] == FALSE)
#endif
        {
            Port = BSWM_MAP_BSWM_GENERAL_TO_PORT(requesting_user);
            BswM_ArbitratePortMappingRules(Port);
        }
    }
#endif
}

#endif

#if(STD_ON == BSWM_COMM_ENABLED)
/*SWS_BswM_00047*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_ComM_CurrentMode  
*
* Description:   Function called by ComM to indicate the current communication mode of a
*                ComM channel.
*
* Inputs:        NetworkHandleType  The ComM communication channel that the indicated
*                                   state corresponds to.
*                RequestedMode      The current state of the ComM communication channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_ComM_CurrentMode
(
    NetworkHandleType Network,
    ComM_ModeType RequestedMode
)
{
#if(BSWM_COMM_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#endif
    /*SWS_BswM_00078*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_COMM_CURRENTMODE_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00091*/
    else if(RequestedMode > COMM_FULL_COMMUNICATION_WITH_WAKEUP_REQUEST)
    {
        BSWM_DET_REPORT_ERROR(BSWM_COMM_CURRENTMODE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_COMM_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_COMM_PORT_NUM; src++)
        {
            if(Network == BswM_ComMModeRef[src])
            {
                BSWM_ATOMIC_WRITE(&(BswM_ComMMode[src]), RequestedMode);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_ComMModeMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_COMM_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }
}
/*SWS_BswM_00148*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_ComM_CurrentPNCMode  
*
* Description:   Function called by ComM to indicate the current mode of the PNC.
*
* Inputs:        PNC: The handle of the PNC for which the current state is reported.
*                CurrentPncMode: The current mode of the PNC.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_ComM_CurrentPNCMode
(
    PNCHandleType PNC,
    ComM_PncModeType CurrentPncMode
)
{
#if(BSWM_COMM_PNC_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#endif

    /*SWS_BswM_00149*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_COMM_CURRENTPNCMODE_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00150*/
    else if(CurrentPncMode > COMM_PNC_REQUESTED_WITH_WAKEUP_REQUEST)
    {
        BSWM_DET_REPORT_ERROR(BSWM_COMM_CURRENTPNCMODE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_COMM_PNC_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_COMM_PNC_PORT_NUM; src++)
        {
            if(PNC == BswM_ComMPNCModeRef[src])
            {
                BSWM_ATOMIC_WRITE(&(BswM_ComMPNCMode[src]), CurrentPncMode);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_ComMPNCModeMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_COMM_PNC_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }
}
#if(STD_ON == BSWM_COMM_RESET_ENABLED)
/*SWS_BswM_00217*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_ComM_InitiateReset  
*
* Description:   Function called by ComM to signal a shutdown.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_ComM_InitiateReset
(
    void
)
{
#if(BSWM_COMM_RESET_PORT_NUM > 0)
    BswMPortType Port = BSWM_MAP_COMM_RESET_TO_PORT();
#endif

    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_COMM_INITIATERESET_APIID, BSWM_E_UNINIT);
    }
    else
    {
#if(BSWM_COMM_RESET_PORT_NUM > 0)
        BSWM_ATOMIC_WRITE(&(BswM_ComMInitiateReset), TRUE);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
        if(BswM_ComMInitiateResetMultiCore == FALSE)
#endif
        {
            BswM_ArbitratePortMappingRules(Port);
        }
#endif
    }
}
#endif/*#if(STD_ON == BSWM_COMM_RESET_ENABLED)*/
#endif/*#if(STD_ON == BSWM_COMM_ENABLED)*/

/*SWS_BswM_00204*/
#if(STD_ON == BSWM_SD_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_Sd_ClientServiceCurrentState  
*
* Description:   Function called by Service Discovery to indicate current state 
*                of the Client Service(available/down).
*
* Inputs:        SdClientServiceHandleId: HandleId to identify the ClientService.
*                CurrentClientState: Current state of the ClientService.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_Sd_ClientServiceCurrentState
(
    uint16 SdClientServiceHandleId,
    Sd_ClientServiceCurrentStateType CurrentClientState
)
{
#if(BSWM_SD_CS_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#endif

    /*SWS_BswM_00205*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_SD_CLIENTSERVICECURRENTSTATE_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00206*/
    else if(CurrentClientState > SD_CLIENT_SERVICE_AVAILABLE)
    {
        BSWM_DET_REPORT_ERROR(BSWM_SD_CLIENTSERVICECURRENTSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_SD_CS_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_SD_CS_PORT_NUM; src++)
        {
            if(SdClientServiceHandleId == BswM_SdCSStateRef[src])
            {
                BSWM_ATOMIC_WRITE(&(BswM_SdCSState[src]), CurrentClientState);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_SdCSStateMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_SD_CS_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }
}
/*SWS_BswM_00207*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_Sd_ConsumedEventGroupCurrentState  
*
* Description:   Function called by Service Discovery to indicate current status 
*                of the Consumed Eventgroup (available/down).
*
* Inputs:        SdConsumedEventGroupHandleId: HandleId to identify the Consumed Eventgroup.
*                ConsumedEventGroupState: Status of the Consumed Eventgroup.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_Sd_ConsumedEventGroupCurrentState
(
    uint16 SdConsumedEventGroupHandleId,
    Sd_ConsumedEventGroupCurrentStateType ConsumedEventGroupState
)
{
#if(BSWM_SD_EVENTGROUP_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#endif
    /*SWS_BswM_00208*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00209*/
    else if(ConsumedEventGroupState > SD_CONSUMED_EVENT_GROUP_AVAILABLE)
    {
        BSWM_DET_REPORT_ERROR(BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_SD_EVENTGROUP_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_SD_EVENTGROUP_PORT_NUM; src++)
        {
            if(SdConsumedEventGroupHandleId == BswM_SdEventGroupStateRef[src])
            {
                BSWM_ATOMIC_WRITE(&(BswM_SdEventGroupState[src]), ConsumedEventGroupState);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_SdEventGroupStateMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_SD_EVENTGROUP_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }
}
/*SWS_BswM_00210*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_Sd_EventHandlerCurrentState  
*
* Description:   Function called by Service Discovery to indicate current status of the
*                EventHandler (requested/released).
*
* Inputs:        SdEventHandlerHandleId HandleId to identify the EventHandler
*                EventHandlerStatus Status of the EventHandler
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_Sd_EventHandlerCurrentState
(
    uint16 SdEventHandlerHandleId,
    Sd_EventHandlerCurrentStateType EventHandlerStatus
)
{
#if(BSWM_SD_EVENTHANDLER_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#endif
    /*SWS_BswM_00211*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_SD_EVENTHANDLERCURRENTSTATE_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00212*/
    else if(EventHandlerStatus > SD_EVENT_HANDLER_REQUESTED)
    {
        BSWM_DET_REPORT_ERROR(BSWM_SD_EVENTHANDLERCURRENTSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_SD_EVENTHANDLER_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_SD_EVENTHANDLER_PORT_NUM; src++)
        {
            if(SdEventHandlerHandleId == BswM_SdEventHandlerStateRef[src])
            {
                BSWM_ATOMIC_WRITE(&(BswM_SdEventHandlerState[src]), EventHandlerStatus);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_SdEventHandlerStateMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_SD_EVENTHANDLER_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }
}
#endif


#if(STD_ON == BSWM_DCM_ENABLED)
/*SWS_BswM_00158*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_Dcm_ApplicationUpdated  
*
* Description:   This function is called by the DCM in order to report an updated application.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_Dcm_ApplicationUpdated
(
    void
)
{
#if(BSWM_DCM_APP_UPDATE_PORT_NUM > 0)
    BswMPortType Port = BSWM_MAP_DCM_APP_UPDATE_TO_PORT();
#endif

    /*SWS_BswM_00159*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_DCM_APPLICATIONUPDATED_APIID, BSWM_E_UNINIT);
    }
    else
    {
#if(BSWM_DCM_APP_UPDATE_PORT_NUM > 0)
        BSWM_ATOMIC_WRITE(&(BswM_DcmAppUpdated), TRUE);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
        if(BswM_DcmAppUpdatedMultiCore == FALSE)
#endif
        {
            BswM_ArbitratePortMappingRules(Port);
        }
#endif
    }
}

/*SWS_BswM_00048*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_Dcm_CommunicationMode_CurrentState  
*
* Description:   Function called by DCM to inform the BswM about the current state of the
*                   communication mode.
*
* Inputs:        Network  The communication channel that the diagnostic mode corresponds to.
*                   RequestedMode The requested diagnostic communication mode.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_Dcm_CommunicationMode_CurrentState
(
    NetworkHandleType Network,
    Dcm_CommunicationModeType RequestedMode
)
{
#if(BSWM_DCM_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#endif

    /*SWS_BswM_00079*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00093*/
    else if(RequestedMode > DCM_DISABLE_RX_TX_NORM_NM)
    {
        BSWM_DET_REPORT_ERROR(BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_DCM_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_DCM_PORT_NUM; src++)
        {
            if(Network == BswM_DcmComMModeRef[src])
            {
                BSWM_ATOMIC_WRITE(&(BswM_DcmComMMode[src]), RequestedMode);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_DcmComMModeMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_DCM_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }

}

#endif

#if(STD_ON == BSWM_CANSM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_CanSM_CurrentState  SWS_BswM_00049
*
* Description:   Function called by CanSM to indicate its current state.
*
* Inputs:        Network  The CAN channel that the indicated state corresponds to.
*                CurrentState The current state of the CAN channel.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_CanSM_CurrentState
(
    NetworkHandleType Network,
    CanSM_BswMCurrentStateType CurrentState
)
{
#if(BSWM_CANSM_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#else
    (void)Network;
#endif
    /*SWS_BswM_00080*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_CANSM_CURRENTSTATE_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00095*/
    else if(CurrentState > CANSM_BSWM_CHANGE_BAUDRATE)
    {
        BSWM_DET_REPORT_ERROR(BSWM_CANSM_CURRENTSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_CANSM_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_CANSM_PORT_NUM; src++)
        {
            if(Network == BswM_CanSMModeRef[src])
            {
                BSWM_ATOMIC_WRITE(&(BswM_CanSMMode[src]), CurrentState);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_CanSMModeMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_CANSM_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }
}

#endif
#if(STD_ON == BSWM_ETHSM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_EthSM_CurrentState   SWS_BswM_00050
*
* Description:   Function called by EthSM to indicate its current state.
*
* Inputs:        Network  The Ethernet channel that the indicated state corresponds to.
*                CurrentState The current state of the Ethernet channel.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_EthSM_CurrentState
(
    NetworkHandleType Network,
    EthSM_NetworkModeStateType CurrentState
)
{
#if(BSWM_ETHSM_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#endif
    /*SWS_BswM_00081*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_ETHSM_CURRENTSTATE_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00097*/
    else if(CurrentState >= ETHSM_STATE_LIMIT)
    {
        BSWM_DET_REPORT_ERROR(BSWM_ETHSM_CURRENTSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_ETHSM_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_ETHSM_PORT_NUM; src++)
        {
            if(Network == BswM_EthSMModeRef[src])
            {
                BSWM_ATOMIC_WRITE(&(BswM_EthSMMode[src]), CurrentState);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_EthSMModeMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_ETHSM_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }

}
#endif

#if(STD_ON == BSWM_FRSM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_FrSM_CurrentState  SWS_BswM_00051
*
* Description:   Function called by FrSM to indicate its current state.
*
* Inputs:        Network  The FlexRay cluster that the indicated state corresponds to.
*                CurrentState The current state of the FlexRay cluster.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_FrSM_CurrentState
(
    NetworkHandleType Network,
    FrSM_BswM_StateType CurrentState
)
{
#if(BSWM_FRSM_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#endif
    /*SWS_BswM_00082*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_FRSM_CURRENTSTATE_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00099*/
    else if(CurrentState > FRSM_LOW_NUMBER_OF_COLDSTARTERS_ECU_PASSIVE)
    {
        BSWM_DET_REPORT_ERROR(BSWM_FRSM_CURRENTSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_FRSM_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_FRSM_PORT_NUM; src++)
        {
            if((uint8)Network == BswM_FrSMModeRef[src])
            {
                BSWM_ATOMIC_WRITE(&(BswM_FrSMMode[src]), CurrentState);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_FrSMModeMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_FRSM_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }
}
#endif


#if(STD_ON == BSWM_LINSM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_LinSM_CurrentState  SWS_BswM_00052
*
* Description:   Function called by LinSM to indicate its current state.
*
* Inputs:        Network  The LIN channel that the indicated state corresponds to.
*                CurrentState The current state of the LIN channel.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_LinSM_CurrentState
(
    NetworkHandleType Network,
    LinSM_ModeType CurrentState
)
{
#if(BSWM_LINSM_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#endif
    /*SWS_BswM_00083*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_LINSM_CURRENTSTATE_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00101*/
    else if((CurrentState != LINSM_FULL_COM) && (CurrentState != LINSM_NO_COM))
    {
        BSWM_DET_REPORT_ERROR(BSWM_LINSM_CURRENTSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_LINSM_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_LINSM_PORT_NUM; src++)
        {
            if(Network == BswM_LinSMModeRef[src])
            {
                BSWM_ATOMIC_WRITE(&(BswM_LinSMMode[src]), CurrentState);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_LinSMModeMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_LINSM_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }
}
/*SWS_BswM_00058*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_LinSM_CurrentSchedule  
*
* Description:   Function called by LinSM to indicate the currently active schedule
*                table for a specific LIN channel.
*
* Inputs:        Network  The LIN channel that the schedule table switch have occurred on.l
*                CurrentSchedule The currently active schedule table of the LIN channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_LinSM_CurrentSchedule
(
    NetworkHandleType Network,
    LinIf_SchHandleType CurrentSchedule
)
{
#if(BSWM_LINSM_SCH_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#endif

    /*SWS_BswM_00086*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_LINSM_CURRENTSCHEDULE_APIID, BSWM_E_UNINIT);
    }
    else
    {
#if(BSWM_LINSM_SCH_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_LINSM_SCH_PORT_NUM; src++)
        {
            if(Network == BswM_LinSMSchRef[src])
            {
                BSWM_ATOMIC_WRITE(&(BswM_LinSMSch[src]), CurrentSchedule);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_LinSMSchMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_LINSM_SCH_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }
}
#endif


#if(STD_ON == BSWM_ECUM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_EcuM_CurrentState  SWS_BswM_91003
*
* Description:   Function called by EcuM to indicate the currentECU Operation Mode.
*
* Inputs:        CurrentState The requested ECU Operation Mode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_EcuM_CurrentState
(
    EcuM_StateType CurrentState
)
{
#if(BSWM_ECUM_INDICATION_PORT_NUM > 0)    
    BswMPortType Port = BSWM_MAP_ECUM_MODE_IND_TO_PORT();
#endif
    /*SWS_BswM_00084*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTSTATE_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00103*/
    else if((CurrentState != ECUM_STATE_APP_RUN)
            && (CurrentState != ECUM_STATE_APP_POST_RUN)
            && (CurrentState != ECUM_STATE_SLEEP)
            && (CurrentState != ECUM_STATE_SHUTDOWN)
            && (CurrentState != ECUM_STATE_PREP_SHUTDOWN)
            && (CurrentState != ECUM_STATE_STARTUP)
            && (CurrentState != ECUM_STATE_STARTUP_ONE)
            && (CurrentState != ECUM_STATE_STARTUP_TWO)
            && (CurrentState != ECUM_STATE_WAKEUP)
            && (CurrentState != ECUM_STATE_RUN)
            && (CurrentState != ECUM_STATE_WAKEUP_ONE)
            && (CurrentState != ECUM_STATE_WAKEUP_VALIDATION)
            && (CurrentState != ECUM_STATE_WAKEUP_REACTION)
            && (CurrentState != ECUM_STATE_WAKEUP_TWO)
            && (CurrentState != ECUM_STATE_WAKEUP_WAKESLEEP)
            && (CurrentState != ECUM_STATE_WAKEUP_TTII)
            && (CurrentState != ECUM_STATE_GO_SLEEP)
            && (CurrentState != ECUM_STATE_GO_OFF_ONE)
            && (CurrentState != ECUM_STATE_GO_OFF_TWO)
            && (CurrentState != ECUM_STATE_RESET)
            && (CurrentState != ECUM_STATE_OFF))
    {
        BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_ECUM_INDICATION_PORT_NUM > 0)
        BSWM_ATOMIC_WRITE(&(BswM_EcuMMode), CurrentState);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
        if(BswM_EcuMModeMultiCore == FALSE)
#endif
        {
            BswM_ArbitratePortMappingRules(Port);
        }
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_EcuM_CurrentWakeup  SWS_BswM_00131
*
* Description:   Function called by EcuM to indicate the current state of a wakeup source
*
* Inputs:        source  Wakeup source(s) that changed state
*                   state The new state of the wakeup source(s)
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_EcuM_CurrentWakeup
(
    EcuM_WakeupSourceType source,
    EcuM_WakeupStatusType state
)
{
#if(BSWM_ECUM_WKUPSRC_PORT_NUM >0)
    BswMPortType Port;
    uint8 src;
#endif
    /*SWS_BswM_00132*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTWAKEUP_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00133*/
    else if(state >= (EcuM_WakeupStatusType)ECUM_WKSTATUS_MAX)
    {
        BSWM_DET_REPORT_ERROR(BSWM_ECUM_CURRENTWAKEUP_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_ECUM_WKUPSRC_PORT_NUM >0)
        for(src = (uint8)0; src < (uint8)BSWM_ECUM_WKUPSRC_PORT_NUM; src++)
        {
            if((source & BswM_WkupSrc[src]) != (EcuM_WakeupSourceType)0)
            {
                BSWM_ATOMIC_WRITE(&(BswM_EcuMWkupSrcStatus[src]), state);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_EcuMWkupSrcStatusMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_ECUM_WKUPSRC_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                /*No need break, because source parameter may contain multiple wake-up source.*/
            }
        }
#endif
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_EcuM_RequestedState  SWS_BswM_91004
*
* Description:   Function called by EcuM to notify about current Status of the
*                Run Request Protocol.
*
* Inputs:        State - The requested state by EcuMFlex.
*                CurrentStatus - Result of the Run Request Protocol
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_EcuM_RequestedState
(
    EcuM_StateType State,
    EcuM_RunStatusType CurrentStatus
)
{
#if(BSWM_ECUM_PORT_NUM > 0)   
    BswMPortType Port = BSWM_MAP_ECUM_TO_PORT();
#endif
    /*SWS_BswM_00227*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_ECUM_REQUESTEDSTATE_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00228*/
    else if((State != ECUM_STATE_SHUTDOWN) && (State != ECUM_STATE_APP_POST_RUN) \
            && (State != ECUM_STATE_APP_RUN))
    {
        BSWM_DET_REPORT_ERROR(BSWM_ECUM_REQUESTEDSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    /*SWS_BswM_00229*/
    else if((CurrentStatus != ECUM_RUNSTATUS_RELEASED) && (CurrentStatus != ECUM_RUNSTATUS_REQUESTED))
    {
        BSWM_DET_REPORT_ERROR(BSWM_ECUM_REQUESTEDSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_ECUM_PORT_NUM > 0)
        if((ECUM_STATE_SHUTDOWN == State) && (ECUM_RUNSTATUS_RELEASED == CurrentStatus))
        {
            BSWM_ATOMIC_WRITE(&(BswM_EcuMRequestMode), State);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
            if(BswM_EcuMRequestModeMultiCore == FALSE)
#endif
            {
                BswM_ArbitratePortMappingRules(Port);
            }
        }
        else if((ECUM_STATE_APP_POST_RUN == State) && (ECUM_RUNSTATUS_RELEASED == CurrentStatus) )
        {
            BSWM_ATOMIC_WRITE(&(BswM_EcuMRequestMode), State);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
            if(BswM_EcuMRequestModeMultiCore == FALSE)
#endif
            {
                BswM_ArbitratePortMappingRules(Port);
            }
        }
        else if((ECUM_STATE_APP_RUN == State) && (ECUM_RUNSTATUS_REQUESTED == CurrentStatus) )
        {
            BSWM_ATOMIC_WRITE(&(BswM_EcuMRequestMode), State);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
            if(BswM_EcuMRequestModeMultiCore == FALSE)
#endif
            {
                BswM_ArbitratePortMappingRules(Port);
            }
        }
        else
        {
            BSWM_DET_REPORT_ERROR(BSWM_ECUM_REQUESTEDSTATE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
        }
#endif
    }
}
#endif


/*SWS_BswM_00165*/
#if(STD_ON == BSWM_J1939DCM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_J1939DcmBroadcastStatus  
*
* Description:   This API tells the BswM the desired communication status of the available
*                networks. The status will typically be activated via COM I-PDU group switches.
*
* Inputs:        NetworkMask Mask containing one bit for each available network.
*                            1: Network enabled 0: Network disabled
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_J1939DcmBroadcastStatus
(
    uint16 NetworkMask
)
{
#if(BSWM_J1939DCM_PORT_NUM > 0)
    BswMPortType Port;
    uint16 RefMask;
    uint8 src;
#endif

    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_J1938DCMBROADCASTSTATUS_APIID, BSWM_E_UNINIT);
    }
    else
    {
#if(BSWM_J1939DCM_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_J1939DCM_PORT_NUM; src++)
        {
            RefMask = (uint16)0x01 << (uint16)BswM_J1939DcmBroadcastRef[src];
            if((NetworkMask & RefMask) != (uint16)0)
            {
                BSWM_ATOMIC_WRITE(&(BswM_J1939DcmBroadcast[src]), TRUE);
            }
            else
            {
                BSWM_ATOMIC_WRITE(&(BswM_J1939DcmBroadcast[src]), FALSE);
            }

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
            if(BswM_J1939DcmBroadcastMultiCore[src] == FALSE)
#endif
            {
                Port = BSWM_MAP_J1939_DCM_TO_PORT((BswMPortType)src);
                BswM_ArbitratePortMappingRules(Port);
            }
            /*No need break, because NetworkMask parameter contains multiple channels.*/
        }
#endif
    }
}
#endif
/*SWS_BswM_00194*/
#if(STD_ON == BSWM_J1939NM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_J1939Nm_StateChangeNotification  
*
* Description:   Notification of current J1939Nm state after state changes
*
* Inputs:        Network Identification of the J1939 channel
*                Node Identification of the J1939 node
*                NmState Current (new) state of the J1939 node
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_J1939Nm_StateChangeNotification
(
    NetworkHandleType Network,
    uint8 Node,
    Nm_StateType NmState
)
{
#if(BSWM_J1939NM_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#endif
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_J1938NM_STATECHANGENOTIFICATION_APIID, BSWM_E_UNINIT);
    }
    else if(NmState > NM_STATE_OFFLINE)
    {
        BSWM_DET_REPORT_ERROR(BSWM_J1938NM_STATECHANGENOTIFICATION_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_J1939NM_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_J1939NM_PORT_NUM; src++)
        {
            if((Network == BswM_J1939NmStateChannelRef[src]) && (Node == BswM_J1939NmStateNodeRef[src]))
            {
                BSWM_ATOMIC_WRITE(&(BswM_J1939NmState[src]), NmState);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_J1939NmStateMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_J1939NM_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }
}


#endif
/*SWS_BswM_00104*/
#if(STD_ON == BSWM_NVM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_NvM_CurrentBlockMode  
*
* Description:   Function called by NvM to indicate the current block mode of an NvM block.
*
* Inputs:        Block  The Block that the new NvM Mode corresponds to.
*                   CurrentBlockMode The current block mode of the NvM block.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_NvM_CurrentBlockMode
(
    NvM_BlockIdType Block,
    NvM_RequestResultType CurrentBlockMode
)
{
#if(BSWM_NVM_BLOCK_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#else
    (void)Block;
#endif

    /*SWS_BswM_00109*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_NVM_CURRENTBLOCKMODE_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00110*/
    else if((CurrentBlockMode != NVM_REQ_OK)
            && (CurrentBlockMode != NVM_REQ_NOT_OK)
            && (CurrentBlockMode != NVM_REQ_PENDING)
            && (CurrentBlockMode != NVM_REQ_INTEGRITY_FAILED)
            && (CurrentBlockMode != NVM_REQ_BLOCK_SKIPPED)
            && (CurrentBlockMode != NVM_REQ_NV_INVALIDATED)
            && (CurrentBlockMode != NVM_REQ_CANCELED)
            && (CurrentBlockMode != NVM_REQ_RESTORED_DEFAULTS))
    {
        BSWM_DET_REPORT_ERROR(BSWM_NVM_CURRENTBLOCKMODE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_NVM_BLOCK_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_NVM_BLOCK_PORT_NUM; src++)
        {
            if(Block == BswM_NvMBlockModeRef[src])
            {
                BSWM_ATOMIC_WRITE(&(BswM_NvMBlockMode[src]), CurrentBlockMode);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_NvMBlockModeMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_NVM_BLOCK_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }
}

/*SWS_BswM_00152*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_NvM_CurrentJobMode 
*
* Description:   Function called by NvM to inform the BswM about the current state of a multi
*                    block job.
*
* Inputs:        MultiBlockRequest Indicates which multi block service this callback refers to.  
*                CurrentJobMode Current state of the multi block job indicated by parameter ServiceId.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_NvM_CurrentJobMode
(
    NvM_MultiBlockRequestType MultiBlockRequest,
    NvM_RequestResultType CurrentJobMode
)
{
#if((STD_ON == BSWM_NVM_READALL_SUPPORT) || (STD_ON == BSWM_NVM_WRITEALL_SUPPORT) ||\
    (STD_ON == BSWM_NVM_VALIDATE_ALL_SUPPORT) || (STD_ON == BSWM_NVM_FIRST_INIT_ALL_SUPPORT) ||\
    (STD_ON == BSWM_NVM_CANCEL_WRITE_ALL_SUPPORT))
    BswMPortType Port;
#else
    (void)MultiBlockRequest;
#endif

    /*SWS_BswM_00153*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_NVM_CURRENTJOBMODE_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00154*/
    else if((CurrentJobMode != NVM_REQ_OK)
            && (CurrentJobMode != NVM_REQ_NOT_OK)
            && (CurrentJobMode != NVM_REQ_PENDING)
            && (CurrentJobMode != NVM_REQ_INTEGRITY_FAILED)
            && (CurrentJobMode != NVM_REQ_BLOCK_SKIPPED)
            && (CurrentJobMode != NVM_REQ_NV_INVALIDATED)
            && (CurrentJobMode != NVM_REQ_CANCELED)
            && (CurrentJobMode != NVM_REQ_RESTORED_DEFAULTS))
    {
        BSWM_DET_REPORT_ERROR(BSWM_NVM_CURRENTJOBMODE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(STD_ON == BSWM_NVM_READALL_SUPPORT)
        if(MultiBlockRequest == NVM_READ_ALL)
        {
            BSWM_ATOMIC_WRITE(&(BswM_NvMReadAllStatus), CurrentJobMode);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
            if(BswM_NvMReadAllStatusMultiCore == FALSE)
#endif
            {
                Port = BSWM_MAP_NVM_READ_ALL_JOB_TO_PORT();
                BswM_ArbitratePortMappingRules(Port);
            }
        }
#endif

#if(STD_ON == BSWM_NVM_WRITEALL_SUPPORT)
        if(MultiBlockRequest == NVM_WRITE_ALL)
        {
            BSWM_ATOMIC_WRITE(&(BswM_NvMWriteAllStatus), CurrentJobMode);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
            if(BswM_NvMWriteAllStatusMultiCore == FALSE)
#endif
            {
                Port = BSWM_MAP_NVM_WRITE_ALL_JOB_TO_PORT();
                BswM_ArbitratePortMappingRules(Port);
            }
        }
#endif

#if(STD_ON == BSWM_NVM_VALIDATE_ALL_SUPPORT)
        if(MultiBlockRequest == NVM_VALIDATE_ALL)
        {
            BSWM_ATOMIC_WRITE(&(BswM_NvmValidateAllStatus), CurrentJobMode);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
            if(BswM_NvmValidateAllStatusMultiCore == FALSE)
#endif
            {
                Port = BSWM_MAP_NVM_VALIDDATE_ALL_JOB_TO_PORT();
                BswM_ArbitratePortMappingRules(Port);
            }
        }
#endif

#if(STD_ON == BSWM_NVM_FIRST_INIT_ALL_SUPPORT)
        if(MultiBlockRequest == NVM_FIRSTINIT_ALL )
        {
            BSWM_ATOMIC_WRITE(&(BswM_NvmFirstInitAllStatus), CurrentJobMode);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
            if(BswM_NvmFirstInitAllStatusMultiCore == FALSE)
#endif
            {
                Port = BSWM_MAP_NVM_FIRST_INIT_ALL_JOB_TO_PORT();
                BswM_ArbitratePortMappingRules(Port);
            }
        }
#endif

#if(STD_ON == BSWM_NVM_CANCEL_WRITE_ALL_SUPPORT)
        if(MultiBlockRequest == NVM_CANCEL_ALL)
        {
            BSWM_ATOMIC_WRITE(&(BswM_NvmCancelWriteAllStatus), CurrentJobMode);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
            if(BswM_NvmCancelWriteAllStatusMultiCore == FALSE)
#endif
            {
                Port = BSWM_MAP_NVM_CANCEL_WRITE_ALL_JOB_TO_PORT();
                BswM_ArbitratePortMappingRules(Port);
            }
        }
#endif
    }
}
#endif


/*SWS_BswM_00156*/
#if(STD_ON == BSWM_LINTP_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_LinTp_RequestMode  
*
* Description:   Function called by LinTP to request a mode for the corresponding LIN channel.
*                   The LinTp_Mode mainly correlates to the LIN schedule table that should be used.
*
* Inputs:        Network  The LIN channel that the schedule table switch have occurred on.l
*                   CurrentSchedule The currently active schedule table of the LIN channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_LinTp_RequestMode
(
    NetworkHandleType Network,
    LinTp_Mode LinTpRequestMode
)
{
#if(BSWM_LINTP_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#endif

    /*SWS_BswM_00112*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_LINTP_REQUESTMODE_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00113*/
    else if(LinTpRequestMode > LINTP_DIAG_RESPONSE)
    {
        BSWM_DET_REPORT_ERROR(BSWM_LINTP_REQUESTMODE_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_LINTP_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_LINTP_PORT_NUM; src++)
        {
            if(Network == BswM_LinTpModeRef[src])
            {
                BSWM_ATOMIC_WRITE(&(BswM_LinTpMode[src]), LinTpRequestMode);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_LinTpModeMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_LINTP_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }
}
#endif

#if(STD_ON == BSWM_NM_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_Nm_CarWakeUpIndication  SWS_BswM_00235
*
* Description:   Function called by Nm to indicate a CarWakeup
*
* Inputs:        Network  Identification of the Nm-Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_Nm_CarWakeUpIndication
(
    NetworkHandleType Network
)
{
#if(BSWM_NM_CAR_WKUP_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#else
    (void)Network;
#endif

    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_NM_CARWAKEUPINDICATION_APIID, BSWM_E_UNINIT);
    }
    else
    {
#if(BSWM_NM_CAR_WKUP_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_NM_CAR_WKUP_PORT_NUM; src++)
        {
            if(Network == BswM_NmCarWakeupIndRef[src])
            {
                BSWM_ATOMIC_WRITE(&(BswM_NmCarWakeupInd[src]), TRUE);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_NmCarWakeupIndMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_NM_CAR_WKUP_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }
}
/*SWS_BswM_91002*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_Nm_StateChangeNotification  
*
* Description:   Notification of current Nm state after state changes.
*
* Inputs:        Network       Identification of the Nm-Channel
*                currentState  Current (new) state of the Nm-channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_Nm_StateChangeNotification                          
(
    NetworkHandleType Network,
    Nm_StateType currentState
)
{
#if(BSWM_NM_STATECHANGENOTIFICATION_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#else
    (void)Network;
#endif

    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_NM_STATECHANGENOTIFICATION_APIID, BSWM_E_UNINIT);
    }
    else if(currentState > NM_STATE_OFFLINE)
    {
        BSWM_DET_REPORT_ERROR(BSWM_NM_STATECHANGENOTIFICATION_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_NM_STATECHANGENOTIFICATION_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_NM_STATECHANGENOTIFICATION_PORT_NUM; src++)
        {
            if(Network == BswM_NmStateRef[src])
            {
                BSWM_ATOMIC_WRITE(&(BswM_NmState[src]), currentState);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_NmStateMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_NM_STATECHANGENOTIFICATION_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }
}
#endif

/*SWS_BswM_91001*/
#if(STD_ON == BSWM_ETHIF_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_EthIf_PortGroupLinkStateChg  
*
* Description:   Function called by EthIf to indicate the link state change of a certain Ethernet switch port group.
*
* Inputs:        PortGroupIdx    The port group index in the context of the Ethernet Interface
*                PortGroupState  The state of the port group. 
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_EthIf_PortGroupLinkStateChg                   
(
    EthIf_SwitchPortGroupIdxType PortGroupIdx,
    EthTrcv_LinkStateType PortGroupState
)
{
#if(BSWM_ETHIF_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#endif    
    /*SWS_BswM_00267*/
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_ETHIF_PORTGROUPLINKSTATECHG_APIID, BSWM_E_UNINIT);
    }
    /*SWS_BswM_00268*/
    else if(PortGroupState > ETHTRCV_LINK_STATE_ACTIVE)
    {
        BSWM_DET_REPORT_ERROR(BSWM_ETHIF_PORTGROUPLINKSTATECHG_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_ETHIF_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_ETHIF_PORT_NUM; src++)
        {
            if(PortGroupIdx == BswM_EthIf_PortGroupStateRef[src])
            {
                BSWM_ATOMIC_WRITE(&(BswM_EthIf_PortGroupState[src]), PortGroupState);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_EthIf_PortGroupStateMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_ETHIF_LINKSTATECHG_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }
}
#endif

/*SWS_BswM_91005*/
#if(STD_ON == BSWM_SOAD_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_SoAd_SoConModeChg  
*

* Description:   Function called by SoAd to notify state changes of a socket connection2
*
* Inputs:        SoConId  The socket connection index.
*                State    The state of the SoAd socket connection
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_SoAd_SoConModeChg                 
(
    SoAd_SoConIdType SoConId,
    SoAd_SoConModeType State
)
{
#if(BSWM_SOAD_SOCONMODECHG_PORT_NUM > 0)
    BswMPortType Port;
    uint8 src;
#endif

    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_SOAD_SOCONMODECHG_APIID, BSWM_E_UNINIT);
    }
    else if(State > SOAD_SOCON_ONLINE)
    {
        BSWM_DET_REPORT_ERROR(BSWM_SOAD_SOCONMODECHG_APIID, BSWM_E_REQ_MODE_OUT_OF_RANGE);
    }
    else
    {
#if(BSWM_SOAD_SOCONMODECHG_PORT_NUM > 0)
        for(src = (uint8)0; src < (uint8)BSWM_SOAD_SOCONMODECHG_PORT_NUM; src++)
        {
            if(SoConId == BswM_SoAd_SoConRef[src])
            {
                BSWM_ATOMIC_WRITE(&(BswM_SoAd_SoCon[src]), State);

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
                if(BswM_SoAd_SoConMultiCore[src] == FALSE)
#endif
                {
                    Port = BSWM_MAP_SOAD_SOCONMODECHG_TO_PORT((BswMPortType)src);
                    BswM_ArbitratePortMappingRules(Port);
                }
                break;
            }
        }
#endif
    }
}
#endif



#if(STD_ON == BSWM_MULTIPATITION_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_BswMPartitionRestarted  SWS_BswM_00193
*
* Description:   Function called by Restart Task if the partition containing the BswM has been
*                restarted.
*
* Inputs:        BswM_ModeGroupType switched_modeGroup,
*                BswM_ModeType switched_mode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_BswMPartitionRestarted
(
    void
)
{
#if(BSWM_PARTITION_RESTARTED_PORT_NUM > 0)
    BswMPortType Port = BSWM_MAP_PARTITION_RESTARTED_TO_PORT();
#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
    uint8 PartitionID = BSWM_GET_CORE_ID();
#else
    uint8 PartitionID = 0;
#endif 
#endif
    if(STD_INITIALIZED != BswM_InitStatus)
    {
        BSWM_DET_REPORT_ERROR(BSWM_BSWMPARTITIONRESTARTED_APIID, BSWM_E_UNINIT);
    }
    else
    {
#if(BSWM_PARTITION_RESTARTED_PORT_NUM > 0)
#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
        if(BswM_PartitionRestartedMultiCore[PartitionID] == TRUE)
        {
            BswM_PartitionRestarted[PartitionID] = TRUE;
        }
        else
        {
            BswM_PartitionRestarted[PartitionID] = TRUE;
        }
#else
        BswM_PartitionRestarted[PartitionID] = TRUE;
#endif
        BswM_ArbitratePortMappingRules(Port);
#endif
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_SetRulesAsDeffer
*
* Description:   This function used to set all rules releated to the port as deffered.
*
* Inputs:        CoreId: Core identifier
*                Port
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_SetRulesAsDeffer
(
    uint8 CoreId,
    BswMPortType Port
)
{
    BswMRuleType RuleIdx;
    BswMRuleType RuleId;
    BswMRuleType StartRuleIdx;
    BswMRuleType EndRuleIdx;

    StartRuleIdx = BswMPortMappingRulesStart[Port];
    EndRuleIdx = StartRuleIdx + BswMPortMappingRulesNum[Port];

    SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_2();

    for(RuleIdx = StartRuleIdx; RuleIdx < EndRuleIdx; RuleIdx++)
    {
        RuleId = BswMPortMappingRules[RuleIdx];

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
        if(BswMAvailableRules[RuleId].CoreId == CoreId)
#endif
        {
            if(!BSWM_RULE_IS_DEFERRED(RuleId))
            {
                BSWM_RULE_SET_DEFERRED(RuleId);
                /*PRQA S 3383 ++*/
                /*A wraparound guard cannot be identified for the given unsigned arithmetic expression.*/
                BswMRuleDeferredCnt[CoreId]++;
                /*PRQA S 3383 --*/
            }
        }
    }

    SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_2();
}

#if(STD_ON == BSWM_TIMER_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_SetTimer
*
* Description:   This routine set the BswM internal timer.
*
* Inputs:        TimerValue: Timer value to be set.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_SetTimer
(
    uint8 TimerID,
    uint16 TimerValue
)
{
    /*SWS_BswM_00262*/
    SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_1();

    BswM_Timer[TimerID] = TimerValue;
    BswM_TimerMode[TimerID] = BSWM_TIMER_STARTED;

    SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_1();
}
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_StopTimer
*
* Description:   This routine stop the BswM internal timer.
*
* Inputs:        TimerValue: Timer value to be set.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_StopTimer
(
    uint8 TimerID
)
{   
    SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_1();
    /*SWS_BswM_00265*/
    BswM_Timer[TimerID] = (uint16)0;
    BswM_TimerMode[TimerID] = BSWM_TIMER_STOPPED;

    SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_1();
}
#endif
/*SWS_BswM_00002*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_Init  
*
* Description:   This routine Initializes the BSW Mode Manager for the further processing.
*
* Inputs:        ConfigPtr: Pointer to configuration parameter set,
*                           used e.g. for post build parameters
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_Init
(
    P2CONST(BswM_ConfigType, AUTOMATIC, BSWM_CONST) ConfigPtr
)
{
    BswMRuleType RuleId;
    BswMRuleType StartRuleId;
    BswMRuleType EndRuleId;
    BswMPortType PortId = (BswMPortType)0;
#if(STD_ON == BSWM_TIMER_ENABLED)
    uint8 TimerId;
#endif
    uint8 CoreID;
    uint8 CurCoreID = (uint8)0;
#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
    CurCoreID = BSWM_GET_CORE_ID();

    if(BSWM_MASTER_CORE_ID == CurCoreID)
#endif
    {
#if(BSWM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        if(NULL_PTR == ConfigPtr)
        {
            BSWM_DET_REPORT_ERROR(BSWM_INIT_APIID, BSWM_E_PARAM_POINTER);
        }
        else
        {
            BswM_ConfigSet = ConfigPtr;
#else
            (void) ConfigPtr;
#endif
            /*Check if configuration is valid*/
            for(PortId = (BswMPortType)0; PortId < (BswMPortType)BSWM_MAX_PORT_NUM; PortId++)
            {
                if((BswMRuleType)(BswMPortMappingRulesStart[PortId] + BswMPortMappingRulesNum[PortId]) > BSWM_MAX_PORT_MAPPING_RULE_NUM)
                {
                    BSWM_DET_REPORT_ERROR(BSWM_INIT_APIID, BSWM_E_PARAM_CONFIG);
                }
            }
#if(BSWM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        }
#endif
        /*PortId >= BSWM_MAX_PORT_NUM means configuration is valid*/
        if(PortId >= (BswMPortType)BSWM_MAX_PORT_NUM)/*PRQA S 2991,2995*/
        {
            /*SWS_BswM_00044*/
            for(RuleId = (BswMRuleType)0; RuleId < (BswMRuleType)BSWM_MAX_RULE_NUM; RuleId++)
            {
                BswMRuleState[RuleId] = BswMAvailableRules[RuleId].RuleInitState;
                BSWM_RULE_SET_UNDEFERRED(RuleId);
            }

#if(STD_ON == BSWM_TIMER_ENABLED)
            for(TimerId = (uint8)0; TimerId < BSWM_MAX_TIMER_NUM; TimerId++)
            {
                BswM_Timer[TimerId] = (uint32)0;
                BswM_TimerMode[TimerId] = BSWM_TIMER_STOPPED;
            }
#endif

            for(CoreID = (uint8)0; CoreID < (uint8)BSWM_USED_CORE_NUMBER; CoreID++)
            {
                BSWM_UNLOCK(CoreID);
                BswMRuleDeferredCnt[CoreID] = (uint16)0;
            }

            BswM_InitStatus = STD_INITIALIZED;
#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
            BswMCoreWaitFlag = TRUE;
#endif
        }
    }

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
    while(BswMCoreWaitFlag == FALSE)/*PRQA S 2481,3442*/
    {
        /*The slave core needs to wait for the master core to complete initialization.*/
    }
#endif
    /*Arbitrate all rules releated to current core with their default value*/
    StartRuleId = BSWM_CORE_RULE_START(CurCoreID);
    EndRuleId = BSWM_CORE_RULE_END(CurCoreID);

    for(RuleId = StartRuleId; RuleId <= EndRuleId; RuleId++)
    {
        (void)BswM_ArbitrateRule(CurCoreID, RuleId);
    }
}
/*SWS_BswM_00119*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_Deinit  
*
* Description:   This routine Deinitializes the BSW Mode Manager.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_Deinit
(
    void
)
{
#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
    if(BSWM_MASTER_CORE_ID == BSWM_GET_CORE_ID())
#endif
    {
        /*SWS_BswM_00120*/
        BswM_InitStatus = STD_UNINITIALIZED;
    }
}


/*******************************************************************************
*   Callback Functions
*******************************************************************************/

/*******************************************************************************
*    Scheduled Functions
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: BswM_MainFunction  SWS_BswM_00053
*
* Description:   Main function of the BswM
*
* Inputs:         None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSWM_CODE) BswM_MainFunction
(
    void
)
{
    BswMRuleType RuleId;
    BswMRuleType StartRuleId;
    BswMRuleType EndRuleId;
    PriorityIdType PriIdx;
    BswMActionListIdType ActionListId;
    DeferALCountType ALIndex;
    DeferALCountType ALCount;
#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
    uint8 CurCoreID = BSWM_GET_CORE_ID();
#else
    uint8 CurCoreID = (uint8)0;
#endif

    /*SWS_BswM_00076 return immediately without performing any action and without reporting an error*/
    if(STD_INITIALIZED == BswM_InitStatus)
    {
#if(STD_ON == BSWM_TIMER_ENABLED)
        /*SWS_BswM_00263*/
        BswM_TimerMainFunction(CurCoreID);
#endif

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
        BswM_CrossCorePortCheck(CurCoreID);
#endif
        /*SWS_BswM_00068*/
        BSWM_LOCK(CurCoreID);
        for(PriIdx = (PriorityIdType)0; PriIdx < (PriorityIdType)BSWM_MAX_PRIORITY_NUM; PriIdx++)
        {
            BswM_PriorityActionList[CurCoreID][PriIdx].DeferALCount = (DeferALCountType)0;
        }
        /*Loop control variable in this 'while' statement, BswMRuleDeferredCnt, has file scope.
          This is a must, since the BswM_ImmediateRunRule may increase BswMRuleDeferredCnt, and 
          this while loop can only exit after the BswMRuleDeferredCnt decreased to zero*/
        StartRuleId = BSWM_CORE_RULE_START(CurCoreID);
        EndRuleId = BSWM_CORE_RULE_END(CurCoreID);
        /*PRQA S 2481 ++*/
        while(BswMRuleDeferredCnt[CurCoreID] > (uint16)0)
        /*PRQA S 2481 --*/
        {
            /*ATTENTION !!!!!!!!*/
            /*If the program enters this while loop and cannot exit, 
              please enable the BSWM_EXCLUSIVE_AREA_2() protection function in the Configurator*/
            /*SWS_BswM_00060*/
            for(RuleId = StartRuleId; RuleId <= EndRuleId; RuleId++)
            {
                if(BSWM_RULE_IS_DEFERRED(RuleId))
                {
                    SchM_Enter_BswM_BSWM_EXCLUSIVE_AREA_2();
                    BSWM_RULE_SET_UNDEFERRED(RuleId);
                    BswMRuleDeferredCnt[CurCoreID]--;
                    SchM_Exit_BswM_BSWM_EXCLUSIVE_AREA_2();
                    /*Enforce the rule.*/
                    BswM_DeferredRunRule(RuleId);
                }
            }
        }

        do
        {
            /*PRQA S 3383 ++*/
            /*PriIdx-- and ALIndex++  won't go beyond the range*/
            PriIdx--;
            ALIndex = (DeferALCountType)0;
            ALCount = BswM_PriorityActionList[CurCoreID][PriIdx].DeferALCount;
            /*Run Action List*//*SWS_BswM_00275*/
            while(ALCount > ALIndex)
            {
                ActionListId = BswM_PriorityActionList[CurCoreID][PriIdx].DeferActionList[ALIndex];
                (void)BswM_RunActionList(ActionListId);
                ALIndex++;
            }
            /*PRQA S 3383 --*/
        } while(PriIdx > (PriorityIdType)0);/*PRQA S 2993,2996*/

        BSWM_UNLOCK(CurCoreID);
    }
}


#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"

