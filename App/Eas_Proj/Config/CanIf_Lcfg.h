/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanIf_Lcfg.h
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
#ifndef CANIF_LCFG_H
#define CANIF_LCFG_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanIf_Types.h"
#include "PduR.h"
#include "CanTp_Cbk.h"
#include "EcuM_Generated_Types.h"
#include "CanSM_Cbk.h"

/*******************************************************************************
*   Global Vars
*******************************************************************************/
#define CANIF_START_SEC_VAR_CLEARED_LOCAL_8
#include "CanIf_MemMap.h"
extern VAR(CanIf_ControllerModeType, CANIF_VAR_NOINIT) CanIf_ControllerMode[1];
extern VAR(CanIf_PduModeType, CANIF_VAR_NOINIT) CanIf_PduMode[1];
extern VAR(CanIf_NotifStatusType, CANIF_VAR_NOINIT) CanIf_TxConfStatus[1];
/*******************************************************************************
*   Typedef
*******************************************************************************/

typedef P2FUNC(void, TYPEDEF, CanIf_User_ControllerBusOff_Type)
(
    uint8 ControllerId
);

typedef P2FUNC(void, TYPEDEF, CanIf_User_SetWakeupEvent_Type)
(
    EcuM_WakeupSourceType sources
);

typedef P2FUNC(void, TYPEDEF, CanIf_User_ValidateWakeupEvent_Type)
(
    EcuM_WakeupSourceType sources
);
typedef P2FUNC(void, TYPEDEF, CanIf_User_ControllerModeIndication_Type)
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
);

typedef P2FUNC(void, TYPEDEF, CanIf_User_CurrentIcomConfiguration_type)
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId,
    IcomSwitch_ErrorType Error
);
#define CANIF_STOP_SEC_VAR_CLEARED_LOCAL_8
#include "CanIf_MemMap.h"


/*******************************************************************************
*   Config Parameters
*******************************************************************************/
#define CANIF_START_SEC_CONFIG_DATA
#include "CanIf_MemMap.h"
extern CONST(CanIf_CanWriteType, CANIF_CONST)                CanIf_Can_Write[1];
extern CONST(CanIf_CanSetControllerModeType, CANIF_CONST)    CanIf_Can_SetControllerMode[1];
extern CONST(CanIf_CanGetControllerErrorState, CANIF_CONST)           CanIf_Can_GetControllerErrorState[1];
extern CONST(CanIf_CanGetControllerTxErrorCounter, CANIF_CONST)       CanIf_Can_GetControllerTxErrorCounter[1];
extern CONST(CanIf_CanGetControllerRxErrorCounter, CANIF_CONST)       CanIf_Can_GetControllerRxErrorCounter[1];
extern CONST(CanIf_User_TxConfirmationType, CANIF_CONST)           CanIf_TxConfirmationName[2];
extern CONST(CanIf_User_RxIndicationType, CANIF_CONST)             CanIf_RxIndicationName[2];
extern CONST(CanIf_CtrlCfgType, CANIF_CONST)           CanIf_CtrlCfg[1];
#define CANIF_STOP_SEC_CONFIG_DATA
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA
#include "CanIf_MemMap.h"
extern CONST(uint8, CANIF_CONST)           CanIf_PublicNumberOfCanHwUnits;
extern CONST(uint8, CANIF_CONST)           CanIf_InitTrcvNum;
extern CONST(uint8, CANIF_CONST)           CanIf_InitWakeUpSrcNum;
#define CANIF_STOP_SEC_CONFIG_DATA
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA
#include "CanIf_MemMap.h"
extern CONST(CanIf_User_ControllerBusOff_Type, CANIF_CONST)             CanIf_DispatchUserCtrlBusOffName;
extern CONST(CanIf_User_ControllerModeIndication_Type, CANIF_CONST)     CanIf_DispatchUserCtrlModeIndicationName;
#define CANIF_STOP_SEC_CONFIG_DATA
#include "CanIf_MemMap.h"

/*******************************************************************************
*   Access macro
*******************************************************************************/
#define CANIF_USED_CONTROLLER_NUM                           CanIf_PublicNumberOfCanHwUnits
#define CANIF_USED_TRCV_NUM                                 CanIf_InitTrcvNum
#define CANIF_USED_WAKRUPSRC_NUM                            CanIf_InitWakeUpSrcNum

#define CANIF_DISPATCH_USERCTRLBUSOFF_NAME                  CanIf_DispatchUserCtrlBusOffName(ControllerId)
#define CANIF_DISPATCH_USERCTRLMODEINDICATION_NAME          CanIf_DispatchUserCtrlModeIndicationName(ControllerId, ControllerMode)
#endif
