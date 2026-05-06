#ifndef _SHELL_H_
#define _SHELL_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************ Include Files ************************/
#include <stdint.h>
#include <stdarg.h>
/************************ Macro Definitions ************************/
#define SHELL_UART_TX_LEN         256
#define SHELL_UART_RX_LEN         256
/************************ Type Definitions ************************/


/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Shell_Task_Init(void);
void Snf_Shell_Task(void);
void Snf_Shell_Print(const char* fmt, ...);

#ifdef __cplusplus
}
#endif

#endif /* _SHELL_H_ */