#ifndef _POWER_COM_H_
#define _POWER_COM_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
#include <stdbool.h>

#include "Power_Types.h"

#define POWER_REV_BUF_SIZE           32
#define POWER_5V_LOAD_ENABLE_TIMEOUT 1
/************************ Function Declarations ************************/
void               Snf_Power_Task_Init(void);
void               Snf_Power_Task(void);
void               Snf_Power_Reset(void);
power_bat_status_e Snf_Power_Bat_Get_State(void);
bool               Snf_Power_Load_Is_Locked(void);

#ifdef __cplusplus
}
#endif

#endif /* _POWER_COM_H_ */