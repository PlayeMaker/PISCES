#ifndef _LUMBAR_H_
#define _LUMBAR_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
/************************ Macro Definitions ************************/
#define LUMBAR_INFLATION_DUTY_CYCLE 50U
#define LUMBAR_DEFLATION_DUTY_CYCLE 0U
    /************************ Type Definitions ************************/
typedef void (*lumbar_action_func_callback)(uint16_t duty_cycle);

typedef enum
{
    LUMBAR_MODE_MODE_KEEP,  // 保持
    LUMBAR_MODE_INFLATION,  // 充气
    LUMBAR_MODE_DEFLATION,  // 放气
} lumbar_mode_e;

typedef enum
{
    LUMBAR_POSITION_TOP,  // 腰托上气袋
    // LUMBAR_POSITION_MID, // 腰托中气袋
    LUMBAR_POSITION_BOTTOM,  //腰托下气袋
} lumbar_position_e;

typedef struct
{
    lumbar_position_e           position;              // 气袋位置
    uint16_t                    inflation_duty_cycle;  // 充气占空比
    uint16_t                    deflation_duty_cycle;  // 放气占空比
    lumbar_action_func_callback action_func;           // 气袋充放气函数
} lumbar_config_t;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Lumbar_Task(void);

#ifdef __cplusplus
}
#endif

#endif /* _LUMBAR_H_ */