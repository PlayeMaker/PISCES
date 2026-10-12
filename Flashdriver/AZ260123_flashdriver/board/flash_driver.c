/*
 * Copyright 2020-2022 Yuntu Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/*!
 * @file flash_driver.c
 */

#include "flash_driver.h"
#include "bl_flash.h"

/*******************************************************************************
 * Code
 ******************************************************************************/

/*******************************************************************************
 * Internal Functions
 ******************************************************************************/
/*!
 * @brief Internal flash command to execute flash commands.
 *        This function will be copy to RAM section when system boot.
 *
 * @param[in] command Target flash command.
 */
START_FUNCTION_DECLARATION_RAMSECTION
__STATIC_FORCEINLINE status_t FLASH_LaunchCommandSequence(uint8_t command)
END_FUNCTION_DECLARATION_RAMSECTION

/*!
 * @brief Internal flash command to execute flash commands.
 *        This function will be copy to RAM section when system boot.
 *
 * @param[in] command Target flash command.
 */
uint32_t FLASH_GetSectorSize(uint32_t dest);


__attribute__((section(".flashdata")))
bl_FlashDrvHeader_t g_FlashHeader =
{
	FLASH_DRIVER_VERSION_TYPE,
	FLASH_DRIVER_VERSION_INDEX,
	FLASH_DRIVER_VERSION_MAGIC,
	FLASH_DRIVER_VERSION_VERSION,
	&Flash_Init,
	&Flash_Deinit,
	&Flash_Erase,
	&Flash_Write

};



 /**************************************************************************//**
  *
  *  \details Initializes the Pflash driver.
  *
  *  \param[in/out]  par     - the parameters
  *
  *  \return None.
  *
  *  \since V1.0.0
  *
  *****************************************************************************/
 __attribute__((section(".ramcode")))
 void Flash_Init(bl_FlashDrvParam_t *par)
 {
     FLASH_DRV_Init();
     par->errCode = BL_ERR_OK;
 }

 /*FUNCTION**********************************************************************
  *
  * Function Name : FLASH_DRV_Init
  * Description   : Initializes the flash driver.
  * This function is called by the driver initialization function.
  *
  *END**************************************************************************/
 __attribute__((section(".ramcode")))
 status_t FLASH_DRV_Init(void)
 {
     /* During initialization, the PRESCALER in the EFM CTRL register
        MUST be configured to match the current clock configuration. */
 #ifdef EFM_CTRL_CMD_VERIFY_EN_MASK
     /* This is confirmed by hardware. Enabling this may take more time.
        If manual read confirmation is performed later, it can also be disabled. */
     /* Enable command verify */
     EFM->CTRL |= EFM_CTRL_CMD_VERIFY_EN_MASK;
 #endif /* EFM_CTRL_CMD_VERIFY_EN_MASK */
     return STATUS_SUCCESS;
 }

 /**************************************************************************//**
  *
  *  \details De-initializes the Pflash driver.
  *
  *  \param[in/out]  par     - the parameters
  *
  *  \return None.
  *
  *  \since V1.0.0
  *
  *****************************************************************************/
 __attribute__((section(".ramcode")))
 void Flash_Deinit(bl_FlashDrvParam_t *par)
 {
     bl_Return_t ret;
     par->errCode = BL_ERR_OK;
     ret= BL_ERR_OK;
 }

 /**************************************************************************//**
  *
  *  \details Erases the block of flash device.
  *
  *  \param[in/out]  par     - the parameters
  *
  *  \return None.
  *
  *  \since V1.0.0
  *
  *****************************************************************************/
 __attribute__((section(".ramcode")))
 void Flash_Erase(bl_FlashDrvParam_t *par)
 {
     bl_Return_t ret = BL_ERR_NOT_OK;       /* Return code variable */
     bl_Address_t dest;
     bl_Size_t dflashsize; //=0x200;

     dest = par->address;
     dflashsize = par->size;
     if((STATUS_SUCCESS) == (FLASH_DRV_EraseSector(dest,dflashsize)))
     {
         ret = BL_ERR_OK;
     }

     par->errCode = ret;
 }

 /**************************************************************************//**
  *
  *  \details Writes the data to dflash device.
  *
  *  \param[in/out]  par     - the parameters
  *
  *  \return None.
  *
  *  \since V1.0.0
  *
  *****************************************************************************/
 __attribute__((section(".ramcode")))
 void Flash_Write(bl_FlashDrvParam_t *par)
 {
     bl_Return_t ret = BL_ERR_NOT_OK;    /* Return code variable */
     bl_Address_t dest = par->address;
     bl_Size_t bufCnt = par->size;
     bl_Size_t size = 0x8;
     bl_Size_t byteNum;
     bl_Size_t round8Byte = 0;
     bl_Buffer_t pData[bufCnt];
     bl_u8_t i;

     for (byteNum = 0; byteNum < bufCnt; byteNum++)
     {
         pData[byteNum] = par->buffer[byteNum];
     }

     round8Byte = bufCnt&7;
     if(round8Byte != 0)
     {
    	 for(i=0; i<(8-round8Byte); i++)
    	 {
    		 pData[byteNum-1+i] = 0;
    	 }
    	 bufCnt = bufCnt+8-round8Byte;
     }

     for(i = 0; i < bufCnt/size; i++)
     {
         if((STATUS_SUCCESS) == (FLASH_DRV_Program(dest+i*size, size, &pData[i*size])))
         {
             ret = BL_ERR_OK;
         }
     }

     par->errCode = ret;
 }


 /*FUNCTION**********************************************************************
  *
  * Function Name : FLASH_LaunchCommandSequence
  * Description   : Perform command write sequence on Flash.
  * It is internal function, called by driver APIs only.
  *
  *END**************************************************************************/
 __attribute__((section(".ramcode")))
 status_t FLASH_LaunchCommandSequence(uint8_t command)
 {
     status_t ret = STATUS_SUCCESS;    /* Return code variable */
 #if defined(EFM_AUTO_DISABLE_GLOBAL_INT)
     INT_SYS_DisableIRQGlobal();
 #endif /* EFM_AUTO_DISABLE_GLOBAL_INT */

     /* clear pending status */
     EFM->STS = FEATURE_EFM_CMD_ERROR_MASK;
     EFM_UNLOCK_CMD_REGISTER(EFM);
     /* Write command register to launch command */
     EFM->CMD = command;

     while ((EFM_STS_DONE_MASK != (EFM->STS & EFM_STS_DONE_MASK)) &&
            (EFM_STS_ACCERR_MASK != (EFM->STS & EFM_STS_ACCERR_MASK)))
     {
             /* Wait untill Done bit is set */
     }

     if ( (FEATURE_EFM_CMD_ERROR_MASK & EFM->STS) != 0U)
     {
         ret = STATUS_ERROR;
     }

 #if defined(FEATURE_SOC_SUPPORT_CACHE) && FEATURE_SOC_SUPPORT_CACHE
     /* Invalidate flash cache */
     CACHE->CACR |= CACHE_CACR_CMDREQ_MASK | CACHE_CACR_IW1_MASK | CACHE_CACR_IW0_MASK;
     while (CACHE->CACR & CACHE_CACR_CMDREQ_MASK)
         ;
     __DSB();
     __ISB();
 #endif /* FEATURE_SOC_SUPPORT_CACHE */

 #if defined(__DCACHE_PRESENT) && __DCACHE_PRESENT
     if (SCB->CCR & SCB_CCR_DC_Msk)
     {
         SCB_CleanInvalidateDCache();
     }
 #endif

 #if defined(EFM_AUTO_DISABLE_GLOBAL_INT)
     INT_SYS_EnableIRQGlobal();
 #endif /* EFM_AUTO_DISABLE_GLOBAL_INT */

     return ret;
 }


 /*FUNCTION**********************************************************************
  *
  * Function Name : FLASH_GetSectorSize
  * Description   : Get flash sector size based on the destination address.
  * It is internal function, called by driver APIs only.
  *
  *END**************************************************************************/
 __attribute__((section(".ramcode")))
 uint32_t FLASH_GetSectorSize(uint32_t dest)
 {
     uint32_t sectorSize = 0;
     if (dest < FEATURE_EFM_MAIN_ARRAY_END_ADDRESS)
     {
         /* Flash main array */
         sectorSize = FEATURE_EFM_MAIN_ARRAY_SECTOR_SIZE;
     }
 #if FEATURE_EFM_HAS_DATA_FLASH
     else if ((dest < FEATURE_EFM_DATA_ARRAY_END_ADDRESS)
             && (dest >= FEATURE_EFM_DATA_ARRAY_START_ADDRESS))
     {
         /* Flash data array */
         sectorSize = FEATURE_EFM_DATA_ARRAY_SECTOR_SIZE;
     }
 #endif
 #if FEATURE_EFM_HAS_NVR_FLASH
     else if ((dest < FEATURE_EFM_NVR_ARRAY_END_ADDRESS)
              && (dest >= FEATURE_EFM_NVR_ARRAY_START_ADDRESS))
     {
         /* Flash NVR array */
         sectorSize = FEATURE_EFM_NVR_ARRAY_SECTOR_SIZE;
     }
 #endif
     return sectorSize;
 }




 /*FUNCTION**********************************************************************
  *
  * Function Name : FLASH_DRV_Deinit
  * Description   : De-initializes the flash driver.
  * This function is called by the driver de-initialization function.
  *
  *END**************************************************************************/
 __attribute__((section(".ramcode")))
 status_t FLASH_DRV_Deinit(void)
 {
     /* Nothing to do here */
     return STATUS_SUCCESS;
 }

 /*FUNCTION**********************************************************************
  *
  * Function Name : FLASH_DRV_EraseSector
  * Description   : Erases one or more sectors in P-Flash or D-Flash memory.
  * This API always returns STATUS_SUCCESS if size provided by the user is
  * zero regardless of the input validation.
  *
  * Implements    : FLASH_DRV_EraseSector_Activity
  *END**************************************************************************/
 __attribute__((section(".ramcode")))
 status_t FLASH_DRV_EraseSector(uint32_t dest, uint32_t size)
 {
     status_t status = STATUS_SUCCESS;   /* Return code variable */
     uint32_t sectorSize;                /* Size of one sector   */
     uint32_t tempSize = size;           /* Temporary of size variation */
     sectorSize = FLASH_GetSectorSize(dest);
     DEV_ASSERT((dest & (sectorSize - 1)) == 0U);
     DEV_ASSERT((size & (sectorSize - 1)) == 0U);

     while ((tempSize > 0U) && (STATUS_SUCCESS == status) && (sectorSize > 0U))
     {
         /* Check IDLE to verify the previous command is completed */
         if (0U == (EFM->STS & EFM_STS_IDLE_MASK))
         {
             status = STATUS_BUSY;
         }
         else
         {
 #if FEATURE_EFM_HAS_ERASE_TIMING_UNION
             EFM->TIMING2 = FEATURE_EFM_SECTOR_ERASE_TIMING;
 #endif
 #ifndef EFM_CTRL_WE_MASK
             /* Add NOP command to clear write buffer */
             EFM->CMD = 0;
 #endif
             EFM->STS = FEATURE_EFM_CMD_ERROR_MASK | EFM_STS_DONE_MASK;
             EFM_ENABLE_WE_COMMAND(EFM);
             /* Passing parameter to the command */
             *(volatile uint32_t *)dest = 0x12345678;
 #ifdef EFM_STS_ARRAY_SELECTED_MASK
             while (EFM_STS_ARRAY_SELECTED_MASK !=
                    (EFM->STS & EFM_STS_ARRAY_SELECTED_MASK))
               ;
 #endif /* EFM_STS_SET_ADDR_MASK */

 #ifdef EFM_STS_SET_ADDR_MASK
             while (EFM_STS_SET_ADDR_MASK != (EFM->STS & EFM_STS_SET_ADDR_MASK))
               ;
 #endif /* EFM_STS_SET_ADDR_MASK */
             EFM_DISABLE_WE_COMMAND(EFM);
             /* Calling flash command sequence function to execute the command */
             status = FLASH_LaunchCommandSequence(FEATURE_EFM_ERASE_SECTOR_CMD_CODE);
         }
         tempSize -= sectorSize;
         dest += sectorSize;
         sectorSize = FLASH_GetSectorSize(dest);
     }

     return status;
 }

 /*FUNCTION**********************************************************************
  *
  * Function Name : FLASH_DRV_Program
  * Description   : Program command on flash
  * This API always returns STATUS_SUCCESS if size provided by user is
  * zero regardless of the input validation.
  *
  * Implements    : FLASH_DRV_Program_Activity
  *END**************************************************************************/
 __attribute__((section(".ramcode")))
 status_t FLASH_DRV_Program(uint32_t dest, uint32_t size, const void * pData)
 {
     status_t ret = STATUS_SUCCESS;    /* Return code variable */
     uint32_t * efm_dest;
     uint32_t * efm_data;
     uint8_t i;
     DEV_ASSERT((dest & (FEATURE_EFM_WRITE_UNIT_SIZE - 1)) == 0U);
     DEV_ASSERT(((uint32_t)pData & 0x03U) == 0U);
     DEV_ASSERT((size & (FEATURE_EFM_WRITE_UNIT_SIZE - 1)) == 0U);

     efm_dest = (uint32_t *) dest;
     efm_data = (uint32_t *) pData;

     while ((size > 0U) && (STATUS_SUCCESS == ret))
     {
         /* Check IDLE to verify the previous command is completed */
         if (0U == (EFM->STS & EFM_STS_IDLE_MASK))
         {
             ret = STATUS_EFM_BUSY;
         }
         else
         {
 #ifndef EFM_CTRL_WE_MASK
             /* Add NOP command to clear write buffer */
             EFM->CMD = 0;
 #endif
             EFM->STS = FEATURE_EFM_CMD_ERROR_MASK | EFM_STS_DONE_MASK;
             EFM_ENABLE_WE_COMMAND(EFM);
             /* Passing parameter to the command */
             for (i = 0U; i < FEATURE_EFM_WRITE_UNIT_WORD_SIZE; i++) {
               efm_dest[i] = efm_data[i];
 #ifdef EFM_STS_ARRAY_SELECTED_MASK
               while (EFM_STS_ARRAY_SELECTED_MASK !=
                      (EFM->STS & EFM_STS_ARRAY_SELECTED_MASK))
                 ;
 #endif /* EFM_STS_SET_ADDR_MASK */
             }
 #ifdef EFM_STS_SET_ADDR_MASK
             while (EFM_STS_SET_ADDR_MASK != (EFM->STS & EFM_STS_SET_ADDR_MASK))
               ;
 #endif /* EFM_STS_SET_ADDR_MASK */
             EFM_DISABLE_WE_COMMAND(EFM);
             /* Calling flash command sequence function to execute the command */
             ret = FLASH_LaunchCommandSequence(FEATURE_EFM_PROGRAM_CMD_CODE);

             /* Update destination address for next iteration */
             efm_dest += FEATURE_EFM_WRITE_UNIT_WORD_SIZE;
             /* Update size for next iteration */
             size -= FEATURE_EFM_WRITE_UNIT_SIZE;
             /* Increment the source address by 1 */
             efm_data += FEATURE_EFM_WRITE_UNIT_WORD_SIZE;
         }
     }

     return ret;
 }



#ifdef FEATURE_EFM_ERASE_NVR_CMD_CODE
/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_DRV_EraseNVR
 * Description   : Program NVR command on flash
 * This API always returns STATUS_SUCCESS if size provided by user is
 * zero regardless of the input validation.
 *
 * Implements    : FLASH_DRV_EraseNVR_Activity
 *END**************************************************************************/
status_t FLASH_DRV_EraseNVR(uint32_t address)
{
    status_t status;    /* Return code variable */
    EFM->STS = FEATURE_EFM_CMD_ERROR_MASK | EFM_STS_DONE_MASK;
    EFM->NVR_ADDR = address;
    /* Calling flash command sequence function to execute the command */
    status = FLASH_LaunchCommandSequence(FEATURE_EFM_ERASE_NVR_CMD_CODE);
    return status;
}
#endif /* FEATURE_EFM_ERASE_NVR_CMD_CODE */


#ifdef FEATURE_EFM_PROGRAM_NVR_CMD_CODE
/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_DRV_ProgramNVR
 * Description   : Program NVR command on flash
 * This API always returns STATUS_SUCCESS if size provided by user is
 * zero regardless of the input validation.
 *
 * Implements    : FLASH_DRV_ProgramNVR_Activity
 *END**************************************************************************/
status_t FLASH_DRV_ProgramNVR( uint32_t address, uint32_t size, const void * pData)
{
    status_t ret = STATUS_SUCCESS;    /* Return code variable */
    uint8_t i;
    uint32_t * efm_data;
    efm_data = (uint32_t *) pData;
    while ((size > 0U) && (STATUS_SUCCESS == ret))
    {
        /* Check IDLE to verify the previous command is completed */
        if (0U == (EFM->STS & EFM_STS_IDLE_MASK))
        {
            ret = STATUS_EFM_BUSY;
        }
        else
        {
            EFM->STS = FEATURE_EFM_CMD_ERROR_MASK | EFM_STS_DONE_MASK;
            EFM->NVR_ADDR = address;
            /* Passing parameter to the command */
            for (i = 0U; i < FEATURE_EFM_WRITE_UNIT_WORD_SIZE; i++)
            {
                EFM->NVR_DATA[i] = efm_data[i];
            }

            /* Calling flash command sequence function to execute the command */
            ret = FLASH_LaunchCommandSequence(FEATURE_EFM_PROGRAM_NVR_CMD_CODE);

            /* Update size for next iteration */
            size -= FEATURE_EFM_WRITE_UNIT_SIZE;
            /* Update address for next iteration */
            address += FEATURE_EFM_WRITE_UNIT_SIZE;
            /* Increment the source address by 1 */
            efm_data += FEATURE_EFM_WRITE_UNIT_WORD_SIZE;
        }
    }
    return ret;
}
#endif /* FEATURE_EFM_PROGRAM_NVR_CMD_CODE */

#ifdef FEATURE_EFM_READ_NVR_CMD_CODE
/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_DRV_ReadNVR
 * Description   : Read NVR command on flash
 * This API always returns STATUS_SUCCESS if size provided by user is
 * zero regardless of the input validation.
 *
 * Implements    : FLASH_DRV_ReadNVR_Activity
 *END**************************************************************************/
status_t FLASH_DRV_ReadNVR(uint32_t address, uint32_t size, void * dest)
{
    status_t ret = STATUS_SUCCESS;    /* Return code variable */
    uint8_t i;
    uint32_t *pData = (uint32_t *)dest;
    while ((size > 0U) && (STATUS_SUCCESS == ret))
    {
        /* Check IDLE to verify the previous command is completed */
        if (0U == (EFM->STS & EFM_STS_IDLE_MASK))
        {
            ret = STATUS_EFM_BUSY;
        }
        else
        {
            EFM->STS = FEATURE_EFM_CMD_ERROR_MASK | EFM_STS_DONE_MASK;
            EFM->NVR_ADDR = address;
            /* Calling flash command sequence function to execute the command */
            ret = FLASH_LaunchCommandSequence(FEATURE_EFM_READ_NVR_CMD_CODE);
            if (STATUS_SUCCESS != ret){
                break;
            }
            /* Passing parameter to the command */
            for (i = 0U; i < FEATURE_EFM_WRITE_UNIT_WORD_SIZE; i++)
            {
                pData[i] = EFM->NVR_DATA[i];
            }

            /* Update size for next iteration */
            size -= FEATURE_EFM_WRITE_UNIT_SIZE;
            /* Update address for next iteration */
            address += FEATURE_EFM_WRITE_UNIT_SIZE;
            /* Increment the source address by 1 */
            pData += FEATURE_EFM_WRITE_UNIT_WORD_SIZE;
        }
    }
    return ret;
}
#endif /* FEATURE_EFM_READ_NVR_CMD_CODE */


/*******************************************************************************
* EOF
*******************************************************************************/
