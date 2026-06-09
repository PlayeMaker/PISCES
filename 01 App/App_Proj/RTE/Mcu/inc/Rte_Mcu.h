#ifndef _RTE_MCU_H_
#define _RTE_MCU_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Drv_Mcu.h"
/************************ Macro Definitions ************************/
#define RTE_MCU_INIT             Snf_Drv_Mcu_Init
#define RTE_MCU_GET_RESET_REASON (rte_mcu_reset_reason_e) Snf_Drv_Mcu_Get_Reset_Reason
#define RTE_MCU_RESET            Snf_Drv_Mcu_Reset
/************************ Type Definitions ************************/
typedef enum
{
    RTE_MCU_RESET_POWER_ON_RESET    = DRV_MCU_RESET_POWER_ON_RESET,     // Power on reset
    RTE_MCU_RESET_SOFTWARE_RESET    = DRV_MCU_RESET_SOFTWARE_RESET,     // Software reset
    RTE_MCU_RESET_SWT_RESET         = DRV_MCU_RESET_SWT_RESET,          // Soft Watchdog reset
    RTE_MCU_RESET_WAKE_UP_RESET     = DRV_MCU_RESET_WAKE_UP_RESET,      // Wake up reset
    RTE_MCU_RESET_EXTERNAL_RESET    = DRV_MCU_RESET_EXTERNAL_RESET,     // External reset
    RTE_MCU_RESET_DEBUG_Reset       = DRV_MCU_RESET_DEBUG_RESET,        // Debug reset
    RTE_MCU_RESET_HSE_SWT_RESET     = DRV_MCU_RESET_HSE_SWT_RESET,      // HSE Soft Watchdog reset
    RTE_MCU_RESET_HSE_BOOT_RESET    = DRV_MCU_RESET_HSE_BOOT_RESET,     // HSE Boot reset
    RTE_MCU_RESET_LOW_VOLTAGE_RESET = DRV_MCU_RESET_LOW_VOLTAGE_RESET,  // Low voltage reset
    RTE_MCU_RESET_UNKNOWN_RESET     = DRV_MCU_RESET_UNKNOWN_RESET       // Unknown reset reason
} rte_mcu_reset_reason_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_MCU_H_ */