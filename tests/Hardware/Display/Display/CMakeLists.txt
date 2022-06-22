add_subdirectory(Fonts)

add_executable(${PROJECT_NAME}
        main.cpp
        )

# pull in common dependencies
target_link_libraries(${PROJECT_NAME} pico_stdlib ili9341 gfx)

# pico_enable_stdio_usb(${PROJECT_NAME} 1)
# pico_enable_stdio_uart(${PROJECT_NAME} 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(${PROJECT_NAME})

# # add url via pico_set_program_url
# example_auto_set_url(blink)

target_include_directories(${PROJECT_NAME} PUBLIC
	.
)