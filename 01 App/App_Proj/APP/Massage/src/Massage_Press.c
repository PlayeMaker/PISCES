/************************ Include Files ************************/
#include "Basic_Config.h"
#include "Massage_Press.h"
#include <stdint.h>
#include "Valve_Types.h"
#include "Rte_Pwm_If.h"
#include "Rte_Swc.h"
#include "Rte_Os.h"
#include "Rte_Log.h"
/************************ Macro Definitions ************************/
#ifdef MASSAGE_PRINTF_ENABLE
#define MASSAGE_PRINTF RTE_LOG_PRINTF
#else
#define MASSAGE_PRINTF(...)
#endif
/************************ Private Global Variables ************************/

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/
/********************************************************************************
************************* Knead Bag Point Press *********************************
********************************************************************************/

/**
 * @brief  双侧低强度三点按压控制函数。根据腰部支撑标志，控制气袋充气保持，和放气时序，实现低强度三点按压效果。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - None
 */
static void _Snf_Massage_3_Point_Press_Double_Intensity_Low(massage_config_t *massage_config)
{
#define SUPPORT_INFLATE()   Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN)

#define SUPPORT_KEEP()      Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN)

#define ALL_INFLATE()       Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP)

#define ALL_DEFLATE()       Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_UP)

    if (massage_config->press_count < massage_config->massage_times)
    {
        if (massage_config->support_flag)
        {
            if (massage_config->press_poll_time < MASSAGE_TIME_MS(4000))
            {
                if (massage_config->press_poll_time < MASSAGE_TIME_MS(2000))
                {
                    SUPPORT_INFLATE();
                    massage_config->press_poll_time++;
                }
                else
                {
                    SUPPORT_KEEP();
                    ALL_INFLATE();
                    massage_config->press_poll_time++;
                }
            }
            else
            {
                ALL_DEFLATE();
                massage_config->press_poll_time = 0;
                massage_config->press_count++;
            }
        }
        else
        {
            if (massage_config->press_poll_time < MASSAGE_TIME_MS(4000))
            {
                ALL_INFLATE();
                massage_config->press_poll_time++;
            }
            else
            {
                ALL_DEFLATE();
                massage_config->press_poll_time = 0;
                massage_config->press_count++;
            }
        }
    }
}

/**
 * @brief  双侧高强度三点按压控制函数。根据腰部支撑标志，控制气袋充气保持，和放气时序，充气保持时间比低强度模式更长。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - None
 */
static void _Snf_Massage_3_Point_Press_Double_Intensity_High(massage_config_t *massage_config)
{
#define SUPPORT_INFLATE()   Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN)

#define SUPPORT_KEEP()      Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN)

#define ALL_INFLATE()       Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP)

#define ALL_DEFLATE()       Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_UP)

    if (massage_config->press_count < massage_config->massage_times)
    {
        if (massage_config->support_flag)
        {
            if (massage_config->press_poll_time < MASSAGE_TIME_MS(6000))
            {
                if (massage_config->press_poll_time < MASSAGE_TIME_MS(3000))
                {
                    SUPPORT_INFLATE();
                    massage_config->press_poll_time++;
                }
                else
                {
                    SUPPORT_KEEP();
                    ALL_INFLATE();
                    massage_config->press_poll_time++;
                }
            }
            else
            {
                ALL_DEFLATE();
                massage_config->press_poll_time = 0;
                massage_config->press_count++;
            }
        }
        else
        {
            if (massage_config->press_poll_time < MASSAGE_TIME_MS(6000))
            {
                ALL_INFLATE();
                massage_config->press_poll_time++;
            }
            else
            {
                ALL_DEFLATE();
                massage_config->press_poll_time = 0;
                massage_config->press_count++;
            }
        }
    }
}

/**
 * @brief  单侧低强度三点按压控制函数。根据腰部支撑标志，控制气袋充气保持，和放气时序，实现单侧低强度三点按压效果。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - None
 */
static void _Snf_Massage_3_Point_Press_Single_Intensity_Low(massage_config_t *massage_config)
{
#define SUPPORT_INFLATE()   Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN)

#define SUPPORT_KEEP()      Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN)

#define ALL_INFLATE()       Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP)

#define ALL_DEFLATE()       Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_UP)

    if (massage_config->press_count < massage_config->massage_times)
    {
        if (massage_config->support_flag)
        {
            if (massage_config->press_poll_time < MASSAGE_TIME_MS(2500))
            {
                if (massage_config->press_poll_time < MASSAGE_TIME_MS(1000))
                {
                    SUPPORT_INFLATE();
                }
                else
                {
                    SUPPORT_KEEP();
                    ALL_INFLATE();
                }
                massage_config->press_poll_time++;
            }
            else
            {
                ALL_DEFLATE();
                massage_config->press_poll_time = 0;
                massage_config->press_count++;
            }
        }
        else
        {
            if (massage_config->press_poll_time < MASSAGE_TIME_MS(2000))
            {
                ALL_INFLATE();
                massage_config->press_poll_time++;
            }
            else
            {
                ALL_DEFLATE();
                massage_config->press_poll_time = 0;
                massage_config->press_count++;
            }
        }
    }
}

/**
 * @brief  单侧高强度三点按压控制函数。根据腰部支撑标志，控制气袋充气保持，和放气时序，充气保持时间比低强度模式更长。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - None
 */
static void _Snf_Massage_3_Point_Press_Single_Intensity_High(massage_config_t *massage_config)
{
#define SUPPORT_INFLATE()   Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN)

#define SUPPORT_KEEP()      Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN)

#define ALL_INFLATE()       Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP)

#define ALL_DEFLATE()       Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_UP)

    if (massage_config->press_count < massage_config->massage_times)
    {
        if (massage_config->support_flag)
        {
            if (massage_config->press_poll_time < MASSAGE_TIME_MS(3500))
            {
                if (massage_config->press_poll_time < MASSAGE_TIME_MS(1500))
                {
                    SUPPORT_INFLATE();
                    massage_config->press_poll_time++;
                }
                else
                {
                    SUPPORT_KEEP();
                    ALL_INFLATE();
                    massage_config->press_poll_time++;
                }
            }
            else
            {
                ALL_DEFLATE();
                massage_config->press_poll_time = 0;
                massage_config->press_count++;
            }
        }
        else
        {
            if (massage_config->press_poll_time < MASSAGE_TIME_MS(3000))
            {
                ALL_INFLATE();
                massage_config->press_poll_time++;
            }
            else
            {
                ALL_DEFLATE();
                massage_config->press_poll_time = 0;
                massage_config->press_count++;
            }
        }
    }
}

/**
 * @brief  三点按压模式时间计算函数。根据腰部支撑标志、双侧/单侧标志和按摩强度等级，计算三点按压输出总时间。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - None
 */
static void Snf_Massage_3_Point_Press_TimeCalc(massage_config_t *massage_config)
{
    if (massage_config->support_flag)
    {
        if (massage_config->double_flag)
        {
            if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
            {
                massage_config->massage_output_time = 40 * massage_config->massage_times;
            }
            else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
            {
                massage_config->massage_output_time = 60 * massage_config->massage_times;
            }
        }
        else
        {
            if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
            {
                massage_config->massage_output_time = 25 * massage_config->massage_times;
            }
            else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
            {
                massage_config->massage_output_time = 35 * massage_config->massage_times;
            }
        }
    }
    else
    {
        if (massage_config->double_flag)
        {
            if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
            {
                massage_config->massage_output_time = 40 * massage_config->massage_times;
            }
            else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
            {
                massage_config->massage_output_time = 60 * massage_config->massage_times;
            }
        }
        else
        {
            if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
            {
                massage_config->massage_output_time = 20 * massage_config->massage_times;
            }
            else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
            {
                massage_config->massage_output_time = 30 * massage_config->massage_times;
            }
        }
    }
}

/********************************************************************************
************************* Shoulder Bag Point Press ******************************
********************************************************************************/

/**
 * @brief  肩部气囊点按模式时间计算函数。计算肩部气囊点按输出总时间。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - None
 */
static void Snf_Massage_Shoulder_Bag_Point_Press_TimeCalc(massage_config_t *massage_config)
{
    massage_config->massage_output_time = 30 * massage_config->massage_times;
}

/**
 * @brief  揉捏气袋循环点按模式时间计算函数。计算揉捏气袋循环点按输出总时间。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - None
 */
static void Snf_Knead_Bag_Cyclic_Press_TimeCalc(massage_config_t *massage_config)
{
    massage_config->massage_output_time = (30 + 25 + 25) * massage_config->massage_times;
}

/************************ Public Function Implementations ************************/

/**
 * @brief  三点按压模式主处理函数。根据双侧/单侧标志和按摩强度等级，调用对应的三点按压控制函数。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - None
 */
void Snf_Massage_3_Point_Press(massage_config_t *massage_config)
{
    if (massage_config->massage_lvl == MASSAGE_INTENSITY_IDLE || massage_config->massage_times == 0)
    {
        massage_config->massage_times = 0;
        return;
    }
    massage_config->valve_close_time = 0;
    massage_config->valve_close_flag = false;

    Snf_Massage_3_Point_Press_TimeCalc(massage_config);

    if (massage_config->double_flag)
    {
        if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
        {
            _Snf_Massage_3_Point_Press_Double_Intensity_Low(massage_config);
        }
        else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
        {
            _Snf_Massage_3_Point_Press_Double_Intensity_High(massage_config);
        }
    }
    else
    {
        if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
        {
            _Snf_Massage_3_Point_Press_Single_Intensity_Low(massage_config);
        }
        else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
        {
            _Snf_Massage_3_Point_Press_Single_Intensity_High(massage_config);
        }
    }
}

/**
 * @brief  肩部气囊点按模式主处理函数。控制肩部气囊按指定时序进行充气和放气，实现肩部点按效果。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - None
 */
void Snf_Massage_Shoulder_Bag_Point_Press(massage_config_t *massage_config)
{
    if (massage_config->massage_lvl == MASSAGE_INTENSITY_IDLE || massage_config->massage_times == 0)
    {
        massage_config->massage_times = 0;
        return;
    }

    massage_config->valve_close_time = 0;
    massage_config->valve_close_flag = false;
    Snf_Massage_Shoulder_Bag_Point_Press_TimeCalc(massage_config);

    if (massage_config->press_count < massage_config->massage_times)
    {
        if (massage_config->press_shoulder_time < MASSAGE_TIME_MS(3000))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->single_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->press_shoulder_time++;
        }
        else
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->single_channel, POWER_VALVE_STATE_RAMP_DOWN);
        }
    }
}

/**
 * @brief  揉捏气袋顺时针循环点按模式控制函数。按头->右->左的顺序依次控制各气囊充气点按，实现顺时针循环点按效果。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - None
 */
void Snf_Knead_Bag_Cyclic_Press_Clockwise(massage_config_t *massage_config)
{
#define NO_ACTION       0
#define ACTION          1
#define COMPLETE_ACTION 0xFF

    if (massage_config->massage_lvl == MASSAGE_INTENSITY_IDLE || massage_config->massage_times == 0)
    {
        massage_config->massage_times = 0;
        return;
    }

    massage_config->valve_close_time = 0;
    massage_config->valve_close_flag = false;
    Snf_Knead_Bag_Cyclic_Press_TimeCalc(massage_config);

    if (massage_config->press_count < massage_config->massage_times)
    {
        //头点按
        if (massage_config->press_top_time < MASSAGE_TIME_MS(3000))
        {
            if (massage_config->press_top_time >= MASSAGE_TIME_MS(2500))
            {
                massage_config->press_right_action_flag = ACTION;
            }
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->press_top_time++;
        }
        else
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
        }

        //右点按
        if (massage_config->press_right_action_flag == ACTION)
        {
            if (massage_config->press_right_time < MASSAGE_TIME_MS(3000))
            {
                if (massage_config->press_right_time >= MASSAGE_TIME_MS(2500))
                {
                    massage_config->press_left_action_flag = ACTION;
                }
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->press_right_time++;
            }
            else
            {
                massage_config->press_right_action_flag = COMPLETE_ACTION;
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
            }
        }

        //左点按
        if (massage_config->press_left_action_flag == ACTION)
        {
            if (massage_config->press_left_time < MASSAGE_TIME_MS(3000))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->press_left_time++;
            }
            else
            {
                massage_config->press_left_action_flag = COMPLETE_ACTION;
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
            }
        }

        //全部点按完成
        if (massage_config->press_left_action_flag == COMPLETE_ACTION)
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
            massage_config->press_top_time = 0;
            massage_config->press_left_time = 0;
            massage_config->press_right_time = 0;
            massage_config->press_right_action_flag = NO_ACTION;
            massage_config->press_left_action_flag = NO_ACTION;
            massage_config->press_count++;
        }
    }
}

/**
 * @brief  揉捏气袋逆时针循环点按模式控制函数。按头->左->右的顺序依次控制各气囊充气点按，实现逆时针循环点按效果。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - None
 */
void Snf_Knead_Bag_Cyclic_Press_Anticlockwise(massage_config_t *massage_config)
{
#define NO_ACTION       0
#define ACTION          1
#define COMPLETE_ACTION 0xFF

    if (massage_config->massage_lvl == MASSAGE_INTENSITY_IDLE || massage_config->massage_times == 0)
    {
        massage_config->massage_times = 0;
        return;
    }

    massage_config->valve_close_time = 0;
    massage_config->valve_close_flag = false;
    Snf_Knead_Bag_Cyclic_Press_TimeCalc(massage_config);

    if (massage_config->press_count < massage_config->massage_times)
    {
        //头点按
        if (massage_config->press_top_time < MASSAGE_TIME_MS(3000))
        {
            if (massage_config->press_top_time >= MASSAGE_TIME_MS(2500))
            {
                massage_config->press_left_action_flag = ACTION;
            }
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->press_top_time++;
        }
        else
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
        }

        //左点按
        if (massage_config->press_left_action_flag == ACTION)
        {
            if (massage_config->press_left_time < MASSAGE_TIME_MS(3000))
            {
                if (massage_config->press_left_time >= MASSAGE_TIME_MS(2500))
                {
                    massage_config->press_right_action_flag = ACTION;
                }
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->press_left_time++;
            }
            else
            {
                massage_config->press_right_action_flag = ACTION;
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
            }
        }

        //右点按
        if (massage_config->press_right_action_flag == ACTION)
        {
            if (massage_config->press_right_time < MASSAGE_TIME_MS(3000))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->press_right_time++;
            }
            else
            {
                massage_config->press_right_action_flag = COMPLETE_ACTION;
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
            }
        }

        //全部点按完成
        if (massage_config->press_right_action_flag == COMPLETE_ACTION)
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
            massage_config->press_top_time = 0;
            massage_config->press_left_time = 0;
            massage_config->press_right_time = 0;
            massage_config->press_right_action_flag = NO_ACTION;
            massage_config->press_left_action_flag = NO_ACTION;
            massage_config->press_count++;
        }
    }
}