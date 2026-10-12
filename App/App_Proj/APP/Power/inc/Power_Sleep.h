#ifndef _POWER_SLEEP_H_
#define _POWER_SLEEP_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Power_Types.h"

typedef enum
{
    POWER_PNC_STATUS_INACTIVE = 0,
    POWER_PNC_STATUS_ACTIVE   = 1,
    POWER_PNC_STATUS_INVALID
} power_pnc_status_e;

/************************ Function Declarations ************************/
void                Snf_Power_Sleep_Init(void);
void                Snf_Power_Sleep_Task(void);
power_sleep_state_e Snf_Power_Sleep_Get_State(void);

#ifdef __cplusplus
}
#endif

#endif /* _POWER_SLEEP_H_ */
