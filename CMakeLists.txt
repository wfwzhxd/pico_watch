cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(pico_rtthread C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

# include_directories(.)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

# add_compile_definitions("DEBUG_PRINTF")
add_subdirectory(lib/lvgl)
add_subdirectory(lib/freertos)
add_subdirectory(lib/display)
add_subdirectory(lib/network)

add_executable(main)
target_include_directories(main
        PRIVATE $<TARGET_PROPERTY:freertos,INTERFACE_INCLUDE_DIRECTORIES>
        PRIVATE $<TARGET_PROPERTY:network,INTERFACE_INCLUDE_DIRECTORIES>
        PRIVATE $<TARGET_PROPERTY:display,INTERFACE_INCLUDE_DIRECTORIES>
        PRIVATE $<TARGET_PROPERTY:lvgl,INTERFACE_INCLUDE_DIRECTORIES>
        )

set(MAIN_SRC
        src/net.c
        src/stdio_net.c
        src/main.c
        src/rtc.c
        src/shell.c
        src/gui/gui.c
        src/gui/lv_font_kslyt_30.c
        src/gui/lv_font_kslyt_48.c
        src/freertos_hook.c)

target_sources(main 
        PRIVATE ${MAIN_SRC})
target_link_libraries(main
        freertos
        network    
        lvgl
        display
        pico_stdlib
        hardware_rtc
        pico_time
        )

# add_compile_definitions("LV_LVGL_H_INCLUDE_SIMPLE")
pico_enable_stdio_usb(main 0)
pico_enable_stdio_uart(main 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(main)

