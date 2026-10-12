#ifndef _SECURITY_TYPES_H_
#define _SECURITY_TYPES_H_
#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
typedef enum
{
    SECURITY_STATUS_UNLOCKED,
    SECURITY_STATUS_LOCKED,
} security_status_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif
#endif  // _SECURITY_TYPES_H_
