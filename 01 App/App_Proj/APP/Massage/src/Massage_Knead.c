/************************ Include Files ************************/
#include "Basic_Config.h"
#include "Massage_Knead.h"
#include "Valve_Types.h"
#include "Rte_Swc.h"
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
static bool _Snf_Knead_Inflate_Double_Intensity_Low(massage_config_t *massage_config);
static bool _Snf_Knead_Inflate_Double_Intensity_High(massage_config_t *massage_config);
static bool _Snf_Knead_Inflate_Single_Intensity_Low(massage_config_t *massage_config);
static bool _Snf_Knead_Inflate_Single_Intensity_High(massage_config_t *massage_config);
static bool _Snf_Knead_Inflate(massage_config_t *massage_config);
static bool _Snf_Knead_Cyclic_Double_Intensity_Low(massage_config_t *massage_config);
static bool _Snf_Knead_Cyclic_Double_Intensity_High(massage_config_t *massage_config);
static bool _Snf_Knead_Cyclic_Single_Intensity_Low(massage_config_t *massage_config);
static bool _Snf_Knead_Cyclic_Single_Intensity_High(massage_config_t *massage_config);
static bool _Snf_Knead_Cyclic(massage_config_t *massage_config);
static void _Snf_Knead_Deflate(massage_config_t *massage_config);
static void _Snf_Knead_TimeCalc(massage_config_t *massage_config);
/************************ Private Function Implementations ************************/

/********************************************************************************
************************* Inflate Status ****************************************
********************************************************************************/

/**
 * @brief  双侧低强度揉捏模式的充气阶段控制函数。根据是否有腰部支撑标志，控制不同气袋的充气和保持时序。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - 充气进行中返回true，充气完成返回false
 */
static bool _Snf_Knead_Inflate_Double_Intensity_Low(massage_config_t *massage_config)
{
#define SUPPORT_INFLATE()   Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN)

#define SUPPORT_KEEP()      Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN)

#define ALL_INFLATE()       Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP)

    if (massage_config->support_flag)
    {
        if (massage_config->knead_inflate_time < MASSAGE_TIME_MS(6000))
        {
            if (massage_config->knead_inflate_time < MASSAGE_TIME_MS(2000))
            {
                SUPPORT_INFLATE();
                massage_config->knead_inflate_time++;
            }
            else
            {
                SUPPORT_KEEP();
                ALL_INFLATE();
                massage_config->knead_inflate_time++;
            }
            return true;
        }
        massage_config->knead_inflate_time = 0;
        return false;
    }
    else
    {
        if (massage_config->knead_inflate_time < MASSAGE_TIME_MS(3500))
        {
            ALL_INFLATE();
            massage_config->knead_inflate_time++;
            return true;
        }
        massage_config->knead_inflate_time = 0;
        return false;
    }
}

/**
 * @brief  双侧高强度揉捏模式的充气阶段控制函数。根据是否有腰部支撑标志，控制不同气袋的充气和保持时序，充气时间比低强度更长。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - 充气进行中返回true，充气完成返回false
 */
static bool _Snf_Knead_Inflate_Double_Intensity_High(massage_config_t *massage_config)
{
#define SUPPORT_INFLATE()   Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN)

#define SUPPORT_KEEP()      Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN)

#define ALL_INFLATE()       Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP)

    if (massage_config->support_flag)
    {
        if (massage_config->knead_inflate_time < MASSAGE_TIME_MS(7000))
        {
            if (massage_config->knead_inflate_time < MASSAGE_TIME_MS(2500))
            {
                SUPPORT_INFLATE();
                massage_config->knead_inflate_time++;
            }
            else
            {
                SUPPORT_KEEP();
                ALL_INFLATE();
                massage_config->knead_inflate_time++;
            }
            return true;
        }
        massage_config->knead_inflate_time = 0;
        return false;
    }
    else
    {
        if (massage_config->knead_inflate_time < MASSAGE_TIME_MS(4000))
        {
            ALL_INFLATE();
            massage_config->knead_inflate_time++;
            return true;
        }
        massage_config->knead_inflate_time = 0;
        return false;
    }
}

/**
 * @brief  单侧低强度揉捏模式的充气阶段控制函数。根据是否有腰部支撑标志，控制气袋的充气时序，充气时间相对较短。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - 充气进行中返回true，充气完成返回false
 */
static bool _Snf_Knead_Inflate_Single_Intensity_Low(massage_config_t *massage_config)
{
#define SUPPORT_INFLATE()   Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN)

#define SUPPORT_KEEP()      Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN)

#define ALL_INFLATE()       Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP)

    if (massage_config->support_flag)
    {
        if (massage_config->knead_inflate_time < MASSAGE_TIME_MS(3500))
        {
            if (massage_config->knead_inflate_time < MASSAGE_TIME_MS(1500))
            {
                SUPPORT_INFLATE();
                massage_config->knead_inflate_time++;
            }
            else
            {
                SUPPORT_KEEP();
                ALL_INFLATE();
                massage_config->knead_inflate_time++;
            }
            return true;
        }
        massage_config->knead_inflate_time = 0;
        return false;
    }
    else
    {
        if (massage_config->knead_inflate_time < MASSAGE_TIME_MS(2000))
        {
            ALL_INFLATE();
            massage_config->knead_inflate_time++;
            return true;
        }
        massage_config->knead_inflate_time = 0;
        return false;
    }
}

/**
 * @brief  单侧高强度揉捏模式的充气阶段控制函数。根据是否有腰部支撑标志，控制气袋的充气时序，充气时间比低强度更长。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - 充气进行中返回true，充气完成返回false
 */
static bool _Snf_Knead_Inflate_Single_Intensity_High(massage_config_t *massage_config)
{
#define SUPPORT_INFLATE()   Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN)

#define SUPPORT_KEEP()      Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN)

#define ALL_INFLATE()       Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP)

    if (massage_config->support_flag)
    {
        if (massage_config->knead_inflate_time < MASSAGE_TIME_MS(5000))
        {
            if (massage_config->knead_inflate_time < MASSAGE_TIME_MS(2000))
            {
                SUPPORT_INFLATE();
                massage_config->knead_inflate_time++;
            }
            else
            {
                SUPPORT_KEEP();
                ALL_INFLATE();
                massage_config->knead_inflate_time++;
            }
            return true;
        }
        massage_config->knead_inflate_time = 0;
        return false;
    }
    else
    {
        if (massage_config->knead_inflate_time < MASSAGE_TIME_MS(2500))
        {
            ALL_INFLATE();
            massage_config->knead_inflate_time++;
            return true;
        }
        massage_config->knead_inflate_time = 0;
        return false;
    }
}

/**
 * @brief  揉捏模式充气阶段分发函数。根据双侧/单侧标志和按摩强度等级，调用对应的充气控制函数。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - 循环进行中返回true，循环完成返回false
 */
static bool _Snf_Knead_Inflate(massage_config_t *massage_config)
{
    if (massage_config->double_flag)
    {
        if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
        {
            return _Snf_Knead_Inflate_Double_Intensity_Low(massage_config);
        }
        else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
        {
            return _Snf_Knead_Inflate_Double_Intensity_High(massage_config);
        }
    }
    else
    {
        if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
        {
            return _Snf_Knead_Inflate_Single_Intensity_Low(massage_config);
        }
        else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
        {
            return _Snf_Knead_Inflate_Single_Intensity_High(massage_config);
        }
    }
}

/********************************************************************************
************************* Cyclic Status *****************************************
********************************************************************************/

/**
 * @brief  双侧低强度揉捏模式的循环阶段控制函数。控制上、左、右气袋按照，顺时针或逆时针方向依次放气实现循环揉捏效果。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - 循环进行中返回true，循环完成返回false
 */
static bool _Snf_Knead_Cyclic_Double_Intensity_Low(massage_config_t *massage_config)
{
#define TOP_DEFLATE()       Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP)

#define LEFT_DEFLATE()      Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN)

#define RIGHT_DEFLATE()     Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP)

    if (massage_config->knead_cyclic_count < massage_config->massage_times)
    {
        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);
        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN);
        //顺时针
        if (massage_config->clockwise == CLOCKWISE)
        {
            if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(700))
            {
                TOP_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(1400))
            {
                RIGHT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if ( massage_config->knead_cyclic_time < MASSAGE_TIME_MS(2100))
            {
                LEFT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time >= MASSAGE_TIME_MS(2100))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->knead_cyclic_time = 0;
                massage_config->knead_cyclic_count++;
            }
            return true;
        }
        //逆时针
        else
        {
            if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(700))
            {
                TOP_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(1400))
            {
                LEFT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(2100))
            {
                RIGHT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time >= MASSAGE_TIME_MS(2100))
            {
                massage_config->knead_cyclic_time = 0;
                massage_config->knead_cyclic_count++;
            }
            return true;
        }
    }
    massage_config->knead_cyclic_count = 0;
    massage_config->knead_cyclic_time = 0;
    return false;
}

/**
 * @brief  双侧高强度揉捏模式的循环阶段控制函数。控制上、左、右气袋按照，顺时针或逆时针方向依次放气，实现循环揉捏效果。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - 循环进行中返回true，循环完成返回false
 */
static bool _Snf_Knead_Cyclic_Double_Intensity_High(massage_config_t *massage_config)
{
#define TOP_DEFLATE()       Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP)

#define LEFT_DEFLATE()      Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN)

#define RIGHT_DEFLATE()     Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP)

    if (massage_config->knead_cyclic_count < massage_config->massage_times)
    {
        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);
        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN);
        //顺时针
        if (massage_config->clockwise == CLOCKWISE)
        {
            if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(500))
            {
                TOP_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(1000))
            {
                RIGHT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(1500))
            {
                LEFT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else
            {
                massage_config->knead_cyclic_time = 0;
                massage_config->knead_cyclic_count++;
            }
            return true;
        }
        //逆时针
        else
        {
            if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(500))
            {
                TOP_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(1000))
            {
                LEFT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(1500))
            {
                RIGHT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else
            {
                massage_config->knead_cyclic_time = 0;
                massage_config->knead_cyclic_count++;
            }
            return true;
        }
    }
    massage_config->knead_cyclic_count = 0;
    massage_config->knead_cyclic_time = 0;
    return false;
}

/**
 * @brief  单侧低强度揉捏模式的循环阶段控制函数。控制上、左、右气袋按照，顺时针或逆时针方向依次放气实现循环揉捏效果。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - 循环进行中返回true，循环完成返回false
 */
static bool _Snf_Knead_Cyclic_Single_Intensity_Low(massage_config_t *massage_config)
{
#define TOP_DEFLATE()       Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP)

#define LEFT_DEFLATE()      Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN)

#define RIGHT_DEFLATE()     Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP)

    if (massage_config->knead_cyclic_count < massage_config->massage_times)
    {
        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);
        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN);
        //顺时针
        if (massage_config->clockwise == CLOCKWISE)
        {
            if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(700))
            {
                TOP_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(1400))
            {
                RIGHT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if ( massage_config->knead_cyclic_time < MASSAGE_TIME_MS(2100))
            {
                LEFT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time >= MASSAGE_TIME_MS(2100))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->knead_cyclic_time = 0;
                massage_config->knead_cyclic_count++;
            }
            return true;
        }
        //逆时针
        else
        {
            if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(700))
            {
                TOP_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(1400))
            {
                LEFT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(2100))
            {
                RIGHT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time >= MASSAGE_TIME_MS(2100))
            {
                massage_config->knead_cyclic_time = 0;
                massage_config->knead_cyclic_count++;
            }
            return true;
        }
    }
    massage_config->knead_cyclic_count = 0;
    massage_config->knead_cyclic_time = 0;
    return false;
}

/**
 * @brief  单侧高强度揉捏模式的循环阶段控制函数。控制上、左、右气袋按照，顺时针或逆时针方向依次放气，循环速度比低强度更快。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - 循环进行中返回true，循环完成返回false
 */
static bool _Snf_Knead_Cyclic_Single_Intensity_High(massage_config_t *massage_config)
{
#define TOP_DEFLATE()       Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP)

#define LEFT_DEFLATE()      Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN)

#define RIGHT_DEFLATE()     Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);\
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP)

    if (massage_config->knead_cyclic_count < massage_config->massage_times)
    {
        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);
        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN);
        //顺时针
        if (massage_config->clockwise == CLOCKWISE)
        {
            if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(500))
            {
                TOP_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(1000))
            {
                RIGHT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(1500))
            {
                LEFT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else
            {
                massage_config->knead_cyclic_time = 0;
                massage_config->knead_cyclic_count++;
            }
            return true;
        }
        //逆时针
        else
        {
            if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(500))
            {
                TOP_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(1000))
            {
                LEFT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_TIME_MS(1500))
            {
                RIGHT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else
            {
                massage_config->knead_cyclic_time = 0;
                massage_config->knead_cyclic_count++;
            }
            return true;
        }
    }
    massage_config->knead_cyclic_count = 0;
    massage_config->knead_cyclic_time = 0;
    return false;
}

/**
 * @brief  揉捏模式循环阶段分发函数。根据双侧/单侧标志和按摩强度等级，调用对应的循环控制函数。
 * @param  massage_config - 按摩配置结构体指针
 * @return bool - 循环进行中返回true，循环完成返回false
 */
static bool _Snf_Knead_Cyclic(massage_config_t *massage_config)
{
    if (massage_config->double_flag)
    {
        if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
        {
            return _Snf_Knead_Cyclic_Double_Intensity_Low(massage_config);
        }
        else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
        {
            return _Snf_Knead_Cyclic_Double_Intensity_High(massage_config);
        }
    }
    else
    {
        if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
        {
            return _Snf_Knead_Cyclic_Single_Intensity_Low(massage_config);
        }
        else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
        {
            return _Snf_Knead_Cyclic_Single_Intensity_High(massage_config);
        }
    }
    return true;
}

/********************************************************************************
************************* Deflate Status ****************************************
********************************************************************************/

/**
 * @brief  揉捏模式放气阶段控制函数。将所有按摩气袋（上、左、右）放气，并将腰部支撑气袋设置为支撑状态。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
static void _Snf_Knead_Deflate(massage_config_t *massage_config)
{
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_UP);
}

/**
 * @brief  揉捏模式时间计算函数。根据是否有腰部支撑标志和按摩强度等级
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
static void _Snf_Knead_TimeCalc(massage_config_t *massage_config)
{
    if (massage_config->support_flag)
    {
        if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
        {
            massage_config->massage_output_time = 60 + 7 * massage_config->massage_times;
        }
        else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
        {
            massage_config->massage_output_time = 70 + 5 * massage_config->massage_times;
        }
    }
    else
    {
        if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
        {
            massage_config->massage_output_time = 35 + 7 * massage_config->massage_times;
        }
        else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
        {
            massage_config->massage_output_time = 45 + 5 * massage_config->massage_times;
        }
    }
}
/************************ Public Function Implementations ************************/
/**
 * @brief  揉捏按摩模式主处理函数。根据按摩配置参数，管理揉捏模式的三个状态：充气状态、循环状态和放气状态，并在各状态之间进行切换。
 * @param  massage_config - 按摩配置结构体指针
 * @return None
 */
void _Snf_Massage_Knead_Handle(massage_config_t *massage_config)
{
    if (massage_config->massage_lvl == 0 || massage_config->massage_times == 0)
    {
        massage_config->massage_output_time = 0;
        return;
    }
    massage_config->valve_close_time = 0;
    massage_config->valve_close_flag = false;

    _Snf_Knead_TimeCalc(massage_config);

    switch (massage_config->knead_status)
    {
        case KNEAD_INFLATE_STATUS:
            if (!_Snf_Knead_Inflate(massage_config))
            {
                massage_config->knead_status = KNEAD_CYCLIC_STATUS;
            }
            break;
        case KNEAD_CYCLIC_STATUS:
            if (!_Snf_Knead_Cyclic(massage_config) )
            {
                massage_config->knead_status = KNEAD_DEFLATE_STATUS;
            }
            break;
        case KNEAD_DEFLATE_STATUS:
            _Snf_Knead_Deflate(massage_config);
            break;
        default:
            break;
    }
}
