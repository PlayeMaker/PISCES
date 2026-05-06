/************************ Include Files ************************/
#include "Power_Message_Box.h"
#include <stdint.h>
#include "Rte_Swc_Com.h"
#include "Rte_Swc_Com_Cfg.h"
/************************ Macro Definitions ************************/
#define POWER_PRINTF(...)
/************************ Private Global Variables ************************/

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
 * @brief  Handle messages in the power message box, should be called periodically in the power task
 * @param  None
 * @return None
 */
void Snf_Power_Message_Box_Handle(void)
{
    uint8_t power_rev_buf[POWER_REV_BUF_SIZE] = {0};
    uint8_t power_rev_size = 0;
    if (RTE_FIFO_STATUS_SUCCESS == Rte_Swc_Fifo_Com_Handle(RTE_SWC_POWER_FIFO_ID, power_rev_buf, &power_rev_size))
    {
        // 处理接收到的数据
    }
}
