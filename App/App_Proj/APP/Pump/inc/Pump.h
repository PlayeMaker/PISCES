#ifndef _PUMP_H_
#define _PUMP_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
#include "Pump_Types.h"
/************************ Macro Definitions ************************/
#define PUMP_CONSTANT_PUMP_UPDATE_CYCLE      100U    // 气泵恒压更新周期,单位ms
#define PUMP_CONSTANT_PUMP_TARGET_VOLTAGE    12000U  // 气泵目标电压,单位mV
#define PUMP_CONSTANT_VOLTAGE_DUTY_CYCLE_MAX 100     // 气泵目标电压对应的最大占空比
#define PUMP_DUTY_FOR_CONST_VOLTAGE(vbat)                                                      \
    ((vbat) == 0U                                                                              \
         ? 0U                                                                                  \
         : ((vbat) <= PUMP_CONSTANT_PUMP_TARGET_VOLTAGE ? PUMP_CONSTANT_VOLTAGE_DUTY_CYCLE_MAX \
                                                        : ((float)PUMP_CONSTANT_PUMP_TARGET_VOLTAGE / (vbat) * 100.0f)))
/************************ Type Definitions ************************/
typedef enum
{
    PUMP_STATUS_ACTION    = 0,  // 气泵状态-动作
    PUMP_STATUS_NO_ACTION = 1,  // 气泵状态-空闲
    PUMP_STATUS_ERR       = 2,  // 气泵状态-故障
} pump_status_e;

typedef struct
{
    pump_work_state_e state;           // 气泵工作状态
    uint32_t          pump_work_mask;  // 气泵工作掩码,用于判断哪些模块需要开启气泵电源
} pump_config_t;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
void              Snf_Pump_Task(void);
void              Snf_Pump_Set_Work_State(pump_work_state_e state, uint32_t work_mask);
pump_work_state_e Snf_Pump_Get_Work_State(void);

#ifdef __cplusplus
}
#endif

#endif /* _PUMP_H_ */