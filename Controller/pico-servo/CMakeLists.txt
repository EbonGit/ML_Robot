cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(servo_example)

pico_sdk_init()

add_executable(servo_example
    src/pico_servo.c
    src/pico_servo.h
    
    example.c
)



pico_add_extra_outputs(servo_example)

target_link_libraries(servo_example pico_stdlib hardware_pwm hardware_pio pico_multicore)

pico_enable_stdio_usb(servo_example 1)
pico_enable_stdio_uart(servo_example 0)
