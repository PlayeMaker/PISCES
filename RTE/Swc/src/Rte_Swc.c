/************************ Include Files ************************/
#include "Rte_Swc.h"
#include "Rte_Swc_Types.h"
#include "Power.h"
#include "Rte_Swc_Com.h"
#include "Rte_Swc_Com_Cfg.h"
#include "App_Task.h"
#include "Valve.h"
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
    /* 直接调用对应的同步函数 */
    Snf_App_Task_Init();
}
/**
  * @brief  Schedule the main application task, should be called periodically in the main loop or a dedicated task
  * @param  None
  * @return None
  */
void Rte_Call_Sync_C_Main_S_App_Task_Scheduler(void)
{
    /* 直接调用对应的同步函数 */
    Snf_App_Task_Scheduler_Handle();
}
/**
  * @brief  Get the current battery voltage
  * @param  None
  * @return uint16_t: The current battery voltage in millivolts
  */
uint16_t Rte_Call_Sync_C_Pump_S_Power_Get_Voltage(void)
{
    return Snf_Power_Get_Bat_Voltage();
}
/**
  * @brief  Set the configuration of a valve
  * @param  index: The index of the valve to configure
  * @param  state: The state to set the valve to
  * @return bool: True if the configuration was successful, false otherwise
  */
bool Rte_Call_Sync_C_Lumbar_S_Valve_Ramp_Control(uint8_t index, valve_state_e state)
{
    return Snf_Valve_Set_Config(index, state);
}
