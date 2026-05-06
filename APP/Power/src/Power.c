/************************ Include Files ************************/
#include "Power.h"
#include <stdint.h>
#include "Rte_Mcu.h"
#include "Rte_Mcu_Types.h"
#include "Rte_Wdg.h"
#include "Rte_Log.h"
#include "Rte_Adc_If.h"
#include "Rte_Gpio_If.h"
#include "Power_Message_Box.h"
#include "Basic_Config.h"
/************************ Macro Definitions ************************/
#ifdef POWER_PRINTF_ENABLE
#define POWER_PRINTF RTE_LOG_PRINTF
#else
#define POWER_PRINTF(...)
#endif
/************************ Private Global Variables ************************/

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Power_Get_Response(void);
/************************ Private Function Implementations ************************/
/**
 * @brief  Get MCU reset reason
 * @param  None
 * @return None
 */
static void _Snf_Power_Get_Response(void)
{
    rte_mcu_reset_reason_e reset_reason = RTE_MCU_GET_RESET_REASON();
    POWER_PRINTF("Reset reason: %d\n", reset_reason);
}
/************************ Public Function Implementations ************************/
/**
 * @brief  Reset MCU
 * @param  None
 * @return None
 */
void Snf_Power_Reset(void)
{
    RTE_MCU_RESET();
}

/**
 * @brief  Initialize power task function
 * @param  None
 * @return None
 */
void Snf_Power_Task_Init(void)
{
    _Snf_Power_Get_Response();
    RTE_GPIO_BAT_VOL_AD_ENABLE();
}

/**
 * @brief  Power task function
 * @param  None
 * @return None
 */
void Snf_Power_Task(void)
{
        RTE_WDG_REFRESH();
    Snf_Power_Message_Box_Handle();
}
