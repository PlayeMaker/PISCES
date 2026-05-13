#ifndef _VALVE_TYPES_H_
#define _VALVE_TYPES_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
typedef enum
{
    POWER_VALVE_STATE_RAMP_UP,
    POWER_VALVE_STATE_RAMP_DOWN,
} valve_state_e;

/************************ External Variables ************************/

/************************ Function Declarations ************************/

#ifdef __cplusplus
}
#endif

#endif /* _VALVE_TYPES_H_ */