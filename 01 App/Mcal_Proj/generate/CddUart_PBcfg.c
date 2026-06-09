/**
* @file    CddUart_PBcfg.c
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

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
                                              INCLUDE FILES                                          
==================================================================================================*/
#include "CddUart.h"
#include "CddUart_PBcfg.h"
/*==================================================================================================
                                      SOURCE FILE VERSION INFORMATION                                
==================================================================================================*/
#define CDDUART_PBCFG_VENDOR_ID_C                      (180)
#define CDDUART_PBCFG_AR_RELEASE_MAJOR_VERSION_C       (4)
#define CDDUART_PBCFG_AR_RELEASE_MINOR_VERSION_C       (4)
#define CDDUART_PBCFG_AR_RELEASE_REVISION_VERSION_C    (0)
#define CDDUART_PBCFG_SW_MAJOR_VERSION_C               (0)
#define CDDUART_PBCFG_SW_MINOR_VERSION_C               (9)
#define CDDUART_PBCFG_SW_PATCH_VERSION_C               (1)
/*==================================================================================================
                                            FILE VERSION CHECKS                                      
==================================================================================================*/
/* Check if source file and CDDUART_PBCFG header file are of the same vendor */
#if (CDDUART_PBCFG_VENDOR_ID_C != CDDUART_PBCFG_VENDOR_ID)
#error "CddUart_PBcfg.c and CddUart_PBcfg.h have different vendor ids"
#endif

/* Check if source file and CDDUART_PBCFG header file are of the same Autosar version */
#if (( CDDUART_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CDDUART_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
      ( CDDUART_PBCFG_AR_RELEASE_MINOR_VERSION_C != CDDUART_PBCFG_AR_RELEASE_MINOR_VERSION) || \
      ( CDDUART_PBCFG_AR_RELEASE_REVISION_VERSION_C != CDDUART_PBCFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CddUart_PBcfg.c and CddUart_PBcfg.h are different"
#endif

/* Check if source file and CDDUART_PBCFG header file are of the same Software version */
#if (( CDDUART_PBCFG_SW_MAJOR_VERSION_C != CDDUART_PBCFG_SW_MAJOR_VERSION) || \
      ( CDDUART_PBCFG_SW_MINOR_VERSION_C != CDDUART_PBCFG_SW_MINOR_VERSION) || \
      ( CDDUART_PBCFG_SW_PATCH_VERSION_C != CDDUART_PBCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of CddUart_PBcfg.c and CddUart_PBcfg.h are different"
#endif

/*==================================================================================================
                                                GLOBAL VARIABLES                                       
==================================================================================================*/
/*==================================================================================================
                                                LOCAL VARIABLES                                        
==================================================================================================*/
/*==================================================================================================
                                                LOCAL CONSTANTS                                        
==================================================================================================*/
/*==================================================================================================
                                                LOCAL MACROS                                           
==================================================================================================*/
/*==================================================================================================
                                                LOCAL FUNCTIONS                                        
==================================================================================================*/
/*==================================================================================================
                                                GLOBAL FUNCTIONS                                       
==================================================================================================*/

#define CDDUART_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CddUart_MemMap.h"
/**
* @brief          Configuration for Uart Channel 0
*/
CDDUART_CONST const CddUart_ChannelConfigType Uart_ChannelConfig_0 =
{
    .UartChannelId = CddUartConf_UartChannel_UartChannel_0, /*Uart Channel Id*/
    .ChannelCoreId = UART_CORE_ID, /*Uart Channel Core Id*/
    .ChannelClockFrequency = 40000000, /* Clock frequency */
    .UartChannelConfig = &CddUart_Mld_HwConfig_0  /* Uart Hardware config */
};

/**
* @brief          Configuration for Uart driver
*/
CDDUART_CONST const CddUart_ConfigType CddUart_Config =
{
    .PartitionCoreId = UART_CORE_ID,
    .Configs = 
    {
        &Uart_ChannelConfig_0,
    },
};

#define CDDUART_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CddUart_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file CddUart_PBcfg.c */
