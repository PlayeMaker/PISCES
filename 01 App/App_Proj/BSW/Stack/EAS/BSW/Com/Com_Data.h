/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name:       Com_Data.h
********************************************************************************
*   Project/Product: AUTOSAR R21-11
*   Title:           Com_Data.h
*   Author:          Hirain
********************************************************************************
*   Description:     Defination of Interface for Application Layer
*
********************************************************************************
*   Limitations:      None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Core C File
********************************************************************************
*END_FILE_HDR*/

#ifndef COM_DATA_H
#define COM_DATA_H
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Com_Types.h"

/*******************************************************************************
*   Macro
*******************************************************************************/
#define COM_BYTE_SIZE 8
#define COM_CHAR_SIZE 1
#define COM_SHORT_SIZE 2
#define COM_INT_SIZE 4
#define COM_LONG_SIZE 8
#define COM_THREE_BIT 3
#define COM_REMAIN_MASK 0x7

#define COM_MASK_8(BitSize)  (0xFF >> (8-BitSize))
#define COM_MASK_16(BitSize) (0xFFFF >> (16-BitSize))
#define COM_MASK_32(BitSize) (0xFFFFFFFF >> (32-BitSize))
#define COM_MASK_64(BitSize) (0xFFFFFFFFFFFFFFFF >> (64-BitSize))
/*******************************************************************************
*   Function Declaration
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

extern FUNC(void, COM_CODE) Com_WriteSignal
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
);
extern FUNC(void, COM_CODE) Com_ReadSignal
(
    P2VAR(void, AUTOMATIC, COM_VAR) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    Com_SigType SigType,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask,
    PduLengthType ByteLength
);
extern FUNC(boolean, COM_CODE) Com_CheckChangeSignalInPdu
(
    P2CONST(void, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    Com_EndiannessType Endianness,
    Com_SigType SigType,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask,
    PduLengthType ByteLength
);
extern FUNC(boolean, COM_CODE) Com_CheckChangeSignal
(
    P2VAR(void, AUTOMATIC, COM_CONST) NewValuePtr,
    P2VAR(void, AUTOMATIC, COM_CONST) OldValuePtr,
    Com_SigType SigType,
    PduLengthType ByteLength
);
#if 0
extern FUNC(boolean, COM_CODE) Com_MoveSignal
(
    P2VAR(uint8, AUTOMATIC, COM_VAR) SrcPduPtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) DestPduPtr,
    Com_EndiannessType Endianness,
    Com_SigType SigType,
    uint16 BitSize,
    uint16 StartBit,
    PduLengthType ByteLength
);
#endif
extern FUNC(void, COM_CODE) Com_CopySignalWithOutLock
(
    P2CONST(void, AUTOMATIC, COM_CONST) SrcPtr,
    P2VAR(void, AUTOMATIC, COM_VAR) DestPtr,
    Com_SigType SigType,
    PduLengthType ByteLength
);

extern FUNC(void, COM_CODE) Com_ReadSignal_LittleU8
(
    P2VAR(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_BigU8
(
    P2VAR(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_LittleS8
(
    P2VAR(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_BigS8
(
    P2VAR(sint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_LittleU16
(
    P2VAR(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_BigU16
(
    P2VAR(uint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_LittleS16
(
    P2VAR(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_BigS16
(
    P2VAR(sint16, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_LittleU32
(
    P2VAR(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_BigU32
(
    P2VAR(uint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_LittleS32
(
    P2VAR(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_BigS32
(
    P2VAR(sint32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_LittleF32
(
    P2VAR(float32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_BigF32
(
    P2VAR(float32, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_LittleU64
(
    P2VAR(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_BigU64
(
    P2VAR(uint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_LittleS64
(
    P2VAR(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_BigS64
(
    P2VAR(sint64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_LittleF64
(
    P2VAR(float64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_BigF64
(
    P2VAR(float64, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    uint16 BitSize,
    uint16 StartBit,
    uint64 Mask
);
extern FUNC(void, COM_CODE) Com_ReadSignal_U8N
(
    P2VAR(uint8, AUTOMATIC, COM_VAR) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    PduLengthType ByteLength,
    uint16 StartBit
);
extern FUNC(boolean, COM_CODE) Com_CheckChangeSignal_U8N
(
    P2CONST(uint8, AUTOMATIC, COM_CONST) ValuePtr,
    P2VAR(uint8, AUTOMATIC, COM_VAR) PduPtr,
    PduLengthType ByteLength,
    uint16 StartBit
);
extern FUNC(uint8, COM_CODE) Com_SignalFilter_U8
(
    P2CONST(uint8, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
extern FUNC(uint8, COM_CODE) Com_SignalFilter_U16
(
    P2CONST(uint16, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
extern FUNC(uint8, COM_CODE) Com_SignalFilter_U32
(
    P2CONST(uint32, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
extern FUNC(uint8, COM_CODE) Com_SignalFilter_U64
(
    P2CONST(uint64, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
extern FUNC(uint8, COM_CODE) Com_SignalFilter_S8
(
    P2CONST(sint8, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
extern FUNC(uint8, COM_CODE) Com_SignalFilter_S16
(
    P2CONST(sint16, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
extern FUNC(uint8, COM_CODE) Com_SignalFilter_S32
(
    P2CONST(sint32, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
extern FUNC(uint8, COM_CODE) Com_SignalFilter_S64
(
    P2CONST(sint64, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
extern FUNC(uint8, COM_CODE) Com_SignalFilter_F32F64U8N
(
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr
);
extern FUNC(uint8, COM_CODE) Com_TxSignalFilter
(
    P2CONST(void, AUTOMATIC, COM_VAR) ValuePtr,
    P2CONST(Com_CfgSigFilterParsType, AUTOMATIC, COM_CONST) AlgPtr,
    Com_SigType SigType
);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#endif
