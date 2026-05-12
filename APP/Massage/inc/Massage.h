#ifndef _MASSAGE_H_
#define _MASSAGE_H_

#ifdef __cplusplus
extern "C"
{
#endif

/************************ Include Files ************************/

/************************ Macro Definitions ************************/

/************************ Type Definitions ************************/
/**
* @brief 按摩模式枚举
*/
typedef enum
{
    MASSAGE_MODE_NONE,      //无按摩模式
    MASSAGE_MODE_KNEADING,  //揉捏模式
    MASSAGE_MODE_PRESSING,  //点按模式
    MASSAGE_MODE_TAPPING,   //叩击模式

    MASSAGE_MODE_MAX,
} massage_mode_e;

/**
* @brief 按摩强度枚举
*/
typedef enum
{
    MASSAGE_INTENSITY_HIGH,    //高强度
    MASSAGE_INTENSITY_LOW,     //低强度
} massage_intensity_e;

/**
* @brief 按摩气袋区域枚举
*/
typedef enum
{
    MASSAGE_BAG_ZONE_BACK,            //背部气袋
    MASSAGE_BAG_ZONE_BACK_SUPPORT,    //背部支撑气袋
    MASSAGE_BAG_ZONE_LUMBAR,          //腰部气袋
    MASSAGE_BAG_ZONE_LUMBAR_SUPPORT,  //腰部支撑气袋
    MASSAGE_BAG_ZONE_SHOULDER,        //肩部气袋
    MASSAGE_BAG_ZONE_HIP,             //臀部气袋
    MASSAGE_BAG_ZONE_LEG,             //腿部气袋
} massage_bag_zone_e;

/**
* @brief 按摩气袋动作枚举
*/
typedef enum
{
    MASSAGE_BAG_ACTION_PRECHARGE,  //气袋预充
    MASSAGE_BAG_ACTION_CYCLE,      //气袋循环
} massage_bag_action_e;

/**
* @brief 按摩配置结构体
*/
typedef struct
{
    massage_mode_e       mode;
    massage_bag_zone_e   zone;
    massage_bag_action_e action;
} massage_config_t;
/************************ External Variables ************************/

/************************ Function Declarations ************************/
void Snf_Massage_Task_Init(void);
void Snf_Massage_Task(void);

#ifdef __cplusplus
}
#endif

#endif /* _MASSAGE_H_ */