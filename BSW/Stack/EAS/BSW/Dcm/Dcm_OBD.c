/*  BEGIN_FILE_HDR
********************************************************************************
*   NOTICE
*   This software is the property of HiRain Technologies. Any information
*   contained in this doc should not be reproduced, or used, or disclosed
*   without the written authorization from HiRain Technologies.
********************************************************************************
*   File Name       : Dcm_OBD.c
********************************************************************************
*   Project/Product : AUTOSAR R21-11
*   Title           : Dcm_OBD.c
*   Author          : Hirain
********************************************************************************
*   Description: Main source file of the AUTOSAR Diagnositc communcation manager,
*                according to AUTOSAR_SWS_DiagnosticCommunicationManager.pdf
*                (Release R21-11) and SAE J1979.
*
********************************************************************************
*   Limitations: None
*
********************************************************************************
*
********************************************************************************
*   Revision History:
*   Reference to Dcm.c File
********************************************************************************
* END_FILE_HDR*/

/*PRQA S 553 EOF*/
/*
When DCM_OBD_SUPPORT is STD_ON, the code is not empty.
*/

/*PRQA S 857 EOF*/

/*PRQA S 3614,3214,862,292 EOF*/
/*
According to the requirements of AUTOSAR Specification,when locating address
segments in the files of each module,#include "Dcm_MemMap.h" is required.Defined
XXX_START_SEC_ will undefine in Dcm_MemMap.h
*/

/*******************************************************************************
* Includes
*******************************************************************************/
#include "Dcm.h"
#include "Dcm_OBD.h"
#include "Dcm_Lcfg.h"
#if(DCM_CONFIG_VARIANTS == STD_CONFIG_VARIANTS_POSTBUILD)
#include "Dcm_PBcfg.h"
#endif
#if(STD_ON == DCM_DEM_SUPPORT)
#include "Dem.h"
#include "Dem_Dcm.h"
#endif
#include "Bsw_Common.h"
/*******************************************************************************
*   Macro
*******************************************************************************/
#if(STD_ON == DCM_OBD_SUPPORT)
/*Used by OBD services start*/
#define DCM_OBD_AVAILABILITY_PARAMETER         (uint8)0x20
#define DCM_OBD_AVAIL_PARA_LENGTH              (uint8)32
#define DCM_OBD_BIT_NUM_PER_BYTE               (uint8)8
#define DCM_OBD_AVAIL_PARA_BYTE_OFFSET         (uint8)3
/*Used by OBD services end*/
#endif

/*For OBD services*/
#if((DCM_OBD_01_ENABLED == STD_ON) || (DCM_OBD_02_ENABLED == STD_ON))
#define DCM_CFG_PID_NUM                        (Dcm_DspPid[DCM_CURRENT_STAB].NumOfPid)
#define DCM_CFG_PID_TABLE                      (Dcm_DspPid[DCM_CURRENT_STAB].Dcm_DspPidTable)
#define DCM_CFG_PID_ID(PidIdx)                 (DCM_CFG_PID_TABLE[PidIdx].DcmDspPidIdentifier)
#define DCM_CFG_PID_SERVICE(PidIdx)            (DCM_CFG_PID_TABLE[PidIdx].DcmDspPidService)
#define DCM_CFG_PID_SIZE(PidIdx)               (DCM_CFG_PID_TABLE[PidIdx].DcmDspPidSize)
#if(DCM_CONFIG_VARIANTS != STD_CONFIG_VARIANTS_POSTBUILD)
#define DCM_CFG_PID_USED(PidIdx)               (DCM_CFG_PID_TABLE[PidIdx].DcmDspPidUsed)
#else
#define DCM_CFG_PID_USED(PidIdx)               (Dcm_PBConfig->DcmDspPidUsed[DCM_CURRENT_STAB][PidIdx])
#endif
#define DCM_CFG_PID_DATA_NUM(PidIdx)                (DCM_CFG_PID_TABLE[PidIdx].NumOfPidData)
#define DCM_CFG_PID_DATA_OFFSET(PidIdx,DataIdx)     (DCM_CFG_PID_TABLE[PidIdx].DcmDspPidData[DataIdx].DcmDspPidByteOffset)
#define DCM_CFG_PID_DATA_SIZE(PidIdx,DataIdx)       (DCM_CFG_PID_TABLE[PidIdx].DcmDspPidData[DataIdx].DcmDspPidDataByteSize)

#if(DCM_OBD_01_ENABLED == STD_ON)
#define DCM_CFG_PID_DATA_SERVICE01(PidIdx,DataIdx)        \
    (DCM_CFG_PID_TABLE[PidIdx].DcmDspPidData[DataIdx].DcmDspPidService01)
#define DCM_CFG_PID_DATA_SERVICE01_FNC(PidIdx,DataIdx)    \
    (DCM_CFG_PID_TABLE[PidIdx].DcmDspPidData[DataIdx].DcmDspPidService01->DcmDspPidDataReadFnc)
#endif
#endif/*#if((DCM_OBD_01_ENABLED == STD_ON) || (DCM_OBD_02_ENABLED == STD_ON))*/


#if(DCM_OBD_08_ENABLED == STD_ON)
#define DCM_CFG_TID_NUM                        (Dcm_DspRequestControl[DCM_CURRENT_STAB].NumOfTid)
#define DCM_CFG_TID_TABLE                      (Dcm_DspRequestControl[DCM_CURRENT_STAB].Dcm_DspRequestControlTable)
#define DCM_CFG_TID_IN_SIZE(TidIdx)            (DCM_CFG_TID_TABLE[TidIdx].DcmDspRequestControlInBufferSize)
#define DCM_CFG_TID_INFO_BYTE(TidIdx)          (DCM_CFG_TID_TABLE[TidIdx].DcmDspRequestControlInfoByte)
#define DCM_CFG_TID_OUT_SIZE(TidIdx)           (DCM_CFG_TID_TABLE[TidIdx].DcmDspRequestControlOutBufferSize)
#define DCM_CFG_TID_TEST_ID(TidIdx)            (DCM_CFG_TID_TABLE[TidIdx].DcmDspRequestControlTestId)
#define DCM_CFG_TID_FNC(TidIdx)                (DCM_CFG_TID_TABLE[TidIdx].DcmDspRequestControlFunction)
#endif/*#if(DCM_OBD_08_ENABLED == STD_ON)*/


#if(DCM_OBD_09_ENABLED == STD_ON)
#define DCM_CFG_INFOTYPE_NUM                          (Dcm_DspVehInfo[DCM_CURRENT_STAB].NumOfVehInfo)
#define DCM_CFG_INFOTYPE_TABLE                        (Dcm_DspVehInfo[DCM_CURRENT_STAB].Dcm_DspVehInfoTable)
#define DCM_CFG_INFOTYPE_ID(InfoIdx)                  (DCM_CFG_INFOTYPE_TABLE[InfoIdx].DcmDspVehInfoInfoType)
#define DCM_CFG_INFOTYPE_NOD_PRO(InfoIdx)             (DCM_CFG_INFOTYPE_TABLE[InfoIdx].DcmDspVehInfoNODIProvResp)
#define DCM_CFG_INFOTYPE_DATA_NUM(InfoIdx)            (DCM_CFG_INFOTYPE_TABLE[InfoIdx].NumOfVehInfoData)
#define DCM_CFG_INFOTYPE_DATA(InfoIdx)                (DCM_CFG_INFOTYPE_TABLE[InfoIdx].DcmDspVehInfoData)
#define DCM_CFG_INFOTYPE_DATA_ORDER(InfoIdx,DataIdx)  \
    (DCM_CFG_INFOTYPE_TABLE[InfoIdx].DcmDspVehInfoData[DataIdx].DcmDspVehInfoDataOrder)
#define DCM_CFG_INFOTYPE_DATA_FNC(InfoIdx,DataIdx)    \
    (DCM_CFG_INFOTYPE_TABLE[InfoIdx].DcmDspVehInfoData[DataIdx].DcmDspVehInfoDataReadFnc)
#define DCM_CFG_INFOTYPE_DATA_SIZE(InfoIdx,DataIdx)   \
    (DCM_CFG_INFOTYPE_TABLE[InfoIdx].DcmDspVehInfoData[DataIdx].DcmDspVehInfoDataSize)
#define DCM_CFG_INFOTYPE_DATA_PORT(InfoIdx,DataIdx)   \
    (DCM_CFG_INFOTYPE_TABLE[InfoIdx].DcmDspVehInfoData[DataIdx].DcmDspVehInfoDataUsePort)
#endif/*#if(DCM_OBD_09_ENABLED == STD_ON)*/


/******************************************************************************
*   static Vars
******************************************************************************/
#define DCM_START_SEC_VAR_CLEARED_LOCAL_8
#include "Dcm_MemMap.h"
#if((DCM_OBD_01_ENABLED == STD_ON) || (DCM_OBD_02_ENABLED == STD_ON) \
    || (DCM_OBD_08_ENABLED == STD_ON) || (DCM_OBD_09_ENABLED == STD_ON))
STATIC VAR(uint8, DCM_VAR) Dcm_OBDServiceReqData[7];
#endif

/*The following four array parameters are assigned during initialization*/
#if(DCM_OBD_01_ENABLED == STD_ON)
STATIC VAR(uint8, DCM_VAR) Dcm_OBDService01_AvailPID[DCM_CFG_NUM_OF_STAB][DCM_OBD_AVAIL_PARA_LENGTH];
#endif
#if(DCM_OBD_02_ENABLED == STD_ON)
STATIC VAR(uint8, DCM_VAR) Dcm_OBDService02_AvailPID[DCM_CFG_NUM_OF_STAB][DCM_OBD_AVAIL_PARA_LENGTH];
#endif
#if(DCM_OBD_08_ENABLED == STD_ON)
/*Be assigned in Dcm_Init() function*/
STATIC VAR(uint8, DCM_VAR) Dcm_OBDService08_AvailTID[DCM_CFG_NUM_OF_STAB][DCM_OBD_AVAIL_PARA_LENGTH];
#endif
#if(DCM_OBD_09_ENABLED == STD_ON)
/*Be assigned in Dcm_Init() function*/
STATIC VAR(uint8, DCM_VAR) Dcm_OBDService09_AvailInfoType[DCM_CFG_NUM_OF_STAB][DCM_OBD_AVAIL_PARA_LENGTH];

STATIC VAR(uint8, DCM_VAR) Dcm_OBDInfoTypeIndex;
STATIC VAR(uint8, DCM_VAR) Dcm_OBDInfoTypeDataIndex;
#endif

#if((DCM_OBD_03_ENABLED == STD_ON) || (DCM_OBD_07_ENABLED == STD_ON) || (DCM_OBD_0A_ENABLED == STD_ON))
STATIC VAR(uint8, DCM_VAR) Dcm_OBDDtcCounter;
#endif
#define DCM_STOP_SEC_VAR_CLEARED_LOCAL_8
#include "Dcm_MemMap.h"


/*******************************************************************************
*   Macro of Vars
*******************************************************************************/
#if((DCM_OBD_01_ENABLED == STD_ON) || (DCM_OBD_02_ENABLED == STD_ON) \
    || (DCM_OBD_08_ENABLED == STD_ON) || (DCM_OBD_09_ENABLED == STD_ON))
#define DCM_OBD_REQ_DATA(Idx)                    (Dcm_OBDServiceReqData[Idx])
#endif
#if(DCM_OBD_01_ENABLED == STD_ON)
#define DCM_OBD_01_AVAIL_PID(Idx)                (Dcm_OBDService01_AvailPID[DCM_CURRENT_STAB][Idx])
#endif
#if(DCM_OBD_02_ENABLED == STD_ON)
#define DCM_OBD_02_AVAIL_PID(Idx)                (Dcm_OBDService02_AvailPID[DCM_CURRENT_STAB][Idx])
#endif
#if(DCM_OBD_08_ENABLED == STD_ON)
#define DCM_OBD_08_AVAIL_TID(Idx)                (Dcm_OBDService08_AvailTID[DCM_CURRENT_STAB][Idx])
#endif
#if(DCM_OBD_09_ENABLED == STD_ON) 
#define DCM_OBD_09_AVAIL_INFO(Idx)               (Dcm_OBDService09_AvailInfoType[DCM_CURRENT_STAB][Idx])

#define DCM_OBD_INFOTYPE_INDEX                   (Dcm_OBDInfoTypeIndex)
#define DCM_OBD_INFOTYPE_DATA_INDEX              (Dcm_OBDInfoTypeDataIndex)
#endif
#if((DCM_OBD_03_ENABLED == STD_ON) || (DCM_OBD_07_ENABLED == STD_ON) || (DCM_OBD_0A_ENABLED == STD_ON))
#define DCM_OBD_DTC_COUNTER                      (Dcm_OBDDtcCounter)
#endif



/*******************************************************************************
* Declarations and definitions of Internal interfaces
*******************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"

#if(DCM_OBD_01_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_01_ReadPidData
(
    uint8 ReqPID,
    uint8 *DataBuffer,
    uint32 *Length
);
#endif

#if(DCM_OBD_02_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_02_ReadPidData
(
    uint8 ReqPID,
    uint8 ReqFrame,
    uint8 *DataBuffer,
    uint32 *Length
);
#endif

#if(DCM_OBD_09_ENABLED == STD_ON)
STATIC FUNC(Std_ReturnType, DCM_CODE) DspInternal_09_ReadInfoTypeData
(
    Dcm_OpStatusType OpStatus,
    uint8 *DataBuffer,
    uint8 *Length
);
#endif


#if(DCM_OBD_01_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_01_ReadPidData
*
* Description: Read the data of one PID.
*
* Inputs: ReqPID
*
* Outputs: DataBuffer, Length
*
* Return: Std_ReturnType
*
* Limitations: Only used by 01 services
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_01_ReadPidData
(
    uint8 ReqPID,
    uint8 *DataBuffer,
    uint32 *Length
)
{
    Std_ReturnType Result = E_OK;
    uint8 PidIdx;
    uint8 DataIdx;
    uint8 ByteOffset;

    for(PidIdx = (uint8)0; PidIdx < DCM_CFG_PID_NUM; PidIdx++)
    {
        if((DCM_CFG_PID_ID(PidIdx) == ReqPID) && (DCM_CFG_PID_USED(PidIdx) == TRUE) \
            && (DCM_CFG_PID_SERVICE(PidIdx) != DCM_SERVICE_02))
        {
            if(*Length < DCM_CFG_PID_SIZE(PidIdx))
            {
                Result = E_NOT_OK;
            }
            else
            {
                *Length = DCM_CFG_PID_SIZE(PidIdx);

                for(DataIdx = (uint8)0; DataIdx < DCM_CFG_PID_SIZE(PidIdx); DataIdx++)
                {
                    /*SWS_Dcm_00623*//*SWS_Dcm_00944*/
                    DataBuffer[DataIdx] = DCM_DATA_CLEAR;
                }
                /*Read the data value of the PID.*/
                for(DataIdx = (uint8)0; DataIdx < DCM_CFG_PID_DATA_NUM(PidIdx); DataIdx++)
                {
                    if(DCM_CFG_PID_DATA_SERVICE01(PidIdx, DataIdx) != NULL_PTR)
                    {
                        ByteOffset = DCM_CFG_PID_DATA_OFFSET(PidIdx, DataIdx);
                        /*SWS_Dcm_00408*/
                        Result = (*DCM_CFG_PID_DATA_SERVICE01_FNC(PidIdx, DataIdx))(&(DataBuffer[ByteOffset]));
                        if(Result != E_OK)
                        {
                            Result = E_NOT_OK;
                            break;
                        }
                    }
                }
            }/*if(*Length < DCM_CFG_PID_SIZE(PidIdx))*/

            break;/*for(PidIdx = (uint8)0; PidIdx < DCM_CFG_PID_NUM; PidIdx++)*/
        }
    }

    if(PidIdx >= DCM_CFG_PID_NUM)
    {
        /*It means that the ReqPID is not supported or not used in the ECU.*/
        *Length = (uint32)0;
    }
    return Result;
}
#endif

#if(DCM_OBD_02_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_02_ReadPidData
*
* Description: Read the data of one PID.
*
* Inputs: ReqPID, ReqFrame
*
* Outputs: DataBuffer, Length
*
* Return: Std_ReturnType
*
* Limitations: Only used by 02 services
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_02_ReadPidData
(
    uint8 ReqPID,
    uint8 ReqFrame,
    uint8 *DataBuffer,
    uint32 *Length
)
{
    Std_ReturnType Result = E_OK;
    uint8 PidIdx;
    uint8 DataIdx;
    uint8 ByteOffset;
    uint16 DemDataLength;/*Temporarily no effect*/
#if(DCM_DEM_SUPPORT == STD_ON)
    uint32 Dtc = (uint32)0;
#endif

    for(PidIdx = (uint8)0; PidIdx < DCM_CFG_PID_NUM; PidIdx++)
    {
        if((DCM_CFG_PID_ID(PidIdx) == ReqPID) && (DCM_CFG_PID_USED(PidIdx) == TRUE) \
            && (DCM_CFG_PID_SERVICE(PidIdx) != DCM_SERVICE_01))
        {
            if(*Length <  DCM_CFG_PID_SIZE(PidIdx))
            {
                Result = E_NOT_OK;
            }
            else
            {
                *Length = DCM_CFG_PID_SIZE(PidIdx);
                DemDataLength = DCM_CFG_PID_SIZE(PidIdx);

                for(DataIdx = (uint8)0; DataIdx < DCM_CFG_PID_SIZE(PidIdx); DataIdx++)
                {
                    /*SWS_Dcm_00973*//*SWS_Dcm_00974*/
                    DataBuffer[DataIdx] = DCM_DATA_CLEAR;
                }

#if(DCM_DEM_SUPPORT == STD_ON)
                /*Read the data value of the PID.*/
                if(ReqPID == (uint8)0x02)
                {
                    /*SWS_Dcm_00279*//*Special PID need processed specially.*/
                    Result = Dem_DcmGetDTCOfOBDFreezeFrame(ReqFrame, &Dtc, DEM_DTC_FORMAT_OBD);
                    if(Result == E_OK)
                    {
                        DataBuffer[DCM_INDEX_0] = (uint8)(Dtc >> DCM_SHIFT_8);
                        DataBuffer[DCM_INDEX_1] = (uint8)Dtc;
                    }
                    else
                    {
                        /*SWS_Dcm_01061 Dcm shall answer positively with $0000 (indicates no stored freeze frame data).*/
                        Result = E_OK;
                    }
                }
                else/*(ReqPID != (uint8)0x02)*/
#endif/*#if(DCM_DEM_SUPPORT == STD_ON)*/
                {
                    for(DataIdx = (uint8)0; DataIdx < DCM_CFG_PID_DATA_NUM(PidIdx); DataIdx++)
                    {
                        ByteOffset = DCM_CFG_PID_DATA_OFFSET(PidIdx, DataIdx);
                        /*SWS_Dcm_00286*/
#if(DCM_DEM_SUPPORT == STD_ON)
                        Result = Dem_DcmReadDataOfOBDFreezeFrame(ReqPID, DataIdx, &(DataBuffer[ByteOffset]), &DemDataLength);
#else
                        Result = Dcm_Rte_OBD_ReadDataOfOBDFreezeFrame(ReqPID, DataIdx, &(DataBuffer[ByteOffset]), &DemDataLength);
#endif
                        if(Result != E_OK)
                        {
                            Result = E_NOT_OK;
                            break;
                        }
                    }
                }/*if(ReqPID == (uint8)0x02)*/
            }/*if(*Length <  DCM_CFG_PID_SIZE(PidIdx))*/

            break;/*for(PidIdx = (uint8)0; PidIdx < DCM_CFG_PID_NUM; PidIdx++)*/
        }
    }

    if(PidIdx == DCM_CFG_PID_NUM)
    {
        /*It means that the ReqPID is not supported or not used in the ECU.*/
        *Length = (uint32)0;
    }
    return Result;
}
#endif

#if(DCM_OBD_09_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_09_ReadInfoTypeData
*
* Description: Read the data of one InfoType.
*
* Inputs: OpStatus
*
* Outputs: DataBuffer, Length
*
* Return: Std_ReturnType
*
* Limitations: Only used by 09 services
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_09_ReadInfoTypeData
(
    Dcm_OpStatusType OpStatus,
    uint8 *DataBuffer,
    uint8 *Length
)
{
    Std_ReturnType Result = E_OK;
    uint8 DataOrder;
    uint8 *DataElementBuffer;
    uint8 DataLength;
    EcucFncVehInfoDataReadDef DataReadFnc;

    for( ; DCM_OBD_INFOTYPE_DATA_INDEX < DCM_CFG_INFOTYPE_DATA_NUM(DCM_OBD_INFOTYPE_INDEX); )
    {
        /*SWS_Dcm_00423*/
        DataReadFnc = DCM_CFG_INFOTYPE_DATA_FNC(DCM_OBD_INFOTYPE_INDEX, DCM_OBD_INFOTYPE_DATA_INDEX);
        DataOrder = DCM_CFG_INFOTYPE_DATA_ORDER(DCM_OBD_INFOTYPE_INDEX, DCM_OBD_INFOTYPE_DATA_INDEX);
        DataElementBuffer = (DataBuffer + DataOrder);
        DataLength = (*Length - DataOrder);
        Result = (*DataReadFnc)(OpStatus, DataElementBuffer, &DataLength);

        if(Result != E_OK)
        {
            break;
        }
        else/*Result == E_OK*/
        {
            if(DCM_CFG_INFOTYPE_NOD_PRO(DCM_OBD_INFOTYPE_INDEX) == TRUE)
            {
                /*SWS_Dcm_01167*//*constr_6045: In case the responsibility is on provider side
                (DcmDspVehInfoNODIProvResp is set to TRUE), only one DcmDspVehInfoData container shall be allowed.*/
                *Length = (DataOrder + DataLength);
                break;/*for( ; DCM_OBD_INFOTYPE_DATA_INDEX < DCM_CFG_INFOTYPE_DATA_NUM(DCM_OBD_INFOTYPE_INDEX); )*/
            }
            else
            {
                /*SWS_Dcm_00684*/
                if((DCM_OBD_INFOTYPE_DATA_INDEX + (uint8)1) == DCM_CFG_INFOTYPE_DATA_NUM(DCM_OBD_INFOTYPE_INDEX))
                {
                    DataLength = DCM_CFG_INFOTYPE_DATA_SIZE(DCM_OBD_INFOTYPE_INDEX, DCM_OBD_INFOTYPE_DATA_INDEX);
                    *Length = (DataOrder + DataLength);
                }

                DCM_OBD_INFOTYPE_DATA_INDEX++;
            }
        }
    }

    return Result;
}
#endif


/*******************************************************************************
* Definitions of internal global Function
*******************************************************************************/

#if((DCM_OBD_01_ENABLED == STD_ON) || (DCM_OBD_02_ENABLED == STD_ON) || (DCM_OBD_08_ENABLED == STD_ON) || (DCM_OBD_09_ENABLED == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DcmInternal_Init_AvailabilityParameters
*
* Description: Based on the configured PIDs, TIDs and InfoTypes, initialize and set
*              the data that can be read by 0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0
*              and 0xE0 request.
*
* Inputs: None
*
* Outputs: None
*
* Return: None
*
* Limitations: Only used by 01, 02, 08, 09 services.
********************************************************************************
END_FUNCTION_HDR*/
FUNC(void, DCM_CODE) DcmInternal_Init_AvailabilityParameters
(
    void
)
{
    uint8 Idx;/*Index*/
    uint8 BytePos;
    uint8 BitPos;
    uint8 TempSaveActiveProtocolId = DCM_ACTIVE_PCL_ID;
#if(DCM_OBD_01_ENABLED == STD_ON)
    uint8 RowMax_Service01 = (uint8)0;
#endif
#if(DCM_OBD_02_ENABLED == STD_ON)
    uint8 RowMax_Service02 = (uint8)0;
#endif
#if(DCM_OBD_08_ENABLED == STD_ON)
    uint8 RowMax_Service08 = (uint8)0;
#endif
#if(DCM_OBD_09_ENABLED == STD_ON)
    uint8 RowMax_Service09 = (uint8)0;
#endif

    for(DCM_ACTIVE_PCL_ID = (uint8)0; DCM_ACTIVE_PCL_ID < DCM_CFG_NUM_OF_PROTOCOL; DCM_ACTIVE_PCL_ID++)
    {
        for(Idx = (uint8)0; Idx < DCM_OBD_AVAIL_PARA_LENGTH; Idx++)
        {
#if(DCM_OBD_01_ENABLED == STD_ON)
            DCM_OBD_01_AVAIL_PID(Idx) = DCM_DATA_CLEAR;
#endif
#if(DCM_OBD_02_ENABLED == STD_ON)
            DCM_OBD_02_AVAIL_PID(Idx) = DCM_DATA_CLEAR;
#endif
#if(DCM_OBD_08_ENABLED == STD_ON)
            DCM_OBD_08_AVAIL_TID(Idx) = DCM_DATA_CLEAR;
#endif
#if(DCM_OBD_09_ENABLED == STD_ON)
            DCM_OBD_09_AVAIL_INFO(Idx) = DCM_DATA_CLEAR;
#endif
        }

#if((DCM_OBD_01_ENABLED == STD_ON) || (DCM_OBD_02_ENABLED == STD_ON))
        for(Idx = (uint8)0; Idx < DCM_CFG_PID_NUM; Idx++)
        {
            if(DCM_CFG_PID_USED(Idx) == TRUE)
            {
                BytePos = ((DCM_CFG_PID_ID(Idx) - (uint8)1) / DCM_OBD_BIT_NUM_PER_BYTE);
                BitPos = ((DCM_CFG_PID_ID(Idx) - (uint8)1) % DCM_OBD_BIT_NUM_PER_BYTE);
                BitPos = (DCM_OBD_BIT_NUM_PER_BYTE - (uint8)1 - BitPos);

#if(DCM_OBD_01_ENABLED == STD_ON)
                if(DCM_CFG_PID_SERVICE(Idx) != DCM_SERVICE_02)
                {
                    DCM_OBD_01_AVAIL_PID(BytePos) |= ((uint8)0x01 << BitPos);
                    if(RowMax_Service01 < BytePos)
                    {
                        RowMax_Service01 = BytePos;
                    }
                }
#endif/*#if(DCM_OBD_01_ENABLED == STD_ON)*/

#if(DCM_OBD_02_ENABLED == STD_ON)
                if(DCM_CFG_PID_SERVICE(Idx) != DCM_SERVICE_01)
                {
                    DCM_OBD_02_AVAIL_PID(BytePos) |= ((uint8)0x01 << BitPos);
                    if(RowMax_Service02 < BytePos)
                    {
                        RowMax_Service02 = BytePos;
                    }
                }
#endif/*#if(DCM_OBD_02_ENABLED == STD_ON)*/
            }
        }

#if(DCM_OBD_01_ENABLED == STD_ON)
        /*RowMax_Service01 = (RowMax_Service01 / 4)*/
        RowMax_Service01 = (RowMax_Service01 >> DCM_SHIFT_2);

        for(Idx = (uint8)0; Idx <= RowMax_Service01; Idx++)
        {
            BytePos = ((Idx << DCM_SHIFT_2) + DCM_OBD_AVAIL_PARA_BYTE_OFFSET);
            DCM_OBD_01_AVAIL_PID(BytePos) |= ((uint8)0x01);
        }
#endif/*#if(DCM_OBD_01_ENABLED == STD_ON)*/

#if(DCM_OBD_02_ENABLED == STD_ON)
        /*RowMax_Service02 = (RowMax_Service02 / 4)*/
        RowMax_Service02 = (RowMax_Service02 >> DCM_SHIFT_2);

        for(Idx = (uint8)0; Idx <= RowMax_Service02; Idx++)
        {
            BytePos = ((Idx << DCM_SHIFT_2) + DCM_OBD_AVAIL_PARA_BYTE_OFFSET);
            DCM_OBD_02_AVAIL_PID(BytePos) |= ((uint8)0x01);
        }
#endif/*#if(DCM_OBD_02_ENABLED == STD_ON)*/
#endif/*#if((DCM_OBD_01_ENABLED == STD_ON)||(DCM_OBD_02_ENABLED == STD_ON))*/


#if(DCM_OBD_08_ENABLED == STD_ON)
        for(Idx = (uint8)0; Idx < DCM_CFG_TID_NUM; Idx++)
        {
            BytePos = ((DCM_CFG_TID_TEST_ID(Idx) - (uint8)1) / DCM_OBD_BIT_NUM_PER_BYTE);
            BitPos = ((DCM_CFG_TID_TEST_ID(Idx) - (uint8)1) % DCM_OBD_BIT_NUM_PER_BYTE);
            BitPos = (DCM_OBD_BIT_NUM_PER_BYTE - (uint8)1 - BitPos);

            DCM_OBD_08_AVAIL_TID(BytePos) |= ((uint8)0x01 << BitPos);
            if(RowMax_Service08 < BytePos)
            {
                RowMax_Service08 = BytePos;
            }
        }
        /*RowMax_Service08 = (RowMax_Service08 / 4)*/
        RowMax_Service08 = (RowMax_Service08 >> DCM_SHIFT_2);

        for(Idx = (uint8)0; Idx <= RowMax_Service08; Idx++)
        {
            BytePos = ((Idx << DCM_SHIFT_2) + DCM_OBD_AVAIL_PARA_BYTE_OFFSET);
            DCM_OBD_08_AVAIL_TID(BytePos) |= ((uint8)0x01);
        }
#endif/*#if(DCM_OBD_08_ENABLED == STD_ON)*/


#if(DCM_OBD_09_ENABLED == STD_ON)
        for(Idx = (uint8)0; Idx < DCM_CFG_INFOTYPE_NUM; Idx++)
        {
            BytePos = ((DCM_CFG_INFOTYPE_ID(Idx) - (uint8)1) / DCM_OBD_BIT_NUM_PER_BYTE);
            BitPos = ((DCM_CFG_INFOTYPE_ID(Idx) - (uint8)1) % DCM_OBD_BIT_NUM_PER_BYTE);
            BitPos = (DCM_OBD_BIT_NUM_PER_BYTE - (uint8)1 - BitPos);

            DCM_OBD_09_AVAIL_INFO(BytePos) |= ((uint8)0x01 << BitPos);
            if(RowMax_Service09 < BytePos)
            {
                RowMax_Service09 = BytePos;
            }
        }
        /*RowMax_Service09 = (RowMax_Service09 / 4)*/
        RowMax_Service09 = (RowMax_Service09 >> DCM_SHIFT_2);

        for(Idx = (uint8)0; Idx <= RowMax_Service09; Idx++)
        {
            BytePos = ((Idx << DCM_SHIFT_2) + DCM_OBD_AVAIL_PARA_BYTE_OFFSET);
            DCM_OBD_09_AVAIL_INFO(BytePos) |= ((uint8)0x01);
        }
#endif/*#if(DCM_OBD_09_ENABLED == STD_ON)*/
    }
    /*Restore original value*/
    DCM_ACTIVE_PCL_ID = TempSaveActiveProtocolId;
}
#endif

#if(DCM_OBD_01_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_01_RequestCurrentPowertrainDiagnosticData SWS_Dcm_00243
*
* Description: This function is the code implementation of the processing logic
*              for the 0x01 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_01_RequestCurrentPowertrainDiagnosticData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    Dcm_MsgLenType DataIdx;
    uint8 BytePos;
    uint8 ReqPID;
    Dcm_MsgLenType DataLength;
    (void)OpStatus;
    (void)pErrorCode;

    if((pMsgContext->reqDataLen) > DCM_LENGTH_7_BYTE)
    {
        Result = E_NOT_OK;
        /*Reset Dcm, do not send NRC 0x13.*/
        /*DsdInternal_ResetWithoutChangeSessionAndSendResponse();*/
    }
    else
    {
        /*SWS_Dcm_00943*/
        if(((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0)
        {
            for(DataIdx = DCM_INDEX_1; DataIdx < pMsgContext->reqDataLen; DataIdx++)
            {
                DCM_OBD_REQ_DATA((DataIdx - DCM_INDEX_1)) = (pMsgContext->reqData[DataIdx]);
                if(((pMsgContext->reqData[DataIdx]) % DCM_OBD_AVAILABILITY_PARAMETER) != 0)
                {
                    Result = E_NOT_OK;
                    /*SWS_Dcm_00943*/
                    /*Reset Dcm, do not send any negative response.*/
                    /*DsdInternal_ResetWithoutChangeSessionAndSendResponse();*/
                    break;
                }
            }
        }
        else
        {
            for(DataIdx = DCM_INDEX_1; DataIdx < pMsgContext->reqDataLen; DataIdx++)
            {
                DCM_OBD_REQ_DATA((DataIdx - DCM_INDEX_1)) = (pMsgContext->reqData[DataIdx]);
                if(((pMsgContext->reqData[DataIdx]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0)
                {
                    Result = E_NOT_OK;
                    /*SWS_Dcm_00943*/
                    /*Reset Dcm, do not send any negative response.*/
                    /*DsdInternal_ResetWithoutChangeSessionAndSendResponse();*/
                    break;
                }
            }
        }
    }

    if(Result == E_OK)
    {
        if((DCM_OBD_REQ_DATA(DCM_INDEX_0) % DCM_OBD_AVAILABILITY_PARAMETER) == 0)
        {
            /*SWS_Dcm_00407*//*Request PIDs are availability PIDs.*/
            pMsgContext->resDataLen = DCM_LENGTH_1_BYTE;

            for(DataIdx = DCM_INDEX_0; DataIdx < (pMsgContext->reqDataLen - DCM_INDEX_1); DataIdx++)
            {
                BytePos = (DCM_OBD_REQ_DATA(DataIdx) / DCM_OBD_BIT_NUM_PER_BYTE);

                if((BytePos == (uint8)0) || ((DCM_OBD_01_AVAIL_PID((BytePos - (uint8)1)) & (uint8)0x01) != (uint8)0))
                {
                    /*Put the request availability PID in response message buffer.*/
                    pMsgContext->resData[pMsgContext->resDataLen] = DCM_OBD_REQ_DATA(DataIdx);
                    pMsgContext->resDataLen += DCM_LENGTH_1_BYTE;

                    Bsw_MemCpy(&(pMsgContext->resData[pMsgContext->resDataLen]), &(DCM_OBD_01_AVAIL_PID(BytePos)), DCM_LENGTH_4_BYTE);

                    pMsgContext->resDataLen += DCM_LENGTH_4_BYTE;
                }
            }
        }
        else
        {
            /*One byte PID*/
            pMsgContext->resDataLen = DCM_LENGTH_1_BYTE;

            for(DataIdx = DCM_INDEX_0; DataIdx < (pMsgContext->reqDataLen - DCM_LENGTH_1_BYTE); DataIdx++)
            {
                ReqPID = DCM_OBD_REQ_DATA(DataIdx);
                /*One byte PID*/
                DataLength = (pMsgContext->resMaxDataLen - pMsgContext->resDataLen - DCM_LENGTH_1_BYTE);

                Result = DspInternal_01_ReadPidData(ReqPID, \
                        &(pMsgContext->resData[pMsgContext->resDataLen + DCM_LENGTH_1_BYTE]), &DataLength);
                if((Result == E_OK) && (DataLength != (Dcm_MsgLenType)0))
                {
                    pMsgContext->resData[pMsgContext->resDataLen] = ReqPID;
                    pMsgContext->resDataLen += DCM_LENGTH_1_BYTE;
                    pMsgContext->resDataLen += DataLength;
                }
            }
        }
    }

    if((Result == E_NOT_OK) || (pMsgContext->resDataLen == DCM_LENGTH_1_BYTE))
    {
        /*if Result equals E_OK and the response length is 1,
        it means that no request PIDs supported in the ECU.*/
        DsdInternal_ResetWithoutChangeSessionAndSendResponse();
    }
    else
    {
        /*Send positive response.*/
    }

    return Result;
}
#endif

#if(DCM_OBD_02_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_02_RequestPowertrainFreezeFrameData SWS_Dcm_00244
*
* Description: This function is the code implementation of the processing logic
*              for the 0x02 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_02_RequestPowertrainFreezeFrameData
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    Dcm_MsgLenType DataIdx;
    uint8 BytePos;
    uint8 ReqPID;
    uint8 ReqFrame;
    Dcm_MsgLenType DataLength;
    (void)OpStatus;
    (void)pErrorCode;

    if(((pMsgContext->reqDataLen) > DCM_LENGTH_7_BYTE) || (!((pMsgContext->reqDataLen) & 0x01U)))
    {
        Result = E_NOT_OK;
        /*Reset Dcm, do not send NRC 0x13.*/
        DsdInternal_ResetWithoutChangeSessionAndSendResponse();
    }
    else
    {
        /*Check the validity of request data.*/
        /*SWS_Dcm_00972*//*SWS_Dcm_00409*/
        if(((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0)
        {
            for(DataIdx = DCM_INDEX_1; DataIdx < pMsgContext->reqDataLen; DataIdx += DCM_LENGTH_2_BYTE)
            {
                if((((pMsgContext->reqData[DataIdx]) % DCM_OBD_AVAILABILITY_PARAMETER) != 0) \
                    || (pMsgContext->reqData[DataIdx + DCM_INDEX_1] != (uint8)0))
                {
                    Result = E_NOT_OK;
                    /*SWS_Dcm_00972*//*SWS_Dcm_00409*/
                    /*Reset Dcm, do not send any negative response.*/
                    /*DsdInternal_ResetWithoutChangeSessionAndSendResponse();*/
                    break;
                }
            }
        }
        else
        {
            for(DataIdx = DCM_INDEX_1; DataIdx < pMsgContext->reqDataLen; DataIdx += DCM_LENGTH_2_BYTE)
            {
                if((((pMsgContext->reqData[DataIdx]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0) \
                    || (pMsgContext->reqData[DataIdx + DCM_INDEX_1] != 0))
                {
                    Result = E_NOT_OK;
                    /*SWS_Dcm_00972*//*SWS_Dcm_00409*/
                    /*Reset Dcm, do not send any negative response.*/
                    /*DsdInternal_ResetWithoutChangeSessionAndSendResponse();*/
                    break;
                }
            }
        }
    }

    if(Result == E_OK)
    {
        /*Copy the request data into local buffer.*/
        for(DataIdx = DCM_INDEX_1; DataIdx < pMsgContext->reqDataLen; DataIdx++)
        {
            DCM_OBD_REQ_DATA((DataIdx - DCM_INDEX_1)) = (pMsgContext->reqData[DataIdx]);
        }

        /*Calculate the response message.*/
        if((DCM_OBD_REQ_DATA(0) % DCM_OBD_AVAILABILITY_PARAMETER) == (uint8)0)
        {
            /*SWS_Dcm_00284*//*Request PIDs are availability PIDs.*/
            pMsgContext->resDataLen = DCM_LENGTH_1_BYTE;

            for(DataIdx = DCM_INDEX_0; DataIdx < (pMsgContext->reqDataLen - DCM_LENGTH_1_BYTE); DataIdx += DCM_LENGTH_2_BYTE)
            {
                BytePos = (DCM_OBD_REQ_DATA(DataIdx) / DCM_OBD_BIT_NUM_PER_BYTE);

                if((BytePos == (uint8)0) || ((DCM_OBD_02_AVAIL_PID((BytePos - (uint8)1)) & (uint8)0x01) != (uint8)0))
                {
                    /*Put the request availability PID in response message buffer.*/
                    pMsgContext->resData[pMsgContext->resDataLen] = DCM_OBD_REQ_DATA(DataIdx);
                    pMsgContext->resDataLen += DCM_LENGTH_1_BYTE;
                    /*Put the request frame number in response message buffer.*/
                    pMsgContext->resData[pMsgContext->resDataLen] = DCM_OBD_REQ_DATA((DataIdx + DCM_INDEX_1));
                    pMsgContext->resDataLen += DCM_LENGTH_1_BYTE;

                    Bsw_MemCpy(&(pMsgContext->resData[pMsgContext->resDataLen]), &(DCM_OBD_02_AVAIL_PID(BytePos)), DCM_LENGTH_4_BYTE);

                    pMsgContext->resDataLen += DCM_LENGTH_4_BYTE;
                }
            }
        }
        else
        {
            /*Request PIDs are not availability PIDs.*/
            pMsgContext->resDataLen = DCM_LENGTH_1_BYTE;

            for(DataIdx = DCM_INDEX_0; DataIdx < (pMsgContext->reqDataLen - DCM_LENGTH_1_BYTE); DataIdx += DCM_LENGTH_2_BYTE)
            {
                ReqPID = DCM_OBD_REQ_DATA(DataIdx);
                ReqFrame = DCM_OBD_REQ_DATA((DataIdx + DCM_LENGTH_1_BYTE));
                /*One byte PID and one byte frame*/
                DataLength = (pMsgContext->resMaxDataLen - pMsgContext->resDataLen - DCM_LENGTH_2_BYTE);

                Result = DspInternal_02_ReadPidData(ReqPID, ReqFrame, \
                        &(pMsgContext->resData[pMsgContext->resDataLen + DCM_LENGTH_2_BYTE]), &DataLength);
                if((Result == E_OK) && (DataLength != 0))
                {
                    /*SWS_Dcm_00287*//*SWS_Dcm_01254*/
                    pMsgContext->resData[pMsgContext->resDataLen] = ReqPID;
                    pMsgContext->resDataLen += DCM_LENGTH_1_BYTE;
                    pMsgContext->resData[pMsgContext->resDataLen] = ReqFrame;
                    pMsgContext->resDataLen += DCM_LENGTH_1_BYTE;
                    pMsgContext->resDataLen += DataLength;
                }
            }
        }
    }

    /*SWS_Dcm_01252*//*SWS_Dcm_01253*//*SWS_Dcm_01254*/
    if((Result == E_NOT_OK) || (pMsgContext->resDataLen == DCM_LENGTH_1_BYTE))
    {
        /*if Result equals E_OK and the response length is 1,
        it means that no request PIDs supported in the ECU.*/
        DsdInternal_ResetWithoutChangeSessionAndSendResponse();
    }
    else
    {
        /*Send positive response.*/
    }

    return Result;
}
#endif


#if((DCM_OBD_03_ENABLED == STD_ON)||(DCM_OBD_07_ENABLED == STD_ON)||(DCM_OBD_0A_ENABLED == STD_ON))
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_03_07_0A_ObtainingDTC SWS_Dcm_00245, SWS_Dcm_00410, SWS_Dcm_00411
*
* Description: This function is the code implementation of the processing logic
*              for the 0x03, 0x07 and 0x0A service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_03_07_0A_ObtainingDTC
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    uint8 RequestService = (pMsgContext->resData[DCM_SID_INDEX]);
#if(DCM_DEM_SUPPORT == STD_ON)
    uint8 DemClient = (Dcm_DslProtocolRow[DCM_ACTIVE_PCL_ID].DcmDemClientRef);
    uint32 GetDtc;
    Dem_UdsStatusByteType GetDtcStatus;
#endif
    (void)pErrorCode;

    if(OpStatus == DCM_INITIAL)
    {
        if((pMsgContext->reqDataLen) != DCM_LENGTH_1_BYTE)
        {
            Result = E_NOT_OK;
            /*Reset Dcm, do not send NRC 0x13.*/
            /*DsdInternal_ResetWithoutChangeSessionAndSendResponse();*/
        }
        else
        {
            DCM_OBD_DTC_COUNTER = DCM_DATA_CLEAR;
#if(DCM_DEM_SUPPORT == STD_ON)
            if(RequestService == DCM_03_SERVICE)
            {
                /*SWS_Dcm_00289*//*SWS_Dcm_00077*/
                Result = Dem_SetDTCFilter(DemClient, DEM_UDS_STATUS_CDTC, DEM_DTC_FORMAT_OBD, \
                            DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY, FALSE, DEM_SEVERITY_NO_SEVERITY, FALSE);
            }
            else if(RequestService == DCM_07_SERVICE)
            {
                /*SWS_Dcm_00412*//*SWS_Dcm_00077*/
                Result = Dem_SetDTCFilter(DemClient, DEM_UDS_STATUS_PDTC, DEM_DTC_FORMAT_OBD, \
                            DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY, FALSE, DEM_SEVERITY_NO_SEVERITY, FALSE);
            }
            else/*(RequestService == DCM_0A_SERVICE)*/
            {
                /*SWS_Dcm_00330*//*SWS_Dcm_00077*/
                Result = Dem_SetDTCFilter(DemClient, (Dem_UdsStatusByteType)0x00, DEM_DTC_FORMAT_OBD, \
                            DEM_DTC_ORIGIN_PERMANENT_MEMORY, FALSE, DEM_SEVERITY_NO_SEVERITY, FALSE);
            }

            /*if Result == E_NOT_OK, Reset Dcm, do not send any negative response.*/
#endif
        }/*if((pMsgContext->reqDataLen) != (Dcm_MsgLenType)1)*/
    }/*if(OpStatus == DCM_INITIAL)*/

    if(Result == E_OK)
    {
#if(DCM_DEM_SUPPORT == STD_ON)
        do
        {
            /*SWS_Dcm_01227*//*SWS_Dcm_01228*/
            Result = Dem_GetNextFilteredDTC(DemClient, &GetDtc, &GetDtcStatus);

            if(Result == E_OK)
            {
                pMsgContext->resData[DCM_INDEX_2 + (DCM_OBD_DTC_COUNTER * DCM_LENGTH_2_BYTE)] = (uint8)(GetDtc >> DCM_SHIFT_8);
                pMsgContext->resData[DCM_INDEX_3 + (DCM_OBD_DTC_COUNTER * DCM_LENGTH_2_BYTE)] = (uint8)GetDtc;
                DCM_OBD_DTC_COUNTER++;
            }
            else if(Result == DEM_PENDING)
            {
                /*03/07/0A are not allowed to send 0x78 negtive response.*/
                Result = E_NOT_OK;
            }
            else/*Result == DEM_NO_SUCH_ELEMENT or E_NOT_OK*/
            {
                /*GetNextFilteredDTC is over*/
            }
        } while(Result == E_OK);

        if(Result == DEM_NO_SUCH_ELEMENT)
        {
            Result = E_OK;
        }
#else
        Result = Dcm_Rte_OBD_ObtainingDTC(RequestService, &(pMsgContext->resData[DCM_INDEX_2]), &DCM_OBD_DTC_COUNTER);
#endif
    }

    if(Result == E_OK)
    {
        /*SWS_Dcm_01227*//*SWS_Dcm_01228*//*Send positive response.*/
        pMsgContext->resData[DCM_INDEX_1] = DCM_OBD_DTC_COUNTER;
        pMsgContext->resDataLen = (DCM_LENGTH_2_BYTE + (DCM_OBD_DTC_COUNTER * DCM_LENGTH_2_BYTE));
    }
    else
    {
        /*Reset Dcm*/
        DsdInternal_ResetWithoutChangeSessionAndSendResponse();
    }

    return Result;
}
#endif

#if(DCM_OBD_04_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_04_ClearEmissionRelatedDiagnosticInformation SWS_Dcm_00246
*
* Description: This function is the code implementation of the processing logic
*              for the 0x04 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_04_ClearEmissionRelatedDiagnosticInformation
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
#if(DCM_DEM_SUPPORT == STD_ON)
    uint8 DemClient = (Dcm_DslProtocolRow[DCM_ACTIVE_PCL_ID].DcmDemClientRef);
#endif

    if(OpStatus == DCM_INITIAL)
    {
        if((pMsgContext->reqDataLen) != DCM_LENGTH_1_BYTE)
        {
            Result = E_NOT_OK;
            /*Reset Dcm, do not send NRC 0x13.*/
            DsdInternal_ResetWithoutChangeSessionAndSendResponse();
        }
        else
        {
#if(DCM_DEM_SUPPORT == STD_ON)
            /*SWS_Dcm_00004*/
            Result = Dem_SelectDTC(DemClient, DEM_DTC_GROUP_ALL, DEM_DTC_FORMAT_OBD, DEM_DTC_ORIGIN_OBD_RELEVANT_MEMORY);
            /*Dem_SelectDTC has only two return values: E_OK and DEM_BUSY.*/
            if(Result == DEM_BUSY)
            {
                *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
                Dcm_SetNRC22Reason(DCM_NRC22_REASON_4);
#endif
                Result = E_NOT_OK;
            }
#endif
        }
    }

    if(Result == E_OK)
    {
#if(DCM_DEM_SUPPORT == STD_ON)
        Result = Dem_ClearDTC(DemClient);

        if(Result == DEM_PENDING)
        {
            /*SWS_Dcm_00703*/
            Result = DCM_E_PENDING;
        }
#else
        Result = Dcm_Rte_OBD_ClearDTC(OpStatus);

        if(Result == DCM_E_PENDING)
        {
            /*SWS_Dcm_00703*/
        }
#endif
        else if(Result == E_OK)
        {
            /*SWS_Dcm_00413*//*Send positve respnse.*/
            pMsgContext->resDataLen = DCM_LENGTH_1_BYTE;
        }
        else/*(Result == DEM_CLEAR_FAILED / DEM_CLEAR_BUSY / DEM_CLEAR_MEMORY_ERROR / E_NOT_OK)*/
        {
            /*SWS_Dcm_00704*//*SWS_Dcm_00967*//*SWS_Dcm_01067*/
            *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
            Dcm_SetNRC22Reason(DCM_NRC22_REASON_4);
#endif
            Result = E_NOT_OK;
        }
    }

    return Result;
}
#endif

#if(DCM_OBD_06_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_06_RequestOnBoardMonitoringTestResults SWS_Dcm_00414
*
* Description: This function is the code implementation of the processing logic
*              for the 0x06 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_06_RequestOnBoardMonitoringTestResults
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    Dcm_MsgLenType DataIdx;
    uint8 ReqMID;
    uint32 MIDValue;/*Used for availability MID*/
#if(DCM_DEM_SUPPORT == STD_ON)
    uint8 TidIdx;
    uint8 NumOfTIDs;/*Number of TIDs*/
    uint8 TIDValue;/*Std./Manuf. Defined TID*/
    uint8 UaSID;/*Unit And Scaling ID*/
    uint16 TestValue;/*Test Value*/
    uint16 LowLimValue;/*Min Test Limit/Lower limit value*/
    uint16 UppLimValue;/*Max Test Limit/Upper limit value*/
#else
    uint32 DataLength = 0;
#endif
    (void)OpStatus;
    (void)pErrorCode;

    if((((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0) \
        && ((pMsgContext->reqDataLen) > DCM_LENGTH_7_BYTE))
    {
        Result = E_NOT_OK;
        /*Reset Dcm, do not send NRC 0x13.*/
        /*DsdInternal_ResetWithoutChangeSessionAndSendResponse();*/
    }
    else if(((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0)
    {
        for(DataIdx = DCM_INDEX_1; DataIdx < pMsgContext->reqDataLen; DataIdx++)
        {
            DCM_OBD_REQ_DATA((DataIdx - DCM_INDEX_1)) = (pMsgContext->reqData[DataIdx]);
            if(((pMsgContext->reqData[DataIdx]) % DCM_OBD_AVAILABILITY_PARAMETER) != 0)
            {
                /*SWS_Dcm_00945*/
                Result = E_NOT_OK;
                /*Reset Dcm, do not send any negative response.*/
                /*DsdInternal_ResetWithoutChangeSessionAndSendResponse();*/
                break;
            }
        }
    }
    else if((((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) != 0) \
        && ((pMsgContext->reqDataLen) != DCM_LENGTH_2_BYTE))
    {
        /*SWS_Dcm_00956*/
        Result = E_NOT_OK;
        /*Reset Dcm, do not send NRC 0x13.*/
        /*DsdInternal_ResetWithoutChangeSessionAndSendResponse();*/
    }
    else
    {
        /*do nothing*/
    }

    if((Result == E_OK) && (((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0))
    {
        pMsgContext->resDataLen = DCM_LENGTH_1_BYTE;
        /*SWS_Dcm_00957*/
        for(DataIdx = DCM_INDEX_0; DataIdx < (pMsgContext->reqDataLen - DCM_LENGTH_1_BYTE); DataIdx++)
        {
            ReqMID = DCM_OBD_REQ_DATA(DataIdx);
#if(DCM_DEM_SUPPORT == STD_ON)
            Result = Dem_DcmGetAvailableOBDMIDs(ReqMID, &MIDValue);
#else
            Result = Dcm_Rte_OBD_GetAvailableOBDMIDs(ReqMID, &MIDValue);
#endif
            if(Result == E_OK)
            {
                pMsgContext->resData[pMsgContext->resDataLen] = DCM_OBD_REQ_DATA(DataIdx);
                pMsgContext->resDataLen += DCM_LENGTH_1_BYTE;

                pMsgContext->resData[pMsgContext->resDataLen] = (uint8)(MIDValue >> DCM_SHIFT_24);
                pMsgContext->resData[pMsgContext->resDataLen + DCM_LENGTH_1_BYTE] = (uint8)(MIDValue >> DCM_SHIFT_16);
                pMsgContext->resData[pMsgContext->resDataLen + DCM_LENGTH_2_BYTE] = (uint8)(MIDValue >> DCM_SHIFT_8);
                pMsgContext->resData[pMsgContext->resDataLen + DCM_LENGTH_3_BYTE] = (uint8)MIDValue;
                pMsgContext->resDataLen += DCM_LENGTH_4_BYTE;
            }
        }
    }
    else if((Result == E_OK) && (((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) != 0))
    {
        /*SWS_Dcm_00958*/
        ReqMID = (pMsgContext->reqData[DCM_INDEX_1]);
        pMsgContext->resDataLen = DCM_LENGTH_1_BYTE;
#if(DCM_DEM_SUPPORT == STD_ON)
        Result = Dem_DcmGetNumTIDsOfOBDMID(ReqMID, &NumOfTIDs);

        if((Result == E_OK) && (NumOfTIDs > (uint8)0))
        {
            for(TidIdx = (uint8)0; TidIdx < NumOfTIDs; TidIdx++)
            {
                Result = Dem_DcmGetDTRData(ReqMID, TidIdx, &TIDValue, &UaSID, &TestValue, &LowLimValue, &UppLimValue);
                if(Result == E_OK)
                {
                    pMsgContext->resData[pMsgContext->resDataLen] = ReqMID;
                    pMsgContext->resData[pMsgContext->resDataLen + DCM_LENGTH_1_BYTE] = TIDValue;
                    pMsgContext->resData[pMsgContext->resDataLen + DCM_LENGTH_2_BYTE] = UaSID;
                    pMsgContext->resData[pMsgContext->resDataLen + DCM_LENGTH_3_BYTE] = (uint8)(TestValue >> DCM_SHIFT_8);
                    pMsgContext->resData[pMsgContext->resDataLen + DCM_LENGTH_4_BYTE] = (uint8)TestValue;
                    pMsgContext->resData[pMsgContext->resDataLen + DCM_LENGTH_5_BYTE] = (uint8)(LowLimValue >> DCM_SHIFT_8);
                    pMsgContext->resData[pMsgContext->resDataLen + DCM_LENGTH_6_BYTE] = (uint8)LowLimValue;
                    pMsgContext->resData[pMsgContext->resDataLen + DCM_LENGTH_7_BYTE] = (uint8)(UppLimValue >> DCM_SHIFT_8);
                    pMsgContext->resData[pMsgContext->resDataLen + DCM_LENGTH_8_BYTE] = (uint8)UppLimValue;
                    pMsgContext->resDataLen += DCM_LENGTH_9_BYTE;
                }
                else
                {
                    Result = E_NOT_OK;
                    break;
                }
            }
        }
        else
        {
            Result = E_NOT_OK;
        }/*if((Result == E_OK) && (NumOfTIDs > (uint8)0))*/
#else
        Result = Dcm_Rte_OBD_GetDTRData(ReqMID, &(pMsgContext->resData[DCM_INDEX_2]), &DataLength);

        if(Result == E_OK)
        {
            pMsgContext->resData[DCM_INDEX_1] = ReqMID;
            pMsgContext->resDataLen += DataLength;
        }
#endif
    }
    else
    {
        /*do nothing*/
    }

    if(Result != E_OK)
    {
        DsdInternal_ResetWithoutChangeSessionAndSendResponse();
    }
    else
    {
        /*Send positive response.*/
    }

    return Result;
}
#endif

#if(DCM_OBD_08_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_08_RequestControlOfOnBoardSystem SWS_Dcm_00417
*
* Description: This function is the code implementation of the processing logic
*              for the 0x08 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_08_RequestControlOfOnBoardSystem
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    Dcm_MsgLenType DataIdx;
    uint8 TidIdx;
    uint8 BytePos;
    uint8 ReqTID;
    (void)OpStatus;

    if((pMsgContext->reqDataLen) > DCM_LENGTH_7_BYTE)
    {
        Result = E_NOT_OK;
        /*Reset Dcm, do not send NRC 0x13.*/
        DsdInternal_ResetWithoutChangeSessionAndSendResponse();
    }
    else
    {
        if(((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0)
        {
            for(DataIdx = DCM_INDEX_1; DataIdx < pMsgContext->reqDataLen; DataIdx++)
            {
                DCM_OBD_REQ_DATA((DataIdx - DCM_INDEX_1)) = (pMsgContext->reqData[DataIdx]);
                if(((pMsgContext->reqData[DataIdx]) % DCM_OBD_AVAILABILITY_PARAMETER) != 0)
                {
                    Result = E_NOT_OK;
                    /*SWS_Dcm_00947*//*Reset Dcm, do not send any negative response.*/
                    DsdInternal_ResetWithoutChangeSessionAndSendResponse();
                    break;
                }
            }
        }
    }

    if((Result == E_OK) && (((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0))
    {
        /*SWS_Dcm_00418*//*Request TIDs are availability TIDs.*/
        pMsgContext->resDataLen = DCM_LENGTH_1_BYTE;

        for(DataIdx = DCM_INDEX_0; DataIdx < (pMsgContext->reqDataLen - DCM_LENGTH_1_BYTE); DataIdx++)
        {
            BytePos = (DCM_OBD_REQ_DATA(DataIdx) / DCM_OBD_BIT_NUM_PER_BYTE);

            if((BytePos == (uint8)0) || ((DCM_OBD_08_AVAIL_TID((BytePos - (uint8)1)) & (uint8)0x01) != (uint8)0))
            {
                /*Put the request availability TID in response message buffer.*/
                pMsgContext->resData[pMsgContext->resDataLen] = DCM_OBD_REQ_DATA(DataIdx);
                pMsgContext->resDataLen += DCM_LENGTH_1_BYTE;

                Bsw_MemCpy(&(pMsgContext->resData[pMsgContext->resDataLen]), &(DCM_OBD_08_AVAIL_TID(BytePos)), DCM_LENGTH_4_BYTE);

                pMsgContext->resDataLen += DCM_LENGTH_4_BYTE;
            }
        }
    }
    else if((Result == E_OK) && (((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) != 0))
    {
        /*Copy the request data into local buffer.*/
        for(DataIdx = DCM_INDEX_2; DataIdx < pMsgContext->reqDataLen; DataIdx++)
        {
            DCM_OBD_REQ_DATA((DataIdx - DCM_LENGTH_2_BYTE)) = (pMsgContext->reqData[DataIdx]);
        }

        /*Check the request TID whether supported in the ECU
        and the request data length equals to the value in configuration.*/
        Result = E_NOT_OK;
        ReqTID = (pMsgContext->reqData[DCM_INDEX_1]);

        for(TidIdx = (uint8)0; TidIdx < DCM_CFG_TID_NUM; TidIdx++)
        {
            if((ReqTID == DCM_CFG_TID_TEST_ID(TidIdx)) \
                && ((pMsgContext->reqDataLen - DCM_LENGTH_2_BYTE) == DCM_CFG_TID_IN_SIZE(TidIdx)))
            {
                Result = E_OK;
                break;
            }
        }

        if(Result == E_OK)
        {
            /*SWS_Dcm_00948*/
            Bsw_MemSet(&(pMsgContext->resData[DCM_INDEX_2]), DCM_DATA_CLEAR, DCM_CFG_TID_OUT_SIZE(TidIdx));
            /*SWS_Dcm_00419*//*SWS_Dcm_00691*//*Call the function to process the request data.*/
            Result = (*DCM_CFG_TID_FNC(TidIdx))(&(pMsgContext->resData[DCM_INDEX_2]), &DCM_OBD_REQ_DATA(0));
            /*SWS_Dcm_00420*/
            if(Result == E_OK)
            {
                /*Send positive response.*/
                pMsgContext->resData[DCM_INDEX_1] = ReqTID;
                pMsgContext->resDataLen = (DCM_LENGTH_2_BYTE + DCM_CFG_TID_OUT_SIZE(TidIdx));
            }
            else
            {
                /*SWS_Dcm_01192*/
                *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
                Dcm_SetNRC22Reason(DCM_NRC22_REASON_8);
#endif
                Result = E_NOT_OK;
            }
        }
        else/*Result == E_NOT_OK*/
        {
            /*Reset Dcm, do not send any negative response.*/
            DsdInternal_ResetWithoutChangeSessionAndSendResponse();
        }
    }
    else
    {
        /*do nothing*/
    }

    return Result;
}
#endif

#if(DCM_OBD_09_ENABLED == STD_ON)
/* BEGIN_FUNCTION_HDR
********************************************************************************
* Function Name: DspInternal_09_RequestVehicleInformation SWS_Dcm_00421
*
* Description: This function is the code implementation of the processing logic
*              for the 0x09 service
*
* Inputs: OpStatus, pMsgContext
*
* Outputs: pErrorCode
*
* Return: Std_ReturnType
*
* Limitations: None
********************************************************************************
END_FUNCTION_HDR*/
FUNC(Std_ReturnType, DCM_CODE) DspInternal_09_RequestVehicleInformation
(
    Dcm_OpStatusType OpStatus,
    P2VAR(Dcm_MsgContextType, AUTOMATIC, DCM_VAR) pMsgContext,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) pErrorCode
)
{
    Std_ReturnType Result = E_OK;
    Dcm_MsgLenType DataIdx;
    uint8 InfoIdx;
    uint8 BytePos;
    uint8 ReqInfoType;
    uint8 DataLength;
    uint8 *DataBuffer;

    if(OpStatus == DCM_INITIAL)
    {
        DCM_OBD_INFOTYPE_INDEX = DCM_DATA_CLEAR;
        DCM_OBD_INFOTYPE_DATA_INDEX = DCM_DATA_CLEAR;

        if(((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0)
        {
            if((pMsgContext->reqDataLen) > DCM_LENGTH_7_BYTE)
            {
                Result = E_NOT_OK;
                /*Reset Dcm, do not send NRC 0x13.*/
                DsdInternal_ResetWithoutChangeSessionAndSendResponse();
            }
            else
            {
                for(DataIdx = DCM_INDEX_1; DataIdx < pMsgContext->reqDataLen; DataIdx++)
                {
                    DCM_OBD_REQ_DATA((DataIdx - DCM_INDEX_1)) = (pMsgContext->reqData[DataIdx]);
                    if(((pMsgContext->reqData[DataIdx]) % DCM_OBD_AVAILABILITY_PARAMETER) != 0)
                    {
                        /*SWS_Dcm_00949*/
                        Result = E_NOT_OK;
                        /*Reset Dcm, do not send any negative response.*/
                        DsdInternal_ResetWithoutChangeSessionAndSendResponse();
                        break;
                    }
                }
            }
            
        }
        else
        {
            if((pMsgContext->reqDataLen) != DCM_LENGTH_2_BYTE)
            {
                /*request InfoType not supported*/
                Result = E_NOT_OK;
                /*Reset Dcm, do not send NRC 0x13.*/
                DsdInternal_ResetWithoutChangeSessionAndSendResponse();
            }
            else
            {
                /*One byte ServiceId and one byte InfoType, then continue to read InfoType data.*/
                ReqInfoType = (pMsgContext->reqData[DCM_INDEX_1]);
                Result = E_NOT_OK;

                for(InfoIdx = (uint8)0; InfoIdx < DCM_CFG_INFOTYPE_NUM; InfoIdx++)
                {
                    if(ReqInfoType == DCM_CFG_INFOTYPE_ID(InfoIdx))
                    {
                        Result = E_OK;
                        DCM_OBD_INFOTYPE_INDEX = InfoIdx;
                        break;
                    }
                }

                if(Result == E_NOT_OK)
                {
                    /*request InfoType not supported*/
                    /*Reset Dcm, do not send NRC 0x13.*/
                    DsdInternal_ResetWithoutChangeSessionAndSendResponse();
                }
                else
                {
                    /*One byte ServiceId and one byte InfoType, then continue to read InfoType data.*/
                    pMsgContext->resDataLen = DCM_LENGTH_2_BYTE;
                }
            }
        }
    }

    /*Read data*/
    if((Result == E_OK) && (((pMsgContext->reqData[DCM_INDEX_1]) % DCM_OBD_AVAILABILITY_PARAMETER) == 0))
    {
        pMsgContext->resDataLen = DCM_LENGTH_1_BYTE;
        /*SWS_Dcm_00422*/
        for(DataIdx = DCM_INDEX_0; DataIdx < (pMsgContext->reqDataLen - DCM_LENGTH_1_BYTE); DataIdx++)
        {
            BytePos = ((DCM_OBD_REQ_DATA(DataIdx)) / DCM_OBD_BIT_NUM_PER_BYTE);

            if((BytePos == (uint8)0) || ((DCM_OBD_09_AVAIL_INFO((BytePos - (uint8)1)) & (uint8)0x01) != (uint8)0))
            {
                /*Put the request availability PID in response message buffer.*/
                pMsgContext->resData[pMsgContext->resDataLen] = DCM_OBD_REQ_DATA(DataIdx);
                pMsgContext->resDataLen += DCM_LENGTH_1_BYTE;

                Bsw_MemCpy(&(pMsgContext->resData[pMsgContext->resDataLen]), &(DCM_OBD_09_AVAIL_INFO(BytePos)), DCM_LENGTH_4_BYTE);

                pMsgContext->resDataLen += DCM_LENGTH_4_BYTE;
            }
        }
    }
    else if(Result == E_OK)
    {
        /*One byte ServiceId and one byte InfoType.*/
        if(pMsgContext->resMaxDataLen > (DCM_DATA_U8_MAX + DCM_LENGTH_4_BYTE))
        {
            DataLength = DCM_DATA_U8_MAX;
        }
        else
        {
            DataLength = (pMsgContext->resMaxDataLen - DCM_LENGTH_4_BYTE);
        }
        DataBuffer = &(pMsgContext->resData[DCM_INDEX_2]);
        /*SWS_Dcm_00423*//*Read the InfoType data*/
        Result = DspInternal_09_ReadInfoTypeData(OpStatus, DataBuffer, &DataLength);

        if(Result == E_OK)
        {
            /*Send positive response.*/
            pMsgContext->resData[DCM_INDEX_1] = (pMsgContext->reqData[DCM_INDEX_1]);
            pMsgContext->resDataLen = (DCM_LENGTH_2_BYTE + DataLength);
        }
        else if(Result == E_NOT_OK)
        {
            /*SWS_Dcm_01191*/
            *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
#if(DCM_CAR_PLATFORM == DCM_SAIC_PLATFORM)
            Dcm_SetNRC22Reason(DCM_NRC22_REASON_9);
#endif
        }
        else/*Result == DCM_E_PENDING*/
        {
            /*Call the function next task loop.*/
        }
    }
    else
    {
        /*do nothing*/
    }

    if((Result == E_NOT_OK) || (pMsgContext->resDataLen == DCM_LENGTH_1_BYTE))
    {
        /*if Result equals E_OK and the response length is 1,
        it means that no request infotypes supported in the ECU.*/
        DsdInternal_ResetWithoutChangeSessionAndSendResponse();
    }
    else
    {
        /*Send positive response.*/
    }

    return Result;
}
#endif

#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"



