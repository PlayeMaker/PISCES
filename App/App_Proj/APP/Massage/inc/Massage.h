#ifndef _MASSAGE_H_
#define _MASSAGE_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stddef.h>
#include <stdbool.h>
#include "Platform_Types.h"
#include "Massage_Cfg.h"
/************************ Macro Definitions ************************/
#define MASSAGE_OUTPUT_TIME_MAX 25500  // 25.5s
#define MASSAGE_OUTPUT_TIME_CONVERT(time) \
    ((time >= MASSAGE_OUTPUT_TIME_MAX) ? MASSAGE_OUTPUT_TIME_MAX / 100 : (time) * 10 / 1000)  // 系数为0.1
/************************ Function Declarations ************************/

/************************ Type Definitions ************************/
/**
* @brief 按摩阀类型枚举
*/
typedef enum
{
    MASSAGE_SUPPORT_VALVE_KEEPER,   // 按摩支撑气袋，断电后保压
    MASSAGE_SUPPORT_VALVE_DEFLATE,  // 按摩支撑气袋，断电后泄气
} massage_support_valve_type_e;

/**
* @brief 支撑气袋动作枚举
*/
typedef enum
{
    MASSAGE_SUPPORT_ACTION_INFLATE,  // 支撑气袋充气
    MASSAGE_SUPPORT_ACTION_HOLD,     // 支撑气袋保压
    MASSAGE_SUPPORT_ACTION_DEFLATE,  // 支撑气袋泄气
} massage_support_action_e;

/**
* @brief 按摩模式枚举
*/
typedef enum
{
    MASSAGE_MODE_IDLE,                      //无按摩模式
    MASSAGE_MODE_KNEADING_CLOCKWISE,        //揉捏-顺时针
    MASSAGE_MODE_KNEADING_ANTICLOCKWISE,    //揉捏-逆时针
    MASSAGE_MODE_3_POINT_PRESSING,          //三点按压
    MASSAGE_MODE_3_SUPPORT_POINT_PRESSING,  //三点支撑按压
    MASSAGE_MODE_RAP_CLOCKWISE,             //叩击-顺时针
    MASSAGE_MODE_RAP_ANTICLOCKWISE,         //叩击-逆时针
    MASSAGE_MODE_POINT_MASSAGE,             //点按按摩
} massage_mode_e;

/**
* @brief 按摩配置结构体
*/
typedef struct
{
    //外发按摩时间
    uint16 massage_output_time;

    //信号接收值
    uint8 massage_skills;  //信号请求手法
    uint8 massage_lvl;     //信号请求挡位
    uint8 massage_times;   //信号请求次数

    //区域
    massage_area_e area;
    //工作标志位
    bool work_flag;

    //区域5，6，7，8
    bool                support_flag;       //支撑气袋是否充气
    bool                double_flag;        //是否以双气袋工作
    massage_clockwise_e clockwise;          //工作方向
    uint8               support_channel;    //支持气袋前通道
    uint8               support_channel_r;  //支持气袋后通道
    uint8               top_channel;        //按摩气袋头通道
    uint8               left_channel;       //按摩气袋左通道
    uint8               right_channel;      //按摩气袋右通道
    //区域9，10
    uint8 single_channel;  //单气袋通道

    //揉捏
    massage_knead_config_t* massage_knead_config;

    //点按
    massage_press_config_t* massage_press_config;

    //叩击
    //揉捏气袋叩击
    massage_rap_config_t* massage_rap_config;
} massage_config_t;
/************************ External Variables ************************/
/************************ Function Declarations ************************/
void                         Snf_Massage_Task_Init(void);
void                         Snf_Massage_Task(void);
void                         Snf_Massage_Cmd_Rx_Notify(void);
massage_support_valve_type_e Snf_Massage_Get_Support_Valve_Type(void);
void Snf_Massage_Support_Valve_Control(uint8 support_channel, uint8 support_channel_r, massage_support_action_e action);

#ifdef __cplusplus
}
#endif

#endif /* _MASSAGE_H_ */
