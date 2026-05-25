/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Com_PBcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Com module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Com module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/


/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Com_Lcfg.h"

#include "Com_Cfg.h"
#define COM_START_SEC_CONFIG_DATA
#include "Com_MemMap.h"

CONST(Com_ConfigType, COM_CONST) Com_InitCfgSet[2] =
{
    {
        (uint32)0,
        (PduIdType)11,
        (Com_SignalIdType)135,
        (PduIdType)6,
        (Com_SignalIdType)66,
        (Com_SignalGroupIdType)0,
        (Com_SignalGroupIdType)0,
        (Com_IpduGroupIdType)2,
        (Com_SignalIdType)0,
        (uint8)0,
        ComTxPduCfgTable0,
        ComTxSigCfgTable0,
        ComRxPduCfgTable0,
        ComRxSigCfgTable0,
        ComPduGroupCfgTable0,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR
    },
    {
        (uint32)1,
        (PduIdType)11,
        (Com_SignalIdType)135,
        (PduIdType)6,
        (Com_SignalIdType)66,
        (Com_SignalGroupIdType)0,
        (Com_SignalGroupIdType)0,
        (Com_IpduGroupIdType)2,
        (Com_SignalIdType)0,
        (uint8)0,
        ComTxPduCfgTable1,
        ComTxSigCfgTable1,
        ComRxPduCfgTable1,
        ComRxSigCfgTable1,
        ComPduGroupCfgTable1,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR,
        NULL_PTR
    }
};
#define COM_STOP_SEC_CONFIG_DATA
#include "Com_MemMap.h"


