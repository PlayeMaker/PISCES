/************************ Include Files ************************/
#include "Rte_Fifo.h"
#include "Rte_Swc_Com.h"
#include <stdio.h>
#include "Rte_Swc_Com_Cfg.h"
#include "Rte_Fifo_Types.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/
static uint8_t           rte_swc_fifo_power_buf[RTE_SWC_POWER_FIFO_MAX_SIZE] = {0};
static rte_fifo_config_t rte_swc_fifo_power = {rte_swc_fifo_power_buf, RTE_SWC_POWER_FIFO_MAX_SIZE, 0, 0, 0};

static uint8_t           rte_swc_fifo_shell_Print_buf[RTE_SWC_SHELL_PRINT_FIFO_MAX_SIZE] = {0};
static rte_fifo_config_t rte_swc_fifo_shell_Print = {rte_swc_fifo_shell_Print_buf, RTE_SWC_SHELL_PRINT_FIFO_MAX_SIZE, 0, 0, 0};

static const rte_swc_com_t rte_swc_fifo_list[]    = {
    {RTE_SWC_POWER_FIFO_ID,       &rte_swc_fifo_power      },
    {RTE_SWC_SHELL_PRINT_FIFO_ID, &rte_swc_fifo_shell_Print},
};

static const uint8_t rte_swc_fifo_list_size = sizeof(rte_swc_fifo_list) / sizeof(rte_swc_fifo_list[0]);
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
 * @brief  Put data into the FIFO communication interface
 * @param  fifo_id: ID of the FIFO to put data into
 * @param  data: Pointer to the data to be put into the FIFO
 * @param  size: Size of the data in bytes
 * @return State of the FIFO put operation
 */
rte_fifo_status_e Rte_Swc_Fifo_Com_Put(uint8_t fifo_id, uint8_t* data, uint8_t size)
{
    rte_swc_com_t* list_ptr = NULL;
    if (!data || size == 0 || fifo_id >= rte_swc_fifo_list_size)
    {
        /* 参数无效，直接返回 */
        return RTE_FIFO_STATUS_PARAM_ERROR;
    }

    list_ptr = (rte_swc_com_t*)(&rte_swc_fifo_list[fifo_id]);

    return Rte_Fifo_Put(list_ptr->fifo, data, size);
}
/**
  * @brief  Handle FIFO operations, should be called periodically in the main loop or a dedicated task
  * @param  fifo_id: ID of the FIFO to handle
  * @param  data: Pointer to the data buffer to store the received data
  * @param  size: Pointer to the size of the data buffer in bytes
  * @return None
  */
rte_fifo_status_e Rte_Swc_Fifo_Com_Handle(uint8_t fifo_id, uint8_t* data, uint8_t* size)
{
    rte_fifo_status_e status   = RTE_FIFO_STATUS_FAILURE;
    rte_swc_com_t*    list_ptr = NULL;
    if (NULL == data || NULL == size || fifo_id >= rte_swc_fifo_list_size)
    {
        /* 参数无效，直接返回 */
        return RTE_FIFO_STATUS_PARAM_ERROR;
    }

    list_ptr = (rte_swc_com_t*)(rte_swc_fifo_list + fifo_id);

    status = Rte_Fifo_Get(list_ptr->fifo, data);
    if (RTE_FIFO_STATUS_SUCCESS == status)
    {
        *size = data[0]; /* 数据的第一个字节表示数据长度 */
        for (uint8_t i = 0; i < *size; i++)
        {
            data[i] = data[i + 1];
        }
    }
    return status;
}
