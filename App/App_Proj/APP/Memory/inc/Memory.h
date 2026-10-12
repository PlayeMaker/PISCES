#ifndef _MEMORY_H_
#define _MEMORY_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
#include <stdbool.h>
/************************ Macro Definitions ************************/
#define MEMORY_NVM_TIMEOUT_MAX (200000U) /* Maximum timeout for NvM operations */
/************************ Type Definitions ************************/

/************************ External Variables ************************/
extern uint8_t serial_number[16];
extern uint8_t manufacturing_date[3];
extern uint8_t faa_flag[1];
/************************ Function Declarations ************************/
void Snf_Memory_Task_Init(void);
void Snf_Memory_Task(void);
bool Snf_Memory_Sync_Read_Block(uint8_t blockId, uint8_t* dataBuffer);
bool Snf_Memory_Sync_Read_All_Block(void);
bool Snf_Memory_Sync_Write_Block(uint8_t blockId, uint8_t* dataBuffer);
bool Snf_Memory_Sync_Write_All_Block(void);

#ifdef __cplusplus
}
#endif

#endif /* _MEMORY_H_ */
