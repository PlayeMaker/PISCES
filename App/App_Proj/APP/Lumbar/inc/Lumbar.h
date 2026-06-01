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
typedef void (*lumbar_funt_callback_f)(uint8_t position);

// 腰托模式枚举，与网络命令中的定义保持一致
typedef enum
{
    LUMBAR_MODE_NO_ACTION,  // 无动作
    LUMBAR_MODE_INFLATION,  // 充气
    LUMBAR_MODE_DEFLATION,  // 泄气
    LUMBAR_MODE_RESERVED,
} lumbar_mode_e;

typedef enum
{
    LUMBAR_POSITION_TOP,     // 腰托上气袋
    LUMBAR_POSITION_BOTTOM,  // 腰托下气袋
} lumbar_position_e;

typedef struct
{
    lumbar_position_e      position;                // 腰托位置
    lumbar_mode_e          mode;                    // 腰托模式
    uint8_t                pwm_channel_fornt;       // 腰托对应的前PWM通道
    uint8_t                pwm_channel_rear;        // 腰托对应的后PWM通道
    lumbar_funt_callback_f read_net_cmd_callback;   // 读取网络命令回调函数
    lumbar_funt_callback_f write_net_cmd_callback;  // 写入网络命令回调函数
} lumbar_config_t;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Lumbar_Task(void);

#ifdef __cplusplus
}
#endif

#endif /* _LUMBAR_H_ */