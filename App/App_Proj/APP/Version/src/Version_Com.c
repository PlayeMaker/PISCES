/************************ Include Files ************************/
#include "Version.h"
#include "Version_Data.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
 * @brief  Initialize version task function
 * @param  None
 * @return None
 * @note   每项初始化逻辑独立成函数，后续新增初始化项在此按序调用
 */
void Snf_Version_Task_Init(void)
{
    //硬件版本初始化（零件号/基线号同步）
    Snf_Version_Data_Init();
}
