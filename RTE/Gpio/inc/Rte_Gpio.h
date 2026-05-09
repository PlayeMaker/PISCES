#ifndef _RTE_GPIO_H_
#define _RTE_GPIO_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Drv_Gpio.h"
/************************ Macro Definitions ************************/
#define RTE_GPIO_INIT Snf_Drv_Gpio_Init
/************************ Type Definitions ************************/
typedef enum
{
    RTE_GPIO_LEVEL_LOW  = DRV_GPIO_LEVEL_LOW,
    RTE_GPIO_LEVEL_HIGH = DRV_GPIO_LEVEL_HIGH,
} rte_gpio_level_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_GPIO_H_ */