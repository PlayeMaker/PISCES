#ifndef _POWER_LOAD_H_
#define _POWER_LOAD_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdbool.h>
#include <stdint.h>
#include "Power_Types.h"


#define POWER_LOAD_DETECTION_TABLE_SIZE 6

#define POWER_LOAD_TASK_TIMEOUT                 10
#define POWER_LOAD_CHANNEL_PERIOD_MS            100        //通道切换等待时间
#define POWER_LOAD_CHANNEL_SAMPLE_COUNT         200     //超时时间 = value - 通道切换等待时间，均值处理样本获取次数 = 超时时间/调度时间
#define POWER_LOAD_ADC_STABLE_TIME_MS           1000       //ADC值稳定确认时间，防止抖动


/************************ Function Declarations ************************/
void                Snf_Power_Load_Init(void);
void                Snf_Power_Load_Task(void);
bool                Snf_Power_Load_Is_Locked(void);
power_load_status_e Snf_Power_Load_Get_State(power_load_channel_e channel);
void                Snf_Power_Set_Load_Status(power_load_channel_e channel, power_load_status_e status);

#ifdef __cplusplus
}
#endif

#endif /* _POWER_LOAD_H_ */
