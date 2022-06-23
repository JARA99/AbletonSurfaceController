# Project name
project(tests C CXX ASM)

add_executable(tests
    tests.c
    ../src/Display/displayTitles.c
)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(tests pico_stdlib ili9341 gfx)

# create map/bin/hex file etc.
pico_add_extra_outputs(tests)