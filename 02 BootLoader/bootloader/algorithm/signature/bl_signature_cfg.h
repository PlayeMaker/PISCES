/******************************************************************************************************************//*******************************************
 *
 *  \copyright  This software is the property of HiRain Technologies. Any information contained in this doc should not
 *              be reproduced, or used, or disclosed without the written authorization from HiRain Technologies.
 *
 *  \brief      This is a head file to configure the signature algorithm.
 *
 *  \file       bl_signature_cfg.h
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
#ifndef _BL_SIGNATURE_CFG_H_
#define _BL_SIGNATURE_CFG_H_
#include "bl_security.h"
/**********************************************************************************************************************
 *  QAC Suppression
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Macro Definitions
 *********************************************************************************************************************/

#define SIGN_PKEY_MEMID             (2)
#define SIGN_PKEY_ADDRESS           (0xFC00)
#define SIGN_PKEY_N_LENGTH          (384)
#define SIGN_PKEY_E_LENGTH          (4)
#define SIGN_PKEY_MD_LENGTH         (32)

#define SIGN_PKEY_LENGTH            (SIGN_PKEY_N_LENGTH + SIGN_PKEY_E_LENGTH)
#define SIGN_PKEY_TOTAL_LENGTH      (SIGN_PKEY_LENGTH + SIGN_PKEY_MD_LENGTH)

#define SIGN_PKEY_MD_TYPE           SECM_HASH_SHA256
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

#endif /*_BL_SIGNATURE_CFG_H_*/
