/************************ Include Files ************************/
#include "Version.h"
#include "Basic_Types.h"
#include "Rte_Adc_If.h"
/************************ Macro Definitions ************************/

/************************ Private Global Variables ************************/
/*EOL*/
static char bootloader_inside_version[3] = BOOTLOADER_INSIDE_VERSION;
static char software_inside_version[3]   = SOFTWARE_INSIDE_VERSION;
static char hardware_inside_version[3]   = HARDWARE_INSIDE_VERSION;

static char build_time_version[6] = { BUILD_YEAR_L, BUILD_MONTH, BUILD_DAY, BUILD_HOUR, BUILD_MINUTE, BUILD_SECOND };
static char build_time_version_1[6] = { 0 };

/*Basic*/
static char software_version[11]        = SOFTWARE_VERSION;
static char hardware_version[11]        = HARDWARE_VERSION;
static char software_baseline[2]        = SOFTWARE_BASELINE;
static char hardware_baseline[2]        = HARDWARE_BASELINE;
static char supplier_number[8]          = SUPPLIER_NUMBER;
static char manufacturing_date[3]       = MANUFACTURING_DATE;
static char diag_database_version[3]    = DIAG_DATABASE_VERSION;
static char bootloader_number[3]        = BOOTLOADER_VERSION;
static char serial_number[16]           = SERIAL_NUMBER;
static char supplier_hardware_number[3] = SUPPLIER_HARDWARE_NUMBER;
static char supplier_software_number[3] = SUPPLIER_SOFTWARE_NUMBER;

static const version_map_t version_table[] = {
    {111,  {'1', '0', '0'}},
    {338,  {'1', '1', '0'}},
    {566,  {'1', '2', '0'}},
    {805,  {'1', '3', '0'}},
    {1062, {'1', '4', '0'}},
    {1327, {'1', '5', '0'}},
    {1565, {'1', '6', '0'}},
    {1782, {'1', '7', '0'}},
    {2020, {'1', '8', '0'}},
    {2321, {'1', '9', '0'}},
    {2629, {'2', '0', '0'}},
    {2931, {'2', '1', '0'}},
    {3218, {'2', '2', '0'}},
    {3440, {'2', '3', '0'}},
    {3678, {'2', '4', '0'}},
    {3938, {'2', '5', '0'}},
    {4170, {'2', '6', '0'}},
    {4391, {'2', '7', '0'}},
    {4616, {'2', '8', '0'}},
    {0xFFFFFFFF, {'2', '9', '0'}}
};
/************************ Public Global Variables ************************/

/************************ Private Function Declarations ************************/

/************************ Private Function Implementations ************************/

/************************ Public Function Implementations ************************/
/**
 * @brief  Get EOL bootloader inside version
 * @param  None
 * @return bootloader inside version array pointer
 */
char* Snf_Bootloader_Inside_Version_Get(void)
{
    return bootloader_inside_version;
}

/**
 * @brief  Get EOL software inside version
 * @param  None
 * @return software inside version array pointer
 */
char* Snf_Software_Inside_Version_Get(void)
{
    return software_inside_version;
}

/**
 * @brief  Get EOL hardware inside version
 * @param  None
 * @return hardware inside version array pointer
 */
char* Snf_Hardware_Inside_Version_Get(void)
{
    uint16_t ver_det_voltage = RTE_ADC_GET_VERSION();
    // 查找对应的版本
    for (uint8_t i = 0; i < sizeof(version_table)/sizeof(version_table[0]); i++) 
    {
        if (ver_det_voltage <= version_table[i].ver_det_voltage_max) {
            hardware_inside_version[0] = version_table[i].version[0];
            hardware_inside_version[1] = version_table[i].version[1];
            hardware_inside_version[2] = version_table[i].version[2];
            break;
        }
    }
    // 如果没有找到对应的版本，则返回默认版本
    return hardware_inside_version;
}

/**
 * @brief  Get EOL build time inside version
 * @param  None
 * @return bootloader inside version array pointer
 */
char* Snf_Build_Time_Inside_Version_Get(void)
{
    for (uint8_t i = 0; i < 6; i++)
    {
        build_time_version_1[i] = SNF_UINT8_TO_BCD(build_time_version[i]);
    }
    return build_time_version_1;
}

/**
 * @brief  Get software version
 * @param  None
 * @return software version array pointer
 */
char* Snf_Software_Version_Get(void)
{
    return software_version;
}

/**
 * @brief  Get hardware version
 * @param  None
 * @return hardware version array pointer
 */
char* Snf_Hardware_Version_Get(void)
{
    return hardware_version;
}

/**
 * @brief  Get software baseline
 * @param  None
 * @return software baseline array pointer
 */
char* Snf_Software_Baseline_Get(void)
{
    return software_baseline;
}

/**
 * @brief  Get EOL hardware baseline
 * @param  None
 * @return hardware baseline array pointer
 */
char* Snf_Hardware_Baseline_Get(void)
{
    return hardware_baseline;
}

/**
 * @brief  Get supplier number
 * @param  None
 * @return supplier number array pointer
 */
char* Snf_Supplier_Number_Get(void)
{
    return supplier_number;
}

/**
 * @brief  Get manufacturing_date
 * @param  None
 * @return manufacturing_date array pointer
 */
char* Snf_Manufacturing_Date_Get(void)
{
    return manufacturing_date;
}

/**
 * @brief  Get diag database version
 * @param  None
 * @return diag database version array pointer
 */
char* Snf_Diag_Database_Version_Get(void)
{
    return diag_database_version;
}

/**
 * @brief  Get bootloader number
 * @param  None
 * @return bootloader number array pointer
 */
char* Snf_Bootloader_Number_Get(void)
{
    return bootloader_number;
}

/**
 * @brief  Get serial number
 * @param  None
 * @return serial number array pointer
 */
char* Snf_Serial_Number_Get(void)
{
    return serial_number;
}

/**
 * @brief  Get supplier hardware number
 * @param  None
 * @return supplier hardware number array pointer
 */
char* Snf_Supplier_Hardware_Number_Get(void)
{
    return supplier_hardware_number;
}

/**
 * @brief  Get supplier software number
 * @param  None
 * @return supplier software number array pointer
 */
char* Snf_Supplier_Software_Number_Get(void)
{
    return supplier_software_number;
}