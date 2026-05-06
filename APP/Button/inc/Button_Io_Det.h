#ifndef _BUTTON_IO_DET_H_
#define _BUTTON_IO_DET_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
typedef enum
{
    BUTTON_IO_STATE_RELEASE,     // 释放
    BUTTON_IO_STATE_PRESS,       // 按下
    BUTTON_IO_STATE_LONG_PRESS,  // 长按
} button_io_state_e;

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Button_Io_Det_Polling(void);

#ifdef __cplusplus
}
#endif

#endif /* _BUTTON_IO_DET_H_ */
