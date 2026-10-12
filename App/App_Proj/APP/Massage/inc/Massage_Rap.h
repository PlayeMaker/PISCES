#ifndef _MASSAGE_RAP_H_
#define _MASSAGE_RAP_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Massage.h"
/************************ Macro Definitions ************************/
#define RAP_MASSAGE_AIG_SINGLE_9_10_INTENSITY_LOW_INFLATE_TIME        3000  // 叩击模式，单气袋，低强度，气袋预充气时间,mS
#define RAP_MASSAGE_AIG_SINGLE_9_10_INTENSITY_LOW_ACTION_INFLATE_TIME 260   // 叩击模式，单气袋，低强度，气袋动作充气时间,mS
#define RAP_MASSAGE_AIG_SINGLE_9_10_INTENSITY_LOW_ACTION_DEFLATE_TIME 160   // 叩击模式，单气袋，低强度，气袋动作泄气时间,mS

#define RAP_MASSAGE_AIG_SINGLE_9_10_INTENSITY_HIGH_INFLATE_TIME        3500  // 叩击模式，单气袋，高强度，气袋预充气时间,mS
#define RAP_MASSAGE_AIG_SINGLE_9_10_INTENSITY_HIGH_ACTION_INFLATE_TIME 300   // 叩击模式，单气袋，高強度，气袋动作充气时间,mS
#define RAP_MASSAGE_AIG_SINGLE_9_10_INTENSITY_HIGH_ACTION_DEFLATE_TIME 140   // 叩击模式，单气袋，高強度，气袋动作泄气时间,mS

#define RAP_MASSAGE_AIG_DOUBLE_9_10_INTENSITY_LOW_INFLATE_TIME        5000  // 叩击模式，双气袋，低强度，气袋预充气时间,mS
#define RAP_MASSAGE_AIG_DOUBLE_9_10_INTENSITY_LOW_ACTION_INFLATE_TIME 280   // 叩击模式，双气袋，低强度，气袋动作充气时间,mS
#define RAP_MASSAGE_AIG_DOUBLE_9_10_INTENSITY_LOW_ACTION_DEFLATE_TIME 180   // 叩击模式，双气袋，低强度，气袋动作泄气时间,mS

#define RAP_MASSAGE_AIG_DOUBLE_9_10_INTENSITY_HIGH_INFLATE_TIME        6000  // 叩击模式，双气袋，高强度，气袋预充气时间,mS
#define RAP_MASSAGE_AIG_DOUBLE_9_10_INTENSITY_HIGH_ACTION_INFLATE_TIME 300   // 叩击模式，双气袋，高強度，气袋动作充气时间,mS
#define RAP_MASSAGE_AIG_DOUBLE_9_10_INTENSITY_HIGH_ACTION_DEFLATE_TIME 140   // 叩击模式，双气袋，高強度，气袋动作泄气时间,mS

#define RAP_SUPPORT_AIR_SINGLE_7_8_INTENSITY_LOW_INFLATE_TIME        1800  // 叩击模式，单气袋，低强度，支撑气袋预充气时间,mS
#define RAP_MASSAGE_AIR_SINGLE_7_8_INTENSITY_LOW_INFLATE_TIME        2000  // 叩击模式，单气袋，低强度，按摩气袋预充气时间,mS
#define RAP_MASSAGE_AIG_SINGLE_7_8_INTENSITY_LOW_ACTION_INFLATE_TIME 300   // 叩击模式，单气袋，低強度，气袋动作充气时间,mS
#define RAP_MASSAGE_AIG_SINGLE_7_8_INTENSITY_LOW_ACTION_DEFLATE_TIME 180   // 叩击模式，单气袋，低強度，气袋动作泄气时间,mS

#define RAP_SUPPORT_AIR_SINGLE_7_8_INTENSITY_HIGH_INFLATE_TIME        2500  // 叩击模式，单气袋，高强度，支撑气袋预充气时间,mS
#define RAP_MASSAGE_AIR_SINGLE_7_8_INTENSITY_HIGH_INFLATE_TIME        2500  // 叩击模式，单气袋，高强度，按摩气袋预充气时间,mS
#define RAP_MASSAGE_AIG_SINGLE_7_8_INTENSITY_HIGH_ACTION_INFLATE_TIME 200   // 叩击模式，单气袋，高強度，气袋动作充气时间,mS
#define RAP_MASSAGE_AIG_SINGLE_7_8_INTENSITY_HIGH_ACTION_DEFLATE_TIME 140   // 叩击模式，单气袋，高強度，气袋动作泄气时间,mS

#define RAP_SUPPORT_AIR_DOUBLE_7_8_INTENSITY_LOW_INFLATE_TIME        2500  // 叩击模式，双气袋，低强度，支撑气袋预充气时间,mS
#define RAP_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_LOW_INFLATE_TIME        3000  // 叩击模式，双气袋，低强度，按摩气袋预充气时间,mS
#define RAP_MASSAGE_AIG_DOUBLE_7_8_INTENSITY_LOW_ACTION_INFLATE_TIME 300   // 叩击模式，双气袋，低強度，气袋动作充气时间,mS
#define RAP_MASSAGE_AIG_DOUBLE_7_8_INTENSITY_LOW_ACTION_DEFLATE_TIME 180   // 叩击模式，双气袋，低強度，气袋动作泄气时间,mS

#define RAP_SUPPORT_AIR_DOUBLE_7_8_INTENSITY_HIGH_INFLATE_TIME        3200  // 叩击模式，双气袋，高强度，支撑气袋预充气时间,mS
#define RAP_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_HIGH_INFLATE_TIME        4000  // 叩击模式，双气袋，高强度，按摩气袋预充气时间,mS
#define RAP_MASSAGE_AIG_DOUBLE_7_8_INTENSITY_HIGH_ACTION_INFLATE_TIME 200   // 叩击模式，双气袋，高強度，气袋动作充气时间,mS
#define RAP_MASSAGE_AIG_DOUBLE_7_8_INTENSITY_HIGH_ACTION_DEFLATE_TIME 140   // 叩击模式，双气袋，高強度，气袋動作泄气時間,mS

#define RAP_KEEP_SUPPORT_AIR_7_8_DEFLATE_TIME \
    4000  // 叩击模式，单/双气袋，低/高强度，支撑气袋泄气时间,mS (硬件AA版本的支撑气袋断电不泄气)
#define RAP_DEFLATE_SUPPORT_AIR_7_8_DEFLATE_TIME \
    0  // 叩击模式，单/双气袋，低/高强度，支撑气袋泄气时间,mS (硬件AB版本的支撑气袋断电泄气)

#define RAP_MASSAGE_AIR_SINGLE_5_6_INTENSITY_LOW_INFLATE_TIME        2500  // 叩击模式，单气袋，低强度，按摩气袋预充气时间,mS
#define RAP_MASSAGE_AIG_SINGLE_5_6_INTENSITY_LOW_ACTION_INFLATE_TIME 280   // 叩击模式，单气袋，低強度，气袋动作充气时间,mS
#define RAP_MASSAGE_AIG_SINGLE_5_6_INTENSITY_LOW_ACTION_DEFLATE_TIME 180   // 叩击模式，单气袋，低強度，气袋动作泄气时间,mS

#define RAP_MASSAGE_AIR_SINGLE_5_6_INTENSITY_HIGH_INFLATE_TIME        3000  // 叩击模式，单气袋，高强度，按摩气袋预充气时间,mS
#define RAP_MASSAGE_AIG_SINGLE_5_6_INTENSITY_HIGH_ACTION_INFLATE_TIME 200   // 叩击模式，单气袋，高強度，气袋动作充气时间,mS
#define RAP_MASSAGE_AIG_SINGLE_5_6_INTENSITY_HIGH_ACTION_DEFLATE_TIME 140   // 叩击模式，单气袋，高強度，气袋动作泄气时间,mS

#define RAP_MASSAGE_AIR_DOUBLE_5_6_INTENSITY_LOW_INFLATE_TIME        3500  // 叩击模式，双气袋，低强度，按摩气袋预充气时间,mS
#define RAP_MASSAGE_AIG_DOUBLE_5_6_INTENSITY_LOW_ACTION_INFLATE_TIME 280   // 叩击模式，双气袋，低強度，气袋动作充气时间,mS
#define RAP_MASSAGE_AIG_DOUBLE_5_6_INTENSITY_LOW_ACTION_DEFLATE_TIME 180   // 叩击模式，双气袋，低強度，气袋动作泄气时间,mS

#define RAP_MASSAGE_AIR_DOUBLE_5_6_INTENSITY_HIGH_INFLATE_TIME        4500  // 叩击模式，双气袋，高强度，按摩气袋预充气时间,mS
#define RAP_MASSAGE_AIG_DOUBLE_5_6_INTENSITY_HIGH_ACTION_INFLATE_TIME 180   // 叩击模式，双气袋，高強度，气袋动作充气时间,mS
#define RAP_MASSAGE_AIG_DOUBLE_5_6_INTENSITY_HIGH_ACTION_DEFLATE_TIME 140   // 叩击模式，双气袋，高強度，气袋動作泄气時間,mS
/************************ Function Declarations ************************/

/************************ Type Definitions ************************/
/**
* @brief 揉捏气袋叩击时间参数表项（时间单位ms）
*/
typedef struct
{
    uint16 support_inflate_time;  // 支撑气袋预充气时间（无支撑时为0）
    uint16 massage_inflate_time;  // 按摩气袋预充气时间
    uint16 action_inflate_time;   // 气袋动作充气时间
    uint16 action_deflate_time;   // 气袋动作泄气时间
} rap_knead_time_param_t;

/**
* @brief 肩部叩击时间参数表项（时间单位ms）
*/
typedef struct
{
    uint16 pre_inflate_time;     // 气袋预充气时间
    uint16 action_inflate_time;  // 气袋动作充气时间
    uint16 action_deflate_time;  // 气袋动作泄气时间
} rap_shoulder_time_param_t;

/************************ External Variables ************************/

/************************ Function Declarations ************************/
const rap_knead_time_param_t* Snf_Massage_Rap_Get_Knead_Param(bool support_flag, bool double_flag, uint8 lvl);
void                          Snf_Massage_Rap_Init(massage_rap_config_t* massage_rap_config_l);
void                          Snf_Massage_Rap_Knead(massage_config_t* massage_config);
void                          Snf_Massage_Shoulder_Rap(massage_config_t* massage_config);

#ifdef __cplusplus
}
#endif

#endif /* _MASSAGE_RAP_H_ */