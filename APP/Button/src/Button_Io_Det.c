/************************ Include Files ************************/
#include <stdbool.h>
#include <stdint.h>

#include "App_Task_Cfg.h"
#include "Basic_Types.h"
#include "Rte_Swc.h"

#include "Button_Io_Det.h"
#include "Button_Io_Det_Class.h"
#include "Button_Io_Det_Def.h"
#include "Button_Io_Det_Class.h"
#include "Button_Io_Det_Def.h"
#include "Button_Io_Det_Class.h"
#include "Button_Io_Det_Def.h"
#include "Button_Io_Det_Class.h"
#include "Button_Io_Det_Def.h"
#include "Button_Io_Det_Class.h"
#include "Button_Io_Det_Def.h"
#include "Button_Io_Det_Class.h"
#include "Button_Io_Det_Def.h"
#include "Button_Io_Det_Class.h"
#include "Button_Io_Det_Def.h"
#include "Button_Io_Det_Class.h"
/************************ Macro Definitions ************************/
#define BUTTON_IO_DEFAULT_STATE 0xFFFFFFFF
/************************ Private Global Variables ************************/
static uint16_t button_io_timer_cumulative[BUTTON_IO_INPUTS] = {0};
static bool     button_io_long_press_flag[BUTTON_IO_INPUTS]  = {0};
static uint32_t button_io_last_state                         = BUTTON_IO_DEFAULT_STATE;  // Last state of the IO

/************************ Public Global Variables ************************/

/************************ Private Function Declarations **************************/

/************************ Private Function Implementations *************************/

/************************ Public Function Implementations ***************************/
/**
 * @brief  Button IO Event Null function
 * @param None
 * @retval None
 */
void Button_Io_Det_Event_Null(void)
{
}
/**
 * @brief  Check the state of the IO button, this function should be implemented according to the actual hardware connection and logic level
 * @param None
 * @retval The state of the IO button, return value should be one of button_io_state_e
 */
uint8_t Button_Io_Det_Check_Text(void)
{
    return (uint8_t)BUTTON_IO_STATE_PRESS;
}
/**
 * @brief  Event function for IO button press, this function will be called when a press event is detected
 * @param None
 * @retval None
 */
void Button_Io_Press_Event_Text(void)
{

}
/**
 * @brief  Event function for IO button long press, this function will be called when a long press event is detected
 * @param None
 * @retval None
 */
void Button_Io_Long_Press_Event_Text(void)
{

}
/**
 * @brief  Loop to check the IO button
 * @param None
 * @retval FALSE
 */
void Button_Io_Det_Polling(void)
{
    bool              result = FALSE;
    uint8_t new_io_det_state;
    uint8_t old_io_det_state;
    uint16_t          timer_deb;
    uint16_t          long_press_timer_deb;
    button_io_state_e button_io_state;

    for (uint8_t i = 0; i < BUTTON_IO_INPUTS; i++)
    {
        result = FALSE;
        button_io_timer_cumulative[i] += BUTTON_TASK_PERIOD_MS;
        old_io_det_state = (uint8_t)SNF_GET_BIT(button_io_last_state, i);

        new_io_det_state = (uint8_t)button_io_check_fun_tab[i]();
        timer_deb        = (BUTTON_IO_STATE_RELEASE == new_io_det_state ? button_io_debounce_tab[i * 3]
                                                                        : button_io_debounce_tab[i * 3 + 1]);
        long_press_timer_deb = button_io_debounce_tab[i * 3 + 2];

        if (button_io_timer_cumulative[i] >= timer_deb && new_io_det_state != old_io_det_state &&
            new_io_det_state == BUTTON_IO_STATE_RELEASE)
        {  // 按键释放判断,主要处理长按之后的释放状态
            button_io_state = (button_io_long_press_flag[i] == TRUE ? BUTTON_IO_STATE_RELEASE : BUTTON_IO_STATE_PRESS);
            result          = TRUE;
        }
        else if (button_io_timer_cumulative[i] >= long_press_timer_deb && new_io_det_state != old_io_det_state &&
                 new_io_det_state == BUTTON_IO_STATE_PRESS)
        {  // 按键长按判断
            button_io_state              = BUTTON_IO_STATE_LONG_PRESS;
            button_io_long_press_flag[i] = TRUE;
            result                       = TRUE;
        }
        else if (button_io_timer_cumulative[i] >= timer_deb && new_io_det_state != old_io_det_state &&
                 new_io_det_state == BUTTON_IO_STATE_PRESS)
        {  // 按键短按判断
            button_io_long_press_flag[i] = FALSE;
        }
        else if (new_io_det_state == old_io_det_state)
        {  // 无事件判断
            button_io_timer_cumulative[i] = 0;
        }

        if (result)
        {
            result                        = FALSE;
            button_io_long_press_flag[i]  = FALSE;
            button_io_timer_cumulative[i] = 0;

            if (BUTTON_IO_STATE_RELEASE == button_io_state)
                SNF_CLR_BIT(button_io_last_state, i);
            else
                SNF_SET_BIT(button_io_last_state, i);

            button_io_event_fun_tab[i * 3 + button_io_last_state]();
        }
    }
}
