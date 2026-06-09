#ifndef _RTE_PWM_IF_H_
#define _RTE_PWM_IF_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Drv_Pwm.h"
#include "Pwm_Cfg.h"
#include "Basic_Config.h"
/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
#define RTE_PWM_CHANNEL_NUM PWM_LOGIC_CHANNEL_NUM

#define RTE_PWM_DUTY_MAX 100
#define RTE_PWM_DUTY_MIN 0

#ifdef HIGH_CONFIGURATION
#define RTE_PWM_CHANNEL_YT2  PwmConf_PwmChannel_PwmChannel_YT2_EN   //对应气路图通道16
#define RTE_PWM_CHANNEL_AM1  PwmConf_PwmChannel_PwmChannel_AM1_EN   //对应气路图通道8
#define RTE_PWM_CHANNEL_AM8  PwmConf_PwmChannel_PwmChannel_AM8_EN   //对应气路图通道12
#define RTE_PWM_CHANNEL_AM9  PwmConf_PwmChannel_PwmChannel_AM9_EN   //对应气路图通道13
#define RTE_PWM_CHANNEL_AM10 PwmConf_PwmChannel_PwmChannel_AM10_EN  //对应气路图通道14
#define RTE_PWM_CHANNEL_YT1  PwmConf_PwmChannel_PwmChannel_YT1_EN   //对应气路图通道15
#define RTE_PWM_CHANNEL_AM3  PwmConf_PwmChannel_PwmChannel_AM3_EN   //对应气路图通道6
#define RTE_PWM_CHANNEL_RNR1 PwmConf_PwmChannel_PwmChannel_RNR1_EN  //对应气路图通道9-1
#define RTE_PWM_CHANNEL_RN1  PwmConf_PwmChannel_PwmChannel_RN1_EN   //对应气路图通道9
#define RTE_PWM_CHANNEL_PUMP PwmConf_PwmChannel_PwmChannel_PUMP_EN
#define RTE_PWM_CHANNEL_AM13 PwmConf_PwmChannel_PwmChannel_AM13_EN  //对应气路图通道19
#define RTE_PWM_CHANNEL_AM14 PwmConf_PwmChannel_PwmChannel_AM14_EN  //对应气路图通道20
#define RTE_PWM_CHANNEL_YLR1 PwmConf_PwmChannel_PwmChannel_YLR1_EN  //对应气路图通道11-1
#define RTE_PWM_CHANNEL_YL1  PwmConf_PwmChannel_PwmChannel_YL1_EN   //对应气路图通道11
#define RTE_PWM_CHANNEL_AM4  PwmConf_PwmChannel_PwmChannel_AM4_EN   //对应气路图通道5
#define RTE_PWM_CHANNEL_AM5  PwmConf_PwmChannel_PwmChannel_AM5_EN   //对应气路图通道4
#define RTE_PWM_CHANNEL_AM6  PwmConf_PwmChannel_PwmChannel_AM6_EN   //对应气路图通道3
#define RTE_PWM_CHANNEL_RN2  PwmConf_PwmChannel_PwmChannel_RN2_EN   //对应气路图通道2
#define RTE_PWM_CHANNEL_AM7  PwmConf_PwmChannel_PwmChannel_AM7_EN   //对应气路图通道1
#define RTE_PWM_CHANNEL_RNR2 PwmConf_PwmChannel_PwmChannel_RNR2_EN  //对应气路图通道2-1
#define RTE_PWM_CHANNEL_AM2  PwmConf_PwmChannel_PwmChannel_AM2_EN   //对应气路图通道7
#define RTE_PWM_CHANNEL_YTR1 PwmConf_PwmChannel_PwmChannel_YTR1_EN  //对应气路图通道15-1
#define RTE_PWM_CHANNEL_YTR2 PwmConf_PwmChannel_PwmChannel_YTR2_EN  //对应气路图通道16-1
#define RTE_PWM_CHANNEL_AM11 PwmConf_PwmChannel_PwmChannel_AM11_EN  //对应气路图通道17
#define RTE_PWM_CHANNEL_AM12 PwmConf_PwmChannel_PwmChannel_AM12_EN  //对应气路图通道18
#elif defined(LOW_CONFIGURATION)
#define RTE_PWM_CHANNEL_YT1  PwmConf_PwmChannel_PwmChannel_AM5_EN
#define RTE_PWM_CHANNEL_YTR1 PwmConf_PwmChannel_PwmChannel_AM13_EN
#define RTE_PWM_CHANNEL_YT2  PwmConf_PwmChannel_PwmChannel_AM6_EN
#define RTE_PWM_CHANNEL_YTR2 PwmConf_PwmChannel_PwmChannel_AM12_EN
#define RTE_PWM_CHANNEL_YT3  PwmConf_PwmChannel_PwmChannel_RN2_EN
#define RTE_PWM_CHANNEL_YTR3 PwmConf_PwmChannel_PwmChannel_AM11_EN
#define RTE_PWM_CHANNEL_YT4  PwmConf_PwmChannel_PwmChannel_AM7_EN
#define RTE_PWM_CHANNEL_YTR4 PwmConf_PwmChannel_PwmChannel_YTR2_EN
#define RTE_PWM_CHANNEL_YT5  PwmConf_PwmChannel_PwmChannel_RNR2_EN
#define RTE_PWM_CHANNEL_YTR5 PwmConf_PwmChannel_PwmChannel_YTR1_EN
#define RTE_PWM_CHANNEL_PUMP PwmConf_PwmChannel_PwmChannel_PUMP_EN
#endif
/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_PWM_IF_H_ */