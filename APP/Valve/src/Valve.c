/************************ Include Files ************************/
#include "Basic_Config.h"
#include "Valve.h"
#include "Rte_Log.h"
#include "Rte_Pwm.h"
#include "Rte_Os.h"
/************************ Macro Definitions ************************/
#ifdef VALVE_PRINTF_ENABLE
#define VALVE_PRINTF RTE_LOG_PRINTF
#else
#define VALVE_PRINTF(...)
#endif
/************************ Private Global Variables ************************/
static const valve_ramp_step_t valve_ramp_up_step[] = {
    { 8000,  20 },
    { 10000, 20 },
    { 12000, 20 },
    { 8000,  20 },
};
static const uint8_t valve_ramp_up_step_size = sizeof(valve_ramp_up_step) / sizeof(valve_ramp_up_step[0]);

static const valve_ramp_step_t valve_ramp_down_step[] = {
    { 4000, 20 },
    { 2000, 20 },
    { 0,    20 },
};
static const uint8_t valve_ramp_down_step_size = sizeof(valve_ramp_down_step) / sizeof(valve_ramp_down_step[0]);

static valve_ramp_group_t valve_ramp_group[VALVE_RAMP_MEMBER_NUM] = { 0 };
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
    valve_ramp_group_t* ramp_group_ptr   = NULL;
    valve_ramp_step_t*  ramp_config_ptr  = NULL;
    uint8_t             ramp_config_size = 0;
    uint16_t            vol              = 0;
    uint8_t             duty_cycle       = 0;

    for (uint8_t i = 0; i < VALVE_RAMP_MEMBER_NUM; i++)
    {
        ramp_group_ptr = &valve_ramp_group[i];
        if (POWER_VALVE_STATE_RAMP_UP == ramp_group_ptr->state)
        {
            ramp_config_ptr  = (valve_ramp_step_t*)valve_ramp_up_step;
            ramp_config_size = valve_ramp_up_step_size;
        }
        else if (POWER_VALVE_STATE_RAMP_DOWN == ramp_group_ptr->state)
        {
            ramp_config_ptr  = (valve_ramp_step_t*)valve_ramp_down_step;
            ramp_config_size = valve_ramp_down_step_size;
        }
        else
        {
            continue;
        }

        if (RTE_OS_IS_TIMEOUT(ramp_group_ptr->last_timer_ms, ramp_config_ptr[ramp_group_ptr->step_index].step_time_ms))
        {
            ramp_group_ptr->step_index++;
            if (ramp_group_ptr->step_index < ramp_config_size)
            {
                ramp_group_ptr->last_timer_ms = RTE_OS_GET_TICK();
                vol                           = ramp_config_ptr[ramp_group_ptr->step_index].voltage;
                duty_cycle                    = VALVE_RAMP_STEP_VOLTAGE_TO_DUTY_CYCLE(vol);
                RTE_PWM_SET_DUTY(i, duty_cycle);
            }
            else
            {
                ramp_group_ptr->state = (POWER_VALVE_STATE_RAMP_UP == ramp_group_ptr->state ? POWER_VALVE_STATE_RAMP_UP_DONE
                                                                                            : POWER_VALVE_STATE_RAMP_DOWN_DONE);
            }
        }
    }
}
/************************ Public Function Implementations ************************/
/**
 * @brief   Set the solenoid valve state
 * @param  index: the index of the solenoid valve
 * @param  state: the state of the solenoid valve
 * @return bool: true if success, false if fail
 */
bool Snf_Valve_Set_Config(uint8_t index, valve_state_e state)
{
    valve_ramp_group_t* ramp_group_ptr  = &valve_ramp_group[index];
    valve_ramp_step_t*  ramp_config_ptr = NULL;
    uint16_t            vol             = 0;
    uint8_t             duty_cycle      = 0;

    if (index >= VALVE_RAMP_MEMBER_NUM)
    {
        return false;
    }

    if (ramp_group_ptr->state != state)
    {
        ramp_group_ptr->state         = state;
        ramp_group_ptr->step_index    = 0;
        ramp_group_ptr->last_timer_ms = RTE_OS_GET_TICK();

        if (POWER_VALVE_STATE_RAMP_UP == ramp_group_ptr->state)
        {
            ramp_config_ptr = (valve_ramp_step_t*)valve_ramp_up_step;
        }
        else if (POWER_VALVE_STATE_RAMP_DOWN == ramp_group_ptr->state)
        {
            ramp_config_ptr = (valve_ramp_step_t*)valve_ramp_down_step;
        }
        else
        {
            return true;
        }
        vol        = ramp_config_ptr[ramp_group_ptr->step_index].voltage;
        duty_cycle = VALVE_RAMP_STEP_VOLTAGE_TO_DUTY_CYCLE(vol);
        RTE_PWM_SET_DUTY(index, duty_cycle);
    }
    return true;
}

/**
 * @brief  Initialize Solenoid valve task function
 * @param  None
 * @return None
 */
#include "Rte_Gpio_If.h"
void Snf_Valve_Task_Init(void)
{
    valve_ramp_group_t* ramp_group_ptr = NULL;
    for (uint8_t i = 0; i < VALVE_RAMP_MEMBER_NUM; i++)
    {
        ramp_group_ptr        = &valve_ramp_group[i];
        ramp_group_ptr->state = POWER_VALVE_STATE_RAMP_DOWN_DONE;
    }
    RTE_GPIO_VALVE_ENABLE();
}

#define VALVE_INFLATION_TIME 180  // 180mS
#define VALVE_DEFLATION_TIME 140  // 140mS
uint32_t last_tick_flag = 0;
uint32_t last_tick_text = 0;
uint32_t last_cnt       = 0;
/**
 * @brief  Solenoid valve task function
 * @param  None
 * @return None
 */
void Snf_Valve_Task(void)
{
    _Snf_Valve_Process_Ramp();

    if (0 == last_cnt)
    {
        if (valve_ramp_group[RTE_PWM_CHANNEL_AM12].state == POWER_VALVE_STATE_RAMP_UP_DONE)
        {
            if (RTE_OS_IS_TIMEOUT(last_tick_text, VALVE_INFLATION_TIME))
            {
                Snf_Valve_Set_Config(RTE_PWM_CHANNEL_AM12, POWER_VALVE_STATE_RAMP_DOWN);
                last_tick_flag = 0;
                last_cnt       = 1;
            }
        }
        else if (valve_ramp_group[RTE_PWM_CHANNEL_AM12].state == POWER_VALVE_STATE_RAMP_DOWN_DONE)
        {
            if (RTE_OS_IS_TIMEOUT(last_tick_text, VALVE_DEFLATION_TIME))
            {
                Snf_Valve_Set_Config(RTE_PWM_CHANNEL_AM12, POWER_VALVE_STATE_RAMP_UP);
                last_tick_flag = 0;
            }
        }
    }

    if (1 == last_cnt)
    {
        if (valve_ramp_group[RTE_PWM_CHANNEL_AM13].state == POWER_VALVE_STATE_RAMP_UP_DONE)
        {
            if (RTE_OS_IS_TIMEOUT(last_tick_text, VALVE_INFLATION_TIME))
            {
                Snf_Valve_Set_Config(RTE_PWM_CHANNEL_AM13, POWER_VALVE_STATE_RAMP_DOWN);
                last_tick_flag = 0;
                last_cnt       = 2;
            }
        }
        else if (valve_ramp_group[RTE_PWM_CHANNEL_AM13].state == POWER_VALVE_STATE_RAMP_DOWN_DONE)
        {
            if (RTE_OS_IS_TIMEOUT(last_tick_text, VALVE_DEFLATION_TIME))
            {
                Snf_Valve_Set_Config(RTE_PWM_CHANNEL_AM13, POWER_VALVE_STATE_RAMP_UP);
                last_tick_flag = 0;
            }
        }
    }

    if (2 == last_cnt)
    {
        if (valve_ramp_group[RTE_PWM_CHANNEL_AM14].state == POWER_VALVE_STATE_RAMP_UP_DONE)
        {
            if (RTE_OS_IS_TIMEOUT(last_tick_text, VALVE_INFLATION_TIME))
            {
                Snf_Valve_Set_Config(RTE_PWM_CHANNEL_AM14, POWER_VALVE_STATE_RAMP_DOWN);
                last_tick_flag = 0;
                last_cnt       = 0;
            }
        }
        else if (valve_ramp_group[RTE_PWM_CHANNEL_AM14].state == POWER_VALVE_STATE_RAMP_DOWN_DONE)
        {
            if (RTE_OS_IS_TIMEOUT(last_tick_text, VALVE_DEFLATION_TIME))
            {
                Snf_Valve_Set_Config(RTE_PWM_CHANNEL_AM14, POWER_VALVE_STATE_RAMP_UP);
                last_tick_flag = 0;
            }
        }
    }

    if (0 == last_tick_flag)
    {
        last_tick_text = RTE_OS_GET_TICK();
        last_tick_flag = 1;
    }
}
