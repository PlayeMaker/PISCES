/************************ Include Files ************************/
#include "Rte_Os.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
 * @brief 延时函数，通过系统tick计数实现毫秒级延时
 * @param ms 需要延时的毫秒数
 * @note 该函数通过获取当前系统tick值，并持续检测是否达到指定延时时间来实现延时功能
 */
void Rte_Os_Hal_Delay(uint32_t ms)
{
    uint32_t tick = RTE_OS_GET_TICK();     // 获取当前系统 tick 值作为基准时间
    while (!RTE_OS_IS_TIMEOUT(tick, ms));  // 持续检测是否超时，直到达到指定延时时间
}
