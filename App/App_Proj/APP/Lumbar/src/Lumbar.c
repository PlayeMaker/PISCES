/************************ Include Files ************************/
#include <stddef.h>
#include "Basic_Config.h"
#include "Lumbar.h"
#include "Rte_Swc.h"
#include "Rte_Log.h"
#include "Valve_Types.h"
#include "Pump_Types.h"
#include "Rte_Com.h"
#include "Lumbar_Data_Class.h"
#include "Lumbar_Data_Def.h"
#include "Lumbar_Data_Class.h"
#include "Lumbar_Data_Def.h"
#include "Lumbar_Data_Class.h"
/************************ Macro Definitions ************************/
#ifdef LUMBAR_PRINTF_ENABLE
#define LUMBAR_PRINTF RTE_LOG_PRINTF
#else
#define LUMBAR_PRINTF(...)
#endif
/************************ Private Global Variables ************************/
/**
 * @brief  腰托动作表：[命令模式] = 动作参数，动作输出(泵阀状态/方向)调整只改这里
 */
static const lumbar_action_param_t lumbar_action_table[LUMBAR_MODE_RESERVED] = {
    [LUMBAR_MODE_NO_ACTION] = { LUMBAR_MODE_NO_ACTION, VALVE_WORK_STATE_OFF, PUMP_WORK_STATE_OFF, POWER_VALVE_STATE_RAMP_DOWN,
                               POWER_VALVE_STATE_RAMP_DOWN },
    [LUMBAR_MODE_INFLATION] = { LUMBAR_MODE_INFLATION, VALVE_WORK_STATE_ON,  PUMP_WORK_STATE_ON,  POWER_VALVE_STATE_RAMP_UP,
                               POWER_VALVE_STATE_RAMP_DOWN },
    [LUMBAR_MODE_DEFLATION] = { LUMBAR_MODE_DEFLATION, VALVE_WORK_STATE_ON,  PUMP_WORK_STATE_OFF, POWER_VALVE_STATE_RAMP_DOWN,
                               POWER_VALVE_STATE_RAMP_UP   },
};
/************************ Private Function Declarations ************************/
static void _Snf_Lumbar_Action(uint8_t position, lumbar_mode_e action);
static void _Snf_Lumbar_Handle(void);
/************************ Private Function Implementations ************************/
/**
 * @brief  读取腰托上气袋网络命令
 * @param  position - 腰托位置(未使用，与回调签名保持一致)
 * @return uint8_t - 网络命令值
 */
static uint8_t _Snf_Lumbar_Top_Read_Cmd(uint8_t position)
{
    uint8_t cmd_value = 0;

    (void)position;
#if defined(PISCES_MCM_D)
    (void)Rte_Read_DrvSeatLumbarTopValue1Cmd_DrvSeatLumbarTopValue1Cmd(&cmd_value);
#elif defined(PISCES_MCM_P)
    (void)Rte_Read_PassSeatLumbarTopValue1Cmd_PassSeatLumbarTopValue1Cmd(&cmd_value);
#endif

    return cmd_value;
}

/**
 * @brief  读取腰托下气袋网络命令
 * @param  position - 腰托位置(未使用，与回调签名保持一致)
 * @return uint8_t - 网络命令值
 */
static uint8_t _Snf_Lumbar_Bottom_Read_Cmd(uint8_t position)
{
    uint8_t cmd_value = 0;

    (void)position;
#if defined(PISCES_MCM_D)
    (void)Rte_Read_DrvSeatLumbarBottomValue3Cmd_DrvSeatLumbarBottomValue3Cmd(&cmd_value);
#elif defined(PISCES_MCM_P)
    (void)Rte_Read_PassSeatLumbarBottomValue3Cmd_PassSeatLumbarBottomValue3Cmd(&cmd_value);
#endif

    return cmd_value;
}

/**
 * @brief  输出腰托上气袋工作状态
 * @param  position - 腰托位置
 * @return None
 */
static void _Snf_Lumbar_Top_Write_Cmd(uint8_t position)
{
    if (position >= (uint8_t)LUMBAR_POSITION_MAX)
    {
        LUMBAR_PRINTF("Write Top invalid lumbar position: %d\n", position);
        return;
    }

#if defined(PISCES_MCM_D)
    (void)Rte_Write_DrvLumbarTopWorkSts_DrvLumbarTopWorkSts(lumbar_config[position].mode);
#elif defined(PISCES_MCM_P)
    (void)Rte_Write_PassLumbarTopWorkSts_PassLumbarTopWorkSts(lumbar_config[position].mode);
#endif
}

/**
 * @brief  输出腰托下气袋工作状态
 * @param  position - 腰托位置
 * @return None
 */
static void _Snf_Lumbar_Bottom_Write_Cmd(uint8_t position)
{
    if (position >= (uint8_t)LUMBAR_POSITION_MAX)
    {
        LUMBAR_PRINTF("Write Bottom invalid lumbar position: %d\n", position);
        return;
    }

#if defined(PISCES_MCM_D)
    (void)Rte_Write_DrvLumbarBottomWorkSts_DrvLumbarBottomWorkSts(lumbar_config[position].mode);
#elif defined(PISCES_MCM_P)
    (void)Rte_Write_PassLumbarBottomWorkSts_PassLumbarBottomWorkSts(lumbar_config[position].mode);
#endif
}

/**
 * @brief  腰托动作控制：按 lumbar_action_table 参数驱动泵阀到目标模式
 * @param  position - 腰托位置
 * @param  action - 目标动作(充气/泄气/保压)
 * @return None
 * @note   已是目标模式不重复动作；上电或无报文时命令为0(NO_ACTION)，初始(RESERVED)状态下
 *         首个周期会主动执行一次保压动作(关阀关泵)，避免阀状态从未被驱动
 */
static void _Snf_Lumbar_Action(uint8_t position, lumbar_mode_e action)
{
    const lumbar_action_param_t* param;
    lumbar_config_t*             config_ptr;

    if ((position >= (uint8_t)LUMBAR_POSITION_MAX) || (action >= LUMBAR_MODE_RESERVED))
    {
        LUMBAR_PRINTF("Lumbar invalid position %d or action %d\n", position, action);
        return;
    }

    config_ptr = &lumbar_config[position];
    param      = &lumbar_action_table[action];

    if (config_ptr->mode == action)
    {
        return;
    }

    Rte_Call_Sync_C_Lumbar_S_Power_Set_Load_States(POWER_LOAD_STATUS_NORMAL);
    LUMBAR_PRINTF("Lumbar position %d action %d\n", position, action);
    config_ptr->mode = param->target_mode;
    Rte_Call_Sync_C_Lumbar_S_Valve_Set_Work_States(param->valve_work, VALVE_LUMBAR_WORK_MASK);
    Rte_Call_Sync_C_Lumbar_S_Pump_Set_Work_States(param->pump_work, PUMP_LUMBAR_WORK_MASK);
    Rte_Call_Sync_C_Lumbar_S_Valve_Ramp_Control(config_ptr->pwm_channel_fornt, param->front_ramp);
    Rte_Call_Sync_C_Lumbar_S_Valve_Ramp_Control(config_ptr->pwm_channel_rear, param->rear_ramp);
}

/**
 * @brief  Lumbar handle control for lumbar
 * @param  None
 * @return None
 */
static void _Snf_Lumbar_Handle(void)
{
    uint8_t cmd_value = 0;

    for (uint8_t i = 0; i < (uint8_t)LUMBAR_POSITION_MAX; i++)
    {
        if (NULL != lumbar_config[i].read_net_cmd_callback)
        {
            cmd_value = lumbar_config[i].read_net_cmd_callback(lumbar_config[i].position);
        }

        if (cmd_value < (uint8_t)LUMBAR_MODE_RESERVED)
        {
            _Snf_Lumbar_Action(i, (lumbar_mode_e)cmd_value);
        }

        if (NULL != lumbar_config[i].write_net_cmd_callback)
        {
            lumbar_config[i].write_net_cmd_callback(lumbar_config[i].position);
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
    _Snf_Lumbar_Handle();
}
