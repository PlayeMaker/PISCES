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
    KNEAD_INFLATE_STATUS,
    KNEAD_CYCLIC_STATUS,
    KNEAD_DEFLATE_STATUS,
}massage_knead_status_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
void _Snf_Massage_Knead_Handle(massage_config_t *massage_config);

#ifdef __cplusplus
}
#endif

#endif /* _MASSAGE_KNEAD_H_ */