#ifndef _RTE_SWC_H_
#define _RTE_SWC_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
#include <stdbool.h>
#include "Rte_Swc_Types.h"
#include "Valve_Types.h"
/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Rte_Call_Sync_C_Main_S_App_Task_Init(void);
void Rte_Call_Sync_C_Main_S_App_Task_Scheduler(void);
void Rte_Call_Sync_C_App_Task_S_System_Task_Scheduler(void);
void Rte_Call_Sync_C_App_Task_S_Power_Task_Init(void);
void Rte_Call_Sync_C_App_Task_S_Power_Task_Scheduler(void);
void Rte_Call_Sync_C_App_Task_S_Massage_Task_Init(void);
void Rte_Call_Sync_C_App_Task_S_Massage_Task_Scheduler(void);
void Rte_Call_Sync_C_App_Task_S_Pump_Task_Scheduler(void);
void Rte_Call_Sync_C_App_Task_S_Valve_Task_Init(void);
void Rte_Call_Sync_C_App_Task_S_Valve_Task_Scheduler(void);
void Rte_Call_Sync_C_App_Task_S_Lumbar_Task_Scheduler(void);
void Rte_Call_Sync_C_App_Task_S_Printf_Task_Scheduler(void);
uint16_t Rte_Call_Sync_C_Pump_S_Power_Get_Voltage(void);
bool Rte_Call_Sync_C_Lumbar_S_Valve_Ramp_Control(uint8_t index, valve_state_e state);

#ifdef __cplusplus
}
#endif

#endif /* _RTE_SWC_H_ */