#ifndef _RTE_OS_H_
#define _RTE_OS_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Drv_Os.h"
#include "OsIf.h"
/************************ Macro Definitions ************************/
#define RTE_OS_INIT                   Snf_Os_init
#define RTE_OS_GET_TICK               Snf_Os_Get_Tick
#define RTE_OS_IS_TIMEOUT             Snf_Os_Is_Timeout
#define RTE_OS_SUSPEND_ALL_INTERRUPTS OsIf_SuspendAllInterrupts
#define RTE_OS_RESUME_ALL_INTERRUPTS  OsIf_ResumeAllInterrupts
/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_OS_H_ */