/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 Markus Hintersteiner
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * **/

#include "hardware/clocks.h"
#include "hardware/gpio.h"
#include "hardware/irq.h"
#include "hardware/pwm.h"

#include "pico_servo.h"

// Set the frequency, making "top" as large as possible for maximum resolution.
// Maximum "top" is set at 65534 to be able to achieve 100% duty with 65535.
#define SERVO_TOP_MAX 65534

int
servo_disable(const uint gpio_pin)
{
    const uint8_t slice = pwm_gpio_to_slice_num(gpio_pin);
    pwm_set_enabled(slice, false);
    return 0;
}

int
servo_enable(const uint gpio_pin)
{
    gpio_set_function(gpio_pin, GPIO_FUNC_PWM);
    const uint8_t slice = pwm_gpio_to_slice_num(gpio_pin);

    // target frequency is 50 hz to reflect 20ms PWM signal
    const uint freq = 50;
    uint32_t source_hz = clock_get_hz(clk_sys);

    uint32_t div16_top = 8 * source_hz / freq;
    uint32_t top = 1;
    for (;;) {
        // Try a few small prime factors to get close to the desired frequency.
        if (div16_top >= 16 * 5 && div16_top % 5 == 0 && top * 5 <= SERVO_TOP_MAX) {
            div16_top /= 5;
            top *= 5;
        } else if (div16_top >= 16 * 3 && div16_top % 3 == 0 && top * 3 <= SERVO_TOP_MAX) {
            div16_top /= 3;
            top *= 3;
        } else if (div16_top >= 16 * 2 && top * 2 <= SERVO_TOP_MAX) {
            div16_top /= 2;
            top *= 2;
        } else {
            break;
        }
    }
    if (div16_top < 16) {
        return 2; // freq too large
    } else if (div16_top >= 256 * 16) {
        return 1; // freq too small
    }
    pwm_hw->slice[slice].div = div16_top;
    pwm_hw->slice[slice].top = top;

    return 0;
}

/**
 * Sets the position of the servo using the the duty cycle of the PWM signal.
 *
 * @param degree: value between 0 and 180
 * **/
int
servo_set_position(const uint gpio_pin, const uint16_t degree)
{
    // values has to be between 0 and 180
    // SERVO_TOP_MAX = 100% full duty cycle

    // TODO check if integer division is of any practical relevance
    const uint16_t oneMs = SERVO_TOP_MAX / 20;
    const uint16_t duty_u16 = oneMs + (oneMs * degree) / 180;

    const uint8_t slice = pwm_gpio_to_slice_num(gpio_pin);
    const uint8_t channel = pwm_gpio_to_channel(gpio_pin);

    const uint32_t top = pwm_hw->slice[slice].top;
    const uint32_t cc = duty_u16 * (top + 1) / SERVO_TOP_MAX;

    pwm_set_chan_level(slice, channel, cc);
    pwm_set_enabled(slice, true);

    return true;
}
