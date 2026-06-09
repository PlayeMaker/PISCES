#ifndef _DRV_MCU_H_
#define _DRV_MCU_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
typedef enum
{
    DRV_MCU_RESET_POWER_ON_RESET    = 0x00,  // Power on reset
    DRV_MCU_RESET_SOFTWARE_RESET    = 0x01,  // Software reset
    DRV_MCU_RESET_SWT_RESET         = 0x02,  // Soft Watchdog reset
    DRV_MCU_RESET_WAKE_UP_RESET     = 0x03,  // Wake up reset
    DRV_MCU_RESET_EXTERNAL_RESET    = 0x04,  // External reset
    DRV_MCU_RESET_DEBUG_RESET       = 0x05,  // Debug reset
    DRV_MCU_RESET_HSE_SWT_RESET     = 0x06,  // HSE Soft Watchdog reset
    DRV_MCU_RESET_HSE_BOOT_RESET    = 0x07,  // HSE Boot reset
    DRV_MCU_RESET_LOW_VOLTAGE_RESET = 0x08,  // Low voltage reset
    DRV_MCU_RESET_UNKNOWN_RESET     = 0xFF   // Unknown reset reason
} drv_mcu_reset_reason_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Drv_Mcu_Init(void);
void Snf_Drv_Mcu_Reset(void);
drv_mcu_reset_reason_e Snf_Drv_Mcu_Get_Reset_Reason(void);

#ifdef __cplusplus
}
#endif

#endif /* _DRV_MCU_H_ */
