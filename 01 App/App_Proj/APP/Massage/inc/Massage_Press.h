#ifndef _MASSAGE_PRESSING_H_
#define _MASSAGE_PRESSING_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Massage.h"
/************************ Macro Definitions ************************/

/************************ Function Declarations ************************/

/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Massage_3_Point_Press(massage_config_t *massage_config);
void Snf_Massage_Shoulder_Bag_Point_Press(massage_config_t *massage_config);
void Snf_Knead_Bag_Cyclic_Press_Clockwise(massage_config_t *massage_config);
void Snf_Knead_Bag_Cyclic_Press_Anticlockwise(massage_config_t *massage_config);

#ifdef __cplusplus
}
#endif

#endif /* _MASSAGE_PRESSING_H_ */