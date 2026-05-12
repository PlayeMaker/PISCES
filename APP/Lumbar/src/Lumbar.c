/************************ Include Files ************************/
#include "Basic_Config.h"
#include "Lumbar.h"
#include "Rte_Pwm.h"
#include "Rte_Pwm_If.h"
#include "Rte_Log.h"
/************************ Macro Definitions ************************/
#ifdef LUMBAR_PRINTF_ENABLE
#define LUMBAR_PRINTF RTE_LOG_PRINTF
#else
#define LUMBAR_PRINTF(...)
#endif
/************************ Private Global Variables ************************/
static lumbar_config_t lumbar_config[] = {
    {LUMBAR_POSITION_TOP,    LUMBAR_MODE_IDLE, RTE_PWM_CHANNEL_YT1, RTE_PWM_CHANNEL_YTR1},
    {LUMBAR_POSITION_BOTTOM, LUMBAR_MODE_IDLE, RTE_PWM_CHANNEL_YT2, RTE_PWM_CHANNEL_YTR2},
};

static const uint8_t lumbar_config_size = sizeof(lumbar_config) / sizeof(lumbar_config[0]);
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Lumbar_Inflation(lumbar_position_e position);
static void _Snf_Lumbar_Deflation(lumbar_position_e position);
static void _Snf_Lumbar_Keep(lumbar_position_e position);
/************************ Private Function Implementations ************************/
/**
 * @brief  Lumbar inflation control for lumbar
 * @param  None
 * @return None
 */
static void _Snf_Lumbar_Inflation(lumbar_position_e position)
{
    lumbar_config_t* config_ptr = &lumbar_config[position];
    if (position >= lumbar_config_size)
    {
        LUMBAR_PRINTF("Inflation invalid lumbar position: %d\n", position);
        return;
    }
    if (LUMBAR_MODE_INFLATION == config_ptr->mode)
    {
        return;
    }
    config_ptr->mode = LUMBAR_MODE_INFLATION;
    RTE_PWM_SET_DUTY(config_ptr->pwm_channel_1, 50);  // 充气占空比50%
    RTE_PWM_SET_DUTY(config_ptr->pwm_channel_2, RTE_PWM_DUTY_MIN);
}
/**
 * @brief  Lumbar deflation control for lumbar
 * @param  None
 * @return None
 */
static void _Snf_Lumbar_Deflation(lumbar_position_e position)
{
    lumbar_config_t* config_ptr = &lumbar_config[position];
    if (position >= lumbar_config_size)
    {
        LUMBAR_PRINTF("Deflation invalid lumbar position: %d\n", position);
        return;
    }
    if (LUMBAR_MODE_DEFLATION == config_ptr->mode)
    {
        return;
    }
    config_ptr->mode = LUMBAR_MODE_DEFLATION;
    RTE_PWM_SET_DUTY(config_ptr->pwm_channel_1, RTE_PWM_DUTY_MIN);
    RTE_PWM_SET_DUTY(config_ptr->pwm_channel_2, 50);
}
/**
 * @brief  Lumbar keep control for lumbar
 * @param  None
 * @return None
 */
static void _Snf_Lumbar_Keep(lumbar_position_e position)
{
    lumbar_config_t* config_ptr = &lumbar_config[position];
    if (position >= lumbar_config_size)
    {
        LUMBAR_PRINTF("Keep invalid lumbar position: %d\n", position);
        return;
    }
    if (LUMBAR_MODE_DEFLATION == config_ptr->mode)
    {
        return;
    }
    config_ptr->mode = LUMBAR_MODE_DEFLATION;
    RTE_PWM_SET_DUTY(config_ptr->pwm_channel_1, RTE_PWM_DUTY_MIN);
    RTE_PWM_SET_DUTY(config_ptr->pwm_channel_2, RTE_PWM_DUTY_MIN);
}
/************************ Public Function Implementations ************************/
/**
 * @brief  Lumbar task function
 * @param  None
 * @return None
 */
void Snf_Lumbar_Task(void)
{
}
