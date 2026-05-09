#ifndef _RTE_PWM_IF_H_
#define _RTE_PWM_IF_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Drv_Pwm.h"
#include "Pwm_Cfg.h"
/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
#define RTE_PWM_DUTY_MAX                     100
#define RTE_PWM_DUTY_MIN                     0

#define RTE_PWM_SET_DUTY_YT2_EN(duty_cycle)  Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_YT2_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_AM1_EN(duty_cycle)  Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_AM1_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_AM8_EN(duty_cycle)  Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_AM8_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_AM9_EN(duty_cycle)  Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_AM9_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_AM10_EN(duty_cycle) Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_AM10_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_YT1_EN(duty_cycle)  Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_YT1_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_AM3_EN(duty_cycle)  Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_AM3_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_RNR1_EN(duty_cycle) Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_RNR1_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_RN1_EN(duty_cycle)  Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_RN1_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_PUMP_EN(duty_cycle) Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_PUMP_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_AM13_EN(duty_cycle) Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_AM13_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_AM14_EN(duty_cycle) Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_AM14_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_YLR1_EN(duty_cycle) Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_YLR1_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_YL1_EN(duty_cycle)  Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_YL1_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_AM4_EN(duty_cycle)  Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_AM4_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_AM5_EN(duty_cycle)  Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_AM5_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_AM6_EN(duty_cycle)  Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_AM6_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_RN2_EN(duty_cycle)  Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_RN2_EN, duty_cycle)
#define RTE_PWM_SET_DUTY_AM7_EN(duty_cycle)  Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_AM7_EN, duty cycle)
#define RTE_PWM_SET_DUTY_RNR2_EN(duty_cycle) Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_RNR2_EN, duty cycle)
#define RTE_PWM_SET_DUTY_AM2_EN(duty_cycle)  Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_AM2_EN, duty cycle)
#define RTE_PWM_SET_DUTY_YTR1_EN(duty_cycle) Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_YTR1_EN, duty cycle)
#define RTE_PWM_SET_DUTY_YTR2_EN(duty_cycle) Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_YTR2_EN, duty cycle)
#define RTE_PWM_SET_DUTY_AM11_EN(duty_cycle) Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_AM11_EN, duty cycle)
#define RTE_PWM_SET_DUTY_AM12_EN(duty_cycle) Snf_Drv_Pwm_Set_Duty(PwmConf_PwmChannel_PwmChannel_AM12_EN, duty cycle)

    /************************ External Variables ************************/

    /************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_PWM_IF_H_ */