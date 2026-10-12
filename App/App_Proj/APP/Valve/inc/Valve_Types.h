#ifndef _VALVE_TYPES_H_
#define _VALVE_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/
#define VALVE_ALL_MODULE_DISABLE_WORK_MASK 0
#define VALVE_ALL_MODULE_ENABLE_WORK_MASK  0xFFFFFFFF
#define VALVE_LUMBAR_WORK_MASK             0x01
#define VALVE_MASSAGE_WORK_MASK            0x02
/************************ Type Definitions ************************/
typedef enum
{
    POWER_VALVE_STATE_RAMP_UP,         // 缓升进行中
    POWER_VALVE_STATE_RAMP_UP_DONE,    // 缓升完成
    POWER_VALVE_STATE_RAMP_DOWN,       // 缓降进行中
    POWER_VALVE_STATE_RAMP_DOWN_DONE,  // 缓降完成
} valve_state_e;

typedef enum
{
    VALVE_WORK_STATE_OFF,       // 工作状态-关
    VALVE_WORK_STATE_ON,        // 工作状态-开
    VALVE_WORK_STATE_ABNORMAL,  // 工作状态-异常
} valve_work_state_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _VALVE_TYPES_H_ */