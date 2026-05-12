/************************ Include Files ************************/
#include "App_Task.h"
#include "App_Task_Cfg.h"
#include "Basic_Types.h"
#include "Button_Com.h"
#include "Power.h"
#include "System.h"
#include "Air_Bag.h"
#include "Pump.h"
#include "Valve.h"
#include "Lumbar.h"
#include "Massage.h"
#include "Printf.h"
#include "Rte_Os.h"

/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/
static scheduler_t schedu_list[] = {
    { NULL,                           Snf_System_Task,           SYSTEM_TASK_PERIOD_MS,  TRUE, TRUE, 0 },
    { Snf_Power_Task_Init,            Snf_Power_Task,            POWER_TASK_PERIOD_MS,   TRUE, TRUE, 0 },
    { Snf_Button_Detection_Task_Init, Snf_Button_Detection_Task, BUTTON_TASK_PERIOD_MS,  TRUE, TRUE, 0 },
    { Snf_Massage_Task_Init,          Snf_Massage_Task,          MASSAGE_TASK_PERIOD_MS, TRUE, TRUE, 0 },
    { NULL,                           Snf_Pump_Task,             PUMP_TASK_PERIOD_MS,    TRUE, TRUE, 0 },
    { Snf_Valve_Task_Init,            Snf_Valve_Task,            VALVE_TASK_PERIOD_MS,   TRUE, TRUE, 0 },
    { Snf_Air_Bag_Task_Init,          Snf_Air_Bag_Task,          AIR_BAG_TASK_PERIOD_MS, TRUE, TRUE, 0 },
    { NULL,                           Snf_Lumbar_Task,           LUMBAR_TASK_PERIOD_MS,  TRUE, TRUE, 0 },
    { NULL,                           Snf_Printf_Task,           PRINTF_TASK_PERIOD_MS,  TRUE, TRUE, 0 },
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
