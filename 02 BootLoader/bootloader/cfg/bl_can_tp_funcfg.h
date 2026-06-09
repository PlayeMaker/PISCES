/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is a functional configuration file of the CAN Transport
 *              Protocol module.
 *
 *  \file       bl_can_tp_funcfg.h
 *  \ingroup    cantp_module
 *  \author     mingqing.tang <mingqing.tang@hirain.com>
 *
 *  \version    5.1.0
 *  \date       27/03/2014
 *
 *  \par        Changelist
 *      Version  | Date       | Authors          | CR# | Descriptions
 *      -------- | ---------- | ---------------- | --- | ------------
 *      05.01.00 | 27/03/2014 | mingqing.tang    | N/A | Boot050002
 *      05.02.00 | 27/03/2016 | beibei.xing      | N/A | BootSpec050010
 *      05.03.00 | 10/09/2019 | lele.liu         | N/A | BootSpec050021
 *
 *****************************************************************************/
#ifndef _BL_CAN_TP_FUNCFG_H_
#define _BL_CAN_TP_FUNCFG_H_

/*****************************************************************************
 *  Macro Definitions
 *****************************************************************************/
/** \brief The frame padding function.*/
#define CANTP_FUN_TX_FRAME_PADDING         BL_FUN_ON
#define CANTP_FUN_RX_FRAME_PADDING         BL_FUN_ON

/** \brief Ignore unexpected N_PDU function.*/
#define CANTP_IGNORE_UNEXPECTED_N_PDU      BL_FUN_ON

/** \brief The frame padding value.*/
#define CANTP_FRAME_PADDING_VALUE       (0xAAu)

/*****************************************************************************
 *  Structure Definitions
 *****************************************************************************/

/*****************************************************************************
 *  External Global Variable Declarations
 *****************************************************************************/

/*****************************************************************************
 *  External Function Prototype Declarations
 *****************************************************************************/

#endif

