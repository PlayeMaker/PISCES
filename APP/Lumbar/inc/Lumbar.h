#ifndef _LUMBAR_H_
#define _LUMBAR_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
typedef enum
{
    LUMBAR_MODE_IDLE,       // 空闲
    LUMBAR_MODE_KEEP,       // 保持
    LUMBAR_MODE_INFLATION,  // 充气
    LUMBAR_MODE_DEFLATION,  // 放气
} lumbar_mode_e;

typedef enum
{
    LUMBAR_POSITION_TOP,     // 腰托上气袋
    LUMBAR_POSITION_MID,     // 腰托中气袋
    LUMBAR_POSITION_BOTTOM,  // 腰托下气袋
} lumbar_position_e;

typedef struct
{
    lumbar_position_e position;       // 气袋位置
    lumbar_mode_e     mode;           // 气袋模式
    uint8_t           pwm_channel_1;  // 气袋对应的PWM通道
    uint8_t           pwm_channel_2;  // 气袋对应的PWM通道
} lumbar_config_t;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Lumbar_Task(void);

#ifdef __cplusplus
}
#endif

#endif /* _LUMBAR_H_ */