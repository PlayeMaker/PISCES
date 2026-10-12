#ifndef _MASSAGE_MODE_CLASS_H_
#define _MASSAGE_MODE_CLASS_H_

#include "Massage.h"

/**
 * @brief 按摩手法处理函数指针类型
 */
typedef void (*massage_mode_handler_t)(massage_config_t* massage_config);

/**
 * @brief 手法分发表项：手法 + 支持区域掩码 + 处理函数
 */
typedef struct
{
    massage_mode_e         mode;
    uint8                  area_mask;
    massage_mode_handler_t handler;
} massage_mode_dispatch_t;

#define MASSAGE_MODE_PASS_1

#endif

#ifdef MASSAGE_MODE_PASS_3
#undef MASSAGE_MODE_PASS_3
#undef FCT_MASSAGE_MODE
#undef BEGIN_MASSAGE_MODE
#undef END_MASSAGE_MODE
#define BEGIN_MASSAGE_MODE
#define FCT_MASSAGE_MODE(a, b, c)
#define END_MASSAGE_MODE
#endif

#ifdef MASSAGE_MODE_PASS_2
#undef MASSAGE_MODE_PASS_2
#define MASSAGE_MODE_PASS_3
#undef FCT_MASSAGE_MODE
#undef BEGIN_MASSAGE_MODE
#undef END_MASSAGE_MODE
#define BEGIN_MASSAGE_MODE        static const massage_mode_dispatch_t mode_dispatch_table[] = {
#define FCT_MASSAGE_MODE(a, b, c) { a, b, c },
#define END_MASSAGE_MODE \
    }                    \
    ;
#endif

#ifdef MASSAGE_MODE_PASS_1
#undef MASSAGE_MODE_PASS_1
#define MASSAGE_MODE_PASS_2
#undef FCT_MASSAGE_MODE
#undef BEGIN_MASSAGE_MODE
#undef END_MASSAGE_MODE
#define BEGIN_MASSAGE_MODE
#define FCT_MASSAGE_MODE(a, b, c) void c(massage_config_t* massage_config);
#define END_MASSAGE_MODE
#endif
