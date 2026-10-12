/************************ Include Files ************************/
#include <stdint.h>
#include <string.h>
#include "Version.h"
#include "Version_Data.h"
#include "Basic_Types.h"
#include "Basic_Config.h"
#include "Rte_Adc_If.h"
#include "Dflash.h"
#include "Power_Bat.h"
#include "Rte_Swc.h"
#include "Rte_Log.h"
#include "Version_Data_Class.h"
#include "Version_Data_Def.h"
#include "Version_Data_Class.h"
#include "Version_Data_Def.h"
#include "Version_Data_Class.h"
/************************ Macro Definitions ************************/
#ifdef VERSION_PRINTF_ENABLE
#define VERSION_PRINTF RTE_LOG_PRINTF
#else
#define VERSION_PRINTF(...)
#endif

#define VERSION_ARRAY_SIZE(array) (sizeof(array) / sizeof((array)[0]))

/************************ Private Global Variables ************************/
/**
 * @brief 硬件版本映射表（按检测电压上限升序，末行 0xFFFFFFFF 为哨兵，任意电压必命中）。
 *        每行：检测电压上限、内部版本号、客户零件号、客户基线号；
 *        零件号末位字母为小版本，随硬件版本电阻档递增（前两档同为'A'，与原厂数据一致）。
 *        字符串长度须与对应字段长度一致（恰好填满数组、不含结束符），字段长度见 Version.h 宏定义。
 */
#if defined(HIGH_CONFIGURATION) && defined(PISCES_MCM_D)
static const version_map_t hard_version_table[] = {
    { 111U,        "100", "P0441087 AA", "  " },
    { 338U,        "110", "P0441087 AA", "  " },
    { 566U,        "120", "P0441087 AB", "  " },
    { 805U,        "130", "P0441087 AC", "  " },
    { 1062U,       "140", "P0441087 AD", "  " },
    { 1327U,       "150", "P0441087 AE", "  " },
    { 1565U,       "160", "P0441087 AF", "  " },
    { 1782U,       "170", "P0441087 AG", "  " },
    { 2020U,       "180", "P0441087 AH", "  " },
    { 2321U,       "190", "P0441087 AI", "  " },
    { 2629U,       "200", "P0441087 AJ", "  " },
    { 2931U,       "210", "P0441087 AK", "  " },
    { 3218U,       "220", "P0441087 AL", "  " },
    { 3440U,       "230", "P0441087 AM", "  " },
    { 3678U,       "240", "P0441087 AN", "  " },
    { 3938U,       "250", "P0441087 AO", "  " },
    { 4170U,       "260", "P0441087 AP", "  " },
    { 4391U,       "270", "P0441087 AQ", "  " },
    { 4616U,       "280", "P0441087 AR", "  " },
    { 0xFFFFFFFFU, "290", "P0441087 AS", "  " },
};
#elif defined(HIGH_CONFIGURATION) && defined(PISCES_MCM_P)
static const version_map_t hard_version_table[] = {
    { 111U,        "100", "P0441094 AA", "  " },
    { 338U,        "110", "P0441094 AA", "  " },
    { 566U,        "120", "P0441094 AB", "  " },
    { 805U,        "130", "P0441094 AC", "  " },
    { 1062U,       "140", "P0441094 AD", "  " },
    { 1327U,       "150", "P0441094 AE", "  " },
    { 1565U,       "160", "P0441094 AF", "  " },
    { 1782U,       "170", "P0441094 AG", "  " },
    { 2020U,       "180", "P0441094 AH", "  " },
    { 2321U,       "190", "P0441094 AI", "  " },
    { 2629U,       "200", "P0441094 AJ", "  " },
    { 2931U,       "210", "P0441094 AK", "  " },
    { 3218U,       "220", "P0441094 AL", "  " },
    { 3440U,       "230", "P0441094 AM", "  " },
    { 3678U,       "240", "P0441094 AN", "  " },
    { 3938U,       "250", "P0441094 AO", "  " },
    { 4170U,       "260", "P0441094 AP", "  " },
    { 4391U,       "270", "P0441094 AQ", "  " },
    { 4616U,       "280", "P0441094 AR", "  " },
    { 0xFFFFFFFFU, "290", "P0441094 AS", "  " },
};
#elif defined(LOW_CONFIGURATION) && defined(PISCES_MCM_D)
static const version_map_t hard_version_table[] = {
    { 111U,        "100", "P0441079 AA", "  " },
    { 338U,        "110", "P0441079 AA", "  " },
    { 566U,        "120", "P0441079 AB", "  " },
    { 805U,        "130", "P0441079 AC", "  " },
    { 1062U,       "140", "P0441079 AD", "  " },
    { 1327U,       "150", "P0441079 AE", "  " },
    { 1565U,       "160", "P0441079 AF", "  " },
    { 1782U,       "170", "P0441079 AG", "  " },
    { 2020U,       "180", "P0441079 AH", "  " },
    { 2321U,       "190", "P0441079 AI", "  " },
    { 2629U,       "200", "P0441079 AJ", "  " },
    { 2931U,       "210", "P0441079 AK", "  " },
    { 3218U,       "220", "P0441079 AL", "  " },
    { 3440U,       "230", "P0441079 AM", "  " },
    { 3678U,       "240", "P0441079 AN", "  " },
    { 3938U,       "250", "P0441079 AO", "  " },
    { 4170U,       "260", "P0441079 AP", "  " },
    { 4391U,       "270", "P0441079 AQ", "  " },
    { 4616U,       "280", "P0441079 AR", "  " },
    { 0xFFFFFFFFU, "290", "P0441079 AS", "  " },
};
#elif defined(LOW_CONFIGURATION) && defined(PISCES_MCM_P)
static const version_map_t hard_version_table[] = {
    { 111U,        "100", "P0439358 AA", "  " },
    { 338U,        "110", "P0439358 AA", "  " },
    { 566U,        "120", "P0439358 AB", "  " },
    { 805U,        "130", "P0439358 AC", "  " },
    { 1062U,       "140", "P0439358 AD", "  " },
    { 1327U,       "150", "P0439358 AE", "  " },
    { 1565U,       "160", "P0439358 AF", "  " },
    { 1782U,       "170", "P0439358 AG", "  " },
    { 2020U,       "180", "P0439358 AH", "  " },
    { 2321U,       "190", "P0439358 AI", "  " },
    { 2629U,       "200", "P0439358 AJ", "  " },
    { 2931U,       "210", "P0439358 AK", "  " },
    { 3218U,       "220", "P0439358 AL", "  " },
    { 3440U,       "230", "P0439358 AM", "  " },
    { 3678U,       "240", "P0439358 AN", "  " },
    { 3938U,       "250", "P0439358 AO", "  " },
    { 4170U,       "260", "P0439358 AP", "  " },
    { 4391U,       "270", "P0439358 AQ", "  " },
    { 4616U,       "280", "P0439358 AR", "  " },
    { 0xFFFFFFFFU, "290", "P0439358 AS", "  " },
};
#else
#error "Please define the configuration"
#endif
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/
/**
 * @brief  按硬件检测电压查版本表
 * @param  ver_det_voltage - 硬件版本检测ADC电压值
 * @return 匹配的版本表项指针（末行哨兵兜底，正常必命中；防御性返回末项）
 */
static const version_map_t* Snf_Hardware_Version_Match(uint16 ver_det_voltage)
{
    for (uint8 i = 0; i < (uint8)VERSION_ARRAY_SIZE(hard_version_table); i++)
    {
        if (ver_det_voltage <= hard_version_table[i].ver_det_voltage_max)
        {
            return &hard_version_table[i];
        }
    }
    return &hard_version_table[VERSION_ARRAY_SIZE(hard_version_table) - 1U];  //不可达，防御
}

/**
 * @brief  读DFlash，失败时打印日志
 * @param  addr - DFlash地址
 * @param  size - 读取长度
 * @param  buf  - 输出缓冲区
 * @note   失败时缓冲区保持读取前内容，与直接调用Dflash_Read的行为一致
 */
static void Snf_Version_Dflash_Read(bl_Address_t addr, bl_Size_t size, bl_Buffer_t* buf)
{
    if (BL_ERR_OK != Dflash_Read(addr, size, buf))
    {
        VERSION_PRINTF("Dflash read fail, addr = 0x%lx\r\n", addr);
    }
}

/**
 * @brief  获取供应商软件内部版本号（DID 0xF195）
 * @return 软件内部版本号缓冲区指针（VERSION_SOFTWARE_INSIDE_LEN 字节）
 * @note   数据为编译期宏 SOFTWARE_INSIDE_VERSION，随配置（高/低配 × MCM_D/P）不同
 */
static uint8* _Snf_Software_Inside_Version_Get(void)
{
    static uint8 software_inside_version[VERSION_SOFTWARE_INSIDE_LEN] = SOFTWARE_INSIDE_VERSION;

    return software_inside_version;
}

/**
 * @brief  获取供应商硬件内部版本号（DID 0xF193）
 * @return 硬件内部版本号缓冲区指针（VERSION_HARDWARE_INSIDE_LEN 字节，ASCII如"110"）
 * @note   经 RTE_ADC_GET_VERSION 读取硬件版本检测电压（mV），查 hard_version_table 匹配档位；
 *         结果为模块内 static 缓冲区，每次调用刷新
 */
static uint8* _Snf_Hardware_Inside_Version_Get(void)
{
    static uint8   hardware_inside_version[VERSION_HARDWARE_INSIDE_LEN] = { 0 };
    uint16         ver_det_voltage                                      = RTE_ADC_GET_VERSION();
    version_map_t* ver_map = (version_map_t*)Snf_Hardware_Version_Match(ver_det_voltage);

    memcpy(hardware_inside_version, ver_map->version, VERSION_HARDWARE_INSIDE_LEN);
    return hardware_inside_version;
}

/**
 * @brief  获取客户软件版本号（DID 0xF118）
 * @return 客户软件版本号缓冲区指针（VERSION_SOFTWARE_LEN 字节）
 * @note   数据为编译期宏 SOFTWARE_VERSION，随配置（高/低配 × MCM_D/P）不同
 */
static uint8* _Snf_Software_Version_Get(void)
{
    static uint8 software_version[VERSION_SOFTWARE_LEN] = SOFTWARE_VERSION;

    return software_version;
}

/**
 * @brief  获取客户硬件号（DID 0xF110）
 * @return 客户硬件号缓冲区指针（DF_HARDWARE_NUMBER_SIZE 字节）
 * @note   从 DFlash（DF_HARDWARE_NUMBER_ADDR）读取；读取失败时缓冲区为全 0
 */
static uint8* _Snf_Hardware_Version_Get(void)
{
    static uint8 hardware_version[DF_HARDWARE_NUMBER_SIZE] = { 0 };

    Snf_Version_Dflash_Read(DF_HARDWARE_NUMBER_ADDR, DF_HARDWARE_NUMBER_SIZE, hardware_version);
    return hardware_version;
}

/**
 * @brief  获取客户软件基线号（DID 0xF119）
 * @return 软件基线号缓冲区指针（VERSION_SOFTWARE_BASELINE_LEN 字节）
 * @note   数据为编译期宏 SOFTWARE_BASELINE
 */
static uint8* _Snf_Software_Baseline_Get(void)
{
    static uint8 software_baseline[VERSION_SOFTWARE_BASELINE_LEN] = SOFTWARE_BASELINE;

    return software_baseline;
}

/**
 * @brief  获取客户硬件基线号（DID 0xF111）
 * @return 硬件基线号缓冲区指针（DF_HARDWARE_BASELINE_SIZE 字节）
 * @note   从 DFlash（DF_HARDWARE_BASELINE_ADDR）读取；读取失败时缓冲区为全 0
 */
static uint8* _Snf_Hardware_Baseline_Get(void)
{
    static uint8 hardware_baseline[DF_HARDWARE_BASELINE_SIZE] = { 0 };

    Snf_Version_Dflash_Read(DF_HARDWARE_BASELINE_ADDR, DF_HARDWARE_BASELINE_SIZE, hardware_baseline);
    return hardware_baseline;
}

/**
 * @brief  获取供应商编号（DID 0xF18A）
 * @return 供应商编号缓冲区指针（VERSION_SUPPLIER_NUMBER_LEN 字节）
 * @note   当前硬编码为 "V46014"（ASCII，不足 8 字节右侧补 0）；
 */
static uint8* _Snf_Supplier_Number_Get(void)
{
    // static uint8 supplier_number[VERSION_SUPPLIER_NUMBER_LEN] = SUPPLIER_NUMBER;
    static uint8 supplier_number[VERSION_SUPPLIER_NUMBER_LEN] = { 0x56, 0x34, 0x36, 0x30, 0x31, 0x34, 0x00, 0x00 };  //V46014
    return supplier_number;
}

/**
 * @brief  获取生产日期（DID 0xF18B）
 * @return 生产日期缓冲区指针（VERSION_MANUFACTURING_DATE_LEN 字节）
 * @note   经 RTE 同步读 NvM 块 NvM_FEE_App_Manufacturing_Date；读取失败打印日志，缓冲区为全 0
 */
static uint8* _Snf_Manufacturing_Date_Get(void)
{
    static uint8 ver_manufacturing_date[VERSION_MANUFACTURING_DATE_LEN] = { 0 };

    if (true != Rte_Call_Sync_C_Version_S_Memory_Sync_Read_Block(NvM_FEE_App_Manufacturing_Date, ver_manufacturing_date))
    {
        VERSION_PRINTF("Read Manufacturing Date fail\r\n");
    }
    return ver_manufacturing_date;
}

/**
 * @brief  写入生产日期（DID 0xF18B）
 * @param  data - 生产日期数据缓冲区（VERSION_MANUFACTURING_DATE_LEN 字节）
 * @return true=写入成功，false=写入失败或参数为空
 * @note   经 RTE 同步写 NvM 块 NvM_FEE_App_Manufacturing_Date
 */
static bool _Snf_Manufacturing_Date_Set(uint8* data)
{
    if (NULL == data)
    {
        return false;
    }
    return Rte_Call_Sync_C_Version_S_Memory_Sync_Write_Block(NvM_FEE_App_Manufacturing_Date, data);
}

/**
 * @brief  获取诊断数据库版本（DID 0xF19E）
 * @return 诊断数据库版本缓冲区指针（VERSION_DIAG_DATABASE_LEN 字节）
 * @note   数据为编译期宏 DIAG_DATABASE_VERSION（当前 {0x03, 0x01, 0x01}）
 */
static uint8* _Snf_Diag_Database_Version_Get(void)
{
    static uint8 diag_database_version[VERSION_DIAG_DATABASE_LEN] = DIAG_DATABASE_VERSION;

    return diag_database_version;
}

/**
 * @brief  获取bootloader版本号（DID 0xF150）
 * @return bootloader版本号缓冲区指针（DF_BOOTLOADER_NUMBER_SIZE 字节）
 * @note   从 DFlash（DF_BOOTLOADER_NUMBER_ADDR）读取；读取失败时缓冲区为全 0
 */
static uint8* _Snf_Bootloader_Number_Get(void)
{
    static uint8 bootloader_number[DF_BOOTLOADER_NUMBER_SIZE] = { 0 };

    Snf_Version_Dflash_Read(DF_BOOTLOADER_NUMBER_ADDR, DF_BOOTLOADER_NUMBER_SIZE, bootloader_number);
    return bootloader_number;
}

/**
 * @brief  获取序列号（DID 0xF18C）
 * @return 序列号缓冲区指针（VERSION_SERIAL_NUMBER_LEN 字节）
 * @note   经 RTE 同步读 NvM 块 FeeConf_FeeBlockConfiguration_FEE_App_Serial_number；
 *         读取失败打印日志，缓冲区为全 0
 */
static uint8* _Snf_Serial_Number_Get(void)
{
    static uint8 ver_serial_number[VERSION_SERIAL_NUMBER_LEN] = { 0 };

    if (true != Rte_Call_Sync_C_Version_S_Memory_Sync_Read_Block(FeeConf_FeeBlockConfiguration_FEE_App_Serial_number,
                                                                 ver_serial_number))
    {
        VERSION_PRINTF("Read Serial Number fail\r\n");
    }
    return ver_serial_number;
}

/**
 * @brief  写入序列号（DID 0xF18C）
 * @param  data - 序列号数据缓冲区（VERSION_SERIAL_NUMBER_LEN 字节）
 * @return true=写入成功，false=写入失败或参数为空
 * @note   经 RTE 同步写 NvM 块 FeeConf_FeeBlockConfiguration_FEE_App_Serial_number
 */
static bool _Snf_Serial_Number_Set(uint8* data)
{
    if (NULL == data)
    {
        return false;
    }
    return Rte_Call_Sync_C_Version_S_Memory_Sync_Write_Block(FeeConf_FeeBlockConfiguration_FEE_App_Serial_number, data);
}

/**
 * @brief  获取电源输入电压（DID 0xFD03）
 * @return 电源输入电压缓冲区指针（VERSION_BAT_VOLTAGE_LEN 字节）
 * @note   由 Rte_Call_Sync_C_Version_S_Power_Get_Bat_Voltage() 函数获取
 */
static uint8* _Snf_BAT_Voltage_Get(void)
{
    static uint8 bat_voltage[VERSION_BAT_VOLTAGE_LEN] = { 0 };
    uint16_t     bat_voltage_mv                       = Rte_Call_Sync_C_Version_S_Power_Get_Bat_Voltage();

    /* 拆分为伏整数部分与 0.01V 小数部分 */
    uint8_t volts       = (uint8_t)(bat_voltage_mv / 1000U);
    uint8_t centi_volts = (uint8_t)((bat_voltage_mv % 1000U) / 10U);

    /* BCD 编码：高半字节为十位，低半字节为个位 */
    bat_voltage[0] = (uint8_t)SNF_UINT8_TO_BCD(volts);
    bat_voltage[1] = (uint8_t)SNF_UINT8_TO_BCD(centi_volts);

    return bat_voltage;
}

/**
 * @brief  获取构建时间版本（DID 0xFD05）
 * @return 构建时间缓冲区指针（VERSION_BUILD_TIME_LEN 字节，6 字节 BCD：年(后两位)/月/日/时/分/秒）
 * @note   由编译期 __DATE__ 解析生成（BUILD_YEAR_L/BUILD_MONTH/BUILD_DAY），时/分/秒固定为 0
 */
static uint8* _Snf_Build_Time_Inside_Version_Get(void)
{
    static uint8 build_time_version[VERSION_BUILD_TIME_LEN] = {
        SNF_UINT8_TO_BCD(BUILD_YEAR_L), SNF_UINT8_TO_BCD(BUILD_MONTH),  SNF_UINT8_TO_BCD(BUILD_DAY),
        SNF_UINT8_TO_BCD(BUILD_HOUR),   SNF_UINT8_TO_BCD(BUILD_MINUTE), SNF_UINT8_TO_BCD(BUILD_SECOND)
    };

    return build_time_version;
}

/**
 * @brief  获取构建 Git 哈希值（DID 0xFD06）
 * @return 构建 Git 哈希值缓冲区指针（VERSION_BUILD_GIT_HASH_LEN 字节）
 * @note   由编译期 GIT_HASH 定义生成
 */
static uint8* _Snf_Build_Git_Hash_Inside_Version_Get(void)
{
    static uint8 build_git_hash_version[VERSION_BUILD_GIT_HASH_LEN] = GIT_HASH;

    return build_git_hash_version;
}

/**
 * @brief  获取指纹（DID 0xF15B）
 * @return 指纹缓冲区指针（DF_FINGER_PRINT_SIZE 字节）
 * @note   从 DFlash（DF_FINGER_PRINT_ADDR）读取；读取失败时缓冲区为全 0
 */
static uint8* _Snf_Finger_Print_Get(void)
{
    static uint8 finger_print[DF_FINGER_PRINT_SIZE] = { 0 };

    Snf_Version_Dflash_Read(DF_FINGER_PRINT_ADDR, DF_FINGER_PRINT_SIZE, finger_print);
    return finger_print;
}

/**
 * @brief  获取刷写尝试计数（DID 0xF010）
 * @return 刷写尝试计数缓冲区指针（DF_REPROGRAMMING_ATTEMPT_COUNT_SIZE 字节）
 * @note   从 DFlash（DF_REPROGRAMMING_ATTEMPT_COUNT_ADDR）读取；读取失败时缓冲区为全 0
 */
static uint8* _Snf_Reprogramming_Attempt_Get(void)
{
    static uint8 reprogramming_attempt_count[DF_REPROGRAMMING_ATTEMPT_COUNT_SIZE] = { 0 };

    Snf_Version_Dflash_Read(DF_REPROGRAMMING_ATTEMPT_COUNT_ADDR, DF_REPROGRAMMING_ATTEMPT_COUNT_SIZE,
                            reprogramming_attempt_count);
    return reprogramming_attempt_count;
}

/**
 * @brief  只读数据项的写入桩函数
 * @param  data - 未使用
 * @return false（只读项不可写）
 */
static bool _Snf_Version_Data_Set_Null(uint8* data)
{
    (void)data;
    return false;
}

/************************ Public Function Implementations ************************/
/**
 * @brief  版本数据初始化：按检测电压查版本表，零件号/基线号与DFlash存储不一致时重写
 * @note   由 Snf_Version_Task_Init 调用；读取失败时读缓冲为全0，memcmp同样触发重写，兼作恢复
 */
void Snf_Version_Data_Init(void)
{
    uint16               ver_det_voltage                          = RTE_ADC_GET_VERSION();
    const version_map_t* version_entry                            = Snf_Hardware_Version_Match(ver_det_voltage);
    uint8                hard_version[DF_HARDWARE_NUMBER_SIZE]    = { 0 };
    uint8                hard_baseline[DF_HARDWARE_BASELINE_SIZE] = { 0 };

    VERSION_PRINTF("hw detect voltage = %d\r\n", ver_det_voltage);

    Snf_Version_Dflash_Read(DF_HARDWARE_NUMBER_ADDR, DF_HARDWARE_NUMBER_SIZE, hard_version);
    if (0 != memcmp(version_entry->hardware_part_version, hard_version, DF_HARDWARE_NUMBER_SIZE))
    {
        if (BL_ERR_OK == Dflash_Write(DF_HARDWARE_NUMBER_ADDR, DF_HARDWARE_NUMBER_SIZE, version_entry->hardware_part_version))
        {
            VERSION_PRINTF("Update Hardware Version\r\n");
        }
        else
        {
            VERSION_PRINTF("Update Hardware Version Fail\r\n");
        }
    }

    Snf_Version_Dflash_Read(DF_HARDWARE_BASELINE_ADDR, DF_HARDWARE_BASELINE_SIZE, hard_baseline);
    if (0 != memcmp(version_entry->hardware_baseline_version, hard_baseline, DF_HARDWARE_BASELINE_SIZE))
    {
        if (BL_ERR_OK ==
            Dflash_Write(DF_HARDWARE_BASELINE_ADDR, DF_HARDWARE_BASELINE_SIZE, version_entry->hardware_baseline_version))
        {
            VERSION_PRINTF("Update Hardware Baseline\r\n");
        }
        else
        {
            VERSION_PRINTF("Update Hardware Baseline Fail\r\n");
        }
    }
}

/**
 * @brief  按ID读取版本数据（表驱动分发）
 * @param  id     - 版本数据ID（version_data_id_e）
 * @param  length - 输出数据长度（字节），不需要时传NULL
 * @return 数据缓冲区指针；ID非法时返回NULL且length输出0
 * @note   返回模块内static缓冲区，调用方直接使用、不可释放；重复调用同ID会刷新其内容
 */
uint8* Snf_Version_Data_Get(version_data_id_e id, uint8* length)
{
    uint8  len  = 0;
    uint8* data = NULL;

    if ((uint32)id < (uint32)VERSION_ID_MAX)
    {
        len  = version_data_table[id].len;
        data = version_data_table[id].get();
    }
    if (NULL != length)
    {
        *length = len;
    }
    return data;
}

/**
 * @brief  按ID写入版本数据（表驱动分发）
 * @param  id   - 版本数据ID（version_data_id_e）
 * @param  data - 数据缓冲区
 * @return true=写入成功；false=写入失败、参数为空、ID非法或该数据项只读
 */
bool Snf_Version_Data_Set(version_data_id_e id, uint8* data)
{
    if ((uint32)id >= (uint32)VERSION_ID_MAX || NULL == data)
    {
        return false;
    }
    return version_data_table[id].set(data);
}
