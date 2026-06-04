/************************ Include Files ************************/
#include "Massage.h"
#include "Basic_Config.h"
#include "Massage_Knead.h"
#include "Massage_Press.h"
#include "Massage_Rap.h"
#include "Pump.h"
#include "Rte_Log.h"
#include "Rte_Pwm_If.h"
#include "Rte_Swc.h"
#include "Valve.h"
#include "Valve_Types.h"

#include <Rte_Com.h>

#if defined(HIGH_CONFIGURATION)
/************************ Macro Definitions ************************/
#ifdef MASSAGE_PRINTF_ENABLE
#define MASSAGE_PRINTF RTE_LOG_PRINTF
#define NONE_CHANNEL   (25U)
#else
#define MASSAGE_PRINTF(...)
#endif
/************************ Private Global Variables ************************/
static massage_config_t massage_area[6] = {
    [AREA_5] = {
        .top_channel = RTE_PWM_CHANNEL_AM13,
        .right_channel = RTE_PWM_CHANNEL_AM12,
        .left_channel = RTE_PWM_CHANNEL_AM11,
        .support_channel = NONE_CHANNEL,
        .support_channel_r = NONE_CHANNEL,
        .single_channel = NONE_CHANNEL,
        .knead_inflate_time = 0,
        .knead_cyclic_count = 0,
        .knead_cyclic_time = 0,
        .knead_status = INFLATE_STATUS,
        .press_right_action_flag = NO_ACTION,
        .press_left_action_flag = NO_ACTION,
    },
    [AREA_6] = {
        .top_channel = RTE_PWM_CHANNEL_AM8,
        .right_channel = RTE_PWM_CHANNEL_AM10,
        .left_channel = RTE_PWM_CHANNEL_AM9,
        .support_channel = NONE_CHANNEL,
        .support_channel_r = NONE_CHANNEL,
        .single_channel = NONE_CHANNEL,
        .knead_inflate_time = 0,
        .knead_cyclic_count = 0,
        .knead_cyclic_time = 0,
        .knead_status = INFLATE_STATUS,
        .press_right_action_flag = NO_ACTION,
        .press_left_action_flag = NO_ACTION,
    },
    [AREA_7] = {
        .top_channel = RTE_PWM_CHANNEL_AM3,
        .right_channel = RTE_PWM_CHANNEL_AM1,
        .left_channel = RTE_PWM_CHANNEL_AM2,
        .support_channel = RTE_PWM_CHANNEL_RN1,
        .support_channel_r = RTE_PWM_CHANNEL_RNR1,
        .single_channel = NONE_CHANNEL,
        .knead_inflate_time = 0,
        .knead_cyclic_count = 0,
        .knead_cyclic_time = 0,
        .knead_status = INFLATE_STATUS,
        .press_right_action_flag = NO_ACTION,
        .press_left_action_flag = NO_ACTION,
    },
    [AREA_8] = {
        .top_channel = RTE_PWM_CHANNEL_AM4,
        .right_channel = RTE_PWM_CHANNEL_AM5,
        .left_channel = RTE_PWM_CHANNEL_AM6,
        .support_channel = RTE_PWM_CHANNEL_RN2,
        .support_channel_r = RTE_PWM_CHANNEL_RNR2,
        .single_channel = NONE_CHANNEL,
        .knead_inflate_time = 0,
        .knead_cyclic_count = 0,
        .knead_cyclic_time = 0,
        .knead_status = INFLATE_STATUS,
        .press_right_action_flag = NO_ACTION,
        .press_left_action_flag = NO_ACTION,
    },
    [AREA_9] = {
        .top_channel = NONE_CHANNEL,
        .right_channel = NONE_CHANNEL,
        .left_channel = NONE_CHANNEL,
        .support_channel = NONE_CHANNEL,
        .support_channel_r = NONE_CHANNEL,
        .single_channel = RTE_PWM_CHANNEL_AM14,
    },
    [AREA_10] = {
        .top_channel = NONE_CHANNEL,
        .right_channel = NONE_CHANNEL,
        .left_channel = NONE_CHANNEL,
        .support_channel = NONE_CHANNEL,
        .support_channel_r = NONE_CHANNEL,
        .single_channel = RTE_PWM_CHANNEL_AM7,
    }
};
massage_config_t last_massage_area[6]= {
    [AREA_5] = {
        .massage_skills = 0,
        .massage_times = 0,
        .massage_lvl = 0,
    },
    [AREA_6] = {
        .massage_skills = 0,
        .massage_times = 0,
        .massage_lvl = 0,
    },
    [AREA_7] = {
        .massage_skills = 0,
        .massage_times = 0,
        .massage_lvl = 0,
    },
    [AREA_8] = {
        .massage_skills = 0,
         .massage_times = 0,
         .massage_lvl = 0,
    },
    [AREA_9] = {
        .massage_skills = 0,
        .massage_times = 0,
        .massage_lvl = 0,
    },
    [AREA_10] = {
        .massage_skills = 0,
        .massage_times = 0,
        .massage_lvl = 0,
    }
};
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Massage_Handle(void);
static void _Snf_Massage_Action_Area_Get(void);
/************************ Private Function Implementations ************************/
static void _Snf_Massage_Action_Area_Get(void)
{
    uint8_t massage_times = 0;
    for (int i = 0; i < AREA_MAX; i++)
    {
        massage_times = 0;
        switch (i)
        {
            case AREA_5:
                #ifdef PISCES_MCM_D
                Rte_Read_DrvKneadingMassgSkillsCmd5_DrvKneadingMassgSkillsCmd5(&(massage_area[i].massage_skills));
                Rte_Read_DrvKneadingMassgLvlCmd5_DrvKneadingMassgLvlCmd5(&(massage_area[i].massage_lvl));
                Rte_Read_DrvKneadingMassgTimesCmd5_DrvKneadingMassgTimesCmd5(&massage_times);
                #endif
                #ifdef PISCES_MCM_P
                Rte_Read_PassKneadingMassgSkillsCmd5_PassKneadingMassgSkillsCmd5(&(massage_area[i].massage_skills));
                Rte_Read_PassKneadingMassgLvlCmd5_PassKneadingMassgLvlCmd5(&(massage_area[i].massage_lvl));
                Rte_Read_PassKneadingMassgTimesCmd5_PassKneadingMassgTimesCmd5(&massage_times);
                #endif

                if(massage_area[i].massage_times != massage_times)
                {
                    massage_area[i].massage_times = massage_times;
                }
                break;
            case AREA_6:
                #ifdef PISCES_MCM_D
                Rte_Read_DrvKneadingMassgSkillsCmd6_DrvKneadingMassgSkillsCmd6(&(massage_area[i].massage_skills));
                Rte_Read_DrvKneadingMassgLvlCmd6_DrvKneadingMassgLvlCmd6(&(massage_area[i].massage_lvl));
                Rte_Read_DrvKneadingMassgTimesCmd6_DrvKneadingMassgTimesCmd6(&massage_times);
                #endif
                #ifdef PISCES_MCM_P
                Rte_Read_PassKneadingMassgSkillsCmd6_PassKneadingMassgSkillsCmd6(&(massage_area[i].massage_skills));
                Rte_Read_PassKneadingMassgLvlCmd6_PassKneadingMassgLvlCmd6(&(massage_area[i].massage_lvl));
                Rte_Read_PassKneadingMassgTimesCmd6_PassKneadingMassgTimesCmd6(&massage_times);
                #endif

                if(massage_area[i].massage_times != massage_times)
                {
                    massage_area[i].massage_times = massage_times;
                }
                break;
            case AREA_7:
                #ifdef PISCES_MCM_D
                Rte_Read_DrvKneadingMassgSkillsCmd7_DrvKneadingMassgSkillsCmd7(&(massage_area[i].massage_skills));
                Rte_Read_DrvKneadingMassgLvlCmd7_DrvKneadingMassgLvlCmd7(&(massage_area[i].massage_lvl));
                Rte_Read_DrvKneadingMassgTimesCmd7_DrvKneadingMassgTimesCmd7(&massage_times);
                #endif
                #ifdef PISCES_MCM_P
                Rte_Read_PassKneadingMassgSkillsCmd7_PassKneadingMassgSkillsCmd7(&(massage_area[i].massage_skills));
                Rte_Read_PassKneadingMassgLvlCmd7_PassKneadingMassgLvlCmd7(&(massage_area[i].massage_lvl));
                Rte_Read_PassKneadingMassgTimesCmd7_PassKneadingMassgTimesCmd7(&massage_times);
                #endif

                if(massage_area[i].massage_times != massage_times)
                {
                    massage_area[i].massage_times = massage_times;
                }
                break;
            case AREA_8:
                #ifdef PISCES_MCM_D
                Rte_Read_DrvKneadingMassgSkillsCmd8_DrvKneadingMassgSkillsCmd8(&(massage_area[i].massage_skills));
                Rte_Read_DrvKneadingMassgLvlCmd8_DrvKneadingMassgLvlCmd8(&(massage_area[i].massage_lvl));
                Rte_Read_DrvKneadingMassgTimesCmd8_DrvKneadingMassgTimesCmd8(&massage_times);
                #endif
                #ifdef PISCES_MCM_P
                Rte_Read_PassKneadingMassgSkillsCmd8_PassKneadingMassgSkillsCmd8(&(massage_area[i].massage_skills));
                Rte_Read_PassKneadingMassgLvlCmd8_PassKneadingMassgLvlCmd8(&(massage_area[i].massage_lvl));
                Rte_Read_PassKneadingMassgTimesCmd8_PassKneadingMassgTimesCmd8(&massage_times);
                #endif

                if(massage_area[i].massage_times != massage_times)
                {
                    massage_area[i].massage_times = massage_times;
                }
                break;
            case AREA_9:
                #ifdef PISCES_MCM_D
                Rte_Read_DrvKneadingMassgSkillsCmd9_DrvKneadingMassgSkillsCmd9(&(massage_area[i].massage_skills));
                Rte_Read_DrvKneadingMassgLvlCmd9_DrvKneadingMassgLvlCmd9(&(massage_area[i].massage_lvl));
                Rte_Read_DrvKneadingMassgTimesCmd9_DrvKneadingMassgTimesCmd9(&massage_times);
                #endif
                #ifdef PISCES_MCM_P
                Rte_Read_PassKneadingMassgSkillsCmd9_PassKneadingMassgSkillsCmd9(&(massage_area[i].massage_skills));
                Rte_Read_PassKneadingMassgLvlCmd9_PassKneadingMassgLvlCmd9(&(massage_area[i].massage_lvl));
                Rte_Read_PassKneadingMassgTimesCmd9_PassKneadingMassgTimesCmd9(&massage_times);
                #endif

                if(massage_area[i].massage_times != massage_times)
                {
                    massage_area[i].massage_times = massage_times;
                }
                break;
            case AREA_10:
                #ifdef PISCES_MCM_D
                Rte_Read_DrvKneadingMassgSkillsCmd10_DrvKneadingMassgSkillsCmd10(&(massage_area[i].massage_skills));
                Rte_Read_DrvKneadingMassgLvlCmd10_DrvKneadingMassgLvlCmd10(&(massage_area[i].massage_lvl));
                Rte_Read_DrvKneadingMassgTimesCmd10_DrvKneadingMassgTimesCmd10(&massage_times);
                #endif
                #ifdef PISCES_MCM_P
                Rte_Read_PassKneadingMassgSkillsCmd10_PassKneadingMassgSkillsCmd10(&(massage_area[i].massage_skills));
                Rte_Read_PassKneadingMassgLvlCmd10_PassKneadingMassgLvlCmd10(&(massage_area[i].massage_lvl));
                Rte_Read_PassKneadingMassgTimesCmd10_PassKneadingMassgTimesCmd10(&massage_times);
                #endif

                if(massage_area[i].massage_times != massage_times)
                {
                    massage_area[i].massage_times = massage_times;
                }
                break;
            default:
                break;
        }
    }
}

static void _Snf_Massage_Single_Double_Get(void)
{
    if ((massage_area[AREA_5].massage_skills == massage_area[AREA_6].massage_skills)
        && (massage_area[AREA_5].massage_times == massage_area[AREA_6].massage_times)
        && (massage_area[AREA_5].massage_lvl == massage_area[AREA_6].massage_lvl))
    {
        massage_area[AREA_5].double_flag = true;
        massage_area[AREA_6].double_flag = true;
    }
    else
    {
        massage_area[AREA_5].double_flag = false;
        massage_area[AREA_6].double_flag = false;
    }
    if ((massage_area[AREA_7].massage_skills == massage_area[AREA_8].massage_skills)
        && (massage_area[AREA_7].massage_times == massage_area[AREA_8].massage_times)
        && (massage_area[AREA_7].massage_lvl == massage_area[AREA_8].massage_lvl))
    {
        massage_area[AREA_7].double_flag = true;
        massage_area[AREA_8].double_flag = true;
    }
    else
    {
        massage_area[AREA_7].double_flag = false;
        massage_area[AREA_8].double_flag = false;
    }
    if ((massage_area[AREA_9].massage_skills == massage_area[AREA_10].massage_skills)
        && (massage_area[AREA_9].massage_times == massage_area[AREA_10].massage_times)
        && (massage_area[AREA_9].massage_lvl == massage_area[AREA_10].massage_lvl))
    {
        massage_area[AREA_9].double_flag = true;
        massage_area[AREA_10].double_flag = true;
    }
    else
    {
        massage_area[AREA_9].double_flag = false;
        massage_area[AREA_10].double_flag = false;
    }
}

static void _Snf_Massage_Status_Init(massage_config_t *massage_config)
{
    //揉捏
    massage_config->knead_inflate_time = 0;
    massage_config->knead_cyclic_count = 0;
    massage_config->knead_cyclic_time = 0;
    massage_config->knead_status = INFLATE_STATUS;
    //点按
    massage_config->press_count = 0;
    massage_config->press_shoulder_time = 0;
    //叩击
    massage_config->rap_knead_status = RAP_INFLATE_STATUS;
    massage_config->rap_knead_cyclic_status = TOP_BAG;
    massage_config->rap_top_cyclic_count = 0;
    massage_config->rap_top_pre_time = 0;
    massage_config->rap_top_cyclic_time = 0;
    massage_config->rap_right_cyclic_count = 0;
    massage_config->rap_right_pre_time = 0;
    massage_config->rap_right_cyclic_time = 0;
    massage_config->rap_left_cyclic_count = 0;
    massage_config->rap_left_pre_time = 0;
    massage_config->rap_left_cyclic_time = 0;
    massage_config->rap_shoulder_status = SHOD_CYCLIC_STATUS;
    massage_config->rap_shoulder_cyclic_count = 0;
    massage_config->rap_shoulder_pre_time = 0;
    massage_config->rap_shoulder_cyclic_time = 0;
}

static void _Snf_Massage_Changed_Init(void)
{
    for (int i = 0; i < AREA_MAX; i++)
    {
        if ((last_massage_area[i].massage_lvl != massage_area[i].massage_lvl)
            || (last_massage_area[i].massage_times != massage_area[i].massage_times)
            || (last_massage_area[i].massage_skills != massage_area[i].massage_skills))
        {
            _Snf_Massage_Status_Init(&massage_area[i]);
        }
        last_massage_area[i].massage_lvl = massage_area[i].massage_lvl;
        last_massage_area[i].massage_times = massage_area[i].massage_times;
        last_massage_area[i].massage_skills = massage_area[i].massage_skills;
    }
}

static void _Snf_Massage_Reset(void)
{
    for (int i = 0; i < AREA_MAX; i++)
    {
        if (massage_area[i].massage_lvl == 0 && massage_area[i].massage_times == 0)
        {
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].top_channel, POWER_VALVE_STATE_RAMP_DOWN);
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].right_channel, POWER_VALVE_STATE_RAMP_DOWN);
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].left_channel, POWER_VALVE_STATE_RAMP_DOWN);
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].support_channel, POWER_VALVE_STATE_RAMP_DOWN);
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].support_channel_r, POWER_VALVE_STATE_RAMP_UP);
            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].single_channel, POWER_VALVE_STATE_RAMP_DOWN);
        }
    }
}

static bool _Snf_Massage_Pump_Valve_Control(void)
{
    bool pump_open_flag = false;

    for (int i = 0; i < AREA_MAX; i++)
    {
        if (massage_area[i].massage_lvl != 0 && massage_area[i].massage_times != 0 && massage_area[i].massage_skills != 0)
        {
            pump_open_flag = true;
        }
    }
    return pump_open_flag;
}
/************************ Public Function Implementations ************************/
/**
 * @brief  Initialize massage task function
 * @param  None
 * @return None
 */
void Snf_Massage_Task_Init(void)
{
    Snf_Valve_Set_Work_State(VALVE_WORK_STATE_ON, VALVE_MASSAGE_WORK_MASK);
    for (int i = 0; i < AREA_MAX; i++)
    {
        last_massage_area[i].massage_skills = 0;
        last_massage_area[i].massage_times = 0;
        last_massage_area[i].massage_lvl = 0;
    }
}

/**
 * @brief  Board Hardware Init function
 * @param  None
 * @return None
 */
static void _Snf_Massage_Handle(void)
{
    _Snf_Massage_Action_Area_Get();
    _Snf_Massage_Single_Double_Get();
    _Snf_Massage_Changed_Init();

    if (_Snf_Massage_Pump_Valve_Control())
    {
        Snf_Pump_Set_Work_State(PUMP_WORK_STATE_ON, PUMP_MASSAGE_WORK_MASK);
    }
    else
    {
        Snf_Pump_Set_Work_State(PUMP_WORK_STATE_OFF, PUMP_MASSAGE_WORK_MASK);
    }

    for (int i = 0; i < AREA_MAX; i++)
    {
        switch (massage_area[i].massage_skills)
        {
            case MASSAGE_MODE_IDLE:
                _Snf_Massage_Reset();
                break;
            case MASSAGE_MODE_KNEADING_CLOCKWISE:
                if (i == AREA_7 || i == AREA_8)
                {
                    massage_area[i].support_flag = true;
                }
                else if (i == AREA_5 || i == AREA_6)
                {
                    massage_area[i].support_flag = false;
                }
                else
                {
                    continue;
                }
                massage_area[i].clockwise = CLOCKWISE;
                _Snf_Massage_Knead_Handle(&massage_area[i]);
                break;
            case MASSAGE_MODE_KNEADING_ANTICLOCKWISE:
                if (i == AREA_5 || i == AREA_6)
                {
                    massage_area[i].support_flag = false;
                }
                else if (i == AREA_7 || i == AREA_8)
                {
                    massage_area[i].support_flag = true;
                }
                else
                {
                    continue;
                }
                massage_area[i].clockwise = ANTICLOCKWISE;
                _Snf_Massage_Knead_Handle(&massage_area[i]);
                break;
            case MASSAGE_MODE_POINT_PRESSING:
                if (i == AREA_9 || i == AREA_10)
                {
                    continue;
                }
                massage_area[i].support_flag = false;
                Snf_Massage_3_Point_Press(&massage_area[i]);
                break;
            case MASSAGE_MODE_SUPPORT_POINT_PRESSING:
                if (i == AREA_7 || i == AREA_8)
                {
                    massage_area[i].support_flag = true;
                }
                else
                {
                    continue;
                }
                Snf_Massage_3_Point_Press(&massage_area[i]);
                break;
            case MASSAGE_MODE_RAP_CLOCKWISE:
                massage_area[i].clockwise = CLOCKWISE;
                if (i == AREA_9 || i == AREA_10)
                {
                    Snf_Massgae_Shoulder_Rap(&massage_area[i]);
                }
                else
                {
                    if (i == AREA_5 || i == AREA_6)
                    {
                        massage_area[i].support_flag = false;
                    }
                    else if (i == AREA_7 || i == AREA_8)
                    {
                        massage_area[i].support_flag = true;
                    }
                    Snf_Massgae_Knead_Rap(&massage_area[i]);
                }
                break;
            case MASSAGE_MODE_RAP_ANTICLOCKWISE:
                massage_area[i].clockwise = ANTICLOCKWISE;
                if (i == AREA_9 || i == AREA_10)
                {
                    Snf_Massgae_Shoulder_Rap(&massage_area[i]);
                }
                else
                {
                    if (i == AREA_5 || i == AREA_6)
                    {
                        massage_area[i].support_flag = false;
                    }
                    else if (i == AREA_7 || i == AREA_8)
                    {
                        massage_area[i].support_flag = true;
                    }
                    Snf_Massgae_Knead_Rap(&massage_area[i]);
                }
                break;
            case MASSAGE_MODE_POINT_MASSAGE:
                if (i == AREA_5 || i == AREA_7)
                {
                    Snf_Knead_Bag_Cyclic_Press_Clockwise(&massage_area[i]);
                }
                else if (i == AREA_6 || i == AREA_8)
                {
                    Snf_Knead_Bag_Cyclic_Press_Anticlockwise(&massage_area[i]);
                }
                else
                {
                    Snf_Massage_Shoulder_Bag_Point_Press(&massage_area[i]);
                }
                break;
            default:
                break;
        }
    }
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