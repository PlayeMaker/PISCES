#ifndef _RTE_FIFO_H_
#define _RTE_FIFO_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdio.h>
#include <stdint.h>
#include "Rte_Fifo_Types.h"
/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
typedef struct
{
    uint8_t*          item_space;       // Start address on memory for item space.
    uint16_t          allocated_bytes;  // Size in bytes of the whole buffer.
    volatile uint16_t read_offset;      // Memory offset from which we will read data.
    volatile uint16_t write_offset;     // Memory offset where data will be written.
    uint16_t          stored_bytes;     // Number of bytes used currently by stored items.
} rte_fifo_config_t;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
rte_fifo_status_e Rte_Fifo_Create_Static(rte_fifo_config_t* fifo, uint8_t* buf, uint8_t size);
rte_fifo_status_e Rte_Fifo_Put(rte_fifo_config_t* fifo, const uint8_t* item, uint8_t size);
rte_fifo_status_e Rte_Fifo_Get(rte_fifo_config_t* fifo, uint8_t* item);
rte_fifo_status_e Rte_Fifo_Space_Is_Enough(rte_fifo_config_t* fifo, uint8_t size);

#ifdef __cplusplus
}
#endif

#endif /* _RTE_FIFO_H_ */