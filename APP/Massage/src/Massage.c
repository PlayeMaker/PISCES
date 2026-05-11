/************************ Include Files ************************/
#include "Basic_Config.h"
#include "Massage.h"
#include "Rte_Log.h"
/************************ Macro Definitions ************************/
#ifdef MASSAGE_PRINTF_ENABLE
#define MASSAGE_PRINTF RTE_LOG_PRINTF
#else
#define MASSAGE_PRINTF(...)
#endif
/************************ Private Global Variables ************************/
static massage_config_t massage_back_config = {.mode   = MASSAGE_MODE_NONE,
                                               .zone   = MASSAGE_BAG_ZONE_BACK,
                                               .action = MASSAGE_BAG_ACTION_PRECHARGE};
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
// static void _Snf_Board_Init(void);
/************************ Private Function Implementations ************************/
/**
 * @brief  Board Hardware Init function
 * @param  None
 * @return None
 */
// static void _Snf_Board_Init(void)
// {

// }

/************************ Public Function Implementations ************************/
/**
 * @brief  Initialize massage task function
 * @param  None
 * @return None
 */
void Snf_Massage_Task_Init(void)
{
}

/**
 * @brief  Massage task function
 * @param  None
 * @return None
 */
void Snf_Massage_Task(void)
{
}
