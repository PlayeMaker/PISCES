#ifndef _BASIC_CONFIG_H_
#define _BASIC_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/
// 调试打印宏开关
#define DEBUG_PRINTF_ENABLE  // 总开关

#ifdef DEBUG_PRINTF_ENABLE
#define POWER_PRINTF_ENABLE
#define SYSTEM_PRINTF_ENABLE
#define PUMP_PRINTF_ENABLE
#define AIR_BAG_PRINTF_ENABLE
#define LUMBAR_PRINTF_ENABLE
#define VALVE_PRINTF_ENABLE
#define MASSAGE_PRINTF_ENABLE
#define STACK_PRINTF_ENABLE
#endif
/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _BASIC_CONFIG_H_ */