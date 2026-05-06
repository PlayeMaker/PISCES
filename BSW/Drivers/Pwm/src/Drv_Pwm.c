/************************ Include Files ************************/
#include "Drv_Pwm.h"
#include "Mcal.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
 * @brief  PWM initialization function
 * @param  None
 * @return None
 */
void Snf_Drv_Pwm_Init(void)
{
    Pwm_Init(&Pwm_Config);
}
