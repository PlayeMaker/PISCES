/************************ Include Files ************************/
#include "Rte_Mcu.h"
#include "Rte_Platform.h"
#include "Rte_Os.h"
#include "Rte_Gpio.h"
#include "Rte_Dma.h"
#include "Rte_Uart.h"
#include "Rte_Adc.h"
#include "Rte_Pwm.h"
#include "Rte_Wdg.h"
#include "Rte_Swc.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Board_Init(void);
/************************ Private Function Implementations ************************/
/**
 * @brief  Board Hardware Init function
 * @param  None
 * @return None
 */
static void _Snf_Board_Init(void)
{
    RTE_MCU_INIT();
    RTE_PLATFORM_INIT();
    RTE_OS_INIT();
    RTE_GPIO_INIT();
    RTE_DMA_INIT();
    RTE_UART_INIT();
    RTE_ADC_INIT();
    RTE_PWM_INIT();
    RTE_WDG_INIT();
}

/************************ Public Function Implementations ************************/
/**
 * @brief  main function
 * @param  None
 * @return None
 */
int main(void)
{
    _Snf_Board_Init();
    Rte_Call_Sync_C_Main_S_App_Task_Init();

    while (1)
    {
        Rte_Call_Sync_C_Main_S_App_Task_Scheduler();
    }

    return 0;
}
