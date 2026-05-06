#ifndef _POWER_H_
#define _POWER_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Power_Task_Init(void);
void Snf_Power_Task(void);
void Snf_Power_Reset(void);

#ifdef __cplusplus
}
#endif

#endif /* _POWER_H_ */