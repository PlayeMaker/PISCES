#ifndef _MASSAGE_RAP_CYCLIC_H_
#define _MASSAGE_RAP_CYCLIC_H_
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
bool Snf_Cyclic_Top_Double_Intensity_High(massage_config_t *massage_config);
bool Snf_Cyclic_Right_Double_Intensity_High(massage_config_t *massage_config);
bool Snf_Cyclic_Left_Double_Intensity_High(massage_config_t *massage_config);
bool Snf_Cyclic_Top_Double_Intensity_Low(massage_config_t *massage_config);
bool Snf_Cyclic_Right_Double_Intensity_Low(massage_config_t *massage_config);
bool Snf_Cyclic_Left_Double_Intensity_Low(massage_config_t *massage_config);
bool Snf_Cyclic_Top_Single_Intensity_High(massage_config_t *massage_config);
bool Snf_Cyclic_Right_Single_Intensity_High(massage_config_t *massage_config);
bool Snf_Cyclic_Left_Single_Intensity_High(massage_config_t *massage_config);
bool Snf_Cyclic_Top_Single_Intensity_Low(massage_config_t *massage_config);
bool Snf_Cyclic_Right_Single_Intensity_Low(massage_config_t *massage_config);
bool Snf_Cyclic_Left_Single_Intensity_Low(massage_config_t *massage_config);

#ifdef __cplusplus
}
#endif

#endif /* _MASSAGE_RAP_CYCLIC_H_ */