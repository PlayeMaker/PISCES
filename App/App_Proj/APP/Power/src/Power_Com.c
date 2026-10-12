/************************ Include Files ************************/
#include "Power_Com.h"
#include "Power_Bat.h"
#include "Power_Load.h"
#include "Power_Sleep.h"
#include "Rte_Gpio_If.h"
#include "Rte_Log.h"
#include "Rte_Mcu.h"
#include "Rte_Os.h"
#include "Rte_Swc_Com.h"
#include "Rte_Swc_Com_Cfg.h"

/************************ Macro Definitions ************************/
#ifdef POWER_PRINTF_ENABLE
#define POWER_LOG_PRINTF RTE_LOG_PRINTF
#else
#define POWER_LOG_PRINTF(...)
#endif

/************************ Private Function Declarations ************************/
static void _Snf_Power_Get_Response(void);
static void Snf_Power_Message_Box_Handle(void);

/************************ Private Function Implementations ************************/
static void _Snf_Power_Get_Response(void)
{
    rte_mcu_reset_reason_e reset_reason = RTE_MCU_GET_RESET_REASON();
    POWER_LOG_PRINTF("Reset reason: %d\n", reset_reason);
}

/**
 * @brief  Handle messages in the power message box, should be called periodically in the power task
 * @param  None
 * @return None
 */
static void Snf_Power_Message_Box_Handle(void)
{
    uint8_t power_rev_buf[POWER_REV_BUF_SIZE] = { 0 };
    uint8_t power_rev_size                    = 0;
    if (RTE_FIFO_STATUS_SUCCESS == Rte_Swc_Fifo_Com_Handle(RTE_SWC_POWER_FIFO_ID, power_rev_buf, &power_rev_size))
    {
        // 处理接收到的数据
    }
}

/************************ Public Function Implementations ************************/
void Snf_Power_Reset(void)
{
    RTE_MCU_RESET();
}

void Snf_Power_Task_Init(void)
{
    _Snf_Power_Get_Response();
    RTE_GPIO_BAT_VOL_AD_ENABLE();
    RTE_GPIO_5V_LOAD_ENABLE();
    Rte_Os_Hal_Delay(POWER_5V_LOAD_ENABLE_TIMEOUT);  // 等待5V电源稳定
    Snf_Power_Load_Init();
}

void Snf_Power_Task(void)
{
    Snf_Power_Bat_Task();
    Snf_Power_Load_Task();
    Snf_Power_Sleep_Task();
    Snf_Power_Message_Box_Handle();
}
