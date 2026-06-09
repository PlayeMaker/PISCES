/**
 * @file    CanIf.h
 * @version
 *
 * @brief   AUTOSAR CanIf module interface
 * @details API implementation for CANIF driver
 *
 * @addtogroup CANIF_MODULE
 * @{
 */
/*==================================================================================================
 *   Project              : YTMicro AUTOSAR 4.4.0 MCAL
 *   Platform             : ARM
 *   Peripheral           : CanIf
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

#ifndef CANIF_H
#define CANIF_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section CanIf_PBCfg_C_REF_1
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external 
 			identifiers.
 *
 * @section CanIf_PBCfg_C_REF_2
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be
 *          checked to ensure that 31 character significance and case sensitivity are supported
 *          for external identifiers.
 *          The used compilers/linkers allow more than 31 characters significance for external 
 			identifiers.
 */

/*=================================================================================================
 *                                        INCLUDE FILES
=================================================================================================*/
#include "Std_Types.h"
#include "Can_GeneralTypes.h"

/*==================================================================================================
 *                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_VENDOR_ID                      (180)
#define CANIF_AR_RELEASE_MAJOR_VERSION       (4)
#define CANIF_AR_RELEASE_MINOR_VERSION       (4)
#define CANIF_AR_RELEASE_REVISION_VERSION    (0)
#define CANIF_SW_MAJOR_VERSION               (0)
#define CANIF_SW_MINOR_VERSION               (9)
#define CANIF_SW_PATCH_VERSION               (1)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and CANIF configuration header file are of the same vendor */
#if (CANIF_VENDOR_ID != CANIF_VENDOR_ID_CFG)
/* #error "CanIf.h and CanIf_Cfg.h have different vendor ids" */
#endif

/* Check if source file and CANIF configuration header file are of the same Autosar version */
#if ((CANIF_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (CANIF_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION_CFG) || \
     (CANIF_AR_RELEASE_REVISION_VERSION != CANIF_AR_RELEASE_REVISION_VERSION_CFG))
/*#error "AutoSar Version Numbers of CanIf.h and CanIf_Cfg.h are different" */
#endif

/* Check if source file and CANIF configuration header file are of the same software version */
#if ((CANIF_SW_MAJOR_VERSION != CANIF_SW_MAJOR_VERSION_CFG) || \
     (CANIF_SW_MINOR_VERSION != CANIF_SW_MINOR_VERSION_CFG) || \
     (CANIF_SW_PATCH_VERSION != CANIF_SW_PATCH_VERSION_CFG))
/*#error "Software Version Numbers of CanIf.h and CanIf_Cfg.h are different" */
#endif

/*==================================================================================================
 *                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief CANIF MODULE INSTANCE ID */
#define CANIF_INSTANCE_ID ((uint8)0U)

/** @brief CANIF MODULE ID */
#define CANIF_MODULE_ID ((uint8)Lookup from Doc U)

#if (CANIF_DEV_ERROR_DETECT == STD_ON)
/**
 * @defgroup        CanIf_DEV_ERROR
 * @brief           CANIF development errors
 * @{
 */

/** @brief CANIF API service is called using an invalid pointer 
		(e.g. the pointer should not be NULL).  */

/** @} */
#endif

/*==================================================================================================
 *                                         EXTERNAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                             ENUMS
==================================================================================================*/

/**
 * @brief
 * @note            trace:
 */
typedef enum
{
    CANIF_NO_NOTIFICATION = 0x00, /**<    */
    CANIF_TX_RX_NOTIFICATION = 1, /**<    */
} CanIf_NotifStatusType;

/**
 * @brief
 * @note            trace:
 */
typedef enum
{
    CANIF_OFFLINE = 0x00,           /**<    */
    CANIF_TX_OFFLINE = 0x01,        /**<    */
    CANIF_TX_OFFLINE_ACTIVE = 0x02, /**<    */
    CANIF_ONLINE = 0x03,            /**<    */
} CanIf_PduModeType;

typedef void (*Can_CallbackRecieve)(const void *Mailbox, const void *PduInfoPtr);
extern Can_CallbackRecieve CanRxCallback;


#if (((CANIF_VERSION_INFO_API == STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_ON)))
/**
 * @brief            Returns the version information of this module.
 * @details
 *
 * @param[in]        none
 * @param[out]       versioninfo Pointer to where to store version information of this module
 *
 * @return           none
 */
#define CanIf_GetVersionInfo(versioninfo)                                       \
    {                                                                           \
        /* Check for DET: CANIF_E_PARAM_POINTER */                              \
        if ((versioninfo) == NULL_PTR)                                          \
        {                                                                       \
            /* Report CANIF_E_PARAM_POINTER DET if service called with          \
               NULL_PTR                                                         \
            */                                                                  \
            Det_ReportError(                                                    \
                (uint16)CANIF_MODULE_ID,                                        \
                CANIF_INSTANCE_ID,                                              \
                CANIF_GET_VERSION_INFO_SID,                                     \
                CANIF_E_PARAM_POINTER);                                         \
        }                                                                       \
        else                                                                    \
        {                                                                       \
            /* Vendor ID information */                                         \
            ((Std_VersionInfoType *)(versioninfo))->vendorID = CANIF_VENDOR_ID; \
            /* CanIf module ID information */                                   \
            ((Std_VersionInfoType *)(versioninfo))->moduleID = CANIF_MODULE_ID; \
            /* CanIf module Software major version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_major_version =          \
                (uint8)CANIF_SW_MAJOR_VERSION;                                      \
            /* CanIf module Software minor version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =          \
                (uint8)CANIF_SW_MINOR_VERSION;                                      \
            /* CanIf module Software patch version information */               \
            ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =          \
                (uint8)CANIF_SW_PATCH_VERSION;                                      \
        }                                                                       \
    }
#elif (((CANIF_VERSION_INFO_API == STD_ON) && (CANIF_DEV_ERROR_DETECT == STD_OFF)))
#define CanIf_GetVersionInfo(versioninfo)                                   \
    {                                                                       \
        /* Vendor ID information */                                         \
        ((Std_VersionInfoType *)(versioninfo))->vendorID = CANIF_VENDOR_ID; \
        /* CanIf module ID information */                                   \
        ((Std_VersionInfoType *)(versioninfo))->moduleID = CANIF_MODULE_ID; \
        /* CanIf module Software major version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_major_version =          \
            (uint8)CANIF_SW_MAJOR_VERSION;                                      \
        /* CanIf module Software minor version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_minor_version =          \
            (uint8)CANIF_SW_MINOR_VERSION;                                      \
        /* CanIf module Software patch version information */               \
        ((Std_VersionInfoType *)(versioninfo))->sw_patch_version =          \
            (uint8)CANIF_SW_PATCH_VERSION;                                      \
    }
#endif /* CANIF_VERSION_INFO_API == STD_ON && CANIF_DEV_ERROR_DETECT == STD_ON */

#ifdef __cplusplus
}
#endif

#endif /* CANIF_H */

/** @} */

