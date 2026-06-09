#include "Rte_Swc.h"
#include "Massage_Rap.h"
#include "Massage_Rap_Cyclic.h"

/***********************************双区域强度高************************************************************/
static bool _Snf_Knead_Rap_Inflate_Double_Intensity_High(massage_config_t *massage_config)
{
    if (!massage_config->support_flag)
    {
        return false;
    }
    if (massage_config->rap_inflate_time < MASSAGE_AIR_BAG_TIME_MS(2500))
    {
        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_UP);
        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN);
        massage_config->rap_inflate_time++;
        return true;
    }

    massage_config->rap_inflate_time = 0;
    return false;
}

static bool _Snf_Knead_Rap_Cyclic_Double_Intensity_High(massage_config_t *massage_config)
{
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN);

    if (massage_config->clockwise == CLOCKWISE)
    {
        switch (massage_config->rap_knead_cyclic_status)
        {
            case TOP_BAG:
                if (!Snf_Cyclic_Top_Double_Intensity_High(massage_config))
                {
                    massage_config->rap_knead_cyclic_status = RIGHT_BAG;
                }
                break;
            case RIGHT_BAG:
                if (!Snf_Cyclic_Right_Double_Intensity_High(massage_config))
                {
                    massage_config->rap_knead_cyclic_status = LEFT_BAG;
                }
                break;
            case LEFT_BAG:
                if (!Snf_Cyclic_Left_Double_Intensity_High(massage_config))
                {
                    return false;
                }
                break;
            default:
                break;
        }
    }
    else
    {
        switch (massage_config->rap_knead_cyclic_status)
        {
            case TOP_BAG:
                if (!Snf_Cyclic_Top_Double_Intensity_High(massage_config))
                {
                    massage_config->rap_knead_cyclic_status = LEFT_BAG;
                }
                break;
            case LEFT_BAG:
                if (!Snf_Cyclic_Left_Double_Intensity_High(massage_config))
                {
                    massage_config->rap_knead_cyclic_status = RIGHT_BAG;
                }
                break;
            case RIGHT_BAG:
                if (!Snf_Cyclic_Right_Double_Intensity_High(massage_config))
                {
                    return false;
                }
                break;
            default:
                break;
        }
    }

    return true;
}

/***********************************双区域强度低************************************************************/
static bool _Snf_Knead_Rap_Inflate_Double_Intensity_Low(massage_config_t *massage_config)
{
    if (!massage_config->support_flag)
    {
        return false;
    }
    if (massage_config->rap_inflate_time < MASSAGE_AIR_BAG_TIME_MS(2000))
    {
        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_UP);
        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN);
        massage_config->rap_inflate_time++;
        return true;
    }

    massage_config->rap_inflate_time = 0;
    return false;
}

static bool _Snf_Knead_Rap_Cyclic_Double_Intensity_Low(massage_config_t *massage_config)
{
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN);

    if (massage_config->clockwise == CLOCKWISE)
    {
        switch (massage_config->rap_knead_cyclic_status)
        {
            case TOP_BAG:
                if (!Snf_Cyclic_Top_Double_Intensity_High(massage_config))
                {
                    massage_config->rap_knead_cyclic_status = RIGHT_BAG;
                }
                break;
            case RIGHT_BAG:
                if (!Snf_Cyclic_Right_Double_Intensity_High(massage_config))
                {
                    massage_config->rap_knead_cyclic_status = LEFT_BAG;
                }
                break;
            case LEFT_BAG:
                if (!Snf_Cyclic_Left_Double_Intensity_High(massage_config))
                {
                    return false;
                }
                break;
            default:
                break;
        }
    }
    else
    {
        switch (massage_config->rap_knead_cyclic_status)
        {
            case TOP_BAG:
                if (!Snf_Cyclic_Top_Double_Intensity_High(massage_config))
                {
                    massage_config->rap_knead_cyclic_status = LEFT_BAG;
                }
                break;
            case LEFT_BAG:
                if (!Snf_Cyclic_Left_Double_Intensity_High(massage_config))
                {
                    massage_config->rap_knead_cyclic_status = RIGHT_BAG;
                }
                break;
            case RIGHT_BAG:
                if (!Snf_Cyclic_Right_Double_Intensity_High(massage_config))
                {
                    return false;
                }
                break;
            default:
                break;
        }
    }

    return true;
}

/***********************************单区域强度高************************************************************/
static bool _Snf_Knead_Rap_Inflate_Single_Intensity_High(massage_config_t *massage_config)
{
    if (!massage_config->support_flag)
    {
        return false;
    }
    if (massage_config->rap_inflate_time < MASSAGE_AIR_BAG_TIME_MS(1800))
    {
        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_UP);
        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN);
        massage_config->rap_inflate_time++;
        return true;
    }

    massage_config->rap_inflate_time = 0;
    return false;
}

static bool _Snf_Knead_Rap_Cyclic_Single_Intensity_High(massage_config_t *massage_config)
{
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN);

    if (massage_config->clockwise == CLOCKWISE)
    {
        switch (massage_config->rap_knead_cyclic_status)
        {
            case TOP_BAG:
                if (!Snf_Cyclic_Top_Single_Intensity_High(massage_config))
                {
                    massage_config->rap_knead_cyclic_status = RIGHT_BAG;
                }
                break;
            case RIGHT_BAG:
                if (!Snf_Cyclic_Right_Single_Intensity_High(massage_config))
                {
                    massage_config->rap_knead_cyclic_status = LEFT_BAG;
                }
                break;
            case LEFT_BAG:
                if (!Snf_Cyclic_Left_Single_Intensity_High(massage_config))
                {
                    return false;
                }
                break;
            default:
                break;
        }
    }
    else
    {
        switch (massage_config->rap_knead_cyclic_status)
        {
            case TOP_BAG:
                if (!Snf_Cyclic_Top_Single_Intensity_High(massage_config))
                {
                    massage_config->rap_knead_cyclic_status = LEFT_BAG;
                }
                break;
            case LEFT_BAG:
                if (!Snf_Cyclic_Left_Single_Intensity_High(massage_config))
                {
                    massage_config->rap_knead_cyclic_status = RIGHT_BAG;
                }
                break;
            case RIGHT_BAG:
                if (!Snf_Cyclic_Right_Single_Intensity_High(massage_config))
                {
                    return false;
                }
                break;
            default:
                break;
        }
    }

    return true;
}

/***********************************单区域强度低************************************************************/
static bool _Snf_Knead_Rap_Inflate_Single_Intensity_Low(massage_config_t *massage_config)
{
    if (!massage_config->support_flag)
    {
        return false;
    }
    if (massage_config->rap_inflate_time < MASSAGE_AIR_BAG_TIME_MS(1500))
    {
        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_UP);
        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN);
        massage_config->rap_inflate_time++;
        return true;
    }

    massage_config->rap_inflate_time = 0;
    return false;
}

static bool _Snf_Knead_Rap_Cyclic_Single_Intensity_Low(massage_config_t *massage_config)
{
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_DOWN);

    if (massage_config->clockwise == CLOCKWISE)
    {
        switch (massage_config->rap_knead_cyclic_status)
        {
            case TOP_BAG:
                if (!Snf_Cyclic_Top_Single_Intensity_Low(massage_config))
                {
                    massage_config->rap_knead_cyclic_status = RIGHT_BAG;
                }
                break;
            case RIGHT_BAG:
                if (!Snf_Cyclic_Right_Single_Intensity_Low(massage_config))
                {
                    massage_config->rap_knead_cyclic_status = LEFT_BAG;
                }
                break;
            case LEFT_BAG:
                if (!Snf_Cyclic_Left_Single_Intensity_Low(massage_config))
                {
                    return false;
                }
                break;
            default:
                break;
        }
    }
    else
    {
        switch (massage_config->rap_knead_cyclic_status)
        {
            case TOP_BAG:
                if (!Snf_Cyclic_Top_Single_Intensity_Low(massage_config))
                {
                    massage_config->rap_knead_cyclic_status = LEFT_BAG;
                }
                break;
            case LEFT_BAG:
                if (!Snf_Cyclic_Left_Single_Intensity_Low(massage_config))
                {
                    massage_config->rap_knead_cyclic_status = RIGHT_BAG;
                }
                break;
            case RIGHT_BAG:
                if (!Snf_Cyclic_Right_Single_Intensity_Low(massage_config))
                {
                    return false;
                }
                break;
            default:
                break;
        }
    }

    return true;
}

static bool _Snf_Knead_Rap_Deflate(massage_config_t *massage_config)
{
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_UP);
}

void Snf_Massgae_Knead_Rap_TimeCalc(massage_config_t *massage_config)
{
    if (massage_config->double_flag)
    {
        if (massage_config->support_flag)
        {
            if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
            {
                massage_config->massage_output_time = 20 + 24 * 3 + (3 + 1) * massage_config->massage_times * 3;
            }
            else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
            {
                massage_config->massage_output_time = 25 + 30 * 3 + (2 + 1) * massage_config->massage_times * 3;
            }
        }
        else
        {
            if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
            {
                massage_config->massage_output_time = 20 + 21 * 3 + (3 + 2) * massage_config->massage_times * 3;
            }
            else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
            {
                massage_config->massage_output_time = 25 + 27 * 3 + (2 + 1) * massage_config->massage_times * 3;
            }
        }
    }
    else
    {
        if (massage_config->support_flag)
        {
            if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
            {
                massage_config->massage_output_time = 15 + 16 * 3 + (3 + 2) * massage_config->massage_times * 3;
            }
            else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
            {
                massage_config->massage_output_time = 18 + 18 * 3 + (2 + 1) * massage_config->massage_times * 3;
            }
        }
        else
        {
            if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
            {
                massage_config->massage_output_time = 12 + 13 * 3 + (3 + 2) * massage_config->massage_times * 3;
            }
            else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
            {
                massage_config->massage_output_time = 15 + 16 * 3 + (2 + 1) * massage_config->massage_times * 3;
            }
        }
    }
}
/************************ Public Function Implementations ************************/
void Snf_Massgae_Knead_Rap(massage_config_t *massage_config)
{
    if (massage_config->massage_lvl == MASSAGE_INTENSITY_IDLE || massage_config->massage_times == 0)
    {
        massage_config->massage_output_time = 0;
        return;
    }

    Snf_Massgae_Knead_Rap_TimeCalc(massage_config);

    if (massage_config->double_flag)
    {
        if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
        {
            switch (massage_config->rap_knead_status)
            {
                case RAP_INFLATE_STATUS:
                    if (!_Snf_Knead_Rap_Inflate_Double_Intensity_Low(massage_config))
                    {
                        massage_config->rap_knead_status = RAP_CYCLIC_STATUS;
                    }
                    break;
                case RAP_CYCLIC_STATUS:
                    if (!_Snf_Knead_Rap_Cyclic_Double_Intensity_Low(massage_config))
                    {
                        massage_config->rap_knead_status = RAP_DEFLATE_STATUS;
                    }
                    break;
                case RAP_DEFLATE_STATUS:
                    _Snf_Knead_Rap_Deflate(massage_config);
                    break;
                default:
                    break;
            }
        }
        else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
        {
            switch (massage_config->rap_knead_status)
            {
                case RAP_INFLATE_STATUS:
                    if (!_Snf_Knead_Rap_Inflate_Double_Intensity_High(massage_config))
                    {
                        massage_config->rap_knead_status = RAP_CYCLIC_STATUS;
                    }
                    break;
                case RAP_CYCLIC_STATUS:
                    if (!_Snf_Knead_Rap_Cyclic_Double_Intensity_High(massage_config))
                    {
                        massage_config->rap_knead_status = RAP_DEFLATE_STATUS;
                    }
                    break;
                case RAP_DEFLATE_STATUS:
                    _Snf_Knead_Rap_Deflate(massage_config);
                    break;
                default:
                    break;
            }
        }
    }
    else
    {
        if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
        {
            switch (massage_config->rap_knead_status)
            {
                case RAP_INFLATE_STATUS:
                    if (!_Snf_Knead_Rap_Inflate_Single_Intensity_Low(massage_config))
                    {
                        massage_config->rap_knead_status = RAP_CYCLIC_STATUS;
                    }
                    break;
                case RAP_CYCLIC_STATUS:
                    if (!_Snf_Knead_Rap_Cyclic_Single_Intensity_Low(massage_config))
                    {
                        massage_config->rap_knead_status = RAP_DEFLATE_STATUS;
                    }
                    break;
                case RAP_DEFLATE_STATUS:
                    _Snf_Knead_Rap_Deflate(massage_config);
                    break;
                default:
                    break;
            }
        }
        else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
        {
            switch (massage_config->rap_knead_status)
            {
                case RAP_INFLATE_STATUS:
                    if (!_Snf_Knead_Rap_Inflate_Single_Intensity_High(massage_config))
                    {
                        massage_config->rap_knead_status = RAP_CYCLIC_STATUS;
                    }
                    break;
                case RAP_CYCLIC_STATUS:
                    if (!_Snf_Knead_Rap_Cyclic_Single_Intensity_High(massage_config))
                    {
                        massage_config->rap_knead_status = RAP_DEFLATE_STATUS;
                    }
                    break;
                case RAP_DEFLATE_STATUS:
                    _Snf_Knead_Rap_Deflate(massage_config);
                    break;
                default:
                    break;
            }
        }
    }
}

static bool _Snf_Shoulder_Rap_Cyclic(massage_config_t *massage_config)
{

    //循环前的充气时间
    if (massage_config->rap_shoulder_pre_time < MASSAGE_AIR_BAG_TIME_MS(2500))
    {
        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->single_channel, POWER_VALVE_STATE_RAMP_UP);
        massage_config->rap_shoulder_pre_time++;
        return true;
    }

    //循环次数
    if (massage_config->rap_shoulder_cyclic_count < massage_config->massage_times)
    {
        if (massage_config->rap_shoulder_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(200))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->single_channel, POWER_VALVE_STATE_RAMP_DOWN);
            massage_config->rap_shoulder_cyclic_time++;
        }
        else if (massage_config->rap_shoulder_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(420))
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->single_channel, POWER_VALVE_STATE_RAMP_UP);
            massage_config->rap_shoulder_cyclic_time++;
        }
        else
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->single_channel, POWER_VALVE_STATE_RAMP_DOWN);
            massage_config->rap_shoulder_cyclic_time = 0;
            massage_config->rap_shoulder_cyclic_count++;
        }
        return true;
    }
    return false;
}

static bool _Snf_Shoulder_Rap_End(massage_config_t *massage_config)
{
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->single_channel, POWER_VALVE_STATE_RAMP_DOWN);
}

static void _Snf_Shoulder_Rap_TimeCalc(massage_config_t *massage_config)
{
    if (massage_config->double_flag)
    {
        if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
        {
            massage_config->massage_output_time = 25 + (2 + 2) * massage_config->massage_times;
        }
        else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
        {
            massage_config->massage_output_time = 30 + (2 + 1) * massage_config->massage_times;
        }
    }
    else
    {
        if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
        {
            massage_config->massage_output_time = 40 + (3 + 2) * massage_config->massage_times;
        }
        else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
        {
            massage_config->massage_output_time = 50 + (2 + 1) * massage_config->massage_times;
        }
    }
}

void Snf_Massgae_Shoulder_Rap(massage_config_t *massage_config)
{
    if (massage_config->massage_lvl == MASSAGE_INTENSITY_IDLE || massage_config->massage_times == 0)
    {
        massage_config->massage_output_time = 0;
        return;
    }

    _Snf_Shoulder_Rap_TimeCalc(massage_config);

    switch (massage_config->rap_shoulder_status)
    {
        case SHOD_CYCLIC_STATUS:
            if (!_Snf_Shoulder_Rap_Cyclic(massage_config))
            {
                massage_config->rap_shoulder_status = SHOD_END_STATUS;
            }
            break;
        case SHOD_END_STATUS:
            _Snf_Shoulder_Rap_End(massage_config);
            break;
        default:
            break;
    }
}