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
