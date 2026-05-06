/************************ Include Files ************************/
#include "Basic.h"

/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/

/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
  * @brief  
  * @param  
  * @return
  */
uint32_t Basic_Cov_U8_Buf_To_U32_Data(uint8_t* buf)
{
    uint32_t result = 0;
    result += LSHIFT(buf[0], 24);
    result += LSHIFT(buf[1], 16);
    result += LSHIFT(buf[2], 8);
    result += LSHIFT(buf[3], 0);
    return result;
}

/**
  * @brief  
  * @param  
  * @return None
  */
void Basic_Cov_U32_Data_To_U8_Buf(uint32_t data, uint8_t* buf)
{
    buf[0] = (uint8_t)RSHIFT(data, 24);
    buf[1] = (uint8_t)RSHIFT(data, 16);
    buf[2] = (uint8_t)RSHIFT(data, 8);
    buf[3] = (uint8_t)RSHIFT(data, 0);
}

/**
  * @brief  
  * @param  
  * @return 
  */
uint16_t Basic_Cov_U8_Buf_To_U16_Data(uint8_t* buf)
{
    uint16_t result = 0;
    result += LSHIFT(buf[0], 8);
    result += LSHIFT(buf[1], 0);
    return result;
}

/**
  * @brief  
  * @param  
  * @return None
  */
void Basic_Cov_U16_Data_To_U8_Buf(uint16_t data, uint8_t* buf)
{
    buf[0] = (uint8_t)RSHIFT(data, 8);
    buf[1] = (uint8_t)RSHIFT(data, 0);
}
