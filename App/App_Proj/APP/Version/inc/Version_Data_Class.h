#ifndef _VERSION_DATA_CLASS_H_
#define _VERSION_DATA_CLASS_H_

#include <stdbool.h>
#include "Platform_Types.h"

typedef uint8* (*version_get_fn)(void);
typedef bool (*version_set_fn)(uint8* data);

typedef struct
{
    version_get_fn get;  //数据读取回调
    version_set_fn set;  //数据写入回调（只读项为 _Snf_Version_Data_Set_Null）
    uint8          len;  //数据长度（字节）
} version_data_entry_t;

#define VERSION_DATA_PASS_1

#endif

#ifdef VERSION_DATA_PASS_4
#undef VERSION_DATA_PASS_4
#undef FCT_VERSION_DATA
#undef BEGIN_VERSION_DATA
#undef END_VERSION_DATA
#define BEGIN_VERSION_DATA
#define FCT_VERSION_DATA(a, b, c, d)
#define END_VERSION_DATA
#endif

#ifdef VERSION_DATA_PASS_3
#undef VERSION_DATA_PASS_3
#define VERSION_DATA_PASS_4
#undef FCT_VERSION_DATA
#undef BEGIN_VERSION_DATA
#undef END_VERSION_DATA
#define BEGIN_VERSION_DATA           static const version_data_entry_t version_data_table[VERSION_ID_MAX] = {
#define FCT_VERSION_DATA(a, b, c, d) { b, c, (uint8)d },
#define END_VERSION_DATA \
    }                    \
    ;
#endif

#ifdef VERSION_DATA_PASS_2
#undef VERSION_DATA_PASS_2
#define VERSION_DATA_PASS_3
#undef FCT_VERSION_DATA
#undef BEGIN_VERSION_DATA
#undef END_VERSION_DATA
#define BEGIN_VERSION_DATA
#define FCT_VERSION_DATA(a, b, c, d) \
    static uint8* b(void);           \
    static bool   c(uint8* data);
#define END_VERSION_DATA
#endif

#ifdef VERSION_DATA_PASS_1
#undef VERSION_DATA_PASS_1
#define VERSION_DATA_PASS_2
#undef FCT_VERSION_DATA
#undef BEGIN_VERSION_DATA
#undef END_VERSION_DATA
#define BEGIN_VERSION_DATA \
    typedef enum           \
    {
#define FCT_VERSION_DATA(a, b, c, d) a,
#define END_VERSION_DATA \
    VERSION_ID_MAX       \
    }                    \
    version_data_id_e;
#endif
