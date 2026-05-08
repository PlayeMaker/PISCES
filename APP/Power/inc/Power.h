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
#define POWER_PUMP_CLOSE_CIRCUIT             1200  // 泵短路电流对应的AD值，单位为mA
#define POWER_VALVE_CLOSE_CIRCUIT            2000  // 阀短路电流对应的AD值，单位为mA
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
    POWER_LOAD_STATUS_PUMP_CLOSE_CIRCUIT,
    POWER_LOAD_STATUS_VALVE_OPEN_CIRCUIT,
    POWER_LOAD_STATUS_VALVE_CLOSE_CIRCUIT,
} power_load_status_e;

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void     Snf_Power_Task_Init(void);
void     Snf_Power_Task(void);
void     Snf_Power_Reset(void);
uint16_t Snf_Power_Get_Bat_Voltage(void);

#ifdef __cplusplus
}
#endif

#endif /* _POWER_H_ */