/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_Main.h
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
#ifndef RTE_MAIN_H
#define RTE_MAIN_H
/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Rte.h"

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

/*Rte*/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void);



/*SchM*/
extern FUNC(void, RTE_CODE) SchM_Init
(
    P2CONST(uint8, AUTOMATIC, RTE_CONST) ConfigPtr
);
extern FUNC(void, RTE_CODE) SchM_Deinit(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#endif



