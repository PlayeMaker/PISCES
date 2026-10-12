#ifndef _RTE_FIFO_TYPES_H_
#define _RTE_FIFO_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
/**
 * @brief FIFO 操作状态返回值枚举
 */
typedef enum
{
    RTE_FIFO_STATUS_SUCCESS,         /**< 操作成功 */
    RTE_FIFO_STATUS_FAILURE,         /**< 操作失败（通用失败，如参数非法） */
    RTE_FIFO_STATUS_FULL,            /**< FIFO 已满 */
    RTE_FIFO_STATUS_NOT_ENOUGH_SPACE,/**< FIFO 剩余空间不足 */
    RTE_FIFO_STATUS_EMPTY,           /**< FIFO 为空，无数据可读 */
    RTE_FIFO_STATUS_PARAM_ERROR,     /**< 参数错误 */
} rte_fifo_status_e;

/************************ External Variables ************************/

/************************ Function Declarations ************************/


#ifdef __cplusplus
}
#endif

#endif /* _RTE_FIFO_TYPES_H_ */