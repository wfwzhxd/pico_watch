
### freertos
set(FREERTOS_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS-Kernel)


# include_directories(.)
# include_directories(${FREERTOS_SOURCE_DIR}/include/)
# include_directories(${FREERTOS_SOURCE_DIR}/portable/GCC/ARM_CM0/)


add_library(freertos STATIC)
file(GLOB FREERTOS_SRC_KERNEL ${FREERTOS_SOURCE_DIR}/*.c)
file(GLOB FREERTOS_SRC_ARM_CM0 ${FREERTOS_SOURCE_DIR}/portable/GCC/ARM_CM0/*.c)
set(FREERTOS_SRC_MEM ${FREERTOS_SOURCE_DIR}/portable/MemMang/heap_4.c)

target_sources(freertos PUBLIC ${FREERTOS_SRC_KERNEL} ${FREERTOS_SRC_ARM_CM0} ${FREERTOS_SRC_MEM})
target_include_directories(freertos
        PUBLIC ${FREERTOS_SOURCE_DIR}/include/
        PUBLIC ${FREERTOS_SOURCE_DIR}/portable/GCC/ARM_CM0/
        )

set_property(TARGET freertos APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
$<BUILD_INTERFACE:${FREERTOS_SOURCE_DIR}/portable/GCC/ARM_CM0/>
$<BUILD_INTERFACE:${FREERTOS_SOURCE_DIR}/include/>
)
