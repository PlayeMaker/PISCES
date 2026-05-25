/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanIf_Lcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanIf module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanIf module configuration File
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
/*PRQA S 862,3214,3614,778,779 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address 
segments in the files of each module,#include "MemMap.h" is required.Defined 
XXX_START_SEC_ will undefine in MemMap.h
*/

/*PRQA S 3132,3211,3111,2213 EOF*/
/*
Particularity of configuration files
*/

/*PRQA S 857,380 EOF*/
/*
Macro definitions exceed 1024.The number of macros is unlimited.
*/
/*PRQA S 1533,1531,1559 EOF*/
/*
Variable and function are used in core code.
*/

/*PRQA S 791,792 EOF*/
/*
Macro name do no differ within 31 characters
*/
/*PRQA S 1281 EOF*/
/*
Integer Literal constant is of an unsigned type but does not include a "U" suffix.
*/

/*PRQA S 5087 EOF*/
/*
Use of #include directive after code fragment.
*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanIf.h"
#include "Can.h"

/*******************************************************************************
*   Global Vars
*******************************************************************************/
#define CANIF_START_SEC_VAR_CLEARED_LOCAL_8
#include "CanIf_MemMap.h"
VAR(CanIf_ControllerModeType, CANIF_VAR_NOINIT) CanIf_ControllerMode[1];
VAR(CanIf_PduModeType, CANIF_VAR_NOINIT) CanIf_PduMode[1];
VAR(CanIf_NotifStatusType, CANIF_VAR_NOINIT) CanIf_TxConfStatus[1];
#define CANIF_STOP_SEC_VAR_CLEARED_LOCAL_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "CanIf_MemMap.h"
#define CANIF_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "CanIf_MemMap.h"


/*******************************************************************************
*   Config Parameters
*******************************************************************************/
#define CANIF_START_SEC_CONFIG_DATA
#include "CanIf_MemMap.h"
CONST(CanIf_CanWriteType, CANIF_CONST)                CanIf_Can_Write[1] =
{
    &Can_Write
};
CONST(CanIf_CanSetControllerModeType, CANIF_CONST)    CanIf_Can_SetControllerMode[1] =
{
    &Can_SetControllerMode
};
CONST(CanIf_CanGetControllerErrorState, CANIF_CONST)       CanIf_Can_GetControllerErrorState[1] =
{
    &Can_GetControllerErrorState
};
CONST(CanIf_CanGetControllerTxErrorCounter, CANIF_CONST)       CanIf_Can_GetControllerTxErrorCounter[1] =
{
    &Can_GetControllerTxErrorCounter
};
CONST(CanIf_CanGetControllerRxErrorCounter, CANIF_CONST)       CanIf_Can_GetControllerRxErrorCounter[1] =
{
    &Can_GetControllerRxErrorCounter
};
CONST(CanIf_User_TxConfirmationType, CANIF_CONST)           CanIf_TxConfirmationName[2] =
{
    &PduR_LoIfTxConfirmation,
    &CanTp_TxConfirmation,
};
CONST(CanIf_User_RxIndicationType, CANIF_CONST)           CanIf_RxIndicationName[2] =
{
    &PduR_LoIfRxIndication,
    &CanTp_RxIndication,
};
CONST(CanIf_CtrlCfgType, CANIF_CONST)           CanIf_CtrlCfg[1] =
{
    {FALSE, (uint8)0, (uint8)0}
};
#define CANIF_STOP_SEC_CONFIG_DATA
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA
#include "CanIf_MemMap.h"
CONST(uint8, CANIF_CONST)           CanIf_PublicNumberOfCanHwUnits = (uint8)1;
CONST(uint8, CANIF_CONST)           CanIf_InitTrcvNum = (uint8)0;
CONST(uint8, CANIF_CONST)           CanIf_InitWakeUpSrcNum = (uint8)0;
#define CANIF_STOP_SEC_CONFIG_DATA
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA
#include "CanIf_MemMap.h"
CONST(CanIf_User_ControllerBusOff_Type, CANIF_CONST)             CanIf_DispatchUserCtrlBusOffName = CanSM_ControllerBusOff;
CONST(CanIf_User_ControllerModeIndication_Type, CANIF_CONST)     CanIf_DispatchUserCtrlModeIndicationName = CanSM_ControllerModeIndication;
#define CANIF_STOP_SEC_CONFIG_DATA
#include "CanIf_MemMap.h"

