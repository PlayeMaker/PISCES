/************************ Include Files ************************/
#include <stdbool.h>
#include "Rte_Type.h"
#include "Power_Sleep.h"
#include "Power_Def.h"
#include "Rte_Adc.h"
#include "Rte_Com.h"
#include "Rte_Dma.h"
#include "Rte_Gpio.h"
#include "Rte_Gpio_If.h"
#include "Rte_Log.h"
#include "Rte_Mcu.h"
#include "Rte_Os.h"
#include "Rte_Pwm.h"
#include "Rte_Uart.h"
#include "Rte_Wdg.h"

/************************ Macro Definitions ************************/
#ifdef POWER_PRINTF_ENABLE
#define POWER_LOG_PRINTF RTE_LOG_PRINTF
#else
#define POWER_LOG_PRINTF(...)
#endif

/************************ Private Function Declarations ************************/

/************************ Private Global Variables ************************/


/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
void Snf_Power_Sleep_Init(void)
{

}

void Snf_Power_Sleep_Task(void)
{
    PNC9_Sts_IDT                 current_pnc9_sts = (PNC9_Sts_IDT)POWER_PNC_STATUS_INVALID;
    PNC_DFT_IDT                  current_pnc_DFT  = (PNC_DFT_IDT)POWER_PNC_STATUS_INVALID;
    static volatile PNC9_Sts_IDT last_pnc9_sts    = (PNC9_Sts_IDT)POWER_PNC_STATUS_INVALID;
    static volatile PNC_DFT_IDT  last_pnc_DFT     = (PNC_DFT_IDT)POWER_PNC_STATUS_INVALID;

    Rte_Read_PNC9_Sts_PNC9_Sts(&current_pnc9_sts);
    Rte_Read_PNC_DFT_PNC_DFT(&current_pnc_DFT);

    if (((PNC9_Sts_IDT)POWER_PNC_STATUS_ACTIVE == last_pnc9_sts || (PNC_DFT_IDT)POWER_PNC_STATUS_ACTIVE == last_pnc_DFT) &&
        ((PNC9_Sts_IDT)POWER_PNC_STATUS_INACTIVE == current_pnc9_sts &&
         (PNC_DFT_IDT)POWER_PNC_STATUS_INACTIVE == current_pnc_DFT))
    {
        POWER_LOG_PRINTF("Power down form pnc\r\n");
        // Com_IpduGroupStop(Com_BODY_LE1_CANTx);
        //下电前保存必要数据到NvM
        Rte_Call_Sync_C_Power_S_Memory_Sync_Write_All_Block();
    }
    else if (((PNC9_Sts_IDT)POWER_PNC_STATUS_INACTIVE == last_pnc9_sts ||
              (PNC_DFT_IDT)POWER_PNC_STATUS_INACTIVE == last_pnc_DFT) &&
             ((PNC9_Sts_IDT)POWER_PNC_STATUS_ACTIVE == current_pnc9_sts &&
              (PNC_DFT_IDT)POWER_PNC_STATUS_ACTIVE == current_pnc_DFT))
    {
        POWER_LOG_PRINTF("Power on form pnc\r\n");
        // Com_IpduGroupStart(Com_BODY_LE1_CANTx, false);
    }

    last_pnc9_sts = current_pnc9_sts;
    last_pnc_DFT  = current_pnc_DFT;
}

power_sleep_state_e Snf_Power_Sleep_Get_State(void)
{
    return POWER_SLEEP_STATE_AWAKE;
}