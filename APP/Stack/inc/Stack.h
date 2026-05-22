#ifndef _STACK_H_
#define _STACK_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/
#define STACK_CAN_TP_TIMEOUT  10 // Unit: ms, timeout for CanTp main function, should be less than CAN_TASK_PERIOD_MS 
/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Stack_Task_Init(void);
void Snf_Stack_Task(void);

#ifdef __cplusplus
}
#endif

#endif /* _STACK_H_ */
