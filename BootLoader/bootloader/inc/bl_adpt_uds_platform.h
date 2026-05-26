/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is the head file of the adapter module based on uds
 *              platform.
 *
 *  \file       bl_adpt_uds_platform.h
 *  \ingroup    communication_adapter_module
 *  \author     heli.zhang <heli.zhang@hirain.com>
 *
 *  \version    5.7.0
 *  \date       25/06/2021
 *
 *  \par        Changelist
 *      Version  | Date       | Authors          | CR# | Descriptions
 *      -------- | ---------- | ---------------- | --- | ------------
 *      03.00.00 | 12/09/2011 | mingqing.tang    | N/A | Boot030001
 *      03.02.00 | 27/09/2011 | mingqing.tang    | N/A | Boot030003
 *      03.03.00 | 29/09/2011 | mingqing.tang    | N/A | Boot030004
 *      03.05.00 | 12/10/2011 | mingqing.tang    | N/A | Boot030006
 *      04.00.00 | 10/07/2012 | mingqing.tang    | N/A | Boot040001
 *      04.02.00 | 15/07/2012 | mingqing.tang    | N/A | Boot040003
 *      04.04.00 | 18/07/2012 | mingqing.tang    | N/A | Boot040005
 *      04.06.00 | 31/07/2012 | mingqing.tang    | N/A | Boot040007
 *      04.10.00 | 07/08/2012 | mingqing.tang    | N/A | Boot040011
 *      04.11.00 | 15/08/2012 | mingqing.tang    | N/A | Boot040012
 *      05.00.00 | 19/06/2013 | heli.zhang       | N/A | Boot050001
 *      05.01.00 | 27/03/2014 | mingqing.tang    | N/A | Boot050002
 *
 *****************************************************************************/
#ifndef _BL_ADPT_UDS_PLATFORM_H_
#define _BL_ADPT_UDS_PLATFORM_H_
#include "bl_typedefs.h"
#include "bl_adapter.h"

/*****************************************************************************
 *  QAC Suppression
 *****************************************************************************/
/*PRQA S 3210,3447,4152 EOF*/
/*
 * 3210:The global identifier is declared but is not used.
 * The functions are used in the bl_dcm_cfg.c file.
 * The g_UdsPlatformAdapter is used in the bl_process_driver_cfg.c file.
 *
 * MISRA-C:2004 8.8(3447):The identifier has external linkage but this
 * declaration is not in a header file.
 * The function Declarations are in the header file.
 *
 * 4152:The identifier may cause confusion.
 * Adpt_UdsCallbackGetSeedForLevel1 is LEVEL One.
 * Adpt_UdsCallbackVerifyKeyForLevel1 is LEVEL One.
 *
 */

/*****************************************************************************
 *  Macro Definitions
 *****************************************************************************/
#define CHECKPROGRAMCOD_SUCCESS             ((bl_u8_t)1)
#define CHECKPROGRAMCOD_NONE_SUCCESS        ((bl_u8_t)0)
/*****************************************************************************
 *  Type Declarations
 *****************************************************************************/

/*****************************************************************************
 *  Structure Definitions
 *****************************************************************************/

/*****************************************************************************
 *  External Global Variable Declarations
 *****************************************************************************/
/** \brief A adapter for uds platform spec*/
extern const bl_Adapter_t g_UdsPlatformAdapter;
extern bl_u8_t CheckProgramCondflag;
extern bl_u8_t serviceid;
/*****************************************************************************
 *  External Function Prototype Declarations
 *****************************************************************************/
/** \brief Initialize the uds module.*/
extern bl_Return_t Adpt_UdsInit(void);
/** \brief Periodic callback of the adapter.*/
extern void Adpt_UdsPeriodicCallback(void);
/** \brief Callback of the adapter.*/
extern void Adpt_UdsCallback(void);
/** \brief Callback of default session.*/
extern bl_ResponseCode_t Adpt_UdsCallback1001(bl_BufferSize_t size,
                                              bl_Buffer_t *buffer,
                                              bl_BufferSize_t *respSize);
/** \brief Callback of programming session.*/
extern bl_ResponseCode_t Adpt_UdsCallback1002(bl_BufferSize_t size,
                                              bl_Buffer_t *buffer,
                                              bl_BufferSize_t *respSize);
/** \brief Callback of extended session.*/
extern bl_ResponseCode_t Adpt_UdsCallback1003(bl_BufferSize_t size,
                                              bl_Buffer_t *buffer,
                                              bl_BufferSize_t *respSize);
/** \brief Callback of reset.*/
extern bl_ResponseCode_t Adpt_UdsCallback1101(bl_BufferSize_t size,
                                              bl_Buffer_t *buffer,
                                              bl_BufferSize_t *respSize);
                                              /** \brief Callback of reset.*/
extern bl_ResponseCode_t Adpt_UdsCallback1103(bl_BufferSize_t size,
                                              bl_Buffer_t *buffer,
                                              bl_BufferSize_t *respSize);
/** \brief Callback of reading fingerprint.*/
extern bl_ResponseCode_t Adpt_UdsCallBackReadFingerprint(bl_BufferSize_t size,
                                                     bl_Buffer_t *buffer,
                                                     bl_BufferSize_t *respSize);
/** \brief Callback of reading 0xF110.*/
extern bl_ResponseCode_t Adpt_UdsCallBackReadF110(bl_BufferSize_t size,
                                                     bl_Buffer_t *buffer,
                                                     bl_BufferSize_t *respSize);
/** \brief Callback of reading 0xF111.*/
extern bl_ResponseCode_t Adpt_UdsCallBackReadF111(bl_BufferSize_t size,
                                                     bl_Buffer_t *buffer,
                                                     bl_BufferSize_t *respSize);
/** \brief Callback of reading 0xF186.*/
extern bl_ResponseCode_t Adpt_UdsCallBackReadActiveDiagnosticSession(bl_BufferSize_t size,
                                                     bl_Buffer_t *buffer,
                                                     bl_BufferSize_t *respSize);
/** \brief Callback of reading 0xF150.*/
extern bl_ResponseCode_t Adpt_UdsCallBackReadF150(bl_BufferSize_t size,
                                                     bl_Buffer_t *buffer,
                                                     bl_BufferSize_t *respSize);
/** \brief Callback of reading 0xF010.*/
extern bl_ResponseCode_t Adpt_UdsCallBackReadF010(bl_BufferSize_t size,
                                                     bl_Buffer_t *buffer,
                                                     bl_BufferSize_t *respSize);
/** \brief Callback of reading 0xF18E.*/
extern bl_ResponseCode_t Adpt_UdsCallBackReadF18E(bl_BufferSize_t size,
                                                     bl_Buffer_t *buffer,
                                                     bl_BufferSize_t *respSize);
/** \brief Callback of getting seed.*/
extern bl_ResponseCode_t Adpt_UdsCallbackGetSeedForLevel1(bl_BufferSize_t size,
                                                     bl_Buffer_t *buffer,
                                                     bl_BufferSize_t *respSize);
/** \brief Callback of verifying key.*/
extern bl_ResponseCode_t Adpt_UdsCallbackVerifyKeyForLevel1(bl_BufferSize_t size,
                                                     bl_Buffer_t *buffer,
                                                     bl_BufferSize_t *respSize);
/** \brief Callback of enable or disable communication.*/
extern bl_ResponseCode_t Adpt_UdsCallback28(bl_BufferSize_t size,
                                              bl_Buffer_t *buffer,
                                              bl_BufferSize_t *respSize);
/** \brief Callback of writting fingerprint.*/
extern bl_ResponseCode_t Adpt_UdsCallBackWriteFingerprint(bl_BufferSize_t size,
                                                     bl_Buffer_t *buffer,
                                                     bl_BufferSize_t *respSize);
/** \brief Callback of writting DID F010.*/
extern bl_ResponseCode_t Adpt_UdsCallBackWriteF010(bl_BufferSize_t size,
                                                     bl_Buffer_t *buffer,
                                                     bl_BufferSize_t *respSize);
/** \brief Callback of writting programming date.*/
extern bl_ResponseCode_t Adpt_UdsCallbackWriteProgramDate(bl_BufferSize_t size,
                                                     bl_Buffer_t *buffer,
                                                     bl_BufferSize_t *respSize);
/** \brief Callback of checking programming contiditions.*/
extern bl_ResponseCode_t Adpt_UdsCallbackCheckProgramCond(bl_BufferSize_t size,
                                                     bl_Buffer_t *buffer,
                                                     bl_BufferSize_t *respSize);
/** \brief Callback of erasing memory.*/
extern bl_ResponseCode_t Adpt_UdsCallbackEraseMemory(bl_BufferSize_t size,
                                                     bl_Buffer_t *buffer,
                                                     bl_BufferSize_t *respSize);
extern bl_ResponseCode_t Adpt_UdsCallbackStopEraseMemory(bl_BufferSize_t size,
                                                     bl_Buffer_t *buffer,
                                                     bl_BufferSize_t *respSize);
extern bl_ResponseCode_t Adpt_UdsCallbackQueryEraseMemory(bl_BufferSize_t size,
                                                     bl_Buffer_t *buffer,
                                                     bl_BufferSize_t *respSize);
/** \brief Callback of checksum.*/
extern bl_ResponseCode_t Adpt_UdsCallbackCheckSum(bl_BufferSize_t size,
                                                  bl_Buffer_t *buffer,
                                                  bl_BufferSize_t *respSize);

/** \brief Callback of checking compatibility.*/
extern bl_ResponseCode_t Adpt_UdsCallbackCheckCompatibility(bl_BufferSize_t size,
                                                     bl_Buffer_t *buffer,
                                                     bl_BufferSize_t *respSize);

/** \brief Callback of stayinboot.*/
extern bl_ResponseCode_t Adpt_UdsCallbackStayInBoot(bl_BufferSize_t size,
                                                    bl_Buffer_t *buffer,
                                                    bl_BufferSize_t *respSize);
/** \brief Callback of requesting download.*/
extern bl_ResponseCode_t Adpt_UdsCallback34(bl_BufferSize_t size,
                                            bl_Buffer_t *buffer,
                                            bl_BufferSize_t *respSize);
/** \brief Callback of transferring data.*/
extern bl_ResponseCode_t Adpt_UdsCallback36(bl_BufferSize_t size,
                                            bl_Buffer_t *buffer,
                                            bl_BufferSize_t *respSize);
/** \brief Callback of requesting transfer exit.*/
extern bl_ResponseCode_t Adpt_UdsCallback37(bl_BufferSize_t size,
                                            bl_Buffer_t *buffer,
                                            bl_BufferSize_t *respSize);
/** \brief Callback of keeping session.*/
extern bl_ResponseCode_t Adpt_UdsCallback3E(bl_BufferSize_t size,
                                            bl_Buffer_t *buffer,
                                            bl_BufferSize_t *respSize);
/** \brief Callback of switching on or off dtc.*/
extern bl_ResponseCode_t Adpt_UdsCallback85(bl_BufferSize_t size,
                                            bl_Buffer_t *buffer,
                                            bl_BufferSize_t *respSize);
/** \brief Callback of Backup APP.*/
extern bl_ResponseCode_t Backup_Callback(bl_Address_t address, bl_Size_t size);
/** \brief Callback of timeout.*/
extern void Adpt_UdsTimeOutCallBack(void);
/** \brief Callback is used when the reprogramming Flag is valid.*/
extern void Adpt_ReprogramValidProcess(void);
/** \brief Callback is used when the reset Flag is valid.*/
extern void Adpt_SystemResetProcess(void);
extern bl_Buffer_t diagnostic_session_state;
extern bl_u8_t reprogrammingflag; 
extern bl_u8_t routinefaliedflag; 
#if (RTE_FUN_STAY_IN_BOOT == BL_FUN_ON)
/** \brief Callback is used when the application is valid.*/
extern void Adpt_AppValidProcess(void);
#endif
/** \brief Timeout callback of sending 0x78.*/
extern void _Adpt_TimeOutCallBack(bl_u8_t id);
#endif

