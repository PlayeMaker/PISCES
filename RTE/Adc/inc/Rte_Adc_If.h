#ifndef _RTE_ADC_IF_H_
#define _RTE_ADC_IF_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Drv_Adc.h"
/************************ Macro Definitions ************************/
#define RTE_ADC_GET_VERSION()       Snf_Drv_Adc_Get_Value(DRV_ADC_INSTANCE_ADC0, DRV_ADC_CHANNEL_0)
#define RTE_ADC_GET_NTC2()          Snf_Drv_Adc_Get_Value(DRV_ADC_INSTANCE_ADC0, DRV_ADC_CHANNEL_1)
#define RTE_ADC_GET_NTC1()          Snf_Drv_Adc_Get_Value(DRV_ADC_INSTANCE_ADC0, DRV_ADC_CHANNEL_2)
#define RTE_ADC_GET_HEAT_IS()       Snf_Drv_Adc_Get_Value(DRV_ADC_INSTANCE_ADC0, DRV_ADC_CHANNEL_3)
#define RTE_ADC_GET_NTC5()          Snf_Drv_Adc_Get_Value(DRV_ADC_INSTANCE_ADC0, DRV_ADC_CHANNEL_4)
#define RTE_ADC_GET_NTC4()          Snf_Drv_Adc_Get_Value(DRV_ADC_INSTANCE_ADC0, DRV_ADC_CHANNEL_5)
#define RTE_ADC_GET_NTC3()          Snf_Drv_Adc_Get_Value(DRV_ADC_INSTANCE_ADC0, DRV_ADC_CHANNEL_6)
#define RTE_ADC_GET_PUMP_VALVE_IS() Snf_Drv_Adc_Get_Value(DRV_ADC_INSTANCE_ADC0, DRV_ADC_CHANNEL_7)
#define RTE_ADC_GET_BAT_VOL()       Snf_Drv_Adc_Get_Value(DRV_ADC_INSTANCE_ADC0, DRV_ADC_CHANNEL_8)
/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_ADC_IF_H_ */