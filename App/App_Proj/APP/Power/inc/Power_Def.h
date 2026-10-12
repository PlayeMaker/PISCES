#ifndef _POWER_DEF_H_
#define _POWER_DEF_H_

/************************ Basic Configuration ************************/
#define POWER_BAT_INVALID_VOLT           0xFFFFU
#define POWER_BAT_AD_TO_VOLT(ad_value)   ((ad_value) * 61 / 10)
#define POWER_BAT_DETECTION_UPDATE_CYCLE 100U
#define POWER_BAT_STATUS_CONFIRM_TIME_MS 1000U  //电压区间持续确认时间，超过后才切换状态并执行回调
#define POWER_BAT_STATUS_CONFIRM_COUNT   (POWER_BAT_STATUS_CONFIRM_TIME_MS / POWER_BAT_DETECTION_UPDATE_CYCLE)

#define POWER_LOAD_DETECTION_UPDATE_CYCLE     100U
#define POWER_LOAD_SHORT_CIRCUIT_CONFIRM_TIME 200U
#if defined(HIGH_CONFIGURATION)
#define POWER_VCS_K 5404U
#define POWER_VCS_R 3300U
#elif defined(LOW_CONFIGURATION)
#define POWER_VCS_K 1800U
#define POWER_VCS_R 2000U
#endif
#define POWER_PUMP_VALVE_AD_TO_VCS(ad_value) ((ad_value) * POWER_VCS_K / POWER_VCS_R)
#if defined(HIGH_CONFIGURATION)
#define POWER_PUMP_OPEN_CIRCUIT   10    // 泵开路电流对应的AD值，单位为mA
#define POWER_PUMP_SHORT_CIRCUIT  4000  // 泵短路电流对应的AD值，单位为mA
#define POWER_VALVE_OPEN_CIRCUIT  10    // 阀开路电流对应的AD值，单位为mA
#define POWER_VALVE_SHORT_CIRCUIT 4000  // 阀短路电流对应的AD值，单位为mA
#elif defined(LOW_CONFIGURATION)
#define POWER_PUMP_OPEN_CIRCUIT   10    // 泵开路电流对应的AD值，单位为mA
#define POWER_PUMP_SHORT_CIRCUIT  2500  // 泵短路电流对应的AD值，单位为mA
#define POWER_VALVE_OPEN_CIRCUIT  10    // 阀开路电流对应的AD值，单位为mA
#define POWER_VALVE_SHORT_CIRCUIT 2500  // 阀短路电流对应的AD值，单位为mA
#endif

#endif /* _POWER_DEF_H_ */
