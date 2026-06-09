/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : ComM.c
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : ComM.c
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of ComM provided functionality
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials       CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   04.00.00    10/11/2022    Feixiang.Dong  N/A          Original
*   04.00.01    01/04/2024    Feixiang.Dong  N/A          QAC
*   04.00.02    19/06/2024    Feixiang.Dong  N/A          QAC
*   04.00.03    06/08/2024    Feixiang.Dong  N/A          EAS470_ComM_20240806_01
********************************************************************************
* END_FILE_HDR*/

/*PRQA S 776 EOF*/
/*
Names in this file may not follow relevant rules.
*/

/*PRQA S 0857 EOF*/
/*
Macro definitions exceed 1024. The number of macros is unlimited
*/

/*PRQA S 3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "ComM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in ComM_MemMap.h
*/

/*PRQA S 2000 EOF*/
/*
When there is only one If,there can be no else.
*/

/*PRQA S 2100,2101 EOF*/
/*
Integer promotion related
*/

/*PRQA S 2742 EOF*/
/*
This 'if' controlling expression is a constant expression and its value is 'false'.
COMM_PNC_ENABLED can be a PreCompile or Link-Time parameter.
*/

/*PRQA S 3119 EOF*/
/*
'(void)parameter;' is written to eliminate the compilation warning.
*/

/*PRQA S 3138,3141 EOF*/
/*
The code of critical segments can be configured as void when QAC testing.
Note:When called by Det,Dem or BswM, the critical segments must be enabled when
QAC testing.Reasons are needed for special circumstances not enabled.
*/

/*PRQA S 3227,3204 EOF*/
/*
Read-only function input parameters may not be defined as const,it does not affect the function.
AUTOSAR API shall define standard input parameters according to specification requirements
*/

/*PRQA S 3352 EOF*/
/*
The case under the switch statement only exsist in certain conditions.
*/

/*PRQA S 3383 EOF*/
/*
The variable doesn't overflow.
*/

/*PRQA S 3416 EOF*/
/*
There's no error when only one branch,but in a statement with &&,|| or multiple
branches,calling a function to determine the return value is not allowed.
*/

/*PRQA S 3453,3429 EOF*/
/*
1.The unified requirement of EAS is that the error reporting functions of Det
and Dem moduls are accessed by macro functions.This part has been verified and
has no problem.
2.Macro functions are allowed to use to access parameters and do some simple operations.
*/

/*PRQA S 3432 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no need to revise.
*/

/*PRQA S 4570,4571 EOF*/
/*
Permission ~ operator, specific implementation methods.
Permission << operator, specific implementation methods.
*/

/*PRQA S 1503,1504 EOF*/
/*
Function declared externally are called by the user.
Variable declared externally are used by the user.
*/

/*PRQA S 2844 EOF*/
/*
Both variables channel and PncId are effectively checked.
*/

/*PRQA S 2880,2877,2992,2889 EOF*/
/*
An internal statement is executed only when the configuration meets the if condition.
Depends on configuration.
Multiple return are allowed.
*/

/*PRQA S 771 EOF*/
/*
Multiple break are allowed.
*/

/*PRQA S 791,792 EOF*/
/*
Macros dont differ within 31 charaters
*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComM.h"
#include "ComM_Nm.h"
#include "ComM_Dcm.h"
#include "ComM_EcuM.h"
#include "ComM_BswM.h"
#include "ComM_BusSM.h"
#include "SchM_ComM.h"
#include "BswM_ComM.h"

#if(STD_ON == COMM_NVM_SUPPORT)
#include "NvM.h"
#endif

#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))
#include "Nm.h"
#endif

#if(STD_ON == COMM_DCM_SUPPORT)
#include "Dcm_ComM.h"
#endif

#if(COMM_NUM_OF_CAN_CHANNEL > 0)
#include "CanSM_ComM.h"
#endif

#if(COMM_NUM_OF_LIN_CHANNEL > 0)
#include "LinSM.h"
#endif

#if(COMM_NUM_OF_FR_CHANNEL > 0)
#include "FrSM.h"
#endif

#if(COMM_NUM_OF_ETH_CHANNEL > 0)
#include "EthSM.h"
#endif

#if(STD_ON == COMM_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*******************************************************************************
*   Configuration Check
*******************************************************************************/
#if(STD_ON == COMM_VERSION_CHECK)
/* check Version with cfg file */
#if((COMM_AR_RELEASE_MAJOR_VERSION != COMM_AR_RELEASE_MAJOR_VERSION_CFG) || \
    (COMM_AR_RELEASE_MINOR_VERSION != COMM_AR_RELEASE_MINOR_VERSION_CFG))
#error "AutoSar Version Numbers of ComM and its cfg file are incompatible"
#endif

#if((COMM_SW_MAJOR_VERSION != COMM_SW_MAJOR_VERSION_CFG) || \
    (COMM_SW_MINOR_VERSION != COMM_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of ComM and its cfg file are incompatible"
#endif
#endif/*#if(STD_ON == COMM_VERSION_CHECK)*/



#if((COMM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE) && \
    (COMM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD))
#error "The ComM module only supports Pre-Compile and Post-Build Configuration."
#endif

/*Cfg compatibility check*/
#if(STD_ON == COMM_PNC_SUPPORT)
/*SWS_ComM_00920*/
#if(COMM_NUM_OF_PNC > 504)
#error "The number of PNCs cannot exceed 504 !!!"
#endif

#if(COMM_NUM_OF_PNC == 0)
#error "The number of PNCs cannot be 0 if ComMPncSupport parameter is true !!!"
#endif
#endif

#if(COMM_MAX_USER_MAPPING_CHANNEL > 255)
#error "The mapping path between Channel and User cannot be greater than 255 !!!"
#endif

#if(COMM_MAX_CHANNEL_MAPPING_USER > 255)
#error "The mapping path between Channel and User cannot be greater than 255 !!!"
#endif

#if((COMM_NUM_OF_INTERNAL_CHANNEL > 0) && (STD_OFF == COMM_NMVARIANT_NONE_ENABLED))
#error "When the channel type is INTERNAL, the ComMNmVariant parameter should be set to NONE !!!"
#endif

#if((STD_OFF == COMM_PNC_GW_ENABLED) && (STD_ON == COMM_SYNC_PNC_SHUTDOWN_ENABLED))
#error "If you want to use the PNC synchronization shutdown function, the PNC gateway function must be enabled !!!"
#endif

/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == COMM_DEV_ERROR_DETECT)
#define  COMM_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(COMM_MODULE_ID, COMM_INSTANCE_ID, (ApiId), (errcode))
#else
#define  COMM_DET_REPORT_ERROR(ApiId, errcode)
#endif

/*Configuration parameters*/
#if(COMM_NUM_OF_USER > 0)
/*ECUC_ComM_00657*//*ECUC_ComM_00658*//*User mapping to Channel*/
#define COMM_CFG_USER_MAP_CHL_START(User)        (ComM_UserMappingChannelStart[User])
#define COMM_CFG_USER_MAP_CHL_NUM(User)          (ComM_UserMappingChannelNum[User])
#define COMM_CFG_USER_MAP_CHL(Idx)               (ComM_UserMappingChannel[Idx])
/*ECUC_ComM_00657*//*ECUC_ComM_00658*//*Channel mapping to User*/
#define COMM_CFG_CHL_MAP_USER_START(Channel)     (ComM_ChannelMappingUserStart[Channel])
#define COMM_CFG_CHL_MAP_USER_NUM(Channel)       (ComM_ChannelMappingUserNum[Channel])
#define COMM_CFG_CHL_MAP_USER(Idx)               (ComM_ChannelMappingUser[Idx])
#endif

#if(STD_ON == COMM_MULTI_CORE_SUPPORT)
#define COMM_CFG_CHL_MAP_CORE(Channel)           (ComM_ChannelMappingCore[Channel])
#endif

/*ECUC_ComM_00567*/
#define COMM_CFG_CHL_BUS_TYPE(Channel)           (ComM_ChannelBusType[Channel])
#define COMM_CFG_CHL_TO_BUSSM(Channel)           (ComM_ChannelToBusSM[Channel])
/*ECUC_ComM_00556*/
#define COMM_CFG_CHL_MAIN_PRRIOD(Channel)        (ComM_ChannelMainFunctionPeriod[Channel])

#if(STD_ON == COMM_DYN_PNC_TO_CHL_MAP_SUPPORT)
/*ECUC_ComM_00896*/
#define COMM_CFG_CHL_DYN_PNC_MAP(Channel)        (ComM_ChannelDynamicPncToChannelMappingEnabled[Channel])
#endif
/*ECUC_ComM_00787*/
#define COMM_CFG_CHL_FULL_REQ_NOTIFY(Channel)    (ComM_ChannelFullCommRequestNotificationEnabled[Channel])
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
/*ECUC_ComM_00571*//*SWS_ComM_00690*/
#define COMM_CFG_CHL_NO_COM(Channel)             (ComM_ChannelNoCom[Channel])
#endif
#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
/*ECUC_ComM_00569*/
#define COMM_CFG_CHL_NO_WAKEUP(Channel)          (ComM_ChannelNoWakeup[Channel])
/*ECUC_ComM_00789*/
#define COMM_CFG_CHL_NO_WAKEUP_STORAGE(Channel)  (ComM_ChannelNoWakeUpInhibitionNvmStorage[Channel])
#endif
#if(STD_ON == COMM_PNC_SUPPORT)
/*ECUC_ComM_00886*/
#define COMM_CFG_CHL_PNC_NM_REQUEST(Channel)     (ComM_ChannelPncNmRequest[Channel])
#endif
#if(STD_ON == COMM_PNC_GW_ENABLED)
/*ECUC_ComM_00842*/
#define COMM_CFG_CHL_PNC_GW_TYPE(Channel)        (ComM_ChannelPncGatewayType[Channel])
#endif
#if(COMM_NUM_OF_ETH_CHANNEL > 0)
/*ECUC_ComM_00898*/
#define COMM_CFG_CHL_WAKE_SLEEP_EN(Channel)      (ComM_ChannelWakeupSleepRequestEnabled[Channel])
#endif
#if(STD_ON == COMM_NMVARIANT_ENABLED)
/*Nm Variant*/
#define COMM_IS_NMVARIANT_FULL(Channel)          (COMM_NM_FULL == ComM_ChannelNmVariant[Channel])
#define COMM_IS_NMVARIANT_LIGHT(Channel)         (COMM_NM_LIGHT == ComM_ChannelNmVariant[Channel])
#define COMM_IS_NMVARIANT_PASSIVE(Channel)       (COMM_NM_PASSIVE == ComM_ChannelNmVariant[Channel])
#define COMM_IS_NMVARIANT_NONE(Channel)          (COMM_NM_NONE == ComM_ChannelNmVariant[Channel])
#define COMM_IS_NMVARIANT_SLAVE_A(Channel)       (COMM_NM_SLAVE_ACTIVE == ComM_ChannelNmVariant[Channel])
#define COMM_IS_NMVARIANT_SLAVE_P(Channel)       (COMM_NM_SLAVE_PASSIVE == ComM_ChannelNmVariant[Channel])
#else
#define COMM_IS_NMVARIANT_FULL(Channel)          (STD_ON == COMM_NMVARIANT_FULL_ENABLED)
#define COMM_IS_NMVARIANT_LIGHT(Channel)         (STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
#define COMM_IS_NMVARIANT_PASSIVE(Channel)       (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED)
#define COMM_IS_NMVARIANT_NONE(Channel)          (STD_ON == COMM_NMVARIANT_NONE_ENABLED)
#define COMM_IS_NMVARIANT_SLAVE_A(Channel)       (STD_ON == COMM_NMVARIANT_SLAVE_A_ENABLED)
#define COMM_IS_NMVARIANT_SLAVE_P(Channel)       (STD_ON == COMM_NMVARIANT_SLAVE_P_ENABLED)
#endif
#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))
#define COMM_CFG_CHL_TO_NM(Channel)              (ComM_ChannelToNm[Channel])
#endif
#if(STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
/*ECUC_ComM_00606*/
#define COMM_CFG_CHL_LIGHT_TIME(Channel)         (ComM_ChannelNmLightTimeout[Channel])
#endif

/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
#if(COMM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_PRECOMPILE)
/*ECUC_ComM_00876 User mapping to Pnc*/
#define COMM_CFG_USER_MAP_PNC_START(User)        (ComM_UserMappingPncStart[User])
#define COMM_CFG_USER_MAP_PNC_NUM(User)          (ComM_UserMappingPncNum[User])
#define COMM_CFG_USER_MAP_PNC(Idx)               (ComM_UserMappingPnc[Idx])
/*ECUC_ComM_00880 Pnc mapping to Channel*/
#define COMM_CFG_PNC_MAP_CHL_START(PncIdx)       (ComM_PncMappingChannelStart[PncIdx])
#define COMM_CFG_PNC_MAP_CHL_NUM(PncIdx)         (ComM_PncMappingChannelNum[PncIdx])
#define COMM_CFG_PNC_MAP_CHL(Idx)                (ComM_PncMappingChannel[Idx])

#else

/*ECUC_ComM_00878 ComMPncEnabled*/
#define COMM_PNC_ENABLED                         (ComM_ConfigSet->ComMPncEnabled)
/*ECUC_ComM_00876 User mapping to Pnc*/
#define COMM_CFG_USER_MAP_PNC_START(User)        (ComM_ConfigSet->ComMUserMappingPncStart[User])
#define COMM_CFG_USER_MAP_PNC_NUM(User)          (ComM_ConfigSet->ComMUserMappingPncNum[User])
#define COMM_CFG_USER_MAP_PNC(Idx)               (ComM_ConfigSet->ComMUserMappingPnc[Idx])
/*ECUC_ComM_00880 Pnc mapping to Channel*/
#define COMM_CFG_PNC_MAP_CHL_START(PncIdx)       (ComM_ConfigSet->ComMPncMappingChannelStart[PncIdx])
#define COMM_CFG_PNC_MAP_CHL_NUM(PncIdx)         (ComM_ConfigSet->ComMPncMappingChannelNum[PncIdx])
#define COMM_CFG_PNC_MAP_CHL(Idx)                (ComM_ConfigSet->ComMPncMappingChannel[Idx])
#endif/*#if(COMM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_PRECOMPILE)*/

/*ECUC_ComM_00874*/
#define COMM_CFG_PNC_ID(PncIdx)                  (ComM_PncId[PncIdx])

#if(COMM_NUM_OF_ETH_CHANNEL > 0)
/*ECUC_ComM_00899*/
#define COMM_CFG_PNC_WAKE_SLEEP_EN(PncIdx)       (ComM_PncWakeupSleepRequestEnabled[PncIdx])
#endif
#endif/*#if(STD_ON == COMM_PNC_SUPPORT)*/



/*Real time operating parameters*/
#define ComM_EcuGroupClassfication                (ComM_StoredData.ComMEcuGroupClassification)
#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
#define ComM_NoWakeupStatus(Channel)              (ComM_StoredData.ComMNoWakeupStatus[Channel])
#endif
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
#define ComM_InhibitCounter                       (ComM_StoredData.ComMInhibitCounter)
#endif

/*Initialization status*/
#define COMM_IS_INITIALIZED()                    (COMM_INIT == ComM_InitStatus)
#define COMM_SET_INITIALIZED()                   (ComM_InitStatus = COMM_INIT)
#define COMM_SET_UNINITIALIZED()                 (ComM_InitStatus = COMM_UNINIT)
#define COMM_GET_INIT_STATUS()                   (ComM_InitStatus)


/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
/*SWS_ComM_00825*/
#define COMM_GET_PNC_BYTE_INDEX(PncID)           ((uint8)((PncID) >> (uint8)3) - COMM_PNC_BYTE_OFFSET)
#define COMM_GET_PNC_BIT_INDEX(PncID)            (uint8)((PncID) & (PNCHandleType)0x07)
#endif

#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
#define COMM_INHIBIT_COUNTER_MAX_VALUE           ((uint16)65535)
#endif

#if(STD_ON == COMM_PNC_GW_ENABLED)
#define COMM_ERA_RECEIVED_ON_ACTIVE              ((uint8)0x01)
#define COMM_ERA_RECEIVED_ON_PASSIVE             ((uint8)0x02)
#endif


/*Bit Position of ComM_TriggerInfo*/
#define COMM_NM_MODE_IND_MASK                    ((uint16)0x0003)
#define COMM_NETWORK_START_IND_MASK              ((uint16)0x0004)
#define COMM_NM_RESTART_IND_MASK                 ((uint16)0x0008)
#define COMM_LIMIT_TO_NO_COM_MASK                ((uint16)0x0010)
#define COMM_ACTIVE_DIAG_MASK                    ((uint16)0x0020)
#define COMM_WAKEUP_IND_MASK                     ((uint16)0x0040)
/*Only used with the channels whoes type is SLAVE_ACTIVE or SLAVE_PASSIVE*/
#define COMM_SM_BUS_SLEEP_IND_MASK               ((uint16)0x0080)

#define COMM_COM_ALLOWED_IND_MASK                ((uint16)0x8000)

#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))
/*Nm Mode Indication*/
#define COMM_NM_MODE_BUS_SLEEP                   ((uint16)0x01)
#define COMM_NM_MODE_PBS                         ((uint16)0x02)
#define COMM_NM_MODE_NETWORK                     ((uint16)0x03)
#endif





/******************************************************************************
*   Global Vars
******************************************************************************/
#define COMM_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "ComM_MemMap.h"

/*This varible is not static since it will be access by NvM*/
VAR(ComM_StoredDataType, COMM_VAR) ComM_StoredData;

#define COMM_STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "ComM_MemMap.h"

/*******************************************************************************
*   Local Data Define
*******************************************************************************/
#define COMM_START_SEC_VAR_INIT_GLOBAL_8
#include "ComM_MemMap.h"
STATIC VAR(ComM_InitStatusType, COMM_VAR) ComM_InitStatus = COMM_UNINIT;

#define COMM_STOP_SEC_VAR_INIT_GLOBAL_8
#include "ComM_MemMap.h"


#define COMM_START_SEC_VAR_CLEARED_GLOBAL_8
#include "ComM_MemMap.h"

#if(COMM_NUM_OF_USER > 0)
#if(STD_ON == COMM_MULTI_CORE_SUPPORT)
STATIC VAR(ComM_ModeType, COMM_VAR) ComM_UserComMode[COMM_NUM_OF_USER][COMM_NUM_OF_CORES];
STATIC VAR(ComM_ModeType, COMM_VAR) ComM_UserLastComMode[COMM_NUM_OF_USER][COMM_NUM_OF_CORES];
#else
STATIC VAR(ComM_ModeType, COMM_VAR) ComM_UserComMode[COMM_NUM_OF_USER];
#endif
#endif

STATIC VAR(ComM_ModeType, COMM_VAR) ComM_Mode[COMM_NUM_OF_CHANNEL];
STATIC VAR(ComM_StateType, COMM_VAR) ComM_State[COMM_NUM_OF_CHANNEL];
STATIC VAR(boolean, COMM_VAR) ComM_KeepComFlag[COMM_NUM_OF_CHANNEL];
/*Nm request pending flag*/
STATIC VAR(boolean, COMM_VAR) ComM_ReqPendingFlag[COMM_NUM_OF_CHANNEL];
/*BusSM request pending flag*/
STATIC VAR(boolean, COMM_VAR) ComM_BusSM_RequestPending[COMM_NUM_OF_CHANNEL];

STATIC VAR(uint8, COMM_VAR) ComM_UserReqChannelCnt[COMM_NUM_OF_CHANNEL];
STATIC VAR(ComM_ModeType, COMM_VAR) ComM_UserMappingChannelModeReq[COMM_MAX_USER_MAPPING_CHANNEL];

/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
STATIC VAR(ComM_PncModeType, COMM_VAR) ComM_UserMappingPncModeReq[COMM_MAX_USER_MAPPING_PNC];
STATIC VAR(uint8, COMM_VAR) ComM_UserReqPncCnt[COMM_NUM_OF_PNC];

STATIC VAR(ComM_ModeType, COMM_VAR) ComM_PncMappingChannelModeReq[COMM_MAX_PNC_MAPPING_CHANNEL];
STATIC VAR(uint8, COMM_VAR) ComM_PncReqChannelCnt[COMM_NUM_OF_CHANNEL];
/*SWS_ComM_00909*/
STATIC VAR(ComM_PncModeType, COMM_VAR) ComM_PncState[COMM_NUM_OF_PNC];
/*SWS_ComM_00982*/
STATIC VAR(boolean, COMM_VAR) ComM_EiraUpdateFlag;
STATIC VAR(uint8, COMM_VAR) ComM_EiraData[COMM_PNC_DATA_LENGTH];
STATIC VAR(boolean, COMM_VAR) ComM_EiraReqOfPnc[COMM_NUM_OF_PNC];
STATIC VAR(uint8, COMM_VAR) ComM_IraTxData[COMM_NUM_OF_CHANNEL][COMM_PNC_DATA_LENGTH];
#if(STD_ON == COMM_PNC_GW_ENABLED)
STATIC VAR(boolean, COMM_VAR) ComM_EraUpdateFlag;/*PRQA S 3229*/ /* tbd used flag*/
STATIC VAR(NetworkHandleType, COMM_VAR) ComM_PncPassiveChannel[COMM_NUM_OF_PNC];
STATIC VAR(uint8, COMM_VAR) ComM_EraReqOfPnc[COMM_NUM_OF_PNC];
STATIC VAR(uint8, COMM_VAR) ComM_EraData[COMM_NUM_OF_CHANNEL][COMM_PNC_DATA_LENGTH];
#if(STD_ON == COMM_SYNC_PNC_SHUTDOWN_ENABLED)
STATIC VAR(boolean, COMM_VAR) ComM_PncSyncShutdownFlag[COMM_NUM_OF_PNC];
#endif
#endif
STATIC VAR(boolean, COMM_VAR) ComM_PncWakeupFlag[COMM_NUM_OF_PNC];
#endif/*#if(STD_ON == COMM_PNC_SUPPORT)*/

#define COMM_STOP_SEC_VAR_CLEARED_GLOBAL_8
#include "ComM_MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_GLOBAL_16
#include "ComM_MemMap.h"

STATIC VAR(uint16, COMM_VAR) ComM_TriggerInfo[COMM_NUM_OF_CHANNEL];

#define COMM_STOP_SEC_VAR_CLEARED_GLOBAL_16
#include "ComM_MemMap.h"


#define COMM_START_SEC_VAR_CLEARED_LOCAL_32
#include "ComM_MemMap.h"

#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
STATIC VAR(ComM_TimerType, COMM_VAR) ComM_TMinFullComModeDurationTimer[COMM_NUM_OF_CHANNEL];
#endif
#if(STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
STATIC VAR(ComM_TimerType, COMM_VAR) ComM_NmLightTimeoutTimer[COMM_NUM_OF_CHANNEL];
#endif

/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
STATIC VAR(ComM_TimerType, COMM_VAR) ComM_PncPrepareSleepTimer[COMM_NUM_OF_PNC];
#endif

#define COMM_STOP_SEC_VAR_CLEARED_LOCAL_32
#include "ComM_MemMap.h"

#define COMM_START_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "ComM_MemMap.h"

#if(COMM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
STATIC P2CONST(ComM_ConfigType, COMM_VAR_NOINIT, COMM_CONST) ComM_ConfigSet;
#endif

#define COMM_STOP_SEC_VAR_CLEARED_GLOBAL_UNSPECIFIED
#include "ComM_MemMap.h"

/*******************************************************************************
*   Local Functions declaration
*******************************************************************************/
#define COMM_START_SEC_CODE
#include "ComM_MemMap.h"

STATIC FUNC(Std_ReturnType, COMM_CODE) ComM_S_CheckCfgParameters
(
    void
);


/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
STATIC FUNC(void, COMM_CODE) ComM_S_InitPnc
(
    void
);

STATIC FUNC(void, COMM_CODE) ComM_S_DeInitPnc
(
    void
);

STATIC FUNC(void, COMM_CODE) ComM_S_UserRequestPncMode
(
    ComM_UserHandleType User,
    ComM_ModeType ComMode
);

STATIC FUNC(void, COMM_CODE) ComM_S_PncRequestChannelMode
(
    PNCHandleType PncIdx,
    ComM_ModeType ComMode
);

STATIC FUNC(void, COMM_CODE)ComM_S_TimerMainFunctionPnc
(
    PNCHandleType PncIdx
);

STATIC FUNC(void, COMM_CODE) ComM_S_MainFunctionPnc
(
    NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_S_EiraReceiveUpdate
(
    void
);

#if(STD_ON == COMM_PNC_GW_ENABLED)
STATIC FUNC(void, COMM_CODE) ComM_S_EraReceiveUpdate
(
    void
);
#endif

STATIC FUNC(void, COMM_CODE) ComM_S_PncNoComProc
(
    PNCHandleType PncIdx
);

STATIC FUNC(void, COMM_CODE) ComM_S_PncNoComEnter
(
    PNCHandleType PncIdx
);

STATIC FUNC(void, COMM_CODE) ComM_S_PncRequestedProc
(
    PNCHandleType PncIdx
);

STATIC FUNC(void, COMM_CODE) ComM_S_PncRequestedEnter
(
    PNCHandleType PncIdx
);

STATIC FUNC(void, COMM_CODE) ComM_S_PncReadySleepProc
(
    PNCHandleType PncIdx
);

STATIC FUNC(void, COMM_CODE) ComM_S_PncReadySleepEnter
(
    PNCHandleType PncIdx
);

STATIC FUNC(void, COMM_CODE) ComM_S_PncPrepareSleepProc
(
    PNCHandleType PncIdx
);

STATIC FUNC(void, COMM_CODE) ComM_S_PncPrepareSleepEnter
(
    PNCHandleType PncIdx
);
#endif/*#if(STD_ON == COMM_PNC_SUPPORT)*/

#if(COMM_NUM_OF_USER > 0)
#if(STD_ON == COMM_MULTI_CORE_SUPPORT)
STATIC FUNC(void, COMM_CODE) ComM_S_ProcessUserRequest
(
    void
);
#endif
STATIC FUNC(Std_ReturnType, COMM_CODE) ComM_S_UserRequestChannelMode
(
    ComM_UserHandleType User,
    ComM_ModeType ComMode
);
#endif

STATIC FUNC(void, COMM_CODE) ComM_S_NoPendingRequestProc
(
    NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_S_RequestPendingProc
(
    NetworkHandleType Channel
);

#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))
STATIC FUNC(void, COMM_CODE) ComM_S_SilentComProc
(
    NetworkHandleType Channel
);
#endif

STATIC FUNC(void, COMM_CODE) ComM_S_NetworkRequestedProc
(
    NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_S_ReadySleepProc
(
    NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_S_ChannelNoComEnter
(
    NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_S_ChannelFullComEnter
(
    NetworkHandleType Channel,
    ComM_StateType SubState
);

#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))
STATIC FUNC(void, COMM_CODE) ComM_S_ChannelSilentComEnter
(
    NetworkHandleType Channel
);
#endif

STATIC FUNC(void, COMM_CODE) ComM_S_NoPendingRequestEnter
(
    NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_S_RequestPendingEnter
(
    NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_S_NetworkRequestedEnter
(
    NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_S_ReadySleepEnter
(
    NetworkHandleType Channel
);

STATIC FUNC(void, COMM_CODE) ComM_S_BusSM_RequestComMode
(
    NetworkHandleType Channel,
    ComM_ModeType Mode
);

STATIC FUNC(Std_ReturnType, COMM_CODE) ComM_S_BusSM_GetCurrentComMode
(
    NetworkHandleType Channel,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_VAR) BusModePtr
);

#if(COMM_NUM_OF_USER > 0)
STATIC FUNC(void, COMM_CODE) ComM_S_ReportModeSwitch
(
    NetworkHandleType Channel
);
#endif

STATIC FUNC(void, COMM_CODE) ComM_S_UpdateKeepComFlag
(
    NetworkHandleType Channel
);


#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
STATIC FUNC(void, COMM_CODE) ComM_S_TimerMainFunction
(
    NetworkHandleType Channel
);
#endif


/*******************************************************************************
*   Local Functions define
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_CheckCfgParameters
*
* Description:   Check whether the configuration parameters are valid.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, COMM_CODE) ComM_S_CheckCfgParameters
(
    void
)
{
    NetworkHandleType Channel;
    ComM_UserHandleType User;
    uint8 StartChannel;
    uint8 EndChannel;
#if(STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED)
    uint8 ChannelIdx;
#endif
    Std_ReturnType ret = E_OK;

#if(COMM_NUM_OF_USER > 0)
    for(User = (ComM_UserHandleType)0; User < (ComM_UserHandleType)COMM_NUM_OF_USER; User++)
    {
/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
        if(TRUE == COMM_PNC_ENABLED)
        {
            if(((COMM_CFG_USER_MAP_PNC_START(User) != (uint8)COMM_MAX_USER_MAPPING_PNC) && (COMM_CFG_USER_MAP_PNC_NUM(User) == (uint8)0)) \
                || ((uint8)(COMM_CFG_USER_MAP_PNC_START(User) + COMM_CFG_USER_MAP_PNC_NUM(User)) > (uint8)COMM_MAX_USER_MAPPING_PNC))
            {
                ret = E_NOT_OK;
                return ret;
            }
        }
#endif
        StartChannel = COMM_CFG_USER_MAP_CHL_START(User);
        EndChannel = StartChannel + COMM_CFG_USER_MAP_CHL_NUM(User);

        if((StartChannel == (uint8)COMM_MAX_USER_MAPPING_CHANNEL) || (COMM_CFG_USER_MAP_CHL_NUM(User) == (uint8)0) \
            || (EndChannel > (uint8)COMM_MAX_USER_MAPPING_CHANNEL))
        {
            ret = E_NOT_OK;
            return ret;
        }

#if(STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED)
        for(ChannelIdx = StartChannel; ChannelIdx < EndChannel; ChannelIdx++)
        {
            Channel = COMM_CFG_USER_MAP_CHL(ChannelIdx);
            if(COMM_IS_NMVARIANT_PASSIVE(Channel))
            {
                ret = E_NOT_OK;
                return ret;
            }
        }
#endif
    }
#endif/*#if(COMM_NUM_OF_USER > 0)*/

    for(Channel = (NetworkHandleType)0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
    {
#if(STD_ON == COMM_NMVARIANT_NONE_ENABLED)
        if((COMM_BUS_TYPE_INTERNAL == COMM_CFG_CHL_BUS_TYPE(Channel)) && (!COMM_IS_NMVARIANT_NONE(Channel)))
        {
            ret = E_NOT_OK;
            return ret;
        }
#endif

#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))
        if((COMM_IS_NMVARIANT_PASSIVE(Channel) || COMM_IS_NMVARIANT_FULL(Channel)) \
            && (COMSTACK_INVALID_NETWORK_HANDLE == COMM_CFG_CHL_TO_NM(Channel)))
        {
            ret = E_NOT_OK;
            return ret;
        }
#endif
    }

    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_BusSM_RequestComMode
*
* Description:   Turn on/off the Tx/Rx ability of the bus interface by calling
*                XXSM_RequestComMode() on the required channel
*
* Inputs:        Channel
*                Mode  COMM_NO_COMMUNICATION: Turn off Tx/Rx
*                      COMM_SILENT_COMMUNICATION: Turn off Tx and turn on Rx
*                      COMM_FULL_COMMUNICATION: Turn on Tx/Rx
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_BusSM_RequestComMode
(
    NetworkHandleType Channel,
    ComM_ModeType Mode
)
{
    Std_ReturnType ret = E_OK;
    /*Clear the pending flag*/
    ComM_BusSM_RequestPending[Channel] = FALSE;
    /*SWS_ComM_00962*//*SWS_ComM_00958*//*SWS_ComM_00402*/
    switch(COMM_CFG_CHL_BUS_TYPE(Channel))
    {
#if(COMM_NUM_OF_CAN_CHANNEL > 0)
    case COMM_BUS_TYPE_CAN:
        ret = CanSM_RequestComMode(COMM_CFG_CHL_TO_BUSSM(Channel), Mode);
        break;
#endif
#if(COMM_NUM_OF_LIN_CHANNEL > 0)
    case COMM_BUS_TYPE_LIN:
        ret = LinSM_RequestComMode(COMM_CFG_CHL_TO_BUSSM(Channel), Mode);
        break;
#endif
#if(COMM_NUM_OF_FR_CHANNEL > 0)
    case COMM_BUS_TYPE_FR:
        ret = FrSM_RequestComMode(COMM_CFG_CHL_TO_BUSSM(Channel), Mode);
        break;
#endif
#if(COMM_NUM_OF_ETH_CHANNEL > 0)
    case COMM_BUS_TYPE_ETH:
        ret = EthSM_RequestComMode(COMM_CFG_CHL_TO_BUSSM(Channel), Mode);
        break;
#endif
#if(COMM_NUM_OF_INTERNAL_CHANNEL > 0)
    /*SWS_ComM_00664*/
    case COMM_BUS_TYPE_INTERNAL:
        /*do nothing*/
        break;
#endif
    default:
        /*do nothing*/
        break;
    }

    if(ret != E_OK)
    {
        ComM_BusSM_RequestPending[Channel] = TRUE;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_BusSM_GetCurrentComMode
*
* Description:   Get current mode of BusSM by calling XXSM_GetCurrentComMode() on
*                the required channel
*
* Inputs:        Channel
*
* Outputs:       Mode  COMM_NO_COMMUNICATION: Turn off Tx/Rx
*                      COMM_SILENT_COMMUNICATION: Turn off Tx and turn on Rx
*                      COMM_FULL_COMMUNICATION: Turn on Tx/Rx*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, COMM_CODE) ComM_S_BusSM_GetCurrentComMode
(
    NetworkHandleType Channel,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_VAR) BusModePtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*SWS_ComM_00084*//*SWS_ComM_00962*//*SWS_ComM_00963*/
    switch(COMM_CFG_CHL_BUS_TYPE(Channel))
    {
#if(COMM_NUM_OF_CAN_CHANNEL > 0)
    case COMM_BUS_TYPE_CAN:
        ret = CanSM_GetCurrentComMode(COMM_CFG_CHL_TO_BUSSM(Channel), BusModePtr);
        break;
#endif
#if(COMM_NUM_OF_LIN_CHANNEL > 0)
    case COMM_BUS_TYPE_LIN:
        ret = LinSM_GetCurrentComMode(COMM_CFG_CHL_TO_BUSSM(Channel), BusModePtr);
        break;
#endif
#if(COMM_NUM_OF_FR_CHANNEL > 0)
    case COMM_BUS_TYPE_FR:
        ret = FrSM_GetCurrentComMode(COMM_CFG_CHL_TO_BUSSM(Channel), BusModePtr);
        break;
#endif
#if(COMM_NUM_OF_ETH_CHANNEL > 0)
    case COMM_BUS_TYPE_ETH:
        ret = EthSM_GetCurrentComMode(COMM_CFG_CHL_TO_BUSSM(Channel), BusModePtr);
        break;
#endif
#if(COMM_NUM_OF_INTERNAL_CHANNEL > 0)
    case COMM_BUS_TYPE_INTERNAL:
        *BusModePtr = COMM_NO_COMMUNICATION;
        ret = E_OK;
        break;
#endif
    default:
        ret = E_NOT_OK;
        break;
    }

    return ret;
}

#if(COMM_NUM_OF_USER > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_ReportModeSwitch
*
* Description:   Propagates the mode switch to user and BswM
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   If all channel types are passive, no User is associated with
*                the channel and the function cannot be used.
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_ReportModeSwitch
(
    NetworkHandleType Channel
)
{
    ComM_UserHandleType User;
    uint8 UserIdx;
    uint8 StartUser, EndUser;
    NetworkHandleType ChannelAll;
    uint8 ChannelIdx;
    uint8 StartChannel, EndChannel;
    ComM_ModeType TempComMode;

    TempComMode = COMM_FULL_COMMUNICATION;
    StartUser = COMM_CFG_CHL_MAP_USER_START(Channel);
    EndUser = StartUser + COMM_CFG_CHL_MAP_USER_NUM(Channel);

    for(UserIdx = StartUser; UserIdx < EndUser; UserIdx++)
    {
        User = COMM_CFG_CHL_MAP_USER(UserIdx);

        StartChannel = COMM_CFG_USER_MAP_CHL_START(User);
        EndChannel = StartChannel + COMM_CFG_USER_MAP_CHL_NUM(User);

        for(ChannelIdx = StartChannel; ChannelIdx < EndChannel; ChannelIdx++)
        {
            ChannelAll = COMM_CFG_USER_MAP_CHL(ChannelIdx);
            /*SWS_ComM_00663*/
            if(COMM_NO_COMMUNICATION == ComM_Mode[ChannelAll])
            {
                TempComMode = COMM_NO_COMMUNICATION;
                break;
            }
            else if(COMM_SILENT_COMMUNICATION == ComM_Mode[ChannelAll])
            {
                TempComMode = COMM_SILENT_COMMUNICATION;
            }
            else
            {
                /*do nothing*/
            }
        }
        /*Report to User*//*SWS_ComM_00091*//*SWS_ComM_00778*/
        ComM_RteSwitchFunction[User](TempComMode);
    }

}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_UpdateKeepComFlag
*
* Description:   Calculate if ComM need to keep communication
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_UpdateKeepComFlag
(
    NetworkHandleType Channel
)
{
#if(STD_ON == COMM_DCM_SUPPORT)
    /*SWS_ComM_00866*//*SWS_ComM_00182*//*SWS_ComM_00876*//*SWS_ComM_00878*/
    if((uint16)0 != (uint16)(ComM_TriggerInfo[Channel] & COMM_ACTIVE_DIAG_MASK))
    {
        ComM_KeepComFlag[Channel] = TRUE;
    }
    else
#endif
#if(STD_ON == COMM_PNC_SUPPORT)
    if((ComM_UserReqChannelCnt[Channel] > (uint8)0) || (ComM_PncReqChannelCnt[Channel] > (uint8)0))
#else
    if(ComM_UserReqChannelCnt[Channel] > (uint8)0)
#endif
    {
        /*SWS_ComM_00827*//*SWS_ComM_00215*/
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
        if(((uint16)0 != (uint16)(ComM_TriggerInfo[Channel] & COMM_LIMIT_TO_NO_COM_MASK)) \
            && ((ComM_InhibitionStatusType)0 != (ComM_InhibitionStatusType)(ComM_EcuGroupClassfication & COMM_LIMITED_TO_NO_COM_BIT)))
        {
            ComM_KeepComFlag[Channel] = FALSE;
        }
        else
#endif
        {
#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
            /*SWS_ComM_00302*//*SWS_ComM_00218*//*SWS_ComM_00219*/
            if(((ComM_InhibitionStatusType)0 != (ComM_InhibitionStatusType)(ComM_EcuGroupClassfication & COMM_WAKE_UP_INHIBITION_ACTIVE_BIT)) \
                && (TRUE == ComM_NoWakeupStatus(Channel)) && (COMM_FULL_COMMUNICATION != ComM_Mode[Channel]))
            {
                ComM_KeepComFlag[Channel] = FALSE;
            }
            else
#endif
            {
                /*SWS_ComM_00875*//*SWS_ComM_00877*/
                ComM_KeepComFlag[Channel] = TRUE;
            }
        }
    }
    else
    {
        ComM_KeepComFlag[Channel] = FALSE;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_ChannelNoComEnter
*
* Description:   Process actions on enter COMM_NO_COMMUNICATION mode
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_ChannelNoComEnter
(
    NetworkHandleType Channel
)
{
    uint8 ChannelIdx;
    uint16 ClearMask;

    ComM_Mode[Channel] = COMM_NO_COMMUNICATION;
    /*SWS_ComM_00898*/
    ComM_S_NoPendingRequestEnter(Channel);

    /*SWS_ComM_00313*/
    if(COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00472*/
#if(COMM_NUM_OF_USER > 0)
        ComM_S_ReportModeSwitch(Channel);
#endif
        /*SWS_ComM_00976*//*SWS_ComM_00861*/
        BswM_ComM_CurrentMode(Channel, COMM_NO_COMMUNICATION);
    }

    /*SWS_ComM_00846*//*SWS_ComM_00073*//*SWS_ComM_00092*/
    ComM_S_BusSM_RequestComMode(Channel, COMM_NO_COMMUNICATION);

#if((STD_OFF == COMM_NMVARIANT_PASSIVE_ENABLED) || (STD_ON == COMM_NMVARIANT_ENABLED))
    /*SWS_ComM_00582*/
    for(ChannelIdx = (uint8)0; ChannelIdx < (uint8)COMM_MAX_USER_MAPPING_CHANNEL; ChannelIdx++)
    {
        if(Channel == ComM_UserMappingChannel[ChannelIdx])
        {
            ComM_UserMappingChannelModeReq[ChannelIdx] = COMM_NO_COMMUNICATION;
        }
    }
#endif

#if(STD_ON == COMM_NMVARIANT_FULL_ENABLED)
    /*SWS_ComM_00288*/
    if(COMM_IS_NMVARIANT_FULL(Channel))
    {
        /*SWS_ComM_00261*//*SWS_ComM_00602*/
        (void)Nm_NetworkRelease(COMM_CFG_CHL_TO_NM(Channel));
    }
#endif

    /*SWS_ComM_00355*/
#if(STD_ON == COMM_RESET_AFTER_FORCING_NOCOMM)
    if(((uint16)0 != (ComM_TriggerInfo[Channel] & COMM_LIMIT_TO_NO_COM_MASK)) \
        && ((ComM_InhibitionStatusType)0 != (ComM_EcuGroupClassfication & COMM_LIMITED_TO_NO_COM_BIT)))
    {
#if(STD_ON == COMM_PNC_SUPPORT)
        if((ComM_UserReqChannelCnt[Channel] > (uint8)0) || (ComM_PncReqChannelCnt[Channel] > (uint8)0))
#else
        if(ComM_UserReqChannelCnt[Channel] > (uint8)0)
#endif
        {
            BswM_ComM_InitiateReset();
        }
    }
#endif

    /*IMPORTANT!! Necessary to clear Nm mode, diag, wakeup indications.*/
    ClearMask = (COMM_LIMIT_TO_NO_COM_MASK | COMM_COM_ALLOWED_IND_MASK);
    ComM_TriggerInfo[Channel] &= ClearMask;
    ComM_ReqPendingFlag[Channel] = FALSE;

    ComM_S_UpdateKeepComFlag(Channel);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_ChannelFullComEnter
*
* Description:   Process actions on enter COMM_FULL_COMMUNICATION mode
*
* Inputs:        Channel
*                SubState
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_ChannelFullComEnter
(
    NetworkHandleType Channel,
    ComM_StateType SubState
)
{
    ComM_ModeType ReqMode = COMM_FULL_COMMUNICATION;

    ComM_Mode[Channel] = COMM_FULL_COMMUNICATION;

    if(COMM_FULL_COM_NETWORK_REQUESTED == SubState)
    {
        ComM_S_NetworkRequestedEnter(Channel);
    }
    else
    {
        ComM_S_ReadySleepEnter(Channel);
    }

#if(COMM_NUM_OF_ETH_CHANNEL > 0)
    /*SWS_ComM_01070*/
    if(TRUE == COMM_CFG_CHL_WAKE_SLEEP_EN(Channel))
    {
        ReqMode = COMM_FULL_COMMUNICATION_WITH_WAKEUP_REQUEST;
    }
#endif

    /*SWS_ComM_00472*/
#if(COMM_NUM_OF_USER > 0)
    ComM_S_ReportModeSwitch(Channel);
#endif

    /*SWS_ComM_00976*//*SWS_ComM_00861*/
    BswM_ComM_CurrentMode(Channel, ReqMode);

    /*SWS_ComM_00845*//*SWS_ComM_00092*//*SWS_ComM_00069*/
    ComM_S_BusSM_RequestComMode(Channel, COMM_FULL_COMMUNICATION);
}

#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_ChannelSilentComEnter
*
* Description:   Process actions on enter COMM_SILENT_COMMUNICATION mode
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_ChannelSilentComEnter
(
    NetworkHandleType Channel
)
{
    ComM_Mode[Channel] = COMM_SILENT_COMMUNICATION;
    ComM_State[Channel] = COMM_SILENT_COM;

    /*SWS_ComM_00472*/
#if(COMM_NUM_OF_USER > 0)
    ComM_S_ReportModeSwitch(Channel);
#endif
    /*SWS_ComM_00976*//*SWS_ComM_00861*/
    BswM_ComM_CurrentMode(Channel, COMM_SILENT_COMMUNICATION);

    /*SWS_ComM_00092*//*SWS_ComM_00071*/
    ComM_S_BusSM_RequestComMode(Channel, COMM_SILENT_COMMUNICATION);
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_NoPendingRequestEnter
*
* Description:   Process actions on enter COMM_NO_COM_NO_PENDING_REQUEST state
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_NoPendingRequestEnter
(
    NetworkHandleType Channel
)
{
    ComM_State[Channel] = COMM_NO_COM_NO_PENDING_REQUEST;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_RequestPendingEnter
*
* Description:   Process actions on enter COMM_NO_COM_REQUEST_PENDING state
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_RequestPendingEnter
(
    NetworkHandleType Channel
)
{
    ComM_State[Channel] = COMM_NO_COM_REQUEST_PENDING;
    ComM_S_RequestPendingProc(Channel);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_NetworkRequestedEnter
*
* Description:   Process actions on enter COMM_FULL_COM_NETWORK_REQUESTED state
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_NetworkRequestedEnter
(
    NetworkHandleType Channel
)
{
#if(STD_ON == COMM_NMVARIANT_FULL_ENABLED)
    ComM_ModeType ComMode = COMM_NO_COMMUNICATION;
#endif
    ComM_State[Channel] = COMM_FULL_COM_NETWORK_REQUESTED;

#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
    /*SWS_ComM_00886*/
    if(COMM_IS_NMVARIANT_LIGHT(Channel) || COMM_IS_NMVARIANT_NONE(Channel))
    {
        ComM_TMinFullComModeDurationTimer[Channel] = (COMM_MIN_FULL_COM_TIME/COMM_CFG_CHL_MAIN_PRRIOD(Channel));
    }
#endif

#if(STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
    /*SWS_ComM_00892*/
    if(COMM_IS_NMVARIANT_LIGHT(Channel))
    {
        ComM_NmLightTimeoutTimer[Channel] = (ComM_TimerType)0;
    }
#endif

#if(STD_ON == COMM_NMVARIANT_FULL_ENABLED)
    /*SWS_ComM_00869*//*SWS_ComM_00870*/
    if((COMM_IS_NMVARIANT_FULL(Channel)) && (TRUE == ComM_KeepComFlag[Channel]))
    {
        (void)ComM_S_BusSM_GetCurrentComMode(Channel, &ComMode);

        if(COMM_FULL_COMMUNICATION == ComMode)
        {
            /*SWS_ComM_00261*//*SWS_ComM_00602*//*SWS_ComM_00667*/
            (void)Nm_NetworkRequest(COMM_CFG_CHL_TO_NM(Channel));
        }
        else
        {
            ComM_ReqPendingFlag[Channel] = TRUE;
        }
    }
#endif

#if((STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED) || (STD_ON == COMM_NMVARIANT_SLAVE_P_ENABLED))
    /*SWS_ComM_00915*/
    if((COMM_IS_NMVARIANT_PASSIVE(Channel)) || (COMM_IS_NMVARIANT_SLAVE_P(Channel)))
    {
        ComM_S_ReadySleepEnter(Channel);
    }
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_ReadySleepEnter
*
* Description:   Process actions on enter COMM_FULL_COM_READY_SLEEP state
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_ReadySleepEnter
(
    NetworkHandleType Channel
)
{
#if(STD_ON == COMM_NMVARIANT_FULL_ENABLED)
    Nm_StateType NmState = NM_STATE_BUS_SLEEP;
    Nm_ModeType NmMode = NM_MODE_BUS_SLEEP;
#endif
    ComM_State[Channel] = COMM_FULL_COM_READY_SLEEP;

#if(STD_ON == COMM_NMVARIANT_FULL_ENABLED)
    if(COMM_IS_NMVARIANT_FULL(Channel))
    {
        /*SWS_ComM_00133*//*SWS_ComM_00261*//*SWS_ComM_00602*/
        (void)Nm_NetworkRelease(COMM_CFG_CHL_TO_NM(Channel));
        ComM_ReqPendingFlag[Channel] = FALSE;

        (void)Nm_GetState(COMM_CFG_CHL_TO_NM(Channel), &NmState, &NmMode);
        if(NmMode == NM_MODE_BUS_SLEEP)
        {
            ComM_TriggerInfo[Channel] &= (uint16)(~COMM_NM_MODE_IND_MASK);
            ComM_TriggerInfo[Channel] |= COMM_NM_MODE_PBS;
        }
    }
#endif

#if(STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
    if(COMM_IS_NMVARIANT_LIGHT(Channel))
    {
        /*SWS_ComM_00891*/
        ComM_NmLightTimeoutTimer[Channel] = (COMM_CFG_CHL_LIGHT_TIME(Channel)/COMM_CFG_CHL_MAIN_PRRIOD(Channel));
    }
#endif

#if(STD_ON == COMM_NMVARIANT_NONE_ENABLED)
    if((COMM_BUS_TYPE_INTERNAL == COMM_CFG_CHL_BUS_TYPE(Channel)))
    {
        /*SWS_ComM_00671*//*NmVariant is NONE on internal bus*/
        ComM_S_ChannelNoComEnter(Channel);
    }
#endif
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_NoPendingRequestProc
*
* Description:   Process actions in COMM_NO_COM_NO_PENDING_REQUEST state
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_NoPendingRequestProc
(
    NetworkHandleType Channel
)
{
    uint16 FocusMask = (uint16)(COMM_WAKEUP_IND_MASK | COMM_NM_RESTART_IND_MASK | COMM_NETWORK_START_IND_MASK);

    /*SWS_ComM_00875*//*SWS_ComM_00876*//*SWS_ComM_00893*/
    /*SWS_ComM_00894*//*SWS_ComM_00694*//*SWS_ComM_00066*/
    if((TRUE == ComM_KeepComFlag[Channel]) || ((uint16)0 != (uint16)(ComM_TriggerInfo[Channel] & FocusMask)))
    {
        ComM_S_RequestPendingEnter(Channel);
    }
    else
    {
        /*Stay in NoPendingRequest state*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_RequestPendingProc
*
* Description:   Process actions in COMM_NO_COM_REQUEST_PENDING state
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_RequestPendingProc
(
    NetworkHandleType Channel
)
{
    uint16 FocusMask = (uint16)(COMM_WAKEUP_IND_MASK | COMM_NM_RESTART_IND_MASK | COMM_NETWORK_START_IND_MASK);
    /*SWS_ComM_00066*/
    if((TRUE == ComM_KeepComFlag[Channel]) || ((uint16)0 != (uint16)(ComM_TriggerInfo[Channel] & FocusMask)))
    {
        /*SWS_ComM_00896*/
        if((uint16)0 != (uint16)(ComM_TriggerInfo[Channel] & COMM_COM_ALLOWED_IND_MASK))
        {
            /*SWS_ComM_00895*//*SWS_ComM_00583*/
            ComM_S_ChannelFullComEnter(Channel, COMM_FULL_COM_NETWORK_REQUESTED);
        }
        else
        {
            /*Stay in RequestPending state*/
        }
    }
    else
    {
        /*SWS_ComM_00897*/
        ComM_S_NoPendingRequestEnter(Channel);
    }
}

#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_SilentComProc
*
* Description:   Process actions in COMM_SILENT_COM state
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_SilentComProc
(
    NetworkHandleType Channel
)
{
    /*Only PASSIVE or FULL channel can reach here*/

    if(TRUE == ComM_KeepComFlag[Channel])
    {
        /*SWS_ComM_00877*//*SWS_ComM_00878*//*SWS_ComM_00899*/
        ComM_S_ChannelFullComEnter(Channel, COMM_FULL_COM_NETWORK_REQUESTED);
    }
    else if(COMM_NM_MODE_BUS_SLEEP == (uint16)(ComM_TriggerInfo[Channel] & COMM_NM_MODE_IND_MASK))
    {
        /*SWS_ComM_00295*/
        ComM_S_ChannelNoComEnter(Channel);
    }
    else if(COMM_NM_MODE_NETWORK == (uint16)(ComM_TriggerInfo[Channel] & COMM_NM_MODE_IND_MASK))
    {
        /*SWS_ComM_00296*/
        ComM_S_ChannelFullComEnter(Channel, COMM_FULL_COM_READY_SLEEP);
    }
    else
    {
        /*Stay in SilentCom state*/
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_NetworkRequestedProc
*
* Description:   Process actions in COMM_FULL_COM_NETWORK_REQUESTED state
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_NetworkRequestedProc
(
    NetworkHandleType Channel
)
{
    if(FALSE == ComM_KeepComFlag[Channel])
    {
#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
        if(COMM_IS_NMVARIANT_LIGHT(Channel) || COMM_IS_NMVARIANT_NONE(Channel))
        {
            if((ComM_TimerType)0 == ComM_TMinFullComModeDurationTimer[Channel])
            {
                /*SWS_ComM_00889*/
                ComM_S_ReadySleepEnter(Channel);
            }
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
            else if(((uint16)0 != (uint16)(ComM_TriggerInfo[Channel] & COMM_LIMIT_TO_NO_COM_MASK)) \
                && ((ComM_InhibitionStatusType)0 != (ComM_InhibitionStatusType)(ComM_EcuGroupClassfication & COMM_LIMITED_TO_NO_COM_BIT)))
            {
                /*SWS_ComM_00890*/
                /*ComM_TMinFullComModeDurationTimer[] may still on, never mind*/
                ComM_S_ReadySleepEnter(Channel);
            }
#endif
            else
            {
                /*Stay in NetworkRequested state*/
            }
        }
        else
#endif
        {
            /*SWS_ComM_00888*//*SWS_ComM_01017*//*SWS_ComM_00303*/
            ComM_S_ReadySleepEnter(Channel);
        }
    }
    else
    {
        /*Stay in NetworkRequested state*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_ReadySleepProc
*
* Description:   Process actions in COMM_FULL_COM_READY_SLEEP state
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_ReadySleepProc
(
    NetworkHandleType Channel
)
{
#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))
    Nm_StateType NmState = NM_STATE_BUS_SLEEP;
    Nm_ModeType NmMode = NM_MODE_BUS_SLEEP;
#endif

    if(TRUE == ComM_KeepComFlag[Channel])
    {
        /*SWS_ComM_00882*//*SWS_ComM_00883*/
        /*SWS_ComM_00892*//*If the channel type is light, ComM_NmLightTimeoutTimer[] may still on, never mind*/
        ComM_S_NetworkRequestedEnter(Channel);
    }
    else
    {
#if(STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
        if(COMM_IS_NMVARIANT_LIGHT(Channel))
        {
            if((ComM_TimerType)0 == ComM_NmLightTimeoutTimer[Channel])
            {
                /*SWS_ComM_00610*/
                ComM_S_ChannelNoComEnter(Channel);
            }
            else
            {
                /*Stay in ReadySleep state*/
            }
        }
        else
#endif

#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))
        if((COMM_IS_NMVARIANT_FULL(Channel)) || (COMM_IS_NMVARIANT_PASSIVE(Channel)))
        {
            if(COMM_NM_MODE_PBS == (uint16)(ComM_TriggerInfo[Channel] & COMM_NM_MODE_IND_MASK))
            {
                /*SWS_ComM_00826*/
                ComM_S_ChannelSilentComEnter(Channel);

                (void)Nm_GetState(COMM_CFG_CHL_TO_NM(Channel), &NmState, &NmMode);
                if(NmMode == NM_MODE_BUS_SLEEP)
                {
                    ComM_TriggerInfo[Channel] &= (uint16)(~COMM_NM_MODE_IND_MASK);
                    ComM_TriggerInfo[Channel] |= COMM_NM_MODE_BUS_SLEEP;
                }
            }
            else if(COMM_NM_MODE_BUS_SLEEP == (uint16)(ComM_TriggerInfo[Channel] & COMM_NM_MODE_IND_MASK))
            {
                /*SWS_ComM_00637*/
                ComM_S_ChannelNoComEnter(Channel);
            }
            else
            {
                /*Stay in ReadySleep*/
            }
        }
        else
#endif
#if((STD_ON == COMM_NMVARIANT_SLAVE_A_ENABLED) || (STD_ON == COMM_NMVARIANT_SLAVE_P_ENABLED))
        if((COMM_IS_NMVARIANT_SLAVE_A(Channel)) || (COMM_IS_NMVARIANT_SLAVE_P(Channel)))
        {
            if((uint16)0 != (ComM_TriggerInfo[Channel] & COMM_SM_BUS_SLEEP_IND_MASK))
            {
                /*SWS_ComM_01018*/
                ComM_S_ChannelNoComEnter(Channel);
            }
        }
        else
#endif
        {
            /*Stay in ReadySleep state*/
        }
    }
}


#if(COMM_NUM_OF_USER > 0)
#if(STD_ON == COMM_MULTI_CORE_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_ProcessUserRequest
*
* Description:   Process the request communication mode from users in master core.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   only called in master core when multi-core enabled
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_ProcessUserRequest
(
    void
)
{
    ComM_UserHandleType User;
    uint8 CoreId;
    ComM_ModeType NewReqComMode = COMM_NO_COMMUNICATION;
    ComM_ModeType LastComMode = COMM_NO_COMMUNICATION;

    for(User = (ComM_UserHandleType)0; User < (ComM_UserHandleType)COMM_NUM_OF_USER; User++)
    {
        for(CoreId = (uint8)0; CoreId < (uint8)COMM_NUM_OF_CORES; CoreId++)
        {
            if(ComM_UserLastComMode[User][CoreId] == COMM_FULL_COMMUNICATION)
            {
                LastComMode = COMM_FULL_COMMUNICATION;
                break;
            }
        }

        for(CoreId = (uint8)0; CoreId < (uint8)COMM_NUM_OF_CORES; CoreId++)
        {
            if(ComM_UserComMode[User][CoreId] == COMM_FULL_COMMUNICATION)
            {
                NewReqComMode = COMM_FULL_COMMUNICATION;
            }
            ComM_UserLastComMode[User][CoreId] = ComM_UserComMode[User][CoreId];
        }

        if(NewReqComMode != LastComMode)
        {
            /*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
            ComM_S_UserRequestPncMode(User, NewReqComMode);
#endif
            (void)ComM_S_UserRequestChannelMode(User, NewReqComMode);
        }
        NewReqComMode = COMM_NO_COMMUNICATION;
        LastComMode = COMM_NO_COMMUNICATION;
    }
}
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_UserRequestChannelMode
*
* Description:   Requesting of a Communication Mode by a user
*
* Inputs:        User: Handle of the user who requests a mode
*                ComMode: Mode that user requested
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, COMM_CODE) ComM_S_UserRequestChannelMode
(
    ComM_UserHandleType User,
    ComM_ModeType ComMode
)
{
    uint8 StartChannel;
    uint8 EndChannel;
    uint8 ChannelIdx;
    NetworkHandleType Channel;
    Std_ReturnType ret = E_OK;

    /*SWS_ComM_00795*/
    StartChannel = COMM_CFG_USER_MAP_CHL_START(User);
    EndChannel = StartChannel + COMM_CFG_USER_MAP_CHL_NUM(User);

    if(COMM_NO_COMMUNICATION == ComMode)
    {
        for(ChannelIdx = StartChannel; ChannelIdx < EndChannel; ChannelIdx++)
        {
            /*if already in the COMM_NO_COMMUNICATION, ignore*/
            if(COMM_NO_COMMUNICATION != ComM_UserMappingChannelModeReq[ChannelIdx])
            {
                /*SWS_ComM_00839*//*SWS_ComM_00625*//*SWS_ComM_00500*/
                ComM_UserMappingChannelModeReq[ChannelIdx] = COMM_NO_COMMUNICATION;

                /*SWS_ComM_00795*/
                Channel = COMM_CFG_USER_MAP_CHL(ChannelIdx);

                if(ComM_UserReqChannelCnt[Channel] > (uint8)0)
                {
                    ComM_UserReqChannelCnt[Channel]--;

                    ComM_S_UpdateKeepComFlag(Channel);
                }
            }
        }
    }
    else/*COMM_FULL_COMMUNICATION*/
    {
        for(ChannelIdx = StartChannel; ChannelIdx < EndChannel; ChannelIdx++)
        {
            Channel = COMM_CFG_USER_MAP_CHL(ChannelIdx);

#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
            if(((uint16)0 != (uint16)(ComM_TriggerInfo[Channel] & COMM_LIMIT_TO_NO_COM_MASK)) \
                && ((ComM_InhibitionStatusType)0 != (ComM_InhibitionStatusType)(ComM_EcuGroupClassfication & COMM_LIMITED_TO_NO_COM_BIT)))
            {
                /*SWS_ComM_00138*//*SWS_ComM_00141*//*SWS_ComM_00142*/
                if(ComM_InhibitCounter < COMM_INHIBIT_COUNTER_MAX_VALUE)
                {
                    ComM_InhibitCounter++;
#if(STD_ON == COMM_NVM_SUPPORT)
                    /*SWS_ComM_00140*//*SWS_ComM_00103*/
                    NvM_SetRamBlockStatus(COMM_GLOBAL_NVM_BLOCK_REF, TRUE);
#endif
                }

                ret = COMM_E_MODE_LIMITATION;
            }
#endif
            /*if already in the COMM_FULL_COMMUNICATION, ignore*/
            if(COMM_FULL_COMMUNICATION != ComM_UserMappingChannelModeReq[ChannelIdx])
            {
                /*SWS_ComM_00686*//*SWS_ComM_00500*//*SWS_ComM_00839*//*SWS_ComM_00840*/
                ComM_UserMappingChannelModeReq[ChannelIdx] = COMM_FULL_COMMUNICATION;

                /*SWS_ComM_00736*/
                ComM_UserReqChannelCnt[Channel]++;

                ComM_S_UpdateKeepComFlag(Channel);
            }
        }
    }

    return ret;
}
#endif

#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_TimerMainFunction
*
* Description:   Main function of the non-pnc-related timers
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_TimerMainFunction
(
    NetworkHandleType Channel
)
{
    if(COMM_FULL_COM_NETWORK_REQUESTED == ComM_State[Channel])
    {
        if(COMM_IS_NMVARIANT_LIGHT(Channel) || COMM_IS_NMVARIANT_NONE(Channel))
        {
            if((ComM_TimerType)0 != ComM_TMinFullComModeDurationTimer[Channel])
            {
                ComM_TMinFullComModeDurationTimer[Channel]--;
            }
        }
    }

#if(STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
    if(COMM_FULL_COM_READY_SLEEP == ComM_State[Channel])
    {
        if(COMM_IS_NMVARIANT_LIGHT(Channel))
        {
            if((ComM_TimerType)0 != ComM_NmLightTimeoutTimer[Channel])
            {
                ComM_NmLightTimeoutTimer[Channel]--;
            }
        }
    }
#endif
}
#endif


/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_InitPnc
*
* Description:   Initialize Pnc
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_InitPnc
(
    void
)
{
    uint8 i;
    uint8 PncIdx2;/*Index value of index value of Pnc*/
    PNCHandleType PncIdx;/*Index value of Pnc*/
    NetworkHandleType Channel;
    uint8 ChannelIdx;
#if(STD_ON == COMM_PNC_GW_ENABLED)
    uint8 StartChannel;
    uint8 EndChannel;
#endif

    ComM_EiraUpdateFlag = FALSE;
#if(STD_ON == COMM_PNC_GW_ENABLED)
    ComM_EraUpdateFlag = FALSE;
#endif

    for(PncIdx2 = (uint8)0; PncIdx2 < (uint8)COMM_MAX_USER_MAPPING_PNC; PncIdx2++)
    {
        ComM_UserMappingPncModeReq[PncIdx2] = COMM_PNC_NO_COMMUNICATION;
    }

    for(ChannelIdx = (uint8)0; ChannelIdx < (uint8)COMM_MAX_PNC_MAPPING_CHANNEL; ChannelIdx++)
    {
        ComM_PncMappingChannelModeReq[ChannelIdx] = COMM_NO_COMMUNICATION;
    }

    for(i = (uint8)0; i < COMM_PNC_DATA_LENGTH; i++)
    {
        ComM_EiraData[i] = (uint8)0;
    }

    for(Channel = (NetworkHandleType)0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
    {
        ComM_PncReqChannelCnt[Channel] = (uint8)0;

        for(i = (uint8)0; i < COMM_PNC_DATA_LENGTH; i++)
        {
            ComM_IraTxData[Channel][i] = (uint8)0;
#if(STD_ON == COMM_PNC_GW_ENABLED)
            ComM_EraData[Channel][i] = (uint8)0;
#endif
        }
    }

    for(PncIdx = (PNCHandleType)0; PncIdx < (PNCHandleType)COMM_NUM_OF_PNC; PncIdx++)
    {
        ComM_PncPrepareSleepTimer[PncIdx] = (ComM_TimerType)0;
        ComM_UserReqPncCnt[PncIdx] = (uint8)0;
        ComM_EiraReqOfPnc[PncIdx] = FALSE;
#if(STD_ON == COMM_PNC_GW_ENABLED)
        ComM_EraReqOfPnc[PncIdx] = (uint8)0;
        ComM_PncPassiveChannel[PncIdx] = COMSTACK_INVALID_NETWORK_HANDLE;

        StartChannel = COMM_CFG_PNC_MAP_CHL_START(PncIdx);
        EndChannel = StartChannel + COMM_CFG_PNC_MAP_CHL_NUM(PncIdx);
        for(ChannelIdx = StartChannel; ChannelIdx < EndChannel; ChannelIdx++)
        {
            Channel = COMM_CFG_PNC_MAP_CHL(ChannelIdx);

            if(COMM_GATEWAY_TYPE_PASSIVE == COMM_CFG_CHL_PNC_GW_TYPE(Channel))
            {
                ComM_PncPassiveChannel[PncIdx] = Channel;
            }
        }
#if(STD_ON == COMM_SYNC_PNC_SHUTDOWN_ENABLED)
        ComM_PncSyncShutdownFlag[PncIdx] = FALSE;
#endif
#endif
        /*SWS_ComM_00926*/
        ComM_S_PncNoComEnter(PncIdx);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_DeInitPnc
*
* Description:   Deinitialize Pnc
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_DeInitPnc
(
    void
)
{
    PNCHandleType PncIdx;

    for(PncIdx = (PNCHandleType)0; PncIdx < (PNCHandleType)COMM_NUM_OF_PNC; PncIdx++)
    {
        ComM_PncPrepareSleepTimer[PncIdx] = (ComM_TimerType)0;
        ComM_S_PncNoComEnter(PncIdx);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_UserRequestPncMode
*
* Description:   If the User is associated with the PNCs, the User request is
*                logged to manage the PNC state machine.
*
* Inputs:        User: Handle of the user who requests a mode
*                ComMode: Mode that user requested
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_UserRequestPncMode
(
    ComM_UserHandleType User,
    ComM_ModeType ComMode
)
{
    uint8 StartPnc;
    uint8 EndPnc;
    uint8 PncIdx2;/*Index value of index value of Pnc*/
    PNCHandleType PncIdx;/*Index value of Pnc*/

    StartPnc = COMM_CFG_USER_MAP_PNC_START(User);
    EndPnc = StartPnc + COMM_CFG_USER_MAP_PNC_NUM(User);

    /*release PNC*/
    if(COMM_NO_COMMUNICATION == ComMode)
    {
        for(PncIdx2 = StartPnc; PncIdx2 < EndPnc; PncIdx2++)
        {
            PncIdx = COMM_CFG_USER_MAP_PNC(PncIdx2);

            /*if PNC already in the COMM_NO_COMMUNICATION, ignore*/
            if(COMM_PNC_NO_COMMUNICATION != ComM_UserMappingPncModeReq[PncIdx2])
            {
                /*SWS_ComM_00500*//*SWS_ComM_00972*/
                ComM_UserMappingPncModeReq[PncIdx2] = COMM_PNC_NO_COMMUNICATION;

                /*Check if there are still users requesting this pnc*/
                if(ComM_UserReqPncCnt[PncIdx] > (uint8)0)
                {
                    ComM_UserReqPncCnt[PncIdx]--;
                }
            }
        }
    }
    /*request PNC*/
    else
    {
        for(PncIdx2 = StartPnc; PncIdx2 < EndPnc; PncIdx2++)
        {
            /*if PNC already in the COMM_FULL_COMMUNICATION, ignore*/
            if(COMM_PNC_REQUESTED != ComM_UserMappingPncModeReq[PncIdx2])
            {
                /*SWS_ComM_00500*//*SWS_ComM_00972*/
                ComM_UserMappingPncModeReq[PncIdx2] = COMM_PNC_REQUESTED;

                PncIdx = COMM_CFG_USER_MAP_PNC(PncIdx2);
                ComM_UserReqPncCnt[PncIdx]++;
            }
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_PncRequestChannelMode
*
* Description:   Requesting of a Communication Mode by a PNC
*
* Inputs:        PncIdx: Handle of the PNC who requests a mode
*                ComMode: Mode that user requested
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_PncRequestChannelMode
(
    PNCHandleType PncIdx,
    ComM_ModeType ComMode
)
{
    uint8 StartChannel;
    uint8 EndChannel;
    uint8 ChannelIdx;
    NetworkHandleType Channel;

    /*SWS_ComM_00795*/
    StartChannel = COMM_CFG_PNC_MAP_CHL_START(PncIdx);
    EndChannel = StartChannel + COMM_CFG_PNC_MAP_CHL_NUM(PncIdx);

    if(COMM_NO_COMMUNICATION == ComMode)
    {
        for(ChannelIdx = StartChannel; ChannelIdx < EndChannel; ChannelIdx++)
        {
            if(COMM_NO_COMMUNICATION != ComM_PncMappingChannelModeReq[ChannelIdx])
            {
                ComM_PncMappingChannelModeReq[ChannelIdx] = COMM_NO_COMMUNICATION;

                Channel = COMM_CFG_PNC_MAP_CHL(ChannelIdx);

                if(ComM_PncReqChannelCnt[Channel] > (uint8)0)
                {
                    ComM_PncReqChannelCnt[Channel]--;

                    ComM_S_UpdateKeepComFlag(Channel);
                }
            }
        }
    }
    else/*COMM_FULL_COMMUNICATION*/
    {
        for(ChannelIdx = StartChannel; ChannelIdx < EndChannel; ChannelIdx++)
        {
            if(COMM_FULL_COMMUNICATION != ComM_PncMappingChannelModeReq[ChannelIdx])
            {
                ComM_PncMappingChannelModeReq[ChannelIdx] = COMM_FULL_COMMUNICATION;

                Channel = COMM_CFG_PNC_MAP_CHL(ChannelIdx);

                ComM_PncReqChannelCnt[Channel]++;

                ComM_S_UpdateKeepComFlag(Channel);
            }
        }
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_TimerMainFunctionPnc
*
* Description:   Main function of PNC related Timers
*
* Inputs:        PncIdx
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_TimerMainFunctionPnc
(
    PNCHandleType PncIdx
)
{
    if(COMM_PNC_PREPARE_SLEEP == ComM_PncState[PncIdx])
    {
        if((ComM_TimerType)0 != ComM_PncPrepareSleepTimer[PncIdx])
        {
            ComM_PncPrepareSleepTimer[PncIdx]--;
        }
    }
}

/********************************************************************************
* Function Name: ComM_S_MainFunctionPnc
*
* Description:   Main function of the Pnc
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_MainFunctionPnc
(
    NetworkHandleType Channel
)
{
    PNCHandleType PncIdx;/*Index value of Pnc*/

    ComM_S_EiraReceiveUpdate();
#if(STD_ON == COMM_PNC_GW_ENABLED)
    ComM_S_EraReceiveUpdate();
#endif
    for(PncIdx = (PNCHandleType)0; PncIdx < (PNCHandleType)COMM_NUM_OF_PNC; PncIdx++)
    {
        /*Manages the state of the PNC in the first Channel associated with the PNC.*/
        if(COMM_CFG_PNC_MAP_CHL(COMM_CFG_PNC_MAP_CHL_START(PncIdx)) == Channel)
        {
            ComM_S_TimerMainFunctionPnc(PncIdx);

            /*SWS_ComM_00909*/
            switch(ComM_PncState[PncIdx])
            {
            case COMM_PNC_NO_COMMUNICATION:
                ComM_S_PncNoComProc(PncIdx);
                break;
            case COMM_PNC_PREPARE_SLEEP:
                ComM_S_PncPrepareSleepProc(PncIdx);
                break;
            case COMM_PNC_READY_SLEEP:
                ComM_S_PncReadySleepProc(PncIdx);
                break;
            case COMM_PNC_REQUESTED:
                ComM_S_PncRequestedProc(PncIdx);
                break;
            default:
                /*do nothing*/
                break;
            }
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_EiraReceiveUpdate
*
* Description:   Update the EIRA value of Pnc accoding to the received EIRA data from Nm.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_EiraReceiveUpdate
(
    void
)
{
    PNCHandleType PncIdx;
    PNCHandleType PncID;
    uint8 PncByteIndex;
    uint8 PncBitIndex;

    if(TRUE == ComM_EiraUpdateFlag)
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_7();

        ComM_EiraUpdateFlag = FALSE;

        for(PncIdx = (PNCHandleType)0; PncIdx < (PNCHandleType)COMM_NUM_OF_PNC; PncIdx++)
        {
            /*Update the EIRA State according to the received EIRA*/
            PncID = COMM_CFG_PNC_ID(PncIdx);

            PncByteIndex = COMM_GET_PNC_BYTE_INDEX(PncID);
            PncBitIndex = COMM_GET_PNC_BIT_INDEX(PncID);

            if((uint8)(ComM_EiraData[PncByteIndex] & (uint8)((uint8)1 << PncBitIndex)) != (uint8)0)
            {
                ComM_EiraReqOfPnc[PncIdx] = TRUE;
            }
            else
            {
                ComM_EiraReqOfPnc[PncIdx] = FALSE;
            }
        }

        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_7();
    }
}

#if(STD_ON == COMM_PNC_GW_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_EraReceiveUpdate
*
* Description:   Update the ERA value of Pnc accoding to the received ERA data from Nm.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_EraReceiveUpdate
(
    void
)
{
    PNCHandleType PncIdx;
    PNCHandleType PncID;
    uint8 PncByteIndex;
    uint8 PncBitIndex;
    NetworkHandleType Channel;
    uint8 i;
    /*PRQA S 2213,3604 ++*/
    /*2213 Matching braces appear on the same line*/
    /*3604 Using an initializer when defining an array.*/
    uint8 TempData[COMM_PNC_DATA_LENGTH] = {0};
    /*PRQA S 2213,3604 --*/

    SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_7();

    for(Channel = (NetworkHandleType)0; Channel < (NetworkHandleType)COMM_NUM_OF_CAN_CHANNEL; Channel++)
    {
        if(COMM_GATEWAY_TYPE_NONE != COMM_CFG_CHL_PNC_GW_TYPE(Channel))
        {
            (void)Nm_GetERA(COMM_CFG_CHL_TO_NM(Channel), &(ComM_EraData[Channel][0]));

            for(i = (uint8)0; i < COMM_PNC_DATA_LENGTH; i++)
            {
                TempData[i] |= ComM_EraData[Channel][i];
            }

            for(PncIdx = (PNCHandleType)0; PncIdx < (PNCHandleType)COMM_NUM_OF_PNC; PncIdx++)
            {
                PncID = COMM_CFG_PNC_ID(PncIdx);

                PncByteIndex = COMM_GET_PNC_BYTE_INDEX(PncID);
                PncBitIndex = COMM_GET_PNC_BIT_INDEX(PncID);

                if((uint8)0 != (uint8)(ComM_EraData[Channel][PncByteIndex] & (uint8)((uint8)1 << PncBitIndex)))
                {
                    if(COMM_GATEWAY_TYPE_ACTIVE == COMM_CFG_CHL_PNC_GW_TYPE(Channel))
                    {
                        ComM_EraReqOfPnc[PncIdx] |= COMM_ERA_RECEIVED_ON_ACTIVE;
                    }
                    else
                    {
                        ComM_EraReqOfPnc[PncIdx] |= COMM_ERA_RECEIVED_ON_PASSIVE;
                    }
                }
            }
        }
    }

    for(PncIdx = (PNCHandleType)0; PncIdx < (PNCHandleType)COMM_NUM_OF_PNC; PncIdx++)
    {
        /*Update the EIRA State according to the received EIRA*/
        PncID = COMM_CFG_PNC_ID(PncIdx);

        PncByteIndex = COMM_GET_PNC_BYTE_INDEX(PncID);
        PncBitIndex = COMM_GET_PNC_BIT_INDEX(PncID);

        if((uint8)0 == (uint8)(TempData[PncByteIndex] & (uint8)((uint8)1 << PncBitIndex)))
        {
            ComM_EraReqOfPnc[PncIdx] = (uint8)0;
        }
    }

    SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_7();
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_PncNoComProc
*
* Description:   Process actions in PNC sub state PNC_NO_COMMUNICATION
*
* Inputs:        PncIdx
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_PncNoComProc
(
    PNCHandleType PncIdx
)
{
    if(ComM_UserReqPncCnt[PncIdx] > (uint8)0)
    {
        /*SWS_ComM_00932*/
        ComM_S_PncRequestedEnter(PncIdx);
    }
#if(STD_ON == COMM_PNC_GW_ENABLED)
    else if((uint8)0 != ComM_EraReqOfPnc[PncIdx])
    {
        /*SWS_ComM_01066*/
        ComM_S_PncRequestedEnter(PncIdx);
    }
#endif
    else if(TRUE == ComM_EiraReqOfPnc[PncIdx])
    {
        /*SWS_ComM_01065*/
        ComM_S_PncReadySleepEnter(PncIdx);
    }
    else
    {
        /*SWS_ComM_00990*//*SWS_ComM_01063*//*SWS_ComM_01064*/
        if(TRUE == ComM_PncWakeupFlag[PncIdx])
        {
            ComM_PncWakeupFlag[PncIdx] = FALSE;
            ComM_S_PncPrepareSleepEnter(PncIdx);
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_PncNoComEnter
*
* Description:   Process actions on entry of PNC sub state PNC_NO_COMMUNICATION
*
* Inputs:        PncIdx
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_PncNoComEnter
(
    PNCHandleType PncIdx
)
{
    ComM_PncState[PncIdx] = COMM_PNC_NO_COMMUNICATION;

    ComM_PncWakeupFlag[PncIdx] = FALSE;

    /*SWS_ComM_00908*/
    if(COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00976*//*SWS_ComM_00829*/
        BswM_ComM_CurrentPNCMode(COMM_CFG_PNC_ID(PncIdx), COMM_PNC_NO_COMMUNICATION);
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_PncRequestedProc
*
* Description:   Process actions in PNC sub state PNC_REQUESTED
*
* Inputs:        PncIdx
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_PncRequestedProc
(
    PNCHandleType PncIdx
)
{
#if(STD_ON == COMM_PNC_GW_ENABLED)
    PNCHandleType PncID;
    uint8 PncByteIndex;
    uint8 PncBitIndex;
    NetworkHandleType Channel;

    /*Uptate IRA bit value on passive channel*/
    if(COMSTACK_INVALID_NETWORK_HANDLE != ComM_PncPassiveChannel[PncIdx])
    {
        Channel = ComM_PncPassiveChannel[PncIdx];
        PncID = COMM_CFG_PNC_ID(PncIdx);
        PncByteIndex = COMM_GET_PNC_BYTE_INDEX(PncID);
        PncBitIndex = COMM_GET_PNC_BIT_INDEX(PncID);

        if((uint8)0 == (uint8)(ComM_IraTxData[Channel][PncByteIndex] & (uint8)((uint8)1 << PncBitIndex)))
        {
            if((ComM_UserReqPncCnt[PncIdx] > (uint8)0) \
                || ((uint8)0 != (uint8)(ComM_EraReqOfPnc[PncIdx] & COMM_ERA_RECEIVED_ON_ACTIVE)))
            {
                /*SWS_ComM_01076*//*SWS_ComM_01077*/
                ComM_IraTxData[Channel][PncByteIndex] |= (uint8)((uint8)1 << PncBitIndex);

                Nm_UpdateIRA(COMM_CFG_CHL_TO_NM(Channel), &(ComM_IraTxData[Channel][0]));
            }
        }
        else
        {
            if((ComM_UserReqPncCnt[PncIdx] == (uint8)0) \
                && ((uint8)0 == (uint8)(ComM_EraReqOfPnc[PncIdx] & COMM_ERA_RECEIVED_ON_ACTIVE)))
            {
                /*SWS_ComM_01079*/
                ComM_IraTxData[Channel][PncByteIndex] &= (uint8)(~(uint8)((uint8)1 << PncBitIndex));

                Nm_UpdateIRA(COMM_CFG_CHL_TO_NM(Channel), &(ComM_IraTxData[Channel][0]));
            }
        }
    }

    /*SWS_ComM_00991*//*SWS_ComM_01075*/
    if((ComM_UserReqPncCnt[PncIdx] == (uint8)0) && ((uint8)0 == ComM_EraReqOfPnc[PncIdx]))
#else
    if(ComM_UserReqPncCnt[PncIdx] == (uint8)0)
#endif
    {
#if(STD_ON == COMM_SYNC_PNC_SHUTDOWN_ENABLED)
        /*SWS_ComM_01082*//*SWS_ComM_01083*/
        if((TRUE == ComM_PncSyncShutdownFlag[PncIdx]) || (COMSTACK_INVALID_NETWORK_HANDLE == ComM_PncPassiveChannel[PncIdx]))
#endif
        {
            /*SWS_ComM_00938*/
            ComM_S_PncReadySleepEnter(PncIdx);
        }
    }

#if(STD_ON == COMM_SYNC_PNC_SHUTDOWN_ENABLED)
    ComM_PncSyncShutdownFlag[PncIdx] = FALSE;
#endif

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_PncRequestedEnter
*
* Description:   Process actions on entry of PNC sub state PNC_REQUESTED
*
* Inputs:        PncIdx
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_PncRequestedEnter
(
    PNCHandleType PncIdx
)
{
    PNCHandleType PncID;
    uint8 PncByteIndex;
    uint8 PncBitIndex;

    uint8 StartChannel;
    uint8 EndChannel;
    uint8 ChannelIdx;
    NetworkHandleType Channel;
    ComM_ModeType ComMode = COMM_NO_COMMUNICATION;
    ComM_PncModeType PncReqMode = COMM_PNC_REQUESTED;


    if(COMM_PNC_PREPARE_SLEEP == ComM_PncState[PncIdx])
    {
        /*Stop prepare sleep timer*//*SWS_ComM_00948*//*SWS_ComM_01089*/
        ComM_PncPrepareSleepTimer[PncIdx] = (ComM_TimerType)0;
    }

#if(COMM_NUM_OF_ETH_CHANNEL > 0)
    /*SWS_ComM_01067*/
    if((COMM_PNC_READY_SLEEP != ComM_PncState[PncIdx]) && (TRUE == COMM_CFG_PNC_WAKE_SLEEP_EN(PncIdx)))
    {
        PncReqMode = COMM_PNC_REQUESTED_WITH_WAKEUP_REQUEST;
    }
#endif

    ComM_PncState[PncIdx] = COMM_PNC_REQUESTED;

    /*Uptate IRA bit to 1*/
    PncID = COMM_CFG_PNC_ID(PncIdx);
    PncByteIndex = COMM_GET_PNC_BYTE_INDEX(PncID);
    PncBitIndex = COMM_GET_PNC_BIT_INDEX(PncID);

    StartChannel = COMM_CFG_PNC_MAP_CHL_START(PncIdx);
    EndChannel = StartChannel + COMM_CFG_PNC_MAP_CHL_NUM(PncIdx);

    for(ChannelIdx = StartChannel; ChannelIdx < EndChannel; ChannelIdx++)
    {
        Channel = COMM_CFG_PNC_MAP_CHL(ChannelIdx);

#if(STD_ON == COMM_PNC_GW_ENABLED)
        /*SWS_ComM_01068*//*SWS_ComM_01072*/
        if(COMM_GATEWAY_TYPE_PASSIVE != COMM_CFG_CHL_PNC_GW_TYPE(Channel))
#endif
        {
            /*SWS_ComM_00982*/
            ComM_IraTxData[Channel][PncByteIndex] |= (uint8)((uint8)1 << PncBitIndex);
            /*SWS_ComM_01062*/
            Nm_UpdateIRA(COMM_CFG_CHL_TO_NM(Channel), &(ComM_IraTxData[Channel][0]));
        }

        if((COMM_IS_NMVARIANT_FULL(Channel)) && (TRUE == COMM_CFG_CHL_PNC_NM_REQUEST(Channel)))
        {
            (void)ComM_S_BusSM_GetCurrentComMode(Channel, &ComMode);

            if(COMM_FULL_COMMUNICATION == ComMode)
            {
                /*SWS_ComM_00980*//*SWS_ComM_00667*/
                (void)Nm_NetworkRequest(COMM_CFG_CHL_TO_NM(Channel));
            }
            else
            {
                ComM_ReqPendingFlag[Channel] = TRUE;
            }
        }
    }

    /*SWS_ComM_00976*//*SWS_ComM_00908*//*SWS_ComM_00829*/
    BswM_ComM_CurrentPNCMode(COMM_CFG_PNC_ID(PncIdx), PncReqMode);

    /*SWS_ComM_00827*//*SWS_ComM_00929*//*SWS_ComM_01069*/
    /*SWS_ComM_01071*//*SWS_ComM_01073*//*SWS_ComM_01078*/
    ComM_S_PncRequestChannelMode(PncIdx, COMM_FULL_COMMUNICATION);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_PncReadySleepProc
*
* Description:   Process actions in PNC sub state PNC_READY_SLEEP
*
* Inputs:        PncIdx
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_PncReadySleepProc
(
    PNCHandleType PncIdx
)
{
    if(ComM_UserReqPncCnt[PncIdx] > (uint8)0)
    {
        /*SWS_ComM_01087*/
        ComM_S_PncRequestedEnter(PncIdx);
    }
#if(STD_ON == COMM_PNC_GW_ENABLED)
    else if((uint8)0 != ComM_EraReqOfPnc[PncIdx])
    {
        /*SWS_ComM_01088*/
        ComM_S_PncRequestedEnter(PncIdx);
    }
#endif
    else if(FALSE == ComM_EiraReqOfPnc[PncIdx])
    {
        /*SWS_ComM_00940*/
        ComM_S_PncPrepareSleepEnter(PncIdx);
    }
    else
    {
        /*stay in ready sleep*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_PncReadySleepEnter
*
* Description:   Process actions on entry of PNC sub state PNC_READY_SLEEP
*
* Inputs:        PncIdx
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_PncReadySleepEnter
(
    PNCHandleType PncIdx
)
{
    PNCHandleType PncID;
    uint8 PncByteIndex;
    uint8 PncBitIndex;

    uint8 StartChannel;
    uint8 EndChannel;
    uint8 ChannelIdx;
    NetworkHandleType Channel;

    /*From request to ready sleep*/
    if(COMM_PNC_REQUESTED == ComM_PncState[PncIdx])
    {
        /*Uptate IRA bit to 0*/
        PncID = COMM_CFG_PNC_ID(PncIdx);
        PncByteIndex = COMM_GET_PNC_BYTE_INDEX(PncID);
        PncBitIndex = COMM_GET_PNC_BIT_INDEX(PncID);

        StartChannel = COMM_CFG_PNC_MAP_CHL_START(PncIdx);
        EndChannel = StartChannel + COMM_CFG_PNC_MAP_CHL_NUM(PncIdx);

        for(ChannelIdx = StartChannel; ChannelIdx < EndChannel; ChannelIdx++)
        {
            Channel = COMM_CFG_PNC_MAP_CHL(ChannelIdx);

#if(STD_ON == COMM_SYNC_PNC_SHUTDOWN_ENABLED)
            /*SWS_ComM_01082*//*SWS_ComM_01083*/
            if(COMM_GATEWAY_TYPE_ACTIVE == COMM_CFG_CHL_PNC_GW_TYPE(Channel))
            {
                (void)Nm_RequestSynchronizedPncShutdown(COMM_CFG_CHL_TO_NM(Channel), PncID);
            }
#endif
            /*SWS_ComM_00982*//*SWS_ComM_01085*//*SWS_ComM_01080*/
            ComM_IraTxData[Channel][PncByteIndex] &= (uint8)(~(uint8)((uint8)1 << PncBitIndex));
            /*SWS_ComM_01062*/
            Nm_UpdateIRA(COMM_CFG_CHL_TO_NM(Channel), &(ComM_IraTxData[Channel][0]));
        }
        /*Release the COMM_FULL_COMMUNICATION request for all configured ComM channels for this PNC */
        /*SWS_ComM_01074*//*SWS_ComM_01081*//*SWS_ComM_01086*/
        ComM_S_PncRequestChannelMode(PncIdx, COMM_NO_COMMUNICATION);
    }
    else if(COMM_PNC_PREPARE_SLEEP == ComM_PncState[PncIdx])
    {
        /*Stop prepare sleep timer*//*SWS_ComM_00950*/
        ComM_PncPrepareSleepTimer[PncIdx] = (ComM_TimerType)0;
    }
    else
    {
        /* do nothing */
    }

    ComM_PncState[PncIdx] = COMM_PNC_READY_SLEEP;

    /*SWS_ComM_00976*//*SWS_ComM_00908*//*SWS_ComM_00829*/
    BswM_ComM_CurrentPNCMode(COMM_CFG_PNC_ID(PncIdx), COMM_PNC_READY_SLEEP);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_PncPrepareSleepProc
*
* Description:   Process actions in PNC sub state PNC_PREPARE_SLEEP
*
* Inputs:        PncIdx
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_PncPrepareSleepProc
(
    PNCHandleType PncIdx
)
{
    if(ComM_UserReqPncCnt[PncIdx] > (uint8)0)
    {
        /*SWS_ComM_00948*/
        ComM_S_PncRequestedEnter(PncIdx);
    }
#if(STD_ON == COMM_PNC_GW_ENABLED)
    else if((uint8)0 != ComM_EraReqOfPnc[PncIdx])
    {
        /*SWS_ComM_01089*/
        ComM_S_PncRequestedEnter(PncIdx);
    }
#endif
    else if(TRUE == ComM_EiraReqOfPnc[PncIdx])
    {
        /*SWS_ComM_00950*/
        ComM_S_PncReadySleepEnter(PncIdx);
    }
    else if((ComM_TimerType)0 == ComM_PncPrepareSleepTimer[PncIdx])
    {
        /*SWS_ComM_00947*/
        ComM_S_PncNoComEnter(PncIdx);
    }
    else
    {
        /*Stay in prepare sleep*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_S_PncPrepareSleepEnter
*
* Description:   Process actions on entry of PNC sub state PNC_PREPARE_SLEEP
*
* Inputs:        PncIdx
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COMM_CODE) ComM_S_PncPrepareSleepEnter
(
    PNCHandleType PncIdx
)
{
    NetworkHandleType Channel;

    ComM_PncState[PncIdx] = COMM_PNC_PREPARE_SLEEP;

    Channel = COMM_CFG_PNC_MAP_CHL(COMM_CFG_PNC_MAP_CHL_START(PncIdx));
    /*start the timer*//*SWS_ComM_00952*/
    ComM_PncPrepareSleepTimer[PncIdx] = (COMM_PNC_PREPARE_SLEEP_TIME/COMM_CFG_CHL_MAIN_PRRIOD(Channel));

    /*SWS_ComM_00976*//*SWS_ComM_00908*//*SWS_ComM_00829*/
    BswM_ComM_CurrentPNCMode(COMM_CFG_PNC_ID(PncIdx), COMM_PNC_PREPARE_SLEEP);
}
#endif/*#if(STD_ON == COMM_PNC_SUPPORT)*/






/*******************************************************************************
*  PUBLIC Functions define
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_Init  SWS_ComM_00146
*
* Description:   Initializes the AUTOSAR Communication Manager and restarts the
*                internal state machines.
*
* Inputs:        ConfigPtr: Pointer to post-build configuration data
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_Init
(
    P2CONST(ComM_ConfigType, AUTOMATIC, COMM_CONST) ConfigPtr
)
{
    NetworkHandleType Channel;
    ComM_UserHandleType User;
#if(STD_ON == COMM_MULTI_CORE_SUPPORT)
    uint8 CoreId;
#endif

#if(COMM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    if(NULL_PTR == ConfigPtr)
    {
        COMM_DET_REPORT_ERROR(COMM_INIT_APIID, COMM_E_PARAM_POINTER);
    }
    else
#else
    (void)ConfigPtr;
#endif
    {
#if(COMM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        ComM_ConfigSet = ConfigPtr;
#endif

        /*Check configuration parameters*/
        if(E_OK != ComM_S_CheckCfgParameters())
        {
            COMM_DET_REPORT_ERROR(COMM_INIT_APIID, COMM_E_INIT_FAILED);
        }
        else
        {
#if(COMM_NUM_OF_USER > 0)
            /*Reset all User ComMode*/
            for(User = (ComM_UserHandleType)0; User < (ComM_UserHandleType)COMM_NUM_OF_USER; User++)
            {
#if(STD_ON == COMM_MULTI_CORE_SUPPORT)
                for(CoreId = (uint8)0; CoreId < (uint8)COMM_NUM_OF_CORES; CoreId++)
                {
                    ComM_UserComMode[User][CoreId] = COMM_NO_COMMUNICATION;
                    ComM_UserLastComMode[User][CoreId] = COMM_NO_COMMUNICATION;
                }
#else
                ComM_UserComMode[User] = COMM_NO_COMMUNICATION;
#endif
            }
#endif
            /*Without NvM we should initialize the non-volatile variables here,
            otherwise NvM had done it before. SWS_ComM_00793 SWS_ComM_00864 */
#if(STD_OFF == COMM_NVM_SUPPORT)
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
            ComM_InhibitCounter = (uint16)0;
#endif
            ComM_EcuGroupClassfication = COMM_ECU_GROUP_CLASS_DEFAULT_VALUE;
#endif
            for(Channel = (NetworkHandleType)0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
            {
                /*SWS_ComM_00884*/
                ComM_TriggerInfo[Channel] = (uint16)0;
                ComM_UserReqChannelCnt[Channel] = (uint8)0;
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
                if(TRUE == COMM_CFG_CHL_NO_COM(Channel))
                {
                    ComM_TriggerInfo[Channel] |= COMM_LIMIT_TO_NO_COM_MASK;
                }
                else
                {
                    ComM_TriggerInfo[Channel] &= (uint16)(~COMM_LIMIT_TO_NO_COM_MASK);
                }
#endif

#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
                if(FALSE == COMM_CFG_CHL_NO_WAKEUP_STORAGE(Channel))
                {
                    if(TRUE == COMM_CFG_CHL_NO_WAKEUP(Channel))
                    {
                        ComM_NoWakeupStatus(Channel) = TRUE;
                    }
                    else
                    {
                        ComM_NoWakeupStatus(Channel) = FALSE;
                    }
                }
#endif

#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
                ComM_TMinFullComModeDurationTimer[Channel] = (ComM_TimerType)0;
#endif
#if(STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
                ComM_NmLightTimeoutTimer[Channel] = (ComM_TimerType)0;
#endif
                /*SWS_ComM_00485*/
                ComM_S_ChannelNoComEnter(Channel);
                /*if the return value of <BusSM>_RequestComMode is not OK at this time, no need to set the RequestPending flag*/
                ComM_BusSM_RequestPending[Channel] = FALSE;
            }

/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
            ComM_S_InitPnc();
#endif
            COMM_SET_INITIALIZED();
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_DeInit  SWS_ComM_00147
*
* Description:   This API de-initializes the AUTOSAR Communication Manager
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_DeInit
(
    void
)
{
    NetworkHandleType Channel;

    if(COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00794 Caller need to make sure all channels controlled by the ComM module
        are in COMM_NO_COMMUNICATION mode.*/
        for(Channel = (NetworkHandleType)0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
        {
#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
            ComM_TMinFullComModeDurationTimer[Channel] = (ComM_TimerType)0;
#endif
#if(STD_ON == COMM_NMVARIANT_LIGHT_ENABLED)
            ComM_NmLightTimeoutTimer[Channel] = (ComM_TimerType)0;
#endif
            ComM_Mode[Channel] = COMM_NO_COMMUNICATION;
            ComM_State[Channel] = COMM_NO_COM_NO_PENDING_REQUEST;
        }

/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
        ComM_S_DeInitPnc();
#endif

#if(STD_ON == COMM_NVM_SUPPORT)
        /*SWS_ComM_00865*/
        NvM_SetRamBlockStatus(COMM_GLOBAL_NVM_BLOCK_REF, TRUE);
#endif
        COMM_SET_UNINITIALIZED();
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_GetStatus  SWS_ComM_00242
*
* Description:   Returns the initialization status of the AUTOSAR Communication Manager
*
* Inputs:        None
*
* Outputs:       Status: COMM_UNINIT, COMM_INIT
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetStatus
(
    P2VAR(ComM_InitStatusType, AUTOMATIC, COMM_APPL_DATA) Status
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(NULL_PTR == Status)
    {
        COMM_DET_REPORT_ERROR(COMM_GETSTATUS_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        *Status = COMM_GET_INIT_STATUS();
        ret = E_OK;
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_GetInhibitionStatus  SWS_ComM_00619
*
* Description:   Returns the inhibition status of a ComM channel.
*
* Inputs:        Channel: ComM channel
*
* Outputs:       Status: Indication a mode inhibition is active or not.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetInhibitionStatus
(
    NetworkHandleType Channel,
    P2VAR(ComM_InhibitionStatusType, AUTOMATIC, COMM_APPL_DATA) Status
)
{
    ComM_InhibitionStatusType TempStatus;
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_GETINHIBITIONSTATUS_APIID, COMM_E_UNINIT);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_GETINHIBITIONSTATUS_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else if(NULL_PTR == Status)
    {
        COMM_DET_REPORT_ERROR(COMM_GETINHIBITIONSTATUS_APIID, COMM_E_PARAM_POINTER);
    }
#if(STD_ON == COMM_MULTI_CORE_SUPPORT)
    else if(COMM_GETCOREID() != COMM_CFG_CHL_MAP_CORE(Channel))
    {
        COMM_DET_REPORT_ERROR(COMM_GETINHIBITIONSTATUS_APIID, COMM_E_CALLED_IN_WRONG_CORE);
    }
#endif
    else
    {
        TempStatus = (ComM_InhibitionStatusType)0;
#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
        if(TRUE == ComM_NoWakeupStatus(Channel))
        {
            TempStatus = COMM_WAKE_UP_INHIBITION_ACTIVE_BIT;
        }
#endif
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
        if((uint16)0 != (uint16)(ComM_TriggerInfo[Channel] & COMM_LIMIT_TO_NO_COM_MASK))
        {
            TempStatus |= COMM_LIMITED_TO_NO_COM_BIT;
        }
#endif
        *Status = TempStatus;
        ret = E_OK;
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_RequestComMode  SWS_ComM_00110
*
* Description:   Requesting of a Communication Mode by a user
*
* Inputs:        User:Handle of the user who requests a mode
*                ComMode: Mode that user requestes
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_RequestComMode
(
    ComM_UserHandleType User,
    ComM_ModeType ComMode
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(STD_ON == COMM_MULTI_CORE_SUPPORT)
    uint8 CoreId;
#endif

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_REQUESTCOMMODE_APIID, COMM_E_UNINIT);
    }
#if(COMM_NUM_OF_USER > 0)
    else if(User >= (ComM_UserHandleType)COMM_NUM_OF_USER)
    {
        COMM_DET_REPORT_ERROR(COMM_REQUESTCOMMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    /*SWS_ComM_00151*/
    else if((COMM_NO_COMMUNICATION != ComMode) && (COMM_FULL_COMMUNICATION != ComMode))
    {
        COMM_DET_REPORT_ERROR(COMM_REQUESTCOMMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_0();

        /*SWS_ComM_00839*//*SWS_ComM_00972*/
#if(STD_ON == COMM_MULTI_CORE_SUPPORT)
        CoreId = COMM_GETCOREID();
        /*SWS_ComM_01019*/
        ComM_UserComMode[User][CoreId] = ComMode;
        ret = E_OK;
#else
        ComM_UserComMode[User] = ComMode;
/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
        ComM_S_UserRequestPncMode(User, ComMode);
#endif

        ret = ComM_S_UserRequestChannelMode(User, ComMode);
#endif
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_0();
    }
#endif

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_GetMaxComMode  SWS_ComM_00085
*
* Description:   Function to query the maximum allowed Communication Mode of the
*                corresponding user.
*
* Inputs:        User:Handle of the user who requests a mode
*
* Outputs:       ComMode
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetMaxComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
#if(COMM_NUM_OF_USER > 0)
#if((STD_ON == COMM_MODE_LIMITATION_ENABLED) || (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED))
    NetworkHandleType Channel;
    uint8 ChannelIdx;
    uint8 StartChannel;
    uint8 EndChannel;
#endif
    ComM_ModeType TempComMode;
#endif
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_GETMAXCOMMODE_APIID, COMM_E_UNINIT);
    }
#if(COMM_NUM_OF_USER > 0)
    else if(User >= (ComM_UserHandleType)COMM_NUM_OF_USER)
    {
        COMM_DET_REPORT_ERROR(COMM_GETMAXCOMMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else if(NULL_PTR == ComMode)
    {
        COMM_DET_REPORT_ERROR(COMM_GETMAXCOMMODE_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        /*Set highest mode as the initial value*/
        TempComMode = COMM_FULL_COMMUNICATION;
#if((STD_ON == COMM_MODE_LIMITATION_ENABLED) || (STD_ON == COMM_WAKEUP_INHIBITION_ENABLED))
        StartChannel = COMM_CFG_USER_MAP_CHL_START(User);
        EndChannel = StartChannel + COMM_CFG_USER_MAP_CHL_NUM(User);

        for(ChannelIdx = StartChannel; ChannelIdx < EndChannel; ChannelIdx++)
        {
            /*SWS_ComM_00796*/
            Channel = COMM_CFG_USER_MAP_CHL(ChannelIdx);

#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
            if(((uint16)0 != (uint16)(ComM_TriggerInfo[Channel] & COMM_LIMIT_TO_NO_COM_MASK)) \
                && ((ComM_InhibitionStatusType)0 != (ComM_InhibitionStatusType)(ComM_EcuGroupClassfication & COMM_LIMITED_TO_NO_COM_BIT)))
            {
                /*SWS_ComM_00374*/
                TempComMode = COMM_NO_COMMUNICATION;
                break;
            }
#endif
#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
            if(((ComM_InhibitionStatusType)0 != (ComM_InhibitionStatusType)(ComM_EcuGroupClassfication & COMM_WAKE_UP_INHIBITION_ACTIVE_BIT)) \
                && (TRUE == ComM_NoWakeupStatus(Channel)))
            {
                /*SWS_ComM_00374*/
                TempComMode = COMM_NO_COMMUNICATION;
                break;
            }
#endif
        }
#endif
        *ComMode = TempComMode;
        ret = E_OK;
    }
#endif/*#if(COMM_NUM_OF_USER > 0)*/

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_GetRequestedComMode  SWS_ComM_00079
*
* Description:   Function to query the currently requested Communication Mode
*                of the corresponding user.
*
* Inputs:        User:Handle of the user who requests a mode
*
* Outputs:       ComMode
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetRequestedComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
    Std_ReturnType ret = E_NOT_OK;
#if(STD_ON == COMM_MULTI_CORE_SUPPORT)
    uint8 CoreId;
#endif

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_GETREQUESTEDCOMMODE_APIID, COMM_E_UNINIT);
    }
#if(COMM_NUM_OF_USER > 0)
    else if(User >= (ComM_UserHandleType)COMM_NUM_OF_USER)
    {
        COMM_DET_REPORT_ERROR(COMM_GETREQUESTEDCOMMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else if(NULL_PTR == ComMode)
    {
        COMM_DET_REPORT_ERROR(COMM_GETREQUESTEDCOMMODE_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
#if(STD_ON == COMM_MULTI_CORE_SUPPORT)
        *ComMode = COMM_NO_COMMUNICATION;
        for(CoreId = (uint8)0; CoreId < (uint8)COMM_NUM_OF_CORES; CoreId++)
        {
            if(ComM_UserComMode[User][CoreId] == COMM_FULL_COMMUNICATION)
            {
                *ComMode = COMM_FULL_COMMUNICATION;
                break;
            }
        }
#else
        *ComMode = ComM_UserComMode[User];
#endif
        ret = E_OK;
    }
#endif

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_GetCurrentComMode  SWS_ComM_00083
*
* Description:   Function to query the current Communication Mode.
*
* Inputs:        User:Handle of the user who requests a mode
*
* Outputs:       ComMode
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurrentComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
#if(COMM_NUM_OF_USER > 0)
    NetworkHandleType Channel;
    uint8 ChannelIdx;
    uint8 StartChannel;
    uint8 EndChannel;
    ComM_ModeType BusMode;
    ComM_ModeType TempComMode;
#endif
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_GETCURRENTCOMMODE_APIID, COMM_E_UNINIT);
    }
#if(COMM_NUM_OF_USER > 0)
    else if(User >= (ComM_UserHandleType)COMM_NUM_OF_USER)
    {
        COMM_DET_REPORT_ERROR(COMM_GETCURRENTCOMMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else if(NULL_PTR == ComMode)
    {
        COMM_DET_REPORT_ERROR(COMM_GETCURRENTCOMMODE_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        /*set highest mode as the initial value*/
        TempComMode = COMM_FULL_COMMUNICATION;

        StartChannel = COMM_CFG_USER_MAP_CHL_START(User);
        EndChannel = StartChannel + COMM_CFG_USER_MAP_CHL_NUM(User);

        for(ChannelIdx = StartChannel; ChannelIdx < EndChannel; ChannelIdx++)
        {
            /*SWS_ComM_00798*/
            Channel = COMM_CFG_USER_MAP_CHL(ChannelIdx);
            /*SWS_ComM_00084*/
            ret = ComM_S_BusSM_GetCurrentComMode(Channel, &BusMode);

            if(E_OK != ret)
            {
                break;
            }

            if(COMM_NO_COMMUNICATION == BusMode)
            {
                /*SWS_ComM_00176*/
                TempComMode = COMM_NO_COMMUNICATION;
                /*PRQA S 771 ++*/
                /*Specific implementation methods, there is no need to modify.*/
                break;
                /*PRQA S 711 --*/
            }
            else if(COMM_SILENT_COMMUNICATION == BusMode)
            {
                /*SWS_ComM_00176*/
                TempComMode = COMM_SILENT_COMMUNICATION;
            }
            else
            {
                /*do nothing*/
            }

        }
        *ComMode = TempComMode;
    }
#endif

    return ret;
}

/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_GetCurrentPNCComMode  SWS_ComM_91002
*
* Description:   The function returns the current Communication Mode of the
*                corresponding PNC the affected user is assigned to.
*
* Inputs:        User:Handle of the user who requests a mode
*
* Outputs:       ComMode
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurrentPNCComMode
(
    ComM_UserHandleType User,
    P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_DATA) ComMode
)
{
#if(COMM_NUM_OF_USER > 0)
    PNCHandleType PncIdx;
#endif
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_GETCURRENTPNCCOMMODE_APIID, COMM_E_UNINIT);
    }
#if(COMM_NUM_OF_USER > 0)
    else if(User >= (ComM_UserHandleType)COMM_NUM_OF_USER)
    {
        COMM_DET_REPORT_ERROR(COMM_GETCURRENTPNCCOMMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else if(NULL_PTR == ComMode)
    {
        COMM_DET_REPORT_ERROR(COMM_GETCURRENTPNCCOMMODE_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        if(COMM_CFG_USER_MAP_PNC_NUM(User) == (uint8)0)
        {
            /*SWS_ComM_01023*/
            ret = COMM_E_NO_PNC_ASSIGNED;
        }
        else if(COMM_CFG_USER_MAP_PNC_NUM(User) > (uint8)1)
        {
            /*SWS_ComM_01022*/
            ret = COMM_E_MULTIPLE_PNC_ASSIGNED;
        }
        else
        {
            /*SWS_ComM_01025*/
            PncIdx = COMM_CFG_USER_MAP_PNC(COMM_CFG_USER_MAP_PNC_START(User));
            /*SWS_ComM_01024*/
            if(COMM_PNC_NO_COMMUNICATION == ComM_PncState[PncIdx])
            {
                *ComMode = COMM_NO_COMMUNICATION;
            }
            else
            {
                *ComMode = COMM_FULL_COMMUNICATION;
            }

            ret = E_OK;
        }
    }
#endif

    return ret;
}
#endif


/*SWS_ComM_00799*/
#if(STD_ON == COMM_WAKEUP_INHIBITION_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_PreventWakeUp  SWS_ComM_00156
*
* Description:   Changes the inhibition status COMM_NO_WAKEUP for the corresponding channel.
*
* Inputs:        Channel
*                Status:FALSE: Wake up inhibition is switched off
*                       TRUE: Wake up inhibition is switched on
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_PreventWakeUp
(
    NetworkHandleType Channel,
    boolean Status
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_PREVENTWAKEUP_APIID, COMM_E_UNINIT);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_PREVENTWAKEUP_APIID, COMM_E_WRONG_PARAMETERS);
    }
#if(STD_ON == COMM_MULTI_CORE_SUPPORT)
    else if(COMM_GETCOREID() != COMM_CFG_CHL_MAP_CORE(Channel))
    {
        COMM_DET_REPORT_ERROR(COMM_PREVENTWAKEUP_APIID, COMM_E_CALLED_IN_WRONG_CORE);
    }
#endif
    else
    {
        if((uint8)0 != ComM_EcuGroupClassfication)
        {
            SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_6();
            /*SWS_ComM_00470*/
            ComM_NoWakeupStatus(Channel) = Status;

            ComM_S_UpdateKeepComFlag(Channel);

            SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_6();
#if(STD_ON == COMM_NVM_SUPPORT)
            /*SWS_ComM_00157*//*SWS_ComM_00103*/
            NvM_SetRamBlockStatus(COMM_GLOBAL_NVM_BLOCK_REF, TRUE);
#endif
            ret = E_OK;
        }
    }

    return ret;
}
#endif

/*SWS_ComM_00800*//*SWS_ComM_00801*//*SWS_ComM_00802*//*SWS_ComM_00803*/
#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_LimitChannelToNoComMode  SWS_ComM_00163 SWS_ComM_00301
*
* Description:   Changes the inhibition status for the channel for changing
*                from COMM_NO_COMMUNICATION to a higher Communication Mode.
*
* Inputs:        Channel
*                Status:FALSE: Limit channel to COMM_NO_COMMUNICATION disabled
*                       TRUE: Limit channel to COMM_NO_COMMUNICATION enabled
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_LimitChannelToNoComMode
(
    NetworkHandleType Channel,
    boolean Status
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_LIMITCHANNELTONOCOMMODE_APIID, COMM_E_UNINIT);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_LIMITCHANNELTONOCOMMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
#if(STD_ON == COMM_MULTI_CORE_SUPPORT)
    else if(COMM_GETCOREID() != COMM_CFG_CHL_MAP_CORE(Channel))
    {
        COMM_DET_REPORT_ERROR(COMM_LIMITCHANNELTONOCOMMODE_APIID, COMM_E_CALLED_IN_WRONG_CORE);
    }
#endif
    else
    {
        if((uint8)0 != ComM_EcuGroupClassfication)
        {
            SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_6();
            /*SWS_ComM_00470*//*SWS_ComM_00842*//*SWS_ComM_00488*/
            if(TRUE != Status)
            {
                ComM_TriggerInfo[Channel] &= (uint16)(~COMM_LIMIT_TO_NO_COM_MASK);
            }
            else
            {
                ComM_TriggerInfo[Channel] |= COMM_LIMIT_TO_NO_COM_MASK;
            }
            ComM_S_UpdateKeepComFlag(Channel);

            SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_6();

            ret = E_OK;
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_LimitECUToNoComMode  SWS_ComM_00124 SWS_ComM_00301
*
* Description:   Changes the inhibition status for the ECU (=all channels) for changing
*                from COMM_NO_COMMUNICATION to a higher Communication Mode.
*
* Inputs:        Status:FALSE: Limit ECU to COMM_NO_COMMUNICATION disabled
*                       TRUE: Limit ECU to COMM_NO_COMMUNICATION enabled
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_LimitECUToNoComMode
(
    boolean Status
)
{
    NetworkHandleType Channel;
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_LIMITECUTONOCOMMODE_APIID, COMM_E_UNINIT);
    }
    else
    {
        if((uint8)0 != ComM_EcuGroupClassfication)
        {
            /*SWS_ComM_00470*/
            if(TRUE != Status)
            {
                for(Channel = (NetworkHandleType)0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
                {
                    SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_6();

                    ComM_TriggerInfo[Channel] &= (uint16)(~COMM_LIMIT_TO_NO_COM_MASK);
                    ComM_S_UpdateKeepComFlag(Channel);

                    SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_6();
                }
            }
            else
            {
                for(Channel = (NetworkHandleType)0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
                {
                    SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_6();

                    ComM_TriggerInfo[Channel] |= COMM_LIMIT_TO_NO_COM_MASK;
                    ComM_S_UpdateKeepComFlag(Channel);

                    SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_6();
                }
            }

            ret = E_OK;
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_ReadInhibitCounter  SWS_ComM_00224
*
* Description:   This function returns the amount of rejected COMM_FULL_COMMUNICATION
*                user requests.
*
* Inputs:        None
*
* Outputs:       CounterValue:Amount of rejected COMM_FULL_COMMUNICATION user requests.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_ReadInhibitCounter
(
    P2VAR(uint16, AUTOMATIC, COMM_APPL_DATA) CounterValue
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_READINHIBITCOUNTER_APIID, COMM_E_UNINIT);
    }
    else if(NULL_PTR == CounterValue)
    {
        COMM_DET_REPORT_ERROR(COMM_READINHIBITCOUNTER_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        /*SWS_ComM_00143*/
        *CounterValue = ComM_InhibitCounter;
        ret = E_OK;
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_ResetInhibitCounter  SWS_ComM_00108
*
* Description:   This function resets the Inhibited COMM_FULL_COMMUNICATION request Counter.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_ResetInhibitCounter
(
    void
)
{
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_RESETINHIBITCOUNTER_APIID, COMM_E_UNINIT);
    }
    else
    {
        /*SWS_ComM_00143*/
        ComM_InhibitCounter = (uint16)0;
#if(STD_ON == COMM_NVM_SUPPORT)
        /*SWS_ComM_00103*/
        NvM_SetRamBlockStatus(COMM_GLOBAL_NVM_BLOCK_REF, TRUE);
#endif
        ret = E_OK;
    }

    return ret;
}
#endif/*#if(STD_ON == COMM_MODE_LIMITATION_ENABLED)*/




/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_SetECUGroupClassification  SWS_ComM_00552 SWS_ComM_00301
*
* Description:   Changes the ECU Group Classification status
*
* Inputs:        Status
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, COMM_CODE) ComM_SetECUGroupClassification
(
    ComM_InhibitionStatusType Status
)
{
#if((STD_ON == COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON == COMM_MODE_LIMITATION_ENABLED))
    NetworkHandleType Channel;
#endif
    Std_ReturnType ret = E_NOT_OK;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_SETECUGROUPCLASSIFICATION_APIID, COMM_E_UNINIT);
    }
    else if((ComM_InhibitionStatusType)0 != (ComM_InhibitionStatusType)(Status & COMM_INHIBITION_INVALID_MASK))
    {
        COMM_DET_REPORT_ERROR(COMM_SETECUGROUPCLASSIFICATION_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        /*SWS_ComM_00470*/
        ComM_EcuGroupClassfication = Status;

#if((STD_ON == COMM_WAKEUP_INHIBITION_ENABLED) || (STD_ON == COMM_MODE_LIMITATION_ENABLED))
        for(Channel = (NetworkHandleType)0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
        {
            SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_6();

            ComM_S_UpdateKeepComFlag(Channel);

            SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_6();
        }
#endif

#if(STD_ON == COMM_NVM_SUPPORT)
        /*SWS_ComM_00103*/
        NvM_SetRamBlockStatus(COMM_GLOBAL_NVM_BLOCK_REF, TRUE);
#endif
        ret = E_OK;
    }

    return ret;
}

/*SWS_ComM_00823*/
#if(STD_ON == COMM_VERSION_INFO_API)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_GetVersionInfo  SWS_ComM_00370
*
* Description:   This function returns the version information of this module
*
* Inputs:        None
*
* Outputs:       VersionInfo: Pointer to where to store the version information
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, COMM_APPL_DATA) VersionInfo
)
{
    if(NULL_PTR == VersionInfo)
    {
        COMM_DET_REPORT_ERROR(COMM_GETVERSIONINFO_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        /*SWS_ComM_00822*/
        VersionInfo->vendorID = COMM_VENDOR_ID;
        VersionInfo->moduleID = COMM_MODULE_ID;

        VersionInfo->sw_major_version = (uint8)COMM_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)COMM_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)COMM_SW_PATCH_VERSION;
    }
}
#endif





/*******************************************************************************
*   Callback Functions
*******************************************************************************/
#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_Nm_NetworkStartIndication  SWS_ComM_00383
*
* Description:   Indication that a NM-message has been received in the Bus Sleep
*                Mode, what indicates that some nodes in the network have already
*                entered the Network Mode
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_Nm_NetworkStartIndication
(
    NetworkHandleType Channel
)
{
    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_NM_NETWORKSTARTINDICATION_APIID, COMM_E_UNINIT);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_NM_NETWORKSTARTINDICATION_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_2();
        /*SWS_ComM_00903*//*SWS_ComM_00583*/
        ComM_TriggerInfo[Channel] |= COMM_NETWORK_START_IND_MASK;
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_2();
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_Nm_NetworkMode  SWS_ComM_00390
*
* Description:   Notification that the network management has entered Network Mode
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_Nm_NetworkMode
(
    NetworkHandleType Channel
)
{
    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_NM_NETWORKMODE_APIID, COMM_E_UNINIT);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_NM_NETWORKMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_2();
        /*SWS_ComM_00296*/
        ComM_TriggerInfo[Channel] &= (uint16)(~COMM_NM_MODE_IND_MASK);
        ComM_TriggerInfo[Channel] |= COMM_NM_MODE_NETWORK;
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_2();
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_Nm_PrepareBusSleepMode  SWS_ComM_00391
*
* Description:   Notification that the network management has entered Prepare Bus-Sleep Mode
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_Nm_PrepareBusSleepMode
(
    NetworkHandleType Channel
)
{
    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_NM_PREPAREBUSSLEEPMODE_APIID, COMM_E_UNINIT);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_NM_PREPAREBUSSLEEPMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_2();
        /*SWS_ComM_00826*/
        ComM_TriggerInfo[Channel] &= (uint16)(~COMM_NM_MODE_IND_MASK);
        ComM_TriggerInfo[Channel] |= COMM_NM_MODE_PBS;
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_2();
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_Nm_BusSleepMode  SWS_ComM_00392
*
* Description:   Notification that the network management has entered Bus-Sleep Mode
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_Nm_BusSleepMode
(
    NetworkHandleType Channel
)
{
    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_NM_BUSSLEEPMODE_APIID, COMM_E_UNINIT);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_NM_BUSSLEEPMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_2();
        /*SWS_ComM_00637*/
        ComM_TriggerInfo[Channel] &= (uint16)(~COMM_NM_MODE_IND_MASK);
        ComM_TriggerInfo[Channel] |= COMM_NM_MODE_BUS_SLEEP;
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_2();
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_Nm_RestartIndication  SWS_ComM_00792
*
* Description:   If NmIf has started to shut down the coordinated busses, AND
*                not all coordinated busses have indicated bus sleep state, AND
*                on at least on one of the coordinated busses NM is restarted, THEN
*                the NM Interface shall call the callback function
*                ComM_Nm_RestartIndication with the nmNetworkHandle of the
*                channels which have already indicated bus sleep state.
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_Nm_RestartIndication
(
    NetworkHandleType Channel
)
{
    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_NM_RESTARTINDICATION_APIID, COMM_E_UNINIT);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_NM_RESTARTINDICATION_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_2();
        /*SWS_ComM_00894*//*SWS_ComM_00902*/
        ComM_TriggerInfo[Channel] |= COMM_NM_RESTART_IND_MASK;
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_2();
    }
}

/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
#if(STD_ON == COMM_DYN_PNC_TO_CHL_MAP_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_Nm_RepeatMessageLeftIndication  SWS_ComM_91024
*
* Description:   Notification that the state of all <BusNm> has left RepeatMessage.
*                This interface is used to indicate by the optional Dynamic PNC-to-
*                channel-mapping feature to indicate that learning phase ends.
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_Nm_RepeatMessageLeftIndication
(
    NetworkHandleType Channel
)
{
    (void)Channel;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_Nm_PncLearningBitIndication  SWS_ComM_91026
*
* Description:   Service to indicate that an NM message with set PNC Learning
*                Bit has been received.
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_Nm_PncLearningBitIndication
(
    NetworkHandleType Channel
)
{
    (void)Channel;
}
#endif/*#if(STD_ON == COMM_DYN_PNC_TO_CHL_MAP_SUPPORT)*/

#if(STD_ON == COMM_PNC_GW_ENABLED)
#if(STD_ON == COMM_SYNC_PNC_SHUTDOWN_ENABLED)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_Nm_ForwardSynchronizedPncShutdown  SWS_ComM_91030
*
* Description:   If an ECU in role of an intermediate PNC coordinator receives a
*                PN shutdown message via a <Bus>Nm, then ComM is immediately
*                indicated via ComM_Nm_ForwardSynchronizedPncShutdown to forward
*                the request for a synchronized PNC shutdown of the affected PNCs
*                given by PncBitVectorPtr. Therefore, ComM will immediately release
*                the affected PNC state machines and forward the PN information to
*                the affected ComM Channels and the corresponding NM channels, respectively.
*
* Inputs:        Channel
*                PncBitVectorPtr:Pointer to PNC Bit vector with all PNC bits set
*                                to "1" which are indicated for a synchronized PNC
*                                shutdown.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_Nm_ForwardSynchronizedPncShutdown
(
    NetworkHandleType Channel,
    P2CONST(uint8, AUTOMATIC, COMM_APPL_DATA) PncBitVectorPtr
)
{
    PNCHandleType PncIdx;
    uint8 ChannelIdx;
    uint8 StartChannel;
    uint8 EndChannel;
    PNCHandleType PncID;
    uint8 PncByteIndex;
    uint8 PncBitIndex;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_NM_FORWARDSYNCPNCSHUTDOWN_APIID, COMM_E_UNINIT);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_NM_FORWARDSYNCPNCSHUTDOWN_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else if(PncBitVectorPtr == NULL_PTR)
    {
        COMM_DET_REPORT_ERROR(COMM_NM_FORWARDSYNCPNCSHUTDOWN_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        /*SWS_ComM_00911*//*SWS_ComM_01082*/
        if((TRUE == COMM_PNC_ENABLED) && (COMM_GATEWAY_TYPE_NONE != COMM_CFG_CHL_PNC_GW_TYPE(Channel)))
        {
            SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_8();

            for(PncIdx = (PNCHandleType)0; PncIdx < (PNCHandleType)COMM_NUM_OF_PNC; PncIdx++)
            {
                StartChannel = COMM_CFG_PNC_MAP_CHL_START(PncIdx);
                EndChannel = StartChannel + COMM_CFG_PNC_MAP_CHL_NUM(PncIdx);

                for(ChannelIdx = StartChannel; ChannelIdx < EndChannel; ChannelIdx++)
                {
                    if(Channel == COMM_CFG_PNC_MAP_CHL(ChannelIdx))
                    {
                        PncID = COMM_CFG_PNC_ID(PncIdx);
                        PncByteIndex = COMM_GET_PNC_BYTE_INDEX(PncID);
                        PncBitIndex = COMM_GET_PNC_BIT_INDEX(PncID);

                        if((uint8)0 != (uint8)(PncBitVectorPtr[PncByteIndex] & (uint8)((uint8)1 << PncBitIndex)))
                        {
                            ComM_PncSyncShutdownFlag[PncIdx] = TRUE;
                        }
                        break;
                    }
                }
            }

            SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_8();
        }
    }
}
#endif/*#if(STD_ON == COMM_SYNC_PNC_SHUTDOWN_ENABLED)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_Nm_UpdateERA  SWS_ComM_91029
*
* Description:   Function to indicate the current external PNC request per channel
*                called by Nm.
*
* Inputs:        Channel
*                PncBitVectorPtr:PNC bit vector which contain the current external
*                                PNC requests (ERA) received on the given channel.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_Nm_UpdateERA
(
    NetworkHandleType Channel,
    P2CONST(uint8, AUTOMATIC, COMM_APPL_DATA) PncBitVectorPtr
)
{
    uint8 i;
    PNCHandleType PncIdx;
    PNCHandleType PncID;
    uint8 PncByteIndex;
    uint8 PncBitIndex;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_NM_UPDATEERA_APIID, COMM_E_UNINIT);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_NM_UPDATEERA_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else if(PncBitVectorPtr == NULL_PTR)
    {
        COMM_DET_REPORT_ERROR(COMM_NM_UPDATEERA_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        /*SWS_ComM_00911*//*SWS_ComM_01061*//*SWS_ComM_01080*//*SWS_ComM_01075*/
        /*SWS_ComM_01088*//*SWS_ComM_01089*/
        if((TRUE == COMM_PNC_ENABLED) && (COMM_GATEWAY_TYPE_NONE != COMM_CFG_CHL_PNC_GW_TYPE(Channel)))
        {
            SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_7();

            ComM_EraUpdateFlag = TRUE;

            for(i = (uint8)0; i < COMM_PNC_DATA_LENGTH; i++)
            {
                /*SWS_ComM_00982*/
                ComM_EraData[Channel][i] = PncBitVectorPtr[i];
            }

            for(PncIdx = (PNCHandleType)0; PncIdx < (PNCHandleType)COMM_NUM_OF_PNC; PncIdx++)
            {
                PncID = COMM_CFG_PNC_ID(PncIdx);

                PncByteIndex = COMM_GET_PNC_BYTE_INDEX(PncID);
                PncBitIndex = COMM_GET_PNC_BIT_INDEX(PncID);

                if((uint8)0 != (uint8)(PncBitVectorPtr[PncByteIndex] & (uint8)((uint8)1 << PncBitIndex)))
                {
                    if(COMM_GATEWAY_TYPE_ACTIVE == COMM_CFG_CHL_PNC_GW_TYPE(Channel))
                    {
                        ComM_EraReqOfPnc[PncIdx] |= COMM_ERA_RECEIVED_ON_ACTIVE;
                    }
                    else
                    {
                        ComM_EraReqOfPnc[PncIdx] |= COMM_ERA_RECEIVED_ON_PASSIVE;
                    }
                }
            }

            SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_7();
        }
    }
}
#endif/*#if(STD_ON == COMM_PNC_GW_ENABLED)*/


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_Nm_UpdateEIRA  SWS_ComM_91028
*
* Description:   Function to indicate the current aggregated external / internal
*                PNC request called by Nm.
*
* Inputs:        PncBitVectorPtr:Pointer to the PNC bit vector which contain the
*                                current aggregated internal and external PNC
*                                requests (EIRA).
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_Nm_UpdateEIRA
(
    P2CONST(uint8, AUTOMATIC, COMM_APPL_DATA) PncBitVectorPtr
)
{
    uint8 i;

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_NM_UPDATEEIRA_APIID, COMM_E_UNINIT);
    }
    else if(PncBitVectorPtr == NULL_PTR)
    {
        COMM_DET_REPORT_ERROR(COMM_NM_UPDATEEIRA_APIID, COMM_E_PARAM_POINTER);
    }
    else
    {
        /*SWS_ComM_00911*/
        if(TRUE == COMM_PNC_ENABLED)
        {
            SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_7();

            ComM_EiraUpdateFlag = TRUE;
            /*SWS_ComM_01060*/
            for(i = (uint8)0; i < COMM_PNC_DATA_LENGTH; i++)
            {
                /*SWS_ComM_00982*/
                ComM_EiraData[i] = PncBitVectorPtr[i];
            }

            SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_7();
        }
    }
}

#endif/*#if(STD_ON == COMM_PNC_SUPPORT)*/

#endif/*#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))*/



#if(STD_ON == COMM_DCM_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_DCM_ActiveDiagnostic  SWS_ComM_00873
*
* Description:   Indication of active diagnostic by the DCM
*
* Inputs:        Channel:Channel needed for Diagnostic communication
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_DCM_ActiveDiagnostic
(
    NetworkHandleType Channel
)
{
    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_DCM_ACTIVEDIAGNOSTIC_APIID, COMM_E_UNINIT);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_DCM_ACTIVEDIAGNOSTIC_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        if(COMM_IS_NMVARIANT_FULL(Channel) || COMM_IS_NMVARIANT_LIGHT(Channel) || COMM_IS_NMVARIANT_NONE(Channel))
        {
            SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_3();
            /*if already in an Active Diagnostic, ignore*/
            if((uint16)0 == (uint16)(ComM_TriggerInfo[Channel] & COMM_ACTIVE_DIAG_MASK))
            {
                ComM_TriggerInfo[Channel] |= COMM_ACTIVE_DIAG_MASK;

                ComM_S_UpdateKeepComFlag(Channel);
            }
            SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_3();
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_DCM_InactiveDiagnostic  SWS_ComM_00874
*
* Description:   Indication of inactive diagnostic by the DCM.
*
* Inputs:        Channel:Channel no longer needed for Diagnostic communication
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_DCM_InactiveDiagnostic
(
    NetworkHandleType Channel
)
{
    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_DCM_INACTIVEDIAGNOSTIC_APIID, COMM_E_UNINIT);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_DCM_INACTIVEDIAGNOSTIC_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_3();
        /*if not in an Active Diagnostic, ignore*/
        if((uint16)0 != (uint16)(ComM_TriggerInfo[Channel] & COMM_ACTIVE_DIAG_MASK))
        {
            ComM_TriggerInfo[Channel] &= (uint16)(~COMM_ACTIVE_DIAG_MASK);

            ComM_S_UpdateKeepComFlag(Channel);
        }
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_3();
    }
}
#endif/*#if(STD_ON == COMM_DCM_SUPPORT)*/



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_EcuM_WakeUpIndication  SWS_ComM_00275
*
* Description:   Notification of a wake up on the corresponding channel.
*
* Inputs:        Channel
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_EcuM_WakeUpIndication
(
    NetworkHandleType Channel
)
{
#if(STD_ON == COMM_SYNCHRONOUS_WAKE_UP)
    NetworkHandleType ChannelAll;
/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
    PNCHandleType PncIdx;
#endif
#endif

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_ECUM_WAKEUPINDICATION_APIID, COMM_E_UNINIT);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_ECUM_WAKEUPINDICATION_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_4();
        /*SWS_ComM_00893*/
        ComM_TriggerInfo[Channel] |= COMM_WAKEUP_IND_MASK;

#if(STD_ON == COMM_SYNCHRONOUS_WAKE_UP)
        /*SWS_ComM_00694*/
        for(ChannelAll = (NetworkHandleType)0; ChannelAll < COMM_NUM_OF_CHANNEL; ChannelAll++)
        {
            ComM_TriggerInfo[ChannelAll] |= COMM_WAKEUP_IND_MASK;
        }

/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
        /*SWS_ComM_01063*//*SWS_ComM_00990*/
        for(PncIdx = (PNCHandleType)0; PncIdx < (PNCHandleType)COMM_NUM_OF_PNC; PncIdx++)
        {
            ComM_PncWakeupFlag[PncIdx] = TRUE;
        }
#endif
#endif/*#if(STD_ON == COMM_SYNCHRONOUS_WAKE_UP)*/

        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_4();
    }
}

/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_EcuM_PNCWakeUpIndication  SWS_ComM_91001
*
* Description:   Notification of a wake up on the corresponding partial network cluster.
*
* Inputs:        PNCid: Identifier of the partial network cluster
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_EcuM_PNCWakeUpIndication
(
    PNCHandleType PNCid
)
{
    PNCHandleType PncIdx;
    NetworkHandleType Channel;
#if(STD_ON != COMM_SYNCHRONOUS_WAKE_UP)
    uint8 ChannelIdx;
    uint8 StartChannel;
    uint8 EndChannel;
#endif

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_ECUM_PNCWAKEUPINDICATION_APIID, COMM_E_UNINIT);
    }
    else
    {
        if(TRUE == COMM_PNC_ENABLED)
        {
            for(PncIdx = (PNCHandleType)0; PncIdx < (PNCHandleType)COMM_NUM_OF_PNC; PncIdx++)
            {
                if(PNCid == COMM_CFG_PNC_ID(PncIdx))
                {
                    SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_4();

#if(STD_ON != COMM_SYNCHRONOUS_WAKE_UP)
                    StartChannel = COMM_CFG_PNC_MAP_CHL_START(PncIdx);
                    EndChannel = StartChannel + COMM_CFG_PNC_MAP_CHL_NUM(PncIdx);

                    for(ChannelIdx = StartChannel; ChannelIdx < EndChannel; ChannelIdx++)
                    {
                        Channel = COMM_CFG_PNC_MAP_CHL(ChannelIdx);
                        /*SWS_ComM_01014*/
                        ComM_TriggerInfo[Channel] |= COMM_WAKEUP_IND_MASK;
                    }
#else
                    for(Channel = (NetworkHandleType)0; Channel < COMM_NUM_OF_CHANNEL; Channel++)
                    {
                        /*SWS_ComM_01015*/
                        ComM_TriggerInfo[Channel] |= COMM_WAKEUP_IND_MASK;
                    }
#endif
                    /*SWS_ComM_01064*/
                    ComM_PncWakeupFlag[PncIdx] = TRUE;

                    SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_4();

                    break;
                }
            }
        }
    }
}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_CommunicationAllowed  SWS_ComM_00871
*
* Description:   Indicate to ComM when communication is allowed
*
* Inputs:        Channel
*                Allowed:TRUE: Communication is allowed
*                        FALSE: Communication is not allowed
*
* Outputs:         None
*
* Limitations:     None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_CommunicationAllowed
(
    NetworkHandleType Channel,
    boolean Allowed
)
{
    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_COMMUNICATIONALLOWED_APIID, COMM_E_UNINIT);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_COMMUNICATIONALLOWED_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_5();
        /*SWS_ComM_00885*/
        if(TRUE == Allowed)
        {
            ComM_TriggerInfo[Channel] |= COMM_COM_ALLOWED_IND_MASK;
        }
        else
        {
            ComM_TriggerInfo[Channel] &= (uint16)(~COMM_COM_ALLOWED_IND_MASK);
        }

        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_5();
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_BusSM_ModeIndication  SWS_ComM_00675
*
* Description:   Indication of the actual bus mode by the corresponding Bus State Manager
*
* Inputs:        Channel
*                ComMode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_BusSM_ModeIndication
(
    NetworkHandleType Channel,
    ComM_ModeType ComMode
)
{
#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))
    uint16 FocusMask = (uint16)(COMM_WAKEUP_IND_MASK | COMM_NM_RESTART_IND_MASK | COMM_NETWORK_START_IND_MASK);
#endif

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_BUSSM_MODEINDICATION_APIID, COMM_E_UNINIT);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_BUSSM_MODEINDICATION_APIID, COMM_E_WRONG_PARAMETERS);
    }
#if(STD_ON == COMM_MULTI_CORE_SUPPORT)
    /*SWS_ComM_01020*/
    else if(COMM_GETCOREID() != COMM_CFG_CHL_MAP_CORE(Channel))
    {
        COMM_DET_REPORT_ERROR(COMM_BUSSM_MODEINDICATION_APIID, COMM_E_CALLED_IN_WRONG_CORE);
    }
#endif
    else
    {
        if(ComMode == ComM_Mode[Channel])
        {
#if(STD_ON == COMM_DCM_SUPPORT)
            /*SWS_ComM_00266*/
            switch(ComMode)
            {
            case COMM_NO_COMMUNICATION:
                Dcm_ComM_NoComModeEntered(Channel);
                break;

            case COMM_SILENT_COMMUNICATION:
                /*SWS_ComM_00868*/
                Dcm_ComM_SilentComModeEntered(Channel);
                break;

            case COMM_FULL_COMMUNICATION:
                Dcm_ComM_FullComModeEntered(Channel);
                break;

            default:
                /*do nothing*/
                break;
            }
#endif

#if((STD_ON == COMM_NMVARIANT_SLAVE_A_ENABLED) || (STD_ON == COMM_NMVARIANT_SLAVE_P_ENABLED))
            if(COMM_NO_COMMUNICATION != ComMode)
            {
                ComM_TriggerInfo[Channel] &= (~COMM_SM_BUS_SLEEP_IND_MASK);
            }
#endif

#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))
            if(COMM_FULL_COMMUNICATION == ComMode)
            {
                if((TRUE == ComM_KeepComFlag[Channel]) && (COMM_IS_NMVARIANT_FULL(Channel)) \
                    && (ComM_ReqPendingFlag[Channel] == TRUE))
                {
                    /*SWS_ComM_00869*//*SWS_ComM_00870*/
                    /*SWS_ComM_00261*//*SWS_ComM_00602*//*SWS_ComM_00667*/
                    (void)Nm_NetworkRequest(COMM_CFG_CHL_TO_NM(Channel));
                    ComM_ReqPendingFlag[Channel] = FALSE;
                }
                else if((uint16)0 != (uint16)(ComM_TriggerInfo[Channel] & FocusMask))
                {
                    ComM_TriggerInfo[Channel] &= (uint16)(~FocusMask);
                    /*SWS_ComM_00665*//*SWS_ComM_00902*//*SWS_ComM_00903*/
                    /*SWS_ComM_00261*//*SWS_ComM_00602*/
                    (void)Nm_PassiveStartUp(COMM_CFG_CHL_TO_NM(Channel));
                }
                else
                {
                    /*do nothing*/
                }
            }
#endif
        }
    }
}

#if((STD_ON == COMM_NMVARIANT_SLAVE_A_ENABLED) || (STD_ON == COMM_NMVARIANT_SLAVE_P_ENABLED))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_BusSM_BusSleepMode  SWS_ComM_91000
*
* Description:   Notification of the corresponding Bus State Manager that the
*                actual bus mode is Bus-Sleep.
*
* Inputs:        Channel
*                ComMode
*
* Outputs:       None
*
* Limitations:   Only applicable for ComM channels with ComMNmVariant set to
*                SLAVE_ACTIVE or SLAVE_PASSIVE.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_BusSM_BusSleepMode
(
    NetworkHandleType Channel
)
{
    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_BUSSM_BUSSLEEPMODE_APIID, COMM_E_UNINIT);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_BUSSM_BUSSLEEPMODE_APIID, COMM_E_WRONG_PARAMETERS);
    }
    else
    {
        if((COMM_IS_NMVARIANT_SLAVE_A(Channel)) || (COMM_IS_NMVARIANT_SLAVE_P(Channel)))
        {
            /*SWS_ComM_01018*/
            ComM_TriggerInfo[Channel] |= COMM_SM_BUS_SLEEP_IND_MASK;
        }
    }
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: ComM_MainFunction   SWS_ComM_00429
*
* Description:   This function shall perform the processing of the AUTOSAR ComM
*                activities that are not directly initiated by the calls e.g. from
*                the RTE. There shall be one dedicated Main Function for each
*                channel of ComM.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COMM_CODE) ComM_MainFunction
(
    NetworkHandleType Channel
)
{
#if(STD_ON == COMM_MULTI_CORE_SUPPORT)
    uint8 CoreId = COMM_GETCOREID();
#endif

    if(!COMM_IS_INITIALIZED())
    {
        /*SWS_ComM_00612*//*SWS_ComM_00858*/
        COMM_DET_REPORT_ERROR(COMM_MAINFUNCTION_APIID, COMM_E_UNINIT);
    }
    else if(Channel >= COMM_NUM_OF_CHANNEL)
    {
        COMM_DET_REPORT_ERROR(COMM_MAINFUNCTION_APIID, COMM_E_WRONG_PARAMETERS);
    }
#if(STD_ON == COMM_MULTI_CORE_SUPPORT)
    else if(CoreId != COMM_CFG_CHL_MAP_CORE(Channel))
    {
        COMM_DET_REPORT_ERROR(COMM_MAINFUNCTION_APIID, COMM_E_CALLED_IN_WRONG_CORE);
    }
#endif
    else
    {
        /*SWS_ComM_00987*/
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_1();

#if((COMM_NUM_OF_USER > 0) && (STD_ON == COMM_MULTI_CORE_SUPPORT))
        /*Unified processing of User requests on the main core to avoid variable consistency issues.*/
        if(CoreId == COMM_MASTER_CORE)
        {
            ComM_S_ProcessUserRequest();
        }
#endif

/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
        /*SWS_ComM_00911*//*SWS_ComM_00953*/
        if(TRUE == COMM_PNC_ENABLED)
        {
            /*SWS_ComM_00978*//*SWS_ComM_00979*/
            ComM_S_MainFunctionPnc(Channel);
        }
#endif

#if((STD_ON == COMM_NMVARIANT_LIGHT_ENABLED) || (STD_ON == COMM_NMVARIANT_NONE_ENABLED))
        ComM_S_TimerMainFunction(Channel);
#endif
        if(ComM_BusSM_RequestPending[Channel] == TRUE)
        {
            ComM_S_BusSM_RequestComMode(Channel, ComM_Mode[Channel]);
        }

        /*SWS_ComM_00051*//*SWS_ComM_00599*/
        switch(ComM_State[Channel])
        {
        case COMM_NO_COM_NO_PENDING_REQUEST:
            ComM_S_NoPendingRequestProc(Channel);
            break;
        case COMM_NO_COM_REQUEST_PENDING:
            ComM_S_RequestPendingProc(Channel);
            break;
#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))
        case COMM_SILENT_COM:
            ComM_S_SilentComProc(Channel);
            break;
#endif
        case COMM_FULL_COM_NETWORK_REQUESTED:
            ComM_S_NetworkRequestedProc(Channel);
            break;
        case COMM_FULL_COM_READY_SLEEP:
            ComM_S_ReadySleepProc(Channel);
            break;
        default:
            /*do nothing*/
            break;
        }
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_1();
    }
}



#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"


