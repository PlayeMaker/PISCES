/************************ Include Files ************************/
#include "Basic_Config.h"
#include "System.h"
#include "Rte_Adc.h"
#include "Rte_Wdg.h"
#include "Rte_Log.h"
#include "Rte_Os.h"
#include "NvM.h"
/************************ Macro Definitions ************************/
#ifdef SYSTEM_PRINTF_ENABLE
#define SYSTEM_PRINTF RTE_LOG_PRINTF
#else
#define SYSTEM_PRINTF(...)
#endif

/************************ Private Global Variables ************************/
static uint32 system_nvm_task_schedu_last_update_time = 0;
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_ADC_Start_Conversion(void);
/************************ Private Function Implementations ************************/
/**
 * @brief  Start ADC conversion
 * @param  None
 * @return None
 */
static void _Snf_ADC_Start_Conversion(void)
{
    RTE_ADC_CONVERSION();
}

/**
 * @brief  Handle NvM operations
 * @param  None
 * @return None
 */
static void _Snf_NvM_Handle(void)
{
    uint32                ReadAllTimeout = 0U;
    NvM_RequestResultType Result         = NVM_REQ_NOT_OK;
    if (RTE_OS_IS_TIMEOUT(system_nvm_task_schedu_last_update_time, SYSTEM_NVM_TASK_CYCLE_TIME))
    {
        system_nvm_task_schedu_last_update_time = RTE_OS_GET_TICK();
        do
        {
            NvM_MainFunction();
            Fee_MainFunction();
            Fls_MainFunction();
            NvM_GetErrorStatus(0, &Result);
            ReadAllTimeout++;
        } while ((Result == NVM_REQ_PENDING) && (ReadAllTimeout < SYSTEM_NVM_TIMEOUT_MAX));
    }
}

/************************ Public Function Implementations ************************/
/**
 * @brief  System task function initialization
 * @param  None
 * @return None
 */
void Snf_System_Task_Init(void)
{
    system_nvm_task_schedu_last_update_time = RTE_OS_GET_TICK();
    _Snf_ADC_Start_Conversion();
}

/**
 * @brief  System task function
 * @param  None
 * @return None
 */
void Snf_System_Task(void)
{
    RTE_WDG_REFRESH();
    _Snf_ADC_Start_Conversion();
    _Snf_NvM_Handle();
}
