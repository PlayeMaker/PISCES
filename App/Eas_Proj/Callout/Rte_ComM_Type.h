/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_ComM_Type.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Rte module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Rte module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/
#ifndef RTE_COMM_TYPE_H
#define RTE_COMM_TYPE_H
/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Rte_Type.h"

#ifndef RTE_MODETYPE_ComMMode
#define RTE_MODETYPE_ComMMode
typedef uint8 Rte_ModeType_ComMMode;
#endif
#ifndef RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION
#define RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION           (Rte_ModeType_ComMMode)0
#endif
#ifndef RTE_MODE_ComMMode_COMM_NO_COMMUNICATION
#define RTE_MODE_ComMMode_COMM_NO_COMMUNICATION             (Rte_ModeType_ComMMode)1
#endif
#ifndef RTE_MODE_ComMMode_COMM_SILENT_COMMUNICATION
#define RTE_MODE_ComMMode_COMM_SILENT_COMMUNICATION         (Rte_ModeType_ComMMode)2
#endif
#ifndef RTE_TRANSITION_ComMMode
#define RTE_TRANSITION_ComMMode                             (Rte_ModeType_ComMMode)3
#endif

#endif



