#ifndef _RTE_GPIO_IF_H_
#define _RTE_GPIO_IF_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Drv_Gpio.h"
#include "Rte_Gpio_Types.h"
/************************ Macro Definitions ************************/
#define RTE_GPIO_BAT_VOL_AD_ENABLE()  Snf_Drv_Gpio_Write(DRV_GPIO_PORT_B, DRV_GPIO_PIN_12, RTE_GPIO_LEVEL_HIGH)
#define RTE_GPIO_BAT_VOL_AD_DISABLE() Snf_Drv_Gpio_Write(DRV_GPIO_PORT_B, DRV_GPIO_PIN_12, RTE_GPIO_LEVEL_LOW)
/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_GPIO_IF_H_ */