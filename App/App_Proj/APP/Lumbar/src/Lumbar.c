/************************ Include Files ************************/
#include <stddef.h>
#include "Basic_Config.h"
#include "Lumbar.h"
#include "Rte_Swc.h"
#include "Rte_Log.h"
#include "Valve_Types.h"
#include "Pump_Types.h"
#include "Rte_Com.h"
/************************ Macro Definitions ************************/
#ifdef LUMBAR_PRINTF_ENABLE
#define LUMBAR_PRINTF RTE_LOG_PRINTF
#else
#define LUMBAR_PRINTF(...)
#endif
/************************ Private Function Declarations ************************/
static void    _Snf_Lumbar_Inflation(uint8_t position);
static void    _Snf_Lumbar_Deflation(uint8_t position);
static void    _Snf_Lumbar_Keep(uint8_t position);
static uint8_t _Snf_Lumbar_Top_Read_Cmd(uint8_t position);
static uint8_t _Snf_Lumbar_Bottom_Read_Cmd(uint8_t position);
static void    _Snf_Lumbar_Top_Write_Cmd(uint8_t position);
static void    _Snf_Lumbar_Bottom_Write_Cmd(uint8_t position);
/************************ Private Global Variables ************************/
static lumbar_config_t lumbar_config[] = {
    { LUMBAR_POSITION_TOP,    LUMBAR_MODE_RESERVED, LUMBAR_TOP_CHANNEL_FRONT,    LUMBAR_TOP_CHANNEL_REAR,    _Snf_Lumbar_Top_Read_Cmd,
     _Snf_Lumbar_Top_Write_Cmd                                                                                                                                      },
    { LUMBAR_POSITION_BOTTOM, LUMBAR_MODE_RESERVED, LUMBAR_BOTTOM_CHANNEL_FRONT, LUMBAR_BOTTOM_CHANNEL_REAR,
     _Snf_Lumbar_Bottom_Read_Cmd,                                                                                                      _Snf_Lumbar_Bottom_Write_Cmd },
};

static const uint8_t lumbar_config_size = sizeof(lumbar_config) / sizeof(lumbar_config[0]);
/************************ Public Global Variables ************************/

/************************ Private Function Implementations ************************/
/**
 * @brief  Lumbar inflation control for lumbar
 * @param  position: the position of lumbar to be controlled
 * @return None
 */
static void _Snf_Lumbar_Inflation(uint8_t position)
{
    lumbar_config_t* config_ptr = NULL;
    if (position >= lumbar_config_size)
    {
        LUMBAR_PRINTF("Inflation invalid lumbar position: %d\n", position);
        return;
    }

    config_ptr = (lumbar_config_t*)&lumbar_config[position];
    if (LUMBAR_MODE_INFLATION == config_ptr->mode)
    {
        return;
    }

    LUMBAR_PRINTF("Inflation lumbar position: %d\n", position);
    config_ptr->mode = LUMBAR_MODE_INFLATION;
    Rte_Call_Sync_C_Lumbar_S_Valve_Set_Work_States(VALVE_WORK_STATE_ON, VALVE_LUMBAR_WORK_MASK);
    Rte_Call_Sync_C_Lumbar_S_Pump_Set_Work_States(PUMP_WORK_STATE_ON, PUMP_LUMBAR_WORK_MASK);
    Rte_Call_Sync_C_Lumbar_S_Valve_Ramp_Control(config_ptr->pwm_channel_fornt, POWER_VALVE_STATE_RAMP_UP);
    Rte_Call_Sync_C_Lumbar_S_Valve_Ramp_Control(config_ptr->pwm_channel_rear, POWER_VALVE_STATE_RAMP_DOWN);
}
/**
 * @brief  Lumbar deflation control for lumbar
 * @param  position: the position of lumbar to be controlled
 * @return None
 */
static void _Snf_Lumbar_Deflation(uint8_t position)
{
    lumbar_config_t* config_ptr = NULL;
    if (position >= lumbar_config_size)
    {
        LUMBAR_PRINTF("Deflation invalid lumbar position: %d\n", position);
        return;
    }

    config_ptr = (lumbar_config_t*)&lumbar_config[position];
    if (LUMBAR_MODE_DEFLATION == config_ptr->mode)
    {
        return;
    }

    LUMBAR_PRINTF("Deflation lumbar position: %d\n", position);
    config_ptr->mode = LUMBAR_MODE_DEFLATION;
    Rte_Call_Sync_C_Lumbar_S_Valve_Set_Work_States(VALVE_WORK_STATE_ON, VALVE_LUMBAR_WORK_MASK);
    Rte_Call_Sync_C_Lumbar_S_Pump_Set_Work_States(PUMP_WORK_STATE_ON, PUMP_LUMBAR_WORK_MASK);
    Rte_Call_Sync_C_Lumbar_S_Valve_Ramp_Control(config_ptr->pwm_channel_fornt, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Lumbar_S_Valve_Ramp_Control(config_ptr->pwm_channel_rear, POWER_VALVE_STATE_RAMP_UP);
}
/**
 * @brief  Lumbar keep control for lumbar
 * @param  position: the position of lumbar to be controlled
 * @return None
 */
static void _Snf_Lumbar_Keep(uint8_t position)
{
    lumbar_config_t* config_ptr = NULL;
    if (position >= lumbar_config_size)
    {
        LUMBAR_PRINTF("Keep invalid lumbar position: %d\n", position);
        return;
    }

    config_ptr = (lumbar_config_t*)&lumbar_config[position];
    if (LUMBAR_MODE_NO_ACTION == config_ptr->mode || LUMBAR_MODE_RESERVED == config_ptr->mode)
    {
        return;
    }

    LUMBAR_PRINTF("Keep lumbar position: %d\n", position);
    config_ptr->mode = LUMBAR_MODE_NO_ACTION;
    Rte_Call_Sync_C_Lumbar_S_Valve_Set_Work_States(VALVE_WORK_STATE_ON, VALVE_LUMBAR_WORK_MASK);
    Rte_Call_Sync_C_Lumbar_S_Pump_Set_Work_States(PUMP_WORK_STATE_ON, PUMP_LUMBAR_WORK_MASK);
    Rte_Call_Sync_C_Lumbar_S_Valve_Ramp_Control(config_ptr->pwm_channel_fornt, POWER_VALVE_STATE_RAMP_DOWN);
    Rte_Call_Sync_C_Lumbar_S_Valve_Ramp_Control(config_ptr->pwm_channel_rear, POWER_VALVE_STATE_RAMP_DOWN);
}
/**
 * @brief  Lumbar top read command for lumbar
 * @param  position: the position of lumbar to be controlled
 * @return None
 */
static uint8_t _Snf_Lumbar_Top_Read_Cmd(uint8_t position)
{
    uint8_t cmd_value = 0;
#if defined(PISCES_MCM_D)
    Rte_Read_DrvSeatLumbarTopValue1Cmd_DrvSeatLumbarTopValue1Cmd(&cmd_value);
#elif defined(PISCES_MCM_P)
    Rte_Read_PassSeatLumbarTopValue1Cmd_PassSeatLumbarTopValue1Cmd(&cmd_value);
#endif
    return cmd_value;
}
/**
 * @brief Lumbar bottom read command for lumbar
 * @param  position: the position of lumbar to be controlled
 * @return None
 */
static uint8_t _Snf_Lumbar_Bottom_Read_Cmd(uint8_t position)
{
    uint8_t cmd_value = 0;
#if defined(PISCES_MCM_D)
    Rte_Read_DrvSeatLumbarBottomValue3Cmd_DrvSeatLumbarBottomValue3Cmd(&cmd_value);
#elif defined(PISCES_MCM_P)
    Rte_Read_PassSeatLumbarBottomValue3Cmd_PassSeatLumbarBottomValue3Cmd(&cmd_value);
#endif
    return cmd_value;
}
/**
 * @brief  Lumbar top write command for lumbar
 * @param  position: the position of lumbar to be controlled
 * @return None
 */
static void _Snf_Lumbar_Top_Write_Cmd(uint8_t position)
{
    lumbar_config_t* config_ptr = NULL;
    if (position >= lumbar_config_size)
    {
        LUMBAR_PRINTF("Write Top invalid lumbar position: %d\n", position);
        return;
    }

    config_ptr = (lumbar_config_t*)&lumbar_config[position];
#if defined(PISCES_MCM_D)
    Rte_Write_DrvLumbarTopWorkSts_DrvLumbarTopWorkSts(config_ptr->mode);
#elif defined(PISCES_MCM_P)
    Rte_Write_PassLumbarTopWorkSts_PassLumbarTopWorkSts(config_ptr->mode);
#endif
}
/**
 * @brief  Lumbar bottom write command for lumbar
 * @param  position: the position of lumbar to be controlled
 * @return None
 */
static void _Snf_Lumbar_Bottom_Write_Cmd(uint8_t position)
{
    lumbar_config_t* config_ptr = NULL;
    if (position >= lumbar_config_size)
    {
        LUMBAR_PRINTF("Write Bottom invalid lumbar position: %d\n", position);
        return;
    }

    config_ptr = (lumbar_config_t*)&lumbar_config[position];
#if defined(PISCES_MCM_D)
    Rte_Write_DrvLumbarBottomWorkSts_DrvLumbarBottomWorkSts(config_ptr->mode);
#elif defined(PISCES_MCM_P)
    Rte_Write_PassLumbarBottomWorkSts_PassLumbarBottomWorkSts(config_ptr->mode);
#endif
}

/**
 * @brief  Lumbar handle control for lumbar
 * @param  None
 * @return None
 */
static void _Snf_Lumbar_handle(void)
{
    lumbar_config_t* config_ptr = NULL;
    uint8_t          cmd_value  = 0;
    for (uint8_t i = 0; i < lumbar_config_size; i++)
    {
        config_ptr = (lumbar_config_t*)&lumbar_config[i];
        if (NULL != config_ptr->read_net_cmd_callback)
        {
            cmd_value = config_ptr->read_net_cmd_callback(config_ptr->position);
        }

        switch (cmd_value)
        {
            case LUMBAR_MODE_NO_ACTION:
                _Snf_Lumbar_Keep(i);
                break;
            case LUMBAR_MODE_INFLATION:
                _Snf_Lumbar_Inflation(i);
                break;
            case LUMBAR_MODE_DEFLATION:
                _Snf_Lumbar_Deflation(i);
                break;
            default:
                break;
        }

        if (NULL != config_ptr->write_net_cmd_callback)
        {
            config_ptr->write_net_cmd_callback(config_ptr->position);
        }
    }
}
/************************ Public Function Implementations ************************/
/**
 * @brief  Lumbar task function
 * @param  None
 * @return None
 */
void Snf_Lumbar_Task(void)
{
    _Snf_Lumbar_handle();
}
