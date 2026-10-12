/************************ Include Files ************************/
#include <string.h>
#include "Basic_Config.h"
#include "Massage_Knead.h"
#include "Massage.h"
#include "Valve_Types.h"
#include "Rte_Swc.h"
/************************ Macro Definitions ************************/
#define ALL_INFLATE(top_channel, right_channel, left_channel) \
    MASSAGE_VALVE_INFLATE(top_channel);                       \
    MASSAGE_VALVE_INFLATE(right_channel);                     \
    MASSAGE_VALVE_INFLATE(left_channel)

/************************ Private Global Variables ************************/
/* 充气时间参数表：[支撑标志][双侧标志][强度]，强度维度按枚举值索引（MASSAGE_INTENSITY_LOW/HIGH），IDLE(0)行空置 */
static const knead_inflate_time_t knead_inflate_time_table[2][2][3] =
{
    /* 区域5/6：无腰部支撑气袋，只有按摩气袋充气阶段 */
    [0] =
        {
            [0] =
                {
                    [MASSAGE_INTENSITY_LOW]  = { 0, KNEAD_MASSAGE_AIR_SINGLE_5_6_INTENSITY_LOW_INFLATE_TIME },
                    [MASSAGE_INTENSITY_HIGH] = { 0, KNEAD_MASSAGE_AIR_SINGLE_5_6_INTENSITY_HIGH_INFLATE_TIME },
                },
            [1] =
                {
                    [MASSAGE_INTENSITY_LOW]  = { 0, KNEAD_MASSAGE_AIR_DOUBLE_5_6_INTENSITY_LOW_INFLATE_TIME },
                    [MASSAGE_INTENSITY_HIGH] = { 0, KNEAD_MASSAGE_AIR_DOUBLE_5_6_INTENSITY_HIGH_INFLATE_TIME },
                },
        },
    /* 区域7/8：有腰部支撑气袋，先支撑气袋充气，再按摩气袋充气 */
    [1] =
        {
            [0] =
                {
                    [MASSAGE_INTENSITY_LOW]  = { KNEAD_SUPPORT_AIR_SINGLE_7_8_INTENSITY_LOW_INFLATE_TIME,
                                                 KNEAD_MASSAGE_AIR_SINGLE_7_8_INTENSITY_LOW_INFLATE_TIME },
                    [MASSAGE_INTENSITY_HIGH] = { KNEAD_SUPPORT_AIR_SINGLE_7_8_INTENSITY_HIGH_INFLATE_TIME,
                                                 KNEAD_MASSAGE_AIR_SINGLE_7_8_INTENSITY_HIGH_INFLATE_TIME },
                },
            [1] =
                {
                    [MASSAGE_INTENSITY_LOW]  = { KNEAD_SUPPORT_AIR_DOUBLE_7_8_INTENSITY_LOW_INFLATE_TIME,
                                                 KNEAD_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_LOW_INFLATE_TIME },
                    [MASSAGE_INTENSITY_HIGH] = { KNEAD_SUPPORT_AIR_DOUBLE_7_8_INTENSITY_HIGH_INFLATE_TIME,
                                                 KNEAD_MASSAGE_AIR_DOUBLE_7_8_INTENSITY_HIGH_INFLATE_TIME },
                },
        },
};

/* 循环周期时间参数表（单位ms）：[双侧标志][强度]，强度维度按枚举值索引（MASSAGE_INTENSITY_LOW/HIGH），IDLE(0)行空置 */
static const uint16 knead_cyclic_time_table[2][3] =
{
    [0] =
        {
            [MASSAGE_INTENSITY_LOW]  = KNEAD_MASSAGE_AIR_SINGLE_5_6_7_8_INTENSITY_LOW_IACTION_CYCLE_TIME,
            [MASSAGE_INTENSITY_HIGH] = KNEAD_MASSAGE_AIR_SINGLE_5_6_7_8_INTENSITY_HIGH_IACTION_CYCLE_TIME,
        },
    [1] =
        {
            [MASSAGE_INTENSITY_LOW]  = KNEAD_MASSAGE_AIR_DOUBLE_5_6_7_8_INTENSITY_LOW_IACTION_CYCLE_TIME,
            [MASSAGE_INTENSITY_HIGH] = KNEAD_MASSAGE_AIR_DOUBLE_5_6_7_8_INTENSITY_HIGH_IACTION_CYCLE_TIME,
        },
};

/* 循环阶段气袋放气顺序：顺时针 上->右->左，逆时针 上->左->右 */
static const uint8 knead_bag_order_clockwise[KNEAD_BAG_MAX]     = { KNEAD_BAG_TOP, KNEAD_BAG_RIGHT, KNEAD_BAG_LEFT };
static const uint8 knead_bag_order_anticlockwise[KNEAD_BAG_MAX] = { KNEAD_BAG_TOP, KNEAD_BAG_LEFT, KNEAD_BAG_RIGHT };

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static bool _Snf_Knead_Inflate_Support_Air_Bag_Control(massage_config_t* massage_config, uint8 support_channel,
                                                       uint8 support_channel_r, uint8 top_channel, uint8 right_channel,
                                                       uint8 left_channel, uint16 support_inflate_time,
                                                       uint16 massage_inflate_time);
static bool _Snf_Knead_Inflate_Unsupport_Air_Bag_Control(massage_config_t* massage_config, uint8 top_channel,
                                                         uint8 right_channel, uint8 left_channel, uint16 massage_inflate_time);
static bool _Snf_Knead_Inflate(massage_config_t* massage_config);
static bool _Snf_Knead_Cyclic_Air_Bag_Control(massage_config_t* massage_config, uint8 support_channel, uint8 support_channel_r,
                                              uint8 top_channel, uint8 right_channel, uint8 left_channel,
                                              const uint8* bag_deflate_order, uint16 massage_cyclic_time);
static bool _Snf_Knead_Cyclic(massage_config_t* massage_config);
static void _Snf_Knead_Deflate(massage_config_t* massage_config, uint16 knead_deflate_time);
static void _Snf_Knead_TimeCalc(massage_config_t* massage_config);
/************************ Private Function Implementations ************************/

/********************************************************************************
************************* Inflate Status ****************************************
********************************************************************************/

/**
 * @brief  揉捏模式带腰部支撑的充气控制函数。先对腰部支撑气袋充气并保持指定时间，然后同时对主按摩气袋（上、左、右）进行充气。
 * @param  massage_config - 按摩配置结构体指针
 * @param  support_channel - 腰部支撑气袋前阀通道
 * @param  support_channel_r - 腰部支撑气袋后阀通道
 * @param  top_channel - 上气袋通道
 * @param  right_channel - 右气袋通道
 * @param  left_channel - 左气袋通道
 * @param  support_inflate_time - 腰部支撑气袋充气时间
 * @param  massage_inflate_time - 主按摩气袋充气时间
 * @return bool - 充气进行中返回true，充气完成返回false
 * @note   支撑阀操作统一走 Snf_Massage_Support_Valve_Control（C_Massage接口，动作表随阀类型驱动前后阀）
 */
static bool _Snf_Knead_Inflate_Support_Air_Bag_Control(massage_config_t* massage_config, uint8 support_channel,
                                                       uint8 support_channel_r, uint8 top_channel, uint8 right_channel,
                                                       uint8 left_channel, uint16 support_inflate_time,
                                                       uint16 massage_inflate_time)
{
    massage_knead_config_t* knead = massage_config->massage_knead_config;

    if (knead->knead_inflate_time < (support_inflate_time + massage_inflate_time))
    {
        if (knead->knead_inflate_time < support_inflate_time)
        {
            Snf_Massage_Support_Valve_Control(support_channel, support_channel_r, MASSAGE_SUPPORT_ACTION_INFLATE);
            knead->knead_inflate_time++;
        }
        else
        {
            Snf_Massage_Support_Valve_Control(support_channel, support_channel_r, MASSAGE_SUPPORT_ACTION_HOLD);
            ALL_INFLATE(top_channel, right_channel, left_channel);
            knead->knead_inflate_time++;
        }
        return true;
    }
    knead->knead_inflate_time = 0;
    return false;
}

/**
 * @brief  揉捏模式不带腰部支撑的充气控制函数。直接对主按摩气袋（上、左、右）同时充气，无需等待支撑气袋。
 * @param  massage_config - 按摩配置结构体指针
 * @param  top_channel - 上气袋通道
 * @param  right_channel - 右气袋通道
 * @param  left_channel - 左气袋通道
 * @param  massage_inflate_time - 主按摩气袋充气时间
 * @return bool - 充气进行中返回true，充气完成返回false
 */
static bool _Snf_Knead_Inflate_Unsupport_Air_Bag_Control(massage_config_t* massage_config, uint8 top_channel,
                                                         uint8 right_channel, uint8 left_channel, uint16 massage_inflate_time)
{
    massage_knead_config_t* knead = massage_config->massage_knead_config;

    if (knead->knead_inflate_time < massage_inflate_time)
    {
        ALL_INFLATE(top_channel, right_channel, left_channel);
        knead->knead_inflate_time++;
        return true;
    }
    knead->knead_inflate_time = 0;
    return false;
}

/**
 * @brief  揉捏模式充气阶段分发函数。根据支撑标志、双侧/单侧标志和按摩强度等级，从参数表取充气时间并调用对应的充气控制函数。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - 充气进行中返回true，充气完成返回false
 */
static bool _Snf_Knead_Inflate(massage_config_t* massage_config)
{
    const knead_inflate_time_t* inflate_time;
    uint8                       lvl = massage_config->massage_lvl;

    if ((lvl < (uint8)MASSAGE_INTENSITY_LOW) || (lvl > (uint8)MASSAGE_INTENSITY_HIGH))
    {
        /* 强度无效，保持充气进行中不动作，与原逻辑兜底一致 */
        return true;
    }

    inflate_time = &knead_inflate_time_table[massage_config->support_flag ? 1 : 0][massage_config->double_flag ? 1 : 0][lvl];

    if (massage_config->support_flag)
    {
        return _Snf_Knead_Inflate_Support_Air_Bag_Control(
            massage_config, massage_config->support_channel, massage_config->support_channel_r, massage_config->top_channel,
            massage_config->right_channel, massage_config->left_channel, MASSAGE_TIME_MS(inflate_time->support_inflate_time),
            MASSAGE_TIME_MS(inflate_time->massage_inflate_time));
    }
    else
    {
        return _Snf_Knead_Inflate_Unsupport_Air_Bag_Control(massage_config, massage_config->top_channel,
                                                            massage_config->right_channel, massage_config->left_channel,
                                                            MASSAGE_TIME_MS(inflate_time->massage_inflate_time));
    }
}

/********************************************************************************
************************* Cyclic Status *****************************************
********************************************************************************/

/**
 * @brief  揉捏模式循环控制函数。按bag_deflate_order指定的顺序依次对气袋放气（其余气袋充气），
 *         形成顺/逆时针揉捏的循环效果，同时释放腰部支撑气袋。
 * @param  massage_config - 按摩配置结构体指针
 * @param  support_channel - 腰部支撑气袋前阀通道
 * @param  support_channel_r - 腰部支撑气袋后阀通道
 * @param  top_channel - 上气袋通道
 * @param  right_channel - 右气袋通道
 * @param  left_channel - 左气袋通道
 * @param  bag_deflate_order - 气袋放气顺序数组（长度为KNEAD_BAG_MAX）
 * @param  massage_cyclic_time - 每个气袋的放气持续时间
 * @return bool - 循环进行中返回true，循环完成返回false
 */
static bool _Snf_Knead_Cyclic_Air_Bag_Control(massage_config_t* massage_config, uint8 support_channel, uint8 support_channel_r,
                                              uint8 top_channel, uint8 right_channel, uint8 left_channel,
                                              const uint8* bag_deflate_order, uint16 massage_cyclic_time)
{
    massage_knead_config_t* knead                      = massage_config->massage_knead_config;
    const uint8             bag_channel[KNEAD_BAG_MAX] = { top_channel, right_channel, left_channel };

    if (knead->knead_cyclic_count < massage_config->massage_times)
    {
        /* 循环期间持续释放腰部支撑气袋（支撑阀保压动作） */
        Snf_Massage_Support_Valve_Control(support_channel, support_channel_r, MASSAGE_SUPPORT_ACTION_HOLD);

        if (knead->knead_cyclic_time < (massage_cyclic_time * KNEAD_BAG_MAX))
        {
            uint8 deflate_phase;

            /* 按时间片确定当前处于第几个放气气袋 */
            if (knead->knead_cyclic_time < massage_cyclic_time)
            {
                deflate_phase = 0;
            }
            else if (knead->knead_cyclic_time < (massage_cyclic_time * 2))
            {
                deflate_phase = 1;
            }
            else
            {
                deflate_phase = 2;
            }

            /* 按放气顺序驱动气袋阀：当前气袋放气，其余两个气袋充气 */
            {
                uint8 deflate_bag = bag_deflate_order[deflate_phase];
                uint8 bag_index;

                for (bag_index = 0; bag_index < KNEAD_BAG_MAX; bag_index++)
                {
                    MASSAGE_VALVE_RAMP(bag_channel[bag_index],
                                       (bag_index == deflate_bag) ? POWER_VALVE_STATE_RAMP_DOWN : POWER_VALVE_STATE_RAMP_UP);
                }
            }
            knead->knead_cyclic_time++;
        }
        else
        {
            Snf_Massage_Support_Valve_Control(support_channel, support_channel_r, MASSAGE_SUPPORT_ACTION_HOLD);
            knead->knead_cyclic_time = 0;
            knead->knead_cyclic_count++;
        }
        return true;
    }
    knead->knead_cyclic_count = 0;
    knead->knead_cyclic_time  = 0;
    return false;
}

/**
 * @brief  揉捏模式循环阶段分发函数。根据双侧/单侧标志、按摩强度等级和揉捏方向，从参数表取循环周期时间，
 *         选择气袋放气顺序后调用统一的循环控制函数。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - 循环进行中返回true，循环完成返回false
 */
static bool _Snf_Knead_Cyclic(massage_config_t* massage_config)
{
    const uint8* bag_deflate_order;
    uint16       massage_cyclic_time;
    uint8        lvl = massage_config->massage_lvl;

    if ((lvl < (uint8)MASSAGE_INTENSITY_LOW) || (lvl > (uint8)MASSAGE_INTENSITY_HIGH))
    {
        /* 强度无效，保持循环进行中不动作，与原逻辑兜底一致 */
        return true;
    }

    if (massage_config->clockwise == CLOCKWISE)
    {
        bag_deflate_order = knead_bag_order_clockwise;
    }
    else if (massage_config->clockwise == ANTICLOCKWISE)
    {
        bag_deflate_order = knead_bag_order_anticlockwise;
    }
    else
    {
        /* 方向无效，保持循环进行中不动作（修复原函数无返回值的缺陷） */
        return true;
    }

    massage_cyclic_time = MASSAGE_TIME_MS(knead_cyclic_time_table[massage_config->double_flag ? 1 : 0][lvl]);

    return _Snf_Knead_Cyclic_Air_Bag_Control(massage_config, massage_config->support_channel, massage_config->support_channel_r,
                                             massage_config->top_channel, massage_config->right_channel,
                                             massage_config->left_channel, bag_deflate_order, massage_cyclic_time);
}

/********************************************************************************
************************* Deflate Status ****************************************
********************************************************************************/

/**
 * @brief  揉捏模式放气阶段控制函数。将所有按摩气袋（上、左、右）放气，并将腰部支撑气袋设置为支撑状态。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
static void _Snf_Knead_Deflate(massage_config_t* massage_config, uint16 knead_deflate_time)
{
    massage_knead_config_t* knead = massage_config->massage_knead_config;

    MASSAGE_VALVE_DEFLATE(massage_config->top_channel);
    MASSAGE_VALVE_DEFLATE(massage_config->right_channel);
    MASSAGE_VALVE_DEFLATE(massage_config->left_channel);
    Snf_Massage_Support_Valve_Control(massage_config->support_channel, massage_config->support_channel_r,
                                      MASSAGE_SUPPORT_ACTION_DEFLATE);

    if (massage_config->support_flag)
    {
        if (knead->knead_deflate_time < knead_deflate_time)
        {
            knead->knead_deflate_time++;
        }
        else
        {
            massage_config->work_flag = false;
        }
    }
    else
    {
        massage_config->work_flag = false;
    }
}

/**
 * @brief  揉捏模式时间计算函数。根据支撑标志、双侧/单侧标志和按摩强度等级，从参数表取时间参数计算总按摩输出时间。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
static void _Snf_Knead_TimeCalc(massage_config_t* massage_config)
{
    uint32_t calc_time = 0;
    uint8    lvl       = massage_config->massage_lvl;

    if ((lvl >= (uint8)MASSAGE_INTENSITY_LOW) && (lvl <= (uint8)MASSAGE_INTENSITY_HIGH))
    {
        const knead_inflate_time_t* inflate_time =
            &knead_inflate_time_table[massage_config->support_flag ? 1 : 0][massage_config->double_flag ? 1 : 0][lvl];
        uint16 cyclic_time = knead_cyclic_time_table[massage_config->double_flag ? 1 : 0][lvl];

        calc_time = (uint32_t)inflate_time->support_inflate_time + (uint32_t)inflate_time->massage_inflate_time +
                    (uint32_t)cyclic_time * massage_config->massage_times * 3;
    }
    else
    {
        /* 强度无效，输出时间为0 */
        MASSAGE_PRINTF("knead massage_lvl invalid: %d\r\n", massage_config->massage_lvl);
    }

    massage_config->massage_output_time = MASSAGE_OUTPUT_TIME_CONVERT(calc_time);
}
/************************ Public Function Implementations ************************/
/**
 * @brief  揉捏状态初始化
 * @param  massage_knead_config_l - 揉捏配置结构体指针
 * @return None
 * @note   全部字段清零即可：knead_status 的初值 KNEAD_INFLATE_STATUS 恰好为枚举值0
 */
void Snf_Massage_Knead_Init(massage_knead_config_t* massage_knead_config_l)
{
    (void)memset(massage_knead_config_l, 0, sizeof(*massage_knead_config_l));
}
/**
 * @brief  揉捏按摩模式主处理函数。根据按摩配置参数，管理揉捏模式的三个状态：充气状态、循环状态和放气状态，并在各状态之间进行切换。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
void Snf_Massage_Knead_Handle(massage_config_t* massage_config)
{
    massage_knead_config_t* knead = massage_config->massage_knead_config;

    if (massage_config->massage_lvl == 0 || massage_config->massage_times == 0)
    {
        massage_config->massage_output_time = 0;
        return;
    }

    _Snf_Knead_TimeCalc(massage_config);

    switch (knead->knead_status)
    {
        case KNEAD_INFLATE_STATUS:
            if (!_Snf_Knead_Inflate(massage_config))
            {
                knead->knead_status = KNEAD_CYCLIC_STATUS;
            }
            break;
        case KNEAD_CYCLIC_STATUS:
            if (!_Snf_Knead_Cyclic(massage_config))
            {
                knead->knead_status = KNEAD_DEFLATE_STATUS;
            }
            break;
        case KNEAD_DEFLATE_STATUS:
            _Snf_Knead_Deflate(massage_config,
                               MASSAGE_TIME_MS(MASSAGE_SUPPORT_VALVE_SELECT(KNEAD_KEEP_SUPPORT_AIR_7_8_DEFLATE_TIME,
                                                                            KNEAD_DEFLATE_SUPPORT_AIR_7_8_DEFLATE_TIME)));
            break;
        default:
            MASSAGE_PRINTF("knead invalid status %d, stop\r\n", knead->knead_status);
            knead->knead_status       = KNEAD_DEFLATE_STATUS;
            massage_config->work_flag = false;
            break;
    }
}
