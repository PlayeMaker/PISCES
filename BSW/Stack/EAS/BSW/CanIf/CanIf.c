/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : CanIf.c
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : CAN Interface module Source File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of CAN Interface provided functionality
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials           CR#          Descriptions
*   ---------   ----------    ---------------   ----------   ---------------
*   04.00.00    12/28/2022    Tiantian.Liang     N/A          Original
*   04.01.00    09/23/2023    Ning.Chen          N/A          Add txfifo
*   04.01.06    16/01/2024    Ning.Chen          N/A          EAS470_CanIf_20240116_01
*   04.01.10    16/01/2024    Ning.Chen          N/A          EAS470_CanIf_20240426_01
*   04.01.11    11/05/2024    Wenbo.Cui          N/A          EAS470_CanIf_20240511_01
*   04.01.12    22/05/2024    Ning.Chen          N/A          EAS470_CanIf_20240522_01
*   04.01.14    20/06/2024    chaolimen.Han      N/A          EAS470_CanIf_20240620_01
********************************************************************************
* END_FILE_HDR*/

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 5087,3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "CanIf_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in CanIf_MemMap.h
*/

/*PRQA S 3453,3429 EOF*/
/*
1.The unified requirement of EAS is that the error reporting functions of Det
and Dem moduls are accessed by macro functions.This part has been verified and
has no problem.
2.Macro functions are allowed to use to access parameters and do some simple operations.
*/

/*PRQA S 3432,3410,3409 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no
need to revise.
*/

/*PRQA S 3673,4603 EOF*/
/*
Parameters in AUTOSAR standard APIs,they may not follow this rule.
*/

/*PRQA S 3212 EOF*/
/*
Unified requirements of EAS: constant shall be converted.
*/

/*PRQA S 3119 EOF*/
/*
No unified input parameter processing is used
*/

/*PRQA S 3197 EOF*/
/*
Redundant initialization will not cause functional problems,there is no need to
revise.And it is the requirement of programming specification to initialize
local variables.
*/

/*PRQA S 3138,3141 EOF*/
/*
The code of critical segments can be configured as void when QAC testing.
Note:When called by Det,Dem or BswM, the critical segments must be enabled when
QAC testing.Reasons are needed for special circumstances not enabled.
*/

/*PRQA S 3416 EOF*/
/*
In a If statement,calling a function to directly determine the return value is 
allowed if there is only one judge branch.
*/

/*PRQA S 0857,0380 EOF*/
/*
Macro definitions exceed 1024. The number of macros is unlimited
*/

/*****************************************************************************
 *  CanIf QAC Suppression
 *****************************************************************************/

/*PRQA S 3227,3204 EOF*/
/*
Read-only function input parameters may not be defined as const,it does not affect the function.
AUTOSAR API shall define standard input parameters according to specification requirements
*/

/*PRQA S 3435,3456 EOF*/
/*
Functional based implementation.
*/

/*PRQA S 2100,2101 EOF*/
/*
Integer promotion related.
*/

/*PRQA S 2000 EOF*/
/*
When there is only one If,there can be no else..
*/

/*PRQA S 3672 EOF*/
/*
Allow non-const function Pointers.
*/

/*PRQA S 3206 EOF*/
/*
Unused function parameters, considering the case of the macro switch on.
*/

/*PRQA S 771 EOF*/
/*
Allows multiple breaks.
*/

/*PRQA S 2844,2814,2934 EOF*/
/*
All array input elements are with in their length.
Null pointer checks performed when retrieving data from Pointers.
*/

/*PRQA S 2877 EOF*/
/*
Depends on configuration.
*/

/*PRQA S 1503,1504,1505 EOF*/
/*
Function declared externally are called by the user.
Variable declared externally are used by the user.
*/

/*PRQA S 791,792 EOF*/
/*
Macro name do no differ within 31 characters
*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanIf.h"
#include "CanIf_Cbk.h"
#include "Bsw_Common.h"


#if(STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*SWS_CANIF_00903*/
#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)
#include "Mirror_Cbk.h"
#endif

#if(STD_ON == CANIF_METADATA_SUPPORT)
#include "Ecuc.h"
#endif

#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_PNNM)
#include "Nm_Cbk.h"
#endif

#if((STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) || (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT))
#include "EcuM_Generated_Types.h"
#endif

#include "CanIf_Callout.h"

/*******************************************************************************
*   Version Check
*******************************************************************************/
/*CANIF021  CANIF728*/
#if(STD_ON == CANIF_PRIVATE_VERSION_CHECK)
/* check Version with other import module */

#if((CANIF_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION_CFG) || \
    ((CANIF_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION_CFG)))
#error "AutoSar Version Numbers of CanIf and its cfg file are different"
#endif

#if((CANIF_SW_MAJOR_VERSION != CANIF_SW_MAJOR_VERSION_CFG) || \
   (CANIF_SW_MINOR_VERSION != CANIF_SW_MINOR_VERSION_CFG))
#error "SW Version Numbers of CanIf and its cfg file are different"
#endif

#endif/*#if(STD_ON == CANIF_PRIVATE_AR_VERSION_CHECK)*/


/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)

#define  CANIF_DET_ERROR_DETECT(cond, ApiId, errcode)  \
    DET_ERROR_DETECT((cond), CANIF_MODULE_ID, CANIF_INSTANCE_ID,(ApiId),(errcode))

#define  CANIF_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret) \
    DET_ERROR_DETECT_RET((cond), CANIF_MODULE_ID,CANIF_INSTANCE_ID,(ApiId),(errcode), (ret))

#define  CANIF_DET_REPORT_ERROR(ApiId, errcode)  \
    DET_REPORT_ERROR(CANIF_MODULE_ID, CANIF_INSTANCE_ID, (ApiId), (errcode))

#else

#define  CANIF_DET_ERROR_DETECT(cond, ApiId, errcode)
#define  CANIF_DET_ERROR_DETECT_RET(cond, ApiId, errcode, ret)
#define  CANIF_DET_REPORT_ERROR(ApiId, errcode)

#endif

/* Used to less code cost in single channel case */
#define CANIF_CONTROLLER_ID                 (ControllerId)

#if(STD_ON == CANIF_TRCV_WAKEUP_SUPPORT)
#define CANIF_TRCV_ID                       (TransceiverId)
#endif


/* Access hth*/
#define CanIf_GetHthOfTxPdu(TxPduId)     (CANIF_HTH_CFG_INFO[CANIF_TXPDU_CFG_INFO[(TxPduId)].HthRef])

#define CanIf_CtrlIdOfTxPdu(TxPduId)     CanIf_GetHthOfTxPdu(TxPduId).CanIfCtrlIdRef

#define CanIf_HthOfTxPdu(TxPduId)        CanIf_GetHthOfTxPdu(TxPduId).HthIdSymRef
#define CanIf_HthTypeOfTxPdu(TxPduId)    CanIf_GetHthOfTxPdu(TxPduId).isFullCanType
#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
#define CanIf_FirstIndexOfTxBuf(TxPduId) CanIf_GetHthOfTxPdu(TxPduId).FirstBufIndexHth
#define CanIf_SizeOfTxBuf(TxPduId)       CanIf_GetHthOfTxPdu(TxPduId).TxBufSize
#endif

#define CanIf_GetDrvIdOfTxPdu(TxPduId)  CanIf_CtrlCfg[CanIf_CtrlIdOfTxPdu(TxPduId)].CanDrvIndex

/* Access hrh*/
#define CanIf_GetHrhOfRxPdu(RxPduId)    (CANIF_HRH_CFG_INFO[CANIF_RXPDU_CFG_INFO[(RxPduId)].HrhRef])
#define CanIf_CtrlIdOfRxPdu(RxPduId)    CanIf_GetHrhOfRxPdu(RxPduId).CanIfCtrlIdRef



#define CanIf_GetDrvIdOfRxPdu(RxPduId)  CanIf_CtrlCfg[CanIf_CtrlIdOfRxPdu(RxPduId)].CanDrvIndex


#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_PNNM)
#define CanIf_GetNmChannel(ControllerId)    CanIf_CtrlCfg[ControllerId].CanIfToNmChannel
#endif
/* Access Controller*/
#define CanIf_GetDrvIdOfCtrl(ControllerId)  CanIf_CtrlCfg[ControllerId].CanDrvIndex
#define CanIf_GetCtrlId(ControllerId)       CanIf_CtrlCfg[ControllerId].CanCtrlIdRef
/*adjust for Nm first message*/
#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)
#define CanIf_GetDrvPnFilterFlag(ControllerId)            CanIf_CtrlCfg[ControllerId].isPnFilter
#endif

/* Access Trcv*/
#if(CANIF_MAX_TRCV_NUM > 0)

#define CanIf_GetDrvIdOfTrcv(TransceiverId)  CanIf_TrcvCfg[TransceiverId].TrcvDrvIndex
#define CanIf_GetTrcvId(TransceiverId)       CanIf_TrcvCfg[TransceiverId].CanTrcvRef
#endif

#if((STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API) || (STD_ON == CANIF_METADATA_SUPPORT))
#define CanIfTxPduCanIdMask_Default           (0xDFFFFFFF)
#endif




#define CANIF_CAN_STD_MAX_CANID             ((Can_IdType)0x07FF)
#define CANIF_CAN_EXT_MAX_CANID             ((Can_IdType)0x1FFFFFFF)
#define CANIF_CAN_EXT_CANID_FLAG            ((Can_IdType)0x80000000)

/*******************************************************************************
*   Local Data Define
*******************************************************************************/
#define CANIF_START_SEC_VAR_INIT_GLOBAL_8
#include "CanIf_MemMap.h"

STATIC VAR(Std_InitStateType, CANIF_VAR)  CanIf_InitStatus = STD_UNINITIALIZED;

#define CANIF_STOP_SEC_VAR_INIT_GLOBAL_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "CanIf_MemMap.h"

#if(CANIF_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
P2CONST(CanIf_ConfigType, CANIF_VAR_NOINIT, CANIF_CONST) CanIf_ConfigSet;
#endif
/*Backup data from CanIf_Transmit to CanIf_TxConfirmation*/
/*CanID length Payload*/
#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)
VAR(CanIf_MirrorBackupType, CANIF_VAR_NOINIT) CanIf_MirrorBackupSts[CANIF_MAX_HTH_NUM];
#endif/*#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)*/

#define CANIF_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "CanIf_MemMap.h"

/* PDU Flag call Can_Write without CanIf_TxConfirmation */
#define CANIF_START_SEC_VAR_CLEARED_LOCAL_8
#include "CanIf_MemMap.h"

#if(CANIF_MAX_TXPDU_NUM > 0)
STATIC VAR(boolean, CANIF_VAR_NOINIT) CanIf_TxWaitConfirmationFlag[CANIF_MAX_TXPDU_NUM];
#endif
#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)
STATIC VAR(boolean, CANIF_VAR_NOINIT) CanIf_BusMirrorEn[CANIF_MAX_CONTROLLER_NUM];
#endif/*#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)*/

#define CANIF_STOP_SEC_VAR_CLEARED_LOCAL_8
#include "CanIf_MemMap.h"

/*******************************************************************************
*   Internal Function Declare
*******************************************************************************/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

#if(CANIF_MAX_TXPDU_NUM > 0)
STATIC FUNC(Std_ReturnType, CANIF_CODE) CanIf_TransmitInternal
(
    PduIdType CanTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
);

#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
STATIC FUNC(void, CANIF_CODE)  CanIf_ClearTransmitBuffer
(
    const uint8 ControllerId
);
#endif

#endif/* #if(CANIF_MAX_TXPDU_NUM > 0) */

#if(CANIF_MAX_RXPDU_NUM > 0)
STATIC FUNC(PduIdType, CANIF_CODE) CanIf_GetRxPduId
(
    uint8 ControllerId,
    Can_HwHandleType Hrh,
    Can_IdType CanId
);

#if(STD_ON == CANIF_PRIVATE_DLC_CHECK)
STATIC FUNC(boolean, CANIF_CODE) CanIf_DlcCheck
(
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  CanDlc,
    const PduIdType RxPduId
);
#endif

#if((STD_OFF == CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT) && (STD_OFF == CANIF_HOH_OPTIMIZE_SUPPORT))
STATIC FUNC(Can_HwHandleType, CANIF_CODE) CanIf_GetInternalHrh
(
    Can_HwHandleType Hrh
);
#endif /*#if((STD_OFF == CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT) && (STD_OFF == CANIF_HOH_OPTIMIZE_SUPPORT))*/

#endif/*#if(CANIF_MAX_RXPDU_NUM > 0)*/

#if((STD_OFF == CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT) && (STD_OFF == CANIF_HOH_OPTIMIZE_SUPPORT))
#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)
STATIC FUNC(Can_HwHandleType, CANIF_CODE) CanIf_MirrorGetHthNum
(
    PduIdType TxPduId
);
#endif
#endif /*#if((STD_OFF == CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT) && (STD_OFF == CANIF_HOH_OPTIMIZE_SUPPORT))*/




/*Data confirmation failure*/
STATIC FUNC(void, CANIF_CODE)  CanIf_TxConfirmationFail
(
    const uint8 ControllerId
);

#if((STD_ON == CANIF_PUBLIC_TX_BUFFERING) && (CANIF_MAX_TXBUF_NUM > 0) && (CANIF_MAX_HTH_NUM > 0))
STATIC FUNC(void, CANIF_CODE)  CanIf_TxConfirmationTransmit
(
    PduIdType CanTxPduId
);
#endif

#if((STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) || (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT))
#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT)
STATIC FUNC(boolean, CANIF_CODE) CanIf_WakeupStatusCheck
(
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr,
    Can_IdType CanId,
    PduIdType canIfRxPduId,
    uint8 ControllerId
);
#endif
#endif

STATIC FUNC(void, CANIF_CODE) CanIf_RxIndicationInternal
(
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr,
    Can_IdType CanId,
    PduIdType canIfRxPduId,
    uint8 ControllerId
);

STATIC FUNC(void, CANIF_CODE) CanIf_PduInit
(
    void
);

#if(CANIF_MAX_TXPDU_NUM > 0)
STATIC FUNC(Std_ReturnType, CANIF_CODE) CanIf_WritePdu
(
    PduIdType CanTxPduId,
    PduLengthType CanIfSduLength,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr,
    P2CONST(Can_PduType, AUTOMATIC, CANIF_APPL_DATA) CanIfTxPduObject,
    P2CONST(uint8, AUTOMATIC, CANIF_APPL_DATA) CanIfTxPduBuffer
);
#endif

/*******************************************************************************
*   Function Define
*******************************************************************************/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_Init  SWS_CANIF_00001
*
* Description:   This service Initializes internal and external interfaces of
*                the CAN Interface for the further processing.
*
* Inputs:        ConfigPtr: Pointer to configuration parameter set,
*                           used e.g. for post build parameters
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_Init
(
    P2CONST(CanIf_ConfigType, AUTOMATIC, CANIF_CONST) ConfigPtr
)
{
    uint8 ControllerId;

#if((STD_ON == CANIF_PUBLIC_TX_BUFFERING) || (STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT))
#if(CANIF_MAX_HTH_NUM > 0)
    Can_HwHandleType HohCnt;
#endif
#endif
#if(CANIF_MAX_TXBUF_NUM > 0)
    PduIdType PduCnt;
#endif


#if(CANIF_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
    if(NULL_PTR == ConfigPtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_INIT_APIID, CANIF_E_PARAM_POINTER);
    }
    else
#endif

    {
#if(CANIF_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
        CanIf_ConfigSet = ConfigPtr;
#else
        (void)ConfigPtr;
#endif
        for(ControllerId = (uint8)0; ControllerId < CANIF_USED_CONTROLLER_NUM; ControllerId++)
        {
            CanIf_PduMode[CANIF_CONTROLLER_ID] = CANIF_OFFLINE;/*SWS_CANIF_00864*/
            CanIf_ControllerMode[CANIF_CONTROLLER_ID] = CANIF_CS_UNINIT;
#if(STD_ON == CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT)
            CanIf_TxConfStatus[CANIF_CONTROLLER_ID] = CANIF_NO_NOTIFICATION;
#endif

#if((STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) || (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT))
#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT)
            CanIf_WakeupStatus[CANIF_CONTROLLER_ID] = FALSE;/*SWS_CANIF_479*/
#endif
#endif

#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)
            CanIf_PnActive[CANIF_CONTROLLER_ID] = CanIf_GetDrvPnFilterFlag(CANIF_CONTROLLER_ID);/*SWS_CANIF_00863*/ /*adjust for Nm first message*/
#endif

        }

        /* CANIF387 init tx buffer */
#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
#if(CANIF_MAX_HTH_NUM > 0)
        for(HohCnt = (Can_HwHandleType)0; HohCnt < CANIF_USED_HTH_NUM; HohCnt++)
        {
            CanIf_TxBufferFillCount[HohCnt] = (PduIdType)0;
        }
#endif

#if(CANIF_MAX_TXBUF_NUM > 0)
        for(PduCnt = (PduIdType)0; PduCnt < CANIF_USED_TXBUF_NUM; PduCnt++)
        {
            CanIf_TxBufActiveFlag[PduCnt] = FALSE;
            CanIf_TxBufPdu[PduCnt].id = (Can_IdType)0;
            CanIf_TxBufPdu[PduCnt].length = (uint8)0;
            CanIf_TxBufPdu[PduCnt].swPduHandle = COMSTACK_INVALID_PDUID;
            CanIf_TxBufPdu[PduCnt].sdu = NULL_PTR;
        }
#endif
#endif/*#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)*/

#if((STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT) && (CANIF_MAX_HTH_NUM > 0))
        for(HohCnt = (Can_HwHandleType)0; HohCnt < CANIF_USED_HTH_NUM; HohCnt++)
        {
            CanIf_TxSwFifo_ResetFifo(HohCnt);
        }
#endif
        CanIf_PduInit();

        for(ControllerId = (uint8)0; ControllerId < CANIF_USED_CONTROLLER_NUM; ControllerId++)
        {
            /*SWS_CANIF_476 477 478*/
            CanIf_ControllerMode[CANIF_CONTROLLER_ID] = CANIF_CS_STOPPED;
        }


        CanIf_InitStatus = STD_INITIALIZED;
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_DeInit  SWS_CANIF_91002
*
* Description:   De-initializes the CanIf module.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_DeInit
(
    void
)
{
    Std_InitStateType DeinitFlag = STD_UNINITIALIZED;
    uint8 ControllerId;

    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_DEINIT_APIID, CANIF_E_UNINIT);
    }
    else
    {
        for(ControllerId = (uint8)0; ControllerId < CANIF_USED_CONTROLLER_NUM; ControllerId++)
        {
            if((CANIF_CS_STARTED == CanIf_ControllerMode[CANIF_CONTROLLER_ID]) ||
                (CANIF_OFFLINE != CanIf_PduMode[CANIF_CONTROLLER_ID]))
            {
                DeinitFlag = STD_INITIALIZED;
                break;
            }
        }
    }

    CanIf_InitStatus = DeinitFlag;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_SetControllerMode  SWS_CANIF_00003
*
* Description:   This service calls the corresponding CAN Driver service for
*                changing of the CAN controller mode.
*
* Inputs:        ControllerId: Abstracted CanIf ControllerId which is assigned
*                              to a CAN controller, which is requested for mode
*                              transition.
*                ControllerMode: Requested mode transition
*
* Outputs:       Std_ReturnType:E_OK: Controller mode request has been accepted
*                               E_NOT_OK: Controller mode request has not been
*                               accepted
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetControllerMode
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
)
{
    Std_ReturnType ret = E_OK;
    CanIf_CanSetControllerModeType canSetModeFctPtr;
    Can_StateTransitionType targetMode;
    
#if((STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT) && (CANIF_MAX_HTH_NUM > 0))
    Can_HwHandleType HohCnt;
#endif

    /*SWS_CANIF_00311 312*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETCONTROLLERMODE_APIID, CANIF_E_UNINIT);
        ret = E_NOT_OK;
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETCONTROLLERMODE_APIID, CANIF_E_PARAM_CONTROLLERID);
        ret = E_NOT_OK;
    }
    else
    {
        /* since the state transition is not very clear in V4.0.3
        so here follow the V4.2.2's detail
        from start -> sleep and from sleep to start are both not allowed
        if the invalid transition is called, canDrv should return Not_Ok

        V4.2.2 SWS_CANIF_00488  SWS_CANIF_00487 ,
        CanSM will not send such transition request ever
        V4.0.3  CANIF719
        */

        /* src     dest  result
        stop -> stop  stop   SWS_CANIF_480
        stop -> start  start SWS_CANIF_481
        stop -> sleep  sleep SWS_CANIF_482

        start->start start   CANIF584
        start->stop stop        CANIF585
        start->sleep sleep     candrv retrun not ok

        sleep->sleep  sleep  SWS_CANIF_486
        sleep->stop  wake  SWS_CANIF_487
        sleep->start start  candrv retrun not ok
        */
        switch(ControllerMode)
        {
        case CANIF_CS_STARTED:
            targetMode = CAN_T_START;    /*if sleep ->start this will be detected by canDrv*/
#if((STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT) && (CANIF_MAX_HTH_NUM > 0))
            for(HohCnt = (Can_HwHandleType)0; HohCnt < CANIF_USED_HTH_NUM; HohCnt++)
            {
                if(CANIF_HTH_CFG_INFO[HohCnt].CanIfCtrlIdRef == CANIF_CONTROLLER_ID)
                {
                    CanIf_TxSwFifo_ResetFifo(HohCnt);
                }
            }
#endif
            break;

        case CANIF_CS_SLEEP:
            targetMode = CAN_T_SLEEP;  /*if sleep ->start this will be detected by canDrv*/
            /*
            SWS_CANIF_865, set OffLine when call CanIf_SetControllerMode(sleep)
            SWS_CANIF_0073,clear txbuffer when swtich to Offline
            */
            CanIf_PduMode[CANIF_CONTROLLER_ID] = CANIF_OFFLINE;
            /*SWS_CANIF_00739*/
            CanIf_TxConfirmationFail(CANIF_CONTROLLER_ID);
#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
            CanIf_ClearTransmitBuffer(CANIF_CONTROLLER_ID);
#endif

#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)
            CanIf_PnActive[CANIF_CONTROLLER_ID] = CanIf_GetDrvPnFilterFlag(CANIF_CONTROLLER_ID);/*SWS_CANIF_00749*/ /*adjust for Nm first message*/
#endif


            break;

        case CANIF_CS_STOPPED:
            if(CANIF_CS_SLEEP == CanIf_ControllerMode[CANIF_CONTROLLER_ID])
            {
                targetMode = CAN_T_WAKEUP;
            }
            else
            {
                targetMode = CAN_T_STOP;
            }

            /*
            SWS_CANIF_866, set TxOffLine when call CanIf_SetControllerMode(stop)
            SWS_CANIF_489,clear txbuffer when swtich to txOffline
            */
            CanIf_PduMode[CANIF_CONTROLLER_ID] = CANIF_TX_OFFLINE;
            /*SWS_CANIF_00739*/
            CanIf_TxConfirmationFail(CANIF_CONTROLLER_ID);
#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
            CanIf_ClearTransmitBuffer(CANIF_CONTROLLER_ID);
#endif
            break;

        default:
            /*SWS_CANIF_00774*/
            CANIF_DET_REPORT_ERROR(CANIF_SETCONTROLLERMODE_APIID, CANIF_E_PARAM_CTRLMODE);
            ret = E_NOT_OK;
            break;
        }

        if(E_OK == ret)
        {
            canSetModeFctPtr = CanIf_Can_SetControllerMode[CanIf_GetDrvIdOfCtrl(CANIF_CONTROLLER_ID)];
            if(NULL_PTR == canSetModeFctPtr)
            {
                CANIF_DET_REPORT_ERROR(CANIF_SETCONTROLLERMODE_APIID, CANIF_E_LINKAPINULL);
                ret = E_NOT_OK;
            }
            else
            {
                /*SWS_CANIF_00308*/
                if(CAN_OK != canSetModeFctPtr(CanIf_GetCtrlId(CANIF_CONTROLLER_ID), targetMode))
                {
                    ret = E_NOT_OK;/*SWS_CANIF_475*/
                }
            }
        }
    }
    return ret;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetControllerMode  SWS_CANIF_00229
*
* Description:   This service reports about the current status of the requested
*                CAN controller.
*
* Inputs:        ControllerId      Abstracted CanIf ControllerId which is
*                                  assigned to a CAN controller, which is
*                                  requested for current operation mode.
*                ControllerModePtr Pointer to a memory location, where the
*                                  current mode of the CAN controller will be
*                                  stored.
*
* Outputs:       Std_ReturnType:E_OK: Controller mode request has been accepted
*                               E_NOT_OK: Controller mode request has not been
*                               accepted
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode
(
    uint8 ControllerId,
    P2VAR(CanIf_ControllerModeType, AUTOMATIC, CANIF_APPL_DATA) ControllerModePtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*SWS_CANIF_00316 313 656*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERMODE_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERMODE_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else if(NULL_PTR == ControllerModePtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERMODE_APIID, CANIF_E_PARAM_POINTER);
    }
    else
    {
        /*SWS_CANIF_00229*/
        *ControllerModePtr = CanIf_ControllerMode[CANIF_CONTROLLER_ID];
        ret = E_OK;
    }

    return ret;

}

#if(CANIF_MAX_TXPDU_NUM > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_TransmitInternal
*
* Description:   This service Transmit a can PDU
*
*
* Inputs:        CanTxPduId   L-PDU handle of CAN L-PDU to be transmitted.
*                             This handle specifies the corresponding CAN L-PDU
*                             ID and implicitly the CAN Driver instance as well
*                             as the corresponding CAN controller device.
*                PduInfoPtr   Pointer to a structure with CAN L-PDU related data
*                             DLC and pointer to CAN L-SDU buffer
*
* Outputs:       Std_ReturnType:E_OK: request has been accepted
*                               E_NOT_OK: request has not been accepted
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, CANIF_CODE) CanIf_TransmitInternal
(
    PduIdType CanTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
)
{
#if(STD_ON == CANIF_PRIVATE_CANFD_SUPPORT)
    uint8 CanIfTxPduBuffer[CANIF_CANFD_MAX_DLC];
#else
    uint8 CanIfTxPduBuffer[CANIF_CAN_MAX_DLC];
#endif

    Can_PduType CanIfTxPduObject;
    CanIf_CanWriteType canWriteFctPtr;
    Std_ReturnType ret = E_NOT_OK;
    PduLengthType CanIfSduLength;
    uint8 MaxDlc;

#if(STD_ON == CANIF_METADATA_SUPPORT)
    uint32 MetadataCanId;
#endif

    canWriteFctPtr = CanIf_Can_Write[CanIf_GetDrvIdOfTxPdu(CanTxPduId)];
    if(NULL_PTR == canWriteFctPtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRANSMIT_APIID, CANIF_E_LINKAPINULL);
    }
    else
    {
        /* SWS_CANIF_00318 SWS_CANIF_00243 */
        SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_0();
#if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)
#if(CANIF_MAX_DYNTXPDU_NUM > 0)
        /*So that,CanIf_SetDynamicTxId()will not be interrupted
        by CanIf_Transmit()*/

        if(TRUE == CANIF_TXPDU_CFG_INFO[CanTxPduId].isDynPduType)
        {
            CanIfTxPduObject.id = CanIf_TxPduCanIdForDynamic[CANIF_TXPDU_CFG_INFO[CanTxPduId].DynPduIndex];
        }
        else
#endif
#endif
        {
            CanIfTxPduObject.id = CANIF_TXPDU_CFG_INFO[CanTxPduId].CanId;
        }
        SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_0();

/*SWS_CANIF_00855*/
#if(STD_ON == CANIF_METADATA_SUPPORT)
        /*SWS_CANIF_00856*/
        if(CanIfTxPduCanIdMask_Default != CANIF_TXPDU_CFG_INFO[CanTxPduId].TxPduCanIdMask)
        {
            /*PRQA S 0314 ++*/
            /*Because the input parameter of Ecuc_GetMetaData is void*.*/
            if(E_OK == Ecuc_GetMetaData(CANIF_TXPDU_CFG_INFO[CanTxPduId].GlobalPduId, ECUC_ENUM_CAN_ID, (void*)(&MetadataCanId)))
            {
                /* SWS_CANIF_00854 */
                CanIfTxPduObject.id = (Can_IdType)(((CANIF_TXPDU_CFG_INFO[CanTxPduId].CanId) & CANIF_TXPDU_CFG_INFO[CanTxPduId].TxPduCanIdMask)
                    | (MetadataCanId & ~CANIF_TXPDU_CFG_INFO[CanTxPduId].TxPduCanIdMask));
            }
            /*PRQA S 0314 --*/
        }
#endif

        /* check dlc */
#if(STD_ON == CANIF_PRIVATE_CANFD_SUPPORT)
        if((STANDARD_FD_CAN == CANIF_TXPDU_CFG_INFO[CanTxPduId].CanIdType) ||
            (EXTENDED_FD_CAN == CANIF_TXPDU_CFG_INFO[CanTxPduId].CanIdType))
        {
            MaxDlc = CANIF_CANFD_MAX_DLC;
        }
        else
        {
            MaxDlc = CANIF_CAN_MAX_DLC;
        }
#else
        MaxDlc = CANIF_CAN_MAX_DLC;
#endif/*#if(STD_ON == CANIF_PRIVATE_CANFD_SUPPORT)*/

        /*SWS_CANIF_00893 SWS_CANIF_00894 SWS_CANIF_00900*/
        if((PduInfoPtr->SduLength > MaxDlc) && (FALSE == CANIF_TXPDU_CFG_INFO[CanTxPduId].TxPduTruncation))
        {
            CANIF_DET_REPORT_ERROR(CANIF_TRANSMIT_APIID, CANIF_E_TXPDU_LENGTH_EXCEEDED);
        }
        else
        {
            if(PduInfoPtr->SduLength > MaxDlc)
            {
                CanIfSduLength = MaxDlc;
            }
            else
            {
                CanIfSduLength = PduInfoPtr->SduLength;
            }
            SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_1();
#if(STD_ON == CANIF_TRIGGER_TRANSMIT_SUPPORT)
            if(TRUE == CANIF_TXPDU_CFG_INFO[CanTxPduId].isTriggerPdu)
            {
                CanIfTxPduObject.length = (uint8)0;
                CanIfTxPduObject.sdu = NULL_PTR;
                CanIfTxPduObject.swPduHandle = CanTxPduId;
            }
            else
#endif
            {
                /* DLC has Checked in det */
                CanIfTxPduObject.length = (uint8)CanIfSduLength;
                Bsw_MemCpy(CanIfTxPduBuffer, PduInfoPtr->SduDataPtr, (uint32)CanIfTxPduObject.length);
                CanIfTxPduObject.sdu = &CanIfTxPduBuffer[0];
                CanIfTxPduObject.swPduHandle = CanTxPduId;
            }
            SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_1();

            ret = CanIf_WritePdu(CanTxPduId, CanIfSduLength, PduInfoPtr, &CanIfTxPduObject, CanIfTxPduBuffer);

        }

    }
    return ret;
}

#endif/*#if(CANIF_MAX_TXPDU_NUM > 0)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_Transmit  SWS_CANIF_00005
*
* Description:   This service Transmit a can PDU
*
*
* Inputs:        CanTxPduId   L-PDU handle of CAN L-PDU to be transmitted.
*                             This handle specifies the corresponding CAN L-PDU
*                             ID and implicitly the CAN Driver instance as well
*                             as the corresponding CAN controller device.
*                PduInfoPtr   Pointer to a structure with CAN L-PDU related data
*                             DLC and pointer to CAN L-SDU buffer
*
* Outputs:       Std_ReturnType:E_OK: request has been accepted
*                               E_NOT_OK: request has not been accepted
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit
(
    PduIdType CanTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
)
{
    uint8 ControllerId = (uint8)0;
    Std_ReturnType ret = E_NOT_OK;
    CanIf_PduModeType tempMode;


    /*SWS_CANIF_00319 320*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRANSMIT_APIID, CANIF_E_UNINIT);
    }
    else if(CanTxPduId >= CANIF_USED_TXPDU_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRANSMIT_APIID, CANIF_E_INVALID_TXPDUID);
    }
    else if((NULL_PTR == PduInfoPtr)
#if((STD_ON == CANIF_TRIGGER_TRANSMIT_SUPPORT) && (CANIF_MAX_TXPDU_NUM > 0))
            && (FALSE == CANIF_TXPDU_CFG_INFO[CanTxPduId].isTriggerPdu) /*SWS_CANIF_00882*/
#endif
           )
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRANSMIT_APIID, CANIF_E_PARAM_POINTER);
    }
    else
    {

#if(CANIF_MAX_TXPDU_NUM > 0)
        ControllerId = CanIf_CtrlIdOfTxPdu(CanTxPduId);
        tempMode = CanIf_PduMode[CANIF_CONTROLLER_ID];

        /* SWS_CANIF_00317 if controller is not in start or the channel is in txoffline
           the tx request will not accept SWS_CANIF_00382 723 677*/
        if((CANIF_CS_STARTED != CanIf_ControllerMode[CANIF_CONTROLLER_ID])
                || (CANIF_OFFLINE == tempMode) /*SWS_CANIF_00073*/
                || (CANIF_TX_OFFLINE == tempMode)) /*SWS_CANIF_00489*/
        {
            /* remoce this Det as , message may need transmit in busoff state*/
            /*CANIF_DET_REPORT_ERROR(CANIF_TRANSMIT_APIID, CANIF_E_STOPPED);*/
        }
        else
        {
#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)/*SWS_CANIF_00750*/
            /* when pn enable, only pdu config as pnfilter can be transmit*/
            if((FALSE == CanIf_PnActive[CANIF_CONTROLLER_ID])
                    || (TRUE == CANIF_TXPDU_CFG_INFO[CanTxPduId].isPnFilterPdu))
#endif
            {
#if(STD_ON == CANIF_TXOFF_ACTIVE_SUPPORT)/*SWS_CANIF_00072*/
                if(CANIF_TX_OFFLINE_ACTIVE == tempMode)
                {
                    ret = E_OK;
                    /*
                    this call up back may cause uplayyer's state incorrect
                    */
                    CanIf_TxConfirmation(CanTxPduId);
                }
                else
#endif
                {
                    ret = CanIf_TransmitInternal(CanTxPduId, PduInfoPtr);
                }
            }

        }

#endif/*#if(CANIF_MAX_TXPDU_NUM > 0)*/
    }


    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ReadRxPduData SWS_CANIF_00194
*
* Description:   This service provides the CAN DLC and the received data of the
*                requested CanRxPduId to the calling upper layer.
*                NOTE:This API must not be used for CanRxPduIds, which are
*                defined to receive multiple CAN-Ids (range reception).
*
* Inputs:        CanRxPduId   L-PDU handle of CAN L-PDU to be received.
*                             This handle specifies the corresponding CAN L-PDU
*                             ID and implicitly the CAN Driver instance as well
*                             as the corresponding CAN controller device.
*                PduInfoPtr   Pointer to a structure with CAN L-PDU related data
*                             DLC and pointer to CAN L-SDU buffer
*
* Outputs:       Std_ReturnType  E_OK: Request for L-PDU data has been accepted
*                                E_NOT_OK: No valid data has been received
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if((STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API) && (CANIF_MAX_RXBUF_NUM > 0))/*SWS_CANIF_00330*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ReadRxPduData
(
    PduIdType CanRxPduId,
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
)
{
    uint8 ControllerId = (uint8)0;
    CanIf_PduModeType tempMode;
    Std_ReturnType ret = E_NOT_OK;
    PduIdType bufIndex = (PduIdType)0;

    /*SWS_CANIF_00325 326*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_READRXPDUDATA_APIID, CANIF_E_UNINIT);
    }
    else if((CanRxPduId >= CANIF_USED_RXPDU_NUM) || (FALSE == CANIF_RXPDU_CFG_INFO[CanRxPduId].RxPduReadData))
    {
        CANIF_DET_REPORT_ERROR(CANIF_READRXPDUDATA_APIID, CANIF_E_INVALID_RXPDUID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_READRXPDUDATA_APIID, CANIF_E_PARAM_POINTER);
    }
    else
    {
#if(CANIF_MAX_RXBUF_NUM > 0)
        ControllerId = CanIf_CtrlIdOfRxPdu(CanRxPduId);
        tempMode = CanIf_PduMode[CANIF_CONTROLLER_ID];

        /*SWS_CANIF_00324*/
        if(CANIF_CS_STARTED == CanIf_ControllerMode[CANIF_CONTROLLER_ID])
        {
            if(tempMode > CANIF_TX_OFFLINE_ACTIVE)
            {
                bufIndex = CANIF_RXPDU_CFG_INFO[CanRxPduId].RxBufIndex;
                SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_6();/*SWS_CANIF_199*//*SWS_CANIF_00329*/
#if(STD_ON == CANIF_PRIVATE_CANFD_SUPPORT)
                if(CanIf_RxBufferSduLength[bufIndex] <= CANIF_CANFD_MAX_DLC)
#else
                if(CanIf_RxBufferSduLength[bufIndex] <= CANIF_CAN_MAX_DLC)
#endif
                {

                    PduInfoPtr->SduLength = CanIf_RxBufferSduLength[bufIndex];
                    Bsw_MemCpy(PduInfoPtr->SduDataPtr, CANIF_RXPDU_CFG_INFO[CanRxPduId].dataBuf,
                               (uint32)CanIf_RxBufferSduLength[bufIndex]);

                    ret = E_OK;
                }
                SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_6();
            }
        }
#endif/*#if(CANIF_MAX_RXBUF_NUM > 0)*/

    }
    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ReadTxNotifStatus SWS_CANIF_00202
*
* Description:   This service returns the confirmation status
*                (confirmation occured of not) of a specific
*                static or dynamic CAN Tx L-PDU, requested by the CanTxPduId.
*
* Inputs:        CanTxPduId   L-PDU handle of CAN L-PDU to be transmitted.
*                             This handle specifies the corresponding CAN L-PDU
*                             ID and implicitly the CAN Driver instance as well
*                             as the corresponding CAN controller device.
*
* Outputs:       CanIf_NotifStatusType   Current confirmation status of the
*                                        corresponding CAN Tx L-PDU.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)/*SWS_CANIF_00335*/
#if(CANIF_MAX_TXNOTIFY_NUM > 0)
FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadTxNotifStatus
(
    PduIdType CanTxPduId
)
{
    CanIf_NotifStatusType ret = CANIF_NO_NOTIFICATION;
    PduIdType notifyIndex;

    /*SWS_CANIF_00331 334*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_READTXNOTIFSTATUS_APIID, CANIF_E_UNINIT);
    }
    else if((CanTxPduId >= CANIF_USED_TXPDU_NUM) || (FALSE == CANIF_TXPDU_CFG_INFO[CanTxPduId].TxPduReadNotifyStatus))
    {
        CANIF_DET_REPORT_ERROR(CANIF_READTXNOTIFSTATUS_APIID, CANIF_E_INVALID_TXPDUID);
    }
    else
    {

        notifyIndex = CANIF_TXPDU_CFG_INFO[CanTxPduId].TxNotifyIndex;
        if(CANIF_TX_RX_NOTIFICATION == CanIf_TxNotifStatus[notifyIndex])
        {
            ret =  CANIF_TX_RX_NOTIFICATION;
            CanIf_TxNotifStatus[notifyIndex] = CANIF_NO_NOTIFICATION;/*SWS_CANIF_00393*/
        }
    }

    return ret;
}
#endif
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ReadRxNotifStatus  SWS_CANIF_00230
*
* Description:   This service returns the indication status
*                (indication occured of not) of a specific
*                static or dynamic CAN Rx L-PDU, requested by the CanRxPduId.
*
* Inputs:        CanRxPduId   L-PDU handle of CAN L-PDU to be received.
*                             This handle specifies the corresponding CAN L-PDU
*                             ID and implicitly the CAN Driver instance as well
*                             as the corresponding CAN controller device.
*
* Outputs:       CanIf_NotifStatusType   Current confirmation status of the
*                                        corresponding CAN Rx L-PDU.
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)/*SWS_CANIF_00340*/
#if(CANIF_MAX_RXNOTIFY_NUM > 0)
FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadRxNotifStatus
(
    PduIdType CanRxPduId
)
{
    CanIf_NotifStatusType ret = CANIF_NO_NOTIFICATION;
    PduIdType notifyIndex;

    /*SWS_CANIF_00336  339*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_READRXNOTIFSTATUS_APIID, CANIF_E_UNINIT);
    }
    else if((CanRxPduId >= CANIF_USED_RXPDU_NUM) || (FALSE == CANIF_RXPDU_CFG_INFO[CanRxPduId].RxPduReadNotifyStatus))
    {
        CANIF_DET_REPORT_ERROR(CANIF_READRXNOTIFSTATUS_APIID, CANIF_E_INVALID_RXPDUID);
    }
    else
    {

        notifyIndex = CANIF_RXPDU_CFG_INFO[CanRxPduId].RxNotifyIndex;
        if(CANIF_TX_RX_NOTIFICATION == CanIf_RxNotifStatus[notifyIndex])
        {
            ret =  CANIF_TX_RX_NOTIFICATION;
            CanIf_RxNotifStatus[notifyIndex] = CANIF_NO_NOTIFICATION;  /*SWS_CANIF_00394*/
        }

    }

    return ret;
}
#endif
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_SetPduMode  SWS_CANIF_00008
*
* Description:   This service sets the requested mode at the L-PDUs of a
*                predefined logical PDU channel.
*
* Inputs:        ControllerId   All PDUs of the own ECU connected to the
*                               corresponding CanIf ControllerId, which is
*                               assigned to a physical CAN controller are
*                               addressed.
*                PduModeRequest Requested PDU mode change
*                               (see CanIf_PduSetModeType)
*
* Outputs:       Std_ReturnType:E_OK: Controller mode request has been accepted
*                               E_NOT_OK: Controller mode request has not been
*                               accepted
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode
(
    uint8 ControllerId,
    CanIf_PduModeType PduModeRequest
)
{
    Std_ReturnType ret = E_NOT_OK;
#if((STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT) && (CANIF_MAX_HTH_NUM > 0))
    Can_HwHandleType HohCnt;
#endif
    /*SWS_CANIF_00860 341 344*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETPDUMODE_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETPDUMODE_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    /*PRQA S 1476 ++*/
    /*
    The result of this comparison will always be 'false'..
    */
    else if(PduModeRequest > CANIF_ONLINE)
    /*PRQA S 1476 --*/
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETPDUMODE_APIID, CANIF_E_PARAM_PDU_MODE);
    }
    else
    {
        /*SWS_CANIF_00874*/
        if(CANIF_CS_STARTED == CanIf_ControllerMode[CANIF_CONTROLLER_ID])
        {
            if(PduModeRequest < CANIF_ONLINE)
            {
                /*SWS_CANIF_00739*/
                CanIf_TxConfirmationFail(CANIF_CONTROLLER_ID);
#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
                /*Clear tx buffer when enter offline txoffline  SWS_CANIF_0073 SWS_CANIF_489
                tx-off-active is not reqired by autosar, but here also clear buffer.*/
                CanIf_ClearTransmitBuffer(CANIF_CONTROLLER_ID);
#endif
            }

#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)
            /* SWS_CANIF_00878 */
            if(PduModeRequest == CANIF_TX_OFFLINE)
            {
                CanIf_PnActive[CANIF_CONTROLLER_ID] = CanIf_GetDrvPnFilterFlag(CANIF_CONTROLLER_ID); /*adjust for Nm first message*/
            }
#endif
            CanIf_PduMode[CANIF_CONTROLLER_ID] = PduModeRequest;

#if((STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT) && (CANIF_MAX_HTH_NUM > 0))
            if(PduModeRequest == CANIF_ONLINE)
            {
                for(HohCnt = (Can_HwHandleType)0; HohCnt < CANIF_USED_HTH_NUM; HohCnt++)
                {
                    if(CANIF_HTH_CFG_INFO[HohCnt].CanIfCtrlIdRef == CANIF_CONTROLLER_ID)
                    {
                        CanIf_TxSwFifo_ResetFifo(HohCnt);
                    }
                }
            }
#endif
            ret = E_OK;
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetPduMode  SWS_CANIF_00009
*
* Description:   This service reports the current mode of a requested PDU
*                channel.
*
* Inputs:        ControllerId   All PDUs of the own ECU connected to the
*                               corresponding CanIf ControllerId, which is
*                               assigned to a physical CAN controller are
*                               addressed.
*                PduModePtr     Pointer to a memory location, where the current
*                               mode of the logical PDU channel will be stored.
*
* Outputs:       Std_ReturnType:E_OK: Controller mode request has been accepted
*                               E_NOT_OK: Controller mode request has not been
*                               accepted
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetPduMode
(
    uint8 ControllerId,
    P2VAR(CanIf_PduModeType, AUTOMATIC, CANIF_APPL_DATA) PduModePtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    /*SWS_CANIF_00346 349 657*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETPDUMODE_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETPDUMODE_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else if(NULL_PTR == PduModePtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETPDUMODE_APIID, CANIF_E_PARAM_POINTER);
    }
    else
    {
        *PduModePtr = CanIf_PduMode[CANIF_CONTROLLER_ID];
        ret = E_OK;
    }
    return ret;
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetVersionInfo  SWS_CANIF_00158
*
* Description:   This service returns the version information of the called
*                CAN Interface module
*
* Inputs:        VersionInfo  Pointer to where to store the version information
*                             of this module.DLC and pointer to CAN L-SDU buffer
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == CANIF_PUBLIC_VERSION_INFO_API)
FUNC(void, CANIF_CODE) CanIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CANIF_APPL_DATA) VersionInfo
)
{
    if(NULL_PTR == VersionInfo)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETVERSIONINFO, CANIF_E_PARAM_POINTER);
    }
    else
    {
        /*SWS_CANIF_00661 getVersion can be called even canif is not init */
        VersionInfo->vendorID = CANIF_VENDOR_ID;
        VersionInfo->moduleID = CANIF_MODULE_ID;

        VersionInfo->sw_major_version = (uint8)CANIF_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)CANIF_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)CANIF_SW_PATCH_VERSION;
    }
}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_SetDynamicTxId  SWS_CANIF_00189
*
* Description:   This service set dynamic id
*
* Inputs:        CanTxPduId   L-PDU handle of CAN L-PDU to be transmitted.
*                             This handle specifies the corresponding CAN L-PDU
*                             ID and implicitly the CAN Driver instance as well
*                             as the corresponding CAN controller device.
*                CanId        Standard/Extended CAN ID of CAN L-PDU that shall
*                             be transmitted
*
* Outputs:       None
*
* Limitations:   The input id must have extension bit
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)/*SWS_CANIF_00357*/
#if(CANIF_MAX_DYNTXPDU_NUM > 0)
FUNC(void, CANIF_CODE) CanIf_SetDynamicTxId
(
    PduIdType CanTxPduId,
    Can_IdType CanId
)
{
    Can_IdType usedId;
    Can_IdType maxId;

    /*SWS_CANIF_00352 355 356*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETDYNAMICTXID_APIID, CANIF_E_UNINIT);
    }
    else if((CanTxPduId >= CANIF_USED_TXPDU_NUM) || (FALSE == CANIF_TXPDU_CFG_INFO[CanTxPduId].isDynPduType))
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETDYNAMICTXID_APIID, CANIF_E_INVALID_TXPDUID);
    }
    else
    {
        /*SWS_CANIF_00353
            extension bit = 0, id must <= 0x7ff
            extension bit = 1, id must <= 0x1fffffff
        */
        usedId = CanId;

        if(CANIF_CAN_EXT_CANID_FLAG == (CanId & CANIF_CAN_EXT_CANID_FLAG))
        {
            maxId = CANIF_CAN_EXT_MAX_CANID;
            usedId = (CanId & (~CANIF_CAN_EXT_CANID_FLAG));
        }
        else
        {
            maxId = CANIF_CAN_STD_MAX_CANID;
        }
#if(STD_ON == CANIF_PRIVATE_CANFD_SUPPORT)
        usedId &= (~CAN_CANFD_MASK);
#endif

        if(usedId > maxId)
        {
            CANIF_DET_REPORT_ERROR(CANIF_SETDYNAMICTXID_APIID, CANIF_E_PARAM_CANID);
        }
        else
        {
            /*SWS_CANIF_00356*/
            SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_5();
            CanIf_TxPduCanIdForDynamic[CANIF_TXPDU_CFG_INFO[CanTxPduId].DynPduIndex] =
                ((CANIF_TXPDU_CFG_INFO[CanTxPduId].CanId & CANIF_TXPDU_CFG_INFO[CanTxPduId].TxPduCanIdMask)
                | (CanId & (Can_IdType)(~CANIF_TXPDU_CFG_INFO[CanTxPduId].TxPduCanIdMask)));
            SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_5();

        }
    }

}
#endif
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_SetTrcvMode  SWS_CANIF_00287
*
* Description:   This service set Trcv's opration mode
*
* Inputs:        TransceiverId, TranseiverMode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(CANIF_MAX_TRCV_NUM > 0)/*SWS_CANIF_362  367 371 373*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvMode
(
    uint8 TransceiverId,
    CanTrcv_TrcvModeType TranseiverMode
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*SWS_CANIF_00538 648*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETTRCVMODE_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETTRCVMODE_APIID, CANIF_E_PARAM_TRCV);
    }
    else if((CANTRCV_TRCVMODE_NORMAL != TranseiverMode)
            && (CANTRCV_TRCVMODE_SLEEP != TranseiverMode)
            && (CANTRCV_TRCVMODE_STANDBY != TranseiverMode))
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETTRCVMODE_APIID, CANIF_E_PARAM_TRCVMODE);
    }
    else if(NULL_PTR == CanIf_CanTrcv_SetOpMode[CanIf_GetDrvIdOfTrcv(TransceiverId)])
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETTRCVMODE_APIID, CANIF_E_LINKAPINULL);
    }
    else
    {
        /*SWS_CANIF_00358*/
        ret = CanIf_CanTrcv_SetOpMode[CanIf_GetDrvIdOfTrcv(TransceiverId)](CanIf_GetTrcvId(TransceiverId), TranseiverMode);
    }


    return ret;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetTrcvMode  SWS_CANIF_00288
*
* Description:   This service get Trcv's opration mode
*
* Inputs:        TransceiverId, TransceiverModePtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvMode
(
    uint8 TransceiverId,
    P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_APPL_DATA) TransceiverModePtr
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*SWS_CANIF_00364 650 */
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTRCVMODE_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTRCVMODE_APIID, CANIF_E_PARAM_TRCV);
    }
    else if(NULL_PTR == TransceiverModePtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTRCVMODE_APIID, CANIF_E_PARAM_POINTER);
    }
    else if(NULL_PTR == CanIf_CanTrcv_GetOpMode[CanIf_GetDrvIdOfTrcv(TransceiverId)])
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTRCVMODE_APIID, CANIF_E_LINKAPINULL);
    }
    else
    {
        /*SWS_CANIF_00363*/
        ret = CanIf_CanTrcv_GetOpMode[CanIf_GetDrvIdOfTrcv(TransceiverId)](CanIf_GetTrcvId(TransceiverId), TransceiverModePtr);
    }

    return ret;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetTrcvWakeupReason  SWS_CANIF_00289
*
* Description:   This service get Trcv's wakeup reason
*
* Inputs:        TransceiverId, TrcvWuReasonPtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason
(
    uint8 TransceiverId,
    P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_APPL_DATA)  TrcvWuReasonPtr
)
{
    Std_ReturnType ret = E_NOT_OK;


    /*SWS_CANIF_00537 649 */
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTRCVWUR_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTRCVWUR_APIID, CANIF_E_PARAM_TRCV);
    }
    else if(NULL_PTR == TrcvWuReasonPtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTRCVWUR_APIID, CANIF_E_PARAM_POINTER);
    }
    else if(NULL_PTR == CanIf_CanTrcv_GetWuR[CanIf_GetDrvIdOfTrcv(TransceiverId)])
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTRCVWUR_APIID, CANIF_E_LINKAPINULL);
    }
    else
    {
        /*SWS_CANIF_00368*/
        ret = CanIf_CanTrcv_GetWuR[CanIf_GetDrvIdOfTrcv(TransceiverId)](CanIf_GetTrcvId(TransceiverId), TrcvWuReasonPtr);
    }

    return ret;

}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_SetTrcvWakeupMode  SWS_CANIF_00290
*
* Description:   This service set Trcv's wakeup mode
*
* Inputs:        TransceiverId, TrcvWakeupMode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvWakeupMode
(
    uint8 TransceiverId,
    CanTrcv_TrcvWakeupModeType TrcvWakeupMode
)
{
    Std_ReturnType ret = E_NOT_OK;

    /*SWS_CANIF_00535 536*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETTRCVWUMODE_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETTRCVWUMODE_APIID, CANIF_E_PARAM_TRCV);
    }
    else if((CANTRCV_WUMODE_ENABLE != TrcvWakeupMode)
            && (CANTRCV_WUMODE_DISABLE != TrcvWakeupMode)
            && (CANTRCV_WUMODE_CLEAR != TrcvWakeupMode))
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETTRCVWUMODE_APIID, CANIF_E_PARAM_TRCVWAKEUPMODE);
    }
    else if(NULL_PTR == CanIf_CanTrcv_SetWuMode[CanIf_GetDrvIdOfTrcv(TransceiverId)])
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETTRCVWUMODE_APIID, CANIF_E_LINKAPINULL);
    }
    else
    {
        /*SWS_CANIF_00372*/
        ret = CanIf_CanTrcv_SetWuMode[CanIf_GetDrvIdOfTrcv(TransceiverId)](CanIf_GetTrcvId(TransceiverId), TrcvWakeupMode);
    }

    return ret;

}

#endif/*#if(CANIF_MAX_TRCV_NUM > 0)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_CheckWakeup  SWS_CANIF_00219
*
* Description:   This service check the wakeu src
*
* Inputs:        WakeupSource
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
/* SWS_CANIF_00180 892*/
#if((STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) || (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT))
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup
(
    EcuM_WakeupSourceType WakeupSource
)
{
    uint8 searchIndex = (uint8)0;
    uint8 ControllerId;

#if(STD_ON == CANIF_CTRL_WAKEUP_SUPPORT)
    CanIf_CanCheckWakeupType canCheckFctPtr;
#endif

#if(STD_ON == CANIF_TRCV_WAKEUP_SUPPORT)
    uint8 TransceiverId;
    CanIf_TrcvCheckWakeupType canTrcvCheckFctPtr;
#endif
    Std_ReturnType ret = E_NOT_OK;

    /*SWS_CANIF_00401 398*/
    boolean srcValidFlag = FALSE;/* used to check the WakeupSource  */

    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CHECKWAKEUP_APIID, CANIF_E_UNINIT);
    }
    else
    {
        /* SWS_CANIF_395 720 678
           first get target controller or trcv , search the wakeup source
           each controller or trcv can only have single wakeupsource
           then, call the target Xxx_CheckWakeup to confirm the wakeup
          */

        for(searchIndex = (uint8)0; searchIndex < CANIF_USED_WAKRUPSRC_NUM; searchIndex++)
        {
            if((EcuM_WakeupSourceType)0 != ((EcuM_WakeupSourceType)(CanIf_WakeupCfg[searchIndex].Source) & WakeupSource))
            {
                srcValidFlag = TRUE;
                ControllerId = CanIf_WakeupCfg[searchIndex].CanIfCtrlIndex;

#if(STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
                /* SWS_CANIF_679 */
                if(CANIF_CS_SLEEP != CanIf_ControllerMode[CANIF_CONTROLLER_ID])
                {
                    CANIF_DET_REPORT_ERROR(CANIF_CHECKWAKEUP_APIID, CANIF_E_NOT_SLEEP);
                }
                else
#endif
                {
#if(STD_ON == CANIF_TRCV_WAKEUP_SUPPORT)
                    if(FALSE == CanIf_WakeupCfg[searchIndex].isCtrlWakeupType)
                    {
                        TransceiverId = CanIf_WakeupCfg[searchIndex].CanIfTrcvIndex;
                        canTrcvCheckFctPtr = CanIf_CanTrcv_CheckWakeup[CanIf_GetDrvIdOfTrcv(CANIF_TRCV_ID)];
#if(STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
                        if(NULL_PTR == canTrcvCheckFctPtr)
                        {
                            CANIF_DET_REPORT_ERROR(CANIF_CHECKWAKEUP_APIID, CANIF_E_LINKAPINULL);
                        }
                        else
#endif
                        {
                            ret = canTrcvCheckFctPtr(CanIf_GetTrcvId(CANIF_TRCV_ID));
                        }
                    }
                    else
#endif
                    {
#if(STD_ON == CANIF_CTRL_WAKEUP_SUPPORT)
                        canCheckFctPtr = CanIf_Can_CheckWakeup[CanIf_GetDrvIdOfCtrl(CANIF_CONTROLLER_ID)];
#if(STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
                        if(NULL_PTR == canCheckFctPtr)
                        {
                            CANIF_DET_REPORT_ERROR(CANIF_CHECKWAKEUP_APIID, CANIF_E_LINKAPINULL);
                        }
                        else
#endif
                        {
                            if(CAN_OK == canCheckFctPtr(CanIf_GetCtrlId(CANIF_CONTROLLER_ID)))
                            {
                                ret = E_OK;
                            }
                        }
#endif
                    }

                }
                /* dont break as more than 1 wakesrc may be input */

            }

        }

        if(srcValidFlag == FALSE)/* SWS_CANIF_00398*/
        {
            CANIF_DET_REPORT_ERROR(CANIF_CHECKWAKEUP_APIID, CANIF_E_PARAM_WAKEUPSOURCE);
        }

    }

    return ret;

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_CheckValidation  SWS_CANIF_00178
*
* Description:   This service validation the wakeup event
*
* Inputs:        WakeupSource
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT)/*SWS_CANIF_226 408*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckValidation
(
    EcuM_WakeupSourceType WakeupSource
)
{
    /* */
    uint8 searchIndex = (uint8)0;
    uint8 ControllerId;
    boolean flag = FALSE;
    EcuM_WakeupSourceType retSrc = (EcuM_WakeupSourceType)0;/* all clear */
    Std_ReturnType ret = E_NOT_OK;


    /*SWS_CANIF_00407*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CHECKVALIDATION_APIID, CANIF_E_UNINIT);
    }
    else
    {
        for(searchIndex = (uint8)0; searchIndex < CANIF_USED_WAKRUPSRC_NUM; searchIndex++)
        {
            if((EcuM_WakeupSourceType)0 != ((EcuM_WakeupSourceType)(CanIf_WakeupCfg[searchIndex].Source) & WakeupSource))
            {
                ControllerId = CanIf_WakeupCfg[searchIndex].CanIfCtrlIndex;
                if(TRUE == CanIf_WakeupStatus[CANIF_CONTROLLER_ID])
                {
                    retSrc = WakeupSource;   /*SWS_CANIF_179*/
                }

                /* dont break as more than 1 wakesrc may be input */
                flag = TRUE;
            }
        }


        if(flag != TRUE)/*SWS_CANIF_00404*/
        {
            CANIF_DET_REPORT_ERROR(CANIF_CHECKVALIDATION_APIID, CANIF_E_PARAM_WAKEUPSOURCE);
        }
        else
        {
#if(CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
            if(NULL_PTR != CanIf_DispatchUserValidateWakeupEventName)
#endif
            {
                if((EcuM_WakeupSourceType)0 != retSrc)
                {
                    CANIF_DISPATCH_USERVALIDATEWAKEUPEVENT_NAME;/*SWS_CANIF_179*/
                }
                ret = E_OK;
            }
        }
    }


    /* tbd, if no src is valid, still return E_OK */
    return ret;

}
#endif


#endif/*#if((STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) || (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT))*/


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetTxConfirmationState  SWS_CANIF_00734
*
* Description:   This service reports, if any TX confirmation has been done for the whole CAN
*                controller since the last CAN controller start
*
* Inputs:        WakeupSource
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT)/*SWS_CANIF_00738*/
FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_GetTxConfirmationState
(
    uint8 ControllerId
)
{
    CanIf_NotifStatusType ret = CANIF_NO_NOTIFICATION;


    /*SWS_CANIF_00736 737*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTXCONFSTATE_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETTXCONFSTATE_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else
    {
        ret = CanIf_TxConfStatus[CANIF_CONTROLLER_ID];
    }


    return ret;
}
#endif



#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)/*SWS_CANIF_00771 813*/
#if(CANIF_MAX_TRCV_NUM > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ClearTrcvWufFlag  SWS_CANIF_00760
*
* Description:   This service clear the wakeup flag of trcv
*
* Inputs:        TransceiverId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag
(
    uint8 TransceiverId
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 drvIndex = 0;
    uint8 conIndex = 0;

    /*SWS_CANIF_00769*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CLEARTRCVWAKEUPFLAG_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CLEARTRCVWAKEUPFLAG_APIID, CANIF_E_PARAM_TRCV);
    }
    else
    {
        drvIndex = CanIf_GetDrvIdOfTrcv(TransceiverId);
        conIndex = CanIf_GetTrcvId(TransceiverId);
        if(NULL_PTR == CanIf_CanTrcv_ClearWakeupFlag[CanIf_GetDrvIdOfTrcv(TransceiverId)])
        {
            CANIF_DET_REPORT_ERROR(CANIF_CLEARTRCVWAKEUPFLAG_APIID, CANIF_E_LINKAPINULL);
        }
        else
        {
            /*SWS_CANIF_00766*/
            ret = CanIf_CanTrcv_ClearWakeupFlag[drvIndex](conIndex);
        }

    }

    return ret;


}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_CheckTrcvWakeFlag  SWS_CANIF_00761
*
* Description:   This service check the wakeup flag of trcv
*
* Inputs:        TransceiverId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTrcvWakeFlag
(
    uint8 TransceiverId
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 drvIndex = 0;
    uint8 conIndex = 0;

    /*SWS_CANIF_00770*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CHECKTRCVWAKEUPFLAG_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CHECKTRCVWAKEUPFLAG_APIID, CANIF_E_PARAM_TRCV);
    }
    else
    {
        drvIndex = CanIf_GetDrvIdOfTrcv(TransceiverId);
        conIndex = CanIf_GetTrcvId(TransceiverId);
        if(NULL_PTR == CanIf_CanTrcv_CheckWakeupFlag[CanIf_GetDrvIdOfTrcv(TransceiverId)])
        {
            CANIF_DET_REPORT_ERROR(CANIF_CHECKTRCVWAKEUPFLAG_APIID, CANIF_E_LINKAPINULL);
        }
        else
        {
            /*SWS_CANIF_00765*/
            ret = CanIf_CanTrcv_CheckWakeupFlag[drvIndex](conIndex);
        }

    }

    return ret;
}
#endif
#endif/*#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)*/


#if(STD_ON == CANIF_SET_BAUDRATE_API)/*SWS_CANIF_00871*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_SetBaudrate  SWS_CANIF_00867
*
* Description:   This service change the baudrate
*
* Inputs:        ControllerId, Baudrate
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetBaudrate
(
    uint8 ControllerId,
    const uint16 BaudRateConfigID
)
{
    uint8 drvIndex = (uint8)0;
    uint8 conIndex = ControllerId;
    Std_ReturnType ret = E_NOT_OK;


    /*SWS_CANIF_00869  SWS_CANIF_00870*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETBAUDRATE_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETBAUDRATE_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else
    {
        drvIndex = CanIf_CtrlCfg[CANIF_CONTROLLER_ID].CanDrvIndex;
        conIndex = CanIf_CtrlCfg[CANIF_CONTROLLER_ID].CanCtrlIdRef;

        if(NULL_PTR == CanIf_Can_ChangeBaudrate[drvIndex])
        {
            CANIF_DET_REPORT_ERROR(CANIF_SETBAUDRATE_APIID, CANIF_E_LINKAPINULL);
        }
        else
        {
            /*SWS_CANIF_00868*/
            ret = CanIf_Can_ChangeBaudrate[drvIndex](conIndex, BaudRateConfigID);
        }

    }

    return ret;
}

#endif/*#if(STD_ON == CANIF_SET_BAUDRATE_API)*/


#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_EnableBusMirroring   SWS_CANIF_91005
*
* Description:   Enables or disables mirroring for a CAN controller.
*
* Inputs:        ControllerId,MirroringActive
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_EnableBusMirroring
(
    uint8 ControllerId,
    boolean MirroringActive
)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 MirrorHthCnt;

    /*SWS_CANIF_00911 SWS_CANIF_00912*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_ENABLEBUSMIRRORING_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_ENABLEBUSMIRRORING_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else
    {
        /*SWS_CANIF_00904*/
        if(TRUE == MirroringActive)
        {
#if(CANIF_MAX_HTH_NUM > 0)
            for(MirrorHthCnt = (uint8)0; MirrorHthCnt < (uint8)CANIF_MAX_HTH_NUM; MirrorHthCnt++)
            {
                if(ControllerId == CANIF_HTH_CFG_INFO[MirrorHthCnt].CanIfCtrlIdRef)
                {
                    CanIf_MirrorBackupSts[MirrorHthCnt].CanID = (Can_IdType)0;
                    CanIf_MirrorBackupSts[MirrorHthCnt].length = (uint8)0;
                }
            }
#endif

            /*SWS_CANIF_00904*/
            CanIf_BusMirrorEn[CANIF_CONTROLLER_ID] = TRUE;
        }
        else
        {
            CanIf_BusMirrorEn[CANIF_CONTROLLER_ID] = FALSE;
        }
        ret = E_OK;
    }
    return ret;
}
#endif/*#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)*/


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetControllerErrorState   SWS_CANIF_91001
*
* Description:   This service calls the corresponding CAN Driver service for obtaining the
*                error state of the CAN controller.
*
* Inputs:        ControllerId,ErrorStatePtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerErrorState
(
    uint8 ControllerId,
    P2VAR(Can_ErrorStateType, AUTOMATIC, CANIF_APPL_DATA) ErrorStatePtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    CanIf_CanGetControllerErrorState GetConErrStFctPtr;

    /*SWS_CANIF_00898 SWS_CANIF_00899*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERERRORSTATE_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERERRORSTATE_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else if(NULL_PTR == ErrorStatePtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERERRORSTATE_APIID, CANIF_E_PARAM_POINTER);
    }
    else
    {
        GetConErrStFctPtr = CanIf_Can_GetControllerErrorState[CanIf_GetDrvIdOfCtrl(CANIF_CONTROLLER_ID)];
        if(NULL_PTR == GetConErrStFctPtr)
        {
            CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERERRORSTATE_APIID, CANIF_E_LINKAPINULL);
        }
        else
        {
            ret = GetConErrStFctPtr(ControllerId,ErrorStatePtr);
        }
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetControllerRxErrorCounter  SWS_CANIF_91003
*
* Description:   This service calls the corresponding CAN Driver service for obtaining the
*                Rx error counter of the CAN controller.
*
* Inputs:        ControllerId,RxErrorCounterPtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerRxErrorCounter
(
    uint8 ControllerId,
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) RxErrorCounterPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    CanIf_CanGetControllerRxErrorCounter GetConRxErrCntFctPtr;

    /*SWS_CANIF_00907 SWS_CANIF_00908*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERRXERRORCOUNTER_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERRXERRORCOUNTER_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else if(NULL_PTR == RxErrorCounterPtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERRXERRORCOUNTER_APIID, CANIF_E_PARAM_POINTER);
    }
    else
    {
        GetConRxErrCntFctPtr = CanIf_Can_GetControllerRxErrorCounter[CanIf_GetDrvIdOfCtrl(CANIF_CONTROLLER_ID)];
        if(NULL_PTR == GetConRxErrCntFctPtr)
        {
            CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERRXERRORCOUNTER_APIID, CANIF_E_LINKAPINULL);
        }
        else
        {
            ret = GetConRxErrCntFctPtr(ControllerId,RxErrorCounterPtr);
        }
    }

    return ret;
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetControllerRxErrorCounter  SWS_CANIF_91004
*
* Description:   This service calls the corresponding CAN Driver service for obtaining the
*                Tx error counter of the CAN controller.
*
* Inputs:        ControllerId,TxErrorCounterPtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerTxErrorCounter
(
    uint8 ControllerId,
    P2VAR(uint8, AUTOMATIC, CANIF_APPL_DATA) TxErrorCounterPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    CanIf_CanGetControllerTxErrorCounter GetConTxErrCntFctPtr;

    /*SWS_CANIF_00909 SWS_CANIF_00910*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERTXERRORCOUNTER_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERTXERRORCOUNTER_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else if(NULL_PTR == TxErrorCounterPtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERTXERRORCOUNTER_APIID, CANIF_E_PARAM_POINTER);
    }
    else
    {
        GetConTxErrCntFctPtr = CanIf_Can_GetControllerTxErrorCounter[CanIf_GetDrvIdOfCtrl(CANIF_CONTROLLER_ID)];
        if(NULL_PTR == GetConTxErrCntFctPtr)
        {
            CANIF_DET_REPORT_ERROR(CANIF_GETCONTROLLERTXERRORCOUNTER_APIID, CANIF_E_LINKAPINULL);
        }
        else
        {
            ret = GetConTxErrCntFctPtr(ControllerId,TxErrorCounterPtr);
        }
    }

    return ret;
}


/*******************************************************************************
*   Callback Functions
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_TxConfirmation SWS_CANIF_00007
*
* Description:   This service confirms a previously successfully processed
*                transmission of a CAN TxPDU.
*
* Inputs:        CanTxPduId   L-PDU handle of CAN L-PDU to be transmitted.
*                             This handle specifies the corresponding CAN L-PDU
*                             ID and implicitly the CAN Driver instance as well
*                             as the corresponding CAN controller device.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_TxConfirmation
(
    PduIdType CanTxPduId
)
{
    uint8 ControllerId;
    CanIf_User_TxConfirmationType TxConfFctPtr = NULL_PTR;
    CanIf_PduModeType tempMode;
#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)
    Can_HwHandleType MirrorHthBufferId = CAN_INVALID_HOH;
#endif/*#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)*/

    /*SWS_CANIF_00410 412 413*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TXCONFIRMATION_APIID, CANIF_E_UNINIT);
    }
    else if(CanTxPduId >= CANIF_USED_TXPDU_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TXCONFIRMATION_APIID, CANIF_E_PARAM_LPDU);
    }
    else
    {
#if(CANIF_MAX_TXPDU_NUM > 0)
        ControllerId = CanIf_CtrlIdOfTxPdu(CanTxPduId);
        tempMode = CanIf_PduMode[CANIF_CONTROLLER_ID];

#if(STD_ON == CANIF_PUBLIC_PN_SUPPORT)
        CanIf_PnActive[CANIF_CONTROLLER_ID] = FALSE/*SWS_CANIF_00751*/;
#endif
#if(STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT)
        CanIf_TxSwFifo_TxConfirmation(CanTxPduId);
#endif
        /* only process when controller is start and pdumode is txConfEnabled SWS_CANIF_00073 */
        if((CANIF_CS_STARTED == CanIf_ControllerMode[CANIF_CONTROLLER_ID])
                && ((CANIF_ONLINE == tempMode) || (CANIF_TX_OFFLINE_ACTIVE == tempMode)))/*SWS_CANIF_00489*/
        {

            /*SWS_CANIF_391 472*/
#if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)
#if(CANIF_MAX_TXNOTIFY_NUM > 0)
            if(TRUE == CANIF_TXPDU_CFG_INFO[CanTxPduId].TxPduReadNotifyStatus)
            {
                CanIf_TxNotifStatus[CANIF_TXPDU_CFG_INFO[CanTxPduId].TxNotifyIndex] = CANIF_TX_RX_NOTIFICATION;
            }
#endif
#endif

#if(STD_ON == CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT)  /*SWS_CANIF_740*/
            CanIf_TxConfStatus[CANIF_CONTROLLER_ID] = CANIF_TX_RX_NOTIFICATION;
#endif

#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)  /*SWS_CANIF_00905*/
            if((TRUE == CanIf_BusMirrorEn[CANIF_CONTROLLER_ID])
                && (CANIF_TX_OFFLINE_ACTIVE != tempMode))
            {
#if((STD_OFF == CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT) && (STD_OFF == CANIF_HOH_OPTIMIZE_SUPPORT))
                MirrorHthBufferId = (uint8)CanIf_MirrorGetHthNum(CanTxPduId);
#else
                MirrorHthBufferId = (CanIf_HthOfTxPdu(CanTxPduId) - (Can_HwHandleType)CANIF_MAX_HRH_NUM);
#endif
                if((uint8)0 != CanIf_MirrorBackupSts[MirrorHthBufferId].length)
                {
                    Mirror_ReportCanFrame(CANIF_CONTROLLER_ID,
                        CanIf_MirrorBackupSts[MirrorHthBufferId].CanID,
                        CanIf_MirrorBackupSts[MirrorHthBufferId].length,
                        &(CanIf_MirrorBackupSts[MirrorHthBufferId].MirrorHthBuffer[0]));
                }
            }
#endif
            /* SWS_CANIF_383  SWS_CANIF_00414 notify uplayer*/
            /*not report det error here if txconf null */
            TxConfFctPtr = CanIf_TxConfirmationName[CANIF_TXPDU_CFG_INFO[CanTxPduId].TxConfirmation];
            if(NULL_PTR != TxConfFctPtr)
            {
                TxConfFctPtr(CANIF_TXPDU_CFG_INFO[CanTxPduId].PduRef,E_OK);
                CanIf_TxWaitConfirmationFlag[CanTxPduId] = FALSE;
            }

#if((STD_ON == CANIF_PUBLIC_TX_BUFFERING) && (CANIF_MAX_TXBUF_NUM > 0) && (CANIF_MAX_HTH_NUM > 0))
            /*SWS_CANIF_386 SWS_CANIF_668: CanIf will check the buffer of this hth, if there is pdu pending
              new transmit will be request
            */
            SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_4();
            if((FALSE == CanIf_HthTypeOfTxPdu(CanTxPduId)) && (CanIf_SizeOfTxBuf(CanTxPduId) > (PduIdType)0))
            {
                CanIf_TxConfirmationTransmit(CanTxPduId);
            }
            SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_4();
#endif/*#if((STD_ON == CANIF_PUBLIC_TX_BUFFERING) && (CANIF_MAX_TXBUF_NUM > 0) && (CANIF_MAX_HTH_NUM > 0))*/

        }
#endif/*#if(CANIF_MAX_TXPDU_NUM > 0)*/

    }
}

#if((STD_ON == CANIF_PUBLIC_TX_BUFFERING) && (CANIF_MAX_TXBUF_NUM > 0) && (CANIF_MAX_HTH_NUM > 0))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_TxConfirmationTransmit SWS_CANIF_00007
*
* Description:   This service confirms a previously successfully processed
*                transmission of a CAN TxPDU.
*
* Inputs:        CanTxPduId   L-PDU handle of CAN L-PDU to be transmitted.
*                             This handle specifies the corresponding CAN L-PDU
*                             ID and implicitly the CAN Driver instance as well
*                             as the corresponding CAN controller device.
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANIF_CODE) CanIf_TxConfirmationTransmit
(
    PduIdType CanTxPduId
)
{
    PduIdType handle;
    Can_HwHandleType hth;
    CanIf_CanWriteType canWriteFctPtr;
#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)
    uint8 MirrorControllerId = (uint8)0;
    Can_HwHandleType MirrorHthBufferId = (CanIf_HthOfTxPdu(CanTxPduId) - (Can_HwHandleType)CANIF_MAX_HRH_NUM);
#endif/*#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)*/

    hth = CANIF_TXPDU_CFG_INFO[CanTxPduId].HthRef;
    /* buffered pdu must have same driver index and hth*/
    canWriteFctPtr = CanIf_Can_Write[CanIf_GetDrvIdOfTxPdu(CanTxPduId)];

    if((PduIdType)0 != CanIf_TxBufferFillCount[hth])
    {
        /* search for buffering tx request
           SWS_CANIF_070:the pdu will be ordered by its canid in config time
        */
        for(handle = CanIf_FirstIndexOfTxBuf(CanTxPduId);
                handle < (CanIf_SizeOfTxBuf(CanTxPduId) + CanIf_FirstIndexOfTxBuf(CanTxPduId));
                handle++)
        {
            if(TRUE == CanIf_TxBufActiveFlag[handle])
            {
                if(NULL_PTR == canWriteFctPtr)
                {
                    CANIF_DET_REPORT_ERROR(CANIF_TXCONFIRMATION_APIID, CANIF_E_LINKAPINULL);
                }
                else
                {
                    if(CAN_OK == canWriteFctPtr(CANIF_HTH_CFG_INFO[hth].HthIdSymRef, &CanIf_TxBufPdu[handle]))
                    {
#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)
#if(CANIF_MAX_CONTROLLER_NUM > 1)
                        MirrorControllerId = CanIf_CtrlIdOfTxPdu(CanTxPduId);
#endif
                        if(TRUE == CanIf_BusMirrorEn[MirrorControllerId])
                        {
                            MirrorHthBufferId = (CanIf_HthOfTxPdu(CanTxPduId) - (Can_HwHandleType)CANIF_MAX_HRH_NUM);
                            Bsw_MemCpy(CanIf_MirrorBackupSts[MirrorHthBufferId].MirrorHthBuffer,
                                CanIf_TxBufPdu[handle].sdu, (uint32)CanIf_TxBufPdu[handle].length);
                            CanIf_MirrorBackupSts[MirrorHthBufferId].CanID = CanIf_TxBufPdu[handle].id;
                            CanIf_MirrorBackupSts[MirrorHthBufferId].length = CanIf_TxBufPdu[handle].length;
                        }
#endif/*(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)*/
                        /*SWS_CANIF_183: txOK, the pengding pdu is removed*/
                        CanIf_TxBufActiveFlag[handle] = FALSE;
                        CanIf_TxBufferFillCount[hth]--;

                        CanIf_TxWaitConfirmationFlag[handle] = TRUE;
                    }
                }
                break;
            }
        }
    }
}
#endif


#if(CANIF_MAX_RXPDU_NUM > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetRxPduId
*
* Description:   This service implement sw filter
*
* Inputs:        ControllerId,Hrh,CanId
*
* Outputs:       PduIdType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(CANIF_FILTER_TYPE_DICH == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)

STATIC FUNC(boolean, CANIF_CODE) CanIf_CheckSingleId
(
    volatile PduIdType  PduIndex,
    volatile Can_IdType CanId
)
{
    boolean ret = FALSE;
    volatile Can_IdType mask;
    volatile Can_IdType tempCanId;



#if(STD_ON == CANIF_HRH_RANGE_FILTER_SUPPORT)
    if(NULL_PTR != CANIF_RXPDU_CFG_INFO[PduIndex].IdRange)
    {
        tempCanId = CanId;

#if(STD_ON == CANIF_PRIVATE_CANFD_SUPPORT)
        /*
            EXTENDED_CAN and STANDARD_CAN type support both fd or non fd
            in these 2 type, the range id is generated without fd bit
            so the canid need to remove fd bit before compare with range id
        */
        if((EXTENDED_CAN == CANIF_RXPDU_CFG_INFO[PduIndex].CanIdType)
                || (STANDARD_CAN == CANIF_RXPDU_CFG_INFO[PduIndex].CanIdType))
        {
            tempCanId = (CanId & CAN_CANFD_INV_MASK);/*clear Fd Bit*/
        }
#endif

        if((tempCanId >= CANIF_RXPDU_CFG_INFO[PduIndex].IdRange->LowerCanId)
                && (tempCanId <= CANIF_RXPDU_CFG_INFO[PduIndex].IdRange->UpperCanId))
        {
            ret = TRUE;
        }

    }
    else
#endif
    {
        mask = CANIF_RXPDU_CFG_INFO[PduIndex].CanIdMask;
        if((CanId & mask) == (CANIF_RXPDU_CFG_INFO[PduIndex].CanId & mask))
        {
            ret = TRUE;
        }
    }
    return ret;
}


STATIC FUNC(PduIdType, CANIF_CODE) CanIf_GetRxPduId
(
    uint8 ControllerId,
    Can_HwHandleType Hrh,
    Can_IdType CanId
)
{

    PduIdType MsgIndex = COMSTACK_INVALID_PDUID;
    PduIdType first = 0;
    PduIdType mid = 0;
    PduIdType last = 0;
    Can_IdType tempCanId = 0;
    Can_IdType tempCanId1 = 0;
    

    boolean cflag = FALSE;
    PduIdType  PduIndexResult = COMSTACK_INVALID_PDUID;
    volatile PduIdType tmpPduId = 0;

    if(CANIF_HRH_CFG_INFO[Hrh].pduNumInHrh > (PduIdType)0)
    {
        /* CanId software search alg */
        first = (PduIdType)0;
        last = CANIF_HRH_CFG_INFO[Hrh].pduNumInHrh - (PduIdType)1;

        while(first <= last)
        {
            mid = (first + last) >> ((PduIdType)1);
            tmpPduId =CANIF_HRH_CFG_INFO[Hrh].pduList[mid];
            
            cflag = CanIf_CheckSingleId(tmpPduId, CanId);
            if((cflag == TRUE) && (Hrh == CANIF_RXPDU_CFG_INFO[tmpPduId].HrhRef))
            {
                PduIndexResult = tmpPduId;
                break;
            }
            else
            {
                tempCanId = CANIF_RXPDU_CFG_INFO[tmpPduId].CanId;
                tempCanId = tempCanId & CAN_CANID_MASK; /*clear non value bit to do compare next*/
                tempCanId1 = CanId & CAN_CANID_MASK;

                if(tempCanId > tempCanId1)
                {
                    if(mid <= 0)
                    {
                        break;
                    }
                    else
                    {
                        last = mid - (PduIdType)1;
                    }
                }
                else 
                {
                    if(mid >= (CANIF_HRH_CFG_INFO[Hrh].pduNumInHrh - (PduIdType)1))
                    {
                        break;
                    }
                    else
                    {
                        first = mid + (PduIdType)1;
                    }
                }

            }
        }
    }
    return PduIndexResult;
}

#else

STATIC FUNC(PduIdType, CANIF_CODE) CanIf_GetRxPduId
(
    uint8 ControllerId,
    Can_HwHandleType Hrh,
    Can_IdType CanId
)
{
    PduIdType  PduIndex;
    PduIdType  PduIndexResult = COMSTACK_INVALID_PDUID;
    Can_IdType mask;
    Can_IdType tempCanId;


    /*******************************************************************************
    * PRQA S 0771  MISRA-C:2004 Rule 14.6
    * More than one break statement is being used to terminate an iteration statement.
    * 2 kind of filter path both need to break.
    * This part of code is verified manually and has no impact.
    *******************************************************************************/


#if(CANIF_FILTER_TYPE_INDEX == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
    for(PduIndex = CANIF_HRH_CFG_INFO[Hrh].FirstRxPduIdInHrh;
        PduIndex != COMSTACK_INVALID_PDUID;
        PduIndex = CANIF_RXPDU_CFG_INFO[PduIndex].NextPduId)
    {
        if(Hrh == CANIF_RXPDU_CFG_INFO[PduIndex].HrhRef)
        {
#endif
#if(CANIF_FILTER_TYPE_LINEAR == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
    for(PduIndex = 0; PduIndex < CANIF_USED_RXPDU_NUM; PduIndex++)
    {
        if(Hrh == CANIF_RXPDU_CFG_INFO[PduIndex].HrhRef)
        {
#endif
#if(CANIF_FILTER_TYPE_TABLE == CANIF_PRIVATE_SOFTWARE_FILTER_TYPE)
    if(CanId <= CANIF_MAX_CANID)
    {
        if(NULL_PTR != CANIF_RXPDUTABLE_CFG_INFO[CanId])
        {
            PduIndex = CANIF_RXPDUTABLE_CFG_INFO[CanId][ControllerId];
#endif
#if(STD_ON == CANIF_HRH_RANGE_FILTER_SUPPORT)
            if(NULL_PTR != CANIF_RXPDU_CFG_INFO[PduIndex].IdRange)
            {
                tempCanId = CanId;

#if(STD_ON == CANIF_PRIVATE_CANFD_SUPPORT)
                /*
                    EXTENDED_CAN and STANDARD_CAN type support both fd or non fd
                    in these 2 type, the range id is generated without fd bit
                    so the canid need to remove fd bit before compare with range id
                */
                if((EXTENDED_CAN == CANIF_RXPDU_CFG_INFO[PduIndex].CanIdType)
                        || (STANDARD_CAN == CANIF_RXPDU_CFG_INFO[PduIndex].CanIdType))
                {
                    tempCanId = (CanId & CAN_CANFD_INV_MASK);/*clear Fd Bit*/
                }
#endif

                if((tempCanId >= CANIF_RXPDU_CFG_INFO[PduIndex].IdRange->LowerCanId)
                        && (tempCanId <= CANIF_RXPDU_CFG_INFO[PduIndex].IdRange->UpperCanId))
                {
                    PduIndexResult = PduIndex;
                    break;
                }

            }
            else
#endif
            {
                mask = CANIF_RXPDU_CFG_INFO[PduIndex].CanIdMask;
                if((CanId & mask) == (CANIF_RXPDU_CFG_INFO[PduIndex].CanId & mask))
                {
                    PduIndexResult = PduIndex;
                    break;
                }
            }
        }
    }

    return PduIndexResult;

}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetInternalHrh
*
* Description:   This service remap the hrh from can to canif's internal hrh
*
* Inputs:        Hrh
*
* Outputs:       PduIdType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if((STD_OFF == CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT) && (STD_OFF == CANIF_HOH_OPTIMIZE_SUPPORT))
STATIC FUNC(Can_HwHandleType, CANIF_CODE) CanIf_GetInternalHrh
(
    Can_HwHandleType Hrh
)
{
    Can_HwHandleType HrhResult = CAN_INVALID_HOH;
    Can_HwHandleType i;

    for(i = (Can_HwHandleType)0; i < CANIF_USED_HRH_NUM; i++)
    {
        if(CANIF_HRH_CFG_INFO[i].HrhIdSymRef == Hrh)
        {
            HrhResult = i;
            break;
        }
    }

    return HrhResult;
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_GetInternalHrh
*
* Description:   This service remap the hrh from can to canif's internal hrh
*
* Inputs:        Hrh
*
* Outputs:       PduIdType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == CANIF_PRIVATE_DLC_CHECK)
STATIC FUNC(boolean, CANIF_CODE) CanIf_DlcCheck
(
    P2VAR(uint8, AUTOMATIC, AUTOMATIC)  CanDlc,
    const PduIdType RxPduId
)
{
    boolean dlcValid = TRUE;

    if(TRUE == CANIF_RXPDU_CFG_INFO[RxPduId].needDlcCheck)
    {
#if(CANIF_DLC_CHECK_TYPE == CANIF_DLC_CHECK_AUTOSAR)
        if(*CanDlc < CANIF_RXPDU_CFG_INFO[RxPduId].Length)
        {
            dlcValid = FALSE;
        }
        else
        {
            /* SWS_CANIF_00297 set dlc to config dlc
            when the reveived dlc is bigger than config dlc*/
            *CanDlc = CANIF_RXPDU_CFG_INFO[RxPduId].Length;
        }
#else
        dlcValid = CanIf_DlcCheckCallout(RxPduId, CanDlc, CANIF_RXPDU_CFG_INFO[RxPduId].Length);
#endif

    }
    return dlcValid;
}
#endif
#endif/*#if(CANIF_MAX_RXPDU_NUM > 0)*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_RxIndication SWS_CANIF_00006
*
* Description:   This service indicates a successful reception of a received CAN
*                Rx L-PDU to the CanIf after passing all filters and validation
*                checks.
*
* Inputs:        Hrh         ID of the corresponding Hardware Object
*                            Range: 0..(total number of HRH -1)
*                CanId       Standard/Extended CAN ID of CAN L-PDU that has been
*                            successfully received
*                CanDlc      Data Length Code (length of CAN L-PDU payload)
*                CanSduPtr   Pointer to received L-SDU (payload)
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_RxIndication
(
    P2CONST(Can_HwType, AUTOMATIC, CANIF_APPL_DATA) Mailbox,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
)
{
    Can_HwHandleType internalHrh;
    uint8 ControllerId;
    uint8 tempMode;
    PduIdType canIfRxPduId = COMSTACK_INVALID_PDUID;
    Can_IdType CanId;
    uint8 maxDlc = CANIF_CAN_MAX_DLC;
    uint8 CanDlc = (uint8)0;

    /*******************************************************************************
    * PRQA S 0715  MISRA-C:2004 Rule 1.1
    * Nesting of control structures (statements) exceeds 15 - program does not conform
    * strictly to ISO:C90. Sequence of rx process need these  statements.
    * This part of code is verified manually and has no impact.
    *******************************************************************************/

    /*SWS_CANIF_00419 421 422 */
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_RXINDICATION_APIID, CANIF_E_UNINIT);
    }
    else if(NULL_PTR == Mailbox)
    {
        CANIF_DET_REPORT_ERROR(CANIF_RXINDICATION_APIID, CANIF_E_PARAM_POINTER);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_RXINDICATION_APIID, CANIF_E_PARAM_POINTER);
    }
    else if(NULL_PTR == PduInfoPtr->SduDataPtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_RXINDICATION_APIID, CANIF_E_PARAM_POINTER);
    }
    else
    {
#if(CANIF_MAX_RXPDU_NUM > 0)
        /*SWS_CANIF_00417 not implement: CanId is not checked here */
        CanId = Mailbox->CanId;
        CanDlc = (uint8)PduInfoPtr->SduLength;

#if(STD_ON == CANIF_PRIVATE_CANFD_SUPPORT)
        /*max Dlc Check*/
        if(CAN_CANFD_MASK == (Can_IdType)(CanId & CAN_CANFD_MASK))
        {
            maxDlc = CANIF_CANFD_MAX_DLC;
        }
#endif

        if(CanDlc > maxDlc)
        {
            CANIF_DET_REPORT_ERROR(CANIF_RXINDICATION_APIID, CANIF_E_INVALID_DLC);
        }
        else
        {
            internalHrh = Mailbox->Hoh;
#if(STD_OFF == CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT)
            /* when mutidrv is off, candrv will directly call this rx cbk funtion
               so the hrh will be serach and check here
               when mutidrv is on, this will be done in generate rx cbk functions
            */
#if(STD_OFF == CANIF_HOH_OPTIMIZE_SUPPORT)
            /* HRH check */
            internalHrh = CanIf_GetInternalHrh(Mailbox->Hoh);
            /* when HOH_OPTIMIZE, hrh can be internalHrh directly */
#endif
#endif
            if(internalHrh >= CANIF_USED_HRH_NUM)/*SWS_CANIF_00416*/
            {
                CANIF_DET_REPORT_ERROR(CANIF_RXINDICATION_APIID, CANIF_E_PARAM_HOH);
            }
            else
            {
                ControllerId = CANIF_HRH_CFG_INFO[internalHrh].CanIfCtrlIdRef;
/*adjust for Nm first message*/
#if((STD_ON == CANIF_PUBLIC_PN_SUPPORT) && (STD_ON == CANIF_PRIVATE_RX_PN_SUPPORT))
                /*SWS_CANIF_00896*/
                CanIf_PnActive[CANIF_CONTROLLER_ID] = FALSE;
#endif
                tempMode = (uint8)CanIf_PduMode[CANIF_CONTROLLER_ID];

                if((CANIF_CS_STARTED == CanIf_ControllerMode[CANIF_CONTROLLER_ID])
                        && (tempMode > (uint8)CANIF_TX_OFFLINE_ACTIVE)) /*SWS_CANIF_00073 489*/
                {
                    /* SWS_CANIF_415 417 389 645 646 030
                    software filter process ,dont need to check fullcan feather */
                    canIfRxPduId = CanIf_GetRxPduId(CANIF_CONTROLLER_ID,internalHrh, CanId);
                    if(COMSTACK_INVALID_PDUID == canIfRxPduId)
                    {
                        /*CANIF_DET_REPORT_ERROR(CANIF_RXINDICATION_APIID, CANIF_E_PARAM_CANID);
                          should not report error, as CanId not pass software filter is normally
                        */
                    }
#if(STD_ON == CANIF_PRIVATE_DLC_CHECK)/*SWS_CANIF_418 390*/
                    else if(FALSE == CanIf_DlcCheck(&CanDlc, canIfRxPduId))/*SWS_CANIF_168 026 829 830*/
                    {
                        CANIF_DET_REPORT_ERROR(CANIF_RXINDICATION_APIID, CANIF_E_INVALID_DLC);
                    }
#endif
                    else
                    {
                        CanIf_RxIndicationInternal(PduInfoPtr, CanId, canIfRxPduId, CANIF_CONTROLLER_ID);
                    }
                }
            }
        }
#endif/*#if(CANIF_MAX_RXPDU_NUM > 0)*/
    }
}

#if((STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) || (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT))
#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_WakeupStatusCheck
*
* Description:   The check of whether to wake up.
*
* Inputs:        PduInfoPtr    Pointer to received PDU
*                CanId         Standard/Extended CAN ID of CAN L-PDU that has been
*                              successfully received
*                canIfRxPduId  Id of received PDU
*                ControllerId  Id of controller
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, CANIF_CODE) CanIf_WakeupStatusCheck
(
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr,
    Can_IdType CanId,
    PduIdType canIfRxPduId,
    uint8 ControllerId
)
{
    boolean WakeupStatus = CanIf_WakeupStatus[CANIF_CONTROLLER_ID];
/*SWS_CANIF_286 when validByNm is true, set wakeup true only when rx nm msg*/
#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM)
    if(CANIF_NM_RX_CBK_HANDLE == CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxIndication)
    {
        WakeupStatus = TRUE;
    }
#endif
#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_PNNM)
    if(CANIF_NM_RX_CBK_HANDLE == CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxIndication)
    {
        if(FALSE == WakeupStatus)
        {
            /*If there is no associated NmChannel, 
            it is considered that receiving an NM message will wake up. If there is an associated NmChannel, 
            it will check whether the received data contains a valid PN.*/
            if(COMSTACK_INVALID_NETWORK_HANDLE == CanIf_GetNmChannel(CANIF_CONTROLLER_ID))
            {
                WakeupStatus = TRUE;
            }
            else
            {
                WakeupStatus |= Nm_CheckIfContainsValidPN(CanIf_GetNmChannel(CANIF_CONTROLLER_ID), PduInfoPtr);
            }
        }
    }
#endif
#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_OSEKNM)
    if(CANIF_OSEKNM_RX_CBK_HANDLE == CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxIndication)
    {
        WakeupStatus = TRUE;
    }
#endif
#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_CALLOUT)
    if(TRUE == CanIf_WakeUpCheck_Callout(PduInfoPtr, CanId, canIfRxPduId, ControllerId))
    {
        WakeupStatus = TRUE;
    }
#endif
    return WakeupStatus;
}
#endif/*#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT)*/
#endif/*#if((STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) || (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT))*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_RxIndicationInternal SWS_CANIF_00006
*
* Description:   This service indicates a successful reception of a received CAN
*                Rx L-PDU to the CanIf after passing all filters and validation
*                checks.
*
* Inputs:        Hrh         ID of the corresponding Hardware Object
*                            Range: 0..(total number of HRH -1)
*                CanId       Standard/Extended CAN ID of CAN L-PDU that has been
*                            successfully received
*                CanDlc      Data Length Code (length of CAN L-PDU payload)
*                CanSduPtr   Pointer to received L-SDU (payload)
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANIF_CODE) CanIf_RxIndicationInternal
(
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr,
    Can_IdType CanId,
    PduIdType canIfRxPduId,
    uint8 ControllerId
)
{
#if(STD_ON == CANIF_METADATA_SUPPORT)
    uint8 MetaDataItemPtr;
    Ecuc_CanIdType MetadataCanId;
#endif
    uint8 CanDlc = (uint8)0;
    CanIf_User_RxIndicationType RxIndFctPtr = NULL_PTR;
    PduInfoType tempPduInfo;

    CanDlc = (uint8)PduInfoPtr->SduLength;
    tempPduInfo.SduDataPtr = PduInfoPtr->SduDataPtr;

#if(STD_ON == CANIF_METADATA_SUPPORT)
    tempPduInfo.MetaDataPtr = NULL_PTR;
    if(E_OK == Ecuc_CheckMetaDataSupport(CANIF_RXPDU_CFG_INFO[canIfRxPduId].GlobalPduId, ECUC_ENUM_CAN_ID))
    {
        /* SWS_CANIF_00847 SWS_CANIF_00848 */
        MetadataCanId = (Ecuc_CanIdType)CanId;
        /*PRQA S 0314 ++*/
        /*Because the input parameter of Ecuc_SetMetaData is void*.*/
        (void)Ecuc_SetMetaData(CANIF_RXPDU_CFG_INFO[canIfRxPduId].GlobalPduId, ECUC_ENUM_CAN_ID, (void*)&MetadataCanId);
        /*PRQA S 0314 --*/
        (void)Ecuc_GetMetaDataPtr(CANIF_RXPDU_CFG_INFO[canIfRxPduId].GlobalPduId, &MetaDataItemPtr);
        tempPduInfo.MetaDataPtr = &MetaDataItemPtr;
    }
#endif
    /* wakeup is only valid when correct pdu is received */
#if((STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) || (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT))
#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT)
    CanIf_WakeupStatus[CANIF_CONTROLLER_ID] = CanIf_WakeupStatusCheck(PduInfoPtr, CanId, canIfRxPduId, ControllerId);
#endif/*#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT)*/
#endif/*#if((STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) || (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT))*/

    /* first copy data and notify to buf, then call out to uplayyer
       as uplayyer may getdata in callout
    */
#if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
#if(CANIF_MAX_RXNOTIFY_NUM > 0)
    /*SWS_CANIF_392 473*/
    if(TRUE == CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxPduReadNotifyStatus)
    {
        CanIf_RxNotifStatus[CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxNotifyIndex] = CANIF_TX_RX_NOTIFICATION;
    }
#endif
#endif

#if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)/*SWS_CANIF_198*/
#if(CANIF_MAX_RXBUF_NUM > 0)
    /*SWS_CANIF_297 why copy config dlc here? */
    if(TRUE == CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxPduReadData)
    {
        SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_7();/*SWS_CANIF_199*/
        Bsw_MemCpy(CANIF_RXPDU_CFG_INFO[canIfRxPduId].dataBuf,
                   tempPduInfo.SduDataPtr, (uint32)CanDlc);
        CanIf_RxBufferSduLength[CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxBufIndex] = CanDlc;
        SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_7();
    }
#endif
#endif
#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)  /*SWS_CANIF_00906*/
    if(TRUE == CanIf_BusMirrorEn[CANIF_CONTROLLER_ID])
    {
        Mirror_ReportCanFrame(ControllerId, CanId, (uint8)PduInfoPtr->SduLength, PduInfoPtr->SduDataPtr);
    }
#endif
    tempPduInfo.SduLength = CanDlc;/* dlc may change to config dlc.*/
    /*SWS_CANIF_056 135*/
#if(STD_ON == CANIF_OSEKNM_SUPPORT)
    if(CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxIndication == 0xFF)
    {
        OsekNm_RxIndication(CANIF_RXPDU_CFG_INFO[canIfRxPduId].PduRef, \
                            ((Mailbox->CanId)&CAN_CANFD_INV_MASK), \
                            &tempPduInfo);
    }
    else
#endif
    {
        RxIndFctPtr = CanIf_RxIndicationName[CANIF_RXPDU_CFG_INFO[canIfRxPduId].RxIndication];
        if(NULL_PTR != RxIndFctPtr)
        {
            /*SWS_CANIF_423 SWS_CANIF_00415*/
            RxIndFctPtr(CANIF_RXPDU_CFG_INFO[canIfRxPduId].PduRef, &tempPduInfo);
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ControllerBusOff  SWS_CANIF_00218
*
* Description:   This service indicates a Controller BusOff event referring to
*                the corresponding CAN Controller.
*
* Inputs:        Controller   CAN controller, where a BusOff occured
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_ControllerBusOff
(
    uint8 ControllerId
)
{

    /* SWS_CANIF_00429 431 432*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CONTROLLERBUSOFF_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CONTROLLERBUSOFF_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else
    {
        /*SWS_CANIF_00739*/
        CanIf_TxConfirmationFail(CANIF_CONTROLLER_ID);
#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)/*SWS_CANIF_485*/
        CanIf_ClearTransmitBuffer(CANIF_CONTROLLER_ID);
#endif
#if(STD_ON == CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT)
        /*SWS_CANIF_739*/
        CanIf_TxConfStatus[CANIF_CONTROLLER_ID] = CANIF_NO_NOTIFICATION;
#endif
        /*SWS_CANIF_298 488 866*/
        CanIf_ControllerMode[CANIF_CONTROLLER_ID] = CANIF_CS_STOPPED;
        CanIf_PduMode[CANIF_CONTROLLER_ID] = CANIF_TX_OFFLINE;

        /*******************************************************************
        * PRQA S 3138   MISRA-C:2004 Rule 14.3
        * PRQA S 3141
        * If not configed by user,CANIF_USERCTRLBUSOFF_FUN is Null.
        * This part of code is verified manually and has no impact.
        *******************************************************************/
        /* Call uplayyer handle */

#if(CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
        if(NULL_PTR != CanIf_DispatchUserCtrlModeIndicationName)
#endif
        {
            CANIF_DISPATCH_USERCTRLBUSOFF_NAME; /*SWS_CANIF_724*/
        }

    }
}


#if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)/* SWS_CANIF_00754 808 812*/
#if(CANIF_MAX_TRCV_NUM > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ConfirmPnAvailability  SWS_CANIF_00815
*
* Description:   This service indicates that the transceiver is running in PN communication mode.
*
* Inputs:        Transceiver
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability
(
    uint8 TransceiverId
)
{
    /* SWS_CANIF_00816 817 818 */
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CONFPNACTIVE_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CONFPNACTIVE_APIID, CANIF_E_PARAM_TRCV);
    }
    else
    {
#if(CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
        if(NULL_PTR != CanIfDispatchUserConfirmPnAvailabilityName)
#endif
        {
            /*SWS_CANIF_00753*/
            CANIF_DISPATCH_USERCONFIRMPNAVAILABILITY_NAME;
        }
    }

}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ClearTrcvWufFlagIndication  SWS_CANIF_00762
*
* Description:   This service indicates that the transceiver has cleared the WufFlag.
*
* Inputs:        Transceiver
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication
(
    uint8 TransceiverId
)
{
    /* SWS_CANIF_00806 807 805*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CLEARTRCVWUFFIND_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CLEARTRCVWUFFIND_APIID, CANIF_E_PARAM_TRCV);
    }
    else
    {
#if(CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
        if(NULL_PTR != CanIfDispatchUserClearTrcvWufFlagIndicationName)
#endif
        {
            CANIF_DISPATCH_USERCLEARTRCVWUFFLAGINDICATION_NAME;/*SWS_CANIF_00757*/
        }
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_CheckTrcvWakeFlagIndication  SWS_CANIF_00763
*
* Description:   This service indicates the reason for the wake up that the CAN
*                transceiver has detected.
*
* Inputs:        Transceiver
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication
(
    uint8 TransceiverId
)
{
    /* SWS_CANIF_00810 811 */
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CHECKTRCVWUFFIND_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CHECKTRCVWUFFIND_APIID, CANIF_E_PARAM_TRCV);
    }
    else
    {
#if(CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
        if(NULL_PTR != CanIfDispatchUserCheckTrcvWakeFlagIndicationName)
#endif
        {
            /*SWS_CANIF_00759*/
            CANIF_DISPATCH_USERCHECKTRCVWAKEFLAGINDICATION_NAME;
        }
    }
}
#endif/*#if(CANIF_MAX_TRCV_NUM > 0)*/
#endif/*#if(CANIF_PUBLIC_PN_SUPPORT == STD_ON)*/


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ControllerModeIndication  SWS_CANIF_00699]
*
* Description:   This service indicates a Controller state transition event
*                referring to the corresponding CAN Controller.
*
* Inputs:        ControllerId:CAN controller, which state has been transitioned.
*                ControllerMode:  Mode to which the CAN controller transitioned
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_ControllerModeIndication
(
    uint8 ControllerId,
    CanIf_ControllerModeType ControllerMode
)
{
    /* SWS_CANIF_00700 702 703 */
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CONTROLLERMODEINDICATION_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CONTROLLERMODEINDICATION_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else if((ControllerMode != CANIF_CS_STARTED)
            && (ControllerMode != CANIF_CS_SLEEP)
            && (ControllerMode != CANIF_CS_STOPPED))
    {
        CANIF_DET_REPORT_ERROR(CANIF_CONTROLLERMODEINDICATION_APIID, CANIF_E_PARAM_CTRLMODE);
    }
    else if((ControllerMode == CANIF_CS_STARTED)
            && (CANIF_CS_SLEEP == CanIf_ControllerMode[CANIF_CONTROLLER_ID]))
    {
        /* not allow start <-> sleep */
        CANIF_DET_REPORT_ERROR(CANIF_CONTROLLERMODEINDICATION_APIID, CANIF_E_PARAM_CTRLMODE);
    }
    else if((ControllerMode == CANIF_CS_SLEEP)
            && (CANIF_CS_STARTED == CanIf_ControllerMode[CANIF_CONTROLLER_ID]))
    {
        /* not allow start <-> sleep */
        CANIF_DET_REPORT_ERROR(CANIF_CONTROLLERMODEINDICATION_APIID, CANIF_E_PARAM_CTRLMODE);
    }
    else
    {
        /*SWS_CANIF_713 714 715 CANIF716 CANIF717 CANIF718 CANIF719*/
        CanIf_ControllerMode[CANIF_CONTROLLER_ID] = ControllerMode;
        if(CANIF_CS_STOPPED == ControllerMode)
        {
            CanIf_TxConfirmationFail(CANIF_CONTROLLER_ID);
            /* clear tx buf SWS_CANIF_485*/
#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
            CanIf_ClearTransmitBuffer(CANIF_CONTROLLER_ID);
#endif
#if(STD_ON == CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT)
            CanIf_TxConfStatus[CANIF_CONTROLLER_ID] = CANIF_NO_NOTIFICATION;
#endif

            /* no need tp clear TxRxNotifStatus, since if there is TxRxNotify active,
               it should be keeped until uplayyer read it
            */

            /* PduMode no need to change */
        }

#if((STD_ON == CANIF_TRCV_WAKEUP_SUPPORT) || (STD_ON == CANIF_CTRL_WAKEUP_SUPPORT))
#if(STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALIDATION_SUPPORT)
        if(CANIF_CS_SLEEP == ControllerMode)
        {
            CanIf_WakeupStatus[CANIF_CONTROLLER_ID] = FALSE;/*SWS_CANIF_756*/
        }
#endif
#endif

        /* Call uplayyer handle SWS_CANIF_711*/
#if(CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
        if(NULL_PTR != CanIf_DispatchUserCtrlModeIndicationName)
#endif
        {
            CANIF_DISPATCH_USERCTRLMODEINDICATION_NAME;
        }
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_TrcvModeIndication  SWS_CANIF_00764
*
* Description:   This service indicates a transceive sition re r state tran ferring
*                to the corresponding CAN transceiver.
*
* Inputs:        Transceiver,TransceiverMode
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(CANIF_MAX_TRCV_NUM > 0) /*SWS_CANIF_00730*/
FUNC(void, CANIF_CODE) CanIf_TrcvModeIndication
(
    uint8 TransceiverId,
    CanTrcv_TrcvModeType TransceiverMode
)
{
    /* CSWS_CANIF_00706 708 709 */
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRCVMODEIND_APIID, CANIF_E_UNINIT);
    }
    else if(TransceiverId >= CANIF_USED_TRCV_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRCVMODEIND_APIID, CANIF_E_PARAM_TRCV);
    }
    else
    {
        /*SWS_CANIF_712*/
#if(CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
        if(NULL_PTR != CanIf_DispatchUserTrcvModeIndicationName)
#endif
        {
            CANIF_DISPATCH_USERTRCVMODEINDICATION_NAME;
        }
    }
}
#endif

#if(STD_ON ==  CANIF_PUBLIC_ICOM_SUPPORT) /*SWS_CANIF_00875*/
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_SetIcomConfiguration  SWS_CANIF_00861
*
* Description:   This service will call Can Driver's api, to change the icom configration
*
* Inputs:        ControllerId,ConfigurationId
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetIcomConfiguration
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId
)
{
    Std_ReturnType ret = E_NOT_OK;
    CanIf_CanSetIComConfigrationType canSetIcomFctPtr;

    /*SWS_CANIF_00872*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETICOM_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_SETICOM_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else
    {
        canSetIcomFctPtr = CanIf_Can_SetIComConfigration[CanIf_GetDrvIdOfCtrl(CANIF_CONTROLLER_ID)];
        if(NULL_PTR == canSetIcomFctPtr)
        {
            CANIF_DET_REPORT_ERROR(CANIF_SETICOM_APIID, CANIF_E_LINKAPINULL);
        }
        else
        {
            ret = canSetIcomFctPtr(CanIf_GetCtrlId(CANIF_CONTROLLER_ID), ConfigurationId);/*SWS_CANIF_00838*/
        }

    }

    return ret;

}
#endif



/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_TriggerTransmit  SWS_CANIF_00883
*
* Description:   This service is called by CanWrite, to trigger the Tx data from uplayyer
*
* Inputs:        TxPduId,PduInfoPtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON ==  CANIF_TRIGGER_TRANSMIT_SUPPORT) /*SWS_CANIF_00884*/
#if(CANIF_MAX_TXTRIGGER_NUM > 0)
FUNC(Std_ReturnType, CANIF_CODE) CanIf_TriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr
)
{
    Std_ReturnType ret = E_NOT_OK;
    CanIf_User_TriggerTransmitType  TriggerTxFun = NULL_PTR;

    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRIGGER_TRANSMIT_APIID, CANIF_E_UNINIT);
    }
    else if((TxPduId >= CANIF_USED_TXPDU_NUM) || (FALSE == CANIF_TXPDU_CFG_INFO[TxPduId].isTriggerPdu))
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRIGGER_TRANSMIT_APIID, CANIF_E_INVALID_TXPDUID);
    }
    else if(NULL_PTR == PduInfoPtr)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TRIGGER_TRANSMIT_APIID, CANIF_E_PARAM_POINTER);
    }
    else
    {
        TriggerTxFun = CanIf_TxTriggerName[CANIF_TXPDU_CFG_INFO[TxPduId].TriggerTransmit];
        if(NULL_PTR != TriggerTxFun)
        {
            ret = TriggerTxFun(CANIF_TXPDU_CFG_INFO[TxPduId].PduRef, PduInfoPtr);/*SWS_CANIF_00885*/
        }
    }

    return ret;

}
#endif
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_CurrentIcomConfiguration  SWS_CANIF_00862
*
* Description:   This service is called when CanDrv finish the new ICom set
*
* Inputs:        TxPduId,PduInfoPtr
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON ==  CANIF_PUBLIC_ICOM_SUPPORT) /*SWS_CANIF_00876*/
FUNC(void, CANIF_CODE) CanIf_CurrentIcomConfiguration
(
    uint8 ControllerId,
    IcomConfigIdType ConfigurationId,
    IcomSwitch_ErrorType Error
)
{

    /*SWS_CANIF_00873*/
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CURRENTICOM_APIID, CANIF_E_UNINIT);
    }
    else if(ControllerId >= CANIF_USED_CONTROLLER_NUM)
    {
        CANIF_DET_REPORT_ERROR(CANIF_CURRENTICOM_APIID, CANIF_E_PARAM_CONTROLLERID);
    }
    else
    {
#if(CANIF_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_PRECOMPILE)
        if(NULL_PTR != CanIf_DispatchUserCurrentIcomConfigurationName)
#endif
        {
            CANIF_DISPATCH_CURRENTICOM_NAME;  /*SWS_CANIF_00839*/
        }

    }

}
#endif


#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_ClearTransmitBuffer
*
* Description:   Clear the  CanIfTxBufferPDUFillflag of CanTxPdu which
*                belong to the specific  controller
* Inputs:        ControllerId : controller which wanted to clear the buffer
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANIF_CODE)  CanIf_ClearTransmitBuffer
(
    const uint8 ControllerId
)
{
#if((CANIF_MAX_TXBUF_NUM > 0) && (CANIF_MAX_HTH_NUM > 0))
    Can_HwHandleType HthCnt;
    PduIdType BufIndex;
    /* search all hth of this controller ,clear buffer*/
    for(HthCnt = (Can_HwHandleType)0; HthCnt < CANIF_USED_HTH_NUM; HthCnt++)
    {
        if(CANIF_HTH_CFG_INFO[HthCnt].CanIfCtrlIdRef == ControllerId)
        {
            CanIf_TxBufferFillCount[HthCnt] = (PduIdType)0;
            if(CANIF_HTH_CFG_INFO[HthCnt].TxBufSize > (PduIdType)0)
            {
                for(BufIndex = CANIF_HTH_CFG_INFO[HthCnt].FirstBufIndexHth;
                        BufIndex < (CANIF_HTH_CFG_INFO[HthCnt].FirstBufIndexHth + CANIF_HTH_CFG_INFO[HthCnt].TxBufSize);
                        BufIndex++)
                {
                    CanIf_TxBufActiveFlag[BufIndex] = FALSE;
                    CanIf_TxBufPdu[BufIndex].id = (Can_IdType)0;
                    CanIf_TxBufPdu[BufIndex].length = (uint8)0;
                    CanIf_TxBufPdu[BufIndex].swPduHandle = COMSTACK_INVALID_PDUID;
                    CanIf_TxBufPdu[BufIndex].sdu = NULL_PTR;
                    /* dont need to set buffer data to 0 */
                }
            }
        }
    }
#endif
}
#endif

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_TxConfirmationFail
*
* Description:	 Used when TxConfirmation fails
*
* Inputs:        ControllerId : controller which wanted to clear the buffer
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANIF_CODE)  CanIf_TxConfirmationFail
(
    const uint8 ControllerId
)
{
    CanIf_User_TxConfirmationType TxConfFctPtr = NULL_PTR;
    PduIdType CanTxPduId;
#if((STD_ON == CANIF_PUBLIC_TX_BUFFERING) && (CANIF_MAX_TXBUF_NUM > 0))
    PduIdType txBufIndex;
#endif

    for(CanTxPduId = (PduIdType)0; CanTxPduId < CANIF_USED_TXPDU_NUM; CanTxPduId++)
    {

        if(ControllerId == CanIf_CtrlIdOfTxPdu(CanTxPduId))
        {
#if((STD_ON == CANIF_PUBLIC_TX_BUFFERING) && (CANIF_MAX_TXBUF_NUM > 0))
            txBufIndex = CANIF_TXPDU_CFG_INFO[(CanTxPduId)].TxBufIndex;
            if(((COMSTACK_INVALID_PDUID != txBufIndex) && (TRUE == CanIf_TxBufActiveFlag[txBufIndex]))
                || (TRUE == CanIf_TxWaitConfirmationFlag[CanTxPduId]))
#else
            if(TRUE == CanIf_TxWaitConfirmationFlag[CanTxPduId])
#endif
            {
                TxConfFctPtr = CanIf_TxConfirmationName[CANIF_TXPDU_CFG_INFO[CanTxPduId].TxConfirmation];
                if(NULL_PTR != TxConfFctPtr)
                {
                    TxConfFctPtr(CANIF_TXPDU_CFG_INFO[CanTxPduId].PduRef, E_NOT_OK);
                }
                CanIf_TxWaitConfirmationFlag[CanTxPduId] = FALSE;
            }
        }
    }
}

#if((STD_ON == CANIF_BUS_MIRRORING_SUPPORT) && (STD_OFF == CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT) && (STD_OFF == CANIF_HOH_OPTIMIZE_SUPPORT))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_MirrorGetHthNum
*
* Description:   This service remap the hrh from can to canif's internal hrh
*
* Inputs:        PduId
*
* Outputs:       PduIdType
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Can_HwHandleType, CANIF_CODE) CanIf_MirrorGetHthNum
(
    PduIdType TxPduId
)
{
    Can_HwHandleType Cnt;
    Can_HwHandleType MirrBuffNum = (Can_HwHandleType)0;
    const Can_HwHandleType HthID = CanIf_HthOfTxPdu(TxPduId);

    for(Cnt = (Can_HwHandleType)0; Cnt < (CANIF_USED_HTH_NUM + CANIF_USED_HRH_NUM); Cnt++)
    {
        if(CANIF_HTH_CFG_INFO[Cnt].HthIdSymRef < HthID)
        {
            MirrBuffNum ++;
        }
    }

    return MirrBuffNum;
}
#endif

#if((CANIF_PRIVATE_SWTXFIFO_RETRY == STD_ON) && (CANIF_PRIVATE_SWTXFIFO_SUPPORT == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_MainFunction
*
* Description:   Operation of FIFO in tasks of the main loop.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, CANIF_CODE) CanIf_MainFunction
(
    void
)
{
    if(STD_INITIALIZED != CanIf_InitStatus)
    {
        CANIF_DET_REPORT_ERROR(CANIF_TXFIFOMAIN_APIID, CANIF_E_UNINIT);
    }
    else
    {
    	CanIf_TxSwFifo_MainFunction();
    }

}
#endif
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_PduInit
*
* Description:   Initialize Pdu related states in CanIf_Init().
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, CANIF_CODE) CanIf_PduInit
(
    void
)
{

#if((CANIF_MAX_TXPDU_NUM > 0) \
  || (CANIF_MAX_RXBUF_NUM > 0) \
  || (CANIF_MAX_RXNOTIFY_NUM > 0))
    PduIdType PduCnt;
#endif

#if(STD_ON == CANIF_PUBLIC_SETDYNAMICTXID_API)
#if(CANIF_MAX_DYNTXPDU_NUM > 0)
    for(PduCnt = (PduIdType)0; PduCnt < CANIF_USED_TXPDU_NUM; PduCnt++)
    {
        if(TRUE == CANIF_TXPDU_CFG_INFO[PduCnt].isDynPduType)
        {
            /*SWS_CANIF_00857*/
            CanIf_TxPduCanIdForDynamic[CANIF_TXPDU_CFG_INFO[PduCnt].DynPduIndex]
                = CANIF_TXPDU_CFG_INFO[PduCnt].CanId;
        }

    }
#endif
#endif

#if(STD_ON == CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API)
#if(CANIF_MAX_TXNOTIFY_NUM > 0)
    for(PduCnt = (PduIdType)0; PduCnt < CANIF_USED_TXNOTIFY_NUM; PduCnt++)
    {
        CanIf_TxNotifStatus[PduCnt] = CANIF_NO_NOTIFICATION;
    }
#endif
#endif

#if(STD_ON == CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API)
#if(CANIF_MAX_RXNOTIFY_NUM > 0)
    for(PduCnt = (PduIdType)0; PduCnt < CANIF_USED_RXNOTIFY_NUM; PduCnt++)
    {
        CanIf_RxNotifStatus[PduCnt] = CANIF_NO_NOTIFICATION;
    }
#endif
#endif

#if(STD_ON == CANIF_PUBLIC_READRXPDU_DATA_API)
#if(CANIF_MAX_RXBUF_NUM > 0)
    for(PduCnt = (PduIdType)0; PduCnt < CANIF_USED_RXBUF_NUM; PduCnt++)
    {
        CanIf_RxBufferSduLength[PduCnt] = (PduIdType)0;
    }
#endif
#endif

#if(CANIF_MAX_TXPDU_NUM > 0)
    for(PduCnt = (PduIdType)0; PduCnt < (PduIdType)CANIF_MAX_TXPDU_NUM; PduCnt++)
    {
        CanIf_TxWaitConfirmationFlag[PduCnt] = FALSE;
    }
#endif
}


#if(CANIF_MAX_TXPDU_NUM > 0)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: CanIf_WritePdu
*
* Description:   Send Pdu and call in the CanIf_TransmitInternal.
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(Std_ReturnType, CANIF_CODE) CanIf_WritePdu
(
    PduIdType CanTxPduId,
    PduLengthType CanIfSduLength,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr,
    P2CONST(Can_PduType, AUTOMATIC, CANIF_APPL_DATA) CanIfTxPduObject,
    P2CONST(uint8, AUTOMATIC, CANIF_APPL_DATA) CanIfTxPduBuffer
)
{
    Std_ReturnType ret = E_NOT_OK;
    Can_ReturnType CanTxResult;
#if(STD_OFF == CANIF_PRIVATE_SWTXFIFO_SUPPORT)
    CanIf_CanWriteType canWriteFctPtr = CanIf_Can_Write[CanIf_GetDrvIdOfTxPdu(CanTxPduId)];
#endif
#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)
    uint8 MirrorControllerId = (uint8)0;
    uint16 MirrorHthBufferId = (uint16)0;
#endif
#if((STD_ON == CANIF_PUBLIC_TX_BUFFERING) && (CANIF_MAX_TXBUF_NUM > 0) && (CANIF_MAX_HTH_NUM > 0))
    PduIdType txBufIndex;
#endif

    SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_2();
#if(STD_ON == CANIF_PRIVATE_SWTXFIFO_SUPPORT)
    /* fifo need HthRef , not CanIf_HthOfTxPdu*/
    CanTxResult =  CanIf_TxSwFifo_Write(CANIF_TXPDU_CFG_INFO[(CanTxPduId)].HthRef, CanIfTxPduObject);
#else
    CanTxResult = canWriteFctPtr(CanIf_HthOfTxPdu(CanTxPduId), CanIfTxPduObject);
#endif
    if(CAN_OK == CanTxResult )
    {
        ret = E_OK;/*SWS_CANIF_00162*/

#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)
        MirrorControllerId = CanIf_CtrlIdOfTxPdu(CanTxPduId);
        MirrorHthBufferId = (CanIf_HthOfTxPdu(CanTxPduId) - (uint16)CANIF_MAX_HRH_NUM);
        if(TRUE == CanIf_BusMirrorEn[MirrorControllerId])
        {
            Bsw_MemCpy(CanIf_MirrorBackupSts[MirrorHthBufferId].MirrorHthBuffer,
                PduInfoPtr->SduDataPtr, (uint32)CanIfSduLength);
            CanIf_MirrorBackupSts[MirrorHthBufferId].CanID = CanIfTxPduObject->id;
            CanIf_MirrorBackupSts[MirrorHthBufferId].length = (uint8)CanIfSduLength;
        }
#endif/*#if(STD_ON == CANIF_BUS_MIRRORING_SUPPORT)*/
        CanIf_TxWaitConfirmationFlag[CanTxPduId] = TRUE;
    }
    else
    {
        ret = E_NOT_OK;
    }
    SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_2();
#if((STD_ON == CANIF_PUBLIC_TX_BUFFERING) && (CANIF_MAX_TXBUF_NUM > 0) && (CANIF_MAX_HTH_NUM > 0))
    /*SWS_CANIF_00063, SWS_CANIF_00849,SWS_CANIF_00881
        SWS_CANIF_00381,835,836 :check if there is active buffer for this pdu
        SWS_CANIF_068, new data will overwrite old data in buffer

    */
    if((Can_ReturnType)CAN_BUSY == CanTxResult)
    {
        txBufIndex = CANIF_TXPDU_CFG_INFO[(CanTxPduId)].TxBufIndex;
        if(txBufIndex != COMSTACK_INVALID_PDUID)
        {
            SchM_Enter_CanIf_CANIF_EXCLUSIVE_AREA_3();

            if(FALSE == CanIf_TxBufActiveFlag[txBufIndex])
            {
                CanIf_TxBufActiveFlag[txBufIndex] = TRUE;
                /*PRQA S 3383 ++*/
                /*CanIf_TxBufferFillCount[] will bever exceed the max value
                    because it is determined by the size of CanIf_TxBufActiveFlag[]*/
                CanIf_TxBufferFillCount[CANIF_TXPDU_CFG_INFO[(CanTxPduId)].HthRef]++;
                /*PRQA S 3383 --*/
            }
#if(STD_ON == CANIF_TRIGGER_TRANSMIT_SUPPORT)
            if(TRUE == CANIF_TXPDU_CFG_INFO[CanTxPduId].isTriggerPdu)
            {
                CanIf_TxBufPdu[txBufIndex].id = CanIfTxPduObject->id;
                CanIf_TxBufPdu[txBufIndex].length = (uint8)0;
                CanIf_TxBufPdu[txBufIndex].sdu = NULL_PTR;
                CanIf_TxBufPdu[txBufIndex].swPduHandle = CanTxPduId;

            }
            else
#endif

            {
                /* CANIF068 */
                Bsw_MemCpy(CANIF_TXPDU_CFG_INFO[(CanTxPduId)].dataBuf, CanIfTxPduBuffer, (uint32)CanIfTxPduObject->length);

                CanIf_TxBufPdu[txBufIndex].id = CanIfTxPduObject->id;
                CanIf_TxBufPdu[txBufIndex].length = CanIfTxPduObject->length;
                CanIf_TxBufPdu[txBufIndex].sdu = CANIF_TXPDU_CFG_INFO[(CanTxPduId)].dataBuf;
                CanIf_TxBufPdu[txBufIndex].swPduHandle = CanTxPduId;
            }
            SchM_Exit_CanIf_CANIF_EXCLUSIVE_AREA_3();

            ret = E_OK;
        }
    }
#endif /*#if(STD_ON == CANIF_PUBLIC_TX_BUFFERING)*/
    return ret;
}
#endif


#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"
