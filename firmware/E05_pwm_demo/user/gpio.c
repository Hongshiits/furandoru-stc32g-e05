#include "gpio.h"

gpio_pin_enum mot_dir_pin_list[3] = {
    MOTOR_LEFT_DIR_PIN,
    MOTOR_RIGHT_DIR_PIN,
    MOTOR_UP_DIR_PIN
};


void pt_gpio_init()
{
    gpio_init(IO_P52, GPO, 1, GPO_PUSH_PULL);
    gpio_init(IO_P32, GPI, 1, GPI_PULL_UP);

    gpio_init(MOTOR_LEFT_DIR_PIN, GPO, 1, GPO_PUSH_PULL); //MOT1 left
    gpio_init(MOTOR_RIGHT_DIR_PIN, GPO, 1, GPO_PUSH_PULL); //MOT2 right
    gpio_init(MOTOR_UP_DIR_PIN, GPO, 1, GPO_PUSH_PULL); //MOT3 top

    // gpio_init(IO_P70,GPI,0,GPI_IMPEDANCE);
}