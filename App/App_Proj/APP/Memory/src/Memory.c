/************************ Include Files ************************/
#include "Basic_Config.h"
#include "Memory.h"
#include "Rte_Log.h"
#include "NvM.h"
#include "Rte_NvM.h"
/************************ Macro Definitions ************************/
#ifdef MEMORY_PRINTF_ENABLE
#define MEMORY_PRINTF RTE_LOG_PRINTF
#else
#define MEMORY_PRINTF(...)
#endif

/************************ Private Global Variables ************************/

/************************ Public Global Variables ************************/
uint8_t serial_number[16]     = { 0 };
uint8_t manufacturing_date[3] = { 0 };
uint8_t faa_flag[1]           = { 0 };
/************************ Private Function Declarations ************************/
static bool _Snf_NvM_Handle(uint8_t blockId);
/************************ Private Function Implementations ************************/
/**
 * @brief  Handle NvM operations
 * @param  blockId: ID of the block to be handled
 * @return None
 */
static bool _Snf_NvM_Handle(uint8_t blockId)
{
    bool                  result         = true;
    uint32                ReadAllTimeout = 0U;
    NvM_RequestResultType Result         = NVM_REQ_NOT_OK;

    do
    {
        NvM_MainFunction();
        Fee_MainFunction();
        Fls_MainFunction();
        NvM_GetErrorStatus(blockId, &Result);
        ReadAllTimeout++;
    } while ((Result == NVM_REQ_PENDING) && (ReadAllTimeout < MEMORY_NVM_TIMEOUT_MAX));

    if (ReadAllTimeout >= MEMORY_NVM_TIMEOUT_MAX)
    {
        result = false;
        MEMORY_PRINTF("NvM operation timeout for blockId: %d\n", blockId);
    }
    else if (Result != NVM_REQ_OK)
    {
        result = false;
        // MEMORY_PRINTF("NvM operation failed for blockId: %d, Result: %d\n", blockId, Result);
    }

    return result;
}

/************************ Public Function Implementations ************************/
/**
 * @brief  Memory task function initialization
 * @param  blockId: ID of the block to be read
 * @param  dataBuffer: Pointer to the data buffer to be read
 * @return None
 */
bool Snf_Memory_Sync_Read_Block(uint8_t blockId, uint8_t* dataBuffer)
{
    NvM_ReadBlock(blockId, dataBuffer);
    return _Snf_NvM_Handle(blockId);
}
/**
 * @brief  Memory task function initialization
 * @param  blockId: ID of the block to be read
 * @param  dataBuffer: Pointer to the data buffer to be read
 * @return None
 */
bool Snf_Memory_Sync_Read_All_Block(void)
{
    Rte_Call_ReadAll_ReadAll();
    return _Snf_NvM_Handle(NvM_Block0);
}
/**
 * @brief  Memory task function initialization
 * @param  blockId: ID of the block to be written
 * @param  dataBuffer: Pointer to the data buffer to be written
 * @return None
 */
bool Snf_Memory_Sync_Write_Block(uint8_t blockId, uint8_t* dataBuffer)
{
    NvM_WriteBlock(blockId, dataBuffer);
    return _Snf_NvM_Handle(blockId);
}
/**
 * @brief  Memory task function initialization
 * @param  blockId: ID of the block to be written
 * @param  dataBuffer: Pointer to the data buffer to be written
 * @return None
 */
bool Snf_Memory_Sync_Write_All_Block(void)
{
    Rte_Call_WriteAll_WriteAll();
    return _Snf_NvM_Handle(NvM_Block0);
}
/**
 * @brief  Memory task function initialization
 * @param  None
 * @return None
 */
void Snf_Memory_Task_Init(void)
{
}

/**
 * @brief  Memory task function
 * @param  None
 * @return None
 */
void Snf_Memory_Task(void)
{
    _Snf_NvM_Handle(NvM_Block0);
}
