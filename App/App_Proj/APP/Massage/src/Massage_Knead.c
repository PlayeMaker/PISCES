/************************ Include Files ************************/
#include "Basic_Config.h"
#include "Massage_Knead.h"
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
        if (massage_config->knead_inflate_time < MASSAGE_AIR_BAG_TIME_MS(6000))
        {
            if (massage_config->knead_inflate_time < MASSAGE_AIR_BAG_TIME_MS(2000))
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
        if (massage_config->knead_inflate_time < MASSAGE_AIR_BAG_TIME_MS(3500))
        {
            ALL_INFLATE();
            massage_config->knead_inflate_time++;
            return true;
        }
        massage_config->knead_inflate_time = 0;
        return false;
    }
}

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
        if (massage_config->knead_inflate_time < MASSAGE_AIR_BAG_TIME_MS(7000))
        {
            if (massage_config->knead_inflate_time < MASSAGE_AIR_BAG_TIME_MS(2500))
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
        if (massage_config->knead_inflate_time < MASSAGE_AIR_BAG_TIME_MS(4000))
        {
            ALL_INFLATE();
            massage_config->knead_inflate_time++;
            return true;
        }
        massage_config->knead_inflate_time = 0;
        return false;
    }
}

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
        if (massage_config->knead_inflate_time < MASSAGE_AIR_BAG_TIME_MS(3500))
        {
            if (massage_config->knead_inflate_time < MASSAGE_AIR_BAG_TIME_MS(1500))
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
        if (massage_config->knead_inflate_time < MASSAGE_AIR_BAG_TIME_MS(2000))
        {
            ALL_INFLATE();
            massage_config->knead_inflate_time++;
            return true;
        }
        massage_config->knead_inflate_time = 0;
        return false;
    }
}

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
        if (massage_config->knead_inflate_time < MASSAGE_AIR_BAG_TIME_MS(5000))
        {
            if (massage_config->knead_inflate_time < MASSAGE_AIR_BAG_TIME_MS(2000))
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
        if (massage_config->knead_inflate_time < MASSAGE_AIR_BAG_TIME_MS(2500))
        {
            ALL_INFLATE();
            massage_config->knead_inflate_time++;
            return true;
        }
        massage_config->knead_inflate_time = 0;
        return false;
    }
}

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

static bool _Snf_Knead_Cyclic_Intensity_Low(massage_config_t *massage_config)
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
            if (massage_config->knead_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(700))
            {
                TOP_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(1400))
            {
                RIGHT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if ( massage_config->knead_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(2100))
            {
                LEFT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time >= MASSAGE_AIR_BAG_TIME_MS(2100))
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
            if (massage_config->knead_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(700))
            {
                TOP_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(1400))
            {
                LEFT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(2100))
            {
                RIGHT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time >= MASSAGE_AIR_BAG_TIME_MS(2100))
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

static bool _Snf_Knead_Cyclic_Intensity_High(massage_config_t *massage_config)
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
            if (massage_config->knead_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(500))
            {
                TOP_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(1000))
            {
                RIGHT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(1500))
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
            if (massage_config->knead_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(500))
            {
                TOP_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(1000))
            {
                LEFT_DEFLATE();
                massage_config->knead_cyclic_time++;
            }
            else if (massage_config->knead_cyclic_time < MASSAGE_AIR_BAG_TIME_MS(1500))
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

static bool _Snf_Knead_Cyclic(massage_config_t *massage_config)
{
    if (massage_config->double_flag)
    {

    }
    if (massage_config->massage_lvl == MASSAGE_INTENSITY_LOW)
    {
        return _Snf_Knead_Cyclic_Intensity_Low(massage_config);
    }
    else if (massage_config->massage_lvl == MASSAGE_INTENSITY_HIGH)
    {
        return _Snf_Knead_Cyclic_Intensity_High(massage_config);
    }
}

static bool _Snf_Knead_Deflate(massage_config_t *massage_config)
{
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->top_channel, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->right_channel, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->left_channel, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_config->support_channel_r, POWER_VALVE_STATE_RAMP_UP);
}
/************************ Public Function Implementations ************************/
void _Snf_Massage_Knead_Handle(massage_config_t *massage_config)
{
    if (massage_config->massage_lvl == MASSAGE_INTENSITY_IDLE || massage_config->massage_times == 0)
    {
        return;
    }

    switch (massage_config->knead_status)
    {
        case INFLATE_STATUS:
            if (!_Snf_Knead_Inflate(massage_config))
            {
                massage_config->knead_status = CYCLIC_STATUS;
            }
            break;
        case CYCLIC_STATUS:
            if (!_Snf_Knead_Cyclic(massage_config) )
            {
                massage_config->knead_status = DEFLATE_STATUS;
            }
            break;
        case DEFLATE_STATUS:
            _Snf_Knead_Deflate(massage_config);
            break;
        default:
            break;
    }
}
