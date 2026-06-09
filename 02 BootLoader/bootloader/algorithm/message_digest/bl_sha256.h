/******************************************************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any information contained in this doc should not
 *              be reproduced, or used, or disclosed without the written authorization from HiRain Technologies.
 *
 *  \brief      This is a head file of the SHA256 algorithm.
 *
 *  \file       bl_sha256.h
 *
 *  \author     Tang, Mingqing <mingqing.tang@hirain.com>
 *
 *  \version    6.1.0
 *  \date       16/01/2019
 *
 *  \par        Changelist
 *              Version  | Date       | Authors          | Descriptions
 *              -------- | ---------- | ---------------- | -----------------------
 *              6.0.0    | 07/09/2018 | Tang, Mingqing   | The first version using the new architecture.
 *              6.0.1    | 02/11/2018 | Tang, Mingqing   | Porting SHA-256 algorithm for checking integrity of data.
 *              6.1.0    | 16/01/2019 | Tang, Mingqing   | Implement digital signature and LZSS algorithm.
 *
 *********************************************************************************************************************/
#ifndef _BL_SHA256_H_
#define _BL_SHA256_H_
#include "bl_typedefs.h"
#include "bl_security.h"

/**********************************************************************************************************************
 *  QAC Suppression
 *********************************************************************************************************************/
/*PRQA S EOF*/

/**********************************************************************************************************************
 *  Macro Definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Type Declarations
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Structure Definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  External Global Variable Declarations
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  External Function Prototype Declarations
 *********************************************************************************************************************/
extern void SHA256_Init(void);
extern void* SHA256_AllocContext(void);
extern void SHA256_FreeContext(void *context);
extern void SHA256_Start(void *context);
extern bl_Return_t SHA256_Update(void *context, bl_Size_t size, const bl_Buffer_t *data);
extern bl_Return_t SHA256_Finish(void *context, bl_Size_t size, bl_Buffer_t *buffer);

#endif /*_BL_SHA256_H_*/
