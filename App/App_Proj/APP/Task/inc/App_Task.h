#ifndef _APP_TASK_H_
#define _APP_TASK_H_

#ifdef __cplusplus
extern "C" {
#endif

/************************ Include Files ************************/
#include <stdbool.h>
#include <stdint.h>

/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
typedef void (*app_init_func_f)(void);
typedef void (*app_scheduler_func_f)(void);

typedef struct {
    app_init_func_f init_func;        /* 初始化函数 */
    app_scheduler_func_f schedu_func; /* 调度函数 */
    uint32_t period;                  /* 调度周期，单位为ms */
    bool enable;                      /* 是否启用 */
    bool reuse;                       /* 是否周期调度 */
    uint32_t count;                   /* 计数值 */
} scheduler_t;

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_App_Task_Init(void);
void Snf_App_Task_Scheduler_Handle(void);

#ifdef __cplusplus
}
#endif

#endif /* _APP_TASK_H_ */