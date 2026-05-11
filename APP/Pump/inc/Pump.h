#ifndef _PUMP_H_
#define _PUMP_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/
#define PUMP_CONSTANT_PUMP_TARGET_VOLTAGE    12000U  // 气泵目标电压,单位mV
#define PUMP_CONSTANT_VOLTAGE_DUTY_CYCLE_MAX 100     // 气泵目标电压对应的最大占空比
#define PUMP_DUTY_FOR_CONST_VOLTAGE(vbat)                                               \
    ((vbat) <= PUMP_CONSTANT_PUMP_TARGET_VOLTAGE ? PUMP_CONSTANT_VOLTAGE_DUTY_CYCLE_MAX \
                                                 : ((float)PUMP_CONSTANT_PUMP_TARGET_VOLTAGE / (vbat) * 100.0f))
/************************ Type Definitions ************************/
/**
* @brief 气泵状态枚举
*/
typedef enum
{
    PUMP_STATE_IDLE          = 0U,  // 气泵空闲状态
    PUMP_STATE_AIR_INFLATION = 1U,  // 气泵充气
    PUMP_STATE_AIR_DEFLATION = 2U,  // 气泵抽气
} pump_state_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Pump_Task(void);

#ifdef __cplusplus
}
#endif

#endif /* _PUMP_H_ */