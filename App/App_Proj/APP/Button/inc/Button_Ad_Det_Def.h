BEGIN_BUTTON_AD_DET
//          (button_ad_det_id,      button_ad_min_value(mV),
//          button_ad_max_value(mV),  button_ad_check_function,
//          button_ad_release_delay(ms),  button_ad_release_event,
//          button_ad_press_delay(ms),  button_ad_press_event
//          button_ad_long_press_delay(ms),  button_ad_long_press_event)
FCT_BUTTON_AD_DET(AD_DET_TEXT, 0, 1024, Button_Ad_Det_Check_Null, 20, Button_Ad_Det_Event_Null, 20, Button_Ad_Det_Event_Null,
                  2000, Button_Ad_Det_Event_Null, 60000, Button_Ad_Det_Event_Null)

END_BUTTON_AD_DET
