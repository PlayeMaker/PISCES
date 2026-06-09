/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Rte module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Rte module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/
#ifndef RTE_H
#define RTE_H
/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
*   Rte Version
*******************************************************************************/
#define RTE_VENDOR_ID                STD_HIRAIN_VENDOR_ID
#define RTE_MODULE_ID                ((uint16)2U)
#define SCHM_MODULE_ID               ((uint16)130U)
#define RTE_INSTANCE_ID              ((uint8)0)
#define RTE_SW_MAJOR_VERSION         4
#define RTE_SW_MINOR_VERSION         0
#define RTE_SW_PATCH_VERSION         4
#define RTE_AR_RELEASE_MAJOR_VERSION    4
#define RTE_AR_RELEASE_MINOR_VERSION    7
#define RTE_AR_RELEASE_REVISION_VERSION 0

/*******************************************************************************
*   Rte ErrorCode
*******************************************************************************/
/* common errors */
#define RTE_E_OK                   (0U)
#define RTE_E_INVALID              (1U)

#define RTE_E_PENDING              (10U)

/* overlayed errors */
#define RTE_E_LOST_DATA            (64U)
#define RTE_E_MAX_AGE_EXCEEDED     (64U)

/* immediate infrastructure errors */
#define RTE_E_COM_STOPPED          (128U)
#define RTE_E_TIMEOUT              (129U)
#define RTE_E_LIMIT                (130U)
#define RTE_E_NO_DATA              (131U)
#define RTE_E_TRANSMIT_ACK         (132U)
#define RTE_E_NEVER_RECEIVED       (133U)
#define RTE_E_UNCONNECTED          (134U)
#define RTE_E_IN_EXCLUSIVE_AREA    (135U)
#define RTE_E_SEG_FAULT            (136U)
#define RTE_E_OUT_OF_RANGE         (137U)
#define RTE_E_HARD_TRANSFORMER_ERROR (138U)
#define RTE_E_TRANSFORMER_LIMIT      (139U)
#define RTE_E_SOFT_TRANSFORMER_ERROR (140U)
#define RTE_E_COM_BUSY               (141U)
#define RTE_E_LOST_DATA              (64U)
#define RTE_E_MAX_AGE_EXCEEDED       (64U)

#define APPSWC_ACTIVE          (0U)
#define APPSWC_INACTIVE        (1U)

/*******************************************************************************
*   SchM ErrorCode
*******************************************************************************/
/* common errors */
#define SCHM_E_OK                  (0U)
#define SCHM_E_TIMEOUT             (129U)
#define SCHM_E_LIMIT               (130U)
#define SCHM_E_NO_DATA             (131U)
#define SCHM_E_TRANSMIT_ACK        (132U)
#define SCHM_E_IN_EXCLUSIVE_AREA   (133U)

/*******************************************************************************
*   RTE API ID
*******************************************************************************/
#define SCHM_INIT_SERVICE_ID            (0x00U)
#define SCHM_DEINIT_SERVICE_ID          (0x01U)
#define SCHM_GETVERSION_SERVICE_ID      (0x02U)
#define RTE_START_SERVICE_ID            (0x00U)
#define RTE_STOP_SERVICE_ID             (0x01U)
/*Det Error Code*/
#define SCHM_E_PARAM_POINTER            (0x01U)

#define RTE_GETSPINLOCK(Flag)                               Bmc_GetSpinLock(Flag)
#define RTE_RELEASESPINLOCK(Flag)                           Bmc_ReleaseSpinLock(Flag)
#endif



