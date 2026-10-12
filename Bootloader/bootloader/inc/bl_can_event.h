/**************************************************************************//**
 *
 *  \copyright  This software is the property of HiRain Technologies. Any
 *              information contained in this doc should not be reproduced,
 *              or used, or disclosed without the written authorization from
 *              HiRain Technologies.
 *
 *  \brief      This is the header file of the can module.
 *
 *  \file       bl_can.h
 *  \ingroup    driver_module
 *  \author     sijia.hao <sijia.hao@hirain.com>
 *
 *  \version    2.0.0
 *  \date       07/09/2018
 *
 *  \par        Changelist
 *      Version  | Date       | Authors          | CR# | Descriptions
 *      -------- | ---------- | ---------------- | --- | -------------
 *      02.00.00 | 07/09/2018 | mingqing.tang    | N/A | Boot060001
 *
 *****************************************************************************/
#ifndef _BL_CAN_EVENT_H_
#define _BL_CAN_EVENT_H_

/*****************************************************************************
 *  QAC Suppression
 *****************************************************************************/
/*PRQA S 783,3205,3210,3447 EOF*/

/*****************************************************************************
 *  Macro Definitions
 *****************************************************************************/

/*****************************************************************************
 *  Type Declarations
 *****************************************************************************/

/*****************************************************************************
 *  Structure Definitions
 *****************************************************************************/

/*****************************************************************************
 *  External Function Prototype Declarations
 *****************************************************************************/

/** \brief Check whether can controller is Rx successfully.*/
extern void Can_CheckRxStatus(void);
/** \brief Check can controller busoff.*/
extern void Can_CheckBusOff(void);

#endif /*_BL_CAN_EVENT_H_*/
