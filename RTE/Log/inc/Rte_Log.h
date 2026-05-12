#ifndef _RTE_LOG_H_
#define _RTE_LOG_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Printf.h"
#include "Basic_Config.h"
/************************ Macro Definitions ************************/
#ifdef DEBUG_PRINTF_ENABLE
#define RTE_LOG_PRINTF Snf_Printf
#else
#define RTE_LOG_PRINTF(...)
#endif
/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_LOG_H_ */