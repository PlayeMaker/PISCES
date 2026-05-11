/************************ Include Files ************************/
#include "Basic_Config.h"
#include "Rte_Adc.h"
#include "Rte_Wdg.h"
#include "Rte_Log.h"
/************************ Macro Definitions ************************/
#ifdef SYSTEM_PRINTF_ENABLE
#define SYSTEM_PRINTF RTE_LOG_PRINTF
#else
#define SYSTEM_PRINTF(...)
#endif

/************************ Private Global Variables ************************/

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

/************************ Public Function Implementations ************************/
/**
 * @brief  System task function
 * @param  None
 * @return None
 */
void Snf_System_Task(void)
{
    RTE_WDG_REFRESH();
    _Snf_ADC_Start_Conversion();
}
