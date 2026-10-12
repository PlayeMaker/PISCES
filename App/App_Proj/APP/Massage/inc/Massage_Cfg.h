//
// Created by XZC on 2026/6/29.
//
#ifndef MASSAGE_CFG_H
#define MASSAGE_CFG_H
#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Platform_Types.h"
#include "Basic_Config.h"
#include "Rte_Log.h"
#include "Rte_Swc.h"
#include "App_Task_Cfg.h"
/************************ Macro Definitions ************************/
#ifdef MASSAGE_PRINTF_ENABLE
#define MASSAGE_PRINTF RTE_LOG_PRINTF
#else
#define MASSAGE_PRINTF(...)
#endif

/* RTE 泵阀/电源接口统一封装：RTE 接口名、工作掩码或通道含义变更时只需修改本段 */
#define MASSAGE_VALVE_RAMP(channel, state) Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control((channel), (state))
#define MASSAGE_VALVE_INFLATE(channel)     MASSAGE_VALVE_RAMP((channel), POWER_VALVE_STATE_RAMP_UP)
#define MASSAGE_VALVE_DEFLATE(channel)     MASSAGE_VALVE_RAMP((channel), POWER_VALVE_STATE_RAMP_DOWN)
#define MASSAGE_VALVE_SET_WORK(state)      Rte_Call_Sync_C_Massage_S_Valve_Set_Work_States((state), VALVE_MASSAGE_WORK_MASK)
#define MASSAGE_VALVE_GET_WORK()           Rte_Call_Sync_C_Massage_S_Valve_Get_Work_States()
#define MASSAGE_PUMP_SET_WORK(state)       Rte_Call_Sync_C_Massage_S_Pump_Set_Work_States((state), PUMP_MASSAGE_WORK_MASK)
#define MASSAGE_PUMP_GET_WORK()            Rte_Call_Sync_C_Massage_S_Pump_Get_Work_States()
#define MASSAGE_POWER_SET_LOAD(status)     Rte_Call_Sync_C_Massage_S_Power_Set_Load_States((status))

//支撑气袋阀类型判断：true=保压阀(断电后保压)，false=泄气阀(断电后泄气)
#define MASSAGE_SUPPORT_VALVE_IS_KEEPER() (MASSAGE_SUPPORT_VALVE_KEEPER == Snf_Massage_Get_Support_Valve_Type())

//根据支撑气袋阀类型二选一：保压阀取keeper_val，泄气阀取deflate_val
#define MASSAGE_SUPPORT_VALVE_SELECT(keeper_val, deflate_val) (MASSAGE_SUPPORT_VALVE_IS_KEEPER() ? (keeper_val) : (deflate_val))

#define MASSAGE_TIME_MS(tmp) (tmp / MASSAGE_TASK_PERIOD_MS)  //单位为ms,task周期为5ms
#define NO_ACTION            0
#define ACTION               1
#define COMPLETE_ACTION      0xFF

#define NONE_CHANNEL (0xFFU)  //无效通道

//泵阀启停时序：工作时先开阀延时后再开泵；停止时先关泵延时后再关阀
#define MASSAGE_PUMP_START_DELAY_TIME 500    //开泵延迟时间,mS
#define MASSAGE_VALVE_STOP_DELAY_TIME 20     //关阀延迟时间,mS
#define MASSAGE_CMD_RX_TIMEOUT_TIME   3000U  //命令报文丢失超时时间,mS
#define MASSAGE_PUMP_STOP_DELAY_TIME  3000U  //无区域工作时的关泵延迟时间(命令全0/报文丢失/动作结束),mS

//区域/手法的位掩码（用于手法分发表 Massage_Mode_Def.h 与合法手法判断）
#define MASSAGE_AREA_BIT(area) ((uint8)(1U << (uint8)(area)))
#define MASSAGE_MODE_BIT(mode) ((uint8)(1U << (uint8)(mode)))

#define MASSAGE_AREA_MASK_5_6     (MASSAGE_AREA_BIT(AREA_5) | MASSAGE_AREA_BIT(AREA_6))
#define MASSAGE_AREA_MASK_7_8     (MASSAGE_AREA_BIT(AREA_7) | MASSAGE_AREA_BIT(AREA_8))
#define MASSAGE_AREA_MASK_9_10    (MASSAGE_AREA_BIT(AREA_9) | MASSAGE_AREA_BIT(AREA_10))
#define MASSAGE_AREA_MASK_5_6_7_8 (MASSAGE_AREA_MASK_5_6 | MASSAGE_AREA_MASK_7_8)
/************************ Function Declarations ************************/

/************************ Type Definitions ************************/
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
} massage_area_e;

/**
 * @brief 按摩气袋方向枚举
 */
typedef enum
{
    CLOCKWISE,
    ANTICLOCKWISE,
} massage_clockwise_e;

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
 * @brief 揉捏模式枚举
 */
typedef enum
{
    KNEAD_INFLATE_STATUS,
    KNEAD_CYCLIC_STATUS,
    KNEAD_DEFLATE_STATUS,
} massage_knead_status_e;

/**
* @brief 揉捏气袋的叩击状态
*/
typedef enum
{
    RAP_KNEAD_INFLATE_STATUS,
    RAP_KNEAD_CYCLIC_STATUS,
    RAP_KNEAD_DEFLATE_STATUS,
} massage_rap_knead_status_e;

/**
* @brief 嵌套在RAP_KNEAD_CYCLIC_STATUS里的子状态
*/
typedef enum
{
    TOP_BAG,
    LEFT_BAG,
    RIGHT_BAG,
} massage_rap_knead_cyclic_status_e;

/**
* @brief 肩部气袋的叩击状态
*/
typedef enum
{
    RAP_SHOD_CYCLIC_STATUS,
    RAP_SHOD_END_STATUS,
} massage_rap_shoulder_status_e;

/**
* @brief 揉捏按摩结构体变量
*/
typedef struct
{
    //揉捏
    uint8  knead_status;        //揉捏状态
    uint16 knead_inflate_time;  //充气时间(用于计算内部时间)
    uint8  knead_cyclic_count;  //循环次数
    uint16 knead_cyclic_time;   //循环时间(用于计算内部时间)
    uint16 knead_deflate_time;  //放气时间
} massage_knead_config_t;

/**
* @brief 点按按摩结构体变量
*/
typedef struct
{
    //点按
    uint16 press_poll_inflate_time;  //充气时间(用于计算内部时间)
    uint16 press_poll_deflate_time;  //放气时间(用于计算内部时间)
    uint8  press_count;              //循环次数
    uint16 press_top_time;
    uint16 press_right_time;
    uint16 press_left_time;
    uint16 press_all_deflate_time;
    uint8  press_right_action_flag;
    uint8  press_left_action_flag;
    uint16 press_shoulder_inflate_time;
    uint16 press_shoulder_deflate_time;  //泄气计时(tick)，与其他计时器保持一致用uint16，防止目标时间>1275ms时回绕
} massage_press_config_t;

/**
* @brief 叩击按摩结构体变量
*/
typedef struct
{
    //叩击
    //揉捏气袋叩击
    massage_rap_knead_status_e rap_knead_status;  //揉捏气袋的叩击状态
    uint16                     rap_inflate_time;  //inflate状态时间(用于计算内部时间)
    uint16                     rap_deflate_time;  //deflate状态时间

    massage_rap_knead_cyclic_status_e rap_knead_cyclic_status;  //揉捏气袋上左右气袋的状态
    uint8                             rap_top_cyclic_count;     //TOP的循环次数
    uint16                            rap_top_pre_time;         //TOP的循环前的充气时间
    uint16                            rap_top_cyclic_time;      //TOP的循环时间(用于计算内部时间)
    uint8                             rap_right_cyclic_count;   //RIGHT的循环次数
    uint16                            rap_right_pre_time;       //RIGHT的循环前的充气时间
    uint16                            rap_right_cyclic_time;    //RIGHT的循环时间(用于计算内部时间)
    uint8                             rap_left_cyclic_count;    //LEFT的循环次数
    uint16                            rap_left_pre_time;        //LEFT的循环前的充气时间
    uint16                            rap_left_cyclic_time;     //LEFT的循环时间(用于计算内部时间)

    //肩部气袋叩击
    massage_rap_shoulder_status_e rap_shoulder_status;  //肩部气袋的叩击状态
    uint8                         rap_shoulder_cyclic_count;
    uint16                        rap_shoulder_pre_time;
    uint16                        rap_shoulder_cyclic_time;
} massage_rap_config_t;

/**
* @brief 按摩命令信号三要素（手法/挡位/次数）
*/
typedef struct
{
    uint8 skills;  //信号请求手法
    uint8 lvl;     //信号请求挡位
    uint8 times;   //信号请求次数
} massage_signal_t;
/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif  // MASSAGE_CFG_H
