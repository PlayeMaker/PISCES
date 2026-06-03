#ifndef _PUMP_TYPES_H_
#define _PUMP_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/
#define PUMP_ALL_MODULE_DISABLE_WORK_MASK 0
#define PUMP_ALL_MODULE_ENABLE_WORK_MASK  0xFFFFFFFF
#define PUMP_LUMBAR_WORK_MASK             0x01
#define PUMP_MASSAGE_WORK_MASK            0x02
/************************ Type Definitions ************************/
/**
* @brief 气泵状态枚举
*/
typedef enum
{
    PUMP_WORK_STATE_OFF,  // 工作状态-关
    PUMP_WORK_STATE_ON,   // 工作状态-开
} pump_work_state_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _PUMP_TYPES_H_ */