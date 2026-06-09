/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_EcuM_Type.h
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
#ifndef RTE_ECUM_TYPE_H
#define RTE_ECUM_TYPE_H
/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Rte_Type.h"

#ifndef RTE_MODETYPE_EcuM_Mode
#define RTE_MODETYPE_EcuM_Mode
typedef uint8 Rte_ModeType_EcuM_Mode;
#endif
#ifndef RTE_MODE_EcuM_Mode_POST_RUN
#define RTE_MODE_EcuM_Mode_POST_RUN                         (Rte_ModeType_EcuM_Mode)0
#endif
#ifndef RTE_MODE_EcuM_Mode_RUN
#define RTE_MODE_EcuM_Mode_RUN                              (Rte_ModeType_EcuM_Mode)1
#endif
#ifndef RTE_MODE_EcuM_Mode_SHUTDOWN
#define RTE_MODE_EcuM_Mode_SHUTDOWN                         (Rte_ModeType_EcuM_Mode)2
#endif
#ifndef RTE_MODE_EcuM_Mode_SLEEP
#define RTE_MODE_EcuM_Mode_SLEEP                            (Rte_ModeType_EcuM_Mode)3
#endif
#ifndef RTE_MODE_EcuM_Mode_STARTUP
#define RTE_MODE_EcuM_Mode_STARTUP                          (Rte_ModeType_EcuM_Mode)4
#endif
#ifndef RTE_TRANSITION_EcuM_Mode
#define RTE_TRANSITION_EcuM_Mode                            (Rte_ModeType_EcuM_Mode)5
#endif

#endif



