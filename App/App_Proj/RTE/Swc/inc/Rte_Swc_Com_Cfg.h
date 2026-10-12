#ifndef _RTE_SWC_COM_CFG_H_
#define _RTE_SWC_COM_CFG_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/
#define RTE_SWC_PRINTF_FIFO_ID       0U     /**< Printf 模块 FIFO 通信 ID */
#define RTE_SWC_PRINTF_FIFO_MAX_SIZE 1024U  /**< Printf FIFO 缓冲区最大长度（字节） */

#define RTE_SWC_POWER_FIFO_ID        1U     /**< Power 模块 FIFO 通信 ID */
#define RTE_SWC_POWER_FIFO_MAX_SIZE  32U    /**< Power FIFO 缓冲区最大长度（字节） */

/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _RTE_SWC_COM_CFG_H_ */