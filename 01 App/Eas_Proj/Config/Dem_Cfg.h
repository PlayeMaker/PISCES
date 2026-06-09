/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Dem_Cfg.h
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
#ifndef DEM_CFG_H
#define DEM_CFG_H


/*******************************************************************************
*   Dem Container:DemGeneral
*******************************************************************************/
#define DEM_CONFIG_VARIANTS                                 STD_CONFIG_VARIANTS_POSTBUILD

#define DEM_PRIVATE_VERSION_CHECK                           STD_ON
/* generate tool's version*/
#define DEM_SW_MAJOR_VERSION_CFG                            4
#define DEM_SW_MINOR_VERSION_CFG                            2
#define DEM_SW_PATCH_VERSION_CFG                            0
#define DEM_AR_RELEASE_MAJOR_VERSION_CFG                    4
#define DEM_AR_RELEASE_MINOR_VERSION_CFG                    7
#define DEM_AR_RELEASE_REVISION_VERSION_CFG                 0

#define DEM_CMA_PLATFORM_ENABLED                            STD_OFF

#define DEM_NVM_SUPPORT                                     STD_ON
#define DEM_FIM_SUPPORT                                     STD_OFF
/*DemAgingRequiresTestedCycle*/
#define DEM_CFG_AGINGREQUIRESTESTEDCYCLE                    STD_ON
/*DemAvailabilitySupport*/
#define DEM_CFG_AVAILABILITYSUPPORT                         DEM_NO_AVAILABILITY
/*DemBswErrorBufferSize*/
#define DEM_CFG_BSWERRORBUFFERSIZE                          (8)
/*DemClearDTCBehavior*/
#define DEM_CFG_CLEARDTCBEHAIOR                             DEM_CLRRESP_VOLATILE
/*DemClearDTCLimitation*/
#define DEM_CFG_CLEARDTCLIMITATION                          DEM_ALL_SUPPORTED_DTCS
/*DemDataElementDefaultEndianness*/
#define DEM_CFG_DATAELEMENTDEFAULTENDIANNESS                DEM_OPAQUE
/*DemDebounceCounterBasedSupport*/ /*SWS_Dem_00526*/
#define DEM_CFG_DEBOUNCECOUNTERBASEDSUPPORT                 STD_ON
/*DemDebounceTimeBasedSupport*//*SWS_Dem_00527*/
#define DEM_CFG_DEBOUNCETIMEBASEDSUPPORT                    STD_ON
/*DemDevErrorDetect*/
#define DEM_DEV_ERROR_DETECT                                STD_OFF
/*DemEventCombinationSupport*/
#define DEM_EVENT_COMBINATION_SUPPORT                       DEM_EVCOMB_DISABLED
/*DemGeneralCallbackMonitorStatusChangedFnc*/
#define DEM_CFG_GENERAL_CBMONITOR_STATUS_CHANGE_FNC         NULL_PTR
/*DemGeneralInterfaceSupport*/
#define DEM_CFG_GENERALINTERFACESUPPORT                     STD_OFF
/*DemMaxNumberPrestoredFF*/
#define DEM_CFG_MAXNUMBER_PRESTOREDFF                       0
/*DemOBDSupport*/
#define DEM_CFG_OBD_SUPPORT                                 DEM_OBD_NO_OBD_SUPPORT
/*DemJ1939Support*/
#define DEM_J1939_SUPPORT                                   STD_OFF
#define DEM_MONITORDATA_SUPPORT                             STD_OFF
/*DemPTOSupport*/
#define DEM_CFG_PTO_SUPPORT                                 STD_OFF
/*DemResetConfirmedBitOnOverflow*/
#define DEM_CFG_RESETCONFIRMEDBITONOVERFLOW                 STD_ON
/*DemStatusBitHandlingTestFailedSinceLastClear*/
#define DEM_CFG_STATUSBITHANDLING_TFSLC                     DEM_STATUS_BIT_AGING_AND_DISPLACEMENT
/*DemStatusBitStorageTestFailed*/
#define DEM_CFG_STATUSBITSTORAGE_TF                         STD_OFF
/*DemSuppressionSupport*/
#define DEM_SUPPRESSION_SUPPORT                             DEM_NO_SUPPRESSION
/*DemTaskTime*/
#define DEM_TASK_TIME                                       ((uint16)10)
/*DemTriggerFiMReports*/
#define DEM_CFG_TRIGGER_FIM_REPORTS                         STD_OFF
/*DemTriggerMonitorInitBeforeClearOk*/
#define DEM_CFG_TRIGGERMONITORINITBEFORECLEAROK             STD_OFF
/*DemVersionInfoApi*/
#define DEM_VERSION_INFO_API                                STD_ON
/*DemClearEventsWithoutDTCEventMemoryRef*/
#define DEM_CFG_EVENT_WITHOUT_REF_DTC_MEMORY                0xFFFF
/*DemOBDEventMemorySetRef*/
#define DEM_CFG_OBD_EVENT_MEMORY_REF                        DEM_DATA_INVALID_U8

#define DEM_MAX_NUMBER_EVENTENTRY_PERMANENT                 0

#define DEM_CORE_NUMBER                                     1
#define DEM_MASTER_COREID                                   ((uint8)0)
#define DEM_FDC_STORAGE_SUPPORT                             STD_OFF
#define DEM_DEBOUNCE_COUNTER_STORAGE_SUPPORT                STD_OFF
#define DEM_EVENT_ONE_TO_ONE_DTC_ENABLED                    STD_ON

#define DEM_EVENT_MAXFDCDCC_SUPPORT                         STD_OFF
#define DEM_EVENT_MAXFDCSLC_SUPPORT                         STD_OFF
#define DEM_EVENT_CSLF_SUPPORT                              STD_OFF
#define DEM_EVENT_CSFF_SUPPORT                              STD_OFF
#define DEM_EVENT_FCSLC_SUPPORT                             STD_OFF
#define DEM_DTC_AGEDCNT_SUPPORT                             STD_OFF
#define DEM_DTC_LASTSTATUS_SUPPORT                          STD_OFF
#define DEM_EVENT_CALLBACK_SUPPORT                          STD_OFF
#define DEM_INITMFORE_CALLBACK_SUPPORT                      STD_OFF
#define DEM_MONITOR_CHANGE_CALLBACK_SUPPORT                 STD_OFF
#define DEM_EVENT_STATUS_CHANGE_CALLBACK_SUPPORT            STD_OFF
#define DEM_EVENT_DATA_CHANGE_CALLBACK_SUPPORT              STD_OFF
#define DEM_CLEAR_EVENT_ALLOWED_CALLBACK_SUPPORT            STD_OFF


/*******************************************************************************
*   Dem Container:DemGeneralOBD ECUC_Dem_00756
*******************************************************************************/
/*ECUC_Dem_00794 DemOBDCentralizedPID21Handling*/
#define DEM_CFG_OBD_CENTRALIZED_PID21_HANDLING              STD_OFF
/*ECUC_Dem_00879 DemOBDCentralizedPID31Handling*/
#define DEM_CFG_OBD_CENTRALIZED_PID31_HANDLING              STD_OFF
/*ECUC_Dem_00795 DemOBDCompliancy*/
#define DEM_CFG_OBD_COMPLIANCY                              ((uint8)0)
/*ECUC_Dem_00900 DemOBDEngineType*/
#define DEM_CFG_OBD_ENGINE_TYPE                             DEM_IGNITION_COMPRESSION
/*ECUC_Dem_00796 DemOBDEventDisplacement*/
#define DEM_CFG_OBD_EVENT_DISPLACEMENT                      STD_OFF
/*ECUC_Dem_00989 DemSupportedObdUdsDtcSeparation*/
#define DEM_CFG_SUPPORTED_OBD_UDS_SEPARATION                STD_OFF
#define DEM_CFG_IGN_CYCLE_REF                               DEM_DATA_INVALID_U8
/*ECUC_Dem_00923 DemOBDDrivingCycleRef*/
#define DEM_CFG_OBD_DRIVING_CYCLE_REF                       DEM_DATA_INVALID_U8
/*ECUC_Dem_00920 DemOBDPFCCycleRef*/
#define DEM_CFG_OBD_PFC_CYCLE_REF                           DEM_DATA_INVALID_U8
/*ECUC_Dem_00922 DemOBDWarmUpCycleRef*/
#define DEM_CFG_OBD_WARMUP_CYCLE_REF                        DEM_DATA_INVALID_U8
/*Ratio configuration*/
#define DEM_NUM_OF_RATIO                                    0
/*PID configuration*/
#define DEM_CFG_OBD_MAXNUM_OF_PID                           0
/*OBD FreezeFrame data length*/
#define DEM_CFG_OBD_FF_LENGTH                               ((uint16)0)
#define DEM_NUM_OF_INDICATOR                                0
#define DEM_NUM_OF_BYTE_RECORD_INDICATOR_STATE              ((uint16)0)

#define DEM_CFG_OBD_TIME_SINCE_ENGINE_START                 DEM_DATA_INVALID_U8
#define DEM_CFG_OBD_IN_VEHICLE_SPEED                        DEM_DATA_INVALID_U8

/*******************************************************************************
*   Dem Container:DemGeneralJ1939
*******************************************************************************/
/*ECUC_Dem_00872 DemJ1939ClearDtcSupport*/
#define DEM_CFG_J1939CLEAR_DTC_SUPPORT                      STD_OFF
/*ECUC_Dem_00868 DemJ1939Dm31Support*/
#define DEM_CFG_J1939DM31_SUPPORT                           STD_OFF
/*ECUC_Dem_00873 DemJ1939ExpandedFreezeFrameSupport*/
#define DEM_CFG_J1939EX_FF_SUPPORT                          STD_OFF
/*ECUC_Dem_00866 DemJ1939FreezeFrameSupport*/
#define DEM_CFG_J1939_FF_SUPPORT                            STD_OFF
/*ECUC_Dem_00867 DemJ1939RatioSupport*/
#define DEM_CFG_J1939_RATIO_SUPPORT                         STD_OFF
/*ECUC_Dem_00869 DemJ1939Readiness1Support*/
#define DEM_CFG_J1939READINESS_1_SUPPORT                    STD_OFF
/*ECUC_Dem_00870 DemJ1939Readiness2Support*/
#define DEM_CFG_J1939READINESS_2_SUPPORT                    STD_OFF
/*ECUC_Dem_00871 DemJ1939Readiness3Support*/
#define DEM_CFG_J1939READINESS_3_SUPPORT                    STD_OFF
/*ECUC_Dem_00865 DemJ1939ReadingDtcSupport*/
#define DEM_CFG_J1939READING_DTC_SUPPORT                    STD_OFF

/*******************************************************************************
*   DemGeneral Macros
*******************************************************************************/
#define DEM_NUM_OF_OPCYCLE                                  2
#define DEM_NUM_OF_EN_CONDITION                             12
#define DEM_NUM_OF_EN_GROUP                                 9
#define DEM_NUM_OF_STOR_CONDITION                           0
#define DEM_NUM_OF_STOR_GROUP                               0
#define DEM_NUM_OF_BLOCKID                                  1
#define DEM_NUM_OF_DTCGROUP                                 0
#define DEM_NUM_OF_DID                                      0
#define DEM_NUM_OF_DATA                                     10
#define DEM_NUM_OF_EXTDATACLASS                             1
#define DEM_NUM_OF_EXTDATAREC                               1
#define DEM_NUM_OF_FFRECCLASS                               0
#define DEM_NUM_OF_FFRECNUM                                 0
#define DEM_NUM_OF_FFCLASS                                  0
#define DEM_NUM_OF_CLIENT                                   ((uint8)1)
#define DEM_NUM_OF_EVENTMEMORYSET                           ((uint8)1)

#define DEM_MAXNUM_CAPTURE_DATA_PER_MAINCYCLE               ((uint16)4)

#define Dem_EventMemory_Set0                                ((uint8)0)

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


#define Dem_OpCycle_OperationCycle_DEM_IGNITION             ((uint8)0)
#define Dem_OpCycle_OperationCycle_DEM_WARMUP               ((uint8)1)


#define Dem_EnableCond_PowerVoltage_9V_16V                  0
#define Dem_EnableCond_ECU_ActiveStatus                     1
#define Dem_EnableCond_AfterPowerIGN_1s                     2
#define Dem_EnableCond_EnteringNetworkModeFor3s             3
#define Dem_EnableCond_NotInBusoffStatus                    4
#define Dem_EnableCond_StopMonitoringImmediatelyWhenNotInNetworkMode  5
#define Dem_EnableCond_VehState_Driving_or_DrvRdy_for_3seconds        6
#define Dem_EnableCond_TheValveIStarted                     7
#define Dem_EnableCond_TheAirPumpIsStarted                  8
#define Dem_EnableCond_TheHeatorIStarted                    9
#define Dem_EnableCond_IGNPowerOn                           10
#define Dem_EnableCond_OnlyDracoHorizonVersion              11


#define Dem_DemClient_0                                     0

#define DEM_MAXNUM_OF_EVENT                                 ((Dem_EventIdType)40)
#define DEM_MAXNUM_OF_DTC                                   ((uint16)20)
#define DEM_NUM_OF_DTCATB                                   ((uint8)2)
#define DEM_MAX_NUM_OF_DTR                                  0
#define DEM_NUM_OF_COUNTER_BASED                            0
#define DEM_NUM_OF_TIME_BASED                               6
#define DEM_MAX_FFSIZE_OF_DTC                               0
#define DEM_MAX_EXTSIZE_OF_DTC                              14
#define DEM_MAX_J1939FFSIZE_OF_DTC                          0
#define DEM_MAX_J1939EXPFFSIZE_OF_DTC                       0
#define DEM_NUM_OF_PRIMARYMEM                               1
#define DEM_NUM_OF_USERDEF                                  0

#define Dem_WriteBlock(BlockId,DataPtr)                     NvM_WriteBlock(BlockId,(uint8*)DataPtr)
#define Dem_GetErrorStatus(BlockId,ResultPtr)               NvM_GetErrorStatus(BlockId,ResultPtr)

#endif /* DEM_CFG_H */



