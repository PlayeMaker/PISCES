BEGIN_MASSAGE_MODE
//        (mode,                                       area_mask,                 handler)
FCT_MASSAGE_MODE(MASSAGE_MODE_KNEADING_CLOCKWISE,              MASSAGE_AREA_MASK_5_6_7_8,  Snf_Massage_Knead_Handle)               //揉捏-顺时针
FCT_MASSAGE_MODE(MASSAGE_MODE_KNEADING_ANTICLOCKWISE,          MASSAGE_AREA_MASK_5_6_7_8,  Snf_Massage_Knead_Handle)               //揉捏-逆时针
FCT_MASSAGE_MODE(MASSAGE_MODE_3_POINT_PRESSING,                MASSAGE_AREA_MASK_5_6,      Snf_Massage_3_Point_Press_Handle)       //三点按压
FCT_MASSAGE_MODE(MASSAGE_MODE_3_SUPPORT_POINT_PRESSING,        MASSAGE_AREA_MASK_7_8,      Snf_Massage_3_Point_Press_Handle)       //三点支撑按压
FCT_MASSAGE_MODE(MASSAGE_MODE_RAP_CLOCKWISE,                   MASSAGE_AREA_MASK_5_6_7_8,  Snf_Massage_Rap_Knead)                  //叩击-顺时针（揉捏气袋）
FCT_MASSAGE_MODE(MASSAGE_MODE_RAP_CLOCKWISE,                   MASSAGE_AREA_MASK_9_10,     Snf_Massage_Shoulder_Rap)               //叩击-顺时针（肩部气袋）
FCT_MASSAGE_MODE(MASSAGE_MODE_RAP_ANTICLOCKWISE,               MASSAGE_AREA_MASK_5_6_7_8,  Snf_Massage_Rap_Knead)                  //叩击-逆时针（揉捏气袋）
FCT_MASSAGE_MODE(MASSAGE_MODE_RAP_ANTICLOCKWISE,               MASSAGE_AREA_MASK_9_10,     Snf_Massage_Shoulder_Rap)               //叩击-逆时针（肩部气袋）
FCT_MASSAGE_MODE(MASSAGE_MODE_POINT_MASSAGE,                   MASSAGE_AREA_MASK_5_6_7_8,  Snf_Massage_1_Point_Press_Handle)       //点按按摩（揉捏气袋）
FCT_MASSAGE_MODE(MASSAGE_MODE_POINT_MASSAGE,                   MASSAGE_AREA_MASK_9_10,     Snf_Massage_Shoulder_Bag_Point_Press)   //点按按摩（肩部气袋）
END_MASSAGE_MODE
