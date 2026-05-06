#ifndef _RTE_SWC_TYPES_H_
#define _RTE_SWC_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
typedef enum
{
    RTE_SWC_EVENT_OK = 0,
    RTE_SWC_EVENT_ERROR,
    RTE_SWC_EVENT_PENDING,
} rte_swc_event_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_SWC_TYPES_H_ */