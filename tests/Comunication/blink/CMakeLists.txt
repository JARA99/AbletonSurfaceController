cmake_minimum_required(VERSION 3.16.3)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)


project(MoodBlink)
set(CMAKE_CXX_STANDARD 17)


pico_sdk_init()
# add_subdirectory(/home/jorgealejandro/.pico/pico-sdk/src/)
# add_subdirectory(./examples)

add_executable(${PROJECT_NAME}
        blink.c
        )

# pull in common dependencies
target_link_libraries(${PROJECT_NAME}
pico_stdlib
)

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(${PROJECT_NAME})

# # add url via pico_set_program_url
# example_auto_set_url(blink)
