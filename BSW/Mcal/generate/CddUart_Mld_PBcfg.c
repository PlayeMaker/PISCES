/**
*   @file    CddUart_PBCfg.c
*   @version 
*   @brief   Mcu Uart configure file.
*/
/*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : uart
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
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "CddUart_Cfg.h"
#include "CddUart_Lld_UartCfg.h"
/*==================================================================================================
*                               FILE VERSION INFORMATION
==================================================================================================*/
#define CDDUART_VENDOR_ID_MLD_CFG_C                      (180)
#define CDDUART_AR_RELEASE_MAJOR_VERSION_MLD_CFG_C       (4)
#define CDDUART_AR_RELEASE_MINOR_VERSION_MLD_CFG_C       (4)
#define CDDUART_AR_RELEASE_REVISION_VERSION_MLD_CFG_C    (0)
#define CDDUART_SW_MAJOR_VERSION_MLD_CFG_C               (0)
#define CDDUART_SW_MINOR_VERSION_MLD_CFG_C               (9)
#define CDDUART_SW_PATCH_VERSION_MLD_CFG_C               (1)
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#if (defined(CPU_YTM32B1MC0) || defined(CPU_YTM32B1MD2))
    /* Check if current file and CddUart header file are of the same Autosar version */
    #if (CDDUART_VENDOR_ID_MLD_CFG_C != CDDUART_VENDOR_ID_UART_CFG)
    #error "CddUart_Mld_PBcfg.c and CddUart_Lld_UartCfg.h have different vendor ids"
    #endif
    
    /* Check if source file and CddUart header file are of the same Autosar version */
    #if ((CDDUART_AR_RELEASE_MAJOR_VERSION_MLD_CFG_C != CDDUART_AR_RELEASE_MAJOR_VERSION_UART_CFG) || \
         (CDDUART_AR_RELEASE_MINOR_VERSION_MLD_CFG_C != CDDUART_AR_RELEASE_MINOR_VERSION_UART_CFG) || \
         (CDDUART_AR_RELEASE_REVISION_VERSION_MLD_CFG_C != CDDUART_AR_RELEASE_REVISION_VERSION_UART_CFG) \
        )
    #error "AutoSar Version Numbers of CddUart_Mld_PBcfg.c  and CddUart_Lld_UartCfg.h are different"
    #endif
    
    /* Check if source file and CddUart header file are of the same Software version */
    #if ((CDDUART_SW_MAJOR_VERSION_MLD_CFG_C != CDDUART_SW_MAJOR_VERSION_UART_CFG) || \
         (CDDUART_SW_MINOR_VERSION_MLD_CFG_C != CDDUART_SW_MINOR_VERSION_UART_CFG) || \
         (CDDUART_SW_PATCH_VERSION_MLD_CFG_C != CDDUART_SW_PATCH_VERSION_UART_CFG) \
        )
    #error "Software Version Numbers of CddUart_Mld_PBcfg.c  and CddUart_Lld_UartCfg.h are different"
    #endif
#else
    /* Check if current file and CddUart header file are of the same Autosar version */
    #if (CDDUART_VENDOR_ID_MLD_CFG_C != CDDUART_VENDOR_ID_LINFLEXDUART_CFG)
    #error "CddUart_Mld_PBcfg.c and CddUart_Lld_LinFlexDCfg.h have different vendor ids"
    #endif
    
    /* Check if source file and CddUart header file are of the same Autosar version */
    #if ((CDDUART_AR_RELEASE_MAJOR_VERSION_MLD_CFG_C != CDDUART_AR_RELEASE_MAJOR_VERSION_LINFLEXDUART_CFG) || \
         (CDDUART_AR_RELEASE_MINOR_VERSION_MLD_CFG_C != CDDUART_AR_RELEASE_MINOR_VERSION_LINFLEXDUART_CFG) || \
         (CDDUART_AR_RELEASE_REVISION_VERSION_MLD_CFG_C != CDDUART_AR_RELEASE_REVISION_VERSION_LINFLEXDUART_CFG) \
        )
    #error "AutoSar Version Numbers of CddUart_Mld_PBcfg.c  and CddUart_Lld_LinFlexDCfg.h are different"
    #endif
    
    /* Check if source file and CddUart header file are of the same Software version */
    #if ((CDDUART_SW_MAJOR_VERSION_MLD_CFG_C != CDDUART_SW_MAJOR_VERSION_LINFLEXDUART_CFG) || \
         (CDDUART_SW_MINOR_VERSION_MLD_CFG_C != CDDUART_SW_MINOR_VERSION_LINFLEXDUART_CFG) || \
         (CDDUART_SW_PATCH_VERSION_MLD_CFG_C != CDDUART_SW_PATCH_VERSION_LINFLEXDUART_CFG) \
        )
    #error "Software Version Numbers of CddUart_Mld_PBcfg.c  and CddUart_Lld_LinFlexDCfg.h are different"
    #endif
#endif
/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define CDDUART_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CddUart_MemMap.h"

/**
* @brief   The Ip configuration structure pointer
*/
CDDUART_CONST const CddUart_Mld_IpConfigType CddUart_Mld_IpChnConfig_0 =
{
    /* LinFlexd Ip configuration structure  */
    .UserConfigOfUartHard = &CddUart_Ip_HwConfig_0,
}; 

/**
* @brief    Hardware configuration for Uart Hardware - Configuration.
*/
CDDUART_CONST const CddUart_Mld_HwConfigType CddUart_Mld_HwConfig_0 =
{
/* Uart Hardware Channel.*/
    .UartHwChannel = UART_2,
    /* Type of Hardware interface configured.*/
    .UartIpType = UART_IP,
    /* Pointer to the Ip configuration structure.*/
    .UserConfig = &CddUart_Mld_IpChnConfig_0
};
#define CDDUART_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CddUart_MemMap.h"

#ifdef __cplusplus
}
#endif

