/************************ Include Files ************************/
#include "Rte_Swc.h"
#include "Power_Types.h"
#include "Power_Bat.h"
#include "Rte_Swc_Types.h"
#include "Rte_Swc_Com.h"
#include "Rte_Swc_Com_Cfg.h"
#include "App_Task.h"
#include "Valve.h"
#include "System.h"
#if defined(HIGH_CONFIGURATION)
#include "Massage.h"
#endif
#include "Pump.h"
#include "Lumbar.h"
#include "Printf.h"
#include "Stack.h"
#include "Memory.h"
#include "Version.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
  * @brief  Initialize the main application task, should be called once at system startup
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_Main_S_App_Task_Init(void)
{
    Snf_App_Task_Init();
}
/**
  * @brief  Schedule the main application task, should be called periodically in the main loop or a dedicated task
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_Main_S_App_Task_Scheduler(void)
{
    Snf_App_Task_Scheduler_Handle();
}
/**
  * @brief  Initialize the system task, should be called once at system startup
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_System_Task_Init(void)
{
    Snf_System_Task_Init();
}
/**
  * @brief  System Task
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_System_Task_Scheduler(void)
{
    Snf_System_Task();
}
/**
  * @brief  Initialize the Vserion task, should be called once at Version startup
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_Version_Task_Init(void)
{
    Snf_Version_Task_Init();
}
/**
  * @brief  Initialize the power task, should be called once at power startup
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_Power_Task_Init(void)
{
    Snf_Power_Task_Init();
}
/**
  * @brief  Power Task
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_Power_Task_Scheduler(void)
{
    Snf_Power_Task();
}
/**
  * @brief  Initialize the massage task, should be called once at massage startup
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_Massage_Task_Init(void)
{
#if defined(HIGH_CONFIGURATION)
    Snf_Massage_Task_Init();
#endif
}
/**
  * @brief  Massage Task
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_Massage_Task_Scheduler(void)
{
#if defined(HIGH_CONFIGURATION)
    Snf_Massage_Task();
#endif
}
/**
  * @brief  Pump Task
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_Pump_Task_Scheduler(void)
{
    Snf_Pump_Task();
}
/**
  * @brief  Initialize the valve task, should be called once at valve startup
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_Valve_Task_Init(void)
{
    Snf_Valve_Task_Init();
}
/**
  * @brief  Valve Task
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_Valve_Task_Scheduler(void)
{
    Snf_Valve_Task();
}
/**
  * @brief  Lumbar Task
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_Lumbar_Task_Scheduler(void)
{
    Snf_Lumbar_Task();
}
/**
  * @brief  Printf Task
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_Printf_Task_Scheduler(void)
{
    Snf_Printf_Task();
}
/**
  * @brief  Initialize the Stack task, should be called once at Stack startup
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_Stack_Task_Init(void)
{
    Snf_Stack_Task_Init();
}
/**
  * @brief  Stack Task
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_Stack_Task_Scheduler(void)
{
    Snf_Stack_Task();
}
/**
  * @brief  Initialize the Memory task, should be called once at system startup
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_Memory_Task_Init(void)
{
    Snf_Memory_Task_Init();
}
/**
  * @brief  Schedule the Memory task, should be called periodically in the main loop or a dedicated task
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_Memory_Task_Scheduler(void)
{
    Snf_Memory_Task();
}
/**
  * @brief  Get the current battery voltage (Pump->Power)
  * @param  None
  * @return uint16_t: The current battery voltage in millivolts
  */
uint16_t Rte_Call_Sync_C_Pump_S_Power_Get_Voltage(void)
{
    return Snf_Power_Get_Bat_Voltage();
}
/**
  * @brief  Set the configuration of a valve (Lumbar->Valve)
  * @param  index: The index of the valve to configure
  * @param  state: The state to set the valve to
  * @return bool: True if the configuration was successful, false otherwise
  */
bool Rte_Call_Sync_C_Lumbar_S_Valve_Ramp_Control(uint8_t index, valve_state_e state)
{
    return Snf_Valve_Set_Config(index, state);
}
/**
  * @brief  Set the configuration of a valve (Massage->Valve)
  * @param  index: The index of the valve to configure
  * @param  state: The state to set the valve to
  * @return bool: True if the configuration was successful, false otherwise
  */
bool Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(uint8_t index, valve_state_e state)
{
    return Snf_Valve_Set_Config(index, state);
}
/**
  * @brief  Get version data by id (Massage->Version)
  * @param  id: The version data id (version_data_id_e)
  * @param  length: Output the data length in bytes, can be NULL
  * @return uint8_t*: The version data buffer pointer, NULL if id is invalid
  */
uint8_t* Rte_Call_Sync_C_Massage_S_Version_Get_Data(version_data_id_e id, uint8_t* length)
{
    return Snf_Version_Data_Get(id, length);
}
/**
  * @brief  Get the current battery states (Pump->Power)
  * @param  None
  * @return power_bat_status_e: The current battery status
  */
power_bat_status_e Rte_Call_Sync_C_Pump_S_Power_Get_Bat_States(void)
{
    return Snf_Power_Bat_Get_State();
}
/**
  * @brief  Get the current load states (Pump->Power)
  * @param  None
  * @return power_load_status_e: The current load status of the pump channel
  */
power_load_status_e Rte_Call_Sync_C_Pump_S_Power_Get_Load_States(void)
{
    return Snf_Power_Load_Get_State(POWER_LOAD_CHANNEL_PUMP);
}
/**
  * @brief  Get the current battery states (Valve->Power)
  * @param  None
  * @return power_bat_status_e: The current battery status
  */
power_bat_status_e Rte_Call_Sync_C_Valve_S_Power_Get_Bat_States(void)
{
    return Snf_Power_Bat_Get_State();
}
/**
  * @brief  Get the current load states (Valve->Power)
  * @param  None
  * @return power_load_status_e: The current load status of the valve channel
  */
power_load_status_e Rte_Call_Sync_C_Valve_S_Power_Get_Load_States(void)
{
    return Snf_Power_Load_Get_State(POWER_LOAD_CHANNEL_VALVE);
}
/**
  * @brief  Set the load states of both the valve and pump channels (Massage->Power)
  * @param  power_load_status_l: The load status to set
  * @return None
  */
void Rte_Call_Sync_C_Massage_S_Power_Set_Load_States(power_load_status_e power_load_status_l)
{
    Snf_Power_Set_Load_Status(POWER_LOAD_CHANNEL_VALVE, power_load_status_l);
    Snf_Power_Set_Load_Status(POWER_LOAD_CHANNEL_PUMP, power_load_status_l);
}
/**
  * @brief  Set the load states of both the valve and pump channels (Lumbar->Power)
  * @param  power_load_status_l: The load status to set
  * @return None
  */
void Rte_Call_Sync_C_Lumbar_S_Power_Set_Load_States(power_load_status_e power_load_status_l)
{
    Snf_Power_Set_Load_Status(POWER_LOAD_CHANNEL_VALVE, power_load_status_l);
    Snf_Power_Set_Load_Status(POWER_LOAD_CHANNEL_PUMP, power_load_status_l);
}
/**
  * @brief  Set the work states of the pump (Massage->Pump)
  * @param  state: The work state to set
  * @param  work_mask: The mask indicating which modules need the pump to work
  * @return None
  */
void Rte_Call_Sync_C_Massage_S_Pump_Set_Work_States(pump_work_state_e state, uint32_t work_mask)
{
    Snf_Pump_Set_Work_State(state, work_mask);
}
/**
  * @brief  Set the work states of the valve (Massage->Valve)
  * @param  state: The work state to set
  * @param  work_mask: The mask indicating which modules need the valve to work
  * @return None
  */
void Rte_Call_Sync_C_Massage_S_Valve_Set_Work_States(valve_work_state_e state, uint32_t work_mask)
{
    Snf_Valve_Set_Work_State(state, work_mask);
}
/**
  * @brief  Set the work states of the pump (Lumbar->Pump)
  * @param  state: The work state to set
  * @param  work_mask: The mask indicating which modules need the pump to work
  * @return None
  */
void Rte_Call_Sync_C_Lumbar_S_Pump_Set_Work_States(pump_work_state_e state, uint32_t work_mask)
{
    Snf_Pump_Set_Work_State(state, work_mask);
}
/**
  * @brief  Set the work states of the valve (Lumbar->Valve)
  * @param  state: The work state to set
  * @param  work_mask: The mask indicating which modules need the valve to work
  * @return None
  */
void Rte_Call_Sync_C_Lumbar_S_Valve_Set_Work_States(valve_work_state_e state, uint32_t work_mask)
{
    Snf_Valve_Set_Work_State(state, work_mask);
}
/**
  * @brief  Set the work states of the pump (Power->Pump)
  * @param  state: The work state to set
  * @param  work_mask: The mask indicating which modules need the pump to work
  * @return None
  */
void Rte_Call_Sync_C_Power_S_Pump_Set_Work_States(pump_work_state_e state, uint32_t work_mask)
{
    Snf_Pump_Set_Work_State(state, work_mask);
}
/**
  * @brief  Get the work states of the pump (Power->Pump)
  * @param  None
  * @return pump_work_state_e: The current work state of the pump
  */
pump_work_state_e Rte_Call_Sync_C_Power_S_Pump_Get_Work_States(void)
{
    return Snf_Pump_Get_Work_State();
}
/**
  * @brief  Set the work states of the Valve (Power->Valve)
  * @param  state: The work state to set
  * @param  work_mask: The mask indicating which modules need the valve to work
  * @return None
  */
void Rte_Call_Sync_C_Power_S_Valve_Set_Work_States(valve_work_state_e state, uint32_t work_mask)
{
    Snf_Valve_Set_Work_State(state, work_mask);
}
/**
  * @brief  Get the work states of the valve (Power->Valve)
  * @param  None
  * @return valve_work_state_e: The current work state of the valve
  */
valve_work_state_e Rte_Call_Sync_C_Power_S_Valve_Get_Work_States(void)
{
    return Snf_Valve_Get_Work_State();
}
/**
  * @brief  Read Nvm Block (Version->Memory)
  * @param  blockId: The block ID to read
  * @param  dataBuffer: The buffer to store the read data
  * @return bool: True if the read was successful, false otherwise
  */
bool Rte_Call_Sync_C_Version_S_Memory_Sync_Read_Block(uint8_t blockId, uint8_t* dataBuffer)
{
    return Snf_Memory_Sync_Read_Block(blockId, dataBuffer);
}
/**
  * @brief  Write Nvm Block (Version->Memory)
  * @param  blockId: The block ID to write
  * @param  dataBuffer: The data buffer to write
  * @return bool: True if the write was successful, false otherwise
  */
bool Rte_Call_Sync_C_Version_S_Memory_Sync_Write_Block(uint8_t blockId, uint8_t* dataBuffer)
{
    return Snf_Memory_Sync_Write_Block(blockId, dataBuffer);
}
/**
  * @brief  Write All Nvm Block (Power->Memory)
  * @param  None
  * @return bool: True if all blocks were written successfully, false otherwise
  */
bool Rte_Call_Sync_C_Power_S_Memory_Sync_Write_All_Block(void)
{
    return Snf_Memory_Sync_Write_All_Block();
}
/**
  * @brief  Read Nvm Block (Security->Memory)
  * @param  blockId: The block ID to read
  * @param  dataBuffer: The buffer to store the read data
  * @return bool: True if the read was successful, false otherwise
  */
bool Rte_Call_Sync_C_Security_S_Memory_Sync_Read_Block(uint8_t blockId, uint8_t* dataBuffer)
{
    return Snf_Memory_Sync_Read_Block(blockId, dataBuffer);
}
/**
  * @brief  Write Nvm Block (Security->Memory)
  * @param  blockId: The block ID to write
  * @param  dataBuffer: The data buffer to write
  * @return bool: True if the write was successful, false otherwise
  */
bool Rte_Call_Sync_C_Security_S_Memory_Sync_Write_Block(uint8_t blockId, uint8_t* dataBuffer)
{
    return Snf_Memory_Sync_Write_Block(blockId, dataBuffer);
}
/**
  * @brief  Get the work states of the pump (Massage->Pump)
  * @param  None
  * @return pump_work_state_e: The current work state of the pump
  */
pump_work_state_e Rte_Call_Sync_C_Massage_S_Pump_Get_Work_States(void)
{
    return Snf_Pump_Get_Work_State();
}
/**
  * @brief  Get the work states of the valve (Massage->Valve)
  * @param  None
  * @return valve_work_state_e: The current work state of the valve
  */
valve_work_state_e Rte_Call_Sync_C_Massage_S_Valve_Get_Work_States(void)
{
    return Snf_Valve_Get_Work_State();
}
/**
  * @brief  Get the work states of the pump (Stack->Pump)
  * @param  None
  * @return pump_work_state_e: The current work state of the pump
  */
pump_work_state_e Rte_Call_Sync_C_Stack_S_Pump_Get_Work_States(void)
{
    return Snf_Pump_Get_Work_State();
}
/**
  * @brief  Get the work states of the valve (Stack->Valve)
  * @param  None
  * @return valve_work_state_e: The current work state of the valve
  */
valve_work_state_e Rte_Call_Sync_C_Stack_S_Valve_Get_Work_States(void)
{
    return Snf_Valve_Get_Work_State();
}
/**
  * @brief  Set the can network status of the stack (CanSM->Stack)
  * @param  status: The can network status to set
  * @return None
  */
void Rte_Call_Sync_C_CanSM_S_Stack_Set_CanNetwork_Status(bool status)
{
    Set_Stack_CanNetwork_Status(status);
}
/**
  * @brief  Get the battery voltage of the stack (Stack->Power)
  * @param  None
  * @return uint16_t: The battery voltage
  */
uint16_t Rte_Call_Sync_C_Stack_S_Power_Get_Bat_Voltage(void)
{
    return Snf_Power_Get_Bat_Voltage();
}
/**
  * @brief  Get the battery voltage of the version (Version->Power)
  * @param  None
  * @return uint16_t: The battery voltage
  */
uint16_t Rte_Call_Sync_C_Version_S_Power_Get_Bat_Voltage(void)
{
    return Snf_Power_Get_Bat_Voltage();
}