/*
 * Copyright 2020-2026 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * @file undefined
 * @brief 
 * 
 */


#ifndef _Crypto_CFG_H_
#define _Crypto_CFG_H_


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_VENDOR_ID_CFG                      (180)
#define CRYPTO_AR_RELEASE_MAJOR_VERSION_CFG       (4)
#define CRYPTO_AR_RELEASE_MINOR_VERSION_CFG       (4)
#define CRYPTO_AR_RELEASE_REVISION_VERSION_CFG    (0)
#define CRYPTO_SW_MAJOR_VERSION_CFG               (0)
#define CRYPTO_SW_MINOR_VERSION_CFG               (9)
#define CRYPTO_SW_PATCH_VERSION_CFG               (1)

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
// CryptoDriverObjects_CryptoDriverObject
/**
 * @brief        Identifier of the Crypto Driver Object. The Crypto Driver Object offers different crypto primitives.
 * @details       
 * @ref          ECUC_Crypto_00009
 */
#define CRYPTO_DRIVER_OBJECT_ID    (1U)
/**
 * @brief        Size of the queue in the Crypto Driver. Defines the maximum number of jobs in the Crypto Driver Object queue. If it is set to 0, queueing is disabled in the Crypto Driver Object.
 * @details       
 * @ref          ECUC_Crypto_00019
 */
#define CRYPTO_QUEUE_SIZE           (0U)

// CryptoGeneral
/**
 * @brief        Switches the development error detection and notification on or off.
 * @details      true: detection and notification is enabled.
              false: detection and notification is disabled 
 * @ref          ECUC_Crypto_00006
 */
#define CRYPTO_DEV_ERROR_DETECT      (STD_OFF)
/**
 * @brief        Pre-processor switch to enable and disable availability of the API Crypto_GetVersionInfo().
 * @details      True: API Crypto_GetVersionInfo() is available
              False: API Cryptosm_GetVersionInfo() is not available. 
 * @ref          ECUC_Crypto_00007
 */
#define CRYPTO_VERSION_INFO_API      (STD_OFF)
/**
 * @brief        Instance ID of the crypto driver. This ID is used to discern several crypto drivers in case more than one driver is used in the same ECU.
 * @details       
 * @ref          ECUC_Crypto_00040
 */
#define CRYPTO_INSTANCE_ID           (0U)
/**
 * @brief        Specifies the period of main function Crypto_MainFunction in seconds.
 * @details       
 * @ref          ECUC_Crypto_00038
 */
#define CRYPTO_MAIN_FUNCTION_PERIOD (0.01)
/**
* @brief Support for SchM: sync/atomic operations, global interrupt disable/enable.
*/
#define CRYPTO_SCHM_SUPPORT                         (STD_ON) 


#define CRYPTO_ASYNJOB_METHOD_SUPPORT      (CRYPTO_METHOD_POLLING)

#ifdef CRYPTO_ENABLE_USER_MODE_SUPPORT
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
#error "Must define MCAL_ENABLE_USER_MODE_SUPPORT if CRYPTO_ENABLE_USER_MODE_SUPPORT is defined"
#endif
#endif

/*Hardware Key store base address*/
#define HCU_NVR_ADDR  0x00000000

/*Define Hardware key slot size*/
#define HCU_HWKEY_SZIE         32U

/*Define KeySlot*/
#define HCU_KEY_Slot0       (HCU_NVR_ADDR + (0 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot1       (HCU_NVR_ADDR + (1 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot2       (HCU_NVR_ADDR + (2 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot3       (HCU_NVR_ADDR + (3 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot4       (HCU_NVR_ADDR + (4 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot5       (HCU_NVR_ADDR + (5 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot6       (HCU_NVR_ADDR + (6 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot7       (HCU_NVR_ADDR + (7 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot8       (HCU_NVR_ADDR + (8 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot9       (HCU_NVR_ADDR + (9 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot10       (HCU_NVR_ADDR + (10 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot11       (HCU_NVR_ADDR + (11 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot12       (HCU_NVR_ADDR + (12 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot13       (HCU_NVR_ADDR + (13 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot14       (HCU_NVR_ADDR + (14 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot15       (HCU_NVR_ADDR + (15 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot16       (HCU_NVR_ADDR + (16 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot17       (HCU_NVR_ADDR + (17 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot18       (HCU_NVR_ADDR + (18 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot19       (HCU_NVR_ADDR + (19 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot20       (HCU_NVR_ADDR + (20 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot21       (HCU_NVR_ADDR + (21 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot22       (HCU_NVR_ADDR + (22 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot23       (HCU_NVR_ADDR + (23 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot24       (HCU_NVR_ADDR + (24 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot25       (HCU_NVR_ADDR + (25 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot26       (HCU_NVR_ADDR + (26 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot27       (HCU_NVR_ADDR + (27 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot28       (HCU_NVR_ADDR + (28 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot29       (HCU_NVR_ADDR + (29 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot30       (HCU_NVR_ADDR + (30 * HCU_HWKEY_SZIE))
#define HCU_KEY_Slot31       (HCU_NVR_ADDR + (31 * HCU_HWKEY_SZIE))

/**/
#define HCU_KEY_NULL        HCU_NVR_ADDR
/*Define type of KeySize*/
#define Crypto_Key_128      128U
#define Crypto_Key_192      192U
#define Crypto_Key_256      256U
/*Define type of DMA UNUSED*/
#define Crypto_DMA_UNUSED   0U
/*Define type of AsyncJob Method*/
#define CRYPTO_METHOD_DMA                 0U
#define CRYPTO_METHOD_INTERRUPT           1U
#define CRYPTO_METHOD_POLLING             2U
/**
 * @brief  SUPPORT HASH.
 */
#define HCU_SUPPORT_HASH

/**
 * @brief  SUPPORT HASH Verification.
 */
#define HCU_SUPPORT_HASH_VERIFICATION
/**
 * @brief  SUPPORT Total msg set.
 */
#define HCU_SUPPORT_TOTAL_MSG_LENGTH_SET

/*
* @brief Information about the Crypto Driver Objects
*/
#define CRYPTO_DRIVER_OBJECT_MAX        (1U)
#define CryptoConf_CryptoDriverObject_CryptoDriverObject_0      (0U)
/*
* @brief Information about the Key
*/
#define CRYPTO_DRIVER_KEYID_MAX         (0U)

#define CRYPTO_DRIVER_InstanceMax       (2U)

#define CRYPTO_DRIVER_KEYELEMENT_MAX    (0U)

#define CRYPTO_LENGTH_OF_RANDOM         (16U)

#endif /* _Crypto_CFG_H_ */
