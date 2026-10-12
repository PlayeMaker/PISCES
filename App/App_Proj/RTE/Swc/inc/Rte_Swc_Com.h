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
    uint8_t            id;   /**< FIFO 通信 ID（见 Rte_Swc_Com_Cfg.h 中的 RTE_SWC_xxx_FIFO_ID） */
    rte_fifo_config_t* fifo; /**< 指向对应 FIFO 配置对象的指针 */
} rte_swc_com_t;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
rte_fifo_status_e Rte_Swc_Fifo_Com_Put(uint8_t fifo_id, uint8_t* data, uint8_t size);
rte_fifo_status_e Rte_Swc_Fifo_Com_Handle(uint8_t fifo_id, uint8_t* data, uint8_t* size);

#ifdef __cplusplus
}
#endif

#endif /* _RTE_SWC_COM_H_ */