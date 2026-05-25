
/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : MemIf_Types.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : MemIf_Types.h
*   Author          : Hirain
********************************************************************************
*   Description     : AUTOSAR MemIf types file
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to MemIf.c File
********************************************************************************
* END_FILE_HDR*/
#ifndef MEMIF_TYPES_H
#define MEMIF_TYPES_H

/*******************************************************************************
    Includes Files
*******************************************************************************/
#include "MemIf_Version.h"

/*******************************************************************************
*   Enum Types  SWS_MemIf_00064 65 66
*******************************************************************************/
typedef enum
{
    MEMIF_UNINIT,
    MEMIF_IDLE,
    MEMIF_BUSY,
    MEMIF_BUSY_INTERNAL
} MemIf_StatusType;

typedef enum
{
    MEMIF_JOB_OK,
    MEMIF_JOB_FAILED,
    MEMIF_JOB_PENDING,
    MEMIF_JOB_CANCELED,
    MEMIF_BLOCK_INCONSISTENT,
    MEMIF_BLOCK_INVALID
} MemIf_JobResultType;

typedef enum
{
    MEMIF_MODE_SLOW,
    MEMIF_MODE_FAST
} MemIf_ModeType;

#endif
