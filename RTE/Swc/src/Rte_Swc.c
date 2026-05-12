/************************ Include Files ************************/
#include "Rte_Swc.h"
#include <stdint.h>
#include "Rte_Swc_Types.h"
#include "Power.h"
#include "Rte_Swc_Com.h"
#include "Rte_Swc_Com_Cfg.h"
#include "App_Task.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/

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
