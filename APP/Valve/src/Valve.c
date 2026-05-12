/************************ Include Files ************************/
#include <stddef.h>
#include "Basic_Config.h"
#include "Valve.h"
#include "Power_Message_Box.h"
#include "Rte_Mcu.h"
#include "Rte_Log.h"
#include "Rte_Adc_If.h"
#include "Rte_Gpio_If.h"
#include "Rte_Pwm.h"
#include "Rte_Pwm_If.h"
#include "Rte_Os.h"
/************************ Macro Definitions ************************/
#ifdef VALVE_PRINTF_ENABLE
#define VALVE_PRINTF RTE_LOG_PRINTF
#else
#define VALVE_PRINTF(...)
#endif
/************************ Private Global Variables ************************/
static const uint8_t power_valve_list[] = {
    RTE_PWM_CHANNEL_YT2,  RTE_PWM_CHANNEL_AM1,  RTE_PWM_CHANNEL_AM8,  RTE_PWM_CHANNEL_AM9,  RTE_PWM_CHANNEL_AM10,
    RTE_PWM_CHANNEL_YT1,  RTE_PWM_CHANNEL_AM3,  RTE_PWM_CHANNEL_RNR1, RTE_PWM_CHANNEL_RN1,  RTE_PWM_CHANNEL_AM13,
    RTE_PWM_CHANNEL_AM14, RTE_PWM_CHANNEL_YLR1, RTE_PWM_CHANNEL_YL1,  RTE_PWM_CHANNEL_AM4,  RTE_PWM_CHANNEL_AM5,
    RTE_PWM_CHANNEL_AM6,  RTE_PWM_CHANNEL_RN2,  RTE_PWM_CHANNEL_AM7,  RTE_PWM_CHANNEL_RNR2, RTE_PWM_CHANNEL_AM2,
    RTE_PWM_CHANNEL_YTR1, RTE_PWM_CHANNEL_YTR2, RTE_PWM_CHANNEL_AM11, RTE_PWM_CHANNEL_AM12
};

static const power_valve_ramp_step_t power_valve_ramp_up_step[] = {
    { 8000,  20 },
    { 10000, 20 },
    { 12000, 20 },
    { 8000,  20 },
};
static const power_valve_ramp_step_t power_valve_ramp_down_step[] = {
    { 4000, 20 },
    { 2000, 20 },
    { 0,    20 },
};

static power_valve_ramp_config_t power_valve_ramp_up_config = {
    .state               = POWER_VALVE_STATE_IDLE,
    .step_index          = 0,
    .last_timer_ms       = 0,
    .valve_list          = power_valve_list,
    .valve_list_size     = sizeof(power_valve_list) / sizeof(power_valve_list[0]),
    .step_up_list        = power_valve_ramp_up_step,
    .step_up_list_size   = sizeof(power_valve_ramp_up_step) / sizeof(power_valve_ramp_up_step[0]),
    .step_down_list      = power_valve_ramp_down_step,
    .step_down_list_size = sizeof(power_valve_ramp_down_step) / sizeof(power_valve_ramp_down_step[0]),
};
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Valve_Process_Ramp(void);
/************************ Private Function Implementations ************************/
/**
 * @brief  Handling the gradual up or down process
 * @param  None
 * @return None
 */
static void _Snf_Valve_Process_Ramp(void)
{
    power_valve_ramp_config_t*     config = &power_valve_ramp_up_config;
    const power_valve_ramp_step_t* step   = NULL;
    if (POWER_VALVE_STATE_RAMP_UP == config->state)
    {
        step = config->step_up_list;
    }
    else if (POWER_VALVE_STATE_RAMP_DOWN == config->state)
    {
        step = config->step_down_list;
    }

    if (0 == config->step_index)
    {
    }
}
/************************ Public Function Implementations ************************/
/**
 * @brief  Initialize Solenoid valve task function
 * @param  None
 * @return None
 */
void Snf_Valve_Task_Init(void)
{
    // power_load_last_update_time              = RTE_OS_GET_TICK();
    // power_pump_last_update_time              = RTE_OS_GET_TICK();
    // power_valve_ramp_up_config.state         = POWER_VALVE_STATE_RAMP_UP;
    // power_valve_ramp_up_config.last_timer_ms = RTE_OS_GET_TICK();
}

/**
 * @brief  Solenoid valve task function
 * @param  None
 * @return None
 */
void Snf_Valve_Task(void)
{
}
