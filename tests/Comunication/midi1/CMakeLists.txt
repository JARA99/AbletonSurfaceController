cmake_minimum_required(VERSION 3.16.3)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)


project(midi_try C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(${PROJECT_NAME}
        midi1.c
        usb_descriptors.c
        )

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

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

# target_include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR})



# # add url via pico_set_program_url
# example_auto_set_url(blink)
