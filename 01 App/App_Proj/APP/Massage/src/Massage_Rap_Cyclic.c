#include "Massage_Rap_Cyclic.h"
#include "Rte_Swc.h"

#include <stdbool.h>
/***********************************双区域强度高************************************************************/
bool Snf_Cyclic_Top_Double_Intensity_High(massage_config_t *massage_config)
{
    if (massage_config->support_flag)
    {
        //循环前的充气时间
        if (massage_config->rap_top_pre_time < MASSAGE_AIR_BAG_TIME_MS(3000))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_top_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_top_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_top_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(200))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_top_cyclic_time++;
            }
            else if (massage_config->rap_top_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(340))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_top_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_top_cyclic_time = 0;
                massage_config->rap_top_cyclic_count++;
            }
            return true;
        }
        return false;
    }
    else
    {
        //循环前的充气时间
        if (massage_config->rap_top_pre_time < MASSAGE_AIR_BAG_TIME_MS(2700))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_top_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_top_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_top_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(180))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_top_cyclic_time++;
            }
            else if (massage_config->rap_top_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(320))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_top_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_top_cyclic_time = 0;
                massage_config->rap_top_cyclic_count++;
            }
            return true;
        }
        return false;
    }
}

bool Snf_Cyclic_Right_Double_Intensity_High(massage_config_t *massage_config)
{
    if (massage_config->support_flag)
    {
        //循环前的充气时间
        if (massage_config->rap_right_pre_time < MASSAGE_AIR_BAG_TIME_MS(3000))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_right_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_right_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_right_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(200))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_right_cyclic_time++;
            }
            else if (massage_config->rap_right_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(340))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_right_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_right_cyclic_time = 0;
                massage_config->rap_right_cyclic_count++;
            }
            return true;
        }
        return false;
    }
    else
    {
        //循环前的充气时间
        if (massage_config->rap_right_pre_time < MASSAGE_AIR_BAG_TIME_MS(2700))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_right_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_right_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_right_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(180))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_right_cyclic_time++;
            }
            else if (massage_config->rap_right_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(320))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_right_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_right_cyclic_time = 0;
                massage_config->rap_right_cyclic_count++;
            }
            return true;
        }
        return false;
    }
}

bool Snf_Cyclic_Left_Double_Intensity_High(massage_config_t *massage_config)
{
    if (massage_config->support_flag)
    {
        //循环前的充气时间
        if (massage_config->rap_left_pre_time < MASSAGE_AIR_BAG_TIME_MS(3000))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_left_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_left_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_left_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(200))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_left_cyclic_time++;
            }
            else if (massage_config->rap_left_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(340))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_left_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_left_cyclic_time = 0;
                massage_config->rap_left_cyclic_count++;
            }
            return true;
        }
        return false;
    }
    else
    {
        //循环前的充气时间
        if (massage_config->rap_left_pre_time < MASSAGE_AIR_BAG_TIME_MS(2700))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_left_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_left_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_left_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(180))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_left_cyclic_time++;
            }
            else if (massage_config->rap_left_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(320))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_left_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_left_cyclic_time = 0;
                massage_config->rap_left_cyclic_count++;
            }
            return true;
        }
        return false;
    }
}
/***********************************双区域强度低************************************************************/
bool Snf_Cyclic_Top_Double_Intensity_Low(massage_config_t *massage_config)
{
    if (massage_config->support_flag)
    {
        //循环前的充气时间
        if (massage_config->rap_top_pre_time < MASSAGE_AIR_BAG_TIME_MS(2400))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_top_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_top_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_top_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(300))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_top_cyclic_time++;
            }
            else if (massage_config->rap_top_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(480))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_top_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_top_cyclic_time = 0;
                massage_config->rap_top_cyclic_count++;
            }
            return true;
        }
        return false;
    }
    else
    {
        //循环前的充气时间
        if (massage_config->rap_top_pre_time < MASSAGE_AIR_BAG_TIME_MS(2100))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_top_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_top_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_top_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(280))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_top_cyclic_time++;
            }
            else if (massage_config->rap_top_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(460))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_top_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_top_cyclic_time = 0;
                massage_config->rap_top_cyclic_count++;
            }
            return true;
        }
        return false;
    }
}

bool Snf_Cyclic_Right_Double_Intensity_Low(massage_config_t *massage_config)
{
    if (massage_config->support_flag)
    {
        //循环前的充气时间
        if (massage_config->rap_right_pre_time < MASSAGE_AIR_BAG_TIME_MS(2400))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_right_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_right_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_right_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(300))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_right_cyclic_time++;
            }
            else if (massage_config->rap_right_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(480))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_right_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_right_cyclic_time = 0;
                massage_config->rap_right_cyclic_count++;
            }
            return true;
        }
        return false;
    }
    else
    {
        //循环前的充气时间
        if (massage_config->rap_right_pre_time < MASSAGE_AIR_BAG_TIME_MS(2100))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_right_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_right_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_right_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(280))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_right_cyclic_time++;
            }
            else if (massage_config->rap_right_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(460))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_right_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_right_cyclic_time = 0;
                massage_config->rap_right_cyclic_count++;
            }
            return true;
        }
        return false;
    }
}

bool Snf_Cyclic_Left_Double_Intensity_Low(massage_config_t *massage_config)
{
    if (massage_config->support_flag)
    {
        //循环前的充气时间
        if (massage_config->rap_left_pre_time < MASSAGE_AIR_BAG_TIME_MS(2400))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_left_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_left_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_left_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(300))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_left_cyclic_time++;
            }
            else if (massage_config->rap_left_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(480))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_left_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_left_cyclic_time = 0;
                massage_config->rap_left_cyclic_count++;
            }
            return true;
        }
        return false;
    }
    else
    {
        //循环前的充气时间
        if (massage_config->rap_left_pre_time < MASSAGE_AIR_BAG_TIME_MS(2100))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_left_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_left_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_left_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(280))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_left_cyclic_time++;
            }
            else if (massage_config->rap_left_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(460))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_left_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_left_cyclic_time = 0;
                massage_config->rap_left_cyclic_count++;
            }
            return true;
        }
        return false;
    }
}
/***********************************单区域强度高************************************************************/
bool Snf_Cyclic_Top_Single_Intensity_High(massage_config_t *massage_config)
{
    if (massage_config->support_flag)
    {
        //循环前的充气时间
        if (massage_config->rap_top_pre_time < MASSAGE_AIR_BAG_TIME_MS(1800))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_top_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_top_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_top_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(200))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_top_cyclic_time++;
            }
            else if (massage_config->rap_top_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(340))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_top_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_top_cyclic_time = 0;
                massage_config->rap_top_cyclic_count++;
            }
            return true;
        }
        return false;
    }
    else
    {
        //循环前的充气时间
        if (massage_config->rap_top_pre_time < MASSAGE_AIR_BAG_TIME_MS(1600))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_top_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_top_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_top_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(180))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_top_cyclic_time++;
            }
            else if (massage_config->rap_top_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(320))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_top_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_top_cyclic_time = 0;
                massage_config->rap_top_cyclic_count++;
            }
            return true;
        }
        return false;
    }
}

bool Snf_Cyclic_Right_Single_Intensity_High(massage_config_t *massage_config)
{
    if (massage_config->support_flag)
    {
        //循环前的充气时间
        if (massage_config->rap_right_pre_time < MASSAGE_AIR_BAG_TIME_MS(1800))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_right_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_right_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_right_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(200))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_right_cyclic_time++;
            }
            else if (massage_config->rap_right_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(340))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_right_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_right_cyclic_time = 0;
                massage_config->rap_right_cyclic_count++;
            }
            return true;
        }
        return false;
    }
    else
    {
        //循环前的充气时间
        if (massage_config->rap_right_pre_time < MASSAGE_AIR_BAG_TIME_MS(1600))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_right_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_right_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_right_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(180))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_right_cyclic_time++;
            }
            else if (massage_config->rap_right_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(320))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_right_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_right_cyclic_time = 0;
                massage_config->rap_right_cyclic_count++;
            }
            return true;
        }
        return false;
    }
}

bool Snf_Cyclic_Left_Single_Intensity_High(massage_config_t *massage_config)
{
    if (massage_config->support_flag)
    {
        //循环前的充气时间
        if (massage_config->rap_left_pre_time < MASSAGE_AIR_BAG_TIME_MS(1800))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_left_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_left_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_left_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(200))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_left_cyclic_time++;
            }
            else if (massage_config->rap_left_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(340))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_left_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_left_cyclic_time = 0;
                massage_config->rap_left_cyclic_count++;
            }
            return true;
        }
        return false;
    }
    else
    {
        //循环前的充气时间
        if (massage_config->rap_left_pre_time < MASSAGE_AIR_BAG_TIME_MS(1600))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_left_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_left_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_left_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(180))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_left_cyclic_time++;
            }
            else if (massage_config->rap_left_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(320))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_left_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_left_cyclic_time = 0;
                massage_config->rap_left_cyclic_count++;
            }
            return true;
        }
        return false;
    }
}
/***********************************单区域强度低************************************************************/
bool Snf_Cyclic_Top_Single_Intensity_Low(massage_config_t *massage_config)
{
    if (massage_config->support_flag)
    {
        //循环前的充气时间
        if (massage_config->rap_top_pre_time < MASSAGE_AIR_BAG_TIME_MS(1600))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_top_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_top_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_top_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(300))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_top_cyclic_time++;
            }
            else if (massage_config->rap_top_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(480))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_top_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_top_cyclic_time = 0;
                massage_config->rap_top_cyclic_count++;
            }
            return true;
        }
        return false;
    }
    else
    {
        //循环前的充气时间
        if (massage_config->rap_top_pre_time < MASSAGE_AIR_BAG_TIME_MS(1300))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_top_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_top_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_top_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(280))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_top_cyclic_time++;
            }
            else if (massage_config->rap_top_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(460))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_top_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_top_cyclic_time = 0;
                massage_config->rap_top_cyclic_count++;
            }
            return true;
        }
        return false;
    }
}

bool Snf_Cyclic_Right_Single_Intensity_Low(massage_config_t *massage_config)
{
    if (massage_config->support_flag)
    {
        //循环前的充气时间
        if (massage_config->rap_right_pre_time < MASSAGE_AIR_BAG_TIME_MS(1600))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_right_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_right_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_right_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(300))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_right_cyclic_time++;
            }
            else if (massage_config->rap_right_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(480))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_right_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_right_cyclic_time = 0;
                massage_config->rap_right_cyclic_count++;
            }
            return true;
        }
        return false;
    }
    else
    {
        //循环前的充气时间
        if (massage_config->rap_right_pre_time < MASSAGE_AIR_BAG_TIME_MS(1300))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_right_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_right_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_right_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(280))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_right_cyclic_time++;
            }
            else if (massage_config->rap_right_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(460))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_right_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_right_cyclic_time = 0;
                massage_config->rap_right_cyclic_count++;
            }
            return true;
        }
        return false;
    }
}

bool Snf_Cyclic_Left_Single_Intensity_Low(massage_config_t *massage_config)
{
    if (massage_config->support_flag)
    {
        //循环前的充气时间
        if (massage_config->rap_left_pre_time < MASSAGE_AIR_BAG_TIME_MS(1600))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_left_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_left_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_left_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(300))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_left_cyclic_time++;
            }
            else if (massage_config->rap_left_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(480))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_left_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_left_cyclic_time = 0;
                massage_config->rap_left_cyclic_count++;
            }
            return true;
        }
        return false;
    }
    else
    {
        //循环前的充气时间
        if (massage_config->rap_left_pre_time < MASSAGE_AIR_BAG_TIME_MS(1300))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_left_pre_time++;
            return true;
        }

        //循环次数
        if (massage_config->rap_left_cyclic_count < massage_config->massage_times)
        {
            if (massage_config->rap_left_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(280))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_left_cyclic_time++;
            }
            else if (massage_config->rap_left_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(460))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_UP);
                massage_config->rap_left_cyclic_time++;
            }
            else
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_config->rap_left_cyclic_time = 0;
                massage_config->rap_left_cyclic_count++;
            }
            return true;
        }
        return false;
    }
}