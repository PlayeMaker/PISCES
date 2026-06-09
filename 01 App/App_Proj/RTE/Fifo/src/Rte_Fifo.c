/************************ Include Files ************************/
#include "Rte_Fifo.h"
#include "Rte_Fifo_Types.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Rte_Fifo_Copy_To(rte_fifo_config_t* fifo, const uint8_t* item, uint8_t size);
static void _Rte_Fifo_Copy_From(rte_fifo_config_t* fifo, uint8_t* item);
/************************ Private Function Implementations ************************/
/**
  * @brief  Copy data to the FIFO buffer
  * @param  fifo: Pointer to the FIFO structure
  * @param  item: Pointer to the data item to be put into the FIFO
  * @param  size: Size of the data item in bytes
  * @return None
  */
static void _Rte_Fifo_Copy_To(rte_fifo_config_t* fifo, const uint8_t* item, uint8_t size)
{
    uint8_t i = 0;
    fifo->stored_bytes += size + 1;
    fifo->item_space[fifo->write_offset] = size;
    if (fifo->write_offset++ > fifo->allocated_bytes)
    {
        fifo->write_offset = 0;
    }

    while (size--)
    {
        fifo->item_space[fifo->write_offset++] = item[i];
        if (fifo->write_offset >= fifo->allocated_bytes)
        {
            fifo->write_offset = 0;
        }
        i++;
    }
}
/**
  * @brief  Copy data from the FIFO buffer
  * @param  fifo: Pointer to the FIFO structure
  * @param  item: Pointer to the buffer where the data will be copied from the FIFO
  * @return None
  */
static void _Rte_Fifo_Copy_From(rte_fifo_config_t* fifo, uint8_t* item)
{
    uint8_t i                          = 1;
    uint8_t size                       = fifo->item_space[fifo->read_offset];
    fifo->item_space[fifo->read_offset] = 0;
    fifo->read_offset++;
    fifo->stored_bytes -= size + 1;
    item[0] = size;

    while (size--)
    {
        item[i]                             = fifo->item_space[fifo->read_offset];
        fifo->item_space[fifo->read_offset] = 0;
        fifo->read_offset++;
        if (fifo->read_offset >= fifo->allocated_bytes)
        {
            fifo->read_offset = 0;
        }
        i++;
    }
}
/************************ Public Function Implementations ************************/
/**
  * @brief  Create a FIFO instance with static memory allocation
  * @param  fifo: Pointer to the FIFO structure
  * @param  buf: Pointer to the buffer that will be used as the FIFO storage area
  * @param  size: Size of the buffer in bytes
  * @return State of the FIFO creation operation
  */
rte_fifo_status_e Rte_Fifo_Create_Static(rte_fifo_config_t* fifo, uint8_t* buf, uint8_t size)
{
    if (buf && fifo && size != 0)
    {
        fifo->item_space      = buf;
        fifo->allocated_bytes = size;
        fifo->read_offset     = 0;
        fifo->write_offset    = 0;
        fifo->stored_bytes    = 0;
        return RTE_FIFO_STATUS_SUCCESS;
    }
    return RTE_FIFO_STATUS_FAILURE;
}
/**
  * @brief  Put an item into the FIFO
  * @param  fifo: Pointer to the FIFO structure
  * @param  item: Pointer to the data item to be put into the FIFO
  * @param  size: Size of the data item in bytes
  * @return State of the FIFO put operation
  */
rte_fifo_status_e Rte_Fifo_Put(rte_fifo_config_t* fifo, const uint8_t* item, uint8_t size)
{
    if (RTE_FIFO_STATUS_SUCCESS == Rte_Fifo_Space_Is_Enough(fifo, size))
    {
        _Rte_Fifo_Copy_To(fifo, item, size);
        return RTE_FIFO_STATUS_SUCCESS;
    }
    else
    {
        return RTE_FIFO_STATUS_FAILURE;
    }
}
/**
  * @brief  Get an item from the FIFO
  * @param  fifo: Pointer to the FIFO structure
  * @param  item: Pointer to the buffer where the data will be copied from the FIFO
  * @return State of the FIFO get operation
  */
rte_fifo_status_e Rte_Fifo_Get(rte_fifo_config_t* fifo, uint8_t* item)
{
    rte_fifo_status_e result = RTE_FIFO_STATUS_FAILURE;
    if (fifo->stored_bytes == 0)
    {
        result = RTE_FIFO_STATUS_EMPTY;
    }
    else
    {
        _Rte_Fifo_Copy_From(fifo, item);
        result = RTE_FIFO_STATUS_SUCCESS;
    }
    return result;
}
/**
  * @brief  Check if the FIFO has enough space for an item
  * @param  fifo: Pointer to the FIFO structure
  * @param  size: Size of the data item in bytes
  * @return State of the FIFO space check operation
  */
rte_fifo_status_e Rte_Fifo_Space_Is_Enough(rte_fifo_config_t* fifo, uint8_t size)
{
    if ((fifo->stored_bytes + size + 1) > fifo->allocated_bytes)
        return RTE_FIFO_STATUS_NOT_ENOUGH_SPACE;
    else
        return RTE_FIFO_STATUS_SUCCESS;
}
