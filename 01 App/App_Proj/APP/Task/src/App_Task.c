/************************ Include Files ************************/
#include "App_Task.h"
#include "App_Task_Cfg.h"
#include "Basic_Types.h"
#include "Rte_Os.h"
#include "Rte_Swc.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/
static scheduler_t schedu_list[] = {
    // clang-format off
    { Rte_Call_Sync_C_App_Task_S_System_Task_Init,  Rte_Call_Sync_C_App_Task_S_System_Task_Scheduler,  SYSTEM_TASK_PERIOD_MS,  TRUE, TRUE, 0 },
    { Rte_Call_Sync_C_App_Task_S_Power_Task_Init,   Rte_Call_Sync_C_App_Task_S_Power_Task_Scheduler,   POWER_TASK_PERIOD_MS,   TRUE, TRUE, 0 },
    { Rte_Call_Sync_C_App_Task_S_Stack_Task_Init,   Rte_Call_Sync_C_App_Task_S_Stack_Task_Scheduler,   STACK_TASK_PERIOD_MS,   TRUE, TRUE, 0 },
    { Rte_Call_Sync_C_App_Task_S_Massage_Task_Init, Rte_Call_Sync_C_App_Task_S_Massage_Task_Scheduler, MASSAGE_TASK_PERIOD_MS, TRUE, TRUE, 0 },
    { NULL,                                         Rte_Call_Sync_C_App_Task_S_Pump_Task_Scheduler,    PUMP_TASK_PERIOD_MS,    TRUE, TRUE, 0 },
    { Rte_Call_Sync_C_App_Task_S_Valve_Task_Init,   Rte_Call_Sync_C_App_Task_S_Valve_Task_Scheduler,   VALVE_TASK_PERIOD_MS,   TRUE, TRUE, 0 },
    { NULL,                                         Rte_Call_Sync_C_App_Task_S_Lumbar_Task_Scheduler,  LUMBAR_TASK_PERIOD_MS,  TRUE, TRUE, 0 },
    { NULL,                                         Rte_Call_Sync_C_App_Task_S_Printf_Task_Scheduler,  PRINTF_TASK_PERIOD_MS,  TRUE, TRUE, 0 },
};

static const uint8_t schedu_list_size = sizeof(schedu_list) / sizeof(schedu_list[0]);

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
 * @brief  Initialize task function
 * @param  None
 * @return None
 */
void Snf_App_Task_Init(void)
{
    scheduler_t* schedu_list_ptr = schedu_list;

    for (uint8_t i = 0; i < schedu_list_size; i++)
    {
        if (schedu_list_ptr->enable && NULL != schedu_list_ptr->init_func)
        {
            schedu_list_ptr->init_func();
        }
        schedu_list_ptr++;
    }
}

/**
 * @brief  Task scheduler handler function
 * @param  None
 * @return None
 */
void Snf_App_Task_Scheduler_Handle(void)
{
    scheduler_t* schedu_list_ptr = schedu_list;

    for (uint8_t i = 0; i < schedu_list_size; i++)
    {
        if (schedu_list_ptr->schedu_func)
        {
            if (schedu_list_ptr->enable)
            {
                if ((RTE_OS_IS_TIMEOUT(schedu_list_ptr->count, schedu_list_ptr->period)) || (0 == schedu_list_ptr->count))
                {
                    schedu_list_ptr->count = RTE_OS_GET_TICK();
                    schedu_list_ptr->schedu_func();
                    if (!(schedu_list_ptr->reuse))
                    {
                        schedu_list_ptr->enable = false;
                    }
                }
            }
        }
        schedu_list_ptr++;
    }
}
