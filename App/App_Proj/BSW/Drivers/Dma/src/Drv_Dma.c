/************************ Include Files ************************/
#include "Drv_Dma.h"
#include "Mcal.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
 * @brief  DMA initialization function
 * @param  None
 * @return None
 */
void Snf_Drv_Dma_Init(void)
{
    CddDma_Init(&CddDma_Config);
}
