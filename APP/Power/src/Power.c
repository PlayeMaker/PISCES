/************************ Include Files ************************/
#include "Power.h"
#include "Rte_Mcu.h"
#include "Rte_Mcu_Types.h"
#include "Rte_Wdg.h"
#include "Power_Message_Box.h"
/************************ Macro Definitions ************************/
#define POWER_PRINTF(...)
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
    (void)reset_reason; /* 避免未使用变量的编译警告 */
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
