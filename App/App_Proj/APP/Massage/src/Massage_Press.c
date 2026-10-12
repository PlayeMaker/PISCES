/************************ Include Files ************************/
#include "Basic_Config.h"
#include "Massage_Press.h"
#include <stdint.h>
#include <string.h>
#include "Valve_Types.h"
#include "Rte_Swc.h"
/************************ Macro Definitions ************************/
#define ALL_INFLATE(top_channel, right_channel, left_channel) \
    MASSAGE_VALVE_INFLATE(top_channel);                       \
    MASSAGE_VALVE_INFLATE(right_channel);                     \
    MASSAGE_VALVE_INFLATE(left_channel)

#define ALL_DEFLATE(top_channel, right_channel, left_channel) \
    MASSAGE_VALVE_DEFLATE(top_channel);                       \
    MASSAGE_VALVE_DEFLATE(right_channel);                     \
    MASSAGE_VALVE_DEFLATE(left_channel)
/************************ Private Global Variables ************************/
/* 三点按压时间参数表：[支撑标志][双侧标志][强度]，强度维度按枚举值索引（MASSAGE_INTENSITY_LOW/HIGH），IDLE(0)行空置 */
static const press_3_point_time_t press_3_point_time_table[2][2][3] =
{
    /* 区域5/6：无腰部支撑气袋，支撑预充时间和重叠时间无效置0 */
    [0] =
        {
            [0] =
                {
                    [MASSAGE_INTENSITY_LOW]  = {0, PRESS_3_POINT_MASSAGE_AIR_SINGLE_5_6_INTENSITY_LOW_INFLATE_TIME, 0,
                                                PRESS_3_POINT_MASSAGE_AIR_SINGLE_5_6_INTENSITY_LOW_DEFLATE_TIME},
                    [MASSAGE_INTENSITY_HIGH] = {0, PRESS_3_POINT_MASSAGE_AIR_SINGLE_5_6_INTENSITY_HIGH_INFLATE_TIME, 0,
                                                PRESS_3_POINT_MASSAGE_AIR_SINGLE_5_6_INTENSITY_HIGH_DEFLATE_TIME},
                },
            [1] =
                {
                    [MASSAGE_INTENSITY_LOW]  = {0, PRESS_3_POINT_MASSAGE_AIR_DOUBLE_5_6_INTENSITY_LOW_INFLATE_TIME, 0,
                                                PRESS_3_POINT_MASSAGE_AIR_DOUBLE_5_6_INTENSITY_LOW_DEFLATE_TIME},
                    [MASSAGE_INTENSITY_HIGH] = {0, PRESS_3_POINT_MASSAGE_AIR_DOUBLE_5_6_INTENSITY_HIGH_INFLATE_TIME, 0,
                                                PRESS_3_POINT_MASSAGE_AIR_DOUBLE_5_6_INTENSITY_HIGH_DEFLATE_TIME},
                },
        },
    /* 区域7/8：有腰部支撑气袋，先支撑气袋预充气，再主按摩气袋充气 */
    [1] =
        {
            [0] =
                {
                    [MASSAGE_INTENSITY_LOW]  = {PRESS_SUPPORT_3_POINT_MASSAGE_AIR_SINGLE_7_8_INTENSITY_LOW_INFLATE_TIME,
                                                PRESS_3_POINT_MASSAGE_AIR_SINGLE_7_8_INTENSITY_LOW_INFLATE_TIME,
                                                PRESS_SUPPORT_3_POINT_MASSAGE_AIR_SINGLE_7_8_INTENSITY_LOW_OVERLAP_TIME,
                                                PRESS_3_POINT_MASSAGE_AIR_SINGLE_7_8_INTENSITY_LOW_DEFLATE_TIME},
                    [MASSAGE_INTENSITY_HIGH] = {PRESS_SUPPORT_3_POINT_MASSAGE_AIR_SINGLE_7_8_INTENSITY_HIGH_INFLATE_TIME,
                                                PRESS_3_POINT_MASSAGE_AIR_SINGLE_7_8_INTENSITY_HIGH_INFLATE_TIME,
                                                PRESS_SUPPORT_3_POINT_MASSAGE_AIR_SINGLE_7_8_INTENSITY_HIGH_OVERLAP_TIME,
                                                PRESS_3_POINT_MASSAGE_AIR_SINGLE_7_8_INTENSITY_HIGH_DEFLATE_TIME},
                },
            [1] =
                {
                    [MASSAGE_INTENSITY_LOW]  = {PRESS_SUPPORT_3_POINT_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_LOW_INFLATE_TIME,
                                                PRESS_3_POINT_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_LOW_INFLATE_TIME,
                                                PRESS_SUPPORT_3_POINT_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_LOW_OVERLAP_TIME,
                                                PRESS_3_POINT_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_LOW_DEFLATE_TIME},
                    [MASSAGE_INTENSITY_HIGH] = {PRESS_SUPPORT_3_POINT_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_HIGH_INFLATE_TIME,
                                                PRESS_3_POINT_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_HIGH_INFLATE_TIME,
                                                PRESS_SUPPORT_3_POINT_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_HIGH_OVERLAP_TIME,
                                                PRESS_3_POINT_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_HIGH_DEFLATE_TIME},
                },
        },
};

/* 单点按压时间参数表（单位ms）：[双侧标志][强度]，强度维度按枚举值索引（MASSAGE_INTENSITY_LOW/HIGH），IDLE(0)行空置 */
static const press_1_point_time_t press_1_point_time_table[2][3] =
{
    [0] =
        {
            [MASSAGE_INTENSITY_LOW]  = {PRESS_MASSAGE_AIR_SINGLE_5_6_7_8_INTENSITY_LOW_INFLATE_TIME,
                                        PRESS_MASSAGE_AIR_SINGLE_5_6_7_8_INTENSITY_LOW_OVERLAP_TIME,
                                        PRESS_MASSAGE_AIR_SINGLE_5_6_7_8_INTENSITY_LOW_ALL_DEFLATE_TIME},
            [MASSAGE_INTENSITY_HIGH] = {PRESS_MASSAGE_AIR_SINGLE_5_6_7_8_INTENSITY_HIGH_INFLATE_TIME,
                                        PRESS_MASSAGE_AIR_SINGLE_5_6_7_8_INTENSITY_HIGH_OVERLAP_TIME,
                                        PRESS_MASSAGE_AIR_SINGLE_5_6_7_8_INTENSITY_HIGH_ALL_DEFLATE_TIME},
        },
    [1] =
        {
            [MASSAGE_INTENSITY_LOW]  = {PRESS_MASSAGE_AIR_DOUBLE_5_6_7_8_INTENSITY_LOW_INFLATE_TIME,
                                        PRESS_MASSAGE_AIR_DOUBLE_5_6_7_8_INTENSITY_LOW_OVERLAP_TIME,
                                        PRESS_MASSAGE_AIR_DOUBLE_5_6_7_8_INTENSITY_LOW_ALL_DEFLATE_TIME},
            [MASSAGE_INTENSITY_HIGH] = {PRESS_MASSAGE_AIR_DOUBLE_5_6_7_8_INTENSITY_HIGH_INFLATE_TIME,
                                        PRESS_MASSAGE_AIR_DOUBLE_5_6_7_8_INTENSITY_HIGH_OVERLAP_TIME,
                                        PRESS_MASSAGE_AIR_DOUBLE_5_6_7_8_INTENSITY_HIGH_ALL_DEFLATE_TIME},
        },
};

/* 肩部气囊点按时间参数表（单位ms）：[双侧标志][强度]，强度维度按枚举值索引（MASSAGE_INTENSITY_LOW/HIGH），IDLE(0)行空置 */
static const press_shoulder_time_t press_shoulder_time_table[2][3] =
{
    [0] =
        {
            [MASSAGE_INTENSITY_LOW]  = {PRESS_MASSAGE_AIR_SINGLE_9_10_INTENSITY_LOW_INFLATE_TIME,
                                        PRESS_MASSAGE_AIR_SINGLE_9_10_INTENSITY_LOW_DEFLATE_TIME},
            [MASSAGE_INTENSITY_HIGH] = {PRESS_MASSAGE_AIR_SINGLE_9_10_INTENSITY_HIGH_INFLATE_TIME,
                                        PRESS_MASSAGE_AIR_SINGLE_9_10_INTENSITY_HIGH_DEFLATE_TIME},
        },
    [1] =
        {
            [MASSAGE_INTENSITY_LOW]  = {PRESS_MASSAGE_AIR_DOUBLE_9_10_INTENSITY_LOW_INFLATE_TIME,
                                        PRESS_MASSAGE_AIR_DOUBLE_9_10_INTENSITY_LOW_DEFLATE_TIME},
            [MASSAGE_INTENSITY_HIGH] = {PRESS_MASSAGE_AIR_DOUBLE_9_10_INTENSITY_HIGH_INFLATE_TIME,
                                        PRESS_MASSAGE_AIR_DOUBLE_9_10_INTENSITY_HIGH_DEFLATE_TIME},
        },
};
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void Snf_Massage_3_Point_Press_TimeCalc(massage_config_t* massage_config);
static void Snf_Knead_Bag_Cyclic_Press_TimeCalc(massage_config_t* massage_config);
static void Snf_Massage_Shoulder_Bag_Point_Press_TimeCalc(massage_config_t* massage_config);
static void _Snf_Press_3_Point_Support_Air_Bag_Control(massage_config_t* massage_config, uint16 press_poll_support_target_time,
                                                       uint16 press_poll_massage_target_time,
                                                       uint16 press_poll_massage_overlap_time,
                                                       uint16 press_poll_deflate_target_time);
static void _Snf_Press_3_Point_Unsupport_Air_Bag_Control(massage_config_t* massage_config,
                                                         uint16            press_poll_massage_target_time,
                                                         uint16            press_poll_deflate_target_time);
static void _Snf_Press_3_Point_Control(massage_config_t* massage_config);
static void _Snf_Press_1_Point_Air_Bag_Control(massage_config_t* massage_config, uint16 press_target_time,
                                               uint16 press_overlap_time, uint16 press_all_deflate_time);
static void _Snf_Press_1_Point_Control(massage_config_t* massage_config);
/************************ Private Function Implementations ************************/
/********************************************************************************
************************* Knead Bag Point Press *********************************
********************************************************************************/

/**
 * @brief  三点按压模式时间计算函数。根据腰部支撑标志、双侧/单侧标志和按摩强度等级，从参数表取时间参数计算三点按压输出总时间。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
static void Snf_Massage_3_Point_Press_TimeCalc(massage_config_t* massage_config)
{
    uint32_t calc_time = 0;
    uint8    lvl       = massage_config->massage_lvl;

    if ((lvl >= (uint8)MASSAGE_INTENSITY_LOW) && (lvl <= (uint8)MASSAGE_INTENSITY_HIGH))
    {
        const press_3_point_time_t* time_param =
            &press_3_point_time_table[massage_config->support_flag ? 1 : 0][massage_config->double_flag ? 1 : 0][lvl];

        if (massage_config->support_flag)
        {
            calc_time = ((uint32_t)time_param->support_inflate_time + (uint32_t)time_param->massage_inflate_time +
                         (uint32_t)time_param->deflate_time) *
                        massage_config->massage_times;
        }
        else
        {
            calc_time = ((uint32_t)time_param->massage_inflate_time + (uint32_t)time_param->deflate_time) *
                        massage_config->massage_times;
        }
    }
    else
    {
        /* 强度无效，输出时间为0 */
        MASSAGE_PRINTF("3 point press massage_lvl invalid: %d\r\n", massage_config->massage_lvl);
    }

    massage_config->massage_output_time = MASSAGE_OUTPUT_TIME_CONVERT(calc_time);
}

/**
 * @brief  揉捏气袋循环点按模式时间计算函数。根据双侧/单侧标志和按摩强度等级，从参数表取时间参数计算循环点按输出总时间。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
static void Snf_Knead_Bag_Cyclic_Press_TimeCalc(massage_config_t* massage_config)
{
    uint32_t calc_time = 0;
    uint8    lvl;

    if (massage_config->massage_times == 0)
    {
        return;
    }

    lvl = massage_config->massage_lvl;
    if ((lvl >= (uint8)MASSAGE_INTENSITY_LOW) && (lvl <= (uint8)MASSAGE_INTENSITY_HIGH))
    {
        const press_1_point_time_t* time_param = &press_1_point_time_table[massage_config->double_flag ? 1 : 0][lvl];

        calc_time = ((uint32_t)time_param->inflate_time * 3 - (uint32_t)time_param->overlap_time * 2 +
                     (uint32_t)time_param->all_deflate_time) *
                    massage_config->massage_times;
    }
    else
    {
        /* 强度无效，输出时间为0 */
        MASSAGE_PRINTF("1 point press massage_lvl invalid: %d\r\n", massage_config->massage_lvl);
    }

    massage_config->massage_output_time = MASSAGE_OUTPUT_TIME_CONVERT(calc_time);
}

/**
 * @brief  三点按压模式带腰部支撑的气袋控制函数。先对腰部支撑气袋充气保持指定时间，然后同时对主按摩气袋（上、左、右）进行充气，完成后全部放气，循环直到达到指定次数。
 * @param  massage_config - 按摩配置结构体指针
 * @param  press_poll_support_target_time - 腰部支撑气袋充气目标时间
 * @param  press_poll_massage_target_time - 主按摩气袋充气目标时间
 * @param  press_poll_massage_overlap_time - 主按摩气袋充气重叠时间
 * @param  press_poll_deflate_target_time - 主按摩气袋放气目标时间
 * @return None
 */
static void _Snf_Press_3_Point_Support_Air_Bag_Control(massage_config_t* massage_config, uint16 press_poll_support_target_time,
                                                       uint16 press_poll_massage_target_time,
                                                       uint16 press_poll_massage_overlap_time,
                                                       uint16 press_poll_deflate_target_time)
{
    massage_press_config_t* press_cfg = massage_config->massage_press_config;

    if (press_cfg->press_count < massage_config->massage_times)
    {
        if (press_cfg->press_poll_inflate_time < (press_poll_support_target_time + press_poll_massage_target_time))
        {
            if (press_cfg->press_poll_inflate_time < press_poll_support_target_time)
            {
                Snf_Massage_Support_Valve_Control(massage_config->support_channel, massage_config->support_channel_r,
                                                  MASSAGE_SUPPORT_ACTION_INFLATE);
                press_cfg->press_poll_inflate_time++;
            }
            else if (press_cfg->press_poll_inflate_time < (press_poll_support_target_time + press_poll_massage_overlap_time))
            {
                Snf_Massage_Support_Valve_Control(massage_config->support_channel, massage_config->support_channel_r,
                                                  MASSAGE_SUPPORT_ACTION_INFLATE);
                ALL_INFLATE(massage_config->top_channel, massage_config->right_channel, massage_config->left_channel);
                press_cfg->press_poll_inflate_time++;
            }
            else
            {
                Snf_Massage_Support_Valve_Control(massage_config->support_channel, massage_config->support_channel_r,
                                                  MASSAGE_SUPPORT_ACTION_HOLD);
                ALL_INFLATE(massage_config->top_channel, massage_config->right_channel, massage_config->left_channel);
                press_cfg->press_poll_inflate_time++;
            }
        }
        else if (press_cfg->press_poll_deflate_time < press_poll_deflate_target_time)
        {
            ALL_DEFLATE(massage_config->top_channel, massage_config->right_channel, massage_config->left_channel);
            Snf_Massage_Support_Valve_Control(massage_config->support_channel, massage_config->support_channel_r,
                                              MASSAGE_SUPPORT_ACTION_DEFLATE);
            press_cfg->press_poll_deflate_time++;
        }
        else
        {
            ALL_DEFLATE(massage_config->top_channel, massage_config->right_channel, massage_config->left_channel);
            Snf_Massage_Support_Valve_Control(massage_config->support_channel, massage_config->support_channel_r,
                                              MASSAGE_SUPPORT_ACTION_DEFLATE);
            press_cfg->press_poll_inflate_time = 0;
            press_cfg->press_poll_deflate_time = 0;
            press_cfg->press_count++;
        }
    }
}

/**
 * @brief  三点按压模式不带腰部支撑的气袋控制函数。直接对主按摩气袋（上、左、右）同时充气，完成后全部放气，循环直到达到指定次数。
 * @param  massage_config - 按摩配置结构体指针
 * @param  press_poll_massage_target_time - 主按摩气袋充气目标时间
 * @param  press_poll_deflate_target_time - 主按摩气袋放气目标时间
 * @return None
 */
static void _Snf_Press_3_Point_Unsupport_Air_Bag_Control(massage_config_t* massage_config,
                                                         uint16            press_poll_massage_target_time,
                                                         uint16            press_poll_deflate_target_time)
{
    massage_press_config_t* press_cfg = massage_config->massage_press_config;

    if (press_cfg->press_count < massage_config->massage_times)
    {
        if (press_cfg->press_poll_inflate_time < press_poll_massage_target_time)
        {
            ALL_INFLATE(massage_config->top_channel, massage_config->right_channel, massage_config->left_channel);
            press_cfg->press_poll_inflate_time++;
        }
        else if (press_cfg->press_poll_deflate_time < press_poll_deflate_target_time)
        {
            ALL_DEFLATE(massage_config->top_channel, massage_config->right_channel, massage_config->left_channel);
            Snf_Massage_Support_Valve_Control(massage_config->support_channel, massage_config->support_channel_r,
                                              MASSAGE_SUPPORT_ACTION_DEFLATE);
            press_cfg->press_poll_deflate_time++;
        }
        else
        {
            ALL_DEFLATE(massage_config->top_channel, massage_config->right_channel, massage_config->left_channel);
            Snf_Massage_Support_Valve_Control(massage_config->support_channel, massage_config->support_channel_r,
                                              MASSAGE_SUPPORT_ACTION_DEFLATE);
            press_cfg->press_poll_inflate_time = 0;
            press_cfg->press_poll_deflate_time = 0;
            press_cfg->press_count++;
        }
    }
}

/**
 * @brief  三点按压模式分发函数。根据腰部支撑标志、双侧/单侧标志和按摩强度等级，从参数表取时间参数并调用对应的气袋控制函数。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
static void _Snf_Press_3_Point_Control(massage_config_t* massage_config)
{
    massage_press_config_t*     press_cfg = massage_config->massage_press_config;
    const press_3_point_time_t* time_param;
    uint8                       lvl;

    if (press_cfg->press_count < massage_config->massage_times)
    {
        lvl = massage_config->massage_lvl;
        if ((lvl < (uint8)MASSAGE_INTENSITY_LOW) || (lvl > (uint8)MASSAGE_INTENSITY_HIGH))
        {
            /* 强度无效，不动作，TimeCalc中已记录日志 */
            return;
        }

        time_param = &press_3_point_time_table[massage_config->support_flag ? 1 : 0][massage_config->double_flag ? 1 : 0][lvl];

        if (massage_config->support_flag)
        {
            _Snf_Press_3_Point_Support_Air_Bag_Control(massage_config, MASSAGE_TIME_MS(time_param->support_inflate_time),
                                                       MASSAGE_TIME_MS(time_param->massage_inflate_time),
                                                       MASSAGE_TIME_MS(time_param->overlap_time),
                                                       MASSAGE_TIME_MS(time_param->deflate_time));
        }
        else
        {
            _Snf_Press_3_Point_Unsupport_Air_Bag_Control(massage_config, MASSAGE_TIME_MS(time_param->massage_inflate_time),
                                                         MASSAGE_TIME_MS(time_param->deflate_time));
        }
    }
    else
    {
        massage_config->work_flag = false;
    }
}

/**
 * @brief  单点按压模式气袋控制函数。按照 上→第二气袋→第三气袋 的顺序依次对点按气袋进行充气，
 *         相邻气袋之间有重叠时间，实现平滑过渡的点按效果；方向只影响气袋动作顺序：
 *         顺时针为 上→右→左，逆时针为 上→左→右。
 * @param  massage_config - 按摩配置结构体指针
 * @param  press_target_time - 单个气袋的点按目标时间
 * @param  press_overlap_time - 相邻气袋点按的重叠时间
 * @param  press_all_deflate_time - 所有气袋放气时间
 * @return None
 */
static void _Snf_Press_1_Point_Air_Bag_Control(massage_config_t* massage_config, uint16 press_target_time,
                                               uint16 press_overlap_time, uint16 press_all_deflate_time)
{
    massage_press_config_t* press_cfg = massage_config->massage_press_config;
    uint8                   second_channel;      // 第二个点按气袋通道
    uint8                   third_channel;       // 第三个点按气袋通道
    uint16*                 second_time;         // 第二个气袋点按计时
    uint16*                 third_time;          // 第三个气袋点按计时
    uint8*                  second_action_flag;  // 第二个气袋动作标志
    uint8*                  third_action_flag;   // 第三个气袋动作标志

    /* 方向只影响气袋动作顺序：顺时针 上→右→左，逆时针 上→左→右 */
    if (massage_config->clockwise == CLOCKWISE)
    {
        second_channel     = massage_config->right_channel;
        second_time        = &press_cfg->press_right_time;
        second_action_flag = &press_cfg->press_right_action_flag;
        third_channel      = massage_config->left_channel;
        third_time         = &press_cfg->press_left_time;
        third_action_flag  = &press_cfg->press_left_action_flag;
    }
    else
    {
        second_channel     = massage_config->left_channel;
        second_time        = &press_cfg->press_left_time;
        second_action_flag = &press_cfg->press_left_action_flag;
        third_channel      = massage_config->right_channel;
        third_time         = &press_cfg->press_right_time;
        third_action_flag  = &press_cfg->press_right_action_flag;
    }

    if (press_cfg->press_count < massage_config->massage_times)
    {
        //头点按
        if (press_cfg->press_top_time < press_target_time)
        {
            if (press_cfg->press_top_time >= (press_target_time - press_overlap_time))
            {
                *second_action_flag = ACTION;
            }
            MASSAGE_VALVE_INFLATE(massage_config->top_channel);
            press_cfg->press_top_time++;
        }
        else
        {
            MASSAGE_VALVE_DEFLATE(massage_config->top_channel);
        }

        //第二气袋点按
        if (*second_action_flag == ACTION)
        {
            if (*second_time < press_target_time)
            {
                if (*second_time >= (press_target_time - press_overlap_time))
                {
                    *third_action_flag = ACTION;
                }
                MASSAGE_VALVE_INFLATE(second_channel);
                (*second_time)++;
            }
            else
            {
                *second_action_flag = COMPLETE_ACTION;
                MASSAGE_VALVE_DEFLATE(second_channel);
            }
        }

        //第三气袋点按
        if (*third_action_flag == ACTION)
        {
            if (*third_time < press_target_time)
            {
                MASSAGE_VALVE_INFLATE(third_channel);
                (*third_time)++;
            }
            else
            {
                *third_action_flag = COMPLETE_ACTION;
                MASSAGE_VALVE_DEFLATE(third_channel);
            }
        }

        //全部点按完成
        if (*third_action_flag == COMPLETE_ACTION)
        {
            if (press_cfg->press_all_deflate_time < press_all_deflate_time)
            {
                MASSAGE_VALVE_DEFLATE(massage_config->top_channel);
                MASSAGE_VALVE_DEFLATE(massage_config->right_channel);
                MASSAGE_VALVE_DEFLATE(massage_config->left_channel);
                press_cfg->press_all_deflate_time++;
            }
            else
            {
                press_cfg->press_top_time          = 0;
                press_cfg->press_left_time         = 0;
                press_cfg->press_right_time        = 0;
                press_cfg->press_all_deflate_time  = 0;
                press_cfg->press_right_action_flag = NO_ACTION;
                press_cfg->press_left_action_flag  = NO_ACTION;
                press_cfg->press_count++;
            }
        }
    }
    else
    {
        massage_config->work_flag = false;
    }
}

/**
 * @brief  单点按压模式分发函数。根据双侧/单侧标志和按摩强度等级，从参数表取时间参数并调用统一的气袋控制函数（方向在控制函数内处理）。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
static void _Snf_Press_1_Point_Control(massage_config_t* massage_config)
{
    const press_1_point_time_t* time_param;
    uint8                       lvl = massage_config->massage_lvl;

    if ((lvl < (uint8)MASSAGE_INTENSITY_LOW) || (lvl > (uint8)MASSAGE_INTENSITY_HIGH))
    {
        /* 强度无效，不动作，TimeCalc中已记录日志 */
        return;
    }

    time_param = &press_1_point_time_table[massage_config->double_flag ? 1 : 0][lvl];

    _Snf_Press_1_Point_Air_Bag_Control(massage_config, MASSAGE_TIME_MS(time_param->inflate_time),
                                       MASSAGE_TIME_MS(time_param->overlap_time),
                                       MASSAGE_TIME_MS(time_param->all_deflate_time));
}

/********************************************************************************
************************* Shoulder Bag Point Press ******************************
********************************************************************************/

/**
 * @brief  肩部气囊点按模式时间计算函数。根据双侧/单侧标志和按摩强度等级，从参数表取时间参数计算肩部气囊点按输出总时间。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
static void Snf_Massage_Shoulder_Bag_Point_Press_TimeCalc(massage_config_t* massage_config)
{
    uint32_t calc_time = 0;
    uint8    lvl       = massage_config->massage_lvl;

    if ((lvl >= (uint8)MASSAGE_INTENSITY_LOW) && (lvl <= (uint8)MASSAGE_INTENSITY_HIGH))
    {
        const press_shoulder_time_t* time_param = &press_shoulder_time_table[massage_config->double_flag ? 1 : 0][lvl];

        calc_time = ((uint32_t)time_param->inflate_time + (uint32_t)time_param->deflate_time) * massage_config->massage_times;
    }
    else
    {
        /* 强度无效，输出时间为0 */
        MASSAGE_PRINTF("shoulder press massage_lvl invalid: %d\r\n", massage_config->massage_lvl);
    }

    massage_config->massage_output_time = MASSAGE_OUTPUT_TIME_CONVERT(calc_time);
}

/************************ Public Function Implementations ************************/

/**
 * @brief  按压模式初始化函数。将按压配置结构体中的所有计时器和标志位清零，确保按压模式开始时处于初始状态。
 * @param  massage_press_config_l - 按压配置结构体指针
 * @return None
 */
void Snf_Massage_Press_Init(massage_press_config_t* massage_press_config_l)
{
    /* 全部字段初值均为0（NO_ACTION == 0），整体清零即可 */
    memset(massage_press_config_l, 0, sizeof(*massage_press_config_l));
}

/**
 * @brief  三点按压模式主处理函数。先计算输出总时间，再调用三点按压分发函数执行气袋控制。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
void Snf_Massage_3_Point_Press_Handle(massage_config_t* massage_config)
{
    if (massage_config->massage_lvl == MASSAGE_INTENSITY_IDLE || massage_config->massage_times == 0)
    {
        massage_config->massage_times = 0;
        return;
    }

    Snf_Massage_3_Point_Press_TimeCalc(massage_config);

    _Snf_Press_3_Point_Control(massage_config);
}

/**
 * @brief  单点按压模式主处理函数。先计算输出总时间，再调用单点按压分发函数执行气袋控制。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
void Snf_Massage_1_Point_Press_Handle(massage_config_t* massage_config)
{
    if (massage_config->massage_lvl == MASSAGE_INTENSITY_IDLE || massage_config->massage_times == 0)
    {
        massage_config->massage_times = 0;
        return;
    }

    Snf_Knead_Bag_Cyclic_Press_TimeCalc(massage_config);

    _Snf_Press_1_Point_Control(massage_config);
}

/**
 * @brief  肩部气囊点按模式主处理函数。控制肩部气囊按指定时序进行充气和放气，实现肩部点按效果。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
void Snf_Massage_Shoulder_Bag_Point_Press(massage_config_t* massage_config)
{
    massage_press_config_t* press_cfg          = massage_config->massage_press_config;
    uint16_t                point_inflate_time = 0;
    uint16_t                point_deflate_time = 0;
    uint8                   lvl;

    if (massage_config->massage_lvl == MASSAGE_INTENSITY_IDLE || massage_config->massage_times == 0)
    {
        massage_config->massage_times = 0;
        return;
    }

    lvl = massage_config->massage_lvl;
    if ((lvl >= (uint8)MASSAGE_INTENSITY_LOW) && (lvl <= (uint8)MASSAGE_INTENSITY_HIGH))
    {
        const press_shoulder_time_t* time_param = &press_shoulder_time_table[massage_config->double_flag ? 1 : 0][lvl];

        point_inflate_time = time_param->inflate_time;
        point_deflate_time = time_param->deflate_time;
    }

    Snf_Massage_Shoulder_Bag_Point_Press_TimeCalc(massage_config);

    if (press_cfg->press_count < massage_config->massage_times)
    {
        if (press_cfg->press_shoulder_inflate_time < MASSAGE_TIME_MS(point_inflate_time))
        {
            MASSAGE_VALVE_INFLATE(massage_config->single_channel);
            press_cfg->press_shoulder_inflate_time++;
        }
        else if (press_cfg->press_shoulder_deflate_time < MASSAGE_TIME_MS(point_deflate_time))
        {
            MASSAGE_VALVE_DEFLATE(massage_config->single_channel);
            press_cfg->press_shoulder_deflate_time++;
        }
        else
        {
            press_cfg->press_shoulder_inflate_time = 0;
            press_cfg->press_shoulder_deflate_time = 0;
            press_cfg->press_count++;
            MASSAGE_VALVE_DEFLATE(massage_config->single_channel);
        }
    }
    else
    {
        massage_config->work_flag = false;
    }
}
