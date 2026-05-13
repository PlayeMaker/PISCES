#ifndef _VALVE_H_
#define _VALVE_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "Valve_Types.h"
#include "Rte_Pwm_If.h"
/************************ Macro Definitions ************************/
// 缓升缓降控制相关参数
#define VALVE_RAMP_MEMBER_NUM                      RTE_PWM_CHANNEL_NUM                 // 缓升缓降组数量
#define VALVE_OPERATING_VOLT                       14400U                              // 电压,单位mV
#define VALVE_RAMP_STEP_VOLTAGE_TO_DUTY_CYCLE(vol) (vol * 100 / VALVE_OPERATING_VOLT)  // 电压对应的占空比
/************************ Type Definitions ************************/
typedef struct
{
    const uint16_t voltage;       // 电压,单位mV
    const uint16_t step_time_ms;  // 持续时间,单位ms
} valve_ramp_step_t;

typedef struct
{
    valve_state_e state;
    uint32_t      step_index;
    uint32_t      last_timer_ms;  // 上一次执行的时间,单位ms
} valve_ramp_group_t;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
bool Snf_Valve_Set_Config(uint8_t index, valve_state_e state);
void Snf_Valve_Task_Init(void);
void Snf_Valve_Task(void);

#ifdef __cplusplus
}
#endif

#endif /* _VALVE_H_ */