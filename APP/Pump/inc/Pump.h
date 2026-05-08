#ifndef _PUMP_H_
#define _PUMP_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/
#define PUMP_CONSTANT_VOLTAGE_MIN            12000U
#define PUMP_CONSTANT_VOLTAGE_DUTY_CYCLE_MAX 100U
/************************ Type Definitions ************************/
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