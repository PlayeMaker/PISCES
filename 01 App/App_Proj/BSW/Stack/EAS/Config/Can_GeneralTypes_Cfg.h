/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Can_GeneralTypes_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Can module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Can module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/
#ifndef CAN_GENERALTYPES_CFG_H
#define CAN_GENERALTYPES_CFG_H

/*******************************************************************************
*   Includes
*******************************************************************************/
#include "ComStack_Types.h" 
#include "Can_GeneralTypes.h" 


/*******************************************************************************
*   Types
*******************************************************************************/
#define CAN_INVALID_HOH                                     ((Can_HwHandleType)0xFFU)

#define CAN_CANID_MASK                                      ((Can_IdType)0x1FFFFFFFU)
#define CAN_CANFD_INV_MASK                                  ((Can_IdType)0xBFFFFFFFU)
#define CAN_CANFD_MASK                                      ((Can_IdType)0x40000000U)
#define CAN_IDTYPE_MASK                                     ((Can_IdType)0xC0000000U)
#endif/* CAN_GERERALTYPES_CFG_H */
