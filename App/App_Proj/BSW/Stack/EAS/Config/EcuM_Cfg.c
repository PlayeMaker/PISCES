/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EcuM_Cfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : EcuM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : EcuM module configuration File
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
segments in the files of each module,#include "EcuM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in EcuM_MemMap.h
*/

/*PRQA S 857 EOF*/
/*
Macro definitions exceed 1024.The number of macros is unlimited
*/

/*PRQA S 4640 EOF*/
/*
This waring is a false position. The 'errno.h' header file will not be used by the
EcuM module.
*/

/*PRQA S 3211,4332,1484,1278 EOF*/
/*
Particularity of configuration files.
*/

/*PRQA S 380 EOF*/
/*
Number of macro definitions exceeds 4095 -program does not conform strictly to ISO:C99.
*/



/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EcuM.h"
#include "ComM_EcuM.h"

/*******************************************************************************
*   Local Data Declaration
*******************************************************************************/
/* EcuM User */
#define ECUM_START_SEC_CONFIG_DATA
#include "EcuM_MemMap.h"

CONST(EcuMAlarmIdType, ECUM_CONST) EcuM_UserAlarm[ECUM_USER_NUMBER] =
{
    ECUM_INVALID_ALARMID
};


#define ECUM_STOP_SEC_CONFIG_DATA
#include "EcuM_MemMap.h"

/* EcuM CoreWakeupMask */
#define ECUM_START_SEC_CONFIG_DATA
#include "EcuM_MemMap.h"

/* EcuM CoreShutdown */
/* EcuM WkSrcConfigTable */
CONST(EcuM_WakeupSourceConfigType, ECUM_CONST) EcuM_WkSrcConfigTable[ECUM_WKSOURCE_NUMBER] =
{
    /*WkSource_Power*/
    {
        FALSE,
        (uint32)0,
        (uint16)0,
        (uint8)0,
        (uint16)0,
        (uint8)0,
        (uint16)0
    },
    /*WkSource_Reset*/
    {
        FALSE,
        (uint32)0,
        (uint16)0,
        (uint8)0,
        (uint16)0,
        (uint8)0,
        (uint16)0
    },
    /*WkSource_Internal_Reset*/
    {
        FALSE,
        (uint32)0,
        (uint16)0,
        (uint8)0,
        (uint16)0,
        (uint8)0,
        (uint16)0
    },
    /*WkSource_Internal_Wdg*/
    {
        FALSE,
        (uint32)0,
        (uint16)0,
        (uint8)0,
        (uint16)0,
        (uint8)0,
        (uint16)0
    },
    /*WkSource_External_Wdg*/
    {
        FALSE,
        (uint32)0,
        (uint16)0,
        (uint8)0,
        (uint16)0,
        (uint8)0,
        (uint16)0
    }
};

/* EcuM SleepModeTable */
/* EcuM AlarmClockTable */

#define ECUM_STOP_SEC_CONFIG_DATA
#include "EcuM_MemMap.h"




