/**
 * @file    Crypto_Lld.c
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
/**
 * @page misra_violations MISRA-C:2012 violations list
 *
 * PRQA S 2985 Rule-2.2: This operation is redundant. The value of the result is always that of the left-hand operand.
 * PRQA S 2469 Rule-14.2 Loop control variable in this 'for' statement, %1s, is modified in the body of the loop.
*/
/*
*  MR12 Rule-2.2 VIOLATION: This file is used to configure registers,there will be some bits-operations
*  like & or | or >> according to bit-wide defined by registers,
*  which are considered redundant operations.it is safe.
*/

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Crypto_Lld_Reg.h"
#include "Crypto_Lld_KeyManage.h"
#include "Crypto_Cfg.h"
#include "Crypto_Lld_Hcu.h"
#include "SchM_Crypto.h"
#if (CRYPTO_METHOD_DMA == CRYPTO_ASYNJOB_METHOD_SUPPORT)
#include "CddDma.h"
#endif
#include "OsIf.h"
/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_LLD_HCU_VENDOR_ID_C                  (180)
#define CRYPTO_LLD_HCU_AR_RELEASE_MAJOR_VERSION_C              (4)
#define CRYPTO_LLD_HCU_AR_RELEASE_MINOR_VERSION_C              (4)
#define CRYPTO_LLD_HCU_AR_RELEASE_REVISION_VERSION_C           (0)
#define CRYPTO_LLD_HCU_SW_MAJOR_VERSION_C                      (0)
#define CRYPTO_LLD_HCU_SW_MINOR_VERSION_C                      (9)
#define CRYPTO_LLD_HCU_SW_PATCH_VERSION_C                      (1)
/*==================================================================================================
                                            FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CRYPTO_LLD_HCU header file are of the same vendor */
#if (CRYPTO_LLD_HCU_VENDOR_ID_C != CRYPTO_LLD_HCU_VENDOR_ID)
#error "Crypto_Lld_Hcu.c and Crypto_Lld_Hcu.h have different vendor ids"
#endif

/* Check if source file and CRYPTO_LLD_HCU header file are of the same Autosar version */
#if (( CRYPTO_LLD_HCU_AR_RELEASE_MAJOR_VERSION_C != CRYPTO_LLD_HCU_AR_RELEASE_MAJOR_VERSION) || \
      ( CRYPTO_LLD_HCU_AR_RELEASE_MINOR_VERSION_C != CRYPTO_LLD_HCU_AR_RELEASE_MINOR_VERSION) || \
      ( CRYPTO_LLD_HCU_AR_RELEASE_REVISION_VERSION_C != CRYPTO_LLD_HCU_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Crypto_Lld_Hcu.c and Crypto_Lld_Hcu.h are different"
#endif

/* Check if source file and CRYPTO_LLD_HCU header file are of the same Software version */
#if (( CRYPTO_LLD_HCU_SW_MAJOR_VERSION_C != CRYPTO_LLD_HCU_SW_MAJOR_VERSION) || \
      ( CRYPTO_LLD_HCU_SW_MINOR_VERSION_C != CRYPTO_LLD_HCU_SW_MINOR_VERSION) || \
      ( CRYPTO_LLD_HCU_SW_PATCH_VERSION_C != CRYPTO_LLD_HCU_SW_PATCH_VERSION))
#error "Software Version Numbers of Crypto_Lld_Hcu.c and Crypto_Lld_Hcu.h are different"
#endif

/*Check if source file and CRYPTO_LLD_REG header file are of the same vendor */
#if (CRYPTO_LLD_HCU_VENDOR_ID_C != CRYPTO_LLD_REG_VENDOR_ID)
#error "Crypto_Lld_Hcu.c and Crypto_Lld_Reg.h have different vendor ids"
#endif

/*Check if source file and CRYPTO_LLD_REG header file are of the same AUTOSAR version*/
#if ((CRYPTO_LLD_HCU_AR_RELEASE_MAJOR_VERSION_C != CRYPTO_LLD_REG_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_LLD_HCU_AR_RELEASE_MINOR_VERSION_C != CRYPTO_LLD_REG_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_LLD_HCU_AR_RELEASE_REVISION_VERSION_C != CRYPTO_LLD_REG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Crypto_Lld_Hcu.c and Crypto_Lld_Reg.h are different"
#endif

/*Check if source file and CRYPTO_LLD_REG header file are of the same software version*/
#if ((CRYPTO_LLD_HCU_SW_MAJOR_VERSION_C != CRYPTO_LLD_REG_SW_MAJOR_VERSION) || \
     (CRYPTO_LLD_HCU_SW_MINOR_VERSION_C != CRYPTO_LLD_REG_SW_MINOR_VERSION) || \
     (CRYPTO_LLD_HCU_SW_PATCH_VERSION_C != CRYPTO_LLD_REG_SW_PATCH_VERSION))
#error "Software Version Numbers of Crypto_Lld_Hcu.c and Crypto_Lld_Reg.h are different"
#endif


/*Check if source file and Crypto_Lld_KeyManage.h are of the same vendor */
#if (CRYPTO_LLD_HCU_VENDOR_ID_C != CRYPTO_LLD_KEYMANAGE_VENDOR_ID)
#error "Crypto_Lld_Hcu.c and Crypto_Lld_KeyManage.h have different vendor ids"
#endif

/*Check if source file and Crypto_Lld_KeyManage.h are of the same AUTOSAR version*/
#if ((CRYPTO_LLD_HCU_AR_RELEASE_MAJOR_VERSION_C != CRYPTO_LLD_KEYMANAGE_AR_RELEASE_MAJOR_VERSION) || \
     (CRYPTO_LLD_HCU_AR_RELEASE_MINOR_VERSION_C != CRYPTO_LLD_KEYMANAGE_AR_RELEASE_MINOR_VERSION) || \
     (CRYPTO_LLD_HCU_AR_RELEASE_REVISION_VERSION_C != CRYPTO_LLD_KEYMANAGE_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Crypto_Lld_Hcu.c and Crypto_Lld_KeyManage.h are different"
#endif

/*Check if source file and Crypto_Lld_KeyManage.h are of the same software version*/
#if ((CRYPTO_LLD_HCU_SW_MAJOR_VERSION_C != CRYPTO_LLD_KEYMANAGE_SW_MAJOR_VERSION) || \
     (CRYPTO_LLD_HCU_SW_MINOR_VERSION_C != CRYPTO_LLD_KEYMANAGE_SW_MINOR_VERSION) || \
     (CRYPTO_LLD_HCU_SW_PATCH_VERSION_C != CRYPTO_LLD_KEYMANAGE_SW_PATCH_VERSION))
#error "Software Version Numbers of Crypto_Lld_Hcu.c and Crypto_Lld_KeyManage.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#define LENGTH_OF_MAC               (4U)
#define LENGTHINBYTE_OF_CVIV        (16U)
#define LENGTHINBITS_OF_KEY128      (128U)
#define LENGTHINBITS_OF_KEY192      (192U)
#define NUMINBYTE_OF_U32            (4U)
#define LENGTH_OF_U8                (8U)
#define LENGTH_OF_U16               (16U)
#define LENGTH_OF_U24               (24U)
#define LSBYTE_OF_U32               (0x000000FFU)
#define HCU_AES_MAC_LENGTH          (16U)
#define HCU_SHA_CONTEXT_LENGTH      (32U)
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
extern const Crypto_ConfigType Crypto_PreCompileConfig;

#if (CRYPTO_METHOD_DMA == CRYPTO_ASYNJOB_METHOD_SUPPORT)
extern const CddDma_TransferConfigType *DmaChannelTransferConfigArray[CDDDMA_CHANNEL_CONFIG_COUNT];
#endif

extern Crypto_RunningDataType  Crypto_RunningData;

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

#define CRYPTO_START_SEC_VAR_INIT_8
#include "Crypto_MemMap.h"
#if (CRYPTO_METHOD_DMA == CRYPTO_ASYNJOB_METHOD_SUPPORT)
CRYPTO_VAR static Crypto_Lld_Hcu_JobStatusType Crypto_Lld_StartDmaFlag = HCU_JOB_IDLE;
#elif (CRYPTO_METHOD_INTERRUPT == CRYPTO_ASYNJOB_METHOD_SUPPORT)
CRYPTO_VAR static Crypto_Lld_Hcu_JobStatusType Crypto_Lld_StartIntFlag = HCU_JOB_IDLE;
#else
CRYPTO_VAR static Crypto_Lld_Hcu_JobStatusType Crypto_Lld_StartPollingFlag = HCU_JOB_IDLE;
#endif

#define CRYPTO_STOP_SEC_VAR_INIT_8
#include "Crypto_MemMap.h"

#if (CRYPTO_METHOD_DMA == CRYPTO_ASYNJOB_METHOD_SUPPORT)
#define CRYPTO_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"
CRYPTO_VAR static CddDma_TransferConfigType Crypto_Lld_HcuInputDmaTcd;
CRYPTO_VAR static CddDma_TransferConfigType Crypto_Lld_HcuOutputDmaTcd;
#define CRYPTO_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crypto_MemMap.h"
#endif
/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
/**
 * @brief This function gets the HCU status flag.
 *
 * @param[in] StatusFlag The status flag, of type Crypto_Lld_Hcu_IntcFlagType
 * @return boolean
 * @retval TRUE  The status flag is asserted.
 * @retval FALSE The status flag is not asserted.
 */
CRYPTO_FUNC LOCAL_INLINE boolean Crypto_Lld_HcuGetStatusFlag(Crypto_Lld_Hcu_IntcFlagType StatusFlag)
{
    return ((boolean)(((HCU->SR) >> (uint8) StatusFlag) & 0x1U));
}

/**
 * @brief This function clears the HCU status flag.
 *
 * @param[in] StatusFlag The status flag, of type Crypto_Lld_Hcu_IntcFlagType
 * @return None
 */
CRYPTO_FUNC LOCAL_INLINE void Crypto_Lld_HcuClearStatusFlag(Crypto_Lld_Hcu_IntcFlagType StatusFlag)
{
    HCU->SR = (uint32) 1 << (uint8) StatusFlag;
}

#if(CRYPTO_METHOD_POLLING != CRYPTO_ASYNJOB_METHOD_SUPPORT)
/**
 * @brief This function gets the HCU interrupt enable.
 *
 * @param[in] statusFlag The status flag, of type Crypto_Lld_Hcu_IntcFlagType
 * @return boolean
 * @retval TRUE  The interrupt is enabled.
 * @retval FALSE The interrupt is disabled.
 */
CRYPTO_FUNC LOCAL_INLINE boolean Crypto_Lld_HcuGetIntMode(Crypto_Lld_Hcu_IntcFlagType StatusFlag)
{
    return (boolean)(((HCU->INTE) >> (uint8) StatusFlag) & 1U);
}

/**
 * @brief This function sets the HCU interrupt enable.
 *
 * @param[in] statusFlag The status flag, of type Crypto_Lld_Hcu_IntcFlagType.
 * @param[in] Enable Enables/Disables the interrupt.
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuSetIntMode(Crypto_Lld_Hcu_IntcFlagType StatusFlag, boolean Enable)
{
    if (TRUE == Enable)
    {
        HCU->INTE |= (uint32) 1U << (uint8) StatusFlag;
    }
    else
    {
        HCU->INTE &= ~((uint32) 1U << (uint8) StatusFlag);
    }
}
/**
 * @brief This function enables or disables HCU default interrupt.
 *
 * @param[in] Enable Enables/Disables HCU default interrupt.
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuSetDefaultInt(boolean Enable)
{
    SchM_Enter_Crypto_CRYPTO_EXCLUSIVE_AREA_05();
    if (TRUE == Enable)
    {
        HCU->INTE |= HCU_INTE_ODIE_MASK | HCU_INTE_INMSGWIE_MASK | HCU_INTE_OUTMSGRIE_MASK;
    }
    else
    {
#if defined (HCU_HASH_SUPPORT)
        HCU->INTE &= ~(HCU_INTE_ODIE_MASK | HCU_INTE_INMSGWIE_MASK | HCU_INTE_OUTMSGRIE_MASK | \
                       HCU_INTE_AESMACRIE_MASK | HCU_INTE_AESIVRIE_MASK | HCU_INTE_SHACTXRIE_MASK | HCU_INTE_AESMACWIE_MASK);
#else
        HCU->INTE &= ~(HCU_INTE_ODIE_MASK | HCU_INTE_INMSGWIE_MASK | HCU_INTE_OUTMSGRIE_MASK | \
                       HCU_INTE_AESMACRIE_MASK | HCU_INTE_AESIVRIE_MASK | HCU_INTE_AESMACWIE_MASK);
#endif
    }
    SchM_Exit_Crypto_CRYPTO_EXCLUSIVE_AREA_05();
}
#endif

/**
 * @brief This function sets the engine algorithm for the HCU.
 *
 * @param[in] Engine The engine type to be set.
 * @param[in] Algorithm The AES mode to be set.
 * @param[in] Encrypt The engine mode (encrypt/decrypt) to be set.
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuSetEngineAlgorithm(Crypto_Lld_Hcu_EngineType Engine,
        Crypto_Lld_Hcu_AesModeType Algorithm,
        Crypto_Lld_Hcu_EngineModeType Encrypt)
{
    SchM_Enter_Crypto_CRYPTO_EXCLUSIVE_AREA_08();
    /* Reset register fields */
    HCU->CR &= ~(HCU_CR_ENGSEL_MASK | HCU_CR_ALGSEL_MASK | HCU_CR_ENC_MASK);
    /* Set register fields */
    HCU->CR |= HCU_CR_ENGSEL(Engine) | HCU_CR_ALGSEL(Algorithm) | HCU_CR_ENC(Encrypt);
    /* Default enable store context data */
    HCU->CR |= HCU_CR_CS_MASK;
    SchM_Exit_Crypto_CRYPTO_EXCLUSIVE_AREA_08();
}

/**
 * @brief This function sets the user key for the HCU.
 *
 * @param[in] KeyArray Pointer to the key array.
 * @param[in] KeyLength Length of the key in bytes.
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuSetUserKey(uint32 const *KeyArray, uint32 KeyLength)
{
    uint8 KeyIndex = 0;
    KeyIndex = (uint8)(KeyLength / NUMINBYTE_OF_U32);
    for (uint8 Tempi = 0; Tempi < KeyIndex; ++Tempi)
    {
        HCU->KEY[Tempi] = KeyArray[Tempi];
    }
}

#if defined(HCU_SUPPORT_KEY_SIZE_SET)
/**
 * @brief This function sets the key size for the HCU.
 *
 * @param[in] LengthOfBits The length of the key in bits.
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuSetKeySize(uint32 LengthOfBits)
{
    Crypto_Lld_Hcu_KeySizeType TempSize;
    if (LENGTHINBITS_OF_KEY128 == LengthOfBits)
    {
        TempSize = KEY_SIZE_128_BITS;
    }
    else if (LENGTHINBITS_OF_KEY192 == LengthOfBits)
    {
        TempSize = KEY_SIZE_192_BITS;
    }
    else
    {
        TempSize = KEY_SIZE_256_BITS;
    }
    SchM_Enter_Crypto_CRYPTO_EXCLUSIVE_AREA_09();
    HCU->CR &= ~HCU_CR_KEYLEN_MASK;
    HCU->CR |= HCU_CR_KEYLEN(TempSize);/*PRQA S 2985 */
    SchM_Exit_Crypto_CRYPTO_EXCLUSIVE_AREA_09();
}
#endif

/**
 * @brief This function sets the message length for the HCU.
 *
 * @param[in] MsgLen The message length to be set.
 * @return None
 */
CRYPTO_FUNC LOCAL_INLINE void Crypto_Lld_HcuSetMsgLength(uint32 MsgLen)
{
    HCU->MSGCUR = HCU_MSGCUR_MSGLEN(MsgLen);
}

/**
 * @brief This function sets the MAC length for the HCU.
 *
 * @param[in] Length The MAC length to be set.
 * @return None
 */
CRYPTO_FUNC void Crypto_Lld_HcuSetMacLength(uint32 Length)
{
    SchM_Enter_Crypto_CRYPTO_EXCLUSIVE_AREA_10();
#if defined (CPU_YTM32B1MD2)
    HCU->CR &= ~HCU_CR_MACLEN_MASK;
    HCU->CR |= HCU_CR_MACLEN((Length * LENGTH_OF_U8));
#else
    HCU->CR &= ~HCU_CR_MACLEN_MASK;
    HCU->CR |= HCU_CR_MACLEN(Length);
#endif
    SchM_Exit_Crypto_CRYPTO_EXCLUSIVE_AREA_10();
}

/**
 * @brief This function sets the message type for the HCU.
 *
 * @param[in] Type The message type to be set.
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuSetMsgType(Crypto_Lld_Hcu_MsgType Type)
{
    SchM_Enter_Crypto_CRYPTO_EXCLUSIVE_AREA_11();
    HCU->CR &= ~(HCU_CR_MSGE_MASK | HCU_CR_MSGB_MASK);
    HCU->CR |= ((uint32)Type) << HCU_CR_MSGE_SHIFT;
    SchM_Exit_Crypto_CRYPTO_EXCLUSIVE_AREA_11();
}

/**
 * @brief This function starts the HCU engine.
 *
 * @param None
 * @return None
 */

CRYPTO_FUNC LOCAL_INLINE void Crypto_Lld_HcuStartEngine(void)
{
    HCU->GO = HCU_GO_GO_MASK;
}

/**
 * @brief This function sets the IV for the HCU.
 *
 * @param[in] Iv Pointer to the IV data.
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuSetIv(const uint8 *Iv)
{
    uint8 Tempi = 0;
    uint8 Tempk = 0;
    uint32 Temp32data = 0;
    uint32 Temp8data = 0;
    while (Tempi < LENGTHINBYTE_OF_CVIV)
    {
        for (uint8 Tempj = 0; Tempj < NUMINBYTE_OF_U32; ++Tempj)
        {
            Temp8data = (uint32)(((uint32)(Iv[Tempi])) << (Tempj * LENGTH_OF_U8));
            Temp32data |= Temp8data;
            ++Tempi;
        }
        HCU->CONTEXT_4_7[Tempk] = Temp32data;
        ++Tempk;
        Temp32data = 0x00000000;
    }
}

/**
 * @brief This function loads data to the HCU input FIFO.
 *
 * @param[in] Data Pointer to the data to be loaded.
 * @param[in] Length Length of the data to be loaded.
 * @return None
 */

/* PRQA S 2469,4391 ++*/
CRYPTO_FUNC static void Crypto_Lld_HcuWriteInputFifo(const uint8 *Data, uint32 Length)
{
    uint8 Tempi = 0;
    uint8 Tempj = 0;
    uint32 Temp32data = 0U;
    uint32 Temp8data = 0U;
    uint32 TempLength = 0U;
    TempLength = Length - Length % NUMINBYTE_OF_U32;
    /*Process data in 4-byte units*/
    while (Tempi < TempLength)
    {
        for (Tempj = 0; Tempj < NUMINBYTE_OF_U32; ++Tempj)
        {
            /*MR12 Rule-14.2 VIOLATION: Converte Data[Tempi],result not large than 32-bits.it is safe.*/
            Temp8data = (uint32)(((uint32)(Data[Tempi])) << (Tempj * LENGTH_OF_U8));
            Temp32data |= Temp8data;
            ++Tempi;/*MR12 Rule-14.2 VIOLATION: Modify Tempi in the other body of loop.it is safe.*/
        }
        /*Add hardware status wait for input msg idle*/
#if(CRYPTO_METHOD_POLLING == CRYPTO_ASYNJOB_METHOD_SUPPORT)
        while (Crypto_Lld_HcuGetStatusFlag(INPUT_MESSAGE_WAIT_FLAG) == FALSE)
        {}
#endif
        HCU->INMSG  = Temp32data;
        Temp32data = 0x00000000;
    }
    /*Data processing of less than 4 bytes*/
    if (Tempi < Length)
    {
        for (Tempj = 0; Tempj < (Length - Tempi); ++Tempj)
        {
            /*MR12 Rule-14.2 VIOLATION: Converte Data[Tempi],result not large than 32-bits.it is safe.*/
            Temp8data = (uint32)(((uint32)(Data[Tempi + Tempj])) << (Tempj * LENGTH_OF_U8));
            Temp32data |= Temp8data;
        }
        for (; Tempj < NUMINBYTE_OF_U32; ++Tempj)
        {
            Temp8data = (uint32)((uint32)0x00 << (Tempj * LENGTH_OF_U8));
            Temp32data |= Temp8data;
        }
        HCU->INMSG  = Temp32data;
    }
}
/* PRQA S 2469,4391 --*/

/**
 * @brief This function reads data from the HCU output FIFO.
 *
 * @param[out] Data Pointer to the buffer where the read data will be stored.
 * @param[in] Length Length of the data to be read.
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuReadOutputFifo(uint8 *Data, uint8 Length)
{
    uint8 Tempi = 0;
    uint8 Tempk = 0;
    uint32 Temp32data = 0;
    for (; Tempi < (Length / NUMINBYTE_OF_U32); ++Tempi)
    {
        Temp32data = HCU->OUTMSG;
        Data[Tempk] = (uint8)((Temp32data >> 0U) & LSBYTE_OF_U32);/*PRQA S 2985 */
        ++Tempk;
        Data[Tempk] = (uint8)((Temp32data >> LENGTH_OF_U8) & LSBYTE_OF_U32);
        ++Tempk;
        Data[Tempk] = (uint8)((Temp32data >> LENGTH_OF_U16)  & LSBYTE_OF_U32);
        ++Tempk;
        Data[Tempk] = (uint8)((Temp32data >> LENGTH_OF_U24)  & LSBYTE_OF_U32);/*PRQA S 2985 */
        ++Tempk;
    }
}

/*MR12 Rule-14.2 VIOLATION: Converte MacVerif[Tempi],result not large than 32-bits.it is safe.*/
/*MR12 Rule-14.2 VIOLATION: Modify Tempi in the other body of loop.it is safe.*/
/**
 * @brief This function sets the input MAC value for the HCU.
 *
 * @param[in] MacVerif Pointer to the MAC data.
 * @param[in] Length Length of the MAC data.
 * @param[in] HcuEngine HCU engine type.
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuSetInputMac(const uint8 *MacVerif, uint32 Length, Crypto_Lld_Hcu_EngineType HcuEngine)
{
    uint8 Tempi = 0U;
    uint8 Tempk = 0U;
    uint32 Temp32data  = 0U;
    uint32 Temp8data = 0U;
    volatile uint32 *MacRegPtr;
#if defined(HCU_SUPPORT_HASH)
    boolean TempReady = FALSE;
    if (ENG_SHA == HcuEngine)
    {
        TempReady = Crypto_Lld_HcuGetStatusFlag(SHA_CTX_WAIT_FLAG);
        MacRegPtr = &HCU->CONTEXT_28_35[0];
    }
    else
    {
        TempReady = Crypto_Lld_HcuGetStatusFlag(AES_MAC_WAIT_FLAG);
        MacRegPtr = &HCU->CONTEXT_8_11[0];
    }
    if (TRUE == TempReady)
#else
    (void)HcuEngine;
    MacRegPtr = &HCU->CONTEXT_8_11[0];
    if (TRUE == Crypto_Lld_HcuGetStatusFlag(AES_MAC_WAIT_FLAG))
#endif
    {
        while (Tempi < Length)
        {

            for (uint8 Tempj = 0; Tempj < NUMINBYTE_OF_U32; ++Tempj)
            {
                Temp8data = (uint32)(((uint32)(MacVerif[Tempi])) << (Tempj * LENGTH_OF_U8)); /* PRQA S 4391 */
                Temp32data |= Temp8data;
                ++Tempi;/* PRQA S 2469 */
            }
            MacRegPtr[Tempk]  = Temp32data;
            ++Tempk;
            Temp32data = 0x00000000;
        }
    }
}

/**
 * @brief This function sets input fifo dma for HCU.
 *
 * @param[in] Enable TRUE to enable input DMA, FALSE to disable it.
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuSetInputDma(boolean Enable)
{
    SchM_Enter_Crypto_CRYPTO_EXCLUSIVE_AREA_02();
    if (TRUE == Enable)
    {
        HCU->CR |= HCU_CR_INDMAE_MASK;
    }
    else
    {
        HCU->CR &= ~HCU_CR_INDMAE_MASK;
    }
    SchM_Exit_Crypto_CRYPTO_EXCLUSIVE_AREA_02();
}

/**
 * @brief This function sets output fifo dma for HCU.
 *
 * @param[in] Enable TRUE to enable output DMA, FALSE to disable it.
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuSetOutputDma(boolean Enable)
{
    SchM_Enter_Crypto_CRYPTO_EXCLUSIVE_AREA_03();
    if (TRUE == Enable)
    {
        HCU->CR |= HCU_CR_OUTDMAE_MASK;
    }
    else
    {
        HCU->CR &= ~HCU_CR_OUTDMAE_MASK;
    }
    SchM_Exit_Crypto_CRYPTO_EXCLUSIVE_AREA_03();
}


#if defined(HCU_SUPPORT_HASH_VERIFICATION)
/**
 * @brief This function sets SHA verification for HCU.
 *
 * @param[in] Enable TRUE to enable SHA verification, FALSE to disable it.
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuSetShaVerify(boolean Enable)
{
    SchM_Enter_Crypto_CRYPTO_EXCLUSIVE_AREA_04();
    if (TRUE == Enable)
    {
        HCU->CR |= HCU_CR_SHAVE_MASK;
    }
    else
    {
        HCU->CR &= ~HCU_CR_SHAVE_MASK;
    }
    SchM_Exit_Crypto_CRYPTO_EXCLUSIVE_AREA_04();
}
#endif

/**
 * @brief This function reads the IV value from the HCU.
 *
 * @param[out] Tempiv Pointer to the buffer to store the IV value.
 * @param[in] HcuEngine The HCU engine type (AES or SHA).
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuReadIv(uint8 *Tempiv, Crypto_Lld_Hcu_EngineType HcuEngine)
{
    uint8 Tempk = 0;
    uint32 Temp32data = 0;

    if ((ENG_SHA != HcuEngine) && (Crypto_Lld_HcuGetStatusFlag(AES_IV_READY_FLAG) == TRUE))
    {
        for (uint8 Tempi = 0; Tempi < 4; ++Tempi)
        {
            Temp32data = HCU->CONTEXT_4_7[Tempi];
            Tempiv[Tempk] = (uint8)((Temp32data >> 0U) & LSBYTE_OF_U32);/*PRQA S 2985 */
            ++Tempk;
            Tempiv[Tempk] = (uint8)((Temp32data >> LENGTH_OF_U8) & LSBYTE_OF_U32);
            ++Tempk;
            Tempiv[Tempk] = (uint8)((Temp32data >> LENGTH_OF_U16)  & LSBYTE_OF_U32);
            ++Tempk;
            Tempiv[Tempk] = (uint8)((Temp32data >> LENGTH_OF_U24)  & LSBYTE_OF_U32);/*PRQA S 2985 */
            ++Tempk;
        }
    }
}

/**
 * @brief This function reads the MAC value(CONTEXT value for SHA) from the HCU.
 *
 * @param[out] Mac Pointer to the buffer to store the MAC value.
 * @param[in] HcuEngine The HCU engine type (AES or SHA).
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuReadMac(uint8 *Mac, Crypto_Lld_Hcu_EngineType HcuEngine)
{

    uint8 Tempk = 0;
    uint32 Temp32data = 0;
    uint32 TempLength = 0;
    volatile uint32 *MacRegPtr;
#if defined (HCU_SUPPORT_HASH)
    boolean TempReady = FALSE;
    if (ENG_SHA == HcuEngine)
    {
        TempReady = Crypto_Lld_HcuGetStatusFlag(SHA_CTX_READY_FLAG);
        TempLength = HCU_SHA_CONTEXT_LENGTH / NUMINBYTE_OF_U32;
        MacRegPtr = &HCU->CONTEXT_28_35[0];
    }
    else
    {
        TempReady = Crypto_Lld_HcuGetStatusFlag(AES_MAC_READY_FLAG);
        TempLength = HCU_AES_MAC_LENGTH / NUMINBYTE_OF_U32;
        MacRegPtr = &HCU->CONTEXT_8_11[0];
    }
    if (TRUE == TempReady)
#else
    (void)HcuEngine;
    TempLength = HCU_AES_MAC_LENGTH / NUMINBYTE_OF_U32;
    MacRegPtr = &HCU->CONTEXT_8_11[0];
    if (Crypto_Lld_HcuGetStatusFlag(AES_MAC_READY_FLAG) == TRUE)
#endif
    {
        for (uint8 Tempi = 0; Tempi < TempLength; ++Tempi)
        {
            Temp32data = MacRegPtr[Tempi];
            Mac[Tempk] = (uint8)((Temp32data >> 0U) & LSBYTE_OF_U32);/*PRQA S 2985 */
            ++Tempk;
            Mac[Tempk] = (uint8)((Temp32data >> LENGTH_OF_U8) & LSBYTE_OF_U32);
            ++Tempk;
            Mac[Tempk] = (uint8)((Temp32data >> LENGTH_OF_U16)  & LSBYTE_OF_U32);
            ++Tempk;
            Mac[Tempk] = (uint8)((Temp32data >> LENGTH_OF_U24)  & LSBYTE_OF_U32);/*PRQA S 2985 */
            ++Tempk;
        }
    }
}

/**
 * @brief  This function writes data to the HCU input MSG.
 *
 * @param None
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuWriteFifo(void)
{

    /* Check if hcu need to write data */
    if ((TRUE == Crypto_Lld_HcuGetStatusFlag(INPUT_MESSAGE_WAIT_FLAG)) && (Crypto_RunningData.HcuInputControlIndex != 0U))
    {
        /* Convert the message length to be processed */
        if (Crypto_RunningData.HcuInputControlIndex < FEATURE_HCU_ONE_LOOP_DATA_SIZE)
        {

            Crypto_Lld_HcuWriteInputFifo(Crypto_RunningData.HcuInputPtr, Crypto_RunningData.HcuInputControlIndex);
            Crypto_RunningData.HcuInputPtr += Crypto_RunningData.HcuInputControlIndex;
            Crypto_RunningData.HcuInputControlIndex = 0U;
        }
        else
        {
            Crypto_Lld_HcuWriteInputFifo(Crypto_RunningData.HcuInputPtr, FEATURE_HCU_ONE_LOOP_DATA_SIZE);
            Crypto_RunningData.HcuInputControlIndex -= FEATURE_HCU_ONE_LOOP_DATA_SIZE;
            Crypto_RunningData.HcuInputPtr += FEATURE_HCU_ONE_LOOP_DATA_SIZE;/*PRQA S 0488 */
        }
    }
}

/*
*  MR12 Rule-18.4 VIOLATION: The variant "Crypto_RunningData.HcuOutPutPtr" type of pointer increases by a fixed value each time,
*  the total size is controlled by the customer.
*/
/**
 * @brief  This function get the output data.
 *
 * @param None
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuReadOutputLoop(void)
{
    if ((ENG_AES == Crypto_RunningData.HcuEngine) &&
            (ALG_AES_CMAC == Crypto_RunningData.AlgorithmAESMode))
    {
        if (MODE_DEC == Crypto_RunningData.HcuModeSel)
        {
            /*MAC Verification.Check if match.*/
            if (TRUE == Crypto_Lld_HcuGetStatusFlag(AES_MAC_VALID_FLAG))
            {
                *(Crypto_RunningData.HcuCmacVerifyResultPtr) = (Crypto_VerifyResultType)0U;
            }
            else
            {
                *(Crypto_RunningData.HcuCmacVerifyResultPtr) = (Crypto_VerifyResultType)1U;
            }
        }
        else
        {
            /*MAC Generate.Read mac */
            for (uint8 Tempi = 0U; Tempi < 16; ++Tempi)
            {
                Crypto_RunningData.HcuOutPutPtr[Tempi] = Crypto_RunningData.TempMacValue[Tempi];
                Crypto_RunningData.HcuOutPutPtrLength = 0;
            }
        }
    }
}
/*
*  MR12 Rule-18.4 VIOLATION: The variant "Crypto_RunningData.HcuOutPutPtr" type of pointer increases by a fixed value each time,
*  the total size is controlled by the customer.
*/
/**
 * @brief  This function get the output data when the output FIFO is full.
 *
 * @param None
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuDisposeOutputData(void)
{
    uint32 Tempdata = 0U;
    /* Read outputfifo */
    while (TRUE == Crypto_Lld_HcuGetStatusFlag(OUTPUT_MESSAGE_READY_FLAG))
    {
        if (0U != Crypto_RunningData.HcuOutPutPtrLength)
        {
            Crypto_Lld_HcuReadOutputFifo(Crypto_RunningData.HcuOutPutPtr, FEATURE_HCU_ONE_LOOP_DATA_SIZE);
            Crypto_Lld_HcuClearStatusFlag(OUTPUT_MESSAGE_READY_FLAG);
            Crypto_RunningData.HcuOutPutPtr += FEATURE_HCU_ONE_LOOP_DATA_SIZE;/*PRQA S 0488 */
            Crypto_RunningData.HcuOutPutPtrLength -= FEATURE_HCU_ONE_LOOP_DATA_SIZE;
        }
        else
        {
            Crypto_Lld_HcuReadOutputFifo((uint8 *)&Tempdata, 4U);
            Crypto_Lld_HcuClearStatusFlag(OUTPUT_MESSAGE_READY_FLAG);
        }
    }
}

/**
 * @brief  This function configures the key for the HCU.
 *
 * @param None
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuConfigureKey(void)
{
    if (ENG_SHA != Crypto_RunningData.HcuEngine)
    {
        while (FALSE == Crypto_Lld_HcuGetStatusFlag(KEY_WAIT_FLAG))
        {
            __ASM("nop");
        }

        if (TRUE == Crypto_RunningData.HcuRunKey->UseSecNVRKey)
        {
            /*Loard key Form NVM */
            (void)Crypto_KeyManage_LoadAESKey(Crypto_RunningData.HcuRunKey->NVRKeySlot);
        }
        else
        {
            Crypto_Lld_HcuSetUserKey(Crypto_RunningData.HcuRunKey->KeyRamAdress, Crypto_RunningData.HcuRunKey->CryptoKeyElementMaxSize);
        }
#if defined (HCU_SUPPORT_KEY_SIZE_SET)
        /*Set key length*/
        Crypto_Lld_HcuSetKeySize(Crypto_RunningData.HcuRunKey->KenLengthInbits);
#endif /* HCU_SUPPORT_KEY_SIZE_SET */
    }
}

/**
 * @brief  This function configures the MAC length for the HCU.
 *
 * @param[in] MsgIndexType The message index type.
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuConfigMacLength(Crypto_Lld_Hcu_MsgType MsgIndexType)
{
    if ((ENG_AES == Crypto_RunningData.HcuEngine) &&
            (ALG_AES_CBC == Crypto_RunningData.AlgorithmAESMode))
    {
        if (MSG_START == MsgIndexType)
        {
            while (FALSE == Crypto_Lld_HcuGetStatusFlag(AES_IV_WAIT_FLAG));
            Crypto_Lld_HcuSetIv(Crypto_RunningData.HcuSecondInputPtr);
        }
        else
        {
            Crypto_Lld_HcuSetIv(Crypto_RunningData.IvFillData);
        }
    }
    else if ((ENG_AES == Crypto_RunningData.HcuEngine) &&
             (ALG_AES_CMAC == Crypto_RunningData.AlgorithmAESMode))
    {
        /*Configure MacLength if needed */
        if (MODE_DEC == Crypto_RunningData.HcuModeSel)
        {
            /*MAC Verification*/
            Crypto_Lld_HcuSetMacLength(Crypto_RunningData.HcuSecondInputLength);
            if (MSG_START != MsgIndexType)
            {
                while (FALSE == Crypto_Lld_HcuGetStatusFlag(AES_IV_WAIT_FLAG));
                Crypto_Lld_HcuSetIv(Crypto_RunningData.IvFillData);
            }
        }
        else
        {
            /*MAC Generate */
            Crypto_Lld_HcuSetMacLength(Crypto_RunningData.HcuOutPutPtrLength);
            if (MSG_START != MsgIndexType)
            {
                while (FALSE == Crypto_Lld_HcuGetStatusFlag(AES_IV_WAIT_FLAG));
                Crypto_Lld_HcuSetIv(Crypto_RunningData.IvFillData);
            }
        }
    }
    else
    {
        /*do nothing*/
    }
}

/*
*  MR12 Rule-13.5 VIOLATION: Even if there is side effects,it reads only,so it is safe.
*  MR12 Rule-18.4 VIOLATION: The variant "Crypto_RunningData.HcuOutPutPtr" type of pointer increases by a fixed value each time,
*  the total size is controlled by the customer.
*/
/**
 * @brief  This function writes input data to the HCU for a sync operation.
 *
 * @param[in] MsgIndexType The message index type.
 * @return None
 */
CRYPTO_FUNC static void  Crypto_Lld_HcuWriteInputLoop(Crypto_Lld_Hcu_MsgType MsgIndexType)
{
    uint8 Tempdata = 1;

    Crypto_Lld_HcuSetInputDma(FALSE);
    Crypto_Lld_HcuSetOutputDma(FALSE);
    Crypto_Lld_HcuStartEngine();
    Crypto_Lld_HcuConfigureKey();
    Crypto_Lld_HcuConfigMacLength(MsgIndexType);

    do
    {
        /* Check If OutputFIFO is full */
        Crypto_Lld_HcuDisposeOutputData();
        Crypto_Lld_HcuReadMac(Crypto_RunningData.TempMacValue, Crypto_RunningData.HcuEngine);
        Crypto_Lld_HcuReadIv(Crypto_RunningData.IvFillData, Crypto_RunningData.HcuEngine);
        if (ENG_SHA == Crypto_RunningData.HcuEngine)
        {
            Crypto_Lld_HcuSetInputMac(Crypto_RunningData.TempMacValue, HCU_SHA_CONTEXT_LENGTH, Crypto_RunningData.HcuEngine);
        }
        else
        {
            Crypto_Lld_HcuSetInputMac(Crypto_RunningData.HcuSecondInputPtr, Crypto_RunningData.HcuSecondInputLength, Crypto_RunningData.HcuEngine);
        }
        /* Check if Operation is already done */

        if (TRUE == Crypto_Lld_HcuGetStatusFlag(OPERATION_DONE_FLAG))
        {
            Crypto_Lld_HcuReadOutputLoop();
            if (0U == Crypto_RunningData.HcuInputControlIndex)
            {
                Tempdata = 0;
            }
            Crypto_Lld_HcuClearStatusFlag(OPERATION_DONE_FLAG);
        }
        Crypto_Lld_HcuWriteFifo();
    } while (Tempdata > 0U);
}
#if (CRYPTO_METHOD_POLLING != CRYPTO_ASYNJOB_METHOD_SUPPORT)
/*
*  MR12 Rule-18.4 VIOLATION: The variant "Crypto_RunningData.HcuOutPutPtr" type of pointer increases by a fixed value each time,
*  the total size is controlled by the customer.
*/

/**
 * @brief  This function checks the result of the HCU operation.
 *
 * @param void
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuCheckResult(void)
{
    boolean tempvalue;
    if ((ENG_AES == Crypto_RunningData.HcuEngine) &&
            (ALG_AES_CMAC == Crypto_RunningData.AlgorithmAESMode))
    {
        if (MODE_DEC == Crypto_RunningData.HcuModeSel)
        {
            /*MAC Verification.Check if match.*/
            tempvalue = Crypto_Lld_HcuGetStatusFlag(AES_MAC_VALID_FLAG);
            if (TRUE == tempvalue)
            {
                *(Crypto_RunningData.HcuCmacVerifyResultPtr) = (Crypto_VerifyResultType)0U;
            }
            else
            {
                *(Crypto_RunningData.HcuCmacVerifyResultPtr) = (Crypto_VerifyResultType)1U;
            }
        }
        else
        {
            /* Copy TempMacValue to HcuOutPutPtr */
            for (uint8 Tempi = 0U; Tempi < 16; ++Tempi)
            {
                Crypto_RunningData.HcuOutPutPtr[Tempi] = Crypto_RunningData.TempMacValue[Tempi];
                Crypto_RunningData.HcuOutPutPtrLength = 0;
            }
        }
    }
}
#endif
#if (CRYPTO_METHOD_INTERRUPT != CRYPTO_ASYNJOB_METHOD_SUPPORT)
/*
*  MR12 Rule-18.4 VIOLATION: The variant "Crypto_RunningData.HcuOutPutPtr" type of pointer increases by a fixed value each time,
*  the total size is controlled by the customer.
*/
/**
 * @brief  This function writes input data to the HCU by polling for an asynchronous operation.
 *
 * @param void
 * @return uint8
 */
CRYPTO_FUNC static uint8  Crypto_Lld_HcuWriteInputPolling(void)
{
    uint8 Retvl = 1;
    /* Check If OutputFIFO is full */
    Crypto_Lld_HcuDisposeOutputData();
    Crypto_Lld_HcuReadMac(Crypto_RunningData.TempMacValue, Crypto_RunningData.HcuEngine);
    Crypto_Lld_HcuReadIv(Crypto_RunningData.IvFillData, Crypto_RunningData.HcuEngine);
    if (ENG_SHA == Crypto_RunningData.HcuEngine)
    {
        Crypto_Lld_HcuSetInputMac(Crypto_RunningData.TempMacValue, 32, Crypto_RunningData.HcuEngine);
    }
    else
    {
        Crypto_Lld_HcuSetInputMac(Crypto_RunningData.HcuSecondInputPtr, Crypto_RunningData.HcuSecondInputLength, Crypto_RunningData.HcuEngine);
    }
    /* Check if Operation is already done */
    if (TRUE == Crypto_Lld_HcuGetStatusFlag(OPERATION_DONE_FLAG))
    {
        Crypto_Lld_HcuReadOutputLoop();
        if (0U == Crypto_RunningData.HcuInputControlIndex)
        {
            Retvl = 0;
        }
        Crypto_Lld_HcuClearStatusFlag(OPERATION_DONE_FLAG);
    }
#if (CRYPTO_METHOD_POLLING == CRYPTO_ASYNJOB_METHOD_SUPPORT)
    Crypto_Lld_HcuWriteFifo();
#endif
    return Retvl;
}
#endif

#if (CRYPTO_METHOD_DMA == CRYPTO_ASYNJOB_METHOD_SUPPORT)
/*
*  MR12 Rule-8.13 VIOLATION: In the followed three functions,"parameter" is pointer and not used in function,it will violate this rule.
*but,it is safe
*/
/**
 * @brief DMA error callback function.
 *
 * @param[in] parameter Pointer to the DMA channel parameter.
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuDmaErrorHandle(uint32 parameter)/*PRQA S 3673 */
{
    /* Check if Operation is already done */
    (void)parameter;
    Crypto_Lld_HcuSetInputDma(FALSE);
    Crypto_Lld_HcuSetOutputDma(FALSE);
    Crypto_Lld_StartDmaFlag = HCU_JOB_ERROR;/*DMA ERROR*/
}

/**
 * @brief DMA input complete callback function.
 *
 * @param[in] parameter Pointer to the DMA channel parameter.
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuDmaInputComplete(uint32 parameter)/*PRQA S 3673 */
{
    /* Check if Operation is already done */
    (void)parameter;
    Crypto_Lld_HcuSetInputDma(FALSE);
    Crypto_RunningData.HcuInputPtr += Crypto_RunningData.HcuInputControlIndex;/*PRQA S 0488 */
    Crypto_RunningData.HcuInputControlIndex = 0U;
    if (ALG_AES_CMAC == Crypto_RunningData.AlgorithmAESMode)
    {
        Crypto_Lld_StartDmaFlag = HCU_JOB_COMPLETED;/*DMA finish.CMAC not generate DMA output req*/
        Crypto_Lld_HcuSetOutputDma(FALSE);
    }
}

/**
 * @brief DMA output complete callback function.
 *
 * @param[in] parameter Pointer to the DMA channel parameter.
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuDmaOutputComplete(uint32 parameter)/*PRQA S 3673 */
{
    /* Check if Operation is already done */
    (void)parameter;
    Crypto_Lld_HcuSetOutputDma(FALSE);
    if (ALG_AES_CMAC != Crypto_RunningData.AlgorithmAESMode)
    {
        Crypto_Lld_StartDmaFlag = HCU_JOB_COMPLETED;/*DMA finish.CMAC not generate DMA output req*/
    }
}
/**
 * @brief Configure DMA channels for HCU input and output data transfer.
 *
 * @param None
 * @return None
 */
CRYPTO_FUNC static void Crypto_Lld_HcuConfigDma(void)
{
    if (Crypto_RunningData.HcuOutPutPtr != NULL_PTR)
    {
        Crypto_Lld_HcuOutputDmaTcd = *DmaChannelTransferConfigArray[Crypto_PreCompileConfig.EgressDMAChannel];
        /*config Dma,DMA block size config by watermark, now is 4 words, 16 bytes*/
        Crypto_Lld_HcuOutputDmaTcd.SrcTransferSize = DMA_TRANSFER_SIZE_4_BYTE;
        Crypto_Lld_HcuOutputDmaTcd.DestTransferSize = DMA_TRANSFER_SIZE_4_BYTE;
        Crypto_Lld_HcuOutputDmaTcd.SrcOffset = 0;
        Crypto_Lld_HcuOutputDmaTcd.DestOffset = (sint16)(1U << (uint16)DMA_TRANSFER_SIZE_4_BYTE);
        Crypto_Lld_HcuOutputDmaTcd.TransferLoopByteCount = (uint32) 1 << (uint32)DMA_TRANSFER_SIZE_16_BYTE;
        Crypto_Lld_HcuOutputDmaTcd.TriggerCount = (uint32)(Crypto_RunningData.HcuOutPutPtrLength / ((uint32)1U << (uint32)DMA_TRANSFER_SIZE_16_BYTE));

        (void)CddDma_SetLogicChannelTransfer(Crypto_PreCompileConfig.EgressDMAChannel,
                                             (uint32)(&(HCU->OUTMSG)),
                                             (uint32)Crypto_RunningData.HcuOutPutPtr,
                                             &Crypto_Lld_HcuOutputDmaTcd);/*PRQA S 0306 */


        CddDma_InstallCallback((CddDma_ChannelType)Crypto_PreCompileConfig.EgressDMAChannel, Crypto_Lld_HcuDmaOutputComplete, 0);
        CddDma_InstallErrorCallback((CddDma_ChannelType)Crypto_PreCompileConfig.EgressDMAChannel, Crypto_Lld_HcuDmaErrorHandle, 0);
        CddDma_StartChannel((CddDma_ChannelType)Crypto_PreCompileConfig.EgressDMAChannel);
        Crypto_Lld_HcuSetOutputDma(TRUE);
    }
    if (Crypto_RunningData.HcuInputPtr != NULL_PTR)
    {
        Crypto_Lld_HcuInputDmaTcd = *DmaChannelTransferConfigArray[Crypto_PreCompileConfig.IngressDMAChannel];
        /*config Dma,DMA block size config by watermark, now is 4 words, 16 bytes*/
        Crypto_Lld_HcuInputDmaTcd.SrcTransferSize = DMA_TRANSFER_SIZE_4_BYTE;
        Crypto_Lld_HcuInputDmaTcd.DestTransferSize = DMA_TRANSFER_SIZE_4_BYTE;
        Crypto_Lld_HcuInputDmaTcd.SrcOffset = (sint16)(1U << (uint16)DMA_TRANSFER_SIZE_4_BYTE);
        Crypto_Lld_HcuInputDmaTcd.DestOffset = 0;
        if (ENG_SHA == Crypto_RunningData.HcuEngine)
        {
            /* In SHA mode, HCU should write 1 or 2 words one time, DMA block size config by watermark, now is 2 words, 8 bytes*/
            Crypto_Lld_HcuInputDmaTcd.TransferLoopByteCount = 8U;
            Crypto_Lld_HcuInputDmaTcd.TriggerCount = (uint32)(Crypto_RunningData.HcuInputControlIndex / 8U);
        }
        else
        {
            /* DMA block size config by watermark, now is 4 words, 16 bytes */
            Crypto_Lld_HcuInputDmaTcd.TransferLoopByteCount = (uint32) 1 << (uint32)DMA_TRANSFER_SIZE_16_BYTE;
            Crypto_Lld_HcuInputDmaTcd.TriggerCount = (uint32)(Crypto_RunningData.HcuInputControlIndex / ((uint32)1U << (uint32)DMA_TRANSFER_SIZE_16_BYTE));
        }
        /*  MR12 Rule-11.4 VIOLATION: "(uint32)(&(HCU->IFDAT)" convert address to uint32, will violate this rule.
        *but,it is safe */
        (void)CddDma_SetLogicChannelTransfer(Crypto_PreCompileConfig.IngressDMAChannel,
                                             (uint32)Crypto_RunningData.HcuInputPtr,
                                             (uint32)(&(HCU->INMSG)),
                                             &Crypto_Lld_HcuInputDmaTcd);/*PRQA S 0306 */
        CddDma_InstallCallback((CddDma_ChannelType)Crypto_PreCompileConfig.IngressDMAChannel, Crypto_Lld_HcuDmaInputComplete, 0);
        CddDma_InstallErrorCallback((CddDma_ChannelType)Crypto_PreCompileConfig.IngressDMAChannel, Crypto_Lld_HcuDmaErrorHandle, 0);
        CddDma_StartChannel((CddDma_ChannelType)Crypto_PreCompileConfig.IngressDMAChannel);
        Crypto_Lld_HcuSetInputDma(TRUE);
    }
}

/**
 * @brief This function configures and enables the necessary HCU interrupts for an asynchronous job when using DMA mode.
 *
 * @param[in] MsgEngine    The HCU engine type (e.g., AES, SHA).
 * @param[in] MsgAesMode   The cryptographic algorithm to use.
 * @param[in] MsgIndexType The message index type (e.g., start, middle, end).
 * @param[in] MsgModeSel   The engine mode (encryption or decryption).
 */
CRYPTO_FUNC static void Crypto_Lld_HcuIntCfgWithDma(Crypto_Lld_Hcu_EngineType MsgEngine, Crypto_Lld_Hcu_AesModeType MsgAesMode, Crypto_Lld_Hcu_MsgType MsgIndexType, Crypto_Lld_Hcu_EngineModeType MsgModeSel)
{
    if (ENG_SHA == MsgEngine)
    {
        /*When implementing SHA, the sha ctx wait interrupt and done interrupt are required.*/
        Crypto_Lld_HcuSetIntMode(SHA_CTX_READY_FLAG, TRUE);
    }
    else
    {
        if (ALG_AES_CMAC == MsgAesMode)
        {
            /*When implementing CMAC, some HCU interrupts are still required.*/
            if (MODE_ENC == MsgModeSel)
            {
                Crypto_Lld_HcuSetIntMode(AES_MAC_READY_FLAG, TRUE);
            }
            else
            {
                Crypto_Lld_HcuSetIntMode(AES_MAC_WAIT_FLAG, TRUE);
            }
            if (0U == (MsgIndexType & MSG_END))
            {
                Crypto_Lld_HcuSetIntMode(AES_IV_READY_FLAG, TRUE);
            }
            Crypto_Lld_HcuSetIntMode(HCU_INTE_ODIE_MASK, TRUE);
        }
    }
}
/**
 * @brief  This function handles the process of writing input data to the HCU for an asynchronous job when using DMA mode.
 *
 * @param[in] MsgIndexType The message index type (e.g., start, middle, end).
 * @return uint8
 */
CRYPTO_FUNC static uint8  Crypto_Lld_HcuWriteInputSingle(Crypto_Lld_Hcu_MsgType MsgIndexType)
{
    uint8 Retvl = 1;
    if (HCU_JOB_IDLE == Crypto_Lld_StartDmaFlag)
    {
        /*DMA is IDLE*/
        Crypto_Lld_StartDmaFlag = HCU_JOB_RUNNING;/*DMA Started*/
        Crypto_Lld_HcuIntCfgWithDma(Crypto_RunningData.HcuEngine, Crypto_RunningData.AlgorithmAESMode, MsgIndexType, Crypto_RunningData.HcuModeSel);
        if (ENG_SHA != Crypto_RunningData.HcuEngine)
        {
            Crypto_Lld_HcuConfigDma();
            Crypto_Lld_HcuStartEngine();
        }
        else
        {
            Crypto_Lld_HcuConfigDma();
            Crypto_Lld_HcuStartEngine();
        }
        Crypto_Lld_HcuConfigureKey();
        Crypto_Lld_HcuConfigMacLength(MsgIndexType);
        if (ENG_SHA == Crypto_RunningData.HcuEngine)
        {
            Crypto_Lld_HcuSetInputMac(Crypto_RunningData.TempMacValue, 32, Crypto_RunningData.HcuEngine);
        }
        else
        {
            Crypto_Lld_HcuSetInputMac(Crypto_RunningData.HcuSecondInputPtr, Crypto_RunningData.HcuSecondInputLength, Crypto_RunningData.HcuEngine);
        }
    }
    if (HCU_JOB_COMPLETED == Crypto_Lld_StartDmaFlag)
    {
        /*DMA  idle*/
        if (TRUE == Crypto_Lld_HcuGetStatusFlag(OPERATION_DONE_FLAG))
        {

            Crypto_Lld_HcuCheckResult();
            Crypto_Lld_HcuClearStatusFlag(OPERATION_DONE_FLAG);
            Crypto_Lld_StartDmaFlag = HCU_JOB_IDLE;/*DMA Idle*/
            Retvl = 0;
        }
    }
    else if (HCU_JOB_ERROR == Crypto_Lld_StartDmaFlag)
    {
        /*DMA  Error*/
        Crypto_Lld_StartDmaFlag = HCU_JOB_IDLE;/*DMA Idle*/
        Retvl = 0xFEU;
    }
    else
    {
        if (ENG_SHA == Crypto_RunningData.HcuEngine)
        {
            /*Hash not spport DMA,using polling mode*/
            Retvl = Crypto_Lld_HcuWriteInputPolling();
        }
        if (Retvl != 1U)
        {
            Crypto_Lld_StartDmaFlag = HCU_JOB_IDLE;/*DMA Idle*/
        }
    }
    return (Retvl);
}
#elif(CRYPTO_METHOD_INTERRUPT == CRYPTO_ASYNJOB_METHOD_SUPPORT)
/**
 * @brief This function configures and enables the necessary HCU interrupts for an asynchronous job when using interrupt mode.
 *
 * @param[in] MsgEngine    The HCU engine type (e.g., AES, SHA).
 * @param[in] MsgAesMode   The cryptographic algorithm to use.
 * @param[in] MsgIndexType The message index type (e.g., start, middle, end).
 * @param[in] MsgModeSel   The engine mode (encryption or decryption).
 */
CRYPTO_FUNC static void Crypto_Lld_HcuIntEnable(Crypto_Lld_Hcu_EngineType MsgEngine, Crypto_Lld_Hcu_AesModeType MsgAesMode, \
        Crypto_Lld_Hcu_MsgType MsgIndexType, Crypto_Lld_Hcu_EngineModeType MsgModeSel)
{
    Crypto_Lld_HcuSetDefaultInt(TRUE);
    if (ENG_SHA == MsgEngine)
    {
        Crypto_Lld_HcuSetIntMode(SHA_CTX_READY_FLAG, TRUE);
    }
    else
    {
        switch (MsgAesMode)
        {
            case ALG_AES_CBC:
                Crypto_Lld_HcuSetIntMode(AES_IV_READY_FLAG, TRUE);
                break;
            case ALG_AES_CMAC:
            {
                if (MODE_ENC == MsgModeSel)
                {
                    Crypto_Lld_HcuSetIntMode(AES_MAC_READY_FLAG, TRUE);
                }
                else
                {
                    Crypto_Lld_HcuSetIntMode(AES_MAC_WAIT_FLAG, TRUE);
                }
                if (0U == (MsgIndexType & MSG_END))
                {
                    Crypto_Lld_HcuSetIntMode(AES_IV_READY_FLAG, TRUE);
                }
            }
            break;
            default:
                break;
        }


    }
}
/**
 * @brief  This function handles the process of writing input data to the HCU for an asynchronous job when using interrupt mode.
 *
 * @param[in] MsgIndexType The message index type (e.g., start, middle, end).
 * @return uint8
 */
CRYPTO_FUNC static uint8  Crypto_Lld_HcuWriteInputSingle(Crypto_Lld_Hcu_MsgType MsgIndexType)
{
    uint8 Retvl = 1;
    if (HCU_JOB_IDLE == Crypto_Lld_StartIntFlag)
    {
        /*DMA is IDLE*/
        Crypto_Lld_StartIntFlag = HCU_JOB_RUNNING;/*DMA Started*/
        /*Enable the interrupt*/
        Crypto_Lld_HcuIntEnable(Crypto_RunningData.HcuEngine,
                                Crypto_RunningData.AlgorithmAESMode,
                                MsgIndexType,
                                Crypto_RunningData.HcuModeSel);
        Crypto_Lld_HcuStartEngine();
        Crypto_Lld_HcuConfigureKey();
        Crypto_Lld_HcuConfigMacLength(MsgIndexType);
        if (ENG_SHA == Crypto_RunningData.HcuEngine)
        {
            Crypto_Lld_HcuSetInputMac(Crypto_RunningData.TempMacValue, 32, Crypto_RunningData.HcuEngine);
        }
        else
        {
            Crypto_Lld_HcuSetInputMac(Crypto_RunningData.HcuSecondInputPtr, Crypto_RunningData.HcuSecondInputLength, Crypto_RunningData.HcuEngine);
        }
    }
    if (HCU_JOB_COMPLETED == Crypto_Lld_StartIntFlag)
    {
        /*DMA  idle*/
        Crypto_Lld_StartIntFlag = HCU_JOB_IDLE;/*DMA Idle*/
        Retvl = 0;
    }
    else
    {
        /*Nothing to do*/
    }
    return Retvl;
}
#else
/**
 * @brief  This function handles the process of writing input data to the HCU for an asynchronous job when using polling mode.
 *
 * @param[in] MsgIndexType The message index type (e.g., start, middle, end).
 * @return uint8
 */
CRYPTO_FUNC static uint8  Crypto_Lld_HcuWriteInputSingle(Crypto_Lld_Hcu_MsgType MsgIndexType)
{
    uint8 Retvl = 1;
    if (HCU_JOB_IDLE == Crypto_Lld_StartPollingFlag)
    {
        /*state busy*/
        Crypto_Lld_StartPollingFlag = HCU_JOB_RUNNING;
        Crypto_Lld_HcuStartEngine();
        Crypto_Lld_HcuConfigureKey();
        Crypto_Lld_HcuConfigMacLength(MsgIndexType);
    }
    Retvl = Crypto_Lld_HcuWriteInputPolling();
    if (Retvl != 1U)
    {
        Crypto_Lld_StartPollingFlag = HCU_JOB_IDLE;/*state Idle*/
    }
    return Retvl;
}
#endif

#if(CRYPTO_METHOD_POLLING != CRYPTO_ASYNJOB_METHOD_SUPPORT)
/**
 * @brief  This function handles interrupts for the HCU, checking the status of various flags and taking appropriate action.
 *
 * @param void
 * @return None
 */
CRYPTO_FUNC void Crypto_Lld_HcuIntHandle(void)
{
    /*Check If AECMACK*/
#if defined (HCU_SUPPORT_HASH)
    if ((Crypto_Lld_HcuGetIntMode(AES_MAC_READY_FLAG) == TRUE) || (Crypto_Lld_HcuGetIntMode(SHA_CTX_READY_FLAG) == TRUE))
#else
    if (Crypto_Lld_HcuGetIntMode(AES_MAC_READY_FLAG) == TRUE)
#endif
    {
        Crypto_Lld_HcuReadMac(Crypto_RunningData.TempMacValue, Crypto_RunningData.HcuEngine);
    }
#if defined (HCU_SUPPORT_HASH)
    if ((Crypto_Lld_HcuGetIntMode(AES_MAC_WAIT_FLAG) == TRUE) || (Crypto_Lld_HcuGetIntMode(SHA_CTX_WAIT_FLAG) == TRUE))
#else
    if (Crypto_Lld_HcuGetIntMode(AES_MAC_WAIT_FLAG) == TRUE)
#endif
    {
        if (ENG_SHA == Crypto_RunningData.HcuEngine)
        {
            Crypto_Lld_HcuSetInputMac(Crypto_RunningData.TempMacValue, 32, Crypto_RunningData.HcuEngine);
        }
        else
        {
            Crypto_Lld_HcuSetInputMac(Crypto_RunningData.HcuSecondInputPtr, Crypto_RunningData.HcuSecondInputLength, Crypto_RunningData.HcuEngine);
        }
    }

    if (Crypto_Lld_HcuGetIntMode(AES_IV_READY_FLAG) == TRUE)
    {
        Crypto_Lld_HcuReadIv(Crypto_RunningData.IvFillData, Crypto_RunningData.HcuEngine);
    }
    /* Check If OutputFIFO is full */
    if ((Crypto_Lld_HcuGetIntMode(OUTPUT_MESSAGE_READY_FLAG) == TRUE) && (TRUE == Crypto_Lld_HcuGetStatusFlag(OUTPUT_MESSAGE_READY_FLAG)) && \
            (0U != Crypto_RunningData.HcuOutPutPtrLength))
    {
        Crypto_Lld_HcuClearStatusFlag(OUTPUT_MESSAGE_READY_FLAG);
        Crypto_Lld_HcuReadOutputFifo(Crypto_RunningData.HcuOutPutPtr, FEATURE_HCU_ONE_LOOP_DATA_SIZE);
        Crypto_RunningData.HcuOutPutPtr += FEATURE_HCU_ONE_LOOP_DATA_SIZE;/*PRQA S 0488 */
        Crypto_RunningData.HcuOutPutPtrLength -= FEATURE_HCU_ONE_LOOP_DATA_SIZE;
    }
    /* Check if Operation is already done */
    if ((TRUE == Crypto_Lld_HcuGetStatusFlag(OPERATION_DONE_FLAG)) && (TRUE == Crypto_Lld_HcuGetIntMode(OPERATION_DONE_FLAG)))
    {
        Crypto_Lld_HcuCheckResult();
#if(CRYPTO_METHOD_INTERRUPT == CRYPTO_ASYNJOB_METHOD_SUPPORT)
        Crypto_Lld_StartIntFlag = 2U;/*finish*/
#endif
        while ((TRUE == Crypto_Lld_HcuGetStatusFlag(OUTPUT_MESSAGE_READY_FLAG)) && (0U != Crypto_RunningData.HcuOutPutPtrLength))
        {
            Crypto_Lld_HcuClearStatusFlag(OUTPUT_MESSAGE_READY_FLAG);
            Crypto_Lld_HcuReadOutputFifo(Crypto_RunningData.HcuOutPutPtr, FEATURE_HCU_ONE_LOOP_DATA_SIZE);
            Crypto_RunningData.HcuOutPutPtr += FEATURE_HCU_ONE_LOOP_DATA_SIZE;/*PRQA S 0488 */
            Crypto_RunningData.HcuOutPutPtrLength -= FEATURE_HCU_ONE_LOOP_DATA_SIZE;
        }
        Crypto_Lld_HcuClearStatusFlag(OPERATION_DONE_FLAG);
        Crypto_Lld_HcuSetDefaultInt(FALSE);
    }

    if ((Crypto_Lld_HcuGetIntMode(INPUT_MESSAGE_WAIT_FLAG) == TRUE) && \
            (TRUE == Crypto_Lld_HcuGetStatusFlag(INPUT_MESSAGE_WAIT_FLAG)) && \
            (Crypto_RunningData.HcuInputControlIndex != 0U))
    {
        Crypto_Lld_HcuClearStatusFlag(INPUT_MESSAGE_WAIT_FLAG);
        Crypto_Lld_HcuWriteInputFifo(Crypto_RunningData.HcuInputPtr, FEATURE_HCU_ONE_LOOP_DATA_SIZE);
        /* Convert the message length to be processed */
        Crypto_RunningData.HcuInputPtr += FEATURE_HCU_ONE_LOOP_DATA_SIZE;/*PRQA S 0488 */
        Crypto_RunningData.HcuInputControlIndex -= FEATURE_HCU_ONE_LOOP_DATA_SIZE;
    }
}
#endif  /* (CRYPTO_METHOD_POLLING != CRYPTO_ASYNJOB_METHOD_SUPPORT) */

#if defined(HCU_SUPPORT_TOTAL_MSG_LENGTH_SET)
/**
 * @brief This function sets the total message length for the HCU.
 *
 * @param[in] MsgTotalLen The total message length to be set.
 * @return None
 */
CRYPTO_FUNC void Crypto_Lld_HcuSetMsgTotalLength(uint32 MsgTotalLen)
{
    HCU->MSGINFO = HCU_MSGINFO_MSGTOT(MsgTotalLen);/*PRQA S 2985 */
}
#endif

/**
 * @brief This function configures the HCU with the length of input data to be processed,
 * based on the message type and operation type.
 *
 * @param[in] MsgType   The message index type (e.g., start, middle, end).
 * @param[in] CallType  The type of cryptographic operation (e.g., single, stream, multi).
 * @return uint8
 */
CRYPTO_FUNC  uint8 Crypto_Lld_HcuSetInputDataLength(Crypto_Lld_Hcu_MsgType MsgType, Crypto_OperationType CallType)
{
    uint8 Retvl = 0;
    uint32 Tempdata;
    /*Set MSG Length*/
    Tempdata = Crypto_RunningData.HcuInputLength - Crypto_RunningData.HcuInputIndex;
    if ((Tempdata > HCU_MAXSIZE_WRITEONCE)
            && ((CRYPTO_OPT_MULTI_MODE == CallType)
                || (MSG_END == MsgType)))
    {
        /*message more then 31K,and mode is finish or Seperately call then Error*/
        Retvl = HCU_ERRO_DATAOVERFLOW;
    }
    else if ((Tempdata > HCU_MAXSIZE_WRITEONCE)
             && (CRYPTO_OPT_STREAM_MODE == CallType)
             && (MSG_MIDDLE == MsgType))
    {
        /*message more then 31K,and mode MIDDLE of stream call then Error*/
        Retvl = HCU_ERRO_DATAOVERFLOW;
    }
    else if ((Tempdata > HCU_MAXSIZE_WRITEONCE) && ((CRYPTO_OPT_SINGLE_MODE == CallType) || (CRYPTO_OPT_STREAM_MODE == CallType)))
    {
        /*message more then 31K,and Mixture call*/
        Crypto_Lld_HcuSetMsgLength(HCU_MAXSIZE_WRITEONCE);
        Crypto_Lld_HcuSetMsgType(MsgType);
        Crypto_RunningData.HcuInputIndex += HCU_MAXSIZE_WRITEONCE;
        Crypto_RunningData.HcuInputControlIndex = HCU_MAXSIZE_WRITEONCE;
    }
    else if ((Tempdata > 0U) && (MSG_START == MsgType) && (CRYPTO_OPT_SINGLE_MODE == CallType))
    {
        /* mode is start and mixture and less than 31*/
        Crypto_Lld_HcuSetMsgLength(Tempdata);
        Crypto_Lld_HcuSetMsgType(MSG_ALL);
        Crypto_RunningData.HcuInputIndex += Tempdata;
        Crypto_RunningData.HcuInputControlIndex = Tempdata;
    }
    else if ((Tempdata > 0U) && (MSG_MIDDLE == MsgType) && (CRYPTO_OPT_SINGLE_MODE == CallType))
    {
        /* mode is Update and mixture and less than 31*/
        Retvl = HCU_ERRO_NOP;
    }
    else if (Tempdata > 0U)
    {
        /*message is 0,and mode is finish*/
        Crypto_Lld_HcuSetMsgLength(Tempdata);
        Crypto_Lld_HcuSetMsgType(MsgType);
        Crypto_RunningData.HcuInputIndex += Tempdata;
        Crypto_RunningData.HcuInputControlIndex = Tempdata;
    }
    else
    {
        /*message is 0,and mode is not finish*/
        Retvl = HCU_ERRO_NODATA;
    }
    return Retvl;
}

/**
 * @brief  This function loads input data into the HCU for cryptographic processing.
 *
 * @param[in] DataProcessType  The type of processing (synchronous or asynchronous).
 * @param[in] MsgIndexType     The message index type (e.g., start, middle, end).
 * @return uint8
 */
CRYPTO_FUNC uint8 Crypto_Lld_HcuSetInputData(Crypto_ProcessingType DataProcessType, Crypto_Lld_Hcu_MsgType MsgIndexType)
{
    uint8 Retvl = 0x01;
    if ((uint8)CRYPTO_PROCESSING_SYNC == (uint8)DataProcessType)
    {
        /*SYNC job*/
        Crypto_Lld_HcuWriteInputLoop(MsgIndexType);
        Retvl = 0;
    }
    else
    {
        /*ASYNC job*/
        Retvl = Crypto_Lld_HcuWriteInputSingle(MsgIndexType);
    }
    return Retvl;
}

/**
 * @brief  This function sets up the Hardware Crypto Unit (HCU) for a new operation by configuring the engine,
 * algorithm, encryption mode, and total message length. It also initializes FIFO watermarks, key, and MAC length
 * as needed for the selected operation type.
 *
 * @param[in] CallType     The type of cryptographic operation to perform (e.g., single, stream, multi).
 * @param[in] Engine       The HCU engine to use (e.g., AES, SHA).
 * @param[in] Algorithm    The cryptographic algorithm to use.
 * @param[in] Encrypt      The job mode for engine (encryption or decryption).
 * @param[in] MsgTotalLen  The total length of the message to be processed.
 * @return None
 */
CRYPTO_FUNC void Crypto_Lld_HcuStartPrepare(Crypto_OperationType CallType,
        Crypto_Lld_Hcu_EngineType Engine,
        Crypto_Lld_Hcu_AesModeType Algorithm,
        Crypto_Lld_Hcu_EngineModeType Encrypt,
        uint32 MsgTotalLen)
{
    Crypto_Lld_HcuSetEngineAlgorithm(Engine, Algorithm, Encrypt);
#if defined(HCU_SUPPORT_HASH_VERIFICATION)
    /*Configure HASH Verification*/
    Crypto_Lld_HcuSetShaVerify(FALSE);
#endif /* HCU_SUPPORT_HASH_VERIFICATION */

#if defined(HCU_SUPPORT_TOTAL_MSG_LENGTH_SET)
    /*Set input data*/
    if (CRYPTO_OPT_SINGLE_MODE == CallType)
    {
        /*if Singnal call ,write TotalLength in start mode*/
        Crypto_Lld_HcuSetMsgTotalLength(MsgTotalLen);
    }
#endif /* HCU_SUPPORT_TOTAL_MSG_LENGTH_SET */
}

/**
 * @brief This function initializes the HCU with the specified configuration.
 *
 * @param[in] Cfg The data swapping configuration to be set.
 * @return None
 */
CRYPTO_FUNC void Crypto_Lld_HcuInit(Crypto_Lld_Hcu_SwappingType Cfg)
{
    uint32 Temp;
    HCU->CR = 0x00000000;
    SchM_Enter_Crypto_CRYPTO_EXCLUSIVE_AREA_07();
    Temp = HCU->CR;
    Temp &= ~ HCU_CR_DATSWP_MASK;
    Temp |= HCU_CR_DATSWP(Cfg);
    HCU->CR = Temp;
    SchM_Exit_Crypto_CRYPTO_EXCLUSIVE_AREA_07();
}
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#ifdef __cplusplus
}
#endif

