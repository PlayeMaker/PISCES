#ifndef _MASSAGE_KNEAD_H_
#define _MASSAGE_KNEAD_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Massage.h"
#include "Massage_Cfg.h"
/************************ Macro Definitions ************************/
#define KNEAD_SUPPORT_AIR_SINGLE_7_8_INTENSITY_LOW_INFLATE_TIME  1800  // 揉捏模式，单气袋，低强度，支撑气袋预充气时间,mS
#define KNEAD_MASSAGE_AIR_SINGLE_7_8_INTENSITY_LOW_INFLATE_TIME  3000  // 揉捏模式，单气袋，低强度，按摩气袋预充气时间,mS
#define KNEAD_SUPPORT_AIR_SINGLE_7_8_INTENSITY_HIGH_INFLATE_TIME 2500  // 揉捏模式，单气袋，高强度，支撑气袋预充气时间,mS
#define KNEAD_MASSAGE_AIR_SINGLE_7_8_INTENSITY_HIGH_INFLATE_TIME 4000  // 揉捏模式，单气袋，高强度，按摩气袋预充气时间,mS
#define KNEAD_SUPPORT_AIR_DOUBLE_7_8_INTENSITY_LOW_INFLATE_TIME  2500  // 揉捏模式，双气袋，低强度，支撑气袋预充气时间,mS
#define KNEAD_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_LOW_INFLATE_TIME  4500  // 揉捏模式，双气袋，低强度，按摩气袋预充气时间,mS
#define KNEAD_SUPPORT_AIR_DOUBLE_7_8_INTENSITY_HIGH_INFLATE_TIME 3200  // 揉捏模式，双气袋，高强度，支撑气袋预充气时间,mS
#define KNEAD_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_HIGH_INFLATE_TIME 5500  // 揉捏模式，双气袋，高强度，按摩气袋预充气时间,mS
#define KNEAD_KEEP_SUPPORT_AIR_7_8_DEFLATE_TIME \
    4000  // 揉捏模式，单/双气袋，低/高强度，支撑气袋泄气时间,mS (硬件AA版本的支撑气袋断电不泄气)
#define KNEAD_DEFLATE_SUPPORT_AIR_7_8_DEFLATE_TIME \
    0  // 揉捏模式，单/双气袋，低/高强度，支撑气袋泄气时间,mS (硬件AB版本的支撑气袋断电泄气)

#define KNEAD_MASSAGE_AIR_SINGLE_5_6_INTENSITY_LOW_INFLATE_TIME  3500  // 揉捏模式，单气袋，低强度，按摩气袋预充气时间,mS
#define KNEAD_MASSAGE_AIR_SINGLE_5_6_INTENSITY_HIGH_INFLATE_TIME 4500  // 揉捏模式，单气袋，高强度，按摩气袋预充气时间,mS
#define KNEAD_MASSAGE_AIR_DOUBLE_5_6_INTENSITY_LOW_INFLATE_TIME  5000  // 揉捏模式，双气袋，低强度，按摩气袋预充气时间,mS
#define KNEAD_MASSAGE_AIR_DOUBLE_5_6_INTENSITY_HIGH_INFLATE_TIME 6000  // 揉捏模式，双气袋，高强度，按摩气袋预充气时间,mS

#define KNEAD_MASSAGE_AIR_SINGLE_5_6_7_8_INTENSITY_LOW_IACTION_CYCLE_TIME \
    800  // 揉捏模式，单气袋，低强度，按摩气袋动作周期时间,mS
#define KNEAD_MASSAGE_AIR_SINGLE_5_6_7_8_INTENSITY_HIGH_IACTION_CYCLE_TIME \
    600  // 揉捏模式，单气袋，高强度，按摩气袋动作周期时间,mS
#define KNEAD_MASSAGE_AIR_DOUBLE_5_6_7_8_INTENSITY_LOW_IACTION_CYCLE_TIME \
    900  // 揉捏模式，单气袋，低强度，按摩气袋动作周期时间,mS
#define KNEAD_MASSAGE_AIR_DOUBLE_5_6_7_8_INTENSITY_HIGH_IACTION_CYCLE_TIME \
    700  // 揉捏模式，单气袋，高强度，按摩气袋动作周期时间,mS

/************************ Function Declarations ************************/

/************************ Type Definitions ************************/
/**
 * @brief 揉捏按摩气袋索引，与气袋通道数组下标一一对应
 */
typedef enum
{
    KNEAD_BAG_TOP,
    KNEAD_BAG_RIGHT,
    KNEAD_BAG_LEFT,
    KNEAD_BAG_MAX,
} knead_air_bag_e;

/**
 * @brief 揉捏模式充气时间参数（单位ms，使用时经MASSAGE_TIME_MS转换为tick）
 */
typedef struct
{
    uint16 support_inflate_time;  // 支撑气袋预充气时间，ms（无支撑气袋时为0）
    uint16 massage_inflate_time;  // 按摩气袋预充气时间，ms
} knead_inflate_time_t;

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Massage_Knead_Init(massage_knead_config_t* massage_knead_config_l);
void Snf_Massage_Knead_Handle(massage_config_t* massage_config);

#ifdef __cplusplus
}
#endif

#endif /* _MASSAGE_KNEAD_H_ */