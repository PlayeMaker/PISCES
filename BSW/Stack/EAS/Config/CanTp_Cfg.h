/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : CanTp_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : CanTp module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : CanTp module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/
#ifndef CANTP_CFG_H
#define CANTP_CFG_H
/*****************************************************************************
 *  General QAC Suppression
 *****************************************************************************/
/*PRQA S 0791,0792 EOF*/
/*
Configure the relevant name of the file, not follow the relevant naming rules


*/
/*PRQA S 3429,3453 EOF*/
/*
Enhance code readability
*/
/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComStack_Types.h"

/*******************************************************************************
*   Common Macro
*******************************************************************************/
/*The configuration variant and version informations*/
#define CANTP_CONFIG_VARIANTS                               STD_CONFIG_VARIANTS_POSTBUILD

/*******************************************************************************
*   Non Autosar Standard
*******************************************************************************/
#define CANTP_VERSION_CHECK                                 STD_ON
#define CANTP_RC                                            STD_OFF
#define CANTP_LONGFF_SUPPORT                                STD_OFF
#define CANTP_MULTI_CORE_SUPPORT                            STD_OFF

/*******************************************************************************
*   CanTpGeneral{CanTpConfiguration}
*******************************************************************************/
/*ECUC_CanTp_00299*/
#define CANTP_CHANGE_PARAMETER_API                          STD_OFF
/*ECUC_CanTp_00239*/
#define CANTP_DEV_ERROR_DETECT                              STD_OFF
/*ECUC_CanTp_00302*/
#define CANTP_DYNID_SUPPORT                                 STD_OFF
/*ECUC_CanTp_00305*/
#define CANTP_CANFD_SUPPORT                                 STD_ON
/*ECUC_CanTp_00303*/
#define CANTP_GENERIC_CONNECTION_SUPPORT                    STD_OFF
/*ECUC_CanTp_00298*/
#define CANTP_PADDING_BYTE                                  ((uint8)0xAA)
/*ECUC_CanTp_00300*/
#define CANTP_READ_PARAMETER_API                            STD_OFF
/*ECUC_CanTp_00283*/
#define CANTP_VERSION_INFO_API                              STD_OFF
/*ECUC_CanTp_00282*/
#define CANTP_TC                                            STD_OFF

/* generate tool's version*/
#define CANTP_SW_MAJOR_VERSION_CFG                          4
#define CANTP_SW_MINOR_VERSION_CFG                          0
#define CANTP_SW_PATCH_VERSION_CFG                          5
#define CANTP_AR_RELEASE_MAJOR_VERSION_CFG                  4
#define CANTP_AR_RELEASE_MINOR_VERSION_CFG                  7
#define CANTP_AR_RELEASE_REVISION_VERSION_CFG               0

#define CANTP_CHANNEL_DUPLEX_VARIES                         (0)
#define CANTP_CHANNEL_HALF_DUPLEX_ONLY                      (1)
#define CANTP_CHANNEL_FULL_DUPLEX_ONLY                      (2)

#define CANTP_SDU_PADDING_VARIES                            (0)
#define CANTP_RXSDU_PADDING_DISABLE                         (1)
#define CANTP_RXSDU_PADDING_ENABLED                         (2)
#define CANTP_TXSDU_PADDING_ENABLED                         (3)
#define CANTP_TXSDU_PADDING_DISABLE                         (4)


#define CANTP_RXSDU_PADDING_MODE                            CANTP_RXSDU_PADDING_ENABLED
#define CANTP_TXSDU_PADDING_MODE                            CANTP_TXSDU_PADDING_ENABLED

#define CANTP_RX_NAI_ADDRESSING                             STD_OFF
#define CANTP_TX_NAI_ADDRESSING                             STD_OFF
#define CANTP_DUPLEX_MODE                                   CANTP_CHANNEL_HALF_DUPLEX_ONLY


typedef uint8 CanTp_ChannelIdType;

#define CANTP_NO_PLATFORM                                   (0)
#define CANTP_NISSAN_PLATFORM                               (1)
#define CANTP_NIO_PLATFORM                                  (2)
#define CANTP_DEEPAL_PLATFORM                               (3)
#define CANTP_CAR_PLATFORM                                  CANTP_NO_PLATFORM


#endif /* CANTP_CFG_H */


