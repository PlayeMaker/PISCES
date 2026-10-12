/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : NvM_Queue.h
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
*   Revision History
*   Reference to NvM.c File
********************************************************************************
* END_FILE_HDR*/
#ifndef NVM_QUEUE_H
#define NVM_QUEUE_H

/*******************************************************************************
*   include
*******************************************************************************/
#include "NvM_Lcfg.h"


/*******************************************************************************
    Prototype  Declaration
*******************************************************************************/
#define NVM_START_SEC_CODE
#include "NvM_MemMap.h"

/* Clear all jobs */
extern FUNC(void, NVM_CODE) NvM_ClearJob(void);

/* Add job to queue */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_QueueJob
(
    const NvM_BlockIdType BlockId,
    const uint8 ServiceId,
    CONSTP2VAR(uint8, AUTOMATIC, NVM_APPL_DATA)  ramAddr
);

/* Get job from queue */
extern FUNC(Std_ReturnType, NVM_CODE) NvM_GetJob
(
    CONSTP2VAR(NvM_QueBuf_Type, AUTOMATIC, AUTOMATIC) Job
);
extern FUNC(Std_ReturnType, NVM_CODE) NvM_DeleteAllPengdingJobOfBlock
(
    const NvM_BlockIdType BlockId
);
extern FUNC(boolean, NVM_CODE) NvM_CheckBlockPending
(
    const NvM_BlockIdType BlockId,
    const boolean isWriteJob
);
extern FUNC(boolean, NVM_CODE) NvM_IsQueueEmpty(void);
extern FUNC(boolean, NVM_CODE) NvM_IsMultiJobEmpty(void);



#define NVM_STOP_SEC_CODE
#include "NvM_MemMap.h"

#endif /* #ifndef _NVM_QUEUE_H */


