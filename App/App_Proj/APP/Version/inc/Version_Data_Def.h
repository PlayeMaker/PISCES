BEGIN_VERSION_DATA
//        (version_data_id,                       version_data_get_function,           version_data_set_function,       version_data_len)
FCT_VERSION_DATA(VERSION_ID_REPROGRAMMING_ATTEMPT,       _Snf_Reprogramming_Attempt_Get,        _Snf_Version_Data_Set_Null,     DF_REPROGRAMMING_ATTEMPT_COUNT_SIZE)  //0xF010 刷写尝试计数
FCT_VERSION_DATA(VERSION_ID_HARDWARE_VERSION,            _Snf_Hardware_Version_Get,             _Snf_Version_Data_Set_Null,     DF_HARDWARE_NUMBER_SIZE)              //0xF110 客户硬件号
FCT_VERSION_DATA(VERSION_ID_HARDWARE_BASELINE,           _Snf_Hardware_Baseline_Get,            _Snf_Version_Data_Set_Null,     DF_HARDWARE_BASELINE_SIZE)            //0xF111 客户硬件基线号
FCT_VERSION_DATA(VERSION_ID_SOFTWARE_VERSION,            _Snf_Software_Version_Get,             _Snf_Version_Data_Set_Null,     VERSION_SOFTWARE_LEN)                 //0xF118 客户软件版本号
FCT_VERSION_DATA(VERSION_ID_SOFTWARE_BASELINE,           _Snf_Software_Baseline_Get,            _Snf_Version_Data_Set_Null,     VERSION_SOFTWARE_BASELINE_LEN)        //0xF119 客户软件基线号
FCT_VERSION_DATA(VERSION_ID_BOOTLOADER_NUMBER,           _Snf_Bootloader_Number_Get,            _Snf_Version_Data_Set_Null,     DF_BOOTLOADER_NUMBER_SIZE)            //0xF150 bootloader版本号
FCT_VERSION_DATA(VERSION_ID_FINGER_PRINT,                _Snf_Finger_Print_Get,                 _Snf_Version_Data_Set_Null,     DF_FINGER_PRINT_SIZE)                 //0xF15B 指纹
FCT_VERSION_DATA(VERSION_ID_SUPPLIER_NUMBER,             _Snf_Supplier_Number_Get,              _Snf_Version_Data_Set_Null,     VERSION_SUPPLIER_NUMBER_LEN)          //0xF18A 供应商编号
FCT_VERSION_DATA(VERSION_ID_MANUFACTURING_DATE,          _Snf_Manufacturing_Date_Get,           _Snf_Manufacturing_Date_Set,    VERSION_MANUFACTURING_DATE_LEN)       //0xF18B 生产日期
FCT_VERSION_DATA(VERSION_ID_SERIAL_NUMBER,               _Snf_Serial_Number_Get,                _Snf_Serial_Number_Set,         VERSION_SERIAL_NUMBER_LEN)            //0xF18C 序列号
FCT_VERSION_DATA(VERSION_ID_SUPPLIER_HARDWARE_NUMBER,    _Snf_Hardware_Inside_Version_Get,      _Snf_Version_Data_Set_Null,     VERSION_HARDWARE_INSIDE_LEN)          //0xF193 供应商硬件号
FCT_VERSION_DATA(VERSION_ID_SUPPLIER_SOFTWARE_NUMBER,    _Snf_Software_Inside_Version_Get,      _Snf_Version_Data_Set_Null,     VERSION_SOFTWARE_INSIDE_LEN)          //0xF195 供应商软件号
FCT_VERSION_DATA(VERSION_ID_DIAG_DATABASE_VERSION,       _Snf_Diag_Database_Version_Get,        _Snf_Version_Data_Set_Null,     VERSION_DIAG_DATABASE_LEN)            //0xF19E 诊断数据库版本
FCT_VERSION_DATA(VERSION_ID_BOOTLOADER_INSIDE_VERSION,   _Snf_Bootloader_Number_Get,            _Snf_Version_Data_Set_Null,     DF_BOOTLOADER_NUMBER_SIZE)            //0xFD00 bootloader内部版本号
FCT_VERSION_DATA(VERSION_ID_SOFTWARE_INSIDE_VERSION,     _Snf_Software_Inside_Version_Get,      _Snf_Version_Data_Set_Null,     VERSION_SOFTWARE_INSIDE_LEN)          //0xFD01 软件内部版本号
FCT_VERSION_DATA(VERSION_ID_HARDWARE_INSIDE_VERSION,     _Snf_Hardware_Inside_Version_Get,      _Snf_Version_Data_Set_Null,     VERSION_HARDWARE_INSIDE_LEN)          //0xFD02 硬件内部版本号
FCT_VERSION_DATA(VERSION_ID_BAT_VOLTAGE,                 _Snf_BAT_Voltage_Get,                  _Snf_Version_Data_Set_Null,     VERSION_BAT_VOLTAGE_LEN)              //0xFD03 读取电源输入电压
FCT_VERSION_DATA(VERSION_ID_BUILD_TIME_VERSION,          _Snf_Build_Time_Inside_Version_Get,    _Snf_Version_Data_Set_Null,     VERSION_BUILD_TIME_LEN)               //0xFD05 构建时间
FCT_VERSION_DATA(VERSION_ID_BUILD_GIT_HASH,              _Snf_Build_Git_Hash_Inside_Version_Get,_Snf_Version_Data_Set_Null,     VERSION_BUILD_GIT_HASH_LEN)           //0xFD06 构建 Git 哈希值
END_VERSION_DATA
