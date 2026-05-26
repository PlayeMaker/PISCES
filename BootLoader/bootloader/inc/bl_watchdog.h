/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is the header file of the watchdog module for xep100.
 *
 *  \file       bl_watchdog.h
 *  \ingroup    driver_module
 *  \author     sijia.hao <sijia.hao@hirain.com>
 *
 *  \version    1.2.0
 *  \date       05/08/2013
 *
 *  \par        Changelist
 *      Version  | Date       | Authors          | CR# | Descriptions
 *      -------- | ---------- | ---------------- | --- | -------------
 *      01.00.00 | 17/03/2010 | he.yang          | N/A | BootDrv010001
 *      01.01.00 | 21/02/2011 | ning.chen        | N/A | BootDrv010002
 *      01.02.00 | 05/08/2013 | sijia.hao        | N/A | BootDrv010003
 *
 *****************************************************************************/
#ifndef _BL_WATCHDOG_H_
#define _BL_WATCHDOG_H_
#include "bl_typedefs.h"

/*****************************************************************************
 *  QAC Suppression
 *****************************************************************************/
/*PRQA S 3205,3210,3447,3448 EOF*/
/*
 * 3205:The identifier is not used and could be removed.
 * The bl_Adapter_t is used by the specifically adapter such as UDS platform in
 * the bl_adpt_uds_platform.c
 *
 * 3210:The global identifier is declared but is not used.
 * The functions are used in the bl_security_cfg.c file.
 *
 * MISRA-C:2004 8.8(3447):The identifier has external linkage but this
 * declaration is not in a header file.
 * The function Declarations are in the header file.
 *
 * MISRA-C:2004 5.3(3448):Declaration of typedef is not in a header file.
 * The bl_SecurityDelay_t is declared in the header file.
 *
 */
/*****************************************************************************
 *  Macro Definitions
 *****************************************************************************/
#define SWT_IP_MAP_MASK_U32  (0xFF000000U)
#define SWT_IP_MAP_SHIFT  (24U)
#define SWT_IP_MAP(x)  (((bl_u32_t)(((bl_u32_t)(x)) << SWT_IP_MAP_SHIFT)) & SWT_IP_MAP_MASK_U32)

#define SWT_IP_UNLOCK_VALUE1_U16  (0xC520U)
#define SWT_IP_UNLOCK_VALUE2_U16  (0xD928U)

#define SWT_IP_FIXED_SERVICE_VALUE1_U16  (0xA602U)
#define SWT_IP_FIXED_SERVICE_VALUE2_U16  (0xB480U)

/**
* @brief  The reset value of the control register
*/
#define SWT_IP_CR_RESET_VALUE_U32  (0xFF00010AU)
/**
* @brief  The reset value of the timeout register
*/
#define SWT_IP_TO_RESET_VALUE_U32  (0x00000320U)
/**
* @brief  The reset value of the window register
*/
#define SWT_IP_WN_RESET_VALUE_U32  (0x00000000U)
/**
* @brief  The reset value of the service key register
*/
#define SWT_IP_SK_RESET_VALUE_U16  (0x0000U)

#define SWT0_IRQn_WATCH             42
/*****************************************************************************
 *  External Function Prototype Declarations
 *****************************************************************************/
extern void Wdg_Init(void);
extern void Wdg_Feed(void);
extern void Wdg_Deinit(void);
extern void Wdg_FastReset(void);
extern void Wdg_disable(void);

#endif
