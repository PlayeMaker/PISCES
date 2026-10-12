#ifndef _VALVE_RAMP_CLASS_H_
#define _VALVE_RAMP_CLASS_H_

#include <stdint.h>
#include "Valve.h"

#define VALVE_RAMP_PASS_1

#endif

#ifdef      VALVE_RAMP_PASS_2
#undef      VALVE_RAMP_PASS_2
#undef      BEGIN_VALVE_RAMP_UP_STEP
#undef      FCT_VALVE_RAMP_STEP
#undef      END_VALVE_RAMP_UP_STEP
#undef      BEGIN_VALVE_RAMP_DOWN_STEP
#undef      END_VALVE_RAMP_DOWN_STEP
#define     BEGIN_VALVE_RAMP_UP_STEP
#define     FCT_VALVE_RAMP_STEP(a,b)
#define     END_VALVE_RAMP_UP_STEP
#define     BEGIN_VALVE_RAMP_DOWN_STEP
#define     END_VALVE_RAMP_DOWN_STEP
#endif

#ifdef      VALVE_RAMP_PASS_1
#undef      VALVE_RAMP_PASS_1
#define     VALVE_RAMP_PASS_2
#undef      BEGIN_VALVE_RAMP_UP_STEP
#undef      FCT_VALVE_RAMP_STEP
#undef      END_VALVE_RAMP_UP_STEP
#undef      BEGIN_VALVE_RAMP_DOWN_STEP
#undef      END_VALVE_RAMP_DOWN_STEP
#define     BEGIN_VALVE_RAMP_UP_STEP    static const valve_ramp_step_t valve_ramp_up_steps[] = {
#define     FCT_VALVE_RAMP_STEP(a,b)    { a, b },
#define     END_VALVE_RAMP_UP_STEP      };
#define     BEGIN_VALVE_RAMP_DOWN_STEP  static const valve_ramp_step_t valve_ramp_down_steps[] = {
#define     END_VALVE_RAMP_DOWN_STEP    };
#endif
