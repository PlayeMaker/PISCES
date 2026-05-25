#ifndef _MASSAGE_H_
#define _MASSAGE_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
/************************ Macro Definitions ************************/
#define MASSAGE_AIR_BAG_PWM_NUM_MAX             2  //一个气袋需要PWM通道最大数量
#define MASSAGE_AIR_BAG_PWM_NUM_MAX             2  //一个气袋需要PWM通道最大数量
#define MASSAGE_AIR_BAG_GROUP_NUM_MAX           4  //一组气袋最大数量
#define MASSAGE_AIR_BAG_SUPPORT_FRONT_VAVLE_IDX 0  //支撑气袋前阀索引
#define MASSAGE_AIR_BAG_SUPPORT_REAR_VAVLE_IDX  1  //支撑气袋后阀索引
/************************ Function Declarations ************************/

/************************ Type Definitions ************************/
/**
* @brief 按摩模式枚举
*/
typedef enum
{
    MASSAGE_MODE_NONE,             //无按摩模式
    MASSAGE_MODE_KNEADING,         //揉捏模式
    MASSAGE_MODE_SINGLE_PRESSING,  //单点按摩模式
    MASSAGE_MODE_MULTI_PRESSING,   //多点按摩模式
    MASSAGE_MODE_TAPPING,          //叩击模式
} massage_mode_e;

/**
* @brief 按摩强度枚举
*/
typedef enum
{
    MASSAGE_INTENSITY_LOW,   //低强度
    MASSAGE_INTENSITY_HIGH,  //高强度
} massage_intensity_e;

/**
* @brief 按摩方向枚举
*/
typedef enum
{
    MASSAGE_DIRECTION_CW,   //顺时针
    MASSAGE_DIRECTION_CCW,  //逆时针
} massage_direction_e;

/**
* @brief 按摩气袋区域枚举
*/
typedef enum
{
    MASSAGE_ZONE_LEFT_SHOULDER,  //左肩部
    MASSAGE_ZONE_RIGHT_SHOULDER, //右肩部
    MASSAGE_ZONE_LEFT_BACK,      //左背部
    MASSAGE_ZONE_RIGHT_BACK,     //右背部
    MASSAGE_ZONE_LEFT_WAIST,     //左腰部
    MASSAGE_ZONE_RIGHT_WAIST,    //右腰部
} massage_zone_e;

/**
* @brief 按摩步骤枚举
*/
typedef enum
{
    MASSAGE_ACTION_STEP_NONE,        //无动作
    MASSAGE_ACTION_STEP_PRE_CHARGE,  //预充气
    MASSAGE_ACTION_STEP_CYCLE,       //循环
    MASSAGE_ACTION_STEP_END,         //结束
} massage_action_step_e;

/**
* @brief 按摩气袋类型枚举
*/
typedef enum
{
    MASSAGE_AIR_BAG_TYPE_STANDARD,  //普通气袋
    MASSAGE_AIR_BAG_TYPE_SUPPORT,   //支撑气袋
} massage_air_bag_type_e;

/**
* @brief 按摩气袋动作枚举
*/
typedef enum
{
    MASSAGE_AIR_BAG_NONE,       //无动作
    MASSAGE_AIR_BAG_INFLATION,  //充气
    MASSAGE_AIR_BAG_KEEP,       //保持
    MASSAGE_AIR_BAG_DEFLATION,  //泄气
} massage_air_bag_mode_e;

/**
* @brief 按摩气袋配置结构体
*/
typedef struct
{
    massage_air_bag_type_e air_bag_type;                                      //气袋类型
    massage_air_bag_mode_e air_bag_mode;                                      //气袋动作
    uint16_t               air_bag_inflation_time;                            //充气时间，单位毫秒
    uint16_t               air_bag_deflation_time;                            //泄气时间，单位毫秒
    uint32_t               air_bag_last_uptime;                               //上次动作的时间，单位毫秒
    uint8_t                air_bag_pwm_channel_num;                           //该气袋使用的PWM通道数量
    uint8_t                air_bag_pwm_channel[MASSAGE_AIR_BAG_PWM_NUM_MAX];  //该气袋使用的PWM通道列表
} massage_air_bag_config_t;

/**
* @brief 按摩动作配置结构体
*/
typedef struct
{
    massage_action_step_e    action_step;        //按摩动作步骤
    massage_intensity_e      intensity;          //按摩强度
    massage_direction_e      direction;          //按摩方向，顺时针或逆时针，针对揉捏和循环动作有效
    uint16_t                 air_bag_cycle_cnt;  //循环次数
    uint16_t                 air_bag_num;        //参与按摩的气袋数量
    massage_air_bag_config_t air_bag_config_list[MASSAGE_AIR_BAG_GROUP_NUM_MAX];  //气袋配置列表
} massage_action_config_t;

/**
* @brief 按摩配置结构体
*/
typedef struct
{
    massage_zone_e          zone;             //按摩区域
    massage_mode_e          mode;             //按摩模式
    uint32_t                action_sum_time;  //按摩动作总时间，单位毫秒
    massage_action_config_t action_cfg;       //按摩动作配置
} massage_config_t;

/**
* @brief 按摩配置组
*/
typedef struct
{
    massage_config_t* config;
} massage_group_t;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Massage_Task_Init(void);
void Snf_Massage_Task(void);

#ifdef __cplusplus
}
#endif

#endif /* _MASSAGE_H_ */