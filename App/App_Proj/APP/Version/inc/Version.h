#ifndef _VERSION_H_
#define _VERSION_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include <stdbool.h>
#include "Basic_Config.h"
#include "Nvm.h"
#include "Version_Data_Class.h"
#include "Version_Data_Def.h"
/************************ Macro Definitions ************************/
/*Reprogramming Attempt Counter F010*/
#define DF_REPROGRAMMING_ATTEMPT_COUNT_ADDR (0x0200FA10UL)
#define DF_REPROGRAMMING_ATTEMPT_COUNT_SIZE (4UL)

/*Hardware Number 0xF110 */
#define DF_HARDWARE_NUMBER_ADDR (0x0200F800UL)
#define DF_HARDWARE_NUMBER_SIZE (11UL)

/*Hardware Baseline 0xF111 */
#define DF_HARDWARE_BASELINE_ADDR (0x0200F80CUL)
#define DF_HARDWARE_BASELINE_SIZE (2UL)

/*Bootloader Version Number 0xF150 */
#define DF_BOOTLOADER_NUMBER_ADDR (0x0200F810UL)
#define DF_BOOTLOADER_NUMBER_SIZE (3UL)

/*Fingerprint F15B */
#define DF_FINGER_PRINT_ADDR (0x0200FA00UL)
#define DF_FINGER_PRINT_SIZE (12UL)

/* 各版本数据长度（字节）。DFlash 持久化的数据直接复用 DF_*_SIZE，以下为编译期数据的长度 */
#define VERSION_SOFTWARE_INSIDE_LEN    (3U)   //软件内部版本号
#define VERSION_HARDWARE_INSIDE_LEN    (3U)   //硬件内部版本号（与版本表version字段同源）
#define VERSION_BUILD_TIME_LEN         (6U)   //构建时间（BCD：年月日时分秒）
#define VERSION_BUILD_GIT_HASH_LEN     (8U)   //构建 Git 哈希值
#define VERSION_SOFTWARE_LEN           (11U)  //客户软件版本号
#define VERSION_SOFTWARE_BASELINE_LEN  (2U)   //客户软件基线号
#define VERSION_SUPPLIER_NUMBER_LEN    (8U)   //供应商编号
#define VERSION_DIAG_DATABASE_LEN      (3U)   //诊断数据库版本
#define VERSION_SERIAL_NUMBER_LEN      (16U)  //序列号
#define VERSION_MANUFACTURING_DATE_LEN (3U)   //生产日期
#define VERSION_BAT_VOLTAGE_LEN        (2U)   //电源输入电压

// 构建时间
//  ((((2 * 10) + 0) * 10 + 2) * 10) + 4;  先加再乘。10进制，加上1位，就*10 。
// #define BUILD_YEAR_H (((__DATE__[7] - '0')) * 10 + (__DATE__[8] - '0'))
#define BUILD_YEAR_L (((__DATE__[9] - '0')) * 10 + (__DATE__[10] - '0'))
// #define BUILD_YEAR   ((BUILD_YEAR_H * 100) + BUILD_YEAR_L)

// DATE得到的月数，__DATE__[0-2]表示月的缩写,判断月的缩写的第3位，如果第3位相同的，则判断第1位或者第0位
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

#define BUILD_HOUR   0
#define BUILD_MINUTE 0
#define BUILD_SECOND 0

/*Basic*/
#if defined(HIGH_CONFIGURATION) && defined(PISCES_MCM_D)
#define SOFTWARE_INSIDE_VERSION "161"
#define SOFTWARE_VERSION        "P0440960 AF"
#define SOFTWARE_BASELINE       "  "
#elif defined(HIGH_CONFIGURATION) && defined(PISCES_MCM_P)
#define SOFTWARE_INSIDE_VERSION "162"
#define SOFTWARE_VERSION        "P0440961 AF"
#define SOFTWARE_BASELINE       "  "
#elif defined(LOW_CONFIGURATION) && defined(PISCES_MCM_D)
#define SOFTWARE_INSIDE_VERSION "163"
#define SOFTWARE_VERSION        "P0440954 AF"
#define SOFTWARE_BASELINE       "  "
#elif defined(LOW_CONFIGURATION) && defined(PISCES_MCM_P)
#define SOFTWARE_INSIDE_VERSION "164"
#define SOFTWARE_VERSION        "P0440959 AF"
#define SOFTWARE_BASELINE       "  "
#else
#error "Please define the configuration"
#endif

//供应商编号（默认"V46014"，不足 VERSION_SUPPLIER_NUMBER_LEN 字节时右侧补0）
#define SUPPLIER_NUMBER "V46014"

#define DIAG_DATABASE_VERSION { 0x03, 0x01, 0x01 }
/************************ Type Definitions ************************/
// 硬件版本映射表
typedef struct
{
    uint32 ver_det_voltage_max;
    uint8  version[VERSION_HARDWARE_INSIDE_LEN + 1];                  // 硬件内部版本号
    uint8  hardware_part_version[DF_HARDWARE_NUMBER_SIZE + 1];        // 客户硬件号
    uint8  hardware_baseline_version[DF_HARDWARE_BASELINE_SIZE + 1];  // 客户硬件基线号
} version_map_t;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
uint8* Snf_Version_Data_Get(version_data_id_e id, uint8* length);
bool   Snf_Version_Data_Set(version_data_id_e id, uint8* data);
void   Snf_Version_Task_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* _VERSION_H_ */
