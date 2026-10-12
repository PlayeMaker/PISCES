#ifndef _POWER_CLASS_H_
#define _POWER_CLASS_H_

/************************ Include Files ************************/
#include <stdint.h>

#include "Power_Types.h"

/************************ Type Definitions ************************/
typedef void (*power_detection_callback_f)(void);

typedef struct
{
    uint16_t                   voltage_min;
    uint16_t                   voltage_max;
    power_bat_status_e         status;
    power_detection_callback_f detection_callback;
} power_bat_detection_t;

typedef struct
{
    uint8_t                    channel;
    uint16_t                   current_min;
    uint16_t                   current_max;
    power_load_status_e        status;
    uint32_t                   confirm_time_ms;
    power_detection_callback_f detection_callback;
} power_load_detection_t;

typedef struct
{
    power_load_status_e status;
    uint32_t            fault_start_tick;
    uint32_t            phase_start_tick;
    uint32_t            sample_sum;
    uint16_t            sample_count;
    uint16_t            sample_avg;
    uint16_t            sample_vol;
    uint16_t            sample_ics;
} power_load_channel_context_t;

/************************ Battery Detection Expand ************************/
#define BEGIN_POWER_BAT_DEF                     static const power_bat_detection_t s_power_bat_detection_table[] = {
#define FCT_POWER_BAT_DEF(min, max, state, cb) { min, max, state, cb },
#define END_POWER_BAT_DEF                       };                                                      \
                                                static const uint8_t s_power_bat_detection_table_size = \
                                                        sizeof(s_power_bat_detection_table) / sizeof(s_power_bat_detection_table[0]);

/************************ Load Detection Expand ************************/
#define BEGIN_POWER_LOAD_DEF                                      static const power_load_detection_t s_power_load_detection_table[] = {
#define FCT_POWER_LOAD_DEF(channel, min, max, state, confirm, cb) { channel, min, max, state, confirm, cb },
#define END_POWER_LOAD_DEF                                        };                                                       \
                                                                  static const uint8_t s_power_load_detection_table_size = \
                                                                          sizeof(s_power_load_detection_table) / sizeof(s_power_load_detection_table[0]);

#endif /* _POWER_CLASS_H_ */
