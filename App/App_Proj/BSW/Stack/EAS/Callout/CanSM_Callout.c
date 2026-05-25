/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanSM_Callout.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanSM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanSM module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/

/*PRQA S 3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR specification,when locating address segments in the files of each module.
*/
/*PRQA S 3206 EOF*/
/*
input parameters of functions in generated files are not used.
*/
/*PRQA S 1532 EOF*/
/*
Function are called in core code.
*/

/*PRQA S 380 EOF*/
/*
Number of macro definitions exceeds 4095 -program does not conform strictly to ISO:C99.
*/

/*PRQA S 857 EOF*/
/*
Number of macro definitions exceeds 1024 -program does not conform strictly to ISO:C90.
*/

/*PRQA S 5087 EOF*/
/*
Use of #include directive after code fragment.
*/



/*******************************************************************************
*   Includes
*******************************************************************************/
#include "CanSM.h"


/*Input File User Code start*/

/*Input File User Code end*/
#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.h"

FUNC(void, CANSM_CODE) CanSM_EnterBorL1_Indication
(
    NetworkHandleType Channel
)
{

/*CanSM_EnterBorL1_Indication User Code start*/

/*CanSM_EnterBorL1_Indication User Code end*/
}

FUNC(void, CANSM_CODE) CanSM_EnterBorL2_Indication
(
    NetworkHandleType Channel
)
{

/*CanSM_EnterBorL2_Indication User Code start*/

/*CanSM_EnterBorL2_Indication User Code end*/
}

FUNC(void, CANSM_CODE) CanSM_BORSuccess_Indication
(
    NetworkHandleType Channel
)
{

/*CanSM_BORSuccess_Indication User Code start*/

/*CanSM_BORSuccess_Indication User Code end*/
}

FUNC(void, CANSM_CODE) CanSM_BusOff_Indication
(
    uint8 ControllerId
)
{

/*CanSM_BusOff_Indication User Code start*/

/*CanSM_BusOff_Indication User Code end*/
}

#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.h"


