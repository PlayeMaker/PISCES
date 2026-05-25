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
void _Snf_Massage_Press_Counter_Clockwise(massage_action_config_t* massage_action_cfg);
/************************ Private Function Implementations ************************/
/**
 * @brief  Set massage press counter clockwise
 * @param  None
 * @return None
 */
void _Snf_Massage_Press_Counter_Clockwise(massage_action_config_t* massage_action_cfg)
{
}

/************************ Public Function Implementations ************************/
/**
 * @brief  Multi-point massage, compatible with both airbag-supported and non-airbag-supported models
 * @param  [in] massage_cfg: Massage configuration structure pointer
 * @return None
 */
void Snf_Massage_Multi_Press(massage_config_t* massage_cfg)
{
    massage_action_config_t* massage_action_cfg = &massage_cfg->action_cfg;
    massage_air_bag_config_t* air_bag_cfg_ptr = NULL;
    for (uint8_t i = 0; i < massage_action_cfg->air_bag_num; i++)
    {
        air_bag_cfg_ptr = &massage_action_cfg->air_bag_config_list[i];
        switch (massage_action_cfg->action_step)
        {
            case MASSAGE_ACTION_STEP_PRE_CHARGE:
            {
                if (MASSAGE_AIR_BAG_TYPE_SUPPORT == air_bag_cfg_ptr->air_bag_type)
                {
                    if (MASSAGE_AIR_BAG_NONE == air_bag_cfg_ptr->air_bag_mode)
                    {
                        air_bag_cfg_ptr->air_bag_last_uptime = RTE_OS_GET_TICK();
                        air_bag_cfg_ptr->air_bag_mode        = MASSAGE_AIR_BAG_INFLATION;
                        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(
                            air_bag_cfg_ptr->air_bag_pwm_channel[MASSAGE_AIR_BAG_SUPPORT_FRONT_VAVLE_IDX],
                            POWER_VALVE_STATE_RAMP_UP);
                        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(
                            air_bag_cfg_ptr->air_bag_pwm_channel[MASSAGE_AIR_BAG_SUPPORT_REAR_VAVLE_IDX],
                            POWER_VALVE_STATE_RAMP_DOWN);
                    }
                    else if (MASSAGE_AIR_BAG_INFLATION == air_bag_cfg_ptr->air_bag_mode)
                    {
                        if (RTE_OS_IS_TIMEOUT(air_bag_cfg_ptr->air_bag_last_uptime, air_bag_cfg_ptr->air_bag_inflation_time))
                        {
                            air_bag_cfg_ptr->air_bag_mode   = MASSAGE_AIR_BAG_KEEP;
                            massage_action_cfg->action_step = MASSAGE_ACTION_STEP_CYCLE;
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(
                                air_bag_cfg_ptr->air_bag_pwm_channel[MASSAGE_AIR_BAG_SUPPORT_FRONT_VAVLE_IDX],
                                POWER_VALVE_STATE_RAMP_UP);
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(
                                air_bag_cfg_ptr->air_bag_pwm_channel[MASSAGE_AIR_BAG_SUPPORT_REAR_VAVLE_IDX],
                                POWER_VALVE_STATE_RAMP_DOWN);
                        }
                    }
                }
                break;
            }
            case MASSAGE_ACTION_STEP_CYCLE:
            {
                if (MASSAGE_AIR_BAG_TYPE_STANDARD == air_bag_cfg_ptr->air_bag_type)
                {
                    if (MASSAGE_AIR_BAG_NONE == air_bag_cfg_ptr->air_bag_mode)
                    {
                        air_bag_cfg_ptr->air_bag_last_uptime = RTE_OS_GET_TICK();
                        air_bag_cfg_ptr->air_bag_mode        = MASSAGE_AIR_BAG_INFLATION;
                        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(air_bag_cfg_ptr->air_bag_pwm_channel[0],
                                                                     POWER_VALVE_STATE_RAMP_UP);
                    }
                    else if (MASSAGE_AIR_BAG_INFLATION == air_bag_cfg_ptr->air_bag_mode)
                    {
                        if (RTE_OS_IS_TIMEOUT(air_bag_cfg_ptr->air_bag_last_uptime, air_bag_cfg_ptr->air_bag_inflation_time))
                        {
                            air_bag_cfg_ptr->air_bag_mode   = MASSAGE_AIR_BAG_DEFLATION;
                            massage_action_cfg->action_step = MASSAGE_ACTION_STEP_END;
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(air_bag_cfg_ptr->air_bag_pwm_channel[0],
                                                                         POWER_VALVE_STATE_RAMP_DOWN);
                        }
                    }
                }
                break;
            }
            case MASSAGE_ACTION_STEP_END:
            {
                if (MASSAGE_AIR_BAG_INFLATION == air_bag_cfg_ptr->air_bag_mode ||
                    MASSAGE_AIR_BAG_KEEP == air_bag_cfg_ptr->air_bag_mode)
                {
                    air_bag_cfg_ptr->air_bag_mode = MASSAGE_AIR_BAG_DEFLATION;

                    if (MASSAGE_AIR_BAG_TYPE_STANDARD == air_bag_cfg_ptr->air_bag_type)
                    {
                        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(air_bag_cfg_ptr->air_bag_pwm_channel[0],
                                                                     POWER_VALVE_STATE_RAMP_DOWN);
                    }
                    else if (MASSAGE_AIR_BAG_TYPE_SUPPORT == air_bag_cfg_ptr->air_bag_type)
                    {
                        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(
                            air_bag_cfg_ptr->air_bag_pwm_channel[MASSAGE_AIR_BAG_SUPPORT_FRONT_VAVLE_IDX],
                            POWER_VALVE_STATE_RAMP_DOWN);
                        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(
                            air_bag_cfg_ptr->air_bag_pwm_channel[MASSAGE_AIR_BAG_SUPPORT_REAR_VAVLE_IDX],
                            POWER_VALVE_STATE_RAMP_UP);
                    }
                }
                else if (MASSAGE_AIR_BAG_DEFLATION == air_bag_cfg_ptr->air_bag_mode)
                {
                    if (RTE_OS_IS_TIMEOUT(air_bag_cfg_ptr->air_bag_last_uptime, air_bag_cfg_ptr->air_bag_inflation_time))
                    {
                        air_bag_cfg_ptr->air_bag_mode   = MASSAGE_AIR_BAG_NONE;
                        massage_action_cfg->action_step = MASSAGE_ACTION_STEP_NONE;
                    }
                }
                break;
            }
            default:
                break;
        }

        if (MASSAGE_AIR_BAG_TYPE_SUPPORT == air_bag_cfg_ptr->air_bag_type &&
            MASSAGE_AIR_BAG_INFLATION == air_bag_cfg_ptr->air_bag_mode)
        {
            break;  // 支撑气袋正在充气，先不处理后续的气袋
        }
    }
}

/**
 * @brief  Single-point massage
 * @param  [in] massage_cfg: Massage configuration structure pointer
 * @return None
 */
void Snf_Massage_Single_Press(massage_config_t* massage_cfg)
{
    massage_action_config_t* massage_action_cfg = &massage_cfg->action_cfg;
    massage_air_bag_config_t* air_bag_cfg_ptr = NULL;
    for (uint8_t i = 0; i < massage_action_cfg->air_bag_num; i++)
    {
        air_bag_cfg_ptr = &massage_action_cfg->air_bag_config_list[i];
        switch (massage_action_cfg->action_step)
        {
            case MASSAGE_ACTION_STEP_CYCLE:
            {
                if (MASSAGE_AIR_BAG_TYPE_STANDARD == air_bag_cfg_ptr->air_bag_type)
                {
                    if (MASSAGE_AIR_BAG_NONE == air_bag_cfg_ptr->air_bag_mode)
                    {
                        air_bag_cfg_ptr->air_bag_last_uptime = RTE_OS_GET_TICK();
                        air_bag_cfg_ptr->air_bag_mode        = MASSAGE_AIR_BAG_INFLATION;
                        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(air_bag_cfg_ptr->air_bag_pwm_channel[0],
                                                                     POWER_VALVE_STATE_RAMP_UP);
                    }
                    else if (MASSAGE_AIR_BAG_INFLATION == air_bag_cfg_ptr->air_bag_mode)
                    {
                        if (RTE_OS_IS_TIMEOUT(air_bag_cfg_ptr->air_bag_last_uptime, air_bag_cfg_ptr->air_bag_inflation_time))
                        {
                            air_bag_cfg_ptr->air_bag_mode   = MASSAGE_AIR_BAG_DEFLATION;
                            massage_action_cfg->action_step = MASSAGE_ACTION_STEP_END;
                            Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(air_bag_cfg_ptr->air_bag_pwm_channel[0],
                                                                         POWER_VALVE_STATE_RAMP_DOWN);
                        }
                    }
                }
                break;
            }
            case MASSAGE_ACTION_STEP_END:
            {
                if (MASSAGE_AIR_BAG_INFLATION == air_bag_cfg_ptr->air_bag_mode ||
                    MASSAGE_AIR_BAG_KEEP == air_bag_cfg_ptr->air_bag_mode)
                {
                    air_bag_cfg_ptr->air_bag_mode = MASSAGE_AIR_BAG_DEFLATION;

                    if (MASSAGE_AIR_BAG_TYPE_STANDARD == air_bag_cfg_ptr->air_bag_type)
                    {
                        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(air_bag_cfg_ptr->air_bag_pwm_channel[0],
                                                                     POWER_VALVE_STATE_RAMP_DOWN);
                    }
                    else if (MASSAGE_AIR_BAG_TYPE_SUPPORT == air_bag_cfg_ptr->air_bag_type)
                    {
                        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(
                            air_bag_cfg_ptr->air_bag_pwm_channel[MASSAGE_AIR_BAG_SUPPORT_FRONT_VAVLE_IDX],
                            POWER_VALVE_STATE_RAMP_DOWN);
                        Rte_Call_Sync_C_Massage_S_Valve_Ramp_Control(
                            air_bag_cfg_ptr->air_bag_pwm_channel[MASSAGE_AIR_BAG_SUPPORT_REAR_VAVLE_IDX],
                            POWER_VALVE_STATE_RAMP_UP);
                    }
                }
                else if (MASSAGE_AIR_BAG_DEFLATION == air_bag_cfg_ptr->air_bag_mode)
                {
                    if (RTE_OS_IS_TIMEOUT(air_bag_cfg_ptr->air_bag_last_uptime, air_bag_cfg_ptr->air_bag_inflation_time))
                    {
                        air_bag_cfg_ptr->air_bag_mode   = MASSAGE_AIR_BAG_NONE;
                        massage_action_cfg->action_step = MASSAGE_ACTION_STEP_NONE;
                    }
                }
                break;
            }
            default:
                break;
        }
    }
}
