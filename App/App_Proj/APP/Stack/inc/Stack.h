#ifndef _STACK_H_
#define _STACK_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************ Include Files ************************/
#include <stdbool.h>
/************************ Macro Definitions ************************/
#define STACK_CAN_TP_TIMEOUT  10 // Unit: ms, timeout for CanTp main function, should be less than CAN_TASK_PERIOD_MS 
#define STACK_DTC_ENABLE_TIMEOUT  100
#define STACK_DTC_ENABLE_CONDITION_TIMEOUT1 1000 
#define STACK_DTC_ENABLE_CONDITION_TIMEOUT2 3000 
#define STACK_DTC_ENABLE_CONDITION_TIMEOUT3 3000 


/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Stack_Task_Init(void);
void Snf_Stack_Task(void);
void Set_Stack_CanNetwork_Status(bool status);

#ifdef __cplusplus
}
#endif

#endif /* _STACK_H_ */
