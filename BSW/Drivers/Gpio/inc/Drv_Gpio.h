#ifndef _DRV_GPIO_H_
#define _DRV_GPIO_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
/************************ Macro Definitions ************************/
#define PORT_PIN_TO_PORT_ID(port_index, pin_num) ((port_index) * 32 + (pin_num))
#define PORT_PIN_TO_DIO_ID(port_index, pin_num)  (((port_index) << 8) + (pin_num))
/************************ Type Definitions ************************/
typedef enum
{
    DRV_GPIO_LEVEL_LOW  = 0U,
    DRV_GPIO_LEVEL_HIGH = 1U,
} drv_gpio_level_e;

typedef enum
{
    DRV_GPIO_PORT_A = 0U,
    DRV_GPIO_PORT_B = 1U,
    DRV_GPIO_PORT_C = 2U,
    DRV_GPIO_PORT_D = 3U,
    DRV_GPIO_PORT_E = 4U,
    DRV_GPIO_PORT_F = 5U,
    DRV_GPIO_PORT_MAX
} drv_gpio_port_e;

typedef enum
{
    DRV_GPIO_PIN_0  = 0U,
    DRV_GPIO_PIN_1  = 1U,
    DRV_GPIO_PIN_2  = 2U,
    DRV_GPIO_PIN_3  = 3U,
    DRV_GPIO_PIN_4  = 4U,
    DRV_GPIO_PIN_5  = 5U,
    DRV_GPIO_PIN_6  = 6U,
    DRV_GPIO_PIN_7  = 7U,
    DRV_GPIO_PIN_8  = 8U,
    DRV_GPIO_PIN_9  = 9U,
    DRV_GPIO_PIN_10 = 10U,
    DRV_GPIO_PIN_11 = 11U,
    DRV_GPIO_PIN_12 = 12U,
    DRV_GPIO_PIN_13 = 13U,
    DRV_GPIO_PIN_14 = 14U,
    DRV_GPIO_PIN_15 = 15U,
    DRV_GPIO_PIN_MAX
} drv_gpio_pin_e;

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Drv_Gpio_Init(void);
void Snf_Drv_Gpio_Write(drv_gpio_port_e port, drv_gpio_pin_e pin, drv_gpio_level_e level);
drv_gpio_level_e Snf_Drv_Gpio_Read(drv_gpio_port_e port, drv_gpio_pin_e pin);

#ifdef __cplusplus
}
#endif

#endif /* _DRV_GPIO_H_ */
