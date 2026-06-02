/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Com_Callout.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Com module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Com module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/

/*******************************************************************************
*  General QAC Suppression
*******************************************************************************/
/*PRQA S 3214,0862,3614,3212 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address 
segments in the files of each module,#include "Com_MemMap.h" is required.Defined 
XXX_START_SEC_ will undefine in Com_MemMap.h
Different types of transformations may be different from different configurations.
*/
/*PRQA S 1503,1532 EOF*/
/*
Api used by other modules.
*/

#include "Com.h"
#include "Rte_Com.h"
/*Com_Callout.c Header File User Code start*/
#include "Basic_Config.h"
#include "Rte_Private_Type.h"
/*Com_Callout.c Header File User Code end*/
/*******************************************************************************
*   Callout declare
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"

FUNC(void, COM_CODE) Com_CbkRxPduTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C
(
    void
)
{
    /*Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C User Code start*/

    /*Com_CbkRxTOut_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1 User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_DrvState User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd5
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd5 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd5 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd5
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd5 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd5 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd5
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd5 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd5 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd6
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd6 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd6 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd7
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd7 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd7 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd8
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd8 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd8 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd6
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd6 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd6 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd6
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd6 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd6 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd7
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd7 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd7 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd7
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd7 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd7 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd8
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd8 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd8 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd8
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd8 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd8 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd9
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd9 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd9 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd9
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd9 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd9 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd9
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd9 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd9 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd10
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd10 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgLvlCmd10 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd10
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd10 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgTimesCmd10 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd10
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd10 User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_MCM_05_DrvKneadingMassgSkillsCmd10 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat1_pct
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat1_pct User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat1_pct User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat2_pct
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat2_pct User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat2_pct User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat3_pct
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat3_pct User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat3_pct User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat4_pct
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat4_pct User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat4_pct User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat5_pct
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat5_pct User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat5_pct User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat6_pct
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat6_pct User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_1C9_DrvHeat6_pct User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve1Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve1Cmd User Code start*/
#if defined(PISCES_MCM_D)
    Rte_Call_Event_Cfg_D_Event_0xF1D187_SetEventStatus(DEM_EVENT_STATUS_FAILED);
#elif defined(PISCES_MCM_P)
    Rte_Call_Event_Cfg_P_Event_0xF1D187_SetEventStatus(DEM_EVENT_STATUS_FAILED);
#endif
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve1Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve1Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve1Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve1Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve2Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve2Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve2Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve2Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve2Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve2Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve3Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve3Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve3Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve3Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve3Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve3Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve4Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve4Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve4Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve4Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve4Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve4Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve5Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve5Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve5Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve5Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve5Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve5Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve6Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve6Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve6Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve6Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve6Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve6Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve7Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve7Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve7Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve7Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve7Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve7Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve8Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve8Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve8Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve8Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve8Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve8Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve9Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve9Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve9Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve9Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve9Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve9Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve10Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve10Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve10Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve10Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve10Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve10Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve11Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve11Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve11Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve11Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve11Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve11Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve12Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve12Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve12Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve12Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve12Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgValve12Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat1Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat1Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat1Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat1Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat1Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat1Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat2Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat2Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat2Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat2Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat2Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat2Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat3Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat3Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat3Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat3Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat3Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat3Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat4Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat4Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat4Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat4Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat4Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat4Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat5Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat5Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat5Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat5Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat5Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat5Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat6Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat6Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat6Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat6Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat6Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat6Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat7Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat7Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat7Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat7Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat7Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat7Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat8Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat8Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat8Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat8Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat8Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat8Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat9Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat9Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat9Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat9Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat9Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat9Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat10Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat10Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat10Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat10Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat10Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat10Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat11Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat11Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat11Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat11Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat11Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat11Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat12Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat12Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat12Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat12Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat12Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatmassgHeat12Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarTopValue1Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarTopValue1Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarTopValue1Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarTopValue1Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarTopValue1Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarTopValue1Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarMidValue2Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarMidValue2Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarMidValue2Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarMidValue2Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarMidValue2Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarMidValue2Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarBottomValue3Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarBottomValue3Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarBottomValue3Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarBottomValue3Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarBottomValue3Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatLumbarBottomValue3Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBLCmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBLCmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBLCmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBLCmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBLCmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBLCmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBRCmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBRCmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBRCmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBRCmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBRCmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatBolsterValueBRCmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue6Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue6Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue6Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue6Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue6Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue6Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue5Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue5Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue5Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue5Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue5Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue5Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue4Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue4Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue4Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue4Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue4Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_01_DrvSeatCushionValue4Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvPumpCmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvPumpCmd User Code start*/
#if defined(PISCES_MCM_D)
    Rte_Call_Event_Cfg_D_Event_0xF1D287_SetEventStatus(DEM_EVENT_STATUS_FAILED);
#elif defined(PISCES_MCM_P)
    Rte_Call_Event_Cfg_P_Event_0xF1D287_SetEventStatus(DEM_EVENT_STATUS_FAILED);
#endif
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvPumpCmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvPumpCmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvPumpCmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvPumpCmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueLCmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueLCmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueLCmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueLCmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueLCmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueLCmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueMCmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueMCmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueMCmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueMCmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueMCmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueMCmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue2Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue2Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue2Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue2Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue2Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue2Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueRCmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueRCmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueRCmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueRCmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueRCmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatUpperValueRCmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue3Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue3Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue3Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue3Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue3Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue3Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue1Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue1Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue1Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue1Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue1Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_Zone_FL_MCM_02_DrvSeatCushionValue1Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Yr
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Yr User Code start*/
#if defined(PISCES_MCM_D)
    Rte_Call_Event_Cfg_D_Event_0xF3B287_SetEventStatus(DEM_EVENT_STATUS_FAILED);
#elif defined(PISCES_MCM_P)
    Rte_Call_Event_Cfg_P_Event_0xF3B287_SetEventStatus(DEM_EVENT_STATUS_FAILED);
#endif
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Yr User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Yr
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Yr User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Yr User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Mth
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Mth User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Mth User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Mth
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Mth User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Mth User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Day
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Day User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Day User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Day
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Day User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Day User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Hr
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Hr User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Hr User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Hr
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Hr User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Hr User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Min
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Min User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Min User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Min
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Min User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Min User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Sec
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Sec User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Sec User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Sec
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Sec User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_Sec User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_MSec
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_MSec User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_MSec User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_MSec
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_MSec User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_3B2_MSec User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload User Code start*/

    /*Rte_COMCbk_Com_Cfg_D_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts5
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts5 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts5 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts6
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts6 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts6 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts5
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts5 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts5 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts6
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts6 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts6 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts7
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts7 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts7 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts8
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts8 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassglvlSts8 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts7
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts7 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts7 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts8
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts8 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgSkillsSts8 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime8
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime8 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime8 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime5
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime5 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime5 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime6
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime6 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime6 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime7
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime7 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1B6_DrvKneadingMassgTime7 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvMassSwitchSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvMassSwitchSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvMassSwitchSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgHeatCSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgHeatCSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgHeatCSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarValueSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarValueSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarValueSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgValveSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgValveSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatmassgValveSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatUpperValueSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatUpperValueSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatUpperValueSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValueSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValueSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValueSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBlosterValueSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBlosterValueSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBlosterValueSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarTopPos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarTopPos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarTopPos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarMidPos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarMidPos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarMidPos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarBottomPos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarBottomPos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatLumbarBottomPos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBLPos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBLPos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBLPos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBRPos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBRPos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatBolsterValueBRPos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValue6Pos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValue6Pos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1DF_DrvSeatCushionValue6Pos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue5Pos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue5Pos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue5Pos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue4Pos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue4Pos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue4Pos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue2Pos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue2Pos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue2Pos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue1Pos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue1Pos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatCushionValue1Pos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueLPos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueLPos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueLPos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueMPos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueMPos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueMPos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueRPos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueRPos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvSeatUpperValueRPos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvPumpSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvPumpSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E0_DrvPumpSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgSkillsSts9
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgSkillsSts9 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgSkillsSts9 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumControlSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumControlSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumControlSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumSwitchSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumSwitchSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumSwitchSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSystemFailr
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSystemFailr User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSystemFailr User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatMassFailr
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatMassFailr User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatMassFailr User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatCushionValue3Pos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatCushionValue3Pos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvSeatCushionValue3Pos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarTopWorkSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarTopWorkSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarTopWorkSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarMidWorkSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarMidWorkSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarMidWorkSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarBottomWorkSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarBottomWorkSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvLumbarBottomWorkSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat1Sts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat1Sts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat1Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat2Sts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat2Sts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat2Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat3Sts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat3Sts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat3Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat4Sts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat4Sts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat4Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5Sts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5Sts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat6Sts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat6Sts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat6Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5ErrSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5ErrSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvHeat5ErrSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassglvlSts9
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassglvlSts9 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassglvlSts9 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgTime9
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgTime9 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E1_DrvKneadingMassgTime9 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgTime10
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgTime10 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgTime10 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgSkillsSts10
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgSkillsSts10 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassgSkillsSts10 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassglvlSts10
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassglvlSts10 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvKneadingMassglvlSts10 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC1
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC1 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC1 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC2
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC2 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC2 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC3
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC3 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC3 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC4
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC4 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC4 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC5
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC5 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC5 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC6
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC6 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1E8_DrvMassageHeatNTC6 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC7
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC7 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC7 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC8
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC8 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC8 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC9
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC9 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC9 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC10
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC10 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC10 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC11
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC11 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC11 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC12
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC12 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_D_Tx_BODY_LE1_CAN_MCM_D_1EC_DrvMassageHeatNTC12 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpdSts_Rdnt1 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_BCU_11E_VehSpd_Rdnt1 User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC User Code start*/
#if defined(PISCES_MCM_D)
    Rte_Call_Event_Cfg_D_Event_0xF13C87_SetEventStatus(DEM_EVENT_STATUS_FAILED);
#elif defined(PISCES_MCM_P)
    Rte_Call_Event_Cfg_P_Event_0xF13C87_SetEventStatus(DEM_EVENT_STATUS_FAILED);
#endif
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_CRC User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_ZONE_13C_MsgCntr User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState_SrvSts User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState_SrvSts User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed_SrvSts User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_DrvState User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_OperatorState User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehStateDetailed User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_13C_VehModeDef User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd5
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd5 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd5 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd5
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd5 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd5 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd5
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd5 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd5 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd6
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd6 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd6 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd7
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd7 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd7 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd8
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd8 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd8 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd6
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd6 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd6 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd6
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd6 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd6 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd7
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd7 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd7 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd7
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd7 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd7 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd8
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd8 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd8 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd8
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd8 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd8 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd9
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd9 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd9 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd9
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd9 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd9 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd10
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd10 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgSkillsCmd10 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd10
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd10 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgTimesCmd10 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd9
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd9 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd9 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd10
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd10 User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_MCM_06_PassKneadingMassgLvlCmd10 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat1_pct
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat1_pct User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat1_pct User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat2_pct
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat2_pct User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat2_pct User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat3_pct
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat3_pct User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat3_pct User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat4_pct
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat4_pct User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat4_pct User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat5_pct
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat5_pct User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat5_pct User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat6_pct
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat6_pct User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_1CF_PassHeat6_pct User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve1Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve1Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve1Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve1Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve1Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve1Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve2Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve2Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve2Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve2Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve2Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve2Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve3Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve3Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve3Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve3Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve3Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve3Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve4Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve4Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve4Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve4Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve4Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve4Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve5Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve5Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve5Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve5Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve5Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve5Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve6Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve6Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve6Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve6Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve6Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve6Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve7Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve7Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve7Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve7Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve7Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve7Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve8Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve8Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve8Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve8Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve8Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve8Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve9Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve9Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve9Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve9Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve9Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve9Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve10Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve10Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve10Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve10Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve10Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve10Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve11Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve11Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve11Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve11Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve11Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve11Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve12Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve12Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve12Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve12Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve12Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgValve12Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat1Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat1Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat1Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat1Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat1Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat1Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat2Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat2Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat2Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat2Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat2Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat2Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat3Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat3Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat3Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat3Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat3Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat3Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat4Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat4Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat4Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat4Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat4Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat4Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat5Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat5Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat5Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat5Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat5Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat5Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat6Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat6Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat6Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat6Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat6Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat6Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat7Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat7Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat7Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat7Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat7Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat7Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat8Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat8Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat8Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat8Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat8Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat8Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat9Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat9Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat9Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat9Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat9Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat9Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat10Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat10Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat10Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat10Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat10Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat10Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat11Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat11Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat11Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat11Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat11Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat11Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat12Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat12Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat12Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat12Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat12Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatmassgHeat12Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarTopValue1Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarTopValue1Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarTopValue1Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarTopValue1Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarTopValue1Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarTopValue1Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarMidValue2Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarMidValue2Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarMidValue2Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarMidValue2Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarMidValue2Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarMidValue2Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarBottomValue3Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarBottomValue3Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarBottomValue3Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarBottomValue3Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarBottomValue3Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatLumbarBottomValue3Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBLCmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBLCmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBLCmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBLCmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBLCmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBLCmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBRCmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBRCmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBRCmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBRCmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBRCmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatBolsterValueBRCmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue6Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue6Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue6Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue6Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue6Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue6Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue5Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue5Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue5Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue5Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue5Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue5Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue4Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue4Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue4Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue4Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue4Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_03_PassSeatCushionValue4Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassPumpCmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassPumpCmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassPumpCmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassPumpCmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassPumpCmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassPumpCmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueLCmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueLCmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueLCmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueLCmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueLCmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueLCmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueMCmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueMCmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueMCmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueMCmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueMCmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueMCmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueRCmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueRCmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueRCmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueRCmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueRCmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatUpperValueRCmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue2Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue2Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue2Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue2Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue2Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue2Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue3Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue3Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue3Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue3Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue3Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue3Cmd User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue1Cmd
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue1Cmd User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue1Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue1Cmd
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue1Cmd User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_Zone_FL_MCM_04_PassSeatCushionValue1Cmd User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_2EF_BattVolt_LBMR User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer User Code start*/
#if defined(PISCES_MCM_D)
    Rte_Call_Event_Cfg_D_Event_0xF3A987_SetEventStatus(DEM_EVENT_STATUS_FAILED);
#elif defined(PISCES_MCM_P)
    Rte_Call_Event_Cfg_P_Event_0xF3A987_SetEventStatus(DEM_EVENT_STATUS_FAILED);
#endif
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3A9_VehOdometer User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Yr
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Yr User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Yr User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Yr
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Yr User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Yr User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Mth
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Mth User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Mth User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Mth
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Mth User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Mth User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Day
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Day User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Day User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Day
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Day User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Day User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Hr
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Hr User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Hr User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Hr
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Hr User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Hr User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Min
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Min User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Min User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Min
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Min User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Min User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Sec
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Sec User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Sec User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Sec
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Sec User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_Sec User Code end*/
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_MSec
(
    void
)
{
    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_MSec User Code start*/

    /*Rte_COMCbkRxTOut_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_MSec User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_MSec
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_MSec User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_3B2_MSec User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC_DFT User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC1_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC2_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC3_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC4_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC5_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC6_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC7_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC8_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC9_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC10_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC11_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC12_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC13_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC14_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC15_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC16_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC17_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC18_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC19_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC20_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC21_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC22_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC23_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC24_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC25_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC26_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC27_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC28_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC29_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC30_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC31_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC32_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC33_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC34_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC35_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC36_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC37_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC38_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC39_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC40_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC41_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC43_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC42_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC44_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC45_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC46_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC47_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_ZONE_PNC_PNC48_Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_CRC User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_MsgCntr User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload
(
    void
)
{
    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload User Code start*/

    /*Rte_COMCbk_Com_Cfg_P_Rx_BODY_LE1_CAN_VC_Data_5E0_VC_Data_5E0_Payload User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts5
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts5 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts5 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts5
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts5 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts5 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts6
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts6 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts6 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime5
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime5 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime5 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts6
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts6 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts6 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts7
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts7 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts7 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime6
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime6 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime6 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime7
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime7 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime7 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts8
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts8 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgSkillsSts8 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts7
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts7 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts7 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts8
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts8 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgLvlSts8 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime8
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime8 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1B7_PassKneadingMassgTime8 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgValveSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgValveSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgValveSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgHeatCSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgHeatCSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatmassgHeatCSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarValueSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarValueSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarValueSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatUpperValueSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatUpperValueSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatUpperValueSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValueSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValueSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValueSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBlosterValueSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBlosterValueSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBlosterValueSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassMassSwitchSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassMassSwitchSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassMassSwitchSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarTopPos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarTopPos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarTopPos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarMidPos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarMidPos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarMidPos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarBottomPos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarBottomPos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatLumbarBottomPos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBLPos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBLPos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBLPos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBRPos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBRPos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatBolsterValueBRPos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValue6Pos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValue6Pos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E2_PassSeatCushionValue6Pos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue5Pos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue5Pos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue5Pos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue4Pos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue4Pos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue4Pos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue2Pos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue2Pos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue2Pos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue1Pos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue1Pos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatCushionValue1Pos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueLPos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueLPos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueLPos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueMPos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueMPos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueMPos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueRPos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueRPos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassSeatUpperValueRPos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassPumpSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassPumpSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E3_PassPumpSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgSkillsSts9
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgSkillsSts9 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgSkillsSts9 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumControlSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumControlSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumControlSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumSwitchSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumSwitchSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumSwitchSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSystemFailr
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSystemFailr User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSystemFailr User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatMassFailr
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatMassFailr User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatMassFailr User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatCushionValue3Pos
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatCushionValue3Pos User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassSeatCushionValue3Pos User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarTopWorkSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarTopWorkSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarTopWorkSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarMidWorkSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarMidWorkSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarMidWorkSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarBottomWorkSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarBottomWorkSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassLumbarBottomWorkSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat1Sts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat1Sts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat1Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat2Sts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat2Sts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat2Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat3Sts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat3Sts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat3Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat4Sts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat4Sts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat4Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5Sts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5Sts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat6Sts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat6Sts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat6Sts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5ErrSts
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5ErrSts User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassHeat5ErrSts User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgLvlSts9
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgLvlSts9 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgLvlSts9 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgTime9
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgTime9 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1E4_PassKneadingMassgTime9 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgTime10
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgTime10 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgTime10 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgSkillsSts10
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgSkillsSts10 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgSkillsSts10 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgLvlSts10
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgLvlSts10 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassKneadingMassgLvlSts10 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC1
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC1 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC1 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC2
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC2 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC2 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC3
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC3 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC3 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC4
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC4 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC4 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC5
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC5 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC5 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC6
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC6 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1EB_PassMassageHeatNTC6 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC7
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC7 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC7 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC8
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC8 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC8 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC9
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC9 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC9 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC10
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC10 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC10 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC11
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC11 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC11 User Code end*/
}


FUNC(void, RTE_CODE) Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC12
(
    void
)
{
    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC12 User Code start*/

    /*Rte_COMCbkTAck_Com_Cfg_P_Tx_BODY_LE1_CAN_MCM_P_1ED_PassMassageHeatNTC12 User Code end*/
}

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"


