/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dcm_Lcfg.c
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

/*PRQA S 778,779,791,792,1531,1559 EOF*/
/*
Names in this file may not follow relevant rules.
*/

/*PRQA S 857 EOF*/

/*PRQA S 3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "Dcm_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in Dcm_MemMap.h
*/

/*PRQA S 3132 EOF*/
/*
Hard coded 'magic' number, '%s', used to define the size of an array.
*/

/*PRQA S 3211 EOF*/
/*
The global identifier '%s' is defined here and will be used in other files.
*/

/*PRQA S 3635 EOF*/
/*
Function identifier used as a pointer without a preceding & operator.
*/

/*PRQA S 380 EOF*/
/*
Number of macro definitions exceeds 4095 -program does not conform strictly to ISO:C99.
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
* Include files
*******************************************************************************/
#include "Rte_Dcm.h"
#include "SchM_Dcm.h"
#include "Dcm_Lcfg.h"
#include "Dcm_Code.h"
#include "PduR.h"
#include "ComM_Dcm.h"
#include "NvM_Cfg.h"


/*******************************************************************************
* Configuration
*******************************************************************************/
#define DCM_START_SEC_VAR_CLEARED_GLOBAL_8
#include "Dcm_MemMap.h"

STATIC VAR(Dcm_MsgItemType, DCM_VAR) Buffer_0[1024];

#define DCM_STOP_SEC_VAR_CLEARED_GLOBAL_8
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONFIG_DATA
#include "Dcm_MemMap.h"

CONST(uint8, DCM_CONST) Dcm_RxPduToProtocolMap[DCM_CFG_RXPDU_NUM] =
{
    (uint8)0,
    (uint8)0
};

#define DCM_STOP_SEC_CONFIG_DATA
#include "Dcm_MemMap.h"


#define DCM_START_SEC_VAR_CLEARED_LOCAL_16
#include "Dcm_MemMap.h"
VAR(uint16, DCM_VAR) Dcm_DidIndexList[1];
#define DCM_STOP_SEC_VAR_CLEARED_LOCAL_16
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONFIG_DATA
#include "Dcm_MemMap.h"


STATIC CONST(Dcm_DsdSubServiceType, DCM_CONST) Dcm_DsdSubServiceTable_0[18] =
{
    /*SubService index 0*//*10 Service*/
    {
        (uint8)0x01,
        DCM_REQ_PHY_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    /*SubService index 1*//*10 Service*/
    {
        (uint8)0x02,
        DCM_REQ_PHY_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        NULL_PTR
    },
    /*SubService index 2*//*10 Service*/
    {
        (uint8)0x03,
        DCM_REQ_PHY_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    /*SubService index 3*//*10 Service*/
    {
        (uint8)0x66,
        DCM_REQ_PHY_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_ALL_MASK,
        NULL_PTR
    },
    /*SubService index 4*//*11 Service*/
    {
        (uint8)0x01,
        DCM_REQ_PHY_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        NULL_PTR
    },
    /*SubService index 5*//*11 Service*/
    {
        (uint8)0x03,
        DCM_REQ_PHY_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        NULL_PTR
    },
    /*SubService index 6*//*19 Service*/
    {
        (uint8)0x01,
        DCM_REQ_PHY_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    /*SubService index 7*//*19 Service*/
    {
        (uint8)0x02,
        DCM_REQ_PHY_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    /*SubService index 8*//*19 Service*/
    {
        (uint8)0x04,
        DCM_REQ_PHY_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    /*SubService index 9*//*19 Service*/
    {
        (uint8)0x06,
        DCM_REQ_PHY_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    /*SubService index 10*//*19 Service*/
    {
        (uint8)0x0A,
        DCM_REQ_PHY_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    /*SubService index 11*//*27 Service*/
    {
        (uint8)0x03,
        DCM_REQ_PHY_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        NULL_PTR
    },
    /*SubService index 12*//*27 Service*/
    {
        (uint8)0x04,
        DCM_REQ_PHY_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        NULL_PTR
    },
    /*SubService index 13*//*28 Service*/
    {
        (uint8)0x00,
        DCM_REQ_PHY_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        NULL_PTR
    },
    /*SubService index 14*//*28 Service*/
    {
        (uint8)0x01,
        DCM_REQ_PHY_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        NULL_PTR
    },
    /*SubService index 15*//*3E Service*/
    {
        (uint8)0x00,
        DCM_REQ_PHY_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        NULL_PTR
    },
    /*SubService index 16*//*85 Service*/
    {
        (uint8)0x01,
        DCM_REQ_PHY_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        NULL_PTR
    },
    /*SubService index 17*//*85 Service*/
    {
        (uint8)0x02,
        DCM_REQ_PHY_FUN_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        NULL_PTR
    }
};


/*DcmDsdServiceTable*/
STATIC CONST(Dcm_DsdServiceType, DCM_CONST) Dcm_DsdServiceTable_0[10] =
{
    {
        (uint8)0x10,
        DCM_REQ_PHY_FUN_MASK,
        (uint16)2,
        NULL_PTR,
        TRUE,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        (uint8)4,
        (uint16)0
    },
    {
        (uint8)0x11,
        DCM_REQ_PHY_FUN_MASK,
        (uint16)2,
        NULL_PTR,
        TRUE,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        (uint8)2,
        (uint16)4
    },
    {
        (uint8)0x14,
        DCM_REQ_PHY_MASK,
        (uint16)4,
        NULL_PTR,
        FALSE,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        (uint8)0,
        (uint16)0
    },
    {
        (uint8)0x19,
        DCM_REQ_PHY_MASK,
        (uint16)2,
        NULL_PTR,
        TRUE,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        (uint8)5,
        (uint16)6
    },
    {
        (uint8)0x22,
        DCM_REQ_PHY_FUN_MASK,
        (uint16)3,
        NULL_PTR,
        FALSE,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        (uint8)0,
        (uint16)0
    },
    {
        (uint8)0x27,
        DCM_REQ_PHY_MASK,
        (uint16)2,
        NULL_PTR,
        TRUE,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        (uint8)2,
        (uint16)11
    },
    {
        (uint8)0x28,
        DCM_REQ_PHY_FUN_MASK,
        (uint16)3,
        NULL_PTR,
        TRUE,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        (uint8)2,
        (uint16)13
    },
    {
        (uint8)0x31,
        DCM_REQ_PHY_MASK,
        (uint16)4,
        NULL_PTR,
        TRUE,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_EXTENDED_MASK | DCM_FACTORYTEST_MASK,
        (uint8)0,
        (uint16)0
    },
    {
        (uint8)0x3E,
        DCM_REQ_PHY_FUN_MASK,
        (uint16)2,
        NULL_PTR,
        TRUE,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_DEFAULT_MASK | DCM_EXTENDED_MASK,
        (uint8)1,
        (uint16)15
    },
    {
        (uint8)0x85,
        DCM_REQ_PHY_FUN_MASK,
        (uint16)2,
        NULL_PTR,
        TRUE,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_EXTENDED_MASK,
        (uint8)2,
        (uint16)16
    }
};
CONST(Dcm_DsdServiceTableType, DCM_CONST) Dcm_DsdServiceTable[DCM_CFG_NUM_OF_STAB] =
{
    {
        (uint8)0,
        (uint8)10,
        Dcm_DsdServiceTable_0,
        (uint16)18,
        Dcm_DsdSubServiceTable_0
    }
};
CONST(Dcm_DslProtocolRowType, DCM_CONST) Dcm_DslProtocolRow[DCM_CFG_NUM_OF_PROTOCOL] =
{
    {
        DCM_UDS_ON_CAN,
        (uint8)1,
        (uint16)20,
        (uint16)20,
        (uint16)0x1234,
        DCM_TYPE1,
        TRUE,
        (uint8)0,
        {
            (Dcm_MsgLenType)1024,
            Buffer_0
        },
        {
            (Dcm_MsgLenType)1024,
            Buffer_0
        },
        (uint8)0,
        (uint8)1,
        (uint32)5000
    }
};


#define DCM_STOP_SEC_CONFIG_DATA
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CONFIG_DATA
#include "Dcm_MemMap.h"

STATIC CONST(Dcm_DspSessionRowType, DCM_CONST) Dcm_DspSessionRow_0[4] =
{
    {
        DCM_NO_BOOT,
        DCM_DEFAULT_SESSION,
        DCM_DEFAULT_MASK,
        (uint16)50,
        (uint32)2000,
        RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION
    },
    {
        DCM_OEM_BOOT,
        DCM_PROGRAMMING_SESSION,
        DCM_PROGRAMMING_MASK,
        (uint16)50,
        (uint32)2000,
        RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION
    },
    {
        DCM_NO_BOOT,
        DCM_EXTENDED_DIAGNOSTIC_SESSION,
        DCM_EXTENDED_MASK,
        (uint16)50,
        (uint32)2000,
        RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_DIAGNOSTIC_SESSION
    },
    {
        DCM_NO_BOOT,
        DCM_FACTORYTEST_SESSION,
        DCM_FACTORYTEST_MASK,
        (uint16)50,
        (uint32)2000,
        RTE_MODE_DcmDiagnosticSessionControl_FACTORYTEST_SESSION
    }
};
CONST(Dcm_DspSessionType, DCM_CONST) Dcm_DspSession[DCM_CFG_NUM_OF_STAB] =
{
    {
        (uint8)4,
        Dcm_DspSessionRow_0
    }
};

STATIC CONST(Dcm_DspSecurityRowType, DCM_CONST) Dcm_DspSecurityRow_0[1] =
{
    {
        DCM_SEC_LEV_L2,
        (uint8)3,
        (uint32)4,
        (uint32)4,
        (uint32)10000,
        (uint32)0,
        Dcm_SecurityAccess_L2_GetSeed,
        Dcm_SecurityAccess_L2_CompareKey,
        TRUE,
        Dcm_Rte_SecurityAccess_L2_GetSecurityAttemptCounter,
        Dcm_Rte_SecurityAccess_L2_SetSecurityAttemptCounter,
        DCM_L2_MASK
    }
};
CONST(Dcm_DspSecurityType, DCM_CONST) Dcm_DspSecurity[DCM_CFG_NUM_OF_STAB] =
{
    {
        (uint8)1,
        Dcm_DspSecurityRow_0
    }
};

CONST(Dcm_DspComControlType, DCM_CONST) Dcm_DspComControl[DCM_CFG_NUM_OF_STAB] =
{
    {
        (uint8)1,
        (uint8)0,
        (uint16)0
    }
};

STATIC CONST(Dcm_DspDataTableType, DCM_CONST) Dcm_DspDataTable_0[18] =
{
    {/*0*/
        (uint16)4,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xF010_0_ReadData,
        (NvM_BlockIdType)0
    },
    {/*1*/
        (uint16)11,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xF110_0_ReadData,
        (NvM_BlockIdType)0
    },
    {/*2*/
        (uint16)2,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xF111_0_ReadData,
        (NvM_BlockIdType)0
    },
    {/*3*/
        (uint16)11,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xF118_0_ReadData,
        (NvM_BlockIdType)0
    },
    {/*4*/
        (uint16)2,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xF119_0_ReadData,
        (NvM_BlockIdType)0
    },
    {/*5*/
        (uint16)3,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xF150_0_ReadData,
        (NvM_BlockIdType)0
    },
    {/*6*/
        (uint16)12,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xF15B_0_ReadData,
        (NvM_BlockIdType)0
    },
    {/*7*/
        (uint16)1,
        DCM_UINT8,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xF186_0_ReadData,
        (NvM_BlockIdType)0
    },
    {/*8*/
        (uint16)8,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xF18A_0_ReadData,
        (NvM_BlockIdType)0
    },
    {/*9*/
        (uint16)3,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xF18B_0_ReadData,
        (NvM_BlockIdType)0
    },
    {/*10*/
        (uint16)16,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xF18C_0_ReadData,
        (NvM_BlockIdType)0
    },
    {/*11*/
        (uint16)3,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xF193_0_ReadData,
        (NvM_BlockIdType)0
    },
    {/*12*/
        (uint16)3,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xF195_0_ReadData,
        (NvM_BlockIdType)0
    },
    {/*13*/
        (uint16)3,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xF19E_0_ReadData,
        (NvM_BlockIdType)0
    },
    {/*14*/
        (uint16)3,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xFD00_0_ReadData,
        (NvM_BlockIdType)0
    },
    {/*15*/
        (uint16)3,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xFD01_0_ReadData,
        (NvM_BlockIdType)0
    },
    {/*16*/
        (uint16)3,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xFD02_0_ReadData,
        (NvM_BlockIdType)0
    },
    {/*17*/
        (uint16)2,
        DCM_UINT8_N,
        DCM_USE_DATA_ASYNCH_CLIENT_SERVER_ERROR,
        FALSE,
        NULL_PTR,
        NULL_PTR,
        Dcm_DataServices_0xFD03_0_ReadData,
        (NvM_BlockIdType)0
    }
};
CONST(Dcm_DspDataType, DCM_CONST) Dcm_DspData[DCM_CFG_NUM_OF_STAB] =
{
    {
        (uint16)18,
        Dcm_DspDataTable_0
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF010_0[1] =
{
    {
        (uint16)0,
        (uint16)0
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF110_0[1] =
{
    {
        (uint16)0,
        (uint16)1
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF111_0[1] =
{
    {
        (uint16)0,
        (uint16)2
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF118_0[1] =
{
    {
        (uint16)0,
        (uint16)3
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF119_0[1] =
{
    {
        (uint16)0,
        (uint16)4
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF150_0[1] =
{
    {
        (uint16)0,
        (uint16)5
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF15B_0[1] =
{
    {
        (uint16)0,
        (uint16)6
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF186_0[1] =
{
    {
        (uint16)0,
        (uint16)7
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF18A_0[1] =
{
    {
        (uint16)0,
        (uint16)8
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF18B_0[1] =
{
    {
        (uint16)0,
        (uint16)9
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF18C_0[1] =
{
    {
        (uint16)0,
        (uint16)10
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF193_0[1] =
{
    {
        (uint16)0,
        (uint16)11
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF195_0[1] =
{
    {
        (uint16)0,
        (uint16)12
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xF19E_0[1] =
{
    {
        (uint16)0,
        (uint16)13
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xFD00_0[1] =
{
    {
        (uint16)0,
        (uint16)14
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xFD01_0[1] =
{
    {
        (uint16)0,
        (uint16)15
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xFD02_0[1] =
{
    {
        (uint16)0,
        (uint16)16
    }
};
STATIC CONST(Dcm_DspDidSignalType, DCM_CONST) Dcm_DspDidSignal_0xFD03_0[1] =
{
    {
        (uint16)0,
        (uint16)17
    }
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF010_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF110_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF111_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF118_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF119_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF150_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF15B_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF186_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF18A_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF18B_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF18C_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF193_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF195_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xF19E_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xFD00_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xFD01_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xFD02_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidReadType, DCM_CONST) Dcm_DspDidRead_0xFD03_0 =
{
    DCM_REQ_PHY_FUN_MASK,
    DCM_LOCKED_MASK | DCM_L2_MASK,
    DCM_DEFAULT_MASK | DCM_EXTENDED_MASK
};
STATIC CONST(Dcm_DspDidTableType, DCM_CONST) Dcm_DspDidTable_0[18] =
{
    {/*0*/
        (uint16)0xF010,
        (uint16)0x4,
        {
            &Dcm_DspDidRead_0xF010_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xF010_0
    },
    {/*1*/
        (uint16)0xF110,
        (uint16)0xb,
        {
            &Dcm_DspDidRead_0xF110_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xF110_0
    },
    {/*2*/
        (uint16)0xF111,
        (uint16)0x2,
        {
            &Dcm_DspDidRead_0xF111_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xF111_0
    },
    {/*3*/
        (uint16)0xF118,
        (uint16)0xb,
        {
            &Dcm_DspDidRead_0xF118_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xF118_0
    },
    {/*4*/
        (uint16)0xF119,
        (uint16)0x2,
        {
            &Dcm_DspDidRead_0xF119_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xF119_0
    },
    {/*5*/
        (uint16)0xF150,
        (uint16)0x3,
        {
            &Dcm_DspDidRead_0xF150_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xF150_0
    },
    {/*6*/
        (uint16)0xF15B,
        (uint16)0xc,
        {
            &Dcm_DspDidRead_0xF15B_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xF15B_0
    },
    {/*7*/
        (uint16)0xF186,
        (uint16)0x1,
        {
            &Dcm_DspDidRead_0xF186_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xF186_0
    },
    {/*8*/
        (uint16)0xF18A,
        (uint16)0x8,
        {
            &Dcm_DspDidRead_0xF18A_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xF18A_0
    },
    {/*9*/
        (uint16)0xF18B,
        (uint16)0x3,
        {
            &Dcm_DspDidRead_0xF18B_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xF18B_0
    },
    {/*10*/
        (uint16)0xF18C,
        (uint16)0x10,
        {
            &Dcm_DspDidRead_0xF18C_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xF18C_0
    },
    {/*11*/
        (uint16)0xF193,
        (uint16)0x3,
        {
            &Dcm_DspDidRead_0xF193_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xF193_0
    },
    {/*12*/
        (uint16)0xF195,
        (uint16)0x3,
        {
            &Dcm_DspDidRead_0xF195_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xF195_0
    },
    {/*13*/
        (uint16)0xF19E,
        (uint16)0x3,
        {
            &Dcm_DspDidRead_0xF19E_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xF19E_0
    },
    {/*14*/
        (uint16)0xFD00,
        (uint16)0x3,
        {
            &Dcm_DspDidRead_0xFD00_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xFD00_0
    },
    {/*15*/
        (uint16)0xFD01,
        (uint16)0x3,
        {
            &Dcm_DspDidRead_0xFD01_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xFD01_0
    },
    {/*16*/
        (uint16)0xFD02,
        (uint16)0x3,
        {
            &Dcm_DspDidRead_0xFD02_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xFD02_0
    },
    {/*17*/
        (uint16)0xFD03,
        (uint16)0x2,
        {
            &Dcm_DspDidRead_0xFD03_0,
        },
        (uint16)1,
        Dcm_DspDidSignal_0xFD03_0
    }
};
CONST(Dcm_DspDidType, DCM_CONST) Dcm_DspDid[DCM_CFG_NUM_OF_STAB] =
{
    {
        (uint16)18,
        Dcm_DspDidTable_0
    }
};
STATIC CONST(Dcm_DspCommonAuthorizationType, DCM_CONST) Dcm_DspCommonAuthorization_0[4] =
{
    {
        DCM_REQ_PHY_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_EXTENDED_MASK
    },
    {
        DCM_REQ_PHY_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_FACTORYTEST_MASK
    },
    {
        DCM_REQ_PHY_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_FACTORYTEST_MASK
    },
    {
        DCM_REQ_PHY_MASK,
        DCM_LOCKED_MASK | DCM_L2_MASK,
        DCM_FACTORYTEST_MASK
    }
};
STATIC CONST(Dcm_DspRoutineControlType, DCM_CONST) Dcm_DspStartRoutine_0x0203_0 =
{
    Dcm_RoutineServices_0x0203_Start,
    &(Dcm_DspCommonAuthorization_0[0]),
    {
        (uint16)0,
        DCM_UINT8
    },
    {
        (uint16)1,
        DCM_UINT8
    }
};

STATIC CONST(Dcm_DspRoutineControlType, DCM_CONST) Dcm_DspStartRoutine_0xFD01_0 =
{
    Dcm_RoutineServices_0xFD01_Start,
    &(Dcm_DspCommonAuthorization_0[3]),
    {
        (uint16)0,
        DCM_UINT8
    },
    {
        (uint16)0,
        DCM_UINT8
    }
};

STATIC CONST(Dcm_DspRoutineControlType, DCM_CONST) Dcm_DspStartRoutine_0xFD04_0 =
{
    Dcm_RoutineServices_0xFD04_Start,
    &(Dcm_DspCommonAuthorization_0[1]),
    {
        (uint16)4,
        DCM_UINT32
    },
    {
        (uint16)4,
        DCM_UINT32
    }
};

STATIC CONST(Dcm_DspRoutineControlType, DCM_CONST) Dcm_DspStartRoutine_0xFD05_0 =
{
    Dcm_RoutineServices_0xFD05_Start,
    &(Dcm_DspCommonAuthorization_0[2]),
    {
        (uint16)2,
        DCM_UINT16
    },
    {
        (uint16)2,
        DCM_UINT16
    }
};


STATIC CONST(Dcm_DspRoutineIdInfoType, DCM_CONST) Dcm_DspRoutineIdInfo_0[4] =
{
    {
        (uint16)0x0203,
        &Dcm_DspStartRoutine_0x0203_0,
        NULL_PTR,
        NULL_PTR
    },
    {
        (uint16)0xFD01,
        &Dcm_DspStartRoutine_0xFD01_0,
        NULL_PTR,
        NULL_PTR
    },
    {
        (uint16)0xFD04,
        &Dcm_DspStartRoutine_0xFD04_0,
        NULL_PTR,
        NULL_PTR
    },
    {
        (uint16)0xFD05,
        &Dcm_DspStartRoutine_0xFD05_0,
        NULL_PTR,
        NULL_PTR
    }
};

CONST(Dcm_DspRoutineType, DCM_CONST) Dcm_DspRoutine[DCM_CFG_NUM_OF_STAB] =
{
    {
        (uint16)4,
        Dcm_DspRoutineIdInfo_0
    }
};

STATIC CONST(Dcm_DspEcuResetRowType, DCM_CONST) Dcm_DspEcuResetRow_0[2] =
{
    {
        (uint8)0x01,
        DCM_BEFORE_RESET
    },
    {
        (uint8)0x03,
        DCM_BEFORE_RESET
    }
};
CONST(Dcm_DspEcuResetType, DCM_CONST) Dcm_DspEcuReset[DCM_CFG_NUM_OF_STAB] =
{
    {
        (uint8)2,
        Dcm_DspEcuResetRow_0
    }
};

#define DCM_STOP_SEC_CONFIG_DATA
#include "Dcm_MemMap.h"


