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
#ifndef _BL_CAN_H_
#define _BL_CAN_H_
#include "bl_typedefs.h"
#include "bl_can_if.h"

/*****************************************************************************
 *  QAC Suppression
 *****************************************************************************/
/*PRQA S 783,3205,3210,3447 EOF*/
/*
 * 783:A subsequent declaration of the identifier means that it is being used
 * both as a structure/union member and also as a label, ordinary identifier.
 * The member of the structure is used through the structure object.
 *
 * 3205:The identifier is not used and could be removed.
 * The identifiers are used in the bl_can.c file.
 *
 * 3210:The global identifier is declared but is not used.
 * The functions are used in the bl_can_if.c file.
 *
 * MISRA-C:2004 8.8(3447):The identifier has external linkage but this
 * declaration is not in a header file.
 * The function Declarations are in the header file.
 *
 */

/*****************************************************************************
 *  Macro Definitions
 *****************************************************************************/
#define CAN_STATUS_NOINIT               (0u)
#define CAN_STATUS_IDLE                 (1u)
#define CAN_STATUS_TRANSMITTING         (2u)

#define CAN_MAX_SIZE_OF_DATA            (0x40u)
#define CAN_MAX_NUMBER_OF_CONTROLLER    (3u)

#define CAN_USED_CONTROLLER_NUMBER      (1u)
#define CAN_USED_CONTROLLER_ID          (0u)

/*****************************************************************************
 *  Type Declarations
 *****************************************************************************/
/** \brief A alias of struct _tag_CanObjectId.*/
typedef struct _tag_CanObjectId bl_CanObjectId_t;

/*****************************************************************************
 *  Structure Definitions
 *****************************************************************************/
struct _tag_CanObjectId
{
    bl_u8_t handle;
    bl_u16_t objId;
    bl_u32_t id;
};

typedef enum{
    MCM_D,
    MCM_P
} ECU_MODE;


/*****************************************************************************
 *  External Global Variable Declarations
 *****************************************************************************/

extern bl_u32_t g_dummy;
/*****************************************************************************
 *  External Function Prototype Declarations
 *****************************************************************************/
/** \brief Initialize the can module.*/
extern bl_Return_t bl_Can_Init(void);
/** \brief Deinitialize the can module.*/
extern void Can_Deinit(void);
/** \brief Transmit the data to can bus.*/
extern bl_Return_t bl_Can_Write(const bl_CanTxPdu_t *pdu);
/** \brief Receive the data from can bus.*/
extern bl_Return_t Can_Read(bl_CanRxPdu_t *pdu);
/** \brief Check whether can controller is Tx successfully.*/
extern bl_Return_t Can_CheckTxStatus(bl_ComIfHandle_t handle);
/** \brief Check can controller busoff.*/
extern void Can_BusOff_Check(void);
/** \brief The can controller into sleep status.*/
extern void Can_Sleep(void);

#endif
