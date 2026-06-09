#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/
#define SYSTEM_NVM_TASK_CYCLE_TIME (100U)        /* Cycle time for NvM task in milliseconds */
#define SYSTEM_NVM_TIMEOUT_MAX     (0xFFFFFFFFU) /* Maximum timeout for NvM operations */
/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_System_Task_Init(void);
void Snf_System_Task(void);

#ifdef __cplusplus
}
#endif

#endif /* _SYSTEM_H_ */
