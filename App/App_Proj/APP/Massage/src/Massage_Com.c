/************************ Include Files ************************/
#include <string.h>
#include "Massage.h"
#include "Basic_Config.h"
#include "Massage_Knead.h"
#include "Massage_Press.h"
#include "Massage_Rap.h"
#include "Rte_Log.h"
#include "Rte_Os.h"
#include "Rte_Pwm_If.h"
#include "Rte_Swc.h"
#include "Valve_Types.h"
#include "Version.h"
#include "Rte_Com.h"

#if defined(HIGH_CONFIGURATION)
#include "Massage_Mode_Class.h"
#include "Massage_Mode_Def.h"
#include "Massage_Mode_Class.h"
#include "Massage_Mode_Def.h"
#include "Massage_Mode_Class.h"
/************************ Macro Definitions ************************/
#define MASSAGE_ARRAY_SIZE(array) (sizeof(array) / sizeof((array)[0]))
/************************ Private Type Definitions ************************/
/**
 * @brief 区域命令读取/状态输出函数指针类型
 */
typedef void (*massage_cmd_read_func_t)(massage_signal_t* signal);
typedef void (*massage_sts_write_func_t)(const massage_config_t* massage_config);

/**
 * @brief 工作流程步骤函数指针类型
 */
typedef void (*massage_flow_func_t)(void);
/************************ Private Global Variables ************************/
static massage_support_valve_type_e massage_support_valve_type = MASSAGE_SUPPORT_VALVE_KEEPER;

/**
 * @brief  支撑气袋阀动作表：[阀类型][动作] = {前阀状态, 后阀状态}
 * @note   保压阀(KEEPER)断电后保压，泄气阀(DEFLATE)断电后泄气，两种硬件的动作组合不同
 */
static const uint8 support_valve_action_table[2][3][2] = {
    [MASSAGE_SUPPORT_VALVE_KEEPER] =
        {
            [MASSAGE_SUPPORT_ACTION_INFLATE] = { POWER_VALVE_STATE_RAMP_UP, POWER_VALVE_STATE_RAMP_DOWN },
            [MASSAGE_SUPPORT_ACTION_HOLD]    = { POWER_VALVE_STATE_RAMP_DOWN, POWER_VALVE_STATE_RAMP_DOWN },
            [MASSAGE_SUPPORT_ACTION_DEFLATE] = { POWER_VALVE_STATE_RAMP_DOWN, POWER_VALVE_STATE_RAMP_UP },
        },
    [MASSAGE_SUPPORT_VALVE_DEFLATE] =
        {
            [MASSAGE_SUPPORT_ACTION_INFLATE] = { POWER_VALVE_STATE_RAMP_UP, POWER_VALVE_STATE_RAMP_UP },
            [MASSAGE_SUPPORT_ACTION_HOLD]    = { POWER_VALVE_STATE_RAMP_DOWN, POWER_VALVE_STATE_RAMP_UP },
            [MASSAGE_SUPPORT_ACTION_DEFLATE] = { POWER_VALVE_STATE_RAMP_DOWN, POWER_VALVE_STATE_RAMP_DOWN },
        },
};

/**
 * @brief  揉捏/点按/叩击模式运行时配置数组。
 * @note   全部字段初值均为0（各状态枚举初始值恰好为0），静态零初始化即可，
 *         运行中由各自的Init函数复位。
 */
static massage_knead_config_t massage_knead_config[AREA_MAX];
static massage_press_config_t massage_press_config[AREA_MAX];
static massage_rap_config_t   massage_rap_config[AREA_MAX];

/**
 * @brief  Main configuration array of the massage area
 */
static massage_config_t massage_area[AREA_MAX] = {
#define _ITEM(a, b, c, d, e, f, g)                            \
    [a] = { .top_channel          = b,                        \
            .right_channel        = c,                        \
            .left_channel         = d,                        \
            .support_channel      = e,                        \
            .support_channel_r    = f,                        \
            .single_channel       = g,                        \
            .massage_knead_config = &massage_knead_config[a], \
            .massage_press_config = &massage_press_config[a], \
            .massage_rap_config   = &massage_rap_config[a],   \
            .area                 = a,                        \
            .work_flag            = false }

    /**   area_id       top_channel       right_channel       left_channel      support_channel     support_channel_r    single_channel**/
    _ITEM(AREA_5, RTE_PWM_CHANNEL_AM13, RTE_PWM_CHANNEL_AM12, RTE_PWM_CHANNEL_AM11, NONE_CHANNEL, NONE_CHANNEL, NONE_CHANNEL),
    _ITEM(AREA_6, RTE_PWM_CHANNEL_AM8, RTE_PWM_CHANNEL_AM10, RTE_PWM_CHANNEL_AM9, NONE_CHANNEL, NONE_CHANNEL, NONE_CHANNEL),
    _ITEM(AREA_7, RTE_PWM_CHANNEL_AM3, RTE_PWM_CHANNEL_AM2, RTE_PWM_CHANNEL_AM1, RTE_PWM_CHANNEL_RN1, RTE_PWM_CHANNEL_RNR1,
          NONE_CHANNEL),
    _ITEM(AREA_8, RTE_PWM_CHANNEL_AM4, RTE_PWM_CHANNEL_AM6, RTE_PWM_CHANNEL_AM5, RTE_PWM_CHANNEL_RN2, RTE_PWM_CHANNEL_RNR2,
          NONE_CHANNEL),
    _ITEM(AREA_9, NONE_CHANNEL, NONE_CHANNEL, NONE_CHANNEL, NONE_CHANNEL, NONE_CHANNEL, RTE_PWM_CHANNEL_AM14),
    _ITEM(AREA_10, NONE_CHANNEL, NONE_CHANNEL, NONE_CHANNEL, NONE_CHANNEL, NONE_CHANNEL, RTE_PWM_CHANNEL_AM7),
};

/**
 * @brief  每个区域支持的合法手法掩码表（MASSAGE_MODE_IDLE 恒合法，不在表中）
 * @note   不再手写：由 Snf_Massage_Task_Init 根据 mode_dispatch_table 推导填充，单一数据源
 */
static uint8 valid_mode_mask[AREA_MAX] = { 0 };

/**
 * @brief  命令报文最近一次接收时间(tick)，由 Snf_Massage_Cmd_Rx_Notify 更新
 */
static volatile uint32 massage_cmd_last_rx_ms = 0U;
/************************ Private Function Declarations ************************/
static bool _Snf_Massage_Signal_Check(const massage_signal_t* signal);
static void _Snf_Massage_Command_Update(void);
static bool _Snf_Massage_Cmd_Is_Active(const massage_config_t* massage_config);
static void _Snf_Massage_Single_Double_Get(void);
static void _Snf_Massage_Status_Init(massage_config_t* massage_config);
static bool _Snf_Massage_Delay_Elapsed(uint16* cnt, uint16 delay_ms);
static void _Snf_Massage_Pump_Valve_Control(void);
static void _Snf_Massage_Air_Bag_Control(void);
static void _Snf_Massage_Mode_Prepare(massage_config_t* massage_config);
static void _Snf_Massage_Output(void);
static void _Snf_Massage_Handle(void);
static void _Snf_Massage_Valid_Mode_Mask_Init(void);
static void _Snf_Massage_Support_Valve_Type_Init(void);

/**
 * @brief  按摩工作流程表：每周期按序执行的流程步骤，流程调整(增删/换序)只改这里
 */
static const massage_flow_func_t massage_flow_table[] = {
    _Snf_Massage_Command_Update,      //命令读取与校验
    _Snf_Massage_Single_Double_Get,   //单双侧联动判断
    _Snf_Massage_Pump_Valve_Control,  //泵阀启停时序
    _Snf_Massage_Air_Bag_Control,     //手法分发执行
    _Snf_Massage_Output,              //状态输出
};
/************************ Signal IO Functions ************************/
/*
 * 区域信号接口表：每行一个区域(区域id, 生成函数名, RTE接口名)，RTE接口名全量写出，便于搜索定位。
 * 信号/接口变更只改对应行；新增区域时 D/P 两处列表都要加行，读写函数和函数表由列表自动生成。
 */
#if defined(PISCES_MCM_D)
#define MASSAGE_CMD_READ_LIST(X)                                                                                              \
    X(AREA_5, _Snf_Massage_Read_Cmd_5, Rte_Read_DrvKneadingMassgSkillsCmd5_DrvKneadingMassgSkillsCmd5,                        \
      Rte_Read_DrvKneadingMassgLvlCmd5_DrvKneadingMassgLvlCmd5, Rte_Read_DrvKneadingMassgTimesCmd5_DrvKneadingMassgTimesCmd5) \
    X(AREA_6, _Snf_Massage_Read_Cmd_6, Rte_Read_DrvKneadingMassgSkillsCmd6_DrvKneadingMassgSkillsCmd6,                        \
      Rte_Read_DrvKneadingMassgLvlCmd6_DrvKneadingMassgLvlCmd6, Rte_Read_DrvKneadingMassgTimesCmd6_DrvKneadingMassgTimesCmd6) \
    X(AREA_7, _Snf_Massage_Read_Cmd_7, Rte_Read_DrvKneadingMassgSkillsCmd7_DrvKneadingMassgSkillsCmd7,                        \
      Rte_Read_DrvKneadingMassgLvlCmd7_DrvKneadingMassgLvlCmd7, Rte_Read_DrvKneadingMassgTimesCmd7_DrvKneadingMassgTimesCmd7) \
    X(AREA_8, _Snf_Massage_Read_Cmd_8, Rte_Read_DrvKneadingMassgSkillsCmd8_DrvKneadingMassgSkillsCmd8,                        \
      Rte_Read_DrvKneadingMassgLvlCmd8_DrvKneadingMassgLvlCmd8, Rte_Read_DrvKneadingMassgTimesCmd8_DrvKneadingMassgTimesCmd8) \
    X(AREA_9, _Snf_Massage_Read_Cmd_9, Rte_Read_DrvKneadingMassgSkillsCmd9_DrvKneadingMassgSkillsCmd9,                        \
      Rte_Read_DrvKneadingMassgLvlCmd9_DrvKneadingMassgLvlCmd9, Rte_Read_DrvKneadingMassgTimesCmd9_DrvKneadingMassgTimesCmd9) \
    X(AREA_10, _Snf_Massage_Read_Cmd_10, Rte_Read_DrvKneadingMassgSkillsCmd10_DrvKneadingMassgSkillsCmd10,                    \
      Rte_Read_DrvKneadingMassgLvlCmd10_DrvKneadingMassgLvlCmd10,                                                             \
      Rte_Read_DrvKneadingMassgTimesCmd10_DrvKneadingMassgTimesCmd10)
#define MASSAGE_STS_WRITE_LIST(X)                                                                                       \
    X(AREA_5, _Snf_Massage_Write_Sts_5, Rte_Write_DrvKneadingMassgSkillsSts5_DrvKneadingMassgSkillsSts5,                \
      Rte_Write_DrvKneadingMassglvlSts5_DrvKneadingMassglvlSts5, Rte_Write_DrvKneadingMassgTime5_DrvKneadingMassgTime5) \
    X(AREA_6, _Snf_Massage_Write_Sts_6, Rte_Write_DrvKneadingMassgSkillsSts6_DrvKneadingMassgSkillsSts6,                \
      Rte_Write_DrvKneadingMassglvlSts6_DrvKneadingMassglvlSts6, Rte_Write_DrvKneadingMassgTime6_DrvKneadingMassgTime6) \
    X(AREA_7, _Snf_Massage_Write_Sts_7, Rte_Write_DrvKneadingMassgSkillsSts7_DrvKneadingMassgSkillsSts7,                \
      Rte_Write_DrvKneadingMassglvlSts7_DrvKneadingMassglvlSts7, Rte_Write_DrvKneadingMassgTime7_DrvKneadingMassgTime7) \
    X(AREA_8, _Snf_Massage_Write_Sts_8, Rte_Write_DrvKneadingMassgSkillsSts8_DrvKneadingMassgSkillsSts8,                \
      Rte_Write_DrvKneadingMassglvlSts8_DrvKneadingMassglvlSts8, Rte_Write_DrvKneadingMassgTime8_DrvKneadingMassgTime8) \
    X(AREA_9, _Snf_Massage_Write_Sts_9, Rte_Write_DrvKneadingMassgSkillsSts9_DrvKneadingMassgSkillsSts9,                \
      Rte_Write_DrvKneadingMassglvlSts9_DrvKneadingMassglvlSts9, Rte_Write_DrvKneadingMassgTime9_DrvKneadingMassgTime9) \
    X(AREA_10, _Snf_Massage_Write_Sts_10, Rte_Write_DrvKneadingMassgSkillsSts10_DrvKneadingMassgSkillsSts10,            \
      Rte_Write_DrvKneadingMassglvlSts10_DrvKneadingMassglvlSts10, Rte_Write_DrvKneadingMassgTime10_DrvKneadingMassgTime10)
#elif defined(PISCES_MCM_P)
#define MASSAGE_CMD_READ_LIST(X)                                                                             \
    X(AREA_5, _Snf_Massage_Read_Cmd_5, Rte_Read_PassKneadingMassgSkillsCmd5_PassKneadingMassgSkillsCmd5,     \
      Rte_Read_PassKneadingMassgLvlCmd5_PassKneadingMassgLvlCmd5,                                            \
      Rte_Read_PassKneadingMassgTimesCmd5_PassKneadingMassgTimesCmd5)                                        \
    X(AREA_6, _Snf_Massage_Read_Cmd_6, Rte_Read_PassKneadingMassgSkillsCmd6_PassKneadingMassgSkillsCmd6,     \
      Rte_Read_PassKneadingMassgLvlCmd6_PassKneadingMassgLvlCmd6,                                            \
      Rte_Read_PassKneadingMassgTimesCmd6_PassKneadingMassgTimesCmd6)                                        \
    X(AREA_7, _Snf_Massage_Read_Cmd_7, Rte_Read_PassKneadingMassgSkillsCmd7_PassKneadingMassgSkillsCmd7,     \
      Rte_Read_PassKneadingMassgLvlCmd7_PassKneadingMassgLvlCmd7,                                            \
      Rte_Read_PassKneadingMassgTimesCmd7_PassKneadingMassgTimesCmd7)                                        \
    X(AREA_8, _Snf_Massage_Read_Cmd_8, Rte_Read_PassKneadingMassgSkillsCmd8_PassKneadingMassgSkillsCmd8,     \
      Rte_Read_PassKneadingMassgLvlCmd8_PassKneadingMassgLvlCmd8,                                            \
      Rte_Read_PassKneadingMassgTimesCmd8_PassKneadingMassgTimesCmd8)                                        \
    X(AREA_9, _Snf_Massage_Read_Cmd_9, Rte_Read_PassKneadingMassgSkillsCmd9_PassKneadingMassgSkillsCmd9,     \
      Rte_Read_PassKneadingMassgLvlCmd9_PassKneadingMassgLvlCmd9,                                            \
      Rte_Read_PassKneadingMassgTimesCmd9_PassKneadingMassgTimesCmd9)                                        \
    X(AREA_10, _Snf_Massage_Read_Cmd_10, Rte_Read_PassKneadingMassgSkillsCmd10_PassKneadingMassgSkillsCmd10, \
      Rte_Read_PassKneadingMassgLvlCmd10_PassKneadingMassgLvlCmd10,                                          \
      Rte_Read_PassKneadingMassgTimesCmd10_PassKneadingMassgTimesCmd10)
#define MASSAGE_STS_WRITE_LIST(X)                                                                                           \
    X(AREA_5, _Snf_Massage_Write_Sts_5, Rte_Write_PassKneadingMassgSkillsSts5_PassKneadingMassgSkillsSts5,                  \
      Rte_Write_PassKneadingMassgLvlSts5_PassKneadingMassgLvlSts5, Rte_Write_PassKneadingMassgTime5_PassKneadingMassgTime5) \
    X(AREA_6, _Snf_Massage_Write_Sts_6, Rte_Write_PassKneadingMassgSkillsSts6_PassKneadingMassgSkillsSts6,                  \
      Rte_Write_PassKneadingMassgLvlSts6_PassKneadingMassgLvlSts6, Rte_Write_PassKneadingMassgTime6_PassKneadingMassgTime6) \
    X(AREA_7, _Snf_Massage_Write_Sts_7, Rte_Write_PassKneadingMassgSkillsSts7_PassKneadingMassgSkillsSts7,                  \
      Rte_Write_PassKneadingMassgLvlSts7_PassKneadingMassgLvlSts7, Rte_Write_PassKneadingMassgTime7_PassKneadingMassgTime7) \
    X(AREA_8, _Snf_Massage_Write_Sts_8, Rte_Write_PassKneadingMassgSkillsSts8_PassKneadingMassgSkillsSts8,                  \
      Rte_Write_PassKneadingMassgLvlSts8_PassKneadingMassgLvlSts8, Rte_Write_PassKneadingMassgTime8_PassKneadingMassgTime8) \
    X(AREA_9, _Snf_Massage_Write_Sts_9, Rte_Write_PassKneadingMassgSkillsSts9_PassKneadingMassgSkillsSts9,                  \
      Rte_Write_PassKneadingMassgLvlSts9_PassKneadingMassgLvlSts9, Rte_Write_PassKneadingMassgTime9_PassKneadingMassgTime9) \
    X(AREA_10, _Snf_Massage_Write_Sts_10, Rte_Write_PassKneadingMassgSkillsSts10_PassKneadingMassgSkillsSts10,              \
      Rte_Write_PassKneadingMassgLvlSts10_PassKneadingMassgLvlSts10,                                                        \
      Rte_Write_PassKneadingMassgTime10_PassKneadingMassgTime10)
#endif

//由接口表生成每个区域的命令读取/状态输出函数
#define _MASSAGE_DEF_CMD_READ(area, func_name, skills_read, lvl_read, times_read) \
    static void func_name(massage_signal_t* signal)                               \
    {                                                                             \
        (void)skills_read(&signal->skills);                                       \
        (void)lvl_read(&signal->lvl);                                             \
        (void)times_read(&signal->times);                                         \
    }
#define _MASSAGE_DEF_STS_WRITE(area, func_name, skills_write, lvl_write, time_write) \
    static void func_name(const massage_config_t* massage_config)                    \
    {                                                                                \
        (void)skills_write(massage_config->massage_skills);                          \
        (void)lvl_write(massage_config->massage_lvl);                                \
        (void)time_write(massage_config->massage_output_time);                       \
    }

MASSAGE_CMD_READ_LIST(_MASSAGE_DEF_CMD_READ)
MASSAGE_STS_WRITE_LIST(_MASSAGE_DEF_STS_WRITE)

/**
 * @brief  每个区域的命令读取函数表(由接口表生成，增删区域不用改这里)
 */
static const massage_cmd_read_func_t massage_cmd_read_table[AREA_MAX] = {
#define _MASSAGE_CMD_READ_ENTRY(area, func_name, skills_read, lvl_read, times_read) [area] = func_name,
    MASSAGE_CMD_READ_LIST(_MASSAGE_CMD_READ_ENTRY)
#undef _MASSAGE_CMD_READ_ENTRY
};

/**
 * @brief  每个区域的状态输出函数表(由接口表生成，增删区域不用改这里)
 */
static const massage_sts_write_func_t massage_sts_write_table[AREA_MAX] = {
#define _MASSAGE_STS_WRITE_ENTRY(area, func_name, skills_write, lvl_write, time_write) [area] = func_name,
    MASSAGE_STS_WRITE_LIST(_MASSAGE_STS_WRITE_ENTRY)
#undef _MASSAGE_STS_WRITE_ENTRY
};
/************************ Private Function Implementations ************************/
/**
 * @brief  检查信号组合是否合法
 * @param  signal - 按摩命令信号
 * @return bool - true:合法(全0表示停止，或全非0表示有效命令)；false:非法组合
 * @note   非法组合(部分为0)忽略本次信号，保持当前命令继续执行
 */
static bool _Snf_Massage_Signal_Check(const massage_signal_t* signal)
{
    bool all_zero  = (signal->skills == 0U) && (signal->lvl == 0U) && (signal->times == 0U);
    bool all_valid = (signal->skills != 0U) && (signal->lvl != 0U) && (signal->times != 0U);

    return (all_zero || all_valid);
}

/**
 * @brief  Init every area status
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 * @note   复位手法子状态机、清工作标志、所有气袋阀泄气；命令变化/停止时统一由此复位
 */
static void _Snf_Massage_Status_Init(massage_config_t* massage_config)
{
    //揉捏
    Snf_Massage_Knead_Init(massage_config->massage_knead_config);
    //点按
    Snf_Massage_Press_Init(massage_config->massage_press_config);
    //叩击
    Snf_Massage_Rap_Init(massage_config->massage_rap_config);

    MASSAGE_POWER_SET_LOAD(POWER_LOAD_STATUS_NORMAL);

    massage_config->work_flag = false;

    //按摩气袋全部泄气
    const uint8 deflate_channels[] = { massage_config->top_channel, massage_config->left_channel, massage_config->right_channel,
                                       massage_config->single_channel };

    for (uint8 i = 0; i < (uint8)MASSAGE_ARRAY_SIZE(deflate_channels); i++)
    {
        if (NONE_CHANNEL != deflate_channels[i])
        {
            MASSAGE_VALVE_DEFLATE(deflate_channels[i]);
        }
    }

    //支撑气袋泄气
    Snf_Massage_Support_Valve_Control(massage_config->support_channel, massage_config->support_channel_r,
                                      MASSAGE_SUPPORT_ACTION_DEFLATE);
}

/**
 * @brief  读取各区域按摩命令信号，校验合法性，命令变化时统一复位并启动
 * @param  None
 * @return None
 * @note   覆盖异常场景：
 *         1.按摩中被打断(手法/挡位/次数变化或清零)：只在此复位一次，气袋泄气后从头开始；
 *         2.非法信号组合(部分为0)：忽略并保持当前命令；
 *         3.手法值超出枚举范围：按停止处理；
 *         4.手法合法但当前区域不支持：不启动并打日志；
 *         5.命令报文丢失期间不采纳总线值：Com对这些信号无超时替换(COM_RX_TIMEOUT_NONE)，
 *           丢帧后缓冲区仍保持最后一次接收的命令，若不清除丢失保护，停泵清零后会被
 *           残留命令当成新命令重新触发，导致丢帧后一直工作；
 *           报文恢复后超时解除，相同命令相对已清零的内部状态可正常重新触发。
 */
static void _Snf_Massage_Command_Update(void)
{
    massage_signal_t signal;

    //报文丢失超时期间保持当前内部命令不变(工作区域继续按原命令跑完流程)
    if (RTE_OS_IS_TIMEOUT(massage_cmd_last_rx_ms, MASSAGE_CMD_RX_TIMEOUT_TIME))
    {
        return;
    }

    for (int i = 0; i < AREA_MAX; i++)
    {
        signal.skills = 0;
        signal.lvl    = 0;
        signal.times  = 0;
        massage_cmd_read_table[i](&signal);

        //手法值超出枚举范围视为非法：按停止处理，防止状态机悬挂
        if (signal.skills > MASSAGE_MODE_POINT_MASSAGE)
        {
            MASSAGE_PRINTF("Massage area %d invalid skills %d, force idle\r\n", i, signal.skills);
            signal.skills = MASSAGE_MODE_IDLE;
            signal.lvl    = 0;
            signal.times  = 0;
        }

        if (!_Snf_Massage_Signal_Check(&signal))
        {
            MASSAGE_PRINTF("Massage area %d invalid signal %d/%d/%d, keep last\r\n", i, signal.skills, signal.lvl,
                           signal.times);
            continue;
        }

        if ((massage_area[i].massage_skills == signal.skills) && (massage_area[i].massage_lvl == signal.lvl) &&
            (massage_area[i].massage_times == signal.times))
        {
            continue;
        }

        //命令变化(含按摩中被打断)：统一复位一次
        _Snf_Massage_Status_Init(&massage_area[i]);

        massage_area[i].massage_skills = signal.skills;
        massage_area[i].massage_lvl    = signal.lvl;
        massage_area[i].massage_times  = signal.times;

        if ((signal.skills != MASSAGE_MODE_IDLE) && ((valid_mode_mask[i] & MASSAGE_MODE_BIT(signal.skills)) != 0U))
        {
            massage_area[i].work_flag = true;
        }
        else
        {
            if (signal.skills != MASSAGE_MODE_IDLE)
            {
                MASSAGE_PRINTF("Massage area %d not support mode %d\r\n", i, signal.skills);
            }
            massage_area[i].work_flag = false;
        }
    }
}

/**
 * @brief  判断区域命令是否有效(手法/挡位/次数均非0)
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - true:命令有效
 */
static bool _Snf_Massage_Cmd_Is_Active(const massage_config_t* massage_config)
{
    return (massage_config->massage_skills != 0U) && (massage_config->massage_lvl != 0U) &&
           (massage_config->massage_times != 0U);
}

/**
 * @brief  Get every area single or double action
 * @param  None
 * @return None
 */
static void _Snf_Massage_Single_Double_Get(void)
{
    bool pair_action;

    pair_action = _Snf_Massage_Cmd_Is_Active(&massage_area[AREA_5]) && _Snf_Massage_Cmd_Is_Active(&massage_area[AREA_6]);
    massage_area[AREA_5].double_flag = pair_action;
    massage_area[AREA_6].double_flag = pair_action;

    pair_action = _Snf_Massage_Cmd_Is_Active(&massage_area[AREA_7]) && _Snf_Massage_Cmd_Is_Active(&massage_area[AREA_8]);
    massage_area[AREA_7].double_flag = pair_action;
    massage_area[AREA_8].double_flag = pair_action;

    pair_action = _Snf_Massage_Cmd_Is_Active(&massage_area[AREA_9]) && _Snf_Massage_Cmd_Is_Active(&massage_area[AREA_10]);
    massage_area[AREA_9].double_flag  = pair_action;
    massage_area[AREA_10].double_flag = pair_action;
}

/**
 * @brief  5ms任务周期下的软件延时计数
 * @param  cnt      - 计数器指针(到时自动清零,保证下次延时从头计数)
 * @param  delay_ms - 延时时间,单位ms
 * @return bool - true:延时时间到；false:延时中
 */
static bool _Snf_Massage_Delay_Elapsed(uint16* cnt, uint16 delay_ms)
{
    if (*cnt < (uint16)MASSAGE_TIME_MS(delay_ms))
    {
        (*cnt)++;
        return false;
    }

    *cnt = 0;
    return true;
}

/**
 * @brief  Control pump and valve
 * @param  None
 * @return None
 * @note   启停依据报文命令与区域工作状态：
 *         任一区域在工作中(含报文丢失期间)保持泵阀开启，按摩流程自然跑完；
 *         无区域工作时(命令全0/报文丢失/动作结束但报文值未变)统一延时
 *         MASSAGE_PUMP_STOP_DELAY_TIME后关泵关阀，延时内来新命令则取消停止，
 *         避免连续按摩间隙泵频繁启停；
 *         因报文丢失超时(>MASSAGE_CMD_RX_TIMEOUT_TIME)停泵时清掉残留命令(状态更新)，
 *         保证报文恢复后命令变化检测能重新触发按摩；
 *         其他场景停泵残留命令不清除(否则总线上相同的命令值会被当成新命令重新触发)；
 *         启动时序：先开阀，延时MASSAGE_PUMP_START_DELAY_TIME后再开泵；
 *         停止时序：先关泵，延时MASSAGE_VALVE_STOP_DELAY_TIME后再关阀；
 *         泵未开时停止立即关阀，打断后重新启动时时序从头开始。
 */
static void _Snf_Massage_Pump_Valve_Control(void)
{
    static bool   pump_started   = false;
    static uint16 pump_time_cnt  = 0;
    static uint16 valve_time_cnt = 0;
    static uint16 stop_time_cnt  = 0;
    bool          any_working    = false;

    for (int i = 0; i < AREA_MAX; i++)
    {
        if ((false == massage_area[i].work_flag) && (massage_area[i].massage_skills == MASSAGE_MODE_IDLE))
        {
            massage_area[i].massage_output_time = 0;
        }
        any_working = any_working || massage_area[i].work_flag;
    }

    //任一区域在工作中(报文丢失也等流程跑完)：保持/启动泵阀
    if (any_working)
    {
        stop_time_cnt = 0;

        //先开阀
        valve_time_cnt = 0;
        MASSAGE_VALVE_SET_WORK(VALVE_WORK_STATE_ON);

        //开阀延时到后开泵；泵已开则保持
        if (pump_started || _Snf_Massage_Delay_Elapsed(&pump_time_cnt, MASSAGE_PUMP_START_DELAY_TIME))
        {
            pump_started = true;
            MASSAGE_PUMP_SET_WORK(PUMP_WORK_STATE_ON);
        }
        return;
    }

    //无区域工作：延时MASSAGE_PUMP_STOP_DELAY_TIME后关泵，延时内来新命令则取消停止
    if (stop_time_cnt < (uint16)MASSAGE_TIME_MS(MASSAGE_PUMP_STOP_DELAY_TIME))
    {
        stop_time_cnt++;
        return;
    }

    //报文丢失超时后的停泵：清掉残留命令(状态更新),
    //否则报文恢复后因命令无变化不会重新触发,出现泵转但按摩不动的问题；
    //注意仅丢帧场景清除，其他停泵场景报文仍有效，清除会导致相同命令被当成新命令重新触发
    if (RTE_OS_IS_TIMEOUT(massage_cmd_last_rx_ms, MASSAGE_CMD_RX_TIMEOUT_TIME))
    {
        for (int i = 0; i < AREA_MAX; i++)
        {
            massage_area[i].massage_skills = MASSAGE_MODE_IDLE;
            massage_area[i].massage_lvl    = 0;
            massage_area[i].massage_times  = 0;
        }
    }

    //先关泵
    pump_time_cnt = 0;
    MASSAGE_PUMP_SET_WORK(PUMP_WORK_STATE_OFF);

    //关泵延时到后关阀；泵未开过则立即关阀
    if (!pump_started || _Snf_Massage_Delay_Elapsed(&valve_time_cnt, MASSAGE_VALVE_STOP_DELAY_TIME))
    {
        pump_started = false;
        MASSAGE_VALVE_SET_WORK(VALVE_WORK_STATE_OFF);
    }
}

/**
 * @brief  手法分发前的区域参数准备：支撑气袋标志与揉捏方向
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 * @note   区域7/8带腰部支撑(点按按摩除外)，其余区域不带；
 *         点按按摩固定方向：区域5/7顺时针，区域6/8逆时针。
 */
static void _Snf_Massage_Mode_Prepare(massage_config_t* massage_config)
{
    bool is_support_area = (massage_config->area == AREA_7) || (massage_config->area == AREA_8);

    massage_config->support_flag = is_support_area && (massage_config->massage_skills != MASSAGE_MODE_POINT_MASSAGE);

    switch (massage_config->massage_skills)
    {
        case MASSAGE_MODE_KNEADING_CLOCKWISE:
        case MASSAGE_MODE_RAP_CLOCKWISE:
            massage_config->clockwise = CLOCKWISE;
            break;
        case MASSAGE_MODE_KNEADING_ANTICLOCKWISE:
        case MASSAGE_MODE_RAP_ANTICLOCKWISE:
            massage_config->clockwise = ANTICLOCKWISE;
            break;
        case MASSAGE_MODE_POINT_MASSAGE:
            if ((massage_config->area == AREA_5) || (massage_config->area == AREA_7))
            {
                massage_config->clockwise = CLOCKWISE;
            }
            else
            {
                massage_config->clockwise = ANTICLOCKWISE;
            }
            break;
        default:
            break;
    }
}

/**
 * @brief  Massage can output
 * @param  None
 * @return None
 */
static void _Snf_Massage_Output(void)
{
    for (int i = 0; i < AREA_MAX; i++)
    {
        massage_sts_write_table[i](&massage_area[i]);
    }
}

/**
 * @brief  Massage control each airbag
 * @param  None
 * @return None
 * @note   泵未开(关闭或电源故障异常)或阀被关闭(如功率降级被Power模块强制关闭)时直接返回，
 *         状态机冻结，恢复后从断点继续；
 *         已完成(work_flag=false)但手法未清零的区域继续执行处理函数，保持气袋处于泄气状态。
 */
static void _Snf_Massage_Air_Bag_Control(void)
{
    if (MASSAGE_PUMP_GET_WORK() != PUMP_WORK_STATE_ON || MASSAGE_VALVE_GET_WORK() == VALVE_WORK_STATE_OFF)
    {
        return;
    }

    for (int i = 0; i < AREA_MAX; i++)
    {
        if (massage_area[i].massage_skills == MASSAGE_MODE_IDLE)
        {
            massage_area[i].massage_output_time = 0;
            continue;
        }

        _Snf_Massage_Mode_Prepare(&massage_area[i]);

        for (int j = 0; j < (int)MASSAGE_ARRAY_SIZE(mode_dispatch_table); j++)
        {
            if ((mode_dispatch_table[j].mode == massage_area[i].massage_skills) &&
                ((mode_dispatch_table[j].area_mask & MASSAGE_AREA_BIT(i)) != 0U))
            {
                mode_dispatch_table[j].handler(&massage_area[i]);
                break;
            }
        }
    }
}

/**
 * @brief  Massage handle function
 * @param  None
 * @return None
 * @note   按 massage_flow_table 顺序执行工作流程
 */
static void _Snf_Massage_Handle(void)
{
    for (uint8 i = 0; i < (uint8)MASSAGE_ARRAY_SIZE(massage_flow_table); i++)
    {
        massage_flow_table[i]();
    }
}

/**
 * @brief  初始化每个区域的合法手法掩码表
 * @param  None
 * @return None
 * @note   由 mode_dispatch_table 推导填充：单一数据源，避免两表不一致
 */
static void _Snf_Massage_Valid_Mode_Mask_Init(void)
{
    for (uint8 area = 0; area < (uint8)AREA_MAX; area++)
    {
        valid_mode_mask[area] = 0;
    }
    for (uint8 j = 0; j < (uint8)MASSAGE_ARRAY_SIZE(mode_dispatch_table); j++)
    {
        for (uint8 area = 0; area < (uint8)AREA_MAX; area++)
        {
            if ((mode_dispatch_table[j].area_mask & MASSAGE_AREA_BIT(area)) != 0U)
            {
                valid_mode_mask[area] |= MASSAGE_MODE_BIT(mode_dispatch_table[j].mode);
            }
        }
    }
}

/**
 * @brief  初始化支撑气袋阀类型
 * @param  None
 * @return None
 * @note   硬件号末两位为AA的使用保压阀，其他使用泄气阀；读取失败时按泄气阀处理
 */
static void _Snf_Massage_Support_Valve_Type_Init(void)
{
    uint8_t  hardware_version_len = 0;
    uint8_t* hardware_version = Rte_Call_Sync_C_Massage_S_Version_Get_Data(VERSION_ID_HARDWARE_VERSION, &hardware_version_len);

    if (NULL != hardware_version && hardware_version_len == DF_HARDWARE_NUMBER_SIZE && hardware_version[9] == 'A' &&
        hardware_version[10] == 'A')
    {
        massage_support_valve_type = MASSAGE_SUPPORT_VALVE_KEEPER;
    }
    else
    {
        massage_support_valve_type = MASSAGE_SUPPORT_VALVE_DEFLATE;
    }
}
/************************ Public Function Implementations ************************/
/**
 * @brief  Massage get support valve type
 * @param  None
 * @return massage_support_valve_type_e
 */
massage_support_valve_type_e Snf_Massage_Get_Support_Valve_Type(void)
{
    return massage_support_valve_type;
}

/**
 * @brief  支撑气袋阀控制。根据硬件阀类型（保压/泄气）从动作表查前、后阀状态并驱动。
 * @param  support_channel - 支撑气袋前阀通道（NONE_CHANNEL时不动作）
 * @param  support_channel_r - 支撑气袋后阀通道（NONE_CHANNEL时不动作）
 * @param  action - 支撑气袋动作（充气/保压/泄气）
 * @return None
 */
void Snf_Massage_Support_Valve_Control(uint8 support_channel, uint8 support_channel_r, massage_support_action_e action)
{
    const uint8* valve_state = support_valve_action_table[massage_support_valve_type][action];

    if (NONE_CHANNEL != support_channel)
    {
        MASSAGE_VALVE_RAMP(support_channel, valve_state[0]);
    }
    if (NONE_CHANNEL != support_channel_r)
    {
        MASSAGE_VALVE_RAMP(support_channel_r, valve_state[1]);
    }
}

/**
 * @brief  命令报文接收通知：记录最近接收时间，供报文丢失检测
 * @param  None
 * @return None
 */
void Snf_Massage_Cmd_Rx_Notify(void)
{
    massage_cmd_last_rx_ms = RTE_OS_GET_TICK();
}

/**
 * @brief  Initialize massage task function
 * @param  None
 * @return None
 * @note   后续新增初始化功能时，封装为独立函数后在此调用
 */
void Snf_Massage_Task_Init(void)
{
    _Snf_Massage_Valid_Mode_Mask_Init();
    _Snf_Massage_Support_Valve_Type_Init();
}

/**
 * @brief  Massage task function
 * @param  None
 * @return None
 */
void Snf_Massage_Task(void)
{
    _Snf_Massage_Handle();
}
#endif
