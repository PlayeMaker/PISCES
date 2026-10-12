BEGIN_BUTTON_IO_DET
//          (button_io_det_id,      button_io_check_function,
//          button_io_release_delay(ms),  button_io_release_event,
//          button_io_press_delay(ms),  button_io_press_event
//          button_io_long_press_delay(ms),  button_io_long_press_event
//          button_io_viscosity_delay(ms),  button_io_viscosity_event)
FCT_BUTTON_IO_DET(IO_DET_TEXT, Button_Io_Det_Check_Null, 20, Button_Io_Det_Event_Null, 20, Button_Io_Det_Event_Null, 2000,
                  Button_Io_Det_Event_Null, 60000, Button_Io_Det_Event_Null)

END_BUTTON_IO_DET
