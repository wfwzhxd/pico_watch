
aux_source_directory(. DIR_INPUT_SRCS)

add_library(input ${DIR_INPUT_SRCS})
target_link_libraries(input pico_stdlib lvgl freertos)
target_include_directories(input
    PUBLIC include/
    INTERFACE $<TARGET_PROPERTY:lvgl,INTERFACE_INCLUDE_DIRECTORIES>
    INTERFACE $<TARGET_PROPERTY:freertos,INTERFACE_INCLUDE_DIRECTORIES>
    )
set_property(TARGET input APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
)