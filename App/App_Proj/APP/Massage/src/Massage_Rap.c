/************************ Include Files ************************/
#include <string.h>
#include "Rte_Swc.h"
#include "Massage_Rap.h"
/************************ Macro Definitions ************************/
/************************ Private Global Variables ************************/
/**
 * @brief 揉捏气袋叩击时间参数表，按[支撑标志][双/单气袋][强度]索引。
 *        支撑标志=1对应区域7/8（含支撑气袋预充参数），支撑标志=0对应区域5/6（无支撑气袋预充）。
 *        强度维度按枚举值索引（MASSAGE_INTENSITY_LOW/HIGH），IDLE(0)行空置。
 */
static const rap_knead_time_param_t rap_knead_time_param_table[2][2][3] = {
    // 无支撑（区域5/6）
    {
     {
            // 单气袋，低强度
            [MASSAGE_INTENSITY_LOW] = { 0, RAP_MASSAGE_AIR_SINGLE_5_6_INTENSITY_LOW_INFLATE_TIME,
                                        RAP_MASSAGE_AIG_SINGLE_5_6_INTENSITY_LOW_ACTION_INFLATE_TIME,
                                        RAP_MASSAGE_AIG_SINGLE_5_6_INTENSITY_LOW_ACTION_DEFLATE_TIME },
            // 单气袋，高强度
            [MASSAGE_INTENSITY_HIGH] = { 0, RAP_MASSAGE_AIR_SINGLE_5_6_INTENSITY_HIGH_INFLATE_TIME,
                                         RAP_MASSAGE_AIG_SINGLE_5_6_INTENSITY_HIGH_ACTION_INFLATE_TIME,
                                         RAP_MASSAGE_AIG_SINGLE_5_6_INTENSITY_HIGH_ACTION_DEFLATE_TIME },
        }, {
            // 双气袋，低强度
            [MASSAGE_INTENSITY_LOW] = { 0, RAP_MASSAGE_AIR_DOUBLE_5_6_INTENSITY_LOW_INFLATE_TIME,
                                        RAP_MASSAGE_AIG_DOUBLE_5_6_INTENSITY_LOW_ACTION_INFLATE_TIME,
                                        RAP_MASSAGE_AIG_DOUBLE_5_6_INTENSITY_LOW_ACTION_DEFLATE_TIME },
            // 双气袋，高强度
            [MASSAGE_INTENSITY_HIGH] = { 0, RAP_MASSAGE_AIR_DOUBLE_5_6_INTENSITY_HIGH_INFLATE_TIME,
                                         RAP_MASSAGE_AIG_DOUBLE_5_6_INTENSITY_HIGH_ACTION_INFLATE_TIME,
                                         RAP_MASSAGE_AIG_DOUBLE_5_6_INTENSITY_HIGH_ACTION_DEFLATE_TIME },
        }, },
    // 有支撑（区域7/8）
    {
     {
            // 单气袋，低强度
            [MASSAGE_INTENSITY_LOW] = { RAP_SUPPORT_AIR_SINGLE_7_8_INTENSITY_LOW_INFLATE_TIME,
                                        RAP_MASSAGE_AIR_SINGLE_7_8_INTENSITY_LOW_INFLATE_TIME,
                                        RAP_MASSAGE_AIG_SINGLE_7_8_INTENSITY_LOW_ACTION_INFLATE_TIME,
                                        RAP_MASSAGE_AIG_SINGLE_7_8_INTENSITY_LOW_ACTION_DEFLATE_TIME },
            // 单气袋，高强度
            [MASSAGE_INTENSITY_HIGH] = { RAP_SUPPORT_AIR_SINGLE_7_8_INTENSITY_HIGH_INFLATE_TIME,
                                         RAP_MASSAGE_AIR_SINGLE_7_8_INTENSITY_HIGH_INFLATE_TIME,
                                         RAP_MASSAGE_AIG_SINGLE_7_8_INTENSITY_HIGH_ACTION_INFLATE_TIME,
                                         RAP_MASSAGE_AIG_SINGLE_7_8_INTENSITY_HIGH_ACTION_DEFLATE_TIME },
        },   {
            // 双气袋，低强度
            [MASSAGE_INTENSITY_LOW] = { RAP_SUPPORT_AIR_DOUBLE_7_8_INTENSITY_LOW_INFLATE_TIME,
                                        RAP_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_LOW_INFLATE_TIME,
                                        RAP_MASSAGE_AIG_DOUBLE_7_8_INTENSITY_LOW_ACTION_INFLATE_TIME,
                                        RAP_MASSAGE_AIG_DOUBLE_7_8_INTENSITY_LOW_ACTION_DEFLATE_TIME },
            // 双气袋，高强度
            [MASSAGE_INTENSITY_HIGH] = { RAP_SUPPORT_AIR_DOUBLE_7_8_INTENSITY_HIGH_INFLATE_TIME,
                                         RAP_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_HIGH_INFLATE_TIME,
                                         RAP_MASSAGE_AIG_DOUBLE_7_8_INTENSITY_HIGH_ACTION_INFLATE_TIME,
                                         RAP_MASSAGE_AIG_DOUBLE_7_8_INTENSITY_HIGH_ACTION_DEFLATE_TIME },
        }, },
};

/**
 * @brief 肩部气袋叩击时间参数表，按[双/单气袋][强度]索引（区域9/10）。
 *        强度维度按枚举值索引（MASSAGE_INTENSITY_LOW/HIGH），IDLE(0)行空置。
 */
static const rap_shoulder_time_param_t rap_shoulder_time_param_table[2][3] = {
    // 单气袋
    {
     // 低强度
        [MASSAGE_INTENSITY_LOW] = { RAP_MASSAGE_AIG_SINGLE_9_10_INTENSITY_LOW_INFLATE_TIME,
                                    RAP_MASSAGE_AIG_SINGLE_9_10_INTENSITY_LOW_ACTION_INFLATE_TIME,
                                    RAP_MASSAGE_AIG_SINGLE_9_10_INTENSITY_LOW_ACTION_DEFLATE_TIME },
     // 高强度
        [MASSAGE_INTENSITY_HIGH] = { RAP_MASSAGE_AIG_SINGLE_9_10_INTENSITY_HIGH_INFLATE_TIME,
                                     RAP_MASSAGE_AIG_SINGLE_9_10_INTENSITY_HIGH_ACTION_INFLATE_TIME,
                                     RAP_MASSAGE_AIG_SINGLE_9_10_INTENSITY_HIGH_ACTION_DEFLATE_TIME },
     },
    // 双气袋
    {
     // 低强度
        [MASSAGE_INTENSITY_LOW] = { RAP_MASSAGE_AIG_DOUBLE_9_10_INTENSITY_LOW_INFLATE_TIME,
                                    RAP_MASSAGE_AIG_DOUBLE_9_10_INTENSITY_LOW_ACTION_INFLATE_TIME,
                                    RAP_MASSAGE_AIG_DOUBLE_9_10_INTENSITY_LOW_ACTION_DEFLATE_TIME },
     // 高强度
        [MASSAGE_INTENSITY_HIGH] = { RAP_MASSAGE_AIG_DOUBLE_9_10_INTENSITY_HIGH_INFLATE_TIME,
                                     RAP_MASSAGE_AIG_DOUBLE_9_10_INTENSITY_HIGH_ACTION_INFLATE_TIME,
                                     RAP_MASSAGE_AIG_DOUBLE_9_10_INTENSITY_HIGH_ACTION_DEFLATE_TIME },
     },
};
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Massage_Rap_Knead_TimeCalc(massage_config_t* massage_config);
static bool _Snf_Rap_Knead_Cyclic_Clockwise_Air_Bag_Control(massage_config_t* massage_config, bool double_flag, uint8 lvl);
static bool _Snf_Rap_Knead_Cyclic_Anticlockwise_Air_Bag_Control(massage_config_t* massage_config, bool double_flag, uint8 lvl);
static bool _Snf_Rap_Knead_Inflate(massage_config_t* massage_config, uint16 support_inflate_time);
static bool _Snf_Rap_Knead_Cyclic(massage_config_t* massage_config, bool double_flag, uint8 lvl);
static void _Snf_Rap_Knead_Deflate(massage_config_t* massage_config, uint16 rap_deflate_time);
static void _Snf_Shoulder_Rap_TimeCalc(massage_config_t* massage_config);
static bool _Snf_Shoulder_Rap_Cyclic(massage_config_t* massage_config);
static void _Snf_Shoulder_Rap_End(massage_config_t* massage_config);
/************************ Private Function Implementations ************************/
/********************************************************************************
************************* Knead Bag Rap *****************************************
********************************************************************************/

/**
 * @brief  叩击模式单个气袋循环控制通用函数。先进行预充气阶段，达到指定时间后进入循环阶段，在循环阶段根据设定的放气时间和充气时间进行循环控制，直到完成指定循环次数。
 * @param  massage_config - 按摩配置结构体指针
 * @param  channel - 气袋对应的阀门控制通道
 * @param  rap_cyclic_count - 当前循环次数计数器指针
 * @param  rap_pre_time - 预充气计时器指针
 * @param  rap_cyclic_time - 当前循环周期计时器指针
 * @param  rap_pre_target_time - 预充气目标时间
 * @param  rap_cyclic_deflate_target_time - 循环中放气阶段的目标时间
 * @param  rap_cyclic_inflate_target_time - 循环中充气阶段的目标时间
 * @return bool - 循环进行中返回true，循环完成返回false
 */
static bool _Snf_Rap_Cyclic_Bag_Control(massage_config_t* massage_config, uint8 channel, uint8* rap_cyclic_count,
                                        uint16* rap_pre_time, uint16* rap_cyclic_time, uint16 rap_pre_target_time,
                                        uint16 rap_cyclic_deflate_target_time, uint16 rap_cyclic_inflate_target_time)
{
    //循环前的充气时间
    if ((*rap_pre_time) < rap_pre_target_time)
    {
        MASSAGE_VALVE_INFLATE(channel);
        (*rap_pre_time)++;
        return true;
    }

    //循环次数
    if ((*rap_cyclic_count) < massage_config->massage_times)
    {
        if ((*rap_cyclic_time) < rap_cyclic_deflate_target_time)
        {
            MASSAGE_VALVE_DEFLATE(channel);
            (*rap_cyclic_time)++;
        }
        else if ((*rap_cyclic_time) < (rap_cyclic_deflate_target_time + rap_cyclic_inflate_target_time))
        {
            MASSAGE_VALVE_INFLATE(channel);
            (*rap_cyclic_time)++;
        }
        else
        {
            MASSAGE_VALVE_DEFLATE(channel);
            (*rap_cyclic_time) = 0;
            (*rap_cyclic_count)++;
        }
        return true;
    }
    return false;
}

/**
 * @brief  叩击模式气袋循环控制函数。按气袋(上/右/左)、双/单气袋标志和按摩强度等级查参数表，先进行预充气，然后按指定时序控制对应气袋进行充放气循环。
 * @param  massage_config - 按摩配置结构体指针
 * @param  bag - 目标气袋（TOP_BAG/RIGHT_BAG/LEFT_BAG）
 * @param  double_flag - 是否以双气袋工作
 * @param  lvl - 按摩强度等级（MASSAGE_INTENSITY_LOW/MASSAGE_INTENSITY_HIGH）
 * @return bool - 循环进行中返回true，循环完成返回false
 */
static bool _Snf_Rap_Cyclic_Bag_Handle(massage_config_t* massage_config, massage_rap_knead_cyclic_status_e bag,
                                       bool double_flag, uint8 lvl)
{
    massage_rap_config_t*         rap_config = massage_config->massage_rap_config;
    const rap_knead_time_param_t* param;
    uint8                         channel;
    uint8*                        cyclic_count;
    uint16*                       pre_time;
    uint16*                       cyclic_time;

    param = Snf_Massage_Rap_Get_Knead_Param(massage_config->support_flag, double_flag, lvl);
    if (param == NULL)
    {
        MASSAGE_PRINTF("rap cyclic invalid lvl %d\r\n", lvl);
        return false;
    }

    switch (bag)
    {
        case TOP_BAG:
            channel      = massage_config->top_channel;
            cyclic_count = &rap_config->rap_top_cyclic_count;
            pre_time     = &rap_config->rap_top_pre_time;
            cyclic_time  = &rap_config->rap_top_cyclic_time;
            break;
        case RIGHT_BAG:
            channel      = massage_config->right_channel;
            cyclic_count = &rap_config->rap_right_cyclic_count;
            pre_time     = &rap_config->rap_right_pre_time;
            cyclic_time  = &rap_config->rap_right_cyclic_time;
            break;
        case LEFT_BAG:
            channel      = massage_config->left_channel;
            cyclic_count = &rap_config->rap_left_cyclic_count;
            pre_time     = &rap_config->rap_left_pre_time;
            cyclic_time  = &rap_config->rap_left_cyclic_time;
            break;
        default:
            MASSAGE_PRINTF("rap cyclic invalid bag %d\r\n", bag);
            return false;
    }

    return _Snf_Rap_Cyclic_Bag_Control(
        massage_config, channel, cyclic_count, pre_time, cyclic_time, MASSAGE_TIME_MS(param->massage_inflate_time),
        MASSAGE_TIME_MS(param->action_deflate_time), MASSAGE_TIME_MS(param->action_inflate_time));
}

/**
 * @brief  揉捏叩击模式时间计算函数。根据双侧/单侧标志、腰部支撑标志和按摩强度等级查参数表，计算叩击输出总时间。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
static void _Snf_Massage_Rap_Knead_TimeCalc(massage_config_t* massage_config)
{
    uint32_t                      calc_time = 0;
    const rap_knead_time_param_t* param =
        Snf_Massage_Rap_Get_Knead_Param(massage_config->support_flag, massage_config->double_flag, massage_config->massage_lvl);

    if (param == NULL)
    {
        MASSAGE_PRINTF("rap knead invalid lvl %d\r\n", massage_config->massage_lvl);
    }
    else
    {
        calc_time = param->support_inflate_time +
                    (param->massage_inflate_time +
                     (param->action_inflate_time + param->action_deflate_time) * massage_config->massage_times) *
                        3;
    }

    massage_config->massage_output_time = MASSAGE_OUTPUT_TIME_CONVERT(calc_time);
}

/**
 * @brief  叩击模式揉捏气袋顺时针循环控制函数。按照上→右→左的顺序依次执行对应气袋的叩击循环，完成后状态机流转至下一个气袋。
 * @param  massage_config - 按摩配置结构体指针
 * @param  double_flag - 是否以双气袋工作
 * @param  lvl - 按摩强度等级
 * @return bool - 循环进行中返回true，循环完成返回false
 */
static bool _Snf_Rap_Knead_Cyclic_Clockwise_Air_Bag_Control(massage_config_t* massage_config, bool double_flag, uint8 lvl)
{
    massage_rap_config_t* rap_config = massage_config->massage_rap_config;

    switch (rap_config->rap_knead_cyclic_status)
    {
        case TOP_BAG:
            if (!_Snf_Rap_Cyclic_Bag_Handle(massage_config, TOP_BAG, double_flag, lvl))
            {
                rap_config->rap_knead_cyclic_status = RIGHT_BAG;
            }
            break;
        case RIGHT_BAG:
            if (!_Snf_Rap_Cyclic_Bag_Handle(massage_config, RIGHT_BAG, double_flag, lvl))
            {
                rap_config->rap_knead_cyclic_status = LEFT_BAG;
            }
            break;
        case LEFT_BAG:
            if (!_Snf_Rap_Cyclic_Bag_Handle(massage_config, LEFT_BAG, double_flag, lvl))
            {
                return false;
            }
            break;
        default:
            MASSAGE_PRINTF("rap knead invalid cyclic status %d, stop\r\n", rap_config->rap_knead_cyclic_status);
            return false;
    }
    return true;
}

/**
 * @brief  叩击模式揉捏气袋逆时针循环控制函数。按照上→左→右的顺序依次执行对应气袋的叩击循环，完成后状态机流转至下一个气袋。
 * @param  massage_config - 按摩配置结构体指针
 * @param  double_flag - 是否以双气袋工作
 * @param  lvl - 按摩强度等级
 * @return bool - 循环进行中返回true，循环完成返回false
 */
static bool _Snf_Rap_Knead_Cyclic_Anticlockwise_Air_Bag_Control(massage_config_t* massage_config, bool double_flag, uint8 lvl)
{
    massage_rap_config_t* rap_config = massage_config->massage_rap_config;

    switch (rap_config->rap_knead_cyclic_status)
    {
        case TOP_BAG:
            if (!_Snf_Rap_Cyclic_Bag_Handle(massage_config, TOP_BAG, double_flag, lvl))
            {
                rap_config->rap_knead_cyclic_status = LEFT_BAG;
            }
            break;
        case LEFT_BAG:
            if (!_Snf_Rap_Cyclic_Bag_Handle(massage_config, LEFT_BAG, double_flag, lvl))
            {
                rap_config->rap_knead_cyclic_status = RIGHT_BAG;
            }
            break;
        case RIGHT_BAG:
            if (!_Snf_Rap_Cyclic_Bag_Handle(massage_config, RIGHT_BAG, double_flag, lvl))
            {
                return false;
            }
            break;
        default:
            MASSAGE_PRINTF("rap knead invalid cyclic status %d, stop\r\n", rap_config->rap_knead_cyclic_status);
            return false;
    }
    return true;
}

/**
 * @brief  叩击充气阶段控制函数。控制腰部支撑气袋按指定时序充气，为后续循环叩击做准备。
 * @param  massage_config - 按摩配置结构体指针
 * @param  support_inflate_time - 支撑气袋预充气目标时间(tick)
 * @return bool - 充气进行中返回true，充气完成返回false
 */
static bool _Snf_Rap_Knead_Inflate(massage_config_t* massage_config, uint16 support_inflate_time)
{
    massage_rap_config_t* rap_config = massage_config->massage_rap_config;

    if (!massage_config->support_flag)
    {
        return false;
    }
    if (rap_config->rap_inflate_time < support_inflate_time)
    {
        Snf_Massage_Support_Valve_Control(massage_config->support_channel, massage_config->support_channel_r,
                                          MASSAGE_SUPPORT_ACTION_INFLATE);

        rap_config->rap_inflate_time++;
        return true;
    }

    rap_config->rap_inflate_time = 0;
    return false;
}

/**
 * @brief  叩击循环阶段控制函数。按顺时针或逆时针方向依次控制上、左、右气袋进行循环叩击。
 * @param  massage_config - 按摩配置结构体指针
 * @param  double_flag - 是否以双气袋工作
 * @param  lvl - 按摩强度等级
 * @return bool - 循环进行中返回true，循环完成返回false
 */
static bool _Snf_Rap_Knead_Cyclic(massage_config_t* massage_config, bool double_flag, uint8 lvl)
{
    Snf_Massage_Support_Valve_Control(massage_config->support_channel, massage_config->support_channel_r,
                                      MASSAGE_SUPPORT_ACTION_HOLD);

    if (massage_config->clockwise == CLOCKWISE)
    {
        return _Snf_Rap_Knead_Cyclic_Clockwise_Air_Bag_Control(massage_config, double_flag, lvl);
    }
    else
    {
        return _Snf_Rap_Knead_Cyclic_Anticlockwise_Air_Bag_Control(massage_config, double_flag, lvl);
    }
}

/**
 * @brief  揉捏叩击模式放气阶段控制函数。将所有按摩气袋（上、左、右）放气，并将腰部支撑气袋设置为支撑状态。
 * @param  massage_config - 按摩配置结构体指针
 * @param  rap_deflate_time - 支撑气袋泄气目标时间(tick)
 * @return None
 */
static void _Snf_Rap_Knead_Deflate(massage_config_t* massage_config, uint16 rap_deflate_time)
{
    massage_rap_config_t* rap_config = massage_config->massage_rap_config;

    MASSAGE_VALVE_DEFLATE(massage_config->top_channel);
    MASSAGE_VALVE_DEFLATE(massage_config->right_channel);
    MASSAGE_VALVE_DEFLATE(massage_config->left_channel);
    Snf_Massage_Support_Valve_Control(massage_config->support_channel, massage_config->support_channel_r,
                                      MASSAGE_SUPPORT_ACTION_DEFLATE);

    if (massage_config->support_flag)
    {
        if (rap_config->rap_deflate_time < rap_deflate_time)
        {
            rap_config->rap_deflate_time++;
        }
        else
        {
            massage_config->work_flag    = false;
            rap_config->rap_deflate_time = 0;
        }
    }
    else
    {
        massage_config->work_flag = false;
    }
}

/********************************************************************************
************************* Shoulder Bag Rap **************************************
********************************************************************************/
/**
 * @brief  肩部叩击模式时间计算函数。根据双侧/单侧标志和按摩强度等级查参数表，计算肩部叩击输出总时间。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
static void _Snf_Shoulder_Rap_TimeCalc(massage_config_t* massage_config)
{
    uint32_t calc_time = 0;
    uint8    lvl       = massage_config->massage_lvl;

    if ((lvl < (uint8)MASSAGE_INTENSITY_LOW) || (lvl > (uint8)MASSAGE_INTENSITY_HIGH))
    {
        MASSAGE_PRINTF("shoulder rap invalid lvl %d\r\n", lvl);
    }
    else
    {
        const rap_shoulder_time_param_t* param = &rap_shoulder_time_param_table[massage_config->double_flag ? 1 : 0][lvl];
        calc_time =
            param->pre_inflate_time + (param->action_inflate_time + param->action_deflate_time) * massage_config->massage_times;
    }

    massage_config->massage_output_time = MASSAGE_OUTPUT_TIME_CONVERT(calc_time);
}

/**
 * @brief  肩部叩击循环阶段控制函数。先进行预充气，然后按指定时序控制肩部气囊进行充放气循环，实现肩部叩击效果。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - 循环进行中返回true，循环完成返回false
 */
static bool _Snf_Shoulder_Rap_Cyclic(massage_config_t* massage_config)
{
    massage_rap_config_t*     rap_config = massage_config->massage_rap_config;
    uint8                     lvl        = massage_config->massage_lvl;
    rap_shoulder_time_param_t time_param = { 0, 0, 0 };

    if ((lvl >= (uint8)MASSAGE_INTENSITY_LOW) && (lvl <= (uint8)MASSAGE_INTENSITY_HIGH))
    {
        time_param = rap_shoulder_time_param_table[massage_config->double_flag ? 1 : 0][lvl];
    }

    //循环前的充气时间
    if (rap_config->rap_shoulder_pre_time < MASSAGE_TIME_MS(time_param.pre_inflate_time))
    {
        MASSAGE_VALVE_INFLATE(massage_config->single_channel);
        rap_config->rap_shoulder_pre_time++;
        return true;
    }

    //循环次数
    if (rap_config->rap_shoulder_cyclic_count < massage_config->massage_times)
    {
        if (rap_config->rap_shoulder_cyclic_time < MASSAGE_TIME_MS(time_param.action_deflate_time))
        {
            MASSAGE_VALVE_DEFLATE(massage_config->single_channel);
            rap_config->rap_shoulder_cyclic_time++;
        }
        //NOTE: 此处与 _Snf_Rap_Cyclic_Bag_Control 不一致，疑似漏加 deflate 时间，暂保持原时序，待确认
        else if (rap_config->rap_shoulder_cyclic_time < MASSAGE_TIME_MS(time_param.action_inflate_time))
        {
            MASSAGE_VALVE_INFLATE(massage_config->single_channel);
            rap_config->rap_shoulder_cyclic_time++;
        }
        else
        {
            MASSAGE_VALVE_DEFLATE(massage_config->single_channel);
            rap_config->rap_shoulder_cyclic_time = 0;
            rap_config->rap_shoulder_cyclic_count++;
        }
        return true;
    }
    return false;
}

/**
 * @brief  肩部叩击结束阶段控制函数。将肩部气囊放气，结束肩部叩击模式。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
static void _Snf_Shoulder_Rap_End(massage_config_t* massage_config)
{
    MASSAGE_VALVE_DEFLATE(massage_config->single_channel);

    massage_config->work_flag = false;
}

/************************ Public Function Implementations ************************/

/**
 * @brief  获取揉捏气袋叩击时间参数表项。按支撑标志、双/单气袋标志和按摩强度等级索引参数表。
 * @param  support_flag - 支撑气袋是否充气（1对应区域7/8，0对应区域5/6）
 * @param  double_flag - 是否以双气袋工作
 * @param  lvl - 按摩强度等级（MASSAGE_INTENSITY_LOW/MASSAGE_INTENSITY_HIGH）
 * @return rap_knead_time_param_t* - 参数表项指针，强度等级非法时返回NULL
 */
const rap_knead_time_param_t* Snf_Massage_Rap_Get_Knead_Param(bool support_flag, bool double_flag, uint8 lvl)
{
    if ((lvl < (uint8)MASSAGE_INTENSITY_LOW) || (lvl > (uint8)MASSAGE_INTENSITY_HIGH))
    {
        return NULL;
    }

    return &rap_knead_time_param_table[support_flag ? 1 : 0][double_flag ? 1 : 0][lvl];
}

/**
 * @brief  叩击状态初始化。清零叩击配置结构体的全部状态和计时字段，防止打断后重启残留。
 * @note   RAP_KNEAD_INFLATE_STATUS、TOP_BAG、RAP_SHOD_CYCLIC_STATUS 枚举初值恰好为0，整体清零即可。
 * @param  massage_rap_config_l - 叩击配置结构体指针
 * @return None
 */
void Snf_Massage_Rap_Init(massage_rap_config_t* massage_rap_config_l)
{
    (void)memset(massage_rap_config_l, 0, sizeof(*massage_rap_config_l));
}
/**
 * @brief  揉捏叩击模式主处理函数。根据双侧/单侧标志和按摩强度等级查参数表，管理叩击模式的三个状态：充气状态、循环状态和放气状态。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
void Snf_Massage_Rap_Knead(massage_config_t* massage_config)
{
    massage_rap_config_t*         rap_config = massage_config->massage_rap_config;
    const rap_knead_time_param_t* param;

    if (massage_config->massage_lvl == MASSAGE_INTENSITY_IDLE || massage_config->massage_times == 0)
    {
        massage_config->massage_output_time = 0;
        return;
    }

    _Snf_Massage_Rap_Knead_TimeCalc(massage_config);

    param =
        Snf_Massage_Rap_Get_Knead_Param(massage_config->support_flag, massage_config->double_flag, massage_config->massage_lvl);
    if (param == NULL)
    {
        //非法强度等级，TimeCalc中已记录日志，本次不做任何动作
        return;
    }

    switch (rap_config->rap_knead_status)
    {
        case RAP_KNEAD_INFLATE_STATUS:
            if (!_Snf_Rap_Knead_Inflate(massage_config, MASSAGE_TIME_MS(param->support_inflate_time)))
            {
                rap_config->rap_knead_status = RAP_KNEAD_CYCLIC_STATUS;
            }
            break;
        case RAP_KNEAD_CYCLIC_STATUS:
            if (!_Snf_Rap_Knead_Cyclic(massage_config, massage_config->double_flag, massage_config->massage_lvl))
            {
                rap_config->rap_knead_status = RAP_KNEAD_DEFLATE_STATUS;
            }
            break;
        case RAP_KNEAD_DEFLATE_STATUS:
            _Snf_Rap_Knead_Deflate(massage_config,
                                   MASSAGE_TIME_MS(MASSAGE_SUPPORT_VALVE_SELECT(RAP_KEEP_SUPPORT_AIR_7_8_DEFLATE_TIME,
                                                                                RAP_DEFLATE_SUPPORT_AIR_7_8_DEFLATE_TIME)));
            break;
        default:
            MASSAGE_PRINTF("rap knead invalid status %d, stop\r\n", rap_config->rap_knead_status);
            rap_config->rap_knead_status = RAP_KNEAD_DEFLATE_STATUS;
            massage_config->work_flag    = false;
            break;
    }
}

/**
 * @brief  肩部叩击模式主处理函数。管理肩部叩击的循环状态和结束状态，实现肩部气囊的叩击效果。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
void Snf_Massage_Shoulder_Rap(massage_config_t* massage_config)
{
    massage_rap_config_t* rap_config = massage_config->massage_rap_config;

    if (massage_config->massage_lvl == MASSAGE_INTENSITY_IDLE || massage_config->massage_times == 0)
    {
        massage_config->massage_output_time = 0;
        return;
    }

    _Snf_Shoulder_Rap_TimeCalc(massage_config);

    switch (rap_config->rap_shoulder_status)
    {
        case RAP_SHOD_CYCLIC_STATUS:
            if (!_Snf_Shoulder_Rap_Cyclic(massage_config))
            {
                rap_config->rap_shoulder_status = RAP_SHOD_END_STATUS;
            }
            break;
        case RAP_SHOD_END_STATUS:
            _Snf_Shoulder_Rap_End(massage_config);
            break;
        default:
            MASSAGE_PRINTF("shoulder rap invalid status %d, stop\r\n", rap_config->rap_shoulder_status);
            rap_config->rap_shoulder_status = RAP_SHOD_END_STATUS;
            massage_config->work_flag       = false;
            break;
    }
}
