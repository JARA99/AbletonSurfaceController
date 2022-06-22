add_executable(AbletonSurfaceController
    main.c
)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(AbletonSurfaceController pico_stdlib ili9341 gfx)

# create map/bin/hex file etc.
pico_add_extra_outputs(AbletonSurfaceController)