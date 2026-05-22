
#include "BSW_APP.h"
#include "PduR_PBcfg.h"


ECU_MODE CURRENT_ECU = MCM_D;
const PduR_PBConfigType* PduR_InitCfgSet[2] = 
{
    &PduR_PBCfg_0,
    &PduR_PBCfg_1
};
