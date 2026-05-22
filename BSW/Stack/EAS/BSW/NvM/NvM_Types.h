/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : NvM_Types.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : NvM module type definitions head File
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of Non-Volatile RAM manager.
*
********************************************************************************
*   Limitations     :
*
********************************************************************************
*
********************************************************************************
*   Revision History
*   Reference to NvM.c File
********************************************************************************
* END_FILE_HDR*/

/*PRQA S 778,779 EOF*/
/*
Names in core files may not follow relevant rules..
*/

/*PRQA S 635,3131,750 EOF*/
/*
 a bit-field can only be defined with one of the following types uint8.
*/

#ifndef NVM_TYPES_H
#define NVM_TYPES_H

/*******************************************************************************
    Include Files
*******************************************************************************/
#include "Std_Types.h"
#include "Rte_NvM_Type.h"
#include "NvM_Cfg.h"
#include "NvM_Version.h"
#include "MemIf.h"
#if(STD_ON == NVM_CIPHER_ENABLE)
#include "Crypto_GeneralTypes.h"
#endif
#include "SchM_NvM.h"
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
#include "Bmc.h"
#endif

/*******************************************************************************
*   Macro
*******************************************************************************/
/*NvM_RequestResultType*/
#define NVM_REQ_WRONGID            ((NvM_RequestResultType)10)
#define NVM_REQ_VERIFY_FAILED      ((NvM_RequestResultType)12)
#define NVM_REQ_CFGID_MISMATCH     ((NvM_RequestResultType)13)


/*def Service ID,the service type of function*/
#define NVM_INIT                         ((uint8)0) /* Service ID NvM_Init()              */
#define NVM_SET_DATA_INDEX               ((uint8)1) /* Service ID NvM_SetDataIndex()      */
#define NVM_GET_DATA_INDEX               ((uint8)2) /* Service ID NvM_GetDataIndex()      */
#define NVM_SET_BLOCK_PROTECTION         ((uint8)3) /* Service ID NvM_SetBlockProtection()*/
#define NVM_GET_ERROR_STATUS             ((uint8)4) /* Service ID NvM_GetErrorStatus()    */
#define NVM_SET_RAM_BLOCK_STATUS_APIID   ((uint8)5) /* Service ID NvM_SetRamBlockStatus() */
#define NVM_READ_BLOCK_APIID             ((uint8)6) /* Service ID NvM_ReadBlock()         */
#define NVM_WRITE_BLOCK_APIID            ((uint8)7) /* Service ID NvM_WriteBlock()        */
#define NVM_RESTORE_BLOCK_DEFAULTS_APIID ((uint8)8) /* Service ID NvM_RestoreBlockDefaults()*/
#define NVM_ERASE_BLOCK                  ((uint8)9) /* Service ID NvM_EraseNvBlock()      */
#define NVM_CANCEL_ALL                   ((uint8)10)
#define NVM_INVALIDATE_NV_BLOCK_APIID    ((uint8)11) /* Service ID NvM_InvalidateNvBlock() */
#define NVM_READ_ALL                     ((uint8)12) /* Service ID NvM_ReadAll()           */
#define NVM_WRITE_ALL                    ((uint8)13) /* Service ID NvM_WriteAll()          */
#define NVM_MAINFUNCTION                 ((uint8)14) /* Service ID NvM_MainFunction()      */
#define NVM_GET_VERSION_INFO             ((uint8)15) /* Service ID NvM_GetVersionInfo()    */
#define NVM_CANCEL_JOBS                  ((uint8)16) /* Service ID NvM_CancelJobs()        */
#define NVM_JOB_END_NOTIFICATION         ((uint8)17) /* Service ID */
#define NVM_JOB_ERROR_NOTIFICATION       ((uint8)18) /* Service ID NvM_SetBlockProtection()*/
#define NVM_SET_BLOCK_LOCK_STATUS        ((uint8)19) /* Service ID NvM_SetBlockProtection()*/
#define NVM_FIRSTINIT_ALL                ((uint8)20)
#define NVM_READ_PRAMBLOCK               ((uint8)22)
#define NVM_WRITE_PRAMBLOCK              ((uint8)23)
#define NVM_RESTORE_PRAMBLOCK            ((uint8)24)
#define NVM_VALIDATE_ALL                 ((uint8)25)
#define NVM_SERVICEID_NUM                ((uint8)26) /* MAX ServiceId, used by BswM to check service id*/
#define NVM_NO_SERVICE                   ((uint8)0xFF)
/* internal api id*/
#define NVM_INTERNAL_INITSUBSTATE_APIID          ((uint8)0x90) 
#define NVM_INTERNAL_READPROC_APIID              ((uint8)0x91) 
#define NVM_INTERNAL_WRITEPROC_APIID             ((uint8)0x92) 
#define NVM_INTERNAL_ERASEPROC_APIID             ((uint8)0x93) 
#define NVM_INTERNAL_INVALIDPROC_APIID           ((uint8)0x94) 
#define NVM_INTERNAL_RESTOREPROC_APIID           ((uint8)0x95) 
#define NVM_INTERNAL_SETRAMPROC_APIID            ((uint8)0x96) 
#define NVM_INTERNAL_NOTIFICATION_APIID          ((uint8)0x97) 
#define NVM_INTERNAL_FIRSTINITALLPROC_APIID      ((uint8)0x98) 

/* NvM Asyn Service  */
#define NVM_JOB_IDLE               ((uint8)255)
#define NVM_JOB_READ               NVM_READ_BLOCK_APIID
#define NVM_JOB_WRITE              NVM_WRITE_BLOCK_APIID
#define NVM_JOB_RESTORE            NVM_RESTORE_BLOCK_DEFAULTS_APIID
#define NVM_JOB_SET_RAMSTA         NVM_SET_RAM_BLOCK_STATUS_APIID
#define NVM_JOB_READALL            NVM_READ_ALL
#define NVM_JOB_WRITEALL           NVM_WRITE_ALL
#define NVM_JOB_ERASE              NVM_ERASE_BLOCK
#define NVM_JOB_INVALID            NVM_INVALIDATE_NV_BLOCK_APIID
#define NVM_JOB_VALIDATEALL        NVM_VALIDATE_ALL
#define NVM_JOB_READ_PRAMBLOCK     NVM_READ_PRAMBLOCK
#define NVM_JOB_WRITE_PRAMBLOCK    NVM_WRITE_PRAMBLOCK
#define NVM_JOB_RESTORE_PRAMBLOCK  NVM_RESTORE_PRAMBLOCK
#define NVM_JOB_FIRSTINITALL       NVM_FIRSTINIT_ALL






#define NVM_PROCESS_NORAM_BLOCK       ((uint8)0)
#define NVM_PROCESS_TEMP_RAM_BLOCK    ((uint8)1)
#define NVM_PROCESS_PER_RAM_BLOCK     ((uint8)2)
#define NVM_PROCESS_SYN_RAM_BLOCK     ((uint8)3)

#define NVM_CONFIG_NO_PERRAM          ((uint8)0)
#define NVM_CONFIG_PERRAM             ((uint8)1)
#define NVM_CONFIG_SYN_PERRAM         ((uint8)2)



#define NVM_NULL   NULL_PTR

#define NVM_API_CONFIG_CLASS_1  1
#define NVM_API_CONFIG_CLASS_2  2
#define NVM_API_CONFIG_CLASS_3  3

#define NVM_CRC8   ((uint16)0x1)
#define NVM_CRC16  ((uint16)0x2)
#define NVM_CRC32  ((uint16)0x4)
#define NVM_QUE_INVALID_POS     ((NvM_QueueSizeType)0xFFFF)
#define NVM_INVALID_BLOCKID     ((NvM_BlockIdType)0xFFFF)

#define NVM_BLOCKID_BYTES       ((uint16)2)

/*******************************************************************************
*   Typedef
*******************************************************************************/
typedef uint16 NvM_QueueSizeType;
/* SWS_NvM_00880 , TBD type */
typedef uint8  NvM_ConfigType;


typedef uint16 NvM_BlockCipherIdType;



typedef uint8 NvM_MultiBlockRequestType;



/* Block Management Type NVM137*/
typedef enum
{
    NVM_BLOCK_NATIVE    = 0,
    NVM_BLOCK_REDUNDANT = 1,
    NVM_BLOCK_DATASET   = 2
} NvM_BlockManagementType;

#if(STD_ON == NVM_COMPRESSION_ENABLE)
typedef struct
{
    uint16  CompressionLength;
    P2VAR(uint8, TYPEDEF, TYPEDEF) CompressionBuffer;
} NvM_BlockCompressionConfigType;
#endif

#if(STD_ON == NVM_CIPHER_ENABLE)
/* struct NvM_ConfigType,Link-time Configuration */
typedef struct
{
    uint16  Length;                             /*NvMNvBlockNVRAMDataLength*/
    uint32  DecryptionJobId;                    /*NvMCsmDecryptionJobId*/
    uint32  EncryptionJobId;                    /*NvMCsmEncryptionJobId*/
} NvM_BlockCipherConfigType;
#endif

/* struct NvM_ConfigType,Link-time Configuration */
typedef struct
{
    P2VAR(uint8, TYPEDEF, TYPEDEF) RamAddr;     /**<RAM Mapping Address NVM482_Conf */
    P2CONST(uint8, TYPEDEF, TYPEDEF) RomAddr;     /**<ROM Address(Default Value) NVM484_Conf */
    NvM_BlockManagementType BlockType;          /*NVM062_Conf*/
    uint16  Length;                             /*NVM479_Conf*/
    NvM_BlockIdType  BaseNumber;                         /*NVM478_Conf*/
    uint8   DeviceId;                           /*NVM035_Conf*/
    uint8   NvBlockNum;                         /*NVM480_Conf*/
    uint8   BlockPri;                           /*NVM477_Conf job priority*/
    boolean EnReadAll;                          /*NVM117_Conf*/
    boolean EnWriteAll;                         /*NVM549_Conf*/

#if (NVM_API_CONFIG_CLASS == NVM_API_CONFIG_CLASS_3)
    boolean EnFirstInitAll;
#endif
#if(STD_ON == NVM_BSWM_SUPPORT)
    boolean EnReportBswM;                       /*NVM551_Conf*/
#endif

#if(STD_ON == NVM_CRC_ENABLE)
    boolean EnCrc;                              /*NVM036_Conf  NVM119_Conf*/
    uint16  CrcType;                            /*NVM476_Conf*/
#if(STD_ON == NVM_CRC_COMP_ENABLE)
    boolean  UseCRCCompMechanism;                /*NVM556_Conf*/
    P2VAR(uint8, TYPEDEF, TYPEDEF) CRCCompAddr;
#endif
#endif

#if(STD_ON == NVM_DATASET_BLOCK_SUPPORT)
    uint8   RomBlockNum;                        /*NVM485_Conf*/
#endif

#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
    boolean   EnWriteOnce;                      /*NVM072_Conf*/
    boolean   InitWriteProt;                    /*NVM033_Conf*/
#endif

#if(STD_ON == NVM_WRITE_VER)
    boolean EnVer;                              /*NVM534_Conf */
    uint16  MaxVerNum;                          /*NVM538_Conf*/
#endif

#if(STD_ON == NVM_BLOCKID_CHECK)
    boolean EnIdCheck;                          /*NVM532_Conf*/
#endif

#if(STD_ON == NVM_AUTO_READ_RETRY)
    uint8   MaxReReadNum;                       /*NVM533_Conf */
#endif

#if(STD_ON == NVM_AUTO_WRITE_RETRY)
    uint8   MaxReWriteNum;                      /*NVM499_Conf */
#endif

#if(STD_ON == NVM_USE_SYNC_MECHANISM)
    boolean EnUseSynM;                          /*NVM519_Conf */
#endif

#if(STD_ON == NVM_DYNAMIC_CONFIGURATION)
    boolean EnResistChged;                      /*NVM483_Conf*/
#endif

    boolean UseSetRamBlockStatus;               /*NVM552_Conf*/
    boolean AutoValidation;                     /*NVM557_Conf*/
#if(STD_ON == NVM_MULTI_CORE_SUPPORT)
    uint8 LogicCoreId;
    uint8 PhyCoreId;
    NvM_BlockIdType AgentJobIndex;
    NvM_BlockIdType AgentBackJobIndex;
#endif

#if(STD_ON == NVM_CIPHER_ENABLE)
	boolean EnCipher;                          /*NVM567_Conf */
	P2CONST(NvM_BlockCipherConfigType, TYPEDEF, NVM_CONST)    NvM_Cipher;
    P2VAR(uint8, TYPEDEF, TYPEDEF) CipherBuffer;
#endif

#if(STD_ON == NVM_COMPRESSION_ENABLE)
	boolean EnCompression;                          /*NVM563_Conf */
    P2CONST(NvM_BlockCompressionConfigType, TYPEDEF, NVM_CONST)    NvM_Compression;
#endif

#if(STD_ON == NVM_USE_PORT)
	boolean EnUsePort;                          /*NVM567_Conf */
#endif
} NvM_BlockConfigType;



/* NvM module main state */
typedef enum
{
    NVM_STATE_UNINIT      = 0, /* NvM not init    */
    NVM_STATE_IDLE        = 1, /* NvM Idle        */
    NVM_STATE_BUSY        = 2  /* NvM Busy        */
} NvM_State_Type;


/* NvM Asyn Job Queue  */
typedef struct
{
    NvM_BlockIdType       BlockId;
    uint8                 ServiceId;
    /* used to save the single block job's ram addr*/
    P2VAR(uint8, TYPEDEF, TYPEDEF) RamAddr;
} NvM_QueBuf_Type;


typedef struct
{
    NvM_QueueSizeType                 Header;
    NvM_QueueSizeType                 Tail;
} NvM_Que_Type;


/* NvM Asyn Job sub State  */
typedef enum
{
    NVM_SUBSTATE_IDLE,
    NVM_SUBSTATE_READ_DATA,
    NVM_SUBSTATE_READDATA_WAIT,
    NVM_SUBSTATE_READDATA_WAIT_IND,
    NVM_SUBSTATE_READ_DECOMPRESSION,
    NVM_SUBSTATE_READ_CALCRC,
    NVM_SUBSTATE_READ_DECRYPT,
    NVM_SUBSTATE_READ_DECRYPT_WAIT,
    NVM_SUBSTATE_READ_PREEND,/* data ok or fail , decide dem and imp restore*/


    NVM_SUBSTATE_READ_RESTORE,
    NVM_SUBSTATE_READ_RESTORE_USER,
    NVM_SUBSTATE_READ_RESTORECRC,
    NVM_SUBSTATE_READ_SYN,
    NVM_SUBSTATE_READ_END,


    NVM_SUBSTATE_RESTOREDATA,
    NVM_SUBSTATE_RESTORE_USER, /* restore from user cbk */
    NVM_SUBSTATE_RESTORE_ROMADDR, /* restore from romaddr */
    NVM_SUBSTATE_RESTORECRC,
    NVM_SUBSTATE_RESTORE_ROMBLOCK,  /* restore from rom block of dataset block */
    NVM_SUBSTATE_RESTORE_READ_WAIT,
    NVM_SUBSTATE_RESTORE_READ_WAIT_IND,
    NVM_SUBSTATE_RESTOREDATA_SYN,
    NVM_SUBSTATE_RESTOREDATA_END,

    NVM_SUBSTATE_WRITE_ENCRYPT,
    NVM_SUBSTATE_WRITE_ENCRYPT_WAIT,
    NVM_SUBSTATE_WRITE_ENCRYPT_END,
    NVM_SUBSTATE_WRITE_CALCRC,
    NVM_SUBSTATE_WRITE_COMPRESSION,
    NVM_SUBSTATE_WRITE_DATA,
    NVM_SUBSTATE_WRITE_WAIT,
    NVM_SUBSTATE_WRITE_WAIT_IND,
    NVM_SUBSTATE_WRITE_VER,
    NVM_SUBSTATE_WRITE_VER_WAIT,
    NVM_SUBSTATE_WRITE_VER_WAIT_IND,
    NVM_SUBSTATE_WRITE_SYN,
    NVM_SUBSTATE_WRITE_END,


    NVM_SUBSTATE_SETRAM_SYN_READIN,
    NVM_SUBSTATE_SETRAM_CRC,
    NVM_SUBSTATE_SETRAM_SYN_WRITEOUT,
    NVM_SUBSTATE_SETRAM_END,

    NVM_SUBSTATE_ERASE,
    NVM_SUBSTATE_ERASE_WAIT,
    NVM_SUBSTATE_ERASE_WAIT_IND,
    NVM_SUBSTATE_ERASE_END,

    NVM_SUBSTATE_INVALID,
    NVM_SUBSTATE_INVALID_WAIT,
    NVM_SUBSTATE_INVALID_WAIT_IND,
    NVM_SUBSTATE_INVALID_END,

    NVM_SUBSTATE_READALL,
    NVM_SUBSTATE_READALL_PRECRC,
    NVM_SUBSTATE_READALL_PRECRC_READIN,


    NVM_SUBSTATE_WRITEALL,
    NVM_SUBSTATE_WRITEALL_WAIT_LOWIDLE,
    
    NVM_SUBSTATE_VALIDATEDALL,
    NVM_SUBSTATE_VALIDATE_CRC,

    NVM_SUBSTATE_FIRSTINITALL,
    NVM_SUBSTATE_FIRSTINITALL_RESTORE_USER, /* restore from user cbk */
    NVM_SUBSTATE_FIRSTINITALL_RESTORE_ROMADDR, /* restore from romaddr */
    NVM_SUBSTATE_FIRSTINITALL_RESTORECRC,
    NVM_SUBSTATE_FIRSTINITALL_RESTOREDATA_SYN,
    NVM_SUBSTATE_FIRSTINITALL_RESTOREDATA_END,
    NVM_SUBSTATE_FIRSTINITALL_WRITE_DATA,
    NVM_SUBSTATE_FIRSTINITALL_WRITE_WAIT,
    NVM_SUBSTATE_FIRSTINITALL_WRITE_WAIT_IND,
    NVM_SUBSTATE_FIRSTINITALL_WRITE_END,
    NVM_SUBSTATE_FIRSTINITALL_INVALID,
    NVM_SUBSTATE_FIRSTINITALL_INVALID_WAIT,
    NVM_SUBSTATE_FIRSTINITALL_INVALID_WAIT_IND,
    NVM_SUBSTATE_FIRSTINITALL_INVALID_END,
    NVM_SUBSTATE_FIRSTINITALL_END
   
} NvM_JobSubState_Type;


/* NvM Per Ram Status Enum  NVM054*/
typedef struct
{
    boolean  NvValid          : 1;
    boolean  NvChanged        : 1;
#if(STD_ON == NVM_WRITE_PROTECTED_SUPPORT)
    boolean  NvWriteProtect : 1;
    boolean  NvWriteOnceReadFirst :1;
#else
    boolean  res1           : 1;
    boolean  res2           : 1;
#endif

#if(STD_ON == NVM_SET_BLOCK_LOCK_API)
    boolean  NvBlockLock    : 1;
#else
    boolean  res3           : 1;
#endif

#if(STD_ON == NVM_REDUNDANT_BLOCK_SUPPORT)
    boolean  lossRedundant  : 1;
#else
    boolean  res4           : 1;
#endif
    uint8    unused         : 2;
} NvM_AttriStruct_Type;


typedef union
{
    uint8                AttriByte;
    NvM_AttriStruct_Type A;
} NvM_Attri_Type;


/* NvM Management Ram Block Type NVM134 NVM136 NVM144*/
typedef struct
{
    NvM_RequestResultType  NvErrStatus;
    NvM_RequestResultType  multiNvErrStatus;/* used to save multi job result*/
    NvM_Attri_Type         NvRamAttributes;
#if((STD_CONFIG_VARIANTS_PRECOMPILE != NVM_CONFIG_VARIANTS) || (NVM_DATASET_SELECTION_BITS > 0))
    uint8                  NvDataIndex;
#endif

} NvM_RamBlock_Type;

/* NvM Callback Type*/
typedef Std_ReturnType (*NvM_MultiCallBackFun)
(NvM_MultiBlockRequestType ServiceId, NvM_RequestResultType JobResult);
typedef Std_ReturnType (*NvM_SingleCallBackFun)/*NVM506_Conf*/
(NvM_BlockRequestType BlockRequest, NvM_RequestResultType JobResult);


typedef Std_ReturnType (*NvM_InitBlockCallBackFun)(NvM_InitBlockRequestType InitBlockRequest);/*NVM116_Conf*/


typedef Std_ReturnType (*NvM_WriteRamBlockToNvmFun)(P2VAR(void, TYPEDEF, TYPEDEF) NvMBuffer);/*NVM539*/

typedef Std_ReturnType (*NvM_ReadRamBlockFromNvmFun)(P2CONST(void, TYPEDEF, TYPEDEF) NvMBuffer);/*NVM540*/

/*******************************************************************************
*   Multi Core Type
*******************************************************************************/
typedef struct
{
    NvM_BlockIdType BlockId;
    CONSTP2VAR(uint8, TYPEDEF, NVM_VAR) BackServiceFlagPtr;
    CONSTP2VAR(NvM_RequestResultType, TYPEDEF, NVM_VAR) BackResultPtr;
} NvM_AgentBackJobInfoType;

typedef struct
{
    NvM_BlockIdType BlockId;
    CONSTP2VAR(uint8, TYPEDEF, NVM_VAR) ServiceFlagPtr;
} NvM_AgentJobInfoType;

typedef struct
{
    NvM_BlockIdType BlockId;
    uint8 ServiceId;
    uint8 AgentCmd;
    NvM_RequestResultType Result;
    NvM_InitBlockRequestType InitReq;
    P2VAR(uint8, TYPEDEF, TYPEDEF) RamAddr;
    uint8 CmdRunState;
    Std_ReturnType CmdResult;
} NvM_AgentBackBufType;

/*******************************************************************************
*   DET & DEM error code
*******************************************************************************/
/*define DEM EventId in cfg.h*/


/*define DET EventId*/
#define NVM_E_NO_ERROR                   ((uint8)0x0U)

#define NVM_E_UNINIT                     ((uint8)0x14U)

#define NVM_E_BLOCK_PENDING              ((uint8)0x15U)
#define NVM_E_BLOCK_CONFIG               ((uint8)0x18U)
#define NVM_E_PARAM_BLOCK_ID             ((uint8)0x0AU)
#define NVM_E_PARAM_BLOCK_TYPE           ((uint8)0x0BU)
#define NVM_E_PARAM_BLOCK_DATA_IDX       ((uint8)0x0CU)
#define NVM_E_PARAM_ADDRESS              ((uint8)0x0DU)
#define NVM_E_PARAM_DATA                 ((uint8)0x0EU)
#define NVM_E_PARAM_POINTER              ((uint8)0x0FU)
#define NVM_E_BLOCK_WITHOUT_DEFAULTS     ((uint8)0x11U)


#define NVM_E_BLOCK_LOCKED               ((uint8)0x19U)
#define NVM_E_WRITE_ONCE_STATUS_UNKNOWN  ((uint8)0x1AU) 

#define NVM_E_BLOCK_CHIPHER_LENGTH_MISSMATCH  ((uint8)0x1BU)

#define NVM_E_WRITE_PROTECTED_DET        ((uint8)0x90U) /* only use when dem is off */
#define NVM_E_QUEUE_FULL                 ((uint8)0xA0U) /* only use when dem is off */
#define NVM_E_UNEXPECTED_CASE            ((uint8)0x92U) 
#define NVM_E_CORE_LIMIT                 ((uint8)0x93U) 
#define NVM_E_AGENT_BUF_FULL             ((uint8)0xA1U)

#endif /* #ifndef _NVM_TYPES_H */


