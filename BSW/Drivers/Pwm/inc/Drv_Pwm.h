#ifndef _DRV_PWM_H_
#define _DRV_PWM_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
#define PWM_DUTY_CYCLE_TICK_MAX      (32768U)
#define PWM_DUTY_CYCLE_TO_TICK(duty) ((duty) * PWM_DUTY_CYCLE_TICK_MAX / 100U)
/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Drv_Pwm_Init(void);
void Snf_Drv_Pwm_Set_Duty(uint8_t channel, uint16_t duty_cycle);

#ifdef __cplusplus
}
#endif

#endif /* _DRV_PWM_H_ */
