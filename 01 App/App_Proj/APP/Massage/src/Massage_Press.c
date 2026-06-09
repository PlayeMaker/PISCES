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
static void _Snf_Massage_Point_Press_Double_Intensity_Low(massage_config_t *massage_config)
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
            if (massage_config->press_poll_time < MASSAGE_AIR_BAG_TIME_MS(4000))
            {
                if (massage_config->press_poll_time < MASSAGE_AIR_BAG_TIME_MS(2000))
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
            if (massage_config->press_poll_time < MASSAGE_AIR_BAG_TIME_MS(4000))
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

static void _Snf_Massage_Point_Press_Double_Intensity_High(massage_config_t *massage_config)
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
            if (massage_config->press_poll_time < MASSAGE_AIR_BAG_TIME_MS(6000))
            {
                if (massage_config->press_poll_time < MASSAGE_AIR_BAG_TIME_MS(3000))
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
            if (massage_config->press_poll_time < MASSAGE_AIR_BAG_TIME_MS(6000))
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

static void _Snf_Massage_Point_Press_Single_Intensity_Low(massage_config_t *massage_config)
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
            if (massage_config->press_poll_time < MASSAGE_AIR_BAG_TIME_MS(2500))
            {
                if (massage_config->press_poll_time < MASSAGE_AIR_BAG_TIME_MS(1000))
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
            if (massage_config->press_poll_time < MASSAGE_AIR_BAG_TIME_MS(2000))
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

static void _Snf_Massage_Point_Press_Single_Intensity_High(massage_config_t *massage_config)
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
            if (massage_config->press_poll_time < MASSAGE_AIR_BAG_TIME_MS(3500))
            {
                if (massage_config->press_poll_time < MASSAGE_AIR_BAG_TIME_MS(1500))
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
            if (massage_config->press_poll_time < MASSAGE_AIR_BAG_TIME_MS(3000))
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

void Snf_Massage_3_Point_Press(massage_config_t *massage_config)
{
    if (massage_config->massage_lvl == MASSAGE_INTENSITY_IDLE || massage_config->massage_times == 0)
    {
        massage_config->massage_times = 0;
        return;
    }

    Snf_Massage_3_Point_Press_TimeCalc(massage_config);

    if (massage_config->double_flag)
    {
        if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
        {
            _Snf_Massage_Point_Press_Double_Intensity_Low(massage_config);
        }
        else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
        {
            _Snf_Massage_Point_Press_Double_Intensity_High(massage_config);
        }
    }
    else
    {
        if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
        {
            _Snf_Massage_Point_Press_Single_Intensity_Low(massage_config);
        }
        else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
        {
            _Snf_Massage_Point_Press_Single_Intensity_High(massage_config);
        }
    }
}

static void Snf_Massage_Shoulder_Bag_Point_Press_TimeCalc(massage_config_t *massage_config)
{
    massage_config->massage_output_time = 30 * massage_config->massage_times;
}

void Snf_Massage_Shoulder_Bag_Point_Press(massage_config_t *massage_config)
{
    if (massage_config->massage_lvl == MASSAGE_INTENSITY_IDLE || massage_config->massage_times == 0)
    {
        massage_config->massage_times = 0;
        return;
    }

    Snf_Massage_Shoulder_Bag_Point_Press_TimeCalc(massage_config);

    if (massage_config->press_count < massage_config->massage_times)
    {
        if (massage_config->press_shoulder_time < MASSAGE_AIR_BAG_TIME_MS(3000))
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

static void Snf_Knead_Bag_Cyclic_Press_TimeCalc(massage_config_t *massage_config)
{
    massage_config->massage_output_time = (30 + 25 + 25) * massage_config->massage_times;
}

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

    Snf_Knead_Bag_Cyclic_Press_TimeCalc(massage_config);

    if (massage_config->press_count < massage_config->massage_times)
    {
        //头点按
        if (massage_config->press_top_time < MASSAGE_AIR_BAG_TIME_MS(3000))
        {
            if (massage_config->press_top_time >= MASSAGE_AIR_BAG_TIME_MS(2500))
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
            if (massage_config->press_right_time < MASSAGE_AIR_BAG_TIME_MS(3000))
            {
                if (massage_config->press_right_time >= MASSAGE_AIR_BAG_TIME_MS(2500))
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
            if (massage_config->press_left_time < MASSAGE_AIR_BAG_TIME_MS(3000))
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

    Snf_Knead_Bag_Cyclic_Press_TimeCalc(massage_config);

    if (massage_config->press_count < massage_config->massage_times)
    {
        //头点按
        if (massage_config->press_top_time < MASSAGE_AIR_BAG_TIME_MS(3000))
        {
            if (massage_config->press_top_time >= MASSAGE_AIR_BAG_TIME_MS(2500))
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
            if (massage_config->press_left_time < MASSAGE_AIR_BAG_TIME_MS(3000))
            {
                if (massage_config->press_left_time >= MASSAGE_AIR_BAG_TIME_MS(2500))
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
            if (massage_config->press_right_time < MASSAGE_AIR_BAG_TIME_MS(3000))
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
