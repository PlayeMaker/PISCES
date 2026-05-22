/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : NvM_Cfg.h
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



/*PRQA S 3429 EOF*/
/*
P2VAR and other macros in the Compiler conforms to AUTOSAR standard.There's no need to revise
*/

#ifndef NVM_CFG_H
#define NVM_CFG_H

#define NVM_CONFIG_VARIANTS                                 STD_CONFIG_VARIANTS_PRECOMPILE
#define NVM_API_CONFIG_CLASS                                NVM_API_CONFIG_CLASS_3
#define NVM_BSWM_MULTI_BLOCK_JOB_STATUS_INFORMATION         STD_ON
#define NVM_CRC_NUM_OF_BYTES                                ((uint16)10)
#define NVM_DATASET_SELECTION_BITS                          0

#define NvM_CSM_RETRY_COUNTER                               ((uint8)0)

#define NVM_DEV_ERROR_DETECT                                STD_ON
#define NVM_DRV_MODE_SWITCH                                 STD_OFF

#define NVM_DYNAMIC_CONFIGURATION                           STD_OFF
#define NVM_JOB_PRIORITIZATION                              STD_OFF
#define NVM_POLLING_MODE                                    STD_OFF

#define NVM_REPEAT_MIRROR_OPERATIONS                        ((uint8)0)
#define NVM_SET_RAM_BLOCK_STATUS_API                        STD_OFF
#define NVM_VERSION_INFO_API                                STD_OFF

/*Eas Special*/
#define NVM_ERASE_API                                       STD_OFF
#define NVM_INVALID_NVBLOCK_API                             STD_OFF
#define NVM_CANCELJOB_API                                   STD_OFF

#define NVM_SET_BLOCK_LOCK_API                              STD_OFF
#define NVM_IMPLICIT_REC_ROM_DATA                           STD_OFF
#define NVM_SPECIAL_READ_ROM                                STD_OFF
#define NVM_VERSION_CHECK                                   STD_ON
#define NVM_WRITE_PROTECTED_SUPPORT                         STD_OFF
#define NVM_LOW_STATIC_ID_CHECK                             STD_OFF
#define NVM_READ_ROM_BYTES                                  0

#define NVM_CRC_ENABLE                                      STD_OFF
#define NVM_CRC_COMP_ENABLE                                 STD_OFF
#define NVM_REDUNDANT_BLOCK_SUPPORT                         STD_OFF
#define NVM_DATASET_BLOCK_SUPPORT                           STD_OFF
#define NVM_AUTO_READ_RETRY                                 STD_OFF
#define NVM_AUTO_WRITE_RETRY                                STD_OFF
#define NVM_USE_SYNC_MECHANISM                              STD_OFF
#define NVM_WRITE_VER                                       STD_OFF
#define NVM_BLOCKID_CHECK                                   STD_OFF
#define NVM_CRC8_SUPPORT                                    STD_OFF
#define NVM_CRC16_SUPPORT                                   STD_OFF
#define NVM_CRC32_SUPPORT                                   STD_OFF
#define NVM_BSWM_SUPPORT                                    STD_ON
#define NVM_IMM_BLOCK_SUPPORT                               STD_OFF
#define NVM_USE_PORT                                        STD_OFF

#define NVM_CIPHER_ENABLE                                   STD_OFF
#define NVM_COMPRESSION_ENABLE                              STD_OFF
#define NVM_MULTI_CORE_SUPPORT                              STD_OFF
#define NVM_FIRST_INIT_ALL_SUPPORT                          STD_OFF

#define NVM_DEM_SUPPORT                                     STD_OFF
#define NVM_DEM_REPORT_E_INTEGRITY_FAILED(state)
#define NVM_DEM_REPORT_E_LOSS_OF_REDUNDANCY(state)
#define NVM_DEM_REPORT_E_QUEUE_OVERFLOW(state)
#define NVM_DEM_REPORT_E_REQ_FAILED(state)
#define NVM_DEM_REPORT_E_VERIFY_FAILED(state)
#define NVM_DEM_REPORT_E_WRITE_PROTECTED(state)
#define NVM_DEM_REPORT_E_WRONG_BLOCK_ID(state)
#define NVM_DEM_REPORT_E_HARDWARE(state)

#define NVM_SW_MAJOR_VERSION_CFG                            4
#define NVM_SW_MINOR_VERSION_CFG                            2
#define NVM_SW_PATCH_VERSION_CFG                            0
#define NVM_AR_RELEASE_MAJOR_VERSION_CFG                    4
#define NVM_AR_RELEASE_MINOR_VERSION_CFG                    7
#define NVM_AR_RELEASE_REVISION_VERSION_CFG                 0

/*******************************************************************************
*   Blocks Handles
*******************************************************************************/
#define NvM_Block0                                          ((NvM_BlockIdType)0)
#define NvM_Block_CfgID                                     ((NvM_BlockIdType)1)
#define NvM_NVM_PrimaryDataEntry_0_0                        ((NvM_BlockIdType)2)
#define NvM_NVM_PrimaryDataEntry_0_1                        ((NvM_BlockIdType)3)
#define NvM_NVM_PrimaryDataEntry_0_2                        ((NvM_BlockIdType)4)
#define NvM_NVM_PrimaryDataEntry_0_3                        ((NvM_BlockIdType)5)
#define NvM_NVM_PrimaryDataEntry_0_4                        ((NvM_BlockIdType)6)
#define NvM_NVM_PrimaryDataEntry_0_5                        ((NvM_BlockIdType)7)
#define NvM_NVM_PrimaryDataEntry_0_6                        ((NvM_BlockIdType)8)
#define NvM_NVM_PrimaryDataEntry_0_7                        ((NvM_BlockIdType)9)
#define NvM_NVM_PrimaryDataEntry_0_8                        ((NvM_BlockIdType)10)
#define NvM_NVM_PrimaryDataEntry_0_9                        ((NvM_BlockIdType)11)
#define NvM_NVM_PrimaryDataEntry_0_10                       ((NvM_BlockIdType)12)
#define NvM_NVM_PrimaryDataEntry_0_11                       ((NvM_BlockIdType)13)
#define NvM_NVM_PrimaryDataEntry_0_12                       ((NvM_BlockIdType)14)
#define NvM_NVM_PrimaryDataEntry_0_13                       ((NvM_BlockIdType)15)
#define NvM_NVM_PrimaryDataEntry_0_14                       ((NvM_BlockIdType)16)
#define NvM_NVM_PrimaryDataEntry_0_15                       ((NvM_BlockIdType)17)
#define NvM_NVM_PrimaryDataEntry_0_16                       ((NvM_BlockIdType)18)
#define NvM_NVM_PrimaryDataEntry_0_17                       ((NvM_BlockIdType)19)
#define NvM_NVM_PrimaryDataEntry_0_18                       ((NvM_BlockIdType)20)
#define NvM_NVM_PrimaryDataEntry_0_19                       ((NvM_BlockIdType)21)
#define NvM_NVM_Dem_StorageMem                              ((NvM_BlockIdType)22)


/*******************************************************************************
*   Access
*******************************************************************************/
#define NVM_TOTAL_NUM_OF_NVRAM_BLOCKS                       ((NvM_BlockIdType)23)
#define NVM_SIZE_STANDARD_JOB_QUEUE                         ((NvM_QueueSizeType)10)


#endif /* #ifndef NVM_CFG_H */





