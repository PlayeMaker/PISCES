/**
* @file    Port_Lld.c
*==================================================================================================
*   Project              : YTMicro AUTOSAR 4.4.0 MCAL
*   Platform             : ARM
*   Peripheral           : Port_Lld
*   Dependencies         : none
*
*   Autosar Version      : V4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   SW Version           : V0.9.1
*
*   (c) Copyright 2020-2025 Yuntu Microelectronics co.,ltd.
*   All Rights Reserved.
==================================================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
 *                                          INCLUDE FILES
==================================================================================================*/
#include "Compiler.h"
#include "Port_Lld_Reg.h"
#include "Port_Lld.h"
#include "SchM_Port.h"
/*==================================================================================================
 *                                  SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PORT_LLD_VENDOR_ID_C                      (180)
#define PORT_LLD_AR_RELEASE_MAJOR_VERSION_C       (4)
#define PORT_LLD_AR_RELEASE_MINOR_VERSION_C       (4)
#define PORT_LLD_AR_RELEASE_REVISION_VERSION_C    (0)
#define PORT_LLD_SW_MAJOR_VERSION_C               (0)
#define PORT_LLD_SW_MINOR_VERSION_C               (9)
#define PORT_LLD_SW_PATCH_VERSION_C               (1)
/*==================================================================================================
 *                                        FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and PORT_LLD header file are of the same vendor */
#if (PORT_LLD_VENDOR_ID_C != PORT_LLD_VENDOR_ID)
#error "Port_Lld.c and Port_Lld.h have different vendor ids"
#endif

/* Check if source file and PORT_LLD header file are of the same Autosar version */
#if (( PORT_LLD_AR_RELEASE_MAJOR_VERSION_C != PORT_LLD_AR_RELEASE_MAJOR_VERSION) || \
      ( PORT_LLD_AR_RELEASE_MINOR_VERSION_C != PORT_LLD_AR_RELEASE_MINOR_VERSION) || \
      ( PORT_LLD_AR_RELEASE_REVISION_VERSION_C != PORT_LLD_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Port_Lld.c and Port_Lld.h are different"
#endif

/* Check if source file and PORT_LLD header file are of the same Software version */
#if (( PORT_LLD_SW_MAJOR_VERSION_C != PORT_LLD_SW_MAJOR_VERSION) || \
      ( PORT_LLD_SW_MINOR_VERSION_C != PORT_LLD_SW_MINOR_VERSION) || \
      ( PORT_LLD_SW_PATCH_VERSION_C != PORT_LLD_SW_PATCH_VERSION))
#error "Software Version Numbers of Port_Lld.c and Port_Lld.h are different"
#endif

/*==================================================================================================
 *                                         GLOBAL VARIABLES
==================================================================================================*/
/*==================================================================================================
 *                                          LOCAL VARIABLES
==================================================================================================*/
/*==================================================================================================
 *                                          LOCAL CONSTANTS
==================================================================================================*/
#define PORT_START_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"
/** @brief Table of base addresses for Port instances. */
PORT_CONST static volatile PCTRL_Type * const PctrlBaseAddrArray[5] = PCTRL_BASE_PTRS;
#define PORT_STOP_SEC_CONST_UNSPECIFIED
#include "Port_MemMap.h"
/*==================================================================================================
 *                                           LOCAL MACROS
==================================================================================================*/
#define Port_IsCorrectPortPinId(Port, Pin) (((Port) < PORT_TOTAL_NUMBER) && ((Pin) < PORT_PIN_TOTAL_NUMBER))

#if (PORT_FIXED_PB_CONFIG == STD_ON)
#define PORT_UNUSED_PARAM(parma) ((void)parma)
#endif
/**
 * MR12 RULE 2.2 VIOLATION: The operation here is redundant as the result's value is always that of
 * the left-hand operand. This line of code has been maintained for the sake of code clarity and readability.
 */
/* PRQA S 2985, 2986 EOF */
/*==================================================================================================
 *                                          LOCAL FUNCTIONS
==================================================================================================*/
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"
/**
 * @brief This function is used to set the pin's pull configuration.
 *
 * @param PinPullConfig Target pull type
 * @param RegPCTRLPCRAddr PCTRL PCR register address
 */
PORT_FUNC LOCAL_INLINE void Port_Lld_InitPull(Port_PinPullConfigType PinPullConfig, uint32 RegPctrlPcrAddr)
{
    switch (PinPullConfig)
    {
        case PORT_PIN_NO_PULL:
            (*(volatile uint32 *)(RegPctrlPcrAddr)) &= ~(PCTRL_PCR_PE_MASK|PCTRL_PCR_PS_MASK);
            break;
        case PORT_PIN_PULLDOWN:
            (*(volatile uint32 *)(RegPctrlPcrAddr)) |= PCTRL_PCR_PE_MASK;
            (*(volatile uint32 *)(RegPctrlPcrAddr)) &= ~PCTRL_PCR_PS_MASK;
            break;
        case PORT_PIN_PULLUP:
            (*(volatile uint32 *)(RegPctrlPcrAddr)) |= (PCTRL_PCR_PE_MASK|PCTRL_PCR_PS_MASK);
            break;
        default:
            /* null */
            break;
    }
}


#if PORT_HAS_SLEW_RATE == STD_ON
/**
 * @brief This function is used to set the pin's slew rate.
 *
 * @param PinSlewRate The port pin slew rate.
 * @param RegPctrlPcrAddr PCTRL PCR register address.
 */
PORT_FUNC LOCAL_INLINE void Port_Lld_InitSRE(Port_PinSlewRateType PinSlewRate, uint32 RegPctrlPcrAddr)
{
    if (PORT_PIN_SLOW_SLEW_RATE == PinSlewRate)
    {
        (*(volatile uint32 *)(RegPctrlPcrAddr)) |= PCTRL_PCR_SRE_MASK;
    }
    else
    {
        (*(volatile uint32 *)(RegPctrlPcrAddr)) &= ~PCTRL_PCR_SRE_MASK;
    }
}
#endif

/**
 * @brief This function sets the relative register for a pin in GPIO mode.
 *
 * @details This function sets the relative register according to the pin's direction specified in PinConfigPtr.
 *
 * @param PinConfigPtr The pin config type ready for initialization.
 * @param PinHwId Hardware pin ID
 * @param PortHwId Hardware port ID
 */

PORT_FUNC LOCAL_INLINE void Port_Lld_InitGPIOMode(const Port_PinConfigType *PinConfigPtr, Port_HwPinType PinHwId, Port_HwPortType PortHwId)
{    if (PORT_PIN_IN == PinConfigPtr->Direction) /* Direction = PORT_PIN_IN */
    {
        /* Disable port pin output */
        (*(volatile uint32 *)(GPIO_POER_ADDR32(PortHwId))) &= ~((uint32)1 << (PinHwId));
        /* Enalbe port pin input */
        (*(volatile uint32 *)(GPIO_PIER_ADDR32(PortHwId))) |= (uint32)1 << (PinHwId);
        /* Config the passive filter */
        if (STD_ON == PinConfigPtr->PassiveFilter)
        {
            PctrlBaseAddrArray[PortHwId]->PCR[PinHwId] |= PCTRL_PCR_PFE_MASK; /* Enable passive filter */
        }
        else
        {
            PctrlBaseAddrArray[PortHwId]->PCR[PinHwId] &= ~PCTRL_PCR_PFE_MASK; /* Disable passive filter */
        }
        uint32 RegGpioPcrAddr = GPIO_PCR_ADDR32((uint32)PortHwId, (uint32)PinHwId);
#if PORT_HAS_DIGITAL_FILTER == STD_ON
        /* Set up Digital filter*/
        if (STD_ON == PinConfigPtr->DigitalFilter)
        {
#if defined(CPU_YTM32B1HA0)||defined(CPU_YTM32B1MC0)||defined(CPU_YTM32B1MD2)
            //TODO: seems HA0 any port can setup digital filter feature, need check and change
            PctrlBaseAddrArray[PortHwId]->PCR[PinHwId] |= PCTRL_PCR_DFE_MASK; /* Enable digital filter */
#else
            (*(volatile uint32 *)(RegGpioPcrAddr)) |= GPIO_PCR_DFE_MASK; /* Enable digital filter */
#endif
        }
        else
        {
#if defined(CPU_YTM32B1HA0)||defined(CPU_YTM32B1MC0)||defined(CPU_YTM32B1MD2)
            PctrlBaseAddrArray[PortHwId]->PCR[PinHwId] &= ~PCTRL_PCR_DFE_MASK; /* Disable digital filter */
#else
            (*(volatile uint32 *)(RegGpioPcrAddr)) &= ~GPIO_PCR_DFE_MASK; /* Disable digital filter */
#endif
        }
#endif
        /* setup invert */
        if (STD_ON == PinConfigPtr->InvertEnable)
        {
            (*(volatile uint32 *)(RegGpioPcrAddr)) |= GPIO_PCR_INVE_MASK; /* Enable invert */
        }
        else
        {
            (*(volatile uint32 *)(RegGpioPcrAddr)) &= ~GPIO_PCR_INVE_MASK; /* Disable invert */
        }
#if PORT_HAS_DIGITAL_FILTER == STD_ON
        /* setup width */
#if defined(CPU_YTM32B1HA0)||defined(CPU_YTM32B1MC0)||defined(CPU_YTM32B1MD2)
        PctrlBaseAddrArray[PortHwId]->PCR[PinHwId] &= ~PCTRL_PCR_DFW_MASK;
        PctrlBaseAddrArray[PortHwId]->PCR[PinHwId] |= PCTRL_PCR_DFW(PinConfigPtr->DigitalFilterWidth); /* Enable digital filter */
#else
        (*(volatile uint32 *)(RegGpioPcrAddr)) &= ~GPIO_PCR_DFW_MASK;
        (*(volatile uint32 *)(RegGpioPcrAddr)) |= GPIO_PCR_DFW(PinConfigPtr->DigitalFilterWidth); /* Enable digital filter */
#endif
#endif
    }
    else /* Direction = PORT_PIN_OUT */
    {
        /** [SWS_Port_00055]
         *  Set the port pin output latch to a default level (defined during configuration)
         *  before setting the port pin direction to output.
         */
        /* Config the init level */
        if (PORT_PIN_LEVEL_LOW == PinConfigPtr->InitLevel)
        {
            (*(volatile uint32 *)GPIO_PCOR_ADDR32(PortHwId)) |= (uint32)1 << (PinHwId);
        }
        else
        {
            (*(volatile uint32 *)GPIO_PSOR_ADDR32(PortHwId)) |= (uint32)1 << (PinHwId);
        }
#if (PORT_READBACK_ENABLE == STD_ON)
        (*(volatile uint32 *)(GPIO_PIER_ADDR32(PortHwId))) |= (uint32)1 << (PinHwId);
#else
        /* Disable port pin input */
        (*(volatile uint32 *)(GPIO_PIER_ADDR32(PortHwId))) &= ~((uint32)1 << (PinHwId));
#endif
#if (PORT_HAS_OUT_CMP == STD_ON)
        /* Set up Output Compare */
        if (STD_ON == PinConfigPtr->OutputCompare)
        {
            PctrlBaseAddrArray[PortHwId]->PCR[PinHwId] |= PCTRL_PCR_OCEN_MASK; /* Enable Output Compare */
        }
        else
        {
            PctrlBaseAddrArray[PortHwId]->PCR[PinHwId] &= ~PCTRL_PCR_OCEN_MASK; /* Disable Output Compare */
        }
#endif
        /* Enalbe port pin output */
        (*(volatile uint32 *)(GPIO_POER_ADDR32(PortHwId))) |= (uint32)1 << (PinHwId);
    }
}

/**
 * @brief This function sets the mode of a pin.
 *
 * @param PinConfigPtr Pointer to pin configuration.
 * @param PinHwId Hardware pin ID.
 * @param PortHwId Hardware port ID.
 *
 * @note If the pin's mode type is GPIO, the function `Port_Lld_InitGPIOMode()` will be called to set the GPIO relative register.
 */
PORT_FUNC LOCAL_INLINE void Port_Lld_InitMode(const Port_PinConfigType *PinConfigPtr, Port_HwPinType PinHwId, Port_HwPortType PortHwId)
{
    if (PORT_PIN_MODE_GPIO == PinConfigPtr->InitMode)
    {
        /* Config the relative register of GPIO mode */
        Port_Lld_InitGPIOMode(PinConfigPtr, PinHwId, PortHwId);
        /* Assign the PCR_MUX register */
        PctrlBaseAddrArray[PortHwId]->PCR[PinHwId] &= ~PCTRL_PCR_MUX_MASK;
        PctrlBaseAddrArray[PortHwId]->PCR[PinHwId] |= PCTRL_PCR_MUX(PORT_PIN_MODE_GPIO);
    }
    else
    {
        /** [SWS_Port_00055]
         *  Set the port pin output latch to a default level (defined during configuration)
         *  before setting the port pin direction to output.
         */
        /* Config the init output level to low */
        (*(volatile uint32 *)GPIO_PDOR_ADDR32(PortHwId)) &= ~((uint32)1 << (PinHwId));
        /* Disable port pin input */
        (*(volatile uint32 *)(GPIO_PIER_ADDR32(PortHwId))) &= ~((uint32)1 << (PinHwId));
        /* Disable port pin output */
        (*(volatile uint32 *)(GPIO_POER_ADDR32(PortHwId))) &= ~((uint32)1 << (PinHwId));
        /* Assign the PCR_MUX register */
        PctrlBaseAddrArray[PortHwId]->PCR[PinHwId] &= ~PCTRL_PCR_MUX_MASK;
        PctrlBaseAddrArray[PortHwId]->PCR[PinHwId] |= PCTRL_PCR_MUX(PinConfigPtr->InitMode);
    }
}

/*==================================================================================================
 *                                         GLOBAL FUNCTIONS
==================================================================================================*/
PORT_FUNC void Port_Lld_Init(const Port_ConfigType *ConfigPtr)
{
    Port_HwPortType PortHwId;
    Port_HwPinType PinHwId;
    uint8 PortAvailablePinsNumber;
    const Port_PinConfigType *PinConfigPtr;
    for (uint8 Idx = 0U; Idx < ConfigPtr->NumberOfGroup; ++Idx)
    {
        PortHwId = ConfigPtr->PortGroupConfigPtr[Idx].HwPortId;
        PinConfigPtr = ConfigPtr->PortGroupConfigPtr[Idx].PortPinConfigPtr;
        PortAvailablePinsNumber = ConfigPtr->PortGroupConfigPtr[Idx].NumberOfPortPins;
        for (uint8 PinConfigIndex = 0U; PinConfigIndex < PortAvailablePinsNumber; ++PinConfigIndex)
        {
            PinHwId = PinConfigPtr->HwPinId;
            /* Config the pull selection */
            Port_Lld_InitPull(PinConfigPtr->PullConfig, PCTRL_PCR_ADDR32((uint32)PortHwId, (uint32)PinHwId));
#if PORT_HAS_SLEW_RATE == STD_ON
            /* Config the slew rate */
            Port_Lld_InitSRE(PinConfigPtr->SlewRate, PCTRL_PCR_ADDR32((uint32)PortHwId, (uint32)PinHwId));
#endif
            /* Config the pin mode */
            Port_Lld_InitMode(PinConfigPtr, PinHwId, PortHwId);
            ++PinConfigPtr;
        }
    }
}

PORT_FUNC void Port_Lld_RefreshPortDirection(const Port_ConfigType *ConfigPtr)
{
    Port_HwPinType PinHwId;
    uint8 PortAvailablePinsNumber;
    const Port_PinConfigType *PinConfigPtr;
    for (Port_HwPortType PortHwId = 0;  PortHwId < ConfigPtr->NumberOfGroup; ++PortHwId)
    {
        PinConfigPtr = ConfigPtr->PortGroupConfigPtr[PortHwId].PortPinConfigPtr;
        PortAvailablePinsNumber = ConfigPtr->PortGroupConfigPtr[PortHwId].NumberOfPortPins;
        for (uint8 PinConfigIndex = 0; PinConfigIndex < PortAvailablePinsNumber; ++PinConfigIndex)
        {
            /* [SWS_Port_00061]*/
            if (PinConfigPtr->IsDirectionChangeable == PORT_PIN_DIRECTION_UNCHANGEABLE)
            {
                PinHwId = PinConfigPtr->HwPinId;
                /* Ensure the port pin not masked */
                SchM_Enter_Port_PORT_EXCLUSIVE_AREA_02();
                /* Config the direction */
                if (PORT_PIN_IN == PinConfigPtr->Direction) /* Direction = PORT_PIN_IN */
                {
                    /* Disable port pin output */
                    (*(volatile uint32 *)(GPIO_POER_ADDR32(PortHwId))) &= ~((uint32)1 << (PinHwId));
                    /* Enalbe port pin input */
                    (*(volatile uint32 *)(GPIO_PIER_ADDR32(PortHwId))) |= (uint32)1 << (PinHwId);
                }
                else
                {
#if (PORT_READBACK_ENABLE == STD_ON)
                    (*(volatile uint32 *)(GPIO_PIER_ADDR32(PortHwId))) |= (uint32)1 << (PinHwId);
#else
                    /* Disable port pin input */
                    (*(volatile uint32 *)(GPIO_PIER_ADDR32(PortHwId))) &= ~((uint32)1 << (PinHwId));
#endif
                    /* Enalbe port pin output */
                    (*(volatile uint32 *)(GPIO_POER_ADDR32(PortHwId))) |= (uint32)1 << (PinHwId);
                }
                SchM_Exit_Port_PORT_EXCLUSIVE_AREA_02();
            }
            ++PinConfigPtr;
        }
    }
}

PORT_FUNC boolean Port_Lld_IsPinDireChangeable(const Port_ConfigType *ConfigPtr, Port_HwPortType Port, Port_HwPinType Pin)
{
    const Port_PinConfigType *PinConfigPtr;
    uint8 PortAvailablePinsNumber;
    boolean ReturnValue = FALSE;
    PinConfigPtr = ConfigPtr->PortGroupConfigPtr[Port].PortPinConfigPtr;
    PortAvailablePinsNumber =  ConfigPtr->PortGroupConfigPtr[Port].NumberOfPortPins;
    /* Find the port pin config ,ensure whether the port pin direction changeable */
    for (uint8 PinConfigIndex = 0; (PinConfigIndex < PortAvailablePinsNumber) && (Pin != PinConfigPtr->HwPinId); ++PinConfigIndex)
    {
        ++PinConfigPtr;
    }
    if (PORT_PIN_DIRECTION_CHANGEABLE == PinConfigPtr->IsDirectionChangeable)
    {
        ReturnValue = TRUE;
    }
    return ReturnValue;
}

PORT_FUNC boolean Port_Lld_IsPinModeChangeable(const Port_ConfigType *ConfigPtr, Port_HwPortType Port, Port_HwPinType Pin)
{
    const Port_PinConfigType *PinConfigPtr;
    uint8 PortAvailablePinsNumber;
    boolean ReturnValue = FALSE;
    PinConfigPtr = ConfigPtr->PortGroupConfigPtr[Port].PortPinConfigPtr;
    PortAvailablePinsNumber =  ConfigPtr->PortGroupConfigPtr[Port].NumberOfPortPins;
    /* Find the port pin config ,ensure whether the port pin direction changeable */
    for (uint8 PinConfigIndex = 0U; (PinConfigIndex < PortAvailablePinsNumber) && (Pin != PinConfigPtr->HwPinId); ++PinConfigIndex)
    {
        ++PinConfigPtr;
    }
    if (PORT_PIN_MODE_CHANGEABLE == PinConfigPtr->IsModeChangeable)
    {
        ReturnValue = TRUE;
    }
    return ReturnValue;
}

PORT_FUNC void Port_Lld_SetPinDirection(Port_HwPortType Port, Port_HwPinType Pin, Port_PinDirectionType Direction)
{
    if (Port_IsCorrectPortPinId(Port, Pin))
    {
        SchM_Enter_Port_PORT_EXCLUSIVE_AREA_00();
        if (PORT_PIN_IN == Direction)
        {
            /* Disable port pin output */
            (*(volatile uint32 *)(GPIO_POER_ADDR32(Port))) &= ~((uint32)1 << (Pin));
            /* Enable port pin input */
            (*(volatile uint32 *)(GPIO_PIER_ADDR32(Port))) |= (uint32)1 << (Pin);
        }
        else
        {
#if (PORT_READBACK_ENABLE == STD_ON)
            (*(volatile uint32 *)(GPIO_PIER_ADDR32(Port))) |= (uint32)1 << (Pin);
#else
            /* Disable port pin input */
            (*(volatile uint32 *)(GPIO_PIER_ADDR32(Port))) &= ~((uint32)1 << (Pin));
#endif
            /* Enable port pin output */
            (*(volatile uint32 *)(GPIO_POER_ADDR32(Port))) |= (uint32)1 << (Pin);
        }
        SchM_Exit_Port_PORT_EXCLUSIVE_AREA_00();
    }
}

PORT_FUNC void Port_Lld_SetPinMode(Port_HwPortType Port, Port_HwPinType Pin, Port_PinModeType Mode)
{
    SchM_Enter_Port_PORT_EXCLUSIVE_AREA_01();
    PctrlBaseAddrArray[Port]->PCR[Pin] &= ~PCTRL_PCR_MUX_MASK;
    PctrlBaseAddrArray[Port]->PCR[Pin] |= PCTRL_PCR_MUX((uint32)Mode);
    SchM_Exit_Port_PORT_EXCLUSIVE_AREA_01();
}

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file Port_Lld.c */

