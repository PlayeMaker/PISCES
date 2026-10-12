#ifndef _DRV_CRYPTO_H_
#define _DRV_CRYPTO_H_

/************************ Include Files ************************/
#include <Platform_Types.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/

/************************ Function Declarations ************************/
void Snf_Drv_Crypto_Init(void);
bool Snf_Drv_Crypto_Get_Random_Data(uint8* Data);

#ifdef __cplusplus
}
#endif

#endif /* _DRV_CRYPTO_H_ */