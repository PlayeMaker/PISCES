/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EcuM_Callout_Stubs.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : EcuM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : EcuM module configuration File
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
/*PRQA S 5087,3614,3214,862 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "EcuM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in EcuM_MemMap.h
*/

/*PRQA S 857 EOF*/
/*
Macro definitions exceed 1024.The number of macros is unlimited
*/

/*PRQA S 4640 EOF*/
/*
This waring is a false position. The 'errno.h' header file will not be used by the
EcuM module.
*/

/*PRQA S 3211,4332,1484,1278,3227 EOF*/
/*
Particularity of configuration files.
Read-only function input parameters may not be defined as const,it does not affect the function.
AUTOSAR API shall define standard input parameters according to specification requirements
*/

/*PRQA S 2100,2101,2000 EOF*/
/*
Integer promotion related
*/

/*PRQA S 380 EOF*/
/*
Number of macro definitions exceeds 4095 -program does not conform strictly to ISO:C99.
*/

/*PRQA S 3206 EOF*/
/*
The parameter 'XXX' is not used in this function.
*/



/*******************************************************************************
*   Includes
*******************************************************************************/
#include "EcuM.h"
#include "Det.h"
/*Input File User Code start*/
#include "Dem.h"
#include "Mcal.h"
#include "OsIf.h"

#include "BSW_APP.h"
/*Input File User Code end*/
#define ECUM_START_SEC_CODE
#include "EcuM_MemMap.h"


/*******************************************************************************
*  PUBLIC Functions define
*******************************************************************************/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_ErrorHook
*
* Description:
*
* Inputs:        reason - error value
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_02904
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_ErrorHook
(
    VAR(Std_ReturnType, AUTOMATIC) reason
)
{
    (void)reason;
    while (1)   /*SWS_EcuM_02758*/
    {

    /*EcuM_ErrorHook User Code start*/

    /*EcuM_ErrorHook User Code end*/
    }
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_AL_SetProgrammableInterrupts
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_04085
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_SetProgrammableInterrupts
(
    void
)
{

    /*EcuM_AL_SetProgrammableInterrupts User Code start*/

    /*EcuM_AL_SetProgrammableInterrupts User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_AL_DriverInitZero
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_02095
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_DriverInitZero
(
    void
)
{
    /*EcuM_AL_DriverInitZero User Code start*/
    Det_Init(NULL_PTR);
    Dem_PreInit();
    /*EcuM_AL_DriverInitZero User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_DeterminePbConfiguration
*
* Description:
*
* Inputs:        None
*
* Outputs:       The Post-Build Configurations of the EcuM module.
*
* Limitations:   SWS_EcuM_02096
********************************************************************************
END_FUNCTION_HDR*/
FUNC(const EcuM_ConfigType *, ECUM_CALLOUT_CODE) EcuM_DeterminePbConfiguration
(
    void
)
{
    /*EcuM_DeterminePbConfiguration User Code start*/

    /*EcuM_DeterminePbConfiguration User Code end*/
    return &(EcuM_PostBuildConfig[CURRENT_ECU]);
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_AL_DriverInitOne
*
* Description:
*
* Inputs:        ConfigPtr - The Post-Build Configurations of the EcuM module.
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_02097
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_DriverInitOne
(
    void
)
{
    Can_Init(&Can_Config[CURRENT_ECU]);

    /*Fee Init*/
    Fls_Init(&Fls_Config);
    Fee_Init(NULL_PTR);
    do
    {
        Fls_MainFunction();
        Fee_MainFunction();
    } while (MEMIF_IDLE != Fee_GetStatus());

    OsIf_ResumeAllInterrupts();
    /*EcuM_AL_DriverInitOne User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_AL_DriverInitBswM_<x>
*
* Description:
*
* Inputs:        ConfigPtr - The Post-Build Configurations of the EcuM module.
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_02097
********************************************************************************
END_FUNCTION_HDR*/

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_OnGoOffOne
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_02916
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_OnGoOffOne
(
    void
)
{

    /*EcuM_OnGoOffOne User Code start*/

    /*EcuM_OnGoOffOne User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_OnGoOffTwo
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_02917
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_OnGoOffTwo
(
    void
)
{

    /*EcuM_OnGoOffTwo User Code start*/

    /*EcuM_OnGoOffTwo User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_AL_SwitchOff
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_02920
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_SwitchOff
(
    void
)
{
    /*If the ECU does NOT support OFF, issue a reset instead.*/
    /*EcuM_AL_SwitchOff User Code start*/

    /*EcuM_AL_SwitchOff User Code end*/
}

/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: EcuM_AL_Reset
*
* Description:
*
* Inputs:        None
*
* Outputs:       None
*
* Limitations:   SWS_EcuM_04065
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_Reset
(
    VAR(EcuM_ResetType, AUTOMATIC) reset
)
{
    EcuM_BootTargetType target;

    (void)EcuM_GetBootTarget(&target);

    switch (target)
    {
    case ECUM_BOOT_TARGET_APP :
        /*EcuM_AL_Reset case ECUM_BOOT_TARGET_APP User Code start*/

        /*EcuM_AL_Reset case ECUM_BOOT_TARGET_APP User Code end*/
        break;
    case ECUM_BOOT_TARGET_OEM_BOOTLOADER :
        /*SWS_EcuM_02247*/
        /*EcuM_AL_Reset case ECUM_BOOT_TARGET_OEM_BOOTLOADER User Code start*/

        /*EcuM_AL_Reset case ECUM_BOOT_TARGET_OEM_BOOTLOADER User Code end*/
        break;
    case ECUM_BOOT_TARGET_SYS_BOOTLOADER :
        /*EcuM_AL_Reset case ECUM_BOOT_TARGET_SYS_BOOTLOADER User Code start*/

        /*EcuM_AL_Reset case ECUM_BOOT_TARGET_SYS_BOOTLOADER User Code end*/
        break;
    default:
        /*EcuM_AL_Reset default User Code start*/

        /*EcuM_AL_Reset default User Code end*/
        break;
    }

    /*Reset now*/
}
#define ECUM_STOP_SEC_CODE
#include "EcuM_MemMap.h"



