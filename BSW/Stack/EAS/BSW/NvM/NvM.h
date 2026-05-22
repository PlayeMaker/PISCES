/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : NvM.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : NvM module header File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of Non-Volatile RAM manager.
*
********************************************************************************
*   Limitations     :
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to NvM.c File
********************************************************************************
* END_FILE_HDR*/

/*PRQA S 776 EOF*/
/*
Names in core files may not follow relevant rules..
*/

#ifndef NVM_H
#define NVM_H

/*******************************************************************************
*   Include
*******************************************************************************/
#include "NvM_Queue.h"
#include "NvM_JobProc.h"


/*******************************************************************************
*   Macro
*******************************************************************************/

/*******************************************************************************
*   Declaration
*******************************************************************************/

/*******************************************************************************
*   Function  Declaration
*******************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

extern FUNC(void, NVM_CODE) NvM_Init
(
    P2CONST(NvM_ConfigType, AUTOMATIC, NVM_CONST) ConfigPtr
);

#if ((NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)\
||(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2))

#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)
extern FUNC(Std_ReturnType, NVM_CODE) NvM_SetDataIndex
(
    NvM_BlockIdType BlockId,
    uint8 DataIndex
);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_GetDataIndex
(
    NvM_BlockIdType BlockId,
    P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) DataIndexPtr
);
#endif

extern FUNC(Std_ReturnType, NVM_CODE) NvM_ReadBlock
(
    NvM_BlockIdType BlockId,
    P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr
);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_ReadBlockAgent
(
    NvM_BlockIdType BlockId,
    P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr
);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_ReadPRAMBlock
(
    NvM_BlockIdType BlockId
);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_ReadPRAMBlockAgent
(
    NvM_BlockIdType BlockId
);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_WriteBlock
(
    NvM_BlockIdType BlockId,
    P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_SrcPtr
);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_WriteBlockAgent
(
    NvM_BlockIdType BlockId,
    P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_SrcPtr
);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_WritePRAMBlock
(
    NvM_BlockIdType BlockId
);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_WritePRAMBlockAgent
(
    NvM_BlockIdType BlockId
);

#if(STD_ON == NVM_CANCELJOB_API)
extern FUNC(Std_ReturnType, NVM_CODE) NvM_CancelJobs
(
    NvM_BlockIdType BlockId
);
#endif

extern FUNC(Std_ReturnType, NVM_CODE) NvM_RestoreBlockDefaults
(
    NvM_BlockIdType BlockId,
    P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DestPtr
);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_RestoreBlockDefaultsAgent
(
    NvM_BlockIdType BlockId,
    P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DestPtr
);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_RestorePRAMBlockDefaults
(
    NvM_BlockIdType BlockId
);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_RestorePRAMBlockDefaultsAgent
(
    NvM_BlockIdType BlockId
);

#endif

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)

#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
extern FUNC(Std_ReturnType, NVM_CODE) NvM_SetBlockProtection
(
    NvM_BlockIdType BlockId,
    boolean ProtectionEnabled
);
#endif

#if(STD_ON == NVM_ERASE_API)
extern FUNC(Std_ReturnType, NVM_CODE) NvM_EraseNvBlock
(
    NvM_BlockIdType BlockId
);

extern FUNC(Std_ReturnType, NVM_CODE) NvM_EraseNvBlockAgent
(
    NvM_BlockIdType BlockId
);
#endif

#if(STD_ON == NVM_INVALID_NVBLOCK_API)
extern FUNC(Std_ReturnType, NVM_CODE) NvM_InvalidateNvBlock
(
    NvM_BlockIdType BlockId
);
extern FUNC(Std_ReturnType, NVM_CODE) NvM_InvalidateNvBlockAgent
(
    NvM_BlockIdType BlockId
);
#endif

#endif

extern FUNC(Std_ReturnType, NVM_CODE) NvM_GetErrorStatus
(
    NvM_BlockIdType BlockId,
    P2VAR(NvM_RequestResultType, AUTOMATIC, NVM_APPL_DATA) RequestResultPtr
);

#if (NVM_SET_RAM_BLOCK_STATUS_API == STD_ON)
extern FUNC(Std_ReturnType, NVM_CODE) NvM_SetRamBlockStatus
(
    NvM_BlockIdType BlockId,
    boolean BlockChanged
);
#endif

#if(STD_ON == NVM_SET_BLOCK_LOCK_API)
extern FUNC(void, NVM_CODE) NvM_SetBlockLockStatus
(
    NvM_BlockIdType BlockId,
    boolean BlockLocked
);
#endif

#if ((NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)\
||(NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_2))
extern FUNC(void, NVM_CODE) NvM_ValidateAll ( void );
#endif


#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
extern FUNC(void, NVM_CODE) NvM_FirstInitAll( void );
#endif


extern FUNC(void, NVM_CODE) NvM_ReadAll( void );

extern FUNC(void, NVM_CODE) NvM_WriteAll ( void );

extern FUNC(void, NVM_CODE) NvM_CancelWriteAll( void );

extern FUNC(void, NVM_CODE) NvM_MainFunction( void );


#if(NVM_VERSION_INFO_API == STD_ON)
extern FUNC(void, NVM_CODE) NvM_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, NVM_APPL_DATA) versioninfo
);
#endif


#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#endif /*  #ifndef _NvM_H */


