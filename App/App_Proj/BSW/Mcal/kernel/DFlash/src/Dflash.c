
/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is the source file of the flash module.
 *
 *  \file       bl_flash.c
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
 *      01.03.00 | 20/03/2014 | sijia.hao        | N/A | BootDrv010004
 *
 *****************************************************************************/
#include "platform_types.h"
#include "IntCtrl_Lld_TypesDef.h"
#include "../inc/Dflash.h"
#include "../inc/common.h"
#include "../inc/flash_driver.h"
#include "../inc/flash_hw_access.h"
#include "../inc/YTM32B1MD2_features.h"
#include "../inc/YTM32B1MD2.h"
//#include "interrupt_manager.h"

/*****************************************************************************
 *  QAC Suppression
 *****************************************************************************/
/*PRQA S 306,506,781,1015,1532,3112,3227,3408 EOF*/
/*
 * MISRA-C:2004 11.3(306):Cast a pointer to an integral type.
 * To address a flash must cast an integral type to a pointer.
 *
 * 506:Dereferencing pointer value that is possibly NULL.
 * The parameter delay is not a null pointer.
 *
 * MISRA-C:2004 5.6(781):The identifier is used as a structure/union member.
 * The member of the structure is used through the structure object.
 *
 * 1015:Far is not a legal keyword in ISO C
 * This is a valid keyword in the CodeWarrior.
 *
 * 1532:The function is only referenced in one translation unit.
 * all functions in this file are configurations in the Security Module.
 *
 * MISRA-C:2004 14.2(3112):This statement has no side-effect.
 * The DEBUG_ASSERT macro is used to debug bootloader when the BL_DEBUG is
 * enable. When the BL_DEBUG is disable, the DEBUG_ASSERT macro is null.
 *
 * 3227:The parameter is never modified and so it could be declared with const.
 *
 * MISRA-C:2004 8.8(3408):The identifier has external linkage but is being
 * defined without any previous declaration.
 * The Flash_Read has a previous declaraton in the bl_flash.h file.
 *
 */

 

/*****************************************************************************
 *  Function Definitions
 *****************************************************************************/
#define dflash_store_start           0x0200F800ul
#define dflash_store_end             0x0200FFFFul //200F800
#define dflash_store_size            0x100ul      //2KB //0xC8ul
#define dflash_sector_size           0x200ul      //一个扇区512字节
#define FLASH_INST (0U)


status_t FLASH_DRV_EraseSector(uint32_t instance, uint32_t dest, uint32_t size);



/*******************************************************************************
 * Internal Functions
 ******************************************************************************/
flash_state_t flash_config0_State;
flash_user_config_t flash_config0={
    .async=false,
    .disGlobalInt=true,
    .readVerify=true,
    .callback=NULL,
};


/* Table of base addresses for EFM instances. */
static EFM_Type * const s_efmBase[EFM_INSTANCE_COUNT] = EFM_BASE_PTRS;

/* Pointer to runtime state structure.*/
static flash_state_t * s_FlashStatePtr[EFM_INSTANCE_COUNT] = {NULL};


static flash_syncCallback_t s_SyncCallBackFunction = NULL_SYNCCALLBACK;

static uint32_t s_tempData = 0x12345678U;


static uint32_t FLASH_GetSectorSize(uint32_t dest);

/* Table for EFM IRQ numbers */
//static const IRQn_Type s_efmIrqId[EFM_INSTANCE_COUNT] = EFM_IRQS;


/**************************************************************************//**
 *
 *  \details Initializes the dflash driver.
 *
 *  \param[in/out]  par     - the parameters
 *
 *  \return None.
 *
 *  \since V1.0.0
 *
 *****************************************************************************/
bl_Return_t Dflash_Init(void)
{
	bl_Return_t ret;
    FLASH_DRV_Init(0,&flash_config0,&flash_config0_State);
	ret = BL_ERR_OK;
        return ret;
}
/**************************************************************************//**
 *
 *  \details De-initializes the dflash driver.
 *
 *  \param[in/out]  par     - the parameters
 *
 *  \return None.
 *
 *  \since V1.0.0
 *
 *****************************************************************************/
bl_Return_t Dflash_Deinit(void)
{
    bl_Return_t ret;
    ret= BL_ERR_OK;
    return ret;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_GetSectorSize
 * Description   : Get flash sector size based on the destination address.
 * It is internal function, called by driver APIs only.
 *
 *END**************************************************************************/
static uint32_t FLASH_GetSectorSize(uint32_t dest)
{
    uint32_t sectorSize = 0;
    if ((dest < FEATURE_EFM_MAIN_ARRAY_END_ADDRESS)
#if defined(FEATURE_EFM_MAIN_ARRAY_START_ADDRESS) && (FEATURE_EFM_MAIN_ARRAY_START_ADDRESS != 0)
            && (dest >= FEATURE_EFM_MAIN_ARRAY_START_ADDRESS)
#endif /* FEATURE_EFM_MAIN_ARRAY_START_ADDRESS */
        )
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
    else{
        sectorSize = 0;
    }
    return sectorSize;
}



/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_LaunchCommandSequence
 * Description   : Perform command write sequence on Flash.
 * It is internal function, called by driver APIs only.
 *
 *END**************************************************************************/

static status_t FLASH_LaunchCommandSequence(uint32_t instance)
{
    //DEV_ASSERT(instance < EFM_INSTANCE_COUNT);
    EFM_Type *base = s_efmBase[instance];
    flash_state_t const *state = s_FlashStatePtr[instance];
    //DEV_ASSERT(state != NULL);
    status_t status = STATUS_SUCCESS; /* Return code variable */
    uint32_t primask_bit;

    /* Enter critical section: Disable interrupts to avoid any interruption during the command launch */
    primask_bit = __get_PRIMASK();
    __disable_irq();

#ifndef EFM_CTRL_WE_MASK
    /* Add NOP command to clear write buffer */
    base->CMD = 0;
#endif

#if defined(FEATURE_EFM_HAS_READONLY_BIT) && (FEATURE_EFM_HAS_READONLY_BIT == 1)
    /* Flash can be read, erased and programmed */
    EFM->CTRL &= ~EFM_CTRL_READONLY_MASK;
#endif
    /* clear pending status */
    /* static inline functions are risks due to "-o0" optimization not inlined,
       So operate registers directly in ram function */
    base->STS = FEATURE_EFM_CMD_ERROR_MASK | EFM_STS_DONE_MASK;

    EFM_ENABLE_WE_COMMAND(base);
    /* Passing parameter to the command */
    for (uint32_t i = 0; i < state->cmdParam.word_size; i++)
    {
        state->cmdParam.dest[i] = state->cmdParam.pdata[i];
#ifdef EFM_STS_ARRAY_SELECTED_MASK
        while (EFM_STS_ARRAY_SELECTED_MASK != (base->STS & EFM_STS_ARRAY_SELECTED_MASK))
        {
            /* Wait until the array is selected */
        }
#endif /* EFM_STS_SET_ADDR_MASK */
    }
#ifdef EFM_STS_SET_ADDR_MASK
    while (EFM_STS_SET_ADDR_MASK != (base->STS & EFM_STS_SET_ADDR_MASK))
    {
        /* Wait until the address is set */
    }
#endif /* EFM_STS_SET_ADDR_MASK */
    EFM_DISABLE_WE_COMMAND(base);

#if defined(FEATURE_EFM_UNLOCK_CMD_COMPLEX) && (FEATURE_EFM_UNLOCK_CMD_COMPLEX == 1)
    s_FlashUnlockCmd[instance](base, state->cmdParam.cmdCode, (uint32_t)state->cmdParam.dest);
#else
    EFM_UNLOCK_CMD_REGISTER(base);
#endif /* EFM_UNLOCK_CMD_REGISTER */

    /* Write command register to launch command */
    if (state->cmdParam.cmdCode == 0xFEU)
    {
        /* Quick erase sector by split erase sector time */
        base->CMD = FEATURE_EFM_ERASE_SECTOR_CMD_CODE;
    }else{
        base->CMD = EFM_CMD_CMD(state->cmdParam.cmdCode);
    }
    /* if sync mode config disGlobalInt, keep disable global interrupt */
    if(false == state->disGlobalInt)
    {
        /* Exit critical section: restore previous priority mask */
        __set_PRIMASK(primask_bit);
    }

    if (false == state->async)
    {
        while ((EFM_STS_DONE_MASK != (base->STS & EFM_STS_DONE_MASK)) &&
               (EFM_STS_ACCERR_MASK != (base->STS & EFM_STS_ACCERR_MASK)))
        {
            /* Wait untill Done bit is set
             * Serve callback function as often as possible
             */
            if (NULL_SYNCCALLBACK != s_SyncCallBackFunction)
            {
                /* Temporarily disable compiler's check for ROM access call from within a ram function.
                 * The use of a function pointer type makes this check irrelevant.
                 * Nevertheless, it is imperative that the user-provided callback be defined in RAM SECTION */
                s_SyncCallBackFunction();
            }
        }
    }
    if (0U != (base->STS & FEATURE_EFM_CMD_ERROR_MASK))
    {
        status = STATUS_ERROR;
    }

#if defined(FEATURE_EFM_HAS_READONLY_BIT) && (FEATURE_EFM_HAS_READONLY_BIT == 1)
    /* Read only flash array */
    EFM->CTRL |= EFM_CTRL_READONLY_MASK;
#endif

    if(true == state->disGlobalInt)
    {
        /* Exit critical section: restore previous priority mask */
        __set_PRIMASK(primask_bit);
    }

    return status;
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
status_t FLASH_DRV_EraseSector(uint32_t instance, uint32_t dest, uint32_t size)
{
    // DEV_ASSERT(instance < EFM_INSTANCE_COUNT);
    EFM_Type *base = s_efmBase[instance];
    flash_state_t *state = s_FlashStatePtr[instance];
    //DEV_ASSERT(state != NULL);
    status_t status = STATUS_SUCCESS; /* Return code variable */
    int32_t leftSize = (int32_t)size;
    uint32_t sectorSize;              /* Size of one sector   */
    sectorSize = FLASH_GetSectorSize(dest);
    // DEV_ASSERT((dest & (sectorSize - 1)) == 0U);
    // DEV_ASSERT((size & (sectorSize - 1)) == 0U);
    // DEV_ASSERT(size >= sectorSize);

#if defined(FEATURE_EFM_HAS_ERASE_TIMING_UNION) && (FEATURE_EFM_HAS_ERASE_TIMING_UNION == 1U)
    base->TIMING2 = FEATURE_EFM_SECTOR_ERASE_TIMING;
#endif

    state->cmdParam.cmdCode = FEATURE_EFM_ERASE_SECTOR_CMD_CODE;
#ifdef FEATURE_EFM_ERASE_SECTOR_VERIFY_CMD_CODE
    if (true == state->readVerify)
    {
        state->cmdParam.cmdCode = FEATURE_EFM_ERASE_SECTOR_VERIFY_CMD_CODE;
    }
#endif
    state->cmdParam.dest = (uint32_t *)dest;
    state->cmdParam.pdata = &s_tempData;
    state->cmdParam.word_size = 1U;

    if (state->async)
    {
        if ((false == FLASH_GetIdleStatus(base)) || (state->driverBusy))
        {
            status = STATUS_EFM_BUSY;
        }
        else
        {
            state->driverBusy = true;
            state->leftSize = leftSize;
            status = FLASH_LaunchCommandSequence(instance);
        }
    }
    else
    {
        while ((leftSize > 0) && (STATUS_SUCCESS == status) && (sectorSize > 0U))
        {
            /* Check IDLE to verify the previous command is completed */
            if (false == FLASH_GetIdleStatus(base))
            {
                status = STATUS_EFM_BUSY;
            }
            else
            {
                /* Calling flash command sequence function to execute the command */
                status = FLASH_LaunchCommandSequence(instance);
            }
            leftSize -= (int32_t)sectorSize;
            state->cmdParam.dest += sectorSize >> 2U; /* PRQA S 0488 */
            sectorSize = FLASH_GetSectorSize((uint32_t)state->cmdParam.dest);
        }
    }

    return status;
}




/*FUNCTION**********************************************************************
*
* Function Name : FLASH_DRV_GetBusyStatus
* Description   : Get the Flash module busy status.
*
* Implements    : FLASH_DRV_GetBusyStatus_Activity
*END**************************************************************************/
bool FLASH_DRV_GetBusyStatus(uint32_t instance)
{
    //DEV_ASSERT(instance < EFM_INSTANCE_COUNT);
    flash_state_t const *state = s_FlashStatePtr[instance];
    //DEV_ASSERT(state != NULL);

    return state->driverBusy;
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
status_t FLASH_DRV_Program(uint32_t instance, uint32_t dest, uint32_t size, const void * pData)
{
    //DEV_ASSERT(instance < EFM_INSTANCE_COUNT);
    EFM_Type *base = s_efmBase[instance];
    flash_state_t *state = s_FlashStatePtr[instance];
    int32_t leftSize = (int32_t)size;
    //DEV_ASSERT(state != NULL);
    status_t status = STATUS_SUCCESS;    /* Return code variable */

    // DEV_ASSERT((dest & (FEATURE_EFM_WRITE_UNIT_SIZE - 1U)) == 0U);
    // DEV_ASSERT((size & (FEATURE_EFM_WRITE_UNIT_SIZE - 1U)) == 0U);
    // DEV_ASSERT(size >= FEATURE_EFM_WRITE_UNIT_SIZE);
    // DEV_ASSERT(((uint32_t)pData & 0x03U) == 0U);

    state->cmdParam.cmdCode = FEATURE_EFM_PROGRAM_CMD_CODE;
#ifdef FEATURE_EFM_PROGRAM_VERIFY_CMD_CODE
    if (true == state->readVerify)
    {
        state->cmdParam.cmdCode = FEATURE_EFM_PROGRAM_VERIFY_CMD_CODE;
    }
#endif
    state->cmdParam.dest = (uint32_t *) dest;
    state->cmdParam.pdata = (const uint32_t *) pData; /* PRQA S 0316 */
    state->cmdParam.word_size = FEATURE_EFM_WRITE_UNIT_WORD_SIZE;

    if (state->async)
    {
        if ((false == FLASH_GetIdleStatus(base)) || (state->driverBusy))
        {
            status = STATUS_EFM_BUSY;
        }
        else
        {
            state->driverBusy = true;
            state->leftSize = leftSize;
            status = FLASH_LaunchCommandSequence(instance);
        }
    }
    else
    {
        while ((leftSize > 0) && (STATUS_SUCCESS == status))
        {
            /* Check IDLE to verify the previous command is completed */
            if (false == FLASH_GetIdleStatus(base))
            {
                status = STATUS_EFM_BUSY;
            }
            else
            {
                /* Calling flash command sequence function to execute the command */
                status = FLASH_LaunchCommandSequence(instance);

                /* Update destination address for next iteration */
                state->cmdParam.dest += FEATURE_EFM_WRITE_UNIT_WORD_SIZE; /* PRQA S 0488 */
                /* Update size for next iteration */
                leftSize -= (int32_t)FEATURE_EFM_WRITE_UNIT_SIZE;
                /* Increment the source address by unit word size */
                state->cmdParam.pdata += FEATURE_EFM_WRITE_UNIT_WORD_SIZE; /* PRQA S 0488 */
            }
        }
    }

    return status;
}




/*************************************************************************************************
* Function Name : Eep_Read
*
* Description   : read  data to memory
*
* Inputs        : bt standard input   
*                 
*
* Outputs       : None
* 
* Limitations   : None
*                 
*************************************************************************************************/
bl_Return_t Dflash_Read(bl_Address_t address, bl_Size_t size, bl_Buffer_t *buffer)
{
    bl_Return_t ret = BL_ERR_OK;
    bl_Size_t i;

	for (i = 0; i < size; i++)
    {
        buffer[i] = *(bl_Buffer_t *)(address + i); /*lint !e511*/
    }
	ret = BL_ERR_OK;

    return ret;
}


/*FUNCTION**********************************************************************
*
* Function Name : FLASH_DRV_Init
* Description   : Initialize the Flash module.
*
* Implements    : FLASH_DRV_Init_Activity
*END**************************************************************************/
status_t FLASH_DRV_Init(uint32_t instance, const flash_user_config_t * userConfigPtr, flash_state_t * state)
{
    // DEV_ASSERT(instance < EFM_INSTANCE_COUNT);
    // DEV_ASSERT(s_FlashStatePtr[instance] == NULL);
    // DEV_ASSERT(userConfigPtr != NULL);
    // DEV_ASSERT(state != NULL);

    EFM_Type *base = s_efmBase[instance];
    status_t status = STATUS_SUCCESS;    /* Return code variable */
#ifdef EFM_WDG_WDG_EN_MASK
    uint32_t slowBusClockFrq;
#endif /* EFM_WDG_WDG_EN_MASK */

    if (FLASH_GetIdleStatus(base)){
        FLASH_ClearErrorFlags(base);
        FLASH_ClearDoneStatusFlag(base);
        s_FlashStatePtr[instance] = state;
        state->async = userConfigPtr->async;
        state->callback = userConfigPtr->callback;
        state->disGlobalInt = userConfigPtr->disGlobalInt;
        state->driverBusy = false;

#if defined(FEATURE_EFM_TIMING_MAX) && (FEATURE_EFM_TIMING_MAX == 1U)
        base->TIMING1 = FEATURE_EFM_TIMING1_MAX;
        base->TIMING2 = FEATURE_EFM_TIMING2_MAX;
#endif

#ifdef EFM_CTRL_CMD_VERIFY_EN_MASK
        if (true == userConfigPtr->readVerify)
        {
            base->CTRL |= EFM_CTRL_CMD_VERIFY_EN_MASK;
        }
        else
        {
            base->CTRL &= ~EFM_CTRL_CMD_VERIFY_EN_MASK;
        }
#endif
        state->readVerify = userConfigPtr->readVerify;

#ifdef EFM_WDG_WDG_EN_MASK
        if (true == userConfigPtr->wdgEnable)
        {
            /* Get slow bus clock freq for WDG module */
            status = CLOCK_SYS_GetFreq(SLOW_BUS_CLK, &slowBusClockFrq);
            if (STATUS_SUCCESS == status){
                base->WDG = EFM_WDG_WDG_PRESCALER(slowBusClockFrq / 1e6);
                base->WDG |= EFM_WDG_WDG_EN_MASK;
            }
        }
        else
        {
            base->WDG &= ~EFM_WDG_WDG_EN_MASK;
        }

#endif /* EFM_WDG_WDG_EN_MASK */

        /* Enable flash interrupt */
        if (state->async)
        {
            FLASH_DRV_EnableCmdCompleteInterrupt(instance);
            //INT_SYS_EnableIRQ(s_efmIrqId[instance]);
            FLASH_DRV_EnableReadCollisionInterrupt(instance);
// #ifdef EFM_READ_COLLISION_IRQS
//             INT_SYS_EnableIRQ(s_efmReadCollisionIrqId[instance]);
// #endif /* EFM_READ_COLLISION_IRQS */
        }

    }else{
        status = STATUS_EFM_BUSY;
    }

#if defined(FEATURE_EFM_HAS_READONLY_BIT) && (FEATURE_EFM_HAS_READONLY_BIT == 1)
    /* Read only flash array */
    EFM->CTRL |= EFM_CTRL_READONLY_MASK;
#endif
    return status;
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
bl_Return_t Dflash_Erase(bl_Address_t address, bl_Size_t size)

{
    bl_Return_t ret = BL_ERR_NOT_OK;       /* Return code variable */
    bl_Size_t dflashsize=size; //dflash_sector_size; //0x200;

    if ((address < FEATURE_EFM_DATA_ARRAY_END_ADDRESS)
            && (address >= FEATURE_EFM_DATA_ARRAY_START_ADDRESS))
    {
        //INT_SYS_DisableIRQGlobal();
        if((STATUS_SUCCESS) == (FLASH_DRV_EraseSector(FLASH_INST,address,dflashsize)))
        {
            ret = BL_ERR_OK;
        }
        //INT_SYS_EnableIRQGlobal();
    }

    return ret;

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
bl_Return_t Dflash_Write(bl_Address_t address, bl_Size_t size, const bl_Buffer_t *buffer)
{
    bl_Return_t ret = BL_ERR_NOT_OK;    /* Return code variable */
	bl_u8_t i;
    bl_Address_t dest = address;
    bl_Buffer_t dest1[dflash_store_size]={0};
    bl_u32_t tempSectorNum = 0;
    bl_Address_t tempstartAddr = 0;


    if ((address < dflash_store_end) && (address >= dflash_store_start))
    {

        tempSectorNum = (bl_u32_t)((address-dflash_store_start)/dflash_sector_size);
        tempstartAddr = dflash_store_start + tempSectorNum*dflash_sector_size;

        if((BL_ERR_OK) != Dflash_Read(tempstartAddr,dflash_store_size,&dest1[tempstartAddr-dflash_store_start]))
        {
            return BL_ERR_NOT_OK;
        }
        Bl_MemCpy(&dest1[dest-dflash_store_start],buffer,size);

        if((BL_ERR_OK) == Dflash_Erase(tempstartAddr,dflash_sector_size))
        {
            for(i = 0; i < dflash_store_size/CLIB_FLASH_D_PAGE_LENGTH; i++)
            {
                //INT_SYS_DisableIRQGlobal();
                if((STATUS_SUCCESS) == (FLASH_DRV_Program(FLASH_INST,tempstartAddr+i*CLIB_FLASH_D_PAGE_LENGTH,CLIB_FLASH_D_PAGE_LENGTH,&dest1[(tempstartAddr-dflash_store_start)+i*CLIB_FLASH_D_PAGE_LENGTH])))
                {
                    ret = BL_ERR_OK;
                }
                //INT_SYS_EnableIRQGlobal();
            }
            if(dflash_store_size % CLIB_FLASH_D_PAGE_LENGTH != 0)
            {
                //INT_SYS_DisableIRQGlobal();
                if((STATUS_SUCCESS) == (FLASH_DRV_Program(FLASH_INST,tempstartAddr+i*CLIB_FLASH_D_PAGE_LENGTH,CLIB_FLASH_D_PAGE_LENGTH,&dest1[(tempstartAddr-dflash_store_start)+i*CLIB_FLASH_D_PAGE_LENGTH])))
                {
                    ret = BL_ERR_OK;
                }
                //NT_SYS_EnableIRQGlobal();
            }

        }      
    }
    
	return ret;
}





/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_DRV_EnableCmdCompleteInterrupt
 * Description   : Enable the command complete interrupt is generated when
 * an EFM command completes.
 *
 * Implements    : FLASH_DRV_EnableCmdCompleteInterrupt_Activity
 *END**************************************************************************/
void FLASH_DRV_EnableCmdCompleteInterrupt(uint32_t instance)
{
    //DEV_ASSERT(instance < EFM_INSTANCE_COUNT);
    EFM_Type *base = s_efmBase[instance];

    /* Enable the command complete interrupt */
    base->CTRL |= EFM_CTRL_DONEIE_MASK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FLASH_DRV_EnableReadCollisionInterrupt
 * Description   : Enable the read collision error interrupt generation when an
 * EFM read collision error occurs.
 *
 * Implements    : FLASH_DRV_EnableReadCollisionInterrupt_Activity
 *END**************************************************************************/
void FLASH_DRV_EnableReadCollisionInterrupt(uint32_t instance)
{
    //DEV_ASSERT(instance < EFM_INSTANCE_COUNT);
    EFM_Type *base = s_efmBase[instance];

    /* Enable the read collision error interrupt */
    base->CTRL |= EFM_CTRL_ACCERRIE_MASK;
}

