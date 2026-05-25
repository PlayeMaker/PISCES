/************************ Include Files ************************/
#include "Drv_Gpio.h"
#include "Mcal.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
 * @brief  GPIO initialization function
 * @param  None
 * @return None
 */
void Snf_Drv_Gpio_Init(void)
{
    Port_Init(&Port_Config);
}

/**
 * @brief  GPIO write function
 * @param  None
 * @return None
 */
void Snf_Drv_Gpio_Write(drv_gpio_port_e port, drv_gpio_pin_e pin, drv_gpio_level_e level)
{
    Dio_ChannelType channel = (Dio_ChannelType)PORT_PIN_TO_DIO_ID(port, pin);
    Dio_WriteChannel(channel, level);
}

/**
 * @brief  GPIO Read function
 * @param  None
 * @return None
 */
drv_gpio_level_e Snf_Drv_Gpio_Read(drv_gpio_port_e port, drv_gpio_pin_e pin)
{
    Dio_ChannelType channel = (Dio_ChannelType)PORT_PIN_TO_DIO_ID(port, pin);
    Dio_LevelType level = Dio_ReadChannel(channel);
    return (drv_gpio_level_e)level;
}
