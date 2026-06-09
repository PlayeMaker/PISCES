/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dem_PBcfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Dem module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Dem module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/
#ifndef DEM_PBCFG_H
#define DEM_PBCFG_H


/*******************************************************************************
*   DemConfigSet Macros
*******************************************************************************/
#define Cfg_D_Event_0x800116                                ((Dem_EventIdType)0)
#define Cfg_D_Event_0x800117                                ((Dem_EventIdType)1)
#define Cfg_D_Event_0x9C0119                                ((Dem_EventIdType)2)
#define Cfg_D_Event_0x9C0218                                ((Dem_EventIdType)3)
#define Cfg_D_Event_0x9C0311                                ((Dem_EventIdType)4)
#define Cfg_D_Event_0x9C0415                                ((Dem_EventIdType)5)
#define Cfg_D_Event_0x9C0511                                ((Dem_EventIdType)6)
#define Cfg_D_Event_0x9C0615                                ((Dem_EventIdType)7)
#define Cfg_D_Event_0x9D0119                                ((Dem_EventIdType)8)
#define Cfg_D_Event_0x9D0218                                ((Dem_EventIdType)9)
#define Cfg_D_Event_0x9D0319                                ((Dem_EventIdType)10)
#define Cfg_D_Event_0x9D0418                                ((Dem_EventIdType)11)
#define Cfg_D_Event_0x9D0511                                ((Dem_EventIdType)12)
#define Cfg_D_Event_0x9D0615                                ((Dem_EventIdType)13)
#define Cfg_D_Event_0xC00B88                                ((Dem_EventIdType)14)
#define Cfg_D_Event_0xF13C87                                ((Dem_EventIdType)15)
#define Cfg_D_Event_0xF1D187                                ((Dem_EventIdType)16)
#define Cfg_D_Event_0xF1D287                                ((Dem_EventIdType)17)
#define Cfg_D_Event_0xF3A987                                ((Dem_EventIdType)18)
#define Cfg_D_Event_0xF3B287                                ((Dem_EventIdType)19)

#define Cfg_P_Event_0x800116                                ((Dem_EventIdType)0)
#define Cfg_P_Event_0x800117                                ((Dem_EventIdType)1)
#define Cfg_P_Event_0x9C0119                                ((Dem_EventIdType)2)
#define Cfg_P_Event_0x9C0218                                ((Dem_EventIdType)3)
#define Cfg_P_Event_0x9C0311                                ((Dem_EventIdType)4)
#define Cfg_P_Event_0x9C0415                                ((Dem_EventIdType)5)
#define Cfg_P_Event_0x9C0511                                ((Dem_EventIdType)6)
#define Cfg_P_Event_0x9C0615                                ((Dem_EventIdType)7)
#define Cfg_P_Event_0x9D0119                                ((Dem_EventIdType)8)
#define Cfg_P_Event_0x9D0218                                ((Dem_EventIdType)9)
#define Cfg_P_Event_0x9D0319                                ((Dem_EventIdType)10)
#define Cfg_P_Event_0x9D0418                                ((Dem_EventIdType)11)
#define Cfg_P_Event_0x9D0511                                ((Dem_EventIdType)12)
#define Cfg_P_Event_0x9D0615                                ((Dem_EventIdType)13)
#define Cfg_P_Event_0xC00B88                                ((Dem_EventIdType)14)
#define Cfg_P_Event_0xF13C87                                ((Dem_EventIdType)15)
#define Cfg_P_Event_0xF1D387                                ((Dem_EventIdType)16)
#define Cfg_P_Event_0xF1D487                                ((Dem_EventIdType)17)
#define Cfg_P_Event_0xF3A987                                ((Dem_EventIdType)18)
#define Cfg_P_Event_0xF3B287                                ((Dem_EventIdType)19)

#define DEM_START_SEC_CONFIG_DATA
#include "Dem_MemMap.h"

extern CONST(Dem_ConfigType, DEM_CONST) Dem_PBCfgSet[2];

#define DEM_STOP_SEC_CONFIG_DATA
#include "Dem_MemMap.h"



#endif /* DEM_PBCFG_H */



