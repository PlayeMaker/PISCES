#ifndef _POWER_LOAD_DEF_H_
#define _POWER_LOAD_DEF_H_

#include <stdint.h>

#ifndef UINT16_MAX
#define UINT16_MAX 0xFFFFU
#endif

/************************ Load Detection Table ************************/
BEGIN_POWER_LOAD_DEF
FCT_POWER_LOAD_DEF(POWER_LOAD_CHANNEL_PUMP,
                   0U,
                   POWER_PUMP_OPEN_CIRCUIT,
                   POWER_LOAD_STATUS_ABNORMAL,
                   0U,
                   _Snf_Power_Load_Pump_Open_Circuit_Callback)
FCT_POWER_LOAD_DEF(POWER_LOAD_CHANNEL_PUMP,
                   POWER_PUMP_OPEN_CIRCUIT,
                   POWER_PUMP_SHORT_CIRCUIT,
                   POWER_LOAD_STATUS_NORMAL,
                   0U,
                   _Snf_Power_Load_Pump_Normal_Callback)
FCT_POWER_LOAD_DEF(POWER_LOAD_CHANNEL_PUMP,
                   POWER_PUMP_SHORT_CIRCUIT,
                   UINT16_MAX,
                   POWER_LOAD_STATUS_ABNORMAL,
                   0U,
                   _Snf_Power_Load_Pump_Short_Circuit_Callback)
                   
FCT_POWER_LOAD_DEF(POWER_LOAD_CHANNEL_VALVE,
                   0U,
                   POWER_VALVE_OPEN_CIRCUIT,
                   POWER_LOAD_STATUS_ABNORMAL,
                   0U,
                   _Snf_Power_Load_Valve_Open_Circuit_Callback)
FCT_POWER_LOAD_DEF(POWER_LOAD_CHANNEL_VALVE,
                   POWER_VALVE_OPEN_CIRCUIT,
                   POWER_VALVE_SHORT_CIRCUIT,
                   POWER_LOAD_STATUS_NORMAL,
                   0U,
                   _Snf_Power_Load_Valve_Normal_Callback)
FCT_POWER_LOAD_DEF(POWER_LOAD_CHANNEL_VALVE,
                   POWER_VALVE_SHORT_CIRCUIT,
                   UINT16_MAX,
                   POWER_LOAD_STATUS_ABNORMAL,
                   0U,
                   _Snf_Power_Load_Valve_Short_Circuit_Callback)
END_POWER_LOAD_DEF

#endif /* _POWER_LOAD_DEF_H_ */