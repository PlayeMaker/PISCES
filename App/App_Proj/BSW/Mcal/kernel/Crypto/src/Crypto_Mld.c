/**
 * @file    Crypto_Mld.h
 * @version
 *
 * @brief   AUTOSAR Crypto module interface
 * @details API implementation for CRYPTO driver
 *
 * @addtogroup CRYPTO_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4 MCAL
 *   Platform             : ARM
 *   Peripheral           : Csm
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V0.9.1
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Crypto_Cfg.h"
#include "Crypto_Mld.h"
#include "Crypto_Lld_Hcu.h"
#include "Crypto_Lld_Trng.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_MLD_VENDOR_ID                           (180)
#define CRYPTO_MLD_AR_RELEASE_MAJOR_VERSION              (4)
#define CRYPTO_MLD_AR_RELEASE_MINOR_VERSION              (4)
#define CRYPTO_MLD_AR_RELEASE_REVISION_VERSION           (0)
#define CRYPTO_MLD_SW_MAJOR_VERSION                      (0)
#define CRYPTO_MLD_SW_MINOR_VERSION                      (9)
#define CRYPTO_MLD_SW_PATCH_VERSION                      (1)

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check the source file and Crypto_Mld.h are of the same vendor */
#if (CRYPTO_MLD_VENDOR_ID != CRYPTO_MLD_VENDOR_ID)
#error "Crypto_Mld.c and Crypto_Mld.h have different vendor ids"
#endif

/* Check the source file and Crypto_Mld.h are of the same AUTOSAR version */
#if ((CRYPTO_MLD_AR_RELEASE_MAJOR_VERSION != CRYPTO_MLD_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_MLD_AR_RELEASE_MINOR_VERSION != CRYPTO_MLD_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_MLD_AR_RELEASE_REVISION_VERSION != CRYPTO_MLD_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Crypto_Mld.c and Crypto_Mld.h are different"
#endif

/* Check the source file and Crypto_Mld.h are of the same software version */
#if ((CRYPTO_MLD_SW_MAJOR_VERSION != CRYPTO_MLD_SW_MAJOR_VERSION) || \
     (CRYPTO_MLD_SW_MINOR_VERSION != CRYPTO_MLD_SW_MINOR_VERSION) || \
     (CRYPTO_MLD_SW_PATCH_VERSION != CRYPTO_MLD_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Crypto_Mld.c and Crypto_Mld.h are different"
#endif

/* Check if source file and Crypto_Lld_Hcu.h are of the same vendor */
#if (CRYPTO_MLD_VENDOR_ID != CRYPTO_LLD_HCU_VENDOR_ID)
#error "Crypto_Mld.c and Crypto_Lld_Hcu.h have different vendor ids"
#endif

/* Check if source file and Crypto_Lld_Hcu.h are of the same AUTOSAR version */
#if ((CRYPTO_MLD_AR_RELEASE_MAJOR_VERSION != CRYPTO_LLD_HCU_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_MLD_AR_RELEASE_MINOR_VERSION != CRYPTO_LLD_HCU_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_MLD_AR_RELEASE_REVISION_VERSION != CRYPTO_LLD_HCU_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Crypto_Mld.c and Crypto_Lld_Hcu.h are different"
#endif

/* Check if source file and Crypto_Lld_Hcu.h are of the same software version */
#if ((CRYPTO_MLD_SW_MAJOR_VERSION != CRYPTO_LLD_HCU_SW_MAJOR_VERSION) || \
     (CRYPTO_MLD_SW_MINOR_VERSION != CRYPTO_LLD_HCU_SW_MINOR_VERSION) || \
     (CRYPTO_MLD_SW_PATCH_VERSION != CRYPTO_LLD_HCU_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Crypto_Mld.c and Crypto_Lld_Hcu.h are different"
#endif

/* Check if source file and Crypto_Lld_Trng.h are of the same vendor */
#if (CRYPTO_MLD_VENDOR_ID != CRYPTO_LLD_TRNG_VENDOR_ID)
#error "Crypto_Mld.c and Crypto_Lld_Trng.h have different vendor ids"
#endif

/* Check if source file and Crypto_Lld_Trng.h are of the same AUTOSAR version */
#if ((CRYPTO_MLD_AR_RELEASE_MAJOR_VERSION != CRYPTO_LLD_TRNG_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_MLD_AR_RELEASE_MINOR_VERSION != CRYPTO_LLD_TRNG_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_MLD_AR_RELEASE_REVISION_VERSION != CRYPTO_LLD_TRNG_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Crypto_Mld.c and Crypto_Lld_Trng.h are different"
#endif

/* Check if source file and Crypto_Lld_Trng.h are of the same software version */
#if ((CRYPTO_MLD_SW_MAJOR_VERSION != CRYPTO_LLD_TRNG_SW_MAJOR_VERSION) || \
     (CRYPTO_MLD_SW_MINOR_VERSION != CRYPTO_LLD_TRNG_SW_MINOR_VERSION) || \
     (CRYPTO_MLD_SW_PATCH_VERSION != CRYPTO_LLD_TRNG_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Crypto_Mld.c and Crypto_Lld_Trng.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
/**
 * @page misra_violations MISRA-C:2012 violations list
 * PRQA S 0306 Rule-11.4:Cast between a pointer to object and an integral type.
 * PRQA S 3673 Rule-8.13: The object addressed by the pointer parameter '%1s' is not modified and so the pointer could be of type 'pointer to const'.
 * PRQA S 0488 Rule-18.4 Performing pointer arithmetic.
*/
#define HCU_ERRO_DATAOVERFLOW           (2U)
#define HCU_ERRO_NOP                    (4U)
#define HCU_ERRO_NODATA                 (5U)
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"
CRYPTO_VAR Crypto_RunningDataType  Crypto_RunningData;
#define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"
/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"

/**
 * @brief Initialize the Crypto module.
 *
 * @param[in] SwapCfg The swapping configuration
 * @return None
 */
CRYPTO_FUNC void Crypto_Mld_Init(Crypto_Lld_Hcu_SwappingType SwapCfg)
{
    Crypto_Lld_HcuInit(SwapCfg);/*Swap byte*/
    Crypto_Lld_Trng_Init(TRNG_INST, TRNG_ENTROPY_DELAY);
}

/**
 * @brief This function starts a new HCU job according to the specified operation type.
 *
 * @param[in] CallType The type of the operation to perform
 * @return uint8
 */
CRYPTO_FUNC uint8 Crypto_Mld_HcuStart(Crypto_OperationType CallType)
{
    uint8 Retvl = 0xFE;
    if (HCU_IDLE == Crypto_RunningData.HcuRunStatus)
    {
        /*Avoiding incorrect operations after function re-entry*/
        Crypto_RunningData.HcuRunStatus = HCU_BUSY;
        Crypto_Lld_HcuStartPrepare(CallType, Crypto_RunningData.HcuEngine, Crypto_RunningData.AlgorithmAESMode, \
                                   Crypto_RunningData.HcuModeSel, Crypto_RunningData.HcuTotalLength);
        Retvl = Crypto_Lld_HcuSetInputDataLength(MSG_START, CallType);
        if (0U == Retvl)
        {
            Crypto_RunningData.HcuRunStatus = HCU_STARTING;
        }
        else
        {
            /*Restore variable values*/
            Crypto_RunningData.HcuRunStatus = HCU_IDLE;
            Retvl = 0xFE;
        }
    }
    if (Crypto_RunningData.HcuRunStatus == HCU_STARTING)
    {
        Retvl = Crypto_Lld_HcuSetInputData(Crypto_RunningData.HcuProcessing, MSG_START);
        if (0U == Retvl)
        {
            Crypto_RunningData.HcuRunStatus = HCU_STARTED;
        }
    }
    return Retvl;
}

/**
 * @brief This function updates the status or data of an ongoing HCU job
 * according to the specified operation type.
 *
 * @param[in] CallType The type of the operation to perform
 * @return uint8
 */
CRYPTO_FUNC uint8 Crypto_Mld_HcuUpdate(Crypto_OperationType CallType)
{
    uint8 Retvl = 0xFE;
    Crypto_Lld_Hcu_RunStatusType TempStatus;
    if ((HCU_STARTED == Crypto_RunningData.HcuRunStatus) ||
            (HCU_UPDATEIDLE == Crypto_RunningData.HcuRunStatus))
    {
        /*Avoiding incorrect operations after function re-entry*/
        TempStatus = Crypto_RunningData.HcuRunStatus;
        Crypto_RunningData.HcuRunStatus = HCU_BUSY;
        /*Set input data*/
        Retvl = Crypto_Lld_HcuSetInputDataLength(MSG_MIDDLE, CallType);
        if (0U == Retvl)
        {
            Crypto_RunningData.HcuRunStatus = HCU_UPDATING;
        }
        else if ((HCU_ERRO_NOP == Retvl) || (HCU_ERRO_NODATA == Retvl))
        {
            /*mixtur and length less than 31k. Under finish mode to be sended*/
            /*no message to be sended for singlecall*/
            if (CRYPTO_OPT_SINGLE_MODE == CallType)
            {
                Crypto_RunningData.HcuRunStatus = HCU_UPDATEFINISH;
            }
            else
            {
                Crypto_RunningData.HcuRunStatus = HCU_UPDATEIDLE;
            }
            Retvl = 0;
        }
        else
        {
            /*Restore variable values*/
            Crypto_RunningData.HcuRunStatus = TempStatus;
        }
    }
    if (Crypto_RunningData.HcuRunStatus == HCU_UPDATING)
    {
        Retvl = Crypto_Lld_HcuSetInputData(Crypto_RunningData.HcuProcessing, MSG_MIDDLE);
        if ((0U == Retvl) && (CRYPTO_OPT_SINGLE_MODE == CallType) && (CRYPTO_PROCESSING_SYNC == Crypto_RunningData.HcuProcessing))
        {
            if ((Crypto_RunningData.HcuInputLength > Crypto_RunningData.HcuInputIndex) && \
                    ((Crypto_RunningData.HcuInputLength - Crypto_RunningData.HcuInputIndex) > HCU_MAXSIZE_WRITEONCE))
            {
                Crypto_RunningData.HcuRunStatus = HCU_UPDATEIDLE;
            }
            else
            {
                Crypto_RunningData.HcuRunStatus = HCU_UPDATEFINISH;
            }
        }
        else if ((0U == Retvl) && (CRYPTO_OPT_MULTI_MODE == CallType))
        {
            Crypto_RunningData.HcuRunStatus = HCU_UPDATEIDLE;
        }
        else if (0U == Retvl)
        {
            Crypto_RunningData.HcuRunStatus = HCU_UPDATEIDLE;
        }
        else
        {
            /*do nothing*/
        }
    }
    return Retvl;
}

/**
 * @brief This function completes the current HCU job according to the specified operation type.
 *
 * @param[in] CallType The type of the operation to perform
 * @return uint8
 */
CRYPTO_FUNC uint8 Crypto_Mld_HcuFinish(Crypto_OperationType CallType)
{
    uint8 RetVal = 0x01;
    Crypto_Lld_Hcu_RunStatusType TempStatus;
    if (HCU_UPDATEFINISH == Crypto_RunningData.HcuRunStatus)
    {
        /*Avoiding incorrect operations after function re-entry*/
        TempStatus = Crypto_RunningData.HcuRunStatus;
        Crypto_RunningData.HcuRunStatus = HCU_BUSY;
        /*Set input data*/
        RetVal = Crypto_Lld_HcuSetInputDataLength(MSG_END, CallType);
        if (0U == RetVal)
        {
#if defined(HCU_SUPPORT_TOTAL_MSG_LENGTH_SET)
            if ((CRYPTO_OPT_MULTI_MODE == CallType) || (CRYPTO_OPT_STREAM_MODE == CallType))
            {
                /*if not Singnal call ,write TotalLength in finished mode*/
                Crypto_Lld_HcuSetMsgTotalLength(Crypto_RunningData.HcuTotalLength);
            }
#endif /* HCU_SUPPORT_TOTAL_MSG_LENGTH_SET */
            Crypto_RunningData.HcuRunStatus = HCU_FINISHING;
        }
        else if (HCU_ERRO_NODATA == RetVal)
        {
            /*no message to be sended*/
            Crypto_RunningData.HcuRunStatus = HCU_FINISHED;
            RetVal = 0;
        }
        else
        {
            /*Restore variable values*/
            Crypto_RunningData.HcuRunStatus = TempStatus;
        }
    }
    if (Crypto_RunningData.HcuRunStatus == HCU_FINISHING)
    {
        RetVal = Crypto_Lld_HcuSetInputData(Crypto_RunningData.HcuProcessing, MSG_END);
        if (0U == RetVal)
        {
            Crypto_RunningData.HcuRunStatus = HCU_FINISHED;
        }
    }
    return RetVal;
}

/**
 * @brief   This function processes a synchronous single job for the HCU.
 *
 * @param[in] CallType The type of the job (single, multi, or stream).
 * @return  uint8
 * @retval  0x01      The function executed successfully.
 */
CRYPTO_FUNC uint8 Crypto_Mld_HcuSyncSingleCall(Crypto_OperationType CallType)
{
    uint8 RetVal = 0x01;
    Crypto_Mld_HcuStart(CallType);
    do
    {
        Crypto_Mld_HcuUpdate(CallType);
    } while (HCU_UPDATEFINISH != Crypto_RunningData.HcuRunStatus);
    Crypto_Mld_HcuUpdate(CallType);
    RetVal = Crypto_Mld_HcuFinish(CallType);
    return RetVal;
}

/**
 * @brief   This function processes an asynchronous single job for the HCU.
 *
 * @param[in] CallType The type of the job (single, multi, or stream).
 * @return  uint8
 * @retval  0x01      The function executed successfully.
 */
CRYPTO_FUNC uint8 Crypto_Mld_HcuAsyncSingleCall(Crypto_OperationType CallType)
{
    uint8 RetVal = 0x01;
    (void)Crypto_Mld_HcuStart(CallType);
    (void)Crypto_Mld_HcuUpdate(CallType);
    RetVal =  Crypto_Mld_HcuFinish(CallType);
    return RetVal;
}

/**
 * @brief   This function checks the status of the TRNG.
 *
 * @return  Std_ReturnType
 * @retval  E_OK          The TRNG is not busy.
 * @retval  E_NOT_OK      The TRNG is busy.
 */
CRYPTO_FUNC static Std_ReturnType Crypto_Mld_CheckTrngStatus(void)
{
    Std_ReturnType ReturnValue = E_OK;
    if (CRYPTO_TRNG_BUSY == Crypto_Lld_Trng_GetStatus(TRNG_INST))
    {
        ReturnValue = E_NOT_OK;
    }
    return ReturnValue;
}
/**
 * @brief   This function processes a random job.
 *
 * @param[in]   Length     Length of the random data to generate
 * @param[out]  OutputPtr  Pointer to the buffer where the generated random data will be stored
 * @return  Std_ReturnType
 * @retval  E_OK          The random generation was successful.
 * @retval  E_NOT_OK      The random generation failed.
 */
CRYPTO_FUNC Std_ReturnType Crypto_Mld_ProcessJobRandom(uint32 Length, uint8 *OutputPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    while (E_NOT_OK == Crypto_Mld_CheckTrngStatus())
    {
        /*Nothing to do*/
    }
    if (CRYPTO_TRNG_SUCCESS == Crypto_Lld_Trng_GetStatus(TRNG_INST))
    {
        Crypto_Lld_Trng_GetEnt(TRNG_INST, OutputPtr, Length);
        RetVal = (Std_ReturnType)E_OK;
    }
    return RetVal;
}


#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"
#ifdef __cplusplus
}
#endif

