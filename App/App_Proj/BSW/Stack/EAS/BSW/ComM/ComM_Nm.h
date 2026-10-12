/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : ComM_Nm.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : ComM module Nm ralated header File
*   Author          : Hirain
********************************************************************************
*   Description     : The header file ComM_Nm.h contains the declaration of
*                     functions which is called by the Nm module
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

#ifndef COMM_NM_H
#define COMM_NM_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComM_Cfg.h"
#include "ComM_Version.h"

/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define COMM_START_SEC_CODE
#include "ComM_MemMap.h"

/*SWS_ComM_00620*/

#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))
/*SWS_ComM_00383*/
extern FUNC(void, COMM_CODE) ComM_Nm_NetworkStartIndication
(
    NetworkHandleType Channel
);

/*SWS_ComM_00390*/
extern FUNC(void, COMM_CODE) ComM_Nm_NetworkMode
(
    NetworkHandleType Channel
);

/*SWS_ComM_00391*/
extern FUNC(void, COMM_CODE) ComM_Nm_PrepareBusSleepMode
(
    NetworkHandleType Channel
);

/*SWS_ComM_00392*/
extern FUNC(void, COMM_CODE) ComM_Nm_BusSleepMode
(
    NetworkHandleType Channel
);

/*SWS_ComM_00792*/
extern FUNC(void, COMM_CODE) ComM_Nm_RestartIndication
(
    NetworkHandleType Channel
);

/*SWS_ComM_00910*/
#if(STD_ON == COMM_PNC_SUPPORT)
#if(STD_ON == COMM_DYN_PNC_TO_CHL_MAP_SUPPORT)
/*SWS_ComM_91024*/
extern FUNC(void, COMM_CODE) ComM_Nm_RepeatMessageLeftIndication
(
    NetworkHandleType Channel
);

/*SWS_ComM_91026*/
extern FUNC(void, COMM_CODE) ComM_Nm_PncLearningBitIndication
(
    NetworkHandleType Channel
);
#endif

#if(STD_ON == COMM_PNC_GW_ENABLED)
#if(STD_ON == COMM_SYNC_PNC_SHUTDOWN_ENABLED)
/*SWS_ComM_91030*/
extern FUNC(void, COMM_CODE) ComM_Nm_ForwardSynchronizedPncShutdown
(
    NetworkHandleType Channel,
    P2CONST(uint8, AUTOMATIC, COMM_APPL_DATA) PncBitVectorPtr
);
#endif
/*SWS_ComM_91029*/
extern FUNC(void, COMM_CODE) ComM_Nm_UpdateERA
(
    NetworkHandleType Channel,
    P2CONST(uint8, AUTOMATIC, COMM_APPL_DATA) PncBitVectorPtr
);
#endif

/*SWS_ComM_91028*/
extern FUNC(void, COMM_CODE) ComM_Nm_UpdateEIRA
(
    P2CONST(uint8, AUTOMATIC, COMM_APPL_DATA) PncBitVectorPtr
);

#endif/*#if(STD_ON == COMM_PNC_SUPPORT)*/

#endif/*#if((STD_ON == COMM_NMVARIANT_FULL_ENABLED) || (STD_ON == COMM_NMVARIANT_PASSIVE_ENABLED))*/


#define COMM_STOP_SEC_CODE
#include "ComM_MemMap.h"


#endif/*COMM_NM_H*/

