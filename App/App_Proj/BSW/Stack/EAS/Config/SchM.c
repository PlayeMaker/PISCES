/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : SchM.c
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

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 380 EOF*/
/*
Number of macro definitions exceeds 4095 -program does not conform strictly to ISO:C99.
*/

/*PRQA S 777 EOF*/
/*
external identifier does not differ from other identifier within the specified number of significant characters.
*/

/*PRQA S 857 EOF*/
/*
Number of macro definitions exceeds 1024 -program does not conform strictly to ISO:C90.
*/

/*PRQA S 3206 EOF*/
/*
The parameter 'nextMode' is not used in this function.
*/

/*PRQA S 3214 EOF*/
/*
The macro 'RTE_START_SEC_XXX' is not used and could be removed.
*/

/*PRQA S 3408 EOF*/
/*
XXX has external linkage and is being defined without any previous declaration.
*/

/*PRQA S 5087 EOF*/
/*
Use of #include directive after code fragment.
*/

/*******************************************************************************
*   Includes.
*******************************************************************************/

#include "SchM.h"
/*SchM.c Header File User Code start*/

/*SchM.c Header File User Code end*/
#include "Rte_Private_Var.h"

/*******************************************************************************
*   Var.
*******************************************************************************/


/*SchM.c Var User Code start*/

/*SchM.c Var User Code end*/

/*******************************************************************************
*   Rte Api
*******************************************************************************/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"

FUNC(void, RTE_CODE) SchM_Init(P2CONST(uint8, AUTOMATIC, RTE_CONST) ConfigPtr)
{
    Rte_VarCfgPtr = ConfigPtr;


}


FUNC(void, RTE_CODE) SchM_Deinit(void)
{
}



FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmCommunicationControl_ComM_BODY_LE1_CAN
(
    CONST(Rte_ModeType_DcmCommunicationControl_ComM_BODY_LE1_CAN, AUTOMATIC) nextMode
)
{
    Std_ReturnType ret = RTE_E_OK;
    /*SchM_Switch_Dcm_DcmCommunicationControl_ComM_BODY_LE1_CAN User Code start*/

    /*SchM_Switch_Dcm_DcmCommunicationControl_ComM_BODY_LE1_CAN User Code end*/

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmControlDtcSetting
(
    CONST(Rte_ModeType_DcmControlDtcSetting, AUTOMATIC) nextMode
)
{
    Std_ReturnType ret = RTE_E_OK;
    /*SchM_Switch_Dcm_DcmControlDtcSetting User Code start*/

    /*SchM_Switch_Dcm_DcmControlDtcSetting User Code end*/

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmDiagnosticSessionControl
(
    CONST(Rte_ModeType_DcmDiagnosticSessionControl, AUTOMATIC) nextMode
)
{
    Std_ReturnType ret = RTE_E_OK;
    /*SchM_Switch_Dcm_DcmDiagnosticSessionControl User Code start*/

    /*SchM_Switch_Dcm_DcmDiagnosticSessionControl User Code end*/

    return ret;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : SystemSoftwareReset
 * Description   : This function is used to initiate a system reset
 *
 * Implements    : SystemSoftwareReset_Activity
 *END**************************************************************************/
void SystemSoftwareReset(void)
{
    Mcu_PerformReset();
}



static uint8 Dcm_ResetMode = 0xFF;
FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmEcuReset
(
    VAR(Rte_ModeType_DcmEcuReset, AUTOMATIC) nextMode
)
{
    /* SchM_Switch_Dcm_DcmEcuReset User Code start*/
    if(RTE_MODE_DcmEcuReset_EXECUTE != nextMode)
    {
        Dcm_ResetMode = nextMode;
    }
    else
    {
        if((RTE_MODE_DcmEcuReset_JUMPTOBOOTLOADER ==
Dcm_ResetMode))
        {
            Dcm_ResetMode = 0xFF;
            SystemSoftwareReset();
        }
        if((RTE_MODE_DcmEcuReset_HARD == Dcm_ResetMode))
        {
            Dcm_ResetMode = 0xFF;
            SystemSoftwareReset();
        }
        if((RTE_MODE_DcmEcuReset_SOFT == Dcm_ResetMode))
        {
            Dcm_ResetMode = 0xFF;
            SystemSoftwareReset();
        }
    }
    return RTE_E_OK;
    /* SchM_Switch_Dcm_DcmEcuReset User Code end*/
}
FUNC(Std_ReturnType, RTE_CODE) SchM_Switch_Dcm_DcmSecurityAccess
(
    CONST(Rte_ModeType_DcmSecurityAccess, AUTOMATIC) nextMode
)
{
    Std_ReturnType ret = RTE_E_OK;
    /*SchM_Switch_Dcm_DcmSecurityAccess User Code start*/

    /*SchM_Switch_Dcm_DcmSecurityAccess User Code end*/

    return ret;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"



