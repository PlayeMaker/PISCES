#ifndef _BASIC_H_
#define _BASIC_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Basic_Types.h"
/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/

/************************ External Variables ************************/

/************************ Function Declarations ************************/
uint32_t Basic_Cov_U8_Buf_To_U32_Data(uint8_t* buf);
void Basic_Cov_U32_Data_To_U8_Buf(uint32_t data, uint8_t* buf);
uint16_t Basic_Cov_U8_Buf_To_U16_Data(uint8_t* buf);
void Basic_Cov_U16_Data_To_U8_Buf(uint16_t data, uint8_t* buf);

#ifdef __cplusplus
}
#endif

#endif /* _BASIC_Type_H_ */