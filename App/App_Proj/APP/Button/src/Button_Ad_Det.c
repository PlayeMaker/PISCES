/************************ Include Files ************************/
#include <stdbool.h>
#include <stdint.h>
#include "Basic_Types.h"
#include "Rte_Adc_If.h"
#include "Rte_Swc.h"

#include "Button_Ad_Det.h"
#include "Button_Ad_Det_Class.h"
#include "Button_Ad_Det_Def.h"
#include "Button_Ad_Det_Class.h"
#include "Button_Ad_Det_Def.h"
#include "Button_Ad_Det_Class.h"
#include "Button_Ad_Det_Def.h"
#include "Button_Ad_Det_Class.h"
#include "Button_Ad_Det_Def.h"
#include "Button_Ad_Det_Class.h"
#include "Button_Ad_Det_Def.h"
#include "Button_Ad_Det_Class.h"
#include "Button_Ad_Det_Def.h"
#include "Button_Ad_Det_Class.h"
#include "Button_Ad_Det_Def.h"
#include "Button_Ad_Det_Class.h"
#include "Button_Ad_Det_Def.h"
#include "Button_Ad_Det_Class.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/
static button_ad_config_t button_ad_config_tab[BUTTON_AD_INPUTS] = { 0 };
/************************ Public Global Variables ************************/

/************************ Private Function Declarations **************************/

/************************ Private Function Implementations *************************/

/************************ Public Function Implementations ***************************/
/**
 * @brief  Button AD Event Null function
 * @param None
 * @retval None
 */
void Button_Ad_Det_Event_Null(void)
{
}
/**
 * @brief  Check the state of the AD button, this function shouldhardware connection and logic level
 * @param None be implemented according to the actual 
 * @retval The state of the AD button
 */
uint16_t Button_Ad_Det_Check_Null(void)
{
    return 0;
}
/**
 * @brief Init the AD button Struct
 * @param None
 * @retval None
 */
void Button_Ad_Det_Init(void)
{
    button_ad_config_t* button_config_ptr = NULL;
    for (uint8_t i = 0; i < BUTTON_AD_INPUTS; i++)
    {
        button_config_ptr                     = &button_ad_config_tab[i];
        button_config_ptr->button_vaild_cnt   = 0;
        button_config_ptr->button_invaild_cnt = 0;
        button_config_ptr->button_state_old   = BUTTON_AD_STATE_RELEASE;
        button_config_ptr->button_state_new   = BUTTON_AD_STATE_RELEASE;
    }
}
/**
 * @brief  Loop to check the AD button
 * @param None
 * @retval None
 */
void Button_Ad_Det_Polling(void)
{
    button_ad_config_t* button_config_ptr = NULL;
    uint16_t            adc_vol           = 0;
    uint32_t            timeout           = 0;
    for (uint8_t i = 0; i < BUTTON_AD_INPUTS; i++)
    {
        button_config_ptr = &button_ad_config_tab[i];

        adc_vol = button_ad_check_fun_tab[i]();

        if (adc_vol >= button_ad_vild[i * 2] && adc_vol <= button_ad_vild[i * 2 + 1])
        {
            button_config_ptr->button_vaild_cnt++;
            button_config_ptr->button_invaild_cnt = 0;
            timeout                               = button_config_ptr->button_vaild_cnt * BUTTON_AD_DET_POLLING_TIME_MS;

            if (timeout >= button_ad_debounce_tab[i * 4 + 3])
            {
                button_config_ptr->button_state_new = BUTTON_AD_STATE_STUCK;
            }
            else if (timeout >= button_ad_debounce_tab[i * 4 + 2])
            {
                button_config_ptr->button_state_new = BUTTON_AD_STATE_LONG_PRESS;
            }
            else if (timeout >= button_ad_debounce_tab[i * 4 + 1])
            {
                button_config_ptr->button_state_new = BUTTON_AD_STATE_PRESS;
            }
        }
        else
        {
            button_config_ptr->button_invaild_cnt++;
            button_config_ptr->button_vaild_cnt = 0;
            timeout                             = button_config_ptr->button_invaild_cnt * BUTTON_AD_DET_POLLING_TIME_MS;

            if (timeout >= button_ad_debounce_tab[i * 4])
            {
                button_config_ptr->button_state_new = BUTTON_AD_STATE_RELEASE;
            }
        }

        if (button_config_ptr->button_state_new != button_config_ptr->button_state_old)
        {
            button_config_ptr->button_state_old = button_config_ptr->button_state_new;
            button_ad_event_fun_tab[i * 4 + button_config_ptr->button_state_new]();
        }
    }
}
