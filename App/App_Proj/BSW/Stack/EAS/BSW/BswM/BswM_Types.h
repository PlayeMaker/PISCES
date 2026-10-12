/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : BswM_Types.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : BswM_Types.h
*   Author          : Hirain
********************************************************************************
*   Description     : The header file BswM_Types.h contains the  common type
*                     definitions of the module BSW Mode Manager
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
* END_FILE_HDR*/
#ifndef BSWM_TYPES_H
#define BSWM_TYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Std_Types.h"
#include "BswM_Cfg.h"

/*******************************************************************************
*   Type define
*******************************************************************************/
typedef uint16 BswMRuleType;
typedef uint16 BswMPortType;
typedef uint16 BswMActionListIdType;
typedef uint16 PriorityIdType;
typedef uint16 DeferALCountType;
typedef P2FUNC(Std_ReturnType, BSWM_CODE, BswM_ActionFuncType)(void);

/*BswM_Timer Status*/
typedef uint8 BswM_TimerState;
#define BSWM_TIMER_STOPPED     (BswM_TimerState)0
#define BSWM_TIMER_STARTED     (BswM_TimerState)1
#define BSWM_TIMER_EXPIRED     (BswM_TimerState)2

typedef enum
{
    BSWM_FALSE = 0,
    BSWM_TRUE = 1,
    BSWM_UNDEFINED = 0xff
} BswMRuleStateType;


typedef P2FUNC(BswMRuleStateType, BSWM_CODE, BswMRuleFuncType)(void);
typedef uint16 BswM_UserType;
typedef uint16 BswM_ModeType;


typedef enum
{
    BSWM_DEFERRED = 0,
    BSWM_IMMEDIATE = 1
} BswMRequestProcessingType;

typedef enum
{
    BSWM_CONDITION = 0,
    BSWM_TRIGGER = 1
} BswMActionListExecutionType;

typedef enum
{
    BSWM_ACTION,
    BSWM_ACTIONLIST,
    BSWM_RULE
} BswMActionType;

/*PRQA S 602++*/
/*_sBswMActionListItem name is specific writing.*/
typedef struct _sBswMActionListItem
{
#if(STD_ON == BSWM_ABORTONFAIL_ENABLED)
    boolean AbortOnFail;                  /*ECUC_BswM_00902*/
#endif
    BswMActionType ActionType;
    BswM_ActionFuncType ActionFunc;     /*ECUC_BswM_00825*/
    BswMActionListIdType ActionListId;
    BswMRuleType RuleId;
#if(STD_ON == BSWM_ERRORID_ENABLED)
    uint16 ErrorId;
#endif
    P2CONST(struct _sBswMActionListItem, AUTOMATIC, BSWM_CONST) next;
} BswM_ActionListItemType;
/*PRQA S 602--*/

typedef struct
{
    BswMActionListExecutionType Excution;
    P2CONST(BswM_ActionListItemType, AUTOMATIC, BSWM_CONST) ActionListHead;
    PriorityIdType PriorityId;
} BswMActionList;


/*ECUC_BswM_00806*/
typedef struct
{
    BswMRuleStateType RuleInitState;          /*ECUC_BswM_00888*/
    BswMRuleFuncType RuleFunc;                /*ECUC_BswM_00819*/
    BswMActionListIdType RuleTrueActionList;  /*ECUC_BswM_00817*/
    BswMActionListIdType RuleFalseActionList; /*ECUC_BswM_00818*/
    BswMRequestProcessingType RequestProcessing;
#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
    uint8 CoreId;
#endif
} BswM_RuleCfgType;

typedef struct
{
    BswMActionListIdType DeferActionList[BSWM_MAX_RULE_NUM];
    DeferALCountType DeferALCount;
} BswM_PriorityALType;

#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
typedef P2FUNC(void, BSWM_CODE, BswM_CrossCorePortCheckFuncType)(void);

typedef struct
{
    BswM_CrossCorePortCheckFuncType CrossCorePortCheckFunc;
    BswMRuleType CoreRuleStart;
    BswMRuleType CoreRuleEnd;
} BswM_CoreInfoType;
#endif

/*SWS_BswM_00213 SWS_BswM_00042*/
typedef struct
{
#if(BSWM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
    uint8 unused;
#else
#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)
    BswM_CoreInfoType CoreInfoTable[BSWM_USED_CORE_NUMBER];
#if(BSWM_CANSM_PORT_NUM > 0)
    boolean CanSMModeMultiCore[BSWM_CANSM_PORT_NUM];
#endif
#if(BSWM_COMM_PORT_NUM > 0)
    boolean ComMModeMultiCore[BSWM_COMM_PORT_NUM];
#endif
#if(BSWM_COMM_PNC_PORT_NUM > 0)
    boolean ComMPNCModeMultiCore[BSWM_COMM_PNC_PORT_NUM];
#endif
#if(BSWM_COMM_RESET_PORT_NUM > 0)
    boolean ComMInitiateResetMultiCore;
#endif
#if(BSWM_DCM_PORT_NUM > 0)
    boolean DcmComMModeMultiCore[BSWM_DCM_PORT_NUM];
#endif
#if(BSWM_DCM_APP_UPDATE_PORT_NUM > 0)
    boolean DcmAppUpdatedMultiCore;
#endif
#if(BSWM_ECUM_INDICATION_PORT_NUM > 0)
    boolean EcuMModeMultiCore;
#endif
#if(BSWM_ECUM_WKUPSRC_PORT_NUM >0)
    boolean EcuMWkupSrcStatusMultiCore[BSWM_ECUM_WKUPSRC_PORT_NUM];
#endif
#if(BSWM_ECUM_PORT_NUM > 0)
    boolean EcuMRequestModeMultiCore;
#endif
#if(BSWM_ETHIF_PORT_NUM > 0)
    boolean EthIf_PortGroupStateMultiCore[BSWM_ETHIF_PORT_NUM];
#endif
#if(BSWM_ETHSM_PORT_NUM > 0)
    boolean EthSMModeMultiCore[BSWM_ETHSM_PORT_NUM];
#endif
#if(BSWM_FRSM_PORT_NUM > 0)
    boolean FrSMModeMultiCore[BSWM_FRSM_PORT_NUM];
#endif
#if(BSWM_J1939DCM_PORT_NUM > 0)
    boolean J1939DcmBroadcastMultiCore[BSWM_J1939DCM_PORT_NUM];
#endif
#if(BSWM_J1939NM_PORT_NUM > 0)
    boolean J1939NmStateMultiCore[BSWM_J1939NM_PORT_NUM];
#endif
#if(BSWM_LINSM_PORT_NUM > 0)
    boolean LinSMModeMultiCore[BSWM_LINSM_PORT_NUM];
#endif
#if(BSWM_LINSM_SCH_PORT_NUM > 0)
    boolean LinSMSchMultiCore[BSWM_LINSM_SCH_PORT_NUM];
#endif
#if(BSWM_LINTP_PORT_NUM > 0)
    boolean LinTpModeMultiCore[BSWM_LINTP_PORT_NUM];
#endif
#if(BSWM_NM_CAR_WKUP_PORT_NUM > 0)
    boolean NmCarWakeupIndMultiCore[BSWM_NM_CAR_WKUP_PORT_NUM];
#endif
#if(BSWM_NM_STATECHANGENOTIFICATION_PORT_NUM > 0)
    boolean NmStateMultiCore[BSWM_NM_STATECHANGENOTIFICATION_PORT_NUM];
#endif
#if(BSWM_NVM_BLOCK_PORT_NUM > 0)
    boolean NvMBlockModeMultiCore[BSWM_NVM_BLOCK_PORT_NUM];
#endif
#if(STD_ON == BSWM_NVM_READALL_SUPPORT)
    boolean NvMReadAllStatusMultiCore;
#endif
#if(STD_ON == BSWM_NVM_WRITEALL_SUPPORT)
    boolean NvMWriteAllStatusMultiCore;
#endif
#if(STD_ON == BSWM_NVM_VALIDATE_ALL_SUPPORT)
    boolean NvmValidateAllStatusMultiCore;
#endif
#if(STD_ON == BSWM_NVM_FIRST_INIT_ALL_SUPPORT)
    boolean NvmFirstInitAllStatusMultiCore;
#endif
#if(STD_ON == BSWM_NVM_CANCEL_WRITE_ALL_SUPPORT)
    boolean NvmCancelWriteAllStatusMultiCore;
#endif
#if(BSWM_SD_CS_PORT_NUM > 0)
    boolean SdCSStateMultiCore[BSWM_SD_CS_PORT_NUM];
#endif
#if(BSWM_SD_EVENTGROUP_PORT_NUM > 0)
    boolean SdEventGroupStateMultiCore[BSWM_SD_EVENTGROUP_PORT_NUM];
#endif
#if(BSWM_SD_EVENTHANDLER_PORT_NUM > 0)
    boolean SdEventHandlerStateMultiCore[BSWM_SD_EVENTHANDLER_PORT_NUM];
#endif
#if(BSWM_SOAD_SOCONMODECHG_PORT_NUM > 0)
    boolean SoAdSoConMultiCore[BSWM_SD_EVENTHANDLER_PORT_NUM];
#endif
#if(BSWM_GENERAL_PORT_NUM > 0)
    boolean GeneralPortModeMultiCore[BSWM_GENERAL_PORT_NUM];
#endif
#endif/*#if(STD_ON == BSWM_MULTI_CORE_SUPPORT)*/

    const BswMRuleType *PortMappingRulesStart;/*BSWM_MAX_PORT_NUM*/
    const BswMRuleType *PortMappingRulesNum;/*BSWM_MAX_PORT_NUM*/
    BswMRuleType PortMappingRuleNum;
    const BswMRuleType *PortMappingRules;/*BswMPortMappingRuleNum*/
    BswMRuleType RuleNum;
    const BswM_RuleCfgType *AvailableRules;/*BswMRuleNum*/
#endif/*(BSWM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)*/
} BswM_ConfigType;


#endif/* BSWM_TYPES_H */

