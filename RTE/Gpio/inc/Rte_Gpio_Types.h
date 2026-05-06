#ifndef _RTE_GPIO_TYPES_H_
#define _RTE_GPIO_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
typedef enum
{
    RTE_GPIO_LEVEL_LOW  = 0U,
    RTE_GPIO_LEVEL_HIGH = 1U,
} rte_gpio_level_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_GPIO_TYPES_H_ */