#ifndef _RTE_GPIO_IF_H_
#define _RTE_GPIO_IF_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Drv_Gpio.h"
/************************ Macro Definitions ************************/
#define RTE_GPIO_HEAT_ENABLE()             Snf_Drv_Gpio_Write(DRV_GPIO_PORT_D, DRV_GPIO_PIN_5, DRV_GPIO_LEVEL_HIGH)
#define RTE_GPIO_HEAT_DISABLE()            Snf_Drv_Gpio_Write(DRV_GPIO_PORT_D, DRV_GPIO_PIN_5, DRV_GPIO_LEVEL_LOW)

#define RTE_GPIO_HEAT5_ENABLE()            Snf_Drv_Gpio_Write(DRV_GPIO_PORT_C, DRV_GPIO_PIN_8, DRV_GPIO_LEVEL_HIGH)
#define RTE_GPIO_HEAT5_DISABLE()           Snf_Drv_Gpio_Write(DRV_GPIO_PORT_C, DRV_GPIO_PIN_8, DRV_GPIO_LEVEL_LOW)

#define RTE_GPIO_HEAT4_ENABLE()            Snf_Drv_Gpio_Write(DRV_GPIO_PORT_A, DRV_GPIO_PIN_7, DRV_GPIO_LEVEL_HIGH)
#define RTE_GPIO_HEAT4_DISABLE()           Snf_Drv_Gpio_Write(DRV_GPIO_PORT_A, DRV_GPIO_PIN_7, DRV_GPIO_LEVEL_LOW)

#define RTE_GPIO_HEAT3_ENABLE()            Snf_Drv_Gpio_Write(DRV_GPIO_PORT_A, DRV_GPIO_PIN_6, DRV_GPIO_LEVEL_HIGH)
#define RTE_GPIO_HEAT3_DISABLE()           Snf_Drv_Gpio_Write(DRV_GPIO_PORT_A, DRV_GPIO_PIN_6, DRV_GPIO_LEVEL_LOW)

#define RTE_GPIO_HEAT2_ENABLE()            Snf_Drv_Gpio_Write(DRV_GPIO_PORT_E, DRV_GPIO_PIN_7, DRV_GPIO_LEVEL_HIGH)
#define RTE_GPIO_HEAT2_DISABLE()           Snf_Drv_Gpio_Write(DRV_GPIO_PORT_E, DRV_GPIO_PIN_7, DRV_GPIO_LEVEL_LOW)

#define RTE_GPIO_HEAT1_ENABLE()            Snf_Drv_Gpio_Write(DRV_GPIO_PORT_B, DRV_GPIO_PIN_13, DRV_GPIO_LEVEL_HIGH)
#define RTE_GPIO_HEAT1_DISABLE()           Snf_Drv_Gpio_Write(DRV_GPIO_PORT_B, DRV_GPIO_PIN_13, DRV_GPIO_LEVEL_LOW)

#define RTE_GPIO_BAT_VOL_AD_ENABLE()       Snf_Drv_Gpio_Write(DRV_GPIO_PORT_B, DRV_GPIO_PIN_12, DRV_GPIO_LEVEL_HIGH)
#define RTE_GPIO_BAT_VOL_AD_DISABLE()      Snf_Drv_Gpio_Write(DRV_GPIO_PORT_B, DRV_GPIO_PIN_12, DRV_GPIO_LEVEL_LOW)

#define RTE_GPIO_5V_LOAD_ENABLE()          Snf_Drv_Gpio_Write(DRV_GPIO_PORT_D, DRV_GPIO_PIN_3, DRV_GPIO_LEVEL_HIGH)
#define RTE_GPIO_5V_LOAD_DISABLE()         Snf_Drv_Gpio_Write(DRV_GPIO_PORT_D, DRV_GPIO_PIN_3, DRV_GPIO_LEVEL_LOW)

#define RTE_GPIO_PUMP_ENABLE()             Snf_Drv_Gpio_Write(DRV_GPIO_PORT_E, DRV_GPIO_PIN_0, DRV_GPIO_LEVEL_HIGH)
#define RTE_GPIO_PUMP_DISABLE()            Snf_Drv_Gpio_Write(DRV_GPIO_PORT_E, DRV_GPIO_PIN_0, DRV_GPIO_LEVEL_LOW)

#define RTE_GPIO_VALVE_ENABLE()            Snf_Drv_Gpio_Write(DRV_GPIO_PORT_E, DRV_GPIO_PIN_1, DRV_GPIO_LEVEL_HIGH)
#define RTE_GPIO_VALVE_DISABLE()           Snf_Drv_Gpio_Write(DRV_GPIO_PORT_E, DRV_GPIO_PIN_1, DRV_GPIO_LEVEL_LOW)

#define RTE_GPIO_PUMP_VALVE_DSEL_ENABLE()  Snf_Drv_Gpio_Write(DRV_GPIO_PORT_C, DRV_GPIO_PIN_5, DRV_GPIO_LEVEL_HIGH)
#define RTE_GPIO_PUMP_VALVE_DSEL_DISABLE() Snf_Drv_Gpio_Write(DRV_GPIO_PORT_C, DRV_GPIO_PIN_5, DRV_GPIO_LEVEL_LOW)
/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_GPIO_IF_H_ */