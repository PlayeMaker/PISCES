/**
 * @file    Fee_Cbk.h
 * @version V0.9.1
 *
 * @brief   AUTOSAR Fee module call back interface
 * @details API implementation for FEE call back
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

#ifndef FEE_CBK_H
#define FEE_CBK_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FEE_CBK_VENDOR_ID                      (180)
#define FEE_CBK_AR_RELEASE_MAJOR_VERSION       (4)
#define FEE_CBK_AR_RELEASE_MINOR_VERSION       (4)
#define FEE_CBK_AR_RELEASE_REVISION_VERSION    (0)
#define FEE_CBK_SW_MAJOR_VERSION               (0)
#define FEE_CBK_SW_MINOR_VERSION               (9)
#define FEE_CBK_SW_PATCH_VERSION               (1)

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

extern void Fee_JobEndNotification(void);
extern void Fee_JobErrorNotification(void);

#ifdef __cplusplus
}
#endif

#endif /* _FEE_CBK_H_ */

/** @} */

