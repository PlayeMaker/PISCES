/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is the source file of the passive process driver.
 *
 *  \file       bl_proc_passive_schedule.h
 *  \ingroup    process_driver_module
 *  \author     heli.zhang <heli.zhang@hirain.com>
 *
 *  \version    5.7.0
 *  \date       25/06/2021
 *
 *  \par        Changelist
 *      Version  | Date       | Authors          | CR# | Descriptions
 *      -------- | ---------- | ---------------- | --- | ------------
 *      04.00.00 | 12/03/2012 | mingqing.tang    | N/A | Boot040001
 *      04.03.00 | 22/03/2012 | mingqing.tang    | N/A | Boot040004
 *      04.07.00 | 18/04/2012 | mingqing.tang    | N/A | Boot040008
 *      05.00.00 | 19/06/2013 | heli.zhang       | N/A | Boot050001
 *      05.01.00 | 27/03/2014 | mingqing.tang    | N/A | Boot050002
 *      05.02.00 | 27/08/2018 | beibei.xing      | N/A | Boot050015
 *
 *****************************************************************************/
#include "bl_rte.h"
#include "bl_proc_passive_schedule.h"
#include "bl_watchdog.h"
#include "Can_Cfg.h"

#include "Mcal.h"
/*****************************************************************************
 *  QAC Suppression
 *****************************************************************************/
/*PRQA S 506,602,1532,2103,3112,3227 EOF*/
/*
 * 506:Dereferencing pointer value that is possibly NULL.
 * The parameter delay is not a null pointer.
 *
 * MISRA-C:2004 20.2(602):The identifier is reserved for use by the library.
 * The Bootloader do not use any library funtion and use the underscores to
 * indicate that the function is a interal function.
 *
 * 1532:The function is only referenced in one translation unit.
 * all functions in this file are configurations in the Security Module.
 *
 * 2103:Integral promotion, unsigned short promoted to unsigned int.
 * This message will therefore only be generated when a short and an int are of
 * equal size.
 *
 * MISRA-C:2004 14.2(3112):This statement has no side-effect.
 * The DEBUG_ASSERT macro is used to debug bootloader when the BL_DEBUG is
 * enable. When the BL_DEBUG is disable, the DEBUG_ASSERT macro is null.
 *
 * 3227:The parameter is never modified and so it could be declared with const.
 *
 */

/*****************************************************************************
 *  Internal Macro Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Internal Type Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Internal Structure Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Internal Function Declarations
 *****************************************************************************/

/*****************************************************************************
 *  Internal Variable Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Global Variable Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Function Definitions
 *****************************************************************************/
/**************************************************************************//**
 *
 *  \details Passive process driver schedule function.
 *
 *  \note The corresponding adapter can't be null, otherwise system will always
 *        reset.
 *
 *  \since  V4.0.0
 *
 *****************************************************************************/

//#define CAN_ID_TYPE_NORMAL_FRAME_MASK (0x40000000U)

// #define SetTempPdu(PduHandle, Len, Id, Mask)                                   \
//   do {                                                                         \
//     TempPduInfo.swPduHandle = PduHandle;                                       \
//     TempPduInfo.id = Id | Mask;                                                \
//     TempPduInfo.length = Len;                                                  \
//   } while (0);

#define CAN_ID_TYPE_FD_FRAME_MASK (0x40000000U) //针对CANFD需要配置的掩码

unsigned int Cnt = 0U;
unsigned int TxCnt = 10U; //5U
uint8 dataBuf[64] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                     0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10};
Can_PduType TempPduInfo = {
    .swPduHandle = 60U,
    .id = 0x111U, //CAN_ID_TYPE_NORMAL_FRAME_MASK,
    .length = 8U,
    .sdu = dataBuf,
};


void Proc_PassiveSchedule(const bl_Adapter_t *adapter)
{
    BL_DEBUG_ASSERT_NO_RET(BL_NULL_PTR != adapter);

    for (;;)
    {
#if(RTE_FUN_WATCHDOG == BL_FUN_ON)
        Wdg_Feed();
#endif




        adapter->Callback();
        Rte_PeriodicSchedule(adapter->PeriodCallback);

        
        if (BL_ERR_OK == g_RteInfo.timerOps->IsTimeout()) //Tim_IsTimeout()
        {
            // Can_MainFunction_Write();
            // Can_MainFunction_Read();
            // Can_Write(CanConf_CanHardwareObject_CAN0_TX_FD,&TempPduInfo);

        }

    }
}

// boolean CanReceiveCallOut(uint8 Hrh, Can_IdType CanId, uint8 CanDataLegth,
//                           const uint8 *CanSduPtr) {
//   switch (Hrh) {
//   case CanConf_CanHardwareObject_CAN0_RX_EN_FIFO: {
//     TxCnt += 9U;
//     break;
//   }
//   }
//   return TRUE;
// }
// void CanTransmitCallOut(PduIdType TxPduId) {
//   (void)TxPduId;
//   if (TxCnt > 0) {
//     TxCnt++; //--;
//   }
// }

