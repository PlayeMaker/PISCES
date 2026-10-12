/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : ComM_Cfg.c
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

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/

/*PRQA S 0857 EOF*/
/*
Macro definitions exceed 1024. The number of macros is unlimited
*/

/*PRQA S 5087,3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "EcuM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in EcuM_MemMap.h
*/

/*PRQA S 3111,2213,3132,3211,0914,3120 EOF*/
/*
Particularity of configuration files.
*/
/*PRQA S 1533,1531,1502 EOF*/
/*
Variable are used in core code.
*/

/*PRQA S 1559 EOF*/
/*
Functions are defined in Rte.
*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComM_Cfg.h"
#include "CanSM_Cfg.h"
#include "Rte_ComM.h"


/*******************************************************************************
*   ECUC_ComM_00565 ComMChannel
*******************************************************************************/

#define COMM_START_SEC_CONFIG_DATA
#include "ComM_MemMap.h"

/*ECUC_ComM_00567*/
CONST(ComM_BusType, COMM_CONST) ComM_ChannelBusType[COMM_NUM_OF_CHANNEL] =
{
    COMM_BUS_TYPE_CAN
};

CONST(NetworkHandleType, COMM_CONST) ComM_ChannelToBusSM[COMM_NUM_OF_CHANNEL] =
{
    CanSM_ComM_BODY_LE1_CAN
};

/*ECUC_ComM_00787*/
CONST(boolean, COMM_CONST) ComM_ChannelFullCommRequestNotificationEnabled[COMM_NUM_OF_CHANNEL] =
{
    FALSE
};

/*SWS_ComM_00910*/
/*SWS_ComM_00995*//*ECUC_ComM_00657*//*ECUC_ComM_00658*//*User mapping to Channel*/
CONST(uint8, COMM_CONST) ComM_UserMappingChannelStart[COMM_NUM_OF_USER] =
{
    (uint8)0
};

CONST(uint8, COMM_CONST) ComM_UserMappingChannelNum[COMM_NUM_OF_USER] =
{
    (uint8)1
};

CONST(NetworkHandleType, COMM_CONST) ComM_UserMappingChannel[COMM_MAX_USER_MAPPING_CHANNEL] =
{
    ComM_ComM_BODY_LE1_CAN
};

/*ECUC_ComM_00657*//*ECUC_ComM_00658*//*Channel mapping to User*/
CONST(uint8, COMM_CONST) ComM_ChannelMappingUserStart[COMM_NUM_OF_CHANNEL] =
{
    (uint8)0
};

CONST(uint8, COMM_CONST) ComM_ChannelMappingUserNum[COMM_NUM_OF_CHANNEL] =
{
    (uint8)1
};

CONST(ComM_UserHandleType, COMM_CONST) ComM_ChannelMappingUser[COMM_MAX_CHANNEL_MAPPING_USER] =
{
    ComM_USERID_User0
};

#define COMM_STOP_SEC_CONFIG_DATA
#include "ComM_MemMap.h"



#define COMM_START_SEC_CONFIG_DATA
#include "ComM_MemMap.h"
/*ECUC_ComM_00556*/
CONST(ComM_TimerType, COMM_CONST) ComM_ChannelMainFunctionPeriod[COMM_NUM_OF_CHANNEL] =
{
    (ComM_TimerType)5
};

/*ECUC_ComM_00606*/
CONST(ComM_TimerType, COMM_CONST) ComM_ChannelNmLightTimeout[COMM_NUM_OF_CHANNEL] =
{
    (ComM_TimerType)1000
};

#define COMM_STOP_SEC_CONFIG_DATA
#include "ComM_MemMap.h"





#define COMM_START_SEC_CONFIG_DATA
#include "ComM_MemMap.h"
CONST(ComM_RteSwitchFctPtrType, COMM_CONST) ComM_RteSwitchFunction[COMM_NUM_OF_USER] =
{
    &Rte_Switch_UM_User0_ComMMode
};

#define COMM_STOP_SEC_CONFIG_DATA
#include "ComM_MemMap.h"

