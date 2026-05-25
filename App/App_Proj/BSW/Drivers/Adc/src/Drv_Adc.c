/************************ Include Files ************************/
#include <stdbool.h>
#include "Drv_Adc.h"
#include "Mcal.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/
Adc_ValueGroupType   Adc0_Group0_Buf[AdcGroup_0_CHANNEL_NUMBER] = {0};
static volatile bool adc_conversion_flag                        = false;
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
 * @brief  Adc initialization function
 * @param  None
 * @return None
 */
void Snf_Drv_Adc_Init(void)
{
    Adc_Init(&Adc_Config);
    Adc_SetupResultBuffer(AdcConf_AdcConfigSet_AdcGroup_0, Adc0_Group0_Buf);
    Adc_EnableGroupNotification(AdcConf_AdcConfigSet_AdcGroup_0);
}

/**
 * @brief  Adc conversion function
 * @param  None
 * @return None
 */
void Snf_Drv_Adc_Conversion(void)
{
    adc_conversion_flag = false;
    Adc_StartGroupConversion(AdcConf_AdcConfigSet_AdcGroup_0);
    while (true != adc_conversion_flag);
}

/**
 * @brief ADC Get the conversion value function
 * @param instance ADC Instance ID
 * @param channel  ADC Channel ID
 * @return None
 */
uint16_t Snf_Drv_Adc_Get_Value(uint8_t instance, uint8_t channel)
{
    uint16_t adc_value = 0;

    (void)instance; /* 目前仅支持一个ADC实例，暂不使用instance参数 */
    if (channel >= AdcGroup_0_CHANNEL_NUMBER)
    {
        return 0; /* 无效的实例或通道 */
    }

    adc_value = (uint16_t)DRV_ADC_CONVERT_TO_MV(Adc0_Group0_Buf[channel]);
    return adc_value;
}

/**
 * @brief  ADC Group0 notification function
 * @param  None
 * @return None
 */
void ADC0_Group0CallBack(void)
{
    if (ADC_STREAM_COMPLETED == Adc_GetGroupStatus(AdcConf_AdcConfigSet_AdcGroup_0))
    {
        /*The group will automatically restart the conversion after read*/
        Adc_ReadGroup(AdcConf_AdcConfigSet_AdcGroup_0, Adc0_Group0_Buf);
        adc_conversion_flag = true;
    }
}
