#ifndef _BASIC_Type_H_
#define _BASIC_Type_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
/************************ Macro Definitions ************************/
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

#define RSHIFT(x, n)  (x >> n)
#define LSHIFT(x, n)  (x << n)

#define SNF_GET_BIT(x, bit) ((x & (1 << bit)) >> bit)
#define SNF_SET_BIT(x, bit) (x |= (1 << bit))
#define SNF_CLR_BIT(x, bit) (x &= ~(1 << bit))

#define SNF_ABS_DIFF(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))
/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _BASIC_Type_H_ */