/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : ComM_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : ComM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : ComM module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/
#ifndef COMM_CFG_H
#define COMM_CFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComM_Types.h"

/*******************************************************************************
*   Common Macro
*******************************************************************************/
/*ECUC_ComM_00890*/
/*Configuration variant, only support VARIANT-POST-BUILD and VARIANT-PRE-COMPILE.*/
#define COMM_CONFIG_VARIANTS                                STD_CONFIG_VARIANTS_POSTBUILD


/*******************************************************************************
*   Non Autosar Standard
*******************************************************************************/
/* EAS special */
#define COMM_VERSION_CHECK                                  STD_ON
#define COMM_DCM_SUPPORT                                    STD_ON
#define COMM_ECUM_SUPPORT                                   STD_ON
#define COMM_NVM_SUPPORT                                    STD_OFF
#define COMM_MULTI_CORE_SUPPORT                             STD_OFF


/*NM*/
#define COMM_NMVARIANT_ENABLED                              STD_OFF
#define COMM_NMVARIANT_FULL_ENABLED                         STD_OFF
#define COMM_NMVARIANT_PASSIVE_ENABLED                      STD_OFF
#define COMM_NMVARIANT_LIGHT_ENABLED                        STD_ON
#define COMM_NMVARIANT_NONE_ENABLED                         STD_OFF
#define COMM_NMVARIANT_SLAVE_A_ENABLED                      STD_OFF
#define COMM_NMVARIANT_SLAVE_P_ENABLED                      STD_OFF
/*Bus Type*/
#define COMM_NUM_OF_CAN_CHANNEL                             1
#define COMM_NUM_OF_LIN_CHANNEL                             0
#define COMM_NUM_OF_FR_CHANNEL                              0
#define COMM_NUM_OF_ETH_CHANNEL                             0
#define COMM_NUM_OF_INTERNAL_CHANNEL                        0
#define COMM_NUM_OF_CHANNEL                                 ((NetworkHandleType)1)

#define COMM_NUM_OF_USER                                    1
#define COMM_MAX_USER_MAPPING_CHANNEL                       1
#define COMM_MAX_CHANNEL_MAPPING_USER                       1

/* generate tool's version*/
#define COMM_SW_MAJOR_VERSION_CFG                           4
#define COMM_SW_MINOR_VERSION_CFG                           0
#define COMM_SW_PATCH_VERSION_CFG                           4
#define COMM_AR_RELEASE_MAJOR_VERSION_CFG                   4
#define COMM_AR_RELEASE_MINOR_VERSION_CFG                   7
#define COMM_AR_RELEASE_REVISION_VERSION_CFG                0

/*******************************************************************************
*   ECUC_ComM_00554 ComMGeneral
*******************************************************************************/
/*ECUC_ComM_00892 ComM0PncVectorAvoidance*/
#define COMM_0_PNC_VECTOR_AVOIDANCE                         STD_OFF
/*ECUC_ComM_00895 ComMDynamicPncToChannelMappingSupport*/
#define COMM_DYN_PNC_TO_CHL_MAP_SUPPORT                     STD_OFF
/*ECUC_ComM_00887 ComMPncGatewayEnabled*/
#define COMM_PNC_GW_ENABLED                                 STD_OFF
/*ECUC_ComM_00841 ComMPncPrepareSleepTimer*/
#define COMM_PNC_PREPARE_SLEEP_TIME                         ((ComM_TimerType)0)/*0...63000 ms*/
/*ECUC_ComM_00839 ComMPncSupport*/
#define COMM_PNC_SUPPORT                                    STD_OFF
/*ECUC_ComM_00897 ComMSynchronizedPncShutdownEnabled*/
#define COMM_SYNC_PNC_SHUTDOWN_ENABLED                      STD_OFF
/*ECUC_ComM_00555 ComMDevErrorDetect*/
#define COMM_DEV_ERROR_DETECT                               STD_ON
/*ECUC_ComM_00622 ComMVersionInfoApi*/
#define COMM_VERSION_INFO_API                               STD_ON
/*ECUC_ComM_00560 ComMModeLimitationEnabled*/
#define COMM_MODE_LIMITATION_ENABLED                        STD_OFF
/*ECUC_ComM_00559 ComMWakeupInhibitionEnabled*/
#define COMM_WAKEUP_INHIBITION_ENABLED                      STD_OFF
/*ECUC_ComM_00563 ComMEcuGroupClassification*/
#define COMM_ECU_GROUP_CLASS_DEFAULT_VALUE                  ((ComM_InhibitionStatusType)0x3)
/*ECUC_ComM_00558 ComMResetAfterForcingNoComm*/
#define COMM_RESET_AFTER_FORCING_NOCOMM                     STD_OFF
/*ECUC_ComM_00695 ComMSynchronousWakeUp*/
#define COMM_SYNCHRONOUS_WAKE_UP                            STD_OFF
/*ECUC_ComM_00557 ComMTMinFullComModeDuration*/
#define COMM_MIN_FULL_COM_TIME                              ((ComM_TimerType)5000)/*0...65000 ms*/

/*******************************************************************************
*   Access macro
*******************************************************************************/
/*ECUC_ComM_00635 ComMChannelId*/
#define ComM_ComM_BODY_LE1_CAN                              ((NetworkHandleType)0)

/*ECUC_ComM_00654 ComMUserIdentifier*/
#define ComM_USERID_User0                                   ((ComM_UserHandleType)0)



/*******************************************************************************
*   Config Parameters declear
*******************************************************************************/
#define COMM_START_SEC_CONFIG_DATA
#include "ComM_MemMap.h"

/*ECUC_ComM_00567*/
extern CONST(ComM_BusType, COMM_CONST) ComM_ChannelBusType[COMM_NUM_OF_CHANNEL];
extern CONST(NetworkHandleType, COMM_CONST) ComM_ChannelToBusSM[COMM_NUM_OF_CHANNEL];

/*ECUC_ComM_00787*/
extern CONST(boolean, COMM_CONST) ComM_ChannelFullCommRequestNotificationEnabled[COMM_NUM_OF_CHANNEL];
/*SWS_ComM_00910*/
/*SWS_ComM_00995*//*ECUC_ComM_00657*//*ECUC_ComM_00658*//*User mapping to Channel*/
extern CONST(uint8, COMM_CONST) ComM_UserMappingChannelStart[COMM_NUM_OF_USER];
extern CONST(uint8, COMM_CONST) ComM_UserMappingChannelNum[COMM_NUM_OF_USER];
extern CONST(NetworkHandleType, COMM_CONST) ComM_UserMappingChannel[COMM_MAX_USER_MAPPING_CHANNEL];

/*ECUC_ComM_00657*//*ECUC_ComM_00658*//*Channel mapping to User*/
extern CONST(uint8, COMM_CONST) ComM_ChannelMappingUserStart[COMM_NUM_OF_CHANNEL];
extern CONST(uint8, COMM_CONST) ComM_ChannelMappingUserNum[COMM_NUM_OF_CHANNEL];
extern CONST(ComM_UserHandleType, COMM_CONST) ComM_ChannelMappingUser[COMM_MAX_CHANNEL_MAPPING_USER];

#define COMM_STOP_SEC_CONFIG_DATA
#include "ComM_MemMap.h"

#define COMM_START_SEC_CONFIG_DATA
#include "ComM_MemMap.h"
/*ECUC_ComM_00556*/
extern CONST(ComM_TimerType, COMM_CONST) ComM_ChannelMainFunctionPeriod[COMM_NUM_OF_CHANNEL];

/*ECUC_ComM_00606*/
extern CONST(ComM_TimerType, COMM_CONST) ComM_ChannelNmLightTimeout[COMM_NUM_OF_CHANNEL];

#define COMM_STOP_SEC_CONFIG_DATA
#include "ComM_MemMap.h"
#define COMM_START_SEC_CONFIG_DATA
#include "ComM_MemMap.h"
extern CONST(ComM_RteSwitchFctPtrType, COMM_CONST) ComM_RteSwitchFunction[COMM_NUM_OF_USER];
#define COMM_STOP_SEC_CONFIG_DATA
#include "ComM_MemMap.h"

#endif /*COMM_CFG_H*/




