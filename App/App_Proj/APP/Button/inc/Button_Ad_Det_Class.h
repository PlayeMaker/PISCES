#ifndef _BUTTON_AD_DET_CLASS_H_
#define _BUTTON_AD_DET_CLASS_H_

#include <stdint.h>

typedef uint16_t (*button_ad_check_fct)(void);
typedef void (*button_ad_event_fct)(void);

#define BUTTON_AD_DET_PASS_1

#endif
#ifdef      BUTTON_AD_DET_PASS_7
#undef      BUTTON_AD_DET_PASS_7
#undef      FCT_BUTTON_AD_DET
#undef      BEGIN_BUTTON_AD_DET
#undef      END_BUTTON_AD_DET
#define     BEGIN_BUTTON_AD_DET
#define     FCT_BUTTON_AD_DET(a,b,c,d,e,f,g,h,i,j,k,l)
#define     END_BUTTON_AD_DET
#endif

#ifdef      BUTTON_AD_DET_PASS_6
#undef      BUTTON_AD_DET_PASS_6
#define     BUTTON_AD_DET_PASS_7
#undef      FCT_BUTTON_AD_DET
#undef      BEGIN_BUTTON_AD_DET
#undef      END_BUTTON_AD_DET
#define     BEGIN_BUTTON_AD_DET                             const uint16_t button_ad_vild[BUTTON_AD_INPUTS*2] = {
#define     FCT_BUTTON_AD_DET(a,b,c,d,e,f,g,h,i,j,k,l)          b,c,
#define     END_BUTTON_AD_DET                               };
#endif

#ifdef      BUTTON_AD_DET_PASS_5
#undef      BUTTON_AD_DET_PASS_5
#define     BUTTON_AD_DET_PASS_6
#undef      FCT_BUTTON_AD_DET
#undef      BEGIN_BUTTON_AD_DET
#undef      END_BUTTON_AD_DET
#define     BEGIN_BUTTON_AD_DET                             const uint16_t button_ad_debounce_tab[BUTTON_AD_INPUTS*4] = {
#define     FCT_BUTTON_AD_DET(a,b,c,d,e,f,g,h,i,j,k,l)          e,g,i,k,
#define     END_BUTTON_AD_DET                               };
#endif

#ifdef      BUTTON_AD_DET_PASS_4
#undef      BUTTON_AD_DET_PASS_4
#define     BUTTON_AD_DET_PASS_5
#undef      FCT_BUTTON_AD_DET
#undef      BEGIN_BUTTON_AD_DET
#undef      END_BUTTON_AD_DET
#define     BEGIN_BUTTON_AD_DET                             const button_ad_event_fct button_ad_event_fun_tab[BUTTON_AD_INPUTS*4] = {
#define     FCT_BUTTON_AD_DET(a,b,c,d,e,f,g,h,i,j,k,l)          f,h,j,l,
#define     END_BUTTON_AD_DET                               };
#endif

#ifdef      BUTTON_AD_DET_PASS_3
#undef      BUTTON_AD_DET_PASS_3
#define     BUTTON_AD_DET_PASS_4
#undef      FCT_BUTTON_AD_DET
#undef      BEGIN_BUTTON_AD_DET
#undef      END_BUTTON_AD_DET
#define     BEGIN_BUTTON_AD_DET                             const button_ad_check_fct button_ad_check_fun_tab[BUTTON_AD_INPUTS] = {
#define     FCT_BUTTON_AD_DET(a,b,c,d,e,f,g,h,i,j,k,l)          d,
#define     END_BUTTON_AD_DET                               };
#endif

#ifdef      BUTTON_AD_DET_PASS_2
#undef      BUTTON_AD_DET_PASS_2
#define     BUTTON_AD_DET_PASS_3
#undef      FCT_BUTTON_AD_DET
#undef      BEGIN_BUTTON_AD_DET
#undef      END_BUTTON_AD_DET
#define     BEGIN_BUTTON_AD_DET
#define     FCT_BUTTON_AD_DET(a,b,c,d,e,f,g,h,i,j,k,l)     uint16_t d(void);void f(void);void h(void);void j(void);void l(void);
#define     END_BUTTON_AD_DET
#endif

#ifdef      BUTTON_AD_DET_PASS_1
#undef      BUTTON_AD_DET_PASS_1
#define     BUTTON_AD_DET_PASS_2
#undef      FCT_BUTTON_AD_DET
#undef      BEGIN_BUTTON_AD_DET
#undef      END_BUTTON_AD_DET
#define     BEGIN_BUTTON_AD_DET                             enum BUTTON_AD_DET_INPUT {
#define     FCT_BUTTON_AD_DET(a,b,c,d,e,f,g,h,i,j,k,l)          a,
#define     END_BUTTON_AD_DET                               BUTTON_AD_INPUTS};
#endif
