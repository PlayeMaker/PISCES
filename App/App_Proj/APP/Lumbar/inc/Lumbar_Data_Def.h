BEGIN_LUMBAR_DATA
//       (position_id, front_channel, rear_channel, read_function, write_function)
FCT_LUMBAR_DATA(LUMBAR_POSITION_TOP,    LUMBAR_TOP_CHANNEL_FRONT,    LUMBAR_TOP_CHANNEL_REAR,    _Snf_Lumbar_Top_Read_Cmd,    _Snf_Lumbar_Top_Write_Cmd)     //腰托上气袋
FCT_LUMBAR_DATA(LUMBAR_POSITION_BOTTOM, LUMBAR_BOTTOM_CHANNEL_FRONT, LUMBAR_BOTTOM_CHANNEL_REAR, _Snf_Lumbar_Bottom_Read_Cmd, _Snf_Lumbar_Bottom_Write_Cmd)  //腰托下气袋
END_LUMBAR_DATA
