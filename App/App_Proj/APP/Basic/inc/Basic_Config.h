#ifndef _BASIC_CONFIG_H_
#define _BASIC_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Project Definitions ************************/
#define HIGH_CONFIGURATION  // 高配版本
// #define LOW_CONFIGURATION // 低配版本

#if defined(HIGH_CONFIGURATION) && defined(LOW_CONFIGURATION)
#error "Must define only one of HIGH_CONFIGURATION or LOW_CONFIGURATION, not both"
#elif !defined(HIGH_CONFIGURATION) && !defined(LOW_CONFIGURATION)
#error "Must define HIGH_CONFIGURATION or LOW_CONFIGURATION"
#endif

#define PISCES_MCM_D  // 主驾
// #define PISCES_MCM_P // 副驾

#if defined(PISCES_MCM_D) && defined(PISCES_MCM_P)
#error "Must define only one of PISCES_MCM_D or PISCES_MCM_P, not both"
#elif !defined(PISCES_MCM_D) && !defined(PISCES_MCM_P)
#error "Must define PISCES_MCM_D or PISCES_MCM_P"
#endif

/************************ Function Definitions ************************/
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

#ifdef __cplusplus
}
#endif

#endif /* _BASIC_CONFIG_H_ */