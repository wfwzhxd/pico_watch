# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_ePaper_SRCS 变量
aux_source_directory(. DIR_DISPLAY_SRCS)

# 生成链接库
add_library(display ${DIR_DISPLAY_SRCS})
target_include_directories(display
    PUBLIC include/display
    PRIVATE include/inner
    INTERFACE $<TARGET_PROPERTY:lvgl,INTERFACE_INCLUDE_DIRECTORIES>
    )
target_link_libraries(display pico_stdlib hardware_spi hardware_pwm lvgl)
set_property(TARGET display APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/display>
)
