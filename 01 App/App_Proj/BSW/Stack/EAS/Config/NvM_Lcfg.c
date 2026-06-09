/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : NvM_Lcfg.c
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : NvM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : NvM module configuration File
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
/*PRQA S 5087,3614,3214,862,2213 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "EcuM_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in EcuM_MemMap.h.
{} is allowed to be in the same line in arrays of configuration files.
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

/*PRQA S 3211,3132,3212 EOF*/
/*
Particularity of configuration files.
Different types of transformations may be different from different configurations.
*/

/*PRQA S 380 EOF*/
/*
Number of macro definitions exceeds 4095 -program does not conform strictly to ISO:C99.
*/

/*PRQA S 674 EOF*/
/*
Initializer for pointer is of incompatible type.
*/

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "NvM.h"

#include "BSW_APP.h"
#include "Dem.h"
#include "Rte_NvM.h"

/*******************************************************************************
*   Global Vars
*******************************************************************************/
#define NVM_START_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "NvM_MemMap.h"
VAR(NvM_RamBlock_Type, NVM_VAR_NOINIT)  NvM_AdmBlock[23];
VAR(NvM_QueBuf_Type, NVM_VAR_NOINIT) NvM_QueBuf[10];

#define NVM_STOP_SEC_VAR_CLEARED_LOCAL_UNSPECIFIED
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_LOCAL_8
#include "NvM_MemMap.h"
VAR(uint8, NVM_VAR_NOINIT) NvM_CfgIDBuffer[2];


#define NVM_STOP_SEC_VAR_CLEARED_LOCAL_8
#include "NvM_MemMap.h"
/*******************************************************************************
*   Config parameters
*******************************************************************************/
#define NVM_START_SEC_CONFIG_DATA
#include "NvM_MemMap.h"
CONST(uint8, NVM_CONST) NvM_CompiledConfigId[2] = {(uint8)213, (uint8)95};
#define NVM_STOP_SEC_CONFIG_DATA
#include "NvM_MemMap.h"

#define NVM_START_SEC_VAR_CLEARED_GLOBAL_8
#include "NvM_MemMap.h"
#define NVM_STOP_SEC_VAR_CLEARED_GLOBAL_8
#include "NvM_MemMap.h"



#define NVM_START_SEC_CONFIG_DATA
#include "NvM_MemMap.h" 




CONST(NvM_BlockConfigType, NVM_CONST) NvM_Config[23] =
{
    /* Block0, index = 0 */
    {
        NVM_NULL, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)1, (uint16)0, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* Block_CfgID, index = 1 */
    {
        (uint8 *)NvM_CfgIDBuffer, (const uint8 *)NvM_CompiledConfigId, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)2, (uint16)1, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_0, index = 2 */
    {
        (uint8 *)&PrimaryDataEntry_0_0, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)2, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_1, index = 3 */
    {
        (uint8 *)&PrimaryDataEntry_0_1, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)3, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_2, index = 4 */
    {
        (uint8 *)&PrimaryDataEntry_0_2, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)4, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_3, index = 5 */
    {
        (uint8 *)&PrimaryDataEntry_0_3, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)5, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_4, index = 6 */
    {
        (uint8 *)&PrimaryDataEntry_0_4, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)6, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_5, index = 7 */
    {
        (uint8 *)&PrimaryDataEntry_0_5, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)7, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_6, index = 8 */
    {
        (uint8 *)&PrimaryDataEntry_0_6, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)8, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_7, index = 9 */
    {
        (uint8 *)&PrimaryDataEntry_0_7, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)9, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_8, index = 10 */
    {
        (uint8 *)&PrimaryDataEntry_0_8, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)10, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_9, index = 11 */
    {
        (uint8 *)&PrimaryDataEntry_0_9, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)11, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_10, index = 12 */
    {
        (uint8 *)&PrimaryDataEntry_0_10, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)12, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_11, index = 13 */
    {
        (uint8 *)&PrimaryDataEntry_0_11, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)13, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_12, index = 14 */
    {
        (uint8 *)&PrimaryDataEntry_0_12, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)14, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_13, index = 15 */
    {
        (uint8 *)&PrimaryDataEntry_0_13, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)15, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_14, index = 16 */
    {
        (uint8 *)&PrimaryDataEntry_0_14, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)16, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_15, index = 17 */
    {
        (uint8 *)&PrimaryDataEntry_0_15, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)17, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_16, index = 18 */
    {
        (uint8 *)&PrimaryDataEntry_0_16, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)18, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_17, index = 19 */
    {
        (uint8 *)&PrimaryDataEntry_0_17, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)19, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_18, index = 20 */
    {
        (uint8 *)&PrimaryDataEntry_0_18, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)20, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_PrimaryDataEntry_0_19, index = 21 */
    {
        (uint8 *)&PrimaryDataEntry_0_19, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)19, (uint16)21, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    },
    /* NVM_Dem_StorageMem, index = 22 */
    {
        (uint8 *)&Dem_StorageMem, NVM_NULL, /*Ram Rom*/
        NVM_BLOCK_NATIVE, /*Block Type*/
        (uint16)156, (uint16)22, (uint8)0, /*Length, BaseNum, DeviceId*/
        (uint8)1, (uint8)1, TRUE, TRUE, FALSE, /*NvNum, Pri, EnReadAll, EnWrAll, FirstInitAll*/
        FALSE, /*BswMEn*/
        FALSE, FALSE, /*setRam, autoValidated*/
    }
};

CONST(NvM_SingleCallBackFun, NVM_CONST) NvM_SingleCallBackFunPtr[23] =
{
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL
};

CONST(NvM_InitBlockCallBackFun, NVM_CONST) NvM_InitBlockCallBackFunPtr[23] =
{
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL,
    NVM_NULL
};
CONST(NvM_MultiCallBackFun, NVM_CONST) NvM_MultiCallBackFunPtr = NVM_NULL ;


#define NVM_STOP_SEC_CONFIG_DATA
#include "NvM_MemMap.h"

