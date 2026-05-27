/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dcm_PBcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Dcm module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Dcm module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/

/*******************************************************************************
* Include files
*******************************************************************************/
#include "Dcm_PBcfg.h"
#include "SchM_Dcm.h"
#include "PduR_PBcfg.h"


/*******************************************************************************
* Configuration
*******************************************************************************/

#define DCM_START_SEC_CONFIG_DATA
#include "Dcm_MemMap.h"

STATIC CONST(boolean, DCM_CONST) Dcm_DsdServiceUsed_PB0_STAB0[10U] = {TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE};
STATIC CONST(boolean, DCM_CONST) Dcm_DsdSubServiceUsed_PB0_STAB0[18U] = {TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE};
STATIC CONST(boolean, DCM_CONST) Dcm_DsdServiceUsed_PB1_STAB0[10U] = {TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE};
STATIC CONST(boolean, DCM_CONST) Dcm_DsdSubServiceUsed_PB1_STAB0[18U] = {TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE};

STATIC CONST(boolean, DCM_CONST) Dcm_DspDidUsed_PB0_STAB0[18U] = {TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE};
STATIC CONST(boolean, DCM_CONST) Dcm_DspDidUsed_PB1_STAB0[18U] = {TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE};

STATIC CONST(boolean, DCM_CONST) Dcm_DspRoutineUsed_PB0_STAB0[4U] = {TRUE, TRUE, TRUE, TRUE};
STATIC CONST(boolean, DCM_CONST) Dcm_DspRoutineUsed_PB1_STAB0[4U] = {TRUE, TRUE, TRUE, TRUE};

#define DCM_STOP_SEC_CONFIG_DATA
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONFIG_DATA
#include "Dcm_MemMap.h"

STATIC CONST(Dcm_DspComControlAllChannelType, DCM_CONST) Dcm_DspComControlAllChannel_PB0_STAB0[1U] =
{
    {
        TRUE,
        ComM_ComM_BODY_LE1_CAN,
        SchM_Switch_DcmCommunicationControl_ComM_BODY_LE1_CAN
    }
};
STATIC CONST(Dcm_DspComControlAllChannelType, DCM_CONST) Dcm_DspComControlAllChannel_PB1_STAB0[1U] =
{
    {
        TRUE,
        ComM_ComM_BODY_LE1_CAN,
        SchM_Switch_DcmCommunicationControl_ComM_BODY_LE1_CAN
    }
};


STATIC CONST(Dcm_DslProtocolRxType, DCM_CONST) Dcm_DslConnection_BODY_LE1_CAN_Model_FunGroup0_ProtocolRx_PB0[2] =
{
    {
        DCM_FUNCTIONAL_TYPE,
        Dcm_PduR_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU,
    },
    {
        DCM_PHYSICAL_TYPE,
        Dcm_PduR_Cfg_D_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_D,
    }
};

STATIC CONST(Dcm_DslProtocolTxType, DCM_CONST) Dcm_DslConnection_BODY_LE1_CAN_Model_FunGroup0_ProtocolTx_PB0 =
{
    Dcm_PduR_Cfg_D_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_D,
    PduR_Dcm_Cfg_D_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_D
};

STATIC CONST(Dcm_DslMainConnectionType, DCM_CONST) Dcm_DslConnection_BODY_LE1_CAN_Model_FunGroup0_MainConnection_0_PB0 =
{
    (uint16)0,
    (uint16)0x1234,
    ComM_ComM_BODY_LE1_CAN,
    (uint8)2,
    Dcm_DslConnection_BODY_LE1_CAN_Model_FunGroup0_ProtocolRx_PB0,
    &Dcm_DslConnection_BODY_LE1_CAN_Model_FunGroup0_ProtocolTx_PB0
};

STATIC CONST(Dcm_DslConnectionType, DCM_CONST) DslProtocolRow0_ConnectionTable_0_PB0[1] =
{
    {
        &Dcm_DslConnection_BODY_LE1_CAN_Model_FunGroup0_MainConnection_0_PB0,
        NULL_PTR
    }
};
STATIC CONST(Dcm_DslProtocolRxType, DCM_CONST) Dcm_DslConnection_BODY_LE1_CAN_Model_FunGroup0_ProtocolRx_PB1[2] =
{
    {
        DCM_FUNCTIONAL_TYPE,
        Dcm_PduR_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_AllECU,
    },
    {
        DCM_PHYSICAL_TYPE,
        Dcm_PduR_Cfg_P_Rx_BODY_LE1_CAN_DIAG_REQ_MCM_P,
    }
};

STATIC CONST(Dcm_DslProtocolTxType, DCM_CONST) Dcm_DslConnection_BODY_LE1_CAN_Model_FunGroup0_ProtocolTx_PB1 =
{
    Dcm_PduR_Cfg_P_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_P,
    PduR_Dcm_Cfg_P_Tx_BODY_LE1_CAN_DIAG_RESP_MCM_P
};

STATIC CONST(Dcm_DslMainConnectionType, DCM_CONST) Dcm_DslConnection_BODY_LE1_CAN_Model_FunGroup0_MainConnection_0_PB1 =
{
    (uint16)0,
    (uint16)0x1234,
    ComM_ComM_BODY_LE1_CAN,
    (uint8)2,
    Dcm_DslConnection_BODY_LE1_CAN_Model_FunGroup0_ProtocolRx_PB1,
    &Dcm_DslConnection_BODY_LE1_CAN_Model_FunGroup0_ProtocolTx_PB1
};

STATIC CONST(Dcm_DslConnectionType, DCM_CONST) DslProtocolRow0_ConnectionTable_0_PB1[1] =
{
    {
        &Dcm_DslConnection_BODY_LE1_CAN_Model_FunGroup0_MainConnection_0_PB1,
        NULL_PTR
    }
};



CONST(Dcm_ConfigType, DCM_CONST) Dcm_PB_Config[2U] =
{
    {
        {TRUE},    /*DcmDslProtocolRowUsed*/
        {DslProtocolRow0_ConnectionTable_0_PB0},    /*DcmDslConnection*/
        {Dcm_DsdServiceUsed_PB0_STAB0},    /*DcmDsdServiceUsed*/
        {Dcm_DsdSubServiceUsed_PB0_STAB0},    /*DcmDsdSubServiceUsed*/
        {Dcm_DspComControlAllChannel_PB0_STAB0},    /*DcmDspComControlAllChannel*/
        {NULL_PTR},    /*DcmDspComControlSpecificChannel*/
        {NULL_PTR},    /*DcmDspComControlSubNodes*/
        {Dcm_DspDidUsed_PB0_STAB0},    /*DcmDspDidUsed*/
        {Dcm_DspRoutineUsed_PB0_STAB0}    /*DcmDspRoutineUsed*/
    },
    {
        {TRUE},    /*DcmDslProtocolRowUsed*/
        {DslProtocolRow0_ConnectionTable_0_PB1},    /*DcmDslConnection*/
        {Dcm_DsdServiceUsed_PB1_STAB0},    /*DcmDsdServiceUsed*/
        {Dcm_DsdSubServiceUsed_PB1_STAB0},    /*DcmDsdSubServiceUsed*/
        {Dcm_DspComControlAllChannel_PB1_STAB0},    /*DcmDspComControlAllChannel*/
        {NULL_PTR},    /*DcmDspComControlSpecificChannel*/
        {NULL_PTR},    /*DcmDspComControlSubNodes*/
        {Dcm_DspDidUsed_PB1_STAB0},    /*DcmDspDidUsed*/
        {Dcm_DspRoutineUsed_PB1_STAB0}    /*DcmDspRoutineUsed*/
    }
};

#define DCM_STOP_SEC_CONFIG_DATA
#include "Dcm_MemMap.h"



