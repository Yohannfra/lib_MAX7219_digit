cmake_minimum_required(VERSION 3.13)

#pull in pico SDK (must before project)
include(pico_sdk_import.cmake)

project(pico_counter C CXX ASM)

#initialize the SDK
pico_sdk_init()

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME}
    main.c
    ../../lib/MAX7219_digit/src/MAX7219_digit.c
    )

#pull in our pico_stdib which pulls common
target_link_libraries(${PROJECT_NAME} pico_stdlib)

#create map/bin/hes file etc.
pico_add_extra_outputs(${PROJECT_NAME})
