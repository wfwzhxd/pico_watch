
set(LWIP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lwip)
include(${LWIP_DIR}/src/Filelists.cmake)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_ePaper_SRCS 变量
aux_source_directory(. DIR_NETWORK_SRCS)

# 生成链接库
add_library(network ${DIR_NETWORK_SRCS})

target_sources(network
    PUBLIC ${lwipcore_SRCS}
    PUBLIC ${lwipcore4_SRCS}
    PUBLIC ${lwipapi_SRCS}
    PUBLIC ${lwipnetif_SRCS}
    PUBLIC ${lwipiperf_SRCS}
    PUBLIC ${lwipsntp_SRCS}
)

target_link_libraries(network PUBLIC pico_stdlib tinyusb_device tinyusb_board freertos)

add_compile_definitions(CFG_TUSB_CONFIG_FILE="${CMAKE_CURRENT_SOURCE_DIR}/tusb_config.h")

target_include_directories(network
        PUBLIC .
        PUBLIC include/
        PUBLIC lwip/src/include/
        PRIVATE $<TARGET_PROPERTY:freertos,INTERFACE_INCLUDE_DIRECTORIES>
        )

set_property(TARGET network APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lwip/src/include/>
)
