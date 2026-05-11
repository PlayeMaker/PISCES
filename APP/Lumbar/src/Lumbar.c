/************************ Include Files ************************/
#include "Basic_Config.h"
#include "Lumbar.h"
#include "Rte_Pwm_If.h"
#include "Rte_Log.h"
/************************ Macro Definitions ************************/
#ifdef LUMBAR_PRINTF_ENABLE
#define LUMBAR_PRINTF RTE_LOG_PRINTF
#else
#define LUMBAR_PRINTF(...)
#endif
/************************ Private Global Variables ************************/
// static const lumbar_config_t lumbar_config[] = {
//     [LUMBAR_POSITION_TOP]    = {LUMBAR_POSITION_TOP,    LUMBAR_INFLATION_DUTY_CYCLE, LUMBAR_DEFLATION_DUTY_CYCLE,
//                                 RTE_PWM_SET_DUTY_YT1_EN},
//     [LUMBAR_POSITION_BOTTOM] = {LUMBAR_POSITION_BOTTOM, LUMBAR_INFLATION_DUTY_CYCLE, LUMBAR_DEFLATION_DUTY_CYCLE,
//                                 RTE_PWM_SET_DUTY_YT2_EN},
// };

// static const uint8_t lumbar_config_size = sizeof(lumbar_config) / sizeof(lumbar_config[0]);
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
// static void _Snf_Board_Init(void);
/************************ Private Function Implementations ************************/
// /**
//  * @brief  Board Hardware Init function
//  * @param  None
//  * @return None
//  */
// static void _Snf_Board_Init(void)
// {

// }

/************************ Public Function Implementations ************************/
/**
 * @brief  Lumbar task function
 * @param  None
 * @return None
 */
static uint8_t acc        = 0;
static uint8_t duty_cycle = 50;
void           Snf_Lumbar_Task(void)
{
    if (1 == acc)
    {
        RTE_PWM_SET_DUTY_YT2_EN(duty_cycle);
    }
    else if (2 == acc)
    {
        RTE_PWM_SET_DUTY_AM1_EN(duty_cycle);
    }
    else if (3 == acc)
    {
        RTE_PWM_SET_DUTY_AM8_EN(duty_cycle);
    }
    else if (4 == acc)
    {
        RTE_PWM_SET_DUTY_AM9_EN(duty_cycle);
    }
    else if (5 == acc)
    {
        RTE_PWM_SET_DUTY_AM10_EN(duty_cycle);
    }
    else if (6 == acc)
    {
        RTE_PWM_SET_DUTY_YT1_EN(duty_cycle);
    }
    else if (7 == acc)
    {
        RTE_PWM_SET_DUTY_AM3_EN(duty_cycle);
    }
    else if (8 == acc)
    {
        RTE_PWM_SET_DUTY_RNR1_EN(duty_cycle);
    }
    else if (9 == acc)
    {
        RTE_PWM_SET_DUTY_RN1_EN(duty_cycle);
    }
    else if (10 == acc)
    {
        RTE_PWM_SET_DUTY_PUMP_EN(duty_cycle);
    }
    else if (11 == acc)
    {
        RTE_PWM_SET_DUTY_AM13_EN(duty_cycle);
    }
    else if (12 == acc)
    {
        RTE_PWM_SET_DUTY_AM14_EN(duty_cycle);
    }
    else if (13 == acc)
    {
        RTE_PWM_SET_DUTY_YLR1_EN(duty_cycle);
    }
    else if (14 == acc)
    {
        RTE_PWM_SET_DUTY_YL1_EN(duty_cycle);
    }
    else if (15 == acc)
    {
        RTE_PWM_SET_DUTY_AM4_EN(duty_cycle);
    }
    else if (16 == acc)
    {
        RTE_PWM_SET_DUTY_AM5_EN(duty_cycle);
    }
    else if (17 == acc)
    {
        RTE_PWM_SET_DUTY_AM6_EN(duty_cycle);
    }
    else if (18 == acc)
    {
        RTE_PWM_SET_DUTY_RN2_EN(duty_cycle);
    }
    else if (19 == acc)
    {
        RTE_PWM_SET_DUTY_AM7_EN(duty_cycle);
    }
    else if (20 == acc)
    {
        RTE_PWM_SET_DUTY_RNR2_EN(duty_cycle);
    }
    else if (21 == acc)
    {
        RTE_PWM_SET_DUTY_AM2_EN(duty_cycle);
    }
    else if (22 == acc)
    {
        RTE_PWM_SET_DUTY_YTR1_EN(duty_cycle);
    }
    else if (23 == acc)
    {
        RTE_PWM_SET_DUTY_YTR2_EN(duty_cycle);
    }
    else if (24 == acc)
    {
        RTE_PWM_SET_DUTY_AM11_EN(duty_cycle);
    }
    else if (25 == acc)
    {
        RTE_PWM_SET_DUTY_AM12_EN(duty_cycle);
    }
}
