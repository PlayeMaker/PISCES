#ifndef _POWER_TYPES_H_
#define _POWER_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
typedef enum
{
    POWER_BAT_STATUS_NORMAL,
    POWER_BAT_STATUS_LOW_VOLT,
    POWER_BAT_STATUS_OVER_VOLT,
} power_bat_status_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/


#ifdef __cplusplus
}
#endif

#endif /* _POWER_TYPES_H_ */