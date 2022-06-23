# Minimun version of cmake
cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

# Project name
project(AbletonSurfaceController C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


# Initialize the SDK
pico_sdk_init()

# add_subdirectory(pico-displayDrivs)
include_directories(
        include/Display
        include/Encoders
        include/Knobs
        include/MIDI
        include/PushButtons
)

add_subdirectory(src)
add_subdirectory(libs)
add_subdirectory(tests)

add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        )