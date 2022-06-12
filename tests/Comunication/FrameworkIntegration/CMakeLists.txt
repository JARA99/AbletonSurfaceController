# Minimun version
cmake_minimum_required(VERSION 3.16.3)

# Pico sdk link
include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

# Project name and codes used
project(AbletonIntegration C CXX ASM)

# Programs versions
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Init the pico sdk
pico_sdk_init()

# Files to compile. usb_descriptors.c rquiered for midi to work
add_executable(${PROJECT_NAME}
        main.c
        usb_descriptors.c
        functions.c
        )

# Disable USB and UART comunication 
pico_enable_stdio_usb(${PROJECT_NAME} 0)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# Include paths to the .h files
target_include_directories(${PROJECT_NAME} PRIVATE 
${CMAKE_CURRENT_LIST_DIR}
)

# create map/bin/hex file etc.
pico_add_extra_outputs(${PROJECT_NAME})

# pull in common dependencies
target_link_libraries(${PROJECT_NAME}
pico_stdlib
tinyusb_device
tinyusb_board
)

