#ifndef _VERSION_H_
#define _VERSION_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdint.h>
#include "Basic_Config.h"
/************************ Macro Definitions ************************/
/*EOL*/
//内部版本号，需要内部维护
#define HARDWARE_INSIDE_VERSION   "100"

// 构建时间
//  ((((2 * 10) + 0) * 10 + 2) * 10) + 4;  先加再乘。10进制，加上1位，就*10 。
#define BUILD_YEAR_H (((__DATE__[7] - '0')) * 10 + (__DATE__[8] - '0'))
#define BUILD_YEAR_L (((__DATE__[9] - '0')) * 10 + (__DATE__[10] - '0'))
#define BUILD_YEAR   ((BUILD_YEAR_H * 100) + BUILD_YEAR_L)

// DATE得到的月数，__DATA__[0-2]表示月的缩写,判断月的缩写的第3位，如果第3位相同的，则判断第1位或者第0位
//[1]Jan [2]Feb  [3]Mar  [4]Apr  [5]May  [6]Jun  [7]Jul  [8]Aug  [9]Sept   [10]Oct  [11]Nov  [12]Dec
#define BUILD_MONTH                                      \
    (__DATE__[2] == 'n'   ? (__DATE__[1] == 'a' ? 1 : 6) \
     : __DATE__[2] == 'b' ? 2                            \
     : __DATE__[2] == 'r' ? (__DATE__[0] == 'M' ? 3 : 4) \
     : __DATE__[2] == 'y' ? 5                            \
     : __DATE__[2] == 'l' ? 7                            \
     : __DATE__[2] == 'g' ? 8                            \
     : __DATE__[2] == 'p' ? 9                            \
     : __DATE__[2] == 't' ? 10                           \
     : __DATE__[2] == 'v' ? 11                           \
                          : 12)

// 求取日期：__DATE__ [4]十位，__DATE__ [5]个位。十位为空，则直接用__DATE__ [5]-'0'表示个位。否则十位*10 +
// 个位。
#define BUILD_DAY ((__DATE__[4] == ' ' ? 0 : __DATE__[4] - '0') * 10 + (__DATE__[5] - '0'))

#define BUILD_HOUR   ((__TIME__[0] - '0') * 10 + (__TIME__[1] - '0'))
#define BUILD_MINUTE ((__TIME__[3] - '0') * 10 + (__TIME__[4] - '0'))
#define BUILD_SECOND ((__TIME__[6] - '0') * 10 + (__TIME__[7] - '0'))

/*Basic*/
#if defined(HIGH_CONFIGURATION) && defined(PISCES_MCM_D)
#define SOFTWARE_INSIDE_VERSION  "101"
#define BOOTLOADER_VERSION       "101"
#define SOFTWARE_VERSION         "P0440960 AA"
#define HARDWARE_VERSION         "P0441087 AA"
#define SOFTWARE_BASELINE        "  "
#define HARDWARE_BASELINE        "  "
#define SUPPLIER_SOFTWARE_NUMBER "010"
#define SUPPLIER_HARDWARE_NUMBER "010"
#elif defined(HIGH_CONFIGURATION) && defined(PISCES_MCM_P)
#define SOFTWARE_INSIDE_VERSION  "102"
#define BOOTLOADER_VERSION       "102"
#define SOFTWARE_VERSION         "P0440961 AA"
#define HARDWARE_VERSION         "P0441094 AA"
#define SOFTWARE_BASELINE        "  "
#define HARDWARE_BASELINE        "  "
#define SUPPLIER_SOFTWARE_NUMBER "010"
#define SUPPLIER_HARDWARE_NUMBER "010"
#elif defined(LOW_CONFIGURATION) && defined(PISCES_MCM_D)
#define SOFTWARE_INSIDE_VERSION  "103"
#define BOOTLOADER_VERSION       "101"
#define SOFTWARE_VERSION         "P0440954 AA"
#define HARDWARE_VERSION         "P0441079 AA"
#define SOFTWARE_BASELINE        "  "
#define HARDWARE_BASELINE        "  "
#define SUPPLIER_SOFTWARE_NUMBER "010"
#define SUPPLIER_HARDWARE_NUMBER "010"
#elif defined(LOW_CONFIGURATION) && defined(PISCES_MCM_P)
#define SOFTWARE_INSIDE_VERSION  "104"
#define BOOTLOADER_VERSION       "102"
#define SOFTWARE_VERSION         "P0440959 AA"
#define HARDWARE_VERSION         "P0441079 AA"
#define SOFTWARE_BASELINE        "  "
#define HARDWARE_BASELINE        "  "
#define SUPPLIER_SOFTWARE_NUMBER "010"
#define SUPPLIER_HARDWARE_NUMBER "010"
#endif

#define SUPPLIER_NUMBER          "00000000"
#define MANUFACTURING_DATE       "000"
#define DIAG_DATABASE_VERSION    {0x03, 0x01, 0x01}
#define SERIAL_NUMBER            "0123456789ABCDEF"
/************************ Type Definitions ************************/
// 硬件版本映射表
typedef struct {
    uint32_t ver_det_voltage_max;
    uint8_t version[3];
} version_map_t;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
char* Snf_Bootloader_Inside_Version_Get(void);
char* Snf_Software_Inside_Version_Get(void);
char* Snf_Hardware_Inside_Version_Get(void);
char* Snf_Software_Version_Get(void);
char* Snf_Hardware_Version_Get(void);
char* Snf_Software_Baseline_Get(void);
char* Snf_Hardware_Baseline_Get(void);
char* Snf_Supplier_Number_Get(void);
char* Snf_Manufacturing_Date_Get(void);
char* Snf_Diag_Database_Version_Get(void);
char* Snf_Bootloader_Number_Get(void);
char* Snf_Serial_Number_Get(void);
char* Snf_Supplier_Hardware_Number_Get(void);
char* Snf_Supplier_Software_Number_Get(void);
char* Snf_Build_Time_Inside_Version_Get(void);

#ifdef __cplusplus
}
#endif

#endif /* _VERSION_H_ */
