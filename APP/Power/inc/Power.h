#ifndef _POWER_H_
#define _POWER_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
/************************ Macro Definitions ************************/
#define POWER_BAT_UNDER_VOLT           8000U
#define POWER_BAT_OVER_VOLT            18000U
#define POWER_BAT_AD_TO_VOLT(ad_value) ((ad_value) * 61 / 10)

#define POWER_VCS_K                          5450U
#define POWER_PUMP_VALVE_AD_TO_VCS(ad_value) ((ad_value) * POWER_VCS_K / 6800)
#define POWER_PUMP_OPEN_CIRCUIT              10    // 泵开路电流对应的AD值，单位为mA
#define POWER_PUMP_SHORT_CIRCUIT             1200  // 泵短路电流对应的AD值，单位为mA
#define POWER_VALVE_SHORT_CIRCUIT            2000  // 阀短路电流对应的AD值，单位为mA

#define POWER_PUMP_CONSTANT_PUMP_UPDATE_CYCLE      100U    // 气泵恒压更新周期,单位ms
#define POWER_PUMP_CONSTANT_PUMP_TARGET_VOLTAGE    12000U  // 气泵目标电压,单位mV
#define POWER_PUMP_CONSTANT_VOLTAGE_DUTY_CYCLE_MAX 100     // 气泵目标电压对应的最大占空比
#define POWER_PUMP_DUTY_FOR_CONST_VOLTAGE(vbat)                                                     \
    ((vbat) <= POWER_PUMP_CONSTANT_PUMP_TARGET_VOLTAGE ? POWER_PUMP_CONSTANT_VOLTAGE_DUTY_CYCLE_MAX \
                                                       : ((float)POWER_PUMP_CONSTANT_PUMP_TARGET_VOLTAGE / (vbat) * 100.0f))
/************************ Type Definitions ************************/
typedef enum
{
    POWER_BAT_STATUS_NORMAL,
    POWER_BAT_STATUS_LOW_VOLT,
    POWER_BAT_STATUS_OVER_VOLT,
} power_bat_status_e;

typedef enum
{
    POWER_LOAD_STATUS_NORMAL,
    POWER_LOAD_STATUS_PUMP_OPEN_CIRCUIT,
    POWER_LOAD_STATUS_PUMP_SHORT_CIRCUIT,
    POWER_LOAD_STATUS_VALVE_OPEN_CIRCUIT,
    POWER_LOAD_STATUS_VALVE_SHORT_CIRCUIT,
} power_load_status_e;

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void     Snf_Power_Task_Init(void);
void     Snf_Power_Task(void);
void     Snf_Power_Reset(void);

#ifdef __cplusplus
}
#endif

#endif /* _POWER_H_ */