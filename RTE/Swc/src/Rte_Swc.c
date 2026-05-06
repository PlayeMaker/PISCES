/************************ Include Files ************************/
#include "Rte_Swc.h"
#include "Rte_Swc_Types.h"
#include "Power.h"
#include "Rte_Swc_Com.h"
#include "Rte_Swc_Com_Cfg.h"
#include "App_Task.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/
static uint8_t rte_power_sleep_state = 0;
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
  * @brief  Initialize the main application task, should be called once at system startup
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_Main_S_App_Task_Init(void)
{
    /* 直接调用对应的同步函数 */
    /* 调用 Snf_App_Task_Init 函数进行应用程序任务初始化 */
    Snf_App_Task_Init();
}
/**
  * @brief  Schedule the main application task, should be called periodically in the main loop or a dedicated task
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_Main_S_App_Task_Scheduler(void)
{
    /* 直接调用对应的同步函数 */
    Snf_App_Task_Scheduler_Handle();
}

rte_swc_event_e Rte_Write_S_Net_Manage_R_Power_Sleep_State(uint8_t data)
{
    /* 直接将数据写入对应的输入端口 */
    rte_power_sleep_state = data;
    return RTE_SWC_EVENT_OK;
}

rte_swc_event_e Rte_Read_S_Net_Manage_R_Power_Sleep_State(uint8_t* data)
{
    if (NULL == data)
    {
        return RTE_SWC_EVENT_ERROR;
    }
    /* 直接将数据写入对应的输出端口 */
    *data = rte_power_sleep_state;

    return RTE_SWC_EVENT_OK;
}

rte_swc_event_e Rte_Call_Sync_C_Button_S_Power_Reset(void)
{
    /* 直接调用对应的同步函数 */
    Snf_Power_Reset();
    return RTE_SWC_EVENT_OK;
}

rte_swc_event_e Rte_Call_Async_C_Button_S_Power_Reset(uint8_t* data, uint8_t size)
{
    rte_swc_event_e event_ret = RTE_SWC_EVENT_OK;
    /* 直接调用对应的异步函数 */
    if (RTE_FIFO_STATUS_SUCCESS != Rte_Swc_Fifo_Com_Put(RTE_SWC_POWER_FIFO_ID, data, size))
    {
        event_ret = RTE_SWC_EVENT_ERROR;
    }
    return event_ret;
}
