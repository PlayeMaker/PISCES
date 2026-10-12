#ifndef _SECURITY_H_
#define _SECURITY_H_
#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Platform_Types.h"
#include "Security_Types.h"
/************************ Macro Definitions ************************/
#define SECURITY_SECRET_CODE_HI 0x87
#define SECURITY_SECRET_CODE_LO 0x64
/************************ Type Definitions ************************/
typedef enum
{
    SECURITY_NOT_OK,
    SECURITY_OK,
} security_types_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
void              Snf_Security_Get_L2_Seed(uint8* Data);
security_types_e  Snf_Security_Compare_L2_Key(uint8* Key);
security_status_e Snf_Security_Get_Faa_Flag(void);
void              Snf_Security_Set_Faa_Flag(security_status_e status);

#ifdef __cplusplus
}
#endif
#endif  // _SECURITY_H_
