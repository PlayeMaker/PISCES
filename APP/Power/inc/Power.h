#ifndef _POWER_H_
#define _POWER_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/
#define POWER_BAT_UNDER_VOLT           8000U
#define POWER_BAT_OVER_VOLT            18000U
#define POWER_BAT_AD_TO_VOLT(ad_value) ((ad_value) * 61 / 10)
/************************ Type Definitions ************************/
typedef enum
{
    POWER_BAT_STATUS_NORMAL,
    POWER_BAT_STATUS_LOW_VOLT,
    POWER_BAT_STATUS_OVER_VOLT,
} power_bat_status_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Power_Task_Init(void);
void Snf_Power_Task(void);
void Snf_Power_Reset(void);

#ifdef __cplusplus
}
#endif

#endif /* _POWER_H_ */