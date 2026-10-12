#ifndef _PRINTF_H_
#define _PRINTF_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************ Include Files ************************/
#include <stdint.h>
#include <stdarg.h>
/************************ Macro Definitions ************************/
#define PRINTF_UART_TX_LEN         256
/************************ Type Definitions ************************/


/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Printf_Task(void);
void Snf_Printf(const char* fmt, ...);

#ifdef __cplusplus
}
#endif

#endif /* _PRINTF_H_ */