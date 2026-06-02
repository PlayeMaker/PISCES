/************************ Include Files ************************/
#include "Basic_Config.h"
#include "Massage.h"
#include "Massage_Knead.h"
#include "Massage_Press.h"
#include "Valve_Types.h"
#include "Rte_Pwm_If.h"
#include "Rte_Swc.h"
#include "Rte_Log.h"

#if defined(HIGH_CONFIGURATION)
/************************ Macro Definitions ************************/
#ifdef MASSAGE_PRINTF_ENABLE
#define MASSAGE_PRINTF RTE_LOG_PRINTF
#else
#define MASSAGE_PRINTF(...)
#endif
/************************ Private Global Variables ************************/
static massage_config_t massage_left_shoulder_config = {
    .zone                              = MASSAGE_ZONE_LEFT_SHOULDER,
    .mode                              = MASSAGE_MODE_NONE,
    .action_sum_time                   = 0,
    .action_cfg.air_bag_num            = 1,
    .action_cfg.air_bag_config_list[0] = { .air_bag_type            = MASSAGE_AIR_BAG_TYPE_STANDARD,
                                          .air_bag_pwm_channel_num = 1,
                                          .air_bag_pwm_channel     = { RTE_PWM_CHANNEL_AM7 } },
};

static massage_config_t massage_left_back_config = {
    .zone                              = MASSAGE_ZONE_LEFT_BACK,
    .mode                              = MASSAGE_MODE_NONE,
    .action_sum_time                   = 0,
    .action_cfg.air_bag_num            = 4,
    .action_cfg.air_bag_config_list[0] = { .air_bag_type            = MASSAGE_AIR_BAG_TYPE_SUPPORT,
                                          .air_bag_pwm_channel_num = 2,
                                          .air_bag_pwm_channel     = { RTE_PWM_CHANNEL_RN2, RTE_PWM_CHANNEL_RNR2 } },
    .action_cfg.air_bag_config_list[1] = { .air_bag_type            = MASSAGE_AIR_BAG_TYPE_STANDARD,
                                          .air_bag_pwm_channel_num = 1,
                                          .air_bag_pwm_channel     = { RTE_PWM_CHANNEL_AM4 }                       },
    .action_cfg.air_bag_config_list[2] = { .air_bag_type            = MASSAGE_AIR_BAG_TYPE_STANDARD,
                                          .air_bag_pwm_channel_num = 1,
                                          .air_bag_pwm_channel     = { RTE_PWM_CHANNEL_AM6 }                       },
    .action_cfg.air_bag_config_list[3] = { .air_bag_type            = MASSAGE_AIR_BAG_TYPE_STANDARD,
                                          .air_bag_pwm_channel_num = 1,
                                          .air_bag_pwm_channel     = { RTE_PWM_CHANNEL_AM5 }                       },
};

static massage_config_t massage_left_waist_config = {
    .zone                              = MASSAGE_ZONE_LEFT_WAIST,
    .mode                              = MASSAGE_MODE_NONE,
    .action_sum_time                   = 0,
    .action_cfg.air_bag_num            = 3,
    .action_cfg.air_bag_config_list[0] = { .air_bag_type            = MASSAGE_AIR_BAG_TYPE_STANDARD,
                                          .air_bag_pwm_channel_num = 1,
                                          .air_bag_pwm_channel     = { RTE_PWM_CHANNEL_AM8 }  },
    .action_cfg.air_bag_config_list[1] = { .air_bag_type            = MASSAGE_AIR_BAG_TYPE_STANDARD,
                                          .air_bag_pwm_channel_num = 1,
                                          .air_bag_pwm_channel     = { RTE_PWM_CHANNEL_AM9 }  },
    .action_cfg.air_bag_config_list[2] = { .air_bag_type            = MASSAGE_AIR_BAG_TYPE_STANDARD,
                                          .air_bag_pwm_channel_num = 1,
                                          .air_bag_pwm_channel     = { RTE_PWM_CHANNEL_AM10 } },
};

static const massage_group_t massage_group[] = {
    { &massage_left_shoulder_config },
    { &massage_left_back_config },
    { &massage_left_waist_config },
};
static const uint8_t massage_group_size = sizeof(massage_group) / sizeof(massage_group[0]);
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Massage_Handle(void);
/************************ Private Function Implementations ************************/
/**
 * @brief  Board Hardware Init function
 * @param  None
 * @return None
 */
static void _Snf_Massage_Handle(void)
{
    massage_config_t* massage_config_ptr = NULL;

    for (uint8_t i = 0; i < massage_group_size; i++)
    {
        massage_config_ptr = massage_group[i].config;

        if (MASSAGE_MODE_NONE != massage_config_ptr->mode)
        {
            switch (massage_config_ptr->mode)
            {
                case MASSAGE_MODE_NONE:
                    break;
                case MASSAGE_MODE_KNEADING:
                    Snf_Massage_Knead_Handle(massage_config_ptr);
                    break;
                case MASSAGE_MODE_SINGLE_PRESSING:
                    Snf_Massage_Single_Press(massage_config_ptr);
                    break;
                case MASSAGE_MODE_MULTI_PRESSING:
                    Snf_Massage_Multi_Press(massage_config_ptr);
                    break;
                case MASSAGE_MODE_TAPPING:
                    // Snf_Massage_Tap(massage_config_ptr);
                    break;
                default:
                    break;
            }
        }
    }
}
/************************ Public Function Implementations ************************/
/**
 * @brief  Initialize massage task function
 * @param  None
 * @return None
 */
#include "Rte_Gpio_If.h"
void Snf_Massage_Task_Init(void)
{
    // RTE_GPIO_PUMP_ENABLE();
    // RTE_GPIO_VALVE_ENABLE();
    // massage_left_waist_config.mode                                                     = MASSAGE_MODE_MULTI_PRESSING;
    // massage_left_waist_config.action_cfg.action_step                                   = MASSAGE_ACTION_STEP_CYCLE;
    // massage_left_waist_config.action_cfg.air_bag_config_list[0].air_bag_inflation_time = 4000;
    // massage_left_waist_config.action_cfg.air_bag_config_list[1].air_bag_inflation_time = 4000;
    // massage_left_waist_config.action_cfg.air_bag_config_list[2].air_bag_inflation_time = 4000;
    // massage_left_waist_config.action_cfg.air_bag_config_list[0].air_bag_deflation_time = 1000;
    // massage_left_waist_config.action_cfg.air_bag_config_list[1].air_bag_deflation_time = 1000;
    // massage_left_waist_config.action_cfg.air_bag_config_list[2].air_bag_deflation_time = 1000;

    // massage_left_back_config.mode                                                     = MASSAGE_MODE_MULTI_PRESSING;
    // massage_left_back_config.action_cfg.action_step                                   = MASSAGE_ACTION_STEP_PRE_CHARGE;
    // massage_left_back_config.action_cfg.air_bag_config_list[0].air_bag_inflation_time = 2000;
    // massage_left_back_config.action_cfg.air_bag_config_list[1].air_bag_inflation_time = 4000;
    // massage_left_back_config.action_cfg.air_bag_config_list[2].air_bag_inflation_time = 4000;
    // massage_left_back_config.action_cfg.air_bag_config_list[3].air_bag_inflation_time = 4000;

    // massage_left_back_config.action_cfg.air_bag_config_list[0].air_bag_deflation_time = 1000;
    // massage_left_back_config.action_cfg.air_bag_config_list[1].air_bag_deflation_time = 1000;
    // massage_left_back_config.action_cfg.air_bag_config_list[2].air_bag_deflation_time = 1000;
    // massage_left_back_config.action_cfg.air_bag_config_list[3].air_bag_deflation_time = 1000;
}

/**
 * @brief  Massage task function
 * @param  None
 * @return None
 */

// static volatile uint8_t massage_task_cnt = 0;
void Snf_Massage_Task(void)
{
    _Snf_Massage_Handle();

    // if (1 == massage_task_cnt) //充气
    // {
    //     massage_task_cnt = 0;
    //     Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(PwmConf_PwmChannel_PwmChannel_RN2_EN, POWER_VALVE_STATE_RAMP_UP);
    //     Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(PwmConf_PwmChannel_PwmChannel_RNR2_EN, POWER_VALVE_STATE_RAMP_DOWN);
    // }
    // else if (2 == massage_task_cnt) //放气
    // {
    //     massage_task_cnt = 0;
    //     Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(PwmConf_PwmChannel_PwmChannel_RN2_EN, POWER_VALVE_STATE_RAMP_DOWN);
    //     Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(PwmConf_PwmChannel_PwmChannel_RNR2_EN, POWER_VALVE_STATE_RAMP_UP);
    // }
    // else if (3 == massage_task_cnt) //保压
    // {
    //     massage_task_cnt = 0;
    //     Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(PwmConf_PwmChannel_PwmChannel_RN2_EN, POWER_VALVE_STATE_RAMP_DOWN);
    //     Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(PwmConf_PwmChannel_PwmChannel_RNR2_EN, POWER_VALVE_STATE_RAMP_DOWN);
    // }
}
#endif