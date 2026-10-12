

#include "Std_Types.h"
#include "PduR.h"
typedef enum{
  MCM_D,
  MCM_P
} ECU_MODE;

extern ECU_MODE CURRENT_ECU;
extern const PduR_PBConfigType* PduR_InitCfgSet[2];
