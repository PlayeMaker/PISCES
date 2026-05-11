#ifndef _DRV_OS_H_
#define _DRV_OS_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
#include <stdbool.h>
/************************ Macro Definitions ************************/
#define DRV_OS_SYSTEM_CORE_CLOCK 80000000U
#define DRV_OS_MAX_TICK          0xFFFFFFFFU
/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void     Snf_Os_init(void);
uint32_t Snf_Os_Get_Tick(void);
bool     Snf_Os_Is_Timeout(uint32_t last_tick, uint32_t timeout);

#ifdef __cplusplus
}
#endif

#endif /* _DRV_OS_H_ */
