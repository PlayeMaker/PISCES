#ifndef _POWER_H_
#define _POWER_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
#include "Basic_Config.h"
#include "Power_Types.h"
/************************ Macro Definitions ************************/
// 电池电压检测相关参数
#define POWER_BAT_INVALID_VOLT         0xFFFFU
#define POWER_BAT_AD_TO_VOLT(ad_value) ((ad_value) * 61 / 10)

// 电源故障诊断相关参数
#define POWER_BAT_DETECTION_UPDATE_CYCLE  100U  // 电源故障诊断更新周期,单位ms
#define POWER_LOAD_DETECTION_UPDATE_CYCLE 100U  // 负载故障诊断更新周期,单位ms
#define POWER_VCS_K                       5404U
#if defined(HIGH_CONFIGURATION)
#define POWER_VCS_R 3300U
#elif defined(LOW_CONFIGURATION)
#define POWER_VCS_R 2000U
#endif
#define POWER_PUMP_VALVE_AD_TO_VCS(ad_value) ((ad_value) * POWER_VCS_K / POWER_VCS_R)
#define POWER_PUMP_OPEN_CIRCUIT              1     // 泵开路电流对应的AD值，单位为mA
#define POWER_PUMP_SHORT_CIRCUIT             1200  // 泵短路电流对应的AD值，单位为mA
#define POWER_VALVE_OPEN_CIRCUIT             1     // 阀开路电流对应的AD值，单位为mA
#define POWER_VALVE_SHORT_CIRCUIT            2000  // 阀短路电流对应的AD值，单位为mA
#define POWER_LOAD_CFG_SIZE                  2     // 负载配置数量
/************************ Type Definitions ************************/
typedef void (*power_decection_callback_f)(void);

typedef enum
{
    POWER_PNC_STATUS_INACTIVE = 0,
    POWER_PNC_STATUS_ACTIVE   = 1,
    POWER_PNC_STATUS_INVALID
} power_pnc_status_e;

typedef enum
{
    POWER_LOAD_STATUS_NORMAL,
    POWER_LOAD_STATUS_PUMP_OPEN_CIRCUIT,
    POWER_LOAD_STATUS_PUMP_SHORT_CIRCUIT,
    POWER_LOAD_STATUS_VALVE_OPEN_CIRCUIT,
    POWER_LOAD_STATUS_VALVE_SHORT_CIRCUIT,
} power_load_status_e;

typedef struct
{
    uint16_t                   voltage_min;         // 电压值，单位mV
    uint16_t                   voltage_max;         // 电压值，单位mV
    power_bat_status_e         status;              // 电池状态
    power_decection_callback_f decection_callback;  // 电池状态检测回调函数
} power_bat_decection_t;

typedef struct
{
    uint16_t                   circuit_min;          // 电流值，单位mA
    uint16_t                   circuit_max;          // 电流值，单位mA
    power_load_status_e        status;               // 负载状态
    power_decection_callback_f precection_callback;  // 负载状态检测前置条件回调函数
    power_decection_callback_f decection_callback;   // 负载状态检测回调函数
} power_load_decection_t;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
void               Snf_Power_Task_Init(void);
void               Snf_Power_Task(void);
void               Snf_Power_Reset(void);
uint16_t           Snf_Power_Get_Bat_Voltage(void);
power_bat_status_e Snf_Power_Bat_Get_State(void);

#ifdef __cplusplus
}
#endif

#endif /* _POWER_H_ */