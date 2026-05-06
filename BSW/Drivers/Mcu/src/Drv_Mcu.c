/************************ Include Files ************************/
#include "Drv_Mcu.h"
#include "Mcal.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
 * @brief  Mcu initialization function
 * @param  None
 * @return None
 */
void Snf_Drv_Mcu_Init(void)
{
    Mcu_Init(&Mcu_Config);
    Mcu_InitClock(0);
#if (MCU_NO_PLL == STD_OFF)
    while (MCU_PLL_LOCKED != Mcu_GetPllStatus())
    {
        /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
#endif
}

/**
 * @brief  Mcu reset function
 * @param  None
 * @return None
 */
void Snf_Drv_Mcu_Reset(void)
{
    Mcu_PerformReset();
}
/**
 * @brief  Mcu initialization function
 * @param  None
 * @return None
 */
rte_mcu_reset_reason_e Snf_Drv_Mcu_Get_Reset_Reason(void)
{
    Mcu_ResetType          reset_reason = Mcu_GetResetReason();
    rte_mcu_reset_reason_e reset_reason_mapped; /* 映射后的复位原因 */

    switch (reset_reason)
    {
        case MCU_POR_BOR_RESET:
            reset_reason_mapped = RTE_MCU_RESET_POWER_ON_RESET; /* 映射为RTE_MCU_RESET_POWER_ON_RESET */
            break;
        case MCU_RESETB_RESET:
            reset_reason_mapped = RTE_MCU_RESET_EXTERNAL_RESET;
            break;
        case MCU_SW_RESET:
            reset_reason_mapped = RTE_MCU_RESET_SOFTWARE_RESET;
            break;
        case MCU_WATCHDOG_RESET:
            reset_reason_mapped = RTE_MCU_RESET_SWT_RESET; /* 将所有SWT复位原因映射为一个统一的值 */
            break;
        case MCU_DEBUG_RESET:
            reset_reason_mapped = RTE_MCU_RESET_DEBUG_RESET;
            break;
        case MCU_LVD_RESET:
            reset_reason_mapped = RTE_MCU_RESET_LOW_VOLTAGE_RESET;
            break;
        default:
            reset_reason_mapped = RTE_MCU_RESET_UNKNOWN_RESET; /* 未知复位原因 */
            break;
    }

    return reset_reason_mapped;
}
