#ifndef _POWER_BAT_H_
#define _POWER_BAT_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>

#include "Power_Types.h"

/************************ Function Declarations ************************/
void               Snf_Power_Bat_Init(void);
void               Snf_Power_Bat_Task(void);
uint16_t           Snf_Power_Get_Bat_Voltage(void);
power_bat_status_e Snf_Power_Bat_Get_State(void);

#ifdef __cplusplus
}
#endif

#endif /* _POWER_BAT_H_ */
