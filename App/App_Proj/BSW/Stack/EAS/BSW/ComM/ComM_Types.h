/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : ComM_Types.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : ComM_Types.h
*   Author          : Hirain
********************************************************************************
*   Description     : The header file ComM_Types.h contains the  common type
*                     definitions of the module COM Manager
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
#ifndef COMM_TYPES_H
#define COMM_TYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComStack_Types.h"
#include "Rte_ComM_Type.h"
/*SWS_ComM_00863 The following Data Types shall be used for the functions
defined in this Specification.*/

/*******************************************************************************
*   Typedef
*******************************************************************************/
/*SWS_ComM_91027 The ComM API uses the following extension to Std_ReturnType.*/
/*Function call has been successful but mode can not be granted because of mode inhibition.*/
#define COMM_E_MODE_LIMITATION                   ((Std_ReturnType)2)
/*Function could not provide the current mode of the PNC, since multiple PNCs are assigned to the affected user.*/
#define COMM_E_MULTIPLE_PNC_ASSIGNED             ((Std_ReturnType)3)
/*Function could not provide the current mode of the PNC, since no PNC is assigned to the affected user.*/
#define COMM_E_NO_PNC_ASSIGNED                   ((Std_ReturnType)4)
/*Function call has been successfully, but functionality cannot be executed because PNC learning phase is active.*/
#define COMM_E_LEARNING_ACTIVE                   ((Std_ReturnType)5)


/*SWS_ComM_00668*/
typedef enum
{
    COMM_UNINIT = 0,   /*The COM Manager is not initialized or not usable.*/
    COMM_INIT   = 1    /*The COM Manager is initialized and usable.*/
} ComM_InitStatusType;

/*SWS_ComM_00673*//*SWS_ComM_00924*//*SWS_ComM_00907*/
typedef uint8 ComM_PncModeType;
/*PNC is requested by a local ComM user*/
#define COMM_PNC_REQUESTED                     (ComM_PncModeType)0
/*PNC is requested by a remote ComM user*/
#define COMM_PNC_READY_SLEEP                   (ComM_PncModeType)1
/*PNC is active with no deadline monitoring*/
#define COMM_PNC_PREPARE_SLEEP                 (ComM_PncModeType)2
/*PNC does not communicate*/
#define COMM_PNC_NO_COMMUNICATION              (ComM_PncModeType)3
/*PNC is requested by a local ComM user(used for Ethernet switch port)*/
#define COMM_PNC_REQUESTED_WITH_WAKEUP_REQUEST (ComM_PncModeType)4

/*SWS_ComM_00674*//*SWS_ComM_00051*//*SWS_ComM_00880*//*SWS_ComM_00881*/
typedef uint8 ComM_StateType;
#define COMM_NO_COM_NO_PENDING_REQUEST           ((ComM_StateType)0)
#define COMM_NO_COM_REQUEST_PENDING              ((ComM_StateType)1)
#define COMM_FULL_COM_NETWORK_REQUESTED          ((ComM_StateType)2)
#define COMM_FULL_COM_READY_SLEEP                ((ComM_StateType)3)
#define COMM_SILENT_COM                          ((ComM_StateType)4)



typedef uint32 ComM_TimerType;


/*SWS_ComM_00322*/
typedef enum
{
    COMM_BUS_TYPE_CAN       = 0,
    COMM_BUS_TYPE_CDD       = 1,/*Custom bus types are not supported.*/
    COMM_BUS_TYPE_ETH       = 2,
    COMM_BUS_TYPE_FR        = 3,
    COMM_BUS_TYPE_INTERNAL  = 4,
    COMM_BUS_TYPE_LIN       = 5
} ComM_BusType;

typedef enum
{
    COMM_GATEWAY_TYPE_NONE     = 0,
    COMM_GATEWAY_TYPE_ACTIVE   = 1,
    COMM_GATEWAY_TYPE_PASSIVE  = 2
} ComM_PncGatewayType;


typedef enum
{
    COMM_NM_FULL           = 0,
    COMM_NM_LIGHT          = 1,
    COMM_NM_NONE           = 2,
    COMM_NM_PASSIVE        = 3,
    COMM_NM_SLAVE_ACTIVE   = 4,
    COMM_NM_SLAVE_PASSIVE  = 5
} ComM_NmVariantType;

typedef P2FUNC(Std_ReturnType, COMM_APPL_CODE, ComM_RteSwitchFctPtrType)(ComM_ModeType ComMode);

#endif/*COMM_TYPES_H*/

