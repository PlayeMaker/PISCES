#ifndef _VERSION_H_
#define _VERSION_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/
#include "Basic_Config.h"
/************************ Macro Definitions ************************/
/*EOL*/
//内部版本号，需要内部维护
#if defined(HIGH_CONFIGURATION) && defined(PISCES_MCM_D)
#define BOOTLOADER_INSIDE_VERSION      "010"
#define SOFTWARE_DRIVER_INSIDE_VERSION "101"
#define HARDWARE_INSIDE_VERSION        "110"
#elif defined(HIGH_CONFIGURATION) && defined(PISCES_MCM_P)
#define BOOTLOADER_INSIDE_VERSION      "010"
#define SOFTWARE_DRIVER_INSIDE_VERSION "102"
#define HARDWARE_INSIDE_VERSION        "110"
#elif defined(LOW_CONFIGURATION) && defined(PISCES_MCM_D)
#define BOOTLOADER_INSIDE_VERSION      "010"
#define SOFTWARE_DRIVER_INSIDE_VERSION "101"
#define HARDWARE_INSIDE_VERSION        "110"
#elif defined(LOW_CONFIGURATION) && defined(PISCES_MCM_P)
#define BOOTLOADER_INSIDE_VERSION      "010"
#define SOFTWARE_DRIVER_INSIDE_VERSION "102"
#define HARDWARE_INSIDE_VERSION        "110"
#endif

/*Basic*/
#if defined(HIGH_CONFIGURATION) && defined(PISCES_MCM_D)
#define SOFTWARE_VERSION         "P0440960 AA"
#define HARDWARE_VERSION         "P0441087 AA"
#define SOFTWARE_BASELINE        "  "
#define HARDWARE_BASELINE        "  "
#define BOOTLOADER_VERSION       "010"
#define SUPPLIER_SOFTWARE_NUMBER "010"
#define SUPPLIER_HARDWARE_NUMBER "010"
#elif defined(HIGH_CONFIGURATION) && defined(PISCES_MCM_P)
#define SOFTWARE_VERSION         "P0440961 AA"
#define HARDWARE_VERSION         "P0441094 AA"
#define SOFTWARE_BASELINE        "  "
#define HARDWARE_BASELINE        "  "
#define BOOTLOADER_VERSION       "010"
#define SUPPLIER_SOFTWARE_NUMBER "010"
#define SUPPLIER_HARDWARE_NUMBER "010"
#elif defined(LOW_CONFIGURATION) && defined(PISCES_MCM_D)
#define SOFTWARE_VERSION         "P0440954 AA"
#define HARDWARE_VERSION         "P0441079 AA"
#define SOFTWARE_BASELINE        "  "
#define HARDWARE_BASELINE        "  "
#define BOOTLOADER_VERSION       "010"
#define SUPPLIER_SOFTWARE_NUMBER "010"
#define SUPPLIER_HARDWARE_NUMBER "010"
#elif defined(LOW_CONFIGURATION) && defined(PISCES_MCM_P)
#define SOFTWARE_VERSION         "P0440959 AA"
#define HARDWARE_VERSION         "P0441079 AA"
#define SOFTWARE_BASELINE        "  "
#define HARDWARE_BASELINE        "  "
#define BOOTLOADER_VERSION       "010"
#define SUPPLIER_SOFTWARE_NUMBER "010"
#define SUPPLIER_HARDWARE_NUMBER "010"
#endif

#define SUPPLIER_NUMBER          "00000000"
#define MANUFACTURING_DATE       "000"
#define DIAG_DATABASE_VERSION    "000"
#define SERIAL_NUMBER            "0000000000000000"
#define SUPPLIER_SOFTWARE_NUMBER "101"
#define SUPPLIER_HARDWARE_NUMBER "110"
/************************ Type Definitions ************************/

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

#ifdef __cplusplus
}
#endif

#endif /* _VERSION_H_ */