# Pisces

基于 YTMicro YTM32B1MD2x 系列 MCU 的嵌入式固件项目，包含应用层（APP/SAPP）、Bootloader、Flash Driver 及配套工具。

## 目录结构

```
├── App/                    # 应用层工程
│   ├── App_Proj/           #   APP 主工程（APP / BSW / RTE），含 chip.svd 与 J-Link 调试配置
│   ├── Eas_Proj/           #   EAS 配置工程（BSW / Callout / SWC / ARXML 等）
│   └── Mcal_Proj/          #   MCAL 工程（CMake 构建，含 Mcal、generate、cmake）
├── Bootloader/             # Bootloader 工程（bootloader 协议栈：algorithm / cfg / src）
├── BootM/                  # Boot Manager 工程
├── Flashdriver/
│   └── AZ260123_flashdriver/   # Flash 驱动工程（CMSIS / middleware / platform / rtos）
├── SApp/
│   └── AZ260123_SAPP/      # SAPP（安全/第二应用）工程
└── Tools/                  # 配套工具
    ├── build_script/       #   各配置（HIGH/LOW × D/P）的构建与合并脚本
    ├── Canoe_Proj/         #   CANoe 工程（DBC、诊断刷写配置等）
    ├── git_log/            #   git 日志检查脚本
    └── MD5/                #   MD5 校验工具
```

## 构建配置

各固件工程通过 `makefile.defs` 中的 `PROJECT_CONFIG_DEF` 选择编译配置：

| 值 | 配置宏 | 说明 |
|----|--------|------|
| 0 | `HIGH_CONFIGURATION` + `PISCES_MCM_D` | 高配 D 型 |
| 1 | `HIGH_CONFIGURATION` + `PISCES_MCM_P` | 高配 P 型 |
| 2 | `LOW_CONFIGURATION` + `PISCES_MCM_D` | 低配 D 型 |
| 3 | `LOW_CONFIGURATION` + `PISCES_MCM_P` | 低配 P 型 |

完整构建与固件合并脚本见 `Tools/build_script/`（`HIGH_D`、`HIGH_P`、`LOW_D`、`LOW_P`、`PISCES_APP1.4x_BOOT1.3x`、`build_merge_all.bat`）。

## 说明

- 各工程均为 Eclipse CDT / Makefile 风格工程，Mcal_Proj 使用 CMake 构建。
- 调试配置使用 J-Link（`*.jdebug`），芯片寄存器视图见 `App/App_Proj/chip.svd`。
- 各工程下的 `Debug/` 为构建输出目录，不纳入版本管理。
