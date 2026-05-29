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
#define BOOTLOADER_INSIDE_VERSION         "100"
#ifdef PISCES_MCM_D
#define SOFTWARE_DRIVER_INSIDE_VERSION    "101"
#endif
#ifdef PISCES_MCM_P
#define SOFTWARE_PASSENGER_INSIDE_VERSION "102"
#endif
#define HARDWARE_INSIDE_VERSION           "110"
/*Basic*/
#define SOFTWARE_VERSION                  "00000000000"
#define HARDWARE_VERSION                  "00000000000"
#define SOFTWARE_BASELINE                 "00"
#define HARDWARE_BASELINE                 "00"
#define SUPPLIER_NUMBER                   "00000000"
#define MANUFACTURING_DATE                "000"
#define DIAG_DATABASE_VERSION             "000"
#define BOOTLOADER_VERSION                "100"
#define SERIAL_NUMBER                     "0000000000000000"
#define SUPPLIER_SOFTWARE_NUMBER          "101"
#define SUPPLIER_HARDWARE_NUMBER          "110"
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