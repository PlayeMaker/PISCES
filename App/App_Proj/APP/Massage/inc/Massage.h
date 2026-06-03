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
#define MASSAGE_AIR_BAG_TIME_MS(tmp)     (tmp / 5)  //单位为ms,task周期为5ms
#define NO_ACTION       0
#define ACTION          1
#define COMPLETE_ACTION 0xFF
/************************ Function Declarations ************************/

/************************ Type Definitions ************************/
/**
* @brief 按摩模式枚举
*/
typedef enum
{
    MASSAGE_MODE_IDLE,                       //无按摩模式
    MASSAGE_MODE_KNEADING_CLOCKWISE,
    MASSAGE_MODE_KNEADING_ANTICLOCKWISE,
    MASSAGE_MODE_POINT_PRESSING,
    MASSAGE_MODE_SUPPORT_POINT_PRESSING,
    MASSAGE_MODE_RAP_CLOCKWISE,
    MASSAGE_MODE_RAP_ANTICLOCKWISE,
    MASSAGE_MODE_POINT_MASSAGE,
} massage_mode_e;

/**
* @brief 按摩区域枚举
*/
typedef enum
{
    AREA_5,
    AREA_6,
    AREA_7,
    AREA_8,
    AREA_9,
    AREA_10,
    AREA_MAX,
}massage_area_e;

/**
* @brief 按摩强度枚举
*/
typedef enum
{
    MASSAGE_INTENSITY_IDLE,
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

typedef enum
{
    CLOCKWISE,
    ANTICLOCKWISE,
}massage_clockwise_e;

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
// typedef struct
// {
//     massage_zone_e          zone;             //按摩区域
//     massage_mode_e          mode;             //按摩模式
//     uint32_t                action_sum_time;  //按摩动作总时间，单位毫秒
//     massage_action_config_t action_cfg;       //按摩动作配置
// } massage_config_t;

//揉捏气袋的叩击状态
typedef enum
{
    RAP_INFLATE_STATUS,
    RAP_CYCLIC_STATUS,
    RAP_DEFLATE_STATUS,
}massage_rap_knead_status_e;

//嵌套在RAP_CYCLIC_STATUS里的
typedef enum
{
    TOP_BAG,
    LEFT_BAG,
    RIGHT_BAG,
}massage_rap_knead_cyclic_status_e;

//肩部气袋的叩击状态
typedef enum
{
    SHOD_CYCLIC_STATUS,
    SHOD_END_STATUS,
}massage_rap_shoulder_status_e;

typedef struct
{
    //信号接收值
    uint8_t massage_skills;         //信号请求手法
    uint8_t massage_lvl;            //信号请求挡位
    uint8_t massage_times;          //信号请求次数

    //揉捏
    uint8_t knead_status;           //揉捏状态
    uint16_t knead_inflate_time;    //充气时间(用于计算内部时间)
    uint8_t knead_cyclic_count;     //循环次数
    uint16_t knead_cyclic_time;     //循环时间(用于计算内部时间)

    //点按
    uint16_t press_poll_time;       //充气时间(用于计算内部时间)
    uint8_t press_count;            //循环次数
    uint16_t press_top_time;
    uint16_t press_right_time;
    uint16_t press_left_time;
    uint8_t press_right_action_flag;
    uint8_t press_left_action_flag;
    uint16_t press_shoulder_time;

    //叩击
    //揉捏气袋叩击
    massage_rap_knead_status_e rap_knead_status;                    //揉捏气袋的叩击状态
    uint16_t rap_inflate_time;                                      //inflate状态时间(用于计算内部时间)
    massage_rap_knead_cyclic_status_e rap_knead_cyclic_status;      //揉捏气袋上左右气袋的状态
    uint8_t rap_top_cyclic_count;                                   //TOP的循环次数
    uint16_t rap_top_pre_time;                                      //Top的循环前的充气时间
    uint16_t rap_top_cyclic_time;                                   //TOP的循环时间(用于计算内部时间)
    uint8_t rap_right_cyclic_count;                                 //RIGHT的循环次数
    uint16_t rap_right_pre_time;                                    //RIGHT的循环前的充气时间
    uint16_t rap_right_cyclic_time;                                 //RIGHT的循环时间(用于计算内部时间)
    uint8_t rap_left_cyclic_count;                                  //LEFT的循环次数
    uint16_t rap_left_pre_time;                                     //LEFT的循环前的充气时间
    uint16_t rap_left_cyclic_time;                                  //LEFT的循环时间(用于计算内部时间)
    //肩部气袋叩击
    massage_rap_shoulder_status_e rap_shoulder_status;              //肩部气袋的叩击状态
    uint8_t rap_shoulder_cyclic_count;
    uint16_t rap_shoulder_pre_time;
    uint16_t rap_shoulder_cyclic_time;

    bool support_flag;                 //支撑气袋是否充气
    bool double_flag;                  //是否以双气袋工作
    massage_clockwise_e clockwise;
    massage_area_e area;
    uint8_t support_channel;
    uint8_t support_channel_r;
    uint8_t top_channel;
    uint8_t left_channel;
    uint8_t right_channel;

    uint8_t single_channel;
} massage_config_t;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Massage_Task_Init(void);
void Snf_Massage_Task(void);

#ifdef __cplusplus
}
#endif

#endif /* _MASSAGE_H_ */
