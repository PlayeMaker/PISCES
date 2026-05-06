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
rte_swc_event_e Rte_Write_S_Net_Manage_R_Power_Sleep_State(uint8_t data);
rte_swc_event_e Rte_Read_S_Net_Manage_R_Power_Sleep_State(uint8_t* data);
rte_swc_event_e Rte_Call_Sync_C_Button_S_Power_Reset(void);
rte_swc_event_e Rte_Call_Async_C_Button_S_Power_Reset(uint8_t* data, uint8_t size);

#ifdef __cplusplus
}
#endif

#endif /* _RTE_SWC_H_ */