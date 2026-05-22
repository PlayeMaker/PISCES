/*  BEGIN_FILE_HDR
********************************************************************************
*   File Name       : Compiler_Cfg.h
********************************************************************************
*   Project/Product : AUTOSAR BSW PROJECT
*   Title           : Common module configuration File
*   Author          : Hirain
********************************************************************************
*   Description     : Common module configuration File
*
********************************************************************************
*   Limitations     : None
*
********************************************************************************
*
* END_FILE_HDR*/

/*PRQA S 4640 EOF*/
/*
The macros 'ECUC, ECUM, E2E' are standard requirement, could not conflict in the future
with the name of a macro in '<erron.h>'.
*/

#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H
/*******************************************************************************
*   BSW COMMON START
*******************************************************************************/
#define BSW_CODE
#define BSW_CONST
#define BSW_APPL_DATA
/*******************************************************************************
*   BSW COMMON END
*******************************************************************************/
/*******************************************************************************
*   BSWM START
*******************************************************************************/
#define BSWM_CODE
#define BSWM_VAR_NOINIT
#define BSWM_VAR_POWER_ON_INIT
#define BSWM_VAR_FAST
#define BSWM_VAR
#define BSWM_CONST
#define BSWM_APPL_CODE
#define BSWM_APPL_CONST
#define BSWM_APPL_DATA
#define BSWM_CALLOUT_CODE
/*******************************************************************************
*   BSWM END
*******************************************************************************/

/*******************************************************************************
*   CANIF START
*******************************************************************************/
#define CANIF_CODE
#define CANIF_VAR_NOINIT
#define CANIF_VAR_POWER_ON_INIT
#define CANIF_VAR_FAST
#define CANIF_VAR
#define CANIF_CONST
#define CANIF_APPL_CODE
#define CANIF_APPL_CONST
#define CANIF_APPL_DATA
#define CANIF_CALLOUT_CODE
/*******************************************************************************
*   CANIF END
*******************************************************************************/

/*******************************************************************************
*   CANSM START
*******************************************************************************/
#define CANSM_CODE
#define CANSM_VAR_NOINIT
#define CANSM_VAR_POWER_ON_INIT
#define CANSM_VAR_FAST
#define CANSM_VAR
#define CANSM_CONST
#define CANSM_APPL_CODE
#define CANSM_APPL_CONST
#define CANSM_APPL_DATA
#define CANSM_CALLOUT_CODE
/*******************************************************************************
*   CANSM END
*******************************************************************************/

/*******************************************************************************
*   CANTP START
*******************************************************************************/
#define CANTP_CODE
#define CANTP_VAR_NOINIT
#define CANTP_VAR_POWER_ON_INIT
#define CANTP_VAR_FAST
#define CANTP_VAR
#define CANTP_CONST
#define CANTP_APPL_CODE
#define CANTP_APPL_CONST
#define CANTP_APPL_DATA
#define CANTP_CALLOUT_CODE
/*******************************************************************************
*   CANTP END
*******************************************************************************/

/*******************************************************************************
*   COM START
*******************************************************************************/
#define COM_CODE
#define COM_VAR_NOINIT
#define COM_VAR_POWER_ON_INIT
#define COM_VAR_FAST
#define COM_VAR
#define COM_CONST
#define COM_APPL_CODE
#define COM_APPL_CONST
#define COM_APPL_DATA
#define COM_CALLOUT_CODE
/*******************************************************************************
*   COM END
*******************************************************************************/

/*******************************************************************************
*   COMM START
*******************************************************************************/
#define COMM_CODE
#define COMM_VAR_NOINIT
#define COMM_VAR_POWER_ON_INIT
#define COMM_VAR_FAST
#define COMM_VAR
#define COMM_CONST
#define COMM_APPL_CODE
#define COMM_APPL_CONST
#define COMM_APPL_DATA
#define COMM_CALLOUT_CODE
/*******************************************************************************
*   COMM END
*******************************************************************************/

/*******************************************************************************
*   DCM START
*******************************************************************************/
#define DCM_CODE
#define DCM_VAR_NOINIT
#define DCM_VAR_POWER_ON_INIT
#define DCM_VAR_FAST
#define DCM_VAR
#define DCM_CONST
#define DCM_APPL_CODE
#define DCM_APPL_CONST
#define DCM_APPL_DATA
#define DCM_CALLOUT_CODE
/*******************************************************************************
*   DCM END
*******************************************************************************/

/*******************************************************************************
*   DEM START
*******************************************************************************/
#define DEM_CODE
#define DEM_VAR_NOINIT
#define DEM_VAR_POWER_ON_INIT
#define DEM_VAR_FAST
#define DEM_VAR
#define DEM_CONST
#define DEM_APPL_CODE
#define DEM_APPL_CONST
#define DEM_APPL_DATA
#define DEM_CALLOUT_CODE
/*******************************************************************************
*   DEM END
*******************************************************************************/

/*******************************************************************************
*   DET START
*******************************************************************************/
#define DET_CODE
#define DET_VAR_NOINIT
#define DET_VAR_POWER_ON_INIT
#define DET_VAR_FAST
#define DET_VAR
#define DET_CONST
#define DET_APPL_CODE
#define DET_APPL_CONST
#define DET_APPL_DATA
#define DET_CALLOUT_CODE
/*******************************************************************************
*   DET END
*******************************************************************************/

/*******************************************************************************
*   ECUC START
*******************************************************************************/
#define ECUC_CODE
#define ECUC_VAR_NOINIT
#define ECUC_VAR_POWER_ON_INIT
#define ECUC_VAR_FAST
#define ECUC_VAR
#define ECUC_CONST
#define ECUC_APPL_CODE
#define ECUC_APPL_CONST
#define ECUC_APPL_DATA
#define ECUC_CALLOUT_CODE
/*******************************************************************************
*   ECUC END
*******************************************************************************/

/*******************************************************************************
*   ECUM START
*******************************************************************************/
#define ECUM_CODE
#define ECUM_VAR_NOINIT
#define ECUM_VAR_POWER_ON_INIT
#define ECUM_VAR_FAST
#define ECUM_VAR
#define ECUM_CONST
#define ECUM_APPL_CODE
#define ECUM_APPL_CONST
#define ECUM_APPL_DATA
#define ECUM_CALLOUT_CODE
/*******************************************************************************
*   ECUM END
*******************************************************************************/

/*******************************************************************************
*   MEMIF START
*******************************************************************************/
#define MEMIF_CODE
#define MEMIF_VAR_NOINIT
#define MEMIF_VAR_POWER_ON_INIT
#define MEMIF_VAR_FAST
#define MEMIF_VAR
#define MEMIF_CONST
#define MEMIF_APPL_CODE
#define MEMIF_APPL_CONST
#define MEMIF_APPL_DATA
#define MEMIF_CALLOUT_CODE
/*******************************************************************************
*   MEMIF END
*******************************************************************************/

/*******************************************************************************
*   NVM START
*******************************************************************************/
#define NVM_CODE
#define NVM_VAR_NOINIT
#define NVM_VAR_POWER_ON_INIT
#define NVM_VAR_FAST
#define NVM_VAR
#define NVM_CONST
#define NVM_APPL_CODE
#define NVM_APPL_CONST
#define NVM_APPL_DATA
#define NVM_CALLOUT_CODE
/*******************************************************************************
*   NVM END
*******************************************************************************/

/*******************************************************************************
*   PDUR START
*******************************************************************************/
#define PDUR_CODE
#define PDUR_VAR_NOINIT
#define PDUR_VAR_POWER_ON_INIT
#define PDUR_VAR_FAST
#define PDUR_VAR
#define PDUR_CONST
#define PDUR_APPL_CODE
#define PDUR_APPL_CONST
#define PDUR_APPL_DATA
#define PDUR_CALLOUT_CODE
/*******************************************************************************
*   PDUR END
*******************************************************************************/

/*******************************************************************************
*   RTE START
*******************************************************************************/
#define RTE_CODE
#define RTE_VAR_NOINIT
#define RTE_VAR_POWER_ON_INIT
#define RTE_VAR_FAST
#define RTE_VAR
#define RTE_CONST
#define RTE_APPL_CODE
#define RTE_APPL_CONST
#define RTE_APPL_DATA
#define RTE_CALLOUT_CODE
/*******************************************************************************
*   RTE END
*******************************************************************************/

#endif



