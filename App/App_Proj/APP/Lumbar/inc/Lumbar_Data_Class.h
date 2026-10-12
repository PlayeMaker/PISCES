#ifndef _LUMBAR_DATA_CLASS_H_
#define _LUMBAR_DATA_CLASS_H_

#define LUMBAR_DATA_PASS_1

#endif

#ifdef LUMBAR_DATA_PASS_4
#undef LUMBAR_DATA_PASS_4
#undef FCT_LUMBAR_DATA
#undef BEGIN_LUMBAR_DATA
#undef END_LUMBAR_DATA
#define BEGIN_LUMBAR_DATA
#define FCT_LUMBAR_DATA(a, b, c, d, e)
#define END_LUMBAR_DATA
#endif

#ifdef LUMBAR_DATA_PASS_3
#undef LUMBAR_DATA_PASS_3
#define LUMBAR_DATA_PASS_4
#undef FCT_LUMBAR_DATA
#undef BEGIN_LUMBAR_DATA
#undef END_LUMBAR_DATA
#define BEGIN_LUMBAR_DATA static lumbar_config_t lumbar_config[LUMBAR_POSITION_MAX] = {
#define FCT_LUMBAR_DATA(a, b, c, d, e)                      \
    [a] = { .position               = a,                    \
            .mode                   = LUMBAR_MODE_RESERVED, \
            .pwm_channel_fornt      = b,                    \
            .pwm_channel_rear       = c,                    \
            .read_net_cmd_callback  = d,                    \
            .write_net_cmd_callback = e },
#define END_LUMBAR_DATA \
    }                   \
    ;
#endif

#ifdef LUMBAR_DATA_PASS_2
#undef LUMBAR_DATA_PASS_2
#define LUMBAR_DATA_PASS_3
#undef FCT_LUMBAR_DATA
#undef BEGIN_LUMBAR_DATA
#undef END_LUMBAR_DATA
#define BEGIN_LUMBAR_DATA
#define FCT_LUMBAR_DATA(a, b, c, d, e)  \
    static uint8_t d(uint8_t position); \
    static void    e(uint8_t position);
#define END_LUMBAR_DATA
#endif

#ifdef LUMBAR_DATA_PASS_1
#undef LUMBAR_DATA_PASS_1
#define LUMBAR_DATA_PASS_2
#undef FCT_LUMBAR_DATA
#undef BEGIN_LUMBAR_DATA
#undef END_LUMBAR_DATA
#define BEGIN_LUMBAR_DATA \
    typedef enum          \
    {
#define FCT_LUMBAR_DATA(a, b, c, d, e) a,
#define END_LUMBAR_DATA \
    LUMBAR_POSITION_MAX \
    }                   \
    lumbar_position_e;
#endif
