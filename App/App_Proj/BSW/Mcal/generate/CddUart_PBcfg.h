/*
* @file    CddUart_PBcfg.h
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : CddUart_PBcfg
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V0.9.1
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifndef CDDUART_PBCFG_H
#define CDDUART_PBCFG_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                              INCLUDE FILES                                          
==================================================================================================*/
/*==================================================================================================
                                      HHEADER FILE VERSION INFORMATION                                
==================================================================================================*/
#define CDDUART_PBCFG_VENDOR_ID                      (180)
#define CDDUART_PBCFG_AR_RELEASE_MAJOR_VERSION       (4)
#define CDDUART_PBCFG_AR_RELEASE_MINOR_VERSION       (4)
#define CDDUART_PBCFG_AR_RELEASE_REVISION_VERSION    (0)
#define CDDUART_PBCFG_SW_MAJOR_VERSION               (0)
#define CDDUART_PBCFG_SW_MINOR_VERSION               (9)
#define CDDUART_PBCFG_SW_PATCH_VERSION               (1)
/*==================================================================================================
                                                DEFINES AND MACROS                                       
==================================================================================================*/
/*==================================================================================================
                                                EXTERNAL CONSTANTS                                        
==================================================================================================*/
/*==================================================================================================
                                                ENUMS                                        
==================================================================================================*/
/*==================================================================================================
                                                FUNCTION PROTOTYPES                                           
==================================================================================================*/

#define CDDUART_CONFIG_PB \
    extern const CddUart_ConfigType CddUart_Config;

#ifdef __cplusplus
}
#endif

#endif /* End of file CddUart_PBcfg.h */
