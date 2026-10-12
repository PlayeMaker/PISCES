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

/**
 * @brief  PWM set duty cycle function
 * @param  channel - PWM channel
 * @param  duty_cycle - Duty cycle value
 * @return None
 */
void Snf_Drv_Pwm_Set_Duty(uint8_t channel, uint8_t duty_cycle)
{
    if(DRV_PWM_DUTY_CYCLE_MAX < duty_cycle)
    {
        duty_cycle = DRV_PWM_DUTY_CYCLE_MAX;
    }
    uint16_t tick = DRV_PWM_DUTY_CYCLE_TO_TICK(duty_cycle);
    Pwm_SetDutyCycle(channel, tick);
}

