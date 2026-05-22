/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name:       Com_Data.c
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title:          : Com module Source File
*   Author:         : Hirain
********************************************************************************
*   Description:      Implementation of Com provided functionality
*
********************************************************************************
*   Limitations:      None
*
********************************************************************************
*END_FILE_HDR*/

/*****************************************************************************
*  General QAC Suppression
*****************************************************************************/
/*PRQA S 5087,3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "EcuM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in EcuM_MemMap.h
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
*    Com QAC Suppression
*****************************************************************************/

/*PRQA S 3227,3204 EOF*/
/*
Read-only function input parameters may not be defined as const,it does not affect the function.
AUTOSAR API shall define standard input parameters according to specification requirements
*/

/*PRQA S 2100,2101 EOF*/
/*
Integer promotion related
*/

/*PRQA S 2000 EOF*/
/*
When there is only one If,there can be no else.
*/

/*PRQA S 3206,3220 EOF*/
/*
Particularity of configuration files
*/

/*PRQA S 316,315 EOF*/
/*
Allows the void pointer type to be converted into other pointer types.
*/

/*******************************************************************************
*    Includes
*******************************************************************************/
#include "Com.h"
#include "Com_Data.h"
#include "Bsw_Common.h"

/*******************************************************************************
*    Static Api of Com_Data
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
#if 0
STATIC FUNC(uint64, COM_CODE) Com_CreateMask
(
    uint16 BitSize
);
#endif
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleU8
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigU8
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleS8
(
    P2CONST(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigS8
(
    P2CONST(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleU16
(
    P2CONST(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigU16
(
    P2CONST(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleS16
(
    P2CONST(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigS16
(
    P2CONST(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleU32
(
    P2CONST(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigU32
(
    P2CONST(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleS32
(
    P2CONST(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigS32
(
    P2CONST(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleF32
(
    P2CONST(float32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigF32
(
    P2CONST(float32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleU64
(
    P2CONST(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigU64
(
    P2CONST(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleS64
(
    P2CONST(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigS64
(
    P2CONST(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleF64
(
    P2CONST(float64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigF64
(
    P2CONST(float64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
);
STATIC FUNC(void, COM_CODE) Com_WriteSignal_U8N
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    PduLengthType ByteLength,
    uint16 StartBit
);

STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_U8
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_S8
(
    P2CONST(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_U16
(
    P2CONST(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_S16
(
    P2CONST(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_U32
(
    P2CONST(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_S32
(
    P2CONST(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_F32
(
    P2CONST(float32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_U64
(
    P2CONST(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_S64
(
    P2CONST(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_F64
(
    P2CONST(float64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OutSide_U8
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OutSide_U16
(
    P2CONST(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OutSide_U32
(
    P2CONST(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OutSide_U64
(
    P2CONST(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OutSide_S8
(
    P2CONST(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OutSide_S16
(
    P2CONST(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OutSide_S32
(
    P2CONST(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OutSide_S64
(
    P2CONST(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_WithIn_U8
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_WithIn_U16
(
    P2CONST(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_WithIn_U32
(
    P2CONST(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_WithIn_U64
(
    P2CONST(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_WithIn_S8
(
    P2CONST(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_WithIn_S16
(
    P2CONST(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_WithIn_S32
(
    P2CONST(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_WithIn_S64
(
    P2CONST(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskEqualsX_U8
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskEqualsX_U16
(
    P2CONST(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskEqualsX_U32
(
    P2CONST(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskEqualsX_U64
(
    P2CONST(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskEqualsX_S8
(
    P2CONST(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskEqualsX_S16
(
    P2CONST(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskEqualsX_S32
(
    P2CONST(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskEqualsX_S64
(
    P2CONST(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersX_U8
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersX_U16
(
    P2CONST(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersX_U32
(
    P2CONST(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersX_U64
(
    P2CONST(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersX_S8
(
    P2CONST(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersX_S16
(
    P2CONST(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersX_S32
(
    P2CONST(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersX_S64
(
    P2CONST(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersOld_U8
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersOld_U16
(
    P2CONST(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersOld_U32
(
    P2CONST(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersOld_U64
(
    P2CONST(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersOld_S8
(
    P2CONST(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersOld_S16
(
    P2CONST(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersOld_S32
(
    P2CONST(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersOld_S64
(
    P2CONST(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
#if(COM_MAX_FILTER_OCCURRENCE_NUM > 0)
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OneEveryN
(
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
#endif
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CreateMask
*
* Description:   Create a mask
*
* Inputs:        BitSize
*
* Outputs:       Mask
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if 0
STATIC FUNC(uint64, COM_CODE) Com_CreateMask
(
    uint16 BitSize
)
{
    uint16 i;
    uint64 Mask = (uint64)0;
    for(i = 0; i < BitSize; i++)
    {
        Mask |= ((uint64)1 << (uint64)i);
    }
    return Mask;
}
#endif

/**********************************************U8 Write**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_LittleU8
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleU8
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint8 ByteSize;
    uint8 StartByte;
    uint8 LeftShift;
    uint8 RightShift;
    uint8 ValueTemp = (uint8)0;

    ValueTemp = (*ValuePtr & COM_MASK_8(BitSize));
    StartByte = (uint8)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        PduPtr[StartByte] = (uint8)ValueTemp;
    }
    else
    {
        LeftShift = (uint8)(StartBit & COM_REMAIN_MASK);
        RightShift = (uint8)COM_BYTE_SIZE - LeftShift;
        ByteSize = ((uint8)BitSize + LeftShift) >> (uint8)COM_THREE_BIT;
        if((((uint8)BitSize + LeftShift) & (uint8)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte + 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + 1] |= (uint8)((ValueTemp >> RightShift) & (uint8)MaskMsb);
        }
    }
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_BigU8
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigU8
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint8 ByteSize;
    uint8 StartByte;
    uint8 LeftShift;
    uint8 RightShift;
    uint8 ValueTemp = (uint8)0;

    ValueTemp = (*ValuePtr & COM_MASK_8(BitSize));
    StartByte = (uint8)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        PduPtr[StartByte] = (uint8)ValueTemp;
    }
    else
    {
        LeftShift = (uint8)(StartBit & COM_REMAIN_MASK);
        RightShift = (uint8)COM_BYTE_SIZE - LeftShift;
        ByteSize = ((uint8)BitSize + LeftShift) >> (uint8)COM_THREE_BIT;
        if((((uint8)BitSize + LeftShift) & (uint8)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte - 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - 1] |= (uint8)((ValueTemp >> RightShift) & (uint8)MaskMsb);
        }
    }
}

/**********************************************S8 Write**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_LittleS8
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleS8
(
    P2CONST(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint8 ByteSize;
    uint8 StartByte;
    uint8 LeftShift;
    uint8 RightShift;
    sint8 ValueTemp = (sint8)0;

    ValueTemp = (*ValuePtr & COM_MASK_8(BitSize));
    StartByte = (uint8)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        PduPtr[StartByte] = (uint8)ValueTemp;
    }
    else
    {
        LeftShift = (uint8)(StartBit & COM_REMAIN_MASK);
        RightShift = (uint8)COM_BYTE_SIZE - LeftShift;
        ByteSize = ((uint8)BitSize + LeftShift) >> (uint8)COM_THREE_BIT;
        if((((uint8)BitSize + LeftShift) & (uint8)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)((uint8)ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)((uint8)ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte + 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + 1] |= (uint8)(((uint8)ValueTemp >> RightShift) & (uint8)MaskMsb);
        }
    }
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_BigS8
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigS8
(
    P2CONST(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint8 ByteSize;
    uint8 StartByte;
    uint8 LeftShift;
    uint8 RightShift;
    sint8 ValueTemp = (sint8)0;

    ValueTemp = (*ValuePtr & COM_MASK_8(BitSize));
    StartByte = (uint8)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        PduPtr[StartByte] = (uint8)ValueTemp;
    }
    else
    {
        LeftShift = (uint8)(StartBit & COM_REMAIN_MASK);
        RightShift = (uint8)COM_BYTE_SIZE - LeftShift;
        ByteSize = ((uint8)BitSize + LeftShift) >> (uint8)COM_THREE_BIT;

        if((((uint8)BitSize + LeftShift) & (uint8)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)((uint8)ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskMsb;
            PduPtr[StartByte] |= (uint8)((uint8)ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte - 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - 1] |= (uint8)(((uint8)ValueTemp >> RightShift) & (uint8)MaskMsb);

        }
    }
}

/**********************************************U16 Write**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_LittleU16
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleU16
(
    P2CONST(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint16 ByteSize;
    uint16 StartByte;
    uint16 LeftShift;
    uint16 RightShift;
    uint16 TempShift = (uint16)0;
    uint16 ValueTemp = (uint16)0;
    uint16 i;

    ValueTemp = (*ValuePtr & COM_MASK_16(BitSize));
    StartByte = (uint16)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint16)BitSize >> (uint16)COM_THREE_BIT;
        for(i = (uint16)0; i < ByteSize; i++)
        {
            PduPtr[StartByte + i] = (uint8)(((uint16)ValueTemp) >> TempShift);
            TempShift += (uint16)COM_BYTE_SIZE;
        }
    }
    else
    {
        LeftShift = StartBit & (uint16)COM_REMAIN_MASK;
        RightShift = (uint16)COM_BYTE_SIZE - LeftShift;
        ByteSize = (BitSize + LeftShift) >> (uint16)COM_THREE_BIT;

        if(((BitSize + LeftShift) & (uint16)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte + 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + 1] |= (uint8)((ValueTemp >> RightShift) & (uint16)MaskMsb);
        }
        else if(ByteSize == 3)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2*/
            TempShift = RightShift;
            PduPtr[StartByte + 1] &= (uint8)0;
            PduPtr[StartByte + 1] |= (uint8)(ValueTemp >> TempShift);
            /*Byte3*/
            TempShift += (uint16)COM_BYTE_SIZE;
            PduPtr[StartByte + 2] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + 2] |= (uint8)((ValueTemp >> TempShift) & (uint16)MaskMsb);
        }
    }
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_BigU16
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigU16
(
    P2CONST(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint16 ByteSize;
    uint16 StartByte;
    uint16 LeftShift;
    uint16 RightShift;
    uint16 TempShift = (uint16)0;
    uint16 ValueTemp = (uint16)0;
    uint16 i;

    ValueTemp = (*ValuePtr & COM_MASK_16(BitSize));
    StartByte = (uint16)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint16)BitSize >> (uint16)COM_THREE_BIT;
        for(i = (uint16)0; i < ByteSize; i++)
        {
            PduPtr[StartByte - i] = (uint8)(((uint16)ValueTemp) >> TempShift);
            TempShift += (uint16)COM_BYTE_SIZE;
        }
    }
    else
    {
        LeftShift = StartBit & (uint16)COM_REMAIN_MASK;
        RightShift = (uint16)COM_BYTE_SIZE - LeftShift;
        ByteSize = (BitSize + LeftShift) >> (uint16)COM_THREE_BIT;

        if(((BitSize + LeftShift) & (uint16)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte - 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - 1] |= (uint8)((ValueTemp >> RightShift) & (uint16)MaskMsb);
        }
        else if(ByteSize == 3)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2*/
            TempShift = RightShift;
            PduPtr[StartByte - 1] &= (uint8)0;
            PduPtr[StartByte - 1] |= (uint8)(ValueTemp >> TempShift);
            /*Byte3*/
            TempShift += (uint16)COM_BYTE_SIZE;
            PduPtr[StartByte - 2] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - 2] |= (uint8)((ValueTemp >> TempShift) & (uint16)MaskMsb);
        }
    }
}

/**********************************************S16 Write**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_LittleS16
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleS16
(
    P2CONST(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint16 ByteSize;
    uint16 StartByte;
    uint16 LeftShift;
    uint16 RightShift;
    uint16 TempShift = (uint16)0;
    uint16 i;
    sint16 ValueTemp = (sint16)0;


    ValueTemp = (*ValuePtr & COM_MASK_16(BitSize));
    StartByte = (uint16)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint16)BitSize >> (uint16)COM_THREE_BIT;
        for(i = (uint16)0; i < ByteSize; i++)
        {
            PduPtr[StartByte + i] = (uint8)(((uint16)ValueTemp) >> TempShift);
            TempShift += (uint16)COM_BYTE_SIZE;
        }
    }
    else
    {
        LeftShift = StartBit & (uint16)COM_REMAIN_MASK;
        RightShift = (uint16)COM_BYTE_SIZE - LeftShift;
        ByteSize = (BitSize + LeftShift) >> (uint16)COM_THREE_BIT;

        if(((BitSize + LeftShift) & (uint16)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)((uint16)ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)((uint16)ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte + 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + 1] |= (uint8)(((uint16)ValueTemp >> RightShift) & (uint16)MaskMsb);
        }
        else if(ByteSize == 3)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)((uint16)ValueTemp << LeftShift);
            /*Byte2*/
            TempShift = RightShift;
            PduPtr[StartByte + 1] &= (uint8)0;
            PduPtr[StartByte + 1] |= (uint8)((uint16)ValueTemp >> TempShift);
            /*Byte3*/
            TempShift += (uint16)COM_BYTE_SIZE;
            PduPtr[StartByte + 2] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + 2] |= (uint8)(((uint16)ValueTemp >> TempShift) & (uint16)MaskMsb);
        }
    }
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_BigS16
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigS16
(
    P2CONST(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint16 ByteSize;
    uint16 StartByte;
    uint16 LeftShift;
    uint16 RightShift;
    uint16 TempShift = (uint16)0;
    uint16 i;
    sint16 ValueTemp = (sint16)0;

    ValueTemp = (*ValuePtr & COM_MASK_16(BitSize));
    StartByte = (uint16)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint16)BitSize >> (uint16)COM_THREE_BIT;
        for(i = (uint16)0; i < ByteSize; i++)
        {
            PduPtr[StartByte - i] = (uint8)(((uint16)ValueTemp) >> TempShift);
            TempShift += (uint16)COM_BYTE_SIZE;
        }
    }
    else
    {
        LeftShift = StartBit & (uint16)COM_REMAIN_MASK;
        RightShift = (uint16)COM_BYTE_SIZE - LeftShift;
        ByteSize = (BitSize + LeftShift) >> (uint16)COM_THREE_BIT;

        if(((BitSize + LeftShift) & (uint16)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)((uint16)ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)((uint16)ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte - 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - 1] |= (uint8)(((uint16)ValueTemp >> RightShift) & (uint16)MaskMsb);
        }
        else if(ByteSize == 3)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)((uint16)ValueTemp << LeftShift);
            /*Byte2*/
            TempShift = RightShift;
            PduPtr[StartByte - 1] &= (uint8)0;
            PduPtr[StartByte - 1] |= (uint8)((uint16)ValueTemp >> TempShift);
            /*Byte3*/
            TempShift += (uint16)COM_BYTE_SIZE;
            PduPtr[StartByte - 2] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - 2] |= (uint8)(((uint16)ValueTemp >> TempShift) & (uint16)MaskMsb);
        }
    }
}

/**********************************************U32 Write**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_LittleU32
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleU32
(
    P2CONST(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint32 i;
    uint32 ByteSize;
    uint32 StartByte;
    uint32 LeftShift;
    uint32 RightShift;
    uint32 TempShift = (uint32)0;
    uint32 ValueTemp = (uint32)0;

    ValueTemp = (*ValuePtr & COM_MASK_32(BitSize));
    StartByte = (uint32)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint32)BitSize >> (uint32)COM_THREE_BIT;
        for(i = (uint32)0; i < ByteSize; i++)
        {
            PduPtr[StartByte + i] = (uint8)(((uint32)ValueTemp) >> TempShift);
            TempShift += (uint32)COM_BYTE_SIZE;
        }
    }
    else
    {
        LeftShift = (uint32)StartBit & (uint32)COM_REMAIN_MASK;
        RightShift = (uint32)COM_BYTE_SIZE - LeftShift;
        ByteSize = (uint32)(BitSize + LeftShift) >> (uint32)COM_THREE_BIT;

        if((((uint32)BitSize + LeftShift) & (uint32)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte + 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + 1] |= (uint8)((ValueTemp >> RightShift) & (uint32)MaskMsb);
        }
        else if((ByteSize > 2)&&(ByteSize < 6))
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2-3/4/5*/
            TempShift = RightShift;
            for (i = (uint32)1; i < (ByteSize - (uint32)1); i++)
            {
                PduPtr[StartByte + i] &= (uint8)0;
                PduPtr[StartByte + i] |= (uint8)(ValueTemp >> TempShift);
                TempShift += (uint32)COM_BYTE_SIZE;
            }
            /*Byte3/4/5*/
            PduPtr[StartByte + i] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + i] |= (uint8)((ValueTemp >> TempShift) & (uint32)MaskMsb);
        }
    }
}


/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_BigU32
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigU32
(
    P2CONST(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint32 i;
    uint32 ByteSize;
    uint32 StartByte;
    uint32 LeftShift;
    uint32 RightShift;
    uint32 TempShift = (uint32)0;
    uint32 ValueTemp = (uint32)0;

    ValueTemp = (*ValuePtr & COM_MASK_32(BitSize));
    StartByte = (uint32)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint32)BitSize >> (uint32)COM_THREE_BIT;
        for(i = (uint32)0; i < ByteSize; i++)
        {
            PduPtr[StartByte - i] = (uint8)(((uint32)ValueTemp) >> TempShift);
            TempShift += (uint32)COM_BYTE_SIZE;
        }
    }
    else
    {
        LeftShift = (uint32)StartBit & (uint32)COM_REMAIN_MASK;
        RightShift = (uint32)COM_BYTE_SIZE - LeftShift;
        ByteSize = ((uint32)BitSize + LeftShift) >> (uint32)COM_THREE_BIT;

        if((((uint32)BitSize + LeftShift) & (uint32)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte - 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - 1] |= (uint8)((ValueTemp >> RightShift) & (uint32)MaskMsb);
        }
        else if((ByteSize > 2)&&(ByteSize < 6))
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2-3/4/5*/
            TempShift = RightShift;
            for (i = (uint32)1; i < (ByteSize - (uint32)1); i++)
            {
                PduPtr[StartByte - i] &= (uint8)0;
                PduPtr[StartByte - i] |= (uint8)(ValueTemp >> TempShift);
                TempShift += (uint32)COM_BYTE_SIZE;
            }
            /*Byte3/4/5*/
            PduPtr[StartByte - i] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - i] |= (uint8)((ValueTemp >> TempShift) & (uint32)MaskMsb);
        }
    }
}

/**********************************************S32 Write**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_LittleS32
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleS32
(
    P2CONST(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint32 i;
    uint32 ByteSize;
    uint32 StartByte;
    uint32 LeftShift;
    uint32 RightShift;
    uint32 TempShift = (uint32)0;
    sint32 ValueTemp = (sint32)0;

    ValueTemp = (*ValuePtr & COM_MASK_32(BitSize));
    StartByte = (uint32)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint32)BitSize >> (uint32)COM_THREE_BIT;
        for(i = (uint32)0; i < ByteSize; i++)
        {
            PduPtr[StartByte + i] = (uint8)(((uint32)ValueTemp) >> TempShift);
            TempShift += (uint32)COM_BYTE_SIZE;
        }
    }
    else
    {
        LeftShift = (uint32)StartBit & (uint32)COM_REMAIN_MASK;
        RightShift = (uint32)COM_BYTE_SIZE - LeftShift;
        ByteSize = (uint32)(BitSize + LeftShift) >> (uint32)COM_THREE_BIT;

        if((((uint32)BitSize + LeftShift) & (uint32)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)((uint32)ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)((uint32)ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte + 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + 1] |= (uint8)(((uint32)ValueTemp >> RightShift) & (uint32)MaskMsb);
        }
        else if((ByteSize > 2)&&(ByteSize < 6))
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)((uint32)ValueTemp << LeftShift);
            /*Byte2-3/4/5*/
            TempShift = RightShift;
            for (i = (uint32)1; i < (ByteSize - (uint32)1); i++)
            {
                PduPtr[StartByte + i] &= (uint8)0;
                PduPtr[StartByte + i] |= (uint8)((uint32)ValueTemp >> TempShift);
                TempShift += (uint32)COM_BYTE_SIZE;
            }
            /*Byte3/4/5*/
            PduPtr[StartByte + i] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + i] |= (uint8)(((uint32)ValueTemp >> TempShift) & (uint32)MaskMsb);
        }
    }
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_BigS32
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigS32
(
    P2CONST(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint32 i;
    uint32 ByteSize;
    uint32 StartByte;
    uint32 LeftShift;
    uint32 RightShift;
    uint32 TempShift = (uint32)0;
    sint32 ValueTemp = (sint32)0;

    ValueTemp = (*ValuePtr & COM_MASK_32(BitSize));
    StartByte = (uint32)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint32)BitSize >> (uint32)COM_THREE_BIT;
        for(i = (uint32)0; i < ByteSize; i++)
        {
            PduPtr[StartByte - i] = (uint8)(((uint32)ValueTemp) >> TempShift);
            TempShift += (uint32)COM_BYTE_SIZE;
        }
    }
    else
    {
        LeftShift = (uint32)StartBit & (uint32)COM_REMAIN_MASK;
        RightShift = (uint32)COM_BYTE_SIZE - LeftShift;
        ByteSize = (uint32)(BitSize + LeftShift) >> (uint32)COM_THREE_BIT;

        if((((uint32)BitSize + LeftShift) & (uint32)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)((uint32)ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)((uint32)ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte - 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - 1] |= (uint8)(((uint32)ValueTemp >> RightShift) & (uint32)MaskMsb);
        }
        else if((ByteSize > 2)&&(ByteSize < 6))
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)((uint32)ValueTemp << LeftShift);
            /*Byte2-3/4/5*/
            TempShift = RightShift;
            for (i = (uint32)1; i < (ByteSize - (uint32)1); i++)
            {
                PduPtr[StartByte - i] &= (uint8)0;
                PduPtr[StartByte - i] |= (uint8)((uint32)ValueTemp >> TempShift);
                TempShift += (uint32)COM_BYTE_SIZE;
            }
            /*Byte3/4/5*/
            PduPtr[StartByte - i] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - i] |= (uint8)(((uint32)ValueTemp >> TempShift) & (uint32)MaskMsb);
        }
    }
}

/**********************************************F32 Write**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_LittleF32
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleF32
(
    P2CONST(float32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint32 i;
    uint32 ByteSize;
    uint32 StartByte;
    uint32 LeftShift;
    uint32 RightShift;
    uint32 TempShift = (uint32)0;
    uint32 ValueTemp = (*(const uint32*)ValuePtr);

    ValueTemp = (ValueTemp & COM_MASK_32(BitSize));
    StartByte = (uint32)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint32)BitSize >> (uint32)COM_THREE_BIT;
        for(i = (uint32)0; i < ByteSize; i++)
        {
            PduPtr[StartByte + i] = (uint8)(((uint32)ValueTemp) >> TempShift);
            TempShift += (uint32)COM_BYTE_SIZE;
        }
    }
    else
    {
        LeftShift = (uint32)StartBit & (uint32)COM_REMAIN_MASK;
        RightShift = (uint32)COM_BYTE_SIZE - LeftShift;
        ByteSize = (uint32)(BitSize + LeftShift) >> (uint32)COM_THREE_BIT;

        if((((uint32)BitSize + LeftShift) & (uint32)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte + 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + 1] |= (uint8)((ValueTemp >> RightShift) & (uint32)MaskMsb);
        }
        else if((ByteSize > 2)&&(ByteSize < 6))
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2-3/4/5*/
            TempShift = RightShift;
            for (i = (uint32)1; i < (ByteSize - (uint32)1); i++)
            {
                PduPtr[StartByte + i] &= (uint8)0;
                PduPtr[StartByte + i] |= (uint8)(ValueTemp >> TempShift);
                TempShift += (uint32)COM_BYTE_SIZE;
            }
            /*Byte3/4/5*/
            PduPtr[StartByte + i] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + i] |= (uint8)((ValueTemp >> TempShift) & (uint32)MaskMsb);
        }
    }
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_BigF32
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigF32
(
    P2CONST(float32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint32 i;
    uint32 ByteSize;
    uint32 StartByte;
    uint32 LeftShift;
    uint32 RightShift;
    uint32 TempShift = (uint32)0;
    uint32 ValueTemp = (*(const uint32*)ValuePtr);

    ValueTemp = (ValueTemp & COM_MASK_32(BitSize));
    StartByte = (uint32)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint32)BitSize >> (uint32)COM_THREE_BIT;
        for(i = (uint32)0; i < ByteSize; i++)
        {
            PduPtr[StartByte - i] = (uint8)(((uint32)ValueTemp) >> TempShift);
            TempShift += (uint32)COM_BYTE_SIZE;
        }
    }
    else
    {
        LeftShift = (uint32)StartBit & (uint32)COM_REMAIN_MASK;
        RightShift = (uint32)COM_BYTE_SIZE - LeftShift;
        ByteSize = (uint32)(BitSize + LeftShift) >> (uint32)COM_THREE_BIT;

        if((((uint32)BitSize + LeftShift) & (uint32)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte - 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - 1] |= (uint8)((ValueTemp >> RightShift) & (uint32)MaskMsb);
        }
        else if((ByteSize > 2)&&(ByteSize < 6))
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2-3/4/5*/
            TempShift = RightShift;
            for (i = (uint32)1; i < (ByteSize - (uint32)1); i++)
            {
                PduPtr[StartByte - i] &= (uint8)0;
                PduPtr[StartByte - i] |= (uint8)(ValueTemp >> TempShift);
                TempShift += (uint32)COM_BYTE_SIZE;
            }
            /*Byte3/4/5*/
            PduPtr[StartByte - i] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - i] |= (uint8)((ValueTemp >> TempShift) & (uint32)MaskMsb);
        }
    }
}

/**********************************************U64 Write**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_LittleU64
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleU64
(
    P2CONST(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint64 i;
    uint64 ByteSize;
    uint64 StartByte;
    uint64 LeftShift;
    uint64 RightShift;
    uint64 TempShift = (uint64)0;
    uint64 ValueTemp = (uint64)0;

    ValueTemp = (*ValuePtr & COM_MASK_64(BitSize));
    StartByte = (uint64)StartBit >> (uint64)COM_THREE_BIT;
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint64)BitSize >> (uint64)COM_THREE_BIT;
        for(i = (uint64)0; i < ByteSize; i++)
        {
            PduPtr[StartByte + i] = (uint8)(((uint64)ValueTemp) >> TempShift);
            TempShift += (uint64)COM_BYTE_SIZE;
        }
    }
    else
    {
        LeftShift = (uint64)StartBit & (uint64)COM_REMAIN_MASK;
        RightShift = (uint64)COM_BYTE_SIZE - LeftShift;
        ByteSize = ((uint64)BitSize + LeftShift) >> (uint64)COM_THREE_BIT;

        if((((uint64)BitSize + LeftShift) & (uint64)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte + 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + 1] |= (uint8)((ValueTemp >> RightShift) & (uint64)MaskMsb);
        }
        else if((ByteSize > 2)&&(ByteSize < 10))
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2-3/4/5/6/7/8/9 */
            for (i = (uint64)1; i < (ByteSize - (uint64)1); i++)
            {
                PduPtr[StartByte + i] &= (uint8)0;
                PduPtr[StartByte + i] |= (uint8)(ValueTemp >> TempShift);
                TempShift += (uint64)COM_BYTE_SIZE;
            }
            /*Byte3/4/5/6/7/8/9*/
            PduPtr[StartByte + i] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + i] |= (uint8)((ValueTemp >> TempShift) & (uint64)MaskMsb);
        }
    }
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_BigU64
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigU64
(
    P2CONST(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint64 i;
    uint64 ByteSize;
    uint64 StartByte;
    uint64 LeftShift;
    uint64 RightShift;
    uint64 TempShift = (uint64)0;
    uint64 ValueTemp = (uint64)0;

    ValueTemp = (*ValuePtr & COM_MASK_64(BitSize));
    StartByte = (uint64)StartBit >> (uint64)COM_THREE_BIT;
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint64)BitSize >> (uint64)COM_THREE_BIT;
        for(i = (uint64)0; i < ByteSize; i++)
        {
            PduPtr[StartByte - i] = (uint8)(((uint64)ValueTemp) >> TempShift);
            TempShift += (uint64)COM_BYTE_SIZE;
        }
    }
    else
    {
        LeftShift = (uint64)StartBit & (uint64)COM_REMAIN_MASK;
        RightShift = (uint64)COM_BYTE_SIZE - LeftShift;
        ByteSize = ((uint64)BitSize + LeftShift) >> (uint64)COM_THREE_BIT;

        if((((uint64)BitSize + LeftShift) & (uint64)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte - 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - 1] |= (uint8)((ValueTemp >> RightShift) & (uint64)MaskMsb);
        }
        else if((ByteSize > 2)&&(ByteSize < 10))
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2-3/4/5/6/7/8/9 */
            TempShift = RightShift;
            for (i = (uint64)1; i < (ByteSize - (uint64)1); i++)
            {
                PduPtr[StartByte - i] &= (uint8)0;
                PduPtr[StartByte - i] |= (uint8)(ValueTemp >> TempShift);
                TempShift += (uint64)COM_BYTE_SIZE;
            }
            /*Byte3/4/5/6/7/8/9*/
            PduPtr[StartByte - i] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - i] |= (uint8)((ValueTemp >> TempShift) & (uint64)MaskMsb);
        }
    }
}

/**********************************************U64 Write**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_LittleS64
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleS64
(
    P2CONST(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint64 i;
    uint64 ByteSize;
    uint64 StartByte;
    uint64 LeftShift;
    uint64 RightShift;
    uint64 TempShift = (uint64)0;
    sint64 ValueTemp = (sint64)0;

    ValueTemp = (*ValuePtr & COM_MASK_64(BitSize));
    StartByte = (uint64)StartBit >> (uint64)COM_THREE_BIT;
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint64)BitSize >> (uint64)COM_THREE_BIT;
        for(i = (uint64)0; i < ByteSize; i++)
        {
            PduPtr[StartByte + i] = (uint8)(((uint64)ValueTemp) >> TempShift);
            TempShift += (uint64)COM_BYTE_SIZE;
        }
    }
    else
    {
        LeftShift = (uint64)StartBit & (uint64)COM_REMAIN_MASK;
        RightShift = (uint64)COM_BYTE_SIZE - LeftShift;
        ByteSize = ((uint64)BitSize + LeftShift) >> (uint64)COM_THREE_BIT;

        if((((uint64)BitSize + LeftShift) & (uint64)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)((uint64)ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)((uint64)ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte + 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + 1] |= (uint8)(((uint64)ValueTemp >> RightShift) & (uint64)MaskMsb);
        }
        else if((ByteSize > 2)&&(ByteSize < 10))
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)((uint64)ValueTemp << LeftShift);
            /*Byte2-3/4/5/6/7/8/9 */
            TempShift = RightShift;
            for (i = (uint64)1; i < (ByteSize - (uint64)1); i++)
            {
                PduPtr[StartByte + i] &= (uint8)0;
                PduPtr[StartByte + i] |= (uint8)((uint64)ValueTemp >> TempShift);
                TempShift += (uint64)COM_BYTE_SIZE;
            }
            /*Byte3/4/5/6/7/8/9*/
            PduPtr[StartByte + i] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + i] |= (uint8)(((uint64)ValueTemp >> TempShift) & (uint64)MaskMsb);
        }
    }
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_BigS64
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigS64
(
    P2CONST(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint64 i;
    uint64 ByteSize;
    uint64 StartByte;
    uint64 LeftShift;
    uint64 RightShift;
    uint64 TempShift = (uint64)0;
    sint64 ValueTemp = (sint64)0;

    ValueTemp = (*ValuePtr & COM_MASK_64(BitSize));
    StartByte = (uint64)StartBit >> (uint64)COM_THREE_BIT;
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint64)BitSize >> (uint64)COM_THREE_BIT;
        for(i = (uint64)0; i < ByteSize; i++)
        {
            PduPtr[StartByte - i] = (uint8)(((uint64)ValueTemp) >> TempShift);
            TempShift += (uint64)COM_BYTE_SIZE;
        }
    }
    else
    {
        LeftShift = (uint64)StartBit & (uint64)COM_REMAIN_MASK;
        RightShift = (uint64)COM_BYTE_SIZE - LeftShift;
        ByteSize = ((uint64)BitSize + LeftShift) >> (uint64)COM_THREE_BIT;

        if((((uint64)BitSize + LeftShift) & (uint64)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)((uint64)ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)((uint64)ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte - 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - 1] |= (uint8)(((uint64)ValueTemp >> RightShift) & (uint64)MaskMsb);
        }
        else if((ByteSize > 2)&&(ByteSize < 10))
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)((uint64)ValueTemp << LeftShift);
            /*Byte2-3/4/5/6/7/8/9 */
            TempShift = RightShift;
            for (i = (uint64)1; i < (ByteSize - (uint64)1); i++)
            {
                PduPtr[StartByte - i] &= (uint8)0;
                PduPtr[StartByte - i] |= (uint8)((uint64)ValueTemp >> TempShift);
                TempShift += (uint64)COM_BYTE_SIZE;
            }
            /*Byte3/4/5/6/7/8/9*/
            PduPtr[StartByte - i] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - i] |= (uint8)(((uint64)ValueTemp >> TempShift) & (uint64)MaskMsb);
        }
    }
}

/**********************************************F64 Write**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_LittleF64
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_LittleF64
(
    P2CONST(float64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint64 i;
    uint64 ByteSize;
    uint64 StartByte;
    uint64 LeftShift;
    uint64 RightShift;
    uint64 TempShift = (uint64)0;
    uint64 ValueTemp = (*(const uint64*)ValuePtr);

    ValueTemp = (ValueTemp & COM_MASK_64(BitSize));
    StartByte = (uint64)StartBit >> (uint64)COM_THREE_BIT;
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint64)BitSize >> (uint64)COM_THREE_BIT;
        for(i = (uint64)0; i < ByteSize; i++)
        {
            PduPtr[StartByte + i] = (uint8)(((uint64)ValueTemp) >> TempShift);
            TempShift += (uint64)COM_BYTE_SIZE;
        }
    }
    else
    {
        LeftShift = (uint64)StartBit & (uint64)COM_REMAIN_MASK;
        RightShift = (uint64)COM_BYTE_SIZE - LeftShift;
        ByteSize = ((uint64)BitSize + LeftShift) >> (uint64)COM_THREE_BIT;

        if((((uint64)BitSize + LeftShift) & (uint64)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte + 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + 1] |= (uint8)((ValueTemp >> RightShift) & (uint64)MaskMsb);
        }
        else if((ByteSize > 2)&&(ByteSize < 10))
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2-3/4/5/6/7/8/9 */
            TempShift = RightShift;
            for (i = 1; (uint64)i < (ByteSize - (uint64)1); i++)
            {
                PduPtr[StartByte + i] &= (uint8)0;
                PduPtr[StartByte + i] |= (uint8)(ValueTemp >> TempShift);
                TempShift += (uint64)COM_BYTE_SIZE;
            }
            /*Byte3/4/5/6/7/8/9*/
            PduPtr[StartByte + i] &= (uint8)(~MaskMsb);
            PduPtr[StartByte + i] |= (uint8)((ValueTemp >> TempShift) & (uint64)MaskMsb);
        }
    }
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_BigF64
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   Noneyte
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_BigF64
(
    P2CONST(float64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb
)
{
    uint64 i;
    uint64 ByteSize;
    uint64 StartByte;
    uint64 LeftShift;
    uint64 RightShift;
    uint64 TempShift = (uint64)0;
    uint64 ValueTemp = (*(const uint64*)ValuePtr);

    ValueTemp = (ValueTemp & COM_MASK_64(BitSize));
    StartByte = (uint64)StartBit >> (uint64)COM_THREE_BIT;
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint64)BitSize >> (uint64)COM_THREE_BIT;
        for(i = (uint64)0; i < ByteSize; i++)
        {
            PduPtr[StartByte - i] = (uint8)(((uint64)ValueTemp) >> TempShift);
            TempShift += (uint64)COM_BYTE_SIZE;
        }
    }
    else
    {
        LeftShift = (uint64)StartBit & (uint64)COM_REMAIN_MASK;
        RightShift = (uint64)COM_BYTE_SIZE - LeftShift;
        ByteSize = ((uint64)BitSize + LeftShift) >> (uint64)COM_THREE_BIT;

        if((((uint64)BitSize + LeftShift) & (uint64)COM_REMAIN_MASK) > 0)
        {
            ByteSize++;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)(MaskLsb | (~MaskMsb));
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2*/
            PduPtr[StartByte - 1] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - 1] |= (uint8)((ValueTemp >> RightShift) & (uint64)MaskMsb);
        }
        else if((ByteSize > 2)&&(ByteSize < 10))
        {
            /*Byte1*/
            PduPtr[StartByte] &= (uint8)MaskLsb;
            PduPtr[StartByte] |= (uint8)(ValueTemp << LeftShift);
            /*Byte2-3/4/5/6/7/8/9 */
            TempShift = RightShift;
            for (i = 1; (uint64)i < (ByteSize - (uint64)1); i++)
            {
                PduPtr[StartByte - i] &= (uint8)0;
                PduPtr[StartByte - i] |= (uint8)(ValueTemp >> TempShift);
                TempShift += (uint64)COM_BYTE_SIZE;
            }
            /*Byte3/4/5/6/7/8/9*/
            PduPtr[StartByte - i] &= (uint8)(~MaskMsb);
            PduPtr[StartByte - i] |= (uint8)((ValueTemp >> TempShift) & (uint64)MaskMsb);
        }
    }
}

/**********************************************U8N Write**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal_U8N
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                ByteLength
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(void, COM_CODE) Com_WriteSignal_U8N
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    PduLengthType ByteLength,
    uint16 StartBit
)
{
    uint16 StartByte;

    StartByte = (uint16)(StartBit >> COM_THREE_BIT);

    Bsw_MemCpy(&PduPtr[StartByte], ValuePtr, (uint32)ByteLength);
}

/**********************************************U8 Read**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_LittleU8
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_LittleU8
(
    P2VAR(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint8 ByteSize;
    uint8 StartByte;
    uint8 LeftShift;
    uint8 RightShift;
    uint8 ValueTemp = (uint8)0;

    StartByte = (uint8)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ValueTemp = PduPtr[StartByte];
    }
    else
    {
        RightShift = (uint8)(StartBit & COM_REMAIN_MASK);
        ByteSize = ((uint8)BitSize + RightShift) >> (uint8)COM_THREE_BIT;
        LeftShift = (uint8)COM_BYTE_SIZE - RightShift;
        if((((uint8)BitSize + RightShift) & (uint8)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= PduPtr[StartByte] >> RightShift;
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= ((uint8)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= ((uint8)PduPtr[StartByte + 1] << LeftShift);
        }
        ValueTemp &= (uint8)Mask;
    }
    *ValuePtr = ValueTemp;
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_BigU8
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_BigU8
(
    P2VAR(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint8 ByteSize;
    uint8 StartByte;
    uint8 LeftShift;
    uint8 RightShift;
    uint8 ValueTemp = (uint8)0;

    StartByte = (uint8)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ValueTemp = PduPtr[StartByte];
    }
    else
    {
        RightShift = (uint8)(StartBit & COM_REMAIN_MASK);
        ByteSize = ((uint8)BitSize + RightShift) >> (uint8)COM_THREE_BIT;
        LeftShift = (uint8)COM_BYTE_SIZE - RightShift;
        if((((uint8)BitSize + RightShift) & (uint8)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= PduPtr[StartByte] >> RightShift;
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= ((uint8)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= ((uint8)PduPtr[StartByte - 1] << LeftShift);
        }
        ValueTemp &= (uint8)Mask;
    }
    *ValuePtr = ValueTemp;
}

/**********************************************S8 Read**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_LittleS8
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_LittleS8
(
    P2VAR(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint8 ByteSize;
    uint8 StartByte;
    uint8 LeftShift;
    uint8 RightShift;
    sint8 ValueTemp = (sint8)0;

    StartByte = (uint8)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ValueTemp = PduPtr[StartByte];
    }
    else
    {
        RightShift = (uint8)(StartBit & COM_REMAIN_MASK);
        ByteSize = ((uint8)BitSize + RightShift) >> (uint8)COM_THREE_BIT;
        LeftShift = (uint8)COM_BYTE_SIZE - RightShift;
        if((((uint8)BitSize + RightShift) & (uint8)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= (sint8)(PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= (sint8)((uint8)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= (sint8)((uint8)PduPtr[StartByte + 1] << LeftShift);
        }
        ValueTemp &= (sint8)Mask;
    }
    *ValuePtr = ValueTemp;
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_BigS8
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_BigS8
(
    P2VAR(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint8 ByteSize;
    uint8 StartByte;
    uint8 LeftShift;
    uint8 RightShift;
    sint8 ValueTemp = (sint8)0;

    StartByte = (uint8)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ValueTemp = PduPtr[StartByte];
    }
    else
    {
        RightShift = (uint8)(StartBit & COM_REMAIN_MASK);
        ByteSize = ((uint8)BitSize + RightShift) >> (uint8)COM_THREE_BIT;
        LeftShift = (uint8)COM_BYTE_SIZE - RightShift;
        if((((uint8)BitSize + RightShift) & (uint8)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= (sint8)(PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= (sint8)((uint8)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= (sint8)((uint8)PduPtr[StartByte - 1] << LeftShift);
        }
        ValueTemp &= (sint8)Mask;
    }
    *ValuePtr = ValueTemp;
}

/**********************************************U16 Read**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_LittleU16
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_LittleU16
(
    P2VAR(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint16 ByteSize;
    uint16 StartByte;
    uint16 LeftShift;
    uint16 RightShift;
    uint16 TempShift = (uint16)0;
    uint16 i;
    uint16 ValueTemp = (uint16)0;

    StartByte = (uint16)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint16)BitSize >> (uint16)COM_THREE_BIT;
        for(i = (uint16)0; i < ByteSize; i++)
        {
            ValueTemp |= ((uint16)PduPtr[StartByte + i] << TempShift);
            TempShift += (uint16)COM_BYTE_SIZE;
        }
    }
    else
    {
        RightShift = StartBit & (uint16)COM_REMAIN_MASK;
        ByteSize = (BitSize + RightShift) >> (uint16)COM_THREE_BIT;
        LeftShift = (uint16)COM_BYTE_SIZE - RightShift;
        if(((BitSize + RightShift) & (uint16)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= ((uint16)PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= ((uint16)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= ((uint16)PduPtr[StartByte + 1] << LeftShift);
        }
        else if(ByteSize == 3)
        {
            /*Byte1*/
            ValueTemp |= ((uint16)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            TempShift = LeftShift;
            ValueTemp |= ((uint16)PduPtr[StartByte + 1] << TempShift);
            /*Byte3*/
            TempShift += (uint16)COM_BYTE_SIZE;
            ValueTemp |= ((uint16)PduPtr[StartByte + 2] << TempShift);
        }
        ValueTemp &= (uint16)Mask;
    }
    *ValuePtr = ValueTemp;
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_BigU16
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_BigU16
(
    P2VAR(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint16 ByteSize;
    uint16 StartByte;
    uint16 LeftShift;
    uint16 RightShift;
    uint16 TempShift = (uint16)0;
    uint16 i;
    uint16 ValueTemp = (uint16)0;

    StartByte = (uint16)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint16)BitSize >> (uint16)COM_THREE_BIT;
        for(i = (uint16)0; i < ByteSize; i++)
        {
            ValueTemp |= ((uint16)PduPtr[StartByte - i] << TempShift);
            TempShift += (uint16)COM_BYTE_SIZE;
        }
    }
    else
    {
        RightShift = StartBit & (uint16)COM_REMAIN_MASK;
        ByteSize = (BitSize + RightShift) >> (uint16)COM_THREE_BIT;
        LeftShift = (uint16)COM_BYTE_SIZE - RightShift;
        if(((BitSize + RightShift) & (uint16)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= ((uint16)PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= ((uint16)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= ((uint16)PduPtr[StartByte - 1] << LeftShift);
        }
        else if(ByteSize == 3)
        {
            /*Byte1*/
            ValueTemp |= ((uint16)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            TempShift = LeftShift;
            ValueTemp |= ((uint16)PduPtr[StartByte - 1] << TempShift);
            /*Byte3*/
            TempShift += (uint16)COM_BYTE_SIZE;
            ValueTemp |= ((uint16)PduPtr[StartByte - 2] << TempShift);
        }
        ValueTemp &= (uint16)Mask;
    }
    *ValuePtr = ValueTemp;
}

/**********************************************S16 Read**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_LittleS16
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_LittleS16
(
    P2VAR(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint16 ByteSize;
    uint16 StartByte;
    uint16 LeftShift;
    uint16 RightShift;
    uint16 TempShift = (uint16)0;
    uint16 i;
    sint16 ValueTemp = (sint16)0;

    StartByte = (uint16)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint16)BitSize >> (uint16)COM_THREE_BIT;
        for(i = (uint16)0; i < ByteSize; i++)
        {
            ValueTemp |= ((sint16)PduPtr[StartByte + i] << TempShift);
            TempShift += (uint16)COM_BYTE_SIZE;
        }
    }
    else
    {
        RightShift = StartBit & (uint16)COM_REMAIN_MASK;
        ByteSize = (BitSize + RightShift) >> (uint16)COM_THREE_BIT;
        LeftShift = (uint16)COM_BYTE_SIZE - RightShift;
        if(((BitSize + RightShift) & (uint16)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= (sint16)((uint16)PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= (sint16)(((uint16)PduPtr[StartByte] >> RightShift));
            /*Byte2*/
            ValueTemp |= (sint16)(((uint16)PduPtr[StartByte + 1] << LeftShift));
        }
        else if(ByteSize == 3)
        {
            /*Byte1*/
            ValueTemp |= (sint16)(((uint16)PduPtr[StartByte] >> RightShift));
            /*Byte2*/
            TempShift = LeftShift;
            ValueTemp |= (sint16)(((uint16)PduPtr[StartByte + 1] << TempShift));
            /*Byte3*/
            TempShift += (uint16)COM_BYTE_SIZE;
            ValueTemp |= (sint16)(((uint16)PduPtr[StartByte + 2] << TempShift));
        }
        ValueTemp &= (sint16)Mask;
    }
    *ValuePtr = ValueTemp;
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_BigS16
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_BigS16
(
    P2VAR(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint16 ByteSize;
    uint16 StartByte;
    uint16 LeftShift;
    uint16 RightShift;
    uint16 TempShift = (uint16)0;
    uint16 i;
    sint16 ValueTemp = (sint16)0;

    StartByte = (uint16)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint16)BitSize >> (uint16)COM_THREE_BIT;
        for(i = (uint16)0; i < ByteSize; i++)
        {
            ValueTemp |= ((sint16)PduPtr[StartByte - i] << TempShift);
            TempShift += (uint16)COM_BYTE_SIZE;
        }
    }
    else
    {
        RightShift = StartBit & (uint16)COM_REMAIN_MASK;
        ByteSize = (BitSize + RightShift) >> (uint16)COM_THREE_BIT;
        LeftShift = (uint16)COM_BYTE_SIZE - RightShift;
        if(((BitSize + RightShift) & (uint16)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= (sint16)((uint16)PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= (sint16)(((uint16)PduPtr[StartByte] >> RightShift));
            /*Byte2*/
            ValueTemp |= (sint16)(((uint16)PduPtr[StartByte - 1] << LeftShift));
        }
        else if(ByteSize == 3)
        {
            /*Byte1*/
            ValueTemp |= (sint16)(((uint16)PduPtr[StartByte] >> RightShift));
            /*Byte2*/
            TempShift = LeftShift;
            ValueTemp |= (sint16)(((uint16)PduPtr[StartByte - 1] << TempShift));
            /*Byte3*/
            TempShift += (uint16)COM_BYTE_SIZE;
            ValueTemp |= (sint16)(((uint16)PduPtr[StartByte - 2] << TempShift));
        }
        ValueTemp &= (sint16)Mask;
    }
    *ValuePtr = ValueTemp;
}

/**********************************************U32 Read**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_LittleU32
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_LittleU32
(
    P2VAR(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint32 i;
    uint32 ByteSize;
    uint32 StartByte;
    uint32 LeftShift;
    uint32 RightShift;
    uint32 TempShift = (uint32)0;
    uint32 ValueTemp = (uint32)0;

    StartByte = (uint32)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint32)BitSize >> (uint32)COM_THREE_BIT;
        for(i = (uint32)0; i < ByteSize; i++)
        {
            ValueTemp |= ((uint32)PduPtr[StartByte + i] << TempShift);
            TempShift += (uint32)COM_BYTE_SIZE;
        }
    }
    else
    {
        RightShift = (uint32)StartBit & (uint32)COM_REMAIN_MASK;
        ByteSize = ((uint32)BitSize + RightShift) >> (uint32)COM_THREE_BIT;
        LeftShift = (uint32)COM_BYTE_SIZE - RightShift;
        if((((uint32)BitSize + RightShift) & (uint32)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= ((uint32)PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= ((uint32)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= ((uint32)PduPtr[StartByte + 1] << LeftShift);
        }
        else if((ByteSize > 2)&&(ByteSize < 6))
        {
            /*Byte1*/
            ValueTemp |= ((uint32)PduPtr[StartByte] >> RightShift);
            /*Byte2-3/4/5*/
            TempShift = LeftShift;
            for (i = (uint32)1; i < (ByteSize - (uint32)1); i++)
            {
                ValueTemp |= ((uint32)PduPtr[StartByte + i] << TempShift);
                TempShift += (uint32)COM_BYTE_SIZE;
            }
            /*Byte3/4/5*/
            ValueTemp |= ((uint32)PduPtr[StartByte + i] << TempShift);
        }
        ValueTemp &= (uint32)Mask;
    }
    *ValuePtr = ValueTemp;
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_BigU32
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_BigU32
(
    P2VAR(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint32 i;
    uint32 ByteSize;
    uint32 StartByte;
    uint32 LeftShift;
    uint32 RightShift;
    uint32 TempShift = (uint32)0;
    uint32 ValueTemp = (uint32)0;

    StartByte = (uint32)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint32)BitSize >> (uint32)COM_THREE_BIT;
        for(i = (uint32)0; i < ByteSize; i++)
        {
            ValueTemp |= ((uint32)PduPtr[StartByte - i] << TempShift);
            TempShift += (uint32)COM_BYTE_SIZE;
        }
    }
    else
    {
        RightShift = (uint32)StartBit & (uint32)COM_REMAIN_MASK;
        ByteSize = ((uint32)BitSize + RightShift) >> (uint32)COM_THREE_BIT;
        LeftShift = (uint32)COM_BYTE_SIZE - RightShift;
        if((((uint32)BitSize + RightShift) & (uint32)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= ((uint32)PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= ((uint32)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= ((uint32)PduPtr[StartByte - 1] << LeftShift);
        }
        else if((ByteSize > 2)&&(ByteSize < 6))
        {
            /*Byte1*/
            ValueTemp |= ((uint32)PduPtr[StartByte] >> RightShift);
            /*Byte2-3/4/5*/
            TempShift = LeftShift;
            for (i = (uint32)1; i < (ByteSize - (uint32)1); i++)
            {
                ValueTemp |= ((uint32)PduPtr[StartByte - i] << TempShift);
                TempShift += (uint32)COM_BYTE_SIZE;
            }
            /*Byte3/4/5*/
            ValueTemp |= ((uint32)PduPtr[StartByte - i] << TempShift);
        }
        ValueTemp &= (uint32)Mask;
    }
    *ValuePtr = ValueTemp;
}

/**********************************************S32 Read**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_LittleS32
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_LittleS32
(
    P2VAR(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint32 i;
    uint32 ByteSize;
    uint32 StartByte;
    uint32 LeftShift;
    uint32 RightShift;
    uint32 TempShift = (uint32)0;
    sint32 ValueTemp = (sint32)0;

    StartByte = (uint32)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint32)BitSize >> (uint32)COM_THREE_BIT;
        for(i = (uint32)0; i < ByteSize; i++)
        {
            ValueTemp |= ((sint32)PduPtr[StartByte + i] << TempShift);
            TempShift += (uint32)COM_BYTE_SIZE;
        }
    }
    else
    {
        RightShift = (uint32)StartBit & (uint32)COM_REMAIN_MASK;
        ByteSize = ((uint32)BitSize + RightShift) >> (uint32)COM_THREE_BIT;
        LeftShift = (uint32)COM_BYTE_SIZE - RightShift;
        if((((uint32)BitSize + RightShift) & (uint32)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= (sint32)((uint32)PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= (sint32)((uint32)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= (sint32)((uint32)PduPtr[StartByte + 1] << LeftShift);
        }
        else if((ByteSize > 2)&&(ByteSize < 6))
        {
            /*Byte1*/
            ValueTemp |= (sint32)((uint32)PduPtr[StartByte] >> RightShift);
            /*Byte2-3/4/5*/
            TempShift = LeftShift;
            for (i = (uint32)1; i < (ByteSize - (uint32)1); i++)
            {
                ValueTemp |= (sint32)((uint32)PduPtr[StartByte + i] << TempShift);
                TempShift += (uint32)COM_BYTE_SIZE;
            }
            /*Byte3/4/5*/
            ValueTemp |= (sint32)((uint32)PduPtr[StartByte + i] << TempShift);
        }
        ValueTemp &= (sint32)Mask;
    }
    *ValuePtr = ValueTemp;
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_BigS32
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_BigS32
(
    P2VAR(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint32 i;
    uint32 ByteSize;
    uint32 StartByte;
    uint32 LeftShift;
    uint32 RightShift;
    uint32 TempShift = (uint32)0;
    sint32 ValueTemp = (sint32)0;

    StartByte = (uint32)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint32)BitSize >> (uint32)COM_THREE_BIT;
        for(i = (uint32)0; i < ByteSize; i++)
        {
            ValueTemp |= ((sint32)PduPtr[StartByte - i] << TempShift);
            TempShift += (uint32)COM_BYTE_SIZE;
        }
    }
    else
    {
        RightShift = (uint32)StartBit & (uint32)COM_REMAIN_MASK;
        ByteSize = ((uint32)BitSize + RightShift) >> (uint32)COM_THREE_BIT;
        LeftShift = (uint32)COM_BYTE_SIZE - RightShift;
        if((((uint32)BitSize + RightShift) & (uint32)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= (sint32)((uint32)PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= (sint32)((uint32)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= (sint32)((uint32)PduPtr[StartByte - 1] << LeftShift);
        }
        else if((ByteSize > 2)&&(ByteSize < 6))
        {
            /*Byte1*/
            ValueTemp |= (sint32)((uint32)PduPtr[StartByte] >> RightShift);
            /*Byte2-3/4/5*/
            TempShift = LeftShift;
            for (i = (uint32)1; i < (ByteSize - (uint32)1); i++)
            {
                ValueTemp |= (sint32)((uint32)PduPtr[StartByte - i] << TempShift);
                TempShift += (uint32)COM_BYTE_SIZE;
            }
            /*Byte3/4/5*/
            ValueTemp |= (sint32)((uint32)PduPtr[StartByte - i] << TempShift);
        }
        ValueTemp &= (sint32)Mask;
    }
    *ValuePtr = ValueTemp;
}

/**********************************************F32 Read**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_LittleF32
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_LittleF32
(
    P2VAR(float32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint32 i;
    uint32 ByteSize;
    uint32 StartByte;
    uint32 LeftShift;
    uint32 RightShift;
    uint32 TempShift = (uint32)0;
    uint32 ValueTemp = (uint32)0;
    float32 *ValuePtrTemp = (float32*)(&ValueTemp);

    StartByte = (uint32)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint32)BitSize >> (uint32)COM_THREE_BIT;
        for(i = (uint32)0; i < ByteSize; i++)
        {
            ValueTemp |= ((uint32)PduPtr[StartByte + i] << TempShift);
            TempShift += (uint32)COM_BYTE_SIZE;
        }
    }
    else
    {
        RightShift = (uint32)StartBit & (uint32)COM_REMAIN_MASK;
        ByteSize = ((uint32)BitSize + RightShift) >> (uint32)COM_THREE_BIT;
        LeftShift = (uint32)COM_BYTE_SIZE - RightShift;
        if((((uint32)BitSize + RightShift) & (uint32)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= ((uint32)PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= ((uint32)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= ((uint32)PduPtr[StartByte + 1] << LeftShift);
        }
        else if((ByteSize > 2)&&(ByteSize < 6))
        {
            /*Byte1*/
            ValueTemp |= ((uint32)PduPtr[StartByte] >> RightShift);
            /*Byte2-3/4/5*/
            TempShift = LeftShift;
            for (i = (uint32)1; i < (ByteSize - (uint32)1); i++)
            {
                ValueTemp |= ((uint32)PduPtr[StartByte + i] << TempShift);
                TempShift += (uint32)COM_BYTE_SIZE;
            }
            /*Byte3/4/5*/
            ValueTemp |= ((uint32)PduPtr[StartByte + i] << TempShift);
        }
        ValueTemp &= (uint32)Mask;
    }
    *ValuePtr = *ValuePtrTemp;
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_BigF32
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_BigF32
(
    P2VAR(float32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint32 i;
    uint32 ByteSize;
    uint32 StartByte;
    uint32 LeftShift;
    uint32 RightShift;
    uint32 TempShift = (uint32)0;
    uint32 ValueTemp = (uint32)0;
    float32 *ValuePtrTemp = (float32*)(&ValueTemp);

    StartByte = (uint32)(StartBit >> COM_THREE_BIT);
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint32)BitSize >> (uint32)COM_THREE_BIT;
        for(i = (uint32)0; i < ByteSize; i++)
        {
            ValueTemp |= ((uint32)PduPtr[StartByte - i] << TempShift);
            TempShift += (uint32)COM_BYTE_SIZE;
        }
    }
    else
    {
        RightShift = (uint32)StartBit & (uint32)COM_REMAIN_MASK;
        ByteSize = ((uint32)BitSize + RightShift) >> (uint32)COM_THREE_BIT;
        LeftShift = (uint32)COM_BYTE_SIZE - RightShift;
        if((((uint32)BitSize + RightShift) & (uint32)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= ((uint32)PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= ((uint32)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= ((uint32)PduPtr[StartByte - 1] << LeftShift);
        }
        else if((ByteSize > 2)&&(ByteSize < 6))
        {
            /*Byte1*/
            ValueTemp |= ((uint32)PduPtr[StartByte] >> RightShift);
            /*Byte2-3/4/5*/
            TempShift = LeftShift;
            for (i = (uint32)1; i < (ByteSize - (uint32)1); i++)
            {
                ValueTemp |= ((uint32)PduPtr[StartByte - i] << TempShift);
                TempShift += (uint32)COM_BYTE_SIZE;
            }
            /*Byte3/4/5*/
            ValueTemp |= ((uint32)PduPtr[StartByte - i] << TempShift);
        }
        ValueTemp &= (uint32)Mask;
    }
    *ValuePtr = *ValuePtrTemp;
}

/**********************************************U64 Read**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_LittleU64
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_LittleU64
(
    P2VAR(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint64 i;
    uint64 ByteSize;
    uint64 StartByte;
    uint64 LeftShift;
    uint64 RightShift;
    uint64 TempShift = (uint64)0;
    uint64 ValueTemp = (uint64)0;

    StartByte = (uint64)StartBit >> (uint64)COM_THREE_BIT;
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint64)BitSize >> (uint64)COM_THREE_BIT;
        for(i = (uint64)0; i < ByteSize; i++)
        {
            ValueTemp |= ((uint64)PduPtr[StartByte + i] << TempShift);
            TempShift += (uint64)COM_BYTE_SIZE;
        }
    }
    else
    {
        RightShift = (uint64)StartBit & (uint64)COM_REMAIN_MASK;
        ByteSize = ((uint64)BitSize + RightShift) >> (uint64)COM_THREE_BIT;
        LeftShift = (uint64)COM_BYTE_SIZE - RightShift;
        if((((uint64)BitSize + RightShift) & (uint64)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= ((uint64)PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= ((uint64)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= ((uint64)PduPtr[StartByte + 1] << LeftShift);
        }
        else if((ByteSize > 2)&&(ByteSize < 10))
        {
            /*Byte1*/
            ValueTemp |= ((uint64)PduPtr[StartByte] >> RightShift);
            /*Byte2-3/4/5/6/7/8/9*/
            TempShift = LeftShift;
            for (i = (uint64)1; i < (ByteSize - (uint64)1); i++)
            {
                ValueTemp |= ((uint64)PduPtr[StartByte + i] << TempShift);
                TempShift += (uint64)COM_BYTE_SIZE;
            }
            /*Byte3/4/5/6/7/8/9*/
            ValueTemp |= ((uint64)PduPtr[StartByte + i] << TempShift);
        }
        ValueTemp &= (uint64)Mask;
    }
    *ValuePtr = ValueTemp;
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_BigU64
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_BigU64
(
    P2VAR(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint64 i;
    uint64 ByteSize;
    uint64 StartByte;
    uint64 LeftShift;
    uint64 RightShift;
    uint64 TempShift = (uint64)0;
    uint64 ValueTemp = (uint64)0;

    StartByte = (uint64)StartBit >> (uint64)COM_THREE_BIT;
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint64)BitSize >> (uint64)COM_THREE_BIT;
        for(i = (uint64)0; i < ByteSize; i++)
        {
            ValueTemp |= ((uint64)PduPtr[StartByte - i] << TempShift);
            TempShift += (uint64)COM_BYTE_SIZE;
        }
    }
    else
    {
        RightShift = (uint64)StartBit & (uint64)COM_REMAIN_MASK;
        ByteSize = ((uint64)BitSize + RightShift) >> (uint64)COM_THREE_BIT;
        LeftShift = (uint64)COM_BYTE_SIZE - RightShift;
        if((((uint64)BitSize + RightShift) & (uint64)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= ((uint64)PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= ((uint64)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= ((uint64)PduPtr[StartByte - 1] << LeftShift);
        }
        else if((ByteSize > 2)&&(ByteSize < 10))
        {
            /*Byte1*/
            ValueTemp |= ((uint64)PduPtr[StartByte] >> RightShift);
            /*Byte2-3/4/5/6/7/8/9*/
            TempShift = LeftShift;
            for (i = (uint64)1; i < (ByteSize - (uint64)1); i++)
            {
                ValueTemp |= ((uint64)PduPtr[StartByte - i] << TempShift);
                TempShift += (uint64)COM_BYTE_SIZE;
            }
            /*Byte3/4/5/6/7/8/9*/
            ValueTemp |= ((uint64)PduPtr[StartByte - i] << TempShift);
        }
        ValueTemp &= (uint64)Mask;
    }
    *ValuePtr = ValueTemp;
}

/**********************************************S64 Read**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_LittleS64
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_LittleS64
(
    P2VAR(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint64 i;
    uint64 ByteSize;
    uint64 StartByte;
    uint64 LeftShift;
    uint64 RightShift;
    uint64 TempShift = (uint64)0;
    sint64 ValueTemp = (sint64)0;

    StartByte = (uint64)StartBit >> (uint64)COM_THREE_BIT;
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint64)BitSize >> (uint64)COM_THREE_BIT;
        for(i = (uint64)0; i < ByteSize; i++)
        {
            ValueTemp |= ((sint64)PduPtr[StartByte + i] << TempShift);
            TempShift += (uint64)COM_BYTE_SIZE;
        }
    }
    else
    {
        RightShift = (uint64)StartBit & (uint64)COM_REMAIN_MASK;
        ByteSize = ((uint64)BitSize + RightShift) >> (uint64)COM_THREE_BIT;
        LeftShift = (uint64)COM_BYTE_SIZE - RightShift;
        if((((uint64)BitSize + RightShift) & (uint64)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= (sint64)((uint64)PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= (sint64)((uint64)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= (sint64)((uint64)PduPtr[StartByte + 1] << LeftShift);
        }
        else if((ByteSize > 2)&&(ByteSize < 10))
        {
            /*Byte1*/
            ValueTemp |= (sint64)((uint64)PduPtr[StartByte] >> RightShift);
            /*Byte2-3/4/5/6/7/8/9*/
            TempShift = LeftShift;
            for (i = (uint64)1; i < (ByteSize - (uint64)1); i++)
            {
                ValueTemp |= (sint64)((uint64)PduPtr[StartByte + i] << TempShift);
                TempShift += (uint64)COM_BYTE_SIZE;
            }
            /*Byte3/4/5/6/7/8/9*/
            ValueTemp |= (sint64)((uint64)PduPtr[StartByte + i] << TempShift);
        }
        ValueTemp &= (sint64)Mask;
    }
    *ValuePtr = ValueTemp;
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_BigS64
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_BigS64
(
    P2VAR(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint64 i;
    uint64 ByteSize;
    uint64 StartByte;
    uint64 LeftShift;
    uint64 RightShift;
    uint64 TempShift = (uint64)0;
    sint64 ValueTemp = (sint64)0;

    StartByte = (uint64)StartBit >> (uint64)COM_THREE_BIT;
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint64)BitSize >> (uint64)COM_THREE_BIT;
        for(i = (uint64)0; i < ByteSize; i++)
        {
            ValueTemp |= ((sint64)PduPtr[StartByte - i] << TempShift);
            TempShift += (uint64)COM_BYTE_SIZE;
        }
    }
    else
    {
        RightShift = (uint64)StartBit & (uint64)COM_REMAIN_MASK;
        ByteSize = ((uint64)BitSize + RightShift) >> (uint64)COM_THREE_BIT;
        LeftShift = (uint64)COM_BYTE_SIZE - RightShift;
        if((((uint64)BitSize + RightShift) & (uint64)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= (sint64)((uint64)PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= (sint64)((uint64)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= (sint64)((uint64)PduPtr[StartByte - 1] << LeftShift);
        }
        else if((ByteSize > 2)&&(ByteSize < 10))
        {
            /*Byte1*/
            ValueTemp |= (sint64)((uint64)PduPtr[StartByte] >> RightShift);
            /*Byte2-3/4/5/6/7/8/9*/
            TempShift = LeftShift;
            for (i = (uint64)1; i < (ByteSize - (uint64)1); i++)
            {
                ValueTemp |= (sint64)((uint64)PduPtr[StartByte - i] << TempShift);
                TempShift += (uint64)COM_BYTE_SIZE;
            }
            /*Byte3/4/5/6/7/8/9*/
            ValueTemp |= (sint64)((uint64)PduPtr[StartByte - i] << TempShift);
        }
        ValueTemp &= (sint64)Mask;
    }
    *ValuePtr = ValueTemp;
}

/**********************************************F64 Read**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_LittleF64
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_LittleF64
(
    P2VAR(float64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint64 i;
    uint64 ByteSize;
    uint64 StartByte;
    uint64 LeftShift;
    uint64 RightShift;
    uint64 TempShift = (uint64)0;
    uint64 ValueTemp = (uint64)0;
    float64 *ValuePtrTemp = (float64*)(&ValueTemp);

    StartByte = (uint64)StartBit >> (uint64)COM_THREE_BIT;
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint64)BitSize >> (uint64)COM_THREE_BIT;
        for(i = (uint64)0; i < ByteSize; i++)
        {
            ValueTemp |= ((uint64)PduPtr[StartByte + i] << TempShift);
            TempShift += (uint64)COM_BYTE_SIZE;
        }
    }
    else
    {
        RightShift = (uint64)StartBit & (uint64)COM_REMAIN_MASK;
        ByteSize = ((uint64)BitSize + RightShift) >> (uint64)COM_THREE_BIT;
        LeftShift = (uint64)COM_BYTE_SIZE - RightShift;
        if((((uint64)BitSize + RightShift) & (uint64)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= ((uint64)PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= ((uint64)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= ((uint64)PduPtr[StartByte + 1] << LeftShift);
        }
        else if((ByteSize > 2)&&(ByteSize < 10))
        {
            /*Byte1*/
            ValueTemp |= ((uint64)PduPtr[StartByte] >> RightShift);
            /*Byte2-3/4/5/6/7/8/9*/
            TempShift = LeftShift;
            for (i = (uint64)1; i < (ByteSize - (uint64)1); i++)
            {
                ValueTemp |= ((uint64)PduPtr[StartByte + i] << TempShift);
                TempShift += (uint64)COM_BYTE_SIZE;
            }
            /*Byte3/4/5/6/7/8/9*/
            ValueTemp |= ((uint64)PduPtr[StartByte + i] << TempShift);
        }
        ValueTemp &= (uint64)Mask;
    }
    *ValuePtr = *ValuePtrTemp;
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_BigF64
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_BigF64
(
    P2VAR(float64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint64 i;
    uint64 ByteSize;
    uint64 StartByte;
    uint64 LeftShift;
    uint64 RightShift;
    uint64 TempShift = (uint64)0;
    uint64 ValueTemp = (uint64)0;
    float64 *ValuePtrTemp = (float64*)(&ValueTemp);

    StartByte = (uint64)StartBit >> (uint64)COM_THREE_BIT;
    if(((StartBit & (uint16)COM_REMAIN_MASK) == (uint16)0) && ((BitSize & (uint16)COM_REMAIN_MASK) == (uint16)0))
    {
        ByteSize = (uint64)BitSize >> (uint64)COM_THREE_BIT;
        for(i = (uint64)0; i < ByteSize; i++)
        {
            ValueTemp |= ((uint64)PduPtr[StartByte - i] << TempShift);
            TempShift += (uint64)COM_BYTE_SIZE;
        }
    }
    else
    {
        RightShift = (uint64)StartBit & (uint64)COM_REMAIN_MASK;
        ByteSize = ((uint64)BitSize + RightShift) >> (uint64)COM_THREE_BIT;
        LeftShift = (uint64)COM_BYTE_SIZE - RightShift;
        if((((uint64)BitSize + RightShift) & (uint64)COM_REMAIN_MASK) > 0)
        {
            ByteSize++ ;
        }
        if(ByteSize == 1)
        {
            /*Byte1*/
            ValueTemp |= ((uint64)PduPtr[StartByte] >> RightShift);
        }
        else if(ByteSize == 2)
        {
            /*Byte1*/
            ValueTemp |= ((uint64)PduPtr[StartByte] >> RightShift);
            /*Byte2*/
            ValueTemp |= ((uint64)PduPtr[StartByte - 1] << LeftShift);
        }
        else if((ByteSize > 2)&&(ByteSize < 10))
        {
            /*Byte1*/
            ValueTemp |= ((uint64)PduPtr[StartByte] >> RightShift);
            /*Byte2-3/4/5/6/7/8/9*/
            TempShift = LeftShift;
            for (i = (uint64)1; i < (ByteSize - (uint64)1); i++)
            {
                ValueTemp |= ((uint64)PduPtr[StartByte - i] << TempShift);
                TempShift += (uint64)COM_BYTE_SIZE;
            }
            /*Byte3/4/5/6/7/8/9*/
            ValueTemp |= ((uint64)PduPtr[StartByte - i] << TempShift);
        }
        ValueTemp &= (uint64)Mask;
    }
    *ValuePtr = *ValuePtrTemp;
}

/**********************************************U8N Read**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal_U8N
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                ByteLength
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_ReadSignal_U8N
(
    P2VAR(uint8, AUTOMATIC, COM_VAR) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    PduLengthType ByteLength,
    uint16 StartBit
)
{
    uint16 StartByte;

    StartByte = (uint16)(StartBit >> COM_THREE_BIT);

    Bsw_MemCpy(ValuePtr, &PduPtr[StartByte], (uint32)ByteLength);
}

/**********************************************U8 Check**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CheckChangeSignal_U8
*
* Description:   Check signal for change.
*
* Inputs:        ValuePtr
*                PduPtr
*                Endianness
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_U8
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint8 NewValue = *ValuePtr;
    uint8 OldValue = 0;
    boolean ret = FALSE;

#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleU8(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigU8(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleU8(&OldValue, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigU8(&OldValue, PduPtr, BitSize, StartBit, Mask);
#endif
    if(NewValue != OldValue)
    {
        ret = TRUE;
    }
    return ret;
}

/**********************************************S8 Check**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CheckChangeSignal_S8
*
* Description:   Check signal for change.
*
* Inputs:        ValuePtr
*                PduPtr
*                Endianness
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_S8
(
    P2CONST(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    sint8 NewValue = *ValuePtr;
    sint8 OldValue = 0;
    boolean ret = FALSE;

#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleS8(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigS8(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleS8(&OldValue, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigS8(&OldValue, PduPtr, BitSize, StartBit, Mask);
#endif
    if(NewValue != OldValue)
    {
        ret = TRUE;
    }
    return ret;
}

/**********************************************U16 Check**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CheckChangeSignal_U16
*
* Description:   Check signal for change.
*
* Inputs:        ValuePtr
*                PduPtr
*                Endianness
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_U16
(
    P2CONST(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint16 NewValue = *ValuePtr;
    uint16 OldValue = 0;
    boolean ret = FALSE;

#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleU16(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigU16(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleU16(&OldValue, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigU16(&OldValue, PduPtr, BitSize, StartBit, Mask);
#endif
    if(NewValue != OldValue)
    {
        ret = TRUE;
    }
    return ret;
}

/**********************************************S16 Check**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CheckChangeSignal_S16
*
* Description:   Check signal for change.
*
* Inputs:        ValuePtr
*                PduPtr
*                Endianness
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_S16
(
    P2CONST(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    sint16 NewValue = *ValuePtr;
    sint16 OldValue = 0;
    boolean ret = FALSE;

#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleS16(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigS16(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleS16(&OldValue, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigS16(&OldValue, PduPtr, BitSize, StartBit, Mask);
#endif
    if(NewValue != OldValue)
    {
        ret = TRUE;
    }
    return ret;
}

/**********************************************U32 Check**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CheckChangeSignal_U32
*
* Description:   Check signal for change.
*
* Inputs:        ValuePtr
*                PduPtr
*                Endianness
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_U32
(
    P2CONST(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint32 NewValue = *ValuePtr;
    uint32 OldValue = 0;
    boolean ret = FALSE;

#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleU32(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigU32(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleU32(&OldValue, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigU32(&OldValue, PduPtr, BitSize, StartBit, Mask);
#endif
    if(NewValue != OldValue)
    {
        ret = TRUE;
    }
    return ret;
}

/**********************************************S32 Check**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CheckChangeSignal_S32
*
* Description:   Check signal for change.
*
* Inputs:        ValuePtr
*                PduPtr
*                Endianness
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_S32
(
    P2CONST(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    sint32 NewValue = *ValuePtr;
    sint32 OldValue = 0;
    boolean ret = FALSE;

#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleS32(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigS32(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleS32(&OldValue, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigS32(&OldValue, PduPtr, BitSize, StartBit, Mask);
#endif
    if(NewValue != OldValue)
    {
        ret = TRUE;
    }
    return ret;
}

/**********************************************F32 Check**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CheckChangeSignal_F32
*
* Description:   Check signal for change.
*
* Inputs:        ValuePtr
*                PduPtr
*                Endianness
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_F32
(
    P2CONST(float32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    float32 NewValue = *ValuePtr;
    float32 OldValue = 0;
    boolean ret = FALSE;

#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleF32(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigF32(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleF32(&OldValue, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigF32(&OldValue, PduPtr, BitSize, StartBit, Mask);
#endif
    if(NewValue != OldValue)
    {
        ret = TRUE;
    }
    return ret;
}

/**********************************************U64 Check**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CheckChangeSignal_U64
*
* Description:   Check signal for change.
*
* Inputs:        ValuePtr
*                PduPtr
*                Endianness
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_U64
(
    P2CONST(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    uint64 NewValue = *ValuePtr;
    uint64 OldValue = 0;
    boolean ret = FALSE;

#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleU64(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigU64(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleU64(&OldValue, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigU64(&OldValue, PduPtr, BitSize, StartBit, Mask);
#endif
    if(NewValue != OldValue)
    {
        ret = TRUE;
    }
    return ret;
}

/**********************************************S64 Check**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CheckChangeSignal_S64
*
* Description:   Check signal for change.
*
* Inputs:        ValuePtr
*                PduPtr
*                Endianness
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_S64
(
    P2CONST(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    sint64 NewValue = *ValuePtr;
    sint64 OldValue = 0;
    boolean ret = FALSE;

#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleS64(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigS64(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleS64(&OldValue, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigS64(&OldValue, PduPtr, BitSize, StartBit, Mask);
#endif
    if(NewValue != OldValue)
    {
        ret = TRUE;
    }
    return ret;
}

/**********************************************F64 Check**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CheckChangeSignal_F64
*
* Description:   Check signal for change.
*
* Inputs:        ValuePtr
*                PduPtr
*                Endianness
*                BitSize
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
STATIC FUNC(boolean, COM_CODE) Com_CheckChangeSignal_F64
(
    P2CONST(float64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
)
{
    float64 NewValue = *ValuePtr;
    float64 OldValue = 0;
    boolean ret = FALSE;

#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
    if(COM_LITTLE_ENDIAN == Endianness)
    {
        Com_ReadSignal_LittleF64(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
    else/*COM_BIG_ENDIAN*/
    {
        Com_ReadSignal_BigF64(&OldValue, PduPtr, BitSize, StartBit, Mask);
    }
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
    Com_ReadSignal_LittleF64(&OldValue, PduPtr, BitSize, StartBit, Mask);
#else
    Com_ReadSignal_BigF64(&OldValue, PduPtr, BitSize, StartBit, Mask);
#endif
    if(NewValue != OldValue)
    {
        ret = TRUE;
    }
    return ret;
}

/**********************************************U8N Check**********************************************/

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CheckChangeSignal_U8N
*
* Description:   Check signal for change.
*
* Inputs:        ValuePtr
*                PduPtr
*                ByteLength
*                StartBit
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(boolean, COM_CODE) Com_CheckChangeSignal_U8N
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    PduLengthType ByteLength,
    uint16 StartBit
)
{
    uint16 StartByte;
    PduLengthType ByteOffset;
    boolean ret = FALSE;

    StartByte = (uint16)(StartBit >> COM_THREE_BIT);
    for(ByteOffset = (PduLengthType)0; ByteOffset < ByteLength; ByteOffset++)
    {
        if(ValuePtr[ByteOffset] != PduPtr[StartByte + ByteOffset])
        {
            ret = TRUE;
            break;
        }
    }
    return ret;
}

/*******************************************************************************
*    Static Api of Com_Data
*******************************************************************************/
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_WriteSignal
*
* Description:   Write signal to pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                Endianness
*                SigType
*                BitSize
*                StartBit
*                ByteLength
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
FUNC(void, COM_CODE) Com_WriteSignal
(
    P2CONST(void, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    Com_SigType SigType,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb,
    PduLengthType ByteLength
)
{
    switch(SigType)
    {
    case COM_SIG_U8:
    case COM_SIG_BOOLEAN:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_WriteSignal_LittleU8((const uint8*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_WriteSignal_BigU8((const uint8*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        break;
    case COM_SIG_S8:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_WriteSignal_LittleS8((const sint8*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_WriteSignal_BigS8((const sint8*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        break;
    case COM_SIG_U16:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_WriteSignal_LittleU16((const uint16*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_WriteSignal_BigU16((const uint16*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        break;
    case COM_SIG_S16:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_WriteSignal_LittleS16((const sint16*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_WriteSignal_BigS16((const sint16*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        break;
    case COM_SIG_U32:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_WriteSignal_LittleU32((const uint32*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_WriteSignal_BigU32((const uint32*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        break;
    case COM_SIG_S32:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_WriteSignal_LittleS32((const sint32*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_WriteSignal_BigS32((const sint32*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        break;
    case COM_SIG_F32:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_WriteSignal_LittleF32((const float32*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_WriteSignal_BigF32((const float32*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        break;
    case COM_SIG_U64:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_WriteSignal_LittleU64((const uint64*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_WriteSignal_BigU64((const uint64*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        break;
    case COM_SIG_S64:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_WriteSignal_LittleS64((const sint64*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_WriteSignal_BigS64((const sint64*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        break;
    case COM_SIG_F64:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_WriteSignal_LittleF64((const float64*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_WriteSignal_BigF64((const float64*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        }
        break;
    case COM_SIG_U8N:
    case COM_SIG_DYN:
        Com_WriteSignal_U8N((const uint8*)ValuePtr, PduPtr, ByteLength, StartBit);
        break;
    default:
        break;
    }
}
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
FUNC(void, COM_CODE) Com_WriteSignal
(
    P2CONST(void, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    Com_SigType SigType,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb,
    PduLengthType ByteLength
)
{
    switch(SigType)
    {
    case COM_SIG_U8:
    case COM_SIG_BOOLEAN:
        Com_WriteSignal_LittleU8((const uint8*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_S8:
        Com_WriteSignal_LittleS8((const sint8*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_U16:
        Com_WriteSignal_LittleU16((const uint16*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_S16:
        Com_WriteSignal_LittleS16((const sint16*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_U32:
        Com_WriteSignal_LittleU32((const uint32*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_S32:
        Com_WriteSignal_LittleS32((const sint32*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_F32:
        Com_WriteSignal_LittleF32((const float32*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_U64:
        Com_WriteSignal_LittleU64((const uint64*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_S64:
        Com_WriteSignal_LittleS64((const sint64*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_F64:
        Com_WriteSignal_LittleF64((const float64*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_U8N:
    case COM_SIG_DYN:
        Com_WriteSignal_U8N((const uint8*)ValuePtr, PduPtr, ByteLength, StartBit);
        break;
    default:
        break;
    }
}
#else
FUNC(void, COM_CODE) Com_WriteSignal
(
    P2CONST(void, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    Com_SigType SigType,
    uint16 BitSize,
    uint16 StartBit,
    uint8 MaskLsb,
    uint8 MaskMsb,
    PduLengthType ByteLength
)
{
    switch(SigType)
    {
    case COM_SIG_U8:
    case COM_SIG_BOOLEAN:
        Com_WriteSignal_BigU8((const uint8*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_S8:
        Com_WriteSignal_BigS8((const sint8*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_U16:
        Com_WriteSignal_BigU16((const uint16*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_S16:
        Com_WriteSignal_BigS16((const sint16*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_U32:
        Com_WriteSignal_BigU32((const uint32*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_S32:
        Com_WriteSignal_BigS32((const sint32*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_F32:
        Com_WriteSignal_BigF32((const float32*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_U64:
        Com_WriteSignal_BigU64((const uint64*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_S64:
        Com_WriteSignal_BigS64((const sint64*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_F64:
        Com_WriteSignal_BigF64((const float64*)ValuePtr, PduPtr, BitSize, StartBit, MaskLsb, MaskMsb);
        break;
    case COM_SIG_U8N:
    case COM_SIG_DYN:
        Com_WriteSignal_U8N((const uint8*)ValuePtr, PduPtr, ByteLength, StartBit);
        break;
    default:
        break;
    }
}
#endif

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_ReadSignal
*
* Description:   Read signal from pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                Endianness
*                SigType
*                BitSize
*                StartBit
*                ByteLength
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)&&(STD_ON == COM_SUPPORT_BIG_ENDIAN)
FUNC(void, COM_CODE) Com_ReadSignal
(
    P2VAR(void, AUTOMATIC, COM_VAR) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    Com_SigType SigType,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask,
    PduLengthType ByteLength
)
{
    switch(SigType)
    {
    case COM_SIG_U8:
    case COM_SIG_BOOLEAN:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleU8((uint8*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigU8((uint8*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        break;
    case COM_SIG_S8:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleS8((sint8*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigS8((sint8*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        break;
    case COM_SIG_U16:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleU16((uint16*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigU16((uint16*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        break;
    case COM_SIG_S16:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleS16((sint16*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigS16((sint16*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        break;
    case COM_SIG_U32:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleU32((uint32*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigU32((uint32*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        break;
    case COM_SIG_S32:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleS32((sint32*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigS32((sint32*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        break;
    case COM_SIG_F32:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleF32((float32*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigF32((float32*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        break;
    case COM_SIG_U64:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleU64((uint64*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigU64((uint64*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        break;
    case COM_SIG_S64:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleS64((sint64*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigS64((sint64*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        break;
    case COM_SIG_F64:
        if(COM_LITTLE_ENDIAN == Endianness)
        {
            Com_ReadSignal_LittleF64((float64*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        else/*COM_BIG_ENDIAN*/
        {
            Com_ReadSignal_BigF64((float64*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        }
        break;
    case COM_SIG_U8N:
    case COM_SIG_DYN:
        Com_ReadSignal_U8N((uint8*)ValuePtr, PduPtr, ByteLength, StartBit);
        break;
    default:
        break;
    }
}
#elif(STD_ON == COM_SUPPORT_LITTLE_ENDIAN)
FUNC(void, COM_CODE) Com_ReadSignal
(
    P2VAR(void, AUTOMATIC, COM_VAR) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    Com_SigType SigType,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask,
    PduLengthType ByteLength
)
{
    switch(SigType)
    {
    case COM_SIG_U8:
    case COM_SIG_BOOLEAN:
        Com_ReadSignal_LittleU8((uint8*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_S8:
        Com_ReadSignal_LittleS8((sint8*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_U16:
        Com_ReadSignal_LittleU16((uint16*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_S16:
        Com_ReadSignal_LittleS16((sint16*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_U32:
        Com_ReadSignal_LittleU32((uint32*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_S32:
        Com_ReadSignal_LittleS32((sint32*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_F32:
        Com_ReadSignal_LittleF32((float32*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_U64:
        Com_ReadSignal_LittleU64((uint64*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_S64:
        Com_ReadSignal_LittleS64((sint64*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_F64:
        Com_ReadSignal_LittleF64((float64*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_U8N:
    case COM_SIG_DYN:
        Com_ReadSignal_U8N((uint8*)ValuePtr, PduPtr, ByteLength, StartBit);
        break;
    default:
        break;
    }
}
#else
FUNC(void, COM_CODE) Com_ReadSignal
(
    P2VAR(void, AUTOMATIC, COM_VAR) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    Com_SigType SigType,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask,
    PduLengthType ByteLength
)
{
    switch(SigType)
    {
    case COM_SIG_U8:
    case COM_SIG_BOOLEAN:
        Com_ReadSignal_BigU8((uint8*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_S8:
        Com_ReadSignal_BigS8((sint8*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_U16:
        Com_ReadSignal_BigU16((uint16*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_S16:
        Com_ReadSignal_BigS16((sint16*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_U32:
        Com_ReadSignal_BigU32((uint32*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_S32:
        Com_ReadSignal_BigS32((sint32*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_F32:
        Com_ReadSignal_BigF32((float32*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_U64:
        Com_ReadSignal_BigU64((uint64*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_S64:
        Com_ReadSignal_BigS64((sint64*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_F64:
        Com_ReadSignal_BigF64((float64*)ValuePtr, PduPtr, BitSize, StartBit, Mask);
        break;
    case COM_SIG_U8N:
    case COM_SIG_DYN:
        Com_ReadSignal_U8N((uint8*)ValuePtr, PduPtr, ByteLength, StartBit);
        break;
    default:
        break;
    }
}
#endif
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CheckChangeSignalInPdu
*
* Description:   Check signal for change in pdu.
*
* Inputs:        ValuePtr
*                PduPtr
*                Endianness
*                SigType
*                BitSize
*                StartBit
*                ByteLength
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(boolean, COM_CODE) Com_CheckChangeSignalInPdu
(
    P2CONST(void, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    Com_SigType SigType,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask,
    PduLengthType ByteLength
)
{
    boolean ret = FALSE;

    switch(SigType)
    {
    case COM_SIG_U8:
    case COM_SIG_BOOLEAN:
        ret = Com_CheckChangeSignal_U8((const uint8*)ValuePtr, PduPtr, Endianness, BitSize, StartBit, Mask);
        break;
    case COM_SIG_S8:
        ret = Com_CheckChangeSignal_S8((const sint8*)ValuePtr, PduPtr, Endianness, BitSize, StartBit, Mask);
        break;
    case COM_SIG_U16:
        ret = Com_CheckChangeSignal_U16((const uint16*)ValuePtr, PduPtr, Endianness, BitSize, StartBit, Mask);
        break;
    case COM_SIG_S16:
        ret = Com_CheckChangeSignal_S16((const sint16*)ValuePtr, PduPtr, Endianness, BitSize, StartBit, Mask);
        break;
    case COM_SIG_U32:
        ret = Com_CheckChangeSignal_U32((const uint32*)ValuePtr, PduPtr, Endianness, BitSize, StartBit, Mask);
        break;
    case COM_SIG_S32:
        ret = Com_CheckChangeSignal_S32((const sint32*)ValuePtr, PduPtr, Endianness, BitSize, StartBit, Mask);
        break;
    case COM_SIG_F32:
        ret = Com_CheckChangeSignal_F32((const float32*)ValuePtr, PduPtr, Endianness, BitSize, StartBit, Mask);
        break;
    case COM_SIG_U64:
        ret = Com_CheckChangeSignal_U64((const uint64*)ValuePtr, PduPtr, Endianness, BitSize, StartBit, Mask);
        break;
    case COM_SIG_S64:
        ret = Com_CheckChangeSignal_S64((const sint64*)ValuePtr, PduPtr, Endianness, BitSize, StartBit, Mask);
        break;
    case COM_SIG_F64:
        ret = Com_CheckChangeSignal_F64((const float64*)ValuePtr, PduPtr, Endianness, BitSize, StartBit, Mask);
        break;
    case COM_SIG_U8N:
    case COM_SIG_DYN:
        ret = Com_CheckChangeSignal_U8N((const uint8*)ValuePtr, PduPtr, ByteLength, StartBit);
        break;
    default:
        break;
    }
    return ret;
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CheckChangeSignal
*
* Description:   Check signal for change.
*
* Inputs:        ValuePtr
*                PduPtr
*                Endianness
*                SigType
*                BitSize
*                StartBit
*                ByteLength
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(boolean, COM_CODE) Com_CheckChangeSignal
(
    P2VAR(void, AUTOMATIC, COM_CONST) NewValuePtr,
    P2VAR(void, AUTOMATIC, COM_CONST) OldValuePtr,
    Com_SigType SigType,
    PduLengthType ByteLength
)
{
    boolean ret = FALSE;

    switch(SigType)
    {
    case COM_SIG_U8:
    case COM_SIG_BOOLEAN:
        if(*(uint8*)NewValuePtr != *(uint8*)OldValuePtr)
        {
            ret = TRUE;
        }
        break;
    case COM_SIG_S8:
        if(*(sint8*)NewValuePtr != *(sint8*)OldValuePtr)
        {
            ret = TRUE;
        }
        break;
    case COM_SIG_U16:
        if(*(uint16*)NewValuePtr != *(uint16*)OldValuePtr)
        {
            ret = TRUE;
        }
        break;
    case COM_SIG_S16:
        if(*(sint16*)NewValuePtr != *(sint16*)OldValuePtr)
        {
            ret = TRUE;
        }
        break;
    case COM_SIG_U32:
        if(*(uint32*)NewValuePtr != *(uint32*)OldValuePtr)
        {
            ret = TRUE;
        }
        break;
    case COM_SIG_S32:
        if(*(sint32*)NewValuePtr != *(sint32*)OldValuePtr)
        {
            ret = TRUE;
        }
        break;
    case COM_SIG_F32:
        if(*(float32*)NewValuePtr != *(float32*)OldValuePtr)
        {
            ret = TRUE;
        }
        break;
    case COM_SIG_U64:
        if(*(uint64*)NewValuePtr != *(uint64*)OldValuePtr)
        {
            ret = TRUE;
        }
        break;
    case COM_SIG_S64:
        if(*(sint64*)NewValuePtr != *(sint64*)OldValuePtr)
        {
            ret = TRUE;
        }
        break;
    case COM_SIG_F64:
        if(*(float64*)NewValuePtr != *(float64*)OldValuePtr)
        {
            ret = TRUE;
        }
        break;
    case COM_SIG_U8N:
    case COM_SIG_DYN:
        ret = Com_CheckChangeSignal_U8N((const uint8*)NewValuePtr, (uint8*)OldValuePtr, ByteLength, (uint16)0);
        break;
    default:
        break;
    }
    return ret;
}
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_MoveSignal
*
* Description:   Move temp signal to signal.
*
* Inputs:        ValuePtr
*                PduPtr
*                Endianness
*                SigType
*                BitSize
*                StartBit
*                ByteLength
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
#if 0
FUNC(boolean, COM_CODE) Com_MoveSignal
(
    P2VAR(uint8, AUTOMATIC, COM_VAR) SrcPduPtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) DestPduPtr,
    Com_EndiannessType Endianness,
    Com_SigType SigType,
    uint16 BitSize,
    uint16 StartBit,
    PduLengthType ByteLength
)
{
    uint8 Value_U8 = (uint8)0;
    uint16 Value_U16 = (uint16)0;
    uint32 Value_U32 = (uint32)0;
    uint64 Value_U64 = (uint64)0;
    sint8 Value_S8 = (sint8)0;
    sint16 Value_S16 = (sint16)0;
    sint32 Value_S32 = (sint32)0;
    sint64 Value_S64 = (sint64)0;
    float32 Value_F32 = (float32)0;
    float64 Value_F64 = (float64)0;
    uint16 StartByte;

    switch(SigType)
    {
    case COM_SIG_U8:
    case COM_SIG_BOOLEAN:
        Com_ReadSignal(&Value_U8, SrcPduPtr, Endianness, SigType, BitSize, StartBit, ByteLength);
        Com_WriteSignal(&Value_U8, DestPduPtr, Endianness,SigType,  BitSize, StartBit, ByteLength);
        break;
    case COM_SIG_S8:
        Com_ReadSignal(&Value_S8, SrcPduPtr, Endianness, SigType, BitSize, StartBit, ByteLength);
        Com_WriteSignal(&Value_S8, DestPduPtr, Endianness,SigType,  BitSize, StartBit, ByteLength);
        break;
    case COM_SIG_U16:
        Com_ReadSignal(&Value_U16, SrcPduPtr, Endianness, SigType, BitSize, StartBit, ByteLength);
        Com_WriteSignal(&Value_U16, DestPduPtr, Endianness,SigType,  BitSize, StartBit, ByteLength);
        break;
    case COM_SIG_S16:
        Com_ReadSignal(&Value_S16, SrcPduPtr, Endianness, SigType, BitSize, StartBit, ByteLength);
        Com_WriteSignal(&Value_S16, DestPduPtr, Endianness,SigType,  BitSize, StartBit, ByteLength);
        break;
    case COM_SIG_U32:
        Com_ReadSignal(&Value_U32, SrcPduPtr, Endianness, SigType, BitSize, StartBit, ByteLength);
        Com_WriteSignal(&Value_U32, DestPduPtr, Endianness,SigType,  BitSize, StartBit, ByteLength);
        break;
    case COM_SIG_S32:
        Com_ReadSignal(&Value_S32, SrcPduPtr, Endianness, SigType, BitSize, StartBit, ByteLength);
        Com_WriteSignal(&Value_S32, DestPduPtr, Endianness,SigType,  BitSize, StartBit, ByteLength);
        break;
    case COM_SIG_F32:
        Com_ReadSignal(&Value_F32, SrcPduPtr, Endianness, SigType, BitSize, StartBit, ByteLength);
        Com_WriteSignal(&Value_F32, DestPduPtr, Endianness,SigType,  BitSize, StartBit, ByteLength);
        break;
    case COM_SIG_U64:
        Com_ReadSignal(&Value_U64, SrcPduPtr, Endianness, SigType, BitSize, StartBit, ByteLength);
        Com_WriteSignal(&Value_U64, DestPduPtr, Endianness,SigType,  BitSize, StartBit, ByteLength);
        break;
    case COM_SIG_S64:
        Com_ReadSignal(&Value_S64, SrcPduPtr, Endianness, SigType, BitSize, StartBit, ByteLength);
        Com_WriteSignal(&Value_S64, DestPduPtr, Endianness,SigType,  BitSize, StartBit, ByteLength);
        break;
    case COM_SIG_F64:
        Com_ReadSignal(&Value_F64, SrcPduPtr, Endianness, SigType, BitSize, StartBit, ByteLength);
        Com_WriteSignal(&Value_F64, DestPduPtr, Endianness,SigType,  BitSize, StartBit, ByteLength);
        break;
    case COM_SIG_U8N:
    case COM_SIG_DYN:
        StartByte = (uint16)(StartBit >> COM_THREE_BIT);
        Bsw_MemCpy(&DestPduPtr[StartByte], &SrcPduPtr[StartByte], (uint32)ByteLength);
        break;
    default:
        break;
    }
}
#endif
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CopySignalWithOutLock
*
* Description:   Copy signal.
*
* Inputs:        SrcPtr
*                DestPtr
*                SigType
*                ByteLength
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(void, COM_CODE) Com_CopySignalWithOutLock
(
    P2CONST(void, AUTOMATIC, COM_CONST) SrcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) DestPtr,
    Com_SigType SigType,
    PduLengthType ByteLength
)
{
    switch(SigType)
    {
    case COM_SIG_U8:
        *(uint8*)DestPtr = *(const uint8*)SrcPtr;
        break;
    case COM_SIG_S8:
        *(sint8*)DestPtr = *(const sint8*)SrcPtr;
        break;
    case COM_SIG_BOOLEAN:
        *(boolean*)DestPtr = *(const boolean*)SrcPtr;
        break;
    case COM_SIG_U16:
        *(uint16*)DestPtr = *(const uint16*)SrcPtr;
        break;
    case COM_SIG_S16:
        *(sint16*)DestPtr = *(const sint16*)SrcPtr;
        break;
    case COM_SIG_U32:
        *(uint32*)DestPtr = *(const uint32*)SrcPtr;
        break;
    case COM_SIG_S32:
        *(sint32*)DestPtr = *(const sint32*)SrcPtr;
        break;
    case COM_SIG_F32:
        *(float32*)DestPtr = *(const float32*)SrcPtr;
        break;
    case COM_SIG_U64:
        *(uint64*)DestPtr = *(const uint64*)SrcPtr;
        break;
    case COM_SIG_S64:
        *(sint64*)DestPtr = *(const sint64*)SrcPtr;
        break;
    case COM_SIG_F64:
        *(float64*)DestPtr = *(const float64*)SrcPtr;
        break;
    case COM_SIG_U8N:
    case COM_SIG_DYN:
        Bsw_MemCpy((uint8 *)DestPtr, (const uint8 *)SrcPtr, (uint32)ByteLength);
        break;
    default:
        break;
    }
}

/*******************************************************************************
*   Filter
*******************************************************************************/
/*******************************************************************************
*   Filter OutSide
*******************************************************************************/
/**********************************************U8 OutSide**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OutSide_U8
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint8 ValueTemp = *ValuePtr;
    uint8 Min = *(const uint8 *)AlgPtr->Par1;
    uint8 Max = *(const uint8 *)AlgPtr->Par2;

    if((ValueTemp > Max) || (ValueTemp < Min))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************U16 OutSide**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OutSide_U16
(
    P2CONST(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint16 ValueTemp = *ValuePtr;
    uint16 Min = *(const uint16 *)AlgPtr->Par1;
    uint16 Max = *(const uint16 *)AlgPtr->Par2;

    if((ValueTemp > Max) || (ValueTemp < Min))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************U32 OutSide**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OutSide_U32
(
    P2CONST(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint32 ValueTemp = *ValuePtr;
    uint32 Min = *(const uint32 *)AlgPtr->Par1;
    uint32 Max = *(const uint32 *)AlgPtr->Par2;

    if((ValueTemp > Max) || (ValueTemp < Min))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************U64 OutSide**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OutSide_U64
(
    P2CONST(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint64 ValueTemp = *ValuePtr;
    uint64 Min = *(const uint64 *)AlgPtr->Par1;
    uint64 Max = *(const uint64 *)AlgPtr->Par2;

    if((ValueTemp > Max) || (ValueTemp < Min))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************S8 OutSide**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OutSide_S8
(
    P2CONST(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint8 ValueTemp = *ValuePtr;
    sint8 Min = *(const sint8 *)AlgPtr->Par1;
    sint8 Max = *(const sint8 *)AlgPtr->Par2;

    if((ValueTemp > Max) || (ValueTemp < Min))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************S16 OutSide**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OutSide_S16
(
    P2CONST(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint16 ValueTemp = *ValuePtr;
    sint16 Min = *(const sint16 *)AlgPtr->Par1;
    sint16 Max = *(const sint16 *)AlgPtr->Par2;

    if((ValueTemp > Max) || (ValueTemp < Min))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************S32 OutSide**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OutSide_S32
(
    P2CONST(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint32 ValueTemp = *ValuePtr;
    sint32 Min = *(const sint32 *)AlgPtr->Par1;
    sint32 Max = *(const sint32 *)AlgPtr->Par2;

    if((ValueTemp > Max) || (ValueTemp < Min))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************S64 OutSide**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OutSide_S64
(
    P2CONST(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint64 ValueTemp = *ValuePtr;
    sint64 Min = *(const sint64 *)AlgPtr->Par1;
    sint64 Max = *(const sint64 *)AlgPtr->Par2;

    if((ValueTemp > Max) || (ValueTemp < Min))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}

/*******************************************************************************
*   Filter WithIn
*******************************************************************************/
/**********************************************U8 WithIn**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_WithIn_U8
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint8 ValueTemp = *ValuePtr;
    uint8 Min = *(const uint8 *)AlgPtr->Par1;
    uint8 Max = *(const uint8 *)AlgPtr->Par2;

    if((ValueTemp < Max) && (ValueTemp > Min))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************U16 WithIn**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_WithIn_U16
(
    P2CONST(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint16 ValueTemp = *ValuePtr;
    uint16 Min = *(const uint16 *)AlgPtr->Par1;
    uint16 Max = *(const uint16 *)AlgPtr->Par2;

    if((ValueTemp < Max) && (ValueTemp > Min))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************U32 WithIn**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_WithIn_U32
(
    P2CONST(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint32 ValueTemp = *ValuePtr;
    uint32 Min = *(const uint32 *)AlgPtr->Par1;
    uint32 Max = *(const uint32 *)AlgPtr->Par2;

    if((ValueTemp < Max) && (ValueTemp > Min))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************U64 WithIn**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_WithIn_U64
(
    P2CONST(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint64 ValueTemp = *ValuePtr;
    uint64 Min = *(const uint64 *)AlgPtr->Par1;
    uint64 Max = *(const uint64 *)AlgPtr->Par2;

    if((ValueTemp < Max) && (ValueTemp > Min))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************S8 WithIn**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_WithIn_S8
(
    P2CONST(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint8 ValueTemp = *ValuePtr;
    sint8 Min = *(const sint8 *)AlgPtr->Par1;
    sint8 Max = *(const sint8 *)AlgPtr->Par2;

    if((ValueTemp < Max) && (ValueTemp > Min))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************S16 WithIn**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_WithIn_S16
(
    P2CONST(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint16 ValueTemp = *ValuePtr;
    sint16 Min = *(const sint16 *)AlgPtr->Par1;
    sint16 Max = *(const sint16 *)AlgPtr->Par2;

    if((ValueTemp < Max) && (ValueTemp > Min))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************S32 WithIn**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_WithIn_S32
(
    P2CONST(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint32 ValueTemp = *ValuePtr;
    sint32 Min = *(const sint32 *)AlgPtr->Par1;
    sint32 Max = *(const sint32 *)AlgPtr->Par2;

    if((ValueTemp < Max) && (ValueTemp > Min))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************S64 WithIn**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_WithIn_S64
(
    P2CONST(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint64 ValueTemp = *ValuePtr;
    sint64 Min = *(const sint64 *)AlgPtr->Par1;
    sint64 Max = *(const sint64 *)AlgPtr->Par2;

    if((ValueTemp < Max) && (ValueTemp > Min))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}

/*******************************************************************************
*   Filter MaskEqualsX
*******************************************************************************/
/**********************************************U8 MaskEqualsX**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskEqualsX_U8
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint8 ValueTemp = *ValuePtr;
    uint8 ValueX = *(const uint8 *)AlgPtr->Par1;
    uint8 Mask = *(const uint8 *)AlgPtr->Par2;

    if((ValueTemp & Mask) == ValueX)
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************U16 MaskEqualsX**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskEqualsX_U16
(
    P2CONST(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint16 ValueTemp = *ValuePtr;
    uint16 ValueX = *(const uint16 *)AlgPtr->Par1;
    uint16 Mask = *(const uint16 *)AlgPtr->Par2;

    if((ValueTemp & Mask) == ValueX)
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************U32 MaskEqualsX**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskEqualsX_U32
(
    P2CONST(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint32 ValueTemp = *ValuePtr;
    uint32 ValueX = *(const uint32 *)AlgPtr->Par1;
    uint32 Mask = *(const uint32 *)AlgPtr->Par2;

    if((ValueTemp & Mask) == ValueX)
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************U64 MaskEqualsX**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskEqualsX_U64
(
    P2CONST(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint64 ValueTemp = *ValuePtr;
    uint64 ValueX = *(const uint64 *)AlgPtr->Par1;
    uint64 Mask = *(const uint64 *)AlgPtr->Par2;

    if((ValueTemp & Mask) == ValueX)
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************S8 MaskEqualsX**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskEqualsX_S8
(
    P2CONST(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint8 ValueTemp = *ValuePtr;
    sint8 ValueX = *(const sint8 *)AlgPtr->Par1;
    sint8 Mask = *(const sint8 *)AlgPtr->Par2;

    if((ValueTemp & Mask) == ValueX)
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************S16 MaskEqualsX**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskEqualsX_S16
(
    P2CONST(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint16 ValueTemp = *ValuePtr;
    sint16 ValueX = *(const sint16 *)AlgPtr->Par1;
    sint16 Mask = *(const sint16 *)AlgPtr->Par2;

    if((ValueTemp & Mask) == ValueX)
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************S32 MaskEqualsX**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskEqualsX_S32
(
    P2CONST(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint32 ValueTemp = *ValuePtr;
    sint32 ValueX = *(const sint32 *)AlgPtr->Par1;
    sint32 Mask = *(const sint32 *)AlgPtr->Par2;

    if((ValueTemp & Mask) == ValueX)
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************S64 MaskEqualsX**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskEqualsX_S64
(
    P2CONST(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint64 ValueTemp = *ValuePtr;
    sint64 ValueX = *(const sint64 *)AlgPtr->Par1;
    sint64 Mask = *(const sint64 *)AlgPtr->Par2;

    if((ValueTemp & Mask) == ValueX)
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/*******************************************************************************
*   Filter MaskDiffersX
*******************************************************************************/
/**********************************************U8 MaskDiffersX**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersX_U8
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint8 ValueTemp = *ValuePtr;
    uint8 ValueX = *(const uint8 *)AlgPtr->Par1;
    uint8 Mask = *(const uint8 *)AlgPtr->Par2;

    if((ValueTemp & Mask) != ValueX)
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************U16 MaskDiffersX**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersX_U16
(
    P2CONST(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint16 ValueTemp = *ValuePtr;
    uint16 ValueX = *(const uint16 *)AlgPtr->Par1;
    uint16 Mask = *(const uint16 *)AlgPtr->Par2;

    if((ValueTemp & Mask) != ValueX)
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************U32 MaskDiffersX**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersX_U32
(
    P2CONST(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint32 ValueTemp = *ValuePtr;
    uint32 ValueX = *(const uint32 *)AlgPtr->Par1;
    uint32 Mask = *(const uint32 *)AlgPtr->Par2;

    if((ValueTemp & Mask) != ValueX)
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************U64 MaskDiffersX**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersX_U64
(
    P2CONST(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint64 ValueTemp = *ValuePtr;
    uint64 ValueX = *(const uint64 *)AlgPtr->Par1;
    uint64 Mask = *(const uint64 *)AlgPtr->Par2;

    if((ValueTemp & Mask) != ValueX)
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************S8 MaskDiffersX**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersX_S8
(
    P2CONST(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint8 ValueTemp = *ValuePtr;
    sint8 ValueX = *(const sint8 *)AlgPtr->Par1;
    sint8 Mask = *(const sint8 *)AlgPtr->Par2;

    if((ValueTemp & Mask) != ValueX)
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************S16 MaskDiffersX**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersX_S16
(
    P2CONST(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint16 ValueTemp = *ValuePtr;
    sint16 ValueX = *(const sint16 *)AlgPtr->Par1;
    sint16 Mask = *(const sint16 *)AlgPtr->Par2;

    if((ValueTemp & Mask) != ValueX)
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************S32 MaskDiffersX**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersX_S32
(
    P2CONST(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint32 ValueTemp = *ValuePtr;
    sint32 ValueX = *(const sint32 *)AlgPtr->Par1;
    sint32 Mask = *(const sint32 *)AlgPtr->Par2;

    if((ValueTemp & Mask) != ValueX)
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************S64 MaskDiffersX**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersX_S64
(
    P2CONST(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint64 ValueTemp = *ValuePtr;
    sint64 ValueX = *(const sint64 *)AlgPtr->Par1;
    sint64 Mask = *(const sint64 *)AlgPtr->Par2;

    if((ValueTemp & Mask) != ValueX)
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/*******************************************************************************
*   Filter MaskDiffersOld
*******************************************************************************/
/**********************************************U8 MaskDiffersOld**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersOld_U8
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint8 NewValue = *ValuePtr;
    uint8 OldValue = *(const uint8 *)AlgPtr->Par3;
    uint8 Mask = *(const uint8 *)AlgPtr->Par2;

    if((NewValue & Mask) != (OldValue & Mask))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************U16 MaskDiffersOld**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersOld_U16
(
    P2CONST(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint16 NewValue = *ValuePtr;
    uint16 OldValue = *(const uint16 *)AlgPtr->Par3;
    uint16 Mask = *(const uint16 *)AlgPtr->Par2;

    if((NewValue & Mask) != (OldValue & Mask))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************U32 MaskDiffersOld**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersOld_U32
(
    P2CONST(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint32 NewValue = *ValuePtr;
    uint32 OldValue = *(const uint32 *)AlgPtr->Par3;
    uint32 Mask = *(const uint32 *)AlgPtr->Par2;

    if((NewValue & Mask) != (OldValue & Mask))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************U64 MaskDiffersOld**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersOld_U64
(
    P2CONST(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    uint64 NewValue = *ValuePtr;
    uint64 OldValue = *(const uint64 *)AlgPtr->Par3;
    uint64 Mask = *(const uint64 *)AlgPtr->Par2;

    if((NewValue & Mask) != (OldValue & Mask))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/**********************************************S8 MaskDiffersOld**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersOld_S8
(
    P2CONST(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint8 NewValue = *ValuePtr;
    sint8 OldValue = *(const sint8 *)AlgPtr->Par3;
    sint8 Mask = *(const sint8 *)AlgPtr->Par2;

    if((NewValue & Mask) != (OldValue & Mask))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}

/**********************************************S16 MaskDiffersOld**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersOld_S16
(
    P2CONST(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint16 NewValue = *ValuePtr;
    sint16 OldValue = *(const sint16 *)AlgPtr->Par3;
    sint16 Mask = *(const sint16 *)AlgPtr->Par2;

    if((NewValue & Mask) != (OldValue & Mask))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}

/**********************************************S32 MaskDiffersOld**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersOld_S32
(
    P2CONST(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint32 NewValue = *ValuePtr;
    sint32 OldValue = *(const sint32 *)AlgPtr->Par3;
    sint32 Mask = *(const sint32 *)AlgPtr->Par2;

    if((NewValue & Mask) != (OldValue & Mask))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}

/**********************************************S64 MaskDiffersOld**********************************************/
STATIC FUNC(uint8, COM_CODE)  Com_Filter_MaskDiffersOld_S64
(
    P2CONST(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    sint64 NewValue = *ValuePtr;
    sint64 OldValue = *(const sint64 *)AlgPtr->Par3;
    sint64 Mask = *(const sint64 *)AlgPtr->Par2;

    if((NewValue & Mask) != (OldValue & Mask))
    {
        ret = COM_SIGNAL_VALID;
    }

    return ret;
}
/*******************************************************************************
*   Filter OneEveryN
*******************************************************************************/
#if(COM_MAX_FILTER_OCCURRENCE_NUM > 0)
STATIC FUNC(uint8, COM_CODE)  Com_Filter_OneEveryN
(
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 ret = COM_SIGNAL_NOT_PASS_FILTER;
    Com_SignalIdType OccIndex = AlgPtr->OccIndex;

    if(Com_Sig_Occurrence[OccIndex] == *(const uint16*)AlgPtr->Par1)
    {
        ret = COM_SIGNAL_VALID;
    }
    if(Com_Sig_Occurrence[OccIndex] < *(const uint16*)AlgPtr->Par2)
    {
        Com_Sig_Occurrence[OccIndex]++;
    }
    if(Com_Sig_Occurrence[OccIndex] >= *(const uint16*)AlgPtr->Par2)
    {
        Com_Sig_Occurrence[OccIndex] = (uint16)0;
    }

    return ret;
}
#endif

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_CheckSignalValid
*
* Description:   Check whether the signal is valid.
*
* Inputs:        ValuePtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_SignalFilter_U8
(
    P2CONST(uint8, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 result = COM_SIGNAL_NOT_PASS_FILTER;
    Com_FilterAlgorithmType FilterType = AlgPtr->FilterType;
    switch(FilterType)
    {
    case COM_ALWAYS:
        result = COM_SIGNAL_VALID;
        break;
    case COM_NEVER:
        result = COM_SIGNAL_NOT_PASS_FILTER;
        break;
    case COM_MASKED_NEW_DIFFERS_MASKED_OLD:
        result = Com_Filter_MaskDiffersOld_U8(ValuePtr, AlgPtr);
        break;
    case COM_MASKED_NEW_DIFFERS_X:
        result = Com_Filter_MaskDiffersX_U8(ValuePtr, AlgPtr);
        break;
    case COM_MASKED_NEW_EQUALS_X:
        result = Com_Filter_MaskEqualsX_U8(ValuePtr, AlgPtr);
        break;
    case COM_NEW_IS_OUTSIDE:
        result = Com_Filter_OutSide_U8(ValuePtr, AlgPtr);
        break;
    case COM_NEW_IS_WITHIN:
        result = Com_Filter_WithIn_U8(ValuePtr, AlgPtr);
        break;
#if(COM_MAX_FILTER_OCCURRENCE_NUM > 0)
    case COM_ONE_EVERY_N:
        result = Com_Filter_OneEveryN(AlgPtr);
        break;
#endif
    default:
        break;
    }
    return result;
}
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_SignalFilter_U16
*
* Description:   Filter signal.
*
* Inputs:        ValuePtr
*                AlgPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_SignalFilter_U16
(
    P2CONST(uint16, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 result = COM_SIGNAL_NOT_PASS_FILTER;
    Com_FilterAlgorithmType FilterType = AlgPtr->FilterType;
    switch(FilterType)
    {
    case COM_ALWAYS:
        result = COM_SIGNAL_VALID;
        break;
    case COM_NEVER:
        result = COM_SIGNAL_NOT_PASS_FILTER;
        break;
    case COM_MASKED_NEW_DIFFERS_MASKED_OLD:
        result = Com_Filter_MaskDiffersOld_U16(ValuePtr, AlgPtr);
        break;
    case COM_MASKED_NEW_DIFFERS_X:
        result = Com_Filter_MaskDiffersX_U16(ValuePtr, AlgPtr);
        break;
    case COM_MASKED_NEW_EQUALS_X:
        result = Com_Filter_MaskEqualsX_U16(ValuePtr, AlgPtr);
        break;
    case COM_NEW_IS_OUTSIDE:
        result = Com_Filter_OutSide_U16(ValuePtr, AlgPtr);
        break;
    case COM_NEW_IS_WITHIN:
        result = Com_Filter_WithIn_U16(ValuePtr, AlgPtr);
        break;
#if(COM_MAX_FILTER_OCCURRENCE_NUM > 0)
    case COM_ONE_EVERY_N:
        result = Com_Filter_OneEveryN(AlgPtr);
        break;
#endif
    default:
        break;
    }
    return result;
}
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_SignalFilter_U32
*
* Description:   Filter signal.
*
* Inputs:        ValuePtr
*                AlgPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_SignalFilter_U32
(
    P2CONST(uint32, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 result = COM_SIGNAL_NOT_PASS_FILTER;
    Com_FilterAlgorithmType FilterType = AlgPtr->FilterType;
    switch(FilterType)
    {
    case COM_ALWAYS:
        result = COM_SIGNAL_VALID;
        break;
    case COM_NEVER:
        result = COM_SIGNAL_NOT_PASS_FILTER;
        break;
    case COM_MASKED_NEW_DIFFERS_MASKED_OLD:
        result = Com_Filter_MaskDiffersOld_U32(ValuePtr, AlgPtr);
        break;
    case COM_MASKED_NEW_DIFFERS_X:
        result = Com_Filter_MaskDiffersX_U32(ValuePtr, AlgPtr);
        break;
    case COM_MASKED_NEW_EQUALS_X:
        result = Com_Filter_MaskEqualsX_U32(ValuePtr, AlgPtr);
        break;
    case COM_NEW_IS_OUTSIDE:
        result = Com_Filter_OutSide_U32(ValuePtr, AlgPtr);
        break;
    case COM_NEW_IS_WITHIN:
        result = Com_Filter_WithIn_U32(ValuePtr, AlgPtr);
        break;
#if(COM_MAX_FILTER_OCCURRENCE_NUM > 0)
    case COM_ONE_EVERY_N:
        result = Com_Filter_OneEveryN(AlgPtr);
        break;
#endif
    default:
        break;
    }
    return result;
}
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_SignalFilter_U64
*
* Description:   Filter signal.
*
* Inputs:        ValuePtr
*                AlgPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_SignalFilter_U64
(
    P2CONST(uint64, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 result = COM_SIGNAL_NOT_PASS_FILTER;
    Com_FilterAlgorithmType FilterType = AlgPtr->FilterType;
    switch(FilterType)
    {
    case COM_ALWAYS:
        result = COM_SIGNAL_VALID;
        break;
    case COM_NEVER:
        result = COM_SIGNAL_NOT_PASS_FILTER;
        break;
    case COM_MASKED_NEW_DIFFERS_MASKED_OLD:
        result = Com_Filter_MaskDiffersOld_U64(ValuePtr, AlgPtr);
        break;
    case COM_MASKED_NEW_DIFFERS_X:
        result = Com_Filter_MaskDiffersX_U64(ValuePtr, AlgPtr);
        break;
    case COM_MASKED_NEW_EQUALS_X:
        result = Com_Filter_MaskEqualsX_U64(ValuePtr, AlgPtr);
        break;
    case COM_NEW_IS_OUTSIDE:
        result = Com_Filter_OutSide_U64(ValuePtr, AlgPtr);
        break;
    case COM_NEW_IS_WITHIN:
        result = Com_Filter_WithIn_U64(ValuePtr, AlgPtr);
        break;
#if(COM_MAX_FILTER_OCCURRENCE_NUM > 0)
    case COM_ONE_EVERY_N:
        result = Com_Filter_OneEveryN(AlgPtr);
        break;
#endif
    default:
        break;
    }
    return result;
}
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_SignalFilter_S8
*
* Description:   Filter signal.
*
* Inputs:        ValuePtr
*                AlgPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_SignalFilter_S8
(
    P2CONST(sint8, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 result = COM_SIGNAL_NOT_PASS_FILTER;
    Com_FilterAlgorithmType FilterType = AlgPtr->FilterType;
    switch(FilterType)
    {
    case COM_ALWAYS:
        result = COM_SIGNAL_VALID;
        break;
    case COM_NEVER:
        result = COM_SIGNAL_NOT_PASS_FILTER;
        break;
    case COM_MASKED_NEW_DIFFERS_MASKED_OLD:
        result = Com_Filter_MaskDiffersOld_S8(ValuePtr, AlgPtr);
        break;
    case COM_MASKED_NEW_DIFFERS_X:
        result = Com_Filter_MaskDiffersX_S8(ValuePtr, AlgPtr);
        break;
    case COM_MASKED_NEW_EQUALS_X:
        result = Com_Filter_MaskEqualsX_S8(ValuePtr, AlgPtr);
        break;
    case COM_NEW_IS_OUTSIDE:
        result = Com_Filter_OutSide_S8(ValuePtr, AlgPtr);
        break;
    case COM_NEW_IS_WITHIN:
        result = Com_Filter_WithIn_S8(ValuePtr, AlgPtr);
        break;
#if(COM_MAX_FILTER_OCCURRENCE_NUM > 0)
    case COM_ONE_EVERY_N:
        result = Com_Filter_OneEveryN(AlgPtr);
        break;
#endif
    default:
        break;
    }
    return result;
}
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_SignalFilter_S16
*
* Description:   Filter signal.
*
* Inputs:        ValuePtr
*                AlgPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_SignalFilter_S16
(
    P2CONST(sint16, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 result = COM_SIGNAL_NOT_PASS_FILTER;
    Com_FilterAlgorithmType FilterType = AlgPtr->FilterType;
    switch(FilterType)
    {
    case COM_ALWAYS:
        result = COM_SIGNAL_VALID;
        break;
    case COM_NEVER:
        result = COM_SIGNAL_NOT_PASS_FILTER;
        break;
    case COM_MASKED_NEW_DIFFERS_MASKED_OLD:
        result = Com_Filter_MaskDiffersOld_S16(ValuePtr, AlgPtr);
        break;
    case COM_MASKED_NEW_DIFFERS_X:
        result = Com_Filter_MaskDiffersX_S16(ValuePtr, AlgPtr);
        break;
    case COM_MASKED_NEW_EQUALS_X:
        result = Com_Filter_MaskEqualsX_S16(ValuePtr, AlgPtr);
        break;
    case COM_NEW_IS_OUTSIDE:
        result = Com_Filter_OutSide_S16(ValuePtr, AlgPtr);
        break;
    case COM_NEW_IS_WITHIN:
        result = Com_Filter_WithIn_S16(ValuePtr, AlgPtr);
        break;
#if(COM_MAX_FILTER_OCCURRENCE_NUM > 0)
    case COM_ONE_EVERY_N:
        result = Com_Filter_OneEveryN(AlgPtr);
        break;
#endif
    default:
        break;
    }
    return result;
}
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_SignalFilter_S32
*
* Description:   Filter signal.
*
* Inputs:        ValuePtr
*                AlgPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_SignalFilter_S32
(
    P2CONST(sint32, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 result = COM_SIGNAL_NOT_PASS_FILTER;
    Com_FilterAlgorithmType FilterType = AlgPtr->FilterType;
    switch(FilterType)
    {
    case COM_ALWAYS:
        result = COM_SIGNAL_VALID;
        break;
    case COM_NEVER:
        result = COM_SIGNAL_NOT_PASS_FILTER;
        break;
    case COM_MASKED_NEW_DIFFERS_MASKED_OLD:
        result = Com_Filter_MaskDiffersOld_S32(ValuePtr, AlgPtr);
        break;
    case COM_MASKED_NEW_DIFFERS_X:
        result = Com_Filter_MaskDiffersX_S32(ValuePtr, AlgPtr);
        break;
    case COM_MASKED_NEW_EQUALS_X:
        result = Com_Filter_MaskEqualsX_S32(ValuePtr, AlgPtr);
        break;
    case COM_NEW_IS_OUTSIDE:
        result = Com_Filter_OutSide_S32(ValuePtr, AlgPtr);
        break;
    case COM_NEW_IS_WITHIN:
        result = Com_Filter_WithIn_S32(ValuePtr, AlgPtr);
        break;
#if(COM_MAX_FILTER_OCCURRENCE_NUM > 0)
    case COM_ONE_EVERY_N:
        result = Com_Filter_OneEveryN(AlgPtr);
        break;
#endif
    default:
        break;
    }
    return result;
}
/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_SignalFilter_S64
*
* Description:   Filter signal.
*
* Inputs:        ValuePtr
*                AlgPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_SignalFilter_S64
(
    P2CONST(sint64, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 result = COM_SIGNAL_NOT_PASS_FILTER;
    Com_FilterAlgorithmType FilterType = AlgPtr->FilterType;
    switch(FilterType)
    {
    case COM_ALWAYS:
        result = COM_SIGNAL_VALID;
        break;
    case COM_NEVER:
        result = COM_SIGNAL_NOT_PASS_FILTER;
        break;
    case COM_MASKED_NEW_DIFFERS_MASKED_OLD:
        result = Com_Filter_MaskDiffersOld_S64(ValuePtr, AlgPtr);
        break;
    case COM_MASKED_NEW_DIFFERS_X:
        result = Com_Filter_MaskDiffersX_S64(ValuePtr, AlgPtr);
        break;
    case COM_MASKED_NEW_EQUALS_X:
        result = Com_Filter_MaskEqualsX_S64(ValuePtr, AlgPtr);
        break;
    case COM_NEW_IS_OUTSIDE:
        result = Com_Filter_OutSide_S64(ValuePtr, AlgPtr);
        break;
    case COM_NEW_IS_WITHIN:
        result = Com_Filter_WithIn_S64(ValuePtr, AlgPtr);
        break;
#if(COM_MAX_FILTER_OCCURRENCE_NUM > 0)
    case COM_ONE_EVERY_N:
        result = Com_Filter_OneEveryN(AlgPtr);
        break;
#endif
    default:
        break;
    }
    return result;
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_SignalFilter_F32F64U8N
*
* Description:   Filter signal.
*
* Inputs:        AlgPtr
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_SignalFilter_F32F64U8N
(
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
)
{
    uint8 result = COM_SIGNAL_NOT_PASS_FILTER;
    Com_FilterAlgorithmType FilterType = AlgPtr->FilterType;
    switch(FilterType)
    {
    case COM_ALWAYS:
        result = COM_SIGNAL_VALID;
        break;
    case COM_NEVER:
        result = COM_SIGNAL_NOT_PASS_FILTER; 
        break;
#if(COM_MAX_FILTER_OCCURRENCE_NUM > 0)
    case COM_ONE_EVERY_N:
        result = Com_Filter_OneEveryN(AlgPtr);
        break;
#endif
    default:
        break;
    }
    return result;
}

/* BEGIN_FUNCTION_HDR
*******************************************************************************
* Function Name: Com_TxSignalFilter
*
* Description:   Filter signal.
*
* Inputs:        ValuePtr
*                AlgPtr
*                SigType
*
* Outputs:       None
*
* Limitations:   None
*******************************************************************************
END_FUNCTION_HDR*/
FUNC(uint8, COM_CODE) Com_TxSignalFilter
(
    P2CONST(void, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr,
    Com_SigType SigType
)
{
    uint8 result = COM_SIGNAL_NOT_PASS_FILTER;
    switch(SigType)
    {
    case COM_SIG_BOOLEAN:
    case COM_SIG_U8:
        result = Com_SignalFilter_U8((const uint8*)ValuePtr, AlgPtr);
        break;
    case COM_SIG_S8:
        result = Com_SignalFilter_S8((const sint8*)ValuePtr, AlgPtr);
        break;
    case COM_SIG_U16:
        result = Com_SignalFilter_U16((const uint16*)ValuePtr, AlgPtr);
        break;
    case COM_SIG_S16:
        result = Com_SignalFilter_S16((const sint16*)ValuePtr, AlgPtr);
        break;
    case COM_SIG_U32:
        result = Com_SignalFilter_U32((const uint32*)ValuePtr, AlgPtr);
        break;
    case COM_SIG_S32:
        result = Com_SignalFilter_S32((const sint32*)ValuePtr, AlgPtr);
        break;
    case COM_SIG_U64:
        result = Com_SignalFilter_U64((const uint64*)ValuePtr, AlgPtr);
        break;
    case COM_SIG_S64:
        result = Com_SignalFilter_S64((const sint64*)ValuePtr, AlgPtr);
        break;
    case COM_SIG_F32:
    case COM_SIG_F64:
    case COM_SIG_U8N:
    case COM_SIG_DYN:
        result = Com_SignalFilter_F32F64U8N(AlgPtr);
        break;
    default:
        break;
    }
    return result;
}

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
