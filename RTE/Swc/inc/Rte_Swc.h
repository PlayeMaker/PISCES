#ifndef _RTE_SWC_H_
#define _RTE_SWC_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
#include "Rte_Swc_Types.h"
/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Rte_Call_Sync_C_Main_S_App_Task_Init(void);
void Rte_Call_Sync_C_Main_S_App_Task_Scheduler(void);
uint16_t Rte_Call_Sync_C_Pump_S_Power_Get_Voltage(void);


#ifdef __cplusplus
}
#endif

#endif /* _RTE_SWC_H_ */