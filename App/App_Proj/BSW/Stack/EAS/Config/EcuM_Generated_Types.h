/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : EcuM_Generated_Types.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : EcuM module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : EcuM module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/
#ifndef ECUM_GENERATED_TYPES_H
#define ECUM_GENERATED_TYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/

#include "Mcu.h"
#include "BswM_Types.h"
#include "ComStack_Types.h"
#include "Rte_EcuM_Type.h"
#include "BswM_PBcfg.h"
#include "CanIf_Types.h"
#include "CanIf_PBcfg.h"
#include "CanSM_Types.h"
#include "CanSM_PBcfg.h"
#include "CanTp_Types.h"
#include "CanTp_PBcfg.h"
#include "Com_Types.h"
#include "Com_PBcfg.h"
#include "ComM_Types.h"
#include "ComM_PBcfg.h"
#include "Dcm_Types.h"
#include "Dcm_PBcfg.h"
#include "Dem_Types.h"
#include "Dem_PBcfg.h"
#include "PduR_Types.h"
#include "PduR_PBcfg.h"


/*******************************************************************************
*   Global Data Declaration
*******************************************************************************/

#define ECUM_USER_NUMBER                                    (1)
typedef uint8 AppModeType;
#define ECUM_USER0                                          (0x0)

typedef uint8 EcuM_ResetType;                               /*SWS_EcuM_04044*/
#define ECUM_RESET_NUMBER                                   (3)
/*The pre-defined reset target*/
#define ECUM_RESET_MCU                                      (0)
#define ECUM_RESET_WDG                                      (1)
#define ECUM_RESET_IO                                       (2)

typedef uint32 EcuM_TimeType;                               /*SWS_EcuM_04102*/
#define ECUM_CAUSE_NUMBER                                   (4)

typedef uint32 EcuM_WakeupSourceType;                       /*SWS_EcuM_04040*/
#define ECUM_WKSOURCE_NUMBER                                (5)
#define ECUM_WKSOURCE_VALID_MASK                            ((EcuM_WakeupSourceType)0x0000001F)
#define ECUM_WKSOURCE_INVALID_MASK                          ((EcuM_WakeupSourceType)0xFFFFFFE0)
/*The pre-defined wakeup sources*/
#define ECUM_WKSOURCE_POWER                                 ((EcuM_WakeupSourceType)0x00000001)
#define ECUM_WKSOURCE_RESET                                 ((EcuM_WakeupSourceType)0x00000002)
#define ECUM_WKSOURCE_INTERNAL_RESET                        ((EcuM_WakeupSourceType)0x00000004)
#define ECUM_WKSOURCE_INTERNAL_WDG                          ((EcuM_WakeupSourceType)0x00000008)
#define ECUM_WKSOURCE_EXTERNAL_WDG                          ((EcuM_WakeupSourceType)0x00000010)


#define ECUM_IS_WAKEUPSOURCE(src,mask)                      (((src) & (mask)) > (EcuM_WakeupSourceType)0)
#define ECUM_MAKE_WAKEUPSOURCE(id)                          ((uint32)(0x01) << (id))

/*SWS_EcuM_04101*/
typedef uint16 EcuM_ShutdownModeType;

typedef struct
{
    boolean Polling;
    uint32 ValidationTimeout;
    uint16 CheckTimeout;
    uint8 ComMChannelNum;
    uint16 ChannelStartNumber;
    uint8 ComMPNCNum;
    uint16 PNCStartNumber;
} EcuM_WakeupSourceConfigType;

typedef struct
{
    /*Module Configuration set*/
    P2CONST(BswM_ConfigType, AUTOMATIC, AUTOMATIC) BswMConfigPtr;
    P2CONST(CanIf_ConfigType, AUTOMATIC, AUTOMATIC) CanIfConfigPtr;
    P2CONST(CanSM_ConfigType, AUTOMATIC, AUTOMATIC) CanSMConfigPtr;
    P2CONST(CanTp_ConfigType, AUTOMATIC, AUTOMATIC) CanTpConfigPtr;
    P2CONST(Com_ConfigType, AUTOMATIC, AUTOMATIC) ComConfigPtr;
    P2CONST(ComM_ConfigType, AUTOMATIC, AUTOMATIC) ComMConfigPtr;
    P2CONST(Dcm_ConfigType, AUTOMATIC, AUTOMATIC) DcmConfigPtr;
    P2CONST(Dem_ConfigType, AUTOMATIC, AUTOMATIC) DemConfigPtr;
    P2CONST(PduR_PBConfigType,AUTOMATIC,AUTOMATIC) PduRConfigPtr;

} EcuM_FlexModuleConfigType;


#endif /* ECUM_GENERATED_TYPES_H */



