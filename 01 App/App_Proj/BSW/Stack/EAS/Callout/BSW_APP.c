
#include "BSW_APP.h"
#include "PduR_PBcfg.h"
#include "Basic_Config.h"

#ifdef PISCES_MCM_D
ECU_MODE CURRENT_ECU = MCM_D;
#elif defined(PISCES_MCM_P)
ECU_MODE CURRENT_ECU = MCM_P;
#endif

const PduR_PBConfigType* PduR_InitCfgSet[2] = 
{
    &PduR_PBCfg_0,
    &PduR_PBCfg_1
};
