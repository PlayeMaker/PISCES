#ifndef _RTE_SWC_H_
#define _RTE_SWC_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
#include <stdbool.h>
#include "Basic_Config.h"
#include "Rte_Swc_Types.h"
#include "Valve_Types.h"
#include "Power_Types.h"
#include "Pump_Types.h"
#include "Valve_Types.h"
#include "Version.h"
/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void                Rte_Call_Sync_C_Main_S_App_Task_Init(void);
void                Rte_Call_Sync_C_Main_S_App_Task_Scheduler(void);
void                Rte_Call_Sync_C_App_Task_S_System_Task_Init(void);
void                Rte_Call_Sync_C_App_Task_S_System_Task_Scheduler(void);
void                Rte_Call_Sync_C_App_Task_S_Version_Task_Init(void);
void                Rte_Call_Sync_C_App_Task_S_Power_Task_Init(void);
void                Rte_Call_Sync_C_App_Task_S_Power_Task_Scheduler(void);
void                Rte_Call_Sync_C_App_Task_S_Massage_Task_Init(void);
void                Rte_Call_Sync_C_App_Task_S_Massage_Task_Scheduler(void);
void                Rte_Call_Sync_C_App_Task_S_Pump_Task_Scheduler(void);
void                Rte_Call_Sync_C_App_Task_S_Valve_Task_Init(void);
void                Rte_Call_Sync_C_App_Task_S_Valve_Task_Scheduler(void);
void                Rte_Call_Sync_C_App_Task_S_Lumbar_Task_Scheduler(void);
void                Rte_Call_Sync_C_App_Task_S_Printf_Task_Scheduler(void);
void                Rte_Call_Sync_C_App_Task_S_Stack_Task_Init(void);
void                Rte_Call_Sync_C_App_Task_S_Stack_Task_Scheduler(void);
void                Rte_Call_Sync_C_App_Task_S_Memory_Task_Init(void);
void                Rte_Call_Sync_C_App_Task_S_Memory_Task_Scheduler(void);
uint16_t            Rte_Call_Sync_C_Pump_S_Power_Get_Voltage(void);
bool                Rte_Call_Sync_C_Lumbar_S_Valve_Ramp_Control(uint8_t index, valve_state_e state);
bool                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(uint8_t index, valve_state_e state);
uint8_t*            Rte_Call_Sync_C_Massage_S_Version_Get_Data(version_data_id_e id, uint8_t* length);
power_bat_status_e  Rte_Call_Sync_C_Pump_S_Power_Get_Bat_States(void);
power_bat_status_e  Rte_Call_Sync_C_Valve_S_Power_Get_Bat_States(void);
void                Rte_Call_Sync_C_Lumbar_S_Pump_Set_Work_States(pump_work_state_e state, uint32_t work_mask);
void                Rte_Call_Sync_C_Lumbar_S_Valve_Set_Work_States(valve_work_state_e state, uint32_t work_mask);
void                Rte_Call_Sync_C_Power_S_Pump_Set_Work_States(pump_work_state_e state, uint32_t work_mask);
pump_work_state_e   Rte_Call_Sync_C_Power_S_Pump_Get_Work_States(void);
void                Rte_Call_Sync_C_Power_S_Valve_Set_Work_States(valve_work_state_e state, uint32_t work_mask);
valve_work_state_e  Rte_Call_Sync_C_Power_S_Valve_Get_Work_States(void);
power_load_status_e Rte_Call_Sync_C_Pump_S_Power_Get_Load_States(void);
power_load_status_e Rte_Call_Sync_C_Valve_S_Power_Get_Load_States(void);
void                Rte_Call_Sync_C_Massage_S_Power_Set_Load_States(power_load_status_e power_load_status_l);
void                Rte_Call_Sync_C_Lumbar_S_Power_Set_Load_States(power_load_status_e power_load_status_l);
void                Rte_Call_Sync_C_Massage_S_Pump_Set_Work_States(pump_work_state_e state, uint32_t work_mask);
void                Rte_Call_Sync_C_Massage_S_Valve_Set_Work_States(valve_work_state_e state, uint32_t work_mask);
bool                Rte_Call_Sync_C_Version_S_Memory_Sync_Read_Block(uint8_t blockId, uint8_t* dataBuffer);
bool                Rte_Call_Sync_C_Version_S_Memory_Sync_Write_Block(uint8_t blockId, uint8_t* dataBuffer);
bool                Rte_Call_Sync_C_Power_S_Memory_Sync_Write_All_Block(void);
bool                Rte_Call_Sync_C_Security_S_Memory_Sync_Read_Block(uint8_t blockId, uint8_t* dataBuffer);
bool                Rte_Call_Sync_C_Security_S_Memory_Sync_Write_Block(uint8_t blockId, uint8_t* dataBuffer);
pump_work_state_e   Rte_Call_Sync_C_Massage_S_Pump_Get_Work_States(void);
valve_work_state_e  Rte_Call_Sync_C_Massage_S_Valve_Get_Work_States(void);
pump_work_state_e   Rte_Call_Sync_C_Stack_S_Pump_Get_Work_States(void);
valve_work_state_e  Rte_Call_Sync_C_Stack_S_Valve_Get_Work_States(void);
uint16_t            Rte_Call_Sync_C_Stack_S_Power_Get_Bat_Voltage(void);
uint16_t            Rte_Call_Sync_C_Version_S_Power_Get_Bat_Voltage(void);

#ifdef __cplusplus
}
#endif

#endif /* _RTE_SWC_H_ */