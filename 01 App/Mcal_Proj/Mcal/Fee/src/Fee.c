/**
 * @file    Fee.c
 * @version V0.9.1
 *
 * @brief   AUTOSAR Fee module interface
 * @details API implementation for FEE driver
 *
 * @addtogroup FEE_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : Fee
 *   Dependencies         : none
 *
 *   Autosar Version      : V4.4.0
 *   Autosar Revision     : ASR_REL_4_4_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           : V0.9.1
 *
 *
 *   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
 *   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#include "Std_Types.h"
#ifdef __cplusplus
extern "C" {
#endif

/*
 * @page misra_violations MISRA-C:2012 violations list
 *
 * PRQA S 0310 Rule 11.3: A cast shall not be performed between a pointer to object type and a pointer
 *                        to a different object type.
 *
 * PRQA S 2461 Rule 14.2: A for loop shall be well-formed.
 *
 * PRQA S 2877   Dir-4.1: Run-time failures shall be minimized.
 *
 * PRQA S 2843 Rule 18.1: A pointer resulting from arithmetic on a pointer operand shall address an
 *                        element of the same array as that pointer operand
 *
 * PRQA S 3408 Rule 8.4: A compatible declaration is one which declares a compatible type for the
 *                       object or function being defined.
 */

/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Fee.h"
#include "Det.h"
#include "SchM_Fee.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_VENDOR_ID_C                      (180)
#define FEE_AR_RELEASE_MAJOR_VERSION_C       (4)
#define FEE_AR_RELEASE_MINOR_VERSION_C       (4)
#define FEE_AR_RELEASE_REVISION_VERSION_C    (0)
#define FEE_SW_MAJOR_VERSION_C               (0)
#define FEE_SW_MINOR_VERSION_C               (9)
#define FEE_SW_PATCH_VERSION_C               (1)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and FEE header file are of the same vendor */
#if (FEE_VENDOR_ID_C != FEE_VENDOR_ID)
#error "Fee.c and Fee.h have different vendor ids"
#endif

/* Check if source file and FEE header file are of the same Autosar version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION_C != FEE_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_C != FEE_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_C != FEE_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Fee.c and Fee.h are different"
#endif

/* Check if source file and FEE header file are of the same Software version */
#if ((FEE_SW_MAJOR_VERSION_C != FEE_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_C != FEE_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_C != FEE_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Fee.c and Fee.h are different"
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/
/* The Offset of flag status part in the cluster header */
#define FEE_CLUSTER_HEADER_STATUS_OFFSET     (FEE_CLUSTER_OVERHEAD - (2U * FEE_VIRTUAL_PAGE_SIZE))
/* The Offset of flag status part in the block header */
#define FEE_BLOCK_HEADER_STATUS_OFFSET      (FEE_BLOCK_OVERHEAD - (2U * FEE_VIRTUAL_PAGE_SIZE))
/* 16 bit blank data*/
#define FEE_BLANK_DATA_16BIT                (0xFFFFU)


/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/
/**
 * @brief   Configuration of cluster group set.
 */
extern const Fee_ClusterGroupType Fee_ClrGrps[FEE_NUMBER_OF_CLUSTER_GROUPS];

/**
 * @brief   Configuration of Fee blocks.
 */
extern const Fee_BlockConfigType Fee_BlockConfig[FEE_CRT_CFG_NR_OF_BLOCKS];
/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/
#define FEE_START_SEC_VAR_INIT_8
#include "Fee_MemMap.h"

FEE_VAR static boolean Fee_SwapToBePerformed = FALSE;
/**
* @brief        Internal cluster group iterator. Used by the scan and swap jobs
*               Warning: do not use it outside scan and swap functions
*                        (because it will be Out of Range)
*/
FEE_VAR static uint8 Fee_JobIntClrGrpIt = 0U;

/**
* @brief        Internal cluster iterator. Used by the scan and swap jobs
*/
FEE_VAR static uint8 Fee_JobIntClrIt = 0U;

/**
 * @brief      Fee Cancel request flag
 */
FEE_VAR static boolean Fee_CancelRequest = FALSE;
#define FEE_STOP_SEC_VAR_INIT_8
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_CLEARED_16
#include "Fee_MemMap.h"
/**
* @brief        Fee block index. Used by all Fee jobs
*/
FEE_VAR static uint16 Fee_JobBlockIndex;

/**
* @brief        Internal block iterator. Used by the swap job
*/
FEE_VAR static uint16 Fee_JobIntBlockIt;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
/**
* @brief        Used to keep the number of foreign blocks found when parsing the data flash.
*               It represents the number of elements from the Fee_ForeignBlockConfig array.
*/
FEE_VAR static uint16 Fee_ForeignBlocksNumber;
#endif

#define FEE_STOP_SEC_VAR_CLEARED_16
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"
/**
* @brief        Currently executed job (including internal one)
*/
FEE_VAR static Fee_JobType Fee_Job = FEE_JOB_DONE;

/**
* @brief        Fee job which started internal management job(s) such as swap...
*/
FEE_VAR static Fee_JobType Fee_JobIntOriginalJob = FEE_JOB_DONE;

#if ((FEE_SETMODE_API_SUPPORTED == STD_ON) || defined(__DOXYGEN__))
FEE_VAR static MemIf_ModeType Fee_Mode = MEMIF_MODE_SLOW;
#endif
/**
* @brief        Internal state of Fee module
*/
FEE_VAR static MemIf_StatusType Fee_ModuleStatus = MEMIF_UNINIT;

/**
* @brief        Result of last Fee module job
*/
FEE_VAR static MemIf_JobResultType Fee_JobResult = MEMIF_JOB_OK;

#define FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT_32
#include "Fee_MemMap.h"
/**
* @brief        Data buffer used by all jobs to store immediate data
*/
FEE_VAR static uint8 Fee_DataBuffer[FEE_DATA_BUFFER_SIZE] = {0U};

/**
* @brief        Pointer to user data buffer. Used by the read Fee jobs
*/
FEE_VAR static uint8 *Fee_JobReadDataDestPtr = (uint8 *)NULL_PTR;

/**
* @brief        Pointer to user data buffer. Used by the write Fee jobs
*/
FEE_VAR static const uint8 *Fee_JobWriteDataDestPtr = (uint8 *)NULL_PTR;
#define FEE_STOP_SEC_VAR_INIT_32
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_CLEARED_32
#include "Fee_MemMap.h"
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
/**
* @brief        Run-time information about blocks touching the Reserved Area
*/
FEE_VAR static uint32 Fee_ReservedAreaTouched[(FEE_MAX_NR_OF_BLOCKS + ((sizeof(uint32) * 8U) - 1U)) / (sizeof(uint32) * 8U)];
#endif

/**
* @brief        Fee block Offset. Used by the read Fee job
*/
FEE_VAR static Fls_LengthType Fee_JobBlockOffset;

/**
* @brief        Number of bytes to read. Used by the read Fee job
*/
FEE_VAR static Fls_LengthType Fee_JobBlockLength;

/**
* @brief        Internal flash helper address iterator. Used by the scan and
*               swap jobs
*/
FEE_VAR static Fls_AddressType Fee_JobIntAddrIt;

/**
* @brief        Internal address of current block header. Used by the swap job
*/
FEE_VAR static Fls_AddressType Fee_JobIntHdrAddr;

/**
* @brief        Internal address of current data block. Used by the swap job.
*/
FEE_VAR static Fls_AddressType Fee_JobIntDataAddr;
#define FEE_STOP_SEC_VAR_CLEARED_32
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_MemMap.h"
/**
* @brief        Run-time information of all configured Fee blocks. Contains
*               status, and data information. Used by all jobs
*/
FEE_VAR static  Fee_BlockInfoType Fee_BlockInfo[FEE_MAX_NR_OF_BLOCKS];

/**
* @brief        Run-time information of all configured cluster groups
*/
FEE_VAR static Fee_ClusterGroupInfoType Fee_ClrGrpInfo[FEE_NUMBER_OF_CLUSTER_GROUPS];

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
/**
* @brief        Used to keep the config of the foreign blocks
*/
FEE_VAR static Fee_BlockConfigType Fee_ForeignBlockConfig[FEE_MAX_NR_OF_BLOCKS - FEE_CRT_CFG_NR_OF_BLOCKS];
#endif
#define FEE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fee_MemMap.h"

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
static void Fee_SerializeBlockHdr(const Fee_BlockType *BlockHder,
                                  const Fls_AddressType TargetAddress,
                                  const Fee_BlockAssignmentType BlockAssignment,
                                  uint8 *BlockHdrPtr
                                 );
#else
static void Fee_SerializeBlockHdr(const Fee_BlockType *BlockHder,
                                  const Fls_AddressType TargetAddress,
                                  uint8 *BlockHdrPtr
                                 );
#endif

static Std_ReturnType Fee_BlankCheck(const uint8 *TargetPtr, const uint8 *const TargetEndPtr);

static Std_ReturnType Fee_DeserializeFlag(const uint8 *const TargetPtr, const uint8 FlagPattern, boolean *FlagValue);

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
static Fee_BlockStatusType Fee_DeserializeBlockHdr(Fee_BlockType *const BlockHder,
        Fls_AddressType *const TargetAddress,
        uint8 *const BlockAssignment,
        const uint8 *BlockHdrPtr
                                                  );
#else
static Fee_BlockStatusType Fee_DeserializeBlockHdr(Fee_BlockType *const BlockHder,
        Fls_AddressType *const TargetAddress,
        const uint8 *BlockHdrPtr
                                                  );
#endif

static Fee_ClusterStatusType Fee_DeserializeClusterHdr(Fee_ClusterHeaderType *ClrHdr,
        const uint8 *ClrHdrPtr
                                                      );

static void Fee_SerializeClusterHdr(const Fee_ClusterHeaderType *ClrHdr,
                                    uint8 *ClrHdrPtr
                                   );

static uint16 Fee_GetBlockIndex(const uint16 BlockNumber);

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
static uint16 Fee_GetForeignBlockIndex(const uint16 BlockNumber);

LOCAL_INLINE Fee_BlockAssignmentType Fee_GetBlockAssignment(const uint16 BlockRuntimeInfoIndex);

LOCAL_INLINE boolean Fee_IsForeignBlock(Fee_BlockAssignmentType BlockAssignment);

LOCAL_INLINE MemIf_JobResultType Fee_UpdateForeignBlockCfgInfo(uint16 *ForeignBlockIndex,
        const Fee_BlockType *BlockHder,
        Fee_BlockAssignmentType BlockAssignment
                                                              );
#endif

LOCAL_INLINE uint16 Fee_GetBlockNumber(const uint16 BlockRuntimeInfoIndex);

LOCAL_INLINE uint16 Fee_GetBlockSize(const uint16 BlockRuntimeInfoIndex);

LOCAL_INLINE uint8 Fee_GetBlockClusterGrp(const uint16 BlockRuntimeInfoIndex);

LOCAL_INLINE boolean Fee_GetBlockImmediate(const uint16 BlockRuntimeInfoIndex);

static uint16 Fee_AlignToVirtualPageSize(uint16 BlockSize);

static void Fee_CopyDataToPageBuffer(const uint8 *SourcePtr, uint8 *TargetPtr, const uint16 Length);

static void Fee_SerializeFlag(uint8 *TargetPtr, const uint8 FlagPattern);

static MemIf_JobResultType Fee_JobInternalSwapClusterVld(void);

static MemIf_JobResultType Fee_JobInternalSwapBlock(void);

static MemIf_JobResultType Fee_JobInternalSwapClusterFmt(void);

static MemIf_JobResultType Fee_JobInternalSwapClusterErase(void);

static MemIf_JobResultType Fee_JobInternalSwap(void);

static MemIf_JobResultType Fee_JobInternalScanBlockHdrRead(void);

static MemIf_JobResultType Fee_JobInternalScanClusterErase(void);

static MemIf_JobResultType Fee_JobInternalScanCluster(void);

static MemIf_JobResultType Fee_JobInternalScanClusterFmt(void);

static MemIf_JobResultType Fee_JobInternalScanCluFmtDone(void);

static MemIf_JobResultType Fee_JobInternalScanBlkHdrParse(const boolean BufferValid);

LOCAL_INLINE boolean Fee_JobInternalScanCluHdrDone(void);

static MemIf_JobResultType Fee_JobInternalScanCluHdrRead(void);

static MemIf_JobResultType Fee_JobInternalScan(void);

static MemIf_JobResultType Fee_JobInternalScanCluHdrParse(const boolean BufferValid);

static MemIf_JobResultType Fee_JobReadBlock(void);

static MemIf_JobResultType Fee_JobInternalSwapBlockVld(void);

static MemIf_JobResultType Fee_JobInternalSwapDataRead(const boolean BufferValid);

static MemIf_JobResultType Fee_JobInternalSwapDataWrite(const boolean BufferValid);

static MemIf_JobResultType Fee_JobInternalSwapCluVldDone(void);

static MemIf_JobResultType Fee_JobWriteHdr(void);

static MemIf_JobResultType Fee_JobWriteBlockData(void);

static MemIf_JobResultType Fee_JobWriteBlock(void);

static MemIf_JobResultType Fee_JobWriteBlockUnalignedData(void);

static MemIf_JobResultType Fee_JobWriteBlockValidate(void);

static MemIf_JobResultType Fee_JobWriteBlockDone(void);

static MemIf_JobResultType Fee_JobInvalidateBlock(void);

static MemIf_JobResultType Fee_JobInvalidateBlockDone(void);

static MemIf_JobResultType Fee_JobEraseImmediateBlock(void);

#if ((FEE_SETMODE_API_SUPPORTED == STD_ON) || defined(__DOXYGEN__))
static MemIf_JobResultType Fee_JobSetModeTransfer(void);
#endif

static MemIf_JobResultType Fee_JobWriteBlockHdrWait(void);

static MemIf_JobResultType Fee_JobSchedule(void);

static MemIf_JobResultType Fee_JobScheAfterSwapCluVldDone(void);

static boolean Fee_ReservedAreaWritable(void);

static void Fee_JobErrorSchedule(void);

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
LOCAL_INLINE boolean Fee_ReservedAreaTargetInClrGrp(const uint8 ClrGrpIndex);

LOCAL_INLINE uint32 Fee_PowerOf2Of5LSB(const uint32 InVal);

LOCAL_INLINE boolean Fee_ReservedAreaTouchedByBlock(const uint16 BlockNumber);

LOCAL_INLINE void Fee_TouchReservedAreaByBlock(const uint16 BlockNumber);

LOCAL_INLINE void Fee_UntouchReservedAreaByClrGrp(const uint8 ClrGrpIndex);

LOCAL_INLINE void Fee_UntouchReservedAreaAll(void);
#endif /* FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON */

LOCAL_INLINE boolean Fee_IsBlockMatchedConfig(uint16 BlockIndex,
        uint16 BlockRuntimeInfoIndex,
        const Fee_BlockType *BlockHder,
        Fls_AddressType DataAddr
                                             );

LOCAL_INLINE void Fee_UpdateBlockRuntimeInfo(uint16 BlockRuntimeInfoIndex,
        Fee_BlockStatusType BlockStatus,
        Fls_AddressType DataAddr,
        boolean ImmediateBlock
                                            );

static Std_ReturnType Fee_ReadFromFls(Fls_AddressType SourceAddress,
                                      uint8 *TargetAddressPtr,
                                      Fls_LengthType Length
                                     );

static Std_ReturnType Fee_WriteToFls(Fls_AddressType TargetAddress,
                                     const uint8 *SourceAddressPtr,
                                     Fls_LengthType Length
                                    );

static Std_ReturnType Fee_EraseCluster(uint8 ClrGrpIt,
                                       uint8 ClrIt
                                      );

LOCAL_INLINE Fls_LengthType Fee_GetClusterLength(uint8 ClrGrpIt,
        uint8 ClrIt
                                                );

LOCAL_INLINE uint8 Fee_GetNextClusterToSwap(uint8 CurrentCluster);

/*==================================================================================================
*                                       FEE JOB SCHEDULE LOOKUP TABLE AREA
==================================================================================================*/
/* Function prototypes */
LOCAL_INLINE MemIf_JobResultType Fee_JobIntalScanCluHdrParseWap(void);
LOCAL_INLINE MemIf_JobResultType Fee_JobIntalScanBlkHdrParseWap(void);
LOCAL_INLINE MemIf_JobResultType Fee_JobInternalSwapDataReadWap(void);
LOCAL_INLINE MemIf_JobResultType Fee_JobInternalSwapDataWriteWap(void);
LOCAL_INLINE MemIf_JobResultType Fee_JobSystemDone(void);
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
LOCAL_INLINE void Fee_SerializeUnit8(uint8 ParamVal, uint8 **SerialPtr);
#endif
LOCAL_INLINE void Fee_SerializeUnit16(uint16 ParamVal, uint8 **SerialPtr);
LOCAL_INLINE void Fee_SerializeUnit32(uint32 ParamVal, uint8 **SerialPtr);
LOCAL_INLINE void Fee_SerializeAddress(Fls_AddressType ParamVal, uint8 **SerialPtr);
LOCAL_INLINE void Fee_SerializeLength(Fls_LengthType ParamVal, uint8 **SerialPtr);
LOCAL_INLINE void Fee_DeserializeUint8(const uint8 **DeserialPtr, uint8 *ParamVal);
LOCAL_INLINE void Fee_DeserializeUint16(const uint8 **DeserialPtr, uint16 *ParamVal);
LOCAL_INLINE void Fee_DeserializeUint32(const uint8 **DeserialPtr, uint32 *ParamVal);
LOCAL_INLINE void Fee_DeserializeAddress(const uint8 **DeserialPtr, Fls_AddressType *ParamVal);
LOCAL_INLINE void Fee_DeserializeLength(const uint8 **DeserialPtr, Fls_LengthType *ParamVal);

#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
/**
* @brief          Serialize scalar parameter into the buffer
* @param[in]      ParamVal serialized parameter
* @param[in/out]  SerialPtr pointer to target buffer
*
*/
FEE_FUNC LOCAL_INLINE void Fee_SerializeUnit8(uint8 ParamVal, uint8 **SerialPtr)
{
    **SerialPtr = ParamVal;
    *SerialPtr = &((*SerialPtr)[sizeof(uint8)]);
}
#endif
/**
* @brief          Serialize scalar parameter into the buffer
* @param[in]      ParamVal serialized parameter
* @param[in/out]  SerialPtr pointer to target buffer
*
*/
FEE_FUNC LOCAL_INLINE void Fee_SerializeUnit16(uint16 ParamVal, uint8 **SerialPtr)
{
    /* MR12 Rule 11.3 VIOLATION: In this specific case, the SerialPtr is set to align 4 byte in the MCAL memory map,
     *                           it couldn't adhere to M3CM Rule-11.3
     */
    *((uint16 *)(*SerialPtr)) = ParamVal; /*PRQA S 0310,3305*/
    *SerialPtr = &((*SerialPtr)[sizeof(uint16)]);
}

/**
* @brief          Serialize scalar parameter into the buffer
* @param[in]      ParamVal serialized parameter
* @param[in/out]  SerialPtr pointer to target buffer
*
*/
FEE_FUNC LOCAL_INLINE void Fee_SerializeUnit32(uint32 ParamVal, uint8 **SerialPtr)
{
    /* MR12 Rule 11.3 VIOLATION: In this specific case, the SerialPtr is set to align 4 byte in the MCAL memory map,
     *                           it couldn't adhere to M3CM Rule-11.3
     */
    *((uint32 *)(*SerialPtr)) = ParamVal; /*PRQA S 0310,3305*/
    *SerialPtr = &((*SerialPtr)[sizeof(uint32)]);
}

/**
* @brief          Serialize scalar parameter into the buffer
* @param[in]      ParamVal serialized parameter
* @param[in/out]  SerialPtr pointer to target buffer
*
*/
FEE_FUNC LOCAL_INLINE void Fee_SerializeAddress(Fls_AddressType ParamVal, uint8 **SerialPtr)
{
    /* MR12 Rule 11.3 VIOLATION: In this specific case, the SerialPtr is set to align 4 byte in the MCAL memory map,
     *                           it couldn't adhere to M3CM Rule-11.3
     */
    *((Fls_AddressType *)(*SerialPtr)) = ParamVal; /*PRQA S 0310,3305*/
    *SerialPtr = &((*SerialPtr)[sizeof(Fls_AddressType)]);
}

/**
* @brief          Serialize scalar parameter into the buffer
* @param[in]      ParamVal serialized parameter
* @param[in/out]  SerialPtr pointer to target buffer
*
*/
FEE_FUNC LOCAL_INLINE void Fee_SerializeLength(Fls_LengthType ParamVal, uint8 **SerialPtr)
{
    /* MR12 Rule 11.3 VIOLATION: In this specific case, the SerialPtr is set to align 4 byte in the MCAL memory map,
     *                           it couldn't adhere to M3CM Rule-11.3
     */
    *((Fls_LengthType *)(*SerialPtr)) = ParamVal; /*PRQA S 0310,3305*/
    *SerialPtr = &((*SerialPtr)[sizeof(Fls_LengthType)]);
}

/**
* @brief          Deserialize scalar parameter from the buffer
* @param[in/out]  DeserialPtr pointer to source buffer
* @param[out]     ParamVal deserialized parameter
*
*/
FEE_FUNC LOCAL_INLINE void Fee_DeserializeUint8(const uint8 **DeserialPtr, uint8 *ParamVal)
{
    *ParamVal = *(*DeserialPtr);
    *DeserialPtr = &((*DeserialPtr)[sizeof(uint8)]);
}

/**
* @brief          Deserialize scalar parameter from the buffer
* @param[in/out]  DeserialPtr pointer to source buffer
* @param[out]     ParamVal deserialized parameter
*
*/

FEE_FUNC LOCAL_INLINE void Fee_DeserializeUint16(const uint8 **DeserialPtr, uint16 *ParamVal)
{
    /* MR12 Rule 11.3 VIOLATION: In this specific case, the DeserialPtr is set to align 4 byte in the MCAL memory map,
     *                           it couldn't adhere to M3CM Rule-11.3
     */
    *ParamVal = *((const uint16 *)(*DeserialPtr)); /*PRQA S 0310,3305*/
    *DeserialPtr = &((*DeserialPtr)[sizeof(uint16)]);
}

/**
* @brief          Deserialize scalar parameter from the buffer
* @param[in/out]  DeserialPtr pointer to source buffer
* @param[out]     ParamVal deserialized parameter
*
*/
FEE_FUNC LOCAL_INLINE void Fee_DeserializeUint32(const uint8 **DeserialPtr, uint32 *ParamVal)
{
    /* MR12 Rule 11.3 VIOLATION: In this specific case, the DeserialPtr is set to align 4 byte in the MCAL memory map,
     *                           it couldn't adhere to M3CM Rule-11.3
     */
    *ParamVal = *((const uint32 *)(*DeserialPtr)); /*PRQA S 0310,3305*/
    *DeserialPtr = &((*DeserialPtr)[sizeof(uint32)]);
}

/**
* @brief          Deserialize scalar parameter from the buffer
* @param[in/out]  DeserialPtr pointer to source buffer
* @param[out]     ParamVal deserialized parameter
*
*/
FEE_FUNC LOCAL_INLINE void Fee_DeserializeAddress(const uint8 **DeserialPtr, Fls_AddressType *ParamVal)
{
    /* MR12 Rule 11.3 VIOLATION: In this specific case, the DeserialPtr is set to align 4 byte in the MCAL memory map,
     *                           it couldn't adhere to M3CM Rule-11.3
     */
    *ParamVal = *((const Fls_AddressType *)(*DeserialPtr)); /*PRQA S 0310,3305*/
    *DeserialPtr = &((*DeserialPtr)[sizeof(Fls_AddressType)]);
}

/**
* @brief          Deserialize scalar parameter from the buffer
* @param[in/out]  DeserialPtr pointer to source buffer
* @param[out]     ParamVal deserialized parameter
*
*/
FEE_FUNC LOCAL_INLINE void Fee_DeserializeLength(const uint8 **DeserialPtr, Fls_LengthType *ParamVal)
{
    /* MR12 Rule 11.3 VIOLATION: In this specific case, the DeserialPtr is set to align 4 byte in the MCAL memory map,
     *                           it couldn't adhere to M3CM Rule-11.3
     */
    *ParamVal = *((const Fls_LengthType *)(*DeserialPtr)); /*PRQA S 0310,3305*/
    *DeserialPtr = &((*DeserialPtr)[sizeof(Fls_LengthType)]);
}
/**
* @brief    A wrapper function for Fee_JobInternalScanCluHdrParse
*
*/
FEE_FUNC LOCAL_INLINE MemIf_JobResultType Fee_JobIntalScanCluHdrParseWap(void)
{
    return Fee_JobInternalScanCluHdrParse(TRUE);
}

/**
* @brief    A wrapper function for Fee_JobInternalScanBlkHdrParse
*
*/
FEE_FUNC LOCAL_INLINE MemIf_JobResultType Fee_JobIntalScanBlkHdrParseWap(void)
{
    return Fee_JobInternalScanBlkHdrParse(TRUE);
}

/**
* @brief    A wrapper function for Fee_JobInternalSwapDataRead
*
*/
FEE_FUNC LOCAL_INLINE MemIf_JobResultType Fee_JobInternalSwapDataReadWap(void)
{
    return Fee_JobInternalSwapDataRead(TRUE);
}

/**
* @brief    A wrapper function for Fee_JobInternalSwapDataWrite
*
*/
FEE_FUNC LOCAL_INLINE MemIf_JobResultType Fee_JobInternalSwapDataWriteWap(void)
{
    return Fee_JobInternalSwapDataWrite(TRUE);
}

/**
* @brief     Fee job done
*
*/
FEE_FUNC LOCAL_INLINE MemIf_JobResultType Fee_JobSystemDone(void)
{
    return MEMIF_JOB_FAILED;
}
#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#define FEE_START_SEC_CONST_UNSPECIFIED
#include "Fee_MemMap.h"
/**
* @brief     List of Fee job functions, used by Fee_JobSchedule
*            The order of functions in this table must be identical
*            with the enumeration Fee_JobType from Fee_InternalTypes.h
*
*/
FEE_CONST static MemIf_JobResultType(* const Fee_JobScheduleLookupTable[])(void) =
{
    /* Fee_Read() related jobs */
    Fee_JobReadBlock,                                /* FEE_JOB_READ */

    /* Fee_Write() related jobs */
    Fee_JobWriteBlock,                               /* FEE_JOB_WRITE */
    Fee_JobWriteBlockData,                           /* FEE_JOB_WRITE_DATA */
    Fee_JobWriteBlockUnalignedData,                  /* FEE_JOB_WRITE_UNALIGNED_DATA */
    Fee_JobWriteBlockValidate,                       /* FEE_JOB_WRITE_VALIDATE */
    Fee_JobWriteBlockDone,                           /* FEE_JOB_WRITE_DONE */

    /* Fee_InvalidateBlock() related jobs */
    Fee_JobInvalidateBlock,                          /* FEE_JOB_INVAL_BLOCK */
    Fee_JobInvalidateBlockDone,                      /* FEE_JOB_INVAL_BLOCK_DONE */

    /* Fee_EraseImmediateBlock() related jobs */
    Fee_JobEraseImmediateBlock,                      /* FEE_JOB_ERASE_IMMEDIATE */

    /* Fee_Init() realted jobs */
    Fee_JobInternalScan,                             /* FEE_JOB_INT_SCAN */
    Fee_JobInternalScanCluster,                      /* FEE_JOB_INT_SCAN_CLR */
    Fee_JobIntalScanCluHdrParseWap,      /* FEE_JOB_INT_SCAN_CLR_HDR_PARSE */
    Fee_JobInternalScanClusterFmt,                   /* FEE_JOB_INT_SCAN_CLR_FMT */
    Fee_JobInternalScanCluFmtDone,               /* FEE_JOB_INT_SCAN_CLR_FMT_DONE */
    Fee_JobIntalScanBlkHdrParseWap,        /* FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE */

    /* Internal swap jobs */
    Fee_JobInternalSwapClusterFmt,                   /* FEE_JOB_INT_SWAP_CLR_FMT */
    Fee_JobInternalSwapBlock,                        /* FEE_JOB_INT_SWAP_BLOCK */
    Fee_JobInternalSwapDataReadWap,             /* FEE_JOB_INT_SWAP_DATA_READ */
    Fee_JobInternalSwapDataWriteWap,            /* FEE_JOB_INT_SWAP_DATA_WRITE */
    Fee_JobInternalSwapCluVldDone,               /* FEE_JOB_INT_SWAP_CLR_VLD_DONE */

    /* Fee system jobs done */
    Fee_JobSystemDone,                               /* FEE_JOB_DONE */
#if (FEE_SETMODE_API_SUPPORTED == STD_ON)
    /* Fee_Setmode() related job */
    Fee_JobSetModeTransfer,                           /* FEE_JOB_SETMODE */
#endif
    Fee_JobWriteBlockHdrWait                        /* FEE_JOB_WRITE_BLOCK_HDR */
};
#define FEE_STOP_SEC_CONST_UNSPECIFIED
#include "Fee_MemMap.h"
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define FEE_START_SEC_CODE
#include "Fee_MemMap.h"
/**
* @brief   Returns the cluster group for a block specified by its index in the Fee_BlockInfo array
* @details This function returns the cluster group for a block specified by its index in the Fee_BlockInfo array
* @param[in]      BlockRuntimeInfoIndex     index in the Fee_BlockInfo array
* @return         uint8
*/
FEE_FUNC LOCAL_INLINE uint8 Fee_GetBlockClusterGrp(const uint16 BlockRuntimeInfoIndex)
{
    uint8 BlockClusterGrp;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (BlockRuntimeInfoIndex < FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        /* this means block is not foreign, so the config is part of Fee_BlockConfig*/
        BlockClusterGrp = Fee_BlockConfig[BlockRuntimeInfoIndex].ClrGrp;
    }
    else
    {
        /* this means block is foreign, so the config is part of Fee_ForeignBlockConfig*/
        BlockClusterGrp = Fee_ForeignBlockConfig[BlockRuntimeInfoIndex - FEE_CRT_CFG_NR_OF_BLOCKS].ClrGrp;
    }
#else
    /* the config is part of Fee_BlockConfig*/
    BlockClusterGrp = Fee_BlockConfig[BlockRuntimeInfoIndex].ClrGrp;
#endif

    return BlockClusterGrp;
}

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
/**
* @brief    Check the reserved area of a cluster group
* @details  Checks whether the area specified by Fee_ClrGrpInfo[ClrGrpIndex].DataAddrIt
*              and Fee_ClrGrpInfo[ClrGrpIndex].HdrAddrIt touches the Reserved Area.
* @param[in] ClrGrpIndex - Cluster Group Index
* @return boolean
*/
FEE_FUNC LOCAL_INLINE boolean Fee_ReservedAreaTargetInClrGrp(const uint8 ClrGrpIndex)
{
    boolean RetVal;
    Fls_LengthType AvailClrSpace;
    uint32 ReservedSpace;

    /* Reserved space of cluster group*/
    ReservedSpace = Fee_ClrGrps[ ClrGrpIndex ].ReservedSize;

    /* Calculate available space in active cluster */
    AvailClrSpace = Fee_ClrGrpInfo[ ClrGrpIndex ].DataAddrIt -
                    Fee_ClrGrpInfo[ ClrGrpIndex ].HdrAddrIt;

    if ((FEE_BLOCK_OVERHEAD + ReservedSpace) > AvailClrSpace)
    {
        RetVal = TRUE;
    }
    else
    {
        RetVal = FALSE;
    }

    return RetVal;
}

/**
* @brief Function to compute the power of 2 out of the 5 LSB bits of InVal value.
* @param[in] InVal - value out of which 5 LSB bits is taken as an input for the
*                     power of 2 computation
* @return  uint32 - Power of 2 computed out of the 5 LSB bits of InVal value.
*/
FEE_FUNC LOCAL_INLINE uint32 Fee_PowerOf2Of5LSB(const uint32 InVal)
{
    return (0x00000001UL << (InVal & 0x1FUL));
}

/**
* @brief Returns the information about touching the Reserved Area by the block
*         specified by uBlockuNumber.
* @param[in] BlockNumber - number of the block under request
* @return boolean
*/
FEE_FUNC LOCAL_INLINE boolean Fee_ReservedAreaTouchedByBlock(const uint16 BlockNumber)
{
    uint32 Idx;
    boolean RetVal;

    /*The Block information is stored by 1 bit, 32 blocks will be stored in one element of Fee_ReservedAreaTouched*/
    /*Calculate index of the element that store the block information*/
    Idx = ((uint32)BlockNumber) >> 5U;
    /*Check if the bit is 1*/
    if (0U != (Fee_ReservedAreaTouched[ Idx ] & Fee_PowerOf2Of5LSB((uint32)BlockNumber)))
    {
        RetVal = TRUE;
    }
    else
    {
        RetVal = FALSE;
    }
    return RetVal;
}

/**
* @brief Stores the information about touching the Reserved Area for the block
*           specified by BlockNumber.
* @param[in] BlockNumber - number of the block touching the Reserved Area
* @return void
*
*/
FEE_FUNC LOCAL_INLINE void Fee_TouchReservedAreaByBlock(const uint16 BlockNumber)
{
    uint32 Idx;

    Idx = ((uint32)BlockNumber) >> 5U;

    if (Idx >= ((FEE_MAX_NR_OF_BLOCKS + ((sizeof(uint32) * 8U) - 1U)) / (sizeof(uint32) * 8U)))
    {
        Idx = ((FEE_MAX_NR_OF_BLOCKS + ((sizeof(uint32) * 8U) - 1U)) / (sizeof(uint32) * 8U)) - 1U;
    }

    Fee_ReservedAreaTouched[Idx] |= Fee_PowerOf2Of5LSB((uint32)BlockNumber);
}

/**
* @brief Removes the information about touching the Reserved Area for all blocks
*           within a cluster group specified by ClrGrpIndex.
*
* @param[in] ClrGrpIndex - Cluster Group Index
* @return void
*
*/
FEE_FUNC LOCAL_INLINE void Fee_UntouchReservedAreaByClrGrp(const uint8 ClrGrpIndex)
{
    uint32 Idx = 0UL;
    uint32 Mask = 0x00000001UL;
    uint8  BlockClusterGrp;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    for (uint32 BlockIt = 0U; BlockIt < ((uint32)FEE_CRT_CFG_NR_OF_BLOCKS + (uint32)Fee_ForeignBlocksNumber); ++BlockIt)
#else
    for (uint32 BlockIt = 0U; BlockIt < FEE_CRT_CFG_NR_OF_BLOCKS; ++BlockIt)
#endif
    {
        /*Get cluster group of block "BlockIt"*/
        BlockClusterGrp = Fee_GetBlockClusterGrp((uint16)BlockIt);

        /*Check if the block "BlockIt" is in ClrGrpIndex*/
        if (ClrGrpIndex == BlockClusterGrp)
        {
            /*Remove information bit of the block*/
            Fee_ReservedAreaTouched[Idx] &= (~Mask);
        }
        /*Check if the block is the last block in one element of Fee_ReservedAreaTouched*/
        if (0x80000000UL == Mask)
        {
            /*Reset Mask to the 1st bit*/
            Mask = 0x00000001UL;
            /*Move to the next element of Fee_ReservedAreaTouched*/
            Idx += 1U;
        }
        else
        {
            /*Move to next bit for next block "BlockIt+1"*/
            Mask = Mask << 1U;
        }
    }
}

/**
* @brief Removes information about touching the Reserved Area globally for all blocks.
* @return void
*
*/
FEE_FUNC LOCAL_INLINE void Fee_UntouchReservedAreaAll(void)
{
    /*MR12 Rule 4.1 VIOLATION: This loop executed times is determined by FEE_MAX_NR_OF_BLOCKS witch configured in
     *                         config tools.
     *
     */
    for (uint32 Idx = 0UL; Idx < ((FEE_MAX_NR_OF_BLOCKS + ((sizeof(uint32) * 8U) - 1U)) / (sizeof(uint32) * 8U)); ++Idx) /*PRQA S 2877*/
    {
        Fee_ReservedAreaTouched[Idx] = 0x00000000UL;
    }
}
#endif /* (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON) */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
/**
* @brief        Serialize Fee block parameters into a write buffer
*
* @param[in]    BlockHder       hder block (block number and Length)
* @param[in]    TargetAddress   Logical address of Fee block in Fls adress
* @param[in]    BlockAssignment Block assignment ,the parameter is valod when FEE_SWAP_FOREIGN_BLOCKS_ENABLED configured STD_ON
* @param[out]   BlockHdrPtr     Pointer to serialization buffer
*
* @pre          BlockHdrPtr must be valid pointer
*
*/
FEE_FUNC static void Fee_SerializeBlockHdr(const Fee_BlockType *BlockHder,
        const Fls_AddressType TargetAddress,
        const Fee_BlockAssignmentType BlockAssignment,
        uint8 *BlockHdrPtr
                                          )
#else
FEE_FUNC static void Fee_SerializeBlockHdr(const Fee_BlockType *BlockHder,
        const Fls_AddressType TargetAddress,
        uint8 *BlockHdrPtr
                                          )
#endif /* (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) */
{
    uint32 CheckSum = 0UL;
    const uint8 *TargetEndPtr;
    uint8 *TempBlockHdrPtr = BlockHdrPtr;

    TargetEndPtr = &BlockHdrPtr[FEE_BLOCK_OVERHEAD];

    /* Calculate the block header Checksum */
    CheckSum = ((uint32) BlockHder->BlockNumber) + ((uint32) BlockHder->Length) + TargetAddress;

    /* Use MSB of the Checksum for the immediate block flag so the Checksum is 31-bit */
    if (TRUE == (BlockHder->ImmediateBlock))
    {
        CheckSum += 1U;
        CheckSum |= 0x80000000U;
    }
    else
    {
        CheckSum &= 0x7fffffffU;
    }
    /*Serialize Fee block parameters into a write buffer*/
    Fee_SerializeUnit16(BlockHder->BlockNumber, &TempBlockHdrPtr);

    Fee_SerializeUnit16(BlockHder->Length, &TempBlockHdrPtr);

    Fee_SerializeAddress(TargetAddress, &TempBlockHdrPtr);

    Fee_SerializeUnit32(CheckSum, &TempBlockHdrPtr);

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    Fee_SerializeUnit8((uint8)BlockAssignment, &TempBlockHdrPtr);
#endif

    /* Fill rest of the header with the erase pattern */
    for (; TempBlockHdrPtr < TargetEndPtr; ++TempBlockHdrPtr)
    {
        *TempBlockHdrPtr = FEE_ERASED_VALUE;
    }
}

/**
* @brief          Check whether specified data buffer contains only
*                 the FEE_ERASED_VALUE value
*
* @param[in]      TargetPtr     pointer to start of the checked buffer
* @param[in]      TargetEndPtr  pointer to end + 1 of the checked buffer
*
* @return         Std_ReturnType
* @retval         E_OK           The buffer contains only erased value
* @retval         E_NOT_OK       The buffer doesn't contain only erased value
*
*/
FEE_FUNC static Std_ReturnType Fee_BlankCheck(const uint8 *TargetPtr, const uint8 *const TargetEndPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    const uint8 *TempTargetPtr = TargetPtr;

    for (; TempTargetPtr < TargetEndPtr; ++TempTargetPtr)
    {
        if (FEE_ERASED_VALUE == *TempTargetPtr)
        {
            /* Pattern match */
        }
        else
        {
            RetVal = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return RetVal;
}

/**
* @brief        Deserialize the valid or invalid flag from a read buffer
*
* @param[in]    TargetPtr       Pointer to the read buffer
* @param[in]    FlagPattern    FEE_VALIDATED_VALUE or FEE_INVALIDATED_VALUE
* @param[out]   FlagValue       TRUE if flag of above type is set
*
* @return       Std_ReturnType
* @retval       E_OK             The flag is set or cleared and rest of the read buffer
*                                (FEE_VIRTUAL_PAGE_SIZE - 1) contains FEE_ERASED_VALUE
* @retval       E_NOT_OK         Buffer doesn't contain valid flag data. It's garbled...
*
* @pre          TargetPtr and FlagValue pointers must be valid
*
*/
FEE_FUNC static Std_ReturnType Fee_DeserializeFlag(const uint8 *const TargetPtr, const uint8 FlagPattern, boolean *FlagValue)
{
    Std_ReturnType RetVal;

    if ((FlagPattern == *TargetPtr) || (FEE_ERASED_VALUE == *TargetPtr))
    {
        /* The bytePattern can be either present or not */
        if (FlagPattern == *TargetPtr)
        {
            *FlagValue = TRUE;
        }
        else
        {
            *FlagValue = FALSE;
        }

        /* Check rest of the FEE_VIRTUAL_PAGE_SIZE */
        RetVal = Fee_BlankCheck(&TargetPtr[1], &TargetPtr[FEE_VIRTUAL_PAGE_SIZE]);
    }
    else
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    return RetVal;
}

/**
* @brief        Deserialize Fee block header parameters from read buffer
*
* @param[out]   BlockHder               Fee BlockHder( Pblock number and Length)
* @param[out]   TargetAddress           Logical address of Fee block in Fls adress space
* @param[out]   BlockAssignment         Block assignment ,the parameter is valod when FEE_SWAP_FOREIGN_BLOCKS_ENABLED configured STD_ON
* @param[in]    BlockHdrPtr             Pointer to read buffer
*
* @return       Fee_BlockStatusType
* @retval       FEE_BLOCK_VALID          Fee block is valid
* @retval       FEE_BLOCK_INVALID        Fee block is invalid (has been invalidated)
* @retval       FEE_BLOCK_INCONSISTENT   Fee block is inconsistent, it may contain corrupted data...
* @retval       FEE_BLOCK_HEADER_INVALID Fee block header is invalid (garbled)
* @retval       FEE_BLOCK_HEADER_BLANK   Fee block header is filled with FEE_ERASED_VALUE
*
* @pre          BlockHdrPtr             pointer must be valid
*
*/
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
FEE_FUNC static Fee_BlockStatusType Fee_DeserializeBlockHdr(Fee_BlockType *const BlockHder,
        Fls_AddressType *const TargetAddress,
        uint8 *const BlockAssignment,
        const uint8 *BlockHdrPtr
                                                           )
#else
FEE_FUNC static Fee_BlockStatusType Fee_DeserializeBlockHdr(Fee_BlockType *const BlockHder,
        Fls_AddressType *const TargetAddress,
        const uint8 *BlockHdrPtr
                                                           )
#endif
{
    Fee_BlockStatusType RetVal = FEE_BLOCK_INVALID;
    uint32 ReadCheckSum;
    uint32 CalcCheckSum;
    const uint8 *TargetEndPtr;
    const uint8 *TempBlockHdrPtr = BlockHdrPtr;
    boolean FlagValid = FALSE;
    boolean FlagInvalid = FALSE;
    boolean RetBlankCheck = E_OK;
    boolean RetDesFlagValid = E_OK;
    boolean RetDesFlagInvalid = E_OK;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_OFF)
    uint8 ReservedSpace;
#endif

    if (E_OK == Fee_BlankCheck(BlockHdrPtr, &BlockHdrPtr[FEE_BLOCK_OVERHEAD]))
    {
        RetVal = FEE_BLOCK_HEADER_BLANK;
    }
    else
    {
        /* Check 1st part of the header */
        TargetEndPtr = &BlockHdrPtr[FEE_BLOCK_HEADER_STATUS_OFFSET];

        Fee_DeserializeUint16(&TempBlockHdrPtr, &(BlockHder->BlockNumber));

        Fee_DeserializeUint16(&TempBlockHdrPtr, &(BlockHder->Length));

        Fee_DeserializeAddress(&TempBlockHdrPtr, TargetAddress);

        Fee_DeserializeUint32(&TempBlockHdrPtr, &ReadCheckSum);

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        Fee_DeserializeUint8(&TempBlockHdrPtr, BlockAssignment);
#else
        /* BlockHdrPtr must be advanced with 1 bytes.
         * the reason is to avoid blank check for this area reserved for BlockAssignment even when
         * SWAP_FOREIGN is disabled to allow disabling SWAP_FOREIGN at production time. */
        Fee_DeserializeUint8(&TempBlockHdrPtr, &ReservedSpace);

        /* variable ReservedSpace not used */
        (void)ReservedSpace;
#endif
        /* Use MSB of Checksum for immediate block flag so
           the Checksum is 31-bit long */
        CalcCheckSum = BlockHder->Length + *TargetAddress + BlockHder->BlockNumber;

        if (0U == (ReadCheckSum & 0x80000000U))
        {
            BlockHder->ImmediateBlock = FALSE;
        }
        else
        {
            BlockHder->ImmediateBlock = TRUE;
            CalcCheckSum += 1U;
        }

        /* Ignore MSB since it's used for ImmediateBlock flag */
        RetBlankCheck = Fee_BlankCheck(TempBlockHdrPtr, TargetEndPtr);
        RetDesFlagValid = Fee_DeserializeFlag(TargetEndPtr, FEE_VALIDATED_VALUE, &FlagValid);
        RetDesFlagInvalid = Fee_DeserializeFlag(&TargetEndPtr[FEE_VIRTUAL_PAGE_SIZE], FEE_INVALIDATED_VALUE, &FlagInvalid);
        if (((ReadCheckSum & 0x7fffffffU) != (CalcCheckSum & 0x7fffffffU)) || \
                (E_OK != RetBlankCheck) || \
                (E_OK != RetDesFlagValid) || \
                (E_OK != RetDesFlagInvalid)
           )
        {
            RetVal = FEE_BLOCK_HEADER_INVALID;
        }
        else
        {
            /* Block header is valid */
            if (TRUE == FlagValid)
            {
                if (FALSE == FlagInvalid)
                {
                    RetVal = FEE_BLOCK_VALID;           /* TRUE vs FALSE */
                }
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
                else
                {
                    RetVal = FEE_BLOCK_INVALIDATED;     /* TRUE vs TRUE */
                }
#endif
            }
            else
            {
                if (FALSE == FlagInvalid)
                {
                    RetVal = FEE_BLOCK_INCONSISTENT;    /* FALSE vs FALSE */
                }
            }
        }
    }

    return RetVal;
}

/**
* @brief        Deserialize Fee cluster header parameters from read buffer
*
* @param[out]   ClrHdr                  Fee cluster header
* @param[in]    ClrHdrPtr               Pointer to read buffer
*
* @return       Fee_ClusterStatusType
* @retval       FEE_CLUSTER_VALID          Fee cluster is valid
* @retval       FEE_CLUSTER_INVALID        Fee cluster has been invalidated
* @retval       FEE_CLUSTER_INCONSISTENT   Fee cluster is inconsistent, it may
*                                          contain corrupted data
* @retval       FEE_CLUSTER_HEADER_INVALID Fee cluster header is invalid (garbled)
*
* @pre          ClrHdrPtr pointer must be valid
*
*/
FEE_FUNC static Fee_ClusterStatusType Fee_DeserializeClusterHdr(Fee_ClusterHeaderType *ClrHdr,
        const uint8 *ClrHdrPtr
                                                               )
{
    Fee_ClusterStatusType RetVal = FEE_CLUSTER_HEADER_INVALID;
    uint32 CheckSumHdr;
    uint32 CheckSumCal;
    boolean FlagValid = FALSE;
    boolean FlagInvalid = FALSE;
    boolean RetBlankCheck = E_OK;
    boolean RetDesFlagValid = E_OK;
    boolean RetDesFlagInvalid = E_OK;
    const uint8 *TargetEndPtr;
    const uint8 *TempClrHdrPtr = ClrHdrPtr;
#if (FEE_SECTOR_RETIREMENT == STD_ON)
    const uint8 *SectorsInfoPtr;
    uint16 SectorCount;
#endif

    /* Check 1st part of the header */
    TargetEndPtr = &ClrHdrPtr[FEE_CLUSTER_HEADER_STATUS_OFFSET];

    Fee_DeserializeUint32(&TempClrHdrPtr, &(ClrHdr->ClrID));

    Fee_DeserializeAddress(&TempClrHdrPtr, &(ClrHdr->StartAddr));

    Fee_DeserializeLength(&TempClrHdrPtr, &(ClrHdr->Length));

    CheckSumCal = ClrHdr->ClrID + ClrHdr->StartAddr + ClrHdr->Length;

#if (FEE_SECTOR_RETIREMENT == STD_ON)
    /* Start address sectors information */
    SectorsInfoPtr = TempClrHdrPtr;

    /* Include 2-byte of the number of sectors into the Checksum */
    Fee_DeserializeUint16(&TempClrHdrPtr, &SectorCount);
    CheckSumCal += (uint32)SectorCount;

    /* Include each byte of the sectors information into the Checksum */
    for (uint32 Index = 0U; Index < (FEE_CLUSTER_HEADER_SECTORINFO_SIZE - 2U); ++Index)
    {
        CheckSumCal += (uint32)(*TempClrHdrPtr);
        TempClrHdrPtr += 1U;
    }
#endif

    Fee_DeserializeUint32(&TempClrHdrPtr, &CheckSumHdr);
    RetBlankCheck = Fee_BlankCheck(TempClrHdrPtr, TargetEndPtr);
    RetDesFlagValid = Fee_DeserializeFlag(TargetEndPtr, FEE_VALIDATED_VALUE, &FlagValid);
    RetDesFlagInvalid = Fee_DeserializeFlag(&TargetEndPtr[FEE_VIRTUAL_PAGE_SIZE], FEE_INVALIDATED_VALUE, &FlagInvalid);
    if ((CheckSumCal != CheckSumHdr) ||
            (((Std_ReturnType)E_OK) != RetBlankCheck) ||
            (((Std_ReturnType)E_OK) != RetDesFlagValid) ||
            (((Std_ReturnType)E_OK) != RetDesFlagInvalid)
       )
    {
        /* FEE_CLUSTER_HEADER_INVALID */
    }
    else if (FALSE == FlagInvalid)
    {
        if (FALSE == FlagValid)
        {
            RetVal = FEE_CLUSTER_INCONSISTENT;
        }
        else
        {
            RetVal = FEE_CLUSTER_VALID;
        }
    }
    else
    {
        RetVal = FEE_CLUSTER_INVALID;
    }
    return RetVal;
}

/**
* @brief        Serialize        Fee cluster header parameters to write buffer
*
* @param[in]    ClrHdr          Cluster header type
* @param[out]   ClrHdrPtr       Pointer to write buffer
*
* @pre          ClrHdrPtr       pointer must be valid
*
*/
FEE_FUNC static void Fee_SerializeClusterHdr(const Fee_ClusterHeaderType *ClrHdr,
        uint8 *ClrHdrPtr
                                            )
{
    uint32 CheckSum;
    const uint8 *TargetEndPtr;
    uint8 *TempClrHdrPtr = ClrHdrPtr;

    TargetEndPtr = &ClrHdrPtr[FEE_CLUSTER_OVERHEAD];

    /* Calculate the cluster header Checksum */
    CheckSum = ClrHdr->ClrID + ClrHdr->StartAddr + ClrHdr->Length;

    /*Fee cluster header parameters to write buffer*/
    Fee_SerializeUnit32(ClrHdr->ClrID, &TempClrHdrPtr);

    Fee_SerializeAddress(ClrHdr->StartAddr, &TempClrHdrPtr);

    Fee_SerializeLength(ClrHdr->Length, &TempClrHdrPtr);

    Fee_SerializeUnit32(CheckSum, &TempClrHdrPtr);

    /* Fill rest of the header with the erase pattern */
    for (; TempClrHdrPtr < TargetEndPtr; ++TempClrHdrPtr)
    {
        *TempClrHdrPtr = FEE_ERASED_VALUE;
    }
}

/**
* @brief        Searches ordered list of Fee blocks and returns index of block
*               with matching BlockNumber
*
* @param[in]    BlockNumber             Fee block number (FeeBlockNumber)
*
* @return       uint16
* @retval       Fee block index
* @retval       0xFFFF if BlockNumber is invalid
*
*/
FEE_FUNC static uint16 Fee_GetBlockIndex(const uint16 BlockNumber)
{
    uint32 Low = 0L;
    uint32 High = (uint32)FEE_CRT_CFG_NR_OF_BLOCKS - 1U;
    uint32 Middle;
    uint16 RetVal = FEE_BLANK_DATA_16BIT;

    /*Using binary search to find the index of BlockNumber*/
    while (Low <= High)
    {
        Middle = Low + ((High - Low) / 2U);

        if (BlockNumber < Fee_BlockConfig[Middle].BlockNumber)
        {
            /*Store High for next searching*/
            /*This modification avoids the High overflow problem. When High = Low=0,
            if BlockNumber is still smaller than the value corresponding to Middle,
            High will become 0xFFFFFFFF, resulting in pointer overflow and an error*/
            if (Middle > 0)
            {
                High = Middle - 1U;
            }
            else
            {
                /*Change the value of Low so that it is greater than High, thus ending the loop.
                Use this method instead of break to avoid failure of SONAR check. */
                Low = High + 1U;
            }
        }
        else if (BlockNumber > Fee_BlockConfig[Middle].BlockNumber)
        {
            /*Store Low for next searching*/
            Low = Middle + 1U;
        }
        else
        {
            /*BlockNumber is matched, store the index and return*/
            RetVal = (uint16)Middle;
            break;
        }
    }
    /*RetVal will be FEE_BLANK_DATA_16BIT if BlockNumber is not matched with any index*/
    return RetVal;
}

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
/**
* @brief        Searches ordered list of Fee blocks and returns index of block
*               with matching BlockNumber
*
* @param[in]    BlockNumber             Fee block number (FeeBlockNumber)
*
* @return       uint16
* @retval       Fee block index
* @retval       0xFFFF if BlockNumber is invalid
*
*/
FEE_FUNC static uint16 Fee_GetForeignBlockIndex(const uint16 BlockNumber)
{
    uint16 RetVal = FEE_BLANK_DATA_16BIT;

    /*Only check when Fee_ForeignBlocksNumber large than 0*/
    if (Fee_ForeignBlocksNumber >= 1UL)
    {
        for (uint16 ForeignBlockIt = 0U; ForeignBlockIt < Fee_ForeignBlocksNumber; ++ForeignBlockIt)
        {
            if (BlockNumber == Fee_ForeignBlockConfig[ForeignBlockIt].BlockNumber)
            {
                /*Found the block, store and return*/
                RetVal = ForeignBlockIt;
                break;
            }
        }
    }

    return RetVal;
}
/**
* @brief  Returns the block project assignement for a block specified by its index in the Fee_BlockInfo array
*
* @param[in]      BlockRuntimeInfoIndex     index in the Fee_BlockInfo array
* @return         Fee_BlockAssignmentType
* @retval         FEE_PROJECT_SHARED       block is a shared block
* @retval         FEE_PROJECT_APPLICATION block is an application block
* @retval         FEE_PROJECT_BOOTLOADER block is a bootloader block
* @retval         FEE_PROJECT_RESERVED   block is a reserved block
*/
FEE_FUNC LOCAL_INLINE Fee_BlockAssignmentType Fee_GetBlockAssignment(const uint16 BlockRuntimeInfoIndex)
{
    Fee_BlockAssignmentType BlockAssignment;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (BlockRuntimeInfoIndex < FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        /* this means block is not foreign, so the config is part of Fee_BlockConfig*/
        BlockAssignment = Fee_BlockConfig[BlockRuntimeInfoIndex].BlockAssignment;
    }
    else
    {
        /* this means block is foreign, so the config is part of Fee_ForeignBlockConfig*/
        /*
         * MR12 Rule 18.1 VIOLATION: The value of BlockRuntimeInfoIndex is affirm by other functions in MCAL driver,
         *                           so it couldn't adhere to M3CM Rule-18.1.
         */
        BlockAssignment = Fee_ForeignBlockConfig[BlockRuntimeInfoIndex - FEE_CRT_CFG_NR_OF_BLOCKS].BlockAssignment; /*PRQA S 2843*/
    }
#else
    /* the config is part of Fee_BlockConfig*/
    BlockAssignment = Fee_BlockConfig[BlockRuntimeInfoIndex].BlockAssignment;
#endif

    return BlockAssignment;
}
#endif


/**
* @brief  Returns the block size for a block specified by its index in the Fee_BlockInfo array
*
* @param[in]      BlockRuntimeInfoIndex     index in the Fee_BlockInfo array
* @return         uint16
* @retval         block size
*/
FEE_FUNC LOCAL_INLINE uint16 Fee_GetBlockSize(const uint16 BlockRuntimeInfoIndex)
{
    uint16 BlockSize;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (BlockRuntimeInfoIndex < FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        /* this means block is not foreign, so the config is part of Fee_BlockConfig*/
        BlockSize = Fee_BlockConfig[BlockRuntimeInfoIndex].BlockSize;
    }
    else
    {
        /* this means block is foreign, so the config is part of Fee_ForeignBlockConfig*/
        /*
         * MR12 Rule 18.1 VIOLATION: The value of BlockRuntimeInfoIndex is affirm by other functions in MCAL driver,
         *                           so it couldn't adhere to M3CM Rule-18.1.
         */
        BlockSize = Fee_ForeignBlockConfig[BlockRuntimeInfoIndex - FEE_CRT_CFG_NR_OF_BLOCKS].BlockSize; /*PRQA S 2843*/
    }
#else
    /* the config is part of Fee_BlockConfig*/
    BlockSize = Fee_BlockConfig[BlockRuntimeInfoIndex].BlockSize;
#endif

    return BlockSize;
}
/**
* @brief  Returns the block number for a block specified by its index in the Fee_BlockInfo array
*
* @param[in]      BlockRuntimeInfoIndex     index in the Fee_BlockInfo array
* @return         uint16
* @retval         block number
*/
FEE_FUNC LOCAL_INLINE uint16 Fee_GetBlockNumber(const uint16 BlockRuntimeInfoIndex)
{
    uint16 BlockNumber = 0U;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (BlockRuntimeInfoIndex < FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        /* this means block is not foreign, so the config is part of Fee_BlockConfig*/
        BlockNumber = Fee_BlockConfig[BlockRuntimeInfoIndex].BlockNumber;
    }
    else
    {
        /* this means block is foreign, so the config is part of Fee_ForeignBlockConfig*/
        /*
         * MR12 Rule 18.1 VIOLATION: The value of BlockRuntimeInfoIndex is affirm by other functions in MCAL driver,
         *                           so it couldn't adhere to M3CM Rule-18.1.
         */
        BlockNumber = Fee_ForeignBlockConfig[BlockRuntimeInfoIndex - FEE_CRT_CFG_NR_OF_BLOCKS].BlockNumber; /*PRQA S 2843*/
    }
#else
    /* the config is part of Fee_BlockConfig*/
    BlockNumber = Fee_BlockConfig[BlockRuntimeInfoIndex].BlockNumber;
#endif

    return BlockNumber;
}
/**
* @brief  Returns the immediate attribute for a block specified by its index in the Fee_BlockInfo array
*
* @param[in]      BlockRuntimeInfoIndex     index in the Fee_BlockInfo array
* @return         boolean
* @retval         value of the immediate attribute
*/
FEE_FUNC LOCAL_INLINE boolean Fee_GetBlockImmediate(const uint16 BlockRuntimeInfoIndex)
{
    boolean Immediate;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (BlockRuntimeInfoIndex < FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        /* this means block is not foreign, so the config is part of Fee_BlockConfig*/
        Immediate = Fee_BlockConfig[BlockRuntimeInfoIndex].ImmediateData;
    }
    else
    {
        /* this means block is foreign, so the config is part of Fee_ForeignBlockConfig*/
        /*
         * MR12 Rule 18.1 VIOLATION: The value of BlockRuntimeInfoIndex is affirm by other functions in MCAL driver,
         *                           so it couldn't adhere to M3CM Rule-18.1.
         */
        Immediate = Fee_ForeignBlockConfig[BlockRuntimeInfoIndex - FEE_CRT_CFG_NR_OF_BLOCKS].ImmediateData; /*PRQA S 2843*/
    }
#else
    /* the config is part of Fee_BlockConfig*/
    Immediate = Fee_BlockConfig[BlockRuntimeInfoIndex].ImmediateData;
#endif

    return Immediate;
}
/**
* @brief        Adjusts passed size so it's integer multiple of pre-configured + FEE_VIRTUAL_PAGE_SIZE
*
* @param[in]    BlockSize        Fee block size (FeeBlockSize)
*
* @return       uint16
* @retval       Adjusted          Fee block size to integer multiple of FEE_VIRTUAL_PAGE_SIZE
*
*/
FEE_FUNC static uint16 Fee_AlignToVirtualPageSize(uint16 BlockSize)
{
    uint16 Retval = 0U;
    /* Check whether the block size is integer multiple of FEE_VIRTUAL_PAGE_SIZE */
    if (0U == (BlockSize % FEE_VIRTUAL_PAGE_SIZE))
    {
        /* block size is an integer multiple of FEE_VIRTUAL_PAGE_SIZE */
        Retval = BlockSize;
    }
    else
    {
        Retval = ((BlockSize / FEE_VIRTUAL_PAGE_SIZE) + 1U) * FEE_VIRTUAL_PAGE_SIZE;
    }

    return Retval;
}

/**
* @brief        Copy data from user to internal write buffer and fills
*               rest of the write buffer with FEE_ERASED_VALUE
*
* @param[in]    SourcePtr        Pointer to user data buffer
* @param[out]   TargetPtr        Pointer to internal write buffer
* @param[in]    Length           Number of bytes to copy
*
* @return       void
* @pre          SourcePtr and TargetPtr must be valid pointers
* @pre          Length must be <= FEE_VIRTUAL_PAGE_SIZE
*
*/
FEE_FUNC static void Fee_CopyDataToPageBuffer(const uint8 *SourcePtr, uint8 *TargetPtr, const uint16 Length)
{
    const uint8 *TargetEndPtr = &TargetPtr[Length];
    const uint8 *PageEndPtr = &TargetPtr[FEE_VIRTUAL_PAGE_SIZE];
    uint8 *TempTargetPtr = TargetPtr;
    const uint8 *TempSourcePtr = SourcePtr;

    /* Copy data to page buffer */
    for (; TempTargetPtr < TargetEndPtr; ++TempTargetPtr)
    {
        *TempTargetPtr = *TempSourcePtr;
        ++TempSourcePtr ;
    }

    /* Fill rest of the page buffer with FEE_ERASED_VALUE */
    for (; TempTargetPtr < PageEndPtr; ++TempTargetPtr)
    {
        *TempTargetPtr = FEE_ERASED_VALUE;
    }
}

/**
* @brief        Serialize validation or invalidation flag to write buffer
*
* @param[out]   TargetPtr       Pointer to write buffer
* @param[in]    FlagPattern    FEE_VALIDATED_VALUE or FEE_INVALIDATED_VALUE
*
* @return       void
* @pre          TargetPtr       must be valid pointer
*
*/
FEE_FUNC static void Fee_SerializeFlag(uint8 *TargetPtr, const uint8 FlagPattern)
{
    const uint8 *TargetEndPtr = &TargetPtr[FEE_VIRTUAL_PAGE_SIZE];
    uint8 *TempPtr = TargetPtr;

    *TempPtr = FlagPattern;
    ++TempPtr;


    for (; TempPtr < TargetEndPtr; ++TempPtr)
    {
        /*Store erase value to target address*/
        *TempPtr = FEE_ERASED_VALUE;
    }
}

/**
* @brief        Validate current Fee cluster in current Fee cluster group by
*               writing FEE_VALIDATED_VALUE into flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the write job
*
* @pre          Fee_JobIntClrGrpIt must contain index of current cluster group
* @pre          Fee_JobIntClrIt must contain index of current cluster
* @post         Schedule the FEE_JOB_INT_SWAP_CLR_VLD_DONE subsequent job
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalSwapClusterVld(void)
{
    MemIf_JobResultType RetVal;
    Fls_AddressType StartAddr;

    /* Get start address of swap cluster */
    StartAddr = Fee_ClrGrps[Fee_JobIntClrGrpIt].ClrPtr[Fee_JobIntClrIt].StartAddr;

    /* Serialize validation pattern to write buffer */
    Fee_SerializeFlag(Fee_DataBuffer, FEE_VALIDATED_VALUE);

    /* Write validation pattern to flash */
    if (((Std_ReturnType)E_OK) == Fee_WriteToFls((StartAddr + FEE_CLUSTER_OVERHEAD) - (2U * FEE_VIRTUAL_PAGE_SIZE),
            Fee_DataBuffer, FEE_VIRTUAL_PAGE_SIZE
                                                )
       )
    {
        /* Fls write job has been accepted */
        RetVal = MEMIF_JOB_PENDING;
    }
    else
    {
        /* Fls write job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;
    }

    /* Schedule subsequent Fee job */
    Fee_Job = FEE_JOB_INT_SWAP_CLR_VLD_DONE;

    return RetVal;
}

/**
* @brief        Copy next block from source to target cluster
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED Underlying Fls didn't accept the write job
*
* @pre          Fee_JobIntBlockIt       must contain index of currently swaped
*                                        Fee block
* @pre          Fee_JobBlockIndex       must contain index of Fee block which
*                                        caused the swap
* @pre          Fee_JobIntClrGrpIt      must contain index of current cluster
*                                        group
* @pre          Fee_JobIntHdrAddr       must contain valid address of Fee block
*                                        header in target cluster
*
* @post         Fee_JobIntHdrAddr is advanced on to next Fee block
* @post         Schedule the FEE_JOB_INT_SWAP_DATA_READ, FEE_JOB_INT_SWAP_BLOCK,
* or            FEE_JOB_INT_SWAP_CLR_VLD_DONE subsequent job
*
* @implements   Fee_JobInternalSwapBlock_Activity
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalSwapBlock(void)
{
    MemIf_JobResultType RetVal;
    Fls_AddressType DataAddr;
    Fee_BlockType BlockHder;
    uint16 AlignedBlockSize;
    uint8 BlockClusterGrp;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    Fee_BlockAssignmentType BlockAssignment;
#endif

    /* Find first valid or inconsistent block in same cluster group */
    /* PRQA S 2461 Rule 14.2: the Fee_JobIntBlockIt in for loop also used in function 'Fee_GetBlockClusterGrp',
     *                       so it couldn't adhere to M3CM Rule-14.2
     */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    for (; Fee_JobIntBlockIt < (FEE_CRT_CFG_NR_OF_BLOCKS + Fee_ForeignBlocksNumber); ++Fee_JobIntBlockIt) /*PRQA S 2461*/
#else
    for (; Fee_JobIntBlockIt < FEE_CRT_CFG_NR_OF_BLOCKS; ++Fee_JobIntBlockIt)  /*PRQA S 2461*/
#endif
    {
        /* get cluster group */
        BlockClusterGrp = Fee_GetBlockClusterGrp(Fee_JobIntBlockIt);
        /* process only valid and inconsistent blocks from the current cluster */
        if ((Fee_JobIntClrGrpIt == BlockClusterGrp) &&
                ((FEE_BLOCK_VALID == Fee_BlockInfo[Fee_JobIntBlockIt].BlockStatus) ||
                 (FEE_BLOCK_INCONSISTENT == Fee_BlockInfo[Fee_JobIntBlockIt].BlockStatus) ||
                 (FEE_BLOCK_INCONSISTENT_COPY == Fee_BlockInfo[Fee_JobIntBlockIt].BlockStatus)
                )
           )

        {
            break;
        }
        else
        {
            /* No match. Try next one... */
        }
    }
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if ((FEE_CRT_CFG_NR_OF_BLOCKS + Fee_ForeignBlocksNumber) == Fee_JobIntBlockIt)
#else
    if (FEE_CRT_CFG_NR_OF_BLOCKS == Fee_JobIntBlockIt)
#endif
    {
        /* No more matching blocks. Validate the cluster */
        RetVal = Fee_JobInternalSwapClusterVld();
    }
    else
    {
        BlockHder.Length = Fee_GetBlockSize(Fee_JobIntBlockIt);
        BlockHder.ImmediateBlock = Fee_GetBlockImmediate(Fee_JobIntBlockIt);
        BlockHder.BlockNumber = Fee_GetBlockNumber(Fee_JobIntBlockIt);
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        BlockAssignment = Fee_GetBlockAssignment(Fee_JobIntBlockIt);
#endif

        /* Data space no more allocated even for inconsistent immediate (pre-erased) blocks */
        /*
         * MR12 Rule 18.1 VIOLATION: The value of Fee_JobIntBlockIt is affirm by other functions in MCAL driver,
         *                           so it couldn't adhere to M3CM Rule-18.1.
         */
        if (FEE_BLOCK_VALID == Fee_BlockInfo[Fee_JobIntBlockIt].BlockStatus) /*PRQA S 2843*/
        {
            /* Align Fee block size to the virtual page boundary */
            AlignedBlockSize = Fee_AlignToVirtualPageSize(BlockHder.Length);

            /* Calculate data address */
            DataAddr = Fee_JobIntDataAddr - AlignedBlockSize;

            /* Update the block address info */
            Fee_JobIntDataAddr = DataAddr;

            /* Initialize the data transfer iterator */
            Fee_JobIntAddrIt = DataAddr;
        }
        else
        {
            /* Don't allocate data space for inconsistent block */
            DataAddr = 0U;
        }

        /* Serialize block header to the write buffer */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        Fee_SerializeBlockHdr(&BlockHder, DataAddr,
                              BlockAssignment,
                              Fee_DataBuffer
                             );
#else
        Fee_SerializeBlockHdr(&BlockHder, DataAddr,
                              Fee_DataBuffer
                             );
#endif

        if (FEE_BLOCK_VALID == Fee_BlockInfo[Fee_JobIntBlockIt].BlockStatus)
        {
            /* Read block data */
            Fee_Job = FEE_JOB_INT_SWAP_DATA_READ;
        }
        else
        {
            /* Nothing to read. Move on to next block */
            Fee_JobIntBlockIt += 1U;
            Fee_Job = FEE_JOB_INT_SWAP_BLOCK;
        }

        /* Write header to flash */
        if (((Std_ReturnType)E_OK) != Fee_WriteToFls(Fee_JobIntHdrAddr, Fee_DataBuffer, FEE_BLOCK_OVERHEAD - (2U * FEE_VIRTUAL_PAGE_SIZE)))
        {
            /* Fls write job hasn't been accepted */
            RetVal = MEMIF_JOB_FAILED;
        }
        else
        {
            /* Fls write job has been accepted */
            RetVal = MEMIF_JOB_PENDING;
        }

        /* Move on to next block header */
        Fee_JobIntHdrAddr += FEE_BLOCK_OVERHEAD;
    }

    return RetVal;
}

/**
* @brief        Format current Fee cluster in current Fee cluster group by
*               writing cluster header into flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the write job
*
* @pre          Fee_JobIntClrGrpIt      must contain index of current cluster group
* @pre          Fee_JobIntClrIt         must contain index of current cluster
* @post         Schedule the FEE_JOB_INT_SWAP_BLOCK subsequent job
*
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalSwapClusterFmt(void)
{
    MemIf_JobResultType RetVal;
    Fee_ClusterHeaderType ClrHdr;
    Fls_LengthType ClusterLength;

    ClusterLength = Fee_GetClusterLength(Fee_JobIntClrGrpIt, Fee_JobIntClrIt);

    ClrHdr.StartAddr = Fee_ClrGrps[Fee_JobIntClrGrpIt].ClrPtr[Fee_JobIntClrIt].StartAddr;
    ClrHdr.Length = ClusterLength;
    ClrHdr.ClrID = Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].ActClrID + 1U;

#if (FEE_SECTOR_RETIREMENT == STD_ON)
    ClrHdr.ClrInfo = &(Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].ClrInfo[Fee_JobIntClrIt]);
#endif

    /* Build cluster header with new ActClrID + 1 */
    Fee_SerializeClusterHdr(&ClrHdr, Fee_DataBuffer);

    /* Write the cluster header to flash */
    if (((Std_ReturnType)E_OK) == Fee_WriteToFls(ClrHdr.StartAddr, Fee_DataBuffer, FEE_CLUSTER_OVERHEAD - (2U * FEE_VIRTUAL_PAGE_SIZE)))
    {
        /* Fls read job has been accepted */
        RetVal = MEMIF_JOB_PENDING;
    }
    else
    {
        /* Fls write job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;
    }

    /* Calculate header address: Move on to the first block header */
    Fee_JobIntHdrAddr = ClrHdr.StartAddr + FEE_CLUSTER_OVERHEAD;

    /* Calculate data address: Move on to the end of cluster */
    Fee_JobIntDataAddr = ClrHdr.StartAddr + ClrHdr.Length;

    /* Reset the block iterator */
    Fee_JobIntBlockIt = 0U;

    /* Schedule cluster format done job */
    Fee_Job = FEE_JOB_INT_SWAP_BLOCK;
    return RetVal;
}

/**
* @brief        Erase current Fee cluster in current Fee cluster group by erasing flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase job
*
* @pre          Fee_JobIntClrGrpIt      must contain index of current cluster group
* @pre          Fee_JobIntClrIt         must contain index of current cluster
* @post         Schedule the FEE_JOB_INT_SWAP_CLR_FMT subsequent job
*
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalSwapClusterErase(void)
{
    MemIf_JobResultType RetVal;

    /* Erase cluster */
    if (((Std_ReturnType)E_OK) == Fee_EraseCluster(Fee_JobIntClrGrpIt, Fee_JobIntClrIt))
    {
        /* Fls read job has been accepted */
        RetVal = MEMIF_JOB_PENDING;
    }
    else
    {
        /* Fls read job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;
    }

    /* Schedule cluster format job */
    Fee_Job = FEE_JOB_INT_SWAP_CLR_FMT;

    return RetVal;
}

/**
* @brief        Calculate the index of the next cluster in current cluster group.
*               In sector retirement mode, find the next good cluster with Length greater than zero.
*
* @return       The index of the next cluster to be erased in the group
*/
FEE_FUNC LOCAL_INLINE uint8 Fee_GetNextClusterToSwap(uint8 CurrentCluster)
{
    uint8 NextCluster = CurrentCluster;

    /* Calculate index of cluster to swap to */
    NextCluster += 1U;

    if (NextCluster == Fee_ClrGrps[Fee_JobIntClrGrpIt].ClrCount)
    {
        /* Cluster roll over */
        NextCluster = 0U;
    }

    return NextCluster;
}

/**
* @brief        Initialize the cluster swap internal operation on
*               current cluster group
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase job,
*                                        or the current Fee group does not have enough clusters to swap in sector retirement mode
*
* @pre          Fee_JobIntClrGrpIt      must contain index of current cluster group
* @pre          Fee_Job                 must contain type of Fee job which caused the cluster swap
*
* @post         Fee module status is set to MEMIF_BUSY_INTERNAL
* @post         Fee_Job is stored in Fee_JobIntOriginalJob so it can be rescheduled
*               once the swap operation is finished
* @post         Fee internal block iterator Fee_JobIntBlockIt is set to zero
* @post         Fee internal cluster iterator Fee_JobIntClrIt is set to
*               the target cluster
* @post         Fee_JobIntHdrAddr and Fee_JobIntDataAddr addresses are initialized to
*               point to the target cluster
* @post         Schedule erase of the target cluster
*
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalSwap(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_FAILED;
    uint8 CurrentCluster;
    uint8 NextCluster;

    /* Get cluster index the block belongs to */
    CurrentCluster = Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].ActClr;
    /* Get the next cluster to erase */
    NextCluster = Fee_GetNextClusterToSwap(CurrentCluster);

    /* Save index of cluster to swap to */
    Fee_JobIntClrIt = NextCluster;

    /* Store type of original job so Fee can re-schedule
           this job once the swap is complete */
    Fee_JobIntOriginalJob = Fee_Job;

    /* Erase the swap cluster */
    RetVal = Fee_JobInternalSwapClusterErase();

    return RetVal;
}

/**
* @brief        Read the Fee block header into internal buffer
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED Underlying Fls didn't accept the read job
*
* @pre          Fee_JobIntAddrIt must contain valid logical address of
*               Fee block header to read
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_PARSE subsequent job
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalScanBlockHdrRead(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;

    /* Read the block header */
    if (((Std_ReturnType)E_OK) != Fee_ReadFromFls(Fee_JobIntAddrIt, Fee_DataBuffer, FEE_BLOCK_OVERHEAD))
    {
        /* Fls read job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;
    }
    else
    {
        /* Fls read job has been accepted */
        RetVal = MEMIF_JOB_PENDING;
    }

    Fee_Job = FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE;

    return RetVal;
}

/**
* @brief        Erase first Fee cluster in current cluster group
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase
*                                        job
*
* @pre          Fee_JobIntClrGrpIt must contain index of current Fee cluster
*               group
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_FMT subsequent job
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalScanClusterErase(void)
{
    MemIf_JobResultType RetVal;

    /* Erase first cluster in the current cluster group */
    if (((Std_ReturnType)E_OK) == Fee_EraseCluster(Fee_JobIntClrGrpIt, Fee_JobIntClrIt))
    {
        /* Fls read job has been accepted */
        RetVal = MEMIF_JOB_PENDING;
    }
    else
    {
        /* Fls read job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;
    }

    /* Schedule cluster format job */
    Fee_Job = FEE_JOB_INT_SCAN_CLR_FMT;

    return RetVal;
}

/**
* @brief        Scan active cluster of current cluster group or erase and format
*               first cluster if an active cluster can't be found
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase or read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase or read job
* @retval       MEMIF_JOB_OK             There is no more cluster groups to scan
*
* @pre          Fee_JobIntClrGrpIt must contain index of current Fee cluster group
* @post         Initialize the Fee_JobIntAddrIt iterator to address of
*               the first Fee block header to scan
* @post         Initialize the HdrAddrIt and DataAddrIt iterators to addresses of
*               the first Fee block header and data block
* @post         Schedule the FEE_JOB_DONE, FEE_JOB_INT_SCAN_CLR_FMT,
*               FEE_JOB_INT_SCAN_CLR_PARSE subsequent job
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalScanCluster(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;
    uint8 ClrIndex;
    Fls_AddressType ClrStartAddr;
    Fls_LengthType ClrLength;

    if (FEE_NUMBER_OF_CLUSTER_GROUPS == Fee_JobIntClrGrpIt)
    {
        /* Nor more cluster groups to scan */
        Fee_Job = FEE_JOB_DONE;
    }
    else
    {
        if (0U == Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].ActClrID)
        {
            /* call the cluster format notification */
#ifdef FEE_NVM_CLUSTER_FORMAT_NOTIFICATION
            FEE_NVM_CLUSTER_FORMAT_NOTIFICATION;
#endif
            /* No active cluster found in current group so erase and format the first one... */
            Fee_JobIntClrIt = 0U;
            RetVal = Fee_JobInternalScanClusterErase();
        }
        else
        {
            /* Active cluster found */
            /* Get index of active cluster */
            ClrIndex = Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].ActClr;

            ClrStartAddr = Fee_ClrGrps[Fee_JobIntClrGrpIt].ClrPtr[ClrIndex].StartAddr;

            /* Calculate logical address of first block header in active cluster */
            Fee_JobIntAddrIt = FEE_CLUSTER_OVERHEAD + ClrStartAddr;

            /* Initialize the block header pointer */
            Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].HdrAddrIt = Fee_JobIntAddrIt;

            /* Initialize the block data pointer */
            ClrLength = Fee_GetClusterLength(Fee_JobIntClrGrpIt, ClrIndex);
            Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].DataAddrIt = ClrStartAddr + ClrLength;

            /* Active cluster found so read the first block header */
            RetVal = Fee_JobInternalScanBlockHdrRead();
        }
    }

    return RetVal;
}

/**
* @brief        Format first Fee cluster in current Fee cluster group by writing
*               cluster header into flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase job
*
* @pre          Fee_JobIntClrGrpIt must contain index of current Fee cluster group
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_FMT_DONE subsequent job
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalScanClusterFmt(void)
{
    MemIf_JobResultType RetVal;
    Fee_ClusterHeaderType ClrHdr;
    Fls_LengthType ClusterLength;

    ClusterLength = Fee_GetClusterLength(Fee_JobIntClrGrpIt, Fee_JobIntClrIt);

    /* Get address and size of first cluster in the current cluster group */
    ClrHdr.StartAddr = Fee_ClrGrps[Fee_JobIntClrGrpIt].ClrPtr[Fee_JobIntClrIt].StartAddr;
    ClrHdr.Length = ClusterLength;
    ClrHdr.ClrID = 1U;

    /* Build cluster header with clusterID = 1 */
    Fee_SerializeClusterHdr(&ClrHdr, Fee_DataBuffer);

    /* Make the cluster valid right away as it's empty anyway... */
    Fee_SerializeFlag(&Fee_DataBuffer[FEE_CLUSTER_HEADER_STATUS_OFFSET], FEE_VALIDATED_VALUE);

    /* Write the cluster header to flash */
    if (((Std_ReturnType)E_OK) == Fee_WriteToFls(ClrHdr.StartAddr, Fee_DataBuffer, FEE_CLUSTER_OVERHEAD - FEE_VIRTUAL_PAGE_SIZE))
    {
        /* Fls read job has been accepted */
        RetVal = MEMIF_JOB_PENDING;
    }
    else
    {
        /* Fls write job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;
    }

    /* Schedule cluster format done job */
    Fee_Job = FEE_JOB_INT_SCAN_CLR_FMT_DONE;

    return RetVal;
}

/**
* @brief        Finalize format of first Fee cluster in current Fee cluster group
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase or
*                                        read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase
*                                        or read job
* @retval       MEMIF_JOB_OK             There is no more cluster groups to scan
*
* @pre          Fee_JobIntClrGrpIt must contain index of current Fee cluster
*               group
* @post         Assign index (ActClr) and ID (ActClrID) of active cluster in
*               current cluster group
* @post         Initialize the HdrAddrIt and DataAddrIt iterators to addresses
*               of the first Fee block header and data block
* @post         Advance the Fee_JobIntClrGrpIt iterator to next cluster group
* @post         Schedule the FEE_JOB_DONE, FEE_JOB_INT_SCAN_CLR_FMT,
*               FEE_JOB_INT_SCAN_CLR_PARSE subsequent job
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalScanCluFmtDone(void)
{
    MemIf_JobResultType RetVal;
    Fls_AddressType ClrStartAddr;
    Fls_LengthType ClrLength;

    /* Assign Index and ID of active cluster */
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].ActClr = Fee_JobIntClrIt;
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].ActClrID = 1U;

    ClrStartAddr = Fee_ClrGrps[Fee_JobIntClrGrpIt].ClrPtr[Fee_JobIntClrIt].StartAddr;
    ClrLength = Fee_GetClusterLength(Fee_JobIntClrGrpIt, Fee_JobIntClrIt);

    /* Initialize the block header pointer */
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].HdrAddrIt = ClrStartAddr + FEE_CLUSTER_OVERHEAD;

    /* Initialize the block data pointer */
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].DataAddrIt = ClrStartAddr + ClrLength;

    /* Move on to next cluster group */
    Fee_JobIntClrGrpIt += 1U;

    /* Scan next cluster group if any */
    RetVal = Fee_JobInternalScanCluster();

    return RetVal;
}

/**
* @brief        Check the block's size and type match the configuration,
*               and its data pointer points to an acceptable area
* @param[in]    BlockIndex          Index of the block in the configuration
* @param[in]    BlockRuntimeInfoIndex Index of the block in the runtime info
* @param[in]    BlockHder           Pointer to the block header
* @param[in]    DataAddr            Address of the block data
* @return       boolean
* @retval       TRUE                Block's size and type match the configuration
*                                   and its data pointer points to an acceptable
*                                   area
* @retval       FALSE               Block's size and type don't match the
*                                   configuration or its data pointer doesn't
*                                   point to an acceptable area
*/
FEE_FUNC LOCAL_INLINE boolean Fee_IsBlockMatchedConfig(uint16 BlockIndex,
        uint16 BlockRuntimeInfoIndex,
        const Fee_BlockType *BlockHder,
        Fls_AddressType DataAddr
                                                      )
{
    boolean RetVal = TRUE;
    uint16 AlignedBlockSize;

    if ((BlockIndex != FEE_BLANK_DATA_16BIT) || (BlockRuntimeInfoIndex != FEE_BLANK_DATA_16BIT))
    {
        AlignedBlockSize = Fee_AlignToVirtualPageSize(BlockHder->Length);

        if ((DataAddr <= (Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].DataAddrIt - AlignedBlockSize)) &&
                (DataAddr >= (Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].HdrAddrIt + (2U * FEE_BLOCK_OVERHEAD))))
        {
            if ((FEE_BLANK_DATA_16BIT == BlockRuntimeInfoIndex) && \
                    ((Fee_BlockConfig[BlockIndex].ClrGrp != Fee_JobIntClrGrpIt) ||
                     (Fee_BlockConfig[BlockIndex].BlockSize != BlockHder->Length) ||
                     (Fee_BlockConfig[BlockIndex].ImmediateData != BlockHder->ImmediateBlock))
               )
            {
                /* Not matched with the configuration */
                RetVal = FALSE;
            }
        }
        else
        {
            /* Invalid area */
            RetVal = FALSE;
        }
    }
    else
    {
        /* Both indexes are FFFF: Invalid block number */
        RetVal = FALSE;
    }

    return RetVal;
}

/**
* @brief        Update block run-time information
* @param[in]    BlockRuntimeInfoIndex Index of the block in the runtime info
* @param[in]    BlockStatus          Status of the block
* @param[in]    DataAddr             Address of the block data
* @param[in]    ImmediateBlock       TRUE if the block contains immediate data
* @return       void
*
*/
FEE_FUNC LOCAL_INLINE void Fee_UpdateBlockRuntimeInfo(uint16 BlockRuntimeInfoIndex,
        Fee_BlockStatusType BlockStatus,
        Fls_AddressType DataAddr,
        boolean ImmediateBlock
                                                     )
{
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)

    /* Update block run-time information when:
     - new valid block is found
     - block was invalidated
     - block contains immediate data (basically just ignore INCONSISTENT non-immediate blocks) */

    if (FEE_BLOCK_INCONSISTENT != BlockStatus)
    {
        /* Mark invalidated blocks as invalid */
        if (FEE_BLOCK_INVALIDATED == BlockStatus)
        {
            Fee_BlockInfo[BlockRuntimeInfoIndex].BlockStatus = FEE_BLOCK_INVALID;
        }
        else
        {
            Fee_BlockInfo[BlockRuntimeInfoIndex].BlockStatus = BlockStatus;
        }

        /* Update the block data pointer */
        Fee_BlockInfo[BlockRuntimeInfoIndex].DataAddr = DataAddr;
        Fee_BlockInfo[BlockRuntimeInfoIndex].InvalidAddr = (Fee_JobIntAddrIt + FEE_BLOCK_OVERHEAD) - FEE_VIRTUAL_PAGE_SIZE;
        Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].DataAddrIt = DataAddr;

    }
    else
    {
        /* header is valid but data is corrupted, in this case it is important to update
           DataAddrIt to avoid corrupted space, cluster swap is not needed */
        Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].DataAddrIt = DataAddr;
    }

    /* Check for blocks potentially overlapping the Reserved Area */

    /* Let Fee_ClrGrpInfo[Fee_JobIntClrGrpIt] be completely updated before calling Fee_ReservedAreaTargetInClrGrp() */
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].HdrAddrIt = Fee_JobIntAddrIt + FEE_BLOCK_OVERHEAD;

    if (FALSE != Fee_ReservedAreaTargetInClrGrp(Fee_JobIntClrGrpIt))
    {
        if (TRUE == ImmediateBlock)
        {
            /* Mark the imm. block as touching the Reserved Area (we are esp.
               interested only about inconsistent imm. blocks here, but it does not
               matter if also consistent imm. block will be marked) */
            Fee_TouchReservedAreaByBlock(BlockRuntimeInfoIndex);

        }
        else
        {
            /* Non-immediate data found in the Reserved Area => swap */
            Fee_SwapToBePerformed = TRUE;
            /* Fee_SwapToBePerformed is not reset to FALSE upon recognition of the next written header =>
               the swap is mandatory. */
        }
    }

#else
    /* FEE_BLOCK_ALWAYS_AVAILABLE mode is off, just update block run-time information */
    /* No special treatment of immediate data and overlapping the Reserved Area needed any more */
    (void)ImmediateBlock;

    Fee_BlockInfo[BlockRuntimeInfoIndex].BlockStatus = BlockStatus;
    /* Update the block data pointer */
    Fee_BlockInfo[BlockRuntimeInfoIndex].DataAddr = DataAddr;
    Fee_BlockInfo[BlockRuntimeInfoIndex].InvalidAddr = (Fee_JobIntAddrIt + FEE_BLOCK_OVERHEAD) - FEE_VIRTUAL_PAGE_SIZE;
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].DataAddrIt = DataAddr;

#endif /* FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON */
}

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
/**
* @brief        Check if the block is foreign or not
* @param[in]    BlockAssignment      Project assignment of the block
* @return       boolean
* @retval      TRUE                 The block is foreign
* @retval      FALSE                The block is not foreign
*
*/
FEE_FUNC LOCAL_INLINE boolean Fee_IsForeignBlock(Fee_BlockAssignmentType BlockAssignment)
{
    boolean Ret = FALSE;
    /* Check if the block is foreign or not */
#if (FEE_BOOTLOADER_CONFIG == STD_ON)
    if (FEE_PROJECT_APPLICATION == BlockAssignment)
    {
        Ret = TRUE;
    }
    else
    {
        /*Nothing to do*/
    }
    return Ret;
#else
    if (FEE_PROJECT_BOOTLOADER == BlockAssignment)
    {
        Ret = TRUE;
    }
    else
    {
        /*Nothing to do*/
    }
    return Ret;
#endif
}

/**
* @brief        Update foreign block configuration information
* @param[out]   ForeignBlockIndex    Index of the foreign block in the foreign block config
* @param[in]    BlockHder            Pointer to the block header
* @param[in]    BlockAssignment      Project assignment of the block
* @return       MemIf_JobResultType
* @retval      MEMIF_JOB_OK         The operation was successful
* @retval      MEMIF_JOB_FAILED     The operation failed
*
*/
FEE_FUNC LOCAL_INLINE MemIf_JobResultType Fee_UpdateForeignBlockCfgInfo(uint16 *ForeignBlockIndex,
        const Fee_BlockType *BlockHder,
        Fee_BlockAssignmentType BlockAssignment
                                                                       )
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;
    uint16 BlockIndex = *ForeignBlockIndex;

    if (FEE_BLANK_DATA_16BIT == BlockIndex)
    {
        /* it's a new foreign block */
        if (Fee_ForeignBlocksNumber < (FEE_MAX_NR_OF_BLOCKS - FEE_CRT_CFG_NR_OF_BLOCKS))
        {
            /* update the foreign block index */
            BlockIndex = Fee_ForeignBlocksNumber;
            *ForeignBlockIndex = BlockIndex;

            /* update the foreign block config */
            Fee_ForeignBlockConfig[BlockIndex].ClrGrp          = Fee_JobIntClrGrpIt;
            Fee_ForeignBlockConfig[BlockIndex].BlockSize       = BlockHder->Length;
            Fee_ForeignBlockConfig[BlockIndex].BlockNumber     = BlockHder->BlockNumber;
            Fee_ForeignBlockConfig[BlockIndex].ImmediateData   = BlockHder->ImmediateBlock;
            Fee_ForeignBlockConfig[BlockIndex].BlockAssignment = BlockAssignment;
            /* increment the number of foreign blocks */
            Fee_ForeignBlocksNumber += 1U;
        }
        else
        {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_WRITE, FEE_E_FOREIGN_BLOCKS_OVF);
#endif
            /* Call job error notification function */
#ifdef FEE_NVM_JOB_ERROR_NOTIFICATION
            FEE_NVM_JOB_ERROR_NOTIFICATION;
#endif
            /* Foreign block overflow, set job failed */
            RetVal = MEMIF_JOB_FAILED;
        }
    }

    return RetVal;
}
#endif /* FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON */

/**
* @brief        Parse Fee block header
*
* @param[in]    BufferValid             FALSE if previous Fls read job has failed
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase or
*                                        read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase
*                                        or read job
* @retval       MEMIF_JOB_OK             There is no more cluster groups to scan
*
* @pre          Fee_JobIntClrGrpIt      must contain index of current Fee
*                                        cluster group
*
* @post         Initialize internal recovery swap operation in case of bogus
*               Fee block header or failure of previous read job (perhaps ECC failure..)
* @post         Advance the Fee_JobIntClrGrpIt iterator to next cluster group in
*               case of blank Fee block header (end of header list)
* @post         Update the BlockStatus, DataAddr, and InvalidAddr block
*               information and the HdrAddrIt and DataAddrIt iterators in case of valid
*               Fee block header
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_PARSE subsequent job in case
*               of valid Fee block header
*
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalScanBlkHdrParse(const boolean BufferValid)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;
    Fee_BlockStatusType BlockStatus;
    Fee_BlockType BlockHder;
    Fls_AddressType DataAddr;
    uint16 BlockIndex;
    uint16 BlockRuntimeInfoIndex = FEE_BLANK_DATA_16BIT;  /* Default value: invalid block number */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    Fee_BlockAssignmentType BlockAssignment = FEE_PROJECT_RESERVED;
    uint16 ForeignBlockIndex;
#endif

    /* Deserialize block header from read buffer */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    BlockStatus = Fee_DeserializeBlockHdr(&BlockHder, &DataAddr,
                                          (uint8 *)&BlockAssignment,
                                          Fee_DataBuffer
                                         );
#else
    BlockStatus = Fee_DeserializeBlockHdr(&BlockHder, &DataAddr,
                                          Fee_DataBuffer
                                         );
#endif


    /* Fee_SwapToBePerformed was set because previously processed block wasn't properly recognized.
       => perform a swap to prevent a risk that this block overlaps the Reserved Area. */
    if ((FEE_BLOCK_HEADER_INVALID  == BlockStatus) || (FALSE == BufferValid))
    {
        /* Invalidate the block index so Fee won't skip the Fee_JobBlockIndex block */
        Fee_JobBlockIndex = FEE_BLANK_DATA_16BIT;

        /* Move on to next block header */
        Fee_JobIntAddrIt += FEE_BLOCK_OVERHEAD;

        /* Update the block header pointer */
        Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].HdrAddrIt = Fee_JobIntAddrIt;

        /* Set swap-to-be-performed flag */
        Fee_SwapToBePerformed = TRUE;

        /* Read next header */
        RetVal = Fee_JobInternalScanBlockHdrRead();

    }
    else if (FEE_BLOCK_HEADER_BLANK == BlockStatus)
    {
        /* If SwapToBePerformed is set, it means that last header is corrupted and
           ONLY now the DataAddrIt variable will be updated to cause swap. */
        if (TRUE == Fee_SwapToBePerformed)
        {
            Fee_SwapToBePerformed = FALSE;
            Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].DataAddrIt = Fee_JobIntAddrIt + (2U * FEE_BLOCK_OVERHEAD);
        }

        /* End of header list so move on to next cluster group */
        Fee_JobIntClrGrpIt += 1U;

        RetVal = Fee_JobInternalScanCluster();
    }
    else
    {
        /* Look for found block in the block configuration */
        BlockIndex = Fee_GetBlockIndex(BlockHder.BlockNumber);

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        /* Check if block was not found in the configuration and it is a foreign block */
        if ((FEE_BLANK_DATA_16BIT == BlockIndex) && (TRUE == Fee_IsForeignBlock(BlockAssignment)))
        {
            /* search for block index in the foreign blocks config */
            ForeignBlockIndex = Fee_GetForeignBlockIndex(BlockHder.BlockNumber);
            /* Check and update foreign block configuration information */
            /* Set job as failed in case of foreign block overflow */
            RetVal = Fee_UpdateForeignBlockCfgInfo(&ForeignBlockIndex, &BlockHder, BlockAssignment);
            /* Found a foreign block: Prepare index to be used for the runtime info data */
            BlockRuntimeInfoIndex = FEE_CRT_CFG_NR_OF_BLOCKS + ForeignBlockIndex;
        }
#endif

        if (MEMIF_JOB_OK == RetVal)
        {
            /* If block header matches Fee config and its data pointer is in an acceptable area: update its runtime info */
            if (TRUE == Fee_IsBlockMatchedConfig(BlockIndex, BlockRuntimeInfoIndex, &BlockHder, DataAddr))
            {
                /* No foreign blocks found, use the index from our configuration */
                if (FEE_BLANK_DATA_16BIT == BlockRuntimeInfoIndex)
                {
                    BlockRuntimeInfoIndex = BlockIndex;
                }
                Fee_UpdateBlockRuntimeInfo(BlockRuntimeInfoIndex, BlockStatus, DataAddr, BlockHder.ImmediateBlock);
            }
            else
            {
                /* 1. Invalid block number (removed from Fee config...) next write cluster swap occurs. Or */
                /* 2. Block header doesn't match Fee config or the FEE algorithm... during next write cluster swap occurs */
                Fee_SwapToBePerformed = TRUE;
            }

            /* Move on to next block header */
            Fee_JobIntAddrIt += FEE_BLOCK_OVERHEAD;

            /* Update the block header pointer */
            Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].HdrAddrIt = Fee_JobIntAddrIt;

            /* Read next header */
            RetVal = Fee_JobInternalScanBlockHdrRead();
        }
    }

    return RetVal;
}

/**
* @brief        Read Fee cluster header
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept read job
*
* @pre          Fee_JobIntClrGrpIt must contain index of current Fee cluster group
* @pre          Fee_JobIntClrIt must contain index of current Fee cluster
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_HDR_PARSE subsequent job
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalScanCluHdrRead(void)
{
    MemIf_JobResultType RetVal;
    Fls_AddressType ReadAddress;


    /* Get address of current cluster */
    ReadAddress = Fee_ClrGrps[Fee_JobIntClrGrpIt].ClrPtr[Fee_JobIntClrIt].StartAddr;

    /* Cluster header will be read directly from logical address, don't need translation here */
    if (((Std_ReturnType)E_OK) != Fls_Read(ReadAddress, Fee_DataBuffer, FEE_CLUSTER_OVERHEAD))
    {
        /* Fls read job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;
    }
    else
    {
        /* Fls read job has been accepted */
        RetVal = MEMIF_JOB_PENDING;
    }

    /* Schedule cluster scan job */
    Fee_Job = FEE_JOB_INT_SCAN_CLR_HDR_PARSE;

    return RetVal;
}


/**
* @brief        Initialize the cluster scan job
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept read job
*
* @post         Reset the Fee_JobIntClrGrpIt and Fee_JobIntClrIt iterators
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_HDR_PARSE subsequent job
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalScan(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;

    /* Reset iterators to first cluster of first cluster group */
    Fee_JobIntClrGrpIt = 0U;
    Fee_JobIntClrIt = 0U;

    /* Schedule reading of first cluster header */
    RetVal = Fee_JobInternalScanCluHdrRead();

    return RetVal;
}

/**
* @brief        Check if all cluster have been scanned or not
* @return       boolean
* @retval       TRUE                    All clusters have been scanned
* @retval       FALSE                   There are still clusters to scan
*
*/
FEE_FUNC LOCAL_INLINE boolean Fee_JobInternalScanCluHdrDone(void)
{
    boolean RetVal;

    /* Move on to next cluster */
    Fee_JobIntClrIt += 1U;

    if (Fee_JobIntClrIt == Fee_ClrGrps[Fee_JobIntClrGrpIt].ClrCount)
    {
        /* Move on to next cluster group */
        Fee_JobIntClrGrpIt += 1U;
        Fee_JobIntClrIt = 0U;
    }

    if (FEE_NUMBER_OF_CLUSTER_GROUPS == Fee_JobIntClrGrpIt)
    {
        Fee_JobIntClrGrpIt = 0U;

        /* Done scanning all cluster headers */
        RetVal = TRUE;
    }
    else
    {
        /* There are still clusters to scan */
        RetVal = FALSE;
    }

    return RetVal;
}

/**
* @brief        Parse Fee cluster header
*
* @param[in]    BufferValid             FALSE if previous Fls read job has failed
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase or read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase or read job
*
* @pre          Fee_JobIntClrGrpIt must contain index of current Fee cluster group
* @pre          Fee_JobIntClrIt must contain index of current cluster
* @post         Update the Fee_JobIntClrIt and/or Fee_JobIntClrGrpIt iterators to move
*               into next cluster and/or cluster group and read next cluster header if
*               there is any
* @post         Scan first active cluster if Fee is done with reading the cluster headers
* @post         Schedule the FEE_JOB_DONE, FEE_JOB_INT_SCAN_CLR_FMT,
*               FEE_JOB_INT_SCAN_CLR_PARSE, FEE_JOB_INT_SCAN_CLR_HDR_PARSE subsequent jobs
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalScanCluHdrParse(const boolean BufferValid)
{
    MemIf_JobResultType RetVal;
    Fee_ClusterStatusType ClrStatus;
    Fls_AddressType CfgStartAddr;
    Fee_ClusterHeaderType ClrHdr;
    Fls_LengthType CfgClrSize;
    boolean ScanClusterDone = FALSE;

    /* Deserialize cluster parameters from the read buffer */
    ClrStatus = Fee_DeserializeClusterHdr(&ClrHdr, Fee_DataBuffer);

    /* Get configured cluster start address and size */
    CfgStartAddr = Fee_ClrGrps[Fee_JobIntClrGrpIt].ClrPtr[Fee_JobIntClrIt].StartAddr;
    CfgClrSize = Fee_GetClusterLength(Fee_JobIntClrGrpIt, Fee_JobIntClrIt);

    if ((TRUE == BufferValid) &&
            (FEE_CLUSTER_VALID == ClrStatus) &&
            (ClrHdr.StartAddr == CfgStartAddr) &&
            (ClrHdr.Length == CfgClrSize)
       )
    {

        if (ClrHdr.ClrID > Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].ActClrID)
        {
            /* Found active cluster */
            Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].ActClr = Fee_JobIntClrIt;
            Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].ActClrID = ClrHdr.ClrID;
        }
    }
    else
    {
        /* Invalid, inconsistent, move to the next one */
    }

    /* Move on to next cluster */
    ScanClusterDone = Fee_JobInternalScanCluHdrDone();


    if (TRUE == ScanClusterDone)
    {
        /* Done reading all cluster headers. Now scan active clusters */
        RetVal = Fee_JobInternalScanCluster();
    }
    else
    {
        /* Read next cluster header */
        RetVal = Fee_JobInternalScanCluHdrRead();
    }

    return RetVal;
}

/**
* @brief        Read Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept read job
* @retval       MEMIF_BLOCK_INVALID      Requested Fee block is invalid
* @retval       MEMIF_BLOCK_INCONSISTENT Requested Fee block is inconsistent
*
* @pre          Fee_JobBlockIndex       must contain index of requested Fee block
* @pre          Fee_JobBlockOffset      must contain Offset in requested Fee block
* @pre          Fee_JobBlockLength      must contain number of bytes to read from requested Fee block
* @post         Schedule the FEE_JOB_DONE    subsequent job
*
* @implements   Fee_JobReadBlock_Activity
*/
FEE_FUNC static MemIf_JobResultType Fee_JobReadBlock(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_FAILED;
    Fee_BlockStatusType BlockStatus = FEE_BLOCK_VALID;
    Fls_AddressType BlockAddress = 0UL;
    BlockStatus = Fee_BlockInfo[Fee_JobBlockIndex].BlockStatus;
    BlockAddress = Fee_BlockInfo[Fee_JobBlockIndex].DataAddr;

    if (FEE_BLOCK_VALID == BlockStatus)
    {
        if (((Std_ReturnType)E_OK) != Fee_ReadFromFls(BlockAddress + Fee_JobBlockOffset, Fee_JobReadDataDestPtr, Fee_JobBlockLength))
        {
            /* Fls read job hasn't been accepted */
            RetVal = MEMIF_JOB_FAILED;
        }
        else
        {
            /* Fls read job has been accepted */
            RetVal = MEMIF_JOB_PENDING;
        }
    }
#if (FEE_MARK_EMPTY_BLOCKS_INVALID == STD_OFF)
    else if (FEE_BLOCK_NEVER_WRITTEN == BlockStatus)
    {
        /* in case the block was never written */
        RetVal = MEMIF_BLOCK_INCONSISTENT;
    }
#endif
    else if (FEE_BLOCK_INVALID == BlockStatus)
    {
        RetVal = MEMIF_BLOCK_INVALID;
    }
    else if ((FEE_BLOCK_INCONSISTENT == BlockStatus) || (FEE_BLOCK_INCONSISTENT_COPY == BlockStatus))
    {
        /* No special treatment of immediate blocks needed anymore */
        RetVal = MEMIF_BLOCK_INCONSISTENT;
    }
    else
    {
        /* Something is wrong... MEMIF_JOB_FAILED */
    }

    /* There is no consecutive job to schedule */
    Fee_Job = FEE_JOB_DONE;

    return RetVal;
}

/**
* @brief        Validate Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls did not accept write job
*
* @pre          Fee_JobIntHdrAddr must contain address of Fee block header to
*               validate
* @post         Schedule the FEE_JOB_INT_SWAP_BLOCK subsequent job
*
* @implements   Fee_JobInternalSwapBlockVld_Activity
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalSwapBlockVld(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;

    /* Serialize validation pattern to buffer */
    Fee_SerializeFlag(Fee_DataBuffer, FEE_VALIDATED_VALUE);

    /* Write header to flash */
    if (((Std_ReturnType)E_OK) != Fee_WriteToFls(Fee_JobIntHdrAddr - (2U * FEE_VIRTUAL_PAGE_SIZE), Fee_DataBuffer, FEE_VIRTUAL_PAGE_SIZE))
    {
        /* Fls read job hasn't been accepted */
        RetVal = MEMIF_JOB_FAILED;
    }
    else
    {
        /* Fls read job has been accepted */
        RetVal = MEMIF_JOB_PENDING;
    }

    /* Finalize the write operation */
    Fee_Job = FEE_JOB_INT_SWAP_BLOCK;

    return RetVal;
}

/**
* @brief        Read data from source cluster to internal Fee buffer
*
* @param[in]    BufferValid             FALSE if previous Fls read job has failed
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept read job
*
* @pre          Fee_JobIntBlockIt must contain index of currently swaped
*               Fee block
* @pre          Fee_JobIntDataAddr must contain start address of Fee data block
*               in the target cluster
* @pre          Fee_JobIntAddrIt must contain current address of Fee data block
*               in the target cluster
* @post         Move on to next block Fee block if BufferValid == FALSE
* @post         Validates the Fee block if there is no more data to read
* @post         Schedule the FEE_JOB_INT_SWAP_DATA_WRITE subsequent job
*
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalSwapDataRead(const boolean BufferValid)
{
    MemIf_JobResultType RetVal;
    Fls_AddressType ReadAddr;
    uint16 AlignedBlockSize;
    uint16 BlockSize;

    /* Get size of swapped block */
    BlockSize = Fee_GetBlockSize(Fee_JobIntBlockIt);

    /* Get size of swapped block aligned to virtual page boundary */
    AlignedBlockSize = Fee_AlignToVirtualPageSize(BlockSize);

    /* Calculate remaining number of bytes to read */
    Fee_JobBlockLength = (Fee_JobIntDataAddr + AlignedBlockSize) - Fee_JobIntAddrIt;

    if (FALSE == BufferValid)
    {
        /* There was error while reading the source cluster.
           Change the block status to FEE_BLOCK_INCONSISTENT_COPY to mark the status change
           during swap, leave the block (in flash) INCONSITENT and move on to next block */
        Fee_BlockInfo[Fee_JobIntBlockIt].BlockStatus = FEE_BLOCK_INCONSISTENT_COPY;

        Fee_JobIntBlockIt  += 1U;

        RetVal = Fee_JobInternalSwapBlock();
    }
    else if (0U == Fee_JobBlockLength)
    {
        /* No more bytes to copy. Validate the block and move on to next block... */
        Fee_JobIntBlockIt  += 1U;

        RetVal = Fee_JobInternalSwapBlockVld();
    }
    else
    {
        if (Fee_JobBlockLength > FEE_DATA_BUFFER_SIZE)
        {
            Fee_JobBlockLength = FEE_DATA_BUFFER_SIZE;
        }
        else
        {
            /* Block data fits into the buffer */
        }

        /* Calculate source address */
        ReadAddr = (Fee_BlockInfo[Fee_JobIntBlockIt].DataAddr + Fee_JobIntAddrIt) - Fee_JobIntDataAddr;

        /* Read the block data */
        if (((Std_ReturnType)E_OK) != Fee_ReadFromFls(ReadAddr, Fee_DataBuffer, Fee_JobBlockLength))
        {
            /* Fls read job hasn't been accepted */
            RetVal = MEMIF_JOB_FAILED;
        }
        else
        {
            /* Fls read job has been accepted */
            RetVal = MEMIF_JOB_PENDING;
        }

        Fee_Job = FEE_JOB_INT_SWAP_DATA_WRITE;
    }

    return RetVal;
}

/**
* @brief        Write data from internal Fee buffer to target cluster
*
* @param[in]    BufferValid              FALSE if previous Fls read job has failed
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING         Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED          Underlying Fls didn't accept write job
*
* @pre          Fee_JobBlockLength       must contain size of data block being
*                                         transfered(up to FEE_DATA_BUFFER_SIZE)
* @pre          Fee_JobIntAddrIt         must contain current address of Fee
*                                         data block in the target cluster
* @post         Update the Fee_JobIntAddrIt data iterator for next data
*               transfer if any
* @post         Schedule the FEE_JOB_INT_SWAP_DATA_READ subsequent job
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalSwapDataWrite(const boolean BufferValid)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;

    if (TRUE == BufferValid)
    {
        if (((Std_ReturnType)E_OK) == Fee_WriteToFls(Fee_JobIntAddrIt, Fee_DataBuffer, Fee_JobBlockLength))
        {
            /* Fls read job has been accepted */
            RetVal = MEMIF_JOB_PENDING;
        }
        else
        {
            /* Fls write job hasn't been accepted */
            RetVal = MEMIF_JOB_FAILED;
        }

        Fee_JobIntAddrIt += Fee_JobBlockLength;

        Fee_Job = FEE_JOB_INT_SWAP_DATA_READ;
    }
    else
    {
        RetVal = Fee_JobInternalSwapDataRead(FALSE);
    }

    return RetVal;
}

/**
* @brief        Finalize cluster validation
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED Underlying Fls didn't accept write job
*
* @pre          Fee_JobIntClrGrpIt must contain index of current Fee cluster
*               group
* @pre          Fee_JobIntClrIt must contain index of current cluster
* @post         Update the DataAddr and InvalidAddr Fee_BlockConfig variables of
*               all affected (swaped) Fee blocks
* @post         Update ActClr, ActClrID, HdrAddrIt, DataAddrIt Fee_ClrGrpInfo
*               variables of current cluster group
* @post         Change Fee module status from MEMIF_BUSYINTERNAL to MEMIF_BUSY
* @post         Re-schedule the Fee_JobIntOriginalJob subsequent job
*
* @implements   Fee_JobInternalSwapClusterVldDone_Activity
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInternalSwapCluVldDone(void)
{
    MemIf_JobResultType RetVal;
    Fls_AddressType HdrAddrIt;
    Fls_AddressType DataAddrIt;
    uint16 BlockSize;
    uint16 AlignedBlockSize;
    uint8 BlockClusterGrp;

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    /* Swap is done => re-initialize info about the blocks touching the Reserved Area within a cluster group where the swap has happened. */
    Fee_UntouchReservedAreaByClrGrp(Fee_JobIntClrGrpIt);
#endif

    HdrAddrIt = Fee_ClrGrps[Fee_JobIntClrGrpIt].ClrPtr[Fee_JobIntClrIt].StartAddr;
    DataAddrIt = HdrAddrIt + Fee_GetClusterLength(Fee_JobIntClrGrpIt, Fee_JobIntClrIt);

    /* Move on to the first block header */
    HdrAddrIt += FEE_CLUSTER_OVERHEAD;

    /* Sync block info */

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    for (uint16 BlockIt = 0U; BlockIt < (FEE_CRT_CFG_NR_OF_BLOCKS + Fee_ForeignBlocksNumber); ++BlockIt)
#else
    for (uint16 BlockIt = 0U; BlockIt < FEE_CRT_CFG_NR_OF_BLOCKS; ++BlockIt)
#endif
    {
        BlockClusterGrp = Fee_GetBlockClusterGrp(BlockIt);

        if (Fee_JobIntClrGrpIt == BlockClusterGrp)
        {
            /* Valid blocks and inconsistent blocks with allocated data were copied,
               update the block info and internal pointers accordingly.
            */
            if ((FEE_BLOCK_VALID == Fee_BlockInfo[BlockIt].BlockStatus) ||
                    (FEE_BLOCK_INCONSISTENT == Fee_BlockInfo[BlockIt].BlockStatus) ||
                    (FEE_BLOCK_INCONSISTENT_COPY == Fee_BlockInfo[BlockIt].BlockStatus)
               )
            {
                /* Sync InvalidAddr */
                Fee_BlockInfo[BlockIt].InvalidAddr = (HdrAddrIt + FEE_BLOCK_OVERHEAD) - FEE_VIRTUAL_PAGE_SIZE;

                /* Update the block data address info */
                if (FEE_BLOCK_VALID == Fee_BlockInfo[BlockIt].BlockStatus)
                {
                    BlockSize = Fee_GetBlockSize(BlockIt);
                    /* Align block size to the virtual page boundary */
                    AlignedBlockSize = Fee_AlignToVirtualPageSize(BlockSize);
                    /* "Allocate" data already swapped (written to the flash) */
                    DataAddrIt -= AlignedBlockSize;
                    /* store the data address to the block runtime record */
                    Fee_BlockInfo[BlockIt].DataAddr = DataAddrIt;
                }
                else
                {
                    /* (Inconsistent plain block in LEGACY == ON) or
                       (Inconsistent plain or immediate block in LEGACY == OFF) -- no data written (swapped, allocated)/available */
                    Fee_BlockInfo[BlockIt].DataAddr = 0U;
                }

                if (FEE_BLOCK_INCONSISTENT_COPY == Fee_BlockInfo[ BlockIt ].BlockStatus)
                {
                    BlockSize = Fee_GetBlockSize(BlockIt);
                    /* Align block size to the virtual page boundary */
                    AlignedBlockSize = Fee_AlignToVirtualPageSize(BlockSize);
                    /* "Allocate" data already swapped (written to the flash) */
                    DataAddrIt -= AlignedBlockSize;
                    /* Damaged data read during copy, but already allocated => inconsistent */
                    Fee_BlockInfo[ BlockIt ].BlockStatus = FEE_BLOCK_INCONSISTENT;
                }

                /* Advance the header pointer */
                HdrAddrIt += FEE_BLOCK_OVERHEAD;
            }
            else
            {
                /* Not a usable block */
                /* clear the addresses of the block not present in the new active cluster */
                Fee_BlockInfo[BlockIt].DataAddr = 0U;
                Fee_BlockInfo[BlockIt].InvalidAddr = 0U;
            }
        }
    }

    /* Switch to the new cluster */
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].ActClr = Fee_JobIntClrIt;
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].ActClrID  += 1U;
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].HdrAddrIt = HdrAddrIt;
    Fee_ClrGrpInfo[Fee_JobIntClrGrpIt].DataAddrIt = DataAddrIt;

    /* restore original Fee_Job */
    if (FEE_JOB_INT_SCAN_CLR == Fee_JobIntOriginalJob)
    {
        ++Fee_JobIntClrGrpIt;
    }
    else
    {
        /* Do nothing */
    }

    /* Internal job has finished so transition from MEMIF_BUSYINTERNAL to MEMIF_BUSY */
    Fee_ModuleStatus = MEMIF_BUSY;

    /* And now cross fingers and re-schedule original job ... */
    Fee_Job = Fee_JobIntOriginalJob;

    RetVal = Fee_JobScheAfterSwapCluVldDone();

    return RetVal;
}

/**
* @brief        Write Fee block header to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
*
* @pre          Fee_JobBlockIndex must contain index of Fee block to write to
* @post         Update the DataAddr and InvalidAddr Fee_BlockConfig variables of
*               written Fee block
* @post         Initialize internal cluster swap sequence if requested block
*               doesn't fit into current cluster
*
* @implements   Fee_JobWriteHdr_Activity
*/
FEE_FUNC static MemIf_JobResultType Fee_JobWriteHdr(void)
{
    MemIf_JobResultType RetVal;
    Fee_BlockType BlockHder;
    uint16 AlignedBlockSize;
    uint8 ClrGrpIndex;
    Fls_AddressType DataAddr;
    Fls_AddressType HdrAddr;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (Fee_JobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)

        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_WRITE, FEE_E_INVALID_BLOCK_NO);
#endif
        /* set job as failed */
        RetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
#ifdef FEE_NVM_JOB_ERROR_NOTIFICATION
        FEE_NVM_JOB_ERROR_NOTIFICATION;
#endif
    }
    else
    {
#endif

        /* Index of cluster group the Fee block belongs to */
        ClrGrpIndex = Fee_BlockConfig[Fee_JobBlockIndex].ClrGrp;

        /* Get size, Blocknumber, type of Fee block */
        BlockHder.Length = Fee_BlockConfig[Fee_JobBlockIndex].BlockSize;
        BlockHder.BlockNumber = Fee_BlockConfig[Fee_JobBlockIndex].BlockNumber;
        BlockHder.ImmediateBlock = Fee_BlockConfig[Fee_JobBlockIndex].ImmediateData;
        /* Align Fee block size to the virtual page boundary */
        AlignedBlockSize = Fee_AlignToVirtualPageSize(BlockHder.Length);

        if (FALSE == Fee_ReservedAreaWritable())
        {
            /* The block won't fit into current cluster. Init swap sequence... */
            /* Get cluster group index the block belongs to */
            Fee_JobIntClrGrpIt = ClrGrpIndex;

            RetVal = Fee_JobInternalSwap();
        }
        else
        {
            /* Calculate data and header addresses */
            DataAddr = Fee_ClrGrpInfo[ClrGrpIndex].DataAddrIt - AlignedBlockSize;
            HdrAddr = Fee_ClrGrpInfo[ClrGrpIndex].HdrAddrIt;

            /* Serialize block header to the write buffer */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
            Fee_SerializeBlockHdr(&BlockHder,
                                  DataAddr,
                                  Fee_BlockConfig[Fee_JobBlockIndex].BlockAssignment,
                                  Fee_DataBuffer
                                 );
#else
            Fee_SerializeBlockHdr(&BlockHder,
                                  DataAddr,
                                  Fee_DataBuffer
                                 );
#endif


            /* Write header to flash */
            if (((Std_ReturnType)E_OK) != Fee_WriteToFls(HdrAddr, Fee_DataBuffer, FEE_BLOCK_OVERHEAD - (2U * FEE_VIRTUAL_PAGE_SIZE)))
            {
                /* Fls read job hasn't been accepted */
                RetVal = MEMIF_JOB_FAILED;
            }
            else
            {
                /* Fls read job has been accepted */
                RetVal = MEMIF_JOB_PENDING;
            }
        }
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    }
#endif
    return RetVal;
}

/**
* @brief        Write Fee block data to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
*
* @pre          Fee_JobBlockIndex       must contain index of Fee block to write to
* @pre          Fee_JobWriteDataDestPtr must contain valid pointer to user buffer
* @post         Update HdrAddrIt, DataAddrIt Fee_ClrGrpInfo variables of current
*               cluster group if ImmediateData == FALSE only
* @post         Changes BlockStatus to FEE_BLOCK_INCONSISTENT
* @post         Schedule either FEE_JOB_WRITE_VALIDATE or
*               FEE_JOB_WRITE_UNALIGNED_DATA subsequent job
*
* @implements   Fee_JobWriteBlockData_Activity
*/
FEE_FUNC static MemIf_JobResultType Fee_JobWriteBlockData(void)
{
    Fls_AddressType DataAddr;
    MemIf_JobResultType RetVal;
    uint16 BlockSize;
    uint16 AlignedBlockSize;
    Fls_LengthType WriteLength;
    uint8 ClrGrp;
    const uint8 *WriteDataPtr;

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    boolean IsReservedAreaTouched;
#endif

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF)
    Fls_AddressType HdrAddr;
    uint8 ClrGrpIndex;
#endif

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (Fee_JobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_WRITE, FEE_E_INVALID_BLOCK_NO);
#endif
        /* set job as failed */
        RetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
#ifdef FEE_NVM_JOB_ERROR_NOTIFICATION
        FEE_NVM_JOB_ERROR_NOTIFICATION;
#endif
    }
    else
    {
#endif
        /* Get size of Fee block */
        BlockSize = Fee_BlockConfig[Fee_JobBlockIndex].BlockSize;

        /* Align Fee block size to the virtual page boundary */
        AlignedBlockSize = Fee_AlignToVirtualPageSize(BlockSize);

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF)
        /* No special treatment of immediate blocks needed anymore; dataAddr and invalidAddr
           has to be updated for a newly written imm/non-imm block  */

        /* Index of cluster group the Fee block belongs to */
        ClrGrpIndex = Fee_BlockConfig[Fee_JobBlockIndex].ClrGrp;

        /* Calculate data and header addresses */
        DataAddr = Fee_ClrGrpInfo[ClrGrpIndex].DataAddrIt - AlignedBlockSize;
        HdrAddr = Fee_ClrGrpInfo[ClrGrpIndex].HdrAddrIt;

        Fee_BlockInfo[Fee_JobBlockIndex].DataAddr = DataAddr;
        Fee_BlockInfo[Fee_JobBlockIndex].InvalidAddr = (HdrAddr + FEE_BLOCK_OVERHEAD) - FEE_VIRTUAL_PAGE_SIZE;

        /* Mark the block as inconsistent since the block header has been written */
        Fee_BlockInfo[Fee_JobBlockIndex].BlockStatus = FEE_BLOCK_INCONSISTENT;
#endif  /* (FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF) */

        /* Index of cluster group the Fee block belongs to */
        ClrGrp = Fee_BlockConfig[Fee_JobBlockIndex].ClrGrp;

        /* Header has been written so update both header and data addresses;
           no special treatment of immediate blocks needed anymore */
        Fee_ClrGrpInfo[ClrGrp].HdrAddrIt += FEE_BLOCK_OVERHEAD;
        Fee_ClrGrpInfo[ClrGrp].DataAddrIt -= AlignedBlockSize;

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        /* When FEE_BLOCK_ALWAYS_AVAILABLE is enabled, Fee_BlockInfo is not updated immediatelly
           upon a header write. In case of FEE Cancel, the information about the incosistent
           (due to incomplete write) immediate block potentially residing in the Reserved Area
           might be lost and therefore it need to be extra handled. */
        IsReservedAreaTouched = Fee_ReservedAreaTargetInClrGrp(ClrGrp);
        if ((FALSE != Fee_BlockConfig[Fee_JobBlockIndex].ImmediateData) && (FALSE != IsReservedAreaTouched))
        {
            /* Store the information about immediate blook touching the Reserved Area. */
            Fee_TouchReservedAreaByBlock(Fee_JobBlockIndex);
        }
#endif

        if (BlockSize < FEE_VIRTUAL_PAGE_SIZE)
        {
            /* Go through buffer... */
            Fee_CopyDataToPageBuffer(Fee_JobWriteDataDestPtr, Fee_DataBuffer, BlockSize);
            WriteDataPtr = Fee_DataBuffer;
            WriteLength = FEE_VIRTUAL_PAGE_SIZE;

            /* Schedule write of validation pattern */
            Fee_Job = FEE_JOB_WRITE_VALIDATE;
        }
        else
        {
            WriteDataPtr = Fee_JobWriteDataDestPtr;

            if (AlignedBlockSize == BlockSize)
            {
                WriteLength = BlockSize;

                /* Schedule write of validation pattern */
                Fee_Job = FEE_JOB_WRITE_VALIDATE;
            }
            else
            {
                WriteLength = ((uint32)AlignedBlockSize) - FEE_VIRTUAL_PAGE_SIZE;

                /* Schedule write of unaligned data */
                Fee_Job = FEE_JOB_WRITE_UNALIGNED_DATA;
            }
        }

        DataAddr = Fee_ClrGrpInfo[ClrGrp].DataAddrIt;

        if (((Std_ReturnType)E_OK) == Fee_WriteToFls(DataAddr, WriteDataPtr, WriteLength))
        {
            /* Fls write job has been accepted */
            RetVal = MEMIF_JOB_PENDING;
        }
        else
        {
            /* Fls write job hasn't been accepted */
            RetVal = MEMIF_JOB_FAILED;
        }
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    }
#endif
    return RetVal;
}

/**
* @brief        Write Fee block to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED Underlying Fls didn't accept write job
*
* @pre          Fee_JobBlockIndex must contain index of Fee block to write to
* @pre          Fee_JobWriteDataDestPtr must contain valid pointer to user buffer
* @post         Initialize internal cluster swap sequence if requested block
*               doesn't fit into current cluster
* @post         Schedule FEE_JOB_WRITE_DATA subsequent job
*
* @implements   Fee_JobWriteBlock_Activity
*/
FEE_FUNC static MemIf_JobResultType Fee_JobWriteBlock(void)
{
    MemIf_JobResultType RetVal;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (Fee_JobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)

        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_WRITE, FEE_E_INVALID_BLOCK_NO);
#endif
        /* set job as failed */
        RetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
#ifdef FEE_NVM_JOB_ERROR_NOTIFICATION
        FEE_NVM_JOB_ERROR_NOTIFICATION;
#endif
    }
    else
    {
#endif
        {
            /* Write block header */
            RetVal = Fee_JobWriteHdr();

            /* Schedule next job */
            if (FEE_JOB_INT_SWAP_CLR_FMT == Fee_Job)
            {
                /* Block didn't fit into the cluster. Cluster swap has been enforced... */
            }
            else
            {
                Fee_Job = FEE_JOB_WRITE_BLOCK_HDR;
            }
        }
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    }
#endif
    return RetVal;
}

/**
 * @brief        Change the Fee state after writting Fee block header to flash completed
 * @return       void
 */
FEE_FUNC static MemIf_JobResultType Fee_JobWriteBlockHdrWait(void)
{
    Fee_Job = FEE_JOB_WRITE_DATA;

    return MEMIF_JOB_PENDING;
}

/**
* @brief        Write unaligned rest of Fee block data to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
*
* @pre          Fee_JobBlockIndex must contain index of Fee block to write to
* @pre          Fee_JobWriteDataDestPtr must contain valid pointer to user buffer
* @post         Schedule FEE_JOB_WRITE_VALIDATE subsequent job
*
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobWriteBlockUnalignedData(void)
{
    MemIf_JobResultType RetVal;
    Fls_AddressType DataAddr;
    uint16 WriteOffset;
    uint16 WriteLength;
    uint16 BlockSize;

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    uint16 ClrGrp;
#endif

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (Fee_JobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)

        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_WRITE, FEE_E_INVALID_BLOCK_NO);
#endif
        /* set job as failed */
        RetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
#ifdef FEE_NVM_JOB_ERROR_NOTIFICATION
        FEE_NVM_JOB_ERROR_NOTIFICATION;
#endif
    }
    else
    {
#endif
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        /* Index of cluster group the Fee block belongs to */
        ClrGrp = Fee_BlockConfig[Fee_JobBlockIndex].ClrGrp;
#endif

        /* Get size of Fee block */
        BlockSize = Fee_BlockConfig[Fee_JobBlockIndex].BlockSize;

        /* Calculate number of bytes already written */
        WriteOffset = (BlockSize / FEE_VIRTUAL_PAGE_SIZE) * FEE_VIRTUAL_PAGE_SIZE;

        /* Calculate Length remaining data to write */
        WriteLength = BlockSize % FEE_VIRTUAL_PAGE_SIZE;

        Fee_CopyDataToPageBuffer(&Fee_JobWriteDataDestPtr[WriteOffset], Fee_DataBuffer, WriteLength);

        /* No special treatment of immediate data needed any more */
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        /* Use ClrGrp info */
        DataAddr = Fee_ClrGrpInfo[ClrGrp].DataAddrIt;
#else
        /* Use Block info because it has been updated */
        DataAddr = Fee_BlockInfo[Fee_JobBlockIndex].DataAddr;
#endif

        if (((Std_ReturnType)E_OK) == Fee_WriteToFls(DataAddr + WriteOffset, Fee_DataBuffer, FEE_VIRTUAL_PAGE_SIZE))
        {
            /* Fls write job has been accepted */
            RetVal = MEMIF_JOB_PENDING;
        }
        else
        {
            /* Fls write job hasn't been accepted */
            RetVal = MEMIF_JOB_FAILED;
        }

        /* Schedule write of validation pattern */
        Fee_Job = FEE_JOB_WRITE_VALIDATE;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    }
#endif
    return RetVal;
}

/**
* @brief        Validate Fee block by writing validation flag to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
*
* @pre          Fee_JobBlockIndex must contain index of Fee block to validate
* @post         Schedule FEE_JOB_WRITE_DONE subsequent job
*
* @implements   Fee_JobWriteBlockValidate_Activity
*/
FEE_FUNC static MemIf_JobResultType Fee_JobWriteBlockValidate(void)
{
    MemIf_JobResultType RetVal;
    Fls_AddressType HdrAddr;

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    uint8 ClrGrpIndex;
#endif

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (Fee_JobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_WRITE, FEE_E_INVALID_BLOCK_NO);
#endif
        /* set job as failed */
        RetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
#ifdef FEE_NVM_JOB_ERROR_NOTIFICATION
        FEE_NVM_JOB_ERROR_NOTIFICATION;
#endif
    }
    else
    {
#endif

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        /* Index of cluster group the Fee block belongs to */
        ClrGrpIndex = Fee_BlockConfig[Fee_JobBlockIndex].ClrGrp;
#endif
        /* Serialize validation pattern to buffer */
        Fee_SerializeFlag(Fee_DataBuffer, FEE_VALIDATED_VALUE);

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        /* Use ClrGrp info */
        HdrAddr = Fee_ClrGrpInfo[ClrGrpIndex].HdrAddrIt - (2U *  FEE_VIRTUAL_PAGE_SIZE);
#else
        /* Use Block info */
        HdrAddr = Fee_BlockInfo[Fee_JobBlockIndex].InvalidAddr - FEE_VIRTUAL_PAGE_SIZE;
#endif

        /* Write validation pattern to flash */
        if (((Std_ReturnType)E_OK) == Fee_WriteToFls(HdrAddr, Fee_DataBuffer, FEE_VIRTUAL_PAGE_SIZE))
        {
            /* Fls read job has been accepted */
            RetVal = MEMIF_JOB_PENDING;
        }
        else
        {
            /* Fls write job hasn't been accepted */
            RetVal = MEMIF_JOB_FAILED;
        }

        /* Finalize the write operation */
        Fee_Job = FEE_JOB_WRITE_DONE;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    }
#endif
    return RetVal;
}

/**
* @brief        Finalize validation of Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK
*
* @pre          Fee_JobBlockIndex must contain index of Fee block to write to
* @post         change Fee block status to FEE_BLOCK_VALID
* @post         Schedule FEE_JOB_DONE subsequent job
*
*
*/
#if ((FEE_SETMODE_API_SUPPORTED == STD_ON) || defined(__DOXYGEN__))
/**
* @brief Checks whether the block specified by Fee_JobBlockIndex is writable into the reserved area.
*
* @return MemIf_JobResultType
* @retval MEMIF_JOB_OK The Fls driver is not busy, set mode successfully
* @retval MEMIF_JOB_FAILED Fls driver is busy with other request
*
* @pre Fee_JobBlockIndex must contain index of Fee block to be written
*
* @implements   Fee_JobSetModeTransfer_Activity
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobSetModeTransfer(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;

    if (Fls_GetStatus() == MEMIF_IDLE)
    {
        Fee_ModuleStatus = MEMIF_BUSY;
        /*Set mode for Fls driver*/
        Fls_SetMode(Fee_Mode);
    }
    else
    {
        /*Return fail if Fls driver is not IDLE*/
        RetVal = MEMIF_JOB_FAILED;
        (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_SET_MODE, FEE_E_BUSY);
    }
    return RetVal;
}
#endif
/**
 * @brief        Finalize write operation
 * @return       MemIf_JobResultType
 * @retval       MEMIF_JOB_OK
 * @pre          Fee_JobBlockIndex must contain index of Fee block to write to
 *
 */
FEE_FUNC static MemIf_JobResultType Fee_JobWriteBlockDone(void)
{
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    Fls_AddressType DataAddr;
    Fls_AddressType HdrAddr;
    uint8 ClrGrpIndex;

    /* Index of cluster group the Fee block belongs to */
    ClrGrpIndex = Fee_BlockConfig[Fee_JobBlockIndex].ClrGrp;

    /* Calculate data and header addresses */
    DataAddr = Fee_ClrGrpInfo[ClrGrpIndex].DataAddrIt;
    HdrAddr = Fee_ClrGrpInfo[ClrGrpIndex].HdrAddrIt;

    /* Update the block address info */
    Fee_BlockInfo[Fee_JobBlockIndex].DataAddr = DataAddr;
    Fee_BlockInfo[Fee_JobBlockIndex].InvalidAddr = HdrAddr - FEE_VIRTUAL_PAGE_SIZE;
#endif

    /* Mark the Fee block as valid */
    Fee_BlockInfo[Fee_JobBlockIndex].BlockStatus = FEE_BLOCK_VALID;

    /* No more Fls jobs to schedule */
    Fee_Job = FEE_JOB_DONE;

    return MEMIF_JOB_OK;
}

/**
* @brief        Invalidate Fee block by writing the invalidation flag to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
* @retval       MEMIF_JOB_OK             The Fee block is already invalid
*
* @pre          Fee_JobBlockIndex must contain index of Fee block to invalidate
* @post         Schedule FEE_JOB_DONE or FEE_JOB_INVAL_BLOCK_DONE subsequent
*               jobs
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInvalidateBlock(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;

    if (FEE_BLOCK_INVALID == Fee_BlockInfo[Fee_JobBlockIndex].BlockStatus)
    {
        /* No more subsequent Fls jobs to schedule */
        Fee_Job = FEE_JOB_DONE;

        /* Fee job completed */
        RetVal = MEMIF_JOB_OK;
    }
    else
    {
#if (FEE_MARK_EMPTY_BLOCKS_INVALID == STD_OFF)
        if (FEE_BLOCK_NEVER_WRITTEN == Fee_BlockInfo[Fee_JobBlockIndex].BlockStatus)
        {
            /* set status as INVALID */
            Fee_BlockInfo[Fee_JobBlockIndex].BlockStatus = FEE_BLOCK_INVALID;

            /* No more subsequent Fls jobs to schedule */
            Fee_Job = FEE_JOB_DONE;

            /* Fee job completed */
            RetVal = MEMIF_JOB_OK;
        }
        else
#endif
        {
            /* Serialize invalidation pattern to buffer */
            Fee_SerializeFlag(Fee_DataBuffer, FEE_INVALIDATED_VALUE);

            /* Write invalidation pattern to flash */
            if (((Std_ReturnType)E_OK) == Fee_WriteToFls(Fee_BlockInfo[Fee_JobBlockIndex].InvalidAddr, Fee_DataBuffer, FEE_VIRTUAL_PAGE_SIZE))
            {
                /* Fls read job has been accepted */
                RetVal = MEMIF_JOB_PENDING;
            }
            else
            {
                /* Fls write job hasn't been accepted */
                RetVal = MEMIF_JOB_FAILED;
            }

            /* Finalize the invalidation operation */
            Fee_Job = FEE_JOB_INVAL_BLOCK_DONE;
        }
    }

    return RetVal;
}

/**
* @brief        Finalize invalidation of Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK
*
* @pre          Fee_JobBlockIndex       must contain index of Fee block to write to
* @post         change Fee block status to FEE_BLOCK_INVALID
* @post         Schedule FEE_JOB_DONE subsequent job
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobInvalidateBlockDone(void)
{
    /* Mark the Fee block as in valid */
    Fee_BlockInfo[Fee_JobBlockIndex].BlockStatus = FEE_BLOCK_INVALID;

    /* No more subsequent Fls jobs to schedule */
    Fee_Job = FEE_JOB_DONE;

    /* Fee job completed */
    return MEMIF_JOB_OK;
}

/**
* @brief        Erase (pre-allocate) immediate Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
*
* @pre          Fee_JobBlockIndex must contain index of Fee block to
*               pre-allocated
* @post         Initialize internal cluster swap sequence if requested block
*               doesn't fit into current cluster
* @post         Schedule FEE_JOB_DONE subsequent jobs
*
* @implements   Fee_JobEraseImmediateBlock_Activity
*
*/
FEE_FUNC static MemIf_JobResultType Fee_JobEraseImmediateBlock(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_OK;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (Fee_JobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)

        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_ERASE_IMMEDIATE_BLOCK, FEE_E_INVALID_BLOCK_NO);
#endif
        /* set job as failed */
        RetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
#ifdef FEE_NVM_JOB_ERROR_NOTIFICATION
        FEE_NVM_JOB_ERROR_NOTIFICATION;
#endif
    }
    else
    {
#endif
#if (FEE_LEGACY_IMM_ERASE_MODE == STD_ON)
        /* Legacy mode enabled, Fee_JobEraseImmediateBlock shall invalidate the block */
        if (FALSE == Fee_ReservedAreaWritable())
        {
            /* In legacy mode, pronounce the block to be erased as invalidated and then force the swap */
            Fee_BlockInfo[ Fee_JobBlockIndex ].BlockStatus = FEE_BLOCK_INVALID;
            Fee_JobIntClrGrpIt = Fee_BlockConfig[Fee_JobBlockIndex].ClrGrp;              /* Get cluster group index */
            RetVal = Fee_JobInternalSwap();
        }
        else
        {
            /* Otherwise trigger invalidate operation (in legacy mode) */
            RetVal = Fee_JobInvalidateBlock();
        }
#else
        /* In standard mode, perform swap if reserved area has been touched, or do nothing. */
        if (FALSE == Fee_ReservedAreaWritable())
        {
            /* Reserved area is not writable, force the swap */
            Fee_JobIntClrGrpIt = Fee_BlockConfig[Fee_JobBlockIndex].ClrGrp;              /* Get cluster group index */
            RetVal = Fee_JobInternalSwap();
        }
        else
        {
            /* Do effectively nothing */
            Fee_Job = FEE_JOB_DONE;
        }
#endif
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    }
#endif
    return RetVal;
}

/**
* @brief        Schedule subsequent jobs
* @return       MemIf_JobResultType
* @pre          Fee_Job must contain type of job to schedule
* @implements   Fee_JobSchedule_Activity
*/
FEE_FUNC static MemIf_JobResultType Fee_JobSchedule(void)
{
    /* Jump to the current Fee job through function pointer */
    return Fee_JobScheduleLookupTable[Fee_Job]();
}

/**
* @brief        Schedule subsequent jobs
* @return       MemIf_JobResultType
* @pre          Fee_Job must contain type of job to schedule
*/
FEE_FUNC static MemIf_JobResultType Fee_JobScheAfterSwapCluVldDone(void)
{
    MemIf_JobResultType RetVal = MEMIF_JOB_FAILED;

    switch (Fee_Job)
    {
        /* Fee_Write() related jobs */
        case FEE_JOB_WRITE:
            RetVal = Fee_JobWriteBlock();
            break;
        /* Fee_EraseImmediateBlock() related jobs */
        case FEE_JOB_ERASE_IMMEDIATE:
            RetVal = Fee_JobEraseImmediateBlock();
            break;
        default:
            /* Compiler_Warning: This default branch will never be reached in FTE */
            break;
    }

    return RetVal;
}

/**
* @brief Checks whether the block specified by Fee_JobBlockIndex is writable into the reserved area.
*
* @return sint8
* @retval TRUE The block is writable into the reserved area.
* @retval FALSE The block is not writable into the reserved area.
*
* @pre Fee_JobBlockIndex must contain index of Fee block to be written
* @pre Fee_ClrGrpInfo[ClrGrpIndex].DataAddrIt must be up to date
* @pre Fee_ClrGrpInfo[ClrGrpIndex].HdrAddrIt must be up to date
*
* @implements   Fee_ReservedAreaWritable_Activity
*/
FEE_FUNC static boolean Fee_ReservedAreaWritable(void)
{
    boolean RetVal;
    uint16 BlockSize;
    uint16 AlignedBlockSize;
    Fls_LengthType AvailClrSpace;
    uint8 ClrGrpIndex;
    uint32 ReservedSpace;
    boolean ImmediateData;
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    boolean IsReservedAreaTouched;
#endif

    /* Index of cluster group the Fee block belongs to */
    ClrGrpIndex = Fee_GetBlockClusterGrp(Fee_JobBlockIndex);

    /* Reserved space of cluster group*/
    ReservedSpace = Fee_ClrGrps[ClrGrpIndex].ReservedSize;

    /* Calculate available space in active cluster */
    AvailClrSpace = Fee_ClrGrpInfo[ClrGrpIndex].DataAddrIt - Fee_ClrGrpInfo[ClrGrpIndex].HdrAddrIt;

    /* Get size of Fee block */
    BlockSize = Fee_GetBlockSize(Fee_JobBlockIndex);

    /* Align Fee block size to the virtual page boundary */
    AlignedBlockSize = Fee_AlignToVirtualPageSize(BlockSize);

    /* Hard Stop condition: One FEE_BLOCK_OVERHEAD must be left blank to have a clear separation
       between header block space and data block space */
    if ((((uint32)AlignedBlockSize) + (2U * FEE_BLOCK_OVERHEAD)) > AvailClrSpace)
    {
        RetVal = FALSE;
    }
    else if ((((uint32)AlignedBlockSize) + (2U * FEE_BLOCK_OVERHEAD) + ReservedSpace) > AvailClrSpace)
    {
        ImmediateData = Fee_GetBlockImmediate(Fee_JobBlockIndex);
        /* Block targets reserved area */
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        IsReservedAreaTouched = Fee_ReservedAreaTouchedByBlock(Fee_JobBlockIndex);
        if ((TRUE == ImmediateData) && (FALSE == IsReservedAreaTouched))
#else
        if (TRUE == ImmediateData)
#endif
        {
            /* Immediate block - only writable if not already present in the reserved area */
            if (((0UL == Fee_BlockInfo[Fee_JobBlockIndex].DataAddr) && (0UL == Fee_BlockInfo[Fee_JobBlockIndex].InvalidAddr)) || \
                    /* The block is written in the cluster - is it written in the reserved area? */
                    ((FEE_BLOCK_OVERHEAD + ReservedSpace) <= (Fee_BlockInfo[Fee_JobBlockIndex].DataAddr - \
                            (Fee_BlockInfo[Fee_JobBlockIndex].InvalidAddr + FEE_VIRTUAL_PAGE_SIZE)))
               )
            {
                /* The block is not written in the cluster at all => writable */
                /* or The block is not written in the reserved area */
                RetVal = TRUE;
            }
            else
            {
                RetVal = FALSE;
            }
        }
        else
        {
            RetVal = FALSE;
        }
    }
    else
    {
        /* Block does not target reserved area */
        RetVal = TRUE;
    }
    return RetVal;
}

/**
* @brief        Schedule the error jobs
* @return       void
* @pre          Fee_Job must contain type of job to schedule
*/
FEE_FUNC static void Fee_JobErrorSchedule(void)
{
    uint8 ClrGrpIndex;

    switch (Fee_Job)
    {
        /* Error while reading block header. Treat block header as invalid and stop reading further block headers */
        case FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE:
            Fee_JobResult = Fee_JobInternalScanBlkHdrParse(FALSE);
            break;

        /* Error while reading cluster header. Treat cluster as invalid and move on to next cluster */
        case FEE_JOB_INT_SCAN_CLR_HDR_PARSE:
            Fee_JobResult = Fee_JobInternalScanCluHdrParse(FALSE);
            break;

        /* Error while reading data from source cluster. Leave block as INCONSISTENT and move on to next block */
        case FEE_JOB_INT_SWAP_DATA_WRITE:
            Fee_JobResult = Fee_JobInternalSwapDataWrite(FALSE);
            break;

        /* for all the following cases based on the Fee module status error notification will be called */
        case FEE_JOB_WRITE:
        case FEE_JOB_WRITE_BLOCK_HDR:
        case FEE_JOB_WRITE_DATA:
        case FEE_JOB_WRITE_UNALIGNED_DATA:
        case FEE_JOB_ERASE_IMMEDIATE:
        case FEE_JOB_WRITE_VALIDATE:
        case FEE_JOB_WRITE_DONE:
        {
            ClrGrpIndex = Fee_GetBlockClusterGrp(Fee_JobBlockIndex);

            /* Something wrong in FlashMemory (cluster swap occurs to next write) */
            Fee_ClrGrpInfo[ClrGrpIndex].DataAddrIt = Fee_ClrGrpInfo[ClrGrpIndex].HdrAddrIt + (2U * FEE_BLOCK_OVERHEAD);
            Fee_JobResult = Fls_GetJobResult();
            Fee_ModuleStatus = MEMIF_IDLE;

            /* Call job error notification function */
#ifdef FEE_NVM_JOB_ERROR_NOTIFICATION
            FEE_NVM_JOB_ERROR_NOTIFICATION;
#endif
            break;
        }

        case FEE_JOB_READ:
        case FEE_JOB_INVAL_BLOCK:
        case FEE_JOB_INVAL_BLOCK_DONE:
        case FEE_JOB_INT_SCAN:
        case FEE_JOB_INT_SCAN_CLR:
        case FEE_JOB_INT_SCAN_CLR_FMT:
        case FEE_JOB_INT_SCAN_CLR_FMT_DONE:
        case FEE_JOB_INT_SWAP_BLOCK:
        case FEE_JOB_INT_SWAP_CLR_FMT:
        case FEE_JOB_INT_SWAP_DATA_READ:
        case FEE_JOB_INT_SWAP_CLR_VLD_DONE:
        case FEE_JOB_DONE:
        default:
            Fee_JobResult = Fls_GetJobResult();

            Fee_ModuleStatus = MEMIF_IDLE;

            /* Call job error notification function */
#ifdef FEE_NVM_JOB_ERROR_NOTIFICATION
            FEE_NVM_JOB_ERROR_NOTIFICATION;
#endif
            break;
    }
}

/**
* @brief        Read data from Fls, translate the emulation to logical address in sector retirement mode
* @param[in]    SourceAddress: Source address in Fls
* @param[out]    TargetAddressPtr: The address reads data to in RAM
* @param[in]    Length: The length of data to read
* @return       Std_ReturnType
* @retval       E_OK: Read successfully
* @retval       E_NOT_OK: Read failed
*/
FEE_FUNC static Std_ReturnType Fee_ReadFromFls(Fls_AddressType SourceAddress,
        uint8 *TargetAddressPtr,
        Fls_LengthType Length
                                              )
{
    return Fls_Read(SourceAddress, TargetAddressPtr, Length);
}

/**
* @brief        Write data to Fls, translate the emulation to logical address in sector retirement mode
* @param[in]    TargetAddress: Target address in Fls
* @param[in]    SourceAddressPtr: The writing source data address
* @param[in]    Length: The length of data to write
* @return       Std_ReturnType
* @retval       E_OK: Write successfully
* @retval       E_NOT_OK: Write failed
*/
FEE_FUNC static Std_ReturnType Fee_WriteToFls(Fls_AddressType TargetAddress,
        const uint8 *SourceAddressPtr,
        Fls_LengthType Length
                                             )
{
    return Fls_Write(TargetAddress, SourceAddressPtr, Length);
}

/**
* @brief        Erase the whole cluster, translate the emulation to logical address in sector retirement mode
*               and erase a sector at a time
* @param[in]    ClrGrpIt: The cluster group index
* @param[in]    ClrIt: The cluster index
* @return       Std_ReturnType
* @retval       E_OK: Erase successfully
* @retval       E_NOT_OK: Erase failed
*
*/
FEE_FUNC static Std_ReturnType Fee_EraseCluster(uint8 ClrGrpIt,
        uint8 ClrIt
                                               )
{

    Fls_AddressType ClusterAddress;
    Fls_LengthType  ClusterLength;

    /* Get address and size of cluster in the cluster group */
    ClusterAddress = Fee_ClrGrps[ClrGrpIt].ClrPtr[ClrIt].StartAddr;
    ClusterLength  = Fee_GetClusterLength(ClrGrpIt, ClrIt);

    return Fls_Erase(ClusterAddress, ClusterLength);
}

/**
* @brief        Get the Length of the cluster by the group index and cluster index
* @param[in]    ClrGrpIt: The cluster group index
* @param[in]    ClrIt: The cluster index
* @return       Fls_LengthType
* @retval       The length of the cluster
*/
FEE_FUNC LOCAL_INLINE Fls_LengthType Fee_GetClusterLength(uint8 ClrGrpIt,
        uint8 ClrIt
                                                         )
{
    return Fee_ClrGrps[ClrGrpIt].ClrPtr[ClrIt].Length;          /* Get from constant data configuration */

}

/**
 * @brief        Cancel ongoing Fls job in Fee mainfunction
 * @return       void
 * @pre          Fee_Job must contain type of job to cancel
*/
FEE_FUNC static void Fee_JobCancelExcult(void)
{
    if((TRUE == Fee_CancelRequest)&&\
        (Fee_Job!=FEE_JOB_WRITE_BLOCK_HDR))
    {
            Fee_JobResult = MEMIF_JOB_CANCELED;
            Fee_Job = FEE_JOB_DONE;
            Fls_Cancel();
            Fee_ModuleStatus = MEMIF_IDLE;
            Fee_CancelRequest = FALSE;
    }
}

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if (FEE_CANCEL_API == STD_ON)
FEE_FUNC void Fee_Cancel(void)
{
    if (MEMIF_UNINIT == Fee_ModuleStatus)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_CANCEL, FEE_E_UNINIT);
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        /* Cancel ongoing Fls job if any */
        if ((MEMIF_BUSY == Fee_ModuleStatus)&&(FALSE==Fee_CancelRequest))
        {

            Fee_CancelRequest = TRUE;
            /* No notifications from internal jobs */
        }
        else
        {
            (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_CANCEL, FEE_E_INVALID_CANCEL);
            /* Call job error notification function */
#ifdef FEE_NVM_JOB_ERROR_NOTIFICATION
            FEE_NVM_JOB_ERROR_NOTIFICATION;
#endif
        }
    }
}
#endif    /* FLS_CANCEL_API == STD_ON */

FEE_FUNC Std_ReturnType Fee_EraseImmediateBlock(uint16 BlockNumber)
{
    Std_ReturnType RetVal;
    uint16 BlockIndex = Fee_GetBlockIndex(BlockNumber);

    if (MEMIF_UNINIT == Fee_ModuleStatus)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_ERASE_IMMEDIATE_BLOCK, FEE_E_UNINIT);
#endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((FEE_BLANK_DATA_16BIT == BlockIndex) || (FALSE == Fee_BlockConfig[BlockIndex].ImmediateData))
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_ERASE_IMMEDIATE_BLOCK, FEE_E_INVALID_BLOCK_NO);
#endif
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_03();
        if (MEMIF_BUSY == Fee_ModuleStatus)
        {
            (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_ERASE_IMMEDIATE_BLOCK, FEE_E_BUSY);
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Configure the erase immediate block job */
            Fee_JobBlockIndex = BlockIndex;
            Fee_Job = FEE_JOB_ERASE_IMMEDIATE;
            Fee_ModuleStatus = MEMIF_BUSY;

            /* Execute the erase immediate block job */
            Fee_JobResult = MEMIF_JOB_PENDING;

            RetVal = (Std_ReturnType)E_OK;

        }
        SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_03();
    }
    return RetVal;
}


FEE_FUNC MemIf_JobResultType Fee_GetJobResult(void)
{
    MemIf_JobResultType RetVal = Fee_JobResult;

    if (MEMIF_UNINIT == Fee_ModuleStatus)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_GET_JOB_RESULT, FEE_E_UNINIT);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        RetVal = MEMIF_JOB_FAILED;
    }
    return RetVal;
}

FEE_FUNC MemIf_StatusType Fee_GetStatus(void)
{
    return Fee_ModuleStatus;
}

FEE_FUNC void Fee_Init(const Fee_ConfigType *ConfigPtr)
{
    uint32 InvalIndex;

    if (NULL_PTR != ConfigPtr)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_INIT, FEE_E_INIT_FAILED);
#endif
    }
    else if (MEMIF_BUSY == Fee_ModuleStatus)
    {
        (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_INIT, FEE_E_BUSY);
    }
    else
    {
        /* Initialize all block info records */
        for (InvalIndex = 0U; InvalIndex < FEE_MAX_NR_OF_BLOCKS; ++InvalIndex)
        {
#if (FEE_MARK_EMPTY_BLOCKS_INVALID == STD_ON)
            /* for blocks which were never written Fee returns INVALID status */
            Fee_BlockInfo[InvalIndex].BlockStatus = FEE_BLOCK_INVALID;
#else
            /* for blocks which were never written Fee returns INCONSISTENT status */
            Fee_BlockInfo[InvalIndex].BlockStatus = FEE_BLOCK_NEVER_WRITTEN;
#endif
            Fee_BlockInfo[InvalIndex].DataAddr = 0U;
            Fee_BlockInfo[InvalIndex].InvalidAddr = 0U;
        }

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        /* Initialize all foreign block config records */
        /*MR12 Rule 4.1 VIOLATION: This loop executed times is determined by FEE_MAX_NR_OF_BLOCKS and FEE_CRT_CFG_NR_OF_BLOCKS,
         *                         they are configured in config tools.
         *
         */
        for (InvalIndex = 0U; InvalIndex < (FEE_MAX_NR_OF_BLOCKS - FEE_CRT_CFG_NR_OF_BLOCKS); ++InvalIndex) /*PRQA S 2877*/
        {
            Fee_ForeignBlockConfig[InvalIndex].BlockNumber = 0U;
            Fee_ForeignBlockConfig[InvalIndex].BlockSize = 0U;
            Fee_ForeignBlockConfig[InvalIndex].ClrGrp = 0U;
            Fee_ForeignBlockConfig[InvalIndex].ImmediateData = FALSE;
            Fee_ForeignBlockConfig[InvalIndex].BlockAssignment = FEE_PROJECT_RESERVED;
        }
#endif
        /* Invalidate all cluster groups */
        for (InvalIndex = 0U; InvalIndex < FEE_NUMBER_OF_CLUSTER_GROUPS; ++InvalIndex)
        {
            Fee_ClrGrpInfo[InvalIndex].ActClrID = 0U;
#if (FEE_SECTOR_RETIREMENT == STD_ON)
            /* Link to the Fee cluster set information */
            Fee_ClrGrpInfo[InvalIndex].ClrInfo = Fee_ClusterRuntimeInfo[InvalIndex];
#endif
        }

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        Fee_UntouchReservedAreaAll();
#endif
        /* Schedule init job */
        Fee_Job = FEE_JOB_INT_SCAN;
        Fee_JobResult = MEMIF_JOB_PENDING;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        Fee_ForeignBlocksNumber = 0U;
#endif
    }
    (void)ConfigPtr;
}


FEE_FUNC Std_ReturnType Fee_InvalidateBlock(uint16 BlockNumber)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint16 BlockIndex = Fee_GetBlockIndex(BlockNumber);

    if (MEMIF_UNINIT == Fee_ModuleStatus)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_INVALIDATE_BLOCK, FEE_E_UNINIT);
#endif
    }
    else if (FEE_BLANK_DATA_16BIT == BlockIndex)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_INVALIDATE_BLOCK, FEE_E_INVALID_BLOCK_NO);
#endif
    }
    else
    {
        SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_02();
        if (MEMIF_BUSY == Fee_ModuleStatus)
        {
            (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_INVALIDATE_BLOCK, FEE_E_BUSY);
        }
        else
        {
            /* Configure the invalidate block job */
            Fee_JobBlockIndex = BlockIndex;

            Fee_Job = FEE_JOB_INVAL_BLOCK;

            Fee_ModuleStatus = MEMIF_BUSY;

            /* Execute the invalidate block job */
            Fee_JobResult = MEMIF_JOB_PENDING;

            RetVal = (Std_ReturnType)E_OK;
        }
        SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_02();
    }

    return RetVal;
}

/**
 * @brief            Service to report to this module the successful end of an asynchronous operation.
 * @return           void
 */
/* PRQA S 3408 Rule 8.4: Fee_JobEndNotification is declared and used in another .c file, so it couldn't
 *                       adhere to M3CM Rule-8.4
 */
FEE_FUNC void Fee_JobEndNotification(void)  /*PRQA S 3408*/
{
    if ((MEMIF_UNINIT == Fee_ModuleStatus) && (MEMIF_JOB_OK == Fee_JobResult) && (FEE_JOB_DONE == Fee_Job))
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_JOB_END_NOTIFICATION, FEE_E_UNINIT);
#else
        /* Do nothing. Fee is not initialized */
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        if (FEE_JOB_DONE == Fee_Job)
        {
            /* Last schedule Fls job finished */
            Fee_JobResult = Fls_GetJobResult();
            Fee_ModuleStatus = MEMIF_IDLE;
            Fee_CancelRequest = FALSE;

            /* Call job end notification function */
#ifdef FEE_NVM_JOB_END_NOTIFICATION
            FEE_NVM_JOB_END_NOTIFICATION;
#endif
        }
        else
        {
            /*if Fee wait block hdr write complete, change the state to write data*/
            if(FEE_JOB_WRITE_BLOCK_HDR==Fee_Job)
            {
                Fee_JobWriteBlockHdrWait();
            }

            Fee_JobResult = Fee_JobSchedule();
            if (MEMIF_JOB_OK == Fee_JobResult)
            {
                Fee_ModuleStatus = MEMIF_IDLE;

                /* Call job end notification function */
#ifdef FEE_NVM_JOB_END_NOTIFICATION
                FEE_NVM_JOB_END_NOTIFICATION;
#endif

            }
            else if (MEMIF_JOB_PENDING == Fee_JobResult)
            {
                /* Nothing to do (ongoing Fls job) */
            }
            else
            {
                Fee_ModuleStatus = MEMIF_IDLE;

                /* Call job error notification function */
#ifdef FEE_NVM_JOB_ERROR_NOTIFICATION
                FEE_NVM_JOB_ERROR_NOTIFICATION;
#endif
            }
        }
    }
}

/**
 * @brief            Service to report to this module the failure of an asynchronous operation.
 * @return           void
 */
/* PRQA S 3408 Rule 8.4: Fee_JobEndNotification is declared and used in another .c file, so it couldn't
 *                       adhere to M3CM Rule-8.4
 */
FEE_FUNC void Fee_JobErrorNotification(void)  /*PRQA S 3408*/
{
#if (FEE_SECTOR_RETIREMENT == STD_ON)
    Std_ReturnType TransStatus;
#endif

    if ((MEMIF_UNINIT == Fee_ModuleStatus) && (MEMIF_JOB_OK == Fee_JobResult) && (FEE_JOB_DONE == Fee_Job))
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)

        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_JOB_ERROR_NOTIFICATION, FEE_E_UNINIT);
#else
        /* Do nothing. Fee is not initialized */
#endif  /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        if (MEMIF_JOB_CANCELED == Fee_JobResult)
        {
            /* Fls job has been canceled. Do nothing in this callback.
            The NvM_JobErrorNotification() callback will be called from the Fee_Cancel()function which called the Fls_Cancel() function */
        }
        else
        {
            /* Schedule the error job */
            Fee_JobErrorSchedule();
        }
    }
}


FEE_FUNC void Fee_MainFunction(void)
{
    if (MEMIF_JOB_PENDING == Fee_JobResult)
    {
        Fee_JobCancelExcult();
        switch (Fee_Job)
        {
            /* for all the following jobs subsequent jobs will be called in Fee job schedule function based on Job */
            case FEE_JOB_INT_SCAN:
            case FEE_JOB_READ:
#if ((FEE_SETMODE_API_SUPPORTED == STD_ON) || defined(__DOXYGEN__))
            case FEE_JOB_SETMODE:
#endif
            case FEE_JOB_WRITE:
            case FEE_JOB_INVAL_BLOCK:
            case FEE_JOB_ERASE_IMMEDIATE:
                Fee_JobResult = Fee_JobSchedule();
                break;
            /* for all the following jobs job end or job error notification will be called based on the job result */
            case FEE_JOB_WRITE_DATA:
            case FEE_JOB_WRITE_UNALIGNED_DATA:
            case FEE_JOB_WRITE_VALIDATE:
            case FEE_JOB_WRITE_DONE:
            case FEE_JOB_INVAL_BLOCK_DONE:
            case FEE_JOB_INT_SCAN_CLR_HDR_PARSE:
            case FEE_JOB_INT_SCAN_CLR:
            case FEE_JOB_INT_SCAN_CLR_FMT:
            case FEE_JOB_INT_SCAN_CLR_FMT_DONE:
            case FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE:
            case FEE_JOB_INT_SWAP_BLOCK:
            case FEE_JOB_INT_SWAP_CLR_FMT:
            case FEE_JOB_INT_SWAP_DATA_READ:
            case FEE_JOB_INT_SWAP_DATA_WRITE:
            case FEE_JOB_INT_SWAP_CLR_VLD_DONE:
            case FEE_JOB_DONE:
            default:
                /* Internal or subsequent job */
                break;
        }

        if (MEMIF_JOB_PENDING == Fee_JobResult)
        {
            /* Nothing to do */
        }
        else if (MEMIF_JOB_OK == Fee_JobResult)
        {
            Fee_ModuleStatus = MEMIF_IDLE;
            /* Call job end notification function */
#ifdef FEE_NVM_JOB_END_NOTIFICATION
            FEE_NVM_JOB_END_NOTIFICATION;
#endif

        }
        else
        {
            Fee_ModuleStatus = MEMIF_IDLE;
            /* Call job error notification function */
#ifdef FEE_NVM_JOB_ERROR_NOTIFICATION
            FEE_NVM_JOB_ERROR_NOTIFICATION;
#endif
        }
    }
}

FEE_FUNC Std_ReturnType Fee_Read(uint16 BlockNumber, uint16 BlockOffset, uint8 *DataBufferPtr, uint16 Length)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint16 BlockIndex = Fee_GetBlockIndex(BlockNumber);

    if (MEMIF_UNINIT == Fee_ModuleStatus)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_READ, FEE_E_UNINIT);
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else if (FEE_BLANK_DATA_16BIT == BlockIndex)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_READ, FEE_E_INVALID_BLOCK_NO);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else if (BlockOffset >= Fee_BlockConfig[BlockIndex].BlockSize)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_READ, FEE_E_INVALID_BLOCK_OFS);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else if ((0U == Length) || ((BlockOffset + Length) > Fee_BlockConfig[BlockIndex].BlockSize))
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_READ, FEE_E_INVALID_BLOCK_LEN);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else if (NULL_PTR == DataBufferPtr)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_READ, FEE_E_PARAM_POINTER);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_00();
        if (MEMIF_BUSY == Fee_ModuleStatus)
        {
            (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_READ, FEE_E_BUSY);
        }
        else
        {
            /* Configure the read job */
            Fee_JobBlockIndex = BlockIndex;

            Fee_JobBlockOffset = BlockOffset;

            Fee_JobBlockLength = Length;

            Fee_JobReadDataDestPtr = DataBufferPtr;

            Fee_Job = FEE_JOB_READ;

            Fee_ModuleStatus = MEMIF_BUSY;

            /* Execute the read job */
            Fee_JobResult = MEMIF_JOB_PENDING;

            RetVal = (Std_ReturnType)E_OK;
        }
        SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_00();
    }
    return RetVal;
}

#if ((FEE_SETMODE_API_SUPPORTED == STD_ON) || defined(__DOXYGEN__))
FEE_FUNC void Fee_SetMode(MemIf_ModeType Mode)
{
    if (MEMIF_UNINIT == Fee_ModuleStatus)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_SET_MODE, FEE_E_UNINIT);
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else if (MEMIF_BUSY == Fee_ModuleStatus)
    {
        (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_SET_MODE, FEE_E_BUSY);
    }
    else
    {
        Fee_Job = FEE_JOB_SETMODE;
        Fee_Mode = Mode;
        Fee_JobResult = MEMIF_JOB_PENDING;
    }
}
#endif /* (FEE_SETMODE_API_SUPPORTED == STD_ON) || defined(__DOXYGEN__) */


FEE_FUNC Std_ReturnType Fee_Write(uint16 BlockNumber, const uint8 *DataBufferPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint16 BlockIndex = Fee_GetBlockIndex(BlockNumber);

    if (MEMIF_UNINIT == Fee_ModuleStatus)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)

        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_WRITE, FEE_E_UNINIT);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (FEE_BLANK_DATA_16BIT == BlockIndex)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_WRITE, FEE_E_INVALID_BLOCK_NO);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (NULL_PTR == DataBufferPtr)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_WRITE, FEE_E_PARAM_POINTER);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    else
    {
        SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_01();
        if (MEMIF_BUSY == Fee_ModuleStatus)
        {
            (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_WRITE, FEE_E_BUSY);
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Configure the write job */
            Fee_JobBlockIndex = BlockIndex;

            Fee_JobWriteDataDestPtr = DataBufferPtr;

            Fee_Job = FEE_JOB_WRITE;

            Fee_ModuleStatus = MEMIF_BUSY;

            /* Execute the write job */
            Fee_JobResult = MEMIF_JOB_PENDING;
        }
        SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_01();
    }
    return RetVal;
}


FEE_FUNC Std_ReturnType Fee_ForceSwapOnNextWrite(uint8 ClrGrpIndex)
{
    Std_ReturnType RetVal = E_NOT_OK;

    /* DET Check for cluster group should be added:
        - INITIALIZED driver
        - BUSY and BUSY_INTERNAL driver
        - Cluster group valid */

    if (MEMIF_UNINIT == Fee_ModuleStatus)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_FORCE_SWAP_ON_NEXT_WRITE, FEE_E_UNINIT);
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Cluster group index in valid range */
    else if (FEE_NUMBER_OF_CLUSTER_GROUPS <= ClrGrpIndex)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_FORCE_SWAP_ON_NEXT_WRITE, FEE_E_CLUSTER_GROUP_IDX);
        RetVal = (Std_ReturnType)E_NOT_OK;
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        if (MEMIF_BUSY == Fee_ModuleStatus)
        {
            (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_FORCE_SWAP_ON_NEXT_WRITE, FEE_E_BUSY);
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Fee_ClrGrpInfo[ClrGrpIndex].DataAddrIt = Fee_ClrGrpInfo[ClrGrpIndex].HdrAddrIt + (2U * FEE_BLOCK_OVERHEAD);
            RetVal = (Std_ReturnType)E_OK;
        }
    }

    return RetVal;
}


FEE_FUNC void Fee_GetRunTimeInfo(uint8 ClrGrpIndex, Fee_ClusterGroupRuntimeInfoType *ClrGrpRTInfo)
{
    uint8 ActiveClrIndex;

    /* DET Check for cluster group should be added:
        - INITIALIZED driver
        - BUSY and BUSY_INTERNAL driver
        - Cluster group valid */
    if (MEMIF_UNINIT == Fee_ModuleStatus)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)

        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_GET_RUNTIME_INFO, FEE_E_UNINIT);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else if (NULL_PTR == ClrGrpRTInfo)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_GET_RUNTIME_INFO, FEE_E_PARAM_POINTER);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else if (MEMIF_BUSY == Fee_ModuleStatus)
    {
        (void)Det_ReportRuntimeError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_GET_RUNTIME_INFO, FEE_E_BUSY);
    }
    /* Cluster group index in valid range */
    else if (FEE_NUMBER_OF_CLUSTER_GROUPS <= ClrGrpIndex)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        (void)Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SID_GET_RUNTIME_INFO, FEE_E_CLUSTER_GROUP_IDX);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        /* Get active cluster index for selected cluster group */
        ActiveClrIndex = Fee_ClrGrpInfo[ ClrGrpIndex ].ActClr;

        /* Size of the active cluster in selected cluster group */
        ClrGrpRTInfo->ClusterTotalSpace = Fee_GetClusterLength(ClrGrpIndex, ActiveClrIndex);

        ClrGrpRTInfo->ClusterFreeSpace = Fee_ClrGrpInfo[ ClrGrpIndex ].DataAddrIt -
                                         (Fee_ClrGrpInfo[ ClrGrpIndex ].HdrAddrIt + FEE_BLOCK_OVERHEAD);

        ClrGrpRTInfo->BlockHeaderOverhead = (uint16)FEE_BLOCK_OVERHEAD;
        ClrGrpRTInfo->VirtualPageSize = (uint16)FEE_VIRTUAL_PAGE_SIZE;
        ClrGrpRTInfo->NumberOfSwap = Fee_ClrGrpInfo[ ClrGrpIndex ].ActClrID - 1U;

#if (FEE_SECTOR_RETIREMENT == STD_ON)
        /* Get sector information from all clusters for selected cluster group */
        Fee_GetSectorRunTimeInfo(ClrGrpIndex, ClrGrpRTInfo);
#endif
    }
    /* to avoid error compiler warning */
    (void)ActiveClrIndex;
}

#define FEE_STOP_SEC_CODE
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

