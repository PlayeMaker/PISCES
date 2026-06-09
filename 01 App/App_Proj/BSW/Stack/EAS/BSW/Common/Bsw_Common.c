/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Bsw_Common.c
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : BSW COMMON File
*   Author          : Hirain
********************************************************************************
*   Description     : for some functions may be used by all modules
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*
*   Version     Date          Initials      CR#          Descriptions
*   ---------   ----------    ------------  ----------   ---------------
*   04.00.00    24/08/2023    Ning.Chen     N/A          Original
********************************************************************************
* END_FILE_HDR*/

/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "Base_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in Base_MemMap.h
*/

/*PRQA S 3432 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no
need to revise.
*/

/*PRQA S 3211 EOF*/
/*
Bsw_CanFDDlcMap is used by CanTp.
*/

/*PRQA S 1502,1503,1532 EOF*/
/*
Function declared externally are called by the user.
*/

/*PRQA S 2824 EOF*/
/*
The null pointer is judged before the function is called.
*/
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "Bsw_Common.h"

#define BSW_START_SEC_CONST_8
#include "Base_MemMap.h"
/* CANFD DLC Map */
CONST(uint8, BSW_CONST) Bsw_CanFDDlcMap[BSW_CANFD_LENGTH_TABLE_SIZE] =
{
    (uint8)0,
    (uint8)1,
    (uint8)2,
    (uint8)3,
    (uint8)4,
    (uint8)5,
    (uint8)6,
    (uint8)7,
    (uint8)8,
    (uint8)12,
    (uint8)16,
    (uint8)20,
    (uint8)24,
    (uint8)32,
    (uint8)48,
    (uint8)64
};
#define BSW_STOP_SEC_CONST_8
#include "Base_MemMap.h"


#define BSW_START_SEC_CODE
#include "Base_MemMap.h"

/*******************************************************************************
*   Functions
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Bsw_MemCpy
*
* Description:   This service copy data from src to dest
*
* Inputs:        dest, src, size
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSW_CODE) Bsw_MemCpy
(
    CONSTP2VAR(uint8, AUTOMATIC, BSW_APPL_DATA) dest,
    CONSTP2CONST(uint8, AUTOMATIC, BSW_APPL_DATA) src,
    const uint32 size
)
{
    uint32 i;

    for(i = (uint32)0; i < size; i++)
    {
        dest[i] = src[i];
    }
}


/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Bsw_MemSet
*
* Description:   This service set fix data to  dest
*
* Inputs:        dest, src, size
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, BSW_CODE) Bsw_MemSet
(
    CONSTP2VAR(uint8, AUTOMATIC, BSW_APPL_DATA) dest,
    const uint8 src,
    const uint32 size
)
{
    uint32 i;

    for(i = (uint32)0; i < size; i++)
    {
        dest[i] = src;
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: Bsw_MemCmp
*
* Description:   This service compare CmpA with CmpB
*
* Inputs:        CmpA, CmpB, size
*
* Outputs:       None
*
* Limitations:   None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, BSW_CODE) Bsw_MemCmp
(
    CONSTP2CONST(uint8, AUTOMATIC, BSW_APPL_DATA) CmpA,
    CONSTP2CONST(uint8, AUTOMATIC, BSW_APPL_DATA) CmpB,
    const uint32 size
)
{
    uint32 i;
    Std_ReturnType ret = E_OK;

    for(i = (uint32)0; i < size; i++)
    {
        /*PRQA S 2100 ++*/
        /*Integer promotion related.*/
        if(CmpA[i] != CmpB[i])
        {
            ret = E_NOT_OK;
            break;
        }
        else
        {
            /*Continue compare*/
        }
        /*PRQA S 2100 --*/
    }
    return ret;
}

#define BSW_STOP_SEC_CODE
#include "Base_MemMap.h"



