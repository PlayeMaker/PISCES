/************************ Include Files ************************/
#include "Basic_Types.h"
#include "Button_Com.h"
#include "Button_Io_Det.h"
#include "Button_Ad_Det.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
 * @brief  Button Detection function
 * @param  None
 * @return None
 */
void Snf_Button_Detection_Task_Init(void)
{
    Button_Io_Det_Init();
    Button_Ad_Det_Init();
}

/**
 * @brief  Button Detection function
 * @param  None
 * @return None
 */
void Snf_Button_Detection_Task(void)
{
    Button_Io_Det_Polling();
    Button_Ad_Det_Polling();
}
