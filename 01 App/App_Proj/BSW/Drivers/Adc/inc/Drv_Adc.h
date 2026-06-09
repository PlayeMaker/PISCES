#ifndef _DRV_ADC_H_
#define _DRV_ADC_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
/************************ Macro Definitions ************************/
#define DRV_ADC_VREF       5U  /* ADC参考电压，单位V */
#define DRV_ADC_RESOLUTION 12U /* ADC分辨率 */
#define DRV_ADC_CONVERT_TO_MV(value) \
    (((value) * (DRV_ADC_VREF) * 1000) / ((1U << DRV_ADC_RESOLUTION) - 1)) /* 将ADC值转换为mv */
#define DRV_ADC_CONVERT_TIMEOUT 0xFFFFU                                    /* ADC转换超时时间 */
/************************ Type Definitions ************************/
typedef enum
{
    DRV_ADC_INSTANCE_ADC0 = 0U, /* ADC0 */
    DRV_ADC_INSTANCE_ADC1 = 1U, /* ADC1 */
    DRV_ADC_INSTANCE_MAX,
} drv_adc_instance_e;

typedef enum
{
    DRV_ADC_CHANNEL_0  = 0U,
    DRV_ADC_CHANNEL_1  = 1U,
    DRV_ADC_CHANNEL_2  = 2U,
    DRV_ADC_CHANNEL_3  = 3U,
    DRV_ADC_CHANNEL_4  = 4U,
    DRV_ADC_CHANNEL_5  = 5U,
    DRV_ADC_CHANNEL_6  = 6U,
    DRV_ADC_CHANNEL_7  = 7U,
    DRV_ADC_CHANNEL_8  = 8U,
    DRV_ADC_CHANNEL_9  = 9U,
    DRV_ADC_CHANNEL_10 = 10U,
    DRV_ADC_CHANNEL_11 = 11U,
    DRV_ADC_CHANNEL_12 = 12U,
    DRV_ADC_CHANNEL_13 = 13U,
    DRV_ADC_CHANNEL_14 = 14U,
    DRV_ADC_CHANNEL_15 = 15U,
    DRV_ADC_CHANNEL_16 = 16U,
    DRV_ADC_CHANNEL_17 = 17U,
    DRV_ADC_CHANNEL_18 = 18U,
    DRV_ADC_CHANNEL_19 = 19U,
    DRV_ADC_CHANNEL_MAX,
} drv_adc_channel_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
void     Snf_Drv_Adc_Init(void);
void     Snf_Drv_Adc_Conversion(void);
uint16_t Snf_Drv_Adc_Get_Value(uint8_t instance, uint8_t channel);

#ifdef __cplusplus
}
#endif

#endif /* _DRV_ADC_H_ */
