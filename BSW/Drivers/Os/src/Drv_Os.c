/************************ Include Files ************************/
#include "Drv_Os.h"
#include "YTM32B1Mx_CM33_DSP_FP.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/
static volatile uint32_t os_adapter_tick_cnt = 0U;
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
 * @brief  Initialize the OS adapter
 * @param  None
 * @return None
 */
void Snf_Os_init(void)
{
    /* Configure SysTick to generate an interrupt every 1 ms */
    SysTick_Config(DRV_OS_SYSTEM_CORE_CLOCK / 1000);
}

/**
 * @brief  Get the current tick count
 * @param  None
 * @return Current tick count
 */
uint32_t Snf_Os_Get_Tick(void)
{
    return os_adapter_tick_cnt;
}

/**
 * @brief  Check if a timeout has occurred
 * @param  last_tick: Last tick count
 * @param  timeout: Timeout value
 * @return TRUE if timeout has occurred, FALSE otherwise
 */
bool Snf_Os_Is_Timeout(uint32_t last_tick, uint32_t timeout)
{
    uint32_t current_tick = Snf_Os_Get_Tick();
    if (current_tick < last_tick)
    {
        /* 处理tick计数器溢出的情况 */
        if ((DRV_OS_MAX_TICK - last_tick + current_tick) >= timeout)
        {
            return TRUE;
        }
    }
    else
    {
        if (current_tick - last_tick >= timeout)
        {
            return TRUE;
        }
    }

    return FALSE;
}

/**
 * @brief  SysTick Handler function, called every SysTick interrupt
 * @param  None
 * @return None
 */
void SysTick_Handler(void)
{
    os_adapter_tick_cnt++;
}