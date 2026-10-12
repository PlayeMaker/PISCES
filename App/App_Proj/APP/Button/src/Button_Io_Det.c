/************************ Include Files ************************/
#include <stdbool.h>
#include <stdint.h>
#include "Basic_Types.h"
#include "Rte_Gpio.h"
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

/************************ Private Global Variables ************************/
static button_io_config_t button_io_config_tab[BUTTON_IO_INPUTS] = { 0 };
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
rte_gpio_level_e Button_Io_Det_Check_Null(void)
{
    return (rte_gpio_level_e)BUTTON_IO_STATE_PRESS;
}
/**
 * @brief Init the IO button Struct
 * @param None
 * @retval None
 */
void Button_Io_Det_Init(void)
{
    button_io_config_t* button_config_ptr = NULL;
    for (uint8_t i = 0; i < BUTTON_IO_INPUTS; i++)
    {
        button_config_ptr                     = &button_io_config_tab[i];
        button_config_ptr->button_vaild_cnt   = 0;
        button_config_ptr->button_invaild_cnt = 0;
        button_config_ptr->button_state_old   = BUTTON_IO_STATE_RELEASE;
        button_config_ptr->button_state_new   = BUTTON_IO_STATE_RELEASE;
    }
}
/**
 * @brief  Loop to check the IO button
 * @param None
 * @retval None
 */
void Button_Io_Det_Polling(void)
{
    button_io_config_t* button_config_ptr = NULL;
    rte_gpio_level_e    io_level          = RTE_GPIO_LEVEL_HIGH;
    uint32_t            timeout           = 0;
    for (uint8_t i = 0; i < BUTTON_IO_INPUTS; i++)
    {
        button_config_ptr = &button_io_config_tab[i];

        io_level = button_io_check_fun_tab[i]();

        if (BUTTON_IO_VAILD_LEVEL == io_level)
        {
            button_config_ptr->button_vaild_cnt++;
            button_config_ptr->button_invaild_cnt = 0;
            timeout                               = button_config_ptr->button_vaild_cnt * BUTTON_IO_DET_POLLING_TIME_MS;

            if (timeout >= button_io_debounce_tab[i * 4 + 3])
            {
                button_config_ptr->button_state_new = BUTTON_IO_STATE_STUCK;
            }
            else if (timeout >= button_io_debounce_tab[i * 4 + 2])
            {
                button_config_ptr->button_state_new = BUTTON_IO_STATE_LONG_PRESS;
            }
            else if (timeout >= button_io_debounce_tab[i * 4 + 1])
            {
                button_config_ptr->button_state_new = BUTTON_IO_STATE_PRESS;
            }
        }
        else
        {
            button_config_ptr->button_invaild_cnt++;
            button_config_ptr->button_vaild_cnt = 0;
            timeout                             = button_config_ptr->button_invaild_cnt * BUTTON_IO_DET_POLLING_TIME_MS;

            if (timeout >= button_io_debounce_tab[i * 4])
            {
                button_config_ptr->button_state_new = BUTTON_IO_STATE_RELEASE;
            }
        }

        if (button_config_ptr->button_state_new != button_config_ptr->button_state_old)
        {
            button_config_ptr->button_state_old = button_config_ptr->button_state_new;
            button_io_event_fun_tab[i * 4 + button_config_ptr->button_state_new]();
        }
    }
}
