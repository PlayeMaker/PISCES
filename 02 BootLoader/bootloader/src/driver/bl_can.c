/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is the source file of the can module.
 *
 *  \file       bl_can.c
 *  \ingroup    driver_module
 *  \author     sijia.hao <sijia.hao@hirain.com>
 *
 *  \version    1.2.0
 *  \date       05/08/2013
 *
 *  \par        Changelist
 *      Version  | Date       | Authors          | CR# | Descriptions
 *      -------- | ---------- | ---------------- | --- | -------------
 *      01.00.00 | 17/03/2010 | he.yang          | N/A | BootDrv010001
 *      01.01.00 | 21/02/2011 | ning.chen        | N/A | BootDrv010002
 *      01.02.00 | 05/08/2013 | sijia.hao        | N/A | BootDrv010003
 *
 *****************************************************************************/
#include "bl_common.h"
#include "bl_rte.h"
#include "bl_system.h"
#include "bl_can.h"
#include "bl_can_if_cfg.h"
#include "Can_GeneralTypes.h"
#include "Platform.h"
#include "Mcal.h"
#include "bl_booting_cfg.h"
/*****************************************************************************
 *  QAC Suppression
 *****************************************************************************/
/*PRQA S 277,303,312,506,602,781,1251,1252,1257,1258,1532,2100,2103,2465 EOF*/
/*PRQA S 3112,3120,3204,3212,3218,3227,3441,3442,3453,4130 EOF*/
/*
 * 277:An integer constant expression with negative value is being converted
 * to an unsigned type.
 *
 * MISRA-C:2004 11.3(303):Cast a pointer to an integral type.
 * To address a register must cast an integral type to a pointer.
 *
 * 312:Dangerous pointer cast results in loss of volatile qualification.
 *
 * 506:Dereferencing pointer value that is possibly NULL.
 * The parameter pdu is not a null pointer.
 *
 * MISRA-C:2004 20.2(602):The identifier is reserved for use by the library.
 * The Bootloader do not use any library funtion and use the underscores to
 * indicate that the function is a interal function.
 *
 * MISRA-C:2004 5.6(781):The identifier is used as a structure/union member.
 * The member of the structure is used through the structure object.
 *
 * 1251:Suffixed integer constant causes implicit conversion of other
 * (integral) operand.
 *
 * 1252:suffixed integer constant implicitly converted to different integer.
 *
 * 1257:Suffixed integer constant implicitly converted to smaller integer type
 * on assignment.
 *
 * 1258:Suffixed integer constant explicitly cast to another type.
 *
 * 1532:The function is only referenced in one translation unit.
 * all functions in this file are configurations in the Security Module.
 *
 * 2100:Integral promotion : unsigned char promoted to signed int.
 *
 * 2103:Integral promotion, unsigned short promoted to unsigned int.
 * This message will therefore only be generated when a short and an int are of
 * equal size.
 *
 * 2465:This 'for' loop will only be executed once.
 *
 * MISRA-C:2004 14.2(3112):This statement has no side-effect. 
 * The DEBUG_ASSERT macro is used to debug bootloader when the BL_DEBUG is
 * enable. When the BL_DEBUG is disable, the DEBUG_ASSERT macro is null.
 *
 * 3120:Hard-coded magic integer constant.
 * This is a only configuration.
 *
 * 3204:The variable is only set once and so it could be declared with the
 * 'const' qualifier.
 *
 * 3212:This explicit cast is redundant and could be removed.
 *
 * MISRA-C:2004 8.7(3218):File scope static identifier is only accessed in one
 * function.
 *
 * 3227:The parameter is never modified and so it could be declared with const.
 *
 * 3441:Function call argument contains side effects.
 *
 * 3442:Operator other than & or = applied to a volatile object.
 *
 * MISRA-C:2004 19.7(3453):A function could probably be used instead of this
 * function-like macro.
 *
 * MISRA-C:2004 12.7(4130):Bitwise operations on signed data will give
 * implementation defined results.
 *
 */

/*****************************************************************************
 *  Verify The Configurations of Macro
 *****************************************************************************/
#if ((CAN_USED_CONTROLLER_NUMBER == 0)\
    || (CAN_USED_CONTROLLER_NUMBER > CAN_MAX_NUMBER_OF_CONTROLLER))
#error "the number of used controller is error."
#endif

/*****************************************************************************
 *  Internal Macro Definitions
 *****************************************************************************/
#define CAN_EXTENDED_FRAME_MASK        (bl_u32_t)(0x80000000)

/*****************************************************************************
 *  Internal Structure Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Internal Function Declarations
 *****************************************************************************/
#if (CANIF_FUN_DYNAMIC_CANID == BL_FUN_ON)
/** \brief Set the can id to the Can IF module.*/
static void _Can_SetCanId(void);
#endif

/*****************************************************************************
 *  Internal Variable Definitions
 *****************************************************************************/
static bl_u8_t gs_CanTxStatus = CAN_STATUS_NOINIT;
bl_CanObjectId_t gs_CanObjectId[CANIFRX_TOTAL_NUM + CANIFTX_TOTAL_NUM] =
{
    {HANDLE_CAN0_RX0, 0, CANIF_PHY_RX_CANID},
    {HANDLE_CAN0_RX1, 0, CANIF_FUN_RX_CANID},
    {HANDLE_CAN0_TX0, 1, CANIF_PHY_TX_CANID}
};

/*****************************************************************************
 *  Global Variable Definitions
 *****************************************************************************/
bl_u32_t g_dummy;
/*****************************************************************************
 *  Function Definitions
 *****************************************************************************/
/**************************************************************************//**
 *
 *  \details Initialize can module.
 *
 *  \return If the can driver is initialized successfully return
 *          BL_ERR_OK. otherwise return BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK     - can driver is initialized successfully.
 *  \retval BL_ERR_NOT_OK - can driver is not initialized successfully.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
ECU_MODE CURRENT_MCU = MCM_D;
bl_Return_t bl_Can_Init(void)
{
    extern Adc_ValueGroupType Adc0_Group0_Buf[AdcGroup_0_CHANNEL_NUMBER];

    bl_Return_t ret = BL_ERR_NOT_OK;

    bl_Buffer_t data_MCMD[4] = {0xA5,0xA5,0xA5,0xA5};
    bl_Buffer_t data_MCMP[4] = {0xB5,0xB5,0xB5,0xB5};
    bl_Buffer_t dest[4];
    bl_Size_t i;

    Bl_MemCpy(&dest[0],(const bl_Buffer_t *)MCM_DATA_ADDR,MCM_DATA_SIZE);

    for(i = 0; i < MCM_DATA_SIZE ; i++)
	{
		if((dest[i] == data_MCMD[i]) || (dest[i] == data_MCMP[i]))
		{
			if(dest[i] == data_MCMD[i]) {
				CURRENT_MCU = MCM_D;
			}
			else {
				CURRENT_MCU = MCM_P;
			}
		}
		else
		{
			break;
		}
	}
    /* CAN Initialization */
    if(CURRENT_MCU == MCM_D)
    {
    	Can_Init(&Can_Config[0]);
    }
    else
    {
    	Can_Init(&Can_Config[1]);
    }

    Port_Init(&Port_Config);
    
    /* Set the controller with state as START */
    if (E_OK == Can_SetControllerMode(CanConf_CanController_CAN0, CAN_CS_STARTED))
    {
        g_RxCanId = 0;
        g_RxCanDlc = 0;
        gs_CanTxStatus = CAN_STATUS_IDLE;
        ret = BL_ERR_OK;
    }
#if (CANIF_FUN_DYNAMIC_CANID == BL_FUN_ON)
    if (BL_ERR_OK == ret)
    {
        _Can_SetCanId();
    }
#endif

    Adc_Init(&Adc_Config);

    Adc_SetupResultBuffer(AdcConf_AdcConfigSet_AdcGroup_0, Adc0_Group0_Buf);
    Dio_WriteChannel(DioConf_DioChannel_BAT_VOL_AD_EN, STD_HIGH);
    Adc_StartGroupConversion(AdcConf_AdcConfigSet_AdcGroup_0);
    
    return ret;
}

/**************************************************************************//**
 *
 *  \details Deinitialize can module.
 *
 *  \return None.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
void Can_Deinit(void)
{
    if (E_OK == Can_SetControllerMode(CanConf_CanController_CAN0,CAN_CS_STOPPED))
    {
        Can_DeInit();
    }

    return ;
}

/**************************************************************************//**
 *
 *  \details Transmit can message.
 *
 *  \param[in/out] pdu  - the pointer of can Tx PDU.
 *
 *  \return If the can driver is transmited successfully return BL_ERR_OK.
 *          otherwise return BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK       - can message is transmited successfully.
 *  \retval BL_ERR_NOT_OK   - the controller is busy or not initialized.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
bl_Return_t bl_Can_Write(const bl_CanTxPdu_t *pdu)
{
    bl_Return_t ret = BL_ERR_NOT_OK;
    Can_PduType pduInfo;

    if (gs_CanTxStatus == CAN_STATUS_IDLE)
    {
        pduInfo.id = pdu->canId;
        pduInfo.length = pdu->dlc;
        pduInfo.swPduHandle = pdu->handle;
        pduInfo.sdu = (uint8 *)pdu->frame;

        if(E_OK == Can_Write(CanConf_CanHardwareObject_CAN0_TX_FD, &pduInfo))
        {
            gs_CanTxStatus = CAN_STATUS_TRANSMITTING;
            ret = BL_ERR_OK;
        }
    }

    return ret;

}

/**************************************************************************//**
 *
 *  \details Receive can message.
 *
 *  \param[in/out] pdu  - the pointer of can Rx PDU.
 *
 *  \return If the can message is received successfully return BL_ERR_OK.
 *          otherwise return BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK       - can message is received successfully.
 *  \retval BL_ERR_NOT_OK   - no can message can be received.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
extern ECU_MODE CURRENT_MCU;
bl_Return_t Can_Read(bl_CanRxPdu_t *pdu)
{
    bl_Return_t ret = BL_ERR_NOT_OK;

    bl_u8_t i;
    bl_u32_t Canid[CANIFRX_TOTAL_NUM];
    Can_MainFunction_Read();
    if ((g_RxCanId != 0) && (g_RxCanDlc <= CAN_MAX_SIZE_OF_DATA))
    {
        if(CURRENT_MCU == MCM_D)
        {
            Canid[0] = 0x623;
            Canid[1] = 0x601;
        }
        else
        {
            Canid[0] = 0x624;
            Canid[1] = 0x601;
        }
        for (i = 0; i < CANIFRX_TOTAL_NUM; i++)
        {
            if (Canid[i] == g_RxCanId)
            {
                pdu->dlc = g_RxCanDlc;
                pdu->canId = Canid[i];
                pdu->handle = gs_CanObjectId[i].handle;
                Bl_MemCpy(pdu->frame, (const bl_Buffer_t *)g_RxCanData, CAN_MAX_SIZE_OF_DATA);
                ret = BL_ERR_OK;
                break;
            }
        }
    }
    g_RxCanId = 0;
    g_RxCanDlc = 0;

    return ret;
}

/**************************************************************************//**
 *
 *  \details Check can transmit status.
 *
 *  \param[in] handle  - the index of a frame pdu list.
 *
 *  \return If the can message is transmited successfully return
 *          BL_ERR_OK. otherwise return BL_ERR_NOT_OK.
 *
 *  \retval BL_ERR_OK       - the data is transmitted successfully.
 *  \retval BL_ERR_NOT_OK   - can driver is not transmitting data.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
bl_Return_t Can_CheckTxStatus(bl_ComIfHandle_t handle)
{
    bl_Return_t ret = BL_ERR_NOT_OK;

    if (gs_CanTxStatus == CAN_STATUS_TRANSMITTING)
    {
        Can_MainFunction_Write();
        if (E_OK == g_TxCanStatus)
        {
            gs_CanTxStatus = CAN_STATUS_IDLE;
            g_TxCanStatus = E_NOT_OK;
            ret = BL_ERR_OK;
        }
    }

    return ret;
}

/**************************************************************************//**
 *
 *  \details Check can busoff.
 *
 *  \return None.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
void Can_BusOff_Check(void)
{

}
#if (RTE_FUN_SYSTEM_SLEEP == BL_FUN_ON)
/**************************************************************************//**
 *
 *  \details Set all can controller into sleep mode.
 *
 *  \return None.
 *
 *  \note   This interface is not set the WUPE in the CTL0 register.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
void Can_Sleep(void)
{
    return ;
}
#endif
#if (CANIF_FUN_DYNAMIC_CANID == BL_FUN_ON)
/**************************************************************************//**
 *
 *  \details Set the can id.
 *
 *  \return None.
 *
 *  \since V2.0.0
 *
 *****************************************************************************/
static void _Can_SetCanId(void)
{
    bl_u32_t id;
    /*add your code to make the can id*/
#error "add your code to make the can id and delete this message."
    /*set the rx id*/
    Canif_SetRxCanId(CANIF_PHY_RX_HANDLE,id);
    /*set the tx id*/
    Canif_SetTxCanId(CANIF_TX_HANDLE,id);
}
#endif

