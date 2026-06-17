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
#include "Rte_Os.h"

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
        .knead_status = KNEAD_INFLATE_STATUS,
        .press_right_action_flag = NO_ACTION,
        .press_left_action_flag = NO_ACTION,
        .valve_close_time = 0,
        .valve_close_flag = true,
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
        .knead_status = KNEAD_INFLATE_STATUS,
        .press_right_action_flag = NO_ACTION,
        .press_left_action_flag = NO_ACTION,
        .valve_close_time = 0,
        .valve_close_flag = true,
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
        .knead_status = KNEAD_INFLATE_STATUS,
        .press_right_action_flag = NO_ACTION,
        .press_left_action_flag = NO_ACTION,
        .valve_close_time = 0,
        .valve_close_flag = true,
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
        .knead_status = KNEAD_INFLATE_STATUS,
        .press_right_action_flag = NO_ACTION,
        .press_left_action_flag = NO_ACTION,
        .valve_close_time = 0,
        .valve_close_flag = true,
    },
    [AREA_9] = {
        .top_channel = NONE_CHANNEL,
        .right_channel = NONE_CHANNEL,
        .left_channel = NONE_CHANNEL,
        .support_channel = NONE_CHANNEL,
        .support_channel_r = NONE_CHANNEL,
        .single_channel = RTE_PWM_CHANNEL_AM14,
        .valve_close_time = 0,
        .valve_close_flag = true,
    },
    [AREA_10] = {
        .top_channel = NONE_CHANNEL,
        .right_channel = NONE_CHANNEL,
        .left_channel = NONE_CHANNEL,
        .support_channel = NONE_CHANNEL,
        .support_channel_r = NONE_CHANNEL,
        .single_channel = RTE_PWM_CHANNEL_AM7,
        .valve_close_time = 0,
        .valve_close_flag = true,
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
/************************ Private Function Implementations ************************/
/**
 * @brief  Get every area action from singles
 * @param  None
 * @return None
 */
static void _Snf_Massage_Action_Area_Get(void)
{
    uint8 massage_skills = 0;
    uint8 massage_lvl = 0;
    uint8 massage_times = 0;
    for (int i = 0; i < AREA_MAX; i++)
    {
        switch (i)
        {
            case AREA_5:
                #ifdef PISCES_MCM_D
                Rte_Read_DrvKneadingMassgSkillsCmd5_DrvKneadingMassgSkillsCmd5(&massage_skills);
                Rte_Read_DrvKneadingMassgLvlCmd5_DrvKneadingMassgLvlCmd5(&massage_lvl);
                Rte_Read_DrvKneadingMassgTimesCmd5_DrvKneadingMassgTimesCmd5(&massage_times);
                #endif
                #ifdef PISCES_MCM_P
                Rte_Read_PassKneadingMassgSkillsCmd5_PassKneadingMassgSkillsCmd5(&massage_skills);
                Rte_Read_PassKneadingMassgLvlCmd5_PassKneadingMassgLvlCmd5(&massage_lvl);
                Rte_Read_PassKneadingMassgTimesCmd5_PassKneadingMassgTimesCmd5(&massage_times);
                #endif
                if ((massage_skills != 0 && massage_times != 0 && massage_lvl != 0)
                    || (massage_skills == 0 && massage_times == 0 && massage_lvl == 0))
                {
                    massage_area[i].massage_skills = massage_skills;
                    massage_area[i].massage_lvl = massage_lvl;
                    massage_area[i].massage_times = massage_times;
                }
                break;
            case AREA_6:
                #ifdef PISCES_MCM_D
                Rte_Read_DrvKneadingMassgSkillsCmd6_DrvKneadingMassgSkillsCmd6(&massage_skills);
                Rte_Read_DrvKneadingMassgLvlCmd6_DrvKneadingMassgLvlCmd6(&massage_lvl);
                Rte_Read_DrvKneadingMassgTimesCmd6_DrvKneadingMassgTimesCmd6(&massage_times);
                #endif
                #ifdef PISCES_MCM_P
                Rte_Read_PassKneadingMassgSkillsCmd6_PassKneadingMassgSkillsCmd6(&massage_skills);
                Rte_Read_PassKneadingMassgLvlCmd6_PassKneadingMassgLvlCmd6(&massage_lvl);
                Rte_Read_PassKneadingMassgTimesCmd6_PassKneadingMassgTimesCmd6(&massage_times);
                #endif
                if ((massage_skills != 0 && massage_times != 0 && massage_lvl != 0)
                    || (massage_skills == 0 && massage_times == 0 && massage_lvl == 0))
                {
                    massage_area[i].massage_skills = massage_skills;
                    massage_area[i].massage_lvl = massage_lvl;
                    massage_area[i].massage_times = massage_times;
                }
                break;
            case AREA_7:
                #ifdef PISCES_MCM_D
                Rte_Read_DrvKneadingMassgSkillsCmd7_DrvKneadingMassgSkillsCmd7(&massage_skills);
                Rte_Read_DrvKneadingMassgLvlCmd7_DrvKneadingMassgLvlCmd7(&massage_lvl);
                Rte_Read_DrvKneadingMassgTimesCmd7_DrvKneadingMassgTimesCmd7(&massage_times);
                #endif
                #ifdef PISCES_MCM_P
                Rte_Read_PassKneadingMassgSkillsCmd7_PassKneadingMassgSkillsCmd7(&massage_skills);
                Rte_Read_PassKneadingMassgLvlCmd7_PassKneadingMassgLvlCmd7(&massage_lvl);
                Rte_Read_PassKneadingMassgTimesCmd7_PassKneadingMassgTimesCmd7(&massage_times);
                #endif
                if ((massage_skills != 0 && massage_times != 0 && massage_lvl != 0)
                    || (massage_skills == 0 && massage_times == 0 && massage_lvl == 0))
                {
                    massage_area[i].massage_skills = massage_skills;
                    massage_area[i].massage_lvl = massage_lvl;
                    massage_area[i].massage_times = massage_times;
                }
                break;
            case AREA_8:
                #ifdef PISCES_MCM_D
                Rte_Read_DrvKneadingMassgSkillsCmd8_DrvKneadingMassgSkillsCmd8(&massage_skills);
                Rte_Read_DrvKneadingMassgLvlCmd8_DrvKneadingMassgLvlCmd8(&massage_lvl);
                Rte_Read_DrvKneadingMassgTimesCmd8_DrvKneadingMassgTimesCmd8(&massage_times);
                #endif
                #ifdef PISCES_MCM_P
                Rte_Read_PassKneadingMassgSkillsCmd8_PassKneadingMassgSkillsCmd8(&massage_skills);
                Rte_Read_PassKneadingMassgLvlCmd8_PassKneadingMassgLvlCmd8(&massage_lvl);
                Rte_Read_PassKneadingMassgTimesCmd8_PassKneadingMassgTimesCmd8(&massage_times);
                #endif
                if ((massage_skills != 0 && massage_times != 0 && massage_lvl != 0)
                    || (massage_skills == 0 && massage_times == 0 && massage_lvl == 0))
                {
                    massage_area[i].massage_skills = massage_skills;
                    massage_area[i].massage_lvl = massage_lvl;
                    massage_area[i].massage_times = massage_times;
                }
                break;
            case AREA_9:
                #ifdef PISCES_MCM_D
                Rte_Read_DrvKneadingMassgSkillsCmd9_DrvKneadingMassgSkillsCmd9(&massage_skills);
                Rte_Read_DrvKneadingMassgLvlCmd9_DrvKneadingMassgLvlCmd9(&massage_lvl);
                Rte_Read_DrvKneadingMassgTimesCmd9_DrvKneadingMassgTimesCmd9(&massage_times);
                #endif
                #ifdef PISCES_MCM_P
                Rte_Read_PassKneadingMassgSkillsCmd9_PassKneadingMassgSkillsCmd9(&massage_skills);
                Rte_Read_PassKneadingMassgLvlCmd9_PassKneadingMassgLvlCmd9(&massage_lvl);
                Rte_Read_PassKneadingMassgTimesCmd9_PassKneadingMassgTimesCmd9(&massage_times);
                #endif
                if ((massage_skills != 0 && massage_times != 0 && massage_lvl != 0)
                    || (massage_skills == 0 && massage_times == 0 && massage_lvl == 0))
                {
                    massage_area[i].massage_skills = massage_skills;
                    massage_area[i].massage_lvl = massage_lvl;
                    massage_area[i].massage_times = massage_times;
                }
                break;
            case AREA_10:
                #ifdef PISCES_MCM_D
                Rte_Read_DrvKneadingMassgSkillsCmd10_DrvKneadingMassgSkillsCmd10(&massage_skills);
                Rte_Read_DrvKneadingMassgLvlCmd10_DrvKneadingMassgLvlCmd10(&massage_lvl);
                Rte_Read_DrvKneadingMassgTimesCmd10_DrvKneadingMassgTimesCmd10(&massage_times);
                #endif
                #ifdef PISCES_MCM_P
                Rte_Read_PassKneadingMassgSkillsCmd10_PassKneadingMassgSkillsCmd10(&massage_skills);
                Rte_Read_PassKneadingMassgLvlCmd10_PassKneadingMassgLvlCmd10(&massage_lvl);
                Rte_Read_PassKneadingMassgTimesCmd10_PassKneadingMassgTimesCmd10(&massage_times);
                #endif
                if ((massage_skills != 0 && massage_times != 0 && massage_lvl != 0)
                    || (massage_skills == 0 && massage_times == 0 && massage_lvl == 0))
                {
                    massage_area[i].massage_skills = massage_skills;
                    massage_area[i].massage_lvl = massage_lvl;
                    massage_area[i].massage_times = massage_times;
                }
                break;
            default:
                break;
        }
    }
}

/**
 * @brief  Get every area single or double action
 * @param  None
 * @return None
 */
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

/**
 * @brief  Init every area status
 * @param  None
 * @return None
 */
static void _Snf_Massage_Status_Init(massage_config_t *massage_config)
{
    //揉捏
    massage_config->knead_inflate_time = 0;
    massage_config->knead_cyclic_count = 0;
    massage_config->knead_cyclic_time = 0;
    massage_config->knead_status = KNEAD_INFLATE_STATUS;
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

/**
 * @brief  Reset every area status
 * @param  None
 * @return None
 */
static void _Snf_Massage_Status_Reset(void)
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

/**
 * @brief  Close each area massage
 * @param  None
 * @return None
 */
static void _Snf_Massage_Close(void)
{
    for (int i = 0; i < AREA_MAX; i++)
    {
        if (massage_area[i].massage_lvl == 0 && massage_area[i].massage_times == 0)
        {
            massage_area[i].massage_output_time = 0;
            if (massage_area[i].valve_close_time >= MASSAGE_TIME_MS(30000))
            {
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].support_channel, POWER_VALVE_STATE_RAMP_DOWN);
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].support_channel_r, POWER_VALVE_STATE_RAMP_DOWN);
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].single_channel, POWER_VALVE_STATE_RAMP_DOWN);
                massage_area[i].valve_close_flag = true;
            }
            else
            {
                massage_area[i].valve_close_time++;
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].top_channel, POWER_VALVE_STATE_RAMP_DOWN);
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].right_channel, POWER_VALVE_STATE_RAMP_DOWN);
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].left_channel, POWER_VALVE_STATE_RAMP_DOWN);
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].support_channel, POWER_VALVE_STATE_RAMP_DOWN);
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].support_channel_r, POWER_VALVE_STATE_RAMP_UP);
                Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(massage_area[i].single_channel, POWER_VALVE_STATE_RAMP_DOWN);
            }
        }
    }
}

/**
 * @brief  Control pump and valve
 * @param  None
 * @return None
 */
static void _Snf_Massage_Pump_Valve_Control(void)
{
#define CLOSE                  0
#define OPEN                   1
#define PUMP_CLOSE             0b00
#define PUMP_OPEN              0b10
#define VALVE_OPEN             0b01
#define VALVE_CLOSE            0b00

    uint8 pump_valve_control_flag = 0;

    for (int i = 0; i < AREA_MAX; i++)
    {
        if (massage_area[i].massage_lvl != 0 && massage_area[i].massage_times != 0 && massage_area[i].massage_skills != 0)
        {
            pump_valve_control_flag = pump_valve_control_flag | PUMP_OPEN;
        }
        if (massage_area[i].valve_close_flag == false)
        {
            pump_valve_control_flag = pump_valve_control_flag | VALVE_OPEN;
        }
    }

    if (pump_valve_control_flag >> 1)
    {
        Snf_Pump_Set_Work_State(PUMP_WORK_STATE_ON, PUMP_MASSAGE_WORK_MASK);
    }
    else
    {
        Snf_Pump_Set_Work_State(PUMP_WORK_STATE_OFF, PUMP_MASSAGE_WORK_MASK);
    }

    if (pump_valve_control_flag & 0b01)
    {
        Snf_Valve_Set_Work_State(VALVE_WORK_STATE_ON, VALVE_MASSAGE_WORK_MASK);
    }
    else
    {
        Snf_Valve_Set_Work_State(VALVE_WORK_STATE_OFF, VALVE_MASSAGE_WORK_MASK);
    }
}

/**
 * @brief  Massage can output
 * @param  None
 * @return None
 */
static void _Snf_Massage_Output(void)
{
    //手法外发
    #ifdef PISCES_MCM_D
    Rte_Write_DrvKneadingMassgSkillsSts10_DrvKneadingMassgSkillsSts10(massage_area[AREA_10].massage_skills);
    Rte_Write_DrvKneadingMassgSkillsSts5_DrvKneadingMassgSkillsSts5(massage_area[AREA_5].massage_skills);
    Rte_Write_DrvKneadingMassgSkillsSts6_DrvKneadingMassgSkillsSts6(massage_area[AREA_6].massage_skills);
    Rte_Write_DrvKneadingMassgSkillsSts7_DrvKneadingMassgSkillsSts7(massage_area[AREA_7].massage_skills);
    Rte_Write_DrvKneadingMassgSkillsSts8_DrvKneadingMassgSkillsSts8(massage_area[AREA_8].massage_skills);
    Rte_Write_DrvKneadingMassgSkillsSts9_DrvKneadingMassgSkillsSts9(massage_area[AREA_9].massage_skills);
    #endif
    #ifdef PISCES_MCM_P
    Rte_Write_PassKneadingMassgSkillsSts10_PassKneadingMassgSkillsSts10(massage_area[AREA_10].massage_skills);
    Rte_Write_PassKneadingMassgSkillsSts5_PassKneadingMassgSkillsSts5(massage_area[AREA_5].massage_skills);
    Rte_Write_PassKneadingMassgSkillsSts6_PassKneadingMassgSkillsSts6(massage_area[AREA_6].massage_skills);
    Rte_Write_PassKneadingMassgSkillsSts7_PassKneadingMassgSkillsSts7(massage_area[AREA_7].massage_skills);
    Rte_Write_PassKneadingMassgSkillsSts8_PassKneadingMassgSkillsSts8(massage_area[AREA_8].massage_skills);
    Rte_Write_PassKneadingMassgSkillsSts9_PassKneadingMassgSkillsSts9(massage_area[AREA_9].massage_skills);
    #endif

    //挡位外发
    #ifdef PISCES_MCM_D
    Rte_Write_DrvKneadingMassglvlSts10_DrvKneadingMassglvlSts10(massage_area[AREA_10].massage_lvl);
    Rte_Write_DrvKneadingMassglvlSts5_DrvKneadingMassglvlSts5(massage_area[AREA_5].massage_lvl);
    Rte_Write_DrvKneadingMassglvlSts6_DrvKneadingMassglvlSts6(massage_area[AREA_6].massage_lvl);
    Rte_Write_DrvKneadingMassglvlSts7_DrvKneadingMassglvlSts7(massage_area[AREA_7].massage_lvl);
    Rte_Write_DrvKneadingMassglvlSts8_DrvKneadingMassglvlSts8(massage_area[AREA_8].massage_lvl);
    Rte_Write_DrvKneadingMassglvlSts9_DrvKneadingMassglvlSts9(massage_area[AREA_9].massage_lvl);
    #endif
    #ifdef PISCES_MCM_P
    Rte_Write_PassKneadingMassgLvlSts10_PassKneadingMassgLvlSts10(massage_area[AREA_10].massage_lvl);
    Rte_Write_PassKneadingMassgLvlSts5_PassKneadingMassgLvlSts5(massage_area[AREA_5].massage_lvl);
    Rte_Write_PassKneadingMassgLvlSts6_PassKneadingMassgLvlSts6(massage_area[AREA_6].massage_lvl);
    Rte_Write_PassKneadingMassgLvlSts7_PassKneadingMassgLvlSts7 (massage_area[AREA_7].massage_lvl);
    Rte_Write_PassKneadingMassgLvlSts8_PassKneadingMassgLvlSts8(massage_area[AREA_8].massage_lvl);
    Rte_Write_PassKneadingMassgLvlSts9_PassKneadingMassgLvlSts9(massage_area[AREA_9].massage_lvl);
    #endif

    //按摩计算时间外发
    #ifdef PISCES_MCM_D
    Rte_Write_DrvKneadingMassgTime10_DrvKneadingMassgTime10(massage_area[AREA_10].massage_output_time);
    Rte_Write_DrvKneadingMassgTime5_DrvKneadingMassgTime5(massage_area[AREA_5].massage_output_time);
    Rte_Write_DrvKneadingMassgTime6_DrvKneadingMassgTime6(massage_area[AREA_6].massage_output_time);
    Rte_Write_DrvKneadingMassgTime7_DrvKneadingMassgTime7(massage_area[AREA_7].massage_output_time);
    Rte_Write_DrvKneadingMassgTime8_DrvKneadingMassgTime8(massage_area[AREA_8].massage_output_time);
    Rte_Write_DrvKneadingMassgTime9_DrvKneadingMassgTime9(massage_area[AREA_9].massage_output_time);
    #endif
    #ifdef PISCES_MCM_P
    Rte_Write_PassKneadingMassgTime10_PassKneadingMassgTime10(massage_area[AREA_10].massage_output_time);
    Rte_Write_PassKneadingMassgTime5_PassKneadingMassgTime5(massage_area[AREA_5].massage_output_time);
    Rte_Write_PassKneadingMassgTime6_PassKneadingMassgTime6(massage_area[AREA_6].massage_output_time);
    Rte_Write_PassKneadingMassgTime7_PassKneadingMassgTime7(massage_area[AREA_7].massage_output_time);
    Rte_Write_PassKneadingMassgTime8_PassKneadingMassgTime8(massage_area[AREA_8].massage_output_time);
    Rte_Write_PassKneadingMassgTime9_PassKneadingMassgTime9(massage_area[AREA_9].massage_output_time);
    #endif
}
/************************ Public Function Implementations ************************/
/**
 * @brief  Initialize massage task function
 * @param  None
 * @return None
 */
void Snf_Massage_Task_Init(void)
{

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
    _Snf_Massage_Status_Reset();
    _Snf_Massage_Close();
    _Snf_Massage_Pump_Valve_Control();

    for (int i = 0; i < AREA_MAX; i++)
    {
        switch (massage_area[i].massage_skills)
        {
            case MASSAGE_MODE_IDLE:
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
    _Snf_Massage_Output();
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