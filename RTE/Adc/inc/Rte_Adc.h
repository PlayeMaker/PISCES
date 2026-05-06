#ifndef _RTE_ADC_H_
#define _RTE_ADC_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Drv_Adc.h"
/************************ Macro Definitions ************************/
#define RTE_ADC_INIT       Snf_Drv_Adc_Init
#define RTE_ADC_CONVERSION Snf_Drv_Adc_Conversion

#define RTE_ADC_GET_AIR()    Snf_Drv_Adc_Get_Value(DRV_ADC_INSTANCE_ADC0, ADC_CHANNEL_0)
#define RTE_ADC_GET_LUMBAR() Snf_Drv_Adc_Get_Value(DRV_ADC_INSTANCE_ADC0, ADC_CHANNEL_1)
/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_ADC_H_ */