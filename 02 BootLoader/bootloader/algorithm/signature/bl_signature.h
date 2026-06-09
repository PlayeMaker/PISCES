/******************************************************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any information contained in this doc should not
 *              be reproduced, or used, or disclosed without the written authorization from HiRain Technologies.
 *
 *  \brief      This is a head file of the signature algorithm.
 *
 *  \file       bl_signature.h
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
#ifndef _BL_SIGNATURE_H_
#define _BL_SIGNATURE_H_
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
extern void Sign_Init(void);

extern bl_Return_t Sign_VerifySignature(bl_HashId_t id, bl_Size_t hashSize, const bl_Buffer_t *hash,
                                        bl_Size_t signSize, const bl_Buffer_t *signature);

extern bl_Return_t Sign_UpdatePublicKey(const bl_Buffer_t *key, bl_BufferSize_t keySize);

extern bl_Return_t Sign_GetPublicKeyHash(bl_BufferSize_t *hashSize, bl_Buffer_t *hash);

#endif /*_BL_SIGNATURE_H_*/
