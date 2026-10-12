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
    RTE_SWC_EVENT_OK = 0,  /**< 操作成功 */
    RTE_SWC_EVENT_ERROR,   /**< 操作失败 */
    RTE_SWC_EVENT_PENDING, /**< 操作挂起（进行中） */
} rte_swc_event_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_SWC_TYPES_H_ */