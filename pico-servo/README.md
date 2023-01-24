# pico-servo

A simple library to control hobby servos using the Raspberry Pi Pico. Under the hood it's using PWM. Pull requests welcome!

Largely inspired by the excellent [MicroPython RP2 PWM code](https://github.com/raspberrypi/micropython/blob/pico/ports/rp2/machine_pwm.c).

## Example

````
#define SERVO_PIN 15
...
servo_enable(SERVO_PIN);

// angle: between 0 and 180
servo_set_position(SERVO_PIN, angle); 
````
See [example.c](example.c) for a full example.

## License
[See LICENSE](LICENSE)
