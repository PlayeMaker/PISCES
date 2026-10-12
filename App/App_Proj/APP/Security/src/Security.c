/************************ Include Files ************************/
#include <stdint.h>
#include <string.h>
#include "Security.h"
#include "Security_Types.h"
#include "Rte_Type.h"
#include "Rte_Crypto.h"
#include "Rte_Swc.h"
#include "NvM_Cfg.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/
static uint8 random_L2_seed[4] = { 0 };
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/
/**
 * @brief  算法出自于 《NIO-TS-0000019-V1.1-NT3_Security_Access_Authorization_Specification.pdf》
 * @param data: 传入数据
 * @param length: 传入数据长度
 * @return 计算出的CRC8值
 */
static uint8 crc8(uint8* data, uint8 length) /*function of calculate the Key*/
{
    uint8 t_crc;
    uint8 f, b;
    t_crc = 0xFF;
    for (f = 0; f < length; f++)
    {
        t_crc ^= data[f];
        for (b = 0; b < 8; b++)
        {
            if ((t_crc & 0x80) != 0)
            {
                t_crc <<= 1;
                t_crc ^= 0x1D;  //0x11D;
            }
            else
            {
                t_crc <<= 1;
            }
        }
    }
    return ~t_crc;
}
/**
 * @brief  算法出自于 《NIO-TS-0000019-V1.1-NT3_Security_Access_Authorization_Specification.pdf》
 * @param seed: 传入数据
 * @param sizeSeed: 传入数据长度
 * @param key: 计算出的Key
 * @param maxSizeKey: Key最大长度
 * @param sizeKey: 计算出的Key长度
 * @return 0: 计算成功
 */
static uint8 ASAP1A_CCP_ComputeKeyFromSeed(uint8* seed, uint8 sizeSeed, uint8* key, uint8 maxSizeKey, uint8* sizeKey)
{
    uint16 seedlength = 6;
    uint8  buf_byte[6];
    uint8  crc_byte[7];

    seed[4] = SECURITY_SECRET_CODE_HI;
    seed[5] = SECURITY_SECRET_CODE_LO;

#if 1 /* original version*/
    buf_byte[0] = seed[0];
    buf_byte[1] = seed[1];
    buf_byte[2] = seed[2];
    buf_byte[3] = seed[3];
    buf_byte[4] = seed[4];
    buf_byte[5] = seed[5];
#endif

    crc_byte[0] = crc8(buf_byte, seedlength);

    buf_byte[0] = crc_byte[0];
    crc_byte[1] = crc8(buf_byte, seedlength);

    buf_byte[0] = seed[0];
    buf_byte[1] = crc_byte[1];
    crc_byte[2] = crc8(buf_byte, seedlength);

    buf_byte[1] = seed[1];
    buf_byte[2] = crc_byte[2];
    crc_byte[3] = crc8(buf_byte, seedlength);

    buf_byte[2] = seed[2];
    buf_byte[3] = crc_byte[3];
    crc_byte[4] = crc8(buf_byte, seedlength);

    buf_byte[3] = seed[3];
    buf_byte[4] = crc_byte[4];
    crc_byte[5] = crc8(buf_byte, seedlength);

    buf_byte[4] = seed[4];
    buf_byte[5] = crc_byte[5];
    crc_byte[6] = crc8(buf_byte, seedlength);

    if (crc_byte[3] == 0 && crc_byte[4] == 0 && crc_byte[5] == 0 && crc_byte[6] == 0)
    {
        key[0] = crc_byte[1];
        key[1] = crc_byte[2];
        key[2] = crc_byte[3];
        key[3] = crc_byte[4];
    }
    else
    {
        key[0] = crc_byte[3];
        key[1] = crc_byte[4];
        key[2] = crc_byte[5];
        key[3] = crc_byte[6];
    }

    *sizeKey = 4;

    /* If the return value is false the flash tool stops*/
    return 0;
}
/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
void Snf_Security_Get_L2_Seed(uint8* Data)
{
    memset(random_L2_seed, 0, sizeof(random_L2_seed));
    RTE_CRYPTO_GET_RANDOM_DATA(Data);
    memcpy(random_L2_seed, Data, sizeof(random_L2_seed));
}

security_types_e Snf_Security_Compare_L2_Key(uint8* Key)
{
    uint8 localKey[4];
    uint8 sizeKey = 4;
    uint8 seedBuf[6];

    memcpy(seedBuf, random_L2_seed, 4);
    ASAP1A_CCP_ComputeKeyFromSeed(seedBuf, 4, localKey, 4, &sizeKey);

    return (memcmp(Key, localKey, 4) == 0) ? SECURITY_OK : SECURITY_NOT_OK;
}

security_status_e Snf_Security_Get_Faa_Flag(void)
{
    security_status_e status  = SECURITY_STATUS_LOCKED;
    uint8_t           flag[1] = { 0 };
    if (true == Rte_Call_Sync_C_Security_S_Memory_Sync_Read_Block(NvM_FEE_App_FAA_Flag, flag))
    {
        if (SECURITY_STATUS_UNLOCKED == flag[0])
        {
            status = SECURITY_STATUS_UNLOCKED;
        }
    }
    else
    {
        status = SECURITY_STATUS_LOCKED;
    }
    return status;
}

void Snf_Security_Set_Faa_Flag(security_status_e status)
{
    uint8 flag[1] = { 0 };

    flag[0] = (uint8)status;

    Rte_Call_Sync_C_Security_S_Memory_Sync_Write_Block(NvM_FEE_App_FAA_Flag, flag);
}
