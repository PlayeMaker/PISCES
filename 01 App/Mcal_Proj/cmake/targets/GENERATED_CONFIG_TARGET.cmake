cmake_minimum_required(VERSION 3.16)



set(sources
    ${PROJ_DIR}/generate/RamInit0.S
    ${PROJ_DIR}/generate/RamInit1.c
    ${PROJ_DIR}/generate/RamInit2.c
    ${PROJ_DIR}/generate/Port_PBcfg.c
    ${PROJ_DIR}/generate/Port_Cfg.c
    ${PROJ_DIR}/generate/IntCtrl_Lld_Cfg.c
    ${PROJ_DIR}/generate/Mpu_Lld_Cfg.c
    ${PROJ_DIR}/generate/Platform_Cfg.c
    ${PROJ_DIR}/generate/Platform_Mld_Cfg.c
    ${PROJ_DIR}/generate/startup.S
    ${PROJ_DIR}/generate/vector.S
    ${PROJ_DIR}/generate/vector_table_copy.c
    ${PROJ_DIR}/generate/system.c
    ${PROJ_DIR}/generate/Can_Cfg.c
    ${PROJ_DIR}/generate/Can_PBcfg.c
    ${PROJ_DIR}/generate/Mcu_Cfg.c
    ${PROJ_DIR}/generate/Mcu_PBcfg.c
    ${PROJ_DIR}/generate/Adc_Cfg.c
    ${PROJ_DIR}/generate/Adc_PBcfg.c
    ${PROJ_DIR}/generate/Fls_Cfg.c
    ${PROJ_DIR}/generate/Fls_PBcfg.c
    ${PROJ_DIR}/generate/Fee_Cfg.c
    ${PROJ_DIR}/generate/Pwm_Cfg.c
    ${PROJ_DIR}/generate/Pwm_PBcfg.c
    ${PROJ_DIR}/generate/Pwm_Lld_Etmr_PBcfg.c
    ${PROJ_DIR}/generate/Pwm_Lld_Mpwm_PBcfg.c
    ${PROJ_DIR}/generate/CddDma_Cfg.c
    ${PROJ_DIR}/generate/CddDma_PBcfg.c
    ${PROJ_DIR}/generate/CddUart_Cfg.c
    ${PROJ_DIR}/generate/CddUart_PBcfg.c
    ${PROJ_DIR}/generate/CddUart_Mld_PBcfg.c
    ${PROJ_DIR}/generate/CddUart_Lld_UartCfg.c
    ${PROJ_DIR}/generate/Dio_Cfg.c
    ${PROJ_DIR}/generate/Wdg_180_Inst0_Cfg.c
    ${PROJ_DIR}/generate/Wdg_180_Inst0_PBcfg.c
    ${PROJ_DIR}/generate/Wdg_Lld_PBcfg.c
)
set(includes
    ${PROJ_DIR}/generate
)
set(priIncludes
)

add_library(GENERATED_CONFIG_TARGET STATIC ${sources})

target_include_directories(GENERATED_CONFIG_TARGET PUBLIC ${includes})


target_include_directories(GENERATED_CONFIG_TARGET PRIVATE ${priIncludes})
configcore(GENERATED_CONFIG_TARGET ${CMAKE_SOURCE_DIR})

target_compile_definitions(GENERATED_CONFIG_TARGET PUBLIC
    YTM32B1MD2
    CPU_YTM32B1MD2
)
target_compile_options(GENERATED_CONFIG_TARGET PUBLIC
    -fdiagnostics-color=always
)



target_link_libraries(GENERATED_CONFIG_TARGET
    GENERATED_SDK_TARGET
)
