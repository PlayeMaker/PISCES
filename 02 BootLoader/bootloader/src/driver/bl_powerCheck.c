
#include "bl_powerCheck.h"
#include "Mcal.h"

#define DRV_ADC_CONVERT_TO_MV(value)                                           \
  (((value) * (5) * 1000) / 4095) 
#define BAT_AD_TO_VOLT(ad_value) ((ad_value) * 61 / 10)


Adc_ValueGroupType Adc0_Group0_Buf[AdcGroup_0_CHANNEL_NUMBER] = {0}; //zsd
uint16 bat_adc = 0;
uint16 bat_vol = 0;

bl_ResponseCode_t powercheckDrv(void)
{
    bl_ResponseCode_t resCode = DCM_E_POSITIVERESPONSE;
    uint16 HighPowerNum = 0;
    uint16 LowPowerNum = 0;
    uint16 NumInx = 0;

    do
    {
        if (Adc_GetGroupStatus(AdcConf_AdcConfigSet_AdcGroup_0) == ADC_STREAM_COMPLETED) 
        {
            NumInx = NumInx+1;
            Adc_ReadGroup(AdcConf_AdcConfigSet_AdcGroup_0, Adc0_Group0_Buf);
            /* Copy the result to physical buffer, and convert to mV */
            bat_adc = (uint16)DRV_ADC_CONVERT_TO_MV(Adc0_Group0_Buf[0]);
            bat_vol = BAT_AD_TO_VOLT(bat_adc);
            if (bat_vol < 8000)
            {
                LowPowerNum = LowPowerNum+1;
            }
            if (bat_vol > 17000)
            {
                HighPowerNum = HighPowerNum+1;
            }

            /* Restart the group conversion */
            Adc_StartGroupConversion(AdcConf_AdcConfigSet_AdcGroup_0);
        }
    }while(NumInx < 5);

    if (HighPowerNum > 1)
    {
        resCode = DCM_E_VOLTAGE_TOOL_HIGH;
    }
    if (LowPowerNum > 1)
    {
        resCode = DCM_E_VOLTAGE_TOOL_LOW;
    }

    return resCode;
}


