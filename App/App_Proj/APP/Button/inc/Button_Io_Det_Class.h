#ifndef _BUTTON_IO_DET_CLASS_H_
#define _BUTTON_IO_DET_CLASS_H_

#include <stdint.h>
#include "Rte_Gpio.h"

typedef rte_gpio_level_e (*button_io_check_fct)(void);
typedef void (*button_io_event_fct)(void);

#define BUTTON_IO_DET_PASS_1

#endif

#ifdef      BUTTON_IO_DET_PASS_6
#undef      BUTTON_IO_DET_PASS_6
#undef      FCT_BUTTON_IO_DET
#undef      BEGIN_BUTTON_IO_DET
#undef      END_BUTTON_IO_DET
#define     BEGIN_BUTTON_IO_DET
#define     FCT_BUTTON_IO_DET(a,b,c,d,e,f,g,h,i,j)
#define     END_BUTTON_IO_DET
#endif

#ifdef      BUTTON_IO_DET_PASS_5
#undef      BUTTON_IO_DET_PASS_5
#define     BUTTON_IO_DET_PASS_6
#undef      FCT_BUTTON_IO_DET
#undef      BEGIN_BUTTON_IO_DET
#undef      END_BUTTON_IO_DET
#define     BEGIN_BUTTON_IO_DET                     const uint16_t button_io_debounce_tab[BUTTON_IO_INPUTS*4] = {
#define     FCT_BUTTON_IO_DET(a,b,c,d,e,f,g,h,i,j)          c,e,g,i,
#define     END_BUTTON_IO_DET                       };
#endif

#ifdef      BUTTON_IO_DET_PASS_4
#undef      BUTTON_IO_DET_PASS_4
#define     BUTTON_IO_DET_PASS_5
#undef      FCT_BUTTON_IO_DET
#undef      BEGIN_BUTTON_IO_DET
#undef      END_BUTTON_IO_DET
#define     BEGIN_BUTTON_IO_DET                     const button_io_event_fct button_io_event_fun_tab[BUTTON_IO_INPUTS*4] = {
#define     FCT_BUTTON_IO_DET(a,b,c,d,e,f,g,h,i,j)          d,f,h,j,
#define     END_BUTTON_IO_DET                       };
#endif

#ifdef      BUTTON_IO_DET_PASS_3
#undef      BUTTON_IO_DET_PASS_3
#define     BUTTON_IO_DET_PASS_4
#undef      FCT_BUTTON_IO_DET
#undef      BEGIN_BUTTON_IO_DET
#undef      END_BUTTON_IO_DET
#define     BEGIN_BUTTON_IO_DET                     const button_io_check_fct button_io_check_fun_tab[BUTTON_IO_INPUTS] = {
#define     FCT_BUTTON_IO_DET(a,b,c,d,e,f,g,h,i,j)          b,
#define     END_BUTTON_IO_DET                       };
#endif

#ifdef      BUTTON_IO_DET_PASS_2
#undef      BUTTON_IO_DET_PASS_2
#define     BUTTON_IO_DET_PASS_3
#undef      FCT_BUTTON_IO_DET
#undef      BEGIN_BUTTON_IO_DET
#undef      END_BUTTON_IO_DET
#define     BEGIN_BUTTON_IO_DET
#define     FCT_BUTTON_IO_DET(a,b,c,d,e,f,g,h,i,j)     uint8_t b(void);void d(void);void f(void);void h(void);void j(void);
#define     END_BUTTON_IO_DET
#endif

#ifdef      BUTTON_IO_DET_PASS_1
#undef      BUTTON_IO_DET_PASS_1
#define     BUTTON_IO_DET_PASS_2
#undef      FCT_BUTTON_IO_DET
#undef      BEGIN_BUTTON_IO_DET
#undef      END_BUTTON_IO_DET
#define     BEGIN_BUTTON_IO_DET                     enum BUTTON_IO_DET_INPUT {
#define     FCT_BUTTON_IO_DET(a,b,c,d,e,f,g,h,i,j)          a,
#define     END_BUTTON_IO_DET                       BUTTON_IO_INPUTS};
#endif
