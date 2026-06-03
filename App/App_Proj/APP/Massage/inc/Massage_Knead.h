#ifndef _MASSAGE_KNEAD_H_
#define _MASSAGE_KNEAD_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Massage.h"
/************************ Macro Definitions ************************/

/************************ Function Declarations ************************/

/************************ Type Definitions ************************/
typedef enum
{
    INFLATE_STATUS,
    CYCLIC_STATUS,
    DEFLATE_STATUS,
}massage_knead_status_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
void _Snf_Massage_Knead_Handle(massage_config_t *massage_config);

#ifdef __cplusplus
}
#endif

#endif /* _MASSAGE_KNEAD_H_ */