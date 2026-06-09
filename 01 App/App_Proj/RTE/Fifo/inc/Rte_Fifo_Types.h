#ifndef _RTE_FIFO_TYPES_H_
#define _RTE_FIFO_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
typedef enum
{
    RTE_FIFO_STATUS_SUCCESS,
    RTE_FIFO_STATUS_FAILURE,
    RTE_FIFO_STATUS_FULL,
    RTE_FIFO_STATUS_NOT_ENOUGH_SPACE,
    RTE_FIFO_STATUS_EMPTY,
    RTE_FIFO_STATUS_PARAM_ERROR,
} rte_fifo_status_e;

/************************ External Variables ************************/

/************************ Function Declarations ************************/


#ifdef __cplusplus
}
#endif

#endif /* _RTE_FIFO_TYPES_H_ */