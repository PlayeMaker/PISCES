#ifndef _RTE_SWC_COM_H_
#define _RTE_SWC_COM_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Rte_Fifo.h"
/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
typedef struct
{
    uint8_t            id;
    rte_fifo_config_t* fifo;
} rte_swc_com_t;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
rte_fifo_status_e Rte_Swc_Fifo_Com_Put(uint8_t fifo_id, uint8_t* data, uint8_t size);
rte_fifo_status_e Rte_Swc_Fifo_Com_Handle(uint8_t fifo_id, uint8_t* data, uint8_t* size);

#ifdef __cplusplus
}
#endif

#endif /* _RTE_SWC_COM_H_ */