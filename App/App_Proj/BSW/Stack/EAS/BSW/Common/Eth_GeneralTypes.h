/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE                              
*   This software is the property of HiRain Technologies. Any information 
*   contained in this doc should not be reproduced, or used, or disclosed 
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Eth_GeneralTypes.h
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : Eth_GeneralTypes.h
*   Author          : Hirain
********************************************************************************
*   Description     : Implementation of Eth
*                     provided functionality
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
* 
*   Version     Date          Initials       CR#          Descriptions
*   ---------   ----------    ------------   ----------   ---------------
*   04.00.00    22/12/2023    yanheng.he     N/A          Original
********************************************************************************
* END_FILE_HDR*/
#ifndef ETH_GENERALTYPES_H
#define ETH_GENERALTYPES_H

/*******************************************************************************
*   Includes
*******************************************************************************/  
#include "ComStack_Types.h"


/*******************************************************************************
*   Macro
*******************************************************************************/ 
/*SWS_EthSwt_91033*/
/*As a return code for the function EthSwt_WritePortMirrorConfiguration*/
#define ETHSWT_PORT_MIRRORING_CONFIGURATION_NOT_SUPPORTED  ((Std_ReturnType)0x2)


/*******************************************************************************
*   Typedef
*******************************************************************************/ 
/*******************************************************************************
*   Specification of Ethernet Driver
*******************************************************************************/
/*SWS_Eth_91008*//*SWS_Eth_91011*/
typedef enum
{
  ETH_MODE_DOWN   = 0x0U,
  ETH_MODE_ACTIVE,
  ETH_MODE_ACTIVE_WITH_WAKEUP_REQUEST,
  ETH_MODE_ACTIVE_TX_OFFLINE
}Eth_ModeType;

/*SWS_Eth_00159*/
typedef enum 
{
  ETH_STATE_UNINIT   = 0x0U,
  ETH_STATE_INIT
}Eth_StateType;

/*SWS_Eth_00162*/
typedef enum
{
  ETH_RECEIVED = 0x0U,
  ETH_NOT_RECEIVED,
  ETH_RECEIVED_MORE_DATA_AVAILABLE
} Eth_RxStatusType;

/*SWS_Eth_00163*/
typedef enum
{
  ETH_ADD_TO_FILTER = 0x0U,
  ETH_REMOVE_FROM_FILTER
} Eth_FilterActionType;

/*SWS_Eth_00177*/
typedef enum
{
  ETH_VALID = 0x0U,
  ETH_INVALID,
  ETH_UNCERTAIN
}Eth_TimeStampQualType;

/*SWS_Eth_00160*/
typedef uint16 Eth_FrameType;
/*SWS_Eth_00161*//*Its definition depends on the used CPU.*/
typedef uint8 Eth_DataType;
/*SWS_Eth_00175*/
typedef uint32 Eth_BufIdxType;

/*SWS_Eth_00178*/
typedef struct
{
  uint32 nanoseconds;
  uint32 seconds;
  uint16 secondsHi;
}Eth_TimeStampType;

/*SWS_Eth_00179*/
typedef struct
{
  Eth_TimeStampType diff;
  boolean sign;
}Eth_TimeIntDiffType;

/*SWS_Eth_00180*/
typedef struct
{
  Eth_TimeIntDiffType IngressTimeStampDelta;
  Eth_TimeIntDiffType OriginTimeStampDelta;
}Eth_RateRatioType;

/*SWS_Eth_91001*/
typedef struct
{
  uint8 MacAddr[6U];
  uint16 VlanId;
  uint32 SwitchPort;
}Eth_MacVlanType;

/*SWS_Eth_91007*/
typedef struct
{
  /*dropped packets due to buffer overrun*/
  uint32 DropPktBufOverrun;
  /*dropped packets due to CRC errors*/
  uint32 DropPktCrc;
  /*number of undersize packets which were 
   *less than 64 octets longand were otherwisewell formed.*/
  uint32 UndersizePkt;
  /*number of oversize packets which are longer than 1518 octets
   *(excluding framing bits, but including FCS octets) and were otherwise
   *well formed.*/
  uint32 OversizePkt;
  /*number of alignment errors*/
  uint32 AlgnmtErr;
  /*SQE test error according to IETF RFC1643 dot3StatsSQETestErrors*/
  uint32 SqeTestErr;
  /*The number of inbound packets which were chosen to be discarded
   *even though no errors had been detected to prevent their being
   *deliverable to a higher-layer protocol.*/
  uint32 DiscInbdPkt;
  /*total number of erroneous inbound packets*/
  uint32 ErrInbdPkt;
  /*The number of outbound packets which were chosen to be discarded
   *even though no errors had been detected to prevent their being
   *transmitted.*/
  uint32 DiscOtbdPkt;
  /*total number of erroneous outbound packets*/
  uint32 ErrOtbdPkt;
  /*Single collision frames*/
  uint32 SnglCollPkt;
  /*Multiple collision frames*/
  uint32 MultCollPkt;
  /*Number of deferred transmission*/
  uint32 DfrdPkt;
  /*Number of late collisions*/
  uint32 LatCollPkt;
  /*HwDepCtr(0-3): hardware dependent counter value*/
  uint32 HwDepCtr0;
  uint32 HwDepCtr1;
  uint32 HwDepCtr2;
  uint32 HwDepCtr3;
}Eth_CounterType;

/*SWS_Eth_91002*/
typedef struct
{
  /*The total number of events in which packets were dropped by the
   *probe due to lack of resources.*/
  uint32 RxStatsDropEvents;
  /*The total number of octets of data received on the network*/
  uint32 RxStatsOctets;
  /*The total number of packets received.*/
  uint32 RxStatsPkts;
  /*The total number of good packets received that were directed to the broadcast address*/
  uint32 RxStatsBroadcastPkts;
  /*The total number of good packets received that were directed to a multicast address.*/
  uint32 RxStatsMulticastPkts;
  /*A bad FCS with an integral number of octets or 
   *a bad FCS with a non-integral number of octets (Alignment Error)*/
  uint32 RxStatsCrcAlignErrors;
  /*packets received that were less than 64 octets*/
  uint32 RxStatsUndersizePkts;
  /*packets received that were longer than 1518 octets*/
  uint32 RxStatsOversizePkts;
  /*received that were less than 64 octets in length and had either
   *a bad FCS with an integral number of octets or
   *bad FCS with a non-integral number of octets*/
  uint32 RxStatsFragments;
  /*packets received that were longer than 1518 octets and
   *a bad FCS with an integral number of octets or 
   *a bad FCS with a non-integral number of octets (Alignment Error)*/
  uint32 RxStatsJabbers;
  /*The best estimate of the total number of collisions on this Ethernet segment*/
  uint32 RxStatsCollisions;
  /*packets (including bad packets) received that were 64 octets in length*/
  uint32 RxStatsPkts64Octets;
  /*packets (including bad packets) received that were between 65 and 127 octets in length.*/
  uint32 RxStatsPkts65to127Octets;
  /*packets (including bad packets) received that were between 128 and 255 octets in length.*/
  uint32 RxStatsPkts128to255Octets;
  /*packets (including bad packets) received that were between 256 and 511 octets in length.*/
  uint32 RxStatsPkts256to511Octets;
  /*packets (including bad packets) received that were between 512 and 1023 octets in length. A*/
  uint32 RxStatsPkts512to1023Octets;
  /*packets (including bad packets) received that were between 1024 and 1518 octets in length*/
  uint32 RxStatsPkts1024to1518Octets;
  /*subnetwork-unicast packets delivered to a higher-layer protoco*/
  uint32 RxUnicastFrames;
}Eth_RxStatsType;

/*Eth_TxStatsType*/
typedef struct
{
  /*The total number of octets transmitted out of the interface, including framing characters.*/
  uint32 TxNumberOfOctets;
  /*The total number of packets that higher-level protocols requested be
   *transmitted to a non-unicast (i.e., a subnetwork-broadcast or
   *subnetwork-multicast) address, including those that were discarded or not sent*/
  uint32 TxNUcastPkts;
  /*The total number of packets that higher-level protocols requested be
   *transmitted to a subnetwork-unicast address, including those that were
   *discarded or not sent*/
  uint32 TxUniCastPkts;
}Eth_TxStatsType;

/*SWS_Eth_91004*/
typedef struct
{
  /*The number of outbound packets which were chosen to be discarded
   *even though no errors had been detected to prevent their being
   *transmitted*/
  uint32 TxDroppedNoErrorPkts;
  /*transmitted because of errors*/
  uint32 TxDroppedErrorPkts;
  /*A count of frames for which the first transmission attempt on a
   *particular interface is delayed because the medium is busy*/
  uint32 TxDeferredTrans;
  /*A count of successfully transmitted frames on a particular interface for
   *which transmission is inhibited by exactly one collision*/
  uint32 TxSingleCollision;
  /*A count of successfully transmitted frames on a particular interface for
   *which transmission is inhibited by more than one collision*/
  uint32 TxMultipleCollision;
  /*The number of times that a collision is detected on a particular
   *interface later than 512 bit-times into the transmission of a packet*/
  uint32 TxLateCollision;
  /*A count of frames for which transmission on a particular interface fails
   *due to excessive collisions*/
  uint32 TxExcessiveCollison;
}Eth_TxErrorCounterValuesType;

/*SWS_Eth_91013*/
typedef struct
{
  /* Bit mapped status defined by OA TC6[26] to notify following
   * information(Pos : description):
   *   0x01: Transmit_Buffer_Overflow_Error
   *   0x02: Transmit_Buffer_Underflow_Error
   *   0x03: Receive_Buffer_Overflow_Error
   *   0x04: Loss_Framing_error
   *   0x05: Header_Error
   *   0x06: Reset_Complete
   *   0x07: PHY_Interrupt
   *   0x08: Transmit_Timestamp Capture_Available_A
   *   0x09: Transmit_Timestamp Capture_Available_B
   *   0x0A: Transmit_Timestamp Capture_Available_C
   *   0x0B: Transmit_Frame_Check_Sequence_Error
   *   0x0C: Control_Data_Protection_Error
   *   0x0D - 0xFF: Reserved
   */
  uint32 SpiStatusRegister;
  boolean Sync;
  uint8 BufferStatusTxCredit;
  uint8 BufferStatusRxCredit;
}Eth_SpiStatusType;

/*SWS_Eth_00156*/
/*typedef struct{}Eth_ConfigType;*/


/*******************************************************************************
*   Specification of Ethernet Transceiver Driver
*******************************************************************************/
/*SWS_EthTrcv_00100*/
typedef uint8 EthTrcv_LinkStateType;
#define ETHTRCV_LINK_STATE_DOWN     (EthTrcv_LinkStateType)0
#define ETHTRCV_LINK_STATE_ACTIVE   (EthTrcv_LinkStateType)1

/*SWS_EthTrcv_00101*/
typedef enum
{
  ETHTRCV_STATE_UNINIT = 0x0U,
  ETHTRCV_STATE_INIT
}EthTrcv_StateType;

/*SWS_EthTrcv_00102*/
typedef enum
{
  ETHTRCV_BAUD_RATE_10MBIT = 0x0, /*10MBIT Ethernet connection*/
  ETHTRCV_BAUD_RATE_100MBIT , /*100MBIT Ethernet connection*/
  ETHTRCV_BAUD_RATE_1000MBIT, /*1000MBIT Ethernet connection*/
  ETHTRCV_BAUD_RATE_2500MBIT /*2500MBIT Ethernet Connection*/
}EthTrcv_BaudRateType;

/*SWS_EthTrcv_00114*/
typedef enum
{
  /*No wake up reason detected*/
  ETHTRCV_WUR_NONE = 0x0U,
  /*General wake up detected*/
  ETHTRCV_WUR_GENERAL = 0x1U,
  /*Internal wake up detected*/
  ETHTRCV_WUR_INTERNAL = 0x3U,
  /*Reset wake up detected*/
  ETHTRCV_WUR_RESET = 0x4U,
  /*Power on wake up detected*/
  ETHTRCV_WUR_POWER_ON = 0x5U,
  /*Pin wake up detected*/
  ETHTRCV_WUR_PIN = 0x6U,
  /*System error wake up detected*/
  ETHTRCV_WUR_SYSERR = 0x7U,
  /*Wake-up on data line detected while link is down of the
   *corresponding Ethernet hardware*/
  ETHTRCV_WUR_WODL_WUP = 0x8U,
  /*Wake-up on data line detected while link is active of the
   *used Ethernet hardware*/
  ETHTRCV_WUR_WODL_WUR = 0x9U,
  /*Device internal transfer of wake-up on data line from a neighboring PHY*/
  ETHTRCV_WUR_TRANSFER = 0xAU
}EthTrcv_WakeupReasonType;

/*SWS_EthTrcv_91002*/
typedef enum
{
  /*normal operation*/
  ETHTRCV_PHYTESTMODE_NONE = 0x0U, 
  /*test transmitter droop*/
  ETHTRCV_PHYTESTMODE_1 = 0x1U,
  /*test master timing jitter*/
  ETHTRCV_PHYTESTMODE_2 = 0x2U,
  /*test slave timing jitter*/
  ETHTRCV_PHYTESTMODE_3 = 0x3U,
  /*test transmitter distortion*/
  ETHTRCV_PHYTESTMODE_4 = 0x4U,
  /*test power spectral density (PSD) mask*/
  ETHTRCV_PHYTESTMODE_5 = 0x5U
}EthTrcv_PhyTestModeType;

/*SWS_EthTrcv_00103*/
typedef enum
{
  ETHTRCV_PHYLOOPBACK_NONE = 0x0U, /*normal operation*/
  ETHTRCV_PHYLOOPBACK_INTERNAL = 0x1U, /*internal loopback*/
  ETHTRCV_PHYLOOPBACK_EXTERNAL = 0x2U, /*external loopback*/
  ETHTRCV_PHYLOOPBACK_REMOTE = 0x3U /*remote loopback*/
}EthTrcv_PhyLoopbackModeType;

/*SWS_EthTrcv_91006*/
typedef enum
{
  ETHTRCV_PHYTXMODE_NORMAL = 0x0U, /*normal operation*/
  ETHTRCV_PHYTXMODE_TX_OFF = 0x1U, /*transmitter disabled*/
  ETHTRCV_PHYTXMODE_SCRAMBLER_OFF = 0x2U /*scrambler disabled*/
}EthTrcv_PhyTxModeType;

/*SWS_EthTrcv_91006*/
typedef enum
{
  ETHTRCV_CABLEDIAG_OK = 0x0U, /*Cable diagnostic ok*/
  ETHTRCV_CABLEDIAG_ERROR = 0x1U, /*Cable diagnostic failed*/
  ETHTRCV_CABLEDIAG_SHORT = 0x2U, /*Short circuit detected*/
  ETHTRCV_CABLEDIAG_OPEN = 0x3U,/*Open circuit detected*/
  ETHTRCV_CABLEDIAG_PENDING = 0x4U,/*cable diagnostic is still running*/
  ETHTRCV_CABLEDIAG_WRONG_POLARITY = 0x5U/*cable diagnostics has detected wrong polarity*/
}EthTrcv_CableDiagResultType;

/*SWS_EthTrcv_91013*/
typedef enum
{
  ETHTRCV_MAC_TYPE_CSMA_CD = 0x0U,/*Carrier sence multiple access with collision detection*/
  ETHTRCV_MAC_TYPE_PLCA/*Physical layer collision avoidanc*/
}EthTrcv_MacMethodType;

/*SWS_EthTrcv_00103*/
typedef enum
{
  ETHTRCV_DUPLEX_MODE_HALF = 0U, /* Half duplex Ethernet connection */
  ETHTRCV_DUPLEX_MODE_FULL /* Full duplex Ethernet connection */
}EthTrcv_DuplexModeType;

/*SWS_EthTrcv_00098*/
/*typedef struct{}EthTrcv_ConfigType;*/


/*******************************************************************************
*   Specification of Ethernet Switch Driver
*******************************************************************************/
/*SWS_EthSwt_00227*/
typedef enum
{
  /*switch must not learn new MAC addresses*/
  ETHSWT_MACLEARNING_HWDISABLED,
  /*switch learns new MAC addresses*/
  ETHSWT_MACLEARNING_HWENABLED,
  /*the hardwarelearning is disabled and the switch forwards
   *packets with an unknown source address to a host CPU*/
  ETHSWT_MACLEARNING_SWENABLED
}EthSwt_MacLearningType;

/*SWS_EthSwt_00123*/
typedef enum
{
  ETHSWT_STATE_UNINIT = 0x0u,/*Switch is not yet configured*/
  ETHSWT_STATE_INIT = 0x1u,/*Switch driver is initialized*/
  ETHSWT_STATE_PORTINIT_COMPLETED = 0x2u,/*Port initialization is completed*/
  ETHSWT_STATE_ACTIVE/*Switch is active*/
}EthSwt_StateType;

/*SWS_EthSwt_91002*/
typedef struct
{
  uint8 SwitchIdx;
  uint8 SwitchPortIdx;
}EthSwt_MgmtInfoType;

/*SWS_EthSwt_91017*/
typedef struct
{
  uint8 srcMacAddrFilter[6u];
  uint8 dstMacAddrFilter[6u];
  /*Specifies the VLAN address 0..4094 that should be mirrored. If set to
   *65535, no VLAN filtering shall take place.*/
  uint16 VlanIdFilter;
  /*Divider if only a subset of received frames should be mirrored*/
  uint8 MirroringPacketDivider;
  /*: 0x00 == No VLAN retagging; 0x01 == VLAN retagging; 0x02 == VLAN Double tagging*/
  uint8 MirroringMode;
  /*Specifies the bit mask of Ethernet switch ingress port traffic direction to be mirrored*/
  uint32 TrafficDirectionIngressBitMask;
  /*Specifies the bit mask of Ethernet switch egress port traffic direction to be mirrored*/
  uint32 TrafficDirectionEgressBitMask;
  /*Specifies the Ethernet switch port which capture the mirrored traffic*/
  uint8 CapturePortIdx;
  /*Specifies the VLAN address 0..4094 which shall be used for re-tagging
   *if MirroringMode is set to 0x01 (VLAN re-tagging)
   *set to 65535, the value shall be ignored*/
  uint16 ReTaggingVlanId;
  /*Specifies the VLAN address 0..4094 which shall be used for
   *double-tagging if MirroringMode is set to 0x02 (VLAN double tagging),
   *set to 65535, the value shall be ignored*/
  uint16 DoubleTaggingVlanId;
}EthSwt_PortMirrorCfgType;

/*SWS_EthSwt_91020*/
typedef enum
{
  PORT_MIRRORING_DISABLED = 0x0U,
  PORT_MIRRORING_ENABLED
}EthSwt_PortMirrorStateType;

/*SWS_EthSwt_91035*/
typedef enum
{
  ETHSWT_MGMT_OBJ_UNUSED = 0x0U,/*Object unused*/
  ETHSWT_MGMT_OBJ_OWNED_BY_ETHSWT,/*Object used and EthSwt collects needed data*/
  ETHSWT_MGMT_OBJ_OWNED_BY_UPPER_LAYER /*Object used and the upper layer does calculations*/
}EthSwt_MgmtOwner;

/*SWS_EthSwt_91036*/
typedef struct
{
  /*IngressTimestampValid shall be set to E_NOT_OK if ingress timestamp is not available*/
  Std_ReturnType IngressTimestampValid;
  /*EgressTimestampValid shall be set to E_NOT_OK if ingress timestamp is not available.*/
  Std_ReturnType EgressTimestampValid;
  /*MgmtInfoValid shall be set to E_NOT_OK if ingress timestamp is not available*/
  Std_ReturnType MgmtInfoValid;
}EthSwt_MgmtObjectValidType;

/*SWS_EthSwt_91037*/
typedef struct
{
  /*The validation information for the mgmt_obj*/
  EthSwt_MgmtObjectValidType Validation;
  /*The ingress timestamp value out of the switch*/
  Eth_TimeStampType IngressTimestamp;
  /*The egress timestamp value out of the switch*/
  Eth_TimeStampType EgressTimestamp;
  /*EthSwt_MgmtInfoType*/
  EthSwt_MgmtInfoType MgmtInfo;
  /*The ownership of MgmtObj*/
  EthSwt_MgmtOwner Ownership;
}EthSwt_MgmtObjectType;

/*SWS_EthSwt_00165*/
/*typedef struct{}EthSwt_ConfigType;*/

#endif /* ETH_GENERALTYPES_H */

