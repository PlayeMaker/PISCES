/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : BswM_Lcfg.h
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
#ifndef BSWM_LCFG_H
#define BSWM_LCFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/

#include "BswM_Types.h"
#include "EcuM.h"
#include "CanSM.h"
#include "ComM_BswM.h"
#include "NvM.h"
#include "Dcm.h"


/*******************************************************************************
*   Global Vars
*******************************************************************************/

#define BSWM_START_SEC_CONFIG_DATA
#include "BswM_MemMap.h"

extern CONST(NetworkHandleType, BSWM_CONST) BswM_CanSMModeRef[BSWM_CANSM_PORT_NUM];
extern CONST(NetworkHandleType, BSWM_CONST) BswM_ComMModeRef[BSWM_COMM_PORT_NUM];
extern CONST(NetworkHandleType, BSWM_CONST) BswM_DcmComMModeRef[BSWM_DCM_PORT_NUM];




#define BSWM_STOP_SEC_CONFIG_DATA
#include "BswM_MemMap.h"


#define BSWM_START_SEC_VAR_INIT_GLOBAL_8
#include "BswM_MemMap.h"

extern VAR(EcuM_StateType, BSWM_VAR) BswM_EcuMRequestMode;

extern VAR(CanSM_BswMCurrentStateType, BSWM_VAR) BswM_CanSMMode[BSWM_CANSM_PORT_NUM];

extern VAR(ComM_ModeType, BSWM_VAR) BswM_ComMMode[BSWM_COMM_PORT_NUM];

extern VAR(NvM_RequestResultType, BSWM_VAR) BswM_NvMReadAllStatus;

extern VAR(NvM_RequestResultType, BSWM_VAR) BswM_NvMWriteAllStatus;



/*ECUC_BswM_00863*/
extern VAR(Dcm_CommunicationModeType, BSWM_VAR) BswM_DcmComMMode[BSWM_DCM_PORT_NUM];
extern VAR(BswM_TimerState, BSWM_VAR) BswM_TimerMode[BSWM_MAX_TIMER_NUM];

#define BSWM_STOP_SEC_VAR_INIT_GLOBAL_8
#include "BswM_MemMap.h"


#define BSWM_START_SEC_VAR_INIT_GLOBAL_16
#include "BswM_MemMap.h"

extern VAR(BswM_ModeType, BSWM_VAR) BswM_GeneralPortMode[BSWM_GENERAL_PORT_NUM];

#define BSWM_STOP_SEC_VAR_INIT_GLOBAL_16
#include "BswM_MemMap.h"





#define BSWM_START_SEC_CODE
#include "BswM_MemMap.h"

extern FUNC(void, BSWM_CODE)  BswM_InitBlockIICallout_Core0(void);
extern FUNC(void, BSWM_CODE)  BswM_StartBswTaskCallout_Core0(void);
extern FUNC(void, BSWM_CODE)  BswM_PostReadAllCallout_Core0(void);
extern FUNC(void, BSWM_CODE)  BswM_PreShutdownCallout_Core0(void);
extern FUNC(void, BSWM_CODE)  BswM_WakeupToSleepCallout_Core0(void);
extern FUNC(void, BSWM_CODE)  BswM_WriteNvMToSleepCallout_Core0(void);
extern FUNC(void, BSWM_CODE)  BswM_ClearWakeupEventCallout_Core0(void);
extern FUNC(void, BSWM_CODE)  BswM_NvMReadAllCallout_Core0(void);
extern FUNC(void, BSWM_CODE)  BswM_NvMWriteAllCallout_Core0(void);

#define BSWM_STOP_SEC_CODE
#include "BswM_MemMap.h"


#endif /* BSWM_LCFG_H */



