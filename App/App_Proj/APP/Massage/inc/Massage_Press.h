#ifndef _MASSAGE_PRESSING_H_
#define _MASSAGE_PRESSING_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Massage.h"
/************************ Macro Definitions ************************/
#define PRESS_MASSAGE_AIR_SINGLE_9_10_INTENSITY_LOW_INFLATE_TIME  2500  // 普通气袋点按模式，单气袋，低强度，充气时间,mS
#define PRESS_MASSAGE_AIR_SINGLE_9_10_INTENSITY_LOW_DEFLATE_TIME  1000  // 普通气袋点按模式，单气袋，低强度，泄气时间,mS
#define PRESS_MASSAGE_AIR_SINGLE_9_10_INTENSITY_HIGH_INFLATE_TIME 3500  // 普通气袋点按模式，单气袋，高强度，充气时间,mS
#define PRESS_MASSAGE_AIR_SINGLE_9_10_INTENSITY_HIGH_DEFLATE_TIME 1000  // 普通气袋点按模式，单气袋，高强度，泄气时间,mS

#define PRESS_MASSAGE_AIR_DOUBLE_9_10_INTENSITY_LOW_INFLATE_TIME  3500  // 普通气袋点按模式，双气袋，低强度，充气时间,mS
#define PRESS_MASSAGE_AIR_DOUBLE_9_10_INTENSITY_LOW_DEFLATE_TIME  1000  // 普通气袋点按模式，双气袋，低强度，泄气时间,mS
#define PRESS_MASSAGE_AIR_DOUBLE_9_10_INTENSITY_HIGH_INFLATE_TIME 6000  // 普通气袋点按模式，双气袋，高强度，充气时间,mS
#define PRESS_MASSAGE_AIR_DOUBLE_9_10_INTENSITY_HIGH_DEFLATE_TIME 1000  // 普通氣袋点按模式，双氣袋，高强度，泄氣时间,mS

#define PRESS_MASSAGE_AIR_SINGLE_5_6_7_8_INTENSITY_LOW_INFLATE_TIME 3000  // 揉捏氣袋点按模式，单氣袋，低强度，充氣时间,mS
#define PRESS_MASSAGE_AIR_SINGLE_5_6_7_8_INTENSITY_LOW_OVERLAP_TIME 700   // 揉捏气袋点按模式，单气袋，低强度，重叠时间,mS
#define PRESS_MASSAGE_AIR_SINGLE_5_6_7_8_INTENSITY_LOW_ALL_DEFLATE_TIME \
    500  // 揉捏气袋点按模式，单气袋，低强度，所有气袋泄气时间,mS

#define PRESS_MASSAGE_AIR_SINGLE_5_6_7_8_INTENSITY_HIGH_INFLATE_TIME 4000  // 揉捏气袋点按模式，单气袋，高强度，充气时间,mS
#define PRESS_MASSAGE_AIR_SINGLE_5_6_7_8_INTENSITY_HIGH_OVERLAP_TIME 900   // 揉捏气袋点按模式，单气袋，高强度，重叠时间,mS
#define PRESS_MASSAGE_AIR_SINGLE_5_6_7_8_INTENSITY_HIGH_ALL_DEFLATE_TIME \
    700  // 揉捏气袋点按模式，单气袋，高强度，所有气袋泄气时间,mS

#define PRESS_MASSAGE_AIR_DOUBLE_5_6_7_8_INTENSITY_LOW_INFLATE_TIME 4500  // 揉捏气袋点按模式，双气袋，低强度，充气时间,mS
#define PRESS_MASSAGE_AIR_DOUBLE_5_6_7_8_INTENSITY_LOW_OVERLAP_TIME 700   // 揉捏气袋点按模式，双气袋，低强度，重叠时间,mS
#define PRESS_MASSAGE_AIR_DOUBLE_5_6_7_8_INTENSITY_LOW_ALL_DEFLATE_TIME \
    500  // 揉捏气袋点按模式，双气袋，低强度，所有气袋泄气时间,mS

#define PRESS_MASSAGE_AIR_DOUBLE_5_6_7_8_INTENSITY_HIGH_INFLATE_TIME 5500  // 揉捏气袋点按模式，双气袋，高强度，充气时间,mS
#define PRESS_MASSAGE_AIR_DOUBLE_5_6_7_8_INTENSITY_HIGH_OVERLAP_TIME 1400  // 揉捏气袋点按模式，双气袋，高强度，重叠时间,mS
#define PRESS_MASSAGE_AIR_DOUBLE_5_6_7_8_INTENSITY_HIGH_ALL_DEFLATE_TIME \
    700  // 揉捏气袋点按模式，双气袋，高强度，所有气袋泄气时间,mS

#define PRESS_3_POINT_MASSAGE_AIR_SINGLE_5_6_INTENSITY_LOW_INFLATE_TIME  3000  // 无支撑3点按模式，单气袋，低强度，充气时间,mS
#define PRESS_3_POINT_MASSAGE_AIR_SINGLE_5_6_INTENSITY_LOW_DEFLATE_TIME  2000  // 无支撑3点按模式，单气袋，低强度，泄气时间,mS
#define PRESS_3_POINT_MASSAGE_AIR_SINGLE_5_6_INTENSITY_HIGH_INFLATE_TIME 3500  // 无支撑3点按模式，单气袋，高强度，充气时间,mS
#define PRESS_3_POINT_MASSAGE_AIR_SINGLE_5_6_INTENSITY_HIGH_DEFLATE_TIME 2000  // 无支撑3点按模式，单气袋，高强度，泄气时间,mS

#define PRESS_3_POINT_MASSAGE_AIR_DOUBLE_5_6_INTENSITY_LOW_INFLATE_TIME  4800  // 无支撑3点按模式，双气袋，低强度，充气时间,mS
#define PRESS_3_POINT_MASSAGE_AIR_DOUBLE_5_6_INTENSITY_LOW_DEFLATE_TIME  2000  // 无支撑3点按模式，双气袋，低强度，泄气时间,mS
#define PRESS_3_POINT_MASSAGE_AIR_DOUBLE_5_6_INTENSITY_HIGH_INFLATE_TIME 6000  // 无支撑3点按模式，双气袋，高强度，充气时间,mS
#define PRESS_3_POINT_MASSAGE_AIR_DOUBLE_5_6_INTENSITY_HIGH_DEFLATE_TIME 2000  // 无支撑3点按模式，双气袋，高强度，泄气时间,mS

#define PRESS_SUPPORT_3_POINT_MASSAGE_AIR_SINGLE_7_8_INTENSITY_LOW_INFLATE_TIME \
    800  // 支撑3点按模式，单气袋，低强度，充气时间,mS
#define PRESS_SUPPORT_3_POINT_MASSAGE_AIR_SINGLE_7_8_INTENSITY_LOW_OVERLAP_TIME \
    1000                                                                      // 支撑3点按模式，单气袋，低强度，重叠时间,mS
#define PRESS_3_POINT_MASSAGE_AIR_SINGLE_7_8_INTENSITY_LOW_INFLATE_TIME 2500  // 支撑3点按模式，单气袋，低强度，充气时间,mS
#define PRESS_3_POINT_MASSAGE_AIR_SINGLE_7_8_INTENSITY_LOW_DEFLATE_TIME 2000  // 支撑3点按模式，单气袋，低强度，泄气时间,mS

#define PRESS_SUPPORT_3_POINT_MASSAGE_AIR_SINGLE_7_8_INTENSITY_HIGH_INFLATE_TIME \
    1500  // 支撑3点按模式，单气袋，低强度，充气时间,mS
#define PRESS_SUPPORT_3_POINT_MASSAGE_AIR_SINGLE_7_8_INTENSITY_HIGH_OVERLAP_TIME \
    1000                                                                       // 支撑3点按模式，单气袋，低强度，重叠时间,mS
#define PRESS_3_POINT_MASSAGE_AIR_SINGLE_7_8_INTENSITY_HIGH_INFLATE_TIME 3000  // 支撑3点按模式，单气袋，低强度，充气时间,mS
#define PRESS_3_POINT_MASSAGE_AIR_SINGLE_7_8_INTENSITY_HIGH_DEFLATE_TIME 2000  // 支撑3点按模式，单气袋，低强度，泄气时间,mS

#define PRESS_SUPPORT_3_POINT_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_LOW_INFLATE_TIME \
    1500  // 支撑3点按模式，双气袋，低强度，充气时间,mS
#define PRESS_SUPPORT_3_POINT_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_LOW_OVERLAP_TIME \
    1000                                                                      // 支撑3点按模式，双气袋，低强度，重叠时间,mS
#define PRESS_3_POINT_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_LOW_INFLATE_TIME 3500  // 支撑3点按模式，双气袋，低强度，充气时间,mS
#define PRESS_3_POINT_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_LOW_DEFLATE_TIME 2000  // 支撑3点按模式，双气袋，低强度，泄气时间,mS

#define PRESS_SUPPORT_3_POINT_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_HIGH_INFLATE_TIME \
    2200  // 支撑3点按模式，双气袋，低强度，充气时间,mS
#define PRESS_SUPPORT_3_POINT_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_HIGH_OVERLAP_TIME \
    1000                                                                       // 支撑3点按模式，双气袋，低强度，重叠时间,mS
#define PRESS_3_POINT_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_HIGH_INFLATE_TIME 4500  // 支撑3点按模式，双气袋，低强度，充气时间,mS
#define PRESS_3_POINT_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_HIGH_DEFLATE_TIME 2000  // 支撑3点按模式，双气袋，低强度，泄气时间,mS

/************************ Function Declarations ************************/

/************************ Type Definitions ************************/
/**
 * @brief 三点按压时间参数（单位ms，使用时经MASSAGE_TIME_MS转换为tick）
 */
typedef struct
{
    uint16 support_inflate_time;  // 支撑气袋预充气时间，ms（无支撑气袋时为0）
    uint16 massage_inflate_time;  // 主按摩气袋充气时间，ms
    uint16 overlap_time;          // 支撑气袋与主按摩气袋重叠时间，ms（无支撑气袋时为0）
    uint16 deflate_time;          // 全部气袋泄气时间，ms
} press_3_point_time_t;

/**
 * @brief 单点按压时间参数（单位ms，使用时经MASSAGE_TIME_MS转换为tick）
 */
typedef struct
{
    uint16 inflate_time;      // 单个气袋点按充气时间，ms
    uint16 overlap_time;      // 相邻气袋点按重叠时间，ms
    uint16 all_deflate_time;  // 所有气袋泄气时间，ms
} press_1_point_time_t;

/**
 * @brief 肩部气囊点按时间参数（单位ms，使用时经MASSAGE_TIME_MS转换为tick）
 */
typedef struct
{
    uint16 inflate_time;  // 充气时间，ms
    uint16 deflate_time;  // 泄气时间，ms
} press_shoulder_time_t;

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Massage_Press_Init(massage_press_config_t* massage_press_config_l);
void Snf_Massage_3_Point_Press_Handle(massage_config_t* massage_config);
void Snf_Massage_Shoulder_Bag_Point_Press(massage_config_t* massage_config);
void Snf_Massage_1_Point_Press_Handle(massage_config_t* massage_config);

#ifdef __cplusplus
}
#endif

#endif /* _MASSAGE_PRESSING_H_ */