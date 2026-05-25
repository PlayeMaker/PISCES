/************************ Include Files ************************/
#include "Basic_Config.h"
#include "Stack.h"
#include "EcuM.h"
#include "CanTP.h"
#include "Com.h"
#include "ComM.h"
#include "CanSM.h"
#include "Dem.h"
#include "BswM.h"
#include "Rte_Log.h"
#include "Rte_Os.h"
/************************ Macro Definitions ************************/
#ifdef STACK_PRINTF_ENABLE
#define STACK_PRINTF RTE_LOG_PRINTF
#else
#define STACK_PRINTF(...)
#endif

/************************ Private Global Variables ************************/
static uint32_t can_tp_last_update_time = 0;
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
static void _Snf_Can_Manager_Handle(void);
static void _Snf_Can_Process_Handle(void);
/************************ Private Function Implementations ************************/
/**
 * @brief   Stack CAN manager handle
 * @param  None
 * @return None
 */
static void _Snf_Can_Manager_Handle(void)
{
    if (RTE_OS_IS_TIMEOUT(can_tp_last_update_time, STACK_CAN_TP_TIMEOUT))
    {
        can_tp_last_update_time = RTE_OS_GET_TICK();
        Com_MainFunctionRx();
        Com_MainFunctionTx();
        CanTp_MainFunction();
        Dcm_MainFunction();
        Dem_MainFunction();
    }
}
/**
 * @brief  Stack CAN process handle
 * @param  None
 * @return None
 */
static void _Snf_Can_Process_Handle(void)
{
    EcuM_MainFunction();
    CanSM_MainFunction();
    ComM_MainFunction(ComM_ComM_BODY_LE1_CAN);
    BswM_MainFunction();
}
/************************ Public Function Implementations ************************/
/**
 * @brief  Stack task function initialization
 * @param  None
 * @return None
 */
void Snf_Stack_Task_Init(void)
{
    EcuM_Init();
    EcuM_StartupTwo();

    EcuM_RequestRUN(EcuM_USERID_User0);
    ComM_RequestComMode(ComM_USERID_User0, COMM_FULL_COMMUNICATION);

    can_tp_last_update_time = RTE_OS_GET_TICK();
}

/**
 * @brief  Stack task function
 * @param  None
 * @return None
 */
void Snf_Stack_Task(void)
{
    _Snf_Can_Manager_Handle();
    _Snf_Can_Process_Handle();
}
