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

typedef enum
{
    POWER_SLEEP_STATE_AWAKE = 0U,
    POWER_SLEEP_STATE_SLEEPING,
} power_sleep_state_e;

typedef enum
{
    POWER_LOAD_STATUS_NORMAL,
    POWER_LOAD_STATUS_ABNORMAL,
} power_load_status_e;

typedef enum
{
    POWER_LOAD_CHANNEL_PUMP = 0U,
    POWER_LOAD_CHANNEL_VALVE,
    POWER_LOAD_CHANNEL_MAX,
} power_load_channel_e;

typedef enum
{
    POWER_LOAD_PHASE_SELECT = 0U,
    POWER_LOAD_PHASE_WAIT_SETTLE,
    POWER_LOAD_PHASE_SAMPLING,
    POWER_LOAD_PHASE_CHECK,
} power_load_sample_phase_e;
/************************ External Variables ************************/

/************************ Function Declarations ************************/


#ifdef __cplusplus
}
#endif

#endif /* _POWER_TYPES_H_ */