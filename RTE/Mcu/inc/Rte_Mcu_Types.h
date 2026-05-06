#ifndef _RTE_MCU_TYPES_H_
#define _RTE_MCU_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
typedef enum
{
    RTE_MCU_RESET_POWER_ON_RESET    = 0x00,  // Power on reset
    RTE_MCU_RESET_SOFTWARE_RESET    = 0x01,  // Software reset
    RTE_MCU_RESET_SWT_RESET         = 0x02,  // Soft Watchdog reset
    RTE_MCU_RESET_WAKE_UP_RESET     = 0x03,  // Wake up reset
    RTE_MCU_RESET_EXTERNAL_RESET    = 0x04,  // External reset
    RTE_MCU_RESET_DEBUG_RESET       = 0x05,  // Debug reset
    RTE_MCU_RESET_HSE_SWT_RESET     = 0x06,  // HSE Soft Watchdog reset
    RTE_MCU_RESET_HSE_BOOT_RESET    = 0x07,  // HSE Boot reset
    RTE_MCU_RESET_LOW_VOLTAGE_RESET = 0x08,  // Low voltage reset
    RTE_MCU_RESET_UNKNOWN_RESET     = 0xFF   // Unknown reset reason
} rte_mcu_reset_reason_e;

/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_MCU_TYPES_H_ */