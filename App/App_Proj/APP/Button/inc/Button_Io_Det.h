#ifndef _BUTTON_IO_DET_H_
#define _BUTTON_IO_DET_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
#include "App_Task_Cfg.h"
/************************ Macro Definitions ************************/
#define BUTTON_IO_DET_POLLING_TIME_MS BUTTON_TASK_PERIOD_MS
#define BUTTON_IO_VAILD_LEVEL         RTE_GPIO_LEVEL_LOW
/************************ Type Definitions ************************/
typedef enum
{
    BUTTON_IO_STATE_RELEASE,     // 释放
    BUTTON_IO_STATE_PRESS,       // 按下
    BUTTON_IO_STATE_LONG_PRESS,  // 长按
    BUTTON_IO_STATE_STUCK        // 粘连
} button_io_state_e;

typedef struct
{
    button_io_state_e button_state_old;
    button_io_state_e button_state_new;
    uint32_t          button_vaild_cnt;
    uint32_t          button_invaild_cnt;
} button_io_config_t;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Button_Io_Det_Init(void);
void Button_Io_Det_Polling(void);

#ifdef __cplusplus
}
#endif

#endif /* _BUTTON_IO_DET_H_ */
