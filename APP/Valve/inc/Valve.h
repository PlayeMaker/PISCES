#ifndef _VALVE_H_
#define _VALVE_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
/************************ Macro Definitions ************************/
// 缓升缓降控制相关参数
#define VALVE_RAMP_STEP_VOLTAGE_TO_DUTY_CYCLE(vol) (vol * 100 / POWER_BAT_OPERATING_VOLT)  // 电压对应的占空比
/************************ Type Definitions ************************/
typedef enum
{
    POWER_VALVE_STATE_IDLE,
    POWER_VALVE_STATE_RAMP_UP,
    POWER_VALVE_STATE_RAMP_UP_DONE,
    POWER_VALVE_STATE_RAMP_DOWN,
    POWER_VALVE_STATE_RAMP_DOWN_DONE,
} power_valve_state_e;

typedef struct
{
    uint16_t voltage;       // 电压,单位mV
    uint16_t step_time_ms;  // 持续时间,单位ms
} power_valve_ramp_step_t;

typedef struct
{
    power_valve_state_e            state;
    uint32_t                       step_index;
    uint32_t                       last_timer_ms;  // 上一次执行的时间,单位ms
    const uint8_t*                 valve_list;     // 需要控制的阀列表
    uint32_t                       valve_list_size;
    const power_valve_ramp_step_t* step_up_list;  // 缓升步骤列表
    uint32_t                       step_up_list_size;
    const power_valve_ramp_step_t* step_down_list;  // 缓降步骤列表
    uint32_t                       step_down_list_size;
} power_valve_ramp_config_t;

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Valve_Task_Init(void);
void Snf_Valve_Task(void);

#ifdef __cplusplus
}
#endif

#endif /* _VALVE_H_ */