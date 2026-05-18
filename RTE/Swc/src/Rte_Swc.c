/************************ Include Files ************************/
#include "Rte_Swc.h"
#include "Rte_Swc_Types.h"
#include "Rte_Swc_Com.h"
#include "Rte_Swc_Com_Cfg.h"
#include "App_Task.h"
#include "Valve.h"
#include "System.h"
#include "Power.h"
#include "Massage.h"
#include "Pump.h"
#include "Lumbar.h"
#include "Printf.h"
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
  * @brief  System Task
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_System_Task_Scheduler(void)
{
    Snf_System_Task();
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
    Snf_Massage_Task_Init();
}
/**
  * @brief  Massage Task
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_App_Task_S_Massage_Task_Scheduler(void)
{
    Snf_Massage_Task();
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