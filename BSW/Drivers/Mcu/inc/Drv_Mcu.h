#ifndef _DRV_MCU_H_
#define _DRV_MCU_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Rte_Mcu_Types.h"
/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Drv_Mcu_Init(void);
void Snf_Drv_Mcu_Reset(void);
rte_mcu_reset_reason_e Snf_Drv_Mcu_Get_Reset_Reason(void);

#ifdef __cplusplus
}
#endif

#endif /* _DRV_MCU_H_ */
