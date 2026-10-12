/************************ Include Files ************************/
#include "Drv_Wdg.h"
#include "Mcal.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
 * @brief  WDG initialization function
 * @param  None
 * @return None
 */
void Snf_Drv_Wdg_Init(void)
{
    Wdg_180_Inst0_Init(&Wdg_180_Inst0_Config);
}

/**
 * @brief  WDG refresh function
 * @param  None
 * @return None
 */
void Snf_Drv_Wdg_Refresh(void)
{
    Wdg_180_Inst0_Service();
}
