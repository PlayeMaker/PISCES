cmake_minimum_required(VERSION 3.16)



set(sources
    ${PROJ_DIR}/Mcal/Port/src/Port.c
    ${PROJ_DIR}/Mcal/Port/src/Port_Lld.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Port.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Platform.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Can.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Mcu.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Adc.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Fls.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Fee.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Pwm.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_CddDma.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_CddUart.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Dio.c
    ${PROJ_DIR}/Mcal/Rte/src/SchM_Wdg_180_Inst0.c
    ${PROJ_DIR}/Mcal/Platform/src/exceptions.c
    ${PROJ_DIR}/Mcal/Platform/src/IntCtrl_Lld.c
    ${PROJ_DIR}/Mcal/Platform/src/OsIf.c
    ${PROJ_DIR}/Mcal/Platform/src/Platform_Mld.c
    ${PROJ_DIR}/Mcal/Platform/src/Platform.c
    ${PROJ_DIR}/Mcal/Platform/src/System_Lld.c
    ${PROJ_DIR}/Mcal/Platform/src/Mpu_Lld_M33.c
    ${PROJ_DIR}/Mcal/Platform/src/Pcache_Lld.c
    ${PROJ_DIR}/Mcal/Det/src/Det.c
    ${PROJ_DIR}/Mcal/CanIf/src/CanIf.c
    ${PROJ_DIR}/Mcal/Can/src/Can.c
    ${PROJ_DIR}/Mcal/Can/src/Can_Lld.c
    ${PROJ_DIR}/Mcal/Can/src/Can_Lld_Irq.c
    ${PROJ_DIR}/Mcal/Mcu/src/Mcu.c
    ${PROJ_DIR}/Mcal/Mcu/src/Mcu_Lld.c
    ${PROJ_DIR}/Mcal/Mcu/src/Mcu_Lld_Irq.c
    ${PROJ_DIR}/Mcal/Adc/src/Adc.c
    ${PROJ_DIR}/Mcal/Adc/src/Adc_Irq.c
    ${PROJ_DIR}/Mcal/Adc/src/Adc_Lld_Eadc.c
    ${PROJ_DIR}/Mcal/Fls/src/Fls.c
    ${PROJ_DIR}/Mcal/Fls/src/Fls_Mld.c
    ${PROJ_DIR}/Mcal/Fls/src/Fls_Lld.c
    ${PROJ_DIR}/Mcal/Fee/src/Fee.c
    ${PROJ_DIR}/Mcal/Pwm/src/Pwm.c
    ${PROJ_DIR}/Mcal/Pwm/src/Pwm_Mld.c
    ${PROJ_DIR}/Mcal/Pwm/src/Pwm_Lld_Etmr.c
    ${PROJ_DIR}/Mcal/Pwm/src/Pwm_Lld_Etmr_Irq.c
    ${PROJ_DIR}/Mcal/Pwm/src/Pwm_Lld_Mpwm.c
    ${PROJ_DIR}/Mcal/Pwm/src/Pwm_Lld_Mpwm_Irq.c
    ${PROJ_DIR}/Mcal/CddDma/src/CddDma.c
    ${PROJ_DIR}/Mcal/CddDma/src/CddDma_Lld.c
    ${PROJ_DIR}/Mcal/CddDma/src/CddDma_Irq.c
    ${PROJ_DIR}/Mcal/CddUart/src/CddUart.c
    ${PROJ_DIR}/Mcal/CddUart/src/CddUart_Mld.c
    ${PROJ_DIR}/Mcal/CddUart/src/CddUart_Lld_Uart.c
    ${PROJ_DIR}/Mcal/CddUart/src/CddUart_Lld_Uart_Irq.c
    ${PROJ_DIR}/Mcal/Dio/src/Dio_Lld.c
    ${PROJ_DIR}/Mcal/Dio/src/Dio.c
    ${PROJ_DIR}/Mcal/Wdg/src/Wdg_Mld_Irq.c
    ${PROJ_DIR}/Mcal/Wdg/src/Wdg_180_Inst0.c
    ${PROJ_DIR}/Mcal/Wdg/src/Wdg_Lld.c
    ${PROJ_DIR}/Mcal/Wdg/src/Wdg_Lld_Irq.c
    ${PROJ_DIR}/Mcal/WdgIf/src/WdgIf.c
)
set(includes
    ${PROJ_DIR}/Mcal/Port/inc
    ${PROJ_DIR}/Mcal/Rte/inc
    ${PROJ_DIR}/Mcal/Platform/inc
    ${PROJ_DIR}/Mcal/Platform/core
    ${PROJ_DIR}/Mcal/Platform/YTM32B1MD2/feature
    ${PROJ_DIR}/Mcal/Platform/YTM32B1MD2/regmap
    ${PROJ_DIR}/Mcal/Det/inc
    ${PROJ_DIR}/Mcal/CanIf/inc
    ${PROJ_DIR}/Mcal/Can/inc
    ${PROJ_DIR}/Mcal/Mcu/inc
    ${PROJ_DIR}/Mcal/Adc/inc
    ${PROJ_DIR}/Mcal/Fls/inc
    ${PROJ_DIR}/Mcal/Fee/inc
    ${PROJ_DIR}/Mcal/MemIf/inc
    ${PROJ_DIR}/Mcal/Pwm/inc
    ${PROJ_DIR}/Mcal/CddDma/inc
    ${PROJ_DIR}/Mcal/CddUart/inc
    ${PROJ_DIR}/Mcal/Dio/inc
    ${PROJ_DIR}/Mcal/Wdg/inc
    ${PROJ_DIR}/Mcal/WdgIf/inc
)
set(priIncludes
)

add_library(GENERATED_SDK_TARGET STATIC ${sources})

target_include_directories(GENERATED_SDK_TARGET PUBLIC ${includes})


target_include_directories(GENERATED_SDK_TARGET PRIVATE ${priIncludes})
configcore(GENERATED_SDK_TARGET ${CMAKE_SOURCE_DIR})

target_compile_definitions(GENERATED_SDK_TARGET PUBLIC
    YTM32B1MD2
    CPU_YTM32B1MD2
)
target_compile_options(GENERATED_SDK_TARGET PUBLIC
    -fdiagnostics-color=always
)



target_link_libraries(GENERATED_SDK_TARGET
    GENERATED_CONFIG_TARGET
)
