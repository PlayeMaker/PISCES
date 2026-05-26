/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Rte_Type.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Rte module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Rte module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/

/*PRQA S 4640 EOF*/
/*The macros 'ECUC, ECUM, E2E' are standard requirement, could not conflict in the future
with the name of a macro in '<erron.h>'.*/

/*PRQA S 778,779,789,791,792 EOF*/
/*
Names in this file may not follow relevant rules.
*/

/*PRQA S 3132 EOF*/
/*
Hard coded 'magic' number, '%s', used to define the size of an array.
*/

#ifndef RTE_TYPE_H
#define RTE_TYPE_H
/*******************************************************************************
*   Includes.
*******************************************************************************/
#include "Rte.h"

#define RTE_TRUE                                     ((boolean)1)
#define RTE_FALSE                                    ((boolean)0)
#define RTE_SERVER_RESPONSE_READY                    0
#define RTE_SERVER_RESPONSE_SUCCESS                  1
#define RTE_CLIENT_REQUESET_CLEAR                    0
#define RTE_CLIENT_REQUESET_SET                      1


/*******************************************************************************
* Macros and Typedef
*******************************************************************************/
/*SWS_ComM_00669*/
typedef uint8 ComM_InhibitionStatusType;
#define COMM_WAKE_UP_INHIBITION_ACTIVE_BIT       ((ComM_InhibitionStatusType)0x1)
#define COMM_LIMITED_TO_NO_COM_BIT               ((ComM_InhibitionStatusType)0x2)
#define COMM_INHIBITION_INVALID_MASK             ((ComM_InhibitionStatusType)0xFC)

/*SWS_ComM_00672*/
typedef uint8 ComM_ModeType;
/*ComM state machine is in "No Communication" mode. Configured channel shall have no transmission or reception capability.*/
#define COMM_NO_COMMUNICATION                         ((ComM_ModeType)0)
/*ComM state machine is in "Silent Communication" mode. Configured channel shall have only reception capability, no transmission capability.*/
#define COMM_SILENT_COMMUNICATION                     ((ComM_ModeType)1)
/*ComM state machine is in "Full Communication" mode. Configured channel shall have both transmission and reception capability.*/
#define COMM_FULL_COMMUNICATION                       ((ComM_ModeType)2)
/*ComM state machine is in "Full Communication" mode. Configured channel shall have both transmission and reception towards the lower layer
(e.g. Ethernet hardware compliant to OA TC10). This is only for internal use within the ComM channel statemachine.*/
#define COMM_FULL_COMMUNICATION_WITH_WAKEUP_REQUEST   ((ComM_ModeType)3)

/*SWS_ComM_00670*/
typedef uint8 ComM_UserHandleType;
#define COMM_NOT_USED_USER_ID          ((ComM_UserHandleType)255)



/*SWS_Dcm_00977*/
typedef uint8 Dcm_SecLevelType;
#define DCM_SEC_LEV_LOCKED                                  (Dcm_SecLevelType)0
/*User creation*/
#define DCM_SEC_LEV_L2                                      (Dcm_SecLevelType)2
#define DCM_SEC_LEV_ALL                                     (Dcm_SecLevelType)255

/*SWS_Dcm_00978*/
typedef uint8 Dcm_SesCtrlType;
/*Sub Service Id*/
#define DCM_DEFAULT_SESSION                                 (Dcm_SesCtrlType)0x01
#define DCM_PROGRAMMING_SESSION                             (Dcm_SesCtrlType)0x02
#define DCM_EXTENDED_DIAGNOSTIC_SESSION                     (Dcm_SesCtrlType)0x03
#define DCM_FACTORYTEST_SESSION                             (Dcm_SesCtrlType)0x66

/*SWS_Dcm_00979*/
/*ECUC_Dcm_01110*/
typedef uint8 Dcm_ProtocolType;
#define DCM_OBD_ON_CAN                                     (Dcm_ProtocolType)0x00
#define DCM_OBD_ON_FLEXRAY                                 (Dcm_ProtocolType)0x01
#define DCM_OBD_ON_IP                                      (Dcm_ProtocolType)0x02
#define DCM_UDS_ON_CAN                                     (Dcm_ProtocolType)0x03
#define DCM_UDS_ON_FLEXRAY                                 (Dcm_ProtocolType)0x04
#define DCM_UDS_ON_IP                                      (Dcm_ProtocolType)0x05
#define DCM_ROE_ON_CAN                                     (Dcm_ProtocolType)0x06
#define DCM_ROE_ON_FLEXRAY                                 (Dcm_ProtocolType)0x07
#define DCM_ROE_ON_IP                                      (Dcm_ProtocolType)0x08
#define DCM_PERIODICTRANS_ON_CAN                           (Dcm_ProtocolType)0x09
#define DCM_PERIODICTRANS_ON_FLEXRAY                       (Dcm_ProtocolType)0x0A
#define DCM_PERIODICTRANS_ON_IP                            (Dcm_ProtocolType)0x0B

#define DCM_NO_ACTIVE_PROTOCOL                             (Dcm_ProtocolType)0x0C

#define DCM_UDS_ON_LIN                                     (Dcm_ProtocolType)0x0D
/*0x0E..0xEF Reserved for further AUTOSAR implementation*/
#define DCM_SUPPLIER_1                                     (Dcm_ProtocolType)0xF0
#define DCM_SUPPLIER_2                                     (Dcm_ProtocolType)0xF1
#define DCM_SUPPLIER_3                                     (Dcm_ProtocolType)0xF2
#define DCM_SUPPLIER_4                                     (Dcm_ProtocolType)0xF3
#define DCM_SUPPLIER_5                                     (Dcm_ProtocolType)0xF4
#define DCM_SUPPLIER_6                                     (Dcm_ProtocolType)0xF5
#define DCM_SUPPLIER_7                                     (Dcm_ProtocolType)0xF6
#define DCM_SUPPLIER_8                                     (Dcm_ProtocolType)0xF7
#define DCM_SUPPLIER_9                                     (Dcm_ProtocolType)0xF8
#define DCM_SUPPLIER_10                                    (Dcm_ProtocolType)0xF9
#define DCM_SUPPLIER_11                                    (Dcm_ProtocolType)0xFA
#define DCM_SUPPLIER_12                                    (Dcm_ProtocolType)0xFB
#define DCM_SUPPLIER_13                                    (Dcm_ProtocolType)0xFC
#define DCM_SUPPLIER_14                                    (Dcm_ProtocolType)0xFD
#define DCM_SUPPLIER_15                                    (Dcm_ProtocolType)0xFE


/*SWS_Dcm_00980*/
typedef uint8 Dcm_NegativeResponseCodeType;
#define DCM_POS_RESP                                       (Dcm_NegativeResponseCodeType)0x00
/*range of values 0x01..0x0F reserved by ISO 14229*/
#define DCM_E_GENERALREJECT                                (Dcm_NegativeResponseCodeType)0x10
#define DCM_E_SERVICENOTSUPPORTED                          (Dcm_NegativeResponseCodeType)0x11
#define DCM_E_SUBFUNCTIONNOTSUPPORTED                      (Dcm_NegativeResponseCodeType)0x12
#define DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT        (Dcm_NegativeResponseCodeType)0x13
#define DCM_E_RESPONSETOOLONG                              (Dcm_NegativeResponseCodeType)0x14
/*range of values 0x15..0x20 reserved by ISO 14229*/
#define DCM_E_BUSYREPEATREQUEST                            (Dcm_NegativeResponseCodeType)0x21
#define DCM_E_CONDITIONSNOTCORRECT                         (Dcm_NegativeResponseCodeType)0x22
/*value 0x23 reserved by ISO 14229*/
#define DCM_E_REQUESTSEQUENCEERROR                         (Dcm_NegativeResponseCodeType)0x24
#define DCM_E_NORESPONSEFROMSUBNETCOMPONENT                (Dcm_NegativeResponseCodeType)0x25
#define DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION    (Dcm_NegativeResponseCodeType)0x26
/*range of values 0x27..0x30 reserved by ISO 14229*/
#define DCM_E_REQUESTOUTOFRANGE                            (Dcm_NegativeResponseCodeType)0x31
/*value 0x32 reserved by ISO 14229*/
#define DCM_E_SECURITYACCESSDENIED                         (Dcm_NegativeResponseCodeType)0x33
#define DCM_E_AUTHENTICATIONREQUIRED                       (Dcm_NegativeResponseCodeType)0x34
#define DCM_E_INVALIDKEY                                   (Dcm_NegativeResponseCodeType)0x35
#define DCM_E_EXCEEDNUMBEROFATTEMPTS                       (Dcm_NegativeResponseCodeType)0x36
#define DCM_E_REQUIREDTIMEDELAYNOTEXPIRED                  (Dcm_NegativeResponseCodeType)0x37
#define DCM_E_SECUREDATATRANSMISSIONREQUIRED               (Dcm_NegativeResponseCodeType)0x38
#define DCM_E_SECUREDATATRANSMISSIONNOTALLOWED             (Dcm_NegativeResponseCodeType)0x39
#define DCM_E_SECUREDATAVERIFICATIONFAILED                 (Dcm_NegativeResponseCodeType)0x3A
/*range of values 0x3B..0x4F reserved by ISO 15764*/
#define DCM_E_CERTIFICATEVERIFICATIONFAILED_INVALIDTIMEPERIOD    (Dcm_NegativeResponseCodeType)0x50
#define DCM_E_CERTIFICATEVERIFICATIONFAILED_INVALIDSIGNATURE     (Dcm_NegativeResponseCodeType)0x51
#define DCM_E_CERTIFICATEVERIFICATIONFAILED_INVALIDCHAINOFTRUST  (Dcm_NegativeResponseCodeType)0x52
#define DCM_E_CERTIFICATEVERIFICATIONFAILED_INVALIDTYPE          (Dcm_NegativeResponseCodeType)0x53
#define DCM_E_CERTIFICATEVERIFICATIONFAILED_INVALIDFORMAT        (Dcm_NegativeResponseCodeType)0x54
#define DCM_E_CERTIFICATEVERIFICATIONFAILED_INVALIDCONTENT       (Dcm_NegativeResponseCodeType)0x55
#define DCM_E_CERTIFICATEVERIFICATIONFAILED_INVALIDSCOPE         (Dcm_NegativeResponseCodeType)0x56
#define DCM_E_CERTIFICATEVERIFICATIONFAILED_INVALIDCERTIFICATE   (Dcm_NegativeResponseCodeType)0x57
#define DCM_E_OWNERSHIPVERFICATIONFAILED                         (Dcm_NegativeResponseCodeType)0x58
#define DCM_E_CHALLENGECALCULATIONFAILED                         (Dcm_NegativeResponseCodeType)0x59
#define DCM_E_SETTINGACCESSRIGHTSFAILED                          (Dcm_NegativeResponseCodeType)0x5A
#define DCM_E_SESSIONKEYCREATION_DERIVATIONFAILED                (Dcm_NegativeResponseCodeType)0x5B
#define DCM_E_CONFIGURATIONDATAUSAGEFAILED                       (Dcm_NegativeResponseCodeType)0x5C
#define DCM_E_DEAUTHENTICATIONFAILED                             (Dcm_NegativeResponseCodeType)0x5D
/*range of values 0x5E..0x6F reserved by ISO 14229*/
#define DCM_E_UPLOADDOWNLOADNOTACCEPTED                    (Dcm_NegativeResponseCodeType)0x70
#define DCM_E_TRANSFERDATASUSPENDED                        (Dcm_NegativeResponseCodeType)0x71
#define DCM_E_GENERALPROGRAMMINGFAILURE                    (Dcm_NegativeResponseCodeType)0x72
#define DCM_E_WRONGBLOCKSEQUENCECOUNTER                    (Dcm_NegativeResponseCodeType)0x73
/*range of values 0x74..0x77 reserved by ISO 14229*/
#define DCM_E_RESPONSEPENDING                              (Dcm_NegativeResponseCodeType)0x78
/*range of values 0x79..0x7D reserved by ISO 14229*/
#define DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION       (Dcm_NegativeResponseCodeType)0x7E
#define DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION           (Dcm_NegativeResponseCodeType)0x7F
/*value 0x80 reserved by ISO 14229*/
#define DCM_E_RPMTOOHIGH                                   (Dcm_NegativeResponseCodeType)0x81
#define DCM_E_RPMTOOLOW                                    (Dcm_NegativeResponseCodeType)0x82
#define DCM_E_ENGINEISRUNNING                              (Dcm_NegativeResponseCodeType)0x83
#define DCM_E_ENGINEISNOTRUNNING                           (Dcm_NegativeResponseCodeType)0x84
#define DCM_E_ENGINERUNTIMETOOLOW                          (Dcm_NegativeResponseCodeType)0x85
#define DCM_E_TEMPERATURETOOHIGH                           (Dcm_NegativeResponseCodeType)0x86
#define DCM_E_TEMPERATURETOOLOW                            (Dcm_NegativeResponseCodeType)0x87
#define DCM_E_VEHICLESPEEDTOOHIGH                          (Dcm_NegativeResponseCodeType)0x88
#define DCM_E_VEHICLESPEEDTOOLOW                           (Dcm_NegativeResponseCodeType)0x89
#define DCM_E_THROTTLE_PEDALTOOHIGH                        (Dcm_NegativeResponseCodeType)0x8A
#define DCM_E_THROTTLE_PEDALTOOLOW                         (Dcm_NegativeResponseCodeType)0x8B
#define DCM_E_TRANSMISSIONRANGENOTINNEUTRAL                (Dcm_NegativeResponseCodeType)0x8C
#define DCM_E_TRANSMISSIONRANGENOTINGEAR                   (Dcm_NegativeResponseCodeType)0x8D
/*value 0x8E reserved by ISO 14229*/
#define DCM_E_BRAKESWITCH_NOTCLOSED                        (Dcm_NegativeResponseCodeType)0x8F
#define DCM_E_SHIFTERLEVERNOTINPARK                        (Dcm_NegativeResponseCodeType)0x90
#define DCM_E_TORQUECONVERTERCLUTCHLOCKED                  (Dcm_NegativeResponseCodeType)0x91
#define DCM_E_VOLTAGETOOHIGH                               (Dcm_NegativeResponseCodeType)0x92
#define DCM_E_VOLTAGETOOLOW                                (Dcm_NegativeResponseCodeType)0x93
/*range of values 0x94..0xEF reserved by ISO 14229*/
#define DCM_E_VMSCNC_0                                     (Dcm_NegativeResponseCodeType)0xF0
#define DCM_E_VMSCNC_1                                     (Dcm_NegativeResponseCodeType)0xF1
#define DCM_E_VMSCNC_2                                     (Dcm_NegativeResponseCodeType)0xF2
#define DCM_E_VMSCNC_3                                     (Dcm_NegativeResponseCodeType)0xF3
#define DCM_E_VMSCNC_4                                     (Dcm_NegativeResponseCodeType)0xF4
#define DCM_E_VMSCNC_5                                     (Dcm_NegativeResponseCodeType)0xF5
#define DCM_E_VMSCNC_6                                     (Dcm_NegativeResponseCodeType)0xF6
#define DCM_E_VMSCNC_7                                     (Dcm_NegativeResponseCodeType)0xF7
#define DCM_E_VMSCNC_8                                     (Dcm_NegativeResponseCodeType)0xF8
#define DCM_E_VMSCNC_9                                     (Dcm_NegativeResponseCodeType)0xF9
#define DCM_E_VMSCNC_A                                     (Dcm_NegativeResponseCodeType)0xFA
#define DCM_E_VMSCNC_B                                     (Dcm_NegativeResponseCodeType)0xFB
#define DCM_E_VMSCNC_C                                     (Dcm_NegativeResponseCodeType)0xFC
#define DCM_E_VMSCNC_D                                     (Dcm_NegativeResponseCodeType)0xFD
#define DCM_E_VMSCNC_E                                     (Dcm_NegativeResponseCodeType)0xFE
/*value 0xFF reserved by ISO 14229*/


/*SWS_Dcm_00983*/
typedef uint8 Dcm_ConfirmationStatusType;
#define DCM_RES_POS_OK                                     (Dcm_ConfirmationStatusType)0x00
#define DCM_RES_POS_NOT_OK                                 (Dcm_ConfirmationStatusType)0x01
#define DCM_RES_NEG_OK                                     (Dcm_ConfirmationStatusType)0x02
#define DCM_RES_NEG_NOT_OK                                 (Dcm_ConfirmationStatusType)0x03


/*SWS_Dcm_00984*/
typedef uint8 Dcm_OpStatusType;
#define DCM_INITIAL                                        (Dcm_OpStatusType)0x00
#define DCM_PENDING                                        (Dcm_OpStatusType)0x01
#define DCM_CANCEL                                         (Dcm_OpStatusType)0x02
#define DCM_FORCE_RCRRP_OK                                 (Dcm_OpStatusType)0x03





/*SWS_Dem_91036*/
typedef uint32 Dem_MonitorDataType;
/*SWS_Dem_00933*/
typedef uint8 Dem_DTCFormatType;
/*selects the 2-byte OBD DTC format (refer to configuration parameter DemObdDTC)*/
#define DEM_DTC_FORMAT_OBD                          ((Dem_DTCFormatType)0)
/*selects the 3-byte UDS DTC format (refer to configuration parameter DemUdsDTC)*/
#define DEM_DTC_FORMAT_UDS                          ((Dem_DTCFormatType)1)
/*selects the merged SPN + FMI to 3-byte J1939 DTC format (refer to DemJ1939DTC)*/
#define DEM_DTC_FORMAT_J1939                        ((Dem_DTCFormatType)2)
/*Selects the 3-byte OBD DTC defined by DemDtcValue3Byte in case that SAE J2012 and UDS DTC format separation is used.*/
#define DEM_DTC_FORMAT_OBD_3BYTE                    ((Dem_DTCFormatType)3)


/*SWS_Dem_91005*/
typedef uint8 Dem_MonitorStatusType;
#define DEM_MONITOR_STATUS_TF                       ((Dem_MonitorStatusType)0x01)                
#define DEM_MONITOR_STATUS_TNCTOC                   ((Dem_MonitorStatusType)0x02)


/*SWS_Dem_00925*/
/*AUTOSAR: 1..65535, 0 is not a valid value.
  Code: 0..65534, 65535 is not a valid value.*/
typedef uint16 Dem_EventIdType;
#define DEM_DTC_ID_INVALID                          ((Dem_EventIdType)0xFFFF)
/*SWS_Dem_00926*/
typedef uint8 Dem_EventStatusType;
#define DEM_EVENT_STATUS_PASSED                     ((Dem_EventStatusType)0x00)
#define DEM_EVENT_STATUS_FAILED                     ((Dem_EventStatusType)0x01)
#define DEM_EVENT_STATUS_PREPASSED                  ((Dem_EventStatusType)0x02)
#define DEM_EVENT_STATUS_PREFAILED                  ((Dem_EventStatusType)0x03)
#define DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED      ((Dem_EventStatusType)0x04)

/*SWS_Dem_01000*/
typedef uint8 Dem_DebouncingStateType;
/*Bit 0: Temporarily Defective(corresponds to 0 <FDC < 127)*/
#define DEM_TEMPORARILY_DEFECTIVE                   ((Dem_DebouncingStateType)0x01)
/*Bit 1: finally Defective(corresponds to FDC =127)*/
#define DEM_FINALLY_DEFECTIVE                       ((Dem_DebouncingStateType)0x02)
/*Bit 2: temporarily healed(corresponds to -128 <FDC < 0)*/
#define DEM_TEMPORARILY_HEALED                      ((Dem_DebouncingStateType)0x04)
/*Bit 3: Test complete (corresponds to FDC = -128 or FDC = 127)*/
#define DEM_TEST_COMPLETE                           ((Dem_DebouncingStateType)0x08)
/*Bit 4: DTR Update (= Test complete && Debouncing complete && enable
conditions/storage conditions fulfilled)*/
#define DEM_DTR_UPDATE                              ((Dem_DebouncingStateType)0x10)

/*SWS_Dem_00927*/
typedef uint8 Dem_DebounceResetStatusType;
#define DEM_DEBOUNCE_STATUS_FREEZE                  ((Dem_DebounceResetStatusType)0x00)
#define DEM_DEBOUNCE_STATUS_RESET                   ((Dem_DebounceResetStatusType)0x01)
/*SWS_Dem_00928*/
typedef uint8 Dem_UdsStatusByteType;
#define DEM_UDS_STATUS_TF                           ((Dem_UdsStatusByteType)0x01)/*bit 0: TestFailed*/
#define DEM_UDS_STATUS_TFTOC                        ((Dem_UdsStatusByteType)0x02)/*bit 1: TestFailedThisOperationCycle*/
#define DEM_UDS_STATUS_PDTC                         ((Dem_UdsStatusByteType)0x04)/*bit 2: PendingDTC*/
#define DEM_UDS_STATUS_CDTC                         ((Dem_UdsStatusByteType)0x08)/*bit 3: ConfirmedDTC*/
#define DEM_UDS_STATUS_TNCSLC                       ((Dem_UdsStatusByteType)0x10)/*bit 4: TestNotCompletedSinceLastClear*/
#define DEM_UDS_STATUS_TFSLC                        ((Dem_UdsStatusByteType)0x20)/*bit 5: TestFailedSinceLastClear*/
#define DEM_UDS_STATUS_TNCTOC                       ((Dem_UdsStatusByteType)0x40)/*bit 6: TestNotCompletedThisOperationCycle*/
#define DEM_UDS_STATUS_WIR                          ((Dem_UdsStatusByteType)0x80)/*bit 7: WarningIndicatorRequested*/

/*SWS_Dem_00929*/
typedef uint8 Dem_OperationCycleStateType;
#define DEM_CYCLE_STATE_START                       ((Dem_OperationCycleStateType)0x01)
#define DEM_CYCLE_STATE_END                         ((Dem_OperationCycleStateType)0x02)
#define DEM_CYCLE_STATE_RESTART                     ((Dem_OperationCycleStateType)0x03)

/*SWS_Dem_00930*/
typedef uint8 Dem_IndicatorStatusType;
#define DEM_INDICATOR_OFF                           ((Dem_IndicatorStatusType)0x00)
#define DEM_INDICATOR_CONTINUOUS                    ((Dem_IndicatorStatusType)0x01)
#define DEM_INDICATOR_BLINKING                      ((Dem_IndicatorStatusType)0x02)
#define DEM_INDICATOR_BLINK_CONT                    ((Dem_IndicatorStatusType)0x03)
#define DEM_INDICATOR_SLOW_FLASH                    ((Dem_IndicatorStatusType)0x04)
#define DEM_INDICATOR_FAST_FLASH                    ((Dem_IndicatorStatusType)0x05)
#define DEM_INDICATOR_ON_DEMAND                     ((Dem_IndicatorStatusType)0x06)
#define DEM_INDICATOR_SHORT                         ((Dem_IndicatorStatusType)0x07)

/*SWS_Dem_00932*/
typedef uint8 Dem_DTCKindType;
#define DEM_DTC_KIND_ALL_DTCS                       ((Dem_DTCKindType)0x01)/*Select all DTCs*/
#define DEM_DTC_KIND_EMISSION_REL_DTCS              ((Dem_DTCKindType)0x02)/*Select OBD-relevant DTCs*/


/*SWS_Dem_00934*/
typedef uint16 Dem_DTCOriginType;
/*Event information located in the primary memory*/
#define DEM_DTC_ORIGIN_PRIMARY_MEMORY               ((Dem_DTCOriginType)0x0001)
/*The Event information is located in the permanent memory*/
#define DEM_DTC_ORIGIN_PERMANENT_MEMORY             ((Dem_DTCOriginType)0x0003)
/*OBD event information located in the primary memory*/
#define DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY          ((Dem_DTCOriginType)0x0004)
/*Event information located in the user defined memory, where XX is the configured
DemUserDefinedMemoryIdentifier in hexadecimal*/
#define DEM_DTC_ORIGIN_USERDEFINED_MEMORY_XX          ((Dem_DTCOriginType)0x0100)

/*SWS_Dem_00942*/
typedef uint8 Dem_InitMonitorReasonType;
/*Event was cleared and all internal values and states are reset.*/
#define DEM_INIT_MONITOR_CLEAR                      ((Dem_InitMonitorReasonType)0x01)
/*Operation cycle of the event was (re-)started.*/
#define DEM_INIT_MONITOR_RESTART                    ((Dem_InitMonitorReasonType)0x02)
/*Enable conditions or DTC settings re-enabled.*/
#define DEM_INIT_MONITOR_REENABLED                  ((Dem_InitMonitorReasonType)0x03)
/*Storage condition reenabled.*/
#define DEM_INIT_MONITOR_STORAGE_REENABLED          ((Dem_InitMonitorReasonType)0x04)

/*SWS_Dem_00943*/
/*This type contains all possible additional IUMPR denominator conditions to
be broadcasted among OBD-relevant ECUs.*/
typedef uint8 Dem_IumprDenomCondIdType;
    /*IUMPR denominator condition "General Denominator"*/
#define DEM_IUMPR_GENERAL_DENOMINATOR                ((Dem_IumprDenomCondIdType)0x00)
    /*Additional IUMPR denominator condition "Cold Start"*/
#define DEM_IUMPR_DEN_COND_COLDSTART                 ((Dem_IumprDenomCondIdType)0x02)
    /*Additional IUMPR denominator condition "EVAP"*/
#define DEM_IUMPR_DEN_COND_EVAP                      ((Dem_IumprDenomCondIdType)0x03)
    /*Additional IUMPR denominator condition "500 miles"*/
#define DEM_IUMPR_DEN_COND_500MI                     ((Dem_IumprDenomCondIdType)0x04)
#define DEM_IUMPR_GENERAL_INDIVIDUAL_DENOMINATOR     ((Dem_IumprDenomCondIdType)0x05)
#define DEM_IUMPR_GENERAL_OBDCOND                    ((Dem_IumprDenomCondIdType)0x06)


/*SWS_Dem_00940*/
/*OBD specific ratio Id.Configurable, size depends on system complexity (refer to range of configuration parameter DemRatioId)*/
typedef uint16 Dem_RatioIdType;/*uint8, uint16*/

/*SWS_Dem_00941*/
typedef uint8 Dem_DTRControlType;
/*Values are reported and regarded as valid test result*/
#define DEM_DTR_CTL_NORMAL                          ((Dem_DTRControlType)0x00)
/*Values are reported,but maximum limit is not available (not valid); upper limit value is ignored.*/
#define DEM_DTR_CTL_NO_MAX                          ((Dem_DTRControlType)0x01)
/*Values are reported,but minimum limit is not available (not valid); lower limit value is ignored.*/
#define DEM_DTR_CTL_NO_MIN                          ((Dem_DTRControlType)0x02)
/*Values are all ignored.External representation will be all zeros as initialized (e.g. after fault clear)*/
#define DEM_DTR_CTL_RESET                           ((Dem_DTRControlType)0x03)
/*Values are all ignored.This DTR is treated for the external view (tester) as if not integrated.*/
#define DEM_DTR_CTL_INVISIBLE                       ((Dem_DTRControlType)0x04)



typedef uint8 EcuM_BootTargetType;      /*SWS_EcuM_04042*/
#define ECUM_BOOT_TARGET_APP                                ((EcuM_BootTargetType)0)
#define ECUM_BOOT_TARGET_OEM_BOOTLOADER                     ((EcuM_BootTargetType)1)
#define ECUM_BOOT_TARGET_SYS_BOOTLOADER                     ((EcuM_BootTargetType)2)
#define ECUM_BOOT_TARGET_MAX_NUMBER                         ((EcuM_BootTargetType)3)



/*SWS_EcuM_04136*/
typedef uint8 EcuM_ShutdownTargetType;
#define ECUM_SHUTDOWN_TARGET_SLEEP                          ((EcuM_ShutdownTargetType)0x0)
#define ECUM_SHUTDOWN_TARGET_RESET                          ((EcuM_ShutdownTargetType)0x1)
#define ECUM_SHUTDOWN_TARGET_OFF                            ((EcuM_ShutdownTargetType)0x2)

/*SWS_EcuM_04045*/
typedef uint8 EcuM_ShutdownCauseType;
#define ECUM_CAUSE_UNKNOWN                                  ((EcuM_ShutdownCauseType)0)
#define ECUM_CAUSE_ECU_STATE                                ((EcuM_ShutdownCauseType)1)
#define ECUM_CAUSE_WDGM                                     ((EcuM_ShutdownCauseType)2)
#define ECUM_CAUSE_DCM                                      ((EcuM_ShutdownCauseType)3)
/*SWS_NvM_00470*/
typedef uint8 NvM_RequestResultType;
#define NVM_REQ_OK                                          ((NvM_RequestResultType)0x00)
#define NVM_REQ_NOT_OK                                      ((NvM_RequestResultType)0x01)
#define NVM_REQ_PENDING                                     ((NvM_RequestResultType)0x02)
#define NVM_REQ_INTEGRITY_FAILED                            ((NvM_RequestResultType)0x03)
#define NVM_REQ_BLOCK_SKIPPED                               ((NvM_RequestResultType)0x04)
#define NVM_REQ_NV_INVALIDATED                              ((NvM_RequestResultType)0x05)
#define NVM_REQ_CANCELED                                    ((NvM_RequestResultType)0x06)
#define NVM_REQ_RESTORED_DEFAULTS                           ((NvM_RequestResultType)0x08)


/*SWS_NvM_91123*/
typedef uint8 NvM_InitBlockRequestType;
#define NVM_INIT_READ_BLOCK                                 ((NvM_InitBlockRequestType)0x00)
#define NVM_INIT_RESTORE_BLOCK_DEFAULTS                     ((NvM_InitBlockRequestType)0x01)
#define NVM_INIT_READ_ALL_BLOCK                             ((NvM_InitBlockRequestType)0x02)
#define NVM_INIT_FIRST_INIT_ALL                             ((NvM_InitBlockRequestType)0x03)


/*SWS_NvM_91002*/
typedef uint8 NvM_BlockRequestType;
#define NVM_READ_BLOCK                                      ((NvM_BlockRequestType)0x00)
#define NVM_WRITE_BLOCK                                     ((NvM_BlockRequestType)0x01)
#define NVM_RESTORE_BLOCK_DEFAULTS                          ((NvM_BlockRequestType)0x02)
#define NVM_ERASE_NV_BLOCK                                  ((NvM_BlockRequestType)0x03)
#define NVM_INVALIDATE_NV_BLOCK                             ((NvM_BlockRequestType)0x04)
#define NVM_READ_ALL_BLOCK                                  ((NvM_BlockRequestType)0x05)
#define NVM_WRITE_ALL_BLOCK                                 ((NvM_BlockRequestType)0x06)


/*******************************************************************************
*   Implementing Data Type Definition.
*******************************************************************************/
typedef uint16 BattVolt_LBMR_IDT;
typedef const void* ConstVoidPtr;
typedef uint8 Day_IDT;
typedef uint8 Dcm_DataElement_DspData_0xF010_0_ArrayType[4];
typedef Dcm_DataElement_DspData_0xF010_0_ArrayType Dcm_DataElement_DspData_0xF010_0Type;
typedef uint8 Dcm_DataElement_DspData_0xF110_0_ArrayType[11];
typedef Dcm_DataElement_DspData_0xF110_0_ArrayType Dcm_DataElement_DspData_0xF110_0Type;
typedef uint8 Dcm_DataElement_DspData_0xF111_0_ArrayType[2];
typedef Dcm_DataElement_DspData_0xF111_0_ArrayType Dcm_DataElement_DspData_0xF111_0Type;
typedef uint8 Dcm_DataElement_DspData_0xF118_0_ArrayType[11];
typedef Dcm_DataElement_DspData_0xF118_0_ArrayType Dcm_DataElement_DspData_0xF118_0Type;
typedef uint8 Dcm_DataElement_DspData_0xF119_0_ArrayType[2];
typedef Dcm_DataElement_DspData_0xF119_0_ArrayType Dcm_DataElement_DspData_0xF119_0Type;
typedef uint8 Dcm_DataElement_DspData_0xF150_0_ArrayType[3];
typedef Dcm_DataElement_DspData_0xF150_0_ArrayType Dcm_DataElement_DspData_0xF150_0Type;
typedef uint8 Dcm_DataElement_DspData_0xF15B_0_ArrayType[12];
typedef Dcm_DataElement_DspData_0xF15B_0_ArrayType Dcm_DataElement_DspData_0xF15B_0Type;
typedef uint8 Dcm_DataElement_DspData_0xF186_0_PrimitiveType;
typedef Dcm_DataElement_DspData_0xF186_0_PrimitiveType Dcm_DataElement_DspData_0xF186_0Type;
typedef uint8 Dcm_DataElement_DspData_0xF18A_0_ArrayType[8];
typedef Dcm_DataElement_DspData_0xF18A_0_ArrayType Dcm_DataElement_DspData_0xF18A_0Type;
typedef uint8 Dcm_DataElement_DspData_0xF18B_0_ArrayType[3];
typedef Dcm_DataElement_DspData_0xF18B_0_ArrayType Dcm_DataElement_DspData_0xF18B_0Type;
typedef uint8 Dcm_DataElement_DspData_0xF18C_0_ArrayType[16];
typedef Dcm_DataElement_DspData_0xF18C_0_ArrayType Dcm_DataElement_DspData_0xF18C_0Type;
typedef uint8 Dcm_DataElement_DspData_0xF193_0_ArrayType[3];
typedef Dcm_DataElement_DspData_0xF193_0_ArrayType Dcm_DataElement_DspData_0xF193_0Type;
typedef uint8 Dcm_DataElement_DspData_0xF195_0_ArrayType[3];
typedef Dcm_DataElement_DspData_0xF195_0_ArrayType Dcm_DataElement_DspData_0xF195_0Type;
typedef uint8 Dcm_DataElement_DspData_0xF19E_0_ArrayType[3];
typedef Dcm_DataElement_DspData_0xF19E_0_ArrayType Dcm_DataElement_DspData_0xF19E_0Type;
typedef uint8 Dcm_DataElement_DspData_0xFD01_0_ArrayType[3];
typedef Dcm_DataElement_DspData_0xFD01_0_ArrayType Dcm_DataElement_DspData_0xFD01_0Type;
typedef uint8 Dcm_DataElement_DspData_0xFD02_0_ArrayType[3];
typedef Dcm_DataElement_DspData_0xFD02_0_ArrayType Dcm_DataElement_DspData_0xFD02_0Type;
typedef uint8 Dcm_DidSupportedType;
typedef uint8 Dcm_KeyArray_L2Type[4];
typedef uint8 Dcm_SeedArray_L2Type[4];
typedef uint8 Dcm_StartDataOut_DspRoutine0x0203_DspRoutine0x0203_StartOutSignalPrimitiveType;
typedef Dcm_StartDataOut_DspRoutine0x0203_DspRoutine0x0203_StartOutSignalPrimitiveType Dcm_StartDataOut_DspRoutine0x0203_DspRoutine0x0203_StartOutSignalType;
typedef uint8 Dem_DataArrayType_DataElement7_Odometer[3];
typedef uint8 Dem_DataArrayType_DataElement9_VehicleSpeed[2];
typedef uint8 Dem_DataPrimitiveType_DataElement1_Year;
typedef uint8 Dem_DataPrimitiveType_DataElement2_Month;
typedef uint8 Dem_DataPrimitiveType_DataElement3_Day;
typedef uint8 Dem_DataPrimitiveType_DataElement4_Hour;
typedef uint8 Dem_DataPrimitiveType_DataElement5_Minute;
typedef uint8 Dem_DataPrimitiveType_DataElement6_Second;
typedef uint8 Dem_DataPrimitiveType_DataElement8_LV_Battery_Voltage;
typedef Dem_DataPrimitiveType_DataElement1_Year Dem_DataType_DataElement1_Year;
typedef Dem_DataPrimitiveType_DataElement2_Month Dem_DataType_DataElement2_Month;
typedef Dem_DataPrimitiveType_DataElement3_Day Dem_DataType_DataElement3_Day;
typedef Dem_DataPrimitiveType_DataElement4_Hour Dem_DataType_DataElement4_Hour;
typedef Dem_DataPrimitiveType_DataElement5_Minute Dem_DataType_DataElement5_Minute;
typedef Dem_DataPrimitiveType_DataElement6_Second Dem_DataType_DataElement6_Second;
typedef Dem_DataArrayType_DataElement7_Odometer Dem_DataType_DataElement7_Odometer;
typedef Dem_DataPrimitiveType_DataElement8_LV_Battery_Voltage Dem_DataType_DataElement8_LV_Battery_Voltage;
typedef Dem_DataArrayType_DataElement9_VehicleSpeed Dem_DataType_DataElement9_VehicleSpeed;
typedef uint8 Dem_MaxDataValueType[1];
typedef uint8 Dem_PID31valueType[2];
typedef uint8 DrvHeat1Sts_IDT;
typedef uint8 DrvHeat1_pct_IDT;
typedef uint8 DrvHeat2Sts_IDT;
typedef uint8 DrvHeat2_pct_IDT;
typedef uint8 DrvHeat3Sts_IDT;
typedef uint8 DrvHeat3_pct_IDT;
typedef uint8 DrvHeat4Sts_IDT;
typedef uint8 DrvHeat4_pct_IDT;
typedef uint8 DrvHeat5ErrSts_IDT;
typedef uint8 DrvHeat5Sts_IDT;
typedef uint8 DrvHeat5_pct_IDT;
typedef uint8 DrvHeat6Sts_IDT;
typedef uint8 DrvHeat6_pct_IDT;
typedef uint8 DrvKneadingMassgLvlCmd10_IDT;
typedef uint8 DrvKneadingMassgLvlCmd5_IDT;
typedef uint8 DrvKneadingMassgLvlCmd6_IDT;
typedef uint8 DrvKneadingMassgLvlCmd7_IDT;
typedef uint8 DrvKneadingMassgLvlCmd8_IDT;
typedef uint8 DrvKneadingMassgLvlCmd9_IDT;
typedef uint8 DrvKneadingMassgSkillsCmd10_IDT;
typedef uint8 DrvKneadingMassgSkillsCmd5_IDT;
typedef uint8 DrvKneadingMassgSkillsCmd6_IDT;
typedef uint8 DrvKneadingMassgSkillsCmd7_IDT;
typedef uint8 DrvKneadingMassgSkillsCmd8_IDT;
typedef uint8 DrvKneadingMassgSkillsCmd9_IDT;
typedef uint8 DrvKneadingMassgSkillsSts10_IDT;
typedef uint8 DrvKneadingMassgSkillsSts5_IDT;
typedef uint8 DrvKneadingMassgSkillsSts6_IDT;
typedef uint8 DrvKneadingMassgSkillsSts7_IDT;
typedef uint8 DrvKneadingMassgSkillsSts8_IDT;
typedef uint8 DrvKneadingMassgSkillsSts9_IDT;
typedef uint8 DrvKneadingMassgTime10_IDT;
typedef uint8 DrvKneadingMassgTime5_IDT;
typedef uint8 DrvKneadingMassgTime6_IDT;
typedef uint8 DrvKneadingMassgTime7_IDT;
typedef uint8 DrvKneadingMassgTime8_IDT;
typedef uint8 DrvKneadingMassgTime9_IDT;
typedef uint8 DrvKneadingMassgTimesCmd10_IDT;
typedef uint8 DrvKneadingMassgTimesCmd5_IDT;
typedef uint8 DrvKneadingMassgTimesCmd6_IDT;
typedef uint8 DrvKneadingMassgTimesCmd7_IDT;
typedef uint8 DrvKneadingMassgTimesCmd8_IDT;
typedef uint8 DrvKneadingMassgTimesCmd9_IDT;
typedef uint8 DrvKneadingMassglvlSts10_IDT;
typedef uint8 DrvKneadingMassglvlSts5_IDT;
typedef uint8 DrvKneadingMassglvlSts6_IDT;
typedef uint8 DrvKneadingMassglvlSts7_IDT;
typedef uint8 DrvKneadingMassglvlSts8_IDT;
typedef uint8 DrvKneadingMassglvlSts9_IDT;
typedef uint8 DrvLumControlSts_IDT;
typedef uint8 DrvLumSwitchSts_IDT;
typedef uint8 DrvLumbarBottomWorkSts_IDT;
typedef uint8 DrvLumbarMidWorkSts_IDT;
typedef uint8 DrvLumbarTopWorkSts_IDT;
typedef uint8 DrvMassSwitchSts_IDT;
typedef uint8 DrvMassageHeatNTC10_IDT;
typedef uint8 DrvMassageHeatNTC11_IDT;
typedef uint8 DrvMassageHeatNTC12_IDT;
typedef uint8 DrvMassageHeatNTC1_IDT;
typedef uint8 DrvMassageHeatNTC2_IDT;
typedef uint8 DrvMassageHeatNTC3_IDT;
typedef uint8 DrvMassageHeatNTC4_IDT;
typedef uint8 DrvMassageHeatNTC5_IDT;
typedef uint8 DrvMassageHeatNTC6_IDT;
typedef uint8 DrvMassageHeatNTC7_IDT;
typedef uint8 DrvMassageHeatNTC8_IDT;
typedef uint8 DrvMassageHeatNTC9_IDT;
typedef uint8 DrvPumpCmd_IDT;
typedef uint8 DrvPumpSts_IDT;
typedef uint8 DrvSeatBlosterValueSts_IDT;
typedef uint8 DrvSeatBolsterValueBLCmd_IDT;
typedef uint8 DrvSeatBolsterValueBLPos_IDT;
typedef uint8 DrvSeatBolsterValueBRCmd_IDT;
typedef uint8 DrvSeatBolsterValueBRPos_IDT;
typedef uint8 DrvSeatCushionValue1Cmd_IDT;
typedef uint8 DrvSeatCushionValue1Pos_IDT;
typedef uint8 DrvSeatCushionValue2Cmd_IDT;
typedef uint8 DrvSeatCushionValue2Pos_IDT;
typedef uint8 DrvSeatCushionValue3Cmd_IDT;
typedef uint8 DrvSeatCushionValue3Pos_IDT;
typedef uint8 DrvSeatCushionValue4Cmd_IDT;
typedef uint8 DrvSeatCushionValue4Pos_IDT;
typedef uint8 DrvSeatCushionValue5Cmd_IDT;
typedef uint8 DrvSeatCushionValue5Pos_IDT;
typedef uint8 DrvSeatCushionValue6Cmd_IDT;
typedef uint8 DrvSeatCushionValue6Pos_IDT;
typedef uint8 DrvSeatCushionValueSts_IDT;
typedef uint8 DrvSeatLumbarBottomPos_IDT;
typedef uint8 DrvSeatLumbarBottomValue3Cmd_IDT;
typedef uint8 DrvSeatLumbarMidPos_IDT;
typedef uint8 DrvSeatLumbarMidValue2Cmd_IDT;
typedef uint8 DrvSeatLumbarTopPos_IDT;
typedef uint8 DrvSeatLumbarTopValue1Cmd_IDT;
typedef uint8 DrvSeatLumbarValueSts_IDT;
typedef uint8 DrvSeatMassFailr_IDT;
typedef uint8 DrvSeatUpperValueLCmd_IDT;
typedef uint8 DrvSeatUpperValueLPos_IDT;
typedef uint8 DrvSeatUpperValueMCmd_IDT;
typedef uint8 DrvSeatUpperValueMPos_IDT;
typedef uint8 DrvSeatUpperValueRCmd_IDT;
typedef uint8 DrvSeatUpperValueRPos_IDT;
typedef uint8 DrvSeatUpperValueSts_IDT;
typedef uint8 DrvSeatmassgHeat10Cmd_IDT;
typedef uint8 DrvSeatmassgHeat11Cmd_IDT;
typedef uint8 DrvSeatmassgHeat12Cmd_IDT;
typedef uint8 DrvSeatmassgHeat1Cmd_IDT;
typedef uint8 DrvSeatmassgHeat2Cmd_IDT;
typedef uint8 DrvSeatmassgHeat3Cmd_IDT;
typedef uint8 DrvSeatmassgHeat4Cmd_IDT;
typedef uint8 DrvSeatmassgHeat5Cmd_IDT;
typedef uint8 DrvSeatmassgHeat6Cmd_IDT;
typedef uint8 DrvSeatmassgHeat7Cmd_IDT;
typedef uint8 DrvSeatmassgHeat8Cmd_IDT;
typedef uint8 DrvSeatmassgHeat9Cmd_IDT;
typedef uint8 DrvSeatmassgHeatCSts_IDT;
typedef uint8 DrvSeatmassgValve10Cmd_IDT;
typedef uint8 DrvSeatmassgValve11Cmd_IDT;
typedef uint8 DrvSeatmassgValve12Cmd_IDT;
typedef uint8 DrvSeatmassgValve1Cmd_IDT;
typedef uint8 DrvSeatmassgValve2Cmd_IDT;
typedef uint8 DrvSeatmassgValve3Cmd_IDT;
typedef uint8 DrvSeatmassgValve4Cmd_IDT;
typedef uint8 DrvSeatmassgValve5Cmd_IDT;
typedef uint8 DrvSeatmassgValve6Cmd_IDT;
typedef uint8 DrvSeatmassgValve7Cmd_IDT;
typedef uint8 DrvSeatmassgValve8Cmd_IDT;
typedef uint8 DrvSeatmassgValve9Cmd_IDT;
typedef uint8 DrvSeatmassgValveSts_IDT;
typedef uint8 DrvState_IDT;
typedef uint8 DrvState_SrvSts_IDT;
typedef uint8 DrvSystemFailr_IDT;
typedef uint8 EcuM_UserType;
typedef uint8 Hr_IDT;
typedef uint16 MSec_IDT;
typedef uint8 Min_IDT;
typedef uint8 Mth_IDT;
typedef uint16 NvM_BlockIdType;
typedef uint8 OperatorState_IDT;
typedef uint8 OperatorState_SrvSts_IDT;
typedef uint8 PNC10_Sts_IDT;
typedef uint8 PNC11_Sts_IDT;
typedef uint8 PNC12_Sts_IDT;
typedef uint8 PNC13_Sts_IDT;
typedef uint8 PNC14_Sts_IDT;
typedef uint8 PNC15_Sts_IDT;
typedef uint8 PNC16_Sts_IDT;
typedef uint8 PNC17_Sts_IDT;
typedef uint8 PNC18_Sts_IDT;
typedef uint8 PNC19_Sts_IDT;
typedef uint8 PNC1_Sts_IDT;
typedef uint8 PNC20_Sts_IDT;
typedef uint8 PNC21_Sts_IDT;
typedef uint8 PNC22_Sts_IDT;
typedef uint8 PNC23_Sts_IDT;
typedef uint8 PNC24_Sts_IDT;
typedef uint8 PNC25_Sts_IDT;
typedef uint8 PNC26_Sts_IDT;
typedef uint8 PNC27_Sts_IDT;
typedef uint8 PNC28_Sts_IDT;
typedef uint8 PNC29_Sts_IDT;
typedef uint8 PNC2_Sts_IDT;
typedef uint8 PNC30_Sts_IDT;
typedef uint8 PNC31_Sts_IDT;
typedef uint8 PNC32_Sts_IDT;
typedef uint8 PNC33_Sts_IDT;
typedef uint8 PNC34_Sts_IDT;
typedef uint8 PNC35_Sts_IDT;
typedef uint8 PNC36_Sts_IDT;
typedef uint8 PNC37_Sts_IDT;
typedef uint8 PNC38_Sts_IDT;
typedef uint8 PNC39_Sts_IDT;
typedef uint8 PNC3_Sts_IDT;
typedef uint8 PNC40_Sts_IDT;
typedef uint8 PNC41_Sts_IDT;
typedef uint8 PNC42_Sts_IDT;
typedef uint8 PNC43_Sts_IDT;
typedef uint8 PNC44_Sts_IDT;
typedef uint8 PNC45_Sts_IDT;
typedef uint8 PNC46_Sts_IDT;
typedef uint8 PNC47_Sts_IDT;
typedef uint8 PNC48_Sts_IDT;
typedef uint8 PNC4_Sts_IDT;
typedef uint8 PNC5_Sts_IDT;
typedef uint8 PNC6_Sts_IDT;
typedef uint8 PNC7_Sts_IDT;
typedef uint8 PNC8_Sts_IDT;
typedef uint8 PNC9_Sts_IDT;
typedef uint8 PNC_DFT_IDT;
typedef uint8 PassHeat1Sts_IDT;
typedef uint8 PassHeat1_pct_IDT;
typedef uint8 PassHeat2Sts_IDT;
typedef uint8 PassHeat2_pct_IDT;
typedef uint8 PassHeat3Sts_IDT;
typedef uint8 PassHeat3_pct_IDT;
typedef uint8 PassHeat4Sts_IDT;
typedef uint8 PassHeat4_pct_IDT;
typedef uint8 PassHeat5ErrSts_IDT;
typedef uint8 PassHeat5Sts_IDT;
typedef uint8 PassHeat5_pct_IDT;
typedef uint8 PassHeat6Sts_IDT;
typedef uint8 PassHeat6_pct_IDT;
typedef uint8 PassKneadingMassgLvlCmd10_IDT;
typedef uint8 PassKneadingMassgLvlCmd5_IDT;
typedef uint8 PassKneadingMassgLvlCmd6_IDT;
typedef uint8 PassKneadingMassgLvlCmd7_IDT;
typedef uint8 PassKneadingMassgLvlCmd8_IDT;
typedef uint8 PassKneadingMassgLvlCmd9_IDT;
typedef uint8 PassKneadingMassgLvlSts10_IDT;
typedef uint8 PassKneadingMassgLvlSts5_IDT;
typedef uint8 PassKneadingMassgLvlSts6_IDT;
typedef uint8 PassKneadingMassgLvlSts7_IDT;
typedef uint8 PassKneadingMassgLvlSts8_IDT;
typedef uint8 PassKneadingMassgLvlSts9_IDT;
typedef uint8 PassKneadingMassgSkillsCmd10_IDT;
typedef uint8 PassKneadingMassgSkillsCmd5_IDT;
typedef uint8 PassKneadingMassgSkillsCmd6_IDT;
typedef uint8 PassKneadingMassgSkillsCmd7_IDT;
typedef uint8 PassKneadingMassgSkillsCmd8_IDT;
typedef uint8 PassKneadingMassgSkillsCmd9_IDT;
typedef uint8 PassKneadingMassgSkillsSts10_IDT;
typedef uint8 PassKneadingMassgSkillsSts5_IDT;
typedef uint8 PassKneadingMassgSkillsSts6_IDT;
typedef uint8 PassKneadingMassgSkillsSts7_IDT;
typedef uint8 PassKneadingMassgSkillsSts8_IDT;
typedef uint8 PassKneadingMassgSkillsSts9_IDT;
typedef uint8 PassKneadingMassgTime10_IDT;
typedef uint8 PassKneadingMassgTime5_IDT;
typedef uint8 PassKneadingMassgTime6_IDT;
typedef uint8 PassKneadingMassgTime7_IDT;
typedef uint8 PassKneadingMassgTime8_IDT;
typedef uint8 PassKneadingMassgTime9_IDT;
typedef uint8 PassKneadingMassgTimesCmd10_IDT;
typedef uint8 PassKneadingMassgTimesCmd5_IDT;
typedef uint8 PassKneadingMassgTimesCmd6_IDT;
typedef uint8 PassKneadingMassgTimesCmd7_IDT;
typedef uint8 PassKneadingMassgTimesCmd8_IDT;
typedef uint8 PassKneadingMassgTimesCmd9_IDT;
typedef uint8 PassLumControlSts_IDT;
typedef uint8 PassLumSwitchSts_IDT;
typedef uint8 PassLumbarBottomWorkSts_IDT;
typedef uint8 PassLumbarMidWorkSts_IDT;
typedef uint8 PassLumbarTopWorkSts_IDT;
typedef uint8 PassMassSwitchSts_IDT;
typedef uint8 PassMassageHeatNTC10_IDT;
typedef uint8 PassMassageHeatNTC11_IDT;
typedef uint8 PassMassageHeatNTC12_IDT;
typedef uint8 PassMassageHeatNTC1_IDT;
typedef uint8 PassMassageHeatNTC2_IDT;
typedef uint8 PassMassageHeatNTC3_IDT;
typedef uint8 PassMassageHeatNTC4_IDT;
typedef uint8 PassMassageHeatNTC5_IDT;
typedef uint8 PassMassageHeatNTC6_IDT;
typedef uint8 PassMassageHeatNTC7_IDT;
typedef uint8 PassMassageHeatNTC8_IDT;
typedef uint8 PassMassageHeatNTC9_IDT;
typedef uint8 PassPumpCmd_IDT;
typedef uint8 PassPumpSts_IDT;
typedef uint8 PassSeatBlosterValueSts_IDT;
typedef uint8 PassSeatBolsterValueBLCmd_IDT;
typedef uint8 PassSeatBolsterValueBLPos_IDT;
typedef uint8 PassSeatBolsterValueBRCmd_IDT;
typedef uint8 PassSeatBolsterValueBRPos_IDT;
typedef uint8 PassSeatCushionValue1Cmd_IDT;
typedef uint8 PassSeatCushionValue1Pos_IDT;
typedef uint8 PassSeatCushionValue2Cmd_IDT;
typedef uint8 PassSeatCushionValue2Pos_IDT;
typedef uint8 PassSeatCushionValue3Cmd_IDT;
typedef uint8 PassSeatCushionValue3Pos_IDT;
typedef uint8 PassSeatCushionValue4Cmd_IDT;
typedef uint8 PassSeatCushionValue4Pos_IDT;
typedef uint8 PassSeatCushionValue5Cmd_IDT;
typedef uint8 PassSeatCushionValue5Pos_IDT;
typedef uint8 PassSeatCushionValue6Cmd_IDT;
typedef uint8 PassSeatCushionValue6Pos_IDT;
typedef uint8 PassSeatCushionValueSts_IDT;
typedef uint8 PassSeatLumbarBottomPos_IDT;
typedef uint8 PassSeatLumbarBottomValue3Cmd_IDT;
typedef uint8 PassSeatLumbarMidPos_IDT;
typedef uint8 PassSeatLumbarMidValue2Cmd_IDT;
typedef uint8 PassSeatLumbarTopPos_IDT;
typedef uint8 PassSeatLumbarTopValue1Cmd_IDT;
typedef uint8 PassSeatLumbarValueSts_IDT;
typedef uint8 PassSeatMassFailr_IDT;
typedef uint8 PassSeatUpperValueLCmd_IDT;
typedef uint8 PassSeatUpperValueLPos_IDT;
typedef uint8 PassSeatUpperValueMCmd_IDT;
typedef uint8 PassSeatUpperValueMPos_IDT;
typedef uint8 PassSeatUpperValueRCmd_IDT;
typedef uint8 PassSeatUpperValueRPos_IDT;
typedef uint8 PassSeatUpperValueSts_IDT;
typedef uint8 PassSeatmassgHeat10Cmd_IDT;
typedef uint8 PassSeatmassgHeat11Cmd_IDT;
typedef uint8 PassSeatmassgHeat12Cmd_IDT;
typedef uint8 PassSeatmassgHeat1Cmd_IDT;
typedef uint8 PassSeatmassgHeat2Cmd_IDT;
typedef uint8 PassSeatmassgHeat3Cmd_IDT;
typedef uint8 PassSeatmassgHeat4Cmd_IDT;
typedef uint8 PassSeatmassgHeat5Cmd_IDT;
typedef uint8 PassSeatmassgHeat6Cmd_IDT;
typedef uint8 PassSeatmassgHeat7Cmd_IDT;
typedef uint8 PassSeatmassgHeat8Cmd_IDT;
typedef uint8 PassSeatmassgHeat9Cmd_IDT;
typedef uint8 PassSeatmassgHeatCSts_IDT;
typedef uint8 PassSeatmassgValve10Cmd_IDT;
typedef uint8 PassSeatmassgValve11Cmd_IDT;
typedef uint8 PassSeatmassgValve12Cmd_IDT;
typedef uint8 PassSeatmassgValve1Cmd_IDT;
typedef uint8 PassSeatmassgValve2Cmd_IDT;
typedef uint8 PassSeatmassgValve3Cmd_IDT;
typedef uint8 PassSeatmassgValve4Cmd_IDT;
typedef uint8 PassSeatmassgValve5Cmd_IDT;
typedef uint8 PassSeatmassgValve6Cmd_IDT;
typedef uint8 PassSeatmassgValve7Cmd_IDT;
typedef uint8 PassSeatmassgValve8Cmd_IDT;
typedef uint8 PassSeatmassgValve9Cmd_IDT;
typedef uint8 PassSeatmassgValveSts_IDT;
typedef uint8 PassSystemFailr_IDT;
typedef uint8 Sec_IDT;
typedef uint8 VC_Data_5E0_CRC_IDT;
typedef uint8 VC_Data_5E0_MsgCntr_IDT;
typedef uint64 VC_Data_5E0_Payload_IDT;
typedef uint8 VehModeDef_IDT;
typedef uint32 VehOdometer_IDT;
typedef uint8 VehSpdSts_Rdnt1_IDT;
typedef uint16 VehSpd_Rdnt1_IDT;
typedef uint8 VehStateDetailed_IDT;
typedef uint8 VehStateDetailed_SrvSts_IDT;
typedef void* VoidPtr;
typedef uint8 Yr_IDT;
typedef uint8 ZONE_13C_CRC_IDT;
typedef uint8 ZONE_13C_MsgCntr_IDT;

/*******************************************************************************
* Port Api Option
*******************************************************************************/

/*****************************************************************************
* Swc structure
******************************************************************************/
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_AppSWC_BswM;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_AppSWC_ComM;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_AppSWC_Dcm;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_AppSWC_Dem;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_AppSWC_Det;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_AppSWC_EcuM;
typedef struct {
    uint8 Rte_Dummy;
} Rte_CDS_AppSWC_NvM;
/*****************************************************************************
* WaitingTaskList Type Definition.
******************************************************************************/
typedef struct
{
    uint8 TaskId;
    uint32 EventMask;
}Rte_WaitingTaskListType;


/*******************************************************************************
*   type define of Server
*******************************************************************************/
typedef struct {
    uint16 clientId;
    uint16 sequenceCounter;
} Rte_Cs_TransactionHandleType;
typedef struct {
    uint8 ClientLoc;
    uint8 ServerLoc;
    uint8 counter;
    uint8 vacant;
} Rte_ServerBufferInfoType_vacant;

typedef struct {
    uint8 ClientLoc;
    uint8 ServerLoc;
    uint8 counter;
} Rte_ServerBufferInfoType;



#endif


