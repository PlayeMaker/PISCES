#ifndef _POWER_BAT_DEF_H_
#define _POWER_BAT_DEF_H_

/************************ Battery Detection Table ************************/
BEGIN_POWER_BAT_DEF
FCT_POWER_BAT_DEF(0U, 9000U, POWER_BAT_STATUS_LOW_VOLT, _Snf_Power_Bat_Low_Voltage_Callback)
FCT_POWER_BAT_DEF(9000U, 16000U, POWER_BAT_STATUS_NORMAL, _Snf_Power_Bat_Normal_Voltage_Callback)
FCT_POWER_BAT_DEF(17000U, POWER_BAT_INVALID_VOLT, POWER_BAT_STATUS_OVER_VOLT, _Snf_Power_Bat_Over_Voltage_Callback)
END_POWER_BAT_DEF

#endif /* _POWER_BAT_DEF_H_ */
